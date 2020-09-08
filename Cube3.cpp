#include <string>
#include "Cube3.h"


Cube3::Cube3(): Cube(3){}

bool Cube3::command(const std::string &commands){
    short times;
    bool isInverse;
    for (int i = 0; i < commands.size(); ++i) {
        times = 1;
        isInverse = false;
        if (commands[i] != ' ') {
            if (commands[i] == '2') {
                times = 2;
                i++;
            }
            if (commands[i + 1] == '\'') isInverse = true;
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
                default:
                    return false;
            }
            while (commands[i] != ' ' && i < commands.size())i++;
        }
    }
    return true;
}

void Cube3::F(bool isInverse) {
    rotateLayer(isInverse, 0);
    rotations += 'F';
    if (isInverse) rotations+= '\'';
    rotations+=' ';
}

void Cube3::B(bool isInverse) {
    rotateLayer(isInverse, 2);
    rotations += 'B';
    if (isInverse) rotations+= '\'';
    rotations+=' ';

}

void Cube3::L(bool isInverse) {
    rotateLayerVertically(isInverse, 0);
    rotations += 'L';
    if (isInverse) rotations+= '\'';
    rotations+=' ';

}

void Cube3::R(bool isInverse) {
    rotateLayerVertically(isInverse, 2);
    rotations += 'R';
    if (isInverse) rotations+= '\'';
    rotations+=' ';

}

void Cube3::U(bool isInverse) {
    rotateLayerHorizontally(isInverse, 0);
    rotations += 'U';
    if (isInverse) rotations+= '\'';
    rotations+=' ';

}

void Cube3::D(bool isInverse) {
    rotateLayerHorizontally(isInverse, 0);
    rotations += 'D';
    if (isInverse) rotations+= '\'';
    rotations+=' ';

}

std::string Cube3::rand() {
    std::string result;
    srand(time(0));
    for (int i = 0; i < 15; ++i) {
        switch (std::rand()%6) {
            case 0:{
                F(false);
                result+='F';
                break;
            }
            case 1:{
                B(false);
                result+='B';
                break;
            }
            case 2:{
                L(false);
                result+='L';
                break;
            }
            case 3:{
                R(false);
                result+='R';
                break;
            }
            case 4:{
                U(false);
                result+='4';
                break;
            }
            case 5:{
                D(false);
                result+='D';
                break;
            }
        }
        result+=' ';
    }
    return result;
}

std::istream &operator>>(std::istream &is, Cube3 &cube) {
    std::string command;
    is>>command;
    cube.command(command);
    return is;
}
