// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/cl_txviewpanel.cpp
// Functions: 10
// ============================================================

#include "engine\cl_txviewpanel.h"

//------------------------------------------------------------------------------
// Address: 0x1009BCD0
// Name: public: static char const __near * TxViewPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl TxViewPanel::GetPanelClassName()
{
  return "TxViewPanel";
}

//------------------------------------------------------------------------------
// Address: 0x1009BCE0
// Name: public: virtual void TxViewPanel::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TxViewPanel::OnTick(TxViewPanel *this)
{
  CColorBalanceUIPanel::Init((vgui::PropertyPage *)this);
  this->IsVisible(this);
}

//------------------------------------------------------------------------------
// Address: 0x1009BD00
// Name: public: virtual void TxViewPanel::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TxViewPanel::OnCommand(TxViewPanel *this, const char *command)
{
  if ( V_strcasecmp(s1: command, s2: "refresh") != 0 )
    vgui::Frame::OnCommand(this, command);
}

//------------------------------------------------------------------------------
// Address: 0x1009BD30
// Name: public: virtual void TxViewPanel::OnMessage(class KeyValues const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TxViewPanel::OnMessage(TxViewPanel *this, KeyValues *params, const KeyValues *fromPanel)
{
  vgui::Panel::OnMessage(this, params, ifromPanel: fromPanel);
}

//------------------------------------------------------------------------------
// Address: 0x1009BD40
// Name: public: virtual struct vgui::PanelMessageMap __near * TxViewPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall TxViewPanel::GetMessageMap(TxViewPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`TxViewPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `TxViewPanel::GetMessageMap'::`2'::s_pMap;
  `TxViewPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "TxViewPanel");
  `TxViewPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1009BD70
// Name: public: virtual struct PanelAnimationMap __near * TxViewPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall TxViewPanel::GetAnimMap(TxViewPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "TxViewPanel");
}

//------------------------------------------------------------------------------
// Address: 0x1009BD80
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * TxViewPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall TxViewPanel::GetKBMap(TxViewPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`TxViewPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `TxViewPanel::GetKBMap'::`2'::s_pMap;
  `TxViewPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "TxViewPanel");
  `TxViewPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1009BDE0
// Name: public: static void TxViewPanel::PanelMessageFunc_OnFileSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall TxViewPanel::PanelMessageFunc_OnFileSelected::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // [esp-68h] [ebp-74h]
  VMatrix v3; // [esp-50h] [ebp-5Ch] BYREF
  int v4; // [esp-4h] [ebp-10h]
  int v5; // [esp+0h] [ebp-Ch]
  void *v6; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v5 = a1;
  v6 = retaddr;
  if ( !`TxViewPanel::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded )
  {
    `TxViewPanel::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded = true;
    v4 = 0;
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "TxViewPanel");
    *(_QWORD *)&v3.m[2][0] = 0x100000001LL;
    memset(&v3.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v3.m[0][0]) = "FileSelected";
    LODWORD(v3.m[1][0]) =  __thiscall vgui::FileOpenDialog::`vcall'{1116,{flat}};
    memset(&v3.m[1][1], 0, 12);
    LODWORD(v3.m[2][2]) = "fullpath";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009BE80
// Name: public: TxViewPanel::TxViewPanel(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
TxViewPanel *__thiscall TxViewPanel::TxViewPanel(TxViewPanel *this, vgui::Panel *parent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  vgui::Button *v6; // eax
  vgui::Button *v7; // eax
  vgui::ListViewPanel *v8; // eax
  vgui::ListViewPanel *v9; // eax

  vgui::Frame::Frame(this, parent, panelName: "TxViewPanel", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (TxViewPanel_vtbl *)&TxViewPanel::`vftable';
  if ( `TxViewPanel::ChainToMap'::`2'::chained == 0 )
  {
    `TxViewPanel::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "TxViewPanel");
    v3->pfnClassName = TxViewPanel::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `TxViewPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `TxViewPanel::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "TxViewPanel");
    v4->pfnClassName = TxViewPanel::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `TxViewPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `TxViewPanel::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "TxViewPanel");
    v5->pfnClassName = TxViewPanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  TxViewPanel::PanelMessageFunc_OnFileSelected::InitVar();
  v6 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v6 != nullptr )
    v7 = vgui::Button::Button(
           this: v6,
           parent: this,
           panelName: "Refresh",
           text: "Refresh",
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v7 = nullptr;
  this->m_pRefresh = v7;
  v8 = (vgui::ListViewPanel *)MemAlloc_Alloc(nSize: 0x1C8u);
  if ( v8 != nullptr )
    v9 = vgui::ListViewPanel::ListViewPanel(this: v8, parent: this, panelName: "Textures");
  else
    v9 = nullptr;
  this->m_pView = v9;
  g_pVGui->AddTickSignal(this: g_pVGui, a2: this->_vpanel, a3: 0);
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "Resource\\TxViewPanel.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  vgui::Panel::SetVisible(this, state: 0);
  vgui::Frame::SetSizeable(this, state: true);
  vgui::Frame::SetMoveable(this, state: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1009BFE0
// Name: public: static void TxViewPanel::Install(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TxViewPanel::Install(vgui::Panel *parent)
{
  TxViewPanel *v1; // eax

  if ( g_pTxViewPanel == nullptr )
  {
    v1 = (TxViewPanel *)MemAlloc_Alloc(nSize: 0x21Cu);
    if ( v1 != nullptr )
      g_pTxViewPanel = TxViewPanel::TxViewPanel(this: v1, parent);
    else
      g_pTxViewPanel = nullptr;
  }
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1009B9C0
// Name: public: static char const __near * TxViewPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl TxViewPanel::GetPanelClassName()
{
  return "TxViewPanel";
}

//------------------------------------------------------------------------------
// Address: 0x1009B9D0
// Name: public: virtual void TxViewPanel::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TxViewPanel::OnTick(TxViewPanel *this)
{
  CColorBalanceUIPanel::Init((vgui::PropertyPage *)this);
  this->IsVisible(this);
}

//------------------------------------------------------------------------------
// Address: 0x1009B9F0
// Name: public: virtual void TxViewPanel::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TxViewPanel::OnCommand(TxViewPanel *this, const char *command)
{
  if ( V_strcasecmp(s1: command, s2: "refresh") != 0 )
    vgui::Frame::OnCommand(this, command);
}

//------------------------------------------------------------------------------
// Address: 0x1009BA20
// Name: public: virtual void TxViewPanel::OnMessage(class KeyValues const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TxViewPanel::OnMessage(TxViewPanel *this, const KeyValues *params, unsigned int fromPanel)
{
  vgui::Panel::OnMessage(this, params, ifromPanel: fromPanel);
}

//------------------------------------------------------------------------------
// Address: 0x1009BA30
// Name: public: virtual struct vgui::PanelMessageMap __near * TxViewPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall TxViewPanel::GetMessageMap(TxViewPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`TxViewPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `TxViewPanel::GetMessageMap'::`2'::s_pMap;
  `TxViewPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "TxViewPanel");
  `TxViewPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1009BA60
// Name: public: virtual struct PanelAnimationMap __near * TxViewPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall TxViewPanel::GetAnimMap(TxViewPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "TxViewPanel");
}

//------------------------------------------------------------------------------
// Address: 0x1009BA70
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * TxViewPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall TxViewPanel::GetKBMap(TxViewPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`TxViewPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `TxViewPanel::GetKBMap'::`2'::s_pMap;
  `TxViewPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "TxViewPanel");
  `TxViewPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1009BAD0
// Name: public: static void TxViewPanel::PanelMessageFunc_OnFileSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall TxViewPanel::PanelMessageFunc_OnFileSelected::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // [esp-68h] [ebp-74h]
  VMatrix v3; // [esp-50h] [ebp-5Ch] BYREF
  int v4; // [esp-4h] [ebp-10h]
  int v5; // [esp+0h] [ebp-Ch]
  void *v6; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v5 = a1;
  v6 = retaddr;
  if ( !`TxViewPanel::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded )
  {
    `TxViewPanel::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded = true;
    v4 = 0;
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "TxViewPanel");
    *(_QWORD *)&v3.m[2][0] = 0x100000001LL;
    memset(&v3.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v3.m[0][0]) = "FileSelected";
    LODWORD(v3.m[1][0]) =  __thiscall vgui::FileOpenDialog::`vcall'{1116,{flat}};
    memset(&v3.m[1][1], 0, 12);
    LODWORD(v3.m[2][2]) = "fullpath";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009BB70
// Name: public: TxViewPanel::TxViewPanel(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
TxViewPanel *__thiscall TxViewPanel::TxViewPanel(TxViewPanel *this, vgui::Panel *parent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  vgui::Button *v6; // eax
  vgui::Button *v7; // eax
  vgui::ListViewPanel *v8; // eax
  vgui::ListViewPanel *v9; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Frame::Frame(this, parent, panelName: "TxViewPanel", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (TxViewPanel_vtbl *)&TxViewPanel::`vftable';
  if ( `TxViewPanel::ChainToMap'::`2'::chained == 0 )
  {
    `TxViewPanel::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "TxViewPanel");
    v3->pfnClassName = TxViewPanel::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `TxViewPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `TxViewPanel::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "TxViewPanel");
    v4->pfnClassName = TxViewPanel::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `TxViewPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `TxViewPanel::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "TxViewPanel");
    v5->pfnClassName = TxViewPanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  TxViewPanel::PanelMessageFunc_OnFileSelected::InitVar(a1: (int)&savedregs);
  v6 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v6 != nullptr )
    v7 = vgui::Button::Button(
           this: v6,
           parent: this,
           panelName: "Refresh",
           text: "Refresh",
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v7 = nullptr;
  this->m_pRefresh = v7;
  v8 = (vgui::ListViewPanel *)MemAlloc_Alloc(nSize: 0x1C8u);
  if ( v8 != nullptr )
    v9 = vgui::ListViewPanel::ListViewPanel(this: v8, parent: this, panelName: "Textures");
  else
    v9 = nullptr;
  this->m_pView = v9;
  g_pVGui->AddTickSignal(this: g_pVGui, a2: this->_vpanel, a3: 0);
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "Resource\\TxViewPanel.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  vgui::Panel::SetVisible(this, state: false);
  vgui::Frame::SetSizeable(this, state: true);
  vgui::Frame::SetMoveable(this, state: true);
  return this;
}

} // namespace engine_xlsp
