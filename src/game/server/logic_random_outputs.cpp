// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/logic_random_outputs.cpp
// Functions: 12
// ============================================================

#include "game\server\logic_random_outputs.h"

//------------------------------------------------------------------------------
// Address: 0x10166F90
// Name: public: virtual struct datamap_t __near * CLogicRandomOutputs::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CLogicRandomOutputs::GetDataDescMap(CLogicRandomOutputs *this)
{
  return &CLogicRandomOutputs::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10166FA0
// Name: public: virtual void CLogicRandomOutputs::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicRandomOutputs::Activate(CLogicRandomOutputs *this)
{
  CBaseEntity::Activate(this);
  if ( CBaseEntityOutput::NumberOfElements(this: &this->m_OnSpawn) > 0 )
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.01, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10166FF0
// Name: public: void CLogicRandomOutputs::InputEnable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicRandomOutputs::InputEnable(CLogicRandomOutputs *this, inputdata_t *inputdata)
{
  this->m_bDisabled = false;
}

//------------------------------------------------------------------------------
// Address: 0x10167000
// Name: public: void CLogicRandomOutputs::InputEnableRefire(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicRandomOutputs::InputEnableRefire(CLogicRandomOutputs *this, inputdata_t *inputdata)
{
  _Msg(a1: " now enabling refire\n");
  this->m_bWaitForRefire = false;
}

//------------------------------------------------------------------------------
// Address: 0x10167020
// Name: public: void CLogicRandomOutputs::InputCancelPending(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicRandomOutputs::InputCancelPending(CLogicRandomOutputs *this, inputdata_t *inputdata)
{
  CEventQueue::CancelEvents(this: &g_EventQueue, pCaller: this);
  this->m_bWaitForRefire = false;
}

//------------------------------------------------------------------------------
// Address: 0x10167040
// Name: public: void CLogicRandomOutputs::InputDisable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicRandomOutputs::InputDisable(CLogicRandomOutputs *this, inputdata_t *inputdata)
{
  this->m_bDisabled = true;
}

//------------------------------------------------------------------------------
// Address: 0x10167050
// Name: public: void CLogicRandomOutputs::InputToggle(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicRandomOutputs::InputToggle(CLogicRandomOutputs *this, inputdata_t *inputdata)
{
  this->m_bDisabled = !this->m_bDisabled;
}

//------------------------------------------------------------------------------
// Address: 0x10167070
// Name: public: virtual bool CLogicRandomOutputs::KeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CLogicRandomOutputs::KeyValue(CLogicRandomOutputs *this, const char *szKeyName, const char *szValue)
{
  int v3; // esi
  const char *v4; // eax

  if ( szValue == nullptr || *szValue == 0 )
    return CServerOnlyPointEntity::KeyValue(this, szKeyName, szValue);
  v3 = 0;
  while ( 1 )
  {
    v4 = UTIL_VarArgs(format: "OnTriggerChance%d", v3);
    if ( szKeyName == v4 || _V_stricmp(s1: szKeyName, s2: v4) == 0 )
      break;
    if ( ++v3 >= 8 )
      return CServerOnlyPointEntity::KeyValue(this, szKeyName, szValue);
  }
  this->m_flOnTriggerChance[v3] = atof(nptr: szValue);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101670F0
// Name: public: virtual void CLogicRandomOutputs::Think(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicRandomOutputs::Think(CLogicRandomOutputs *this)
{
  COutputEvent::FireOutput(this: &this->m_OnSpawn, pActivator: this, pCaller: this, fDelay: 0.0);
  if ( (this->m_spawnflags.m_Value & 1) != 0 )
    UTIL_Remove(oldObj: this);
}

//------------------------------------------------------------------------------
// Address: 0x10167120
// Name: public: void CLogicRandomOutputs::InputTrigger(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLogicRandomOutputs::InputTrigger(CLogicRandomOutputs *this, inputdata_t *inputdata)
{
  COutputEvent *m_Output; // edi
  float *m_flOnTriggerChance; // ebx
  int m_Value; // eax
  COutputEvent *v6; // edi
  int j; // ebx
  int i; // [esp+14h] [ebp-4h]
  float fMaxDelay; // [esp+20h] [ebp+8h]

  if ( !this->m_bDisabled && !this->m_bWaitForRefire )
  {
    m_Output = this->m_Output;
    m_flOnTriggerChance = this->m_flOnTriggerChance;
    for ( i = 8; i != 0; --i )
    {
      if ( (double)*m_flOnTriggerChance >= _RandomFloat((IUniformRandomStream *)this, a2: 0.0, a3: 1.0) )
        COutputEvent::FireOutput(this: m_Output, pActivator: inputdata->pActivator, pCaller: this, fDelay: 0.0);
      ++m_flOnTriggerChance;
      ++m_Output;
    }
    m_Value = this->m_spawnflags.m_Value;
    if ( (m_Value & 1) != 0 )
    {
      UTIL_Remove(oldObj: this);
    }
    else if ( (m_Value & 2) == 0 )
    {
      fMaxDelay = 0.0;
      v6 = this->m_Output;
      for ( j = 8; j != 0; --j )
      {
        if ( fMaxDelay <= CBaseEntityOutput::GetMaxDelay(this: v6) )
          fMaxDelay = CBaseEntityOutput::GetMaxDelay(this: v6);
        ++v6;
      }
      if ( fMaxDelay > 0.0 )
      {
        this->m_bWaitForRefire = true;
        CEventQueue::AddEvent(
          this: &g_EventQueue,
          target: this,
          action: "EnableRefire",
          fireDelay: fMaxDelay + 0.001,
          pActivator: this,
          pCaller: this,
          outputID: 0);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10167250
// Name: public: CLogicRandomOutputs::CLogicRandomOutputs(void)
// Source: json
//------------------------------------------------------------------------------
CLogicRandomOutputs *__thiscall CLogicRandomOutputs::CLogicRandomOutputs(CLogicRandomOutputs *this)
{
  CBaseEntity::CBaseEntity(this, bServerOnly: true);
  this->__vftable = (CLogicRandomOutputs_vtbl *)&CLogicRandomOutputs::`vftable';
  this->m_Output[0].m_Value.iVal = 0;
  this->m_Output[0].m_Value.eVal.m_Index = -1;
  this->m_Output[0].m_Value.fieldType = FIELD_VOID;
  this->m_Output[1].m_Value.iVal = 0;
  this->m_Output[1].m_Value.eVal.m_Index = -1;
  this->m_Output[1].m_Value.fieldType = FIELD_VOID;
  this->m_Output[2].m_Value.iVal = 0;
  this->m_Output[2].m_Value.eVal.m_Index = -1;
  this->m_Output[2].m_Value.fieldType = FIELD_VOID;
  this->m_Output[3].m_Value.iVal = 0;
  this->m_Output[3].m_Value.eVal.m_Index = -1;
  this->m_Output[3].m_Value.fieldType = FIELD_VOID;
  this->m_Output[4].m_Value.iVal = 0;
  this->m_Output[4].m_Value.eVal.m_Index = -1;
  this->m_Output[4].m_Value.fieldType = FIELD_VOID;
  this->m_Output[5].m_Value.iVal = 0;
  this->m_Output[5].m_Value.eVal.m_Index = -1;
  this->m_Output[5].m_Value.fieldType = FIELD_VOID;
  this->m_Output[6].m_Value.iVal = 0;
  this->m_Output[6].m_Value.eVal.m_Index = -1;
  this->m_Output[6].m_Value.fieldType = FIELD_VOID;
  this->m_Output[7].m_Value.iVal = 0;
  this->m_Output[7].m_Value.eVal.m_Index = -1;
  this->m_Output[7].m_Value.fieldType = FIELD_VOID;
  this->m_OnSpawn.m_Value.iVal = 0;
  this->m_OnSpawn.m_Value.eVal.m_Index = -1;
  this->m_OnSpawn.m_Value.fieldType = FIELD_VOID;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104057C0
// Name: CLogicRandomOutputs_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CLogicRandomOutputs_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CLogicRandomOutputs>();
  CLogicRandomOutputs_DataDescInit::g_DataMapHolder = result;
  return result;
}
