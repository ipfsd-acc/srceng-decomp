// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/fire.cpp
// Functions: 47
// ============================================================

#include "game\server\fire.h"

//------------------------------------------------------------------------------
// Address: 0x10124BE0
// Name: public: bool CFireSphere::AddToList(class CFire __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CFireSphere::AddToList(CFireSphere *this, CFire *pFire)
{
  int m_count; // eax

  m_count = this->m_count;
  if ( m_count >= this->m_listMax )
    return 0;
  this->m_pList[m_count] = pFire;
  ++this->m_count;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10124C10
// Name: protected: virtual struct datamap_t __near * CFire::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CFire::GetDataDescMap(CFire *this)
{
  return &CFire::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10124C20
// Name: public: bool CFire::GetFireDimensions(class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CFire::GetFireDimensions(CFire *this, Vector *pFireMins, Vector *pFireMaxs)
{
  float m_flHeatLevel; // xmm0_4
  float v5; // xmm2_4
  float v6; // xmm0_4
  float v7; // xmm1_4

  m_flHeatLevel = this->m_flHeatLevel;
  if ( m_flHeatLevel > 0.0 )
  {
    v5 = m_flHeatLevel / this->m_flMaxHeat;
    v6 = (float)((float)((float)((float)(this->m_flFireSize * v5) * 128.0) * 0.00390625) * 0.5) * 2.0;
    if ( v6 < 16.0 )
      v6 = 16.0;
    LODWORD(pFireMins->x) = LODWORD(v6) ^ _mask__NegFloat_;
    LODWORD(pFireMins->y) = LODWORD(v6) ^ _mask__NegFloat_;
    pFireMins->z = 0.0;
    v7 = this->m_flFireSize * v5;
    pFireMaxs->x = v6;
    pFireMaxs->y = v6;
    pFireMaxs->z = v7;
    return 1;
  }
  else
  {
    pFireMins->x = 0.0;
    pFireMins->y = 0.0;
    pFireMins->z = 0.0;
    pFireMaxs->x = 0.0;
    pFireMaxs->y = 0.0;
    pFireMaxs->z = 0.0;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10124CE0
// Name: public: void CFire::BurnThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFire::BurnThink(CFire *this)
{
  float thinkTime; // [esp+0h] [ebp-Ch]

  thinkTime = gpGlobals->curtime + 0.1;
  CBaseEntity::SetNextThink(this, thinkTime, szContext: nullptr);
  ((void (__thiscall *)(CFire *, int))this->Update)(a1: this, a2: 1036831949);
}

//------------------------------------------------------------------------------
// Address: 0x10124D30
// Name: public: virtual struct datamap_t __near * CEnvFireSource::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CEnvFireSource::GetDataDescMap(CEnvFireSource *this)
{
  return &CEnvFireSource::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10124D40
// Name: public: void CEnvFireSource::InputEnable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvFireSource::InputEnable(CEnvFireSource *this, inputdata_t *inputdata)
{
  if ( !this->m_bEnabled )
  {
    this->m_bEnabled = true;
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10124D70
// Name: public: void CEnvFireSource::InputDisable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvFireSource::InputDisable(CEnvFireSource *this, inputdata_t *inputdata)
{
  if ( this->m_bEnabled )
  {
    this->m_bEnabled = false;
    CBaseEntity::SetNextThink(this, thinkTime: -1.0, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10124DA0
// Name: public: virtual struct datamap_t __near * CEnvFireSensor::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CEnvFireSensor::GetDataDescMap(CEnvFireSensor *this)
{
  return &CEnvFireSensor::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10124DB0
// Name: public: void CEnvFireSensor::InputEnable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvFireSensor::InputEnable(CEnvFireSensor *this, inputdata_t *inputdata)
{
  if ( !this->m_bEnabled )
  {
    this->m_bEnabled = true;
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
    this->m_bHeatAtLevel = false;
    this->m_levelTime = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10124DF0
// Name: public: void CEnvFireSensor::InputDisable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvFireSensor::InputDisable(CEnvFireSensor *this, inputdata_t *inputdata)
{
  if ( this->m_bEnabled )
  {
    this->m_bEnabled = false;
    CBaseEntity::SetNextThink(this, thinkTime: -1.0, szContext: nullptr);
    if ( this->m_bHeatAtLevel )
    {
      this->m_bHeatAtLevel = false;
      COutputEvent::FireOutput(this: &this->m_OnHeatLevelEnd, pActivator: this, pCaller: this, fDelay: 0.0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10124E50
// Name: public: virtual int CFire::DrawDebugTextOverlays(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFire::DrawDebugTextOverlays(CFire *this)
{
  int result; // eax
  int v3; // edi
  char tempstr[512]; // [esp+1Ch] [ebp-200h] BYREF

  result = CBaseEntity::DrawDebugTextOverlays(this);
  v3 = result;
  if ( (this->m_debugOverlays & 1) != 0 )
  {
    V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "    size: %f", this->m_flFireSize);
    CBaseEntity::EntityText(this, text_offset: v3, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    return v3 + 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10124ED0
// Name: public: virtual enum IterationRetval_t CFireSphere::EnumElement(class IHandleEntity __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CFireSphere::EnumElement(CFireSphere *this, IHandleEntity *pHandleEntity)
{
  unsigned int m_Index; // eax
  CEntInfo *v4; // ecx
  IHandleEntity *m_pEntity; // ecx
  CBaseEntity *v6; // eax
  CFire *v7; // esi
  float v8; // xmm1_4
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  m_Index = pHandleEntity->GetRefEHandle(this: pHandleEntity)->m_Index;
  if ( m_Index == -1 )
    return false;
  v4 = &gEntList.m_EntPtrArray[(unsigned __int16)m_Index];
  if ( v4->m_SerialNumber != HIWORD(m_Index) )
    return false;
  m_pEntity = v4->m_pEntity;
  if ( m_pEntity == nullptr )
    return false;
  v6 = (CBaseEntity *)m_pEntity->__vftable[1].GetRefEHandle(this: m_pEntity);
  v7 = (CFire *)v6;
  if ( v6 == nullptr
    || v6->m_iClassname.pszValue != "env_fire"
    && CBaseEntity::ClassMatchesComplex(this: v6, pszClassOrWildcard: "env_fire") == 0 )
  {
    return false;
  }
  if ( this->m_onlyActiveFires && v7->m_flHeatLevel <= 0.0 )
    return false;
  if ( (v7->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: v7, a2: (int)&savedregs);
  v8 = this->m_origin.y - v7->m_vecAbsOrigin.y;
  return this->m_radiusSqr > (float)((float)((float)((float)(this->m_origin.x - v7->m_vecAbsOrigin.x)
                                                   * (float)(this->m_origin.x - v7->m_vecAbsOrigin.x))
                                           + (float)(v8 * v8))
                                   + (float)((float)(this->m_origin.z - v7->m_vecAbsOrigin.z)
                                           * (float)(this->m_origin.z - v7->m_vecAbsOrigin.z)))
      && CFireSphere::AddToList(this, pFire: v7) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10124FE0
// Name: public: virtual void CFire::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFire::Precache(CFire *this)
{
  if ( this->m_nFireType == 0 )
  {
    UTIL_PrecacheOther(szClassname: "_firesmoke", modelName: nullptr);
    if ( (this->m_spawnflags.m_Value & 2) != 0 )
    {
      PrecacheParticleSystem(pParticleSystemName: "env_fire_tiny");
      PrecacheParticleSystem(pParticleSystemName: "env_fire_small");
      PrecacheParticleSystem(pParticleSystemName: "env_fire_medium");
      PrecacheParticleSystem(pParticleSystemName: "env_fire_large");
    }
    else
    {
      PrecacheParticleSystem(pParticleSystemName: "env_fire_tiny_smoke");
      PrecacheParticleSystem(pParticleSystemName: "env_fire_small_smoke");
      PrecacheParticleSystem(pParticleSystemName: "env_fire_medium_smoke");
      PrecacheParticleSystem(pParticleSystemName: "env_fire_large_smoke");
    }
  }
  if ( this->m_nFireType == 1 )
    UTIL_PrecacheOther(szClassname: "_plasma", modelName: nullptr);
  CBaseEntity::PrecacheScriptSound(soundname: "Fire.Plasma");
}

//------------------------------------------------------------------------------
// Address: 0x10125080
// Name: public: virtual void CEnvFireSource::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvFireSource::Spawn(CEnvFireSource *this)
{
  if ( (this->m_spawnflags.m_Value & 1) != 0 )
  {
    if ( !this->m_bEnabled )
    {
      this->m_bEnabled = true;
      CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
    }
  }
  else if ( this->m_bEnabled )
  {
    this->m_bEnabled = false;
    CBaseEntity::SetNextThink(this, thinkTime: -1.0, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101250E0
// Name: public: virtual void CEnvFireSensor::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvFireSensor::Spawn(CEnvFireSensor *this)
{
  if ( (this->m_spawnflags.m_Value & 1) != 0 )
  {
    if ( !this->m_bEnabled )
    {
      this->m_bEnabled = true;
      CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
      this->m_bHeatAtLevel = false;
      this->m_levelTime = 0.0;
    }
  }
  else if ( this->m_bEnabled )
  {
    this->m_bEnabled = false;
    CBaseEntity::SetNextThink(this, thinkTime: -1.0, szContext: nullptr);
    if ( this->m_bHeatAtLevel )
    {
      this->m_bHeatAtLevel = false;
      COutputEvent::FireOutput(this: &this->m_OnHeatLevelEnd, pActivator: this, pCaller: this, fDelay: 0.0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10125180
// Name: public: virtual void CEnvFireSensor::Think(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvFireSensor::Think(CEnvFireSensor *this)
{
  float v2; // xmm0_4
  unsigned int v3; // ecx
  float m_radius; // xmm0_4
  float v5; // xmm0_4
  int v6; // eax
  float v7; // xmm0_4
  bool v8; // cf
  bool v9; // zf
  CFire *pFires[128]; // [esp+1Ch] [ebp-22Ch] BYREF
  float v11[7]; // [esp+21Ch] [ebp-2Ch] BYREF
  int v12; // [esp+238h] [ebp-10h]
  char v13; // [esp+23Ch] [ebp-Ch]
  float heat; // [esp+240h] [ebp-8h]
  float time; // [esp+244h] [ebp-4h]
  int savedregs; // [esp+248h] [ebp+0h] BYREF

  if ( this->m_bEnabled )
  {
    time = this->m_targetTime * 0.25;
    v2 = time;
    if ( time < 0.1 )
    {
      v2 = 0.1;
      time = 0.1;
    }
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + v2, szContext: nullptr);
    v3 = (unsigned int)this->m_iEFlags >> 11;
    heat = 0.0;
    if ( (v3 & 1) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    m_radius = this->m_radius;
    v11[1] = this->m_vecAbsOrigin.x;
    v11[2] = this->m_vecAbsOrigin.y;
    v11[3] = this->m_vecAbsOrigin.z;
    LODWORD(v11[0]) = &CFireSphere::`vftable';
    LODWORD(v11[5]) = pFires;
    LODWORD(v11[6]) = 128;
    v12 = 0;
    v13 = 1;
    v11[4] = m_radius * m_radius;
    ((void (__thiscall *)(ISpatialPartition *, int, Vector *, _DWORD, _DWORD, float *))partition->EnumerateElementsInSphere)(
      a1: partition,
      a2: 16,
      a3: &this->m_vecAbsOrigin,
      a4: LODWORD(m_radius),
      a5: 0,
      a6: v11);
    v5 = heat;
    v6 = 0;
    if ( v12 >= 4 )
    {
      do
      {
        v5 = (float)((float)((float)(v5 + pFires[v6]->m_flHeatLevel) + pFires[v6 + 1]->m_flHeatLevel)
                   + pFires[v6 + 2]->m_flHeatLevel)
           + pFires[v6 + 3]->m_flHeatLevel;
        v6 += 4;
      }
      while ( v6 < v12 - 3 );
    }
    for ( ; v6 < v12; ++v6 )
      v5 = v5 + pFires[v6]->m_flHeatLevel;
    if ( v5 < this->m_targetLevel )
    {
      v9 = !this->m_bHeatAtLevel;
      this->m_levelTime = 0.0;
      if ( !v9 )
      {
        this->m_bHeatAtLevel = false;
        COutputEvent::FireOutput(this: &this->m_OnHeatLevelEnd, pActivator: this, pCaller: this, fDelay: 0.0);
      }
    }
    else
    {
      v7 = this->m_levelTime + time;
      v8 = v7 < this->m_targetTime;
      this->m_levelTime = v7;
      if ( !v8 && !this->m_bHeatAtLevel )
      {
        this->m_bHeatAtLevel = true;
        COutputEvent::FireOutput(this: &this->m_OnHeatLevelStart, pActivator: this, pCaller: this, fDelay: 0.0);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10125400
// Name: public: CFire::CFire(void)
// Source: json
//------------------------------------------------------------------------------
CFire *__thiscall CFire::CFire(CFire *this)
{
  CBaseEntity::CBaseEntity(this, bServerOnly: false);
  this->__vftable = (CFire_vtbl *)&CFire::`vftable';
  this->m_hEffect.m_Index = -1;
  this->m_hOwner.m_Index = -1;
  this->m_OnIgnited.m_Value.iVal = 0;
  this->m_OnIgnited.m_Value.eVal.m_Index = -1;
  this->m_OnIgnited.m_Value.fieldType = FIELD_VOID;
  this->m_OnExtinguished.m_Value.iVal = 0;
  this->m_OnExtinguished.m_Value.eVal.m_Index = -1;
  this->m_OnExtinguished.m_Value.fieldType = FIELD_VOID;
  this->m_iEFlags |= 0x40000u;
  this->m_nFireType = 0;
  this->m_flFuel = 0.0;
  this->m_flAttackTime = 0.0;
  this->m_flDamageTime = 0.0;
  this->m_lastDamage = 0.0;
  this->m_flHeatAbsorb = 8.0;
  this->m_flHeatLevel = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101254A0
// Name: public: virtual void CFire::DrawDebugGeometryOverlays(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFire::DrawDebugGeometryOverlays(CFire *this)
{
  CBaseEntity *v2; // ecx
  char tempstr[512]; // [esp+18h] [ebp-218h] BYREF
  Vector maxs; // [esp+218h] [ebp-18h] BYREF
  Vector mins; // [esp+224h] [ebp-Ch] BYREF
  int savedregs; // [esp+230h] [ebp+0h] BYREF

  if ( (this->m_debugOverlays & 4) != 0 )
  {
    if ( this->m_lastDamage <= gpGlobals->curtime || this->m_flHeatAbsorb <= 0.0 )
    {
      if ( this->m_flHeatLevel <= 0.0 )
        NDebugOverlay::EntityBounds(pEntity: this, r: 88, g: 88, b: 128, a: 0, flDuration: 0.0);
    }
    else
    {
      NDebugOverlay::EntityBounds(pEntity: this, r: 88, g: 255, b: 128, a: 0, flDuration: 0.0);
      V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "Heat: %.1f", this->m_flHeatAbsorb);
      CBaseEntity::EntityText(this, text_offset: 1, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    }
    if ( this->m_flHeatLevel > 0.0 && CFire::GetFireDimensions(this, pFireMins: &mins, pFireMaxs: &maxs) != 0 )
    {
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: v2, a2: (int)&savedregs);
      NDebugOverlay::Box(origin: &this->m_vecAbsOrigin, &mins, &maxs, r: 128, g: 0, b: 0, a: 10, flDuration: 0.0);
    }
  }
  CBaseEntity::DrawDebugGeometryOverlays(this);
}

//------------------------------------------------------------------------------
// Address: 0x10125630
// Name: public: bool CFire::GoOut(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CFire::GoOut(CFire *this)
{
  unsigned int m_Index; // eax
  CBaseEntity **v3; // ecx
  CBaseEntity *v4; // edi
  float v5; // xmm0_4
  Vector vecMin; // [esp+10h] [ebp-18h] BYREF
  Vector vecMax; // [esp+1Ch] [ebp-Ch] BYREF

  COutputEvent::FireOutput(this: &this->m_OnExtinguished, pActivator: this, pCaller: this, fDelay: 0.0);
  m_Index = this->m_hEffect.m_Index;
  if ( m_Index != -1 )
  {
    v3 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
    {
      v4 = *v3;
      if ( *v3 != nullptr )
      {
        ((void (__thiscall *)(CBaseEntity *, _DWORD))v4->__vftable[1].GetRefEHandle)(a1: v4, a2: 0);
        UTIL_Remove(oldObj: v4);
      }
    }
  }
  v5 = this->m_flHeatLevel - 20.0;
  this->m_flHeatLevel = v5;
  if ( v5 > 0.0 )
    this->m_flHeatLevel = 0.0;
  this->m_flLastHeatLevel = this->m_flHeatLevel;
  CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
  CBaseEntity::SetNextThink(this, thinkTime: -1.0, szContext: nullptr);
  if ( SLOBYTE(this->m_spawnflags.m_Value) >= 0 )
  {
    vecMax.x = 8.0;
    vecMax.y = 8.0;
    vecMax.z = 8.0;
    vecMin.x = -8.0;
    vecMin.y = -8.0;
    vecMin.z = 0.0;
    UTIL_SetSize(pEnt: this, &vecMin, &vecMax);
    return 0;
  }
  else
  {
    UTIL_Remove(oldObj: this);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101257E0
// Name: public: virtual void CFire::UpdateOnRemove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFire::UpdateOnRemove(CFire *this)
{
  unsigned int m_Index; // ecx
  CBaseEntity **v3; // eax
  CBaseEntity *v4; // esi

  CBaseEntity::StopSound(this, soundname: "Fire.Plasma");
  m_Index = this->m_hEffect.m_Index;
  if ( m_Index != -1 )
  {
    v3 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
    {
      v4 = *v3;
      if ( *v3 != nullptr )
      {
        ((void (__thiscall *)(CBaseEntity *, _DWORD))v4->__vftable[1].GetRefEHandle)(a1: v4, a2: 0);
        UTIL_Remove(oldObj: v4);
      }
    }
  }
  CBaseEntity::UpdateOnRemove(this);
}

//------------------------------------------------------------------------------
// Address: 0x10125840
// Name: protected: void CFire::SpawnEffect(enum fireType_e,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFire::SpawnEffect(CFire *this, fireType_e type, float scale)
{
  CFireSmoke *EntityByName; // edi
  int savedregs; // [esp+24h] [ebp+0h] BYREF

  if ( type == FIRE_PLASMA )
  {
    EntityByName = (CFireSmoke *)CreateEntityByName(className: "_plasma", iForceEdictIndex: -1, bNotify: true);
    CPlasma::EnableSmoke(this: EntityByName, state: 1);
    this->m_nFireType = 1;
    if ( this->m_takedamage.m_Value != 2 )
    {
      this->NetworkStateChanged_m_takedamage(this, a2: &this->m_takedamage);
      this->m_takedamage.m_Value = 2;
    }
    CBaseEntity::EmitSound(this, soundname: "Fire.Plasma", soundtime: 0.0, duration: nullptr);
  }
  else
  {
    EntityByName = (CFireSmoke *)CreateEntityByName(className: "_firesmoke", iForceEdictIndex: -1, bNotify: true);
    CPlasma::EnableSmoke(this: EntityByName, state: (this->m_spawnflags.m_Value & 2) == 0);
    CFireSmoke::EnableGlow(this: EntityByName, state: (this->m_spawnflags.m_Value & 0x20) == 0);
    CFireSmoke::EnableVisibleFromAbove(this: EntityByName, state: (this->m_spawnflags.m_Value & 0x100) != 0);
    this->m_nFireType = 0;
    if ( this->m_takedamage.m_Value != 2 )
    {
      this->NetworkStateChanged_m_takedamage(this, a2: &this->m_takedamage);
      this->m_takedamage.m_Value = 2;
    }
  }
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  UTIL_SetOrigin(entity: EntityByName, vecOrigin: &this->m_vecAbsOrigin, bFireTriggers: false);
  EntityByName->Spawn(this: EntityByName);
  EntityByName->SetParent(this: EntityByName, a2: this, a3: -1);
  ((void (__thiscall *)(CFireSmoke *, _DWORD, _DWORD, _DWORD))EntityByName->Scale)(
    a1: EntityByName,
    a2: LODWORD(this->m_flFireSize),
    a3: LODWORD(this->m_flFireSize),
    a4: 0);
  EntityByName->Enable(this: EntityByName, a2: this->m_spawnflags.m_Value & 4);
  this->m_hEffect.m_Index = EntityByName->GetRefEHandle(this: EntityByName)->m_Index;
}

//------------------------------------------------------------------------------
// Address: 0x101259D0
// Name: public: void CFire::Init(class Vector const __near &,float,float,float,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFire::Init(
        CFire *this,
        const Vector *position,
        float scale,
        float attackTime,
        float fuel,
        int flags,
        int fireType)
{
  edict_t *m_pPev; // ecx
  float v9; // xmm0_4
  int v10; // ebx
  edict_t *v11; // ecx
  unsigned int m_Index; // ecx
  float z; // eax
  int v14; // eax
  CEntInfo *v15; // edx
  unsigned int v16; // ecx
  int v17; // eax
  bool v18; // zf
  CBaseEntity **v19; // eax
  CBaseEntity *v20; // eax
  float v21; // ecx
  float v22; // xmm0_4
  EntityMatrix parentMatrix; // [esp+0h] [ebp-58h] BYREF
  __int64 v24; // [esp+40h] [ebp-18h]
  float v25; // [esp+48h] [ebp-10h]
  Vector localOrigin; // [esp+4Ch] [ebp-Ch] BYREF

  this->m_flAttackTime = attackTime;
  if ( this->m_spawnflags.m_Value != flags )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x2F8u);
    }
    this->m_spawnflags.m_Value = flags;
  }
  this->m_nFireType = fireType;
  if ( (flags & 1) != 0 )
    v9 = 0.0;
  else
    v9 = fuel;
  this->m_flFuel = v9;
  if ( v9 != 0.0 )
  {
    v10 = this->m_spawnflags.m_Value | 0x80;
    if ( this->m_spawnflags.m_Value != v10 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v11 = this->m_Network.m_pPev;
        if ( v11 != nullptr )
          CBaseEdict::StateChanged(this: &v11->CBaseEdict, offset: 0x2F8u);
      }
      this->m_spawnflags.m_Value = v10;
    }
  }
  m_Index = this->m_hMoveParent.m_Value.m_Index;
  z = position->z;
  *(_QWORD *)&localOrigin.x = *(_QWORD *)&position->x;
  localOrigin.z = z;
  if ( m_Index != -1 )
  {
    v14 = (unsigned __int16)m_Index;
    v15 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v16 = HIWORD(m_Index);
    if ( v15->m_SerialNumber == v16 && v15->m_pEntity != nullptr )
    {
      v17 = v14;
      v18 = g_pEntityList->m_EntPtrArray[v17].m_SerialNumber == v16;
      v19 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[v17];
      if ( v18 )
        v20 = *v19;
      else
        v20 = nullptr;
      EntityMatrix::InitFromEntity(this: &parentMatrix, pEntity: v20, iAttachment: 0);
      v21 = position->z;
      v24 = *(_QWORD *)&position->x;
      v25 = v21;
      localOrigin.x = (float)((float)(parentMatrix.m[0][0] * (float)(*(float *)&v24 - parentMatrix.m[0][3]))
                            + (float)((float)(*((float *)&v24 + 1) - parentMatrix.m[1][3]) * parentMatrix.m[1][0]))
                    + (float)((float)(v21 - parentMatrix.m[2][3]) * parentMatrix.m[2][0]);
      localOrigin.y = (float)((float)(parentMatrix.m[1][1] * (float)(*((float *)&v24 + 1) - parentMatrix.m[1][3]))
                            + (float)(parentMatrix.m[0][1] * (float)(*(float *)&v24 - parentMatrix.m[0][3])))
                    + (float)(parentMatrix.m[2][1] * (float)(v21 - parentMatrix.m[2][3]));
      localOrigin.z = (float)((float)(parentMatrix.m[1][2] * (float)(*((float *)&v24 + 1) - parentMatrix.m[1][3]))
                            + (float)(parentMatrix.m[0][2] * (float)(*(float *)&v24 - parentMatrix.m[0][3])))
                    + (float)(parentMatrix.m[2][2] * (float)(v21 - parentMatrix.m[2][3]));
    }
  }
  UTIL_SetOrigin(entity: this, vecOrigin: &localOrigin, bFireTriggers: false);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
  v18 = (this->m_spawnflags.m_Value & 8) == 0;
  this->m_flFireSize = scale;
  v22 = (float)(scale * 0.00390625) * 64.0;
  this->m_flMaxHeat = v22;
  if ( !v18 )
    this->m_flHeatLevel = v22;
  this->m_flLastHeatLevel = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10125C00
// Name: public: void CFire::Start(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFire::Start(CFire *this)
{
  float m_flFireSize; // xmm1_4
  float thinkTime; // [esp+0h] [ebp-24h]
  Vector vecMin; // [esp+Ch] [ebp-18h] BYREF
  Vector vecMax; // [esp+18h] [ebp-Ch] BYREF

  m_flFireSize = this->m_flFireSize;
  vecMax.x = (float)(m_flFireSize * 0.5) * 0.5;
  vecMax.y = vecMax.x;
  LODWORD(vecMin.x) = LODWORD(vecMax.x) ^ _mask__NegFloat_;
  LODWORD(vecMin.y) = LODWORD(vecMax.x) ^ _mask__NegFloat_;
  vecMax.z = m_flFireSize;
  vecMin.z = 0.0;
  UTIL_SetSize(pEnt: this, &vecMin, &vecMax);
  CFire::SpawnEffect(this, type: (fireType_e)this->m_nFireType, scale: this->m_flFireSize * 0.00390625);
  COutputEvent::FireOutput(this: &this->m_OnIgnited, pActivator: this, pCaller: this, fDelay: 0.0);
  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CFire::BurnThink,
    thinkTime: 0.0,
    szContext: nullptr);
  this->m_flLastNavUpdateTime = 0.0;
  this->m_flDamageTime = 0.0;
  thinkTime = gpGlobals->curtime + 0.1;
  CBaseEntity::SetNextThink(this, thinkTime, szContext: nullptr);
  ((void (__thiscall *)(CFire *, int))this->Update)(a1: this, a2: 1036831949);
}

//------------------------------------------------------------------------------
// Address: 0x10125D10
// Name: public: void CFire::GoOutThink(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CFire::GoOutThink(CFire *this)
{
  CFire::GoOut(this);
}

//------------------------------------------------------------------------------
// Address: 0x10125D20
// Name: public: void CFire::GoOutInSeconds(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFire::GoOutInSeconds(CFire *this, float seconds)
{
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx

  m_Index = this->m_hEffect.m_Index;
  if ( m_Index != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
  {
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    if ( m_pEntity != nullptr )
      ((void (__thiscall *)(IHandleEntity *, _DWORD, _DWORD))m_pEntity->__vftable[65].dtr_IHandleEntity)(
        a1: m_pEntity,
        a2: 0,
        a3: LODWORD(seconds));
  }
  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CFire::GoOutThink,
    thinkTime: 0.0,
    szContext: nullptr);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + seconds, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10125E10
// Name: public: void CFire::InputDisable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFire::InputDisable(CFire *this, inputdata_t *inputdata)
{
  float m_flHeatLevel; // xmm0_4

  m_flHeatLevel = this->m_flHeatLevel;
  this->m_bEnabled = false;
  if ( m_flHeatLevel > 0.0 )
    CFire::GoOut(this);
}

//------------------------------------------------------------------------------
// Address: 0x10125E30
// Name: public: void CFire::InputExtinguish(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFire::InputExtinguish(CFire *this, inputdata_t *inputdata)
{
  unsigned int v3; // esi
  edict_t *m_pPev; // ecx

  v3 = this->m_spawnflags.m_Value & 0xFFFFFFFE;
  if ( this->m_spawnflags.m_Value != v3 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x2F8u);
    }
    this->m_spawnflags.m_Value = v3;
  }
  if ( inputdata->value.fieldType == FIELD_FLOAT )
    CFire::GoOutInSeconds(this, seconds: inputdata->value.flVal);
  else
    CFire::GoOutInSeconds(this, seconds: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x10125EB0
// Name: public: void CFire::InputExtinguishTemporary(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFire::InputExtinguishTemporary(CFire *this, inputdata_t *inputdata)
{
  if ( inputdata->value.fieldType == FIELD_FLOAT )
    CFire::GoOutInSeconds(this, seconds: inputdata->value.flVal);
  else
    CFire::GoOutInSeconds(this, seconds: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x10125EF0
// Name: public: void CFire::StartFire(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFire::StartFire(CFire *this)
{
  unsigned int m_Index; // eax
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_spawnflags> *p_m_spawnflags; // edi
  float z; // xmm0_4
  int m_iEFlags; // edx
  int m_Value; // eax
  int v7; // ebx
  edict_t *m_pPev; // ecx
  int v9; // esi
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_spawnflags> *v10; // eax
  CBaseEdict *v11; // ecx
  CGameTrace tr; // [esp+20h] [ebp-64h] BYREF
  Vector vFirePos; // [esp+74h] [ebp-10h] BYREF
  int spawnflags; // [esp+80h] [ebp-4h]
  IHandleEntity savedregs; // [esp+84h] [ebp+0h] BYREF

  m_Index = this->m_hEffect.m_Index;
  if ( m_Index == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
  {
    p_m_spawnflags = &this->m_spawnflags;
    if ( (this->m_spawnflags.m_Value & 0x10) != 0 )
    {
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      vFirePos.x = this->m_vecAbsOrigin.x;
      vFirePos.y = this->m_vecAbsOrigin.y;
      z = this->m_vecAbsOrigin.z;
    }
    else
    {
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      m_iEFlags = this->m_iEFlags;
      vFirePos.x = this->m_vecAbsOrigin.x;
      vFirePos.y = this->m_vecAbsOrigin.y;
      vFirePos.z = this->m_vecAbsOrigin.z - 1024.0;
      if ( (m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      UTIL_TraceLine(
        a1: &savedregs,
        a2: (int)this,
        vecAbsStart: &this->m_vecAbsOrigin,
        vecAbsEnd: &vFirePos,
        mask: 0x4003u,
        ignore: this,
        collisionGroup: 0,
        ptr: &tr);
      vFirePos.x = tr.endpos.x;
      vFirePos.y = tr.endpos.y;
      z = tr.endpos.z;
    }
    m_Value = p_m_spawnflags->m_Value;
    v7 = p_m_spawnflags->m_Value | 4;
    vFirePos.z = z;
    spawnflags = m_Value;
    if ( m_Value != v7 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x2F8u);
      }
      p_m_spawnflags->m_Value = v7;
    }
    CFire::Init(
      this,
      position: &vFirePos,
      scale: this->m_flFireSize,
      attackTime: this->m_flAttackTime,
      fuel: (float)this->m_iHealth.m_Value,
      flags: p_m_spawnflags->m_Value,
      fireType: this->m_nFireType);
    CFire::Start(this);
    v9 = spawnflags;
    if ( p_m_spawnflags->m_Value != spawnflags )
    {
      v10 = p_m_spawnflags - 190;
      if ( LOBYTE(p_m_spawnflags[-169].m_Value) != 0 )
      {
        LOBYTE(v10[22].m_Value) |= 1u;
        p_m_spawnflags->m_Value = v9;
      }
      else
      {
        v11 = (CBaseEdict *)v10[6].m_Value;
        if ( v11 != nullptr )
          CBaseEdict::StateChanged(this: v11, offset: 0x2F8u);
        p_m_spawnflags->m_Value = v9;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101260D0
// Name: public: virtual void CFire::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFire::Spawn(CFire *this)
{
  float v2; // xmm0_4
  unsigned int v3; // edx
  float m_flHeatLevel; // xmm0_4
  Vector vecMin; // [esp+20h] [ebp-18h] BYREF
  Vector vecMax; // [esp+2Ch] [ebp-Ch] BYREF
  int savedregs; // [esp+38h] [ebp+0h] BYREF

  CAI_BaseNPC::OnSetSchedule((vgui::Panel *)this);
  this->Precache(this);
  if ( this->m_takedamage.m_Value != 0 )
  {
    this->NetworkStateChanged_m_takedamage(this, a2: &this->m_takedamage);
    this->m_takedamage.m_Value = 0;
  }
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
  CBaseEntity::AddEffects(this, nEffects: 32);
  vecMax.x = 8.0;
  vecMax.y = 8.0;
  vecMax.z = 8.0;
  vecMin.x = -8.0;
  vecMin.y = -8.0;
  vecMin.z = 0.0;
  UTIL_SetSize(pEnt: this, &vecMin, &vecMax);
  v2 = this->m_flHeatLevel * 0.05;
  v3 = (unsigned int)this->m_iEFlags >> 11;
  this->m_flHeatAbsorb = v2;
  this->m_flHeatLevel = 0.0;
  if ( (v3 & 1) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  CFire::Init(
    this,
    position: &this->m_vecAbsOrigin,
    scale: this->m_flFireSize,
    attackTime: this->m_flAttackTime,
    fuel: this->m_flFuel,
    flags: this->m_spawnflags.m_Value,
    fireType: this->m_nFireType);
  if ( this->m_bStartDisabled )
  {
    m_flHeatLevel = this->m_flHeatLevel;
    this->m_bEnabled = false;
    if ( m_flHeatLevel > 0.0 )
      CFire::GoOut(this);
  }
  else
  {
    this->m_bEnabled = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10126230
// Name: public: virtual void CFire::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFire::Activate(CFire *this)
{
  CBaseEntity::Activate(this);
  if ( !this->m_bDidActivate && (this->m_spawnflags.m_Value & 4) != 0 )
  {
    this->m_flHeatLevel = this->m_flMaxHeat;
    CFire::StartFire(this);
  }
  this->m_bDidActivate = true;
}

//------------------------------------------------------------------------------
// Address: 0x10126270
// Name: public: void CFire::AddHeat(float,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFire::AddHeat(CFire *this, float heat, bool selfHeat)
{
  float v4; // xmm2_4
  bool v5; // cf
  char v6; // al
  float m_flHeatAbsorb; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  float m_flMaxHeat; // xmm0_4

  if ( this->m_bEnabled )
  {
    if ( selfHeat || this->m_flHeatLevel <= 0.0 )
      v4 = heat;
    else
      v4 = fire_incomingheatscale.m_pParent->m_Value.m_fValue * heat;
    v5 = this->m_flHeatLevel > 0.0;
    this->m_lastDamage = gpGlobals->curtime + 0.5;
    v6 = !v5;
    m_flHeatAbsorb = this->m_flHeatAbsorb;
    if ( m_flHeatAbsorb > 0.0 )
    {
      v8 = fire_absorbrate.m_pParent->m_Value.m_fValue * v4;
      if ( v8 <= m_flHeatAbsorb )
      {
        this->m_flHeatAbsorb = m_flHeatAbsorb - v8;
        v4 = 0.0;
      }
      else
      {
        v4 = v4 - (float)(m_flHeatAbsorb / fire_absorbrate.m_pParent->m_Value.m_fValue);
        this->m_flHeatAbsorb = 0.0;
      }
    }
    v9 = this->m_flHeatLevel + v4;
    this->m_flHeatLevel = v9;
    if ( v6 != 0
      && v9 > 0.0
      && CHandle<CBaseEntity>::operator==(this: (CHandle<CBaseEntity> *)&this->m_hEffect, val: nullptr) )
    {
      CFire::StartFire(this);
    }
    m_flMaxHeat = this->m_flMaxHeat;
    if ( this->m_flHeatLevel > m_flMaxHeat )
      this->m_flHeatLevel = m_flMaxHeat;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10126380
// Name: public: virtual void CEnvFireSource::Think(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvFireSource::Think(CEnvFireSource *this)
{
  int v2; // ebx
  float m_radius; // xmm0_4
  CFire *v4; // esi
  float v5; // xmm1_4
  bool v6; // cf
  char v7; // al
  float m_flHeatAbsorb; // xmm0_4
  float v9; // xmm2_4
  float v10; // xmm0_4
  unsigned int m_Index; // eax
  float m_flMaxHeat; // xmm0_4
  CFire *pFires[128]; // [esp+18h] [ebp-224h] BYREF
  float v14[7]; // [esp+218h] [ebp-24h] BYREF
  int v15; // [esp+234h] [ebp-8h]
  char v16; // [esp+238h] [ebp-4h]
  int savedregs; // [esp+23Ch] [ebp+0h] BYREF

  if ( this->m_bEnabled )
  {
    v2 = 0;
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.25, szContext: nullptr);
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    m_radius = this->m_radius;
    v14[1] = this->m_vecAbsOrigin.x;
    v14[2] = this->m_vecAbsOrigin.y;
    v14[3] = this->m_vecAbsOrigin.z;
    LODWORD(v14[0]) = &CFireSphere::`vftable';
    LODWORD(v14[5]) = pFires;
    LODWORD(v14[6]) = 128;
    v15 = 0;
    v16 = 0;
    v14[4] = m_radius * m_radius;
    ((void (__thiscall *)(ISpatialPartition *, int, Vector *, _DWORD, _DWORD, float *))partition->EnumerateElementsInSphere)(
      a1: partition,
      a2: 16,
      a3: &this->m_vecAbsOrigin,
      a4: LODWORD(m_radius),
      a5: 0,
      a6: v14);
    if ( v15 > 0 )
    {
      do
      {
        v4 = pFires[v2];
        v5 = this->m_damage * 0.25;
        if ( v4->m_bEnabled )
        {
          if ( v4->m_flHeatLevel > 0.0 )
            v5 = fire_incomingheatscale.m_pParent->m_Value.m_fValue * v5;
          v6 = v4->m_flHeatLevel > 0.0;
          v4->m_lastDamage = gpGlobals->curtime + 0.5;
          v7 = !v6;
          m_flHeatAbsorb = v4->m_flHeatAbsorb;
          if ( m_flHeatAbsorb > 0.0 )
          {
            v9 = fire_absorbrate.m_pParent->m_Value.m_fValue * v5;
            if ( v9 <= m_flHeatAbsorb )
            {
              v4->m_flHeatAbsorb = m_flHeatAbsorb - v9;
              v5 = 0.0;
            }
            else
            {
              v5 = v5 - (float)(m_flHeatAbsorb / fire_absorbrate.m_pParent->m_Value.m_fValue);
              v4->m_flHeatAbsorb = 0.0;
            }
          }
          v10 = v4->m_flHeatLevel + v5;
          v4->m_flHeatLevel = v10;
          if ( v7 != 0 && v10 > 0.0 )
          {
            m_Index = v4->m_hEffect.m_Index;
            if ( m_Index == -1
              || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
              || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
            {
              CFire::StartFire(this: v4);
            }
          }
          m_flMaxHeat = v4->m_flMaxHeat;
          if ( v4->m_flHeatLevel > m_flMaxHeat )
            v4->m_flHeatLevel = m_flMaxHeat;
        }
        ++v2;
      }
      while ( v2 < v15 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10126590
// Name: void FireSystem_AddHeatInRadius(class Vector const __near &,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FireSystem_AddHeatInRadius(const Vector *origin, float radius, float heat)
{
  int v3; // edi
  float v4; // xmm5_4
  CFire *v5; // esi
  float v6; // xmm1_4
  bool v7; // cf
  char v8; // al
  float m_flHeatAbsorb; // xmm0_4
  float v10; // xmm2_4
  float v11; // xmm0_4
  unsigned int m_Index; // eax
  float m_flMaxHeat; // xmm0_4
  CFire *pFires[32]; // [esp+14h] [ebp-A4h] BYREF
  void **v15; // [esp+94h] [ebp-24h] BYREF
  Vector v16; // [esp+98h] [ebp-20h]
  float v17; // [esp+A4h] [ebp-14h]
  CFire **v18; // [esp+A8h] [ebp-10h]
  int v19; // [esp+ACh] [ebp-Ch]
  int v20; // [esp+B0h] [ebp-8h]
  char v21; // [esp+B4h] [ebp-4h]

  v18 = pFires;
  v16 = *origin;
  v15 = &CFireSphere::`vftable';
  v19 = 32;
  v20 = 0;
  v21 = 0;
  v17 = radius * radius;
  ((void (__thiscall *)(ISpatialPartition *, int, const Vector *, _DWORD, _DWORD, void ***))partition->EnumerateElementsInSphere)(
    a1: partition,
    a2: 16,
    a3: origin,
    a4: LODWORD(radius),
    a5: 0,
    a6: &v15);
  v3 = 0;
  if ( v20 > 0 )
  {
    v4 = heat;
    do
    {
      v5 = pFires[v3];
      v6 = v4;
      if ( v5->m_bEnabled )
      {
        if ( v5->m_flHeatLevel > 0.0 )
          v6 = fire_incomingheatscale.m_pParent->m_Value.m_fValue * v4;
        v7 = v5->m_flHeatLevel > 0.0;
        v5->m_lastDamage = gpGlobals->curtime + 0.5;
        v8 = !v7;
        m_flHeatAbsorb = v5->m_flHeatAbsorb;
        if ( m_flHeatAbsorb > 0.0 )
        {
          v10 = fire_absorbrate.m_pParent->m_Value.m_fValue * v6;
          if ( v10 <= m_flHeatAbsorb )
          {
            v5->m_flHeatAbsorb = m_flHeatAbsorb - v10;
            v6 = 0.0;
          }
          else
          {
            v6 = v6 - (float)(m_flHeatAbsorb / fire_absorbrate.m_pParent->m_Value.m_fValue);
            v5->m_flHeatAbsorb = 0.0;
          }
        }
        v11 = v5->m_flHeatLevel + v6;
        v5->m_flHeatLevel = v11;
        if ( v8 != 0 && v11 > 0.0 )
        {
          m_Index = v5->m_hEffect.m_Index;
          if ( m_Index == -1
            || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
            || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
          {
            CFire::StartFire(this: v5);
            v4 = heat;
          }
        }
        m_flMaxHeat = v5->m_flMaxHeat;
        if ( v5->m_flHeatLevel > m_flMaxHeat )
          v5->m_flHeatLevel = m_flMaxHeat;
      }
      ++v3;
    }
    while ( v3 < v20 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10126750
// Name: public: void CFire::InputStartFire(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFire::InputStartFire(CFire *this, inputdata_t *inputdata)
{
  if ( this->m_bEnabled )
    CFire::StartFire(this);
}

//------------------------------------------------------------------------------
// Address: 0x10126770
// Name: public: virtual void CFire::Update(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFire::Update(CFire *this, float simTime)
{
  float m_flFuel; // xmm0_4
  float v4; // xmm0_4
  float m_flHeatLevel; // xmm1_4
  bool v6; // zf
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  float m_flAttackTime; // xmm1_4
  float m_flMaxHeat; // xmm0_4
  float v11; // xmm0_4
  float x; // xmm4_4
  float y; // xmm6_4
  float v14; // xmm5_4
  float v15; // xmm7_4
  float v16; // xmm1_4
  int m_iEFlags; // ecx
  int v18; // edx
  float v19; // xmm4_4
  float v20; // xmm0_4
  int v21; // eax
  float v22; // xmm5_4
  float v23; // xmm0_4
  int v24; // ecx
  int v25; // ecx
  float curtime; // xmm0_4
  bool v27; // cf
  int v28; // eax
  int v29; // ebx
  CFire *v30; // edi
  int v31; // eax
  const Vector *v32; // eax
  const CTakeDamageInfo *v33; // eax
  int v34; // edi
  float v35; // xmm5_4
  CFire *v36; // esi
  float v37; // xmm1_4
  char v38; // al
  float m_flHeatAbsorb; // xmm0_4
  float v40; // xmm2_4
  float v41; // xmm0_4
  unsigned int v42; // eax
  float v43; // xmm0_4
  const Vector *v44; // [esp+4h] [ebp-578h]
  CBaseEntity *pNearby[256]; // [esp+24h] [ebp-558h] BYREF
  CTakeDamageInfo v46; // [esp+424h] [ebp-158h] BYREF
  CFire *pFires[16]; // [esp+480h] [ebp-FCh]
  CGameTrace tr; // [esp+4C0h] [ebp-BCh] BYREF
  Vector otherMaxs; // [esp+514h] [ebp-68h] BYREF
  CFlaggedEntitiesEnum pEnum; // [esp+520h] [ebp-5Ch] BYREF
  int nearbyCount; // [esp+534h] [ebp-48h]
  int outputDamage; // [esp+538h] [ebp-44h]
  Vector fireEntityDamageMins; // [esp+53Ch] [ebp-40h] BYREF
  Vector fireEntityDamageMaxs; // [esp+548h] [ebp-34h] BYREF
  Vector fireMins; // [esp+554h] [ebp-28h] BYREF
  Vector fireMaxs; // [esp+560h] [ebp-1Ch] BYREF
  float outputHeat; // [esp+56Ch] [ebp-10h]
  int i; // [esp+570h] [ebp-Ch]
  int fireCount; // [esp+574h] [ebp-8h]
  bool damage; // [esp+57Bh] [ebp-1h]
  IHandleEntity savedregs; // [esp+57Ch] [ebp+0h] BYREF

  m_flFuel = this->m_flFuel;
  if ( m_flFuel == 0.0 || (v4 = m_flFuel - simTime, this->m_flFuel = v4, v4 > 0.0) )
  {
    m_flHeatLevel = this->m_flHeatLevel;
    v6 = m_flHeatLevel == this->m_flLastHeatLevel;
    *(float *)&i = m_flHeatLevel * 0.015625;
    if ( !v6 )
    {
      this->m_flLastHeatLevel = m_flHeatLevel;
      m_Index = this->m_hEffect.m_Index;
      if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
        m_pEntity = nullptr;
      else
        m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      ((void (__thiscall *)(IHandleEntity *, _DWORD, int))m_pEntity->__vftable[65].dtr_IHandleEntity)(
        a1: m_pEntity,
        a2: m_flHeatLevel * 0.015625,
        a3: 1056964608);
    }
    m_flAttackTime = this->m_flAttackTime;
    m_flMaxHeat = this->m_flMaxHeat;
    if ( m_flAttackTime > 0.0 )
      m_flMaxHeat = m_flMaxHeat / m_flAttackTime;
    CFire::AddHeat(
      this,
      heat: (float)(fire_growthrate.m_pParent->m_Value.m_fValue * simTime) * m_flMaxHeat,
      selfHeat: true);
    v11 = this->m_flHeatLevel;
    outputHeat = v11 * *(float *)&i;
    if ( v11 > 0.0 )
    {
      v15 = this->m_flFireSize * (float)(v11 / this->m_flMaxHeat);
      v16 = (float)((float)((float)(v15 * 128.0) * 0.00390625) * 0.5) * 2.0;
      if ( v16 < 16.0 )
        v16 = 16.0;
      LODWORD(x) = LODWORD(v16) ^ _mask__NegFloat_;
      LODWORD(y) = LODWORD(v16) ^ _mask__NegFloat_;
      v14 = v16;
      fireMaxs.y = v16;
    }
    else
    {
      x = 0.0;
      y = 0.0;
      v14 = 0.0;
      fireMaxs.y = 0.0;
      v15 = 0.0;
    }
    m_iEFlags = this->m_iEFlags;
    fireMins.z = 0.0;
    fireEntityDamageMins.x = x * 0.5;
    fireEntityDamageMins.y = y * 0.5;
    fireEntityDamageMins.z = 0.0;
    fireMaxs.z = v15;
    fireMaxs.x = v14;
    fireMins.y = y;
    fireMins.x = x;
    fireEntityDamageMaxs.x = v14 * 0.5;
    fireEntityDamageMaxs.y = fireMaxs.y * 0.5;
    fireEntityDamageMaxs.z = v15 * 0.5;
    if ( (m_iEFlags & 0x800) != 0 )
    {
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      y = fireMins.y;
      x = fireMins.x;
      v14 = fireMaxs.x;
    }
    v18 = this->m_iEFlags;
    v19 = x + this->m_vecAbsOrigin.x;
    fireMins.y = this->m_vecAbsOrigin.y + y;
    v20 = this->m_vecAbsOrigin.z + fireMins.z;
    fireMins.x = v19;
    fireMins.z = v20;
    if ( (v18 & 0x800) != 0 )
    {
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      v14 = fireMaxs.x;
    }
    v21 = this->m_iEFlags;
    v22 = v14 + this->m_vecAbsOrigin.x;
    fireMaxs.y = this->m_vecAbsOrigin.y + fireMaxs.y;
    v23 = this->m_vecAbsOrigin.z + fireMaxs.z;
    fireMaxs.x = v22;
    fireMaxs.z = v23;
    if ( (v21 & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    v24 = this->m_iEFlags;
    fireEntityDamageMins.x = fireEntityDamageMins.x + this->m_vecAbsOrigin.x;
    fireEntityDamageMins.y = this->m_vecAbsOrigin.y + fireEntityDamageMins.y;
    fireEntityDamageMins.z = this->m_vecAbsOrigin.z + fireEntityDamageMins.z;
    if ( (v24 & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    fireEntityDamageMaxs.x = fireEntityDamageMaxs.x + this->m_vecAbsOrigin.x;
    fireEntityDamageMaxs.y = this->m_vecAbsOrigin.y + fireEntityDamageMaxs.y;
    fireEntityDamageMaxs.z = this->m_vecAbsOrigin.z + fireEntityDamageMaxs.z;
    CFlaggedEntitiesEnum::CFlaggedEntitiesEnum(this: &pEnum, pList: pNearby, listMax: 256, flagMask: 0);
    v25 = UTIL_EntitiesInBox(mins: &fireMins, maxs: &fireMaxs, &pEnum);
    curtime = gpGlobals->curtime;
    v27 = curtime < this->m_flDamageTime;
    nearbyCount = v25;
    fireCount = 0;
    damage = false;
    outputDamage = 0;
    if ( !v27 )
    {
      this->m_flDamageTime = fire_dmginterval.m_pParent->m_Value.m_fValue + curtime;
      outputDamage = (int)(float)((float)((float)((float)(fire_dmgscale.m_pParent->m_Value.m_fValue * outputHeat)
                                                * this->m_flDamageScale)
                                        + fire_dmgbase.m_pParent->m_Value.m_fValue)
                                * fire_dmginterval.m_pParent->m_Value.m_fValue);
      if ( outputDamage != 0 )
        damage = true;
    }
    v28 = 0;
    v29 = this->m_nFireType != 0 ? 0x1000000 : 8;
    *(float *)&i = 0.0;
    if ( v25 > 0 )
    {
      do
      {
        v30 = (CFire *)pNearby[v28];
        if ( v30 != this )
        {
          if ( v30 != nullptr
            && (v30->m_iClassname.pszValue == "env_fire"
             || CBaseEntity::ClassMatchesComplex(this: v30, pszClassOrWildcard: "env_fire") != 0) )
          {
            v31 = fireCount;
            if ( (unsigned int)fireCount < 0x10 )
            {
              pFires[fireCount] = v30;
              fireCount = v31 + 1;
            }
          }
          else if ( v30->m_takedamage.m_Value != 0 && damage )
          {
            CCollisionProperty::CollisionAABBToWorldAABB(
              this: &v30->m_Collision,
              entityMins: &v30->m_Collision.m_vecMins.m_Value,
              entityMaxs: &v30->m_Collision.m_vecMaxs.m_Value,
              pWorldMins: (Vector *)&pEnum.m_listMax,
              pWorldMaxs: &otherMaxs);
            if ( IsBoxIntersectingBox(
                   boxMin1: (const Vector *)&pEnum.m_listMax,
                   boxMax1: &otherMaxs,
                   boxMin2: &fireEntityDamageMins,
                   boxMax2: &fireEntityDamageMaxs) )
            {
              v44 = v30->WorldSpaceCenter(this: v30);
              v32 = this->WorldSpaceCenter(this);
              UTIL_TraceLine(
                a1: &savedregs,
                a2: (int)this,
                vecAbsStart: v32,
                vecAbsEnd: v44,
                mask: 0x4003u,
                ignore: v30,
                collisionGroup: 0,
                ptr: &tr);
              if ( tr.fraction == 1.0 && !tr.startsolid )
              {
                v33 = CTakeDamageInfo::CTakeDamageInfo(
                        this: &v46,
                        pInflictor: this,
                        pAttacker: this,
                        flDamage: (float)outputDamage,
                        bitsDamageType: v29,
                        iKillType: 0,
                        iObjectsPenetrated: 0);
                CBaseEntity::TakeDamage(this: v30, a2: (int)this, inputInfo: v33);
              }
            }
          }
        }
        v28 = i + 1;
        i = v28;
      }
      while ( v28 < nearbyCount );
      if ( fireCount > 0 )
      {
        v34 = 0;
        v35 = (float)((float)(fire_heatscale.m_pParent->m_Value.m_fValue * simTime) * outputHeat) / (float)fireCount;
        outputHeat = v35;
        do
        {
          v36 = pFires[v34];
          v37 = v35;
          if ( v36->m_bEnabled )
          {
            if ( v36->m_flHeatLevel > 0.0 )
              v37 = fire_incomingheatscale.m_pParent->m_Value.m_fValue * v35;
            v27 = v36->m_flHeatLevel > 0.0;
            v36->m_lastDamage = gpGlobals->curtime + 0.5;
            v38 = !v27;
            m_flHeatAbsorb = v36->m_flHeatAbsorb;
            if ( m_flHeatAbsorb > 0.0 )
            {
              v40 = fire_absorbrate.m_pParent->m_Value.m_fValue * v37;
              if ( v40 <= m_flHeatAbsorb )
              {
                v36->m_flHeatAbsorb = m_flHeatAbsorb - v40;
                v37 = 0.0;
              }
              else
              {
                v37 = v37 - (float)(m_flHeatAbsorb / fire_absorbrate.m_pParent->m_Value.m_fValue);
                v36->m_flHeatAbsorb = 0.0;
              }
            }
            v41 = v36->m_flHeatLevel + v37;
            v36->m_flHeatLevel = v41;
            if ( v38 != 0 && v41 > 0.0 )
            {
              v42 = v36->m_hEffect.m_Index;
              if ( v42 == -1
                || g_pEntityList->m_EntPtrArray[(unsigned __int16)v42].m_SerialNumber != HIWORD(v42)
                || g_pEntityList->m_EntPtrArray[(unsigned __int16)v42].m_pEntity == nullptr )
              {
                CFire::StartFire(this: v36);
                v35 = outputHeat;
              }
            }
            v43 = v36->m_flMaxHeat;
            if ( v36->m_flHeatLevel > v43 )
              v36->m_flHeatLevel = v43;
          }
          ++v34;
        }
        while ( v34 < fireCount );
      }
    }
  }
  else
  {
    CFire::GoOutInSeconds(this, seconds: 1.0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017CF00
// Name: public: virtual int CFire::OnTakeDamage(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall CFire::OnTakeDamage(vgui::Panel *this, wchar_t key)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x104033B0
// Name: CFire_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CFire_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CFire>(__formal: nullptr);
  CFire_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104033E0
// Name: CEnvFireSource_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CEnvFireSource_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CEnvFireSource>(__formal: nullptr);
  CEnvFireSource_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10403410
// Name: CEnvFireSensor_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CEnvFireSensor_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CEnvFireSensor>(__formal: nullptr);
  CEnvFireSensor_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10125760
// Name: class CEnvFireSensor __near * _CreateEntityTemplate<class CEnvFireSensor>(class CEnvFireSensor __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CEnvFireSensor *__cdecl _CreateEntityTemplate<CEnvFireSensor>(CEnvFireSensor *newEnt, const char *className)
{
  CBaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x398u);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    *v3 = &CEnvFireSensor::`vftable';
    v3[218] = 0;
    v3[221] = -1;
    v3[222] = 0;
    v3[224] = 0;
    v3[227] = -1;
    v3[228] = 0;
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CEnvFireSensor *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10126DF0
// Name: struct datamap_t __near * DataMapInit<class CEnvFireSource>(class CEnvFireSource __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CEnvFireSource>()
{
  if ( (_S3_57 & 1) == 0 )
  {
    _S3_57 |= 1u;
    nameHolder_196.m_pszBase = "CEnvFireSource";
    nameHolder_196.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_196.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_196.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_196.m_Names.m_Size = 0;
    nameHolder_196.m_Names.m_pElements = nullptr;
    nameHolder_196.m_nLenBase = 14;
    atexit(func: DataMapInit_CEnvFireSource__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CEnvFireSource::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CEnvFireSource::m_DataMap.dataNumFields = 5;
  CEnvFireSource::m_DataMap.dataDesc = &dataDesc_186[1];
  return &CEnvFireSource::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10126E70
// Name: struct datamap_t __near * DataMapInit<class CEnvFireSensor>(class CEnvFireSensor __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CEnvFireSensor>()
{
  if ( (_S4_30 & 1) == 0 )
  {
    _S4_30 |= 1u;
    nameHolder_197.m_pszBase = "CEnvFireSensor";
    nameHolder_197.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_197.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_197.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_197.m_Names.m_Size = 0;
    nameHolder_197.m_Names.m_pElements = nullptr;
    nameHolder_197.m_nLenBase = 14;
    atexit(func: DataMapInit_CEnvFireSensor__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CEnvFireSensor::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S4_30 & 2) == 0 )
  {
    _S4_30 |= 2u;
    *(_QWORD *)&dataDesc_187[9].inputFunc = 0;
    *(_QWORD *)&dataDesc_187[9].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_187[9].override_count = 0;
    *(_QWORD *)dataDesc_187[9].flatOffset = 0;
    dataDesc_187[9].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_187[9].flatGroup = 0;
    dataDesc_187[10].fieldType = FIELD_CUSTOM;
    dataDesc_187[10].fieldName = "m_OnHeatLevelEnd";
    dataDesc_187[10].fieldOffset = 896;
    *(_DWORD *)&dataDesc_187[10].fieldSize = 1441793;
    dataDesc_187[10].externalName = "OnHeatLevelEnd";
    dataDesc_187[10].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_187[10].inputFunc = 0;
    *(_QWORD *)&dataDesc_187[10].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_187[10].override_count = 0;
    *(_QWORD *)dataDesc_187[10].flatOffset = 0;
    *(_DWORD *)&dataDesc_187[10].flatGroup = 0;
  }
  CEnvFireSensor::m_DataMap.dataNumFields = 10;
  CEnvFireSensor::m_DataMap.dataDesc = &dataDesc_187[1];
  return &CEnvFireSensor::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10126FB0
// Name: struct datamap_t __near * DataMapInit<class CFire>(class CFire __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CFire>()
{
  if ( (_S2_103 & 1) == 0 )
  {
    _S2_103 |= 1u;
    nameHolder_198.m_pszBase = "CFire";
    nameHolder_198.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_198.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_198.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_198.m_Names.m_Size = 0;
    nameHolder_198.m_Names.m_pElements = nullptr;
    nameHolder_198.m_nLenBase = 5;
    atexit(func: DataMapInit_CFire__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CFire::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S2_103 & 2) == 0 )
  {
    _S2_103 |= 2u;
    dataDesc_188[16].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_198,
                                   pszIdentifier: "BurnThink");
    dataDesc_188[16].flags = 32;
    dataDesc_188[16].fieldOffset = 0;
    dataDesc_188[16].fieldSize = 1;
    dataDesc_188[16].externalName = nullptr;
    dataDesc_188[16].pSaveRestoreOps = nullptr;
    dataDesc_188[16].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CFire::BurnThink;
    *(_QWORD *)&dataDesc_188[16].td = 0;
    *(_QWORD *)&dataDesc_188[16].override_field = 0;
    *(_QWORD *)&dataDesc_188[16].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_188[16].flatOffset[1] = 0;
    dataDesc_188[17].fieldType = FIELD_VOID;
    dataDesc_188[17].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_198,
                                   pszIdentifier: "GoOutThink");
    dataDesc_188[17].fieldSize = 1;
    *(_QWORD *)&dataDesc_188[17].td = 0;
    *(_QWORD *)&dataDesc_188[17].override_field = 0;
    *(_QWORD *)&dataDesc_188[17].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_188[17].flatOffset[1] = 0;
    dataDesc_188[17].flags = 32;
    dataDesc_188[18].fieldSize = 1;
    *(_QWORD *)&dataDesc_188[18].td = 0;
    *(_QWORD *)&dataDesc_188[18].override_field = 0;
    *(_QWORD *)&dataDesc_188[18].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_188[18].flatOffset[1] = 0;
    dataDesc_188[18].flags = 8;
    dataDesc_188[19].fieldSize = 1;
    *(_QWORD *)&dataDesc_188[19].td = 0;
    *(_QWORD *)&dataDesc_188[19].override_field = 0;
    *(_QWORD *)&dataDesc_188[19].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_188[19].flatOffset[1] = 0;
    dataDesc_188[17].fieldOffset = 0;
    dataDesc_188[17].externalName = nullptr;
    dataDesc_188[17].pSaveRestoreOps = nullptr;
    dataDesc_188[17].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CFire::GoOutThink;
    dataDesc_188[18].fieldType = FIELD_VOID;
    dataDesc_188[18].fieldName = "InputStartFire";
    dataDesc_188[18].fieldOffset = 0;
    dataDesc_188[18].externalName = "StartFire";
    dataDesc_188[18].pSaveRestoreOps = nullptr;
    dataDesc_188[18].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CFire::InputStartFire;
    dataDesc_188[19].fieldType = FIELD_FLOAT;
    dataDesc_188[19].fieldName = "InputExtinguish";
    dataDesc_188[19].fieldOffset = 0;
    dataDesc_188[19].flags = 8;
    dataDesc_188[19].externalName = "Extinguish";
    dataDesc_188[19].pSaveRestoreOps = nullptr;
    dataDesc_188[19].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CFire::InputExtinguish;
    dataDesc_188[20].fieldType = FIELD_FLOAT;
    dataDesc_188[20].fieldName = "InputExtinguishTemporary";
    dataDesc_188[20].fieldOffset = 0;
    dataDesc_188[20].fieldSize = 1;
    dataDesc_188[20].flags = 8;
    dataDesc_188[20].externalName = "ExtinguishTemporary";
    dataDesc_188[20].pSaveRestoreOps = nullptr;
    dataDesc_188[20].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CFire::InputExtinguishTemporary;
    *(_QWORD *)&dataDesc_188[20].td = 0;
    *(_QWORD *)&dataDesc_188[20].override_field = 0;
    *(_QWORD *)&dataDesc_188[20].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_188[20].flatOffset[1] = 0;
    *(_QWORD *)&dataDesc_188[21].td = 0;
    *(_QWORD *)&dataDesc_188[21].override_field = 0;
    *(_QWORD *)&dataDesc_188[21].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_188[21].flatOffset[1] = 0;
    dataDesc_188[21].fieldSize = 1;
    dataDesc_188[22].fieldSize = 1;
    *(_QWORD *)&dataDesc_188[22].td = 0;
    *(_QWORD *)&dataDesc_188[22].override_field = 0;
    *(_QWORD *)&dataDesc_188[22].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_188[22].flatOffset[1] = 0;
    dataDesc_188[21].flags = 8;
    dataDesc_188[22].flags = 8;
    dataDesc_188[23].flags = 22;
    *(_QWORD *)&dataDesc_188[23].inputFunc = 0;
    *(_QWORD *)&dataDesc_188[23].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_188[23].override_count = 0;
    *(_QWORD *)dataDesc_188[23].flatOffset = 0;
    dataDesc_188[21].fieldType = FIELD_VOID;
    dataDesc_188[21].fieldName = "InputEnable";
    dataDesc_188[21].fieldOffset = 0;
    dataDesc_188[21].externalName = "Enable";
    dataDesc_188[21].pSaveRestoreOps = nullptr;
    dataDesc_188[21].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CFuncLadder::InputDisable;
    dataDesc_188[22].fieldType = FIELD_VOID;
    dataDesc_188[22].fieldName = "InputDisable";
    dataDesc_188[22].fieldOffset = 0;
    dataDesc_188[22].externalName = "Disable";
    dataDesc_188[22].pSaveRestoreOps = nullptr;
    dataDesc_188[22].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CFire::InputDisable;
    dataDesc_188[23].fieldType = FIELD_CUSTOM;
    dataDesc_188[23].fieldName = "m_OnIgnited";
    dataDesc_188[23].fieldOffset = 912;
    dataDesc_188[23].fieldSize = 1;
    dataDesc_188[23].externalName = "OnIgnited";
    dataDesc_188[23].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_188[23].flatGroup = 0;
    dataDesc_188[24].fieldType = FIELD_CUSTOM;
    dataDesc_188[24].fieldName = "m_OnExtinguished";
    dataDesc_188[24].fieldOffset = 936;
    *(_DWORD *)&dataDesc_188[24].fieldSize = 1441793;
    dataDesc_188[24].externalName = "OnExtinguished";
    dataDesc_188[24].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_188[24].inputFunc = 0;
    *(_QWORD *)&dataDesc_188[24].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_188[24].override_count = 0;
    *(_QWORD *)dataDesc_188[24].flatOffset = 0;
    *(_DWORD *)&dataDesc_188[24].flatGroup = 0;
  }
  CFire::m_DataMap.dataNumFields = 24;
  CFire::m_DataMap.dataDesc = &dataDesc_188[1];
  return &CFire::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x104033C0
// Name: _dynamic_initializer_for__env_fire__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_fire__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CFire> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_fire,
           a3: "env_fire");
}

//------------------------------------------------------------------------------
// Address: 0x104033F0
// Name: _dynamic_initializer_for__env_firesource__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_firesource__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CEnvFireSource> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_firesource,
           a3: "env_firesource");
}

//------------------------------------------------------------------------------
// Address: 0x10403420
// Name: _dynamic_initializer_for__env_firesensor__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_firesensor__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CEnvFireSensor> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_firesensor,
           a3: "env_firesensor");
}
