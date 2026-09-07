// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: inputsystem/key_translation.cpp
// Functions: 12
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10003CC0
// Name: bool IsPunctuation(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl IsPunctuation(ButtonCode_t code)
{
  return (unsigned int)(code - 1) <= 0x40 && code > KEY_Z && code != KEY_ENTER && code != KEY_SPACE;
}

//------------------------------------------------------------------------------
// Address: 0x10003D00
// Name: void ButtonCode_InitKeyTranslationTable(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ButtonCode_InitKeyTranslationTable()
{
  unsigned int i; // eax

  memset(dst: (unsigned __int8 *)s_pVirtualKeyToButtonCode, value: 0, count: sizeof(s_pVirtualKeyToButtonCode));
  s_pVirtualKeyToButtonCode[48] = KEY_0;
  s_pVirtualKeyToButtonCode[49] = KEY_1;
  s_pVirtualKeyToButtonCode[50] = KEY_2;
  s_pVirtualKeyToButtonCode[51] = KEY_3;
  s_pVirtualKeyToButtonCode[52] = KEY_4;
  s_pVirtualKeyToButtonCode[53] = KEY_5;
  s_pVirtualKeyToButtonCode[54] = KEY_6;
  s_pVirtualKeyToButtonCode[55] = KEY_7;
  s_pVirtualKeyToButtonCode[56] = KEY_8;
  s_pVirtualKeyToButtonCode[57] = KEY_9;
  s_pVirtualKeyToButtonCode[65] = KEY_A;
  s_pVirtualKeyToButtonCode[66] = KEY_B;
  s_pVirtualKeyToButtonCode[67] = KEY_C;
  s_pVirtualKeyToButtonCode[68] = KEY_D;
  s_pVirtualKeyToButtonCode[69] = KEY_E;
  s_pVirtualKeyToButtonCode[70] = KEY_F;
  s_pVirtualKeyToButtonCode[71] = KEY_G;
  s_pVirtualKeyToButtonCode[72] = KEY_H;
  s_pVirtualKeyToButtonCode[73] = KEY_I;
  s_pVirtualKeyToButtonCode[74] = KEY_J;
  s_pVirtualKeyToButtonCode[75] = KEY_K;
  s_pVirtualKeyToButtonCode[76] = KEY_L;
  s_pVirtualKeyToButtonCode[77] = KEY_M;
  s_pVirtualKeyToButtonCode[78] = KEY_N;
  s_pVirtualKeyToButtonCode[79] = KEY_O;
  s_pVirtualKeyToButtonCode[80] = KEY_P;
  s_pVirtualKeyToButtonCode[81] = KEY_Q;
  s_pVirtualKeyToButtonCode[82] = KEY_R;
  s_pVirtualKeyToButtonCode[83] = KEY_S;
  s_pVirtualKeyToButtonCode[84] = KEY_T;
  s_pVirtualKeyToButtonCode[85] = KEY_U;
  s_pVirtualKeyToButtonCode[86] = KEY_V;
  s_pVirtualKeyToButtonCode[87] = KEY_W;
  s_pVirtualKeyToButtonCode[88] = KEY_X;
  s_pVirtualKeyToButtonCode[89] = KEY_Y;
  s_pVirtualKeyToButtonCode[90] = KEY_Z;
  s_pVirtualKeyToButtonCode[96] = KEY_PAD_0;
  s_pVirtualKeyToButtonCode[97] = KEY_PAD_1;
  s_pVirtualKeyToButtonCode[98] = KEY_PAD_2;
  s_pVirtualKeyToButtonCode[99] = KEY_PAD_3;
  s_pVirtualKeyToButtonCode[100] = KEY_PAD_4;
  s_pVirtualKeyToButtonCode[101] = KEY_PAD_5;
  s_pVirtualKeyToButtonCode[102] = KEY_PAD_6;
  s_pVirtualKeyToButtonCode[103] = KEY_PAD_7;
  s_pVirtualKeyToButtonCode[104] = KEY_PAD_8;
  s_pVirtualKeyToButtonCode[105] = KEY_PAD_9;
  s_pVirtualKeyToButtonCode[111] = KEY_PAD_DIVIDE;
  s_pVirtualKeyToButtonCode[106] = KEY_PAD_MULTIPLY;
  s_pVirtualKeyToButtonCode[109] = KEY_PAD_MINUS;
  s_pVirtualKeyToButtonCode[107] = KEY_PAD_PLUS;
  s_pVirtualKeyToButtonCode[110] = KEY_PAD_DECIMAL;
  s_pVirtualKeyToButtonCode[219] = KEY_LBRACKET;
  s_pVirtualKeyToButtonCode[221] = KEY_RBRACKET;
  s_pVirtualKeyToButtonCode[186] = KEY_SEMICOLON;
  s_pVirtualKeyToButtonCode[222] = KEY_APOSTROPHE;
  s_pVirtualKeyToButtonCode[192] = KEY_BACKQUOTE;
  s_pVirtualKeyToButtonCode[188] = KEY_COMMA;
  s_pVirtualKeyToButtonCode[190] = KEY_PERIOD;
  s_pVirtualKeyToButtonCode[191] = KEY_SLASH;
  s_pVirtualKeyToButtonCode[220] = KEY_BACKSLASH;
  s_pVirtualKeyToButtonCode[189] = KEY_MINUS;
  s_pVirtualKeyToButtonCode[187] = KEY_EQUAL;
  s_pVirtualKeyToButtonCode[13] = KEY_ENTER;
  s_pVirtualKeyToButtonCode[32] = KEY_SPACE;
  s_pVirtualKeyToButtonCode[8] = KEY_BACKSPACE;
  s_pVirtualKeyToButtonCode[9] = KEY_TAB;
  s_pVirtualKeyToButtonCode[20] = KEY_CAPSLOCK;
  s_pVirtualKeyToButtonCode[144] = KEY_NUMLOCK;
  s_pVirtualKeyToButtonCode[27] = KEY_ESCAPE;
  s_pVirtualKeyToButtonCode[145] = KEY_SCROLLLOCK;
  s_pVirtualKeyToButtonCode[45] = KEY_INSERT;
  s_pVirtualKeyToButtonCode[46] = KEY_DELETE;
  s_pVirtualKeyToButtonCode[36] = KEY_HOME;
  s_pVirtualKeyToButtonCode[35] = KEY_END;
  s_pVirtualKeyToButtonCode[33] = KEY_PAGEUP;
  s_pVirtualKeyToButtonCode[34] = KEY_PAGEDOWN;
  s_pVirtualKeyToButtonCode[19] = KEY_BREAK;
  s_pVirtualKeyToButtonCode[16] = KEY_LSHIFT;
  s_pVirtualKeyToButtonCode[18] = KEY_LALT;
  s_pVirtualKeyToButtonCode[17] = KEY_LCONTROL;
  s_pVirtualKeyToButtonCode[91] = KEY_LWIN;
  s_pVirtualKeyToButtonCode[92] = KEY_RWIN;
  s_pVirtualKeyToButtonCode[93] = KEY_APP;
  s_pVirtualKeyToButtonCode[38] = KEY_UP;
  s_pVirtualKeyToButtonCode[37] = KEY_LEFT;
  s_pVirtualKeyToButtonCode[40] = KEY_DOWN;
  s_pVirtualKeyToButtonCode[39] = KEY_RIGHT;
  s_pVirtualKeyToButtonCode[112] = KEY_F1;
  s_pVirtualKeyToButtonCode[113] = KEY_F2;
  s_pVirtualKeyToButtonCode[114] = KEY_F3;
  s_pVirtualKeyToButtonCode[115] = KEY_F4;
  s_pVirtualKeyToButtonCode[116] = KEY_F5;
  s_pVirtualKeyToButtonCode[117] = KEY_F6;
  s_pVirtualKeyToButtonCode[118] = KEY_F7;
  s_pVirtualKeyToButtonCode[119] = KEY_F8;
  s_pVirtualKeyToButtonCode[120] = KEY_F9;
  s_pVirtualKeyToButtonCode[121] = KEY_F10;
  s_pVirtualKeyToButtonCode[122] = KEY_F11;
  s_pVirtualKeyToButtonCode[123] = KEY_F12;
  s_pXKeyTrans[0] = BUTTON_CODE_NONE;
  s_pXKeyTrans[1] = JOYSTICK_FIRST_POV_BUTTON;
  s_pXKeyTrans[2] = KEY_XBUTTON_DOWN;
  s_pXKeyTrans[3] = KEY_XBUTTON_LEFT;
  s_pXKeyTrans[4] = KEY_XBUTTON_RIGHT;
  s_pXKeyTrans[5] = KEY_XBUTTON_START;
  s_pXKeyTrans[6] = KEY_XBUTTON_BACK;
  s_pXKeyTrans[7] = KEY_XBUTTON_STICK1;
  s_pXKeyTrans[8] = KEY_XBUTTON_STICK2;
  s_pXKeyTrans[9] = JOYSTICK_FIRST;
  s_pXKeyTrans[10] = KEY_XBUTTON_B;
  s_pXKeyTrans[11] = KEY_XBUTTON_X;
  s_pXKeyTrans[12] = KEY_XBUTTON_Y;
  s_pXKeyTrans[13] = KEY_XBUTTON_LEFT_SHOULDER;
  s_pXKeyTrans[14] = KEY_XBUTTON_RIGHT_SHOULDER;
  s_pXKeyTrans[15] = KEY_XBUTTON_LTRIGGER;
  s_pXKeyTrans[16] = KEY_XBUTTON_RTRIGGER;
  s_pXKeyTrans[17] = KEY_XSTICK1_UP;
  s_pXKeyTrans[18] = KEY_XSTICK1_DOWN;
  s_pXKeyTrans[19] = KEY_XSTICK1_LEFT;
  s_pXKeyTrans[20] = JOYSTICK_FIRST_AXIS_BUTTON;
  s_pXKeyTrans[21] = KEY_XSTICK2_UP;
  s_pXKeyTrans[22] = KEY_XSTICK2_DOWN;
  s_pXKeyTrans[23] = KEY_XSTICK2_LEFT;
  s_pXKeyTrans[24] = KEY_XSTICK2_RIGHT;
  s_pXKeyTrans[25] = KEY_XBUTTON_INACTIVE_START;
  for ( i = 0; i < 0x100; ++i )
    s_pButtonCodeToVirtual[s_pVirtualKeyToButtonCode[i]] = i;
  s_pButtonCodeToVirtual[0] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10004230
// Name: enum ButtonCode_t ButtonCode_VirtualKeyToButtonCode(int)
// Source: json
//------------------------------------------------------------------------------
ButtonCode_t __cdecl ButtonCode_VirtualKeyToButtonCode(unsigned int keyCode)
{
  if ( keyCode >= 0x100 )
    return BUTTON_CODE_NONE;
  else
    return s_pVirtualKeyToButtonCode[keyCode];
}

//------------------------------------------------------------------------------
// Address: 0x10004250
// Name: int ButtonCode_ButtonCodeToVirtualKey(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ButtonCode_ButtonCodeToVirtualKey(ButtonCode_t code)
{
  return s_pButtonCodeToVirtual[code];
}

//------------------------------------------------------------------------------
// Address: 0x10004260
// Name: enum ButtonCode_t ButtonCode_XKeyToButtonCode(int,int)
// Source: json
//------------------------------------------------------------------------------
ButtonCode_t __cdecl ButtonCode_XKeyToButtonCode(int nPort, unsigned int keyCode)
{
  ButtonCode_t v2; // ecx

  if ( keyCode > 0x19 )
    return BUTTON_CODE_NONE;
  v2 = s_pXKeyTrans[keyCode];
  if ( (unsigned int)(v2 - 114) <= 0x7F )
    return v2 + 32 * nPort;
  if ( (unsigned int)(v2 - 242) <= 0xF )
    return v2 + 4 * nPort;
  if ( (unsigned int)(v2 - 258) > 0x2F )
    return s_pXKeyTrans[keyCode];
  return v2 + 12 * nPort;
}

//------------------------------------------------------------------------------
// Address: 0x100042C0
// Name: char const __near * ButtonCode_ButtonCodeToString(enum ButtonCode_t,bool)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl ButtonCode_ButtonCodeToString(ButtonCode_t code, bool bXController)
{
  if ( !bXController )
    return s_pButtonCodeName[code];
  if ( (unsigned int)(code - 114) <= 0x7F )
    return s_pXControllerButtonCodeNames[(code - 114) & 0x8000001F];
  if ( (unsigned int)(code - 242) <= 0xF )
    return s_pXControllerButtonCodeNames[((code - 242) & 0x80000003) + 128];
  if ( (unsigned int)(code - 258) <= 0x2F )
    return s_pXControllerButtonCodeNames[(code - 258) % 12 + 144];
  else
    return s_pButtonCodeName[code];
}

//------------------------------------------------------------------------------
// Address: 0x10004340
// Name: char const __near * AnalogCode_AnalogCodeToString(enum AnalogCode_t)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl AnalogCode_AnalogCodeToString(AnalogCode_t code)
{
  return s_pAnalogCodeName[code];
}

//------------------------------------------------------------------------------
// Address: 0x10004350
// Name: enum ButtonCode_t ButtonCode_StringToButtonCode(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ButtonCode_StringToButtonCode(const char *pString, bool bXController)
{
  int v2; // eax
  int i; // esi
  int v5; // esi

  if ( pString == nullptr || *pString == 0 )
    return -1;
  if ( V_strnicmp(s1: pString, s2: "aux", n: 3) == 0 )
  {
    v2 = atoi(nptr: pString + 3);
    if ( v2 < 29 )
      return v2 + 114;
    if ( v2 <= 32 )
      return v2 + 213;
    return -1;
  }
  for ( i = 0; i < 306; ++i )
  {
    if ( _V_stricmp(s1: s_pButtonCodeName[i], s2: pString) == 0 )
      return i;
  }
  if ( !bXController )
    return -1;
  v5 = 0;
  while ( _V_stricmp(s1: s_pXControllerButtonCodeNames[v5], s2: pString) != 0 )
  {
    if ( (unsigned int)++v5 >= 0xC0 )
      return -1;
  }
  return v5 + 114;
}

//------------------------------------------------------------------------------
// Address: 0x10004400
// Name: enum AnalogCode_t AnalogCode_StringToAnalogCode(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl AnalogCode_StringToAnalogCode(const char *pString)
{
  int v1; // esi

  if ( pString == nullptr || *pString == 0 )
    return -1;
  v1 = 0;
  while ( _V_stricmp(s1: s_pAnalogCodeName[v1], s2: pString) != 0 )
  {
    if ( ++v1 >= 28 )
      return -1;
  }
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x10004450
// Name: enum ButtonCode_t ButtonCode_ScanCodeToButtonCode(int)
// Source: json
//------------------------------------------------------------------------------
ButtonCode_t __cdecl ButtonCode_ScanCodeToButtonCode(int lParam)
{
  ButtonCode_t result; // eax

  if ( BYTE2(lParam) > 0x7Fu )
    return BUTTON_CODE_NONE;
  result = s_pScanToButtonCode[BYTE2(lParam)];
  if ( (lParam & 0x1000000) != 0 )
  {
    switch ( result )
    {
      case KEY_SLASH:
        result = KEY_PAD_DIVIDE;
        break;
      case KEY_ENTER:
        result = KEY_PAD_ENTER;
        break;
      case KEY_CAPSLOCK:
        result = KEY_PAD_PLUS;
        break;
      case KEY_LALT:
        result = KEY_RALT;
        break;
      case KEY_LCONTROL:
        result = KEY_RCONTROL;
        break;
      default:
        return result;
    }
  }
  else
  {
    switch ( result )
    {
      case KEY_INSERT:
        result = KEY_PAD_0;
        break;
      case KEY_DELETE:
        result = KEY_PAD_DECIMAL;
        break;
      case KEY_HOME:
        result = KEY_PAD_7;
        break;
      case KEY_END:
        result = KEY_PAD_1;
        break;
      case KEY_PAGEUP:
        result = KEY_PAD_9;
        break;
      case KEY_PAGEDOWN:
        result = KEY_PAD_3;
        break;
      case KEY_UP:
        result = KEY_PAD_8;
        break;
      case KEY_LEFT:
        result = KEY_PAD_4;
        break;
      case KEY_DOWN:
        result = KEY_PAD_2;
        break;
      case KEY_RIGHT:
        result = KEY_PAD_6;
        break;
      default:
        return result;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10004590
// Name: void ButtonCode_UpdateScanCodeLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ButtonCode_UpdateScanCodeLayout()
{
  UINT v0; // edi
  HKL KeyboardLayout; // esi
  HKL KeyboardLayoutA; // eax
  ButtonCode_t v3; // esi
  UINT v4; // eax
  HKL__ *currentKb; // [esp+8h] [ebp-8h]
  HKL__ *englishKb; // [esp+Ch] [ebp-4h]

  qmemcpy(s_pScanToButtonCode, s_pScanToButtonCode_QWERTY, sizeof(s_pScanToButtonCode));
  v0 = 0;
  KeyboardLayout = GetKeyboardLayout(idThread: 0);
  currentKb = KeyboardLayout;
  KeyboardLayoutA = LoadKeyboardLayoutA(pwszKLID: "00000409", Flags: 0);
  englishKb = KeyboardLayoutA;
  if ( KeyboardLayoutA == nullptr || KeyboardLayoutA == KeyboardLayout )
  {
    s_pScanToButtonCode[0] = BUTTON_CODE_NONE;
  }
  else
  {
    do
    {
      v3 = s_pScanToButtonCode_QWERTY[v0];
      if ( v3 != BUTTON_CODE_NONE
        && v3 != KEY_BACKQUOTE
        && ((unsigned int)(v3 - 1) <= 0x23 || IsPunctuation(code: s_pScanToButtonCode_QWERTY[v0])) )
      {
        v4 = MapVirtualKeyExA(uCode: v0, uMapType: 1u, dwhkl: englishKb);
        s_pScanToButtonCode[MapVirtualKeyExA(uCode: v4, uMapType: 0, dwhkl: currentKb) & 0x7F] = v3;
      }
      ++v0;
    }
    while ( v0 < 0x80 );
    s_pScanToButtonCode[0] = BUTTON_CODE_NONE;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004640
// Name: key_updatelayout
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl key_updatelayout()
{
  ButtonCode_UpdateScanCodeLayout();
}
