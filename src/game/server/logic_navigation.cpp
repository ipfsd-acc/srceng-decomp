// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/logic_navigation.cpp
// Functions: 12
// ============================================================

#include "game\server\logic_navigation.h"

//------------------------------------------------------------------------------
// Address: 0x101661C0
// Name: private: virtual struct datamap_t __near * CLogicNavigation::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CLogicNavigation::GetDataDescMap(CLogicNavigation *this)
{
  return &CLogicNavigation::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101661D0
// Name: private: virtual void CLogicNavigation::UpdateOnRemove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicNavigation::UpdateOnRemove(CLogicNavigation *this)
{
  if ( this->m_isOn )
    CGlobalEntityList::RemoveListenerEntity(this: &gEntList, pListener: &this->IEntityListener);
  CBaseEntity::UpdateOnRemove(this);
}

//------------------------------------------------------------------------------
// Address: 0x10166200
// Name: private: virtual bool CLogicNavigation::KeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CLogicNavigation::KeyValue(CLogicNavigation *this, const char *szKeyName, const char *szValue)
{
  if ( szKeyName != "navprop" && _V_stricmp(s1: szKeyName, s2: "navprop") != 0 )
    return CServerOnlyPointEntity::KeyValue(this, szKeyName, szValue);
  if ( szValue != "Ignore" && _V_stricmp(s1: szValue, s2: "Ignore") != 0 )
  {
    _DevMsg(a1: 1, a2: "Unknown nav property %s\n", szValue);
    return true;
  }
  else
  {
    this->m_navProperty = NAV_IGNORE;
    return true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10166280
// Name: private: virtual void CLogicNavigation::OnEntitySpawned(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicNavigation::OnEntitySpawned(CLogicNavigation *this, CBaseEntity *pEntity)
{
  const char *v2; // eax

  if ( LOBYTE(this->m_pfnMoveDone) != 0 && ((int)this->m_pfnThink & 1) != 0 )
  {
    v2 = *((const char **)this - 169);
    if ( pEntity->m_iName.m_Value.pszValue == v2 )
      goto LABEL_7;
    if ( v2 == nullptr )
      v2 = locale;
    if ( CBaseEntity::NameMatchesComplex(this: pEntity, pszNameOrWildcard: v2) != 0 )
    {
LABEL_7:
      if ( pEntity->m_flNavIgnoreUntilTime < 3.4028235e38 )
        pEntity->m_flNavIgnoreUntilTime = 3.4028235e38;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101662E0
// Name: private: void CLogicNavigation::UpdateProperty(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicNavigation::UpdateProperty(CLogicNavigation *this)
{
  CBasePlayer *EntityByName; // eax
  const char *pszValue; // ecx

  EntityByName = nullptr;
  while ( 1 )
  {
    pszValue = this->m_target.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    EntityByName = CGlobalEntityList::FindEntityByName(
                     this: &gEntList,
                     pStartEntity: EntityByName,
                     szName: pszValue,
                     pSearchingEntity: nullptr,
                     pActivator: nullptr,
                     pCaller: nullptr,
                     pFilter: nullptr);
    if ( EntityByName == nullptr )
      break;
    if ( this->m_isOn )
    {
      if ( (this->m_navProperty & 1) != 0 && EntityByName->m_flNavIgnoreUntilTime < 3.4028235e38 )
        EntityByName->m_flNavIgnoreUntilTime = 3.4028235e38;
    }
    else if ( (this->m_navProperty & 1) != 0 )
    {
      EntityByName->m_flNavIgnoreUntilTime = 0.0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10166360
// Name: private: void CLogicNavigation::InputTurnOff(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicNavigation::InputTurnOff(CLogicNavigation *this, inputdata_t *inputdata)
{
  if ( this->m_isOn )
  {
    this->m_isOn = false;
    CGlobalEntityList::RemoveListenerEntity(this: &gEntList, pListener: &this->IEntityListener);
    CLogicNavigation::UpdateProperty(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10166390
// Name: private: void CLogicNavigation::InputTurnOn(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicNavigation::InputTurnOn(CLogicNavigation *this, inputdata_t *inputdata)
{
  if ( !this->m_isOn )
  {
    this->m_isOn = true;
    CGlobalEntityList::AddListenerEntity(this: &gEntList, pListener: &this->IEntityListener);
    CLogicNavigation::UpdateProperty(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101663C0
// Name: private: void CLogicNavigation::InputToggle(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicNavigation::InputToggle(CLogicNavigation *this, inputdata_t *inputdata)
{
  IEntityListener *v3; // eax

  v3 = &this->IEntityListener;
  if ( this->m_isOn )
  {
    this->m_isOn = false;
    CGlobalEntityList::RemoveListenerEntity(this: &gEntList, pListener: v3);
  }
  else
  {
    this->m_isOn = true;
    CGlobalEntityList::AddListenerEntity(this: &gEntList, pListener: v3);
  }
  CLogicNavigation::UpdateProperty(this);
}

//------------------------------------------------------------------------------
// Address: 0x10166490
// Name: private: virtual void CLogicNavigation::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicNavigation::Activate(CLogicNavigation *this)
{
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_spawnflags> *p_m_spawnflags; // edi
  unsigned int v3; // esi
  CNetworkVarBase<int,CBaseEntity::NetworkVar_m_spawnflags> *v4; // eax
  CBaseEdict *m_Value; // ecx

  CBaseEntity::Activate(this);
  p_m_spawnflags = &this->m_spawnflags;
  if ( (this->m_spawnflags.m_Value & 1) != 0 )
  {
    if ( !this->m_isOn )
    {
      this->m_isOn = true;
      CGlobalEntityList::AddListenerEntity(this: &gEntList, pListener: &this->IEntityListener);
      CLogicNavigation::UpdateProperty(this);
    }
    v3 = p_m_spawnflags->m_Value & 0xFFFFFFFE;
    if ( p_m_spawnflags->m_Value != v3 )
    {
      v4 = p_m_spawnflags - 190;
      if ( LOBYTE(p_m_spawnflags[-169].m_Value) != 0 )
      {
        LOBYTE(v4[22].m_Value) |= 1u;
        p_m_spawnflags->m_Value = v3;
      }
      else
      {
        m_Value = (CBaseEdict *)v4[6].m_Value;
        if ( m_Value != nullptr )
          CBaseEdict::StateChanged(this: m_Value, offset: 0x2F8u);
        p_m_spawnflags->m_Value = v3;
      }
    }
  }
  else if ( this->m_isOn )
  {
    CGlobalEntityList::AddListenerEntity(this: &gEntList, pListener: &this->IEntityListener);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10405730
// Name: CLogicNavigation_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CLogicNavigation_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CLogicNavigation>(__formal: nullptr);
  CLogicNavigation_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10166410
// Name: class CLogicNavigation __near * _CreateEntityTemplate<class CLogicNavigation>(class CLogicNavigation __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CLogicNavigation *__cdecl _CreateEntityTemplate<CLogicNavigation>(CLogicNavigation *newEnt, const char *className)
{
  CBaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x360u);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: true);
    v3[213] = &IEntityListener::`vftable';
    *v3 = &CLogicNavigation::`vftable'{for `CLogicalEntity'};
    v3[213] = &CLogicNavigation::`vftable'{for `IEntityListener'};
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CLogicNavigation *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10166530
// Name: struct datamap_t __near * DataMapInit<class CLogicNavigation>(class CLogicNavigation __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CLogicNavigation>()
{
  if ( (_S2_144 & 1) == 0 )
  {
    _S2_144 |= 1u;
    nameHolder_247.m_pszBase = "CLogicNavigation";
    nameHolder_247.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_247.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_247.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_247.m_Names.m_Size = 0;
    nameHolder_247.m_Names.m_pElements = nullptr;
    nameHolder_247.m_nLenBase = 16;
    atexit(func: DataMapInit_CLogicNavigation__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CLogicNavigation::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CLogicNavigation::m_DataMap.dataNumFields = 5;
  CLogicNavigation::m_DataMap.dataDesc = &dataDesc_234[1];
  return &CLogicNavigation::m_DataMap;
}
