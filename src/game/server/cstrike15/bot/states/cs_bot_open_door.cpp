// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/cstrike15/bot/states/cs_bot_open_door.cpp
// Functions: 5
// ============================================================

#include "game\server\cstrike15\bot\states\cs_bot_open_door.h"

//------------------------------------------------------------------------------
// Address: 0x102D82C0
// Name: public: void OpenDoorState::SetDoor(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OpenDoorState::SetDoor(OpenDoorState *this, CBaseEntity *door)
{
  void *v3; // eax
  void *v4; // eax

  v3 = __RTDynamicCast(
         inptr: door,
         VfDelta: 0,
         SrcType: &CBaseEntity `RTTI Type Descriptor',
         TargetType: &CBaseDoor `RTTI Type Descriptor',
         isReference: 0);
  if ( v3 != nullptr )
  {
    this->m_funcDoor.m_Index = *(_DWORD *)(*(int (__thiscall **)(void *))(*(_DWORD *)v3 + 8))(a1: v3);
  }
  else
  {
    v4 = __RTDynamicCast(
           inptr: door,
           VfDelta: 0,
           SrcType: &CBaseEntity `RTTI Type Descriptor',
           TargetType: &CBasePropDoor `RTTI Type Descriptor',
           isReference: 0);
    if ( v4 != nullptr )
      this->m_propDoor.m_Index = *(_DWORD *)(*(int (__thiscall **)(void *))(*(_DWORD *)v4 + 8))(a1: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D8330
// Name: public: virtual void OpenDoorState::OnUpdate(class CCSBot __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OpenDoorState::OnUpdate(OpenDoorState *this, CCSBot *me)
{
  unsigned int m_Index; // ecx
  int v4; // eax
  CEntInfo *v5; // edx
  unsigned int v6; // ecx
  int v7; // eax
  bool v8; // zf
  CEntInfo *v9; // eax
  IHandleEntity *m_pEntity; // ecx
  unsigned int v11; // eax
  Vector pos; // [esp+1Ch] [ebp-Ch] BYREF

  CCSBot::ResetStuckMonitor(this: me);
  if ( IntervalTimer::Now(this: (CEffectsServer *)&this->m_timeout) <= this->m_timeout.m_timestamp.m_Value )
  {
    m_Index = this->m_funcDoor.m_Index;
    if ( m_Index != -1
      && (v4 = (unsigned __int16)m_Index,
          v5 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
          v6 = HIWORD(m_Index),
          v5->m_SerialNumber == v6)
      && v5->m_pEntity != nullptr )
    {
      v7 = v4;
      v8 = g_pEntityList->m_EntPtrArray[v7].m_SerialNumber == v6;
      v9 = &g_pEntityList->m_EntPtrArray[v7];
      if ( v8 )
        m_pEntity = v9->m_pEntity;
      else
        m_pEntity = nullptr;
    }
    else
    {
      v11 = this->m_propDoor.m_Index;
      if ( v11 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_SerialNumber != HIWORD(v11) )
        m_pEntity = nullptr;
      else
        m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_pEntity;
    }
    pos = *(Vector *)((int (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[49].dtr_IHandleEntity)(a1: m_pEntity);
    CCSBot::SetLookAt(
      this: me,
      desc: "Open door",
      &pos,
      pri: PRIORITY_HIGH,
      duration: -1.0,
      clearIfClose: false,
      angleTolerance: 5.0,
      attack: false);
    if ( CBot<CCSPlayer>::IsLookingAtPosition(this: me, &pos, angleTolerance: 20.0) )
      me->UseEnvironment(this: me);
  }
  else
  {
    this->m_isDone = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D84B0
// Name: public: virtual void OpenDoorState::OnEnter(class CCSBot __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OpenDoorState::OnEnter(OpenDoorState *this, CCSBot *me)
{
  CountdownTimer *p_m_timeout; // edi
  double v3; // st7
  float v4; // [esp+8h] [ebp-4h]

  p_m_timeout = &this->m_timeout;
  this->m_isDone = false;
  v3 = IntervalTimer::Now(this: (CEffectsServer *)&this->m_timeout) + 1.0;
  if ( p_m_timeout->m_timestamp.m_Value != v3 )
  {
    p_m_timeout->NetworkStateChanged(this: p_m_timeout, a2: &p_m_timeout->m_timestamp);
    v4 = v3;
    p_m_timeout->m_timestamp.m_Value = v4;
  }
  if ( p_m_timeout->m_duration.m_Value != 1.0 )
  {
    p_m_timeout->NetworkStateChanged(this: p_m_timeout, a2: &p_m_timeout->m_duration);
    p_m_timeout->m_duration.m_Value = 1.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D8760
// Name: public: virtual void OpenDoorState::OnExit(class CCSBot __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall OpenDoorState::OnExit(OpenDoorState *this, CCSBot *me)
{
  me->m_lookAtSpotState = NOT_LOOKING_AT_SPOT;
  me->m_lookAtDesc = nullptr;
  CCSBot::ResetStuckMonitor(this: me);
}

//------------------------------------------------------------------------------
// Address: 0x102D8530
// Name: __CreateCServerGameTagsIServerGameTags_interface_49
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CServerGameTags *__cdecl _CreateCServerGameTagsIServerGameTags_interface_49()
{
  return &_g_CServerGameTags_singleton_49;
}
