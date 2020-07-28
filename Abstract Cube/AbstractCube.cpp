//
// Created by art on 7/25/20.
//

#include <algorithm>
#include "AbstractCube.h"

AbstractCube::AbstractCube() {
    for (short i = 0; i < 6; ++i) {
        sides[i] = Side(1, 1, i);
    }
}

AbstractCube::AbstractCube(int rows, int columns) {
    this->rows = rows;
    this->columns = columns;
    sides[0] = Side(rows, columns, 0);
    sides[1] = Side(rows, columns, 1);
    if (rows < columns) {
        sides[4] = Side(rows, columns, 4);
        sides[5] = Side(rows, columns, 5);
        sides[2] = Side(columns, columns, 2);
        sides[3] = Side(columns, columns, 3);
    } else {
        sides[2] = Side(rows, columns, 2);
        sides[3] = Side(rows, columns, 3);
        sides[4] = Side(rows, rows, 4);
        sides[5] = Side(rows, rows, 5);
    }
}

void AbstractCube::sideRotationHorizontal(const int rowNumber, const bool isInverse) {
    if (rowNumber != (rows - 1) / 2) {
        short temp;
        if (isInverse) {
            // поворачиваем сторону под номером rowNumber (от нуля до rows-1) против часовой стрелки (правый поворот)
            for (int i = 0; i < columns; ++i) {
                temp = sides[rightColor].matrix[rowNumber][i];
                sides[rightColor].matrix[rowNumber][i] = sides[currentColor].matrix[rowNumber][i];
                sides[currentColor].matrix[rowNumber][i] = sides[leftColor].matrix[rowNumber][i];
                sides[leftColor].matrix[rowNumber][i] = sides[currentColor % 2 == 0 ? currentColor + 1 : currentColor -
                                                                                                         1].matrix[rowNumber][i];
                sides[currentColor % 2 == 0 ? currentColor + 1 : currentColor - 1].matrix[rowNumber][i] = temp;
            }
        } else {
            // поворачиваем сторону под номером rowNumber (от нуля до rows-1) по часовой стрелки (левый поворот)
            for (int i = 0; i < columns; ++i) {
                temp = sides[leftColor].matrix[rowNumber][i];
                sides[leftColor].matrix[rowNumber][i] = sides[currentColor].matrix[rowNumber][i];
                sides[currentColor].matrix[rowNumber][i] = sides[rightColor].matrix[rowNumber][i];
                sides[rightColor].matrix[rowNumber][i] = sides[currentColor % 2 == 0 ? currentColor + 1 : currentColor -
                                                                                                          1].matrix[rowNumber][i];
                sides[currentColor % 2 == 0 ? currentColor + 1 : currentColor - 1].matrix[rowNumber][i] = temp;
            }
        }

        if (rowNumber == 0) {
            rotateSide(upColor, isInverse);
        } else if (rowNumber == rows - 1) {
            rotateSide(downColor, !isInverse);
        }

    }

}

void AbstractCube::sideRotationVertical(const int columnNumber, const bool isInverse) {
    if (columnNumber != (columns - 1) / 2) {
        short temp;
        if (isInverse) {
            // поворачиваем сторону под номером columnNumber (от нуля до columns-1) против часовой стрелки (опускаем вниз)
            for (int i = 0; i < rows; ++i) {
                temp = sides[upColor].matrix[i][columnNumber];
                sides[upColor].matrix[i][columnNumber] = sides[currentColor].matrix[i][columnNumber];
                sides[currentColor].matrix[i][columnNumber] = sides[downColor].matrix[i][columnNumber];
                sides[downColor].matrix[i][columnNumber] = sides[currentColor % 2 == 0 ? currentColor + 1 :
                                                                 currentColor - 1].matrix[i][columnNumber];
                sides[currentColor % 2 == 0 ? currentColor + 1 : currentColor - 1].matrix[i][columnNumber] = temp;
            }

        } else {
            // поворачиваем сторону под номером columnNumber (от нуля до columns-1) по часовой стрелки (поднимаем вверх)
            for (int i = 0; i < rows; ++i) {
                temp = sides[downColor].matrix[i][columnNumber];
                sides[downColor].matrix[i][columnNumber] = sides[currentColor].matrix[i][columnNumber];
                sides[currentColor].matrix[i][columnNumber] = sides[upColor].matrix[i][columnNumber];
                sides[upColor].matrix[i][columnNumber] = sides[currentColor % 2 == 0 ? currentColor + 1 : currentColor -
                                                                                                          1].matrix[i][columnNumber];
                sides[currentColor % 2 == 0 ? currentColor + 1 : currentColor - 1].matrix[i][columnNumber] = temp;
            }
        }

        if (columnNumber == 0) {
            rotateSide(leftColor, !isInverse);
        } else if (columnNumber == columns - 1) {
            rotateSide(rightColor, isInverse);
        }
    }

}

void AbstractCube::cubeRotationHorizontal(const bool direction) {
    // left - true
    // right - false
    if (direction) {
        leftColor = currentColor;
        currentColor = rightColor;
        rightColor = leftColor % 2 == 0 ?  leftColor + 1 : leftColor - 1;
    } else {
        rightColor = currentColor;
        currentColor = leftColor;
        leftColor = rightColor % 2 == 0 ? rightColor + 1 : rightColor - 1;
    }
}

void AbstractCube::cubeRotationVertical(bool direction) {
    // down - true
    // up - false
    if (direction) {
        downColor = currentColor;
        currentColor = upColor;
        upColor = downColor % 2 == 0 ? downColor + 1 : downColor - 1;
    } else {
        upColor = currentColor;
        currentColor = downColor;
        downColor = upColor % 2 == 0 ? upColor + 1 : upColor - 1;
    }
}

char AbstractCube::convertCodeToColor(const short colorCode) const {
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

void AbstractCube::rotateSide(int side, bool isInverse) {
    auto **original = new short *[rows];
    for (int k = 0; k < rows; ++k) {
        original[k] = new short[columns];
        for (int i = 0; i < columns; ++i) {
            original[k][i] = sides[side].matrix[k][i];
        }
    }
    if (isInverse) {
        for (int i = 0; i < sides[side].rows; ++i) {
            for (int j = 0; j < sides[side].columns; ++j) {
                sides[side].matrix[rows - 1 - j][i] = original[i][j];
            }
        }
    } else {
        for (int i = 0; i < sides[side].rows; ++i) {
            for (int j = 0; j < sides[side].columns; ++j) {
                sides[side].matrix[j][columns - 1 - i] = original[i][j];
            }
        }

    }

    for (int l = 0; l < rows; ++l) {
        delete[] original[l];
    }
    delete[] original;
}

char AbstractCube::getCurrentColor() const {
    return convertCodeToColor(currentColor);
}

char AbstractCube::getUpColor() const {
    return convertCodeToColor(upColor);
}

char AbstractCube::getDownColor() const {
    return convertCodeToColor(downColor);
}

char AbstractCube::getLeftColor() const {
    return convertCodeToColor(leftColor);
}

char AbstractCube::getRightColor() const {
    return convertCodeToColor(rightColor);
}

int AbstractCube::getRows() const {
    return rows;
}

int AbstractCube::getColumns() const {
    return columns;
}

char AbstractCube::getColor(const int row, const int column) const {
    return convertCodeToColor(sides[currentColor].matrix[row][column]);
}
