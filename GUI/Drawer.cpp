//
// Created by art on 9/6/20.
//

#include "Drawer.h"
#include "Button.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window.hpp>
#include <iostream>

#define ITEM(x) case sf::Keyboard:: ## x : ret = #x; break;

Drawer::Drawer(Cube cb) : cube(cb) {}

void Drawer::mainWindow() {
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Magic Cube");
    window.clear(sf::Color(192, 192, 192));

    commandsFont.loadFromFile("GUI/CommandFont.ttf");
    oldCommands.setFont(commandsFont);
    oldCommands.setCharacterSize(30);
    oldCommands.setFillColor(sf::Color::Black);

    Button mash(window);
    mash.setPosition(100, 100);
    mash.setSize(sf::Vector2f(300, 150));

    Button solve(window);
    solve.setPosition(100, 400);
    solve.setSize(sf::Vector2f(300, 150));


    sf::RectangleShape commandField;
    commandField.setPosition(50, 700);
    commandField.setSize(sf::Vector2f(1100, 50));

    window.draw(solve);
    window.draw(mash);
    window.draw(commandField);
    updateCube(window);
    mash.setText("Random mash");
    solve.setText("Solve");

    sf::Event event;
    window.display();

    while (window.isOpen()) {

        window.pollEvent(event);
        switch (event.type) {
            case sf::Event::Closed: {
                window.close();
                break;
            }
            case sf::Event::KeyPressed: {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::V)) {
                    window.draw(commandField);
                    commandLine('V', window);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)) {
                    window.draw(commandField);
                    commandLine('H', window);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
                    window.draw(commandField);
                    commandLine('P', window);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0)) {
                    window.draw(commandField);
                    commandLine('0', window);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
                    window.draw(commandField);
                    commandLine('1', window);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
                    window.draw(commandField);
                    commandLine('2', window);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
                    window.draw(commandField);
                    commandLine('3', window);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) {
                    window.draw(commandField);
                    commandLine('4', window);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5)) {
                    window.draw(commandField);
                    commandLine('5', window);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6)) {
                    window.draw(commandField);
                    commandLine('6', window);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7)) {
                    window.draw(commandField);
                    commandLine('7', window);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8)) {
                    window.draw(commandField);
                    commandLine('8', window);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9)) {
                    window.draw(commandField);
                    commandLine('9', window);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Quote)) {
                    window.draw(commandField);
                    commandLine('\'', window);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace)) {
                    window.draw(commandField);
                    commandLine('\b', window);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                    enterCommand();
                    updateCube(window);
                }
                window.display();
                break;
            }
            case sf::Event::MouseButtonPressed : {
                if (mash.isPressed(sf::Mouse::getPosition(window))) mashButton();
                if (solve.isPressed(sf::Mouse::getPosition(window))) solveButton();
                updateCube(window);
                window.display();
                sf::sleep(sf::milliseconds(10));
                break;
            }
        }
    }

}

void Drawer::updateCube(sf::RenderWindow &window) {
    const int elementSize = 600 / cube.getSize();
    for (int i = 0; i < cube.getSize(); ++i) {
        for (int j = 0; j < cube.getSize(); ++j) {
            sf::RectangleShape element(sf::Vector2f(elementSize, elementSize));
            element.setPosition(550 + j * elementSize, 50 + i * elementSize);
            element.setOutlineThickness(3);
            switch (cube.getColor(0, i, j)) {
                case 0: {
                    element.setFillColor(sf::Color(229, 231, 233));
                    window.draw(element);
                    break;
                }
                case 1: {
                    element.setFillColor(sf::Color::Yellow);
                    window.draw(element);
                    break;
                }
                case 2: {
                    element.setFillColor(sf::Color::Red);
                    window.draw(element);
                    break;
                }
                case 3: {
                    element.setFillColor(sf::Color(243, 156, 18));
                    window.draw(element);
                    break;
                }
                case 4: {
                    element.setFillColor(sf::Color::Blue);
                    window.draw(element);
                    break;
                }
                case 5: {
                    element.setFillColor(sf::Color::Green);
                    window.draw(element);
                    break;
                }
            }
        }
    }
}

void Drawer::mashButton() {
    cube.rand();
}

void Drawer::solveButton() {
    cube.solve();
}

void Drawer::commandLine(char command, sf::RenderWindow &window) {
    if (command == '\b')
        oldCommands.setString(oldCommands.getString().substring(0, oldCommands.getString().getSize() - 1));
    else if (command == 'V' || command == 'H' || command == 'P')
        oldCommands.setString(oldCommands.getString() + " " + command);
    else {
        oldCommands.setString(oldCommands.getString() + command);
    }
    oldCommands.setPosition(50, 700);
    window.draw(oldCommands);
}

void Drawer::enterCommand() {
    cube.solve();
    cube.command(oldCommands.getString());
}
