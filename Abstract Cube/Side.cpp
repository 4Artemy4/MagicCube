//
// Created by art on 7/25/20.
//

#include "Side.h"


Side::Side(int rows, int columns, short color) {
    matrix = new short*[rows];
    this->rows = rows;
    this->columns = columns;

    for (int i = 0; i < rows; ++i) {
        matrix[i] = new short [columns];
    }

    for (int j = 0; j < rows; ++j) {
        for (int i = 0; i < columns; ++i) {
            matrix[j][i] = color;
        }
    }
}

Side::Side() = default;
