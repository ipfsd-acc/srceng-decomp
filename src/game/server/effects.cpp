// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/effects.cpp
// Functions: 206
// ============================================================

#include "game\server\effects.h"

//------------------------------------------------------------------------------
// Address: 0x10048710
// Name: public: void CNetworkColor32Base<struct color32_s,class CBaseEntity::NetworkVar_m_clrRender>::Init(unsigned char,unsigned char,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkColor32Base<color32_s,CBaseEntity::NetworkVar_m_clrRender>::Init(
        CNetworkColor32Base<color32_s,CBaseEntity::NetworkVar_m_clrRender> *this,
        unsigned __int8 rVal,
        unsigned __int8 gVal,
        unsigned __int8 bVal)
{
  CNetworkColor32Base<color32_s,CBaseEntity::NetworkVar_m_clrRender> *v5; // eax
  CBaseEdict *v6; // ecx
  CNetworkColor32Base<color32_s,CBaseEntity::NetworkVar_m_clrRender> *v7; // eax
  CBaseEdict *v8; // ecx
  CNetworkColor32Base<color32_s,CBaseEntity::NetworkVar_m_clrRender> *v9; // eax
  CBaseEdict *v10; // ecx

  if ( this->m_Value.r != rVal )
  {
    v5 = this - 46;
    if ( *((_BYTE *)this - 100) != 0 )
    {
      v5[22].m_Value.r |= 1u;
    }
    else
    {
      v6 = (CBaseEdict *)v5[6];
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: v6, offset: 0xB8u);
    }
    this->m_Value.r = rVal;
  }
  if ( this->m_Value.g != gVal )
  {
    v7 = this - 46;
    if ( *((_BYTE *)this - 100) != 0 )
    {
      v7[22].m_Value.r |= 1u;
    }
    else
    {
      v8 = (CBaseEdict *)v7[6];
      if ( v8 != nullptr )
        CBaseEdict::StateChanged(this: v8, offset: 0xB8u);
    }
    this->m_Value.g = gVal;
  }
  if ( this->m_Value.b != bVal )
  {
    v9 = this - 46;
    if ( *((_BYTE *)this - 100) != 0 )
    {
      v9[22].m_Value.r |= 1u;
      this->m_Value.b = bVal;
    }
    else
    {
      v10 = (CBaseEdict *)v9[6];
      if ( v10 != nullptr )
        CBaseEdict::StateChanged(this: v10, offset: 0xB8u);
      this->m_Value.b = bVal;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10104CA0
// Name: public: virtual struct datamap_t __near * CBubbling::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CBubbling::GetDataDescMap(CBubbling *this)
{
  return &CBubbling::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10104CB0
// Name: public: virtual void CBubbling::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBubbling::Precache(CBubbling *this@<ecx>, bool (__cdecl *a2)(const char *)@<edi>)
{
  this->m_bubbleModel = CBaseEntity::PrecacheModel(a1: a2, name: "sprites/bubble.vmt", bPreload: true);
}

//------------------------------------------------------------------------------
// Address: 0x10104CD0
// Name: public: void CBubbling::InputDeactivate(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBubbling::InputDeactivate(CBubbling *this, inputdata_t *inputdata)
{
  this->m_state = 0;
  CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
  CBaseEntity::SetNextThink(this, thinkTime: -1.0, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10104D10
// Name: public: virtual struct datamap_t __near * CEnvTracer::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CEnvTracer::GetDataDescMap(CEnvTracer *this)
{
  return &CEnvTracer::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10104D20
// Name: protected: virtual struct datamap_t __near * CGibShooter::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CGibShooter::GetDataDescMap(CGibShooter *this)
{
  return &CGibShooter::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10104D30
// Name: public: virtual struct datamap_t __near * CEnvShooter::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CEnvShooter::GetDataDescMap(CEnvShooter *this)
{
  return &CEnvShooter::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10104D40
// Name: public: virtual struct datamap_t __near * CRotorWashShooter::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CRotorWashShooter::GetDataDescMap(CRotorWashShooter *this)
{
  return &CRotorWashShooter::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10104D50
// Name: public: virtual void CTestEffect::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CTestEffect::Precache(CTestEffect *this@<ecx>, bool (__cdecl *a2)(const char *)@<edi>)
{
  CBaseEntity::PrecacheModel(a1: a2, name: "sprites/lgtning.vmt", bPreload: true);
}

//------------------------------------------------------------------------------
// Address: 0x10104D60
// Name: public: virtual void CTestEffect::Use(class CBaseEntity __near *,class CBaseEntity __near *,enum USE_TYPE,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTestEffect::Use(
        CTestEffect *this,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller,
        CBaseEntity *useType,
        float value)
{
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
  this->m_flStartTime = gpGlobals->curtime;
}

//------------------------------------------------------------------------------
// Address: 0x10104DA0
// Name: public: virtual struct datamap_t __near * CBlood::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CBlood::GetDataDescMap(CBlood *this)
{
  return &CBlood::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10104DB0
// Name: private: virtual struct datamap_t __near * CEnvFunnel::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CEnvFunnel::GetDataDescMap(CEnvFunnel *this)
{
  return &CEnvFunnel::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10104DC0
// Name: public: virtual void CEnvFunnel::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CEnvFunnel::Precache(CEnvFunnel *this@<ecx>, bool (__cdecl *a2)(const char *)@<edi>)
{
  this->m_iSprite = CBaseEntity::PrecacheModel(a1: a2, name: "sprites/flare6.vmt", bPreload: true);
}

//------------------------------------------------------------------------------
// Address: 0x10104DE0
// Name: public: virtual void CEnvBeverage::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CEnvBeverage::Precache(CEnvBeverage *this@<ecx>, bool (__cdecl *a2)(const char *)@<edi>)
{
  CBaseEntity::PrecacheModel(a1: a2, name: "models/can.mdl", bPreload: true);
}

//------------------------------------------------------------------------------
// Address: 0x10104DF0
// Name: public: virtual struct datamap_t __near * CEnvBeverage::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CEnvBeverage::GetDataDescMap(CEnvBeverage *this)
{
  return &CEnvBeverage::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10104E00
// Name: public: void CEnvBeverage::InputActivate(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvBeverage::InputActivate(CEnvBeverage *this, inputdata_t *inputdata)
{
  ((void (__stdcall *)(CBaseEntity *, CBaseEntity *, int, _DWORD))this->Use)(
    a1: inputdata->pActivator,
    a2: inputdata->pCaller,
    a3: 1,
    a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10104E30
// Name: public: virtual struct datamap_t __near * CItemSoda::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CItemSoda::GetDataDescMap(CItemSoda *this)
{
  return &CItemSoda::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10104E40
// Name: public: virtual void CItemSoda::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CItemSoda::Precache(CItemSoda *this@<ecx>, bool (__cdecl *a2)(const char *)@<edi>)
{
  CBaseEntity::PrecacheModel(a1: a2, name: "models/can.mdl", bPreload: true);
  CBaseEntity::PrecacheScriptSound(soundname: "ItemSoda.Bounce");
}

//------------------------------------------------------------------------------
// Address: 0x10104E60
// Name: public: virtual struct datamap_t __near * CPrecipitation::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CPrecipitation::GetDataDescMap(CPrecipitation *this)
{
  return &CPrecipitation::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10104E70
// Name: public: virtual class ServerClass __near * CPrecipitation::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CPrecipitation::GetServerClass(CPrecipitation *this)
{
  return &g_CPrecipitation_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x10104E80
// Name: public: virtual struct datamap_t __near * CPrecipitationBlocker::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CPrecipitationBlocker::GetDataDescMap(CPrecipitationBlocker *this)
{
  return &CPrecipitationBlocker::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10104E90
// Name: public: virtual class ServerClass __near * CPrecipitationBlocker::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CPrecipitationBlocker::GetServerClass(CPrecipitationBlocker *this)
{
  return &g_CPrecipitationBlocker_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x10104EA0
// Name: public: virtual struct datamap_t __near * CEnvWind::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CEnvWind::GetDataDescMap(CEnvWind *this)
{
  return &CEnvWind::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10104EB0
// Name: public: virtual class ServerClass __near * CEnvWind::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CEnvWind::GetServerClass(CEnvWind *this)
{
  return &g_CEnvWind_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x10104EC0
// Name: public: void CEnvWind::WindThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvWind::WindThink(CEnvWind *this)
{
  float flTime; // [esp+0h] [ebp-Ch]

  flTime = CEnvWindShared::WindThink(this: &this->m_EnvWindShared, flTime: gpGlobals->curtime);
  CBaseEntity::SetNextThink(this, thinkTime: flTime, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10104EF0
// Name: public: virtual struct datamap_t __near * CEmbers::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CEmbers::GetDataDescMap(CEmbers *this)
{
  return &CEmbers::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10104F00
// Name: public: virtual class ServerClass __near * CEmbers::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CEmbers::GetServerClass(CEmbers *this)
{
  return &g_CEmbers_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x10104F10
// Name: public: virtual struct datamap_t __near * CPhysicsWire::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CPhysicsWire::GetDataDescMap(CPhysicsWire *this)
{
  return &CPhysicsWire::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10104F40
// Name: public: virtual struct datamap_t __near * CEnvMuzzleFlash::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CEnvMuzzleFlash::GetDataDescMap(CEnvMuzzleFlash *this)
{
  return &CEnvMuzzleFlash::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10104F50
// Name: protected: virtual struct datamap_t __near * CEnvSplash::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CEnvSplash::GetDataDescMap(CEnvSplash *this)
{
  return &CEnvSplash::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10104F60
// Name: public: virtual void CEnvSplash::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvSplash::Spawn(CEnvSplash *this)
{
  this->Precache(this);
  CPointEntity::Spawn(this);
}

//------------------------------------------------------------------------------
// Address: 0x10104F80
// Name: public: virtual struct datamap_t __near * CEnvGunfire::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CEnvGunfire::GetDataDescMap(CEnvGunfire *this)
{
  return &CEnvGunfire::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10104F90
// Name: public: virtual void CEnvGunfire::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvGunfire::Precache(CEnvGunfire *this)
{
  const char *pszValue; // eax

  pszValue = this->m_iszShootSound.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  CBaseEntity::PrecacheScriptSound(soundname: pszValue);
}

//------------------------------------------------------------------------------
// Address: 0x10104FB0
// Name: public: void CEnvGunfire::InputDisable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvGunfire::InputDisable(CEnvGunfire *this, inputdata_t *inputdata)
{
  this->m_bDisabled = true;
  CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10104FD0
// Name: private: virtual struct datamap_t __near * CEnvQuadraticBeam::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CEnvQuadraticBeam::GetDataDescMap(CEnvQuadraticBeam *this)
{
  return &CEnvQuadraticBeam::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10104FE0
// Name: public: virtual class ServerClass __near * CEnvQuadraticBeam::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CEnvQuadraticBeam::GetServerClass(CEnvQuadraticBeam *this)
{
  return &g_CEnvQuadraticBeam_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x10104FF0
// Name: public: virtual void EffectsPrecachePrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall EffectsPrecachePrecache::CResourcePrecacher::Cache(
        EffectsPrecachePrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: GAMESOUND,
    a3: "Underwater.BulletImpact",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: GAMESOUND,
    a3: "FX_RicochetSound.Ricochet",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: GAMESOUND,
    a3: "Physics.WaterSplash",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: GAMESOUND,
    a3: "BaseExplosionEffect.Sound",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: GAMESOUND,
    a3: "Splash.SplashSound",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  if ( !bIgnoreConditionals && gpGlobals->maxClients > 1 )
    pPrecacheHandler->CacheResource(
      this: pPrecacheHandler,
      a2: GAMESOUND,
      a3: "HudChat.Message",
      a4: bPrecache,
      a5: hResourceList,
      a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10105090
// Name: private: virtual struct datamap_t __near * CEnvViewPunch::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CEnvViewPunch::GetDataDescMap(CEnvViewPunch *this)
{
  return &CEnvViewPunch::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101050A0
// Name: public: class CBaseEntity __near * CGib::GetSprite(void)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CGib::GetSprite(CGib *this)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_hSprite.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x101050D0
// Name: public: void CBubbling::InputSetCurrent(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBubbling::InputSetCurrent(CBubbling *this, inputdata_t *inputdata)
{
  if ( inputdata->value.fieldType == FIELD_INTEGER )
    this->m_flSpeed = (float)inputdata->value.iVal;
  else
    this->m_flSpeed = (float)0;
}

//------------------------------------------------------------------------------
// Address: 0x10105110
// Name: public: void CBubbling::InputSetDensity(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBubbling::InputSetDensity(CBubbling *this, inputdata_t *inputdata)
{
  if ( inputdata->value.fieldType == FIELD_INTEGER )
    this->m_density = inputdata->value.iVal;
  else
    this->m_density = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10105140
// Name: public: void CBubbling::InputSetFrequency(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBubbling::InputSetFrequency(CBubbling *this, inputdata_t *inputdata)
{
  int iVal; // eax
  bool v3; // zf

  if ( inputdata->value.fieldType == FIELD_INTEGER )
    iVal = inputdata->value.iVal;
  else
    iVal = 0;
  v3 = this->m_state == 0;
  this->m_frequency = iVal;
  if ( !v3 )
  {
    if ( iVal <= 19 )
      CBaseEntity::SetNextThink(
        this,
        thinkTime: (float)(gpGlobals->curtime + 2.5) - (double)iVal * 0.1,
        szContext: nullptr);
    else
      CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.5, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101051D0
// Name: public: void CBubbling::FizzThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBubbling::FizzThink(CBubbling *this)
{
  int m_frequency; // eax
  float thinkTime; // xmm0_4
  CPASFilter filter; // [esp+24h] [ebp-2Ch] BYREF
  Vector center; // [esp+44h] [ebp-Ch] BYREF

  center = *this->WorldSpaceCenter(this);
  CRecipientFilter::CRecipientFilter(this: &filter);
  filter.__vftable = (CPASFilter_vtbl *)&CPASFilter::`vftable';
  CRecipientFilter::AddRecipientsByPAS(this: &filter, origin: &center);
  ((void (__stdcall *)(CPASFilter *, _DWORD, CBubbling *, int, int, int))te->Fizz)(
    a1: &filter,
    a2: 0,
    a3: this,
    a4: this->m_bubbleModel,
    a5: this->m_density,
    a6: (int)this->m_flSpeed);
  m_frequency = this->m_frequency;
  if ( m_frequency <= 19 )
    thinkTime = (float)(gpGlobals->curtime + 2.5) - (double)m_frequency * 0.1;
  else
    thinkTime = gpGlobals->curtime + 0.5;
  CBaseEntity::SetNextThink(this, thinkTime, szContext: nullptr);
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x101052B0
// Name: public: virtual void CEnvTracer::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvTracer::Spawn(CEnvTracer *this)
{
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
  if ( this->m_flDelay == 0.0 )
    this->m_flDelay = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x10105300
// Name: public: void CEnvTracer::TracerThink(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CEnvTracer::TracerThink(CEnvTracer *this@<ecx>, int a2@<ebp>)
{
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2);
  UTIL_Tracer(
    vecStart: &this->m_vecAbsOrigin,
    vecEnd: &this->m_vecEnd,
    iEntIndex: 0,
    iAttachment: -1,
    flVelocity: 0.0,
    bWhiz: false,
    pCustomTracerName: nullptr,
    iParticleID: 0);
  CBaseEntity::SetNextThink(this, thinkTime: this->m_flDelay + gpGlobals->curtime, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10105370
// Name: public: virtual void CGibShooter::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CGibShooter::Precache(CGibShooter *this@<ecx>, bool (__cdecl *a2)(const char *)@<edi>)
{
  if ( g_Language.m_pParent != nullptr && g_Language.m_pParent->m_Value.m_nValue == 1 )
    this->m_iGibModelIndex = CBaseEntity::PrecacheModel(a1: a2, name: "models/germanygibs.mdl", bPreload: true);
  else
    this->m_iGibModelIndex = CBaseEntity::PrecacheModel(a1: a2, name: "models/gibs/hgibs.mdl", bPreload: true);
}

//------------------------------------------------------------------------------
// Address: 0x101053B0
// Name: public: virtual void CGibShooter::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGibShooter::Spawn(CGibShooter *this)
{
  int m_iGibModelIndex; // edx
  IVModelInfo_vtbl *v3; // edi
  const struct model_t *v4; // eax

  this->Precache(this);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
  CBaseEntity::AddEffects(this, nEffects: 32);
  if ( this->m_flDelay < 0.0 )
    this->m_flDelay = 0.0;
  if ( this->m_flGibLife == 0.0 )
    this->m_flGibLife = 25.0;
  m_iGibModelIndex = this->m_iGibModelIndex;
  this->m_iGibCapacity = this->m_iGibs;
  v3 = modelinfo->__vftable;
  v4 = modelinfo->GetModel(this: modelinfo, a2: m_iGibModelIndex);
  this->m_nMaxGibModelFrame = v3->GetModelFrameCount(this: modelinfo, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10105440
// Name: public: virtual bool CEnvShooter::KeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEnvShooter::KeyValue(CEnvShooter *this, const char *szKeyName, const char *szValue)
{
  const char *v4; // edi
  bool result; // al

  if ( szKeyName != "shootmodel" && _V_stricmp(s1: szKeyName, s2: "shootmodel") != 0 )
  {
    if ( szKeyName != "shootsounds" && _V_stricmp(s1: szKeyName, s2: "shootsounds") != 0 )
    {
      return CBaseEntity::KeyValue(this, szKeyName, szValue);
    }
    else
    {
      switch ( atoi(nptr: szValue) )
      {
        case 0:
          this->m_iGibMaterial = 0;
          result = true;
          break;
        case 1:
          this->m_iGibMaterial = 1;
          result = true;
          break;
        case 2:
          this->m_iGibMaterial = 2;
          result = true;
          break;
        case 3:
          this->m_iGibMaterial = 3;
          result = true;
          break;
        case 4:
          this->m_iGibMaterial = 8;
          result = true;
          break;
        default:
          this->m_iGibMaterial = 10;
          return true;
      }
    }
  }
  else
  {
    v4 = szValue;
    this->m_bIsSprite = false;
    this->m_ModelName.pszValue = *(const char **)AllocPooledString(pszValue: (const char *)&szValue).pszValue;
    CBaseEntity::DispatchUpdateTransmitState(this);
    if ( V_stristr(pStr: v4, pSearch: ".vmt") != nullptr )
    {
      this->m_bIsSprite = true;
      return true;
    }
    else
    {
      return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10105580
// Name: public: virtual void CEnvShooter::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CEnvShooter::Precache(CEnvShooter *this@<ecx>, bool (__cdecl *a2)(const char *)@<edi>)
{
  const char *v3; // eax
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  v3 = *(const char **)((int (__thiscall *)(CEnvShooter *, _BYTE *))this->GetModelName)(a1: this, a2: v4);
  if ( v3 == nullptr )
    v3 = locale;
  this->m_iGibModelIndex = CBaseEntity::PrecacheModel(a1: a2, name: v3, bPreload: true);
}

//------------------------------------------------------------------------------
// Address: 0x101055C0
// Name: public: virtual void CRotorWashShooter::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRotorWashShooter::Spawn(CRotorWashShooter *this)
{
  CGibShooter::Spawn(this);
  this->m_flLastWashStartTime = -1.0;
}

//------------------------------------------------------------------------------
// Address: 0x101055E0
// Name: public: virtual void CBlood::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBlood::Precache(CBlood *this)
{
  PrecacheEffect(pEffectName: "bloodspray");
}

//------------------------------------------------------------------------------
// Address: 0x101055F0
// Name: public: virtual void CBlood::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBlood::Spawn(CBlood *this)
{
  QAngle angSprayDir; // [esp+4h] [ebp-Ch] BYREF

  this->Precache(this);
  angSprayDir = (QAngle)this->m_vecSprayDir;
  AngleVectors(angles: &angSprayDir, forward: &this->m_vecSprayDir);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
  this->m_Color = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10105670
// Name: public: virtual bool CBlood::KeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBlood::KeyValue(CBlood *this, const char *szKeyName, const char *szValue)
{
  if ( szKeyName != "color" && _V_stricmp(s1: szKeyName, s2: "color") != 0 )
    return CServerOnlyPointEntity::KeyValue((CLogicalEntity *)this, szKeyName, szValue);
  if ( atoi(nptr: szValue) == 1 )
    this->m_Color = 1;
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x101056D0
// Name: void UTIL_BloodSpray(class Vector const __near &,class Vector const __near &,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_BloodSpray(const Vector *pos, const Vector *dir, int color, int amount, int flags)
{
  float z; // xmm0_4
  CEffectData data; // [esp+0h] [ebp-64h] BYREF

  if ( color != -1 )
  {
    memset((void *)&data.m_vStart, 0, sizeof(data.m_vStart));
    memset((void *)&data.m_vAngles, 0, sizeof(data.m_vAngles));
    memset(&data.m_flMagnitude, 0, 14);
    data.m_nEntIndex = 0;
    memset(&data.m_nMaterial, 0, 16);
    data.m_vOrigin = *pos;
    data.m_vNormal.x = dir->x;
    data.m_vNormal.y = dir->y;
    z = dir->z;
    data.m_nColor = color;
    data.m_vNormal.z = z;
    data.m_flScale = (float)amount;
    data.m_fFlags = flags;
    DispatchEffect(pName: "bloodspray", &data);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101057A0
// Name: public: virtual void CEnvFunnel::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvFunnel::Spawn(CEnvFunnel *this)
{
  this->Precache(this);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
  CBaseEntity::AddEffects(this, nEffects: 32);
}

//------------------------------------------------------------------------------
// Address: 0x101057D0
// Name: public: virtual bool CEnvBeverage::KeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEnvBeverage::KeyValue(CEnvBeverage *this, const char *szKeyName, const char *szValue)
{
  if ( szKeyName != "beveragetype" && _V_stricmp(s1: szKeyName, s2: "beveragetype") != 0 )
    return CBaseEntity::KeyValue(this, szKeyName, szValue);
  this->m_nBeverageType = atoi(nptr: szValue);
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x10105CA0
// Name: public: void CEnvMuzzleFlash::InputFire(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CEnvMuzzleFlash::InputFire(CEnvMuzzleFlash *this@<ecx>, int a2@<ebp>, inputdata_t *inputdata)
{
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2);
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2);
  ((void (__stdcall *)(Vector *, QAngle *, _DWORD, int))g_pEffects->MuzzleFlash)(
    a1: &this->m_vecAbsOrigin,
    a2: &this->m_angAbsRotation,
    a3: LODWORD(this->m_flScale),
    a4: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10105D00
// Name: public: virtual void CEnvSplash::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvSplash::Precache(CEnvSplash *this)
{
  PrecacheEffect(pEffectName: "watersplash");
}

//------------------------------------------------------------------------------
// Address: 0x10105D10
// Name: public: virtual void CEnvGunfire::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvGunfire::Activate(CEnvGunfire *this)
{
  const char *pszValue; // eax
  CBaseEntity *EntityByName; // eax

  pszValue = this->m_target.pszValue;
  if ( pszValue != nullptr )
  {
    EntityByName = CGlobalEntityList::FindEntityByName(
                     this: &gEntList,
                     pStartEntity: nullptr,
                     szName: pszValue,
                     pSearchingEntity: nullptr,
                     pActivator: nullptr,
                     pCaller: nullptr,
                     pFilter: nullptr);
    if ( EntityByName != nullptr )
    {
      this->m_hTarget.m_Index = EntityByName->GetRefEHandle(this: EntityByName)->m_Index;
      CBaseEntity::Activate(this);
      return;
    }
    this->m_hTarget.m_Index = -1;
  }
  CBaseEntity::Activate(this);
}

//------------------------------------------------------------------------------
// Address: 0x101060B0
// Name: public: void CBubbling::InputActivate(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBubbling::InputActivate(CBubbling *this, inputdata_t *inputdata)
{
  this->m_state = 1;
  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CBubbling::FizzThink,
    thinkTime: 0.0,
    szContext: nullptr);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10106100
// Name: public: virtual void CEnvTracer::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvTracer::Activate(CEnvTracer *this)
{
  const char *pszValue; // eax
  CBaseEntity *EntityByName; // eax
  const char *v4; // esi

  CBaseEntity::Activate(this);
  pszValue = this->m_target.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  EntityByName = CGlobalEntityList::FindEntityByName(
                   this: &gEntList,
                   pStartEntity: nullptr,
                   szName: pszValue,
                   pSearchingEntity: nullptr,
                   pActivator: nullptr,
                   pCaller: nullptr,
                   pFilter: nullptr);
  if ( EntityByName != nullptr )
  {
    this->m_vecEnd.x = EntityByName->m_vecOrigin.m_Value.x;
    this->m_vecEnd.y = EntityByName->m_vecOrigin.m_Value.y;
    this->m_vecEnd.z = EntityByName->m_vecOrigin.m_Value.z;
    CBaseEntity::ThinkSet(
      this,
      func: (void (__thiscall *)(CBaseEntity *))CEnvTracer::TracerThink,
      thinkTime: 0.0,
      szContext: nullptr);
    CBaseEntity::SetNextThink(this, thinkTime: this->m_flDelay + gpGlobals->curtime, szContext: nullptr);
  }
  else
  {
    v4 = this->m_target.pszValue;
    if ( v4 == nullptr )
      v4 = locale;
    _Msg(a1: "env_tracer: unknown entity \"%s\"\n", v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101061B0
// Name: public: class Vector CBlood::BloodPosition(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CBlood::BloodPosition(CBlood *this, Vector *result, CBasePlayer *pActivator)
{
  CBasePlayer *LocalPlayer; // esi
  float z; // ecx
  float *v7; // eax
  double v8; // st7
  Vector v9; // [esp+20h] [ebp-18h] BYREF
  float v10; // [esp+2Ch] [ebp-Ch]
  float v11; // [esp+30h] [ebp-8h]
  float v12; // [esp+34h] [ebp-4h]

  if ( (this->m_spawnflags.m_Value & 4) == 0 )
    goto LABEL_5;
  LocalPlayer = pActivator;
  if ( pActivator != nullptr && pActivator->IsPlayer(this: pActivator) )
  {
    if ( !pActivator->IsPlayer(this: pActivator) )
    {
LABEL_5:
      z = this->m_vecOrigin.m_Value.z;
      *(_QWORD *)&result->x = *(_QWORD *)&this->m_vecOrigin.m_Value.x;
      result->z = z;
      return result;
    }
  }
  else
  {
    LocalPlayer = UTIL_GetLocalPlayer();
  }
  if ( LocalPlayer == nullptr )
    goto LABEL_5;
  v10 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
          a1: random,
          a2: -1054867456,
          a3: 1092616192);
  v11 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
          a1: random,
          a2: -1054867456,
          a3: 1092616192);
  v12 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
          a1: random,
          a2: -1054867456,
          a3: 1092616192);
  v7 = (float *)LocalPlayer->EyePosition(this: LocalPlayer, result: &v9);
  result->x = v10 + *v7;
  result->y = v7[1] + v11;
  v8 = v7[2];
  result->z = v8 + v12;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101062E0
// Name: public: void CBlood::InputEmitBlood(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBlood::InputEmitBlood(CBlood *this, CBasePlayer **inputdata)
{
  unsigned int v3; // eax
  int m_Color; // edi
  float z; // edx
  CBasePlayer **v6; // edi
  Vector *v7; // eax
  float v8; // edx
  Vector *v9; // eax
  float v10; // eax
  float v11; // xmm3_4
  int m_Value; // eax
  int v13; // edi
  int v14; // ebx
  float v15; // eax
  int v16; // [esp-Ch] [ebp-8Ch]
  int v17; // [esp-Ch] [ebp-8Ch]
  int v18; // [esp-8h] [ebp-88h]
  int v19; // [esp-8h] [ebp-88h]
  CGameTrace tr; // [esp+4h] [ebp-7Ch] BYREF
  Vector result; // [esp+58h] [ebp-28h] BYREF
  Vector start; // [esp+64h] [ebp-1Ch] BYREF
  Vector forward; // [esp+70h] [ebp-10h] BYREF
  float m_flAmount; // [esp+7Ch] [ebp-4h]
  IHandleEntity savedregs; // [esp+80h] [ebp+0h] BYREF
  float inputdataa; // [esp+88h] [ebp+8h]

  v3 = (unsigned int)this->m_spawnflags.m_Value >> 1;
  m_Color = this->m_Color;
  m_flAmount = this->m_flAmount;
  if ( (v3 & 1) != 0 )
  {
    if ( (this->m_spawnflags.m_Value & 1) != 0 )
    {
      UTIL_RandomBloodVector(result: &start);
    }
    else
    {
      z = this->m_vecSprayDir.z;
      *(_QWORD *)&start.x = *(_QWORD *)&this->m_vecSprayDir.x;
      start.z = z;
    }
    v18 = (int)m_flAmount;
    v16 = m_Color;
    v6 = inputdata;
    v7 = CBlood::BloodPosition(this, &result, pActivator: *inputdata);
    UTIL_BloodStream(origin: v7, direction: &start, color: v16, amount: v18);
  }
  else
  {
    if ( (this->m_spawnflags.m_Value & 1) != 0 )
    {
      UTIL_RandomBloodVector(result: &start);
    }
    else
    {
      v8 = this->m_vecSprayDir.z;
      *(_QWORD *)&start.x = *(_QWORD *)&this->m_vecSprayDir.x;
      start.z = v8;
    }
    v19 = (int)m_flAmount;
    v17 = m_Color;
    v6 = inputdata;
    v9 = CBlood::BloodPosition(this, &result, pActivator: *inputdata);
    UTIL_BloodDrips(origin: v9, direction: &start, color: v17, amount: v19);
  }
  if ( (this->m_spawnflags.m_Value & 8) != 0 )
  {
    if ( (this->m_spawnflags.m_Value & 1) != 0 )
    {
      UTIL_RandomBloodVector(result: &forward);
    }
    else
    {
      v10 = this->m_vecSprayDir.z;
      *(_QWORD *)&forward.x = *(_QWORD *)&this->m_vecSprayDir.x;
      forward.z = v10;
    }
    CBlood::BloodPosition(this, result: &start, pActivator: *v6);
    v11 = this->m_flAmount;
    result.y = start.y + (float)((float)(forward.y * v11) * 2.0);
    result.x = start.x + (float)((float)(forward.x * v11) * 2.0);
    result.z = start.z + (float)((float)(forward.z * v11) * 2.0);
    UTIL_TraceLine(
      a1: &savedregs,
      a2: (int)this,
      vecAbsStart: &start,
      vecAbsEnd: &result,
      mask: 0x400Bu,
      ignore: nullptr,
      collisionGroup: 0,
      ptr: &tr);
    if ( tr.fraction != 1.0 )
      UTIL_BloodDecalTrace(pTrace: &tr, bloodColor: this->m_Color);
  }
  m_Value = this->m_spawnflags.m_Value;
  if ( (m_Value & 0x70) != 0 )
  {
    v13 = 0;
    if ( (m_Value & 0x10) != 0 )
      v13 = 4;
    if ( (m_Value & 0x20) != 0 )
      v13 |= 1u;
    if ( (m_Value & 0x40) != 0 )
      v13 |= 2u;
    v14 = this->m_Color;
    inputdataa = this->m_flAmount;
    if ( (this->m_spawnflags.m_Value & 1) != 0 )
    {
      UTIL_RandomBloodVector(&result);
    }
    else
    {
      v15 = this->m_vecSprayDir.z;
      *(_QWORD *)&result.x = *(_QWORD *)&this->m_vecSprayDir.x;
      result.z = v15;
    }
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    UTIL_BloodSpray(pos: &this->m_vecAbsOrigin, dir: &result, color: v14, amount: (int)inputdataa, flags: v13);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10106550
// Name: public: virtual void CEnvFunnel::Use(class CBaseEntity __near *,class CBaseEntity __near *,enum USE_TYPE,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvFunnel::Use(
        CEnvFunnel *this,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller,
        USE_TYPE useType,
        float value)
{
  char v6; // bl
  CBroadcastRecipientFilter filter; // [esp+24h] [ebp-20h] BYREF
  int savedregs; // [esp+44h] [ebp+0h] BYREF

  CRecipientFilter::CRecipientFilter(this: &filter);
  filter.__vftable = (CBroadcastRecipientFilter_vtbl *)&CBroadcastRecipientFilter::`vftable';
  CRecipientFilter::AddAllPlayers(this: &filter);
  v6 = this->m_spawnflags.m_Value & 1;
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  ((void (__stdcall *)(CBroadcastRecipientFilter *, _DWORD, Vector *, int, bool))te->LargeFunnel)(
    a1: &filter,
    a2: 0,
    a3: &this->m_vecAbsOrigin,
    a4: this->m_iSprite,
    a5: v6 != 0);
  CBaseEntity::ThinkSet(this, func: CBaseEntity::SUB_Remove, thinkTime: 0.0, szContext: nullptr);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x10106600
// Name: public: void CItemSoda::CanTouch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CItemSoda::CanTouch(CItemSoda *this, CBaseEntity *pOther)
{
  unsigned int m_Index; // ecx
  int v4; // eax
  CEntInfo *v5; // edx
  unsigned int v6; // ecx
  int v7; // eax
  bool v8; // zf
  CEntInfo *v9; // eax
  IHandleEntity *m_pEntity; // eax

  if ( pOther->IsPlayer(this: pOther) )
  {
    ((void (__thiscall *)(CBaseEntity *, int, _DWORD))pOther->TakeHealth)(a1: pOther, a2: 1065353216, a3: 0);
    m_Index = this->m_hOwnerEntity.m_Value.m_Index;
    if ( m_Index != -1 )
    {
      v4 = (unsigned __int16)m_Index;
      v5 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
      v6 = HIWORD(m_Index);
      if ( v5->m_SerialNumber == v6 && v5->m_pEntity != nullptr )
      {
        v7 = v4;
        v8 = g_pEntityList->m_EntPtrArray[v7].m_SerialNumber == v6;
        v9 = &g_pEntityList->m_EntPtrArray[v7];
        if ( v8 )
          m_pEntity = v9->m_pEntity;
        else
          m_pEntity = nullptr;
        LOBYTE(m_pEntity[213].__vftable) = 0;
      }
    }
    CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 4);
    CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
    CBaseEntity::AddEffects(this, nEffects: 32);
    this->m_pfnTouch = nullptr;
    CBaseEntity::ThinkSet(this, func: CBaseEntity::SUB_Remove, thinkTime: 0.0, szContext: nullptr);
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101067A0
// Name: public: virtual void CEnvWind::NetworkVar_m_EnvWindShared::NetworkStateChanged(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvWind::NetworkVar_m_EnvWindShared::NetworkStateChanged(
        CEnvWind::NetworkVar_m_EnvWindShared *this,
        void *pVar)
{
  char *v2; // eax
  CBaseEdict *v3; // ecx

  v2 = (char *)this - 852;
  if ( *((_BYTE *)this - 768) != 0 )
  {
    v2[88] |= 1u;
  }
  else
  {
    v3 = *((CBaseEdict **)v2 + 6);
    if ( v3 != nullptr )
      CBaseEdict::StateChanged(this: v3, offset: (_WORD)pVar - (_WORD)v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101067D0
// Name: public: virtual void CEnvMuzzleFlash::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvMuzzleFlash::Spawn(CEnvMuzzleFlash *this)
{
  unsigned int m_Index; // ecx
  int v3; // eax
  CEntInfo *v4; // edx
  unsigned int v5; // ecx
  int v6; // eax
  bool v7; // zf
  CEntInfo *v8; // eax
  IHandleEntity *v9; // eax
  CBaseEntity *Parent; // eax
  CBaseAnimating *v11; // eax
  const char *pszValue; // edx
  int v13; // eax
  CEnvMuzzleFlash_vtbl *v14; // edi
  CBaseEntity *v15; // eax
  int v16; // [esp-8h] [ebp-Ch]

  if ( this->m_iszParentAttachment.pszValue != nullptr )
  {
    m_Index = this->m_pParent.m_Index;
    if ( m_Index != -1 )
    {
      v3 = (unsigned __int16)m_Index;
      v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
      v5 = HIWORD(m_Index);
      if ( v4->m_SerialNumber == v5 && v4->m_pEntity != nullptr )
      {
        v6 = v3;
        v7 = g_pEntityList->m_EntPtrArray[v6].m_SerialNumber == v5;
        v8 = &g_pEntityList->m_EntPtrArray[v6];
        v9 = v7 ? v8->m_pEntity : nullptr;
        if ( v9->__vftable[17].GetRefEHandle(this: v9) != nullptr )
        {
          Parent = CBaseEntity::GetParent(this);
          v11 = Parent->GetBaseAnimating(this: Parent);
          pszValue = this->m_iszParentAttachment.pszValue;
          if ( pszValue == nullptr )
            pszValue = locale;
          v13 = CBaseAnimating::LookupAttachment(this: v11, szName: pszValue);
          if ( v13 != 0 )
          {
            v14 = this->__vftable;
            v16 = v13;
            v15 = CBaseEntity::GetParent(this);
            v14->SetParent(this, a2: v15, a3: v16);
            CBaseEntity::SetLocalOrigin(this, origin: &vec3_origin);
            CBaseEntity::SetLocalAngles(this, angles: &vec3_angle);
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101068A0
// Name: public: void CEnvSplash::InputSplash(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvSplash::InputSplash(CEnvSplash *this, inputdata_t *inputdata)
{
  bool v3; // zf
  float m_flScale; // xmm1_4
  int m_iEFlags; // edx
  float x; // xmm2_4
  float y; // xmm3_4
  float z; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  CGameTrace tr; // [esp+0h] [ebp-C8h] BYREF
  CEffectData data; // [esp+54h] [ebp-74h] BYREF
  Vector vecAbsEnd; // [esp+B8h] [ebp-10h] BYREF
  float scale; // [esp+C4h] [ebp-4h]
  IHandleEntity savedregs; // [esp+C8h] [ebp+0h] BYREF

  v3 = (this->m_spawnflags.m_Value & 1) == 0;
  data.m_flScale = 1.0;
  m_flScale = this->m_flScale;
  memset(&data, 0, 56);
  memset(&data.m_flMagnitude, 0, 14);
  memset(&data.m_nMaterial, 0, 17);
  scale = m_flScale;
  if ( v3 )
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    x = this->m_vecAbsOrigin.x;
    y = this->m_vecAbsOrigin.y;
    z = this->m_vecAbsOrigin.z;
    data.m_vOrigin.x = x;
    data.m_vOrigin.y = y;
    data.m_vOrigin.z = z;
  }
  else
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    if ( (enginetrace->GetPointContents(this: enginetrace, a2: &this->m_vecAbsOrigin, a3: 16432, a4: nullptr) & 0x4030) != 0 )
      return;
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    m_iEFlags = this->m_iEFlags;
    vecAbsEnd.x = this->m_vecAbsOrigin.x;
    vecAbsEnd.y = this->m_vecAbsOrigin.y;
    vecAbsEnd.z = this->m_vecAbsOrigin.z - 4096.0;
    if ( (m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    UTIL_TraceLine(
      a1: &savedregs,
      a2: (int)this,
      vecAbsStart: &this->m_vecAbsOrigin,
      &vecAbsEnd,
      mask: 0x403Bu,
      ignore: this,
      collisionGroup: 0,
      ptr: &tr);
    x = tr.endpos.x;
    y = tr.endpos.y;
    z = tr.endpos.z;
    data.m_vOrigin = tr.endpos;
    if ( (tr.contents & 0x10) != 0 )
      data.m_fFlags |= 1u;
  }
  if ( (this->m_spawnflags.m_Value & 2) != 0 )
  {
    vecAbsEnd.x = x;
    vecAbsEnd.y = y;
    vecAbsEnd.z = z - 4096.0;
    UTIL_TraceLine(
      a1: &savedregs,
      a2: (int)this,
      vecAbsStart: &data.m_vOrigin,
      &vecAbsEnd,
      mask: 0x400Bu,
      ignore: this,
      collisionGroup: 0,
      ptr: &tr);
    v9 = 1.0 - (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(tr.startpos.z - tr.endpos.z) & _mask__AbsFloat_) * 0.0083333338);
    if ( v9 < 0.1 )
      return;
    v10 = v9 * scale;
  }
  else
  {
    v10 = scale;
  }
  data.m_vNormal.x = 0.0;
  data.m_vNormal.y = 0.0;
  data.m_vNormal.z = 1.0;
  data.m_flScale = v10;
  DispatchEffect(pName: "watersplash", &data);
}

//------------------------------------------------------------------------------
// Address: 0x10106B30
// Name: public: void CEnvGunfire::UpdateTarget(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CEnvGunfire::UpdateTarget(CEnvGunfire *this@<ecx>, int a2@<ebp>)
{
  unsigned int m_Index; // ecx
  int v4; // eax
  CEntInfo *v5; // edx
  unsigned int v6; // ecx
  int v7; // eax
  bool v8; // zf
  CEntInfo *v9; // eax
  IHandleEntity *v10; // ecx
  float *v11; // eax
  unsigned int v12; // eax
  IHandleEntity *m_pEntity; // ecx
  float *v14; // eax
  float v15; // xmm0_4
  _DWORD v16[3]; // [esp+0h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+Ch] [ebp+0h]

  v16[0] = a2;
  v16[1] = retaddr;
  m_Index = this->m_hTarget.m_Index;
  if ( m_Index != -1 )
  {
    v4 = (unsigned __int16)m_Index;
    v5 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v6 = HIWORD(m_Index);
    if ( v5->m_SerialNumber == v6 && v5->m_pEntity != nullptr )
    {
      v7 = v4;
      v8 = g_pEntityList->m_EntPtrArray[v7].m_SerialNumber == v6;
      v9 = &g_pEntityList->m_EntPtrArray[v7];
      v10 = v8 ? v9->m_pEntity : nullptr;
      v11 = (float *)((int (__thiscall *)(IHandleEntity *))v10->__vftable[49].dtr_IHandleEntity)(a1: v10);
      if ( this->m_vecTargetPosition.x != *v11
        || this->m_vecTargetPosition.y != v11[1]
        || this->m_vecTargetPosition.z != v11[2] )
      {
        v12 = this->m_hTarget.m_Index;
        if ( v12 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v12].m_SerialNumber != HIWORD(v12) )
          m_pEntity = nullptr;
        else
          m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v12].m_pEntity;
        v14 = (float *)((int (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[49].dtr_IHandleEntity)(a1: m_pEntity);
        this->m_vecTargetPosition.x = *v14;
        this->m_vecTargetPosition.y = v14[1];
        this->m_vecTargetPosition.z = v14[2];
        if ( (this->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this, a2: (int)v16);
        v15 = this->m_vecAbsOrigin.x - this->m_vecTargetPosition.x;
        this->m_flTargetDist = fsqrt(
                                 (float)((float)((float)(this->m_vecAbsOrigin.y - this->m_vecTargetPosition.y)
                                               * (float)(this->m_vecAbsOrigin.y - this->m_vecTargetPosition.y))
                                       + (float)((float)(this->m_vecAbsOrigin.z - this->m_vecTargetPosition.z)
                                               * (float)(this->m_vecAbsOrigin.z - this->m_vecTargetPosition.z)))
                               + (float)(v15 * v15));
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10106CB0
// Name: public: void CEnvGunfire::ShootThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvGunfire::ShootThink(CEnvGunfire *this)
{
  unsigned int m_Index; // eax
  Vector *p_m_vecAbsOrigin; // edi
  const Vector *v4; // eax
  bool v5; // zf
  float x; // xmm2_4
  float y; // xmm0_4
  float z; // xmm1_4
  unsigned int v9; // ecx
  int m_iEFlags; // edx
  float m_flTargetDist; // xmm3_4
  unsigned int v12; // eax
  float v13; // xmm4_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  const char *pszValue; // ebx
  const char *v17; // eax
  float thinkTime; // [esp+10h] [ebp-C4h]
  CGameTrace tr; // [esp+1Ch] [ebp-B8h] BYREF
  CShotManipulator manipulator; // [esp+70h] [ebp-64h] BYREF
  Vector vecAbsEnd; // [esp+A0h] [ebp-34h] BYREF
  Vector vecEnd; // [esp+B0h] [ebp-24h] BYREF
  Vector vecDir; // [esp+BCh] [ebp-18h] BYREF
  float v24; // [esp+C8h] [ebp-Ch]
  float v25; // [esp+CCh] [ebp-8h]
  float v26; // [esp+D0h] [ebp-4h]
  IHandleEntity savedregs; // [esp+D4h] [ebp+0h] BYREF

  m_Index = this->m_hTarget.m_Index;
  if ( m_Index == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
  {
    CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
  }
  CBaseEntity::SetNextThink(this, thinkTime: this->m_flRateOfFire + gpGlobals->curtime, szContext: nullptr);
  CEnvGunfire::UpdateTarget(this, a2: (int)&savedregs);
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  p_m_vecAbsOrigin = &this->m_vecAbsOrigin;
  vecDir.x = this->m_vecTargetPosition.x - this->m_vecAbsOrigin.x;
  vecDir.y = this->m_vecTargetPosition.y - this->m_vecAbsOrigin.y;
  vecDir.z = this->m_vecTargetPosition.z - this->m_vecAbsOrigin.z;
  VectorNormalize(vec: &vecDir);
  manipulator.m_vecShotDirection = vecDir;
  VectorVectors(forward: &manipulator.m_vecShotDirection, right: &manipulator.m_vecRight, up: &manipulator.m_vecUp);
  v4 = CShotManipulator::ApplySpread(this: &manipulator, vecSpread: &this->m_vecSpread, bias: this->m_flBias);
  v5 = !this->m_bCollide;
  x = v4->x;
  vecDir.x = v4->x;
  y = v4->y;
  vecDir.y = y;
  z = v4->z;
  vecDir.z = z;
  if ( v5 )
  {
    m_flTargetDist = this->m_flTargetDist;
    v12 = (unsigned int)this->m_iEFlags >> 11;
    v13 = m_flTargetDist * x;
    v24 = m_flTargetDist * x;
    v25 = y * m_flTargetDist;
    v26 = z * m_flTargetDist;
    if ( (v12 & 1) != 0 )
    {
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      v13 = v24;
    }
    v14 = this->m_vecAbsOrigin.y + v25;
    v15 = this->m_vecAbsOrigin.z + v26;
    vecEnd.x = p_m_vecAbsOrigin->x + v13;
    vecEnd.y = v14;
    vecEnd.z = v15;
  }
  else
  {
    v9 = (unsigned int)this->m_iEFlags >> 11;
    v24 = x * 8192.0;
    v25 = y * 8192.0;
    v26 = z * 8192.0;
    if ( (v9 & 1) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    m_iEFlags = this->m_iEFlags;
    vecAbsEnd.x = p_m_vecAbsOrigin->x + v24;
    vecAbsEnd.y = this->m_vecAbsOrigin.y + v25;
    vecAbsEnd.z = this->m_vecAbsOrigin.z + v26;
    if ( (m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    UTIL_TraceLine(
      a1: &savedregs,
      a2: (int)this,
      vecAbsStart: &this->m_vecAbsOrigin,
      &vecAbsEnd,
      mask: 0x46004003u,
      ignore: this,
      collisionGroup: 0,
      ptr: &tr);
    if ( tr.fraction != 1.0 )
      this->DoImpactEffect(this, a2: &tr, a3: 2);
    vecEnd = tr.endpos;
  }
  if ( this->m_iszTracerType.pszValue != nullptr )
  {
    pszValue = this->m_iszTracerType.pszValue;
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    UTIL_Tracer(
      vecStart: &this->m_vecAbsOrigin,
      &vecEnd,
      iEntIndex: 0,
      iAttachment: -1,
      flVelocity: 5000.0,
      bWhiz: true,
      pCustomTracerName: pszValue,
      iParticleID: 0);
  }
  else
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    UTIL_Tracer(
      vecStart: &this->m_vecAbsOrigin,
      &vecEnd,
      iEntIndex: 0,
      iAttachment: -1,
      flVelocity: 5000.0,
      bWhiz: true,
      pCustomTracerName: nullptr,
      iParticleID: 0);
  }
  v17 = this->m_iszShootSound.pszValue;
  if ( v17 == nullptr )
    v17 = locale;
  CBaseEntity::EmitSound(this, soundname: v17, soundtime: 0.0, duration: nullptr);
  v5 = this->m_iShotsRemaining-- == 1;
  if ( v5 )
  {
    CEnvGunfire::StartShooting(this);
    thinkTime = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, _DWORD))random->RandomFloat)(
                  a1: random,
                  a2: LODWORD(this->m_flMinBurstDelay),
                  a3: LODWORD(this->m_flMaxBurstDelay))
              + gpGlobals->curtime;
    CBaseEntity::SetNextThink(this, thinkTime, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10107060
// Name: public: virtual void CEnvViewPunch::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvViewPunch::Spawn(CEnvViewPunch *this)
{
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
  if ( (this->m_spawnflags.m_Value & 1) != 0 )
    this->m_flRadius = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x101070A0
// Name: private: void CEnvViewPunch::DoViewPunch(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvViewPunch::DoViewPunch(CEnvViewPunch *this)
{
  bool bAir; // [esp+Ch] [ebp-4h]
  int savedregs; // [esp+10h] [ebp+0h] BYREF

  bAir = (this->m_spawnflags.m_Value & 2) != 0;
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  UTIL_ViewPunch(center: &this->m_vecAbsOrigin, angPunch: this->m_angViewPunch, radius: this->m_flRadius, bInAir: bAir);
}

//------------------------------------------------------------------------------
// Address: 0x10107110
// Name: public: void CEnvViewPunch::InputViewPunch(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CEnvViewPunch::InputViewPunch(CEnvViewPunch *this, inputdata_t *inputdata)
{
  CEnvViewPunch::DoViewPunch(this);
}

//------------------------------------------------------------------------------
// Address: 0x10107570
// Name: private: void CBubbling::Toggle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBubbling::Toggle(CBubbling *this)
{
  if ( this->m_state != 0 )
  {
    this->m_state = 0;
    CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
    CBaseEntity::SetNextThink(this, thinkTime: -1.0, szContext: nullptr);
  }
  else
  {
    this->m_state = 1;
    CBaseEntity::ThinkSet(
      this,
      func: (void (__thiscall *)(CBaseEntity *))CBubbling::FizzThink,
      thinkTime: 0.0,
      szContext: nullptr);
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101075F0
// Name: public: void CBubbling::InputToggle(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CBubbling::InputToggle(CBubbling *this, inputdata_t *inputdata)
{
  CBubbling::Toggle(this);
}

//------------------------------------------------------------------------------
// Address: 0x10107600
// Name: public: virtual void CEnvBeverage::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvBeverage::Spawn(CEnvBeverage *this)
{
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_iHealth> *p_m_iHealth; // esi

  this->Precache(this);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
  CBaseEntity::AddEffects(this, nEffects: 32);
  this->m_CanInDispenser = false;
  p_m_iHealth = &this->m_iHealth;
  if ( p_m_iHealth->m_Value == 0 )
  {
    (*(void (__thiscall **)(CNetworkVarBase<int,CBaseEntity::NetworkVar_m_iHealth> *, CNetworkVarBase<int,CBaseEntity::NetworkVar_m_iHealth> *))(p_m_iHealth[-132].m_Value + 732))(
      a1: p_m_iHealth - 132,
      a2: p_m_iHealth);
    p_m_iHealth->m_Value = 10;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10107660
// Name: public: void CItemSoda::CanThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CItemSoda::CanThink(CItemSoda *this)
{
  Vector vecMin; // [esp+10h] [ebp-18h] BYREF
  Vector vecMax; // [esp+1Ch] [ebp-Ch] BYREF

  CBaseEntity::EmitSound(this, soundname: "ItemSoda.Bounce", soundtime: 0.0, duration: nullptr);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_BBOX);
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 8);
  vecMax.x = 8.0;
  vecMax.y = 8.0;
  vecMax.z = 8.0;
  vecMin.x = -8.0;
  vecMin.y = -8.0;
  vecMin.z = 0.0;
  UTIL_SetSize(pEnt: this, &vecMin, &vecMax);
  CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
  this->m_pfnTouch = (void (__thiscall *)(CBaseEntity *, CBaseEntity *))CItemSoda::CanTouch;
}

//------------------------------------------------------------------------------
// Address: 0x10107710
// Name: public: virtual void CEnvWind::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvWind::Spawn(CEnvWind *this)
{
  int v2; // ebx
  edict_t *m_pPev; // eax
  signed int v4; // eax

  this->Precache(this);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
  CBaseEntity::AddEffects(this, nEffects: 32);
  v2 = (int)(float)((float)(unsigned __int16)(int)(float)((float)this->m_EnvWindShared.m_iInitialWindDir.m_Value
                                                        * 182.04445)
                  * 0.0054931641);
  if ( this->m_EnvWindShared.m_iInitialWindDir.m_Value != v2 )
  {
    this->m_EnvWindShared.NetworkStateChanged(
      this: &this->m_EnvWindShared,
      a2: &this->m_EnvWindShared.m_iInitialWindDir);
    this->m_EnvWindShared.m_iInitialWindDir.m_Value = v2;
  }
  m_pPev = this->m_Network.m_pPev;
  if ( m_pPev != nullptr )
    v4 = m_pPev - gpGlobals->pEdicts;
  else
    v4 = 0;
  CEnvWindShared::Init(
    this: &this->m_EnvWindShared,
    nEntIndex: v4,
    iRandomSeed: 0,
    flTime: gpGlobals->curtime,
    iInitialWindYaw: (int)this->m_angRotation.m_Value.y,
    flInitialWindSpeed: 0.0);
  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CEnvWind::WindThink,
    thinkTime: 0.0,
    szContext: nullptr);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101077F0
// Name: public: void CEnvGunfire::StartShooting(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvGunfire::StartShooting(CEnvGunfire *this)
{
  this->m_iShotsRemaining = random->RandomInt(this: random, a2: this->m_iMinBurstSize, a3: this->m_iMaxBurstSize);
  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CEnvGunfire::ShootThink,
    thinkTime: 0.0,
    szContext: nullptr);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10107850
// Name: public: void CEnvGunfire::InputEnable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvGunfire::InputEnable(CEnvGunfire *this, inputdata_t *inputdata)
{
  int m_iMaxBurstSize; // edx

  m_iMaxBurstSize = this->m_iMaxBurstSize;
  this->m_bDisabled = false;
  this->m_iShotsRemaining = random->RandomInt(this: random, a2: this->m_iMinBurstSize, a3: m_iMaxBurstSize);
  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CEnvGunfire::ShootThink,
    thinkTime: 0.0,
    szContext: nullptr);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101078B0
// Name: public: struct color32_s const __near & CNetworkColor32Base<struct color32_s,class CBaseEntity::NetworkVar_m_clrRender>::operator=(class CNetworkColor32Base<struct color32_s,class CBaseEntity::NetworkVar_m_clrRender> const __near &)
// Source: json
//------------------------------------------------------------------------------
CNetworkColor32Base<color32_s,CBaseEntity::NetworkVar_m_clrRender> *__thiscall CNetworkColor32Base<color32_s,CBaseEntity::NetworkVar_m_clrRender>::operator=(
        CNetworkColor32Base<color32_s,CBaseEntity::NetworkVar_m_clrRender> *this,
        const CNetworkColor32Base<color32_s,CBaseEntity::NetworkVar_m_clrRender> *val)
{
  CNetworkColor32Base<color32_s,CBaseEntity::NetworkVar_m_clrRender> *v3; // eax
  CBaseEdict *v5; // ecx

  if ( this->m_Value.r != val->m_Value.r
    || this->m_Value.g != val->m_Value.g
    || this->m_Value.b != val->m_Value.b
    || this->m_Value.a != val->m_Value.a )
  {
    v3 = this - 46;
    if ( *((_BYTE *)this - 100) != 0 )
    {
      v3[22].m_Value.r |= 1u;
      *this = *val;
      return this;
    }
    v5 = (CBaseEdict *)v3[6];
    if ( v5 != nullptr )
      CBaseEdict::StateChanged(this: v5, offset: 0xB8u);
    *this = *val;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101079A0
// Name: public: void CSprite::SetAttachment(class CBaseEntity __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSprite::SetAttachment(CSprite *this, CBaseEntity *pEntity, int attachment)
{
  edict_t *m_pPev; // ecx

  if ( pEntity != nullptr )
  {
    CNetworkHandleBase<CBaseEntity,CEntityFlame::NetworkVar_m_hEntAttached>::Set(
      this: &this->m_hAttachedToEntity,
      val: pEntity);
    if ( this->m_nAttachment.m_Value != attachment )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x358u);
      }
      this->m_nAttachment.m_Value = attachment;
    }
    CBaseEntity::FollowEntity(this, pBaseEntity: pEntity, bBoneMerge: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10107A10
// Name: public: void CSprite::AnimateForTime(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSprite::AnimateForTime(CSprite *this, float framerate, float time)
{
  edict_t *m_pPev; // ecx

  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CSprite::AnimateUntilDead,
    thinkTime: 0.0,
    szContext: nullptr);
  if ( this->m_flSpriteFramerate.m_Value != framerate )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x35Cu);
    }
    this->m_flSpriteFramerate.m_Value = framerate;
  }
  this->m_flDieTime = gpGlobals->curtime + time;
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10107AB0
// Name: public: virtual class CGib __near * CGibShooter::CreateGib(void)
// Source: json
//------------------------------------------------------------------------------
CGib *__thiscall CGibShooter::CreateGib(CGibShooter *this)
{
  CBaseEntity *EntityByName; // eax
  CGib *v4; // edi
  int v5; // ebx
  CBaseEdict *v6; // ecx
  ConVarRef violence_hgibs; // [esp+Ch] [ebp-Ch] BYREF

  ConVarRef::ConVarRef(this: &violence_hgibs, pName: "violence_hgibs");
  if ( ConVarRef::IsValid(this: &violence_hgibs) && violence_hgibs.m_pConVarState->m_Value.m_nValue == 0 )
    return nullptr;
  EntityByName = CreateEntityByName(className: "gib", iForceEdictIndex: -1, bNotify: true);
  v4 = (CGib *)__RTDynamicCast(
                 inptr: EntityByName,
                 VfDelta: 0,
                 SrcType: &CBaseEntity `RTTI Type Descriptor',
                 TargetType: &CGib `RTTI Type Descriptor',
                 isReference: 0);
  if ( v4 == nullptr )
    _Warning(a1: "classname %s used to create wrong class type\n", "gib");
  CGib::Spawn(this: v4, szGibModel: "models/gibs/hgibs.mdl", flLifetime: 25.0);
  CGib::SetBloodColor(this: v4, nBloodColor: 0);
  if ( this->m_nMaxGibModelFrame <= 1 )
    _DevWarning(a1: 2, a2: "GibShooter Body is <= 1!\n");
  v5 = random->RandomInt(this: random, a2: 1, a3: this->m_nMaxGibModelFrame - 1);
  if ( v4->m_nBody.m_Value != v5 )
  {
    if ( v4->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&v4->m_Network + 76) |= 1u;
    }
    else
    {
      v6 = &v4->m_Network.m_pPev->CBaseEdict;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: v6, offset: 0x370u);
    }
    v4->m_nBody.m_Value = v5;
  }
  if ( this->m_iszLightingOrigin.pszValue != nullptr )
    CBaseAnimating::SetLightingOrigin(this: v4, strLightingOrigin: this->m_iszLightingOrigin);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10107BD0
// Name: public: virtual class CGib __near * CEnvShooter::CreateGib(void)
// Source: json
//------------------------------------------------------------------------------
CGib *__thiscall CEnvShooter::CreateGib(CEnvShooter *this)
{
  CBaseEntity *EntityByName; // eax
  CGib *v3; // esi
  const char *v4; // eax
  int m_nMaxGibModelFrame; // eax
  CBaseEdict *v6; // ecx
  CBaseEdict *v7; // ecx
  CEntityFlame *v8; // eax
  int bodyPart; // [esp+20h] [ebp-4h] BYREF

  EntityByName = CreateEntityByName(className: "gib", iForceEdictIndex: -1, bNotify: true);
  v3 = (CGib *)__RTDynamicCast(
                 inptr: EntityByName,
                 VfDelta: 0,
                 SrcType: &CBaseEntity `RTTI Type Descriptor',
                 TargetType: &CGib `RTTI Type Descriptor',
                 isReference: 0);
  if ( v3 == nullptr )
    _Warning(a1: "classname %s used to create wrong class type\n", "gib");
  if ( this->m_bIsSprite )
  {
    CGib::Spawn(this: v3, szGibModel: locale, flLifetime: 25.0);
  }
  else
  {
    v4 = *(const char **)((int (__thiscall *)(CEnvShooter *, int *))this->GetModelName)(a1: this, a2: &bodyPart);
    if ( v4 == nullptr )
      v4 = locale;
    CGib::Spawn(this: v3, szGibModel: v4, flLifetime: 25.0);
  }
  m_nMaxGibModelFrame = this->m_nMaxGibModelFrame;
  bodyPart = 0;
  if ( m_nMaxGibModelFrame > 1 )
    bodyPart = random->RandomInt(this: random, a2: 0, a3: m_nMaxGibModelFrame - 1);
  if ( v3->m_nBody.m_Value != bodyPart )
  {
    if ( v3->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&v3->m_Network + 76) |= 1u;
    }
    else
    {
      v6 = &v3->m_Network.m_pPev->CBaseEdict;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: v6, offset: 0x370u);
    }
    v3->m_nBody.m_Value = bodyPart;
  }
  CGib::SetBloodColor(this: v3, nBloodColor: -1);
  v3->m_material = this->m_iGibMaterial;
  v3->m_nRenderMode.m_Value = this->m_nRenderMode.m_Value;
  CNetworkColor32Base<color32_s,CBaseEntity::NetworkVar_m_clrRender>::operator=(
    this: &v3->m_clrRender,
    val: &this->m_clrRender);
  v3->m_nRenderFX.m_Value = this->m_nRenderFX.m_Value;
  if ( v3->m_nSkin.m_Value != this->m_nSkin )
  {
    if ( v3->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&v3->m_Network + 76) |= 1u;
    }
    else
    {
      v7 = &v3->m_Network.m_pPev->CBaseEdict;
      if ( v7 != nullptr )
        CBaseEdict::StateChanged(this: v7, offset: 0x36Cu);
    }
    v3->m_nSkin.m_Value = this->m_nSkin;
  }
  v3->m_lifeTime = this->m_flGibLife + gpGlobals->curtime;
  v3->m_flGravity = this->m_flGibGravityScale;
  if ( (this->m_spawnflags.m_Value & 2) != 0 )
  {
    v8 = CEntityFlame::Create(pTarget: v3, flLifetime: v3->m_lifeTime, flSize: 0.0, bUseHitboxes: true);
    if ( v8 != nullptr )
      v3->m_hFlame.m_Index = v8->GetRefEHandle(this: v8)->m_Index;
  }
  if ( this->m_iszLightingOrigin.pszValue != nullptr )
    CBaseAnimating::SetLightingOrigin(this: v3, strLightingOrigin: this->m_iszLightingOrigin);
  if ( this->m_bNoGibShadows )
    CBaseEntity::AddEffects(this: v3, nEffects: 16);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10107DE0
// Name: public: virtual void CEnvBeverage::Use(class CBaseEntity __near *,class CBaseEntity __near *,enum USE_TYPE,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvBeverage::Use(
        CEnvBeverage *this,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller,
        USE_TYPE useType,
        float value)
{
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_iHealth> *p_m_iHealth; // ebx
  CBaseEntity *v7; // eax
  CBaseEntity *v8; // esi
  int v9; // ebx
  CBaseEdict *v10; // ecx
  int v11; // esi
  CBaseEdict *v12; // ecx
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_iHealth> *v13; // [esp+4h] [ebp-4h]

  if ( !this->m_CanInDispenser )
  {
    p_m_iHealth = &this->m_iHealth;
    v13 = &this->m_iHealth;
    if ( this->m_iHealth.m_Value > 0 )
    {
      v7 = CBaseEntity::Create(
             szName: "item_sodacan",
             vecOrigin: &this->m_vecOrigin.m_Value,
             vecAngles: &this->m_angRotation.m_Value,
             pOwner: this);
      v8 = v7;
      if ( this->m_nBeverageType == 6 )
      {
        v9 = random->RandomInt(this: random, a2: 0, a3: 5);
        if ( v8[1].m_Network.m_pPev != (edict_t *)v9 )
        {
          if ( v8->m_Network.m_TimerEvent.m_bRegistered )
          {
            *((_BYTE *)&v8->m_Network + 76) |= 1u;
          }
          else
          {
            v10 = &v8->m_Network.m_pPev->CBaseEdict;
            if ( v10 != nullptr )
              CBaseEdict::StateChanged(this: v10, offset: 0x36Cu);
          }
          v8[1].m_Network.m_pPev = (edict_t *)v9;
        }
        p_m_iHealth = v13;
      }
      else if ( v7[1].m_Network.m_pPev != (edict_t *)this->m_nBeverageType )
      {
        if ( v7->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&v7->m_Network + 76) |= 1u;
          v7[1].m_Network.m_pPev = (edict_t *)this->m_nBeverageType;
        }
        else
        {
          v12 = &v7->m_Network.m_pPev->CBaseEdict;
          if ( v12 != nullptr )
            CBaseEdict::StateChanged(this: v12, offset: 0x36Cu);
          v8[1].m_Network.m_pPev = (edict_t *)this->m_nBeverageType;
        }
      }
      this->m_CanInDispenser = true;
      v11 = p_m_iHealth->m_Value - 1;
      if ( p_m_iHealth->m_Value != v11 )
      {
        (*(void (__thiscall **)(CNetworkVarBase<int,CBaseEntity::NetworkVar_m_iHealth> *, CNetworkVarBase<int,CBaseEntity::NetworkVar_m_iHealth> *))(p_m_iHealth[-132].m_Value + 732))(
          a1: p_m_iHealth - 132,
          a2: p_m_iHealth);
        p_m_iHealth->m_Value = v11;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10107F00
// Name: public: virtual void CItemSoda::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CItemSoda::Spawn(CItemSoda *this)
{
  Vector vecMin; // [esp+10h] [ebp-18h] BYREF
  Vector vecMax; // [esp+1Ch] [ebp-Ch] BYREF

  this->Precache(this);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_FLYGRAVITY, moveCollide: MOVECOLLIDE_DEFAULT);
  this->SetModel(this, a2: "models/can.mdl");
  memset((void *)&vecMax, 0, sizeof(vecMax));
  memset((void *)&vecMin, 0, sizeof(vecMin));
  UTIL_SetSize(pEnt: this, &vecMin, &vecMax);
  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CItemSoda::CanThink,
    thinkTime: 0.0,
    szContext: nullptr);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.5, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10107FB0
// Name: public: CPrecipitation::CPrecipitation(void)
// Source: json
//------------------------------------------------------------------------------
CPrecipitation *__thiscall CPrecipitation::CPrecipitation(CPrecipitation *this)
{
  CPrecipitation *result; // eax
  edict_t *m_pPev; // ecx

  CBaseEntity::CBaseEntity(this, bServerOnly: false);
  this->__vftable = (CPrecipitation_vtbl *)&CPrecipitation::`vftable';
  result = this;
  if ( this->m_nPrecipType.m_Value != PRECIPITATION_TYPE_RAIN )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_nPrecipType.m_Value = PRECIPITATION_TYPE_RAIN;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x354u);
      this->m_nPrecipType.m_Value = PRECIPITATION_TYPE_RAIN;
      return this;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10108010
// Name: public: virtual void CPrecipitation::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrecipitation::Spawn(CPrecipitation *this)
{
  const char *v2; // eax
  CBaseEntity::NetworkVar_m_Collision *p_m_Collision; // ecx
  PrecipitationType_t m_Value; // eax
  bool v5; // zf
  edict_t *m_pPev; // ecx
  edict_t *v7; // ecx
  _BYTE v8[4]; // [esp+4h] [ebp-4h] BYREF

  CBaseEntity::SetTransmitState(this, nFlag: 32);
  PrecacheMaterial(pMaterialName: "effects/fleck_ash1");
  PrecacheMaterial(pMaterialName: "effects/fleck_ash2");
  PrecacheMaterial(pMaterialName: "effects/fleck_ash3");
  PrecacheMaterial(pMaterialName: "effects/ember_swirling001");
  this->Precache(this);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
  v2 = *(const char **)((int (__thiscall *)(CPrecipitation *, _BYTE *))this->GetModelName)(a1: this, a2: v8);
  if ( v2 == nullptr )
    v2 = locale;
  this->SetModel(this, a2: v2);
  p_m_Collision = &this->m_Collision;
  if ( this->m_nPrecipType.m_Value == PRECIPITATION_TYPE_PARTICLERAIN )
  {
    CCollisionProperty::SetSolid(this: p_m_Collision, val: SOLID_VPHYSICS);
    CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 4);
    CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 0x40);
    CBaseEntity::VPhysicsInitStatic(this);
  }
  else
  {
    CCollisionProperty::SetSolid(this: p_m_Collision, val: SOLID_NONE);
  }
  m_Value = this->m_nPrecipType.m_Value;
  v5 = m_Value == PRECIPITATION_TYPE_RAIN;
  if ( m_Value >= PRECIPITATION_TYPE_RAIN )
  {
    if ( m_Value <= NUM_PRECIPITATION_TYPES )
      goto LABEL_15;
    v5 = m_Value == PRECIPITATION_TYPE_RAIN;
  }
  if ( !v5 )
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
    this->m_nPrecipType.m_Value = PRECIPITATION_TYPE_RAIN;
  }
LABEL_15:
  if ( this->m_nRenderMode.m_Value != 6 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_nRenderMode.m_Value = 6;
    }
    else
    {
      v7 = this->m_Network.m_pPev;
      if ( v7 != nullptr )
        CBaseEdict::StateChanged(this: &v7->CBaseEdict, offset: 0xB5u);
      this->m_nRenderMode.m_Value = 6;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10108160
// Name: public: virtual void CPrecipitationBlocker::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrecipitationBlocker::Spawn(CPrecipitationBlocker *this)
{
  const char *v2; // eax
  edict_t *m_pPev; // ecx
  _BYTE v4[4]; // [esp+4h] [ebp-4h] BYREF

  CBaseEntity::SetTransmitState(this, nFlag: 8);
  this->Precache(this);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
  v2 = *(const char **)((int (__thiscall *)(CPrecipitationBlocker *, _BYTE *))this->GetModelName)(a1: this, a2: v4);
  if ( v2 == nullptr )
    v2 = locale;
  this->SetModel(this, a2: v2);
  if ( this->m_nRenderMode.m_Value != 6 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_nRenderMode.m_Value = 6;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xB5u);
      this->m_nRenderMode.m_Value = 6;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10108200
// Name: public: void CEmbers::EmberUse(class CBaseEntity __near *,class CBaseEntity __near *,enum USE_TYPE,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEmbers::EmberUse(
        CEmbers *this,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller,
        USE_TYPE useType,
        float value)
{
  CNetworkVarBase<bool,CEmbers::NetworkVar_m_bEmit> *p_m_bEmit; // esi
  bool v6; // bl
  edict_t *v7; // ecx
  edict_t *m_pPev; // ecx
  edict_t *v9; // ecx

  if ( (this->m_spawnflags.m_Value & 2) == 0 )
    this->m_pfnUse = nullptr;
  p_m_bEmit = &this->m_bEmit;
  if ( useType != USE_OFF )
  {
    if ( useType == USE_ON )
    {
      if ( !p_m_bEmit->m_Value )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
          p_m_bEmit->m_Value = true;
        }
        else
        {
          m_pPev = this->m_Network.m_pPev;
          if ( m_pPev != nullptr )
            CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x360u);
          p_m_bEmit->m_Value = true;
        }
      }
    }
    else
    {
      if ( useType == USE_SET )
        v6 = (int)value != 0;
      else
        v6 = !p_m_bEmit->m_Value;
      if ( p_m_bEmit->m_Value != v6 )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
          p_m_bEmit->m_Value = v6;
        }
        else
        {
          v7 = this->m_Network.m_pPev;
          if ( v7 != nullptr )
            CBaseEdict::StateChanged(this: &v7->CBaseEdict, offset: 0x360u);
          p_m_bEmit->m_Value = v6;
        }
      }
    }
  }
  else if ( p_m_bEmit->m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_bEmit->m_Value = false;
    }
    else
    {
      v9 = this->m_Network.m_pPev;
      if ( v9 != nullptr )
        CBaseEdict::StateChanged(this: &v9->CBaseEdict, offset: 0x360u);
      p_m_bEmit->m_Value = false;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101082F0
// Name: public: virtual void CEnvGunfire::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvGunfire::Spawn(CEnvGunfire *this)
{
  float v2; // xmm0_4
  int v3; // eax
  float z; // xmm0_4

  this->Precache(this);
  v2 = 1.0 / this->m_flRateOfFire;
  v3 = this->m_iSpread - 1;
  this->m_iShotsRemaining = 0;
  this->m_flRateOfFire = v2;
  switch ( v3 )
  {
    case 0:
      z = 0.0087299999;
      goto LABEL_3;
    case 4:
      z = 0.043620002;
      goto LABEL_3;
    case 9:
      z = 0.087159999;
      goto LABEL_3;
    case 14:
      z = 0.13053;
LABEL_3:
      this->m_vecSpread.x = z;
      this->m_vecSpread.y = z;
      break;
    default:
      this->m_vecSpread.x = vec3_origin.x;
      this->m_vecSpread.y = vec3_origin.y;
      z = vec3_origin.z;
      break;
  }
  this->m_vecSpread.z = z;
  if ( !this->m_bDisabled )
  {
    this->m_iShotsRemaining = random->RandomInt(this: random, a2: this->m_iMinBurstSize, a3: this->m_iMaxBurstSize);
    CBaseEntity::ThinkSet(
      this,
      func: (void (__thiscall *)(CBaseEntity *))CEnvGunfire::ShootThink,
      thinkTime: 0.0,
      szContext: nullptr);
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10108420
// Name: public: virtual void CBubbling::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBubbling::Spawn(CBubbling *this)
{
  const char *v2; // eax
  edict_t *m_pPev; // ecx
  _BYTE v4[4]; // [esp+14h] [ebp-4h] BYREF

  this->Precache(this);
  v2 = *(const char **)((int (__thiscall *)(CBubbling *, _BYTE *))this->GetModelName)(a1: this, a2: v4);
  if ( v2 == nullptr )
    v2 = locale;
  this->SetModel(this, a2: v2);
  if ( this->m_clrRender.m_Value.a != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xB8u);
    }
    this->m_clrRender.m_Value.a = 0;
  }
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
  if ( (this->m_spawnflags.m_Value & 1) != 0 )
  {
    this->m_state = 0;
  }
  else
  {
    CBaseEntity::ThinkSet(
      this,
      func: (void (__thiscall *)(CBaseEntity *))CBubbling::FizzThink,
      thinkTime: 0.0,
      szContext: nullptr);
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 2.0, szContext: nullptr);
    this->m_state = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10108500
// Name: public: virtual void CEmbers::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEmbers::Spawn(CEmbers *this)
{
  const char *v2; // eax
  edict_t *m_pPev; // ecx
  edict_t *v4; // ecx
  bool v5; // zf
  bool v6; // bl
  edict_t *v7; // ecx
  _BYTE v8[4]; // [esp+Ch] [ebp-4h] BYREF

  this->Precache(this);
  v2 = *(const char **)((int (__thiscall *)(CEmbers *, _BYTE *))this->GetModelName)(a1: this, a2: v8);
  if ( v2 == nullptr )
    v2 = locale;
  this->SetModel(this, a2: v2);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
  if ( this->m_clrRender.m_Value.a != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xB8u);
    }
    this->m_clrRender.m_Value.a = 0;
  }
  if ( this->m_nRenderMode.m_Value != 2 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v4 = this->m_Network.m_pPev;
      if ( v4 != nullptr )
        CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0xB5u);
    }
    this->m_nRenderMode.m_Value = 2;
  }
  v5 = (this->m_spawnflags.m_Value & 1) == 0;
  this->m_pfnUse = (void (__thiscall *)(CBaseEntity *, CBaseEntity *, CBaseEntity *, USE_TYPE, float))CEmbers::EmberUse;
  v6 = !v5 || this->m_iName.m_Value.pszValue == nullptr;
  if ( this->m_bEmit.m_Value != v6 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_bEmit.m_Value = v6;
    }
    else
    {
      v7 = this->m_Network.m_pPev;
      if ( v7 != nullptr )
        CBaseEdict::StateChanged(this: &v7->CBaseEdict, offset: 0x360u);
      this->m_bEmit.m_Value = v6;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10108BE0
// Name: public: virtual void CTestEffect::Think(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTestEffect::Think(CTestEffect *this)
{
  bool v2; // cc
  float v3; // xmm0_4
  CBeam *v4; // edi
  float z; // edx
  CBaseEdict *v6; // ecx
  CBaseEdict *v7; // ecx
  float *m_flBeamTime; // ebx
  int v9; // edi
  int v10; // edx
  CBaseEdict *v11; // ecx
  float thinkTime; // xmm0_4
  int v13; // edi
  CBaseEntity **m_pBeam; // ebx
  CGameTrace tr; // [esp+2Ch] [ebp-8Ch] BYREF
  Vector vecAbsEnd; // [esp+80h] [ebp-38h] BYREF
  float v17; // [esp+8Ch] [ebp-2Ch]
  float v18; // [esp+90h] [ebp-28h]
  float t; // [esp+94h] [ebp-24h]
  Vector vecDir; // [esp+98h] [ebp-20h] BYREF
  Vector vecSrc; // [esp+A4h] [ebp-14h] BYREF
  int i; // [esp+B0h] [ebp-8h]
  char v23; // [esp+B4h] [ebp-4h]
  IHandleEntity savedregs; // [esp+B8h] [ebp+0h] BYREF

  v2 = this->m_iBeam < 24;
  v3 = gpGlobals->curtime - this->m_flStartTime;
  t = v3;
  if ( v2 )
  {
    v4 = CBeam::BeamCreate(pSpriteName: "sprites/lgtning.vmt", width: 10.0);
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    z = this->m_vecAbsOrigin.z;
    *(_QWORD *)&vecSrc.x = *(_QWORD *)&this->m_vecAbsOrigin.x;
    vecSrc.z = z;
    *(float *)&i = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                     a1: random,
                     a2: -1082130432,
                     a3: 1065353216);
    v18 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
            a1: random,
            a2: -1082130432,
            a3: 1065353216);
    v17 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
            a1: random,
            a2: -1082130432,
            a3: 1065353216);
    LODWORD(vecDir.x) = i;
    vecDir.y = v18;
    vecDir.z = v17;
    VectorNormalize(vec: &vecDir);
    vecAbsEnd.y = vecSrc.y + (float)(vecDir.y * 128.0);
    vecAbsEnd.x = vecSrc.x + (float)(vecDir.x * 128.0);
    vecAbsEnd.z = vecSrc.z + (float)(vecDir.z * 128.0);
    UTIL_TraceLine(
      a1: &savedregs,
      a2: (int)this,
      vecAbsStart: &vecSrc,
      &vecAbsEnd,
      mask: 0x400Bu,
      ignore: this,
      collisionGroup: 0,
      ptr: &tr);
    CBeam::PointsInit(this: v4, start: &vecSrc, end: &tr.endpos);
    CNetworkColor32Base<color32_s,CBaseEntity::NetworkVar_m_clrRender>::Init(
      this: &v4->m_clrRender,
      rVal: 0xFFu,
      gVal: 0xB4u,
      bVal: 0x64u);
    if ( v4->m_fWidth.m_Value != 10.0 )
    {
      if ( v4->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&v4->m_Network + 76) |= 1u;
      }
      else
      {
        v6 = &v4->m_Network.m_pPev->CBaseEdict;
        if ( v6 != nullptr )
          CBaseEdict::StateChanged(this: v6, offset: 0x3C4u);
      }
      v4->m_fWidth.m_Value = 10.0;
    }
    if ( v4->m_fSpeed.m_Value != 12.0 )
    {
      if ( v4->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&v4->m_Network + 76) |= 1u;
      }
      else
      {
        v7 = &v4->m_Network.m_pPev->CBaseEdict;
        if ( v7 != nullptr )
          CBaseEdict::StateChanged(this: v7, offset: 0x3DCu);
      }
      v4->m_fSpeed.m_Value = 12.0;
    }
    v3 = t;
    this->m_flBeamTime[this->m_iBeam] = gpGlobals->curtime;
    this->m_pBeam[this->m_iBeam++] = v4;
  }
  if ( v3 >= 3.0 )
  {
    v13 = 0;
    if ( this->m_iBeam > 0 )
    {
      m_pBeam = this->m_pBeam;
      do
      {
        UTIL_Remove(oldObj: *m_pBeam);
        ++v13;
        ++m_pBeam;
      }
      while ( v13 < this->m_iBeam );
    }
    thinkTime = -1.0;
    this->m_flStartTime = gpGlobals->curtime;
    this->m_iBeam = 0;
  }
  else
  {
    v2 = this->m_iBeam <= 0;
    *(float *)&i = 0.0;
    if ( !v2 )
    {
      m_flBeamTime = this->m_flBeamTime;
      do
      {
        v9 = *((_DWORD *)m_flBeamTime - 24);
        v10 = (int)(float)((float)((float)(gpGlobals->curtime - *m_flBeamTime)
                                 / (float)((float)(this->m_flStartTime + 3.0) - *m_flBeamTime))
                         * 255.0);
        v23 = v10;
        if ( *(_BYTE *)(v9 + 187) != (_BYTE)v10 )
        {
          if ( *(_BYTE *)(v9 + 84) != 0 )
          {
            *(_BYTE *)(v9 + 88) |= 1u;
          }
          else
          {
            v11 = *(CBaseEdict **)(v9 + 24);
            if ( v11 != nullptr )
            {
              CBaseEdict::StateChanged(this: v11, offset: 0xB8u);
              LOBYTE(v10) = v23;
            }
          }
          *(_BYTE *)(v9 + 187) = v10;
        }
        ++m_flBeamTime;
        ++i;
      }
      while ( i < this->m_iBeam );
    }
    thinkTime = gpGlobals->curtime + 0.1;
  }
  CBaseEntity::SetNextThink(this, thinkTime, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10109970
// Name: public: virtual void CEnvQuadraticBeam::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvQuadraticBeam::Spawn(CEnvQuadraticBeam *this)
{
  edict_t *m_pPev; // ecx

  CPointEntity::Spawn(this);
  if ( this->m_nRenderMode.m_Value != 5 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xB5u);
    }
    this->m_nRenderMode.m_Value = 5;
  }
  CNetworkColor32Base<color32_s,CBaseEntity::NetworkVar_m_clrRender>::Init(
    this: &this->m_clrRender,
    rVal: 0xFFu,
    gVal: 0xFFu,
    bVal: 0xFFu);
}

//------------------------------------------------------------------------------
// Address: 0x10109A50
// Name: public: void CSprite::SetTransparency(int,int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSprite::SetTransparency(
        CSprite *this,
        unsigned __int8 rendermode,
        unsigned __int8 r,
        unsigned __int8 g,
        unsigned __int8 b,
        int a,
        unsigned __int8 fx)
{
  edict_t *m_pPev; // ecx
  edict_t *v9; // ecx

  if ( this->m_nRenderMode.m_Value != rendermode )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xB5u);
    }
    this->m_nRenderMode.m_Value = rendermode;
  }
  CNetworkColor32Base<color32_s,CBaseEntity::NetworkVar_m_clrRender>::Init(
    this: &this->m_clrRender,
    rVal: r,
    gVal: g,
    bVal: b);
  CSprite::SetBrightness(this, brightness: a, time: 0.0);
  if ( this->m_nRenderFX.m_Value != fx )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_nRenderFX.m_Value = fx;
    }
    else
    {
      v9 = this->m_Network.m_pPev;
      if ( v9 != nullptr )
        CBaseEdict::StateChanged(this: &v9->CBaseEdict, offset: 0xB4u);
      this->m_nRenderFX.m_Value = fx;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10109B00
// Name: private: void CGibShooter::InitPointGib(class CGib __near *,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGibShooter::InitPointGib(CGibShooter *this, float pGib, float vecShootDir, float flSpeed)
{
  float v4; // esi
  double v6; // st7
  double NextThink; // st7
  float (__thiscall *RandomFloat)(IUniformRandomStream *, float, float); // eax
  float v9; // xmm0_4
  const char *v10; // eax
  CSprite *v11; // eax
  unsigned int v12; // eax
  CSprite **v13; // ecx
  CSprite *v14; // ebx
  QAngle angVel; // [esp+34h] [ebp-18h] BYREF
  Vector vecAbsVelocity; // [esp+40h] [ebp-Ch] BYREF
  int savedregs; // [esp+4Ch] [ebp+0h] BYREF

  v4 = pGib;
  if ( pGib != 0.0 )
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    CBaseEntity::SetLocalOrigin(this: (CBaseEntity *)LODWORD(v4), origin: &this->m_vecAbsOrigin);
    vecAbsVelocity.x = *(float *)LODWORD(vecShootDir) * flSpeed;
    vecAbsVelocity.y = *(float *)(LODWORD(vecShootDir) + 4) * flSpeed;
    vecAbsVelocity.z = *(float *)(LODWORD(vecShootDir) + 8) * flSpeed;
    CBaseEntity::SetAbsVelocity(this: (CBaseEntity *)LODWORD(v4), &vecAbsVelocity);
    pGib = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
             a1: random,
             a2: 1120403456,
             a3: 1128792064);
    v6 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
           a1: random,
           a2: 1120403456,
           a3: 1133903872);
    angVel.x = pGib;
    angVel.y = v6;
    angVel.z = 0.0;
    CBaseEntity::SetLocalAngularVelocity(this: (CBaseEntity *)LODWORD(v4), vecAngVelocity: &angVel);
    NextThink = CBaseEntity::GetNextThink(this: (CBaseEntity *)LODWORD(v4), szContext: nullptr);
    RandomFloat = random->RandomFloat;
    vecShootDir = NextThink - gpGlobals->curtime;
    pGib = ((double (__thiscall *)(IUniformRandomStream *, int, int))RandomFloat)(
             a1: random,
             a2: 1064514355,
             a3: 1065772646)
         * this->m_flGibLife;
    *(float *)(LODWORD(v4) + 1176) = pGib;
    if ( (this->m_spawnflags.m_Value & 4) != 0 )
    {
      CBaseEntity::SetNextThink(
        this: (CBaseEntity *)LODWORD(v4),
        thinkTime: gpGlobals->curtime + pGib,
        szContext: nullptr);
      CBaseEntity::ThinkSet(
        this: (CBaseEntity *)LODWORD(v4),
        func: (void (__thiscall *)(CBaseEntity *))CGib::DieThink,
        thinkTime: 0.0,
        szContext: nullptr);
    }
    v9 = *(float *)(LODWORD(v4) + 1176);
    if ( vecShootDir > v9 )
    {
      CBaseEntity::SetNextThink(
        this: (CBaseEntity *)LODWORD(v4),
        thinkTime: gpGlobals->curtime + v9,
        szContext: nullptr);
      *(_DWORD *)(LODWORD(v4) + 1176) = 0;
    }
    if ( this->m_bIsSprite )
    {
      if ( (*(_DWORD *)(LODWORD(v4) + 196) & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: (CBaseEntity *)LODWORD(v4), a2: (int)&savedregs);
      v10 = *(const char **)((int (__thiscall *)(CGibShooter *, float *))this->GetModelName)(a1: this, a2: &pGib);
      if ( v10 == nullptr )
        v10 = locale;
      v11 = CSprite::SpriteCreate(pSpriteName: v10, origin: (const Vector *)(LODWORD(v4) + 460), animate: false);
      if ( v11 != nullptr )
        *(_DWORD *)(LODWORD(v4) + 1196) = v11->GetRefEHandle(this: v11)->m_Index;
      else
        *(_DWORD *)(LODWORD(v4) + 1196) = -1;
      v12 = *(_DWORD *)(LODWORD(v4) + 1196);
      if ( v12 != -1 )
      {
        v13 = (CSprite **)&g_pEntityList->m_EntPtrArray[(unsigned __int16)v12];
        if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)v12].m_SerialNumber == HIWORD(v12) )
        {
          v14 = *v13;
          if ( *v13 != nullptr )
          {
            CSprite::SetAttachment(this: v14, pEntity: (CBaseEntity *)LODWORD(v4), attachment: 0);
            ((void (__thiscall *)(CSprite *, float))v14->SetOwnerEntity)(a1: v14, a2: COERCE_FLOAT(LODWORD(v4)));
            CSprite::SetScale(this: v14, scale: 1.0, time: 0.0);
            CSprite::SetTransparency(
              this: v14,
              rendermode: this->m_nRenderMode.m_Value,
              r: this->m_clrRender.m_Value.r,
              g: this->m_clrRender.m_Value.g,
              b: this->m_clrRender.m_Value.b,
              a: this->m_clrRender.m_Value.a,
              fx: this->m_nRenderFX.m_Value);
            CSprite::AnimateForTime(this: v14, framerate: 5.0, time: this->m_flGibLife + 1.0);
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10109E00
// Name: protected: class CBaseEntity __near * CGibShooter::SpawnGib(class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
CGib *__thiscall CGibShooter::SpawnGib(CGibShooter *this, const Vector *vecShootDir, float flSpeed)
{
  int m_nSimulationType; // eax
  int v5; // eax
  unsigned int v6; // eax
  float v7; // xmm1_4
  float v8; // xmm2_4
  const char *v9; // eax
  CGib *v11; // edi
  int v12; // eax
  IPhysicsObject *inited; // ebx
  void (__thiscall *AddVelocity)(IPhysicsObject *, const Vector *, const Vector *); // edx
  double v15; // st7
  float (__thiscall *GetMass)(IPhysicsObject *); // edx
  double v17; // st7
  void (__thiscall *ApplyTorqueCenter)(IPhysicsObject *, const Vector *); // edx
  CGib *v19; // edi
  Vector vVel; // [esp+38h] [ebp-1Ch] BYREF
  Vector torque; // [esp+44h] [ebp-10h] BYREF
  _BYTE v22[4]; // [esp+50h] [ebp-4h] BYREF
  int savedregs; // [esp+54h] [ebp+0h] BYREF
  float flSpeeda; // [esp+60h] [ebp+Ch]

  m_nSimulationType = this->m_nSimulationType;
  if ( m_nSimulationType == 0 )
  {
    v19 = this->CreateGib(this);
    if ( v19 != nullptr )
    {
      CBaseEntity::SetAbsAngles(this: v19, absAngles: &this->m_angGibRotation);
      CGibShooter::InitPointGib(this, pGib: *(float *)&v19, vecShootDir: *(float *)&vecShootDir, flSpeed);
      return v19;
    }
    return nullptr;
  }
  v5 = m_nSimulationType - 1;
  if ( v5 != 0 )
  {
    if ( v5 == 1 )
    {
      v6 = (unsigned int)this->m_iEFlags >> 11;
      v7 = (float)(vecShootDir->y * flSpeed) * 200.0;
      v8 = (float)(vecShootDir->z * flSpeed) * 200.0;
      torque.x = (float)(vecShootDir->x * flSpeed) * 200.0;
      torque.y = v7;
      torque.z = v8;
      if ( (v6 & 1) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      v9 = *(const char **)((int (__thiscall *)(CGibShooter *, _BYTE *))this->GetModelName)(a1: this, a2: v22);
      if ( v9 == nullptr )
        v9 = locale;
      return (CGib *)CreateRagGib(
                       szModel: v9,
                       vecOrigin: &this->m_vecAbsOrigin,
                       vecAngles: &this->m_angAbsRotation,
                       vecForce: &torque,
                       flFadeTime: this->m_flGibLife,
                       bShouldIgnite: false);
    }
    return nullptr;
  }
  v11 = this->CreateGib(this);
  if ( v11 != nullptr )
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    CBaseEntity::SetAbsOrigin(this: v11, absOrigin: &this->m_vecAbsOrigin);
    CBaseEntity::SetAbsAngles(this: v11, absAngles: &this->m_angGibRotation);
    v11->m_lifeTime = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                        a1: random,
                        a2: 1064514355,
                        a3: 1065772646)
                    * this->m_flGibLife;
    CBaseEntity::SetCollisionGroup(this: v11, collisionGroup: 1);
    v12 = v11->m_Collision.GetSolidFlags(this: &v11->m_Collision);
    inited = CBaseEntity::VPhysicsInitNormal(
               this: v11,
               solidType: SOLID_VPHYSICS,
               nSolidFlags: v12,
               createAsleep: false,
               pSolid: nullptr);
    CBaseEntity::SetMoveType(this: v11, val: MOVETYPE_VPHYSICS, moveCollide: MOVECOLLIDE_DEFAULT);
    if ( inited != nullptr )
    {
      vVel.x = vecShootDir->x * flSpeed;
      vVel.y = vecShootDir->y * flSpeed;
      AddVelocity = inited->AddVelocity;
      vVel.z = vecShootDir->z * flSpeed;
      AddVelocity(this: inited, a2: &vVel, a3: nullptr);
      torque.x = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                   a1: random,
                   a2: 1036831949,
                   a3: 1065353216)
               * this->m_flGibAngVelocity;
      v15 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
              a1: random,
              a2: 1036831949,
              a3: 1065353216);
      GetMass = inited->GetMass;
      torque.y = v15 * this->m_flGibAngVelocity;
      torque.z = 0.0;
      v17 = ((double (__thiscall *)(IPhysicsObject *))GetMass)(a1: inited);
      flSpeeda = v17;
      ApplyTorqueCenter = inited->ApplyTorqueCenter;
      torque.x = torque.x * v17;
      torque.z = flSpeeda * torque.z;
      torque.y = v17 * torque.y;
      ApplyTorqueCenter(this: inited, a2: &torque);
      if ( (this->m_spawnflags.m_Value & 4) != 0 )
      {
        v11->m_bForceRemove = true;
        CBaseEntity::SetNextThink(this: v11, thinkTime: gpGlobals->curtime + v11->m_lifeTime, szContext: nullptr);
        CBaseEntity::ThinkSet(
          this: v11,
          func: (void (__thiscall *)(CBaseEntity *))CGib::DieThink,
          thinkTime: 0.0,
          szContext: nullptr);
        return v11;
      }
    }
    else
    {
      CGibShooter::InitPointGib(this, pGib: *(float *)&v11, vecShootDir: *(float *)&vecShootDir, flSpeed);
    }
  }
  return v11;
}

//------------------------------------------------------------------------------
// Address: 0x1010A150
// Name: private: void CGibShooter::ShootThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGibShooter::ShootThink(CGibShooter *this)
{
  float m_flVariance; // xmm3_4
  float v3; // xmm3_4
  float v4; // xmm3_4
  Vector vUp; // [esp+24h] [ebp-34h] BYREF
  Vector vRight; // [esp+30h] [ebp-28h] BYREF
  Vector vForward; // [esp+3Ch] [ebp-1Ch] BYREF
  Vector vecShootDir; // [esp+48h] [ebp-10h] BYREF
  float v9; // [esp+54h] [ebp-4h]
  int savedregs; // [esp+58h] [ebp+0h] BYREF

  CBaseEntity::SetNextThink(this, thinkTime: this->m_flDelay + gpGlobals->curtime, szContext: nullptr);
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  AngleVectors(angles: &this->m_angAbsRotation, forward: &vForward, right: &vRight, up: &vUp);
  vecShootDir = vForward;
  v9 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
         a1: random,
         a2: -1082130432,
         a3: 1065353216);
  m_flVariance = this->m_flVariance;
  vecShootDir.x = (float)((float)(vRight.x * v9) * m_flVariance) + vecShootDir.x;
  vecShootDir.y = (float)((float)(vRight.y * v9) * m_flVariance) + vecShootDir.y;
  vecShootDir.z = (float)((float)(vRight.z * v9) * m_flVariance) + vecShootDir.z;
  v9 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
         a1: random,
         a2: -1082130432,
         a3: 1065353216);
  v3 = this->m_flVariance;
  vecShootDir.x = (float)((float)(v9 * vForward.x) * v3) + vecShootDir.x;
  vecShootDir.y = (float)((float)(vForward.y * v9) * v3) + vecShootDir.y;
  vecShootDir.z = (float)((float)(vForward.z * v9) * v3) + vecShootDir.z;
  v9 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
         a1: random,
         a2: -1082130432,
         a3: 1065353216);
  v4 = this->m_flVariance;
  vecShootDir.x = (float)((float)(vUp.x * v9) * v4) + vecShootDir.x;
  vecShootDir.y = (float)((float)(vUp.y * v9) * v4) + vecShootDir.y;
  vecShootDir.z = (float)((float)(vUp.z * v9) * v4) + vecShootDir.z;
  VectorNormalize(vec: &vecShootDir);
  CGibShooter::SpawnGib(this, &vecShootDir, flSpeed: this->m_flGibVelocity);
  if ( --this->m_iGibs <= 0 )
  {
    if ( (this->m_spawnflags.m_Value & 1) != 0 )
    {
      this->m_iGibs = this->m_iGibCapacity;
      CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
    }
    else
    {
      CBaseEntity::ThinkSet(this, func: CBaseEntity::SUB_Remove, thinkTime: 0.0, szContext: nullptr);
    }
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010A3F0
// Name: public: virtual class CBaseEntity __near * CRotorWashShooter::DoWashPush(float,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
CGib *__thiscall CRotorWashShooter::DoWashPush(
        CRotorWashShooter *this,
        CServerNetworkProperty_vtbl *flWashStartTime,
        const Vector *vecForce)
{
  CGib *result; // eax
  float curtime; // xmm0_4
  float z; // eax
  float (__thiscall *RandomFloat)(IUniformRandomStream *, float, float); // eax
  CBaseEntity *v8; // ebx
  Vector vecShootDir; // [esp+34h] [ebp-Ch] BYREF
  float flWashStartTimea; // [esp+48h] [ebp+8h]

  if ( *(float *)&flWashStartTime == *(float *)&this->m_Network.CEnvShooter::CGibShooter::CBaseEntity::__vftable
    && *(float *)&this->m_Network.__vftable > gpGlobals->curtime )
  {
    return nullptr;
  }
  this->m_Network.CEnvShooter::CGibShooter::CBaseEntity::__vftable = flWashStartTime;
  flWashStartTimea = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                       a1: random,
                       a2: -1082130432,
                       a3: 1065353216)
                   * *(float *)&this->m_pfnThink
                   + gpGlobals->curtime
                   + *(float *)&this->m_pfnMoveDone;
  *(float *)&this->m_Network.__vftable = flWashStartTimea;
  curtime = gpGlobals->curtime;
  if ( curtime >= flWashStartTimea )
    *(float *)&this->m_Network.__vftable = curtime + 0.0099999998;
  z = vecForce->z;
  *(_QWORD *)&vecShootDir.x = *(_QWORD *)&vecForce->x;
  vecShootDir.z = z;
  VectorNormalize(vec: (Vector *)LODWORD(vecShootDir.x));
  RandomFloat = random->RandomFloat;
  vecShootDir.x = 1.0;
  vecShootDir.x = ((double (__stdcall *)(int))RandomFloat)(a1: -1082130432) * *((float *)this - 10) + 1.0;
  vecShootDir.y = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                    a1: random,
                    a2: -1082130432,
                    a3: 1065353216)
                * *((float *)this - 10)
                + vecShootDir.y;
  vecShootDir.z = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                    a1: random,
                    a2: -1082130432,
                    a3: 1065353216)
                * *((float *)this - 10)
                + vecShootDir.z;
  VectorNormalize(vec: &vecShootDir);
  result = CGibShooter::SpawnGib(
             this: (CRotorWashShooter *)((char *)this - 928),
             &vecShootDir,
             flSpeed: *((float *)this - 15));
  --*((_DWORD *)this - 19);
  v8 = result;
  if ( *((int *)this - 19) <= 0 )
  {
    if ( (*((_BYTE *)this - 168) & 1) != 0 )
    {
      *((_DWORD *)this - 19) = *((_DWORD *)this - 18);
      return result;
    }
    CBaseEntity::ThinkSet(
      this: (CRotorWashShooter *)((char *)this - 928),
      func: CBaseEntity::SUB_Remove,
      thinkTime: 0.0,
      szContext: nullptr);
    CBaseEntity::SetNextThink(
      this: (CRotorWashShooter *)((char *)this - 928),
      thinkTime: gpGlobals->curtime,
      szContext: nullptr);
  }
  return (CGib *)v8;
}

//------------------------------------------------------------------------------
// Address: 0x1010A5D0
// Name: public: virtual void CGibShooter::Use(class CBaseEntity __near *,class CBaseEntity __near *,enum USE_TYPE,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGibShooter::Use(
        CGibShooter *this,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller,
        CBaseEntity *useType,
        float value)
{
  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CGibShooter::ShootThink,
    thinkTime: 0.0,
    szContext: nullptr);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1010A610
// Name: protected: void CGibShooter::InputShoot(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGibShooter::InputShoot(CGibShooter *this, inputdata_t *inputdata)
{
  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CGibShooter::ShootThink,
    thinkTime: 0.0,
    szContext: nullptr);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1012C3B0
// Name: public: virtual void CEnvWind::NetworkVar_m_EnvWindShared::NetworkStateChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvWind::NetworkVar_m_EnvWindShared::NetworkStateChanged(CEnvWind::NetworkVar_m_EnvWindShared *this)
{
  CBaseEdict *v1; // ecx

  if ( *((_BYTE *)this - 768) != 0 )
  {
    *((_BYTE *)this - 764) |= 1u;
  }
  else
  {
    v1 = *((CBaseEdict **)this - 207);
    if ( v1 != nullptr )
    {
      v1->m_fStateFlags |= 0x101u;
      CBaseEdict::GetChangeAccessor(this: v1)->m_iChangeInfoSerialNumber = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10401A90
// Name: CBubbling_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CBubbling_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CBubbling>();
  CBubbling_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10401AC0
// Name: CEnvTracer_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CEnvTracer_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CEnvTracer>();
  CEnvTracer_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10401AD0
// Name: CGibShooter_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CGibShooter_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CGibShooter>(__formal: nullptr);
  CGibShooter_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10401B00
// Name: CEnvShooter_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CEnvShooter_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CEnvShooter>();
  CEnvShooter_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10401B50
// Name: CRotorWashShooter_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CRotorWashShooter_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CRotorWashShooter>();
  CRotorWashShooter_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10401BA0
// Name: CBlood_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CBlood_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CBlood>(__formal: nullptr);
  CBlood_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10401BD0
// Name: CEnvFunnel_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CEnvFunnel_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CEnvFunnel>(__formal: nullptr);
  CEnvFunnel_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10401BE0
// Name: CEnvBeverage_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CEnvBeverage_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CEnvBeverage>(__formal: nullptr);
  CEnvBeverage_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10401C10
// Name: CItemSoda_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CItemSoda_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CItemSoda>(__formal: nullptr);
  CItemSoda_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10401C60
// Name: CPrecipitation_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CPrecipitation_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CPrecipitation>(__formal: nullptr);
  CPrecipitation_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10401C90
// Name: DT_Precipitation::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_Precipitation::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_Precipitation::g_SendTable);
  return atexit(func: DT_Precipitation::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10401CB0
// Name: DT_Precipitation::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_Precipitation::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_Precipitation::ignored>();
  DT_Precipitation::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10401CE0
// Name: CPrecipitationBlocker_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CPrecipitationBlocker_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CPrecipitationBlocker>(__formal: nullptr);
  CPrecipitationBlocker_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10401D10
// Name: DT_PrecipitationBlocker::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_PrecipitationBlocker::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_PrecipitationBlocker::g_SendTable);
  return atexit(func: DT_PrecipitationBlocker::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10401D30
// Name: DT_PrecipitationBlocker::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_PrecipitationBlocker::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_PrecipitationBlocker::ignored>();
  DT_PrecipitationBlocker::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10401D80
// Name: CEnvWind_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CEnvWind_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CEnvWind>(__formal: nullptr);
  CEnvWind_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10401D90
// Name: DT_EnvWindShared::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_EnvWindShared::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_EnvWindShared::g_SendTable);
  return atexit(func: DT_EnvWindShared::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10401DB0
// Name: DT_EnvWindShared::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_EnvWindShared::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_EnvWindShared::ignored>();
  DT_EnvWindShared::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10401DE0
// Name: DT_EnvWind::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_EnvWind::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_EnvWind::g_SendTable);
  return atexit(func: DT_EnvWind::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10401E00
// Name: DT_EnvWind::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_EnvWind::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_EnvWind::ignored>();
  DT_EnvWind::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10401E30
// Name: CEmbers_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CEmbers_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CEmbers>(__formal: nullptr);
  CEmbers_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10401E60
// Name: DT_Embers::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_Embers::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_Embers::g_SendTable);
  return atexit(func: DT_Embers::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10401E80
// Name: DT_Embers::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_Embers::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_Embers::ignored>();
  DT_Embers::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10401EB0
// Name: CPhysicsWire_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CPhysicsWire_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CPhysicsWire>(__formal: nullptr);
  CPhysicsWire_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10401EC0
// Name: CEnvMuzzleFlash_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CEnvMuzzleFlash_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CEnvMuzzleFlash>(__formal: nullptr);
  CEnvMuzzleFlash_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10401EF0
// Name: CEnvSplash_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CEnvSplash_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CEnvSplash>(__formal: nullptr);
  CEnvSplash_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10401F20
// Name: CEnvGunfire_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CEnvGunfire_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CEnvGunfire>(__formal: nullptr);
  CEnvGunfire_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10401F50
// Name: CEnvQuadraticBeam_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CEnvQuadraticBeam_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CEnvQuadraticBeam>(__formal: nullptr);
  CEnvQuadraticBeam_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10401FA0
// Name: DT_QuadraticBeam::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_QuadraticBeam::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_QuadraticBeam::g_SendTable);
  return atexit(func: DT_QuadraticBeam::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10401FC0
// Name: DT_QuadraticBeam::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_QuadraticBeam::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_QuadraticBeam::ignored>();
  DT_QuadraticBeam::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10401FD0
// Name: EffectsPrecachePrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int EffectsPrecachePrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106DA8A4;
  EffectsPrecachePrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106DA8A4;
  dword_106DA8A4 = (int)&EffectsPrecachePrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10402010
// Name: CEnvViewPunch_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CEnvViewPunch_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CEnvViewPunch>(__formal: nullptr);
  CEnvViewPunch_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041A860
// Name: DT_Precipitation::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_Precipitation::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_Precipitation::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041A870
// Name: DT_PrecipitationBlocker::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_PrecipitationBlocker::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_PrecipitationBlocker::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041A8A0
// Name: DT_EnvWindShared::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_EnvWindShared::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_EnvWindShared::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041A8D0
// Name: DT_EnvWind::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_EnvWind::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_EnvWind::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041A900
// Name: DT_Embers::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_Embers::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_Embers::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041A930
// Name: DT_QuadraticBeam::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_QuadraticBeam::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_QuadraticBeam::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x100487B0
// Name: struct datamap_t __near * DataMapInit<class CAI_RappelBehavior>(class CAI_RappelBehavior __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CAI_RappelBehavior>()
{
  if ( (_S2_11 & 1) == 0 )
  {
    _S2_11 |= 1u;
    nameHolder_31.m_pszBase = "CAI_RappelBehavior";
    nameHolder_31.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_31.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_31.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_31.m_Names.m_Size = 0;
    nameHolder_31.m_Names.m_pElements = nullptr;
    nameHolder_31.m_nLenBase = 18;
    atexit(func: DataMapInit_CAI_RappelBehavior__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CAI_RappelBehavior::m_DataMap.baseMap = &CAI_BehaviorBase::m_DataMap;
  CAI_RappelBehavior::m_DataMap.dataNumFields = 4;
  CAI_RappelBehavior::m_DataMap.dataDesc = &dataDesc_31[1];
  return &CAI_RappelBehavior::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10048830
// Name: struct datamap_t __near * DataMapInit<class CRopeAnchor>(class CRopeAnchor __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CRopeAnchor>()
{
  if ( (_S3_7 & 1) == 0 )
  {
    _S3_7 |= 1u;
    nameHolder_32.m_pszBase = "CRopeAnchor";
    nameHolder_32.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_32.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_32.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_32.m_Names.m_Size = 0;
    nameHolder_32.m_Names.m_pElements = nullptr;
    nameHolder_32.m_nLenBase = 11;
    atexit(func: DataMapInit_CRopeAnchor__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CRopeAnchor::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S3_7 & 2) == 0 )
  {
    _S3_7 |= 2u;
    dataDesc_32[2].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                 this: &nameHolder_32,
                                 pszIdentifier: "FallThink");
    dataDesc_32[2].flags = 32;
    dataDesc_32[2].fieldOffset = 0;
    dataDesc_32[2].fieldSize = 1;
    dataDesc_32[2].externalName = nullptr;
    dataDesc_32[2].pSaveRestoreOps = nullptr;
    dataDesc_32[2].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CRopeAnchor::FallThink;
    *(_QWORD *)&dataDesc_32[2].td = 0;
    *(_QWORD *)&dataDesc_32[2].override_field = 0;
    *(_QWORD *)&dataDesc_32[2].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_32[2].flatOffset[1] = 0;
    dataDesc_32[3].fieldType = FIELD_VOID;
    dataDesc_32[3].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                 this: &nameHolder_32,
                                 pszIdentifier: "RemoveThink");
    dataDesc_32[3].fieldOffset = 0;
    *(_DWORD *)&dataDesc_32[3].fieldSize = 2097153;
    dataDesc_32[3].externalName = nullptr;
    dataDesc_32[3].pSaveRestoreOps = nullptr;
    dataDesc_32[3].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CRopeAnchor::RemoveThink;
    *(_QWORD *)&dataDesc_32[3].td = 0;
    *(_QWORD *)&dataDesc_32[3].override_field = 0;
    *(_QWORD *)&dataDesc_32[3].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_32[3].flatOffset[1] = 0;
  }
  CRopeAnchor::m_DataMap.dataNumFields = 3;
  CRopeAnchor::m_DataMap.dataDesc = &dataDesc_32[1];
  return &CRopeAnchor::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10108F80
// Name: struct datamap_t __near * DataMapInit<class CBlood>(class CBlood __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CBlood>()
{
  if ( (_S7_4 & 1) == 0 )
  {
    _S7_4 |= 1u;
    nameHolder_136.m_pszBase = "CBlood";
    nameHolder_136.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_136.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_136.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_136.m_Names.m_Size = 0;
    nameHolder_136.m_Names.m_pElements = nullptr;
    nameHolder_136.m_nLenBase = 6;
    atexit(func: DataMapInit_CBlood__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CBlood::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CBlood::m_DataMap.dataNumFields = 4;
  CBlood::m_DataMap.dataDesc = &dataDesc_131[1];
  return &CBlood::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10109000
// Name: struct datamap_t __near * DataMapInit<class CEnvFunnel>(class CEnvFunnel __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CEnvFunnel>()
{
  if ( (_S8_2 & 1) == 0 )
  {
    _S8_2 |= 1u;
    nameHolder_137.m_pszBase = "CEnvFunnel";
    nameHolder_137.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_137.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_137.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_137.m_Names.m_Size = 0;
    nameHolder_137.m_Names.m_pElements = nullptr;
    nameHolder_137.m_nLenBase = 10;
    atexit(func: DataMapInit_CEnvFunnel__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CEnvFunnel::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CEnvFunnel::m_DataMap.dataNumFields = 1;
  CEnvFunnel::m_DataMap.dataDesc = dataDesc_472;
  return &CEnvFunnel::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10109070
// Name: struct datamap_t __near * DataMapInit<class CEnvBeverage>(class CEnvBeverage __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CEnvBeverage>()
{
  if ( (_S9_1 & 1) == 0 )
  {
    _S9_1 |= 1u;
    nameHolder_138.m_pszBase = "CEnvBeverage";
    nameHolder_138.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_138.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_138.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_138.m_Names.m_Size = 0;
    nameHolder_138.m_Names.m_pElements = nullptr;
    nameHolder_138.m_nLenBase = 12;
    atexit(func: DataMapInit_CEnvBeverage__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CEnvBeverage::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CEnvBeverage::m_DataMap.dataNumFields = 3;
  CEnvBeverage::m_DataMap.dataDesc = &dataDesc_132[1];
  return &CEnvBeverage::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101090F0
// Name: struct datamap_t __near * DataMapInit<class CItemSoda>(class CItemSoda __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CItemSoda>()
{
  if ( (_S10_0 & 1) == 0 )
  {
    _S10_0 |= 1u;
    nameHolder_139.m_pszBase = "CItemSoda";
    nameHolder_139.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_139.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_139.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_139.m_Names.m_Size = 0;
    nameHolder_139.m_Names.m_pElements = nullptr;
    nameHolder_139.m_nLenBase = 9;
    atexit(func: DataMapInit_CItemSoda__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CItemSoda::m_DataMap.baseMap = &CBaseAnimating::m_DataMap;
  if ( (_S10_0 & 2) == 0 )
  {
    _S10_0 |= 2u;
    dataDesc_473[1].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_139,
                                  pszIdentifier: "CanThink");
    dataDesc_473[1].fieldOffset = 0;
    *(_DWORD *)&dataDesc_473[1].fieldSize = 2097153;
    dataDesc_473[1].externalName = nullptr;
    dataDesc_473[1].pSaveRestoreOps = nullptr;
    dataDesc_473[1].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CItemSoda::CanThink;
    *(_QWORD *)&dataDesc_473[1].td = 0;
    *(_QWORD *)&dataDesc_473[1].override_field = 0;
    *(_QWORD *)&dataDesc_473[1].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_473[1].flatOffset[1] = 0;
    dataDesc_473[2].fieldType = FIELD_VOID;
    dataDesc_473[2].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_139,
                                  pszIdentifier: "CanTouch");
    dataDesc_473[2].fieldOffset = 0;
    *(_DWORD *)&dataDesc_473[2].fieldSize = 2097153;
    dataDesc_473[2].externalName = nullptr;
    dataDesc_473[2].pSaveRestoreOps = nullptr;
    dataDesc_473[2].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CItemSoda::CanTouch;
    *(_QWORD *)&dataDesc_473[2].td = 0;
    *(_QWORD *)&dataDesc_473[2].override_field = 0;
    *(_QWORD *)&dataDesc_473[2].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_473[2].flatOffset[1] = 0;
  }
  CItemSoda::m_DataMap.dataNumFields = 2;
  CItemSoda::m_DataMap.dataDesc = &dataDesc_473[1];
  return &CItemSoda::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10109240
// Name: struct datamap_t __near * DataMapInit<class CPrecipitation>(class CPrecipitation __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CPrecipitation>()
{
  if ( (_S11_0 & 1) == 0 )
  {
    _S11_0 |= 1u;
    nameHolder_140.m_pszBase = "CPrecipitation";
    nameHolder_140.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_140.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_140.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_140.m_Names.m_Size = 0;
    nameHolder_140.m_Names.m_pElements = nullptr;
    nameHolder_140.m_nLenBase = 14;
    atexit(func: DataMapInit_CPrecipitation__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CPrecipitation::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CPrecipitation::m_DataMap.dataNumFields = 1;
  CPrecipitation::m_DataMap.dataDesc = &dataDesc_133[1];
  return &CPrecipitation::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101092B0
// Name: struct datamap_t __near * DataMapInit<class CPrecipitationBlocker>(class CPrecipitationBlocker __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CPrecipitationBlocker>()
{
  if ( (_S13 & 1) == 0 )
  {
    _S13 |= 1u;
    nameHolder_141.m_pszBase = "CPrecipitationBlocker";
    nameHolder_141.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_141.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_141.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_141.m_Names.m_Size = 0;
    nameHolder_141.m_Names.m_pElements = nullptr;
    nameHolder_141.m_nLenBase = 21;
    atexit(func: DataMapInit_CPrecipitationBlocker__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CPrecipitationBlocker::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CPrecipitationBlocker::m_DataMap.dataNumFields = 1;
  CPrecipitationBlocker::m_DataMap.dataDesc = dataDesc_474;
  return &CPrecipitationBlocker::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10109320
// Name: struct datamap_t __near * DataMapInit<class CEnvWind>(class CEnvWind __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CEnvWind>()
{
  if ( (_S16 & 1) == 0 )
  {
    _S16 |= 1u;
    nameHolder_142.m_pszBase = "CEnvWind";
    nameHolder_142.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_142.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_142.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_142.m_Names.m_Size = 0;
    nameHolder_142.m_Names.m_pElements = nullptr;
    nameHolder_142.m_nLenBase = 8;
    atexit(func: DataMapInit_CEnvWind__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CEnvWind::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S16 & 2) == 0 )
  {
    _S16 |= 2u;
    *(_QWORD *)&dataDesc_134[11].inputFunc = 0;
    *(_QWORD *)&dataDesc_134[11].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_134[11].override_count = 0;
    *(_QWORD *)dataDesc_134[11].flatOffset = 0;
    dataDesc_134[12].fieldSize = 1;
    dataDesc_134[11].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_134[11].flatGroup = 0;
    dataDesc_134[12].fieldType = FIELD_CUSTOM;
    dataDesc_134[12].fieldName = "m_EnvWindShared.m_OnGustEnd";
    dataDesc_134[12].fieldOffset = 992;
    dataDesc_134[12].flags = 22;
    dataDesc_134[12].externalName = "OnGustEnd";
    dataDesc_134[12].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_134[12].inputFunc = 0;
    *(_QWORD *)&dataDesc_134[12].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_134[12].override_count = 0;
    *(_QWORD *)dataDesc_134[12].flatOffset = 0;
    *(_DWORD *)&dataDesc_134[12].flatGroup = 0;
    dataDesc_134[13].fieldType = FIELD_VOID;
    dataDesc_134[13].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_142,
                                   pszIdentifier: "WindThink");
    dataDesc_134[13].fieldOffset = 0;
    *(_DWORD *)&dataDesc_134[13].fieldSize = 2097153;
    dataDesc_134[13].externalName = nullptr;
    dataDesc_134[13].pSaveRestoreOps = nullptr;
    dataDesc_134[13].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CEnvWind::WindThink;
    *(_QWORD *)&dataDesc_134[13].td = 0;
    *(_QWORD *)&dataDesc_134[13].override_field = 0;
    *(_QWORD *)&dataDesc_134[13].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_134[13].flatOffset[1] = 0;
  }
  CEnvWind::m_DataMap.dataNumFields = 13;
  CEnvWind::m_DataMap.dataDesc = &dataDesc_134[1];
  return &CEnvWind::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101094C0
// Name: struct datamap_t __near * DataMapInit<class CEmbers>(class CEmbers __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CEmbers>()
{
  if ( (_S19 & 1) == 0 )
  {
    _S19 |= 1u;
    nameHolder_143.m_pszBase = "CEmbers";
    nameHolder_143.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_143.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_143.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_143.m_Names.m_Size = 0;
    nameHolder_143.m_Names.m_pElements = nullptr;
    nameHolder_143.m_nLenBase = 7;
    atexit(func: DataMapInit_CEmbers__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CEmbers::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S19 & 2) == 0 )
  {
    _S19 |= 2u;
    dataDesc_135[5].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_143,
                                  pszIdentifier: "EmberUse");
    dataDesc_135[5].fieldOffset = 0;
    *(_DWORD *)&dataDesc_135[5].fieldSize = 2097153;
    dataDesc_135[5].externalName = nullptr;
    dataDesc_135[5].pSaveRestoreOps = nullptr;
    dataDesc_135[5].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CEmbers::EmberUse;
    *(_QWORD *)&dataDesc_135[5].td = 0;
    *(_QWORD *)&dataDesc_135[5].override_field = 0;
    *(_QWORD *)&dataDesc_135[5].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_135[5].flatOffset[1] = 0;
  }
  CEmbers::m_DataMap.dataNumFields = 5;
  CEmbers::m_DataMap.dataDesc = &dataDesc_135[1];
  return &CEmbers::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101095B0
// Name: struct datamap_t __near * DataMapInit<class CPhysicsWire>(class CPhysicsWire __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CPhysicsWire>()
{
  if ( (_S21 & 1) == 0 )
  {
    _S21 |= 1u;
    nameHolder_144.m_pszBase = "CPhysicsWire";
    nameHolder_144.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_144.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_144.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_144.m_Names.m_Size = 0;
    nameHolder_144.m_Names.m_pElements = nullptr;
    nameHolder_144.m_nLenBase = 12;
    atexit(func: DataMapInit_CPhysicsWire__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CPhysicsWire::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CPhysicsWire::m_DataMap.dataNumFields = 1;
  CPhysicsWire::m_DataMap.dataDesc = &dataDesc_136[1];
  return &CPhysicsWire::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10109620
// Name: struct datamap_t __near * DataMapInit<class CEnvMuzzleFlash>(class CEnvMuzzleFlash __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CEnvMuzzleFlash>()
{
  if ( (_S22 & 1) == 0 )
  {
    _S22 |= 1u;
    nameHolder_145.m_pszBase = "CEnvMuzzleFlash";
    nameHolder_145.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_145.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_145.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_145.m_Names.m_Size = 0;
    nameHolder_145.m_Names.m_pElements = nullptr;
    nameHolder_145.m_nLenBase = 15;
    atexit(func: DataMapInit_CEnvMuzzleFlash__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CEnvMuzzleFlash::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CEnvMuzzleFlash::m_DataMap.dataNumFields = 3;
  CEnvMuzzleFlash::m_DataMap.dataDesc = &dataDesc_137[1];
  return &CEnvMuzzleFlash::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101096A0
// Name: struct datamap_t __near * DataMapInit<class CEnvSplash>(class CEnvSplash __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CEnvSplash>()
{
  if ( (_S23 & 1) == 0 )
  {
    _S23 |= 1u;
    nameHolder_146.m_pszBase = "CEnvSplash";
    nameHolder_146.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_146.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_146.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_146.m_Names.m_Size = 0;
    nameHolder_146.m_Names.m_pElements = nullptr;
    nameHolder_146.m_nLenBase = 10;
    atexit(func: DataMapInit_CEnvSplash__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CEnvSplash::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CEnvSplash::m_DataMap.dataNumFields = 2;
  CEnvSplash::m_DataMap.dataDesc = &dataDesc_138[1];
  return &CEnvSplash::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10109720
// Name: struct datamap_t __near * DataMapInit<class CEnvGunfire>(class CEnvGunfire __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CEnvGunfire>()
{
  if ( (_S24 & 1) == 0 )
  {
    _S24 |= 1u;
    nameHolder_147.m_pszBase = "CEnvGunfire";
    nameHolder_147.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_147.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_147.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_147.m_Names.m_Size = 0;
    nameHolder_147.m_Names.m_pElements = nullptr;
    nameHolder_147.m_nLenBase = 11;
    atexit(func: DataMapInit_CEnvGunfire__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CEnvGunfire::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S24 & 2) == 0 )
  {
    _S24 |= 2u;
    dataDesc_139[17].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_147,
                                   pszIdentifier: "ShootThink");
    *(_QWORD *)&dataDesc_139[17].td = 0;
    *(_QWORD *)&dataDesc_139[17].override_field = 0;
    *(_QWORD *)&dataDesc_139[17].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_139[17].flatOffset[1] = 0;
    dataDesc_139[17].fieldSize = 1;
    *(_QWORD *)&dataDesc_139[18].td = 0;
    *(_QWORD *)&dataDesc_139[18].override_field = 0;
    *(_QWORD *)&dataDesc_139[18].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_139[18].flatOffset[1] = 0;
    dataDesc_139[17].fieldOffset = 0;
    dataDesc_139[17].flags = 32;
    dataDesc_139[17].externalName = nullptr;
    dataDesc_139[17].pSaveRestoreOps = nullptr;
    dataDesc_139[17].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CEnvGunfire::ShootThink;
    dataDesc_139[18].fieldType = FIELD_VOID;
    dataDesc_139[18].fieldName = "InputEnable";
    dataDesc_139[18].fieldOffset = 0;
    dataDesc_139[18].fieldSize = 1;
    dataDesc_139[18].flags = 8;
    dataDesc_139[18].externalName = "Enable";
    dataDesc_139[18].pSaveRestoreOps = nullptr;
    dataDesc_139[18].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CEnvGunfire::InputEnable;
    dataDesc_139[19].fieldType = FIELD_VOID;
    dataDesc_139[19].fieldName = "InputDisable";
    dataDesc_139[19].fieldOffset = 0;
    *(_DWORD *)&dataDesc_139[19].fieldSize = 524289;
    dataDesc_139[19].externalName = "Disable";
    dataDesc_139[19].pSaveRestoreOps = nullptr;
    dataDesc_139[19].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CEnvGunfire::InputDisable;
    *(_QWORD *)&dataDesc_139[19].td = 0;
    *(_QWORD *)&dataDesc_139[19].override_field = 0;
    *(_QWORD *)&dataDesc_139[19].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_139[19].flatOffset[1] = 0;
  }
  CEnvGunfire::m_DataMap.dataNumFields = 19;
  CEnvGunfire::m_DataMap.dataDesc = &dataDesc_139[1];
  return &CEnvGunfire::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101098F0
// Name: struct datamap_t __near * DataMapInit<class CEnvQuadraticBeam>(class CEnvQuadraticBeam __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CEnvQuadraticBeam>()
{
  if ( (_S25 & 1) == 0 )
  {
    _S25 |= 1u;
    nameHolder_148.m_pszBase = "CEnvQuadraticBeam";
    nameHolder_148.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_148.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_148.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_148.m_Names.m_Size = 0;
    nameHolder_148.m_Names.m_pElements = nullptr;
    nameHolder_148.m_nLenBase = 17;
    atexit(func: DataMapInit_CEnvQuadraticBeam__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CEnvQuadraticBeam::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CEnvQuadraticBeam::m_DataMap.dataNumFields = 4;
  CEnvQuadraticBeam::m_DataMap.dataDesc = &dataDesc_140[1];
  return &CEnvQuadraticBeam::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101099D0
// Name: struct datamap_t __near * DataMapInit<class CEnvViewPunch>(class CEnvViewPunch __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CEnvViewPunch>()
{
  if ( (_S27 & 1) == 0 )
  {
    _S27 |= 1u;
    nameHolder_149.m_pszBase = "CEnvViewPunch";
    nameHolder_149.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_149.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_149.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_149.m_Names.m_Size = 0;
    nameHolder_149.m_Names.m_pElements = nullptr;
    nameHolder_149.m_nLenBase = 13;
    atexit(func: DataMapInit_CEnvViewPunch__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CEnvViewPunch::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CEnvViewPunch::m_DataMap.dataNumFields = 3;
  CEnvViewPunch::m_DataMap.dataDesc = &dataDesc_141[1];
  return &CEnvViewPunch::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1010A650
// Name: struct datamap_t __near * DataMapInit<class CGibShooter>(class CGibShooter __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CGibShooter>()
{
  if ( (_S4_23 & 1) == 0 )
  {
    _S4_23 |= 1u;
    nameHolder_150.m_pszBase = "CGibShooter";
    nameHolder_150.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_150.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_150.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_150.m_Names.m_Size = 0;
    nameHolder_150.m_Names.m_pElements = nullptr;
    nameHolder_150.m_nLenBase = 11;
    atexit(func: DataMapInit_CGibShooter__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CGibShooter::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S4_23 & 2) == 0 )
  {
    _S4_23 |= 2u;
    dataDesc_142[17].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_150,
                                   pszIdentifier: "ShootThink");
    dataDesc_142[17].fieldOffset = 0;
    *(_DWORD *)&dataDesc_142[17].fieldSize = 2097153;
    dataDesc_142[17].externalName = nullptr;
    dataDesc_142[17].pSaveRestoreOps = nullptr;
    dataDesc_142[17].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CGibShooter::ShootThink;
    *(_QWORD *)&dataDesc_142[17].td = 0;
    *(_QWORD *)&dataDesc_142[17].override_field = 0;
    *(_QWORD *)&dataDesc_142[17].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_142[17].flatOffset[1] = 0;
  }
  CGibShooter::m_DataMap.dataNumFields = 17;
  CGibShooter::m_DataMap.dataDesc = &dataDesc_142[1];
  return &CGibShooter::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1010A740
// Name: __CreateCEffectsServerIEffects_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CEffectsServer *__cdecl _CreateCEffectsServerIEffects_interface()
{
  return &s_EffectServer;
}

//------------------------------------------------------------------------------
// Address: 0x10401AA0
// Name: _dynamic_initializer_for__env_tracer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_tracer__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CEnvTracer> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_tracer,
           a3: "env_tracer");
}

//------------------------------------------------------------------------------
// Address: 0x10401AE0
// Name: _dynamic_initializer_for__gibshooter__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__gibshooter__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CGibShooter> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &gibshooter,
           a3: "gibshooter");
}

//------------------------------------------------------------------------------
// Address: 0x10401B10
// Name: _dynamic_initializer_for__env_shooter__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_shooter__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CEnvShooter> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_shooter,
           a3: "env_shooter");
}

//------------------------------------------------------------------------------
// Address: 0x10401B30
// Name: _dynamic_initializer_for__env_rotorshooter__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_rotorshooter__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CRotorWashShooter> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_rotorshooter,
           a3: "env_rotorshooter");
}

//------------------------------------------------------------------------------
// Address: 0x10401BB0
// Name: _dynamic_initializer_for__env_funnel__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_funnel__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CEnvFunnel> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_funnel,
           a3: "env_funnel");
}

//------------------------------------------------------------------------------
// Address: 0x10401BF0
// Name: _dynamic_initializer_for__env_beverage__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_beverage__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CEnvBeverage> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_beverage,
           a3: "env_beverage");
}

//------------------------------------------------------------------------------
// Address: 0x10401C70
// Name: _dynamic_initializer_for__g_CPrecipitation_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CPrecipitation_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CPrecipitation_ClassReg,
           pNetworkName: "CPrecipitation",
           pTable: &DT_Precipitation::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10401CF0
// Name: _dynamic_initializer_for__g_CPrecipitationBlocker_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CPrecipitationBlocker_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CPrecipitationBlocker_ClassReg,
           pNetworkName: "CPrecipitationBlocker",
           pTable: &DT_PrecipitationBlocker::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10401DC0
// Name: _dynamic_initializer_for__g_CEnvWind_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CEnvWind_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CEnvWind_ClassReg,
           pNetworkName: "CEnvWind",
           pTable: &DT_EnvWind::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10401E10
// Name: _dynamic_initializer_for__env_embers__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_embers__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CEmbers> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_embers,
           a3: "env_embers");
}

//------------------------------------------------------------------------------
// Address: 0x10401E40
// Name: _dynamic_initializer_for__g_CEmbers_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CEmbers_ClassReg__()
{
  return ServerClass::ServerClass(this: &g_CEmbers_ClassReg, pNetworkName: "CEmbers", pTable: &DT_Embers::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10401E90
// Name: _dynamic_initializer_for__env_physwire__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_physwire__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CPhysicsWire> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_physwire,
           a3: "env_physwire");
}

//------------------------------------------------------------------------------
// Address: 0x10401ED0
// Name: _dynamic_initializer_for__env_muzzleflash__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_muzzleflash__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CEnvMuzzleFlash> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_muzzleflash,
           a3: "env_muzzleflash");
}

//------------------------------------------------------------------------------
// Address: 0x10401F00
// Name: _dynamic_initializer_for__env_splash__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_splash__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CEnvSplash> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_splash,
           a3: "env_splash");
}

//------------------------------------------------------------------------------
// Address: 0x10401F30
// Name: _dynamic_initializer_for__env_gunfire__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_gunfire__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CEnvGunfire> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_gunfire,
           a3: "env_gunfire");
}

//------------------------------------------------------------------------------
// Address: 0x10401F60
// Name: _dynamic_initializer_for__env_quadraticbeam__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_quadraticbeam__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CEnvQuadraticBeam> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_quadraticbeam,
           a3: "env_quadraticbeam");
}

//------------------------------------------------------------------------------
// Address: 0x10401F80
// Name: _dynamic_initializer_for__g_CEnvQuadraticBeam_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CEnvQuadraticBeam_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CEnvQuadraticBeam_ClassReg,
           pNetworkName: "CEnvQuadraticBeam",
           pTable: &DT_QuadraticBeam::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10401FF0
// Name: _dynamic_initializer_for__env_viewpunch__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_viewpunch__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CEnvViewPunch> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_viewpunch,
           a3: "env_viewpunch");
}

//------------------------------------------------------------------------------
// Address: 0x10402020
// Name: _dynamic_initializer_for__s_EffectServer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EffectServer__()
{
  s_EffectServer.m_pNextSystem = IPredictionSystem::g_pPredictionSystems;
  IPredictionSystem::g_pPredictionSystems = &s_EffectServer;
  return atexit(func: dynamic_atexit_destructor_for__s_EffectServer__);
}

//------------------------------------------------------------------------------
// Address: 0x10402040
// Name: _dynamic_initializer_for____g_CreateCEffectsServerIEffects_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCEffectsServerIEffects_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCEffectsServerIEffects_reg,
           fn: (void *(__cdecl *)())_CreateCEffectsServerIEffects_interface,
           pName: "IEffects001");
}

//------------------------------------------------------------------------------
// Address: 0x1041A880
// Name: _ServerClassInit_DT_PrecipitationBlocker::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_PrecipitationBlocker::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S14;
  for ( i = 1; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041A8B0
// Name: _ServerClassInit_DT_EnvWindShared::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_EnvWindShared::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S17;
  for ( i = 12; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041A8E0
// Name: _ServerClassInit_DT_EnvWind::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_EnvWind::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S18;
  for ( i = 1; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041A910
// Name: _ServerClassInit_DT_Embers::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_Embers::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S20;
  for ( i = 5; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041A940
// Name: _ServerClassInit_DT_QuadraticBeam::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_QuadraticBeam::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S26;
  for ( i = 5; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041A960
// Name: _ServerClassInit_DT_Precipitation::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_Precipitation::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S12_0;
  for ( i = 2; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041A980
// Name: _DataMapInit_CBubbling__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CBubbling__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_132);
}

//------------------------------------------------------------------------------
// Address: 0x1041A990
// Name: _DataMapInit_CEnvTracer__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CEnvTracer__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_133);
}

//------------------------------------------------------------------------------
// Address: 0x1041A9A0
// Name: _DataMapInit_CGibShooter__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CGibShooter__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_150);
}

//------------------------------------------------------------------------------
// Address: 0x1041A9B0
// Name: _DataMapInit_CEnvShooter__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CEnvShooter__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_134);
}

//------------------------------------------------------------------------------
// Address: 0x1041A9C0
// Name: _DataMapInit_CRotorWashShooter__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CRotorWashShooter__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_135);
}

//------------------------------------------------------------------------------
// Address: 0x1041A9D0
// Name: _DataMapInit_CBlood__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CBlood__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_136);
}

//------------------------------------------------------------------------------
// Address: 0x1041A9E0
// Name: _DataMapInit_CEnvFunnel__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CEnvFunnel__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_137);
}

//------------------------------------------------------------------------------
// Address: 0x1041A9F0
// Name: _DataMapInit_CEnvBeverage__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CEnvBeverage__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_138);
}

//------------------------------------------------------------------------------
// Address: 0x1041AA00
// Name: _DataMapInit_CItemSoda__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CItemSoda__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_139);
}

//------------------------------------------------------------------------------
// Address: 0x1041AA10
// Name: _DataMapInit_CPrecipitation__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CPrecipitation__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_140);
}

//------------------------------------------------------------------------------
// Address: 0x1041AA20
// Name: _DataMapInit_CPrecipitationBlocker__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CPrecipitationBlocker__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_141);
}

//------------------------------------------------------------------------------
// Address: 0x1041AA30
// Name: _DataMapInit_CEnvWind__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CEnvWind__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_142);
}

//------------------------------------------------------------------------------
// Address: 0x1041AA40
// Name: _DataMapInit_CEmbers__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CEmbers__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_143);
}

//------------------------------------------------------------------------------
// Address: 0x1041AA50
// Name: _DataMapInit_CPhysicsWire__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CPhysicsWire__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_144);
}

//------------------------------------------------------------------------------
// Address: 0x1041AA60
// Name: _DataMapInit_CEnvMuzzleFlash__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CEnvMuzzleFlash__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_145);
}

//------------------------------------------------------------------------------
// Address: 0x1041AA70
// Name: _DataMapInit_CEnvSplash__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CEnvSplash__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_146);
}

//------------------------------------------------------------------------------
// Address: 0x1041AA80
// Name: _DataMapInit_CEnvGunfire__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CEnvGunfire__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_147);
}

//------------------------------------------------------------------------------
// Address: 0x1041AA90
// Name: _DataMapInit_CEnvQuadraticBeam__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CEnvQuadraticBeam__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_148);
}

//------------------------------------------------------------------------------
// Address: 0x1041AAA0
// Name: _DataMapInit_CEnvViewPunch__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CEnvViewPunch__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_149);
}

//------------------------------------------------------------------------------
// Address: 0x1041AAB0
// Name: _dynamic_atexit_destructor_for__s_EffectServer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EffectServer__()
{
  s_EffectServer.__vftable = (CEffectsServer_vtbl *)&IPredictionSystem::`vftable';
}
