// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/cstrike15/func_hostage_rescue.cpp
// Functions: 82
// ============================================================

#include "game\server\cstrike15\func_hostage_rescue.h"

//------------------------------------------------------------------------------
// Address: 0x1029BEE0
// Name: public: virtual struct datamap_t __near * CHostageRescueZone::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CHostageRescueZone::GetDataDescMap(CHostageRescueZone *this)
{
  return &CHostageRescueZone::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1029BEF0
// Name: public: void CHostageRescueZone::HostageRescueTouch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHostageRescueZone::HostageRescueTouch(CHostageRescueZone *this, CBaseEntity *pOther)
{
  ((void (__thiscall *)(CBaseEntity *, const char *, _DWORD, _DWORD, _DWORD))pOther->AcceptInput)(
    a1: pOther,
    a2: "OnRescueZoneTouch",
    a3: 0,
    a4: 0,
    a5: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1029BF40
// Name: public: virtual void CHostageRescueZone::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHostageRescueZone::Spawn(CHostageRescueZone *this)
{
  CBaseTrigger::InitTrigger(this);
  this->m_pfnTouch = (void (__thiscall *)(CBaseEntity *, CBaseEntity *))CHostageRescueZone::HostageRescueTouch;
}

//------------------------------------------------------------------------------
// Address: 0x1040F6F0
// Name: CHostageRescueZone_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CHostageRescueZone_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CHostageRescueZone>(__formal: nullptr);
  CHostageRescueZone_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029BF80
// Name: struct datamap_t __near * DataMapInit<class CHostageRescueZone>(class CHostageRescueZone __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CHostageRescueZone>()
{
  if ( (_S2_252 & 1) == 0 )
  {
    _S2_252 |= 1u;
    nameHolder_481.m_pszBase = "CHostageRescueZone";
    nameHolder_481.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_481.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_481.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_481.m_Names.m_Size = 0;
    nameHolder_481.m_Names.m_pElements = nullptr;
    nameHolder_481.m_nLenBase = 18;
    atexit(func: DataMapInit_CHostageRescueZone__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CHostageRescueZone::m_DataMap.baseMap = &CBaseTrigger::m_DataMap;
  if ( (_S2_252 & 2) == 0 )
  {
    _S2_252 |= 2u;
    dataDesc_502[1].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_481,
                                  pszIdentifier: "HostageRescueTouch");
    dataDesc_502[1].fieldOffset = 0;
    *(_DWORD *)&dataDesc_502[1].fieldSize = 2097153;
    dataDesc_502[1].externalName = nullptr;
    dataDesc_502[1].pSaveRestoreOps = nullptr;
    dataDesc_502[1].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CHostageRescueZone::HostageRescueTouch;
    *(_QWORD *)&dataDesc_502[1].td = 0;
    *(_QWORD *)&dataDesc_502[1].override_field = 0;
    *(_QWORD *)&dataDesc_502[1].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_502[1].flatOffset[1] = 0;
  }
  CHostageRescueZone::m_DataMap.dataNumFields = 1;
  CHostageRescueZone::m_DataMap.dataDesc = &dataDesc_502[1];
  return &CHostageRescueZone::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1040F700
// Name: _dynamic_initializer_for__g_FUNFACT_DAMAGE_WITH_GRENADES_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_DAMAGE_WITH_GRENADES_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_DAMAGE_WITH_GRENADES_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_DAMAGE_WITH_GRENADES_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040F720
// Name: _dynamic_initializer_for__g_FUNFACT_KNIFE_KILLS_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_KNIFE_KILLS_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_KNIFE_KILLS_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_KNIFE_KILLS_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040F740
// Name: _dynamic_initializer_for__g_FUNFACT_KILLS_WITH_GRENADES_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_KILLS_WITH_GRENADES_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_KILLS_WITH_GRENADES_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_KILLS_WITH_GRENADES_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040F760
// Name: _dynamic_initializer_for__g_FUNFACT_BLIND_KILLS_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_BLIND_KILLS_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_BLIND_KILLS_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_BLIND_KILLS_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040F780
// Name: _dynamic_initializer_for__g_FUNFACT_KILLED_ENEMIES_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_KILLED_ENEMIES_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_KILLED_ENEMIES_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_KILLED_ENEMIES_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040F7A0
// Name: _dynamic_initializer_for__g_FUNFACT_KILLS_WITH_LAST_ROUND_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_KILLS_WITH_LAST_ROUND_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_KILLS_WITH_LAST_ROUND_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_KILLS_WITH_LAST_ROUND_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040F7C0
// Name: _dynamic_initializer_for__g_FUNFACT_DONATED_WEAPONS_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_DONATED_WEAPONS_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_DONATED_WEAPONS_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_DONATED_WEAPONS_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040F7E0
// Name: _dynamic_initializer_for__g_FUNFACT_NUM_TIMES_JUMPED_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_NUM_TIMES_JUMPED_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_NUM_TIMES_JUMPED_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_NUM_TIMES_JUMPED_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040F800
// Name: _dynamic_initializer_for__g_FUNFACT_FALL_DAMAGE_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_FALL_DAMAGE_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_FALL_DAMAGE_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_FALL_DAMAGE_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040F820
// Name: _dynamic_initializer_for__g_FUNFACT_POSTHUMOUS_KILLS_WITH_GRENADE_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_POSTHUMOUS_KILLS_WITH_GRENADE_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_POSTHUMOUS_KILLS_WITH_GRENADE_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_POSTHUMOUS_KILLS_WITH_GRENADE_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040F840
// Name: _dynamic_initializer_for__g_FUNFACT_ITEMS_PURCHASED_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_ITEMS_PURCHASED_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_ITEMS_PURCHASED_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_ITEMS_PURCHASED_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040F860
// Name: _dynamic_initializer_for__g_FUNFACT_NUMBER_OF_OVERKILLS_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_NUMBER_OF_OVERKILLS_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_NUMBER_OF_OVERKILLS_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_NUMBER_OF_OVERKILLS_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040F880
// Name: _dynamic_initializer_for__g_FUNFACT_MONEY_SPENT_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_MONEY_SPENT_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_MONEY_SPENT_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_MONEY_SPENT_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040F8A0
// Name: _dynamic_initializer_for__g_FUNFACT_GRENADES_THROWN_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_GRENADES_THROWN_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_GRENADES_THROWN_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_GRENADES_THROWN_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040F8C0
// Name: _dynamic_initializer_for__g_FUNFACT_DEFENDED_BOMB_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_DEFENDED_BOMB_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_DEFENDED_BOMB_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_DEFENDED_BOMB_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040F8E0
// Name: _dynamic_initializer_for__g_FUNFACT_ITEMS_DROPPED_VALUE_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_ITEMS_DROPPED_VALUE_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_ITEMS_DROPPED_VALUE_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_ITEMS_DROPPED_VALUE_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040F900
// Name: _dynamic_initializer_for__g_FUNFACT_KILL_WOUNDED_ENEMIES_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_KILL_WOUNDED_ENEMIES_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_KILL_WOUNDED_ENEMIES_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_KILL_WOUNDED_ENEMIES_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040F920
// Name: _dynamic_initializer_for__g_FUNFACT_KILLS_HEADSHOTS_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_KILLS_HEADSHOTS_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_KILLS_HEADSHOTS_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_KILLS_HEADSHOTS_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040F940
// Name: _dynamic_initializer_for__g_FUNFACT_BROKE_WINDOWS_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_BROKE_WINDOWS_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_BROKE_WINDOWS_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_BROKE_WINDOWS_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040F960
// Name: _dynamic_initializer_for__g_FUNFACT_SHOTS_FIRED_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_SHOTS_FIRED_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_SHOTS_FIRED_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_SHOTS_FIRED_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040F980
// Name: _dynamic_initializer_for__g_FUNFACT_KILL_DEFUSER_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_KILL_DEFUSER_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_KILL_DEFUSER_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_KILL_DEFUSER_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040F9A0
// Name: _dynamic_initializer_for__g_FUNFACT_KILL_RESCUER_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_KILL_RESCUER_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_KILL_RESCUER_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_KILL_RESCUER_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040F9C0
// Name: _dynamic_initializer_for__g_FUNFACT_KILLS_WITH_SINGLE_GRENADE_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_KILLS_WITH_SINGLE_GRENADE_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_KILLS_WITH_SINGLE_GRENADE_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_KILLS_WITH_SINGLE_GRENADE_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040F9E0
// Name: _dynamic_initializer_for__g_FUNFACT_DAMAGE_NO_KILLS_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_DAMAGE_NO_KILLS_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_DAMAGE_NO_KILLS_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_DAMAGE_NO_KILLS_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040FA00
// Name: _dynamic_initializer_for__g_FUNFACT_FIRST_KILL_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_FIRST_KILL_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_FIRST_KILL_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_FIRST_KILL_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040FA20
// Name: _dynamic_initializer_for__g_FUNFACT_FIRST_BLOOD_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_FIRST_BLOOD_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_FIRST_BLOOD_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_FIRST_BLOOD_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040FA40
// Name: _dynamic_initializer_for__g_FUNFACT_BEST_ACCURACY_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_BEST_ACCURACY_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_BEST_ACCURACY_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_BEST_ACCURACY_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040FA60
// Name: _dynamic_initializer_for__g_FUNFACT_KNIFE_IN_GUNFIGHT_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_KNIFE_IN_GUNFIGHT_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_KNIFE_IN_GUNFIGHT_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_KNIFE_IN_GUNFIGHT_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040FA80
// Name: _dynamic_initializer_for__g_FUNFACT_SURVIVED_MULTIPLE_ATTACKERS_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_SURVIVED_MULTIPLE_ATTACKERS_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_SURVIVED_MULTIPLE_ATTACKERS_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_SURVIVED_MULTIPLE_ATTACKERS_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040FAA0
// Name: _dynamic_initializer_for__g_FUNFACT_DIED_FROM_MULTIPLE_ATTACKERS_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_DIED_FROM_MULTIPLE_ATTACKERS_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_DIED_FROM_MULTIPLE_ATTACKERS_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_DIED_FROM_MULTIPLE_ATTACKERS_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040FAC0
// Name: _dynamic_initializer_for__g_FUNFACT_USED_ALL_AMMO_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_USED_ALL_AMMO_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_USED_ALL_AMMO_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_USED_ALL_AMMO_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040FAE0
// Name: _dynamic_initializer_for__g_FUNFACT_DAMAGE_MULTIPLE_ENEMIES_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_DAMAGE_MULTIPLE_ENEMIES_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_DAMAGE_MULTIPLE_ENEMIES_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_DAMAGE_MULTIPLE_ENEMIES_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040FB00
// Name: _dynamic_initializer_for__g_FUNFACT_USED_MULTIPLE_WEAPONS_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_USED_MULTIPLE_WEAPONS_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_USED_MULTIPLE_WEAPONS_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_USED_MULTIPLE_WEAPONS_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040FB20
// Name: _dynamic_initializer_for__g_FUNFACT_DEFUSED_WITH_DROPPED_KIT_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_DEFUSED_WITH_DROPPED_KIT_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_DEFUSED_WITH_DROPPED_KIT_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_DEFUSED_WITH_DROPPED_KIT_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040FB40
// Name: _dynamic_initializer_for__g_FUNFACT_KILLED_HALF_OF_ENEMIES_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_KILLED_HALF_OF_ENEMIES_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_KILLED_HALF_OF_ENEMIES_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_KILLED_HALF_OF_ENEMIES_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040FB60
// Name: _dynamic_initializer_for__g_FUNFACT_CT_WIN_NO_KILLS_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_CT_WIN_NO_KILLS_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_CT_WIN_NO_KILLS_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_CT_WIN_NO_KILLS_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040FB80
// Name: _dynamic_initializer_for__g_FUNFACT_T_WIN_NO_KILLS_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_T_WIN_NO_KILLS_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_T_WIN_NO_KILLS_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_T_WIN_NO_KILLS_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040FBA0
// Name: _dynamic_initializer_for__g_FUNFACT_T_WIN_NO_CASUALTIES_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_T_WIN_NO_CASUALTIES_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_T_WIN_NO_CASUALTIES_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_T_WIN_NO_CASUALTIES_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040FBC0
// Name: _dynamic_initializer_for__g_FUNFACT_CT_WIN_NO_CASUALTIES_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_CT_WIN_NO_CASUALTIES_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_CT_WIN_NO_CASUALTIES_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_CT_WIN_NO_CASUALTIES_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040FBE0
// Name: _dynamic_initializer_for__g_FUNFACT_SHORT_ROUND_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_SHORT_ROUND_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_SHORT_ROUND_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_SHORT_ROUND_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040FC00
// Name: _dynamic_initializer_for__g_FUNFACT_WON_AS_LAST_MEMBER_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_WON_AS_LAST_MEMBER_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_WON_AS_LAST_MEMBER_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_WON_AS_LAST_MEMBER_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040FC20
// Name: _dynamic_initializer_for__g_FUNFACT_TERRORIST_ACCURACY_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_TERRORIST_ACCURACY_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_TERRORIST_ACCURACY_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_TERRORIST_ACCURACY_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040FC40
// Name: _dynamic_initializer_for__g_FUNFACT_CT_ACCURACY_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_CT_ACCURACY_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_CT_ACCURACY_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_CT_ACCURACY_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040FC60
// Name: _dynamic_initializer_for__g_FUNFACT_BEST_TERRORIST_ACCURACY_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_BEST_TERRORIST_ACCURACY_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_BEST_TERRORIST_ACCURACY_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_BEST_TERRORIST_ACCURACY_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040FC80
// Name: _dynamic_initializer_for__g_FUNFACT_BEST_COUNTERTERRORIST_ACCURACY_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_BEST_COUNTERTERRORIST_ACCURACY_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_BEST_COUNTERTERRORIST_ACCURACY_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_BEST_COUNTERTERRORIST_ACCURACY_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040FCA0
// Name: _dynamic_initializer_for__g_FUNFACT_SHOTS_FIRED_FALLBACK_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_SHOTS_FIRED_FALLBACK_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_SHOTS_FIRED_FALLBACK_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_SHOTS_FIRED_FALLBACK_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040FCC0
// Name: _dynamic_initializer_for__g_FUNFACT_KNIFE_LEVEL_REACHED_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_KNIFE_LEVEL_REACHED_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_KNIFE_LEVEL_REACHED_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_KNIFE_LEVEL_REACHED_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040FCE0
// Name: _dynamic_initializer_for__g_FUNFACT_MAX_KILLED_BEFORE_DYING_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_MAX_KILLED_BEFORE_DYING_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_MAX_KILLED_BEFORE_DYING_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_MAX_KILLED_BEFORE_DYING_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040FD00
// Name: _dynamic_initializer_for__g_FUNFACT_MAX_RESPAWNS_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_MAX_RESPAWNS_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_MAX_RESPAWNS_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_MAX_RESPAWNS_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040FD20
// Name: _dynamic_initializer_for__g_FUNFACT_DEFAULT_WEAPON_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_DEFAULT_WEAPON_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_DEFAULT_WEAPON_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_DEFAULT_WEAPON_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040FD40
// Name: _dynamic_initializer_for__g_FUNFACT_ROUNDS_WITHOUT_DYING_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_ROUNDS_WITHOUT_DYING_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_ROUNDS_WITHOUT_DYING_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_ROUNDS_WITHOUT_DYING_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040FD60
// Name: _dynamic_initializer_for__g_FUNFACT_TASER_KILL_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_TASER_KILL_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_TASER_KILL_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_TASER_KILL_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040FD80
// Name: _dynamic_initializer_for__g_FUNFACT_TICKING_TIME_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_TICKING_TIME_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_TICKING_TIME_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_TICKING_TIME_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040FDA0
// Name: _dynamic_initializer_for__g_FUNFACT_CT_WIN_TIME_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_CT_WIN_TIME_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_CT_WIN_TIME_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_CT_WIN_TIME_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040FDC0
// Name: _dynamic_initializer_for__g_FUNFACT_TER_WIN_TIME_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_TER_WIN_TIME_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_TER_WIN_TIME_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_TER_WIN_TIME_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040FDE0
// Name: _dynamic_initializer_for__g_FUNFACT_HIGHEST_CONTRIBUTING_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_HIGHEST_CONTRIBUTING_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_HIGHEST_CONTRIBUTING_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_HIGHEST_CONTRIBUTING_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040FE00
// Name: _dynamic_initializer_for__g_FUNFACT_BIGGEST_GRIEFER_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_BIGGEST_GRIEFER_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_BIGGEST_GRIEFER_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_BIGGEST_GRIEFER_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040FE20
// Name: _dynamic_initializer_for__g_FUNFACT_CT_AVERAGE_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_CT_AVERAGE_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_CT_AVERAGE_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_CT_AVERAGE_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040FE40
// Name: _dynamic_initializer_for__g_FUNFACT_TER_AVERAGE_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_TER_AVERAGE_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_TER_AVERAGE_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_TER_AVERAGE_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040FE60
// Name: _dynamic_initializer_for__g_FUNFACT_HIGHEST_PROXIMITY_SCORE_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_HIGHEST_PROXIMITY_SCORE_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_HIGHEST_PROXIMITY_SCORE_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_HIGHEST_PROXIMITY_SCORE_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040FE80
// Name: _dynamic_initializer_for__g_FUNFACT_BOTS_ASSUMED_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_BOTS_ASSUMED_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_BOTS_ASSUMED_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_BOTS_ASSUMED_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040FEA0
// Name: _dynamic_initializer_for__g_FUNFACT_DOMINATION_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_DOMINATION_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_DOMINATION_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_DOMINATION_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040FEC0
// Name: _dynamic_initializer_for__g_FUNFACT_REVENGE_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_REVENGE_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_REVENGE_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_REVENGE_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040FEE0
// Name: _dynamic_initializer_for__g_FUNFACT_STEPS_TAKEN_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_STEPS_TAKEN_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_STEPS_TAKEN_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_STEPS_TAKEN_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040FF00
// Name: _dynamic_initializer_for__g_FUNFACT_QUARTER_HEALTH_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_QUARTER_HEALTH_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_QUARTER_HEALTH_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_QUARTER_HEALTH_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040FF20
// Name: _dynamic_initializer_for__g_FUNFACT_GUNS_USED_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_GUNS_USED_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_GUNS_USED_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_GUNS_USED_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040FF40
// Name: _dynamic_initializer_for__g_FUNFACT_EMPTY_GUNS_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_EMPTY_GUNS_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_EMPTY_GUNS_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_EMPTY_GUNS_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040FF60
// Name: _dynamic_initializer_for__g_FUNFACT_SLOW_TRIGGER_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_SLOW_TRIGGER_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_SLOW_TRIGGER_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_SLOW_TRIGGER_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040FF80
// Name: _dynamic_initializer_for__g_FUNFACT_PICKUP_BOMB_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_PICKUP_BOMB_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_PICKUP_BOMB_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_PICKUP_BOMB_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040FFA0
// Name: _dynamic_initializer_for__g_FUNFACT_BOMB_CARRIERS_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_BOMB_CARRIERS_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_BOMB_CARRIERS_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_BOMB_CARRIERS_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040FFC0
// Name: _dynamic_initializer_for__g_FUNFACT_KNIFE_BOMB_PLANTER_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_KNIFE_BOMB_PLANTER_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_KNIFE_BOMB_PLANTER_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_KNIFE_BOMB_PLANTER_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040FFE0
// Name: _dynamic_initializer_for__g_FUNFACT_BOMB_PLANTED_BEFORE_KILL_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_BOMB_PLANTED_BEFORE_KILL_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_BOMB_PLANTED_BEFORE_KILL_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_BOMB_PLANTED_BEFORE_KILL_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10410000
// Name: _dynamic_initializer_for__g_FUNFACT_FAILED_BOMB_PLANTS_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_FAILED_BOMB_PLANTS_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_FAILED_BOMB_PLANTS_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_FAILED_BOMB_PLANTS_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10410020
// Name: _dynamic_initializer_for__g_FUNFACT_KNIFE_WITHOUT_AMMO_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_KNIFE_WITHOUT_AMMO_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_KNIFE_WITHOUT_AMMO_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_KNIFE_WITHOUT_AMMO_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10410040
// Name: _dynamic_initializer_for__g_FUNFACT_MOLOTOV_BURNS_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_MOLOTOV_BURNS_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_MOLOTOV_BURNS_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_MOLOTOV_BURNS_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10410060
// Name: _dynamic_initializer_for__g_FUNFACT_SURVIVAL_TIME_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_SURVIVAL_TIME_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_SURVIVAL_TIME_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_SURVIVAL_TIME_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10410080
// Name: _dynamic_initializer_for__g_FUNFACT_PULLED_TRIGGER_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunFactHelper *dynamic_initializer_for__g_FUNFACT_PULLED_TRIGGER_Helper__()
{
  CFunFactHelper *result; // eax

  result = CFunFactHelper::s_pFirst;
  g_FUNFACT_PULLED_TRIGGER_Helper.m_pNext = CFunFactHelper::s_pFirst;
  CFunFactHelper::s_pFirst = &g_FUNFACT_PULLED_TRIGGER_Helper;
  return result;
}
