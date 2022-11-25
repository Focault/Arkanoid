#ifndef ARKA_MOVING_BALL_HPP
#define ARKA_MOVING_BALL_HPP

#include <SFML/Graphics.hpp>
#include "arka_ball.hpp"
#include "arka_paddle.hpp"

namespace arka {

class MovingBall : public Ball {
public:
    virtual ~MovingBall() = default;

    virtual void setPosition(const float& a_x, const float& a_y) = 0;
    // return false if exited game scope
    virtual bool move() override;
    virtual void mount(float a_leftX, float a_topY, float a_rightX) override;

    virtual bool isCollision(float a_leftX, float a_topY, float a_rightX, float a_bottomY) override;
    virtual bool isLow() override;

    virtual const sf::Drawable& operator*() const = 0;

    virtual void resketch() = 0;

    virtual sf::Vector2f getPosition() const = 0;
    virtual float calcDiameter() const override;

    virtual void increaseVerSpeed(float a_factor) = 0;
    virtual void resetSpeed() = 0;

protected:
    virtual const float& radiusPrecent() const = 0;
    virtual const size_t& windowSize() const = 0;
    virtual float& verSpeedPrecent() = 0;
    virtual float& horSpeedPrecent() = 0;
    virtual const float& maxSpeedPrecent() = 0;

protected:
    MovingBall& operator=(const MovingBall& a_other) = default;
    MovingBall(const MovingBall& a_other) = default;
    MovingBall() = default;
};

} // arka

#include "arka_moving_ball.hxx"

#endif /* ARKA_MOVING_BALL_HPP */