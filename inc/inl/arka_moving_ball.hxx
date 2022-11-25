#ifndef ARKA_MOVING_BALL_HXX
#define ARKA_MOVING_BALL_HXX

#include <cmath>
#include "arka_paddle.hpp"

namespace arka {

// return false if exited game scope
inline bool MovingBall::move() 
{
    sf::Vector2f ballPosition = getPosition();
    const size_t& windowLen = windowSize();
    float& ballVerSpeed = verSpeedPrecent();
    float& ballHorSpeed = horSpeedPrecent();
    // bounderies check
    if (ballPosition.x <= 0 || ballPosition.x + calcDiameter() >= windowLen) {
        ballHorSpeed *= -1;
    } else if (ballPosition.y <= 0) {
        ballVerSpeed *= -1;
    } else if (ballPosition.y >= windowLen) {
        return false;
    }
    setPosition(ballPosition.x + (ballHorSpeed * windowLen), ballPosition.y + (ballVerSpeed * windowLen));
    return true;
}

inline bool MovingBall::isCollision(float a_leftX, float a_topY, float a_rightX, float a_bottomY)
{
    sf::Vector2f ballPosition = getPosition();
    float diameter = calcDiameter();
    float& ballVerSpeed = verSpeedPrecent();
    float& ballHorSpeed = horSpeedPrecent();
    float ballBottomY = ballPosition.y + diameter;
    float ballRightX = ballPosition.x + diameter;
    if (ballBottomY >= a_topY && ballPosition.y <= a_bottomY &&
        ballRightX >= a_leftX && ballPosition.x <= a_rightX) {
            // TODO corner check
            float centerX = ballPosition.x + diameter / 2;
            float centerY = ballPosition.y + diameter / 2;
            if (!(centerX >= a_leftX && centerX <= a_rightX)) { 
                ballHorSpeed *= -1;
            } else {
                if (!(centerY >= a_topY * 1.3 && centerY <= a_bottomY * 1.3)) {
                    ballVerSpeed *= -1;
                } else {
                    return false;
                }
            }
            return true;
    }
    return false;
}

inline bool MovingBall::isLow()
{
    return getPosition().y > windowSize() * 0.7;
}

inline void MovingBall::mount(float a_leftX, float a_topY, float a_rightX)
{
    float diameter = calcDiameter();
    setPosition(a_leftX + (a_rightX - a_leftX - diameter) / 2, a_topY - windowSize() * 0.01 - diameter);
}

inline float MovingBall::calcDiameter() const
{
    return radiusPrecent() * windowSize() * 2;
}

} // arka

#endif /* ARKA_MOVING_BALL_HXX */