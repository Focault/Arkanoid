#ifndef ARKA_LEVEL_HXX
#define ARKA_LEVEL_HXX

#include <string>
#include <fstream>
#include <algorithm>

#include "arka_wall.hpp"
#include "fsl_parser.hpp"
#include "fsl_string_manipulations.hpp"

#include "arka_standard_brick.hpp"

namespace arka {

inline Level::Level(size_t a_startAt)
: m_level(a_startAt)
{}

bool Level::Load(Wall& a_wall) const
{
    a_wall.destroyWall();
    typedef fsl::CleanCode levelSettings;
    size_t brickIdx = 0;
    std::string fileName{"../DATA/levels/level"};
    fileName += m_level + '0';
    fileName += ".arka";
    std::ifstream stream{fileName.c_str()};
    if (stream.good()) {
        levelSettings settings = fsl::Parser{}.Parse(stream);
        std::for_each(settings.cbegin(), settings.cend(), [&a_wall=a_wall, &a_brickIdx=brickIdx](const std::string& a_string) {
            if (fsl::IsNumeric(a_string)) {
                switch (static_cast<BrickType>(fsl::NumFromString<int>(a_string))) {
                    case STANDARD:
                        a_wall.push(new StandardBrick{}, a_brickIdx++);
                        break;
                    case EMPTY:
                        ++a_brickIdx;
                }
            }
        });
        return true;
    }
    return false;
}

void Level::operator++() noexcept
{
    ++m_level;
}

} // arka

#endif /* ARKA_LEVEL_HXX */