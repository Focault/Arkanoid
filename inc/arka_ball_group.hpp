#ifndef ARKA_BALL_GROUP_HPP
#define ARKA_BALL_GROUP_HPP

#include <list>
#include <SFML/Graphics.hpp>

#include "arka_wall.hpp"
#include "arka_ball.hpp"
#include "arka_paddle.hpp"

namespace arka {

class BallGroup {
public:
    typedef std::list<Ball*> ballGroupT;

    BallGroup(Paddle& a_paddle);
    BallGroup(const BallGroup& a_other) = delete;
    BallGroup& operator=(const BallGroup& a_other) = delete;
    ~BallGroup();

    Ball* operator*();

    void push(Ball* a_ball);

    void bounceThemBalls(size_t a_startAt = 1) noexcept;

    void checkCollisionWithPaddle(const float& a_playerSpeed, size_t a_startAt = 1) noexcept;
    bool checkCollisionWithPaddle(Ball* a_ball, const float& a_playerSpeed) noexcept;

    void checkCollisionWithWall(Wall& a_wall, size_t a_startAt = 1) noexcept;

    void draw(sf::RenderWindow& a_window) const;
    void resketch() const;

private:
    void destroyBalls();
    void pop(ballGroupT::iterator& a_ball);
    
    Paddle& m_paddle;
    ballGroupT m_balls;
};

} // arka

#include "arka_ball_group.hxx"

#endif /* ARKA_BALL_GROUP_HPP */