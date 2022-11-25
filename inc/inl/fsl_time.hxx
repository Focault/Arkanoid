#ifndef FSL_TIME_HXX
#define FSL_TIME_HXX

#include <chrono>

namespace fsl {

static bool IsFrame(size_t a_fps) 
{
    using std::chrono::system_clock;
    constexpr short milisecondsInSecond = 1000;
    static std::chrono::duration<int,std::ratio<1, milisecondsInSecond> > frameRate{milisecondsInSecond / a_fps};
    static system_clock::time_point lastLapse = system_clock::now();

    system_clock::time_point stop = system_clock::now();
    if (stop - lastLapse >= frameRate) {
        lastLapse = stop;
        return true;
    }
    return false;
}

} // fsl

#endif /* FSL_TIME_HXX */