#ifndef ARKA_BALL_GROUP_HXX
#define ARKA_BALL_GROUP_HXX

#include <cmath>
#include "arka_wall.hpp"
#include "arka_ball.hpp"
#include "arka_paddle.hpp"

namespace arka {

inline BallGroup::BallGroup(Paddle& a_paddle)
: m_paddle(a_paddle)
, m_balls()
{}

inline BallGroup::~BallGroup()
{
    destroyBalls();
}

inline Ball* BallGroup::operator*()
{
    return *m_balls.begin();
}

inline void BallGroup::push(Ball* a_ball)
{
    m_balls.push_back(a_ball);
}

inline void BallGroup::bounceThemBalls(size_t a_startAt) noexcept
{
    if (a_startAt < m_balls.size()) {
        ballGroupT::iterator bounce = m_balls.begin();
        for (size_t i = 0; i < a_startAt; ++i) {++bounce;}
        for (; bounce != m_balls.end(); ++bounce) {
            if ((*bounce)->move() == false) {
                pop(bounce);
            }
        }
    }
}

inline void BallGroup::checkCollisionWithPaddle(const float& a_playerSpeed, size_t a_startAt) noexcept
{
    if (a_startAt < m_balls.size()) {
        ballGroupT::iterator check = m_balls.begin();
        for (size_t i = 0; i < a_startAt; ++i) {++check;}
        auto checkCollision = [&group = *this, speed = a_playerSpeed](Ball* a_ball) {
            return group.checkCollisionWithPaddle(a_ball, speed);
        };
        std::for_each(check, m_balls.end(), checkCollision);
    }
}

inline bool BallGroup::checkCollisionWithPaddle(Ball* a_ball, const float& a_playerSpeed) noexcept
{
    if (a_ball->isLow() && a_ball->isCollision(m_paddle.leftX(), m_paddle.topY(), m_paddle.rightX(), m_paddle.bottomY())) {
        a_ball->increaseVerSpeed(fabs(a_playerSpeed));
        return true;
    }
    return false;
}

inline void BallGroup::checkCollisionWithWall(Wall& a_wall, size_t a_startAt) noexcept
{
    if (a_startAt < m_balls.size()) {
        ballGroupT::iterator check = m_balls.begin();
        for (size_t i = 0; i < a_startAt; ++i) {++check;}
        std::for_each(m_balls.begin(), m_balls.end(), [&a_wall=a_wall](Ball* a_ball) {
            a_wall.checkCollisionWithBall(a_ball);
        });
    }
}

inline void BallGroup::draw(sf::RenderWindow& a_window) const
{
    std::for_each(m_balls.cbegin(), m_balls.cend(), [&a_window=a_window](Ball* a_ballP){a_window.draw(**a_ballP);});
}

inline void BallGroup::resketch() const
{
    std::for_each(m_balls.cbegin(), m_balls.cend(), [&](Ball* a_ballP){a_ballP->resketch();});
}

inline void BallGroup::destroyBalls()
{
    std::for_each(m_balls.begin(), m_balls.end(), [&](Ball* a_ballP){delete a_ballP;});
    m_balls.clear();
}   

inline void BallGroup::pop(ballGroupT::iterator& a_ball)
{
    delete *a_ball;
    m_balls.erase(a_ball);
}

} // arka

#endif /* ARKA_BALL_GROUP_HXX */