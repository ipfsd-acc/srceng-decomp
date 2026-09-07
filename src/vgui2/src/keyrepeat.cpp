// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/src/keyrepeat.cpp
// Functions: 5
// ============================================================

#include "vgui2\src\keyrepeat.h"

//------------------------------------------------------------------------------
// Address: 0x10006510
// Name: enum ButtonCode_t GetBaseButtonCode(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
ButtonCode_t __cdecl GetBaseButtonCode(ButtonCode_t code)
{
  ButtonCode_t result; // eax

  result = code;
  if ( (unsigned int)(code - 114) <= 0x7F )
    return ((code - 114) & 0x8000001F) + 114;
  if ( (unsigned int)(code - 242) <= 0xF )
    return ((code - 242) & 0x80000003) + 242;
  if ( (unsigned int)(code - 258) <= 0x2F )
    return (code - 258) % 12 + 258;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10006580
// Name: int GetJoystickForCode(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetJoystickForCode(ButtonCode_t code)
{
  if ( (unsigned int)(code - 114) > 0xBF )
    return 0;
  if ( code <= JOYSTICK_LAST_BUTTON )
    return (code - 114) / 32;
  if ( (unsigned int)(code - 242) > 0xF )
    return (code - 258) / 12;
  return (code - 242) / 4;
}

//------------------------------------------------------------------------------
// Address: 0x100065F0
// Name: public: void vgui::CKeyRepeatHandler::KeyDown(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CKeyRepeatHandler::KeyDown(vgui::CKeyRepeatHandler *this, ButtonCode_t code)
{
  int JoystickForCode; // edi
  int v4; // eax
  int v5; // eax

  JoystickForCode = GetJoystickForCode(code);
  switch ( GetBaseButtonCode(code) )
  {
    case JOYSTICK_FIRST_POV_BUTTON:
    case KEY_XSTICK1_UP:
    case KEY_XSTICK2_UP:
      v4 = 0;
      goto LABEL_6;
    case KEY_XBUTTON_RIGHT:
    case JOYSTICK_FIRST_AXIS_BUTTON:
    case KEY_XSTICK2_RIGHT:
      v4 = 3;
      goto LABEL_6;
    case KEY_XBUTTON_DOWN:
    case KEY_XSTICK1_DOWN:
    case KEY_XSTICK2_DOWN:
      v4 = 1;
      goto LABEL_6;
    case KEY_XBUTTON_LEFT:
    case KEY_XSTICK1_LEFT:
    case KEY_XSTICK2_LEFT:
      v4 = 2;
LABEL_6:
      v5 = v4 + 4 * JoystickForCode;
      if ( !this->m_bAliasDown[0][v5] )
      {
        *(_QWORD *)&this->m_bAliasDown[0][0] = 0;
        *(_QWORD *)&this->m_bAliasDown[2][0] = 0;
        this->m_bHaveKeyDown = false;
        this->m_bAliasDown[0][v5] = true;
        this->m_flNextKeyRepeat[JoystickForCode] = _Plat_FloatTime() + 0.4;
        this->m_bHaveKeyDown = true;
      }
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100066B0
// Name: public: void vgui::CKeyRepeatHandler::KeyUp(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CKeyRepeatHandler::KeyUp(vgui::CKeyRepeatHandler *this, ButtonCode_t code)
{
  int JoystickForCode; // ebx
  int v4; // eax
  int v5; // edx
  int v6; // eax
  _BYTE *v7; // ecx

  JoystickForCode = GetJoystickForCode(code);
  switch ( GetBaseButtonCode(code) )
  {
    case JOYSTICK_FIRST_POV_BUTTON:
    case KEY_XSTICK1_UP:
    case KEY_XSTICK2_UP:
      v4 = 0;
      goto LABEL_6;
    case KEY_XBUTTON_RIGHT:
    case JOYSTICK_FIRST_AXIS_BUTTON:
    case KEY_XSTICK2_RIGHT:
      v4 = 3;
      goto LABEL_6;
    case KEY_XBUTTON_DOWN:
    case KEY_XSTICK1_DOWN:
    case KEY_XSTICK2_DOWN:
      v4 = 1;
      goto LABEL_6;
    case KEY_XBUTTON_LEFT:
    case KEY_XSTICK1_LEFT:
    case KEY_XSTICK2_LEFT:
      v4 = 2;
LABEL_6:
      this->m_bAliasDown[JoystickForCode][v4] = false;
      this->m_bHaveKeyDown = false;
      v5 = 0;
      break;
    default:
      return;
  }
  do
  {
    v6 = 0;
    v7 = (char *)this + v5;
    while ( *v7 == 0 )
    {
      ++v6;
      v7 += 4;
      if ( v6 >= 4 )
        goto LABEL_12;
    }
    this->m_bHaveKeyDown = true;
LABEL_12:
    ++v5;
  }
  while ( v5 < 4 );
}

//------------------------------------------------------------------------------
// Address: 0x10006770
// Name: public: vgui::CKeyRepeatHandler::CKeyRepeatHandler(void)
// Source: json
//------------------------------------------------------------------------------
vgui::CKeyRepeatHandler *__thiscall vgui::CKeyRepeatHandler::CKeyRepeatHandler(vgui::CKeyRepeatHandler *this)
{
  *(_QWORD *)&this->m_bAliasDown[0][0] = 0;
  *(_QWORD *)&this->m_bAliasDown[2][0] = 0;
  this->m_bHaveKeyDown = false;
  this->m_flRepeatTimes[0] = 0.16;
  this->m_flRepeatTimes[1] = 0.16;
  this->m_flRepeatTimes[2] = 0.16;
  this->m_flRepeatTimes[3] = 0.16;
  return this;
}
