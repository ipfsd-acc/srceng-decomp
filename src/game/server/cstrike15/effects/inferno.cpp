// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/cstrike15/effects/inferno.cpp
// Functions: 85
// ============================================================

#include "game\server\cstrike15\effects\inferno.h"

//------------------------------------------------------------------------------
// Address: 0x1014C3A0
// Name: public: virtual bool CInferno::CanHarm(class CBaseEntity __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CInferno::CanHarm(CBaseEntity *this, CBaseEntity *other)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102D8880
// Name: public: virtual class ServerClass __near * CInferno::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CInferno::GetServerClass(CInferno *this)
{
  return &g_CInferno_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x102D8890
// Name: public: virtual struct datamap_t __near * CInferno::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CInferno::GetDataDescMap(CInferno *this)
{
  return &CInferno::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x102D88A0
// Name: public: virtual void infernoPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall infernoPrecache::CResourcePrecacher::Cache(
        infernoPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "inferno",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102D88D0
// Name: public: virtual class ServerClass __near * CFireCrackerBlast::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CFireCrackerBlast::GetServerClass(CFireCrackerBlast *this)
{
  return &g_CFireCrackerBlast_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x102D88E0
// Name: public: virtual void fire_cracker_blastPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall fire_cracker_blastPrecache::CResourcePrecacher::Cache(
        fire_cracker_blastPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "fire_cracker_blast",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102D8990
// Name: public: virtual CInferno::~CInferno(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInferno::~CInferno(CInferno *this)
{
  int v2; // ebx
  void **m_fire; // esi
  int m_Value; // eax

  v2 = 0;
  this->__vftable = (CInferno_vtbl *)&CInferno::`vftable';
  if ( this->m_fireCount.m_Value > 0 )
  {
    m_fire = (void **)this->m_fire;
    do
    {
      free(pMem: *m_fire);
      *m_fire = nullptr;
      ++v2;
      ++m_fire;
    }
    while ( v2 < this->m_fireCount.m_Value );
  }
  m_Value = this->m_nInfernoType.m_Value;
  if ( m_Value != 0 )
  {
    if ( m_Value == 1 )
    {
      CBaseEntity::EmitSound(this, soundname: "FireworksCrate.Stop", soundtime: 0.0, duration: nullptr);
      CBaseEntity::StopSound(this, soundname: "FireworksCrate.Start");
      CBaseEntity::~CBaseEntity(this);
      return;
    }
  }
  else
  {
    CBaseEntity::EmitSound(this, soundname: "Inferno.FadeOut", soundtime: 0.0, duration: nullptr);
    CBaseEntity::StopSound(this, soundname: "Inferno.Loop");
  }
  CBaseEntity::~CBaseEntity(this);
}

//------------------------------------------------------------------------------
// Address: 0x102D8A40
// Name: public: virtual int CInferno::UpdateTransmitState(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CInferno::UpdateTransmitState(IceKey *this)
{
  return 8;
}

//------------------------------------------------------------------------------
// Address: 0x102D8A50
// Name: public: virtual void CInferno::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInferno::Precache(CInferno *this)
{
  const char *v2; // eax
  const char *v3; // eax

  CBaseEntity::PrecacheScriptSound(soundname: "Inferno.Start");
  CBaseEntity::PrecacheScriptSound(soundname: "Inferno.StartSweeten");
  CBaseEntity::PrecacheScriptSound(soundname: "Inferno.Loop");
  CBaseEntity::PrecacheScriptSound(soundname: "Inferno.Fire.Ignite");
  CBaseEntity::PrecacheScriptSound(soundname: "Inferno.FadeOut");
  CBaseEntity::PrecacheScriptSound(soundname: "FireworksCrate.Start");
  CBaseEntity::PrecacheScriptSound(soundname: "FireworksCrate.Stop");
  if ( this->GetParticleEffectName(this) != nullptr )
  {
    v2 = this->GetParticleEffectName(this);
    PrecacheParticleSystem(pParticleSystemName: v2);
  }
  if ( this->GetImpactParticleEffectName(this) != nullptr )
  {
    v3 = this->GetImpactParticleEffectName(this);
    PrecacheParticleSystem(pParticleSystemName: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D8AF0
// Name: public: virtual float CInferno::GetDamagePerSecond(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CInferno::GetDamagePerSecond(CInferno *this)
{
  return InfernoDamage.m_pParent->m_Value.m_fValue;
}

//------------------------------------------------------------------------------
// Address: 0x102D8B00
// Name: public: virtual float CInferno::GetFlameLifetime(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CInferno::GetFlameLifetime(CInferno *this)
{
  return InfernoFlameLifetime.m_pParent->m_Value.m_fValue;
}

//------------------------------------------------------------------------------
// Address: 0x102D8B10
// Name: private: void CInferno::RecomputeExtent(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInferno::RecomputeExtent(CInferno *this)
{
  int v1; // edx
  float m_maxFireHalfWidth; // xmm1_4
  float x; // xmm6_4
  float v4; // xmm5_4
  float y; // xmm4_4
  float v6; // xmm3_4
  float z; // xmm2_4
  CInferno::FireInfo **m_fire; // esi
  float *v9; // eax
  float v10; // xmm0_4
  float v11; // xmm0_4
  float v12; // xmm0_4
  float v13; // xmm0_4
  float v14; // xmm0_4
  float v15; // xmm0_4
  float m_maxFireHeight; // [esp+0h] [ebp-8h]
  float v17; // [esp+4h] [ebp-4h]

  this->m_extent.lo.x = 999999.88;
  this->m_extent.lo.y = 999999.88;
  this->m_extent.lo.z = 999999.88;
  v1 = 0;
  this->m_extent.hi.x = -999999.88;
  this->m_extent.hi.y = -999999.88;
  this->m_extent.hi.z = -999999.88;
  if ( this->m_fireCount.m_Value > 0 )
  {
    m_maxFireHalfWidth = this->m_maxFireHalfWidth;
    x = this->m_extent.lo.x;
    v4 = this->m_extent.hi.x;
    y = this->m_extent.lo.y;
    v6 = this->m_extent.hi.y;
    z = this->m_extent.hi.z;
    m_maxFireHeight = this->m_maxFireHeight;
    v17 = this->m_extent.lo.z;
    m_fire = this->m_fire;
    do
    {
      v9 = (float *)*m_fire;
      v10 = (*m_fire)->m_pos.x - m_maxFireHalfWidth;
      if ( x > v10 )
      {
        x = (*m_fire)->m_pos.x - m_maxFireHalfWidth;
        this->m_extent.lo.x = v10;
      }
      v11 = *v9 + m_maxFireHalfWidth;
      if ( v11 > v4 )
      {
        v4 = *v9 + m_maxFireHalfWidth;
        this->m_extent.hi.x = v11;
      }
      v12 = v9[1] - m_maxFireHalfWidth;
      if ( y > v12 )
      {
        y = v9[1] - m_maxFireHalfWidth;
        this->m_extent.lo.y = v12;
      }
      v13 = v9[1] + m_maxFireHalfWidth;
      if ( v13 > v6 )
      {
        v6 = v9[1] + m_maxFireHalfWidth;
        this->m_extent.hi.y = v13;
      }
      v14 = v9[2];
      if ( v17 > v14 )
      {
        v17 = v9[2];
        this->m_extent.lo.z = v14;
      }
      v15 = v9[2] + m_maxFireHeight;
      if ( v15 > z )
      {
        z = v9[2] + m_maxFireHeight;
        this->m_extent.hi.z = v15;
      }
      ++v1;
      ++m_fire;
    }
    while ( v1 < this->m_fireCount.m_Value );
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D8C70
// Name: public: bool CInferno::IsTouching(class Vector const __near &,class Vector const __near &,class Vector __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CInferno::IsTouching(CInferno *this, const Vector *from, const Vector *to, Vector *where)
{
  bool v4; // cc
  CInferno::FireInfo **j; // edi
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm3_4
  float v10; // xmm0_4
  float v11; // xmm0_4
  float x; // xmm0_4
  float y; // xmm6_4
  float z; // xmm2_4
  float v15; // xmm1_4
  float v16; // xmm3_4
  float v18; // [esp+14h] [ebp-18h]
  Vector vec; // [esp+18h] [ebp-14h] BYREF
  CInferno *v20; // [esp+24h] [ebp-8h]
  int i; // [esp+28h] [ebp-4h]
  float toa; // [esp+38h] [ebp+Ch]

  v4 = this->m_fireCount.m_Value <= 0;
  v20 = this;
  i = 0;
  if ( v4 )
    return 0;
  for ( j = this->m_fire; ; ++j )
  {
    v7 = (*j)->m_center.x - from->x;
    v8 = (*j)->m_center.y - from->y;
    v18 = (*j)->m_center.z - from->z;
    v9 = to->x - from->x;
    vec.y = to->y - from->y;
    v10 = to->z - from->z;
    vec.x = v9;
    vec.z = v10;
    toa = VectorNormalize(&vec);
    v11 = (float)((float)(vec.x * v7) + (float)(vec.y * v8)) + (float)(vec.z * v18);
    if ( v11 >= 0.0 )
    {
      if ( v11 <= toa )
      {
        v15 = (float)(vec.y * v11) + from->y;
        v16 = vec.z * v11;
        x = from->x + (float)(vec.x * v11);
        z = from->z + v16;
        y = v15;
      }
      else
      {
        x = to->x;
        y = to->y;
        z = to->z;
      }
    }
    else
    {
      x = from->x;
      y = from->y;
      z = from->z;
    }
    if ( (float)((float)(v20->m_maxFireHalfWidth * 2.0) * (float)(v20->m_maxFireHalfWidth * 2.0)) > (float)((float)((float)((float)(y - (*j)->m_center.y) * (float)(y - (*j)->m_center.y)) + (float)((float)(x - (*j)->m_center.x) * (float)(x - (*j)->m_center.x))) + (float)((float)(z - (*j)->m_center.z) * (float)(z - (*j)->m_center.z))) )
      break;
    if ( ++i >= v20->m_fireCount.m_Value )
      return 0;
  }
  if ( where != nullptr )
  {
    where->x = x;
    where->y = y;
    where->z = z;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102D8E20
// Name: public: bool CInferno::IsTouching(class CNavArea const __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CInferno::IsTouching(CInferno *this, CNavArea *area)
{
  int v3; // edi
  CInferno::FireInfo **i; // esi
  const Vector *v5; // eax
  Vector close; // [esp+Ch] [ebp-10h] BYREF
  float v8; // [esp+18h] [ebp-4h]

  if ( area == nullptr )
    return 0;
  v3 = 0;
  if ( this->m_fireCount.m_Value <= 0 )
    return 0;
  v8 = (float)(this->m_maxFireHalfWidth * 2.0) * (float)(this->m_maxFireHalfWidth * 2.0);
  for ( i = this->m_fire; ; ++i )
  {
    CNavArea::GetClosestPointOnArea(this: area, pPos: &(*i)->m_center, &close);
    v5 = (const Vector *)*i;
    close.z = (*i)->m_flWaterHeight + close.z;
    if ( v8 > (float)((float)((float)((float)(close.x - v5[1].x) * (float)(close.x - v5[1].x))
                            + (float)((float)(close.y - v5[1].y) * (float)(close.y - v5[1].y)))
                    + (float)((float)(close.z - v5[1].z) * (float)(close.z - v5[1].z))) )
      break;
    if ( ++v3 >= this->m_fireCount.m_Value )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102D8EF0
// Name: public: void CInferno::NetworkVar_m_fireXDelta::Set(int,int const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInferno::NetworkVar_m_fireXDelta::Set(CInferno::NetworkVar_m_fireXDelta *this, int i, const int *val)
{
  char *v4; // eax
  CBaseEdict *v5; // ecx

  if ( this->m_Value[i] != *val )
  {
    v4 = (char *)this - 852;
    if ( *((_BYTE *)this - 768) != 0 )
    {
      v4[88] |= 1u;
      this->m_Value[i] = *val;
    }
    else
    {
      v5 = *((CBaseEdict **)v4 + 6);
      if ( v5 != nullptr )
        CBaseEdict::StateChanged(this: v5, offset: (_WORD)this + 4 * i - (_WORD)v4);
      this->m_Value[i] = *val;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D8F50
// Name: public: void CInferno::NetworkVar_m_fireYDelta::Set(int,int const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInferno::NetworkVar_m_fireYDelta::Set(CInferno::NetworkVar_m_fireYDelta *this, int i, const int *val)
{
  char *v4; // eax
  CBaseEdict *v5; // ecx

  if ( this->m_Value[i] != *val )
  {
    v4 = (char *)this - 1108;
    if ( *((_BYTE *)this - 1024) != 0 )
    {
      v4[88] |= 1u;
      this->m_Value[i] = *val;
    }
    else
    {
      v5 = *((CBaseEdict **)v4 + 6);
      if ( v5 != nullptr )
        CBaseEdict::StateChanged(this: v5, offset: (_WORD)this + 4 * i - (_WORD)v4);
      this->m_Value[i] = *val;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D8FB0
// Name: public: void CInferno::NetworkVar_m_fireZDelta::Set(int,int const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInferno::NetworkVar_m_fireZDelta::Set(CInferno::NetworkVar_m_fireZDelta *this, int i, const int *val)
{
  char *v4; // eax
  CBaseEdict *v5; // ecx

  if ( this->m_Value[i] != *val )
  {
    v4 = (char *)this - 1364;
    if ( *((_BYTE *)this - 1280) != 0 )
    {
      v4[88] |= 1u;
      this->m_Value[i] = *val;
    }
    else
    {
      v5 = *((CBaseEdict **)v4 + 6);
      if ( v5 != nullptr )
        CBaseEdict::StateChanged(this: v5, offset: (_WORD)this + 4 * i - (_WORD)v4);
      this->m_Value[i] = *val;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D9010
// Name: public: void CInferno::NetworkVar_m_BurnNormal::Set(int,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInferno::NetworkVar_m_BurnNormal::Set(
        CInferno::NetworkVar_m_BurnNormal *this,
        int i,
        const Vector *val)
{
  const Vector *v3; // eax
  __int16 v4; // di
  unsigned int v5; // edx
  char *v6; // eax
  CBaseEdict *v7; // edx
  Vector *ia; // [esp+14h] [ebp+8h]

  v3 = val;
  v4 = i;
  ia = &this->m_Value[i];
  v5 = 12;
  while ( *(_DWORD *)((char *)&v3->x + (char *)ia - (char *)val) == LODWORD(v3->x) )
  {
    v5 -= 4;
    v3 = (const Vector *)((char *)v3 + 4);
    if ( v5 < 4 )
      return;
  }
  v6 = (char *)this - 1620;
  if ( *((_BYTE *)this - 1536) != 0 )
  {
    v6[88] |= 1u;
  }
  else
  {
    v7 = *((CBaseEdict **)v6 + 6);
    if ( v7 != nullptr )
      CBaseEdict::StateChanged(this: v7, offset: 12 * v4 + 1620);
  }
  *ia = *val;
}

//------------------------------------------------------------------------------
// Address: 0x102D9230
// Name: private: bool CInferno::IsTouching(class CBaseEntity __near *,float,bool)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CInferno::IsTouching(CInferno *this, CBaseEntity *entity, float radius, bool checkLOS)
{
  CInferno::FireInfo **j; // ebx
  const Vector *v6; // edi
  const Vector *p_m_center; // esi
  CGameTrace tr; // [esp+10h] [ebp-68h] BYREF
  Vector pos; // [esp+64h] [ebp-14h] BYREF
  CInferno *v11; // [esp+70h] [ebp-8h]
  CCollisionProperty *p_m_Collision; // [esp+74h] [ebp-4h]
  IHandleEntity savedregs; // [esp+78h] [ebp+0h] BYREF
  int i; // [esp+80h] [ebp+8h]
  float radiusa; // [esp+84h] [ebp+Ch]

  v11 = this;
  if ( entity == nullptr )
    return 0;
  i = 0;
  if ( this->m_fireCount.m_Value <= 0 )
    return 0;
  p_m_Collision = &entity->m_Collision;
  radiusa = radius * radius;
  for ( j = this->m_fire; ; ++j )
  {
    v6 = (const Vector *)*j;
    p_m_center = &(*j)->m_center;
    CCollisionProperty::CalcNearestPoint(this: p_m_Collision, vecWorldPt: p_m_center, pVecNearestWorldPt: &pos);
    if ( radiusa > (float)((float)((float)((float)(pos.x - v6[1].x) * (float)(pos.x - v6[1].x))
                                 + (float)((float)(pos.y - v6[1].y) * (float)(pos.y - v6[1].y)))
                         + (float)((float)(pos.z - v6[1].z) * (float)(pos.z - v6[1].z))) )
    {
      if ( !checkLOS )
        break;
      UTIL_TraceLine(
        a1: &savedregs,
        a2: (int)p_m_center,
        vecAbsStart: v6 + 1,
        vecAbsEnd: &pos,
        mask: 0x4003u,
        ignore: nullptr,
        collisionGroup: 0,
        ptr: &tr);
      if ( tr.fraction == 1.0 )
      {
        if ( InfernoDebug.m_pParent != nullptr && InfernoDebug.m_pParent->m_Value.m_nValue != 0 )
          NDebugOverlay::Line(origin: v6 + 1, target: &pos, r: 255, g: 0, b: 255, noDepthTest: 1, duration: 50.200001);
        return 1;
      }
      if ( InfernoDebug.m_pParent != nullptr && InfernoDebug.m_pParent->m_Value.m_nValue != 0 )
        NDebugOverlay::Line(origin: v6 + 1, target: &pos, r: 255, g: 0, b: 0, noDepthTest: 1, duration: 50.200001);
    }
    if ( ++i >= v11->m_fireCount.m_Value )
      return 0;
  }
  if ( InfernoDebug.m_pParent == nullptr || InfernoDebug.m_pParent->m_Value.m_nValue == 0 )
    return 1;
  NDebugOverlay::Line(origin: v6 + 1, target: &pos, r: 255, g: 0, b: 255, noDepthTest: 1, duration: 0.2);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102D93E0
// Name: public: CInferno::CInferno(void)
// Source: json
//------------------------------------------------------------------------------
CInferno *__thiscall CInferno::CInferno(CInferno *this)
{
  CountdownTimer_vtbl *v2; // edx
  CountdownTimer_vtbl *v3; // edx
  CountdownTimer_vtbl *v4; // edx
  CountdownTimer_vtbl *v5; // edx
  IntervalTimer_vtbl *v6; // edx
  CountdownTimer_vtbl *v7; // edx
  CountdownTimer_vtbl *v8; // edx

  CBaseEntity::CBaseEntity(this, bServerOnly: false);
  this->__vftable = (CInferno_vtbl *)&CInferno::`vftable';
  this->m_damageTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v2 = this->m_damageTimer.__vftable;
  this->m_damageTimer.m_duration.m_Value = 0.0;
  ((void (__stdcall *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v2->NetworkStateChanged)(a1: &this->m_damageTimer.m_duration);
  v3 = this->m_damageTimer.__vftable;
  this->m_damageTimer.m_timestamp.m_Value = -1.0;
  v3->NetworkStateChanged(this: &this->m_damageTimer, a2: &this->m_damageTimer.m_timestamp);
  this->m_damageRampTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v4 = this->m_damageRampTimer.__vftable;
  this->m_damageRampTimer.m_duration.m_Value = 0.0;
  ((void (__stdcall *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v4->NetworkStateChanged)(a1: &this->m_damageRampTimer.m_duration);
  v5 = this->m_damageRampTimer.__vftable;
  this->m_damageRampTimer.m_timestamp.m_Value = -1.0;
  v5->NetworkStateChanged(this: &this->m_damageRampTimer, a2: &this->m_damageRampTimer.m_timestamp);
  this->m_activeTimer.__vftable = (IntervalTimer_vtbl *)&IntervalTimer::`vftable';
  v6 = this->m_activeTimer.__vftable;
  this->m_activeTimer.m_timestamp.m_Value = -1.0;
  ((void (__stdcall *)(CNetworkVarBase<float,IntervalTimer::NetworkVar_m_timestamp> *))v6->NetworkStateChanged)(a1: &this->m_activeTimer.m_timestamp);
  this->m_NextSpreadTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v7 = this->m_NextSpreadTimer.__vftable;
  this->m_NextSpreadTimer.m_duration.m_Value = 0.0;
  ((void (__stdcall *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v7->NetworkStateChanged)(a1: &this->m_NextSpreadTimer.m_duration);
  v8 = this->m_NextSpreadTimer.__vftable;
  this->m_NextSpreadTimer.m_timestamp.m_Value = -1.0;
  v8->NetworkStateChanged(this: &this->m_NextSpreadTimer, a2: &this->m_NextSpreadTimer.m_timestamp);
  if ( InfernoMaxFlames.m_pParent != nullptr )
    this->m_nMaxFlames = InfernoMaxFlames.m_pParent->m_Value.m_nValue;
  else
    this->m_nMaxFlames = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102D9500
// Name: public: CInferno::FireInfo::FireInfo(void)
// Source: json
//------------------------------------------------------------------------------
CInferno::FireInfo *__thiscall CInferno::FireInfo::FireInfo(CInferno::FireInfo *this)
{
  CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *p_m_duration; // eax
  CountdownTimer *p_m_spawnLifetime; // ecx
  CountdownTimer_vtbl *v4; // edx
  CountdownTimer_vtbl *v5; // edx
  CountdownTimer_vtbl *v6; // edx
  CountdownTimer_vtbl *v7; // edx
  CountdownTimer_vtbl *v8; // edx
  CountdownTimer_vtbl *v9; // edx

  p_m_duration = &this->m_spawnLifetime.m_duration;
  p_m_spawnLifetime = &this->m_spawnLifetime;
  this->m_spawnLifetime.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v4 = p_m_spawnLifetime->__vftable;
  p_m_duration->m_Value = 0.0;
  v4->NetworkStateChanged(this: p_m_spawnLifetime, a2: p_m_duration);
  v5 = this->m_spawnLifetime.__vftable;
  this->m_spawnLifetime.m_timestamp.m_Value = -1.0;
  v5->NetworkStateChanged(this: &this->m_spawnLifetime, a2: &this->m_spawnLifetime.m_timestamp);
  this->m_spawnTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v6 = this->m_spawnTimer.__vftable;
  this->m_spawnTimer.m_duration.m_Value = 0.0;
  ((void (__stdcall *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v6->NetworkStateChanged)(a1: &this->m_spawnTimer.m_duration);
  v7 = this->m_spawnTimer.__vftable;
  this->m_spawnTimer.m_timestamp.m_Value = -1.0;
  v7->NetworkStateChanged(this: &this->m_spawnTimer, a2: &this->m_spawnTimer.m_timestamp);
  this->m_lifetime.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v8 = this->m_lifetime.__vftable;
  this->m_lifetime.m_duration.m_Value = 0.0;
  ((void (__stdcall *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v8->NetworkStateChanged)(a1: &this->m_lifetime.m_duration);
  v9 = this->m_lifetime.__vftable;
  this->m_lifetime.m_timestamp.m_Value = -1.0;
  v9->NetworkStateChanged(this: &this->m_lifetime, a2: &this->m_lifetime.m_timestamp);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102D9660
// Name: private: bool CInferno::CreateFire(class Vector const __near &,class Vector const __near &,struct CInferno::FireInfo __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CInferno::CreateFire@<al>(
        CInferno *this@<ecx>,
        int a2@<esi>,
        const Vector *pos,
        const Vector *normal,
        CInferno::FireInfo *parent,
        int depth)
{
  int m_nMaxFlames; // eax
  IEngineTrace_vtbl *v10; // edx
  int (__thiscall *GetPointContents)(IEngineTrace *, const Vector *, int, IHandleEntity **); // eax
  CInferno::FireInfo *v12; // eax
  CInferno::FireInfo *v13; // esi
  float z; // xmm1_4
  float x; // xmm2_4
  float y; // xmm3_4
  int v17; // ecx
  float v18; // xmm0_4
  CInferno::FireInfo *v19; // eax
  double v20; // st7
  float (__thiscall *GetFlameLifetime)(CInferno *); // eax
  double v22; // st7
  double v23; // st7
  CInferno::FireInfo *v24; // ebx
  float m_Value; // xmm0_4
  float v26; // xmm0_4
  float m_fValue; // xmm0_4
  float v28; // xmm0_4
  int v29; // eax
  float v30; // xmm1_4
  int v31; // eax
  int v32; // eax
  CInferno::FireInfo *v33; // edx
  edict_t *m_pPev; // ecx
  float attenuation; // [esp+Ch] [ebp-1A4h]
  CSoundParameters params; // [esp+1Ch] [ebp-194h] BYREF
  CGameTrace tr; // [esp+D0h] [ebp-E0h] BYREF
  CGameTrace ptr; // [esp+124h] [ebp-8Ch] BYREF
  CPASAttenuationFilter filter; // [esp+178h] [ebp-38h] BYREF
  Vector firePos; // [esp+198h] [ebp-18h]
  Vector vecDelta; // [esp+1A4h] [ebp-Ch] BYREF
  IHandleEntity savedregs; // [esp+1B0h] [ebp+0h] BYREF
  char overWater_3; // [esp+1BBh] [ebp+Bh]

  m_nMaxFlames = this->m_nMaxFlames;
  if ( m_nMaxFlames > 64 )
    m_nMaxFlames = 64;
  if ( this->m_fireCount.m_Value >= m_nMaxFlames )
    return 0;
  if ( CInferno::IsTouching(this, from: pos, to: pos, where: nullptr) != 0 )
    return 0;
  if ( InfernoDebug.m_pParent != nullptr && InfernoDebug.m_pParent->m_Value.m_nValue != 0 && parent != nullptr )
    NDebugOverlay::Line(origin: &parent->m_pos, target: pos, r: 0, g: 255, b: 255, noDepthTest: 1, duration: 10.0);
  v10 = enginetrace->__vftable;
  firePos.z = pos->z;
  GetPointContents = v10->GetPointContents;
  *(_QWORD *)&firePos.x = *(_QWORD *)&pos->x;
  overWater_3 = 0;
  if ( (GetPointContents(this: enginetrace, a2: pos, a3: 16432, a4: nullptr) & 0x30) != 0 )
  {
    vecDelta.x = pos->x;
    vecDelta.y = pos->y;
    vecDelta.z = pos->z + 30.0;
    UTIL_TraceLine(
      a1: &savedregs,
      a2,
      vecAbsStart: &vecDelta,
      vecAbsEnd: pos,
      mask: 0x403Bu,
      ignore: nullptr,
      collisionGroup: 0,
      ptr: &tr);
    if ( tr.allsolid )
      return 0;
    firePos = tr.endpos;
    overWater_3 = 1;
  }
  v12 = (CInferno::FireInfo *)operator new(nSize: 0x58u);
  if ( v12 != nullptr )
    v13 = CInferno::FireInfo::FireInfo(this: v12);
  else
    v13 = nullptr;
  z = firePos.z;
  x = firePos.x;
  y = firePos.y;
  v17 = depth;
  v13->m_pos = firePos;
  v18 = this->m_maxFireHeight * 0.5;
  v13->m_center.x = x;
  v13->m_center.y = y;
  v13->m_center.z = v18 + z;
  v13->m_normal.x = normal->x;
  v13->m_normal.y = normal->y;
  v19 = parent;
  v13->m_normal.z = normal->z;
  v13->m_parent = v19;
  v13->m_treeDepth = v17;
  v13->m_spawnCount = 0;
  v13->m_flWaterHeight = z - pos->z;
  if ( this->m_activeTimer.m_timestamp.m_Value <= 0.0 )
  {
    v23 = ((double (__thiscall *)(CInferno *))this->GetFlameLifetime)(a1: this);
  }
  else
  {
    v20 = IntervalTimer::Now(this: (CEffectsServer *)&this->m_activeTimer);
    GetFlameLifetime = this->GetFlameLifetime;
    *(float *)&depth = v20 - this->m_activeTimer.m_timestamp.m_Value;
    v22 = ((double (__thiscall *)(CInferno *))GetFlameLifetime)(a1: this);
    v23 = v22 - *(float *)&depth;
  }
  attenuation = v23;
  CountdownTimer::Start(this: &v13->m_lifetime, duration: attenuation);
  v24 = parent;
  if ( parent != nullptr )
  {
    m_Value = 0.0;
    if ( parent->m_spawnLifetime.m_timestamp.m_Value > 0.0 )
      m_Value = parent->m_spawnLifetime.m_duration.m_Value;
    CountdownTimer::Start(this: &v13->m_spawnLifetime, duration: m_Value);
    v26 = 0.0;
    if ( v24->m_spawnTimer.m_timestamp.m_Value > 0.0 )
      v26 = v24->m_spawnTimer.m_duration.m_Value;
    m_fValue = v26 * InfernoChildSpawnIntervalMultiplier.m_pParent->m_Value.m_fValue;
    if ( m_fValue > InfernoMaxChildSpawnInterval.m_pParent->m_Value.m_fValue )
      m_fValue = InfernoMaxChildSpawnInterval.m_pParent->m_Value.m_fValue;
  }
  else
  {
    CountdownTimer::Start(
      this: &v13->m_spawnLifetime,
      duration: InfernoPerFlameSpawnDuration.m_pParent->m_Value.m_fValue);
    m_fValue = InfernoInitialSpawnInterval.m_pParent->m_Value.m_fValue;
  }
  CountdownTimer::Start(this: &v13->m_spawnTimer, duration: m_fValue);
  this->m_fire[this->m_fireCount.m_Value] = v13;
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  v28 = v13->m_pos.x - this->m_vecAbsOrigin.x;
  v29 = this->m_fireCount.m_Value;
  vecDelta.y = v13->m_pos.y - this->m_vecAbsOrigin.y;
  v30 = v13->m_pos.z - this->m_vecAbsOrigin.z;
  parent = (CInferno::FireInfo *)(int)v28;
  vecDelta.z = v30;
  CInferno::NetworkVar_m_fireXDelta::Set(this: &this->m_fireXDelta, i: v29, val: (const int *)&parent);
  v31 = this->m_fireCount.m_Value;
  parent = (CInferno::FireInfo *)(int)vecDelta.y;
  CInferno::NetworkVar_m_fireYDelta::Set(this: &this->m_fireYDelta, i: v31, val: (const int *)&parent);
  v32 = this->m_fireCount.m_Value;
  parent = (CInferno::FireInfo *)(int)vecDelta.z;
  CInferno::NetworkVar_m_fireZDelta::Set(this: &this->m_fireZDelta, i: v32, val: (const int *)&parent);
  CInferno::NetworkVar_m_BurnNormal::Set(this: &this->m_BurnNormal, i: this->m_fireCount.m_Value, val: normal);
  v33 = (CInferno::FireInfo *)(this->m_fireCount.m_Value + 1);
  parent = v33;
  if ( this->m_Network.m_TimerEvent.m_bRegistered )
  {
    *((_BYTE *)&this->m_Network + 76) |= 1u;
  }
  else
  {
    m_pPev = this->m_Network.m_pPev;
    if ( m_pPev != nullptr )
    {
      CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x954u);
      v33 = parent;
    }
  }
  this->m_fireCount.m_Value = (int)v33;
  CInferno::RecomputeExtent(this);
  if ( this->m_nInfernoType.m_Value == 0 )
  {
    CSoundParameters::CSoundParameters(this: &params);
    if ( CBaseEntity::GetParametersForSound(soundname: "Inferno.Fire.Ignite", &params, actormodel: nullptr) )
    {
      EmitSound_t::EmitSound_t(this: (EmitSound_t *)&ptr.endpos, src: &params);
      LODWORD(ptr.plane.dist) = v13;
      CPASAttenuationFilter::CPASAttenuationFilter(this: &filter, origin: &v13->m_pos, attenuation: 0.80000001);
      CBaseEntity::EmitSound(&filter, iEntIndex: 0, params: (const EmitSound_t *)&ptr.endpos);
      CRecipientFilter::~CRecipientFilter(this: &filter);
      CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&ptr.fractionleftsolid);
    }
    if ( inferno_scorch_decals.m_pParent != nullptr
      && inferno_scorch_decals.m_pParent->m_Value.m_nValue != 0
      && overWater_3 == 0 )
    {
      vecDelta.x = v13->m_pos.x;
      vecDelta.y = v13->m_pos.y;
      vecDelta.z = v13->m_pos.z - 100.0;
      UTIL_TraceLine(
        a1: &savedregs,
        a2: (int)v13,
        vecAbsStart: &v13->m_pos,
        vecAbsEnd: &vecDelta,
        mask: 0x4081u,
        ignore: nullptr,
        collisionGroup: 0,
        &ptr);
      UTIL_DecalTrace(pTrace: &ptr, decalName: "MolotovScorch");
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102D9B10
// Name: public: void CInferno::StartBurning(class Vector const __near &,class Vector const __near &,class Vector const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CInferno::StartBurning(
        CInferno *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        const Vector *pos,
        const Vector *normal,
        const Vector *velocity,
        int initialDepth)
{
  float y; // xmm1_4
  float v10; // xmm4_4
  float x; // xmm2_4
  float v12; // xmm5_4
  float z; // xmm3_4
  float v14; // xmm6_4
  float v15; // xmm0_4
  float m_fValue; // xmm7_4
  const char *v17; // eax
  int m_Value; // eax
  CInferno::FireInfo *v19; // eax
  double v20; // st7
  double v21; // st6
  CNetworkVarBase<float,IntervalTimer::NetworkVar_m_timestamp> *p_m_timestamp; // esi
  QAngle splashangle; // [esp+24h] [ebp-Ch] BYREF
  float normala; // [esp+3Ch] [ebp+Ch]
  Vector v26; // 0:^4.12
  QAngle radius; // 0:^10.12

  this->m_startPos.x = (float)(InfernoSurfaceOffset.m_pParent->m_Value.m_fValue * normal->x) + pos->x;
  this->m_startPos.y = (float)(InfernoSurfaceOffset.m_pParent->m_Value.m_fValue * normal->y) + pos->y;
  this->m_startPos.z = pos->z;
  y = normal->y;
  v10 = velocity->y;
  x = normal->x;
  v12 = velocity->x;
  z = normal->z;
  v14 = velocity->z;
  v15 = (float)((float)(v10 * y) + (float)(velocity->x * normal->x)) + (float)(v14 * z);
  splashangle.x = normal->x * v15;
  splashangle.y = y * v15;
  splashangle.z = z * v15;
  m_fValue = InfernoVelocityNormalFactor.m_pParent->m_Value.m_fValue;
  this->m_splashVelocity.x = (float)(v12 - splashangle.x) - (float)((float)(x * m_fValue) * v15);
  this->m_splashVelocity.y = (float)(v10 - (float)(y * v15)) - (float)((float)(y * m_fValue) * v15);
  this->m_splashVelocity.z = (float)(v14 - (float)(z * v15)) - (float)((float)(z * m_fValue) * v15);
  VectorAngles(forward: velocity, angles: &splashangle);
  if ( ((int (__thiscall *)(CInferno *, int, int, int))this->GetImpactParticleEffectName)(
         a1: this,
         a2: a3,
         a3: a4,
         a4: a2) != 0 )
  {
    radius = splashangle;
    v26 = *pos;
    v17 = this->GetImpactParticleEffectName(this);
    DispatchParticleEffect(
      pszParticleName: v17,
      vecOrigin: v26,
      vecAngles: radius,
      pEntity: nullptr,
      nSplitScreenPlayerSlot: -1,
      filter: nullptr);
  }
  if ( InfernoDebug.m_pParent != nullptr && InfernoDebug.m_pParent->m_Value.m_nValue != 0 )
  {
    NDebugOverlay::Sphere(
      center: pos,
      radius: this->m_maxFireHalfWidth * 0.5,
      r: 0,
      g: 255,
      b: 0,
      noDepthTest: 1,
      flDuration: 10.0);
    NDebugOverlay::Sphere(
      center: &this->m_startPos,
      radius: this->m_maxFireHalfWidth * 0.5,
      r: 255,
      g: 255,
      b: 0,
      noDepthTest: 1,
      flDuration: 10.0);
  }
  if ( CInferno::CreateFire(this, a2: (int)this, pos: &this->m_startPos, normal, parent: nullptr, depth: initialDepth) != 0 )
  {
    m_Value = this->m_nInfernoType.m_Value;
    if ( m_Value != 0 )
    {
      if ( m_Value == 1 )
        CBaseEntity::EmitSound(this, soundname: "FireworksCrate.Start", soundtime: 0.0, duration: nullptr);
    }
    else
    {
      CBaseEntity::EmitSound(this, soundname: "Inferno.Start", soundtime: 0.0, duration: nullptr);
      CBaseEntity::EmitSound(this, soundname: "Inferno.StartSweeten", soundtime: 0.0, duration: nullptr);
      CBaseEntity::EmitSound(this, soundname: "Inferno.Loop", soundtime: 0.0, duration: nullptr);
    }
    v19 = this->m_fire[0];
    this->m_startPos.x = v19->m_pos.x;
    this->m_startPos.y = v19->m_pos.y;
    this->m_startPos.z = v19->m_pos.z;
    CBaseEntity::SetAbsOrigin(this, absOrigin: &this->m_startPos);
  }
  v20 = IntervalTimer::Now(this: (CEffectsServer *)&this->m_activeTimer);
  v21 = this->m_activeTimer.m_timestamp.m_Value;
  p_m_timestamp = &this->m_activeTimer.m_timestamp;
  if ( v21 != v20 )
  {
    (*(void (__thiscall **)(CNetworkVarBase<float,IntervalTimer::NetworkVar_m_timestamp> *, CNetworkVarBase<float,IntervalTimer::NetworkVar_m_timestamp> *))(LODWORD(p_m_timestamp[-1].m_Value) + 4))(
      a1: p_m_timestamp - 1,
      a2: p_m_timestamp);
    normala = v20;
    p_m_timestamp->m_Value = normala;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D9DE0
// Name: private: void CInferno::Spread(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CInferno::Spread(
        CInferno *this@<ecx>,
        int a2@<ebp>,
        Vector *p_to@<edi>,
        int a4@<esi>,
        const Vector *spreadVelocity)
{
  double v6; // st7
  bool v7; // cc
  CEffectsServer *v8; // ecx
  float *v9; // esi
  double v10; // st7
  int v11; // ecx
  float x; // eax
  CInferno::FireInfo *v13; // esi
  int m_spawnCount; // edx
  int v15; // eax
  int v16; // ecx
  float *p_x; // eax
  double v18; // xmm0_8
  double v19; // xmm0_8
  double v20; // st7
  double m_fValue; // xmm0_8
  float v22; // xmm3_4
  float v23; // xmm0_4
  float v24; // xmm4_4
  float y; // xmm6_4
  float z; // xmm7_4
  float v27; // xmm5_4
  float v28; // xmm0_4
  float v29; // xmm1_4
  float v30; // xmm4_4
  float v31; // xmm3_4
  float v32; // xmm2_4
  float v33; // xmm0_4
  float v34; // xmm1_4
  float v35; // xmm2_4
  float (__thiscall *RandomFloat)(IUniformRandomStream *, float, float); // eax
  float v37; // xmm0_4
  float v38; // xmm1_4
  float v39; // xmm2_4
  int v40; // xmm3_4
  float v41; // xmm4_4
  float v42; // xmm0_4
  float v43; // xmm2_4
  int v44; // xmm1_4
  float v45; // xmm3_4
  float v46; // xmm2_4
  float v47; // xmm3_4
  float v48; // xmm0_4
  float v49; // xmm1_4
  float v50; // xmm0_4
  float v51; // xmm4_4
  float v52; // xmm5_4
  float v53; // xmm0_4
  CTraceFilterSimple *v56; // [esp+4Ch] [ebp-174h]
  Vector *v57; // [esp+50h] [ebp-170h]
  CTraceFilterSimple v58; // [esp+54h] [ebp-16Ch] BYREF
  CTraceFilterSimple v59; // [esp+64h] [ebp-15Ch] BYREF
  Vector v60; // [esp+74h] [ebp-14Ch] BYREF
  CGameTrace tr; // [esp+80h] [ebp-140h] BYREF
  Vector v62; // [esp+DCh] [ebp-E4h] BYREF
  Vector normal; // [esp+E8h] [ebp-D8h] BYREF
  __int64 v64; // [esp+F4h] [ebp-CCh]
  float v65; // [esp+FCh] [ebp-C4h]
  Vector endPos; // [esp+100h] [ebp-C0h] BYREF
  QAngle angles; // [esp+10Ch] [ebp-B4h] BYREF
  Vector v68; // [esp+118h] [ebp-A8h] BYREF
  Vector to; // [esp+124h] [ebp-9Ch] BYREF
  float v70; // [esp+134h] [ebp-8Ch]
  float v71; // [esp+138h] [ebp-88h]
  float v72; // [esp+13Ch] [ebp-84h]
  int v73; // [esp+144h] [ebp-7Ch]
  int v74; // [esp+148h] [ebp-78h]
  int v75; // [esp+14Ch] [ebp-74h]
  int v76; // [esp+154h] [ebp-6Ch]
  int v77; // [esp+158h] [ebp-68h]
  int v78; // [esp+15Ch] [ebp-64h]
  int v79; // [esp+164h] [ebp-5Ch]
  char v80; // [esp+168h] [ebp-58h]
  bool v81; // [esp+169h] [ebp-57h]
  int v82; // [esp+174h] [ebp-4Ch]
  float v83; // [esp+178h] [ebp-48h]
  int v84; // [esp+17Ch] [ebp-44h]
  int depth; // [esp+180h] [ebp-40h] BYREF
  float velocityDecay; // [esp+184h] [ebp-3Ch]
  float v87; // [esp+188h] [ebp-38h]
  Vector fireDir; // [esp+18Ch] [ebp-34h] BYREF
  Vector out; // [esp+198h] [ebp-28h] BYREF
  Vector pos; // [esp+1A4h] [ebp-1Ch]
  int nextFireOffset; // [esp+1B0h] [ebp-10h]
  int t; // [esp+1B4h] [ebp-Ch]
  float angle; // [esp+1B8h] [ebp-8h]
  float retaddr; // [esp+1C0h] [ebp+0h]

  t = a2;
  angle = retaddr;
  if ( this->m_NextSpreadTimer.m_timestamp.m_Value <= 0.0
    || IntervalTimer::Now(this: (CEffectsServer *)&this->m_NextSpreadTimer) > this->m_NextSpreadTimer.m_timestamp.m_Value )
  {
    *(float *)&nextFireOffset = this->GetFlameSpreadDelay(this);
    v6 = IntervalTimer::Now(this: (CEffectsServer *)&this->m_NextSpreadTimer) + *(float *)&nextFireOffset;
    pos.x = v6;
    if ( this->m_NextSpreadTimer.m_timestamp.m_Value != v6 )
    {
      this->m_NextSpreadTimer.NetworkStateChanged(
        this: &this->m_NextSpreadTimer,
        a2: &this->m_NextSpreadTimer.m_timestamp);
      this->m_NextSpreadTimer.m_timestamp.m_Value = pos.x;
    }
    if ( this->m_NextSpreadTimer.m_duration.m_Value != *(float *)&nextFireOffset )
    {
      this->m_NextSpreadTimer.NetworkStateChanged(
        this: &this->m_NextSpreadTimer,
        a2: &this->m_NextSpreadTimer.m_duration);
      this->m_NextSpreadTimer.m_duration.m_Value = *(float *)&nextFireOffset;
    }
    v7 = this->m_fireCount.m_Value <= 0;
    pos.z = 0.0;
    if ( !v7 )
    {
      LODWORD(pos.y) = this->m_fire;
      do
      {
        v8 = (CEffectsServer *)(*(_DWORD *)LODWORD(pos.y) + 48);
        nextFireOffset = *(int *)LODWORD(pos.y);
        if ( IntervalTimer::Now(this: v8) <= *(float *)(nextFireOffset + 56) )
        {
          v9 = (float *)(nextFireOffset + 68);
          if ( IntervalTimer::Now(this: (CEffectsServer *)(nextFireOffset + 60)) > *(float *)(nextFireOffset + 68) )
          {
            v10 = IntervalTimer::Now(this: (CEffectsServer *)(nextFireOffset + 60)) + *(float *)(nextFireOffset + 64);
            pos.x = v10;
            if ( *v9 != v10 )
            {
              (**(void (__thiscall ***)(int, int))(nextFireOffset + 60))(
                a1: nextFireOffset + 60,
                a2: nextFireOffset + 68);
              *v9 = pos.x;
            }
            ++*(_DWORD *)(nextFireOffset + 40);
          }
        }
        LODWORD(pos.y) += 4;
        ++LODWORD(pos.z);
      }
      while ( SLODWORD(pos.z) < this->m_fireCount.m_Value );
    }
    v11 = 0;
    if ( inferno_max_trace_per_tick.m_pParent != nullptr )
      nextFireOffset = inferno_max_trace_per_tick.m_pParent->m_Value.m_nValue;
    else
      *(float *)&nextFireOffset = 0.0;
    LODWORD(x) = this->m_fireSpawnOffset + 1;
    v84 = 0;
    if ( this->m_fireCount.m_Value > 0 )
    {
      while ( 1 )
      {
        if ( nextFireOffset <= 0 )
          goto LABEL_56;
        v13 = this->m_fire[(v11 + this->m_fireSpawnOffset) % this->m_fireCount.m_Value];
        LODWORD(pos.x) = (v11 + this->m_fireSpawnOffset) % this->m_fireCount.m_Value;
        m_spawnCount = v13->m_spawnCount;
        if ( m_spawnCount != 0 )
        {
          v15 = v13->m_treeDepth + 1;
          v82 = v15;
          v16 = InfernoChildSpawnMaxDepth.m_pParent != nullptr
              ? InfernoChildSpawnMaxDepth.m_pParent->m_Value.m_nValue
              : 0;
          if ( v15 < v16 )
            break;
        }
LABEL_55:
        x = pos.x;
        v11 = v84 + 1;
        v84 = v11;
        if ( v11 >= this->m_fireCount.m_Value )
          goto LABEL_56;
      }
      v13->m_spawnCount = m_spawnCount - 1;
      pos.y = 0.0;
      while ( 1 )
      {
        p_x = &v13->m_parent->m_pos.x;
        if ( p_x != nullptr )
        {
          v68.x = v13->m_pos.x - *p_x;
          v68.y = v13->m_pos.y - p_x[1];
          v68.z = v13->m_pos.z - p_x[2];
          VectorNormalize(vec: &v68);
          VectorAngles(forward: &v68, angles: (QAngle *)&endPos);
          v20 = ((double (__thiscall *)(IUniformRandomStream *, unsigned int, _DWORD, Vector *, int, CTraceFilterSimple *, Vector *, CTraceFilterSimple_vtbl *, const IHandleEntity *))random->RandomFloat)(
                  a1: random,
                  a2: LODWORD(InfernoSpawnAngle.m_pParent->m_Value.m_fValue) ^ (unsigned int)_mask__NegFloat_,
                  a3: LODWORD(InfernoSpawnAngle.m_pParent->m_Value.m_fValue),
                  a4: p_to,
                  a5: a4,
                  a6: v56,
                  a7: v57,
                  a8: v58.__vftable,
                  a9: v58.m_pPassEnt);
          endPos.y = v20 + endPos.y;
          AngleVectors(angles: (const QAngle *)&endPos, forward: &fireDir);
        }
        else
        {
          pos.z = ((double (__thiscall *)(IUniformRandomStream *, int, int, Vector *, int, CTraceFilterSimple *, Vector *, CTraceFilterSimple_vtbl *, const IHandleEntity *))random->RandomFloat)(
                    a1: random,
                    a2: -1068953648,
                    a3: 1078530000,
                    a4: p_to,
                    a5: a4,
                    a6: v56,
                    a7: v57,
                    a8: v58.__vftable,
                    a9: v58.m_pPassEnt);
          __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd((__m128)LODWORD(pos.z)));
          *(float *)&v18 = v18;
          tr.hitbox = LODWORD(v18);
          __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd((__m128)LODWORD(pos.z)));
          *(float *)&v19 = v19;
          fireDir.y = *(float *)&v19;
          LODWORD(fireDir.x) = tr.hitbox;
          fireDir.z = 0.0;
        }
        m_fValue = InfernoVelocityDecayFactor.m_pParent->m_Value.m_fValue;
        __libm_sse2_pow(x: *(long double *)&v58.m_collisionGroup, y: *(long double *)&v59.__vftable);
        v22 = 0.0;
        *(float *)&m_fValue = m_fValue;
        v83 = *(float *)&m_fValue;
        if ( v13->m_lifetime.m_timestamp.m_Value > 0.0 )
        {
          v22 = 0.0;
          pos.z = v13->m_lifetime.m_timestamp.m_Value - IntervalTimer::Now(this: (CEffectsServer *)&v13->m_lifetime);
          v23 = pos.z / v13->m_lifetime.m_duration.m_Value;
          if ( v23 >= 0.0 )
          {
            v22 = 1.0;
            if ( v23 <= 1.0 )
              v22 = pos.z / v13->m_lifetime.m_duration.m_Value;
          }
        }
        v24 = InfernoVelocityFactor.m_pParent->m_Value.m_fValue;
        y = v13->m_normal.y;
        z = v13->m_normal.z;
        v27 = v13->m_normal.x;
        v28 = (float)((float)((float)(v22 * spreadVelocity->x) * v83) * v24) + fireDir.x;
        v29 = (float)((float)((float)(spreadVelocity->y * v22) * v83) * v24) + fireDir.y;
        v30 = (float)(v24 * (float)((float)(spreadVelocity->z * v22) * v83)) + fireDir.z;
        v31 = v28;
        v32 = v29;
        v33 = (float)(v30 * y) - (float)(v29 * z);
        v34 = (float)(v31 * z) - (float)(v30 * v27);
        v35 = (float)(v32 * v27) - (float)(v31 * y);
        fireDir.z = (float)(v33 * y) - (float)(v34 * v27);
        fireDir.x = (float)(v34 * z) - (float)(v35 * y);
        fireDir.y = (float)(v35 * v27) - (float)(v33 * z);
        RandomFloat = random->RandomFloat;
        v58.m_pPassEnt = (const IHandleEntity *)1117126656;
        v58.__vftable = (CTraceFilterSimple_vtbl *)1112014848;
        pos.z = ((double (__thiscall *)(IUniformRandomStream *))RandomFloat)(a1: random);
        v37 = (float)(fireDir.x * pos.z) + v13->m_pos.x;
        v38 = (float)(fireDir.y * pos.z) + v13->m_pos.y;
        v39 = v13->m_pos.z + (float)(fireDir.z * pos.z);
        *(float *)&v40 = v37 - this->m_startPos.x;
        v41 = v38 - this->m_startPos.y;
        out.x = v37;
        out.y = v38;
        out.z = v39;
        depth = v40;
        velocityDecay = v41;
        v87 = v39 - this->m_startPos.z;
        if ( (float)((float)((float)(*(float *)&v40 * *(float *)&v40) + (float)(v41 * v41)) + (float)(v87 * v87)) > (float)(InfernoMaxRange.m_pParent->m_Value.m_fValue * InfernoMaxRange.m_pParent->m_Value.m_fValue) )
        {
          VectorNormalize(vec: (Vector *)&depth);
          v42 = InfernoMaxRange.m_pParent->m_Value.m_fValue;
          v43 = velocityDecay * v42;
          *(float *)&v44 = *(float *)&depth * v42;
          v45 = v87 * v42;
          v37 = this->m_startPos.x + (float)(*(float *)&depth * v42);
          depth = v44;
          v38 = this->m_startPos.y + v43;
          velocityDecay = v43;
          v39 = this->m_startPos.z + v45;
          v87 = v45;
          out.x = v37;
          out.y = v38;
          out.z = v39;
        }
        v46 = v39 + 50.0;
        v64 = *(_QWORD *)&out.x;
        v47 = v13->m_pos.z - 200.0;
        v71 = out.y - v38;
        v70 = out.x - v37;
        v72 = v47 - v46;
        v65 = out.z;
        v81 = (float)((float)((float)(v71 * v71) + (float)(v70 * v70)) + (float)(v72 * v72)) != 0.0;
        v78 = 0;
        v77 = 0;
        v76 = 0;
        v79 = 0;
        v80 = 1;
        v75 = 0;
        v74 = 0;
        v73 = 0;
        to.x = v37;
        to.y = v38;
        to.z = v46;
        CTraceFilterSimple::CTraceFilterSimple(
          this: &v59,
          passedict: nullptr,
          collisionGroup: 0,
          pExtraShouldHitFunc: nullptr);
        v57 = &v60;
        v56 = &v59;
        a4 = 16387;
        p_to = &to;
        ((void (__thiscall *)(IEngineTrace *))enginetrace->TraceRay)(a1: enginetrace);
        if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
          DebugDrawLine(vecAbsStart: &v60, vecAbsEnd: &tr.startpos, r: 255, g: 0, b: 0, test: true, duration: -1.0);
        --nextFireOffset;
        if ( tr.plane.normal.z < 1.0 || tr.plane.pad[0] != 0 || tr.plane.pad[1] != 0 )
        {
          v51 = v13->m_pos.x;
          v52 = v13->m_pos.y;
          out.z = tr.startpos.z;
          *(_QWORD *)&v62.x = *(_QWORD *)&tr.endpos.x;
          v53 = v13->m_pos.z + 30.0;
          v71 = out.y - v52;
          v70 = out.x - v51;
          v72 = (float)(tr.startpos.z + 30.0) - v53;
          v62.z = tr.endpos.z;
          v81 = (float)((float)((float)(v71 * v71) + (float)(v70 * v70)) + (float)(v72 * v72)) != 0.0;
          v80 = 1;
          v78 = 0;
          v77 = 0;
          v76 = 0;
          v79 = 0;
          v75 = 0;
          v74 = 0;
          v73 = 0;
          to.x = v51;
          to.y = v52;
          to.z = v53;
          CTraceFilterSimple::CTraceFilterSimple(
            this: &v58,
            passedict: nullptr,
            collisionGroup: 0,
            pExtraShouldHitFunc: nullptr);
          enginetrace->TraceRay(this: enginetrace, a2: (const Ray_t *)&to, a3: 16387u, a4: &v58, a5: (CGameTrace *)&v60);
          if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
            DebugDrawLine(vecAbsStart: &v60, vecAbsEnd: &tr.startpos, r: 255, g: 0, b: 0, test: true, duration: -1.0);
          --nextFireOffset;
          if ( tr.plane.normal.z >= 1.0 )
          {
            if ( CInferno::CreateFire(this, a2: (int)v13, pos: &out, normal: &v62, parent: v13, depth: v82) != 0 )
              goto LABEL_55;
            goto LABEL_54;
          }
          if ( InfernoDebug.m_pParent != nullptr && InfernoDebug.m_pParent->m_Value.m_nValue != 0 )
          {
            normal.x = out.x;
            normal.y = out.y;
            normal.z = out.z + 30.0;
            angles.x = v13->m_pos.x;
            angles.y = v13->m_pos.y;
            angles.z = v13->m_pos.z + 30.0;
            NDebugOverlay::Line(
              origin: (const Vector *)&angles,
              target: &normal,
              r: 255,
              g: 0,
              b: 0,
              noDepthTest: 1,
              duration: 1.0);
          }
        }
        else if ( InfernoDebug.m_pParent != nullptr && InfernoDebug.m_pParent->m_Value.m_nValue != 0 )
        {
          NDebugOverlay::Line(origin: &v13->m_pos, target: &out, r: 255, g: 255, b: 0, noDepthTest: 1, duration: 1.0);
          NDebugOverlay::Cross3D(position: &out, size: 5.0, r: 255, g: 0, b: 0, noDepthTest: 1, flDuration: 1.0);
        }
        v48 = inferno_forward_reduction_factor.m_pParent->m_Value.m_fValue;
        this->m_splashVelocity.x = this->m_splashVelocity.x * v48;
        v49 = v48 * this->m_splashVelocity.y;
        v50 = v48 * this->m_splashVelocity.z;
        this->m_splashVelocity.y = v49;
        this->m_splashVelocity.z = v50;
LABEL_54:
        ++LODWORD(pos.y);
        if ( SLODWORD(pos.y) >= 4 )
          goto LABEL_55;
      }
    }
LABEL_56:
    this->m_fireSpawnOffset = LODWORD(x) + 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102DA800
// Name: public: void CInferno::InfernoThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInferno::InfernoThink(CInferno *this)
{
  unsigned int m_Index; // eax
  float z; // ecx
  IHandleEntity *m_pEntity; // eax
  bool v5; // cc
  CInferno::FireInfo **m_fire; // edi
  Vector *v7; // ebx
  const Vector *v8; // ecx
  char *v9; // eax
  edict_t *m_pPev; // ecx
  edict_t *v11; // ecx
  CInferno::NetworkVar_m_fireZDelta *p_m_fireZDelta; // ebx
  edict_t *v13; // ecx
  bool v14; // zf
  CInferno::FireInfo *v15; // eax
  float v16; // xmm0_4
  int m_nMaxFlames; // eax
  CNetworkVarBase<float,CountdownTimer::NetworkVar_m_timestamp> *p_m_timestamp; // ebx
  double v19; // st7
  float m_Value; // xmm0_4
  unsigned int v21; // eax
  int v22; // ebx
  int v23; // edi
  CBaseEntity *v24; // ecx
  CInferno *v25; // ecx
  bool v26; // al
  int v27; // eax
  float v28; // xmm1_4
  float v29; // xmm0_4
  float (__thiscall *GetDamagePerSecond)(CInferno *); // edx
  double v31; // st7
  double v32; // st7
  float v33; // xmm0_4
  float v34; // xmm1_4
  int j; // ebx
  CBaseEntity *v36; // edi
  int v37; // edi
  CNavArea *v38; // ebx
  CBaseEntity *damageList[256]; // [esp+78h] [ebp-8ACh]
  CBaseEntity *list[256]; // [esp+478h] [ebp-4ACh] BYREF
  CTakeDamageInfo info; // [esp+878h] [ebp-ACh] BYREF
  CNetworkVarBase<float,CountdownTimer::NetworkVar_m_timestamp> *v42; // [esp+8D4h] [ebp-50h]
  NavAreaCollector overlap; // [esp+8D8h] [ebp-4Ch] BYREF
  Extent pEnum; // [esp+8F0h] [ebp-34h] BYREF
  float v45; // [esp+908h] [ebp-1Ch]
  int count; // [esp+90Ch] [ebp-18h]
  int damageCount; // [esp+910h] [ebp-14h]
  bool bIsAttachedToMovingObject; // [esp+917h] [ebp-Dh]
  int i; // [esp+918h] [ebp-Ch]
  bool isDone; // [esp+91Fh] [ebp-5h]
  float baseDamage; // [esp+920h] [ebp-4h]
  int savedregs; // [esp+924h] [ebp+0h] BYREF

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CInferno::InfernoThink",
    a3: 0,
    a4: "Fire",
    a5: false,
    a6: 4);
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  m_Index = this->m_pParent.m_Index;
  z = this->m_vecAbsOrigin.z;
  *(_QWORD *)&pEnum.hi.x = *(_QWORD *)&this->m_vecAbsOrigin.x;
  pEnum.hi.z = z;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  bIsAttachedToMovingObject = m_pEntity != nullptr;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CInferno::InfernoThink (check lifetimes)",
    a3: 0,
    a4: "Fire",
    a5: false,
    a6: 4);
  v5 = this->m_fireCount.m_Value <= 0;
  isDone = true;
  i = 0;
  if ( v5 )
    goto LABEL_38;
  m_fire = this->m_fire;
  LODWORD(baseDamage) = -2396 - (_DWORD)this;
  do
  {
    v7 = (Vector *)*m_fire;
    if ( IntervalTimer::Now(this: (CEffectsServer *)&(*m_fire)->m_lifetime) <= v7[6].z )
    {
      v14 = !bIsAttachedToMovingObject;
      (*m_fire)->m_pos = pEnum.hi;
      (*m_fire)->m_pos.x = (float)(int)*(m_fire - 386) + (*m_fire)->m_pos.x;
      (*m_fire)->m_pos.y = (float)(int)*(m_fire - 322) + (*m_fire)->m_pos.y;
      v15 = *m_fire;
      v16 = (float)(int)*(m_fire - 258) + (*m_fire)->m_pos.z;
      isDone = false;
      v15->m_pos.z = v16;
      if ( !v14 )
        CInferno::RecomputeExtent(this);
      if ( InfernoDebug.m_pParent != nullptr && InfernoDebug.m_pParent->m_Value.m_nValue != 0 )
        NDebugOverlay::Sphere(
          center: &(*m_fire)->m_pos,
          radius: this->m_maxFireHalfWidth * 2.0,
          r: 255,
          g: 100,
          b: 0,
          noDepthTest: 1,
          flDuration: 0.1);
    }
    else
    {
      v8 = (const Vector *)*m_fire;
      if ( (*m_fire)->m_pos.x != 0.0 || v8->y != 0.0 || v8->z != 0.0 )
      {
        v9 = (char *)m_fire + LODWORD(baseDamage);
        v8->x = 0.0;
        v8->y = 0.0;
        v8->z = 0.0;
        if ( *(int *)((char *)this->m_fireXDelta.m_Value + (_DWORD)v9) != 0 )
        {
          if ( this->m_Network.m_TimerEvent.m_bRegistered )
          {
            *((_BYTE *)&this->m_Network + 76) |= 1u;
          }
          else
          {
            m_pPev = this->m_Network.m_pPev;
            if ( m_pPev != nullptr )
              CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 4 * i + 852);
          }
          v9 = (char *)m_fire + LODWORD(baseDamage);
          *(int *)((char *)this->m_fireXDelta.m_Value + (_DWORD)m_fire + LODWORD(baseDamage)) = 0;
        }
        if ( *(_DWORD *)&v9[(_DWORD)this + 1108] != 0 )
        {
          if ( this->m_Network.m_TimerEvent.m_bRegistered )
          {
            *((_BYTE *)&this->m_Network + 76) |= 1u;
          }
          else
          {
            v11 = this->m_Network.m_pPev;
            if ( v11 != nullptr )
              CBaseEdict::StateChanged(this: &v11->CBaseEdict, offset: 4 * i + 1108);
          }
          v9 = (char *)m_fire + LODWORD(baseDamage);
          *(int *)((char *)this->m_fireYDelta.m_Value + (_DWORD)m_fire + LODWORD(baseDamage)) = 0;
        }
        p_m_fireZDelta = &this->m_fireZDelta;
        if ( *(_DWORD *)&v9[(_DWORD)this + 1364] != 0 )
        {
          if ( this->m_Network.m_TimerEvent.m_bRegistered )
          {
            *((_BYTE *)&this->m_Network + 76) |= 1u;
            *(CInferno::FireInfo **)((char *)m_fire + LODWORD(baseDamage) + (_DWORD)p_m_fireZDelta) = nullptr;
          }
          else
          {
            v13 = this->m_Network.m_pPev;
            if ( v13 != nullptr )
              CBaseEdict::StateChanged(this: &v13->CBaseEdict, offset: 4 * i + 1364);
            *(CInferno::FireInfo **)((char *)m_fire + LODWORD(baseDamage) + (_DWORD)p_m_fireZDelta) = nullptr;
          }
        }
      }
    }
    ++m_fire;
    ++i;
  }
  while ( i < this->m_fireCount.m_Value );
  if ( isDone )
  {
LABEL_38:
    UTIL_Remove(oldObj: this);
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
  else
  {
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    m_nMaxFlames = this->m_nMaxFlames;
    if ( m_nMaxFlames >= 64 )
      m_nMaxFlames = 64;
    if ( this->m_fireCount.m_Value < m_nMaxFlames )
    {
      CVProfile::EnterScope(
        this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
        a2: "CInferno::InfernoThink (spread)",
        a3: 0,
        a4: "Fire",
        a5: false,
        a6: 4);
      if ( this->m_fireCount.m_Value > 0 )
        CInferno::Spread(
          this,
          a2: (int)&savedregs,
          p_to: (Vector *)m_fire,
          a4: (int)this,
          spreadVelocity: &this->m_splashVelocity);
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    }
    p_m_timestamp = &this->m_damageTimer.m_timestamp;
    baseDamage = this->m_maxFireHalfWidth * 2.0;
    v42 = &this->m_damageTimer.m_timestamp;
    if ( IntervalTimer::Now(this: (CEffectsServer *)&this->m_damageTimer) > this->m_damageTimer.m_timestamp.m_Value )
    {
      CVProfile::EnterScope(
        this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
        a2: "CInferno::InfernoThink (damage)",
        a3: 0,
        a4: "Fire",
        a5: false,
        a6: 4);
      v19 = IntervalTimer::Now(this: (CEffectsServer *)&this->m_damageTimer) + 0.2;
      *(float *)&damageCount = v19;
      if ( p_m_timestamp->m_Value != v19 )
      {
        this->m_damageTimer.NetworkStateChanged(this: &this->m_damageTimer, a2: &this->m_damageTimer.m_timestamp);
        SLODWORD(p_m_timestamp->m_Value) = damageCount;
      }
      m_Value = this->m_damageTimer.m_duration.m_Value;
      LODWORD(v45) = &this->m_damageTimer.m_duration;
      if ( m_Value != 0.2 )
      {
        this->m_damageTimer.NetworkStateChanged(this: &this->m_damageTimer, a2: &this->m_damageTimer.m_duration);
        this->m_damageTimer.m_duration.m_Value = 0.2;
      }
      v21 = this->m_hOwnerEntity.m_Value.m_Index;
      if ( v21 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v21].m_SerialNumber != HIWORD(v21) )
        i = 0;
      else
        i = (int)g_pEntityList->m_EntPtrArray[(unsigned __int16)v21].m_pEntity;
      *(float *)&v22 = 0.0;
      *(float *)&damageCount = 0.0;
      CFlaggedEntitiesEnum::CFlaggedEntitiesEnum(
        this: (CFlaggedEntitiesEnum *)&pEnum.lo.y,
        pList: list,
        listMax: 256,
        flagMask: 0);
      v23 = 0;
      count = UTIL_EntitiesInBox(
                mins: &this->m_extent.lo,
                maxs: &this->m_extent.hi,
                pEnum: (CFlaggedEntitiesEnum *)&pEnum.lo.y);
      if ( count > 0 )
      {
        do
        {
          v24 = list[v23];
          if ( v24 != nullptr && v24->IsAlive(this: v24) )
          {
            v25 = (CInferno *)list[v23];
            if ( v25 != this )
            {
              v26 = v25->IsPlayer(this: v25);
              if ( CInferno::IsTouching(this, entity: list[v23], radius: baseDamage, checkLOS: v26) != 0 )
                damageList[v22++] = list[v23];
            }
          }
          ++v23;
        }
        while ( v23 < count );
        damageCount = v22;
      }
      v27 = this->GetDamageType_2(this);
      v28 = v42->m_Value;
      v29 = 0.0;
      count = v27;
      if ( v28 > 0.0 )
        v29 = *(float *)LODWORD(v45);
      GetDamagePerSecond = this->GetDamagePerSecond;
      baseDamage = v29;
      v31 = ((double (__thiscall *)(CInferno *))GetDamagePerSecond)(a1: this);
      baseDamage = v31 * baseDamage;
      if ( IntervalTimer::Now(this: (CEffectsServer *)&this->m_damageRampTimer) <= this->m_damageRampTimer.m_timestamp.m_Value )
      {
        v32 = IntervalTimer::Now(this: (CEffectsServer *)&this->m_damageRampTimer);
        v33 = this->m_damageRampTimer.m_timestamp.m_Value;
        v34 = 0.0;
        v45 = v32 - v33 + this->m_damageRampTimer.m_duration.m_Value;
        if ( v33 > 0.0 )
          v34 = this->m_damageRampTimer.m_duration.m_Value;
        baseDamage = (float)(v45 / v34) * baseDamage;
      }
      for ( j = 0; j < damageCount; ++j )
      {
        v36 = damageList[j];
        if ( this->CanHarm(this, a2: v36) )
        {
          CTakeDamageInfo::CTakeDamageInfo(
            this: &info,
            pInflictor: this,
            pAttacker: (CBaseEntity *)i,
            flDamage: baseDamage,
            bitsDamageType: count,
            iKillType: 0,
            iObjectsPenetrated: 0);
          CBaseEntity::TakeDamage(this: v36, a2: (int)this, inputInfo: &info);
        }
      }
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    }
    pEnum = this->m_extent;
    pEnum.lo.x = pEnum.lo.x - 32.0;
    pEnum.lo.y = pEnum.lo.y - 32.0;
    pEnum.lo.z = pEnum.lo.z - 32.0;
    pEnum.hi.x = pEnum.hi.x + 32.0;
    v37 = 0;
    pEnum.hi.y = pEnum.hi.y + 32.0;
    memset(&overlap.m_area, 0, sizeof(overlap.m_area));
    overlap.m_checkForDuplicates = false;
    pEnum.hi.z = pEnum.hi.z + 32.0;
    CNavMesh::ForAllAreasOverlappingExtent<NavAreaCollector>(this: TheNavMesh, func: &overlap, extent: &pEnum);
    if ( overlap.m_area.m_Size > 0 )
    {
      do
      {
        v38 = overlap.m_area.m_Memory.m_pMemory[v37];
        if ( CInferno::IsTouching(this, area: v38) != 0 )
          v38->m_damagingTickCount = gpGlobals->tickcount
                                   + (int)(float)((float)(1.0 / gpGlobals->interval_per_tick) + 0.5);
        ++v37;
      }
      while ( v37 < overlap.m_area.m_Size );
    }
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
    if ( overlap.m_area.m_Memory.m_nGrowSize >= 0 && overlap.m_area.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: overlap.m_area.m_Memory.m_pMemory);
      overlap.m_area.m_Memory.m_pMemory = nullptr;
    }
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102DB070
// Name: public: virtual void CInferno::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInferno::Spawn(CInferno *this)
{
  edict_t *m_pPev; // ecx
  double v3; // st7
  double v4; // st7
  edict_t *v5; // ecx
  float v6; // [esp+1Ch] [ebp-8h]
  float v7; // [esp+20h] [ebp-4h]
  float v8; // [esp+20h] [ebp-4h]

  if ( this->m_fireCount.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x954u);
    }
    this->m_fireCount.m_Value = 0;
  }
  this->m_maxFireHalfWidth = 30.0;
  this->m_maxFireHeight = 80.0;
  v3 = IntervalTimer::Now(this: (CEffectsServer *)&this->m_damageRampTimer) + 2.0;
  if ( this->m_damageRampTimer.m_timestamp.m_Value != v3 )
  {
    this->m_damageRampTimer.NetworkStateChanged(
      this: &this->m_damageRampTimer,
      a2: &this->m_damageRampTimer.m_timestamp);
    v7 = v3;
    this->m_damageRampTimer.m_timestamp.m_Value = v7;
  }
  if ( this->m_damageRampTimer.m_duration.m_Value != 2.0 )
  {
    this->m_damageRampTimer.NetworkStateChanged(this: &this->m_damageRampTimer, a2: &this->m_damageRampTimer.m_duration);
    this->m_damageRampTimer.m_duration.m_Value = 2.0;
  }
  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CInferno::InfernoThink,
    thinkTime: 0.0,
    szContext: nullptr);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
  v8 = this->GetFlameSpreadDelay(this);
  v4 = IntervalTimer::Now(this: (CEffectsServer *)&this->m_NextSpreadTimer) + v8;
  if ( this->m_NextSpreadTimer.m_timestamp.m_Value != v4 )
  {
    this->m_NextSpreadTimer.NetworkStateChanged(
      this: &this->m_NextSpreadTimer,
      a2: &this->m_NextSpreadTimer.m_timestamp);
    v6 = v4;
    this->m_NextSpreadTimer.m_timestamp.m_Value = v6;
  }
  if ( this->m_NextSpreadTimer.m_duration.m_Value != v8 )
  {
    this->m_NextSpreadTimer.NetworkStateChanged(this: &this->m_NextSpreadTimer, a2: &this->m_NextSpreadTimer.m_duration);
    this->m_NextSpreadTimer.m_duration.m_Value = v8;
  }
  if ( this->m_nInfernoType.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_nInfernoType.m_Value = 0;
    }
    else
    {
      v5 = this->m_Network.m_pPev;
      if ( v5 != nullptr )
        CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0x958u);
      this->m_nInfernoType.m_Value = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102DB230
// Name: public: virtual void CFireCrackerBlast::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFireCrackerBlast::Spawn(CFireCrackerBlast *this)
{
  edict_t *m_pPev; // ecx

  CInferno::Spawn(this);
  if ( this->m_nInfernoType.m_Value != 1 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_nInfernoType.m_Value = 1;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x958u);
      this->m_nInfernoType.m_Value = 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104115D0
// Name: DT_Inferno::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_Inferno::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_Inferno::g_SendTable);
  return atexit(func: DT_Inferno::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104115F0
// Name: DT_Inferno::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_Inferno::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_Inferno::ignored>();
  DT_Inferno::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10411600
// Name: CInferno_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CInferno_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CInferno>(__formal: nullptr);
  CInferno_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10411610
// Name: _dynamic_initializer_for__inferno__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__inferno__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CInferno> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &inferno,
           a3: "inferno");
}

//------------------------------------------------------------------------------
// Address: 0x10411630
// Name: infernoPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int infernoPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106DA8A4;
  infernoPrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106DA8A4;
  dword_106DA8A4 = (int)&infernoPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10411670
// Name: DT_FireCrackerBlast::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_FireCrackerBlast::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_FireCrackerBlast::g_SendTable);
  return atexit(func: DT_FireCrackerBlast::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10411690
// Name: DT_FireCrackerBlast::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_FireCrackerBlast::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_FireCrackerBlast::ignored>();
  DT_FireCrackerBlast::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104116C0
// Name: fire_cracker_blastPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int fire_cracker_blastPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106DA8A4;
  fire_cracker_blastPrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106DA8A4;
  dword_106DA8A4 = (int)&fire_cracker_blastPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10411A10
// Name: _dynamic_initializer_for__inferno_scorch_decals__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__inferno_scorch_decals__()
{
  ConVar::ConVar(this: &inferno_scorch_decals, pName: "inferno_scorch_decals", pDefaultValue: "1", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__inferno_scorch_decals__);
}

//------------------------------------------------------------------------------
// Address: 0x10411A40
// Name: _dynamic_initializer_for__inferno_max_trace_per_tick__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__inferno_max_trace_per_tick__()
{
  ConVar::ConVar(this: &inferno_max_trace_per_tick, pName: "inferno_max_trace_per_tick", pDefaultValue: "16", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__inferno_max_trace_per_tick__);
}

//------------------------------------------------------------------------------
// Address: 0x10411A70
// Name: _dynamic_initializer_for__inferno_forward_reduction_factor__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__inferno_forward_reduction_factor__()
{
  ConVar::ConVar(
    this: &inferno_forward_reduction_factor,
    pName: "inferno_forward_reduction_factor",
    pDefaultValue: "0.9",
    flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__inferno_forward_reduction_factor__);
}

//------------------------------------------------------------------------------
// Address: 0x10420490
// Name: DT_Inferno::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_Inferno::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_Inferno::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x104204A0
// Name: DT_FireCrackerBlast::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_FireCrackerBlast::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_FireCrackerBlast::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x104205E0
// Name: _dynamic_atexit_destructor_for__inferno_scorch_decals__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__inferno_scorch_decals__()
{
  ConVar::~ConVar(this: &inferno_scorch_decals);
}

//------------------------------------------------------------------------------
// Address: 0x104205F0
// Name: _dynamic_atexit_destructor_for__inferno_max_trace_per_tick__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__inferno_max_trace_per_tick__()
{
  ConVar::~ConVar(this: &inferno_max_trace_per_tick);
}

//------------------------------------------------------------------------------
// Address: 0x10420600
// Name: _dynamic_atexit_destructor_for__inferno_forward_reduction_factor__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__inferno_forward_reduction_factor__()
{
  ConVar::~ConVar(this: &inferno_forward_reduction_factor);
}

//------------------------------------------------------------------------------
// Address: 0x102DAF80
// Name: struct datamap_t __near * DataMapInit<class CInferno>(class CInferno __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CInferno>()
{
  if ( (_S3_152 & 1) == 0 )
  {
    _S3_152 |= 1u;
    nameHolder_488.m_pszBase = "CInferno";
    nameHolder_488.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_488.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_488.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_488.m_Names.m_Size = 0;
    nameHolder_488.m_Names.m_pElements = nullptr;
    nameHolder_488.m_nLenBase = 8;
    atexit(func: DataMapInit_CInferno__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CInferno::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S3_152 & 2) == 0 )
  {
    _S3_152 |= 2u;
    dataDesc_506[1].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_488,
                                  pszIdentifier: "InfernoThink");
    dataDesc_506[1].fieldOffset = 0;
    *(_DWORD *)&dataDesc_506[1].fieldSize = 2097153;
    dataDesc_506[1].externalName = nullptr;
    dataDesc_506[1].pSaveRestoreOps = nullptr;
    dataDesc_506[1].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CInferno::InfernoThink;
    *(_QWORD *)&dataDesc_506[1].td = 0;
    *(_QWORD *)&dataDesc_506[1].override_field = 0;
    *(_QWORD *)&dataDesc_506[1].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_506[1].flatOffset[1] = 0;
  }
  CInferno::m_DataMap.dataNumFields = 1;
  CInferno::m_DataMap.dataDesc = &dataDesc_506[1];
  return &CInferno::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10411650
// Name: _dynamic_initializer_for__g_CFireCrackerBlast_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CFireCrackerBlast_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CFireCrackerBlast_ClassReg,
           pNetworkName: "CFireCrackerBlast",
           pTable: &DT_FireCrackerBlast::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x104116E0
// Name: _dynamic_initializer_for__InfernoPerFlameSpawnDuration__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__InfernoPerFlameSpawnDuration__()
{
  ConVar::ConVar(
    this: &InfernoPerFlameSpawnDuration,
    pName: "inferno_per_flame_spawn_duration",
    pDefaultValue: "5",
    flags: 0x4000,
    pHelpString: "Duration each new flame will attempt to spawn new flames");
  return atexit(func: dynamic_atexit_destructor_for__InfernoPerFlameSpawnDuration__);
}

//------------------------------------------------------------------------------
// Address: 0x10411710
// Name: _dynamic_initializer_for__InfernoInitialSpawnInterval__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__InfernoInitialSpawnInterval__()
{
  ConVar::ConVar(
    this: &InfernoInitialSpawnInterval,
    pName: "inferno_initial_spawn_interval",
    pDefaultValue: "0.05",
    flags: 0x4000,
    pHelpString: "Time between spawning flames for first fire");
  return atexit(func: dynamic_atexit_destructor_for__InfernoInitialSpawnInterval__);
}

//------------------------------------------------------------------------------
// Address: 0x10411740
// Name: _dynamic_initializer_for__InfernoChildSpawnIntervalMultiplier__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__InfernoChildSpawnIntervalMultiplier__()
{
  ConVar::ConVar(
    this: &InfernoChildSpawnIntervalMultiplier,
    pName: "inferno_child_spawn_interval_multiplier",
    pDefaultValue: "1",
    flags: 0x4000,
    pHelpString: "Amount spawn interval increases for each child");
  return atexit(func: dynamic_atexit_destructor_for__InfernoChildSpawnIntervalMultiplier__);
}

//------------------------------------------------------------------------------
// Address: 0x10411770
// Name: _dynamic_initializer_for__InfernoMaxChildSpawnInterval__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__InfernoMaxChildSpawnInterval__()
{
  ConVar::ConVar(
    this: &InfernoMaxChildSpawnInterval,
    pName: "inferno_max_child_spawn_interval",
    pDefaultValue: "1",
    flags: 0x4000,
    pHelpString: "Largest time interval for child flame spawning");
  return atexit(func: dynamic_atexit_destructor_for__InfernoMaxChildSpawnInterval__);
}

//------------------------------------------------------------------------------
// Address: 0x104117A0
// Name: _dynamic_initializer_for__InfernoSpawnAngle__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__InfernoSpawnAngle__()
{
  ConVar::ConVar(
    this: &InfernoSpawnAngle,
    pName: "inferno_spawn_angle",
    pDefaultValue: "45",
    flags: 0x4000,
    pHelpString: "Angular change from parent");
  return atexit(func: dynamic_atexit_destructor_for__InfernoSpawnAngle__);
}

//------------------------------------------------------------------------------
// Address: 0x104117D0
// Name: _dynamic_initializer_for__InfernoMaxFlames__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__InfernoMaxFlames__()
{
  ConVar::ConVar(
    this: &InfernoMaxFlames,
    pName: "inferno_max_flames",
    pDefaultValue: "32",
    flags: 0x4000,
    pHelpString: "Maximum number of flames that can be created");
  return atexit(func: dynamic_atexit_destructor_for__InfernoMaxFlames__);
}

//------------------------------------------------------------------------------
// Address: 0x10411800
// Name: _dynamic_initializer_for__InfernoFlameSpacing__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__InfernoFlameSpacing__()
{
  ConVar::ConVar(
    this: &InfernoFlameSpacing,
    pName: "inferno_flame_spacing",
    pDefaultValue: "50",
    flags: 0x4000,
    pHelpString: "Minimum distance between separate flame spawns");
  return atexit(func: dynamic_atexit_destructor_for__InfernoFlameSpacing__);
}

//------------------------------------------------------------------------------
// Address: 0x10411830
// Name: _dynamic_initializer_for__InfernoFlameLifetime__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__InfernoFlameLifetime__()
{
  ConVar::ConVar(
    this: &InfernoFlameLifetime,
    pName: "inferno_flame_lifetime",
    pDefaultValue: "7",
    flags: 0x4000,
    pHelpString: "Average lifetime of each flame in seconds");
  return atexit(func: dynamic_atexit_destructor_for__InfernoFlameLifetime__);
}

//------------------------------------------------------------------------------
// Address: 0x10411860
// Name: _dynamic_initializer_for__InfernoFriendlyFireDuration__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__InfernoFriendlyFireDuration__()
{
  ConVar::ConVar(
    this: &InfernoFriendlyFireDuration,
    pName: "inferno_friendly_fire_duration",
    pDefaultValue: "6",
    flags: 0x4000,
    pHelpString: "For this long, FF is credited back to the thrower.");
  return atexit(func: dynamic_atexit_destructor_for__InfernoFriendlyFireDuration__);
}

//------------------------------------------------------------------------------
// Address: 0x10411890
// Name: _dynamic_initializer_for__InfernoDebug__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__InfernoDebug__()
{
  ConVar::ConVar(this: &InfernoDebug, pName: "inferno_debug", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__InfernoDebug__);
}

//------------------------------------------------------------------------------
// Address: 0x104118C0
// Name: _dynamic_initializer_for__InfernoDamage__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__InfernoDamage__()
{
  ConVar::ConVar(
    this: &InfernoDamage,
    pName: "inferno_damage",
    pDefaultValue: "40",
    flags: 0x4000,
    pHelpString: "Damage per second");
  return atexit(func: dynamic_atexit_destructor_for__InfernoDamage__);
}

//------------------------------------------------------------------------------
// Address: 0x104118F0
// Name: _dynamic_initializer_for__InfernoMaxRange__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__InfernoMaxRange__()
{
  ConVar::ConVar(
    this: &InfernoMaxRange,
    pName: "inferno_max_range",
    pDefaultValue: "300",
    flags: 0x4000,
    pHelpString: "Maximum distance flames can spread from their initial ignition point");
  return atexit(func: dynamic_atexit_destructor_for__InfernoMaxRange__);
}

//------------------------------------------------------------------------------
// Address: 0x10411920
// Name: _dynamic_initializer_for__InfernoVelocityFactor__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__InfernoVelocityFactor__()
{
  ConVar::ConVar(this: &InfernoVelocityFactor, pName: "inferno_velocity_factor", pDefaultValue: "0.003", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__InfernoVelocityFactor__);
}

//------------------------------------------------------------------------------
// Address: 0x10411950
// Name: _dynamic_initializer_for__InfernoVelocityDecayFactor__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__InfernoVelocityDecayFactor__()
{
  ConVar::ConVar(
    this: &InfernoVelocityDecayFactor,
    pName: "inferno_velocity_decay_factor",
    pDefaultValue: "0.2",
    flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__InfernoVelocityDecayFactor__);
}

//------------------------------------------------------------------------------
// Address: 0x10411980
// Name: _dynamic_initializer_for__InfernoVelocityNormalFactor__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__InfernoVelocityNormalFactor__()
{
  ConVar::ConVar(
    this: &InfernoVelocityNormalFactor,
    pName: "inferno_velocity_normal_factor",
    pDefaultValue: "0",
    flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__InfernoVelocityNormalFactor__);
}

//------------------------------------------------------------------------------
// Address: 0x104119B0
// Name: _dynamic_initializer_for__InfernoSurfaceOffset__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__InfernoSurfaceOffset__()
{
  ConVar::ConVar(this: &InfernoSurfaceOffset, pName: "inferno_surface_offset", pDefaultValue: "20", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__InfernoSurfaceOffset__);
}

//------------------------------------------------------------------------------
// Address: 0x104119E0
// Name: _dynamic_initializer_for__InfernoChildSpawnMaxDepth__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__InfernoChildSpawnMaxDepth__()
{
  ConVar::ConVar(
    this: &InfernoChildSpawnMaxDepth,
    pName: "inferno_child_spawn_max_depth",
    pDefaultValue: "4",
    flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__InfernoChildSpawnMaxDepth__);
}

//------------------------------------------------------------------------------
// Address: 0x10411AA0
// Name: _dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___51
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___51()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCServerGameTagsIServerGameTags_reg_51,
           fn: _CreateCServerGameTagsIServerGameTags_interface_51,
           pName: "ServerGameTags001");
}

//------------------------------------------------------------------------------
// Address: 0x10411AC0
// Name: _dynamic_initializer_for__mp_hostagepenalty__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mp_hostagepenalty__()
{
  ConVar::ConVar(
    this: &mp_hostagepenalty,
    pName: "mp_hostagepenalty",
    pDefaultValue: "13",
    flags: 256,
    pHelpString: "Terrorist are kicked for killing too much hostages");
  return atexit(func: dynamic_atexit_destructor_for__mp_hostagepenalty__);
}

//------------------------------------------------------------------------------
// Address: 0x104204B0
// Name: _ServerClassInit_DT_FireCrackerBlast::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_FireCrackerBlast::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S4_70;
  for ( i = 1; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x104204D0
// Name: _dynamic_atexit_destructor_for__InfernoPerFlameSpawnDuration__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__InfernoPerFlameSpawnDuration__()
{
  ConVar::~ConVar(this: &InfernoPerFlameSpawnDuration);
}

//------------------------------------------------------------------------------
// Address: 0x104204E0
// Name: _dynamic_atexit_destructor_for__InfernoInitialSpawnInterval__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__InfernoInitialSpawnInterval__()
{
  ConVar::~ConVar(this: &InfernoInitialSpawnInterval);
}

//------------------------------------------------------------------------------
// Address: 0x104204F0
// Name: _dynamic_atexit_destructor_for__InfernoChildSpawnIntervalMultiplier__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__InfernoChildSpawnIntervalMultiplier__()
{
  ConVar::~ConVar(this: &InfernoChildSpawnIntervalMultiplier);
}

//------------------------------------------------------------------------------
// Address: 0x10420500
// Name: _dynamic_atexit_destructor_for__InfernoMaxChildSpawnInterval__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__InfernoMaxChildSpawnInterval__()
{
  ConVar::~ConVar(this: &InfernoMaxChildSpawnInterval);
}

//------------------------------------------------------------------------------
// Address: 0x10420510
// Name: _dynamic_atexit_destructor_for__InfernoSpawnAngle__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__InfernoSpawnAngle__()
{
  ConVar::~ConVar(this: &InfernoSpawnAngle);
}

//------------------------------------------------------------------------------
// Address: 0x10420520
// Name: _dynamic_atexit_destructor_for__InfernoMaxFlames__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__InfernoMaxFlames__()
{
  ConVar::~ConVar(this: &InfernoMaxFlames);
}

//------------------------------------------------------------------------------
// Address: 0x10420530
// Name: _dynamic_atexit_destructor_for__InfernoFlameSpacing__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__InfernoFlameSpacing__()
{
  ConVar::~ConVar(this: &InfernoFlameSpacing);
}

//------------------------------------------------------------------------------
// Address: 0x10420540
// Name: _dynamic_atexit_destructor_for__InfernoFlameLifetime__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__InfernoFlameLifetime__()
{
  ConVar::~ConVar(this: &InfernoFlameLifetime);
}

//------------------------------------------------------------------------------
// Address: 0x10420550
// Name: _dynamic_atexit_destructor_for__InfernoFriendlyFireDuration__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__InfernoFriendlyFireDuration__()
{
  ConVar::~ConVar(this: &InfernoFriendlyFireDuration);
}

//------------------------------------------------------------------------------
// Address: 0x10420560
// Name: _dynamic_atexit_destructor_for__InfernoDebug__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__InfernoDebug__()
{
  ConVar::~ConVar(this: &InfernoDebug);
}

//------------------------------------------------------------------------------
// Address: 0x10420570
// Name: _dynamic_atexit_destructor_for__InfernoDamage__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__InfernoDamage__()
{
  ConVar::~ConVar(this: &InfernoDamage);
}

//------------------------------------------------------------------------------
// Address: 0x10420580
// Name: _dynamic_atexit_destructor_for__InfernoMaxRange__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__InfernoMaxRange__()
{
  ConVar::~ConVar(this: &InfernoMaxRange);
}

//------------------------------------------------------------------------------
// Address: 0x10420590
// Name: _dynamic_atexit_destructor_for__InfernoVelocityFactor__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__InfernoVelocityFactor__()
{
  ConVar::~ConVar(this: &InfernoVelocityFactor);
}

//------------------------------------------------------------------------------
// Address: 0x104205A0
// Name: _dynamic_atexit_destructor_for__InfernoVelocityDecayFactor__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__InfernoVelocityDecayFactor__()
{
  ConVar::~ConVar(this: &InfernoVelocityDecayFactor);
}

//------------------------------------------------------------------------------
// Address: 0x104205B0
// Name: _dynamic_atexit_destructor_for__InfernoVelocityNormalFactor__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__InfernoVelocityNormalFactor__()
{
  ConVar::~ConVar(this: &InfernoVelocityNormalFactor);
}

//------------------------------------------------------------------------------
// Address: 0x104205C0
// Name: _dynamic_atexit_destructor_for__InfernoSurfaceOffset__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__InfernoSurfaceOffset__()
{
  ConVar::~ConVar(this: &InfernoSurfaceOffset);
}

//------------------------------------------------------------------------------
// Address: 0x104205D0
// Name: _dynamic_atexit_destructor_for__InfernoChildSpawnMaxDepth__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__InfernoChildSpawnMaxDepth__()
{
  ConVar::~ConVar(this: &InfernoChildSpawnMaxDepth);
}

//------------------------------------------------------------------------------
// Address: 0x10420610
// Name: _ServerClassInit_DT_Inferno::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_Inferno::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_264;
  for ( i = 5; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x10420630
// Name: _DataMapInit_CInferno__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CInferno__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_488);
}

//------------------------------------------------------------------------------
// Address: 0x10420640
// Name: _dynamic_atexit_destructor_for__mp_hostagepenalty__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_hostagepenalty__()
{
  ConVar::~ConVar(this: &mp_hostagepenalty);
}
