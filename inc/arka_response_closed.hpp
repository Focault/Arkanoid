#ifndef ARKA_RESPONSE_CLOSED_HPP
#define ARKA_RESPONSE_CLOSED_HPP

#include <SFML/Graphics.hpp>
#include "arka_event_response.hpp"

namespace arka {

class Closed : public EventResponse {
public:
    Closed(sf::RenderWindow& a_window);
    Closed(const Closed& a_other) = default;
    Closed& operator=(const Closed& a_other) = default;
    ~Closed() = default;

    virtual void respond() override;

private:
    sf::RenderWindow& m_window;
};

} // arka

#include "arka_response_closed.hxx"

#endif /* ARKA_RESPONSE_CLOSED_HPP */