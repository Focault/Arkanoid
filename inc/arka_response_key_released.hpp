#ifndef ARKA_RESPONSE_KEY_RELEASED_HPP
#define ARKA_RESPONSE_KEY_RELEASED_HPP

#include <SFML/Graphics.hpp>
#include "arka_response_key.hpp"

namespace arka {

class KeyReleased : public Key {
public:
    using Key::Key;
    // returns false
    virtual bool execute(float& a_speedFactor, sf::Keyboard::Key& a_key) override;
};

} // arka

#include "arka_response_key_released.hxx"

#endif /* ARKA_RESPONSE_KEY_RELEASED_HPP */