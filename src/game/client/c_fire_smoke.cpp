// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_fire_smoke.cpp
// Functions: 19
// ============================================================

#include "game\client\c_fire_smoke.h"

//------------------------------------------------------------------------------
// Address: 0x1006A7F0
// Name: public: virtual void SmokeStackMaterialsPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SmokeStackMaterialsPrecache::CResourcePrecacher::Cache(
        SmokeStackMaterialsPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "particle/SmokeStack",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1006A820
// Name: void RecvProxy_Scale(class CRecvProxyData const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvProxy_Scale(const CRecvProxyData *pData, float *pStruct)
{
  float m_Float; // xmm0_4
  float v3; // xmm1_4
  double v4; // st7

  m_Float = pData->m_Value.m_Float;
  v3 = pStruct[609];
  pStruct[609] = m_Float;
  if ( v3 != m_Float && pStruct[616] != m_Float )
  {
    v4 = pStruct[614];
    pStruct[616] = m_Float;
    pStruct[615] = v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006A870
// Name: void RecvProxy_ScaleTime(class CRecvProxyData const __near *,void __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvProxy_ScaleTime(const CRecvProxyData *pData, float *pStruct)
{
  CEffectsClient *v2; // ecx
  double v3; // st7
  CEffectsClient *v4; // ecx
  double v5; // st7
  float time; // [esp+8h] [ebp+8h]

  time = pData->m_Value.m_Float;
  if ( time == -1.0 )
  {
    v3 = CountdownTimer::Now(this: v2) - 1.0;
    pStruct[617] = v3;
    pStruct[610] = time;
    pStruct[618] = v3;
  }
  else
  {
    pStruct[617] = CountdownTimer::Now(this: v2);
    v5 = CountdownTimer::Now(this: v4);
    pStruct[610] = time;
    pStruct[618] = v5 + time;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006A8F0
// Name: public: virtual class ClientClass __near * C_FireSmoke::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_FireSmoke::GetClientClass(C_FireSmoke *this)
{
  return &__g_C_FireSmokeClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1006AA50
// Name: private: virtual int C_FireSprite::DrawModel(int,struct RenderableInstance_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_FireSprite::DrawModel(C_FireSprite *this, int flags, const RenderableInstance_t *instance)
{
  const Vector *v4; // esi
  const Vector *LocalOrigin; // eax
  int v6; // eax
  Vector vToPos; // [esp+4h] [ebp-Ch] BYREF

  if ( LOBYTE(this->m_vecMoveDir.z) != 0 )
  {
    v4 = CurrentViewOrigin();
    LocalOrigin = C_BaseEntity::GetLocalOrigin(this: (C_FireSprite *)((char *)this - 4));
    vToPos.x = LocalOrigin->x - v4->x;
    vToPos.y = LocalOrigin->y - v4->y;
    vToPos.z = LocalOrigin->z - v4->z;
    VectorNormalize(vec: &vToPos);
    LOBYTE(v6) = -1;
    if ( vToPos.z >= -0.75 )
    {
      if ( vToPos.z >= -0.64999998 )
      {
        if ( vToPos.z <= 0.85000002 )
        {
          if ( vToPos.z > 0.75 )
            v6 = 255 - (int)(float)((float)((float)(vToPos.z - 0.75) * 10.0) * 255.0);
        }
        else
        {
          LOBYTE(v6) = 0;
        }
      }
      else
      {
        v6 = 255 - (int)(float)((float)((float)(vToPos.z + 0.64999998) * -10.0) * 255.0);
      }
    }
    else
    {
      LOBYTE(v6) = 0;
    }
    if ( LOBYTE(this->model) != (_BYTE)v6 )
      LOBYTE(this->model) = v6;
    if ( BYTE1(this->model) != (_BYTE)v6 )
      BYTE1(this->model) = v6;
    if ( BYTE2(this->model) != (_BYTE)v6 )
      BYTE2(this->model) = v6;
  }
  return C_Sprite::DrawModel(this, flags, instance);
}

//------------------------------------------------------------------------------
// Address: 0x1006AB60
// Name: private: virtual int C_FireFromAboveSprite::DrawModel(int,struct RenderableInstance_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_FireFromAboveSprite::DrawModel(
        C_FireFromAboveSprite *this,
        int flags,
        const RenderableInstance_t *instance)
{
  const Vector *v4; // esi
  const Vector *LocalOrigin; // eax
  int v6; // eax
  float v7; // xmm0_4
  Vector vToPos; // [esp+Ch] [ebp-Ch] BYREF

  v4 = CurrentViewOrigin();
  LocalOrigin = C_BaseEntity::GetLocalOrigin(this: (C_FireFromAboveSprite *)((char *)this - 4));
  vToPos.x = LocalOrigin->x - v4->x;
  vToPos.y = LocalOrigin->y - v4->y;
  vToPos.z = LocalOrigin->z - v4->z;
  VectorNormalize(vec: &vToPos);
  LOBYTE(v6) = 0;
  if ( vToPos.z < -0.85000002 )
  {
    LOBYTE(v6) = -1;
    goto LABEL_10;
  }
  if ( vToPos.z < -0.64999998 )
  {
    v7 = (float)((float)(vToPos.z + 0.64999998) * 5.0) * -255.0;
LABEL_9:
    v6 = (int)v7;
    goto LABEL_10;
  }
  if ( vToPos.z > 0.75 )
  {
    LOBYTE(v6) = -1;
    goto LABEL_10;
  }
  if ( vToPos.z > 0.55000001 )
  {
    v7 = (float)((float)(vToPos.z - 0.55000001) * 5.0) * 255.0;
    goto LABEL_9;
  }
LABEL_10:
  if ( LOBYTE(this->model) != (_BYTE)v6 )
    LOBYTE(this->model) = v6;
  if ( BYTE1(this->model) != (_BYTE)v6 )
    BYTE1(this->model) = v6;
  if ( BYTE2(this->model) != (_BYTE)v6 )
    BYTE2(this->model) = v6;
  return C_Sprite::DrawModel(this, flags, instance);
}

//------------------------------------------------------------------------------
// Address: 0x1006AC60
// Name: public: C_FireSmoke::C_FireSmoke(void)
// Source: json
//------------------------------------------------------------------------------
C_FireSmoke *__thiscall C_FireSmoke::C_FireSmoke(C_FireSmoke *this)
{
  C_FireSprite *m_entFlames; // esi
  int i; // ebx
  C_FireFromAboveSprite *m_entFlamesFromAbove; // esi
  int j; // ebx

  C_BaseEntity::C_BaseEntity(this);
  this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_FireSmoke_vtbl *)&C_FireSmoke::`vftable'{for `IClientUnknown'};
  this->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_FireSmoke::`vftable'{for `IClientRenderable'};
  this->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_FireSmoke::`vftable'{for `IClientNetworkable'};
  this->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_FireSmoke::`vftable'{for `IClientThinkable'};
  this->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_FireSmoke::`vftable';
  this->m_pSmokeEmitter.m_pObj = nullptr;
  m_entFlames = this->m_entFlames;
  for ( i = 3; i >= 0; --i )
  {
    C_Sprite::C_Sprite(this: m_entFlames);
    m_entFlames->C_Sprite::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_FireSprite_vtbl *)&C_FireSprite::`vftable'{for `IClientUnknown'};
    m_entFlames->C_Sprite::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_FireSprite::`vftable'{for `IClientRenderable'};
    m_entFlames->C_Sprite::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_FireSprite::`vftable'{for `IClientNetworkable'};
    m_entFlames->C_Sprite::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_FireSprite::`vftable'{for `IClientThinkable'};
    m_entFlames->C_Sprite::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_FireSprite::`vftable'{for `C_BaseEntity'};
    m_entFlames->C_Sprite::C_SpriteRenderer::__vftable = (C_SpriteRenderer_vtbl *)&C_FireSprite::`vftable'{for `C_SpriteRenderer'};
    ++m_entFlames;
  }
  m_entFlamesFromAbove = this->m_entFlamesFromAbove;
  for ( j = 3; j >= 0; --j )
  {
    C_Sprite::C_Sprite(this: m_entFlamesFromAbove);
    m_entFlamesFromAbove->C_Sprite::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_FireFromAboveSprite_vtbl *)&C_FireFromAboveSprite::`vftable'{for `IClientUnknown'};
    m_entFlamesFromAbove->C_Sprite::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_FireFromAboveSprite::`vftable'{for `IClientRenderable'};
    m_entFlamesFromAbove->C_Sprite::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_FireFromAboveSprite::`vftable'{for `IClientNetworkable'};
    m_entFlamesFromAbove->C_Sprite::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_FireFromAboveSprite::`vftable'{for `IClientThinkable'};
    m_entFlamesFromAbove->C_Sprite::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_FireFromAboveSprite::`vftable'{for `C_BaseEntity'};
    m_entFlamesFromAbove->C_Sprite::C_SpriteRenderer::__vftable = (C_SpriteRenderer_vtbl *)&C_FireFromAboveSprite::`vftable'{for `C_SpriteRenderer'};
    ++m_entFlamesFromAbove;
  }
  this->m_tParticleSpawn.m_TimeBetweenEvents = -1.0;
  this->m_hEffect.m_pPrev = nullptr;
  this->m_hEffect.m_pNext = nullptr;
  this->m_hEffect.m_pObject = nullptr;
  this->m_tParticleSpawn.m_fNextEvent = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1006ADB0
// Name: public: virtual C_FireSmoke::~C_FireSmoke(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_FireSmoke::~C_FireSmoke(C_FireSmoke *this)
{
  CNewParticleEffect *m_pObject; // ecx
  CNewParticleEffect *v3; // eax
  CNewParticleEffect *v4; // eax
  float *m_entFlameScales; // edi
  int i; // ebx
  C_FireFromAboveSprite *m_entFlamesFromAbove; // edi
  int j; // ebx
  CLitSmokeEmitter *m_pObj; // ecx

  m_pObject = this->m_hEffect.m_pObject;
  this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_FireSmoke_vtbl *)&C_FireSmoke::`vftable'{for `IClientUnknown'};
  this->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_FireSmoke::`vftable'{for `IClientRenderable'};
  this->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_FireSmoke::`vftable'{for `IClientNetworkable'};
  this->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_FireSmoke::`vftable'{for `IClientThinkable'};
  this->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_FireSmoke::`vftable';
  if ( m_pObject != nullptr )
  {
    CNewParticleEffect::StopEmission(
      this: m_pObject,
      bInfiniteOnly: false,
      bRemoveAllParticles: false,
      bWakeOnStop: true,
      bPlayEndCap: false);
    v3 = this->m_hEffect.m_pObject;
    if ( v3 != nullptr )
    {
      CUtlIntrusiveDList<CUtlReference<CNewParticleEffect>>::RemoveNode(
        this: (CUtlIntrusiveDList<CUtlReference<CSheet> > *)&v3->m_References,
        which: (CUtlReference<CSheet> *)&this->m_hEffect);
      this->m_hEffect.m_pObject = nullptr;
    }
  }
  v4 = this->m_hEffect.m_pObject;
  if ( v4 != nullptr )
  {
    CUtlIntrusiveDList<CUtlReference<CNewParticleEffect>>::RemoveNode(
      this: (CUtlIntrusiveDList<CUtlReference<CSheet> > *)&v4->m_References,
      which: (CUtlReference<CSheet> *)&this->m_hEffect);
    this->m_hEffect.m_pObject = nullptr;
  }
  m_entFlameScales = this->m_entFlameScales;
  for ( i = 3; i >= 0; --i )
  {
    m_entFlameScales -= 634;
    C_Sprite::~C_Sprite(this: (C_Sprite *)m_entFlameScales);
  }
  m_entFlamesFromAbove = this->m_entFlamesFromAbove;
  for ( j = 3; j >= 0; --j )
  {
    m_entFlamesFromAbove = (C_FireFromAboveSprite *)((char *)m_entFlamesFromAbove - 2552);
    C_Sprite::~C_Sprite(this: m_entFlamesFromAbove);
  }
  m_pObj = this->m_pSmokeEmitter.m_pObj;
  if ( m_pObj != nullptr )
    CParticleEffect::Release(this: m_pObj);
  C_BaseEntity::~C_BaseEntity(this);
}

//------------------------------------------------------------------------------
// Address: 0x1006AE90
// Name: public: void C_FireSmoke::Start(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_FireSmoke::Start(C_FireSmoke *this)
{
  __m128 v1; // xmm2
  __m128 m_flStartScale_low; // xmm0
  __m128 v4; // xmm3
  __m128 v5; // xmm1
  __m128 v6; // xmm2
  int v7; // eax
  int v8; // eax
  const char *v9; // ecx
  CNewParticleEffect *v10; // eax
  CUtlReference<CSheet> *p_m_hEffect; // esi
  CNewParticleEffect *v12; // edi
  CUtlIntrusiveDList<CUtlReference<CSheet> > *p_m_References; // eax
  CUtlReference<CNewParticleEffect> *m_pHead; // eax

  v1.m128_i32[0] = 1258291200;
  m_flStartScale_low = (__m128)LODWORD(this->m_flStartScale);
  m_flStartScale_low.m128_f32[0] = m_flStartScale_low.m128_f32[0] * 0.027777778;
  v4 = _mm_and_ps((__m128)0x80000000, m_flStartScale_low);
  v1.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(m_flStartScale_low, v4), v1).m128_f32[0]) & 0x4B000000
                 | v4.m128_i32[0];
  v5 = m_flStartScale_low;
  v5.m128_f32[0] = (float)(m_flStartScale_low.m128_f32[0] + v1.m128_f32[0]) - v1.m128_f32[0];
  v6 = v5;
  v6.m128_f32[0] = v5.m128_f32[0] - m_flStartScale_low.m128_f32[0];
  v7 = (int)(float)(v5.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v6, v4).m128_u32[0] & 0x3F800000));
  if ( v7 != 0 )
  {
    v8 = v7 - 1;
    if ( v8 != 0 )
    {
      if ( v8 == 1 )
      {
        if ( (this->m_nFlags & 2) != 0 )
          v9 = "env_fire_medium_smoke";
        else
          v9 = "env_fire_medium";
      }
      else if ( (this->m_nFlags & 2) != 0 )
      {
        v9 = "env_fire_large_smoke";
      }
      else
      {
        v9 = "env_fire_large";
      }
    }
    else if ( (this->m_nFlags & 2) != 0 )
    {
      v9 = "env_fire_small_smoke";
    }
    else
    {
      v9 = "env_fire_small";
    }
  }
  else
  {
    v9 = "env_fire_tiny_smoke";
    if ( (this->m_nFlags & 2) == 0 )
      v9 = "env_fire_tiny";
  }
  v10 = CParticleProperty::Create(
          this: &this->m_Particles,
          pszParticleName: v9,
          iAttachType: PATTACH_ABSORIGIN,
          iAttachmentPoint: -1,
          vecOriginOffset: vec3_origin,
          matOffset: nullptr);
  p_m_hEffect = (CUtlReference<CSheet> *)&this->m_hEffect;
  v12 = v10;
  p_m_References = &p_m_hEffect->m_pObject->m_References;
  if ( p_m_References != (CUtlIntrusiveDList<CUtlReference<CSheet> > *)v12 )
  {
    if ( p_m_References != nullptr )
    {
      CUtlIntrusiveDList<CUtlReference<CNewParticleEffect>>::RemoveNode(this: p_m_References + 232, which: p_m_hEffect);
      p_m_hEffect->m_pObject = nullptr;
    }
    p_m_hEffect->m_pObject = (CSheet *)v12;
    if ( v12 != nullptr )
    {
      p_m_hEffect->m_pNext = (CUtlReference<CSheet> *)v12->m_References.m_pHead;
      m_pHead = v12->m_References.m_pHead;
      if ( m_pHead != nullptr )
        m_pHead->m_pPrev = (CUtlReference<CNewParticleEffect> *)p_m_hEffect;
      p_m_hEffect->m_pPrev = nullptr;
      v12->m_References.m_pHead = (CUtlReference<CNewParticleEffect> *)p_m_hEffect;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006B010
// Name: public: virtual void C_FireSmoke::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_FireSmoke::OnDataChanged(C_FireSmoke *this, DataUpdateType_t updateType)
{
  C_BaseEntity::OnDataChanged(this, type: updateType);
  if ( updateType == DATA_UPDATE_CREATED )
    C_FireSmoke::Start(this: (C_FireSmoke *)((char *)this - 8));
}

//------------------------------------------------------------------------------
// Address: 0x10411E80
// Name: SmokeStackMaterialsPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
CBaseResourcePrecacher *SmokeStackMaterialsPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  CBaseResourcePrecacher *result; // eax

  result = CBaseResourcePrecacher::sm_pFirst[0];
  SmokeStackMaterialsPrecache::s_ResourcePrecacher.m_pNext = CBaseResourcePrecacher::sm_pFirst[0];
  CBaseResourcePrecacher::sm_pFirst[0] = &SmokeStackMaterialsPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10411EC0
// Name: DT_FireSmoke::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_FireSmoke::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_FireSmoke::g_RecvTable);
  return atexit(func: DT_FireSmoke::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10411EE0
// Name: DT_FireSmoke::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_FireSmoke::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_FireSmoke::ignored>();
  DT_FireSmoke::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430270
// Name: DT_FireSmoke::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_FireSmoke::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_FireSmoke::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x1006AD60
// Name: _C_FireSmoke_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_FireSmoke_CreateObject(int entnum, int serialNum)
{
  C_FireSmoke *v2; // eax
  C_FireSmoke *v3; // eax
  C_FireSmoke *v4; // esi

  v2 = (C_FireSmoke *)C_BaseEntity::operator new(stAllocateBlock: 0x5978u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_FireSmoke::C_FireSmoke(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x10411EA0
// Name: _dynamic_initializer_for____g_C_FireSmokeClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_FireSmokeClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_FireSmokeClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_FireSmokeClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10411EF0
// Name: _dynamic_initializer_for__FishDebug__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__FishDebug__()
{
  ConVar::ConVar(
    this: &FishDebug,
    pName: "fish_debug",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Show debug info for fish");
  return atexit(func: dynamic_atexit_destructor_for__FishDebug__);
}

//------------------------------------------------------------------------------
// Address: 0x10411F20
// Name: _dynamic_initializer_for____g_C_FishClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_FishClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_FishClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_FishClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430280
// Name: _dynamic_atexit_destructor_for__FishDebug__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__FishDebug__()
{
  ConVar::~ConVar(this: &FishDebug);
}
