// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/logic_playerproxy.cpp
// Functions: 5
// ============================================================

#include "game\server\logic_playerproxy.h"

//------------------------------------------------------------------------------
// Address: 0x101665B0
// Name: private: virtual struct datamap_t __near * CLogicPlayerProxy::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CLogicPlayerProxy::GetDataDescMap(CLogicPlayerProxy *this)
{
  return &CLogicPlayerProxy::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101665C0
// Name: public: virtual void CLogicPlayerProxy::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicPlayerProxy::Activate(CLogicPlayerProxy *this)
{
  unsigned int m_Index; // eax
  CBasePlayer *LocalPlayer; // eax

  CBaseEntity::Activate(this);
  m_Index = this->m_hPlayer.m_Index;
  if ( m_Index == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
  {
    if ( gpGlobals->maxClients <= 1 )
      LocalPlayer = UTIL_GetLocalPlayer();
    else
      LocalPlayer = nullptr;
    if ( LocalPlayer != nullptr )
      this->m_hPlayer.m_Index = LocalPlayer->GetRefEHandle(this: LocalPlayer)->m_Index;
    else
      this->m_hPlayer.m_Index = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10166690
// Name: public: CLogicPlayerProxy::CLogicPlayerProxy(void)
// Source: json
//------------------------------------------------------------------------------
CLogicPlayerProxy *__thiscall CLogicPlayerProxy::CLogicPlayerProxy(CLogicPlayerProxy *this)
{
  CBaseEntity::CBaseEntity(this, bServerOnly: true);
  this->__vftable = (CLogicPlayerProxy_vtbl *)&CLogicPlayerProxy::`vftable';
  this->m_PlayerHasAmmo.m_Value.iVal = 0;
  this->m_PlayerHasAmmo.m_Value.eVal.m_Index = -1;
  this->m_PlayerHasAmmo.m_Value.fieldType = FIELD_VOID;
  this->m_PlayerHasNoAmmo.m_Value.iVal = 0;
  this->m_PlayerHasNoAmmo.m_Value.eVal.m_Index = -1;
  this->m_PlayerHasNoAmmo.m_Value.fieldType = FIELD_VOID;
  this->m_PlayerDied.m_Value.iVal = 0;
  this->m_PlayerDied.m_Value.eVal.m_Index = -1;
  this->m_PlayerDied.m_Value.fieldType = FIELD_VOID;
  this->m_OnDuck.m_Value.iVal = 0;
  this->m_OnDuck.m_Value.eVal.m_Index = -1;
  this->m_OnDuck.m_Value.fieldType = FIELD_VOID;
  this->m_OnUnDuck.m_Value.iVal = 0;
  this->m_OnUnDuck.m_Value.eVal.m_Index = -1;
  this->m_OnUnDuck.m_Value.fieldType = FIELD_VOID;
  this->m_OnJump.m_Value.iVal = 0;
  this->m_OnJump.m_Value.eVal.m_Index = -1;
  this->m_OnJump.m_Value.fieldType = FIELD_VOID;
  this->m_RequestedPlayerHealth.m_Value.iVal = 0;
  this->m_RequestedPlayerHealth.m_Value.eVal.m_Index = -1;
  this->m_RequestedPlayerHealth.m_Value.fieldType = FIELD_VOID;
  this->m_hPlayer.m_Index = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10166730
// Name: public: virtual CLogicPlayerProxy::~CLogicPlayerProxy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicPlayerProxy::~CLogicPlayerProxy(CLogicPlayerProxy *this)
{
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_RequestedPlayerHealth);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnJump);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnUnDuck);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnDuck);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_PlayerDied);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_PlayerHasNoAmmo);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_PlayerHasAmmo);
  CBaseEntity::~CBaseEntity(this);
}

//------------------------------------------------------------------------------
// Address: 0x10405760
// Name: CLogicPlayerProxy_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CLogicPlayerProxy_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CLogicPlayerProxy>();
  CLogicPlayerProxy_DataDescInit::g_DataMapHolder = result;
  return result;
}
