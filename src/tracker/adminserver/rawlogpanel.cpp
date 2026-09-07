// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tracker/adminserver/rawlogpanel.cpp
// Functions: 9
// ============================================================

#include "tracker\adminserver\rawlogpanel.h"

//------------------------------------------------------------------------------
// Address: 0x1000A1D0
// Name: public: virtual void CRawLogPanel::OnPageHide(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CRawLogPanel::OnPageHide(vgui::ListViewPanel *this)
{
  vgui::PropertyPage::OnPageHide((vgui::PropertyPage *)this);
}

//------------------------------------------------------------------------------
// Address: 0x1000D1C0
// Name: public: static char const __near * CRawLogPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CRawLogPanel::GetPanelClassName()
{
  return "CRawLogPanel";
}

//------------------------------------------------------------------------------
// Address: 0x1000D1D0
// Name: public: void CRawLogPanel::DoInsertString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRawLogPanel::DoInsertString(CRawLogPanel *this, const char *str)
{
  if ( str != nullptr )
    this->m_pConsole->Print(this: &this->m_pConsole->IConsoleDisplayFunc, a2: str);
}

//------------------------------------------------------------------------------
// Address: 0x1000D200
// Name: private: virtual void CRawLogPanel::OnCommandSubmitted(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRawLogPanel::OnCommandSubmitted(CRawLogPanel *this, const char *pchCommand)
{
  CRemoteServer *v2; // eax

  if ( pchCommand != nullptr && *pchCommand != 0 )
  {
    v2 = RemoteServer();
    CRemoteServer::SendCommand(this: v2, commandString: pchCommand);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D220
// Name: public: virtual struct vgui::PanelMessageMap __near * CRawLogPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CRawLogPanel::GetMessageMap(CRawLogPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CRawLogPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CRawLogPanel::GetMessageMap'::`2'::s_pMap;
  `CRawLogPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CRawLogPanel");
  `CRawLogPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000D250
// Name: public: virtual struct PanelAnimationMap __near * CRawLogPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CRawLogPanel::GetAnimMap(CRawLogPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CRawLogPanel");
}

//------------------------------------------------------------------------------
// Address: 0x1000D260
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CRawLogPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CRawLogPanel::GetKBMap(CRawLogPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CRawLogPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CRawLogPanel::GetKBMap'::`2'::s_pMap;
  `CRawLogPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CRawLogPanel");
  `CRawLogPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000D2C0
// Name: public: static void CRawLogPanel::PanelMessageFunc_OnCommandSubmitted::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CRawLogPanel::PanelMessageFunc_OnCommandSubmitted::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  __int128 v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CRawLogPanel::PanelMessageFunc_OnCommandSubmitted::InitVar'::`2'::bAdded )
  {
    `CRawLogPanel::PanelMessageFunc_OnCommandSubmitted::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CRawLogPanel::`vcall'{964,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CRawLogPanel");
    v2 = (__int128)_mm_load_si128(&v5);
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_CONSTCHARPTR;
    memset(&v4.secondParamType, 0, 20);
    m_Size = v1->entries.m_Size;
    v4.name = "CommandSubmitted";
    v4.func = v2;
    v4.firstParamName = "command";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D360
// Name: public: CRawLogPanel::CRawLogPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CRawLogPanel *__thiscall CRawLogPanel::CRawLogPanel(CRawLogPanel *this, vgui::Panel *parent, const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::CConsolePanel *v7; // eax
  vgui::CConsolePanel *v8; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::PropertyPage::PropertyPage(this, parent, panelName: name);
  this->__vftable = (CRawLogPanel_vtbl *)&CRawLogPanel::`vftable';
  if ( `CRawLogPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CRawLogPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CRawLogPanel");
    v4->pfnClassName = CRawLogPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::PropertyPage");
  }
  if ( `CRawLogPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CRawLogPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CRawLogPanel");
    v5->pfnClassName = CRawLogPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::PropertyPage");
  }
  if ( `CRawLogPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CRawLogPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CRawLogPanel");
    v6->pfnClassName = CRawLogPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::PropertyPage");
  }
  CRawLogPanel::PanelMessageFunc_OnCommandSubmitted::InitVar(a1: (int)&savedregs);
  vgui::Panel::SetSize(this, wide: 200, tall: 100);
  v7 = (vgui::CConsolePanel *)operator new(nSize: 0x3D0u);
  if ( v7 != nullptr )
    v8 = vgui::CConsolePanel::CConsolePanel(this: v7, pParent: this, pName: "Console", bStatusVersion: false);
  else
    v8 = nullptr;
  this->m_pConsole = v8;
  vgui::EditablePanel::LoadControlSettings(
    this,
    resourceName: "Admin\\RawLogPanel.res",
    pathID: "PLATFORM",
    pKeyValues: nullptr,
    pConditions: nullptr);
  return this;
}
