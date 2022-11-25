#ifndef ARKA_RESPONSE_RESIZED_HXX
#define ARKA_RESPONSE_RESIZED_HXX

#include <SFML/Graphics.hpp>
#include <cstddef>

namespace arka {

Resized::Resized(bool& a_isResize, size_t& a_windowSize, sf::Event& a_event)
: m_isResize(a_isResize)
, m_windowSize(a_windowSize)
, m_event(a_event)
{}

void Resized::respond() 
{
    m_isResize = true;
    m_windowSize = m_windowSize != m_event.size.width ? m_event.size.width : m_event.size.height;
}

} // arka

#endif /* ARKA_RESPONSE_RESIZED_HXX */