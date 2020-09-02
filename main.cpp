#include "Cube3.h"

int main() {
    Cube cb(5);
    cb.redraw();
    cb.rotateLayerVertically(true, 1);
    cb.rotateLayerVertically(true, 1);
    cb.rotateLayerVertically(true, 3);
    cb.rotateLayerVertically(true, 3);
    cb.redraw();
    cb.rotateLayer(true, 1);
    cb.rotateLayer(true, 1);
    cb.rotateLayer(true, 3);
    cb.rotateLayer(true, 3);
    cb.redraw();
    cb.rotateLayerHorizontally(true, 1);
    cb.rotateLayerHorizontally(true, 1);
    cb.rotateLayerHorizontally(true, 3);
    cb.rotateLayerHorizontally(true, 3);
    cb.redraw();


    //    Cube3 cube3;
//    cube3.redraw();
//    cube3.command("B L U R F D R U L L' U' R' D' F' R' U' L' B'");
//    cube3.command("F U");
//    cube3.rand();
//    cube3.load("file.txt");
//    cube3.redraw();
//    std::cout << cube3.check();


    return 0;
}
