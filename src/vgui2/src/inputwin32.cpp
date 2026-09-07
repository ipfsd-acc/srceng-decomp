// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/src/inputwin32.cpp
// Functions: 103
// ============================================================

#include "vgui2\src\inputwin32.h"

//------------------------------------------------------------------------------
// Address: 0x10001FC0
// Name: public: virtual void CInputWin32::ActivateInputContext(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputWin32::ActivateInputContext(CInputWin32 *this, int context)
{
  this->m_hContext = context;
}

//------------------------------------------------------------------------------
// Address: 0x10001FD0
// Name: public: virtual void CInputWin32::UpdateJoystickXPosInternal(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputWin32::UpdateJoystickXPosInternal(CInputWin32 *this, int pos)
{
  this->m_JoystickX = pos;
}

//------------------------------------------------------------------------------
// Address: 0x10001FE0
// Name: public: virtual void CInputWin32::UpdateJoystickYPosInternal(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputWin32::UpdateJoystickYPosInternal(CInputWin32 *this, int pos)
{
  this->m_JoysitckY = pos;
}

//------------------------------------------------------------------------------
// Address: 0x10001FF0
// Name: public: virtual void CInputWin32::GetKeyCodeText(enum ButtonCode_t,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputWin32::GetKeyCodeText(CInputWin32 *this, ButtonCode_t code, char *buf, int buflen)
{
  int i; // eax
  char v5; // dl

  if ( buf != nullptr )
  {
    for ( i = 0; i < buflen; ++i )
    {
      v5 = this->_keyTrans[code][i + 2];
      buf[i] = v5;
      if ( v5 == 0 )
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002030
// Name: private: void CInputWin32::SurfaceSetCursorPos(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputWin32::SurfaceSetCursorPos(CInputWin32 *this, int x, int y)
{
  int pw; // [esp+0h] [ebp-10h] BYREF
  int pt; // [esp+4h] [ebp-Ch] BYREF
  int px; // [esp+8h] [ebp-8h] BYREF
  int py; // [esp+Ch] [ebp-4h] BYREF

  if ( vgui::g_pSurface->HasCursorPosFunctions(this: vgui::g_pSurface) )
  {
    vgui::g_pSurface->SurfaceSetCursorPos(this: vgui::g_pSurface, a2: x, a3: y);
  }
  else
  {
    vgui::g_pSurface->GetAbsoluteWindowBounds(this: vgui::g_pSurface, a2: &px, a3: &py, a4: &pw, a5: &pt);
    SetCursorPos(X: x + px, Y: y + py);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100020A0
// Name: private: void CInputWin32::SurfaceGetCursorPos(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputWin32::SurfaceGetCursorPos(CInputWin32 *this, int *x, int *y)
{
  tagPOINT pnt; // [esp+0h] [ebp-18h] BYREF
  int pw; // [esp+8h] [ebp-10h] BYREF
  int pt; // [esp+Ch] [ebp-Ch] BYREF
  int py; // [esp+10h] [ebp-8h] BYREF
  int px; // [esp+14h] [ebp-4h] BYREF

  if ( vgui::g_pSurface->HasCursorPosFunctions(this: vgui::g_pSurface) )
  {
    vgui::g_pSurface->SurfaceGetCursorPos(this: vgui::g_pSurface, a2: x, a3: y);
  }
  else
  {
    GetCursorPos(lpPoint: &pnt);
    *(tagPOINT *)x = pnt;
    vgui::g_pSurface->GetAbsoluteWindowBounds(this: vgui::g_pSurface, a2: &px, a3: &py, a4: &pw, a5: &pt);
    *x -= px;
    *y -= py;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002130
// Name: public: virtual void CInputWin32::SetCursorOveride(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputWin32::SetCursorOveride(CInputWin32 *this, unsigned int cursor)
{
  this->_cursorOverride = cursor;
}

//------------------------------------------------------------------------------
// Address: 0x10002140
// Name: public: virtual bool CInputWin32::InternalCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CInputWin32::InternalCursorMoved(CInputWin32 *this, int x, int y)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(
           this: v3,
           setName: "SetCursorPosInternal",
           firstKey: "xpos",
           firstValue: x,
           secondKey: "ypos",
           secondValue: y);
  else
    v4 = nullptr;
  ((void (__thiscall *)(vgui::IVGui *, int, KeyValues *, _DWORD, _DWORD))vgui::g_pIVgui->PostMessageA)(
    a1: vgui::g_pIVgui,
    a2: -1,
    a3: v4,
    a4: 0,
    a5: 0);
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x100021A0
// Name: public: virtual void CInputWin32::UpdateButtonState(struct InputEvent_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputWin32::UpdateButtonState(CInputWin32 *this, const InputEvent_t *event)
{
  int m_nType; // eax
  ButtonCode_t m_nData2; // esi
  vgui::MouseCodeState_t v4; // edx

  m_nType = event->m_nType;
  if ( event->m_nType <= 2u )
  {
    m_nData2 = event->m_nData2;
    if ( (unsigned int)m_nData2 <= KEY_SCROLLLOCKTOGGLE || (unsigned int)(m_nData2 - 114) <= 0xBF )
    {
      this->SetKeyCodeState(this, a2: m_nData2, a3: m_nType != 1);
    }
    else if ( (unsigned int)(m_nData2 - 107) <= 6 )
    {
      v4 = m_nType != 1;
      if ( m_nType == 2 )
        v4 = BUTTON_DOUBLECLICKED;
      this->SetMouseCodeState(this, a2: m_nData2, a3: v4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002210
// Name: public: virtual void CInputWin32::SetIMEWindow(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputWin32::SetIMEWindow(CInputWin32 *this, void *hwnd)
{
  this->_imeWnd = hwnd;
}

//------------------------------------------------------------------------------
// Address: 0x10002220
// Name: public: virtual void __near * CInputWin32::GetIMEWindow(void)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CInputWin32::GetIMEWindow(CInputWin32 *this)
{
  return this->_imeWnd;
}

//------------------------------------------------------------------------------
// Address: 0x10002230
// Name: SpewIMEInfo
// Source: json
//------------------------------------------------------------------------------
void __fastcall SpewIMEInfo(int a1, __int16 langid)
{
  int v2; // ecx
  unsigned int v3; // eax
  LanguageIds *v4; // eax
  const wchar_t *shortcode; // eax
  wchar_t outstr[512]; // [esp+0h] [ebp-400h] BYREF

  v2 = 0;
  v3 = 0;
  while ( g_LanguageIds[v3].id != langid )
  {
    ++v3;
    ++v2;
    if ( v3 >= 168 )
      return;
  }
  v4 = &g_LanguageIds[v2];
  if ( v4 != nullptr )
  {
    shortcode = v4->shortcode;
    if ( shortcode == nullptr )
      shortcode = L"???";
    _snwprintf(string: outstr, count: 0x200u, format: L"IME language changed to:  %s", shortcode);
    OutputDebugStringW(lpOutputString: outstr);
    OutputDebugStringW(lpOutputString: L"\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x100022B0
// Name: public: virtual int CInputWin32::GetCurrentIMEHandle(void)
// Source: json
//------------------------------------------------------------------------------
HKL __thiscall CInputWin32::GetCurrentIMEHandle(CInputWin32 *this)
{
  return GetKeyboardLayout(idThread: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100022C0
// Name: public: virtual int CInputWin32::GetEnglishIMEHandle(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CInputWin32::GetEnglishIMEHandle(CInputWin32 *this)
{
  return 67699721;
}

//------------------------------------------------------------------------------
// Address: 0x100022D0
// Name: public: virtual void CInputWin32::OnChangeIMEByHandle(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputWin32::OnChangeIMEByHandle(CInputWin32 *this, HKL handleValue)
{
  int v2; // ecx

  ActivateKeyboardLayout(hkl: handleValue, Flags: 0);
  SpewIMEInfo(a1: v2, langid: (__int16)handleValue);
}

//------------------------------------------------------------------------------
// Address: 0x100022F0
// Name: public: virtual void CInputWin32::GetIMELanguageName(wchar_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputWin32::GetIMELanguageName(CInputWin32 *this, wchar_t *buf, unsigned int unicodeBufferSizeInBytes)
{
  unsigned __int16 KeyboardLayout; // dx
  int v4; // ecx
  const wchar_t *v5; // edi
  unsigned int v6; // eax

  KeyboardLayout = (unsigned __int16)GetKeyboardLayout(idThread: 0);
  v4 = 0;
  v5 = L"???";
  v6 = 0;
  while ( g_LanguageIds[v6].id != KeyboardLayout )
  {
    ++v6;
    ++v4;
    if ( v6 >= 168 )
      goto LABEL_6;
  }
  v5 = (&off_1004C144)[5 * v4];
LABEL_6:
  wcsncpy(dest: buf, source: v5, count: (unicodeBufferSizeInBytes >> 1) - 1);
  buf[(unicodeBufferSizeInBytes >> 1) - 1] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10002360
// Name: public: virtual void CInputWin32::GetIMELanguageShortCode(wchar_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputWin32::GetIMELanguageShortCode(
        CInputWin32 *this,
        wchar_t *buf,
        unsigned int unicodeBufferSizeInBytes)
{
  unsigned __int16 KeyboardLayout; // dx
  int v4; // ecx
  unsigned int v5; // eax
  LanguageIds *v6; // eax

  KeyboardLayout = (unsigned __int16)GetKeyboardLayout(idThread: 0);
  v4 = 0;
  v5 = 0;
  while ( g_LanguageIds[v5].id != KeyboardLayout )
  {
    ++v5;
    ++v4;
    if ( v5 >= 168 )
    {
      *buf = 0;
      return;
    }
  }
  v6 = &g_LanguageIds[v4];
  if ( v6 != nullptr )
  {
    wcsncpy(dest: buf, source: v6->shortcode, count: (unicodeBufferSizeInBytes >> 1) - 1);
    buf[(unicodeBufferSizeInBytes >> 1) - 1] = 0;
  }
  else
  {
    *buf = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100023E0
// Name: public: void IMESettingsTransform::Apply(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IMESettingsTransform::Apply(IMESettingsTransform *this, unsigned int hwnd)
{
  HWND v2; // ebx
  HIMC Context; // esi
  unsigned int v5; // [esp-4h] [ebp-14h]
  unsigned int v6; // [esp-4h] [ebp-14h]
  unsigned int dwSentMode; // [esp+Ch] [ebp-4h] BYREF

  v2 = (HWND)hwnd;
  Context = ImmGetContext(a1: (HWND)hwnd);
  if ( Context != nullptr )
  {
    ImmGetConversionStatus(a1: Context, lpfdwConversion: &hwnd, lpfdwSentence: &dwSentMode);
    v5 = ~this->smode_remove & dwSentMode;
    hwnd &= ~this->cmode_remove;
    dwSentMode = v5;
    ImmSetConversionStatus(a1: Context, a2: hwnd, a3: v5);
    v6 = this->smode_add | dwSentMode;
    hwnd |= this->cmode_add;
    dwSentMode = v6;
    ImmSetConversionStatus(a1: Context, a2: hwnd, a3: v6);
    ImmReleaseContext(a1: v2, a2: Context);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002460
// Name: public: virtual int CInputWin32::GetIMEConversionModes(struct vgui::IInput::ConversionModeItem __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CInputWin32::GetIMEConversionModes(
        CInputWin32 *this,
        vgui::IInput::ConversionModeItem *dest,
        unsigned int destcount)
{
  vgui::IInput::ConversionModeItem *v3; // esi
  void *(__thiscall *GetIMEWindow)(struct CInputWin32 *); // eax
  HWND v6; // eax
  HIMC Context; // eax
  HIMC v8; // ebx
  HWND v9; // eax
  unsigned __int16 KeyboardLayout; // dx
  int v11; // ecx
  unsigned int v12; // eax
  LanguageIds *v13; // eax
  unsigned int v14; // ecx
  bool v15; // al
  vgui::IInput::ConversionModeItem *v16; // esi
  unsigned int v17; // eax
  int result; // eax
  unsigned int v19; // ecx
  bool v20; // al
  unsigned int v21; // eax
  bool v22; // al
  unsigned int v23; // eax
  bool v24; // al
  unsigned int v25; // eax
  bool v26; // al
  vgui::IInput::ConversionModeItem *v27; // edi
  unsigned int v28; // eax
  bool v29; // al
  vgui::IInput::ConversionModeItem *v30; // esi
  unsigned int v31; // eax
  unsigned int v32; // ecx
  bool v33; // al
  vgui::IInput::ConversionModeItem *v34; // esi
  unsigned int v35; // eax
  unsigned int v36; // eax
  bool v37; // al
  vgui::IInput::ConversionModeItem *v38; // esi
  unsigned int v39; // eax

  v3 = dest;
  if ( dest != nullptr )
    memset(dst: (unsigned __int8 *)dest, value: 0, count: 264 * destcount);
  GetIMEWindow = this->GetIMEWindow;
  dest = nullptr;
  destcount = 0;
  v6 = (HWND)GetIMEWindow(this);
  Context = ImmGetContext(a1: v6);
  v8 = Context;
  if ( Context != nullptr )
  {
    ImmGetConversionStatus(a1: Context, lpfdwConversion: (LPDWORD)&dest, lpfdwSentence: &destcount);
    v9 = (HWND)this->GetIMEWindow(this);
    ImmReleaseContext(a1: v9, a2: v8);
  }
  KeyboardLayout = (unsigned __int16)GetKeyboardLayout(idThread: 0);
  v11 = 0;
  v12 = 0;
  while ( g_LanguageIds[v12].id != KeyboardLayout )
  {
    ++v12;
    ++v11;
    if ( v12 >= 168 )
    {
      v13 = nullptr;
      goto LABEL_9;
    }
  }
  v13 = &g_LanguageIds[v11];
LABEL_9:
  switch ( v13->languageflag )
  {
    case 1:
      if ( v3 != nullptr )
      {
        wcsncpy(dest: v3->menuname, source: L"#IME_Chinese", count: 0x80u);
        v14 = (unsigned int)dest;
        v3->handleValue = (int)&g_ConversionMode_CHT_ToChinese;
        v15 = (v14 & g_ConversionMode_CHT_ToChinese.cmode_remove) == 0
           && (v14 & g_ConversionMode_CHT_ToChinese.cmode_add) == g_ConversionMode_CHT_ToChinese.cmode_add;
        v3->active = v15;
        v16 = v3 + 1;
        wcsncpy(dest: v16->menuname, source: L"#IME_English", count: 0x80u);
        v17 = (unsigned int)dest;
        v16->handleValue = (int)&g_ConversionMode_CHT_ToEnglish;
        if ( (v17 & g_ConversionMode_CHT_ToEnglish.cmode_remove) != 0 )
        {
          v16->active = false;
          return 2;
        }
        v16->active = (v17 & g_ConversionMode_CHT_ToEnglish.cmode_add) == g_ConversionMode_CHT_ToEnglish.cmode_add;
      }
      result = 2;
      break;
    case 2:
      if ( v3 != nullptr )
      {
        wcsncpy(dest: v3->menuname, source: L"#IME_Hiragana", count: 0x80u);
        v19 = (unsigned int)dest;
        v3->handleValue = (int)&g_ConversionMode_JP_Hiragana;
        v20 = (v19 & g_ConversionMode_JP_Hiragana.cmode_remove) == 0
           && (v19 & g_ConversionMode_JP_Hiragana.cmode_add) == g_ConversionMode_JP_Hiragana.cmode_add;
        v3->active = v20;
        wcsncpy(dest: v3[1].menuname, source: L"#IME_FullWidthKatakana", count: 0x80u);
        v21 = (unsigned int)dest;
        v3[1].handleValue = (int)&g_ConversionMode_JP_FullwidthKatakana;
        v22 = (v21 & g_ConversionMode_JP_FullwidthKatakana.cmode_remove) == 0
           && (v21 & g_ConversionMode_JP_FullwidthKatakana.cmode_add) == g_ConversionMode_JP_FullwidthKatakana.cmode_add;
        v3[1].active = v22;
        wcsncpy(dest: v3[2].menuname, source: L"#IME_FullWidthAlphanumeric", count: 0x80u);
        v23 = (unsigned int)dest;
        v3[2].handleValue = (int)&g_ConversionMode_JP_FullwidthAlphanumeric;
        v24 = (v23 & g_ConversionMode_JP_FullwidthAlphanumeric.cmode_remove) == 0
           && (v23 & g_ConversionMode_JP_FullwidthAlphanumeric.cmode_add) == g_ConversionMode_JP_FullwidthAlphanumeric.cmode_add;
        v3[2].active = v24;
        wcsncpy(dest: v3[3].menuname, source: L"#IME_HalfWidthKatakana", count: 0x80u);
        v25 = (unsigned int)dest;
        v3[3].handleValue = (int)&g_ConversionMode_JP_HalfwidthKatakana;
        v26 = (v25 & g_ConversionMode_JP_HalfwidthKatakana.cmode_remove) == 0
           && (v25 & g_ConversionMode_JP_HalfwidthKatakana.cmode_add) == g_ConversionMode_JP_HalfwidthKatakana.cmode_add;
        v3[3].active = v26;
        v27 = v3 + 4;
        wcsncpy(dest: v3[4].menuname, source: L"#IME_HalfWidthAlphanumeric", count: 0x80u);
        v28 = (unsigned int)dest;
        v3[4].handleValue = (int)&g_ConversionMode_JP_HalfwidthAlphanumeric;
        v29 = (v28 & g_ConversionMode_JP_HalfwidthAlphanumeric.cmode_remove) == 0
           && (v28 & g_ConversionMode_JP_HalfwidthAlphanumeric.cmode_add) == g_ConversionMode_JP_HalfwidthAlphanumeric.cmode_add;
        v30 = v3 + 5;
        v27->active = v29;
        wcsncpy(dest: v30->menuname, source: L"#IME_English", count: 0x80u);
        v31 = (unsigned int)dest;
        v30->handleValue = (int)&g_ConversionMode_JP_DirectInput;
        if ( (v31 & g_ConversionMode_JP_DirectInput.cmode_remove) != 0 )
        {
          v30->active = false;
          return 6;
        }
        v30->active = (v31 & g_ConversionMode_JP_DirectInput.cmode_add) == g_ConversionMode_JP_DirectInput.cmode_add;
      }
      result = 6;
      break;
    case 3:
      if ( v3 != nullptr )
      {
        wcsncpy(dest: v3->menuname, source: L"#IME_Korean", count: 0x80u);
        v32 = (unsigned int)dest;
        v3->handleValue = (int)&g_ConversionMode_KO_ToKorean;
        v33 = (v32 & g_ConversionMode_KO_ToKorean.cmode_remove) == 0
           && (v32 & g_ConversionMode_KO_ToKorean.cmode_add) == g_ConversionMode_KO_ToKorean.cmode_add;
        v3->active = v33;
        v34 = v3 + 1;
        wcsncpy(dest: v34->menuname, source: L"#IME_English", count: 0x80u);
        v35 = (unsigned int)dest;
        v34->handleValue = (int)&g_ConversionMode_KO_ToEnglish;
        if ( (v35 & g_ConversionMode_KO_ToEnglish.cmode_remove) != 0 )
        {
          v34->active = false;
          return 2;
        }
        v34->active = (v35 & g_ConversionMode_KO_ToEnglish.cmode_add) == g_ConversionMode_KO_ToEnglish.cmode_add;
      }
      result = 2;
      break;
    case 4:
      if ( v3 != nullptr )
      {
        wcsncpy(dest: v3->menuname, source: L"#IME_Chinese", count: 0x80u);
        v36 = (unsigned int)dest;
        v3->handleValue = (int)&g_ConversionMode_CHS_ToChinese;
        v37 = (v36 & g_ConversionMode_CHS_ToChinese.cmode_remove) == 0
           && (v36 & g_ConversionMode_CHS_ToChinese.cmode_add) == g_ConversionMode_CHS_ToChinese.cmode_add;
        v3->active = v37;
        v38 = v3 + 1;
        wcsncpy(dest: v38->menuname, source: L"#IME_English", count: 0x80u);
        v39 = (unsigned int)dest;
        v38->handleValue = (int)&g_ConversionMode_CHS_ToChinese;
        if ( (v39 & g_ConversionMode_CHS_ToChinese.cmode_remove) != 0 )
        {
          v38->active = false;
          return 2;
        }
        v38->active = (v39 & g_ConversionMode_CHS_ToChinese.cmode_add) == g_ConversionMode_CHS_ToChinese.cmode_add;
      }
      result = 2;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100028F0
// Name: public: virtual int CInputWin32::GetIMESentenceModes(struct vgui::IInput::SentenceModeItem __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CInputWin32::GetIMESentenceModes(
        CInputWin32 *this,
        vgui::IInput::SentenceModeItem *dest,
        unsigned int destcount)
{
  vgui::IInput::SentenceModeItem *v3; // edi
  void *(__thiscall *GetIMEWindow)(struct CInputWin32 *); // eax
  HWND v6; // eax
  HIMC Context; // eax
  HIMC v8; // ebx
  HWND v9; // eax
  unsigned __int16 KeyboardLayout; // dx
  int v11; // ecx
  unsigned int v12; // eax
  LanguageIds *v13; // eax
  unsigned int v15; // ecx
  bool v16; // al
  unsigned int v17; // eax
  bool v18; // al
  unsigned int v19; // eax
  bool v20; // al
  unsigned int v21; // eax

  v3 = dest;
  if ( dest != nullptr )
    memset(dst: (unsigned __int8 *)dest, value: 0, count: 264 * destcount);
  GetIMEWindow = this->GetIMEWindow;
  destcount = 0;
  dest = nullptr;
  v6 = (HWND)GetIMEWindow(this);
  Context = ImmGetContext(a1: v6);
  v8 = Context;
  if ( Context != nullptr )
  {
    ImmGetConversionStatus(a1: Context, lpfdwConversion: &destcount, lpfdwSentence: (LPDWORD)&dest);
    v9 = (HWND)this->GetIMEWindow(this);
    ImmReleaseContext(a1: v9, a2: v8);
  }
  KeyboardLayout = (unsigned __int16)GetKeyboardLayout(idThread: 0);
  v11 = 0;
  v12 = 0;
  while ( g_LanguageIds[v12].id != KeyboardLayout )
  {
    ++v12;
    ++v11;
    if ( v12 >= 168 )
    {
      v13 = nullptr;
      goto LABEL_9;
    }
  }
  v13 = &g_LanguageIds[v11];
LABEL_9:
  if ( v13->languageflag != 2 )
    return 0;
  if ( v3 != nullptr )
  {
    wcsncpy(dest: v3->menuname, source: L"#IME_General", count: 0x80u);
    v15 = (unsigned int)dest;
    v3->handleValue = (int)&g_SentenceMode_JP_General;
    v16 = (v15 & g_SentenceMode_JP_General.smode_remove) == 0
       && (v15 & g_SentenceMode_JP_General.smode_add) == g_SentenceMode_JP_General.smode_add;
    v3->active = v16;
    wcsncpy(dest: v3[1].menuname, source: L"#IME_BiasNames", count: 0x80u);
    v17 = (unsigned int)dest;
    v3[1].handleValue = (int)&g_SentenceMode_JP_BiasNames;
    v18 = (v17 & g_SentenceMode_JP_BiasNames.smode_remove) == 0
       && (v17 & g_SentenceMode_JP_BiasNames.smode_add) == g_SentenceMode_JP_BiasNames.smode_add;
    v3[1].active = v18;
    wcsncpy(dest: v3[2].menuname, source: L"#IME_BiasSpeech", count: 0x80u);
    v19 = (unsigned int)dest;
    v3[2].handleValue = (int)&g_SentenceMode_JP_BiasSpeech;
    v20 = (v19 & g_SentenceMode_JP_BiasSpeech.smode_remove) == 0
       && (v19 & g_SentenceMode_JP_BiasSpeech.smode_add) == g_SentenceMode_JP_BiasSpeech.smode_add;
    v3[2].active = v20;
    wcsncpy(dest: v3[3].menuname, source: L"#IME_NoConversion", count: 0x80u);
    v21 = (unsigned int)dest;
    v3[3].handleValue = (int)&g_SentenceMode_JP_None;
    if ( (v21 & g_SentenceMode_JP_None.smode_remove) != 0 )
    {
      v3[3].active = false;
      return 4;
    }
    v3[3].active = (v21 & g_SentenceMode_JP_None.smode_add) == g_SentenceMode_JP_None.smode_add;
  }
  return 4;
}

//------------------------------------------------------------------------------
// Address: 0x10002AD0
// Name: public: virtual void CInputWin32::OnChangeIMEConversionModeByHandle(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputWin32::OnChangeIMEConversionModeByHandle(CInputWin32 *this, IMESettingsTransform *handleValue)
{
  void *v2; // eax

  if ( handleValue != nullptr )
  {
    v2 = this->GetIMEWindow(this);
    IMESettingsTransform::Apply(this: handleValue, hwnd: (unsigned int)v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002AF0
// Name: private: void CInputWin32::CreateNewCandidateList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputWin32::CreateNewCandidateList(CInputWin32 *this)
{
  CInputWin32 *v1; // esi
  void *(__thiscall *GetIMEWindow)(struct CInputWin32 *); // edx
  HWND v3; // eax
  HIMC Context; // ebx
  DWORD CandidateListCountW; // eax
  DWORD v6; // esi
  tagCANDIDATELIST *v7; // edi
  CInputWin32 *v8; // ecx
  HWND v9; // eax
  unsigned int numCandidates; // [esp+8h] [ebp-8h] BYREF
  CInputWin32 *v11; // [esp+Ch] [ebp-4h]

  v1 = this;
  GetIMEWindow = this->GetIMEWindow;
  v11 = this;
  v3 = (HWND)((int (__fastcall *)(CInputWin32 *))GetIMEWindow)(a1: this);
  Context = ImmGetContext(a1: v3);
  if ( Context != nullptr )
  {
    numCandidates = 0;
    CandidateListCountW = ImmGetCandidateListCountW(a1: Context, lpdwListCount: &numCandidates);
    if ( numCandidates != 0 )
    {
      v6 = CandidateListCountW + 1;
      v7 = (tagCANDIDATELIST *)operator new(nSize: CandidateListCountW + 1);
      _V_memset(dest: v7, fill: 0, count: v6);
      if ( ImmGetCandidateListW(a1: Context, deIndex: 0, lpCandList: v7, dwBufLen: v6) != 0 )
      {
        v8 = v11;
        v11->_imeCandidates = v7;
        v1 = v8;
      }
      else
      {
        free(pMem: v7);
        v1 = v11;
      }
    }
    v9 = (HWND)v1->GetIMEWindow(this: v1);
    ImmReleaseContext(a1: v9, a2: Context);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002B80
// Name: public: virtual int CInputWin32::GetCandidateListCount(void)
// Source: json
//------------------------------------------------------------------------------
tagCANDIDATELIST *__thiscall CInputWin32::GetCandidateListCount(CInputWin32 *this)
{
  tagCANDIDATELIST *result; // eax

  result = this->_imeCandidates;
  if ( result != nullptr )
    return (tagCANDIDATELIST *)result->dwCount;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10002B90
// Name: public: virtual void CInputWin32::GetCandidate(int,wchar_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputWin32::GetCandidate(CInputWin32 *this, int num, wchar_t *dest, unsigned int destSizeBytes)
{
  tagCANDIDATELIST *imeCandidates; // eax

  *dest = 0;
  if ( num >= 0 )
  {
    imeCandidates = this->_imeCandidates;
    if ( num < (signed int)imeCandidates->dwCount )
    {
      wcsncpy(
        dest,
        source: (const wchar_t *)((char *)imeCandidates + imeCandidates->dwOffset[num]),
        count: (destSizeBytes >> 1) - 1);
      dest[(destSizeBytes >> 1) - 1] = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002BE0
// Name: public: virtual int CInputWin32::GetCandidateListSelectedItem(void)
// Source: json
//------------------------------------------------------------------------------
tagCANDIDATELIST *__thiscall CInputWin32::GetCandidateListSelectedItem(CInputWin32 *this)
{
  tagCANDIDATELIST *result; // eax

  result = this->_imeCandidates;
  if ( result != nullptr )
    return (tagCANDIDATELIST *)result->dwSelection;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10002BF0
// Name: public: virtual int CInputWin32::GetCandidateListPageSize(void)
// Source: json
//------------------------------------------------------------------------------
tagCANDIDATELIST *__thiscall CInputWin32::GetCandidateListPageSize(CInputWin32 *this)
{
  tagCANDIDATELIST *result; // eax

  result = this->_imeCandidates;
  if ( result != nullptr )
    return (tagCANDIDATELIST *)result->dwPageSize;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10002C00
// Name: public: virtual int CInputWin32::GetCandidateListPageStart(void)
// Source: json
//------------------------------------------------------------------------------
tagCANDIDATELIST *__thiscall CInputWin32::GetCandidateListPageStart(CInputWin32 *this)
{
  tagCANDIDATELIST *result; // eax

  result = this->_imeCandidates;
  if ( result != nullptr )
    return (tagCANDIDATELIST *)result->dwPageStart;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10002C10
// Name: public: virtual void CInputWin32::SetCandidateListPageStart(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputWin32::SetCandidateListPageStart(CInputWin32 *this, DWORD start)
{
  HWND v3; // eax
  HIMC Context; // edi
  HWND v5; // eax

  v3 = (HWND)this->GetIMEWindow(this);
  Context = ImmGetContext(a1: v3);
  if ( Context != nullptr )
  {
    ImmNotifyIME(a1: Context, dwAction: 0x16u, dwIndex: 0, dwValue: start);
    v5 = (HWND)this->GetIMEWindow(this);
    ImmReleaseContext(a1: v5, a2: Context);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002C50
// Name: public: virtual bool CInputWin32::CandidateListStartsAtOne(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CInputWin32::CandidateListStartsAtOne(CInputWin32 *this)
{
  HKL KeyboardLayout; // eax

  KeyboardLayout = GetKeyboardLayout(idThread: 0);
  return (ImmGetProperty(a1: KeyboardLayout, a2: 4u) & 0x40000) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10002C70
// Name: public: virtual void CInputWin32::SetCandidateWindowPos(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputWin32::SetCandidateWindowPos(CInputWin32 *this, int x, int y)
{
  HWND v4; // eax
  HIMC Context; // edi
  HWND v6; // eax
  tagCANDIDATEFORM Candidate; // [esp+8h] [ebp-20h] BYREF

  v4 = (HWND)this->GetIMEWindow(this);
  Context = ImmGetContext(a1: v4);
  if ( Context != nullptr )
  {
    Candidate.dwIndex = 0;
    Candidate.dwStyle = 32;
    Candidate.ptCurrentPos.x = x;
    Candidate.ptCurrentPos.y = y;
    ImmSetCandidateWindow(a1: Context, lpCandidate: &Candidate);
    v6 = (HWND)this->GetIMEWindow(this);
    ImmReleaseContext(a1: v6, a2: Context);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002CD0
// Name: public: virtual bool CInputWin32::GetShouldInvertCompositionString(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CInputWin32::GetShouldInvertCompositionString(CInputWin32 *this)
{
  unsigned __int16 KeyboardLayout; // dx
  int v2; // ecx
  unsigned int v3; // eax
  LanguageIds *v5; // eax

  KeyboardLayout = (unsigned __int16)GetKeyboardLayout(idThread: 0);
  v2 = 0;
  v3 = 0;
  while ( g_LanguageIds[v3].id != KeyboardLayout )
  {
    ++v3;
    ++v2;
    if ( v3 >= 168 )
      return false;
  }
  v5 = &g_LanguageIds[v2];
  return v5 != nullptr && v5->invertcomposition;
}

//------------------------------------------------------------------------------
// Address: 0x10002D10
// Name: public: virtual void CInputWin32::GetCursorPos(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputWin32::GetCursorPos(CInputWin32 *this, int *x, int *y)
{
  if ( IsDispatchingMessageQueue() )
    this->GetCursorPosition(this, a2: x, a3: y);
  else
    CInputWin32::SurfaceGetCursorPos(this, x, y);
}

//------------------------------------------------------------------------------
// Address: 0x10002D40
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<struct CInputWin32::InputContext_t,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CInputWin32::InputContext_t,int>,int>::Grow(
        CUtlMemory<UtlLinkedListElem_t<CInputWin32::InputContext_t,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 1408 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *)_g_pMemAlloc->Realloc_2(
                                                                                  this: _g_pMemAlloc,
                                                                                  a2: m_pMemory,
                                                                                  a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *)_g_pMemAlloc->Alloc_2(
                                                                                  this: _g_pMemAlloc,
                                                                                  a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002DE0
// Name: public: virtual void CInputWin32::AssociatePanelWithInputContext(int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputWin32::AssociatePanelWithInputContext(CInputWin32 *this, int context, unsigned int pRoot)
{
  UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *p_m_DefaultInputContext; // eax

  if ( context == -1 )
    p_m_DefaultInputContext = (UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *)&this->m_DefaultInputContext;
  else
    p_m_DefaultInputContext = &this->m_Contexts.m_Memory.m_pMemory[context];
  if ( p_m_DefaultInputContext->m_Element._rootPanel != pRoot )
  {
    this->ResetInputContext(this, a2: context);
    if ( context == -1 )
      this->m_DefaultInputContext._rootPanel = pRoot;
    else
      this->m_Contexts.m_Memory.m_pMemory[context].m_Element._rootPanel = pRoot;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002E50
// Name: public: virtual void CInputWin32::SetMouseFocus(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputWin32::SetMouseFocus(CInputWin32 *this, unsigned int newMouseFocus)
{
  unsigned int v2; // esi
  CInputWin32 *v3; // ebx
  int m_hContext; // edi
  UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *p_m_DefaultInputContext; // edi
  char v6; // bl
  int v7; // eax
  vgui::VPanel *mouseOver; // eax
  vgui::VPanel *mouseCapture; // ecx
  KeyValues *v10; // eax
  KeyValues *v11; // eax
  vgui::VPanel *v12; // ecx
  vgui::VPanel *v13; // eax
  KeyValues *v14; // eax
  KeyValues *v15; // eax
  vgui::VPanel *v16; // esi
  const char *v17; // ebx
  vgui::VPanel *mouseFocus; // ecx
  const char *v19; // eax
  char isPopup; // [esp+2Fh] [ebp-1h]

  v2 = newMouseFocus;
  v3 = this;
  if ( ((unsigned __int8 (__stdcall *)(unsigned int, int))this->IsChildOfModalPanel)(a1: newMouseFocus, a2: 1) != 0 )
  {
    m_hContext = v3->m_hContext;
    if ( m_hContext == -1 )
      p_m_DefaultInputContext = (UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *)&v3->m_DefaultInputContext;
    else
      p_m_DefaultInputContext = &v3->m_Contexts.m_Memory.m_pMemory[m_hContext];
    if ( newMouseFocus != 0 )
    {
      while ( 1 )
      {
        v6 = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)v2 + 172))(a1: v2);
        isPopup = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)v2 + 28))(a1: v2);
        v7 = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)v2 + 124))(a1: v2);
        v2 = v7;
        if ( v6 == 0 )
          break;
        if ( isPopup != 0 || v7 == 0 || (*(int (__thiscall **)(int))(*(_DWORD *)v7 + 124))(a1: v7) == 0 )
        {
          v3 = this;
          v2 = newMouseFocus;
          goto LABEL_11;
        }
      }
    }
    else
    {
LABEL_11:
      mouseOver = p_m_DefaultInputContext->m_Element._mouseOver;
      if ( mouseOver != (vgui::VPanel *)v2
        || p_m_DefaultInputContext->m_Element._mouseCapture == nullptr
        && p_m_DefaultInputContext->m_Element._mouseFocus != (vgui::VPanel *)v2 )
      {
        p_m_DefaultInputContext->m_Element._oldMouseFocus = mouseOver;
        p_m_DefaultInputContext->m_Element._mouseOver = (vgui::VPanel *)v2;
        if ( mouseOver != nullptr )
        {
          mouseCapture = p_m_DefaultInputContext->m_Element._mouseCapture;
          if ( mouseCapture == nullptr || mouseOver == mouseCapture )
          {
            v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v10 != nullptr )
              v11 = KeyValues::KeyValues(this: v10, setName: "CursorExited");
            else
              v11 = nullptr;
            ((void (__stdcall *)(vgui::VPanel *, KeyValues *, _DWORD, _DWORD))vgui::g_pIVgui->PostMessageA)(
              a1: p_m_DefaultInputContext->m_Element._oldMouseFocus,
              a2: v11,
              a3: 0,
              a4: 0);
          }
        }
        v12 = p_m_DefaultInputContext->m_Element._mouseOver;
        if ( v12 != nullptr )
        {
          v13 = p_m_DefaultInputContext->m_Element._mouseCapture;
          if ( v13 == nullptr || v12 == v13 )
          {
            v14 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v14 != nullptr )
              v15 = KeyValues::KeyValues(this: v14, setName: "CursorEntered");
            else
              v15 = nullptr;
            ((void (__stdcall *)(vgui::VPanel *, KeyValues *, _DWORD, _DWORD))vgui::g_pIVgui->PostMessageA)(
              a1: p_m_DefaultInputContext->m_Element._mouseOver,
              a2: v15,
              a3: 0,
              a4: 0);
          }
        }
        v16 = p_m_DefaultInputContext->m_Element._mouseCapture;
        if ( v16 == nullptr )
          v16 = p_m_DefaultInputContext->m_Element._mouseOver;
        if ( v3->m_nDebugMessages > 0 )
        {
          if ( v16 != nullptr )
            v17 = v16->GetName(this: v16);
          else
            v17 = "(no name)";
          mouseFocus = p_m_DefaultInputContext->m_Element._mouseFocus;
          if ( mouseFocus != nullptr )
            v19 = mouseFocus->GetName(this: mouseFocus);
          else
            v19 = "(no name)";
          vgui::g_pIVgui->DPrintf2(this: vgui::g_pIVgui, a2: "changing mouse focus from %s to %s\n", v19, v17);
        }
        p_m_DefaultInputContext->m_Element._mouseFocus = v16;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003040
// Name: private: class vgui::VPanel __near * CInputWin32::GetMouseFocusIgnoringModalSubtree(void)
// Source: json
//------------------------------------------------------------------------------
vgui::VPanel *__thiscall CInputWin32::GetMouseFocusIgnoringModalSubtree(CInputWin32 *this)
{
  CInputWin32 *v1; // ebx
  int m_hContext; // eax
  UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *p_m_DefaultInputContext; // eax
  int *rootPanel; // ecx
  int m_nCursorX; // esi
  int m_nCursorY; // edi
  int v7; // eax
  unsigned int v8; // edi
  int v9; // esi
  bool v10; // al
  char v11; // bl
  int v12; // eax
  int *v13; // eax
  int v14; // edx
  int v15; // eax
  int y; // [esp+10h] [ebp-14h]
  int x; // [esp+14h] [ebp-10h]
  int i; // [esp+18h] [ebp-Ch]
  vgui::VPanel *focus; // [esp+1Ch] [ebp-8h]
  char wantsMouse; // [esp+23h] [ebp-1h]

  v1 = this;
  m_hContext = this->m_hContext;
  focus = nullptr;
  if ( m_hContext == -1 )
    p_m_DefaultInputContext = (UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *)&this->m_DefaultInputContext;
  else
    p_m_DefaultInputContext = &this->m_Contexts.m_Memory.m_pMemory[m_hContext];
  rootPanel = (int *)p_m_DefaultInputContext->m_Element._rootPanel;
  m_nCursorX = p_m_DefaultInputContext->m_Element.m_nCursorX;
  m_nCursorY = p_m_DefaultInputContext->m_Element.m_nCursorY;
  x = m_nCursorX;
  y = m_nCursorY;
  if ( p_m_DefaultInputContext->m_Element._rootPanel != 0 )
  {
    v14 = *rootPanel;
    goto LABEL_20;
  }
  if ( !vgui::g_pSurface->IsCursorVisible(this: vgui::g_pSurface)
    || !vgui::g_pSurface->IsWithin(this: vgui::g_pSurface, a2: m_nCursorX, a3: m_nCursorY) )
  {
    goto LABEL_23;
  }
  v7 = vgui::g_pSurface->GetPopupCount(this: vgui::g_pSurface) - 1;
  i = v7;
  if ( v7 < 0 )
  {
LABEL_19:
    v13 = (int *)vgui::g_pSurface->GetEmbeddedPanel(this: vgui::g_pSurface);
    v14 = *v13;
    rootPanel = v13;
LABEL_20:
    v15 = (*(int (__fastcall **)(int *))(v14 + 156))(a1: rootPanel);
    focus = (vgui::VPanel *)(*(int (__thiscall **)(int, int, int, _DWORD))(*(_DWORD *)v15 + 20))(
                              a1: v15,
                              a2: m_nCursorX,
                              a3: m_nCursorY,
                              a4: 0);
    goto LABEL_23;
  }
  while ( 1 )
  {
    v8 = vgui::g_pSurface->GetPopup(this: vgui::g_pSurface, a2: v7);
    v9 = v8;
    wantsMouse = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)v8 + 172))(a1: v8);
    v10 = vgui::g_pSurface->IsMinimized(this: vgui::g_pSurface, a2: v8);
    v11 = !v10;
    if ( !v10 )
    {
      do
      {
        if ( v9 == 0 )
          break;
        if ( (*(int (__thiscall **)(int))(*(_DWORD *)v9 + 124))(a1: v9) == 0 )
          break;
        v11 = (*(int (__thiscall **)(int))(*(_DWORD *)v9 + 100))(a1: v9);
        v9 = (*(int (__thiscall **)(int))(*(_DWORD *)v9 + 124))(a1: v9);
      }
      while ( v11 != 0 );
    }
    if ( wantsMouse != 0 && v11 != 0 )
    {
      v12 = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)v8 + 156))(a1: v8);
      focus = (vgui::VPanel *)(*(int (__thiscall **)(int, int, int, _DWORD))(*(_DWORD *)v12 + 20))(
                                a1: v12,
                                a2: x,
                                a3: y,
                                a4: 0);
      if ( focus != nullptr )
        break;
    }
    if ( --i < 0 )
    {
      v1 = this;
      m_nCursorX = x;
      m_nCursorY = y;
      goto LABEL_19;
    }
    v7 = i;
  }
  v1 = this;
LABEL_23:
  if ( v1->IsChildOfModalPanel(this: v1, a2: (unsigned int)focus, a3: false) )
    return focus;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100031F0
// Name: public: virtual void CInputWin32::SetMouseCaptureEx(unsigned int,enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputWin32::SetMouseCaptureEx(
        CInputWin32 *this,
        unsigned int panel,
        ButtonCode_t captureStartMouseCode)
{
  int m_hContext; // eax

  this->SetMouseCapture(this, a2: panel);
  if ( this->IsChildOfModalPanel(this, a2: panel, a3: true) )
  {
    m_hContext = this->m_hContext;
    if ( m_hContext == -1 )
      this->m_DefaultInputContext.m_MouseCaptureStartCode = captureStartMouseCode;
    else
      this->m_Contexts.m_Memory.m_pMemory[m_hContext].m_Element.m_MouseCaptureStartCode = captureStartMouseCode;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003250
// Name: public: virtual unsigned int CInputWin32::GetMouseCapture(void)
// Source: json
//------------------------------------------------------------------------------
vgui::VPanel *__thiscall CInputWin32::GetMouseCapture(CInputWin32 *this)
{
  int m_hContext; // eax

  m_hContext = this->m_hContext;
  if ( m_hContext == -1 )
    return this->m_DefaultInputContext._mouseCapture;
  else
    return this->m_Contexts.m_Memory.m_pMemory[m_hContext].m_Element._mouseCapture;
}

//------------------------------------------------------------------------------
// Address: 0x10003280
// Name: public: virtual void CInputWin32::SetMouseCapture(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputWin32::SetMouseCapture(CInputWin32 *this, vgui::VPanel *panel)
{
  int m_hContext; // eax
  UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *p_m_DefaultInputContext; // esi
  vgui::VPanel *mouseCapture; // eax
  KeyValues *v6; // eax
  KeyValues *v7; // eax
  unsigned int v8; // eax

  if ( this->IsChildOfModalPanel(this, a2: (unsigned int)panel, a3: true) )
  {
    m_hContext = this->m_hContext;
    if ( m_hContext == -1 )
      p_m_DefaultInputContext = (UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *)&this->m_DefaultInputContext;
    else
      p_m_DefaultInputContext = &this->m_Contexts.m_Memory.m_pMemory[m_hContext];
    mouseCapture = p_m_DefaultInputContext->m_Element._mouseCapture;
    p_m_DefaultInputContext->m_Element.m_MouseCaptureStartCode = BUTTON_CODE_INVALID;
    if ( mouseCapture != nullptr && panel != mouseCapture )
    {
      v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v6 != nullptr )
        v7 = KeyValues::KeyValues(this: v6, setName: "MouseCaptureLost");
      else
        v7 = nullptr;
      ((void (__stdcall *)(vgui::VPanel *, KeyValues *, _DWORD, _DWORD))vgui::g_pIVgui->PostMessageA)(
        a1: p_m_DefaultInputContext->m_Element._mouseCapture,
        a2: v7,
        a3: 0,
        a4: 0);
    }
    if ( panel != nullptr )
    {
      vgui::g_pSurface->EnableMouseCapture(this: vgui::g_pSurface, a2: (unsigned int)panel, a3: true);
    }
    else
    {
      v8 = (unsigned int)p_m_DefaultInputContext->m_Element._mouseCapture;
      if ( v8 != 0 )
        vgui::g_pSurface->EnableMouseCapture(this: vgui::g_pSurface, a2: v8, a3: false);
    }
    p_m_DefaultInputContext->m_Element._mouseCapture = panel;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003350
// Name: private: bool CInputWin32::IsChildOfModalSubTree(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CInputWin32::IsChildOfModalSubTree(CInputWin32 *this, unsigned int panel)
{
  int m_hContext; // eax
  UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *p_m_DefaultInputContext; // esi
  vgui::VPanel *m_pModalSubTree; // eax

  if ( panel == 0 )
    return 1;
  m_hContext = this->m_hContext;
  if ( m_hContext == -1 )
    p_m_DefaultInputContext = (UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *)&this->m_DefaultInputContext;
  else
    p_m_DefaultInputContext = &this->m_Contexts.m_Memory.m_pMemory[m_hContext];
  m_pModalSubTree = p_m_DefaultInputContext->m_Element.m_pModalSubTree;
  if ( m_pModalSubTree == nullptr )
    return 1;
  if ( (*(unsigned __int8 (__thiscall **)(unsigned int, vgui::VPanel *))(*(_DWORD *)panel + 136))(
         a1: panel,
         a2: m_pModalSubTree) != 0 )
    return p_m_DefaultInputContext->m_Element.m_bRestrictMessagesToModalSubTree;
  return !p_m_DefaultInputContext->m_Element.m_bRestrictMessagesToModalSubTree;
}

//------------------------------------------------------------------------------
// Address: 0x100033D0
// Name: public: virtual bool CInputWin32::IsChildOfModalPanel(unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CInputWin32::IsChildOfModalPanel(CInputWin32 *this, unsigned int panel, bool checkModalSubTree)
{
  char result; // al
  int m_hContext; // eax
  UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *p_m_DefaultInputContext; // eax
  vgui::VPanel *appModalPanel; // eax

  if ( panel == 0 )
    return 1;
  m_hContext = this->m_hContext;
  if ( m_hContext == -1 )
    p_m_DefaultInputContext = (UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *)&this->m_DefaultInputContext;
  else
    p_m_DefaultInputContext = &this->m_Contexts.m_Memory.m_pMemory[m_hContext];
  appModalPanel = p_m_DefaultInputContext->m_Element._appModalPanel;
  if ( appModalPanel == nullptr
    || (result = (*(int (__thiscall **)(unsigned int, vgui::VPanel *))(*(_DWORD *)panel + 136))(
                   a1: panel,
                   a2: appModalPanel)) != 0 )
  {
    if ( !checkModalSubTree )
      return 1;
    return CInputWin32::IsChildOfModalSubTree(this, panel);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10003440
// Name: public: virtual unsigned int CInputWin32::GetFocus(void)
// Source: json
//------------------------------------------------------------------------------
vgui::VPanel *__thiscall CInputWin32::GetFocus(CInputWin32 *this)
{
  int m_hContext; // eax

  m_hContext = this->m_hContext;
  if ( m_hContext == -1 )
    return this->m_DefaultInputContext._keyFocus;
  else
    return this->m_Contexts.m_Memory.m_pMemory[m_hContext].m_Element._keyFocus;
}

//------------------------------------------------------------------------------
// Address: 0x10003470
// Name: public: virtual unsigned int CInputWin32::GetMouseOver(void)
// Source: json
//------------------------------------------------------------------------------
vgui::VPanel *__thiscall CInputWin32::GetMouseOver(CInputWin32 *this)
{
  int m_hContext; // eax

  m_hContext = this->m_hContext;
  if ( m_hContext == -1 )
    return this->m_DefaultInputContext._mouseOver;
  else
    return this->m_Contexts.m_Memory.m_pMemory[m_hContext].m_Element._mouseOver;
}

//------------------------------------------------------------------------------
// Address: 0x100034A0
// Name: public: virtual unsigned int CInputWin32::GetMouseFocus(void)
// Source: json
//------------------------------------------------------------------------------
vgui::VPanel *__thiscall CInputWin32::GetMouseFocus(CInputWin32 *this)
{
  int m_hContext; // eax

  m_hContext = this->m_hContext;
  if ( m_hContext == -1 )
    return this->m_DefaultInputContext._mouseFocus;
  else
    return this->m_Contexts.m_Memory.m_pMemory[m_hContext].m_Element._mouseFocus;
}

//------------------------------------------------------------------------------
// Address: 0x100034D0
// Name: public: virtual bool CInputWin32::WasMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CInputWin32::WasMousePressed(CInputWin32 *this, ButtonCode_t code)
{
  int m_hContext; // eax

  m_hContext = this->m_hContext;
  if ( m_hContext == -1 )
    return *((_BYTE *)&this->_keyTrans[80] + code + 1);
  else
    return *((_BYTE *)&this->m_Contexts.m_Memory.m_pMemory[m_hContext - 1].m_Element.m_nExternallySetCursorX + code + 1);
}

//------------------------------------------------------------------------------
// Address: 0x10003510
// Name: public: virtual bool CInputWin32::WasMouseDoublePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
// Force-skipped: ?WasMouseDoublePressed@CInputWin32@@UAE_NW4ButtonCode_t@@@Z

//------------------------------------------------------------------------------
// Address: 0x10003550
// Name: public: virtual bool CInputWin32::IsMouseDown(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CInputWin32::IsMouseDown(CInputWin32 *this, ButtonCode_t code)
{
  int m_hContext; // eax

  m_hContext = this->m_hContext;
  if ( m_hContext == -1 )
    return *((_BYTE *)&this->_keyTrans[83] + code + 3);
  else
    return *((_BYTE *)&this->m_Contexts.m_Memory.m_pMemory[m_hContext - 1].m_Element.m_KeyCodeUnhandledListeners.m_Memory.m_pMemory
           + code
           + 3);
}

//------------------------------------------------------------------------------
// Address: 0x10003590
// Name: public: virtual bool CInputWin32::WasMouseReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CInputWin32::WasMouseReleased(CInputWin32 *this, ButtonCode_t code)
{
  int m_hContext; // eax

  m_hContext = this->m_hContext;
  if ( m_hContext == -1 )
    return *((_BYTE *)&this->_keyTrans[85] + code + 2);
  else
    return *((_BYTE *)&this->m_Contexts.m_Memory.m_pMemory[m_hContext - 1].m_Element.m_KeyCodeUnhandledListeners.m_Memory.m_nGrowSize
           + code
           + 2);
}

//------------------------------------------------------------------------------
// Address: 0x100035D0
// Name: public: virtual bool CInputWin32::WasKeyPressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CInputWin32::WasKeyPressed(CInputWin32 *this, ButtonCode_t code)
{
  int m_hContext; // eax

  m_hContext = this->m_hContext;
  if ( m_hContext == -1 )
    return this->m_DefaultInputContext._keyPressed[code];
  else
    return this->m_Contexts.m_Memory.m_pMemory[m_hContext].m_Element._keyPressed[code];
}

//------------------------------------------------------------------------------
// Address: 0x10003610
// Name: public: virtual bool CInputWin32::IsKeyDown(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CInputWin32::IsKeyDown(CInputWin32 *this, ButtonCode_t code)
{
  int m_hContext; // eax

  m_hContext = this->m_hContext;
  if ( m_hContext == -1 )
    return this->m_DefaultInputContext._keyDown[code];
  else
    return this->m_Contexts.m_Memory.m_pMemory[m_hContext].m_Element._keyDown[code];
}

//------------------------------------------------------------------------------
// Address: 0x10003650
// Name: public: virtual bool CInputWin32::WasKeyTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CInputWin32::WasKeyTyped(CInputWin32 *this, ButtonCode_t code)
{
  int m_hContext; // eax

  m_hContext = this->m_hContext;
  if ( m_hContext == -1 )
    return this->m_DefaultInputContext._keyTyped[code];
  else
    return this->m_Contexts.m_Memory.m_pMemory[m_hContext].m_Element._keyTyped[code];
}

//------------------------------------------------------------------------------
// Address: 0x10003690
// Name: public: virtual bool CInputWin32::WasKeyReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CInputWin32::WasKeyReleased(CInputWin32 *this, ButtonCode_t code)
{
  int m_hContext; // eax

  m_hContext = this->m_hContext;
  if ( m_hContext == -1 )
    return this->m_DefaultInputContext._keyReleased[code];
  else
    return this->m_Contexts.m_Memory.m_pMemory[m_hContext].m_Element._keyReleased[code];
}

//------------------------------------------------------------------------------
// Address: 0x100036D0
// Name: public: virtual void CInputWin32::UpdateCursorPosInternal(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputWin32::UpdateCursorPosInternal(CInputWin32 *this, int x, int y)
{
  int m_hContext; // eax
  UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *p_m_DefaultInputContext; // eax

  m_hContext = this->m_hContext;
  if ( m_hContext == -1 )
    p_m_DefaultInputContext = (UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *)&this->m_DefaultInputContext;
  else
    p_m_DefaultInputContext = &this->m_Contexts.m_Memory.m_pMemory[m_hContext];
  if ( p_m_DefaultInputContext->m_Element.m_nCursorX != x || p_m_DefaultInputContext->m_Element.m_nCursorY != y )
  {
    p_m_DefaultInputContext->m_Element.m_nCursorX = x;
    p_m_DefaultInputContext->m_Element.m_nCursorY = y;
    this->UpdateMouseFocus(this, a2: x, a3: y);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003730
// Name: public: virtual void CInputWin32::SetCursorPos(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputWin32::SetCursorPos(CInputWin32 *this, int x, int y)
{
  int m_hContext; // eax
  UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *p_m_DefaultInputContext; // eax

  if ( IsDispatchingMessageQueue() )
  {
    m_hContext = this->m_hContext;
    if ( m_hContext == -1 )
      p_m_DefaultInputContext = (UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *)&this->m_DefaultInputContext;
    else
      p_m_DefaultInputContext = &this->m_Contexts.m_Memory.m_pMemory[m_hContext];
    p_m_DefaultInputContext->m_Element.m_nExternallySetCursorX = x;
    p_m_DefaultInputContext->m_Element.m_nExternallySetCursorY = y;
    p_m_DefaultInputContext->m_Element.m_bSetCursorExplicitly = true;
  }
  else
  {
    CInputWin32::SurfaceSetCursorPos(this, x, y);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003790
// Name: public: virtual void CInputWin32::GetCursorPosition(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputWin32::GetCursorPosition(CInputWin32 *this, int *x, int *y)
{
  int m_hContext; // eax
  UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *p_m_DefaultInputContext; // eax

  m_hContext = this->m_hContext;
  if ( m_hContext == -1 )
    p_m_DefaultInputContext = (UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *)&this->m_DefaultInputContext;
  else
    p_m_DefaultInputContext = &this->m_Contexts.m_Memory.m_pMemory[m_hContext];
  *x = p_m_DefaultInputContext->m_Element.m_nCursorX;
  *y = p_m_DefaultInputContext->m_Element.m_nCursorY;
}

//------------------------------------------------------------------------------
// Address: 0x100037D0
// Name: public: virtual bool CInputWin32::InternalJoystickMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CInputWin32::InternalJoystickMoved(CInputWin32 *this, int axis, int value)
{
  KeyValues *v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  int m_hContext; // eax
  UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *p_m_DefaultInputContext; // esi
  unsigned int keyFocus; // eax
  KeyValues *v10; // eax
  KeyValues *v11; // eax
  const char *axis_message_map[4]; // [esp+28h] [ebp-10h]

  if ( axis != 0 )
  {
    if ( axis != 1 )
      goto LABEL_9;
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
    {
      v5 = KeyValues::KeyValues(this: v6, setName: "SetJoystickYPosInternal", firstKey: "pos", firstValue: value);
      goto LABEL_8;
    }
LABEL_7:
    v5 = nullptr;
    goto LABEL_8;
  }
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 == nullptr )
    goto LABEL_7;
  v5 = KeyValues::KeyValues(this: v4, setName: "SetJoystickXPosInternal", firstKey: "pos", firstValue: value);
LABEL_8:
  ((void (__thiscall *)(vgui::IVGui *, int, KeyValues *, _DWORD, _DWORD))vgui::g_pIVgui->PostMessageA)(
    a1: vgui::g_pIVgui,
    a2: -1,
    a3: v5,
    a4: 0,
    a5: 0);
LABEL_9:
  m_hContext = this->m_hContext;
  if ( m_hContext == -1 )
    p_m_DefaultInputContext = (UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *)&this->m_DefaultInputContext;
  else
    p_m_DefaultInputContext = &this->m_Contexts.m_Memory.m_pMemory[m_hContext];
  keyFocus = (unsigned int)p_m_DefaultInputContext->m_Element._keyFocus;
  if ( keyFocus != 0 && this->IsChildOfModalPanel(this, a2: keyFocus, a3: true) )
  {
    axis_message_map[0] = "Stick1XChanged";
    axis_message_map[1] = "Stick1YChanged";
    axis_message_map[2] = "Stick2XChanged";
    axis_message_map[3] = "Stick2YChanged";
    v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v10 != nullptr )
      v11 = KeyValues::KeyValues(this: v10, setName: axis_message_map[axis], firstKey: "pos", firstValue: value);
    else
      v11 = nullptr;
    ((void (__stdcall *)(vgui::VPanel *, KeyValues *, _DWORD, _DWORD))vgui::g_pIVgui->PostMessageA)(
      a1: p_m_DefaultInputContext->m_Element._keyFocus,
      a2: v11,
      a3: 0,
      a4: 0);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10003900
// Name: public: virtual void CInputWin32::HandleExplicitSetCursor(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputWin32::HandleExplicitSetCursor(CInputWin32 *this)
{
  int m_hContext; // esi
  UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *p_m_DefaultInputContext; // esi
  int m_nExternallySetCursorX; // eax
  int m_nExternallySetCursorY; // [esp-4h] [ebp-Ch]

  m_hContext = this->m_hContext;
  if ( m_hContext == -1 )
    p_m_DefaultInputContext = (UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *)&this->m_DefaultInputContext;
  else
    p_m_DefaultInputContext = &this->m_Contexts.m_Memory.m_pMemory[m_hContext];
  if ( p_m_DefaultInputContext->m_Element.m_bSetCursorExplicitly )
  {
    m_nExternallySetCursorX = p_m_DefaultInputContext->m_Element.m_nExternallySetCursorX;
    m_nExternallySetCursorY = p_m_DefaultInputContext->m_Element.m_nExternallySetCursorY;
    p_m_DefaultInputContext->m_Element.m_nCursorY = m_nExternallySetCursorY;
    p_m_DefaultInputContext->m_Element.m_nCursorX = m_nExternallySetCursorX;
    p_m_DefaultInputContext->m_Element.m_bSetCursorExplicitly = false;
    p_m_DefaultInputContext->m_Element.m_nLastPostedCursorY = -9999;
    p_m_DefaultInputContext->m_Element.m_nLastPostedCursorX = -9999;
    CInputWin32::SurfaceSetCursorPos(this, x: m_nExternallySetCursorX, y: m_nExternallySetCursorY);
    this->UpdateMouseFocus(
      this,
      a2: p_m_DefaultInputContext->m_Element.m_nCursorX,
      a3: p_m_DefaultInputContext->m_Element.m_nCursorY);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003990
// Name: public: virtual void CInputWin32::PostCursorMessage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputWin32::PostCursorMessage(CInputWin32 *this)
{
  int m_hContext; // esi
  UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *p_m_DefaultInputContext; // esi
  int m_nExternallySetCursorY; // edx
  int m_nCursorX; // eax
  unsigned int mouseCapture; // eax
  KeyValues *v6; // eax
  KeyValues *v7; // eax
  KeyValues *v8; // eax
  KeyValues *v9; // eax

  m_hContext = this->m_hContext;
  if ( m_hContext == -1 )
    p_m_DefaultInputContext = (UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *)&this->m_DefaultInputContext;
  else
    p_m_DefaultInputContext = &this->m_Contexts.m_Memory.m_pMemory[m_hContext];
  if ( p_m_DefaultInputContext->m_Element.m_bSetCursorExplicitly )
  {
    m_nExternallySetCursorY = p_m_DefaultInputContext->m_Element.m_nExternallySetCursorY;
    p_m_DefaultInputContext->m_Element.m_nCursorX = p_m_DefaultInputContext->m_Element.m_nExternallySetCursorX;
    p_m_DefaultInputContext->m_Element.m_nCursorY = m_nExternallySetCursorY;
  }
  m_nCursorX = p_m_DefaultInputContext->m_Element.m_nCursorX;
  if ( p_m_DefaultInputContext->m_Element.m_nLastPostedCursorX != m_nCursorX
    || p_m_DefaultInputContext->m_Element.m_nLastPostedCursorY != p_m_DefaultInputContext->m_Element.m_nCursorY )
  {
    p_m_DefaultInputContext->m_Element.m_nLastPostedCursorX = m_nCursorX;
    p_m_DefaultInputContext->m_Element.m_nLastPostedCursorY = p_m_DefaultInputContext->m_Element.m_nCursorY;
    mouseCapture = (unsigned int)p_m_DefaultInputContext->m_Element._mouseCapture;
    if ( mouseCapture != 0 )
    {
      if ( this->IsChildOfModalPanel(this, a2: mouseCapture, a3: true) )
      {
        v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v6 != nullptr )
          v7 = KeyValues::KeyValues(
                 this: v6,
                 setName: "CursorMoved",
                 firstKey: "xpos",
                 firstValue: p_m_DefaultInputContext->m_Element.m_nCursorX,
                 secondKey: "ypos",
                 secondValue: p_m_DefaultInputContext->m_Element.m_nCursorY);
        else
          v7 = nullptr;
        ((void (__stdcall *)(vgui::VPanel *, KeyValues *, _DWORD, _DWORD))vgui::g_pIVgui->PostMessageA)(
          a1: p_m_DefaultInputContext->m_Element._mouseCapture,
          a2: v7,
          a3: 0,
          a4: 0);
      }
    }
    else if ( p_m_DefaultInputContext->m_Element._mouseFocus != nullptr )
    {
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
        v9 = KeyValues::KeyValues(
               this: v8,
               setName: "CursorMoved",
               firstKey: "xpos",
               firstValue: p_m_DefaultInputContext->m_Element.m_nCursorX,
               secondKey: "ypos",
               secondValue: p_m_DefaultInputContext->m_Element.m_nCursorY);
      else
        v9 = nullptr;
      ((void (__stdcall *)(vgui::VPanel *, KeyValues *, _DWORD, _DWORD))vgui::g_pIVgui->PostMessageA)(
        a1: p_m_DefaultInputContext->m_Element._mouseFocus,
        a2: v9,
        a3: 0,
        a4: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003AE0
// Name: public: virtual bool CInputWin32::InternalMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CInputWin32::InternalMousePressed(CInputWin32 *this, int code)
{
  CInputWin32 *v2; // edi
  int m_hContext; // esi
  UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *p_m_DefaultInputContext; // esi
  unsigned int mouseCapture; // eax
  unsigned int mouseOver; // ebx
  ButtonCode_t m_MouseCaptureStartCode; // eax
  KeyValues *v9; // eax
  KeyValues *v10; // eax
  vgui::VPanel *mouseFocus; // eax
  KeyValues *v13; // eax
  KeyValues *v14; // eax
  KeyValues *v15; // eax
  KeyValues *v16; // edi
  int v17; // eax
  vgui::VPanel *MouseFocusIgnoringModalSubtree; // eax
  KeyValues *v19; // eax
  KeyValues *v20; // eax
  bool bFilter; // [esp+1Fh] [ebp-1h]
  char captureLost_3; // [esp+2Bh] [ebp+Bh]

  v2 = this;
  m_hContext = this->m_hContext;
  bFilter = false;
  if ( m_hContext == -1 )
    p_m_DefaultInputContext = (UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *)&this->m_DefaultInputContext;
  else
    p_m_DefaultInputContext = &this->m_Contexts.m_Memory.m_pMemory[m_hContext];
  mouseCapture = (unsigned int)p_m_DefaultInputContext->m_Element._mouseCapture;
  mouseOver = (unsigned int)p_m_DefaultInputContext->m_Element._mouseOver;
  if ( mouseCapture != 0 && this->IsChildOfModalPanel(this, a2: mouseCapture, a3: true) )
  {
    if ( code != 113 && code != 112 )
    {
      m_MouseCaptureStartCode = p_m_DefaultInputContext->m_Element.m_MouseCaptureStartCode;
      bFilter = true;
      if ( code == m_MouseCaptureStartCode || (captureLost_3 = 0, m_MouseCaptureStartCode == BUTTON_CODE_INVALID) )
        captureLost_3 = 1;
      v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v9 != nullptr )
        v10 = KeyValues::KeyValues(this: v9, setName: "MousePressed", firstKey: "code", firstValue: code);
      else
        v10 = nullptr;
      ((void (__stdcall *)(vgui::VPanel *, KeyValues *, _DWORD, _DWORD))vgui::g_pIVgui->PostMessageA)(
        a1: p_m_DefaultInputContext->m_Element._mouseCapture,
        a2: v10,
        a3: 0,
        a4: 0);
      mouseOver = (unsigned int)p_m_DefaultInputContext->m_Element._mouseCapture;
      if ( captureLost_3 != 0 )
        v2->SetMouseCapture(this: v2, a2: 0);
      goto LABEL_32;
    }
    return 1;
  }
  mouseFocus = p_m_DefaultInputContext->m_Element._mouseFocus;
  if ( mouseFocus != nullptr && v2->IsChildOfModalPanel(this: v2, a2: (unsigned int)mouseFocus, a3: true) )
  {
    if ( code != 113 && code != 112 )
    {
      v13 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v13 != nullptr )
        v14 = KeyValues::KeyValues(this: v13, setName: "MousePressed", firstKey: "code", firstValue: code);
      else
        v14 = nullptr;
      ((void (__stdcall *)(vgui::VPanel *, KeyValues *, _DWORD, _DWORD))vgui::g_pIVgui->PostMessageA)(
        a1: p_m_DefaultInputContext->m_Element._mouseFocus,
        a2: v14,
        a3: 0,
        a4: 0);
      mouseOver = (unsigned int)p_m_DefaultInputContext->m_Element._mouseFocus;
      bFilter = true;
      v15 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v15 != nullptr )
        v16 = KeyValues::KeyValues(
                this: v15,
                setName: "InputControlState",
                firstKey: "event",
                firstValue: "mousepressed");
      else
        v16 = nullptr;
      v17 = (int)p_m_DefaultInputContext->m_Element._mouseFocus->Client(this: p_m_DefaultInputContext->m_Element._mouseFocus);
      if ( (*(unsigned __int8 (__thiscall **)(int, KeyValues *))(*(_DWORD *)v17 + 44))(a1: v17, a2: v16) != 0 )
        bFilter = KeyValues::GetInt(this: v16, keyName: "passthrough", defaultValue: 0) == 0;
      if ( v16 != nullptr )
        KeyValues::deleteThis(this: v16);
      v2 = this;
      goto LABEL_32;
    }
    return 1;
  }
  if ( p_m_DefaultInputContext->m_Element.m_pModalSubTree != nullptr
    && p_m_DefaultInputContext->m_Element.m_pUnhandledMouseClickListener != nullptr )
  {
    MouseFocusIgnoringModalSubtree = CInputWin32::GetMouseFocusIgnoringModalSubtree(this: v2);
    if ( MouseFocusIgnoringModalSubtree != nullptr
      && !p_m_DefaultInputContext->m_Element.m_bRestrictMessagesToModalSubTree != CInputWin32::IsChildOfModalSubTree(
                                                                                    this: v2,
                                                                                    panel: (unsigned int)MouseFocusIgnoringModalSubtree) )
    {
      if ( code == 113 || code == 112 )
        return 1;
      v19 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v19 != nullptr )
        v20 = KeyValues::KeyValues(this: v19, setName: "UnhandledMouseClick", firstKey: "code", firstValue: code);
      else
        v20 = nullptr;
      ((void (__stdcall *)(vgui::VPanel *, KeyValues *, _DWORD, _DWORD))vgui::g_pIVgui->PostMessageA)(
        a1: p_m_DefaultInputContext->m_Element.m_pUnhandledMouseClickListener,
        a2: v20,
        a3: 0,
        a4: 0);
      mouseOver = (unsigned int)p_m_DefaultInputContext->m_Element.m_pUnhandledMouseClickListener;
      bFilter = true;
    }
  }
LABEL_32:
  if ( v2->IsChildOfModalPanel(this: v2, a2: mouseOver, a3: true) )
    vgui::g_pSurface->SetTopLevelFocus(this: vgui::g_pSurface, a2: mouseOver);
  return bFilter;
}

//------------------------------------------------------------------------------
// Address: 0x10003D90
// Name: public: virtual bool CInputWin32::InternalMouseDoublePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CInputWin32::InternalMouseDoublePressed(CInputWin32 *this, ButtonCode_t code)
{
  CInputWin32 *v2; // ebx
  int m_hContext; // esi
  UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *p_m_DefaultInputContext; // esi
  unsigned int mouseCapture; // eax
  unsigned int mouseOver; // edi
  KeyValues *v7; // eax
  KeyValues *v8; // eax
  vgui::VPanel *mouseFocus; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // eax
  KeyValues *v13; // eax
  KeyValues *v14; // ebx
  int v15; // eax
  bool bFilter; // [esp+1Fh] [ebp-1h]

  v2 = this;
  m_hContext = this->m_hContext;
  bFilter = false;
  if ( m_hContext == -1 )
    p_m_DefaultInputContext = (UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *)&this->m_DefaultInputContext;
  else
    p_m_DefaultInputContext = &this->m_Contexts.m_Memory.m_pMemory[m_hContext];
  mouseCapture = (unsigned int)p_m_DefaultInputContext->m_Element._mouseCapture;
  mouseOver = (unsigned int)p_m_DefaultInputContext->m_Element._mouseOver;
  if ( mouseCapture != 0 && this->IsChildOfModalPanel(this, a2: mouseCapture, a3: true) )
  {
    if ( code != MOUSE_WHEEL_DOWN && code != MOUSE_WHEEL_UP )
    {
      v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v7 != nullptr )
        v8 = KeyValues::KeyValues(this: v7, setName: "MouseDoublePressed", firstKey: "code", firstValue: code);
      else
        v8 = nullptr;
      ((void (__stdcall *)(vgui::VPanel *, KeyValues *, _DWORD, _DWORD))vgui::g_pIVgui->PostMessageA)(
        a1: p_m_DefaultInputContext->m_Element._mouseCapture,
        a2: v8,
        a3: 0,
        a4: 0);
      mouseOver = (unsigned int)p_m_DefaultInputContext->m_Element._mouseCapture;
      bFilter = true;
      goto LABEL_28;
    }
    return 1;
  }
  mouseFocus = p_m_DefaultInputContext->m_Element._mouseFocus;
  if ( mouseFocus != nullptr && v2->IsChildOfModalPanel(this: v2, a2: (unsigned int)mouseFocus, a3: true) )
  {
    if ( code != MOUSE_WHEEL_DOWN && code != MOUSE_WHEEL_UP )
    {
      v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v11 != nullptr )
        v12 = KeyValues::KeyValues(this: v11, setName: "MouseDoublePressed", firstKey: "code", firstValue: code);
      else
        v12 = nullptr;
      ((void (__stdcall *)(vgui::VPanel *, KeyValues *, _DWORD, _DWORD))vgui::g_pIVgui->PostMessageA)(
        a1: p_m_DefaultInputContext->m_Element._mouseFocus,
        a2: v12,
        a3: 0,
        a4: 0);
      mouseOver = (unsigned int)p_m_DefaultInputContext->m_Element._mouseFocus;
      bFilter = true;
      v13 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v13 != nullptr )
        v14 = KeyValues::KeyValues(
                this: v13,
                setName: "InputControlState",
                firstKey: "event",
                firstValue: "mousepressed");
      else
        v14 = nullptr;
      v15 = (int)p_m_DefaultInputContext->m_Element._mouseFocus->Client(this: p_m_DefaultInputContext->m_Element._mouseFocus);
      if ( (*(unsigned __int8 (__thiscall **)(int, KeyValues *))(*(_DWORD *)v15 + 44))(a1: v15, a2: v14) != 0 )
        bFilter = KeyValues::GetInt(this: v14, keyName: "passthrough", defaultValue: 0) == 0;
      if ( v14 != nullptr )
        KeyValues::deleteThis(this: v14);
      v2 = this;
      goto LABEL_28;
    }
    return 1;
  }
LABEL_28:
  if ( v2->IsChildOfModalPanel(this: v2, a2: mouseOver, a3: true) )
    vgui::g_pSurface->SetTopLevelFocus(this: vgui::g_pSurface, a2: mouseOver);
  return bFilter;
}

//------------------------------------------------------------------------------
// Address: 0x10003F70
// Name: public: virtual bool CInputWin32::InternalMouseReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CInputWin32::InternalMouseReleased(CInputWin32 *this, ButtonCode_t code)
{
  int m_hContext; // eax
  bool v4; // bl
  UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *p_m_DefaultInputContext; // edi
  unsigned int mouseCapture; // eax
  KeyValues *v7; // eax
  KeyValues *v8; // eax
  unsigned int mouseFocus; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // eax
  KeyValues *v13; // eax
  KeyValues *v14; // esi
  int v15; // eax

  m_hContext = this->m_hContext;
  v4 = false;
  if ( m_hContext == -1 )
    p_m_DefaultInputContext = (UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *)&this->m_DefaultInputContext;
  else
    p_m_DefaultInputContext = &this->m_Contexts.m_Memory.m_pMemory[m_hContext];
  mouseCapture = (unsigned int)p_m_DefaultInputContext->m_Element._mouseCapture;
  if ( mouseCapture == 0 || !this->IsChildOfModalPanel(this, a2: mouseCapture, a3: true) )
  {
    mouseFocus = (unsigned int)p_m_DefaultInputContext->m_Element._mouseFocus;
    if ( mouseFocus != 0 && this->IsChildOfModalPanel(this, a2: mouseFocus, a3: true) )
    {
      if ( code == MOUSE_WHEEL_DOWN || code == MOUSE_WHEEL_UP )
        return 1;
      v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v11 != nullptr )
        v12 = KeyValues::KeyValues(this: v11, setName: "MouseReleased", firstKey: "code", firstValue: code);
      else
        v12 = nullptr;
      ((void (__stdcall *)(vgui::VPanel *, KeyValues *, _DWORD, _DWORD))vgui::g_pIVgui->PostMessageA)(
        a1: p_m_DefaultInputContext->m_Element._mouseFocus,
        a2: v12,
        a3: 0,
        a4: 0);
      v4 = true;
      v13 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v13 != nullptr )
        v14 = KeyValues::KeyValues(
                this: v13,
                setName: "InputControlState",
                firstKey: "event",
                firstValue: "mousepressed");
      else
        v14 = nullptr;
      v15 = (int)p_m_DefaultInputContext->m_Element._mouseFocus->Client(this: p_m_DefaultInputContext->m_Element._mouseFocus);
      if ( (*(unsigned __int8 (__thiscall **)(int, KeyValues *))(*(_DWORD *)v15 + 44))(a1: v15, a2: v14) != 0 )
        v4 = KeyValues::GetInt(this: v14, keyName: "passthrough", defaultValue: 0) == 0;
      if ( v14 != nullptr )
        KeyValues::deleteThis(this: v14);
    }
    return v4;
  }
  if ( code == MOUSE_WHEEL_DOWN || code == MOUSE_WHEEL_UP )
    return 1;
  v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v7 != nullptr )
    v8 = KeyValues::KeyValues(this: v7, setName: "MouseReleased", firstKey: "code", firstValue: code);
  else
    v8 = nullptr;
  ((void (__stdcall *)(vgui::VPanel *, KeyValues *, _DWORD, _DWORD))vgui::g_pIVgui->PostMessageA)(
    a1: p_m_DefaultInputContext->m_Element._mouseCapture,
    a2: v8,
    a3: 0,
    a4: 0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10004110
// Name: public: virtual bool CInputWin32::InternalMouseWheeled(int)
// Source: json
//------------------------------------------------------------------------------
bool __userpurge CInputWin32::InternalMouseWheeled@<al>(CInputWin32 *this@<ecx>, int a2@<esi>, int delta)
{
  int m_hContext; // eax
  UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *p_m_DefaultInputContext; // edi
  unsigned int mouseFocus; // eax
  KeyValues *v6; // eax
  KeyValues *v7; // eax
  bool v8; // bl
  KeyValues *v9; // eax
  KeyValues *v10; // esi
  int v11; // eax

  m_hContext = this->m_hContext;
  if ( m_hContext == -1 )
    p_m_DefaultInputContext = (UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *)&this->m_DefaultInputContext;
  else
    p_m_DefaultInputContext = &this->m_Contexts.m_Memory.m_pMemory[m_hContext];
  mouseFocus = (unsigned int)p_m_DefaultInputContext->m_Element._mouseFocus;
  if ( mouseFocus == 0 || !this->IsChildOfModalPanel(this, a2: mouseFocus, a3: true) )
    return false;
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(this: v6, setName: "MouseWheeled", firstKey: "delta", firstValue: delta);
  else
    v7 = nullptr;
  ((void (__stdcall *)(vgui::VPanel *, KeyValues *, _DWORD, _DWORD, int))vgui::g_pIVgui->PostMessageA)(
    a1: p_m_DefaultInputContext->m_Element._mouseFocus,
    a2: v7,
    a3: 0,
    a4: 0,
    a5: a2);
  v8 = true;
  v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v9 != nullptr )
    v10 = KeyValues::KeyValues(this: v9, setName: "InputControlState", firstKey: "event", firstValue: "mousepressed");
  else
    v10 = nullptr;
  v11 = (int)p_m_DefaultInputContext->m_Element._mouseFocus->Client(this: p_m_DefaultInputContext->m_Element._mouseFocus);
  if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v11 + 44))(a1: v11) != 0 )
    v8 = KeyValues::GetInt(this: v10, keyName: "passthrough", defaultValue: 0) == 0;
  if ( v10 != nullptr )
    KeyValues::deleteThis(this: v10);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x10004220
// Name: public: virtual void CInputWin32::SetMouseCodeState(enum ButtonCode_t,enum vgui::MouseCodeState_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputWin32::SetMouseCodeState(CInputWin32 *this, ButtonCode_t code, vgui::MouseCodeState_t state)
{
  int m_hContext; // eax
  UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *p_m_DefaultInputContext; // eax

  if ( (unsigned int)(code - 107) <= 6 )
  {
    m_hContext = this->m_hContext;
    if ( m_hContext == -1 )
      p_m_DefaultInputContext = (UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *)&this->m_DefaultInputContext;
    else
      p_m_DefaultInputContext = &this->m_Contexts.m_Memory.m_pMemory[m_hContext];
    if ( state != BUTTON_RELEASED )
    {
      if ( state == BUTTON_PRESSED )
      {
        *((_BYTE *)p_m_DefaultInputContext + code - 103) = 1;
        *((_BYTE *)p_m_DefaultInputContext + code - 89) = 1;
        return;
      }
      if ( state == BUTTON_DOUBLECLICKED )
      {
        *((_BYTE *)p_m_DefaultInputContext + code - 96) = 1;
        *((_BYTE *)p_m_DefaultInputContext + code - 89) = 1;
        return;
      }
    }
    else
    {
      *((_BYTE *)p_m_DefaultInputContext + code - 82) = 1;
    }
    *((_BYTE *)p_m_DefaultInputContext + code - 89) = state != BUTTON_RELEASED;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100042A0
// Name: public: virtual void CInputWin32::SetKeyCodeState(enum ButtonCode_t,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputWin32::SetKeyCodeState(CInputWin32 *this, ButtonCode_t code, bool bPressed)
{
  int m_hContext; // eax
  UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *p_m_DefaultInputContext; // eax

  if ( (unsigned int)code <= KEY_SCROLLLOCKTOGGLE )
  {
    m_hContext = this->m_hContext;
    if ( m_hContext == -1 )
      p_m_DefaultInputContext = (UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *)&this->m_DefaultInputContext;
    else
      p_m_DefaultInputContext = &this->m_Contexts.m_Memory.m_pMemory[m_hContext];
    if ( bPressed )
    {
      p_m_DefaultInputContext->m_Element._keyPressed[code] = true;
      p_m_DefaultInputContext->m_Element._keyDown[code] = bPressed;
    }
    else
    {
      p_m_DefaultInputContext->m_Element._keyReleased[code] = true;
      p_m_DefaultInputContext->m_Element._keyDown[code] = false;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004300
// Name: private: bool CInputWin32::PostKeyMessage(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CInputWin32::PostKeyMessage(CInputWin32 *this, KeyValues *message)
{
  int m_hContext; // eax
  UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *p_m_DefaultInputContext; // esi
  unsigned int keyFocus; // eax

  m_hContext = this->m_hContext;
  if ( m_hContext == -1 )
    p_m_DefaultInputContext = (UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *)&this->m_DefaultInputContext;
  else
    p_m_DefaultInputContext = &this->m_Contexts.m_Memory.m_pMemory[m_hContext];
  keyFocus = (unsigned int)p_m_DefaultInputContext->m_Element._keyFocus;
  if ( keyFocus != 0 && this->IsChildOfModalPanel(this, a2: keyFocus, a3: true) )
  {
    ((void (__stdcall *)(vgui::VPanel *, KeyValues *, _DWORD, _DWORD))vgui::g_pIVgui->PostMessageA)(
      a1: p_m_DefaultInputContext->m_Element._keyFocus,
      a2: message,
      a3: 0,
      a4: 0);
    return 1;
  }
  else
  {
    KeyValues::deleteThis(this: message);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004380
// Name: public: virtual unsigned int CInputWin32::GetAppModalSurface(void)
// Source: json
//------------------------------------------------------------------------------
vgui::VPanel *__thiscall CInputWin32::GetAppModalSurface(CInputWin32 *this)
{
  int m_hContext; // eax

  m_hContext = this->m_hContext;
  if ( m_hContext == -1 )
    return this->m_DefaultInputContext._appModalPanel;
  else
    return this->m_Contexts.m_Memory.m_pMemory[m_hContext].m_Element._appModalPanel;
}

//------------------------------------------------------------------------------
// Address: 0x100043B0
// Name: public: virtual void CInputWin32::SetAppModalSurface(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputWin32::SetAppModalSurface(CInputWin32 *this, vgui::VPanel *panel)
{
  int m_hContext; // eax

  m_hContext = this->m_hContext;
  if ( m_hContext == -1 )
    this->m_DefaultInputContext._appModalPanel = panel;
  else
    this->m_Contexts.m_Memory.m_pMemory[m_hContext].m_Element._appModalPanel = panel;
}

//------------------------------------------------------------------------------
// Address: 0x100043F0
// Name: public: virtual void CInputWin32::ReleaseAppModalSurface(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputWin32::ReleaseAppModalSurface(CInputWin32 *this)
{
  int m_hContext; // eax

  m_hContext = this->m_hContext;
  if ( m_hContext == -1 )
    this->m_DefaultInputContext._appModalPanel = nullptr;
  else
    this->m_Contexts.m_Memory.m_pMemory[m_hContext].m_Element._appModalPanel = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10004420
// Name: public: virtual void CInputWin32::OnIMEEndComposition(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputWin32::OnIMEEndComposition(CInputWin32 *this)
{
  int m_hContext; // eax
  UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *p_m_DefaultInputContext; // eax
  KeyValues *v4; // eax
  KeyValues *v5; // eax

  m_hContext = this->m_hContext;
  if ( m_hContext == -1 )
    p_m_DefaultInputContext = (UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *)&this->m_DefaultInputContext;
  else
    p_m_DefaultInputContext = &this->m_Contexts.m_Memory.m_pMemory[m_hContext];
  if ( p_m_DefaultInputContext != nullptr )
  {
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
    {
      v5 = KeyValues::KeyValues(
             this: v4,
             setName: "DoCompositionString",
             firstKey: "string",
             firstValue: &word_1003DE18);
      CInputWin32::PostKeyMessage(this, message: v5);
    }
    else
    {
      CInputWin32::PostKeyMessage(this, message: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004480
// Name: private: void CInputWin32::InternalSetCompositionString(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputWin32::InternalSetCompositionString(CInputWin32 *this, const wchar_t *compstr)
{
  int m_hContext; // eax
  UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *p_m_DefaultInputContext; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  m_hContext = this->m_hContext;
  if ( m_hContext == -1 )
    p_m_DefaultInputContext = (UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *)&this->m_DefaultInputContext;
  else
    p_m_DefaultInputContext = &this->m_Contexts.m_Memory.m_pMemory[m_hContext];
  if ( p_m_DefaultInputContext != nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
    {
      v6 = KeyValues::KeyValues(this: v5, setName: "DoCompositionString", firstKey: "string", firstValue: compstr);
      CInputWin32::PostKeyMessage(this, message: v6);
    }
    else
    {
      CInputWin32::PostKeyMessage(this, message: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100044F0
// Name: public: virtual void CInputWin32::OnKeyCodeUnhandled(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputWin32::OnKeyCodeUnhandled(CInputWin32 *this, int keyCode)
{
  int m_hContext; // eax
  CInputWin32::InputContext_t *p_m_DefaultInputContext; // ecx
  int m_Size; // ebx
  int v5; // esi
  vgui::VPanel *v6; // edi
  KeyValues *v7; // eax
  KeyValues *v8; // eax
  UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *pContext; // [esp+10h] [ebp-4h]

  m_hContext = this->m_hContext;
  if ( m_hContext == -1 )
  {
    p_m_DefaultInputContext = &this->m_DefaultInputContext;
    pContext = (UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *)p_m_DefaultInputContext;
  }
  else
  {
    pContext = &this->m_Contexts.m_Memory.m_pMemory[m_hContext];
    p_m_DefaultInputContext = &pContext->m_Element;
  }
  if ( p_m_DefaultInputContext != nullptr )
  {
    m_Size = p_m_DefaultInputContext->m_KeyCodeUnhandledListeners.m_Size;
    v5 = 0;
    if ( m_Size > 0 )
    {
      while ( 1 )
      {
        v6 = p_m_DefaultInputContext->m_KeyCodeUnhandledListeners.m_Memory.m_pMemory[v5];
        v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        v8 = v7 != nullptr
           ? KeyValues::KeyValues(this: v7, setName: "KeyCodeUnhandled", firstKey: "code", firstValue: keyCode)
           : nullptr;
        ((void (__thiscall *)(vgui::IVGui *, vgui::VPanel *, KeyValues *, _DWORD, _DWORD))vgui::g_pIVgui->PostMessageA)(
          a1: vgui::g_pIVgui,
          a2: v6,
          a3: v8,
          a4: 0,
          a5: 0);
        if ( ++v5 >= m_Size )
          break;
        p_m_DefaultInputContext = &pContext->m_Element;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004590
// Name: private: void CInputWin32::PostModalSubTreeMessage(class vgui::VPanel __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputWin32::PostModalSubTreeMessage(CInputWin32 *this, vgui::VPanel *subTree, bool state)
{
  int m_hContext; // eax
  UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *p_m_DefaultInputContext; // esi
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  m_hContext = this->m_hContext;
  if ( m_hContext == -1 )
    p_m_DefaultInputContext = (UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *)&this->m_DefaultInputContext;
  else
    p_m_DefaultInputContext = &this->m_Contexts.m_Memory.m_pMemory[m_hContext];
  if ( p_m_DefaultInputContext->m_Element.m_pModalSubTree != nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "ModalSubTree", firstKey: "state", firstValue: state);
    else
      v6 = nullptr;
    ((void (__stdcall *)(vgui::VPanel *, KeyValues *, _DWORD, _DWORD))vgui::g_pIVgui->PostMessageA)(
      a1: p_m_DefaultInputContext->m_Element.m_pModalSubTree,
      a2: v6,
      a3: 0,
      a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004610
// Name: public: virtual void CInputWin32::SetModalSubTree(unsigned int,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputWin32::SetModalSubTree(
        CInputWin32 *this,
        vgui::VPanel *subTree,
        vgui::VPanel *unhandledMouseClickListener,
        bool restrictMessagesToSubTree)
{
  int m_hContext; // eax
  UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *p_m_DefaultInputContext; // esi
  vgui::VPanel *m_pModalSubTree; // eax

  m_hContext = this->m_hContext;
  if ( m_hContext == -1 )
    p_m_DefaultInputContext = (UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *)&this->m_DefaultInputContext;
  else
    p_m_DefaultInputContext = &this->m_Contexts.m_Memory.m_pMemory[m_hContext];
  if ( p_m_DefaultInputContext != nullptr )
  {
    m_pModalSubTree = p_m_DefaultInputContext->m_Element.m_pModalSubTree;
    if ( m_pModalSubTree != nullptr && m_pModalSubTree != subTree )
      this->ReleaseModalSubTree(this);
    if ( subTree != nullptr )
    {
      p_m_DefaultInputContext->m_Element.m_bRestrictMessagesToModalSubTree = restrictMessagesToSubTree;
      p_m_DefaultInputContext->m_Element.m_pModalSubTree = subTree;
      p_m_DefaultInputContext->m_Element.m_pUnhandledMouseClickListener = unhandledMouseClickListener;
      CInputWin32::PostModalSubTreeMessage(this, subTree, state: true);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004690
// Name: public: virtual void CInputWin32::ReleaseModalSubTree(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputWin32::ReleaseModalSubTree(CInputWin32 *this)
{
  int m_hContext; // eax
  UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *p_m_DefaultInputContext; // esi
  vgui::VPanel *m_pModalSubTree; // eax

  m_hContext = this->m_hContext;
  if ( m_hContext == -1 )
    p_m_DefaultInputContext = (UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *)&this->m_DefaultInputContext;
  else
    p_m_DefaultInputContext = &this->m_Contexts.m_Memory.m_pMemory[m_hContext];
  if ( p_m_DefaultInputContext != nullptr )
  {
    m_pModalSubTree = p_m_DefaultInputContext->m_Element.m_pModalSubTree;
    if ( m_pModalSubTree != nullptr )
      CInputWin32::PostModalSubTreeMessage(this, subTree: m_pModalSubTree, state: false);
    p_m_DefaultInputContext->m_Element.m_pModalSubTree = nullptr;
    p_m_DefaultInputContext->m_Element.m_pUnhandledMouseClickListener = nullptr;
    p_m_DefaultInputContext->m_Element.m_bRestrictMessagesToModalSubTree = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100046F0
// Name: public: virtual unsigned int CInputWin32::GetModalSubTree(void)
// Source: json
//------------------------------------------------------------------------------
UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *__thiscall CInputWin32::GetModalSubTree(CInputWin32 *this)
{
  int m_hContext; // eax
  UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *result; // eax

  m_hContext = this->m_hContext;
  if ( m_hContext == -1 )
    result = (UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *)&this->m_DefaultInputContext;
  else
    result = &this->m_Contexts.m_Memory.m_pMemory[m_hContext];
  if ( result != nullptr )
    return (UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *)result->m_Element.m_pModalSubTree;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10004720
// Name: public: virtual void CInputWin32::SetModalSubTreeReceiveMessages(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputWin32::SetModalSubTreeReceiveMessages(CInputWin32 *this, bool state)
{
  int m_hContext; // eax
  UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *p_m_DefaultInputContext; // eax

  m_hContext = this->m_hContext;
  if ( m_hContext == -1 )
    p_m_DefaultInputContext = (UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *)&this->m_DefaultInputContext;
  else
    p_m_DefaultInputContext = &this->m_Contexts.m_Memory.m_pMemory[m_hContext];
  if ( p_m_DefaultInputContext != nullptr && p_m_DefaultInputContext->m_Element.m_pModalSubTree != nullptr )
    p_m_DefaultInputContext->m_Element.m_bRestrictMessagesToModalSubTree = state;
}

//------------------------------------------------------------------------------
// Address: 0x10004760
// Name: public: virtual bool CInputWin32::ShouldModalSubTreeReceiveMessages(void)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CInputWin32::ShouldModalSubTreeReceiveMessages(CInputWin32 *this)
{
  int m_hContext; // eax
  UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *p_m_DefaultInputContext; // eax

  m_hContext = this->m_hContext;
  if ( m_hContext == -1 )
    p_m_DefaultInputContext = (UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *)&this->m_DefaultInputContext;
  else
    p_m_DefaultInputContext = &this->m_Contexts.m_Memory.m_pMemory[m_hContext];
  return p_m_DefaultInputContext == nullptr || p_m_DefaultInputContext->m_Element.m_bRestrictMessagesToModalSubTree;
}

//------------------------------------------------------------------------------
// Address: 0x100048D0
// Name: private: void CInputWin32::InitInputContext(struct CInputWin32::InputContext_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputWin32::InitInputContext(CInputWin32 *this, CInputWin32::InputContext_t *pContext)
{
  pContext->_rootPanel = 0;
  pContext->_keyFocus = nullptr;
  pContext->_oldMouseFocus = nullptr;
  pContext->_mouseFocus = nullptr;
  pContext->_mouseOver = nullptr;
  pContext->_mouseCapture = nullptr;
  pContext->_appModalPanel = nullptr;
  pContext->m_nCursorY = 0;
  pContext->m_nCursorX = 0;
  pContext->m_nExternallySetCursorY = 0;
  pContext->m_nExternallySetCursorX = 0;
  pContext->m_bSetCursorExplicitly = false;
  pContext->m_nLastPostedCursorY = -9999;
  pContext->m_nLastPostedCursorX = -9999;
  *(_DWORD *)pContext->_mousePressed = 0;
  *(_WORD *)&pContext->_mousePressed[4] = 0;
  pContext->_mousePressed[6] = false;
  *(_DWORD *)pContext->_mouseDoublePressed = 0;
  *(_WORD *)&pContext->_mouseDoublePressed[4] = 0;
  pContext->_mouseDoublePressed[6] = false;
  *(_DWORD *)pContext->_mouseDown = 0;
  *(_WORD *)&pContext->_mouseDown[4] = 0;
  pContext->_mouseDown[6] = false;
  *(_DWORD *)pContext->_mouseReleased = 0;
  *(_WORD *)&pContext->_mouseReleased[4] = 0;
  pContext->_mouseReleased[6] = false;
  memset(dst: (unsigned __int8 *)pContext->_keyPressed, value: 0, count: sizeof(pContext->_keyPressed));
  memset(dst: (unsigned __int8 *)pContext->_keyTyped, value: 0, count: sizeof(pContext->_keyTyped));
  memset(dst: (unsigned __int8 *)pContext->_keyDown, value: 0, count: sizeof(pContext->_keyDown));
  memset(dst: (unsigned __int8 *)pContext->_keyReleased, value: 0, count: sizeof(pContext->_keyReleased));
  pContext->m_MouseCaptureStartCode = BUTTON_CODE_INVALID;
  pContext->m_KeyCodeUnhandledListeners.m_Size = 0;
  pContext->m_pModalSubTree = nullptr;
  pContext->m_pUnhandledMouseClickListener = nullptr;
  pContext->m_bRestrictMessagesToModalSubTree = false;
}

//------------------------------------------------------------------------------
// Address: 0x100049D0
// Name: public: virtual void CInputWin32::ResetInputContext(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputWin32::ResetInputContext(CInputWin32 *this, int context)
{
  if ( context == -1 )
    CInputWin32::InitInputContext(this, pContext: &this->m_DefaultInputContext);
  else
    CInputWin32::InitInputContext(this, pContext: &this->m_Contexts.m_Memory.m_pMemory[context].m_Element);
}

//------------------------------------------------------------------------------
// Address: 0x10004A10
// Name: private: class vgui::VPanel __near * CInputWin32::CalculateNewKeyFocus(void)
// Source: json
//------------------------------------------------------------------------------
vgui::VPanel *__thiscall CInputWin32::CalculateNewKeyFocus(CInputWin32 *this)
{
  CInputWin32 *v1; // ebx
  int m_hContext; // eax
  UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *p_m_DefaultInputContext; // eax
  unsigned int rootPanel; // edi
  unsigned int v5; // esi
  int i; // ebx
  int v7; // edi
  int v8; // eax
  vgui::VPanel *pRoot; // [esp+8h] [ebp-Ch]
  vgui::VPanel *wantedKeyFocus; // [esp+Ch] [ebp-8h]

  v1 = this;
  m_hContext = this->m_hContext;
  if ( m_hContext == -1 )
    p_m_DefaultInputContext = (UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *)&this->m_DefaultInputContext;
  else
    p_m_DefaultInputContext = &this->m_Contexts.m_Memory.m_pMemory[m_hContext];
  rootPanel = p_m_DefaultInputContext->m_Element._rootPanel;
  wantedKeyFocus = nullptr;
  pRoot = (vgui::VPanel *)p_m_DefaultInputContext->m_Element._rootPanel;
  v5 = p_m_DefaultInputContext->m_Element._rootPanel;
  if ( vgui::g_pSurface->GetPopupCount(this: vgui::g_pSurface) > 0 )
  {
    for ( i = vgui::g_pSurface->GetPopupCount(this: vgui::g_pSurface); i != 0; v5 = rootPanel )
    {
      v5 = vgui::g_pSurface->GetPopup(this: vgui::g_pSurface, a2: --i);
      if ( v5 != 0
        && (*(unsigned __int8 (__thiscall **)(unsigned int))(*(_DWORD *)v5 + 100))(a1: v5) != 0
        && (*(unsigned __int8 (__thiscall **)(unsigned int))(*(_DWORD *)v5 + 168))(a1: v5) != 0
        && !vgui::g_pSurface->IsMinimized(this: vgui::g_pSurface, a2: v5)
        && CInputWin32::IsChildOfModalSubTree(this, panel: v5) != 0
        && (rootPanel == 0
         || (*(unsigned __int8 (__thiscall **)(unsigned int, unsigned int))(*(_DWORD *)v5 + 136))(a1: v5, a2: rootPanel) != 0) )
      {
        v7 = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)v5 + 124))(a1: v5);
        if ( v7 != 0 )
        {
          while ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v7 + 100))(a1: v7) != 0 )
          {
            v7 = (*(int (__thiscall **)(int))(*(_DWORD *)v7 + 124))(a1: v7);
            if ( v7 == 0 )
              goto LABEL_16;
          }
        }
        else
        {
LABEL_16:
          if ( !vgui::g_pSurface->IsMinimized(this: vgui::g_pSurface, a2: v5) )
            break;
        }
        rootPanel = (unsigned int)pRoot;
      }
    }
    v1 = this;
  }
  if ( v5 != 0 )
  {
    v8 = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)v5 + 156))(a1: v5);
    wantedKeyFocus = (vgui::VPanel *)(*(int (__thiscall **)(int))(*(_DWORD *)v8 + 64))(a1: v8);
    if ( wantedKeyFocus == nullptr )
      wantedKeyFocus = (vgui::VPanel *)v5;
  }
  if ( !vgui::g_pSurface->HasFocus(this: vgui::g_pSurface) )
    wantedKeyFocus = nullptr;
  if ( v1->IsChildOfModalPanel(this: v1, a2: (unsigned int)wantedKeyFocus, a3: true) )
    return wantedKeyFocus;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10004BB0
// Name: public: virtual void CInputWin32::UpdateMouseFocus(int,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CInputWin32::UpdateMouseFocus(CInputWin32 *this@<ecx>, int a2@<ebx>, int a3@<esi>, int x, int y)
{
  CInputWin32 *v5; // edi
  int m_hContext; // ecx
  UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *p_m_DefaultInputContext; // eax
  unsigned int rootPanel; // esi
  char v9; // bl
  char v10; // al
  int v11; // eax
  bool v12; // al
  int v13; // eax
  unsigned int v14; // eax
  unsigned int v15; // edi
  int v16; // esi
  bool v17; // al
  char v18; // bl
  int v19; // eax
  unsigned int v20; // eax
  int v21; // eax
  int i; // [esp+4h] [ebp-10h]
  CInputWin32::InputContext_t *pContext; // [esp+8h] [ebp-Ch]
  CInputWin32 *v25; // [esp+Ch] [ebp-8h]
  vgui::VPanel *focus; // [esp+10h] [ebp-4h]

  v5 = this;
  m_hContext = this->m_hContext;
  v25 = v5;
  focus = nullptr;
  if ( m_hContext == -1 )
    p_m_DefaultInputContext = (UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *)&v5->m_DefaultInputContext;
  else
    p_m_DefaultInputContext = &v5->m_Contexts.m_Memory.m_pMemory[m_hContext];
  pContext = &p_m_DefaultInputContext->m_Element;
  if ( m_hContext == -1 )
  {
    if ( ((unsigned __int8 (__thiscall *)(vgui::ISurface *, int, int))vgui::g_pSurface->IsCursorVisible)(
           a1: vgui::g_pSurface,
           a2: a3,
           a3: a2) != 0
      && vgui::g_pSurface->IsWithin(this: vgui::g_pSurface, a2: x, a3: y) )
    {
      v13 = vgui::g_pSurface->GetPopupCount(this: vgui::g_pSurface) - 1;
      i = v13;
      if ( v13 < 0 )
      {
LABEL_24:
        v20 = vgui::g_pSurface->GetEmbeddedPanel(this: vgui::g_pSurface);
        v21 = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)v20 + 156))(a1: v20);
        focus = (vgui::VPanel *)(*(int (__thiscall **)(int, int, int, _DWORD))(*(_DWORD *)v21 + 20))(
                                  a1: v21,
                                  a2: x,
                                  a3: y,
                                  a4: 0);
        v12 = v5->IsChildOfModalPanel(this: v5, a2: (unsigned int)focus, a3: true);
        goto LABEL_27;
      }
      while ( 1 )
      {
        v14 = vgui::g_pSurface->GetPopup(this: vgui::g_pSurface, a2: v13);
        v15 = v14;
        v16 = v14;
        if ( (pContext->_rootPanel == 0
           || (*(unsigned __int8 (__thiscall **)(unsigned int, unsigned int))(*(_DWORD *)v14 + 136))(
                a1: v14,
                a2: pContext->_rootPanel) != 0)
          && (*(unsigned __int8 (__thiscall **)(unsigned int))(*(_DWORD *)v15 + 172))(a1: v15) != 0
          && CInputWin32::IsChildOfModalSubTree(this: v25, panel: v15) != 0 )
        {
          v17 = vgui::g_pSurface->IsMinimized(this: vgui::g_pSurface, a2: v15);
          v18 = !v17;
          if ( !v17 )
          {
            while ( v16 != 0 && (*(int (__thiscall **)(int))(*(_DWORD *)v16 + 124))(a1: v16) != 0 )
            {
              v18 = (*(int (__thiscall **)(int))(*(_DWORD *)v16 + 100))(a1: v16);
              v16 = (*(int (__thiscall **)(int))(*(_DWORD *)v16 + 124))(a1: v16);
              if ( v18 == 0 )
                goto LABEL_22;
            }
            if ( v18 != 0 )
            {
              v19 = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)v15 + 156))(a1: v15);
              focus = (vgui::VPanel *)(*(int (__thiscall **)(int, int, int, _DWORD))(*(_DWORD *)v19 + 20))(
                                        a1: v19,
                                        a2: x,
                                        a3: y,
                                        a4: 0);
              if ( focus != nullptr )
                break;
            }
          }
        }
LABEL_22:
        v13 = --i;
        if ( i < 0 )
        {
          v5 = v25;
          goto LABEL_24;
        }
      }
      v5 = v25;
    }
  }
  else
  {
    rootPanel = p_m_DefaultInputContext->m_Element._rootPanel;
    v9 = (*(int (__thiscall **)(unsigned int, int, int))(*(_DWORD *)p_m_DefaultInputContext->m_Element._rootPanel + 172))(
           a1: p_m_DefaultInputContext->m_Element._rootPanel,
           a2: a3,
           a3: a2);
    v10 = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)rootPanel + 100))(a1: rootPanel);
    if ( v9 != 0 && v10 != 0 )
    {
      v11 = (*(int (__thiscall **)(unsigned int))(*(_DWORD *)rootPanel + 156))(a1: rootPanel);
      focus = (vgui::VPanel *)(*(int (__thiscall **)(int, int, int, _DWORD))(*(_DWORD *)v11 + 20))(
                                a1: v11,
                                a2: x,
                                a3: y,
                                a4: 0);
      v12 = v5->IsChildOfModalPanel(this: v5, a2: (unsigned int)focus, a3: true);
      goto LABEL_27;
    }
  }
  v12 = v5->IsChildOfModalPanel(this: v5, a2: (unsigned int)focus, a3: true);
LABEL_27:
  if ( !v12 )
    focus = nullptr;
  v5->SetMouseFocus(this: v5, a2: (unsigned int)focus);
}

//------------------------------------------------------------------------------
// Address: 0x10004DE0
// Name: public: virtual unsigned int CInputWin32::GetCalculatedFocus(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
vgui::VPanel *__thiscall CInputWin32::GetCalculatedFocus(CInputWin32 *this)
{
  return CInputWin32::CalculateNewKeyFocus(this);
}

//------------------------------------------------------------------------------
// Address: 0x10004DF0
// Name: public: virtual bool CInputWin32::InternalKeyCodePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CInputWin32::InternalKeyCodePressed(CInputWin32 *this, ButtonCode_t code)
{
  int m_hContext; // eax
  UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *p_m_DefaultInputContext; // eax
  KeyValues *v6; // eax
  KeyValues *v7; // eax
  char v8; // bl
  CInputWin32::InputContext_t *pContext; // [esp+8h] [ebp-4h]

  m_hContext = this->m_hContext;
  if ( m_hContext == -1 )
    p_m_DefaultInputContext = (UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *)&this->m_DefaultInputContext;
  else
    p_m_DefaultInputContext = &this->m_Contexts.m_Memory.m_pMemory[m_hContext];
  pContext = &p_m_DefaultInputContext->m_Element;
  if ( (unsigned int)code > KEY_SCROLLLOCKTOGGLE && (unsigned int)(code - 114) > 0xBF )
    return 0;
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(this: v6, setName: "KeyCodePressed", firstKey: "code", firstValue: code);
  else
    v7 = nullptr;
  v8 = CInputWin32::PostKeyMessage(this, message: v7);
  if ( v8 != 0 )
    vgui::CKeyRepeatHandler::KeyDown(this: &pContext->m_keyRepeater, code);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x10004E90
// Name: public: virtual void CInputWin32::InternalKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputWin32::InternalKeyCodeTyped(CInputWin32 *this, ButtonCode_t code)
{
  int m_hContext; // eax
  UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *p_m_DefaultInputContext; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  m_hContext = this->m_hContext;
  if ( m_hContext == -1 )
    p_m_DefaultInputContext = (UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *)&this->m_DefaultInputContext;
  else
    p_m_DefaultInputContext = &this->m_Contexts.m_Memory.m_pMemory[m_hContext];
  if ( (unsigned int)code <= KEY_SCROLLLOCKTOGGLE || (unsigned int)(code - 114) <= 0xBF )
  {
    p_m_DefaultInputContext->m_Element._keyTyped[code] = true;
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
    {
      v6 = KeyValues::KeyValues(this: v5, setName: "KeyCodeTyped", firstKey: "code", firstValue: code);
      CInputWin32::PostKeyMessage(this, message: v6);
    }
    else
    {
      CInputWin32::PostKeyMessage(this, message: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004F10
// Name: public: virtual void CInputWin32::InternalKeyTyped(wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputWin32::InternalKeyTyped(CInputWin32 *this, wchar_t unichar)
{
  int m_hContext; // eax
  UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *p_m_DefaultInputContext; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  m_hContext = this->m_hContext;
  if ( m_hContext == -1 )
    p_m_DefaultInputContext = (UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *)&this->m_DefaultInputContext;
  else
    p_m_DefaultInputContext = &this->m_Contexts.m_Memory.m_pMemory[m_hContext];
  if ( unichar <= 0x6Au )
    p_m_DefaultInputContext->m_Element._keyTyped[unichar] = true;
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
  {
    v6 = KeyValues::KeyValues(this: v5, setName: "KeyTyped", firstKey: "unichar", firstValue: unichar);
    CInputWin32::PostKeyMessage(this, message: v6);
  }
  else
  {
    CInputWin32::PostKeyMessage(this, message: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004F90
// Name: public: virtual bool CInputWin32::InternalKeyCodeReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CInputWin32::InternalKeyCodeReleased(CInputWin32 *this, ButtonCode_t code)
{
  int m_hContext; // eax
  UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *p_m_DefaultInputContext; // eax
  KeyValues *v6; // eax
  KeyValues *v7; // eax

  m_hContext = this->m_hContext;
  if ( m_hContext == -1 )
    p_m_DefaultInputContext = (UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *)&this->m_DefaultInputContext;
  else
    p_m_DefaultInputContext = &this->m_Contexts.m_Memory.m_pMemory[m_hContext];
  if ( (unsigned int)code > KEY_SCROLLLOCKTOGGLE && (unsigned int)(code - 114) > 0xBF )
    return 0;
  vgui::CKeyRepeatHandler::KeyUp(this: &p_m_DefaultInputContext->m_Element.m_keyRepeater, code);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 == nullptr )
    return CInputWin32::PostKeyMessage(this, message: nullptr);
  v7 = KeyValues::KeyValues(this: v6, setName: "KeyCodeReleased", firstKey: "code", firstValue: code);
  return CInputWin32::PostKeyMessage(this, message: v7);
}

//------------------------------------------------------------------------------
// Address: 0x10005020
// Name: public: virtual void CInputWin32::OnIMEComposition(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputWin32::OnIMEComposition(CInputWin32 *this, __int16 flags)
{
  HWND v3; // eax
  HIMC__ *Context; // esi
  LONG CompositionStringW; // eax
  signed int v6; // ebx
  signed int v7; // esi
  LONG v8; // eax
  HWND v9; // eax
  wchar_t Buf[256]; // [esp+8h] [ebp-244h] BYREF
  wchar_t tempstr[32]; // [esp+208h] [ebp-44h] BYREF
  HIMC__ *hIMC; // [esp+248h] [ebp-4h]

  v3 = (HWND)this->GetIMEWindow(this);
  Context = ImmGetContext(a1: v3);
  hIMC = Context;
  if ( Context != nullptr )
  {
    if ( (flags & 0x800) != 0 )
    {
      CompositionStringW = ImmGetCompositionStringW(a1: Context, a2: 0x800u, lpBuf: tempstr, dwBufLen: 0x40u);
      if ( CompositionStringW > 0 )
      {
        if ( (CompositionStringW & 0x80000001) != 0 )
          ++CompositionStringW;
        v6 = (unsigned int)CompositionStringW >> 1;
        v7 = 0;
        if ( (unsigned int)CompositionStringW >> 1 != 0 )
        {
          do
            this->InternalKeyTyped(this, a2: tempstr[v7++]);
          while ( v7 < v6 );
        }
        Context = hIMC;
      }
    }
    if ( (flags & 8) != 0 )
    {
      v8 = ImmGetCompositionStringW(a1: Context, a2: 8u, lpBuf: Buf, dwBufLen: 0x200u);
      if ( v8 > 0 )
      {
        if ( (v8 & 0x80000001) != 0 )
          ++v8;
        Buf[(unsigned int)v8 >> 1] = 0;
        CInputWin32::InternalSetCompositionString(this, compstr: Buf);
      }
    }
    v9 = (HWND)this->GetIMEWindow(this);
    ImmReleaseContext(a1: v9, a2: Context);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005100
// Name: public: virtual void CInputWin32::OnIMEShowCandidates(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputWin32::OnIMEShowCandidates(CInputWin32 *this)
{
  int m_hContext; // eax
  UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *p_m_DefaultInputContext; // eax
  KeyValues *v4; // eax
  KeyValues *v5; // eax

  if ( this->_imeCandidates != nullptr )
  {
    free(pMem: this->_imeCandidates);
    this->_imeCandidates = nullptr;
  }
  CInputWin32::CreateNewCandidateList(this);
  m_hContext = this->m_hContext;
  if ( m_hContext == -1 )
    p_m_DefaultInputContext = (UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *)&this->m_DefaultInputContext;
  else
    p_m_DefaultInputContext = &this->m_Contexts.m_Memory.m_pMemory[m_hContext];
  if ( p_m_DefaultInputContext != nullptr )
  {
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
    {
      v5 = KeyValues::KeyValues(this: v4, setName: "DoShowIMECandidates");
      CInputWin32::PostKeyMessage(this, message: v5);
    }
    else
    {
      CInputWin32::PostKeyMessage(this, message: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005180
// Name: public: virtual void CInputWin32::OnIMECloseCandidates(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputWin32::OnIMECloseCandidates(CInputWin32 *this)
{
  int m_hContext; // eax
  UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *p_m_DefaultInputContext; // eax
  KeyValues *v4; // eax
  KeyValues *v5; // eax

  m_hContext = this->m_hContext;
  if ( m_hContext == -1 )
    p_m_DefaultInputContext = (UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *)&this->m_DefaultInputContext;
  else
    p_m_DefaultInputContext = &this->m_Contexts.m_Memory.m_pMemory[m_hContext];
  if ( p_m_DefaultInputContext != nullptr )
  {
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "DoHideIMECandidates");
    else
      v5 = nullptr;
    CInputWin32::PostKeyMessage(this, message: v5);
  }
  if ( this->_imeCandidates != nullptr )
  {
    free(pMem: this->_imeCandidates);
    this->_imeCandidates = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100051F0
// Name: public: virtual void CInputWin32::OnIMEChangeCandidates(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputWin32::OnIMEChangeCandidates(CInputWin32 *this)
{
  int m_hContext; // eax
  UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *p_m_DefaultInputContext; // eax
  KeyValues *v4; // eax
  KeyValues *v5; // eax

  if ( this->_imeCandidates != nullptr )
  {
    free(pMem: this->_imeCandidates);
    this->_imeCandidates = nullptr;
  }
  CInputWin32::CreateNewCandidateList(this);
  m_hContext = this->m_hContext;
  if ( m_hContext == -1 )
    p_m_DefaultInputContext = (UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *)&this->m_DefaultInputContext;
  else
    p_m_DefaultInputContext = &this->m_Contexts.m_Memory.m_pMemory[m_hContext];
  if ( p_m_DefaultInputContext != nullptr )
  {
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
    {
      v5 = KeyValues::KeyValues(this: v4, setName: "DoUpdateIMECandidates");
      CInputWin32::PostKeyMessage(this, message: v5);
    }
    else
    {
      CInputWin32::PostKeyMessage(this, message: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005300
// Name: public: virtual void CInputWin32::RunFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CInputWin32::RunFrame(CInputWin32 *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  CInputWin32 *v3; // esi
  int v4; // eax
  int m_hContext; // eax
  int p_m_DefaultInputContext; // ebx
  unsigned int v7; // eax
  KeyValues *v8; // eax
  KeyValues *v9; // eax
  unsigned int v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // eax
  _BYTE *v13; // eax
  int i; // ecx
  _BYTE *v15; // eax
  int j; // ecx
  vgui::VPanel *v17; // eax
  vgui::VPanel *v18; // ecx
  vgui::VPanel *v19; // edi
  int v20; // eax
  KeyValues *v21; // eax
  KeyValues *v22; // esi
  int v23; // ecx
  int v24; // eax
  int v25; // esi
  char v26; // al
  int v27; // edx
  int v28; // eax
  int v29; // eax
  KeyValues *v30; // eax
  KeyValues *v31; // esi
  int v32; // eax
  int v33; // esi
  char v34; // al
  int v35; // edx
  int v36; // eax
  const char *v37; // esi
  int v38; // ecx
  const char *v39; // eax
  int ModalPanel; // eax
  int v41; // [esp+28h] [ebp-10h]
  int v42; // [esp+2Ch] [ebp-Ch]

  v3 = this;
  if ( this->m_nDebugMessages == -1 )
  {
    v4 = _CommandLine();
    v3->m_nDebugMessages = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v4 + 40))(a1: v4, a2: "-vguifocus") != 0;
  }
  m_hContext = v3->m_hContext;
  v42 = a2;
  v41 = a3;
  if ( m_hContext == -1 )
    p_m_DefaultInputContext = (int)&v3->m_DefaultInputContext;
  else
    p_m_DefaultInputContext = (int)&v3->m_Contexts.m_Memory.m_pMemory[m_hContext];
  v7 = *(_DWORD *)(p_m_DefaultInputContext + 1260);
  if ( v7 != 0 && v3->IsChildOfModalPanel(this: v3, a2: v7, a3: true) )
  {
    v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v8 != nullptr )
      v9 = KeyValues::KeyValues(this: v8, setName: "KeyFocusTicked");
    else
      v9 = nullptr;
    ((void (__stdcall *)(_DWORD, KeyValues *, _DWORD, _DWORD))vgui::g_pIVgui->PostMessageA)(
      a1: *(_DWORD *)(p_m_DefaultInputContext + 1260),
      a2: v9,
      a3: 0,
      a4: 0);
  }
  v10 = *(_DWORD *)(p_m_DefaultInputContext + 1268);
  if ( v10 != 0 )
  {
    if ( v3->IsChildOfModalPanel(this: v3, a2: v10, a3: true) )
    {
      v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v11 != nullptr )
        v12 = KeyValues::KeyValues(this: v11, setName: "MouseFocusTicked");
      else
        v12 = nullptr;
      ((void (__stdcall *)(_DWORD, KeyValues *, _DWORD, _DWORD))vgui::g_pIVgui->PostMessageA)(
        a1: *(_DWORD *)(p_m_DefaultInputContext + 1268),
        a2: v12,
        a3: 0,
        a4: 0);
    }
  }
  else if ( *(_DWORD *)(p_m_DefaultInputContext + 1284) != 0 )
  {
    vgui::g_pSurface->SetCursor(this: vgui::g_pSurface, a2: 2u);
  }
  v13 = (_BYTE *)(p_m_DefaultInputContext + 11);
  for ( i = 7; i != 0; --i )
  {
    *(v13 - 7) = 0;
    *v13 = 0;
    v13[14] = 0;
    ++v13;
  }
  v15 = (_BYTE *)(p_m_DefaultInputContext + 339);
  for ( j = 307; j != 0; --j )
  {
    *(v15 - 307) = 0;
    *v15 = 0;
    v15[614] = 0;
    ++v15;
  }
  v17 = CInputWin32::CalculateNewKeyFocus(this: v3);
  v18 = *(vgui::VPanel **)(p_m_DefaultInputContext + 1260);
  v19 = v17;
  if ( v18 != v17 )
  {
    if ( v18 != nullptr )
    {
      v20 = ((int (__thiscall *)(vgui::VPanel *, int, int))v18->Client)(a1: v18, a2: v41, a3: v42);
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v20 + 40))(a1: v20, a2: 1);
      v21 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v21 != nullptr )
        v22 = KeyValues::KeyValues(this: v21, setName: "KillFocus");
      else
        v22 = nullptr;
      KeyValues::SetPtr(this: v22, keyName: "newPanel", value: v19);
      (*(void (__thiscall **)(_DWORD, KeyValues *, _DWORD))(**(_DWORD **)(p_m_DefaultInputContext + 1260) + 152))(
        a1: *(_DWORD *)(p_m_DefaultInputContext + 1260),
        a2: v22,
        a3: 0);
      if ( v22 != nullptr )
        KeyValues::deleteThis(this: v22);
      v23 = *(_DWORD *)(p_m_DefaultInputContext + 1260);
      if ( v23 != 0 )
      {
        v24 = (*(int (__thiscall **)(int))(*(_DWORD *)v23 + 156))(a1: v23);
        (*(void (__thiscall **)(int))(*(_DWORD *)v24 + 16))(a1: v24);
      }
      v25 = *(_DWORD *)(p_m_DefaultInputContext + 1260);
      if ( v25 != 0 )
      {
        while ( 1 )
        {
          v26 = (*(int (__thiscall **)(int))(*(_DWORD *)v25 + 28))(a1: v25);
          v27 = *(_DWORD *)v25;
          if ( v26 != 0 )
            break;
          v25 = (*(int (__thiscall **)(int))(v27 + 124))(a1: v25);
          if ( v25 == 0 )
            goto LABEL_38;
        }
        v28 = (*(int (__thiscall **)(int))(v27 + 156))(a1: v25);
        (*(void (__thiscall **)(int))(*(_DWORD *)v28 + 16))(a1: v28);
      }
LABEL_38:
      v3 = this;
    }
    if ( v19 != nullptr )
    {
      v29 = ((int (__thiscall *)(vgui::VPanel *, int, int))v19->Client)(a1: v19, a2: v41, a3: v42);
      (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v29 + 40))(a1: v29, a2: 0);
      v30 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v30 != nullptr )
        v31 = KeyValues::KeyValues(this: v30, setName: "SetFocus");
      else
        v31 = nullptr;
      v19->SendMessage(this: v19, a2: v31, a3: 0);
      if ( v31 != nullptr )
        KeyValues::deleteThis(this: v31);
      v32 = (int)v19->Client(this: v19);
      (*(void (__thiscall **)(int))(*(_DWORD *)v32 + 16))(a1: v32);
      v33 = (int)v19;
      while ( 1 )
      {
        v34 = (*(int (__thiscall **)(int))(*(_DWORD *)v33 + 28))(a1: v33);
        v35 = *(_DWORD *)v33;
        if ( v34 != 0 )
          break;
        v33 = (*(int (__thiscall **)(int))(v35 + 124))(a1: v33);
        if ( v33 == 0 )
          goto LABEL_50;
      }
      v36 = (*(int (__thiscall **)(int))(v35 + 156))(a1: v33);
      (*(void (__thiscall **)(int))(*(_DWORD *)v36 + 16))(a1: v36);
LABEL_50:
      v3 = this;
    }
    if ( v3->m_nDebugMessages > 0 )
    {
      if ( v19 != nullptr )
        v37 = v19->GetName(this: v19);
      else
        v37 = "(no name)";
      v38 = *(_DWORD *)(p_m_DefaultInputContext + 1260);
      if ( v38 != 0 )
        v39 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v38 + 140))(a1: v38);
      else
        v39 = "(no name)";
      vgui::g_pIVgui->DPrintf2(this: vgui::g_pIVgui, a2: "changing kb focus from %s to %s\n", v39, v37);
      v3 = this;
    }
    *(_DWORD *)(p_m_DefaultInputContext + 1260) = v19;
    if ( v19 != nullptr )
      v19->MoveToFront(this: v19);
  }
  ModalPanel = CWin32Surface::GetModalPanel(this: (ConVar *)(p_m_DefaultInputContext + 1348));
  if ( ModalPanel != 0 )
    v3->InternalKeyCodePressed(this: v3, a2: (ButtonCode_t)ModalPanel);
}

//------------------------------------------------------------------------------
// Address: 0x10005680
// Name: private: void CInputWin32::PanelDeleted(unsigned int,struct CInputWin32::InputContext_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputWin32::PanelDeleted(
        CInputWin32 *this,
        vgui::VPanel *vfocus,
        CInputWin32::InputContext_t *context)
{
  CInputWin32::InputContext_t *v3; // esi
  unsigned int v4; // edi
  vgui::VPanel *keyFocus; // ecx
  const char *v7; // eax

  v3 = context;
  v4 = (unsigned int)vfocus;
  keyFocus = context->_keyFocus;
  if ( keyFocus == vfocus )
  {
    if ( this->m_nDebugMessages > 0 )
    {
      if ( keyFocus != nullptr )
        v7 = keyFocus->GetName(this: keyFocus);
      else
        v7 = "(no name)";
      vgui::g_pIVgui->DPrintf2(this: vgui::g_pIVgui, a2: "removing kb focus %s\n", v7);
    }
    v3->_keyFocus = nullptr;
  }
  if ( v3->_mouseOver == (vgui::VPanel *)v4 )
    v3->_mouseOver = nullptr;
  if ( v3->_oldMouseFocus == (vgui::VPanel *)v4 )
    v3->_oldMouseFocus = nullptr;
  if ( v3->_mouseFocus == (vgui::VPanel *)v4 )
    v3->_mouseFocus = nullptr;
  if ( v3->_mouseCapture == (vgui::VPanel *)v4 )
  {
    this->SetMouseCapture(this, a2: 0);
    v3->_mouseCapture = nullptr;
  }
  if ( v3->_appModalPanel == (vgui::VPanel *)v4 )
    this->ReleaseAppModalSurface(this);
  if ( v3->m_pUnhandledMouseClickListener == (vgui::VPanel *)v4 )
    v3->m_pUnhandledMouseClickListener = nullptr;
  if ( v3->m_pModalSubTree == (vgui::VPanel *)v4 )
  {
    v3->m_pModalSubTree = nullptr;
    v3->m_bRestrictMessagesToModalSubTree = false;
  }
  CUtlVector<CChromeHTMLWindow *,CUtlMemory<CChromeHTMLWindow *,int>>::FindAndRemove(
    this: &v3->m_KeyCodeUnhandledListeners,
    src: &vfocus);
}

//------------------------------------------------------------------------------
// Address: 0x10005770
// Name: public: virtual void CInputWin32::PanelDeleted(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputWin32::PanelDeleted(CInputWin32 *this, vgui::VPanel *focus)
{
  CInputWin32 *v2; // edi
  int m_Head; // eax
  UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *m_pMemory; // esi
  vgui::VPanel *v5; // edx
  int v6; // ebx
  vgui::VPanel *keyFocus; // ecx
  UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *v8; // esi
  int v9; // eax
  const char *v10; // eax
  int m_Size; // ecx
  vgui::VPanel **v12; // edx
  int v13; // ecx

  v2 = this;
  m_Head = this->m_Contexts.m_Head;
  if ( m_Head == -1 )
  {
    v5 = focus;
  }
  else
  {
    do
    {
      m_pMemory = v2->m_Contexts.m_Memory.m_pMemory;
      v5 = focus;
      v6 = m_Head;
      keyFocus = m_pMemory[m_Head].m_Element._keyFocus;
      v8 = &m_pMemory[m_Head];
      v9 = 0;
      if ( keyFocus == focus )
      {
        if ( v2->m_nDebugMessages > 0 )
        {
          if ( keyFocus != nullptr )
            v10 = keyFocus->GetName(this: keyFocus);
          else
            v10 = "(no name)";
          vgui::g_pIVgui->DPrintf2(this: vgui::g_pIVgui, a2: "removing kb focus %s\n", v10);
          v5 = focus;
          v9 = 0;
        }
        v8->m_Element._keyFocus = nullptr;
      }
      if ( v8->m_Element._mouseOver == v5 )
        v8->m_Element._mouseOver = nullptr;
      if ( v8->m_Element._oldMouseFocus == v5 )
        v8->m_Element._oldMouseFocus = nullptr;
      if ( v8->m_Element._mouseFocus == v5 )
        v8->m_Element._mouseFocus = nullptr;
      if ( v8->m_Element._mouseCapture == v5 )
      {
        v2->SetMouseCapture(this: v2, a2: 0);
        v5 = focus;
        v8->m_Element._mouseCapture = nullptr;
        v9 = 0;
      }
      if ( v8->m_Element._appModalPanel == v5 )
      {
        v2->ReleaseAppModalSurface(this: v2);
        v5 = focus;
        v9 = 0;
      }
      if ( v8->m_Element.m_pUnhandledMouseClickListener == v5 )
        v8->m_Element.m_pUnhandledMouseClickListener = nullptr;
      if ( v8->m_Element.m_pModalSubTree == v5 )
      {
        v8->m_Element.m_pModalSubTree = nullptr;
        v8->m_Element.m_bRestrictMessagesToModalSubTree = false;
      }
      m_Size = v8->m_Element.m_KeyCodeUnhandledListeners.m_Size;
      if ( m_Size > 0 )
      {
        v12 = v8->m_Element.m_KeyCodeUnhandledListeners.m_Memory.m_pMemory;
        while ( *v12 != focus )
        {
          ++v9;
          ++v12;
          if ( v9 >= m_Size )
            goto LABEL_32;
        }
        if ( v9 != -1 )
        {
          v13 = m_Size - v9 - 1;
          if ( v13 > 0 )
            _V_memmove(
              dest: &v8->m_Element.m_KeyCodeUnhandledListeners.m_Memory.m_pMemory[v9],
              src: &v8->m_Element.m_KeyCodeUnhandledListeners.m_Memory.m_pMemory[v9 + 1],
              count: 4 * v13);
          --v8->m_Element.m_KeyCodeUnhandledListeners.m_Size;
        }
LABEL_32:
        v2 = this;
        v5 = focus;
      }
      m_Head = v2->m_Contexts.m_Memory.m_pMemory[v6].m_Next;
    }
    while ( m_Head != -1 );
  }
  CInputWin32::PanelDeleted(this: v2, vfocus: v5, context: &v2->m_DefaultInputContext);
}

//------------------------------------------------------------------------------
// Address: 0x10005900
// Name: public: virtual void CInputWin32::UnregisterKeyCodeUnhandledListener(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputWin32::UnregisterKeyCodeUnhandledListener(CInputWin32 *this, vgui::VPanel *panel)
{
  int m_hContext; // eax
  UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *p_m_DefaultInputContext; // eax

  if ( panel != nullptr )
  {
    m_hContext = this->m_hContext;
    if ( m_hContext == -1 )
      p_m_DefaultInputContext = (UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *)&this->m_DefaultInputContext;
    else
      p_m_DefaultInputContext = &this->m_Contexts.m_Memory.m_pMemory[m_hContext];
    if ( p_m_DefaultInputContext != nullptr )
      CUtlVector<CChromeHTMLWindow *,CUtlMemory<CChromeHTMLWindow *,int>>::FindAndRemove(
        this: &p_m_DefaultInputContext->m_Element.m_KeyCodeUnhandledListeners,
        src: &panel);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100059D0
// Name: public: virtual void CInputWin32::OnChangeIME(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputWin32::OnChangeIME(CInputWin32 *this, bool forward)
{
  unsigned int KeyboardLayoutList; // eax
  int v3; // edi
  HKL__ **v4; // esi
  int v5; // edi
  int m_nAllocationCount; // edx
  int m_Size; // ebx
  int v8; // eax
  int v9; // esi
  HKL__ **m_pMemory; // ecx
  HKL__ **v11; // esi
  HKL__ **v12; // edi
  CUtlVector<HKL__ *,CUtlMemory<HKL__ *,int> > selections; // [esp+8h] [ebp-24h] BYREF
  HKL__ *currentKb; // [esp+1Ch] [ebp-10h]
  unsigned int numKBs; // [esp+20h] [ebp-Ch]
  HKL__ **list; // [esp+24h] [ebp-8h]
  int oldKb; // [esp+28h] [ebp-4h]

  currentKb = GetKeyboardLayout(idThread: 0);
  KeyboardLayoutList = GetKeyboardLayoutList(nBuff: 0, lpList: nullptr);
  v3 = KeyboardLayoutList;
  numKBs = KeyboardLayoutList;
  if ( KeyboardLayoutList != 0 )
  {
    v4 = (HKL__ **)operator new(nSize: 4 * KeyboardLayoutList);
    list = v4;
    GetKeyboardLayoutList(nBuff: v3, lpList: v4);
    v5 = 0;
    m_nAllocationCount = 0;
    m_Size = 0;
    oldKb = 0;
    memset(&selections, 0, sizeof(selections));
    while ( 1 )
    {
      v8 = 0;
      if ( v5 <= 0 )
      {
LABEL_7:
        v9 = m_Size;
        if ( m_Size + 1 > m_nAllocationCount )
        {
          CUtlMemory<int,int>::Grow(
            this: (CUtlMemory<CWin32Font *,int> *)&selections,
            num: m_Size - m_nAllocationCount + 1);
          m_Size = selections.m_Size;
        }
        m_pMemory = selections.m_Memory.m_pMemory;
        selections.m_Size = ++m_Size;
        selections.m_pElements = selections.m_Memory.m_pMemory;
        if ( m_Size - v9 - 1 > 0 )
        {
          _V_memmove(
            dest: &selections.m_Memory.m_pMemory[v9 + 1],
            src: &selections.m_Memory.m_pMemory[v9],
            count: 4 * (m_Size - v9 - 1));
          m_pMemory = selections.m_Memory.m_pMemory;
        }
        v11 = &m_pMemory[v9];
        if ( v11 != nullptr )
          *v11 = list[v5];
        v4 = list;
        if ( list[v5] == currentKb )
          oldKb = m_Size - 1;
      }
      else
      {
        while ( LOWORD(v4[v8]) != LOWORD(v4[v5]) )
        {
          if ( ++v8 >= v5 )
            goto LABEL_7;
        }
      }
      if ( ++v5 >= numKBs )
        break;
      m_nAllocationCount = selections.m_Memory.m_nAllocationCount;
    }
    oldKb += 2 * forward - 1;
    if ( oldKb >= 0 )
    {
      if ( oldKb >= m_Size )
        oldKb = 0;
    }
    else
    {
      oldKb = (m_Size - 1) & ((m_Size - 1 < 0) - 1);
    }
    ActivateKeyboardLayout(hkl: selections.m_Memory.m_pMemory[oldKb], Flags: 0);
    v12 = selections.m_Memory.m_pMemory;
    SpewIMEInfo(a1: oldKb, langid: (__int16)selections.m_Memory.m_pMemory[oldKb]);
    free(pMem: v4);
    if ( selections.m_Memory.m_nGrowSize >= 0 && v12 != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v12);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005B50
// Name: public: virtual int CInputWin32::GetIMELanguageList(struct vgui::IInput::LanguageItem __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CInputWin32::GetIMELanguageList(CInputWin32 *this, vgui::IInput::LanguageItem *dest, int destcount)
{
  unsigned int KeyboardLayoutList; // eax
  int v4; // edi
  HKL__ **v5; // esi
  HKL__ **m_pMemory; // ecx
  int m_Size; // ebx
  signed int v8; // edi
  int v9; // eax
  int v10; // esi
  HKL__ **v11; // esi
  HKL__ **v12; // edx
  int v14; // eax
  vgui::IInput::LanguageItem *j; // esi
  int v16; // edx
  HKL v17; // ebx
  int v18; // ecx
  unsigned int v19; // eax
  LanguageIds *v20; // edi
  HKL KeyboardLayout; // eax
  bool v22; // zf
  CUtlVector<HKL__ *,CUtlMemory<HKL__ *,int> > selections; // [esp+Ch] [ebp-1Ch] BYREF
  unsigned int numKBs; // [esp+20h] [ebp-8h]
  HKL__ **list; // [esp+24h] [ebp-4h]
  int i; // [esp+30h] [ebp+8h]

  KeyboardLayoutList = GetKeyboardLayoutList(nBuff: 0, lpList: nullptr);
  v4 = KeyboardLayoutList;
  numKBs = KeyboardLayoutList;
  if ( KeyboardLayoutList == 0 )
    return 0;
  v5 = (HKL__ **)operator new(nSize: 4 * KeyboardLayoutList);
  list = v5;
  GetKeyboardLayoutList(nBuff: v4, lpList: v5);
  m_pMemory = nullptr;
  m_Size = 0;
  v8 = 0;
  memset(&selections, 0, sizeof(selections));
  do
  {
    v9 = 0;
    if ( v8 <= 0 )
    {
LABEL_6:
      v10 = m_Size;
      if ( m_Size + 1 > selections.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<int,int>::Grow(
          this: (CUtlMemory<CWin32Font *,int> *)&selections,
          num: m_Size - selections.m_Memory.m_nAllocationCount + 1);
        m_Size = selections.m_Size;
        m_pMemory = selections.m_Memory.m_pMemory;
      }
      selections.m_Size = ++m_Size;
      selections.m_pElements = m_pMemory;
      if ( m_Size - v10 - 1 > 0 )
      {
        _V_memmove(dest: &m_pMemory[v10 + 1], src: &m_pMemory[v10], count: 4 * (m_Size - v10 - 1));
        m_pMemory = selections.m_Memory.m_pMemory;
      }
      v11 = &m_pMemory[v10];
      if ( v11 != nullptr )
      {
        v12 = list;
        *v11 = list[v8];
        v5 = v12;
      }
      else
      {
        v5 = list;
      }
    }
    else
    {
      while ( LOWORD(v5[v9]) != LOWORD(v5[v8]) )
      {
        if ( ++v9 >= v8 )
          goto LABEL_6;
      }
    }
    ++v8;
  }
  while ( v8 < numKBs );
  if ( dest != nullptr )
  {
    v14 = 0;
    i = 0;
    for ( j = dest; ; ++j )
    {
      v16 = destcount;
      if ( m_Size < destcount )
        v16 = m_Size;
      if ( v14 >= v16 )
        break;
      v17 = m_pMemory[v14];
      v18 = 0;
      v19 = 0;
      while ( g_LanguageIds[v19].id != (_WORD)v17 )
      {
        ++v19;
        ++v18;
        if ( v19 >= 168 )
        {
          v20 = nullptr;
          goto LABEL_23;
        }
      }
      v20 = &g_LanguageIds[v18];
LABEL_23:
      memset(dst: (unsigned __int8 *)j, value: 0, count: sizeof(vgui::IInput::LanguageItem));
      wcsncpy(dest: j->shortname, source: v20->shortcode, count: 4u);
      j->shortname[3] = 0;
      wcsncpy(dest: j->menuname, source: v20->displayname, count: 0x80u);
      j->menuname[127] = 0;
      j->handleValue = (int)v17;
      KeyboardLayout = GetKeyboardLayout(idThread: 0);
      m_pMemory = selections.m_Memory.m_pMemory;
      v22 = v17 == KeyboardLayout;
      m_Size = selections.m_Size;
      ++i;
      j->active = v22;
      v14 = i;
    }
    v5 = list;
  }
  free(pMem: v5);
  if ( selections.m_Memory.m_nGrowSize >= 0 && selections.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: selections.m_Memory.m_pMemory);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10005D30
// Name: public: virtual void CInputWin32::RegisterKeyCodeUnhandledListener(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputWin32::RegisterKeyCodeUnhandledListener(CInputWin32 *this, CWin32Font *panel)
{
  int m_hContext; // eax
  CInputWin32::InputContext_t *v3; // eax
  int m_Size; // ecx
  CUtlMemory<CWin32Font *,int> *p_m_KeyCodeUnhandledListeners; // esi
  int v6; // eax
  CWin32Font **m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v9; // edi
  CWin32Font **v10; // ecx
  int v11; // eax
  CWin32Font **v12; // eax

  if ( panel != nullptr )
  {
    m_hContext = this->m_hContext;
    v3 = m_hContext == -1
       ? &this->m_DefaultInputContext
       : (CInputWin32::InputContext_t *)&this->m_Contexts.m_Memory.m_pMemory[m_hContext];
    if ( v3 != nullptr )
    {
      m_Size = v3->m_KeyCodeUnhandledListeners.m_Size;
      p_m_KeyCodeUnhandledListeners = (CUtlMemory<CWin32Font *,int> *)&v3->m_KeyCodeUnhandledListeners;
      v6 = 0;
      if ( m_Size <= 0 )
        goto LABEL_12;
      m_pMemory = p_m_KeyCodeUnhandledListeners->m_pMemory;
      while ( *m_pMemory != panel )
      {
        ++v6;
        ++m_pMemory;
        if ( v6 >= m_Size )
          goto LABEL_12;
      }
      if ( v6 == -1 )
      {
LABEL_12:
        m_nAllocationCount = p_m_KeyCodeUnhandledListeners->m_nAllocationCount;
        v9 = m_Size;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<int,int>::Grow(this: p_m_KeyCodeUnhandledListeners, num: m_Size - m_nAllocationCount + 1);
        ++p_m_KeyCodeUnhandledListeners[1].m_pMemory;
        v10 = p_m_KeyCodeUnhandledListeners->m_pMemory;
        v11 = (int)p_m_KeyCodeUnhandledListeners[1].m_pMemory - v9 - 1;
        p_m_KeyCodeUnhandledListeners[1].m_nAllocationCount = (int)p_m_KeyCodeUnhandledListeners->m_pMemory;
        if ( v11 > 0 )
          _V_memmove(dest: &v10[v9 + 1], src: &v10[v9], count: 4 * v11);
        v12 = &p_m_KeyCodeUnhandledListeners->m_pMemory[v9];
        if ( v12 != nullptr )
          *v12 = panel;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005F50
// Name: public: virtual int CInputWin32::CreateInputContext(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CInputWin32::CreateInputContext(CInputWin32 *this)
{
  int v2; // ebx

  v2 = CUtlLinkedList<CInputWin32::InputContext_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CInputWin32::InputContext_t,int>,int>>::InsertBefore(
         this: &this->m_Contexts,
         before: -1);
  CInputWin32::InitInputContext(this, pContext: &this->m_Contexts.m_Memory.m_pMemory[v2].m_Element);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10005F80
// Name: public: CInputWin32::CInputWin32(void)
// Source: json
//------------------------------------------------------------------------------
CInputWin32 *__thiscall CInputWin32::CInputWin32(CInputWin32 *this)
{
  CInputWin32::InputContext_t *p_m_DefaultInputContext; // edi

  this->__vftable = (CInputWin32_vtbl *)&CInputWin32::`vftable';
  p_m_DefaultInputContext = &this->m_DefaultInputContext;
  this->m_DefaultInputContext.m_KeyCodeUnhandledListeners.m_Memory.m_pMemory = nullptr;
  this->m_DefaultInputContext.m_KeyCodeUnhandledListeners.m_Memory.m_nAllocationCount = 0;
  this->m_DefaultInputContext.m_KeyCodeUnhandledListeners.m_Memory.m_nGrowSize = 0;
  this->m_DefaultInputContext.m_KeyCodeUnhandledListeners.m_Size = 0;
  this->m_DefaultInputContext.m_KeyCodeUnhandledListeners.m_pElements = nullptr;
  vgui::CKeyRepeatHandler::CKeyRepeatHandler(this: &this->m_DefaultInputContext.m_keyRepeater);
  this->m_Contexts.m_Memory.m_pMemory = nullptr;
  this->m_Contexts.m_Memory.m_nAllocationCount = 0;
  this->m_Contexts.m_Memory.m_nGrowSize = 0;
  this->m_Contexts.m_LastAlloc.index = -1;
  this->m_Contexts.m_pElements = this->m_Contexts.m_Memory.m_pMemory;
  this->m_Contexts.m_Head = -1;
  this->m_Contexts.m_Tail = -1;
  this->m_Contexts.m_FirstFree = -1;
  this->m_Contexts.m_ElementCount = 0;
  this->m_Contexts.m_NumAlloced = 0;
  this->m_nDebugMessages = -1;
  this->_imeWnd = nullptr;
  this->_imeCandidates = nullptr;
  CInputWin32::InitInputContext(this, pContext: p_m_DefaultInputContext);
  this->m_hContext = -1;
  this->_keyTrans[1] = "0)KEY_0";
  this->_keyTrans[2] = "1!KEY_1";
  this->_keyTrans[3] = "2@KEY_2";
  this->_keyTrans[4] = "3#KEY_3";
  this->_keyTrans[5] = "4$KEY_4";
  this->_keyTrans[6] = "5%KEY_5";
  this->_keyTrans[7] = "6^KEY_6";
  this->_keyTrans[8] = "7&KEY_7";
  this->_keyTrans[9] = "8*KEY_8";
  this->_keyTrans[10] = "9(KEY_9";
  this->_keyTrans[11] = "aAKEY_A";
  this->_keyTrans[12] = "bBKEY_B";
  this->_keyTrans[13] = "cCKEY_C";
  this->_keyTrans[14] = "dDKEY_D";
  this->_keyTrans[15] = "eEKEY_E";
  this->_keyTrans[16] = "fFKEY_F";
  this->_keyTrans[17] = "gGKEY_G";
  this->_keyTrans[18] = "hHKEY_H";
  this->_keyTrans[19] = "iIKEY_I";
  this->_keyTrans[20] = "jJKEY_J";
  this->_keyTrans[21] = "kKKEY_K";
  this->_keyTrans[22] = "lLKEY_L, L";
  this->_keyTrans[23] = "mMKEY_M";
  this->_keyTrans[24] = "nNKEY_N";
  this->_keyTrans[25] = "oOKEY_O";
  this->_keyTrans[26] = "pPKEY_P";
  this->_keyTrans[27] = "qQKEY_Q";
  this->_keyTrans[28] = "rRKEY_R";
  this->_keyTrans[29] = "sSKEY_S";
  this->_keyTrans[30] = "tTKEY_T";
  this->_keyTrans[31] = "uUKEY_U";
  this->_keyTrans[32] = "vVKEY_V";
  this->_keyTrans[33] = "wWKEY_W";
  this->_keyTrans[34] = "xXKEY_X";
  this->_keyTrans[35] = "yYKEY_Y";
  this->_keyTrans[36] = "zZKEY_Z";
  this->_keyTrans[37] = "0";
  this->_keyTrans[38] = "1";
  this->_keyTrans[39] = "2";
  this->_keyTrans[40] = "3";
  this->_keyTrans[41] = "4";
  this->_keyTrans[42] = "5";
  this->_keyTrans[43] = "6";
  this->_keyTrans[44] = "7";
  this->_keyTrans[45] = "8";
  this->_keyTrans[46] = "9";
  this->_keyTrans[47] = "//KEY_PAD_DIVIDE";
  this->_keyTrans[48] = "**KEY_PAD_MULTIPLY";
  this->_keyTrans[49] = "--KEY_PAD_MINUS";
  this->_keyTrans[50] = "++KEY_PAD_PLUS";
  this->_keyTrans[51] = (char *)&unk_1003E67C;
  this->_keyTrans[52] = ".";
  this->_keyTrans[53] = "[{KEY_LBRACKET";
  this->_keyTrans[54] = "]}KEY_RBRACKET";
  this->_keyTrans[55] = ";:KEY_SEMICOLON";
  this->_keyTrans[56] = "'\"KEY_APOSTROPHE";
  this->_keyTrans[57] = "`~KEY_BACKQUOTE";
  this->_keyTrans[58] = ",<KEY_COMMA";
  this->_keyTrans[59] = ".>KEY_PERIOD";
  this->_keyTrans[60] = "/?KEY_SLASH";
  this->_keyTrans[61] = "\\|KEY_BACKSLASH";
  this->_keyTrans[62] = "-_KEY_MINUS";
  this->_keyTrans[63] = "=+KEY_EQUAL, L";
  this->_keyTrans[64] = (char *)&unk_1003E5B0;
  this->_keyTrans[65] = "  KEY_SPACE";
  this->_keyTrans[66] = (char *)&unk_1003E594;
  this->_keyTrans[67] = (char *)&unk_1003E588;
  this->_keyTrans[68] = (char *)&unk_1003E578;
  this->_keyTrans[69] = (char *)&unk_1003E568;
  this->_keyTrans[70] = (char *)&unk_1003E558;
  this->_keyTrans[71] = (char *)&unk_1003E544;
  this->_keyTrans[72] = (char *)&unk_1003E534;
  this->_keyTrans[73] = (char *)&unk_1003E524;
  this->_keyTrans[74] = (char *)&unk_1003E518;
  this->_keyTrans[75] = (char *)&unk_1003E50C;
  this->_keyTrans[76] = (char *)&unk_1003E4FC;
  this->_keyTrans[77] = (char *)&unk_1003E4EC;
  this->_keyTrans[78] = (char *)&unk_1003E4E0;
  this->_keyTrans[79] = (char *)&unk_1003E4D0;
  this->_keyTrans[80] = (char *)&unk_1003E4C0;
  this->_keyTrans[81] = (char *)&unk_1003E4B4;
  this->_keyTrans[82] = (char *)&unk_1003E4A8;
  this->_keyTrans[83] = (char *)&unk_1003E494;
  this->_keyTrans[84] = (char *)&unk_1003E480;
  this->_keyTrans[85] = (char *)&unk_1003E474;
  this->_keyTrans[86] = (char *)&unk_1003E468;
  this->_keyTrans[87] = (char *)&unk_1003E45C;
  this->_keyTrans[88] = (char *)&unk_1003E450;
  this->_keyTrans[89] = (char *)&unk_1003E444;
  this->_keyTrans[90] = (char *)&unk_1003E438;
  this->_keyTrans[91] = (char *)&unk_1003E42C;
  this->_keyTrans[92] = (char *)&unk_1003E420;
  this->_keyTrans[93] = (char *)&unk_1003E414;
  this->_keyTrans[94] = (char *)&unk_1003E408;
  this->_keyTrans[95] = (char *)&unk_1003E3FC;
  this->_keyTrans[96] = (char *)&unk_1003E3F0;
  this->_keyTrans[97] = (char *)&unk_1003E3E4;
  this->_keyTrans[98] = (char *)&unk_1003E3D8;
  this->_keyTrans[99] = (char *)&unk_1003E3CC;
  this->_keyTrans[100] = (char *)&unk_1003E3C0;
  this->_keyTrans[101] = (char *)&unk_1003E3B4;
  this->_keyTrans[102] = (char *)&unk_1003E3A8;
  this->_keyTrans[103] = (char *)&unk_1003E39C;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100063E0
// Name: public: virtual int CInputWin32::GetJoystickXPos(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CInputWin32::GetJoystickXPos(CInputWin32 *this)
{
  return this->m_JoystickX;
}

//------------------------------------------------------------------------------
// Address: 0x100063F0
// Name: public: virtual int CInputWin32::GetJoystickYPos(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CInputWin32::GetJoystickYPos(CInputWin32 *this)
{
  return this->m_JoysitckY;
}

//------------------------------------------------------------------------------
// Address: 0x10006400
// Name: public: virtual CInputWin32::~CInputWin32(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputWin32::~CInputWin32(CInputWin32 *this)
{
  tagCANDIDATELIST *imeCandidates; // eax

  imeCandidates = this->_imeCandidates;
  this->__vftable = (CInputWin32_vtbl *)&CInputWin32::`vftable';
  if ( imeCandidates != nullptr )
  {
    free(pMem: imeCandidates);
    this->_imeCandidates = nullptr;
  }
  CUtlLinkedList<CInputWin32::InputContext_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CInputWin32::InputContext_t,int>,int>>::RemoveAll(this: &this->m_Contexts);
  if ( this->m_Contexts.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Contexts.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Contexts.m_Memory.m_pMemory);
      this->m_Contexts.m_Memory.m_pMemory = nullptr;
    }
    this->m_Contexts.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<CFontAmalgam::TFontRange,CUtlMemory<CFontAmalgam::TFontRange,int>>::~CUtlVector<CFontAmalgam::TFontRange,CUtlMemory<CFontAmalgam::TFontRange,int>>(this: (CUtlVector<CWin32Font *,CUtlMemory<CWin32Font *,int> > *)&this->m_DefaultInputContext.m_KeyCodeUnhandledListeners);
  this->__vftable = (CInputWin32_vtbl *)&IBaseInterface::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10006480
// Name: public: virtual void CInputWin32::DestroyInputContext(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputWin32::DestroyInputContext(CInputWin32 *this, int context)
{
  CUtlLinkedList<CInputWin32::InputContext_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CInputWin32::InputContext_t,int>,int> > *p_m_Contexts; // edi
  UtlLinkedListElem_t<CInputWin32::InputContext_t,int> *v4; // esi

  if ( this->m_hContext == context )
    this->ActivateInputContext(this, a2: -1);
  p_m_Contexts = &this->m_Contexts;
  CUtlLinkedList<CInputWin32::InputContext_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CInputWin32::InputContext_t,int>,int>>::Unlink(
    this: &this->m_Contexts,
    elem: context);
  v4 = &this->m_Contexts.m_Memory.m_pMemory[context];
  CUtlVector<CFontAmalgam::TFontRange,CUtlMemory<CFontAmalgam::TFontRange,int>>::~CUtlVector<CFontAmalgam::TFontRange,CUtlMemory<CFontAmalgam::TFontRange,int>>(this: (CUtlVector<CWin32Font *,CUtlMemory<CWin32Font *,int> > *)&v4->m_Element.m_KeyCodeUnhandledListeners);
  v4->m_Next = p_m_Contexts->m_FirstFree;
  p_m_Contexts->m_FirstFree = context;
}
