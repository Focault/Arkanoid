#ifndef ARKA_RESPONSE_KEY_PRESSED_HXX
#define ARKA_RESPONSE_KEY_PRESSED_HXX

#include <SFML/Graphics.hpp>

namespace arka {

inline bool KeyPressed::execute(float& a_speedFactor, sf::Keyboard::Key& a_key)
{
    switch (a_key) {
    case sf::Keyboard::Right:
        a_speedFactor = 1;
        break;
    case sf::Keyboard::Left:
        a_speedFactor = -1;
        break;
    case sf::Keyboard::Space:
        return true;
    default: break;
    }
    return false;
}

} // arka

#endif /* ARKA_RESPONSE_KEY_PRESSED_HXX */