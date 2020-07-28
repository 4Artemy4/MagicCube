//
// Created by art on 7/25/20.
//

#ifndef RUBICKSCUBE_CUBE3_H
#define RUBICKSCUBE_CUBE3_H


#include "Abstract Cube/AbstractCube.h"
#include <iostream>
#include <string>

class Cube3: public AbstractCube {
public:
    Cube3();
    bool command(const std::string &commands);
    void F(bool isInverse);
    void B(bool isInverse);
    void R(bool isInverse);
    void L(bool isInverse);
    void U(bool isInverse);
    void D(bool isInverse);

};


#endif //RUBICKSCUBE_CUBE3_H
