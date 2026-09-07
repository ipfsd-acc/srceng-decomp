// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/game_controls/keyrepeat.cpp
// Functions: 6
// ============================================================

#include "vgui2\game_controls\keyrepeat.h"

//------------------------------------------------------------------------------
// Address: 0x004222A0
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
// Address: 0x00422310
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
// Address: 0x00422380
// Name: GetIndexForCode
// Source: json
//------------------------------------------------------------------------------
int __usercall GetIndexForCode@<eax>(ButtonCode_t code@<eax>)
{
  int result; // eax

  switch ( GetBaseButtonCode(code) )
  {
    case JOYSTICK_FIRST_POV_BUTTON:
    case KEY_XSTICK1_UP:
    case KEY_XSTICK2_UP:
      result = 0;
      break;
    case KEY_XBUTTON_RIGHT:
    case JOYSTICK_FIRST_AXIS_BUTTON:
    case KEY_XSTICK2_RIGHT:
      result = 3;
      break;
    case KEY_XBUTTON_DOWN:
    case KEY_XSTICK1_DOWN:
    case KEY_XSTICK2_DOWN:
      result = 1;
      break;
    case KEY_XBUTTON_LEFT:
    case KEY_XSTICK1_LEFT:
    case KEY_XSTICK2_LEFT:
      result = 2;
      break;
    default:
      result = -1;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004223F0
// Name: public: void CKeyRepeatHandler::KeyDown(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKeyRepeatHandler::KeyDown(CKeyRepeatHandler *this, ButtonCode_t code)
{
  int JoystickForCode; // edi
  int IndexForCode; // eax
  int v5; // ecx
  bool *v6; // eax

  JoystickForCode = GetJoystickForCode(code);
  IndexForCode = GetIndexForCode(code);
  if ( IndexForCode != -1 )
  {
    v6 = &this->m_bAliasDown[JoystickForCode][IndexForCode];
    if ( !*v6 )
    {
      *(_QWORD *)&this->m_bAliasDown[0][0] = 0;
      *(_QWORD *)&this->m_bAliasDown[2][0] = 0;
      this->m_bHaveKeyDown = false;
      *v6 = true;
      this->m_flNextKeyRepeat[JoystickForCode] = _Plat_FloatTime(a1: v5) + 0.4;
      this->m_bHaveKeyDown = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00422450
// Name: public: void CKeyRepeatHandler::KeyUp(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKeyRepeatHandler::KeyUp(CKeyRepeatHandler *this, ButtonCode_t code)
{
  int IndexForCode; // edi
  int JoystickForCode; // eax
  int v5; // edx
  int v6; // eax
  _BYTE *v7; // ecx

  IndexForCode = GetIndexForCode(code);
  if ( IndexForCode != -1 )
  {
    JoystickForCode = GetJoystickForCode(code);
    v5 = 0;
    this->m_bAliasDown[JoystickForCode][IndexForCode] = false;
    this->m_bHaveKeyDown = false;
    do
    {
      v6 = 0;
      v7 = (char *)this + v5;
      while ( *v7 == 0 )
      {
        ++v6;
        v7 += 4;
        if ( v6 >= 4 )
          goto LABEL_8;
      }
      this->m_bHaveKeyDown = true;
LABEL_8:
      ++v5;
    }
    while ( v5 < 4 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004224B0
// Name: public: CKeyRepeatHandler::CKeyRepeatHandler(void)
// Source: json
//------------------------------------------------------------------------------
CKeyRepeatHandler *__thiscall CKeyRepeatHandler::CKeyRepeatHandler(CKeyRepeatHandler *this)
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
