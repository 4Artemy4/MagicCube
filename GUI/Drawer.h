//
// Created by art on 9/6/20.
//

#ifndef RUBICKSCUBE_DRAWER_H
#define RUBICKSCUBE_DRAWER_H


#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include "../Cube/Cube.h"

class Drawer {
private:
    Cube cube;
    sf::Font commandsFont;
    sf::Text oldCommands;
public:
    Drawer(Cube cb);

    void mainWindow();

    void updateCube(sf::RenderWindow &window);

    void mashButton();

    void solveButton();

    void commandLine(char command, sf::RenderWindow &window);

    void enterCommand();
};


#endif //RUBICKSCUBE_DRAWER_H
