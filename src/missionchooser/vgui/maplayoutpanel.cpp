// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: missionchooser/vgui/maplayoutpanel.cpp
// Functions: 16
// ============================================================

#include "missionchooser\vgui\maplayoutpanel.h"

//------------------------------------------------------------------------------
// Address: 0x10027D20
// Name: public: static char const __near * CMapLayoutPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CMapLayoutPanel::GetPanelClassName()
{
  return "CMapLayoutPanel";
}

//------------------------------------------------------------------------------
// Address: 0x10027D30
// Name: public: void CMapLayoutPanel::GetCursorTile(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapLayoutPanel::GetCursorTile(CMapLayoutPanel *this, int *tilex, int *tiley)
{
  __m128i v4; // xmm0
  int my; // [esp+4h] [ebp-8h] BYREF
  int mx; // [esp+8h] [ebp-4h] BYREF

  if ( g_pTileGenDialog != nullptr )
  {
    g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &mx, a3: &my);
    vgui::Panel::ScreenToLocal(this, x: &mx, y: &my);
    v4 = _mm_cvtsi32_si128(my);
    *tilex = (int)(float)((float)mx / g_pTileGenDialog->m_fTileSize);
    *tiley = 119 - (int)(float)(_mm_cvtepi32_ps(v4).m128_f32[0] / g_pTileGenDialog->m_fTileSize);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10027DB0
// Name: public: virtual void CMapLayoutPanel::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapLayoutPanel::OnMousePressed(CMapLayoutPanel *this, int code)
{
  int mx; // [esp+4h] [ebp-4h] BYREF

  if ( g_pTileGenDialog != nullptr && g_pTileGenDialog->m_pCursorTemplate == nullptr && code == 107 )
  {
    g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &mx, a3: &code);
    vgui::Panel::ScreenToLocal(this, x: &mx, y: &code);
    CTileGenDialog::StartRubberBandSelection(this: g_pTileGenDialog, mx, my: code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10027E10
// Name: private: class CMapLayout __near * CMapLayoutPanel::GetMapLayout(void)
// Source: json
//------------------------------------------------------------------------------
CMapLayout *__thiscall CMapLayoutPanel::GetMapLayout(CMapLayoutPanel *this)
{
  if ( g_pTileGenDialog != nullptr )
    return g_pTileGenDialog->m_pMapLayout;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10027E30
// Name: public: virtual struct vgui::PanelMessageMap __near * CMapLayoutPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CMapLayoutPanel::GetMessageMap(CMapLayoutPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CMapLayoutPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CMapLayoutPanel::GetMessageMap'::`2'::s_pMap;
  `CMapLayoutPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CMapLayoutPanel");
  `CMapLayoutPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10027E60
// Name: public: virtual struct PanelAnimationMap __near * CMapLayoutPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CMapLayoutPanel::GetAnimMap(CMapLayoutPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CMapLayoutPanel");
}

//------------------------------------------------------------------------------
// Address: 0x10027E70
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CMapLayoutPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CMapLayoutPanel::GetKBMap(CMapLayoutPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CMapLayoutPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CMapLayoutPanel::GetKBMap'::`2'::s_pMap;
  `CMapLayoutPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CMapLayoutPanel");
  `CMapLayoutPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10027EA0
// Name: public: CMapLayoutPanel::CMapLayoutPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CMapLayoutPanel *__thiscall CMapLayoutPanel::CMapLayoutPanel(
        CMapLayoutPanel *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CMissionChooserTGAImagePanel *v7; // eax
  CMissionChooserTGAImagePanel *v8; // eax
  CNPC_Spawns_Panel *v9; // eax
  CNPC_Spawns_Panel *v10; // eax

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (CMapLayoutPanel_vtbl *)&CMapLayoutPanel::`vftable';
  if ( `CMapLayoutPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CMapLayoutPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CMapLayoutPanel");
    v4->pfnClassName = CMapLayoutPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Panel");
  }
  if ( `CMapLayoutPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CMapLayoutPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CMapLayoutPanel");
    v5->pfnClassName = CMapLayoutPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Panel");
  }
  if ( `CMapLayoutPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CMapLayoutPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CMapLayoutPanel");
    v6->pfnClassName = CMapLayoutPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Panel");
  }
  vgui::Panel::SetPaintBackgroundEnabled(this, state: true);
  vgui::Panel::SetMouseInputEnabled(this, state: true);
  v7 = (CMissionChooserTGAImagePanel *)operator new(nSize: 0x258u);
  if ( v7 != nullptr )
    v8 = CMissionChooserTGAImagePanel::CMissionChooserTGAImagePanel(
           this: v7,
           parent: this,
           name: "PlayerStartImagePanel");
  else
    v8 = nullptr;
  this->m_pPlayerStartImagePanel = v8;
  vgui::Panel::SetZPos(this: v8, z: 10);
  v9 = (CNPC_Spawns_Panel *)operator new(nSize: 0x158u);
  if ( v9 != nullptr )
    v10 = CNPC_Spawns_Panel::CNPC_Spawns_Panel(this: v9, parent: this, name: "SpawnsPanel");
  else
    v10 = nullptr;
  this->m_pSpawnsPanel = v10;
  vgui::Panel::SetZPos(this: v10, z: 9);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10028010
// Name: public: virtual void CMapLayoutPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapLayoutPanel::PerformLayout(CMapLayoutPanel *this)
{
  CMapLayout *m_pMapLayout; // edx
  int v3; // ecx
  CMapLayout *v4; // edx

  vgui::Panel::PerformLayout(this);
  if ( g_pTileGenDialog != nullptr )
  {
    vgui::Panel::SetSize(
      this,
      wide: (int)(float)(g_pTileGenDialog->m_fTileSize * 120.0),
      tall: (int)(float)(g_pTileGenDialog->m_fTileSize * 120.0));
    vgui::Panel::SetSize(
      this: this->m_pPlayerStartImagePanel,
      wide: (int)g_pTileGenDialog->m_fTileSize,
      tall: (int)g_pTileGenDialog->m_fTileSize);
    if ( g_pTileGenDialog != nullptr )
      m_pMapLayout = g_pTileGenDialog->m_pMapLayout;
    else
      m_pMapLayout = nullptr;
    v3 = 120 - m_pMapLayout->m_iPlayerStartTileY;
    if ( g_pTileGenDialog != nullptr )
      v4 = g_pTileGenDialog->m_pMapLayout;
    else
      v4 = nullptr;
    vgui::Panel::SetPos(
      this: this->m_pPlayerStartImagePanel,
      x: (int)(float)((float)v4->m_iPlayerStartTileX * g_pTileGenDialog->m_fTileSize),
      y: (int)(float)((float)v3 * g_pTileGenDialog->m_fTileSize));
  }
}

//------------------------------------------------------------------------------
// Address: 0x100280D0
// Name: public: virtual void CMapLayoutPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapLayoutPanel::ApplySchemeSettings(CMapLayoutPanel *this, vgui::IScheme *pScheme)
{
  vgui::Panel::ApplySchemeSettings(this, pScheme);
  ((void (__thiscall *)(CMapLayoutPanel *, int))this->SetBgColor)(a1: this, a2: -16777216);
  this->SetPaintBackgroundEnabled(this, a2: true);
  this->SetPaintBackgroundType(this, a2: 0);
  CMissionChooserTGAImagePanel::SetTGA(
    this: this->m_pPlayerStartImagePanel,
    filename: "tilegen/roomtemplates/playerstart.tga",
    pPathID: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10028130
// Name: public: virtual void CMapLayoutPanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CMapLayoutPanel::Paint(CMapLayoutPanel *this@<ecx>, int a2@<ebx>, int a3@<edi>, int a4@<esi>)
{
  void (__thiscall *DrawSetColor)(vgui::ISurface *, Color); // edx
  int v5; // eax
  int v6; // edi
  vgui::ISurface *v7; // ebx
  vgui::ISurface_vtbl *v8; // esi
  int Tall; // eax
  int v10; // eax
  int v11; // ebx
  vgui::ISurface *v12; // edi
  vgui::ISurface_vtbl *v13; // esi
  int Wide; // eax
  void (__thiscall *v15)(vgui::ISurface *, Color); // eax
  int v16; // eax
  int v17; // edi
  vgui::ISurface *v18; // ebx
  vgui::ISurface_vtbl *v19; // esi
  int v20; // eax
  int v21; // eax
  int v22; // ebx
  vgui::ISurface *v23; // edi
  vgui::ISurface_vtbl *v24; // esi
  int v25; // eax
  void (__thiscall *v26)(vgui::ISurface *, Color); // eax
  int v27; // edx
  int v28; // edi
  int v29; // [esp-Ch] [ebp-24h]
  int sy; // [esp+0h] [ebp-18h] BYREF
  int sx; // [esp+4h] [ebp-14h] BYREF
  int my; // [esp+8h] [ebp-10h] BYREF
  int iTileSize; // [esp+Ch] [ebp-Ch]
  int mx; // [esp+10h] [ebp-8h] BYREF
  vgui::Panel *v37; // [esp+14h] [ebp-4h]

  v37 = this;
  if ( g_pTileGenDialog != nullptr )
  {
    DrawSetColor = g_pVGuiSurface->DrawSetColor;
    iTileSize = (int)g_pTileGenDialog->m_fTileSize;
    mx = -14671840;
    ((void (__stdcall *)(int, int))DrawSetColor)(a1: -14671840, a2: a3);
    v5 = 0;
    my = 0;
    v6 = 0;
    do
    {
      if ( (v5 & 3) != 0 )
      {
        v7 = g_pVGuiSurface;
        v8 = g_pVGuiSurface->__vftable;
        Tall = vgui::Panel::GetTall(this: v37);
        v8->DrawLine(this: v7, a2: v6, a3: 0, a4: v6, a5: Tall);
        v5 = my;
      }
      v6 += iTileSize;
      my = ++v5;
    }
    while ( v5 < 120 );
    v10 = 0;
    my = 0;
    v11 = 0;
    do
    {
      if ( (v10 & 3) != 0 )
      {
        v12 = g_pVGuiSurface;
        v13 = g_pVGuiSurface->__vftable;
        Wide = vgui::Panel::GetWide(this: v37);
        v13->DrawLine(this: v12, a2: 0, a3: v11, a4: Wide, a5: v11);
        v10 = my;
      }
      v11 += iTileSize;
      my = ++v10;
    }
    while ( v10 < 120 );
    v15 = g_pVGuiSurface->DrawSetColor;
    mx = -12566464;
    ((void (__thiscall *)(vgui::ISurface *, int))v15)(a1: g_pVGuiSurface, a2: -12566464);
    v16 = 0;
    my = 0;
    v17 = 0;
    do
    {
      if ( (v16 & 3) == 0 )
      {
        v18 = g_pVGuiSurface;
        v19 = g_pVGuiSurface->__vftable;
        v20 = vgui::Panel::GetTall(this: v37);
        v19->DrawLine(this: v18, a2: v17, a3: 0, a4: v17, a5: v20);
        v16 = my;
      }
      v17 += iTileSize;
      my = ++v16;
    }
    while ( v16 < 120 );
    v21 = 0;
    my = 0;
    v22 = 0;
    do
    {
      if ( (v21 & 3) == 0 )
      {
        v23 = g_pVGuiSurface;
        v24 = g_pVGuiSurface->__vftable;
        v25 = vgui::Panel::GetWide(this: v37);
        v24->DrawLine(this: v23, a2: 0, a3: v22, a4: v25, a5: v22);
        v21 = my;
      }
      v22 += iTileSize;
      my = ++v21;
    }
    while ( v21 < 120 );
    if ( CTileGenDialog::GetRubberBandStart(this: g_pTileGenDialog, &sx, &sy) )
    {
      ((void (__thiscall *)(vgui::IInput *, int *, int *, int, int, int))g_pVGuiInput->GetCursorPos)(
        a1: g_pVGuiInput,
        a2: &mx,
        a3: &my,
        a4: v29,
        a5: a4,
        a6: a2);
      vgui::Panel::ScreenToLocal(this: v37, x: &mx, y: &my);
      v26 = g_pVGuiSurface->DrawSetColor;
      iTileSize = -12517377;
      ((void (__thiscall *)(vgui::ISurface *, int))v26)(a1: g_pVGuiSurface, a2: -12517377);
      v27 = sx;
      if ( sx > mx )
      {
        v27 = mx;
        mx = sx;
        sx = v27;
      }
      if ( sy > my )
      {
        v28 = my;
        my = sy;
        sy = v28;
      }
      ((void (__thiscall *)(vgui::ISurface *, int))g_pVGuiSurface->DrawOutlinedRect)(a1: g_pVGuiSurface, a2: v27);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10028300
// Name: public: void CMapLayoutPanel::AddRoom(class CRoomTemplate const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapLayoutPanel::AddRoom(CMapLayoutPanel *this, const CRoomTemplate *pTemplate, int iTileX, int iTileY)
{
  CRoom *v5; // eax
  CMapLayout *m_pMapLayout; // edx
  CRoom *v7; // esi
  CPlacedRoomTemplatePanel *v8; // eax

  if ( g_pTileGenDialog != nullptr )
  {
    v5 = (CRoom *)operator new(nSize: 0x24u);
    if ( v5 != nullptr )
    {
      if ( g_pTileGenDialog != nullptr )
        m_pMapLayout = g_pTileGenDialog->m_pMapLayout;
      else
        m_pMapLayout = nullptr;
      v7 = CRoom::CRoom(
             this: v5,
             pMapLayout: m_pMapLayout,
             pRoomTemplate: g_pTileGenDialog->m_pCursorTemplate,
             TileX: iTileX,
             TileY: iTileY);
    }
    else
    {
      v7 = nullptr;
    }
    if ( v7->m_pPlacedRoomPanel == nullptr )
    {
      v8 = (CPlacedRoomTemplatePanel *)operator new(nSize: 0x1A8u);
      if ( v8 != nullptr )
        v7->m_pPlacedRoomPanel = CPlacedRoomTemplatePanel::CPlacedRoomTemplatePanel(
                                   this: v8,
                                   pRoom: v7,
                                   parent: this,
                                   name: "PlacedRoomPanel");
      else
        v7->m_pPlacedRoomPanel = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10028390
// Name: public: virtual void CMapLayoutPanel::OnMouseReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapLayoutPanel::OnMouseReleased(CMapLayoutPanel *this, int code)
{
  ButtonCode_t v3; // edi
  int v4; // esi
  const CRoomTemplate *m_pCursorTemplate; // eax
  CMapLayout *MapLayout; // eax
  const CRoomTemplate *v7; // [esp-14h] [ebp-20h]
  ButtonCode_t v8; // [esp-10h] [ebp-1Ch]
  int v9; // [esp-Ch] [ebp-18h]
  int mx; // [esp+8h] [ebp-4h] BYREF

  if ( g_pTileGenDialog != nullptr )
  {
    if ( g_pTileGenDialog->m_pCursorTemplate != nullptr )
    {
      if ( code == 107 )
      {
        code = 0;
        mx = 0;
        CMapLayoutPanel::GetCursorTile(this, tilex: &code, tiley: &mx);
        v3 = code;
        if ( code >= 0 )
        {
          v4 = mx;
          if ( mx >= 0 && code < 120 && mx < 120 )
          {
            m_pCursorTemplate = g_pTileGenDialog->m_pCursorTemplate;
            if ( code + m_pCursorTemplate->m_nTilesX <= 120 && mx + m_pCursorTemplate->m_nTilesY <= 120 )
            {
              v9 = mx;
              v8 = code;
              v7 = g_pTileGenDialog->m_pCursorTemplate;
              MapLayout = CMapLayoutPanel::GetMapLayout(this);
              if ( CMapLayout::TemplateFits(this: MapLayout, pTemplate: v7, x: v8, y: v9, bAllowNoExits: true) )
              {
                CMapLayoutPanel::AddRoom(this, pTemplate: g_pTileGenDialog->m_pCursorTemplate, iTileX: v3, iTileY: v4);
                _Msg(a1: "Manually added room %s at %d,%d\n", g_pTileGenDialog->m_pCursorTemplate->m_FullName, v3, v4);
              }
              else
              {
                _Msg(a1: "  Template doesn't fit there!\n");
              }
            }
          }
        }
      }
      else if ( code == 108 )
      {
        CTileGenDialog::SetCursorRoomTemplate(this: g_pTileGenDialog, pRoomTemplate: nullptr);
      }
    }
    else
    {
      g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &mx, a3: &code);
      vgui::Panel::ScreenToLocal(this, x: &mx, y: &code);
      CTileGenDialog::EndRubberBandSelection(this: g_pTileGenDialog, mx, my: code);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100284E0
// Name: public: void CMapLayoutPanel::CreateAllUIPanels(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapLayoutPanel::CreateAllUIPanels(CMapLayoutPanel *this)
{
  int i; // ebx
  CRoom *v3; // esi
  CPlacedRoomTemplatePanel *v4; // eax
  CPlacedRoomTemplatePanel *v5; // eax

  if ( g_pTileGenDialog != nullptr && g_pTileGenDialog->m_pMapLayout != nullptr )
  {
    for ( i = 0; i < CMapLayoutPanel::GetMapLayout(this)->m_PlacedRooms.m_Size; ++i )
    {
      v3 = CMapLayoutPanel::GetMapLayout(this)->m_PlacedRooms.m_Memory.m_pMemory[i];
      if ( v3->m_pPlacedRoomPanel == nullptr )
      {
        v4 = (CPlacedRoomTemplatePanel *)operator new(nSize: 0x1A8u);
        if ( v4 != nullptr )
          v5 = CPlacedRoomTemplatePanel::CPlacedRoomTemplatePanel(
                 this: v4,
                 pRoom: v3,
                 parent: this,
                 name: "PlacedRoomPanel");
        else
          v5 = nullptr;
        v3->m_pPlacedRoomPanel = v5;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FD740
// Name: _dynamic_initializer_for__panel_test_title_safe__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__panel_test_title_safe__()
{
  ConVar::ConVar(
    this: &panel_test_title_safe,
    pName: "panel_test_title_safe",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Test vgui panel positioning with title safe indentation");
  return atexit(func: dynamic_atexit_destructor_for__panel_test_title_safe__);
}

//------------------------------------------------------------------------------
// Address: 0x100FE100
// Name: _dynamic_atexit_destructor_for__panel_test_title_safe__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__panel_test_title_safe__()
{
  ConVar::~ConVar(this: &panel_test_title_safe);
}
