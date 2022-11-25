#ifndef ARKA_PADDLE_HPP
#define ARKA_PADDLE_HPP

#include <SFML/Graphics.hpp>

namespace arka {

extern constexpr float paddleStandardSpeedPrecent = 0.02;
extern constexpr float paddleStandardWidthPrecent = 0.2;
extern constexpr float paddleStandardHeightPrecent = 0.03;

class Paddle {
public:
    Paddle(const size_t& a_windowSize, 
           float a_speedPrecent = paddleStandardSpeedPrecent,
           float a_widthPrecent = paddleStandardWidthPrecent,
           float a_heightPrecent = paddleStandardHeightPrecent);
    Paddle& operator=(const Paddle& a_other) = delete;
    Paddle(const Paddle& a_other) = delete;
    ~Paddle() = default;

    const sf::Drawable& operator*() const;

    float leftX() const;
    float rightX() const;
    float topY() const;
    float bottomY() const;

    void move(float a_factor = 1);

    void resketch();

private:
    void initiatePaddle();

    const size_t& m_windowSize;

    float m_widthPrecent;
    float m_heightPrecent;

    float m_speedPrecent;

    sf::RectangleShape m_paddle;
};

} // arka

#include "arka_paddle.hxx"

#endif /* ARKA_PADDLE_HPP */