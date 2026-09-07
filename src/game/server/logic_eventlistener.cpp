// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/logic_eventlistener.cpp
// Functions: 7
// ============================================================

#include "game\server\logic_eventlistener.h"

//------------------------------------------------------------------------------
// Address: 0x10165440
// Name: private: virtual struct datamap_t __near * CLogicEventListener::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CLogicEventListener::GetDataDescMap(CLogicEventListener *this)
{
  return &CLogicEventListener::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10165450
// Name: public: void CLogicEventListener::InputEnable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicEventListener::InputEnable(CLogicEventListener *this, inputdata_t *inputdata)
{
  this->m_bIsEnabled = true;
}

//------------------------------------------------------------------------------
// Address: 0x10165460
// Name: public: void CLogicEventListener::InputDisable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicEventListener::InputDisable(CLogicEventListener *this, inputdata_t *inputdata)
{
  this->m_bIsEnabled = false;
}

//------------------------------------------------------------------------------
// Address: 0x10165470
// Name: public: virtual void CLogicEventListener::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicEventListener::Spawn(CLogicEventListener *this)
{
  const char *pszValue; // edx

  CAI_BaseNPC::OnSetSchedule((vgui::Panel *)this);
  pszValue = this->m_iszEventName.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: &this->CGameEventListener, a3: pszValue, a4: true);
}

//------------------------------------------------------------------------------
// Address: 0x101654C0
// Name: public: virtual void CLogicEventListener::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicEventListener::FireGameEvent(CLogicEventListener *this, IGameEvent *event)
{
  CLogicEventListener *v2; // edi
  const char *v3; // eax
  const char *v4; // ecx
  int v5; // ebx
  int v6; // edi
  CBasePlayer *v7; // eax
  CBaseEntity *v8; // esi
  int TeamNumber; // eax

  v2 = this;
  if ( LOBYTE(this->m_Network.__vftable) != 0 )
  {
    v3 = event->GetName(this: event);
    v4 = (const char *)v2->m_Network.CLogicalEntity::CServerOnlyEntity::CBaseEntity::__vftable;
    if ( v4 == nullptr )
      v4 = locale;
    if ( _V_strcmp(s1: v3, s2: v4) == 0 )
    {
      if ( (int)v2->m_Network.m_pOuter <= 0 )
      {
LABEL_14:
        COutputEvent::FireOutput(
          this: (COutputEvent *)&v2->m_Network.m_pPev,
          pActivator: nullptr,
          pCaller: nullptr,
          fDelay: 0.0);
        return;
      }
      v5 = event->GetInt(this: event, a2: "userid", a3: 0);
      v6 = 0;
      while ( 1 )
      {
        v7 = UTIL_PlayerByIndex(playerIndex: v6);
        v8 = v7;
        if ( v7 != nullptr && engine->GetPlayerUserId(this: engine, a2: v7->m_Network.m_pPev) == v5 )
          break;
        if ( ++v6 > 64 )
        {
          TeamNumber = -1;
          goto LABEL_12;
        }
      }
      TeamNumber = CBaseEntity::GetTeamNumber(this: v8);
LABEL_12:
      if ( (CBaseEntity *)TeamNumber == this->m_Network.m_pOuter )
      {
        v2 = this;
        goto LABEL_14;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10165580
// Name: public: CLogicEventListener::CLogicEventListener(void)
// Source: json
//------------------------------------------------------------------------------
CLogicEventListener *__thiscall CLogicEventListener::CLogicEventListener(CLogicEventListener *this)
{
  CBaseEntity::CBaseEntity(this, bServerOnly: true);
  this->CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&CGameEventListener::`vftable';
  this->m_bRegisteredForEvents = false;
  this->m_nDebugID = 42;
  this->CLogicalEntity::CServerOnlyEntity::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable = (CLogicEventListener_vtbl *)&CLogicEventListener::`vftable'{for `CLogicalEntity'};
  this->CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&CLogicEventListener::`vftable'{for `CGameEventListener'};
  this->m_OnEventFired.m_Value.iVal = 0;
  this->m_OnEventFired.m_Value.eVal.m_Index = -1;
  this->m_OnEventFired.m_Value.fieldType = FIELD_VOID;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104056D0
// Name: CLogicEventListener_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CLogicEventListener_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CLogicEventListener>();
  CLogicEventListener_DataDescInit::g_DataMapHolder = result;
  return result;
}
