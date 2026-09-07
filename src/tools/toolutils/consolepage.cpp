// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tools/toolutils/consolepage.cpp
// Functions: 7
// ============================================================

#include "tools\toolutils\consolepage.h"

//------------------------------------------------------------------------------
// Address: 0x102C3AD0
// Name: public: static char const __near * CConsolePage::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CConsolePage::GetPanelClassName()
{
  return "CConsolePage";
}

//------------------------------------------------------------------------------
// Address: 0x102C3B00
// Name: private: virtual void CConsolePage::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CConsolePage::ApplySchemeSettings(CConsolePage *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi

  v2 = pScheme;
  vgui::CConsolePanel::ApplySchemeSettings(this, pScheme);
  this->m_PrintColor = *this->GetSchemeColor_2(this, result: &pScheme, a3: "IFMConsole.TextColor", a4: v2);
  this->m_DPrintColor = *this->GetSchemeColor_2(this, result: &pScheme, a3: "IFMConsole.DevTextColor", a4: v2);
}

//------------------------------------------------------------------------------
// Address: 0x102C3B60
// Name: public: static void CConsolePage::PanelMessageFunc_OnCommandSubmitted::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CConsolePage::PanelMessageFunc_OnCommandSubmitted::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CConsolePage::PanelMessageFunc_OnCommandSubmitted::InitVar'::`2'::bAdded )
  {
    `CConsolePage::PanelMessageFunc_OnCommandSubmitted::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CColorPickerPanel::`vcall'{956,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CConsolePage");
    v2 = _mm_load_si128(&v5);
    *(_QWORD *)&v4.m[2][0] = 0x100000001LL;
    memset(&v4.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "CommandSubmitted";
    *(__m128i *)&v4.m[1][0] = v2;
    LODWORD(v4.m[2][2]) = "command";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C3C00
// Name: public: CConsolePage::CConsolePage(class vgui::Panel __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CConsolePage *__thiscall CConsolePage::CConsolePage(CConsolePage *this, vgui::Panel *parent, bool bStatusVersion)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::CConsolePanel::CConsolePanel(this, pParent: parent, pName: "ToolsConsole", bStatusVersion);
  this->vgui::CConsolePanel::vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CConsolePage_vtbl *)&CConsolePage::`vftable'{for `vgui::EditablePanel'};
  this->vgui::CConsolePanel::IConsoleDisplayFunc::__vftable = (IConsoleDisplayFunc_vtbl *)&CConsolePage::`vftable'{for `IConsoleDisplayFunc'};
  if ( `CConsolePage::ChainToMap'::`2'::chained == 0 )
  {
    `CConsolePage::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CConsolePage");
    v4->pfnClassName = CConsolePage::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::CConsolePanel");
  }
  if ( `CConsolePage::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CConsolePage::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CConsolePage");
    v5->pfnClassName = CConsolePage::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::CConsolePanel");
  }
  if ( `CConsolePage::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CConsolePage::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CConsolePage");
    v6->pfnClassName = CConsolePage::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::CConsolePanel");
  }
  CConsolePage::PanelMessageFunc_OnCommandSubmitted::InitVar(a1: (int)&savedregs);
  vgui::Panel::AddActionSignalTarget(this, messageTarget: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102C3CE0
// Name: public: virtual struct vgui::PanelMessageMap __near * CConsolePage::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CConsolePage::GetMessageMap(CConsolePage *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CConsolePage::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CConsolePage::GetMessageMap'::`2'::s_pMap;
  `CConsolePage::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CConsolePage");
  `CConsolePage::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C3D10
// Name: public: virtual struct PanelAnimationMap __near * CConsolePage::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CConsolePage::GetAnimMap(CConsolePage *this)
{
  return FindOrAddPanelAnimationMap(className: "CConsolePage");
}

//------------------------------------------------------------------------------
// Address: 0x102C3D20
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CConsolePage::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CConsolePage::GetKBMap(CConsolePage *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CConsolePage::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CConsolePage::GetKBMap'::`2'::s_pMap;
  `CConsolePage::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CConsolePage");
  `CConsolePage::GetKBMap'::`2'::s_pMap = result;
  return result;
}
