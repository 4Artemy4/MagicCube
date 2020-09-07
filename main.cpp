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


        Cube cube(3);
//    cube.command("H'");
    Drawer dr(cube);
        dr.mainWindow();
    std::cout << cube;
//    std::cin >> cube3;
//cube.command("V'0 H2 P'0 H' V0");
//cube.command("H'2");
//    cube3.command("B L U R F D R U L L' U' R' D' F' R' U' L' B'");
//    cube3.command("2B' 2L U' R 2F' D R U 2L'");
//    std::cout << cube;
//    cube.solve();
//    std::cout << cube;
//    cube3.command("F U");
//    std::cout << cube3;
//    cube3.rand();
//    std::cout << cube3;
//    cube3.load("file.txt");
//    cube3.redraw();
//    std::cout << cube3.check();


    return 0;
}
