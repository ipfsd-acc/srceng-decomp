// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/spritetrail.cpp
// Functions: 27
// ============================================================

#include "game\shared\spritetrail.h"

//------------------------------------------------------------------------------
// Address: 0x10170BA0
// Name: private: virtual struct datamap_t __near * C_SpriteTrail::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall C_SpriteTrail::GetDataDescMap(C_SpriteTrail *this)
{
  return &C_SpriteTrail::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10170BB0
// Name: private: virtual class ClientClass __near * C_SpriteTrail::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_SpriteTrail::GetClientClass(C_SpriteTrail *this)
{
  return &__g_C_SpriteTrailClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10170D20
// Name: public: virtual struct datamap_t __near * C_SpriteTrail::GetPredDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall C_SpriteTrail::GetPredDescMap(C_SpriteTrail *this)
{
  return &C_SpriteTrail::m_PredMap;
}

//------------------------------------------------------------------------------
// Address: 0x10170D30
// Name: public: virtual void C_SpriteTrail::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall C_SpriteTrail::Spawn(C_SpriteTrail *this)
{
  C_Sprite::Spawn(this);
}

//------------------------------------------------------------------------------
// Address: 0x10170D40
// Name: public: virtual void C_SpriteTrail::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SpriteTrail::Precache(C_SpriteTrail *this)
{
  const char *m_iszSpriteName; // esi

  C_Sprite::Precache(this);
  m_iszSpriteName = this->m_iszSpriteName;
  if ( m_iszSpriteName != nullptr )
    C_BaseEntity::PrecacheModel(name: m_iszSpriteName);
}

//------------------------------------------------------------------------------
// Address: 0x10170D60
// Name: public: virtual void C_SpriteTrail::OnPreDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SpriteTrail::OnPreDataChanged(C_SpriteTrail *this, DataUpdateType_t updateType)
{
  C_BaseEntity::OnPreDataChanged(this, type: updateType);
  *(float *)&this->m_nStepCount = this->m_flTextureRes.m_Value;
  this->m_flUpdateTime = this->m_flMinFadeLength.m_Value;
  this->m_vecPrevSkyboxOrigin.x = this->m_vecSkyboxOrigin.m_Value.x;
  this->m_vecPrevSkyboxOrigin.y = this->m_vecSkyboxOrigin.m_Value.y;
}

//------------------------------------------------------------------------------
// Address: 0x10170DB0
// Name: public: virtual void C_SpriteTrail::GetRenderBounds(class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SpriteTrail::GetRenderBounds(C_SpriteTrail *this, Vector *mins, Vector *maxs)
{
  *mins = *(Vector *)&this->m_flPrevSkyboxScale;
  *maxs = *(Vector *)&this->m_vecRenderMins.z;
}

//------------------------------------------------------------------------------
// Address: 0x10170E00
// Name: private: void C_SpriteTrail::ConvertSkybox(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SpriteTrail::ConvertSkybox(C_SpriteTrail *this)
{
  int i; // edx
  TrailPoint_t *v2; // eax
  float y; // xmm1_4
  float v4; // xmm3_4
  float z; // xmm2_4
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm2_4

  for ( i = 0;
        i < this->m_nStepCount;
        v2->m_flWidthVariance = (float)(this->m_flPrevSkyboxScale / this->m_flSkyboxScale.m_Value)
                              * v2->m_flWidthVariance )
  {
    v2 = &this->m_vecSteps[((_BYTE)i + (unsigned __int8)this->m_nFirstStep) & 0x3F];
    v2->m_vecScreenPos.x = v2->m_vecScreenPos.x - this->m_vecPrevSkyboxOrigin.x;
    v2->m_vecScreenPos.y = v2->m_vecScreenPos.y - this->m_vecPrevSkyboxOrigin.y;
    y = v2->m_vecScreenPos.y;
    v2->m_vecScreenPos.z = v2->m_vecScreenPos.z - this->m_vecPrevSkyboxOrigin.z;
    v4 = this->m_flPrevSkyboxScale / this->m_flSkyboxScale.m_Value;
    z = v2->m_vecScreenPos.z;
    v6 = v2->m_vecScreenPos.x * v4;
    v2->m_vecScreenPos.x = v6;
    v7 = y * v4;
    v2->m_vecScreenPos.y = v7;
    v8 = z * v4;
    v2->m_vecScreenPos.z = v8;
    v2->m_vecScreenPos.x = v6 - this->m_vecSkyboxOrigin.m_Value.x;
    v2->m_vecScreenPos.y = v7 - this->m_vecSkyboxOrigin.m_Value.y;
    v2->m_vecScreenPos.z = v8 - this->m_vecSkyboxOrigin.m_Value.z;
    ++i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10170EF0
// Name: private: void C_SpriteTrail::UpdateBoundingBox(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SpriteTrail::UpdateBoundingBox(C_SpriteTrail *this)
{
  const Vector *v2; // eax
  __int64 v3; // xmm0_8
  float z; // eax
  float v5; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm4_4
  float m_Value; // xmm0_4
  float v9; // xmm7_4
  int v10; // ecx
  float v11; // xmm0_4
  float v12; // xmm4_4
  float v13; // xmm5_4
  float v14; // xmm6_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm3_4
  double x; // xmm0_8
  double v19; // xmm4_8
  float v20; // xmm0_4
  double y; // xmm0_8
  float v22; // xmm0_4
  double v23; // xmm0_8
  float v24; // xmm0_4
  double v25; // xmm0_8
  double v26; // xmm1_8
  float v27; // xmm0_4
  double v28; // xmm0_8
  float v29; // xmm0_4
  double v30; // xmm0_8
  __int64 vecRenderOrigin; // [esp+4h] [ebp-Ch]

  v2 = this->GetRenderOrigin(this: &this->IClientRenderable);
  v3 = *(_QWORD *)&v2->x;
  z = v2->z;
  vecRenderOrigin = v3;
  v5 = *(float *)&v3;
  v6 = *((float *)&v3 + 1);
  *(_QWORD *)&this->m_vecRenderMins.x = v3;
  v7 = z;
  this->m_vecRenderMins.z = z;
  *(_QWORD *)&this->m_vecRenderMaxs.x = v3;
  this->m_vecRenderMaxs.z = z;
  m_Value = this->m_flEndWidth.m_Value;
  v9 = this->m_flStartWidth.m_Value;
  if ( m_Value >= 0.0 && m_Value > this->m_flStartWidth.m_Value )
    v9 = this->m_flEndWidth.m_Value;
  v10 = 0;
  if ( this->m_nStepCount > 0 )
  {
    do
    {
      v11 = (float)(this->m_vecSteps[((_BYTE)v10 + (unsigned __int8)this->m_nFirstStep) & 0x3F].m_flWidthVariance + v9)
          * 0.5;
      v12 = this->m_vecSteps[((_BYTE)v10 + (unsigned __int8)this->m_nFirstStep) & 0x3F].m_vecScreenPos.x - v11;
      v13 = this->m_vecSteps[((_BYTE)v10 + (unsigned __int8)this->m_nFirstStep) & 0x3F].m_vecScreenPos.y - v11;
      v14 = this->m_vecSteps[((_BYTE)v10 + (unsigned __int8)this->m_nFirstStep) & 0x3F].m_vecScreenPos.z - v11;
      v15 = this->m_vecSteps[((_BYTE)v10 + (unsigned __int8)this->m_nFirstStep) & 0x3F].m_vecScreenPos.x + v11;
      v16 = this->m_vecSteps[((_BYTE)v10 + (unsigned __int8)this->m_nFirstStep) & 0x3F].m_vecScreenPos.y + v11;
      v17 = this->m_vecSteps[((_BYTE)v10 + (unsigned __int8)this->m_nFirstStep) & 0x3F].m_vecScreenPos.z + v11;
      x = this->m_vecRenderMins.x;
      v19 = v12;
      if ( x > v19 )
        x = v19;
      v20 = x;
      this->m_vecRenderMins.x = v20;
      y = this->m_vecRenderMins.y;
      if ( y > v13 )
        y = v13;
      v22 = y;
      this->m_vecRenderMins.y = v22;
      v23 = this->m_vecRenderMins.z;
      if ( v23 > v14 )
        v23 = v14;
      v24 = v23;
      this->m_vecRenderMins.z = v24;
      v25 = this->m_vecRenderMaxs.x;
      v26 = v15;
      if ( v25 < v26 )
        v25 = v26;
      v27 = v25;
      this->m_vecRenderMaxs.x = v27;
      v28 = this->m_vecRenderMaxs.y;
      if ( v28 < v16 )
        v28 = v16;
      v29 = v28;
      this->m_vecRenderMaxs.y = v29;
      v30 = this->m_vecRenderMaxs.z;
      if ( v30 < v17 )
        v30 = v17;
      ++v10;
      this->m_vecRenderMaxs.z = v30;
    }
    while ( v10 < this->m_nStepCount );
    v7 = z;
    v6 = *((float *)&vecRenderOrigin + 1);
    v5 = *(float *)&vecRenderOrigin;
  }
  this->m_vecRenderMins.x = this->m_vecRenderMins.x - v5;
  this->m_vecRenderMins.y = this->m_vecRenderMins.y - v6;
  this->m_vecRenderMins.z = this->m_vecRenderMins.z - v7;
  this->m_vecRenderMaxs.x = this->m_vecRenderMaxs.x - v5;
  this->m_vecRenderMaxs.y = this->m_vecRenderMaxs.y - v6;
  this->m_vecRenderMaxs.z = this->m_vecRenderMaxs.z - v7;
}

//------------------------------------------------------------------------------
// Address: 0x10171170
// Name: public: virtual void C_SpriteTrail::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SpriteTrail::OnDataChanged(C_SpriteTrail *this, DataUpdateType_t updateType)
{
  C_Sprite::OnDataChanged(this, updateType);
  if ( updateType != DATA_UPDATE_CREATED )
  {
    if ( this->m_vecPrevSkyboxOrigin.y != this->m_vecSkyboxOrigin.m_Value.y
      || this->m_flTextureRes.m_Value != *(float *)&this->m_nStepCount
      || this->m_flMinFadeLength.m_Value != this->m_flUpdateTime
      || this->m_vecSkyboxOrigin.m_Value.x != this->m_vecPrevSkyboxOrigin.x )
    {
      C_SpriteTrail::ConvertSkybox(this: (C_SpriteTrail *)((char *)this - 8));
    }
  }
  else
  {
    (*(void (__stdcall **)(int))(*((_DWORD *)this - 2) + 456))(a1: -996040704);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10171210
// Name: private: void C_SpriteTrail::UpdateTrail(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SpriteTrail::UpdateTrail(C_SpriteTrail *this)
{
  const Vector *v2; // eax
  int m_nStepCount; // ecx
  float x; // xmm3_4
  float y; // xmm4_4
  float z; // xmm5_4
  int m_nFirstStep; // edx
  TrailPoint_t *v8; // eax
  float v9; // xmm1_4
  float v10; // xmm2_4
  TrailPoint_t *v11; // edi
  float v12; // xmm0_4
  float v13; // [esp+1Ch] [ebp-28h]
  TrailPoint_t *v14; // [esp+34h] [ebp-10h]

  if ( this->m_flUpdateTime <= *(float *)(gpGlobals.m_Index + 12) )
  {
    v2 = this->GetRenderOrigin(this: &this->IClientRenderable);
    m_nStepCount = this->m_nStepCount;
    x = v2->x;
    y = v2->y;
    z = v2->z;
    v13 = v2->x;
    if ( m_nStepCount != 0 )
    {
      m_nFirstStep = this->m_nFirstStep;
      v14 = &this->m_vecSteps[((_BYTE)m_nFirstStep + (_BYTE)m_nStepCount - 1) & 0x3F];
      if ( (C_SpriteTrail *)((char *)this + 24 * (((_BYTE)m_nFirstStep + (_BYTE)m_nStepCount - 1) & 0x3F)) != (C_SpriteTrail *)-2536 )
      {
        v9 = this->m_vecSteps[((_BYTE)m_nFirstStep + (_BYTE)m_nStepCount - 1) & 0x3F].m_vecScreenPos.y;
        v10 = this->m_vecSteps[((_BYTE)m_nFirstStep + (_BYTE)m_nStepCount - 1) & 0x3F].m_vecScreenPos.z;
        v8 = &this->m_vecSteps[((_BYTE)m_nFirstStep + (_BYTE)m_nStepCount - 1) & 0x3F];
        if ( (float)((float)((float)((float)(v9 - y) * (float)(v9 - y))
                           + (float)((float)(v8->m_vecScreenPos.x - x) * (float)(v8->m_vecScreenPos.x - x)))
                   + (float)((float)(v10 - z) * (float)(v10 - z))) <= 4.0 )
        {
LABEL_12:
          this->m_flUpdateTime = (float)(this->m_flLifeTime.m_Value * 0.015625) + *(float *)(gpGlobals.m_Index + 12);
          return;
        }
      }
    }
    else
    {
      v14 = nullptr;
    }
    if ( m_nStepCount >= 64 )
    {
      ++this->m_nFirstStep;
      this->m_nStepCount = m_nStepCount - 1;
    }
    v11 = &this->m_vecSteps[(this->m_nStepCount + this->m_nFirstStep) & 0x3F];
    v11->m_vecScreenPos.x = x;
    v11->m_vecScreenPos.y = y;
    v11->m_vecScreenPos.z = z;
    v11->m_flDieTime = this->m_flLifeTime.m_Value + *(float *)(gpGlobals.m_Index + 12);
    v11->m_flWidthVariance = ((double (__thiscall *)(IUniformRandomStream *, unsigned int, _DWORD))random->RandomFloat)(
                               a1: random,
                               a2: LODWORD(this->m_flStartWidthVariance.m_Value) ^ (unsigned int)_mask__NegFloat_,
                               a3: LODWORD(this->m_flStartWidthVariance.m_Value));
    if ( v14 != nullptr )
      v12 = (float)(this->m_flTextureRes.m_Value
                  * fsqrt(
                      (float)((float)((float)(v14->m_vecScreenPos.y - y) * (float)(v14->m_vecScreenPos.y - y))
                            + (float)((float)(v14->m_vecScreenPos.z - z) * (float)(v14->m_vecScreenPos.z - z)))
                    + (float)((float)(v14->m_vecScreenPos.x - v13) * (float)(v14->m_vecScreenPos.x - v13))))
          + v14->m_flTexCoord;
    else
      v12 = 0.0;
    v11->m_flTexCoord = v12;
    ++this->m_nStepCount;
    goto LABEL_12;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10171400
// Name: public: virtual class Vector const __near & C_SpriteTrail::GetRenderOrigin(void)
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall C_SpriteTrail::GetRenderOrigin(C_SpriteTrail *this)
{
  float m_flHDRColorScale; // ecx
  int v3; // eax
  CEntInfo *v4; // edx
  int v5; // ecx
  int v6; // eax
  bool v7; // zf
  CEntInfo *v8; // eax
  IHandleEntity *m_pEntity; // ecx
  int v10; // eax
  QAngle dummyAngles; // [esp+4h] [ebp-Ch] BYREF

  if ( (_S8_10 & 1) == 0 )
    _S8_10 |= 1u;
  vOrigin_0 = *(Vector *)(*(int (__thiscall **)(char *))(*((_DWORD *)this - 1) + 40))(a1: (char *)this - 4);
  m_flHDRColorScale = this->C_Sprite::C_SpriteRenderer::m_flHDRColorScale;
  if ( m_flHDRColorScale != NAN )
  {
    v3 = LOWORD(m_flHDRColorScale);
    v4 = &g_pEntityList->m_EntPtrArray[LOWORD(m_flHDRColorScale)];
    v5 = HIWORD(LODWORD(m_flHDRColorScale));
    if ( v4->m_SerialNumber == v5 && v4->m_pEntity != nullptr )
    {
      v6 = v3;
      v7 = g_pEntityList->m_EntPtrArray[v6].m_SerialNumber == v5;
      v8 = &g_pEntityList->m_EntPtrArray[v6];
      if ( v7 )
        m_pEntity = v8->m_pEntity;
      else
        m_pEntity = nullptr;
      v10 = ((int (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[2].SetRefEHandle)(a1: m_pEntity);
      if ( v10 != 0 )
        (*(void (__thiscall **)(int, unsigned int, Vector *, QAngle *))(*(_DWORD *)(v10 + 4) + 140))(
          a1: v10 + 4,
          a2: this->m_hAttachedToEntity.m_Value.m_Index,
          a3: &vOrigin_0,
          a4: &dummyAngles);
    }
  }
  return &vOrigin_0;
}

//------------------------------------------------------------------------------
// Address: 0x101714D0
// Name: public: virtual void C_SpriteTrail::ClientThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_SpriteTrail::ClientThink(C_SpriteTrail *this)
{
  C_SpriteTrail *v1; // esi

  v1 = (C_SpriteTrail *)((char *)this - 12);
  C_SpriteTrail::UpdateTrail(this: (C_SpriteTrail *)((char *)this - 12));
  C_SpriteTrail::UpdateBoundingBox(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x101714F0
// Name: public: virtual int C_SpriteTrail::DrawModel(int,struct RenderableInstance_t const __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
int __userpurge C_SpriteTrail::DrawModel@<eax>(
        C_SpriteTrail *this@<ecx>,
        float a2@<ebp>,
        int flags,
        const RenderableInstance_t *instance)
{
  int m_Value; // edx
  C_SpriteTrail_vtbl *v6; // eax
  const struct model_t *v7; // eax
  IMatRenderContext *v8; // eax
  int v9; // ecx
  float *v10; // edi
  void (__thiscall *SetRefEHandle)(struct IClientUnknown *, const CBaseHandle *); // eax
  float *v12; // eax
  float v13; // xmm1_4
  float v14; // xmm2_4
  float m_flWidth; // xmm3_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm1_4
  __int128 v19; // xmm0
  RenderMode_t v20; // ecx
  float *v21; // edx
  float v22; // xmm4_4
  float *v23; // edi
  float v24; // xmm0_4
  __int128 v25; // xmm0
  int RenderBrightness; // eax
  float v27; // xmm2_4
  float v28; // xmm1_4
  float v29; // xmm0_4
  bool v30; // cf
  float v31; // xmm0_4
  int v32; // esi
  _DWORD v34[3]; // [esp-Ch] [ebp-2CCh] BYREF
  _BYTE segDraw_12[584]; // [esp+Ch] [ebp-2B4h] OVERLAPPED BYREF
  float v36[3]; // [esp+25Ch] [ebp-64h] BYREF
  TrailPoint_t currentPoint; // [esp+268h] [ebp-58h] BYREF
  BeamSeg_t curSeg; // [esp+280h] [ebp-40h]
  float flTailAlphaDist; // [esp+2A4h] [ebp-1Ch]
  CMatRenderContextPtr pRenderContext; // [esp+2A8h] [ebp-18h]
  RenderMode_t v41; // [esp+2ACh] [ebp-14h]
  __int16 model; // [esp+2B0h] [ebp-10h]
  char v43; // [esp+2B2h] [ebp-Eh]
  float flAlphaFade; // [esp+2B4h] [ebp-Ch] BYREF
  int i; // [esp+2B8h] [ebp-8h]
  int retaddr; // [esp+2C0h] [ebp+0h]

  flAlphaFade = a2;
  i = retaddr;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CSpriteTrail::DrawModel",
    a3: 0,
    a4: "Particle/Effect_Rendering",
    a5: false,
    a6: 4);
  if ( this->m_nFirstStep < 1 )
  {
LABEL_33:
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return 1;
  }
  if ( HIWORD(this->m_flOldSimulationTime) != 0xFFFF
    && (this->m_nOldRenderMode & 1) != 0
    && LOBYTE(this->m_VisibilityBits.m_Ints[0]) != 0 )
  {
    m_Value = (int)this->m_flSpriteFramerate.m_Value;
    v41 = (unsigned __int8)this->m_iName[259];
    v6 = this->C_Sprite::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
    pRenderContext.m_pObject = (IMatRenderContext *)m_Value;
    v7 = (const struct model_t *)v6->GetClientThinkable(this);
    *(float *)&pRenderContext.m_pObject = COERCE_FLOAT(
                                            Draw_SetSpriteTexture(
                                              a1: (int)this,
                                              pSpriteModel: v7,
                                              frame: (int)pRenderContext.m_pObject,
                                              rendermode: v41));
    if ( *(float *)&pRenderContext.m_pObject != 0.0 )
    {
      v8 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
      *((_DWORD *)&curSeg.m_flWidth + 1) = v8;
      if ( v8 != nullptr )
        v8->BeginRender(this: v8);
      v34[0] = &CBeamSegDraw::`vftable';
      CMeshBuilder::CMeshBuilder(this: (CMeshBuilder *)segDraw_12);
      v9 = (unsigned __int8)this->m_iName[259];
      v41 = kRenderNormal;
      *(_DWORD *)&segDraw_12[540] = 0;
      CBeamSegDraw::Start(
        this: (CBeamSegDraw *)v34,
        pRenderContext: *((IMatRenderContext **)&curSeg.m_flWidth + 1),
        nSegs: this->m_nFirstStep + 1,
        pMaterial: (IMaterial *)pRenderContext.m_pObject[v9 + 4].__vftable,
        pMeshBuilder: nullptr,
        nMeshVertCount: 0);
      v10 = (float *)(&this->m_bClientOnly
                    + 24
                    * (((unsigned __int8)LODWORD(this->m_vecSteps[63].m_flWidthVariance)
                      + (unsigned __int8)this->m_nFirstStep
                      - 1)
                     & 0x3F)
                    + 4);
      SetRefEHandle = this->SetRefEHandle;
      currentPoint.m_vecScreenPos.x = *(float *)(gpGlobals.m_Index + 12) + this->m_vecRenderMaxs.z;
      v12 = (float *)((int (__thiscall *)(C_SpriteTrail *))SetRefEHandle)(a1: this);
      v13 = v12[1];
      v14 = v12[2];
      m_flWidth = this->m_flTextureRes.m_Value;
      v36[0] = *v12;
      v16 = v36[0] - *v10;
      v36[1] = v13;
      v17 = v13 - v10[1];
      v36[2] = v14;
      v18 = (float)((float)(v17 * v17) + (float)((float)(v14 - v10[2]) * (float)(v14 - v10[2]))) + (float)(v16 * v16);
      v19 = 0;
      *(float *)&v19 = fsqrt(v18);
      *(_OWORD *)&segDraw_12[568] = v19;
      v20 = kRenderNormal;
      v21 = nullptr;
      currentPoint.m_vecScreenPos.y = (float)(this->m_flStartWidthVariance.m_Value * *(float *)&v19) + v10[4];
      currentPoint.m_vecScreenPos.z = 0.0;
      curSeg.m_flWidth = m_flWidth;
      v41 = kRenderNormal;
      if ( this->m_nFirstStep >= 0 )
      {
        while ( 1 )
        {
          v22 = 1.0;
          v23 = v20 == this->m_nFirstStep
              ? v36
              : (float *)(&this->m_bClientOnly
                        + 24 * (((_BYTE)v20 + (unsigned __int8)LODWORD(this->m_vecSteps[63].m_flWidthVariance)) & 0x3F)
                        + 4);
          v24 = (float)(v23[3] - *(float *)(gpGlobals.m_Index + 12)) / this->m_vecRenderMaxs.z;
          if ( v24 >= 0.0 )
          {
            if ( v24 <= 1.0 )
              v22 = (float)(v23[3] - *(float *)(gpGlobals.m_Index + 12)) / this->m_vecRenderMaxs.z;
          }
          else
          {
            v22 = 0.0;
          }
          model = (__int16)this->model;
          v43 = BYTE2(this->model);
          LOWORD(curSeg.m_vPos.y) = model;
          flTailAlphaDist = v22;
          BYTE2(curSeg.m_vPos.y) = v43;
          *(float *)&pRenderContext.m_pObject = v22;
          if ( m_flWidth > 0.0 )
          {
            if ( v21 != nullptr )
            {
              v25 = 0;
              *(float *)&v25 = fsqrt(
                                 (float)((float)((float)(v23[1] - v21[1]) * (float)(v23[1] - v21[1]))
                                       + (float)((float)(v23[2] - v21[2]) * (float)(v23[2] - v21[2])))
                               + (float)((float)(*v23 - *v21) * (float)(*v23 - *v21)));
              *(_OWORD *)&segDraw_12[568] = v25;
              m_flWidth = m_flWidth - *(float *)&v25;
              curSeg.m_flWidth = m_flWidth;
            }
            if ( m_flWidth > 0.0
              && v22 > (float)((float)(this->m_flTextureRes.m_Value - m_flWidth) / this->m_flTextureRes.m_Value) )
            {
              *(float *)&pRenderContext.m_pObject = (float)(this->m_flTextureRes.m_Value - m_flWidth)
                                                  / this->m_flTextureRes.m_Value;
            }
          }
          RenderBrightness = C_Sprite::GetRenderBrightness(this: (C_SpriteTrail *)((char *)this - 4));
          HIBYTE(curSeg.m_vPos.y) = (int)(float)((float)RenderBrightness * *(float *)&pRenderContext.m_pObject);
          v27 = *v23;
          v28 = v23[2];
          currentPoint.m_flTexCoord = v23[1];
          v29 = this->m_flStartWidth.m_Value;
          currentPoint.m_flDieTime = v27;
          v30 = v29 < 0.0;
          v31 = this->m_flLifeTime.m_Value;
          currentPoint.m_flWidthVariance = v28;
          if ( !v30 )
            v31 = (float)((float)(v31 - this->m_flStartWidth.m_Value) * flTailAlphaDist) + this->m_flStartWidth.m_Value;
          curSeg.m_vPos.w = v31;
          curSeg.m_vPos.w = v23[5] + v31;
          if ( curSeg.m_vPos.w < 0.0 )
            curSeg.m_vPos.w = 0.0;
          curSeg.m_vPos.z = v23[4];
          CBeamSegDraw::NextSeg(
            this: (CBeamSegDraw *)v34,
            a2: COERCE_FLOAT(&flAlphaFade),
            pSeg: (BeamSeg_t *)&currentPoint.m_flDieTime);
          if ( *(float *)(gpGlobals.m_Index + 12) >= v23[3] )
          {
            ++LODWORD(this->m_vecSteps[63].m_flWidthVariance);
            --v41;
            --this->m_nFirstStep;
          }
          v21 = v23;
          if ( ++v41 > this->m_nFirstStep )
            break;
          m_flWidth = curSeg.m_flWidth;
          v20 = v41;
        }
      }
      CBeamSegDraw::End(this: (CBeamSegDraw *)v34);
      CBeamSegDraw::~CBeamSegDraw(this: (CBeamSegDraw *)v34);
      v32 = *((_DWORD *)&curSeg.m_flWidth + 1);
      if ( *((_DWORD *)&curSeg.m_flWidth + 1) != 0 )
      {
        (*(void (__thiscall **)(_DWORD))(**((_DWORD **)&curSeg.m_flWidth + 1) + 12))(a1: *((_DWORD *)&curSeg.m_flWidth
                                                                                         + 1));
        (*(void (__thiscall **)(int))(*(_DWORD *)v32 + 4))(a1: v32);
      }
      goto LABEL_33;
    }
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10171910
// Name: public: C_SpriteTrail::C_SpriteTrail(void)
// Source: json
//------------------------------------------------------------------------------
C_SpriteTrail *__thiscall C_SpriteTrail::C_SpriteTrail(C_SpriteTrail *this)
{
  C_SpriteTrail *result; // eax

  C_Sprite::C_Sprite(this);
  this->m_nFirstStep = 0;
  this->m_nStepCount = 0;
  this->C_Sprite::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_SpriteTrail_vtbl *)&C_SpriteTrail::`vftable'{for `IClientUnknown'};
  this->C_Sprite::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_SpriteTrail::`vftable'{for `IClientRenderable'};
  this->C_Sprite::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_SpriteTrail::`vftable'{for `IClientNetworkable'};
  this->C_Sprite::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_SpriteTrail::`vftable'{for `IClientThinkable'};
  this->C_Sprite::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_SpriteTrail::`vftable'{for `C_BaseEntity'};
  this->C_Sprite::C_SpriteRenderer::__vftable = (C_SpriteRenderer_vtbl *)&C_SpriteTrail::`vftable'{for `C_SpriteRenderer'};
  if ( this->m_flStartWidthVariance.m_Value != 0.0 )
    this->m_flStartWidthVariance.m_Value = 0.0;
  if ( this->m_vecSkyboxOrigin.m_Value.x != 0.0
    || this->m_vecSkyboxOrigin.m_Value.y != 0.0
    || this->m_vecSkyboxOrigin.m_Value.z != 0.0 )
  {
    this->m_vecSkyboxOrigin.m_Value.x = 0.0;
    this->m_vecSkyboxOrigin.m_Value.y = 0.0;
    this->m_vecSkyboxOrigin.m_Value.z = 0.0;
  }
  if ( this->m_flSkyboxScale.m_Value != 1.0 )
    this->m_flSkyboxScale.m_Value = 1.0;
  result = this;
  if ( this->m_flEndWidth.m_Value != -1.0 )
    this->m_flEndWidth.m_Value = -1.0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10171A50
// Name: CC_SpriteTrailFactory
// Source: json
//------------------------------------------------------------------------------
C_SpriteTrail *__cdecl CC_SpriteTrailFactory()
{
  C_SpriteTrail *v0; // eax

  v0 = (C_SpriteTrail *)C_BaseEntity::operator new(stAllocateBlock: 0x1050u);
  if ( v0 != nullptr )
    return C_SpriteTrail::C_SpriteTrail(this: v0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1041C7F0
// Name: TrailPoint_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *TrailPoint_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<TrailPoint_t>();
  TrailPoint_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041C800
// Name: C_SpriteTrail_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *C_SpriteTrail_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<C_SpriteTrail>();
  C_SpriteTrail_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041C830
// Name: DT_SpriteTrail::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_SpriteTrail::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_SpriteTrail::g_RecvTable);
  return atexit(func: DT_SpriteTrail::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1041C850
// Name: DT_SpriteTrail::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_SpriteTrail::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_SpriteTrail::ignored>();
  DT_SpriteTrail::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041C890
// Name: C_SpriteTrail_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__
// Source: json
//------------------------------------------------------------------------------
void C_SpriteTrail_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__()
{
  C_SpriteTrail::m_PredMap.dataNumFields = 1;
  C_SpriteTrail::m_PredMap.dataDesc = (typedescription_t *)&unk_106503C4;
}

//------------------------------------------------------------------------------
// Address: 0x10433B50
// Name: DT_SpriteTrail::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_SpriteTrail::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_SpriteTrail::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10171A00
// Name: _C_SpriteTrail_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_SpriteTrail_CreateObject(int entnum, int serialNum)
{
  C_SpriteTrail *v2; // eax
  C_SpriteTrail *v3; // eax
  C_SpriteTrail *v4; // esi

  v2 = (C_SpriteTrail *)C_BaseEntity::operator new(stAllocateBlock: 0x1050u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_SpriteTrail::C_SpriteTrail(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x1041C810
// Name: _dynamic_initializer_for____g_C_SpriteTrailClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_SpriteTrailClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_SpriteTrailClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_SpriteTrailClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041C860
// Name: _dynamic_initializer_for__g_Cenv_spritetrailFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Cenv_spritetrailFoo__()
{
  CClassMap *ClassMap; // eax
  int result; // eax

  ClassMap = GetClassMap();
  result = ((int (__thiscall *)(CClassMap *, const char *, const char *, int, C_SpriteTrail *(__cdecl *)()))ClassMap->Add)(
             a1: ClassMap,
             a2: "env_spritetrail",
             a3: "C_SpriteTrail",
             a4: 4176,
             a5: CC_SpriteTrailFactory);
  __g_C_SpriteTrailClientClass.m_pMapClassname = "env_spritetrail";
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10433B60
// Name: _DataMapInit_TrailPoint_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_TrailPoint_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_29);
}

//------------------------------------------------------------------------------
// Address: 0x10433B70
// Name: _DataMapInit_C_SpriteTrail__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_C_SpriteTrail__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_30);
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x10329DD0
// Name: private: virtual struct datamap_t __near * CSpriteTrail::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CSpriteTrail::GetDataDescMap(CSpriteTrail *this)
{
  return &CSpriteTrail::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10329DE0
// Name: public: virtual class ServerClass __near * CSpriteTrail::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CSpriteTrail::GetServerClass(CSpriteTrail *this)
{
  return &g_CSpriteTrail_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x10329DF0
// Name: public: virtual void CSpriteTrail::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpriteTrail::Spawn(CSpriteTrail *this)
{
  _BYTE v2[4]; // [esp+4h] [ebp-4h] BYREF

  if ( *(_DWORD *)((int (__thiscall *)(CSpriteTrail *, _BYTE *))this->GetModelName)(a1: this, a2: v2) != 0 )
  {
    CSprite::Spawn(this);
  }
  else
  {
    this->m_ModelName.pszValue = this->m_iszSpriteName.pszValue;
    CBaseEntity::DispatchUpdateTransmitState(this);
    CSprite::Spawn(this);
    CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
    CBaseEntity::SetMoveType(this, val: MOVETYPE_NOCLIP, moveCollide: MOVECOLLIDE_DEFAULT);
    CBaseEntity::SetCollisionBounds(this, mins: &vec3_origin, maxs: &vec3_origin);
    CSprite::TurnOn(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10329E70
// Name: public: virtual void CSpriteTrail::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CSpriteTrail::Precache(CSpriteTrail *this@<ecx>, bool (__cdecl *a2)(const char *)@<edi>)
{
  const char *pszValue; // esi

  CWreckage::Precache((CEntityFreezing *)this, a2);
  pszValue = this->m_iszSpriteName.pszValue;
  if ( pszValue != nullptr )
    CBaseEntity::PrecacheModel(a1: a2, name: pszValue, bPreload: true);
}

//------------------------------------------------------------------------------
// Address: 0x10329E90
// Name: public: static class CSpriteTrail __near * CSpriteTrail::SpriteTrailCreate(char const __near *,class Vector const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
CSpriteTrail *__cdecl CSpriteTrail::SpriteTrailCreate(const char *pSpriteName, const Vector *origin, bool animate)
{
  IServerNetworkable *EntityByName; // eax
  CSprite *v4; // esi

  EntityByName = CreateEntityByName(className: "env_spritetrail", iForceEdictIndex: -1, bNotify: true);
  v4 = (CSprite *)__RTDynamicCast(
                    inptr: EntityByName,
                    VfDelta: 0,
                    SrcType: &CBaseEntity `RTTI Type Descriptor',
                    TargetType: &CSpriteTrail `RTTI Type Descriptor',
                    isReference: 0);
  if ( v4 == nullptr )
    _Warning(a1: "classname %s used to create wrong class type\n", "env_spritetrail");
  CSprite::SpriteInit(this: v4, pSpriteName, origin);
  CCollisionProperty::SetSolid(this: &v4->m_Collision, val: SOLID_NONE);
  CBaseEntity::SetMoveType(this: v4, val: MOVETYPE_NOCLIP, moveCollide: MOVECOLLIDE_DEFAULT);
  UTIL_SetSize(pEnt: v4, vecMin: &vec3_origin, vecMax: &vec3_origin);
  if ( animate )
    CSprite::TurnOn(this: v4);
  return (CSpriteTrail *)v4;
}

//------------------------------------------------------------------------------
// Address: 0x1032A1B0
// Name: public: CSpriteTrail::CSpriteTrail(void)
// Source: json
//------------------------------------------------------------------------------
CSpriteTrail *__thiscall CSpriteTrail::CSpriteTrail(CSpriteTrail *this)
{
  edict_t *m_pPev; // ecx
  edict_t *v3; // ecx
  edict_t *v4; // ecx
  CSpriteTrail *result; // eax
  edict_t *v6; // ecx

  CSprite::CSprite(this);
  this->__vftable = (CSpriteTrail_vtbl *)&CSpriteTrail::`vftable';
  if ( this->m_flStartWidthVariance.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x3B0u);
    }
    this->m_flStartWidthVariance.m_Value = 0.0;
  }
  if ( this->m_vecSkyboxOrigin.m_Value.x != 0.0
    || this->m_vecSkyboxOrigin.m_Value.y != 0.0
    || this->m_vecSkyboxOrigin.m_Value.z != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v3 = this->m_Network.m_pPev;
      if ( v3 != nullptr )
        CBaseEdict::StateChanged(this: &v3->CBaseEdict, offset: 0x3BCu);
    }
    this->m_vecSkyboxOrigin.m_Value.x = 0.0;
    this->m_vecSkyboxOrigin.m_Value.y = 0.0;
    this->m_vecSkyboxOrigin.m_Value.z = 0.0;
  }
  if ( this->m_flSkyboxScale.m_Value != 1.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v4 = this->m_Network.m_pPev;
      if ( v4 != nullptr )
        CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0x3C8u);
    }
    this->m_flSkyboxScale.m_Value = 1.0;
  }
  result = this;
  if ( this->m_flEndWidth.m_Value != -1.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v6 = this->m_Network.m_pPev;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: &v6->CBaseEdict, offset: 0x3ACu);
    }
    this->m_flEndWidth.m_Value = -1.0;
    return this;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1032A300
// Name: public: void CSpriteTrail::SetLifeTime(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpriteTrail::SetLifeTime(CSpriteTrail *this, float time)
{
  CNetworkVarBase<float,CSpriteTrail::NetworkVar_m_flLifeTime> *p_m_flLifeTime; // esi
  edict_t *m_pPev; // ecx

  p_m_flLifeTime = &this->m_flLifeTime;
  if ( this->m_flLifeTime.m_Value != time )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_flLifeTime->m_Value = time;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x3A4u);
      p_m_flLifeTime->m_Value = time;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1032A360
// Name: public: void CSpriteTrail::SetStartWidth(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpriteTrail::SetStartWidth(CSpriteTrail *this, float flStartWidth)
{
  edict_t *m_pPev; // ecx
  float v4; // xmm0_4
  edict_t *v5; // ecx

  if ( this->m_flStartWidth.m_Value != flStartWidth )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x3A8u);
    }
    this->m_flStartWidth.m_Value = flStartWidth;
  }
  v4 = this->m_flStartWidth.m_Value / this->m_flSkyboxScale.m_Value;
  if ( this->m_flStartWidth.m_Value != v4 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_flStartWidth.m_Value = v4;
    }
    else
    {
      v5 = this->m_Network.m_pPev;
      if ( v5 != nullptr )
        CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0x3A8u);
      this->m_flStartWidth.m_Value = v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1032A410
// Name: public: void CSpriteTrail::SetTextureResolution(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpriteTrail::SetTextureResolution(CSpriteTrail *this, float flTexelsPerInch)
{
  edict_t *m_pPev; // ecx
  float m_Value; // xmm1_4
  float v5; // xmm0_4
  edict_t *v6; // ecx

  if ( this->m_flTextureRes.m_Value != flTexelsPerInch )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x3B4u);
    }
    this->m_flTextureRes.m_Value = flTexelsPerInch;
  }
  m_Value = this->m_flTextureRes.m_Value;
  v5 = this->m_flSkyboxScale.m_Value * m_Value;
  if ( m_Value != v5 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_flTextureRes.m_Value = v5;
    }
    else
    {
      v6 = this->m_Network.m_pPev;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: &v6->CBaseEdict, offset: 0x3B4u);
      this->m_flTextureRes.m_Value = v5;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10415850
// Name: CSpriteTrail_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CSpriteTrail_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CSpriteTrail>();
  CSpriteTrail_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10415880
// Name: DT_SpriteTrail::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_SpriteTrail::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_SpriteTrail::g_SendTable);
  return atexit(func: DT_SpriteTrail::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104158A0
// Name: DT_SpriteTrail::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_SpriteTrail::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_SpriteTrail::ignored>();
  DT_SpriteTrail::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421D10
// Name: DT_SpriteTrail::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_SpriteTrail::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_SpriteTrail::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10415860
// Name: _dynamic_initializer_for__g_CSpriteTrail_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CSpriteTrail_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CSpriteTrail_ClassReg,
           pNetworkName: "CSpriteTrail",
           pTable: &DT_SpriteTrail::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x104158B0
// Name: _dynamic_initializer_for__env_spritetrail__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_spritetrail__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CSpriteTrail> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_spritetrail,
           a3: "env_spritetrail");
}

//------------------------------------------------------------------------------
// Address: 0x104158D0
// Name: _dynamic_initializer_for__g_CSteamJet_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CSteamJet_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CSteamJet_ClassReg,
           pNetworkName: "CSteamJet",
           pTable: &DT_SteamJet::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10421D20
// Name: _ServerClassInit_DT_SpriteTrail::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_SpriteTrail::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S3_171;
  for ( i = 9; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x10421D40
// Name: _DataMapInit_CSpriteTrail__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CSpriteTrail__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_514);
}

} // namespace server
