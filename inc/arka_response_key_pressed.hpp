#ifndef ARKA_RESPONSE_KEY_PRESSED_HPP
#define ARKA_RESPONSE_KEY_PRESSED_HPP

#include <SFML/Graphics.hpp>
#include "arka_response_key.hpp"

namespace arka {

class KeyPressed : public Key {
public:
    using Key::Key;
    // returns true to unmount ball
    virtual bool execute(float& a_speedFactor, sf::Keyboard::Key& a_key) override;
};

} // arka

#include "arka_response_key_pressed.hxx"

#endif /* ARKA_RESPONSE_KEY_PRESSED_HPP */