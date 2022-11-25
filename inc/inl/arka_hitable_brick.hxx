#ifndef ARKA_HITABLE_BRICK_HXX
#define ARKA_HITABLE_BRICK_HXX

#include <SFML/Graphics.hpp>

#include "arka_brick.hpp"

namespace arka {

inline HitableBrick::HitableBrick(float a_initialHealth, 
                                  float a_initialWidth, 
                                  float a_initialHeight)
: m_healthBar(a_initialHealth > 0 ? a_initialHealth : StandardBrickInitialHealth)
, m_width(a_initialWidth > 0 ? a_initialWidth : StandardBrickInitialWidth)
, m_height(a_initialHeight > 0 ? a_initialHeight : StandardBrickInitialHeight)
, m_brick(sf::Vector2f(m_width, m_height))
{}

inline void HitableBrick::Initialize()
{
    initiate(m_brick);
}

inline void HitableBrick::setPosition(float a_x, float a_y) 
{
    m_brick.setPosition(sf::Vector2f(a_x, a_y));
}

inline const sf::Drawable& HitableBrick::operator*() const
{
    return m_brick;
}

inline void HitableBrick::resketch(sf::Vector2f a_dimensions)
{
    m_width = a_dimensions.x;
    m_height = a_dimensions.y;
    sf::Vector2f sketchSize{static_cast<float>(a_dimensions.x * 0.8), static_cast<float>(a_dimensions.y * 0.8)};
    m_brick.setSize(sketchSize);
}

inline sf::Vector2f HitableBrick::getPosition() const
{
    return m_brick.getPosition();
}

inline float HitableBrick::Width() const
{
    return m_width;
}

inline float HitableBrick::Height() const
{
    return m_height;
}

// return true if broken
inline bool HitableBrick::HitIt(float a_damage) noexcept
{
    m_healthBar -= a_damage;
    return !m_healthBar;
}

} // arka

#endif /* ARKA_HITABLE_BRICK_HXX */