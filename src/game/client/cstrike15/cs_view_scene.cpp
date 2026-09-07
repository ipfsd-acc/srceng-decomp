// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/cs_view_scene.cpp
// Functions: 12
// ============================================================

#include "game\client\cstrike15\cs_view_scene.h"

//------------------------------------------------------------------------------
// Address: 0x101C9E70
// Name: public: virtual void PrecacheCSViewScenePrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PrecacheCSViewScenePrecache::CResourcePrecacher::Cache(
        PrecacheCSViewScenePrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "effects/flashbang",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "effects/flashbang_white",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "effects/nightvision",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101C9EC0
// Name: class IViewRender __near * GetViewRenderInstance(void)
// Source: json
//------------------------------------------------------------------------------
CCSViewRender *__cdecl GetViewRenderInstance()
{
  return &g_ViewRender;
}

//------------------------------------------------------------------------------
// Address: 0x101C9ED0
// Name: public: virtual void CCSViewRender::Init(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CCSViewRender::Init(CCSViewRender *this)
{
  CViewRender::Init(this);
}

//------------------------------------------------------------------------------
// Address: 0x101C9EE0
// Name: public: virtual void CCSViewRender::RenderPlayerSprites(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSViewRender::RenderPlayerSprites(CCSViewRender *this)
{
  CRadioStatus *v1; // eax

  CViewRender::RenderPlayerSprites(this);
  v1 = RadioManager();
  CRadioStatus::DrawHeadLabels(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x101C9F00
// Name: float clamp<float,int,class CNetworkVarBase<float,class C_CSPlayer::NetworkVar_m_flFlashMaxAlpha>>(float const __near &,int const __near &,class CNetworkVarBase<float,class C_CSPlayer::NetworkVar_m_flFlashMaxAlpha> const __near &)
// Source: json
//------------------------------------------------------------------------------
double __cdecl clamp<float,int,CNetworkVarBase<float,C_CSPlayer::NetworkVar_m_flFlashMaxAlpha>>(
        float *val,
        const int *minVal,
        const CNetworkVarBase<float,C_CSPlayer::NetworkVar_m_flFlashMaxAlpha> *maxVal)
{
  float v3; // xmm1_4
  float vala; // [esp+8h] [ebp+8h]

  v3 = (float)*minVal;
  vala = *val;
  if ( v3 > vala )
    return v3;
  if ( vala <= maxVal->m_Value )
    return vala;
  return maxVal->m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x101C9F50
// Name: private: void CCSViewRender::PerformNightVisionEffect(class CViewSetup const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CCSViewRender::PerformNightVisionEffect(
        CCSViewRender *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        const CViewSetup *view)
{
  C_CSPlayer *LocalPlayer; // esi
  int v5; // edi
  IMaterial *v6; // edi
  float m_flNightVisionAlpha; // xmm0_4
  float v8; // xmm0_4
  int v9; // xmm1_4
  bool v10; // cc
  IMatRenderContext *v11; // esi
  __int64 v12; // [esp-20h] [ebp-28h]
  __int64 v13; // [esp-18h] [ebp-20h]
  unsigned __int8 overlaycolor[4]; // [esp+4h] [ebp-4h] BYREF

  LocalPlayer = CClientTools::GetLocalPlayer();
  if ( LocalPlayer != nullptr )
  {
    if ( LocalPlayer->GetObserverMode(this: LocalPlayer) == 4 )
    {
      v5 = (int)LocalPlayer->GetObserverTarget(this: LocalPlayer);
      if ( v5 != 0 && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 584))(a1: v5) != 0 )
        LocalPlayer = (C_CSPlayer *)v5;
    }
    if ( LocalPlayer->m_flNightVisionAlpha > 0.0 )
    {
      v6 = materials->FindMaterial(
             this: materials,
             a2: "effects/nightvision",
             a3: "ClientEffect textures",
             a4: 1,
             a5: 0);
      if ( v6 != nullptr )
      {
        v13 = *(_QWORD *)&view->width;
        v12 = *(_QWORD *)&view->x;
        *(_DWORD *)overlaycolor = -16711936;
        UpdateScreenEffectTexture(
          a1: a2,
          a2: (int)LocalPlayer,
          textureIndex: 0,
          x: v12,
          w: v13,
          bDestFullScreen: false,
          pActualRect: nullptr);
        m_flNightVisionAlpha = LocalPlayer->m_flNightVisionAlpha;
        if ( LocalPlayer->m_bNightVisionOn.m_Value )
        {
          v8 = m_flNightVisionAlpha + 15.0;
          v9 = 1132396544;
          v10 = v8 >= 255.0;
        }
        else
        {
          v8 = m_flNightVisionAlpha - 40.0;
          v9 = 0;
          v10 = v8 <= 0.0;
        }
        LocalPlayer->m_flNightVisionAlpha = v8;
        if ( v10 )
          v8 = *(float *)&v9;
        LocalPlayer->m_flNightVisionAlpha = v8;
        overlaycolor[3] = (int)v8;
        ((void (__thiscall *)(IVRenderView *, unsigned __int8 *, IMaterial *, int, int))render->ViewDrawFade)(
          a1: render,
          a2: overlaycolor,
          a3: v6,
          a4: a2,
          a5: a3);
        v11 = materials->GetRenderContext(this: materials);
        if ( v11 != nullptr )
          v11->BeginRender(this: v11);
        v11->DrawScreenSpaceQuad(this: v11, a2: v6);
        ((void (__thiscall *)(IVRenderView *, unsigned __int8 *))render->ViewDrawFade)(a1: render, a2: overlaycolor);
        v11->DrawScreenSpaceQuad(this: v11, a2: v6);
        v11->EndRender(this: v11);
        v11->Release(this: v11);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CA0D0
// Name: private: void CCSViewRender::PerformFlashbangEffect(class CViewSetup const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CCSViewRender::PerformFlashbangEffect(
        CCSViewRender *this@<ecx>,
        int a2@<ebx>,
        int a3@<esi>,
        const CViewSetup *view)
{
  C_CSPlayer *LocalPlayer; // edi
  IMaterial *v5; // ebx
  int v6; // eax
  int v7; // esi
  float m_flFlashAlpha; // xmm0_4
  float m_Value; // xmm1_4
  float v10; // xmm0_4
  int v11; // eax
  const CViewSetup *v12; // edi
  int y; // edx
  ITexture *m_pFlashTexture; // ecx
  int v15; // eax
  int (__thiscall *GetActualHeight)(ITexture *); // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // ecx
  int v21; // eax
  int (__thiscall *v22)(ITexture *); // eax
  int v23; // eax
  int v24; // eax
  int v25; // eax
  int v26; // ecx
  int v27; // eax
  int height; // ecx
  const CViewSetup *v29; // edx
  ITexture *v30; // edi
  int v31; // eax
  int v32; // eax
  int v33; // eax
  int v34; // eax
  int (__thiscall *v35)(ITexture *); // eax
  int v36; // eax
  int v37; // eax
  int v38; // eax
  int v39; // ecx
  int v40; // eax
  int v41; // ecx
  IMaterial *v42; // eax
  float v43; // xmm0_4
  float v44; // xmm2_4
  float v45; // xmm0_4
  float v46; // xmm1_4
  Rect_t srcRect; // [esp+B0h] [ebp-28h] BYREF
  int minVal; // [esp+C0h] [ebp-18h] BYREF
  C_CSPlayer *pPlayer; // [esp+C4h] [ebp-14h]
  CCSViewRender *v51; // [esp+C8h] [ebp-10h]
  float flAlpha; // [esp+CCh] [ebp-Ch] BYREF
  unsigned __int8 overlaycolor[7]; // [esp+D0h] [ebp-8h] BYREF
  bool foundVar; // [esp+D7h] [ebp-1h] BYREF
  const CViewSetup *viewa; // [esp+E0h] [ebp+8h]
  const CViewSetup *viewb; // [esp+E0h] [ebp+8h]
  const CViewSetup *viewc; // [esp+E0h] [ebp+8h]

  v51 = this;
  LocalPlayer = CClientTools::GetLocalPlayer();
  pPlayer = LocalPlayer;
  if ( LocalPlayer == nullptr )
    return;
  if ( *(float *)(gpGlobals.m_Index + 12) > LocalPlayer->m_flFlashBangTime )
    return;
  v5 = materials->FindMaterial(this: materials, a2: "effects/flashbang", a3: "ClientEffect textures", a4: 1, a5: 0);
  if ( v5 == nullptr )
    return;
  *(_DWORD *)overlaycolor = -1;
  v6 = ((int (__thiscall *)(IMaterialSystem *, int, int))materials->GetRenderContext)(a1: materials, a2: a3, a3: a2);
  v7 = v6;
  if ( v6 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 8))(a1: v6);
  m_flFlashAlpha = LocalPlayer->m_flFlashAlpha;
  m_Value = LocalPlayer->m_flFlashMaxAlpha.m_Value;
  if ( m_Value > m_flFlashAlpha )
  {
    v10 = m_flFlashAlpha + 45.0;
    LocalPlayer->m_flFlashAlpha = v10;
    if ( m_Value <= v10 )
      v10 = m_Value;
    LocalPlayer->m_flFlashAlpha = v10;
    overlaycolor[2] = (int)v10;
    overlaycolor[1] = overlaycolor[2];
    overlaycolor[0] = overlaycolor[2];
    v51->m_pFlashTexture = GetFullFrameFrameBufferTexture(textureIndex: 1);
    v11 = (int)v5->FindVar(this: v5, a2: "$basetexture", a3: &foundVar, a4: false);
    v12 = view;
    y = view->y;
    srcRect.x = view->x;
    srcRect.width = view->width;
    m_pFlashTexture = v51->m_pFlashTexture;
    srcRect.y = y;
    srcRect.height = view->height;
    (*(void (__thiscall **)(int, ITexture *))(*(_DWORD *)v11 + 60))(a1: v11, a2: m_pFlashTexture);
    v15 = *(_DWORD *)v7;
    srcRect.height = 0;
    srcRect.width = (int)&srcRect;
    (*(void (__thiscall **)(int, ITexture *, _DWORD))(v15 + 452))(a1: v7, a2: v51->m_pFlashTexture, a3: 0);
    (*(void (__thiscall **)(int, ITexture *, _DWORD))(*(_DWORD *)v7 + 72))(a1: v7, a2: v51->m_pFlashTexture, a3: 0);
    render->ViewDrawFade(this: render, a2: overlaycolor, a3: v5);
    viewa = (const CViewSetup *)(*(_DWORD *)v7 + 420);
    GetActualHeight = v51->m_pFlashTexture->GetActualHeight;
    flAlpha = *(float *)&v51->m_pFlashTexture;
    v17 = ((int (__stdcall *)(_DWORD, int, int))GetActualHeight)(a1: 0, a2: 1, a3: 1);
    v18 = (*(int (__thiscall **)(float, int))(*(_DWORD *)LODWORD(flAlpha) + 12))(
            a1: COERCE_FLOAT(LODWORD(flAlpha)),
            a2: v17);
    v19 = (*(int (__thiscall **)(float, int))(*(_DWORD *)LODWORD(flAlpha) + 16))(
            a1: COERCE_FLOAT(LODWORD(flAlpha)),
            a2: v18);
    srcRect.height = v20;
    v21 = (*(int (__thiscall **)(float, float))(*(_DWORD *)LODWORD(flAlpha) + 12))(
            a1: COERCE_FLOAT(LODWORD(flAlpha)),
            a2: (float)(v19 - 1));
    ((void (__thiscall *)(int, IMaterial *, int, int, int, int, _DWORD, _DWORD, float))viewa->x)(
      a1: v7,
      a2: v5,
      a3: v12->x,
      a4: v12->y,
      a5: v12->width,
      a6: v12->height,
      a7: 0,
      a8: 0,
      a9: (float)(v21 - 1));
    render->ViewDrawFade(this: render, a2: overlaycolor, a3: v5);
    viewb = (const CViewSetup *)(*(_DWORD *)v7 + 420);
    v22 = v51->m_pFlashTexture->GetActualHeight;
    flAlpha = *(float *)&v51->m_pFlashTexture;
    v23 = ((int (__stdcall *)(_DWORD, int, int))v22)(a1: 0, a2: 1, a3: 1);
    v24 = (*(int (__thiscall **)(float, int))(*(_DWORD *)LODWORD(flAlpha) + 12))(
            a1: COERCE_FLOAT(LODWORD(flAlpha)),
            a2: v23);
    v25 = (*(int (__thiscall **)(float, int))(*(_DWORD *)LODWORD(flAlpha) + 16))(
            a1: COERCE_FLOAT(LODWORD(flAlpha)),
            a2: v24);
    srcRect.height = v26;
    v27 = (*(int (__thiscall **)(float, float))(*(_DWORD *)LODWORD(flAlpha) + 12))(
            a1: COERCE_FLOAT(LODWORD(flAlpha)),
            a2: (float)(v25 - 1));
    height = v12->height;
    *(float *)&srcRect.height = (float)(v27 - 1);
    srcRect.width = 0;
    srcRect.y = 0;
    srcRect.x = height;
    v29 = viewb;
    goto LABEL_12;
  }
  if ( v51->m_pFlashTexture != nullptr )
  {
    flAlpha = (float)((float)(LocalPlayer->m_flFlashBangTime - *(float *)(gpGlobals.m_Index + 12)) * m_Value)
            / LocalPlayer->m_flFlashDuration.m_Value;
    minVal = 0;
    flAlpha = clamp<float,int,CNetworkVarBase<float,C_CSPlayer::NetworkVar_m_flFlashMaxAlpha>>(
                val: &flAlpha,
                &minVal,
                maxVal: &LocalPlayer->m_flFlashMaxAlpha);
    overlaycolor[2] = (int)flAlpha;
    overlaycolor[1] = overlaycolor[2];
    overlaycolor[0] = overlaycolor[2];
    render->ViewDrawFade(this: render, a2: overlaycolor, a3: v5);
    minVal = *(_DWORD *)v7 + 420;
    v30 = v51->m_pFlashTexture;
    v31 = ((int (__thiscall *)(ITexture *, _DWORD, int, int))v30->GetActualHeight)(a1: v30, a2: 0, a3: 1, a4: 1);
    v32 = ((int (__thiscall *)(ITexture *, int))v30->GetActualWidth)(a1: v30, a2: v31);
    v33 = ((int (__thiscall *)(ITexture *, int))v30->GetActualHeight)(a1: v30, a2: v32);
    v34 = ((int (__thiscall *)(ITexture *, float))v30->GetActualWidth)(a1: v30, a2: (float)(v33 - 1));
    v12 = view;
    (*(void (__thiscall **)(int, IMaterial *, int, int, int, int, _DWORD, _DWORD, float))minVal)(
      a1: v7,
      a2: v5,
      a3: view->x,
      a4: view->y,
      a5: view->width,
      a6: view->height,
      a7: 0,
      a8: 0,
      a9: (float)(v34 - 1));
    render->ViewDrawFade(this: render, a2: overlaycolor, a3: v5);
    viewc = (const CViewSetup *)(*(_DWORD *)v7 + 420);
    v35 = v51->m_pFlashTexture->GetActualHeight;
    flAlpha = *(float *)&v51->m_pFlashTexture;
    v36 = ((int (__stdcall *)(_DWORD, int, int))v35)(a1: 0, a2: 1, a3: 1);
    v37 = (*(int (__thiscall **)(float, int))(*(_DWORD *)LODWORD(flAlpha) + 12))(
            a1: COERCE_FLOAT(LODWORD(flAlpha)),
            a2: v36);
    v38 = (*(int (__thiscall **)(float, int))(*(_DWORD *)LODWORD(flAlpha) + 16))(
            a1: COERCE_FLOAT(LODWORD(flAlpha)),
            a2: v37);
    srcRect.height = v39;
    v40 = (*(int (__thiscall **)(float, float))(*(_DWORD *)LODWORD(flAlpha) + 12))(
            a1: COERCE_FLOAT(LODWORD(flAlpha)),
            a2: (float)(v38 - 1));
    v41 = v12->height;
    *(float *)&srcRect.height = (float)(v40 - 1);
    srcRect.width = 0;
    srcRect.y = 0;
    srcRect.x = v41;
    v29 = viewc;
LABEL_12:
    ((void (__thiscall *)(int, IMaterial *, int, int))v29->x)(a1: v7, a2: v5, a3: v12->x, a4: v12->y);
    LocalPlayer = pPlayer;
  }
  v42 = (IMaterial *)((int (__thiscall *)(IMaterialSystem *, const char *, const char *))materials->FindMaterial)(
                       a1: materials,
                       a2: "effects/flashbang_white",
                       a3: "ClientEffect textures");
  if ( v42 == nullptr )
  {
    if ( v7 == 0 )
      return;
    goto LABEL_25;
  }
  v43 = LocalPlayer->m_flFlashAlpha;
  v44 = LocalPlayer->m_flFlashMaxAlpha.m_Value;
  if ( v44 <= v43 )
  {
    v45 = LocalPlayer->m_flFlashBangTime - *(float *)(gpGlobals.m_Index + 12);
    if ( v45 <= 3.0 )
      v46 = (float)(v45 * 0.33333334) * (float)(v45 * 0.33333334);
    else
      v46 = 1.0;
    v43 = v44 * v46;
    if ( (float)(v44 * v46) <= 0.0 )
      v43 = 0.0;
    if ( v44 <= v43 )
      v43 = LocalPlayer->m_flFlashMaxAlpha.m_Value;
  }
  overlaycolor[2] = (int)v43;
  overlaycolor[1] = overlaycolor[2];
  overlaycolor[0] = overlaycolor[2];
  render->ViewDrawFade(this: render, a2: overlaycolor, a3: v42);
  if ( v7 != 0 )
  {
LABEL_25:
    (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 12))(a1: v7);
    (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 4))(a1: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CA5D0
// Name: public: virtual void CCSViewRender::Render2DEffectsPreHUD(class CViewSetup const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CCSViewRender::Render2DEffectsPreHUD(
        CCSViewRender *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        const CViewSetup *view)
{
  CCSViewRender::PerformNightVisionEffect(this, a2, a3, view);
}

//------------------------------------------------------------------------------
// Address: 0x101CA5E0
// Name: public: virtual void CCSViewRender::Render2DEffectsPostHUD(class CViewSetup const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CCSViewRender::Render2DEffectsPostHUD(
        CCSViewRender *this@<ecx>,
        int a2@<ebx>,
        int a3@<esi>,
        const CViewSetup *view)
{
  CCSViewRender::PerformFlashbangEffect(this, a2, a3, view);
}

//------------------------------------------------------------------------------
// Address: 0x10423570
// Name: PrecacheCSViewScenePrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
CBaseResourcePrecacher *PrecacheCSViewScenePrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  CBaseResourcePrecacher *result; // eax

  result = CBaseResourcePrecacher::sm_pFirst[0];
  PrecacheCSViewScenePrecache::s_ResourcePrecacher.m_pNext = CBaseResourcePrecacher::sm_pFirst[0];
  CBaseResourcePrecacher::sm_pFirst[0] = &PrecacheCSViewScenePrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10423590
// Name: _dynamic_initializer_for__g_ViewRender__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ViewRender__()
{
  CViewRender::CViewRender(this: &g_ViewRender);
  g_ViewRender.__vftable = (CCSViewRender_vtbl *)&CCSViewRender::`vftable';
  g_ViewRender.m_pFlashTexture = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__g_ViewRender__);
}

//------------------------------------------------------------------------------
// Address: 0x104235C0
// Name: _dynamic_initializer_for__g_EquipmentInfo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
FileWeaponInfo_t *dynamic_initializer_for__g_EquipmentInfo__()
{
  FileWeaponInfo_t *v0; // esi
  int i; // edi
  FileWeaponInfo_t *result; // eax

  v0 = &g_EquipmentInfo;
  for ( i = 2; i >= 0; --i )
  {
    result = FileWeaponInfo_t::FileWeaponInfo_t(this: v0);
    v0->__vftable = (FileWeaponInfo_t_vtbl *)&CCSWeaponInfo::`vftable';
    v0[1].__vftable = (FileWeaponInfo_t_vtbl *)1065353216;
    v0[1].szPrintName[59] = 0;
    v0 = (FileWeaponInfo_t *)((char *)v0 + 2840);
  }
  return result;
}
