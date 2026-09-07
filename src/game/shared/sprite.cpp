// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/sprite.cpp
// Functions: 36
// ============================================================

#include "game\shared\sprite.h"

//------------------------------------------------------------------------------
// Address: 0x1016F2C0
// Name: public: virtual struct datamap_t __near * C_Sprite::GetPredDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall C_Sprite::GetPredDescMap(C_Sprite *this)
{
  return &C_Sprite::m_PredMap;
}

//------------------------------------------------------------------------------
// Address: 0x1016F2D0
// Name: public: virtual class ClientClass __near * C_Sprite::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_Sprite::GetClientClass(C_Sprite *this)
{
  return &__g_C_SpriteClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1016F2E0
// Name: public: virtual void C_Sprite::SetModel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_Sprite::SetModel(C_Sprite *this, const char *szModelName)
{
  int v3; // eax
  const struct model_t *v4; // eax
  const char *v5; // eax

  v3 = modelinfo->GetModelIndex(this: modelinfo, a2: szModelName);
  v4 = modelinfo->GetModel(this: modelinfo, a2: v3);
  if ( v4 != nullptr && modelinfo->GetModelType(this: modelinfo, a2: v4) != 2 )
  {
    v5 = szModelName;
    if ( szModelName == nullptr )
      v5 = "NULL";
    _Msg(a1: "Setting CSprite to non-sprite model %s\n", v5);
  }
  C_BaseEntity::SetModel(this, pModelName: szModelName);
}

//------------------------------------------------------------------------------
// Address: 0x1016F350
// Name: public: virtual void C_Sprite::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_Sprite::Precache(C_Sprite *this)
{
  const char *ModelName; // eax

  if ( C_BaseEntity::GetModelName(this) != nullptr )
  {
    ModelName = C_BaseEntity::GetModelName(this);
    C_BaseEntity::PrecacheModel(name: ModelName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016F370
// Name: public: virtual class ClientClass __near * C_SpriteOriented::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_SpriteOriented::GetClientClass(C_SpriteOriented *this)
{
  return &__g_C_SpriteOrientedClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1016F3F0
// Name: public: virtual void C_Sprite::ComputeWorldSpaceSurroundingBox(class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_Sprite::ComputeWorldSpaceSurroundingBox(C_Sprite *this, Vector *pVecWorldMins, Vector *pVecWorldMaxs)
{
  float v4; // xmm0_4
  IVModelInfoClient_vtbl *v5; // edi
  const struct model_t *v6; // eax
  int v7; // eax
  IVModelInfoClient_vtbl *v8; // edi
  const struct model_t *v9; // eax
  float v10; // xmm0_4
  const Vector *v11; // eax
  const Vector *v12; // eax
  float flScale; // [esp+4h] [ebp-8h]
  float width; // [esp+8h] [ebp-4h]

  v4 = this->m_flSpriteScale.m_Value * 0.5;
  flScale = v4;
  if ( !this->m_bWorldSpaceScale.m_Value )
  {
    v5 = modelinfo->__vftable;
    v6 = this->GetModel(this: &this->IClientRenderable);
    v7 = v5->GetModelSpriteWidth(this: modelinfo, a2: v6);
    v8 = modelinfo->__vftable;
    width = (float)v7;
    v9 = this->GetModel(this: &this->IClientRenderable);
    v10 = (float)v8->GetModelSpriteHeight(this: modelinfo, a2: v9);
    if ( width > v10 )
      v10 = width;
    v4 = v10 * flScale;
  }
  LODWORD(pVecWorldMins->x) = LODWORD(v4) ^ _mask__NegFloat_;
  LODWORD(pVecWorldMins->y) = LODWORD(v4) ^ _mask__NegFloat_;
  LODWORD(pVecWorldMins->z) = LODWORD(v4) ^ _mask__NegFloat_;
  pVecWorldMaxs->x = v4;
  pVecWorldMaxs->y = v4;
  pVecWorldMaxs->z = v4;
  v11 = this->GetAbsOrigin(this);
  pVecWorldMins->x = pVecWorldMins->x + v11->x;
  pVecWorldMins->y = v11->y + pVecWorldMins->y;
  pVecWorldMins->z = v11->z + pVecWorldMins->z;
  v12 = this->GetAbsOrigin(this);
  pVecWorldMaxs->x = pVecWorldMaxs->x + v12->x;
  pVecWorldMaxs->y = v12->y + pVecWorldMaxs->y;
  pVecWorldMaxs->z = v12->z + pVecWorldMaxs->z;
}

//------------------------------------------------------------------------------
// Address: 0x1016F520
// Name: public: float C_Sprite::GetRenderScale(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_Sprite::GetRenderScale(C_Sprite *this)
{
  float m_Value; // xmm2_4
  float m_flScaleTimeStart; // [esp+4h] [ebp-8h]

  m_Value = this->m_flScaleTime.m_Value;
  if ( m_Value == 0.0 )
    return this->m_flSpriteScale.m_Value;
  m_flScaleTimeStart = this->m_flScaleTimeStart;
  if ( *(float *)(gpGlobals.m_Index + 12) > (float)(m_flScaleTimeStart + m_Value) )
    return this->m_flSpriteScale.m_Value;
  else
    return this->m_flStartScale
         + (*(float *)(gpGlobals.m_Index + 12) - m_flScaleTimeStart)
         / this->m_flScaleTime.m_Value
         * (this->m_flDestScale - this->m_flStartScale);
}

//------------------------------------------------------------------------------
// Address: 0x1016F590
// Name: public: virtual void C_Sprite::GetRenderBounds(class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_Sprite::GetRenderBounds(C_Sprite *this, Vector *vecMins, Vector *vecMaxs)
{
  float m_Value; // xmm1_4
  float v4; // xmm1_4
  IVModelInfoClient_vtbl *v5; // esi
  IClientThinkable *v6; // eax
  int v7; // eax
  int v8; // ecx
  int v9; // eax

  if ( this->m_flSpriteScale.m_Value == 0.0 )
  {
    m_Value = this->m_flBrightnessTime.m_Value;
  }
  else
  {
    m_Value = this->m_flStartScale;
    if ( this->m_flMaxFrame > m_Value )
      m_Value = this->m_flMaxFrame;
  }
  v4 = m_Value * 0.5;
  if ( LOBYTE(this->m_flScaleTime.m_Value) == 0 )
  {
    v5 = modelinfo->__vftable;
    v6 = this->GetClientThinkable(this);
    v7 = (int)v5->GetModelExtraData(this: modelinfo, a2: (const struct model_t *)v6);
    if ( v7 != 0 )
    {
      v8 = *(_DWORD *)(v7 + 8);
      v9 = *(_DWORD *)(v7 + 4);
      if ( v9 <= v8 )
        v9 = v8;
      v4 = (float)v9 * v4;
    }
  }
  LODWORD(vecMins->x) = LODWORD(v4) ^ _mask__NegFloat_;
  LODWORD(vecMins->y) = LODWORD(v4) ^ _mask__NegFloat_;
  LODWORD(vecMins->z) = LODWORD(v4) ^ _mask__NegFloat_;
  vecMaxs->x = v4;
  vecMaxs->y = v4;
  vecMaxs->z = v4;
}

//------------------------------------------------------------------------------
// Address: 0x1016F660
// Name: public: int C_Sprite::GetRenderBrightness(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_Sprite::GetRenderBrightness(C_Sprite *this)
{
  float m_Value; // xmm2_4
  float v2; // xmm0_4

  m_Value = this->m_flBrightnessTime.m_Value;
  if ( m_Value == 0.0 )
    return this->m_nBrightness.m_Value;
  v2 = *(float *)(gpGlobals.m_Index + 12);
  if ( v2 > (float)(this->m_flBrightnessTimeStart + m_Value) )
    return this->m_nBrightness.m_Value;
  else
    return (int)(float)((float)((float)((float)(v2 - this->m_flBrightnessTimeStart) / m_Value)
                              * (float)(this->m_nDestBrightness - this->m_nStartBrightness))
                      + (float)this->m_nStartBrightness);
}

//------------------------------------------------------------------------------
// Address: 0x1016F6D0
// Name: public: virtual void C_Sprite::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_Sprite::OnDataChanged(C_Sprite *this, DataUpdateType_t updateType)
{
  float m_Value; // eax
  int v4; // xmm0_4
  int v5; // xmm0_4

  C_BaseEntity::OnDataChanged(this, type: updateType);
  if ( updateType == DATA_UPDATE_CREATED )
  {
    m_Value = this->m_flFrame.m_Value;
    v4 = this->m_nBrightness.m_Value;
    LODWORD(this->m_flMaxFrame) = v4;
    LODWORD(this->m_flLastTime) = v4;
    this->m_flScaleTimeStart = m_Value;
    this->m_flDestScale = m_Value;
  }
  C_BaseEntity::UpdateVisibility(this: (C_Sprite *)((char *)this - 8));
  if ( *(float *)&this->m_nBrightness.m_Value == this->m_flMaxFrame
    && LODWORD(this->m_flFrame.m_Value) == LODWORD(this->m_flScaleTimeStart) )
  {
    v5 = -1082130432;
  }
  else
  {
    v5 = -996040704;
  }
  (*(void (__thiscall **)(char *, int))(*((_DWORD *)this - 2) + 456))(a1: (char *)this - 8, a2: v5);
}

//------------------------------------------------------------------------------
// Address: 0x1016F770
// Name: public: virtual void C_Sprite::ClientThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_Sprite::ClientThink(C_Sprite *this)
{
  float m_flDieTime; // xmm0_4
  float m_flLastTime; // xmm1_4
  char v3; // bl
  float m_Value; // eax
  float m_flDestScale; // edx
  char *v6; // esi

  m_flDieTime = this->m_flDieTime;
  m_flLastTime = this->m_flLastTime;
  v3 = 1;
  if ( m_flDieTime != m_flLastTime )
  {
    this->m_flHDRColorScale.m_Value = m_flLastTime;
    this->m_flLastTime = m_flDieTime;
    v3 = 0;
    this->m_flMaxFrame = *(float *)(gpGlobals.m_Index + 12);
  }
  m_Value = this->m_flSpriteFramerate.m_Value;
  m_flDestScale = this->m_flDestScale;
  if ( LODWORD(m_Value) != LODWORD(m_flDestScale) )
  {
    this->m_flStartScale = m_flDestScale;
    this->m_flDestScale = m_Value;
    v3 = 0;
    this->m_flScaleTimeStart = *(float *)(gpGlobals.m_Index + 12);
  }
  v6 = (char *)this - 12;
  C_BaseEntity::InvalidatePhysicsRecursive(this: (C_Sprite *)((char *)this - 12), nChangeFlags: 16);
  if ( v3 != 0 )
    (*(void (__thiscall **)(char *, int))(*(_DWORD *)v6 + 456))(a1: v6, a2: -1082130432);
}

//------------------------------------------------------------------------------
// Address: 0x1016F810
// Name: public: virtual class Vector const __near & C_Sprite::GetRenderOrigin(void)
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall C_Sprite::GetRenderOrigin(C_Sprite *this)
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

  if ( (_S6_40 & 1) == 0 )
    _S6_40 |= 1u;
  vOrigin = *(Vector *)(*(int (__thiscall **)(char *))(*((_DWORD *)this - 1) + 40))(a1: (char *)this - 4);
  m_flHDRColorScale = this->C_SpriteRenderer::m_flHDRColorScale;
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
          a3: &vOrigin,
          a4: &dummyAngles);
    }
  }
  return &vOrigin;
}

//------------------------------------------------------------------------------
// Address: 0x1016F8E0
// Name: public: virtual int C_Sprite::DrawModel(int,struct RenderableInstance_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_Sprite::DrawModel(C_Sprite *this, int flags, const RenderableInstance_t *instance)
{
  char *v4; // edi
  unsigned int m_nSplitUserPlayerPredictionSlot; // ecx
  IHandleEntity *m_pEntity; // eax
  int v7; // eax
  IVModelInfoClient_vtbl *v9; // ebx
  IClientThinkable *v10; // eax
  IVModelInfoClient_vtbl *v11; // edi
  IClientThinkable *v12; // eax
  int v13; // ebx
  IClientThinkable *v14; // eax
  int v15; // eax
  int v16; // eax
  IVModelInfoClient_vtbl *v17; // ebx
  IClientThinkable *v18; // eax
  int v19; // eax
  int v20; // ecx
  int v21; // eax
  float v22; // xmm0_4
  RenderMode_t v23; // ebx
  const struct model_t *v24; // eax
  int v25; // esi
  const Vector *v26; // [esp+10h] [ebp-148h]
  const QAngle *v27; // [esp+14h] [ebp-144h]
  float frame; // [esp+18h] [ebp-140h]
  C_BaseCombatWeapon *v29; // [esp+1Ch] [ebp-13Ch]
  unsigned int m_Index; // [esp+20h] [ebp-138h]
  int v31; // [esp+28h] [ebp-130h]
  int v32; // [esp+2Ch] [ebp-12Ch]
  int model_low; // [esp+30h] [ebp-128h]
  int v34; // [esp+34h] [ebp-124h]
  int v35; // [esp+38h] [ebp-120h]
  const char *scale; // [esp+3Ch] [ebp-11Ch]
  int flHDRColorScale; // [esp+40h] [ebp-118h]
  float flHDRColorScalea; // [esp+40h] [ebp-118h]
  char msg[256]; // [esp+50h] [ebp-108h] BYREF
  float renderscale; // [esp+150h] [ebp-8h]
  IVModelInfoClient_vtbl *instancea; // [esp+164h] [ebp+Ch]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CSprite::DrawModel",
    a3: 0,
    a4: "Particle/Effect_Rendering",
    a5: false,
    a6: 4);
  v4 = (char *)this - 4;
  if ( HIWORD(this->m_flOldSimulationTime) == 0xFFFF
    || (v4[616] & 1) == 0
    || LOBYTE(this->m_VisibilityBits.m_Ints[0]) == 0
    || (g_bRenderingScreenshot
     || r_drawviewmodel.m_pParent == nullptr
     || r_drawviewmodel.m_pParent->m_Value.m_nValue == 0)
    && (m_nSplitUserPlayerPredictionSlot = this->m_nSplitUserPlayerPredictionSlot) != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_nSplitUserPlayerPredictionSlot].m_SerialNumber == HIWORD(m_nSplitUserPlayerPredictionSlot)
    && (m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_nSplitUserPlayerPredictionSlot].m_pEntity) != nullptr
    && (v7 = (int)m_pEntity->__vftable[14].GetRefEHandle(this: m_pEntity)) != 0
    && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v7 + 844))(a1: v7) != 0 )
  {
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return 0;
  }
  else
  {
    v9 = modelinfo->__vftable;
    v10 = this->GetClientThinkable(this);
    if ( v9->GetModelType(this: modelinfo, a2: (const struct model_t *)v10) == 2 )
    {
      renderscale = C_Sprite::GetRenderScale(this: (C_Sprite *)((char *)this - 4));
      if ( LOBYTE(this->m_flScaleTime.m_Value) != 0 )
      {
        v17 = modelinfo->__vftable;
        v18 = this->GetClientThinkable(this);
        v19 = (int)v17->GetModelExtraData(this: modelinfo, a2: (const struct model_t *)v18);
        v20 = *(_DWORD *)(v19 + 8);
        v21 = *(_DWORD *)(v19 + 4);
        if ( v21 >= v20 )
          v21 = v20;
        v22 = renderscale / (float)v21;
      }
      else
      {
        v22 = renderscale;
      }
      v23 = (unsigned __int8)this->m_iName[259];
      flHDRColorScalea = this->m_flGlowProxySize.m_Value;
      v35 = BYTE2(this->model);
      v34 = BYTE1(this->model);
      model_low = LOBYTE(this->model);
      v32 = (int)(float)((float)((float)(instance->m_nAlpha
                                       * C_Sprite::GetRenderBrightness(this: (C_Sprite *)((char *)this - 4)))
                               * 0.0039215689)
                       + 0.5);
      v31 = (unsigned __int8)this->m_iName[258];
      m_Index = this->m_hAttachedToEntity.m_Value.m_Index;
      v29 = CHandle<C_PointCommentaryNode>::operator C_PointCommentaryNode *(this: (CHandle<C_BaseCombatWeapon> *)&this->C_SpriteRenderer::m_flHDRColorScale);
      frame = this->m_flSpriteFramerate.m_Value;
      v27 = (const QAngle *)(*(int (__thiscall **)(char *))(*(_DWORD *)v4 + 44))(a1: (char *)this - 4);
      v26 = (const Vector *)(*(int (__thiscall **)(char *))(*(_DWORD *)v4 + 40))(a1: (char *)this - 4);
      v24 = (const struct model_t *)this->GetClientThinkable(this);
      v25 = C_SpriteRenderer::DrawSprite(
              this: (C_SpriteRenderer *)(&this->m_bIsBlurred + 4),
              a2: v23,
              entity: (C_Sprite *)((char *)this - 4),
              model: v24,
              origin: v26,
              angles: v27,
              frame,
              attachedto: v29,
              attachmentindex: m_Index,
              rendermode: v23,
              renderfx: v31,
              alpha: v32,
              r: model_low,
              g: v34,
              b: v35,
              scale: v22,
              flHDRColorScale: flHDRColorScalea);
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      return v25;
    }
    else
    {
      v11 = modelinfo->__vftable;
      v12 = this->GetClientThinkable(this);
      v13 = (int)v11->GetModelName(this: modelinfo, a2: (const struct model_t *)v12);
      instancea = modelinfo->__vftable;
      v14 = this->GetClientThinkable(this);
      v15 = instancea->GetModelType(this: modelinfo, a2: (const struct model_t *)v14);
      v16 = ((int (__thiscall *)(IClientRenderable *, int, int))this->GetBody)(
              a1: &this->IClientRenderable,
              a2: v13,
              a3: v15);
      V_snprintf(
        pDest: msg,
        maxLen: 0x100u,
        pFormat: "Sprite %d has non-mod_sprite model %s (type %d)\n",
        v16,
        scale,
        flHDRColorScale);
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016FB70
// Name: public: C_Sprite::C_Sprite(void)
// Source: json
//------------------------------------------------------------------------------
C_Sprite *__thiscall C_Sprite::C_Sprite(C_Sprite *this)
{
  C_Sprite *result; // eax

  C_BaseEntity::C_BaseEntity(this);
  this->C_SpriteRenderer::__vftable = (C_SpriteRenderer_vtbl *)&C_SpriteRenderer::`vftable';
  this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_Sprite_vtbl *)&C_Sprite::`vftable'{for `IClientUnknown'};
  this->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_Sprite::`vftable'{for `IClientRenderable'};
  this->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_Sprite::`vftable'{for `IClientNetworkable'};
  this->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_Sprite::`vftable'{for `IClientThinkable'};
  this->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_Sprite::`vftable'{for `C_BaseEntity'};
  this->C_SpriteRenderer::__vftable = (C_SpriteRenderer_vtbl *)&C_Sprite::`vftable'{for `C_SpriteRenderer'};
  this->m_hAttachedToEntity.m_Value.m_Index = -1;
  this->m_bClientOnly = false;
  if ( this->m_flGlowProxySize.m_Value != 2.0 )
    this->m_flGlowProxySize.m_Value = 2.0;
  result = this;
  if ( this->m_flHDRColorScale.m_Value != 1.0 )
    this->m_flHDRColorScale.m_Value = 1.0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1016FC10
// Name: public: virtual C_Sprite::~C_Sprite(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_Sprite::~C_Sprite(C_Sprite *this)
{
  bool v1; // zf
  int m_Size; // edx
  int v3; // eax

  v1 = !this->m_bClientOnly;
  this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_Sprite_vtbl *)&C_Sprite::`vftable'{for `IClientUnknown'};
  this->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_Sprite::`vftable'{for `IClientRenderable'};
  this->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_Sprite::`vftable'{for `IClientNetworkable'};
  this->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_Sprite::`vftable'{for `IClientThinkable'};
  this->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_Sprite::`vftable'{for `C_BaseEntity'};
  this->C_SpriteRenderer::__vftable = (C_SpriteRenderer_vtbl *)&C_Sprite::`vftable'{for `C_SpriteRenderer'};
  if ( !v1 )
  {
    m_Size = g_ClientsideSprites.m_Size;
    v3 = 0;
    if ( g_ClientsideSprites.m_Size > 0 )
    {
      while ( g_ClientsideSprites.m_Memory.m_pMemory[v3] != this )
      {
        if ( ++v3 >= g_ClientsideSprites.m_Size )
          goto LABEL_11;
      }
      if ( v3 != -1 && g_ClientsideSprites.m_Size > 0 )
      {
        if ( v3 != g_ClientsideSprites.m_Size - 1 )
        {
          g_ClientsideSprites.m_Memory.m_pMemory[v3] = g_ClientsideSprites.m_Memory.m_pMemory[g_ClientsideSprites.m_Size
                                                                                            - 1];
          m_Size = g_ClientsideSprites.m_Size;
        }
        g_ClientsideSprites.m_Size = m_Size - 1;
      }
    }
  }
LABEL_11:
  C_BaseEntity::~C_BaseEntity(this);
}

//------------------------------------------------------------------------------
// Address: 0x1016FCA0
// Name: public: void C_Sprite::SetBrightness(int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_Sprite::SetBrightness(C_Sprite *this, int brightness, float time)
{
  if ( this->m_nBrightness.m_Value != brightness )
    this->m_nBrightness.m_Value = brightness;
  if ( this->m_flBrightnessTime.m_Value != time )
    this->m_flBrightnessTime.m_Value = time;
}

//------------------------------------------------------------------------------
// Address: 0x1016FCE0
// Name: public: void C_Sprite::SetScale(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_Sprite::SetScale(C_Sprite *this, float scale, float time)
{
  if ( this->m_flScaleTime.m_Value != time )
    this->m_flScaleTime.m_Value = time;
  if ( scale != this->m_flSpriteScale.m_Value )
  {
    this->m_flSpriteScale.m_Value = scale;
    CCollisionProperty::MarkSurroundingBoundsDirty(this: &this->m_Collision);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016FD40
// Name: CC_SpriteOrientedFactory
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__cdecl CC_SpriteOrientedFactory()
{
  C_Sprite *v0; // eax
  _DWORD *v1; // esi

  v0 = (C_Sprite *)C_BaseEntity::operator new(stAllocateBlock: 0x9E8u);
  v1 = &v0->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v0 == nullptr )
    return nullptr;
  C_Sprite::C_Sprite(this: v0);
  *v1 = &C_SpriteOriented::`vftable'{for `IClientUnknown'};
  v1[1] = &C_SpriteOriented::`vftable'{for `IClientRenderable'};
  v1[2] = &C_SpriteOriented::`vftable'{for `IClientNetworkable'};
  v1[3] = &C_SpriteOriented::`vftable'{for `IClientThinkable'};
  v1[4] = &C_SpriteOriented::`vftable'{for `C_BaseEntity'};
  v1[608] = &C_SpriteOriented::`vftable'{for `C_SpriteRenderer'};
  return (C_BaseEntity *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x1016FDE0
// Name: RecvProxy_SpriteScale
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvProxy_SpriteScale(const CRecvProxyData *pData, char *pStruct)
{
  float m_Float; // xmm0_4

  m_Float = pData->m_Value.m_Float;
  if ( m_Float != *((float *)pStruct + 619) )
  {
    *((float *)pStruct + 619) = m_Float;
    CCollisionProperty::MarkSurroundingBoundsDirty(this: (CCollisionProperty *)(pStruct + 780));
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016FFE0
// Name: CC_SpriteFactory
// Source: json
//------------------------------------------------------------------------------
C_Sprite *__cdecl CC_SpriteFactory()
{
  C_Sprite *v0; // eax

  v0 = (C_Sprite *)C_BaseEntity::operator new(stAllocateBlock: 0x9E8u);
  if ( v0 != nullptr )
    return C_Sprite::C_Sprite(this: v0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10170000
// Name: public: void C_Sprite::AnimateThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_Sprite::AnimateThink(C_Sprite *this)
{
  unsigned int m_Index; // edi
  float m_Value; // xmm1_4
  float v4; // xmm0_4
  float m_flMaxFrame; // xmm0_4
  long double v6; // st7
  float v7; // [esp+10h] [ebp-8h]

  m_Index = gpGlobals.m_Index;
  m_Value = this->m_flFrame.m_Value;
  v4 = (float)((float)(*(float *)(gpGlobals.m_Index + 12) - this->m_flLastTime) * this->m_flSpriteFramerate.m_Value)
     + m_Value;
  if ( m_Value != v4 )
    this->m_flFrame.m_Value = v4;
  m_flMaxFrame = this->m_flMaxFrame;
  if ( this->m_flFrame.m_Value > m_flMaxFrame && m_flMaxFrame > 0.0 )
  {
    v6 = fmod(this->m_flFrame.m_Value, this->m_flMaxFrame);
    if ( this->m_flFrame.m_Value != v6 )
    {
      v7 = v6;
      this->m_flFrame.m_Value = v7;
    }
  }
  C_BaseEntity::SetNextThink(this, thinkTime: *(float *)(m_Index + 12), szContext: nullptr);
  this->m_flLastTime = *(float *)(gpGlobals.m_Index + 12);
}

//------------------------------------------------------------------------------
// Address: 0x101700C0
// Name: public: void C_Sprite::TurnOn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_Sprite::TurnOn(C_Sprite *this)
{
  _QWORD v2[2]; // [esp+Ch] [ebp-10h] BYREF

  this->m_fEffects &= ~0x20u;
  C_BaseEntity::UpdateVisibility(this);
  C_BaseEntity::OnDisableShadowDepthRenderingChanged(this);
  C_BaseEntity::OnShadowDepthRenderingCacheableStateChanged(this);
  if ( this->m_flSpriteFramerate.m_Value != 0.0 && this->m_flMaxFrame > 1.0 )
  {
    LODWORD(v2[0]) = C_Sprite::AnimateThink;
    HIDWORD(v2[0]) = 0;
    v2[1] = 0;
    C_BaseEntity::ThinkSet(
      this,
      a2: (int)v2,
      func: (unsigned int)C_Sprite::AnimateThink,
      thinkTime: 0.0,
      szContext: nullptr);
    C_BaseEntity::SetNextThink(this, thinkTime: *(float *)(gpGlobals.m_Index + 12), szContext: nullptr);
    this->m_flLastTime = *(float *)(gpGlobals.m_Index + 12);
  }
  if ( this->m_flFrame.m_Value != 0.0 )
    this->m_flFrame.m_Value = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10170210
// Name: public: virtual void C_Sprite::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_Sprite::Spawn(C_Sprite *this)
{
  C_Sprite_vtbl *v2; // edi
  const char *ModelName; // eax
  IVModelInfoClient_vtbl *v4; // edi
  const struct model_t *v5; // eax
  float m_Value; // xmm0_4
  unsigned __int8 RenderAlpha; // al
  int v8; // eax
  float v9; // xmm0_4
  QAngle angles; // [esp+8h] [ebp-10h] BYREF
  float scale; // [esp+14h] [ebp-4h]

  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
  C_BaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
  if ( this->m_flFrame.m_Value != 0.0 )
    this->m_flFrame.m_Value = 0.0;
  this->Precache(this);
  v2 = this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  ModelName = C_BaseEntity::GetModelName(this);
  v2->SetModel(this, a2: ModelName);
  CCollisionProperty::SetSurroundingBoundsType(
    this: &this->m_Collision,
    type: USE_GAME_CODE,
    pMins: nullptr,
    pMaxs: nullptr);
  v4 = modelinfo->__vftable;
  v5 = this->GetModel(this: &this->IClientRenderable);
  this->m_flMaxFrame = (float)v4->GetModelFrameCount(this: modelinfo, a2: v5) - 1.0;
  C_BaseEntity::AddEffects(this, nEffects: 80);
  C_Sprite::TurnOn(this);
  if ( C_BaseEntity::GetLocalAngles(this)->y != 0.0 && C_BaseEntity::GetLocalAngles(this)->z == 0.0 )
  {
    *(_QWORD *)&angles.x = *(_QWORD *)&C_BaseEntity::GetLocalAngles(this)->x;
    angles.z = angles.y;
    angles.y = 0.0;
    C_BaseEntity::SetLocalAngles(this, &angles);
  }
  scale = this->m_flSpriteScale.m_Value;
  if ( scale < 0.0 || scale > 64.0 )
  {
    m_Value = this->m_flSpriteScale.m_Value;
    if ( m_Value >= 0.0 )
    {
      if ( m_Value <= 64.0 )
        scale = this->m_flSpriteScale.m_Value;
      else
        scale = 64.0;
    }
    else
    {
      scale = 0.0;
    }
  }
  RenderAlpha = C_BaseEntity::GetRenderAlpha(this);
  if ( this->m_nBrightness.m_Value != RenderAlpha )
    this->m_nBrightness.m_Value = RenderAlpha;
  if ( this->m_flBrightnessTime.m_Value != 0.0 )
    this->m_flBrightnessTime.m_Value = 0.0;
  if ( this->m_flScaleTime.m_Value != 0.0 )
    this->m_flScaleTime.m_Value = 0.0;
  if ( scale != this->m_flSpriteScale.m_Value )
  {
    this->m_flSpriteScale.m_Value = scale;
    CCollisionProperty::MarkSurroundingBoundsDirty(this: &this->m_Collision);
  }
  v8 = this->m_nBrightness.m_Value;
  v9 = this->m_flSpriteScale.m_Value;
  this->m_flDestScale = v9;
  this->m_flStartScale = v9;
  this->m_nDestBrightness = v8;
  this->m_nStartBrightness = v8;
}

//------------------------------------------------------------------------------
// Address: 0x1041C6D0
// Name: C_Sprite_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__
// Source: json
//------------------------------------------------------------------------------
void C_Sprite_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__()
{
  C_Sprite::m_PredMap.dataNumFields = 11;
  C_Sprite::m_PredMap.dataDesc = (typedescription_t *)&unk_105AA73C;
}

//------------------------------------------------------------------------------
// Address: 0x1041C710
// Name: DT_Sprite::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_Sprite::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_Sprite::g_RecvTable);
  return atexit(func: DT_Sprite::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1041C730
// Name: DT_Sprite::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_Sprite::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_Sprite::ignored>();
  DT_Sprite::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041C790
// Name: DT_SpriteOriented::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_SpriteOriented::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_SpriteOriented::g_RecvTable);
  return atexit(func: DT_SpriteOriented::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1041C7B0
// Name: DT_SpriteOriented::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_SpriteOriented::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_SpriteOriented::ignored>();
  DT_SpriteOriented::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10433B30
// Name: DT_Sprite::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_Sprite::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_Sprite::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10433B40
// Name: DT_SpriteOriented::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_SpriteOriented::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_SpriteOriented::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x1016FD90
// Name: _C_Sprite_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_Sprite_CreateObject(int entnum, int serialNum)
{
  C_Sprite *v2; // eax
  C_Sprite *v3; // eax
  C_Sprite *v4; // esi

  v2 = (C_Sprite *)C_BaseEntity::operator new(stAllocateBlock: 0x9E8u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_Sprite::C_Sprite(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x101701A0
// Name: _C_SpriteOriented_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_SpriteOriented_CreateObject(int entnum, int serialNum)
{
  C_Sprite *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_Sprite *)C_BaseEntity::operator new(stAllocateBlock: 0x9E8u);
  v3 = &v2->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_Sprite::C_Sprite(this: v2);
  *v3 = &C_SpriteOriented::`vftable'{for `IClientUnknown'};
  v3[1] = &C_SpriteOriented::`vftable'{for `IClientRenderable'};
  v3[2] = &C_SpriteOriented::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_SpriteOriented::`vftable'{for `IClientThinkable'};
  v3[4] = &C_SpriteOriented::`vftable'{for `C_BaseEntity'};
  v3[608] = &C_SpriteOriented::`vftable'{for `C_SpriteRenderer'};
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x1041C6F0
// Name: _dynamic_initializer_for____g_C_SpriteClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_SpriteClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_SpriteClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_SpriteClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041C740
// Name: _dynamic_initializer_for__g_Cenv_spriteFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Cenv_spriteFoo__()
{
  CClassMap *ClassMap; // eax
  int result; // eax

  ClassMap = GetClassMap();
  result = ((int (__thiscall *)(CClassMap *, const char *, const char *, int, C_Sprite *(__cdecl *)()))ClassMap->Add)(
             a1: ClassMap,
             a2: "env_sprite",
             a3: "C_Sprite",
             a4: 2536,
             a5: CC_SpriteFactory);
  __g_C_SpriteClientClass.m_pMapClassname = "env_sprite";
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041C770
// Name: _dynamic_initializer_for____g_C_SpriteOrientedClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_SpriteOrientedClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_SpriteOrientedClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_SpriteOrientedClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041C7C0
// Name: _dynamic_initializer_for__g_Cenv_sprite_orientedFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Cenv_sprite_orientedFoo__()
{
  CClassMap *ClassMap; // eax
  int result; // eax

  ClassMap = GetClassMap();
  result = ((int (__thiscall *)(CClassMap *, const char *, const char *, int, C_BaseEntity *(__cdecl *)()))ClassMap->Add)(
             a1: ClassMap,
             a2: "env_sprite_oriented",
             a3: "C_SpriteOriented",
             a4: 2536,
             a5: CC_SpriteOrientedFactory);
  __g_C_SpriteOrientedClientClass.m_pMapClassname = "env_sprite_oriented";
  return result;
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x100E0110
// Name: public: void CSprite::InputColorGreenValue(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSprite::InputColorGreenValue(CBeam *this, inputdata_t *inputdata)
{
  float flVal; // xmm0_4
  int v3; // xmm1_4

  if ( inputdata->value.fieldType == FIELD_FLOAT )
  {
    flVal = inputdata->value.flVal;
    v3 = 0;
    if ( flVal < 0.0 || (v3 = 1132396544, flVal > 255.0) )
      flVal = *(float *)&v3;
  }
  else
  {
    flVal = 0.0;
  }
  CNetworkColor32Base<color32_s,CBaseEntity::NetworkVar_m_clrRender>::Init(
    this: &this->m_clrRender,
    rVal: this->m_clrRender.m_Value.r,
    gVal: (int)flVal,
    bVal: this->m_clrRender.m_Value.b);
}

//------------------------------------------------------------------------------
// Address: 0x10223210
// Name: public: virtual struct datamap_t __near * CSprite::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CSprite::GetDataDescMap(CSprite *this)
{
  return &CSprite::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10223220
// Name: public: virtual class ServerClass __near * CSprite::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CSprite::GetServerClass(CSprite *this)
{
  return &g_CSprite_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x10223230
// Name: public: virtual CSprite::~CSprite(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSprite::~CSprite(CSprite *this)
{
  this->__vftable = (CSprite_vtbl *)&CSprite::`vftable';
  CBaseEntity::~CBaseEntity(this);
}

//------------------------------------------------------------------------------
// Address: 0x10223240
// Name: public: virtual void CSprite::SetModel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSprite::SetModel(CSprite *this, const char *szModelName)
{
  int v3; // eax
  const struct model_t *v4; // eax
  const char *v5; // eax

  v3 = modelinfo->GetModelIndex(this: modelinfo, a2: szModelName);
  v4 = modelinfo->GetModel(this: modelinfo, a2: v3);
  if ( v4 != nullptr && modelinfo->GetModelType(this: modelinfo, a2: v4) != 2 )
  {
    v5 = szModelName;
    if ( szModelName == nullptr )
      v5 = "NULL";
    _Msg(a1: "Setting CSprite to non-sprite model %s\n", v5);
  }
  UTIL_SetModel(pEntity: this, pModelName: szModelName);
}

//------------------------------------------------------------------------------
// Address: 0x102232B0
// Name: public: void CSprite::TurnOff(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSprite::TurnOff(CSprite *this)
{
  CBaseEntity::AddEffects(this, nEffects: 32);
  CBaseEntity::SetNextThink(this, thinkTime: -1.0, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102232E0
// Name: public: void CSprite::InputHideSprite(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSprite::InputHideSprite(CSprite *this, inputdata_t *inputdata)
{
  CBaseEntity::AddEffects(this, nEffects: 32);
  CBaseEntity::SetNextThink(this, thinkTime: -1.0, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10223310
// Name: public: virtual class ServerClass __near * CSpriteOriented::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CSpriteOriented::GetServerClass(CSpriteOriented *this)
{
  return &g_CSpriteOriented_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x10223320
// Name: public: virtual void CSprite::ComputeWorldSpaceSurroundingBox(class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSprite::ComputeWorldSpaceSurroundingBox(CSprite *this, Vector *pVecWorldMins, Vector *pVecWorldMaxs)
{
  float v4; // xmm0_4
  IVModelInfo_vtbl *v5; // edi
  model_t *Model; // eax
  int v7; // eax
  IVModelInfo_vtbl *v8; // edi
  model_t *v9; // eax
  float v10; // xmm0_4
  float flScale; // [esp+8h] [ebp-8h]
  float width; // [esp+Ch] [ebp-4h]
  int savedregs; // [esp+10h] [ebp+0h] BYREF

  v4 = this->m_flSpriteScale.m_Value * 0.5;
  flScale = v4;
  if ( !this->m_bWorldSpaceScale.m_Value )
  {
    v5 = modelinfo->__vftable;
    Model = CBaseEntity::GetModel(this);
    v7 = v5->GetModelSpriteWidth(this: modelinfo, a2: Model);
    v8 = modelinfo->__vftable;
    width = (float)v7;
    v9 = CBaseEntity::GetModel(this);
    v10 = (float)v8->GetModelSpriteHeight(this: modelinfo, a2: v9);
    if ( width > v10 )
      v10 = width;
    v4 = v10 * flScale;
  }
  LODWORD(pVecWorldMins->x) = LODWORD(v4) ^ _mask__NegFloat_;
  LODWORD(pVecWorldMins->y) = LODWORD(v4) ^ _mask__NegFloat_;
  LODWORD(pVecWorldMins->z) = LODWORD(v4) ^ _mask__NegFloat_;
  pVecWorldMaxs->x = v4;
  pVecWorldMaxs->y = v4;
  pVecWorldMaxs->z = v4;
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  pVecWorldMins->x = pVecWorldMins->x + this->m_vecAbsOrigin.x;
  pVecWorldMins->y = pVecWorldMins->y + this->m_vecAbsOrigin.y;
  pVecWorldMins->z = this->m_vecAbsOrigin.z + pVecWorldMins->z;
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  pVecWorldMaxs->x = pVecWorldMaxs->x + this->m_vecAbsOrigin.x;
  pVecWorldMaxs->y = pVecWorldMaxs->y + this->m_vecAbsOrigin.y;
  pVecWorldMaxs->z = pVecWorldMaxs->z + this->m_vecAbsOrigin.z;
}

//------------------------------------------------------------------------------
// Address: 0x10223470
// Name: public: void CSprite::SpriteInit(char const __near *,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSprite::SpriteInit(CSprite *this, const char *pSpriteName, const Vector *origin)
{
  const char *v3; // eax

  v3 = pSpriteName;
  if ( pSpriteName == nullptr || *pSpriteName == 0 )
    v3 = nullptr;
  this->m_ModelName.pszValue = v3;
  CBaseEntity::DispatchUpdateTransmitState(this);
  CBaseEntity::SetLocalOrigin(this, origin);
  this->Spawn(this);
}

//------------------------------------------------------------------------------
// Address: 0x10223800
// Name: public: virtual int CSprite::UpdateTransmitState(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSprite::UpdateTransmitState(CSprite *this)
{
  unsigned int m_Index; // edx

  m_Index = this->m_hMoveParent.m_Value.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
  {
    return CBaseEntity::SetTransmitState(this, nFlag: 0);
  }
  else
  {
    return CBaseEntity::SetTransmitState(this, nFlag: 8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10223840
// Name: public: virtual int CSprite::ShouldTransmit(class CCheckTransmitInfo const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSprite::ShouldTransmit(CSprite *this, const CCheckTransmitInfo *pInfo)
{
  unsigned int m_Index; // ecx
  int v3; // eax
  CEntInfo *v4; // edx
  unsigned int v5; // ecx
  int v6; // eax
  bool v7; // zf
  CEntInfo *v8; // eax
  int v9; // eax
  int v10; // esi

  m_Index = this->m_hMoveParent.m_Value.m_Index;
  if ( m_Index == -1 )
    return 8;
  v3 = (unsigned __int16)m_Index;
  v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
  v5 = HIWORD(m_Index);
  if ( v4->m_SerialNumber != v5 )
    return 8;
  if ( v4->m_pEntity != nullptr
    && (v6 = v3, v7 = g_pEntityList->m_EntPtrArray[v6].m_SerialNumber == v5, v8 = &g_pEntityList->m_EntPtrArray[v6], v7)
    && v8->m_pEntity != nullptr
    && (v9 = (int)v8->m_pEntity->__vftable[17].GetRefEHandle(this: v8->m_pEntity), v10 = v9, v9 != 0)
    && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v9 + 872))(a1: v9) != 0 )
  {
    return (*(int (__thiscall **)(int, const CCheckTransmitInfo *))(*(_DWORD *)v10 + 80))(a1: v10, a2: pInfo);
  }
  else
  {
    return 8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102238C0
// Name: public: CSprite::CSprite(void)
// Source: json
//------------------------------------------------------------------------------
CSprite *__thiscall CSprite::CSprite(CSprite *this)
{
  edict_t *m_pPev; // ecx
  CSprite *result; // eax
  edict_t *v4; // ecx

  CBaseEntity::CBaseEntity(this, bServerOnly: false);
  this->__vftable = (CSprite_vtbl *)&CSprite::`vftable';
  this->m_hAttachedToEntity.m_Value.m_Index = -1;
  if ( this->m_flGlowProxySize.m_Value != 2.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x37Cu);
    }
    this->m_flGlowProxySize.m_Value = 2.0;
  }
  result = this;
  if ( this->m_flHDRColorScale.m_Value != 1.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v4 = this->m_Network.m_pPev;
      if ( v4 != nullptr )
        CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0x380u);
    }
    this->m_flHDRColorScale.m_Value = 1.0;
    return this;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10223970
// Name: public: virtual void CSprite::OnRestore(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSprite::OnRestore(CSprite *this)
{
  CBaseEntity *FollowedEntity; // eax
  unsigned int m_Index; // eax
  edict_t *m_pPev; // ecx
  edict_t *v5; // ecx
  int m_Value; // [esp-4h] [ebp-8h]

  CBaseEntity::OnRestore(this);
  if ( CBaseEntity::GetFollowedEntity(this) != nullptr )
  {
    m_Value = this->m_nAttachment.m_Value;
    FollowedEntity = CBaseEntity::GetFollowedEntity(this);
    CSprite::SetAttachment(this, pEntity: FollowedEntity, attachment: m_Value);
  }
  else
  {
    m_Index = this->m_hAttachedToEntity.m_Value.m_Index;
    if ( m_Index != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x354u);
      }
      this->m_hAttachedToEntity.m_Value.m_Index = -1;
    }
    if ( this->m_nAttachment.m_Value != 0 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        this->m_nAttachment.m_Value = 0;
      }
      else
      {
        v5 = this->m_Network.m_pPev;
        if ( v5 != nullptr )
          CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0x358u);
        this->m_nAttachment.m_Value = 0;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10223A40
// Name: public: void CSprite::Animate(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSprite::Animate(CSprite *this, float frames)
{
  float v3; // xmm0_4
  edict_t *m_pPev; // ecx
  float m_flMaxFrame; // xmm0_4
  long double v6; // st7
  edict_t *v7; // ecx
  float framesa; // [esp+1Ch] [ebp+8h]
  float framesb; // [esp+1Ch] [ebp+8h]

  framesa = this->m_flFrame.m_Value + frames;
  v3 = framesa;
  if ( this->m_flFrame.m_Value != framesa )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
      {
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x360u);
        v3 = framesa;
      }
    }
    this->m_flFrame.m_Value = v3;
  }
  m_flMaxFrame = this->m_flMaxFrame;
  if ( this->m_flFrame.m_Value > m_flMaxFrame )
  {
    if ( (this->m_spawnflags.m_Value & 2) != 0 )
    {
      CBaseEntity::AddEffects(this, nEffects: 32);
      CBaseEntity::SetNextThink(this, thinkTime: -1.0, szContext: nullptr);
    }
    else if ( m_flMaxFrame > 0.0 )
    {
      v6 = fmod(this->m_flFrame.m_Value, this->m_flMaxFrame);
      if ( this->m_flFrame.m_Value != v6 )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          v7 = this->m_Network.m_pPev;
          if ( v7 != nullptr )
            CBaseEdict::StateChanged(this: &v7->CBaseEdict, offset: 0x360u);
        }
        framesb = v6;
        this->m_flFrame.m_Value = framesb;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10223B50
// Name: public: void CSprite::SetBrightness(int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSprite::SetBrightness(CSprite *this, int brightness, float time)
{
  edict_t *m_pPev; // ecx
  edict_t *v5; // ecx

  if ( this->m_nBrightness.m_Value != brightness )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x368u);
    }
    this->m_nBrightness.m_Value = brightness;
  }
  if ( this->m_flBrightnessTime.m_Value != time )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_flBrightnessTime.m_Value = time;
    }
    else
    {
      v5 = this->m_Network.m_pPev;
      if ( v5 != nullptr )
        CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0x36Cu);
      this->m_flBrightnessTime.m_Value = time;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10223BF0
// Name: public: void CSprite::SetScale(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSprite::SetScale(CSprite *this, float scale, float time)
{
  edict_t *m_pPev; // ecx
  float v5; // xmm0_4
  edict_t *v6; // ecx

  if ( this->m_flScaleTime.m_Value != time )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x374u);
    }
    this->m_flScaleTime.m_Value = time;
  }
  v5 = scale;
  if ( scale != this->m_flSpriteScale.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v6 = this->m_Network.m_pPev;
      if ( v6 != nullptr )
      {
        CBaseEdict::StateChanged(this: &v6->CBaseEdict, offset: 0x370u);
        v5 = scale;
      }
    }
    this->m_flSpriteScale.m_Value = v5;
    CCollisionProperty::MarkSurroundingBoundsDirty(this: &this->m_Collision);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10223CD0
// Name: public: void CSprite::AnimateThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSprite::AnimateThink(CSprite *this)
{
  CSprite::Animate(this, frames: (float)(gpGlobals->curtime - this->m_flLastTime) * this->m_flSpriteFramerate.m_Value);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
  this->m_flLastTime = gpGlobals->curtime;
}

//------------------------------------------------------------------------------
// Address: 0x10223D30
// Name: public: void CSprite::AnimateUntilDead(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSprite::AnimateUntilDead(CSprite *this)
{
  float curtime; // xmm0_4
  CGlobalVars *v3; // eax

  curtime = gpGlobals->curtime;
  if ( curtime <= this->m_flDieTime )
  {
    CSprite::Animate(this, frames: (float)(curtime - this->m_flLastTime) * this->m_flSpriteFramerate.m_Value);
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
    v3 = gpGlobals;
    this->m_flLastTime = gpGlobals->curtime;
    CBaseEntity::SetNextThink(this, thinkTime: v3->curtime, szContext: nullptr);
  }
  else
  {
    CNullEntity::Spawn(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10223DB0
// Name: public: void CSprite::ExpandThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSprite::ExpandThink(CSprite *this)
{
  float v2; // xmm1_4
  float m_Value; // xmm2_4
  float v4; // xmm0_4
  edict_t *m_pPev; // ecx
  unsigned __int8 a; // al
  int v7; // ecx
  edict_t *v8; // ecx
  unsigned __int8 v9; // bl
  edict_t *v10; // ecx

  v2 = gpGlobals->curtime - this->m_flLastTime;
  m_Value = this->m_flSpriteScale.m_Value;
  v4 = (float)(this->m_flSpeed * v2) + m_Value;
  if ( v4 != m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x370u);
    }
    this->m_flSpriteScale.m_Value = v4;
    CCollisionProperty::MarkSurroundingBoundsDirty(this: &this->m_Collision);
  }
  a = this->m_clrRender.m_Value.a;
  v7 = (int)(float)((float)this->m_iHealth.m_Value * v2);
  if ( v7 <= a )
  {
    v9 = a - v7;
    if ( this->m_clrRender.m_Value.a != a - (_BYTE)v7 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v10 = this->m_Network.m_pPev;
        if ( v10 != nullptr )
          CBaseEdict::StateChanged(this: &v10->CBaseEdict, offset: 0xB8u);
      }
      this->m_clrRender.m_Value.a = v9;
    }
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
    this->m_flLastTime = gpGlobals->curtime;
  }
  else
  {
    if ( a != 0 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        this->m_clrRender.m_Value.a = 0;
        CNullEntity::Spawn(this);
        return;
      }
      v8 = this->m_Network.m_pPev;
      if ( v8 != nullptr )
        CBaseEdict::StateChanged(this: &v8->CBaseEdict, offset: 0xB8u);
      this->m_clrRender.m_Value.a = 0;
    }
    CNullEntity::Spawn(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10223F20
// Name: public: void CSprite::TurnOn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSprite::TurnOn(CSprite *this)
{
  unsigned int v2; // edi
  edict_t *m_pPev; // ecx
  edict_t *v4; // ecx

  v2 = this->m_fEffects.m_Value & 0xFFFFFFDF;
  if ( this->m_fEffects.m_Value != v2 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xA4u);
    }
    this->m_fEffects.m_Value = v2;
  }
  if ( this->m_Network.m_pPev != nullptr )
    this->m_Network.m_pPev->m_fStateFlags |= 0x80u;
  CBaseEntity::DispatchUpdateTransmitState(this);
  if ( this->m_flSpriteFramerate.m_Value != 0.0 && this->m_flMaxFrame > 1.0 || (this->m_spawnflags.m_Value & 2) != 0 )
  {
    CBaseEntity::ThinkSet(
      this,
      func: (void (__thiscall *)(CBaseEntity *))CSprite::AnimateThink,
      thinkTime: 0.0,
      szContext: nullptr);
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
    this->m_flLastTime = gpGlobals->curtime;
  }
  if ( this->m_flFrame.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_flFrame.m_Value = 0.0;
    }
    else
    {
      v4 = this->m_Network.m_pPev;
      if ( v4 != nullptr )
        CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0x360u);
      this->m_flFrame.m_Value = 0.0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10224030
// Name: public: virtual void CSprite::Use(class CBaseEntity __near *,class CBaseEntity __near *,enum USE_TYPE,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSprite::Use(
        CSprite *this,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller,
        USE_TYPE useType,
        float value)
{
  BOOL v6; // edi

  v6 = (this->m_fEffects.m_Value & 0x20) == 0;
  if ( CBaseEntity::ShouldToggle(this, useType, currentState: v6) != 0 )
  {
    if ( v6 )
    {
      CBaseEntity::AddEffects(this, nEffects: 32);
      CBaseEntity::SetNextThink(this, thinkTime: -1.0, szContext: nullptr);
    }
    else
    {
      CSprite::TurnOn(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10224090
// Name: public: void CSprite::InputShowSprite(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CSprite::InputShowSprite(CSprite *this, inputdata_t *inputdata)
{
  CSprite::TurnOn(this);
}

//------------------------------------------------------------------------------
// Address: 0x102240A0
// Name: public: void CSprite::InputToggleSprite(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSprite::InputToggleSprite(CSprite *this, inputdata_t *inputdata)
{
  if ( (this->m_fEffects.m_Value & 0x20) != 0 )
  {
    CSprite::TurnOn(this);
  }
  else
  {
    CBaseEntity::AddEffects(this, nEffects: 32);
    CBaseEntity::SetNextThink(this, thinkTime: -1.0, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10224120
// Name: public: void CSprite::BeginFadeOutThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSprite::BeginFadeOutThink(CSprite *this)
{
  CSprite::SetBrightness(this, brightness: 0, time: 0.25);
  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CSprite::AnimateUntilDead,
    thinkTime: 0.0,
    szContext: nullptr);
  this->m_flDieTime = gpGlobals->curtime + 0.25;
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10224190
// Name: public: virtual void CSprite::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSprite::Spawn(CSprite *this)
{
  edict_t *m_pPev; // ecx
  const char *v3; // eax
  IVModelInfo_vtbl *v4; // edi
  model_t *Model; // eax
  edict_t *v6; // ecx
  float v7; // xmm0_4
  const char *DebugName; // eax
  float m_Value; // xmm0_4
  QAngle angles; // [esp+40h] [ebp-10h] BYREF
  float scale; // [esp+4Ch] [ebp-4h] BYREF
  int savedregs; // [esp+50h] [ebp+0h] BYREF

  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
  if ( this->m_flFrame.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x360u);
    }
    this->m_flFrame.m_Value = 0.0;
  }
  this->Precache(this);
  v3 = *(const char **)((int (__thiscall *)(CSprite *, float *))this->GetModelName)(a1: this, a2: &scale);
  if ( v3 == nullptr )
    v3 = locale;
  this->SetModel(this, a2: v3);
  CCollisionProperty::SetSurroundingBoundsType(
    this: &this->m_Collision,
    type: USE_GAME_CODE,
    pMins: nullptr,
    pMaxs: nullptr);
  v4 = modelinfo->__vftable;
  Model = CBaseEntity::GetModel(this);
  this->m_flMaxFrame = (float)v4->GetModelFrameCount(this: modelinfo, a2: Model) - 1.0;
  CBaseEntity::AddEffects(this, nEffects: 80);
  if ( this->m_flGlowProxySize.m_Value > 64.0 )
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    DevWarning(
      a1: "env_sprite at setpos %0.0f %0.0f %0.0f has invalid glow size %f - clamping to %f\n",
      this->m_vecAbsOrigin.x,
      this->m_vecAbsOrigin.y,
      this->m_vecAbsOrigin.z,
      this->m_flGlowProxySize.m_Value,
      64.0);
    if ( this->m_flGlowProxySize.m_Value != 64.0 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v6 = this->m_Network.m_pPev;
        if ( v6 != nullptr )
          CBaseEdict::StateChanged(this: &v6->CBaseEdict, offset: 0x37Cu);
      }
      this->m_flGlowProxySize.m_Value = 64.0;
    }
  }
  if ( this->m_iName.m_Value.pszValue == nullptr || (this->m_spawnflags.m_Value & 1) != 0 )
  {
    CSprite::TurnOn(this);
  }
  else
  {
    CBaseEntity::AddEffects(this, nEffects: 32);
    CBaseEntity::SetNextThink(this, thinkTime: -1.0, szContext: nullptr);
  }
  if ( this->m_angRotation.m_Value.y != 0.0 && this->m_angRotation.m_Value.z == 0.0 )
  {
    *(_QWORD *)&angles.x = *(_QWORD *)&this->m_angRotation.m_Value.x;
    angles.z = angles.y;
    angles.y = 0.0;
    CBaseEntity::SetLocalAngles(this, &angles);
  }
  scale = this->m_flSpriteScale.m_Value;
  v7 = scale;
  if ( scale < 0.0 || scale > 64.0 )
  {
    DebugName = CBaseEntity::GetDebugName(this);
    DevMsg(a1: "LEVEL DESIGN ERROR: Sprite %s with bad scale %f [0..%f]\n", DebugName, v7, 64.0);
    m_Value = this->m_flSpriteScale.m_Value;
    if ( m_Value >= 0.0 )
    {
      if ( m_Value <= 64.0 )
        scale = this->m_flSpriteScale.m_Value;
      else
        scale = 64.0;
    }
    else
    {
      scale = 0.0;
    }
  }
  CSprite::SetBrightness(this, brightness: this->m_clrRender.m_Value.a, time: 0.0);
  CSprite::SetScale(this, scale, time: 0.0);
  if ( this->m_iClassname.pszValue == "env_sprite_clientside"
    || CBaseEntity::ClassMatchesComplex(this, pszClassOrWildcard: "env_sprite_clientside") != 0 )
  {
    UTIL_Remove(oldObj: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102244E0
// Name: public: static class CSprite __near * CSprite::SpriteCreate(char const __near *,class Vector const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
CSprite *__cdecl CSprite::SpriteCreate(const char *pSpriteName, const Vector *origin, bool animate)
{
  CBaseEntity *EntityByName; // eax
  CSprite *v4; // esi
  const char *v5; // eax

  EntityByName = CreateEntityByName(className: "env_sprite", iForceEdictIndex: -1, bNotify: true);
  v4 = (CSprite *)__RTDynamicCast(
                    inptr: EntityByName,
                    VfDelta: 0,
                    SrcType: &CBaseEntity `RTTI Type Descriptor',
                    TargetType: &CSprite `RTTI Type Descriptor',
                    isReference: 0);
  if ( v4 == nullptr )
    _Warning(a1: "classname %s used to create wrong class type\n", "env_sprite");
  v5 = pSpriteName;
  if ( pSpriteName == nullptr || *pSpriteName == 0 )
    v5 = nullptr;
  v4->m_ModelName.pszValue = v5;
  CBaseEntity::DispatchUpdateTransmitState(this: v4);
  CBaseEntity::SetLocalOrigin(this: v4, origin);
  v4->Spawn(this: v4);
  CCollisionProperty::SetSolid(this: &v4->m_Collision, val: SOLID_NONE);
  UTIL_SetSize(pEnt: v4, vecMin: &vec3_origin, vecMax: &vec3_origin);
  CBaseEntity::SetMoveType(this: v4, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
  if ( animate )
    CSprite::TurnOn(this: v4);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x102245A0
// Name: public: void CSprite::InputColorBlueValue(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSprite::InputColorBlueValue(CBeam *this, inputdata_t *inputdata)
{
  float flVal; // xmm0_4
  int v3; // xmm1_4

  if ( inputdata->value.fieldType == FIELD_FLOAT )
  {
    flVal = inputdata->value.flVal;
    v3 = 0;
    if ( flVal < 0.0 || (v3 = 1132396544, flVal > 255.0) )
      flVal = *(float *)&v3;
  }
  else
  {
    flVal = 0.0;
  }
  CNetworkColor32Base<color32_s,CBaseEntity::NetworkVar_m_clrRender>::Init(
    this: &this->m_clrRender,
    rVal: this->m_clrRender.m_Value.r,
    gVal: this->m_clrRender.m_Value.g,
    bVal: (int)flVal);
}

//------------------------------------------------------------------------------
// Address: 0x10224600
// Name: public: virtual void CSpriteOriented::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpriteOriented::Spawn(CSpriteOriented *this)
{
  QAngle angles; // [esp+4h] [ebp-Ch] BYREF
  int savedregs; // [esp+10h] [ebp+0h] BYREF

  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  angles = this->m_angAbsRotation;
  CSprite::Spawn(this);
  angles.y = (float)(unsigned __int16)(int)(float)((float)(angles.y + 180.0) * 182.04445) * 0.0054931641;
  CBaseEntity::SetAbsAngles(this, absAngles: &angles);
}

//------------------------------------------------------------------------------
// Address: 0x1040A5E0
// Name: CSprite_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CSprite_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CSprite>();
  CSprite_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040A610
// Name: DT_Sprite::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_Sprite::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_Sprite::g_SendTable);
  return atexit(func: DT_Sprite::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1040A630
// Name: DT_Sprite::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_Sprite::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_Sprite::ignored>();
  DT_Sprite::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040A680
// Name: DT_SpriteOriented::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_SpriteOriented::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_SpriteOriented::g_SendTable);
  return atexit(func: DT_SpriteOriented::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1040A6A0
// Name: DT_SpriteOriented::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_SpriteOriented::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_SpriteOriented::ignored>();
  DT_SpriteOriented::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041E190
// Name: DT_Sprite::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_Sprite::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_Sprite::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041E1A0
// Name: DT_SpriteOriented::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_SpriteOriented::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_SpriteOriented::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x100E0170
// Name: struct datamap_t __near * DataMapInit<class CBeam>(class CBeam __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CBeam>()
{
  if ( (_S3_28 & 1) == 0 )
  {
    _S3_28 |= 1u;
    nameHolder_99.m_pszBase = "CBeam";
    nameHolder_99.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_99.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_99.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_99.m_Names.m_Size = 0;
    nameHolder_99.m_Names.m_pElements = nullptr;
    nameHolder_99.m_nLenBase = 5;
    atexit(func: DataMapInit_CBeam__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CBeam::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CBeam::m_DataMap.dataNumFields = 27;
  CBeam::m_DataMap.dataDesc = &dataDesc_96[1];
  return &CBeam::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1040A5F0
// Name: _dynamic_initializer_for__g_CSprite_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CSprite_ClassReg__()
{
  return ServerClass::ServerClass(this: &g_CSprite_ClassReg, pNetworkName: "CSprite", pTable: &DT_Sprite::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1040A640
// Name: _dynamic_initializer_for__env_sprite__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_sprite__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CSprite> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_sprite,
           a3: "env_sprite");
}

//------------------------------------------------------------------------------
// Address: 0x1040A660
// Name: _dynamic_initializer_for__g_CSpriteOriented_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CSpriteOriented_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CSpriteOriented_ClassReg,
           pNetworkName: "CSpriteOriented",
           pTable: &DT_SpriteOriented::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1040A6B0
// Name: _dynamic_initializer_for__env_sprite_oriented__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_sprite_oriented__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CSpriteOriented> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_sprite_oriented,
           a3: "env_sprite_oriented");
}

//------------------------------------------------------------------------------
// Address: 0x1040A6D0
// Name: _dynamic_initializer_for__env_particle_performance_monitor__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_particle_performance_monitor__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CParticlePerformanceMonitor> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_particle_performance_monitor,
           a3: "env_particle_performance_monitor");
}

//------------------------------------------------------------------------------
// Address: 0x1041E1B0
// Name: _ServerClassInit_DT_SpriteOriented::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_SpriteOriented::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S4_57;
  for ( i = 1; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041E1D0
// Name: _ServerClassInit_DT_Sprite::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_Sprite::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S3_121;
  for ( i = 12; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041E1F0
// Name: _DataMapInit_CSprite__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CSprite__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_400);
}

} // namespace server
