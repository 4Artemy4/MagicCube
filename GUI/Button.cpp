//
// Created by art on 9/6/20.
//

#include <iostream>
#include "Button.h"

Button::Button(sf::RenderWindow &window) : parent(window) {
    sf::Texture *buttonTexture = new sf::Texture();
    buttonTexture->loadFromFile("GUI/ButtonTexture.png");
    setTexture(buttonTexture);
    update();
}

void Button::isPressed(sf::Vector2f position) {
    if (getPosition() == position) function();
}

void Button::onCick(void (*fun)()) {
    function = fun;
}

void Button::setText(const std::string &stroke) {
    sf::Font font;
    font.loadFromFile("GUI/font.ttf");
    text.setString(stroke);
    text.setFont(font);
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::Black);
    text.setPosition(getPosition().x + getSize().x/2 - stroke.size()*9, getPosition().y + getSize().y / 2 - 20);
    parent.draw(text);
//    update();
}
