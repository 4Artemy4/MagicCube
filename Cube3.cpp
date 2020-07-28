//
// Created by art on 7/25/20.
//

#include <string>
#include "Cube3.h"

Cube3::Cube3() {
    rows = 3;
    columns = 3;
    for (short i = 0; i < 6; ++i) {
        sides[i] = Side(3, 3, i);
    }
}

bool Cube3::command(const std::string &commands) {
    short times;
    bool isInverse;
    for (int i = 0; i < commands.size(); ++i) {
        times = 1;
        isInverse = false;
        if (commands[i] != ' '){
            if (commands[i] == '2') {times = 2; i++;}
            if (commands[i+1] == '\'') isInverse = true;
            switch (commands[i]) {
                case 'F': {
                    for (int j = 0; j < times; ++j) {
                        F(isInverse);
                    }
                    break;
                }
                case 'B': {
                    for (int j = 0; j < times; ++j) {
                        B(isInverse);
                    }
                    break;
                }
                case 'L': {
                    for (int j = 0; j < times; ++j) {
                        L(isInverse);
                    }
                    break;
                }
                case 'R': {
                    for (int j = 0; j < times; ++j) {
                        R(isInverse);
                    }
                    break;
                }
                case 'U': {
                    for (int j = 0; j < times; ++j) {
                        U(isInverse);
                    }
                    break;
                }
                case 'D': {
                    for (int j = 0; j < times; ++j) {
                        D(isInverse);
                    }
                    break;
                }
                default: return false;
            }
            while (commands[i]!=' ' && i<commands.size())i++;
        }
    }
    return true;
}

void Cube3::F(bool isInverse) {
    cubeRotationHorizontal(false);
    sideRotationVertical(0, isInverse);
    cubeRotationHorizontal(true);
}

void Cube3::B(bool isInverse) {
    cubeRotationHorizontal(false);
    sideRotationVertical(2, isInverse);
    cubeRotationHorizontal(true);
}

void Cube3::L(bool isInverse) {
    sideRotationVertical(0, isInverse);
}

void Cube3::R(bool isInverse) {
    sideRotationVertical(2, isInverse);

}

void Cube3::U(bool isInverse) {
    sideRotationHorizontal(0, isInverse);
}

void Cube3::D(bool isInverse) {
    sideRotationHorizontal(2, isInverse);
}


