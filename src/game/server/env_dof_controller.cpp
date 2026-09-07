// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/env_dof_controller.cpp
// Functions: 24
// ============================================================

#include "game\server\env_dof_controller.h"

//------------------------------------------------------------------------------
// Address: 0x101114A0
// Name: public: virtual struct datamap_t __near * CEnvDOFController::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CEnvDOFController::GetDataDescMap(CEnvDOFController *this)
{
  return &CEnvDOFController::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101114B0
// Name: public: virtual class ServerClass __near * CEnvDOFController::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CEnvDOFController::GetServerClass(CEnvDOFController *this)
{
  return &g_CEnvDOFController_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x10111730
// Name: public: void CEnvDOFController::InputSetFarFocusDepth(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvDOFController::InputSetFarFocusDepth(CEnvDOFController *this, inputdata_t *inputdata)
{
  float flVal; // xmm0_4
  CNetworkVarBase<float,CEnvDOFController::NetworkVar_m_flFarFocusDepth> *p_m_flFarFocusDepth; // esi
  edict_t *m_pPev; // ecx

  if ( inputdata->value.fieldType == FIELD_FLOAT )
    flVal = inputdata->value.flVal;
  else
    flVal = 0.0;
  p_m_flFarFocusDepth = &this->m_flFarFocusDepth;
  if ( this->m_flFarFocusDepth.m_Value != flVal )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_flFarFocusDepth->m_Value = flVal;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x36Cu);
      p_m_flFarFocusDepth->m_Value = flVal;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101117B0
// Name: public: void CEnvDOFController::InputSetFarBlurDepth(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvDOFController::InputSetFarBlurDepth(CEnvDOFController *this, inputdata_t *inputdata)
{
  float flVal; // xmm0_4
  CNetworkVarBase<float,CEnvDOFController::NetworkVar_m_flFarBlurDepth> *p_m_flFarBlurDepth; // esi
  edict_t *m_pPev; // ecx

  if ( inputdata->value.fieldType == FIELD_FLOAT )
    flVal = inputdata->value.flVal;
  else
    flVal = 0.0;
  p_m_flFarBlurDepth = &this->m_flFarBlurDepth;
  if ( this->m_flFarBlurDepth.m_Value != flVal )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_flFarBlurDepth->m_Value = flVal;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x370u);
      p_m_flFarBlurDepth->m_Value = flVal;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10111830
// Name: public: void CEnvDOFController::UpdateParamBlend(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CEnvDOFController::UpdateParamBlend(CEnvDOFController *this@<ecx>, int a2@<ebp>)
{
  CEnvDOFController *v2; // esi
  unsigned int m_Index; // eax
  CBasePlayer *LocalPlayer; // edi
  unsigned int v5; // eax
  CBaseEntity *m_pEntity; // esi
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm0_4
  edict_t *m_pPev; // ecx
  edict_t *v12; // ecx
  _DWORD v14[3]; // [esp+38h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+44h] [ebp+0h]

  v14[0] = a2;
  v14[1] = retaddr;
  v2 = this;
  m_Index = this->m_hFocusTarget.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
  {
    if ( gpGlobals->maxClients <= 1 )
      LocalPlayer = UTIL_GetLocalPlayer();
    else
      LocalPlayer = nullptr;
    if ( (LocalPlayer->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: LocalPlayer, a2: (int)v14);
    v5 = v2->m_hFocusTarget.m_Index;
    if ( v5 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_SerialNumber != HIWORD(v5) )
      m_pEntity = nullptr;
    else
      m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_pEntity;
    if ( (m_pEntity->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: m_pEntity, a2: (int)v14);
    v7 = m_pEntity->m_vecAbsOrigin.x - LocalPlayer->m_vecAbsOrigin.x;
    v8 = m_pEntity->m_vecAbsOrigin.y - LocalPlayer->m_vecAbsOrigin.y;
    v9 = m_pEntity->m_vecAbsOrigin.z - LocalPlayer->m_vecAbsOrigin.z;
    v10 = fsqrt((float)((float)(v8 * v8) + (float)(v9 * v9)) + (float)(v7 * v7));
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x36Cu);
    }
    this->m_flFarFocusDepth.m_Value = this->m_flFocusTargetRange + v10;
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v12 = this->m_Network.m_pPev;
      if ( v12 != nullptr )
        CBaseEdict::StateChanged(this: &v12->CBaseEdict, offset: 0x370u);
    }
    this->m_flFarBlurDepth.m_Value = this->m_flFarFocusDepth.m_Value + 500.0;
    v2 = this;
  }
  CBaseEntity::ThinkSet(
    this: v2,
    func: (void (__thiscall *)(CBaseEntity *))CEnvDOFController::UpdateParamBlend,
    thinkTime: 0.0,
    szContext: nullptr);
  CBaseEntity::SetNextThink(this: v2, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10111A10
// Name: public: void CEnvDOFController::InputSetFocusTarget(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvDOFController::InputSetFocusTarget(CEnvDOFController *this, inputdata_t *inputdata)
{
  variant_t *p_value; // ecx
  const char *iVal; // eax
  CBasePlayer *EntityByName; // eax
  unsigned int m_Index; // eax

  p_value = &inputdata->value;
  if ( inputdata->value.fieldType == FIELD_STRING )
  {
    iVal = (const char *)p_value->iVal;
    if ( p_value->iVal == 0 )
      iVal = locale;
  }
  else
  {
    iVal = variant_t::ToString(this: p_value);
  }
  EntityByName = CGlobalEntityList::FindEntityByName(
                   this: &gEntList,
                   pStartEntity: nullptr,
                   szName: iVal,
                   pSearchingEntity: nullptr,
                   pActivator: nullptr,
                   pCaller: nullptr,
                   pFilter: nullptr);
  if ( EntityByName != nullptr )
    this->m_hFocusTarget.m_Index = EntityByName->GetRefEHandle(this: EntityByName)->m_Index;
  else
    this->m_hFocusTarget.m_Index = -1;
  m_Index = this->m_hFocusTarget.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
  {
    CBaseEntity::ThinkSet(
      this,
      func: (void (__thiscall *)(CBaseEntity *))CEnvDOFController::UpdateParamBlend,
      thinkTime: 0.0,
      szContext: nullptr);
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10111B30
// Name: public: virtual void CEnvDOFController::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvDOFController::Activate(CEnvDOFController *this)
{
  const char *pszValue; // eax
  CBasePlayer *EntityByName; // eax
  unsigned int m_Index; // eax

  CBaseEntity::Activate(this);
  pszValue = this->m_strFocusTargetName.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  EntityByName = CGlobalEntityList::FindEntityByName(
                   this: &gEntList,
                   pStartEntity: nullptr,
                   szName: pszValue,
                   pSearchingEntity: nullptr,
                   pActivator: nullptr,
                   pCaller: nullptr,
                   pFilter: nullptr);
  if ( EntityByName != nullptr )
    this->m_hFocusTarget.m_Index = EntityByName->GetRefEHandle(this: EntityByName)->m_Index;
  else
    this->m_hFocusTarget.m_Index = -1;
  m_Index = this->m_hFocusTarget.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
  {
    CBaseEntity::ThinkSet(
      this,
      func: (void (__thiscall *)(CBaseEntity *))CEnvDOFController::UpdateParamBlend,
      thinkTime: 0.0,
      szContext: nullptr);
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10111BF0
// Name: public: void CEnvDOFController::InputSetNearBlurRadius(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvDOFController::InputSetNearBlurRadius(CEnvDOFController *this, inputdata_t *inputdata)
{
  float flVal; // xmm0_4
  edict_t *m_pPev; // ecx
  bool v5; // bl
  edict_t *v6; // ecx

  if ( inputdata->value.fieldType == FIELD_FLOAT )
    flVal = inputdata->value.flVal;
  else
    flVal = 0.0;
  if ( this->m_flNearBlurRadius.m_Value != flVal )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x374u);
    }
    this->m_flNearBlurRadius.m_Value = flVal;
  }
  v5 = this->m_flNearBlurRadius.m_Value > 0.0 || this->m_flFarBlurRadius.m_Value > 0.0;
  if ( this->m_bDOFEnabled.m_Value != v5 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_bDOFEnabled.m_Value = v5;
    }
    else
    {
      v6 = this->m_Network.m_pPev;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: &v6->CBaseEdict, offset: 0x360u);
      this->m_bDOFEnabled.m_Value = v5;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10111CC0
// Name: public: void CEnvDOFController::InputSetFarBlurRadius(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvDOFController::InputSetFarBlurRadius(CEnvDOFController *this, inputdata_t *inputdata)
{
  float flVal; // xmm0_4
  edict_t *m_pPev; // ecx
  bool v5; // bl
  edict_t *v6; // ecx

  if ( inputdata->value.fieldType == FIELD_FLOAT )
    flVal = inputdata->value.flVal;
  else
    flVal = 0.0;
  if ( this->m_flFarBlurRadius.m_Value != flVal )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x378u);
    }
    this->m_flFarBlurRadius.m_Value = flVal;
  }
  v5 = this->m_flNearBlurRadius.m_Value > 0.0 || this->m_flFarBlurRadius.m_Value > 0.0;
  if ( this->m_bDOFEnabled.m_Value != v5 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_bDOFEnabled.m_Value = v5;
    }
    else
    {
      v6 = this->m_Network.m_pPev;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: &v6->CBaseEdict, offset: 0x360u);
      this->m_bDOFEnabled.m_Value = v5;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10175470
// Name: public: void CEnvDOFController::InputSetNearBlurDepth(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvDOFController::InputSetNearBlurDepth(CEnvDOFController *this, inputdata_t *inputdata)
{
  float flVal; // xmm0_4
  CNetworkVarBase<float,CEnvDOFController::NetworkVar_m_flNearBlurDepth> *p_m_flNearBlurDepth; // esi
  edict_t *m_pPev; // ecx

  if ( inputdata->value.fieldType == FIELD_FLOAT )
    flVal = inputdata->value.flVal;
  else
    flVal = 0.0;
  p_m_flNearBlurDepth = &this->m_flNearBlurDepth;
  if ( this->m_flNearBlurDepth.m_Value != flVal )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_flNearBlurDepth->m_Value = flVal;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x364u);
      p_m_flNearBlurDepth->m_Value = flVal;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101754F0
// Name: public: void CEnvDOFController::InputSetNearFocusDepth(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEnvDOFController::InputSetNearFocusDepth(CEnvDOFController *this, inputdata_t *inputdata)
{
  float flVal; // xmm0_4
  CNetworkVarBase<float,CEnvDOFController::NetworkVar_m_flNearFocusDepth> *p_m_flNearFocusDepth; // esi
  edict_t *m_pPev; // ecx

  if ( inputdata->value.fieldType == FIELD_FLOAT )
    flVal = inputdata->value.flVal;
  else
    flVal = 0.0;
  p_m_flNearFocusDepth = &this->m_flNearFocusDepth;
  if ( this->m_flNearFocusDepth.m_Value != flVal )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_flNearFocusDepth->m_Value = flVal;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x368u);
      p_m_flNearFocusDepth->m_Value = flVal;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104026E0
// Name: CEnvDOFController_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CEnvDOFController_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CEnvDOFController>(__formal: nullptr);
  CEnvDOFController_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10402710
// Name: DT_EnvDOFController::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_EnvDOFController::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_EnvDOFController::g_SendTable);
  return atexit(func: DT_EnvDOFController::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10402730
// Name: DT_EnvDOFController::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_EnvDOFController::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_EnvDOFController::ignored>();
  DT_EnvDOFController::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041ADB0
// Name: DT_EnvDOFController::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_EnvDOFController::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_EnvDOFController::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10111D90
// Name: struct datamap_t __near * DataMapInit<class CEnvDOFController>(class CEnvDOFController __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CEnvDOFController>()
{
  if ( (_S2_82 & 1) == 0 )
  {
    _S2_82 |= 1u;
    nameHolder_159.m_pszBase = "CEnvDOFController";
    nameHolder_159.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_159.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_159.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_159.m_Names.m_Size = 0;
    nameHolder_159.m_Names.m_pElements = nullptr;
    nameHolder_159.m_nLenBase = 17;
    atexit(func: DataMapInit_CEnvDOFController__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CEnvDOFController::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S2_82 & 2) == 0 )
  {
    _S2_82 |= 2u;
    dataDesc_150[11].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_159,
                                   pszIdentifier: "UpdateParamBlend");
    dataDesc_150[11].fieldSize = 1;
    *(_QWORD *)&dataDesc_150[11].td = 0;
    *(_QWORD *)&dataDesc_150[11].override_field = 0;
    *(_QWORD *)&dataDesc_150[11].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_150[11].flatOffset[1] = 0;
    dataDesc_150[11].flags = 32;
    dataDesc_150[12].fieldSize = 1;
    *(_QWORD *)&dataDesc_150[12].td = 0;
    *(_QWORD *)&dataDesc_150[12].override_field = 0;
    *(_QWORD *)&dataDesc_150[12].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_150[12].flatOffset[1] = 0;
    dataDesc_150[12].flags = 8;
    dataDesc_150[13].fieldSize = 1;
    *(_QWORD *)&dataDesc_150[13].td = 0;
    *(_QWORD *)&dataDesc_150[13].override_field = 0;
    *(_QWORD *)&dataDesc_150[13].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_150[13].flatOffset[1] = 0;
    dataDesc_150[13].flags = 8;
    dataDesc_150[14].fieldSize = 1;
    *(_QWORD *)&dataDesc_150[14].td = 0;
    *(_QWORD *)&dataDesc_150[14].override_field = 0;
    *(_QWORD *)&dataDesc_150[14].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_150[14].flatOffset[1] = 0;
    dataDesc_150[11].fieldOffset = 0;
    dataDesc_150[11].externalName = nullptr;
    dataDesc_150[11].pSaveRestoreOps = nullptr;
    dataDesc_150[11].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CEnvDOFController::UpdateParamBlend;
    dataDesc_150[12].fieldType = FIELD_FLOAT;
    dataDesc_150[12].fieldName = "InputSetNearBlurDepth";
    dataDesc_150[12].fieldOffset = 0;
    dataDesc_150[12].externalName = "SetNearBlurDepth";
    dataDesc_150[12].pSaveRestoreOps = nullptr;
    dataDesc_150[12].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CEnvDOFController::InputSetNearBlurDepth;
    dataDesc_150[13].fieldType = FIELD_FLOAT;
    dataDesc_150[13].fieldName = "InputSetNearFocusDepth";
    dataDesc_150[13].fieldOffset = 0;
    dataDesc_150[13].externalName = "SetNearFocusDepth";
    dataDesc_150[13].pSaveRestoreOps = nullptr;
    dataDesc_150[13].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CEnvDOFController::InputSetNearFocusDepth;
    dataDesc_150[14].fieldType = FIELD_FLOAT;
    dataDesc_150[14].fieldName = "InputSetFarFocusDepth";
    dataDesc_150[14].fieldOffset = 0;
    dataDesc_150[14].flags = 8;
    dataDesc_150[14].externalName = "SetFarFocusDepth";
    dataDesc_150[14].pSaveRestoreOps = nullptr;
    dataDesc_150[14].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CEnvDOFController::InputSetFarFocusDepth;
    dataDesc_150[15].fieldType = FIELD_FLOAT;
    dataDesc_150[15].fieldName = "InputSetFarBlurDepth";
    dataDesc_150[15].fieldOffset = 0;
    dataDesc_150[15].fieldSize = 1;
    dataDesc_150[15].flags = 8;
    dataDesc_150[15].externalName = "SetFarBlurDepth";
    dataDesc_150[15].pSaveRestoreOps = nullptr;
    dataDesc_150[15].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CEnvDOFController::InputSetFarBlurDepth;
    *(_QWORD *)&dataDesc_150[15].td = 0;
    *(_QWORD *)&dataDesc_150[15].override_field = 0;
    *(_QWORD *)&dataDesc_150[15].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_150[15].flatOffset[1] = 0;
    dataDesc_150[16].fieldType = FIELD_FLOAT;
    dataDesc_150[16].fieldName = "InputSetNearBlurRadius";
    dataDesc_150[16].fieldOffset = 0;
    *(_QWORD *)&dataDesc_150[16].td = 0;
    *(_QWORD *)&dataDesc_150[16].override_field = 0;
    *(_QWORD *)&dataDesc_150[16].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_150[16].flatOffset[1] = 0;
    dataDesc_150[16].fieldSize = 1;
    *(_QWORD *)&dataDesc_150[17].td = 0;
    *(_QWORD *)&dataDesc_150[17].override_field = 0;
    *(_QWORD *)&dataDesc_150[17].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_150[17].flatOffset[1] = 0;
    dataDesc_150[16].flags = 8;
    dataDesc_150[17].fieldSize = 1;
    *(_QWORD *)&dataDesc_150[18].td = 0;
    *(_QWORD *)&dataDesc_150[18].override_field = 0;
    *(_QWORD *)&dataDesc_150[18].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_150[18].flatOffset[1] = 0;
    dataDesc_150[16].externalName = "SetNearBlurRadius";
    dataDesc_150[16].pSaveRestoreOps = nullptr;
    dataDesc_150[16].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CEnvDOFController::InputSetNearBlurRadius;
    dataDesc_150[17].fieldType = FIELD_FLOAT;
    dataDesc_150[17].fieldName = "InputSetFarBlurRadius";
    dataDesc_150[17].fieldOffset = 0;
    dataDesc_150[17].flags = 8;
    dataDesc_150[17].externalName = "SetFarBlurRadius";
    dataDesc_150[17].pSaveRestoreOps = nullptr;
    dataDesc_150[17].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CEnvDOFController::InputSetFarBlurRadius;
    dataDesc_150[18].fieldType = FIELD_STRING;
    dataDesc_150[18].fieldName = "InputSetFocusTarget";
    dataDesc_150[18].fieldOffset = 0;
    *(_DWORD *)&dataDesc_150[18].fieldSize = 524289;
    dataDesc_150[18].externalName = "SetFocusTarget";
    dataDesc_150[18].pSaveRestoreOps = nullptr;
    dataDesc_150[18].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CEnvDOFController::InputSetFocusTarget;
    dataDesc_150[19].fieldType = FIELD_STRING;
    dataDesc_150[19].fieldName = "InputSetFocusTargetRange";
    dataDesc_150[19].fieldOffset = 0;
    *(_DWORD *)&dataDesc_150[19].fieldSize = 524289;
    dataDesc_150[19].externalName = "SetFocusTargetRange";
    dataDesc_150[19].pSaveRestoreOps = nullptr;
    dataDesc_150[19].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CLogicCompare::InputSetValue;
    *(_QWORD *)&dataDesc_150[19].td = 0;
    *(_QWORD *)&dataDesc_150[19].override_field = 0;
    *(_QWORD *)&dataDesc_150[19].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_150[19].flatOffset[1] = 0;
  }
  CEnvDOFController::m_DataMap.dataNumFields = 19;
  CEnvDOFController::m_DataMap.dataDesc = &dataDesc_150[1];
  return &CEnvDOFController::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x104026F0
// Name: _dynamic_initializer_for__g_CEnvDOFController_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CEnvDOFController_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CEnvDOFController_ClassReg,
           pNetworkName: "CEnvDOFController",
           pTable: &DT_EnvDOFController::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041ADC0
// Name: _ServerClassInit_DT_EnvDOFController::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_EnvDOFController::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S3_48;
  for ( i = 8; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041ADE0
// Name: _DataMapInit_CEnvDOFController__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CEnvDOFController__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_159);
}

//------------------------------------------------------------------------------
// Address: 0x1041ADF0
// Name: _DataMapInit_CEnvEffectsScript__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CEnvEffectsScript__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_160);
}

//------------------------------------------------------------------------------
// Address: 0x1041AE00
// Name: _DataMapInit_CEnvEntityMaker__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CEnvEntityMaker__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_161);
}

//------------------------------------------------------------------------------
// Address: 0x1041AE10
// Name: _dynamic_atexit_destructor_for__g_CEnvEntityMaker_ScriptDesc__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CEnvEntityMaker_ScriptDesc__()
{
  CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::~CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>(this: &g_CEnvEntityMaker_ScriptDesc.m_FunctionBindings);
}

//------------------------------------------------------------------------------
// Address: 0x1041AE20
// Name: _DataMapInit_CEnvInstructorHint__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CEnvInstructorHint__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_162);
}

//------------------------------------------------------------------------------
// Address: 0x1041AE30
// Name: _DataMapInit_CInfoInstructorHintTarget__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CInfoInstructorHintTarget__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_163);
}
