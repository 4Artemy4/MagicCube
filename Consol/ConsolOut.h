//
// Created by art on 7/27/20.
//

#ifndef RUBICKSCUBE_CONSOLOUT_H
#define RUBICKSCUBE_CONSOLOUT_H


#include "../Abstract Cube/AbstractCube.h"

class ConsolOut {
public:
    ConsolOut(AbstractCube &cube);
    void redraw();
private:

    AbstractCube &cube;
};
#endif //RUBICKSCUBE_CONSOLOUT_H
