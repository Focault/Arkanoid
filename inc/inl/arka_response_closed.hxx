#ifndef ARKA_RESPONSE_CLOSED_HXX
#define ARKA_RESPONSE_CLOSED_HXX

#include <SFML/Graphics.hpp>

namespace arka {

inline Closed::Closed(sf::RenderWindow& a_window)
: m_window(a_window)
{}

inline void Closed::respond()
{
    m_window.close();
}

} // arka

#endif /* ARKA_RESPONSE_CLOSED_HXX */