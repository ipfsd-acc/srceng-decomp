// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/player_resource.cpp
// Functions: 11
// ============================================================

#include "game\server\player_resource.h"

//------------------------------------------------------------------------------
// Address: 0x101CF180
// Name: public: virtual class ServerClass __near * CPlayerResource::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CPlayerResource::GetServerClass(CPlayerResource *this)
{
  return &g_CPlayerResource_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x101CF190
// Name: public: virtual struct datamap_t __near * CPlayerResource::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CPlayerResource::GetDataDescMap(CPlayerResource *this)
{
  return &CPlayerResource::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101CF1A0
// Name: public: virtual void CPlayerResource::ResourceThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlayerResource::ResourceThink(CPlayerResource *this)
{
  void (*UpdatePlayerData)(void); // edx

  UpdatePlayerData = (void (*)(void))this->UpdatePlayerData;
  ++this->m_nUpdateCounter;
  UpdatePlayerData();
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101CF460
// Name: public: virtual void CPlayerResource::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlayerResource::Spawn(CPlayerResource *this)
{
  int v2; // esi
  CPlayerResource::NetworkVar_m_iPing *p_m_iPing; // ebx
  int *v4; // eax
  CBaseEdict *v5; // ecx
  edict_t *m_pPev; // ecx
  edict_t *v7; // ecx
  edict_t *v8; // ecx
  edict_t *v9; // ecx
  edict_t *v10; // ecx

  v2 = 0;
  p_m_iPing = &this->m_iPing;
  do
  {
    if ( p_m_iPing->m_Value[v2] != 0 )
    {
      v4 = &p_m_iPing[-4].m_Value[47];
      if ( LOBYTE(p_m_iPing[-3].m_Value[3]) != 0 )
      {
        *((_BYTE *)v4 + 88) |= 1u;
      }
      else
      {
        v5 = (CBaseEdict *)v4[6];
        if ( v5 != nullptr )
          CBaseEdict::StateChanged(this: v5, offset: 4 * v2 + 852);
      }
      p_m_iPing->m_Value[v2] = 0;
    }
    if ( this->m_iKills.m_Value[v2] != 0 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 4 * v2 + 1112);
      }
      this->m_iKills.m_Value[v2] = 0;
    }
    if ( this->m_iDeaths.m_Value[v2] != 0 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v7 = this->m_Network.m_pPev;
        if ( v7 != nullptr )
          CBaseEdict::StateChanged(this: &v7->CBaseEdict, offset: 4 * v2 + 1372);
      }
      this->m_iDeaths.m_Value[v2] = 0;
    }
    if ( this->m_bConnected.m_Value[v2] != 0 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v8 = this->m_Network.m_pPev;
        if ( v8 != nullptr )
          CBaseEdict::StateChanged(this: &v8->CBaseEdict, offset: 4 * v2 + 1632);
      }
      this->m_bConnected.m_Value[v2] = 0;
    }
    if ( this->m_iTeam.m_Value[v2] != 0 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v9 = this->m_Network.m_pPev;
        if ( v9 != nullptr )
          CBaseEdict::StateChanged(this: &v9->CBaseEdict, offset: 4 * v2 + 1892);
      }
      this->m_iTeam.m_Value[v2] = 0;
    }
    if ( this->m_bAlive.m_Value[v2] != 0 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v10 = this->m_Network.m_pPev;
        if ( v10 != nullptr )
          CBaseEdict::StateChanged(this: &v10->CBaseEdict, offset: 4 * v2 + 2152);
      }
      this->m_bAlive.m_Value[v2] = 0;
    }
    ++v2;
  }
  while ( v2 < 65 );
  CBaseEntity::ThinkSet(this, func:  __thiscall CAI_BattleLine::`vcall'{776,{flat}}, thinkTime: 0.0, szContext: nullptr);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
  this->m_nUpdateCounter = 0;
}

//------------------------------------------------------------------------------
// Address: 0x101CF670
// Name: public: virtual void CPlayerResource::UpdatePlayerData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlayerResource::UpdatePlayerData(CPlayerResource *this)
{
  int v1; // esi
  CBasePlayer *v2; // eax
  CBasePlayer *v3; // edx
  int m_iFrags; // ebx
  CPlayerResource::NetworkVar_m_iKills *p_m_iKills; // edi
  CBaseEdict *v6; // ecx
  int m_iDeaths; // ebx
  CPlayerResource::NetworkVar_m_iDeaths *p_m_iDeaths; // edi
  CBaseEdict *v9; // ecx
  CPlayerResource::NetworkVar_m_bConnected *v10; // edi
  CBaseEdict *v11; // ecx
  int TeamNumber; // ebx
  CPlayerResource::NetworkVar_m_iTeam *p_m_iTeam; // edi
  CBaseEdict *v14; // ecx
  int v15; // ebx
  CPlayerResource::NetworkVar_m_bAlive *p_m_bAlive; // edi
  CBaseEdict *v17; // ecx
  CPlayerResource::NetworkVar_m_iHealth *p_m_iHealth; // edi
  int v19; // ebx
  CBaseEdict *v20; // ecx
  int v21; // eax
  int v22; // edx
  CPlayerResource::NetworkVar_m_iPing *p_m_iPing; // edi
  CBaseEdict *v24; // ecx
  CPlayerResource::NetworkVar_m_bConnected *p_m_bConnected; // edi
  CBaseEdict *v26; // ecx
  int packetloss; // [esp+4h] [ebp-10h] BYREF
  int ping; // [esp+8h] [ebp-Ch] BYREF
  CBasePlayer *pPlayer; // [esp+Ch] [ebp-8h]
  CPlayerResource *i; // [esp+10h] [ebp-4h]

  v1 = 1;
  for ( i = this; v1 <= gpGlobals->maxClients; ++v1 )
  {
    v2 = UTIL_PlayerByIndex(playerIndex: v1);
    v3 = v2;
    pPlayer = v2;
    if ( v2 == nullptr || v2->m_iConnected == PlayerDisconnected )
    {
      p_m_bConnected = &i->m_bConnected;
      if ( i->m_bConnected.m_Value[v1] != 0 )
      {
        if ( i->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&i->m_Network + 76) |= 1u;
        }
        else
        {
          v26 = &i->m_Network.m_pPev->CBaseEdict;
          if ( v26 != nullptr )
            CBaseEdict::StateChanged(this: v26, offset: 4 * v1 + 1632);
        }
        p_m_bConnected->m_Value[v1] = 0;
      }
    }
    else
    {
      m_iFrags = v2->m_iFrags;
      p_m_iKills = &i->m_iKills;
      if ( i->m_iKills.m_Value[v1] != m_iFrags )
      {
        if ( i->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&i->m_Network + 76) |= 1u;
        }
        else
        {
          v6 = &i->m_Network.m_pPev->CBaseEdict;
          if ( v6 != nullptr )
          {
            CBaseEdict::StateChanged(this: v6, offset: 4 * v1 + 1112);
            v3 = pPlayer;
          }
        }
        p_m_iKills->m_Value[v1] = m_iFrags;
      }
      m_iDeaths = v3->m_iDeaths;
      p_m_iDeaths = &i->m_iDeaths;
      if ( i->m_iDeaths.m_Value[v1] != m_iDeaths )
      {
        if ( i->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&i->m_Network + 76) |= 1u;
        }
        else
        {
          v9 = &i->m_Network.m_pPev->CBaseEdict;
          if ( v9 != nullptr )
          {
            CBaseEdict::StateChanged(this: v9, offset: 4 * v1 + 1372);
            v3 = pPlayer;
          }
        }
        p_m_iDeaths->m_Value[v1] = m_iDeaths;
      }
      v10 = &i->m_bConnected;
      if ( i->m_bConnected.m_Value[v1] != 1 )
      {
        if ( i->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&i->m_Network + 76) |= 1u;
        }
        else
        {
          v11 = &i->m_Network.m_pPev->CBaseEdict;
          if ( v11 != nullptr )
          {
            CBaseEdict::StateChanged(this: v11, offset: 4 * v1 + 1632);
            v3 = pPlayer;
          }
        }
        v10->m_Value[v1] = 1;
      }
      TeamNumber = CBaseEntity::GetTeamNumber(this: v3);
      p_m_iTeam = &i->m_iTeam;
      if ( i->m_iTeam.m_Value[v1] != TeamNumber )
      {
        if ( i->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&i->m_Network + 76) |= 1u;
        }
        else
        {
          v14 = &i->m_Network.m_pPev->CBaseEdict;
          if ( v14 != nullptr )
            CBaseEdict::StateChanged(this: v14, offset: 4 * v1 + 1892);
        }
        p_m_iTeam->m_Value[v1] = TeamNumber;
      }
      v15 = pPlayer->IsAlive(this: pPlayer);
      p_m_bAlive = &i->m_bAlive;
      if ( i->m_bAlive.m_Value[v1] != v15 )
      {
        if ( i->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&i->m_Network + 76) |= 1u;
        }
        else
        {
          v17 = &i->m_Network.m_pPev->CBaseEdict;
          if ( v17 != nullptr )
            CBaseEdict::StateChanged(this: v17, offset: 4 * v1 + 2152);
        }
        p_m_bAlive->m_Value[v1] = v15;
      }
      p_m_iHealth = &i->m_iHealth;
      v19 = pPlayer->m_iHealth.m_Value < 0 ? 0 : pPlayer->m_iHealth.m_Value;
      if ( i->m_iHealth.m_Value[v1] != v19 )
      {
        if ( i->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&i->m_Network + 76) |= 1u;
        }
        else
        {
          v20 = &i->m_Network.m_pPev->CBaseEdict;
          if ( v20 != nullptr )
            CBaseEdict::StateChanged(this: v20, offset: 4 * v1 + 2412);
        }
        p_m_iHealth->m_Value[v1] = v19;
      }
      if ( i->m_nUpdateCounter % 20 == 0 )
      {
        UTIL_GetPlayerConnectionInfo(playerIndex: v1, &ping, &packetloss);
        v21 = i->m_iPing.m_Value[v1];
        v22 = (int)(float)((float)((float)v21 * 0.80000001) + (float)((float)ping * 0.2));
        ping = v22;
        if ( v21 != v22 )
        {
          p_m_iPing = &i->m_iPing;
          if ( i->m_Network.m_TimerEvent.m_bRegistered )
          {
            *((_BYTE *)&i->m_Network + 76) |= 1u;
            p_m_iPing->m_Value[v1] = v22;
          }
          else
          {
            v24 = &i->m_Network.m_pPev->CBaseEdict;
            if ( v24 != nullptr )
            {
              CBaseEdict::StateChanged(this: v24, offset: 4 * v1 + 852);
              v22 = ping;
            }
            p_m_iPing->m_Value[v1] = v22;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10408360
// Name: DT_PlayerResource::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_PlayerResource::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_PlayerResource::g_SendTable);
  return atexit(func: DT_PlayerResource::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10408380
// Name: DT_PlayerResource::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_PlayerResource::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_PlayerResource::ignored>();
  DT_PlayerResource::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10408390
// Name: CPlayerResource_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CPlayerResource_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CPlayerResource>();
  CPlayerResource_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041D2F0
// Name: DT_PlayerResource::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_PlayerResource::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_PlayerResource::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041D300
// Name: _ServerClassInit_DT_PlayerResource::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_PlayerResource::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_172;
  for ( i = 7; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041D320
// Name: _DataMapInit_CPlayerResource__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CPlayerResource__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_328);
}
