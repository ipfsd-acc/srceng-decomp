// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/scaleformui/scaleformuiimpl/scaleformuikeymapimpl.cpp
// Functions: 7
// ============================================================

#include "materialsystem\scaleformui\scaleformuiimpl\scaleformuikeymapimpl.h"

//------------------------------------------------------------------------------
// Address: 0x10012030
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
// Address: 0x100120A0
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
// Address: 0x10012110
// Name: public: unsigned int ScaleformUIImpl::ValveButtonCodeToVirtualKey(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
int __thiscall ScaleformUIImpl::ValveButtonCodeToVirtualKey(ScaleformUIImpl *this, ButtonCode_t code)
{
  int result; // eax

  switch ( code )
  {
    case JOYSTICK_FIRST:
      result = 32;
      break;
    case KEY_XBUTTON_B:
    case KEY_XBUTTON_STICK2:
      result = 46;
      break;
    case KEY_XBUTTON_X:
      result = 88;
      break;
    case KEY_XBUTTON_Y:
      result = 89;
      break;
    case KEY_XBUTTON_LEFT_SHOULDER:
      result = 33;
      break;
    case KEY_XBUTTON_RIGHT_SHOULDER:
      result = 34;
      break;
    case KEY_XBUTTON_BACK:
      result = 219;
      break;
    case KEY_XBUTTON_START:
      result = 221;
      break;
    case KEY_XBUTTON_STICK1:
      result = 45;
      break;
    case JOYSTICK_FIRST_POV_BUTTON:
    case KEY_XSTICK1_UP:
      result = 38;
      break;
    case KEY_XBUTTON_RIGHT:
    case JOYSTICK_FIRST_AXIS_BUTTON:
      result = 39;
      break;
    case KEY_XBUTTON_DOWN:
    case KEY_XSTICK1_DOWN:
      result = 40;
      break;
    case KEY_XBUTTON_LEFT:
    case KEY_XSTICK1_LEFT:
      result = 37;
      break;
    case KEY_XBUTTON_LTRIGGER:
      result = 36;
      break;
    case KEY_XBUTTON_RTRIGGER:
      result = 35;
      break;
    case KEY_XSTICK2_RIGHT:
      result = 137;
      break;
    case KEY_XSTICK2_LEFT:
      result = 139;
      break;
    case KEY_XSTICK2_DOWN:
      result = 138;
      break;
    case KEY_XSTICK2_UP:
      result = 136;
      break;
    default:
      result = g_pInputSystem->ButtonCodeToVirtualKey(this: g_pInputSystem, a2: code);
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100122E0
// Name: public: void ScaleformUIImpl::DecodeButtonandSlotFromButtonCode(enum ButtonCode_t,enum ButtonCode_t __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformUIImpl::DecodeButtonandSlotFromButtonCode(
        ScaleformUIImpl *this,
        ButtonCode_t inCode,
        ButtonCode_t *outCode,
        int *outSlot)
{
  *outCode = GetBaseButtonCode(code: inCode);
  *outSlot = GetJoystickForCode(code: inCode);
}

//------------------------------------------------------------------------------
// Address: 0x10012310
// Name: public: virtual enum IScaleformUI::KeyCode ScaleformUIImpl::TranslateKeyCode(unsigned int)
// Source: json
//------------------------------------------------------------------------------
IScaleformUI::KeyCode __thiscall ScaleformUIImpl::TranslateKeyCode(ScaleformUIImpl *this, IScaleformUI::KeyCode wParam)
{
  IScaleformUI::KeyCode result; // eax
  unsigned int winKey; // ecx
  int v4; // edx

  result = wParam;
  if ( (unsigned int)(wParam - 65) > 0x19
    && (unsigned int)(wParam - 112) > 0xE
    && (unsigned int)(wParam - 48) > 9
    && (unsigned int)(wParam - 96) > 0xF )
  {
    winKey = KeyCodeMap[0].winKey;
    v4 = 0;
    if ( KeyCodeMap[0].winKey != 0 )
    {
      while ( wParam != winKey )
      {
        winKey = KeyCodeMap[++v4].winKey;
        if ( winKey == 0 )
          return 0;
      }
      return KeyCodeMap[v4].appKey;
    }
    else
    {
      return 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10012370
// Name: public: virtual unsigned int ScaleformUIImpl::GetKeyModifierFlags(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall ScaleformUIImpl::GetKeyModifierFlags(ScaleformUIImpl *this)
{
  int v1; // edi

  v1 = 0;
  if ( GetKeyState(nVirtKey: 16) < 0 )
    v1 = 4;
  if ( GetKeyState(nVirtKey: 17) < 0 )
    v1 |= 1u;
  if ( GetKeyState(nVirtKey: 18) < 0 )
    v1 |= 2u;
  if ( (GetKeyState(nVirtKey: 144) & 1) != 0 )
    v1 |= 8u;
  if ( (GetKeyState(nVirtKey: 20) & 1) != 0 )
    v1 |= 0x10u;
  if ( (GetKeyState(nVirtKey: 145) & 1) != 0 )
    return v1 | 0x20;
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x100123E0
// Name: public: bool ScaleformUIImpl::InitKeyEvent(class GFxKeyEvent __near &,enum IScaleformUI::KeyCode,bool,unsigned int,unsigned char)
// Source: json
//------------------------------------------------------------------------------
char __thiscall ScaleformUIImpl::InitKeyEvent(
        ScaleformUIImpl *this,
        GFxKeyEvent *keyEvent,
        GFxKey::Code keyCode,
        bool down,
        unsigned int mods,
        unsigned __int8 asciiCode)
{
  char v6; // al

  if ( keyCode == VoidSymbol )
    return 0;
  v6 = mods;
  if ( mods == -1 )
    v6 = this->GetKeyModifierFlags(this);
  keyEvent->KeyCode = keyCode;
  keyEvent->WcharCode = 0;
  keyEvent->KeyboardIndex = 0;
  keyEvent->Type = !down + 5;
  keyEvent->AsciiCode = asciiCode;
  if ( (v6 & 4) != 0 )
    keyEvent->SpecialKeysState.States |= 1u;
  else
    keyEvent->SpecialKeysState.States &= ~1u;
  if ( (v6 & 1) != 0 )
    keyEvent->SpecialKeysState.States |= 2u;
  else
    keyEvent->SpecialKeysState.States &= ~2u;
  if ( (v6 & 2) != 0 )
    keyEvent->SpecialKeysState.States |= 4u;
  else
    keyEvent->SpecialKeysState.States &= ~4u;
  if ( (v6 & 8) != 0 )
    keyEvent->SpecialKeysState.States |= 0x10u;
  else
    keyEvent->SpecialKeysState.States &= ~0x10u;
  if ( (v6 & 0x10) != 0 )
    keyEvent->SpecialKeysState.States |= 8u;
  else
    keyEvent->SpecialKeysState.States &= ~8u;
  if ( (v6 & 0x20) != 0 )
    keyEvent->SpecialKeysState.States |= 0x20u;
  else
    keyEvent->SpecialKeysState.States &= ~0x20u;
  return 1;
}
