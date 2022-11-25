#ifndef ARKA_GAME_WINDOW_HPP
#define ARKA_GAME_WINDOW_HPP

#include <SFML/Graphics.hpp>
#include "arka_paddle.hpp"
#include "arka_ball_group.hpp"
#include "arka_wall.hpp"

namespace arka {

class GameWindow {
public:
    GameWindow(size_t a_windowSize, const char* a_header);
    GameWindow(const GameWindow& a_other) = delete;
    GameWindow& operator=(const GameWindow& a_other) = delete;
    ~GameWindow() = default;

    sf::RenderWindow& operator*() noexcept;
    size_t& size() noexcept;

    void refreshScreen(BallGroup& a_balls, Paddle& a_paddle, Wall& a_wall);
    void resizeScreen(BallGroup& a_balls, Paddle& a_paddle, Wall& a_wall);

private:
    void initiateWindow();

    size_t m_windowSize;
    const std::string m_header;
    sf::RenderWindow m_window;
};

} // arka

#include "arka_game_window.hxx"

#endif /* ARKA_GAME_WINDOW_HPP */