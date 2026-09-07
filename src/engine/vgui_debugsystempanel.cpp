// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/vgui_debugsystempanel.cpp
// Functions: 37
// ============================================================

#include "engine\vgui_debugsystempanel.h"

//------------------------------------------------------------------------------
// Address: 0x1020A410
// Name: public: virtual void CDebugCommandButton::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDebugCommandButton::OnCommand(CDebugCommandButton *this, const char *command)
{
  vgui::CTreeViewListControl *v2; // ecx
  ECommandTarget_t TraceType; // eax
  const char *v4; // [esp-8h] [ebp-8h]

  v4 = va(format: "%s\n", command);
  TraceType = CTraceFilter::GetTraceType(this: v2);
  Cbuf_AddText(eTarget: TraceType, pText: v4, nTickDelay: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1020A440
// Name: public: CDebugMenuButton::CDebugMenuButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDebugMenuButton *__thiscall CDebugMenuButton::CDebugMenuButton(
        CDebugMenuButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::Menu *v5; // eax
  vgui::Menu *v6; // eax

  vgui::MenuButton::MenuButton(this, parent, panelName, text);
  this->__vftable = (CDebugMenuButton_vtbl *)&CDebugMenuButton::`vftable';
  vgui::Panel::MakePopup(this, showTaskbarIcon: true, disabled: false);
  v5 = (vgui::Menu *)MemAlloc_Alloc(nSize: 0x420u);
  if ( v5 != nullptr )
    v6 = vgui::Menu::Menu(this: v5, parent: this, panelName: "DebugMenu");
  else
    v6 = nullptr;
  this->m_pMenu = v6;
  v6->AddMenuItem(this: v6, a2: "Debug Panel", a3: "toggledebugpanel", a4: parent, a5: nullptr);
  this->m_pMenu->AddMenuItem(this: this->m_pMenu, a2: "Quit", a3: "Quit", a4: parent, a5: nullptr);
  vgui::MenuButton::SetMenu(this, menu: this->m_pMenu);
  vgui::MenuButton::SetOpenDirection(this, direction: (vgui::Menu::MenuDirection_e)3);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1020A4F0
// Name: public: static char const __near * vgui::Button::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::Button::GetPanelClassName()
{
  return "Button";
}

//------------------------------------------------------------------------------
// Address: 0x1020A500
// Name: public: static char const __near * vgui::CheckButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CheckButton::GetPanelClassName()
{
  return "CheckButton";
}

//------------------------------------------------------------------------------
// Address: 0x1020A520
// Name: public: virtual void CDebugCommandCheckbox::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDebugCommandCheckbox::OnCommand(CDebugCommandCheckbox *this, const char *command)
{
  ConVar *m_pVar; // eax
  ConVar *m_pParent; // eax
  int m_nValue; // eax
  const char *v5; // eax
  vgui::CTreeViewListControl *v6; // ecx
  ECommandTarget_t TraceType; // eax
  int v8; // [esp-8h] [ebp-8h]
  const char *v9; // [esp-8h] [ebp-8h]

  m_pVar = this->m_pVar;
  if ( m_pVar != nullptr )
  {
    m_pParent = m_pVar->m_pParent;
    if ( m_pParent != nullptr )
      m_nValue = m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    v5 = (const char *)((int (__thiscall *)(ConVar *, bool))this->m_pVar->GetName)(a1: this->m_pVar, a2: m_nValue == 0);
    v9 = va(format: "%s %d\n", v5, v8);
    TraceType = CTraceFilter::GetTraceType(this: v6);
    Cbuf_AddText(eTarget: TraceType, pText: v9, nTickDelay: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020A5A0
// Name: public: virtual void CDebugIncrementCVarButton::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDebugIncrementCVarButton::OnTick(CDebugIncrementCVarButton *this)
{
  ConVar *m_pVar; // ecx
  const char *v3; // eax
  double m_fValue; // [esp+0h] [ebp-20Ch]
  double v5; // [esp+0h] [ebp-20Ch]
  char pDest[12]; // [esp+8h] [ebp-204h] BYREF

  m_pVar = this->m_pVar;
  if ( m_pVar != nullptr && m_pVar->m_pParent->m_Value.m_fValue != this->m_flPreviousValue )
  {
    m_fValue = m_pVar->m_pParent->m_Value.m_fValue;
    v3 = (const char *)((int (__cdecl *)(_DWORD, _DWORD))m_pVar->GetName)(a1: LODWORD(m_fValue), a2: HIDWORD(m_fValue));
    V_snprintf(pDest: &pDest[4], maxLen: 512, pFormat: "%s %.2f", v3, v5);
    this->SetText(this, a2: &pDest[4]);
    this->SizeToContents(this);
    this->m_flPreviousValue = this->m_pVar->m_pParent->m_Value.m_fValue;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020A630
// Name: public: virtual void CDebugSystemPanel::SetVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDebugSystemPanel::SetVisible(CDebugSystemPanel *this, int state)
{
  vgui::ISurface *v3; // edi
  vgui::ISurface_vtbl *v4; // ebx
  unsigned int v5; // eax

  vgui::Panel::SetVisible(this, state);
  if ( (_BYTE)state != 0 )
  {
    v3 = g_pVGuiSurface;
    v4 = g_pVGuiSurface->__vftable;
    v5 = this->GetCursor(this);
    v4->SetCursor(this: v3, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020A670
// Name: public: virtual void CDebugSystemPanel::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDebugSystemPanel::OnCommand(CDebugSystemPanel *this, const char *command)
{
  vgui::DHANDLE<CDebugOptionsPanel> *p_m_hDebugOptions; // esi
  vgui::Panel *v4; // edi
  vgui::Panel *v5; // ebx
  vgui::Panel_vtbl *v6; // esi
  bool v7; // al
  vgui::CTreeViewListControl *v8; // ecx
  ECommandTarget_t TraceType; // eax

  if ( V_strcasecmp(s1: command, s2: "toggledebugpanel") != 0 )
  {
    if ( V_strcasecmp(s1: command, s2: "quit") == 0 )
    {
      TraceType = CTraceFilter::GetTraceType(this: v8);
      Cbuf_AddText(eTarget: TraceType, pText: "quit\n", nTickDelay: 0);
    }
    vgui::Panel::OnCommand(this, command);
  }
  else
  {
    p_m_hDebugOptions = &this->m_hDebugOptions;
    if ( vgui::PHandle::Get(this: p_m_hDebugOptions) != nullptr )
    {
      v4 = vgui::PHandle::Get(this: p_m_hDebugOptions);
      v5 = vgui::PHandle::Get(this: p_m_hDebugOptions);
      v6 = v5->__vftable;
      v7 = v4->IsVisible(this: v4);
      v6->SetVisible(this: v5, a2: !v7);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020A710
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Button::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Button::GetMessageMap(vgui::Button *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Button::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Button::GetMessageMap'::`2'::s_pMap;
  `vgui::Button::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "Button");
  `vgui::Button::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1020A750
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Button::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Button::GetKBMap(vgui::Button *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Button::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Button::GetKBMap'::`2'::s_pMap;
  `vgui::Button::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  `vgui::Button::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1020A780
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CheckButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CheckButton::GetMessageMap(vgui::CheckButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CheckButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CheckButton::GetMessageMap'::`2'::s_pMap;
  `vgui::CheckButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CheckButton");
  `vgui::CheckButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1020A7B0
// Name: public: virtual struct PanelAnimationMap __near * vgui::CheckButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CheckButton::GetAnimMap(vgui::CheckButton *this)
{
  return FindOrAddPanelAnimationMap(className: "CheckButton");
}

//------------------------------------------------------------------------------
// Address: 0x1020A7C0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CheckButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CheckButton::GetKBMap(vgui::CheckButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CheckButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CheckButton::GetKBMap'::`2'::s_pMap;
  `vgui::CheckButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CheckButton");
  `vgui::CheckButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1020A7F0
// Name: public: CDebugIncrementCVarButton::CDebugIncrementCVarButton(class vgui::Panel __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDebugIncrementCVarButton *__thiscall CDebugIncrementCVarButton::CDebugIncrementCVarButton(
        CDebugIncrementCVarButton *this,
        vgui::Panel *pParent,
        const char *pPanelName,
        const char *pLabelText,
        char *pCommand)
{
  int m_nArgc; // eax
  bool v7; // cc
  const char *v8; // eax
  ConVar *v9; // eax
  const char *v10; // eax
  const char *v11; // eax
  const char *v12; // eax
  CCommand args; // [esp+4h] [ebp-508h] BYREF

  vgui::Button::Button(
    this,
    parent: pParent,
    panelName: pPanelName,
    text: pLabelText,
    pActionSignalTarget: nullptr,
    pCmd: nullptr);
  this->__vftable = (CDebugIncrementCVarButton_vtbl *)&CDebugIncrementCVarButton::`vftable';
  CCommand::CCommand(this: &args);
  CCommand::Tokenize(this: &args, pCommand, pBreakSet: nullptr);
  m_nArgc = args.m_nArgc;
  this->m_pVar = nullptr;
  if ( m_nArgc >= 4 )
  {
    v7 = m_nArgc <= 0;
    v8 = defaultValue;
    if ( !v7 )
      v8 = args.m_ppArgv[0];
    v9 = g_pCVar->FindVar_2(this: g_pCVar, a2: v8);
    v7 = args.m_nArgc <= 1;
    this->m_pVar = v9;
    v10 = defaultValue;
    if ( !v7 )
      v10 = args.m_ppArgv[1];
    this->m_flMinvalue = atof(nptr: v10);
    v11 = defaultValue;
    if ( args.m_nArgc > 2 )
      v11 = args.m_ppArgv[2];
    this->m_flMaxvalue = atof(nptr: v11);
    v12 = defaultValue;
    if ( args.m_nArgc > 3 )
      v12 = args.m_ppArgv[3];
    this->m_flIncrement = atof(nptr: v12);
  }
  vgui::Button::SetCommand(this, command: "increment");
  vgui::Panel::AddActionSignalTarget(this, messageTarget: this);
  this->m_flPreviousValue = -9999.0;
  CDebugIncrementCVarButton::OnTick(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1020A910
// Name: public: virtual void CDebugIncrementCVarButton::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDebugIncrementCVarButton::OnCommand(CDebugIncrementCVarButton *this, const char *command)
{
  ConVar *m_pVar; // eax
  float v3; // xmm0_4
  float m_flMaxvalue; // [esp+4h] [ebp-4h]

  m_pVar = this->m_pVar;
  if ( m_pVar != nullptr )
  {
    v3 = m_pVar->m_pParent->m_Value.m_fValue + this->m_flIncrement;
    m_flMaxvalue = v3;
    if ( v3 <= this->m_flMaxvalue )
    {
      if ( this->m_flMinvalue > v3 )
        m_flMaxvalue = this->m_flMaxvalue;
    }
    else
    {
      m_flMaxvalue = this->m_flMinvalue;
    }
    ((void (__stdcall *)(_DWORD))this->m_pVar->SetValue_3)(a1: LODWORD(m_flMaxvalue));
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020A9B0
// Name: public: CDebugOptionsPage::CDebugOptionsPage(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDebugOptionsPage *__thiscall CDebugOptionsPage::CDebugOptionsPage(
        CDebugOptionsPage *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PropertyPage::PropertyPage(this, parent, panelName);
  this->__vftable = (CDebugOptionsPage_vtbl *)&CDebugOptionsPage::`vftable';
  this->m_LayoutItems.m_Memory.m_pMemory = nullptr;
  this->m_LayoutItems.m_Memory.m_nAllocationCount = 0;
  this->m_LayoutItems.m_Memory.m_nGrowSize = 0;
  this->m_LayoutItems.m_Size = 0;
  this->m_LayoutItems.m_pElements = nullptr;
  g_pVGui->AddTickSignal(this: g_pVGui, a2: this->_vpanel, a3: 250);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1020AA10
// Name: public: static char const __near * vgui::PropertyPage::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::PropertyPage::GetPanelClassName()
{
  return "PropertyPage";
}

//------------------------------------------------------------------------------
// Address: 0x1020AA20
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::PropertyPage::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::PropertyPage::GetMessageMap(vgui::PropertyPage *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::PropertyPage::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::PropertyPage::GetMessageMap'::`2'::s_pMap;
  `vgui::PropertyPage::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "PropertyPage");
  `vgui::PropertyPage::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1020AA50
// Name: public: virtual struct PanelAnimationMap __near * vgui::PropertyPage::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::PropertyPage::GetAnimMap(vgui::PropertyPage *this)
{
  return FindOrAddPanelAnimationMap(className: "PropertyPage");
}

//------------------------------------------------------------------------------
// Address: 0x1020AA60
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::PropertyPage::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::PropertyPage::GetKBMap(vgui::PropertyPage *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::PropertyPage::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::PropertyPage::GetKBMap'::`2'::s_pMap;
  `vgui::PropertyPage::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "PropertyPage");
  `vgui::PropertyPage::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1020AA90
// Name: public: virtual void CDebugOptionsPage::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDebugOptionsPage::OnTick(CDebugOptionsPage *this)
{
  int m_Size; // edi
  int i; // esi
  vgui::Panel *v4; // ecx

  CColorBalanceUIPanel::Init(this);
  if ( this->IsVisible(this) )
  {
    m_Size = this->m_LayoutItems.m_Size;
    for ( i = 0; i < m_Size; ++i )
    {
      v4 = this->m_LayoutItems.m_Memory.m_pMemory[i];
      v4->OnTick(this: v4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020AAE0
// Name: public: virtual void CDebugOptionsPage::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDebugOptionsPage::PerformLayout(CDebugOptionsPage *this)
{
  int v2; // esi
  int Tall; // eax
  int v4; // ebx
  int v5; // [esp+Ch] [ebp-Ch]
  int c; // [esp+10h] [ebp-8h]
  int x; // [esp+14h] [ebp-4h]

  vgui::EditablePanel::PerformLayout(this);
  v2 = 5;
  c = this->m_LayoutItems.m_Size;
  x = 5;
  Tall = vgui::Panel::GetTall(this);
  v4 = 0;
  if ( c > 0 )
  {
    v5 = Tall - 18;
    do
    {
      vgui::Panel::SetBounds(this: this->m_LayoutItems.m_Memory.m_pMemory[v4], x, y: v2, wide: 150, tall: 18);
      v2 += 20;
      if ( v2 >= v5 )
      {
        x += 152;
        v2 = 5;
      }
      ++v4;
    }
    while ( v4 < c );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020AB50
// Name: public: void CDebugOptionsPage::Init(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDebugOptionsPage::Init(CDebugOptionsPage *this, KeyValues *kv)
{
  KeyValues *FirstSubKey; // ebx
  const char *String; // eax
  const char *v4; // edi
  vgui::Button *v5; // esi
  const char *Name; // eax
  int m_Size; // esi
  int m_nAllocationCount; // eax
  vgui::Panel **m_pMemory; // ecx
  int v10; // eax
  vgui::Panel **v11; // eax
  const char *v12; // eax
  const char *v13; // edi
  vgui::CheckButton *v14; // esi
  const char *v15; // eax
  vgui::CheckButton *v16; // ebx
  int v17; // esi
  int v18; // eax
  vgui::Panel **v19; // ecx
  int v20; // eax
  vgui::Panel **v21; // eax
  const char *v22; // eax
  char *v23; // esi
  CDebugIncrementCVarButton *v24; // edi
  const char *v25; // eax
  int v26; // edi
  int v27; // eax
  vgui::Panel **v28; // ecx
  int v29; // eax
  vgui::Panel **v30; // eax
  CDebugIncrementCVarButton *increment; // [esp+10h] [ebp+8h]
  CDebugIncrementCVarButton *incrementa; // [esp+10h] [ebp+8h]
  CDebugIncrementCVarButton *incrementb; // [esp+10h] [ebp+8h]

  FirstSubKey = KeyValues::GetFirstSubKey(this: kv);
  increment = (CDebugIncrementCVarButton *)FirstSubKey;
  if ( FirstSubKey != nullptr )
  {
    while ( 1 )
    {
      String = KeyValues::GetString(this: FirstSubKey, keyName: "command", defaultValue: defaultValue);
      v4 = String;
      if ( String != nullptr && *String != 0 )
      {
        v5 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
        if ( v5 != nullptr )
        {
          Name = KeyValues::GetName(this: FirstSubKey);
          vgui::Button::Button(
            this: v5,
            parent: this,
            panelName: "CommandButton",
            text: Name,
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
          v5->__vftable = (vgui::Button_vtbl *)&CDebugCommandButton::`vftable';
          vgui::Panel::AddActionSignalTarget(this: v5, messageTarget: v5);
          vgui::Button::SetCommand(this: v5, command: v4);
          incrementa = (CDebugIncrementCVarButton *)v5;
        }
        else
        {
          incrementa = nullptr;
        }
        m_Size = this->m_LayoutItems.m_Size;
        m_nAllocationCount = this->m_LayoutItems.m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<INetMessage *,int>::Grow(
            this: (CUtlMemory<S3RGBA,int> *)&this->m_LayoutItems,
            num: m_Size - m_nAllocationCount + 1);
        ++this->m_LayoutItems.m_Size;
        m_pMemory = this->m_LayoutItems.m_Memory.m_pMemory;
        v10 = this->m_LayoutItems.m_Size - m_Size - 1;
        this->m_LayoutItems.m_pElements = m_pMemory;
        if ( v10 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v10);
        v11 = &this->m_LayoutItems.m_Memory.m_pMemory[m_Size];
        if ( v11 != nullptr )
          *v11 = incrementa;
      }
      else
      {
        v12 = KeyValues::GetString(this: FirstSubKey, keyName: "togglecvar", defaultValue: defaultValue);
        v13 = v12;
        if ( v12 != nullptr && *v12 != 0 )
        {
          v14 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x21Cu);
          if ( v14 != nullptr )
          {
            v15 = KeyValues::GetName(this: FirstSubKey);
            vgui::CheckButton::CheckButton(this: v14, parent: this, panelName: "CommandCheck", text: v15);
            v14->__vftable = (vgui::CheckButton_vtbl *)&CDebugCommandCheckbox::`vftable';
            v14[1].__vftable = (vgui::CheckButton_vtbl *)g_pCVar->FindVar_2(this: g_pCVar, a2: v13);
            vgui::Button::SetCommand(this: v14, command: v13);
            vgui::Panel::AddActionSignalTarget(this: v14, messageTarget: v14);
            v16 = v14;
          }
          else
          {
            v16 = nullptr;
          }
          v17 = this->m_LayoutItems.m_Size;
          v18 = this->m_LayoutItems.m_Memory.m_nAllocationCount;
          if ( v17 + 1 > v18 )
            CUtlMemory<INetMessage *,int>::Grow(
              this: (CUtlMemory<S3RGBA,int> *)&this->m_LayoutItems,
              num: v17 - v18 + 1);
          ++this->m_LayoutItems.m_Size;
          v19 = this->m_LayoutItems.m_Memory.m_pMemory;
          v20 = this->m_LayoutItems.m_Size - v17 - 1;
          this->m_LayoutItems.m_pElements = v19;
          if ( v20 > 0 )
            _V_memmove(dest: &v19[v17 + 1], src: &v19[v17], count: 4 * v20);
          v21 = &this->m_LayoutItems.m_Memory.m_pMemory[v17];
          if ( v21 != nullptr )
            *v21 = v16;
          FirstSubKey = (KeyValues *)increment;
        }
        else
        {
          v22 = KeyValues::GetString(this: FirstSubKey, keyName: "incrementcvar", defaultValue: defaultValue);
          v23 = (char *)v22;
          if ( v22 != nullptr && *v22 != 0 )
          {
            v24 = (CDebugIncrementCVarButton *)MemAlloc_Alloc(nSize: 0x208u);
            if ( v24 != nullptr )
            {
              v25 = KeyValues::GetName(this: FirstSubKey);
              incrementb = CDebugIncrementCVarButton::CDebugIncrementCVarButton(
                             this: v24,
                             pParent: this,
                             pPanelName: "IncrementCVar",
                             pLabelText: v25,
                             pCommand: v23);
            }
            else
            {
              incrementb = nullptr;
            }
            v26 = this->m_LayoutItems.m_Size;
            v27 = this->m_LayoutItems.m_Memory.m_nAllocationCount;
            if ( v26 + 1 > v27 )
              CUtlMemory<INetMessage *,int>::Grow(
                this: (CUtlMemory<S3RGBA,int> *)&this->m_LayoutItems,
                num: v26 - v27 + 1);
            ++this->m_LayoutItems.m_Size;
            v28 = this->m_LayoutItems.m_Memory.m_pMemory;
            v29 = this->m_LayoutItems.m_Size - v26 - 1;
            this->m_LayoutItems.m_pElements = v28;
            if ( v29 > 0 )
              _V_memmove(dest: &v28[v26 + 1], src: &v28[v26], count: 4 * v29);
            v30 = &this->m_LayoutItems.m_Memory.m_pMemory[v26];
            if ( v30 != nullptr )
              *v30 = incrementb;
          }
        }
      }
      increment = (CDebugIncrementCVarButton *)KeyValues::GetNextKey(this: FirstSubKey);
      if ( increment == nullptr )
        break;
      FirstSubKey = (KeyValues *)increment;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020AE60
// Name: public: CDebugOptionsPanel::CDebugOptionsPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDebugOptionsPanel *__thiscall CDebugOptionsPanel::CDebugOptionsPanel(
        CDebugOptionsPanel *this,
        vgui::Panel *parent,
        KeyValues *panelName)
{
  KeyValues *v4; // eax
  KeyValues *v5; // ebx
  IBaseFileSystem *v6; // eax
  KeyValues *i; // edi
  const char *Name; // eax
  int v9; // eax
  const char *v10; // eax
  int Int; // eax
  CDebugOptionsPage *v12; // ebx
  const char *v13; // eax
  CDebugOptionsPage *v14; // ebx
  const char *v15; // eax
  vgui::PropertySheet *Font; // eax
  int v17; // edi
  int v18; // eax
  KeyValues *kv; // [esp+14h] [ebp+Ch]

  vgui::PropertyDialog::PropertyDialog(this, parent, (const char *)panelName);
  this->__vftable = (CDebugOptionsPanel_vtbl *)&CDebugOptionsPanel::`vftable';
  vgui::Frame::SetTitle(this, title: "Debug Options", surfaceTitle: true);
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
  {
    v5 = KeyValues::KeyValues(this: v4, setName: "DebugOptions");
    kv = v5;
    if ( v5 != nullptr )
    {
      if ( g_pFullFileSystem != nullptr )
        v6 = &g_pFullFileSystem->IBaseFileSystem;
      else
        v6 = nullptr;
      if ( KeyValues::LoadFromFile(
             this: v5,
             filesystem: v6,
             resourceName: "scripts/DebugOptions.txt",
             pathID: nullptr,
             pfnEvaluateSymbolProc: nullptr) )
      {
        for ( i = KeyValues::GetFirstSubKey(this: v5); i != nullptr; i = KeyValues::GetNextKey(this: i) )
        {
          Name = KeyValues::GetName(this: i);
          if ( V_strcasecmp(s1: Name, s2: "width") != 0 )
          {
            v10 = KeyValues::GetName(this: i);
            if ( V_strcasecmp(s1: v10, s2: "height") != 0 )
            {
              v12 = (CDebugOptionsPage *)MemAlloc_Alloc(nSize: 0x19Cu);
              if ( v12 != nullptr )
              {
                v13 = KeyValues::GetName(this: i);
                v14 = CDebugOptionsPage::CDebugOptionsPage(this: v12, parent: this, panelName: v13);
              }
              else
              {
                v14 = nullptr;
              }
              CDebugOptionsPage::Init(this: v14, kv: i);
              v15 = KeyValues::GetName(this: i);
              vgui::PropertyDialog::AddPage(this, page: v14, title: v15);
              v5 = kv;
            }
            else
            {
              Int = KeyValues::GetInt(this: i, keyName: nullptr, defaultValue: 0);
              vgui::Panel::SetTall(this, tall: Int);
            }
          }
          else
          {
            v9 = KeyValues::GetInt(this: i, keyName: nullptr, defaultValue: 0);
            vgui::Panel::SetWide(this, wide: v9);
          }
        }
      }
      KeyValues::deleteThis(this: v5);
    }
  }
  Font = CRenderTextureEditor::GetFont(this);
  ((void (__thiscall *)(vgui::PropertySheet *))Font->SetTabWidth)(a1: Font);
  v17 = -10 - vgui::Panel::GetWide(this);
  v18 = ((int (__thiscall *)(IVideoMode *, int))videomode->GetModeWidth)(a1: videomode, a2: 10);
  vgui::Panel::SetPos(this, x: v17 + v18, y: 72);
  vgui::Panel::SetVisible(this, state: 1);
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "resource\\DebugOptionsPanel.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1020B010
// Name: public: static char const __near * vgui::PropertyDialog::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::PropertyDialog::GetPanelClassName()
{
  return "PropertyDialog";
}

//------------------------------------------------------------------------------
// Address: 0x1020B020
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::PropertyDialog::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::PropertyDialog::GetMessageMap(vgui::PropertyDialog *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::PropertyDialog::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::PropertyDialog::GetMessageMap'::`2'::s_pMap;
  `vgui::PropertyDialog::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "PropertyDialog");
  `vgui::PropertyDialog::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1020B050
// Name: public: virtual struct PanelAnimationMap __near * vgui::PropertyDialog::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::PropertyDialog::GetAnimMap(vgui::PropertyDialog *this)
{
  return FindOrAddPanelAnimationMap(className: "PropertyDialog");
}

//------------------------------------------------------------------------------
// Address: 0x1020B060
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::PropertyDialog::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::PropertyDialog::GetKBMap(vgui::PropertyDialog *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::PropertyDialog::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::PropertyDialog::GetKBMap'::`2'::s_pMap;
  `vgui::PropertyDialog::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "PropertyDialog");
  `vgui::PropertyDialog::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1020B0C0
// Name: public: CDebugSystemPanel::CDebugSystemPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDebugSystemPanel *__thiscall CDebugSystemPanel::CDebugSystemPanel(
        CDebugSystemPanel *this,
        vgui::Panel *parent,
        const char *panelName)
{
  int v4; // eax
  CDebugMenuButton *v5; // eax
  CDebugMenuButton *v6; // eax
  CDebugOptionsPanel *v7; // eax
  CDebugOptionsPanel *v8; // eax
  int v10; // [esp-4h] [ebp-Ch]

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (CDebugSystemPanel_vtbl *)&CDebugSystemPanel::`vftable';
  this->m_hDebugOptions.m_iPanelID = -1;
  v10 = videomode->GetModeHeight(this: videomode);
  v4 = videomode->GetModeWidth(this: videomode);
  vgui::Panel::SetBounds(this, x: 0, y: 0, wide: v4, tall: v10);
  vgui::Panel::SetCursor(this, cursor: 2u);
  vgui::Panel::SetVisible(this, state: 0);
  vgui::Panel::SetPaintEnabled(this, state: false);
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  v5 = (CDebugMenuButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v5 != nullptr )
    v6 = CDebugMenuButton::CDebugMenuButton(this: v5, parent: this, panelName: "Debug Menu", text: "Debug Menu");
  else
    v6 = nullptr;
  this->m_pDebugMenu = v6;
  vgui::Panel::SetPos(this: v6, x: 0, y: 0);
  vgui::Panel::SetSize(this: this->m_pDebugMenu, wide: 110, tall: 24);
  v7 = (CDebugOptionsPanel *)MemAlloc_Alloc(nSize: 0x22Cu);
  if ( v7 != nullptr )
  {
    v8 = CDebugOptionsPanel::CDebugOptionsPanel(this: v7, parent: this, panelName: (KeyValues *)"DebugOptions");
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(
      this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_hDebugOptions,
      pPanel: (CDragDropHelperPanel *)v8);
  }
  else
  {
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(
      this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_hDebugOptions,
      pPanel: nullptr);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102A3680
// Name: protected: virtual class vgui::IBorder __near * vgui::Button::GetBorder(bool,bool,bool,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::IBorder *__thiscall vgui::Button::GetBorder(
        vgui::Button *this,
        bool depressed,
        bool armed,
        bool selected,
        bool keyfocus)
{
  if ( (this->_buttonFlags.m_nFlags & 8) != 0 )
  {
    if ( depressed )
      return this->_depressedBorder;
    if ( keyfocus || this->IsEnabled(this) && (this->_buttonFlags.m_nFlags & 0x40) != 0 )
      return this->_keyFocusBorder;
  }
  else if ( depressed )
  {
    return this->_depressedBorder;
  }
  return this->_defaultBorder;
}

//------------------------------------------------------------------------------
// Address: 0x102D2490
// Name: public: virtual class vgui::Panel __near * vgui::PropertyDialog::GetActivePage(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::PropertyDialog::GetActivePage(vgui::PropertyDialog *this)
{
  return this->_propertySheet->GetActivePage(this: this->_propertySheet);
}

//------------------------------------------------------------------------------
// Address: 0x10318F10
// Name: _dynamic_initializer_for__debug_map_crc__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__debug_map_crc__()
{
  ConVar::ConVar(
    this: &debug_map_crc,
    pName: "debug_map_crc",
    pDefaultValue: "0",
    flags: 2,
    pHelpString: "Prints CRC for each map lump loaded");
  return atexit(func: dynamic_atexit_destructor_for__debug_map_crc__);
}

//------------------------------------------------------------------------------
// Address: 0x1031D380
// Name: _dynamic_initializer_for__debug_paint_alpha__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__debug_paint_alpha__()
{
  ConVar::ConVar(this: &debug_paint_alpha, pName: "debug_paint_alpha", pDefaultValue: "0", flags: 2);
  return atexit(func: dynamic_atexit_destructor_for__debug_paint_alpha__);
}

//------------------------------------------------------------------------------
// Address: 0x10324B30
// Name: _dynamic_atexit_destructor_for__debug_map_crc__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__debug_map_crc__()
{
  ConVar::~ConVar(this: &debug_map_crc);
}

//------------------------------------------------------------------------------
// Address: 0x10326600
// Name: _dynamic_atexit_destructor_for__debug_paint_alpha__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__debug_paint_alpha__()
{
  ConVar::~ConVar(this: &debug_paint_alpha);
}

//------------------------------------------------------------------------------
// Address: 0x1031D3B0
// Name: _dynamic_initializer_for__g_PaintManager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_PaintManager__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_PaintManager__);
}

//------------------------------------------------------------------------------
// Address: 0x10326610
// Name: _dynamic_atexit_destructor_for__g_PaintManager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_PaintManager__()
{
  g_PaintManager.__vftable = (CPaintmapDataManager_vtbl *)&CPaintmapDataManager::`vftable';
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1020A560
// Name: public: virtual void CDebugCommandButton::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDebugCommandButton::OnCommand(CDebugCommandButton *this, const char *command)
{
  vgui::CTreeViewListControl *v2; // ecx
  ECommandTarget_t TraceType; // eax
  const char *v4; // [esp-8h] [ebp-8h]

  v4 = va(format: "%s\n", command);
  TraceType = CTraceFilter::GetTraceType(this: v2);
  Cbuf_AddText(eTarget: TraceType, pText: v4, nTickDelay: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1020A590
// Name: public: CDebugMenuButton::CDebugMenuButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDebugMenuButton *__thiscall CDebugMenuButton::CDebugMenuButton(
        CDebugMenuButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::Menu *v5; // eax
  vgui::Menu *v6; // eax

  vgui::MenuButton::MenuButton(this, parent, panelName, text);
  this->__vftable = (CDebugMenuButton_vtbl *)&CDebugMenuButton::`vftable';
  vgui::Panel::MakePopup(this, showTaskbarIcon: true, disabled: false);
  v5 = (vgui::Menu *)MemAlloc_Alloc(nSize: 0x420u);
  if ( v5 != nullptr )
    v6 = vgui::Menu::Menu(this: v5, parent: this, panelName: "DebugMenu");
  else
    v6 = nullptr;
  this->m_pMenu = v6;
  v6->AddMenuItem(this: v6, a2: "Debug Panel", a3: "toggledebugpanel", a4: parent, a5: nullptr);
  this->m_pMenu->AddMenuItem(this: this->m_pMenu, a2: "Quit", a3: "Quit", a4: parent, a5: nullptr);
  vgui::MenuButton::SetMenu(this, menu: this->m_pMenu);
  vgui::MenuButton::SetOpenDirection(this, direction: (vgui::Menu::MenuDirection_e)3);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1020A640
// Name: public: static char const __near * vgui::Button::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::Button::GetPanelClassName()
{
  return "Button";
}

//------------------------------------------------------------------------------
// Address: 0x1020A650
// Name: public: static char const __near * vgui::CheckButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CheckButton::GetPanelClassName()
{
  return "CheckButton";
}

//------------------------------------------------------------------------------
// Address: 0x1020A660
// Name: public: virtual void CDebugCommandCheckbox::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDebugCommandCheckbox::OnCommand(CDebugCommandCheckbox *this, const char *command)
{
  ConVar *m_pVar; // eax
  ConVar *m_pParent; // eax
  int m_nValue; // eax
  const char *v5; // eax
  vgui::CTreeViewListControl *v6; // ecx
  ECommandTarget_t TraceType; // eax
  int v8; // [esp-8h] [ebp-8h]
  const char *v9; // [esp-8h] [ebp-8h]

  m_pVar = this->m_pVar;
  if ( m_pVar != nullptr )
  {
    m_pParent = m_pVar->m_pParent;
    if ( m_pParent != nullptr )
      m_nValue = m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    v5 = (const char *)((int (__thiscall *)(ConVar *, bool))this->m_pVar->GetName)(a1: this->m_pVar, a2: m_nValue == 0);
    v9 = va(format: "%s %d\n", v5, v8);
    TraceType = CTraceFilter::GetTraceType(this: v6);
    Cbuf_AddText(eTarget: TraceType, pText: v9, nTickDelay: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020A6B0
// Name: public: virtual void CDebugIncrementCVarButton::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDebugIncrementCVarButton::OnTick(CDebugIncrementCVarButton *this)
{
  ConVar *m_pVar; // ecx
  const char *v3; // eax
  double m_fValue; // [esp+0h] [ebp-20Ch]
  double v5; // [esp+0h] [ebp-20Ch]
  char pDest[12]; // [esp+8h] [ebp-204h] BYREF

  m_pVar = this->m_pVar;
  if ( m_pVar != nullptr && m_pVar->m_pParent->m_Value.m_fValue != this->m_flPreviousValue )
  {
    m_fValue = m_pVar->m_pParent->m_Value.m_fValue;
    v3 = (const char *)((int (__cdecl *)(_DWORD, _DWORD))m_pVar->GetName)(a1: LODWORD(m_fValue), a2: HIDWORD(m_fValue));
    V_snprintf(pDest: &pDest[4], maxLen: 512, pFormat: "%s %.2f", v3, v5);
    this->SetText(this, a2: &pDest[4]);
    this->SizeToContents(this);
    this->m_flPreviousValue = this->m_pVar->m_pParent->m_Value.m_fValue;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020A770
// Name: public: virtual void CDebugSystemPanel::SetVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDebugSystemPanel::SetVisible(CDebugSystemPanel *this, bool state)
{
  vgui::ISurface *v3; // edi
  vgui::ISurface_vtbl *v4; // ebx
  unsigned int v5; // eax

  vgui::Panel::SetVisible(this, state);
  if ( state )
  {
    v3 = g_pVGuiSurface;
    v4 = g_pVGuiSurface->__vftable;
    v5 = this->GetCursor(this);
    v4->SetCursor(this: v3, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020A850
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Button::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Button::GetMessageMap(vgui::Button *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Button::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Button::GetMessageMap'::`2'::s_pMap;
  `vgui::Button::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "Button");
  `vgui::Button::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1020A890
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Button::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Button::GetKBMap(vgui::Button *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Button::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Button::GetKBMap'::`2'::s_pMap;
  `vgui::Button::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  `vgui::Button::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1020A8C0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CheckButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CheckButton::GetMessageMap(vgui::CheckButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CheckButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CheckButton::GetMessageMap'::`2'::s_pMap;
  `vgui::CheckButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CheckButton");
  `vgui::CheckButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1020A8F0
// Name: public: virtual struct PanelAnimationMap __near * vgui::CheckButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CheckButton::GetAnimMap(vgui::CheckButton *this)
{
  return FindOrAddPanelAnimationMap(className: "CheckButton");
}

//------------------------------------------------------------------------------
// Address: 0x1020A900
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CheckButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CheckButton::GetKBMap(vgui::CheckButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CheckButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CheckButton::GetKBMap'::`2'::s_pMap;
  `vgui::CheckButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CheckButton");
  `vgui::CheckButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1020A930
// Name: public: CDebugIncrementCVarButton::CDebugIncrementCVarButton(class vgui::Panel __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDebugIncrementCVarButton *__thiscall CDebugIncrementCVarButton::CDebugIncrementCVarButton(
        CDebugIncrementCVarButton *this,
        vgui::Panel *pParent,
        const char *pPanelName,
        const char *pLabelText,
        const char *pCommand)
{
  int m_nArgc; // eax
  bool v7; // cc
  const char *v8; // eax
  ConVar *v9; // eax
  const char *v10; // eax
  const char *v11; // eax
  const char *v12; // eax
  CCommand args; // [esp+4h] [ebp-508h] BYREF

  vgui::Button::Button(
    this,
    parent: pParent,
    panelName: pPanelName,
    text: pLabelText,
    pActionSignalTarget: nullptr,
    pCmd: nullptr);
  this->__vftable = (CDebugIncrementCVarButton_vtbl *)&CDebugIncrementCVarButton::`vftable';
  CCommand::CCommand(this: &args);
  CCommand::Tokenize(this: &args, pCommand, pBreakSet: nullptr);
  m_nArgc = args.m_nArgc;
  this->m_pVar = nullptr;
  if ( m_nArgc >= 4 )
  {
    v7 = m_nArgc <= 0;
    v8 = defaultValue;
    if ( !v7 )
      v8 = args.m_ppArgv[0];
    v9 = g_pCVar->FindVar_2(this: g_pCVar, a2: v8);
    v7 = args.m_nArgc <= 1;
    this->m_pVar = v9;
    v10 = defaultValue;
    if ( !v7 )
      v10 = args.m_ppArgv[1];
    this->m_flMinvalue = atof(nptr: v10);
    v11 = defaultValue;
    if ( args.m_nArgc > 2 )
      v11 = args.m_ppArgv[2];
    this->m_flMaxvalue = atof(nptr: v11);
    v12 = defaultValue;
    if ( args.m_nArgc > 3 )
      v12 = args.m_ppArgv[3];
    this->m_flIncrement = atof(nptr: v12);
  }
  vgui::Button::SetCommand(this, command: "increment");
  vgui::Panel::AddActionSignalTarget(this, messageTarget: this);
  this->m_flPreviousValue = -9999.0;
  CDebugIncrementCVarButton::OnTick(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1020AAC0
// Name: public: CDebugOptionsPage::CDebugOptionsPage(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDebugOptionsPage *__thiscall CDebugOptionsPage::CDebugOptionsPage(
        CDebugOptionsPage *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PropertyPage::PropertyPage(this, parent, panelName);
  this->__vftable = (CDebugOptionsPage_vtbl *)&CDebugOptionsPage::`vftable';
  this->m_LayoutItems.m_Memory.m_pMemory = nullptr;
  this->m_LayoutItems.m_Memory.m_nAllocationCount = 0;
  this->m_LayoutItems.m_Memory.m_nGrowSize = 0;
  this->m_LayoutItems.m_Size = 0;
  this->m_LayoutItems.m_pElements = nullptr;
  g_pVGui->AddTickSignal(this: g_pVGui, a2: this->_vpanel, a3: 250);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1020AB20
// Name: public: static char const __near * vgui::PropertyPage::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::PropertyPage::GetPanelClassName()
{
  return "PropertyPage";
}

//------------------------------------------------------------------------------
// Address: 0x1020AB30
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::PropertyPage::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::PropertyPage::GetMessageMap(vgui::PropertyPage *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::PropertyPage::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::PropertyPage::GetMessageMap'::`2'::s_pMap;
  `vgui::PropertyPage::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "PropertyPage");
  `vgui::PropertyPage::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1020AB60
// Name: public: virtual struct PanelAnimationMap __near * vgui::PropertyPage::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::PropertyPage::GetAnimMap(vgui::PropertyPage *this)
{
  return FindOrAddPanelAnimationMap(className: "PropertyPage");
}

//------------------------------------------------------------------------------
// Address: 0x1020AB70
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::PropertyPage::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::PropertyPage::GetKBMap(vgui::PropertyPage *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::PropertyPage::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::PropertyPage::GetKBMap'::`2'::s_pMap;
  `vgui::PropertyPage::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "PropertyPage");
  `vgui::PropertyPage::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1020ABA0
// Name: public: virtual void CDebugOptionsPage::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDebugOptionsPage::OnTick(CDebugOptionsPage *this)
{
  int m_Size; // edi
  int i; // esi
  vgui::Panel *v4; // ecx

  CColorBalanceUIPanel::Init(this);
  if ( this->IsVisible(this) )
  {
    m_Size = this->m_LayoutItems.m_Size;
    for ( i = 0; i < m_Size; ++i )
    {
      v4 = this->m_LayoutItems.m_Memory.m_pMemory[i];
      v4->OnTick(this: v4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020ABF0
// Name: public: virtual void CDebugOptionsPage::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDebugOptionsPage::PerformLayout(CDebugOptionsPage *this)
{
  int v2; // esi
  int Tall; // eax
  int v4; // ebx
  int v5; // [esp+Ch] [ebp-Ch]
  int c; // [esp+10h] [ebp-8h]
  int x; // [esp+14h] [ebp-4h]

  vgui::EditablePanel::PerformLayout(this);
  v2 = 5;
  c = this->m_LayoutItems.m_Size;
  x = 5;
  Tall = vgui::Panel::GetTall(this);
  v4 = 0;
  if ( c > 0 )
  {
    v5 = Tall - 18;
    do
    {
      vgui::Panel::SetBounds(this: this->m_LayoutItems.m_Memory.m_pMemory[v4], x, y: v2, wide: 150, tall: 18);
      v2 += 20;
      if ( v2 >= v5 )
      {
        x += 152;
        v2 = 5;
      }
      ++v4;
    }
    while ( v4 < c );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020AC60
// Name: public: void CDebugOptionsPage::Init(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDebugOptionsPage::Init(CDebugOptionsPage *this, KeyValues *kv)
{
  KeyValues *FirstSubKey; // ebx
  const char *String; // eax
  const char *v4; // edi
  vgui::Button *v5; // esi
  const char *Name; // eax
  int m_Size; // esi
  int m_nAllocationCount; // eax
  vgui::Panel **m_pMemory; // ecx
  int v10; // eax
  vgui::Panel **v11; // eax
  const char *v12; // eax
  const char *v13; // edi
  vgui::CheckButton *v14; // esi
  const char *v15; // eax
  vgui::CheckButton *v16; // ebx
  int v17; // esi
  int v18; // eax
  vgui::Panel **v19; // ecx
  int v20; // eax
  vgui::Panel **v21; // eax
  const char *v22; // eax
  const char *v23; // esi
  CDebugIncrementCVarButton *v24; // edi
  const char *v25; // eax
  int v26; // edi
  int v27; // eax
  vgui::Panel **v28; // ecx
  int v29; // eax
  vgui::Panel **v30; // eax
  CDebugIncrementCVarButton *increment; // [esp+10h] [ebp+8h]
  CDebugIncrementCVarButton *incrementa; // [esp+10h] [ebp+8h]
  CDebugIncrementCVarButton *incrementb; // [esp+10h] [ebp+8h]

  FirstSubKey = KeyValues::GetFirstSubKey(this: kv);
  increment = (CDebugIncrementCVarButton *)FirstSubKey;
  if ( FirstSubKey != nullptr )
  {
    while ( 1 )
    {
      String = KeyValues::GetString(this: FirstSubKey, keyName: "command", defaultValue: defaultValue);
      v4 = String;
      if ( String != nullptr && *String != 0 )
      {
        v5 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
        if ( v5 != nullptr )
        {
          Name = KeyValues::GetName(this: FirstSubKey);
          vgui::Button::Button(
            this: v5,
            parent: this,
            panelName: "CommandButton",
            text: Name,
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
          v5->__vftable = (vgui::Button_vtbl *)&CDebugCommandButton::`vftable';
          vgui::Panel::AddActionSignalTarget(this: v5, messageTarget: v5);
          vgui::Button::SetCommand(this: v5, command: v4);
          incrementa = (CDebugIncrementCVarButton *)v5;
        }
        else
        {
          incrementa = nullptr;
        }
        m_Size = this->m_LayoutItems.m_Size;
        m_nAllocationCount = this->m_LayoutItems.m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<INetMessage *,int>::Grow(
            this: (CUtlMemory<S3RGBA,int> *)&this->m_LayoutItems,
            num: m_Size - m_nAllocationCount + 1);
        ++this->m_LayoutItems.m_Size;
        m_pMemory = this->m_LayoutItems.m_Memory.m_pMemory;
        v10 = this->m_LayoutItems.m_Size - m_Size - 1;
        this->m_LayoutItems.m_pElements = m_pMemory;
        if ( v10 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v10);
        v11 = &this->m_LayoutItems.m_Memory.m_pMemory[m_Size];
        if ( v11 != nullptr )
          *v11 = incrementa;
      }
      else
      {
        v12 = KeyValues::GetString(this: FirstSubKey, keyName: "togglecvar", defaultValue: defaultValue);
        v13 = v12;
        if ( v12 != nullptr && *v12 != 0 )
        {
          v14 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x21Cu);
          if ( v14 != nullptr )
          {
            v15 = KeyValues::GetName(this: FirstSubKey);
            vgui::CheckButton::CheckButton(this: v14, parent: this, panelName: "CommandCheck", text: v15);
            v14->__vftable = (vgui::CheckButton_vtbl *)&CDebugCommandCheckbox::`vftable';
            v14[1].__vftable = (vgui::CheckButton_vtbl *)g_pCVar->FindVar_2(this: g_pCVar, a2: v13);
            vgui::Button::SetCommand(this: v14, command: v13);
            vgui::Panel::AddActionSignalTarget(this: v14, messageTarget: v14);
            v16 = v14;
          }
          else
          {
            v16 = nullptr;
          }
          v17 = this->m_LayoutItems.m_Size;
          v18 = this->m_LayoutItems.m_Memory.m_nAllocationCount;
          if ( v17 + 1 > v18 )
            CUtlMemory<INetMessage *,int>::Grow(
              this: (CUtlMemory<S3RGBA,int> *)&this->m_LayoutItems,
              num: v17 - v18 + 1);
          ++this->m_LayoutItems.m_Size;
          v19 = this->m_LayoutItems.m_Memory.m_pMemory;
          v20 = this->m_LayoutItems.m_Size - v17 - 1;
          this->m_LayoutItems.m_pElements = v19;
          if ( v20 > 0 )
            _V_memmove(dest: &v19[v17 + 1], src: &v19[v17], count: 4 * v20);
          v21 = &this->m_LayoutItems.m_Memory.m_pMemory[v17];
          if ( v21 != nullptr )
            *v21 = v16;
          FirstSubKey = (KeyValues *)increment;
        }
        else
        {
          v22 = KeyValues::GetString(this: FirstSubKey, keyName: "incrementcvar", defaultValue: defaultValue);
          v23 = v22;
          if ( v22 != nullptr && *v22 != 0 )
          {
            v24 = (CDebugIncrementCVarButton *)MemAlloc_Alloc(nSize: 0x208u);
            if ( v24 != nullptr )
            {
              v25 = KeyValues::GetName(this: FirstSubKey);
              incrementb = CDebugIncrementCVarButton::CDebugIncrementCVarButton(
                             this: v24,
                             pParent: this,
                             pPanelName: "IncrementCVar",
                             pLabelText: v25,
                             pCommand: v23);
            }
            else
            {
              incrementb = nullptr;
            }
            v26 = this->m_LayoutItems.m_Size;
            v27 = this->m_LayoutItems.m_Memory.m_nAllocationCount;
            if ( v26 + 1 > v27 )
              CUtlMemory<INetMessage *,int>::Grow(
                this: (CUtlMemory<S3RGBA,int> *)&this->m_LayoutItems,
                num: v26 - v27 + 1);
            ++this->m_LayoutItems.m_Size;
            v28 = this->m_LayoutItems.m_Memory.m_pMemory;
            v29 = this->m_LayoutItems.m_Size - v26 - 1;
            this->m_LayoutItems.m_pElements = v28;
            if ( v29 > 0 )
              _V_memmove(dest: &v28[v26 + 1], src: &v28[v26], count: 4 * v29);
            v30 = &this->m_LayoutItems.m_Memory.m_pMemory[v26];
            if ( v30 != nullptr )
              *v30 = incrementb;
          }
        }
      }
      increment = (CDebugIncrementCVarButton *)KeyValues::GetNextKey(this: FirstSubKey);
      if ( increment == nullptr )
        break;
      FirstSubKey = (KeyValues *)increment;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020AF70
// Name: public: CDebugOptionsPanel::CDebugOptionsPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDebugOptionsPanel *__thiscall CDebugOptionsPanel::CDebugOptionsPanel(
        CDebugOptionsPanel *this,
        vgui::Panel *parent,
        KeyValues *panelName)
{
  KeyValues *v4; // eax
  KeyValues *v5; // ebx
  IBaseFileSystem *v6; // eax
  KeyValues *i; // edi
  const char *Name; // eax
  int v9; // eax
  const char *v10; // eax
  int Int; // eax
  CDebugOptionsPage *v12; // ebx
  const char *v13; // eax
  CDebugOptionsPage *v14; // ebx
  const char *v15; // eax
  vgui::PropertySheet *Font; // eax
  int v17; // edi
  int v18; // eax
  KeyValues *kv; // [esp+14h] [ebp+Ch]

  vgui::PropertyDialog::PropertyDialog(this, parent, (const char *)panelName);
  this->__vftable = (CDebugOptionsPanel_vtbl *)&CDebugOptionsPanel::`vftable';
  vgui::Frame::SetTitle(this, title: "Debug Options", surfaceTitle: true);
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
  {
    v5 = KeyValues::KeyValues(this: v4, setName: "DebugOptions");
    kv = v5;
    if ( v5 != nullptr )
    {
      if ( g_pFullFileSystem != nullptr )
        v6 = &g_pFullFileSystem->IBaseFileSystem;
      else
        v6 = nullptr;
      if ( KeyValues::LoadFromFile(
             this: v5,
             filesystem: v6,
             resourceName: "scripts/DebugOptions.txt",
             pathID: nullptr,
             pfnEvaluateSymbolProc: nullptr) )
      {
        for ( i = KeyValues::GetFirstSubKey(this: v5); i != nullptr; i = KeyValues::GetNextKey(this: i) )
        {
          Name = KeyValues::GetName(this: i);
          if ( V_strcasecmp(s1: Name, s2: "width") != 0 )
          {
            v10 = KeyValues::GetName(this: i);
            if ( V_strcasecmp(s1: v10, s2: "height") != 0 )
            {
              v12 = (CDebugOptionsPage *)MemAlloc_Alloc(nSize: 0x19Cu);
              if ( v12 != nullptr )
              {
                v13 = KeyValues::GetName(this: i);
                v14 = CDebugOptionsPage::CDebugOptionsPage(this: v12, parent: this, panelName: v13);
              }
              else
              {
                v14 = nullptr;
              }
              CDebugOptionsPage::Init(this: v14, kv: i);
              v15 = KeyValues::GetName(this: i);
              vgui::PropertyDialog::AddPage(this, page: v14, title: v15);
              v5 = kv;
            }
            else
            {
              Int = KeyValues::GetInt(this: i, keyName: nullptr, defaultValue: 0);
              vgui::Panel::SetTall(this, tall: Int);
            }
          }
          else
          {
            v9 = KeyValues::GetInt(this: i, keyName: nullptr, defaultValue: 0);
            vgui::Panel::SetWide(this, wide: v9);
          }
        }
      }
      KeyValues::deleteThis(this: v5);
    }
  }
  Font = CRenderTextureEditor::GetFont(this);
  ((void (__thiscall *)(vgui::PropertySheet *))Font->SetTabWidth)(a1: Font);
  v17 = -10 - vgui::Panel::GetWide(this);
  v18 = ((int (__thiscall *)(IVideoMode *, int))videomode->GetModeWidth)(a1: videomode, a2: 10);
  vgui::Panel::SetPos(this, x: v17 + v18, y: 72);
  vgui::Panel::SetVisible(this, state: true);
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "resource\\DebugOptionsPanel.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1020B120
// Name: public: static char const __near * vgui::PropertyDialog::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::PropertyDialog::GetPanelClassName()
{
  return "PropertyDialog";
}

//------------------------------------------------------------------------------
// Address: 0x1020B130
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::PropertyDialog::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::PropertyDialog::GetMessageMap(vgui::PropertyDialog *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::PropertyDialog::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::PropertyDialog::GetMessageMap'::`2'::s_pMap;
  `vgui::PropertyDialog::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "PropertyDialog");
  `vgui::PropertyDialog::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1020B160
// Name: public: virtual struct PanelAnimationMap __near * vgui::PropertyDialog::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::PropertyDialog::GetAnimMap(vgui::PropertyDialog *this)
{
  return FindOrAddPanelAnimationMap(className: "PropertyDialog");
}

//------------------------------------------------------------------------------
// Address: 0x1020B170
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::PropertyDialog::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::PropertyDialog::GetKBMap(vgui::PropertyDialog *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::PropertyDialog::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::PropertyDialog::GetKBMap'::`2'::s_pMap;
  `vgui::PropertyDialog::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "PropertyDialog");
  `vgui::PropertyDialog::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1020B1D0
// Name: public: CDebugSystemPanel::CDebugSystemPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDebugSystemPanel *__thiscall CDebugSystemPanel::CDebugSystemPanel(
        CDebugSystemPanel *this,
        vgui::Panel *parent,
        const char *panelName)
{
  int v4; // eax
  CDebugMenuButton *v5; // eax
  CDebugMenuButton *v6; // eax
  CDebugOptionsPanel *v7; // eax
  CDebugOptionsPanel *v8; // eax
  int v10; // [esp-4h] [ebp-Ch]

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (CDebugSystemPanel_vtbl *)&CDebugSystemPanel::`vftable';
  this->m_hDebugOptions.m_iPanelID = -1;
  v10 = videomode->GetModeHeight(this: videomode);
  v4 = videomode->GetModeWidth(this: videomode);
  vgui::Panel::SetBounds(this, x: 0, y: 0, wide: v4, tall: v10);
  vgui::Panel::SetCursor(this, cursor: 2u);
  vgui::Panel::SetVisible(this, state: false);
  vgui::Panel::SetPaintEnabled(this, state: false);
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  v5 = (CDebugMenuButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v5 != nullptr )
    v6 = CDebugMenuButton::CDebugMenuButton(this: v5, parent: this, panelName: "Debug Menu", text: "Debug Menu");
  else
    v6 = nullptr;
  this->m_pDebugMenu = v6;
  vgui::Panel::SetPos(this: v6, x: 0, y: 0);
  vgui::Panel::SetSize(this: this->m_pDebugMenu, wide: 110, tall: 24);
  v7 = (CDebugOptionsPanel *)MemAlloc_Alloc(nSize: 0x22Cu);
  if ( v7 != nullptr )
  {
    v8 = CDebugOptionsPanel::CDebugOptionsPanel(this: v7, parent: this, panelName: (KeyValues *)"DebugOptions");
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(
      this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_hDebugOptions,
      pPanel: (CDragDropHelperPanel *)v8);
  }
  else
  {
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(
      this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_hDebugOptions,
      pPanel: nullptr);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102A3750
// Name: protected: virtual class vgui::IBorder __near * vgui::Button::GetBorder(bool,bool,bool,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::IBorder *__thiscall vgui::Button::GetBorder(
        vgui::Button *this,
        bool depressed,
        bool armed,
        bool selected,
        bool keyfocus)
{
  if ( (this->_buttonFlags.m_nFlags & 8) != 0 )
  {
    if ( depressed )
      return this->_depressedBorder;
    if ( keyfocus || this->IsEnabled(this) && (this->_buttonFlags.m_nFlags & 0x40) != 0 )
      return this->_keyFocusBorder;
  }
  else if ( depressed )
  {
    return this->_depressedBorder;
  }
  return this->_defaultBorder;
}

//------------------------------------------------------------------------------
// Address: 0x102D2520
// Name: public: virtual class vgui::Panel __near * vgui::PropertyDialog::GetActivePage(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::PropertyDialog::GetActivePage(vgui::PropertyDialog *this)
{
  return this->_propertySheet->GetActivePage(this: this->_propertySheet);
}

} // namespace engine_xlsp
