////
//// Created by art on 9/22/20.
////
//
#include "../catch.hpp"
#include "../Cube/Cube.h"

TEST_CASE(){
    SECTION("vertical rotation (clockwise)"){
        Cube correct(3);
        Cube test(3);
        test.rotateLayerVertically(false, 0);

        short temp[3];
        temp[0] = correct.getColor(0, 0, 0);
        temp[1] = correct.getColor(0, 1, 0);
        temp[2] = correct.getColor(0, 2, 0);

        correct.setColor(correct.getColor(2, 0, 0), 0, 0, 0);
        correct.setColor(correct.getColor(2, 1, 0), 0, 1, 0);
        correct.setColor(correct.getColor(2, 2, 0), 0, 2, 0);

        correct.setColor(correct.getColor(1, 0, 0), 2, 0, 0);
        correct.setColor(correct.getColor(1, 1, 0), 2, 1, 0);
        correct.setColor(correct.getColor(1, 2, 0), 2, 2, 0);

        correct.setColor(correct.getColor(3, 0, 0), 1, 0, 0);
        correct.setColor(correct.getColor(3, 1, 0), 1, 1, 0);
        correct.setColor(correct.getColor(3, 2, 0), 1, 2, 0);

        correct.setColor(temp[0], 3, 0, 0);
        correct.setColor(temp[1], 3, 1, 0);
        correct.setColor(temp[2], 3, 2, 0);

        REQUIRE(correct == test);
    }
    SECTION("vertical rotation (anticlockwise)"){
        Cube correct(3);
        Cube test(3);
        test.rotateLayerVertically(true, 0);

        short temp[3];
        temp[0] = correct.getColor(0, 0, 0);
        temp[1] = correct.getColor(0, 1, 0);
        temp[2] = correct.getColor(0, 2, 0);

        correct.setColor(correct.getColor(3, 0, 0), 0, 0, 0);
        correct.setColor(correct.getColor(3, 1, 0), 0, 1, 0);
        correct.setColor(correct.getColor(3, 2, 0), 0, 2, 0);

        correct.setColor(correct.getColor(1, 0, 0), 3, 0, 0);
        correct.setColor(correct.getColor(1, 1, 0), 3, 1, 0);
        correct.setColor(correct.getColor(1, 2, 0), 3, 2, 0);

        correct.setColor(correct.getColor(2, 0, 0), 1, 0, 0);
        correct.setColor(correct.getColor(2, 1, 0), 1, 1, 0);
        correct.setColor(correct.getColor(2, 2, 0), 1, 2, 0);

        correct.setColor(temp[0], 2, 0, 0);
        correct.setColor(temp[1], 2, 1, 0);
        correct.setColor(temp[2], 2, 2, 0);

        REQUIRE(correct == test);
    }
    SECTION("horizontal rotation (clockwise)"){
        Cube correct(3);
        Cube test(3);

        test.rotateLayerHorizontally(false, 0);

        short temp[3];
        temp[0] = correct.getColor(0, 0, 0);
        temp[1] = correct.getColor(0, 0, 1);
        temp[2] = correct.getColor(0, 0, 2);

        correct.setColor(correct.getColor(5, 0, 0), 0, 0, 0);
        correct.setColor(correct.getColor(5, 0, 1), 0, 0, 1);
        correct.setColor(correct.getColor(5, 0, 2), 0, 0, 2);

        correct.setColor(correct.getColor(1, 0, 0), 5, 0, 0);
        correct.setColor(correct.getColor(1, 0, 0), 5, 0, 1);
        correct.setColor(correct.getColor(1, 0, 0), 5, 0, 2);

        correct.setColor(correct.getColor(4, 0, 0), 1, 0, 0);
        correct.setColor(correct.getColor(4, 0, 1), 1, 0, 1);
        correct.setColor(correct.getColor(4, 0, 2), 1, 0, 2);

        correct.setColor(temp[0], 4, 0, 0);
        correct.setColor(temp[1], 4, 0, 1);
        correct.setColor(temp[2], 4, 0, 2);

        REQUIRE(correct == test);
    }
    SECTION("horizontal rotation(anticlockwise)"){
        Cube correct(3);
        Cube test(3);

        test.rotateLayerHorizontally(true, 0);

        short temp[3];
        temp[0] = correct.getColor(0, 0, 0);
        temp[1] = correct.getColor(0, 0, 1);
        temp[2] = correct.getColor(0, 0, 2);

        correct.setColor(correct.getColor(4, 0, 0), 0, 0, 0);
        correct.setColor(correct.getColor(4, 0, 1), 0, 0, 1);
        correct.setColor(correct.getColor(4, 0, 2), 0, 0, 2);

        correct.setColor(correct.getColor(1, 0, 0), 4, 0, 0);
        correct.setColor(correct.getColor(1, 0, 0), 4, 0, 1);
        correct.setColor(correct.getColor(1, 0, 0), 4, 0, 2);

        correct.setColor(correct.getColor(5, 0, 0), 1, 0, 0);
        correct.setColor(correct.getColor(5, 0, 1), 1, 0, 1);
        correct.setColor(correct.getColor(5, 0, 2), 1, 0, 2);

        correct.setColor(temp[0], 5, 0, 0);
        correct.setColor(temp[1], 5, 0, 1);
        correct.setColor(temp[2], 5, 0, 2);

        REQUIRE(correct == test);
    }
    SECTION("loading from file"){
        Cube correct(3);
        Cube test(3);
        correct.command("V H P");
        test.load("Tests/test1");
        REQUIRE(correct == test);
    }
    SECTION("solver"){
        Cube correct(3);
        Cube testSolved(3);

        testSolved.rand();
        testSolved.solve();

        REQUIRE(correct == testSolved);
    }
    SECTION("equality"){
        Cube a(3);
        Cube b(3);
        REQUIRE(a == b);
    }
}
