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
    Cube cube;              ///< Cube we work with
    sf::Font commandsFont;  ///< Font for CommandLine
    sf::Text CommandLine;   ///< Edit aria with commands

public:
    Drawer(Cube cb);

    ///\brief Initialising components
    void mainWindow();

    ///\brief Redrawing Cube
    ///\param window - mainWindow
    void updateCube(sf::RenderWindow &window);

    ///\brief Button for mashing the Cube
    ///\return string with commands in "Cube rotation language"
    std::string mashButton();

    ///\brief Button for solve Cube
    void solveButton();

    ///\brief Redrawing commandLine aria
    ///\param command - command in "Cube rotation language"
    ///\param window - mainWindow
    void commandLine(char command, sf::RenderWindow &window);

    ///\brief Update Cube after writing commands;
    void enterCommand();
};


#endif //RUBICKSCUBE_DRAWER_H
