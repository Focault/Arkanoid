#ifndef ARKA_BRICK_HPP
#define ARKA_BRICK_HPP

#include <SFML/Graphics.hpp>

namespace arka {

enum BrickType {
    EMPTY,
    STANDARD
};

constexpr float StandardBrickInitialHealth = 1;
constexpr float StandardBrickInitialWidth = 76;
constexpr float StandardBrickInitialHeight = StandardBrickInitialWidth / 2;

class Brick {
public:
    virtual ~Brick() = default;

    virtual void Initialize() = 0;

    virtual void setPosition(float a_x, float a_y) = 0;
    virtual const sf::Drawable& operator*() const = 0;

    virtual void resketch(sf::Vector2f a_dimensions) = 0;

    virtual sf::Vector2f getPosition() const = 0;
    virtual float Width() const = 0;
    virtual float Height() const = 0;

    // return true if broken
    virtual bool HitIt(float a_damage) noexcept = 0;

protected:
    Brick() = default;
    Brick& operator=(const Brick& a_other) = default;
    Brick(const Brick& a_other) = default;
};

} // arka

#endif /* ARKA_BRICK_HPP */