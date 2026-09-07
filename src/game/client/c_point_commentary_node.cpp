// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_point_commentary_node.cpp
// Functions: 73
// ============================================================

#include "game\client\c_point_commentary_node.h"

//------------------------------------------------------------------------------
// Address: 0x10010A10
// Name: public: virtual bool vgui::Panel::LookupElementBounds(char const __near *,int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::Panel::LookupElementBounds(
        CParticleOperatorInstance *this,
        int nStartBlock,
        int nNumBlocks,
        CParticleCollection *pParticles,
        CParticleCollection *pContext,
        void *nNumValidParticlesInLastChunk)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x1007EF70
// Name: public: static char const __near * CHudCommentary::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CHudCommentary::GetPanelClassName()
{
  return "CHudCommentary";
}

//------------------------------------------------------------------------------
// Address: 0x1007EF80
// Name: private: static void __near * CHudCommentary::GetVar_m_iBarX(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel::Panel_RegisterMap *__cdecl CHudCommentary::GetVar_m_iBarX(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return &panel[3].m_RegisterClass;
  else
    return (vgui::Panel::Panel_RegisterMap *)1056;
}

//------------------------------------------------------------------------------
// Address: 0x1007EFA0
// Name: private: static void __near * CHudCommentary::GetVar_m_iBarY(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel::PanelMessageFunc_OnDelete *__cdecl CHudCommentary::GetVar_m_iBarY(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return &panel[3].m_OnDelete_register;
  else
    return (vgui::Panel::PanelMessageFunc_OnDelete *)1064;
}

//------------------------------------------------------------------------------
// Address: 0x1007EFC0
// Name: private: static void __near * CHudCommentary::GetVar_m_iBarTall(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel::NAV_DIRECTION *__cdecl CHudCommentary::GetVar_m_iBarTall(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return &panel[3].m_LastNavDirection;
  else
    return (vgui::Panel::NAV_DIRECTION *)1072;
}

//------------------------------------------------------------------------------
// Address: 0x1007EFE0
// Name: private: static void __near * CHudCommentary::GetVar_m_iBarWide(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel::PanelMessageFunc_InternalMouseDoublePressed *__cdecl CHudCommentary::GetVar_m_iBarWide(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return &panel[3].m_InternalMouseDoublePressed_register;
  else
    return (vgui::Panel::PanelMessageFunc_InternalMouseDoublePressed *)1080;
}

//------------------------------------------------------------------------------
// Address: 0x1007F000
// Name: private: static void __near * CHudCommentary::GetVar_m_iSpeakersX(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel::PanelMessageFunc_InternalKeyFocusTicked *__cdecl CHudCommentary::GetVar_m_iSpeakersX(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return &panel[3].m_InternalKeyFocusTicked_register;
  else
    return (vgui::Panel::PanelMessageFunc_InternalKeyFocusTicked *)1088;
}

//------------------------------------------------------------------------------
// Address: 0x1007F020
// Name: private: static void __near * CHudCommentary::GetVar_m_iSpeakersY(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
Color *__cdecl CHudCommentary::GetVar_m_iSpeakersY(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return &panel[3].m_clrDragFrame;
  else
    return (Color *)1096;
}

//------------------------------------------------------------------------------
// Address: 0x1007F040
// Name: private: static void __near * CHudCommentary::GetVar_m_iCountXFR(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Tooltip **__cdecl CHudCommentary::GetVar_m_iCountXFR(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return &panel[3].m_pTooltips;
  else
    return (vgui::Tooltip **)1104;
}

//------------------------------------------------------------------------------
// Address: 0x1007F060
// Name: private: static void __near * CHudCommentary::GetVar_m_iCountY(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl CHudCommentary::GetVar_m_iCountY(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return &panel[3].m_lLastDoublePressTime;
  else
    return (void *)1112;
}

//------------------------------------------------------------------------------
// Address: 0x1007F080
// Name: private: static void __near * CHudCommentary::GetVar_m_iIconX(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::KeyBindingContextHandle_t *__cdecl CHudCommentary::GetVar_m_iIconX(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return &panel[3].m_hKeyBindingsContext;
  else
    return (vgui::KeyBindingContextHandle_t *)1120;
}

//------------------------------------------------------------------------------
// Address: 0x1007F0A0
// Name: private: static void __near * CHudCommentary::GetVar_m_iIconY(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlString *__cdecl CHudCommentary::GetVar_m_iIconY(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return &panel[3]._panelName;
  else
    return (CUtlString *)1128;
}

//------------------------------------------------------------------------------
// Address: 0x1007F0C0
// Name: private: static void __near * CHudCommentary::GetVar_m_iIconWide(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl CHudCommentary::GetVar_m_iIconWide(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return &panel[3]._panelName.m_Storage.m_Memory.m_nGrowSize;
  else
    return (void *)1136;
}

//------------------------------------------------------------------------------
// Address: 0x1007F0E0
// Name: private: static void __near * CHudCommentary::GetVar_m_iIconTall(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::IBorder **__cdecl CHudCommentary::GetVar_m_iIconTall(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return &panel[3]._border;
  else
    return (vgui::IBorder **)1144;
}

//------------------------------------------------------------------------------
// Address: 0x1007F100
// Name: private: static void __near * CHudCommentary::GetVar_m_nIconTextureId(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Dar<unsigned long> *__cdecl CHudCommentary::GetVar_m_nIconTextureId(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return &panel[3]._actionSignalTargetDar;
  else
    return (vgui::Dar<unsigned long> *)1152;
}

//------------------------------------------------------------------------------
// Address: 0x1007F120
// Name: private: static void __near * CHudCommentary::GetVar_m_bUseScriptBGColor(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CHudCommentary::GetVar_m_bUseScriptBGColor(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return (int)&panel[3]._actionSignalTargetDar.m_Memory.m_nAllocationCount + 1;
  else
    return 1157;
}

//------------------------------------------------------------------------------
// Address: 0x1007F140
// Name: private: static void __near * CHudCommentary::GetVar_m_BackgroundColor(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CHudCommentary::GetVar_m_BackgroundColor(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return (int)&panel[3]._actionSignalTargetDar.m_Memory.m_nAllocationCount + 3;
  else
    return 1159;
}

//------------------------------------------------------------------------------
// Address: 0x1007F160
// Name: private: static void __near * CHudCommentary::GetVar_m_BGOverrideColor(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl CHudCommentary::GetVar_m_BGOverrideColor(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return &panel[3]._actionSignalTargetDar.m_Size;
  else
    return (void *)1164;
}

//------------------------------------------------------------------------------
// Address: 0x1007F180
// Name: public: virtual class ClientClass __near * C_PointCommentaryNode::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_PointCommentaryNode::GetClientClass(C_PointCommentaryNode *this)
{
  return &__g_C_PointCommentaryNodeClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1007F2E0
// Name: public: virtual struct datamap_t __near * C_PointCommentaryNode::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall C_PointCommentaryNode::GetDataDescMap(C_PointCommentaryNode *this)
{
  return &C_PointCommentaryNode::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1007F2F0
// Name: public: virtual void C_PointCommentaryNode::OnPreDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_PointCommentaryNode::OnPreDataChanged(C_PointCommentaryNode *this, DataUpdateType_t updateType)
{
  C_BaseAnimating::OnPreDataChanged(this, updateType);
  BYTE1(this->m_vecRenderOriginOverride.z) = LOBYTE(this->m_vecRenderOriginOverride.z);
}

//------------------------------------------------------------------------------
// Address: 0x1007F310
// Name: public: virtual bool C_PointCommentaryNode::TestCollision(struct Ray_t const __near &,unsigned int,class CGameTrace __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_PointCommentaryNode::TestCollision(
        C_PointCommentaryNode *this,
        const Ray_t *ray,
        unsigned int mask,
        CGameTrace *trace)
{
  return g_bTracingVsCommentaryNodes && C_BaseAnimating::TestCollision(this, ray, fContentsMask: mask, tr: trace);
}

//------------------------------------------------------------------------------
// Address: 0x1007F330
// Name: public: virtual void CHudCommentary::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudCommentary::ApplySchemeSettings(CHudCommentary *this, vgui::IScheme *pScheme)
{
  vgui::Panel::ApplySchemeSettings((vgui::Panel *)this, (int)pScheme);
  if ( *((_BYTE *)&this->m_m_iCountXFR_register + 1) != 0 )
    ((void (__thiscall *)(CHudCommentary *, _DWORD))this->CHudElement::CGameEventListener::IGameEventListener2::__vftable[3].VidInit)(
      a1: this,
      a2: *(_DWORD *)&this->m_m_iCountY_register);
}

//------------------------------------------------------------------------------
// Address: 0x1007F360
// Name: public: virtual void CHudCommentary::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudCommentary::Init(CHudCommentary *this)
{
  CMaterialReference::Init(
    this: &this->m_matIcon,
    pMaterialName: "vgui/hud/icon_commentary",
    pTextureGroupName: "VGUI textures",
    bComplain: true);
}

//------------------------------------------------------------------------------
// Address: 0x1007F380
// Name: bool IsInCommentaryMode(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl IsInCommentaryMode()
{
  return g_CommentaryNodes.m_Size > 0;
}

//------------------------------------------------------------------------------
// Address: 0x1007F400
// Name: bool IsNodeUnderCrosshair(class C_BasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsNodeUnderCrosshair(C_BasePlayer *pPlayer)
{
  const QAngle *v1; // eax
  CGameTrace tr; // [esp+4h] [ebp-78h] BYREF
  Vector vecAbsEnd; // [esp+58h] [ebp-24h] BYREF
  Vector vecForward; // [esp+64h] [ebp-18h] BYREF
  Vector vecSrc; // [esp+70h] [ebp-Ch] BYREF

  pPlayer->EyePosition(this: pPlayer, result: &vecSrc);
  v1 = pPlayer->EyeAngles(this: pPlayer);
  AngleVectors(angles: v1, forward: &vecForward);
  vecAbsEnd.y = vecSrc.y + (float)(vecForward.y * 56755.84);
  g_bTracingVsCommentaryNodes = true;
  vecAbsEnd.x = vecSrc.x + (float)(vecForward.x * 56755.84);
  vecAbsEnd.z = vecSrc.z + (float)(vecForward.z * 56755.84);
  UTIL_TraceLine(vecAbsStart: &vecSrc, &vecAbsEnd, mask: 0x200400Bu, ignore: pPlayer, collisionGroup: 0, ptr: &tr);
  g_bTracingVsCommentaryNodes = false;
  return tr.m_pEnt != nullptr
      && __RTDynamicCast(
           inptr: tr.m_pEnt,
           VfDelta: 0,
           SrcType: &C_BaseEntity `RTTI Type Descriptor',
           TargetType: &C_PointCommentaryNode `RTTI Type Descriptor',
           isReference: 0) != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1007F4E0
// Name: public: virtual bool CHudCommentary::ShouldDraw(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CHudCommentary::ShouldDraw(CHudCommentary *this)
{
  unsigned int m_Index; // edx

  m_Index = this->m_hActiveNode.m_Index;
  return m_Index != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr
      || vgui::Panel::GetAlpha(this: &this->vgui::Panel) > 0;
}

//------------------------------------------------------------------------------
// Address: 0x1007F530
// Name: bool CommentaryModeShouldSwallowInput(class C_BasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CommentaryModeShouldSwallowInput(C_BasePlayer *pPlayer)
{
  int m_nButtons; // eax
  bool result; // al

  result = false;
  if ( g_CommentaryNodes.m_Size > 0 )
  {
    m_nButtons = pPlayer->m_nButtons;
    if ( (m_nButtons & 0x20) != 0 && ((m_nButtons & 0x800) != 0 || IsNodeUnderCrosshair(pPlayer)) )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007F570
// Name: public: virtual void CHudCommentary::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CHudCommentary::Paint(CHudCommentary *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  float v4; // xmm0_4
  float m_flAlpha; // ecx
  int v6; // eax
  CEntInfo *v7; // edx
  int v8; // ecx
  IClientMode *ClientMode; // eax
  vgui::AnimationController *v10; // eax
  CHud *Hud; // eax
  CHudElement *Element; // eax
  int v13; // eax
  bool v14; // zf
  CEntInfo *v15; // eax
  IHandleEntity *m_pEntity; // eax
  IHandleEntity_vtbl *v17; // edi
  CSoundEnvelopeController *Controller; // eax
  double v19; // st7
  float v20; // xmm0_4
  float v21; // ecx
  IClientMode *v22; // eax
  vgui::AnimationController *v23; // eax
  int v24; // edi
  int v25; // ebx
  char Alpha; // al
  void (__thiscall *DrawSetColor)(vgui::ISurface *, Color); // edx
  unsigned int v28; // ebx
  vgui::IScheme *v29; // eax
  unsigned int v30; // edi
  vgui::IScheme *v31; // eax
  int *p_m_nBgTextureId1; // eax
  __int16 v33; // bx
  wchar_t *v34; // eax
  __int16 v35; // dx
  vgui::ISurface *v36; // edi
  char v37; // al
  void (__thiscall *v38)(vgui::ISurface *, Color); // edx
  int iCountTall; // [esp+4h] [ebp-20h] BYREF
  int x; // [esp+8h] [ebp-1Ch] BYREF
  int y; // [esp+Ch] [ebp-18h] BYREF
  int tall; // [esp+10h] [ebp-14h] BYREF
  int iCountWide; // [esp+14h] [ebp-10h] BYREF
  int wide; // [esp+18h] [ebp-Ch] BYREF
  float flPercentage; // [esp+1Ch] [ebp-8h]
  float flDuration; // [esp+20h] [ebp-4h]

  v4 = *(float *)&this->m_m_nBgTextureId1_register - *(float *)&this->m_nPaintBackgroundType;
  m_flAlpha = this->m_flAlpha;
  flDuration = v4;
  flPercentage = 1.0;
  if ( m_flAlpha == NAN
    || (v6 = LOWORD(m_flAlpha),
        v7 = &g_pEntityList->m_EntPtrArray[LOWORD(m_flAlpha)],
        v8 = HIWORD(LODWORD(m_flAlpha)),
        v7->m_SerialNumber != v8)
    || v7->m_pEntity == nullptr )
  {
    if ( LOBYTE(this->m_szCount[38]) == 0 )
    {
      LOBYTE(this->m_szCount[38]) = 1;
      ClientMode = GetClientMode();
      v10 = ClientMode->GetViewportAnimationController(this: ClientMode);
      vgui::AnimationController::StartAnimationSequence(this: v10, sequenceName: "HideCommentary");
      Hud = GetHud(nSlot: 0);
      Element = CHud::FindElement(this: Hud, pName: "CHudCloseCaption");
      if ( Element != nullptr )
        Element->Reset(this: Element);
    }
    goto LABEL_22;
  }
  v13 = v6;
  v14 = g_pEntityList->m_EntPtrArray[v13].m_SerialNumber == v8;
  v15 = &g_pEntityList->m_EntPtrArray[v13];
  if ( v14 )
    m_pEntity = v15->m_pEntity;
  else
    m_pEntity = nullptr;
  v17 = m_pEntity[1012].__vftable;
  Controller = CSoundEnvelopeController::GetController();
  v19 = ((double (__thiscall *)(CSoundEnvelopeController *, IHandleEntity_vtbl *))Controller->SoundGetElapsedTime)(
          a1: Controller,
          a2: v17)
      / flDuration;
  flDuration = v19;
  if ( v19 >= 0.0 )
  {
    v20 = flDuration;
    if ( flDuration <= 1.0 )
    {
      flPercentage = flDuration;
      if ( flDuration <= 0.0 )
        goto LABEL_16;
    }
    else
    {
      v20 = 1.0;
      flPercentage = 1.0;
    }
    HIBYTE(this->m_szCount[38]) = 1;
    goto LABEL_16;
  }
  v20 = 0.0;
  flPercentage = 0.0;
LABEL_16:
  if ( HIBYTE(this->m_szCount[38]) != 0 && v20 == 0.0 )
  {
    v21 = this->m_flAlpha;
    if ( v21 != NAN
      && g_pEntityList->m_EntPtrArray[LOWORD(v21)].m_SerialNumber == HIWORD(LODWORD(v21))
      && g_pEntityList->m_EntPtrArray[LOWORD(v21)].m_pEntity != nullptr )
    {
      this->m_flAlpha = NAN;
      v22 = GetClientMode();
      v23 = (vgui::AnimationController *)((int (__thiscall *)(IClientMode *, const char *))v22->GetViewportAnimationController)(
                                           a1: v22,
                                           a2: "HideCommentary");
      vgui::AnimationController::StartAnimationSequence(this: v23, sequenceName: (const char *)a3);
      a3 = 1;
      ((void (__thiscall *)(IVEngineClient *, const char *))engine->ServerCmd)(
        a1: engine,
        a2: "commentary_finishnode\n");
      flPercentage = 1.0;
    }
  }
LABEL_22:
  if ( *(_BYTE *)&this->m_m_nPaintBackgroundType_register != 0 )
  {
    vgui::Panel::GetBounds((vgui::Panel *)this, &x, &y, &wide, &tall);
    v24 = *(_DWORD *)&this->m_szCount[40];
    v25 = *(_DWORD *)&this->m_szCount[44];
    LOWORD(flDuration) = -21761;
    BYTE2(flDuration) = 0;
    Alpha = vgui::Panel::GetAlpha((vgui::Panel *)this);
    DrawSetColor = g_pVGuiSurface->DrawSetColor;
    HIBYTE(flDuration) = Alpha;
    ((void (__thiscall *)(vgui::ISurface *, _DWORD, int, int))DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: LODWORD(flDuration),
      a3: a2,
      a4: a3);
    g_pVGuiSurface->DrawOutlinedRect(
      this: g_pVGuiSurface,
      a2: v24,
      a3: v25,
      a4: v24 + *(_DWORD *)&this->m_szCount[52],
      a5: v25 + *(_DWORD *)&this->m_szCount[48]);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
      a1: g_pVGuiSurface,
      a2: LODWORD(flDuration));
    ((void (__stdcall *)(int, int, int, int))g_pVGuiSurface->DrawFilledRect)(
      a1: v24 + 2,
      a2: v25 + 2,
      a3: (int)(float)((float)*(int *)&this->m_szCount[52] * flPercentage) + v24 - 2,
      a4: v25 + *(_DWORD *)&this->m_szCount[48] - 2);
    v28 = this->CHudElement::CGameEventListener::IGameEventListener2::__vftable[1].GetEventDebugID(this);
    v29 = g_pVGuiSchemeManager->GetIScheme(this: g_pVGuiSchemeManager, a2: v28);
    v30 = v29->GetFont(this: v29, a2: "CommentaryDefault", a3: true);
    if ( v30 == 0 )
    {
      v31 = g_pVGuiSchemeManager->GetIScheme(this: g_pVGuiSchemeManager, a2: v28);
      v30 = v31->GetFont(this: v31, a2: "Default", a3: true);
    }
    g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: v30);
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetTextColor)(
      a1: g_pVGuiSurface,
      a2: LODWORD(flDuration));
    g_pVGuiSurface->DrawSetTextPos(
      this: g_pVGuiSurface,
      a2: *(_DWORD *)&this->m_szCount[56],
      a3: *(_DWORD *)&this->m_szCount[60]);
    p_m_nBgTextureId1 = &this->m_nBgTextureId1;
    do
    {
      v33 = *(_WORD *)p_m_nBgTextureId1;
      p_m_nBgTextureId1 = (int *)((char *)p_m_nBgTextureId1 + 2);
    }
    while ( v33 != 0 );
    g_pVGuiSurface->DrawPrintText(
      this: g_pVGuiSurface,
      a2: (const wchar_t *)&this->m_nBgTextureId1,
      a3: ((char *)p_m_nBgTextureId1 - ((char *)&this->m_nBgTextureId1 + 2)) >> 1,
      a4: FONT_DRAW_DEFAULT);
    g_pVGuiSurface->GetTextSize(
      this: g_pVGuiSurface,
      a2: v30,
      a3: &this->m_szSpeakers[228],
      a4: &iCountWide,
      a5: &iCountTall);
    ((void (__stdcall *)(unsigned int, int))g_pVGuiSurface->DrawSetTextPos)(
      a1: wide - (unsigned int)this->m_matIcon.m_pMaterial - iCountWide,
      a2: this->m_iBarX);
    v34 = &this->m_szSpeakers[228];
    do
      v35 = *v34++;
    while ( v35 != 0 );
    ((void (__thiscall *)(vgui::ISurface *, wchar_t *))g_pVGuiSurface->DrawPrintText)(
      a1: g_pVGuiSurface,
      a2: &this->m_szSpeakers[228]);
    v36 = g_pVGuiSurface;
    LOWORD(flPercentage) = -21761;
    BYTE2(flPercentage) = 0;
    v37 = vgui::Panel::GetAlpha((vgui::Panel *)this);
    v38 = v36->DrawSetColor;
    HIBYTE(flPercentage) = v37;
    ((void (__thiscall *)(vgui::ISurface *, _DWORD))v38)(a1: v36, a2: LODWORD(flPercentage));
    g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: this->m_iSpeakersY);
    g_pVGuiSurface->DrawTexturedRect(
      this: g_pVGuiSurface,
      a2: this->m_iBarY,
      a3: this->m_iBarTall,
      a4: this->m_iBarWide,
      a5: this->m_iSpeakersX);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007F970
// Name: public: void CHudCommentary::StartCommentary(class C_PointCommentaryNode __near *,char __near *,int,int,float,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CHudCommentary::StartCommentary(
        CHudCommentary *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        C_PointCommentaryNode *pNode,
        char *pszSpeakers,
        int iNode,
        int iNodeMax,
        float flStartTime,
        float flEndTime)
{
  int (__thiscall *ConvertANSIToUnicode)(ILocalize *, const char *, wchar_t *, int); // eax
  IClientMode *ClientMode; // eax
  vgui::AnimationController *v12; // eax
  int v13; // [esp-8h] [ebp-50h]
  char sz[64]; // [esp+0h] [ebp-48h] BYREF
  ConVarRef pCVar; // [esp+40h] [ebp-8h] BYREF

  if ( (float)(flEndTime - flStartTime) > 0.0 )
  {
    if ( pNode != nullptr )
      this->m_hActiveNode.m_Index = pNode->GetRefEHandle(this: pNode)->m_Index;
    else
      this->m_hActiveNode.m_Index = -1;
    this->m_flStartTime = flStartTime;
    this->m_flEndTime = flEndTime;
    *(_WORD *)&this->m_bHiding = 0;
    ((void (__thiscall *)(vgui::ILocalize *, char *, wchar_t *, int, int, _DWORD, _DWORD, _DWORD))g_pVGuiLocalize->ConvertANSIToUnicode)(
      a1: g_pVGuiLocalize,
      a2: pszSpeakers,
      a3: this->m_szSpeakers,
      a4: 512,
      a5: a3,
      a6: *(_DWORD *)sz,
      a7: *(_DWORD *)&sz[4],
      a8: *(_DWORD *)&sz[8]);
    ConVarRef::ConVarRef(this: &pCVar, pName: "closecaption");
    this->m_bShouldPaint = !ConVarRef::IsValid(this: (SplitScreenConVarRef *)&pCVar)
                        || pCVar.m_pConVarState->m_Value.m_nValue == 0
                        && english.m_pParent != nullptr
                        && english.m_pParent->m_Value.m_nValue != 0;
    ((void (__thiscall *)(vgui::Panel *, bool, int))this->SetPaintBackgroundEnabled)(
      a1: &this->vgui::Panel,
      a2: this->m_bShouldPaint,
      a3: a2);
    *(_DWORD *)sz = iNodeMax;
    V_snprintf(pDest: sz, maxLen: 0x40u, pFormat: "%d \\ %d", iNode);
    ConvertANSIToUnicode = g_pVGuiLocalize->ConvertANSIToUnicode;
    *(_DWORD *)sz = 128;
    ((void (__thiscall *)(vgui::ILocalize *, char *))ConvertANSIToUnicode)(a1: g_pVGuiLocalize, a2: sz);
    if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(flStartTime - *(float *)(gpGlobals.m_Index + 12)) & _mask__AbsFloat_) >= 1.0 )
    {
      vgui::Panel::SetAlpha(this: &this->vgui::Panel, alpha: 255);
    }
    else
    {
      ClientMode = GetClientMode();
      v12 = (vgui::AnimationController *)((int (__thiscall *)(IClientMode *, const char *, int, wchar_t *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))ClientMode->GetViewportAnimationController)(
                                           a1: ClientMode,
                                           a2: "ShowCommentary",
                                           a3: v13,
                                           a4: this->m_szCount,
                                           a5: *(_DWORD *)sz,
                                           a6: *(_DWORD *)&sz[4],
                                           a7: *(_DWORD *)&sz[8],
                                           a8: *(_DWORD *)&sz[12],
                                           a9: *(_DWORD *)&sz[16],
                                           a10: *(_DWORD *)&sz[20],
                                           a11: *(_DWORD *)&sz[24],
                                           a12: *(_DWORD *)&sz[28],
                                           a13: *(_DWORD *)&sz[32],
                                           a14: *(_DWORD *)&sz[36],
                                           a15: *(_DWORD *)&sz[40],
                                           a16: *(_DWORD *)&sz[44],
                                           a17: *(_DWORD *)&sz[48],
                                           a18: *(_DWORD *)&sz[52],
                                           a19: *(_DWORD *)&sz[56]);
      vgui::AnimationController::StartAnimationSequence(this: v12, sequenceName: *(const char **)&sz[60]);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007FB80
// Name: public: void C_PointCommentaryNode::RemoveAndUnlockCommentaryHudGroup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_PointCommentaryNode::RemoveAndUnlockCommentaryHudGroup(C_PointCommentaryNode *this)
{
  int v1; // eax
  CHud *Hud; // eax
  CHud *v3; // eax
  int v4; // [esp-8h] [ebp-Ch]
  CHandle<C_BasePlayer> src; // [esp+0h] [ebp-4h] BYREF

  src.m_Index = (unsigned int)this;
  if ( this != nullptr )
    src.m_Index = *(_DWORD *)((int (__thiscall *)(C_PointCommentaryNode *, unsigned int))this->GetRefEHandle)(
                               a1: this,
                               a2: src.m_Index);
  else
    src.m_Index = -1;
  v1 = CUtlVector<CHandle<C_BasePlayer>,CUtlMemory<CHandle<C_BasePlayer>,int>>::Find(
         this: (CUtlVector<CHandle<C_BasePlayer>,CUtlMemory<CHandle<C_BasePlayer>,int> > *)&g_CommentaryNodes,
         (CHandle<C_BaseCombatWeapon> *)&src);
  if ( v1 != -1 )
  {
    if ( g_CommentaryNodes.m_Size - v1 - 1 > 0 )
      _V_memmove(
        dest: &g_CommentaryNodes.m_Memory.m_pMemory[v1],
        src: &g_CommentaryNodes.m_Memory.m_pMemory[v1 + 1],
        count: 4 * (g_CommentaryNodes.m_Size - v1 - 1));
    --g_CommentaryNodes.m_Size;
  }
  if ( g_CommentaryNodes.m_Size == 0 )
  {
    Hud = GetHud(nSlot: -1);
    v4 = CHud::RegisterForRenderGroup(this: Hud, pszGroupName: "commentary");
    v3 = GetHud(nSlot: -1);
    CHud::UnlockRenderGroup(this: v3, iGroupIndex: v4, pLocker: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007FC20
// Name: public: virtual void CHudCommentary::VidInit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudCommentary::VidInit(CHudCommentary *this)
{
  vgui::Panel::SetAlpha(this: &this->vgui::Panel, alpha: 0);
  this->m_hActiveNode.m_Index = -1;
}

//------------------------------------------------------------------------------
// Address: 0x1007FC40
// Name: public: static void CHudCommentary::PanelAnimationVar_m_iBarX::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudCommentary::PanelAnimationVar_m_iBarX::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudCommentary::PanelAnimationVar_m_iBarX::InitVar'::`2'::bAdded )
  {
    `CHudCommentary::PanelAnimationVar_m_iBarX::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudCommentary");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "bar_xpos";
    src.m_pszVariable = "m_iBarX";
    src.m_pszType = "proportional_int";
    src.m_pszDefaultValue = "8";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CHudCommentary::GetVar_m_iBarX;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007FCA0
// Name: public: static void CHudCommentary::PanelAnimationVar_m_iBarY::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudCommentary::PanelAnimationVar_m_iBarY::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudCommentary::PanelAnimationVar_m_iBarY::InitVar'::`2'::bAdded )
  {
    `CHudCommentary::PanelAnimationVar_m_iBarY::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudCommentary");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "bar_ypos";
    src.m_pszVariable = "m_iBarY";
    src.m_pszType = "proportional_int";
    src.m_pszDefaultValue = "8";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CHudCommentary::GetVar_m_iBarY;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007FD00
// Name: public: static void CHudCommentary::PanelAnimationVar_m_iBarTall::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudCommentary::PanelAnimationVar_m_iBarTall::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudCommentary::PanelAnimationVar_m_iBarTall::InitVar'::`2'::bAdded )
  {
    `CHudCommentary::PanelAnimationVar_m_iBarTall::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudCommentary");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "bar_height";
    src.m_pszVariable = "m_iBarTall";
    src.m_pszType = "proportional_int";
    src.m_pszDefaultValue = "16";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CHudCommentary::GetVar_m_iBarTall;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007FD60
// Name: public: static void CHudCommentary::PanelAnimationVar_m_iBarWide::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudCommentary::PanelAnimationVar_m_iBarWide::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudCommentary::PanelAnimationVar_m_iBarWide::InitVar'::`2'::bAdded )
  {
    `CHudCommentary::PanelAnimationVar_m_iBarWide::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudCommentary");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "bar_width";
    src.m_pszVariable = "m_iBarWide";
    src.m_pszType = "proportional_int";
    src.m_pszDefaultValue = "16";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CHudCommentary::GetVar_m_iBarWide;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007FDC0
// Name: public: static void CHudCommentary::PanelAnimationVar_m_iSpeakersX::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudCommentary::PanelAnimationVar_m_iSpeakersX::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudCommentary::PanelAnimationVar_m_iSpeakersX::InitVar'::`2'::bAdded )
  {
    `CHudCommentary::PanelAnimationVar_m_iSpeakersX::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudCommentary");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "speaker_xpos";
    src.m_pszVariable = "m_iSpeakersX";
    src.m_pszType = "proportional_int";
    src.m_pszDefaultValue = "8";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CHudCommentary::GetVar_m_iSpeakersX;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007FE20
// Name: public: static void CHudCommentary::PanelAnimationVar_m_iSpeakersY::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudCommentary::PanelAnimationVar_m_iSpeakersY::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudCommentary::PanelAnimationVar_m_iSpeakersY::InitVar'::`2'::bAdded )
  {
    `CHudCommentary::PanelAnimationVar_m_iSpeakersY::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudCommentary");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "speaker_ypos";
    src.m_pszVariable = "m_iSpeakersY";
    src.m_pszType = "proportional_int";
    src.m_pszDefaultValue = "8";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CHudCommentary::GetVar_m_iSpeakersY;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007FE80
// Name: public: static void CHudCommentary::PanelAnimationVar_m_iCountXFR::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudCommentary::PanelAnimationVar_m_iCountXFR::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudCommentary::PanelAnimationVar_m_iCountXFR::InitVar'::`2'::bAdded )
  {
    `CHudCommentary::PanelAnimationVar_m_iCountXFR::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudCommentary");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "count_xpos_from_right";
    src.m_pszVariable = "m_iCountXFR";
    src.m_pszType = "proportional_int";
    src.m_pszDefaultValue = "8";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CHudCommentary::GetVar_m_iCountXFR;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007FEE0
// Name: public: static void CHudCommentary::PanelAnimationVar_m_iCountY::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudCommentary::PanelAnimationVar_m_iCountY::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudCommentary::PanelAnimationVar_m_iCountY::InitVar'::`2'::bAdded )
  {
    `CHudCommentary::PanelAnimationVar_m_iCountY::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudCommentary");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "count_ypos";
    src.m_pszVariable = "m_iCountY";
    src.m_pszType = "proportional_int";
    src.m_pszDefaultValue = "8";
    src.m_pfnLookup = CHudCommentary::GetVar_m_iCountY;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007FF40
// Name: public: static void CHudCommentary::PanelAnimationVar_m_iIconX::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudCommentary::PanelAnimationVar_m_iIconX::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudCommentary::PanelAnimationVar_m_iIconX::InitVar'::`2'::bAdded )
  {
    `CHudCommentary::PanelAnimationVar_m_iIconX::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudCommentary");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "icon_xpos";
    src.m_pszVariable = "m_iIconX";
    src.m_pszType = "proportional_int";
    src.m_pszDefaultValue = "8";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CHudCommentary::GetVar_m_iIconX;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007FFA0
// Name: public: static void CHudCommentary::PanelAnimationVar_m_iIconY::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudCommentary::PanelAnimationVar_m_iIconY::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudCommentary::PanelAnimationVar_m_iIconY::InitVar'::`2'::bAdded )
  {
    `CHudCommentary::PanelAnimationVar_m_iIconY::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudCommentary");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "icon_ypos";
    src.m_pszVariable = "m_iIconY";
    src.m_pszType = "proportional_int";
    src.m_pszDefaultValue = "8";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CHudCommentary::GetVar_m_iIconY;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10080000
// Name: public: static void CHudCommentary::PanelAnimationVar_m_iIconWide::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudCommentary::PanelAnimationVar_m_iIconWide::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudCommentary::PanelAnimationVar_m_iIconWide::InitVar'::`2'::bAdded )
  {
    `CHudCommentary::PanelAnimationVar_m_iIconWide::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudCommentary");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "icon_width";
    src.m_pszVariable = "m_iIconWide";
    src.m_pszType = "proportional_int";
    src.m_pszDefaultValue = "8";
    src.m_pfnLookup = CHudCommentary::GetVar_m_iIconWide;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10080060
// Name: public: static void CHudCommentary::PanelAnimationVar_m_iIconTall::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudCommentary::PanelAnimationVar_m_iIconTall::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudCommentary::PanelAnimationVar_m_iIconTall::InitVar'::`2'::bAdded )
  {
    `CHudCommentary::PanelAnimationVar_m_iIconTall::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudCommentary");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "icon_height";
    src.m_pszVariable = "m_iIconTall";
    src.m_pszType = "proportional_int";
    src.m_pszDefaultValue = "8";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CHudCommentary::GetVar_m_iIconTall;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100800C0
// Name: public: static void CHudCommentary::PanelAnimationVar_m_nIconTextureId::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudCommentary::PanelAnimationVar_m_nIconTextureId::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudCommentary::PanelAnimationVar_m_nIconTextureId::InitVar'::`2'::bAdded )
  {
    `CHudCommentary::PanelAnimationVar_m_nIconTextureId::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudCommentary");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "icon_texture";
    src.m_pszVariable = "m_nIconTextureId";
    src.m_pszType = "textureid";
    src.m_pszDefaultValue = "vgui/hud/icon_commentary";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CHudCommentary::GetVar_m_nIconTextureId;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10080120
// Name: public: static void CHudCommentary::PanelAnimationVar_m_bUseScriptBGColor::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudCommentary::PanelAnimationVar_m_bUseScriptBGColor::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudCommentary::PanelAnimationVar_m_bUseScriptBGColor::InitVar'::`2'::bAdded )
  {
    `CHudCommentary::PanelAnimationVar_m_bUseScriptBGColor::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudCommentary");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "use_script_bgcolor";
    src.m_pszVariable = "m_bUseScriptBGColor";
    src.m_pszType = "bool";
    src.m_pszDefaultValue = "0";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CHudCommentary::GetVar_m_bUseScriptBGColor;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10080180
// Name: public: static void CHudCommentary::PanelAnimationVar_m_BackgroundColor::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudCommentary::PanelAnimationVar_m_BackgroundColor::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudCommentary::PanelAnimationVar_m_BackgroundColor::InitVar'::`2'::bAdded )
  {
    `CHudCommentary::PanelAnimationVar_m_BackgroundColor::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudCommentary");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "BackgroundColor";
    src.m_pszVariable = "m_BackgroundColor";
    src.m_pszType = "Color";
    src.m_pszDefaultValue = "0 0 0 0";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CHudCommentary::GetVar_m_BackgroundColor;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100801E0
// Name: public: static void CHudCommentary::PanelAnimationVar_m_BGOverrideColor::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudCommentary::PanelAnimationVar_m_BGOverrideColor::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudCommentary::PanelAnimationVar_m_BGOverrideColor::InitVar'::`2'::bAdded )
  {
    `CHudCommentary::PanelAnimationVar_m_BGOverrideColor::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudCommentary");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "BackgroundOverrideColor";
    src.m_pszVariable = "m_BGOverrideColor";
    src.m_pszType = "Color";
    src.m_pszDefaultValue = "Panel.BgColor";
    src.m_pfnLookup = CHudCommentary::GetVar_m_BGOverrideColor;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10080240
// Name: public: virtual void C_PointCommentaryNode::SetDormant(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_PointCommentaryNode::SetDormant(C_PointCommentaryNode *this, BOOL bDormant)
{
  if ( !this->IsDormant(this: &this->IClientNetworkable) && bDormant )
    C_PointCommentaryNode::RemoveAndUnlockCommentaryHudGroup(this);
  C_BaseEntity::SetDormant(this, bDormant);
}

//------------------------------------------------------------------------------
// Address: 0x10080280
// Name: public: virtual void C_PointCommentaryNode::UpdateOnRemove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_PointCommentaryNode::UpdateOnRemove(C_PointCommentaryNode *this)
{
  CSoundEnvelopeController *Controller; // eax

  C_PointCommentaryNode::RemoveAndUnlockCommentaryHudGroup(this);
  if ( this->m_sndCommentary != nullptr )
  {
    Controller = CSoundEnvelopeController::GetController();
    Controller->SoundDestroy(this: Controller, a2: this->m_sndCommentary);
    this->m_sndCommentary = nullptr;
  }
  C_BaseEntity::UpdateOnRemove(this);
}

//------------------------------------------------------------------------------
// Address: 0x100802C0
// Name: public: void C_PointCommentaryNode::AddAndLockCommentaryHudGroup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_PointCommentaryNode::AddAndLockCommentaryHudGroup(C_PointCommentaryNode *this)
{
  int m_Size; // esi
  unsigned int m_Index; // ebx
  CHud *Hud; // eax
  CHud *v5; // eax
  const CBaseHandle *v6; // eax
  int v7; // edi
  CHandle<C_PointCommentaryNode> *m_pMemory; // eax
  int v9; // esi
  CHandle<C_PointCommentaryNode> *v10; // eax
  int v11; // [esp-8h] [ebp-18h]
  CHandle<C_BasePlayer> src; // [esp+Ch] [ebp-4h] BYREF

  m_Size = g_CommentaryNodes.m_Size;
  m_Index = -1;
  if ( g_CommentaryNodes.m_Size == 0 )
  {
    Hud = GetHud(nSlot: -1);
    v11 = CHud::RegisterForRenderGroup(this: Hud, pszGroupName: "commentary");
    v5 = GetHud(nSlot: -1);
    CHud::LockRenderGroup(this: v5, iGroupIndex: v11, pLocker: nullptr);
    m_Size = g_CommentaryNodes.m_Size;
  }
  if ( this != nullptr )
  {
    v6 = this->GetRefEHandle(this);
    m_Size = g_CommentaryNodes.m_Size;
    src.m_Index = v6->m_Index;
  }
  else
  {
    src.m_Index = -1;
  }
  if ( CUtlVector<CHandle<C_BasePlayer>,CUtlMemory<CHandle<C_BasePlayer>,int>>::Find(
         this: (CUtlVector<CHandle<C_BasePlayer>,CUtlMemory<CHandle<C_BasePlayer>,int> > *)&g_CommentaryNodes,
         (CHandle<C_BaseCombatWeapon> *)&src) == -1 )
  {
    if ( this != nullptr )
    {
      m_Index = this->GetRefEHandle(this)->m_Index;
      m_Size = g_CommentaryNodes.m_Size;
    }
    v7 = m_Size;
    if ( m_Size + 1 > g_CommentaryNodes.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<CChoreoActor *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&g_CommentaryNodes,
        num: m_Size - g_CommentaryNodes.m_Memory.m_nAllocationCount + 1);
      m_Size = g_CommentaryNodes.m_Size;
    }
    m_pMemory = g_CommentaryNodes.m_Memory.m_pMemory;
    g_CommentaryNodes.m_Size = m_Size + 1;
    v9 = m_Size - v7;
    g_CommentaryNodes.m_pElements = g_CommentaryNodes.m_Memory.m_pMemory;
    if ( v9 > 0 )
    {
      _V_memmove(
        dest: &g_CommentaryNodes.m_Memory.m_pMemory[v7 + 1],
        src: &g_CommentaryNodes.m_Memory.m_pMemory[v7],
        count: 4 * v9);
      m_pMemory = g_CommentaryNodes.m_Memory.m_pMemory;
    }
    v10 = &m_pMemory[v7];
    if ( v10 != nullptr )
      v10->m_Index = m_Index;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100803B0
// Name: public: virtual void C_PointCommentaryNode::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __userpurge C_PointCommentaryNode::OnDataChanged(
        C_PointCommentaryNode *this@<ecx>,
        int a2@<ebx>,
        DataUpdateType_t updateType)
{
  C_BasePlayer *LocalPlayer; // eax
  C_BasePlayer *v5; // ebx
  const char *p_m_bActive; // edi
  int v7; // eax
  const char *Controller; // ebx
  int v9; // edi
  int v10; // eax
  int v11; // eax
  CSoundEnvelopeController *v12; // eax
  CSoundEnvelopeController *v13; // eax
  CSoundEnvelopeController *v14; // eax
  const char *v15; // eax
  const char *v16; // ecx
  char *v17; // eax
  CHud *Hud; // eax
  CHudCloseCaption *Element; // edi
  CHud *v20; // eax
  CHudCommentary *v21; // eax
  CSoundEnvelopeController *v22; // eax
  CHud *v23; // eax
  CHudElement *v24; // eax
  CHudElement_vtbl *v25; // edx
  C_PointCommentaryNode *m_pEntity; // ecx
  const char *flEndTime; // [esp+30h] [ebp-7Ch]
  EmitSound_t v29; // [esp+40h] [ebp-6Ch] BYREF
  CSingleUserRecipientFilter filter; // [esp+88h] [ebp-24h] BYREF
  char *pszCommentaryFile; // [esp+A8h] [ebp-4h]
  C_BaseCombatWeapon *flDuration; // [esp+B4h] [ebp+8h]
  float flDurationa; // [esp+B4h] [ebp+8h]

  C_BaseAnimating::OnDataChanged(this, updateType);
  if ( updateType == DATA_UPDATE_CREATED )
    C_PointCommentaryNode::AddAndLockCommentaryHudGroup(this: (C_PointCommentaryNode *)((char *)this - 8));
  if ( BYTE1(this->m_vecRenderOriginOverride.z) != LOBYTE(this->m_vecRenderOriginOverride.z)
    || LOBYTE(this->m_sndCommentary) != 0 )
  {
    LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
    v5 = LocalPlayer;
    if ( LOBYTE(this->m_vecRenderOriginOverride.z) != 0 && LocalPlayer != nullptr )
    {
      if ( ((int (__thiscall *)(IMaterialSystemHardwareConfig *, int))g_pMaterialSystemHardwareConfig->GetHDRType)(
             a1: g_pMaterialSystemHardwareConfig,
             a2) != 0
        || this == (C_PointCommentaryNode *)-3516
        || this->m_iszCommentaryFile[252] == 0 )
      {
        pszCommentaryFile = (char *)&this->m_bActive;
        p_m_bActive = (const char *)&this->m_bActive;
      }
      else
      {
        p_m_bActive = &this->m_iszCommentaryFile[252];
        pszCommentaryFile = &this->m_iszCommentaryFile[252];
      }
      if ( p_m_bActive != nullptr && *p_m_bActive != 0 )
      {
        EmitSound_t::EmitSound_t(this: &v29);
        v29.m_nChannel = 6;
        v29.m_pSoundName = p_m_bActive;
        v29.m_SoundLevel = SNDLVL_GUNFIRE;
        v29.m_nFlags = 128;
        if ( CHandle<C_PointCommentaryNode>::operator C_PointCommentaryNode *(this: (CHandle<C_BaseCombatWeapon> *)&this->m_iNodeNumberMax) != nullptr )
        {
          flDuration = CHandle<C_PointCommentaryNode>::operator C_PointCommentaryNode *(this: (CHandle<C_BaseCombatWeapon> *)&this->m_iNodeNumberMax);
        }
        else if ( render->GetViewEntity(this: render) != 0 )
        {
          v7 = render->GetViewEntity(this: render);
          flDuration = (C_BaseCombatWeapon *)CClientEntityList::GetBaseEntity(
                                               this: (CClientEntityList *)cl_entitylist.m_Index,
                                               entnum: v7);
          v29.m_SoundLevel = SNDLVL_NONE;
        }
        else
        {
          flDuration = (C_BaseCombatWeapon *)v5;
        }
        C_RecipientFilter::C_RecipientFilter(this: &filter);
        filter.__vftable = (CSingleUserRecipientFilter_vtbl *)&CSingleUserRecipientFilter::`vftable';
        C_RecipientFilter::AddRecipient(this: &filter, player: v5);
        Controller = (const char *)CSoundEnvelopeController::GetController();
        v9 = *(_DWORD *)Controller;
        v10 = ((int (__thiscall *)(IClientNetworkable *, EmitSound_t *))flDuration->entindex)(
                a1: &flDuration->IClientNetworkable,
                a2: &v29);
        v11 = (*(int (__thiscall **)(const char *, CSingleUserRecipientFilter *, int))(v9 + 24))(
                a1: Controller,
                a2: &filter,
                a3: v10);
        this->m_iNodeNumber = v11;
        if ( v11 != 0 )
        {
          v12 = CSoundEnvelopeController::GetController();
          ((void (__thiscall *)(CSoundEnvelopeController *, int, int))v12->SoundSetCloseCaptionDuration)(
            a1: v12,
            a2: this->m_iNodeNumber,
            a3: -1082130432);
          v13 = CSoundEnvelopeController::GetController();
          ((void (__thiscall *)(CSoundEnvelopeController *, int, int, int, _DWORD))v13->Play)(
            a1: v13,
            a2: this->m_iNodeNumber,
            a3: 1065353216,
            a4: 1120403456,
            a5: *((_DWORD *)&this->m_vecRenderOriginOverride + 3));
        }
        v14 = CSoundEnvelopeController::GetController();
        flEndTime = (const char *)this->m_iNodeNumber;
        v15 = (const char *)((int (__thiscall *)(CSoundEnvelopeController *))v14->SoundGetName)(a1: v14);
        v17 = V_stristr(a1: v16, a2: Controller, pStr: v15, pSearch: flEndTime);
        flDurationa = enginesound->GetSoundDuration(this: enginesound, a2: v17);
        Hud = GetHud(nSlot: 0);
        Element = (CHudCloseCaption *)CHud::FindElement(this: Hud, pName: "CHudCloseCaption");
        if ( Element != nullptr
          && (closecaption.m_pParent != nullptr && closecaption.m_pParent->m_Value.m_nValue != 0
           || english.m_pParent == nullptr
           || english.m_pParent->m_Value.m_nValue == 0) )
        {
          Element->Reset(this: Element);
          CHudCloseCaption::ProcessCaptionDirect(
            this: Element,
            tokenname: pszCommentaryFile,
            duration: flDurationa,
            fromplayer: false);
          CHudCloseCaption::Lock(this: Element);
        }
        v20 = GetHud(nSlot: -1);
        v21 = (CHudCommentary *)CHud::FindElement(this: v20, pName: "CHudCommentary");
        CHudCommentary::StartCommentary(
          this: v21,
          a2: (int)Element,
          a3: (int)this,
          pNode: (C_PointCommentaryNode *)((char *)this - 8),
          pszSpeakers: &this->m_iszCommentaryFileNoHDR[252],
          iNode: *(_DWORD *)&this->m_iszSpeakers[248],
          iNodeMax: *(_DWORD *)&this->m_iszSpeakers[252],
          flStartTime: *((float *)&this->m_vecRenderOriginOverride + 3),
          flEndTime: *((float *)&this->m_vecRenderOriginOverride + 3) + flDurationa);
        C_RecipientFilter::~C_RecipientFilter(this: &filter);
        CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&v29.m_UtlVecSoundOrigin);
        LOBYTE(this->m_sndCommentary) = 0;
      }
      else
      {
        ((void (__thiscall *)(IVEngineClient *, const char *))engine->ServerCmd)(
          a1: engine,
          a2: "commentary_finishnode\n");
      }
    }
    else
    {
      if ( BYTE1(this->m_vecRenderOriginOverride.z) != 0 )
      {
        if ( this->m_iNodeNumber != 0 )
        {
          v22 = CSoundEnvelopeController::GetController();
          v22->SoundDestroy(this: v22, a2: (CSoundPatch *)this->m_iNodeNumber);
          this->m_iNodeNumber = 0;
        }
        v23 = GetHud(nSlot: -1);
        v24 = CHud::FindElement(this: v23, pName: "CHudCommentary");
        v25 = v24[7].__vftable;
        if ( v25 == (CHudElement_vtbl *)-1
          || g_pEntityList->m_EntPtrArray[(unsigned __int16)v25].m_SerialNumber != (unsigned int)v25 >> 16 )
        {
          m_pEntity = nullptr;
        }
        else
        {
          m_pEntity = (C_PointCommentaryNode *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v25].m_pEntity;
        }
        if ( (C_PointCommentaryNode *)((char *)this - 8) == m_pEntity )
          v24[7].__vftable = (CHudElement_vtbl *)-1;
      }
      LOBYTE(this->m_sndCommentary) = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10080740
// Name: public: CHudCommentary::CHudCommentary(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CHudCommentary *__thiscall CHudCommentary::CHudCommentary(CHudCommentary *this, const char *name)
{
  vgui::PanelMessageMap *v3; // ebx
  PanelAnimationMap *v4; // ebx
  vgui::PanelKeyBindingMap *v5; // ebx
  IClientMode *ClientMode; // eax
  vgui::Panel *v7; // eax

  CHudElement::CHudElement(this, pElementName: name);
  vgui::Panel::Panel(this: &this->vgui::Panel, parent: nullptr, panelName: "HudCommentary");
  this->CHudElement::CGameEventListener::IGameEventListener2::__vftable = (CHudCommentary_vtbl *)&CHudCommentary::`vftable'{for `CHudElement'};
  this->vgui::Panel::vgui::IClientPanel::__vftable = (vgui::Panel_vtbl *)&CHudCommentary::`vftable'{for `vgui::Panel'};
  if ( `CHudCommentary::ChainToMap'::`2'::chained == 0 )
  {
    `CHudCommentary::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CHudCommentary");
    v3->pfnClassName = CHudCommentary::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Panel");
  }
  if ( `CHudCommentary::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CHudCommentary::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CHudCommentary");
    v4->pfnClassName = CHudCommentary::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Panel");
  }
  if ( `CHudCommentary::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CHudCommentary::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CHudCommentary");
    v5->pfnClassName = CHudCommentary::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Panel");
  }
  this->m_hActiveNode.m_Index = -1;
  CMaterialReference::CMaterialReference(
    this: &this->m_matIcon,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  CHudCommentary::PanelAnimationVar_m_iBarX::InitVar();
  CHudCommentary::PanelAnimationVar_m_iBarY::InitVar();
  CHudCommentary::PanelAnimationVar_m_iBarTall::InitVar();
  CHudCommentary::PanelAnimationVar_m_iBarWide::InitVar();
  CHudCommentary::PanelAnimationVar_m_iSpeakersX::InitVar();
  CHudCommentary::PanelAnimationVar_m_iSpeakersY::InitVar();
  CHudCommentary::PanelAnimationVar_m_iCountXFR::InitVar();
  CHudCommentary::PanelAnimationVar_m_iCountY::InitVar();
  CHudCommentary::PanelAnimationVar_m_iIconX::InitVar();
  CHudCommentary::PanelAnimationVar_m_iIconY::InitVar();
  CHudCommentary::PanelAnimationVar_m_iIconWide::InitVar();
  CHudCommentary::PanelAnimationVar_m_iIconTall::InitVar();
  CHudCommentary::PanelAnimationVar_m_nIconTextureId::InitVar();
  CHudCommentary::PanelAnimationVar_m_bUseScriptBGColor::InitVar();
  CHudCommentary::PanelAnimationVar_m_BackgroundColor::InitVar();
  this->m_BackgroundColor = 0;
  CHudCommentary::PanelAnimationVar_m_BGOverrideColor::InitVar();
  this->m_BGOverrideColor = 0;
  ClientMode = GetClientMode();
  v7 = ClientMode->GetViewport(this: ClientMode);
  vgui::Panel::SetParent(this: &this->vgui::Panel, newParent: v7);
  vgui::Panel::SetPaintBorderEnabled(this: &this->vgui::Panel, state: false);
  CTraceFilterSkipTwoEntities::SetPassEntity2(
    (CTraceFilterSkipTwoEntities *)this,
    pPassEntity2: (const IHandleEntity *)0x10);
  this->m_hActiveNode.m_Index = -1;
  this->m_bShouldPaint = true;
  this->m_bSoundStarted = false;
  vgui::Panel::SetScheme(this: &this->vgui::Panel, tag: "basemodui_scheme");
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100808E0
// Name: public: virtual char const __near * CHudElement::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CHudElement::GetName(CHudElement *this)
{
  return this->m_pElementName;
}

//------------------------------------------------------------------------------
// Address: 0x100808F0
// Name: public: virtual bool CHudElement::IsActive(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHudElement::IsActive(CHudElement *this)
{
  return this->m_bActive;
}

//------------------------------------------------------------------------------
// Address: 0x10080910
// Name: public: virtual unsigned long vgui::Panel::GetDragFailCursor(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::Panel::GetDragFailCursor(
        vgui::Panel *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msglist)
{
  return 13;
}

//------------------------------------------------------------------------------
// Address: 0x10080930
// Name: public: virtual bool vgui::Panel::IsProportional(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall vgui::Panel::IsProportional(vgui::Panel *this)
{
  return (this->_flags.m_nFlags & 0x1000) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10080940
// Name: public: virtual struct vgui::PanelMessageMap __near * CHudCommentary::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CHudCommentary::GetMessageMap(CHudCommentary *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CHudCommentary::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CHudCommentary::GetMessageMap'::`2'::s_pMap;
  `CHudCommentary::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CHudCommentary");
  `CHudCommentary::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10080970
// Name: public: virtual struct PanelAnimationMap __near * CHudCommentary::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CHudCommentary::GetAnimMap(CHudCommentary *this)
{
  return FindOrAddPanelAnimationMap(className: "CHudCommentary");
}

//------------------------------------------------------------------------------
// Address: 0x10080980
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CHudCommentary::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CHudCommentary::GetKBMap(CHudCommentary *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CHudCommentary::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CHudCommentary::GetKBMap'::`2'::s_pMap;
  `CHudCommentary::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CHudCommentary");
  `CHudCommentary::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100809F0
// Name: public: virtual void CHudCommentary::LevelInit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudCommentary::LevelInit(CHudCommentary *this)
{
  CHandle<C_PointCommentaryNode> *m_pMemory; // eax

  g_CommentaryNodes.m_Size = 0;
  if ( g_CommentaryNodes.m_Memory.m_nGrowSize < 0 )
  {
    g_CommentaryNodes.m_pElements = g_CommentaryNodes.m_Memory.m_pMemory;
  }
  else
  {
    m_pMemory = g_CommentaryNodes.m_Memory.m_pMemory;
    if ( g_CommentaryNodes.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_CommentaryNodes.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      g_CommentaryNodes.m_Memory.m_pMemory = nullptr;
    }
    g_CommentaryNodes.m_Memory.m_nAllocationCount = 0;
    g_CommentaryNodes.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10080A40
// Name: public: virtual void C_PointCommentaryNode::OnRestore(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_PointCommentaryNode::OnRestore(C_PointCommentaryNode *this)
{
  CSoundEnvelopeController *Controller; // eax

  C_BaseEntity::OnRestore(this);
  if ( this->m_bActive )
  {
    if ( this->m_sndCommentary != nullptr )
    {
      Controller = CSoundEnvelopeController::GetController();
      Controller->SoundDestroy(this: Controller, a2: this->m_sndCommentary);
      this->m_sndCommentary = nullptr;
    }
    this->m_bRestartAfterRestore = true;
  }
  C_PointCommentaryNode::AddAndLockCommentaryHudGroup(this);
}

//------------------------------------------------------------------------------
// Address: 0x10080B60
// Name: Create_CHudCommentary
// Source: json
//------------------------------------------------------------------------------
CHudCommentary *__cdecl Create_CHudCommentary()
{
  unsigned __int8 *v0; // esi

  v0 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 1168);
  memset(dst: v0, value: 0, count: 0x490u);
  if ( v0 != nullptr )
    return CHudCommentary::CHudCommentary(this: (CHudCommentary *)v0, name: "CHudCommentary");
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10412ED0
// Name: DT_PointCommentaryNode::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_PointCommentaryNode::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_PointCommentaryNode::g_RecvTable);
  return atexit(func: DT_PointCommentaryNode::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10412EF0
// Name: DT_PointCommentaryNode::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_PointCommentaryNode::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_PointCommentaryNode::ignored>();
  DT_PointCommentaryNode::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10412F00
// Name: C_PointCommentaryNode_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *C_PointCommentaryNode_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<C_PointCommentaryNode>();
  C_PointCommentaryNode_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430850
// Name: DT_PointCommentaryNode::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_PointCommentaryNode::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_PointCommentaryNode::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x1007F390
// Name: _C_PointCommentaryNode_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_PointCommentaryNode_CreateObject(int entnum, int serialNum)
{
  C_BaseAnimating *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_BaseAnimating *)C_BaseEntity::operator new(stAllocateBlock: 0xFE0u);
  v3 = &v2->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_BaseAnimating::C_BaseAnimating(this: v2);
  *v3 = &C_PointCommentaryNode::`vftable'{for `IClientUnknown'};
  v3[1] = &C_PointCommentaryNode::`vftable'{for `IClientRenderable'};
  v3[2] = &C_PointCommentaryNode::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_PointCommentaryNode::`vftable'{for `IClientThinkable'};
  v3[4] = &C_PointCommentaryNode::`vftable';
  v3[1013] = -1;
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x10080A90
// Name: struct datamap_t __near * DataMapInit<class C_PointCommentaryNode>(class C_PointCommentaryNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<C_PointCommentaryNode>()
{
  if ( (_S6_18 & 1) == 0 )
  {
    _S6_18 |= 1u;
    nameHolder_8.m_pszBase = "C_PointCommentaryNode";
    nameHolder_8.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_8.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_8.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_8.m_Names.m_Size = 0;
    nameHolder_8.m_Names.m_pElements = nullptr;
    nameHolder_8.m_nLenBase = 21;
    atexit(func: DataMapInit_C_PointCommentaryNode__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  C_PointCommentaryNode::m_DataMap.baseMap = &C_BaseEntity::m_DataMap;
  if ( (_S6_18 & 2) == 0 )
  {
    _S6_18 |= 2u;
    dataDesc_8[3].pSaveRestoreOps = GetSoundSaveRestoreOps();
    dataDesc_8[3].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_8[3].td = 0;
    *(_QWORD *)&dataDesc_8[3].override_field = 0;
    *(_QWORD *)&dataDesc_8[3].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_8[3].flatOffset[1] = 0;
  }
  C_PointCommentaryNode::m_DataMap.dataNumFields = 3;
  C_PointCommentaryNode::m_DataMap.dataDesc = &dataDesc_8[1];
  return &C_PointCommentaryNode::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10412F10
// Name: _dynamic_initializer_for__g_CHudCommentary_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CHudElementHelper *dynamic_initializer_for__g_CHudCommentary_Helper__()
{
  return CHudElementHelper::CHudElementHelper(
           this: &g_CHudCommentary_Helper,
           pfnCreate: (CHudElement *(__cdecl *)())Create_CHudCommentary,
           depth: 50,
           flags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10412F30
// Name: _dynamic_initializer_for____g_C_PostProcessControllerClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_PostProcessControllerClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_PostProcessControllerClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_PostProcessControllerClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430860
// Name: _dynamic_atexit_destructor_for__g_CommentaryNodes__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CommentaryNodes__()
{
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CommentaryNodes);
}

//------------------------------------------------------------------------------
// Address: 0x10430870
// Name: _DataMapInit_C_PointCommentaryNode__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_C_PointCommentaryNode__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_8);
}
