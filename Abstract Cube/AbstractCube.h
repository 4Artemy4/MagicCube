//
// Created by art on 7/25/20.
//

#ifndef RUBICKSCUBE_ABSTRACTCUBE_H
#define RUBICKSCUBE_ABSTRACTCUBE_H

// 0 - white
// 1 - yellow
// 2 - red
// 3 - orange
// 4 - blue
// 5 - green

// Standards:
// up - true
// down - false
// left - true
// right - false

#include "Side.h"

class AbstractCube {


public:
    AbstractCube();

    AbstractCube(int rows, int columns);

    char getCurrentColor() const;

    char getUpColor() const;

    char getDownColor() const;

    char getLeftColor() const;

    char getRightColor() const;

    int getRows() const;

    int getColumns() const;

    char getColor(int row, int column) const;

    void sideRotationHorizontal(int rowNumber, bool isInverse);
    void sideRotationVertical(int columnNumber, bool isInverse);
    void cubeRotationHorizontal(bool direction);
    void cubeRotationVertical(bool direction);
    char convertCodeToColor(short colorCode) const;

protected:
    void rotateSide(int side, bool isInverse);
    Side sides[6];
    short currentColor = 0, upColor = 2, downColor = 3, leftColor = 4, rightColor = 5;
    int rows = 1, columns = 1;
};


#endif //RUBICKSCUBE_ABSTRACTCUBE_H
