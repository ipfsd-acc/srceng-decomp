// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/subs.cpp
// Functions: 31
// ============================================================

#include "game\server\subs.h"

//------------------------------------------------------------------------------
// Address: 0x100E4790
// Name: public: virtual bool CBaseToggle::KeyValue(char const __near *,class Vector)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseToggle::KeyValue(CBaseToggle *this, const char *szKeyName, Vector vec)
{
  return CBaseEntity::KeyValue(this, szKeyName, vecValue: &vec);
}

//------------------------------------------------------------------------------
// Address: 0x100E47B0
// Name: public: virtual bool CBaseToggle::KeyValue(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseToggle::KeyValue(CBaseToggle *this, const char *szKeyName, float flValue)
{
  return CBaseEntity::KeyValue(this, szKeyName, flValue);
}

//------------------------------------------------------------------------------
// Address: 0x1019B600
// Name: public: virtual void CNullEntity::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNullEntity::Spawn(CBaseEntity *this)
{
  UTIL_Remove(oldObj: this);
}

//------------------------------------------------------------------------------
// Address: 0x1022B200
// Name: public: virtual struct datamap_t __near * CBaseDMStart::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CBaseDMStart::GetDataDescMap(CBaseDMStart *this)
{
  return &CBaseDMStart::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1022B210
// Name: public: virtual bool CBaseDMStart::IsTriggered(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseDMStart::IsTriggered(CBaseDMStart *this, CBaseEntity *pEntity)
{
  return UTIL_IsMasterTriggered(sMaster: this->m_Master, pActivator: pEntity);
}

//------------------------------------------------------------------------------
// Address: 0x1022B230
// Name: public: virtual struct datamap_t __near * CBaseToggle::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CBaseToggle::GetDataDescMap(CBaseToggle *this)
{
  return &CBaseToggle::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1022B240
// Name: public: virtual class ServerClass __near * CBaseToggle::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CBaseToggle::GetServerClass(CBaseToggle *this)
{
  return &g_CBaseToggle_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x1022B250
// Name: public: static float CBaseToggle::AxisDelta(int,class QAngle const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
double __cdecl CBaseToggle::AxisDelta(char flags, const QAngle *angle1, const QAngle *angle2)
{
  if ( (flags & 0x40) != 0 )
    return angle1->z - angle2->z;
  if ( flags >= 0 )
    return angle1->y - angle2->y;
  return angle1->x - angle2->x;
}

//------------------------------------------------------------------------------
// Address: 0x1022B290
// Name: public: virtual void CPointEntity::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPointEntity::Spawn(CPointEntity *this)
{
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
}

//------------------------------------------------------------------------------
// Address: 0x1022B2A0
// Name: void FireTargets(char const __near *,class CBaseEntity __near *,class CBaseEntity __near *,enum USE_TYPE,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FireTargets(
        const char *targetName,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller,
        USE_TYPE useType,
        float value)
{
  CBaseEntity *i; // esi
  const char *DebugName; // eax

  if ( targetName != nullptr && *targetName != 0 )
  {
    _DevMsg(a1: 2, a2: "Firing: (%s)\n", targetName);
    for ( i = CGlobalEntityList::FindEntityByName(
                this: &gEntList,
                pStartEntity: nullptr,
                szName: targetName,
                pSearchingEntity: pActivator,
                pActivator,
                pCaller,
                pFilter: nullptr);
          i != nullptr;
          i = CGlobalEntityList::FindEntityByName(
                this: &gEntList,
                pStartEntity: i,
                szName: targetName,
                pSearchingEntity: pActivator,
                pActivator,
                pCaller,
                pFilter: nullptr) )
    {
      if ( (i->m_iEFlags & 1) == 0 )
      {
        DebugName = CBaseEntity::GetDebugName(this: i);
        _DevMsg(a1: 2, a2: "[%03d] Found: %s, firing (%s)\n", gpGlobals->tickcount % 1000, DebugName, targetName);
        ((void (__thiscall *)(CBaseEntity *, CBaseEntity *, CBaseEntity *, USE_TYPE, _DWORD))i->Use)(
          a1: i,
          a2: pActivator,
          a3: pCaller,
          a4: useType,
          a5: LODWORD(value));
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022B370
// Name: public: virtual bool CBaseToggle::KeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseToggle::KeyValue(CBaseToggle *this, char *szKeyName, const char *szValue)
{
  if ( szKeyName != "lip" && _V_stricmp(s1: szKeyName, s2: "lip") != 0 )
  {
    if ( szKeyName != "wait" && _V_stricmp(s1: szKeyName, s2: "wait") != 0 )
    {
      if ( szKeyName != "master" && _V_stricmp(s1: szKeyName, s2: "master") != 0 )
      {
        if ( szKeyName != "distance" && _V_stricmp(s1: szKeyName, s2: "distance") != 0 )
        {
          return CBaseEntity::KeyValue(this, szKeyName, szValue);
        }
        else
        {
          this->m_flMoveDistance = atof(nptr: szValue);
          return true;
        }
      }
      else
      {
        this->m_sMaster.pszValue = *(const char **)AllocPooledString(pszValue: (const char *)&szValue).pszValue;
        return true;
      }
    }
    else
    {
      this->m_flWait = atof(nptr: szValue);
      return true;
    }
  }
  else
  {
    this->m_flLip = atof(nptr: szValue);
    return true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022B470
// Name: public: virtual bool CBaseToggle::IsLockedByMaster(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseToggle::IsLockedByMaster(CBaseToggle *this)
{
  unsigned int m_Index; // edx
  CBaseEntity *m_pEntity; // eax
  bool result; // al

  result = false;
  if ( this->m_sMaster.pszValue != nullptr )
  {
    m_Index = this->m_hActivator.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    if ( !UTIL_IsMasterTriggered(sMaster: this->m_sMaster, pActivator: m_pEntity) )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1022B4D0
// Name: public: void CBaseToggle::AxisDir(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseToggle::AxisDir(CBaseToggle *this)
{
  int m_Value; // eax

  m_Value = this->m_spawnflags.m_Value;
  if ( (m_Value & 0x40) != 0 )
  {
    this->m_vecMoveAng.x = 0.0;
    this->m_vecMoveAng.y = 0.0;
    this->m_vecMoveAng.z = 1.0;
  }
  else
  {
    if ( (m_Value & 0x80u) == 0 )
    {
      this->m_vecMoveAng.x = 0.0;
      this->m_vecMoveAng.y = 1.0;
    }
    else
    {
      this->m_vecMoveAng.x = 1.0;
      this->m_vecMoveAng.y = 0.0;
    }
    this->m_vecMoveAng.z = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022B670
// Name: public: virtual void CBaseToggle::GetGroundVelocityToApply(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseToggle::GetGroundVelocityToApply(CBaseToggle *this, Vector *vecGroundVel)
{
  *vecGroundVel = this->m_vecVelocity.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x1022B720
// Name: public: void CBaseEntity::SUB_Remove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseEntity::SUB_Remove(CBaseEntity *this)
{
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_iHealth> *p_m_iHealth; // esi

  p_m_iHealth = &this->m_iHealth;
  if ( this->m_iHealth.m_Value > 0 )
  {
    this->NetworkStateChanged_m_iHealth(this, a2: &this->m_iHealth);
    p_m_iHealth->m_Value = 0;
    _DevWarning(a1: 2, a2: "SUB_Remove called on entity with health > 0\n");
  }
  UTIL_Remove(oldObj: this);
}

//------------------------------------------------------------------------------
// Address: 0x1022B7B0
// Name: public: CBaseToggle::CBaseToggle(void)
// Source: json
//------------------------------------------------------------------------------
CBaseToggle *__thiscall CBaseToggle::CBaseToggle(CBaseToggle *this)
{
  CBaseEntity::CBaseEntity(this, bServerOnly: false);
  this->__vftable = (CBaseToggle_vtbl *)&CBaseToggle::`vftable';
  this->m_hActivator.m_Index = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1022B7D0
// Name: public: void CBaseToggle::LinearMove(class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBaseToggle::LinearMove(CBaseToggle *this@<ecx>, int a2@<ebp>, const Vector *vecDest, float flSpeed)
{
  bool v4; // zf
  CNetworkVectorBase<Vector,CBaseToggle::NetworkVar_m_vecFinalDest> *p_m_vecFinalDest; // esi
  edict_t *m_pPev; // edx
  CNetworkVarBase<int,CBaseToggle::NetworkVar_m_movementType> *p_m_movementType; // esi
  edict_t *v8; // edx
  float x; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  __int128 v13; // xmm1
  float z; // edi
  float v15; // xmm0_4
  CBaseEdict *v16; // ecx
  __int128 v17; // [esp+14h] [ebp-3Ch] BYREF
  float v18; // [esp+2Ch] [ebp-24h]
  float v19; // [esp+30h] [ebp-20h]
  float v20; // [esp+34h] [ebp-1Ch]
  Vector vecDestDelta; // [esp+38h] [ebp-18h]
  int v22; // [esp+44h] [ebp-Ch]
  float flTravelTime; // [esp+48h] [ebp-8h]
  float retaddr; // [esp+50h] [ebp+0h]

  v22 = a2;
  flTravelTime = retaddr;
  v4 = vecDest->x == this->m_vecFinalDest.m_Value.x;
  p_m_vecFinalDest = &this->m_vecFinalDest;
  LODWORD(vecDestDelta.z) = this;
  if ( !v4 || vecDest->y != this->m_vecFinalDest.m_Value.y || vecDest->z != this->m_vecFinalDest.m_Value.z )
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
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x3A8u);
        this = (CBaseToggle *)LODWORD(vecDestDelta.z);
      }
    }
    p_m_vecFinalDest->m_Value = *vecDest;
  }
  p_m_movementType = &this->m_movementType;
  if ( this->m_movementType.m_Value != 1 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v8 = this->m_Network.m_pPev;
      if ( v8 != nullptr )
      {
        CBaseEdict::StateChanged(this: &v8->CBaseEdict, offset: 0x3C0u);
        this = (CBaseToggle *)LODWORD(vecDestDelta.z);
      }
    }
    p_m_movementType->m_Value = 1;
  }
  x = this->m_vecOrigin.m_Value.x;
  if ( x == vecDest->x && this->m_vecOrigin.m_Value.y == vecDest->y && this->m_vecOrigin.m_Value.z == vecDest->z )
  {
    this->MoveDone(this);
  }
  else
  {
    v10 = vecDest->x - x;
    v11 = vecDest->z - this->m_vecOrigin.m_Value.z;
    v19 = vecDest->y - this->m_vecOrigin.m_Value.y;
    v20 = v11;
    v18 = v10;
    v12 = (float)((float)(v19 * v19) + (float)(v18 * v18)) + (float)(v11 * v11);
    v13 = 0;
    *(float *)&v13 = fsqrt(v12);
    v17 = v13;
    vecDestDelta.y = *(float *)&v13 / flSpeed;
    CBaseEntity::SetMoveDoneTime(this, flDelay: *(float *)&v13 / flSpeed);
    z = vecDestDelta.z;
    v15 = gpGlobals->curtime + (float)(*(float *)&v13 / flSpeed);
    LODWORD(v13) = *(_DWORD *)(LODWORD(vecDestDelta.z) + 964);
    vecDestDelta.x = gpGlobals->curtime + vecDestDelta.y;
    if ( *(float *)&v13 != v15 )
    {
      if ( *(_BYTE *)(LODWORD(vecDestDelta.z) + 84) != 0 )
      {
        *(_BYTE *)(LODWORD(vecDestDelta.z) + 88) |= 1u;
      }
      else
      {
        v16 = *(CBaseEdict **)(LODWORD(vecDestDelta.z) + 24);
        if ( v16 != nullptr )
        {
          CBaseEdict::StateChanged(this: v16, offset: 0x3C4u);
          v15 = vecDestDelta.x;
        }
      }
      *(float *)(LODWORD(z) + 964) = v15;
    }
    *((float *)&v17 + 1) = (float)(1.0 / vecDestDelta.y) * v18;
    *((float *)&v17 + 2) = (float)(1.0 / vecDestDelta.y) * v19;
    *((float *)&v17 + 3) = (float)(1.0 / vecDestDelta.y) * v20;
    CBaseEntity::SetLocalVelocity(this: (CBaseEntity *)LODWORD(z), vecVelocity: (const Vector *)((char *)&v17 + 4));
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022BA00
// Name: public: virtual void CBaseToggle::MoveDone(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseToggle::MoveDone(CBaseToggle *this)
{
  edict_t *m_pPev; // ecx
  void (__thiscall *m_pfnMoveDone)(CBaseEntity *); // eax

  if ( this->m_movementType.m_Value == 1 )
  {
    UTIL_SetOrigin(entity: this, vecOrigin: &this->m_vecFinalDest.m_Value, bFireTriggers: false);
    CBaseEntity::SetAbsVelocity(this, vecAbsVelocity: &vec3_origin);
  }
  else
  {
    if ( this->m_movementType.m_Value != 2 )
      goto LABEL_6;
    CBaseEntity::SetLocalAngles(this, angles: &this->m_vecFinalAngle);
    CBaseEntity::SetLocalAngularVelocity(this, vecAngVelocity: &vec3_angle);
  }
  CBaseEntity::SetMoveDoneTime(this, flDelay: -1.0);
LABEL_6:
  if ( this->m_movementType.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x3C0u);
    }
    this->m_movementType.m_Value = 0;
  }
  m_pfnMoveDone = this->m_pfnMoveDone;
  if ( m_pfnMoveDone != nullptr )
    m_pfnMoveDone(this);
}

//------------------------------------------------------------------------------
// Address: 0x1022BAB0
// Name: public: void CBaseToggle::AngularMove(class QAngle const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBaseToggle::AngularMove(
        CBaseToggle *this@<ecx>,
        float a2@<ebp>,
        const QAngle *vecDestAngle,
        float flSpeed)
{
  edict_t *m_pPev; // ecx
  float x; // xmm1_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm0_4
  __int128 v11; // xmm1
  float flDelay; // xmm0_4
  float v13; // xmm0_4
  __int128 v14; // [esp+14h] [ebp-2Ch] BYREF
  float v15; // [esp+24h] [ebp-1Ch]
  float v16; // [esp+28h] [ebp-18h]
  float v17; // [esp+2Ch] [ebp-14h]
  QAngle vecDestDelta; // [esp+30h] [ebp-10h]
  float retaddr; // [esp+40h] [ebp+0h]

  vecDestDelta.y = a2;
  vecDestDelta.z = retaddr;
  this->m_vecFinalAngle = *vecDestAngle;
  if ( this->m_movementType.m_Value != 2 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x3C0u);
    }
    this->m_movementType.m_Value = 2;
  }
  x = this->m_angRotation.m_Value.x;
  if ( x == vecDestAngle->x
    && this->m_angRotation.m_Value.y == vecDestAngle->y
    && this->m_angRotation.m_Value.z == vecDestAngle->z )
  {
    this->MoveDone(this);
  }
  else
  {
    v7 = vecDestAngle->x - x;
    v8 = vecDestAngle->z - this->m_angRotation.m_Value.z;
    v9 = v7;
    v16 = vecDestAngle->y - this->m_angRotation.m_Value.y;
    v17 = v8;
    v10 = (float)(v16 * v16) + (float)(v8 * v8);
    v15 = v9;
    v11 = 0;
    *(float *)&v11 = fsqrt(v10 + (float)(v9 * v9));
    v14 = v11;
    flDelay = *(float *)&v11 / flSpeed;
    vecDestDelta.x = *(float *)&v11 / flSpeed;
    if ( (float)(*(float *)&v11 / flSpeed) < 0.0099999998 )
    {
      flDelay = 0.0099999998;
      vecDestDelta.x = 0.0099999998;
    }
    CBaseEntity::SetMoveDoneTime(this, flDelay);
    v13 = 1.0 / vecDestDelta.x;
    *((float *)&v14 + 1) = v13 * v15;
    *((float *)&v14 + 2) = v16 * v13;
    *((float *)&v14 + 3) = v13 * v17;
    CBaseEntity::SetLocalAngularVelocity(this, vecAngVelocity: (const QAngle *)((char *)&v14 + 4));
  }
}

//------------------------------------------------------------------------------
// Address: 0x1040A8D0
// Name: CBaseDMStart_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CBaseDMStart_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CBaseDMStart>(__formal: nullptr);
  CBaseDMStart_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040A940
// Name: CBaseToggle_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CBaseToggle_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CBaseToggle>(__formal: nullptr);
  CBaseToggle_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040A970
// Name: DT_BaseToggle::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseToggle::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_BaseToggle::g_SendTable);
  return atexit(func: DT_BaseToggle::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1040A990
// Name: DT_BaseToggle::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseToggle::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_BaseToggle::ignored>();
  DT_BaseToggle::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041E2E0
// Name: DT_BaseToggle::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_BaseToggle::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_BaseToggle::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1022BC50
// Name: struct datamap_t __near * DataMapInit<class CBaseDMStart>(class CBaseDMStart __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CBaseDMStart>()
{
  if ( (_S2_212 & 1) == 0 )
  {
    _S2_212 |= 1u;
    nameHolder_402.m_pszBase = "CBaseDMStart";
    nameHolder_402.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_402.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_402.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_402.m_Names.m_Size = 0;
    nameHolder_402.m_Names.m_pElements = nullptr;
    nameHolder_402.m_nLenBase = 12;
    atexit(func: DataMapInit_CBaseDMStart__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CBaseDMStart::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CBaseDMStart::m_DataMap.dataNumFields = 1;
  CBaseDMStart::m_DataMap.dataDesc = &dataDesc_382[1];
  return &CBaseDMStart::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1022BCC0
// Name: struct datamap_t __near * DataMapInit<class CBaseToggle>(class CBaseToggle __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CBaseToggle>()
{
  if ( (_S3_123 & 1) == 0 )
  {
    _S3_123 |= 1u;
    nameHolder_403.m_pszBase = "CBaseToggle";
    nameHolder_403.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_403.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_403.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_403.m_Names.m_Size = 0;
    nameHolder_403.m_Names.m_pElements = nullptr;
    nameHolder_403.m_nLenBase = 11;
    atexit(func: DataMapInit_CBaseToggle__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CBaseToggle::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CBaseToggle::m_DataMap.dataNumFields = 15;
  CBaseToggle::m_DataMap.dataDesc = &dataDesc_383[1];
  return &CBaseToggle::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1040A950
// Name: _dynamic_initializer_for__g_CBaseToggle_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CBaseToggle_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CBaseToggle_ClassReg,
           pNetworkName: "CBaseToggle",
           pTable: &DT_BaseToggle::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1040A9A0
// Name: _dynamic_initializer_for__g_CSun_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CSun_ClassReg__()
{
  return ServerClass::ServerClass(this: &g_CSun_ClassReg, pNetworkName: "CSun", pTable: &DT_Sun::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041E2F0
// Name: _ServerClassInit_DT_BaseToggle::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_BaseToggle::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S4_58;
  for ( i = 4; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041E310
// Name: _DataMapInit_CBaseDMStart__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CBaseDMStart__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_402);
}

//------------------------------------------------------------------------------
// Address: 0x1041E320
// Name: _DataMapInit_CBaseToggle__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CBaseToggle__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_403);
}
