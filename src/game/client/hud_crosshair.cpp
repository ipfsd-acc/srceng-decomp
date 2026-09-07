// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/hud_crosshair.cpp
// Functions: 22
// ============================================================

#include "game\client\hud_crosshair.h"

//------------------------------------------------------------------------------
// Address: 0x101012D0
// Name: public: static char const __near * CHudCrosshair::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CHudCrosshair::GetPanelClassName()
{
  return "CHudCrosshair";
}

//------------------------------------------------------------------------------
// Address: 0x101012E0
// Name: private: static void __near * CHudCrosshair::GetVar_m_bHideCrosshair(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CHudCrosshair::GetVar_m_bHideCrosshair(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return (int)&panel[1].m_pTooltips + 1;
  else
    return 441;
}

//------------------------------------------------------------------------------
// Address: 0x10101300
// Name: protected: virtual void CHudCrosshair::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudCrosshair::ApplySchemeSettings(CHudCrosshair *this, vgui::IScheme *scheme)
{
  CHudIcons *v3; // eax
  CHudTexture *Icon; // eax
  CHudCrosshair_vtbl *v5; // edx
  int v6; // eax
  int v7; // [esp-4h] [ebp-8h]

  vgui::Panel::ApplySchemeSettings((vgui::Panel *)this, pScheme: (int)scheme);
  v3 = HudIcons();
  Icon = CHudIcons::GetIcon(this: v3, szIcon: "crosshair_default");
  v5 = this->CHudElement::CGameEventListener::IGameEventListener2::__vftable;
  *(_DWORD *)&this->m_m_nPaintBackgroundType_register = Icon;
  ((void (__thiscall *)(CHudCrosshair *, _DWORD))v5[3].OnSplitScreenStateChanged)(a1: this, a2: 0);
  v7 = ScreenHeight();
  v6 = ScreenWidth();
  vgui::Panel::SetSize((vgui::Panel *)this, wide: v6, tall: v7);
}

//------------------------------------------------------------------------------
// Address: 0x10101350
// Name: public: void CHudCrosshair::SetCrosshair(class CHudTexture __near *,class Color const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudCrosshair::SetCrosshair(CHudCrosshair *this, CHudTexture *texture, const Color *clr)
{
  this->m_pCrosshair = texture;
  this->m_clrCrosshair = *clr;
}

//------------------------------------------------------------------------------
// Address: 0x10101370
// Name: public: void CHudCrosshair::SetCrosshairAngle(class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudCrosshair::SetCrosshairAngle(CHudCrosshair *this, const QAngle *angle)
{
  this->m_vecCrossHairOffsetAngle = *angle;
}

//------------------------------------------------------------------------------
// Address: 0x101013A0
// Name: public: void CHudCrosshair::ResetCrosshair(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudCrosshair::ResetCrosshair(CHudCrosshair *this)
{
  this->m_pCrosshair = this->m_pDefaultCrosshair;
  this->m_clrCrosshair = (Color)-1;
}

//------------------------------------------------------------------------------
// Address: 0x101013D0
// Name: protected: virtual void CHudCrosshair::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CHudCrosshair::Paint(CHudCrosshair *this@<ecx>, int a2@<edi>)
{
  int v3; // eax
  bool (__thiscall *IsStereoActiveThisFrame)(IMaterialSystem *); // edx
  int *p_m_nBgTextureId2; // edi
  const Vector *v6; // eax
  double z; // st7
  vgui::ToggleButton *v8; // ecx
  C_BasePlayer *v9; // eax
  Vector *(__thiscall *Weapon_ShootPosition)(C_BasePlayer *, Vector *); // eax
  float *v11; // eax
  float v12; // xmm0_4
  Vector *(__thiscall *v13)(C_BasePlayer *, Vector *); // eax
  const Vector *v14; // eax
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  float v20; // xmm0_4
  C_BasePlayer *LocalPlayer; // ecx
  C_BasePlayer *v22; // eax
  float m_flAlpha; // edx
  float v24; // xmm0_4
  int v25; // ecx
  C_BasePlayer_vtbl *v26; // edx
  float v27; // xmm0_4
  C_BasePlayer *v28; // ecx
  C_BaseCombatWeapon *(__thiscall *GetActiveWeapon)(C_BaseCombatCharacter *); // eax
  int v30; // eax
  float v31; // eax
  C_BasePlayer *v32; // [esp+0h] [ebp-D0h]
  CGameTrace tr; // [esp+10h] [ebp-C0h] BYREF
  Vector forward; // [esp+64h] [ebp-6Ch] BYREF
  Vector vecAbsEnd; // [esp+70h] [ebp-60h] BYREF
  Vector aimVector; // [esp+7Ch] [ebp-54h] BYREF
  float flW; // [esp+88h] [ebp-48h]
  Vector screen; // [esp+8Ch] [ebp-44h] BYREF
  Vector point; // [esp+98h] [ebp-38h] BYREF
  float flWeaponScale; // [esp+A4h] [ebp-2Ch] BYREF
  float y; // [esp+A8h] [ebp-28h]
  Vector vecEnd; // [esp+ACh] [ebp-24h] BYREF
  float x; // [esp+B8h] [ebp-18h]
  Vector v45; // [esp+BCh] [ebp-14h] BYREF
  C_BasePlayer *pPlayer; // [esp+C8h] [ebp-8h]
  bool bStereoActive; // [esp+CFh] [ebp-1h]
  IHandleEntity savedregs; // [esp+D0h] [ebp+0h] BYREF

  if ( LODWORD(this->m_flAlpha) != 0 && IsCurrentViewAccessAllowed() )
  {
    x = (float)(ScreenWidth() / 2);
    v3 = ScreenHeight();
    IsStereoActiveThisFrame = materials->IsStereoActiveThisFrame;
    y = (float)(v3 / 2);
    bStereoActive = IsStereoActiveThisFrame(this: materials);
    *(QAngle *)&this->m_nBgTextureId2 = *CurrentViewAngles();
    p_m_nBgTextureId2 = &this->m_nBgTextureId2;
    v6 = CurrentViewOrigin();
    *(float *)&this->m_m_nBgTextureId4_register = v6->x;
    *(float *)&this->m_nBgTextureId4 = v6->y;
    z = v6->z;
    screen.x = 0.0;
    *(float *)&this->m_roundedCorners = z;
    screen.y = 0.0;
    screen.z = 0.0;
    if ( IsPresetCurrentCostDebuggingEnabled(this: v8) )
    {
      *(float *)&v9 = COERCE_FLOAT(C_BasePlayer::GetLocalPlayer(nSlot: -1));
      pPlayer = v9;
      if ( *(float *)&v9 == 0.0 )
        return;
      ((void (__thiscall *)(C_BasePlayer *, Vector *, int, int))v9->GetAutoaimVector)(
        a1: v9,
        a2: &aimVector,
        a3: 1035108022,
        a4: a2);
      Weapon_ShootPosition = pPlayer->Weapon_ShootPosition;
      v45.x = aimVector.x * 56755.84;
      v45.y = aimVector.y * 56755.84;
      v45.z = aimVector.z * 56755.84;
      v11 = (float *)Weapon_ShootPosition(this: pPlayer, result: &vecAbsEnd);
      point.x = *v11 + v45.x;
      v32 = pPlayer;
      point.y = v11[1] + v45.y;
      v12 = v11[2] + v45.z;
      v13 = pPlayer->Weapon_ShootPosition;
      point.z = v12;
      v14 = (const Vector *)((int (__thiscall *)(C_BasePlayer *))v13)(a1: pPlayer);
      UTIL_TraceLine(
        a1: &savedregs,
        a2: (int)this,
        vecAbsStart: v14,
        &vecAbsEnd,
        mask: (unsigned int)&point,
        ignore: (const IHandleEntity *)0x46004003,
        collisionGroup: (int)v32,
        ptr: nullptr);
      v15 = *(float *)&this->m_nBgTextureId1 + *(float *)&this->m_m_nBgTextureId3_register;
      v16 = *(float *)&this->m_m_nBgTextureId2_register + *(float *)&this->m_nBgTextureId3;
      vecEnd.x = *(float *)p_m_nBgTextureId2 + *(float *)&this->m_m_nBgTextureId1_register;
      vecEnd.y = v15;
      vecEnd.z = v16;
      AngleVectors(angles: (const QAngle *)&vecEnd, &forward);
      ScreenTransform(point: &tr.endpos, &screen);
    }
    else
    {
      v17 = *(float *)&this->m_m_nBgTextureId1_register;
      if ( vec3_angle.x == v17
        && vec3_angle.y == *(float *)&this->m_nBgTextureId1
        && vec3_angle.z == *(float *)&this->m_m_nBgTextureId2_register )
      {
        AngleVectors(angles: (const QAngle *)&this->m_nBgTextureId2, forward: &v45);
      }
      else
      {
        v18 = *(float *)&this->m_m_nBgTextureId2_register + *(float *)&this->m_nBgTextureId3;
        v19 = v17 + *(float *)p_m_nBgTextureId2;
        v20 = *(float *)&this->m_nBgTextureId1 + *(float *)&this->m_m_nBgTextureId3_register;
        vecEnd.x = v19;
        vecEnd.y = v20;
        vecEnd.z = v18;
        AngleVectors(angles: (const QAngle *)&vecEnd, forward: &v45);
        point.x = v45.x + *(float *)&this->m_m_nBgTextureId4_register;
        point.y = *(float *)&this->m_nBgTextureId4 + v45.y;
        point.z = *(float *)&this->m_roundedCorners + v45.z;
        ScreenTransform(&point, &screen);
      }
      if ( bStereoActive )
      {
        LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
        if ( LocalPlayer != nullptr && (float)HIBYTE(this->m_nPaintBackgroundType) != 0.0 )
        {
          vecEnd.x = (float)(v45.x * 56755.84) + *(float *)&this->m_m_nBgTextureId4_register;
          vecEnd.y = *(float *)&this->m_nBgTextureId4 + (float)(v45.y * 56755.84);
          vecEnd.z = *(float *)&this->m_roundedCorners + (float)(v45.z * 56755.84);
          UTIL_TraceLine(
            a1: &savedregs,
            a2: (int)this,
            vecAbsStart: (const Vector *)&this->m_m_nBgTextureId4_register,
            vecAbsEnd: &vecEnd,
            mask: 0x46004003u,
            ignore: LocalPlayer,
            collisionGroup: 0,
            ptr: &tr);
        }
      }
    }
    x = (float)((float)((float)ScreenWidth() * (float)(screen.x * 0.5)) + 0.5) + x;
    y = (float)((float)((float)ScreenHeight() * (float)(screen.y * 0.5)) + 0.5) + y;
    v22 = C_BasePlayer::GetLocalPlayer(nSlot: -1);
    if ( v22 != nullptr )
    {
      m_flAlpha = this->m_flAlpha;
      flWeaponScale = 1.0;
      v24 = (float)(*(_DWORD *)(LODWORD(m_flAlpha) + 160) - *(_DWORD *)(LODWORD(m_flAlpha) + 156));
      v25 = *(_DWORD *)(LODWORD(m_flAlpha) + 168) - *(_DWORD *)(LODWORD(m_flAlpha) + 164);
      v26 = v22->C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
      flW = v24;
      v27 = (float)v25;
      v28 = v22;
      GetActiveWeapon = v26->GetActiveWeapon;
      *(float *)&pPlayer = v27;
      v30 = (int)GetActiveWeapon(this: v28);
      if ( v30 != 0 )
        (*(void (__thiscall **)(int, float *))(*(_DWORD *)v30 + 1436))(a1: v30, a2: &flWeaponScale);
      v31 = this->m_flAlpha;
      CHudTexture::DrawSelfCropped(
        this: (CHudTexture *)LODWORD(v31),
        x: (int)(float)((float)(x
                           - (float)((float)((float)(*(_DWORD *)(LODWORD(v31) + 160) - *(_DWORD *)(LODWORD(v31) + 156))
                                           * 0.5)
                                   * flWeaponScale))
                   + 0.5),
        y: (int)(float)((float)(y
                           - (float)((float)((float)(*(_DWORD *)(LODWORD(v31) + 168) - *(_DWORD *)(LODWORD(v31) + 164))
                                           * 0.5)
                                   * flWeaponScale))
                   + 0.5),
        cropx: 0,
        cropy: 0,
        cropw: (int)flW,
        croph: (int)*(float *)&pPlayer,
        finalWidth: (int)(float)(flW * flWeaponScale),
        finalHeight: (int)(float)(*(float *)&pPlayer * flWeaponScale),
        clr: (Color)this->m_nPaintBackgroundType,
        flApparentZ: 1.0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101018D0
// Name: public: static void CHudCrosshair::PanelAnimationVar_m_bHideCrosshair::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudCrosshair::PanelAnimationVar_m_bHideCrosshair::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudCrosshair::PanelAnimationVar_m_bHideCrosshair::InitVar'::`2'::bAdded )
  {
    `CHudCrosshair::PanelAnimationVar_m_bHideCrosshair::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudCrosshair");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "never_draw";
    src.m_pszVariable = "m_bHideCrosshair";
    src.m_pszType = "bool";
    src.m_pszDefaultValue = "false";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CHudCrosshair::GetVar_m_bHideCrosshair;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10101930
// Name: public: CHudCrosshair::CHudCrosshair(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CHudCrosshair *__thiscall CHudCrosshair::CHudCrosshair(CHudCrosshair *this, const char *pElementName)
{
  vgui::PanelMessageMap *v3; // ebx
  PanelAnimationMap *v4; // ebx
  vgui::PanelKeyBindingMap *v5; // ebx
  IClientMode *ClientMode; // eax
  vgui::Panel *v7; // eax

  CHudElement::CHudElement(this, pElementName);
  vgui::Panel::Panel(this: &this->vgui::Panel, parent: nullptr, panelName: "HudCrosshair");
  this->CHudElement::CGameEventListener::IGameEventListener2::__vftable = (CHudCrosshair_vtbl *)&CHudCrosshair::`vftable'{for `CHudElement'};
  this->vgui::Panel::vgui::IClientPanel::__vftable = (vgui::Panel_vtbl *)&CHudCrosshair::`vftable'{for `vgui::Panel'};
  if ( `CHudCrosshair::ChainToMap'::`2'::chained == 0 )
  {
    `CHudCrosshair::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CHudCrosshair");
    v3->pfnClassName = CHudCrosshair::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Panel");
  }
  if ( `CHudCrosshair::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CHudCrosshair::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CHudCrosshair");
    v4->pfnClassName = CHudCrosshair::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Panel");
  }
  if ( `CHudCrosshair::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CHudCrosshair::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CHudCrosshair");
    v5->pfnClassName = CHudCrosshair::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Panel");
  }
  this->m_clrCrosshair = 0;
  CHudCrosshair::PanelAnimationVar_m_bHideCrosshair::InitVar();
  ClientMode = GetClientMode();
  v7 = ClientMode->GetViewport(this: ClientMode);
  vgui::Panel::SetParent(this: &this->vgui::Panel, newParent: v7);
  this->m_pCrosshair = nullptr;
  this->m_clrCrosshair = 0;
  this->m_vecCrossHairOffsetAngle.x = 0.0;
  this->m_vecCrossHairOffsetAngle.y = 0.0;
  this->m_vecCrossHairOffsetAngle.z = 0.0;
  CTraceFilterSkipTwoEntities::SetPassEntity2(
    (CTraceFilterSkipTwoEntities *)this,
    pPassEntity2: (const IHandleEntity *)0x110);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10101A60
// Name: public: virtual struct vgui::PanelMessageMap __near * CHudCrosshair::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CHudCrosshair::GetMessageMap(CHudCrosshair *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CHudCrosshair::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CHudCrosshair::GetMessageMap'::`2'::s_pMap;
  `CHudCrosshair::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CHudCrosshair");
  `CHudCrosshair::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10101A90
// Name: public: virtual struct PanelAnimationMap __near * CHudCrosshair::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CHudCrosshair::GetAnimMap(CHudCrosshair *this)
{
  return FindOrAddPanelAnimationMap(className: "CHudCrosshair");
}

//------------------------------------------------------------------------------
// Address: 0x10101AA0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CHudCrosshair::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CHudCrosshair::GetKBMap(CHudCrosshair *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CHudCrosshair::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CHudCrosshair::GetKBMap'::`2'::s_pMap;
  `CHudCrosshair::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CHudCrosshair");
  `CHudCrosshair::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10101AD0
// Name: Create_CHudCrosshair
// Source: json
//------------------------------------------------------------------------------
CHudCrosshair *__cdecl Create_CHudCrosshair()
{
  unsigned __int8 *v0; // esi

  v0 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 444);
  memset(dst: v0, value: 0, count: 0x1BCu);
  if ( v0 != nullptr )
    return CHudCrosshair::CHudCrosshair(this: (CHudCrosshair *)v0, pElementName: "CHudCrosshair");
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10426F70
// Name: _dynamic_initializer_for__crosshair__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__crosshair__()
{
  ConVar::ConVar(this: &crosshair, pName: "crosshair", pDefaultValue: "1", flags: 32896);
  return atexit(func: dynamic_atexit_destructor_for__crosshair__);
}

//------------------------------------------------------------------------------
// Address: 0x10435D60
// Name: _dynamic_atexit_destructor_for__crosshair__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__crosshair__()
{
  ConVar::~ConVar(this: &crosshair);
}

//------------------------------------------------------------------------------
// Address: 0x10426FA0
// Name: _dynamic_initializer_for__cl_observercrosshair__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_observercrosshair__()
{
  ConVar::ConVar(this: &cl_observercrosshair, pName: "cl_observercrosshair", pDefaultValue: "1", flags: 32896);
  return atexit(func: dynamic_atexit_destructor_for__cl_observercrosshair__);
}

//------------------------------------------------------------------------------
// Address: 0x10426FD0
// Name: _dynamic_initializer_for__hud_showtargetpos__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__hud_showtargetpos__()
{
  ConVar::ConVar(
    this: &hud_showtargetpos,
    pName: "hud_showtargetpos",
    pDefaultValue: "0",
    flags: 32896,
    pHelpString: "0: center, 1: upper left, 2 upper right, 3: lower left, 4: lower right");
  return atexit(func: dynamic_atexit_destructor_for__hud_showtargetpos__);
}

//------------------------------------------------------------------------------
// Address: 0x10427000
// Name: _dynamic_initializer_for__hud_showtargetid__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__hud_showtargetid__()
{
  ConVar::ConVar(
    this: &hud_showtargetid,
    pName: "hud_showtargetid",
    pDefaultValue: "1",
    flags: 32896,
    pHelpString: "Enables display of target names");
  return atexit(func: dynamic_atexit_destructor_for__hud_showtargetid__);
}

//------------------------------------------------------------------------------
// Address: 0x10427030
// Name: _dynamic_initializer_for__g_SFHudReticle_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CHudElementHelper *dynamic_initializer_for__g_SFHudReticle_Helper__()
{
  return CHudElementHelper::CHudElementHelper(
           this: &g_SFHudReticle_Helper,
           pfnCreate: (CHudElement *(__cdecl *)())Create_SFHudReticle,
           depth: 50,
           flags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10435D70
// Name: _dynamic_atexit_destructor_for__cl_observercrosshair__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_observercrosshair__()
{
  ConVar::~ConVar(this: &cl_observercrosshair);
}

//------------------------------------------------------------------------------
// Address: 0x10435D80
// Name: _dynamic_atexit_destructor_for__hud_showtargetpos__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__hud_showtargetpos__()
{
  ConVar::~ConVar(this: &hud_showtargetpos);
}

//------------------------------------------------------------------------------
// Address: 0x10435D90
// Name: _dynamic_atexit_destructor_for__hud_showtargetid__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__hud_showtargetid__()
{
  ConVar::~ConVar(this: &hud_showtargetid);
}
