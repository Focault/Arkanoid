#ifndef ARKA_STANDARD_BALL_HXX
#define ARKA_STANDARD_BALL_HXX

#include <SFML/Graphics.hpp>

namespace arka {

namespace detail {

constexpr uint8_t maxSpeedFactor = 3;

} // detail

inline StandardBall::StandardBall(size_t& a_windowSize, float a_initialSpeedPrecent, float a_radiusPrecent)
: m_windowSize(a_windowSize)
, m_radiusPrecent(a_radiusPrecent > 0 ? a_radiusPrecent : standardBallRadiusPrecent)
, m_circle(m_radiusPrecent * m_windowSize)
, m_verSpeedPrecent(a_initialSpeedPrecent)
, m_horSpeedPrecent(a_initialSpeedPrecent)
, m_maxSpeedPrecent(a_initialSpeedPrecent * detail::maxSpeedFactor)
{
    initiateBall();
}

inline const sf::Drawable& StandardBall::operator*() const
{
    return m_circle;
}

inline void StandardBall::resketch()
{
    m_circle.setRadius(m_radiusPrecent * m_windowSize);
    initiateBall();
}

inline sf::Vector2f StandardBall::getPosition() const
{
    return m_circle.getPosition();
}

inline void StandardBall::setPosition(const float& a_x, const float& a_y)
{
    m_circle.setPosition(a_x, a_y);
}

inline const size_t& StandardBall::windowSize() const
{
    return m_windowSize;
}

inline float& StandardBall::verSpeedPrecent()
{
    return m_verSpeedPrecent;
}

inline float& StandardBall::horSpeedPrecent()
{
    return m_horSpeedPrecent;
}

inline const float& StandardBall::maxSpeedPrecent()
{
    return m_maxSpeedPrecent;
}

inline const float& StandardBall::radiusPrecent() const
{
    return m_radiusPrecent;
}

inline void StandardBall::increaseVerSpeed(float a_factor)
{
    if (m_verSpeedPrecent < m_maxSpeedPrecent) {
        m_verSpeedPrecent *= (1 + a_factor);
    }
}

inline void StandardBall::resetSpeed()
{
    m_verSpeedPrecent = m_maxSpeedPrecent / detail::maxSpeedFactor;
    m_horSpeedPrecent = m_verSpeedPrecent;
}

void StandardBall::initiateBall() 
{
    m_circle.setFillColor(sf::Color::Red);
    m_circle.setOutlineThickness(m_windowSize * m_radiusPrecent * 0.2);
    m_circle.setOutlineColor(sf::Color::Black);
}

} // arka

#endif /* ARKA_STANDARD_BALL_HXX */