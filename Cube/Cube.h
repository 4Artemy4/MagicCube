//
// Created by art on 9/3/20.
//

#ifndef RUBICKSCUBE_CUBE_H
#define RUBICKSCUBE_CUBE_H


#include "Side.h"

class Cube {
protected:
    void rotateSide(int side, bool isInverse);
    Side sides[6];
    int size;
    const short currentColor = 0, backwardColor = 1, upColor = 2, downColor = 3, leftColor = 4, rightColor = 5;
public:
    Cube(int n);
    void redraw() const;
    static char convertCodeToColor(short colorCode) ;
    void rotateLayerVertically(bool isInverse, int layer);
    void rotateLayerHorizontally(bool isInverse, int layer);
    void rotateLayer(bool isInverse, int layer);
};


#endif //RUBICKSCUBE_CUBE_H
