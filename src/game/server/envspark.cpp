// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/envspark.cpp
// Functions: 13
// ============================================================

#include "game\server\envspark.h"

//------------------------------------------------------------------------------
// Address: 0x10120F00
// Name: void DoSpark(class CBaseEntity __near *,class Vector const __near &,int,int,bool,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DoSpark(
        CBaseEntity *ent,
        const Vector *location,
        int nMagnitude,
        int nTrailLength,
        bool bPlaySound,
        const Vector *vecDir)
{
  g_pEffects->Sparks(this: g_pEffects, a2: location, a3: nMagnitude, a4: nTrailLength, a5: vecDir);
}

//------------------------------------------------------------------------------
// Address: 0x10120F30
// Name: public: virtual struct datamap_t __near * CEnvSpark::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CEnvSpark::GetDataDescMap(CEnvSpark *this)
{
  return &CEnvSpark::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10120F40
// Name: public: virtual void CEnvSpark::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CEnvSpark::Precache(CEnvSpark *this@<ecx>, bool (__cdecl *a2)(const char *)@<edi>)
{
  bool oldLock; // [esp+4h] [ebp-4h]

  oldLock = engine->LockNetworkStringTables(this: engine, a2: false);
  this->m_nGlowSpriteIndex = CBaseEntity::PrecacheModel(a1: a2, name: "sprites/glow01.vmt", bPreload: true);
  engine->LockNetworkStringTables(this: engine, a2: oldLock);
  if ( CBaseEntity::IsPrecacheAllowed() )
  {
    CBaseEntity::PrecacheScriptSound(soundname: "DoSpark");
    PrecacheParticleSystem(pParticleSystemName: "env_sparks_omni");
    PrecacheParticleSystem(pParticleSystemName: "env_sparks_directional");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10120FE0
// Name: public: void CEnvSpark::SparkThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvSpark::SparkThink(CEnvSpark *this)
{
  int m_Value; // edx
  CEnvSpark_vtbl *v3; // eax
  float v4; // xmm0_4
  const Vector *(__thiscall *WorldSpaceCenter)(struct CEnvSpark *); // edx
  Vector *v6; // eax
  int v7; // edx
  CEnvSpark_vtbl *v8; // eax
  float v9; // xmm0_4
  const Vector *(__thiscall *v10)(struct CEnvSpark *); // edx
  Vector *v11; // eax
  bool v12; // zf
  int m_nTrailLength; // edi
  int m_nMagnitude; // ebx
  const Vector *v15; // eax
  float thinkTime; // [esp+28h] [ebp-40h]
  CPVSFilter filter; // [esp+3Ch] [ebp-2Ch] BYREF
  Vector vecDir; // [esp+5Ch] [ebp-Ch] BYREF
  int savedregs; // [esp+68h] [ebp+0h] BYREF

  thinkTime = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, _DWORD))random->RandomFloat)(
                a1: random,
                a2: 0,
                a3: LODWORD(this->m_flDelay))
            + gpGlobals->curtime
            + 0.1;
  CBaseEntity::SetNextThink(this, thinkTime, szContext: nullptr);
  COutputEvent::FireOutput(this: &this->m_OnSpark, pActivator: this, pCaller: this, fDelay: 0.0);
  if ( (this->m_spawnflags.m_Value & 0x100) == 0 )
    CBaseEntity::EmitSound(this, soundname: "DoSpark", soundtime: 0.0, duration: nullptr);
  if ( fx_new_sparks.m_pParent != nullptr && fx_new_sparks.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( (this->m_spawnflags.m_Value & 0x200) != 0 )
    {
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      m_Value = this->m_spawnflags.m_Value;
      v3 = this->__vftable;
      vecDir.x = (float)this->m_nMagnitude;
      vecDir.y = (float)this->m_nTrailLength;
      v4 = (float)(m_Value & 0x80);
      WorldSpaceCenter = v3->WorldSpaceCenter;
      vecDir.z = v4;
      v6 = WorldSpaceCenter(this);
      DispatchParticleEffect(
        pszParticleName: "env_sparks_directional",
        vecOrigin: *v6,
        vecStart: vecDir,
        vecAngles: this->m_angAbsRotation,
        pEntity: nullptr,
        nSplitScreenPlayerSlot: -1,
        filter: nullptr);
    }
    else
    {
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      v7 = this->m_spawnflags.m_Value;
      v8 = this->__vftable;
      vecDir.x = (float)this->m_nMagnitude;
      vecDir.y = (float)this->m_nTrailLength;
      v9 = (float)(v7 & 0x80);
      v10 = v8->WorldSpaceCenter;
      vecDir.z = v9;
      v11 = v10(this);
      DispatchParticleEffect(
        pszParticleName: "env_sparks_omni",
        vecOrigin: *v11,
        vecStart: vecDir,
        vecAngles: this->m_angAbsRotation,
        pEntity: nullptr,
        nSplitScreenPlayerSlot: -1,
        filter: nullptr);
    }
  }
  else
  {
    v12 = (this->m_spawnflags.m_Value & 0x200) == 0;
    vecDir = vec3_origin;
    if ( !v12 )
    {
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      AngleVectors(angles: &this->m_angAbsRotation, forward: &vecDir);
    }
    m_nTrailLength = this->m_nTrailLength;
    m_nMagnitude = this->m_nMagnitude;
    v15 = this->WorldSpaceCenter(this);
    g_pEffects->Sparks(this: g_pEffects, a2: v15, a3: m_nMagnitude, a4: m_nTrailLength, a5: &vecDir);
    if ( SLOBYTE(this->m_spawnflags.m_Value) < 0 )
    {
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      CRecipientFilter::CRecipientFilter(this: &filter);
      filter.__vftable = (CPVSFilter_vtbl *)&CPVSFilter::`vftable';
      CRecipientFilter::AddRecipientsByPVS(this: &filter, origin: &this->m_vecAbsOrigin);
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      ((void (__stdcall *)(CPVSFilter *, _DWORD, Vector *, int, int, int, int))te->GlowSprite)(
        a1: &filter,
        a2: 0,
        a3: &this->m_vecAbsOrigin,
        a4: this->m_nGlowSpriteIndex,
        a5: 1045220557,
        a6: 1069547520,
        a7: 25);
      CRecipientFilter::~CRecipientFilter(this: &filter);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10121310
// Name: public: void CEnvSpark::InputStartSpark(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvSpark::InputStartSpark(CEnvSpark *this, inputdata_t *inputdata)
{
  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CEnvSpark::SparkThink,
    thinkTime: 0.0,
    szContext: nullptr);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10121350
// Name: public: void CEnvSpark::InputSparkOnce(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvSpark::InputSparkOnce(CEnvSpark *this, inputdata_t *inputdata)
{
  CEnvSpark::SparkThink(this);
  CBaseEntity::SetNextThink(this, thinkTime: -1.0, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10121380
// Name: public: void CEnvSpark::InputToggleSpark(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvSpark::InputToggleSpark(CEnvSpark *this, inputdata_t *inputdata)
{
  if ( CBaseEntity::GetNextThink(this, szContext: nullptr) == -1.0 )
  {
    CBaseEntity::ThinkSet(
      this,
      func: (void (__thiscall *)(CBaseEntity *))CEnvSpark::SparkThink,
      thinkTime: 0.0,
      szContext: nullptr);
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
  }
  else
  {
    CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10121410
// Name: public: virtual void CEnvSpark::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvSpark::Spawn(CEnvSpark *this)
{
  bool v2; // zf
  float thinkTime; // [esp+8h] [ebp-Ch]

  CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
  v2 = (this->m_spawnflags.m_Value & 0x40) == 0;
  this->m_pfnUse = nullptr;
  if ( !v2 )
    CBaseEntity::ThinkSet(
      this,
      func: (void (__thiscall *)(CBaseEntity *))CEnvSpark::SparkThink,
      thinkTime: 0.0,
      szContext: nullptr);
  thinkTime = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, int))random->RandomFloat)(
                a1: random,
                a2: 0,
                a3: 1069547520)
            + gpGlobals->curtime
            + 0.1;
  CBaseEntity::SetNextThink(this, thinkTime, szContext: nullptr);
  if ( this->m_flDelay < 0.0 )
    this->m_flDelay = 0.0;
  this->Precache(this);
}

//------------------------------------------------------------------------------
// Address: 0x10402F40
// Name: CEnvSpark_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CEnvSpark_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CEnvSpark>();
  CEnvSpark_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101214B0
// Name: class CEnvSpark __near * _CreateEntityTemplate<class CEnvSpark>(class CEnvSpark __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CEnvSpark *__cdecl _CreateEntityTemplate<CEnvSpark>(CEnvSpark *newEnt, const char *className)
{
  CBaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x37Cu);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    *v3 = &CEnvSpark::`vftable';
    v3[217] = 0;
    v3[220] = -1;
    v3[221] = 0;
    v3[215] = 1;
    v3[216] = 1;
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CEnvSpark *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10402F50
// Name: _dynamic_initializer_for__env_spark__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_spark__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CEnvSpark> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_spark,
           a3: "env_spark");
}

//------------------------------------------------------------------------------
// Address: 0x10402F70
// Name: _dynamic_initializer_for__g_EventList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_EventList__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_EventList__);
}

//------------------------------------------------------------------------------
// Address: 0x10402F80
// Name: _dynamic_initializer_for__g_EventStrings__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_EventStrings__()
{
  CStringRegistry::CStringRegistry(this: &g_EventStrings);
  return atexit(func: dynamic_atexit_destructor_for__g_EventStrings__);
}
