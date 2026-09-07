// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/cstrike15/func_buy_zone.cpp
// Functions: 5
// ============================================================

#include "game\server\cstrike15\func_buy_zone.h"

//------------------------------------------------------------------------------
// Address: 0x1029BC40
// Name: public: virtual struct datamap_t __near * CBuyZone::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CBuyZone::GetDataDescMap(CBuyZone *this)
{
  return &CBuyZone::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1029BC50
// Name: public: void CBuyZone::BuyZoneTouch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBuyZone::BuyZoneTouch(CBuyZone *this, CBaseEntity *pOther)
{
  CBaseEntity *v3; // eax
  CBaseEntity *v4; // edi
  int TeamNumber; // ebx
  CBaseEdict *v6; // ecx

  v3 = (CBaseEntity *)__RTDynamicCast(
                        inptr: pOther,
                        VfDelta: 0,
                        SrcType: &CBaseEntity `RTTI Type Descriptor',
                        TargetType: &CCSPlayer `RTTI Type Descriptor',
                        isReference: 0);
  v4 = v3;
  if ( v3 != nullptr )
  {
    TeamNumber = CBaseEntity::GetTeamNumber(this: v3);
    if ( TeamNumber == CBaseEntity::GetTeamNumber(this) )
    {
      if ( HIBYTE(v4[7].m_Network.m_PVSInfo.m_nAreaNum) != 1 )
      {
        if ( v4->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&v4->m_Network + 76) |= 1u;
          HIBYTE(v4[7].m_Network.m_PVSInfo.m_nAreaNum) = 1;
          CCSPlayer::AutoBuyAmmo(this: (CCSPlayer *)v4);
          return;
        }
        v6 = &v4->m_Network.m_pPev->CBaseEdict;
        if ( v6 != nullptr )
          CBaseEdict::StateChanged(this: v6, offset: 0x1771u);
        HIBYTE(v4[7].m_Network.m_PVSInfo.m_nAreaNum) = 1;
      }
      CCSPlayer::AutoBuyAmmo(this: (CCSPlayer *)v4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1029BCE0
// Name: public: virtual void CBuyZone::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBuyZone::Spawn(CBuyZone *this)
{
  int m_LegacyTeamNum; // eax

  CBaseTrigger::InitTrigger(this);
  m_LegacyTeamNum = this->m_LegacyTeamNum;
  this->m_pfnTouch = (void (__thiscall *)(CBaseEntity *, CBaseEntity *))CBuyZone::BuyZoneTouch;
  if ( m_LegacyTeamNum == 1 )
  {
    this->ChangeTeam(this, a2: 2);
  }
  else if ( m_LegacyTeamNum == 2 )
  {
    this->ChangeTeam(this, a2: 3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1040F6C0
// Name: CBuyZone_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CBuyZone_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CBuyZone>(__formal: nullptr);
  CBuyZone_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029BD30
// Name: struct datamap_t __near * DataMapInit<class CBuyZone>(class CBuyZone __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CBuyZone>()
{
  char *Name; // eax

  if ( (_S2_251 & 1) == 0 )
  {
    _S2_251 |= 1u;
    nameHolder_480.m_pszBase = "CBuyZone";
    nameHolder_480.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_480.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_480.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_480.m_Names.m_Size = 0;
    nameHolder_480.m_Names.m_pElements = nullptr;
    nameHolder_480.m_nLenBase = 8;
    atexit(func: DataMapInit_CBuyZone__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CBuyZone::m_DataMap.baseMap = &CBaseTrigger::m_DataMap;
  if ( (_S2_251 & 2) == 0 )
  {
    _S2_251 |= 2u;
    Name = CDatadescGeneratedNameHolder::GenerateName(this: &nameHolder_480, pszIdentifier: "BuyZoneTouch");
    *(_QWORD *)&dataDesc_501[1].td = 0;
    *(_QWORD *)&dataDesc_501[1].override_field = 0;
    *(_QWORD *)&dataDesc_501[1].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_501[1].flatOffset[1] = 0;
    dataDesc_501[1].fieldName = Name;
    dataDesc_501[1].fieldOffset = 0;
    *(_DWORD *)&dataDesc_501[1].fieldSize = 2097153;
    dataDesc_501[1].externalName = nullptr;
    dataDesc_501[1].pSaveRestoreOps = nullptr;
    dataDesc_501[1].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CBuyZone::BuyZoneTouch;
    dataDesc_501[2].fieldType = FIELD_INTEGER;
    dataDesc_501[2].fieldName = "m_LegacyTeamNum";
    dataDesc_501[2].fieldOffset = 1152;
    *(_DWORD *)&dataDesc_501[2].fieldSize = 917505;
    dataDesc_501[2].externalName = "team";
    dataDesc_501[2].pSaveRestoreOps = nullptr;
    dataDesc_501[2].inputFunc = nullptr;
    dataDesc_501[2].td = nullptr;
    dataDesc_501[2].fieldSizeInBytes = 4;
    *(_QWORD *)&dataDesc_501[2].override_field = 0;
    *(_QWORD *)&dataDesc_501[2].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_501[2].flatOffset[1] = 0;
  }
  CBuyZone::m_DataMap.dataNumFields = 2;
  CBuyZone::m_DataMap.dataDesc = &dataDesc_501[1];
  return &CBuyZone::m_DataMap;
}
