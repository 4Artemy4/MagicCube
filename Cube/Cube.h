//
// Created by art on 9/3/20.
//

#ifndef RUBICKSCUBE_CUBE_H
#define RUBICKSCUBE_CUBE_H


#include <ostream>
#include "Side.h"

class Cube {
protected:
    Side sides[6];
    int size;
    static char colors[6];
    const short currentColor = 0, backwardColor = 1, upColor = 2, downColor = 3, leftColor = 4, rightColor = 5;
    std::string rotations;

    void rotateSide(int side, bool isInverse);

public:

    ///\brief Constructor
    Cube(int n);

    ///\brief Convert color code to color char
    ///\param colorCode
    ///\details: \n
    /// 0 - White
    /// 1 - Yellow
    /// 2 - Red
    /// 3 - Orange
    /// 4 - Blue
    /// 5 - Green
    static char convertCodeToColor(short colorCode);

    ///\brief Rotate layer vertically
    ///\param isInverse If false - clockwise rotation, true - anticlockwise rotation
    void rotateLayerVertically(bool isInverse, int layer);

    ///\brief Rotate layer horizontally
    ///\param isInverse If false - clockwise rotation, true - anticlockwise rotation
    void rotateLayerHorizontally(bool isInverse, int layer);

    ///\brief Rotate layer
    ///\param isInverse If false - clockwise rotation, true - anticlockwise rotation
    void rotateLayer(bool isInverse, int layer);

    ///\brief Output stream operator
    ///\param os output stream
    ///\param cube
    ///\return Output stream
    friend std::ostream &operator<<(std::ostream &os, const Cube &cube);

    ///\brief Output stream operator
    ///\param os output stream
    ///\param cube
    ///\return Output stream
    friend std::istream &operator>>(std::istream &is, Cube &cube);

    virtual bool command(const std::string &commands);

    virtual void rand();

    bool check() const;

    void load(const std::string &filename);

    int getSize() const;

    const std::string &getRotations() const;

    short getColor(short sideColor, int i, int j)const;
};


#endif //RUBICKSCUBE_CUBE_H
