//
// Created by art on 9/6/20.
//

#include <iostream>
#include "Button.h"
#include "Drawer.h"

Button::Button(sf::RenderWindow &window) : parent(window) {
    sf::Texture *buttonTexture = new sf::Texture();
    buttonTexture->loadFromFile("GUI/ButtonTexture.png");
    setTexture(buttonTexture);
    update();
}

bool Button::isPressed(sf::Vector2i position) {
    if ((position.x >= getPosition().x && position.x <= getPosition().x + getSize().x) &&
        (position.y >= getPosition().y && position.y <= getPosition().y + getSize().y))
        return true;
    return false;
}

void Button::setText(const std::string &stroke) {
    sf::Font font;
    font.loadFromFile("GUI/font.ttf");
    text.setString(stroke);
    text.setFont(font);
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::Black);
    text.setPosition(getPosition().x + getSize().x / 2 - stroke.size() * 9, getPosition().y + getSize().y / 2 - 20);
    parent.draw(text);
}

const sf::Text &Button::getText() const {
    return text;
}

sf::RenderWindow &Button::getParent() const {
    return parent;
}

