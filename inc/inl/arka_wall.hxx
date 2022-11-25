#ifndef ARKA_WALL_HXX
#define ARKA_WALL_HXX

#include <unordered_map>
#include <stdexcept>
#include <algorithm>
#include "arka_brick.hpp"
#include "arka_ball.hpp"

namespace arka {

inline Wall::Wall(size_t& a_windowSize, size_t a_bricksInRow)
: m_wall()
, m_bricksInRow(a_bricksInRow)
, m_lastBrickIndex(0)
, m_windowSize(a_windowSize)
{}

inline Wall::~Wall()
{
    destroyWall();
}

inline void Wall::push(Brick* a_brick, index a_index)
{
    if (m_wall.find(a_index) == m_wall.end()) {
        a_brick->Initialize();
        m_lastBrickIndex = a_index > m_lastBrickIndex ? a_index : m_lastBrickIndex;
        m_wall[a_index] = a_brick;
        // TODO extract
        sf::Vector2f brickDimensions = BrickSize();
        float wallTop = m_windowSize * standardWallBeginingPrecentege;
        a_brick->setPosition((a_index % m_bricksInRow) * brickDimensions.x,
                             (a_index / m_bricksInRow) * brickDimensions.y + wallTop);
        a_brick->resketch(brickDimensions);
    } else {
        throw std::invalid_argument("Brick can't be positioned in the place of another.");
    }
}

// Work In Progress
inline void Wall::checkCollisionWithBall(Ball* a_ball) noexcept
{
    sf::Vector2f brickDimensions = BrickSize();
    sf::Vector2f ballPosition = a_ball->getPosition();
    float ballDiameter = a_ball->calcDiameter();
    float ballBottomY = ballPosition.y + ballDiameter;
    size_t rows = m_lastBrickIndex > m_bricksInRow ? m_lastBrickIndex / m_bricksInRow + 1 : 1;
    float wallTop = m_windowSize * standardWallBeginingPrecentege;
    float wallFloor = wallTop + brickDimensions.y * rows;
    if (ballBottomY >= wallTop && ballPosition.y <= wallFloor) {
        // TODO improve and seperate
        std::vector<index> checkThose;
        if (ballPosition.y > wallTop) {
            index topLeftX = ballPosition.x / brickDimensions.x;
            index topLeftY = (ballPosition.y - wallTop) / brickDimensions.y;
            checkThose.push_back(topLeftX + topLeftY * m_bricksInRow);
            if (topLeftX < m_bricksInRow - 1) {
                checkThose.push_back((*checkThose.end()) + 1);
            }
        }
        if (ballBottomY < wallFloor) {
            if (!checkThose.empty()) {
                if (checkThose.size() == 2) {
                    checkThose.push_back(checkThose[1] + m_bricksInRow);
                }
                checkThose.push_back(checkThose[0] + m_bricksInRow);
            } else {
                index bottomLeftX = ballPosition.x / brickDimensions.x;
                index bottomLeftY = (ballBottomY - wallTop) / brickDimensions.y;
                checkThose.push_back(bottomLeftX + bottomLeftY * m_bricksInRow);
                if (bottomLeftX < m_bricksInRow - 1) {
                    checkThose.push_back((*checkThose.end()) + 1);
                }
            }
        }
        std::for_each(checkThose.cbegin(), checkThose.cend(), [&a_map=m_wall, &a_wall=*this, a_ball=a_ball](index a_index){
            auto iter = a_map.find(a_index);
            if (iter != a_map.end()) {
                Brick* brick = a_map[a_index];
                sf::Vector2f topLeft = brick->getPosition();
                if (a_ball->isCollision(topLeft.x, topLeft.y, topLeft.x + brick->Width(), topLeft.y + brick->Height())) {
                    if (brick->HitIt(1)) { // TODO change to ball speed
                        a_wall.crumble(iter);
                    }
                }
            }
        });
    }
}

inline void Wall::draw(sf::RenderWindow& a_window) const
{
    std::for_each(m_wall.begin(), m_wall.end(), [&window = a_window](std::pair<index, Brick*> a_pair) {
        window.draw(**std::get<1>(a_pair));
    });
}

inline void Wall::resketch() const
{
    sf::Vector2f dimensions = BrickSize();
    std::for_each(m_wall.begin(), m_wall.end(), [&dimensions = dimensions](std::pair<index, Brick*> a_pair) {
        std::get<1>(a_pair)->resketch(dimensions);
    });
}

inline void Wall::destroyWall()
{
    std::for_each(m_wall.begin(), m_wall.end(), 
    [](std::pair<index, Brick*> a_pair){delete std::get<1>(a_pair);});
    m_wall.clear();
}

inline sf::Vector2f Wall::BrickSize() const
{
    float width = m_windowSize / m_bricksInRow;
    return sf::Vector2f{width, width / 2};
}

inline void Wall::crumble(BrickWallT::iterator& a_brick)
{
    delete std::get<1>(*a_brick);
    m_wall.erase(a_brick);
}

} // arka

#endif /* ARKA_WALL_HXX */