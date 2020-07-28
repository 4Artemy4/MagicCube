#include "Abstract Cube/AbstractCube.h"
#include "Consol/ConsolOut.h"
#include "Cube3.h"

int main() {
    Cube3 cube3;
    ConsolOut clOut(cube3);
    clOut.redraw();
//    cube3.command("L R' 2U L'");
cube3.command("B");
    clOut.redraw();

//    cube3.cubeRotationVertical(true);
//    clOut.redraw();

//    cube3.L(false);
    cube3.cubeRotationHorizontal(false);
    clOut.redraw();

    cube3.cubeRotationHorizontal(false);
    cube3.cubeRotationHorizontal(false);
    clOut.redraw();


    return 0;
}
