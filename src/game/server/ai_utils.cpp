// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/ai_utils.cpp
// Functions: 22
// ============================================================

#include "game\server\ai_utils.h"

//------------------------------------------------------------------------------
// Address: 0x10090270
// Name: public: CAI_ShotRegulator::CAI_ShotRegulator(void)
// Source: json
//------------------------------------------------------------------------------
CAI_ShotRegulator *__thiscall CAI_ShotRegulator::CAI_ShotRegulator(CAI_ShotRegulator *this)
{
  this->m_nBurstShotsRemaining = 1;
  this->m_flMinRestInterval = 0.0;
  this->m_flMinBurstInterval = 0.0;
  this->m_flMaxBurstInterval = 0.0;
  *(_DWORD *)&this->m_nMinBurstShots = 65537;
  this->m_flNextShotTime = -1.0;
  this->m_bInRestInterval = false;
  this->m_bDisabled = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100902B0
// Name: public: void CAI_ShotRegulator::SetBurstShotCountRange(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_ShotRegulator::SetBurstShotCountRange(
        CAI_ShotRegulator *this,
        unsigned __int16 minShotsPerBurst,
        unsigned __int16 maxShotsPerBurst)
{
  this->m_nMinBurstShots = minShotsPerBurst;
  this->m_nMaxBurstShots = maxShotsPerBurst;
}

//------------------------------------------------------------------------------
// Address: 0x100902D0
// Name: public: void CAI_ShotRegulator::SetRestInterval(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_ShotRegulator::SetRestInterval(
        CAI_ShotRegulator *this,
        float flMinRestInterval,
        float flMaxRestInterval)
{
  this->m_flMinRestInterval = flMinRestInterval;
  this->m_flMaxRestInterval = flMaxRestInterval;
}

//------------------------------------------------------------------------------
// Address: 0x100902F0
// Name: public: void CAI_ShotRegulator::SetBurstInterval(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_ShotRegulator::SetBurstInterval(
        CAI_ShotRegulator *this,
        float flMinBurstInterval,
        float flMaxBurstInterval)
{
  this->m_flMinBurstInterval = flMinBurstInterval;
  this->m_flMaxBurstInterval = flMaxBurstInterval;
}

//------------------------------------------------------------------------------
// Address: 0x10090310
// Name: public: void CAI_ShotRegulator::Reset(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_ShotRegulator::Reset(CAI_ShotRegulator *this, bool bStartShooting)
{
  int m_nMaxBurstShots; // edx
  double curtime; // st7

  m_nMaxBurstShots = this->m_nMaxBurstShots;
  this->m_bDisabled = false;
  this->m_nBurstShotsRemaining = ((int (__stdcall *)(_DWORD, int))random->RandomInt)(
                                   a1: this->m_nMinBurstShots,
                                   a2: m_nMaxBurstShots);
  if ( bStartShooting )
  {
    curtime = gpGlobals->curtime;
    this->m_bInRestInterval = false;
  }
  else
  {
    curtime = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, _DWORD))random->RandomFloat)(
                a1: random,
                a2: LODWORD(this->m_flMinRestInterval),
                a3: LODWORD(this->m_flMaxRestInterval))
            + gpGlobals->curtime;
    this->m_bInRestInterval = true;
  }
  this->m_flNextShotTime = curtime;
}

//------------------------------------------------------------------------------
// Address: 0x10090390
// Name: public: bool CAI_ShotRegulator::ShouldShoot(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CAI_ShotRegulator::ShouldShoot(CAI_ShotRegulator *this)
{
  return !this->m_bDisabled && gpGlobals->curtime >= this->m_flNextShotTime;
}

//------------------------------------------------------------------------------
// Address: 0x100903B0
// Name: public: bool CAI_ShotRegulator::IsInRestInterval(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CAI_ShotRegulator::IsInRestInterval(CAI_ShotRegulator *this)
{
  return this->m_bInRestInterval && (this->m_bDisabled || gpGlobals->curtime < this->m_flNextShotTime);
}

//------------------------------------------------------------------------------
// Address: 0x100903E0
// Name: public: float CAI_ShotRegulator::NextShotTime(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAI_ShotRegulator::NextShotTime(CAI_ShotRegulator *this)
{
  return this->m_flNextShotTime;
}

//------------------------------------------------------------------------------
// Address: 0x100903F0
// Name: public: void CAI_ShotRegulator::FireNoEarlierThan(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_ShotRegulator::FireNoEarlierThan(CAI_ShotRegulator *this, float flTime)
{
  if ( flTime > this->m_flNextShotTime )
    this->m_flNextShotTime = flTime;
}

//------------------------------------------------------------------------------
// Address: 0x10090410
// Name: public: void CAI_ShotRegulator::OnFiredWeapon(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_ShotRegulator::OnFiredWeapon(CAI_ShotRegulator *this)
{
  int m_nMaxBurstShots; // eax
  unsigned __int16 v4; // ax
  float m_flMaxRestInterval; // xmm0_4
  double v6; // st7
  float m_flMaxBurstInterval; // xmm0_4
  float curtime; // xmm0_4
  float v9; // [esp+14h] [ebp-4h]

  if ( this->m_nBurstShotsRemaining-- == 1 )
  {
    m_nMaxBurstShots = this->m_nMaxBurstShots;
    this->m_bDisabled = false;
    v4 = ((int (__stdcall *)(_DWORD, int))random->RandomInt)(a1: this->m_nMinBurstShots, a2: m_nMaxBurstShots);
    m_flMaxRestInterval = this->m_flMaxRestInterval;
    this->m_nBurstShotsRemaining = v4;
    v6 = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, _DWORD))random->RandomFloat)(
           a1: random,
           a2: LODWORD(this->m_flMinRestInterval),
           a3: LODWORD(m_flMaxRestInterval))
       + gpGlobals->curtime;
    this->m_bInRestInterval = true;
    this->m_flNextShotTime = v6;
  }
  else
  {
    m_flMaxBurstInterval = this->m_flMaxBurstInterval;
    this->m_bInRestInterval = false;
    v9 = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, _DWORD))random->RandomFloat)(
           a1: random,
           a2: LODWORD(this->m_flMinBurstInterval),
           a3: LODWORD(m_flMaxBurstInterval))
       + this->m_flNextShotTime;
    this->m_flNextShotTime = v9;
    curtime = gpGlobals->curtime;
    if ( curtime > v9 )
      this->m_flNextShotTime = curtime;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100904D0
// Name: public: CTraceFilterNav::CTraceFilterNav(class CAI_BaseNPC __near *,bool,class IServerEntity const __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
CTraceFilterNav *__thiscall CTraceFilterNav::CTraceFilterNav(
        CTraceFilterNav *this,
        CAI_BaseNPC *pProber,
        bool bIgnoreTransientEntities,
        const IServerEntity *passedict,
        int collisionGroup,
        bool bAllowPlayerAvoid)
{
  CTraceFilterSimple::CTraceFilterSimple(this, passedict, collisionGroup, pExtraShouldHitFunc: nullptr);
  this->m_pProber = pProber;
  this->__vftable = (CTraceFilterNav_vtbl *)&CTraceFilterNav::`vftable';
  this->m_bIgnoreTransientEntities = bIgnoreTransientEntities;
  this->m_bAllowPlayerAvoid = bAllowPlayerAvoid;
  this->m_bCheckCollisionTable = g_EntityCollisionHash->IsObjectInHash(this: g_EntityCollisionHash, a2: pProber);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10090520
// Name: public: virtual void CTraceFilterSimple::SetCollisionGroup(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTraceFilterSimple::SetCollisionGroup(CTraceFilterSimple *this, int iCollisionGroup)
{
  this->m_collisionGroup = iCollisionGroup;
}

//------------------------------------------------------------------------------
// Address: 0x10090530
// Name: public: virtual bool CTraceFilterNav::ShouldHitEntity(class IHandleEntity __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTraceFilterNav::ShouldHitEntity(CTraceFilterNav *this, CBaseEntity *pHandleEntity, int contentsMask)
{
  CAI_BaseNPC *m_pProber; // eax

  m_pProber = this->m_pProber;
  return m_pProber != pHandleEntity
      && !CAI_MoveProbe::ShouldBrushBeIgnored(this: m_pProber->m_pMoveProbe, pEntity: pHandleEntity)
      && (!this->m_bIgnoreTransientEntities
       || !pHandleEntity->IsPlayer(this: pHandleEntity) && !pHandleEntity->IsNPC(this: pHandleEntity))
      && (!this->m_bAllowPlayerAvoid
       || !this->m_pProber->ShouldPlayerAvoid(this: this->m_pProber)
       || !pHandleEntity->IsPlayer(this: pHandleEntity))
      && pHandleEntity->m_flNavIgnoreUntilTime < gpGlobals->curtime
      && (!this->m_bCheckCollisionTable
       || !g_EntityCollisionHash->IsObjectPairInHash(
             this: g_EntityCollisionHash,
             a2: this->m_pProber,
             a3: pHandleEntity))
      && this->m_pProber->ShouldProbeCollideAgainstEntity(this: this->m_pProber, a2: pHandleEntity)
      && CTraceFilterSimple::ShouldHitEntity(this, pHandleEntity, contentsMask);
}

//------------------------------------------------------------------------------
// Address: 0x103FEF30
// Name: CAI_MoveMonitor_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CAI_MoveMonitor_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CAI_MoveMonitor>(__formal: nullptr);
  CAI_MoveMonitor_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FEF40
// Name: CAI_ShotRegulator_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CAI_ShotRegulator_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CAI_ShotRegulator>(__formal: nullptr);
  CAI_ShotRegulator_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FEF50
// Name: CAI_AccelDecay_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CAI_AccelDecay_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CAI_AccelDecay>(__formal: nullptr);
  CAI_AccelDecay_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FEF90
// Name: AI_FreePassParams_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *AI_FreePassParams_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<AI_FreePassParams_t>();
  AI_FreePassParams_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FEFA0
// Name: CAI_FreePass_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CAI_FreePass_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CAI_FreePass>();
  CAI_FreePass_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10090610
// Name: struct datamap_t __near * DataMapInit<class CAI_MoveMonitor>(class CAI_MoveMonitor __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CAI_MoveMonitor>()
{
  if ( (_S2_39 & 1) == 0 )
  {
    _S2_39 |= 1u;
    nameHolder_74.m_pszBase = "CAI_MoveMonitor";
    nameHolder_74.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_74.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_74.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_74.m_Names.m_Size = 0;
    nameHolder_74.m_Names.m_pElements = nullptr;
    nameHolder_74.m_nLenBase = 15;
    atexit(func: DataMapInit_CAI_MoveMonitor__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CAI_MoveMonitor::m_DataMap.baseMap = nullptr;
  CAI_MoveMonitor::m_DataMap.dataNumFields = 2;
  CAI_MoveMonitor::m_DataMap.dataDesc = &dataDesc_71[1];
  return &CAI_MoveMonitor::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10090690
// Name: struct datamap_t __near * DataMapInit<class CAI_ShotRegulator>(class CAI_ShotRegulator __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CAI_ShotRegulator>()
{
  if ( (_S3_18 & 1) == 0 )
  {
    _S3_18 |= 1u;
    nameHolder_75.m_pszBase = "CAI_ShotRegulator";
    nameHolder_75.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_75.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_75.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_75.m_Names.m_Size = 0;
    nameHolder_75.m_Names.m_pElements = nullptr;
    nameHolder_75.m_nLenBase = 17;
    atexit(func: DataMapInit_CAI_ShotRegulator__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CAI_ShotRegulator::m_DataMap.baseMap = nullptr;
  CAI_ShotRegulator::m_DataMap.dataNumFields = 10;
  CAI_ShotRegulator::m_DataMap.dataDesc = &dataDesc_72[1];
  return &CAI_ShotRegulator::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10090710
// Name: struct datamap_t __near * DataMapInit<class CAI_AccelDecay>(class CAI_AccelDecay __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CAI_AccelDecay>()
{
  if ( (_S4_8 & 1) == 0 )
  {
    _S4_8 |= 1u;
    nameHolder_76.m_pszBase = "CAI_AccelDecay";
    nameHolder_76.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_76.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_76.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_76.m_Names.m_Size = 0;
    nameHolder_76.m_Names.m_pElements = nullptr;
    nameHolder_76.m_nLenBase = 14;
    atexit(func: DataMapInit_CAI_AccelDecay__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CAI_AccelDecay::m_DataMap.baseMap = nullptr;
  CAI_AccelDecay::m_DataMap.dataNumFields = 6;
  CAI_AccelDecay::m_DataMap.dataDesc = &dataDesc_73[1];
  return &CAI_AccelDecay::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x103FEFB0
// Name: _dynamic_initializer_for__AI_Waypoint_t::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__AI_Waypoint_t::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &AI_Waypoint_t::s_Allocator,
    blockSize: 48,
    numElements: 512,
    growMode: 1,
    pszAllocOwner: "AI_Waypoint_t pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__AI_Waypoint_t::s_Allocator__);
}
