// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/prop_hallucination.cpp
// Functions: 18
// ============================================================

#include "game\server\prop_hallucination.h"

//------------------------------------------------------------------------------
// Address: 0x101DD130
// Name: public: virtual struct datamap_t __near * CProp_Hallucination::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CProp_Hallucination::GetDataDescMap(CProp_Hallucination *this)
{
  return &CProp_Hallucination::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101DD140
// Name: public: virtual class ServerClass __near * CProp_Hallucination::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CProp_Hallucination::GetServerClass(CProp_Hallucination *this)
{
  return &g_CProp_Hallucination_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x101DD150
// Name: public: virtual void CProp_Hallucination::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CProp_Hallucination::Precache(CProp_Hallucination *this@<ecx>, bool (__cdecl *a2)(const char *)@<edi>)
{
  const char *pszValue; // esi

  CBaseAnimating::Precache(this);
  pszValue = this->m_ModelName.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  CBaseEntity::PrecacheModel(a1: a2, name: pszValue, bPreload: true);
}

//------------------------------------------------------------------------------
// Address: 0x101DD180
// Name: public: virtual int CProp_Hallucination::DrawDebugTextOverlays(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CProp_Hallucination::DrawDebugTextOverlays(CProp_Hallucination *this)
{
  int result; // eax
  int v3; // esi
  const char *v4; // eax
  int v5; // esi
  char tempstr[256]; // [esp+1Ch] [ebp-100h] BYREF

  result = CBaseAnimating::DrawDebugTextOverlays(this);
  v3 = result;
  if ( (this->m_debugOverlays & 1) != 0 )
  {
    v4 = "Enabled";
    if ( !this->m_bEnabled.m_Value )
      v4 = "Disabled";
    V_snprintf(pDest: tempstr, maxLen: 255, pFormat: "%s", v4);
    CBaseEntity::EntityText(this, text_offset: v3, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    v5 = v3 + 1;
    V_snprintf(pDest: tempstr, maxLen: 255, pFormat: "Start Enabled Chance: %f%%", this->m_fStartEnabledChance);
    CBaseEntity::EntityText(this, text_offset: v5++, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    V_snprintf(pDest: tempstr, maxLen: 255, pFormat: "Visible Time: %fs", this->m_fVisibleTime.m_Value);
    CBaseEntity::EntityText(this, text_offset: v5++, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    V_snprintf(pDest: tempstr, maxLen: 255, pFormat: "Recharge Time: %fs", this->m_fRechargeTime.m_Value);
    CBaseEntity::EntityText(this, text_offset: v5, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    return v5 + 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101DD480
// Name: public: virtual void CProp_Hallucination::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall CProp_Hallucination::Spawn(CProp_Hallucination *this)
{
  const char *pszValue; // eax
  IUniformRandomStream *v3; // ecx
  bool v4; // bl
  edict_t *m_pPev; // ecx

  this->Precache(this);
  vgui::ListViewPanel::Paint((vgui::ListViewPanel *)this);
  pszValue = this->m_ModelName.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  this->SetModel(this, a2: pszValue);
  if ( this->m_fStartEnabledChance > 0.0 )
  {
    v4 = this->m_fStartEnabledChance * 0.0099999998 >= _RandomFloat(this: v3, a2: 0.0, a3: 1.0);
    if ( this->m_bEnabled.m_Value != v4 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        this->m_bEnabled.m_Value = v4;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x48Cu);
        this->m_bEnabled.m_Value = v4;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DD530
// Name: public: void CProp_Hallucination::InputEnable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProp_Hallucination::InputEnable(CProp_Hallucination *this, inputdata_t *inputdata)
{
  CNetworkVarBase<bool,CProp_Hallucination::NetworkVar_m_bEnabled> *p_m_bEnabled; // esi
  edict_t *m_pPev; // ecx

  p_m_bEnabled = &this->m_bEnabled;
  if ( !this->m_bEnabled.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_bEnabled->m_Value = true;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x48Cu);
      p_m_bEnabled->m_Value = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DD580
// Name: public: void CProp_Hallucination::InputDisable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProp_Hallucination::InputDisable(CProp_Hallucination *this, inputdata_t *inputdata)
{
  CNetworkVarBase<bool,CProp_Hallucination::NetworkVar_m_bEnabled> *p_m_bEnabled; // esi
  edict_t *m_pPev; // ecx

  p_m_bEnabled = &this->m_bEnabled;
  if ( this->m_bEnabled.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_bEnabled->m_Value = false;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x48Cu);
      p_m_bEnabled->m_Value = false;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DD5D0
// Name: public: void CProp_Hallucination::InputSetVisibleTime(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProp_Hallucination::InputSetVisibleTime(CProp_Hallucination *this, inputdata_t *inputdata)
{
  float flVal; // xmm0_4
  CNetworkVarBase<float,CProp_Hallucination::NetworkVar_m_fVisibleTime> *p_m_fVisibleTime; // esi
  edict_t *m_pPev; // ecx

  if ( inputdata->value.fieldType == FIELD_FLOAT )
    flVal = inputdata->value.flVal;
  else
    flVal = 0.0;
  p_m_fVisibleTime = &this->m_fVisibleTime;
  if ( this->m_fVisibleTime.m_Value != flVal )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_fVisibleTime->m_Value = flVal;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x494u);
      p_m_fVisibleTime->m_Value = flVal;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DD650
// Name: public: void CProp_Hallucination::InputSetRechargeTime(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CProp_Hallucination::InputSetRechargeTime(CProp_Hallucination *this, inputdata_t *inputdata)
{
  float flVal; // xmm0_4
  CNetworkVarBase<float,CProp_Hallucination::NetworkVar_m_fRechargeTime> *p_m_fRechargeTime; // esi
  edict_t *m_pPev; // ecx

  if ( inputdata->value.fieldType == FIELD_FLOAT )
    flVal = inputdata->value.flVal;
  else
    flVal = 0.0;
  p_m_fRechargeTime = &this->m_fRechargeTime;
  if ( this->m_fRechargeTime.m_Value != flVal )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_fRechargeTime->m_Value = flVal;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x498u);
      p_m_fRechargeTime->m_Value = flVal;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10408AE0
// Name: CProp_Hallucination_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CProp_Hallucination_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CProp_Hallucination>(__formal: nullptr);
  CProp_Hallucination_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10408B10
// Name: DT_Prop_Hallucination::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_Prop_Hallucination::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_Prop_Hallucination::g_SendTable);
  return atexit(func: DT_Prop_Hallucination::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10408B30
// Name: DT_Prop_Hallucination::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_Prop_Hallucination::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_Prop_Hallucination::ignored>();
  DT_Prop_Hallucination::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041D690
// Name: DT_Prop_Hallucination::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_Prop_Hallucination::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_Prop_Hallucination::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x101DD6D0
// Name: struct datamap_t __near * DataMapInit<class CProp_Hallucination>(class CProp_Hallucination __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CProp_Hallucination>()
{
  if ( (_S2_188 & 1) == 0 )
  {
    _S2_188 |= 1u;
    nameHolder_350.m_pszBase = "CProp_Hallucination";
    nameHolder_350.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_350.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_350.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_350.m_Names.m_Size = 0;
    nameHolder_350.m_Names.m_pElements = nullptr;
    nameHolder_350.m_nLenBase = 19;
    atexit(func: DataMapInit_CProp_Hallucination__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CProp_Hallucination::m_DataMap.baseMap = &CBaseAnimating::m_DataMap;
  CProp_Hallucination::m_DataMap.dataNumFields = 8;
  CProp_Hallucination::m_DataMap.dataDesc = &dataDesc_335[1];
  return &CProp_Hallucination::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10408AF0
// Name: _dynamic_initializer_for__g_CProp_Hallucination_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CProp_Hallucination_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CProp_Hallucination_ClassReg,
           pNetworkName: "CProp_Hallucination",
           pTable: &DT_Prop_Hallucination::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041D6A0
// Name: _ServerClassInit_DT_Prop_Hallucination::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_Prop_Hallucination::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S3_104;
  for ( i = 4; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041D6C0
// Name: _DataMapInit_CProp_Hallucination__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CProp_Hallucination__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_350);
}

//------------------------------------------------------------------------------
// Address: 0x1041D6D0
// Name: _dynamic_atexit_destructor_for__g_debug_doors__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_debug_doors__()
{
  ConVar::~ConVar(this: &g_debug_doors);
}
