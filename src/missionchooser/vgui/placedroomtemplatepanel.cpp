// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: missionchooser/vgui/placedroomtemplatepanel.cpp
// Functions: 11
// ============================================================

#include "missionchooser\vgui\placedroomtemplatepanel.h"

//------------------------------------------------------------------------------
// Address: 0x100292E0
// Name: public: static char const __near * CPlacedRoomTemplatePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CPlacedRoomTemplatePanel::GetPanelClassName()
{
  return "CPlacedRoomTemplatePanel";
}

//------------------------------------------------------------------------------
// Address: 0x100292F0
// Name: public: virtual void CPlacedRoomTemplatePanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlacedRoomTemplatePanel::PerformLayout(CPlacedRoomTemplatePanel *this)
{
  CRoom *m_pRoom; // eax
  const CRoomTemplate *m_pRoomTemplate; // ecx
  vgui::AnimationController *AnimationController; // eax
  vgui::AnimationController *v5; // eax
  vgui::AnimationController *v6; // eax
  vgui::AnimationController *v7; // eax
  float v8; // [esp-14h] [ebp-28h]
  float v9; // [esp-14h] [ebp-28h]
  float v10; // [esp-14h] [ebp-28h]
  float v11; // [esp-14h] [ebp-28h]
  int startDelaySeconds; // [esp+4h] [ebp-10h] BYREF
  int duration; // [esp+8h] [ebp-Ch] BYREF
  int v14; // [esp+Ch] [ebp-8h] BYREF
  int animParameter; // [esp+10h] [ebp-4h] BYREF

  CRoomTemplatePanel::PerformLayout(this);
  m_pRoom = this->m_pRoom;
  if ( m_pRoom != nullptr )
  {
    m_pRoomTemplate = m_pRoom->m_pRoomTemplate;
    if ( m_pRoomTemplate != nullptr )
    {
      vgui::Panel::SetPos(
        this,
        x: (int)(float)((float)m_pRoom->m_iPosX * g_pTileGenDialog->m_fTileSize),
        y: (int)(float)((float)(120 - m_pRoomTemplate->m_nTilesY - m_pRoom->m_iPosY) * g_pTileGenDialog->m_fTileSize));
      if ( !this->m_bStartedGrowAnimation )
      {
        this->m_bStartedGrowAnimation = true;
        vgui::Panel::GetBounds(this, x: &animParameter, y: &v14, wide: &duration, tall: &startDelaySeconds);
        vgui::Panel::SetBounds(
          this,
          x: (int)(float)((float)((float)duration * 0.5) + (float)animParameter),
          y: (int)(float)((float)((float)startDelaySeconds * 0.5) + (float)v14),
          wide: 0,
          tall: 0);
        v8 = (float)animParameter;
        AnimationController = vgui::GetAnimationController();
        vgui::AnimationController::RunAnimationCommand(
          this: AnimationController,
          panel: this,
          variable: "xpos",
          targetValue: v8,
          startDelaySeconds: 0.0,
          duration: 0.40000001,
          interpolator: INTERPOLATOR_LINEAR,
          animParameter: 0.0);
        v9 = (float)v14;
        v5 = vgui::GetAnimationController();
        vgui::AnimationController::RunAnimationCommand(
          this: v5,
          panel: this,
          variable: "ypos",
          targetValue: v9,
          startDelaySeconds: 0.0,
          duration: 0.40000001,
          interpolator: INTERPOLATOR_LINEAR,
          animParameter: 0.0);
        v10 = (float)duration;
        v6 = vgui::GetAnimationController();
        vgui::AnimationController::RunAnimationCommand(
          this: v6,
          panel: this,
          variable: "wide",
          targetValue: v10,
          startDelaySeconds: 0.0,
          duration: 0.40000001,
          interpolator: INTERPOLATOR_LINEAR,
          animParameter: 0.0);
        v11 = (float)startDelaySeconds;
        v7 = vgui::GetAnimationController();
        vgui::AnimationController::RunAnimationCommand(
          this: v7,
          panel: this,
          variable: "tall",
          targetValue: v11,
          startDelaySeconds: 0.0,
          duration: 0.40000001,
          interpolator: INTERPOLATOR_LINEAR,
          animParameter: 0.0);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100294E0
// Name: public: virtual void CPlacedRoomTemplatePanel::OnMouseReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlacedRoomTemplatePanel::OnMouseReleased(CPlacedRoomTemplatePanel *this, ButtonCode_t code)
{
  CMapLayout *m_pMapLayout; // eax
  CMapLayoutPanel *MapLayoutPanel; // eax
  CMapLayoutPanel *v5; // eax
  int *p_m_iPlayerStartTileX; // [esp-8h] [ebp-10h]
  int *p_m_iPlayerStartTileY; // [esp-4h] [ebp-Ch]

  CRoomTemplatePanel::OnMouseReleased(this, code);
  if ( code == MOUSE_RIGHT )
  {
    m_pMapLayout = g_pTileGenDialog->m_pMapLayout;
    if ( m_pMapLayout != nullptr )
    {
      p_m_iPlayerStartTileY = &m_pMapLayout->m_iPlayerStartTileY;
      p_m_iPlayerStartTileX = &m_pMapLayout->m_iPlayerStartTileX;
      MapLayoutPanel = CTileGenDialog::GetMapLayoutPanel(this: g_pTileGenDialog);
      CMapLayoutPanel::GetCursorTile(this: MapLayoutPanel, tilex: p_m_iPlayerStartTileX, tiley: p_m_iPlayerStartTileY);
      v5 = CTileGenDialog::GetMapLayoutPanel(this: g_pTileGenDialog);
      v5->InvalidateLayout(this: v5, a2: true, a3: false);
      g_pTileGenDialog->Repaint(this: g_pTileGenDialog);
    }
  }
  else if ( (g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LCONTROL)
          || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RCONTROL))
         && !this->m_bDragged
         && !this->m_bSelectedOnThisPress )
  {
    CTileGenDialog::ToggleRoomSelection(this: g_pTileGenDialog, pRoom: this->m_pRoom);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100295A0
// Name: public: virtual void CPlacedRoomTemplatePanel::OnDragged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlacedRoomTemplatePanel::OnDragged(CPlacedRoomTemplatePanel *this)
{
  void (__thiscall *InvalidateLayout)(vgui::Panel *, bool, bool); // edx

  InvalidateLayout = this->InvalidateLayout;
  this->m_bDragged = true;
  ((void (__stdcall *)(int, _DWORD))InvalidateLayout)(a1: 1, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100295C0
// Name: public: virtual void CPlacedRoomTemplatePanel::MarkForDeletion(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlacedRoomTemplatePanel::MarkForDeletion(CPlacedRoomTemplatePanel *this)
{
  vgui::Panel::MarkForDeletion(this);
  this->m_pRoom = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100295E0
// Name: public: virtual struct vgui::PanelMessageMap __near * CPlacedRoomTemplatePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CPlacedRoomTemplatePanel::GetMessageMap(CPlacedRoomTemplatePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CPlacedRoomTemplatePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CPlacedRoomTemplatePanel::GetMessageMap'::`2'::s_pMap;
  `CPlacedRoomTemplatePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CPlacedRoomTemplatePanel");
  `CPlacedRoomTemplatePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10029610
// Name: public: virtual struct PanelAnimationMap __near * CPlacedRoomTemplatePanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CPlacedRoomTemplatePanel::GetAnimMap(CPlacedRoomTemplatePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CPlacedRoomTemplatePanel");
}

//------------------------------------------------------------------------------
// Address: 0x10029620
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CPlacedRoomTemplatePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CPlacedRoomTemplatePanel::GetKBMap(CPlacedRoomTemplatePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CPlacedRoomTemplatePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CPlacedRoomTemplatePanel::GetKBMap'::`2'::s_pMap;
  `CPlacedRoomTemplatePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CPlacedRoomTemplatePanel");
  `CPlacedRoomTemplatePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10029650
// Name: public: CPlacedRoomTemplatePanel::CPlacedRoomTemplatePanel(class CRoom __near *,class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CPlacedRoomTemplatePanel *__thiscall CPlacedRoomTemplatePanel::CPlacedRoomTemplatePanel(
        CPlacedRoomTemplatePanel *this,
        CRoom *pRoom,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi

  CRoomTemplatePanel::CRoomTemplatePanel(this, parent, name);
  this->__vftable = (CPlacedRoomTemplatePanel_vtbl *)&CPlacedRoomTemplatePanel::`vftable';
  if ( `CPlacedRoomTemplatePanel::ChainToMap'::`2'::chained == 0 )
  {
    `CPlacedRoomTemplatePanel::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CPlacedRoomTemplatePanel");
    v5->pfnClassName = CPlacedRoomTemplatePanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "CRoomTemplatePanel");
  }
  if ( `CPlacedRoomTemplatePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CPlacedRoomTemplatePanel::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CPlacedRoomTemplatePanel");
    v6->pfnClassName = CPlacedRoomTemplatePanel::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "CRoomTemplatePanel");
  }
  if ( `CPlacedRoomTemplatePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CPlacedRoomTemplatePanel::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CPlacedRoomTemplatePanel");
    v7->pfnClassName = CPlacedRoomTemplatePanel::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CRoomTemplatePanel");
  }
  this->m_pRoom = pRoom;
  CRoomTemplatePanel::SetRoomTemplate(this, pTemplate: pRoom->m_pRoomTemplate);
  *(_WORD *)&this->m_bSetAlpha = 0;
  this->m_bSelectedOnThisPress = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10029770
// Name: public: virtual void CPlacedRoomTemplatePanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlacedRoomTemplatePanel::ApplySchemeSettings(CPlacedRoomTemplatePanel *this, vgui::IScheme *pScheme)
{
  vgui::AnimationController *AnimationController; // eax
  int m_Size; // edx
  int v5; // eax
  CRoom **m_pMemory; // ecx

  CRoomTemplatePanel::ApplySchemeSettings(this, pScheme);
  if ( !this->m_bSetAlpha )
  {
    this->m_bSetAlpha = true;
    vgui::Panel::SetAlpha(this, alpha: 0);
    AnimationController = vgui::GetAnimationController();
    vgui::AnimationController::RunAnimationCommand(
      this: AnimationController,
      panel: this,
      variable: "alpha",
      targetValue: 255.0,
      startDelaySeconds: 0.0,
      duration: 0.40000001,
      interpolator: INTERPOLATOR_LINEAR,
      animParameter: 0.0);
  }
  if ( g_pTileGenDialog == nullptr )
    goto LABEL_8;
  m_Size = g_pTileGenDialog->m_SelectedRooms.m_Size;
  v5 = 0;
  if ( m_Size <= 0 )
    goto LABEL_8;
  m_pMemory = g_pTileGenDialog->m_SelectedRooms.m_Memory.m_pMemory;
  while ( *m_pMemory != this->m_pRoom )
  {
    ++v5;
    ++m_pMemory;
    if ( v5 >= m_Size )
      goto LABEL_8;
  }
  if ( v5 == -1 )
LABEL_8:
    this->m_pSelectedOutline->SetVisible(this: this->m_pSelectedOutline, a2: false);
  else
    this->m_pSelectedOutline->SetVisible(this: this->m_pSelectedOutline, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x10029830
// Name: public: virtual void CPlacedRoomTemplatePanel::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlacedRoomTemplatePanel::OnMousePressed(CPlacedRoomTemplatePanel *this, ButtonCode_t code)
{
  CTileGenDialog *v3; // edi
  int m_Size; // ecx
  int v5; // eax
  CRoom **m_pMemory; // edx
  int v7; // edx
  int v8; // eax
  CRoom **v9; // ecx

  CRoomTemplatePanel::OnMouseReleased(this, code);
  if ( code == KEY_COUNT )
  {
    *(_WORD *)&this->m_bSelectedOnThisPress = 0;
    v3 = g_pTileGenDialog;
    m_Size = g_pTileGenDialog->m_SelectedRooms.m_Size;
    v5 = 0;
    if ( m_Size <= 0 )
      goto LABEL_8;
    m_pMemory = g_pTileGenDialog->m_SelectedRooms.m_Memory.m_pMemory;
    while ( *m_pMemory != this->m_pRoom )
    {
      ++v5;
      ++m_pMemory;
      if ( v5 >= m_Size )
        goto LABEL_8;
    }
    if ( v5 == -1 )
    {
LABEL_8:
      if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LCONTROL)
        || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RCONTROL) )
      {
        CTileGenDialog::ToggleRoomSelection(this: g_pTileGenDialog, pRoom: this->m_pRoom);
      }
      else
      {
        CTileGenDialog::SetRoomSelection(this: g_pTileGenDialog, pRoom: this->m_pRoom);
      }
      this->m_bSelectedOnThisPress = true;
      v3 = g_pTileGenDialog;
    }
    v7 = v3->m_SelectedRooms.m_Size;
    v8 = 0;
    if ( v7 <= 0 )
      goto LABEL_17;
    v9 = v3->m_SelectedRooms.m_Memory.m_pMemory;
    while ( *v9 != this->m_pRoom )
    {
      ++v8;
      ++v9;
      if ( v8 >= v7 )
        goto LABEL_17;
    }
    if ( v8 == -1 )
    {
LABEL_17:
      this->m_bSelectedOnThisPress = false;
    }
    else
    {
      this->MoveToFront(this);
      CTileGenDialog::OnStartDraggingSelectedRooms(this: g_pTileGenDialog);
    }
  }
}
