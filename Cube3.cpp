#include <string>
#include <fstream>
#include "Cube3.h"


/*
 * Нумерация массивов
 *
 *                    [0,0] [0,1] [0,2]
 *                    [1,0]   R   [1,2]
 *                    [2,0] [2,1] [2,2]
 *
 * [0,0] [0,1] [0,2]  [0,0] [0,1] [0,2]  [0,0] [0,1] [0,2]
 * [1,0]   B   [1,2]  [1,0]   W   [1,2]  [1,0]   G   [1,2]
 * [2,0] [2,1] [2,2]  [2,0] [2,1] [2,2]  [2,0] [2,1] [2,2]
 *
 *                    [0,0] [0,1] [0,2]
 *                    [1,0]   O   [1,2]
 *                    [2,0] [2,1] [2,2]
 *
*/
Cube3::Cube3(): Cube(3){}

/*
Преобразование Языка вращения кубика Рубика в
последвательность поворотов
F - поворот фронтальной грани
B - поворот задней грани
L - поворот левой грани
R - поворот правой грани
U - поворот верхней грани
D - поворот нижней грани

Все повороты выполняются по часовой стрелке
Если после буквы стоит ' - поворот выполняется против часовой стрелки
Если перед буквой стоит число 2 - выполняется двойной поворот (на 180 градусов)
*/
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
}

void Cube3::B(bool isInverse) {
    rotateLayer(isInverse, 2);
}

void Cube3::L(bool isInverse) {
    rotateLayerVertically(isInverse, 0);
}

void Cube3::R(bool isInverse) {
    rotateLayerVertically(isInverse, 2);
}

void Cube3::U(bool isInverse) {
    rotateLayerHorizontally(isInverse, 0);
}

void Cube3::D(bool isInverse) {
    rotateLayerHorizontally(isInverse, 0);

}

void Cube3::rand() {
    srand(time(0));
    for (int i = 0; i < 15; ++i) {
        switch (std::rand()%6) {
            case 0:{
                F(false);
                break;
            }
            case 1:{
                B(false);
                break;
            }
            case 2:{
                L(false);
                break;
            }
            case 3:{
                R(false);
                break;
            }
            case 4:{
                U(false);
                break;
            }
            case 5:{
                B(false);
                break;
            }
        }
    }
}

bool Cube3::check() const {
    for (int k = 0; k < 5; ++k) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (sides[currentColor].matrix[i][j] != 0) return false;
            }
        }
    }
    return true;
}

void Cube3::load(const std::string &filename) {
    std::fstream file(filename);
    std::string command;
    getline(file, command);
    this->command(command);
}
