// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/cs_hud_chat.cpp
// Functions: 28
// ============================================================

#include "game\client\cstrike15\cs_hud_chat.h"

//------------------------------------------------------------------------------
// Address: 0x10201A30
// Name: public: static char const __near * CHudChatLine::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CHudChatLine::GetPanelClassName()
{
  return "CHudChatLine";
}

//------------------------------------------------------------------------------
// Address: 0x10201A40
// Name: public: static char const __near * CHudChatInputLine::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CHudChatInputLine::GetPanelClassName()
{
  return "CHudChatInputLine";
}

//------------------------------------------------------------------------------
// Address: 0x10201A50
// Name: public: static char const __near * CHudChat::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CHudChat::GetPanelClassName()
{
  return "CHudChat";
}

//------------------------------------------------------------------------------
// Address: 0x10201A60
// Name: public: virtual void CHudChatLine::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudChatLine::ApplySchemeSettings(CHudChatLine *this, vgui::IScheme *pScheme)
{
  CBaseHudChatLine::ApplySchemeSettings(this, pScheme);
}

//------------------------------------------------------------------------------
// Address: 0x10201A70
// Name: public: virtual void CHudChat::Init(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CHudChat::Init(CHudChat *this)
{
  CBaseHudChat::Init(this);
}

//------------------------------------------------------------------------------
// Address: 0x10201A80
// Name: public: virtual int CHudChat::GetChatInputOffset(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHudChat::GetChatInputOffset(CHudChat *this)
{
  if ( this->m_pChatInput->IsVisible(this: this->m_pChatInput) )
    return this->m_iFontHeight;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10201AB0
// Name: public: virtual class Color CHudChat::GetClientColor(int)
// Source: json
//------------------------------------------------------------------------------
Color *__thiscall CHudChat::GetClientColor(CHudChat *this, Color *result, int clientIndex)
{
  Color *v3; // eax
  int v4; // eax
  bool v5; // zf

  if ( clientIndex != 0 )
  {
    if ( g_PR != nullptr )
    {
      v4 = g_PR->GetTeam(this: &g_PR->IGameResources, a2: clientIndex) - 2;
      if ( v4 != 0 )
      {
        v5 = v4 == 1;
        v3 = result;
        if ( v5 )
          *result = g_ColorBlue;
        else
          *result = g_ColorGrey;
      }
      else
      {
        *result = g_ColorRed;
        return result;
      }
    }
    else
    {
      *result = g_ColorYellow;
      return result;
    }
  }
  else
  {
    *result = g_ColorGreen;
    return result;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10201B30
// Name: public: virtual int CHudChat::GetFilterForString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHudChat::GetFilterForString(CHudChat *this, const char *pString)
{
  int FilterForString; // esi
  bool v3; // zf
  int result; // eax

  FilterForString = CBaseHudChat::GetFilterForString(this, pString);
  if ( FilterForString != 0 )
    return FilterForString;
  v3 = _V_stricmp(s1: pString, s2: "#CStrike_Name_Change") == 0;
  result = 2;
  if ( !v3 )
    return FilterForString;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10201B70
// Name: public: CHudChatInputLine::CHudChatInputLine(class CBaseHudChat __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CHudChatInputLine *__thiscall CHudChatInputLine::CHudChatInputLine(
        CHudChatInputLine *this,
        vgui::TextEntry_vtbl *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  CBaseHudChatInputLine::CBaseHudChatInputLine(this, parent, panelName);
  this->__vftable = (CHudChatInputLine_vtbl *)&CHudChatInputLine::`vftable';
  if ( `CHudChatInputLine::ChainToMap'::`2'::chained == 0 )
  {
    `CHudChatInputLine::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CHudChatInputLine");
    v4->pfnClassName = CHudChatInputLine::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseHudChatInputLine");
  }
  if ( `CHudChatInputLine::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CHudChatInputLine::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CHudChatInputLine");
    v5->pfnClassName = CHudChatInputLine::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CBaseHudChatInputLine");
  }
  if ( `CHudChatInputLine::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CHudChatInputLine::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CHudChatInputLine");
    v6->pfnClassName = CHudChatInputLine::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseHudChatInputLine");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10201C30
// Name: public: virtual struct vgui::PanelMessageMap __near * CHudChatInputLine::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CHudChatInputLine::GetMessageMap(CHudChatInputLine *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CHudChatInputLine::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CHudChatInputLine::GetMessageMap'::`2'::s_pMap;
  `CHudChatInputLine::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CHudChatInputLine");
  `CHudChatInputLine::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10201C60
// Name: public: virtual struct PanelAnimationMap __near * CHudChatInputLine::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CHudChatInputLine::GetAnimMap(CHudChatInputLine *this)
{
  return FindOrAddPanelAnimationMap(className: "CHudChatInputLine");
}

//------------------------------------------------------------------------------
// Address: 0x10201C70
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CHudChatInputLine::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CHudChatInputLine::GetKBMap(CHudChatInputLine *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CHudChatInputLine::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CHudChatInputLine::GetKBMap'::`2'::s_pMap;
  `CHudChatInputLine::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CHudChatInputLine");
  `CHudChatInputLine::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10201CA0
// Name: public: CHudChatLine::CHudChatLine(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CHudChatLine *__thiscall CHudChatLine::CHudChatLine(CHudChatLine *this, vgui::Panel *parent, const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  CBaseHudChatLine::CBaseHudChatLine(this, parent, panelName);
  this->__vftable = (CHudChatLine_vtbl *)&CHudChatLine::`vftable';
  if ( `CHudChatLine::ChainToMap'::`2'::chained == 0 )
  {
    `CHudChatLine::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CHudChatLine");
    v4->pfnClassName = CHudChatLine::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseHudChatLine");
  }
  if ( `CHudChatLine::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CHudChatLine::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CHudChatLine");
    v5->pfnClassName = CHudChatLine::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CBaseHudChatLine");
  }
  if ( `CHudChatLine::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CHudChatLine::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CHudChatLine");
    v6->pfnClassName = CHudChatLine::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseHudChatLine");
  }
  this->m_text = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10201D70
// Name: public: virtual struct vgui::PanelMessageMap __near * CHudChatLine::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CHudChatLine::GetMessageMap(CHudChatLine *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CHudChatLine::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CHudChatLine::GetMessageMap'::`2'::s_pMap;
  `CHudChatLine::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CHudChatLine");
  `CHudChatLine::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10201DA0
// Name: public: virtual struct PanelAnimationMap __near * CHudChatLine::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CHudChatLine::GetAnimMap(CHudChatLine *this)
{
  return FindOrAddPanelAnimationMap(className: "CHudChatLine");
}

//------------------------------------------------------------------------------
// Address: 0x10201DB0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CHudChatLine::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CHudChatLine::GetKBMap(CHudChatLine *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CHudChatLine::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CHudChatLine::GetKBMap'::`2'::s_pMap;
  `CHudChatLine::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CHudChatLine");
  `CHudChatLine::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10201E10
// Name: public: virtual void CHudChatInputLine::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudChatInputLine::ApplySchemeSettings(CHudChatInputLine *this, int pScheme)
{
  vgui::IScheme *v2; // edi
  unsigned int v4; // ebx
  CBaseHudChatEntry *m_pInput; // eax
  vgui::IScheme_vtbl *v6; // ebx
  Color *(__thiscall *GetColor)(vgui::IScheme *, Color *, const char *, Color); // edx
  _DWORD *v8; // eax
  _DWORD *v9; // eax
  char v10[4]; // [esp+Ch] [ebp-8h] BYREF
  CBaseHudChatEntry_vtbl *v11; // [esp+10h] [ebp-4h]

  v2 = (vgui::IScheme *)pScheme;
  CBaseHudChatInputLine::ApplySchemeSettings(this, pScheme);
  v4 = v2->GetFont(this: v2, a2: "ChatFont", a3: false);
  this->m_pPrompt->SetFont(this: this->m_pPrompt, a2: v4);
  this->m_pInput->SetFont(this: this->m_pInput, a2: v4);
  m_pInput = this->m_pInput;
  v6 = v2->__vftable;
  pScheme = -1;
  GetColor = v6->GetColor;
  v11 = m_pInput->__vftable;
  v8 = (_DWORD *)((int (__thiscall *)(vgui::IScheme *, int *, const char *, int))GetColor)(
                   a1: v2,
                   a2: &pScheme,
                   a3: "Panel.FgColor",
                   a4: -1);
  v9 = (_DWORD *)((int (__thiscall *)(vgui::IScheme *, char *, const char *, _DWORD))v6->GetColor)(
                   a1: v2,
                   a2: v10,
                   a3: "Chat.TypingText",
                   a4: *v8);
  ((void (__thiscall *)(CBaseHudChatEntry *, _DWORD))v11->SetFgColor)(a1: this->m_pInput, a2: *v9);
}

//------------------------------------------------------------------------------
// Address: 0x10201EB0
// Name: public: CHudChat::CHudChat(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CHudChat *__thiscall CHudChat::CHudChat(CHudChat *this, const char *pElementName)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi

  CBaseHudChat::CBaseHudChat(this, pElementName);
  this->CBaseHudChat::CHudElement::CGameEventListener::IGameEventListener2::__vftable = (CHudChat_vtbl *)&CHudChat::`vftable'{for `CHudElement'};
  this->CBaseHudChat::vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (vgui::EditablePanel_vtbl *)&CHudChat::`vftable'{for `vgui::EditablePanel'};
  if ( `CHudChat::ChainToMap'::`2'::chained == 0 )
  {
    `CHudChat::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CHudChat");
    v3->pfnClassName = CHudChat::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseHudChat");
  }
  if ( `CHudChat::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CHudChat::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CHudChat");
    v4->pfnClassName = CHudChat::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "CBaseHudChat");
  }
  if ( `CHudChat::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CHudChat::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CHudChat");
    v5->pfnClassName = CHudChat::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseHudChat");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10201F80
// Name: public: virtual struct vgui::PanelMessageMap __near * CHudChat::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CHudChat::GetMessageMap(CHudChat *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CHudChat::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CHudChat::GetMessageMap'::`2'::s_pMap;
  `CHudChat::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CHudChat");
  `CHudChat::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10201FB0
// Name: public: virtual struct PanelAnimationMap __near * CHudChat::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CHudChat::GetAnimMap(CHudChat *this)
{
  return FindOrAddPanelAnimationMap(className: "CHudChat");
}

//------------------------------------------------------------------------------
// Address: 0x10201FC0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CHudChat::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CHudChat::GetKBMap(CHudChat *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CHudChat::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CHudChat::GetKBMap'::`2'::s_pMap;
  `CHudChat::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CHudChat");
  `CHudChat::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10202020
// Name: public: virtual void CHudChat::CreateChatInputLine(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudChat::CreateChatInputLine(CHudChat *this)
{
  CHudChatInputLine *v2; // eax
  CHudChatInputLine *v3; // eax

  v2 = (CHudChatInputLine *)MemAlloc_Alloc(nSize: 0x158u);
  if ( v2 != nullptr )
    v3 = CHudChatInputLine::CHudChatInputLine(
           this: v2,
           parent: (vgui::TextEntry_vtbl *)this,
           panelName: "ChatInputLine");
  else
    v3 = nullptr;
  this->m_pChatInput = v3;
  v3->SetVisible(this: v3, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x10202060
// Name: public: virtual void CHudChat::CreateChatLines(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudChat::CreateChatLines(CHudChat *this)
{
  CHudChatLine *v2; // eax
  CHudChatLine *v3; // eax

  v2 = (CHudChatLine *)MemAlloc_Alloc(nSize: 0x260u);
  if ( v2 != nullptr )
  {
    if ( this != nullptr )
      v3 = CHudChatLine::CHudChatLine(this: v2, parent: &this->vgui::EditablePanel, panelName: "ChatLine1");
    else
      v3 = CHudChatLine::CHudChatLine(this: v2, parent: nullptr, panelName: "ChatLine1");
  }
  else
  {
    v3 = nullptr;
  }
  this->m_ChatLine = v3;
  v3->SetVisible(this: v3, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x102020C0
// Name: public: void CHudChat::MsgFunc_RadioText(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudChat::MsgFunc_RadioText(CHudChat *this, bf_read *msg)
{
  int m_nBitsAvail; // eax
  int v3; // eax
  const unsigned int *m_pDataIn; // eax
  const unsigned int *m_pBufferEnd; // ecx
  const unsigned int *v6; // edx
  int v7; // ecx
  const unsigned int *v8; // eax
  int v9; // ecx
  unsigned int m_nInBufWord; // eax
  int v11; // edi
  int v12; // ecx
  const unsigned int *v13; // eax
  const unsigned int *v14; // ecx
  const unsigned int *v15; // edx
  unsigned int v16; // edi
  int v17; // eax
  const unsigned int *v18; // ecx
  unsigned int v19; // edx
  unsigned int v20; // ebx
  wchar_t *LocalizedString; // ebx
  vgui::ILocalize_vtbl *v22; // esi
  wchar_t *v23; // eax
  char ansiString[512]; // [esp+20h] [ebp-824h] BYREF
  wchar_t szBuf[6][128]; // [esp+220h] [ebp-624h] BYREF
  CLocalPlayerFilter filter; // [esp+820h] [ebp-24h] BYREF
  CHudChat *v27; // [esp+840h] [ebp-4h]

  m_nBitsAvail = msg->m_nBitsAvail;
  v27 = this;
  if ( m_nBitsAvail >= 8 )
  {
    v3 = m_nBitsAvail - 8;
    msg->m_nBitsAvail = v3;
    if ( v3 != 0 )
    {
      msg->m_nInBufWord >>= 8;
    }
    else
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
    }
    goto LABEL_17;
  }
  v6 = msg->m_pBufferEnd;
  v7 = 8 - m_nBitsAvail;
  v8 = msg->m_pDataIn;
  if ( v8 == v6 )
  {
    msg->m_nBitsAvail = 1;
    msg->m_nInBufWord = 0;
    msg->m_bOverflow = true;
  }
  else
  {
    if ( v8 > v6 )
    {
      msg->m_bOverflow = true;
      msg->m_nInBufWord = 0;
      goto LABEL_15;
    }
    msg->m_nInBufWord = *v8;
  }
  msg->m_pDataIn = v8 + 1;
LABEL_15:
  if ( !msg->m_bOverflow )
  {
    msg->m_nInBufWord >>= v7;
    msg->m_nBitsAvail = 32 - v7;
  }
LABEL_17:
  v9 = msg->m_nBitsAvail;
  if ( v9 >= 8 )
  {
    m_nInBufWord = msg->m_nInBufWord;
    v11 = (unsigned __int8)m_nInBufWord;
    v12 = v9 - 8;
    msg->m_nBitsAvail = v12;
    if ( v12 != 0 )
    {
      msg->m_nInBufWord = m_nInBufWord >> 8;
    }
    else
    {
      v13 = msg->m_pDataIn;
      v14 = msg->m_pBufferEnd;
      msg->m_nBitsAvail = 32;
      if ( v13 == v14 )
      {
        msg->m_nBitsAvail = 1;
        msg->m_nInBufWord = 0;
        msg->m_pDataIn = v13 + 1;
      }
      else if ( v13 <= v14 )
      {
        msg->m_nInBufWord = *v13;
        msg->m_pDataIn = v13 + 1;
      }
      else
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
      }
    }
    goto LABEL_34;
  }
  v15 = msg->m_pBufferEnd;
  v16 = msg->m_nInBufWord;
  v17 = 8 - v9;
  v18 = msg->m_pDataIn;
  if ( v18 == v15 )
  {
    msg->m_nBitsAvail = 1;
    msg->m_nInBufWord = 0;
    msg->m_bOverflow = true;
  }
  else
  {
    if ( v18 > v15 )
    {
      msg->m_bOverflow = true;
      msg->m_nInBufWord = 0;
      goto LABEL_31;
    }
    msg->m_nInBufWord = *v18;
  }
  msg->m_pDataIn = v18 + 1;
LABEL_31:
  if ( msg->m_bOverflow )
  {
    v11 = 0;
  }
  else
  {
    v19 = msg->m_nInBufWord;
    v20 = (v19 & CBitBuffer::s_nMaskTable[v17]) << msg->m_nBitsAvail;
    msg->m_nBitsAvail = 32 - v17;
    v11 = v20 | v16;
    msg->m_nInBufWord = v19 >> v17;
  }
LABEL_34:
  LocalizedString = ReadLocalizedString(
                      a1: (int)msg,
                      msg,
                      pOut: szBuf[0],
                      outSize: 0x100u,
                      bStripNewline: false,
                      originalString: nullptr,
                      originalSize: 0);
  ReadChatTextString(msg, pOut: szBuf[1], outSize: 256);
  ReadLocalizedString(
    a1: (int)msg,
    msg,
    pOut: szBuf[2],
    outSize: 0x100u,
    bStripNewline: true,
    originalString: nullptr,
    originalSize: 0);
  ReadLocalizedString(
    a1: (int)msg,
    msg,
    pOut: szBuf[3],
    outSize: 0x100u,
    bStripNewline: true,
    originalString: nullptr,
    originalSize: 0);
  ReadLocalizedString(
    a1: (int)msg,
    msg,
    pOut: szBuf[4],
    outSize: 0x100u,
    bStripNewline: true,
    originalString: nullptr,
    originalSize: 0);
  g_pVGuiLocalize->ConstructString_3(
    this: g_pVGuiLocalize,
    a2: szBuf[5],
    a3: 256,
    a4: LocalizedString,
    a5: 4,
    szBuf[1],
    szBuf[2],
    szBuf[3],
    szBuf[4]);
  v22 = g_pVGuiLocalize->__vftable;
  v23 = ConvertCRtoNL(str: szBuf[5]);
  v22->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: v23, a3: ansiString, a4: 512);
  v27->ChatPrintf(this: v27, a2: v11, a3: 16, a4: "%s", ansiString);
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
// Address: 0x10202390
// Name: public: virtual void CHudChat::MsgFunc_SayText2(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudChat::MsgFunc_SayText2(CHudChat *this, bf_read *msg)
{
  int m_nBitsAvail; // ecx
  unsigned int v3; // edx
  int v4; // ebx
  unsigned int v5; // edx
  const unsigned int *v6; // eax
  const unsigned int *v7; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int m_nInBufWord; // ebx
  int v10; // eax
  const unsigned int *m_pDataIn; // ecx
  unsigned int v12; // edx
  unsigned int v13; // edi
  int v14; // ecx
  unsigned int v15; // eax
  int v16; // ebx
  int v17; // ecx
  const unsigned int *v18; // eax
  const unsigned int *v19; // ecx
  const unsigned int *v20; // edx
  unsigned int v21; // ebx
  int v22; // eax
  const unsigned int *v23; // ecx
  unsigned int v24; // edx
  unsigned int v25; // edi
  wchar_t *LocalizedString; // edi
  vgui::ILocalize_vtbl *v27; // esi
  wchar_t *v28; // eax
  int v29; // ebx
  IGameResources_vtbl *v30; // esi
  IGameResources *v31; // edi
  int LocalPlayerIndex; // eax
  int v33; // esi
  CHudChat *v34; // esi
  int (__thiscall *GetFilterFlags)(struct CHudChat *); // edx
  const char *v36; // eax
  CHudChat *v37; // edi
  CHudChat_vtbl *v38; // esi
  int v39; // eax
  wchar_t szBuf[6][256]; // [esp+20h] [ebp-F2Ch] BYREF
  char untranslated_msg_text[256]; // [esp+C20h] [ebp-32Ch] BYREF
  char ansiString[512]; // [esp+D20h] [ebp-22Ch] BYREF
  CLocalPlayerFilter filter; // [esp+F20h] [ebp-2Ch] BYREF
  int iFilter; // [esp+F40h] [ebp-Ch]
  CHudChat *v45; // [esp+F44h] [ebp-8h]
  int v46; // [esp+F48h] [ebp-4h]
  bool playChatSound_3; // [esp+F57h] [ebp+Bh]

  v45 = this;
  if ( g_PR == nullptr )
    return;
  m_nBitsAvail = msg->m_nBitsAvail;
  if ( m_nBitsAvail < 8 )
  {
    m_pBufferEnd = msg->m_pBufferEnd;
    m_nInBufWord = msg->m_nInBufWord;
    v10 = 8 - m_nBitsAvail;
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
          v46 = 0;
          goto LABEL_21;
        }
        v12 = msg->m_nInBufWord;
        v13 = (v12 & CBitBuffer::s_nMaskTable[v10]) << msg->m_nBitsAvail;
        msg->m_nBitsAvail = 32 - v10;
        v4 = v13 | m_nInBufWord;
        v5 = v12 >> v10;
        goto LABEL_19;
      }
      msg->m_nInBufWord = *m_pDataIn;
    }
    msg->m_pDataIn = m_pDataIn + 1;
    goto LABEL_16;
  }
  v3 = msg->m_nInBufWord;
  v4 = (unsigned __int8)v3;
  msg->m_nBitsAvail = m_nBitsAvail - 8;
  if ( m_nBitsAvail == 8 )
  {
    v6 = msg->m_pDataIn;
    v7 = msg->m_pBufferEnd;
    msg->m_nBitsAvail = 32;
    if ( v6 == v7 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_pDataIn = v6 + 1;
    }
    else if ( v6 <= v7 )
    {
      msg->m_nInBufWord = *v6;
      msg->m_pDataIn = v6 + 1;
    }
    else
    {
      msg->m_bOverflow = true;
      msg->m_nInBufWord = 0;
    }
    goto LABEL_20;
  }
  v5 = v3 >> 8;
LABEL_19:
  msg->m_nInBufWord = v5;
LABEL_20:
  v46 = v4;
LABEL_21:
  v14 = msg->m_nBitsAvail;
  if ( v14 >= 8 )
  {
    v15 = msg->m_nInBufWord;
    v16 = (unsigned __int8)v15;
    v17 = v14 - 8;
    msg->m_nBitsAvail = v17;
    if ( v17 != 0 )
    {
      msg->m_nInBufWord = v15 >> 8;
    }
    else
    {
      v18 = msg->m_pDataIn;
      v19 = msg->m_pBufferEnd;
      msg->m_nBitsAvail = 32;
      if ( v18 == v19 )
      {
        msg->m_nBitsAvail = 1;
        msg->m_nInBufWord = 0;
        msg->m_pDataIn = v18 + 1;
      }
      else if ( v18 <= v19 )
      {
        msg->m_nInBufWord = *v18;
        msg->m_pDataIn = v18 + 1;
      }
      else
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
      }
    }
    goto LABEL_38;
  }
  v20 = msg->m_pBufferEnd;
  v21 = msg->m_nInBufWord;
  v22 = 8 - v14;
  v23 = msg->m_pDataIn;
  if ( v23 == v20 )
  {
    msg->m_nBitsAvail = 1;
    msg->m_nInBufWord = 0;
    msg->m_bOverflow = true;
  }
  else
  {
    if ( v23 > v20 )
    {
      msg->m_bOverflow = true;
      msg->m_nInBufWord = 0;
      goto LABEL_35;
    }
    msg->m_nInBufWord = *v23;
  }
  msg->m_pDataIn = v23 + 1;
LABEL_35:
  if ( msg->m_bOverflow )
  {
    v16 = 0;
  }
  else
  {
    v24 = msg->m_nInBufWord;
    v25 = (v24 & CBitBuffer::s_nMaskTable[v22]) << msg->m_nBitsAvail;
    msg->m_nBitsAvail = 32 - v22;
    v16 = v25 | v21;
    msg->m_nInBufWord = v24 >> v22;
  }
LABEL_38:
  LocalizedString = ReadLocalizedString(
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
  g_pVGuiLocalize->ConstructString_3(
    this: g_pVGuiLocalize,
    a2: szBuf[5],
    a3: 512,
    a4: LocalizedString,
    a5: 4,
    szBuf[1],
    szBuf[2],
    szBuf[3],
    szBuf[4]);
  v27 = g_pVGuiLocalize->__vftable;
  v28 = ConvertCRtoNL(str: szBuf[5]);
  v27->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: v28, a3: ansiString, a4: 512);
  if ( v16 != 0 )
  {
    v29 = v46;
    iFilter = 0;
    playChatSound_3 = true;
    if ( v46 <= 0
      || g_PR == nullptr
      || (v30 = g_PR->IGameResources::__vftable,
          v31 = &g_PR->IGameResources,
          LocalPlayerIndex = GetLocalPlayerIndex(),
          v33 = v30->GetTeam(this: &g_PR->IGameResources, a2: LocalPlayerIndex),
          v31->GetTeam(this: v31, a2: v29) == v33) )
    {
      v34 = v45;
    }
    else
    {
      v34 = v45;
      GetFilterFlags = v45->GetFilterFlags;
      iFilter = 4;
      playChatSound_3 = (GetFilterFlags(this: v45) & 4) != 0;
    }
    v34->ChatPrintf(this: v34, a2: v29, a3: iFilter, a4: "%s", ansiString);
    v36 = RemoveColorMarkup(str: ansiString);
    _Msg(a1: "%s\n", v36);
    if ( playChatSound_3 )
    {
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
  }
  else
  {
    v37 = v45;
    v38 = v45->CBaseHudChat::CHudElement::CGameEventListener::IGameEventListener2::__vftable;
    v39 = v45->GetFilterForString(this: v45, a2: untranslated_msg_text);
    ((void (__cdecl *)(CHudChat *, int, int))v38->ChatPrintf)(a1: v37, a2: v46, a3: v39);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10202760
// Name: public: virtual class Color CHudChat::GetTextColorForClient(enum TextColor,int)
// Source: json
//------------------------------------------------------------------------------
Color *__thiscall CHudChat::GetTextColorForClient(CHudChat *this, Color *result, TextColor colorNum, int clientIndex)
{
  Color v5; // ecx
  vgui::ISchemeManager *v6; // esi
  vgui::ISchemeManager_vtbl *v7; // edi
  int v8; // eax
  vgui::IScheme *v9; // eax
  vgui::IScheme *v10; // esi
  vgui::IScheme_vtbl *v11; // edi
  Color *v12; // eax
  Color *v13; // eax
  char v15[4]; // [esp+Ch] [ebp-4h] BYREF

  switch ( colorNum )
  {
    case COLOR_PLAYERNAME:
      v13 = this->GetClientColor(this, result: v15, a3: clientIndex);
      goto LABEL_10;
    case COLOR_LOCATION:
      v5 = g_ColorDarkGreen;
      goto LABEL_11;
    case COLOR_ACHIEVEMENT:
      v6 = g_pVGuiSchemeManager;
      v7 = g_pVGuiSchemeManager->__vftable;
      v8 = ((int (__stdcall *)(const char *))g_pVGuiSchemeManager->GetScheme)(a1: "SourceScheme");
      v9 = v7->GetIScheme(this: v6, a2: v8);
      v10 = v9;
      if ( v9 == nullptr )
      {
        v5 = g_ColorGrey;
        goto LABEL_11;
      }
      v11 = v9->__vftable;
      v12 = this->GetBgColor(this: &this->vgui::EditablePanel, result: &colorNum);
      v13 = v11->GetColor(this: v10, result: (Color *)&clientIndex, a3: "SteamLightGreen", a4: *v12);
LABEL_10:
      v5 = *v13;
      goto LABEL_11;
    default:
      break;
  }
  v5 = g_ColorYellow;
LABEL_11:
  *(_WORD *)result->_color = *(_WORD *)v5._color;
  result->_color[2] = v5._color[2];
  result->_color[3] = -1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10202820
// Name: Create_CHudChat
// Source: json
//------------------------------------------------------------------------------
CHudChat *__cdecl Create_CHudChat()
{
  unsigned __int8 *v0; // esi

  v0 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 492);
  memset(dst: v0, value: 0, count: 0x1ECu);
  if ( v0 != nullptr )
    return CHudChat::CHudChat(this: (CHudChat *)v0, pElementName: "CHudChat");
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10202860
// Name: public: void CHudChat::MsgFunc_RawAudio(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudChat::MsgFunc_RawAudio(CHudChat *this, bf_read *msg)
{
  int m_nBitsAvail; // ecx
  unsigned int v4; // edx
  int v5; // esi
  int v6; // ecx
  const unsigned int *v7; // ecx
  const unsigned int *v8; // edx
  unsigned int v9; // edx
  const unsigned int *m_pBufferEnd; // esi
  unsigned int m_nInBufWord; // edi
  int v12; // edx
  const unsigned int *m_pDataIn; // ecx
  unsigned int v14; // esi
  unsigned int v15; // ebx
  int v16; // ecx
  unsigned int v17; // edx
  int v18; // esi
  int v19; // ecx
  int v20; // edi
  const unsigned int *v21; // ecx
  const unsigned int *v22; // edx
  unsigned int v23; // edx
  const unsigned int *v24; // esi
  unsigned int v25; // edi
  int v26; // edx
  const unsigned int *v27; // ecx
  unsigned int v28; // esi
  unsigned int v29; // ebx
  int v30; // esi
  unsigned int v31; // ecx
  const unsigned int *v32; // edx
  const unsigned int *v33; // esi
  const unsigned int *v34; // ecx
  int v35; // edx
  const unsigned int *v36; // esi
  unsigned int v37; // esi
  unsigned int v38; // edi
  CRadioStatus *v39; // eax
  char szString[2048]; // [esp+10h] [ebp-874h] BYREF
  CLocalPlayerFilter filter; // [esp+810h] [ebp-74h] BYREF
  EmitSound_t ep; // [esp+830h] [ebp-54h] BYREF
  unsigned int v43; // [esp+878h] [ebp-Ch]
  int v44; // [esp+87Ch] [ebp-8h]
  int v45; // [esp+880h] [ebp-4h]
  float msga; // [esp+88Ch] [ebp+8h]

  m_nBitsAvail = msg->m_nBitsAvail;
  if ( m_nBitsAvail < 8 )
  {
    m_pBufferEnd = msg->m_pBufferEnd;
    m_nInBufWord = msg->m_nInBufWord;
    v12 = 8 - m_nBitsAvail;
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
        goto LABEL_16;
      }
      msg->m_nInBufWord = *m_pDataIn;
    }
    msg->m_pDataIn = m_pDataIn + 1;
LABEL_16:
    if ( msg->m_bOverflow )
    {
      v44 = 0;
    }
    else
    {
      v14 = msg->m_nInBufWord;
      v15 = (v14 & CBitBuffer::s_nMaskTable[v12]) << msg->m_nBitsAvail;
      msg->m_nBitsAvail = 32 - v12;
      v44 = v15 | m_nInBufWord;
      msg->m_nInBufWord = v14 >> v12;
    }
    goto LABEL_19;
  }
  v4 = msg->m_nInBufWord;
  v5 = (unsigned __int8)v4;
  v6 = m_nBitsAvail - 8;
  msg->m_nBitsAvail = v6;
  if ( v6 != 0 )
  {
    msg->m_nInBufWord = v4 >> 8;
    v44 = (unsigned __int8)v4;
  }
  else
  {
    v7 = msg->m_pDataIn;
    v8 = msg->m_pBufferEnd;
    msg->m_nBitsAvail = 32;
    if ( v7 == v8 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_pDataIn = v7 + 1;
      v44 = v5;
    }
    else
    {
      if ( v7 <= v8 )
      {
        v9 = *v7;
        msg->m_pDataIn = v7 + 1;
        msg->m_nInBufWord = v9;
      }
      else
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
      }
      v44 = v5;
    }
  }
LABEL_19:
  v16 = msg->m_nBitsAvail;
  if ( v16 < 8 )
  {
    v24 = msg->m_pBufferEnd;
    v25 = msg->m_nInBufWord;
    v26 = 8 - v16;
    v27 = msg->m_pDataIn;
    if ( v27 == v24 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( v27 > v24 )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
        goto LABEL_34;
      }
      msg->m_nInBufWord = *v27;
    }
    msg->m_pDataIn = v27 + 1;
LABEL_34:
    if ( msg->m_bOverflow )
    {
      v20 = 0;
    }
    else
    {
      v28 = msg->m_nInBufWord;
      v29 = (v28 & CBitBuffer::s_nMaskTable[v26]) << msg->m_nBitsAvail;
      msg->m_nBitsAvail = 32 - v26;
      v20 = v29 | v25;
      msg->m_nInBufWord = v28 >> v26;
    }
    goto LABEL_37;
  }
  v17 = msg->m_nInBufWord;
  v18 = (unsigned __int8)v17;
  v19 = v16 - 8;
  msg->m_nBitsAvail = v19;
  if ( v19 != 0 )
  {
    msg->m_nInBufWord = v17 >> 8;
    v20 = (unsigned __int8)v17;
  }
  else
  {
    v21 = msg->m_pDataIn;
    v22 = msg->m_pBufferEnd;
    msg->m_nBitsAvail = 32;
    if ( v21 == v22 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_pDataIn = v21 + 1;
      v20 = v18;
    }
    else
    {
      if ( v21 <= v22 )
      {
        v23 = *v21;
        msg->m_pDataIn = v21 + 1;
        msg->m_nInBufWord = v23;
      }
      else
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
      }
      v20 = v18;
    }
  }
LABEL_37:
  v30 = msg->m_nBitsAvail;
  v45 = v20;
  if ( v30 >= 32 )
  {
    v31 = msg->m_nInBufWord;
    msg->m_nBitsAvail = v30 - 32;
    if ( v30 == 32 )
    {
      v32 = msg->m_pDataIn;
      v33 = msg->m_pBufferEnd;
      msg->m_nBitsAvail = 32;
      if ( v32 == v33 )
      {
        msg->m_nBitsAvail = 1;
        msg->m_nInBufWord = 0;
        msg->m_pDataIn = v32 + 1;
        msga = *(float *)&v31;
      }
      else
      {
        if ( v32 <= v33 )
        {
          msg->m_nInBufWord = *v32;
          msg->m_pDataIn = v32 + 1;
        }
        else
        {
          msg->m_bOverflow = true;
          msg->m_nInBufWord = 0;
        }
        msga = *(float *)&v31;
      }
    }
    else
    {
      msg->m_nInBufWord = 0;
      msga = *(float *)&v31;
    }
    goto LABEL_55;
  }
  v34 = msg->m_pDataIn;
  v43 = msg->m_nInBufWord;
  v35 = 32 - v30;
  v36 = msg->m_pBufferEnd;
  if ( v34 == v36 )
  {
    msg->m_nBitsAvail = 1;
    msg->m_nInBufWord = 0;
    msg->m_bOverflow = true;
  }
  else
  {
    if ( v34 > v36 )
    {
      msg->m_bOverflow = true;
      msg->m_nInBufWord = 0;
      goto LABEL_52;
    }
    msg->m_nInBufWord = *v34;
  }
  msg->m_pDataIn = v34 + 1;
LABEL_52:
  if ( msg->m_bOverflow )
  {
    msga = 0.0;
  }
  else
  {
    v37 = msg->m_nInBufWord;
    v38 = (v37 & CBitBuffer::s_nMaskTable[v35]) << msg->m_nBitsAvail;
    msg->m_nBitsAvail = 32 - v35;
    LODWORD(msga) = v38 | v43;
    v20 = v45;
    msg->m_nInBufWord = v37 >> v35;
  }
LABEL_55:
  CBitRead::ReadString(this: msg, pStr: szString, maxLen: 2048, bLine: false, pOutNumChars: nullptr);
  ep.m_pSoundName = szString;
  ep.m_nFlags = 0;
  memset(&ep.m_pOrigin, 0, 12);
  *(_WORD *)&ep.m_bEmitCloseCaption = 1;
  ep.m_bWarnOnDirectWaveReference = false;
  ep.m_nSpeakerEntity = -1;
  memset(&ep.m_UtlVecSoundOrigin, 0, sizeof(ep.m_UtlVecSoundOrigin));
  ep.m_hSoundScriptHandle = -1;
  ep.m_nSoundEntryVersion = 1;
  ep.m_nChannel = 2;
  ep.m_flVolume = 1.0;
  ep.m_SoundLevel = SNDLVL_NORM;
  ep.m_nPitch = v44;
  CLocalPlayerFilter::CLocalPlayerFilter(this: &filter);
  C_BaseEntity::EmitSound(&filter, iEntIndex: -1, params: &ep);
  if ( msga > 0.0
    && CClientEntityList::GetBaseEntity(this: (CClientEntityList *)cl_entitylist.m_Index, entnum: v20) != nullptr )
  {
    v39 = RadioManager();
    CRadioStatus::UpdateVoiceStatus(this: v39, entindex: v20, duration: msga);
  }
  C_RecipientFilter::~C_RecipientFilter(this: &filter);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&ep.m_UtlVecSoundOrigin);
}
