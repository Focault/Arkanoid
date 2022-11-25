#ifndef ARKA_RESPONSE_UPDATE_FOCUS_HXX
#define ARKA_RESPONSE_UPDATE_FOCUS_HXX

namespace arka {

inline UpdateFocus::UpdateFocus(bool& a_isFocus, bool a_setTo)
: m_isFocus(a_isFocus)
, m_setTo(a_setTo)
{}

inline void UpdateFocus::respond()
{
    m_isFocus = m_setTo;
}

} // arka

#endif /* ARKA_RESPONSE_UPDATE_FOCUS_HXX */