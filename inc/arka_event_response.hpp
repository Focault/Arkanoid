#ifndef ARKA_EVENT_RESPONSE_HPP
#define ARKA_EVENT_RESPONSE_HPP

namespace arka {

class EventResponse {
public:
    virtual ~EventResponse() = default;

    virtual void respond() = 0;
protected:
    EventResponse() = default;
    EventResponse& operator=(const EventResponse& a_other) = default;
    EventResponse(const EventResponse& a_other) = default;
};

} // arka

#endif /* ARKA_EVENT_RESPONSE_HPP */