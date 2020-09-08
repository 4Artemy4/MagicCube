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
    sf::Text text;              ///< Text on the button
    sf::RenderWindow &parent;   ///< mainWindow
public:
    ///\brief Constructor
    ///\param window - mainWindow
    Button(sf::RenderWindow &window);

    ///\brief Compare mouse and button coordinates
    ///\param position - mouse coordinates
    ///\return true - mouse is located in button aria
    bool isPressed(sf::Vector2i position);

    ///\brief Set button Text
    void setText(const std::string &stroke);

    ///\brief Getter for button text
    const sf::Text &getText() const;

    ///\brief Getter for button parent
    sf::RenderWindow &getParent() const;
};


#endif //RUBICKSCUBE_BUTTON_H
