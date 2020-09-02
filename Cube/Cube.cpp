//
// Created by art on 9/3/20.
//

#include <iostream>
#include "Cube.h"

Cube::Cube(int n) {
    size = n;
    for (short i = 0; i < 6; ++i) {
        sides[i] = Side(n, i);
    }
}

void Cube::rotateLayerVertically(bool isInverse, int layer) {
    short temp;
    if (isInverse) {
        // поворачиваем левую грань против часовой стрелки
        for (int i = 0; i < size; ++i) {
            temp = sides[upColor].matrix[i][layer];
            sides[upColor].matrix[i][layer] = sides[currentColor].matrix[i][layer];
            sides[currentColor].matrix[i][layer] = sides[downColor].matrix[i][layer];
            sides[downColor].matrix[i][layer] = sides[backwardColor].matrix[i][layer];
            sides[backwardColor].matrix[i][layer] = temp;
        }

    } else {
        // поворачиваем левую грань по часовой стрелки
        for (int i = 0; i < size; ++i) {
            temp = sides[downColor].matrix[i][layer];
            sides[downColor].matrix[i][layer] = sides[currentColor].matrix[i][layer];
            sides[currentColor].matrix[i][layer] = sides[upColor].matrix[i][layer];
            sides[upColor].matrix[i][layer] = sides[backwardColor].matrix[i][layer];
            sides[backwardColor].matrix[i][layer] = temp;
        }
    }
    if (layer == 0)rotateSide(leftColor, !isInverse);
    else if (layer == size - 1)rotateSide(leftColor, isInverse);
}

void Cube::rotateLayerHorizontally(bool isInverse, int layer) {
    short temp;
    if (isInverse) {
        // поворачиваем верхную грань против часовой стрелки
        for (int i = 0; i < size; ++i) {
            temp = sides[rightColor].matrix[layer][i];
            sides[rightColor].matrix[layer][i] = sides[currentColor].matrix[layer][i];
            sides[currentColor].matrix[layer][i] = sides[leftColor].matrix[layer][i];
            sides[leftColor].matrix[layer][i] = sides[backwardColor].matrix[layer][i];
            sides[backwardColor].matrix[layer][i] = temp;
        }
    } else {
        // поворачиваем верхную грань по часовой стрелки
        for (int i = 0; i < size; ++i) {
            temp = sides[leftColor].matrix[layer][i];
            sides[leftColor].matrix[layer][i] = sides[currentColor].matrix[layer][i];
            sides[currentColor].matrix[layer][i] = sides[rightColor].matrix[layer][i];
            sides[rightColor].matrix[layer][i] = sides[backwardColor].matrix[layer][i];
            sides[backwardColor].matrix[layer][i] = temp;
        }
    }
    if (layer == 0)rotateSide(upColor, isInverse);
    else if (layer == size - 1)rotateSide(upColor, !isInverse);
}

void Cube::rotateLayer(bool isInverse, int layer) {
    short temp;
    if (isInverse) {
        // поворачиваем фронтальную грань против часовой стрелки
        for (int i = 0; i < size; ++i) {
            temp = sides[rightColor].matrix[i][layer];
            sides[rightColor].matrix[i][layer] = sides[downColor].matrix[layer][size - 1 - i];
            sides[downColor].matrix[layer][size - 1 - i] = sides[leftColor].matrix[size - 1 - i][size - 1 - layer];
            sides[leftColor].matrix[size - 1 - i][size - 1 - layer] = sides[upColor].matrix[size - 1][i];
            sides[upColor].matrix[size - 1][i] = temp;
        }
    } else {
        // поворачиваем фронтальную грань по часовой стрелки
        for (int i = 0; i < size; ++i) {
            temp = sides[leftColor].matrix[size - 1 - i][size - 1 - layer];
            sides[leftColor].matrix[size - 1 - i][size - 1 - layer] = sides[downColor].matrix[layer][size - 1 - i];
            sides[downColor].matrix[layer][size - 1 - i] = sides[rightColor].matrix[i][layer];
            sides[rightColor].matrix[i][layer] = sides[upColor].matrix[size - 1 - layer][i];
            sides[upColor].matrix[size - 1 - layer][i] = temp;
        }
    }
    if (layer == 0) rotateSide(currentColor, isInverse);
    if (layer == size - 1)rotateSide(currentColor, !isInverse);
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

void Cube::redraw() const {
    for (int i = 0; i < size/2; ++i) {
        std::cout << "   ";
    }
    std::cout << convertCodeToColor(upColor) << std::endl;
    for (int i = 0; i < size; ++i) {
        if (i == size/2) {
            std::cout << convertCodeToColor(leftColor) << ' ';
            for (int j = 0; j < size; ++j) {
                std::cout << convertCodeToColor(sides[currentColor].matrix[i][j]) << ' ';
            }
            std::cout << convertCodeToColor(rightColor);
        }
        else{
            std::cout << "  ";
            for (int j = 0; j < size; ++j) {
                std::cout << convertCodeToColor(sides[currentColor].matrix[i][j]) << ' ';
            }
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < size/2; ++i) {
        std::cout << "   ";
    }
    std::cout << convertCodeToColor(downColor) << std::endl;
}

char Cube::convertCodeToColor(short colorCode) {
    // White
    // Yellow
    // Red
    // Orange
    // Blue
    // Green
    // Error @Debug

    switch (colorCode) {
        case 0:
            return 'W';
        case 1:
            return 'Y';
        case 2:
            return 'R';
        case 3:
            return 'O';
        case 4:
            return 'B';
        case 5:
            return 'G';
    }
    return 'E';
}
