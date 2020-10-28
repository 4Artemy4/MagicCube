
#include "Cube/Cube.h"
#include "GUI/Drawer.h"

// Press H to horizontally rotation
// Press V to vertically rotation
// Press P to front rotation
// Press enter 
int main() {
    Cube cube8(8);
    Drawer drawer(cube8);
    drawer.mainWindow();
    return 0;
}
