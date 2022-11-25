#ifndef ARKA_STANDARD_BALL_HPP
#define ARKA_STANDARD_BALL_HPP

#include <SFML/Graphics.hpp>
#include "arka_moving_ball.hpp"
#include "arka_paddle.hpp"

namespace arka {

extern constexpr float standardBallInitialSpeedPrecent = -0.008;
extern constexpr float standardBallRadiusPrecent = 0.015;

class StandardBall : public MovingBall {
public:
    StandardBall(size_t& a_windowSize, 
                 float a_initialSpeedPrecent = standardBallInitialSpeedPrecent,
                 float a_radiusPrecent = standardBallRadiusPrecent);
    StandardBall& operator=(const StandardBall& a_other) = default;
    StandardBall(const StandardBall& a_other) = default;
    ~StandardBall() = default;

    virtual const sf::Drawable& operator*() const override;
    virtual void resketch() override;

    virtual sf::Vector2f getPosition() const override;
    virtual void setPosition(const float& a_x, const float& a_y) override;
    virtual const size_t& windowSize() const override;
    virtual float& verSpeedPrecent() override;
    virtual float& horSpeedPrecent() override;
    virtual const float& maxSpeedPrecent() override;
    virtual const float& radiusPrecent() const override;
    virtual void increaseVerSpeed(float a_factor) override;
    virtual void resetSpeed() override;

private:
    void initiateBall();

    const size_t& m_windowSize;

    float m_radiusPrecent;
    sf::CircleShape m_circle;

    float m_verSpeedPrecent;
    float m_horSpeedPrecent;
    const float m_maxSpeedPrecent;
};

} // arka

#include "arka_standard_ball.hxx"

#endif /* ARKA_STANDARD_BALL_HPP */