#ifndef ARKA_STANDARD_BRICK_HXX
#define ARKA_STANDARD_BRICK_HXX

#include <SFML/Graphics.hpp>

namespace arka {

inline void StandardBrick::initiate(sf::RectangleShape& a_brick)
{
    a_brick.setFillColor(sf::Color::Magenta);
    a_brick.setOutlineThickness(a_brick.getSize().y * 0.2);
    a_brick.setOutlineColor(sf::Color::Black);
}

} // arka

#endif /* ARKA_STANDARD_BRICK_HXX */