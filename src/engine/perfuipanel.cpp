// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/perfuipanel.cpp
// Functions: 50
// ============================================================

#include "engine\perfuipanel.h"

//------------------------------------------------------------------------------
// Address: 0x100A1B20
// Name: public: virtual void CPerfUIPanel::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPerfUIPanel::OnKeyCodeTyped(CColorCorrectionUIPanel *this, ButtonCode_t code)
{
  if ( code == KEY_ESCAPE )
    this->Close(this);
  else
    vgui::Frame::OnKeyCodeTyped(this, code);
}

//------------------------------------------------------------------------------
// Address: 0x10202960
// Name: public: static char const __near * CPerfUIChildPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CPerfUIChildPanel::GetPanelClassName()
{
  return "CPerfUIChildPanel";
}

//------------------------------------------------------------------------------
// Address: 0x10202970
// Name: public: static char const __near * CPropFadeUIPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CPropFadeUIPanel::GetPanelClassName()
{
  return "CPropFadeUIPanel";
}

//------------------------------------------------------------------------------
// Address: 0x10202980
// Name: public: virtual void CPropFadeUIPanel::Activate(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CPropFadeUIPanel::Activate(CPropFadeUIPanel *this)
{
  int ActiveItem; // eax
  int v3; // eax
  unsigned int pDest[5]; // [esp+Ch] [ebp-108h] BYREF
  __int64 buf_236; // [esp+10Ch] [ebp-8h] OVERLAPPED BYREF

  modelinfoclient->GetLevelScreenFadeRange(
    this: modelinfoclient,
    a2: (float *)&buf_236,
    a3: (float *)((char *)&buf_236 + 4));
  V_snprintf((char *)pDest, maxLen: 256, pFormat: "%.2f", *(float *)&buf_236);
  this->m_pMinScreenArea->SetText(this: this->m_pMinScreenArea, a2: (const char *)pDest);
  V_snprintf((char *)pDest, maxLen: 256, pFormat: "%.2f", *((float *)&buf_236 + 1));
  this->m_pMaxScreenArea->SetText(this: this->m_pMaxScreenArea, a2: (const char *)pDest);
  ActiveItem = vgui::ComboBox::GetActiveItem(this: this->m_pVisualization);
  if ( ActiveItem != 0 )
  {
    v3 = ActiveItem - 1;
    if ( v3 != 0 )
    {
      if ( v3 == 1 )
        CLoaderMemAlloc::CrtIsValidPointer(
          this: (ConVar *)&r_staticpropinfo.IConVar,
          value: 4,
          a2: pDest[0],
          a3: pDest[1]);
    }
    else
    {
      CLoaderMemAlloc::CrtIsValidPointer(
        this: (ConVar *)&r_staticpropinfo.IConVar,
        value: 3,
        a2: pDest[0],
        a3: pDest[1]);
    }
  }
  else
  {
    CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&r_staticpropinfo.IConVar, value: 0, a2: pDest[0], a3: pDest[1]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10202A60
// Name: public: virtual void CPropFadeUIPanel::Deactivate(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall CPropFadeUIPanel::Deactivate(CPropFadeUIPanel *this)
{
  unsigned int v1; // [esp-8h] [ebp-8h]
  int v2; // [esp-4h] [ebp-4h]

  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&r_staticpropinfo.IConVar, value: 0, a2: v1, a3: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10202A70
// Name: public: static char const __near * CAreaPortalsUIPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAreaPortalsUIPanel::GetPanelClassName()
{
  return "CAreaPortalsUIPanel";
}

//------------------------------------------------------------------------------
// Address: 0x10202A80
// Name: public: virtual void CAreaPortalsUIPanel::Activate(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall CAreaPortalsUIPanel::Activate(CAreaPortalsUIPanel *this)
{
  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&r_DrawPortals.IConVar, value: 1);
  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&mat_wireframe.IConVar, value: 3);
}

//------------------------------------------------------------------------------
// Address: 0x10202AA0
// Name: public: virtual void CAreaPortalsUIPanel::Deactivate(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall CAreaPortalsUIPanel::Deactivate(CAreaPortalsUIPanel *this)
{
  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&r_DrawPortals.IConVar, value: 0);
  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&mat_wireframe.IConVar, value: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10202AC0
// Name: public: static char const __near * COcclusionUIPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl COcclusionUIPanel::GetPanelClassName()
{
  return "COcclusionUIPanel";
}

//------------------------------------------------------------------------------
// Address: 0x10202AD0
// Name: public: virtual void COcclusionUIPanel::Deactivate(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall COcclusionUIPanel::Deactivate(COcclusionUIPanel *this)
{
  unsigned int v1; // [esp-10h] [ebp-10h]
  int v2; // [esp-Ch] [ebp-Ch]
  unsigned int v3; // [esp-8h] [ebp-8h]
  int v4; // [esp-4h] [ebp-4h]

  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&r_visocclusion.IConVar, value: 0, a2: v1, a3: v2);
  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&mat_wireframe.IConVar, value: 0, a2: v3, a3: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10202AF0
// Name: protected: virtual void COcclusionUIPanel::OnCheckButtonChecked(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall COcclusionUIPanel::OnCheckButtonChecked(COcclusionUIPanel *this, vgui::CheckButton *panel)
{
  bool v2; // al
  unsigned int v3; // [esp-8h] [ebp-8h]
  int v4; // [esp-4h] [ebp-4h]

  if ( panel == this->m_pDeactivateOcclusion )
  {
    v2 = this->m_pDeactivateOcclusion->IsSelected(this: this->m_pDeactivateOcclusion);
    CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&r_occlusion.IConVar, value: !v2, a2: v3, a3: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10202B30
// Name: public: static char const __near * CPerfUIPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CPerfUIPanel::GetPanelClassName()
{
  return "CPerfUIPanel";
}

//------------------------------------------------------------------------------
// Address: 0x10202B40
// Name: private: void CPerfUIPanel::OnPerfToolSelected(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPerfUIPanel::OnPerfToolSelected(CPerfUIPanel *this)
{
  PerformanceTool_t ActiveItem; // edi
  CPerfUIChildPanel *m_pCurrentToolPanel; // ecx
  CPerfUIChildPanel *v4; // ecx

  ActiveItem = vgui::ComboBox::GetActiveItem(this: this->m_pPerformanceTool);
  if ( ActiveItem != this->m_nPerfTool )
  {
    m_pCurrentToolPanel = this->m_pCurrentToolPanel;
    if ( m_pCurrentToolPanel != nullptr )
    {
      m_pCurrentToolPanel->Deactivate(this: m_pCurrentToolPanel);
      this->m_pCurrentToolPanel->SetVisible(this: this->m_pCurrentToolPanel, a2: false);
    }
    this->m_nPerfTool = ActiveItem;
    v4 = this->m_pToolPanel[ActiveItem];
    this->m_pCurrentToolPanel = v4;
    v4->SetVisible(this: v4, a2: true);
    this->m_pCurrentToolPanel->Activate(this: this->m_pCurrentToolPanel);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10202BC0
// Name: public: virtual void CPerfUIPanel::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPerfUIPanel::OnCommand(CPerfUIPanel *this, const char *command)
{
  if ( V_strcasecmp(s1: command, s2: "submit") != 0 && V_strcasecmp(s1: command, s2: "cancel") != 0 )
    vgui::Frame::OnCommand(this, command);
}

//------------------------------------------------------------------------------
// Address: 0x10202C00
// Name: public: virtual void CEnginePerfTools::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnginePerfTools::Shutdown(CEnginePerfTools *this)
{
  CPerfUIChildPanel **p_m_pCurrentToolPanel; // esi

  if ( g_pPerfUI != nullptr )
  {
    p_m_pCurrentToolPanel = &g_pPerfUI->m_pCurrentToolPanel;
    if ( g_pPerfUI->m_pCurrentToolPanel != nullptr )
    {
      (*p_m_pCurrentToolPanel)->Deactivate(this: *p_m_pCurrentToolPanel);
      (*p_m_pCurrentToolPanel)->SetVisible(this: *p_m_pCurrentToolPanel, a2: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10202C40
// Name: void ShowHidePerfUI(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowHidePerfUI()
{
  bool v0; // zf
  CPerfUIPanel_vtbl *v1; // eax

  if ( g_pPerfUI != nullptr )
  {
    v0 = !g_pPerfUI->IsVisible(this: g_pPerfUI);
    v1 = g_pPerfUI->__vftable;
    if ( v0 )
      ((void (*)(void))v1->Activate)();
    else
      ((void (*)(void))v1->Close)();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10202C80
// Name: public: CPerfUIChildPanel::CPerfUIChildPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CPerfUIChildPanel *__thiscall CPerfUIChildPanel::CPerfUIChildPanel(
        CPerfUIChildPanel *this,
        vgui::Panel *parent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // esi
  PanelAnimationMap *v5; // esi
  vgui::PanelKeyBindingMap *v6; // esi

  vgui::EditablePanel::EditablePanel(this, parent, panelName: pName);
  this->__vftable = (CPerfUIChildPanel_vtbl *)&CPerfUIChildPanel::`vftable';
  if ( `CPerfUIChildPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CPerfUIChildPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CPerfUIChildPanel");
    v4->pfnClassName = CPerfUIChildPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CPerfUIChildPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CPerfUIChildPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CPerfUIChildPanel");
    v5->pfnClassName = CPerfUIChildPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CPerfUIChildPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CPerfUIChildPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CPerfUIChildPanel");
    v6->pfnClassName = CPerfUIChildPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  vgui::Panel::SetVisible(this, state: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10202D50
// Name: public: virtual struct vgui::PanelMessageMap __near * CPerfUIChildPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CPerfUIChildPanel::GetMessageMap(CPerfUIChildPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CPerfUIChildPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CPerfUIChildPanel::GetMessageMap'::`2'::s_pMap;
  `CPerfUIChildPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CPerfUIChildPanel");
  `CPerfUIChildPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10202D80
// Name: public: virtual struct PanelAnimationMap __near * CPerfUIChildPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CPerfUIChildPanel::GetAnimMap(CPerfUIChildPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CPerfUIChildPanel");
}

//------------------------------------------------------------------------------
// Address: 0x10202D90
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CPerfUIChildPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CPerfUIChildPanel::GetKBMap(CPerfUIChildPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CPerfUIChildPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CPerfUIChildPanel::GetKBMap'::`2'::s_pMap;
  `CPerfUIChildPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CPerfUIChildPanel");
  `CPerfUIChildPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10202DC0
// Name: protected: virtual void CPropFadeUIPanel::OnTextChanged(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CPropFadeUIPanel::OnTextChanged(CPropFadeUIPanel *this, KeyValues *data)
{
  void *Ptr; // edi
  vgui::ComboBox *v4; // eax
  vgui::ComboBox *m_pVisualization; // ecx
  int ActiveItem; // eax
  int v7; // eax
  vgui::TextEntry *v8; // eax
  int v9; // edi
  int v10; // eax
  int v11; // [esp+8h] [ebp-11Ch]
  int v12; // [esp+Ch] [ebp-118h]
  int v13; // [esp+10h] [ebp-114h]
  int v14; // [esp+14h] [ebp-110h]
  unsigned int v15; // [esp+18h] [ebp-10Ch]
  int v16; // [esp+1Ch] [ebp-108h]
  char string[24]; // [esp+20h] [ebp-104h] BYREF
  int buf_232; // [esp+120h] [ebp-4h] OVERLAPPED BYREF

  Ptr = KeyValues::GetPtr(this: data, keyName: "panel", defaultValue: nullptr);
  v4 = (vgui::ComboBox *)__RTDynamicCast(
                           inptr: Ptr,
                           VfDelta: 0,
                           SrcType: &vgui::Panel `RTTI Type Descriptor',
                           TargetType: &vgui::ComboBox `RTTI Type Descriptor',
                           isReference: 0);
  m_pVisualization = this->m_pVisualization;
  if ( v4 == m_pVisualization )
  {
    ActiveItem = vgui::ComboBox::GetActiveItem(this: m_pVisualization);
    if ( ActiveItem != 0 )
    {
      v7 = ActiveItem - 1;
      if ( v7 != 0 )
      {
        if ( v7 == 1 )
          CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&r_staticpropinfo.IConVar, value: 4, a2: v15, a3: v16);
      }
      else
      {
        CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&r_staticpropinfo.IConVar, value: 3, a2: v15, a3: v16);
      }
    }
    else
    {
      CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&r_staticpropinfo.IConVar, value: 0, a2: v15, a3: v16);
    }
  }
  else
  {
    v8 = (vgui::TextEntry *)__RTDynamicCast(
                              inptr: Ptr,
                              VfDelta: 0,
                              SrcType: &vgui::Panel `RTTI Type Descriptor',
                              TargetType: &vgui::TextEntry `RTTI Type Descriptor',
                              isReference: 0);
    if ( v8 == this->m_pMinScreenArea || v8 == this->m_pMaxScreenArea )
    {
      this->m_pMinScreenArea->GetText_2(this: this->m_pMinScreenArea, a2: string, a3: 256);
      v9 = sscanf(string, format: "%f", &buf_232);
      this->m_pMaxScreenArea->GetText_2(this: this->m_pMaxScreenArea, a2: string, a3: 256);
      v10 = sscanf(string, format: "%f", &data);
      if ( v9 != 0 && v10 != 0 )
        ((void (__thiscall *)(IVModelInfoClient *, int, KeyValues *, int, int, int, int))modelinfoclient->SetLevelScreenFadeRange)(
          a1: modelinfoclient,
          a2: buf_232,
          a3: data,
          a4: v11,
          a5: v12,
          a6: v13,
          a7: v14);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10202F20
// Name: public: CAreaPortalsUIPanel::CAreaPortalsUIPanel(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CAreaPortalsUIPanel *__thiscall CAreaPortalsUIPanel::CAreaPortalsUIPanel(
        CAreaPortalsUIPanel *this,
        vgui::Panel *parent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi

  CPerfUIChildPanel::CPerfUIChildPanel(this, parent, pName: "AreaPortalUIPanel");
  this->__vftable = (CAreaPortalsUIPanel_vtbl *)&CAreaPortalsUIPanel::`vftable';
  if ( `CAreaPortalsUIPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAreaPortalsUIPanel::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CAreaPortalsUIPanel");
    v3->pfnClassName = CAreaPortalsUIPanel::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "CPerfUIChildPanel");
  }
  if ( `CAreaPortalsUIPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAreaPortalsUIPanel::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CAreaPortalsUIPanel");
    v4->pfnClassName = CAreaPortalsUIPanel::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "CPerfUIChildPanel");
  }
  if ( `CAreaPortalsUIPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAreaPortalsUIPanel::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CAreaPortalsUIPanel");
    v5->pfnClassName = CAreaPortalsUIPanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CPerfUIChildPanel");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10203010
// Name: public: virtual struct vgui::PanelMessageMap __near * CAreaPortalsUIPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAreaPortalsUIPanel::GetMessageMap(CAreaPortalsUIPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAreaPortalsUIPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAreaPortalsUIPanel::GetMessageMap'::`2'::s_pMap;
  `CAreaPortalsUIPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAreaPortalsUIPanel");
  `CAreaPortalsUIPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10203040
// Name: public: virtual struct PanelAnimationMap __near * CAreaPortalsUIPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAreaPortalsUIPanel::GetAnimMap(CAreaPortalsUIPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAreaPortalsUIPanel");
}

//------------------------------------------------------------------------------
// Address: 0x10203050
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAreaPortalsUIPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAreaPortalsUIPanel::GetKBMap(CAreaPortalsUIPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAreaPortalsUIPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAreaPortalsUIPanel::GetKBMap'::`2'::s_pMap;
  `CAreaPortalsUIPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAreaPortalsUIPanel");
  `CAreaPortalsUIPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10203080
// Name: public: virtual void COcclusionUIPanel::Activate(void)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __thiscall COcclusionUIPanel::Activate(COcclusionUIPanel *this)
{
  int ActiveItem; // eax
  bool v3; // al
  unsigned int v4; // [esp+0h] [ebp-104h]
  char buf[256]; // [esp+4h] [ebp-100h] BYREF

  ActiveItem = vgui::ComboBox::GetActiveItem(this: this->m_pVisualization);
  if ( ActiveItem == 0 )
  {
    CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&r_visocclusion.IConVar, value: 0, a2: v4, a3: *(int *)buf);
    *(_DWORD *)buf = 0;
    goto LABEL_5;
  }
  if ( ActiveItem == 1 )
  {
    CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&r_visocclusion.IConVar, value: 1, a2: v4, a3: *(int *)buf);
    *(_DWORD *)buf = 3;
LABEL_5:
    CLoaderMemAlloc::CrtIsValidPointer(
      this: (ConVar *)&mat_wireframe.IConVar,
      value: *(int *)buf,
      a2: *(unsigned int *)&buf[4],
      a3: *(int *)&buf[8]);
  }
  v3 = this->m_pDeactivateOcclusion->IsSelected(this: this->m_pDeactivateOcclusion);
  CLoaderMemAlloc::CrtIsValidPointer(
    this: (ConVar *)&r_occlusion.IConVar,
    value: !v3,
    a2: *(unsigned int *)&buf[12],
    a3: *(int *)&buf[16]);
  *(double *)&buf[12] = r_occluderminarea.m_pParent->m_Value.m_fValue;
  V_snprintf(pDest: buf, maxLen: 256, pFormat: "%.2f");
  this->m_pMinOccluderArea->SetText(this: this->m_pMinOccluderArea, a2: buf);
  *(double *)&buf[8] = r_occludeemaxarea.m_pParent->m_Value.m_fValue;
  V_snprintf(pDest: buf, maxLen: 256, pFormat: "%.2f");
  this->m_pMaxOccludeeArea->SetText(this: this->m_pMaxOccludeeArea, a2: buf);
}

//------------------------------------------------------------------------------
// Address: 0x10203170
// Name: protected: virtual void COcclusionUIPanel::OnTextChanged(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall COcclusionUIPanel::OnTextChanged(COcclusionUIPanel *this, KeyValues *data)
{
  void *Ptr; // edi
  vgui::ComboBox *v4; // eax
  vgui::ComboBox *m_pVisualization; // ecx
  int ActiveItem; // eax
  vgui::TextEntry *v7; // eax
  unsigned int v8; // [esp+14h] [ebp-10Ch]
  int v9; // [esp+18h] [ebp-108h]
  _DWORD value[5]; // [esp+1Ch] [ebp-104h] BYREF
  float buf_236; // [esp+11Ch] [ebp-4h] OVERLAPPED BYREF

  Ptr = KeyValues::GetPtr(this: data, keyName: "panel", defaultValue: nullptr);
  v4 = (vgui::ComboBox *)__RTDynamicCast(
                           inptr: Ptr,
                           VfDelta: 0,
                           SrcType: &vgui::Panel `RTTI Type Descriptor',
                           TargetType: &vgui::ComboBox `RTTI Type Descriptor',
                           isReference: 0);
  m_pVisualization = this->m_pVisualization;
  if ( v4 == m_pVisualization )
  {
    ActiveItem = vgui::ComboBox::GetActiveItem(this: m_pVisualization);
    if ( ActiveItem != 0 )
    {
      if ( ActiveItem == 1 )
      {
        CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&r_visocclusion.IConVar, value: 1, a2: v8, a3: v9);
        CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&mat_wireframe.IConVar, value: 3, a2: value[0], a3: value[1]);
      }
    }
    else
    {
      CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&r_visocclusion.IConVar, value: 0, a2: v8, a3: v9);
      CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&mat_wireframe.IConVar, value: 0, a2: value[0], a3: value[1]);
    }
  }
  else
  {
    v7 = (vgui::TextEntry *)__RTDynamicCast(
                              inptr: Ptr,
                              VfDelta: 0,
                              SrcType: &vgui::Panel `RTTI Type Descriptor',
                              TargetType: &vgui::TextEntry `RTTI Type Descriptor',
                              isReference: 0);
    if ( v7 == this->m_pMinOccluderArea || v7 == this->m_pMaxOccludeeArea )
    {
      this->m_pMinOccluderArea->GetText_2(this: this->m_pMinOccluderArea, a2: (char *)value, a3: 256);
      if ( sscanf(string: (const char *)value, format: "%f", &data) != 0 )
        ConVar::SetValue(this: (ConVar *)&r_occluderminarea.IConVar, value: *(float *)&data);
      this->m_pMaxOccludeeArea->GetText_2(this: this->m_pMaxOccludeeArea, a2: (char *)value, a3: 256);
      if ( sscanf(string: (const char *)value, format: "%f", &buf_236) != 0 )
        ConVar::SetValue(this: (ConVar *)&r_occludeemaxarea.IConVar, value: buf_236);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102032D0
// Name: public: virtual struct vgui::PanelMessageMap __near * CPerfUIPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CPerfUIPanel::GetMessageMap(CPerfUIPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CPerfUIPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CPerfUIPanel::GetMessageMap'::`2'::s_pMap;
  `CPerfUIPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CPerfUIPanel");
  `CPerfUIPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10203300
// Name: public: virtual struct PanelAnimationMap __near * CPerfUIPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CPerfUIPanel::GetAnimMap(CPerfUIPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CPerfUIPanel");
}

//------------------------------------------------------------------------------
// Address: 0x10203310
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CPerfUIPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CPerfUIPanel::GetKBMap(CPerfUIPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CPerfUIPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CPerfUIPanel::GetKBMap'::`2'::s_pMap;
  `CPerfUIPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CPerfUIPanel");
  `CPerfUIPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10203370
// Name: private: void CPerfUIPanel::PopulateControls(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPerfUIPanel::PopulateControls(CPerfUIPanel *this)
{
  const char **v2; // esi

  vgui::ComboBox::RemoveAll(this: this->m_pPerformanceTool);
  v2 = s_pPerfToolNames;
  do
    this->m_pPerformanceTool->AddItem_2(this: this->m_pPerformanceTool, a2: *v2++, a3: nullptr);
  while ( (int)v2 < (int)CPropFadeUIPanel::s_pFadeVisualizeLabel );
  this->m_pPerformanceTool->AddActionSignalTarget_2(this: this->m_pPerformanceTool, a2: this);
  this->m_pPerformanceTool->ActivateItem(this: this->m_pPerformanceTool, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x102033D0
// Name: protected: virtual void CPerfUIPanel::OnTextChanged(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPerfUIPanel::OnTextChanged(CPerfUIPanel *this, KeyValues *data)
{
  void *Ptr; // eax

  Ptr = KeyValues::GetPtr(this: data, keyName: "panel", defaultValue: nullptr);
  if ( __RTDynamicCast(
         inptr: Ptr,
         VfDelta: 0,
         SrcType: &vgui::Panel `RTTI Type Descriptor',
         TargetType: &vgui::ComboBox `RTTI Type Descriptor',
         isReference: 0) == this->m_pPerformanceTool )
    CPerfUIPanel::OnPerfToolSelected(this);
}

//------------------------------------------------------------------------------
// Address: 0x10203410
// Name: public: virtual void CPerfUIPanel::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPerfUIPanel::OnTick(CPerfUIPanel *this)
{
  if ( (sv_cheats.m_pParent == nullptr || sv_cheats.m_pParent->m_Value.m_nValue == 0)
    && !Cmd_IsRptActive()
    && this->m_pCurrentToolPanel != nullptr )
  {
    this->m_pCurrentToolPanel->Deactivate(this: this->m_pCurrentToolPanel);
    this->m_pCurrentToolPanel->SetVisible(this: this->m_pCurrentToolPanel, a2: false);
  }
  CColorBalanceUIPanel::Init((vgui::PropertyPage *)this);
}

//------------------------------------------------------------------------------
// Address: 0x10203460
// Name: public: virtual void CPerfUIPanel::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPerfUIPanel::Activate(CPerfUIPanel *this)
{
  int x; // [esp+4h] [ebp-10h] BYREF
  int wide; // [esp+8h] [ebp-Ch] BYREF
  int y; // [esp+Ch] [ebp-8h] BYREF
  int tall; // [esp+10h] [ebp-4h] BYREF

  if ( sv_cheats.m_pParent != nullptr && sv_cheats.m_pParent->m_Value.m_nValue != 0 || Cmd_IsRptActive() )
  {
    vgui::Panel::GetBounds(this, &x, &y, &wide, &tall);
    g_pVGuiInput->SetCursorPos(this: g_pVGuiInput, a2: x + wide / 2, a3: y + tall / 2);
    vgui::Frame::Activate(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102034D0
// Name: public: static void CPropFadeUIPanel::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CPropFadeUIPanel::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
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
  if ( !`CPropFadeUIPanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `CPropFadeUIPanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v4 = 0;
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CPropFadeUIPanel");
    memset(&v3.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v3.m[0][0]) = "TextChanged";
    LODWORD(v3.m[1][0]) =  __thiscall vgui::PropertyPage::`vcall'{952,{flat}};
    memset(&v3.m[1][1], 0, 12);
    LODWORD(v3.m[2][0]) = 1;
    *(_QWORD *)&v3.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10203570
// Name: public: CPropFadeUIPanel::CPropFadeUIPanel(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CPropFadeUIPanel *__thiscall CPropFadeUIPanel::CPropFadeUIPanel(CPropFadeUIPanel *this, vgui::Panel *parent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  vgui::ComboBox *v6; // eax
  vgui::ComboBox *v7; // eax
  const char **v8; // edi
  vgui::TextEntry *v9; // eax
  vgui::TextEntry *v10; // eax
  vgui::TextEntry *v11; // eax
  vgui::TextEntry *v12; // eax

  CPerfUIChildPanel::CPerfUIChildPanel(this, parent, pName: "PropFadeUIPanel");
  this->__vftable = (CPropFadeUIPanel_vtbl *)&CPropFadeUIPanel::`vftable';
  if ( `CPropFadeUIPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CPropFadeUIPanel::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CPropFadeUIPanel");
    v3->pfnClassName = CPropFadeUIPanel::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "CPerfUIChildPanel");
  }
  if ( `CPropFadeUIPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CPropFadeUIPanel::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CPropFadeUIPanel");
    v4->pfnClassName = CPropFadeUIPanel::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "CPerfUIChildPanel");
  }
  if ( `CPropFadeUIPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CPropFadeUIPanel::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CPropFadeUIPanel");
    v5->pfnClassName = CPropFadeUIPanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CPerfUIChildPanel");
  }
  CPropFadeUIPanel::PanelMessageFunc_OnTextChanged::InitVar();
  v6 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v6 != nullptr )
    v7 = vgui::ComboBox::ComboBox(this: v6, parent: this, panelName: "VisualizeMode", numLines: 3, allowEdit: false);
  else
    v7 = nullptr;
  this->m_pVisualization = v7;
  v8 = CPropFadeUIPanel::s_pFadeVisualizeLabel;
  do
    this->m_pVisualization->AddItem_2(this: this->m_pVisualization, a2: *v8++, a3: nullptr);
  while ( (int)v8 < (int)&off_1042333C );
  this->m_pVisualization->AddActionSignalTarget_2(this: this->m_pVisualization, a2: this);
  this->m_pVisualization->ActivateItem(this: this->m_pVisualization, a2: 0);
  v9 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v9 != nullptr )
    v10 = vgui::TextEntry::TextEntry(this: v9, parent: this, panelName: "MinFadeSize");
  else
    v10 = nullptr;
  this->m_pMinScreenArea = v10;
  v11 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v11 != nullptr )
    v12 = vgui::TextEntry::TextEntry(this: v11, parent: this, panelName: "MaxFadeSize");
  else
    v12 = nullptr;
  this->m_pMaxScreenArea = v12;
  vgui::EditablePanel::LoadControlSettings(
    this,
    resourceName: "Resource\\PerfPropFadeUIPanel.res",
    pathID: nullptr,
    pKeyValues: nullptr,
    pConditions: nullptr);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10203740
// Name: public: virtual struct vgui::PanelMessageMap __near * CPropFadeUIPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CPropFadeUIPanel::GetMessageMap(CPropFadeUIPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CPropFadeUIPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CPropFadeUIPanel::GetMessageMap'::`2'::s_pMap;
  `CPropFadeUIPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CPropFadeUIPanel");
  `CPropFadeUIPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10203770
// Name: public: virtual struct PanelAnimationMap __near * CPropFadeUIPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CPropFadeUIPanel::GetAnimMap(CPropFadeUIPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CPropFadeUIPanel");
}

//------------------------------------------------------------------------------
// Address: 0x10203780
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CPropFadeUIPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CPropFadeUIPanel::GetKBMap(CPropFadeUIPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CPropFadeUIPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CPropFadeUIPanel::GetKBMap'::`2'::s_pMap;
  `CPropFadeUIPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CPropFadeUIPanel");
  `CPropFadeUIPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102037B0
// Name: public: static void COcclusionUIPanel::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall COcclusionUIPanel::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
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
  if ( !`COcclusionUIPanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `COcclusionUIPanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v4 = 0;
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "COcclusionUIPanel");
    memset(&v3.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v3.m[0][0]) = "TextChanged";
    LODWORD(v3.m[1][0]) =  __thiscall vgui::PropertyPage::`vcall'{952,{flat}};
    memset(&v3.m[1][1], 0, 12);
    LODWORD(v3.m[2][0]) = 1;
    *(_QWORD *)&v3.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10203850
// Name: public: static void COcclusionUIPanel::PanelMessageFunc_OnCheckButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall COcclusionUIPanel::PanelMessageFunc_OnCheckButtonChecked::InitVar(int a1@<ebp>)
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
  if ( !`COcclusionUIPanel::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded )
  {
    `COcclusionUIPanel::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded = true;
    v4 = 0;
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "COcclusionUIPanel");
    memset(&v3.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v3.m[0][0]) = "CheckButtonChecked";
    LODWORD(v3.m[1][0]) =  __thiscall vgui::PropertyPage::`vcall'{956,{flat}};
    memset(&v3.m[1][1], 0, 12);
    *(_QWORD *)&v3.m[2][0] = 0x400000001LL;
    LODWORD(v3.m[2][2]) = "panel";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102038F0
// Name: public: COcclusionUIPanel::COcclusionUIPanel(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
COcclusionUIPanel *__thiscall COcclusionUIPanel::COcclusionUIPanel(COcclusionUIPanel *this, vgui::Panel *parent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  vgui::ComboBox *v6; // eax
  vgui::ComboBox *v7; // eax
  const char **v8; // edi
  vgui::TextEntry *v9; // eax
  vgui::TextEntry *v10; // eax
  vgui::TextEntry *v11; // eax
  vgui::TextEntry *v12; // eax
  vgui::CheckButton *v13; // eax
  vgui::CheckButton *v14; // eax

  CPerfUIChildPanel::CPerfUIChildPanel(this, parent, pName: "AreaPortalUIPanel");
  this->__vftable = (COcclusionUIPanel_vtbl *)&COcclusionUIPanel::`vftable';
  if ( `COcclusionUIPanel::ChainToMap'::`2'::chained == 0 )
  {
    `COcclusionUIPanel::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "COcclusionUIPanel");
    v3->pfnClassName = COcclusionUIPanel::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "CPerfUIChildPanel");
  }
  if ( `COcclusionUIPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `COcclusionUIPanel::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "COcclusionUIPanel");
    v4->pfnClassName = COcclusionUIPanel::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "CPerfUIChildPanel");
  }
  if ( `COcclusionUIPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `COcclusionUIPanel::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "COcclusionUIPanel");
    v5->pfnClassName = COcclusionUIPanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CPerfUIChildPanel");
  }
  COcclusionUIPanel::PanelMessageFunc_OnTextChanged::InitVar();
  COcclusionUIPanel::PanelMessageFunc_OnCheckButtonChecked::InitVar();
  v6 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v6 != nullptr )
    v7 = vgui::ComboBox::ComboBox(this: v6, parent: this, panelName: "VisualizeMode", numLines: 2, allowEdit: false);
  else
    v7 = nullptr;
  this->m_pVisualization = v7;
  v8 = COcclusionUIPanel::s_pOccVisualizeLabel;
  do
    this->m_pVisualization->AddItem_2(this: this->m_pVisualization, a2: *v8++, a3: nullptr);
  while ( (int)v8 < (int)&perftools );
  this->m_pVisualization->AddActionSignalTarget_2(this: this->m_pVisualization, a2: this);
  this->m_pVisualization->ActivateItem(this: this->m_pVisualization, a2: 0);
  v9 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v9 != nullptr )
    v10 = vgui::TextEntry::TextEntry(this: v9, parent: this, panelName: "MinOccluderSize");
  else
    v10 = nullptr;
  this->m_pMinOccluderArea = v10;
  v11 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v11 != nullptr )
    v12 = vgui::TextEntry::TextEntry(this: v11, parent: this, panelName: "MaxOccludeeSize");
  else
    v12 = nullptr;
  this->m_pMaxOccludeeArea = v12;
  v13 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v13 != nullptr )
    v14 = vgui::CheckButton::CheckButton(this: v13, parent: this, panelName: "DeactivateOcclusion", text: defaultValue);
  else
    v14 = nullptr;
  this->m_pDeactivateOcclusion = v14;
  v14->AddActionSignalTarget_2(this: v14, a2: this);
  vgui::EditablePanel::LoadControlSettings(
    this,
    resourceName: "Resource\\PerfOcclusionUIPanel.res",
    pathID: nullptr,
    pKeyValues: nullptr,
    pConditions: nullptr);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10203B00
// Name: public: virtual struct vgui::PanelMessageMap __near * COcclusionUIPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall COcclusionUIPanel::GetMessageMap(COcclusionUIPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`COcclusionUIPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `COcclusionUIPanel::GetMessageMap'::`2'::s_pMap;
  `COcclusionUIPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "COcclusionUIPanel");
  `COcclusionUIPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10203B30
// Name: public: virtual struct PanelAnimationMap __near * COcclusionUIPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall COcclusionUIPanel::GetAnimMap(COcclusionUIPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "COcclusionUIPanel");
}

//------------------------------------------------------------------------------
// Address: 0x10203B40
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * COcclusionUIPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall COcclusionUIPanel::GetKBMap(COcclusionUIPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`COcclusionUIPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `COcclusionUIPanel::GetKBMap'::`2'::s_pMap;
  `COcclusionUIPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "COcclusionUIPanel");
  `COcclusionUIPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10203B70
// Name: public: static void CPerfUIPanel::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CPerfUIPanel::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
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
  if ( !`CPerfUIPanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `CPerfUIPanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v4 = 0;
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CPerfUIPanel");
    memset(&v3.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v3.m[0][0]) = "TextChanged";
    LODWORD(v3.m[1][0]) =  __thiscall vgui::FileOpenDialog::`vcall'{1116,{flat}};
    memset(&v3.m[1][1], 0, 12);
    LODWORD(v3.m[2][0]) = 1;
    *(_QWORD *)&v3.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10203C10
// Name: public: CPerfUIPanel::CPerfUIPanel(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CPerfUIPanel *__thiscall CPerfUIPanel::CPerfUIPanel(CPerfUIPanel *this, vgui::Panel *parent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  vgui::ComboBox *v6; // eax
  vgui::ComboBox *v7; // eax
  int v8; // edi
  double v9; // st7
  CPerfUIChildPanel *v10; // eax
  CPerfUIChildPanel *v11; // eax
  vgui::Panel **m_pToolPanel; // edi
  CPropFadeUIPanel *v13; // eax
  CPropFadeUIPanel *v14; // eax
  CAreaPortalsUIPanel *v15; // eax
  CAreaPortalsUIPanel *v16; // eax
  COcclusionUIPanel *v17; // eax
  COcclusionUIPanel *v18; // eax
  int i; // ebx
  double v21; // [esp+Ch] [ebp-8h]

  vgui::Frame::Frame(this, parent, panelName: "PerfUIPanel", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CPerfUIPanel_vtbl *)&CPerfUIPanel::`vftable';
  if ( `CPerfUIPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CPerfUIPanel::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CPerfUIPanel");
    v3->pfnClassName = CPerfUIPanel::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CPerfUIPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CPerfUIPanel::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CPerfUIPanel");
    v4->pfnClassName = CPerfUIPanel::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CPerfUIPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CPerfUIPanel::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CPerfUIPanel");
    v5->pfnClassName = CPerfUIPanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  CPerfUIPanel::PanelMessageFunc_OnTextChanged::InitVar();
  vgui::Frame::SetTitle(this, title: "Level Performance Tools", surfaceTitle: true);
  v6 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v6 != nullptr )
    v7 = vgui::ComboBox::ComboBox(this: v6, parent: this, panelName: "PerformanceTool", numLines: 10, allowEdit: false);
  else
    v7 = nullptr;
  this->m_pPerformanceTool = v7;
  g_pVGui->AddTickSignal(this: g_pVGui, a2: this->_vpanel, a3: 0);
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "Resource\\PerfUIPanel.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  vgui::Panel::SetVisible(this, state: 0);
  vgui::Frame::SetSizeable(this, state: false);
  vgui::Frame::SetMoveable(this, state: true);
  v8 = videomode->GetModeWidth(this: videomode) - 260;
  v21 = (double)((videomode->GetModeHeight(this: videomode) - 400) / 2);
  v9 = (double)videomode->GetModeHeight(this: videomode) * 0.2 + v21;
  vgui::Panel::SetBounds(this, x: v8, y: (int)v9, wide: 250, tall: 400);
  v10 = (CPerfUIChildPanel *)MemAlloc_Alloc(nSize: 0x180u);
  if ( v10 != nullptr )
    v11 = CPerfUIChildPanel::CPerfUIChildPanel(this: v10, parent: this, pName: "PerfNone");
  else
    v11 = nullptr;
  m_pToolPanel = this->m_pToolPanel;
  this->m_pToolPanel[0] = v11;
  v13 = (CPropFadeUIPanel *)MemAlloc_Alloc(nSize: 0x190u);
  if ( v13 != nullptr )
    v14 = CPropFadeUIPanel::CPropFadeUIPanel(this: v13, parent: this);
  else
    v14 = nullptr;
  this->m_pToolPanel[1] = v14;
  v15 = (CAreaPortalsUIPanel *)MemAlloc_Alloc(nSize: 0x184u);
  if ( v15 != nullptr )
    v16 = CAreaPortalsUIPanel::CAreaPortalsUIPanel(this: v15, parent: this);
  else
    v16 = nullptr;
  this->m_pToolPanel[2] = v16;
  v17 = (COcclusionUIPanel *)MemAlloc_Alloc(nSize: 0x198u);
  if ( v17 != nullptr )
    v18 = COcclusionUIPanel::COcclusionUIPanel(this: v17, parent: this);
  else
    v18 = nullptr;
  this->m_pToolPanel[3] = v18;
  for ( i = 4; i != 0; --i )
    vgui::Panel::SetBounds(this: *m_pToolPanel++, x: 0, y: 75, wide: 250, tall: 325);
  this->m_nPerfTool = PERF_TOOL_COUNT;
  this->m_pCurrentToolPanel = nullptr;
  CPerfUIPanel::PopulateControls(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10203E80
// Name: public: virtual void CEnginePerfTools::InstallPerformanceToolsUI(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnginePerfTools::InstallPerformanceToolsUI(CEnginePerfTools *this, vgui::Panel *parent)
{
  CPerfUIPanel *v2; // eax

  if ( g_pPerfUI == nullptr )
  {
    v2 = (CPerfUIPanel *)MemAlloc_Alloc(nSize: 0x234u);
    if ( v2 != nullptr )
      g_pPerfUI = CPerfUIPanel::CPerfUIPanel(this: v2, parent);
    else
      g_pPerfUI = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1031EED0
// Name: _dynamic_initializer_for__perfui__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__perfui__()
{
  ConCommand::ConCommand(
    this: &perfui,
    pName: "perfui",
    callback: ShowHidePerfUI,
    pHelpString: "Show/hide the level performance tools UI.",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__perfui__);
}

//------------------------------------------------------------------------------
// Address: 0x10327180
// Name: _dynamic_atexit_destructor_for__perfui__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__perfui__()
{
  ConCommand::~ConCommand(this: &perfui);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10202BD0
// Name: public: static char const __near * CPerfUIChildPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CPerfUIChildPanel::GetPanelClassName()
{
  return "CPerfUIChildPanel";
}

//------------------------------------------------------------------------------
// Address: 0x10202BE0
// Name: public: static char const __near * CPropFadeUIPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CPropFadeUIPanel::GetPanelClassName()
{
  return "CPropFadeUIPanel";
}

//------------------------------------------------------------------------------
// Address: 0x10202BF0
// Name: public: virtual void CPropFadeUIPanel::Activate(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CPropFadeUIPanel::Activate(CPropFadeUIPanel *this)
{
  int ActiveItem; // eax
  int v3; // eax
  unsigned int pDest[5]; // [esp+Ch] [ebp-108h] BYREF
  __int64 buf_236; // [esp+10Ch] [ebp-8h] OVERLAPPED BYREF

  modelinfoclient->GetLevelScreenFadeRange(
    this: modelinfoclient,
    a2: (float *)&buf_236,
    a3: (float *)((char *)&buf_236 + 4));
  V_snprintf((char *)pDest, maxLen: 256, pFormat: "%.2f", *(float *)&buf_236);
  this->m_pMinScreenArea->SetText(this: this->m_pMinScreenArea, a2: (const char *)pDest);
  V_snprintf((char *)pDest, maxLen: 256, pFormat: "%.2f", *((float *)&buf_236 + 1));
  this->m_pMaxScreenArea->SetText(this: this->m_pMaxScreenArea, a2: (const char *)pDest);
  ActiveItem = vgui::ComboBox::GetActiveItem(this: this->m_pVisualization);
  if ( ActiveItem != 0 )
  {
    v3 = ActiveItem - 1;
    if ( v3 != 0 )
    {
      if ( v3 == 1 )
        CLoaderMemAlloc::CrtIsValidPointer(
          this: (ConVar *)&r_staticpropinfo.IConVar,
          value: 4,
          a2: pDest[0],
          a3: pDest[1]);
    }
    else
    {
      CLoaderMemAlloc::CrtIsValidPointer(
        this: (ConVar *)&r_staticpropinfo.IConVar,
        value: 3,
        a2: pDest[0],
        a3: pDest[1]);
    }
  }
  else
  {
    CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&r_staticpropinfo.IConVar, value: 0, a2: pDest[0], a3: pDest[1]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10202CD0
// Name: public: virtual void CPropFadeUIPanel::Deactivate(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall CPropFadeUIPanel::Deactivate(CPropFadeUIPanel *this)
{
  unsigned int v1; // [esp-8h] [ebp-8h]
  int v2; // [esp-4h] [ebp-4h]

  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&r_staticpropinfo.IConVar, value: 0, a2: v1, a3: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10202CE0
// Name: public: static char const __near * CAreaPortalsUIPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAreaPortalsUIPanel::GetPanelClassName()
{
  return "CAreaPortalsUIPanel";
}

//------------------------------------------------------------------------------
// Address: 0x10202CF0
// Name: public: virtual void CAreaPortalsUIPanel::Activate(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall CAreaPortalsUIPanel::Activate(CAreaPortalsUIPanel *this)
{
  unsigned int v1; // [esp-10h] [ebp-10h]
  int v2; // [esp-Ch] [ebp-Ch]
  unsigned int v3; // [esp-8h] [ebp-8h]
  int v4; // [esp-4h] [ebp-4h]

  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&r_DrawPortals.IConVar, value: 1, a2: v1, a3: v2);
  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&mat_wireframe.IConVar, value: 3, a2: v3, a3: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10202D10
// Name: public: virtual void CAreaPortalsUIPanel::Deactivate(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall CAreaPortalsUIPanel::Deactivate(CAreaPortalsUIPanel *this)
{
  unsigned int v1; // [esp-10h] [ebp-10h]
  int v2; // [esp-Ch] [ebp-Ch]
  unsigned int v3; // [esp-8h] [ebp-8h]
  int v4; // [esp-4h] [ebp-4h]

  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&r_DrawPortals.IConVar, value: 0, a2: v1, a3: v2);
  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&mat_wireframe.IConVar, value: 0, a2: v3, a3: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10202D30
// Name: public: static char const __near * COcclusionUIPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl COcclusionUIPanel::GetPanelClassName()
{
  return "COcclusionUIPanel";
}

//------------------------------------------------------------------------------
// Address: 0x10202D40
// Name: public: virtual void COcclusionUIPanel::Deactivate(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall COcclusionUIPanel::Deactivate(COcclusionUIPanel *this)
{
  unsigned int v1; // [esp-10h] [ebp-10h]
  int v2; // [esp-Ch] [ebp-Ch]
  unsigned int v3; // [esp-8h] [ebp-8h]
  int v4; // [esp-4h] [ebp-4h]

  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&r_visocclusion.IConVar, value: 0, a2: v1, a3: v2);
  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&mat_wireframe.IConVar, value: 0, a2: v3, a3: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10202D60
// Name: protected: virtual void COcclusionUIPanel::OnCheckButtonChecked(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall COcclusionUIPanel::OnCheckButtonChecked(COcclusionUIPanel *this, vgui::CheckButton *panel)
{
  bool v2; // al
  unsigned int v3; // [esp-8h] [ebp-8h]
  int v4; // [esp-4h] [ebp-4h]

  if ( panel == this->m_pDeactivateOcclusion )
  {
    v2 = this->m_pDeactivateOcclusion->IsSelected(this: this->m_pDeactivateOcclusion);
    CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&r_occlusion.IConVar, value: !v2, a2: v3, a3: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10202DA0
// Name: public: static char const __near * CPerfUIPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CPerfUIPanel::GetPanelClassName()
{
  return "CPerfUIPanel";
}

//------------------------------------------------------------------------------
// Address: 0x10202DB0
// Name: private: void CPerfUIPanel::OnPerfToolSelected(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPerfUIPanel::OnPerfToolSelected(CPerfUIPanel *this)
{
  PerformanceTool_t ActiveItem; // edi
  CPerfUIChildPanel *m_pCurrentToolPanel; // ecx
  CPerfUIChildPanel *v4; // ecx

  ActiveItem = vgui::ComboBox::GetActiveItem(this: this->m_pPerformanceTool);
  if ( ActiveItem != this->m_nPerfTool )
  {
    m_pCurrentToolPanel = this->m_pCurrentToolPanel;
    if ( m_pCurrentToolPanel != nullptr )
    {
      m_pCurrentToolPanel->Deactivate(this: m_pCurrentToolPanel);
      this->m_pCurrentToolPanel->SetVisible(this: this->m_pCurrentToolPanel, a2: false);
    }
    this->m_nPerfTool = ActiveItem;
    v4 = this->m_pToolPanel[ActiveItem];
    this->m_pCurrentToolPanel = v4;
    v4->SetVisible(this: v4, a2: true);
    this->m_pCurrentToolPanel->Activate(this: this->m_pCurrentToolPanel);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10202E30
// Name: public: virtual void CPerfUIPanel::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPerfUIPanel::OnCommand(CPerfUIPanel *this, const char *command)
{
  if ( V_strcasecmp(s1: command, s2: "submit") != 0 && V_strcasecmp(s1: command, s2: "cancel") != 0 )
    vgui::Frame::OnCommand(this, command);
}

//------------------------------------------------------------------------------
// Address: 0x10202E70
// Name: public: virtual void CPerfUIPanel::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPerfUIPanel::OnKeyCodeTyped(CColorCorrectionUIPanel *this, ButtonCode_t code)
{
  if ( code == KEY_ESCAPE )
    this->Close(this);
  else
    vgui::Frame::OnKeyCodeTyped(this, code);
}

//------------------------------------------------------------------------------
// Address: 0x10202EA0
// Name: public: virtual void CEnginePerfTools::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnginePerfTools::Shutdown(CEnginePerfTools *this)
{
  CPerfUIChildPanel **p_m_pCurrentToolPanel; // esi

  if ( g_pPerfUI != nullptr )
  {
    p_m_pCurrentToolPanel = &g_pPerfUI->m_pCurrentToolPanel;
    if ( g_pPerfUI->m_pCurrentToolPanel != nullptr )
    {
      (*p_m_pCurrentToolPanel)->Deactivate(this: *p_m_pCurrentToolPanel);
      (*p_m_pCurrentToolPanel)->SetVisible(this: *p_m_pCurrentToolPanel, a2: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10202EE0
// Name: void ShowHidePerfUI(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowHidePerfUI()
{
  bool v0; // zf
  CPerfUIPanel_vtbl *v1; // eax

  if ( g_pPerfUI != nullptr )
  {
    v0 = !g_pPerfUI->IsVisible(this: g_pPerfUI);
    v1 = g_pPerfUI->__vftable;
    if ( v0 )
      ((void (*)(void))v1->Activate)();
    else
      ((void (*)(void))v1->Close)();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10203000
// Name: public: virtual struct vgui::PanelMessageMap __near * CPerfUIChildPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CPerfUIChildPanel::GetMessageMap(CPerfUIChildPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CPerfUIChildPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CPerfUIChildPanel::GetMessageMap'::`2'::s_pMap;
  `CPerfUIChildPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CPerfUIChildPanel");
  `CPerfUIChildPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10203030
// Name: public: virtual struct PanelAnimationMap __near * CPerfUIChildPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CPerfUIChildPanel::GetAnimMap(CPerfUIChildPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CPerfUIChildPanel");
}

//------------------------------------------------------------------------------
// Address: 0x10203070
// Name: protected: virtual void CPropFadeUIPanel::OnTextChanged(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CPropFadeUIPanel::OnTextChanged(CPropFadeUIPanel *this, KeyValues *data)
{
  void *Ptr; // edi
  vgui::ComboBox *v4; // eax
  vgui::ComboBox *m_pVisualization; // ecx
  int ActiveItem; // eax
  int v7; // eax
  vgui::TextEntry *v8; // eax
  int v9; // edi
  int v10; // eax
  int v11; // [esp+8h] [ebp-11Ch]
  int v12; // [esp+Ch] [ebp-118h]
  int v13; // [esp+10h] [ebp-114h]
  int v14; // [esp+14h] [ebp-110h]
  unsigned int v15; // [esp+18h] [ebp-10Ch]
  int v16; // [esp+1Ch] [ebp-108h]
  char v17[24]; // [esp+20h] [ebp-104h] BYREF
  int buf_232; // [esp+120h] [ebp-4h] OVERLAPPED BYREF

  Ptr = KeyValues::GetPtr(this: data, keyName: "panel", defaultValue: nullptr);
  v4 = (vgui::ComboBox *)__RTDynamicCast(
                           inptr: Ptr,
                           VfDelta: 0,
                           SrcType: &vgui::Panel `RTTI Type Descriptor',
                           TargetType: &vgui::ComboBox `RTTI Type Descriptor',
                           isReference: 0);
  m_pVisualization = this->m_pVisualization;
  if ( v4 == m_pVisualization )
  {
    ActiveItem = vgui::ComboBox::GetActiveItem(this: m_pVisualization);
    if ( ActiveItem != 0 )
    {
      v7 = ActiveItem - 1;
      if ( v7 != 0 )
      {
        if ( v7 == 1 )
          CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&r_staticpropinfo.IConVar, value: 4, a2: v15, a3: v16);
      }
      else
      {
        CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&r_staticpropinfo.IConVar, value: 3, a2: v15, a3: v16);
      }
    }
    else
    {
      CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&r_staticpropinfo.IConVar, value: 0, a2: v15, a3: v16);
    }
  }
  else
  {
    v8 = (vgui::TextEntry *)__RTDynamicCast(
                              inptr: Ptr,
                              VfDelta: 0,
                              SrcType: &vgui::Panel `RTTI Type Descriptor',
                              TargetType: &vgui::TextEntry `RTTI Type Descriptor',
                              isReference: 0);
    if ( v8 == this->m_pMinScreenArea || v8 == this->m_pMaxScreenArea )
    {
      this->m_pMinScreenArea->GetText_2(this: this->m_pMinScreenArea, a2: v17, a3: 256);
      v9 = sscanf(string: v17, format: "%f", &buf_232);
      this->m_pMaxScreenArea->GetText_2(this: this->m_pMaxScreenArea, a2: v17, a3: 256);
      v10 = sscanf(string: v17, format: "%f", &data);
      if ( v9 != 0 && v10 != 0 )
        ((void (__thiscall *)(IVModelInfoClient *, int, KeyValues *, int, int, int, int))modelinfoclient->SetLevelScreenFadeRange)(
          a1: modelinfoclient,
          a2: buf_232,
          a3: data,
          a4: v11,
          a5: v12,
          a6: v13,
          a7: v14);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102031D0
// Name: public: CAreaPortalsUIPanel::CAreaPortalsUIPanel(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CAreaPortalsUIPanel *__thiscall CAreaPortalsUIPanel::CAreaPortalsUIPanel(
        CAreaPortalsUIPanel *this,
        vgui::Panel *parent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi

  CPerfUIChildPanel::CPerfUIChildPanel(this, parent, pName: "AreaPortalUIPanel");
  this->__vftable = (CAreaPortalsUIPanel_vtbl *)&CAreaPortalsUIPanel::`vftable';
  if ( `CAreaPortalsUIPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAreaPortalsUIPanel::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CAreaPortalsUIPanel");
    v3->pfnClassName = CAreaPortalsUIPanel::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "CPerfUIChildPanel");
  }
  if ( `CAreaPortalsUIPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAreaPortalsUIPanel::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CAreaPortalsUIPanel");
    v4->pfnClassName = CAreaPortalsUIPanel::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "CPerfUIChildPanel");
  }
  if ( `CAreaPortalsUIPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAreaPortalsUIPanel::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CAreaPortalsUIPanel");
    v5->pfnClassName = CAreaPortalsUIPanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CPerfUIChildPanel");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102032C0
// Name: public: virtual struct vgui::PanelMessageMap __near * CAreaPortalsUIPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAreaPortalsUIPanel::GetMessageMap(CAreaPortalsUIPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAreaPortalsUIPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAreaPortalsUIPanel::GetMessageMap'::`2'::s_pMap;
  `CAreaPortalsUIPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAreaPortalsUIPanel");
  `CAreaPortalsUIPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102032F0
// Name: public: virtual struct PanelAnimationMap __near * CAreaPortalsUIPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAreaPortalsUIPanel::GetAnimMap(CAreaPortalsUIPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAreaPortalsUIPanel");
}

//------------------------------------------------------------------------------
// Address: 0x10203330
// Name: public: virtual void COcclusionUIPanel::Activate(void)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __thiscall COcclusionUIPanel::Activate(COcclusionUIPanel *this)
{
  int ActiveItem; // eax
  bool v3; // al
  unsigned int v4; // [esp+0h] [ebp-104h]
  char buf[256]; // [esp+4h] [ebp-100h] BYREF

  ActiveItem = vgui::ComboBox::GetActiveItem(this: this->m_pVisualization);
  if ( ActiveItem == 0 )
  {
    CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&r_visocclusion.IConVar, value: 0, a2: v4, a3: *(int *)buf);
    *(_DWORD *)buf = 0;
    goto LABEL_5;
  }
  if ( ActiveItem == 1 )
  {
    CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&r_visocclusion.IConVar, value: 1, a2: v4, a3: *(int *)buf);
    *(_DWORD *)buf = 3;
LABEL_5:
    CLoaderMemAlloc::CrtIsValidPointer(
      this: (ConVar *)&mat_wireframe.IConVar,
      value: *(int *)buf,
      a2: *(unsigned int *)&buf[4],
      a3: *(int *)&buf[8]);
  }
  v3 = this->m_pDeactivateOcclusion->IsSelected(this: this->m_pDeactivateOcclusion);
  CLoaderMemAlloc::CrtIsValidPointer(
    this: (ConVar *)&r_occlusion.IConVar,
    value: !v3,
    a2: *(unsigned int *)&buf[12],
    a3: *(int *)&buf[16]);
  *(double *)&buf[12] = r_occluderminarea.m_pParent->m_Value.m_fValue;
  V_snprintf(pDest: buf, maxLen: 256, pFormat: "%.2f");
  this->m_pMinOccluderArea->SetText(this: this->m_pMinOccluderArea, a2: buf);
  *(double *)&buf[8] = r_occludeemaxarea.m_pParent->m_Value.m_fValue;
  V_snprintf(pDest: buf, maxLen: 256, pFormat: "%.2f");
  this->m_pMaxOccludeeArea->SetText(this: this->m_pMaxOccludeeArea, a2: buf);
}

//------------------------------------------------------------------------------
// Address: 0x10203420
// Name: protected: virtual void COcclusionUIPanel::OnTextChanged(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall COcclusionUIPanel::OnTextChanged(COcclusionUIPanel *this, KeyValues *data)
{
  void *Ptr; // edi
  vgui::ComboBox *v4; // eax
  vgui::ComboBox *m_pVisualization; // ecx
  int ActiveItem; // eax
  vgui::TextEntry *v7; // eax
  unsigned int v8; // [esp+14h] [ebp-10Ch]
  int v9; // [esp+18h] [ebp-108h]
  _DWORD value[5]; // [esp+1Ch] [ebp-104h] BYREF
  float buf_236; // [esp+11Ch] [ebp-4h] OVERLAPPED BYREF

  Ptr = KeyValues::GetPtr(this: data, keyName: "panel", defaultValue: nullptr);
  v4 = (vgui::ComboBox *)__RTDynamicCast(
                           inptr: Ptr,
                           VfDelta: 0,
                           SrcType: &vgui::Panel `RTTI Type Descriptor',
                           TargetType: &vgui::ComboBox `RTTI Type Descriptor',
                           isReference: 0);
  m_pVisualization = this->m_pVisualization;
  if ( v4 == m_pVisualization )
  {
    ActiveItem = vgui::ComboBox::GetActiveItem(this: m_pVisualization);
    if ( ActiveItem != 0 )
    {
      if ( ActiveItem == 1 )
      {
        CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&r_visocclusion.IConVar, value: 1, a2: v8, a3: v9);
        CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&mat_wireframe.IConVar, value: 3, a2: value[0], a3: value[1]);
      }
    }
    else
    {
      CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&r_visocclusion.IConVar, value: 0, a2: v8, a3: v9);
      CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&mat_wireframe.IConVar, value: 0, a2: value[0], a3: value[1]);
    }
  }
  else
  {
    v7 = (vgui::TextEntry *)__RTDynamicCast(
                              inptr: Ptr,
                              VfDelta: 0,
                              SrcType: &vgui::Panel `RTTI Type Descriptor',
                              TargetType: &vgui::TextEntry `RTTI Type Descriptor',
                              isReference: 0);
    if ( v7 == this->m_pMinOccluderArea || v7 == this->m_pMaxOccludeeArea )
    {
      this->m_pMinOccluderArea->GetText_2(this: this->m_pMinOccluderArea, a2: (char *)value, a3: 256);
      if ( sscanf(string: (char *)value, format: "%f", &data) != 0 )
        ConVar::SetValue(this: (ConVar *)&r_occluderminarea.IConVar, value: *(float *)&data);
      this->m_pMaxOccludeeArea->GetText_2(this: this->m_pMaxOccludeeArea, a2: (char *)value, a3: 256);
      if ( sscanf(string: (char *)value, format: "%f", &buf_236) != 0 )
        ConVar::SetValue(this: (ConVar *)&r_occludeemaxarea.IConVar, value: buf_236);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10203580
// Name: public: virtual struct vgui::PanelMessageMap __near * CPerfUIPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CPerfUIPanel::GetMessageMap(CPerfUIPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CPerfUIPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CPerfUIPanel::GetMessageMap'::`2'::s_pMap;
  `CPerfUIPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CPerfUIPanel");
  `CPerfUIPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102035B0
// Name: public: virtual struct PanelAnimationMap __near * CPerfUIPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CPerfUIPanel::GetAnimMap(CPerfUIPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CPerfUIPanel");
}

//------------------------------------------------------------------------------
// Address: 0x102035C0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CPerfUIPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CPerfUIPanel::GetKBMap(CPerfUIPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CPerfUIPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CPerfUIPanel::GetKBMap'::`2'::s_pMap;
  `CPerfUIPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CPerfUIPanel");
  `CPerfUIPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10203620
// Name: private: void CPerfUIPanel::PopulateControls(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPerfUIPanel::PopulateControls(CPerfUIPanel *this)
{
  const char **v2; // esi

  vgui::ComboBox::RemoveAll(this: this->m_pPerformanceTool);
  v2 = s_pPerfToolNames;
  do
    this->m_pPerformanceTool->AddItem_2(this: this->m_pPerformanceTool, a2: *v2++, a3: nullptr);
  while ( (int)v2 < (int)CPropFadeUIPanel::s_pFadeVisualizeLabel );
  this->m_pPerformanceTool->AddActionSignalTarget_2(this: this->m_pPerformanceTool, a2: this);
  this->m_pPerformanceTool->ActivateItem(this: this->m_pPerformanceTool, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10203680
// Name: protected: virtual void CPerfUIPanel::OnTextChanged(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPerfUIPanel::OnTextChanged(CPerfUIPanel *this, KeyValues *data)
{
  void *Ptr; // eax

  Ptr = KeyValues::GetPtr(this: data, keyName: "panel", defaultValue: nullptr);
  if ( __RTDynamicCast(
         inptr: Ptr,
         VfDelta: 0,
         SrcType: &vgui::Panel `RTTI Type Descriptor',
         TargetType: &vgui::ComboBox `RTTI Type Descriptor',
         isReference: 0) == this->m_pPerformanceTool )
    CPerfUIPanel::OnPerfToolSelected(this);
}

//------------------------------------------------------------------------------
// Address: 0x102036C0
// Name: public: virtual void CPerfUIPanel::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPerfUIPanel::OnTick(CPerfUIPanel *this)
{
  if ( (sv_cheats.m_pParent == nullptr || sv_cheats.m_pParent->m_Value.m_nValue == 0)
    && !Cmd_IsRptActive()
    && this->m_pCurrentToolPanel != nullptr )
  {
    this->m_pCurrentToolPanel->Deactivate(this: this->m_pCurrentToolPanel);
    this->m_pCurrentToolPanel->SetVisible(this: this->m_pCurrentToolPanel, a2: false);
  }
  CColorBalanceUIPanel::Init((vgui::PropertyPage *)this);
}

//------------------------------------------------------------------------------
// Address: 0x10203710
// Name: public: virtual void CPerfUIPanel::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPerfUIPanel::Activate(CPerfUIPanel *this)
{
  int x; // [esp+4h] [ebp-10h] BYREF
  int wide; // [esp+8h] [ebp-Ch] BYREF
  int y; // [esp+Ch] [ebp-8h] BYREF
  int tall; // [esp+10h] [ebp-4h] BYREF

  if ( sv_cheats.m_pParent != nullptr && sv_cheats.m_pParent->m_Value.m_nValue != 0 || Cmd_IsRptActive() )
  {
    vgui::Panel::GetBounds(this, &x, &y, &wide, &tall);
    g_pVGuiInput->SetCursorPos(this: g_pVGuiInput, a2: x + wide / 2, a3: y + tall / 2);
    vgui::Frame::Activate(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10203820
// Name: public: CPropFadeUIPanel::CPropFadeUIPanel(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CPropFadeUIPanel *__thiscall CPropFadeUIPanel::CPropFadeUIPanel(CPropFadeUIPanel *this, vgui::Panel *parent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  vgui::ComboBox *v6; // eax
  vgui::ComboBox *v7; // eax
  const char **v8; // edi
  vgui::TextEntry *v9; // eax
  vgui::TextEntry *v10; // eax
  vgui::TextEntry *v11; // eax
  vgui::TextEntry *v12; // eax

  CPerfUIChildPanel::CPerfUIChildPanel(this, parent, pName: "PropFadeUIPanel");
  this->__vftable = (CPropFadeUIPanel_vtbl *)&CPropFadeUIPanel::`vftable';
  if ( `CPropFadeUIPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CPropFadeUIPanel::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CPropFadeUIPanel");
    v3->pfnClassName = CPropFadeUIPanel::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "CPerfUIChildPanel");
  }
  if ( `CPropFadeUIPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CPropFadeUIPanel::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CPropFadeUIPanel");
    v4->pfnClassName = CPropFadeUIPanel::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "CPerfUIChildPanel");
  }
  if ( `CPropFadeUIPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CPropFadeUIPanel::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CPropFadeUIPanel");
    v5->pfnClassName = CPropFadeUIPanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CPerfUIChildPanel");
  }
  CPropFadeUIPanel::PanelMessageFunc_OnTextChanged::InitVar();
  v6 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v6 != nullptr )
    v7 = vgui::ComboBox::ComboBox(this: v6, parent: this, panelName: "VisualizeMode", numLines: 3, allowEdit: false);
  else
    v7 = nullptr;
  this->m_pVisualization = v7;
  v8 = CPropFadeUIPanel::s_pFadeVisualizeLabel;
  do
    this->m_pVisualization->AddItem_2(this: this->m_pVisualization, a2: *v8++, a3: nullptr);
  while ( (int)v8 < (int)&off_1042333C );
  this->m_pVisualization->AddActionSignalTarget_2(this: this->m_pVisualization, a2: this);
  this->m_pVisualization->ActivateItem(this: this->m_pVisualization, a2: 0);
  v9 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v9 != nullptr )
    v10 = vgui::TextEntry::TextEntry(this: v9, parent: this, panelName: "MinFadeSize");
  else
    v10 = nullptr;
  this->m_pMinScreenArea = v10;
  v11 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v11 != nullptr )
    v12 = vgui::TextEntry::TextEntry(this: v11, parent: this, panelName: "MaxFadeSize");
  else
    v12 = nullptr;
  this->m_pMaxScreenArea = v12;
  vgui::EditablePanel::LoadControlSettings(
    this,
    resourceName: "Resource\\PerfPropFadeUIPanel.res",
    pathID: nullptr,
    pKeyValues: nullptr,
    pConditions: nullptr);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102039F0
// Name: public: virtual struct vgui::PanelMessageMap __near * CPropFadeUIPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CPropFadeUIPanel::GetMessageMap(CPropFadeUIPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CPropFadeUIPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CPropFadeUIPanel::GetMessageMap'::`2'::s_pMap;
  `CPropFadeUIPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CPropFadeUIPanel");
  `CPropFadeUIPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10203A20
// Name: public: virtual struct PanelAnimationMap __near * CPropFadeUIPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CPropFadeUIPanel::GetAnimMap(CPropFadeUIPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CPropFadeUIPanel");
}

//------------------------------------------------------------------------------
// Address: 0x10203A30
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CPropFadeUIPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CPropFadeUIPanel::GetKBMap(CPropFadeUIPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CPropFadeUIPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CPropFadeUIPanel::GetKBMap'::`2'::s_pMap;
  `CPropFadeUIPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CPropFadeUIPanel");
  `CPropFadeUIPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10203A60
// Name: public: static void COcclusionUIPanel::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall COcclusionUIPanel::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
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
  if ( !`COcclusionUIPanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `COcclusionUIPanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v4 = 0;
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "COcclusionUIPanel");
    memset(&v3.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v3.m[0][0]) = "TextChanged";
    LODWORD(v3.m[1][0]) =  __thiscall vgui::PropertyPage::`vcall'{952,{flat}};
    memset(&v3.m[1][1], 0, 12);
    LODWORD(v3.m[2][0]) = 1;
    *(_QWORD *)&v3.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10203BA0
// Name: public: COcclusionUIPanel::COcclusionUIPanel(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
COcclusionUIPanel *__thiscall COcclusionUIPanel::COcclusionUIPanel(COcclusionUIPanel *this, vgui::Panel *parent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  vgui::ComboBox *v6; // eax
  vgui::ComboBox *v7; // eax
  const char **v8; // edi
  vgui::TextEntry *v9; // eax
  vgui::TextEntry *v10; // eax
  vgui::TextEntry *v11; // eax
  vgui::TextEntry *v12; // eax
  vgui::CheckButton *v13; // eax
  vgui::CheckButton *v14; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  CPerfUIChildPanel::CPerfUIChildPanel(this, parent, pName: "AreaPortalUIPanel");
  this->__vftable = (COcclusionUIPanel_vtbl *)&COcclusionUIPanel::`vftable';
  if ( `COcclusionUIPanel::ChainToMap'::`2'::chained == 0 )
  {
    `COcclusionUIPanel::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "COcclusionUIPanel");
    v3->pfnClassName = COcclusionUIPanel::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "CPerfUIChildPanel");
  }
  if ( `COcclusionUIPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `COcclusionUIPanel::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "COcclusionUIPanel");
    v4->pfnClassName = COcclusionUIPanel::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "CPerfUIChildPanel");
  }
  if ( `COcclusionUIPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `COcclusionUIPanel::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "COcclusionUIPanel");
    v5->pfnClassName = COcclusionUIPanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CPerfUIChildPanel");
  }
  COcclusionUIPanel::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&savedregs);
  COcclusionUIPanel::PanelMessageFunc_OnCheckButtonChecked::InitVar();
  v6 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v6 != nullptr )
    v7 = vgui::ComboBox::ComboBox(this: v6, parent: this, panelName: "VisualizeMode", numLines: 2, allowEdit: false);
  else
    v7 = nullptr;
  this->m_pVisualization = v7;
  v8 = COcclusionUIPanel::s_pOccVisualizeLabel;
  do
    this->m_pVisualization->AddItem_2(this: this->m_pVisualization, a2: *v8++, a3: nullptr);
  while ( (int)v8 < (int)&perftools );
  this->m_pVisualization->AddActionSignalTarget_2(this: this->m_pVisualization, a2: this);
  this->m_pVisualization->ActivateItem(this: this->m_pVisualization, a2: 0);
  v9 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v9 != nullptr )
    v10 = vgui::TextEntry::TextEntry(this: v9, parent: this, panelName: "MinOccluderSize");
  else
    v10 = nullptr;
  this->m_pMinOccluderArea = v10;
  v11 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v11 != nullptr )
    v12 = vgui::TextEntry::TextEntry(this: v11, parent: this, panelName: "MaxOccludeeSize");
  else
    v12 = nullptr;
  this->m_pMaxOccludeeArea = v12;
  v13 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v13 != nullptr )
    v14 = vgui::CheckButton::CheckButton(this: v13, parent: this, panelName: "DeactivateOcclusion", text: defaultValue);
  else
    v14 = nullptr;
  this->m_pDeactivateOcclusion = v14;
  v14->AddActionSignalTarget_2(this: v14, a2: this);
  vgui::EditablePanel::LoadControlSettings(
    this,
    resourceName: "Resource\\PerfOcclusionUIPanel.res",
    pathID: nullptr,
    pKeyValues: nullptr,
    pConditions: nullptr);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10203DB0
// Name: public: virtual struct vgui::PanelMessageMap __near * COcclusionUIPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall COcclusionUIPanel::GetMessageMap(COcclusionUIPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`COcclusionUIPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `COcclusionUIPanel::GetMessageMap'::`2'::s_pMap;
  `COcclusionUIPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "COcclusionUIPanel");
  `COcclusionUIPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10203DE0
// Name: public: virtual struct PanelAnimationMap __near * COcclusionUIPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall COcclusionUIPanel::GetAnimMap(COcclusionUIPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "COcclusionUIPanel");
}

//------------------------------------------------------------------------------
// Address: 0x10203DF0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * COcclusionUIPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall COcclusionUIPanel::GetKBMap(COcclusionUIPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`COcclusionUIPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `COcclusionUIPanel::GetKBMap'::`2'::s_pMap;
  `COcclusionUIPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "COcclusionUIPanel");
  `COcclusionUIPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10203E20
// Name: public: static void CPerfUIPanel::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CPerfUIPanel::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
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
  if ( !`CPerfUIPanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `CPerfUIPanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v4 = 0;
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CPerfUIPanel");
    memset(&v3.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v3.m[0][0]) = "TextChanged";
    LODWORD(v3.m[1][0]) =  __thiscall vgui::FileOpenDialog::`vcall'{1116,{flat}};
    memset(&v3.m[1][1], 0, 12);
    LODWORD(v3.m[2][0]) = 1;
    *(_QWORD *)&v3.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10203EC0
// Name: public: CPerfUIPanel::CPerfUIPanel(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CPerfUIPanel *__thiscall CPerfUIPanel::CPerfUIPanel(CPerfUIPanel *this, vgui::Panel *parent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  vgui::ComboBox *v6; // eax
  vgui::ComboBox *v7; // eax
  int v8; // edi
  double v9; // st7
  CPerfUIChildPanel *v10; // eax
  CPerfUIChildPanel *v11; // eax
  vgui::Panel **m_pToolPanel; // edi
  CPropFadeUIPanel *v13; // eax
  CPropFadeUIPanel *v14; // eax
  CAreaPortalsUIPanel *v15; // eax
  CAreaPortalsUIPanel *v16; // eax
  COcclusionUIPanel *v17; // eax
  COcclusionUIPanel *v18; // eax
  int i; // ebx
  double v21; // [esp+Ch] [ebp-8h]
  int savedregs; // [esp+14h] [ebp+0h] BYREF

  vgui::Frame::Frame(this, parent, panelName: "PerfUIPanel", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CPerfUIPanel_vtbl *)&CPerfUIPanel::`vftable';
  if ( `CPerfUIPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CPerfUIPanel::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CPerfUIPanel");
    v3->pfnClassName = CPerfUIPanel::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CPerfUIPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CPerfUIPanel::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CPerfUIPanel");
    v4->pfnClassName = CPerfUIPanel::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CPerfUIPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CPerfUIPanel::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CPerfUIPanel");
    v5->pfnClassName = CPerfUIPanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  CPerfUIPanel::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&savedregs);
  vgui::Frame::SetTitle(this, title: "Level Performance Tools", surfaceTitle: true);
  v6 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v6 != nullptr )
    v7 = vgui::ComboBox::ComboBox(this: v6, parent: this, panelName: "PerformanceTool", numLines: 10, allowEdit: false);
  else
    v7 = nullptr;
  this->m_pPerformanceTool = v7;
  g_pVGui->AddTickSignal(this: g_pVGui, a2: this->_vpanel, a3: 0);
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "Resource\\PerfUIPanel.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  vgui::Panel::SetVisible(this, state: false);
  vgui::Frame::SetSizeable(this, state: false);
  vgui::Frame::SetMoveable(this, state: true);
  v8 = videomode->GetModeWidth(this: videomode) - 260;
  v21 = (double)((videomode->GetModeHeight(this: videomode) - 400) / 2);
  v9 = (double)videomode->GetModeHeight(this: videomode) * 0.2 + v21;
  vgui::Panel::SetBounds(this, x: v8, y: (int)v9, wide: 250, tall: 400);
  v10 = (CPerfUIChildPanel *)MemAlloc_Alloc(nSize: 0x180u);
  if ( v10 != nullptr )
    v11 = CPerfUIChildPanel::CPerfUIChildPanel(this: v10, parent: this, pName: "PerfNone");
  else
    v11 = nullptr;
  m_pToolPanel = this->m_pToolPanel;
  this->m_pToolPanel[0] = v11;
  v13 = (CPropFadeUIPanel *)MemAlloc_Alloc(nSize: 0x190u);
  if ( v13 != nullptr )
    v14 = CPropFadeUIPanel::CPropFadeUIPanel(this: v13, parent: this);
  else
    v14 = nullptr;
  this->m_pToolPanel[1] = v14;
  v15 = (CAreaPortalsUIPanel *)MemAlloc_Alloc(nSize: 0x184u);
  if ( v15 != nullptr )
    v16 = CAreaPortalsUIPanel::CAreaPortalsUIPanel(this: v15, parent: this);
  else
    v16 = nullptr;
  this->m_pToolPanel[2] = v16;
  v17 = (COcclusionUIPanel *)MemAlloc_Alloc(nSize: 0x198u);
  if ( v17 != nullptr )
    v18 = COcclusionUIPanel::COcclusionUIPanel(this: v17, parent: this);
  else
    v18 = nullptr;
  this->m_pToolPanel[3] = v18;
  for ( i = 4; i != 0; --i )
    vgui::Panel::SetBounds(this: *m_pToolPanel++, x: 0, y: 75, wide: 250, tall: 325);
  this->m_nPerfTool = PERF_TOOL_COUNT;
  this->m_pCurrentToolPanel = nullptr;
  CPerfUIPanel::PopulateControls(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10204130
// Name: public: virtual void CEnginePerfTools::InstallPerformanceToolsUI(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnginePerfTools::InstallPerformanceToolsUI(CEnginePerfTools *this, vgui::Panel *parent)
{
  CPerfUIPanel *v2; // eax

  if ( g_pPerfUI == nullptr )
  {
    v2 = (CPerfUIPanel *)MemAlloc_Alloc(nSize: 0x234u);
    if ( v2 != nullptr )
      g_pPerfUI = CPerfUIPanel::CPerfUIPanel(this: v2, parent);
    else
      g_pPerfUI = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1031F0B0
// Name: _dynamic_initializer_for__perfui__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__perfui__()
{
  ConCommand::ConCommand(
    this: &perfui,
    pName: "perfui",
    callback: ShowHidePerfUI,
    pHelpString: "Show/hide the level performance tools UI.",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__perfui__);
}

//------------------------------------------------------------------------------
// Address: 0x10327370
// Name: _dynamic_atexit_destructor_for__perfui__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__perfui__()
{
  ConCommand::~ConCommand(this: &perfui);
}

} // namespace engine_xlsp
