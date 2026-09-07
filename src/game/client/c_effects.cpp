// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_effects.cpp
// Functions: 145
// ============================================================

#include "game\client\c_effects.h"

//------------------------------------------------------------------------------
// Address: 0x101054D0
// Name: public: void CUtlMemory<struct CSnowFallManager::SnowFall_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CSnowFallManager::SnowFall_t,int>::Grow(
        CUtlMemory<vgui::SectionedListPanel::section_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  vgui::SectionedListPanel::section_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 36 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (vgui::SectionedListPanel::section_t *)_g_pMemAlloc->Realloc_2(
                                                                 this: _g_pMemAlloc,
                                                                 a2: m_pMemory,
                                                                 a3: v7);
    else
      this->m_pMemory = (vgui::SectionedListPanel::section_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1023DF30
// Name: public: virtual void PrecachePrecipitationPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PrecachePrecipitationPrecache::CResourcePrecacher::Cache(
        PrecachePrecipitationPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "particle/rain",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "particle/snow",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: PARTICLE_SYSTEM,
    a3: "rain_storm",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: PARTICLE_SYSTEM,
    a3: "rain_storm_screen",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: PARTICLE_SYSTEM,
    a3: "rain_storm_outer",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: PARTICLE_SYSTEM,
    a3: "rain",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: PARTICLE_SYSTEM,
    a3: "rain_outer",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: PARTICLE_SYSTEM,
    a3: "ash",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: PARTICLE_SYSTEM,
    a3: "ash_outer",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: PARTICLE_SYSTEM,
    a3: "snow",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: PARTICLE_SYSTEM,
    a3: "snow_outer",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1023E020
// Name: public: virtual class ClientClass __near * C_PrecipitationBlocker::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_PrecipitationBlocker::GetClientClass(C_PrecipitationBlocker *this)
{
  return &__g_C_PrecipitationBlockerClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1023E0A0
// Name: public: virtual class ClientClass __near * CClient_Precipitation::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall CClient_Precipitation::GetClientClass(CClient_Precipitation *this)
{
  return &__g_CClient_PrecipitationClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1023E130
// Name: public: unsigned long CCycleCount::GetMicroseconds(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int64 __thiscall CCycleCount::GetMicroseconds(CCycleCount *this)
{
  unsigned __int64 v2; // [esp-8h] [ebp-Ch]

  HIDWORD(v2) = HIDWORD(_g_ClockSpeed);
  LODWORD(v2) = _g_ClockSpeed;
  return 1000000 * this->m_Int64 / v2;
}

//------------------------------------------------------------------------------
// Address: 0x1023E160
// Name: public: virtual void CClient_Precipitation::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClient_Precipitation::Precache(CClient_Precipitation *this)
{
  PrecipitationType_t m_nPrecipType; // eax
  IMaterial *v3; // eax

  if ( this->m_MatHandle == nullptr )
  {
    m_nPrecipType = this->m_nPrecipType;
    if ( m_nPrecipType != PRECIPITATION_TYPE_RAIN )
    {
      if ( m_nPrecipType == PRECIPITATION_TYPE_SNOW )
      {
        this->m_Speed = 80.0;
        v3 = materials->FindMaterial(this: materials, a2: "particle/snow", a3: "ClientEffect textures", a4: 1, a5: 0);
        this->m_InitialRamp = 0.60000002;
        this->m_Width = 0.69999999;
        this->m_MatHandle = v3;
LABEL_7:
        this->m_Color[0] = 1.0;
        this->m_Color[1] = 1.0;
        this->m_Color[2] = 1.0;
        return;
      }
    }
    else
    {
      this->m_Speed = 425.0;
      this->m_MatHandle = materials->FindMaterial(
                            this: materials,
                            a2: "particle/rain",
                            a3: "ClientEffect textures",
                            a4: 1,
                            a5: 0);
      this->m_Width = 0.34999999;
    }
    this->m_Color[3] = 1.0;
    this->m_InitialRamp = 1.0;
    goto LABEL_7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1023E3E0
// Name: public: virtual class ClientClass __near * C_EnvWind::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_EnvWind::GetClientClass(C_EnvWind *this)
{
  return &__g_C_EnvWindClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1023E480
// Name: public: virtual void C_EnvWind::ClientThink(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall C_EnvWind::ClientThink(C_EnvWind *this@<ecx>, int a2@<edi>, int a3@<esi>)
{
  float flNextThink; // [esp+8h] [ebp-4h]

  flNextThink = CEnvWindShared::WindThink(
                  this: (CEnvWindShared *)&this->m_CalcAbsoluteVelocityMutex.m_depth,
                  a2,
                  flTime: *(float *)(gpGlobals.m_Index + 12));
  (*(void (__stdcall **)(_DWORD, int))(*((_DWORD *)this - 3) + 456))(a1: LODWORD(flNextThink), a2: a3);
}

//------------------------------------------------------------------------------
// Address: 0x1023E4D0
// Name: public: virtual class ClientClass __near * C_Embers::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_Embers::GetClientClass(C_Embers *this)
{
  return &__g_C_EmbersClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1023E5C0
// Name: public: virtual class ClientClass __near * C_QuadraticBeam::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_QuadraticBeam::GetClientClass(C_QuadraticBeam *this)
{
  return &__g_C_QuadraticBeamClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1023E6B0
// Name: public: void CUtlBlockMemory<struct CacheOptimizedTriangle,int>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBlockMemory<CacheOptimizedTriangle,int>::Purge(CUtlBlockMemory<CacheOptimizedTriangle,int> *this)
{
  int i; // edi

  if ( this->m_pMemory != nullptr )
  {
    for ( i = 0; i < this->m_nBlocks; ++i )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pMemory[i]);
    this->m_nBlocks = 0;
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pMemory);
    this->m_pMemory = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1023E700
// Name: protected: void CUtlBlockMemory<struct CacheOptimizedTriangle,int>::ChangeSize(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBlockMemory<CacheOptimizedTriangle,int>::ChangeSize(
        CUtlBlockMemory<CacheOptimizedTriangle,int> *this,
        int nBlocks)
{
  int v2; // ebx
  int m_nBlocks; // edi
  IMemAlloc_vtbl *v5; // edx
  CacheOptimizedTriangle **v6; // eax
  unsigned int v7; // ebx
  const char *v8; // [esp+0h] [ebp-Ch]

  v2 = nBlocks;
  m_nBlocks = this->m_nBlocks;
  this->m_nBlocks = nBlocks;
  if ( nBlocks < m_nBlocks )
  {
    do
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pMemory[v2++]);
    while ( v2 < m_nBlocks );
  }
  v5 = _g_pMemAlloc->__vftable;
  if ( this->m_pMemory != nullptr )
    v6 = (CacheOptimizedTriangle **)((int (__stdcall *)(CacheOptimizedTriangle **, int))v5->Realloc_2)(
                                      a1: this->m_pMemory,
                                      a2: 4 * this->m_nBlocks);
  else
    v6 = (CacheOptimizedTriangle **)((int (__stdcall *)(int))v5->Alloc_2)(a1: 4 * this->m_nBlocks);
  this->m_pMemory = v6;
  if ( v6 == nullptr )
    _Error(this: (ISceneTokenProcessor *)&stru_104DF4FC, a2: v8);
  if ( m_nBlocks < this->m_nBlocks )
  {
    v7 = 16 * (3 * ((32 * *((_DWORD *)this + 2)) >> 5) + 3);
    do
      this->m_pMemory[m_nBlocks++] = (CacheOptimizedTriangle *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
    while ( m_nBlocks < this->m_nBlocks );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1023E7B0
// Name: private: bool CClient_Precipitation::SimulateSnow(class CPrecipitationParticle __near *,float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CClient_Precipitation::SimulateSnow(
        CClient_Precipitation *this,
        CPrecipitationParticle *pParticle,
        float dt)
{
  float x; // xmm1_4
  float v4; // xmm1_4
  bool v5; // cc
  float y; // xmm1_4
  float v7; // xmm0_4
  bool v8; // cc

  if ( (enginetrace->GetPointContents(this: enginetrace, a2: &pParticle->m_Pos, a3: -1, a4: nullptr) & 1) == 0 )
  {
    pParticle->m_Pos.x = (float)(pParticle->m_Velocity.x * dt) + pParticle->m_Pos.x;
    pParticle->m_Pos.y = (float)(pParticle->m_Velocity.y * dt) + pParticle->m_Pos.y;
    pParticle->m_Pos.z = (float)(pParticle->m_Velocity.z * dt) + pParticle->m_Pos.z;
    x = pParticle->m_Velocity.x;
    if ( CClient_Precipitation::s_WindVector.x <= x )
    {
      if ( x <= CClient_Precipitation::s_WindVector.x )
        goto LABEL_8;
      pParticle->m_Velocity.x = pParticle->m_Velocity.x - (float)(5.0 / pParticle->m_Mass);
      pParticle->m_Ramp = 0.5;
      v4 = CClient_Precipitation::s_WindVector.x;
      v5 = CClient_Precipitation::s_WindVector.x <= pParticle->m_Velocity.x;
    }
    else
    {
      pParticle->m_Velocity.x = (float)(5.0 / pParticle->m_Mass) + pParticle->m_Velocity.x;
      pParticle->m_Ramp = 0.5;
      v4 = CClient_Precipitation::s_WindVector.x;
      v5 = pParticle->m_Velocity.x <= CClient_Precipitation::s_WindVector.x;
    }
    if ( !v5 )
      pParticle->m_Velocity.x = v4;
LABEL_8:
    y = pParticle->m_Velocity.y;
    if ( CClient_Precipitation::s_WindVector.y <= y )
    {
      if ( y <= CClient_Precipitation::s_WindVector.y )
        return 1;
      pParticle->m_Velocity.y = pParticle->m_Velocity.y - (float)(5.0 / pParticle->m_Mass);
      pParticle->m_Ramp = 0.5;
      v7 = CClient_Precipitation::s_WindVector.y;
      v8 = CClient_Precipitation::s_WindVector.y <= pParticle->m_Velocity.y;
    }
    else
    {
      pParticle->m_Velocity.y = (float)(5.0 / pParticle->m_Mass) + y;
      pParticle->m_Ramp = 0.5;
      v7 = CClient_Precipitation::s_WindVector.y;
      v8 = pParticle->m_Velocity.y <= CClient_Precipitation::s_WindVector.y;
    }
    if ( !v8 )
      pParticle->m_Velocity.y = v7;
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1023E910
// Name: public: bool CClient_Precipitation::ComputeEmissionArea(class Vector __near &,class Vector2D __near &,class C_BaseCombatCharacter __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CClient_Precipitation::ComputeEmissionArea(
        CClient_Precipitation *this,
        Vector *origin,
        Vector2D *size,
        C_BaseCombatCharacter *pCharacter)
{
  float z; // xmm0_4
  float v7; // xmm3_4
  float v8; // xmm0_4
  float x; // xmm1_4
  float y; // xmm2_4
  __int64 vMins; // [esp+8h] [ebp-28h]
  float emissionSize; // [esp+28h] [ebp-8h]
  float fallTime; // [esp+2Ch] [ebp-4h]
  float emissionHeight; // [esp+40h] [ebp+10h]
  Vector vMaxs; // 0:^14.12

  if ( pCharacter == nullptr )
    return 0;
  emissionSize = r_RainRadius.m_pParent->m_Value.m_fValue;
  vMins = *(_QWORD *)&this->WorldAlignMins(this)->x;
  vMaxs = *this->WorldAlignMaxs(this);
  if ( r_RainHack.m_pParent != nullptr && r_RainHack.m_pParent->m_Value.m_nValue != 0 )
  {
    vMins = *(_QWORD *)&GetClientWorldEntity()->m_WorldMins.x;
    vMaxs = GetClientWorldEntity()->m_WorldMaxs;
  }
  z = vMaxs.z;
  if ( (float)(pCharacter->GetAbsOrigin(this: pCharacter)->z + 512.0) <= vMaxs.z )
    z = pCharacter->GetAbsOrigin(this: pCharacter)->z + 512.0;
  emissionHeight = z;
  fallTime = (float)(z - pCharacter->GetAbsOrigin(this: pCharacter)->z)
           / CClient_Precipitation::s_rainspeed.m_pParent->m_Value.m_fValue;
  v7 = (float)(pCharacter->GetAbsOrigin(this: pCharacter)->x - (float)(CClient_Precipitation::s_WindVector.x * fallTime))
     - (float)(emissionSize * 0.5);
  v8 = (float)(pCharacter->GetAbsOrigin(this: pCharacter)->y - (float)(CClient_Precipitation::s_WindVector.y * fallTime))
     - (float)(emissionSize * 0.5);
  x = v7 + emissionSize;
  y = v8 + emissionSize;
  if ( v7 > vMaxs.x || v8 > vMaxs.y || *(float *)&vMins > x || *((float *)&vMins + 1) > y )
    return 0;
  if ( *(float *)&vMins > v7 )
    v7 = *(float *)&vMins;
  origin->x = v7;
  if ( *((float *)&vMins + 1) > v8 )
    v8 = *((float *)&vMins + 1);
  origin->y = v8;
  origin->z = emissionHeight;
  if ( x > vMaxs.x )
    x = vMaxs.x;
  if ( y > vMaxs.y )
    y = vMaxs.y;
  size->x = x - v7;
  size->y = y - origin->y;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1023EB20
// Name: public: virtual float AshDebrisEffect::UpdateRoll(class SimpleParticle __near *,float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall AshDebrisEffect::UpdateRoll(AshDebrisEffect *this, SimpleParticle *pParticle, float timeDelta)
{
  double result; // st7
  float v5; // xmm0_4
  float z; // xmm1_4
  __int64 vTempEntVel; // [esp+8h] [ebp-20h]
  float flRoll; // [esp+14h] [ebp-14h]
  float s; // [esp+30h] [ebp+8h]

  result = CSimpleEmitter::UpdateRoll(this, pParticle, timeDelta);
  if ( (pParticle->m_iFlags & 4) != 0 )
  {
    vTempEntVel = *(_QWORD *)&pParticle->m_vecVelocity.x;
    s = sin((float)(*(float *)(gpGlobals.m_Index + 12) * 1.5));
    flRoll = result;
    v5 = pParticle->m_Pos.y + (float)((float)(*((float *)&vTempEntVel + 1) * timeDelta) * s);
    z = pParticle->m_Pos.z;
    pParticle->m_Pos.x = pParticle->m_Pos.x + (float)((float)(*(float *)&vTempEntVel * timeDelta) * s);
    pParticle->m_Pos.y = v5;
    pParticle->m_Pos.z = z;
    return flRoll;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1023EBE0
// Name: private: static void CClient_Precipitation::ComputeWindVector(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CClient_Precipitation::ComputeWindVector()
{
  IUniformRandomStream_vtbl *v0; // edx
  QAngle windangle; // [esp+10h] [ebp-10h] BYREF
  float windspeed; // [esp+1Ch] [ebp-4h]

  windangle.y = cl_winddir.m_pParent->m_Value.m_fValue;
  windangle.x = 0.0;
  windangle.z = 0.0;
  windangle.y = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                  a1: random,
                  a2: -1054867456,
                  a3: 1092616192)
              + windangle.y;
  v0 = random->__vftable;
  windspeed = cl_windspeed.m_pParent->m_Value.m_fValue;
  windspeed = (((double (__thiscall *)(IUniformRandomStream *, int, int))v0->RandomFloat)(
                 a1: random,
                 a2: -1102263091,
                 a3: 1045220557)
             + 1.0)
            * windspeed;
  AngleVectors(angles: &windangle, forward: &CClient_Precipitation::s_WindVector);
  CClient_Precipitation::s_WindVector.x = CClient_Precipitation::s_WindVector.x * windspeed;
  CClient_Precipitation::s_WindVector.y = CClient_Precipitation::s_WindVector.y * windspeed;
  CClient_Precipitation::s_WindVector.z = windspeed * CClient_Precipitation::s_WindVector.z;
}

//------------------------------------------------------------------------------
// Address: 0x1023ED60
// Name: public: virtual void C_EnvWind::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_EnvWind::OnDataChanged(C_EnvWind *this, DataUpdateType_t updateType)
{
  int v3; // eax
  int iRandomSeed; // [esp+0h] [ebp-10h]
  float y; // [esp+4h] [ebp-Ch]
  int iInitialWindYaw; // [esp+8h] [ebp-8h]
  float v7; // [esp+Ch] [ebp-4h]

  iInitialWindYaw = LODWORD(this->m_EnvWindShared.m_PrevSwayVector.z);
  y = this->m_EnvWindShared.m_PrevSwayVector.y;
  iRandomSeed = *((_DWORD *)&this->m_bIsBlurred + 1);
  v3 = ((int (__thiscall *)(C_EnvWind *, CEnvWindShared_vtbl *))this->GetAbsOrigin)(
         a1: this,
         a2: this->m_EnvWindShared.__vftable);
  CEnvWindShared::Init(
    this: (CEnvWindShared *)&this->m_bIsBlurred,
    nEntIndex: v3,
    iRandomSeed,
    flTime: y,
    iInitialWindYaw,
    flInitialWindSpeed: v7);
  (*(void (__cdecl **)(_DWORD))(*((_DWORD *)this - 2) + 456))(a1: 0);
  C_BaseEntity::OnDataChanged(this, type: updateType);
}

//------------------------------------------------------------------------------
// Address: 0x1023EDD0
// Name: public: virtual void CEmberEmitter::UpdateVelocity(class SimpleParticle __near *,float)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall CEmberEmitter::UpdateVelocity(CEmberEmitter *this, SimpleParticle *pParticle, float timeDelta)
{
  Vector *p_m_vecVelocity; // esi
  IUniformRandomStream *v4; // ecx
  IUniformRandomStream *v5; // ecx
  IUniformRandomStream *v6; // ecx
  float v7; // xmm0_4
  float offset; // [esp+Ch] [ebp-Ch]
  float offset_4; // [esp+10h] [ebp-8h]
  float speed; // [esp+20h] [ebp+8h]

  p_m_vecVelocity = &pParticle->m_vecVelocity;
  speed = VectorNormalize(vec: &pParticle->m_vecVelocity) - timeDelta;
  _RandomFloat(this: v4, a2: -0.025, a3: 0.025);
  offset_4 = _RandomFloat(this: v5, a2: -0.025, a3: 0.025);
  _RandomFloat(this: v6, a2: -0.025, a3: 0.025);
  p_m_vecVelocity->x = offset + p_m_vecVelocity->x;
  p_m_vecVelocity->y = offset_4 + p_m_vecVelocity->y;
  p_m_vecVelocity->z = p_m_vecVelocity->z;
  VectorNormalize(vec: p_m_vecVelocity);
  p_m_vecVelocity->x = speed * p_m_vecVelocity->x;
  v7 = speed * p_m_vecVelocity->z;
  p_m_vecVelocity->y = speed * p_m_vecVelocity->y;
  p_m_vecVelocity->z = v7;
}

//------------------------------------------------------------------------------
// Address: 0x1023EF30
// Name: public: virtual void C_QuadraticBeam::GetRenderBounds(class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_QuadraticBeam::GetRenderBounds(C_QuadraticBeam *this, Vector *mins, Vector *maxs)
{
  float *v4; // eax
  float *v5; // eax

  ClearBounds(mins, maxs);
  AddPointToBounds(v: &vec3_origin, mins, maxs);
  AddPointToBounds(v: (const Vector *)(&this->m_bIsBlurred + 4), mins, maxs);
  AddPointToBounds(v: (const Vector *)&this->m_targetPosition.z, mins, maxs);
  v4 = (float *)((int (__thiscall *)(C_QuadraticBeam *))this->SetRefEHandle)(a1: this);
  mins->x = mins->x - *v4;
  mins->y = mins->y - v4[1];
  mins->z = mins->z - v4[2];
  v5 = (float *)((int (__thiscall *)(C_QuadraticBeam *))this->SetRefEHandle)(a1: this);
  maxs->x = maxs->x - *v5;
  maxs->y = maxs->y - v5[1];
  maxs->z = maxs->z - v5[2];
}

//------------------------------------------------------------------------------
// Address: 0x1023EFE0
// Name: public: virtual void SnowFallEffect::UpdateVelocity(class SimpleParticle __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SnowFallEffect::UpdateVelocity(SnowFallEffect *this, SimpleParticle *pParticle, float timeDelta)
{
  Vector *p_m_vecVelocity; // esi
  IUniformRandomStream *v5; // ecx
  IUniformRandomStream *v6; // ecx
  double v7; // st6
  float v8; // ecx
  float m_fValue; // xmm1_4
  float y; // xmm2_4
  float z; // xmm3_4
  Vector vecWindVelocity; // [esp+10h] [ebp-Ch] BYREF
  float flSpeed; // [esp+24h] [ebp+8h]

  p_m_vecVelocity = &pParticle->m_vecVelocity;
  flSpeed = VectorNormalize(vec: &pParticle->m_vecVelocity) - timeDelta;
  p_m_vecVelocity->x = _RandomFloat(this: v5, a2: -0.025, a3: 0.025) + p_m_vecVelocity->x;
  pParticle->m_vecVelocity.y = _RandomFloat(this: v6, a2: -0.025, a3: 0.025) + pParticle->m_vecVelocity.y;
  VectorNormalize(vec: p_m_vecVelocity);
  LODWORD(vecWindVelocity.y) = &vecWindVelocity;
  v7 = flSpeed * p_m_vecVelocity->x;
  vecWindVelocity.x = v8;
  p_m_vecVelocity->x = v7;
  p_m_vecVelocity->y = p_m_vecVelocity->y * flSpeed;
  p_m_vecVelocity->z = flSpeed * p_m_vecVelocity->z;
  GetWindspeedAtTime(flTime: *(float *)(gpGlobals.m_Index + 12), vecVelocity: (Vector *)LODWORD(vecWindVelocity.y));
  m_fValue = r_SnowWindScale.m_pParent->m_Value.m_fValue;
  y = vecWindVelocity.y;
  z = vecWindVelocity.z;
  p_m_vecVelocity->x = (float)(vecWindVelocity.x * m_fValue) + p_m_vecVelocity->x;
  p_m_vecVelocity->y = p_m_vecVelocity->y + (float)(y * m_fValue);
  p_m_vecVelocity->z = p_m_vecVelocity->z + (float)(z * m_fValue);
}

//------------------------------------------------------------------------------
// Address: 0x1023F0E0
// Name: public: virtual void SnowFallEffect::SimulateParticles(class CParticleSimulateIterator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SnowFallEffect::SimulateParticles(SnowFallEffect *this, CParticleSimulateIterator *pIterator)
{
  CEffectMaterial *m_pMaterial; // eax
  Particle *m_pNext; // esi
  float x; // xmm4_4
  float v6; // xmm3_4
  float v7; // xmm2_4
  SnowFallEffect *v8; // [esp+18h] [ebp-4h]
  float timeDelta; // [esp+24h] [ebp+8h]

  m_pMaterial = pIterator->m_pMaterial;
  m_pNext = m_pMaterial->m_Particles.m_pNext;
  v8 = this;
  timeDelta = pIterator->m_flTimeDelta;
  if ( m_pNext != &m_pMaterial->m_Particles )
  {
    for ( pIterator->m_pNextParticle = m_pNext->m_pNext; ; pIterator->m_pNextParticle = m_pNext->m_pNext )
    {
      ((void (__stdcall *)(Particle *, _DWORD))this->UpdateVelocity)(a1: m_pNext, a2: LODWORD(timeDelta));
      x = m_pNext->m_Pos.x;
      v6 = *(float *)&m_pNext[1].m_pPrev * timeDelta;
      v7 = (float)(*(float *)&m_pNext[1].m_pSubTexture * timeDelta) + m_pNext->m_Pos.z;
      m_pNext->m_Pos.y = (float)(*(float *)&m_pNext[1].m_pNext * timeDelta) + m_pNext->m_Pos.y;
      m_pNext->m_Pos.x = x + v6;
      m_pNext->m_Pos.z = v7;
      m_pNext[1].m_Pos.z = m_pNext[1].m_Pos.z + timeDelta;
      v8->UpdateRoll(this: v8, a2: (SimpleParticle *)m_pNext, a3: COERCE_FLOAT(LODWORD(timeDelta)));
      if ( m_pNext[1].m_Pos.z >= m_pNext[1].m_Pos.y
        || (enginetrace->GetPointContents(this: enginetrace, a2: &m_pNext->m_Pos, a3: -1, a4: nullptr) & 1) != 0 )
      {
        CParticleEffectBinding::RemoveParticle(this: pIterator->m_pEffectBinding, pParticle: m_pNext);
      }
      m_pNext = pIterator->m_pNextParticle;
      if ( m_pNext == &pIterator->m_pMaterial->m_Particles )
        break;
      this = v8;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1023F1E0
// Name: public: virtual void CSnowFallManager::SpawnClientEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSnowFallManager::SpawnClientEntity(CSnowFallManager *this)
{
  void (__thiscall *SetNextClientThink)(C_BaseEntity *, float); // edx

  this->m_tSnowFallParticleTimer.m_TimeBetweenEvents = 0.0020000001;
  this->m_tSnowFallParticleTimer.m_fNextEvent = 0.0;
  this->m_tSnowFallParticleTraceTimer.m_fNextEvent = 0.0;
  this->m_tSnowFallParticleTraceTimer.m_TimeBetweenEvents = 0.16666667;
  SetNextClientThink = this->SetNextClientThink;
  this->m_iSnowFallArea = 0;
  ((void (__stdcall *)(int))SetNextClientThink)(a1: -996040704);
}

//------------------------------------------------------------------------------
// Address: 0x1023F2F0
// Name: private: void CClient_Precipitation::CreateAshParticle(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CClient_Precipitation::CreateAshParticle(CClient_Precipitation *this@<ecx>, float a2@<ebp>)
{
  CSimpleEmitter *v3; // eax
  AshDebrisEffect *v4; // esi
  AshDebrisEffect *m_pObj; // ecx
  AshDebrisEffect *v6; // ecx
  C_BasePlayer *LocalPlayer; // esi
  const Vector *(__thiscall *WorldAlignMins)(C_BaseEntity *); // eax
  int v9; // eax
  float v10; // ecx
  __int64 v11; // xmm0_8
  const Vector *(__thiscall *WorldAlignMaxs)(C_BaseEntity *); // eax
  int v13; // eax
  float v14; // ecx
  float m_fNextEvent; // xmm0_4
  float x; // xmm1_4
  Vector *(__thiscall *EyePosition)(C_BaseEntity *, Vector *); // edx
  Vector *(__thiscall *v18)(C_BaseEntity *, Vector *); // edx
  float *v19; // eax
  float v20; // xmm2_4
  float v21; // xmm0_4
  bool v22; // zf
  float v23; // xmm0_4
  float v24; // xmm1_4
  __int64 v25; // xmm0_8
  AshDebrisEffect *v26; // ecx
  CParticleMgr *v27; // eax
  CParticleMgr *v28; // eax
  CParticleMgr *v29; // eax
  CParticleMgr *v30; // eax
  IUniformRandomStream *v31; // ecx
  float v32; // xmm0_4
  float v33; // xmm1_4
  IUniformRandomStream *v34; // ecx
  IUniformRandomStream *v35; // ecx
  IUniformRandomStream *v36; // ecx
  float v37; // xmm1_4
  float v38; // xmm2_4
  bool v39; // cc
  int v40; // eax
  Vector *v41; // eax
  float v42; // xmm1_4
  float v43; // xmm0_4
  float *p_z; // esi
  IUniformRandomStream *v45; // ecx
  double v46; // st7
  Particle *v47; // eax
  Particle *v48; // esi
  IUniformRandomStream *v49; // ecx
  Vector *v50; // eax
  Vector *(__thiscall *v51)(C_BaseEntity *, Vector *); // edx
  float *v52; // eax
  float v53; // xmm1_4
  float v54; // xmm2_4
  float y; // xmm1_4
  float z; // xmm2_4
  IUniformRandomStream *v57; // ecx
  IUniformRandomStream *v58; // ecx
  double v59; // st7
  int v60; // eax
  Vector val; // [esp+24h] [ebp-194h] BYREF
  CGameTrace tr; // [esp+30h] [ebp-188h] BYREF
  Vector v63; // [esp+88h] [ebp-130h] BYREF
  int v64; // [esp+94h] [ebp-124h] BYREF
  Vector v65; // [esp+A0h] [ebp-118h] BYREF
  Vector v66; // [esp+ACh] [ebp-10Ch] BYREF
  CGameTrace tr2; // [esp+B8h] [ebp-100h] BYREF
  __int64 v68; // [esp+110h] [ebp-A8h]
  float v69; // [esp+118h] [ebp-A0h]
  Vector absmins; // [esp+11Ch] [ebp-9Ch]
  Vector absmaxs; // [esp+128h] [ebp-90h] BYREF
  Vector m_vecAbsVelocity; // [esp+134h] [ebp-84h] BYREF
  Vector vecVelocity; // [esp+140h] [ebp-78h] BYREF
  CParticleSubTexture *hMaterial[4]; // [esp+14Ch] [ebp-6Ch] BYREF
  int v75; // [esp+15Ch] [ebp-5Ch]
  Vector v76; // [esp+160h] [ebp-58h] BYREF
  C_BasePlayer *v77; // [esp+16Ch] [ebp-4Ch]
  __int64 v78; // [esp+170h] [ebp-48h]
  C_BasePlayer *pPlayer; // [esp+178h] [ebp-40h]
  Vector vSpawnOrigin; // [esp+17Ch] [ebp-3Ch] BYREF
  Vector vForward; // [esp+188h] [ebp-30h] BYREF
  Vector offset; // [esp+194h] [ebp-24h] BYREF
  Vector vDir; // [esp+1A0h] [ebp-18h]
  float curTime; // [esp+1ACh] [ebp-Ch] BYREF
  int iRandomAltitude; // [esp+1B0h] [ebp-8h]
  int retaddr; // [esp+1B8h] [ebp+0h]

  curTime = a2;
  iRandomAltitude = retaddr;
  if ( this->m_Ash[0].m_pAshEmitter.m_pObj != nullptr )
    goto LABEL_13;
  v3 = (CSimpleEmitter *)MemAlloc_Alloc(nSize: 0x108u);
  v4 = (AshDebrisEffect *)v3;
  if ( v3 != nullptr )
  {
    CSimpleEmitter::CSimpleEmitter(this: v3, pDebugName: "ashtray");
    v4->__vftable = (AshDebrisEffect_vtbl *)&AshDebrisEffect::`vftable';
  }
  else
  {
    v4 = nullptr;
  }
  if ( v4 != this->m_Ash[0].m_pAshEmitter.m_pObj )
  {
    if ( v4 != nullptr )
      CParticleEffect::AddRef(this: v4);
    m_pObj = this->m_Ash[0].m_pAshEmitter.m_pObj;
    if ( m_pObj != nullptr )
      CParticleEffect::Release(this: m_pObj);
    this->m_Ash[0].m_pAshEmitter.m_pObj = v4;
  }
  if ( v4 != nullptr )
  {
    this->m_Ash[0].m_tAshParticleTimer.m_TimeBetweenEvents = 0.0052083335;
    this->m_Ash[0].m_tAshParticleTimer.m_fNextEvent = 0.0;
    this->m_Ash[0].m_tAshParticleTraceTimer.m_TimeBetweenEvents = 0.06666667;
    this->m_Ash[0].m_tAshParticleTraceTimer.m_fNextEvent = 0.0;
    v6 = this->m_Ash[0].m_pAshEmitter.m_pObj;
    this->m_Ash[0].m_bActiveAshEmitter = false;
    this->m_Ash[0].m_iAshCount = 0;
    CSimpleEmitter::SetShouldDrawForSplitScreenUser(this: v6, nSlot: 0);
LABEL_13:
    LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
    v77 = LocalPlayer;
    if ( LocalPlayer != nullptr )
    {
      C_BaseEntity::GetVectors(this: LocalPlayer, pForward: &vSpawnOrigin, pRight: nullptr, pUp: nullptr);
      WorldAlignMins = this->WorldAlignMins;
      vSpawnOrigin.z = 0.0;
      vDir.x = *(float *)(gpGlobals.m_Index + 16);
      v9 = (int)WorldAlignMins(this);
      v10 = *(float *)(v9 + 8);
      v11 = *(_QWORD *)v9;
      WorldAlignMaxs = this->WorldAlignMaxs;
      v69 = v10;
      v68 = v11;
      v13 = (int)WorldAlignMaxs(this);
      v14 = *(float *)(v13 + 8);
      *(_QWORD *)&absmins.x = *(_QWORD *)v13;
      absmins.z = v14;
      while ( 1 )
      {
        m_fNextEvent = this->m_Ash[0].m_tAshParticleTraceTimer.m_fNextEvent;
        x = vDir.x;
        if ( vDir.x < m_fNextEvent )
          break;
        this->m_Ash[0].m_tAshParticleTraceTimer.m_fNextEvent = this->m_Ash[0].m_tAshParticleTraceTimer.m_TimeBetweenEvents;
        EyePosition = LocalPlayer->EyePosition;
        vDir.x = x - m_fNextEvent;
        EyePosition(this: LocalPlayer, result: &offset);
        v18 = LocalPlayer->EyePosition;
        *(float *)&v78 = vSpawnOrigin.x * 56755.84;
        *((float *)&v78 + 1) = vSpawnOrigin.y * 56755.84;
        *(float *)&pPlayer = vSpawnOrigin.z * 56755.84;
        v19 = (float *)v18(this: LocalPlayer, result: &absmaxs);
        v20 = v19[2];
        v21 = (float)(*v19 + *(float *)&v78) - offset.x;
        tr2.startpos.z = (float)(v19[1] + *((float *)&v78 + 1)) - offset.y;
        tr2.startpos.y = v21;
        tr2.endpos.x = (float)(v20 + *(float *)&pPlayer) - offset.z;
        BYTE1(tr2.fractionleftsolid) = (float)((float)((float)(tr2.startpos.z * tr2.startpos.z) + (float)(v21 * v21))
                                             + (float)(tr2.endpos.x * tr2.endpos.x)) != 0.0;
        memset(&tr2.plane.dist, 0, 12);
        *(_DWORD *)&tr2.dispFlags = 0;
        LOBYTE(tr2.fractionleftsolid) = 1;
        memset(&tr2.endpos.z, 0, 12);
        v66 = offset;
        CTraceFilterSimple::CTraceFilterSimple(
          this: (CTraceFilterSimple *)&vecVelocity,
          passedict: LocalPlayer,
          collisionGroup: 0,
          pExtraShouldHitFunc: nullptr);
        enginetrace->TraceRay(
          this: enginetrace,
          a2: (const Ray_t *)&v66,
          a3: 100679683u,
          a4: (ITraceFilter *)&vecVelocity,
          a5: (CGameTrace *)&val);
        if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
          DebugDrawLine(vecAbsStart: &val, vecAbsEnd: &tr.startpos, r: 255, g: 0, b: 0, test: 1, duration: -1.0);
        if ( tr.plane.normal.z != 1.0 )
        {
          v76.x = 1.0;
          v76.y = 1.0;
          v76.z = 1.0;
          hMaterial[2] = (CParticleSubTexture *)-1082130432;
          hMaterial[3] = (CParticleSubTexture *)-1082130432;
          v75 = -1082130432;
          UTIL_TraceModel(
            a1: (int)&curTime,
            vecStart: &offset,
            vecEnd: &tr.startpos,
            hullMin: (const Vector *)&hMaterial[2],
            hullMax: &v76,
            pentModel: this,
            collisionGroup: 0,
            ptr: (CGameTrace *)&v66);
          if ( *(CClient_Precipitation **)&tr2.surface.surfaceProps == this )
          {
            v22 = tr2.plane.pad[1] == 0;
            this->m_Ash[0].m_bActiveAshEmitter = true;
            if ( v22 )
            {
              v23 = tr2.startpos.y + (float)(vSpawnOrigin.y * 256.0);
              v24 = tr2.startpos.z + (float)(vSpawnOrigin.z * 256.0);
              this->m_Ash[0].m_vAshSpawnOrigin.x = tr2.startpos.x + (float)(vSpawnOrigin.x * 256.0);
              this->m_Ash[0].m_vAshSpawnOrigin.y = v23;
              this->m_Ash[0].m_vAshSpawnOrigin.z = v24;
            }
            else
            {
              this->m_Ash[0].m_vAshSpawnOrigin = offset;
            }
          }
          else
          {
            this->m_Ash[0].m_bActiveAshEmitter = false;
          }
        }
      }
      this->m_Ash[0].m_tAshParticleTraceTimer.m_fNextEvent = this->m_Ash[0].m_tAshParticleTraceTimer.m_fNextEvent
                                                           - vDir.x;
      if ( this->m_Ash[0].m_bActiveAshEmitter )
      {
        C_BaseEntity::CalcAbsoluteVelocity(this: LocalPlayer);
        m_vecAbsVelocity = LocalPlayer->m_vecAbsVelocity;
        vDir.y = VectorNormalize(vec: &m_vecAbsVelocity);
        v25 = *(_QWORD *)&this->m_Ash[0].m_vAshSpawnOrigin.x;
        vForward.z = this->m_Ash[0].m_vAshSpawnOrigin.z;
        v26 = this->m_Ash[0].m_pAshEmitter.m_pObj;
        *(_QWORD *)&vForward.x = v25;
        CParticleEffect::SetSortOrigin(this: v26, vSortOrigin: &vForward);
        v27 = ParticleMgr();
        LODWORD(vecVelocity.x) = CParticleMgr::GetPMaterial(this: v27, pMaterialName: "effects/fleck_ash1");
        v28 = ParticleMgr();
        LODWORD(vecVelocity.y) = CParticleMgr::GetPMaterial(this: v28, pMaterialName: "effects/fleck_ash2");
        v29 = ParticleMgr();
        LODWORD(vecVelocity.z) = CParticleMgr::GetPMaterial(this: v29, pMaterialName: "effects/fleck_ash3");
        v30 = ParticleMgr();
        hMaterial[0] = CParticleMgr::GetPMaterial(this: v30, pMaterialName: "effects/ember_swirling001");
        v78 = *(_QWORD *)&vec3_origin.x;
        pPlayer = (C_BasePlayer *)LODWORD(vec3_origin.z);
        if ( vDir.y > 0.0 )
        {
          *(float *)&v78 = (float)(vSpawnOrigin.x * 256.0) + (float)(m_vecAbsVelocity.x * (float)(vDir.y * 2.0));
          *((float *)&v78 + 1) = (float)(vSpawnOrigin.y * 256.0) + (float)(m_vecAbsVelocity.y * (float)(vDir.y * 2.0));
        }
        while ( 1 )
        {
          v32 = this->m_Ash[0].m_tAshParticleTimer.m_fNextEvent;
          v33 = vDir.x;
          if ( vDir.x < v32 )
            break;
          this->m_Ash[0].m_tAshParticleTimer.m_fNextEvent = this->m_Ash[0].m_tAshParticleTimer.m_TimeBetweenEvents;
          vDir.x = v33 - v32;
          LODWORD(vDir.y) = _RandomInt(this: v31, a2: 0, a3: 128);
          *(float *)&hMaterial[2] = _RandomFloat(this: v34, a2: -256.0, a3: 256.0);
          *(float *)&hMaterial[3] = _RandomFloat(this: v35, a2: -256.0, a3: 256.0);
          _RandomFloat(this: v36, a2: -256.0, a3: 256.0);
          v37 = (float)(*((float *)&v78 + 1) + this->m_Ash[0].m_vAshSpawnOrigin.y) + *(float *)&hMaterial[3];
          v38 = this->m_Ash[0].m_vAshSpawnOrigin.z + (float)SLODWORD(vDir.y);
          vForward.x = (float)(this->m_Ash[0].m_vAshSpawnOrigin.x + *(float *)&v78) + *(float *)&hMaterial[2];
          vForward.y = v37;
          *(float *)&hMaterial[1] = (float)SLODWORD(vDir.y);
          vForward.z = v38;
          if ( vForward.x <= absmins.x
            && v37 <= absmins.y
            && v38 <= absmins.z
            && *(float *)&v68 <= vForward.x
            && *((float *)&v68 + 1) <= v37
            && v69 <= v38 )
          {
            v39 = ++this->m_Ash[0].m_iAshCount < 250;
            HIBYTE(vDir.z) = 0;
            if ( !v39 )
            {
              HIBYTE(vDir.z) = 1;
              this->m_Ash[0].m_iAshCount = 0;
            }
            v40 = random->RandomInt(this: random, a2: 0, a3: 2);
            if ( HIBYTE(vDir.z) == 1 )
            {
              v76.y = (float)(vSpawnOrigin.y * 256.0) + this->m_Ash[0].m_vAshSpawnOrigin.y;
              v76.z = this->m_Ash[0].m_vAshSpawnOrigin.z + (float)(vSpawnOrigin.z * 256.0);
              tr.startpos.x = 128.0;
              v76.x = this->m_Ash[0].m_vAshSpawnOrigin.x + (float)(vSpawnOrigin.x * 256.0);
              v41 = RandomVector(result: &v63, minVal: -128.0, maxVal: 128.0);
              v42 = v41->z + v76.z;
              v43 = v41->y + v76.y;
              vForward.x = v76.x + v41->x;
              vForward.y = v43;
              vForward.z = v42;
              p_z = &LocalPlayer->EyePosition(this: LocalPlayer, result: (Vector *)&v64)->z;
              v46 = _RandomFloat(this: v45, a2: -16.0, a3: 64.0);
              v40 = 3;
              vForward.z = v46 + *p_z;
            }
            v47 = CParticleEffect::AddParticle(
                    this: this->m_Ash[0].m_pAshEmitter.m_pObj,
                    particleSize: 0x3Cu,
                    material: *((CParticleSubTexture **)&vecVelocity.x + v40),
                    origin: &vForward);
            v48 = v47;
            if ( v47 != nullptr )
            {
              tr.startpos.y = 8.0;
              tr.startpos.x = 4.0;
              val.z = 128.0;
              val.y = 0.0;
              v47[1].m_Pos.z = 0.0;
              v47[1].m_Pos.y = RemapVal(
                                 val: *(float *)&hMaterial[1],
                                 A: val.y,
                                 B: val.z,
                                 C: tr.startpos.x,
                                 D: tr.startpos.y);
              if ( HIBYTE(vDir.z) == 1 )
              {
                v50 = RandomVector(result: &v65, minVal: -64.0, maxVal: 64.0);
                v51 = v77->EyePosition;
                LODWORD(vDir.y) = v50;
                v52 = (float *)v51(this: v77, result: (Vector *)&tr.m_pEnt);
                v53 = (float)(*(float *)(LODWORD(vDir.y) + 4) + v52[1]) - vForward.y;
                v54 = (float)(*(float *)(LODWORD(vDir.y) + 8) + v52[2]) - vForward.z;
                offset.x = (float)(*(float *)LODWORD(vDir.y) + *v52) - vForward.x;
                offset.y = v53;
                offset.z = v54;
                VectorNormalize(vec: &offset);
                y = offset.y;
                z = offset.z;
                *(float *)&v48[1].m_pPrev = offset.x * 75.0;
                *(float *)&v48[1].m_pNext = y * 75.0;
                *(float *)&v48[1].m_pSubTexture = z * 75.0;
                v48[1].m_Pos.y = 2.5;
              }
              else
              {
                absmaxs.x = _RandomFloat(this: v49, a2: -20.0, a3: 20.0);
                absmaxs.y = _RandomFloat(this: v57, a2: -20.0, a3: 20.0);
                v59 = _RandomFloat(this: v58, a2: -10.0, a3: -15.0);
                *(float *)&v48[1].m_pPrev = absmaxs.x;
                *(float *)&v48[1].m_pNext = absmaxs.y;
                *(float *)&v48[1].m_pSubTexture = v59;
              }
              v60 = (int)(float)random->RandomInt(this: random, a2: 125, a3: 225);
              LOBYTE(v48[2].m_pPrev) = v60;
              BYTE1(v48[2].m_pPrev) = v60;
              BYTE2(v48[2].m_pPrev) = v60;
              *(_WORD *)((char *)&v48[2].m_pNext + 1) = 257;
              HIBYTE(v48[2].m_pPrev) = -1;
              v48[1].m_Pos.x = (float)random->RandomInt(this: random, a2: 0, a3: 360);
              *(float *)&v48[2].m_pSubTexture = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                                  a1: random,
                                                  a2: -1105618534,
                                                  a3: 1041865114);
              HIBYTE(v48[2].m_pNext) = 1;
              if ( random->RandomInt(this: random, a2: 0, a3: 10) <= 1 )
                HIBYTE(v48[2].m_pNext) |= 4u;
            }
            LocalPlayer = v77;
          }
        }
        this->m_Ash[0].m_tAshParticleTimer.m_fNextEvent = this->m_Ash[0].m_tAshParticleTimer.m_fNextEvent - vDir.x;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1023FD90
// Name: public: virtual void C_Embers::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_Embers::OnDataChanged(C_Embers *this, DataUpdateType_t updateType)
{
  float m_TimeBetweenEvents; // ebx
  const Vector *v4; // eax

  C_BaseEntity::OnDataChanged(this, type: updateType);
  if ( updateType == DATA_UPDATE_CREATED )
  {
    m_TimeBetweenEvents = this->m_tParticleSpawn.m_TimeBetweenEvents;
    v4 = (const Vector *)(*(int (__thiscall **)(char *))(*((_DWORD *)this - 2) + 40))(a1: (char *)this - 8);
    CParticleEffect::SetSortOrigin(this: (CParticleEffect *)LODWORD(m_TimeBetweenEvents), vSortOrigin: v4);
    *(float *)&this->m_bEmit = 1.0 / (float)*(int *)&this->m_bIsBlurred;
    this->m_hMaterial = nullptr;
    this->m_nSpeed = (int)CParticleEffect::GetPMaterial(
                            this: (CParticleEffect *)LODWORD(this->m_tParticleSpawn.m_TimeBetweenEvents),
                            name: "particle/fire");
  }
  if ( LOBYTE(this->m_nLifetime) != 0 )
    C_BaseEntity::AddToEntityList(this: (C_Embers *)((char *)this - 8), listId: ENTITY_LIST_SIMULATE);
}

//------------------------------------------------------------------------------
// Address: 0x1023FE20
// Name: protected: void C_Embers::SpawnEmber(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_Embers::SpawnEmber(C_Embers *this)
{
  IVModelInfoClient_vtbl *v1; // esi
  int v3; // eax
  Particle *v4; // esi
  float v5; // xmm1_4
  const QAngle *v6; // eax
  float v7; // xmm2_4
  float v8; // xmm3_4
  int m_nSpeed; // ebx
  int v10; // ebx
  int v11; // ebx
  Vector *v12; // [esp+44h] [ebp-40h]
  Vector velocity; // [esp+50h] [ebp-34h] BYREF
  Vector offset; // [esp+5Ch] [ebp-28h] BYREF
  Vector mins; // [esp+68h] [ebp-1Ch] BYREF
  Vector maxs; // [esp+74h] [ebp-10h] BYREF
  float cScale; // [esp+80h] [ebp-4h]

  v1 = modelinfo->__vftable;
  v3 = ((int (__thiscall *)(IClientRenderable *, Vector *, Vector *))this->GetModel)(
         a1: &this->IClientRenderable,
         a2: &mins,
         a3: &maxs);
  ((void (__thiscall *)(IVModelInfoClient *, int))v1->GetModelBounds)(a1: modelinfo, a2: v3);
  offset.x = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, _DWORD))random->RandomFloat)(
               a1: random,
               a2: LODWORD(mins.x),
               a3: LODWORD(maxs.x));
  offset.y = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, _DWORD))random->RandomFloat)(
               a1: random,
               a2: LODWORD(mins.y),
               a3: LODWORD(maxs.y));
  offset.z = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, _DWORD))random->RandomFloat)(
               a1: random,
               a2: LODWORD(mins.z),
               a3: LODWORD(maxs.z));
  v4 = CParticleEffect::AddParticle(
         this: this->m_pEmitter.m_pObj,
         particleSize: 0x3Cu,
         material: this->m_hMaterial,
         origin: &offset);
  if ( v4 != nullptr )
  {
    cScale = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
               a1: random,
               a2: 1061158912,
               a3: 1065353216);
    v4[1].m_Pos.z = 0.0;
    v4[1].m_Pos.y = (float)this->m_nLifetime;
    v5 = cScale;
    LOBYTE(v4[2].m_pPrev) = (int)(float)((float)this->m_clrRender.m_Value.r * cScale);
    BYTE1(v4[2].m_pPrev) = (int)(float)((float)this->m_clrRender.m_Value.g * v5);
    BYTE2(v4[2].m_pPrev) = (int)(float)((float)this->m_clrRender.m_Value.b * v5);
    *(Particle **)((char *)&v4[2].m_pPrev + 3) = (Particle *)65791;
    v4[2].m_pSubTexture = nullptr;
    v4[1].m_Pos.x = 0.0;
    v6 = (const QAngle *)((int (__thiscall *)(C_Embers *, Vector *))this->GetAbsAngles)(a1: this, a2: &velocity);
    AngleVectors(angles: v6, forward: v12);
    v7 = velocity.y * (float)this->m_nSpeed;
    v8 = velocity.z * (float)this->m_nSpeed;
    *(float *)&v4[1].m_pPrev = velocity.x * (float)this->m_nSpeed;
    *(float *)&v4[1].m_pNext = v7;
    *(float *)&v4[1].m_pSubTexture = v8;
    m_nSpeed = this->m_nSpeed;
    cScale = *(float *)&random->__vftable;
    *(float *)&v4[1].m_pPrev = ((double (__thiscall *)(_DWORD, _DWORD))*(_DWORD *)(LODWORD(cScale) + 4))(
                                 a1: random,
                                 a2: (float)(m_nSpeed / -8))
                             + *(float *)&v4[1].m_pPrev;
    v10 = this->m_nSpeed;
    cScale = *(float *)&random->__vftable;
    *(float *)&v4[1].m_pNext = ((double (__thiscall *)(_DWORD, _DWORD, _DWORD))*(_DWORD *)(LODWORD(cScale) + 4))(
                                 a1: random,
                                 a2: (float)(v10 / -8),
                                 a3: (float)(v10 / 8))
                             + *(float *)&v4[1].m_pNext;
    v11 = this->m_nSpeed;
    cScale = *(float *)&random->__vftable;
    *(float *)&v4[1].m_pSubTexture = ((double (__thiscall *)(_DWORD, _DWORD, _DWORD))*(_DWORD *)(LODWORD(cScale) + 4))(
                                       a1: random,
                                       a2: (float)(v11 / -8),
                                       a3: (float)(v11 / 8))
                                   + *(float *)&v4[1].m_pSubTexture;
    C_BaseEntity::UpdateVisibility(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10240150
// Name: public: virtual int C_QuadraticBeam::DrawModel(int,struct RenderableInstance_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __userpurge C_QuadraticBeam::DrawModel@<eax>(
        C_QuadraticBeam *this@<ecx>,
        int a2@<edi>,
        int __formal,
        const RenderableInstance_t *instance)
{
  const struct model_t *v5; // eax
  int v6; // ecx
  int v7; // edx
  float v8; // xmm1_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  const Vector *v11; // eax
  float width; // [esp+0h] [ebp-20h]
  float scrollOffset; // [esp+8h] [ebp-18h]
  RenderMode_t flHDRColorScale; // [esp+Ch] [ebp-14h]
  Vector color; // [esp+14h] [ebp-Ch] BYREF
  int savedregs; // [esp+20h] [ebp+0h] BYREF

  flHDRColorScale = (unsigned __int8)this->m_iName[259];
  v5 = (const struct model_t *)this->GetClientThinkable(this);
  Draw_SetSpriteTexture(a1: (int)this, pSpriteModel: v5, frame: 0, rendermode: flHDRColorScale);
  v6 = BYTE1(this->model);
  v7 = BYTE2(this->model);
  v8 = (double)LOBYTE(this->model) * 0.00392156862745098;
  color.x = v8;
  v9 = (double)v6 * 0.00392156862745098;
  color.y = v9;
  v10 = (double)v7 * 0.00392156862745098;
  color.z = v10;
  scrollOffset = this->m_controlPosition.z * *(float *)(gpGlobals.m_Index + 12);
  width = this->m_scrollRate;
  v11 = (const Vector *)((int (__thiscall *)(C_QuadraticBeam *))this->SetRefEHandle)(a1: this);
  DrawBeamQuadratic(
    a1: (int)&savedregs,
    a2,
    a3: (int)this,
    start: v11,
    control: (const Vector *)&this->m_targetPosition.z,
    end: (const Vector *)(&this->m_bIsBlurred + 4),
    width,
    &color,
    scrollOffset);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10240230
// Name: private: bool CSnowFallManager::CreateSnowFallEmitter(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSnowFallManager::CreateSnowFallEmitter(CSnowFallManager *this)
{
  CSimpleEmitter *v2; // eax
  SnowFallEffect *v3; // esi
  SnowFallEffect *m_pObj; // ecx

  v2 = (CSimpleEmitter *)MemAlloc_Alloc(nSize: 0x108u);
  v3 = (SnowFallEffect *)v2;
  if ( v2 != nullptr )
  {
    CSimpleEmitter::CSimpleEmitter(this: v2, pDebugName: "snowfall");
    v3->__vftable = (SnowFallEffect_vtbl *)&SnowFallEffect::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  if ( v3 != this->m_pSnowFallEmitter.m_pObj )
  {
    if ( v3 != nullptr )
      CParticleEffect::AddRef(this: v3);
    m_pObj = this->m_pSnowFallEmitter.m_pObj;
    if ( m_pObj != nullptr )
      CParticleEffect::Release(this: m_pObj);
    this->m_pSnowFallEmitter.m_pObj = v3;
  }
  if ( v3 == nullptr )
    return 0;
  CSimpleEmitter::SetShouldDrawForSplitScreenUser(
    this: this->m_pSnowFallEmitter.m_pObj,
    nSlot: this->m_nSplitScreenPlayerSlot);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102402B0
// Name: private: int CSnowFallManager::StandingInSnowVolume(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSnowFallManager::StandingInSnowVolume(CSnowFallManager *this, Vector *vecPoint)
{
  int m_Size; // eax
  int v3; // edi
  int i; // esi
  CGameTrace traceSnow; // [esp+Ch] [ebp-5Ch] BYREF
  int nSnowCount; // [esp+60h] [ebp-8h]
  CSnowFallManager *v8; // [esp+64h] [ebp-4h]
  int savedregs; // [esp+68h] [ebp+0h] BYREF

  m_Size = this->m_aSnow.m_Size;
  v3 = 0;
  v8 = this;
  nSnowCount = m_Size;
  if ( m_Size <= 0 )
    return -1;
  for ( i = 0; ; ++i )
  {
    UTIL_TraceModel(
      a1: (int)&savedregs,
      vecStart: vecPoint,
      vecEnd: vecPoint,
      hullMin: &vec3_origin,
      hullMax: &vec3_origin,
      pentModel: this->m_aSnow.m_Memory.m_pMemory[i].m_pEntity,
      collisionGroup: 0,
      ptr: &traceSnow);
    if ( traceSnow.startsolid )
      break;
    if ( ++v3 >= nSnowCount )
      return -1;
    this = v8;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10240320
// Name: private: void CSnowFallManager::FindSnowVolumes(class Vector const __near &,float,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSnowFallManager::FindSnowVolumes(
        CSnowFallManager *this,
        const Vector *vecCenter,
        float flRadius,
        const Vector *vecEyePos,
        const Vector *vecForward)
{
  int m_Size; // eax
  int v7; // ebx
  int v8; // edi
  int v9; // ecx
  IClientLeafSystem_vtbl *v10; // ebx
  int v11; // eax
  bool v12; // al
  int v13; // ebx
  float m_fValue; // xmm2_4
  float y; // xmm1_4
  CSnowFallManager::SnowFall_t *m_pMemory; // ecx
  CBaseTrace trace; // [esp+1Ch] [ebp-4Ch] BYREF
  Vector vecNewForward; // [esp+54h] [ebp-14h] BYREF
  int nSnowCount; // [esp+60h] [ebp-8h]
  int v20; // [esp+64h] [ebp-4h]

  m_Size = this->m_aSnow.m_Size;
  v7 = 0;
  v8 = 0;
  this->m_nActiveSnowCount = 0;
  this->m_bRayParticles = false;
  nSnowCount = m_Size;
  if ( m_Size > 0 )
  {
    v20 = 0;
    do
    {
      v9 = *(int *)((char *)&this->m_aSnow.m_Memory.m_pMemory->m_pEntity + v7);
      v10 = g_pClientLeafSystem->IClientLeafSystemEngine::__vftable;
      v11 = (*(int (__thiscall **)(int))(*(_DWORD *)v9 + 20))(a1: v9);
      v12 = v10->IsRenderableInPVS(this: g_pClientLeafSystem, a2: (IClientRenderable *)v11);
      v13 = v20;
      if ( v12 )
      {
        if ( IsBoxIntersectingSphere(
               boxMin: (const Vector *)((char *)&this->m_aSnow.m_Memory.m_pMemory->m_vecMin + v20),
               boxMax: (const Vector *)((char *)&this->m_aSnow.m_Memory.m_pMemory->m_vecMax + v20),
               center: vecCenter,
               radius: flRadius) )
        {
          this->m_aActiveSnow[this->m_nActiveSnowCount++] = v8;
          if ( this->m_nActiveSnowCount >= 32 )
            goto LABEL_12;
        }
        else
        {
          m_fValue = r_SnowRayLength.m_pParent->m_Value.m_fValue;
          y = vecForward->y;
          m_pMemory = this->m_aSnow.m_Memory.m_pMemory;
          vecNewForward.x = vecForward->x * m_fValue;
          vecNewForward.z = 0.0;
          vecNewForward.y = y * m_fValue;
          IntersectRayWithBox(
            vecRayStart: vecEyePos,
            vecRayDelta: &vecNewForward,
            boxMins: (const Vector *)((char *)&m_pMemory->m_vecMin + v13),
            boxMaxs: (const Vector *)((char *)&m_pMemory->m_vecMax + v13),
            flTolerance: 0.32499999,
            pTrace: &trace,
            pFractionLeftSolid: nullptr);
          if ( trace.fraction < 1.0 )
          {
            this->m_aActiveSnow[this->m_nActiveSnowCount++] = v8;
            if ( this->m_nActiveSnowCount >= 32 )
            {
LABEL_12:
              _DevWarning(a1: 1, a2: "Max Active Snow Volume Count!\n");
              return;
            }
            this->m_bRayParticles = true;
          }
        }
      }
      ++v8;
      v7 = v13 + 36;
      v20 = v7;
    }
    while ( v8 < nSnowCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x102404B0
// Name: private: void CSnowFallManager::CreateSnowFallParticle(class Vector const __near &,int,class C_BasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSnowFallManager::CreateSnowFallParticle(
        CSnowFallManager *this,
        const Vector *vecParticleSpawn,
        int iSnow,
        C_BasePlayer *pLocalPlayer)
{
  int v5; // edi
  Particle *v6; // eax
  Particle *v7; // esi
  IUniformRandomStream *v8; // ecx
  IUniformRandomStream *v9; // ecx
  double v10; // st7
  CSnowFallManager::SnowFall_t *m_pMemory; // edx
  float v12; // xmm0_4
  int m_nValue; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  Particle *v17; // [esp+14h] [ebp-Ch]
  float v18; // [esp+18h] [ebp-8h]
  float iSnowa; // [esp+2Ch] [ebp+Ch]

  v5 = iSnow;
  v6 = CParticleEffect::AddParticle(
         this: this->m_pSnowFallEmitter.m_pObj,
         particleSize: 0x3Cu,
         material: this->m_aSnow.m_Memory.m_pMemory[iSnow].m_hMaterial,
         origin: vecParticleSpawn);
  v7 = v6;
  if ( v6 != nullptr )
  {
    v6[1].m_Pos.z = 0.0;
    iSnowa = r_SnowFallSpeed.m_pParent->m_Value.m_fValue;
    _RandomFloat(this: (IUniformRandomStream *)r_SnowFallSpeed.m_pParent, a2: -5.0, a3: 5.0);
    v18 = _RandomFloat(this: v8, a2: -5.0, a3: 5.0);
    v10 = _RandomFloat(this: v9, a2: -25.0, a3: -35.0);
    m_pMemory = this->m_aSnow.m_Memory.m_pMemory;
    v7[1].m_pPrev = v17;
    *(float *)&v7[1].m_pNext = v18;
    *(float *)&v7[1].m_pSubTexture = v10 * iSnowa;
    v12 = COERCE_DOUBLE(
            COERCE_UNSIGNED_INT64((float)(vecParticleSpawn->z - m_pMemory[v5].m_vecMin.z) / (*(float *)&v7[1].m_pSubTexture
                                                                                           - 0.1))
          & _mask__AbsDouble_);
    v7[1].m_Pos.y = v12;
    LOBYTE(v7[2].m_pPrev) = this->m_aSnow.m_Memory.m_pMemory[v5].m_pEntity->m_clrRender.m_Value.r;
    BYTE1(v7[2].m_pPrev) = this->m_aSnow.m_Memory.m_pMemory[v5].m_pEntity->m_clrRender.m_Value.g;
    BYTE2(v7[2].m_pPrev) = this->m_aSnow.m_Memory.m_pMemory[v5].m_pEntity->m_clrRender.m_Value.b;
    if ( r_SnowStartSize.m_pParent != nullptr )
      m_nValue = r_SnowStartSize.m_pParent->m_Value.m_nValue;
    else
      LOBYTE(m_nValue) = 0;
    BYTE1(v7[2].m_pNext) = m_nValue;
    if ( r_SnowEndSize.m_pParent != nullptr )
      v14 = r_SnowEndSize.m_pParent->m_Value.m_nValue;
    else
      LOBYTE(v14) = 0;
    BYTE2(v7[2].m_pNext) = v14;
    if ( r_SnowStartAlpha.m_pParent != nullptr )
      v15 = r_SnowStartAlpha.m_pParent->m_Value.m_nValue;
    else
      LOBYTE(v15) = 0;
    HIBYTE(v7[2].m_pPrev) = v15;
    if ( r_SnowEndAlpha.m_pParent != nullptr )
      v16 = r_SnowEndAlpha.m_pParent->m_Value.m_nValue;
    else
      LOBYTE(v16) = 0;
    LOBYTE(v7[2].m_pNext) = v16;
    v7[1].m_Pos.x = (float)random->RandomInt(this: random, a2: 0, a3: 360);
    *(float *)&v7[2].m_pSubTexture = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                       a1: random,
                                       a2: -1105618534,
                                       a3: 1041865114);
    HIBYTE(v7[2].m_pNext) = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10240890
// Name: public: virtual void CPrecipHack::LevelShutdownPreEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrecipHack::LevelShutdownPreEntity(CPrecipHack *this)
{
  if ( r_RainHack.m_pParent != nullptr
    && r_RainHack.m_pParent->m_Value.m_nValue != 0
    && g_pPrecipHackEnt.m_Index != -1
    && g_pEntityList->m_EntPtrArray[LOWORD(g_pPrecipHackEnt.m_Index)].m_SerialNumber == HIWORD(g_pPrecipHackEnt.m_Index)
    && g_pEntityList->m_EntPtrArray[LOWORD(g_pPrecipHackEnt.m_Index)].m_pEntity != nullptr )
  {
    if ( g_pEntityList->m_EntPtrArray[LOWORD(g_pPrecipHackEnt.m_Index)].m_SerialNumber == HIWORD(g_pPrecipHackEnt.m_Index) )
    {
      C_BaseEntity::Remove(this: (C_BaseEntity *)g_pEntityList->m_EntPtrArray[LOWORD(g_pPrecipHackEnt.m_Index)].m_pEntity);
      this->m_bLevelInitted = false;
      return;
    }
    C_BaseEntity::Remove(this: nullptr);
  }
  this->m_bLevelInitted = false;
}

//------------------------------------------------------------------------------
// Address: 0x10240900
// Name: public: virtual void CPrecipHack::Update(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrecipHack::Update(CPrecipHack *this, float frametime)
{
  if ( this->m_bLevelInitted )
  {
    if ( r_RainHack.m_pParent != nullptr && r_RainHack.m_pParent->m_Value.m_nValue != 0 )
    {
      if ( g_pPrecipHackEnt.m_Index == -1
        || g_pEntityList->m_EntPtrArray[LOWORD(g_pPrecipHackEnt.m_Index)].m_SerialNumber != HIWORD(g_pPrecipHackEnt.m_Index)
        || g_pEntityList->m_EntPtrArray[LOWORD(g_pPrecipHackEnt.m_Index)].m_pEntity == nullptr )
      {
        this->LevelInitPostEntity(this);
      }
    }
    else if ( g_pPrecipHackEnt.m_Index != -1
           && g_pEntityList->m_EntPtrArray[LOWORD(g_pPrecipHackEnt.m_Index)].m_SerialNumber == HIWORD(g_pPrecipHackEnt.m_Index)
           && g_pEntityList->m_EntPtrArray[LOWORD(g_pPrecipHackEnt.m_Index)].m_pEntity != nullptr )
    {
      this->LevelShutdownPreEntity(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102409E0
// Name: public: C_Embers::C_Embers(void)
// Source: json
//------------------------------------------------------------------------------
C_Embers *__thiscall C_Embers::C_Embers(C_Embers *this)
{
  CParticleEffect *v2; // ebx
  CSimpleEmitter *v3; // eax
  CParticleEffect *v4; // edi
  CEmberEmitter *v5; // edi
  CEmberEmitter *m_pObj; // ecx

  C_BaseEntity::C_BaseEntity(this);
  this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_Embers_vtbl *)&C_Embers::`vftable'{for `IClientUnknown'};
  this->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_Embers::`vftable'{for `IClientRenderable'};
  this->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_Embers::`vftable'{for `IClientNetworkable'};
  this->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_Embers::`vftable'{for `IClientThinkable'};
  this->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_Embers::`vftable';
  this->m_tParticleSpawn.m_TimeBetweenEvents = -1.0;
  v2 = nullptr;
  this->m_tParticleSpawn.m_fNextEvent = 0.0;
  this->m_pEmitter.m_pObj = nullptr;
  v3 = (CSimpleEmitter *)MemAlloc_Alloc(nSize: 0x108u);
  v4 = v3;
  if ( v3 != nullptr )
  {
    CSimpleEmitter::CSimpleEmitter(this: v3, pDebugName: "C_Embers");
    v4->__vftable = (CParticleEffect_vtbl *)&CEmberEmitter::`vftable';
    v2 = v4;
  }
  v5 = nullptr;
  if ( v2 != nullptr )
  {
    CParticleEffect::AddRef(this: v2);
    v5 = (CEmberEmitter *)v2;
  }
  if ( v5 != this->m_pEmitter.m_pObj )
  {
    if ( v5 != nullptr )
      CParticleEffect::AddRef(this: v5);
    m_pObj = this->m_pEmitter.m_pObj;
    if ( m_pObj != nullptr )
      CParticleEffect::Release(this: m_pObj);
    this->m_pEmitter.m_pObj = v5;
  }
  if ( v5 != nullptr )
    CParticleEffect::Release(this: v5);
  C_BaseEntity::AddToEntityList(this, listId: ENTITY_LIST_SIMULATE);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10240B10
// Name: public: virtual bool C_Embers::Simulate(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_Embers::Simulate(C_Embers *this)
{
  float i; // xmm1_4
  float m_fNextEvent; // xmm0_4

  if ( !this->m_bEmit )
    return 0;
  for ( i = *(float *)(gpGlobals.m_Index + 16); ; i = i - m_fNextEvent )
  {
    m_fNextEvent = this->m_tParticleSpawn.m_fNextEvent;
    if ( i < m_fNextEvent )
      break;
    this->m_tParticleSpawn.m_fNextEvent = this->m_tParticleSpawn.m_TimeBetweenEvents;
    C_Embers::SpawnEmber(this);
  }
  this->m_tParticleSpawn.m_fNextEvent = this->m_tParticleSpawn.m_fNextEvent - i;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10240B80
// Name: private: void CSnowFallManager::CreateOutsideVolumeSnowParticles(float,float,float,class C_BasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSnowFallManager::CreateOutsideVolumeSnowParticles(
        CSnowFallManager *this,
        float flCurrentTime,
        float flRadius,
        float flZoomScale,
        C_BasePlayer *pLocalPlayer)
{
  int v6; // edi
  float m_fNextEvent; // xmm0_4
  int NumActiveParticles; // eax
  int m_nValue; // ecx
  IUniformRandomStream *v10; // ecx
  Vector vecParticleSpawn; // [esp+14h] [ebp-Ch] BYREF
  float flRadius2; // [esp+2Ch] [ebp+Ch]

  v6 = 0;
  flRadius2 = (float)(flRadius * flZoomScale) * (float)(flRadius * flZoomScale);
  while ( 1 )
  {
    m_fNextEvent = this->m_tSnowFallParticleTimer.m_fNextEvent;
    if ( flCurrentTime < m_fNextEvent )
      break;
    this->m_tSnowFallParticleTimer.m_fNextEvent = this->m_tSnowFallParticleTimer.m_TimeBetweenEvents;
    flCurrentTime = flCurrentTime - m_fNextEvent;
    NumActiveParticles = CParticleEffectBinding::GetNumActiveParticles(this: &this->m_pSnowFallEmitter.m_pObj->m_ParticleEffect);
    if ( r_SnowParticles.m_pParent != nullptr )
      m_nValue = r_SnowParticles.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    if ( NumActiveParticles < m_nValue )
    {
      vecParticleSpawn.x = _RandomFloat(
                             this: (IUniformRandomStream *)this->m_aSnow.m_Memory.m_pMemory,
                             a2: this->m_aSnow.m_Memory.m_pMemory[this->m_aActiveSnow[v6]].m_vecMin.x,
                             a3: this->m_aSnow.m_Memory.m_pMemory[this->m_aActiveSnow[v6]].m_vecMax.x);
      vecParticleSpawn.y = _RandomFloat(
                             this: v10,
                             a2: this->m_aSnow.m_Memory.m_pMemory[this->m_aActiveSnow[v6]].m_vecMin.y,
                             a3: this->m_aSnow.m_Memory.m_pMemory[this->m_aActiveSnow[v6]].m_vecMax.y);
      vecParticleSpawn.z = _RandomFloat(
                             this: (IUniformRandomStream *)(9 * this->m_aActiveSnow[v6]),
                             a2: this->m_aSnow.m_Memory.m_pMemory[this->m_aActiveSnow[v6]].m_vecMin.z,
                             a3: this->m_aSnow.m_Memory.m_pMemory[this->m_aActiveSnow[v6]].m_vecMax.z);
      if ( flRadius2 > (float)((float)((float)((float)(this->m_vecSnowFallEmitOrigin.x - vecParticleSpawn.x)
                                             * (float)(this->m_vecSnowFallEmitOrigin.x - vecParticleSpawn.x))
                                     + (float)((float)(this->m_vecSnowFallEmitOrigin.y - vecParticleSpawn.y)
                                             * (float)(this->m_vecSnowFallEmitOrigin.y - vecParticleSpawn.y)))
                             + (float)((float)(this->m_vecSnowFallEmitOrigin.z - vecParticleSpawn.z)
                                     * (float)(this->m_vecSnowFallEmitOrigin.z - vecParticleSpawn.z))) )
        CSnowFallManager::CreateSnowFallParticle(this, &vecParticleSpawn, iSnow: this->m_aActiveSnow[v6], pLocalPlayer);
      v6 = (v6 + 1) % this->m_nActiveSnowCount;
    }
  }
  this->m_tSnowFallParticleTimer.m_fNextEvent = this->m_tSnowFallParticleTimer.m_fNextEvent - flCurrentTime;
}

//------------------------------------------------------------------------------
// Address: 0x10240D30
// Name: private: void CSnowFallManager::CreateSnowParticlesSphere(float,class C_BasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall CSnowFallManager::CreateSnowParticlesSphere(
        CSnowFallManager *this,
        float flRadius,
        C_BasePlayer *pLocalPlayer)
{
  IUniformRandomStream *v4; // ecx
  IUniformRandomStream *v5; // ecx
  double v6; // st7
  int m_nActiveSnowCount; // edi
  int v8; // edx
  CSnowFallManager::SnowFall_t *m_pMemory; // esi
  int *v10; // ecx
  float *v11; // eax
  float *v12; // eax
  float *v13; // eax
  float *v14; // eax
  bool v15; // zf
  int *v16; // ecx
  CSnowFallManager::SnowFall_t *v17; // eax
  Vector vecParticleSpawn; // [esp+14h] [ebp-10h] BYREF
  float v19; // [esp+20h] [ebp-4h]

  LODWORD(v19) = LODWORD(flRadius) ^ _mask__NegFloat_;
  vecParticleSpawn.x = _RandomFloat(
                         (IUniformRandomStream *)this,
                         a2: COERCE_FLOAT(LODWORD(flRadius) ^ _mask__NegFloat_),
                         a3: flRadius)
                     + this->m_vecSnowFallEmitOrigin.x;
  vecParticleSpawn.y = _RandomFloat(this: v4, a2: COERCE_FLOAT(LODWORD(flRadius) ^ _mask__NegFloat_), a3: flRadius)
                     + this->m_vecSnowFallEmitOrigin.y;
  v6 = _RandomFloat(this: v5, a2: COERCE_FLOAT(LODWORD(flRadius) ^ _mask__NegFloat_), a3: flRadius);
  m_nActiveSnowCount = this->m_nActiveSnowCount;
  vecParticleSpawn.z = v6 + this->m_vecSnowFallEmitOrigin.z;
  v8 = 0;
  if ( m_nActiveSnowCount < 4 )
  {
LABEL_28:
    v15 = v8 == m_nActiveSnowCount;
    if ( v8 >= m_nActiveSnowCount )
      goto LABEL_42;
    v16 = &this->m_aActiveSnow[v8];
    do
    {
      v17 = &this->m_aSnow.m_Memory.m_pMemory[*v16];
      if ( v17->m_vecMin.x <= vecParticleSpawn.x
        && vecParticleSpawn.x <= v17->m_vecMax.x
        && v17->m_vecMin.y <= vecParticleSpawn.y
        && vecParticleSpawn.y <= v17->m_vecMax.y
        && v17->m_vecMin.z <= vecParticleSpawn.z
        && vecParticleSpawn.z <= v17->m_vecMax.z )
      {
        break;
      }
      ++v8;
      ++v16;
    }
    while ( v8 < m_nActiveSnowCount );
  }
  else
  {
    m_pMemory = this->m_aSnow.m_Memory.m_pMemory;
    v10 = &this->m_aActiveSnow[1];
    while ( 1 )
    {
      v11 = (float *)&m_pMemory[*(v10 - 1)];
      if ( v11[3] <= vecParticleSpawn.x
        && vecParticleSpawn.x <= v11[6]
        && v11[4] <= vecParticleSpawn.y
        && vecParticleSpawn.y <= v11[7]
        && v11[5] <= vecParticleSpawn.z
        && vecParticleSpawn.z <= v11[8] )
      {
        break;
      }
      v12 = (float *)&m_pMemory[*v10];
      if ( v12[3] <= vecParticleSpawn.x
        && vecParticleSpawn.x <= v12[6]
        && v12[4] <= vecParticleSpawn.y
        && vecParticleSpawn.y <= v12[7]
        && v12[5] <= vecParticleSpawn.z
        && vecParticleSpawn.z <= v12[8] )
      {
        ++v8;
        break;
      }
      v13 = (float *)&m_pMemory[v10[1]];
      if ( v13[3] <= vecParticleSpawn.x
        && vecParticleSpawn.x <= v13[6]
        && v13[4] <= vecParticleSpawn.y
        && vecParticleSpawn.y <= v13[7]
        && v13[5] <= vecParticleSpawn.z
        && vecParticleSpawn.z <= v13[8] )
      {
        v8 += 2;
        break;
      }
      v14 = (float *)&m_pMemory[v10[2]];
      if ( v14[3] <= vecParticleSpawn.x
        && vecParticleSpawn.x <= v14[6]
        && v14[4] <= vecParticleSpawn.y
        && vecParticleSpawn.y <= v14[7]
        && v14[5] <= vecParticleSpawn.z
        && vecParticleSpawn.z <= v14[8] )
      {
        v8 += 3;
        break;
      }
      v8 += 4;
      v10 += 4;
      if ( v8 >= m_nActiveSnowCount - 3 )
        goto LABEL_28;
    }
  }
  v15 = v8 == m_nActiveSnowCount;
LABEL_42:
  if ( !v15 )
    CSnowFallManager::CreateSnowFallParticle(this, &vecParticleSpawn, iSnow: this->m_aActiveSnow[v8], pLocalPlayer);
}

//------------------------------------------------------------------------------
// Address: 0x10240F80
// Name: private: void CSnowFallManager::CreateSnowParticlesRay(float,class Vector const __near &,class Vector const __near &,class C_BasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
// positive sp value has been detected, the output may be wrong!
void __thiscall CSnowFallManager::CreateSnowParticlesRay(
        CSnowFallManager *this,
        float flRadius,
        const Vector *vecEyePos,
        const Vector *vecForward,
        C_BasePlayer *pLocalPlayer)
{
  float v6; // xmm2_4
  IUniformRandomStream *v7; // ecx
  IUniformRandomStream *v8; // ecx
  IUniformRandomStream *v9; // ecx
  double v10; // st7
  int m_nActiveSnowCount; // edi
  int v12; // edx
  CSnowFallManager::SnowFall_t *m_pMemory; // esi
  int *v14; // ecx
  float *v15; // eax
  float *v16; // eax
  float *v17; // eax
  float *v18; // eax
  bool v19; // zf
  int *v20; // ecx
  CSnowFallManager::SnowFall_t *v21; // eax
  Vector vecParticleSpawn; // [esp+14h] [ebp-10h] BYREF
  float flRayRadius; // [esp+20h] [ebp-4h]
  float flRadiusa; // [esp+2Ch] [ebp+8h]

  if ( this->m_bRayParticles || r_SnowRayEnable.m_pParent == nullptr || r_SnowRayEnable.m_pParent->m_Value.m_nValue == 0 )
  {
    flRayRadius = r_SnowRayRadius.m_pParent->m_Value.m_fValue;
    flRadiusa = _RandomFloat(
                  this: (IUniformRandomStream *)r_SnowRayLength.m_pParent,
                  a2: flRadius,
                  a3: r_SnowRayLength.m_pParent->m_Value.m_fValue);
    v6 = vecEyePos->x + (float)(vecForward->x * flRadiusa);
    vecParticleSpawn.y = vecEyePos->y + (float)(vecForward->y * flRadiusa);
    vecParticleSpawn.x = v6;
    vecParticleSpawn.z = _RandomFloat(this: v7, a2: 72.0, a3: flRayRadius) + vecEyePos->z;
    vecParticleSpawn.x = _RandomFloat(
                           this: v8,
                           a2: COERCE_FLOAT(LODWORD(flRayRadius) ^ _mask__NegFloat_),
                           a3: flRayRadius)
                       + v6;
    v10 = _RandomFloat(this: v9, a2: COERCE_FLOAT(LODWORD(flRayRadius) ^ _mask__NegFloat_), a3: flRayRadius);
    m_nActiveSnowCount = this->m_nActiveSnowCount;
    vecParticleSpawn.y = v10 + vecParticleSpawn.y;
    v12 = 0;
    if ( m_nActiveSnowCount < 4 )
    {
LABEL_31:
      v19 = v12 == m_nActiveSnowCount;
      if ( v12 >= m_nActiveSnowCount )
        goto LABEL_45;
      v20 = &this->m_aActiveSnow[v12];
      do
      {
        v21 = &this->m_aSnow.m_Memory.m_pMemory[*v20];
        if ( v21->m_vecMin.x <= vecParticleSpawn.x
          && vecParticleSpawn.x <= v21->m_vecMax.x
          && v21->m_vecMin.y <= vecParticleSpawn.y
          && vecParticleSpawn.y <= v21->m_vecMax.y
          && v21->m_vecMin.z <= vecParticleSpawn.z
          && vecParticleSpawn.z <= v21->m_vecMax.z )
        {
          break;
        }
        ++v12;
        ++v20;
      }
      while ( v12 < m_nActiveSnowCount );
    }
    else
    {
      m_pMemory = this->m_aSnow.m_Memory.m_pMemory;
      v14 = &this->m_aActiveSnow[1];
      while ( 1 )
      {
        v15 = (float *)&m_pMemory[*(v14 - 1)];
        if ( v15[3] <= vecParticleSpawn.x
          && vecParticleSpawn.x <= v15[6]
          && v15[4] <= vecParticleSpawn.y
          && vecParticleSpawn.y <= v15[7]
          && v15[5] <= vecParticleSpawn.z
          && vecParticleSpawn.z <= v15[8] )
        {
          break;
        }
        v16 = (float *)&m_pMemory[*v14];
        if ( v16[3] <= vecParticleSpawn.x
          && vecParticleSpawn.x <= v16[6]
          && v16[4] <= vecParticleSpawn.y
          && vecParticleSpawn.y <= v16[7]
          && v16[5] <= vecParticleSpawn.z
          && vecParticleSpawn.z <= v16[8] )
        {
          ++v12;
          break;
        }
        v17 = (float *)&m_pMemory[v14[1]];
        if ( v17[3] <= vecParticleSpawn.x
          && vecParticleSpawn.x <= v17[6]
          && v17[4] <= vecParticleSpawn.y
          && vecParticleSpawn.y <= v17[7]
          && v17[5] <= vecParticleSpawn.z
          && vecParticleSpawn.z <= v17[8] )
        {
          v12 += 2;
          break;
        }
        v18 = (float *)&m_pMemory[v14[2]];
        if ( v18[3] <= vecParticleSpawn.x
          && vecParticleSpawn.x <= v18[6]
          && v18[4] <= vecParticleSpawn.y
          && vecParticleSpawn.y <= v18[7]
          && v18[5] <= vecParticleSpawn.z
          && vecParticleSpawn.z <= v18[8] )
        {
          v12 += 3;
          break;
        }
        v12 += 4;
        v14 += 4;
        if ( v12 >= m_nActiveSnowCount - 3 )
          goto LABEL_31;
      }
    }
    v19 = v12 == m_nActiveSnowCount;
LABEL_45:
    if ( !v19 )
      CSnowFallManager::CreateSnowFallParticle(this, &vecParticleSpawn, iSnow: this->m_aActiveSnow[v12], pLocalPlayer);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10241330
// Name: private: void CSnowFallManager::CreateInsideVolumeSnowParticles(float,float,class Vector const __near &,class Vector const __near &,float,class C_BasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSnowFallManager::CreateInsideVolumeSnowParticles(
        CSnowFallManager *this,
        float flCurrentTime,
        float flRadius,
        const Vector *vecEyePos,
        const Vector *vecForward,
        float flZoomScale,
        C_BasePlayer *pLocalPlayer)
{
  float m_fNextEvent; // xmm0_4
  SnowFallEffect *m_pObj; // ecx
  int NumActiveParticles; // eax
  int m_nValue; // ecx
  int iIndex; // [esp+1Ch] [ebp-8h]
  float flZoomRadius; // [esp+20h] [ebp-4h]
  bool bZoomed_3; // [esp+3Fh] [ebp+1Bh]

  bZoomed_3 = flZoomScale > 1.0;
  flZoomRadius = 0.0;
  if ( bZoomed_3 )
    flZoomRadius = flRadius * flZoomScale;
  iIndex = 0;
  while ( 1 )
  {
    m_fNextEvent = this->m_tSnowFallParticleTimer.m_fNextEvent;
    if ( flCurrentTime < m_fNextEvent )
      break;
    m_pObj = this->m_pSnowFallEmitter.m_pObj;
    this->m_tSnowFallParticleTimer.m_fNextEvent = this->m_tSnowFallParticleTimer.m_TimeBetweenEvents;
    flCurrentTime = flCurrentTime - m_fNextEvent;
    NumActiveParticles = CParticleEffectBinding::GetNumActiveParticles(this: &m_pObj->m_ParticleEffect);
    if ( r_SnowParticles.m_pParent != nullptr )
      m_nValue = r_SnowParticles.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    if ( NumActiveParticles < m_nValue )
    {
      if ( iIndex <= 0 )
      {
        CSnowFallManager::CreateSnowParticlesSphere(this, flRadius, pLocalPlayer);
        CSnowFallManager::CreateSnowParticlesRay(this, flRadius, vecEyePos, vecForward, pLocalPlayer);
      }
      else
      {
        CSnowFallManager::CreateSnowParticlesSphere(this, flRadius: flZoomRadius, pLocalPlayer);
        CSnowFallManager::CreateSnowParticlesRay(this, flRadius: flZoomRadius, vecEyePos, vecForward, pLocalPlayer);
      }
      if ( bZoomed_3 )
        iIndex = (iIndex + 1) % 3;
    }
  }
  this->m_tSnowFallParticleTimer.m_fNextEvent = this->m_tSnowFallParticleTimer.m_fNextEvent - flCurrentTime;
}

//------------------------------------------------------------------------------
// Address: 0x102414F0
// Name: public: C_PrecipitationBlocker::C_PrecipitationBlocker(void)
// Source: json
//------------------------------------------------------------------------------
C_PrecipitationBlocker *__thiscall C_PrecipitationBlocker::C_PrecipitationBlocker(C_PrecipitationBlocker *this)
{
  int m_Size; // eax
  int v3; // edi
  C_PrecipitationBlocker **m_pMemory; // ecx
  int v5; // eax
  C_PrecipitationBlocker **v6; // eax

  C_BaseEntity::C_BaseEntity(this);
  this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_PrecipitationBlocker_vtbl *)&C_PrecipitationBlocker::`vftable'{for `IClientUnknown'};
  this->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_PrecipitationBlocker::`vftable'{for `IClientRenderable'};
  this->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_PrecipitationBlocker::`vftable'{for `IClientNetworkable'};
  this->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_PrecipitationBlocker::`vftable'{for `IClientThinkable'};
  this->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_PrecipitationBlocker::`vftable';
  m_Size = g_PrecipitationBlockers.m_Size;
  v3 = g_PrecipitationBlockers.m_Size;
  if ( g_PrecipitationBlockers.m_Size + 1 > g_PrecipitationBlockers.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<CChoreoActor *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&g_PrecipitationBlockers,
      num: g_PrecipitationBlockers.m_Size - g_PrecipitationBlockers.m_Memory.m_nAllocationCount + 1);
    m_Size = g_PrecipitationBlockers.m_Size;
  }
  m_pMemory = g_PrecipitationBlockers.m_Memory.m_pMemory;
  g_PrecipitationBlockers.m_Size = m_Size + 1;
  v5 = m_Size - v3;
  g_PrecipitationBlockers.m_pElements = g_PrecipitationBlockers.m_Memory.m_pMemory;
  if ( v5 > 0 )
  {
    _V_memmove(
      dest: (unsigned __int8 *)&g_PrecipitationBlockers.m_Memory.m_pMemory[v3 + 1],
      src: (unsigned __int8 *)&g_PrecipitationBlockers.m_Memory.m_pMemory[v3],
      count: 4 * v5);
    m_pMemory = g_PrecipitationBlockers.m_Memory.m_pMemory;
  }
  v6 = &m_pMemory[v3];
  if ( v6 != nullptr )
    *v6 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102415F0
// Name: public: virtual CClient_Precipitation::~CClient_Precipitation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClient_Precipitation::~CClient_Precipitation(CClient_Precipitation *this)
{
  CNewParticleEffect *m_pObject; // ecx
  CUtlReference<CNewParticleEffect> *m_pParticlePrecipOuter; // eax
  CUtlReference<CNewParticleEffect> *m_pPrev; // edx
  CUtlReference<CNewParticleEffect> *m_pNext; // edx
  CNewParticleEffect *v6; // ecx
  CUtlReference<CNewParticleEffect> *m_pParticlePrecipInnerFar; // eax
  CUtlReference<CNewParticleEffect> *v8; // edx
  CUtlReference<CNewParticleEffect> *v9; // edx
  CNewParticleEffect *v10; // ecx
  CUtlReference<CNewParticleEffect> *m_pParticlePrecipInnerNear; // eax
  CUtlReference<CNewParticleEffect> *v12; // edx
  CUtlReference<CNewParticleEffect> *v13; // edx
  vgui::TreeNode *src; // [esp+Ch] [ebp-4h] BYREF

  this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (CClient_Precipitation_vtbl *)&CClient_Precipitation::`vftable'{for `IClientUnknown'};
  this->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&CClient_Precipitation::`vftable'{for `IClientRenderable'};
  this->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&CClient_Precipitation::`vftable'{for `IClientNetworkable'};
  this->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&CClient_Precipitation::`vftable'{for `IClientThinkable'};
  this->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&CClient_Precipitation::`vftable';
  src = (vgui::TreeNode *)this;
  CUtlVector<C_BaseParticleEntity *,CUtlMemory<C_BaseParticleEntity *,int>>::FindAndRemove(
    this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_Precipitations_1,
    &src);
  if ( s_pSnowFallMgr[0] != nullptr )
  {
    ((void (__thiscall *)(CSnowFallManager *, int))s_pSnowFallMgr[0]->dtr_IHandleEntity)(a1: s_pSnowFallMgr[0], a2: 1);
    s_pSnowFallMgr[0] = nullptr;
  }
  m_pObject = this->m_pParticlePrecipOuter[0].m_pObject;
  m_pParticlePrecipOuter = this->m_pParticlePrecipOuter;
  if ( m_pObject != nullptr )
  {
    m_pPrev = this->m_pParticlePrecipOuter[0].m_pPrev;
    if ( m_pPrev != nullptr )
    {
      m_pPrev->m_pNext = m_pParticlePrecipOuter->m_pNext;
      if ( m_pParticlePrecipOuter->m_pNext != nullptr )
        m_pParticlePrecipOuter->m_pNext->m_pPrev = this->m_pParticlePrecipOuter[0].m_pPrev;
    }
    else if ( m_pObject->m_References.m_pHead == m_pParticlePrecipOuter )
    {
      m_pNext = m_pParticlePrecipOuter->m_pNext;
      m_pObject->m_References.m_pHead = m_pParticlePrecipOuter->m_pNext;
      if ( m_pNext != nullptr )
        m_pNext->m_pPrev = nullptr;
    }
    this->m_pParticlePrecipOuter[0].m_pPrev = nullptr;
    m_pParticlePrecipOuter->m_pNext = nullptr;
    this->m_pParticlePrecipOuter[0].m_pObject = nullptr;
  }
  v6 = this->m_pParticlePrecipInnerFar[0].m_pObject;
  m_pParticlePrecipInnerFar = this->m_pParticlePrecipInnerFar;
  if ( v6 != nullptr )
  {
    v8 = this->m_pParticlePrecipInnerFar[0].m_pPrev;
    if ( v8 != nullptr )
    {
      v8->m_pNext = m_pParticlePrecipInnerFar->m_pNext;
      if ( m_pParticlePrecipInnerFar->m_pNext != nullptr )
        m_pParticlePrecipInnerFar->m_pNext->m_pPrev = this->m_pParticlePrecipInnerFar[0].m_pPrev;
    }
    else if ( v6->m_References.m_pHead == m_pParticlePrecipInnerFar )
    {
      v9 = m_pParticlePrecipInnerFar->m_pNext;
      v6->m_References.m_pHead = m_pParticlePrecipInnerFar->m_pNext;
      if ( v9 != nullptr )
        v9->m_pPrev = nullptr;
    }
    this->m_pParticlePrecipInnerFar[0].m_pPrev = nullptr;
    m_pParticlePrecipInnerFar->m_pNext = nullptr;
    this->m_pParticlePrecipInnerFar[0].m_pObject = nullptr;
  }
  v10 = this->m_pParticlePrecipInnerNear[0].m_pObject;
  m_pParticlePrecipInnerNear = this->m_pParticlePrecipInnerNear;
  if ( v10 != nullptr )
  {
    v12 = this->m_pParticlePrecipInnerNear[0].m_pPrev;
    if ( v12 != nullptr )
    {
      v12->m_pNext = m_pParticlePrecipInnerNear->m_pNext;
      if ( m_pParticlePrecipInnerNear->m_pNext != nullptr )
        m_pParticlePrecipInnerNear->m_pNext->m_pPrev = this->m_pParticlePrecipInnerNear[0].m_pPrev;
    }
    else if ( v10->m_References.m_pHead == m_pParticlePrecipInnerNear )
    {
      v13 = m_pParticlePrecipInnerNear->m_pNext;
      v10->m_References.m_pHead = m_pParticlePrecipInnerNear->m_pNext;
      if ( v13 != nullptr )
        v13->m_pPrev = nullptr;
    }
    this->m_pParticlePrecipInnerNear[0].m_pPrev = nullptr;
    m_pParticlePrecipInnerNear->m_pNext = nullptr;
    this->m_pParticlePrecipInnerNear[0].m_pObject = nullptr;
  }
  if ( this->m_Ash[0].m_pAshEmitter.m_pObj != nullptr )
    CParticleEffect::Release(this: this->m_Ash[0].m_pAshEmitter.m_pObj);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_Splashes);
  CUtlLinkedList<CPrecipitationParticle,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPrecipitationParticle,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_Particles);
  if ( this->m_Particles.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Particles.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Particles.m_Memory.m_pMemory);
      this->m_Particles.m_Memory.m_pMemory = nullptr;
    }
    this->m_Particles.m_Memory.m_nAllocationCount = 0;
  }
  C_BaseEntity::~C_BaseEntity(this);
}

//------------------------------------------------------------------------------
// Address: 0x10241790
// Name: public: CSnowFallManager::CSnowFallManager(void)
// Source: json
//------------------------------------------------------------------------------
CSnowFallManager *__thiscall CSnowFallManager::CSnowFallManager(CSnowFallManager *this)
{
  SnowFallEffect *m_pObj; // ecx

  C_BaseEntity::C_BaseEntity(this);
  this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (CSnowFallManager_vtbl *)&CSnowFallManager::`vftable'{for `IClientUnknown'};
  this->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&CSnowFallManager::`vftable'{for `IClientRenderable'};
  this->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&CSnowFallManager::`vftable'{for `IClientNetworkable'};
  this->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&CSnowFallManager::`vftable'{for `IClientThinkable'};
  this->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&CSnowFallManager::`vftable';
  this->m_tSnowFallParticleTimer.m_TimeBetweenEvents = -1.0;
  this->m_tSnowFallParticleTimer.m_fNextEvent = 0.0;
  this->m_tSnowFallParticleTraceTimer.m_TimeBetweenEvents = -1.0;
  this->m_tSnowFallParticleTraceTimer.m_fNextEvent = 0.0;
  this->m_pSnowFallEmitter.m_pObj = nullptr;
  this->m_aSnow.m_Memory.m_pMemory = nullptr;
  this->m_aSnow.m_Memory.m_nAllocationCount = 0;
  this->m_aSnow.m_Memory.m_nGrowSize = 0;
  this->m_aSnow.m_Size = 0;
  this->m_aSnow.m_pElements = nullptr;
  this->m_iSnowFallArea = 0;
  m_pObj = this->m_pSnowFallEmitter.m_pObj;
  if ( m_pObj != nullptr )
  {
    CParticleEffect::Release(this: m_pObj);
    this->m_pSnowFallEmitter.m_pObj = nullptr;
  }
  this->m_vecSnowFallEmitOrigin.x = 0.0;
  this->m_vecSnowFallEmitOrigin.y = 0.0;
  this->m_vecSnowFallEmitOrigin.z = 0.0;
  this->m_flSnowRadius = 0.0;
  this->m_vecMin.x = 3.4028235e38;
  this->m_vecMin.y = 3.4028235e38;
  this->m_vecMin.z = 3.4028235e38;
  this->m_vecMax.x = 1.1754944e-38;
  this->m_vecMax.y = 1.1754944e-38;
  this->m_vecMax.z = 1.1754944e-38;
  this->m_nActiveSnowCount = 0;
  this->m_aSnow.m_Size = 0;
  if ( this->m_aSnow.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_aSnow.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_aSnow.m_Memory.m_pMemory);
      this->m_aSnow.m_Memory.m_pMemory = nullptr;
    }
    this->m_aSnow.m_Memory.m_nAllocationCount = 0;
  }
  this->m_aSnow.m_pElements = this->m_aSnow.m_Memory.m_pMemory;
  this->m_nSplitScreenPlayerSlot = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102418E0
// Name: public: virtual CSnowFallManager::~CSnowFallManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSnowFallManager::~CSnowFallManager(CSnowFallManager *this)
{
  bool v2; // sf
  SnowFallEffect *m_pObj; // ecx

  this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (CSnowFallManager_vtbl *)&CSnowFallManager::`vftable'{for `IClientUnknown'};
  this->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&CSnowFallManager::`vftable'{for `IClientRenderable'};
  this->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&CSnowFallManager::`vftable'{for `IClientNetworkable'};
  this->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&CSnowFallManager::`vftable'{for `IClientThinkable'};
  this->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&CSnowFallManager::`vftable';
  v2 = this->m_aSnow.m_Memory.m_nGrowSize < 0;
  this->m_aSnow.m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_aSnow.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_aSnow.m_Memory.m_pMemory);
      this->m_aSnow.m_Memory.m_pMemory = nullptr;
    }
    this->m_aSnow.m_Memory.m_nAllocationCount = 0;
  }
  this->m_aSnow.m_pElements = this->m_aSnow.m_Memory.m_pMemory;
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_aSnow);
  m_pObj = this->m_pSnowFallEmitter.m_pObj;
  if ( m_pObj != nullptr )
    CParticleEffect::Release(this: m_pObj);
  C_BaseEntity::~C_BaseEntity(this);
}

//------------------------------------------------------------------------------
// Address: 0x10241980
// Name: public: void CSnowFallManager::AddSnowFallEntity(class CClient_Precipitation __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSnowFallManager::AddSnowFallEntity(CSnowFallManager *this, CClient_Precipitation *pSnowEntity)
{
  int m_Size; // edi
  int v3; // eax
  CClient_Precipitation **p_m_pEntity; // edx
  int v5; // edi
  int m_nAllocationCount; // eax
  CUtlMemory<vgui::SectionedListPanel::section_t,int> *p_m_aSnow; // esi
  vgui::SectionedListPanel::section_t *m_pMemory; // ecx
  int v9; // eax
  int v10; // edi
  CSimpleEmitter *v11; // eax
  vgui::CSectionHeader *v12; // ebx
  vgui::SectionedListPanel::section_t *v13; // ebx
  CParticleMgr *v14; // eax
  float *p_m_Columns; // ebx
  const Vector *v16; // eax
  float *p_m_Size; // ebx
  const Vector *v18; // eax
  float *p_m_iID; // edi
  float v20; // xmm0_4
  float v21; // xmm0_4
  float v22; // xmm0_4
  float v23; // xmm0_4
  float v24; // xmm0_4
  float v25; // xmm0_4

  if ( pSnowEntity != nullptr )
  {
    m_Size = this->m_aSnow.m_Size;
    v3 = 0;
    if ( m_Size > 0 )
    {
      p_m_pEntity = &this->m_aSnow.m_Memory.m_pMemory->m_pEntity;
      do
      {
        if ( *p_m_pEntity == pSnowEntity )
          break;
        ++v3;
        p_m_pEntity += 9;
      }
      while ( v3 < m_Size );
    }
    if ( v3 == m_Size )
    {
      v5 = this->m_aSnow.m_Size;
      m_nAllocationCount = this->m_aSnow.m_Memory.m_nAllocationCount;
      p_m_aSnow = (CUtlMemory<vgui::SectionedListPanel::section_t,int> *)&this->m_aSnow;
      if ( v5 + 1 > m_nAllocationCount )
        CUtlMemory<CSnowFallManager::SnowFall_t,int>::Grow(this: p_m_aSnow, num: v5 - m_nAllocationCount + 1);
      ++p_m_aSnow[1].m_pMemory;
      m_pMemory = p_m_aSnow->m_pMemory;
      v9 = (int)p_m_aSnow[1].m_pMemory - v5 - 1;
      p_m_aSnow[1].m_nAllocationCount = (int)p_m_aSnow->m_pMemory;
      if ( v9 > 0 )
        _V_memmove(dest: (unsigned __int8 *)&m_pMemory[v5 + 1], src: (unsigned __int8 *)&m_pMemory[v5], count: 36 * v9);
      v10 = v5;
      *(_DWORD *)&p_m_aSnow->m_pMemory[v10].m_bAlwaysVisible = pSnowEntity;
      v11 = (CSimpleEmitter *)MemAlloc_Alloc(nSize: 0x108u);
      v12 = (vgui::CSectionHeader *)v11;
      if ( v11 != nullptr )
      {
        CSimpleEmitter::CSimpleEmitter(this: v11, pDebugName: "snowfall");
        v12->__vftable = (vgui::CSectionHeader_vtbl *)&SnowFallEffect::`vftable';
      }
      else
      {
        v12 = nullptr;
      }
      p_m_aSnow->m_pMemory[v10].m_pHeader = v12;
      v13 = p_m_aSnow->m_pMemory;
      v14 = ParticleMgr();
      v13[v10].m_iID = (int)CParticleMgr::GetPMaterial(this: v14, pMaterialName: "particle/snow");
      p_m_Columns = (float *)&p_m_aSnow->m_pMemory[v10].m_Columns;
      v16 = pSnowEntity->WorldAlignMins(this: pSnowEntity);
      *p_m_Columns = v16->x;
      p_m_Columns[1] = v16->y;
      p_m_Columns[2] = v16->z;
      p_m_Size = (float *)&p_m_aSnow->m_pMemory[v10].m_Columns.m_Size;
      v18 = pSnowEntity->WorldAlignMaxs(this: pSnowEntity);
      *p_m_Size = v18->x;
      p_m_Size[1] = v18->y;
      p_m_Size[2] = v18->z;
      p_m_iID = (float *)&p_m_aSnow->m_pMemory[v10].m_iID;
      v20 = p_m_iID[3];
      if ( this->m_vecMin.x > v20 )
        this->m_vecMin.x = v20;
      v21 = p_m_iID[6];
      if ( v21 > this->m_vecMax.x )
        this->m_vecMax.x = v21;
      v22 = p_m_iID[4];
      if ( this->m_vecMin.y > v22 )
        this->m_vecMin.y = v22;
      v23 = p_m_iID[7];
      if ( v23 > this->m_vecMax.y )
        this->m_vecMax.y = v23;
      v24 = p_m_iID[5];
      if ( this->m_vecMin.z > v24 )
        this->m_vecMin.z = v24;
      v25 = p_m_iID[8];
      if ( v25 > this->m_vecMax.z )
        this->m_vecMax.z = v25;
      CParticleEffectBinding::SetBBox(
        this: &this->m_pSnowFallEmitter.m_pObj->m_ParticleEffect,
        bbMin: &this->m_vecMin,
        bbMax: &this->m_vecMax,
        bDisableAutoUpdate: true);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10241B70
// Name: private: void CSnowFallManager::CreateSnowFallParticles(float,float,class Vector const __near &,class Vector const __near &,float,class C_BasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSnowFallManager::CreateSnowFallParticles(
        CSnowFallManager *this,
        float flCurrentTime,
        float flRadius,
        const Vector *vecEyePos,
        const Vector *vecForward,
        float flZoomScale,
        C_BasePlayer *pLocalPlayer)
{
  CClient_Precipitation *m_pEntity; // edi
  int RenderAlpha; // eax

  if ( this->m_nActiveSnowCount <= 0 )
    goto LABEL_7;
  m_pEntity = this->m_aSnow.m_Memory.m_pMemory[this->m_aActiveSnow[0]].m_pEntity;
  RenderAlpha = C_BaseEntity::GetRenderAlpha(this: m_pEntity);
  if ( (unsigned __int8)RenderAlpha > 0x64u )
    RenderAlpha = 100;
  if ( m_pEntity != nullptr && RenderAlpha > 0 )
    this->m_tSnowFallParticleTimer.m_TimeBetweenEvents = 1.0
                                                       / (float)((float)((float)RenderAlpha * 500.0) * 0.0099999998);
  else
LABEL_7:
    this->m_tSnowFallParticleTimer.m_TimeBetweenEvents = 0.0020000001;
  if ( this->m_iSnowFallArea == 2 )
    CSnowFallManager::CreateOutsideVolumeSnowParticles(this, flCurrentTime, flRadius, flZoomScale, pLocalPlayer);
  else
    CSnowFallManager::CreateInsideVolumeSnowParticles(
      this,
      flCurrentTime,
      flRadius,
      vecEyePos,
      vecForward,
      flZoomScale,
      pLocalPlayer);
}

//------------------------------------------------------------------------------
// Address: 0x10241C70
// Name: bool SnowFallManagerCreate(class CClient_Precipitation __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SnowFallManagerCreate(CClient_Precipitation *pSnowEntity)
{
  int v1; // esi
  CSnowFallManager *v2; // eax
  CSnowFallManager *v3; // eax
  IClientLeafSystem_vtbl *v4; // edi
  unsigned __int16 *v5; // eax

  v1 = 0;
  while ( s_pSnowFallMgr[v1] != nullptr )
  {
LABEL_8:
    CSnowFallManager::AddSnowFallEntity(this: s_pSnowFallMgr[v1++], pSnowEntity);
    if ( v1 >= 1 )
      return 1;
  }
  v2 = (CSnowFallManager *)C_BaseEntity::operator new(stAllocateBlock: 0xA60u);
  if ( v2 != nullptr )
    v3 = CSnowFallManager::CSnowFallManager(this: v2);
  else
    v3 = nullptr;
  s_pSnowFallMgr[v1] = v3;
  if ( v3 != nullptr )
  {
    v3->m_nSplitScreenPlayerSlot = v1;
    CSnowFallManager::CreateSnowFallEmitter(this: s_pSnowFallMgr[v1]);
    s_pSnowFallMgr[v1]->InitializeAsClientEntity(this: s_pSnowFallMgr[v1], a2: nullptr, a3: false);
    v4 = g_pClientLeafSystem->IClientLeafSystemEngine::__vftable;
    v5 = s_pSnowFallMgr[v1]->RenderHandle(this: &s_pSnowFallMgr[v1]->IClientRenderable);
    v4->EnableRendering(this: g_pClientLeafSystem, a2: *v5, a3: false);
    goto LABEL_8;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10241DB0
// Name: private: virtual void CClient_Precipitation::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClient_Precipitation::OnDataChanged(CClient_Precipitation *this, DataUpdateType_t updateType)
{
  if ( updateType == DATA_UPDATE_CREATED )
  {
    (*(void (__thiscall **)(char *, int))(*((_DWORD *)this - 2) + 456))(a1: (char *)this - 8, a2: -996040704);
    if ( LODWORD(this->m_Width) == 3 )
      SnowFallManagerCreate(pSnowEntity: (CClient_Precipitation *)((char *)this - 8));
  }
  *(float *)&this->m_nPrecipType = (float)C_BaseEntity::GetRenderAlpha(this: (CClient_Precipitation *)((char *)this - 8))
                                 * 0.0099999998;
  C_BaseEntity::OnDataChanged(this, type: updateType);
}

//------------------------------------------------------------------------------
// Address: 0x10241E20
// Name: private: bool CClient_Precipitation::SimulateRain(class CPrecipitationParticle __near *,float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CClient_Precipitation::SimulateRain(
        CClient_Precipitation *this,
        CPrecipitationParticle *pParticle,
        float dt)
{
  float x; // xmm2_4
  float z; // ecx
  float m_fValue; // xmm0_4
  float v7; // xmm0_4
  float v8; // xmm2_4
  bool v9; // cc
  float y; // xmm0_4
  bool v11; // cc
  IUniformRandomStream *v12; // ecx
  int m_nValue; // edi
  CGameTrace trace; // [esp+0h] [ebp-60h] BYREF
  Vector vOldPos; // [esp+54h] [ebp-Ch] BYREF
  IHandleEntity savedregs; // [esp+60h] [ebp+0h] BYREF

  if ( (float)(pParticle->m_flMaxLifetime - (float)(*(float *)(gpGlobals.m_Index + 12) - pParticle->m_SpawnTime)) < 0.0 )
    return 0;
  x = pParticle->m_Velocity.x;
  z = pParticle->m_Pos.z;
  *(_QWORD *)&vOldPos.x = *(_QWORD *)&pParticle->m_Pos.x;
  pParticle->m_Pos.x = (float)(x * dt) + pParticle->m_Pos.x;
  pParticle->m_Pos.y = (float)(pParticle->m_Velocity.y * dt) + pParticle->m_Pos.y;
  pParticle->m_Pos.z = (float)(pParticle->m_Velocity.z * dt) + pParticle->m_Pos.z;
  m_fValue = cl_windspeed.m_pParent->m_Value.m_fValue;
  vOldPos.z = z;
  if ( m_fValue > 0.0 )
  {
    v7 = pParticle->m_Velocity.x;
    v8 = 5.0 / pParticle->m_Mass;
    if ( CClient_Precipitation::s_WindVector.x <= v7 )
    {
      if ( v7 <= CClient_Precipitation::s_WindVector.x )
        goto LABEL_9;
      v7 = v7 - v8;
      v9 = v7 <= CClient_Precipitation::s_WindVector.x;
    }
    else
    {
      v7 = v7 + v8;
      v9 = CClient_Precipitation::s_WindVector.x <= v7;
    }
    if ( v9 )
      v7 = CClient_Precipitation::s_WindVector.x;
LABEL_9:
    pParticle->m_Velocity.x = v7;
    y = pParticle->m_Velocity.y;
    if ( CClient_Precipitation::s_WindVector.y <= y )
    {
      if ( y <= CClient_Precipitation::s_WindVector.y )
      {
LABEL_15:
        pParticle->m_Velocity.y = y;
        goto LABEL_16;
      }
      y = y - v8;
      v11 = y <= CClient_Precipitation::s_WindVector.y;
    }
    else
    {
      y = y + v8;
      v11 = CClient_Precipitation::s_WindVector.y <= y;
    }
    if ( v11 )
      y = CClient_Precipitation::s_WindVector.y;
    goto LABEL_15;
  }
LABEL_16:
  if ( r_RainCheck.m_pParent != nullptr
    && r_RainCheck.m_pParent->m_Value.m_nValue != 0
    && (((int (__thiscall *)(IEngineTrace *))enginetrace->GetPointContents)(a1: enginetrace) & 1) != 0 )
  {
    if ( this->m_Splashes.m_Size < 20 )
    {
      if ( r_RainSplashPercentage.m_pParent != nullptr )
        m_nValue = r_RainSplashPercentage.m_pParent->m_Value.m_nValue;
      else
        m_nValue = 0;
      if ( _RandomInt(this: v12, a2: 0, a3: 100) < m_nValue )
      {
        UTIL_TraceLine(
          a1: &savedregs,
          a2: (int)pParticle,
          vecAbsStart: &vOldPos,
          vecAbsEnd: &pParticle->m_Pos,
          mask: 0x4030u,
          ignore: nullptr,
          collisionGroup: 0,
          ptr: &trace);
        if ( trace.fraction < 1.0 )
          CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
            this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&this->m_Splashes,
            elem: this->m_Splashes.m_Size,
            src: (const QAngle *)&trace.endpos);
      }
    }
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10241FD0
// Name: public: CClient_Precipitation::CClient_Precipitation(void)
// Source: json
//------------------------------------------------------------------------------
CClient_Precipitation *__thiscall CClient_Precipitation::CClient_Precipitation(CClient_Precipitation *this)
{
  CUtlReference<CNewParticleEffect> *m_pParticlePrecipInnerNear; // eax
  CUtlReference<CNewParticleEffect> *m_pParticlePrecipInnerFar; // ecx
  CNewParticleEffect *m_pObject; // edx
  CUtlReference<CNewParticleEffect> *m_pPrev; // edi
  CUtlReference<CNewParticleEffect> *m_pNext; // edi
  CNewParticleEffect *v7; // edx
  CUtlReference<CNewParticleEffect> *v8; // eax
  CUtlReference<CNewParticleEffect> *v9; // eax
  CNewParticleEffect *v10; // edx
  CUtlReference<CNewParticleEffect> *m_pParticlePrecipOuter; // eax
  CUtlReference<CNewParticleEffect> *v12; // ecx
  CUtlReference<CNewParticleEffect> *v13; // ecx
  int m_Size; // eax
  int v15; // edi
  CClient_Precipitation **m_pMemory; // ecx
  int v17; // eax
  CClient_Precipitation **v18; // eax

  C_BaseEntity::C_BaseEntity(this);
  this->m_Remainder = 0.0;
  this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (CClient_Precipitation_vtbl *)&CClient_Precipitation::`vftable'{for `IClientUnknown'};
  this->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&CClient_Precipitation::`vftable'{for `IClientRenderable'};
  this->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&CClient_Precipitation::`vftable'{for `IClientNetworkable'};
  this->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&CClient_Precipitation::`vftable'{for `IClientThinkable'};
  this->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&CClient_Precipitation::`vftable';
  this->m_Particles.m_Memory.m_pMemory = nullptr;
  this->m_Particles.m_Memory.m_nAllocationCount = 0;
  this->m_Particles.m_Memory.m_nGrowSize = 0;
  this->m_Particles.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_Particles.m_FirstFree = 0xFFFF;
  this->m_Particles.m_pElements = this->m_Particles.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_Particles.m_Head = -1;
  this->m_Particles.m_NumAlloced = 0;
  this->m_Splashes.m_Memory.m_pMemory = nullptr;
  this->m_Splashes.m_Memory.m_nAllocationCount = 0;
  this->m_Splashes.m_Memory.m_nGrowSize = 0;
  this->m_Splashes.m_Size = 0;
  this->m_Splashes.m_pElements = nullptr;
  this->m_Ash[0].m_pAshEmitter.m_pObj = nullptr;
  this->m_Ash[0].m_tAshParticleTimer = (TimedEvent)3212836864LL;
  this->m_Ash[0].m_tAshParticleTraceTimer = (TimedEvent)3212836864LL;
  this->m_Ash[0].m_bActiveAshEmitter = false;
  this->m_Ash[0].m_vAshSpawnOrigin.x = 0.0;
  this->m_Ash[0].m_vAshSpawnOrigin.y = 0.0;
  this->m_Ash[0].m_vAshSpawnOrigin.z = 0.0;
  this->m_Ash[0].m_iAshCount = 0;
  this->m_pParticlePrecipInnerNear[0].m_pPrev = nullptr;
  this->m_pParticlePrecipInnerNear[0].m_pNext = nullptr;
  this->m_pParticlePrecipInnerNear[0].m_pObject = nullptr;
  m_pParticlePrecipInnerNear = this->m_pParticlePrecipInnerNear;
  this->m_pParticlePrecipInnerFar[0].m_pPrev = nullptr;
  this->m_pParticlePrecipInnerFar[0].m_pNext = nullptr;
  this->m_pParticlePrecipInnerFar[0].m_pObject = nullptr;
  m_pParticlePrecipInnerFar = this->m_pParticlePrecipInnerFar;
  this->m_tParticlePrecipTraceTimer[0].m_fNextEvent = 0.0;
  this->m_pParticlePrecipOuter[0].m_pPrev = nullptr;
  this->m_pParticlePrecipOuter[0].m_pNext = nullptr;
  this->m_pParticlePrecipOuter[0].m_pObject = nullptr;
  this->m_tParticlePrecipTraceTimer[0].m_TimeBetweenEvents = -1.0;
  this->m_nPrecipType = PRECIPITATION_TYPE_RAIN;
  this->m_MatHandle = nullptr;
  this->m_flHalfScreenWidth = 1.0;
  m_pObject = this->m_pParticlePrecipInnerNear[0].m_pObject;
  if ( m_pObject != nullptr )
  {
    m_pPrev = this->m_pParticlePrecipInnerNear[0].m_pPrev;
    if ( m_pPrev != nullptr )
    {
      m_pPrev->m_pNext = m_pParticlePrecipInnerNear->m_pNext;
      if ( m_pParticlePrecipInnerNear->m_pNext != nullptr )
        m_pParticlePrecipInnerNear->m_pNext->m_pPrev = this->m_pParticlePrecipInnerNear[0].m_pPrev;
    }
    else if ( m_pObject->m_References.m_pHead == m_pParticlePrecipInnerNear )
    {
      m_pNext = m_pParticlePrecipInnerNear->m_pNext;
      m_pObject->m_References.m_pHead = m_pParticlePrecipInnerNear->m_pNext;
      if ( m_pNext != nullptr )
        m_pNext->m_pPrev = nullptr;
    }
    this->m_pParticlePrecipInnerNear[0].m_pPrev = nullptr;
    m_pParticlePrecipInnerNear->m_pNext = nullptr;
    this->m_pParticlePrecipInnerNear[0].m_pObject = nullptr;
  }
  v7 = this->m_pParticlePrecipInnerFar[0].m_pObject;
  if ( v7 != nullptr )
  {
    v8 = this->m_pParticlePrecipInnerFar[0].m_pPrev;
    if ( v8 != nullptr )
    {
      v8->m_pNext = m_pParticlePrecipInnerFar->m_pNext;
      if ( m_pParticlePrecipInnerFar->m_pNext != nullptr )
        m_pParticlePrecipInnerFar->m_pNext->m_pPrev = this->m_pParticlePrecipInnerFar[0].m_pPrev;
    }
    else if ( v7->m_References.m_pHead == m_pParticlePrecipInnerFar )
    {
      v9 = m_pParticlePrecipInnerFar->m_pNext;
      v7->m_References.m_pHead = m_pParticlePrecipInnerFar->m_pNext;
      if ( v9 != nullptr )
        v9->m_pPrev = nullptr;
    }
    this->m_pParticlePrecipInnerFar[0].m_pPrev = nullptr;
    m_pParticlePrecipInnerFar->m_pNext = nullptr;
    this->m_pParticlePrecipInnerFar[0].m_pObject = nullptr;
  }
  v10 = this->m_pParticlePrecipOuter[0].m_pObject;
  m_pParticlePrecipOuter = this->m_pParticlePrecipOuter;
  if ( v10 != nullptr )
  {
    v12 = this->m_pParticlePrecipOuter[0].m_pPrev;
    if ( v12 != nullptr )
    {
      v12->m_pNext = m_pParticlePrecipOuter->m_pNext;
      if ( m_pParticlePrecipOuter->m_pNext != nullptr )
        m_pParticlePrecipOuter->m_pNext->m_pPrev = this->m_pParticlePrecipOuter[0].m_pPrev;
    }
    else if ( v10->m_References.m_pHead == m_pParticlePrecipOuter )
    {
      v13 = m_pParticlePrecipOuter->m_pNext;
      v10->m_References.m_pHead = m_pParticlePrecipOuter->m_pNext;
      if ( v13 != nullptr )
        v13->m_pPrev = nullptr;
    }
    this->m_pParticlePrecipOuter[0].m_pPrev = nullptr;
    m_pParticlePrecipOuter->m_pNext = nullptr;
    this->m_pParticlePrecipOuter[0].m_pObject = nullptr;
  }
  this->m_bActiveParticlePrecipEmitter[0] = false;
  m_Size = g_Precipitations_1.m_Size;
  v15 = g_Precipitations_1.m_Size;
  if ( g_Precipitations_1.m_Size + 1 > g_Precipitations_1.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<CChoreoActor *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&g_Precipitations_1,
      num: g_Precipitations_1.m_Size - g_Precipitations_1.m_Memory.m_nAllocationCount + 1);
    m_Size = g_Precipitations_1.m_Size;
  }
  m_pMemory = g_Precipitations_1.m_Memory.m_pMemory;
  g_Precipitations_1.m_Size = m_Size + 1;
  v17 = m_Size - v15;
  g_Precipitations_1.m_pElements = g_Precipitations_1.m_Memory.m_pMemory;
  if ( v17 > 0 )
  {
    _V_memmove(
      dest: (unsigned __int8 *)&g_Precipitations_1.m_Memory.m_pMemory[v15 + 1],
      src: (unsigned __int8 *)&g_Precipitations_1.m_Memory.m_pMemory[v15],
      count: 4 * v17);
    m_pMemory = g_Precipitations_1.m_Memory.m_pMemory;
  }
  v18 = &m_pMemory[v15];
  if ( v18 != nullptr )
    *v18 = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10242290
// Name: private: void CClient_Precipitation::DestroyInnerParticlePrecip(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClient_Precipitation::DestroyInnerParticlePrecip(CClient_Precipitation *this, int nSlot)
{
  char *v2; // esi
  CNewParticleEffect *v3; // ecx
  CUtlIntrusiveDList<CUtlReference<CSheet> > *v4; // eax
  CNewParticleEffect *v5; // ecx
  CUtlIntrusiveDList<CUtlReference<CSheet> > *v6; // eax
  CUtlReference<CSheet> *v7; // esi

  v2 = (char *)this + 12 * nSlot;
  v3 = *((CNewParticleEffect **)v2 + 652);
  if ( v3 != nullptr )
  {
    CNewParticleEffect::StopEmission(
      this: v3,
      bInfiniteOnly: false,
      bRemoveAllParticles: false,
      bWakeOnStop: false,
      bPlayEndCap: false);
    v4 = *((CUtlIntrusiveDList<CUtlReference<CSheet> > **)v2 + 652);
    if ( v4 != nullptr )
    {
      CUtlIntrusiveDList<CUtlReference<CNewParticleEffect>>::RemoveNode(
        this: v4 + 232,
        which: (CUtlReference<CSheet> *)(v2 + 2600));
      *((_DWORD *)v2 + 652) = 0;
    }
  }
  v5 = *((CNewParticleEffect **)v2 + 649);
  if ( v5 != nullptr )
  {
    CNewParticleEffect::StopEmission(
      this: v5,
      bInfiniteOnly: false,
      bRemoveAllParticles: false,
      bWakeOnStop: false,
      bPlayEndCap: false);
    v6 = *((CUtlIntrusiveDList<CUtlReference<CSheet> > **)v2 + 649);
    v7 = (CUtlReference<CSheet> *)(v2 + 2588);
    if ( v6 != nullptr )
    {
      CUtlIntrusiveDList<CUtlReference<CNewParticleEffect>>::RemoveNode(this: v6 + 232, which: v7);
      v7->m_pObject = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10242320
// Name: private: void CClient_Precipitation::DispatchOuterParticlePrecip(int,class C_BasePlayer __near *,class Vector)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClient_Precipitation::DispatchOuterParticlePrecip(
        CClient_Precipitation *this,
        int nSlot,
        C_BasePlayer *pPlayer,
        Vector vForward)
{
  CNewParticleEffect *m_pObject; // ecx
  char *v6; // ebx
  CUtlIntrusiveDList<CUtlReference<CSheet> > *v7; // eax
  float m_flDensity; // xmm0_4
  Vector *(__thiscall *EyePosition)(C_BaseEntity *, Vector *); // edx
  CNewParticleEffect *v10; // edi
  CUtlIntrusiveDList<CUtlReference<CSheet> > *v11; // eax
  CUtlReference<CNewParticleEffect> *v12; // esi
  CUtlReference<CNewParticleEffect> *m_pHead; // eax
  CNewParticleEffect *v14; // ecx
  Vector vDensity; // [esp+Ch] [ebp-24h] BYREF
  Vector v; // [esp+18h] [ebp-18h] BYREF
  Vector vPlayerPos; // [esp+24h] [ebp-Ch] BYREF

  m_pObject = this->m_pParticlePrecipOuter[nSlot].m_pObject;
  v6 = (char *)this + 12 * nSlot;
  if ( m_pObject != nullptr )
  {
    CNewParticleEffect::StopEmission(
      this: m_pObject,
      bInfiniteOnly: false,
      bRemoveAllParticles: false,
      bWakeOnStop: false,
      bPlayEndCap: false);
    v7 = *((CUtlIntrusiveDList<CUtlReference<CSheet> > **)v6 + 655);
    if ( v7 != nullptr )
    {
      CUtlIntrusiveDList<CUtlReference<CNewParticleEffect>>::RemoveNode(
        this: v7 + 232,
        which: (CUtlReference<CSheet> *)(v6 + 2612));
      *((_DWORD *)v6 + 655) = 0;
    }
  }
  m_flDensity = this->m_flDensity;
  EyePosition = pPlayer->EyePosition;
  vDensity.x = r_RainParticleDensity.m_pParent->m_Value.m_fValue * m_flDensity;
  vDensity.y = m_flDensity * 0.0;
  vDensity.z = m_flDensity * 0.0;
  EyePosition(this: pPlayer, result: &vPlayerPos);
  v10 = CParticleProperty::Create(
          this: &this->C_BaseEntity::m_Particles,
          pszParticleName: this->m_pParticleOuterDef,
          iAttachType: PATTACH_ABSORIGIN_FOLLOW,
          iAttachmentPoint: -1,
          vecOriginOffset: vec3_origin,
          matOffset: nullptr);
  v11 = *((CUtlIntrusiveDList<CUtlReference<CSheet> > **)v6 + 655);
  v12 = (CUtlReference<CNewParticleEffect> *)(v6 + 2612);
  if ( v11 != (CUtlIntrusiveDList<CUtlReference<CSheet> > *)v10 )
  {
    if ( v11 != nullptr )
    {
      CUtlIntrusiveDList<CUtlReference<CNewParticleEffect>>::RemoveNode(
        this: v11 + 232,
        which: (CUtlReference<CSheet> *)(v6 + 2612));
      *((_DWORD *)v6 + 655) = 0;
    }
    *((_DWORD *)v6 + 655) = v10;
    if ( v10 != nullptr )
    {
      v12->m_pNext = v10->m_References.m_pHead;
      m_pHead = v10->m_References.m_pHead;
      if ( m_pHead != nullptr )
        m_pHead->m_pPrev = v12;
      *((_DWORD *)v6 + 654) = 0;
      v10->m_References.m_pHead = v12;
    }
  }
  CNewParticleEffect::SetControlPointEntity(this: *((CNewParticleEffect **)v6 + 655), nWhichPoint: 2, pEntity: pPlayer);
  v14 = *((CNewParticleEffect **)v6 + 655);
  v.x = vPlayerPos.x;
  v.y = vPlayerPos.y;
  v.z = vPlayerPos.z + 180.0;
  CNewParticleEffect::SetControlPoint(this: v14, nWhichPoint: 1, &v);
  CNewParticleEffect::SetControlPoint(this: *((CNewParticleEffect **)v6 + 655), nWhichPoint: 3, v: &vDensity);
  CNewParticleEffect::SetDrawOnlyForSplitScreenUser(this: *((CNewParticleEffect **)v6 + 655), nSlot);
}

//------------------------------------------------------------------------------
// Address: 0x102424B0
// Name: private: void CClient_Precipitation::DispatchInnerParticlePrecip(int,class C_BasePlayer __near *,class Vector)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClient_Precipitation::DispatchInnerParticlePrecip(
        CClient_Precipitation *this,
        int nSlot,
        C_BasePlayer *pPlayer,
        Vector vForward)
{
  CNewParticleEffect *m_pObject; // ecx
  char *v6; // esi
  CUtlIntrusiveDList<CUtlReference<CSheet> > *v7; // eax
  float m_flParticleInnerDist; // xmm4_4
  float m_flDensity; // xmm0_4
  float v10; // xmm1_4
  CNewParticleEffect *v11; // eax
  CUtlIntrusiveDList<CUtlReference<CSheet> > *v12; // ecx
  CUtlReference<CNewParticleEffect> *v13; // ebx
  CUtlReference<CNewParticleEffect> *m_pHead; // ecx
  CNewParticleEffect *v15; // eax
  CUtlIntrusiveDList<CUtlReference<CSheet> > *v16; // ecx
  CUtlReference<CNewParticleEffect> *v17; // ebx
  CUtlReference<CNewParticleEffect> *v18; // ecx
  CNewParticleEffect *v19; // ebx
  CUtlIntrusiveDList<CUtlReference<CSheet> > *v20; // eax
  CUtlReference<CNewParticleEffect> *v21; // edi
  CUtlReference<CNewParticleEffect> *v22; // eax
  char *m_pParticleOuterDef; // [esp-1Ch] [ebp-84h]
  char *m_pParticleInnerNearDef; // [esp-1Ch] [ebp-84h]
  Vector vOffsetPosFar; // [esp+18h] [ebp-50h] BYREF
  Vector vOffsetPosNear; // [esp+24h] [ebp-44h] BYREF
  Vector vOffsetPos; // [esp+30h] [ebp-38h] BYREF
  Vector vPlayerPos; // [esp+3Ch] [ebp-2Ch] BYREF
  Vector vDensity; // [esp+48h] [ebp-20h] BYREF
  float x; // [esp+54h] [ebp-14h]
  float y; // [esp+58h] [ebp-10h]
  float v32; // [esp+5Ch] [ebp-Ch]
  CParticleProperty *p_m_Particles; // [esp+60h] [ebp-8h]
  CNewParticleEffect *v34; // [esp+64h] [ebp-4h]

  CClient_Precipitation::DestroyInnerParticlePrecip(this, nSlot);
  m_pObject = this->m_pParticlePrecipOuter[nSlot].m_pObject;
  v6 = (char *)this + 12 * nSlot;
  if ( m_pObject != nullptr )
  {
    CNewParticleEffect::StopEmission(
      this: m_pObject,
      bInfiniteOnly: false,
      bRemoveAllParticles: false,
      bWakeOnStop: false,
      bPlayEndCap: false);
    v7 = *((CUtlIntrusiveDList<CUtlReference<CSheet> > **)v6 + 655);
    if ( v7 != nullptr )
    {
      CUtlIntrusiveDList<CUtlReference<CNewParticleEffect>>::RemoveNode(
        this: v7 + 232,
        which: (CUtlReference<CSheet> *)(v6 + 2612));
      *((_DWORD *)v6 + 655) = 0;
    }
  }
  pPlayer->EyePosition(this: pPlayer, result: &vPlayerPos);
  vOffsetPosNear.y = vPlayerPos.y + (float)(vForward.y * 32.0);
  vOffsetPos.z = vPlayerPos.z + 180.0;
  v32 = vPlayerPos.z + 180.0;
  vOffsetPosNear.z = (float)(vPlayerPos.z + 180.0) + (float)(vForward.z * 32.0);
  m_flParticleInnerDist = this->m_flParticleInnerDist;
  vOffsetPos.x = vPlayerPos.x;
  x = vPlayerPos.x;
  vOffsetPos.y = vPlayerPos.y;
  y = vPlayerPos.y;
  vOffsetPosFar.z = (float)(vPlayerPos.z + 180.0) + (float)(vForward.z * m_flParticleInnerDist);
  m_flDensity = this->m_flDensity;
  vOffsetPosFar.x = vPlayerPos.x + (float)(vForward.x * m_flParticleInnerDist);
  vOffsetPosNear.x = vPlayerPos.x + (float)(vForward.x * 32.0);
  vOffsetPosFar.y = vPlayerPos.y + (float)(vForward.y * m_flParticleInnerDist);
  v10 = r_RainParticleDensity.m_pParent->m_Value.m_fValue * m_flDensity;
  vDensity.y = m_flDensity * 0.0;
  vDensity.z = m_flDensity * 0.0;
  m_pParticleOuterDef = this->m_pParticleOuterDef;
  vDensity.x = v10;
  v11 = CParticleProperty::Create(
          this: &this->C_BaseEntity::m_Particles,
          pszParticleName: m_pParticleOuterDef,
          iAttachType: PATTACH_ABSORIGIN_FOLLOW,
          iAttachmentPoint: -1,
          vecOriginOffset: vec3_origin,
          matOffset: nullptr);
  v12 = *((CUtlIntrusiveDList<CUtlReference<CSheet> > **)v6 + 655);
  v13 = (CUtlReference<CNewParticleEffect> *)(v6 + 2612);
  v34 = v11;
  if ( v12 != (CUtlIntrusiveDList<CUtlReference<CSheet> > *)v11 )
  {
    if ( v12 != nullptr )
    {
      CUtlIntrusiveDList<CUtlReference<CNewParticleEffect>>::RemoveNode(
        this: v12 + 232,
        which: (CUtlReference<CSheet> *)(v6 + 2612));
      v11 = v34;
      *((_DWORD *)v6 + 655) = 0;
    }
    *((_DWORD *)v6 + 655) = v11;
    if ( v11 != nullptr )
    {
      v13->m_pNext = v11->m_References.m_pHead;
      m_pHead = v11->m_References.m_pHead;
      if ( m_pHead != nullptr )
        m_pHead->m_pPrev = v13;
      *((_DWORD *)v6 + 654) = 0;
      v11->m_References.m_pHead = v13;
    }
  }
  m_pParticleInnerNearDef = this->m_pParticleInnerNearDef;
  p_m_Particles = &this->C_BaseEntity::m_Particles;
  v15 = CParticleProperty::Create(
          this: &this->C_BaseEntity::m_Particles,
          pszParticleName: m_pParticleInnerNearDef,
          iAttachType: PATTACH_ABSORIGIN_FOLLOW,
          iAttachmentPoint: -1,
          vecOriginOffset: vec3_origin,
          matOffset: nullptr);
  v16 = *((CUtlIntrusiveDList<CUtlReference<CSheet> > **)v6 + 649);
  v17 = (CUtlReference<CNewParticleEffect> *)(v6 + 2588);
  v34 = v15;
  if ( v16 != (CUtlIntrusiveDList<CUtlReference<CSheet> > *)v15 )
  {
    if ( v16 != nullptr )
    {
      CUtlIntrusiveDList<CUtlReference<CNewParticleEffect>>::RemoveNode(
        this: v16 + 232,
        which: (CUtlReference<CSheet> *)(v6 + 2588));
      v15 = v34;
      *((_DWORD *)v6 + 649) = 0;
    }
    *((_DWORD *)v6 + 649) = v15;
    if ( v15 != nullptr )
    {
      v17->m_pNext = v15->m_References.m_pHead;
      v18 = v15->m_References.m_pHead;
      if ( v18 != nullptr )
        v18->m_pPrev = v17;
      *((_DWORD *)v6 + 648) = 0;
      v15->m_References.m_pHead = v17;
    }
  }
  v19 = CParticleProperty::Create(
          this: p_m_Particles,
          pszParticleName: this->m_pParticleInnerFarDef,
          iAttachType: PATTACH_ABSORIGIN_FOLLOW,
          iAttachmentPoint: -1,
          vecOriginOffset: vec3_origin,
          matOffset: nullptr);
  v20 = *((CUtlIntrusiveDList<CUtlReference<CSheet> > **)v6 + 652);
  v21 = (CUtlReference<CNewParticleEffect> *)(v6 + 2600);
  if ( v20 != (CUtlIntrusiveDList<CUtlReference<CSheet> > *)v19 )
  {
    if ( v20 != nullptr )
    {
      CUtlIntrusiveDList<CUtlReference<CNewParticleEffect>>::RemoveNode(
        this: v20 + 232,
        which: (CUtlReference<CSheet> *)(v6 + 2600));
      *((_DWORD *)v6 + 652) = 0;
    }
    *((_DWORD *)v6 + 652) = v19;
    if ( v19 != nullptr )
    {
      v21->m_pNext = v19->m_References.m_pHead;
      v22 = v19->m_References.m_pHead;
      if ( v22 != nullptr )
        v22->m_pPrev = v21;
      *((_DWORD *)v6 + 651) = 0;
      v19->m_References.m_pHead = v21;
    }
  }
  CNewParticleEffect::SetControlPointEntity(this: *((CNewParticleEffect **)v6 + 655), nWhichPoint: 2, pEntity: pPlayer);
  CNewParticleEffect::SetControlPointEntity(this: *((CNewParticleEffect **)v6 + 649), nWhichPoint: 2, pEntity: pPlayer);
  CNewParticleEffect::SetControlPointEntity(this: *((CNewParticleEffect **)v6 + 652), nWhichPoint: 2, pEntity: pPlayer);
  CNewParticleEffect::SetControlPoint(this: *((CNewParticleEffect **)v6 + 655), nWhichPoint: 1, v: &vOffsetPos);
  CNewParticleEffect::SetControlPoint(this: *((CNewParticleEffect **)v6 + 649), nWhichPoint: 1, v: &vOffsetPosNear);
  CNewParticleEffect::SetControlPoint(this: *((CNewParticleEffect **)v6 + 652), nWhichPoint: 1, v: &vOffsetPosFar);
  CNewParticleEffect::SetControlPoint(this: *((CNewParticleEffect **)v6 + 649), nWhichPoint: 3, v: &vDensity);
  CNewParticleEffect::SetControlPoint(this: *((CNewParticleEffect **)v6 + 652), nWhichPoint: 3, v: &vDensity);
  CNewParticleEffect::SetControlPoint(this: *((CNewParticleEffect **)v6 + 655), nWhichPoint: 3, v: &vDensity);
  CNewParticleEffect::SetDrawOnlyForSplitScreenUser(this: *((CNewParticleEffect **)v6 + 655), nSlot);
  CNewParticleEffect::SetDrawOnlyForSplitScreenUser(this: *((CNewParticleEffect **)v6 + 649), nSlot);
  CNewParticleEffect::SetDrawOnlyForSplitScreenUser(this: *((CNewParticleEffect **)v6 + 652), nSlot);
}

//------------------------------------------------------------------------------
// Address: 0x10242860
// Name: public: virtual void CPrecipHack::LevelInitPostEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrecipHack::LevelInitPostEntity(CPrecipHack *this)
{
  CClient_Precipitation *v2; // eax
  CClient_Precipitation *v3; // esi

  if ( r_RainHack.m_pParent != nullptr && r_RainHack.m_pParent->m_Value.m_nValue != 0 )
  {
    v2 = (CClient_Precipitation *)C_BaseEntity::operator new(stAllocateBlock: 0xA50u);
    if ( v2 != nullptr )
      v3 = CClient_Precipitation::CClient_Precipitation(this: v2);
    else
      v3 = nullptr;
    v3->InitializeAsClientEntity(this: v3, a2: nullptr, a3: false);
    g_pPrecipHackEnt.m_Index = v3->GetRefEHandle(this: v3)->m_Index;
  }
  this->m_bLevelInitted = true;
}

//------------------------------------------------------------------------------
// Address: 0x102428F0
// Name: private: void CSnowFallManager::CreateSnowFall(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CSnowFallManager::CreateSnowFall(CSnowFallManager *this@<ecx>, int a2@<esi>)
{
  C_BasePlayer *LocalPlayer; // eax
  C_BasePlayer *v4; // edi
  Vector *(__thiscall *EyePosition)(C_BaseEntity *, Vector *); // edx
  float *v6; // eax
  float v7; // xmm0_4
  float z; // xmm3_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm0_4
  float x; // xmm1_4
  float y; // xmm2_4
  float v14; // xmm0_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  double v17; // st7
  float v18; // eax
  C_BasePlayer_vtbl *v19; // edx
  double v20; // st7
  float (__thiscall *GetFOV)(C_BasePlayer *); // eax
  double v22; // st7
  float m_fNextEvent; // xmm0_4
  float v24; // xmm1_4
  Vector *(__thiscall *v25)(C_BaseEntity *, Vector *); // edx
  float m_flSnowRadius; // xmm0_4
  const Vector *v27; // eax
  const Vector *v28; // eax
  float v29; // [esp+34h] [ebp-58h]
  Vector v30; // [esp+48h] [ebp-44h] BYREF
  Vector vecTraceStart; // [esp+54h] [ebp-38h] BYREF
  Vector vecVelocity; // [esp+60h] [ebp-2Ch] BYREF
  Vector vecForward; // [esp+6Ch] [ebp-20h] BYREF
  float v34; // [esp+78h] [ebp-14h]
  float flCurrentTime; // [esp+7Ch] [ebp-10h]
  float flRadius; // [esp+80h] [ebp-Ch]
  float flZoomScale; // [esp+84h] [ebp-8h]
  bool bZoomed; // [esp+8Bh] [ebp-1h]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "SnowFall",
    a3: 0,
    a4: "Particle/Effect_Rendering",
    a5: false,
    a6: 4);
  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  v4 = LocalPlayer;
  if ( LocalPlayer != nullptr )
  {
    EyePosition = LocalPlayer->EyePosition;
    flCurrentTime = *(float *)(gpGlobals.m_Index + 16);
    v6 = (float *)EyePosition(this: LocalPlayer, result: &vecTraceStart);
    this->m_vecSnowFallEmitOrigin.x = *v6;
    this->m_vecSnowFallEmitOrigin.y = v6[1];
    this->m_vecSnowFallEmitOrigin.z = v6[2];
    C_BaseEntity::GetVectors(this: v4, pForward: &vecForward, pRight: nullptr, pUp: nullptr);
    vecForward.z = 0.0;
    C_BaseEntity::CalcAbsoluteVelocity(this: v4);
    vecVelocity = v4->m_vecAbsVelocity;
    flRadius = VectorNormalize(vec: &vecVelocity);
    v7 = (float)((float)(flRadius * 0.40000001) * r_SnowPosScale.m_pParent->m_Value.m_fValue) + 64.0;
    z = vecVelocity.z;
    v9 = (float)(vecForward.x * v7) + this->m_vecSnowFallEmitOrigin.x;
    v10 = (float)(vecForward.y * v7) + this->m_vecSnowFallEmitOrigin.y;
    v11 = (float)(v7 * vecForward.z) + this->m_vecSnowFallEmitOrigin.z;
    this->m_vecSnowFallEmitOrigin.x = v9;
    x = vecVelocity.x;
    this->m_vecSnowFallEmitOrigin.y = v10;
    y = vecVelocity.y;
    this->m_vecSnowFallEmitOrigin.z = v11;
    v14 = (float)(flRadius * 1.25) * r_SnowSpeedScale.m_pParent->m_Value.m_fValue;
    v15 = (float)(y * v14) + this->m_vecSnowFallEmitOrigin.y;
    v16 = (float)(z * v14) + this->m_vecSnowFallEmitOrigin.z;
    this->m_vecSnowFallEmitOrigin.x = (float)(x * v14) + this->m_vecSnowFallEmitOrigin.x;
    this->m_vecSnowFallEmitOrigin.y = v15;
    this->m_vecSnowFallEmitOrigin.z = v16;
    v34 = v4->GetFOV(this: v4);
    v17 = (double)v4->GetDefaultFOV(this: v4);
    bZoomed = v34 != v17;
    flZoomScale = 1.0;
    if ( v34 != v17 )
    {
      v18 = COERCE_FLOAT(v4->GetDefaultFOV(this: v4));
      v19 = v4->C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
      v34 = v18;
      v20 = (double)SLODWORD(v18);
      GetFOV = v19->GetFOV;
      v34 = v20;
      v22 = ((double (__thiscall *)(C_BasePlayer *))GetFOV)(a1: v4);
      flZoomScale = v34 / v22 * 0.5;
    }
    m_fNextEvent = this->m_tSnowFallParticleTraceTimer.m_fNextEvent;
    v24 = flCurrentTime;
    if ( flCurrentTime < m_fNextEvent )
    {
      this->m_tSnowFallParticleTraceTimer.m_fNextEvent = m_fNextEvent - flCurrentTime;
    }
    else
    {
      this->m_tSnowFallParticleTraceTimer.m_fNextEvent = this->m_tSnowFallParticleTraceTimer.m_TimeBetweenEvents;
      this->m_iSnowFallArea = 0;
      v25 = v4->EyePosition;
      flCurrentTime = v24 - m_fNextEvent;
      vecTraceStart = *(Vector *)((int (__thiscall *)(C_BasePlayer *, Vector *, int))v25)(a1: v4, a2: &v30, a3: a2);
      if ( CSnowFallManager::StandingInSnowVolume(this, vecPoint: &vecTraceStart) == -1 )
      {
        this->m_flSnowRadius = r_SnowOutsideRadius.m_pParent->m_Value.m_fValue;
      }
      else
      {
        this->m_flSnowRadius = (float)(flRadius * 0.5) + r_SnowInsideRadius.m_pParent->m_Value.m_fValue;
        this->m_iSnowFallArea = 1;
      }
      m_flSnowRadius = this->m_flSnowRadius;
      flRadius = m_flSnowRadius;
      if ( bZoomed )
      {
        if ( this->m_iSnowFallArea == 1 )
          m_flSnowRadius = r_SnowOutsideRadius.m_pParent->m_Value.m_fValue;
        flRadius = m_flSnowRadius * flZoomScale;
      }
      v27 = (const Vector *)((int (__thiscall *)(C_BasePlayer *))v4->EyePosition)(a1: v4);
      CSnowFallManager::FindSnowVolumes(
        this,
        vecCenter: &this->m_vecSnowFallEmitOrigin,
        flRadius,
        vecEyePos: v27,
        vecForward: &v30);
      if ( this->m_nActiveSnowCount != 0 && this->m_iSnowFallArea != 1 )
        this->m_iSnowFallArea = 2;
    }
    if ( this->m_iSnowFallArea != 0 )
    {
      CParticleEffect::SetSortOrigin(this: this->m_pSnowFallEmitter.m_pObj, vSortOrigin: &this->m_vecSnowFallEmitOrigin);
      v29 = flZoomScale;
      v28 = v4->EyePosition(this: v4, result: &v30);
      CSnowFallManager::CreateSnowFallParticles(
        this,
        flCurrentTime,
        flRadius: this->m_flSnowRadius,
        vecEyePos: v28,
        &vecForward,
        flZoomScale: v29,
        pLocalPlayer: v4);
    }
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
  else
  {
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10242C70
// Name: public: RayTracingEnvironment::RayTracingEnvironment(void)
// Source: json
//------------------------------------------------------------------------------
RayTracingEnvironment *__thiscall RayTracingEnvironment::RayTracingEnvironment(RayTracingEnvironment *this)
{
  CUtlBlockVector<CacheOptimizedTriangle> *p_OptimizedTriangleList; // ecx
  unsigned int v3; // eax
  int v4; // ecx
  __m128 v5; // xmm1

  p_OptimizedTriangleList = &this->OptimizedTriangleList;
  this->OptimizedKDTree.m_Memory.m_pMemory = nullptr;
  this->OptimizedKDTree.m_Memory.m_nAllocationCount = 0;
  this->OptimizedKDTree.m_Memory.m_nGrowSize = 0;
  this->OptimizedKDTree.m_Size = 0;
  this->OptimizedKDTree.m_pElements = nullptr;
  p_OptimizedTriangleList->m_Memory.m_pMemory = nullptr;
  p_OptimizedTriangleList->m_Memory.m_nBlocks = 0;
  *((_DWORD *)&p_OptimizedTriangleList->m_Memory + 2) = 0;
  CUtlBlockMemory<CacheOptimizedTriangle,int>::Purge(this: &p_OptimizedTriangleList->m_Memory);
  v3 = 1023;
  v4 = 1024;
  *((_DWORD *)&this->OptimizedTriangleList.m_Memory + 2) = 1023;
  do
  {
    v4 >>= 1;
    v3 = ((v3 & 0xF8000000) + 0x8000000) ^ v3 & 0x7FFFFFF;
  }
  while ( v4 > 1 );
  *((_DWORD *)&this->OptimizedTriangleList.m_Memory + 2) = v3;
  this->OptimizedTriangleList.m_Size = 0;
  this->OptimizedTriangleList.m_pElements = nullptr;
  this->TriangleIndexList.m_Memory.m_pMemory = nullptr;
  this->TriangleIndexList.m_Memory.m_nAllocationCount = 0;
  this->TriangleIndexList.m_Memory.m_nGrowSize = 0;
  this->TriangleIndexList.m_Size = 0;
  this->TriangleIndexList.m_pElements = nullptr;
  this->LightList.m_Memory.m_pMemory = nullptr;
  this->LightList.m_Memory.m_nAllocationCount = 0;
  this->LightList.m_Memory.m_nGrowSize = 0;
  this->LightList.m_Size = 0;
  this->LightList.m_pElements = nullptr;
  this->TriangleColors.m_Memory.m_pMemory = nullptr;
  this->TriangleColors.m_Memory.m_nAllocationCount = 0;
  this->TriangleColors.m_Memory.m_nGrowSize = 0;
  this->TriangleColors.m_Size = 0;
  this->TriangleColors.m_pElements = nullptr;
  this->TriangleMaterials.m_Memory.m_pMemory = nullptr;
  this->TriangleMaterials.m_Memory.m_nAllocationCount = 0;
  this->TriangleMaterials.m_Memory.m_nGrowSize = 0;
  this->TriangleMaterials.m_Size = 0;
  this->TriangleMaterials.m_pElements = nullptr;
  this->BackgroundColor.x = _mm_shuffle_ps((__m128)0x3F800000u, (__m128)0x3F800000u, 0);
  v5 = _mm_shuffle_ps((__m128)0, (__m128)0, 0);
  this->BackgroundColor.y = v5;
  this->BackgroundColor.z = v5;
  this->Flags = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10242DC0
// Name: private: void CClient_Precipitation::UpdateParticlePrecip(class C_BasePlayer __near *,int)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CClient_Precipitation::UpdateParticlePrecip(
        CClient_Precipitation *this@<ecx>,
        int a2@<ebp>,
        C_BasePlayer *pPlayer,
        int nSlot)
{
  float y; // esi
  __m128 v5; // xmm0
  float v6; // xmm0_4
  float v7; // xmm1_4
  float *v8; // eax
  Vector *(__thiscall *EyePosition)(C_BaseEntity *, Vector *); // edx
  float v10; // xmm0_4
  __m128 v11; // xmm0
  bool v12; // cl
  bool v13; // al
  CNewParticleEffect *v14; // ecx
  CUtlIntrusiveDList<CUtlReference<CSheet> > *v15; // eax
  CUtlReference<CSheet> *v16; // ecx
  __m128 v17; // xmm0
  bool v18; // zf
  float z; // eax
  CNewParticleEffect *v20; // eax
  CNewParticleEffect **v21; // esi
  CNewParticleEffect *v22; // ecx
  float Result_32; // [esp+20h] [ebp-170h]
  __int128 Result_36; // [esp+24h] [ebp-16Ch]
  __m128 Result_52; // [esp+34h] [ebp-15Ch]
  __m128 v26; // [esp+B4h] [ebp-DCh]
  Vector v27; // [esp+D4h] [ebp-BCh] BYREF
  Vector vForward45Left; // [esp+E0h] [ebp-B0h] BYREF
  float v29; // [esp+ECh] [ebp-A4h]
  __m128 vForward45Right_4; // [esp+F4h] [ebp-9Ch] OVERLAPPED
  Vector v31; // [esp+104h] [ebp-8Ch] BYREF
  Vector vOffsetPosNear; // [esp+110h] [ebp-80h] BYREF
  Vector vRight; // [esp+11Ch] [ebp-74h] BYREF
  Vector vOffsetPosFar; // [esp+128h] [ebp-68h] BYREF
  _BYTE vOffsetPos[28]; // [esp+134h] [ebp-5Ch] OVERLAPPED
  Vector v36; // [esp+150h] [ebp-40h] BYREF
  Vector vPlayerPos; // [esp+15Ch] [ebp-34h] BYREF
  __int128 vDensity; // [esp+168h] [ebp-28h] OVERLAPPED BYREF
  Vector vForward; // [esp+178h] [ebp-18h]
  int v40; // [esp+184h] [ebp-Ch]
  void *v41; // [esp+188h] [ebp-8h]
  void *retaddr; // [esp+190h] [ebp+0h]

  v40 = a2;
  v41 = retaddr;
  y = *(float *)&this;
  LODWORD(vForward.y) = this;
  if ( pPlayer != nullptr )
  {
    C_BaseEntity::GetVectors(
      this: pPlayer,
      pForward: (Vector *)((char *)&vDensity + 4),
      pRight: &vOffsetPosNear,
      pUp: nullptr);
    HIDWORD(vDensity) = 0;
    VectorNormalize(vec: (Vector *)((char *)&vDensity + 4));
    vForward45Left.y = vOffsetPosNear.x + *((float *)&vDensity + 1);
    vForward45Left.z = *((float *)&vDensity + 2) + vOffsetPosNear.y;
    v29 = vOffsetPosNear.z + *((float *)&vDensity + 3);
    v27.x = *((float *)&vDensity + 1) - vOffsetPosNear.x;
    v27.y = *((float *)&vDensity + 2) - vOffsetPosNear.y;
    v27.z = *((float *)&vDensity + 3) - vOffsetPosNear.z;
    VectorNormalize(vec: (Vector *)&vForward45Left.y);
    VectorNormalize(vec: &v27);
    v5 = 0;
    v5.m128_f32[0] = 320.0;
    v26 = _mm_shuffle_ps(v5, v5, 0);
    v26.m128_i32[3] = 2139095039;
    LODWORD(vDensity) = *(_DWORD *)(gpGlobals.m_Index + 16);
    while ( 1 )
    {
      while ( 1 )
      {
        v6 = *(float *)(LODWORD(y) + 8 * nSlot + 2628);
        v7 = *(float *)&vDensity;
        v8 = (float *)(LODWORD(y) + 8 * nSlot + 2628);
        if ( *(float *)&vDensity < v6 )
        {
          *v8 = *v8 - *(float *)&vDensity;
          return;
        }
        *v8 = *(float *)(LODWORD(y) + 8 * nSlot + 2624);
        EyePosition = pPlayer->EyePosition;
        *(float *)&vDensity = v7 - v6;
        EyePosition(this: pPlayer, result: &v36);
        v31.y = v36.y + (float)(*((float *)&vDensity + 2) * 32.0);
        vOffsetPosFar.z = v36.z + 180.0;
        v31.z = (float)(v36.z + 180.0) + (float)(*((float *)&vDensity + 3) * 32.0);
        *(_QWORD *)&vOffsetPosFar.x = *(_QWORD *)&v36.x;
        *(_QWORD *)&vOffsetPos[16] = *(_QWORD *)&v36.x;
        *(float *)&vOffsetPos[24] = v36.z + 180.0;
        vRight.x = v36.x + (float)(*((float *)&vDensity + 1) * 100.0);
        vRight.z = (float)(v36.z + 180.0) + (float)(*((float *)&vDensity + 3) * 100.0);
        v10 = *(float *)(LODWORD(y) + 2480);
        vRight.y = v36.y + (float)(*((float *)&vDensity + 2) * 100.0);
        v31.x = v36.x + (float)(*((float *)&vDensity + 1) * 32.0);
        vPlayerPos.x = r_RainParticleDensity.m_pParent->m_Value.m_fValue * v10;
        vPlayerPos.y = v10 * 0.0;
        vPlayerPos.z = v10 * 0.0;
        RayTracingEnvironment::Trace4Rays(this: *g_RayTraceEnvironments.m_Memory.m_pMemory, TMin: Four_Zeros, TMax: v26);
        *(_OWORD *)vOffsetPos = Result_36;
        vForward45Right_4.m128_f32[0] = (float)(int)Result_36;
        vForward45Right_4.m128_f32[1] = (float)SDWORD1(Result_36);
        vForward45Right_4.m128_f32[2] = (float)SDWORD2(Result_36);
        vForward45Right_4.m128_f32[3] = (float)SHIDWORD(Result_36);
        v11 = _mm_shuffle_ps((__m128)0x43960000u, (__m128)0x43960000u, 0);
        v12 = HIDWORD(Result_36) != -1 && Result_32 < 0.0;
        v13 = _mm_movemask_ps(_mm_cmple_ps(Four_Zeros, vForward45Right_4)) != 0
           && _mm_movemask_ps(_mm_cmple_ps(Result_52, v11)) != 0;
        if ( !v12 )
          break;
LABEL_23:
        v18 = *(_DWORD *)(LODWORD(y) + 12 * nSlot + 2596) == 0;
        v21 = (CNewParticleEffect **)(LODWORD(y) + 12 * nSlot);
        if ( !v18 && v21[652] != nullptr && (v22 = v21[655]) != nullptr )
        {
          CNewParticleEffect::SetControlPoint(this: v22, nWhichPoint: 1, v: &vOffsetPosFar);
          CNewParticleEffect::SetControlPoint(this: v21[649], nWhichPoint: 1, v: &v31);
          CNewParticleEffect::SetControlPoint(this: v21[652], nWhichPoint: 1, v: &vRight);
          CNewParticleEffect::SetControlPoint(this: v21[649], nWhichPoint: 3, v: &vPlayerPos);
          CNewParticleEffect::SetControlPoint(this: v21[652], nWhichPoint: 3, v: &vPlayerPos);
          CNewParticleEffect::SetControlPoint(this: v21[655], nWhichPoint: 3, v: &vPlayerPos);
          y = vForward.y;
        }
        else
        {
          CClient_Precipitation::DispatchInnerParticlePrecip(
            this: (CClient_Precipitation *)LODWORD(vForward.y),
            nSlot,
            pPlayer,
            vForward: *(Vector *)((char *)&vDensity + 4));
          y = vForward.y;
        }
      }
      if ( v13 )
      {
        v17 = _mm_min_ps(
                _mm_min_ps(Result_52, _mm_shuffle_ps(Result_52, Result_52, 57)),
                _mm_shuffle_ps(Result_52, Result_52, 78));
        *(__m128 *)vOffsetPos = _mm_shuffle_ps(v17, v17, 0);
        if ( *(float *)vOffsetPos < *(float *)(LODWORD(y) + 2572) )
          goto LABEL_23;
        v18 = *(_DWORD *)(LODWORD(y) + 12 * nSlot + 2596) == 0;
        LODWORD(z) = LODWORD(y) + 12 * nSlot;
        vForward.z = z;
        if ( !v18 )
        {
          CClient_Precipitation::DestroyInnerParticlePrecip(this: (CClient_Precipitation *)LODWORD(y), nSlot);
          z = vForward.z;
        }
        v20 = *(CNewParticleEffect **)(LODWORD(z) + 2620);
        if ( v20 != nullptr )
        {
          CNewParticleEffect::SetControlPoint(this: v20, nWhichPoint: 1, v: &vOffsetPosFar);
          CNewParticleEffect::SetControlPoint(
            this: *(CNewParticleEffect **)(LODWORD(vForward.z) + 2620),
            nWhichPoint: 3,
            v: &vPlayerPos);
        }
        else
        {
          CClient_Precipitation::DispatchOuterParticlePrecip(
            this: (CClient_Precipitation *)LODWORD(y),
            nSlot,
            pPlayer,
            vForward: *(Vector *)((char *)&vDensity + 4));
        }
      }
      else
      {
        CClient_Precipitation::DestroyInnerParticlePrecip(this: (CClient_Precipitation *)LODWORD(y), nSlot);
        v14 = *(CNewParticleEffect **)(LODWORD(y) + 12 * nSlot + 2620);
        LODWORD(vForward.z) = LODWORD(y) + 12 * nSlot;
        if ( v14 != nullptr )
        {
          CNewParticleEffect::StopEmission(
            this: v14,
            bInfiniteOnly: false,
            bRemoveAllParticles: false,
            bWakeOnStop: false,
            bPlayEndCap: false);
          v15 = *(CUtlIntrusiveDList<CUtlReference<CSheet> > **)(LODWORD(vForward.z) + 2620);
          v16 = (CUtlReference<CSheet> *)(LODWORD(vForward.z) + 2612);
          LODWORD(vForward.z) += 2612;
          if ( v15 != nullptr )
          {
            CUtlIntrusiveDList<CUtlReference<CNewParticleEffect>>::RemoveNode(this: v15 + 232, which: v16);
            *(_DWORD *)(LODWORD(vForward.z) + 8) = 0;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10243350
// Name: private: void CClient_Precipitation::EmitParticles(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClient_Precipitation::EmitParticles(CClient_Precipitation *this, float fTimeDelta)
{
  C_BasePlayer *LocalPlayer; // esi
  int v4; // eax
  __int64 v5; // xmm0_8
  float v6; // eax
  float v7; // xmm2_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  float z; // edi
  int m_nValue; // edx
  int v12; // eax
  double v13; // st7
  int v14; // edx
  int v15; // eax
  double v16; // st7
  double v17; // st7
  double v18; // st7
  int v19; // esi
  float v20; // xmm1_4
  ConVar *m_pParent; // eax
  CClient_Precipitation *v22; // edi
  unsigned __int16 v23; // si
  unsigned __int16 v24; // ax
  float x; // xmm0_4
  int v26; // esi
  double m_InitialRamp; // st7
  CGameTrace trace; // [esp+68h] [ebp-C0h] BYREF
  Vector org; // [esp+BCh] [ebp-6Ch] BYREF
  Vector vUnitParticleVel; // [esp+C8h] [ebp-60h]
  Vector vPlayerCenter; // [esp+D4h] [ebp-54h]
  Vector vParticleEndPos; // [esp+E0h] [ebp-48h] BYREF
  Vector vel; // [esp+ECh] [ebp-3Ch]
  Vector2D size; // [esp+F8h] [ebp-30h] BYREF
  CClient_Precipitation *v35; // [esp+100h] [ebp-28h]
  Vector vParticleVel; // [esp+104h] [ebp-24h]
  Vector vPlayerHeight; // [esp+110h] [ebp-18h] BYREF
  Vector vParticlePos; // [esp+11Ch] [ebp-Ch] BYREF
  IHandleEntity savedregs; // [esp+128h] [ebp+0h] BYREF
  int fTimeDeltaa; // [esp+130h] [ebp+8h]

  v35 = this;
  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  if ( LocalPlayer != nullptr )
  {
    v4 = (int)LocalPlayer->WorldSpaceCenter(this: LocalPlayer);
    v5 = *(_QWORD *)v4;
    v6 = *(float *)(v4 + 8);
    *(_QWORD *)&vPlayerCenter.x = v5;
    vPlayerCenter.z = v6;
    if ( CClient_Precipitation::ComputeEmissionArea(this, origin: &org, &size, pCharacter: LocalPlayer) != 0 )
    {
      v7 = fTimeDelta;
      if ( fTimeDelta > 0.075000003 )
        v7 = 0.075000003;
      v8 = this->m_flDensity * 0.001;
      if ( v8 > 0.0099999998 )
        v8 = 0.0099999998;
      v9 = (float)((float)((float)(size.y * size.x) * v8) * v7) + this->m_Remainder;
      this->m_Remainder = v9 - (float)(int)v9;
      vel.x = CClient_Precipitation::s_WindVector.x;
      vel.y = CClient_Precipitation::s_WindVector.y;
      vel.z = CClient_Precipitation::s_WindVector.z - CClient_Precipitation::s_rainspeed.m_pParent->m_Value.m_fValue;
      if ( (int)v9 > 0 )
      {
        fTimeDeltaa = (int)v9;
        while ( 1 )
        {
          z = vel.z;
          vParticleVel = vel;
          if ( r_RainSideVel.m_pParent != nullptr )
          {
            m_nValue = r_RainSideVel.m_pParent->m_Value.m_nValue;
            v12 = m_nValue;
          }
          else
          {
            m_nValue = 0;
            v12 = 0;
          }
          v13 = ((double (__thiscall *)(_DWORD, _DWORD, _DWORD))random->RandomFloat)(
                  a1: random,
                  a2: (float)-v12,
                  a3: (float)m_nValue);
          vParticleVel.x = v13 + vel.x;
          if ( r_RainSideVel.m_pParent != nullptr )
          {
            v14 = r_RainSideVel.m_pParent->m_Value.m_nValue;
            v15 = v14;
          }
          else
          {
            v14 = 0;
            v15 = 0;
          }
          v16 = ((double (__thiscall *)(_DWORD, _DWORD, _DWORD))random->RandomFloat)(
                  a1: random,
                  a2: (float)-v15,
                  a3: (float)v14);
          vParticlePos = org;
          vParticleVel.y = v16 + vParticleVel.y;
          v17 = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, int))random->RandomFloat)(
                  a1: random,
                  a2: 0,
                  a3: 1065353216);
          vParticlePos.x = v17 * size.x + vParticlePos.x;
          v18 = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, int))random->RandomFloat)(
                  a1: random,
                  a2: 0,
                  a3: 1065353216);
          v19 = 0;
          vParticlePos.y = v18 * size.y + vParticlePos.y;
          *(_QWORD *)&vPlayerHeight.x = *(_QWORD *)&vParticlePos.x;
          vPlayerHeight.z = vPlayerCenter.z;
          if ( g_PrecipitationBlockers.m_Size > 0 )
          {
            while ( !CCollisionProperty::IsPointInBounds(
                       this: &g_PrecipitationBlockers.m_Memory.m_pMemory[v19]->m_Collision,
                       vecWorldPt: &vPlayerHeight) )
            {
              if ( ++v19 >= g_PrecipitationBlockers.m_Size )
                goto LABEL_18;
            }
            if ( r_RainDebugDuration.m_pParent != nullptr && r_RainDebugDuration.m_pParent->m_Value.m_nValue != 0 )
              ((void (__stdcall *)(Vector *, Vector *, int, _DWORD, _DWORD, _DWORD, _DWORD))debugoverlay->AddLineOverlay)(
                a1: &vPlayerHeight,
                a2: &vParticlePos,
                a3: 255,
                a4: 0,
                a5: 0,
                a6: 0,
                a7: LODWORD(r_RainDebugDuration.m_pParent->m_Value.m_fValue));
            goto LABEL_30;
          }
LABEL_18:
          *(_QWORD *)&vUnitParticleVel.x = *(_QWORD *)&vParticleVel.x;
          v20 = 1.0 / (float)(vParticlePos.z - vPlayerHeight.z);
          vUnitParticleVel.z = z;
          vPlayerHeight.x = (float)((float)(vParticleVel.x * v20) * (float)(vParticlePos.z - vPlayerHeight.z))
                          + vPlayerHeight.x;
          vPlayerHeight.y = (float)((float)(v20 * vParticleVel.y) * (float)(vParticlePos.z - vPlayerHeight.z))
                          + vPlayerHeight.y;
          UTIL_TraceLine(
            a1: &savedregs,
            a2: v19,
            vecAbsStart: &vPlayerHeight,
            vecAbsEnd: &vParticlePos,
            mask: 0x400Bu,
            ignore: nullptr,
            collisionGroup: 0,
            ptr: &trace);
          if ( trace.fraction >= 1.0 )
            goto LABEL_23;
          m_pParent = r_RainDebugDuration.m_pParent;
          if ( (trace.surface.flags & 4) == 0 )
          {
            if ( r_RainDebugDuration.m_pParent != nullptr && r_RainDebugDuration.m_pParent->m_Value.m_nValue != 0 )
              ((void (__stdcall *)(Vector *, Vector *, int, _DWORD, _DWORD, _DWORD, _DWORD))debugoverlay->AddLineOverlay)(
                a1: &vPlayerHeight,
                a2: &trace.endpos,
                a3: 255,
                a4: 0,
                a5: 0,
                a6: 0,
                a7: LODWORD(r_RainDebugDuration.m_pParent->m_Value.m_fValue));
            goto LABEL_30;
          }
          vParticlePos = trace.endpos;
          if ( r_RainDebugDuration.m_pParent != nullptr && r_RainDebugDuration.m_pParent->m_Value.m_nValue != 0 )
            break;
LABEL_24:
          vParticleEndPos = vPlayerHeight;
          if ( m_pParent != nullptr && m_pParent->m_Value.m_nValue != 0 )
            ((void (__stdcall *)(Vector *, Vector *, _DWORD, int, _DWORD, int, _DWORD))debugoverlay->AddLineOverlay)(
              a1: &vParticlePos,
              a2: &vParticleEndPos,
              a3: 0,
              a4: 255,
              a5: 0,
              a6: 1,
              a7: LODWORD(m_pParent->m_Value.m_fValue));
          v22 = v35;
          v23 = CUtlLinkedList<CPrecipitationParticle,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPrecipitationParticle,unsigned short>,unsigned short>>::AllocInternal(
                  this: &v35->m_Particles,
                  multilist: false);
          v24 = -1;
          if ( v23 != 0xFFFF )
          {
            CUtlLinkedList<CPrecipitationParticle,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPrecipitationParticle,unsigned short>,unsigned short>>::LinkBefore(
              this: &v22->m_Particles,
              before: 0xFFFFu,
              elem: v23);
            v24 = v23;
          }
          x = vParticleVel.x;
          v26 = (int)&v22->m_Particles.m_Memory.m_pMemory[v24];
          *(float *)(v26 + 24) = *(float *)(gpGlobals.m_Index + 12);
          m_InitialRamp = v22->m_InitialRamp;
          *(_DWORD *)(v26 + 40) = 0;
          *(float *)(v26 + 32) = m_InitialRamp;
          *(float *)(v26 + 12) = x;
          *(float *)(v26 + 16) = vParticleVel.y;
          *(float *)(v26 + 20) = vParticleVel.z;
          *(Vector *)v26 = vParticlePos;
          *(float *)(v26 + 28) = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                                   a1: random,
                                   a2: 1056964608,
                                   a3: 1069547520);
          *(_DWORD *)(v26 + 36) = COERCE_UNSIGNED_INT((float)(vParticlePos.z - vParticleEndPos.z) / vParticleVel.z)
                                & _mask__AbsFloat_;
LABEL_30:
          if ( --fTimeDeltaa == 0 )
            return;
        }
        ((void (__stdcall *)(Vector *, Vector *, _DWORD, _DWORD, int, _DWORD, _DWORD))debugoverlay->AddLineOverlay)(
          a1: &vPlayerHeight,
          a2: &trace.endpos,
          a3: 0,
          a4: 0,
          a5: 255,
          a6: 0,
          a7: LODWORD(r_RainDebugDuration.m_pParent->m_Value.m_fValue));
LABEL_23:
        m_pParent = r_RainDebugDuration.m_pParent;
        goto LABEL_24;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10243860
// Name: public: virtual void CSnowFallManager::ClientThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSnowFallManager::ClientThink(CSnowFallManager *this)
{
  if ( IsValidSplitScreenSlot(i: this->m_aSnow.m_Memory.m_nGrowSize)
    && r_SnowEnable.m_pParent != nullptr
    && r_SnowEnable.m_pParent->m_Value.m_nValue != 0
    && (LODWORD(this->m_tSnowFallParticleTraceTimer.m_TimeBetweenEvents) != 0
     || CSnowFallManager::CreateSnowFallEmitter(this: (CSnowFallManager *)((char *)this - 12)) != 0) )
  {
    CSnowFallManager::CreateSnowFall(this: (CSnowFallManager *)((char *)this - 12), a2: (int)this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10243BB0
// Name: private: void CClient_Precipitation::InitializeParticlePrecip(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CClient_Precipitation::InitializeParticlePrecip(
        CClient_Precipitation *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>)
{
  PrecipitationType_t m_nPrecipType; // eax
  float v5; // xmm0_4
  char *v6; // eax
  int v7; // eax
  RayTracingEnvironment *v8; // esi
  RayTracingEnvironment *v9; // ecx
  RayTracingEnvironment *v10; // ebx
  int m_Size; // eax
  int v12; // edi
  RayTracingEnvironment **m_pMemory; // ecx
  int v14; // eax
  RayTracingEnvironment **v15; // eax
  void *v16; // eax
  RayTracingEnvironment *v17; // ecx
  int v18; // eax
  int v19; // edi
  RayTracingEnvironment **v20; // ecx
  int v21; // eax
  RayTracingEnvironment **v22; // eax
  int v23; // edi
  int v24; // ebx
  IVModelInfoClient_vtbl *v25; // esi
  int ModelIndex; // eax
  int v27; // eax
  int v28; // eax
  int v29; // esi
  unsigned int v30; // edi
  int v31; // edi
  int v32; // ebx
  IVModelInfoClient_vtbl *v33; // esi
  int v34; // eax
  int v35; // eax
  int v36; // eax
  int v37; // esi
  unsigned int v38; // edi
  Vector color; // [esp+0h] [ebp-24h] BYREF
  CClient_Precipitation *v40; // [esp+Ch] [ebp-18h]
  int vertCount; // [esp+10h] [ebp-14h]
  int i; // [esp+14h] [ebp-10h] BYREF
  Vector *outVerts; // [esp+18h] [ebp-Ch] BYREF
  RayTracingEnvironment *rtEnvRainEmission; // [esp+1Ch] [ebp-8h]
  RayTracingEnvironment *rtEnvRainBlocker; // [esp+20h] [ebp-4h]

  m_nPrecipType = this->m_nPrecipType;
  v40 = this;
  switch ( m_nPrecipType )
  {
    case PRECIPITATION_TYPE_PARTICLEASH:
      v5 = 280.0;
      v6 = "ash";
      this->m_pParticleOuterDef = "ash_outer";
      break;
    case PRECIPITATION_TYPE_PARTICLESNOW:
      v5 = 280.0;
      v6 = "snow";
      this->m_pParticleOuterDef = "snow_outer";
      break;
    case PRECIPITATION_TYPE_PARTICLERAINSTORM:
      v5 = 0.0;
      this->m_pParticleInnerNearDef = "rain_storm";
      this->m_pParticleInnerFarDef = "rain_storm_screen";
      this->m_pParticleOuterDef = "rain_storm_outer";
      goto LABEL_9;
    default:
      v5 = 180.0;
      v6 = "rain";
      this->m_pParticleOuterDef = "rain_outer";
      break;
  }
  this->m_pParticleInnerNearDef = v6;
  this->m_pParticleInnerFarDef = v6;
LABEL_9:
  this->m_flParticleInnerDist = v5;
  CUtlVector<RayTracingEnvironment *,CUtlMemory<RayTracingEnvironment *,int>>::PurgeAndDeleteElements(this: &g_RayTraceEnvironments);
  v7 = ((int (__thiscall *)(IMemAlloc *, int, int, int, int))_g_pMemAlloc->Alloc_2)(
         a1: _g_pMemAlloc,
         a2: 227,
         a3,
         a4,
         a5: a2);
  v8 = nullptr;
  if ( v7 != 0 )
  {
    v9 = (RayTracingEnvironment *)((v7 + 19) & 0xFFFFFFF0);
    *((_DWORD *)&v9[-1].TriangleMaterials + 6) = v7;
    v10 = RayTracingEnvironment::RayTracingEnvironment(this: v9);
    rtEnvRainEmission = v10;
  }
  else
  {
    rtEnvRainEmission = nullptr;
    v10 = nullptr;
  }
  m_Size = g_RayTraceEnvironments.m_Size;
  v12 = g_RayTraceEnvironments.m_Size;
  if ( g_RayTraceEnvironments.m_Size + 1 > g_RayTraceEnvironments.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<CChoreoActor *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&g_RayTraceEnvironments,
      num: g_RayTraceEnvironments.m_Size - g_RayTraceEnvironments.m_Memory.m_nAllocationCount + 1);
    m_Size = g_RayTraceEnvironments.m_Size;
  }
  m_pMemory = g_RayTraceEnvironments.m_Memory.m_pMemory;
  g_RayTraceEnvironments.m_Size = m_Size + 1;
  v14 = m_Size - v12;
  g_RayTraceEnvironments.m_pElements = g_RayTraceEnvironments.m_Memory.m_pMemory;
  if ( v14 > 0 )
  {
    _V_memmove(
      dest: (unsigned __int8 *)&g_RayTraceEnvironments.m_Memory.m_pMemory[v12 + 1],
      src: (unsigned __int8 *)&g_RayTraceEnvironments.m_Memory.m_pMemory[v12],
      count: 4 * v14);
    m_pMemory = g_RayTraceEnvironments.m_Memory.m_pMemory;
  }
  v15 = &m_pMemory[v12];
  if ( v15 != nullptr )
    *v15 = v10;
  v16 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 227);
  if ( v16 != nullptr )
  {
    v17 = (RayTracingEnvironment *)(((unsigned int)v16 + 19) & 0xFFFFFFF0);
    *((_DWORD *)&v17[-1].TriangleMaterials + 6) = v16;
    v8 = RayTracingEnvironment::RayTracingEnvironment(this: v17);
  }
  v18 = g_RayTraceEnvironments.m_Size;
  rtEnvRainBlocker = v8;
  v19 = g_RayTraceEnvironments.m_Size;
  if ( g_RayTraceEnvironments.m_Size + 1 > g_RayTraceEnvironments.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<CChoreoActor *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&g_RayTraceEnvironments,
      num: g_RayTraceEnvironments.m_Size - g_RayTraceEnvironments.m_Memory.m_nAllocationCount + 1);
    v18 = g_RayTraceEnvironments.m_Size;
  }
  v20 = g_RayTraceEnvironments.m_Memory.m_pMemory;
  g_RayTraceEnvironments.m_Size = v18 + 1;
  v21 = v18 - v19;
  g_RayTraceEnvironments.m_pElements = g_RayTraceEnvironments.m_Memory.m_pMemory;
  if ( v21 > 0 )
  {
    _V_memmove(
      dest: (unsigned __int8 *)&g_RayTraceEnvironments.m_Memory.m_pMemory[v19 + 1],
      src: (unsigned __int8 *)&g_RayTraceEnvironments.m_Memory.m_pMemory[v19],
      count: 4 * v21);
    v20 = g_RayTraceEnvironments.m_Memory.m_pMemory;
  }
  v22 = &v20[v19];
  if ( v22 != nullptr )
    *v22 = v8;
  v10->Flags |= 2u;
  v8->Flags |= 2u;
  v23 = 0;
  v24 = 1;
  i = 0;
  if ( g_Precipitations_1.m_Size > 0 )
  {
    do
    {
      v25 = modelinfo->__vftable;
      ModelIndex = C_BaseEntity::GetModelIndex(this: g_Precipitations_1.m_Memory.m_pMemory[v23]);
      v27 = (int)v25->GetVCollide(this: modelinfo, a2: ModelIndex);
      if ( v27 != 0 && (*(_WORD *)v27 & 0x7FFF) != 0 )
      {
        v28 = g_pPhysicsCollision->CreateDebugMesh(
                this: g_pPhysicsCollision,
                a2: **(const struct CPhysCollide ***)(v27 + 4),
                a3: &outVerts);
        vertCount = v28;
        if ( v28 > 0 )
        {
          v29 = 0;
          v30 = (v28 - 1) / 3u + 1;
          do
          {
            color.x = 1.0;
            color.y = 1.0;
            color.z = 1.0;
            RayTracingEnvironment::AddTriangle(
              this: rtEnvRainEmission,
              id: v24++,
              v1: &outVerts[v29],
              v2: &outVerts[v29 + 1],
              v3: &outVerts[v29 + 2],
              &color);
            v29 += 3;
            --v30;
          }
          while ( v30 != 0 );
          v28 = vertCount;
          v23 = i;
        }
        physcollision->DestroyDebugMesh(this: physcollision, a2: v28, a3: outVerts);
      }
      i = ++v23;
    }
    while ( v23 < g_Precipitations_1.m_Size );
    v8 = rtEnvRainBlocker;
  }
  RayTracingEnvironment::SetupAccelerationStructure(this: rtEnvRainEmission);
  v31 = 0;
  v32 = 1;
  outVerts = nullptr;
  if ( g_PrecipitationBlockers.m_Size > 0 )
  {
    do
    {
      v33 = modelinfo->__vftable;
      v34 = C_BaseEntity::GetModelIndex(this: g_PrecipitationBlockers.m_Memory.m_pMemory[v31]);
      v35 = (int)v33->GetVCollide(this: modelinfo, a2: v34);
      if ( v35 != 0 && (*(_WORD *)v35 & 0x7FFF) != 0 )
      {
        v36 = g_pPhysicsCollision->CreateDebugMesh(
                this: g_pPhysicsCollision,
                a2: **(const struct CPhysCollide ***)(v35 + 4),
                a3: (Vector **)&i);
        vertCount = v36;
        if ( v36 > 0 )
        {
          v37 = 0;
          v38 = (v36 - 1) / 3u + 1;
          do
          {
            color.x = 1.0;
            color.y = 1.0;
            color.z = 1.0;
            RayTracingEnvironment::AddTriangle(
              this: rtEnvRainBlocker,
              id: v32++,
              v1: (const Vector *)(v37 + i),
              v2: (const Vector *)(v37 + i + 12),
              v3: (const Vector *)(v37 + i + 24),
              &color);
            v37 += 36;
            --v38;
          }
          while ( v38 != 0 );
          v36 = vertCount;
          v31 = (int)outVerts;
        }
        physcollision->DestroyDebugMesh(this: physcollision, a2: v36, a3: (Vector *)i);
      }
      outVerts = (Vector *)++v31;
    }
    while ( v31 < g_PrecipitationBlockers.m_Size );
    v8 = rtEnvRainBlocker;
  }
  RayTracingEnvironment::SetupAccelerationStructure(this: v8);
  v40->m_bParticlePrecipInitialized = true;
}

//------------------------------------------------------------------------------
// Address: 0x10243FA0
// Name: private: void CClient_Precipitation::CreateParticlePrecip(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CClient_Precipitation::CreateParticlePrecip(
        CClient_Precipitation *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>)
{
  CNewParticleEffect *v4; // ecx
  CNewParticleEffect *v5; // eax
  CUtlReference<CSheet> *m_pParticlePrecipOuter; // esi
  C_BasePlayer *LocalPlayer; // eax
  CNewParticleEffect *m_pObject; // ecx
  CNewParticleEffect *v9; // eax
  C_BasePlayer *pPlayer; // [esp+4h] [ebp-4h]
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  if ( r_RainAllowInSplitScreen.m_pParent != nullptr && r_RainAllowInSplitScreen.m_pParent->m_Value.m_nValue != 0
    || !engine->IsSplitScreenActive(this: engine) )
  {
    if ( !this->m_bParticlePrecipInitialized )
      CClient_Precipitation::InitializeParticlePrecip(this, a2, a3, a4: (int)this);
    LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
    pPlayer = LocalPlayer;
    if ( LocalPlayer != nullptr )
    {
      if ( !this->m_bActiveParticlePrecipEmitter[0] )
      {
        this->m_tParticlePrecipTraceTimer[0].m_TimeBetweenEvents = 0.125;
        this->m_tParticlePrecipTraceTimer[0].m_fNextEvent = 0.0;
        CClient_Precipitation::DestroyInnerParticlePrecip(this, nSlot: 0);
        m_pObject = this->m_pParticlePrecipOuter[0].m_pObject;
        if ( m_pObject != nullptr )
        {
          CNewParticleEffect::StopEmission(
            this: m_pObject,
            bInfiniteOnly: false,
            bRemoveAllParticles: false,
            bWakeOnStop: false,
            bPlayEndCap: false);
          v9 = this->m_pParticlePrecipOuter[0].m_pObject;
          if ( v9 != nullptr )
          {
            CUtlIntrusiveDList<CUtlReference<CNewParticleEffect>>::RemoveNode(
              this: (CUtlIntrusiveDList<CUtlReference<CSheet> > *)&v9->m_References,
              which: (CUtlReference<CSheet> *)this->m_pParticlePrecipOuter);
            this->m_pParticlePrecipOuter[0].m_pObject = nullptr;
          }
        }
        LocalPlayer = pPlayer;
        this->m_bActiveParticlePrecipEmitter[0] = true;
      }
      CClient_Precipitation::UpdateParticlePrecip(this, a2: (int)&savedregs, pPlayer: LocalPlayer, nSlot: 0);
    }
  }
  else if ( this->m_pParticlePrecipOuter[0].m_pObject != nullptr )
  {
    CClient_Precipitation::DestroyInnerParticlePrecip(this, nSlot: 0);
    v4 = this->m_pParticlePrecipOuter[0].m_pObject;
    if ( v4 != nullptr )
    {
      CNewParticleEffect::StopEmission(
        this: v4,
        bInfiniteOnly: false,
        bRemoveAllParticles: false,
        bWakeOnStop: false,
        bPlayEndCap: false);
      v5 = this->m_pParticlePrecipOuter[0].m_pObject;
      m_pParticlePrecipOuter = (CUtlReference<CSheet> *)this->m_pParticlePrecipOuter;
      if ( v5 != nullptr )
      {
        CUtlIntrusiveDList<CUtlReference<CNewParticleEffect>>::RemoveNode(
          this: (CUtlIntrusiveDList<CUtlReference<CSheet> > *)&v5->m_References,
          which: m_pParticlePrecipOuter);
        m_pParticlePrecipOuter->m_pObject = nullptr;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102440D0
// Name: private: void CClient_Precipitation::Simulate(float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CClient_Precipitation::Simulate(
        CClient_Precipitation *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        float dt)
{
  PrecipitationType_t m_nPrecipType; // eax
  PrecipitationType_t v6; // eax
  C_World *ClientWorldEntity; // edi
  float v8; // xmm0_4
  const Vector *v9; // eax
  const Vector *(__thiscall *WorldAlignMins)(C_BaseEntity *); // edx
  PrecipitationType_t v11; // eax
  int v12; // edi
  UtlLinkedListElem_t<CPrecipitationParticle,unsigned short> *m_pMemory; // edx
  int v14; // ecx
  int v15; // ebx
  int m_Head; // edi
  int v17; // eax
  int m_Next; // ebx
  int m_ElementCount; // edx
  IVEngineClient *v20; // edi
  IVEngineClient_vtbl *v21; // ebx
  unsigned int Microseconds; // eax
  UtlLinkedListElem_t<CPrecipitationParticle,unsigned short> *fTimeDelta; // [esp+0h] [ebp-20h]
  int fTimeDeltaa; // [esp+0h] [ebp-20h]
  CFastTimer timer; // [esp+10h] [ebp-10h] BYREF
  unsigned __int64 v26; // [esp+18h] [ebp-8h]
  int savedregs; // [esp+20h] [ebp+0h] BYREF

  m_nPrecipType = this->m_nPrecipType;
  if ( m_nPrecipType == PRECIPITATION_TYPE_PARTICLERAIN
    || m_nPrecipType == PRECIPITATION_TYPE_PARTICLEASH
    || m_nPrecipType == PRECIPITATION_TYPE_PARTICLERAINSTORM
    || m_nPrecipType == PRECIPITATION_TYPE_PARTICLESNOW )
  {
    CClient_Precipitation::CreateParticlePrecip(this, a2, a3);
  }
  else
  {
    this->Precache(this);
    this->m_flHalfScreenWidth = (float)ScreenWidth() * 0.5;
    if ( dt != 0.0 )
      CClient_Precipitation::ComputeWindVector();
    v6 = this->m_nPrecipType;
    if ( v6 == PRECIPITATION_TYPE_ASH )
    {
      CClient_Precipitation::CreateAshParticle(this, a2: COERCE_FLOAT(&savedregs));
    }
    else if ( v6 != PRECIPITATION_TYPE_SNOWFALL )
    {
      if ( r_RainHack.m_pParent != nullptr && r_RainHack.m_pParent->m_Value.m_nValue != 0 )
      {
        ClientWorldEntity = GetClientWorldEntity();
        v8 = ClientWorldEntity->m_WorldMaxs.z - GetClientWorldEntity()->m_WorldMins.z;
      }
      else
      {
        v9 = this->WorldAlignMaxs(this);
        WorldAlignMins = this->WorldAlignMins;
        HIDWORD(v26) = LODWORD(v9->z);
        v8 = *((float *)&v26 + 1) - WorldAlignMins(this)->z;
      }
      this->m_Lifetime = v8 / this->m_Speed;
      if ( r_RainSimulate.m_pParent != nullptr && r_RainSimulate.m_pParent->m_Value.m_nValue != 0 )
      {
        HIDWORD(v26) = &timer;
        timer.m_Duration.m_Int64 = __rdtsc();
        CClient_Precipitation::EmitParticles(this, fTimeDelta: dt);
        v11 = this->m_nPrecipType;
        if ( v11 != PRECIPITATION_TYPE_RAIN )
        {
          if ( v11 == PRECIPITATION_TYPE_SNOW )
          {
            m_Head = this->m_Particles.m_Head;
            if ( m_Head != 0xFFFF )
            {
              do
              {
                fTimeDelta = this->m_Particles.m_Memory.m_pMemory;
                v17 = (unsigned __int16)m_Head;
                m_Next = fTimeDelta[v17].m_Next;
                if ( CClient_Precipitation::SimulateSnow(this, pParticle: &fTimeDelta[v17].m_Element, dt) == 0 )
                  CUtlLinkedList<CPrecipitationParticle,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPrecipitationParticle,unsigned short>,unsigned short>>::Remove(
                    this: &this->m_Particles,
                    elem: m_Head);
                LOWORD(m_Head) = m_Next;
              }
              while ( m_Next != 0xFFFF );
            }
          }
        }
        else
        {
          v12 = this->m_Particles.m_Head;
          if ( v12 != 0xFFFF )
          {
            do
            {
              m_pMemory = this->m_Particles.m_Memory.m_pMemory;
              v14 = (unsigned __int16)v12;
              v15 = m_pMemory[v14].m_Next;
              if ( CClient_Precipitation::SimulateRain(this, pParticle: &m_pMemory[v14].m_Element, dt) == 0 )
                CUtlLinkedList<CPrecipitationParticle,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CPrecipitationParticle,unsigned short>,unsigned short>>::Remove(
                  this: &this->m_Particles,
                  elem: v12);
              LOWORD(v12) = v15;
            }
            while ( v15 != 0xFFFF );
          }
        }
        if ( r_RainProfile.m_pParent != nullptr && r_RainProfile.m_pParent->m_Value.m_nValue != 0 )
        {
          v26 = __rdtsc();
          m_ElementCount = this->m_Particles.m_ElementCount;
          v20 = engine;
          timer.m_Duration.m_Int64 = v26 - timer.m_Duration.m_Int64;
          v21 = engine->__vftable;
          fTimeDeltaa = m_ElementCount;
          Microseconds = CCycleCount::GetMicroseconds(this: &timer.m_Duration);
          v21->Con_NPrintf(this: v20, a2: 15, a3: "Rain simulation: %du (%d tracers)", Microseconds, fTimeDeltaa);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10244350
// Name: private: virtual void CClient_Precipitation::ClientThink(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CClient_Precipitation::ClientThink(CClient_Precipitation *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  CClient_Precipitation::Simulate(
    this: (CClient_Precipitation *)((char *)this - 12),
    a2,
    a3,
    dt: *(float *)(gpGlobals.m_Index + 16));
}

//------------------------------------------------------------------------------
// Address: 0x1042A230
// Name: PrecachePrecipitationPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
CBaseResourcePrecacher *PrecachePrecipitationPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  CBaseResourcePrecacher *result; // eax

  result = CBaseResourcePrecacher::sm_pFirst[0];
  PrecachePrecipitationPrecache::s_ResourcePrecacher.m_pNext = CBaseResourcePrecacher::sm_pFirst[0];
  CBaseResourcePrecacher::sm_pFirst[0] = &PrecachePrecipitationPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042A280
// Name: DT_PrecipitationBlocker::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_PrecipitationBlocker::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_PrecipitationBlocker::g_RecvTable);
  return atexit(func: DT_PrecipitationBlocker::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1042A2A0
// Name: DT_PrecipitationBlocker::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_PrecipitationBlocker::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_PrecipitationBlocker::ignored>();
  DT_PrecipitationBlocker::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042A2E0
// Name: DT_Precipitation::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_Precipitation::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_Precipitation::g_RecvTable);
  return atexit(func: DT_Precipitation::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1042A300
// Name: DT_Precipitation::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_Precipitation::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_Precipitation::ignored>();
  DT_Precipitation::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042A7C0
// Name: DT_EnvWindShared::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_EnvWindShared::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_EnvWindShared::g_RecvTable);
  return atexit(func: DT_EnvWindShared::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1042A7E0
// Name: DT_EnvWindShared::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_EnvWindShared::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_EnvWindShared::ignored>();
  DT_EnvWindShared::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042A810
// Name: DT_EnvWind::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_EnvWind::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_EnvWind::g_RecvTable);
  return atexit(func: DT_EnvWind::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1042A830
// Name: DT_EnvWind::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_EnvWind::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_EnvWind::ignored>();
  DT_EnvWind::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042A860
// Name: DT_Embers::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_Embers::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_Embers::g_RecvTable);
  return atexit(func: DT_Embers::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1042A880
// Name: DT_Embers::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_Embers::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_Embers::ignored>();
  DT_Embers::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042A8B0
// Name: DT_QuadraticBeam::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_QuadraticBeam::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_QuadraticBeam::g_RecvTable);
  return atexit(func: DT_QuadraticBeam::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1042A8D0
// Name: DT_QuadraticBeam::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_QuadraticBeam::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_QuadraticBeam::ignored>();
  DT_QuadraticBeam::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10436380
// Name: DT_PrecipitationBlocker::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_PrecipitationBlocker::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_PrecipitationBlocker::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10436390
// Name: DT_Precipitation::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_Precipitation::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_Precipitation::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10436520
// Name: DT_EnvWindShared::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_EnvWindShared::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_EnvWindShared::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10436530
// Name: DT_EnvWind::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_EnvWind::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_EnvWind::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10436540
// Name: DT_Embers::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_Embers::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_Embers::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10436550
// Name: DT_QuadraticBeam::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_QuadraticBeam::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_QuadraticBeam::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x1023ECC0
// Name: _C_EnvWind_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_EnvWind_CreateObject(int entnum, int serialNum)
{
  C_BaseEntity *v2; // eax
  C_BaseEntity *v3; // esi

  v2 = (C_BaseEntity *)C_BaseEntity::operator new(stAllocateBlock: 0xB90u);
  v3 = v2;
  if ( v2 == nullptr )
    return nullptr;
  C_BaseEntity::C_BaseEntity(this: v2);
  v3->IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_BaseEntity_vtbl *)&C_EnvWind::`vftable'{for `IClientUnknown'};
  v3->IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_EnvWind::`vftable'{for `IClientRenderable'};
  v3->IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_EnvWind::`vftable'{for `IClientNetworkable'};
  v3->IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_EnvWind::`vftable'{for `IClientThinkable'};
  v3->IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_EnvWind::`vftable';
  CEnvWindShared::CEnvWindShared(this: (CEnvWindShared *)&v3[1]);
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v3->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x102400E0
// Name: _C_QuadraticBeam_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_QuadraticBeam_CreateObject(int entnum, int serialNum)
{
  C_BaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_BaseEntity *)C_BaseEntity::operator new(stAllocateBlock: 0x9A0u);
  v3 = &v2->IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_BaseEntity::C_BaseEntity(this: v2);
  *v3 = &C_QuadraticBeam::`vftable'{for `IClientUnknown'};
  v3[1] = &C_QuadraticBeam::`vftable'{for `IClientRenderable'};
  v3[2] = &C_QuadraticBeam::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_QuadraticBeam::`vftable'{for `IClientThinkable'};
  v3[4] = &C_QuadraticBeam::`vftable';
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x10242D70
// Name: _CClient_Precipitation_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl CClient_Precipitation_CreateObject(int entnum, int serialNum)
{
  CClient_Precipitation *v2; // eax
  CClient_Precipitation *v3; // eax
  CClient_Precipitation *v4; // esi

  v2 = (CClient_Precipitation *)C_BaseEntity::operator new(stAllocateBlock: 0xA50u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = CClient_Precipitation::CClient_Precipitation(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x1042A250
// Name: _dynamic_initializer_for__g_RayTraceEnvironments__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_RayTraceEnvironments__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_RayTraceEnvironments__);
}

//------------------------------------------------------------------------------
// Address: 0x1042A260
// Name: _dynamic_initializer_for____g_C_PrecipitationBlockerClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_PrecipitationBlockerClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_PrecipitationBlockerClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_PrecipitationBlockerClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042A2B0
// Name: _dynamic_initializer_for__g_PrecipitationBlockers__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_PrecipitationBlockers__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_PrecipitationBlockers__);
}

//------------------------------------------------------------------------------
// Address: 0x1042A2C0
// Name: _dynamic_initializer_for____g_CClient_PrecipitationClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_CClient_PrecipitationClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_CClient_PrecipitationClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_CClient_PrecipitationClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042A310
// Name: _dynamic_initializer_for__r_SnowEnable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_SnowEnable__()
{
  ConVar::ConVar(
    this: &r_SnowEnable,
    pName: "r_SnowEnable",
    pDefaultValue: "1",
    flags: 0x4000,
    pHelpString: "Snow Enable");
  return atexit(func: dynamic_atexit_destructor_for__r_SnowEnable__);
}

//------------------------------------------------------------------------------
// Address: 0x1042A340
// Name: _dynamic_initializer_for__r_SnowParticles__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_SnowParticles__()
{
  ConVar::ConVar(
    this: &r_SnowParticles,
    pName: "r_SnowParticles",
    pDefaultValue: "500",
    flags: 0x4000,
    pHelpString: "Snow.");
  return atexit(func: dynamic_atexit_destructor_for__r_SnowParticles__);
}

//------------------------------------------------------------------------------
// Address: 0x1042A370
// Name: _dynamic_initializer_for__r_SnowInsideRadius__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_SnowInsideRadius__()
{
  ConVar::ConVar(
    this: &r_SnowInsideRadius,
    pName: "r_SnowInsideRadius",
    pDefaultValue: "256",
    flags: 0x4000,
    pHelpString: "Snow.");
  return atexit(func: dynamic_atexit_destructor_for__r_SnowInsideRadius__);
}

//------------------------------------------------------------------------------
// Address: 0x1042A3A0
// Name: _dynamic_initializer_for__r_SnowOutsideRadius__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_SnowOutsideRadius__()
{
  ConVar::ConVar(
    this: &r_SnowOutsideRadius,
    pName: "r_SnowOutsideRadius",
    pDefaultValue: "1024",
    flags: 0x4000,
    pHelpString: "Snow.");
  return atexit(func: dynamic_atexit_destructor_for__r_SnowOutsideRadius__);
}

//------------------------------------------------------------------------------
// Address: 0x1042A3D0
// Name: _dynamic_initializer_for__r_SnowSpeedScale__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_SnowSpeedScale__()
{
  ConVar::ConVar(
    this: &r_SnowSpeedScale,
    pName: "r_SnowSpeedScale",
    pDefaultValue: "1",
    flags: 0x4000,
    pHelpString: "Snow.");
  return atexit(func: dynamic_atexit_destructor_for__r_SnowSpeedScale__);
}

//------------------------------------------------------------------------------
// Address: 0x1042A400
// Name: _dynamic_initializer_for__r_SnowPosScale__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_SnowPosScale__()
{
  ConVar::ConVar(
    this: &r_SnowPosScale,
    pName: "r_SnowPosScale",
    pDefaultValue: "1",
    flags: 0x4000,
    pHelpString: "Snow.");
  return atexit(func: dynamic_atexit_destructor_for__r_SnowPosScale__);
}

//------------------------------------------------------------------------------
// Address: 0x1042A430
// Name: _dynamic_initializer_for__r_SnowFallSpeed__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_SnowFallSpeed__()
{
  ConVar::ConVar(
    this: &r_SnowFallSpeed,
    pName: "r_SnowFallSpeed",
    pDefaultValue: "1.5",
    flags: 0x4000,
    pHelpString: "Snow fall speed scale.");
  return atexit(func: dynamic_atexit_destructor_for__r_SnowFallSpeed__);
}

//------------------------------------------------------------------------------
// Address: 0x1042A460
// Name: _dynamic_initializer_for__r_SnowWindScale__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_SnowWindScale__()
{
  ConVar::ConVar(
    this: &r_SnowWindScale,
    pName: "r_SnowWindScale",
    pDefaultValue: "0.0035",
    flags: 0x4000,
    pHelpString: "Snow.");
  return atexit(func: dynamic_atexit_destructor_for__r_SnowWindScale__);
}

//------------------------------------------------------------------------------
// Address: 0x1042A490
// Name: _dynamic_initializer_for__r_SnowDebugBox__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_SnowDebugBox__()
{
  ConVar::ConVar(
    this: &r_SnowDebugBox,
    pName: "r_SnowDebugBox",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Snow Debug Boxes.");
  return atexit(func: dynamic_atexit_destructor_for__r_SnowDebugBox__);
}

//------------------------------------------------------------------------------
// Address: 0x1042A4C0
// Name: _dynamic_initializer_for__r_SnowZoomOffset__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_SnowZoomOffset__()
{
  ConVar::ConVar(
    this: &r_SnowZoomOffset,
    pName: "r_SnowZoomOffset",
    pDefaultValue: "384.0f",
    flags: 0x4000,
    pHelpString: "Snow.");
  return atexit(func: dynamic_atexit_destructor_for__r_SnowZoomOffset__);
}

//------------------------------------------------------------------------------
// Address: 0x1042A4F0
// Name: _dynamic_initializer_for__r_SnowZoomRadius__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_SnowZoomRadius__()
{
  ConVar::ConVar(
    this: &r_SnowZoomRadius,
    pName: "r_SnowZoomRadius",
    pDefaultValue: "512.0f",
    flags: 0x4000,
    pHelpString: "Snow.");
  return atexit(func: dynamic_atexit_destructor_for__r_SnowZoomRadius__);
}

//------------------------------------------------------------------------------
// Address: 0x1042A520
// Name: _dynamic_initializer_for__r_SnowStartAlpha__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_SnowStartAlpha__()
{
  ConVar::ConVar(
    this: &r_SnowStartAlpha,
    pName: "r_SnowStartAlpha",
    pDefaultValue: "25",
    flags: 0x4000,
    pHelpString: "Snow.");
  return atexit(func: dynamic_atexit_destructor_for__r_SnowStartAlpha__);
}

//------------------------------------------------------------------------------
// Address: 0x1042A550
// Name: _dynamic_initializer_for__r_SnowEndAlpha__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_SnowEndAlpha__()
{
  ConVar::ConVar(
    this: &r_SnowEndAlpha,
    pName: "r_SnowEndAlpha",
    pDefaultValue: "255",
    flags: 0x4000,
    pHelpString: "Snow.");
  return atexit(func: dynamic_atexit_destructor_for__r_SnowEndAlpha__);
}

//------------------------------------------------------------------------------
// Address: 0x1042A580
// Name: _dynamic_initializer_for__r_SnowStartSize__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_SnowStartSize__()
{
  ConVar::ConVar(
    this: &r_SnowStartSize,
    pName: "r_SnowStartSize",
    pDefaultValue: "1",
    flags: 0x4000,
    pHelpString: "Snow.");
  return atexit(func: dynamic_atexit_destructor_for__r_SnowStartSize__);
}

//------------------------------------------------------------------------------
// Address: 0x1042A5B0
// Name: _dynamic_initializer_for__r_SnowEndSize__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_SnowEndSize__()
{
  ConVar::ConVar(this: &r_SnowEndSize, pName: "r_SnowEndSize", pDefaultValue: "0", flags: 0x4000, pHelpString: "Snow.");
  return atexit(func: dynamic_atexit_destructor_for__r_SnowEndSize__);
}

//------------------------------------------------------------------------------
// Address: 0x1042A5E0
// Name: _dynamic_initializer_for__r_SnowRayLength__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_SnowRayLength__()
{
  ConVar::ConVar(
    this: &r_SnowRayLength,
    pName: "r_SnowRayLength",
    pDefaultValue: "8192.0f",
    flags: 0x4000,
    pHelpString: "Snow.");
  return atexit(func: dynamic_atexit_destructor_for__r_SnowRayLength__);
}

//------------------------------------------------------------------------------
// Address: 0x1042A610
// Name: _dynamic_initializer_for__r_SnowRayRadius__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_SnowRayRadius__()
{
  ConVar::ConVar(
    this: &r_SnowRayRadius,
    pName: "r_SnowRayRadius",
    pDefaultValue: "256",
    flags: 0x4000,
    pHelpString: "Snow.");
  return atexit(func: dynamic_atexit_destructor_for__r_SnowRayRadius__);
}

//------------------------------------------------------------------------------
// Address: 0x1042A640
// Name: _dynamic_initializer_for__r_SnowRayEnable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_SnowRayEnable__()
{
  ConVar::ConVar(
    this: &r_SnowRayEnable,
    pName: "r_SnowRayEnable",
    pDefaultValue: "1",
    flags: 0x4000,
    pHelpString: "Snow.");
  return atexit(func: dynamic_atexit_destructor_for__r_SnowRayEnable__);
}

//------------------------------------------------------------------------------
// Address: 0x1042A670
// Name: _dynamic_initializer_for__CClient_Precipitation::s_raindensity__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__CClient_Precipitation::s_raindensity__()
{
  ConVar::ConVar(
    this: &CClient_Precipitation::s_raindensity,
    pName: "r_raindensity",
    pDefaultValue: "0.001",
    flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__CClient_Precipitation::s_raindensity__);
}

//------------------------------------------------------------------------------
// Address: 0x1042A6A0
// Name: _dynamic_initializer_for__CClient_Precipitation::s_rainwidth__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__CClient_Precipitation::s_rainwidth__()
{
  ConVar::ConVar(this: &CClient_Precipitation::s_rainwidth, pName: "r_rainwidth", pDefaultValue: "0.5", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__CClient_Precipitation::s_rainwidth__);
}

//------------------------------------------------------------------------------
// Address: 0x1042A6D0
// Name: _dynamic_initializer_for__CClient_Precipitation::s_rainlength__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__CClient_Precipitation::s_rainlength__()
{
  ConVar::ConVar(
    this: &CClient_Precipitation::s_rainlength,
    pName: "r_rainlength",
    pDefaultValue: "0.1f",
    flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__CClient_Precipitation::s_rainlength__);
}

//------------------------------------------------------------------------------
// Address: 0x1042A700
// Name: _dynamic_initializer_for__CClient_Precipitation::s_rainspeed__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__CClient_Precipitation::s_rainspeed__()
{
  ConVar::ConVar(
    this: &CClient_Precipitation::s_rainspeed,
    pName: "r_rainspeed",
    pDefaultValue: "600.0f",
    flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__CClient_Precipitation::s_rainspeed__);
}

//------------------------------------------------------------------------------
// Address: 0x1042A730
// Name: _dynamic_initializer_for__r_rainalpha__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_rainalpha__()
{
  ConVar::ConVar(this: &r_rainalpha, pName: "r_rainalpha", pDefaultValue: "0.4", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_rainalpha__);
}

//------------------------------------------------------------------------------
// Address: 0x1042A760
// Name: _dynamic_initializer_for__r_rainalphapow__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_rainalphapow__()
{
  ConVar::ConVar(this: &r_rainalphapow, pName: "r_rainalphapow", pDefaultValue: "0.8", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_rainalphapow__);
}

//------------------------------------------------------------------------------
// Address: 0x1042A790
// Name: _dynamic_initializer_for__g_PrecipHack__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_PrecipHack__()
{
  CAutoGameSystemPerFrame::CAutoGameSystemPerFrame(this: &g_PrecipHack, name: "CPrecipHack");
  g_PrecipHack.__vftable = (CPrecipHack_vtbl *)&CPrecipHack::`vftable';
  g_PrecipHack.m_bLevelInitted = false;
  return atexit(func: dynamic_atexit_destructor_for__g_PrecipHack__);
}

//------------------------------------------------------------------------------
// Address: 0x1042A7F0
// Name: _dynamic_initializer_for____g_C_EnvWindClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_EnvWindClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_EnvWindClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_EnvWindClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042A840
// Name: _dynamic_initializer_for____g_C_EmbersClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_EmbersClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_EmbersClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_EmbersClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042A890
// Name: _dynamic_initializer_for____g_C_QuadraticBeamClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_QuadraticBeamClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_QuadraticBeamClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_QuadraticBeamClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104363A0
// Name: _dynamic_atexit_destructor_for__r_SnowEnable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_SnowEnable__()
{
  ConVar::~ConVar(this: &r_SnowEnable);
}

//------------------------------------------------------------------------------
// Address: 0x104363B0
// Name: _dynamic_atexit_destructor_for__r_SnowParticles__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_SnowParticles__()
{
  ConVar::~ConVar(this: &r_SnowParticles);
}

//------------------------------------------------------------------------------
// Address: 0x104363C0
// Name: _dynamic_atexit_destructor_for__r_SnowInsideRadius__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_SnowInsideRadius__()
{
  ConVar::~ConVar(this: &r_SnowInsideRadius);
}

//------------------------------------------------------------------------------
// Address: 0x104363D0
// Name: _dynamic_atexit_destructor_for__r_SnowOutsideRadius__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_SnowOutsideRadius__()
{
  ConVar::~ConVar(this: &r_SnowOutsideRadius);
}

//------------------------------------------------------------------------------
// Address: 0x104363E0
// Name: _dynamic_atexit_destructor_for__r_SnowSpeedScale__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_SnowSpeedScale__()
{
  ConVar::~ConVar(this: &r_SnowSpeedScale);
}

//------------------------------------------------------------------------------
// Address: 0x104363F0
// Name: _dynamic_atexit_destructor_for__r_SnowPosScale__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_SnowPosScale__()
{
  ConVar::~ConVar(this: &r_SnowPosScale);
}

//------------------------------------------------------------------------------
// Address: 0x10436400
// Name: _dynamic_atexit_destructor_for__r_SnowFallSpeed__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_SnowFallSpeed__()
{
  ConVar::~ConVar(this: &r_SnowFallSpeed);
}

//------------------------------------------------------------------------------
// Address: 0x10436410
// Name: _dynamic_atexit_destructor_for__r_SnowWindScale__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_SnowWindScale__()
{
  ConVar::~ConVar(this: &r_SnowWindScale);
}

//------------------------------------------------------------------------------
// Address: 0x10436420
// Name: _dynamic_atexit_destructor_for__r_SnowDebugBox__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_SnowDebugBox__()
{
  ConVar::~ConVar(this: &r_SnowDebugBox);
}

//------------------------------------------------------------------------------
// Address: 0x10436430
// Name: _dynamic_atexit_destructor_for__r_SnowZoomOffset__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_SnowZoomOffset__()
{
  ConVar::~ConVar(this: &r_SnowZoomOffset);
}

//------------------------------------------------------------------------------
// Address: 0x10436440
// Name: _dynamic_atexit_destructor_for__r_SnowZoomRadius__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_SnowZoomRadius__()
{
  ConVar::~ConVar(this: &r_SnowZoomRadius);
}

//------------------------------------------------------------------------------
// Address: 0x10436450
// Name: _dynamic_atexit_destructor_for__r_SnowStartAlpha__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_SnowStartAlpha__()
{
  ConVar::~ConVar(this: &r_SnowStartAlpha);
}

//------------------------------------------------------------------------------
// Address: 0x10436460
// Name: _dynamic_atexit_destructor_for__r_SnowEndAlpha__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_SnowEndAlpha__()
{
  ConVar::~ConVar(this: &r_SnowEndAlpha);
}

//------------------------------------------------------------------------------
// Address: 0x10436470
// Name: _dynamic_atexit_destructor_for__r_SnowStartSize__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_SnowStartSize__()
{
  ConVar::~ConVar(this: &r_SnowStartSize);
}

//------------------------------------------------------------------------------
// Address: 0x10436480
// Name: _dynamic_atexit_destructor_for__r_SnowEndSize__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_SnowEndSize__()
{
  ConVar::~ConVar(this: &r_SnowEndSize);
}

//------------------------------------------------------------------------------
// Address: 0x10436490
// Name: _dynamic_atexit_destructor_for__r_SnowRayLength__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_SnowRayLength__()
{
  ConVar::~ConVar(this: &r_SnowRayLength);
}

//------------------------------------------------------------------------------
// Address: 0x104364A0
// Name: _dynamic_atexit_destructor_for__r_SnowRayRadius__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_SnowRayRadius__()
{
  ConVar::~ConVar(this: &r_SnowRayRadius);
}

//------------------------------------------------------------------------------
// Address: 0x104364B0
// Name: _dynamic_atexit_destructor_for__r_SnowRayEnable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_SnowRayEnable__()
{
  ConVar::~ConVar(this: &r_SnowRayEnable);
}

//------------------------------------------------------------------------------
// Address: 0x104364C0
// Name: _dynamic_atexit_destructor_for__CClient_Precipitation::s_raindensity__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CClient_Precipitation::s_raindensity__()
{
  ConVar::~ConVar(this: &CClient_Precipitation::s_raindensity);
}

//------------------------------------------------------------------------------
// Address: 0x104364D0
// Name: _dynamic_atexit_destructor_for__CClient_Precipitation::s_rainwidth__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CClient_Precipitation::s_rainwidth__()
{
  ConVar::~ConVar(this: &CClient_Precipitation::s_rainwidth);
}

//------------------------------------------------------------------------------
// Address: 0x104364E0
// Name: _dynamic_atexit_destructor_for__CClient_Precipitation::s_rainlength__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CClient_Precipitation::s_rainlength__()
{
  ConVar::~ConVar(this: &CClient_Precipitation::s_rainlength);
}

//------------------------------------------------------------------------------
// Address: 0x104364F0
// Name: _dynamic_atexit_destructor_for__CClient_Precipitation::s_rainspeed__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CClient_Precipitation::s_rainspeed__()
{
  ConVar::~ConVar(this: &CClient_Precipitation::s_rainspeed);
}

//------------------------------------------------------------------------------
// Address: 0x10436500
// Name: _dynamic_atexit_destructor_for__r_rainalpha__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_rainalpha__()
{
  ConVar::~ConVar(this: &r_rainalpha);
}

//------------------------------------------------------------------------------
// Address: 0x10436510
// Name: _dynamic_atexit_destructor_for__r_rainalphapow__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_rainalphapow__()
{
  ConVar::~ConVar(this: &r_rainalphapow);
}

//------------------------------------------------------------------------------
// Address: 0x10436560
// Name: _dynamic_atexit_destructor_for__g_PrecipHack__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_PrecipHack__()
{
  IGameSystemPerFrame::~IGameSystemPerFrame(this: &g_PrecipHack);
}

//------------------------------------------------------------------------------
// Address: 0x10436570
// Name: _dynamic_atexit_destructor_for__g_Precipitations___1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_Precipitations___1()
{
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_Precipitations_1);
}

//------------------------------------------------------------------------------
// Address: 0x10436580
// Name: _dynamic_atexit_destructor_for__g_RayTraceEnvironments__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_RayTraceEnvironments__()
{
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_RayTraceEnvironments);
}

//------------------------------------------------------------------------------
// Address: 0x10436590
// Name: _dynamic_atexit_destructor_for__g_PrecipitationBlockers__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_PrecipitationBlockers__()
{
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_PrecipitationBlockers);
}

//------------------------------------------------------------------------------
// Address: 0x104365A0
// Name: _dynamic_atexit_destructor_for__fx_drawimpactdebris__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fx_drawimpactdebris__()
{
  ConVar::~ConVar(this: &fx_drawimpactdebris);
}

//------------------------------------------------------------------------------
// Address: 0x104365B0
// Name: _dynamic_atexit_destructor_for__fx_drawimpactdust__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fx_drawimpactdust__()
{
  ConVar::~ConVar(this: &fx_drawimpactdust);
}
