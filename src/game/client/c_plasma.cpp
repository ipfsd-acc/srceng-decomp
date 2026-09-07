// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_plasma.cpp
// Functions: 19
// ============================================================

#include "game\client\c_plasma.h"

//------------------------------------------------------------------------------
// Address: 0x1007D150
// Name: void RecvProxy_PlasmaScale(class CRecvProxyData const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvProxy_PlasmaScale(const CRecvProxyData *pData, float *pStruct)
{
  float m_Float; // xmm0_4
  double v3; // st7

  m_Float = pData->m_Value.m_Float;
  if ( pStruct[609] != m_Float )
  {
    v3 = pStruct[615];
    pStruct[617] = m_Float;
    pStruct[616] = v3;
    pStruct[609] = m_Float;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007D190
// Name: void RecvProxy_PlasmaScaleTime(class CRecvProxyData const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvProxy_PlasmaScaleTime(const CRecvProxyData *pData, float *pStruct)
{
  float m_Float; // xmm1_4
  float v3; // xmm0_4
  unsigned int m_Index; // eax

  m_Float = pData->m_Value.m_Float;
  if ( pStruct[610] != m_Float )
  {
    if ( m_Float == -1.0 )
    {
      v3 = *(float *)(gpGlobals.m_Index + 12) - 1.0;
      pStruct[618] = v3;
      pStruct[619] = v3;
    }
    else
    {
      m_Index = gpGlobals.m_Index;
      pStruct[618] = *(float *)(gpGlobals.m_Index + 12);
      pStruct[619] = m_Float + *(float *)(m_Index + 12);
    }
    pStruct[610] = m_Float;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007D220
// Name: public: virtual class ClientClass __near * C_Plasma::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_Plasma::GetClientClass(C_Plasma *this)
{
  return &__g_C_PlasmaClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1007D360
// Name: public: virtual C_Plasma::~C_Plasma(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_Plasma::~C_Plasma(C_Plasma *this)
{
  float *m_entFlameScales; // edi
  int i; // ebx

  this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_Plasma_vtbl *)&C_Plasma::`vftable'{for `IClientUnknown'};
  this->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_Plasma::`vftable'{for `IClientRenderable'};
  this->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_Plasma::`vftable'{for `IClientNetworkable'};
  this->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_Plasma::`vftable'{for `IClientThinkable'};
  this->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_Plasma::`vftable';
  C_Sprite::~C_Sprite(this: &this->m_entGlow);
  m_entFlameScales = this->m_entFlameScales;
  for ( i = 5; i >= 0; --i )
  {
    m_entFlameScales -= 638;
    C_Sprite::~C_Sprite(this: (C_Sprite *)m_entFlameScales);
  }
  C_BaseEntity::~C_BaseEntity(this);
}

//------------------------------------------------------------------------------
// Address: 0x1007D3C0
// Name: protected: void C_Plasma::UpdateFlames(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_Plasma::UpdateFlames(C_Plasma *this)
{
  int v2; // edi
  C_PlasmaSprite *m_entFlames; // esi
  const Vector *(__thiscall *GetAbsOrigin)(IClientEntity *); // edx
  int v5; // eax
  __int64 v6; // xmm0_8
  C_PlasmaSprite_vtbl *v7; // edx
  const Vector *(__thiscall *v8)(IClientEntity *); // eax
  double v9; // xmm0_8
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm0_4
  double LocalOriginDim; // st7
  float time; // [esp+4h] [ebp-40h]
  Vector dir; // [esp+14h] [ebp-30h] BYREF
  Vector origin; // [esp+20h] [ebp-24h] BYREF
  Vector offset; // [esp+2Ch] [ebp-18h]
  float dScale; // [esp+38h] [ebp-Ch]
  float newScale; // [esp+3Ch] [ebp-8h]
  float *m_entFlameScales; // [esp+40h] [ebp-4h]

  v2 = 0;
  m_entFlames = this->m_entFlames;
  m_entFlameScales = this->m_entFlameScales;
  do
  {
    newScale = *m_entFlameScales * this->m_flScaleRegister;
    dScale = newScale - m_entFlames->m_flSpriteScale.m_Value;
    dir.z = 0.0;
    VectorNormalize(vec: &dir);
    GetAbsOrigin = this->GetAbsOrigin;
    dir.z = 0.0;
    v5 = (int)GetAbsOrigin(this);
    v6 = *(_QWORD *)v5;
    v7 = m_entFlames->C_Sprite::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
    offset.z = *(float *)(v5 + 8);
    v8 = v7->GetAbsOrigin;
    *(_QWORD *)&offset.x = v6;
    offset.z = v8(this: m_entFlames)->z;
    v9 = 0.000001;
    if ( newScale >= 0.000001 )
      v9 = newScale;
    C_Sprite::SetScale(this: m_entFlames, scale: v9, time: 0.0);
    if ( v2 != 0 )
    {
      v10 = m_entFlames->m_flSpriteScale.m_Value * 40.0;
      v11 = (float)(m_entFlames->m_vecMoveDir.y * v10) + offset.y;
      v12 = m_entFlames->m_vecMoveDir.x * v10;
      v13 = v10 * m_entFlames->m_vecMoveDir.z;
      origin.y = v11;
      origin.x = offset.x + v12;
      origin.z = offset.z + v13;
      C_BaseEntity::SetLocalOrigin(this: m_entFlames, &origin);
    }
    LocalOriginDim = C_BaseEntity::GetLocalOriginDim(this: m_entFlames, iDim: 2);
    time = LocalOriginDim + dScale * 64.0;
    C_BaseEntity::SetLocalOriginDim(this: m_entFlames, iDim: 2, flValue: time);
    ++m_entFlameScales;
    ++v2;
    ++m_entFlames;
  }
  while ( v2 < 6 );
}

//------------------------------------------------------------------------------
// Address: 0x1007D530
// Name: public: C_Plasma::C_Plasma(void)
// Source: json
//------------------------------------------------------------------------------
C_Plasma *__thiscall C_Plasma::C_Plasma(C_Plasma *this)
{
  C_PlasmaSprite *m_entFlames; // esi
  int i; // ebx
  void (__thiscall *Clear)(C_BaseEntity *); // edx
  C_PlasmaSprite *v5; // esi
  int j; // ebx

  C_BaseEntity::C_BaseEntity(this);
  this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_Plasma_vtbl *)&C_Plasma::`vftable'{for `IClientUnknown'};
  this->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_Plasma::`vftable'{for `IClientRenderable'};
  this->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_Plasma::`vftable'{for `IClientNetworkable'};
  this->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_Plasma::`vftable'{for `IClientThinkable'};
  this->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_Plasma::`vftable';
  m_entFlames = this->m_entFlames;
  for ( i = 5; i >= 0; --i )
  {
    C_Sprite::C_Sprite(this: m_entFlames);
    m_entFlames->C_Sprite::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_PlasmaSprite_vtbl *)&C_PlasmaSprite::`vftable'{for `IClientUnknown'};
    m_entFlames->C_Sprite::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_PlasmaSprite::`vftable'{for `IClientRenderable'};
    m_entFlames->C_Sprite::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_PlasmaSprite::`vftable'{for `IClientNetworkable'};
    m_entFlames->C_Sprite::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_PlasmaSprite::`vftable'{for `IClientThinkable'};
    m_entFlames->C_Sprite::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_PlasmaSprite::`vftable'{for `C_BaseEntity'};
    m_entFlames->C_Sprite::C_SpriteRenderer::__vftable = (C_SpriteRenderer_vtbl *)&C_PlasmaSprite::`vftable'{for `C_SpriteRenderer'};
    ++m_entFlames;
  }
  C_Sprite::C_Sprite(this: &this->m_entGlow);
  this->m_tParticleSpawn.m_TimeBetweenEvents = -1.0;
  this->m_tParticleSpawn.m_fNextEvent = 0.0;
  this->m_tDecalSpawn.m_TimeBetweenEvents = -1.0;
  this->m_tDecalSpawn.m_fNextEvent = 0.0;
  this->m_nFlags = 0;
  this->m_nPlasmaModelIndex = 0;
  this->m_nPlasmaModelIndex2 = 0;
  this->m_nGlowModelIndex = 0;
  this->m_bClipTested = false;
  Clear = this->m_entGlow.Clear;
  this->m_flStartScale = 0.0;
  this->m_flScale = 0.0;
  this->m_flScaleTime = 0.0;
  this->m_flScaleRegister = 0.0;
  this->m_flScaleStart = 0.0;
  this->m_flScaleEnd = 0.0;
  this->m_flScaleTimeStart = 0.0;
  this->m_flScaleTimeEnd = 0.0;
  this->m_flGlowScale = 0.0;
  Clear(this: &this->m_entGlow);
  v5 = this->m_entFlames;
  for ( j = 6; j != 0; --j )
  {
    v5->Clear(this: v5);
    ++v5;
  }
  C_BaseEntity::AddToEntityList(this, listId: ENTITY_LIST_SIMULATE);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1007D710
// Name: protected: void C_Plasma::AddFlames(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_Plasma::AddFlames(C_Plasma *this)
{
  const Vector *v2; // edi
  const Vector *v3; // eax
  unsigned __int8 *p_g; // esi
  int i; // edi
  Vector viewDir; // [esp+10h] [ebp-Ch] BYREF

  v2 = CurrentViewOrigin();
  v3 = this->GetAbsOrigin(this);
  viewDir.x = v3->x - v2->x;
  viewDir.y = v3->y - v2->y;
  viewDir.z = v3->z - v2->z;
  VectorNormalize(vec: &viewDir);
  p_g = &this->m_entFlames[0].m_clrRender.m_Value.g;
  for ( i = 6; i != 0; --i )
  {
    if ( *(float *)(p_g + 2367) > 0.0 )
    {
      if ( *(p_g - 1) != 0xFF )
        *(p_g - 1) = -1;
      if ( *p_g != 0xFF )
        *p_g = -1;
      if ( p_g[1] != 0xFF )
        p_g[1] = -1;
      C_Sprite::SetBrightness(this: (C_Sprite *)(p_g - 109), brightness: 255, time: 0.0);
    }
    C_BaseEntity::AddToLeafSystem(this: (C_BaseEntity *)(p_g - 109), bRenderWithViewModels: false);
    p_g += 2552;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007D7D0
// Name: protected: void C_Plasma::Start(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall C_Plasma::Start(C_Plasma *this@<ecx>, int a2@<ebx>, int a3@<edi>, int a4@<esi>)
{
  char *v5; // ebx
  const struct model_t *v6; // eax
  const Vector *LocalOrigin; // eax
  float v8; // xmm0_4
  float v9; // xmm0_4
  int v10; // eax
  const Vector *v11; // eax
  C_PlasmaSprite *m_entFlames; // edi
  int j; // esi
  QAngle offset; // [esp+34h] [ebp-18h] BYREF
  int maxFrames; // [esp+40h] [ebp-Ch]
  int nModelIndex; // [esp+44h] [ebp-8h]
  int i; // [esp+48h] [ebp-4h]

  this->m_tParticleSpawn.m_TimeBetweenEvents = 0.1;
  this->m_tParticleSpawn.m_fNextEvent = 0.0;
  this->m_tDecalSpawn.m_TimeBetweenEvents = 0.050000001;
  this->m_tDecalSpawn.m_fNextEvent = 0.0;
  i = 0;
  do
  {
    offset.x = 0.0;
    offset.y = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, int, int, int, int))random->RandomFloat)(
                 a1: random,
                 a2: 0,
                 a3: 1135869952,
                 a4: a3,
                 a5: a4,
                 a6: a2);
    v5 = (char *)this + 2552 * i;
    offset.z = 0.0;
    AngleVectors(angles: &offset, forward: (Vector *)v5 + 420);
    if ( (i & 1) != 0 )
      nModelIndex = this->m_nPlasmaModelIndex;
    else
      nModelIndex = this->m_nPlasmaModelIndex2;
    a2 = nModelIndex;
    v6 = (const struct model_t *)((int (__thiscall *)(IVModelInfoClient *))modelinfo->GetModel)(a1: modelinfo);
    maxFrames = modelinfo->GetModelFrameCount(this: modelinfo, a2: v6);
    C_BaseEntity::SetModelByIndex(this: (C_BaseEntity *)(v5 + 2504), nModelIndex);
    LocalOrigin = C_BaseEntity::GetLocalOrigin(this);
    C_BaseEntity::SetLocalOrigin(this: (C_BaseEntity *)(v5 + 2504), origin: LocalOrigin);
    v8 = (float)random->RandomInt(this: random, a2: 0, a3: maxFrames);
    if ( *((float *)v5 + 1241) != v8 )
      *((float *)v5 + 1241) = v8;
    a4 = 20;
    a3 = 15;
    v9 = (float)((int (__thiscall *)(IUniformRandomStream *))random->RandomInt)(a1: random);
    if ( *((float *)v5 + 1240) != v9 )
      *((float *)v5 + 1240) = v9;
    C_Sprite::SetScale(this: (C_Sprite *)(v5 + 2504), scale: this->m_flStartScale, time: 0.0);
    C_BaseEntity::SetRenderMode(
      this: (C_BaseEntity *)(v5 + 2504),
      nRenderMode: kRenderTransAddFrameBlend,
      bForceUpdate: false);
    C_BaseEntity::SetRenderFX(
      this: (C_BaseEntity *)(v5 + 2504),
      nRenderFX: kRenderFxNone,
      flStartTime: 3.4028235e38,
      flDuration: 0.0);
    if ( v5[2612] != -1 )
      v5[2612] = -1;
    if ( v5[2613] != -1 )
      v5[2613] = -1;
    if ( v5[2614] != -1 )
      v5[2614] = -1;
    C_BaseEntity::SetRenderAlpha(this: (C_BaseEntity *)(v5 + 2504), a: 255);
    C_Sprite::SetBrightness(this: (C_Sprite *)(v5 + 2504), brightness: 255, time: 0.0);
    v10 = i;
    *((_DWORD *)v5 + 650) = -1;
    if ( v10 != 0 )
      this->m_entFlameScales[v10] = 1.0 - (float)((float)v10 * 0.16666667);
    else
      this->m_entFlameScales[0] = 1.0;
    i = v10 + 1;
  }
  while ( v10 + 1 < 6 );
  C_BaseEntity::SetModelByIndex(this: &this->m_entGlow, nModelIndex: this->m_nGlowModelIndex);
  v11 = C_BaseEntity::GetLocalOrigin(this);
  C_BaseEntity::SetLocalOrigin(this: &this->m_entGlow, origin: v11);
  C_Sprite::SetScale(this: &this->m_entGlow, scale: this->m_flStartScale, time: 0.0);
  C_BaseEntity::SetRenderMode(this: &this->m_entGlow, nRenderMode: kRenderTransAdd, bForceUpdate: false);
  C_BaseEntity::SetRenderFX(
    this: &this->m_entGlow,
    nRenderFX: kRenderFxNone,
    flStartTime: 3.4028235e38,
    flDuration: 0.0);
  if ( this->m_entGlow.m_clrRender.m_Value.r != 0xFF )
    this->m_entGlow.m_clrRender.m_Value.r = -1;
  if ( this->m_entGlow.m_clrRender.m_Value.g != 0xFF )
    this->m_entGlow.m_clrRender.m_Value.g = -1;
  if ( this->m_entGlow.m_clrRender.m_Value.b != 0xFF )
    this->m_entGlow.m_clrRender.m_Value.b = -1;
  C_BaseEntity::SetRenderAlpha(this: &this->m_entGlow, a: 255);
  C_Sprite::SetBrightness(this: &this->m_entGlow, brightness: 255, time: 0.0);
  this->m_flGlowScale = this->m_flStartScale;
  this->m_entGlow.index = -1;
  C_BaseEntity::AddToLeafSystem(this: &this->m_entGlow, bRenderWithViewModels: false);
  m_entFlames = this->m_entFlames;
  for ( j = 6; j != 0; --j )
    C_BaseEntity::AddToLeafSystem(this: m_entFlames++, bRenderWithViewModels: false);
}

//------------------------------------------------------------------------------
// Address: 0x1007DB60
// Name: protected: void C_Plasma::UpdateAnimation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_Plasma::UpdateAnimation(C_Plasma *this)
{
  CNetworkVarBase<float,C_Sprite::NetworkVar_m_flFrame> *p_m_flFrame; // esi
  int i; // ebx
  float v3; // xmm0_4
  IVModelInfoClient_vtbl *v4; // edi
  int v5; // eax
  float v6; // xmm0_4
  float frametime; // [esp+0h] [ebp-4h]

  frametime = *(float *)(gpGlobals.m_Index + 16);
  p_m_flFrame = &this->m_entFlames[0].m_flFrame;
  for ( i = 6; i != 0; --i )
  {
    v3 = (float)(p_m_flFrame[-1].m_Value * frametime) + p_m_flFrame->m_Value;
    if ( p_m_flFrame->m_Value != v3 )
      p_m_flFrame->m_Value = v3;
    v4 = modelinfo->__vftable;
    v5 = (*(int (__thiscall **)(CNetworkVarBase<float,C_Sprite::NetworkVar_m_flFrame> *))(LODWORD(p_m_flFrame[-614].m_Value)
                                                                                        + 32))(a1: p_m_flFrame - 614);
    if ( p_m_flFrame->m_Value >= (float)v4->GetModelFrameCount(this: modelinfo, a2: (const struct model_t *)v5) )
    {
      v6 = p_m_flFrame->m_Value - (float)(int)p_m_flFrame->m_Value;
      if ( p_m_flFrame->m_Value != v6 )
        p_m_flFrame->m_Value = v6;
    }
    p_m_flFrame += 638;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007DC10
// Name: protected: void C_Plasma::Update(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_Plasma::Update(C_Plasma *this)
{
  float v1; // xmm3_4
  float m_flScaleEnd; // xmm1_4
  float m_flScaleTimeEnd; // xmm0_4
  float v5; // xmm0_4
  float i; // xmm1_4
  float m_fNextEvent; // xmm0_4
  C_BaseEntity *BaseEntity; // esi
  IVEfx_vtbl *v9; // edi
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int index; // [esp+0h] [ebp-Ch]

  v1 = *(float *)(gpGlobals.m_Index + 12);
  m_flScaleEnd = this->m_flScaleEnd;
  if ( this->m_flScaleRegister != m_flScaleEnd )
  {
    m_flScaleTimeEnd = this->m_flScaleTimeEnd;
    if ( v1 <= m_flScaleTimeEnd )
    {
      v5 = (float)((float)(1.0
                         - (float)((float)(m_flScaleTimeEnd - v1) / (float)(m_flScaleTimeEnd - this->m_flScaleTimeStart)))
                 * (float)(m_flScaleEnd - this->m_flScaleStart))
         + this->m_flScaleStart;
      this->m_flStartScale = v5;
      this->m_flScaleRegister = v5;
    }
    else
    {
      this->m_flStartScale = m_flScaleEnd;
      this->m_flScaleRegister = m_flScaleEnd;
    }
  }
  C_Plasma::UpdateAnimation(this);
  C_Plasma::UpdateFlames(this);
  if ( this->m_flScaleRegister > 0.1 )
  {
    for ( i = *(float *)(gpGlobals.m_Index + 16); ; i = i - m_fNextEvent )
    {
      m_fNextEvent = this->m_tDecalSpawn.m_fNextEvent;
      if ( i < m_fNextEvent )
        break;
      this->m_tDecalSpawn.m_fNextEvent = this->m_tDecalSpawn.m_TimeBetweenEvents;
      BaseEntity = CClientEntityList::GetBaseEntity(this: (CClientEntityList *)cl_entitylist.m_Index, entnum: 0);
      if ( BaseEntity != nullptr )
      {
        index = decalsystem->GetDecalIndexForName(this: decalsystem, a2: "PlasmaGlowFade");
        if ( index >= 0 )
        {
          v9 = effects->__vftable;
          v10 = ((int (__thiscall *)(C_Plasma *, _DWORD, _DWORD, _DWORD))this->GetAbsOrigin)(
                  a1: this,
                  a2: 0,
                  a3: 0,
                  a4: 0);
          v11 = ((int (__thiscall *)(C_BaseEntity *, int))BaseEntity->GetAbsAngles)(a1: BaseEntity, a2: v10);
          v12 = ((int (__thiscall *)(C_BaseEntity *, int))BaseEntity->GetAbsOrigin)(a1: BaseEntity, a2: v11);
          v13 = ((int (__thiscall *)(IClientRenderable *, int))BaseEntity->GetModel)(
                  a1: &BaseEntity->IClientRenderable,
                  a2: v12);
          ((void (__thiscall *)(IVEfx *, int, _DWORD, int))v9->DecalShoot)(a1: effects, a2: index, a3: 0, a4: v13);
        }
      }
    }
    this->m_tDecalSpawn.m_fNextEvent = this->m_tDecalSpawn.m_fNextEvent - i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007DDB0
// Name: public: virtual bool C_Plasma::Simulate(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_Plasma::Simulate(C_Plasma *this)
{
  float m_flScaleRegister; // xmm0_4
  float v4; // xmm1_4
  __m128 v5; // xmm0
  double v6; // xmm0_8
  __m128 v7; // xmm0
  double v8; // xmm0_8
  float v9; // xmm1_4
  __m128 v10; // xmm0
  double v11; // xmm0_8
  float v12; // xmm1_4
  float scale; // xmm0_4
  C_Sprite *p_m_entGlow; // esi
  float time; // [esp+4h] [ebp-18h]
  float dScale; // [esp+Ch] [ebp-10h]
  float v17; // [esp+10h] [ebp-Ch]
  float v18; // [esp+14h] [ebp-8h]
  float v19; // [esp+14h] [ebp-8h]
  float v20; // [esp+18h] [ebp-4h]

  if ( (this->m_nFlags & 1) == 0 )
    return 0;
  C_Plasma::Update(this);
  C_Plasma::AddFlames(this);
  m_flScaleRegister = this->m_flScaleRegister;
  v4 = m_flScaleRegister - this->m_flGlowScale;
  this->m_flGlowScale = m_flScaleRegister;
  v17 = m_flScaleRegister;
  v5 = (__m128)*(unsigned int *)(gpGlobals.m_Index + 12);
  v20 = v5.m128_f32[0];
  v5.m128_f32[0] = v5.m128_f32[0] * 2000.0;
  dScale = v4;
  __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd(v5));
  *(float *)&v6 = v6;
  v18 = *(float *)&v6 * 0.5;
  v7 = (__m128)LODWORD(v20);
  v7.m128_f32[0] = v20 * 10000.0;
  __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd(v7));
  *(float *)&v8 = v8;
  v9 = v18 + *(float *)&v8;
  v10 = (__m128)LODWORD(v20);
  v10.m128_f32[0] = v20 * 8000.0;
  v19 = v9;
  __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd(v10));
  v12 = v11;
  scale = (float)((float)(v19 - (float)(v12 * 0.5)) * 0.1) + (float)(v17 * 1.5);
  if ( scale < 0.0000001 )
    scale = 0.0000001;
  p_m_entGlow = &this->m_entGlow;
  C_Sprite::SetScale(this: p_m_entGlow, scale, time: 0.0);
  time = C_BaseEntity::GetLocalOriginDim(this: p_m_entGlow, iDim: 2) + dScale * 32.0;
  C_BaseEntity::SetLocalOriginDim(this: p_m_entGlow, iDim: 2, flValue: time);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1007DEF0
// Name: public: virtual void C_Plasma::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __userpurge C_Plasma::OnDataChanged(C_Plasma *this@<ecx>, int a2@<ebx>, DataUpdateType_t updateType)
{
  C_BaseEntity::OnDataChanged(this, type: updateType);
  if ( updateType == DATA_UPDATE_CREATED )
    C_Plasma::Start(this: (C_Plasma *)((char *)this - 8), a2, a3: 0, a4: (int)this);
  if ( (LOBYTE(this->m_flScale) & 1) != 0 )
    C_BaseEntity::AddToEntityList(this: (C_Plasma *)((char *)this - 8), listId: ENTITY_LIST_SIMULATE);
}

//------------------------------------------------------------------------------
// Address: 0x10412D60
// Name: DT_Plasma::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_Plasma::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_Plasma::g_RecvTable);
  return atexit(func: DT_Plasma::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10412D80
// Name: DT_Plasma::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_Plasma::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_Plasma::ignored>();
  DT_Plasma::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430800
// Name: DT_Plasma::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_Plasma::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_Plasma::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x1007D6C0
// Name: _C_Plasma_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_Plasma_CreateObject(int entnum, int serialNum)
{
  C_Plasma *v2; // eax
  C_Plasma *v3; // eax
  C_Plasma *v4; // esi

  v2 = (C_Plasma *)C_BaseEntity::operator new(stAllocateBlock: 0x4FB0u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_Plasma::C_Plasma(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x10412D90
// Name: _dynamic_initializer_for__cl_names_debug__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_names_debug__()
{
  ConVar::ConVar(this: &cl_names_debug, pName: "cl_names_debug", pDefaultValue: "0", flags: 2);
  return atexit(func: dynamic_atexit_destructor_for__cl_names_debug__);
}

//------------------------------------------------------------------------------
// Address: 0x10412DC0
// Name: _dynamic_initializer_for____g_C_PlayerResourceClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_PlayerResourceClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_PlayerResourceClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_PlayerResourceClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430810
// Name: _dynamic_atexit_destructor_for__cl_names_debug__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_names_debug__()
{
  ConVar::~ConVar(this: &cl_names_debug);
}
