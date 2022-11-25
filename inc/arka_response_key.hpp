#ifndef ARKA_RESPONSE_KEY_HPP
#define ARKA_RESPONSE_KEY_HPP

#include <SFML/Graphics.hpp>
#include "arka_event_response.hpp"

namespace arka {

class Key : public EventResponse {
public:
    Key(float& a_speedFactor, sf::Event& a_event, bool& a_isMounted);
    virtual ~Key() = default;

    virtual void respond() override;

protected:
    // returns true to unmount ball
    virtual bool execute(float& a_speedFactor, sf::Keyboard::Key& a_key) = 0;
    Key(const Key& a_other) = default;
    Key& operator=(const Key& a_other) = default;

private:
    float& m_speedFactor;
    sf::Event& m_event;
    bool& m_isMounted;
};

} // arka

#include "arka_response_key.hxx"

#endif /* ARKA_RESPONSE_KEY_HPP */