#ifndef ARKA_BALL_HPP
#define ARKA_BALL_HPP

#include <SFML/Graphics.hpp>

namespace arka {

class Ball {
public:
    virtual ~Ball() = default;

    virtual void setPosition(const float& a_x, const float& a_y) = 0;
    // return false if exited game scope
    virtual bool move() = 0;
    virtual void mount(float a_leftX, float a_topY, float a_rightX) = 0;

    virtual bool isCollision(float a_leftX, float a_topY, float a_rightX, float a_bottomY) = 0;
    virtual bool isLow() = 0;

    virtual const sf::Drawable& operator*() const = 0;

    virtual void resketch() = 0;

    virtual sf::Vector2f getPosition() const = 0;
    virtual float calcDiameter() const = 0;

    virtual void increaseVerSpeed(float a_factor) = 0;
    virtual void resetSpeed() = 0;

protected:
    Ball() = default;
    Ball& operator=(const Ball& a_other) = default;
    Ball(const Ball& a_other) = default;
};

} // arka

#endif /* ARKA_BALL_HPP */