//
// Created by art on 9/6/20.
//

#include "Drawer.h"
#include "Button.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window.hpp>
#include <iostream>

Drawer::Drawer(Cube cb) : cube(cb) {}

void Drawer::mainWindow() {
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Magic Cube");
    window.setFramerateLimit(20);

    commandsFont.loadFromFile("GUI/CommandFont.ttf");
    oldCommands.setFont(commandsFont);
    oldCommands.setCharacterSize(30);
    oldCommands.setFillColor(sf::Color::Black);

    Button mash(window);
    mash.setPosition(100, 100);
    mash.setSize(sf::Vector2f(300, 150));
    mash.onCick(mashButton);

    Button solve(window);
    solve.setPosition(100, 400);
    solve.setSize(sf::Vector2f(300, 150));
    solve.onCick(solveButton);

    window.clear(sf::Color(192, 192, 192));

    sf::RectangleShape commandField;
    commandField.setPosition(50, 700);
    commandField.setSize(sf::Vector2f(1100, 50));

    window.draw(solve);
    window.draw(mash);
    window.draw(commandField);
    mash.setText("Random mash");
    solve.setText("Solve");
    updateCube(window);
    commandLine(' ', window);
    sf::Event event;

    while (window.isOpen()) {
        switch (event.type) {
            case sf::Event::Closed: {
                window.close();
                break;
            }
            case sf::Event::KeyPressed: {
                commandLine(event.key.code, window);
                break;
            }
            case sf::Event::MouseButtonPressed : {
                mash.isPressed(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
                break;
            }
        }
        window.display();
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
                    element.setFillColor(sf::Color(211, 84, 0));
                    window.draw(element);
                    break;
                }
                case 4: {
                    element.setFillColor(sf::Color::Blue);
                    window.draw(element);
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

}

void Drawer::solveButton() {

}

void Drawer::commandLine(char command, sf::RenderWindow &window) {
    oldCommands.setString(oldCommands.getString() + command + ' ' + "qwerty");
    oldCommands.setPosition(50, 700);
    window.draw(oldCommands);
}

void Drawer::enterCommand() {

}
