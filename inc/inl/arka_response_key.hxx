#ifndef ARKA_RESPONSE_KEY_HXX
#define ARKA_RESPONSE_KEY_HXX

#include <SFML/Graphics.hpp>
#include "arka_event_response.hpp"

namespace arka {

inline Key::Key(float& a_speedFactor, sf::Event& a_event, bool& a_isMounted)
: m_speedFactor(a_speedFactor)
, m_event(a_event)
, m_isMounted(a_isMounted)
{}

inline void Key::respond() 
{
    if (execute(m_speedFactor, m_event.key.code)) {
        m_isMounted = false;
    }
}

} // arka

#endif /* ARKA_RESPONSE_KEY_HXX */