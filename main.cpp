#include "Cube/Cube.h"
#include "GUI/Drawer.h"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE(){
    SECTION("vertical rotation"){
        REQUIRE(Cube::testVerticalRotation());
    }
    SECTION("horizontal rotation"){
        REQUIRE(Cube::testHorizontalRotation());
    }
    SECTION("front rotation"){
        REQUIRE(Cube::testFrontRotation());
    }
}

//int main() {
//
//    Cube cube(3);
//    Drawer dr(cube);
//    dr.mainWindow();
//    return 0;
//}
