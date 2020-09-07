//
// Created by art on 7/25/20.
//

#ifndef RUBICKSCUBE_CUBE3_H
#define RUBICKSCUBE_CUBE3_H


#include <iostream>
#include <string>
#include "Cube/Side.h"
#include "Cube/Cube.h"


class Cube3: public Cube {

public:
    Cube3();
    bool command(const std::string &commands);
    void F(bool isInverse);
    void B(bool isInverse);
    void R(bool isInverse);
    void L(bool isInverse);
    void U(bool isInverse);
    void D(bool isInverse);

    friend std::istream &operator>>(std::istream &is, Cube3 &cube);

    void rand() override;
};


#endif //RUBICKSCUBE_CUBE3_H
