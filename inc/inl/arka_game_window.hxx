#ifndef ARKA_GAME_WINDOW_HXX
#define ARKA_GAME_WINDOW_HXX

#include <SFML/Graphics.hpp>
#include "arka_wall.hpp"
#include "arka_paddle.hpp"
#include "arka_ball_group.hpp"

namespace arka {

inline GameWindow::GameWindow(size_t a_windowSize, const char* a_header)
: m_windowSize(a_windowSize > 0 ? a_windowSize : 1000)
, m_header(a_header)
, m_window(sf::VideoMode(m_windowSize, m_windowSize), m_header)
{
    initiateWindow();
}

inline sf::RenderWindow& GameWindow::operator*() noexcept
{
    return m_window;
}

inline size_t& GameWindow::size() noexcept
{
    return m_windowSize;
}

inline void GameWindow::refreshScreen(BallGroup& a_balls, Paddle& a_paddle, Wall& a_wall)
{
    m_window.clear(sf::Color(255, 248, 175));
    a_balls.draw(m_window);
    m_window.draw(*a_paddle);
    a_wall.draw(m_window);
    m_window.display();
}

inline void GameWindow::resizeScreen(BallGroup& a_balls, Paddle& a_paddle, Wall& a_wall)
{
    m_window.setSize(sf::Vector2u(m_windowSize, m_windowSize));
    a_balls.resketch();
    a_paddle.resketch();
    a_wall.resketch();
}

inline void GameWindow::initiateWindow()
{
    m_window.setPosition(sf::Vector2i(3000, 50)); // TODO improve
    m_window.setVerticalSyncEnabled(true);
    m_window.setKeyRepeatEnabled(false);
}

} // arka

#endif /* ARKA_GAME_WINDOW_HXX */