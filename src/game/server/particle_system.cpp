// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/particle_system.cpp
// Functions: 43
// ============================================================

#include "game\server\particle_system.h"

//------------------------------------------------------------------------------
// Address: 0x1017C370
// Name: public: virtual class ServerClass __near * CParticleSystem::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CParticleSystem::GetServerClass(CParticleSystem *this)
{
  return &g_CParticleSystem_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x1017C380
// Name: public: virtual struct datamap_t __near * CParticleSystem::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CParticleSystem::GetDataDescMap(CParticleSystem *this)
{
  return &CParticleSystem::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1017C390
// Name: public: virtual int CParticleSystem::ObjectCaps(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CParticleSystem::ObjectCaps(CParticleSystem *this)
{
  unsigned int v1; // esi

  v1 = 0;
  if ( this->m_bNoSave )
    v1 = 0x80000000;
  return v1 | CBaseEntity::ObjectCaps(this);
}

//------------------------------------------------------------------------------
// Address: 0x1017C3B0
// Name: public: virtual bool CParticleSystem::GetKeyValue(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CParticleSystem::GetKeyValue(CParticleSystem *this, const char *szKeyName, char *szValue, int iMaxLen)
{
  if ( szKeyName != "snapshot_file" && _V_stricmp(s1: szKeyName, s2: "snapshot_file") != 0 )
    return CBaseEntity::GetKeyValue(this, szKeyName, szValue, iMaxLen);
  V_snprintf(pDest: szValue, maxLen: iMaxLen, pFormat: "%s", this->m_szSnapshotFileName.m_Value);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1017C780
// Name: public: CParticleSystem::CParticleSystem(void)
// Source: json
//------------------------------------------------------------------------------
CParticleSystem *__thiscall CParticleSystem::CParticleSystem(CParticleSystem *this)
{
  int i; // esi
  edict_t *m_pPev; // ecx

  CBaseEntity::CBaseEntity(this, bServerOnly: false);
  this->__vftable = (CParticleSystem_vtbl *)&CParticleSystem::`vftable';
  this->m_bNoSave = false;
  memset(&this->m_hControlPointEnts, 0xFFu, sizeof(this->m_hControlPointEnts));
  for ( i = 0; i != 4; ++i )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: i + 1184);
    }
    this->m_iServerControlPointAssignments.m_Value[i] = -1;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1017C7F0
// Name: public: virtual void CParticleSystem::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSystem::Precache(CParticleSystem *this)
{
  const char *pszValue; // eax
  const char *v2; // esi
  const char *v3; // eax

  pszValue = this->m_iszEffectName.pszValue;
  if ( pszValue != nullptr )
  {
    v2 = this->m_iszEffectName.pszValue;
    if ( *pszValue != 0 )
      goto LABEL_6;
  }
  else
  {
    v2 = locale;
  }
  v3 = this->m_iName.m_Value.pszValue;
  if ( v3 == nullptr )
    v3 = locale;
  _Warning(a1: "info_particle_system (%s) has no particle system name specified!\n", v3);
LABEL_6:
  PrecacheParticleSystem(pParticleSystemName: v2);
}

//------------------------------------------------------------------------------
// Address: 0x1017C840
// Name: protected: void CParticleSystem::ReadControlPointEnts(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSystem::ReadControlPointEnts(CParticleSystem *this)
{
  CParticleSystem *v1; // ebx
  string_t *m_iszControlPointNames; // edi
  CBasePlayer *EntityGeneric; // eax
  const char *pszValue; // ecx
  const char *v5; // eax
  unsigned int m_Index; // esi
  CParticleSystem::NetworkVar_m_hControlPointEnts *v7; // edi
  CBaseEdict *v8; // ecx
  int v10; // [esp+10h] [ebp-Ch]
  string_t *v11; // [esp+14h] [ebp-8h]
  int i; // [esp+18h] [ebp-4h]

  v1 = this;
  m_iszControlPointNames = this->m_iszControlPointNames;
  i = 0;
  v11 = this->m_iszControlPointNames;
  v10 = -1188 - (_DWORD)this;
  do
  {
    if ( m_iszControlPointNames->pszValue != nullptr )
    {
      EntityGeneric = CGlobalEntityList::FindEntityGeneric(
                        this: &gEntList,
                        pStartEntity: nullptr,
                        szName: m_iszControlPointNames->pszValue,
                        pSearchingEntity: v1,
                        pActivator: nullptr,
                        pCaller: nullptr);
      if ( EntityGeneric != nullptr )
      {
        m_Index = EntityGeneric->GetRefEHandle(this: EntityGeneric)->m_Index;
        v7 = (CParticleSystem::NetworkVar_m_hControlPointEnts *)((char *)&v1->m_hControlPointEnts
                                                               + (_DWORD)m_iszControlPointNames
                                                               + v10);
        if ( v7->m_Value[0].m_Index != m_Index )
        {
          if ( v1->m_Network.m_TimerEvent.m_bRegistered )
          {
            *((_BYTE *)&v1->m_Network + 76) |= 1u;
          }
          else
          {
            v8 = &v1->m_Network.m_pPev->CBaseEdict;
            if ( v8 != nullptr )
            {
              CBaseEdict::StateChanged(this: v8, offset: 4 * i + 1440);
              v1 = this;
            }
          }
          v7->m_Value[0].m_Index = m_Index;
        }
        m_iszControlPointNames = v11;
      }
      else
      {
        pszValue = m_iszControlPointNames->pszValue;
        if ( m_iszControlPointNames->pszValue == nullptr )
          pszValue = locale;
        v5 = v1->m_iName.m_Value.pszValue;
        if ( v5 == nullptr )
          v5 = locale;
        _Warning(a1: "Particle system %s could not find control point entity (%s)\n", v5, pszValue);
      }
    }
    ++m_iszControlPointNames;
    ++i;
    v11 = m_iszControlPointNames;
  }
  while ( i < 63 );
}

//------------------------------------------------------------------------------
// Address: 0x1017C930
// Name: public: virtual bool CParticleSystem::KeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CParticleSystem::KeyValue(CParticleSystem *this, char *szKeyName, const char *szValue)
{
  CParticleSystem::NetworkVar_m_szSnapshotFileName *p_m_szSnapshotFileName; // esi
  CBaseEdict *v5; // ecx

  if ( szKeyName != "snapshot_file" && _V_stricmp(s1: szKeyName, s2: "snapshot_file") != 0 )
    return CBaseEntity::KeyValue(this, szKeyName, szValue);
  p_m_szSnapshotFileName = &this->m_szSnapshotFileName;
  if ( p_m_szSnapshotFileName[-3].m_Value[4] != 0 )
  {
    p_m_szSnapshotFileName[-3].m_Value[8] |= 1u;
  }
  else
  {
    v5 = *(CBaseEdict **)&p_m_szSnapshotFileName[-4].m_Value[204];
    if ( v5 != nullptr )
    {
      v5->m_fStateFlags |= 0x101u;
      CBaseEdict::GetChangeAccessor(this: v5)->m_iChangeInfoSerialNumber = 0;
    }
  }
  V_strncpy(pDest: p_m_szSnapshotFileName->m_Value, pSrc: szValue, maxLen: 260);
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x1017CA00
// Name: public: virtual void CParticleSystem::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSystem::Spawn(CParticleSystem *this)
{
  edict_t *m_pPev; // ecx

  CAI_BaseNPC::OnSetSchedule((vgui::Panel *)this);
  this->Precache(this);
  if ( this->m_iEffectIndex.m_Value != -1 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_iEffectIndex.m_Value = -1;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x468u);
      this->m_iEffectIndex.m_Value = -1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017CA60
// Name: public: void CParticleSystem::StartParticleSystem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSystem::StartParticleSystem(CParticleSystem *this)
{
  CParticleSystem *v1; // edx
  CNetworkVarBase<bool,CParticleSystem::NetworkVar_m_bActive> *p_m_bActive; // ebx
  CGlobalVars *v3; // edi
  CNetworkVarBase<float,CParticleSystem::NetworkVar_m_flStartTime> *p_m_flStartTime; // esi
  edict_t *m_pPev; // ecx
  CNetworkVarBase<bool,CParticleSystem::NetworkVar_m_bActive> *v6; // eax
  CBaseEdict *v7; // ecx

  v1 = this;
  p_m_bActive = &this->m_bActive;
  if ( !this->m_bActive.m_Value )
  {
    v3 = gpGlobals;
    p_m_flStartTime = &this->m_flStartTime;
    if ( this->m_flStartTime.m_Value != gpGlobals->curtime )
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
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x46Cu);
          v1 = this;
        }
      }
      p_m_flStartTime->m_Value = v3->curtime;
    }
    if ( !p_m_bActive->m_Value )
    {
      v6 = p_m_bActive - 1120;
      if ( p_m_bActive[-1036].m_Value )
      {
        v6[88].m_Value |= 1u;
        p_m_bActive->m_Value = true;
        CParticleSystem::ReadControlPointEnts(this: v1);
        return;
      }
      v7 = *(CBaseEdict **)&v6[24].m_Value;
      if ( v7 != nullptr )
      {
        CBaseEdict::StateChanged(this: v7, offset: 0x460u);
        v1 = this;
      }
      p_m_bActive->m_Value = true;
    }
    CParticleSystem::ReadControlPointEnts(this: v1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017CB20
// Name: public: void CParticleSystem::StopParticleSystem(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSystem::StopParticleSystem(CParticleSystem *this, int nStopType)
{
  edict_t *m_pPev; // ecx
  CNetworkVarBase<int,CParticleSystem::NetworkVar_m_nStopType> *p_m_nStopType; // esi
  edict_t *v5; // ecx

  if ( this->m_bActive.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x460u);
    }
    this->m_bActive.m_Value = false;
  }
  p_m_nStopType = &this->m_nStopType;
  if ( this->m_nStopType.m_Value != nStopType )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_nStopType->m_Value = nStopType;
    }
    else
    {
      v5 = this->m_Network.m_pPev;
      if ( v5 != nullptr )
        CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0x464u);
      p_m_nStopType->m_Value = nStopType;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017CBA0
// Name: public: void CParticleSystem::InputStart(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CParticleSystem::InputStart(CParticleSystem *this, inputdata_t *inputdata)
{
  CParticleSystem::StartParticleSystem(this);
}

//------------------------------------------------------------------------------
// Address: 0x1017CBB0
// Name: public: void CParticleSystem::InputStop(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSystem::InputStop(CParticleSystem *this, inputdata_t *inputdata)
{
  CParticleSystem::StopParticleSystem(this, nStopType: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1017CBC0
// Name: public: void CParticleSystem::InputDestroy(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSystem::InputDestroy(CParticleSystem *this, inputdata_t *inputdata)
{
  CParticleSystem::StopParticleSystem(this, nStopType: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1017CBD0
// Name: public: void CParticleSystem::InputStopEndCap(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSystem::InputStopEndCap(CParticleSystem *this, inputdata_t *inputdata)
{
  CParticleSystem::StopParticleSystem(this, nStopType: 2);
}

//------------------------------------------------------------------------------
// Address: 0x1017CBE0
// Name: public: virtual void CParticleSystem::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSystem::Activate(CParticleSystem *this)
{
  const char *pszValue; // eax
  int ParticleSystemIndex; // ebx
  edict_t *m_pPev; // ecx

  CBaseEntity::Activate(this);
  pszValue = this->m_iszEffectName.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  ParticleSystemIndex = GetParticleSystemIndex(pParticleSystemName: pszValue);
  if ( this->m_iEffectIndex.m_Value != ParticleSystemIndex )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x468u);
    }
    this->m_iEffectIndex.m_Value = ParticleSystemIndex;
  }
  if ( this->m_bStartActive )
  {
    this->m_bStartActive = false;
    CParticleSystem::StartParticleSystem(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017CC60
// Name: public: void CParticleSystem::StartParticleSystemThink(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CParticleSystem::StartParticleSystemThink(CParticleSystem *this)
{
  CParticleSystem::StartParticleSystem(this);
}

//------------------------------------------------------------------------------
// Address: 0x10406B40
// Name: DT_ParticleSystem::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_ParticleSystem::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_ParticleSystem::g_SendTable);
  return atexit(func: DT_ParticleSystem::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10406B60
// Name: DT_ParticleSystem::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_ParticleSystem::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_ParticleSystem::ignored>();
  DT_ParticleSystem::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10406B70
// Name: CParticleSystem_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CParticleSystem_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CParticleSystem>(__formal: nullptr);
  CParticleSystem_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041C8C0
// Name: DT_ParticleSystem::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_ParticleSystem::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_ParticleSystem::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1017CC70
// Name: struct datamap_t __near * DataMapInit<class CParticleSystem>(class CParticleSystem __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CParticleSystem>()
{
  if ( (_S4_41 & 1) == 0 )
  {
    _S4_41 |= 1u;
    nameHolder_286.m_pszBase = "CParticleSystem";
    nameHolder_286.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_286.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_286.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_286.m_Names.m_Size = 0;
    nameHolder_286.m_Names.m_pElements = nullptr;
    nameHolder_286.m_nLenBase = 15;
    atexit(func: DataMapInit_CParticleSystem__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CParticleSystem::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S4_41 & 2) == 0 )
  {
    _S4_41 |= 2u;
    dataDesc_273[83].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_286,
                                   pszIdentifier: "StartParticleSystemThink");
    dataDesc_273[83].fieldOffset = 0;
    *(_DWORD *)&dataDesc_273[83].fieldSize = 2097153;
    dataDesc_273[83].externalName = nullptr;
    dataDesc_273[83].pSaveRestoreOps = nullptr;
    dataDesc_273[83].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CParticleSystem::StartParticleSystemThink;
    *(_QWORD *)&dataDesc_273[83].td = 0;
    *(_QWORD *)&dataDesc_273[83].override_field = 0;
    *(_QWORD *)&dataDesc_273[83].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_273[83].flatOffset[1] = 0;
  }
  CParticleSystem::m_DataMap.dataNumFields = 83;
  CParticleSystem::m_DataMap.dataDesc = &dataDesc_273[1];
  return &CParticleSystem::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1041C8D0
// Name: _ServerClassInit_DT_ParticleSystem::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_ParticleSystem::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S3_84;
  for ( i = 15; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041C8F0
// Name: _DataMapInit_CParticleSystem__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CParticleSystem__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_286);
}

//------------------------------------------------------------------------------
// Address: 0x1041C900
// Name: _DataMapInit_CPathCorner__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CPathCorner__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_287);
}

//------------------------------------------------------------------------------
// Address: 0x1041C910
// Name: _DataMapInit_CPathTrack__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CPathTrack__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_288);
}

//------------------------------------------------------------------------------
// Address: 0x1041C920
// Name: _DataMapInit_CConstantForceController__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CConstantForceController__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_289);
}

//------------------------------------------------------------------------------
// Address: 0x1041C930
// Name: _DataMapInit_CPhysForce__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CPhysForce__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_290);
}

//------------------------------------------------------------------------------
// Address: 0x1041C940
// Name: _DataMapInit_CPhysThruster__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CPhysThruster__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_291);
}

//------------------------------------------------------------------------------
// Address: 0x1041C950
// Name: _DataMapInit_CPhysTorque__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CPhysTorque__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_292);
}

//------------------------------------------------------------------------------
// Address: 0x1041C960
// Name: _DataMapInit_CMotorController__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CMotorController__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_293);
}

//------------------------------------------------------------------------------
// Address: 0x1041C970
// Name: _DataMapInit_CPhysMotor__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CPhysMotor__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_294);
}

//------------------------------------------------------------------------------
// Address: 0x1041C980
// Name: _DataMapInit_CKeepUpright__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CKeepUpright__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_295);
}

//------------------------------------------------------------------------------
// Address: 0x1041C990
// Name: _dynamic_atexit_destructor_for__g_debug_constraint_sounds__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_debug_constraint_sounds__()
{
  ConVar::~ConVar(this: &g_debug_constraint_sounds);
}

//------------------------------------------------------------------------------
// Address: 0x1041C9A0
// Name: _dynamic_atexit_destructor_for__g_AnchorList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_AnchorList__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_AnchorList.m_list);
  IGameSystem::~IGameSystem(this: &g_AnchorList);
}

//------------------------------------------------------------------------------
// Address: 0x1041C9C0
// Name: _DataMapInit_CConstraintAnchor__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CConstraintAnchor__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_296);
}

//------------------------------------------------------------------------------
// Address: 0x1041C9D0
// Name: _DataMapInit_CPhysConstraintSystem__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CPhysConstraintSystem__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_297);
}

//------------------------------------------------------------------------------
// Address: 0x1041C9E0
// Name: _DataMapInit_CPhysConstraint__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CPhysConstraint__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_298);
}

//------------------------------------------------------------------------------
// Address: 0x1041C9F0
// Name: _DataMapInit_CPhysHinge__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CPhysHinge__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_299);
}

//------------------------------------------------------------------------------
// Address: 0x1041CA00
// Name: _DataMapInit_CPhysSlideConstraint__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CPhysSlideConstraint__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_300);
}

//------------------------------------------------------------------------------
// Address: 0x1041CA10
// Name: _DataMapInit_CPhysPulley__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CPhysPulley__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_301);
}

//------------------------------------------------------------------------------
// Address: 0x1041CA20
// Name: _DataMapInit_CPhysLength__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CPhysLength__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_302);
}

//------------------------------------------------------------------------------
// Address: 0x1041CA30
// Name: _DataMapInit_CRagdollConstraint__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CRagdollConstraint__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_303);
}
