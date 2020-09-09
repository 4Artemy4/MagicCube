//
// Created by art on 9/3/20.
//

#include <fstream>
#include "Cube.h"

#define  verticalRotation 'V'
#define horizontalRotation 'H'
#define frontRotation 'P'
char Cube::colors[6] = {'W', 'Y', 'R', 'O', 'B', 'G'};

Cube::Cube(int n) {
    size = n;
    for (short i = 0; i < 6; ++i) {
        sides[i] = Side(n, i);
    }
}

void Cube::rotateLayerVertically(bool isInverse, int layer) {
    if (size % 2 == 1 && layer == size / 2) return;
    if (isInverse) {
        rotateVerticalInverse(layer);
    } else {
        rotateVertical(layer);
    }
    if (layer == 0)rotateSide(leftColor, !isInverse);
    else if (layer == size - 1)rotateSide(rightColor, isInverse);
}

void Cube::rotateLayerHorizontally(bool isInverse, int layer) {
    if (size % 2 == 1 && layer == size / 2) return;

    if (isInverse) {
        rotateHorizontalInverse(layer);
    } else {
        rotateHorizontal(layer);
    }

    if (layer == 0) rotateSide(upColor, isInverse);
    else if (layer == size - 1)rotateSide(downColor, !isInverse);
}

void Cube::rotateFrontLayer(bool isInverse, int layer) {
    if (size % 2 == 1 && layer == size / 2) return;

    if (isInverse) {
        rotateFrontInverse(layer);
    } else {
        rotateFront(layer);
    }

    if (layer == 0) rotateSide(currentColor, isInverse);
    if (layer == size - 1)rotateSide(backwardColor, !isInverse);
}

void Cube::rotateSide(short side, bool isInverse) {
    short **original = nullptr;
    initMatrix(original, side);
    if (isInverse) {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                sides[side].matrix[size - 1 - j][i] = original[i][j];
            }
        }
    } else {
        for (int i = 0; i < sides[side].size; ++i) {
            for (int j = 0; j < sides[side].size; ++j) {
                sides[side].matrix[j][size - 1 - i] = original[i][j];
            }
        }
    }
    deleteMatrix(original);
}

char Cube::convertCodeToColor(short colorCode) {
    return colors[colorCode];
}

std::ostream &operator<<(std::ostream &os, const Cube &cube) {
    for (int i = 0; i < cube.size / 2 + 1; ++i) os << "  ";
    os << cube.convertCodeToColor(cube.upColor) << std::endl;
    for (int i = 0; i < cube.size; ++i) {
        if (i == cube.size / 2) {
            os << cube.convertCodeToColor(cube.leftColor) << ' ';
            for (int j = 0; j < cube.size; ++j) {
                os << cube.convertCodeToColor(cube.sides[cube.currentColor].matrix[i][j]) << ' ';
            }
            os << cube.convertCodeToColor(cube.rightColor);
        } else {
            os << "  ";
            for (int j = 0; j < cube.size; ++j) {
                os << cube.convertCodeToColor(cube.sides[cube.currentColor].matrix[i][j]) << ' ';
            }
        }
        os << std::endl;
    }
    for (int i = 0; i < cube.size / 2 + 1; ++i) os << "  ";
    os << cube.convertCodeToColor(cube.downColor) << std::endl;
    return os;
}

std::istream &operator>>(std::istream &is, Cube &cube) {
    std::string command;
    is >> command;
    cube.command(command);
    return is;
}

bool Cube::command(const std::string &commands) {
    bool isInverse;
    int layerNum;
    for (int i = 0; i < commands.size(); ++i) {
        if (commands[i] == verticalRotation || commands[i] == horizontalRotation || commands[i] == frontRotation) {
            isInverse = commands[i + 1] == '\'';
            int j = i + 1;
            if (isInverse) j++;
            layerNum = stringToInt(commands, j);

            switch (commands[i]) {
                case verticalRotation: {
                    addVerticalRotationCommand(isInverse, layerNum);
                    break;
                }
                case horizontalRotation: {
                    addHorizontalRotationCommand(isInverse, layerNum);
                    break;
                }
                case frontRotation: {
                    addFrontRotationCommand(isInverse, layerNum);
                    break;
                }
                default:
                    return false;
            }
        }
    }
    return true;
}

std::string Cube::rand() {
    std::string result;
    srand(time(0));
    const int times = std::rand() % (5 * size);
    int layer;
    for (int i = 0; i < times; ++i) {
        layer = std::rand() % size;
        switch (std::rand() % 3) {
            case 0: {
                rotateLayerVertically(false, layer);
                result += verticalRotation + std::to_string(layer);
                break;
            }
            case 1: {
                rotateLayerHorizontally(false, std::rand() % size);
                result += horizontalRotation + std::to_string(layer);
                break;
            }
            case 2: {
                rotateFrontLayer(false, std::rand() % size);
                result += frontRotation + std::to_string(layer);
                break;
            }
        }
        result += ' ';
    }
    return result;
}

bool Cube::check() const {
    for (int k = 0; k < 5; ++k) {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (sides[currentColor].matrix[i][j] != 0) return false;
            }
        }
    }
    return true;
}

void Cube::load(const std::string &filename) {
    std::fstream file(filename);
    std::string command;
    getline(file, command);
    this->command(command);
}

int Cube::getSize() const {
    return size;
}

const std::string &Cube::getRotations() const {
    return rotations;
}

short Cube::getColor(short sideColor, int i, int j) const {
    return sides[sideColor].matrix[i][j];
}

void Cube::solve() {
    rotations.clear();
    for (short i = 0; i < 6; ++i) {
        for (int j = 0; j < size; ++j) {
            for (int k = 0; k < size; ++k) {
                sides[i].matrix[j][k] = i;
            }
        }
    }

}

bool Cube::operator==(const Cube &rhs) const {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < size; ++j) {
            for (int k = 0; k < size; ++k) {
                if (sides[i].matrix[i][j] != rhs.sides[i].matrix[i][j]) return false;
            }
        }
    }
    return true;
}

bool Cube::operator!=(const Cube &rhs) const {
    return !(rhs == *this);
}

void Cube::rotateVertical(int layer) {
    short temp;
    for (int i = 0; i < size; ++i) {
        temp = sides[downColor].matrix[i][layer];
        sides[downColor].matrix[i][layer] = sides[currentColor].matrix[i][layer];
        sides[currentColor].matrix[i][layer] = sides[upColor].matrix[i][layer];
        sides[upColor].matrix[i][layer] = sides[backwardColor].matrix[i][layer];
        sides[backwardColor].matrix[i][layer] = temp;
    }
}

void Cube::rotateVerticalInverse(int layer) {
    short temp;
    for (int i = 0; i < size; ++i) {
        temp = sides[upColor].matrix[i][layer];
        sides[upColor].matrix[i][layer] = sides[currentColor].matrix[i][layer];
        sides[currentColor].matrix[i][layer] = sides[downColor].matrix[i][layer];
        sides[downColor].matrix[i][layer] = sides[backwardColor].matrix[i][layer];
        sides[backwardColor].matrix[i][layer] = temp;
    }
}

void Cube::rotateHorizontal(int layer) {
    short temp;
    for (int i = 0; i < size; ++i) {
        temp = sides[leftColor].matrix[layer][i];
        sides[leftColor].matrix[layer][i] = sides[currentColor].matrix[layer][i];
        sides[currentColor].matrix[layer][i] = sides[rightColor].matrix[layer][i];
        sides[rightColor].matrix[layer][i] = sides[backwardColor].matrix[layer][i];
        sides[backwardColor].matrix[layer][i] = temp;
    }
}

void Cube::rotateHorizontalInverse(int layer) {
    short temp;
    for (int i = 0; i < size; ++i) {
        temp = sides[rightColor].matrix[layer][i];
        sides[rightColor].matrix[layer][i] = sides[currentColor].matrix[layer][i];
        sides[currentColor].matrix[layer][i] = sides[leftColor].matrix[layer][i];
        sides[leftColor].matrix[layer][i] = sides[backwardColor].matrix[layer][i];
        sides[backwardColor].matrix[layer][i] = temp;
    }
}

void Cube::rotateFront(int layer) {
    short temp;
    for (int i = 0; i < size; ++i) {
        temp = sides[leftColor].matrix[size - 1 - i][size - 1 - layer];
        sides[leftColor].matrix[size - 1 - i][size - 1 - layer] = sides[downColor].matrix[layer][size - 1 - i];
        sides[downColor].matrix[layer][size - 1 - i] = sides[rightColor].matrix[i][layer];
        sides[rightColor].matrix[i][layer] = sides[upColor].matrix[size - 1 - layer][i];
        sides[upColor].matrix[size - 1 - layer][i] = temp;
    }
}

void Cube::rotateFrontInverse(int layer) {
    short temp;
    for (int i = 0; i < size; ++i) {
        temp = sides[rightColor].matrix[i][layer];
        sides[rightColor].matrix[i][layer] = sides[downColor].matrix[layer][size - 1 - i];
        sides[downColor].matrix[layer][size - 1 - i] = sides[leftColor].matrix[size - 1 - i][size - 1 - layer];
        sides[leftColor].matrix[size - 1 - i][size - 1 - layer] = sides[upColor].matrix[size - 1][i];
        sides[upColor].matrix[size - 1][i] = temp;
    }
}

void Cube::deleteMatrix(short **matrix) const {
    for (int l = 0; l < size; ++l) {
        delete[] matrix[l];
    }
    delete[] matrix;
}

void Cube::initMatrix(short **matrix, short side) {
    matrix = new short *[size];
    for (int k = 0; k < size; ++k) {
        matrix[k] = new short[size];
        for (int i = 0; i < size; ++i) {
            matrix[k][i] = sides[side].matrix[k][i];
        }
    }
}

void Cube::addVerticalRotationCommand(bool isInverse, int layerNum) {
    std::string result;
    rotateLayerVertically(isInverse, layerNum);
    rotations += verticalRotation;
    if (isInverse) rotations += '\'';
    rotations += std::to_string(layerNum);
}

void Cube::addHorizontalRotationCommand(bool isInverse, int layerNum) {
    rotateLayerHorizontally(isInverse, layerNum);
    rotations += horizontalRotation;
    if (isInverse) rotations += '\'';
    rotations += std::to_string(layerNum);
}

void Cube::addFrontRotationCommand(bool isInverse, int layerNum) {
    rotateFrontLayer(isInverse, layerNum);
    rotations += frontRotation;
    if (isInverse) rotations += '\'';
    rotations += std::to_string(layerNum);
}

int Cube::stringToInt(const std::string &commands, int j) {
    std::string layerNumber;
    int result;
    while (commands[j] >= '0' && commands[j] <= '9') {
        layerNumber += commands[j];
        j++;
    }
    sscanf(layerNumber.c_str(), "%d", &result);
    return result;
}
