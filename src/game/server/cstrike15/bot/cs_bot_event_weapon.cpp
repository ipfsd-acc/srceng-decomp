// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/cstrike15/bot/cs_bot_event_weapon.cpp
// Functions: 5
// ============================================================

#include "game\server\cstrike15\bot\cs_bot_event_weapon.h"

//------------------------------------------------------------------------------
// Address: 0x102B0360
// Name: public: void CCSBot::OnWeaponZoom(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::OnWeaponZoom(CCSBot *this, IGameEvent *event)
{
  int v3; // eax
  CCSBot *v4; // eax
  int savedregs; // [esp+24h] [ebp+0h] BYREF

  if ( this->IsAlive(this) )
  {
    v3 = event->GetInt(this: event, a2: "userid", a3: 0);
    v4 = (CCSBot *)UTIL_PlayerByUserId(userID: v3);
    if ( v4 != this )
      CCSBot::OnAudibleEvent(
        this,
        a2: COERCE_FLOAT(&savedregs),
        event,
        player: v4,
        range: 1100.0,
        priority: PRIORITY_LOW,
        isHostile: false,
        isFootstep: false,
        actualOrigin: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B03C0
// Name: public: void CCSBot::ForceRun(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::ForceRun(CCSBot *this, float duration)
{
  CountdownTimer *p_m_mustRunTimer; // edi
  double v4; // st7
  CNetworkVarBase<float,CountdownTimer::NetworkVar_m_timestamp> *p_m_timestamp; // esi
  float v6; // [esp+8h] [ebp-4h]

  this->Run(this);
  p_m_mustRunTimer = &this->m_mustRunTimer;
  v4 = IntervalTimer::Now(this: (CEffectsServer *)&this->m_mustRunTimer) + duration;
  p_m_timestamp = &this->m_mustRunTimer.m_timestamp;
  if ( p_m_mustRunTimer->m_timestamp.m_Value != v4 )
  {
    p_m_mustRunTimer->NetworkStateChanged(this: p_m_mustRunTimer, a2: &p_m_mustRunTimer->m_timestamp);
    v6 = v4;
    p_m_timestamp->m_Value = v6;
  }
  if ( p_m_mustRunTimer->m_duration.m_Value != duration )
  {
    p_m_mustRunTimer->NetworkStateChanged(this: p_m_mustRunTimer, a2: &p_m_mustRunTimer->m_duration);
    p_m_mustRunTimer->m_duration.m_Value = duration;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B0440
// Name: public: void CCSBot::OnWeaponFire(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CCSBot::OnWeaponFire(CCSBot *this@<ecx>, int a2@<ebx>, int a3@<esi>, IGameEvent *event)
{
  int v5; // eax
  CCSBot *v6; // ebx
  const char *v7; // eax
  CSWeaponID v8; // eax
  float range; // xmm0_4
  int savedregs; // [esp+38h] [ebp+0h] BYREF

  if ( this->IsAlive(this) )
  {
    v5 = event->GetInt(this: event, a2: "userid", a3: 0);
    v6 = (CCSBot *)UTIL_PlayerByUserId(userID: v5);
    if ( v6 != this )
    {
      if ( (CCSBot *)((int (__thiscall *)(CCSBot *, int, int))this->GetEnemy_2)(a1: this, a2: a3, a3: a2) == v6
        && CCSBot::IsUsingKnife(this) )
      {
        CCSBot::ForceRun(this, duration: 5.0);
      }
      v7 = event->GetString(this: event, a2: "weapon", a3: locale);
      if ( v7 != nullptr )
      {
        v8 = AliasToWeaponID(szAlias: v7);
        if ( v8 != -1 )
        {
          switch ( v8 )
          {
            case WEAPON_AWP:
              range = 99999.0;
              goto LABEL_13;
            case WEAPON_KNIFE:
              goto $LN5_54;
            case WEAPON_FLASHBANG:
            case WEAPON_HEGRENADE:
            case WEAPON_SMOKEGRENADE:
            case WEAPON_MOLOTOV:
            case WEAPON_DECOY:
            case WEAPON_C4:
            case WEAPON_SHIELDGUN:
              return;
            default:
              if ( event->GetBool(this: event, a2: "silenced", a3: false) )
$LN5_54:
                range = 1000.0;
              else
                range = 2000.0;
LABEL_13:
              CCSBot::OnAudibleEvent(
                this,
                a2: COERCE_FLOAT(&savedregs),
                event,
                player: v6,
                range,
                priority: PRIORITY_HIGH,
                isHostile: true,
                isFootstep: false,
                actualOrigin: nullptr);
              break;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B0570
// Name: public: void CCSBot::OnWeaponReload(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::OnWeaponReload(CCSBot *this, IGameEvent *event)
{
  int v3; // eax
  CCSBot *v4; // edi
  int savedregs; // [esp+28h] [ebp+0h] BYREF

  if ( this->IsAlive(this) )
  {
    v3 = event->GetInt(this: event, a2: "userid", a3: 0);
    v4 = (CCSBot *)UTIL_PlayerByUserId(userID: v3);
    if ( v4 != this )
    {
      if ( this->GetEnemy_2(this) == v4 && CCSBot::IsUsingKnife(this) )
        CCSBot::ForceRun(this, duration: 5.0);
      CCSBot::OnAudibleEvent(
        this,
        a2: COERCE_FLOAT(&savedregs),
        event,
        player: v4,
        range: 1100.0,
        priority: PRIORITY_LOW,
        isHostile: false,
        isFootstep: false,
        actualOrigin: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B0600
// Name: __CreateCServerGameTagsIServerGameTags_interface_19
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CServerGameTags *__cdecl _CreateCServerGameTagsIServerGameTags_interface_19()
{
  return &_g_CServerGameTags_singleton_19;
}
