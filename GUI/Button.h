//
// Created by art on 9/6/20.
//

#ifndef RUBICKSCUBE_BUTTON_H
#define RUBICKSCUBE_BUTTON_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include "Drawer.h"

class Button : public sf::RectangleShape {
private:
    sf::Text text;
    sf::RenderWindow &parent;
public:
    Button(sf::RenderWindow &window);
    bool isPressed(sf::Vector2i position);
    void setText(const std::string &stroke);
};


#endif //RUBICKSCUBE_BUTTON_H
