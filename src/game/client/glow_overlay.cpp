// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/glow_overlay.cpp
// Functions: 22
// ============================================================

#include "game\client\glow_overlay.h"

//------------------------------------------------------------------------------
// Address: 0x100424D0
// Name: void BuildingCubemapsChanged(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __usercall BuildingCubemapsChanged(int a1@<edi>)
{
  C_BaseEntity::UpdateVisibilityAllEntities(a1);
}

//------------------------------------------------------------------------------
// Address: 0x100EAB50
// Name: public: virtual void PrecacheEffectGlowPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PrecacheEffectGlowPrecache::CResourcePrecacher::Cache(
        PrecacheEffectGlowPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "sun/overlay",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "sprites/light_glow02_add_noz",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100EAB90
// Name: public: void CGlowOverlay::Deactivate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGlowOverlay::Deactivate(CGlowOverlay *this)
{
  this->m_bActivated = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100EABA0
// Name: protected: virtual void CGlowOverlay::CalcBasis(class Vector const __near &,float,float,class Vector __near &,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGlowOverlay::CalcBasis(
        CGlowOverlay *this,
        const Vector *vToGlow,
        float flHorzSize,
        float flVertSize,
        Vector *vBasePt,
        Vector *vUp,
        Vector *vRight)
{
  const Vector *v8; // eax
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v12; // xmm0_4
  float v13; // xmm4_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // [esp+0h] [ebp-Ch]
  float v19; // [esp+4h] [ebp-8h]
  float v20; // [esp+8h] [ebp-4h]

  v18 = vToGlow->x * 100.0;
  v19 = vToGlow->y * 100.0;
  v20 = vToGlow->z * 100.0;
  v8 = CurrentViewOrigin();
  v9 = v8->y + v19;
  v10 = v8->z + v20;
  vBasePt->x = v8->x + v18;
  vBasePt->y = v9;
  vBasePt->z = v10;
  vUp->z = 1.0;
  vUp->x = 0.0;
  vUp->y = 0.0;
  v12 = vToGlow->z * 0.0;
  v13 = vToGlow->y - v12;
  v14 = v12 - vToGlow->x;
  v15 = (float)(vToGlow->x * 0.0) - (float)(vToGlow->y * 0.0);
  vRight->x = v13;
  vRight->y = v14;
  vRight->z = v15;
  VectorNormalize(vec: vRight);
  v16 = (float)(vRight->z * vToGlow->x) - (float)(vRight->x * vToGlow->z);
  v17 = (float)(vRight->x * vToGlow->y) - (float)(vRight->y * vToGlow->x);
  vUp->x = (float)(vRight->y * vToGlow->z) - (float)(vRight->z * vToGlow->y);
  vUp->y = v16;
  vUp->z = v17;
  VectorNormalize(vec: vUp);
  vRight->x = vRight->x * flHorzSize;
  vRight->y = vRight->y * flHorzSize;
  vRight->z = vRight->z * flHorzSize;
  vUp->x = vUp->x * flVertSize;
  vUp->y = flVertSize * vUp->y;
  vUp->z = vUp->z * flVertSize;
}

//------------------------------------------------------------------------------
// Address: 0x100EAD30
// Name: public: CGlowOverlay::CGlowOverlay(void)
// Source: json
//------------------------------------------------------------------------------
CGlowOverlay *__thiscall CGlowOverlay::CGlowOverlay(CGlowOverlay *this)
{
  this->__vftable = (CGlowOverlay_vtbl *)&CGlowOverlay::`vftable';
  this->m_flGlowObstructionScale = 0.0;
  this->m_skyObstructionScale = 1.0;
  this->m_flProxyRadius = 2.0;
  this->m_flHDRColorScale = 1.0;
  this->m_ListIndex = -1;
  this->m_nSprites = 0;
  this->m_bDirectional = false;
  this->m_bInSky = false;
  this->m_queryHandle = 0;
  this->m_bActivated = 0;
  this->m_Sprites[0].m_vColor.x = 0.0;
  this->m_Sprites[0].m_vColor.y = 0.0;
  this->m_Sprites[0].m_vColor.z = 0.0;
  this->m_Sprites[0].m_flHorzSize = 1.0;
  this->m_Sprites[0].m_flVertSize = 1.0;
  this->m_Sprites[0].m_pMaterial = nullptr;
  this->m_Sprites[1].m_vColor.x = 0.0;
  this->m_Sprites[1].m_vColor.y = 0.0;
  this->m_Sprites[1].m_vColor.z = 0.0;
  this->m_Sprites[1].m_flHorzSize = 1.0;
  this->m_Sprites[1].m_flVertSize = 1.0;
  this->m_Sprites[1].m_pMaterial = nullptr;
  this->m_Sprites[2].m_vColor.x = 0.0;
  this->m_Sprites[2].m_vColor.y = 0.0;
  this->m_Sprites[2].m_vColor.z = 0.0;
  this->m_Sprites[2].m_flHorzSize = 1.0;
  this->m_Sprites[2].m_flVertSize = 1.0;
  this->m_Sprites[2].m_pMaterial = nullptr;
  this->m_Sprites[3].m_vColor.x = 0.0;
  this->m_Sprites[3].m_vColor.y = 0.0;
  this->m_Sprites[3].m_vColor.z = 0.0;
  this->m_Sprites[3].m_flHorzSize = 1.0;
  this->m_Sprites[3].m_flVertSize = 1.0;
  this->m_Sprites[3].m_pMaterial = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100EAE10
// Name: protected: void CGlowOverlay::UpdateSkyGlowObstruction(float,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGlowOverlay::UpdateSkyGlowObstruction(CGlowOverlay *this, float zFar, bool bCacheFullSceneState)
{
  float v4; // xmm1_4
  float v5; // xmm2_4
  const Vector *v6; // eax
  float v7; // xmm1_4
  float v8; // xmm2_4
  const Vector *v9; // eax
  const Vector *v10; // eax
  CGameTrace trace; // [esp+4h] [ebp-88h] BYREF
  pixelvis_queryparams_t params; // [esp+58h] [ebp-34h] BYREF
  Vector vecAbsEnd; // [esp+74h] [ebp-18h] BYREF
  float v14; // [esp+80h] [ebp-Ch]
  float v15; // [esp+84h] [ebp-8h]
  float v16; // [esp+88h] [ebp-4h]
  IHandleEntity savedregs; // [esp+8Ch] [ebp+0h] BYREF

  if ( bCacheFullSceneState )
  {
    if ( this->m_bCacheSkyObstruction )
      return;
    this->m_bCacheSkyObstruction = true;
  }
  else if ( this->m_bCacheSkyObstruction )
  {
    this->m_bCacheSkyObstruction = false;
  }
  if ( PixelVisibility_IsAvailable() )
  {
    v4 = (float)(this->m_vDirection.y * zFar) * 0.99900001;
    v5 = (float)(this->m_vDirection.z * zFar) * 0.99900001;
    v14 = (float)(zFar * this->m_vDirection.x) * 0.99900001;
    v15 = v4;
    v16 = v5;
    v6 = CurrentViewOrigin();
    v7 = v6->y + v4;
    v8 = v6->z + v5;
    params.position.x = v6->x + v14;
    params.proxySize = this->m_flProxyRadius;
    params.proxyAspect = 1.0;
    params.position.y = v7;
    params.position.z = v8;
    params.fadeTime = 0.0625;
    *(_WORD *)&params.bSetup = 257;
    this->m_skyObstructionScale = PixelVisibility_FractionVisible(&params, queryHandle: &this->m_queryHandle);
  }
  else
  {
    v14 = this->m_vDirection.x * 56755.84;
    v15 = this->m_vDirection.y * 56755.84;
    v16 = this->m_vDirection.z * 56755.84;
    v9 = CurrentViewOrigin();
    vecAbsEnd.x = v9->x + v14;
    vecAbsEnd.y = v9->y + v15;
    vecAbsEnd.z = v9->z + v16;
    v10 = CurrentViewOrigin();
    UTIL_TraceLine(
      a1: &savedregs,
      a2: (int)this,
      vecAbsStart: v10,
      &vecAbsEnd,
      mask: 1u,
      ignore: nullptr,
      collisionGroup: 0,
      ptr: &trace);
    if ( (trace.surface.flags & 4) != 0 )
      this->m_skyObstructionScale = 1.0;
    else
      this->m_skyObstructionScale = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EAFC0
// Name: protected: void CGlowOverlay::UpdateGlowObstruction(class Vector const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGlowOverlay::UpdateGlowObstruction(
        CGlowOverlay *this,
        const Vector *vToGlow,
        bool bCacheFullSceneState)
{
  float v4; // xmm0_4
  const Vector *v5; // eax
  float v6; // xmm1_4
  float v7; // xmm2_4
  float m_flHorzSize; // xmm3_4
  float m_flVertSize; // xmm4_4
  float v10; // xmm3_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  float m_flProxyRadius; // xmm1_4
  const Vector *v15; // eax
  const Vector *v16; // eax
  int v17; // xmm1_4
  float v18; // xmm0_4
  bool v19; // cc
  CGameTrace trace; // [esp+4h] [ebp-88h] BYREF
  Vector vecAbsEnd; // [esp+58h] [ebp-34h] BYREF
  pixelvis_queryparams_t params; // [esp+64h] [ebp-28h] BYREF
  float v23; // [esp+80h] [ebp-Ch]
  float v24; // [esp+84h] [ebp-8h]
  float v25; // [esp+88h] [ebp-4h]
  IHandleEntity savedregs; // [esp+8Ch] [ebp+0h] BYREF

  if ( bCacheFullSceneState )
  {
    if ( this->m_bCacheGlowObstruction )
      return;
    this->m_bCacheGlowObstruction = true;
  }
  else if ( this->m_bCacheGlowObstruction )
  {
    this->m_bCacheGlowObstruction = false;
  }
  if ( PixelVisibility_IsAvailable() )
  {
    if ( this->m_bInSky )
    {
      v4 = view->GetViewSetup(this: view)->zFar * 0.99900001;
      v23 = this->m_vDirection.x * v4;
      v24 = this->m_vDirection.y * v4;
      v25 = this->m_vDirection.z * v4;
      v5 = CurrentViewOrigin();
      v6 = v5->y + v24;
      v7 = v5->z + v25;
      if ( this->m_nSprites == 0
        || (m_flHorzSize = this->m_Sprites[0].m_flHorzSize) == 0.0
        || (m_flVertSize = this->m_Sprites[0].m_flVertSize) == 0.0 )
      {
        v10 = 1.0;
      }
      else
      {
        v10 = m_flHorzSize / m_flVertSize;
      }
      params.position.x = v5->x + v23;
      params.proxySize = this->m_flProxyRadius;
      params.position.y = v6;
      params.position.z = v7;
      params.proxyAspect = v10;
      params.fadeTime = 0.0625;
      *(_WORD *)&params.bSetup = 257;
      this->m_flGlowObstructionScale = PixelVisibility_FractionVisible(&params, queryHandle: &this->m_queryHandle)
                                     * this->m_skyObstructionScale;
    }
    else
    {
      if ( this->m_nSprites == 0
        || (v11 = this->m_Sprites[0].m_flHorzSize) == 0.0
        || (v12 = this->m_Sprites[0].m_flVertSize) == 0.0 )
      {
        v13 = 1.0;
      }
      else
      {
        v13 = v11 / v12;
      }
      params.position = this->m_vPos;
      m_flProxyRadius = this->m_flProxyRadius;
      params.proxyAspect = v13;
      params.proxySize = m_flProxyRadius;
      params.fadeTime = 0.0625;
      *(_WORD *)&params.bSetup = 1;
      this->m_flGlowObstructionScale = PixelVisibility_FractionVisible(&params, queryHandle: &this->m_queryHandle);
    }
    return;
  }
  if ( this->m_bInSky )
  {
    v23 = vToGlow->x * 56755.84;
    v24 = vToGlow->y * 56755.84;
    v25 = vToGlow->z * 56755.84;
    v15 = CurrentViewOrigin();
    vecAbsEnd.x = v15->x + v23;
    vecAbsEnd.y = v15->y + v24;
    vecAbsEnd.z = v15->z + v25;
    v16 = CurrentViewOrigin();
    UTIL_TraceLine(
      a1: &savedregs,
      a2: (int)this,
      vecAbsStart: v16,
      &vecAbsEnd,
      mask: 1u,
      ignore: nullptr,
      collisionGroup: 0,
      ptr: &trace);
    *(float *)&v17 = 1.0;
    if ( trace.fraction >= 1.0 || (trace.surface.flags & 4) != 0 )
      goto LABEL_30;
  }
  else
  {
    params.position = this->m_vPos;
    params.proxySize = this->m_flProxyRadius;
    params.proxyAspect = 1.0;
    params.fadeTime = 0.0625;
    *(_WORD *)&params.bSetup = 1;
    if ( PixelVisibility_FractionVisible(&params, queryHandle: &this->m_queryHandle) >= 1.0 )
    {
      *(float *)&v17 = 1.0;
LABEL_30:
      if ( building_cubemaps.m_pParent != nullptr && building_cubemaps.m_pParent->m_Value.m_nValue != 0 )
      {
        this->m_flGlowObstructionScale = 1.0;
        return;
      }
      v18 = (float)(*(float *)(gpGlobals.m_Index + 16) / cl_sun_decay_rate.m_pParent->m_Value.m_fValue)
          + this->m_flGlowObstructionScale;
      v19 = v18 >= 1.0;
      goto LABEL_34;
    }
  }
  if ( building_cubemaps.m_pParent != nullptr && building_cubemaps.m_pParent->m_Value.m_nValue != 0 )
  {
    this->m_flGlowObstructionScale = 0.0;
    return;
  }
  v18 = this->m_flGlowObstructionScale
      - (float)(*(float *)(gpGlobals.m_Index + 16) / cl_sun_decay_rate.m_pParent->m_Value.m_fValue);
  *(float *)&v17 = 0.0;
  v19 = v18 <= 0.0;
LABEL_34:
  this->m_flGlowObstructionScale = v18;
  if ( v19 )
    v18 = *(float *)&v17;
  this->m_flGlowObstructionScale = v18;
}

//------------------------------------------------------------------------------
// Address: 0x100EB360
// Name: protected: virtual void CGlowOverlay::CalcSpriteColorAndSize(float,class CGlowSprite __near *,float __near *,float __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGlowOverlay::CalcSpriteColorAndSize(
        CGlowOverlay *this,
        float flDot,
        CGlowSprite *pSprite,
        float *flHorzSize,
        float *flVertSize,
        Vector *vColor)
{
  float m_flHorzSize; // xmm2_4
  float v7; // xmm3_4
  float v8; // xmm0_4
  float v9; // xmm2_4
  float v10; // xmm1_4
  float m_flVertSize; // xmm3_4
  float v12; // xmm1_4
  float v13; // xmm3_4
  float v14; // xmm2_4
  float v15; // xmm4_4
  float v16; // xmm1_4
  float v17; // xmm2_4
  float v18; // xmm3_4

  m_flHorzSize = pSprite->m_flHorzSize;
  v7 = m_flHorzSize * 70.0;
  v8 = 1.0;
  v9 = m_flHorzSize * 150.0;
  if ( g_flOverlayRange != 1.0 )
  {
    v10 = (float)(flDot - g_flOverlayRange) / (float)(1.0 - g_flOverlayRange);
    if ( v10 >= 0.0 )
    {
      if ( v10 > 1.0 )
        v10 = 1.0;
    }
    else
    {
      v10 = 0.0;
    }
    v7 = (float)((float)(v7 - v9) * v10) + v9;
    goto LABEL_9;
  }
  if ( (float)(flDot - 1.0) >= 0.0 )
LABEL_9:
    v9 = v7;
  *flHorzSize = v9;
  m_flVertSize = pSprite->m_flVertSize;
  v12 = m_flVertSize * 70.0;
  v13 = m_flVertSize * 150.0;
  if ( g_flOverlayRange == 1.0 )
  {
    if ( (float)(flDot - 1.0) < 0.0 )
      v12 = v13;
  }
  else
  {
    v14 = (float)(flDot - g_flOverlayRange) / (float)(1.0 - g_flOverlayRange);
    if ( v14 >= 0.0 )
    {
      if ( v14 > 1.0 )
        v14 = 1.0;
    }
    else
    {
      v14 = 0.0;
    }
    v12 = (float)((float)(v12 - v13) * v14) + v13;
  }
  *flVertSize = v12;
  if ( g_flOverlayRange == 1.0 )
  {
    if ( (float)(flDot - 1.0) < 0.0 )
LABEL_20:
      v8 = 0.0;
  }
  else
  {
    v15 = (float)(flDot - g_flOverlayRange) / (float)(1.0 - g_flOverlayRange);
    if ( v15 < 0.0 )
      goto LABEL_20;
    if ( v15 <= 1.0 )
      v8 = (float)(flDot - g_flOverlayRange) / (float)(1.0 - g_flOverlayRange);
  }
  v16 = this->m_flGlowObstructionScale * v8;
  v17 = pSprite->m_vColor.y * v16;
  v18 = pSprite->m_vColor.z * v16;
  vColor->x = pSprite->m_vColor.x * v16;
  vColor->y = v17;
  vColor->z = v18;
}

//------------------------------------------------------------------------------
// Address: 0x100EB650
// Name: protected: virtual void CGlowOverlay::Draw(bool)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CGlowOverlay::Draw(
        CGlowOverlay *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        bool bCacheFullSceneState)
{
  const Vector *v6; // eax
  float v7; // xmm1_4
  int v8; // xmm2_4
  const Vector *v9; // eax
  IMatRenderContext *v10; // edi
  bool v11; // cc
  IMaterial **p_m_pMaterial; // esi
  __int128 radius; // xmm1
  IViewRender_vtbl *v14; // edx
  const VPlane *v15; // eax
  int v16; // eax
  int v17; // ecx
  void (__thiscall *v18)(int, _DWORD); // edx
  IMesh *(__thiscall *GetDynamicMesh)(IMatRenderContext *, bool, IMesh *, IMesh *, IMaterial *); // edx
  IMesh *v20; // esi
  void (__thiscall *SetPrimitiveType)(IMesh *, MaterialPrimitiveType_t); // edx
  void (__thiscall *v22)(_DWORD); // eax
  float v23; // xmm2_4
  float v24; // xmm0_4
  float v25; // xmm1_4
  int v26; // eax
  int v27; // eax
  float v28; // xmm0_4
  float v29; // xmm2_4
  float v30; // xmm1_4
  int v31; // eax
  int v32; // eax
  float v33; // xmm1_4
  float v34; // xmm2_4
  int v35; // eax
  int v36; // eax
  float v37; // xmm2_4
  float v38; // xmm0_4
  float v39; // xmm1_4
  int v40; // eax
  int v41; // eax
  int v42; // eax
  void (__thiscall *v43)(_DWORD); // edx
  IMaterial *v44; // esi
  IMesh *v45; // esi
  float v46; // xmm0_4
  float v47; // xmm1_4
  float v48; // xmm2_4
  float *m_pCurrPosition; // eax
  float v50; // xmm0_4
  float *v51; // eax
  float v52; // xmm1_4
  float v53; // xmm2_4
  float v54; // xmm0_4
  float *v55; // eax
  float v56; // xmm1_4
  float v57; // xmm2_4
  float v58; // xmm0_4
  float *v59; // eax
  float v60; // xmm1_4
  float v61; // xmm2_4
  int v64; // [esp+50h] [ebp-4E4h]
  int v65; // [esp+54h] [ebp-4E0h]
  CMeshBuilder v66; // [esp+58h] [ebp-4DCh] BYREF
  _BYTE v67[12]; // [esp+240h] [ebp-2F4h] BYREF
  _BYTE builder_144[348]; // [esp+2DCh] [ebp-258h] OVERLAPPED BYREF
  int v69; // [esp+444h] [ebp-F0h]
  int v70; // [esp+448h] [ebp-ECh]
  int v71; // [esp+44Ch] [ebp-E8h]
  float v72; // [esp+450h] [ebp-E4h]
  int v73; // [esp+454h] [ebp-E0h]
  float v74; // [esp+458h] [ebp-DCh]
  int v75; // [esp+45Ch] [ebp-D8h]
  float v76; // [esp+460h] [ebp-D4h]
  float v77; // [esp+464h] [ebp-D0h]
  int v78; // [esp+468h] [ebp-CCh]
  float v79; // [esp+46Ch] [ebp-C8h]
  int flDot; // [esp+470h] [ebp-C4h] BYREF
  float v81; // [esp+474h] [ebp-C0h]
  int v82; // [esp+478h] [ebp-BCh] BYREF
  float flHorzSize; // [esp+47Ch] [ebp-B8h]
  float v84; // [esp+480h] [ebp-B4h]
  float flVertSize; // [esp+484h] [ebp-B0h]
  int v86; // [esp+488h] [ebp-ACh]
  float v87; // [esp+48Ch] [ebp-A8h]
  int v88; // [esp+490h] [ebp-A4h]
  float v89; // [esp+494h] [ebp-A0h]
  int v90; // [esp+498h] [ebp-9Ch]
  float v91; // [esp+49Ch] [ebp-98h]
  int v92; // [esp+4A0h] [ebp-94h]
  float v93; // [esp+4A4h] [ebp-90h]
  int v94; // [esp+4A8h] [ebp-8Ch]
  float v95; // [esp+4ACh] [ebp-88h]
  int v96; // [esp+4B0h] [ebp-84h]
  float v97; // [esp+4B4h] [ebp-80h]
  int v98; // [esp+4B8h] [ebp-7Ch]
  int v99; // [esp+4BCh] [ebp-78h]
  float v100; // [esp+4C0h] [ebp-74h]
  IMaterial **v101; // [esp+4C4h] [ebp-70h]
  int v102; // [esp+4C8h] [ebp-6Ch]
  float x; // [esp+4CCh] [ebp-68h] BYREF
  float y; // [esp+4D0h] [ebp-64h]
  int iSprite; // [esp+4D4h] [ebp-60h]
  Vector vToGlow; // [esp+4D8h] [ebp-5Ch]
  Vector vPt; // [esp+4E4h] [ebp-50h]
  CGlowOverlay *v108; // [esp+4F0h] [ebp-44h]
  float v109[3]; // [esp+4F4h] [ebp-40h] BYREF
  Vector vColor; // [esp+500h] [ebp-34h] BYREF
  Vector vBasePt; // [esp+50Ch] [ebp-28h] BYREF
  Vector vUp; // [esp+518h] [ebp-1Ch] BYREF
  Vector vRight; // [esp+524h] [ebp-10h]
  float retaddr; // [esp+534h] [ebp+0h]

  vRight.y = a2;
  vRight.z = retaddr;
  v108 = this;
  if ( r_drawsprites.m_pParent != nullptr && r_drawsprites.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( this->m_bDirectional )
    {
      x = this->m_vDirection.x;
      y = this->m_vDirection.y;
      iSprite = SLODWORD(this->m_vDirection.z);
    }
    else
    {
      v6 = CurrentViewOrigin();
      v7 = this->m_vPos.y - v6->y;
      *(float *)&v8 = this->m_vPos.z - v6->z;
      x = this->m_vPos.x - v6->x;
      y = v7;
      iSprite = v8;
    }
    VectorNormalize(vec: (Vector *)&x);
    v9 = CurrentViewForward();
    v77 = (float)((float)(v9->y * y) + (float)(v9->x * x)) + (float)(v9->z * *(float *)&iSprite);
    CGlowOverlay::UpdateGlowObstruction(this, vToGlow: (const Vector *)&x, bCacheFullSceneState);
    if ( this->m_flGlowObstructionScale != 0.0 )
    {
      HIBYTE(vRight.x) = ShouldDrawInWireFrameMode()
                      || r_drawsprites.m_pParent != nullptr && r_drawsprites.m_pParent->m_Value.m_nValue == 2;
      v10 = materials->GetRenderContext(this: materials);
      if ( v10 != nullptr )
        v10->BeginRender(this: v10);
      v11 = this->m_nSprites <= 0;
      v102 = 0;
      if ( !v11 )
      {
        p_m_pMaterial = &this->m_Sprites[0].m_pMaterial;
        v101 = p_m_pMaterial;
        do
        {
          ((void (__stdcall *)(float, IMaterial **, int *, int *, float *))v108->CalcSpriteColorAndSize)(
            a1: COERCE_FLOAT(LODWORD(v77)),
            a2: p_m_pMaterial - 5,
            a3: &flDot,
            a4: &v82,
            a5: v109);
          v84 = v109[0] * v109[0];
          if ( (float)((float)((float)(v109[0] * v109[0]) + (float)(v109[1] * v109[1])) + (float)(v109[2] * v109[2])) >= 0.0000099999997 )
          {
            ((void (__thiscall *)(CGlowOverlay *, float *, int, int, Vector *, Vector *, Vector *))v108->CalcBasis)(
              a1: v108,
              a2: &x,
              a3: flDot,
              a4: v82,
              a5: &vColor,
              a6: &vBasePt,
              a7: &vUp);
            radius = 0;
            v14 = view->__vftable;
            *(float *)&radius = fsqrt(
                                  (float)((float)((float)(vBasePt.x + vUp.x) * (float)(vBasePt.x + vUp.x))
                                        + (float)((float)(vBasePt.y + vUp.y) * (float)(vBasePt.y + vUp.y)))
                                + (float)((float)(vBasePt.z + vUp.z) * (float)(vBasePt.z + vUp.z)));
            *(_OWORD *)&builder_144[332] = radius;
            v15 = v14->GetFrustum(this: view);
            if ( R_CullSphere(pPlanes: v15, nPlanes: 5, pCenter: &vColor, radius: *(float *)&radius) == 0 )
            {
              if ( *p_m_pMaterial == nullptr )
                *p_m_pMaterial = materials->FindMaterial(
                                   this: materials,
                                   a2: "sprites/light_glow02_add_noz",
                                   a3: "ClientEffect textures",
                                   a4: 1,
                                   a5: 0);
              v16 = ((int (__thiscall *)(IMaterial *, const char *, unsigned int *, int, int, int, int, int, int, int, int, int, int, int, int, int, int))(*p_m_pMaterial)->FindVarFast)(
                      a1: *p_m_pMaterial,
                      a2: "$hdrcolorscale",
                      a3: &nHDRColorScaleCache_7,
                      a4: a3,
                      a5: a4,
                      a6: v64,
                      a7: v65,
                      a8: v66.m_VertexSize_Position,
                      a9: v66.m_VertexSize_BoneWeight,
                      a10: v66.m_VertexSize_BoneMatrixIndex,
                      a11: v66.m_VertexSize_Normal,
                      a12: v66.m_VertexSize_Color,
                      a13: v66.m_VertexSize_Specular,
                      a14: v66.m_VertexSize_TexCoord[0],
                      a15: v66.m_VertexSize_TexCoord[1],
                      a16: v66.m_VertexSize_TexCoord[2],
                      a17: v66.m_VertexSize_TexCoord[3]);
              if ( v16 != 0 )
              {
                v18 = *(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v16 + 16);
                v66.m_VertexSize_TexCoord[3] = v17;
                v18(a1: v16, a2: LODWORD(v108->m_flHDRColorScale));
              }
              GetDynamicMesh = v10->GetDynamicMesh;
              v66.m_VertexSize_TexCoord[3] = (int)*p_m_pMaterial;
              memset(v66.m_VertexSize_TexCoord, 0, 12);
              v20 = (IMesh *)((int (__thiscall *)(IMatRenderContext *))GetDynamicMesh)(a1: v10);
              CMeshBuilder::CMeshBuilder(this: (CMeshBuilder *)v67);
              *(_DWORD *)&builder_144[24] = v20;
              builder_144[32] = 1;
              *(_DWORD *)&builder_144[28] = 7;
              SetPrimitiveType = v20->SetPrimitiveType;
              v66.m_VertexSize_Specular = 2;
              ((void (__thiscall *)(IMesh *))SetPrimitiveType)(a1: v20);
              v22 = *(void (__thiscall **)(_DWORD))(**(_DWORD **)&builder_144[24] + 68);
              v66.m_VertexSize_Color = 0;
              v66.m_VertexSize_Normal = (int)v67;
              v66.m_VertexSize_BoneMatrixIndex = 6;
              v66.m_VertexSize_BoneWeight = 4;
              v22(a1: *(_DWORD *)&builder_144[24]);
              *(_DWORD *)&builder_144[60] = 0;
              builder_144[84] = 0;
              *(_DWORD *)&builder_144[68] = 0;
              *(_DWORD *)&builder_144[52] = &v20->IIndexBuffer;
              *(_DWORD *)&builder_144[64] = *(_DWORD *)builder_144;
              *(_DWORD *)&builder_144[36] = *(_DWORD *)&builder_144[8];
              *(_DWORD *)&builder_144[56] = 6;
              *(_DWORD *)&builder_144[48] = *(_DWORD *)&builder_144[20];
              CVertexBuilder::AttachBegin(
                this: (CVertexBuilder *)&builder_144[88],
                pMesh: v20,
                nMaxVertexCount: 4,
                desc: (const MeshDesc_t *)v67);
              *(_DWORD *)&builder_144[68] = 0;
              CVertexBuilder::Reset(this: (CVertexBuilder *)&builder_144[88]);
              v23 = (float)(vColor.z - vUp.z) + vBasePt.z;
              v24 = (float)(vColor.x - vUp.x) + vBasePt.x;
              v25 = (float)(vColor.y - vUp.y) + vBasePt.y;
              v26 = *(_DWORD *)&builder_144[272];
              vToGlow.z = v23;
              **(float **)&builder_144[272] = v24;
              *(float *)(v26 + 4) = v25;
              *(float *)(v26 + 8) = v23;
              vToGlow.x = v24;
              vToGlow.y = v25;
              v72 = (float)(v109[2] * 255.0) + 8388608.0;
              v74 = (float)(v109[1] * 255.0) + 8388608.0;
              v76 = (float)(v109[0] * 255.0) + 8388608.0;
              v78 = 1258291455;
              **(_DWORD **)&builder_144[280] = LOBYTE(v72) | ((LOBYTE(v74) | ((LOBYTE(v76) | 0xFF00) << 8)) << 8);
              v27 = *(_DWORD *)&builder_144[284];
              **(_DWORD **)&builder_144[284] = 0;
              *(_DWORD *)(v27 + 4) = 1065353216;
              CVertexBuilder::AdvanceVertex(this: (CVertexBuilder *)&builder_144[88]);
              v28 = (float)(vColor.x + vUp.x) + vBasePt.x;
              v29 = (float)(vColor.z + vUp.z) + vBasePt.z;
              v30 = (float)(vColor.y + vUp.y) + vBasePt.y;
              v31 = *(_DWORD *)&builder_144[272];
              **(float **)&builder_144[272] = v28;
              *(float *)(v31 + 4) = v30;
              *(float *)(v31 + 8) = v29;
              vToGlow.z = v29;
              vToGlow.x = v28;
              vToGlow.y = v30;
              v95 = (float)(v109[2] * 255.0) + 8388608.0;
              v81 = (float)(v109[1] * 255.0) + 8388608.0;
              v97 = (float)(v109[0] * 255.0) + 8388608.0;
              v69 = 1258291455;
              **(_DWORD **)&builder_144[280] = LOBYTE(v95) | ((LOBYTE(v81) | ((LOBYTE(v97) | 0xFF00) << 8)) << 8);
              v32 = *(_DWORD *)&builder_144[284];
              **(_DWORD **)&builder_144[284] = 1065353216;
              *(_DWORD *)(v32 + 4) = 1065353216;
              CVertexBuilder::AdvanceVertex(this: (CVertexBuilder *)&builder_144[88]);
              v33 = (float)(vColor.y + vUp.y) - vBasePt.y;
              v34 = (float)(vColor.z + vUp.z) - vBasePt.z;
              vToGlow.x = (float)(vColor.x + vUp.x) - vBasePt.x;
              v35 = *(_DWORD *)&builder_144[272];
              **(_DWORD **)&builder_144[272] = LODWORD(vToGlow.x);
              *(float *)(v35 + 4) = v33;
              *(float *)(v35 + 8) = v34;
              vToGlow.z = v34;
              vToGlow.y = v33;
              v91 = (float)(v109[2] * 255.0) + 8388608.0;
              v79 = (float)(v109[1] * 255.0) + 8388608.0;
              v93 = (float)(v109[0] * 255.0) + 8388608.0;
              v73 = 1258291455;
              **(_DWORD **)&builder_144[280] = LOBYTE(v91) | ((LOBYTE(v79) | ((LOBYTE(v93) | 0xFF00) << 8)) << 8);
              v36 = *(_DWORD *)&builder_144[284];
              **(_DWORD **)&builder_144[284] = 1065353216;
              *(_DWORD *)(v36 + 4) = 0;
              CVertexBuilder::AdvanceVertex(this: (CVertexBuilder *)&builder_144[88]);
              v37 = (float)(vColor.z - vUp.z) - vBasePt.z;
              v38 = (float)(vColor.x - vUp.x) - vBasePt.x;
              v39 = (float)(vColor.y - vUp.y) - vBasePt.y;
              v40 = *(_DWORD *)&builder_144[272];
              **(float **)&builder_144[272] = v38;
              vToGlow.z = v37;
              *(float *)(v40 + 4) = v39;
              *(float *)(v40 + 8) = v37;
              vToGlow.x = v38;
              vToGlow.y = v39;
              v87 = (float)(v109[2] * 255.0) + 8388608.0;
              v100 = (float)(v109[1] * 255.0) + 8388608.0;
              v89 = (float)(v109[0] * 255.0) + 8388608.0;
              v70 = 1258291455;
              **(_DWORD **)&builder_144[280] = LOBYTE(v87) | ((LOBYTE(v100) | ((LOBYTE(v89) | 0xFF00) << 8)) << 8);
              v41 = *(_DWORD *)&builder_144[284];
              **(_DWORD **)&builder_144[284] = 0;
              *(_DWORD *)(v41 + 4) = 0;
              CVertexBuilder::AdvanceVertex(this: (CVertexBuilder *)&builder_144[88]);
              if ( builder_144[32] != 0 )
              {
                switch ( *(_DWORD *)&builder_144[28] )
                {
                  case 4:
                    v42 = 2 * *(_DWORD *)&builder_144[264] - 2;
                    break;
                  case 5:
                    v42 = 2 * *(_DWORD *)&builder_144[264];
                    break;
                  case 6:
                    v42 = 3 * *(_DWORD *)&builder_144[264] - 6;
                    break;
                  case 7:
                    v42 = 6 * *(_DWORD *)&builder_144[264] / 4;
                    break;
                  case 0xA:
                    v42 = 0;
                    break;
                  default:
                    v42 = *(_DWORD *)&builder_144[264];
                    break;
                }
                CIndexBuilder::GenerateIndices(
                  this: (CIndexBuilder *)&builder_144[36],
                  primitiveType: *(MaterialPrimitiveType_t *)&builder_144[28],
                  nIndexCount: v42);
              }
              v43 = *(void (__thiscall **)(_DWORD))(**(_DWORD **)&builder_144[24] + 80);
              v66.m_VertexSize_Position = (int)v67;
              v65 = *(_DWORD *)&builder_144[60];
              v64 = *(_DWORD *)&builder_144[264];
              v43(a1: *(_DWORD *)&builder_144[24]);
              *(_DWORD *)&builder_144[52] = 0;
              *(_DWORD *)&builder_144[56] = 0;
              *(_DWORD *)&builder_144[260] = 0;
              *(_DWORD *)&builder_144[252] = 0;
              *(_DWORD *)&builder_144[164] = -1;
              a4 = 0;
              a3 = -1;
              (*(void (__thiscall **)(_DWORD))(**(_DWORD **)&builder_144[24] + 48))(a1: *(_DWORD *)&builder_144[24]);
              *(_DWORD *)&builder_144[24] = 0;
              if ( HIBYTE(vRight.x) != 0 )
              {
                v44 = materials->FindMaterial(
                        this: materials,
                        a2: "debug/debugwireframevertexcolor",
                        a3: "Other textures",
                        a4: 1,
                        a5: 0);
                v10->Bind(this: v10, a2: v44, a3: nullptr);
                v45 = v10->GetDynamicMesh(this: v10, a2: false, a3: nullptr, a4: nullptr, a5: v44);
                CMeshBuilder::CMeshBuilder(this: &v66);
                v66.m_pMesh = v45;
                v66.m_bGenerateIndices = true;
                v66.m_Type = MATERIAL_QUADS;
                v45->SetPrimitiveType(this: v45, a2: MATERIAL_TRIANGLES);
                v66.m_pMesh->LockMesh(this: v66.m_pMesh, a2: 4, a3: 6, a4: &v66, a5: nullptr);
                v66.m_IndexBuilder.m_pIndices = v66.m_pIndices;
                v66.m_IndexBuilder.m_nIndexOffset = v66.m_nFirstVertex;
                v66.m_IndexBuilder.m_pIndexBuffer = &v45->IIndexBuffer;
                v66.m_IndexBuilder.m_nIndexSize = v66.m_nIndexSize;
                v66.m_IndexBuilder.m_nIndexCount = 0;
                v66.m_IndexBuilder.m_nMaxIndexCount = 6;
                v66.m_IndexBuilder.m_bModify = false;
                v66.m_IndexBuilder.m_nCurrentIndex = 0;
                CVertexBuilder::AttachBegin(this: &v66.m_VertexBuilder, pMesh: v45, nMaxVertexCount: 4, desc: &v66);
                v66.m_IndexBuilder.m_nCurrentIndex = 0;
                CVertexBuilder::Reset(this: &v66.m_VertexBuilder);
                v46 = (float)(vColor.x - vUp.x) + vBasePt.x;
                v47 = (float)(vColor.y - vUp.y) + vBasePt.y;
                v48 = (float)(vColor.z - vUp.z) + vBasePt.z;
                m_pCurrPosition = v66.m_VertexBuilder.m_pCurrPosition;
                *v66.m_VertexBuilder.m_pCurrPosition = v46;
                m_pCurrPosition[1] = v47;
                vPt.x = v46;
                vPt.y = v47;
                vPt.z = v48;
                m_pCurrPosition[2] = v48;
                v75 = 1258291200;
                flVertSize = 8388608.0;
                v71 = 1258291455;
                *(_DWORD *)v66.m_VertexBuilder.m_pCurrColor = -65536;
                CVertexBuilder::AdvanceVertex(this: &v66.m_VertexBuilder);
                v50 = (float)(vColor.x + vUp.x) + vBasePt.x;
                v51 = v66.m_VertexBuilder.m_pCurrPosition;
                v52 = (float)(vColor.y + vUp.y) + vBasePt.y;
                v53 = (float)(vColor.z + vUp.z) + vBasePt.z;
                *v66.m_VertexBuilder.m_pCurrPosition = v50;
                v51[1] = v52;
                vPt.x = v50;
                v51[2] = v53;
                vPt.y = v52;
                vPt.z = v53;
                v98 = 1258291200;
                v99 = 1258291200;
                flHorzSize = 8388863.0;
                *(_DWORD *)v66.m_VertexBuilder.m_pCurrColor = -65536;
                CVertexBuilder::AdvanceVertex(this: &v66.m_VertexBuilder);
                v54 = (float)(vColor.x + vUp.x) - vBasePt.x;
                v55 = v66.m_VertexBuilder.m_pCurrPosition;
                v56 = (float)(vColor.y + vUp.y) - vBasePt.y;
                v57 = (float)(vColor.z + vUp.z) - vBasePt.z;
                *v66.m_VertexBuilder.m_pCurrPosition = v54;
                v55[1] = v56;
                vPt.x = v54;
                v55[2] = v57;
                vPt.y = v56;
                vPt.z = v57;
                v92 = 1258291200;
                v94 = 1258291200;
                v96 = 1258291455;
                *(_DWORD *)v66.m_VertexBuilder.m_pCurrColor = -65536;
                CVertexBuilder::AdvanceVertex(this: &v66.m_VertexBuilder);
                v58 = (float)(vColor.x - vUp.x) - vBasePt.x;
                v59 = v66.m_VertexBuilder.m_pCurrPosition;
                v60 = (float)(vColor.y - vUp.y) - vBasePt.y;
                v61 = (float)(vColor.z - vUp.z) - vBasePt.z;
                *v66.m_VertexBuilder.m_pCurrPosition = v58;
                v59[1] = v60;
                v59[2] = v61;
                vPt.x = v58;
                vPt.y = v60;
                vPt.z = v61;
                v86 = 1258291200;
                v88 = 1258291200;
                v90 = 1258291455;
                *(_DWORD *)v66.m_VertexBuilder.m_pCurrColor = -65536;
                CVertexBuilder::AdvanceVertex(this: &v66.m_VertexBuilder);
                CMeshBuilder::End(this: &v66, bSpewData: false, bDraw: true);
                CMeshBuilder::~CMeshBuilder(this: &v66);
              }
              CMeshBuilder::~CMeshBuilder(this: (CMeshBuilder *)v67);
              p_m_pMaterial = v101;
            }
          }
          p_m_pMaterial += 6;
          ++v102;
          v101 = p_m_pMaterial;
        }
        while ( v102 < v108->m_nSprites );
      }
      if ( v10 != nullptr )
      {
        v10->EndRender(this: v10);
        v10->Release(this: v10);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EC300
// Name: public: static void CGlowOverlay::DrawOverlays(bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall CGlowOverlay::DrawOverlays(int a1@<esi>, int bCacheFullSceneState)
{
  IMatRenderContext *v2; // edi
  unsigned __int16 m_Head; // ax
  CGlowOverlay *m_Element; // esi
  unsigned __int16 m_Next; // bx
  bool bClippingEnabled; // [esp+4h] [ebp-4h]

  v2 = materials->GetRenderContext(this: materials);
  if ( v2 != nullptr )
    v2->BeginRender(this: v2);
  bClippingEnabled = v2->EnableClipping(this: v2, a2: true);
  m_Head = g_GlowOverlaySystem.m_GlowOverlays.m_Head;
  if ( g_GlowOverlaySystem.m_GlowOverlays.m_Head != 0xFFFF )
  {
    do
    {
      m_Element = g_GlowOverlaySystem.m_GlowOverlays.m_Memory.m_pMemory[m_Head].m_Element;
      m_Next = g_GlowOverlaySystem.m_GlowOverlays.m_Memory.m_pMemory[m_Head].m_Next;
      if ( m_Element->m_bActivated != 0 )
      {
        if ( ((unsigned __int8 (__thiscall *)(CGlowOverlay *, int))m_Element->Update)(a1: m_Element, a2: a1) != 0 )
        {
          v2->EnableClipping(this: v2, a2: !m_Element->m_bInSky && bClippingEnabled);
          a1 = bCacheFullSceneState;
          ((void (__thiscall *)(CGlowOverlay *))m_Element->Draw)(a1: m_Element);
        }
        else
        {
          a1 = 1;
          m_Element->dtr_CGlowOverlay(this: m_Element);
        }
      }
      m_Head = m_Next;
    }
    while ( m_Next != 0xFFFF );
  }
  v2->EnableClipping(this: v2, a2: bClippingEnabled);
  v2->EndRender(this: v2);
  v2->Release(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x100EC3E0
// Name: public: static void CGlowOverlay::UpdateSkyOverlays(float,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CGlowOverlay::UpdateSkyOverlays(float zFar, bool bCacheFullSceneState)
{
  unsigned __int16 m_Head; // ax
  CGlowOverlay *m_Element; // ecx
  unsigned __int16 m_Next; // si

  m_Head = g_GlowOverlaySystem.m_GlowOverlays.m_Head;
  if ( g_GlowOverlaySystem.m_GlowOverlays.m_Head != 0xFFFF )
  {
    do
    {
      m_Element = g_GlowOverlaySystem.m_GlowOverlays.m_Memory.m_pMemory[m_Head].m_Element;
      m_Next = g_GlowOverlaySystem.m_GlowOverlays.m_Memory.m_pMemory[m_Head].m_Next;
      if ( m_Element->m_bActivated != 0 && m_Element->m_bDirectional && m_Element->m_bInSky )
        CGlowOverlay::UpdateSkyGlowObstruction(this: m_Element, zFar, bCacheFullSceneState);
      m_Head = m_Next;
    }
    while ( m_Next != 0xFFFF );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EC560
// Name: public: virtual void CGlowOverlaySystem::LevelShutdownPostEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGlowOverlaySystem::LevelShutdownPostEntity(CGlowOverlaySystem *this)
{
  CUtlLinkedList<CGlowOverlay *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CGlowOverlay *,unsigned short>,unsigned short>>::PurgeAndDeleteElements(this: &this->m_GlowOverlays);
}

//------------------------------------------------------------------------------
// Address: 0x100EC570
// Name: public: virtual CGlowOverlay::~CGlowOverlay(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGlowOverlay::~CGlowOverlay(CGlowOverlay *this)
{
  int m_ListIndex; // esi

  m_ListIndex = this->m_ListIndex;
  this->__vftable = (CGlowOverlay_vtbl *)&CGlowOverlay::`vftable';
  if ( (_WORD)m_ListIndex != 0xFFFF )
  {
    CUtlLinkedList<CEffectMaterial *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEffectMaterial *,unsigned short>,unsigned short>>::Unlink(
      this: (CUtlLinkedList<C_RopeKeyframe *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_RopeKeyframe *,unsigned short>,unsigned short> > *)&g_GlowOverlaySystem.m_GlowOverlays,
      elem: m_ListIndex);
    g_GlowOverlaySystem.m_GlowOverlays.m_Memory.m_pMemory[m_ListIndex].m_Next = g_GlowOverlaySystem.m_GlowOverlays.m_FirstFree;
    g_GlowOverlaySystem.m_GlowOverlays.m_FirstFree = m_ListIndex;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EC610
// Name: public: void CGlowOverlay::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGlowOverlay::Activate(CGlowOverlay *this)
{
  unsigned __int16 v2; // ax
  int v3; // esi
  UtlLinkedListElem_t<CGlowOverlay *,unsigned short> *v4; // eax

  this->m_bActivated = 1;
  if ( this->m_ListIndex == 0xFFFF )
  {
    v2 = CUtlLinkedList<CGlowOverlay *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CGlowOverlay *,unsigned short>,unsigned short>>::AllocInternal(
           this: &g_GlowOverlaySystem.m_GlowOverlays,
           multilist: false);
    v3 = v2;
    if ( v2 == 0xFFFF )
    {
      this->m_ListIndex = -1;
    }
    else
    {
      CUtlLinkedList<CEnvWindShared *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared *,unsigned short>,unsigned short>>::LinkBefore(
        this: (CUtlLinkedList<C_RopeKeyframe *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<C_RopeKeyframe *,unsigned short>,unsigned short> > *)&g_GlowOverlaySystem.m_GlowOverlays,
        before: 0xFFFFu,
        elem: v2);
      v4 = &g_GlowOverlaySystem.m_GlowOverlays.m_Memory.m_pMemory[v3];
      if ( v4 != nullptr )
        v4->m_Element = this;
      this->m_ListIndex = v3;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10416730
// Name: PrecacheEffectGlowPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
CBaseResourcePrecacher *PrecacheEffectGlowPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  CBaseResourcePrecacher *result; // eax

  result = CBaseResourcePrecacher::sm_pFirst[0];
  PrecacheEffectGlowPrecache::s_ResourcePrecacher.m_pNext = CBaseResourcePrecacher::sm_pFirst[0];
  CBaseResourcePrecacher::sm_pFirst[0] = &PrecacheEffectGlowPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10416750
// Name: _dynamic_initializer_for__g_GlowOverlaySystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_GlowOverlaySystem__()
{
  CAutoGameSystem::CAutoGameSystem(this: &g_GlowOverlaySystem, name: "CGlowOverlaySystem");
  g_GlowOverlaySystem.__vftable = (CGlowOverlaySystem_vtbl *)&CGlowOverlaySystem::`vftable';
  g_GlowOverlaySystem.m_GlowOverlays.m_Memory.m_pMemory = nullptr;
  g_GlowOverlaySystem.m_GlowOverlays.m_Memory.m_nAllocationCount = 0;
  g_GlowOverlaySystem.m_GlowOverlays.m_Memory.m_nGrowSize = 0;
  g_GlowOverlaySystem.m_GlowOverlays.m_LastAlloc.index = -1;
  *(_DWORD *)&g_GlowOverlaySystem.m_GlowOverlays.m_Head = -1;
  *(_DWORD *)&g_GlowOverlaySystem.m_GlowOverlays.m_FirstFree = 0xFFFF;
  g_GlowOverlaySystem.m_GlowOverlays.m_NumAlloced = 0;
  g_GlowOverlaySystem.m_GlowOverlays.m_pElements = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__g_GlowOverlaySystem__);
}

//------------------------------------------------------------------------------
// Address: 0x104167B0
// Name: _dynamic_initializer_for__cl_ShowSunVectors__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_ShowSunVectors__()
{
  ConVar::ConVar(this: &cl_ShowSunVectors, pName: "cl_ShowSunVectors", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__cl_ShowSunVectors__);
}

//------------------------------------------------------------------------------
// Address: 0x104167E0
// Name: _dynamic_initializer_for__cl_sun_decay_rate__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_sun_decay_rate__()
{
  ConVar::ConVar(this: &cl_sun_decay_rate, pName: "cl_sun_decay_rate", pDefaultValue: "0.05", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__cl_sun_decay_rate__);
}

//------------------------------------------------------------------------------
// Address: 0x10416810
// Name: _dynamic_initializer_for__g_flOverlayRange__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_flOverlayRange__()
{
  double v0; // xmm0_8

  __libm_sse2_cos(X: (__m128i)0x3FE6571840000000uLL);
  *(float *)&v0 = v0;
  g_flOverlayRange = *(float *)&v0;
}

//------------------------------------------------------------------------------
// Address: 0x10416830
// Name: _dynamic_initializer_for__building_cubemaps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__building_cubemaps__()
{
  ConVar::ConVar(
    this: &building_cubemaps,
    pName: "building_cubemaps",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Indicates we're building cubemaps",
    callback: (void (__cdecl *)(IConVar *, const char *, float))BuildingCubemapsChanged);
  return atexit(func: dynamic_atexit_destructor_for__building_cubemaps__);
}

//------------------------------------------------------------------------------
// Address: 0x10416860
// Name: _dynamic_initializer_for__cl_showhelp__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_showhelp__()
{
  ConVar::ConVar(
    this: &cl_showhelp,
    pName: "cl_showhelp",
    pDefaultValue: "1",
    flags: 640,
    pHelpString: "Set to 0 to not show on-screen help");
  return atexit(func: dynamic_atexit_destructor_for__cl_showhelp__);
}

//------------------------------------------------------------------------------
// Address: 0x10416890
// Name: _dynamic_initializer_for__cl_clearhinthistory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_clearhinthistory__()
{
  ConCommand::ConCommand(
    this: &cl_clearhinthistory,
    pName: "cl_clearhinthistory",
    callback: HintClear,
    pHelpString: "Clear memory of client side hints displayed to the player.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__cl_clearhinthistory__);
}
