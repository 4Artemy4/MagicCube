//
// Created by art on 9/6/20.
//

#include "Drawer.h"
#include "Button.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window.hpp>
#include <iostream>

#define KEY_PRESSED(x) else if (sf::Keyboard::isKeyPressed(sf::Keyboard::x)) { window.draw(commandField);commandLine(((#x)[0]), window);}
#define KEY_PRESSED_NUM(x) else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num##x)) { window.draw(commandField);commandLine(((#x)[0]), window);}

Drawer::Drawer(Cube cb) : cube(cb) {}

void Drawer::mainWindow() {
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Magic Cube");
    window.clear(sf::Color(192, 192, 192));

    commandLineInit();

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

    sf::Event event{};
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
                KEY_PRESSED(H)
                KEY_PRESSED(P)
                KEY_PRESSED_NUM(0)
                KEY_PRESSED_NUM(1)
                KEY_PRESSED_NUM(2)
                KEY_PRESSED_NUM(3)
                KEY_PRESSED_NUM(4)
                KEY_PRESSED_NUM(5)
                KEY_PRESSED_NUM(6)
                KEY_PRESSED_NUM(7)
                KEY_PRESSED_NUM(8)
                KEY_PRESSED_NUM(9)
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace)) {
                    window.draw(commandField);
                    commandLine('\b', window);
                } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                    enterCommand();
                    updateCube(window);
                }
                window.display();
                break;
            }
            case sf::Event::MouseButtonPressed: {
                onMouseClick(window, mash, solve, commandField);
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

std::string Drawer::mashButton() {
    return cube.rand();
}

void Drawer::solveButton() {
    cube.solve();
}

void Drawer::commandLine(char command, sf::RenderWindow &window) {
    if (command == '\b')
        CommandLine.setString(CommandLine.getString().substring(0, CommandLine.getString().getSize() - 1));
    else if (command == 'V' || command == 'H' || command == 'P')
        CommandLine.setString(CommandLine.getString() + " " + command);
    else {
        CommandLine.setString(CommandLine.getString() + command);
    }
    CommandLine.setPosition(50, 700);
    window.draw(CommandLine);
}

void Drawer::enterCommand() {
    cube.solve();
    cube.command(CommandLine.getString());
}

void Drawer::commandLineInit() {
    commandsFont.loadFromFile("GUI/CommandFont.ttf");
    CommandLine.setFont(commandsFont);
    CommandLine.setCharacterSize(30);
    CommandLine.setFillColor(sf::Color::Black);
}

void Drawer::onMouseClick(sf::RenderWindow &window, Button &mash, Button &solve, sf::RectangleShape &commandField) {
    if (mash.isPressed(sf::Mouse::getPosition(window))) {
        window.draw(commandField);
        CommandLine.setString(mashButton());
        commandLine('\b', window);
        enterCommand();
    }
    if (solve.isPressed(sf::Mouse::getPosition(window))) {
        window.draw(commandField);
        solveButton();
    }
    updateCube(window);
    window.display();
    sf::sleep(sf::milliseconds(10));
}
