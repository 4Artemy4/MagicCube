//
// Created by art on 7/25/20.
//

#include "Side.h"


Side::Side(int size, short color) {
    this->size = size;

    matrix = new short*[size];
    for (int i = 0; i < size; ++i) {
        matrix[i] = new short [size];
    }

    for (int j = 0; j < size; ++j) {
        for (int i = 0; i < size; ++i) {
            matrix[j][i] = color;
        }
    }
}

Side::Side() = default;
