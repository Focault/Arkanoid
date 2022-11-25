#ifndef ARKA_RESPONSE_UPDATE_FOCUS_HPP
#define ARKA_RESPONSE_UPDATE_FOCUS_HPP

#include "arka_event_response.hpp"

namespace arka {

class UpdateFocus : public EventResponse {
public:
    UpdateFocus(bool& a_isFocus, bool a_setTo);
    UpdateFocus(const UpdateFocus& a_other) = default;
    UpdateFocus& operator=(const UpdateFocus& a_other) = default;
    ~UpdateFocus() = default;

    virtual void respond() override;

private:
    bool& m_isFocus;
    const bool m_setTo;
};

} // arka

#include "arka_response_update_focus.hxx"

#endif /* ARKA_RESPONSE_UPDATE_FOCUS_HPP */