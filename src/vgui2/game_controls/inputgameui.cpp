// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/game_controls/inputgameui.cpp
// Functions: 128
// ============================================================

#include "vgui2\game_controls\inputgameui.h"

//------------------------------------------------------------------------------
// Address: 0x00413270
// Name: public: virtual void CInputGameUI::ActivateInputContext(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputGameUI::ActivateInputContext(CInputGameUI *this, unsigned int context)
{
  this->m_hContext = context;
}

//------------------------------------------------------------------------------
// Address: 0x00413280
// Name: public: void CInputGameUI::ProcessEvents(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputGameUI::ProcessEvents(CInputGameUI *this)
{
  g_pEventSystem->ProcessEvents(this: g_pEventSystem, a2: this->m_hEventChannel);
}

//------------------------------------------------------------------------------
// Address: 0x004132A0
// Name: private: void CInputGameUI::GraphicHidden(class CHitArea __near *,struct CInputGameUI::InputContext_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputGameUI::GraphicHidden(CInputGameUI *this, CHitArea *focus, CInputGameUI::InputContext_t *context)
{
  if ( context->_keyFocus == focus )
  {
    context->_keyFocus = nullptr;
    context->_bKeyTrap = false;
  }
  if ( context->_mouseOver == focus )
    context->_mouseOver = nullptr;
  if ( context->_oldMouseFocus == focus )
    context->_oldMouseFocus = nullptr;
  if ( context->_mouseFocus == focus )
    context->_mouseFocus = nullptr;
  if ( context->_mouseLeftTrap == focus )
    context->_mouseLeftTrap = nullptr;
  if ( context->_mouseMiddleTrap == focus )
    context->_mouseMiddleTrap = nullptr;
  if ( context->_mouseRightTrap == focus )
    context->_mouseRightTrap = nullptr;
  if ( context->_mouseCapture == focus )
  {
    this->SetMouseCapture(this, a2: nullptr);
    context->_mouseCapture = nullptr;
  }
  if ( context->m_pUnhandledMouseClickListener == focus )
    context->m_pUnhandledMouseClickListener = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00413350
// Name: public: void CInputGameUI::GetCursorPos(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputGameUI::GetCursorPos(CInputGameUI *this, int *x, int *y)
{
  this->GetCursorPosition(this, a2: x, a3: y);
}

//------------------------------------------------------------------------------
// Address: 0x00413360
// Name: public: virtual void CInputGameUI::SetIMEWindow(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputGameUI::SetIMEWindow(CInputGameUI *this, void *hwnd)
{
  this->_imeWnd = hwnd;
}

//------------------------------------------------------------------------------
// Address: 0x00413370
// Name: public: virtual void __near * CInputGameUI::GetIMEWindow(void)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CInputGameUI::GetIMEWindow(CInputGameUI *this)
{
  return this->_imeWnd;
}

//------------------------------------------------------------------------------
// Address: 0x00413380
// Name: SpewIMEInfo
// Source: json
//------------------------------------------------------------------------------
void __fastcall SpewIMEInfo(int a1, __int16 langid)
{
  int v2; // ecx
  unsigned int v3; // eax
  const wchar_t *v4; // eax
  wchar_t outstr[514]; // [esp+0h] [ebp-404h] BYREF

  v2 = 0;
  v3 = 0;
  while ( g_LanguageIds[v3].id != langid )
  {
    ++v3;
    ++v2;
    if ( v3 >= 168 )
      return;
  }
  if ( 20 * v2 != -5999248 )
  {
    v4 = *((const wchar_t **)&unk_5B8A98 + 5 * v2);
    if ( v4 == nullptr )
      v4 = L"???";
    _snwprintf(string: &outstr[2], count: 0x200u, format: L"IME language changed to:  %s", v4);
    OutputDebugStringW(lpOutputString: &outstr[2]);
    OutputDebugStringW(lpOutputString: L"\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x00413400
// Name: public: virtual int CInputGameUI::GetCurrentIMEHandle(void)
// Source: json
//------------------------------------------------------------------------------
HKL __thiscall CInputGameUI::GetCurrentIMEHandle(CInputGameUI *this)
{
  return GetKeyboardLayout(idThread: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00413410
// Name: public: virtual int CInputGameUI::GetEnglishIMEHandle(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CInputGameUI::GetEnglishIMEHandle(CInputGameUI *this)
{
  return 67699721;
}

//------------------------------------------------------------------------------
// Address: 0x00413420
// Name: public: virtual void CInputGameUI::OnChangeIMEByHandle(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputGameUI::OnChangeIMEByHandle(CInputGameUI *this, HKL handleValue)
{
  int v2; // ecx

  ActivateKeyboardLayout(hkl: handleValue, Flags: 0);
  SpewIMEInfo(a1: v2, langid: (__int16)handleValue);
}

//------------------------------------------------------------------------------
// Address: 0x00413440
// Name: public: virtual void CInputGameUI::GetIMELanguageName(wchar_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputGameUI::GetIMELanguageName(
        CInputGameUI *this,
        wchar_t *buf,
        unsigned int unicodeBufferSizeInBytes)
{
  unsigned __int16 KeyboardLayout; // si
  int v4; // ecx
  const wchar_t *v5; // edx
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
  v5 = (&off_5B8A9C)[5 * v4];
LABEL_6:
  wcsncpy(dest: buf, source: v5, count: (unicodeBufferSizeInBytes >> 1) - 1);
  buf[(unicodeBufferSizeInBytes >> 1) - 1] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x004134A0
// Name: public: virtual void CInputGameUI::GetIMELanguageShortCode(wchar_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputGameUI::GetIMELanguageShortCode(
        CInputGameUI *this,
        wchar_t *buf,
        unsigned int unicodeBufferSizeInBytes)
{
  unsigned __int16 KeyboardLayout; // dx
  int v4; // ecx
  unsigned int v5; // eax

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
  if ( 20 * v4 == -5999248 )
  {
    *buf = 0;
  }
  else
  {
    wcsncpy(dest: buf, source: *((const wchar_t **)&unk_5B8A98 + 5 * v4), count: (unicodeBufferSizeInBytes >> 1) - 1);
    buf[(unicodeBufferSizeInBytes >> 1) - 1] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00413520
// Name: public: void IMESettingsTransform::Apply(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IMESettingsTransform::Apply(IMESettingsTransform *this, unsigned int hwnd)
{
  HWND v2; // ebx
  HIMC Context; // esi
  unsigned int v5; // [esp-4h] [ebp-14h]
  unsigned int v6; // [esp-4h] [ebp-14h]
  unsigned int fdwSentence; // [esp+Ch] [ebp-4h] BYREF

  v2 = (HWND)hwnd;
  Context = ImmGetContext(a1: (HWND)hwnd);
  if ( Context != nullptr )
  {
    ImmGetConversionStatus(a1: Context, lpfdwConversion: &hwnd, lpfdwSentence: &fdwSentence);
    v5 = ~this->smode_remove & fdwSentence;
    hwnd &= ~this->cmode_remove;
    fdwSentence = v5;
    ImmSetConversionStatus(a1: Context, a2: hwnd, a3: v5);
    v6 = this->smode_add | fdwSentence;
    hwnd |= this->cmode_add;
    fdwSentence = v6;
    ImmSetConversionStatus(a1: Context, a2: hwnd, a3: v6);
    ImmReleaseContext(a1: v2, a2: Context);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004135A0
// Name: public: bool IMESettingsTransform::ConvMatches(unsigned long)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall IMESettingsTransform::ConvMatches(IMESettingsTransform *this, unsigned int convFlags)
{
  return (convFlags & this->cmode_remove) == 0 && (convFlags & this->cmode_add) == this->cmode_add;
}

//------------------------------------------------------------------------------
// Address: 0x004135C0
// Name: public: virtual int CInputGameUI::GetIMEConversionModes(struct CInputGameUI::ConversionModeItem __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CInputGameUI::GetIMEConversionModes(
        CInputGameUI *this,
        CInputGameUI::ConversionModeItem *dest,
        unsigned int destcount)
{
  CInputGameUI::ConversionModeItem *v3; // esi
  void *(__thiscall *GetIMEWindow)(CInputGameUI *); // eax
  HWND v6; // eax
  HIMC Context; // eax
  HIMC v8; // ebx
  HWND v9; // eax
  unsigned __int16 KeyboardLayout; // dx
  int v11; // ecx
  unsigned int v12; // eax
  int v13; // eax
  CInputGameUI::ConversionModeItem *v14; // esi
  IMESettingsTransform *v15; // ecx
  CInputGameUI::ConversionModeItem *v16; // edx
  bool v17; // al
  CInputGameUI::ConversionModeItem *v19; // edi
  CInputGameUI::ConversionModeItem *v20; // esi
  CInputGameUI::ConversionModeItem *v21; // [esp-4h] [ebp-Ch]
  CInputGameUI::ConversionModeItem *v22; // [esp-4h] [ebp-Ch]
  CInputGameUI::ConversionModeItem *v23; // [esp-4h] [ebp-Ch]
  CInputGameUI::ConversionModeItem *v24; // [esp-4h] [ebp-Ch]
  CInputGameUI::ConversionModeItem *v25; // [esp-4h] [ebp-Ch]
  CInputGameUI::ConversionModeItem *v26; // [esp-4h] [ebp-Ch]
  CInputGameUI::ConversionModeItem *v27; // [esp-4h] [ebp-Ch]
  CInputGameUI::ConversionModeItem *v28; // [esp-4h] [ebp-Ch]
  CInputGameUI::ConversionModeItem *v29; // [esp-4h] [ebp-Ch]
  CInputGameUI::ConversionModeItem *v30; // [esp-4h] [ebp-Ch]

  v3 = dest;
  if ( dest != nullptr )
    memset(dst: (int)dest, value: nullptr, count: 264 * destcount);
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
      v13 = 0;
      goto LABEL_9;
    }
  }
  v13 = 20 * v11 + 5999248;
LABEL_9:
  switch ( *(_DWORD *)(v13 + 4) )
  {
    case 1:
      if ( v3 == nullptr )
        return 2;
      wcsncpy(dest: v3->menuname, source: L"#IME_Chinese", count: 0x80u);
      v21 = dest;
      v3->handleValue = (int)&g_ConversionMode_CHT_ToChinese;
      v3->active = IMESettingsTransform::ConvMatches(
                     this: &g_ConversionMode_CHT_ToChinese,
                     convFlags: (unsigned int)v21);
      v14 = v3 + 1;
      wcsncpy(dest: v14->menuname, source: L"#IME_English", count: 0x80u);
      v15 = &g_ConversionMode_CHT_ToEnglish;
      goto LABEL_13;
    case 2:
      if ( v3 != nullptr )
      {
        wcsncpy(dest: v3->menuname, source: L"#IME_Hiragana", count: 0x80u);
        v22 = dest;
        v3->handleValue = (int)&g_ConversionMode_JP_Hiragana;
        v3->active = IMESettingsTransform::ConvMatches(
                       this: &g_ConversionMode_JP_Hiragana,
                       convFlags: (unsigned int)v22);
        wcsncpy(dest: v3[1].menuname, source: L"#IME_FullWidthKatakana", count: 0x80u);
        v23 = dest;
        v3[1].handleValue = (int)&g_ConversionMode_JP_FullwidthKatakana;
        v3[1].active = IMESettingsTransform::ConvMatches(
                         this: &g_ConversionMode_JP_FullwidthKatakana,
                         convFlags: (unsigned int)v23);
        wcsncpy(dest: v3[2].menuname, source: L"#IME_FullWidthAlphanumeric", count: 0x80u);
        v24 = dest;
        v3[2].handleValue = (int)&g_ConversionMode_JP_FullwidthAlphanumeric;
        v3[2].active = IMESettingsTransform::ConvMatches(
                         this: &g_ConversionMode_JP_FullwidthAlphanumeric,
                         convFlags: (unsigned int)v24);
        v19 = v3 + 3;
        wcsncpy(dest: v3[3].menuname, source: L"#IME_HalfWidthKatakana", count: 0x80u);
        v25 = dest;
        v3[3].handleValue = (int)&g_ConversionMode_JP_HalfwidthKatakana;
        v20 = v3 + 4;
        v19->active = IMESettingsTransform::ConvMatches(
                        this: &g_ConversionMode_JP_HalfwidthKatakana,
                        convFlags: (unsigned int)v25);
        wcsncpy(dest: v20->menuname, source: L"#IME_HalfWidthAlphanumeric", count: 0x80u);
        v26 = dest;
        v20->handleValue = (int)&g_ConversionMode_JP_HalfwidthAlphanumeric;
        v20->active = IMESettingsTransform::ConvMatches(
                        this: &g_ConversionMode_JP_HalfwidthAlphanumeric,
                        convFlags: (unsigned int)v26);
        ++v20;
        wcsncpy(dest: v20->menuname, source: L"#IME_English", count: 0x80u);
        v27 = dest;
        v20->handleValue = (int)&g_ConversionMode_JP_DirectInput;
        v20->active = IMESettingsTransform::ConvMatches(
                        this: &g_ConversionMode_JP_DirectInput,
                        convFlags: (unsigned int)v27);
      }
      return 6;
    case 3:
      if ( v3 == nullptr )
        return 2;
      wcsncpy(dest: v3->menuname, source: L"#IME_Korean", count: 0x80u);
      v28 = dest;
      v3->handleValue = (int)&g_ConversionMode_KO_ToKorean;
      v3->active = IMESettingsTransform::ConvMatches(this: &g_ConversionMode_KO_ToKorean, convFlags: (unsigned int)v28);
      v14 = v3 + 1;
      wcsncpy(dest: v14->menuname, source: L"#IME_English", count: 0x80u);
      v15 = &g_ConversionMode_KO_ToEnglish;
LABEL_13:
      v16 = dest;
      v14->handleValue = (int)v15;
      v17 = IMESettingsTransform::ConvMatches(this: v15, convFlags: (unsigned int)v16);
      break;
    case 4:
      if ( v3 == nullptr )
        return 2;
      wcsncpy(dest: v3->menuname, source: L"#IME_Chinese", count: 0x80u);
      v29 = dest;
      v3->handleValue = (int)&g_ConversionMode_CHS_ToChinese;
      v3->active = IMESettingsTransform::ConvMatches(
                     this: &g_ConversionMode_CHS_ToChinese,
                     convFlags: (unsigned int)v29);
      v14 = v3 + 1;
      wcsncpy(dest: v14->menuname, source: L"#IME_English", count: 0x80u);
      v30 = dest;
      v14->handleValue = (int)&g_ConversionMode_CHS_ToChinese;
      v17 = IMESettingsTransform::ConvMatches(this: &g_ConversionMode_CHS_ToChinese, convFlags: (unsigned int)v30);
      break;
    default:
      return 0;
  }
  v14->active = v17;
  return 2;
}

//------------------------------------------------------------------------------
// Address: 0x00413900
// Name: public: virtual int CInputGameUI::GetIMESentenceModes(struct CInputGameUI::SentenceModeItem __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CInputGameUI::GetIMESentenceModes(
        CInputGameUI *this,
        CInputGameUI::SentenceModeItem *dest,
        unsigned int destcount)
{
  CInputGameUI::SentenceModeItem *v3; // edi
  void *(__thiscall *GetIMEWindow)(CInputGameUI *); // eax
  HWND v6; // eax
  HIMC Context; // eax
  HIMC v8; // ebp
  HWND v9; // eax
  unsigned __int16 KeyboardLayout; // dx
  int v11; // ecx
  unsigned int v12; // eax
  int v13; // eax
  unsigned int v15; // ecx
  bool v16; // al
  unsigned int v17; // eax
  bool v18; // al
  unsigned int v19; // eax
  bool v20; // al
  unsigned int v21; // eax

  v3 = dest;
  if ( dest != nullptr )
    memset(dst: (int)dest, value: nullptr, count: 264 * destcount);
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
      v13 = 0;
      goto LABEL_9;
    }
  }
  v13 = 20 * v11 + 5999248;
LABEL_9:
  if ( *(_DWORD *)(v13 + 4) != 2 )
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
// Address: 0x00413AF0
// Name: public: virtual void CInputGameUI::OnChangeIMEConversionModeByHandle(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputGameUI::OnChangeIMEConversionModeByHandle(CInputGameUI *this, IMESettingsTransform *handleValue)
{
  void *v2; // eax

  if ( handleValue != nullptr )
  {
    v2 = this->GetIMEWindow(this);
    IMESettingsTransform::Apply(this: handleValue, hwnd: (unsigned int)v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00413B10
// Name: private: void CInputGameUI::CreateNewCandidateList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputGameUI::CreateNewCandidateList(CInputGameUI *this)
{
  HWND v2; // eax
  HIMC Context; // ebx
  DWORD CandidateListCountW; // eax
  DWORD v5; // esi
  tagCANDIDATELIST *v6; // edi
  HWND v7; // eax
  unsigned int dwListCount; // [esp+8h] [ebp-4h] BYREF

  v2 = (HWND)this->GetIMEWindow(this);
  Context = ImmGetContext(a1: v2);
  if ( Context != nullptr )
  {
    dwListCount = 0;
    CandidateListCountW = ImmGetCandidateListCountW(a1: Context, lpdwListCount: &dwListCount);
    if ( dwListCount != 0 )
    {
      v5 = CandidateListCountW + 1;
      v6 = (tagCANDIDATELIST *)MemAlloc_Alloc(nSize: CandidateListCountW + 1);
      _V_memset(dest: v6, fill: 0, count: v5);
      if ( ImmGetCandidateListW(a1: Context, deIndex: 0, lpCandList: v6, dwBufLen: v5) != 0 )
        this->_imeCandidates = v6;
      else
        free(pMem: v6);
    }
    v7 = (HWND)this->GetIMEWindow(this);
    ImmReleaseContext(a1: v7, a2: Context);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00413BA0
// Name: public: virtual int CInputGameUI::GetCandidateListCount(void)
// Source: json
//------------------------------------------------------------------------------
tagCANDIDATELIST *__thiscall CInputGameUI::GetCandidateListCount(CInputGameUI *this)
{
  tagCANDIDATELIST *result; // eax

  result = this->_imeCandidates;
  if ( result != nullptr )
    return (tagCANDIDATELIST *)result->dwCount;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00413BB0
// Name: public: virtual void CInputGameUI::GetCandidate(int,wchar_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputGameUI::GetCandidate(CInputGameUI *this, int num, wchar_t *dest, unsigned int destSizeBytes)
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
// Address: 0x00413C00
// Name: public: virtual int CInputGameUI::GetCandidateListSelectedItem(void)
// Source: json
//------------------------------------------------------------------------------
tagCANDIDATELIST *__thiscall CInputGameUI::GetCandidateListSelectedItem(CInputGameUI *this)
{
  tagCANDIDATELIST *result; // eax

  result = this->_imeCandidates;
  if ( result != nullptr )
    return (tagCANDIDATELIST *)result->dwSelection;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00413C10
// Name: public: virtual int CInputGameUI::GetCandidateListPageSize(void)
// Source: json
//------------------------------------------------------------------------------
tagCANDIDATELIST *__thiscall CInputGameUI::GetCandidateListPageSize(CInputGameUI *this)
{
  tagCANDIDATELIST *result; // eax

  result = this->_imeCandidates;
  if ( result != nullptr )
    return (tagCANDIDATELIST *)result->dwPageSize;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00413C20
// Name: public: virtual int CInputGameUI::GetCandidateListPageStart(void)
// Source: json
//------------------------------------------------------------------------------
tagCANDIDATELIST *__thiscall CInputGameUI::GetCandidateListPageStart(CInputGameUI *this)
{
  tagCANDIDATELIST *result; // eax

  result = this->_imeCandidates;
  if ( result != nullptr )
    return (tagCANDIDATELIST *)result->dwPageStart;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00413C30
// Name: public: virtual void CInputGameUI::SetCandidateListPageStart(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputGameUI::SetCandidateListPageStart(CInputGameUI *this, DWORD start)
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
// Address: 0x00413C70
// Name: public: virtual bool CInputGameUI::CandidateListStartsAtOne(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CInputGameUI::CandidateListStartsAtOne(CInputGameUI *this)
{
  HKL KeyboardLayout; // eax

  KeyboardLayout = GetKeyboardLayout(idThread: 0);
  return (ImmGetProperty(a1: KeyboardLayout, a2: 4u) & 0x40000) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x00413C90
// Name: public: virtual void CInputGameUI::SetCandidateWindowPos(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputGameUI::SetCandidateWindowPos(CInputGameUI *this, int x, int y)
{
  HWND v4; // eax
  HIMC Context; // edi
  HWND v6; // eax
  tagCANDIDATEFORM Candidate; // [esp+4h] [ebp-24h] BYREF

  v4 = (HWND)this->GetIMEWindow(this);
  Context = ImmGetContext(a1: v4);
  if ( Context != nullptr )
  {
    Candidate.dwStyle = 0;
    Candidate.ptCurrentPos.x = 32;
    Candidate.ptCurrentPos.y = x;
    Candidate.rcArea.left = y;
    ImmSetCandidateWindow(a1: Context, lpCandidate: (LPCANDIDATEFORM)&Candidate.dwStyle);
    v6 = (HWND)this->GetIMEWindow(this);
    ImmReleaseContext(a1: v6, a2: Context);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00413CF0
// Name: public: virtual bool CInputGameUI::GetShouldInvertCompositionString(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CInputGameUI::GetShouldInvertCompositionString(CInputGameUI *this)
{
  unsigned __int16 KeyboardLayout; // dx
  int v2; // ecx
  unsigned int v3; // eax

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
  if ( 20 * v2 == -5999248 )
    return false;
  else
    return byte_5B8AA0[20 * v2];
}

//------------------------------------------------------------------------------
// Address: 0x00413D30
// Name: public: void CInputGameUI::OnCursorEnter(class CHitArea __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputGameUI::OnCursorEnter(CInputGameUI *this, CHitArea **pTarget)
{
  CHitArea::OnCursorEnter(this: *pTarget);
}

//------------------------------------------------------------------------------
// Address: 0x00413D40
// Name: public: void CInputGameUI::OnCursorExit(class CHitArea __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputGameUI::OnCursorExit(CInputGameUI *this, CHitArea **pTarget)
{
  CHitArea::OnCursorExit(this: *pTarget);
}

//------------------------------------------------------------------------------
// Address: 0x00413D50
// Name: public: void CInputGameUI::OnCursorMove(class CHitArea __near * const __near &,int const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputGameUI::OnCursorMove(CInputGameUI *this, CHitArea **pTarget, const int *x, const int *y)
{
  CHitArea::OnCursorMove(this: *pTarget, cursorX: x, cursorY: y);
}

//------------------------------------------------------------------------------
// Address: 0x00413D70
// Name: public: void CInputGameUI::OnMouseDown(class CHitArea __near * const __near &,enum ButtonCode_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputGameUI::OnMouseDown(CInputGameUI *this, CHitArea **pTarget, const ButtonCode_t *code)
{
  CHitArea::OnMouseDown(this: *pTarget, code);
}

//------------------------------------------------------------------------------
// Address: 0x00413D90
// Name: public: void CInputGameUI::OnMouseDoubleClick(class CHitArea __near * const __near &,enum ButtonCode_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputGameUI::OnMouseDoubleClick(CInputGameUI *this, CHitArea **pTarget, const ButtonCode_t *code)
{
  CHitArea::OnMouseDoubleClick(this: *pTarget, code);
}

//------------------------------------------------------------------------------
// Address: 0x00413DB0
// Name: public: void CInputGameUI::OnKeyDown(class CHitArea __near * const __near &,enum ButtonCode_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputGameUI::OnKeyDown(CInputGameUI *this, CHitArea **pTarget, const ButtonCode_t *code)
{
  CHitArea::OnKeyDown(this: *pTarget, code);
}

//------------------------------------------------------------------------------
// Address: 0x00413DD0
// Name: public: void CInputGameUI::OnKeyUp(class CHitArea __near * const __near &,enum ButtonCode_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputGameUI::OnKeyUp(CInputGameUI *this, CHitArea **pTarget, const ButtonCode_t *code)
{
  CHitArea::OnKeyUp(this: *pTarget, code);
}

//------------------------------------------------------------------------------
// Address: 0x00413DF0
// Name: public: void CInputGameUI::OnKeyCodeTyped(class CHitArea __near * const __near &,enum ButtonCode_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputGameUI::OnKeyCodeTyped(CInputGameUI *this, CHitArea **pTarget, const ButtonCode_t *code)
{
  CHitArea::OnKeyCodeTyped(this: *pTarget, code);
}

//------------------------------------------------------------------------------
// Address: 0x00413E10
// Name: public: void CInputGameUI::OnKeyTyped(class CHitArea __near * const __near &,wchar_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputGameUI::OnKeyTyped(CInputGameUI *this, CHitArea **pTarget, const wchar_t *unichar)
{
  CHitArea::OnKeyTyped(this: *pTarget, unichar);
}

//------------------------------------------------------------------------------
// Address: 0x00413E30
// Name: public: void CInputGameUI::OnLoseKeyFocus(class CHitArea __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputGameUI::OnLoseKeyFocus(CInputGameUI *this, CHitArea **pTarget)
{
  CHitArea::OnLoseKeyFocus(this: *pTarget);
}

//------------------------------------------------------------------------------
// Address: 0x00413E40
// Name: public: void CInputGameUI::OnGainKeyFocus(class CHitArea __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputGameUI::OnGainKeyFocus(CInputGameUI *this, CHitArea **pTarget)
{
  CHitArea::OnGainKeyFocus(this: *pTarget);
}

//------------------------------------------------------------------------------
// Address: 0x00413E50
// Name: public: virtual void CMemberFunctorCallback3<class CInputGameUI,class CHitArea __near *,int,int,class CFuncMemPolicyNone>::ComputeValidationString(char __near *,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctorCallback3<CInputGameUI,CHitArea *,int,int,CFuncMemPolicyNone>::ComputeValidationString(
        CMemberFunctorCallback3<CInputGameUI,CHitArea *,int,int,CFuncMemPolicyNone> *this,
        char *pString,
        unsigned int nBufLen)
{
  const char *v3; // eax
  const char *v4; // [esp-8h] [ebp-8h]
  const char *v5; // [esp-4h] [ebp-4h]

  v5 = type_info::name(this: &int `RTTI Type Descriptor', __ptype_info_node: &__type_info_root_node);
  v4 = type_info::name(this: &int `RTTI Type Descriptor', __ptype_info_node: &__type_info_root_node);
  v3 = type_info::name(this: &CHitArea * `RTTI Type Descriptor', __ptype_info_node: &__type_info_root_node);
  V_snprintf(pDest: pString, maxLen: nBufLen, pFormat: "method( %s, %s, %s )", v3, v4, v5);
}

//------------------------------------------------------------------------------
// Address: 0x00413EA0
// Name: public: virtual void CFunctorData2<int,int>::ComputeValidationString(char __near *,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFunctorData2<int,int>::ComputeValidationString(
        CMemberFunctorCallback2<CInputGameUI,int,int,CFuncMemPolicyNone> *this,
        char *pString,
        unsigned int nBufLen)
{
  const char *v3; // eax
  const char *v4; // [esp-4h] [ebp-4h]

  v4 = type_info::name(this: &int `RTTI Type Descriptor', __ptype_info_node: &__type_info_root_node);
  v3 = type_info::name(this: &int `RTTI Type Descriptor', __ptype_info_node: &__type_info_root_node);
  V_snprintf(pDest: pString, maxLen: nBufLen, pFormat: "method( %s, %s )", v3, v4);
}

//------------------------------------------------------------------------------
// Address: 0x00413EE0
// Name: public: virtual void CFunctorData2<class CHitArea __near *,int>::ComputeValidationString(char __near *,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFunctorData2<CHitArea *,int>::ComputeValidationString(
        CMemberFunctorCallback2<CInputGameUI,CHitArea *,int,CFuncMemPolicyNone> *this,
        char *pString,
        unsigned int nBufLen)
{
  const char *v3; // eax
  const char *v4; // [esp-4h] [ebp-4h]

  v4 = type_info::name(this: &int `RTTI Type Descriptor', __ptype_info_node: &__type_info_root_node);
  v3 = type_info::name(this: &CHitArea * `RTTI Type Descriptor', __ptype_info_node: &__type_info_root_node);
  V_snprintf(pDest: pString, maxLen: nBufLen, pFormat: "method( %s, %s )", v3, v4);
}

//------------------------------------------------------------------------------
// Address: 0x00413F20
// Name: public: virtual void CMemberFunctorCallback2<class CInputGameUI,class CHitArea __near *,wchar_t,class CFuncMemPolicyNone>::ComputeValidationString(char __near *,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctorCallback2<CInputGameUI,CHitArea *,wchar_t,CFuncMemPolicyNone>::ComputeValidationString(
        CMemberFunctorCallback2<CInputGameUI,CHitArea *,wchar_t,CFuncMemPolicyNone> *this,
        char *pString,
        unsigned int nBufLen)
{
  const char *v3; // eax
  const char *v4; // [esp-4h] [ebp-4h]

  v4 = type_info::name(this: &wchar_t `RTTI Type Descriptor', __ptype_info_node: &__type_info_root_node);
  v3 = type_info::name(this: &CHitArea * `RTTI Type Descriptor', __ptype_info_node: &__type_info_root_node);
  V_snprintf(pDest: pString, maxLen: nBufLen, pFormat: "method( %s, %s )", v3, v4);
}

//------------------------------------------------------------------------------
// Address: 0x00413F60
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<struct CInputGameUI::InputContext_t,unsigned int>,unsigned int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int>,unsigned int>::Grow(
        CUtlMemory<UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int>,unsigned int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int> *m_pMemory; // edx
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
    v7 = 1412 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int> *)_g_pMemAlloc->Realloc_2(
                                                                                            this: _g_pMemAlloc,
                                                                                            a2: m_pMemory,
                                                                                            a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int> *)_g_pMemAlloc->Alloc_2(
                                                                                            this: _g_pMemAlloc,
                                                                                            a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00413FF0
// Name: public: virtual int CRefCounted1<class CFunctorCallback,class CRefCountServiceBase<1,class CRefMT>>::AddRef(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT>>::AddRef(
        CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *this)
{
  return _InterlockedIncrement(&this->m_iRefs);
}

//------------------------------------------------------------------------------
// Address: 0x00414000
// Name: public: virtual int CRefCounted1<class CFunctorCallback,class CRefCountServiceBase<1,class CRefMT>>::Release(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT>>::Release(
        CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *this)
{
  CRefCountServiceBase<1,CRefMT> *v1; // esi
  int result; // eax

  v1 = &this->CRefCountServiceBase<1,CRefMT>;
  result = _InterlockedDecrement(&this->m_iRefs);
  if ( result == 0 )
  {
    if ( v1->OnFinalRelease(this: v1) )
      ((void (__thiscall *)(CRefCountServiceBase<1,CRefMT> *, int))v1->dtr_CRefCountServiceBase<1,CRefMT>)(
        a1: v1,
        a2: 1);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00414030
// Name: public: virtual void CInputGameUI::SetMouseCaptureEx(class CHitArea __near *,enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputGameUI::SetMouseCaptureEx(
        CInputGameUI *this,
        CHitArea *panel,
        ButtonCode_t captureStartMouseCode)
{
  unsigned int m_hContext; // eax

  this->SetMouseCapture(this, a2: panel);
  m_hContext = this->m_hContext;
  if ( m_hContext == -1 )
    this->m_DefaultInputContext.m_MouseCaptureStartCode = captureStartMouseCode;
  else
    this->m_Contexts.m_Memory.m_pMemory[m_hContext].m_Element.m_MouseCaptureStartCode = captureStartMouseCode;
}

//------------------------------------------------------------------------------
// Address: 0x00414080
// Name: public: virtual void CInputGameUI::SetMouseCapture(class CHitArea __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputGameUI::SetMouseCapture(CInputGameUI *this, CHitArea *panel)
{
  unsigned int m_hContext; // eax
  UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int> *v3; // eax

  m_hContext = this->m_hContext;
  if ( m_hContext == -1 )
  {
    this->m_DefaultInputContext.m_MouseCaptureStartCode = BUTTON_CODE_INVALID;
    this->m_DefaultInputContext._mouseCapture = panel;
  }
  else
  {
    v3 = &this->m_Contexts.m_Memory.m_pMemory[m_hContext];
    v3->m_Element.m_MouseCaptureStartCode = BUTTON_CODE_INVALID;
    v3->m_Element._mouseCapture = panel;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004140C0
// Name: public: virtual class CHitArea __near * CInputGameUI::GetMouseCapture(void)
// Source: json
//------------------------------------------------------------------------------
CHitArea *__thiscall CInputGameUI::GetMouseCapture(CInputGameUI *this)
{
  unsigned int m_hContext; // eax

  m_hContext = this->m_hContext;
  if ( m_hContext == -1 )
    return this->m_DefaultInputContext._mouseCapture;
  else
    return this->m_Contexts.m_Memory.m_pMemory[m_hContext].m_Element._mouseCapture;
}

//------------------------------------------------------------------------------
// Address: 0x004140F0
// Name: public: class CHitArea __near * CInputGameUI::GetKeyFocus(void)
// Source: json
//------------------------------------------------------------------------------
CHitArea *__thiscall CInputGameUI::GetKeyFocus(CInputGameUI *this)
{
  unsigned int m_hContext; // eax

  m_hContext = this->m_hContext;
  if ( m_hContext == -1 )
    return this->m_DefaultInputContext._keyFocus;
  else
    return this->m_Contexts.m_Memory.m_pMemory[m_hContext].m_Element._keyFocus;
}

//------------------------------------------------------------------------------
// Address: 0x00414120
// Name: public: virtual class CHitArea __near * CInputGameUI::GetMouseFocus(void)
// Source: json
//------------------------------------------------------------------------------
CHitArea *__thiscall CInputGameUI::GetMouseFocus(CInputGameUI *this)
{
  unsigned int m_hContext; // eax

  m_hContext = this->m_hContext;
  if ( m_hContext == -1 )
    return this->m_DefaultInputContext._mouseFocus;
  else
    return this->m_Contexts.m_Memory.m_pMemory[m_hContext].m_Element._mouseFocus;
}

//------------------------------------------------------------------------------
// Address: 0x00414150
// Name: public: virtual void CInputGameUI::GetCursorPosition(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputGameUI::GetCursorPosition(CInputGameUI *this, int *x, int *y)
{
  unsigned int m_hContext; // eax
  UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int> *p_m_DefaultInputContext; // eax

  m_hContext = this->m_hContext;
  if ( m_hContext == -1 )
    p_m_DefaultInputContext = (UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int> *)&this->m_DefaultInputContext;
  else
    p_m_DefaultInputContext = &this->m_Contexts.m_Memory.m_pMemory[m_hContext];
  *x = p_m_DefaultInputContext->m_Element.m_nCursorX;
  *y = p_m_DefaultInputContext->m_Element.m_nCursorY;
}

//------------------------------------------------------------------------------
// Address: 0x00414190
// Name: public: virtual void CInputGameUI::OnIMEEndComposition(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputGameUI::OnIMEEndComposition(CInputGameUI *this)
{
  unsigned int m_hContext; // eax
  UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int> *p_m_DefaultInputContext; // eax
  KeyValues *v4; // eax
  KeyValues *v5; // eax
  unsigned int v6; // edx
  UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int> *v7; // edx

  m_hContext = this->m_hContext;
  if ( m_hContext == -1 )
    p_m_DefaultInputContext = (UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int> *)&this->m_DefaultInputContext;
  else
    p_m_DefaultInputContext = &this->m_Contexts.m_Memory.m_pMemory[m_hContext];
  if ( p_m_DefaultInputContext != nullptr )
  {
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "DoCompositionString", firstKey: "string", firstValue: &firstValue);
    else
      v5 = nullptr;
    v6 = this->m_hContext;
    if ( v6 == -1 )
      v7 = (UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int> *)&this->m_DefaultInputContext;
    else
      v7 = &this->m_Contexts.m_Memory.m_pMemory[v6];
    if ( v7->m_Element._keyFocus == nullptr )
      KeyValues::deleteThis(this: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00414210
// Name: private: void CInputGameUI::InternalSetCompositionString(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputGameUI::InternalSetCompositionString(CInputGameUI *this, const wchar_t *compstr)
{
  unsigned int m_hContext; // eax
  UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int> *p_m_DefaultInputContext; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  unsigned int v7; // edx
  UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int> *v8; // edx

  m_hContext = this->m_hContext;
  if ( m_hContext == -1 )
    p_m_DefaultInputContext = (UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int> *)&this->m_DefaultInputContext;
  else
    p_m_DefaultInputContext = &this->m_Contexts.m_Memory.m_pMemory[m_hContext];
  if ( p_m_DefaultInputContext != nullptr )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "DoCompositionString", firstKey: "string", firstValue: compstr);
    else
      v6 = nullptr;
    v7 = this->m_hContext;
    if ( v7 == -1 )
      v8 = (UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int> *)&this->m_DefaultInputContext;
    else
      v8 = &this->m_Contexts.m_Memory.m_pMemory[v7];
    if ( v8->m_Element._keyFocus == nullptr )
      KeyValues::deleteThis(this: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004142A0
// Name: private: void CInputGameUI::InternalShowCandidateWindow(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputGameUI::InternalShowCandidateWindow(CInputGameUI *this)
{
  unsigned int m_hContext; // eax
  UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int> *p_m_DefaultInputContext; // eax
  KeyValues *v4; // eax
  KeyValues *v5; // eax
  unsigned int v6; // edx
  UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int> *v7; // edx

  m_hContext = this->m_hContext;
  if ( m_hContext == -1 )
    p_m_DefaultInputContext = (UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int> *)&this->m_DefaultInputContext;
  else
    p_m_DefaultInputContext = &this->m_Contexts.m_Memory.m_pMemory[m_hContext];
  if ( p_m_DefaultInputContext != nullptr )
  {
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "DoShowIMECandidates");
    else
      v5 = nullptr;
    v6 = this->m_hContext;
    if ( v6 == -1 )
      v7 = (UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int> *)&this->m_DefaultInputContext;
    else
      v7 = &this->m_Contexts.m_Memory.m_pMemory[v6];
    if ( v7->m_Element._keyFocus == nullptr )
      KeyValues::deleteThis(this: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00414320
// Name: private: void CInputGameUI::InternalHideCandidateWindow(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputGameUI::InternalHideCandidateWindow(CInputGameUI *this)
{
  unsigned int m_hContext; // eax
  UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int> *p_m_DefaultInputContext; // eax
  KeyValues *v4; // eax
  KeyValues *v5; // eax
  unsigned int v6; // edx
  UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int> *v7; // edx

  m_hContext = this->m_hContext;
  if ( m_hContext == -1 )
    p_m_DefaultInputContext = (UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int> *)&this->m_DefaultInputContext;
  else
    p_m_DefaultInputContext = &this->m_Contexts.m_Memory.m_pMemory[m_hContext];
  if ( p_m_DefaultInputContext != nullptr )
  {
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "DoHideIMECandidates");
    else
      v5 = nullptr;
    v6 = this->m_hContext;
    if ( v6 == -1 )
      v7 = (UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int> *)&this->m_DefaultInputContext;
    else
      v7 = &this->m_Contexts.m_Memory.m_pMemory[v6];
    if ( v7->m_Element._keyFocus == nullptr )
      KeyValues::deleteThis(this: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004143A0
// Name: private: void CInputGameUI::InternalUpdateCandidateWindow(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputGameUI::InternalUpdateCandidateWindow(CInputGameUI *this)
{
  unsigned int m_hContext; // eax
  UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int> *p_m_DefaultInputContext; // eax
  KeyValues *v4; // eax
  KeyValues *v5; // eax
  unsigned int v6; // edx
  UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int> *v7; // edx

  m_hContext = this->m_hContext;
  if ( m_hContext == -1 )
    p_m_DefaultInputContext = (UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int> *)&this->m_DefaultInputContext;
  else
    p_m_DefaultInputContext = &this->m_Contexts.m_Memory.m_pMemory[m_hContext];
  if ( p_m_DefaultInputContext != nullptr )
  {
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "DoUpdateIMECandidates");
    else
      v5 = nullptr;
    v6 = this->m_hContext;
    if ( v6 == -1 )
      v7 = (UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int> *)&this->m_DefaultInputContext;
    else
      v7 = &this->m_Contexts.m_Memory.m_pMemory[v6];
    if ( v7->m_Element._keyFocus == nullptr )
      KeyValues::deleteThis(this: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00414420
// Name: public: void CInputGameUI::OnMouseUp(class CHitArea __near * const __near &,class CHitArea __near * const __near &,enum ButtonCode_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputGameUI::OnMouseUp(CInputGameUI *this, CHitArea **pTarget, CHitArea **pTrap, ButtonCode_t *code)
{
  unsigned int m_hContext; // eax
  UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int> *p_m_DefaultInputContext; // eax
  ButtonCode_t v6; // edx

  m_hContext = this->m_hContext;
  if ( m_hContext == -1 )
    p_m_DefaultInputContext = (UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int> *)&this->m_DefaultInputContext;
  else
    p_m_DefaultInputContext = &this->m_Contexts.m_Memory.m_pMemory[m_hContext];
  v6 = *code;
  if ( *code == KEY_COUNT || v6 == MOUSE_MIDDLE || v6 == MOUSE_RIGHT )
    CHitArea::OnMouseUp(this: *pTarget, code, bFireScripts: *pTrap == p_m_DefaultInputContext->m_Element._mouseFocus);
}

//------------------------------------------------------------------------------
// Address: 0x00414480
// Name: public: virtual void CMemberFunctorCallback1<class CInputGameUI,class CHitArea __near *,class CFuncMemPolicyNone>::ComputeValidationString(char __near *,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctorCallback1<CInputGameUI,CHitArea *,CFuncMemPolicyNone>::ComputeValidationString(
        CMemberFunctorCallback1<CInputGameUI,CHitArea *,CFuncMemPolicyNone> *this,
        char *pString,
        unsigned int nBufLen)
{
  const char *v3; // eax

  v3 = type_info::name(this: &CHitArea * `RTTI Type Descriptor', __ptype_info_node: &__type_info_root_node);
  V_snprintf(pDest: pString, maxLen: nBufLen, pFormat: "method( %s )", v3);
}

//------------------------------------------------------------------------------
// Address: 0x004144B0
// Name: public: virtual char const __near * CMemberFunctorCallback1<class CInputGameUI,class CHitArea __near *,class CFuncMemPolicyNone>::GetImplClassName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CMemberFunctorCallback1<CInputGameUI,CHitArea *,CFuncMemPolicyNone>::GetImplClassName(
        CMemberFunctorCallback1<CInputGameUI,CHitArea *,CFuncMemPolicyNone> *this)
{
  return "CMemberFunctorCallback1";
}

//------------------------------------------------------------------------------
// Address: 0x004144C0
// Name: public: virtual bool CMemberFunctorCallback1<class CInputGameUI,class CHitArea __near *,class CFuncMemPolicyNone>::IsEqual(class CFunctorCallback __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMemberFunctorCallback1<CInputGameUI,CHitArea *,CFuncMemPolicyNone>::IsEqual(
        CMemberFunctorCallback2<CInputGameUI,CHitArea *,wchar_t,CFuncMemPolicyNone> *this,
        CFunctorCallback *pSrc)
{
  const char *v3; // eax
  const char *v5; // [esp-4h] [ebp-Ch]

  v5 = pSrc->GetImplClassName(this: pSrc);
  v3 = this->GetImplClassName(this);
  return _V_stricmp(s1: v3, s2: v5) == 0
      && this->m_Proxy.m_pfnProxied == (void (__thiscall *)(CInputGameUI *, CHitArea *const *, const wchar_t *))pSrc[3].__vftable
      && this->m_Proxy.m_pObject == (CInputGameUI *)pSrc[4].__vftable;
}

//------------------------------------------------------------------------------
// Address: 0x00414510
// Name: public: virtual void CMemberFunctorCallback1<class CInputGameUI,class CHitArea __near *,class CFuncMemPolicyNone>::operator()(class CFunctorData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctorCallback1<CInputGameUI,CHitArea *,CFuncMemPolicyNone>::operator()(
        CMemberFunctorCallback1<CInputGameUI,CHitArea *,CFuncMemPolicyNone> *this,
        CFunctorData *pFunctorDataBase)
{
  this->ValidateFunctorData(this, a2: pFunctorDataBase);
  this->m_Proxy.m_pfnProxied(this: this->m_Proxy.m_pObject, a2: (CHitArea *const *)&pFunctorDataBase[3]);
}

//------------------------------------------------------------------------------
// Address: 0x00414540
// Name: public: virtual char const __near * CMemberFunctorCallback3<class CInputGameUI,class CHitArea __near *,class CHitArea __near *,enum ButtonCode_t,class CFuncMemPolicyNone>::GetImplClassName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CMemberFunctorCallback3<CInputGameUI,CHitArea *,CHitArea *,enum ButtonCode_t,CFuncMemPolicyNone>::GetImplClassName(
        CMemberFunctorCallback3<CInputGameUI,CHitArea *,CHitArea *,enum ButtonCode_t,CFuncMemPolicyNone> *this)
{
  return "CMemberFunctorCallback3";
}

//------------------------------------------------------------------------------
// Address: 0x00414560
// Name: public: virtual void CMemberFunctorCallback3<class CInputGameUI,class CHitArea __near *,int,int,class CFuncMemPolicyNone>::operator()(class CFunctorData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctorCallback3<CInputGameUI,CHitArea *,int,int,CFuncMemPolicyNone>::operator()(
        CMemberFunctorCallback3<CInputGameUI,CHitArea *,CHitArea *,enum ButtonCode_t,CFuncMemPolicyNone> *this,
        CFunctorData *pFunctorDataBase)
{
  this->ValidateFunctorData(this, a2: pFunctorDataBase);
  this->m_Proxy.m_pfnProxied(
    this: this->m_Proxy.m_pObject,
    a2: (CHitArea *const *)&pFunctorDataBase[3],
    a3: (CHitArea *const *)&pFunctorDataBase[4],
    a4: (const ButtonCode_t *)&pFunctorDataBase[5]);
}

//------------------------------------------------------------------------------
// Address: 0x00414590
// Name: public: virtual char const __near * CMemberFunctorCallback2<class CInputGameUI,class CHitArea __near *,wchar_t,class CFuncMemPolicyNone>::GetImplClassName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CMemberFunctorCallback2<CInputGameUI,CHitArea *,wchar_t,CFuncMemPolicyNone>::GetImplClassName(
        CMemberFunctorCallback2<CInputGameUI,CHitArea *,wchar_t,CFuncMemPolicyNone> *this)
{
  return "CMemberFunctorCallback2";
}

//------------------------------------------------------------------------------
// Address: 0x004145A0
// Name: public: virtual void CFunctorData2<class CHitArea __near *,enum ButtonCode_t>::ComputeValidationString(char __near *,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFunctorData2<CHitArea *,enum ButtonCode_t>::ComputeValidationString(
        CMemberFunctorCallback2<CInputGameUI,CHitArea *,enum ButtonCode_t,CFuncMemPolicyNone> *this,
        char *pString,
        unsigned int nBufLen)
{
  const char *v3; // eax
  const char *v4; // [esp-4h] [ebp-4h]

  v4 = type_info::name(this: &enum ButtonCode_t `RTTI Type Descriptor', __ptype_info_node: &__type_info_root_node);
  v3 = type_info::name(this: &CHitArea * `RTTI Type Descriptor', __ptype_info_node: &__type_info_root_node);
  V_snprintf(pDest: pString, maxLen: nBufLen, pFormat: "method( %s, %s )", v3, v4);
}

//------------------------------------------------------------------------------
// Address: 0x004145E0
// Name: public: virtual void CMemberFunctorCallback2<class CInputGameUI,int,int,class CFuncMemPolicyNone>::operator()(class CFunctorData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctorCallback2<CInputGameUI,int,int,CFuncMemPolicyNone>::operator()(
        CMemberFunctorCallback2<CInputGameUI,CHitArea *,wchar_t,CFuncMemPolicyNone> *this,
        CFunctorData *pFunctorDataBase)
{
  this->ValidateFunctorData(this, a2: pFunctorDataBase);
  this->m_Proxy.m_pfnProxied(
    this: this->m_Proxy.m_pObject,
    a2: (CHitArea *const *)&pFunctorDataBase[3],
    a3: (const wchar_t *)&pFunctorDataBase[4]);
}

//------------------------------------------------------------------------------
// Address: 0x00414610
// Name: public: virtual void CMemberFunctorCallback3<class CInputGameUI,class CHitArea __near *,class CHitArea __near *,enum ButtonCode_t,class CFuncMemPolicyNone>::ComputeValidationString(char __near *,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctorCallback3<CInputGameUI,CHitArea *,CHitArea *,enum ButtonCode_t,CFuncMemPolicyNone>::ComputeValidationString(
        CMemberFunctorCallback3<CInputGameUI,CHitArea *,CHitArea *,enum ButtonCode_t,CFuncMemPolicyNone> *this,
        char *pString,
        unsigned int nBufLen)
{
  const char *v3; // eax
  const char *v4; // [esp-8h] [ebp-8h]
  const char *v5; // [esp-4h] [ebp-4h]

  v5 = type_info::name(this: &enum ButtonCode_t `RTTI Type Descriptor', __ptype_info_node: &__type_info_root_node);
  v4 = type_info::name(this: &CHitArea * `RTTI Type Descriptor', __ptype_info_node: &__type_info_root_node);
  v3 = type_info::name(this: &CHitArea * `RTTI Type Descriptor', __ptype_info_node: &__type_info_root_node);
  V_snprintf(pDest: pString, maxLen: nBufLen, pFormat: "method( %s, %s, %s )", v3, v4, v5);
}

//------------------------------------------------------------------------------
// Address: 0x00414660
// Name: public: virtual void const __near * CMemberFunctorCallback2<class CInputGameUI,class CHitArea __near *,int,class CFuncMemPolicyNone>::GetTarget(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMemberFunctorCallback2<CInputGameUI,CHitArea *,int,CFuncMemPolicyNone>::GetTarget(CVTFTexture *this)
{
  return this->m_nHeight;
}

//------------------------------------------------------------------------------
// Address: 0x004147D0
// Name: private: void CInputGameUI::InitInputContext(struct CInputGameUI::InputContext_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputGameUI::InitInputContext(CInputGameUI *this, CInputGameUI::InputContext_t *pContext)
{
  pContext->_keyFocus = nullptr;
  pContext->_bKeyTrap = false;
  pContext->_oldMouseFocus = nullptr;
  pContext->_mouseFocus = nullptr;
  pContext->_mouseOver = nullptr;
  pContext->_mouseCapture = nullptr;
  pContext->_mouseLeftTrap = nullptr;
  pContext->_mouseMiddleTrap = nullptr;
  pContext->_mouseRightTrap = nullptr;
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
  memset(dst: (int)pContext->_keyPressed, value: nullptr, count: sizeof(pContext->_keyPressed));
  memset(dst: (int)pContext->_keyTyped, value: nullptr, count: sizeof(pContext->_keyTyped));
  memset(dst: (int)pContext->_keyDown, value: nullptr, count: sizeof(pContext->_keyDown));
  memset(dst: (int)pContext->_keyReleased, value: nullptr, count: sizeof(pContext->_keyReleased));
  pContext->m_MouseCaptureStartCode = BUTTON_CODE_INVALID;
  pContext->m_KeyCodeUnhandledListeners.m_Size = 0;
  pContext->m_pUnhandledMouseClickListener = nullptr;
  pContext->m_bRestrictMessagesToModalSubTree = false;
}

//------------------------------------------------------------------------------
// Address: 0x004148D0
// Name: public: virtual void CInputGameUI::ResetInputContext(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputGameUI::ResetInputContext(CInputGameUI *this, unsigned int context)
{
  if ( context == -1 )
    CInputGameUI::InitInputContext(this, pContext: &this->m_DefaultInputContext);
  else
    CInputGameUI::InitInputContext(this, pContext: &this->m_Contexts.m_Memory.m_pMemory[context].m_Element);
}

//------------------------------------------------------------------------------
// Address: 0x00414900
// Name: public: void CInputGameUI::GraphicHidden(class CHitArea __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputGameUI::GraphicHidden(CInputGameUI *this, CHitArea *focus)
{
  unsigned int m_Head; // esi
  UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int> *m_pMemory; // eax
  int v5; // esi

  m_Head = this->m_Contexts.m_Head;
  if ( m_Head != -1 )
  {
    m_pMemory = this->m_Contexts.m_Memory.m_pMemory;
    do
    {
      v5 = m_Head;
      CInputGameUI::GraphicHidden(this, focus, context: &m_pMemory[v5].m_Element);
      m_pMemory = this->m_Contexts.m_Memory.m_pMemory;
      m_Head = m_pMemory[v5].m_Next;
    }
    while ( m_Head != -1 );
  }
  CInputGameUI::GraphicHidden(this, focus, context: &this->m_DefaultInputContext);
}

//------------------------------------------------------------------------------
// Address: 0x00414960
// Name: public: virtual void CInputGameUI::OnIMEShowCandidates(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputGameUI::OnIMEShowCandidates(CInputGameUI *this)
{
  if ( this->_imeCandidates != nullptr )
  {
    free(pMem: this->_imeCandidates);
    this->_imeCandidates = nullptr;
  }
  CInputGameUI::CreateNewCandidateList(this);
  CInputGameUI::InternalShowCandidateWindow(this);
}

//------------------------------------------------------------------------------
// Address: 0x00414990
// Name: public: virtual void CInputGameUI::OnIMECloseCandidates(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputGameUI::OnIMECloseCandidates(CInputGameUI *this)
{
  CInputGameUI::InternalHideCandidateWindow(this);
  if ( this->_imeCandidates != nullptr )
  {
    free(pMem: this->_imeCandidates);
    this->_imeCandidates = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004149C0
// Name: public: virtual void CInputGameUI::OnIMEChangeCandidates(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputGameUI::OnIMEChangeCandidates(CInputGameUI *this)
{
  if ( this->_imeCandidates != nullptr )
  {
    free(pMem: this->_imeCandidates);
    this->_imeCandidates = nullptr;
  }
  CInputGameUI::CreateNewCandidateList(this);
  CInputGameUI::InternalUpdateCandidateWindow(this);
}

//------------------------------------------------------------------------------
// Address: 0x004149F0
// Name: public: static void CEventSignature1<class CursorEnterEvent,class CHitArea __near *>::Post(class CHitArea __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CEventSignature1<CursorEnterEvent,CHitArea *>::Post(CFunctorData_vtbl **arg1)
{
  CFunctorData *v1; // eax
  CFunctorData *v2; // esi
  EventId_t__ *v3; // eax

  v1 = (CFunctorData *)MemAlloc_Alloc(nSize: 0x10u);
  if ( v1 != nullptr )
  {
    v1[2].__vftable = (CFunctorData_vtbl *)1;
    v1->__vftable = (CFunctorData_vtbl *)&CFunctorData1<CHitArea *>::`vftable'{for `CFunctorData'};
    v1[1].__vftable = (CFunctorData_vtbl *)&CFunctorData1<CHitArea *>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    v1[3].__vftable = *arg1;
    v2 = v1;
  }
  else
  {
    v2 = nullptr;
  }
  v3 = (EventId_t__ *)`CursorEnterEvent::GetEventId'::`2'::s_nEventId;
  if ( `CursorEnterEvent::GetEventId'::`2'::s_nEventId == 0 )
  {
    v3 = g_pEventSystem->RegisterEvent(this: g_pEventSystem, a2: "CursorEnterEvent");
    `CursorEnterEvent::GetEventId'::`2'::s_nEventId = (int)v3;
  }
  g_pEventSystem->PostEventInternal(this: g_pEventSystem, a2: v3, a3: nullptr, a4: nullptr, a5: v2);
}

//------------------------------------------------------------------------------
// Address: 0x00414A60
// Name: public: static void CEventSignature1<class CursorExitEvent,class CHitArea __near *>::Post(class CHitArea __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CEventSignature1<CursorExitEvent,CHitArea *>::Post(CFunctorData_vtbl **arg1)
{
  CFunctorData *v1; // eax
  CFunctorData *v2; // esi
  EventId_t__ *v3; // eax

  v1 = (CFunctorData *)MemAlloc_Alloc(nSize: 0x10u);
  if ( v1 != nullptr )
  {
    v1[2].__vftable = (CFunctorData_vtbl *)1;
    v1->__vftable = (CFunctorData_vtbl *)&CFunctorData1<CHitArea *>::`vftable'{for `CFunctorData'};
    v1[1].__vftable = (CFunctorData_vtbl *)&CFunctorData1<CHitArea *>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    v1[3].__vftable = *arg1;
    v2 = v1;
  }
  else
  {
    v2 = nullptr;
  }
  v3 = (EventId_t__ *)`CursorExitEvent::GetEventId'::`2'::s_nEventId;
  if ( `CursorExitEvent::GetEventId'::`2'::s_nEventId == 0 )
  {
    v3 = g_pEventSystem->RegisterEvent(this: g_pEventSystem, a2: "CursorExitEvent");
    `CursorExitEvent::GetEventId'::`2'::s_nEventId = (int)v3;
  }
  g_pEventSystem->PostEventInternal(this: g_pEventSystem, a2: v3, a3: nullptr, a4: nullptr, a5: v2);
}

//------------------------------------------------------------------------------
// Address: 0x00414AD0
// Name: public: static void CEventSignature3<class CursorMoveEvent,class CHitArea __near *,int,int>::Post(class CHitArea __near * const __near &,int const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CEventSignature3<CursorMoveEvent,CHitArea *,int,int>::Post(
        CFunctorData_vtbl **arg1,
        CFunctorData_vtbl **arg2,
        CFunctorData_vtbl **arg3)
{
  CFunctorData *v3; // eax
  CFunctorData *v4; // esi
  EventId_t__ *v5; // eax

  v3 = (CFunctorData *)MemAlloc_Alloc(nSize: 0x18u);
  if ( v3 != nullptr )
  {
    v3[2].__vftable = (CFunctorData_vtbl *)1;
    v3->__vftable = (CFunctorData_vtbl *)&CFunctorData3<CHitArea *,int,int>::`vftable'{for `CFunctorData'};
    v3[1].__vftable = (CFunctorData_vtbl *)&CFunctorData3<CHitArea *,int,int>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    v3[3].__vftable = *arg1;
    v3[4].__vftable = *arg2;
    v3[5].__vftable = *arg3;
    v4 = v3;
  }
  else
  {
    v4 = nullptr;
  }
  v5 = (EventId_t__ *)`CursorMoveEvent::GetEventId'::`2'::s_nEventId;
  if ( `CursorMoveEvent::GetEventId'::`2'::s_nEventId == 0 )
  {
    v5 = g_pEventSystem->RegisterEvent(this: g_pEventSystem, a2: "CursorMoveEvent");
    `CursorMoveEvent::GetEventId'::`2'::s_nEventId = (int)v5;
  }
  g_pEventSystem->PostEventInternal(this: g_pEventSystem, a2: v5, a3: nullptr, a4: nullptr, a5: v4);
}

//------------------------------------------------------------------------------
// Address: 0x00414B50
// Name: public: static void CEventSignature2<class InternalCursorMoveEvent,int,int>::Post(int const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CEventSignature2<InternalCursorMoveEvent,int,int>::Post(
        CFunctorData_vtbl **arg1,
        CFunctorData_vtbl **arg2)
{
  CFunctorData *v2; // eax
  CFunctorData *v3; // esi
  EventId_t__ *v4; // eax

  v2 = (CFunctorData *)MemAlloc_Alloc(nSize: 0x14u);
  if ( v2 != nullptr )
  {
    v2[2].__vftable = (CFunctorData_vtbl *)1;
    v2->__vftable = (CFunctorData_vtbl *)&CFunctorData2<int,int>::`vftable'{for `CFunctorData'};
    v2[1].__vftable = (CFunctorData_vtbl *)&CFunctorData2<int,int>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    v2[3].__vftable = *arg1;
    v2[4].__vftable = *arg2;
    v3 = v2;
  }
  else
  {
    v3 = nullptr;
  }
  v4 = (EventId_t__ *)`InternalCursorMoveEvent::GetEventId'::`2'::s_nEventId;
  if ( `InternalCursorMoveEvent::GetEventId'::`2'::s_nEventId == 0 )
  {
    v4 = g_pEventSystem->RegisterEvent(this: g_pEventSystem, a2: "InternalCursorMoveEvent");
    `InternalCursorMoveEvent::GetEventId'::`2'::s_nEventId = (int)v4;
  }
  g_pEventSystem->PostEventInternal(this: g_pEventSystem, a2: v4, a3: nullptr, a4: nullptr, a5: v3);
}

//------------------------------------------------------------------------------
// Address: 0x00414BC0
// Name: public: static void CEventSignature2<class MouseDownEvent,class CHitArea __near *,enum ButtonCode_t>::Post(class CHitArea __near * const __near &,enum ButtonCode_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CEventSignature2<MouseDownEvent,CHitArea *,enum ButtonCode_t>::Post(
        CFunctorData_vtbl **arg1,
        CFunctorData_vtbl **arg2)
{
  CFunctorData *v2; // eax
  CFunctorData *v3; // esi
  EventId_t__ *v4; // eax

  v2 = (CFunctorData *)MemAlloc_Alloc(nSize: 0x14u);
  if ( v2 != nullptr )
  {
    v2[2].__vftable = (CFunctorData_vtbl *)1;
    v2->__vftable = (CFunctorData_vtbl *)&CFunctorData2<CHitArea *,enum ButtonCode_t>::`vftable'{for `CFunctorData'};
    v2[1].__vftable = (CFunctorData_vtbl *)&CFunctorData2<CHitArea *,enum ButtonCode_t>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    v2[3].__vftable = *arg1;
    v2[4].__vftable = *arg2;
    v3 = v2;
  }
  else
  {
    v3 = nullptr;
  }
  v4 = (EventId_t__ *)`MouseDownEvent::GetEventId'::`2'::s_nEventId;
  if ( `MouseDownEvent::GetEventId'::`2'::s_nEventId == 0 )
  {
    v4 = g_pEventSystem->RegisterEvent(this: g_pEventSystem, a2: "MouseDownEvent");
    `MouseDownEvent::GetEventId'::`2'::s_nEventId = (int)v4;
  }
  g_pEventSystem->PostEventInternal(this: g_pEventSystem, a2: v4, a3: nullptr, a4: nullptr, a5: v3);
}

//------------------------------------------------------------------------------
// Address: 0x00414C30
// Name: public: static void CEventSignature3<class MouseUpEvent,class CHitArea __near *,class CHitArea __near *,enum ButtonCode_t>::Post(class CHitArea __near * const __near &,class CHitArea __near * const __near &,enum ButtonCode_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CEventSignature3<MouseUpEvent,CHitArea *,CHitArea *,enum ButtonCode_t>::Post(
        CFunctorData_vtbl **arg1,
        CFunctorData_vtbl **arg2,
        CFunctorData_vtbl **arg3)
{
  CFunctorData *v3; // eax
  CFunctorData *v4; // esi
  EventId_t__ *v5; // eax

  v3 = (CFunctorData *)MemAlloc_Alloc(nSize: 0x18u);
  if ( v3 != nullptr )
  {
    v3[2].__vftable = (CFunctorData_vtbl *)1;
    v3->__vftable = (CFunctorData_vtbl *)&CFunctorData3<CHitArea *,CHitArea *,enum ButtonCode_t>::`vftable'{for `CFunctorData'};
    v3[1].__vftable = (CFunctorData_vtbl *)&CFunctorData3<CHitArea *,CHitArea *,enum ButtonCode_t>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    v3[3].__vftable = *arg1;
    v3[4].__vftable = *arg2;
    v3[5].__vftable = *arg3;
    v4 = v3;
  }
  else
  {
    v4 = nullptr;
  }
  v5 = (EventId_t__ *)`MouseUpEvent::GetEventId'::`2'::s_nEventId;
  if ( `MouseUpEvent::GetEventId'::`2'::s_nEventId == 0 )
  {
    v5 = g_pEventSystem->RegisterEvent(this: g_pEventSystem, a2: "MouseUpEvent");
    `MouseUpEvent::GetEventId'::`2'::s_nEventId = (int)v5;
  }
  g_pEventSystem->PostEventInternal(this: g_pEventSystem, a2: v5, a3: nullptr, a4: nullptr, a5: v4);
}

//------------------------------------------------------------------------------
// Address: 0x00414CB0
// Name: public: static void CEventSignature2<class MouseDoubleClickEvent,class CHitArea __near *,enum ButtonCode_t>::Post(class CHitArea __near * const __near &,enum ButtonCode_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CEventSignature2<MouseDoubleClickEvent,CHitArea *,enum ButtonCode_t>::Post(
        CFunctorData_vtbl **arg1,
        CFunctorData_vtbl **arg2)
{
  CFunctorData *v2; // eax
  CFunctorData *v3; // esi
  EventId_t__ *v4; // eax

  v2 = (CFunctorData *)MemAlloc_Alloc(nSize: 0x14u);
  if ( v2 != nullptr )
  {
    v2[2].__vftable = (CFunctorData_vtbl *)1;
    v2->__vftable = (CFunctorData_vtbl *)&CFunctorData2<CHitArea *,enum ButtonCode_t>::`vftable'{for `CFunctorData'};
    v2[1].__vftable = (CFunctorData_vtbl *)&CFunctorData2<CHitArea *,enum ButtonCode_t>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    v2[3].__vftable = *arg1;
    v2[4].__vftable = *arg2;
    v3 = v2;
  }
  else
  {
    v3 = nullptr;
  }
  v4 = (EventId_t__ *)`MouseDoubleClickEvent::GetEventId'::`2'::s_nEventId;
  if ( `MouseDoubleClickEvent::GetEventId'::`2'::s_nEventId == 0 )
  {
    v4 = g_pEventSystem->RegisterEvent(this: g_pEventSystem, a2: "MouseDoubleClickEvent");
    `MouseDoubleClickEvent::GetEventId'::`2'::s_nEventId = (int)v4;
  }
  g_pEventSystem->PostEventInternal(this: g_pEventSystem, a2: v4, a3: nullptr, a4: nullptr, a5: v3);
}

//------------------------------------------------------------------------------
// Address: 0x00414D20
// Name: public: static void CEventSignature2<class MouseWheelEvent,class CHitArea __near *,int>::Post(class CHitArea __near * const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CEventSignature2<MouseWheelEvent,CHitArea *,int>::Post(CFunctorData_vtbl **arg1, CFunctorData_vtbl **arg2)
{
  CFunctorData *v2; // eax
  CFunctorData *v3; // esi
  EventId_t__ *v4; // eax

  v2 = (CFunctorData *)MemAlloc_Alloc(nSize: 0x14u);
  if ( v2 != nullptr )
  {
    v2[2].__vftable = (CFunctorData_vtbl *)1;
    v2->__vftable = (CFunctorData_vtbl *)&CFunctorData2<CHitArea *,int>::`vftable'{for `CFunctorData'};
    v2[1].__vftable = (CFunctorData_vtbl *)&CFunctorData2<CHitArea *,int>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    v2[3].__vftable = *arg1;
    v2[4].__vftable = *arg2;
    v3 = v2;
  }
  else
  {
    v3 = nullptr;
  }
  v4 = (EventId_t__ *)`MouseWheelEvent::GetEventId'::`2'::s_nEventId;
  if ( `MouseWheelEvent::GetEventId'::`2'::s_nEventId == 0 )
  {
    v4 = g_pEventSystem->RegisterEvent(this: g_pEventSystem, a2: "MouseWheelEvent");
    `MouseWheelEvent::GetEventId'::`2'::s_nEventId = (int)v4;
  }
  g_pEventSystem->PostEventInternal(this: g_pEventSystem, a2: v4, a3: nullptr, a4: nullptr, a5: v3);
}

//------------------------------------------------------------------------------
// Address: 0x00414D90
// Name: public: static void CEventSignature2<class KeyDownEvent,class CHitArea __near *,enum ButtonCode_t>::Post(class CHitArea __near * const __near &,enum ButtonCode_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CEventSignature2<KeyDownEvent,CHitArea *,enum ButtonCode_t>::Post(
        CFunctorData_vtbl **arg1,
        CFunctorData_vtbl **arg2)
{
  CFunctorData *v2; // eax
  CFunctorData *v3; // esi
  EventId_t__ *v4; // eax

  v2 = (CFunctorData *)MemAlloc_Alloc(nSize: 0x14u);
  if ( v2 != nullptr )
  {
    v2[2].__vftable = (CFunctorData_vtbl *)1;
    v2->__vftable = (CFunctorData_vtbl *)&CFunctorData2<CHitArea *,enum ButtonCode_t>::`vftable'{for `CFunctorData'};
    v2[1].__vftable = (CFunctorData_vtbl *)&CFunctorData2<CHitArea *,enum ButtonCode_t>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    v2[3].__vftable = *arg1;
    v2[4].__vftable = *arg2;
    v3 = v2;
  }
  else
  {
    v3 = nullptr;
  }
  v4 = (EventId_t__ *)`KeyDownEvent::GetEventId'::`2'::s_nEventId;
  if ( `KeyDownEvent::GetEventId'::`2'::s_nEventId == 0 )
  {
    v4 = g_pEventSystem->RegisterEvent(this: g_pEventSystem, a2: "KeyDownEvent");
    `KeyDownEvent::GetEventId'::`2'::s_nEventId = (int)v4;
  }
  g_pEventSystem->PostEventInternal(this: g_pEventSystem, a2: v4, a3: nullptr, a4: nullptr, a5: v3);
}

//------------------------------------------------------------------------------
// Address: 0x00414E00
// Name: public: static void CEventSignature2<class KeyUpEvent,class CHitArea __near *,enum ButtonCode_t>::Post(class CHitArea __near * const __near &,enum ButtonCode_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CEventSignature2<KeyUpEvent,CHitArea *,enum ButtonCode_t>::Post(
        CFunctorData_vtbl **arg1,
        CFunctorData_vtbl **arg2)
{
  CFunctorData *v2; // eax
  CFunctorData *v3; // esi
  EventId_t__ *v4; // eax

  v2 = (CFunctorData *)MemAlloc_Alloc(nSize: 0x14u);
  if ( v2 != nullptr )
  {
    v2[2].__vftable = (CFunctorData_vtbl *)1;
    v2->__vftable = (CFunctorData_vtbl *)&CFunctorData2<CHitArea *,enum ButtonCode_t>::`vftable'{for `CFunctorData'};
    v2[1].__vftable = (CFunctorData_vtbl *)&CFunctorData2<CHitArea *,enum ButtonCode_t>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    v2[3].__vftable = *arg1;
    v2[4].__vftable = *arg2;
    v3 = v2;
  }
  else
  {
    v3 = nullptr;
  }
  v4 = (EventId_t__ *)`KeyUpEvent::GetEventId'::`2'::s_nEventId;
  if ( `KeyUpEvent::GetEventId'::`2'::s_nEventId == 0 )
  {
    v4 = g_pEventSystem->RegisterEvent(this: g_pEventSystem, a2: "KeyUpEvent");
    `KeyUpEvent::GetEventId'::`2'::s_nEventId = (int)v4;
  }
  g_pEventSystem->PostEventInternal(this: g_pEventSystem, a2: v4, a3: nullptr, a4: nullptr, a5: v3);
}

//------------------------------------------------------------------------------
// Address: 0x00414E70
// Name: public: static void CEventSignature2<class KeyCodeTypedEvent,class CHitArea __near *,enum ButtonCode_t>::Post(class CHitArea __near * const __near &,enum ButtonCode_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CEventSignature2<KeyCodeTypedEvent,CHitArea *,enum ButtonCode_t>::Post(
        CFunctorData_vtbl **arg1,
        CFunctorData_vtbl **arg2)
{
  CFunctorData *v2; // eax
  CFunctorData *v3; // esi
  EventId_t__ *v4; // eax

  v2 = (CFunctorData *)MemAlloc_Alloc(nSize: 0x14u);
  if ( v2 != nullptr )
  {
    v2[2].__vftable = (CFunctorData_vtbl *)1;
    v2->__vftable = (CFunctorData_vtbl *)&CFunctorData2<CHitArea *,enum ButtonCode_t>::`vftable'{for `CFunctorData'};
    v2[1].__vftable = (CFunctorData_vtbl *)&CFunctorData2<CHitArea *,enum ButtonCode_t>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    v2[3].__vftable = *arg1;
    v2[4].__vftable = *arg2;
    v3 = v2;
  }
  else
  {
    v3 = nullptr;
  }
  v4 = (EventId_t__ *)`KeyCodeTypedEvent::GetEventId'::`2'::s_nEventId;
  if ( `KeyCodeTypedEvent::GetEventId'::`2'::s_nEventId == 0 )
  {
    v4 = g_pEventSystem->RegisterEvent(this: g_pEventSystem, a2: "KeyCodeTypedEvent");
    `KeyCodeTypedEvent::GetEventId'::`2'::s_nEventId = (int)v4;
  }
  g_pEventSystem->PostEventInternal(this: g_pEventSystem, a2: v4, a3: nullptr, a4: nullptr, a5: v3);
}

//------------------------------------------------------------------------------
// Address: 0x00414EE0
// Name: public: static void CEventSignature2<class KeyTypedEvent,class CHitArea __near *,wchar_t>::Post(class CHitArea __near * const __near &,wchar_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CEventSignature2<KeyTypedEvent,CHitArea *,wchar_t>::Post(CFunctorData_vtbl **arg1, const wchar_t *arg2)
{
  CFunctorData *v2; // eax
  CFunctorData *v3; // esi
  EventId_t__ *v4; // eax

  v2 = (CFunctorData *)MemAlloc_Alloc(nSize: 0x14u);
  if ( v2 != nullptr )
  {
    v2[2].__vftable = (CFunctorData_vtbl *)1;
    v2->__vftable = (CFunctorData_vtbl *)&CFunctorData2<CHitArea *,wchar_t>::`vftable'{for `CFunctorData'};
    v2[1].__vftable = (CFunctorData_vtbl *)&CFunctorData2<CHitArea *,wchar_t>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    v2[3].__vftable = *arg1;
    LOWORD(v2[4].__vftable) = *arg2;
    v3 = v2;
  }
  else
  {
    v3 = nullptr;
  }
  v4 = (EventId_t__ *)`KeyTypedEvent::GetEventId'::`2'::s_nEventId;
  if ( `KeyTypedEvent::GetEventId'::`2'::s_nEventId == 0 )
  {
    v4 = g_pEventSystem->RegisterEvent(this: g_pEventSystem, a2: "KeyTypedEvent");
    `KeyTypedEvent::GetEventId'::`2'::s_nEventId = (int)v4;
  }
  g_pEventSystem->PostEventInternal(this: g_pEventSystem, a2: v4, a3: nullptr, a4: nullptr, a5: v3);
}

//------------------------------------------------------------------------------
// Address: 0x00415060
// Name: private: void CInputGameUI::PanelDeleted(class CHitArea __near *,struct CInputGameUI::InputContext_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputGameUI::PanelDeleted(CInputGameUI *this, CHitArea *focus, CInputGameUI::InputContext_t *context)
{
  CInputGameUI::InputContext_t *v3; // esi
  CHitArea *v4; // edi

  v3 = context;
  v4 = focus;
  if ( context->_keyFocus == focus )
  {
    context->_keyFocus = nullptr;
    v3->_bKeyTrap = false;
  }
  if ( v3->_mouseOver == v4 )
    v3->_mouseOver = nullptr;
  if ( v3->_oldMouseFocus == v4 )
    v3->_oldMouseFocus = nullptr;
  if ( v3->_mouseFocus == v4 )
    v3->_mouseFocus = nullptr;
  if ( v3->_mouseLeftTrap == v4 )
    v3->_mouseLeftTrap = nullptr;
  if ( v3->_mouseMiddleTrap == v4 )
    v3->_mouseMiddleTrap = nullptr;
  if ( v3->_mouseRightTrap == v4 )
    v3->_mouseRightTrap = nullptr;
  if ( v3->_mouseCapture == v4 )
  {
    this->SetMouseCapture(this, a2: nullptr);
    v3->_mouseCapture = nullptr;
  }
  if ( v3->m_pUnhandledMouseClickListener == v4 )
    v3->m_pUnhandledMouseClickListener = nullptr;
  CUtlVector<CHitArea *,CUtlMemory<CHitArea *,int>>::FindAndRemove(
    this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&v3->m_KeyCodeUnhandledListeners,
    src: (vgui::TreeNode **)&focus);
}

//------------------------------------------------------------------------------
// Address: 0x00415120
// Name: public: void CInputGameUI::PanelDeleted(class CHitArea __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputGameUI::PanelDeleted(CInputGameUI *this, CHitArea *focus)
{
  unsigned int m_Head; // esi
  UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int> *m_pMemory; // eax
  int v5; // esi

  m_Head = this->m_Contexts.m_Head;
  if ( m_Head != -1 )
  {
    m_pMemory = this->m_Contexts.m_Memory.m_pMemory;
    do
    {
      v5 = m_Head;
      CInputGameUI::PanelDeleted(this, focus, context: &m_pMemory[v5].m_Element);
      m_pMemory = this->m_Contexts.m_Memory.m_pMemory;
      m_Head = m_pMemory[v5].m_Next;
    }
    while ( m_Head != -1 );
  }
  CInputGameUI::PanelDeleted(this, focus, context: &this->m_DefaultInputContext);
}

//------------------------------------------------------------------------------
// Address: 0x00415180
// Name: public: void CInputGameUI::SetMouseFocus(class CHitArea __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputGameUI::SetMouseFocus(CInputGameUI *this, CHitArea *newMouseFocus)
{
  unsigned int m_hContext; // esi
  UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int> *p_m_DefaultInputContext; // esi
  CHitArea *mouseOver; // ecx
  CHitArea **p_mouseOver; // edi
  CHitArea *mouseCapture; // edx
  CHitArea *v7; // eax
  CHitArea *v8; // eax

  m_hContext = this->m_hContext;
  if ( m_hContext == -1 )
    p_m_DefaultInputContext = (UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int> *)&this->m_DefaultInputContext;
  else
    p_m_DefaultInputContext = &this->m_Contexts.m_Memory.m_pMemory[m_hContext];
  mouseOver = p_m_DefaultInputContext->m_Element._mouseOver;
  p_mouseOver = &p_m_DefaultInputContext->m_Element._mouseOver;
  if ( mouseOver != newMouseFocus
    || p_m_DefaultInputContext->m_Element._mouseCapture == nullptr
    && p_m_DefaultInputContext->m_Element._mouseFocus != newMouseFocus )
  {
    p_m_DefaultInputContext->m_Element._oldMouseFocus = mouseOver;
    *p_mouseOver = newMouseFocus;
    if ( mouseOver != nullptr )
    {
      mouseCapture = p_m_DefaultInputContext->m_Element._mouseCapture;
      if ( mouseCapture == nullptr || mouseOver == mouseCapture )
        CEventSignature1<CursorExitEvent,CHitArea *>::Post(arg1: (CFunctorData_vtbl **)&p_m_DefaultInputContext->m_Element._oldMouseFocus);
    }
    if ( *p_mouseOver != nullptr )
    {
      v7 = p_m_DefaultInputContext->m_Element._mouseCapture;
      if ( v7 == nullptr || *p_mouseOver == v7 )
        CEventSignature1<CursorEnterEvent,CHitArea *>::Post(arg1: (CFunctorData_vtbl **)&p_m_DefaultInputContext->m_Element._mouseOver);
    }
    v8 = p_m_DefaultInputContext->m_Element._mouseCapture;
    if ( v8 == nullptr )
      v8 = *p_mouseOver;
    p_m_DefaultInputContext->m_Element._mouseFocus = v8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00415220
// Name: public: void CInputGameUI::UpdateCursorPosInternal(int const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputGameUI::UpdateCursorPosInternal(CInputGameUI *this, int *x, int y)
{
  unsigned int m_hContext; // esi
  UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int> *p_m_DefaultInputContext; // esi
  int *v6; // edi
  CHitArea *MouseFocus; // eax
  int windowWidth; // [esp+Ch] [ebp-Ch] BYREF
  int viewportWidth; // [esp+10h] [ebp-8h] BYREF
  int nWidth; // [esp+14h] [ebp-4h] BYREF

  m_hContext = this->m_hContext;
  if ( m_hContext == -1 )
    p_m_DefaultInputContext = (UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int> *)&this->m_DefaultInputContext;
  else
    p_m_DefaultInputContext = &this->m_Contexts.m_Memory.m_pMemory[m_hContext];
  v6 = (int *)y;
  if ( p_m_DefaultInputContext->m_Element.m_nCursorX != *x
    || p_m_DefaultInputContext->m_Element.m_nCursorY != *(_DWORD *)y )
  {
    p_m_DefaultInputContext->m_Element.m_nCursorX = *x;
    p_m_DefaultInputContext->m_Element.m_nCursorY = *v6;
    CGameUISystemMgr::GetWindowSize(this: g_pGameUISystemMgrImpl, nWidth: &viewportWidth, nHeight: &windowWidth);
    CGameUISystemMgr::GetViewportSize(this: g_pGameUISystemMgrImpl, &nWidth, nHeight: &y);
    if ( windowWidth != 0 && y != 0 && (viewportWidth != nWidth || windowWidth != y) )
    {
      p_m_DefaultInputContext->m_Element.m_nCursorX = nWidth * *x / viewportWidth;
      p_m_DefaultInputContext->m_Element.m_nCursorY = y * *v6 / windowWidth;
    }
    MouseFocus = CGameUISystemMgr::GetMouseFocus(
                   this: g_pGameUISystemMgrImpl,
                   x: p_m_DefaultInputContext->m_Element.m_nCursorX,
                   y: p_m_DefaultInputContext->m_Element.m_nCursorY);
    CInputGameUI::SetMouseFocus(this, newMouseFocus: MouseFocus);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00415310
// Name: public: bool CInputGameUI::InternalCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CInputGameUI::InternalCursorMoved(CInputGameUI *this, int x, int y)
{
  CEventSignature2<InternalCursorMoveEvent,int,int>::Post(
    arg1: (CFunctorData_vtbl **)&x,
    arg2: (CFunctorData_vtbl **)&y);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00415330
// Name: public: virtual void CInputGameUI::HandleExplicitSetCursor(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputGameUI::HandleExplicitSetCursor(CInputGameUI *this)
{
  unsigned int m_hContext; // esi
  UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int> *p_m_DefaultInputContext; // esi
  int m_nExternallySetCursorY; // ecx
  int m_nExternallySetCursorX; // eax
  IInputStackSystem_vtbl *v6; // edi
  InputContextHandle_t__ *InputContext; // eax
  CHitArea *MouseFocus; // eax
  int v9; // [esp-Ch] [ebp-14h]
  int v10; // [esp-8h] [ebp-10h]

  m_hContext = this->m_hContext;
  if ( m_hContext == -1 )
    p_m_DefaultInputContext = (UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int> *)&this->m_DefaultInputContext;
  else
    p_m_DefaultInputContext = &this->m_Contexts.m_Memory.m_pMemory[m_hContext];
  if ( p_m_DefaultInputContext->m_Element.m_bSetCursorExplicitly )
  {
    m_nExternallySetCursorY = p_m_DefaultInputContext->m_Element.m_nExternallySetCursorY;
    m_nExternallySetCursorX = p_m_DefaultInputContext->m_Element.m_nExternallySetCursorX;
    p_m_DefaultInputContext->m_Element.m_nCursorX = m_nExternallySetCursorX;
    p_m_DefaultInputContext->m_Element.m_nCursorY = m_nExternallySetCursorY;
    p_m_DefaultInputContext->m_Element.m_bSetCursorExplicitly = false;
    p_m_DefaultInputContext->m_Element.m_nLastPostedCursorY = -9999;
    p_m_DefaultInputContext->m_Element.m_nLastPostedCursorX = -9999;
    v6 = g_pInputStackSystem->__vftable;
    v10 = m_nExternallySetCursorY;
    v9 = m_nExternallySetCursorX;
    InputContext = CGameUISystemMgr::GetInputContext(this: g_pGameUISystemMgrImpl);
    v6->SetCursorPosition(this: g_pInputStackSystem, a2: InputContext, a3: v9, a4: v10);
    MouseFocus = CGameUISystemMgr::GetMouseFocus(
                   this: g_pGameUISystemMgrImpl,
                   x: p_m_DefaultInputContext->m_Element.m_nCursorX,
                   y: p_m_DefaultInputContext->m_Element.m_nCursorY);
    CInputGameUI::SetMouseFocus(this, newMouseFocus: MouseFocus);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004153E0
// Name: public: virtual void CInputGameUI::PostCursorMessage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputGameUI::PostCursorMessage(CInputGameUI *this)
{
  unsigned int m_hContext; // eax
  UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int> *p_m_DefaultInputContext; // eax
  int m_nExternallySetCursorY; // edx
  int m_nCursorX; // ecx
  CFunctorData_vtbl **p_m_nCursorX; // esi
  bool v6; // zf
  int m_nCursorY; // edx
  CFunctorData_vtbl **p_m_nCursorY; // ecx
  CFunctorData_vtbl **p_mouseFocus; // eax

  m_hContext = this->m_hContext;
  if ( m_hContext == -1 )
    p_m_DefaultInputContext = (UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int> *)&this->m_DefaultInputContext;
  else
    p_m_DefaultInputContext = &this->m_Contexts.m_Memory.m_pMemory[m_hContext];
  if ( p_m_DefaultInputContext->m_Element.m_bSetCursorExplicitly )
  {
    m_nExternallySetCursorY = p_m_DefaultInputContext->m_Element.m_nExternallySetCursorY;
    p_m_DefaultInputContext->m_Element.m_nCursorX = p_m_DefaultInputContext->m_Element.m_nExternallySetCursorX;
    p_m_DefaultInputContext->m_Element.m_nCursorY = m_nExternallySetCursorY;
  }
  m_nCursorX = p_m_DefaultInputContext->m_Element.m_nCursorX;
  p_m_nCursorX = (CFunctorData_vtbl **)&p_m_DefaultInputContext->m_Element.m_nCursorX;
  if ( p_m_DefaultInputContext->m_Element.m_nLastPostedCursorX != m_nCursorX
    || p_m_DefaultInputContext->m_Element.m_nLastPostedCursorY != p_m_DefaultInputContext->m_Element.m_nCursorY )
  {
    v6 = p_m_DefaultInputContext->m_Element._mouseCapture == nullptr;
    m_nCursorY = p_m_DefaultInputContext->m_Element.m_nCursorY;
    p_m_DefaultInputContext->m_Element.m_nLastPostedCursorX = m_nCursorX;
    p_m_nCursorY = (CFunctorData_vtbl **)&p_m_DefaultInputContext->m_Element.m_nCursorY;
    p_m_DefaultInputContext->m_Element.m_nLastPostedCursorY = m_nCursorY;
    if ( v6 )
    {
      p_mouseFocus = (CFunctorData_vtbl **)&p_m_DefaultInputContext->m_Element._mouseFocus;
      if ( *p_mouseFocus != nullptr )
        CEventSignature3<CursorMoveEvent,CHitArea *,int,int>::Post(
          arg1: p_mouseFocus,
          arg2: p_m_nCursorX,
          arg3: p_m_nCursorY);
    }
    else
    {
      CEventSignature3<CursorMoveEvent,CHitArea *,int,int>::Post(
        arg1: (CFunctorData_vtbl **)&p_m_DefaultInputContext->m_Element._mouseCapture,
        arg2: (CFunctorData_vtbl **)&p_m_DefaultInputContext->m_Element.m_nCursorX,
        arg3: (CFunctorData_vtbl **)&p_m_DefaultInputContext->m_Element.m_nCursorY);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00415490
// Name: public: bool CInputGameUI::InternalMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CInputGameUI::InternalMousePressed(CInputGameUI *this, ButtonCode_t code)
{
  unsigned int m_hContext; // ecx
  bool result; // al
  UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int> *p_m_DefaultInputContext; // esi
  CFunctorData_vtbl **p_mouseCapture; // ecx
  ButtonCode_t m_MouseCaptureStartCode; // esi
  bool v8; // bl
  CHitArea **p_mouseFocus; // edi
  ButtonCode_t v10; // ebx

  m_hContext = this->m_hContext;
  result = false;
  if ( m_hContext == -1 )
    p_m_DefaultInputContext = (UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int> *)&this->m_DefaultInputContext;
  else
    p_m_DefaultInputContext = &this->m_Contexts.m_Memory.m_pMemory[m_hContext];
  p_mouseCapture = (CFunctorData_vtbl **)&p_m_DefaultInputContext->m_Element._mouseCapture;
  if ( p_m_DefaultInputContext->m_Element._mouseCapture != nullptr )
  {
    if ( code != MOUSE_WHEEL_DOWN && code != MOUSE_WHEEL_UP )
    {
      m_MouseCaptureStartCode = p_m_DefaultInputContext->m_Element.m_MouseCaptureStartCode;
      v8 = code == m_MouseCaptureStartCode || m_MouseCaptureStartCode == BUTTON_CODE_INVALID;
      CEventSignature2<MouseDownEvent,CHitArea *,enum ButtonCode_t>::Post(
        arg1: p_mouseCapture,
        arg2: (CFunctorData_vtbl **)&code);
      if ( v8 )
      {
        this->SetMouseCapture(this, a2: nullptr);
        return true;
      }
    }
  }
  else
  {
    p_mouseFocus = &p_m_DefaultInputContext->m_Element._mouseFocus;
    if ( p_m_DefaultInputContext->m_Element._mouseFocus == nullptr )
      return result;
    v10 = code;
    if ( code != MOUSE_WHEEL_DOWN && code != MOUSE_WHEEL_UP )
    {
      CEventSignature2<MouseDownEvent,CHitArea *,enum ButtonCode_t>::Post(
        arg1: (CFunctorData_vtbl **)&p_m_DefaultInputContext->m_Element._mouseFocus,
        arg2: (CFunctorData_vtbl **)&code);
      switch ( v10 )
      {
        case KEY_COUNT:
          p_m_DefaultInputContext->m_Element._mouseLeftTrap = *p_mouseFocus;
          return true;
        case MOUSE_MIDDLE:
          p_m_DefaultInputContext->m_Element._mouseMiddleTrap = *p_mouseFocus;
          return true;
        case MOUSE_RIGHT:
          p_m_DefaultInputContext->m_Element._mouseRightTrap = *p_mouseFocus;
          break;
        default:
          break;
      }
    }
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x00415590
// Name: public: bool CInputGameUI::InternalMouseDoublePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CInputGameUI::InternalMouseDoublePressed(CInputGameUI *this, ButtonCode_t code)
{
  unsigned int m_hContext; // edx
  bool result; // al
  UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int> *p_m_DefaultInputContext; // edx

  m_hContext = this->m_hContext;
  result = false;
  if ( m_hContext == -1 )
    p_m_DefaultInputContext = (UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int> *)&this->m_DefaultInputContext;
  else
    p_m_DefaultInputContext = &this->m_Contexts.m_Memory.m_pMemory[m_hContext];
  if ( p_m_DefaultInputContext->m_Element._mouseCapture != nullptr )
  {
    if ( code != MOUSE_WHEEL_DOWN && code != MOUSE_WHEEL_UP )
    {
      CEventSignature2<MouseDoubleClickEvent,CHitArea *,enum ButtonCode_t>::Post(
        arg1: (CFunctorData_vtbl **)&p_m_DefaultInputContext->m_Element._mouseCapture,
        arg2: (CFunctorData_vtbl **)&code);
      return true;
    }
  }
  else
  {
    if ( p_m_DefaultInputContext->m_Element._mouseFocus == nullptr )
      return result;
    if ( code != MOUSE_WHEEL_DOWN && code != MOUSE_WHEEL_UP )
      CEventSignature2<MouseDoubleClickEvent,CHitArea *,enum ButtonCode_t>::Post(
        arg1: (CFunctorData_vtbl **)&p_m_DefaultInputContext->m_Element._mouseFocus,
        arg2: (CFunctorData_vtbl **)&code);
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x00415620
// Name: public: bool CInputGameUI::InternalMouseReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CInputGameUI::InternalMouseReleased(CInputGameUI *this, ButtonCode_t code)
{
  unsigned int m_hContext; // edx
  bool result; // al
  UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int> *p_m_DefaultInputContext; // edx
  CFunctorData_vtbl **p_mouseLeftTrap; // esi
  CFunctorData_vtbl **p_mouseMiddleTrap; // edi

  m_hContext = this->m_hContext;
  result = false;
  if ( m_hContext == -1 )
    p_m_DefaultInputContext = (UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int> *)&this->m_DefaultInputContext;
  else
    p_m_DefaultInputContext = &this->m_Contexts.m_Memory.m_pMemory[m_hContext];
  if ( p_m_DefaultInputContext->m_Element._mouseCapture != nullptr )
  {
    if ( code != MOUSE_WHEEL_DOWN && code != MOUSE_WHEEL_UP )
      CEventSignature3<MouseUpEvent,CHitArea *,CHitArea *,enum ButtonCode_t>::Post(
        arg1: (CFunctorData_vtbl **)&p_m_DefaultInputContext->m_Element._mouseCapture,
        arg2: (CFunctorData_vtbl **)&p_m_DefaultInputContext->m_Element._mouseCapture,
        arg3: (CFunctorData_vtbl **)&code);
    return true;
  }
  else
  {
    p_mouseLeftTrap = (CFunctorData_vtbl **)&p_m_DefaultInputContext->m_Element._mouseLeftTrap;
    if ( p_m_DefaultInputContext->m_Element._mouseLeftTrap != nullptr )
    {
      CEventSignature3<MouseUpEvent,CHitArea *,CHitArea *,enum ButtonCode_t>::Post(
        arg1: (CFunctorData_vtbl **)&p_m_DefaultInputContext->m_Element._mouseLeftTrap,
        arg2: (CFunctorData_vtbl **)&p_m_DefaultInputContext->m_Element._mouseLeftTrap,
        arg3: (CFunctorData_vtbl **)&code);
      *p_mouseLeftTrap = nullptr;
      return true;
    }
    else
    {
      p_mouseMiddleTrap = (CFunctorData_vtbl **)&p_m_DefaultInputContext->m_Element._mouseMiddleTrap;
      if ( p_m_DefaultInputContext->m_Element._mouseMiddleTrap != nullptr
        || (p_mouseMiddleTrap = (CFunctorData_vtbl **)&p_m_DefaultInputContext->m_Element._mouseRightTrap,
            p_m_DefaultInputContext->m_Element._mouseRightTrap != nullptr) )
      {
        CEventSignature3<MouseUpEvent,CHitArea *,CHitArea *,enum ButtonCode_t>::Post(
          arg1: p_mouseMiddleTrap,
          arg2: p_mouseLeftTrap,
          arg3: (CFunctorData_vtbl **)&code);
        *p_mouseMiddleTrap = nullptr;
        return true;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004156E0
// Name: public: bool CInputGameUI::InternalMouseWheeled(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CInputGameUI::InternalMouseWheeled(CInputGameUI *this, int delta)
{
  unsigned int m_hContext; // edx
  char result; // al
  UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int> *p_m_DefaultInputContext; // edx

  m_hContext = this->m_hContext;
  result = 0;
  if ( m_hContext == -1 )
    p_m_DefaultInputContext = (UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int> *)&this->m_DefaultInputContext;
  else
    p_m_DefaultInputContext = &this->m_Contexts.m_Memory.m_pMemory[m_hContext];
  if ( p_m_DefaultInputContext->m_Element._mouseFocus != nullptr )
  {
    CEventSignature2<MouseWheelEvent,CHitArea *,int>::Post(
      arg1: (CFunctorData_vtbl **)&p_m_DefaultInputContext->m_Element._mouseFocus,
      arg2: (CFunctorData_vtbl **)&delta);
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00415730
// Name: public: bool CInputGameUI::InternalKeyCodePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CInputGameUI::InternalKeyCodePressed(CInputGameUI *this, ButtonCode_t code)
{
  unsigned int m_hContext; // eax
  UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int> *p_m_DefaultInputContext; // esi
  ButtonCode_t v4; // edi
  char v6; // bl

  m_hContext = this->m_hContext;
  if ( m_hContext == -1 )
    p_m_DefaultInputContext = (UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int> *)&this->m_DefaultInputContext;
  else
    p_m_DefaultInputContext = &this->m_Contexts.m_Memory.m_pMemory[m_hContext];
  v4 = code;
  if ( (unsigned int)code > KEY_SCROLLLOCKTOGGLE && (unsigned int)(code - 114) > 0xBF )
    return 0;
  v6 = 0;
  if ( p_m_DefaultInputContext->m_Element._keyFocus != nullptr )
  {
    CEventSignature2<KeyDownEvent,CHitArea *,enum ButtonCode_t>::Post(
      arg1: (CFunctorData_vtbl **)&p_m_DefaultInputContext->m_Element._keyFocus,
      arg2: (CFunctorData_vtbl **)&code);
    v6 = 1;
    p_m_DefaultInputContext->m_Element._bKeyTrap = true;
    CKeyRepeatHandler::KeyDown(this: &p_m_DefaultInputContext->m_Element.m_keyRepeater, code: v4);
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x004157B0
// Name: public: void CInputGameUI::InternalKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputGameUI::InternalKeyCodeTyped(CInputGameUI *this, ButtonCode_t code)
{
  unsigned int m_hContext; // eax
  UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int> *p_m_DefaultInputContext; // eax
  CFunctorData_vtbl **p_keyFocus; // eax

  m_hContext = this->m_hContext;
  if ( m_hContext == -1 )
    p_m_DefaultInputContext = (UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int> *)&this->m_DefaultInputContext;
  else
    p_m_DefaultInputContext = &this->m_Contexts.m_Memory.m_pMemory[m_hContext];
  if ( (unsigned int)code <= KEY_SCROLLLOCKTOGGLE || (unsigned int)(code - 114) <= 0xBF )
  {
    p_m_DefaultInputContext->m_Element._keyTyped[code] = true;
    p_keyFocus = (CFunctorData_vtbl **)&p_m_DefaultInputContext->m_Element._keyFocus;
    if ( *p_keyFocus != nullptr )
    {
      CEventSignature2<KeyCodeTypedEvent,CHitArea *,enum ButtonCode_t>::Post(
        arg1: p_keyFocus,
        arg2: (CFunctorData_vtbl **)&code);
      CGameUISystemMgr::OnKeyCodeTyped(this: g_pGameUISystemMgrImpl, &code);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00415820
// Name: public: void CInputGameUI::InternalKeyTyped(wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputGameUI::InternalKeyTyped(CInputGameUI *this, wchar_t unichar)
{
  unsigned int m_hContext; // eax
  UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int> *p_m_DefaultInputContext; // eax
  CFunctorData_vtbl **p_keyFocus; // eax

  m_hContext = this->m_hContext;
  if ( m_hContext == -1 )
    p_m_DefaultInputContext = (UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int> *)&this->m_DefaultInputContext;
  else
    p_m_DefaultInputContext = &this->m_Contexts.m_Memory.m_pMemory[m_hContext];
  if ( unichar <= 0x6Au )
    p_m_DefaultInputContext->m_Element._keyTyped[unichar] = true;
  p_keyFocus = (CFunctorData_vtbl **)&p_m_DefaultInputContext->m_Element._keyFocus;
  if ( *p_keyFocus != nullptr )
  {
    CEventSignature2<KeyTypedEvent,CHitArea *,wchar_t>::Post(arg1: p_keyFocus, arg2: &unichar);
    CUtlBuffer::GetOverflow(
      this: (vgui::Panel *)g_pGameUISystemMgrImpl,
      msglist: (CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *)&unichar);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00415880
// Name: public: bool CInputGameUI::InternalKeyCodeReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CInputGameUI::InternalKeyCodeReleased(CInputGameUI *this, ButtonCode_t code)
{
  unsigned int m_hContext; // eax
  UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int> *p_m_DefaultInputContext; // esi

  m_hContext = this->m_hContext;
  if ( m_hContext == -1 )
    p_m_DefaultInputContext = (UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int> *)&this->m_DefaultInputContext;
  else
    p_m_DefaultInputContext = &this->m_Contexts.m_Memory.m_pMemory[m_hContext];
  if ( (unsigned int)code > KEY_SCROLLLOCKTOGGLE && (unsigned int)(code - 114) > 0xBF )
    return 0;
  CKeyRepeatHandler::KeyUp(this: &p_m_DefaultInputContext->m_Element.m_keyRepeater, code);
  if ( p_m_DefaultInputContext->m_Element._keyFocus == nullptr || !p_m_DefaultInputContext->m_Element._bKeyTrap )
    return 0;
  CEventSignature2<KeyUpEvent,CHitArea *,enum ButtonCode_t>::Post(
    arg1: (CFunctorData_vtbl **)&p_m_DefaultInputContext->m_Element._keyFocus,
    arg2: (CFunctorData_vtbl **)&code);
  p_m_DefaultInputContext->m_Element._bKeyTrap = false;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00415900
// Name: public: virtual void CInputGameUI::OnIMEComposition(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputGameUI::OnIMEComposition(CInputGameUI *this, __int16 flags)
{
  HWND v3; // eax
  HIMC Context; // ebx
  LONG CompositionStringW; // eax
  signed int v6; // edi
  signed int v7; // esi
  LONG v8; // eax
  HWND v9; // eax
  wchar_t tempstr[32]; // [esp+4h] [ebp-244h] BYREF
  wchar_t Buf[256]; // [esp+48h] [ebp-200h] BYREF

  v3 = (HWND)this->GetIMEWindow(this);
  Context = ImmGetContext(a1: v3);
  if ( Context != nullptr )
  {
    if ( (flags & 0x800) != 0 )
    {
      CompositionStringW = ImmGetCompositionStringW(a1: Context, a2: 0x800u, lpBuf: &tempstr[2], dwBufLen: 0x40u);
      if ( CompositionStringW > 0 )
      {
        if ( (CompositionStringW & 0x80000001) != 0 )
          ++CompositionStringW;
        v6 = (unsigned int)CompositionStringW >> 1;
        v7 = 0;
        if ( (unsigned int)CompositionStringW >> 1 != 0 )
        {
          do
            CInputGameUI::InternalKeyTyped(this, unichar: tempstr[v7++ + 2]);
          while ( v7 < v6 );
        }
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
        CInputGameUI::InternalSetCompositionString(this, compstr: Buf);
      }
    }
    v9 = (HWND)this->GetIMEWindow(this);
    ImmReleaseContext(a1: v9, a2: Context);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004159E0
// Name: bool InputGameUIHandleInputEvent(struct InputEvent_t const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl InputGameUIHandleInputEvent(const InputEvent_t *event)
{
  ButtonCode_t m_nData2; // esi
  char result; // al
  ButtonCode_t v3; // esi
  ButtonCode_t v4; // esi
  int m_nData; // eax

  switch ( event->m_nType )
  {
    case 0:
      m_nData2 = event->m_nData2;
      if ( (unsigned int)m_nData2 <= KEY_SCROLLLOCKTOGGLE || (unsigned int)(m_nData2 - 114) <= 0xBF )
        return CInputGameUI::InternalKeyCodePressed(this: g_pInputGameUI, code: m_nData2);
      if ( (unsigned int)(m_nData2 - 107) > 6 )
        goto LABEL_32;
      return CInputGameUI::InternalMousePressed(this: g_pInputGameUI, code: m_nData2);
    case 1:
      v3 = event->m_nData2;
      if ( (unsigned int)v3 <= KEY_SCROLLLOCKTOGGLE || (unsigned int)(v3 - 114) <= 0xBF )
        return CInputGameUI::InternalKeyCodeReleased(this: g_pInputGameUI, code: v3);
      if ( (unsigned int)(v3 - 107) > 6 )
        goto LABEL_32;
      return CInputGameUI::InternalMouseReleased(this: g_pInputGameUI, code: v3);
    case 2:
      v4 = event->m_nData2;
      if ( (unsigned int)(v4 - 107) > 6 )
        goto LABEL_32;
      return CInputGameUI::InternalMouseDoublePressed(this: g_pInputGameUI, code: v4);
    case 3:
      m_nData = event->m_nData;
      if ( m_nData == 3 )
        return CInputGameUI::InternalMouseWheeled(this: g_pInputGameUI, delta: event->m_nData3);
      if ( m_nData != 2 )
        goto LABEL_32;
      return CInputGameUI::InternalCursorMoved(this: g_pInputGameUI, x: event->m_nData2, y: event->m_nData3);
    case 0x64:
    case 0x67:
    case 0xC9:
      return 1;
    case 0x68:
      CGameUISystemMgr::SetWindowSize(
        this: (CUtlBuffer *)g_pGameUISystemMgrImpl,
        getFunc: (bool (__thiscall *)(CUtlBuffer *, int))event->m_nData,
        putFunc: (bool (__thiscall *)(CUtlBuffer *, int))event->m_nData2);
      goto $LN72;
    case 0xC8:
      CInputGameUI::InternalCursorMoved(this: g_pInputGameUI, x: event->m_nData, y: event->m_nData2);
      return 1;
    case 0xCA:
      CInputGameUI::InternalKeyTyped(this: g_pInputGameUI, unichar: event->m_nData);
      return 1;
    case 0xCB:
      CInputGameUI::InternalKeyCodeTyped(this: g_pInputGameUI, code: (ButtonCode_t)event->m_nData);
      return 1;
    case 0xCC:
      g_pInputGameUI->OnInputLanguageChanged(this: g_pInputGameUI);
      return 1;
    case 0xCD:
$LN72:
      g_pInputGameUI->SetIMEWindow(this: g_pInputGameUI, a2: (void *)event->m_nData);
      result = 1;
      break;
    case 0xCE:
      g_pInputGameUI->OnIMEStartComposition(this: g_pInputGameUI);
      result = 1;
      break;
    case 0xCF:
      g_pInputGameUI->OnIMEComposition(this: g_pInputGameUI, a2: event->m_nData);
      result = 1;
      break;
    case 0xD0:
      g_pInputGameUI->OnIMEEndComposition(this: g_pInputGameUI);
      result = 1;
      break;
    case 0xD1:
      g_pInputGameUI->OnIMEShowCandidates(this: g_pInputGameUI);
      result = 1;
      break;
    case 0xD2:
      g_pInputGameUI->OnIMEChangeCandidates(this: g_pInputGameUI);
      result = 1;
      break;
    case 0xD3:
      g_pInputGameUI->OnIMECloseCandidates(this: g_pInputGameUI);
      result = 1;
      break;
    case 0xD4:
      g_pInputGameUI->OnIMERecomputeModes(this: g_pInputGameUI);
      result = 1;
      break;
    default:
LABEL_32:
      result = 0;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00415D00
// Name: public: static void CEventSignature1<class CursorEnterEvent,class CHitArea __near *>::RegisterMemberFunc<class CInputGameUI>(struct EventQueue_t__ __near *,class CInputGameUI __near *,void (CInputGameUI::*)(class CHitArea __near * const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl CEventSignature1<CursorEnterEvent,CHitArea *>::RegisterMemberFunc<CInputGameUI>(
        EventQueue_t__ *hQueue,
        CFunctorCallback_vtbl *pClass,
        void (__thiscall *pfnProxied)(CInputGameUI *this, CHitArea *const *))
{
  CFunctorCallback *v3; // eax
  CFunctorCallback *v4; // esi
  EventId_t__ *v5; // eax

  v3 = (CFunctorCallback *)MemAlloc_Alloc(nSize: 0x14u);
  if ( v3 != nullptr )
  {
    v3[2].__vftable = (CFunctorCallback_vtbl *)1;
    v3->__vftable = (CFunctorCallback_vtbl *)&CMemberFunctorCallback1<CInputGameUI,CHitArea *,CFuncMemPolicyNone>::`vftable'{for `CFunctorCallback'};
    v3[1].__vftable = (CFunctorCallback_vtbl *)&CMemberFunctorCallback1<CInputGameUI,CHitArea *,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    v3[3].__vftable = (CFunctorCallback_vtbl *)pfnProxied;
    v3[4].__vftable = pClass;
    v4 = v3;
  }
  else
  {
    v4 = nullptr;
  }
  v5 = (EventId_t__ *)`CursorEnterEvent::GetEventId'::`2'::s_nEventId;
  if ( `CursorEnterEvent::GetEventId'::`2'::s_nEventId == 0 )
  {
    v5 = g_pEventSystem->RegisterEvent(this: g_pEventSystem, a2: "CursorEnterEvent");
    `CursorEnterEvent::GetEventId'::`2'::s_nEventId = (int)v5;
  }
  g_pEventSystem->RegisterListener(this: g_pEventSystem, a2: v5, a3: hQueue, a4: v4);
}

//------------------------------------------------------------------------------
// Address: 0x00415D70
// Name: public: static void CEventSignature1<class CursorExitEvent,class CHitArea __near *>::RegisterMemberFunc<class CInputGameUI>(struct EventQueue_t__ __near *,class CInputGameUI __near *,void (CInputGameUI::*)(class CHitArea __near * const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl CEventSignature1<CursorExitEvent,CHitArea *>::RegisterMemberFunc<CInputGameUI>(
        EventQueue_t__ *hQueue,
        CFunctorCallback_vtbl *pClass,
        void (__thiscall *pfnProxied)(CInputGameUI *this, CHitArea *const *))
{
  CFunctorCallback *v3; // eax
  CFunctorCallback *v4; // esi
  EventId_t__ *v5; // eax

  v3 = (CFunctorCallback *)MemAlloc_Alloc(nSize: 0x14u);
  if ( v3 != nullptr )
  {
    v3[2].__vftable = (CFunctorCallback_vtbl *)1;
    v3->__vftable = (CFunctorCallback_vtbl *)&CMemberFunctorCallback1<CInputGameUI,CHitArea *,CFuncMemPolicyNone>::`vftable'{for `CFunctorCallback'};
    v3[1].__vftable = (CFunctorCallback_vtbl *)&CMemberFunctorCallback1<CInputGameUI,CHitArea *,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    v3[3].__vftable = (CFunctorCallback_vtbl *)pfnProxied;
    v3[4].__vftable = pClass;
    v4 = v3;
  }
  else
  {
    v4 = nullptr;
  }
  v5 = (EventId_t__ *)`CursorExitEvent::GetEventId'::`2'::s_nEventId;
  if ( `CursorExitEvent::GetEventId'::`2'::s_nEventId == 0 )
  {
    v5 = g_pEventSystem->RegisterEvent(this: g_pEventSystem, a2: "CursorExitEvent");
    `CursorExitEvent::GetEventId'::`2'::s_nEventId = (int)v5;
  }
  g_pEventSystem->RegisterListener(this: g_pEventSystem, a2: v5, a3: hQueue, a4: v4);
}

//------------------------------------------------------------------------------
// Address: 0x00415DE0
// Name: public: static void CEventSignature3<class CursorMoveEvent,class CHitArea __near *,int,int>::RegisterMemberFunc<class CInputGameUI>(struct EventQueue_t__ __near *,class CInputGameUI __near *,void (CInputGameUI::*)(class CHitArea __near * const __near &,int const __near &,int const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl CEventSignature3<CursorMoveEvent,CHitArea *,int,int>::RegisterMemberFunc<CInputGameUI>(
        EventQueue_t__ *hQueue,
        CFunctorCallback_vtbl *pClass,
        void (__thiscall *pfnProxied)(CInputGameUI *this, CHitArea *const *, const int *, const int *))
{
  CFunctorCallback *v3; // eax
  CFunctorCallback *v4; // esi
  EventId_t__ *v5; // eax

  v3 = (CFunctorCallback *)MemAlloc_Alloc(nSize: 0x14u);
  if ( v3 != nullptr )
  {
    v3[2].__vftable = (CFunctorCallback_vtbl *)1;
    v3->__vftable = (CFunctorCallback_vtbl *)&CMemberFunctorCallback3<CInputGameUI,CHitArea *,int,int,CFuncMemPolicyNone>::`vftable'{for `CFunctorCallback'};
    v3[1].__vftable = (CFunctorCallback_vtbl *)&CMemberFunctorCallback3<CInputGameUI,CHitArea *,int,int,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    v3[3].__vftable = (CFunctorCallback_vtbl *)pfnProxied;
    v3[4].__vftable = pClass;
    v4 = v3;
  }
  else
  {
    v4 = nullptr;
  }
  v5 = (EventId_t__ *)`CursorMoveEvent::GetEventId'::`2'::s_nEventId;
  if ( `CursorMoveEvent::GetEventId'::`2'::s_nEventId == 0 )
  {
    v5 = g_pEventSystem->RegisterEvent(this: g_pEventSystem, a2: "CursorMoveEvent");
    `CursorMoveEvent::GetEventId'::`2'::s_nEventId = (int)v5;
  }
  g_pEventSystem->RegisterListener(this: g_pEventSystem, a2: v5, a3: hQueue, a4: v4);
}

//------------------------------------------------------------------------------
// Address: 0x00415E50
// Name: public: static void CEventSignature2<class InternalCursorMoveEvent,int,int>::RegisterMemberFunc<class CInputGameUI>(struct EventQueue_t__ __near *,class CInputGameUI __near *,void (CInputGameUI::*)(int const __near &,int const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl CEventSignature2<InternalCursorMoveEvent,int,int>::RegisterMemberFunc<CInputGameUI>(
        EventQueue_t__ *hQueue,
        CFunctorCallback_vtbl *pClass,
        void (__thiscall *pfnProxied)(CInputGameUI *this, const int *, const int *))
{
  CFunctorCallback *v3; // eax
  CFunctorCallback *v4; // esi
  EventId_t__ *v5; // eax

  v3 = (CFunctorCallback *)MemAlloc_Alloc(nSize: 0x14u);
  if ( v3 != nullptr )
  {
    v3[2].__vftable = (CFunctorCallback_vtbl *)1;
    v3->__vftable = (CFunctorCallback_vtbl *)&CMemberFunctorCallback2<CInputGameUI,int,int,CFuncMemPolicyNone>::`vftable'{for `CFunctorCallback'};
    v3[1].__vftable = (CFunctorCallback_vtbl *)&CMemberFunctorCallback2<CInputGameUI,int,int,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    v3[3].__vftable = (CFunctorCallback_vtbl *)pfnProxied;
    v3[4].__vftable = pClass;
    v4 = v3;
  }
  else
  {
    v4 = nullptr;
  }
  v5 = (EventId_t__ *)`InternalCursorMoveEvent::GetEventId'::`2'::s_nEventId;
  if ( `InternalCursorMoveEvent::GetEventId'::`2'::s_nEventId == 0 )
  {
    v5 = g_pEventSystem->RegisterEvent(this: g_pEventSystem, a2: "InternalCursorMoveEvent");
    `InternalCursorMoveEvent::GetEventId'::`2'::s_nEventId = (int)v5;
  }
  g_pEventSystem->RegisterListener(this: g_pEventSystem, a2: v5, a3: hQueue, a4: v4);
}

//------------------------------------------------------------------------------
// Address: 0x00415EC0
// Name: public: static void CEventSignature2<class MouseDownEvent,class CHitArea __near *,enum ButtonCode_t>::RegisterMemberFunc<class CInputGameUI>(struct EventQueue_t__ __near *,class CInputGameUI __near *,void (CInputGameUI::*)(class CHitArea __near * const __near &,enum ButtonCode_t const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl CEventSignature2<MouseDownEvent,CHitArea *,enum ButtonCode_t>::RegisterMemberFunc<CInputGameUI>(
        EventQueue_t__ *hQueue,
        CFunctorCallback_vtbl *pClass,
        void (__thiscall *pfnProxied)(CInputGameUI *this, CHitArea *const *, const ButtonCode_t *))
{
  CFunctorCallback *v3; // eax
  CFunctorCallback *v4; // esi
  EventId_t__ *v5; // eax

  v3 = (CFunctorCallback *)MemAlloc_Alloc(nSize: 0x14u);
  if ( v3 != nullptr )
  {
    v3[2].__vftable = (CFunctorCallback_vtbl *)1;
    v3->__vftable = (CFunctorCallback_vtbl *)&CMemberFunctorCallback2<CInputGameUI,CHitArea *,enum ButtonCode_t,CFuncMemPolicyNone>::`vftable'{for `CFunctorCallback'};
    v3[1].__vftable = (CFunctorCallback_vtbl *)&CMemberFunctorCallback2<CInputGameUI,CHitArea *,enum ButtonCode_t,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    v3[3].__vftable = (CFunctorCallback_vtbl *)pfnProxied;
    v3[4].__vftable = pClass;
    v4 = v3;
  }
  else
  {
    v4 = nullptr;
  }
  v5 = (EventId_t__ *)`MouseDownEvent::GetEventId'::`2'::s_nEventId;
  if ( `MouseDownEvent::GetEventId'::`2'::s_nEventId == 0 )
  {
    v5 = g_pEventSystem->RegisterEvent(this: g_pEventSystem, a2: "MouseDownEvent");
    `MouseDownEvent::GetEventId'::`2'::s_nEventId = (int)v5;
  }
  g_pEventSystem->RegisterListener(this: g_pEventSystem, a2: v5, a3: hQueue, a4: v4);
}

//------------------------------------------------------------------------------
// Address: 0x00415F30
// Name: public: static void CEventSignature3<class MouseUpEvent,class CHitArea __near *,class CHitArea __near *,enum ButtonCode_t>::RegisterMemberFunc<class CInputGameUI>(struct EventQueue_t__ __near *,class CInputGameUI __near *,void (CInputGameUI::*)(class CHitArea __near * const __near &,class CHitArea __near * const __near &,enum ButtonCode_t const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl CEventSignature3<MouseUpEvent,CHitArea *,CHitArea *,enum ButtonCode_t>::RegisterMemberFunc<CInputGameUI>(
        EventQueue_t__ *hQueue,
        CFunctorCallback_vtbl *pClass,
        void (__thiscall *pfnProxied)(CInputGameUI *this, CHitArea *const *, CHitArea *const *, const ButtonCode_t *))
{
  CFunctorCallback *v3; // eax
  CFunctorCallback *v4; // esi
  EventId_t__ *v5; // eax

  v3 = (CFunctorCallback *)MemAlloc_Alloc(nSize: 0x14u);
  if ( v3 != nullptr )
  {
    v3[2].__vftable = (CFunctorCallback_vtbl *)1;
    v3->__vftable = (CFunctorCallback_vtbl *)&CMemberFunctorCallback3<CInputGameUI,CHitArea *,CHitArea *,enum ButtonCode_t,CFuncMemPolicyNone>::`vftable'{for `CFunctorCallback'};
    v3[1].__vftable = (CFunctorCallback_vtbl *)&CMemberFunctorCallback3<CInputGameUI,CHitArea *,CHitArea *,enum ButtonCode_t,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    v3[3].__vftable = (CFunctorCallback_vtbl *)pfnProxied;
    v3[4].__vftable = pClass;
    v4 = v3;
  }
  else
  {
    v4 = nullptr;
  }
  v5 = (EventId_t__ *)`MouseUpEvent::GetEventId'::`2'::s_nEventId;
  if ( `MouseUpEvent::GetEventId'::`2'::s_nEventId == 0 )
  {
    v5 = g_pEventSystem->RegisterEvent(this: g_pEventSystem, a2: "MouseUpEvent");
    `MouseUpEvent::GetEventId'::`2'::s_nEventId = (int)v5;
  }
  g_pEventSystem->RegisterListener(this: g_pEventSystem, a2: v5, a3: hQueue, a4: v4);
}

//------------------------------------------------------------------------------
// Address: 0x00415FA0
// Name: public: static void CEventSignature2<class MouseDoubleClickEvent,class CHitArea __near *,enum ButtonCode_t>::RegisterMemberFunc<class CInputGameUI>(struct EventQueue_t__ __near *,class CInputGameUI __near *,void (CInputGameUI::*)(class CHitArea __near * const __near &,enum ButtonCode_t const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl CEventSignature2<MouseDoubleClickEvent,CHitArea *,enum ButtonCode_t>::RegisterMemberFunc<CInputGameUI>(
        EventQueue_t__ *hQueue,
        CFunctorCallback_vtbl *pClass,
        void (__thiscall *pfnProxied)(CInputGameUI *this, CHitArea *const *, const ButtonCode_t *))
{
  CFunctorCallback *v3; // eax
  CFunctorCallback *v4; // esi
  EventId_t__ *v5; // eax

  v3 = (CFunctorCallback *)MemAlloc_Alloc(nSize: 0x14u);
  if ( v3 != nullptr )
  {
    v3[2].__vftable = (CFunctorCallback_vtbl *)1;
    v3->__vftable = (CFunctorCallback_vtbl *)&CMemberFunctorCallback2<CInputGameUI,CHitArea *,enum ButtonCode_t,CFuncMemPolicyNone>::`vftable'{for `CFunctorCallback'};
    v3[1].__vftable = (CFunctorCallback_vtbl *)&CMemberFunctorCallback2<CInputGameUI,CHitArea *,enum ButtonCode_t,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    v3[3].__vftable = (CFunctorCallback_vtbl *)pfnProxied;
    v3[4].__vftable = pClass;
    v4 = v3;
  }
  else
  {
    v4 = nullptr;
  }
  v5 = (EventId_t__ *)`MouseDoubleClickEvent::GetEventId'::`2'::s_nEventId;
  if ( `MouseDoubleClickEvent::GetEventId'::`2'::s_nEventId == 0 )
  {
    v5 = g_pEventSystem->RegisterEvent(this: g_pEventSystem, a2: "MouseDoubleClickEvent");
    `MouseDoubleClickEvent::GetEventId'::`2'::s_nEventId = (int)v5;
  }
  g_pEventSystem->RegisterListener(this: g_pEventSystem, a2: v5, a3: hQueue, a4: v4);
}

//------------------------------------------------------------------------------
// Address: 0x00416010
// Name: public: static void CEventSignature2<class KeyDownEvent,class CHitArea __near *,enum ButtonCode_t>::RegisterMemberFunc<class CInputGameUI>(struct EventQueue_t__ __near *,class CInputGameUI __near *,void (CInputGameUI::*)(class CHitArea __near * const __near &,enum ButtonCode_t const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl CEventSignature2<KeyDownEvent,CHitArea *,enum ButtonCode_t>::RegisterMemberFunc<CInputGameUI>(
        EventQueue_t__ *hQueue,
        CFunctorCallback_vtbl *pClass,
        void (__thiscall *pfnProxied)(CInputGameUI *this, CHitArea *const *, const ButtonCode_t *))
{
  CFunctorCallback *v3; // eax
  CFunctorCallback *v4; // esi
  EventId_t__ *v5; // eax

  v3 = (CFunctorCallback *)MemAlloc_Alloc(nSize: 0x14u);
  if ( v3 != nullptr )
  {
    v3[2].__vftable = (CFunctorCallback_vtbl *)1;
    v3->__vftable = (CFunctorCallback_vtbl *)&CMemberFunctorCallback2<CInputGameUI,CHitArea *,enum ButtonCode_t,CFuncMemPolicyNone>::`vftable'{for `CFunctorCallback'};
    v3[1].__vftable = (CFunctorCallback_vtbl *)&CMemberFunctorCallback2<CInputGameUI,CHitArea *,enum ButtonCode_t,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    v3[3].__vftable = (CFunctorCallback_vtbl *)pfnProxied;
    v3[4].__vftable = pClass;
    v4 = v3;
  }
  else
  {
    v4 = nullptr;
  }
  v5 = (EventId_t__ *)`KeyDownEvent::GetEventId'::`2'::s_nEventId;
  if ( `KeyDownEvent::GetEventId'::`2'::s_nEventId == 0 )
  {
    v5 = g_pEventSystem->RegisterEvent(this: g_pEventSystem, a2: "KeyDownEvent");
    `KeyDownEvent::GetEventId'::`2'::s_nEventId = (int)v5;
  }
  g_pEventSystem->RegisterListener(this: g_pEventSystem, a2: v5, a3: hQueue, a4: v4);
}

//------------------------------------------------------------------------------
// Address: 0x00416080
// Name: public: static void CEventSignature2<class KeyUpEvent,class CHitArea __near *,enum ButtonCode_t>::RegisterMemberFunc<class CInputGameUI>(struct EventQueue_t__ __near *,class CInputGameUI __near *,void (CInputGameUI::*)(class CHitArea __near * const __near &,enum ButtonCode_t const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl CEventSignature2<KeyUpEvent,CHitArea *,enum ButtonCode_t>::RegisterMemberFunc<CInputGameUI>(
        EventQueue_t__ *hQueue,
        CFunctorCallback_vtbl *pClass,
        void (__thiscall *pfnProxied)(CInputGameUI *this, CHitArea *const *, const ButtonCode_t *))
{
  CFunctorCallback *v3; // eax
  CFunctorCallback *v4; // esi
  EventId_t__ *v5; // eax

  v3 = (CFunctorCallback *)MemAlloc_Alloc(nSize: 0x14u);
  if ( v3 != nullptr )
  {
    v3[2].__vftable = (CFunctorCallback_vtbl *)1;
    v3->__vftable = (CFunctorCallback_vtbl *)&CMemberFunctorCallback2<CInputGameUI,CHitArea *,enum ButtonCode_t,CFuncMemPolicyNone>::`vftable'{for `CFunctorCallback'};
    v3[1].__vftable = (CFunctorCallback_vtbl *)&CMemberFunctorCallback2<CInputGameUI,CHitArea *,enum ButtonCode_t,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    v3[3].__vftable = (CFunctorCallback_vtbl *)pfnProxied;
    v3[4].__vftable = pClass;
    v4 = v3;
  }
  else
  {
    v4 = nullptr;
  }
  v5 = (EventId_t__ *)`KeyUpEvent::GetEventId'::`2'::s_nEventId;
  if ( `KeyUpEvent::GetEventId'::`2'::s_nEventId == 0 )
  {
    v5 = g_pEventSystem->RegisterEvent(this: g_pEventSystem, a2: "KeyUpEvent");
    `KeyUpEvent::GetEventId'::`2'::s_nEventId = (int)v5;
  }
  g_pEventSystem->RegisterListener(this: g_pEventSystem, a2: v5, a3: hQueue, a4: v4);
}

//------------------------------------------------------------------------------
// Address: 0x004160F0
// Name: public: static void CEventSignature2<class KeyCodeTypedEvent,class CHitArea __near *,enum ButtonCode_t>::RegisterMemberFunc<class CInputGameUI>(struct EventQueue_t__ __near *,class CInputGameUI __near *,void (CInputGameUI::*)(class CHitArea __near * const __near &,enum ButtonCode_t const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl CEventSignature2<KeyCodeTypedEvent,CHitArea *,enum ButtonCode_t>::RegisterMemberFunc<CInputGameUI>(
        EventQueue_t__ *hQueue,
        CFunctorCallback_vtbl *pClass,
        void (__thiscall *pfnProxied)(CInputGameUI *this, CHitArea *const *, const ButtonCode_t *))
{
  CFunctorCallback *v3; // eax
  CFunctorCallback *v4; // esi
  EventId_t__ *v5; // eax

  v3 = (CFunctorCallback *)MemAlloc_Alloc(nSize: 0x14u);
  if ( v3 != nullptr )
  {
    v3[2].__vftable = (CFunctorCallback_vtbl *)1;
    v3->__vftable = (CFunctorCallback_vtbl *)&CMemberFunctorCallback2<CInputGameUI,CHitArea *,enum ButtonCode_t,CFuncMemPolicyNone>::`vftable'{for `CFunctorCallback'};
    v3[1].__vftable = (CFunctorCallback_vtbl *)&CMemberFunctorCallback2<CInputGameUI,CHitArea *,enum ButtonCode_t,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    v3[3].__vftable = (CFunctorCallback_vtbl *)pfnProxied;
    v3[4].__vftable = pClass;
    v4 = v3;
  }
  else
  {
    v4 = nullptr;
  }
  v5 = (EventId_t__ *)`KeyCodeTypedEvent::GetEventId'::`2'::s_nEventId;
  if ( `KeyCodeTypedEvent::GetEventId'::`2'::s_nEventId == 0 )
  {
    v5 = g_pEventSystem->RegisterEvent(this: g_pEventSystem, a2: "KeyCodeTypedEvent");
    `KeyCodeTypedEvent::GetEventId'::`2'::s_nEventId = (int)v5;
  }
  g_pEventSystem->RegisterListener(this: g_pEventSystem, a2: v5, a3: hQueue, a4: v4);
}

//------------------------------------------------------------------------------
// Address: 0x00416160
// Name: public: static void CEventSignature2<class KeyTypedEvent,class CHitArea __near *,wchar_t>::RegisterMemberFunc<class CInputGameUI>(struct EventQueue_t__ __near *,class CInputGameUI __near *,void (CInputGameUI::*)(class CHitArea __near * const __near &,wchar_t const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl CEventSignature2<KeyTypedEvent,CHitArea *,wchar_t>::RegisterMemberFunc<CInputGameUI>(
        EventQueue_t__ *hQueue,
        CFunctorCallback_vtbl *pClass,
        void (__thiscall *pfnProxied)(CInputGameUI *this, CHitArea *const *, const wchar_t *))
{
  CFunctorCallback *v3; // eax
  CFunctorCallback *v4; // esi
  EventId_t__ *v5; // eax

  v3 = (CFunctorCallback *)MemAlloc_Alloc(nSize: 0x14u);
  if ( v3 != nullptr )
  {
    v3[2].__vftable = (CFunctorCallback_vtbl *)1;
    v3->__vftable = (CFunctorCallback_vtbl *)&CMemberFunctorCallback2<CInputGameUI,CHitArea *,wchar_t,CFuncMemPolicyNone>::`vftable'{for `CFunctorCallback'};
    v3[1].__vftable = (CFunctorCallback_vtbl *)&CMemberFunctorCallback2<CInputGameUI,CHitArea *,wchar_t,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    v3[3].__vftable = (CFunctorCallback_vtbl *)pfnProxied;
    v3[4].__vftable = pClass;
    v4 = v3;
  }
  else
  {
    v4 = nullptr;
  }
  v5 = (EventId_t__ *)`KeyTypedEvent::GetEventId'::`2'::s_nEventId;
  if ( `KeyTypedEvent::GetEventId'::`2'::s_nEventId == 0 )
  {
    v5 = g_pEventSystem->RegisterEvent(this: g_pEventSystem, a2: "KeyTypedEvent");
    `KeyTypedEvent::GetEventId'::`2'::s_nEventId = (int)v5;
  }
  g_pEventSystem->RegisterListener(this: g_pEventSystem, a2: v5, a3: hQueue, a4: v4);
}

//------------------------------------------------------------------------------
// Address: 0x004161D0
// Name: public: static void CEventSignature1<class LoseKeyFocusEvent,class CHitArea __near *>::RegisterMemberFunc<class CInputGameUI>(struct EventQueue_t__ __near *,class CInputGameUI __near *,void (CInputGameUI::*)(class CHitArea __near * const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl CEventSignature1<LoseKeyFocusEvent,CHitArea *>::RegisterMemberFunc<CInputGameUI>(
        EventQueue_t__ *hQueue,
        CFunctorCallback_vtbl *pClass,
        void (__thiscall *pfnProxied)(CInputGameUI *this, CHitArea *const *))
{
  CFunctorCallback *v3; // eax
  CFunctorCallback *v4; // esi
  EventId_t__ *v5; // eax

  v3 = (CFunctorCallback *)MemAlloc_Alloc(nSize: 0x14u);
  if ( v3 != nullptr )
  {
    v3[2].__vftable = (CFunctorCallback_vtbl *)1;
    v3->__vftable = (CFunctorCallback_vtbl *)&CMemberFunctorCallback1<CInputGameUI,CHitArea *,CFuncMemPolicyNone>::`vftable'{for `CFunctorCallback'};
    v3[1].__vftable = (CFunctorCallback_vtbl *)&CMemberFunctorCallback1<CInputGameUI,CHitArea *,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    v3[3].__vftable = (CFunctorCallback_vtbl *)pfnProxied;
    v3[4].__vftable = pClass;
    v4 = v3;
  }
  else
  {
    v4 = nullptr;
  }
  v5 = (EventId_t__ *)`LoseKeyFocusEvent::GetEventId'::`2'::s_nEventId;
  if ( `LoseKeyFocusEvent::GetEventId'::`2'::s_nEventId == 0 )
  {
    v5 = g_pEventSystem->RegisterEvent(this: g_pEventSystem, a2: "LoseKeyFocusEvent");
    `LoseKeyFocusEvent::GetEventId'::`2'::s_nEventId = (int)v5;
  }
  g_pEventSystem->RegisterListener(this: g_pEventSystem, a2: v5, a3: hQueue, a4: v4);
}

//------------------------------------------------------------------------------
// Address: 0x00416240
// Name: public: static void CEventSignature1<class GainKeyFocusEvent,class CHitArea __near *>::RegisterMemberFunc<class CInputGameUI>(struct EventQueue_t__ __near *,class CInputGameUI __near *,void (CInputGameUI::*)(class CHitArea __near * const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl CEventSignature1<GainKeyFocusEvent,CHitArea *>::RegisterMemberFunc<CInputGameUI>(
        EventQueue_t__ *hQueue,
        CFunctorCallback_vtbl *pClass,
        void (__thiscall *pfnProxied)(CInputGameUI *this, CHitArea *const *))
{
  CFunctorCallback *v3; // eax
  CFunctorCallback *v4; // esi
  EventId_t__ *v5; // eax

  v3 = (CFunctorCallback *)MemAlloc_Alloc(nSize: 0x14u);
  if ( v3 != nullptr )
  {
    v3[2].__vftable = (CFunctorCallback_vtbl *)1;
    v3->__vftable = (CFunctorCallback_vtbl *)&CMemberFunctorCallback1<CInputGameUI,CHitArea *,CFuncMemPolicyNone>::`vftable'{for `CFunctorCallback'};
    v3[1].__vftable = (CFunctorCallback_vtbl *)&CMemberFunctorCallback1<CInputGameUI,CHitArea *,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    v3[3].__vftable = (CFunctorCallback_vtbl *)pfnProxied;
    v3[4].__vftable = pClass;
    v4 = v3;
  }
  else
  {
    v4 = nullptr;
  }
  v5 = (EventId_t__ *)`GainKeyFocusEvent::GetEventId'::`2'::s_nEventId;
  if ( `GainKeyFocusEvent::GetEventId'::`2'::s_nEventId == 0 )
  {
    v5 = g_pEventSystem->RegisterEvent(this: g_pEventSystem, a2: "GainKeyFocusEvent");
    `GainKeyFocusEvent::GetEventId'::`2'::s_nEventId = (int)v5;
  }
  g_pEventSystem->RegisterListener(this: g_pEventSystem, a2: v5, a3: hQueue, a4: v4);
}

//------------------------------------------------------------------------------
// Address: 0x00416330
// Name: public: void CInputGameUI::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputGameUI::Init(CInputGameUI *this)
{
  EventQueue_t__ *v2; // eax
  EventQueue_t__ *m_hEventChannel; // ebx
  CFunctorCallback *v4; // eax
  CFunctorCallback *v5; // edi
  EventId_t__ *v6; // eax

  v2 = g_pEventSystem->CreateEventQueue(this: g_pEventSystem);
  this->m_hEventChannel = v2;
  CEventSignature1<CursorEnterEvent,CHitArea *>::RegisterMemberFunc<CInputGameUI>(
    hQueue: v2,
    pClass: (CFunctorCallback_vtbl *)this,
    pfnProxied: (void (__thiscall *)(CInputGameUI *, CHitArea *const *))CInputGameUI::OnCursorEnter);
  CEventSignature1<CursorExitEvent,CHitArea *>::RegisterMemberFunc<CInputGameUI>(
    hQueue: this->m_hEventChannel,
    pClass: (CFunctorCallback_vtbl *)this,
    pfnProxied: (void (__thiscall *)(CInputGameUI *, CHitArea *const *))CInputGameUI::OnCursorExit);
  CEventSignature3<CursorMoveEvent,CHitArea *,int,int>::RegisterMemberFunc<CInputGameUI>(
    hQueue: this->m_hEventChannel,
    pClass: (CFunctorCallback_vtbl *)this,
    pfnProxied: (void (__thiscall *)(CInputGameUI *, CHitArea *const *, const int *, const int *))CInputGameUI::OnCursorMove);
  CEventSignature2<InternalCursorMoveEvent,int,int>::RegisterMemberFunc<CInputGameUI>(
    hQueue: this->m_hEventChannel,
    pClass: (CFunctorCallback_vtbl *)this,
    pfnProxied: (void (__thiscall *)(CInputGameUI *, const int *, const int *))CInputGameUI::UpdateCursorPosInternal);
  CEventSignature2<MouseDownEvent,CHitArea *,enum ButtonCode_t>::RegisterMemberFunc<CInputGameUI>(
    hQueue: this->m_hEventChannel,
    pClass: (CFunctorCallback_vtbl *)this,
    pfnProxied: (void (__thiscall *)(CInputGameUI *, CHitArea *const *, const ButtonCode_t *))CInputGameUI::OnMouseDown);
  CEventSignature3<MouseUpEvent,CHitArea *,CHitArea *,enum ButtonCode_t>::RegisterMemberFunc<CInputGameUI>(
    hQueue: this->m_hEventChannel,
    pClass: (CFunctorCallback_vtbl *)this,
    pfnProxied: (void (__thiscall *)(CInputGameUI *, CHitArea *const *, CHitArea *const *, const ButtonCode_t *))CInputGameUI::OnMouseUp);
  CEventSignature2<MouseDoubleClickEvent,CHitArea *,enum ButtonCode_t>::RegisterMemberFunc<CInputGameUI>(
    hQueue: this->m_hEventChannel,
    pClass: (CFunctorCallback_vtbl *)this,
    pfnProxied: (void (__thiscall *)(CInputGameUI *, CHitArea *const *, const ButtonCode_t *))CInputGameUI::OnMouseDoubleClick);
  m_hEventChannel = this->m_hEventChannel;
  v4 = (CFunctorCallback *)MemAlloc_Alloc(nSize: 0x14u);
  if ( v4 != nullptr )
  {
    v4[2].__vftable = (CFunctorCallback_vtbl *)1;
    v4->__vftable = (CFunctorCallback_vtbl *)&CMemberFunctorCallback2<CInputGameUI,CHitArea *,int,CFuncMemPolicyNone>::`vftable'{for `CFunctorCallback'};
    v4[1].__vftable = (CFunctorCallback_vtbl *)&CMemberFunctorCallback2<CInputGameUI,CHitArea *,int,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    v4[3].__vftable = (CFunctorCallback_vtbl *)CTextureDictionary::BindTextureToMaterial2;
    v4[4].__vftable = (CFunctorCallback_vtbl *)this;
    v5 = v4;
  }
  else
  {
    v5 = nullptr;
  }
  v6 = (EventId_t__ *)`MouseWheelEvent::GetEventId'::`2'::s_nEventId;
  if ( `MouseWheelEvent::GetEventId'::`2'::s_nEventId == 0 )
  {
    v6 = g_pEventSystem->RegisterEvent(this: g_pEventSystem, a2: "MouseWheelEvent");
    `MouseWheelEvent::GetEventId'::`2'::s_nEventId = (int)v6;
  }
  g_pEventSystem->RegisterListener(this: g_pEventSystem, a2: v6, a3: m_hEventChannel, a4: v5);
  CEventSignature2<KeyDownEvent,CHitArea *,enum ButtonCode_t>::RegisterMemberFunc<CInputGameUI>(
    hQueue: this->m_hEventChannel,
    pClass: (CFunctorCallback_vtbl *)this,
    pfnProxied: (void (__thiscall *)(CInputGameUI *, CHitArea *const *, const ButtonCode_t *))CInputGameUI::OnKeyDown);
  CEventSignature2<KeyUpEvent,CHitArea *,enum ButtonCode_t>::RegisterMemberFunc<CInputGameUI>(
    hQueue: this->m_hEventChannel,
    pClass: (CFunctorCallback_vtbl *)this,
    pfnProxied: (void (__thiscall *)(CInputGameUI *, CHitArea *const *, const ButtonCode_t *))CInputGameUI::OnKeyUp);
  CEventSignature2<KeyCodeTypedEvent,CHitArea *,enum ButtonCode_t>::RegisterMemberFunc<CInputGameUI>(
    hQueue: this->m_hEventChannel,
    pClass: (CFunctorCallback_vtbl *)this,
    pfnProxied: (void (__thiscall *)(CInputGameUI *, CHitArea *const *, const ButtonCode_t *))CInputGameUI::OnKeyCodeTyped);
  CEventSignature2<KeyTypedEvent,CHitArea *,wchar_t>::RegisterMemberFunc<CInputGameUI>(
    hQueue: this->m_hEventChannel,
    pClass: (CFunctorCallback_vtbl *)this,
    pfnProxied: (void (__thiscall *)(CInputGameUI *, CHitArea *const *, const wchar_t *))CInputGameUI::OnKeyTyped);
  CEventSignature1<LoseKeyFocusEvent,CHitArea *>::RegisterMemberFunc<CInputGameUI>(
    hQueue: this->m_hEventChannel,
    pClass: (CFunctorCallback_vtbl *)this,
    pfnProxied: (void (__thiscall *)(CInputGameUI *, CHitArea *const *))CInputGameUI::OnLoseKeyFocus);
  CEventSignature1<GainKeyFocusEvent,CHitArea *>::RegisterMemberFunc<CInputGameUI>(
    hQueue: this->m_hEventChannel,
    pClass: (CFunctorCallback_vtbl *)this,
    pfnProxied: (void (__thiscall *)(CInputGameUI *, CHitArea *const *))CInputGameUI::OnGainKeyFocus);
}

//------------------------------------------------------------------------------
// Address: 0x004164A0
// Name: public: void CInputGameUI::RunFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputGameUI::RunFrame(CInputGameUI *this)
{
  CInputGameUI *v1; // ebp
  int v2; // eax
  unsigned int m_hContext; // eax
  CInputGameUI::InputContext_t *p_m_DefaultInputContext; // esi
  bool *mouseDoublePressed; // eax
  int i; // ecx
  bool *keyTyped; // eax
  int j; // ecx
  vgui::IBorder *RequestedKeyFocus; // eax
  unsigned int v10; // eax
  CFunctorData_vtbl *keyFocus; // edi
  CHitArea *v12; // eax
  CFunctorData *v13; // eax
  CFunctorData *v14; // esi
  EventId_t__ *v15; // eax
  CFunctorData *v16; // eax
  CFunctorData *v17; // esi
  EventId_t__ *v18; // eax
  ButtonCode_t Dependencies; // eax
  int mousePressed; // [esp+2Ch] [ebp-8h]

  v1 = this;
  if ( this->m_nDebugMessages == -1 )
  {
    v2 = _CommandLine();
    v1->m_nDebugMessages = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v2 + 40))(a1: v2, a2: "-debuggameui") != 0;
  }
  m_hContext = v1->m_hContext;
  if ( m_hContext == -1 )
  {
    p_m_DefaultInputContext = &v1->m_DefaultInputContext;
    mousePressed = (int)v1->m_DefaultInputContext._mousePressed;
  }
  else
  {
    mousePressed = (int)&v1->m_Contexts.m_Memory.m_pMemory[m_hContext];
    p_m_DefaultInputContext = (CInputGameUI::InputContext_t *)mousePressed;
  }
  mouseDoublePressed = p_m_DefaultInputContext->_mouseDoublePressed;
  for ( i = 7; i != 0; --i )
  {
    *(mouseDoublePressed - 7) = false;
    *mouseDoublePressed = false;
    mouseDoublePressed[14] = false;
    ++mouseDoublePressed;
  }
  keyTyped = p_m_DefaultInputContext->_keyTyped;
  for ( j = 307; j != 0; --j )
  {
    *(keyTyped - 307) = false;
    *keyTyped = false;
    keyTyped[614] = false;
    ++keyTyped;
  }
  RequestedKeyFocus = CGameUISystemMgr::GetRequestedKeyFocus(this: (vgui::Panel *)g_pGameUISystemMgrImpl);
  if ( RequestedKeyFocus != nullptr )
  {
    keyFocus = (CFunctorData_vtbl *)RequestedKeyFocus;
  }
  else
  {
    v10 = v1->m_hContext;
    if ( v10 == -1 )
      keyFocus = (CFunctorData_vtbl *)v1->m_DefaultInputContext._keyFocus;
    else
      keyFocus = (CFunctorData_vtbl *)v1->m_Contexts.m_Memory.m_pMemory[v10].m_Element._keyFocus;
  }
  v12 = p_m_DefaultInputContext->_keyFocus;
  if ( v12 != (CHitArea *)keyFocus )
  {
    if ( v12 != nullptr )
    {
      v13 = (CFunctorData *)MemAlloc_Alloc(nSize: 0x10u);
      if ( v13 != nullptr )
      {
        v13[2].__vftable = (CFunctorData_vtbl *)1;
        v13->__vftable = (CFunctorData_vtbl *)&CFunctorData1<CHitArea *>::`vftable'{for `CFunctorData'};
        v13[1].__vftable = (CFunctorData_vtbl *)&CFunctorData1<CHitArea *>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
        v13[3].__vftable = (CFunctorData_vtbl *)p_m_DefaultInputContext->_keyFocus;
        v14 = v13;
      }
      else
      {
        v14 = nullptr;
      }
      v15 = (EventId_t__ *)`LoseKeyFocusEvent::GetEventId'::`2'::s_nEventId;
      if ( `LoseKeyFocusEvent::GetEventId'::`2'::s_nEventId == 0 )
      {
        v15 = g_pEventSystem->RegisterEvent(this: g_pEventSystem, a2: "LoseKeyFocusEvent");
        `LoseKeyFocusEvent::GetEventId'::`2'::s_nEventId = (int)v15;
      }
      g_pEventSystem->PostEventInternal(this: g_pEventSystem, a2: v15, a3: nullptr, a4: nullptr, a5: v14);
      p_m_DefaultInputContext = (CInputGameUI::InputContext_t *)mousePressed;
    }
    if ( keyFocus != nullptr )
    {
      v16 = (CFunctorData *)MemAlloc_Alloc(nSize: 0x10u);
      if ( v16 != nullptr )
      {
        v16[2].__vftable = (CFunctorData_vtbl *)1;
        v16->__vftable = (CFunctorData_vtbl *)&CFunctorData1<CHitArea *>::`vftable'{for `CFunctorData'};
        v16[1].__vftable = (CFunctorData_vtbl *)&CFunctorData1<CHitArea *>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
        v16[3].__vftable = keyFocus;
        v17 = v16;
      }
      else
      {
        v17 = nullptr;
      }
      v18 = (EventId_t__ *)`GainKeyFocusEvent::GetEventId'::`2'::s_nEventId;
      if ( `GainKeyFocusEvent::GetEventId'::`2'::s_nEventId == 0 )
      {
        v18 = g_pEventSystem->RegisterEvent(this: g_pEventSystem, a2: "GainKeyFocusEvent");
        `GainKeyFocusEvent::GetEventId'::`2'::s_nEventId = (int)v18;
      }
      g_pEventSystem->PostEventInternal(this: g_pEventSystem, a2: v18, a3: nullptr, a4: nullptr, a5: v17);
      p_m_DefaultInputContext = (CInputGameUI::InputContext_t *)mousePressed;
    }
    v1 = this;
    p_m_DefaultInputContext->_keyFocus = (CHitArea *)keyFocus;
    p_m_DefaultInputContext->_bKeyTrap = false;
  }
  Dependencies = CBaseAppSystem<IDataModel>::GetDependencies(this: (vgui::CTreeViewListControl *)&p_m_DefaultInputContext->m_keyRepeater);
  if ( Dependencies != BUTTON_CODE_NONE )
    CInputGameUI::InternalKeyCodePressed(this: v1, code: Dependencies);
}

//------------------------------------------------------------------------------
// Address: 0x00416690
// Name: public: void CInputGameUI::ForceInputFocusUpdate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputGameUI::ForceInputFocusUpdate(CInputGameUI *this)
{
  unsigned int m_Head; // esi
  UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int> *m_pMemory; // eax
  int v4; // esi
  CHitArea *MouseFocus; // eax
  CHitArea *v6; // eax

  m_Head = this->m_Contexts.m_Head;
  if ( m_Head != -1 )
  {
    m_pMemory = this->m_Contexts.m_Memory.m_pMemory;
    do
    {
      v4 = m_Head;
      MouseFocus = CGameUISystemMgr::GetMouseFocus(
                     this: g_pGameUISystemMgrImpl,
                     x: m_pMemory[v4].m_Element.m_nCursorX,
                     y: m_pMemory[v4].m_Element.m_nCursorY);
      CInputGameUI::SetMouseFocus(this, newMouseFocus: MouseFocus);
      m_pMemory = this->m_Contexts.m_Memory.m_pMemory;
      m_Head = m_pMemory[v4].m_Next;
    }
    while ( m_Head != -1 );
  }
  v6 = CGameUISystemMgr::GetMouseFocus(
         this: g_pGameUISystemMgrImpl,
         x: this->m_DefaultInputContext.m_nCursorX,
         y: this->m_DefaultInputContext.m_nCursorY);
  CInputGameUI::SetMouseFocus(this, newMouseFocus: v6);
}

//------------------------------------------------------------------------------
// Address: 0x00416710
// Name: public: virtual void CInputGameUI::OnChangeIME(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputGameUI::OnChangeIME(CInputGameUI *this, bool forward)
{
  int KeyboardLayoutList; // eax
  unsigned int v3; // edi
  HKL *v4; // ebx
  HKL__ **m_pElements; // edx
  int v6; // esi
  vgui::TreeNode **v7; // ebp
  int v8; // eax
  _WORD *m_nAllocationCount; // ebp
  HKL__ *currentKb; // [esp+Ch] [ebp-1Ch]
  int currentKba; // [esp+Ch] [ebp-1Ch]
  CUtlVector<HKL__ *,CUtlMemory<HKL__ *,int> > selections; // [esp+10h] [ebp-18h] BYREF
  int v13; // [esp+24h] [ebp-4h]

  selections.m_Memory.m_pMemory = (HKL__ **)GetKeyboardLayout(idThread: 0);
  KeyboardLayoutList = GetKeyboardLayoutList(nBuff: 0, lpList: nullptr);
  v3 = KeyboardLayoutList;
  if ( KeyboardLayoutList != 0 )
  {
    v4 = (HKL *)MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)KeyboardLayoutList >> 30 != 0 ? -1 : 4 * KeyboardLayoutList);
    GetKeyboardLayoutList(nBuff: v3, lpList: v4);
    m_pElements = nullptr;
    v6 = 0;
    currentKb = nullptr;
    memset(&selections.m_Memory.m_nAllocationCount, 0, 16);
    v13 = 0;
    v7 = (vgui::TreeNode **)v4;
    do
    {
      v8 = 0;
      if ( v6 <= 0 )
      {
LABEL_6:
        CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
          this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&selections.m_Memory.m_nAllocationCount,
          elem: (int)m_pElements,
          src: v7);
        m_pElements = selections.m_pElements;
        if ( *v7 == (vgui::TreeNode *)selections.m_Memory.m_pMemory )
          currentKb = (HKL__ *)((char *)selections.m_pElements - 1);
      }
      else
      {
        while ( LOWORD(v4[v8]) != *(_WORD *)v7 )
        {
          if ( ++v8 >= v6 )
            goto LABEL_6;
        }
      }
      ++v6;
      ++v7;
    }
    while ( v6 < v3 );
    m_nAllocationCount = (_WORD *)selections.m_Memory.m_nAllocationCount;
    currentKba = (int)currentKb + 2 * forward - 1;
    if ( currentKba >= 0 )
    {
      if ( currentKba >= (int)m_pElements )
        currentKba = 0;
    }
    else
    {
      currentKba = (int)m_pElements - 1 < 0 ? 0 : (unsigned int)m_pElements - 1;
    }
    ActivateKeyboardLayout(hkl: *(HKL *)(selections.m_Memory.m_nAllocationCount + 4 * currentKba), Flags: 0);
    SpewIMEInfo(a1: currentKba, langid: m_nAllocationCount[2 * currentKba]);
    free(pMem: v4);
    if ( selections.m_Size >= 0 && m_nAllocationCount != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00416850
// Name: public: virtual int CInputGameUI::GetIMELanguageList(struct CInputGameUI::LanguageItem __near *,int)
// Source: json
//------------------------------------------------------------------------------
HKL__ **__thiscall CInputGameUI::GetIMELanguageList(
        CInputGameUI *this,
        CInputGameUI::LanguageItem *dest,
        int destcount)
{
  int KeyboardLayoutList; // eax
  unsigned int v4; // edi
  HKL__ **m_pMemory; // ebp
  HKL__ **m_pElements; // edx
  int v7; // esi
  vgui::TreeNode **v8; // ebx
  int v9; // eax
  _DWORD *m_nAllocationCount; // ebx
  CInputGameUI::LanguageItem *v11; // esi
  int i; // ebp
  int v13; // eax
  HKL v14; // ebx
  int v15; // ecx
  unsigned int v16; // eax
  int v17; // edi
  HKL KeyboardLayout; // eax
  bool v19; // zf
  CUtlVector<HKL__ *,CUtlMemory<HKL__ *,int> > selections; // [esp+Ch] [ebp-18h] BYREF
  int v22; // [esp+20h] [ebp-4h]

  KeyboardLayoutList = GetKeyboardLayoutList(nBuff: 0, lpList: nullptr);
  v4 = KeyboardLayoutList;
  if ( KeyboardLayoutList == 0 )
    return nullptr;
  m_pMemory = (HKL__ **)MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)KeyboardLayoutList >> 30 != 0 ? -1 : 4 * KeyboardLayoutList);
  selections.m_Memory.m_pMemory = m_pMemory;
  GetKeyboardLayoutList(nBuff: v4, lpList: m_pMemory);
  m_pElements = nullptr;
  v7 = 0;
  memset(&selections.m_Memory.m_nAllocationCount, 0, 16);
  v22 = 0;
  v8 = (vgui::TreeNode **)m_pMemory;
  do
  {
    v9 = 0;
    if ( v7 <= 0 )
    {
LABEL_6:
      CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
        this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&selections.m_Memory.m_nAllocationCount,
        elem: (int)m_pElements,
        src: v8);
      m_pElements = selections.m_pElements;
    }
    else
    {
      while ( LOWORD(m_pMemory[v9]) != *(_WORD *)v8 )
      {
        if ( ++v9 >= v7 )
          goto LABEL_6;
      }
    }
    ++v7;
    ++v8;
  }
  while ( v7 < v4 );
  m_nAllocationCount = (_DWORD *)selections.m_Memory.m_nAllocationCount;
  v11 = dest;
  if ( dest != nullptr )
  {
    for ( i = 0; ; ++i )
    {
      v13 = destcount;
      if ( (int)m_pElements < destcount )
        v13 = (int)m_pElements;
      if ( i >= v13 )
        break;
      v14 = (HKL)m_nAllocationCount[i];
      v15 = 0;
      v16 = 0;
      while ( g_LanguageIds[v16].id != (_WORD)v14 )
      {
        ++v16;
        ++v15;
        if ( v16 >= 168 )
        {
          v17 = 0;
          goto LABEL_17;
        }
      }
      v17 = 20 * v15 + 5999248;
LABEL_17:
      memset(dst: (int)v11, value: nullptr, count: sizeof(CInputGameUI::LanguageItem));
      wcsncpy(dest: v11->shortname, source: *(const wchar_t **)(v17 + 8), count: 4u);
      v11->shortname[3] = 0;
      wcsncpy(dest: v11->menuname, source: *(const wchar_t **)(v17 + 12), count: 0x80u);
      v11->menuname[127] = 0;
      v11->handleValue = (int)v14;
      KeyboardLayout = GetKeyboardLayout(idThread: 0);
      m_pElements = selections.m_pElements;
      v19 = v14 == KeyboardLayout;
      m_nAllocationCount = (_DWORD *)selections.m_Memory.m_nAllocationCount;
      v11->active = v19;
      ++v11;
    }
    m_pMemory = selections.m_Memory.m_pMemory;
  }
  free(pMem: m_pMemory);
  if ( selections.m_Size >= 0 && m_nAllocationCount != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_nAllocationCount);
  return selections.m_pElements;
}

//------------------------------------------------------------------------------
// Address: 0x00416AF0
// Name: public: virtual unsigned int CInputGameUI::CreateInputContext(void)
// Source: json
//------------------------------------------------------------------------------
signed int __thiscall CInputGameUI::CreateInputContext(CInputGameUI *this)
{
  CUtlLinkedList<CInputGameUI::InputContext_t,unsigned int,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int>,unsigned int> > *p_m_Contexts; // edi
  signed int v3; // ebx

  p_m_Contexts = &this->m_Contexts;
  v3 = CUtlLinkedList<CInputGameUI::InputContext_t,unsigned int,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int>,unsigned int>>::InsertBefore(
         this: &this->m_Contexts,
         before: 0xFFFFFFFF);
  CInputGameUI::InitInputContext(this, pContext: &p_m_Contexts->m_Memory.m_pMemory[v3].m_Element);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00416B20
// Name: public: CInputGameUI::CInputGameUI(void)
// Source: json
//------------------------------------------------------------------------------
CInputGameUI *__thiscall CInputGameUI::CInputGameUI(CInputGameUI *this)
{
  CInputGameUI::InputContext_t *p_m_DefaultInputContext; // edi
  UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int> *m_pMemory; // eax

  this->__vftable = (CInputGameUI_vtbl *)&CInputGameUI::`vftable';
  p_m_DefaultInputContext = &this->m_DefaultInputContext;
  this->m_DefaultInputContext.m_KeyCodeUnhandledListeners.m_Memory.m_pMemory = nullptr;
  this->m_DefaultInputContext.m_KeyCodeUnhandledListeners.m_Memory.m_nAllocationCount = 0;
  this->m_DefaultInputContext.m_KeyCodeUnhandledListeners.m_Memory.m_nGrowSize = 0;
  this->m_DefaultInputContext.m_KeyCodeUnhandledListeners.m_Size = 0;
  this->m_DefaultInputContext.m_KeyCodeUnhandledListeners.m_pElements = nullptr;
  CKeyRepeatHandler::CKeyRepeatHandler(this: &this->m_DefaultInputContext.m_keyRepeater);
  this->m_Contexts.m_Memory.m_pMemory = nullptr;
  this->m_Contexts.m_Memory.m_nAllocationCount = 0;
  this->m_Contexts.m_Memory.m_nGrowSize = 0;
  this->m_Contexts.m_LastAlloc.index = -1;
  m_pMemory = this->m_Contexts.m_Memory.m_pMemory;
  this->m_Contexts.m_Head = -1;
  this->m_Contexts.m_Tail = -1;
  this->m_Contexts.m_FirstFree = -1;
  this->m_Contexts.m_ElementCount = 0;
  this->m_Contexts.m_NumAlloced = 0;
  this->m_Contexts.m_pElements = m_pMemory;
  this->m_nDebugMessages = -1;
  this->_imeWnd = nullptr;
  this->_imeCandidates = nullptr;
  CInputGameUI::InitInputContext(this, pContext: p_m_DefaultInputContext);
  this->m_hContext = -1;
  this->m_nWindowWidth = 0;
  this->m_nWindowHeight = 0;
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
  this->_keyTrans[51] = (char *)&unk_53AE74;
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
  this->_keyTrans[64] = (char *)&unk_53ADA8;
  this->_keyTrans[65] = "  KEY_SPACE";
  this->_keyTrans[66] = (char *)&unk_53AD8C;
  this->_keyTrans[67] = (char *)&unk_53AD80;
  this->_keyTrans[68] = (char *)&unk_53AD70;
  this->_keyTrans[69] = (char *)&unk_53AD60;
  this->_keyTrans[70] = (char *)&unk_53AD50;
  this->_keyTrans[71] = (char *)&unk_53AD3C;
  this->_keyTrans[72] = (char *)&unk_53AD2C;
  this->_keyTrans[73] = (char *)&unk_53AD1C;
  this->_keyTrans[74] = (char *)&unk_53AD10;
  this->_keyTrans[75] = (char *)&unk_53AD04;
  this->_keyTrans[76] = (char *)&unk_53ACF4;
  this->_keyTrans[77] = (char *)&unk_53ACE4;
  this->_keyTrans[78] = (char *)&unk_53ACD8;
  this->_keyTrans[79] = (char *)&unk_53ACC8;
  this->_keyTrans[80] = (char *)&unk_53ACB8;
  this->_keyTrans[81] = (char *)&unk_53ACAC;
  this->_keyTrans[82] = (char *)&unk_53ACA0;
  this->_keyTrans[83] = (char *)&unk_53AC8C;
  this->_keyTrans[84] = (char *)&unk_53AC78;
  this->_keyTrans[85] = (char *)&unk_53AC6C;
  this->_keyTrans[86] = (char *)&unk_53AC60;
  this->_keyTrans[87] = (char *)&unk_53AC54;
  this->_keyTrans[88] = (char *)&unk_53AC48;
  this->_keyTrans[89] = (char *)&unk_53AC3C;
  this->_keyTrans[90] = (char *)&unk_53AC30;
  this->_keyTrans[91] = (char *)&unk_53AC24;
  this->_keyTrans[92] = (char *)&unk_53AC18;
  this->_keyTrans[93] = (char *)&unk_53AC0C;
  this->_keyTrans[94] = (char *)&unk_53AC00;
  this->_keyTrans[95] = (char *)&unk_53ABF4;
  this->_keyTrans[96] = (char *)&unk_53ABE8;
  this->_keyTrans[97] = (char *)&unk_53ABDC;
  this->_keyTrans[98] = (char *)&unk_53ABD0;
  this->_keyTrans[99] = (char *)&unk_53ABC4;
  this->_keyTrans[100] = (char *)&unk_53ABB8;
  this->_keyTrans[101] = (char *)&unk_53ABAC;
  this->_keyTrans[102] = (char *)&unk_53ABA0;
  this->_keyTrans[103] = (char *)&unk_53AB94;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00416F90
// Name: public: CInputGameUI::~CInputGameUI(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputGameUI::~CInputGameUI(CInputGameUI *this)
{
  tagCANDIDATELIST *imeCandidates; // eax
  CUtlLinkedList<CInputGameUI::InputContext_t,unsigned int,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int>,unsigned int> > *p_m_Contexts; // esi

  imeCandidates = this->_imeCandidates;
  this->__vftable = (CInputGameUI_vtbl *)&CInputGameUI::`vftable';
  if ( imeCandidates != nullptr )
  {
    free(pMem: imeCandidates);
    this->_imeCandidates = nullptr;
  }
  p_m_Contexts = &this->m_Contexts;
  CUtlLinkedList<CInputGameUI::InputContext_t,unsigned int,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int>,unsigned int>>::RemoveAll(this: &this->m_Contexts);
  if ( this->m_Contexts.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_Contexts->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_Contexts->m_Memory.m_pMemory);
      p_m_Contexts->m_Memory.m_pMemory = nullptr;
    }
    this->m_Contexts.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_DefaultInputContext.m_KeyCodeUnhandledListeners);
}

//------------------------------------------------------------------------------
// Address: 0x00417000
// Name: public: virtual void CInputGameUI::DestroyInputContext(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInputGameUI::DestroyInputContext(CInputGameUI *this, unsigned int context)
{
  CUtlLinkedList<CInputGameUI::InputContext_t,unsigned int,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int>,unsigned int> > *p_m_Contexts; // edi
  UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int> *v4; // esi

  if ( this->m_hContext == context )
    this->ActivateInputContext(this, a2: -1u);
  p_m_Contexts = &this->m_Contexts;
  CUtlLinkedList<CInputGameUI::InputContext_t,unsigned int,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<CInputGameUI::InputContext_t,unsigned int>,unsigned int>>::Unlink(
    this: &this->m_Contexts,
    elem: context);
  v4 = &this->m_Contexts.m_Memory.m_pMemory[context];
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v4->m_Element.m_KeyCodeUnhandledListeners);
  v4->m_Next = p_m_Contexts->m_FirstFree;
  p_m_Contexts->m_FirstFree = context;
}

//------------------------------------------------------------------------------
// Address: 0x004367B0
// Name: public: virtual int CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>::AddRef(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>::AddRef(
        CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > *this)
{
  return _InterlockedIncrement(&this->m_iRefs);
}

//------------------------------------------------------------------------------
// Address: 0x004367C0
// Name: public: virtual int CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>::Release(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>::Release(
        CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > *this)
{
  CRefCountServiceBase<1,CRefMT> *v1; // esi
  int result; // eax

  v1 = &this->CRefCountServiceBase<1,CRefMT>;
  result = _InterlockedDecrement(&this->m_iRefs);
  if ( result == 0 )
  {
    if ( v1->OnFinalRelease(this: v1) )
      ((void (__thiscall *)(CRefCountServiceBase<1,CRefMT> *, int))v1->dtr_CRefCountServiceBase<1,CRefMT>)(
        a1: v1,
        a2: 1);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00473430
// Name: protected: virtual void CFunctorCallbackBase::ValidateFunctorData(class CFunctorData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFunctorCallbackBase::ValidateFunctorData(vgui::TreeView *this, int itemIndex)
{
  ;
}
