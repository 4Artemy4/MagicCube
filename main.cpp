#include "Cube3.h"
#include "GUI/Drawer.h"

int main() {
//    Cube cb(5);
//    cb.redraw();
//    cb.rotateLayerVertically(true, 1);
//    cb.rotateLayerVertically(true, 1);
//    cb.rotateLayerVertically(true, 3);
//    cb.rotateLayerVertically(true, 3);
//    cb.redraw();
//    cb.rotateLayer(true, 1);
//    cb.rotateLayer(true, 1);
//    cb.rotateLayer(true, 3);
//    cb.rotateLayer(true, 3);
//    cb.redraw();
//    cb.rotateLayerHorizontally(true, 1);
//    cb.rotateLayerHorizontally(true, 1);
//    cb.rotateLayerHorizontally(true, 3);
//    cb.rotateLayerHorizontally(true, 3);
//    cb.redraw();


        Cube3 cube3;
    cube3.command("L");
    Drawer dr(cube3);
        dr.mainWindow();
    std::cout << cube3;
//    std::cin >> cube3;
//    cube3.command("B L U R F D R U L L' U' R' D' F' R' U' L' B'");
    std::cout << cube3;
//    cube3.command("F U");
//    std::cout << cube3;
//    cube3.rand();
//    std::cout << cube3;
//    cube3.load("file.txt");
//    cube3.redraw();
//    std::cout << cube3.check();


    return 0;
}
