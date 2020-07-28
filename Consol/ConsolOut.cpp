//
// Created by art on 7/27/20.
//

#include <iostream>
#include "ConsolOut.h"

ConsolOut::ConsolOut(AbstractCube &cube): cube(cube) {}

void ConsolOut::redraw() {
    for (int k = 0; k < cube.getColumns()+1; ++k) {
        std::cout << ' ';
    }
    std::cout << cube.getUpColor() << std::endl;
    for (int i = 0; i < cube.getRows(); ++i) {
        if (i == cube.getRows()/2) {
            std::cout << cube.getLeftColor() << ' ';
            for (int j = 0; j < cube.getColumns(); ++j) {
                std::cout << cube.getColor(i, j) << ' ';
            }
            std::cout << cube.getRightColor();
        }
        else{
            std::cout << "  ";
            for (int j = 0; j < cube.getColumns(); ++j) {
                std::cout << cube.getColor(i, j) << ' ';
            }
        }
        std::cout << std::endl;
    }
    for (int k = 0; k < cube.getColumns()+1; ++k) {
        std::cout << ' ';
    }
    std::cout << cube.getDownColor() << std::endl;

}



