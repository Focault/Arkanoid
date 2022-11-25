#ifndef ARKA_PADDLE_HXX
#define ARKA_PADDLE_HXX

#include <SFML/Graphics.hpp>

namespace arka {

inline Paddle::Paddle(const size_t& a_windowSize, 
               float a_speedPrecent,
               float a_widthPrecent,
               float a_heightPrecent)
: m_windowSize(a_windowSize)
, m_widthPrecent(a_widthPrecent > 0 ? a_widthPrecent : paddleStandardWidthPrecent)
, m_heightPrecent(a_heightPrecent > 0 ? a_heightPrecent : paddleStandardHeightPrecent)
, m_speedPrecent(a_speedPrecent > 0 ? a_speedPrecent : paddleStandardSpeedPrecent)
, m_paddle(sf::Vector2f(m_widthPrecent * m_windowSize, m_heightPrecent * m_windowSize))
{
    initiatePaddle();
}

inline const sf::Drawable& Paddle::operator*() const 
{
    return m_paddle;
}

inline float Paddle::leftX() const
{
    return m_paddle.getPosition().x;
}

inline float Paddle::rightX() const
{
    return leftX() + m_widthPrecent * m_windowSize;
}

inline float Paddle::topY() const
{
    return m_paddle.getPosition().y;
}

inline float Paddle::bottomY() const
{
    return topY() + m_heightPrecent * m_windowSize;
}

inline void Paddle::move(float a_factor)
{
    if ((a_factor > 0 && rightX() < m_windowSize) || (a_factor < 0 && leftX() > 0)) {
        m_paddle.move(m_speedPrecent * m_windowSize * a_factor, 0);
    }
}

inline void Paddle::resketch()
{
    m_paddle.setSize(sf::Vector2f(m_widthPrecent * m_windowSize, m_heightPrecent * m_windowSize));
    initiatePaddle();
}

inline void Paddle::initiatePaddle()
{
    m_paddle.setFillColor(sf::Color::Green);
    m_paddle.setOutlineThickness(m_heightPrecent * m_windowSize * 0.2);
    m_paddle.setOutlineColor(sf::Color::Black);
    m_paddle.setPosition(m_windowSize / 2.f, m_windowSize * 0.9f);
}

} // arka

#endif /* ARKA_PADDLE_HXX */