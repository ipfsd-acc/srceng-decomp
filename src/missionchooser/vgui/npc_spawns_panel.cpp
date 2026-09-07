// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: missionchooser/vgui/npc_spawns_panel.cpp
// Functions: 9
// ============================================================

#include "missionchooser\vgui\npc_spawns_panel.h"

//------------------------------------------------------------------------------
// Address: 0x10028AD0
// Name: public: void Vector2D::Init(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Vector2D::Init(Vector2D *this, float ix, float iy)
{
  this->x = ix;
  this->y = iy;
}

//------------------------------------------------------------------------------
// Address: 0x10028AF0
// Name: public: static char const __near * CNPC_Spawns_Panel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CNPC_Spawns_Panel::GetPanelClassName()
{
  return "CNPC_Spawns_Panel";
}

//------------------------------------------------------------------------------
// Address: 0x10028B00
// Name: public: virtual void CNPC_Spawns_Panel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNPC_Spawns_Panel::ApplySchemeSettings(CNPC_Spawns_Panel *this, vgui::IScheme *pScheme)
{
  vgui::Panel::ApplySchemeSettings(this, pScheme);
  this->m_hTextFont = pScheme->GetFont(this: pScheme, a2: "DefaultVerySmall", a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x10028B30
// Name: public: virtual struct vgui::PanelMessageMap __near * CNPC_Spawns_Panel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CNPC_Spawns_Panel::GetMessageMap(CNPC_Spawns_Panel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CNPC_Spawns_Panel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CNPC_Spawns_Panel::GetMessageMap'::`2'::s_pMap;
  `CNPC_Spawns_Panel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CNPC_Spawns_Panel");
  `CNPC_Spawns_Panel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10028B60
// Name: public: virtual struct PanelAnimationMap __near * CNPC_Spawns_Panel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CNPC_Spawns_Panel::GetAnimMap(CNPC_Spawns_Panel *this)
{
  return FindOrAddPanelAnimationMap(className: "CNPC_Spawns_Panel");
}

//------------------------------------------------------------------------------
// Address: 0x10028B70
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CNPC_Spawns_Panel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CNPC_Spawns_Panel::GetKBMap(CNPC_Spawns_Panel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CNPC_Spawns_Panel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CNPC_Spawns_Panel::GetKBMap'::`2'::s_pMap;
  `CNPC_Spawns_Panel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CNPC_Spawns_Panel");
  `CNPC_Spawns_Panel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10028BA0
// Name: public: CNPC_Spawns_Panel::CNPC_Spawns_Panel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CNPC_Spawns_Panel *__thiscall CNPC_Spawns_Panel::CNPC_Spawns_Panel(
        CNPC_Spawns_Panel *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (CNPC_Spawns_Panel_vtbl *)&CNPC_Spawns_Panel::`vftable';
  if ( `CNPC_Spawns_Panel::ChainToMap'::`2'::chained == 0 )
  {
    `CNPC_Spawns_Panel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CNPC_Spawns_Panel");
    v4->pfnClassName = CNPC_Spawns_Panel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Panel");
  }
  if ( `CNPC_Spawns_Panel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CNPC_Spawns_Panel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CNPC_Spawns_Panel");
    v5->pfnClassName = CNPC_Spawns_Panel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Panel");
  }
  if ( `CNPC_Spawns_Panel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CNPC_Spawns_Panel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CNPC_Spawns_Panel");
    v6->pfnClassName = CNPC_Spawns_Panel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Panel");
  }
  this->m_nWhiteTextureId = -1;
  vgui::Panel::SetMouseInputEnabled(this, state: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10028CA0
// Name: public: virtual void CNPC_Spawns_Panel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNPC_Spawns_Panel::PerformLayout(CNPC_Spawns_Panel *this)
{
  vgui::Panel *v2; // edi
  int Wide; // eax
  int Tall; // [esp-4h] [ebp-Ch]

  vgui::Panel::PerformLayout(this);
  v2 = this->GetParent(this);
  Tall = vgui::Panel::GetTall(this: v2);
  Wide = vgui::Panel::GetWide(this: v2);
  vgui::Panel::SetBounds(this, x: 0, y: 0, wide: Wide, tall: Tall);
}

//------------------------------------------------------------------------------
// Address: 0x10028CE0
// Name: public: virtual void CNPC_Spawns_Panel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CNPC_Spawns_Panel::Paint(CNPC_Spawns_Panel *this@<ecx>, int a2@<esi>)
{
  CNPC_Spawns_Panel *v2; // edi
  int m_fTileSize; // eax
  CMapLayout *m_pMapLayout; // esi
  bool v5; // cc
  CASW_Encounter *v6; // esi
  const Vector *(__thiscall *GetEncounterPosition)(struct CASW_Encounter *); // eax
  int v8; // eax
  float v9; // ecx
  void (__thiscall *DrawSetColor)(vgui::ISurface *, Color); // edx
  int v11; // eax
  double v12; // st7
  int v13; // edi
  double v14; // xmm0_8
  double v15; // xmm0_8
  CNPC_Spawns_Panel *v16; // edi
  unsigned int m_hTextFont; // eax
  int v18; // eax
  unsigned int v19; // edx
  void (__thiscall *DrawSetTextColor)(vgui::ISurface *, Color); // edx
  int (__thiscall *GetNumSpawnDefs)(struct CASW_Encounter *); // eax
  IASWSpawnDefinition *v22; // edi
  int (__thiscall *GetEntryCount)(IASWSpawnDefinition *); // edx
  int (__thiscall ***v24)(_DWORD, wchar_t *, int); // esi
  int (__thiscall *v25)(_DWORD, wchar_t *, int); // edx
  int v26; // eax
  int v27; // esi
  int (__thiscall *v28)(IASWSpawnDefinition *); // edx
  int v29; // esi
  int (__thiscall *v30)(struct CASW_Encounter *); // edx
  int v31; // edi
  CRoom *v32; // ecx
  void (__thiscall *v33)(vgui::ISurface *, Color); // edx
  int v34; // eax
  CRoom *v35; // ecx
  int m_nWhiteTextureId; // eax
  float v37; // xmm0_4
  long double v38; // [esp-4h] [ebp-91Ch]
  long double v39; // [esp-4h] [ebp-91Ch]
  long double v40; // [esp-4h] [ebp-91Ch]
  long double v41; // [esp-4h] [ebp-91Ch]
  wchar_t szAlienList[1024]; // [esp+4h] [ebp-914h] BYREF
  wchar_t szconverted[64]; // [esp+804h] [ebp-114h] BYREF
  FontVertex_t v[3]; // [esp+884h] [ebp-94h] BYREF
  int maxAliens; // [esp+8B4h] [ebp-64h] BYREF
  int line_height; // [esp+8B8h] [ebp-60h]
  CASW_Encounter *pEncounter; // [esp+8BCh] [ebp-5Ch]
  float v48; // [esp+8C0h] [ebp-58h]
  int minAliens; // [esp+8C4h] [ebp-54h] BYREF
  float v50; // [esp+8C8h] [ebp-50h]
  vgui::ILocalize_vtbl *v51; // [esp+8CCh] [ebp-4Ch]
  int iTileSize; // [esp+8D0h] [ebp-48h]
  float v53; // [esp+8D4h] [ebp-44h]
  int ypos; // [esp+8D8h] [ebp-40h]
  Vector vecMins; // [esp+8DCh] [ebp-3Ch] BYREF
  int e; // [esp+8E8h] [ebp-30h]
  int d; // [esp+8ECh] [ebp-2Ch]
  CMapLayout *pLayout; // [esp+8F0h] [ebp-28h]
  CNPC_Spawns_Panel *v59; // [esp+8F4h] [ebp-24h]
  float flPixelsPerWorldCoord; // [esp+8F8h] [ebp-20h]
  int i; // [esp+8FCh] [ebp-1Ch]
  int v62; // [esp+900h] [ebp-18h]
  Vector vecMaxs; // [esp+904h] [ebp-14h] BYREF
  int v64; // [esp+910h] [ebp-8h]
  float v65; // [esp+914h] [ebp-4h]

  v2 = this;
  v59 = this;
  if ( g_pTileGenDialog != nullptr
    && asw_encounter_display.m_pParent != nullptr
    && asw_encounter_display.m_pParent->m_Value.m_nValue > 0 )
  {
    m_fTileSize = (int)g_pTileGenDialog->m_fTileSize;
    LODWORD(v38) = a2;
    m_pMapLayout = g_pTileGenDialog->m_pMapLayout;
    iTileSize = m_fTileSize;
    pLayout = m_pMapLayout;
    if ( m_pMapLayout != nullptr )
    {
      v5 = m_pMapLayout->m_Encounters.m_Size <= 0;
      flPixelsPerWorldCoord = (float)m_fTileSize * 0.00390625;
      i = 0;
      if ( !v5 )
      {
        v50 = (float)(120 * m_fTileSize) * 0.5;
        v62 = 1075904288;
        do
        {
          v6 = m_pMapLayout->m_Encounters.m_Memory.m_pMemory[i];
          GetEncounterPosition = v6->GetEncounterPosition;
          pEncounter = v6;
          v8 = ((int (__thiscall *)(CASW_Encounter *, _DWORD))GetEncounterPosition)(a1: v6, a2: LODWORD(v38));
          v9 = *(float *)(v8 + 8);
          *(_QWORD *)&vecMaxs.x = *(_QWORD *)v8;
          vecMaxs.z = v9;
          DrawSetColor = g_pVGuiSurface->DrawSetColor;
          vecMaxs.x = v50 + (float)(vecMaxs.x * flPixelsPerWorldCoord);
          vecMaxs.y = v50 + COERCE_FLOAT(COERCE_UNSIGNED_INT(vecMaxs.y * flPixelsPerWorldCoord) ^ _mask__NegFloat_);
          ((void (__thiscall *)(vgui::ISurface *, int))DrawSetColor)(a1: g_pVGuiSurface, a2: v62);
          if ( v2->m_nWhiteTextureId < 0 )
          {
            v11 = g_pVGuiSurface->CreateNewTextureID(this: g_pVGuiSurface, a2: false);
            v2->m_nWhiteTextureId = v11;
            g_pVGuiSurface->DrawSetTextureFile(this: g_pVGuiSurface, a2: v11, a3: "vgui/white", a4: 1, a5: false);
          }
          LODWORD(v38) = v2->m_nWhiteTextureId;
          ((void (__thiscall *)(vgui::ISurface *))g_pVGuiSurface->DrawSetTexture)(a1: g_pVGuiSurface);
          v12 = ((double (__thiscall *)(CASW_Encounter *))v6->GetEncounterRadius)(a1: v6);
          v13 = 0;
          v65 = (float)(int)(v12 * flPixelsPerWorldCoord);
          do
          {
            v[0].m_Position.x = vecMaxs.x;
            v[0].m_Position.y = vecMaxs.y;
            v53 = (float)v13 * 0.31415927;
            __libm_sse2_cos(x: v38);
            v[1].m_Position.x = (float)((float)((float)v13 * 0.31415927) * v65) + vecMaxs.x;
            v14 = v53;
            __libm_sse2_sin(x: v39);
            *(float *)&v14 = v14;
            v[1].m_Position.y = (float)(*(float *)&v14 * v65) + vecMaxs.y;
            v48 = (float)++v13 * 0.31415927;
            __libm_sse2_cos(x: v40);
            v[2].m_Position.x = (float)((float)((float)v13 * 0.31415927) * v65) + vecMaxs.x;
            v15 = v48;
            __libm_sse2_sin(x: v41);
            *(float *)&v15 = v15;
            v[2].m_Position.y = (float)(*(float *)&v15 * v65) + vecMaxs.y;
            v[0].m_TexCoord.x = 0.0;
            v[0].m_TexCoord.y = 0.0;
            v[1].m_TexCoord.x = 1.0;
            v[1].m_TexCoord.y = 0.0;
            v[2].m_TexCoord.x = 1.0;
            v[2].m_TexCoord.y = 1.0;
            g_pVGuiSurface->DrawTexturedPolygon(this: g_pVGuiSurface, a2: 3, a3: v, a4: true);
          }
          while ( v13 < 20 );
          if ( asw_encounter_display.m_pParent != nullptr && asw_encounter_display.m_pParent->m_Value.m_nValue >= 2 )
          {
            v16 = v59;
            m_hTextFont = v59->m_hTextFont;
            ypos = (int)vecMaxs.y;
            v18 = g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: m_hTextFont);
            v19 = v16->m_hTextFont;
            line_height = v18;
            g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: v19);
            DrawSetTextColor = g_pVGuiSurface->DrawSetTextColor;
            v64 = -1;
            ((void (__thiscall *)(vgui::ISurface *, int))DrawSetTextColor)(a1: g_pVGuiSurface, a2: -1);
            _snwprintf(string: szAlienList, count: 0x400u, format: &word_1010DB00);
            GetNumSpawnDefs = v6->GetNumSpawnDefs;
            d = 0;
            if ( GetNumSpawnDefs(this: v6) > 0 )
            {
              do
              {
                v22 = v6->GetSpawnDef(this: v6, a2: d);
                GetEntryCount = v22->GetEntryCount;
                e = 0;
                if ( GetEntryCount(this: v22) > 0 )
                {
                  do
                  {
                    v24 = (int (__thiscall ***)(_DWORD, wchar_t *, int))((int (__thiscall *)(IASWSpawnDefinition *, int, _DWORD))v22->GetEntry)(
                                                                          a1: v22,
                                                                          a2: e,
                                                                          a3: LODWORD(v38));
                    (*v24)[1](a1: v24, a2: (wchar_t *)&minAliens, a3: (int)&maxAliens);
                    v25 = **v24;
                    v51 = g_pVGuiLocalize->__vftable;
                    v26 = v25(a1: v24, a2: szconverted, a3: 128);
                    ((void (__thiscall *)(vgui::ILocalize *, int))v51->ConvertANSIToUnicode)(
                      a1: g_pVGuiLocalize,
                      a2: v26);
                    _snwprintf(
                      string: szAlienList,
                      count: 0x400u,
                      format: L"%s (%d/%d)",
                      szconverted,
                      minAliens,
                      maxAliens);
                    v27 = ypos;
                    g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: (int)vecMaxs.x, a3: ypos);
                    LODWORD(v38) = 0;
                    ((void (__thiscall *)(vgui::ISurface *, wchar_t *, unsigned int))g_pVGuiSurface->DrawPrintText)(
                      a1: g_pVGuiSurface,
                      a2: szAlienList,
                      a3: wcslen(szAlienList));
                    v28 = v22->GetEntryCount;
                    ypos = line_height + v27;
                    v29 = ++e;
                  }
                  while ( v29 < v28(this: v22) );
                  v6 = pEncounter;
                }
                v30 = v6->GetNumSpawnDefs;
                v31 = ++d;
              }
              while ( v31 < v30(this: v6) );
            }
          }
          v2 = v59;
          ++i;
          m_pMapLayout = pLayout;
        }
        while ( i < pLayout->m_Encounters.m_Size );
      }
      v5 = m_pMapLayout->m_PlacedRooms.m_Size <= 0;
      v65 = 0.0;
      if ( !v5 )
      {
        do
        {
          v32 = m_pMapLayout->m_PlacedRooms.m_Memory.m_pMemory[LODWORD(v65)];
          if ( v32->HasAlienEncounter(this: v32) )
          {
            v33 = g_pVGuiSurface->DrawSetColor;
            v64 = -2147483393;
            ((void (__thiscall *)(vgui::ISurface *, int, _DWORD))v33)(
              a1: g_pVGuiSurface,
              a2: -2147483393,
              a3: LODWORD(v38));
            if ( v2->m_nWhiteTextureId < 0 )
            {
              v34 = g_pVGuiSurface->CreateNewTextureID(this: g_pVGuiSurface, a2: false);
              v2->m_nWhiteTextureId = v34;
              g_pVGuiSurface->DrawSetTextureFile(this: g_pVGuiSurface, a2: v34, a3: "vgui/white", a4: 1, a5: false);
            }
            v35 = m_pMapLayout->m_PlacedRooms.m_Memory.m_pMemory[LODWORD(v65)];
            LODWORD(v38) = &vecMaxs;
            ((void (__thiscall *)(CRoom *, Vector *))v35->GetWorldBounds)(a1: v35, a2: &vecMins);
            m_nWhiteTextureId = v2->m_nWhiteTextureId;
            v37 = (float)(120 * iTileSize) * 0.5;
            vecMins.y = v37 + COERCE_FLOAT(COERCE_UNSIGNED_INT(vecMins.y * flPixelsPerWorldCoord) ^ _mask__NegFloat_);
            vecMins.z = v37 + (float)(vecMins.z * flPixelsPerWorldCoord);
            vecMaxs.x = v37 + (float)(vecMaxs.x * flPixelsPerWorldCoord);
            vecMins.x = v37 + (float)(vecMins.x * flPixelsPerWorldCoord);
            vecMaxs.y = v37 + COERCE_FLOAT(COERCE_UNSIGNED_INT(vecMaxs.y * flPixelsPerWorldCoord) ^ _mask__NegFloat_);
            vecMaxs.z = v37 + (float)(vecMaxs.z * flPixelsPerWorldCoord);
            g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: m_nWhiteTextureId);
            g_pVGuiSurface->DrawTexturedRect(
              this: g_pVGuiSurface,
              a2: (int)vecMins.x,
              a3: (int)vecMaxs.y,
              a4: (int)vecMaxs.x,
              a5: (int)vecMins.y);
          }
          ++LODWORD(v65);
        }
        while ( SLODWORD(v65) < m_pMapLayout->m_PlacedRooms.m_Size );
      }
    }
  }
}
