//
// Created by art on 9/6/20.
//

#ifndef RUBICKSCUBE_BUTTON_H
#define RUBICKSCUBE_BUTTON_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>

class Button : public sf::RectangleShape {
private:
    sf::Text text;
    sf::RenderWindow &parent;
    void (*function)();
public:
    Button(sf::RenderWindow &window);
    void isPressed(sf::Vector2f position);
    void onCick(void (*fun)());
    void setText(const std::string &stroke);
};


#endif //RUBICKSCUBE_BUTTON_H
