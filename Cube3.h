//
// Created by art on 9/3/20.
//

#ifndef RUBICKSCUBE_CUBE3_H
#define RUBICKSCUBE_CUBE3_H


#include <iostream>
#include <string>
#include "Cube/Side.h"
#include "Cube/Cube.h"


class Cube3: public Cube {

public:
    ///\brief Constructor
    Cube3();

    ///\brief Command converter for 3x3 Cube
    bool command(const std::string &commands) override;

    ///\brief Forward side rotation
    ///\param isInverse - rotation direction \n
    ///true - anticlockwise \n
    ///false - clockwise \n
    void F(bool isInverse);

    ///\brief Backward side rotation
    ///\param isInverse - rotation direction \n
    ///true - anticlockwise \n
    ///false - clockwise \n
    void B(bool isInverse);

    ///\brief Right side rotation
    ///\param isInverse - rotation direction \n
    ///true - anticlockwise \n
    ///false - clockwise \n
    void R(bool isInverse);

    ///\brief Left side rotation
    ///\param isInverse - rotation direction \n
    ///true - anticlockwise \n
    ///false - clockwise \n
    void L(bool isInverse);

    ///\brief Up side rotation
    ///\param isInverse - rotation direction \n
    ///true - anticlockwise \n
    ///false - clockwise \n
    void U(bool isInverse);

    ///\brief Down side rotation
    ///\param isInverse - rotation direction \n
    ///true - anticlockwise \n
    ///false - clockwise \n
    void D(bool isInverse);

    ///\brief Input stream for 3x3 Cube
    friend std::istream &operator>>(std::istream &is, Cube3 &cube);

    ///\brief Random commands for 3x3 Cube
    std::string rand() override;
};


#endif //RUBICKSCUBE_CUBE3_H
