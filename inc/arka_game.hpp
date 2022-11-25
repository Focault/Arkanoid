#ifndef ARKA_GAME_HPP
#define ARKA_GAME_HPP

#include <unordered_map>
#include <list>
#include <string>
#include <utility>
#include <SFML/Graphics.hpp>

#include "arka_game_window.hpp"
#include "arka_event_response.hpp"
#include "arka_ball_group.hpp"
#include "arka_paddle.hpp"

namespace arka {

class Game {
public:
    typedef std::pair<sf::Event::EventType, EventResponse*> responsePair;
    typedef std::unordered_map<sf::Event::EventType, EventResponse*> releventEventsT;

    Game(size_t a_windowSize = 1000, const char* a_header = "Arkanoid - The Revolt of The Bricks");
    Game(const Game& a_other) = delete;
    Game& operator=(const Game& a_other) = delete;
    ~Game() = default;

    void run(size_t a_lifes = 3);

private:
    void initiateEvents(GameWindow& a_window, sf::Event& a_event);

    void DestroyEvents();

private:
    bool m_isFocus;
    bool m_isBallMounted;
    bool m_isResize;
    float m_playerSpeed;
    size_t m_lifesRemain;
    releventEventsT m_events;

    const size_t m_initialWindowSize;
    const std::string m_header;
};

} // arka

#include "arka_game.hxx"

#endif /* ARKA_GAME_HPP */