#ifndef ARKA_RESPONSE_RESIZED_HPP
#define ARKA_RESPONSE_RESIZED_HPP

#include <SFML/Graphics.hpp>
#include <cstddef>
#include "arka_event_response.hpp"

namespace arka {

class Resized : public EventResponse {
public:
    Resized(bool& a_isResize, size_t& a_windowSize, sf::Event& a_event);
    Resized(const Resized& a_other) = default;
    Resized& operator=(const Resized& a_other) = default;
    ~Resized() = default;

    virtual void respond() override;

private:
    bool& m_isResize;
    size_t& m_windowSize;
    sf::Event& m_event;
};

} // arka

#include "arka_response_resized.hxx"

#endif /* ARKA_RESPONSE_RESIZED_HPP */