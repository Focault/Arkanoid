#ifndef ARKA_RESPONSE_KEY_RELEASED_HXX
#define ARKA_RESPONSE_KEY_RELEASED_HXX

#include <SFML/Graphics.hpp>

namespace arka {

inline bool KeyReleased::execute(float& a_speedFactor, sf::Keyboard::Key& a_key)
{
    if ((a_key == sf::Keyboard::Right && a_speedFactor > 0) || 
        (a_key == sf::Keyboard::Left && a_speedFactor < 0)) {
            a_speedFactor = 0;
    }
    return false;
}

} // arka

#endif /* ARKA_RESPONSE_KEY_RELEASED_HXX */