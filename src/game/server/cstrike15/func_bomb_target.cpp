// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/cstrike15/func_bomb_target.cpp
// Functions: 10
// ============================================================

#include "game\server\cstrike15\func_bomb_target.h"

//------------------------------------------------------------------------------
// Address: 0x1029B4E0
// Name: public: virtual struct datamap_t __near * CBombTarget::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CBombTarget::GetDataDescMap(CBombTarget *this)
{
  return &CBombTarget::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1029B4F0
// Name: public: void CBombTarget::BombTargetUse(class CBaseEntity __near *,class CBaseEntity __near *,enum USE_TYPE,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBombTarget::BombTargetUse(
        CBombTarget *this,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller,
        CBaseEntity *useType,
        float value)
{
  _DevMsg(a1: 2, a2: "BombTargetUse does nothing\n");
}

//------------------------------------------------------------------------------
// Address: 0x1029B510
// Name: public: void CBombTarget::OnBombExplode(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBombTarget::OnBombExplode(CBombTarget *this, inputdata_t *inputdata)
{
  COutputEvent::FireOutput(this: &this->m_OnBombExplode, pActivator: this, pCaller: this, fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x1029B530
// Name: public: void CBombTarget::OnBombPlanted(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBombTarget::OnBombPlanted(CBombTarget *this, inputdata_t *inputdata)
{
  COutputEvent::FireOutput(this: &this->m_OnBombPlanted, pActivator: this, pCaller: this, fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x1029B550
// Name: public: void CBombTarget::OnBombDefused(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBombTarget::OnBombDefused(CBombTarget *this, inputdata_t *inputdata)
{
  COutputEvent::FireOutput(this: &this->m_OnBombDefused, pActivator: this, pCaller: this, fDelay: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x1029B580
// Name: public: void CBombTarget::BombTargetTouch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBombTarget::BombTargetTouch(CBombTarget *this, CBaseEntity *pOther)
{
  CCSPlayer *v2; // eax
  CCSPlayer *v3; // esi
  CBaseEdict *v4; // ecx
  edict_t *m_pPev; // eax

  v2 = (CCSPlayer *)__RTDynamicCast(
                      inptr: pOther,
                      VfDelta: 0,
                      SrcType: &CBaseEntity `RTTI Type Descriptor',
                      TargetType: &CCSPlayer `RTTI Type Descriptor',
                      isReference: 0);
  v3 = v2;
  if ( v2 != nullptr )
  {
    v2->m_bInBombZoneTrigger = true;
    if ( CCSPlayer::HasC4(this: v2) && LOBYTE(g_pGameRules[144].m_pNext) == 0 )
    {
      if ( !v3->m_bInBombZone.m_Value )
      {
        if ( v3->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&v3->m_Network + 76) |= 1u;
        }
        else
        {
          v4 = &v3->m_Network.m_pPev->CBaseEdict;
          if ( v4 != nullptr )
            CBaseEdict::StateChanged(this: v4, offset: 0x1770u);
        }
        v3->m_bInBombZone.m_Value = true;
      }
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        m_pPev -= (int)gpGlobals->pEdicts;
      v3->m_iBombSiteIndex = (int)m_pPev;
      if ( (v3->m_iDisplayHistoryBits & 0x10000) == 0 )
      {
        CCSPlayer::HintMessage(
          this: v3,
          pMessage: "#Hint_you_are_in_targetzone",
          bDisplayIfDead: false,
          bOverrideClientSettings: false);
        v3->m_iDisplayHistoryBits |= 0x10000u;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1029B650
// Name: public: CBombTarget::CBombTarget(void)
// Source: json
//------------------------------------------------------------------------------
CBombTarget *__thiscall CBombTarget::CBombTarget(CBombTarget *this)
{
  CBaseTrigger::CBaseTrigger(this);
  this->__vftable = (CBombTarget_vtbl *)&CBombTarget::`vftable';
  this->m_OnBombExplode.m_Value.iVal = 0;
  this->m_OnBombExplode.m_Value.eVal.m_Index = -1;
  this->m_OnBombExplode.m_Value.fieldType = FIELD_VOID;
  this->m_OnBombPlanted.m_Value.iVal = 0;
  this->m_OnBombPlanted.m_Value.eVal.m_Index = -1;
  this->m_OnBombPlanted.m_Value.fieldType = FIELD_VOID;
  this->m_OnBombDefused.m_Value.iVal = 0;
  this->m_OnBombDefused.m_Value.eVal.m_Index = -1;
  this->m_OnBombDefused.m_Value.fieldType = FIELD_VOID;
  this->m_bIsHeistBombTarget = false;
  this->m_szMountTarget.pszValue = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1029B6B0
// Name: public: virtual void CBombTarget::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBombTarget::Spawn(CBombTarget *this)
{
  CBaseTrigger::InitTrigger(this);
  this->m_pfnTouch = (void (__thiscall *)(CBaseEntity *, CBaseEntity *))CBombTarget::BombTargetTouch;
  this->m_pfnUse = (void (__thiscall *)(CBaseEntity *, CBaseEntity *, CBaseEntity *, USE_TYPE, float))CBombTarget::BombTargetUse;
  VisibilityMonitor_AddEntity(pEntity: this, flMinDist: 400.0, pfnCallback: nullptr, pfnEvaluator: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1040F690
// Name: CBombTarget_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CBombTarget_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CBombTarget>(__formal: nullptr);
  CBombTarget_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029B6F0
// Name: struct datamap_t __near * DataMapInit<class CBombTarget>(class CBombTarget __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CBombTarget>()
{
  char *Name; // eax

  if ( (_S2_250 & 1) == 0 )
  {
    _S2_250 |= 1u;
    nameHolder_479.m_pszBase = "CBombTarget";
    nameHolder_479.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_479.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_479.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_479.m_Names.m_Size = 0;
    nameHolder_479.m_Names.m_pElements = nullptr;
    nameHolder_479.m_nLenBase = 11;
    atexit(func: DataMapInit_CBombTarget__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CBombTarget::m_DataMap.baseMap = &CBaseTrigger::m_DataMap;
  if ( (_S2_250 & 2) == 0 )
  {
    _S2_250 |= 2u;
    dataDesc_500[1].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_479,
                                  pszIdentifier: "BombTargetTouch");
    dataDesc_500[1].flags = 32;
    dataDesc_500[1].fieldOffset = 0;
    dataDesc_500[1].fieldSize = 1;
    dataDesc_500[1].externalName = nullptr;
    dataDesc_500[1].pSaveRestoreOps = nullptr;
    dataDesc_500[1].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CBombTarget::BombTargetTouch;
    *(_QWORD *)&dataDesc_500[1].td = 0;
    *(_QWORD *)&dataDesc_500[1].override_field = 0;
    *(_QWORD *)&dataDesc_500[1].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_500[1].flatOffset[1] = 0;
    dataDesc_500[2].fieldType = FIELD_VOID;
    Name = CDatadescGeneratedNameHolder::GenerateName(this: &nameHolder_479, pszIdentifier: "BombTargetUse");
    *(_QWORD *)&dataDesc_500[2].td = 0;
    *(_QWORD *)&dataDesc_500[2].override_field = 0;
    *(_QWORD *)&dataDesc_500[2].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_500[2].flatOffset[1] = 0;
    dataDesc_500[2].fieldName = Name;
    dataDesc_500[2].fieldSize = 1;
    *(_QWORD *)&dataDesc_500[3].td = 0;
    *(_QWORD *)&dataDesc_500[3].override_field = 0;
    *(_QWORD *)&dataDesc_500[3].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_500[3].flatOffset[1] = 0;
    dataDesc_500[2].flags = 32;
    dataDesc_500[3].fieldSize = 1;
    dataDesc_500[3].flags = 8;
    dataDesc_500[4].fieldSize = 1;
    dataDesc_500[4].flags = 8;
    *(_QWORD *)&dataDesc_500[4].td = 0;
    *(_QWORD *)&dataDesc_500[4].override_field = 0;
    *(_QWORD *)&dataDesc_500[4].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_500[4].flatOffset[1] = 0;
    dataDesc_500[2].fieldOffset = 0;
    dataDesc_500[2].externalName = nullptr;
    dataDesc_500[2].pSaveRestoreOps = nullptr;
    dataDesc_500[2].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CBombTarget::BombTargetUse;
    dataDesc_500[3].fieldType = FIELD_VOID;
    dataDesc_500[3].fieldName = "OnBombExplode";
    dataDesc_500[3].fieldOffset = 0;
    dataDesc_500[3].externalName = "BombExplode";
    dataDesc_500[3].pSaveRestoreOps = nullptr;
    dataDesc_500[3].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CBombTarget::OnBombExplode;
    dataDesc_500[4].fieldType = FIELD_VOID;
    dataDesc_500[4].fieldName = "OnBombPlanted";
    dataDesc_500[4].fieldOffset = 0;
    dataDesc_500[4].externalName = "BombPlanted";
    dataDesc_500[4].pSaveRestoreOps = nullptr;
    dataDesc_500[4].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CBombTarget::OnBombPlanted;
    dataDesc_500[5].fieldType = FIELD_VOID;
    dataDesc_500[5].fieldName = "OnBombDefused";
    dataDesc_500[5].fieldOffset = 0;
    *(_DWORD *)&dataDesc_500[5].fieldSize = 524289;
    dataDesc_500[5].externalName = "BombDefused";
    dataDesc_500[5].pSaveRestoreOps = nullptr;
    dataDesc_500[5].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CBombTarget::OnBombDefused;
    *(_QWORD *)&dataDesc_500[5].td = 0;
    *(_QWORD *)&dataDesc_500[5].override_field = 0;
    *(_QWORD *)&dataDesc_500[5].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_500[5].flatOffset[1] = 0;
    dataDesc_500[6].fieldType = FIELD_CUSTOM;
    dataDesc_500[6].fieldName = "m_OnBombExplode";
    *(_QWORD *)&dataDesc_500[6].inputFunc = 0;
    *(_QWORD *)&dataDesc_500[6].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_500[6].override_count = 0;
    *(_QWORD *)dataDesc_500[6].flatOffset = 0;
    dataDesc_500[6].fieldSize = 1;
    *(_QWORD *)&dataDesc_500[7].inputFunc = 0;
    *(_QWORD *)&dataDesc_500[7].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_500[7].override_count = 0;
    *(_QWORD *)dataDesc_500[7].flatOffset = 0;
    *(_QWORD *)&dataDesc_500[8].inputFunc = 0;
    *(_QWORD *)&dataDesc_500[8].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_500[8].override_count = 0;
    *(_QWORD *)dataDesc_500[8].flatOffset = 0;
    dataDesc_500[6].flags = 22;
    dataDesc_500[7].externalName = "BombPlanted";
    dataDesc_500[7].fieldSize = 1;
    dataDesc_500[6].externalName = "BombExplode";
    dataDesc_500[8].fieldSize = 1;
    dataDesc_500[9].fieldTolerance = 0.0;
    dataDesc_500[10].fieldTolerance = 0.0;
    dataDesc_500[6].fieldOffset = 1152;
    dataDesc_500[6].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_500[6].flatGroup = 0;
    dataDesc_500[7].fieldType = FIELD_CUSTOM;
    dataDesc_500[7].fieldName = "m_OnBombPlanted";
    dataDesc_500[7].fieldOffset = 1176;
    dataDesc_500[7].flags = 22;
    dataDesc_500[7].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_500[7].flatGroup = 0;
    dataDesc_500[8].fieldType = FIELD_CUSTOM;
    dataDesc_500[8].fieldName = "m_OnBombDefused";
    dataDesc_500[8].fieldOffset = 1200;
    dataDesc_500[8].flags = 22;
    dataDesc_500[8].externalName = "BombDefused";
    dataDesc_500[8].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_500[8].flatGroup = 0;
    dataDesc_500[9].fieldType = FIELD_BOOLEAN;
    dataDesc_500[9].fieldName = "m_bIsHeistBombTarget";
    dataDesc_500[9].fieldOffset = 1224;
    *(_DWORD *)&dataDesc_500[9].fieldSize = 393217;
    dataDesc_500[9].externalName = "heistbomb";
    dataDesc_500[9].pSaveRestoreOps = nullptr;
    dataDesc_500[9].inputFunc = nullptr;
    dataDesc_500[9].td = nullptr;
    dataDesc_500[9].fieldSizeInBytes = 1;
    dataDesc_500[9].override_field = nullptr;
    dataDesc_500[9].override_count = 0;
    *(_QWORD *)dataDesc_500[9].flatOffset = 0;
    *(_DWORD *)&dataDesc_500[9].flatGroup = 0;
    dataDesc_500[10].fieldType = FIELD_STRING;
    dataDesc_500[10].fieldName = "m_szMountTarget";
    dataDesc_500[10].fieldOffset = 1228;
    *(_DWORD *)&dataDesc_500[10].fieldSize = 393217;
    dataDesc_500[10].externalName = "bomb_mount_target";
    dataDesc_500[10].pSaveRestoreOps = nullptr;
    dataDesc_500[10].inputFunc = nullptr;
    dataDesc_500[10].td = nullptr;
    dataDesc_500[10].fieldSizeInBytes = 4;
    dataDesc_500[10].override_field = nullptr;
    dataDesc_500[10].override_count = 0;
    *(_QWORD *)dataDesc_500[10].flatOffset = 0;
    *(_DWORD *)&dataDesc_500[10].flatGroup = 0;
  }
  CBombTarget::m_DataMap.dataNumFields = 10;
  CBombTarget::m_DataMap.dataDesc = &dataDesc_500[1];
  return &CBombTarget::m_DataMap;
}
