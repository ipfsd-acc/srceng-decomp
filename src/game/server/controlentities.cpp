// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/controlentities.cpp
// Functions: 8
// ============================================================

#include "game\server\controlentities.h"

//------------------------------------------------------------------------------
// Address: 0x100F9980
// Name: public: virtual struct datamap_t __near * CTargetCDAudioRep::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CTargetCDAudioRep::GetDataDescMap(CTargetCDAudioRep *this)
{
  return &CTargetCDAudioRep::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100F9990
// Name: public: virtual struct datamap_t __near * CTargetChangeGravity::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CTargetChangeGravity::GetDataDescMap(CTargetChangeGravity *this)
{
  return &CTargetChangeGravity::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100F99A0
// Name: public: void CTargetChangeGravity::InputChangeGrav(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTargetChangeGravity::InputChangeGrav(CTargetChangeGravity *this, inputdata_t *inputdata)
{
  CBaseEntity *pActivator; // esi

  pActivator = inputdata->pActivator;
  if ( inputdata->pActivator != nullptr && pActivator->IsPlayer(this: inputdata->pActivator) )
  {
    if ( this->m_iOldGrav != 0 )
      this->m_iOldGrav = (int)pActivator->m_flGravity;
    pActivator->m_flGravity = (float)this->m_iGravity;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F99F0
// Name: public: void CTargetChangeGravity::InputResetGrav(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTargetChangeGravity::InputResetGrav(CTargetChangeGravity *this, inputdata_t *inputdata)
{
  CBaseEntity *pActivator; // esi

  pActivator = inputdata->pActivator;
  if ( inputdata->pActivator != nullptr && pActivator->IsPlayer(this: inputdata->pActivator) )
    pActivator->m_flGravity = (float)this->m_iOldGrav;
}

//------------------------------------------------------------------------------
// Address: 0x100F9A30
// Name: public: void CTargetCDAudioRep::InputChangeCDTrack(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTargetCDAudioRep::InputChangeCDTrack(CTargetCDAudioRep *this, inputdata_t *inputdata)
{
  int m_iTrack; // edi
  edict_t *pEdicts; // eax
  edict_t *v4; // esi
  void *v5; // eax
  char string[64]; // [esp+8h] [ebp-40h] BYREF

  m_iTrack = this->m_iTrack;
  if ( gpGlobals->maxClients == 1 )
  {
    if ( gpGlobals->pEdicts == nullptr )
      return;
    pEdicts = gpGlobals->pEdicts;
    if ( (pEdicts[1].m_fStateFlags & 2) != 0 )
      return;
    v4 = pEdicts + 1;
  }
  else
  {
    v5 = __RTDynamicCast(
           inptr: inputdata->pActivator,
           VfDelta: 0,
           SrcType: &CBaseEntity `RTTI Type Descriptor',
           TargetType: &CBasePlayer `RTTI Type Descriptor',
           isReference: 0);
    if ( v5 == nullptr )
      return;
    v4 = *((edict_t **)v5 + 6);
  }
  if ( v4 != nullptr )
  {
    if ( (unsigned int)(m_iTrack + 1) > 0x1F )
    {
      _Warning(a1: "TargetCDAudio - Track %d out of range\n", m_iTrack);
    }
    else if ( m_iTrack == -1 )
    {
      engine->ClientCommand(this: engine, a2: v4, a3: "cd pause\n");
    }
    else
    {
      V_snprintf(pDest: string, maxLen: 64, pFormat: "cd play %3d\n", m_iTrack);
      engine->ClientCommand(this: engine, a2: v4, a3: string);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10401740
// Name: CTargetCDAudioRep_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CTargetCDAudioRep_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CTargetCDAudioRep>();
  CTargetCDAudioRep_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10401770
// Name: CTargetChangeGravity_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CTargetChangeGravity_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CTargetChangeGravity>();
  CTargetChangeGravity_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10401780
// Name: _dynamic_initializer_for__ai_debug_ragdoll_magnets__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_debug_ragdoll_magnets__()
{
  ConVar::ConVar(this: &ai_debug_ragdoll_magnets, pName: "ai_debug_ragdoll_magnets", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ai_debug_ragdoll_magnets__);
}
