#ifndef ARKA_STANDARD_BRICK_HPP
#define ARKA_STANDARD_BRICK_HPP

#include <SFML/Graphics.hpp>

#include "arka_hitable_brick.hpp"

namespace arka {

class StandardBrick : public HitableBrick {
public:
    using HitableBrick::HitableBrick;

    virtual void initiate(sf::RectangleShape& a_brick) override;
};

} // arka

#include "arka_standard_brick.hxx"

#endif /* ARKA_STANDARD_BRICK_HPP */