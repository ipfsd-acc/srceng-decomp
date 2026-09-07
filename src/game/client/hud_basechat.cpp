// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/hud_basechat.cpp
// Functions: 91
// ============================================================

#include "game\client\hud_basechat.h"

//------------------------------------------------------------------------------
// Address: 0x100F3B80
// Name: wchar_t __near * CloneWString(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
wchar_t *__cdecl CloneWString(const wchar_t *str)
{
  unsigned int v1; // kr00_4
  wchar_t *result; // eax
  const wchar_t *v3; // ecx
  wchar_t v4; // dx

  v1 = wcslen(str);
  result = (wchar_t *)MemAlloc_Alloc(nSize: (unsigned __int64)(v1 + 1) >> 31 != 0 ? -1 : 2 * (v1 + 1));
  v3 = str;
  do
  {
    v4 = *v3;
    *(const wchar_t *)((char *)v3 + (char *)result - (char *)str) = *v3;
    ++v3;
  }
  while ( v4 != 0 );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100F3BE0
// Name: public: static char const __near * CHudChatHistory::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CHudChatHistory::GetPanelClassName()
{
  return "CHudChatHistory";
}

//------------------------------------------------------------------------------
// Address: 0x100F3BF0
// Name: public: static char const __near * CHudChatFilterButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CHudChatFilterButton::GetPanelClassName()
{
  return "CHudChatFilterButton";
}

//------------------------------------------------------------------------------
// Address: 0x100F3C00
// Name: public: static char const __near * CHudChatFilterCheckButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CHudChatFilterCheckButton::GetPanelClassName()
{
  return "CHudChatFilterCheckButton";
}

//------------------------------------------------------------------------------
// Address: 0x100F3C10
// Name: public: static char const __near * CBaseHudChat::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CBaseHudChat::GetPanelClassName()
{
  return "CBaseHudChat";
}

//------------------------------------------------------------------------------
// Address: 0x100F3C20
// Name: public: static char const __near * vgui::TextEntry::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::TextEntry::GetPanelClassName()
{
  return "TextEntry";
}

//------------------------------------------------------------------------------
// Address: 0x100F3C30
// Name: public: virtual void vgui::TextEntry::SetAutoLocalize(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextEntry::SetAutoLocalize(vgui::TextEntry *this, bool bState)
{
  this->m_bAutoLocalize = bState;
}

//------------------------------------------------------------------------------
// Address: 0x100F3C40
// Name: public: virtual void CBaseHudChatEntry::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseHudChatEntry::ApplySchemeSettings(CBaseHudChatEntry *this, vgui::IScheme *pScheme)
{
  vgui::TextEntry::ApplySchemeSettings(this, pScheme);
  this->SetPaintBorderEnabled(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x100F3C70
// Name: public: static char const __near * CHudChatFilterPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CHudChatFilterPanel::GetPanelClassName()
{
  return "CHudChatFilterPanel";
}

//------------------------------------------------------------------------------
// Address: 0x100F3C80
// Name: public: class CBaseHudChat __near * CHudChatFilterPanel::GetChatParent(void)
// Source: json
//------------------------------------------------------------------------------
CBaseHudChat *__thiscall CHudChatFilterPanel::GetChatParent(CHudChatFilterPanel *this)
{
  vgui::Panel *v1; // eax

  v1 = this->GetParent(this);
  return (CBaseHudChat *)__RTDynamicCast(
                           inptr: v1,
                           VfDelta: 0,
                           SrcType: &vgui::Panel `RTTI Type Descriptor',
                           TargetType: &CBaseHudChat `RTTI Type Descriptor',
                           isReference: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100F3CB0
// Name: char __near * RemoveColorMarkup(char __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl RemoveColorMarkup(char *str)
{
  char *result; // eax
  char *v2; // esi
  char *i; // edx
  char v4; // cl

  result = str;
  v2 = str;
  for ( i = str; *i != 0; ++i )
  {
    v4 = *i;
    if ( *i <= 0 || v4 >= 8 )
      *v2++ = v4;
  }
  *v2 = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100F3CE0
// Name: wchar_t __near * ConvertCRtoNL(wchar_t __near *)
// Source: json
//------------------------------------------------------------------------------
wchar_t *__cdecl ConvertCRtoNL(wchar_t *str)
{
  wchar_t *result; // eax
  wchar_t *i; // ecx

  result = str;
  for ( i = str; *i != 0; ++i )
  {
    if ( *i == 13 )
      *i = 10;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100F3D10
// Name: wchar_t __near * ReadLocalizedString(class bf_read __near &,wchar_t __near *,int,bool,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
wchar_t *__usercall ReadLocalizedString@<eax>(
        int a1@<esi>,
        bf_read *msg,
        wchar_t *pOut,
        unsigned int outSize,
        bool bStripNewline,
        char *originalString,
        int originalSize)
{
  const wchar_t *v7; // eax
  wchar_t *result; // eax
  __int16 v9; // cx
  int v10; // eax
  int v11; // ecx
  char szString[2048]; // [esp+0h] [ebp-800h] BYREF

  szString[0] = 0;
  CBitRead::ReadString(this: msg, pStr: szString, maxLen: 2048, bLine: false, pOutNumChars: nullptr);
  if ( originalString != nullptr )
    V_strncpy(pDest: originalString, pSrc: szString, maxLen: originalSize);
  v7 = (const wchar_t *)((int (__thiscall *)(vgui::ILocalize *, char *, int))g_pVGuiLocalize->Find)(
                          a1: g_pVGuiLocalize,
                          a2: szString,
                          a3: a1);
  if ( v7 != nullptr )
  {
    wcsncpy(dest: pOut, source: v7, count: outSize >> 1);
    pOut[(outSize >> 1) - 1] = 0;
  }
  else
  {
    g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: szString, a3: pOut, a4: outSize);
  }
  result = pOut;
  if ( bStripNewline )
  {
    do
      v9 = *result++;
    while ( v9 != 0 );
    v10 = result - (pOut + 1) - 1;
    if ( v10 >= 0 )
    {
      v11 = pOut[v10];
      if ( v11 == 10 || v11 == 13 )
        pOut[v10] = 0;
    }
    return pOut;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100F3DE0
// Name: wchar_t __near * ReadChatTextString(class bf_read __near &,wchar_t __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
wchar_t *__cdecl ReadChatTextString(bf_read *msg, wchar_t *pOut, int outSize)
{
  signed int v3; // eax
  int v4; // ecx
  wchar_t *i; // ecx
  unsigned int v6; // eax
  char szString[2048]; // [esp+4h] [ebp-800h] BYREF

  szString[0] = 0;
  CBitRead::ReadString(this: msg, pStr: szString, maxLen: 2048, bLine: false, pOutNumChars: nullptr);
  g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: szString, a3: pOut, a4: outSize);
  v3 = wcslen(pOut) - 1;
  if ( v3 >= 0 )
  {
    v4 = pOut[v3];
    if ( v4 == 10 || v4 == 13 )
      pOut[v3] = 0;
  }
  for ( i = pOut; i != nullptr; ++i )
  {
    v6 = *i;
    if ( (_WORD)v6 == 0 )
      break;
    if ( v6 < 8 )
      *i = 1;
  }
  return pOut;
}

//------------------------------------------------------------------------------
// Address: 0x100F3E90
// Name: public: CBaseHudChatInputLine::CBaseHudChatInputLine(class CBaseHudChat __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseHudChatInputLine *__thiscall CBaseHudChatInputLine::CBaseHudChatInputLine(
        CBaseHudChatInputLine *this,
        vgui::TextEntry_vtbl *parent,
        const char *panelName)
{
  vgui::EditablePanel *p_RequestFocusNext; // eax
  vgui::Label *v5; // eax
  vgui::Label *v6; // eax
  vgui::TextEntry *v7; // eax
  vgui::TextEntry *v8; // esi
  CBaseHudChatEntry *v9; // ecx

  if ( parent != nullptr )
    p_RequestFocusNext = (vgui::EditablePanel *)&parent->RequestFocusNext;
  else
    p_RequestFocusNext = nullptr;
  vgui::Panel::Panel(this, parent: p_RequestFocusNext, panelName);
  this->__vftable = (CBaseHudChatInputLine_vtbl *)&CBaseHudChatInputLine::`vftable';
  vgui::Panel::SetMouseInputEnabled(this, state: 0);
  v5 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v5 != nullptr )
    v6 = vgui::Label::Label(this: v5, parent: this, panelName: "ChatInputPrompt", wszText: L"Enter text:");
  else
    v6 = nullptr;
  this->m_pPrompt = v6;
  v7 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x440u);
  v8 = v7;
  if ( v7 != nullptr )
  {
    vgui::TextEntry::TextEntry(this: v7, parent: this, panelName: "ChatInput");
    v8->__vftable = (vgui::TextEntry_vtbl *)&CBaseHudChatEntry::`vftable';
    vgui::TextEntry::SetCatchEnterKey(this: v8, state: true);
    vgui::TextEntry::SetAllowNonAsciiCharacters(this: v8, state: true);
    vgui::TextEntry::SetDrawLanguageIDAtLeft(this: v8, state: true);
    v8[1].__vftable = parent;
    v9 = (CBaseHudChatEntry *)v8;
  }
  else
  {
    v9 = nullptr;
  }
  this->m_pInput = v9;
  v9->SetMaximumCharCount(this: v9, a2: 127);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100F3F60
// Name: public: static char const __near * vgui::Panel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::Panel::GetPanelClassName()
{
  return "Panel";
}

//------------------------------------------------------------------------------
// Address: 0x100F3F70
// Name: public: virtual unsigned int CBaseHudChatInputLine::GetCurrentKeyFocus(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CBaseHudChatInputLine::GetCurrentKeyFocus(CBaseHudChatInputLine *this)
{
  return this->m_pInput->GetVPanel(this: this->m_pInput);
}

//------------------------------------------------------------------------------
// Address: 0x100F3F90
// Name: public: virtual void CBaseHudChatInputLine::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseHudChatInputLine::PerformLayout(CBaseHudChatInputLine *this)
{
  int h; // [esp+4h] [ebp-10h] BYREF
  int wide; // [esp+8h] [ebp-Ch] BYREF
  int w; // [esp+Ch] [ebp-8h] BYREF
  int tall; // [esp+10h] [ebp-4h] BYREF

  vgui::Panel::PerformLayout(this);
  vgui::Panel::GetSize(this, &wide, &tall);
  this->m_pPrompt->GetContentSize(this: this->m_pPrompt, a2: &w, a3: &h);
  vgui::Panel::SetBounds(this: this->m_pPrompt, x: 0, y: 0, wide: w, tall);
  vgui::Panel::SetBounds(this: this->m_pInput, x: w + 2, y: 0, wide: wide - w - 2, tall);
}

//------------------------------------------------------------------------------
// Address: 0x100F4010
// Name: public: virtual void CHudChatHistory::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudChatHistory::ApplySchemeSettings(CHudChatHistory *this, vgui::IScheme *pScheme)
{
  unsigned int v3; // eax

  vgui::RichText::ApplySchemeSettings(this, pScheme);
  v3 = pScheme->GetFont(this: pScheme, a2: "ChatFont", a3: false);
  vgui::RichText::SetFont(this, font: v3);
  vgui::Panel::SetAlpha(this, alpha: 255);
}

//------------------------------------------------------------------------------
// Address: 0x100F4050
// Name: public: virtual void CHudChatHistory::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudChatHistory::Paint(CHudChatHistory *this)
{
  vgui::RichText::Paint(this);
  if ( vgui::RichText::IsAllTextAlphaZero(this) && vgui::RichText::HasText(this) )
    vgui::RichText::SetText(this, text: prType);
}

//------------------------------------------------------------------------------
// Address: 0x100F4080
// Name: public: static class CBaseHudChat __near * CBaseHudChat::GetHudChat(void)
// Source: json
//------------------------------------------------------------------------------
CBaseHudChat *__cdecl CBaseHudChat::GetHudChat()
{
  return g_pHudChat;
}

//------------------------------------------------------------------------------
// Address: 0x100F4090
// Name: public: virtual CBaseHudChat::~CBaseHudChat(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseHudChat::~CBaseHudChat(CBaseHudChat *this)
{
  vgui::EditablePanel *v2; // ecx

  v2 = &this->vgui::EditablePanel;
  this->CHudElement::CGameEventListener::IGameEventListener2::__vftable = (CBaseHudChat_vtbl *)&CBaseHudChat::`vftable'{for `CHudElement'};
  v2->__vftable = (vgui::EditablePanel_vtbl *)&CBaseHudChat::`vftable'{for `vgui::EditablePanel'};
  g_pHudChat = nullptr;
  vgui::EditablePanel::~EditablePanel(this: v2);
  CHudElement::~CHudElement(this);
}

//------------------------------------------------------------------------------
// Address: 0x100F40C0
// Name: public: virtual int CBaseHudChat::GetFilterFlags(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseHudChat::GetFilterFlags(CBaseHudChat *this)
{
  return this->m_iFilterFlags;
}

//------------------------------------------------------------------------------
// Address: 0x100F40D0
// Name: public: virtual void CBaseHudChat::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseHudChat::Init(CBaseHudChat *this)
{
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: this, a3: "hltv_chat", a4: false);
}

//------------------------------------------------------------------------------
// Address: 0x100F40F0
// Name: public: virtual int CBaseHudChat::GetFilterForString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseHudChat::GetFilterForString(CBaseHudChat *this, const char *pString)
{
  return _V_stricmp(s1: pString, s2: "#HL_Name_Change") != 0 ? 0 : 2;
}

//------------------------------------------------------------------------------
// Address: 0x100F4120
// Name: public: virtual char const __near * CBaseHudChat::GetDisplayedSubtitlePlayerName(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBaseHudChat::GetDisplayedSubtitlePlayerName(CBaseHudChat *this, int clientIndex)
{
  return g_PR->GetPlayerName(this: &g_PR->IGameResources, a2: clientIndex);
}

//------------------------------------------------------------------------------
// Address: 0x100F4140
// Name: public: virtual int CBaseHudChat::GetChatInputOffset(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseHudChat::GetChatInputOffset(vgui::TextEntry *this)
{
  return this->_maxCharCount;
}

//------------------------------------------------------------------------------
// Address: 0x100F4150
// Name: public: virtual void CBaseHudChat::Printf(int,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CBaseHudChat::Printf(CBaseHudChat *this, int iFilter, char *fmt, ...)
{
  char pDest[4096]; // [esp+0h] [ebp-1000h] BYREF
  va_list params; // [esp+1014h] [ebp+14h] BYREF

  va_start(params, fmt);
  V_vsnprintf(pDest, maxLen: 0x1000u, pFormat: fmt, params);
  this->ChatPrintf(this, a2: 0, a3: iFilter, a4: "%s", pDest);
}

//------------------------------------------------------------------------------
// Address: 0x100F41A0
// Name: public: virtual void CBaseHudChat::SetChatPrompt(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseHudChat::SetChatPrompt(CBaseHudChat *this, int iMessageModeType)
{
  const wchar_t *v3; // eax
  CBaseHudChatInputLine *m_pChatInput; // esi

  if ( this->m_nMessageMode == 1 )
    v3 = g_pVGuiLocalize->FindSafe(this: g_pVGuiLocalize, a2: "#chat_say");
  else
    v3 = g_pVGuiLocalize->FindSafe(this: g_pVGuiLocalize, a2: "#chat_say_team");
  m_pChatInput = this->m_pChatInput;
  m_pChatInput->m_pPrompt->SetText(this: m_pChatInput->m_pPrompt, a2: v3, a3: false);
  m_pChatInput->InvalidateLayout(this: m_pChatInput, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x100F4200
// Name: public: void CBaseHudChat::SetFilterFlag(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseHudChat::SetFilterFlag(CBaseHudChat *this, int iFilter)
{
  this->m_iFilterFlags = iFilter;
  ConVar::SetValue(this: (ConVar *)&cl_chatfilters.IConVar, value: iFilter);
}

//------------------------------------------------------------------------------
// Address: 0x100F4220
// Name: public: virtual class Color CBaseHudChat::GetDefaultTextColor(void)
// Source: json
//------------------------------------------------------------------------------
Color *__thiscall CBaseHudChat::GetDefaultTextColor(CBaseHudChat *this, Color *result)
{
  *result = g_ColorYellow;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100F4240
// Name: public: virtual class Color CBaseHudChat::GetClientColor(int)
// Source: json
//------------------------------------------------------------------------------
Color *__thiscall CBaseHudChat::GetClientColor(CBaseHudChat *this, Color *result, int clientIndex)
{
  if ( clientIndex != 0 )
  {
    if ( g_PR != nullptr )
      *result = g_ColorGrey;
    else
      *result = g_ColorYellow;
    return result;
  }
  else
  {
    *result = g_ColorGreen;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F4280
// Name: public: class vgui::Panel __near * CBaseHudChat::GetInputPanel(void)
// Source: json
//------------------------------------------------------------------------------
CBaseHudChatEntry *__thiscall CBaseHudChat::GetInputPanel(CBaseHudChat *this)
{
  return this->m_pChatInput->m_pInput;
}

//------------------------------------------------------------------------------
// Address: 0x100F4290
// Name: public: virtual void CBaseHudChat::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseHudChat::FireGameEvent(CBaseHudChat *this, IGameEvent *event)
{
  const char *v4; // eax
  C_BasePlayer *LocalPlayer; // eax
  IClientNetworkable *v6; // esi
  const char *v7; // eax
  int v8; // eax
  IGameEvent *eventa; // [esp+10h] [ebp+8h]

  v4 = event->GetName(this: event);
  if ( _V_strcmp(s1: "hltv_chat", s2: v4) == 0 )
  {
    LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
    if ( LocalPlayer != nullptr )
    {
      eventa = (IGameEvent *)this->CHudElement::CGameEventListener::IGameEventListener2::__vftable;
      v6 = &LocalPlayer->IClientNetworkable;
      v7 = event->GetString(this: event, a2: "text", a3: prType);
      v8 = ((int (__thiscall *)(IClientNetworkable *, _DWORD, const char *, const char *))v6->entindex)(
             a1: v6,
             a2: 0,
             a3: "(SourceTV) %s",
             a4: v7);
      ((void (__cdecl *)(CBaseHudChat *, int))eventa[22].__vftable)(a1: this, a2: v8);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F4400
// Name: public: virtual struct vgui::PanelMessageMap __near * CBaseHudChat::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CBaseHudChat::GetMessageMap(CBaseHudChat *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CBaseHudChat::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseHudChat::GetMessageMap'::`2'::s_pMap;
  `CBaseHudChat::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CBaseHudChat");
  `CBaseHudChat::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100F4430
// Name: public: virtual struct PanelAnimationMap __near * CBaseHudChat::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CBaseHudChat::GetAnimMap(CBaseHudChat *this)
{
  return FindOrAddPanelAnimationMap(className: "CBaseHudChat");
}

//------------------------------------------------------------------------------
// Address: 0x100F4440
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CBaseHudChat::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CBaseHudChat::GetKBMap(CBaseHudChat *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CBaseHudChat::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseHudChat::GetKBMap'::`2'::s_pMap;
  `CBaseHudChat::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseHudChat");
  `CBaseHudChat::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100F4470
// Name: public: virtual void CBaseHudChatLine::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseHudChatLine::ApplySchemeSettings(CBaseHudChatLine *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  void (__thiscall *SetBgColor)(vgui::Panel *, Color); // edx
  vgui::IScheme_vtbl *v5; // ebx
  Color *v6; // eax
  Color v7; // [esp+Ch] [ebp-4h] BYREF

  v2 = pScheme;
  vgui::RichText::ApplySchemeSettings(this, pScheme);
  this->m_hFont = v2->GetFont(this: v2, a2: "Default", a3: false);
  SetBgColor = this->SetBgColor;
  pScheme = (vgui::IScheme *)1677721600;
  ((void (__thiscall *)(CBaseHudChatLine *, int))SetBgColor)(a1: this, a2: 1677721600);
  this->m_hFontMarlett = v2->GetFont(this: v2, a2: "Marlett", a3: false);
  v5 = v2->__vftable;
  v6 = this->GetFgColor(this, result: &pScheme);
  this->m_clrText = *v5->GetColor(this: v2, result: &v7, a3: "FgColor", a4: *v6);
  vgui::RichText::SetFont(this, font: this->m_hFont);
}

//------------------------------------------------------------------------------
// Address: 0x100F4510
// Name: public: virtual void CBaseHudChatLine::PerformFadeout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseHudChatLine::PerformFadeout(CBaseHudChatLine *this)
{
  __m128 v1; // xmm0
  int v3; // edx
  float m_flStartTime; // xmm1_4
  int v5; // ebx
  __m128d v6; // xmm0
  __m128i v7; // xmm0
  double v8; // xmm0_8
  float v9; // xmm1_4
  float v10; // xmm0_4
  float m_flExpireTime; // xmm1_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  int v14; // ecx
  wchar_t buf[4096]; // [esp+0h] [ebp-2010h] BYREF
  int v16; // [esp+2000h] [ebp-10h]
  int v17; // [esp+2004h] [ebp-Ch]
  int v18; // [esp+2008h] [ebp-8h]
  Color col; // [esp+200Ch] [ebp-4h]

  v1 = (__m128)*(unsigned int *)(gpGlobals.m_Index + 12);
  v3 = this->m_clrText._color[2];
  m_flStartTime = this->m_flStartTime;
  v5 = this->m_clrText._color[0];
  v18 = this->m_clrText._color[1];
  v17 = v3;
  if ( v1.m128_f32[0] >= m_flStartTime && (float)(m_flStartTime + 5.0) > v1.m128_f32[0] )
  {
    *(float *)&v16 = (float)(v1.m128_f32[0] - m_flStartTime) * 0.2;
    v1.m128_f32[0] = *(float *)&v16 * 8.0;
    v6 = _mm_cvtps_pd(v1);
    v6.m128d_f64[0] = v6.m128d_f64[0] * 6.283185307179586;
    v7 = (__m128i)_mm_cvtpd_ps(v6);
    *(double *)v7.m128i_i64 = *(float *)v7.m128i_i32;
    __libm_sse2_cos(X: v7);
    v9 = v8;
    if ( v9 >= 0.0 )
    {
      if ( v9 > 1.0 )
        v9 = 1.0;
    }
    else
    {
      v9 = 0.0;
    }
    v10 = (float)(1.0 - *(float *)&v16) * v9;
    v5 = (int)(float)((float)((float)(255 - v5) * v10) + (float)v5);
    v18 = (int)(float)((float)((float)(255 - v18) * v10) + (float)v18);
    v17 = (int)(float)((float)((float)(255 - v17) * v10) + (float)v17);
    goto LABEL_8;
  }
  m_flExpireTime = this->m_flExpireTime;
  if ( m_flExpireTime < v1.m128_f32[0] || v1.m128_f32[0] <= (float)(m_flExpireTime - 1.0) )
  {
LABEL_8:
    vgui::RichText::GetText(this, offset: 0, buf, bufLenInBytes: 0x2000);
    vgui::RichText::SetText(this, text: prType);
    col._color[1] = v18;
    col._color[2] = v17;
    col._color[0] = v5;
    col._color[3] = -1;
    vgui::RichText::InsertColorChange(this, col);
    vgui::RichText::InsertString(this, wszText: buf);
    goto LABEL_9;
  }
  *(float *)&col = m_flExpireTime - v1.m128_f32[0];
  v12 = (float)(m_flExpireTime - v1.m128_f32[0]) * 255.0;
  if ( (int)v12 >= 0 )
  {
    v16 = 255;
    if ( (int)v12 <= 255 )
      v16 = (int)v12;
  }
  else
  {
    *(float *)&v16 = 0.0;
  }
  vgui::RichText::GetText(this, offset: 0, buf, bufLenInBytes: 0x2000);
  vgui::RichText::SetText(this, text: prType);
  v13 = *(float *)&col;
  v14 = (int)(float)((float)v18 * *(float *)&col);
  col._color[0] = (int)(float)((float)v5 * *(float *)&col);
  col._color[1] = v14;
  col._color[2] = (int)(float)((float)v17 * v13);
  col._color[3] = v16;
  vgui::RichText::InsertColorChange(this, col);
  vgui::RichText::InsertString(this, wszText: buf);
LABEL_9:
  this->OnThink(this);
}

//------------------------------------------------------------------------------
// Address: 0x100F4770
// Name: public: virtual void CBaseHudChatInputLine::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseHudChatInputLine::ApplySchemeSettings(CBaseHudChatInputLine *this, int pScheme)
{
  vgui::IScheme *v2; // edi
  unsigned int v4; // ebx
  CBaseHudChatEntry *m_pInput; // eax
  vgui::IScheme_vtbl *v6; // ebx
  Color *(__thiscall *GetColor)(vgui::IScheme *, Color *, const char *, Color); // edx
  _DWORD *v8; // eax
  _DWORD *v9; // eax
  CBaseHudChatInputLine_vtbl *v10; // edx
  char v11[4]; // [esp+Ch] [ebp-8h] BYREF
  CBaseHudChatEntry_vtbl *v12; // [esp+10h] [ebp-4h]

  v2 = (vgui::IScheme *)pScheme;
  vgui::Panel::ApplySchemeSettings(this, pScheme);
  v4 = v2->GetFont(this: v2, a2: "ChatFont", a3: false);
  this->m_pPrompt->SetFont(this: this->m_pPrompt, a2: v4);
  this->m_pInput->SetFont(this: this->m_pInput, a2: v4);
  m_pInput = this->m_pInput;
  v6 = v2->__vftable;
  pScheme = -1;
  GetColor = v6->GetColor;
  v12 = m_pInput->__vftable;
  v8 = (_DWORD *)((int (__thiscall *)(vgui::IScheme *, int *, const char *, int))GetColor)(
                   a1: v2,
                   a2: &pScheme,
                   a3: "Panel.FgColor",
                   a4: -1);
  v9 = (_DWORD *)((int (__thiscall *)(vgui::IScheme *, char *, const char *, _DWORD))v6->GetColor)(
                   a1: v2,
                   a2: v11,
                   a3: "Chat.TypingText",
                   a4: *v8);
  ((void (__thiscall *)(CBaseHudChatEntry *, _DWORD))v12->SetFgColor)(a1: this->m_pInput, a2: *v9);
  this->SetPaintBackgroundEnabled(this, a2: true);
  this->m_pPrompt->SetPaintBackgroundEnabled(this: this->m_pPrompt, a2: true);
  this->m_pPrompt->SetContentAlignment(this: this->m_pPrompt, a2: a_west);
  this->m_pPrompt->SetTextInset(this: this->m_pPrompt, a2: 2, a3: 0);
  this->m_pInput->SetMouseInputEnabled(this: this->m_pInput, a2: true);
  v10 = this->__vftable;
  pScheme = 0;
  ((void (__thiscall *)(CBaseHudChatInputLine *, _DWORD))v10->SetBgColor)(a1: this, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100F4880
// Name: public: CHudChatFilterButton::CHudChatFilterButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CHudChatFilterButton *__thiscall CHudChatFilterButton::CHudChatFilterButton(
        CHudChatFilterButton *this,
        vgui::Panel *pParent,
        const char *pName,
        const char *pText)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi

  vgui::Button::Button(
    this,
    parent: pParent,
    panelName: pName,
    text: pText,
    pActionSignalTarget: nullptr,
    pCmd: nullptr);
  this->__vftable = (CHudChatFilterButton_vtbl *)&CHudChatFilterButton::`vftable';
  if ( `CHudChatFilterButton::ChainToMap'::`2'::chained == 0 )
  {
    `CHudChatFilterButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CHudChatFilterButton");
    v5->pfnClassName = CHudChatFilterButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Button");
  }
  if ( `CHudChatFilterButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CHudChatFilterButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CHudChatFilterButton");
    v6->pfnClassName = CHudChatFilterButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Button");
  }
  if ( `CHudChatFilterButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CHudChatFilterButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CHudChatFilterButton");
    v7->pfnClassName = CHudChatFilterButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Button");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100F4960
// Name: public: virtual void vgui::Button::OnHotkey(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Button::OnHotkey(vgui::Button *this)
{
  this->DoClick(this);
}

//------------------------------------------------------------------------------
// Address: 0x100F4970
// Name: public: virtual struct vgui::PanelMessageMap __near * CHudChatFilterButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CHudChatFilterButton::GetMessageMap(CHudChatFilterButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CHudChatFilterButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CHudChatFilterButton::GetMessageMap'::`2'::s_pMap;
  `CHudChatFilterButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CHudChatFilterButton");
  `CHudChatFilterButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100F49A0
// Name: public: virtual struct PanelAnimationMap __near * CHudChatFilterButton::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CHudChatFilterButton::GetAnimMap(CHudChatFilterButton *this)
{
  return FindOrAddPanelAnimationMap(className: "CHudChatFilterButton");
}

//------------------------------------------------------------------------------
// Address: 0x100F49B0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CHudChatFilterButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CHudChatFilterButton::GetKBMap(CHudChatFilterButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CHudChatFilterButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CHudChatFilterButton::GetKBMap'::`2'::s_pMap;
  `CHudChatFilterButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CHudChatFilterButton");
  `CHudChatFilterButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100F49E0
// Name: public: CHudChatFilterCheckButton::CHudChatFilterCheckButton(class vgui::Panel __near *,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CHudChatFilterCheckButton *__thiscall CHudChatFilterCheckButton::CHudChatFilterCheckButton(
        CHudChatFilterCheckButton *this,
        vgui::Panel *pParent,
        const char *pName,
        const char *pText,
        int iFlag)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi

  vgui::CheckButton::CheckButton(this, parent: pParent, panelName: pName, text: pText);
  this->__vftable = (CHudChatFilterCheckButton_vtbl *)&CHudChatFilterCheckButton::`vftable';
  if ( `CHudChatFilterCheckButton::ChainToMap'::`2'::chained == 0 )
  {
    `CHudChatFilterCheckButton::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "CHudChatFilterCheckButton");
    v6->pfnClassName = CHudChatFilterCheckButton::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::CheckButton");
  }
  if ( `CHudChatFilterCheckButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CHudChatFilterCheckButton::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "CHudChatFilterCheckButton");
    v7->pfnClassName = CHudChatFilterCheckButton::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "vgui::CheckButton");
  }
  if ( `CHudChatFilterCheckButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CHudChatFilterCheckButton::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "CHudChatFilterCheckButton");
    v8->pfnClassName = CHudChatFilterCheckButton::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::CheckButton");
  }
  this->m_iFlag = iFlag;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100F4AD0
// Name: public: virtual struct vgui::PanelMessageMap __near * CHudChatFilterCheckButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CHudChatFilterCheckButton::GetMessageMap(CHudChatFilterCheckButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CHudChatFilterCheckButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CHudChatFilterCheckButton::GetMessageMap'::`2'::s_pMap;
  `CHudChatFilterCheckButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CHudChatFilterCheckButton");
  `CHudChatFilterCheckButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100F4B00
// Name: public: virtual struct PanelAnimationMap __near * CHudChatFilterCheckButton::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CHudChatFilterCheckButton::GetAnimMap(CHudChatFilterCheckButton *this)
{
  return FindOrAddPanelAnimationMap(className: "CHudChatFilterCheckButton");
}

//------------------------------------------------------------------------------
// Address: 0x100F4B10
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CHudChatFilterCheckButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CHudChatFilterCheckButton::GetKBMap(CHudChatFilterCheckButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CHudChatFilterCheckButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CHudChatFilterCheckButton::GetKBMap'::`2'::s_pMap;
  `CHudChatFilterCheckButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CHudChatFilterCheckButton");
  `CHudChatFilterCheckButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100F4B70
// Name: public: virtual void CHudChatFilterPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudChatFilterPanel::ApplySchemeSettings(CHudChatFilterPanel *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v3; // edi
  vgui::IScheme *v4; // ebx
  Color *v5; // eax
  void (__thiscall *SetBgColor)(vgui::Panel *, Color); // edx
  CHudChatFilterPanel_vtbl *v7; // ebx
  Color *(__thiscall *GetFgColor)(vgui::Panel *, Color *); // edx
  _DWORD *v9; // eax
  _DWORD *v10; // eax
  _BYTE v11[4]; // [esp+Ch] [ebp-Ch] BYREF
  Color v12; // [esp+10h] [ebp-8h] BYREF
  Color cColor; // [esp+14h] [ebp-4h] BYREF

  this->LoadControlSettings(this, a2: "resource/UI/ChatFilters.res", a3: nullptr, a4: nullptr, a5: nullptr);
  v3 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = (vgui::IScheme *)v3->__vftable;
  v5 = this->GetBgColor(this, result: &pScheme);
  ((void (__thiscall *)(vgui::IScheme *, Color *, const char *, _DWORD))v4[5].__vftable)(
    a1: v3,
    a2: &cColor,
    a3: "DullWhite",
    a4: *v5);
  SetBgColor = this->SetBgColor;
  LOWORD(pScheme) = *(_WORD *)cColor._color;
  BYTE2(pScheme) = cColor._color[2];
  HIBYTE(pScheme) = 127;
  ((void (__thiscall *)(CHudChatFilterPanel *, vgui::IScheme *))SetBgColor)(a1: this, a2: pScheme);
  v7 = this->__vftable;
  GetFgColor = this->GetFgColor;
  pScheme = (vgui::IScheme *)v3->__vftable;
  v9 = (_DWORD *)GetFgColor(this, result: &v12);
  v10 = (_DWORD *)((int (__thiscall *)(vgui::IScheme *, _BYTE *, const char *, _DWORD))pScheme[5].__vftable)(
                    a1: v3,
                    a2: v11,
                    a3: "Blank",
                    a4: *v9);
  ((void (__thiscall *)(CHudChatFilterPanel *, _DWORD))v7->SetFgColor)(a1: this, a2: *v10);
}

//------------------------------------------------------------------------------
// Address: 0x100F4C30
// Name: public: virtual void CHudChatFilterPanel::OnFilterButtonChecked(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudChatFilterPanel::OnFilterButtonChecked(CHudChatFilterPanel *this, vgui::Panel *panel)
{
  _DWORD *v3; // edi
  vgui::Panel *v4; // eax
  CBaseHudChat *ChatParent; // eax
  int v6; // edi
  int v7; // eax
  CBaseHudChat *v8; // eax
  int v9; // edi
  CBaseHudChat *v10; // eax
  int v11; // [esp-4h] [ebp-Ch]

  v3 = __RTDynamicCast(
         inptr: panel,
         VfDelta: 0,
         SrcType: &vgui::Panel `RTTI Type Descriptor',
         TargetType: &CHudChatFilterCheckButton `RTTI Type Descriptor',
         isReference: 0);
  if ( v3 != nullptr )
  {
    v4 = this->GetParent(this);
    if ( __RTDynamicCast(
           inptr: v4,
           VfDelta: 0,
           SrcType: &vgui::Panel `RTTI Type Descriptor',
           TargetType: &CBaseHudChat `RTTI Type Descriptor',
           isReference: 0) != nullptr
      && this->IsVisible(this) )
    {
      if ( (*(unsigned __int8 (__thiscall **)(_DWORD *))(*v3 + 1024))(a1: v3) != 0 )
      {
        ChatParent = CHudChatFilterPanel::GetChatParent(this);
        v6 = v3[135];
        v7 = v6 | ChatParent->GetFilterFlags(this: ChatParent);
      }
      else
      {
        v8 = CHudChatFilterPanel::GetChatParent(this);
        v9 = v3[135];
        v7 = ~v9 & v8->GetFilterFlags(this: v8);
      }
      v11 = v7;
      v10 = CHudChatFilterPanel::GetChatParent(this);
      CBaseHudChat::SetFilterFlag(this: v10, iFilter: v11);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F4CF0
// Name: public: virtual void CHudChatFilterPanel::SetVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudChatFilterPanel::SetVisible(CHudChatFilterPanel *this, int state)
{
  int i; // esi
  vgui::Panel *Child; // eax
  _DWORD *v5; // ecx
  int m_nValue; // eax
  void (__stdcall *v7)(int); // edx

  if ( (_BYTE)state == 1 )
  {
    for ( i = 0; i < vgui::Panel::GetChildCount(this); ++i )
    {
      Child = vgui::Panel::GetChild(this, index: i);
      v5 = __RTDynamicCast(
             inptr: Child,
             VfDelta: 0,
             SrcType: &vgui::Panel `RTTI Type Descriptor',
             TargetType: &CHudChatFilterCheckButton `RTTI Type Descriptor',
             isReference: 0);
      if ( v5 != nullptr )
      {
        if ( cl_chatfilters.m_pParent != nullptr )
          m_nValue = cl_chatfilters.m_pParent->m_Value.m_nValue;
        else
          m_nValue = 0;
        v7 = *(void (__stdcall **)(int))(*v5 + 1020);
        if ( (m_nValue & v5[135]) != 0 )
          v7(a1: 1);
        else
          v7(a1: 0);
      }
    }
  }
  vgui::Panel::SetVisible(this, state);
}

//------------------------------------------------------------------------------
// Address: 0x100F4D80
// Name: public: CHudChatHistory::CHudChatHistory(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CHudChatHistory *__thiscall CHudChatHistory::CHudChatHistory(
        CHudChatHistory *this,
        vgui::Panel *pParent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // esi
  PanelAnimationMap *v5; // esi
  vgui::PanelKeyBindingMap *v6; // esi

  vgui::RichText::RichText(this, parent: pParent, panelName: "HudChatHistory");
  this->__vftable = (CHudChatHistory_vtbl *)&CHudChatHistory::`vftable';
  if ( `CHudChatHistory::ChainToMap'::`2'::chained == 0 )
  {
    `CHudChatHistory::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CHudChatHistory");
    v4->pfnClassName = CHudChatHistory::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::RichText");
  }
  if ( `CHudChatHistory::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CHudChatHistory::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CHudChatHistory");
    v5->pfnClassName = CHudChatHistory::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::RichText");
  }
  if ( `CHudChatHistory::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CHudChatHistory::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CHudChatHistory");
    v6->pfnClassName = CHudChatHistory::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::RichText");
  }
  vgui::Panel::SetScheme(this, tag: "ChatScheme");
  vgui::RichText::InsertFade(this, flSustain: -1.0, flLength: -1.0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100F4E70
// Name: public: virtual struct vgui::PanelMessageMap __near * CHudChatHistory::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CHudChatHistory::GetMessageMap(CHudChatHistory *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CHudChatHistory::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CHudChatHistory::GetMessageMap'::`2'::s_pMap;
  `CHudChatHistory::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CHudChatHistory");
  `CHudChatHistory::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100F4EA0
// Name: public: virtual struct PanelAnimationMap __near * CHudChatHistory::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CHudChatHistory::GetAnimMap(CHudChatHistory *this)
{
  return FindOrAddPanelAnimationMap(className: "CHudChatHistory");
}

//------------------------------------------------------------------------------
// Address: 0x100F4EB0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CHudChatHistory::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CHudChatHistory::GetKBMap(CHudChatHistory *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CHudChatHistory::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CHudChatHistory::GetKBMap'::`2'::s_pMap;
  `CHudChatHistory::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CHudChatHistory");
  `CHudChatHistory::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100F4F30
// Name: public: virtual void CBaseHudChat::CreateChatInputLine(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseHudChat::CreateChatInputLine(CBaseHudChat *this)
{
  CBaseHudChatInputLine *v2; // eax
  CBaseHudChatInputLine *v3; // eax
  CHudChatHistory *m_pChatHistory; // ecx

  v2 = (CBaseHudChatInputLine *)MemAlloc_Alloc(nSize: 0x154u);
  if ( v2 != nullptr )
    v3 = CBaseHudChatInputLine::CBaseHudChatInputLine(this: v2, parent: this, panelName: "ChatInputLine");
  else
    v3 = nullptr;
  this->m_pChatInput = v3;
  v3->SetVisible(this: v3, a2: false);
  m_pChatHistory = this->m_pChatHistory;
  if ( m_pChatHistory != nullptr )
  {
    vgui::RichText::SetMaximumCharCount(this: m_pChatHistory, maxChars: 12700);
    this->m_pChatHistory->SetVisible(this: this->m_pChatHistory, a2: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F4FA0
// Name: public: virtual void CBaseHudChat::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseHudChat::ApplySchemeSettings(CBaseHudChat *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v3; // edi
  vgui::IScheme_vtbl *v4; // ebx
  _DWORD *v5; // eax
  void (__thiscall *StartMessageMode)(CBaseHudChat *, int); // edx
  Color cColor; // [esp+Ch] [ebp-4h] BYREF

  ((void (__thiscall *)(CBaseHudChat *, const char *, _DWORD, _DWORD, _DWORD))this->CHudElement::CGameEventListener::IGameEventListener2::__vftable[5].GetDefaultTextColor)(
    a1: this,
    a2: "resource/UI/BaseChat.res",
    a3: 0,
    a4: 0,
    a5: 0);
  v3 = pScheme;
  vgui::Panel::ApplySchemeSettings((vgui::Panel *)this, (int)pScheme);
  ((void (__thiscall *)(CBaseHudChat *, int))this->CHudElement::CGameEventListener::IGameEventListener2::__vftable[2].GetEventDebugID)(
    a1: this,
    a2: 2);
  this->CHudElement::CGameEventListener::IGameEventListener2::__vftable[1].GetFilterForString(this, a2: (const char *)1);
  this->CHudElement::CGameEventListener::IGameEventListener2::__vftable[1].GetDisplayedSubtitlePlayerName(this, a2: 1);
  this->CHudElement::CGameEventListener::IGameEventListener2::__vftable[3].MsgFunc_VoiceSubtitle(this, a2: nullptr);
  this->CHudElement::CGameEventListener::IGameEventListener2::__vftable[3].MsgFunc_SayText2(this, a2: nullptr);
  v4 = v3->__vftable;
  v5 = (_DWORD *)((int (__thiscall *)(CBaseHudChat *, vgui::IScheme **))this->CHudElement::CGameEventListener::IGameEventListener2::__vftable[1].GetChatInputOffset)(
                   a1: this,
                   a2: &pScheme);
  ((void (__thiscall *)(vgui::IScheme *, Color *, const char *, _DWORD))v4->GetColor)(
    a1: v3,
    a2: &cColor,
    a3: "DullWhite",
    a4: *v5);
  StartMessageMode = this->CHudElement::CGameEventListener::IGameEventListener2::__vftable[1].StartMessageMode;
  LOWORD(pScheme) = *(_WORD *)cColor._color;
  BYTE2(pScheme) = cColor._color[2];
  HIBYTE(pScheme) = 127;
  StartMessageMode(this, a2: (int)pScheme);
  vgui::RichText::SetVerticalScrollbar(this: (vgui::RichText *)this->m_NavGroup._defaultButton.m_iPanelID, state: false);
}

//------------------------------------------------------------------------------
// Address: 0x100F5070
// Name: public: virtual void CBaseHudChat::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseHudChat::Reset(CBaseHudChat *this)
{
  CHudChatHistory *m_pChatHistory; // ecx

  this->StopMessageMode(this, a2: true);
  m_pChatHistory = this->m_pChatHistory;
  this->m_flHistoryFadeTime = 0.0;
  if ( m_pChatHistory != nullptr )
    vgui::RichText::ResetAllFades(this: m_pChatHistory, bHold: false, bOnlyExpired: false, flNewSustain: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x100F50B0
// Name: public: virtual void CBaseHudChat::MsgFunc_SayText(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseHudChat::MsgFunc_SayText(CBaseHudChat *this, bf_read *msg)
{
  int m_nBitsAvail; // ecx
  unsigned int v4; // edx
  int v5; // edi
  unsigned int v6; // edx
  const unsigned int *v7; // eax
  const unsigned int *v8; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int m_nInBufWord; // edi
  int v11; // eax
  const unsigned int *m_pDataIn; // ecx
  unsigned int v13; // edx
  unsigned int v14; // ebx
  int v15; // ecx
  unsigned int v16; // eax
  int v17; // edx
  int v18; // ecx
  int v19; // edi
  const unsigned int *v20; // eax
  const unsigned int *v21; // ecx
  const unsigned int *v22; // edx
  unsigned int v23; // edi
  int v24; // eax
  const unsigned int *v25; // ecx
  unsigned int v26; // edx
  unsigned int v27; // ebx
  CBaseHudChat *v28; // edi
  CBaseHudChat_vtbl *v29; // esi
  char *v30; // eax
  char szString[256]; // [esp+1Ch] [ebp-124h] BYREF
  CLocalPlayerFilter filter; // [esp+11Ch] [ebp-24h] BYREF
  CBaseHudChat *v33; // [esp+13Ch] [ebp-4h]
  bf_read *msga; // [esp+148h] [ebp+8h]

  v33 = this;
  m_nBitsAvail = msg->m_nBitsAvail;
  if ( m_nBitsAvail < 8 )
  {
    m_pBufferEnd = msg->m_pBufferEnd;
    m_nInBufWord = msg->m_nInBufWord;
    v11 = 8 - m_nBitsAvail;
    m_pDataIn = msg->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
LABEL_15:
        if ( msg->m_bOverflow )
        {
          msga = nullptr;
          goto LABEL_20;
        }
        v13 = msg->m_nInBufWord;
        v14 = (v13 & CBitBuffer::s_nMaskTable[v11]) << msg->m_nBitsAvail;
        msg->m_nBitsAvail = 32 - v11;
        v5 = v14 | m_nInBufWord;
        v6 = v13 >> v11;
        goto LABEL_18;
      }
      msg->m_nInBufWord = *m_pDataIn;
    }
    msg->m_pDataIn = m_pDataIn + 1;
    goto LABEL_15;
  }
  v4 = msg->m_nInBufWord;
  v5 = (unsigned __int8)v4;
  msg->m_nBitsAvail = m_nBitsAvail - 8;
  if ( m_nBitsAvail == 8 )
  {
    v7 = msg->m_pDataIn;
    v8 = msg->m_pBufferEnd;
    msg->m_nBitsAvail = 32;
    if ( v7 == v8 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_pDataIn = v7 + 1;
    }
    else if ( v7 <= v8 )
    {
      msg->m_nInBufWord = *v7;
      msg->m_pDataIn = v7 + 1;
    }
    else
    {
      msg->m_bOverflow = true;
      msg->m_nInBufWord = 0;
    }
    goto LABEL_19;
  }
  v6 = v4 >> 8;
LABEL_18:
  msg->m_nInBufWord = v6;
LABEL_19:
  msga = (bf_read *)v5;
LABEL_20:
  CBitRead::ReadString(this: msg, pStr: szString, maxLen: 256, bLine: false, pOutNumChars: nullptr);
  v15 = msg->m_nBitsAvail;
  if ( v15 >= 8 )
  {
    v16 = msg->m_nInBufWord;
    v17 = (unsigned __int8)v16;
    v18 = v15 - 8;
    msg->m_nBitsAvail = v18;
    if ( v18 != 0 )
    {
      msg->m_nInBufWord = v16 >> 8;
      v19 = (unsigned __int8)v16;
    }
    else
    {
      v20 = msg->m_pDataIn;
      v21 = msg->m_pBufferEnd;
      msg->m_nBitsAvail = 32;
      if ( v20 == v21 )
      {
        msg->m_nInBufWord = 0;
        msg->m_nBitsAvail = 1;
        msg->m_pDataIn = v20 + 1;
        v19 = v17;
      }
      else
      {
        if ( v20 <= v21 )
        {
          msg->m_nInBufWord = *v20;
          msg->m_pDataIn = v20 + 1;
        }
        else
        {
          msg->m_nInBufWord = 0;
          msg->m_bOverflow = true;
        }
        v19 = v17;
      }
    }
    goto LABEL_37;
  }
  v22 = msg->m_pBufferEnd;
  v23 = msg->m_nInBufWord;
  v24 = 8 - v15;
  v25 = msg->m_pDataIn;
  if ( v25 == v22 )
  {
    msg->m_nBitsAvail = 1;
    msg->m_nInBufWord = 0;
    msg->m_bOverflow = true;
LABEL_34:
    msg->m_pDataIn = v25 + 1;
    goto LABEL_35;
  }
  if ( v25 <= v22 )
  {
    msg->m_nInBufWord = *v25;
    goto LABEL_34;
  }
  msg->m_bOverflow = true;
  msg->m_nInBufWord = 0;
LABEL_35:
  if ( msg->m_bOverflow )
  {
LABEL_39:
    v28 = v33;
    v29 = v33->CHudElement::CGameEventListener::IGameEventListener2::__vftable;
    v30 = hudtextmessage->LookupString(this: hudtextmessage, a2: szString, a3: 0);
    v29->Printf(this: v28, a2: 0, a3: "%s", v30);
    goto LABEL_40;
  }
  v26 = msg->m_nInBufWord;
  v27 = (v26 & CBitBuffer::s_nMaskTable[v24]) << msg->m_nBitsAvail;
  msg->m_nBitsAvail = 32 - v24;
  v19 = v27 | v23;
  msg->m_nInBufWord = v26 >> v24;
LABEL_37:
  if ( v19 == 0 )
    goto LABEL_39;
  v33->ChatPrintf(this: v33, a2: (int)msga, a3: 0, a4: "%s", szString);
LABEL_40:
  CLocalPlayerFilter::CLocalPlayerFilter(this: &filter);
  C_BaseEntity::EmitSound(
    &filter,
    iEntIndex: -1,
    soundname: "HudChat.Message",
    pOrigin: nullptr,
    soundtime: 0.0,
    duration: nullptr);
  C_RecipientFilter::~C_RecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x100F5320
// Name: public: virtual void CBaseHudChat::MsgFunc_SayText2(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseHudChat::MsgFunc_SayText2(CBaseHudChat *this, bf_read *msg)
{
  int m_nBitsAvail; // ecx
  unsigned int v4; // edx
  int v5; // edi
  unsigned int v6; // edx
  const unsigned int *v7; // eax
  const unsigned int *v8; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int m_nInBufWord; // edi
  int v11; // eax
  const unsigned int *m_pDataIn; // ecx
  unsigned int v13; // edx
  unsigned int v14; // ebx
  int v15; // ecx
  unsigned int v16; // edx
  int v17; // eax
  int v18; // ecx
  unsigned int v19; // edx
  const unsigned int *v20; // ecx
  const unsigned int *v21; // edx
  const unsigned int *v22; // edx
  unsigned int v23; // edi
  int v24; // eax
  const unsigned int *v25; // ecx
  unsigned int v26; // edx
  unsigned int v27; // ebx
  bool v28; // bl
  wchar_t *i; // eax
  int v30; // ebx
  C_PlayerResource *v31; // edi
  IGameResources_vtbl *v32; // esi
  int LocalPlayerIndex; // eax
  int v34; // esi
  CBaseHudChat *v35; // edi
  CBaseHudChat_vtbl *v36; // esi
  int v37; // eax
  wchar_t szBuf[6][256]; // [esp+28h] [ebp-F24h] BYREF
  char ansiString[512]; // [esp+C28h] [ebp-324h] BYREF
  char untranslated_msg_text[256]; // [esp+E28h] [ebp-124h] BYREF
  CLocalPlayerFilter filter; // [esp+F28h] [ebp-24h] BYREF
  CBaseHudChat *v42; // [esp+F48h] [ebp-4h]
  bf_read *msga; // [esp+F54h] [ebp+8h]

  v42 = this;
  if ( g_PR == nullptr )
    return;
  m_nBitsAvail = msg->m_nBitsAvail;
  if ( m_nBitsAvail < 8 )
  {
    m_pBufferEnd = msg->m_pBufferEnd;
    m_nInBufWord = msg->m_nInBufWord;
    v11 = 8 - m_nBitsAvail;
    m_pDataIn = msg->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
LABEL_16:
        if ( msg->m_bOverflow )
        {
          msga = nullptr;
          goto LABEL_21;
        }
        v13 = msg->m_nInBufWord;
        v14 = (v13 & CBitBuffer::s_nMaskTable[v11]) << msg->m_nBitsAvail;
        msg->m_nBitsAvail = 32 - v11;
        v5 = v14 | m_nInBufWord;
        v6 = v13 >> v11;
        goto LABEL_19;
      }
      msg->m_nInBufWord = *m_pDataIn;
    }
    msg->m_pDataIn = m_pDataIn + 1;
    goto LABEL_16;
  }
  v4 = msg->m_nInBufWord;
  v5 = (unsigned __int8)v4;
  msg->m_nBitsAvail = m_nBitsAvail - 8;
  if ( m_nBitsAvail == 8 )
  {
    v7 = msg->m_pDataIn;
    v8 = msg->m_pBufferEnd;
    msg->m_nBitsAvail = 32;
    if ( v7 == v8 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_pDataIn = v7 + 1;
    }
    else if ( v7 <= v8 )
    {
      msg->m_nInBufWord = *v7;
      msg->m_pDataIn = v7 + 1;
    }
    else
    {
      msg->m_bOverflow = true;
      msg->m_nInBufWord = 0;
    }
    goto LABEL_20;
  }
  v6 = v4 >> 8;
LABEL_19:
  msg->m_nInBufWord = v6;
LABEL_20:
  msga = (bf_read *)v5;
LABEL_21:
  v15 = msg->m_nBitsAvail;
  if ( v15 < 8 )
  {
    v22 = msg->m_pBufferEnd;
    v23 = msg->m_nInBufWord;
    v24 = 8 - v15;
    v25 = msg->m_pDataIn;
    if ( v25 == v22 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( v25 > v22 )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
LABEL_35:
        if ( !msg->m_bOverflow )
        {
          v26 = msg->m_nInBufWord;
          v27 = (v26 & CBitBuffer::s_nMaskTable[v24]) << msg->m_nBitsAvail;
          msg->m_nBitsAvail = 32 - v24;
          v19 = v26 >> v24;
          v17 = v27 | v23;
          goto LABEL_38;
        }
        v17 = 0;
        goto LABEL_39;
      }
      msg->m_nInBufWord = *v25;
    }
    msg->m_pDataIn = v25 + 1;
    goto LABEL_35;
  }
  v16 = msg->m_nInBufWord;
  v17 = (unsigned __int8)v16;
  v18 = v15 - 8;
  msg->m_nBitsAvail = v18;
  if ( v18 != 0 )
  {
    v19 = v16 >> 8;
LABEL_38:
    msg->m_nInBufWord = v19;
    goto LABEL_39;
  }
  v20 = msg->m_pDataIn;
  v21 = msg->m_pBufferEnd;
  msg->m_nBitsAvail = 32;
  if ( v20 == v21 )
  {
    msg->m_nBitsAvail = 1;
    msg->m_nInBufWord = 0;
    msg->m_pDataIn = v20 + 1;
  }
  else
  {
    if ( v20 <= v21 )
    {
      v19 = *v20;
      msg->m_pDataIn = v20 + 1;
      goto LABEL_38;
    }
    msg->m_bOverflow = true;
    msg->m_nInBufWord = 0;
  }
LABEL_39:
  v28 = v17 != 0;
  ReadLocalizedString(
    a1: (int)msg,
    msg,
    pOut: szBuf[0],
    outSize: 0x200u,
    bStripNewline: false,
    originalString: untranslated_msg_text,
    originalSize: 256);
  ReadChatTextString(msg, pOut: szBuf[1], outSize: 512);
  ReadChatTextString(msg, pOut: szBuf[2], outSize: 512);
  ReadLocalizedString(
    a1: (int)msg,
    msg,
    pOut: szBuf[3],
    outSize: 0x200u,
    bStripNewline: true,
    originalString: nullptr,
    originalSize: 0);
  ReadLocalizedString(
    a1: (int)msg,
    msg,
    pOut: szBuf[4],
    outSize: 0x200u,
    bStripNewline: true,
    originalString: nullptr,
    originalSize: 0);
  ((void (__stdcall *)(vgui::ILocalize *, wchar_t *))g_pVGuiLocalize->ConstructString_3)(
    a1: g_pVGuiLocalize,
    a2: szBuf[5]);
  for ( i = szBuf[5]; *i != 0; ++i )
  {
    if ( *i == 13 )
      *i = 10;
  }
  ((void (__thiscall *)(vgui::ILocalize *, wchar_t *))g_pVGuiLocalize->ConvertUnicodeToANSI)(
    a1: g_pVGuiLocalize,
    a2: szBuf[5]);
  if ( v28 )
  {
    v30 = 0;
    if ( (int)msga > 0 )
    {
      v31 = g_PR;
      v32 = g_PR->IGameResources::__vftable;
      LocalPlayerIndex = GetLocalPlayerIndex();
      v34 = v32->GetTeam(this: &g_PR->IGameResources, a2: LocalPlayerIndex);
      if ( v31->GetTeam(this: &v31->IGameResources, a2: (int)msga) != v34 )
        v30 = 4;
    }
    v42->ChatPrintf(this: v42, a2: (int)msga, a3: v30, a4: "%s", ansiString);
    CLocalPlayerFilter::CLocalPlayerFilter(this: &filter);
    C_BaseEntity::EmitSound(
      &filter,
      iEntIndex: -1,
      soundname: "HudChat.Message",
      pOrigin: nullptr,
      soundtime: 0.0,
      duration: nullptr);
    C_RecipientFilter::~C_RecipientFilter(this: &filter);
  }
  else
  {
    v35 = v42;
    v36 = v42->CHudElement::CGameEventListener::IGameEventListener2::__vftable;
    v37 = v42->GetFilterForString(this: v42, a2: untranslated_msg_text);
    ((void (__cdecl *)(CBaseHudChat *, bf_read *, int))v36->ChatPrintf)(a1: v35, a2: msga, a3: v37);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F56D0
// Name: public: virtual void CBaseHudChat::MsgFunc_TextMsg(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __thiscall CBaseHudChat::MsgFunc_TextMsg(CBaseHudChat *this, bf_read *msg)
{
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // edx
  int v5; // edi
  unsigned int v6; // edx
  const unsigned int *m_pDataIn; // eax
  const unsigned int *m_pBufferEnd; // ecx
  const unsigned int *v9; // edx
  unsigned int v10; // edi
  int v11; // eax
  const unsigned int *v12; // ecx
  unsigned int v13; // edx
  unsigned int v14; // ebx
  unsigned __int16 *v15; // ebx
  const char *v16; // edi
  const wchar_t *v17; // eax
  signed int v18; // eax
  char v19; // cl
  CCenterPrint *CenterPrint; // eax
  _WORD *m; // edx
  unsigned int v22; // kr04_4
  char v23; // al
  char *i; // eax
  unsigned int v25; // kr08_4
  char v26; // al
  char *k; // eax
  unsigned int v28; // kr0C_4
  char v29; // al
  char *j; // eax
  unsigned __int16 dest[255]; // [esp+Ch] [ebp-140Ch] BYREF
  char v32; // [esp+20Ah] [ebp-120Eh] BYREF
  _BYTE v33[512]; // [esp+20Ch] [ebp-120Ch] BYREF
  _BYTE v34[512]; // [esp+40Ch] [ebp-100Ch] BYREF
  _BYTE v35[512]; // [esp+60Ch] [ebp-E0Ch] BYREF
  char v36[512]; // [esp+80Ch] [ebp-C0Ch] BYREF
  char pStr[2048]; // [esp+A0Ch] [ebp-A0Ch] BYREF
  _WORD v38[256]; // [esp+120Ch] [ebp-20Ch] BYREF
  CBaseHudChat *v39; // [esp+140Ch] [ebp-Ch]
  int v40; // [esp+1410h] [ebp-8h] BYREF
  char *v41; // [esp+1414h] [ebp-4h]
  CBitRead *v42; // [esp+1420h] [ebp+8h]

  v39 = this;
  m_nBitsAvail = msg->m_nBitsAvail;
  if ( m_nBitsAvail >= 8 )
  {
    m_nInBufWord = msg->m_nInBufWord;
    v5 = (unsigned __int8)m_nInBufWord;
    msg->m_nBitsAvail = m_nBitsAvail - 8;
    if ( m_nBitsAvail == 8 )
    {
      m_pDataIn = msg->m_pDataIn;
      m_pBufferEnd = msg->m_pBufferEnd;
      msg->m_nBitsAvail = 32;
      if ( m_pDataIn == m_pBufferEnd )
      {
        msg->m_nBitsAvail = 1;
        msg->m_nInBufWord = 0;
        msg->m_pDataIn = m_pDataIn + 1;
      }
      else if ( m_pDataIn <= m_pBufferEnd )
      {
        msg->m_nInBufWord = *m_pDataIn;
        msg->m_pDataIn = m_pDataIn + 1;
      }
      else
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
      }
      goto LABEL_19;
    }
    v6 = m_nInBufWord >> 8;
    goto LABEL_18;
  }
  v9 = msg->m_pBufferEnd;
  v10 = msg->m_nInBufWord;
  v11 = 8 - m_nBitsAvail;
  v12 = msg->m_pDataIn;
  if ( v12 == v9 )
  {
    msg->m_nBitsAvail = 1;
    msg->m_nInBufWord = 0;
    msg->m_bOverflow = true;
  }
  else
  {
    if ( v12 > v9 )
    {
      msg->m_bOverflow = true;
      msg->m_nInBufWord = 0;
      goto LABEL_15;
    }
    msg->m_nInBufWord = *v12;
  }
  msg->m_pDataIn = v12 + 1;
LABEL_15:
  if ( !msg->m_bOverflow )
  {
    v13 = msg->m_nInBufWord;
    v14 = (v13 & CBitBuffer::s_nMaskTable[v11]) << msg->m_nBitsAvail;
    msg->m_nBitsAvail = 32 - v11;
    v5 = v14 | v10;
    v6 = v13 >> v11;
LABEL_18:
    msg->m_nInBufWord = v6;
    goto LABEL_19;
  }
  v5 = 0;
LABEL_19:
  v40 = v5;
  v42 = nullptr;
  v15 = dest;
  v41 = &v32;
  do
  {
    CBitRead::ReadString(this: msg, pStr, maxLen: 2048, bLine: false, pOutNumChars: nullptr);
    v16 = hudtextmessage->LookupString(this: hudtextmessage, a2: pStr, a3: &v40);
    v17 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: v16);
    if ( v17 != nullptr )
    {
      wcsncpy(dest: v15, source: v17, count: 0x100u);
      *(_WORD *)v41 = 0;
    }
    else
    {
      if ( v42 != nullptr )
      {
        v18 = strlen(v16) - 1;
        if ( v18 >= 0 )
        {
          v19 = v16[v18];
          if ( v19 == 10 || v19 == 13 )
            v16[v18] = 0;
        }
      }
      g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: v16, a3: v15, a4: 512);
    }
    v41 += 512;
    v15 += 256;
    v42 = (CBitRead *)((char *)v42 + 1);
  }
  while ( (int)v42 < 5 );
  if ( cl_showtextmsg.m_pParent != nullptr && cl_showtextmsg.m_pParent->m_Value.m_nValue != 0 )
  {
    switch ( v40 )
    {
      case 1:
        g_pVGuiLocalize->ConstructString_3(this: g_pVGuiLocalize, a2: v38, a3: 512, a4: dest, a5: 4, v33, v34, v35, v36);
        g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: v38, a3: pStr, a4: 2048);
        v22 = strlen(pStr);
        if ( v22 != 0 )
        {
          v23 = v36[v22 + 511];
          if ( v23 != 10 && v23 != 13 )
            V_strncat(pDest: pStr, pSrc: "\n", destBufferSize: 0x800u, max_chars_to_copy: 1);
        }
        for ( i = pStr; *i != 0; ++i )
        {
          if ( *i == 13 )
            *i = 10;
        }
        goto LABEL_63;
      case 2:
        g_pVGuiLocalize->ConstructString_3(this: g_pVGuiLocalize, a2: v38, a3: 512, a4: dest, a5: 4, v33, v34, v35, v36);
        g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: v38, a3: pStr, a4: 2048);
        v28 = strlen(pStr);
        if ( v28 != 0 )
        {
          v29 = v36[v28 + 511];
          if ( v29 != 10 && v29 != 13 )
            V_strncat(pDest: pStr, pSrc: "\n", destBufferSize: 0x800u, max_chars_to_copy: 1);
        }
        for ( j = pStr; *j != 0; ++j )
        {
          if ( *j == 13 )
            *j = 10;
        }
LABEL_63:
        _Msg(a1: "%s", pStr);
        break;
      case 3:
        g_pVGuiLocalize->ConstructString_3(this: g_pVGuiLocalize, a2: v38, a3: 512, a4: dest, a5: 4, v33, v34, v35, v36);
        g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: v38, a3: pStr, a4: 2048);
        v25 = strlen(pStr);
        if ( v25 != 0 )
        {
          v26 = v36[v25 + 511];
          if ( v26 != 10 && v26 != 13 )
            V_strncat(pDest: pStr, pSrc: "\n", destBufferSize: 0x800u, max_chars_to_copy: 1);
        }
        for ( k = pStr; *k != 0; ++k )
        {
          if ( *k == 13 )
            *k = 10;
        }
        v39->Printf(this: v39, a2: 0, a3: "%s", pStr);
        break;
      case 4:
        g_pVGuiLocalize->ConstructString_3(this: g_pVGuiLocalize, a2: v38, a3: 512, a4: dest, a5: 4, v33, v34, v35, v36);
        CenterPrint = GetCenterPrint();
        for ( m = v38; *m != 0; ++m )
        {
          if ( *m == 13 )
            *m = 10;
        }
        CenterPrint->Print(this: CenterPrint, a2: v38);
        break;
      default:
        return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F5BE0
// Name: public: virtual void CBaseHudChat::MsgFunc_VoiceSubtitle(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBaseHudChat::MsgFunc_VoiceSubtitle(
        CBaseHudChat *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        bf_read *msg)
{
  int m_nBitsAvail; // ecx
  unsigned int v6; // edx
  int v7; // esi
  int v8; // ecx
  const unsigned int *v9; // ecx
  const unsigned int *v10; // edx
  unsigned int v11; // edx
  const unsigned int *m_pBufferEnd; // esi
  unsigned int m_nInBufWord; // edi
  int v14; // edx
  const unsigned int *m_pDataIn; // ecx
  unsigned int v16; // esi
  unsigned int v17; // ebx
  int v18; // ecx
  unsigned int v19; // edx
  int v20; // esi
  int v21; // ecx
  const unsigned int *v22; // ecx
  const unsigned int *v23; // edx
  unsigned int v24; // edx
  const unsigned int *v25; // esi
  unsigned int v26; // edi
  int v27; // edx
  const unsigned int *v28; // ecx
  unsigned int v29; // esi
  unsigned int v30; // ebx
  int v31; // ecx
  unsigned int v32; // edx
  int v33; // edi
  int v34; // ecx
  const unsigned int *v35; // ecx
  const unsigned int *v36; // edx
  unsigned int v37; // edx
  const unsigned int *v38; // esi
  unsigned int v39; // edi
  int v40; // edx
  const unsigned int *v41; // ecx
  unsigned int v42; // esi
  unsigned int v43; // ebx
  const char *VoiceCommandSubtitle; // esi
  C_MultiplayRules *v45; // eax
  int *v46; // edi
  const wchar_t *v47; // eax
  unsigned int v48; // kr00_4
  char v49; // al
  const wchar_t *v50; // eax
  char *i; // eax
  int v52; // esi
  int v53; // edi
  int v54; // eax
  CBaseHudChat *v55; // edi
  int v56; // [esp-28h] [ebp-974h]
  char szString[2048]; // [esp+4h] [ebp-948h] BYREF
  wchar_t szBuf[128]; // [esp+804h] [ebp-148h] BYREF
  char szPrefix[64]; // [esp+904h] [ebp-48h] BYREF
  CBaseHudChat *v63; // [esp+944h] [ebp-8h]
  int v64; // [esp+948h] [ebp-4h]
  int msga; // [esp+954h] [ebp+8h]

  v63 = this;
  if ( g_PR == nullptr || cl_showtextmsg.m_pParent == nullptr || cl_showtextmsg.m_pParent->m_Value.m_nValue == 0 )
    return;
  m_nBitsAvail = msg->m_nBitsAvail;
  if ( m_nBitsAvail < 8 )
  {
    m_pBufferEnd = msg->m_pBufferEnd;
    m_nInBufWord = msg->m_nInBufWord;
    v14 = 8 - m_nBitsAvail;
    m_pDataIn = msg->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
        goto LABEL_19;
      }
      msg->m_nInBufWord = *m_pDataIn;
    }
    msg->m_pDataIn = m_pDataIn + 1;
LABEL_19:
    if ( msg->m_bOverflow )
    {
      v64 = 0;
    }
    else
    {
      v16 = msg->m_nInBufWord;
      v17 = (v16 & CBitBuffer::s_nMaskTable[v14]) << msg->m_nBitsAvail;
      msg->m_nBitsAvail = 32 - v14;
      v64 = v17 | m_nInBufWord;
      msg->m_nInBufWord = v16 >> v14;
    }
    goto LABEL_22;
  }
  v6 = msg->m_nInBufWord;
  v7 = (unsigned __int8)v6;
  v8 = m_nBitsAvail - 8;
  msg->m_nBitsAvail = v8;
  if ( v8 != 0 )
  {
    msg->m_nInBufWord = v6 >> 8;
    v64 = (unsigned __int8)v6;
  }
  else
  {
    v9 = msg->m_pDataIn;
    v10 = msg->m_pBufferEnd;
    msg->m_nBitsAvail = 32;
    if ( v9 == v10 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_pDataIn = v9 + 1;
      v64 = v7;
    }
    else
    {
      if ( v9 <= v10 )
      {
        v11 = *v9;
        msg->m_pDataIn = v9 + 1;
        msg->m_nInBufWord = v11;
      }
      else
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
      }
      v64 = v7;
    }
  }
LABEL_22:
  v18 = msg->m_nBitsAvail;
  if ( v18 < 8 )
  {
    v25 = msg->m_pBufferEnd;
    v26 = msg->m_nInBufWord;
    v27 = 8 - v18;
    v28 = msg->m_pDataIn;
    if ( v28 == v25 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( v28 > v25 )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
        goto LABEL_37;
      }
      msg->m_nInBufWord = *v28;
    }
    msg->m_pDataIn = v28 + 1;
LABEL_37:
    if ( msg->m_bOverflow )
    {
      msga = 0;
    }
    else
    {
      v29 = msg->m_nInBufWord;
      v30 = (v29 & CBitBuffer::s_nMaskTable[v27]) << msg->m_nBitsAvail;
      msg->m_nBitsAvail = 32 - v27;
      msga = v30 | v26;
      msg->m_nInBufWord = v29 >> v27;
    }
    goto LABEL_40;
  }
  v19 = msg->m_nInBufWord;
  v20 = (unsigned __int8)v19;
  v21 = v18 - 8;
  msg->m_nBitsAvail = v21;
  if ( v21 != 0 )
  {
    msg->m_nInBufWord = v19 >> 8;
    msga = (unsigned __int8)v19;
  }
  else
  {
    v22 = msg->m_pDataIn;
    v23 = msg->m_pBufferEnd;
    msg->m_nBitsAvail = 32;
    if ( v22 == v23 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_pDataIn = v22 + 1;
      msga = v20;
    }
    else
    {
      if ( v22 <= v23 )
      {
        v24 = *v22;
        msg->m_pDataIn = v22 + 1;
        msg->m_nInBufWord = v24;
      }
      else
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
      }
      msga = v20;
    }
  }
LABEL_40:
  v31 = msg->m_nBitsAvail;
  if ( v31 < 8 )
  {
    v38 = msg->m_pBufferEnd;
    v39 = msg->m_nInBufWord;
    v40 = 8 - v31;
    v41 = msg->m_pDataIn;
    if ( v41 == v38 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( v41 > v38 )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
        goto LABEL_54;
      }
      msg->m_nInBufWord = *v41;
    }
    msg->m_pDataIn = v41 + 1;
LABEL_54:
    if ( msg->m_bOverflow )
    {
      v33 = 0;
    }
    else
    {
      v42 = msg->m_nInBufWord;
      v43 = (v42 & CBitBuffer::s_nMaskTable[v40]) << msg->m_nBitsAvail;
      msg->m_nBitsAvail = 32 - v40;
      v33 = v43 | v39;
      msg->m_nInBufWord = v42 >> v40;
    }
    goto LABEL_57;
  }
  v32 = msg->m_nInBufWord;
  v33 = (unsigned __int8)v32;
  v34 = v31 - 8;
  msg->m_nBitsAvail = v34;
  if ( v34 != 0 )
  {
    msg->m_nInBufWord = v32 >> 8;
  }
  else
  {
    v35 = msg->m_pDataIn;
    v36 = msg->m_pBufferEnd;
    msg->m_nBitsAvail = 32;
    if ( v35 == v36 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_pDataIn = v35 + 1;
    }
    else if ( v35 <= v36 )
    {
      v37 = *v35;
      msg->m_pDataIn = v35 + 1;
      msg->m_nInBufWord = v37;
    }
    else
    {
      msg->m_bOverflow = true;
      msg->m_nInBufWord = 0;
    }
  }
LABEL_57:
  VoiceCommandSubtitle = prType;
  v45 = (C_MultiplayRules *)__RTDynamicCast(
                              inptr: g_pGameRules,
                              VfDelta: 0,
                              SrcType: &C_GameRules `RTTI Type Descriptor',
                              TargetType: &C_MultiplayRules `RTTI Type Descriptor',
                              isReference: 0);
  if ( v45 != nullptr )
    VoiceCommandSubtitle = C_MultiplayRules::GetVoiceCommandSubtitle(this: v45, iMenu: msga, iItem: v33);
  v46 = (int *)v63;
  v63->m_bEnteringVoice = true;
  v47 = (const wchar_t *)((int (__thiscall *)(vgui::ILocalize *, const char *, int, int))g_pVGuiLocalize->Find)(
                           a1: g_pVGuiLocalize,
                           a2: VoiceCommandSubtitle,
                           a3: a2,
                           a4: a3);
  if ( v47 != nullptr )
  {
    wcsncpy(dest: szBuf, source: v47, count: 0x80u);
    szBuf[127] = 0;
  }
  else
  {
    g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: VoiceCommandSubtitle, a3: szBuf, a4: 256);
  }
  g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: szBuf, a3: szString, a4: 2048);
  v48 = strlen(szString);
  if ( v48 != 0 )
  {
    v49 = szString[v48 - 1];
    if ( v49 != 10 && v49 != 13 )
      V_strncat(pDest: szString, pSrc: "\n", destBufferSize: 0x800u, max_chars_to_copy: 1);
  }
  v50 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: "#Voice");
  g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: v50, a3: szPrefix, a4: 64);
  for ( i = szString; *i != 0; ++i )
  {
    if ( *i == 13 )
      *i = 10;
  }
  v52 = *v46;
  v53 = v64;
  v54 = (*(int (__thiscall **)(CBaseHudChat *, int, int, char *))(v52 + 140))(a1: v63, a2: v64, a3: 1, a4: szString);
  v56 = v53;
  v55 = v63;
  (*(void (**)(CBaseHudChat *, int, _DWORD, const char *, ...))(v52 + 88))(
    a1: v63,
    a2: v56,
    a3: 0,
    a4: "%c(%s) %s%c: %s",
    3,
    szPrefix,
    v54);
  v55->m_bEnteringVoice = false;
}

//------------------------------------------------------------------------------
// Address: 0x100F6010
// Name: public: virtual void CBaseHudChat::StartMessageMode(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseHudChat::StartMessageMode(CBaseHudChat *this, int iMessageModeType)
{
  int v2; // edi
  vgui::ISchemeManager *v4; // edi
  vgui::ISchemeManager_vtbl *v5; // ebx
  unsigned int v6; // eax
  int v7; // eax
  CHudChatHistory *m_pChatHistory; // edi
  unsigned int v9; // eax
  int v10; // [esp+20h] [ebp-18h]
  int x; // [esp+2Ch] [ebp-Ch] BYREF
  int w; // [esp+30h] [ebp-8h] BYREF
  int y; // [esp+34h] [ebp-4h] BYREF

  v2 = iMessageModeType;
  v10 = iMessageModeType;
  this->m_nMessageMode = iMessageModeType;
  ConVar::SetValue(this: (ConVar *)&cl_chat_active.IConVar, value: v10);
  this->m_pChatInput->m_pInput->SetText_2(this: this->m_pChatInput->m_pInput, a2: &szFunFact);
  this->SetChatPrompt(this, a2: v2);
  if ( this->m_pChatHistory != nullptr )
  {
    v4 = g_pVGuiSchemeManager;
    v5 = g_pVGuiSchemeManager->__vftable;
    v6 = this->GetScheme(this: &this->vgui::EditablePanel);
    v7 = (int)v5->GetIScheme(this: v4, a2: v6);
    m_pChatHistory = this->m_pChatHistory;
    v9 = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v7 + 12))(a1: v7, a2: "ChatFont", a3: 0);
    vgui::RichText::SetFont(this: m_pChatHistory, font: v9);
    this->m_pChatHistory->SetMouseInputEnabled(this: this->m_pChatHistory, a2: true);
    this->m_pChatHistory->SetKeyBoardInputEnabled(this: this->m_pChatHistory, a2: false);
    vgui::RichText::SetVerticalScrollbar(this: this->m_pChatHistory, state: true);
    vgui::RichText::ResetAllFades(this: this->m_pChatHistory, bHold: true, bOnlyExpired: false, flNewSustain: -1.0);
    this->m_pChatHistory->SetPaintBorderEnabled(this: this->m_pChatHistory, a2: true);
    this->m_pChatHistory->SetVisible(this: this->m_pChatHistory, a2: true);
  }
  vgui::Panel::MakeReadyForUse(this: &this->vgui::EditablePanel);
  this->SetKeyBoardInputEnabled(this: &this->vgui::EditablePanel, a2: true);
  this->SetMouseInputEnabled(this: &this->vgui::EditablePanel, a2: true);
  this->m_pChatInput->SetVisible(this: this->m_pChatInput, a2: true);
  g_pVGuiSurface->CalculateMouseVisible(this: g_pVGuiSurface);
  this->m_pChatInput->RequestFocus(this: this->m_pChatInput, a2: 0);
  this->m_pChatInput->SetPaintBorderEnabled(this: this->m_pChatInput, a2: true);
  this->m_pChatInput->SetMouseInputEnabled(this: this->m_pChatInput, a2: true);
  vgui::Panel::GetBounds(this: this->m_pChatHistory, &x, &y, wide: &w, tall: &iMessageModeType);
  g_pVGuiInput->SetCursorPos(this: g_pVGuiInput, a2: x + w / 2, a3: y + iMessageModeType / 2);
  this->m_pFilterPanel->SetVisible(this: this->m_pFilterPanel, a2: false);
  this->m_flHistoryFadeTime = *(float *)(gpGlobals.m_Index + 12) + 0.25;
  engine->ClientCmd_Unrestricted(this: engine, a2: "gameui_preventescapetoshow\n");
}

//------------------------------------------------------------------------------
// Address: 0x100F6220
// Name: public: virtual void CBaseHudChat::StopMessageMode(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseHudChat::StopMessageMode(CBaseHudChat *this, bool bFade)
{
  CHudChatHistory *m_pChatHistory; // ecx

  engine->ClientCmd_Unrestricted(this: engine, a2: "gameui_allowescapetoshow\n");
  this->SetKeyBoardInputEnabled(this: &this->vgui::EditablePanel, a2: false);
  this->SetMouseInputEnabled(this: &this->vgui::EditablePanel, a2: false);
  m_pChatHistory = this->m_pChatHistory;
  if ( m_pChatHistory != nullptr )
  {
    m_pChatHistory->SetPaintBorderEnabled(this: m_pChatHistory, a2: false);
    vgui::RichText::GotoTextEnd(this: this->m_pChatHistory);
    this->m_pChatHistory->SetMouseInputEnabled(this: this->m_pChatHistory, a2: false);
    vgui::RichText::SetVerticalScrollbar(this: this->m_pChatHistory, state: false);
    vgui::RichText::ResetAllFades(this: this->m_pChatHistory, bHold: false, bOnlyExpired: true, flNewSustain: 0.25);
    vgui::RichText::SelectNoText(this: this->m_pChatHistory);
  }
  this->m_pChatInput->m_pInput->SetText_2(this: this->m_pChatInput->m_pInput, a2: &szFunFact);
  this->m_nMessageMode = 0;
  ConVar::SetValue(this: (ConVar *)&cl_chat_active.IConVar, value: 0);
  if ( bFade )
    this->m_flHistoryFadeTime = *(float *)(gpGlobals.m_Index + 12) + 0.25;
  else
    this->m_flHistoryFadeTime = *(float *)(gpGlobals.m_Index + 12);
}

//------------------------------------------------------------------------------
// Address: 0x100F6330
// Name: public: void CBaseHudChat::FadeChatHistory(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBaseHudChat::FadeChatHistory(CBaseHudChat *this@<ecx>, int a2@<esi>)
{
  int v3; // ebx
  CHudChatHistory *m_pChatHistory; // ecx
  void (__thiscall *SetBgColor)(vgui::Panel *, Color); // edx
  Color *v6; // eax
  Color *(__thiscall *GetBgColor)(vgui::Panel *, Color *); // edx
  int v8; // eax
  Color *(__thiscall *v9)(vgui::Panel *, Color *); // edx
  void (__thiscall *v10)(vgui::Panel *, Color); // edx
  CHudChatHistory *v11; // ecx
  void (__thiscall *v12)(vgui::Panel *, Color); // edx
  Color *v13; // eax
  Color *(__thiscall *v14)(vgui::Panel *, Color *); // edx
  int v15; // eax
  Color *(__thiscall *v16)(vgui::Panel *, Color *); // edx
  vgui::EditablePanel_vtbl *v17; // eax
  void (__thiscall *v18)(vgui::Panel *, Color); // edx
  Color v19; // [esp+8h] [ebp-1Ch] BYREF
  Color v20; // [esp+Ch] [ebp-18h] BYREF
  Color v21; // [esp+10h] [ebp-14h] BYREF
  int v22; // [esp+14h] [ebp-10h]
  int v23; // [esp+18h] [ebp-Ch]
  int v24; // [esp+1Fh] [ebp-5h]
  char v25; // [esp+23h] [ebp-1h]

  v3 = (int)(float)((float)((float)(this->m_flHistoryFadeTime - *(float *)(gpGlobals.m_Index + 12)) * 4.0) * 127.0);
  if ( v3 >= 0 )
  {
    if ( v3 > 127 )
      v3 = 127;
  }
  else
  {
    v3 = 0;
  }
  if ( this->m_pChatHistory != nullptr )
  {
    if ( ((unsigned __int8 (__thiscall *)(vgui::EditablePanel *, int))this->IsMouseInputEnabled)(
           a1: &this->vgui::EditablePanel,
           a2) != 0 )
    {
      vgui::Panel::SetAlpha(this: &this->vgui::EditablePanel, alpha: 255);
      m_pChatHistory = this->m_pChatHistory;
      SetBgColor = m_pChatHistory->SetBgColor;
      v25 = 127 - v3;
      HIBYTE(v24) = 127 - v3;
      LOWORD(v24) = 0;
      BYTE2(v24) = 0;
      ((void (__thiscall *)(CHudChatHistory *, int))SetBgColor)(a1: m_pChatHistory, a2: v24);
      v6 = this->GetBgColor(this: &this->vgui::EditablePanel, result: &v21);
      GetBgColor = this->GetBgColor;
      v22 = v6->_color[2];
      v8 = (int)GetBgColor(this: &this->vgui::EditablePanel, result: &v20);
      v9 = this->GetBgColor;
      v23 = *(unsigned __int8 *)(v8 + 1);
      LOBYTE(v24) = v9(this: &this->vgui::EditablePanel, result: &v19)->_color[0];
      BYTE2(v24) = v22;
      v10 = this->SetBgColor;
      BYTE1(v24) = v23;
      HIBYTE(v24) = v25;
      ((void (__thiscall *)(vgui::EditablePanel *, int))v10)(a1: &this->vgui::EditablePanel, a2: v24);
      vgui::Panel::SetAlpha(this: this->m_pChatInput->m_pPrompt, alpha: 254 - v3);
      vgui::Panel::SetAlpha(this: this->m_pChatInput->m_pInput, alpha: 254 - v3);
      vgui::Panel::SetAlpha(this: this->m_pFiltersButton, alpha: 254 - v3);
    }
    else
    {
      v11 = this->m_pChatHistory;
      v12 = v11->SetBgColor;
      LOWORD(v24) = 0;
      BYTE2(v24) = 0;
      HIBYTE(v24) = v3;
      ((void (__thiscall *)(CHudChatHistory *, int))v12)(a1: v11, a2: v24);
      v13 = this->GetBgColor(this: &this->vgui::EditablePanel, result: &v19);
      v14 = this->GetBgColor;
      v23 = v13->_color[2];
      v15 = (int)v14(this: &this->vgui::EditablePanel, result: &v20);
      v16 = this->GetBgColor;
      v22 = *(unsigned __int8 *)(v15 + 1);
      LOBYTE(v24) = v16(this: &this->vgui::EditablePanel, result: &v21)->_color[0];
      v17 = this->vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable;
      BYTE1(v24) = v22;
      BYTE2(v24) = v23;
      v18 = v17->SetBgColor;
      HIBYTE(v24) = v3;
      ((void (__thiscall *)(vgui::EditablePanel *, int))v18)(a1: &this->vgui::EditablePanel, a2: v24);
      vgui::Panel::SetAlpha(this: this->m_pChatInput->m_pPrompt, alpha: v3);
      vgui::Panel::SetAlpha(this: this->m_pChatInput->m_pInput, alpha: v3);
      vgui::Panel::SetAlpha(this: this->m_pFiltersButton, alpha: v3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F6540
// Name: public: virtual class Color CBaseHudChat::GetTextColorForClient(enum TextColor,int)
// Source: json
//------------------------------------------------------------------------------
Color *__thiscall CBaseHudChat::GetTextColorForClient(
        CBaseHudChat *this,
        Color *result,
        TextColor colorNum,
        int clientIndex)
{
  Color *v5; // eax
  vgui::ISchemeManager *v6; // edi
  vgui::ISchemeManager_vtbl *v7; // ebx
  int v8; // eax
  vgui::IScheme *v9; // eax
  vgui::IScheme *v10; // edi
  vgui::IScheme_vtbl *v11; // ebx
  Color *v12; // eax
  Color v13; // ecx
  char v15[4]; // [esp+Ch] [ebp-Ch] BYREF
  char v16[4]; // [esp+10h] [ebp-8h] BYREF
  Color v17; // [esp+14h] [ebp-4h] BYREF

  if ( colorNum == COLOR_PLAYERNAME )
  {
    v5 = this->GetClientColor(this, result: v15, a3: clientIndex);
LABEL_10:
    v13 = *v5;
    goto LABEL_11;
  }
  if ( colorNum != COLOR_LOCATION )
  {
    if ( colorNum == COLOR_ACHIEVEMENT )
    {
      v6 = g_pVGuiSchemeManager;
      v7 = g_pVGuiSchemeManager->__vftable;
      v8 = ((int (__stdcall *)(const char *))g_pVGuiSchemeManager->GetScheme)(a1: "SourceScheme");
      v9 = v7->GetIScheme(this: v6, a2: v8);
      v10 = v9;
      if ( v9 != nullptr )
      {
        v11 = v9->__vftable;
        v12 = this->GetBgColor(this: &this->vgui::EditablePanel, result: &clientIndex);
        v5 = v11->GetColor(this: v10, result: &v17, a3: "SteamLightGreen", a4: *v12);
      }
      else
      {
        v5 = this->GetDefaultTextColor(this, result: v16);
      }
    }
    else
    {
      v5 = this->GetDefaultTextColor(this, result: &colorNum);
    }
    goto LABEL_10;
  }
  v13 = g_ColorDarkGreen;
LABEL_11:
  *(_WORD *)result->_color = *(_WORD *)v13._color;
  result->_color[2] = v13._color[2];
  result->_color[3] = -1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100F6610
// Name: public: void CBaseHudChat::LevelInit(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseHudChat::LevelInit(CBaseHudChat *this, const char *newmap)
{
  CHudChatHistory *m_pChatHistory; // ecx
  ConVar *m_pParent; // eax

  this->StopMessageMode(this, a2: true);
  m_pChatHistory = this->m_pChatHistory;
  this->m_flHistoryFadeTime = 0.0;
  if ( m_pChatHistory != nullptr )
    vgui::RichText::ResetAllFades(this: m_pChatHistory, bHold: false, bOnlyExpired: false, flNewSustain: 0.0);
  m_pParent = cl_chatfilter_version.m_pParent;
  if ( cl_chatfilter_version.m_pParent == nullptr || cl_chatfilter_version.m_pParent->m_Value.m_nValue == 0 )
  {
    this->m_iFilterFlags |= 0x20u;
    m_pParent = cl_chatfilter_version.m_pParent;
  }
  if ( m_pParent == nullptr || m_pParent->m_Value.m_nValue != 1 )
  {
    ConVar::SetValue(this: (ConVar *)&cl_chatfilters.IConVar, value: this->m_iFilterFlags);
    ConVar::SetValue(this: (ConVar *)&cl_chatfilter_version.IConVar, value: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F6690
// Name: public: virtual void CBaseHudChat::ChatPrintf(int,int,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CBaseHudChat::ChatPrintf(CBaseHudChat *this, int iPlayerIndex, int iFilter, char *fmt, ...)
{
  int v4; // eax
  char v5; // cl
  bool v6; // zf
  _BYTE *v7; // eax
  char v8; // al
  char *p_pDest; // esi
  CHud *Hud; // eax
  SFHudVoiceStatus *Element; // eax
  char v12; // [esp+1h] [ebp-1001h]
  char pDest; // [esp+2h] [ebp-1000h] BYREF
  _BYTE v14[3]; // [esp+3h] [ebp-FFFh] BYREF
  va_list params; // [esp+101Ah] [ebp+18h] BYREF

  va_start(params, fmt);
  V_vsnprintf(&pDest, maxLen: 0x1000u, pFormat: fmt, params);
  v4 = &v14[strlen(&pDest)] - v14;
  if ( v4 != 0 )
  {
    v6 = *(&v12 + v4) == 10;
    v7 = &v14[v4 - 1];
    if ( v6 )
      *(v7 - 1) = v5;
  }
  v8 = pDest;
  p_pDest = &pDest;
  if ( pDest != 0 )
  {
    while ( v8 == 10 || v8 > 0 && v8 < 8 )
    {
      v8 = *++p_pDest;
      if ( v8 == 0 )
        return;
    }
    if ( *p_pDest != 0 && (iFilter == 0 || (this->GetFilterFlags(this) & iFilter) != 0) )
    {
      Hud = GetHud(nSlot: -1);
      Element = (SFHudVoiceStatus *)CHud::FindElement(this: Hud, pName: "SFHudVoiceStatus");
      if ( Element != nullptr )
        SFHudVoiceStatus::PushNotice(this: Element, szNoticeText: p_pDest, clientId: iPlayerIndex);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F67F0
// Name: public: virtual void CBaseHudChat::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseHudChat::OnTick(CBaseHudChat *this)
{
  vgui::BuildGroup *buildGroup; // eax
  int iInputY; // [esp+4h] [ebp-30h] BYREF
  int iInputH; // [esp+8h] [ebp-2Ch] BYREF
  int iChatX; // [esp+Ch] [ebp-28h] BYREF
  int iChatY; // [esp+10h] [ebp-24h] BYREF
  int iChatW; // [esp+14h] [ebp-20h] BYREF
  int iChatHistoryX; // [esp+18h] [ebp-1Ch] BYREF
  int iChatHistoryW; // [esp+1Ch] [ebp-18h] BYREF
  int iChatHistoryH; // [esp+20h] [ebp-14h] BYREF
  int iChatHistoryY; // [esp+24h] [ebp-10h] BYREF
  int iInputX; // [esp+28h] [ebp-Ch] BYREF
  int iInputW; // [esp+2Ch] [ebp-8h] BYREF
  int iChatH; // [esp+30h] [ebp-4h] BYREF

  buildGroup = this->vgui::EditablePanel::_buildGroup;
  if ( buildGroup != nullptr )
  {
    this->m_NavGroup.vgui::EditablePanel::__vftable = (vgui::FocusNavGroup_vtbl *)(g_pVGuiSurface->GetFontTall(
                                                                                     this: g_pVGuiSurface,
                                                                                     a2: (unsigned int)buildGroup[2]._controlGroup.m_Memory.m_pMemory)
                                                                                 + 2);
    vgui::Panel::GetBounds((vgui::Panel *)this, x: &iChatX, y: &iChatY, wide: &iChatW, tall: &iChatH);
    vgui::Panel::GetBounds(
      this: *(vgui::Panel **)&this->m_OnCurrentDefaultButtonSet_register,
      x: &iInputX,
      y: &iInputY,
      wide: &iInputW,
      tall: &iInputH);
    vgui::Panel::SetBounds(
      this: *(vgui::Panel **)&this->m_OnCurrentDefaultButtonSet_register,
      x: iInputX,
      y: (int)((double)iChatH - (double)(int)this->m_NavGroup.vgui::EditablePanel::__vftable * 1.75),
      wide: iInputW,
      tall: (int)this->m_NavGroup.vgui::EditablePanel::__vftable);
    vgui::Panel::GetBounds(
      this: (vgui::Panel *)this->m_NavGroup._defaultButton.m_iPanelID,
      x: &iChatHistoryX,
      y: &iChatHistoryY,
      wide: &iChatHistoryW,
      tall: &iChatHistoryH);
    iChatHistoryH = (int)((double)iChatH
                        - (double)(int)this->m_NavGroup.vgui::EditablePanel::__vftable * 2.25
                        - (double)iChatHistoryY);
    vgui::Panel::SetBounds(
      this: (vgui::Panel *)this->m_NavGroup._defaultButton.m_iPanelID,
      x: iChatHistoryX,
      y: iChatHistoryY,
      wide: iChatHistoryW,
      tall: iChatHistoryH);
  }
  CBaseHudChat::FadeChatHistory(this: (CBaseHudChat *)((char *)this - 56), a2: (int)this);
}

//------------------------------------------------------------------------------
// Address: 0x100F6910
// Name: public: virtual void CBaseHudChatLine::Colorize(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseHudChatLine::Colorize(CBaseHudChatLine *this, unsigned __int8 alpha)
{
  int v3; // ebx
  vgui::Panel *v4; // eax
  void *v5; // eax
  vgui::RichText *v6; // eax
  TextRange *m_pMemory; // ecx
  int start; // eax
  signed int v9; // edi
  TextRange *v10; // edx
  vgui::Panel *v11; // eax
  vgui::RichText **v12; // eax
  vgui::RichText **v13; // edi
  vgui::RichText *v14; // ecx
  unsigned __int16 dest[4096]; // [esp+14h] [ebp-2008h] BYREF
  int i; // [esp+2014h] [ebp-8h]
  Color col; // [esp+2018h] [ebp-4h] BYREF

  vgui::RichText::SetText(this, text: prType);
  v3 = 0;
  v4 = this->GetParent(this);
  v5 = __RTDynamicCast(
         inptr: v4,
         VfDelta: 0,
         SrcType: &vgui::Panel `RTTI Type Descriptor',
         TargetType: &CBaseHudChat `RTTI Type Descriptor',
         isReference: 0);
  if ( v5 != nullptr )
  {
    v6 = *((vgui::RichText **)v5 + 115);
    if ( v6 != nullptr )
      vgui::RichText::InsertString(this: v6, text: "\n");
  }
  col = 0;
  for ( i = 0; i < this->m_textRanges.m_Size; ++i )
  {
    m_pMemory = this->m_textRanges.m_Memory.m_pMemory;
    start = m_pMemory[v3].start;
    v9 = m_pMemory[v3].end - start + 1;
    if ( v9 > 1 )
    {
      wcsncpy(dest, source: &this->m_text[start], count: v9);
      v10 = this->m_textRanges.m_Memory.m_pMemory;
      dest[v9 - 1] = 0;
      col = v10[v3].color;
      col._color[3] = alpha;
      vgui::RichText::InsertColorChange(this, col);
      vgui::RichText::InsertString(this, wszText: dest);
      ConColorMsg(a1: &col, a2: "%ls", dest);
      v11 = this->GetParent(this);
      v12 = (vgui::RichText **)__RTDynamicCast(
                                 inptr: v11,
                                 VfDelta: 0,
                                 SrcType: &vgui::Panel `RTTI Type Descriptor',
                                 TargetType: &CBaseHudChat `RTTI Type Descriptor',
                                 isReference: 0);
      v13 = v12;
      if ( v12 != nullptr )
      {
        v14 = v12[115];
        if ( v14 != nullptr )
        {
          vgui::RichText::InsertColorChange(this: v14, col);
          vgui::RichText::InsertString(this: v13[115], wszText: dest);
          vgui::RichText::InsertFade(
            this: v13[115],
            flSustain: hud_saytext_time.m_pParent->m_Value.m_fValue,
            flLength: 2.5);
          if ( i == this->m_textRanges.m_Size - 1 )
            vgui::RichText::InsertFade(this: v13[115], flSustain: -1.0, flLength: -1.0);
        }
      }
    }
    ++v3;
  }
  _Msg(a1: "\n");
  this->InvalidateLayout(this, a2: true, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x100F6C70
// Name: public: CBaseHudChatLine::CBaseHudChatLine(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseHudChatLine *__thiscall CBaseHudChatLine::CBaseHudChatLine(
        CBaseHudChatLine *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::RichText::RichText(this, parent, panelName);
  this->__vftable = (CBaseHudChatLine_vtbl *)&CBaseHudChatLine::`vftable';
  this->m_clrText = 0;
  this->m_clrNameColor = 0;
  this->m_textRanges.m_Memory.m_pMemory = nullptr;
  this->m_textRanges.m_Memory.m_nAllocationCount = 0;
  this->m_textRanges.m_Memory.m_nGrowSize = 0;
  this->m_textRanges.m_Size = 0;
  this->m_textRanges.m_pElements = nullptr;
  this->m_hFontMarlett = 0;
  this->m_hFont = 0;
  this->m_flExpireTime = 0.0;
  this->m_flStartTime = 0.0;
  this->m_iNameLength = 0;
  this->m_text = nullptr;
  vgui::Panel::SetPaintBackgroundEnabled(this, state: true);
  vgui::RichText::SetVerticalScrollbar(this, state: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100F6D00
// Name: public: static char const __near * vgui::RichText::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::RichText::GetPanelClassName()
{
  return "RichText";
}

//------------------------------------------------------------------------------
// Address: 0x100F6D10
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::RichText::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::RichText::GetMessageMap(vgui::RichText *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::RichText::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::RichText::GetMessageMap'::`2'::s_pMap;
  `vgui::RichText::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "RichText");
  `vgui::RichText::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100F6D40
// Name: public: virtual struct PanelAnimationMap __near * vgui::RichText::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::RichText::GetAnimMap(vgui::RichText *this)
{
  return FindOrAddPanelAnimationMap(className: "RichText");
}

//------------------------------------------------------------------------------
// Address: 0x100F6D50
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::RichText::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::RichText::GetKBMap(vgui::RichText *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::RichText::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::RichText::GetKBMap'::`2'::s_pMap;
  `vgui::RichText::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "RichText");
  `vgui::RichText::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100F6D80
// Name: public: virtual CBaseHudChatLine::~CBaseHudChatLine(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseHudChatLine::~CBaseHudChatLine(CBaseHudChatLine *this)
{
  wchar_t *m_text; // eax

  m_text = this->m_text;
  this->__vftable = (CBaseHudChatLine_vtbl *)&CBaseHudChatLine::`vftable';
  if ( m_text != nullptr )
  {
    C_BaseEntity::operator delete(pMem: m_text);
    this->m_text = nullptr;
  }
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_textRanges);
  vgui::RichText::~RichText(this);
}

//------------------------------------------------------------------------------
// Address: 0x100F6DC0
// Name: public: virtual void CBaseHudChat::CreateChatLines(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseHudChat::CreateChatLines(CBaseHudChat *this)
{
  CBaseHudChatLine *v2; // eax
  CBaseHudChatLine *v3; // eax

  v2 = (CBaseHudChatLine *)MemAlloc_Alloc(nSize: 0x25Cu);
  if ( v2 != nullptr )
  {
    if ( this != nullptr )
      v3 = CBaseHudChatLine::CBaseHudChatLine(this: v2, parent: &this->vgui::EditablePanel, panelName: "ChatLine1");
    else
      v3 = CBaseHudChatLine::CBaseHudChatLine(this: v2, parent: nullptr, panelName: "ChatLine1");
  }
  else
  {
    v3 = nullptr;
  }
  this->m_ChatLine = v3;
  v3->SetVisible(this: v3, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x100F6EC0
// Name: public: static void CHudChatFilterPanel::PanelMessageFunc_OnFilterButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CHudChatFilterPanel::PanelMessageFunc_OnFilterButtonChecked::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CHudChatFilterPanel::PanelMessageFunc_OnFilterButtonChecked::InitVar'::`2'::bAdded )
  {
    `CHudChatFilterPanel::PanelMessageFunc_OnFilterButtonChecked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CSaveGamePanel::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CHudChatFilterPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "CheckButtonChecked";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x400000001LL;
    LODWORD(v4.m[2][2]) = "panel";
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F6FD0
// Name: public: CHudChatFilterPanel::CHudChatFilterPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CHudChatFilterPanel *__thiscall CHudChatFilterPanel::CHudChatFilterPanel(
        CHudChatFilterPanel *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CHudChatFilterCheckButton *v7; // eax
  CHudChatFilterCheckButton *v8; // eax
  CHudChatFilterCheckButton *v9; // eax
  CHudChatFilterCheckButton *v10; // eax
  CHudChatFilterCheckButton *v11; // eax
  CHudChatFilterCheckButton *v12; // eax

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: pName);
  this->__vftable = (CHudChatFilterPanel_vtbl *)&CHudChatFilterPanel::`vftable';
  if ( `CHudChatFilterPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CHudChatFilterPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CHudChatFilterPanel");
    v4->pfnClassName = CHudChatFilterPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CHudChatFilterPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CHudChatFilterPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CHudChatFilterPanel");
    v5->pfnClassName = CHudChatFilterPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CHudChatFilterPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CHudChatFilterPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CHudChatFilterPanel");
    v6->pfnClassName = CHudChatFilterPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  CHudChatFilterPanel::PanelMessageFunc_OnFilterButtonChecked::InitVar();
  vgui::Panel::SetSize(this: pParent, wide: 10, tall: 10);
  vgui::Panel::SetParent(this, newParent: pParent);
  v7 = (CHudChatFilterCheckButton *)MemAlloc_Alloc(nSize: 0x220u);
  if ( v7 != nullptr )
    CHudChatFilterCheckButton::CHudChatFilterCheckButton(
      this: v7,
      pParent: this,
      pName: "joinleave_button",
      pText: "Sky is blue?",
      iFlag: 1);
  v8 = (CHudChatFilterCheckButton *)MemAlloc_Alloc(nSize: 0x220u);
  if ( v8 != nullptr )
    CHudChatFilterCheckButton::CHudChatFilterCheckButton(
      this: v8,
      pParent: this,
      pName: "namechange_button",
      pText: "Sky is blue?",
      iFlag: 2);
  v9 = (CHudChatFilterCheckButton *)MemAlloc_Alloc(nSize: 0x220u);
  if ( v9 != nullptr )
    CHudChatFilterCheckButton::CHudChatFilterCheckButton(
      this: v9,
      pParent: this,
      pName: "publicchat_button",
      pText: "Sky is blue?",
      iFlag: 4);
  v10 = (CHudChatFilterCheckButton *)MemAlloc_Alloc(nSize: 0x220u);
  if ( v10 != nullptr )
    CHudChatFilterCheckButton::CHudChatFilterCheckButton(
      this: v10,
      pParent: this,
      pName: "servermsg_button",
      pText: "Sky is blue?",
      iFlag: 8);
  v11 = (CHudChatFilterCheckButton *)MemAlloc_Alloc(nSize: 0x220u);
  if ( v11 != nullptr )
    CHudChatFilterCheckButton::CHudChatFilterCheckButton(
      this: v11,
      pParent: this,
      pName: "teamchange_button",
      pText: "Sky is blue?",
      iFlag: 16);
  v12 = (CHudChatFilterCheckButton *)MemAlloc_Alloc(nSize: 0x220u);
  if ( v12 != nullptr )
    CHudChatFilterCheckButton::CHudChatFilterCheckButton(
      this: v12,
      pParent: this,
      pName: "achivement_button",
      pText: "Sky is blue?",
      iFlag: 32);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100F7190
// Name: public: virtual struct vgui::PanelMessageMap __near * CHudChatFilterPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CHudChatFilterPanel::GetMessageMap(CHudChatFilterPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CHudChatFilterPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CHudChatFilterPanel::GetMessageMap'::`2'::s_pMap;
  `CHudChatFilterPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CHudChatFilterPanel");
  `CHudChatFilterPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100F71C0
// Name: public: virtual struct PanelAnimationMap __near * CHudChatFilterPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CHudChatFilterPanel::GetAnimMap(CHudChatFilterPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CHudChatFilterPanel");
}

//------------------------------------------------------------------------------
// Address: 0x100F71D0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CHudChatFilterPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CHudChatFilterPanel::GetKBMap(CHudChatFilterPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CHudChatFilterPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CHudChatFilterPanel::GetKBMap'::`2'::s_pMap;
  `CHudChatFilterPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CHudChatFilterPanel");
  `CHudChatFilterPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100F7200
// Name: public: class CHudChatFilterPanel __near * CBaseHudChat::GetChatFilterPanel(void)
// Source: json
//------------------------------------------------------------------------------
CHudChatFilterPanel *__thiscall CBaseHudChat::GetChatFilterPanel(CBaseHudChat *this)
{
  CHudChatFilterPanel *v2; // eax
  CHudChatFilterPanel *result; // eax

  if ( this->m_pFilterPanel != nullptr )
    return this->m_pFilterPanel;
  v2 = (CHudChatFilterPanel *)MemAlloc_Alloc(nSize: 0x180u);
  if ( v2 != nullptr )
    result = CHudChatFilterPanel::CHudChatFilterPanel(
               this: v2,
               pParent: &this->vgui::EditablePanel,
               pName: "HudChatFilterPanel");
  else
    result = nullptr;
  this->m_pFilterPanel = result;
  if ( result != nullptr )
  {
    result->SetScheme_2(this: result, a2: "ChatScheme");
    this->m_pFilterPanel->InvalidateLayout(this: this->m_pFilterPanel, a2: true, a3: true);
    this->m_pFilterPanel->SetMouseInputEnabled(this: this->m_pFilterPanel, a2: true);
    this->m_pFilterPanel->SetPaintBackgroundType(this: this->m_pFilterPanel, a2: 2);
    this->m_pFilterPanel->SetPaintBorderEnabled(this: this->m_pFilterPanel, a2: true);
    this->m_pFilterPanel->SetVisible(this: this->m_pFilterPanel, a2: false);
    return this->m_pFilterPanel;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100F72C0
// Name: public: virtual void CBaseHudChatLine::InsertAndColorizeText(wchar_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseHudChatLine::InsertAndColorizeText(CBaseHudChatLine *this, wchar_t *buf, int clientIndex)
{
  wchar_t *v4; // eax
  CBaseHudChatLine_vtbl *v5; // edx
  vgui::Panel *v6; // eax
  CBaseHudChat *v7; // ecx
  wchar_t *m_text; // eax
  wchar_t *v9; // edx
  __int16 v10; // si
  int v11; // edx
  int v12; // edx
  Color *(__thiscall *GetTextColorForClient)(CBaseHudChat *, Color *, TextColor, int); // edx
  int v14; // esi
  int m_Size; // eax
  int v16; // esi
  int m_nAllocationCount; // eax
  TextRange *m_pMemory; // ecx
  int v19; // eax
  TextRange *v20; // eax
  Color *(__thiscall *v21)(CBaseHudChat *, Color *, TextColor, int); // edx
  Color *v22; // eax
  int v23; // esi
  Color *(__thiscall *v24)(CBaseHudChat *, Color *, TextColor, int); // eax
  Color v25; // ecx
  int v26; // eax
  wchar_t *v27; // eax
  wchar_t *v28; // edx
  __int16 v29; // cx
  int v30; // eax
  Color *(__thiscall *v31)(CBaseHudChat *, Color *, TextColor, int); // edx
  Color *v32; // eax
  wchar_t *v33; // edx
  wchar_t *v34; // esi
  __int16 v35; // ax
  Color *(__thiscall *v36)(CBaseHudChat *, Color *, TextColor, int); // eax
  Color v37; // ecx
  int v38; // eax
  int v39; // edx
  TextRange *v40; // eax
  unsigned int v41; // ecx
  int v42; // [esp-8h] [ebp-30h]
  int v43; // [esp-8h] [ebp-30h]
  const wchar_t *v44; // [esp-4h] [ebp-2Ch]
  TextRange range; // [esp+Ch] [ebp-1Ch] BYREF
  Color v46; // [esp+18h] [ebp-10h] BYREF
  int lineLen; // [esp+1Ch] [ebp-Ch]
  wchar_t *v48; // [esp+20h] [ebp-8h]
  CBaseHudChat *pChat; // [esp+24h] [ebp-4h]

  if ( this->m_text != nullptr )
  {
    C_BaseEntity::operator delete(pMem: this->m_text);
    this->m_text = nullptr;
  }
  v44 = buf;
  this->m_textRanges.m_Size = 0;
  v4 = CloneWString(str: v44);
  v5 = this->__vftable;
  this->m_text = v4;
  v6 = v5->GetParent(this);
  v7 = (CBaseHudChat *)__RTDynamicCast(
                         inptr: v6,
                         VfDelta: 0,
                         SrcType: &vgui::Panel `RTTI Type Descriptor',
                         TargetType: &CBaseHudChat `RTTI Type Descriptor',
                         isReference: 0);
  pChat = v7;
  if ( v7 != nullptr )
  {
    m_text = this->m_text;
    v9 = m_text;
    buf = m_text;
    v48 = m_text + 1;
    do
      v10 = *v9++;
    while ( v10 != 0 );
    lineLen = v9 - v48;
    v11 = *m_text;
    if ( (v11 == 3 || v11 == 4 || v11 == 1 || v11 == 5 || v11 == 6 || v11 == 7) && m_text != nullptr )
    {
      do
      {
        v12 = *m_text;
        if ( (_WORD)v12 == 0 )
          break;
        range.color = 0;
        v48 = (wchar_t *)v12;
        if ( v12 == 1 || v12 > 2 && v12 <= 7 )
        {
          GetTextColorForClient = v7->GetTextColorForClient;
          v14 = m_text - this->m_text + 1;
          range.start = v14;
          range.color = *GetTextColorForClient(this: v7, result: &v46, a3: (TextColor)v48, a4: clientIndex);
          m_Size = this->m_textRanges.m_Size;
          range.end = lineLen;
          if ( m_Size != 0 )
            this->m_textRanges.m_Memory.m_pMemory[m_Size - 1].end = v14 - 1;
          v16 = this->m_textRanges.m_Size;
          m_nAllocationCount = this->m_textRanges.m_Memory.m_nAllocationCount;
          if ( v16 + 1 > m_nAllocationCount )
            CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
              this: (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)&this->m_textRanges,
              num: v16 - m_nAllocationCount + 1);
          ++this->m_textRanges.m_Size;
          m_pMemory = this->m_textRanges.m_Memory.m_pMemory;
          v19 = this->m_textRanges.m_Size - v16 - 1;
          this->m_textRanges.m_pElements = m_pMemory;
          if ( v19 > 0 )
            _V_memmove(
              dest: (unsigned __int8 *)&m_pMemory[v16 + 1],
              src: (unsigned __int8 *)&m_pMemory[v16],
              count: 12 * v19);
          v20 = &this->m_textRanges.m_Memory.m_pMemory[v16];
          if ( v20 != nullptr )
            *v20 = range;
          m_text = ++buf;
          v7 = pChat;
        }
        else
        {
          buf = ++m_text;
        }
      }
      while ( m_text != nullptr );
    }
    if ( this->m_textRanges.m_Size == 0 )
    {
      if ( this->m_iNameLength > 0 && *this->m_text == 2 )
      {
        v21 = v7->GetTextColorForClient;
        range.end = this->m_iNameStart;
        range.start = 0;
        v22 = v21(this: v7, result: (Color *)&buf, a3: COLOR_NORMAL, a4: clientIndex);
        v42 = this->m_textRanges.m_Size;
        range.color = *v22;
        CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
          this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&this->m_textRanges,
          elem: v42,
          src: (const QAngle *)&range);
        v23 = this->m_iNameStart + this->m_iNameLength;
        range.start = this->m_iNameStart;
        v24 = pChat->GetTextColorForClient;
        range.end = v23;
        v25 = *v24(this: pChat, result: (Color *)&buf, a3: COLOR_PLAYERNAME, a4: clientIndex);
        v26 = this->m_textRanges.m_Size;
        range.color = v25;
        CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
          this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&this->m_textRanges,
          elem: v26,
          src: (const QAngle *)&range);
        v27 = this->m_text;
        range.start = v23;
        v28 = v27 + 1;
        do
          v29 = *v27++;
        while ( v29 != 0 );
        v30 = (char *)v27 - (char *)v28;
        v31 = pChat->GetTextColorForClient;
        range.end = v30 >> 1;
        v32 = v31(this: pChat, result: (Color *)&buf, a3: COLOR_NORMAL, a4: clientIndex);
        v43 = this->m_textRanges.m_Size;
        range.color = *v32;
        CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
          this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&this->m_textRanges,
          elem: v43,
          src: (const QAngle *)&range);
        v7 = pChat;
      }
      if ( this->m_textRanges.m_Size == 0 )
      {
        v33 = this->m_text;
        range.start = 0;
        v34 = v33 + 1;
        do
          v35 = *v33++;
        while ( v35 != 0 );
        v36 = v7->GetTextColorForClient;
        range.end = v33 - v34;
        v37 = *v36(this: v7, result: (Color *)&clientIndex, a3: COLOR_NORMAL, a4: clientIndex);
        v38 = this->m_textRanges.m_Size;
        range.color = v37;
        CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
          this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&this->m_textRanges,
          elem: v38,
          src: (const QAngle *)&range);
      }
    }
    v39 = 0;
    for ( clientIndex = 0; clientIndex < this->m_textRanges.m_Size; ++clientIndex )
    {
      v40 = &this->m_textRanges.m_Memory.m_pMemory[v39];
      v41 = this->m_text[v40->start];
      if ( (_WORD)v41 != 0 && v41 < 8 )
        ++v40->start;
      ++v39;
    }
    this->Colorize(this, a2: 255);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F7640
// Name: public: virtual void CHudChatFilterButton::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudChatFilterButton::DoClick(CHudChatFilterButton *this)
{
  vgui::Panel *v2; // eax
  CBaseHudChat *v3; // eax
  CBaseHudChat *v4; // esi
  CHudChatFilterPanel *ChatFilterPanel; // eax
  CHudChatFilterPanel *v6; // eax
  CHudChatFilterPanel *v7; // eax
  CHudChatFilterPanel *v8; // eax
  CHudChatFilterPanel *v9; // eax

  vgui::Button::DoClick(this);
  v2 = this->GetParent(this);
  v3 = (CBaseHudChat *)__RTDynamicCast(
                         inptr: v2,
                         VfDelta: 0,
                         SrcType: &vgui::Panel `RTTI Type Descriptor',
                         TargetType: &CBaseHudChat `RTTI Type Descriptor',
                         isReference: 0);
  v4 = v3;
  if ( v3 != nullptr )
  {
    v3->m_pChatInput->RequestFocus(this: v3->m_pChatInput, a2: 0);
    if ( CBaseHudChat::GetChatFilterPanel(this: v4) != nullptr )
    {
      ChatFilterPanel = CBaseHudChat::GetChatFilterPanel(this: v4);
      if ( ChatFilterPanel->IsVisible(this: ChatFilterPanel) )
      {
        v6 = CBaseHudChat::GetChatFilterPanel(this: v4);
        v6->SetVisible(this: v6, a2: false);
      }
      else
      {
        v7 = CBaseHudChat::GetChatFilterPanel(this: v4);
        v7->SetVisible(this: v7, a2: true);
        v8 = CBaseHudChat::GetChatFilterPanel(this: v4);
        vgui::Panel::MakePopup(this: v8, showTaskbarIcon: 1, disabled: 0);
        v9 = CBaseHudChat::GetChatFilterPanel(this: v4);
        v9->SetMouseInputEnabled(this: v9, a2: true);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F7700
// Name: public: CBaseHudChat::CBaseHudChat(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseHudChat *__thiscall CBaseHudChat::CBaseHudChat(CBaseHudChat *this, const char *pElementName)
{
  vgui::PanelMessageMap *v3; // ebx
  PanelAnimationMap *v4; // ebx
  vgui::PanelKeyBindingMap *v5; // ebx
  ClientModeCSFullscreen *FullscreenClientMode; // eax
  vgui::Panel *v7; // eax
  unsigned int v8; // ebx
  CHudChatFilterButton *v9; // eax
  CHudChatFilterButton *v10; // eax
  CHudChatHistory *v11; // eax
  CHudChatHistory *v12; // eax
  CBaseHudChatLine *v13; // eax
  CBaseHudChatLine *v14; // eax

  CHudElement::CHudElement(this, pElementName);
  vgui::EditablePanel::EditablePanel(this: &this->vgui::EditablePanel, parent: nullptr, panelName: "HudChat");
  this->CHudElement::CGameEventListener::IGameEventListener2::__vftable = (CBaseHudChat_vtbl *)&CBaseHudChat::`vftable'{for `CHudElement'};
  this->vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (vgui::EditablePanel_vtbl *)&CBaseHudChat::`vftable'{for `vgui::EditablePanel'};
  if ( `CBaseHudChat::ChainToMap'::`2'::chained == 0 )
  {
    `CBaseHudChat::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CBaseHudChat");
    v3->pfnClassName = CBaseHudChat::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CBaseHudChat::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CBaseHudChat::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CBaseHudChat");
    v4->pfnClassName = CBaseHudChat::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CBaseHudChat::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CBaseHudChat::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseHudChat");
    v5->pfnClassName = CBaseHudChat::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  g_pHudChat = this;
  FullscreenClientMode = GetFullscreenClientMode();
  v7 = FullscreenClientMode->GetViewport(this: FullscreenClientMode);
  vgui::Panel::SetParent(this: &this->vgui::EditablePanel, newParent: v7);
  v8 = g_pVGuiSchemeManager->LoadSchemeFromFileEx(
         this: g_pVGuiSchemeManager,
         a2: 0,
         a3: "resource/ChatScheme.res",
         a4: "ChatScheme");
  vgui::Panel::SetScheme(this: &this->vgui::EditablePanel, scheme: v8);
  g_pVGuiLocalize->AddFile(this: g_pVGuiLocalize, a2: "resource/chat_%language%.txt", a3: nullptr, a4: false);
  this->m_nMessageMode = 0;
  ConVar::SetValue(this: (ConVar *)&cl_chat_active.IConVar, value: 0);
  g_pVGui->AddTickSignal(this: g_pVGui, a2: this->_vpanel, a3: 0);
  vgui::Panel::MakePopup(this: &this->vgui::EditablePanel, showTaskbarIcon: 1, disabled: 0);
  vgui::Panel::SetZPos(this: &this->vgui::EditablePanel, z: -30);
  CTraceFilterSkipTwoEntities::SetPassEntity2(
    (CTraceFilterSkipTwoEntities *)this,
    pPassEntity2: (const IHandleEntity *)0x80);
  v9 = (CHudChatFilterButton *)MemAlloc_Alloc(nSize: 0x1F8u);
  if ( v9 != nullptr )
    v10 = CHudChatFilterButton::CHudChatFilterButton(
            this: v9,
            pParent: &this->vgui::EditablePanel,
            pName: "ChatFiltersButton",
            pText: "#chat_filterbutton");
  else
    v10 = nullptr;
  this->m_pFiltersButton = v10;
  if ( v10 != nullptr )
  {
    v10->SetScheme(this: v10, a2: v8);
    this->m_pFiltersButton->SetVisible(this: this->m_pFiltersButton, a2: true);
    this->m_pFiltersButton->SetEnabled(this: this->m_pFiltersButton, a2: true);
    this->m_pFiltersButton->SetMouseInputEnabled(this: this->m_pFiltersButton, a2: true);
    this->m_pFiltersButton->SetKeyBoardInputEnabled(this: this->m_pFiltersButton, a2: false);
  }
  v11 = (CHudChatHistory *)MemAlloc_Alloc(nSize: 0x224u);
  if ( v11 != nullptr )
    v12 = CHudChatHistory::CHudChatHistory(this: v11, pParent: &this->vgui::EditablePanel, panelName: "HudChatHistory");
  else
    v12 = nullptr;
  this->m_pChatHistory = v12;
  v13 = (CBaseHudChatLine *)MemAlloc_Alloc(nSize: 0x25Cu);
  if ( v13 != nullptr )
    v14 = CBaseHudChatLine::CBaseHudChatLine(this: v13, parent: &this->vgui::EditablePanel, panelName: "ChatLine1");
  else
    v14 = nullptr;
  this->m_ChatLine = v14;
  v14->SetVisible(this: v14, a2: false);
  CBaseHudChat::CreateChatInputLine(this);
  CBaseHudChat::GetChatFilterPanel(this);
  if ( cl_chatfilters.m_pParent != nullptr )
    this->m_iFilterFlags = cl_chatfilters.m_pParent->m_Value.m_nValue;
  else
    this->m_iFilterFlags = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100F7990
// Name: ParseTokens
// Source: json
//------------------------------------------------------------------------------
CUtlLinkedList<char const *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<char const *,unsigned short>,unsigned short> > *__cdecl ParseTokens(
        char *szString)
{
  CUtlLinkedList<char const *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<char const *,unsigned short>,unsigned short> > *v1; // eax
  UtlLinkedListElem_t<char const *,unsigned short> *m_pMemory; // ecx
  CUtlLinkedList<char const *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<char const *,unsigned short>,unsigned short> > *v3; // ebx
  unsigned __int16 v4; // ax
  int v5; // esi
  UtlLinkedListElem_t<char const *,unsigned short> *v6; // eax
  unsigned __int16 v7; // ax
  int v8; // esi
  UtlLinkedListElem_t<char const *,unsigned short> *v9; // eax
  unsigned __int16 v10; // ax
  int v11; // esi
  UtlLinkedListElem_t<char const *,unsigned short> *v12; // eax
  char *v13; // esi
  char *v14; // ecx
  char *v16; // eax
  const char *v17; // edi
  char *v18; // eax
  const char **v19; // esi
  const char **v20; // esi
  const char *v21; // esi
  unsigned __int16 v22; // ax
  int v23; // edi
  UtlLinkedListElem_t<char const *,unsigned short> *v24; // eax
  unsigned __int16 v25; // ax
  int v26; // edi
  UtlLinkedListElem_t<char const *,unsigned short> *v27; // eax
  const char *v28; // [esp+Ch] [ebp-8h]
  char *pStart; // [esp+10h] [ebp-4h]

  v1 = (CUtlLinkedList<char const *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<char const *,unsigned short>,unsigned short> > *)MemAlloc_Alloc(nSize: 0x1Cu);
  if ( v1 != nullptr )
  {
    v1->m_Memory.m_pMemory = nullptr;
    v1->m_Memory.m_nAllocationCount = 0;
    v1->m_Memory.m_nGrowSize = 0;
    v1->m_LastAlloc.index = -1;
    *(_DWORD *)&v1->m_FirstFree = 0xFFFF;
    m_pMemory = v1->m_Memory.m_pMemory;
    *(_DWORD *)&v1->m_Head = -1;
    v1->m_NumAlloced = 0;
    v1->m_pElements = m_pMemory;
    v3 = v1;
  }
  else
  {
    v3 = nullptr;
  }
  v4 = CUtlLinkedList<char const *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<char const *,unsigned short>,unsigned short>>::AllocInternal(
         this: v3,
         multilist: false);
  v5 = v4;
  if ( v4 != 0xFFFF )
  {
    CUtlLinkedList<char const *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<char const *,unsigned short>,unsigned short>>::LinkAfter(
      this: v3,
      after: 0xFFFFu,
      elem: v4);
    v6 = &v3->m_Memory.m_pMemory[v5];
    if ( v6 != nullptr )
      v6->m_Element = "NONE";
  }
  v7 = CUtlLinkedList<char const *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<char const *,unsigned short>,unsigned short>>::AllocInternal(
         this: v3,
         multilist: false);
  v8 = v7;
  if ( v7 != 0xFFFF )
  {
    CUtlLinkedList<char const *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<char const *,unsigned short>,unsigned short>>::LinkAfter(
      this: v3,
      after: 0xFFFFu,
      elem: v7);
    v9 = &v3->m_Memory.m_pMemory[v8];
    if ( v9 != nullptr )
      v9->m_Element = "High";
  }
  v10 = CUtlLinkedList<char const *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<char const *,unsigned short>,unsigned short>>::AllocInternal(
          this: v3,
          multilist: false);
  v11 = v10;
  if ( v10 != 0xFFFF )
  {
    CUtlLinkedList<char const *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<char const *,unsigned short>,unsigned short>>::LinkAfter(
      this: v3,
      after: 0xFFFFu,
      elem: v10);
    v12 = &v3->m_Memory.m_pMemory[v11];
    if ( v12 != nullptr )
      v12->m_Element = "triage";
  }
  v13 = szString;
  v14 = &szString[_V_strlen(str: szString) - 1];
  if ( v14 >= szString )
  {
    do
    {
      if ( *v14 == 41 )
      {
        v16 = v14 - 1;
        v17 = nullptr;
        if ( v14 - 1 >= v13 )
        {
          while ( *v16 == 32 )
          {
            if ( --v16 < v13 )
              goto LABEL_25;
          }
          if ( v16 >= v13 )
          {
            v14 = v16 + 1;
            v16[1] = 0;
          }
        }
LABEL_25:
        v18 = v14;
        pStart = v14;
        if ( v14 > v13 )
        {
          do
          {
            if ( *v18 == 40 )
              break;
            --v18;
          }
          while ( v18 > v13 );
          pStart = v18;
        }
        if ( v18 >= v13 )
        {
          *v18 = 0;
          v17 = v18 + 1;
        }
        if ( v17 >= v13 && v17 != v14 )
        {
          v19 = gBugTokenTable;
          if ( gBugTokenTable[0] != nullptr )
          {
            while ( _V_stricmp(s1: *v19, s2: v17) != 0 )
            {
              v19 += 2;
              if ( *v19 == nullptr )
                goto LABEL_36;
            }
            v28 = v19[1];
          }
          else
          {
LABEL_36:
            v28 = v17;
          }
          v20 = gBugPriorityTable;
          if ( gBugPriorityTable[0] != nullptr )
          {
            while ( _V_stricmp(s1: *v20, s2: v17) != 0 )
            {
              if ( *++v20 == nullptr )
                goto LABEL_40;
            }
            v21 = *v20;
          }
          else
          {
LABEL_40:
            v21 = nullptr;
          }
          v22 = CUtlLinkedList<char const *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<char const *,unsigned short>,unsigned short>>::AllocInternal(
                  this: v3,
                  multilist: false);
          v23 = v22;
          if ( v22 != 0xFFFF )
          {
            CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::LinkBefore(
              this: (CUtlLinkedList<C_RopeKeyframe *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_RopeKeyframe *,unsigned short>,unsigned short> > *)v3,
              before: 0xFFFFu,
              elem: v22);
            v24 = &v3->m_Memory.m_pMemory[v23];
            if ( v24 != nullptr )
              v24->m_Element = v28;
          }
          if ( v21 != nullptr )
          {
            v25 = CUtlLinkedList<char const *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<char const *,unsigned short>,unsigned short>>::AllocInternal(
                    this: v3,
                    multilist: false);
            v26 = v25;
            if ( v25 != 0xFFFF )
            {
              CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::LinkBefore(
                this: (CUtlLinkedList<C_RopeKeyframe *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_RopeKeyframe *,unsigned short>,unsigned short> > *)v3,
                before: 0xFFFFu,
                elem: v25);
              v27 = &v3->m_Memory.m_pMemory[v26];
              if ( v27 != nullptr )
                v27->m_Element = v21;
            }
          }
          v13 = szString;
          v18 = pStart;
        }
        v14 = v18;
      }
      else
      {
        if ( *v14 != 32 )
          return v3;
        *v14 = 0;
      }
      --v14;
    }
    while ( v14 >= v13 );
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100F7BC0
// Name: public: void CBaseHudChat::Send(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseHudChat::Send(CBaseHudChat *this)
{
  signed int v2; // esi
  CUtlLinkedList<char const *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<char const *,unsigned short>,unsigned short> > *v3; // edi
  int m_Head; // eax
  UtlLinkedListElem_t<char const *,unsigned short> *m_pMemory; // ecx
  int v6; // esi
  const char *v7; // eax
  char v8[2048]; // [esp+8h] [ebp-1404h] BYREF
  char v9[1024]; // [esp+808h] [ebp-C04h] BYREF
  char pDest[1024]; // [esp+C08h] [ebp-804h] BYREF
  char str[4]; // [esp+1008h] [ebp-404h] BYREF
  char pSrc[1020]; // [esp+100Ch] [ebp-400h] BYREF
  signed int v13; // [esp+1408h] [ebp-4h]

  this->m_pChatInput->m_pInput->GetText(this: this->m_pChatInput->m_pInput, a2: (wchar_t *)v8, a3: 2048);
  g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: (const wchar_t *)v8, a3: str, a4: 1024);
  v2 = _V_strlen(str);
  v13 = v2;
  if ( V_strnicmp(s1: str, s2: "bug!", n: 4) == 0 || V_strnicmp(s1: str, s2: "bug:", n: 4) == 0 )
  {
    V_strncpy(pDest, pSrc, maxLen: 1024);
    v3 = ParseTokens(szString: pDest);
    if ( _V_strlen(str: pDest) != 0 )
      V_snprintf(pDest: v9, maxLen: 0x400u, pFormat: "bug -auto -title \"%s\"", pDest);
    else
      V_strncpy(pDest: v9, pSrc: "bug", maxLen: 1024);
    m_Head = v3->m_Head;
    if ( m_Head != 0xFFFF )
    {
      m_pMemory = v3->m_Memory.m_pMemory;
      do
      {
        v6 = (unsigned __int16)m_Head;
        V_snprintf(pDest: v9, maxLen: 0x400u, pFormat: "%s \"%s\"", v9, m_pMemory[v6].m_Element);
        m_pMemory = v3->m_Memory.m_pMemory;
        m_Head = v3->m_Memory.m_pMemory[v6].m_Next;
      }
      while ( m_Head != 0xFFFF );
      v2 = v13;
    }
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3);
    engine->ClientCmd_Unrestricted(this: engine, a2: v9);
  }
  if ( v2 > 0 )
  {
    if ( pDest[v2 + 1023] == 10 )
      pDest[v2 + 1023] = 0;
    v7 = "say";
    if ( this->m_nMessageMode != 1 )
      v7 = "say_team";
    V_snprintf(pDest, maxLen: 0x400u, pFormat: "%s \"%s\"", v7, str);
    engine->ClientCmd_Unrestricted(this: engine, a2: pDest);
  }
  this->m_pChatInput->m_pInput->SetText_2(this: this->m_pChatInput->m_pInput, a2: &szFunFact);
  this->m_nMessageMode = 0;
  ConVar::SetValue(this: (ConVar *)&cl_chat_active.IConVar, value: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100F7DE0
// Name: public: virtual void CBaseHudChatEntry::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseHudChatEntry::OnKeyCodeTyped(CBaseHudChatEntry *this, ButtonCode_t code)
{
  CBaseHudChat *m_pHudChat; // ecx

  switch ( code )
  {
    case KEY_ENTER:
    case KEY_PAD_ENTER:
      m_pHudChat = this->m_pHudChat;
      if ( m_pHudChat != nullptr )
        CBaseHudChat::Send(this: m_pHudChat);
      break;
    case KEY_ESCAPE:
      break;
    case KEY_TAB:
      return;
    default:
      vgui::TextEntry::OnKeyCodeTyped(this, code);
      return;
  }
  if ( this->m_pHudChat != nullptr )
    this->m_pHudChat->StopMessageMode(this: this->m_pHudChat, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x103B7600
// Name: public: virtual int vgui::TextEntry::GetTextCursorPos(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::TextEntry::GetTextCursorPos(vgui::TreeView *this)
{
  return this->m_Font;
}
