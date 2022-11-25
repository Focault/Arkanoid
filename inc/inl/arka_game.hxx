#ifndef ARKA_GAME_HXX
#define ARKA_GAME_HXX

#include <utility>
#include <algorithm>

#include "arka_wall.hpp"
#include "arka_game_window.hpp"
#include "arka_level.hpp"
#include "arka_ball_group.hpp"
#include "arka_standard_ball.hpp"
#include "arka_paddle.hpp"
#include "fsl_time.hpp"

#include "arka_response_closed.hpp"
#include "arka_response_resized.hpp"
#include "arka_response_update_focus.hpp"
#include "arka_response_key_pressed.hpp"
#include "arka_response_key_released.hpp"

namespace arka {

inline Game::Game(size_t a_windowSize, const char* a_header) 
: m_isFocus(true)
, m_isBallMounted(true)
, m_isResize(false)
, m_playerSpeed(0)
, m_lifesRemain(0)
, m_events()
, m_initialWindowSize(a_windowSize > 0 ? a_windowSize : 1000)
, m_header(a_header)
{}

inline void Game::run(size_t a_lifes) 
{
    m_lifesRemain = a_lifes;
    GameWindow window{m_initialWindowSize, m_header.c_str()};
    Paddle player{window.size()};
    BallGroup balls{player};
    sf::Event event;
    initiateEvents(window, event);
    releventEventsT::iterator eventIter;
    releventEventsT::iterator untracked = m_events.end();
    balls.push(new StandardBall{window.size()});
    Level level{};
    Wall wall{window.size()};
    level.Load(wall);

    while ((*window).isOpen()) {
        while ((*window).pollEvent(event)) {
            eventIter = m_events.find(event.type);
            if (eventIter != untracked) {
                std::get<1>(*eventIter)->respond();
            }
        }
        if (m_isResize) {
            window.resizeScreen(balls, player, wall);
            m_isResize = false;
        }
        if (m_isFocus) {
            if (fsl::IsFrame()) {
                if (m_playerSpeed) {
                    player.move(m_playerSpeed);
                }
                if (m_isBallMounted) {
                    (*balls)->mount(player.leftX(), player.topY(), player.rightX());
                } else {
                    if ((*balls)->move() == false) {
                        (*balls)->resetSpeed();
                        --m_lifesRemain;
                        m_isBallMounted = true;
                    }
                }
                balls.checkCollisionWithPaddle(m_playerSpeed, m_isBallMounted ? 1 : 0);
                balls.checkCollisionWithWall(wall, m_isBallMounted ? 1 : 0);
                balls.bounceThemBalls();
                window.refreshScreen(balls, player, wall);
            }
        }
    }
    DestroyEvents();
}

inline void Game::initiateEvents(GameWindow& a_window, sf::Event& a_event) 
{
    using sf::Event;
    m_events[Event::Closed] = new Closed{*a_window};
    m_events[Event::Resized] = new Resized{m_isResize, a_window.size(), a_event};
    m_events[Event::LostFocus] = new UpdateFocus{m_isFocus, false};
    m_events[Event::GainedFocus] = new UpdateFocus{m_isFocus, true};
    m_events[Event::KeyPressed] = new KeyPressed{m_playerSpeed, a_event, m_isBallMounted};
    m_events[Event::KeyPressed] = new KeyPressed{m_playerSpeed, a_event, m_isBallMounted};
    m_events[Event::KeyReleased] = new KeyReleased{m_playerSpeed, a_event, m_isBallMounted};
}

inline void Game::DestroyEvents() 
{
    auto destruct = [&](responsePair a_those) {
        delete std::get<1>(a_those);
    };
    std::for_each(m_events.begin(), m_events.end(), destruct);
    m_events.clear();
}

} // arka

#endif /* ARKA_GAME_HXX */