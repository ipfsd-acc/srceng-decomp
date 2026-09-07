// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/ragdoll_manager.cpp
// Functions: 24
// ============================================================

#include "game\server\ragdoll_manager.h"

//------------------------------------------------------------------------------
// Address: 0x10114C10
// Name: public: virtual int CRagdollManager::UpdateTransmitState(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRagdollManager::UpdateTransmitState(CColorCorrection *this)
{
  return CBaseEntity::SetTransmitState(this, nFlag: 8);
}

//------------------------------------------------------------------------------
// Address: 0x101F1B20
// Name: public: virtual class ServerClass __near * CRagdollManager::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CRagdollManager::GetServerClass(CRagdollManager *this)
{
  return &g_CRagdollManager_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x101F1B30
// Name: public: virtual struct datamap_t __near * CRagdollManager::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CRagdollManager::GetDataDescMap(CRagdollManager *this)
{
  return &CRagdollManager::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101F1B40
// Name: public: virtual int CRagdollManager::DrawDebugTextOverlays(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRagdollManager::DrawDebugTextOverlays(CRagdollManager *this)
{
  int result; // eax
  int v3; // edi
  char tempstr[512]; // [esp+1Ch] [ebp-200h] BYREF

  result = CBaseEntity::DrawDebugTextOverlays(this);
  v3 = result;
  if ( (this->m_debugOverlays & 1) != 0 )
  {
    V_snprintf(pDest: tempstr, maxLen: 512, pFormat: "max ragdoll count: %d", this->m_iCurrentMaxRagdollCount.m_Value);
    CBaseEntity::EntityText(this, text_offset: v3, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
    return v3 + 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F1C40
// Name: public: CRagdollManager::CRagdollManager(void)
// Source: json
//------------------------------------------------------------------------------
CRagdollManager *__thiscall CRagdollManager::CRagdollManager(CRagdollManager *this)
{
  CRagdollManager *result; // eax
  edict_t *m_pPev; // ecx

  CBaseEntity::CBaseEntity(this, bServerOnly: false);
  this->__vftable = (CRagdollManager_vtbl *)&CRagdollManager::`vftable';
  this->m_iMaxRagdollCount = -1;
  result = this;
  if ( this->m_iCurrentMaxRagdollCount.m_Value != -1 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_iCurrentMaxRagdollCount.m_Value = -1;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x354u);
      this->m_iCurrentMaxRagdollCount.m_Value = -1;
      return this;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F1CB0
// Name: public: void CRagdollManager::InputSetMaxRagdollCount(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRagdollManager::InputSetMaxRagdollCount(CRagdollManager *this, inputdata_t *inputdata)
{
  const char *pszValue; // eax
  edict_t *m_pPev; // ecx
  int m_iMaxRagdollCount; // eax

  if ( inputdata->value.fieldType == FIELD_INTEGER )
    pszValue = inputdata->value.iszVal.pszValue;
  else
    pszValue = nullptr;
  this->m_iMaxRagdollCount = (int)pszValue;
  if ( this->m_iCurrentMaxRagdollCount.m_Value == this->m_iMaxRagdollCount )
  {
    s_RagdollLRU.m_iMaxRagdolls = this->m_iCurrentMaxRagdollCount.m_Value;
  }
  else
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x354u);
    }
    m_iMaxRagdollCount = this->m_iMaxRagdollCount;
    this->m_iCurrentMaxRagdollCount.m_Value = m_iMaxRagdollCount;
    s_RagdollLRU.m_iMaxRagdolls = m_iMaxRagdollCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F1D30
// Name: public: virtual void CRagdollManager::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRagdollManager::Activate(CRagdollManager *this)
{
  edict_t *m_pPev; // ecx
  int m_iMaxRagdollCount; // eax

  CBaseEntity::Activate(this);
  if ( this->m_iCurrentMaxRagdollCount.m_Value == this->m_iMaxRagdollCount )
  {
    s_RagdollLRU.m_iMaxRagdolls = this->m_iCurrentMaxRagdollCount.m_Value;
  }
  else
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x354u);
    }
    m_iMaxRagdollCount = this->m_iMaxRagdollCount;
    this->m_iCurrentMaxRagdollCount.m_Value = m_iMaxRagdollCount;
    s_RagdollLRU.m_iMaxRagdolls = m_iMaxRagdollCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104094C0
// Name: DT_RagdollManager::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_RagdollManager::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_RagdollManager::g_SendTable);
  return atexit(func: DT_RagdollManager::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104094E0
// Name: DT_RagdollManager::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_RagdollManager::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_RagdollManager::ignored>();
  DT_RagdollManager::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10409510
// Name: CRagdollManager_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CRagdollManager_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CRagdollManager>();
  CRagdollManager_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041DA50
// Name: DT_RagdollManager::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_RagdollManager::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_RagdollManager::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10409520
// Name: _dynamic_initializer_for__g_ragdoll_maxcount__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ragdoll_maxcount__()
{
  ConVar::ConVar(this: &g_ragdoll_maxcount, pName: "g_ragdoll_maxcount", pDefaultValue: "8", flags: 0x2000);
  return atexit(func: dynamic_atexit_destructor_for__g_ragdoll_maxcount__);
}

//------------------------------------------------------------------------------
// Address: 0x10409550
// Name: _dynamic_initializer_for__g_debug_ragdoll_removal__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_debug_ragdoll_removal__()
{
  ConVar::ConVar(this: &g_debug_ragdoll_removal, pName: "g_debug_ragdoll_removal", pDefaultValue: "0", flags: 24576);
  return atexit(func: dynamic_atexit_destructor_for__g_debug_ragdoll_removal__);
}

//------------------------------------------------------------------------------
// Address: 0x10409580
// Name: _dynamic_initializer_for__s_RagdollLRU__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_RagdollLRU__()
{
  CRagdollLRURetirement::CRagdollLRURetirement(this: &s_RagdollLRU, name: "CRagdollLRURetirement");
  return atexit(func: dynamic_atexit_destructor_for__s_RagdollLRU__);
}

//------------------------------------------------------------------------------
// Address: 0x104095A0
// Name: _dynamic_initializer_for__g_ragdoll_important_maxcount__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ragdoll_important_maxcount__()
{
  ConVar::ConVar(
    this: &g_ragdoll_important_maxcount,
    pName: "g_ragdoll_important_maxcount",
    pDefaultValue: "2",
    flags: 0x2000);
  return atexit(func: dynamic_atexit_destructor_for__g_ragdoll_important_maxcount__);
}

//------------------------------------------------------------------------------
// Address: 0x1041DA60
// Name: _ServerClassInit_DT_RagdollManager::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_RagdollManager::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_191;
  for ( i = 1; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041DA80
// Name: _DataMapInit_CRagdollManager__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CRagdollManager__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_363);
}

//------------------------------------------------------------------------------
// Address: 0x1041DA90
// Name: _dynamic_atexit_destructor_for__g_ragdoll_maxcount__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ragdoll_maxcount__()
{
  ConVar::~ConVar(this: &g_ragdoll_maxcount);
}

//------------------------------------------------------------------------------
// Address: 0x1041DAA0
// Name: _dynamic_atexit_destructor_for__g_debug_ragdoll_removal__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_debug_ragdoll_removal__()
{
  ConVar::~ConVar(this: &g_debug_ragdoll_removal);
}

//------------------------------------------------------------------------------
// Address: 0x1041DAB0
// Name: _dynamic_atexit_destructor_for__g_ragdoll_important_maxcount__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ragdoll_important_maxcount__()
{
  ConVar::~ConVar(this: &g_ragdoll_important_maxcount);
}

//------------------------------------------------------------------------------
// Address: 0x1041DAC0
// Name: _dynamic_atexit_destructor_for__s_RagdollLRU__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_RagdollLRU__()
{
  CRagdollLRURetirement::~CRagdollLRURetirement(this: &s_RagdollLRU);
}

//------------------------------------------------------------------------------
// Address: 0x1041DAD0
// Name: _DataMapInit_CRagdollBoogie__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CRagdollBoogie__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_364);
}

//------------------------------------------------------------------------------
// Address: 0x1041DAE0
// Name: _dynamic_atexit_destructor_for__g_RecipientFilterPredictionSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_RecipientFilterPredictionSystem__()
{
  g_RecipientFilterPredictionSystem.__vftable = (IPredictionSystem_vtbl *)&IPredictionSystem::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1041DAF0
// Name: _dynamic_atexit_destructor_for__g_Registry__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_Registry__()
{
  g_Registry.__vftable = (CRegistry_vtbl *)&CRegistry::`vftable';
}
