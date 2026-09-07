// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tracker/adminserver/dialogaddban.cpp
// Functions: 14
// ============================================================

#include "tracker\adminserver\dialogaddban.h"

//------------------------------------------------------------------------------
// Address: 0x10001700
// Name: private: virtual void CDialogAddBan::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CDialogAddBan::PerformLayout(CGamePanelInfo *this)
{
  vgui::Frame::PerformLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x10007DF0
// Name: public: static char const __near * CDialogAddBan::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CDialogAddBan::GetPanelClassName()
{
  return "CDialogAddBan";
}

//------------------------------------------------------------------------------
// Address: 0x10007E00
// Name: public: bool CDialogAddBan::IsIPCheck(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDialogAddBan::IsIPCheck(CDialogAddBan *this)
{
  int v1; // edi
  unsigned int v2; // ecx
  unsigned int v3; // kr00_4
  char buf[64]; // [esp+8h] [ebp-40h] BYREF

  v1 = 0;
  this->m_pIDTextEntry->GetText_2(this: this->m_pIDTextEntry, a2: buf, a3: 63);
  v2 = 0;
  v3 = strlen(buf);
  if ( v3 == 0 )
    return false;
  do
  {
    if ( buf[v2] == 46 )
      ++v1;
    ++v2;
  }
  while ( v2 < v3 );
  return v1 > 0;
}

//------------------------------------------------------------------------------
// Address: 0x10007E60
// Name: private: virtual void CDialogAddBan::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDialogAddBan::OnCommand(CDialogAddBan *this, float command)
{
  const char *v2; // edi
  KeyValues *v4; // eax
  KeyValues *v5; // edi
  vgui::MessageBox *v6; // eax
  vgui::MessageBox *v7; // eax
  vgui::MessageBox *v8; // eax
  vgui::MessageBox *v9; // eax
  float value; // xmm0_4
  int v11; // eax
  int v12; // eax
  vgui::MessageBox *v13; // eax
  vgui::MessageBox *v14; // eax
  bool IsIPCheck; // al
  char idbuf[64]; // [esp+28h] [ebp-80h] BYREF
  char buf[64]; // [esp+68h] [ebp-40h] BYREF

  v2 = (const char *)LODWORD(command);
  if ( _V_stricmp(s1: (const char *)LODWORD(command), s2: "Okay") != 0 )
  {
    if ( _V_stricmp(s1: v2, s2: "Close") != 0 )
    {
      vgui::Frame::OnCommand(this, command: v2);
      return;
    }
    goto LABEL_28;
  }
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "AddBanValue");
  else
    v5 = nullptr;
  this->m_pIDTextEntry->GetText_2(this: this->m_pIDTextEntry, a2: idbuf, a3: 64);
  this->m_pTimeTextEntry->GetText_2(this: this->m_pTimeTextEntry, a2: buf, a3: 64);
  if ( strlen(idbuf) == 0 )
  {
    v6 = (vgui::MessageBox *)operator new(nSize: 0x234u);
    if ( v6 != nullptr )
    {
      v7 = vgui::MessageBox::MessageBox(this: v6, title: "#Add_Ban_Error", text: "#Add_Ban_ID_Invalid", parent: nullptr);
      v7->DoModal_2(this: v7, a2: nullptr);
      return;
    }
    goto LABEL_8;
  }
  if ( strlen(buf) == 0 && !this->m_pPermBanRadio->IsSelected(this: this->m_pPermBanRadio) )
  {
    v9 = (vgui::MessageBox *)operator new(nSize: 0x234u);
    if ( v9 != nullptr )
    {
      v8 = vgui::MessageBox::MessageBox(this: v9, title: "#Add_Ban_Error", text: "#Add_Ban_Time_Empty", parent: nullptr);
      goto LABEL_9;
    }
LABEL_8:
    v8 = nullptr;
LABEL_9:
    v8->DoModal_2(this: v8, a2: nullptr);
    return;
  }
  if ( this->m_pPermBanRadio->IsSelected(this: this->m_pPermBanRadio) )
  {
    value = 0.0;
    command = 0.0;
LABEL_27:
    KeyValues::SetFloat(this: v5, keyName: "time", value);
    KeyValues::SetString(this: v5, keyName: "id", value: idbuf);
    KeyValues::SetString(this: v5, keyName: "type", value: this->m_cType);
    IsIPCheck = CDialogAddBan::IsIPCheck(this);
    KeyValues::SetInt(this: v5, keyName: "ipcheck", value: IsIPCheck);
    this->PostActionSignal(this, a2: v5);
LABEL_28:
    this->Close(this);
    return;
  }
  sscanf(string: buf, format: "%f", &command);
  this->m_pTimeCombo->GetText_2(this: this->m_pTimeCombo, a2: buf, a3: 64);
  strstr(str1: (unsigned __int8 *)buf, str2: "hour");
  if ( v11 != 0 )
  {
    value = command * 60.0;
  }
  else
  {
    strstr(str1: (unsigned __int8 *)buf, str2: "day");
    value = command;
    if ( v12 == 0 )
      goto LABEL_21;
    value = command * 1440.0;
  }
  command = value;
LABEL_21:
  if ( value < 0.0 )
  {
    v13 = (vgui::MessageBox *)operator new(nSize: 0x234u);
    if ( v13 != nullptr )
      v14 = vgui::MessageBox::MessageBox(
              this: v13,
              title: "#Add_Ban_Error",
              text: "#Add_Ban_Time_Invalid",
              parent: nullptr);
    else
      v14 = nullptr;
    v14->DoModal_2(this: v14, a2: nullptr);
    value = command;
  }
  if ( value >= 0.0 )
    goto LABEL_27;
}

//------------------------------------------------------------------------------
// Address: 0x10008120
// Name: private: virtual void CDialogAddBan::OnButtonToggled(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDialogAddBan::OnButtonToggled(CDialogAddBan *this, vgui::RadioButton *panel)
{
  void (__thiscall *SetEnabled)(vgui::Panel *, bool); // eax
  int v4; // [esp+0h] [ebp-4h]

  SetEnabled = this->m_pTimeTextEntry->SetEnabled;
  if ( panel == this->m_pPermBanRadio )
  {
    ((void (__stdcall *)(_DWORD, int))SetEnabled)(a1: 0, a2: v4);
    this->m_pTimeCombo->SetEnabled(this: this->m_pTimeCombo, a2: false);
  }
  else
  {
    ((void (__stdcall *)(int, int))SetEnabled)(a1: 1, a2: v4);
    this->m_pTimeCombo->SetEnabled(this: this->m_pTimeCombo, a2: true);
  }
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x10008170
// Name: public: virtual struct vgui::PanelMessageMap __near * CDialogAddBan::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CDialogAddBan::GetMessageMap(CDialogAddBan *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CDialogAddBan::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CDialogAddBan::GetMessageMap'::`2'::s_pMap;
  `CDialogAddBan::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CDialogAddBan");
  `CDialogAddBan::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100081A0
// Name: public: virtual struct PanelAnimationMap __near * CDialogAddBan::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CDialogAddBan::GetAnimMap(CDialogAddBan *this)
{
  return FindOrAddPanelAnimationMap(className: "CDialogAddBan");
}

//------------------------------------------------------------------------------
// Address: 0x100081B0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CDialogAddBan::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CDialogAddBan::GetKBMap(CDialogAddBan *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CDialogAddBan::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CDialogAddBan::GetKBMap'::`2'::s_pMap;
  `CDialogAddBan::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CDialogAddBan");
  `CDialogAddBan::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10008210
// Name: public: void CDialogAddBan::Activate(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDialogAddBan::Activate(CDialogAddBan *this, const char *type, const char *player, const char *authid)
{
  vgui::Button *m_pOkayButton; // ecx
  vgui::Panel *ChildByName; // eax
  void *v7; // eax
  vgui::Panel *v8; // eax
  void *v9; // eax

  m_pOkayButton = this->m_pOkayButton;
  this->m_cType = type;
  m_pOkayButton->SetAsDefaultButton(this: m_pOkayButton, a2: 1);
  vgui::Panel::MakePopup(this, showTaskbarIcon: true, disabled: false);
  this->MoveToFront(this);
  this->RequestFocus(this, a2: 0);
  this->m_pIDTextEntry->RequestFocus(this: this->m_pIDTextEntry, a2: 0);
  this->SetVisible(this, a2: true);
  ChildByName = vgui::Panel::FindChildByName(this, childName: "PlayerTextEntry", recurseDown: false);
  v7 = __RTDynamicCast(
         inptr: ChildByName,
         VfDelta: 0,
         SrcType: &vgui::Panel `RTTI Type Descriptor',
         TargetType: &vgui::TextEntry `RTTI Type Descriptor',
         isReference: 0);
  if ( v7 != nullptr )
    (*(void (__thiscall **)(void *, const char *))(*(_DWORD *)v7 + 844))(a1: v7, a2: player);
  v8 = vgui::Panel::FindChildByName(this, childName: "IDTextEntry", recurseDown: false);
  v9 = __RTDynamicCast(
         inptr: v8,
         VfDelta: 0,
         SrcType: &vgui::Panel `RTTI Type Descriptor',
         TargetType: &vgui::TextEntry `RTTI Type Descriptor',
         isReference: 0);
  if ( v9 != nullptr )
    (*(void (__thiscall **)(void *, const char *))(*(_DWORD *)v9 + 844))(a1: v9, a2: authid);
  vgui::Frame::Activate(this);
}

//------------------------------------------------------------------------------
// Address: 0x100082F0
// Name: public: static void CDialogAddBan::PanelMessageFunc_OnButtonToggled::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDialogAddBan::PanelMessageFunc_OnButtonToggled::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDialogAddBan::PanelMessageFunc_OnButtonToggled::InitVar'::`2'::bAdded )
  {
    `CDialogAddBan::PanelMessageFunc_OnButtonToggled::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenDialog::`vcall'{1116,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CDialogAddBan");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "RadioButtonChecked";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_PTR;
    v4.firstParamName = "panel";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10008390
// Name: public: CDialogAddBan::CDialogAddBan(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CDialogAddBan *__thiscall CDialogAddBan::CDialogAddBan(CDialogAddBan *this, vgui::Panel *parent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  vgui::TextEntry *v6; // eax
  vgui::TextEntry *v7; // eax
  vgui::Button *v8; // eax
  vgui::Button *v9; // eax
  vgui::RadioButton *v10; // eax
  vgui::RadioButton *v11; // eax
  vgui::RadioButton *v12; // eax
  vgui::RadioButton *v13; // eax
  vgui::RadioButton *m_pPermBanRadio; // ecx
  vgui::TextEntry *v15; // eax
  vgui::TextEntry *v16; // eax
  vgui::ComboBox *v17; // eax
  vgui::ComboBox *v18; // eax
  int v19; // edi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Frame::Frame(this, parent, panelName: "DialogAddBan", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CDialogAddBan_vtbl *)&CDialogAddBan::`vftable';
  if ( `CDialogAddBan::ChainToMap'::`2'::chained == 0 )
  {
    `CDialogAddBan::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CDialogAddBan");
    v3->pfnClassName = CDialogAddBan::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CDialogAddBan::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CDialogAddBan::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CDialogAddBan");
    v4->pfnClassName = CDialogAddBan::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CDialogAddBan::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CDialogAddBan::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CDialogAddBan");
    v5->pfnClassName = CDialogAddBan::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  CDialogAddBan::PanelMessageFunc_OnButtonToggled::InitVar(a1: (int)&savedregs);
  vgui::Panel::SetSize(this, wide: 320, tall: 200);
  vgui::Frame::SetTitle(this, title: "#Game_Ban_Add_Title", surfaceTitle: false);
  v6 = (vgui::TextEntry *)operator new(nSize: 0x43Cu);
  if ( v6 != nullptr )
    v7 = vgui::TextEntry::TextEntry(this: v6, parent: this, panelName: "IDTextEntry");
  else
    v7 = nullptr;
  this->m_pIDTextEntry = v7;
  v8 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v8 != nullptr )
    v9 = vgui::Button::Button(
           this: v8,
           parent: this,
           panelName: "OkayButton",
           text: "#Okay_Button",
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v9 = nullptr;
  this->m_pOkayButton = v9;
  v10 = (vgui::RadioButton *)operator new(nSize: 0x210u);
  if ( v10 != nullptr )
    v11 = vgui::RadioButton::RadioButton(
            this: v10,
            parent: this,
            panelName: "PermBanRadio",
            text: "#Add_Ban_Time_Permanent");
  else
    v11 = nullptr;
  this->m_pPermBanRadio = v11;
  v12 = (vgui::RadioButton *)operator new(nSize: 0x210u);
  if ( v12 != nullptr )
    v13 = vgui::RadioButton::RadioButton(
            this: v12,
            parent: this,
            panelName: "TempBanRadio",
            text: "#Add_Ban_Time_Temporary");
  else
    v13 = nullptr;
  m_pPermBanRadio = this->m_pPermBanRadio;
  this->m_pTempBanRadio = v13;
  m_pPermBanRadio->SetSelected(this: m_pPermBanRadio, a2: true);
  v15 = (vgui::TextEntry *)operator new(nSize: 0x43Cu);
  if ( v15 != nullptr )
    v16 = vgui::TextEntry::TextEntry(this: v15, parent: this, panelName: "TimeTextEntry");
  else
    v16 = nullptr;
  this->m_pTimeTextEntry = v16;
  v17 = (vgui::ComboBox *)operator new(nSize: 0x458u);
  if ( v17 != nullptr )
    v18 = vgui::ComboBox::ComboBox(this: v17, parent: this, panelName: "TimeCombo", numLines: 3, allowEdit: false);
  else
    v18 = nullptr;
  this->m_pTimeCombo = v18;
  v19 = v18->AddItem_2(this: v18, a2: "#Add_Ban_Period_Minutes", a3: nullptr);
  this->m_pTimeCombo->AddItem_2(this: this->m_pTimeCombo, a2: "#Add_Ban_Period_Hours", a3: nullptr);
  this->m_pTimeCombo->AddItem_2(this: this->m_pTimeCombo, a2: "#Add_Ban_Period_Days", a3: nullptr);
  this->m_pTimeCombo->ActivateItem(this: this->m_pTimeCombo, a2: v19);
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "Admin\\DialogAddBan.res",
    pathID: "PLATFORM",
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  vgui::Frame::SetTitle(this, title: "#Add_Ban_Title", surfaceTitle: true);
  vgui::Frame::SetSizeable(this, state: false);
  vgui::Frame::MoveToCenterOfScreen(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10035690
// Name: public: virtual class vgui::Panel __near * vgui::TextEntry::GetDragPanel(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::TextEntry::GetDragPanel(vgui::TextEntry *this)
{
  int v2; // edi
  int cx1; // [esp+4h] [ebp-10h] BYREF
  int cx0; // [esp+8h] [ebp-Ch] BYREF
  int x; // [esp+Ch] [ebp-8h] BYREF
  int y; // [esp+10h] [ebp-4h] BYREF

  if ( !g_pVGuiInput->IsMouseDown(this: g_pVGuiInput, a2: KEY_COUNT) )
    return vgui::Panel::GetDragPanel(this);
  g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: &y);
  vgui::Panel::ScreenToLocal(this, &x, &y);
  v2 = this->PixelToCursorSpace(this, a2: x, a3: y);
  if ( this->GetSelectedRange(this, a2: &cx0, a3: &cx1) && v2 >= cx0 && v2 < cx1 )
    return vgui::Panel::GetDragPanel(this);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10038EC0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::TextEntry::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::TextEntry::GetMessageMap(vgui::TextEntry *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::TextEntry::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::TextEntry::GetMessageMap'::`2'::s_pMap;
  `vgui::TextEntry::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "TextEntry");
  `vgui::TextEntry::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10038F00
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::TextEntry::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::TextEntry::GetKBMap(vgui::TextEntry *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::TextEntry::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::TextEntry::GetKBMap'::`2'::s_pMap;
  `vgui::TextEntry::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "TextEntry");
  `vgui::TextEntry::GetKBMap'::`2'::s_pMap = result;
  return result;
}
