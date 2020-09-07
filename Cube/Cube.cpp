//
// Created by art on 9/3/20.
//

#include <iostream>
#include <fstream>
#include "Cube.h"

char Cube::colors[6] = {'W', 'Y', 'R', 'O', 'B', 'G'};

Cube::Cube(int n) {
    size = n;
    for (short i = 0; i < 6; ++i) {
        sides[i] = Side(n, i);
    }
}

void Cube::rotateLayerVertically(bool isInverse, int layer) {
    short temp;
    if (isInverse) {
        for (int i = 0; i < size; ++i) {
            temp = sides[upColor].matrix[i][layer];
            sides[upColor].matrix[i][layer] = sides[currentColor].matrix[i][layer];
            sides[currentColor].matrix[i][layer] = sides[downColor].matrix[i][layer];
            sides[downColor].matrix[i][layer] = sides[backwardColor].matrix[i][layer];
            sides[backwardColor].matrix[i][layer] = temp;
        }

    } else {
        for (int i = 0; i < size; ++i) {
            temp = sides[downColor].matrix[i][layer];
            sides[downColor].matrix[i][layer] = sides[currentColor].matrix[i][layer];
            sides[currentColor].matrix[i][layer] = sides[upColor].matrix[i][layer];
            sides[upColor].matrix[i][layer] = sides[backwardColor].matrix[i][layer];
            sides[backwardColor].matrix[i][layer] = temp;
        }
    }
    if (layer == 0)rotateSide(leftColor, !isInverse);
    else if (layer == size - 1)rotateSide(rightColor, isInverse);


}

void Cube::rotateLayerHorizontally(bool isInverse, int layer) {
    short temp;
    if (isInverse) {
        for (int i = 0; i < size; ++i) {
            temp = sides[rightColor].matrix[layer][i];
            sides[rightColor].matrix[layer][i] = sides[currentColor].matrix[layer][i];
            sides[currentColor].matrix[layer][i] = sides[leftColor].matrix[layer][i];
            sides[leftColor].matrix[layer][i] = sides[backwardColor].matrix[layer][i];
            sides[backwardColor].matrix[layer][i] = temp;
        }
    } else {
        for (int i = 0; i < size; ++i) {
            temp = sides[leftColor].matrix[layer][i];
            sides[leftColor].matrix[layer][i] = sides[currentColor].matrix[layer][i];
            sides[currentColor].matrix[layer][i] = sides[rightColor].matrix[layer][i];
            sides[rightColor].matrix[layer][i] = sides[backwardColor].matrix[layer][i];
            sides[backwardColor].matrix[layer][i] = temp;
        }
    }
    if (layer == 0)rotateSide(upColor, isInverse);
    else if (layer == size - 1)rotateSide(downColor, !isInverse);

}

void Cube::rotateLayer(bool isInverse, int layer) {
    short temp;
    if (isInverse) {
        for (int i = 0; i < size; ++i) {
            temp = sides[rightColor].matrix[i][layer];
            sides[rightColor].matrix[i][layer] = sides[downColor].matrix[layer][size - 1 - i];
            sides[downColor].matrix[layer][size - 1 - i] = sides[leftColor].matrix[size - 1 - i][size - 1 - layer];
            sides[leftColor].matrix[size - 1 - i][size - 1 - layer] = sides[upColor].matrix[size - 1][i];
            sides[upColor].matrix[size - 1][i] = temp;
        }
    } else {
        for (int i = 0; i < size; ++i) {
            temp = sides[leftColor].matrix[size - 1 - i][size - 1 - layer];
            sides[leftColor].matrix[size - 1 - i][size - 1 - layer] = sides[downColor].matrix[layer][size - 1 - i];
            sides[downColor].matrix[layer][size - 1 - i] = sides[rightColor].matrix[i][layer];
            sides[rightColor].matrix[i][layer] = sides[upColor].matrix[size - 1 - layer][i];
            sides[upColor].matrix[size - 1 - layer][i] = temp;
        }
    }
    if (layer == 0) rotateSide(currentColor, isInverse);
    if (layer == size - 1)rotateSide(backwardColor, !isInverse);


}

void Cube::rotateSide(int side, bool isInverse) {
    auto **original = new short *[size];
    for (int k = 0; k < size; ++k) {
        original[k] = new short[size];
        for (int i = 0; i < size; ++i) {
            original[k][i] = sides[side].matrix[k][i];
        }
    }
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

    for (int l = 0; l < size; ++l) {
        delete[] original[l];
    }
    delete[] original;
}

char Cube::convertCodeToColor(short colorCode) {
    return colors[colorCode];
}

std::ostream &operator<<(std::ostream &os, const Cube &cube) {
    for (int i = 0; i < cube.size / 2 + 1; ++i) {
        os << "  ";
    }
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

    for (int i = 0; i < cube.size / 2 + 1; ++i) {
        os << "  ";
    }
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
    short times;
    bool isInverse;
    int layerNum=0;
    for (int i = 0; i < commands.size(); ++i) {
        times = 1;
        isInverse = false;
        if (commands[i] != ' ') {
            if (commands[i] == '2') {
                times = 2;
                i++;
            }

            if (commands[i + 1] == '\'') isInverse = true;

            std::string layerNumber;
            int j = i + 2;
            while (commands[j] >= '0' && commands[j] <= '9') {
                layerNumber += commands[j];
                j++;
            }
            sscanf(layerNumber.c_str(), "%d", &layerNum);
            switch (commands[i]) {
                case 'V': {
                    for (int j = 0; j < times; ++j) {
                        rotateLayerVertically(isInverse, layerNum);
                        rotations += 'V';
                        if (isInverse) rotations+= '\'';
                        rotations += std::to_string(layerNum);
                    }
                    break;
                }
                case 'H': {
                    for (int j = 0; j < times; ++j) {
                        rotateLayerHorizontally(isInverse, layerNum);
                        rotations += 'H';
                        if (isInverse) rotations+= '\'';
                        rotations += std::to_string(layerNum);
                    }
                    break;
                }
                case 'P': {
                    for (int j = 0; j < times; ++j) {
                        rotateLayer(isInverse, layerNum);
                        rotations += 'P';
                        if (isInverse) rotations+= '\'';
                        rotations += std::to_string(layerNum);
                    }
                    break;
                }
                default:
                    return false;
            }
            while (commands[i] != ' ' && i < commands.size())i++;
        }
    }
    return true;
}

void Cube::rand() {
    srand(time(0));
    for (int i = 0; i < 3*size; ++i) {
        switch (std::rand()%3) {
            case 0:{
                rotateLayerVertically(false, std::rand()%size);
                break;
            }
            case 1:{
                rotateLayerHorizontally(false, std::rand()%size);
                break;
            }
            case 2:{
                rotateLayer(false, std::rand()%size);
                break;
            }
        }
    }
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
//    std::string solverResult;
//    std::string layerNumber;
//    for (int i = rotations.size()-2; i >= 0; --i) {
//        if (rotations[i]>='A' && rotations[i]<='Z'){
//            solverResult += rotations[i];
//            if (rotations[i+1] != '\'') solverResult+='\'';
//            solverResult += layerNumber + ' ';
//            layerNumber.clear();
//        } else if (rotations[i]>='0' && rotations[i]<='9') layerNumber+=rotations[i];
//    }
//    command(solverResult);
    rotations.clear();
    for (short i = 0; i < 6; ++i) {
        for (int j = 0; j < size; ++j) {
            for (int k = 0; k < size; ++k) {
                sides[i].matrix[j][k] = i;
            }
        }
    }

}
