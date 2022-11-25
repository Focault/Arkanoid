#ifndef ARKA_HITABLE_BRICK_HPP
#define ARKA_HITABLE_BRICK_HPP

#include <SFML/Graphics.hpp>

#include "arka_brick.hpp"

namespace arka {

class HitableBrick : public Brick {
public:
    HitableBrick(float a_initialHealth = StandardBrickInitialHealth,
                  float a_initialWidth = StandardBrickInitialWidth, 
                  float a_initialHeight = StandardBrickInitialHeight);
    HitableBrick& operator=(const HitableBrick& a_other) = default;
    HitableBrick(const HitableBrick& a_other) = default;
    ~HitableBrick() = default;

    virtual void Initialize() override;

    virtual void setPosition(float a_x, float a_y) override;
    virtual const sf::Drawable& operator*() const override;

    virtual void resketch(sf::Vector2f a_dimensions) override;

    virtual sf::Vector2f getPosition() const override;
    virtual float Width() const override;
    virtual float Height() const override;

    // return true if broken
    virtual bool HitIt(float a_damage) noexcept override;

protected:
    virtual void initiate(sf::RectangleShape& a_brick) = 0;

private:
    float m_healthBar;
    float m_width;
    float m_height;
    sf::RectangleShape m_brick;
};

} // arka

#include "arka_hitable_brick.hxx"

#endif /* ARKA_HITABLE_BRICK_HPP */