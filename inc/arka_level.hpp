#ifndef ARKA_LEVEL_HPP
#define ARKA_LEVEL_HPP

#include <cstddef>
#include "arka_wall.hpp"

namespace arka {

class Level {
public:
    Level(size_t a_startAt = 1);
    Level(const Level& a_other) = default;
    Level& operator=(const Level& a_other) = default;
    ~Level() = default;

    // return false if game over
    bool Load(Wall& a_wall) const;

    void operator++() noexcept;

private:
    size_t m_level;
};

} // arka

#include "arka_level.hxx"

#endif /* ARKA_LEVEL_HPP */