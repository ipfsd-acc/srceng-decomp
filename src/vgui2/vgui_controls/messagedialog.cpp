// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/vgui_controls/messagedialog.cpp
// Functions: 14
// ============================================================

#include "vgui2\vgui_controls\messagedialog.h"

//------------------------------------------------------------------------------
// Address: 0x103CC610
// Name: public: static char const __near * CMessageDialog::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CMessageDialog::GetPanelClassName()
{
  return "CMessageDialog";
}

//------------------------------------------------------------------------------
// Address: 0x103CC620
// Name: public: virtual CMessageDialog::~CMessageDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMessageDialog::~CMessageDialog(CMessageDialog *this)
{
  int m_ButtonPressed; // eax
  vgui::Label **p_pText; // edi
  void **m_pCommands; // esi
  int v5; // ecx
  vgui::Label *m_pTitle; // ecx
  vgui::Label *m_pMsg; // ecx
  vgui::ImagePanel *m_pBackground; // ecx
  int i; // [esp+4h] [ebp-4h]

  m_ButtonPressed = this->m_ButtonPressed;
  this->__vftable = (CMessageDialog_vtbl *)&CMessageDialog::`vftable';
  if ( m_ButtonPressed == -1 || (this->m_nType & 0x200) == 0 )
  {
    if ( (this->m_nType & 0x800) != 0 )
      this->m_pCreator->OnCommand(this: this->m_pCreator, a2: this->m_pCommands[1]);
  }
  else
  {
    this->m_pCreator->OnCommand(this: this->m_pCreator, a2: this->m_pCommands[m_ButtonPressed]);
  }
  p_pText = &this->m_Buttons[0].pText;
  m_pCommands = (void **)this->m_pCommands;
  for ( i = 2; i != 0; --i )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *m_pCommands);
    *m_pCommands = nullptr;
    v5 = (int)*(p_pText - 1);
    if ( v5 != 0 )
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v5 + 128))(a1: v5, a2: 1);
    if ( *p_pText != nullptr )
      ((void (__thiscall *)(vgui::Label *, int))(*p_pText)->dtr_Panel)(a1: *p_pText, a2: 1);
    ++m_pCommands;
    p_pText += 4;
  }
  m_pTitle = this->m_pTitle;
  if ( m_pTitle != nullptr )
    ((void (__thiscall *)(vgui::Label *, int))m_pTitle->dtr_Panel)(a1: m_pTitle, a2: 1);
  m_pMsg = this->m_pMsg;
  this->m_pTitle = nullptr;
  if ( m_pMsg != nullptr )
    ((void (__thiscall *)(vgui::Label *, int))m_pMsg->dtr_Panel)(a1: m_pMsg, a2: 1);
  m_pBackground = this->m_pBackground;
  this->m_pMsg = nullptr;
  if ( m_pBackground != nullptr )
    ((void (__thiscall *)(vgui::ImagePanel *, int))m_pBackground->dtr_Panel)(a1: m_pBackground, a2: 1);
  this->m_pBackground = nullptr;
  vgui::Frame::~Frame(this);
}

//------------------------------------------------------------------------------
// Address: 0x103CC750
// Name: public: void CMessageDialog::SetControlSettingsKeys(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMessageDialog::SetControlSettingsKeys(CMessageDialog *this, KeyValues *pKeys)
{
  this->m_pControlSettings = pKeys;
}

//------------------------------------------------------------------------------
// Address: 0x103CC760
// Name: public: unsigned int CMessageDialog::GetType(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CMessageDialog::GetType(CMessageDialog *this)
{
  return this->m_nType;
}

//------------------------------------------------------------------------------
// Address: 0x103CC770
// Name: private: void CMessageDialog::DoCommand(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMessageDialog::DoCommand(CMessageDialog *this, int button)
{
  unsigned int m_nType; // ecx

  if ( button != -1 )
  {
    m_nType = this->m_nType;
    if ( (m_nType & 0x800) == 0 && this->m_pCommands[button] != nullptr )
    {
      this->m_ButtonPressed = button;
      if ( (m_nType & 0x200) == 0 )
        this->m_pCreator->OnCommand(this: this->m_pCreator, a2: this->m_pCommands[button]);
      this->m_pCreator->OnCommand(this: this->m_pCreator, a2: "ReleaseModalWindow");
      this->Close(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103CC7F0
// Name: public: virtual void CMessageDialog::OnKeyCodePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMessageDialog::OnKeyCodePressed(CMessageDialog *this, ButtonCode_t code)
{
  __int32 v3; // eax

  if ( this->m_ButtonPressed == -1 && vgui::Panel::GetAlpha(this) == 255 )
  {
    v3 = GetBaseButtonCode(code) - 114;
    if ( v3 != 0 )
    {
      if ( v3 == 1 )
        CMessageDialog::DoCommand(this, button: 0);
    }
    else
    {
      CMessageDialog::DoCommand(this, button: 1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103CC840
// Name: public: virtual void CMessageDialog::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMessageDialog::PaintBackground(CMessageDialog *this)
{
  unsigned __int8 Alpha; // al
  void (__thiscall *DrawBox)(vgui::Panel *, int, int, int, int, Color, float, bool); // edx
  int v4; // ecx
  int v5; // esi
  void (__thiscall *DrawSetColor)(vgui::ISurface *, Color); // edx
  int titleX; // [esp+28h] [ebp-20h] BYREF
  int titleWide; // [esp+2Ch] [ebp-1Ch] BYREF
  int titleY; // [esp+30h] [ebp-18h] BYREF
  int titleTall; // [esp+34h] [ebp-14h] BYREF
  int wide; // [esp+38h] [ebp-10h] BYREF
  int tall; // [esp+3Ch] [ebp-Ch] BYREF
  Color col; // [esp+40h] [ebp-8h] BYREF
  Color darkColor; // [esp+44h] [ebp-4h]

  vgui::Panel::GetSize(this, &wide, &tall);
  if ( (this->m_nType & 0x100) != 0 )
  {
    this->GetBgColor(this, result: &col);
    ((void (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))this->DrawBox)(
      a1: this,
      a2: 0,
      a3: 0,
      a4: wide,
      a5: tall,
      a6: col,
      a7: 1065353216,
      a8: 0);
    vgui::Panel::GetBounds(this: this->m_pTitle, x: &titleX, y: &titleY, wide: &titleWide, tall: &titleTall);
    v5 = titleTall + titleY;
    darkColor = (Color)(unsigned __int8)(int)(float)((float)col._color[0] * 0.69999999);
    darkColor._color[1] = (int)(float)((float)col._color[1] * 0.69999999);
    darkColor._color[3] = col._color[3];
    DrawSetColor = g_pVGuiSurface->DrawSetColor;
    darkColor._color[2] = (int)(float)((float)col._color[2] * 0.69999999);
    ((void (__thiscall *)(_DWORD, _DWORD))DrawSetColor)(a1: g_pVGuiSurface, a2: darkColor);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 8, a3: v5, a4: wide - 8, a5: tall - 8);
  }
  else
  {
    Alpha = vgui::Panel::GetAlpha(this);
    DrawBox = this->DrawBox;
    v4 = tall;
    this->m_clrNotSimpleBG._color[3] = Alpha;
    this->m_clrNotSimpleBGBlack._color[3] = Alpha;
    ((void (__thiscall *)(CMessageDialog *, _DWORD, _DWORD, int, int, _DWORD, int, _DWORD))DrawBox)(
      a1: this,
      a2: 0,
      a3: 0,
      a4: wide,
      a5: v4,
      a6: *(_DWORD *)&this->m_clrNotSimpleBGBlack,
      a7: 1065353216,
      a8: 0);
    ((void (__thiscall *)(CMessageDialog *, _DWORD, _DWORD, int, int, _DWORD, int, _DWORD))this->DrawBox)(
      a1: this,
      a2: 0,
      a3: 0,
      a4: wide,
      a5: tall - this->m_FooterTall,
      a6: *(_DWORD *)&this->m_clrNotSimpleBG,
      a7: 1065353216,
      a8: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103CC9D0
// Name: public: virtual struct vgui::PanelMessageMap __near * CMessageDialog::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CMessageDialog::GetMessageMap(CMessageDialog *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CMessageDialog::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CMessageDialog::GetMessageMap'::`2'::s_pMap;
  `CMessageDialog::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CMessageDialog");
  `CMessageDialog::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103CCA00
// Name: public: virtual struct PanelAnimationMap __near * CMessageDialog::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CMessageDialog::GetAnimMap(CMessageDialog *this)
{
  return FindOrAddPanelAnimationMap(className: "CMessageDialog");
}

//------------------------------------------------------------------------------
// Address: 0x103CCA10
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CMessageDialog::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CMessageDialog::GetKBMap(CMessageDialog *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CMessageDialog::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CMessageDialog::GetKBMap'::`2'::s_pMap;
  `CMessageDialog::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CMessageDialog");
  `CMessageDialog::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103CCA40
// Name: public: CMessageDialog::CMessageDialog(class vgui::Panel __near *,unsigned int,char const __near *,char const __near *,char const __near *,char const __near *,class vgui::Panel __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CMessageDialog *__thiscall CMessageDialog::CMessageDialog(
        CMessageDialog *this,
        vgui::Panel *pParent,
        unsigned int nType,
        const char *pTitle,
        const char *pMsg,
        char *pCmdA,
        char *pCmdB,
        vgui::Panel *pCreator,
        bool bShowActivity)
{
  vgui::PanelMessageMap *v10; // edi
  PanelAnimationMap *v11; // edi
  vgui::PanelKeyBindingMap *v12; // edi
  vgui::Panel *v13; // eax
  vgui::Label *v14; // eax
  vgui::Label *v15; // eax
  vgui::Label *v16; // eax
  vgui::Label *v17; // eax
  vgui::AnimatingImagePanel *v18; // eax
  vgui::AnimatingImagePanel *v19; // eax
  vgui::ImagePanel *v20; // eax
  vgui::ImagePanel *v21; // eax
  unsigned int v22; // edi
  char *v23; // eax
  unsigned int v24; // edi
  char *v25; // eax

  vgui::Frame::Frame(this, parent: pParent, panelName: "MessageDialog", showTaskbarIcon: 1, bPopup: true);
  this->__vftable = (CMessageDialog_vtbl *)&CMessageDialog::`vftable';
  if ( `CMessageDialog::ChainToMap'::`2'::chained == 0 )
  {
    `CMessageDialog::ChainToMap'::`2'::chained = 1;
    v10 = vgui::FindOrAddPanelMessageMap(className: "CMessageDialog");
    v10->pfnClassName = CMessageDialog::GetPanelClassName;
    v10->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CMessageDialog::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CMessageDialog::ChainToAnimationMap'::`2'::chained = 1;
    v11 = FindOrAddPanelAnimationMap(className: "CMessageDialog");
    v11->pfnClassName = CMessageDialog::GetPanelClassName;
    v11->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CMessageDialog::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CMessageDialog::KB_ChainToMap'::`2'::chained = 1;
    v12 = vgui::FindOrAddPanelKeyBindingMap(className: "CMessageDialog");
    v12->pfnClassName = CMessageDialog::GetPanelClassName;
    v12->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  this->m_ButtonTextColor = 0;
  this->m_clrNotSimpleBG = 0;
  this->m_clrNotSimpleBGBlack = 0;
  vgui::Panel::SetSize(this, wide: 500, tall: 200);
  vgui::Frame::SetDeleteSelfOnClose(this, state: true);
  vgui::Frame::SetTitleBarVisible(this, state: false);
  vgui::Frame::SetCloseButtonVisible(this, state: false);
  vgui::Frame::SetSizeable(this, state: false);
  v13 = pCreator;
  this->m_pControlSettings = nullptr;
  if ( pCreator == nullptr )
    v13 = pParent;
  this->m_pCreator = v13;
  this->m_nType = nType;
  v14 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v14 != nullptr )
    v15 = vgui::Label::Label(this: v14, parent: this, panelName: "TitleLabel", text: pTitle);
  else
    v15 = nullptr;
  this->m_pTitle = v15;
  v16 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v16 != nullptr )
    v17 = vgui::Label::Label(this: v16, parent: this, panelName: "MessageLabel", text: pMsg);
  else
    v17 = nullptr;
  this->m_pMsg = v17;
  v18 = (vgui::AnimatingImagePanel *)MemAlloc_Alloc(nSize: 0x178u);
  if ( v18 != nullptr )
    v19 = vgui::AnimatingImagePanel::AnimatingImagePanel(this: v18, parent: this, name: "AnimatingPanel");
  else
    v19 = nullptr;
  this->m_pAnimatingPanel = v19;
  this->m_bShowActivity = bShowActivity;
  if ( (nType & 0x100) != 0 )
  {
    vgui::Panel::SetPaintBackgroundEnabled(this, state: true);
    this->m_pBackground = nullptr;
  }
  else
  {
    v20 = (vgui::ImagePanel *)MemAlloc_Alloc(nSize: 0x17Cu);
    if ( v20 != nullptr )
      v21 = vgui::ImagePanel::ImagePanel(this: v20, parent: this, name: "Background");
    else
      v21 = nullptr;
    this->m_pBackground = v21;
    if ( (nType & 1) != 0 )
    {
      vgui::Panel::SetName(this: v21, panelName: "WarningBackground");
    }
    else if ( (nType & 2) != 0 )
    {
      vgui::Panel::SetName(this: v21, panelName: "ErrorBackground");
    }
  }
  _V_memset(dest: (int)this->m_pCommands, fill: nullptr, count: 8u);
  _V_memset(dest: (int)this->m_Buttons, fill: nullptr, count: 0x20u);
  if ( pCmdA != nullptr )
  {
    v22 = _V_strlen(str: pCmdA) + 1;
    v23 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v22);
    this->m_pCommands[1] = v23;
    V_strncpy(pDest: v23, pSrc: pCmdA, maxLen: v22);
  }
  if ( pCmdB != nullptr )
  {
    v24 = _V_strlen(str: pCmdB) + 1;
    v25 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v24);
    this->m_pCommands[0] = v25;
    V_strncpy(pDest: v25, pSrc: pCmdB, maxLen: v24);
  }
  this->m_ButtonPressed = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103CCD10
// Name: private: void CMessageDialog::CreateButtonLabel(struct CMessageDialog::ButtonLabel_s __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMessageDialog::CreateButtonLabel(
        CMessageDialog *this,
        CMessageDialog::ButtonLabel_s *pButton,
        const char *pIcon,
        const char *pText)
{
  vgui::Label *v5; // eax
  vgui::Label *v6; // eax
  vgui::Label *v7; // eax
  vgui::Label *v8; // eax

  pButton->nWide = this->m_ButtonIconLabelSpace;
  pButton->bCreated = true;
  v5 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v5 != nullptr )
    v6 = vgui::Label::Label(this: v5, parent: this, panelName: "icon", text: pIcon);
  else
    v6 = nullptr;
  pButton->pIcon = v6;
  vgui::Panel::MakeReadyForUse(this: v6);
  pButton->pIcon->SetFont(this: pButton->pIcon, a2: this->m_hButtonFont);
  pButton->pIcon->SizeToContents(this: pButton->pIcon);
  pButton->nWide += vgui::Panel::GetWide(this: pButton->pIcon);
  v7 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v7 != nullptr )
    v8 = vgui::Label::Label(this: v7, parent: this, panelName: "text", text: pText);
  else
    v8 = nullptr;
  pButton->pText = v8;
  vgui::Panel::MakeReadyForUse(this: v8);
  pButton->pText->SetFont(this: pButton->pText, a2: this->m_hTextFont);
  pButton->pText->SizeToContents(this: pButton->pText);
  ((void (__thiscall *)(vgui::Label *, _DWORD))pButton->pText->SetFgColor)(
    a1: pButton->pText,
    a2: *(_DWORD *)&this->m_ButtonTextColor);
  pButton->nWide += vgui::Panel::GetWide(this: pButton->pText);
}

//------------------------------------------------------------------------------
// Address: 0x103CCE00
// Name: public: virtual void CMessageDialog::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMessageDialog::ApplySchemeSettings(CMessageDialog *this@<ecx>, int a2@<ebx>, int pScheme)
{
  int v3; // edi
  unsigned int m_nType; // eax
  int nWide; // edi
  bool v7; // zf
  int v8; // ebx
  int v9; // ecx
  int v10; // ebx
  int v11; // eax
  CMessageDialog::ButtonLabel_s *m_Buttons; // edi
  vgui::Panel *pIcon; // ecx
  int Wide; // eax
  vgui::Panel *pText; // ecx
  int v16; // edi
  Color *(__thiscall *v17)(vgui::IScheme *, Color *, const char *, Color); // eax
  Color v18; // ecx
  vgui::AnimatingImagePanel *m_pAnimatingPanel; // ecx
  void (*StartAnimation)(void); // eax
  int iH; // [esp+8h] [ebp-10h] BYREF
  int iY; // [esp+Ch] [ebp-Ch] BYREF
  int iX; // [esp+10h] [ebp-8h] BYREF
  int xpos; // [esp+14h] [ebp-4h]

  v3 = pScheme;
  vgui::Frame::ApplySchemeSettings(this, (vgui::IScheme *)pScheme);
  this->LoadControlSettings(
    this,
    a2: "resource/UI/MessageDialog.res",
    a3: "GAME",
    a4: this->m_pControlSettings,
    a5: nullptr);
  this->m_hButtonFont = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v3 + 12))(
                          a1: v3,
                          a2: "GameUIButtons",
                          a3: 0);
  this->m_hTextFont = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v3 + 12))(
                        a1: v3,
                        a2: "MenuLarge",
                        a3: 0);
  m_nType = this->m_nType;
  if ( (m_nType & 4) != 0 )
  {
    CMessageDialog::CreateButtonLabel(
      this,
      pButton: &this->m_Buttons[1],
      pIcon: "#GameUI_Icons_A_BUTTON",
      pText: "#GameUI_OK");
  }
  else if ( (m_nType & 8) != 0 )
  {
    CMessageDialog::CreateButtonLabel(
      this,
      pButton: this->m_Buttons,
      pIcon: "#GameUI_Icons_B_BUTTON",
      pText: "#GameUI_Cancel");
  }
  else if ( (m_nType & 0x10) != 0 )
  {
    CMessageDialog::CreateButtonLabel(
      this,
      pButton: &this->m_Buttons[1],
      pIcon: "#GameUI_Icons_A_BUTTON",
      pText: "#GameUI_OK");
    CMessageDialog::CreateButtonLabel(
      this,
      pButton: this->m_Buttons,
      pIcon: "#GameUI_Icons_B_BUTTON",
      pText: "#GameUI_Cancel");
  }
  else if ( (m_nType & 0x20) != 0 )
  {
    CMessageDialog::CreateButtonLabel(
      this,
      pButton: &this->m_Buttons[1],
      pIcon: "#GameUI_Icons_A_BUTTON",
      pText: "#GameUI_Yes");
    CMessageDialog::CreateButtonLabel(
      this,
      pButton: this->m_Buttons,
      pIcon: "#GameUI_Icons_B_BUTTON",
      pText: "#GameUI_No");
  }
  nWide = 0;
  v7 = !this->m_Buttons[0].bCreated;
  iX = 0;
  if ( !v7 )
  {
    nWide = this->m_Buttons[0].nWide;
    iX = 1;
  }
  if ( this->m_Buttons[1].bCreated )
  {
    ++iX;
    nWide += this->m_Buttons[1].nWide;
  }
  v8 = ((int (__thiscall *)(vgui::ISurface *, unsigned int, int))g_pVGuiSurface->GetFontTall)(
         a1: g_pVGuiSurface,
         a2: this->m_hButtonFont,
         a3: a2);
  v9 = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: this->m_hTextFont);
  iH = (v8 - v9) / 2;
  xpos = 0;
  iY = v8;
  if ( v8 <= v9 )
    iY = v9;
  v10 = vgui::Panel::GetTall(this) - this->m_ButtonMargin - iY;
  v11 = (vgui::Panel::GetWide(this) - nWide) / (iX + 1);
  m_Buttons = this->m_Buttons;
  iY = 2;
  iX = v11;
  do
  {
    if ( m_Buttons->bCreated )
    {
      pIcon = m_Buttons->pIcon;
      xpos += iX;
      vgui::Panel::SetPos(this: pIcon, x: xpos, y: v10);
      Wide = vgui::Panel::GetWide(this: m_Buttons->pIcon);
      pText = m_Buttons->pText;
      xpos += this->m_ButtonIconLabelSpace + Wide;
      vgui::Panel::SetPos(this: pText, x: xpos, y: v10 + iH);
      xpos += vgui::Panel::GetWide(this: m_Buttons->pText);
    }
    ++m_Buttons;
    --iY;
  }
  while ( iY != 0 );
  v16 = pScheme;
  v17 = *(Color *(__thiscall **)(vgui::IScheme *, Color *, const char *, Color))(*(_DWORD *)pScheme + 20);
  iX = -6833976;
  v18 = *(Color *)((int (__thiscall *)(int, int *, const char *))v17)(
                    a1: pScheme,
                    a2: &pScheme,
                    a3: "MessageDialog.MatchmakingBG");
  pScheme = -13160396;
  this->m_clrNotSimpleBG = v18;
  this->m_clrNotSimpleBGBlack = *(Color *)(*(int (__thiscall **)(int, int *, const char *, int))(*(_DWORD *)v16 + 20))(
                                            a1: v16,
                                            a2: &pScheme,
                                            a3: "MessageDialog.MatchmakingBGBlack",
                                            a4: -13160396);
  m_pAnimatingPanel = this->m_pAnimatingPanel;
  if ( this->m_bShowActivity )
  {
    if ( m_pAnimatingPanel != nullptr )
    {
      if ( !m_pAnimatingPanel->IsVisible(this: m_pAnimatingPanel) )
        this->m_pAnimatingPanel->SetVisible(this: this->m_pAnimatingPanel, a2: true);
      StartAnimation = (void (*)(void))this->m_pAnimatingPanel->StartAnimation;
      goto LABEL_28;
    }
  }
  else if ( m_pAnimatingPanel != nullptr )
  {
    if ( m_pAnimatingPanel->IsVisible(this: m_pAnimatingPanel) )
      this->m_pAnimatingPanel->SetVisible(this: this->m_pAnimatingPanel, a2: false);
    StartAnimation = (void (*)(void))this->m_pAnimatingPanel->StopAnimation;
LABEL_28:
    StartAnimation();
  }
  this->MoveToCenterOfScreen(this);
  if ( this->m_bShowActivity && this->m_ActivityIndent != 0 )
  {
    vgui::Panel::GetBounds(this: this->m_pMsg, x: &iX, y: &iY, wide: &pScheme, tall: &iH);
    vgui::Panel::SetBounds(
      this: this->m_pMsg,
      x: iX + this->m_ActivityIndent,
      y: iY,
      wide: pScheme - this->m_ActivityIndent < 0 ? 0 : pScheme - this->m_ActivityIndent,
      tall: iH);
  }
  this->m_pMsg->InvalidateLayout(this: this->m_pMsg, a2: false, a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x103CD150
// Name: public: virtual void CMessageDialog::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMessageDialog::ApplySettings(CMessageDialog *this, KeyValues *inResourceData)
{
  KeyValues *v2; // edi
  vgui::Label *m_pTitle; // eax
  Color *Color; // eax
  vgui::Label *m_pMsg; // ecx
  Color *v7; // eax
  Color result; // [esp+Ch] [ebp-8h] BYREF
  vgui::Label_vtbl *v9; // [esp+10h] [ebp-4h]

  v2 = inResourceData;
  vgui::Frame::ApplySettings(this, inResourceData);
  m_pTitle = this->m_pTitle;
  inResourceData = nullptr;
  v9 = m_pTitle->__vftable;
  Color = KeyValues::GetColor(this: v2, &result, keyName: "titlecolor", defaultColor: (const Color *)&inResourceData);
  v9->SetFgColor(this: this->m_pTitle, a2: *Color);
  m_pMsg = this->m_pMsg;
  inResourceData = nullptr;
  v9 = m_pMsg->__vftable;
  v7 = KeyValues::GetColor(this: v2, &result, keyName: "messagecolor", defaultColor: (const Color *)&inResourceData);
  v9->SetFgColor(this: this->m_pMsg, a2: *v7);
  inResourceData = nullptr;
  this->m_ButtonTextColor = *KeyValues::GetColor(
                               this: v2,
                               &result,
                               keyName: "buttontextcolor",
                               defaultColor: (const Color *)&inResourceData);
  this->m_FooterTall = KeyValues::GetInt(this: v2, keyName: "footer_tall", defaultValue: 0);
  this->m_ButtonMargin = KeyValues::GetInt(this: v2, keyName: "button_margin", defaultValue: 25);
  this->m_ButtonIconLabelSpace = KeyValues::GetInt(this: v2, keyName: "button_separator", defaultValue: 10);
  this->m_ActivityIndent = KeyValues::GetInt(this: v2, keyName: "activity_indent", defaultValue: 0);
}
