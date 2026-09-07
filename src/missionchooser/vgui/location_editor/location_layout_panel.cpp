// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: missionchooser/vgui/location_editor/location_layout_panel.cpp
// Functions: 23
// ============================================================

#include "missionchooser\vgui\location_editor\location_layout_panel.h"

//------------------------------------------------------------------------------
// Address: 0x10010CF0
// Name: public: static char const __near * CLocation_Panel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CLocation_Panel::GetPanelClassName()
{
  return "CLocation_Panel";
}

//------------------------------------------------------------------------------
// Address: 0x10010D00
// Name: public: static char const __near * CLocation_Layout_Panel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CLocation_Layout_Panel::GetPanelClassName()
{
  return "CLocation_Layout_Panel";
}

//------------------------------------------------------------------------------
// Address: 0x10010D10
// Name: public: virtual void CLocation_Layout_Panel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocation_Layout_Panel::PerformLayout(CLocation_Layout_Panel *this)
{
  vgui::Panel::PerformLayout(this);
  vgui::Panel::SetSize(this, wide: 1819, tall: 1024);
  this->m_pBgImage->SetImage(this: this->m_pBgImage, a2: "briefing/map.vmt");
  vgui::Panel::SetSize(this: this->m_pBgImage, wide: 1819, tall: 1024);
}

//------------------------------------------------------------------------------
// Address: 0x10010D60
// Name: public: void CLocation_Panel::SetLocationID(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocation_Panel::SetLocationID(CLocation_Panel *this, int i)
{
  KeyValues *m_actionMessage; // ecx
  KeyValues *v4; // eax
  KeyValues *v5; // eax
  char buffer[32]; // [esp+8h] [ebp-20h] BYREF

  m_actionMessage = this->m_actionMessage;
  this->m_iLocationID = i;
  if ( m_actionMessage != nullptr )
    KeyValues::deleteThis(this: m_actionMessage);
  V_snprintf(pDest: buffer, maxLen: 32, pFormat: "Location%d", i);
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "command", firstKey: "command", firstValue: buffer);
  else
    v5 = nullptr;
  this->m_actionMessage = v5;
  V_snprintf(pDest: buffer, maxLen: 32, pFormat: "%d", i);
  this->m_pIDLabel->SetText(this: this->m_pIDLabel, a2: buffer);
}

//------------------------------------------------------------------------------
// Address: 0x10010DF0
// Name: private: bool CLocation_Panel::IsCursorOverHex(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CLocation_Panel::IsCursorOverHex(CLocation_Panel *this)
{
  bool result; // al
  float v3; // [esp+4h] [ebp-Ch]
  float v4; // [esp+4h] [ebp-Ch]
  int current_posy; // [esp+8h] [ebp-8h] BYREF
  int current_posx; // [esp+Ch] [ebp-4h] BYREF

  result = false;
  if ( this->IsCursorOver(this) )
  {
    g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &current_posx, a3: &current_posy);
    vgui::Panel::ScreenToLocal(this, x: &current_posx, y: &current_posy);
    v3 = (float)current_posx;
    if ( v3 <= (float)((float)vgui::Panel::GetWide(this) * 0.75) )
    {
      v4 = (float)current_posy;
      if ( v4 <= (float)((float)vgui::Panel::GetTall(this) * 0.85000002) )
        return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10010EA0
// Name: public: virtual void CLocation_Panel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocation_Panel::PerformLayout(CLocation_Panel *this)
{
  CASW_Mission_Chooser *v2; // ecx
  CASW_Mission_Chooser *v3; // ecx
  IASW_Location_Grid *v4; // eax
  int v5; // esi
  int v6; // eax
  int m_iLastXPos; // ecx
  double v8; // xmm0_8
  int v9; // ebx
  int v10; // [esp-Ch] [ebp-18h]
  int x; // [esp+4h] [ebp-8h]

  vgui::Panel::PerformLayout(this);
  if ( CASW_Mission_Chooser::LocationGrid(this: v2) != nullptr )
  {
    v4 = CASW_Mission_Chooser::LocationGrid(this: v3);
    v5 = (int)v4->GetLocationByID(this: v4, a2: this->m_iLocationID);
    if ( v5 != 0 )
    {
      this->m_iLastXPos = (int)((double)(*(int (__thiscall **)(int))(*(_DWORD *)v5 + 16))(a1: v5) * 2.133333333333333);
      v6 = (*(int (__thiscall **)(int))(*(_DWORD *)v5 + 20))(a1: v5);
      m_iLastXPos = this->m_iLastXPos;
      v8 = (double)v6 * 2.133333333333333;
      this->m_iLastYPos = (int)v8;
      x = m_iLastXPos;
      v9 = 0;
      if ( (*(int (__thiscall **)(int))(*(_DWORD *)v5 + 68))(a1: v5) != 0 )
        v9 = 9;
      v10 = 2 * (23 - v9);
      if ( this->m_bDragging )
        vgui::Panel::SetSize(this, wide: v10, tall: v10);
      else
        vgui::Panel::SetBounds(this, x: x + v9, y: v9 + (int)v8, wide: v10, tall: v10);
      vgui::Panel::SetBounds(this: this->m_pHexImage, x: 0, y: 0, wide: 2 * (23 - v9), tall: 2 * (23 - v9));
      vgui::Panel::SetBounds(this: this->m_pIDLabel, x: 0, y: 0, wide: 46, tall: 46);
      vgui::Panel::SetZPos(this: this->m_pIDLabel, z: 2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10010FB0
// Name: public: virtual struct vgui::PanelMessageMap __near * CLocation_Panel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CLocation_Panel::GetMessageMap(CLocation_Panel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CLocation_Panel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CLocation_Panel::GetMessageMap'::`2'::s_pMap;
  `CLocation_Panel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CLocation_Panel");
  `CLocation_Panel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10010FE0
// Name: public: virtual struct PanelAnimationMap __near * CLocation_Panel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CLocation_Panel::GetAnimMap(CLocation_Panel *this)
{
  return FindOrAddPanelAnimationMap(className: "CLocation_Panel");
}

//------------------------------------------------------------------------------
// Address: 0x10011000
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CLocation_Panel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CLocation_Panel::GetKBMap(CLocation_Panel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CLocation_Panel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CLocation_Panel::GetKBMap'::`2'::s_pMap;
  `CLocation_Panel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CLocation_Panel");
  `CLocation_Panel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10011030
// Name: public: virtual void CLocation_Layout_Panel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocation_Layout_Panel::ApplySchemeSettings(CLocation_Layout_Panel *this, vgui::IScheme *scheme)
{
  vgui::Panel::ApplySchemeSettings(this, pScheme: scheme);
  this->SetPaintBackgroundEnabled(this, a2: true);
  this->SetPaintBackgroundType(this, a2: 0);
  ((void (__thiscall *)(CLocation_Layout_Panel *, int))this->SetBgColor)(a1: this, a2: -16777216);
}

//------------------------------------------------------------------------------
// Address: 0x10011080
// Name: public: CLocation_Panel::CLocation_Panel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CLocation_Panel *__thiscall CLocation_Panel::CLocation_Panel(
        CLocation_Panel *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::ImagePanel *v7; // eax
  vgui::ImagePanel *v8; // eax
  vgui::Label *v9; // eax
  vgui::Label *v10; // eax

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (CLocation_Panel_vtbl *)&CLocation_Panel::`vftable';
  if ( `CLocation_Panel::ChainToMap'::`2'::chained == 0 )
  {
    `CLocation_Panel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CLocation_Panel");
    v4->pfnClassName = CLocation_Panel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Panel");
  }
  if ( `CLocation_Panel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CLocation_Panel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CLocation_Panel");
    v5->pfnClassName = CLocation_Panel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Panel");
  }
  if ( `CLocation_Panel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CLocation_Panel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CLocation_Panel");
    v6->pfnClassName = CLocation_Panel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Panel");
  }
  this->m_iLocationID = -1;
  v7 = (vgui::ImagePanel *)operator new(nSize: 0x17Cu);
  if ( v7 != nullptr )
    v8 = vgui::ImagePanel::ImagePanel(this: v7, parent: this, name: "HexImage");
  else
    v8 = nullptr;
  this->m_pHexImage = v8;
  vgui::ImagePanel::SetShouldScaleImage(this: v8, state: true);
  this->m_pHexImage->SetMouseInputEnabled(this: this->m_pHexImage, a2: false);
  this->m_actionMessage = nullptr;
  this->m_pLayoutPanel = (CLocation_Layout_Panel *)__RTDynamicCast(
                                                     inptr: parent,
                                                     VfDelta: 0,
                                                     SrcType: &vgui::Panel `RTTI Type Descriptor',
                                                     TargetType: &CLocation_Layout_Panel `RTTI Type Descriptor',
                                                     isReference: 0);
  this->m_bDragging = false;
  v9 = (vgui::Label *)operator new(nSize: 0x1A4u);
  if ( v9 != nullptr )
    v10 = vgui::Label::Label(this: v9, parent: this, panelName: "IDLabel", text: szDescription);
  else
    v10 = nullptr;
  this->m_pIDLabel = v10;
  v10->SetContentAlignment(this: v10, a2: a_center);
  this->m_pIDLabel->SetMouseInputEnabled(this: this->m_pIDLabel, a2: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10011250
// Name: public: virtual void CLocation_Panel::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocation_Panel::OnMousePressed(CLocation_Panel *this, ButtonCode_t code)
{
  int v3; // ecx
  int current_posy; // [esp+4h] [ebp-10h] BYREF
  int y; // [esp+8h] [ebp-Ch] BYREF
  int current_posx; // [esp+Ch] [ebp-8h] BYREF
  int x; // [esp+10h] [ebp-4h] BYREF

  if ( CLocation_Panel::IsCursorOverHex(this)
    && this->m_pLayoutPanel->m_pEditorFrame->m_iCurrentLocationID == this->m_iLocationID )
  {
    this->m_bDragging = true;
    vgui::Panel::GetPos(this, &x, &y);
    g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &current_posx, a3: &current_posy);
    v3 = y - current_posy;
    this->m_MouseOffset.x = (float)(x - current_posx);
    this->m_MouseOffset.y = (float)v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100112E0
// Name: public: virtual void CLocation_Panel::OnMouseReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocation_Panel::OnMouseReleased(CLocation_Panel *this, ButtonCode_t code)
{
  CLocation_Panel_vtbl *v3; // edi
  KeyValues *Copy; // eax

  if ( CLocation_Panel::IsCursorOverHex(this) )
  {
    v3 = this->__vftable;
    Copy = KeyValues::MakeCopy(this: this->m_actionMessage);
    v3->PostActionSignal(this, a2: Copy);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011310
// Name: private: void CLocation_Panel::UpdateHexColor(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocation_Panel::UpdateHexColor(CLocation_Panel *this)
{
  CASW_Mission_Chooser *v2; // ecx
  IASW_Location_Grid *v3; // eax
  CLocation_Editor_Frame *m_pEditorFrame; // edi

  if ( CASW_Mission_Chooser::LocationGrid((CASW_Mission_Chooser *)this) != nullptr )
  {
    v3 = CASW_Mission_Chooser::LocationGrid(this: v2);
    if ( v3->GetLocationByID(this: v3, a2: this->m_iLocationID) != nullptr )
    {
      m_pEditorFrame = this->m_pLayoutPanel->m_pEditorFrame;
      if ( CLocation_Panel::IsCursorOverHex(this) )
      {
        ((void (__thiscall *)(vgui::ImagePanel *, int))this->m_pHexImage->SetDrawColor)(
          a1: this->m_pHexImage,
          a2: -922746881);
      }
      else if ( m_pEditorFrame != nullptr && m_pEditorFrame->m_iCurrentLocationID == this->m_iLocationID )
      {
        ((void (__thiscall *)(vgui::ImagePanel *, int))this->m_pHexImage->SetDrawColor)(
          a1: this->m_pHexImage,
          a2: -939458561);
      }
      else
      {
        ((void (__thiscall *)(vgui::ImagePanel *, int))this->m_pHexImage->SetDrawColor)(
          a1: this->m_pHexImage,
          a2: -926365496);
      }
    }
    else
    {
      ((void (__thiscall *)(vgui::ImagePanel *, _DWORD))this->m_pHexImage->SetDrawColor)(a1: this->m_pHexImage, a2: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100113F0
// Name: public: virtual void CLocation_Panel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocation_Panel::ApplySchemeSettings(CLocation_Panel *this, vgui::IScheme *scheme)
{
  vgui::Label_vtbl *v3; // ebx
  unsigned int v4; // eax

  vgui::Panel::ApplySchemeSettings(this, pScheme: scheme);
  this->SetPaintBackgroundEnabled(this, a2: false);
  v3 = this->m_pIDLabel->__vftable;
  v4 = scheme->GetFont(this: scheme, a2: "DefaultVerySmall", a3: false);
  v3->SetFont(this: this->m_pIDLabel, a2: v4);
  ((void (__thiscall *)(vgui::Label *, int))this->m_pIDLabel->SetFgColor)(a1: this->m_pIDLabel, a2: -1);
  this->m_pIDLabel->SetPaintBackgroundEnabled(this: this->m_pIDLabel, a2: false);
  this->m_pHexImage->SetImage(this: this->m_pHexImage, a2: "briefing/map_icon_available.vmt");
  CLocation_Panel::UpdateHexColor(this);
}

//------------------------------------------------------------------------------
// Address: 0x10011490
// Name: public: virtual void CLocation_Panel::OnThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocation_Panel::OnThink(CLocation_Panel *this)
{
  int v2; // ebx
  CASW_Mission_Chooser *v3; // ecx
  IASW_Location_Grid *v4; // eax
  int v5; // edi
  vgui::Panel *v6; // eax
  CLocation_Editor_Frame *m_pEditorFrame; // ebx
  IASW_Location_Group *v8; // eax
  CASW_Mission_Chooser *v9; // ecx
  CASW_Mission_Chooser *v10; // ecx
  IASW_Location_Grid *v11; // eax
  int v12; // edi
  int (__thiscall *v13)(int); // edx
  double v14; // xmm0_8
  int (__thiscall *v15)(int); // edx
  double v16; // xmm0_8
  double m_iLastXPos; // [esp+24h] [ebp-18h] BYREF
  int wide_4; // [esp+2Ch] [ebp-10h] BYREF
  int v19[2]; // [esp+30h] [ebp-Ch] BYREF
  int v20; // [esp+38h] [ebp-4h] BYREF

  if ( this->m_bDragging )
  {
    if ( g_pVGuiInput->IsMouseDown(this: g_pVGuiInput, a2: KEY_COUNT) )
    {
      g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &wide_4, a3: (int *)((char *)&m_iLastXPos + 4));
      vgui::Panel::SetPos(
        this,
        x: (int)(float)((float)wide_4 + this->m_MouseOffset.x),
        y: (int)(float)((float)SHIDWORD(m_iLastXPos) + this->m_MouseOffset.y));
    }
    else
    {
      this->m_bDragging = false;
      vgui::Panel::GetPos(this, x: &v19[1], y: &v20);
      v2 = (int)((double)v19[1] * 0.46875);
      v19[0] = (int)((double)v20 * 0.46875);
      v4 = CASW_Mission_Chooser::LocationGrid(this: v3);
      v5 = (int)v4->GetLocationByID(this: v4, a2: this->m_iLocationID);
      if ( v5 != 0 )
      {
        (*(void (__thiscall **)(int, int, int))(*(_DWORD *)v5 + 76))(a1: v5, a2: v2, a3: v19[0]);
        if ( (**(int (__thiscall ***)(int))v5)(a1: v5) == 21 )
        {
          v6 = this->GetParent(this);
          vgui::Panel::GetSize(this: v6, wide: (int *)&m_iLastXPos + 1, tall: &wide_4);
          _Msg(
            a1: "EdLoc21 x=%d y=%d fx=%d fx=%d xfrac=%f yfrac=%f edw=%d edh=%d\n",
            v19[1],
            v20,
            v2,
            v19[0],
            (float)((float)v19[1] / (float)SHIDWORD(m_iLastXPos)),
            (float)((float)v20 / (float)wide_4),
            HIDWORD(m_iLastXPos),
            wide_4);
        }
        m_pEditorFrame = this->m_pLayoutPanel->m_pEditorFrame;
        v8 = (IASW_Location_Group *)(*(int (__thiscall **)(int))(*(_DWORD *)v5 + 4))(a1: v5);
        CLocation_Editor_Frame::SetGroup(this: m_pEditorFrame, pGroup: v8);
      }
    }
  }
  CLocation_Panel::UpdateHexColor(this);
  CLocation_Panel::IsCursorOverHex(this);
  if ( CASW_Mission_Chooser::LocationGrid(this: v9) != nullptr )
  {
    v11 = CASW_Mission_Chooser::LocationGrid(this: v10);
    v12 = (int)v11->GetLocationByID(this: v11, a2: this->m_iLocationID);
    if ( v12 != 0 )
    {
      v13 = *(int (__thiscall **)(int))(*(_DWORD *)v12 + 16);
      m_iLastXPos = (double)this->m_iLastXPos;
      v14 = (double)v13(a1: v12) * 2.133333333333333;
      if ( m_iLastXPos != v14
        || (v15 = *(int (__thiscall **)(int))(*(_DWORD *)v12 + 20),
            m_iLastXPos = (double)this->m_iLastYPos,
            v16 = (double)v15(a1: v12) * 2.133333333333333,
            m_iLastXPos != v16) )
      {
        this->InvalidateLayout(this, a2: true, a3: false);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100116E0
// Name: public: CLocation_Layout_Panel::CLocation_Layout_Panel(class vgui::Panel __near *,class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CLocation_Layout_Panel *__thiscall CLocation_Layout_Panel::CLocation_Layout_Panel(
        CLocation_Layout_Panel *this,
        vgui::Panel *parent,
        vgui::Panel *pActionTarget,
        const char *name)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::ImagePanel *v8; // eax
  vgui::ImagePanel *v9; // eax

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (CLocation_Layout_Panel_vtbl *)&CLocation_Layout_Panel::`vftable';
  if ( `CLocation_Layout_Panel::ChainToMap'::`2'::chained == 0 )
  {
    `CLocation_Layout_Panel::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CLocation_Layout_Panel");
    v5->pfnClassName = CLocation_Layout_Panel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Panel");
  }
  if ( `CLocation_Layout_Panel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CLocation_Layout_Panel::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CLocation_Layout_Panel");
    v6->pfnClassName = CLocation_Layout_Panel::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Panel");
  }
  if ( `CLocation_Layout_Panel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CLocation_Layout_Panel::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CLocation_Layout_Panel");
    v7->pfnClassName = CLocation_Layout_Panel::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Panel");
  }
  this->m_LocationPanels.m_Memory.m_pMemory = nullptr;
  this->m_LocationPanels.m_Memory.m_nAllocationCount = 0;
  this->m_LocationPanels.m_Memory.m_nGrowSize = 0;
  this->m_LocationPanels.m_Size = 0;
  this->m_LocationPanels.m_pElements = nullptr;
  this->m_pActionTarget = pActionTarget;
  this->m_pEditorFrame = (CLocation_Editor_Frame *)__RTDynamicCast(
                                                     inptr: parent,
                                                     VfDelta: 0,
                                                     SrcType: &vgui::Panel `RTTI Type Descriptor',
                                                     TargetType: &CLocation_Editor_Frame `RTTI Type Descriptor',
                                                     isReference: 0);
  v8 = (vgui::ImagePanel *)operator new(nSize: 0x17Cu);
  if ( v8 != nullptr )
    v9 = vgui::ImagePanel::ImagePanel(this: v8, parent: this, name: "LayoutBgImage");
  else
    v9 = nullptr;
  this->m_pBgImage = v9;
  vgui::ImagePanel::SetShouldScaleImage(this: v9, state: true);
  this->m_pBgImage->SetMouseInputEnabled(this: this->m_pBgImage, a2: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10011830
// Name: public: virtual struct vgui::PanelMessageMap __near * CLocation_Layout_Panel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CLocation_Layout_Panel::GetMessageMap(CLocation_Layout_Panel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CLocation_Layout_Panel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CLocation_Layout_Panel::GetMessageMap'::`2'::s_pMap;
  `CLocation_Layout_Panel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CLocation_Layout_Panel");
  `CLocation_Layout_Panel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10011860
// Name: public: virtual struct PanelAnimationMap __near * CLocation_Layout_Panel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CLocation_Layout_Panel::GetAnimMap(CLocation_Layout_Panel *this)
{
  return FindOrAddPanelAnimationMap(className: "CLocation_Layout_Panel");
}

//------------------------------------------------------------------------------
// Address: 0x10011870
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CLocation_Layout_Panel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CLocation_Layout_Panel::GetKBMap(CLocation_Layout_Panel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CLocation_Layout_Panel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CLocation_Layout_Panel::GetKBMap'::`2'::s_pMap;
  `CLocation_Layout_Panel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CLocation_Layout_Panel");
  `CLocation_Layout_Panel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100118E0
// Name: public: void CLocation_Layout_Panel::CreateLocationPanels(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocation_Layout_Panel::CreateLocationPanels(CLocation_Layout_Panel *this)
{
  CLocation_Layout_Panel *v1; // edi
  CASW_Mission_Chooser *v2; // ecx
  int v3; // esi
  IASW_Location_Grid *v4; // eax
  CASW_Mission_Chooser *v5; // ecx
  IASW_Location_Grid *v6; // eax
  int v7; // eax
  CASW_Mission_Chooser *v8; // ecx
  int v9; // ebx
  CUtlMemory<vgui::TreeNode *,int> *p_m_LocationPanels; // esi
  CLocation_Panel *v11; // eax
  CLocation_Panel *v12; // eax
  vgui::TreeNode **m_pMemory; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v15; // ecx
  int v16; // eax
  CLocation_Panel **v17; // edi
  int (__thiscall ***v18)(_DWORD); // eax
  CLocation_Panel **v19; // edi
  int v20; // eax
  IASW_Location_Grid *v21; // eax
  int i; // [esp+4h] [ebp-14h]
  int k; // [esp+Ch] [ebp-Ch]
  CLocation_Panel *pPanel; // [esp+10h] [ebp-8h]
  int iCount; // [esp+14h] [ebp-4h]

  v1 = this;
  if ( CASW_Mission_Chooser::LocationGrid((CASW_Mission_Chooser *)this) != nullptr )
  {
    v3 = 0;
    iCount = 0;
    i = 0;
    v4 = CASW_Mission_Chooser::LocationGrid(this: v2);
    if ( v4->GetNumGroups(this: v4) > 0 )
    {
      do
      {
        v6 = CASW_Mission_Chooser::LocationGrid(this: v5);
        v7 = (int)v6->GetGroup(this: v6, a2: v3);
        v9 = v7;
        if ( v7 != 0 )
        {
          k = 0;
          if ( (*(int (__thiscall **)(int))(*(_DWORD *)v7 + 28))(a1: v7) > 0 )
          {
            p_m_LocationPanels = (CUtlMemory<vgui::TreeNode *,int> *)&v1->m_LocationPanels;
            do
            {
              if ( v1->m_LocationPanels.m_Size <= iCount )
              {
                v11 = (CLocation_Panel *)operator new(nSize: 0x178u);
                if ( v11 != nullptr )
                {
                  v12 = CLocation_Panel::CLocation_Panel(this: v11, parent: v1, name: "Location_Panel");
                  pPanel = v12;
                }
                else
                {
                  pPanel = nullptr;
                  v12 = nullptr;
                }
                v12->AddActionSignalTarget_2(this: v12, a2: v1->m_pActionTarget);
                m_pMemory = p_m_LocationPanels[1].m_pMemory;
                m_nAllocationCount = p_m_LocationPanels->m_nAllocationCount;
                if ( (int)m_pMemory + 1 > m_nAllocationCount )
                  CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
                    this: p_m_LocationPanels,
                    num: (int)m_pMemory - m_nAllocationCount + 1);
                ++p_m_LocationPanels[1].m_pMemory;
                v15 = p_m_LocationPanels->m_pMemory;
                v16 = (char *)p_m_LocationPanels[1].m_pMemory - (char *)m_pMemory - 1;
                p_m_LocationPanels[1].m_nAllocationCount = (int)p_m_LocationPanels->m_pMemory;
                if ( v16 > 0 )
                  _V_memmove(dest: &v15[(_DWORD)m_pMemory + 1], src: &v15[(_DWORD)m_pMemory], count: 4 * v16);
                v17 = (CLocation_Panel **)&p_m_LocationPanels->m_pMemory[(_DWORD)m_pMemory];
                if ( v17 != nullptr )
                  *v17 = pPanel;
              }
              v18 = (int (__thiscall ***)(_DWORD))(*(int (__thiscall **)(int, int))(*(_DWORD *)v9 + 32))(a1: v9, a2: k);
              v19 = (CLocation_Panel **)&p_m_LocationPanels->m_pMemory[iCount];
              v20 = (**v18)(a1: v18);
              CLocation_Panel::SetLocationID(this: *v19, i: v20);
              ++iCount;
              ++k;
              v1 = this;
            }
            while ( k < (*(int (__thiscall **)(int))(*(_DWORD *)v9 + 28))(a1: v9) );
            v3 = i;
          }
        }
        i = ++v3;
        v21 = CASW_Mission_Chooser::LocationGrid(this: v8);
      }
      while ( v3 < v21->GetNumGroups(this: v21) );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011A60
// Name: public: virtual void CLocation_Layout_Panel::OnThink(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CLocation_Layout_Panel::OnThink(CLocation_Layout_Panel *this)
{
  CLocation_Layout_Panel::CreateLocationPanels(this);
}

//------------------------------------------------------------------------------
// Address: 0x100628F0
// Name: public: Vector2D::Vector2D(void)
// Source: json
//------------------------------------------------------------------------------
cplane_t *__thiscall Vector2D::Vector2D(cplane_t *this)
{
  return this;
}
