// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/spatialentity.cpp
// Functions: 19
// ============================================================

#include "game\server\spatialentity.h"

//------------------------------------------------------------------------------
// Address: 0x10169670
// Name: public: void CSpatialEntity::InputSetFadeOutDuration(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpatialEntity::InputSetFadeOutDuration(CLogicCompare *this, inputdata_t *inputdata)
{
  if ( inputdata->value.fieldType == FIELD_FLOAT )
    LODWORD(this->m_flCompareValue) = inputdata->value.iVal;
  else
    this->m_flCompareValue = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10221C30
// Name: public: virtual struct datamap_t __near * CSpatialEntity::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CSpatialEntity::GetDataDescMap(CSpatialEntity *this)
{
  return &CSpatialEntity::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10221C40
// Name: public: virtual class ServerClass __near * CSpatialEntity::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CSpatialEntity::GetServerClass(CSpatialEntity *this)
{
  return &g_CSpatialEntity_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x10221DD0
// Name: private: void CSpatialEntity::FadeInThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpatialEntity::FadeInThink(CSpatialEntity *this)
{
  float v2; // xmm2_4
  float m_flMaxWeight; // xmm3_4
  float m_flStartFadeInWeight; // xmm0_4
  float *p_m_flStartFadeInWeight; // esi
  float v6; // xmm0_4
  edict_t *m_pPev; // ecx
  float v8; // [esp+14h] [ebp-14h]
  float flTimeToFade; // [esp+18h] [ebp-10h] BYREF
  float flWeightRatio; // [esp+1Ch] [ebp-Ch] BYREF
  float minVal; // [esp+20h] [ebp-8h] BYREF
  float flFadeRatio; // [esp+24h] [ebp-4h] BYREF

  flTimeToFade = this->m_flFadeInDuration;
  v2 = flTimeToFade;
  if ( flTimeToFade <= 0.0
    || (m_flMaxWeight = this->m_flMaxWeight, this->m_flCurWeight.m_Value >= m_flMaxWeight)
    || !this->m_bEnabled.m_Value
    || m_flMaxWeight == 0.0
    || (m_flStartFadeInWeight = this->m_flStartFadeInWeight,
        p_m_flStartFadeInWeight = &this->m_flStartFadeInWeight,
        m_flStartFadeInWeight >= m_flMaxWeight) )
  {
    CBaseEntity::SetNextThink(this, thinkTime: -1.0, szContext: s_pFadeInContextThink_0);
  }
  else
  {
    if ( m_flStartFadeInWeight > 0.0 )
    {
      flWeightRatio = m_flStartFadeInWeight / m_flMaxWeight;
      flFadeRatio = 0.99000001;
      minVal = 0.0;
      flTimeToFade = (1.0 - clamp<float,float,float>(val: &flWeightRatio, &minVal, maxVal: &flFadeRatio)) * flTimeToFade;
      v2 = flTimeToFade;
    }
    flFadeRatio = (float)(gpGlobals->curtime - this->m_flTimeStartFadeIn) / v2;
    flTimeToFade = 1.0;
    flWeightRatio = 0.0;
    flFadeRatio = clamp<float,float,float>(val: &flFadeRatio, minVal: &flWeightRatio, maxVal: &flTimeToFade);
    flTimeToFade = 1.0;
    flWeightRatio = 0.0;
    *p_m_flStartFadeInWeight = clamp<float,float,float>(
                                 val: &this->m_flStartFadeInWeight,
                                 minVal: &flWeightRatio,
                                 maxVal: &flTimeToFade);
    v8 = (float)((float)(m_flMaxWeight - *p_m_flStartFadeInWeight) * flFadeRatio) + *p_m_flStartFadeInWeight;
    v6 = v8;
    if ( this->m_flCurWeight.m_Value != v8 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
        {
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x37Cu);
          v6 = v8;
        }
      }
      this->m_flCurWeight.m_Value = v6;
    }
    CBaseEntity::SetNextThink(
      this,
      thinkTime: gpGlobals->interval_per_tick + gpGlobals->curtime,
      szContext: s_pFadeInContextThink_0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10221FA0
// Name: private: void CSpatialEntity::FadeOutThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpatialEntity::FadeOutThink(CSpatialEntity *this)
{
  float v2; // xmm3_4
  float m_flMaxWeight; // xmm1_4
  float m_flStartFadeOutWeight; // xmm0_4
  float *p_m_flStartFadeOutWeight; // esi
  float v6; // xmm0_4
  float m_Value; // xmm1_4
  edict_t *m_pPev; // ecx
  float flTimeToFade; // [esp+14h] [ebp-10h] BYREF
  float flWeightRatio; // [esp+18h] [ebp-Ch] BYREF
  float minVal; // [esp+1Ch] [ebp-8h] BYREF
  float flFadeRatio; // [esp+20h] [ebp-4h] BYREF

  flTimeToFade = this->m_flFadeOutDuration;
  v2 = flTimeToFade;
  if ( flTimeToFade <= 0.0
    || this->m_flCurWeight.m_Value <= 0.0
    || this->m_bEnabled.m_Value
    || (m_flMaxWeight = this->m_flMaxWeight) == 0.0
    || (m_flStartFadeOutWeight = this->m_flStartFadeOutWeight,
        p_m_flStartFadeOutWeight = &this->m_flStartFadeOutWeight,
        m_flStartFadeOutWeight <= 0.0) )
  {
    CBaseEntity::SetNextThink(this, thinkTime: -1.0, szContext: s_pFadeOutContextThink_0);
  }
  else
  {
    if ( m_flMaxWeight > m_flStartFadeOutWeight )
    {
      flWeightRatio = m_flStartFadeOutWeight / m_flMaxWeight;
      flFadeRatio = 1.0;
      minVal = 0.0099999998;
      flTimeToFade = clamp<float,float,float>(val: &flWeightRatio, &minVal, maxVal: &flFadeRatio) * flTimeToFade;
      v2 = flTimeToFade;
    }
    flFadeRatio = (float)(gpGlobals->curtime - this->m_flTimeStartFadeOut) / v2;
    flTimeToFade = 1.0;
    flWeightRatio = 0.0;
    flFadeRatio = clamp<float,float,float>(val: &flFadeRatio, minVal: &flWeightRatio, maxVal: &flTimeToFade);
    flTimeToFade = 1.0;
    flWeightRatio = 0.0;
    flTimeToFade = clamp<float,float,float>(
                     val: &this->m_flStartFadeOutWeight,
                     minVal: &flWeightRatio,
                     maxVal: &flTimeToFade);
    *p_m_flStartFadeOutWeight = flTimeToFade;
    m_Value = this->m_flCurWeight.m_Value;
    flTimeToFade = (float)(1.0 - flFadeRatio) * flTimeToFade;
    v6 = flTimeToFade;
    if ( m_Value != flTimeToFade )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
        {
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x37Cu);
          v6 = flTimeToFade;
        }
      }
      this->m_flCurWeight.m_Value = v6;
    }
    CBaseEntity::SetNextThink(
      this,
      thinkTime: gpGlobals->interval_per_tick + gpGlobals->curtime,
      szContext: s_pFadeOutContextThink_0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10222170
// Name: public: CSpatialEntity::CSpatialEntity(void)
// Source: json
//------------------------------------------------------------------------------
CSpatialEntity *__thiscall CSpatialEntity::CSpatialEntity(CSpatialEntity *this)
{
  edict_t *m_pPev; // ecx
  edict_t *v3; // ecx
  edict_t *v4; // ecx
  edict_t *v5; // ecx

  CBaseEntity::CBaseEntity(this, bServerOnly: false);
  this->__vftable = (CSpatialEntity_vtbl *)&CSpatialEntity::`vftable';
  if ( !this->m_bEnabled.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x371u);
    }
    this->m_bEnabled.m_Value = true;
  }
  if ( this->m_MinFalloff.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v3 = this->m_Network.m_pPev;
      if ( v3 != nullptr )
        CBaseEdict::StateChanged(this: &v3->CBaseEdict, offset: 0x374u);
    }
    this->m_MinFalloff.m_Value = 0.0;
  }
  if ( this->m_MaxFalloff.m_Value != 1000.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v4 = this->m_Network.m_pPev;
      if ( v4 != nullptr )
        CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0x378u);
    }
    this->m_MaxFalloff.m_Value = 1000.0;
  }
  this->m_flMaxWeight = 1.0;
  if ( this->m_flCurWeight.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v5 = this->m_Network.m_pPev;
      if ( v5 != nullptr )
        CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0x37Cu);
    }
    this->m_flCurWeight.m_Value = 0.0;
  }
  this->m_flFadeInDuration = 0.0;
  this->m_flFadeOutDuration = 0.0;
  this->m_flStartFadeInWeight = 0.0;
  this->m_flStartFadeOutWeight = 0.0;
  this->m_flTimeStartFadeIn = 0.0;
  this->m_flTimeStartFadeOut = 0.0;
  this->m_lookupFilename.pszValue = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102222D0
// Name: public: virtual void CSpatialEntity::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpatialEntity::Spawn(CSpatialEntity *this)
{
  edict_t *v2; // ecx
  edict_t *v3; // ecx
  edict_t *m_pPev; // ecx
  edict_t *v5; // ecx

  this->m_iEFlags |= 0x880u;
  CBaseEntity::DispatchUpdateTransmitState(this);
  this->Precache(this);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CSpatialEntity::FadeInThink,
    thinkTime: -1.0,
    szContext: s_pFadeInContextThink_0);
  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CSpatialEntity::FadeOutThink,
    thinkTime: -1.0,
    szContext: s_pFadeOutContextThink_0);
  if ( !this->m_bStartDisabled )
  {
    if ( !this->m_bEnabled.m_Value )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x371u);
      }
      this->m_bEnabled.m_Value = true;
    }
    if ( this->m_flCurWeight.m_Value != 1.0 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v5 = this->m_Network.m_pPev;
        if ( v5 != nullptr )
          CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0x37Cu);
      }
      this->m_flCurWeight.m_Value = 1.0;
    }
    goto LABEL_26;
  }
  if ( this->m_bEnabled.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v2 = this->m_Network.m_pPev;
      if ( v2 != nullptr )
        CBaseEdict::StateChanged(this: &v2->CBaseEdict, offset: 0x371u);
    }
    this->m_bEnabled.m_Value = false;
  }
  if ( this->m_flCurWeight.m_Value == 0.0 )
  {
LABEL_26:
    CAI_BaseNPC::OnSetSchedule((vgui::Panel *)this);
    return;
  }
  if ( this->m_Network.m_TimerEvent.m_bRegistered )
  {
    *((_BYTE *)&this->m_Network + 76) |= 1u;
    this->m_flCurWeight.m_Value = 0.0;
    CAI_BaseNPC::OnSetSchedule((vgui::Panel *)this);
  }
  else
  {
    v3 = this->m_Network.m_pPev;
    if ( v3 != nullptr )
      CBaseEdict::StateChanged(this: &v3->CBaseEdict, offset: 0x37Cu);
    this->m_flCurWeight.m_Value = 0.0;
    CAI_BaseNPC::OnSetSchedule((vgui::Panel *)this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10222460
// Name: private: void CSpatialEntity::FadeIn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpatialEntity::FadeIn(CSpatialEntity *this)
{
  edict_t *m_pPev; // ecx
  CGlobalVars *v3; // eax
  const char *v4; // ecx

  if ( !this->m_bEnabled.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x371u);
    }
    this->m_bEnabled.m_Value = true;
  }
  v3 = gpGlobals;
  v4 = s_pFadeInContextThink_0;
  this->m_flTimeStartFadeIn = gpGlobals->curtime;
  this->m_flStartFadeInWeight = this->m_flCurWeight.m_Value;
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->interval_per_tick + v3->curtime, szContext: v4);
}

//------------------------------------------------------------------------------
// Address: 0x102224E0
// Name: private: void CSpatialEntity::FadeOut(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpatialEntity::FadeOut(CSpatialEntity *this)
{
  edict_t *m_pPev; // ecx
  CGlobalVars *v3; // eax
  const char *v4; // ecx

  if ( this->m_bEnabled.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x371u);
    }
    this->m_bEnabled.m_Value = false;
  }
  v3 = gpGlobals;
  v4 = s_pFadeOutContextThink_0;
  this->m_flTimeStartFadeOut = gpGlobals->curtime;
  this->m_flStartFadeOutWeight = this->m_flCurWeight.m_Value;
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->interval_per_tick + v3->curtime, szContext: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10222560
// Name: public: void CSpatialEntity::InputEnable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpatialEntity::InputEnable(CSpatialEntity *this, inputdata_t *inputdata)
{
  edict_t *m_pPev; // ecx
  edict_t *v4; // ecx

  if ( !this->m_bEnabled.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x371u);
    }
    this->m_bEnabled.m_Value = true;
  }
  if ( this->m_flFadeInDuration <= 0.0 )
  {
    if ( this->m_flCurWeight.m_Value != this->m_flMaxWeight )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        this->m_flCurWeight.m_Value = this->m_flMaxWeight;
      }
      else
      {
        v4 = this->m_Network.m_pPev;
        if ( v4 != nullptr )
          CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0x37Cu);
        this->m_flCurWeight.m_Value = this->m_flMaxWeight;
      }
    }
  }
  else
  {
    CSpatialEntity::FadeIn(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10222610
// Name: public: void CSpatialEntity::InputDisable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpatialEntity::InputDisable(CSpatialEntity *this, inputdata_t *inputdata)
{
  edict_t *m_pPev; // ecx
  edict_t *v4; // ecx

  if ( this->m_bEnabled.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x371u);
    }
    this->m_bEnabled.m_Value = false;
  }
  if ( this->m_flFadeOutDuration <= 0.0 )
  {
    if ( this->m_flCurWeight.m_Value != 0.0 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        this->m_flCurWeight.m_Value = 0.0;
      }
      else
      {
        v4 = this->m_Network.m_pPev;
        if ( v4 != nullptr )
          CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0x37Cu);
        this->m_flCurWeight.m_Value = 0.0;
      }
    }
  }
  else
  {
    CSpatialEntity::FadeOut(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1040A4C0
// Name: CSpatialEntity_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CSpatialEntity_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CSpatialEntity>(__formal: nullptr);
  CSpatialEntity_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040A4F0
// Name: DT_SpatialEntity::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_SpatialEntity::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_SpatialEntity::g_SendTable);
  return atexit(func: DT_SpatialEntity::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1040A510
// Name: DT_SpatialEntity::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_SpatialEntity::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_SpatialEntity::ignored>();
  DT_SpatialEntity::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041E110
// Name: DT_SpatialEntity::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_SpatialEntity::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_SpatialEntity::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x102226C0
// Name: struct datamap_t __near * DataMapInit<class CSpatialEntity>(class CSpatialEntity __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CSpatialEntity>()
{
  if ( (_S2_208 & 1) == 0 )
  {
    _S2_208 |= 1u;
    nameHolder_398.m_pszBase = "CSpatialEntity";
    nameHolder_398.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_398.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_398.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_398.m_Names.m_Size = 0;
    nameHolder_398.m_Names.m_pElements = nullptr;
    nameHolder_398.m_nLenBase = 14;
    atexit(func: DataMapInit_CSpatialEntity__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CSpatialEntity::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S2_208 & 2) == 0 )
  {
    _S2_208 |= 2u;
    dataDesc_486[1].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_398,
                                  pszIdentifier: "FadeInThink");
    dataDesc_486[1].flags = 32;
    dataDesc_486[1].fieldOffset = 0;
    dataDesc_486[1].fieldSize = 1;
    dataDesc_486[1].externalName = nullptr;
    dataDesc_486[1].pSaveRestoreOps = nullptr;
    dataDesc_486[1].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CSpatialEntity::FadeInThink;
    *(_QWORD *)&dataDesc_486[1].td = 0;
    *(_QWORD *)&dataDesc_486[1].override_field = 0;
    *(_QWORD *)&dataDesc_486[1].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_486[1].flatOffset[1] = 0;
    dataDesc_486[2].fieldType = FIELD_VOID;
    dataDesc_486[2].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_398,
                                  pszIdentifier: "FadeOutThink");
    dataDesc_486[2].fieldSize = 1;
    dataDesc_486[2].flags = 32;
    *(_QWORD *)&dataDesc_486[2].td = 0;
    *(_QWORD *)&dataDesc_486[2].override_field = 0;
    *(_QWORD *)&dataDesc_486[2].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_486[2].flatOffset[1] = 0;
    *(_QWORD *)dataDesc_486[3].flatOffset = 0;
    dataDesc_486[2].fieldOffset = 0;
    dataDesc_486[2].externalName = nullptr;
    dataDesc_486[2].pSaveRestoreOps = nullptr;
    dataDesc_486[2].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CSpatialEntity::FadeOutThink;
    dataDesc_486[3].fieldType = FIELD_FLOAT;
    dataDesc_486[3].fieldName = "m_flCurWeight";
    dataDesc_486[3].fieldOffset = 892;
    dataDesc_486[3].fieldSize = 1;
    dataDesc_486[3].flags = 2;
    dataDesc_486[3].externalName = nullptr;
    dataDesc_486[3].pSaveRestoreOps = nullptr;
    dataDesc_486[3].inputFunc = nullptr;
    dataDesc_486[3].td = nullptr;
    dataDesc_486[3].fieldSizeInBytes = 4;
    dataDesc_486[3].override_field = nullptr;
    dataDesc_486[3].override_count = 0;
    dataDesc_486[3].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_486[3].flatGroup = 0;
    dataDesc_486[4].fieldType = FIELD_FLOAT;
    dataDesc_486[4].fieldName = "m_flTimeStartFadeIn";
    dataDesc_486[4].fieldOffset = 868;
    dataDesc_486[4].fieldSize = 1;
    dataDesc_486[4].flags = 2;
    dataDesc_486[4].externalName = nullptr;
    dataDesc_486[4].pSaveRestoreOps = nullptr;
    dataDesc_486[4].inputFunc = nullptr;
    dataDesc_486[4].td = nullptr;
    dataDesc_486[4].fieldSizeInBytes = 4;
    dataDesc_486[4].override_field = nullptr;
    dataDesc_486[4].override_count = 0;
    dataDesc_486[4].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_486[4].flatOffset = 0;
    *(_DWORD *)&dataDesc_486[4].flatGroup = 0;
    dataDesc_486[5].fieldType = FIELD_FLOAT;
    dataDesc_486[5].fieldName = "m_flTimeStartFadeOut";
    dataDesc_486[5].fieldOffset = 872;
    dataDesc_486[5].fieldSize = 1;
    dataDesc_486[5].flags = 2;
    dataDesc_486[5].externalName = nullptr;
    dataDesc_486[5].pSaveRestoreOps = nullptr;
    dataDesc_486[5].inputFunc = nullptr;
    dataDesc_486[5].td = nullptr;
    dataDesc_486[6].flags = 2;
    dataDesc_486[7].flags = 2;
    dataDesc_486[6].fieldSize = 1;
    dataDesc_486[7].fieldSize = 1;
    dataDesc_486[8].fieldSize = 1;
    dataDesc_486[8].flags = 6;
    *(_QWORD *)dataDesc_486[5].flatOffset = 0;
    dataDesc_486[9].fieldSize = 1;
    *(_QWORD *)dataDesc_486[6].flatOffset = 0;
    *(_QWORD *)dataDesc_486[7].flatOffset = 0;
    dataDesc_486[9].flags = 6;
    *(_QWORD *)dataDesc_486[8].flatOffset = 0;
    dataDesc_486[10].fieldSize = 1;
    dataDesc_486[5].fieldSizeInBytes = 4;
    dataDesc_486[5].override_field = nullptr;
    dataDesc_486[5].override_count = 0;
    dataDesc_486[5].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_486[5].flatGroup = 0;
    dataDesc_486[6].fieldType = FIELD_FLOAT;
    dataDesc_486[6].fieldName = "m_flStartFadeInWeight";
    dataDesc_486[6].fieldOffset = 860;
    dataDesc_486[6].externalName = nullptr;
    dataDesc_486[6].pSaveRestoreOps = nullptr;
    dataDesc_486[6].inputFunc = nullptr;
    dataDesc_486[6].td = nullptr;
    dataDesc_486[6].fieldSizeInBytes = 4;
    dataDesc_486[6].override_field = nullptr;
    dataDesc_486[6].override_count = 0;
    dataDesc_486[6].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_486[6].flatGroup = 0;
    dataDesc_486[7].fieldType = FIELD_FLOAT;
    dataDesc_486[7].fieldName = "m_flStartFadeOutWeight";
    dataDesc_486[7].fieldOffset = 864;
    dataDesc_486[7].externalName = nullptr;
    dataDesc_486[7].pSaveRestoreOps = nullptr;
    dataDesc_486[7].inputFunc = nullptr;
    dataDesc_486[7].td = nullptr;
    dataDesc_486[7].fieldSizeInBytes = 4;
    dataDesc_486[7].override_field = nullptr;
    dataDesc_486[7].override_count = 0;
    dataDesc_486[7].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_486[7].flatGroup = 0;
    dataDesc_486[8].fieldType = FIELD_FLOAT;
    dataDesc_486[8].fieldName = "m_MinFalloff";
    dataDesc_486[8].fieldOffset = 884;
    dataDesc_486[8].externalName = "minfalloff";
    dataDesc_486[8].pSaveRestoreOps = nullptr;
    dataDesc_486[8].inputFunc = nullptr;
    dataDesc_486[8].td = nullptr;
    dataDesc_486[8].fieldSizeInBytes = 4;
    dataDesc_486[8].override_field = nullptr;
    dataDesc_486[8].override_count = 0;
    dataDesc_486[8].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_486[8].flatGroup = 0;
    dataDesc_486[9].fieldType = FIELD_FLOAT;
    dataDesc_486[9].fieldName = "m_MaxFalloff";
    dataDesc_486[9].fieldOffset = 888;
    dataDesc_486[9].externalName = "maxfalloff";
    dataDesc_486[9].pSaveRestoreOps = nullptr;
    dataDesc_486[9].inputFunc = nullptr;
    dataDesc_486[9].td = nullptr;
    dataDesc_486[9].fieldSizeInBytes = 4;
    dataDesc_486[9].override_field = nullptr;
    dataDesc_486[9].override_count = 0;
    dataDesc_486[9].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_486[9].flatOffset = 0;
    *(_DWORD *)&dataDesc_486[9].flatGroup = 0;
    dataDesc_486[10].fieldType = FIELD_FLOAT;
    dataDesc_486[10].fieldName = "m_flMaxWeight";
    dataDesc_486[10].fieldOffset = 876;
    dataDesc_486[10].flags = 6;
    dataDesc_486[11].fieldSize = 1;
    dataDesc_486[11].flags = 6;
    dataDesc_486[12].fieldSize = 1;
    *(_QWORD *)dataDesc_486[10].flatOffset = 0;
    *(_QWORD *)dataDesc_486[11].flatOffset = 0;
    dataDesc_486[12].flags = 6;
    *(_QWORD *)dataDesc_486[12].flatOffset = 0;
    dataDesc_486[10].fieldSizeInBytes = 4;
    dataDesc_486[11].fieldSizeInBytes = 4;
    dataDesc_486[12].fieldSizeInBytes = 4;
    dataDesc_486[13].fieldSize = 1;
    dataDesc_486[13].fieldSizeInBytes = 4;
    *(_QWORD *)dataDesc_486[13].flatOffset = 0;
    dataDesc_486[10].externalName = "maxweight";
    dataDesc_486[10].pSaveRestoreOps = nullptr;
    dataDesc_486[10].inputFunc = nullptr;
    dataDesc_486[10].td = nullptr;
    dataDesc_486[10].override_field = nullptr;
    dataDesc_486[10].override_count = 0;
    dataDesc_486[10].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_486[10].flatGroup = 0;
    dataDesc_486[11].fieldType = FIELD_FLOAT;
    dataDesc_486[11].fieldName = "m_flFadeInDuration";
    dataDesc_486[11].fieldOffset = 852;
    dataDesc_486[11].externalName = "fadeInDuration";
    dataDesc_486[11].pSaveRestoreOps = nullptr;
    dataDesc_486[11].inputFunc = nullptr;
    dataDesc_486[11].td = nullptr;
    dataDesc_486[11].override_field = nullptr;
    dataDesc_486[11].override_count = 0;
    dataDesc_486[11].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_486[11].flatGroup = 0;
    dataDesc_486[12].fieldType = FIELD_FLOAT;
    dataDesc_486[12].fieldName = "m_flFadeOutDuration";
    dataDesc_486[12].fieldOffset = 856;
    dataDesc_486[12].externalName = "fadeOutDuration";
    dataDesc_486[12].pSaveRestoreOps = nullptr;
    dataDesc_486[12].inputFunc = nullptr;
    dataDesc_486[12].td = nullptr;
    dataDesc_486[12].override_field = nullptr;
    dataDesc_486[12].override_count = 0;
    dataDesc_486[12].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_486[12].flatGroup = 0;
    dataDesc_486[13].fieldType = FIELD_STRING;
    dataDesc_486[13].fieldName = "m_lookupFilename";
    dataDesc_486[13].fieldOffset = 896;
    dataDesc_486[13].flags = 6;
    dataDesc_486[13].externalName = "filename";
    dataDesc_486[13].pSaveRestoreOps = nullptr;
    dataDesc_486[13].inputFunc = nullptr;
    dataDesc_486[13].td = nullptr;
    dataDesc_486[13].override_field = nullptr;
    dataDesc_486[13].override_count = 0;
    dataDesc_486[13].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_486[13].flatGroup = 0;
    dataDesc_486[14].fieldType = FIELD_BOOLEAN;
    dataDesc_486[14].fieldName = "m_bEnabled";
    dataDesc_486[14].fieldOffset = 881;
    dataDesc_486[14].fieldSize = 1;
    dataDesc_486[14].flags = 6;
    dataDesc_486[14].externalName = "enabled";
    dataDesc_486[14].pSaveRestoreOps = nullptr;
    dataDesc_486[14].inputFunc = nullptr;
    dataDesc_486[14].td = nullptr;
    dataDesc_486[14].fieldSizeInBytes = 1;
    dataDesc_486[14].override_field = nullptr;
    dataDesc_486[14].override_count = 0;
    dataDesc_486[14].fieldTolerance = 0.0;
    dataDesc_486[15].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_486[15].flatOffset = 0;
    dataDesc_486[15].fieldType = FIELD_BOOLEAN;
    dataDesc_486[15].flags = 6;
    *(_QWORD *)&dataDesc_486[16].td = 0;
    *(_QWORD *)&dataDesc_486[16].override_field = 0;
    *(_QWORD *)&dataDesc_486[16].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_486[16].flatOffset[1] = 0;
    dataDesc_486[16].fieldSize = 1;
    *(_QWORD *)&dataDesc_486[17].td = 0;
    *(_QWORD *)&dataDesc_486[17].override_field = 0;
    *(_QWORD *)&dataDesc_486[17].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_486[17].flatOffset[1] = 0;
    dataDesc_486[15].fieldSize = 1;
    dataDesc_486[16].flags = 8;
    dataDesc_486[17].fieldSize = 1;
    *(_QWORD *)&dataDesc_486[18].td = 0;
    *(_QWORD *)&dataDesc_486[18].override_field = 0;
    *(_QWORD *)&dataDesc_486[18].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_486[18].flatOffset[1] = 0;
    *(_QWORD *)dataDesc_486[14].flatOffset = 0;
    *(_DWORD *)&dataDesc_486[14].flatGroup = 0;
    dataDesc_486[15].fieldName = "m_bStartDisabled";
    dataDesc_486[15].fieldOffset = 880;
    dataDesc_486[15].externalName = "StartDisabled";
    dataDesc_486[15].pSaveRestoreOps = nullptr;
    dataDesc_486[15].inputFunc = nullptr;
    dataDesc_486[15].td = nullptr;
    dataDesc_486[15].fieldSizeInBytes = 1;
    dataDesc_486[15].override_field = nullptr;
    dataDesc_486[15].override_count = 0;
    *(_DWORD *)&dataDesc_486[15].flatGroup = 0;
    dataDesc_486[16].fieldType = FIELD_VOID;
    dataDesc_486[16].fieldName = "InputEnable";
    dataDesc_486[16].fieldOffset = 0;
    dataDesc_486[16].externalName = "Enable";
    dataDesc_486[16].pSaveRestoreOps = nullptr;
    dataDesc_486[16].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CSpatialEntity::InputEnable;
    dataDesc_486[17].fieldType = FIELD_VOID;
    dataDesc_486[17].fieldName = "InputDisable";
    dataDesc_486[17].fieldOffset = 0;
    dataDesc_486[17].flags = 8;
    dataDesc_486[17].externalName = "Disable";
    dataDesc_486[17].pSaveRestoreOps = nullptr;
    dataDesc_486[17].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CSpatialEntity::InputDisable;
    dataDesc_486[18].fieldType = FIELD_FLOAT;
    dataDesc_486[18].fieldName = "InputSetFadeInDuration";
    dataDesc_486[18].fieldOffset = 0;
    *(_DWORD *)&dataDesc_486[18].fieldSize = 524289;
    dataDesc_486[18].externalName = "SetFadeInDuration";
    dataDesc_486[18].pSaveRestoreOps = nullptr;
    dataDesc_486[18].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CLogicCompare::InputSetValue;
    dataDesc_486[19].fieldType = FIELD_FLOAT;
    dataDesc_486[19].fieldName = "InputSetFadeOutDuration";
    dataDesc_486[19].fieldOffset = 0;
    *(_DWORD *)&dataDesc_486[19].fieldSize = 524289;
    dataDesc_486[19].externalName = "SetFadeOutDuration";
    dataDesc_486[19].pSaveRestoreOps = nullptr;
    dataDesc_486[19].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CSpatialEntity::InputSetFadeOutDuration;
    *(_QWORD *)&dataDesc_486[19].td = 0;
    *(_QWORD *)&dataDesc_486[19].override_field = 0;
    *(_QWORD *)&dataDesc_486[19].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_486[19].flatOffset[1] = 0;
  }
  CSpatialEntity::m_DataMap.dataNumFields = 19;
  CSpatialEntity::m_DataMap.dataDesc = &dataDesc_486[1];
  return &CSpatialEntity::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1040A4D0
// Name: _dynamic_initializer_for__g_CSpatialEntity_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CSpatialEntity_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CSpatialEntity_ClassReg,
           pNetworkName: "CSpatialEntity",
           pTable: &DT_SpatialEntity::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041E120
// Name: _ServerClassInit_DT_SpatialEntity::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_SpatialEntity::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S3_119;
  for ( i = 5; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041E140
// Name: _DataMapInit_CSpatialEntity__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CSpatialEntity__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_398);
}
