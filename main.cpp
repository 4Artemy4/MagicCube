#include "Cube3.h"
#include "GUI/Drawer.h"

int main() {

    Cube cube(3);
//    cube.command("H'");
    Drawer dr(cube);
    dr.mainWindow();
    std::cout << cube;
//    std::cin >> cube3;
//    cube.command("V'0 H2 P'0 H' V0");
//    cube.command("H'2");
//    cube3.command("B L U R F D R U L L' U' R' D' F' R' U' L' B'");
//    cube3.command("2B' 2L U' R 2F' D R U 2L'");
//    std::cout << cube;
//    cube.solve();
//    std::cout << cube;


    return 0;
}
