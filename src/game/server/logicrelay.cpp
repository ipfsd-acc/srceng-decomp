// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/logicrelay.cpp
// Functions: 11
// ============================================================

#include "game\server\logicrelay.h"

//------------------------------------------------------------------------------
// Address: 0x1016E9D0
// Name: public: virtual struct datamap_t __near * CLogicRelay::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CLogicRelay::GetDataDescMap(CLogicRelay *this)
{
  return &CLogicRelay::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1016E9E0
// Name: public: virtual void CLogicRelay::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicRelay::Activate(CLogicRelay *this)
{
  CBaseEntity::Activate(this);
  if ( CBaseEntityOutput::NumberOfElements(this: &this->m_OnSpawn) > 0 )
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.01, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1016EA30
// Name: public: void CLogicRelay::InputEnable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicRelay::InputEnable(CLogicRelay *this, inputdata_t *inputdata)
{
  this->m_bDisabled = false;
}

//------------------------------------------------------------------------------
// Address: 0x1016EA40
// Name: public: void CLogicRelay::InputEnableRefire(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicRelay::InputEnableRefire(CLogicRelay *this, inputdata_t *inputdata)
{
  this->m_bWaitForRefire = false;
}

//------------------------------------------------------------------------------
// Address: 0x1016EA50
// Name: public: void CLogicRelay::InputCancelPending(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicRelay::InputCancelPending(CLogicRelay *this, inputdata_t *inputdata)
{
  CEventQueue::CancelEvents(this: &g_EventQueue, pCaller: this);
  this->m_bWaitForRefire = false;
}

//------------------------------------------------------------------------------
// Address: 0x1016EA70
// Name: public: void CLogicRelay::InputDisable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicRelay::InputDisable(CLogicRelay *this, inputdata_t *inputdata)
{
  this->m_bDisabled = true;
}

//------------------------------------------------------------------------------
// Address: 0x1016EA80
// Name: public: void CLogicRelay::InputToggle(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicRelay::InputToggle(CLogicRelay *this, inputdata_t *inputdata)
{
  this->m_bDisabled = !this->m_bDisabled;
}

//------------------------------------------------------------------------------
// Address: 0x1016EAA0
// Name: public: virtual void CLogicRelay::Think(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicRelay::Think(CLogicRelay *this)
{
  COutputEvent::FireOutput(this: &this->m_OnSpawn, pActivator: this, pCaller: this, fDelay: 0.0);
  if ( (this->m_spawnflags.m_Value & 1) != 0 )
    UTIL_Remove(oldObj: this);
}

//------------------------------------------------------------------------------
// Address: 0x1016EAD0
// Name: public: void CLogicRelay::InputTrigger(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicRelay::InputTrigger(CLogicRelay *this, inputdata_t *inputdata)
{
  int m_Value; // eax
  const char *DebugName; // eax
  float fireDelay; // [esp+0h] [ebp-18h]

  if ( !this->m_bDisabled )
  {
    if ( this->m_bWaitForRefire )
    {
      _Warning(a1: "*************************************************************************************************\n");
      DebugName = CBaseEntity::GetDebugName(this);
      _Warning(
        a1: "*** ERROR: logic_relay %s has been triggered but is awaiting refire. OUTPUTS WILL NOT BE FIRED!!!\n",
        DebugName);
      _Warning(a1: "*************************************************************************************************\n\n");
    }
    else
    {
      COutputEvent::FireOutput(this: &this->m_OnTrigger, pActivator: inputdata->pActivator, pCaller: this, fDelay: 0.0);
      m_Value = this->m_spawnflags.m_Value;
      if ( (m_Value & 1) != 0 )
      {
        UTIL_Remove(oldObj: this);
      }
      else if ( (m_Value & 2) == 0 )
      {
        this->m_bWaitForRefire = true;
        fireDelay = CBaseEntityOutput::GetMaxDelay(this: &this->m_OnTrigger) + 0.001;
        CEventQueue::AddEvent(
          this: &g_EventQueue,
          target: this,
          action: "EnableRefire",
          fireDelay,
          pActivator: this,
          pCaller: this,
          outputID: 0);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10405BA0
// Name: CLogicRelay_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CLogicRelay_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CLogicRelay>();
  CLogicRelay_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1016EBD0
// Name: class CLogicRelay __near * _CreateEntityTemplate<class CLogicRelay>(class CLogicRelay __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CLogicRelay *__cdecl _CreateEntityTemplate<CLogicRelay>(CLogicRelay *newEnt, const char *className)
{
  CBaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x388u);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: true);
    *v3 = &CLogicRelay::`vftable';
    v3[213] = 0;
    v3[216] = -1;
    v3[217] = 0;
    v3[219] = 0;
    v3[222] = -1;
    v3[223] = 0;
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CLogicRelay *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}
