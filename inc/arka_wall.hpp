#ifndef ARKA_WALL_HPP
#define ARKA_WALL_HPP

#include <SFML/Graphics.hpp>
#include <unordered_map>

#include "arka_brick.hpp"
#include "arka_ball.hpp"

namespace arka {

extern constexpr size_t standardBrickNumInRow = 13;
extern constexpr float standardWallBeginingPrecentege = 0.2;

class Wall {
public:
    typedef size_t index;
    typedef std::unordered_map<index, Brick*> BrickWallT;

    Wall(size_t& a_windowSize, size_t a_bricksInRow = standardBrickNumInRow);
    Wall(const Wall& a_other) = delete;
    Wall& operator=(const Wall& a_other) = delete;
    ~Wall();

    void push(Brick* a_brick, index a_index);

    void checkCollisionWithBall(Ball* a_ball) noexcept;

    void draw(sf::RenderWindow& a_window) const;
    void resketch() const;

    void destroyWall();

    sf::Vector2f BrickSize() const;

    void crumble(BrickWallT::iterator& a_brick);

private:
    BrickWallT m_wall;
    size_t m_bricksInRow;
    index m_lastBrickIndex;
    size_t& m_windowSize;
};

} // arka

#include "arka_wall.hxx"

#endif /* ARKA_WALL_HPP */