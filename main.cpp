
#include "Cube/Cube.h"
#include "GUI/Drawer.h"

int main() {
    Cube cube8(8);
    Drawer drawer(cube8);
    drawer.mainWindow();
    return 0;
}
