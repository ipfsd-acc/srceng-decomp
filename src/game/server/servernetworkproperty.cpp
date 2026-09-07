// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/servernetworkproperty.cpp
// Functions: 21
// ============================================================

#include "game\server\servernetworkproperty.h"

//------------------------------------------------------------------------------
// Address: 0x10212910
// Name: public: virtual struct datamap_t __near * CServerNetworkProperty::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CServerNetworkProperty::GetDataDescMap(CServerNetworkProperty *this)
{
  return &CServerNetworkProperty::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10212920
// Name: public: void CServerNetworkProperty::Init(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerNetworkProperty::Init(CServerNetworkProperty *this, CBaseEntity *pEntity)
{
  *((_BYTE *)this + 76) &= ~1u;
  this->m_pPev = nullptr;
  this->m_pServerClass = nullptr;
  this->m_PVSInfo.m_nClusterCount = 0;
  this->m_pOuter = pEntity;
  CEventRegister::Init(
    this: &this->m_TimerEvent,
    pMgr: &g_NetworkPropertyEventMgr,
    pCallback: &this->IEventRegisterCallback);
}

//------------------------------------------------------------------------------
// Address: 0x10212950
// Name: public: void CServerNetworkProperty::CacheServerClass(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerNetworkProperty::CacheServerClass(CServerNetworkProperty *this)
{
  this->m_pServerClass = this->m_pOuter->GetServerClass(this: this->m_pOuter);
}

//------------------------------------------------------------------------------
// Address: 0x10212970
// Name: public: virtual void CServerNetworkProperty::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerNetworkProperty::Release(CServerNetworkProperty *this)
{
  CBaseEntity *m_pOuter; // ecx

  m_pOuter = this->m_pOuter;
  if ( m_pOuter != nullptr )
    ((void (__thiscall *)(CBaseEntity *, int))m_pOuter->dtr_IHandleEntity)(a1: m_pOuter, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10212980
// Name: public: virtual class ServerClass __near * CServerNetworkProperty::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CServerNetworkProperty::GetServerClass(CServerNetworkProperty *this)
{
  return this->m_pServerClass;
}

//------------------------------------------------------------------------------
// Address: 0x10212990
// Name: public: bool CServerNetworkProperty::IsInPVS(class CCheckTransmitInfo const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CServerNetworkProperty::IsInPVS(CServerNetworkProperty *this, const CCheckTransmitInfo *pInfo)
{
  int v3; // edi
  bool v4; // zf
  int *m_Areas; // esi
  int v6; // edx
  int m_nAreaNum; // eax
  int v8; // esi
  __int16 m_nClusterCount; // ax
  int v11; // esi
  unsigned __int16 *i; // edi
  CServerNetworkProperty *v13; // [esp+Ch] [ebp-4h]
  int *pInfoa; // [esp+18h] [ebp+8h]

  v3 = 0;
  v13 = this;
  if ( this->m_PVSInfo.m_nAreaNum2 != 0 )
  {
    v4 = pInfo->m_AreasNetworked == 0;
    if ( pInfo->m_AreasNetworked > 0 )
    {
      pInfoa = pInfo->m_Areas;
      while ( 1 )
      {
        m_nAreaNum = this->m_PVSInfo.m_nAreaNum;
        v8 = *pInfoa;
        if ( *pInfoa == m_nAreaNum || v8 == this->m_PVSInfo.m_nAreaNum2 )
          goto LABEL_17;
        if ( engine->CheckAreasConnected(this: engine, a2: v8, a3: m_nAreaNum) != 0
          || ((int (__stdcall *)(int, _DWORD))engine->CheckAreasConnected)(a1: v8, a2: v13->m_PVSInfo.m_nAreaNum2) != 0
          || (++pInfoa, ++v3, v3 >= pInfo->m_AreasNetworked) )
        {
LABEL_16:
          this = v13;
          goto LABEL_17;
        }
        this = v13;
      }
    }
  }
  else
  {
    v4 = pInfo->m_AreasNetworked == 0;
    if ( pInfo->m_AreasNetworked > 0 )
    {
      m_Areas = pInfo->m_Areas;
      do
      {
        v6 = this->m_PVSInfo.m_nAreaNum;
        if ( *m_Areas == v6 )
          break;
        if ( engine->CheckAreasConnected(this: engine, a2: *m_Areas, a3: v6) != 0 )
          goto LABEL_16;
        this = v13;
        ++v3;
        ++m_Areas;
      }
      while ( v3 < pInfo->m_AreasNetworked );
LABEL_17:
      v4 = v3 == pInfo->m_AreasNetworked;
    }
  }
  if ( v4 )
    return false;
  m_nClusterCount = this->m_PVSInfo.m_nClusterCount;
  if ( m_nClusterCount < 0 )
    return engine->CheckHeadnodeVisible(
             this: engine,
             a2: this->m_PVSInfo.m_nHeadNode,
             a3: pInfo->m_PVS,
             a4: pInfo->m_nPVSSize) != 0;
  v11 = m_nClusterCount - 1;
  if ( v11 < 0 )
    return false;
  for ( i = &this->m_PVSInfo.m_pClusters[v11]; ((unsigned __int8)(1 << (*i & 7)) & pInfo->m_PVS[(int)*i >> 3]) == 0; --i )
  {
    if ( --v11 < 0 )
      return false;
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x10212AF0
// Name: public: void CServerNetworkProperty::SetUpdateInterval(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerNetworkProperty::SetUpdateInterval(CServerNetworkProperty *this, CEventRegister *val)
{
  if ( *(float *)&val == 0.0 )
    CEventRegister::StopUpdates(this: &this->m_TimerEvent);
  else
    CEventRegister::SetUpdateInterval(this: &this->m_TimerEvent, interval: val);
}

//------------------------------------------------------------------------------
// Address: 0x10212B60
// Name: public: CServerNetworkProperty::CServerNetworkProperty(void)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CServerNetworkProperty::CServerNetworkProperty(CServerNetworkProperty *this)
{
  IEventRegisterCallback *v2; // edi

  v2 = &this->IEventRegisterCallback;
  this->IEventRegisterCallback::__vftable = (IEventRegisterCallback_vtbl *)&IEventRegisterCallback::`vftable';
  this->IServerNetworkable::__vftable = (CServerNetworkProperty_vtbl *)&CServerNetworkProperty::`vftable'{for `IServerNetworkable'};
  this->IEventRegisterCallback::__vftable = (IEventRegisterCallback_vtbl *)&CServerNetworkProperty::`vftable'{for `IEventRegisterCallback'};
  this->m_hParent.m_Index = -1;
  CEventRegister::CEventRegister(this: &this->m_TimerEvent);
  *((_BYTE *)this + 76) &= ~1u;
  this->m_pPev = nullptr;
  this->m_pOuter = nullptr;
  this->m_pServerClass = nullptr;
  this->m_PVSInfo.m_nClusterCount = 0;
  CEventRegister::Init(this: &this->m_TimerEvent, pMgr: &g_NetworkPropertyEventMgr, pCallback: v2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10212BB0
// Name: public: virtual struct PVSInfo_t __near * CServerNetworkProperty::GetPVSInfo(void)
// Source: json
//------------------------------------------------------------------------------
PVSInfo_t *__thiscall CServerNetworkProperty::GetPVSInfo(CServerNetworkProperty *this)
{
  return &this->m_PVSInfo;
}

//------------------------------------------------------------------------------
// Address: 0x10212BC0
// Name: public: void CServerNetworkProperty::AttachEdict(struct edict_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerNetworkProperty::AttachEdict(CServerNetworkProperty *this, edict_t *pRequiredEdict)
{
  edict_t *v2; // eax
  CBaseEntity *v4; // eax
  edict_t *m_pPev; // esi

  v2 = pRequiredEdict;
  if ( pRequiredEdict == nullptr )
    v2 = engine->CreateEdict(this: engine, a2: -1);
  this->m_pPev = v2;
  v4 = this->GetBaseEntity(this);
  m_pPev = this->m_pPev;
  m_pPev->m_pUnk = v4;
  m_pPev->m_fStateFlags = v4 != nullptr ? 4 : 0;
}

//------------------------------------------------------------------------------
// Address: 0x10212C00
// Name: public: class CServerNetworkProperty __near * CServerNetworkProperty::GetNetworkParent(void)
// Source: json
//------------------------------------------------------------------------------
IHandleEntity *__thiscall CServerNetworkProperty::GetNetworkParent(CServerNetworkProperty *this)
{
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx

  m_Index = this->m_hParent.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && (m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity) != nullptr )
  {
    return m_pEntity + 3;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10212C40
// Name: public: void CServerNetworkProperty::MarkForDeletion(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerNetworkProperty::MarkForDeletion(CServerNetworkProperty *this)
{
  this->m_pOuter->m_iEFlags |= 1u;
}

//------------------------------------------------------------------------------
// Address: 0x10212C50
// Name: public: bool CServerNetworkProperty::IsMarkedForDeletion(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CServerNetworkProperty::IsMarkedForDeletion(CServerNetworkProperty *this)
{
  return this->m_pOuter->m_iEFlags & 1;
}

//------------------------------------------------------------------------------
// Address: 0x10212C60
// Name: public: void CServerNetworkProperty::RecomputePVSInformation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerNetworkProperty::RecomputePVSInformation(CServerNetworkProperty *this)
{
  edict_t *m_pPev; // ecx

  m_pPev = this->m_pPev;
  if ( m_pPev != nullptr && SLOBYTE(m_pPev->m_fStateFlags) < 0 )
  {
    m_pPev->m_fStateFlags &= ~0x80u;
    engine->BuildEntityClusterList(this: engine, a2: this->m_pPev, a3: &this->m_PVSInfo);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10212C90
// Name: public: virtual char const __near * CServerNetworkProperty::GetClassName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CServerNetworkProperty::GetClassName(CServerNetworkProperty *this)
{
  const char *result; // eax

  result = this->m_pOuter->m_iClassname.pszValue;
  if ( result == nullptr )
    return locale;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10212CA0
// Name: public: bool CServerNetworkProperty::IsInPVS(struct edict_t const __near *,void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CServerNetworkProperty::IsInPVS(
        CServerNetworkProperty *this,
        const edict_t *pRecipient,
        _BYTE *pvs,
        int pvssize)
{
  edict_t *m_pPev; // eax
  __int16 m_nClusterCount; // ax
  int v8; // edi
  unsigned __int16 *i; // esi

  m_pPev = this->m_pPev;
  if ( m_pPev != nullptr && SLOBYTE(m_pPev->m_fStateFlags) < 0 )
  {
    m_pPev->m_fStateFlags &= ~0x80u;
    engine->BuildEntityClusterList(this: engine, a2: this->m_pPev, a3: &this->m_PVSInfo);
  }
  m_nClusterCount = this->m_PVSInfo.m_nClusterCount;
  if ( m_nClusterCount < 0 )
    return ((int (__stdcall *)(_DWORD, _BYTE *, int))engine->CheckHeadnodeVisible)(
             a1: this->m_PVSInfo.m_nHeadNode,
             a2: pvs,
             a3: pvssize) != 0;
  v8 = 0;
  if ( m_nClusterCount <= 0 )
    return false;
  for ( i = this->m_PVSInfo.m_pClusters; ((unsigned __int8)(1 << (*i & 7)) & pvs[*i >> 3]) == 0; ++i )
  {
    if ( ++v8 >= m_nClusterCount )
      return false;
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x10212D50
// Name: public: virtual int CServerNetworkProperty::AreaNum(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CServerNetworkProperty::AreaNum(CServerNetworkProperty *this)
{
  edict_t *m_pPev; // eax

  m_pPev = this->m_pPev;
  if ( m_pPev != nullptr && SLOBYTE(m_pPev->m_fStateFlags) < 0 )
  {
    m_pPev->m_fStateFlags &= ~0x80u;
    engine->BuildEntityClusterList(this: engine, a2: this->m_pPev, a3: &this->m_PVSInfo);
  }
  return this->m_PVSInfo.m_nAreaNum;
}

//------------------------------------------------------------------------------
// Address: 0x10212D90
// Name: public: virtual CServerNetworkProperty::~CServerNetworkProperty(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerNetworkProperty::~CServerNetworkProperty(CServerNetworkProperty *this)
{
  edict_t *m_pPev; // eax

  this->IServerNetworkable::__vftable = (CServerNetworkProperty_vtbl *)&CServerNetworkProperty::`vftable'{for `IServerNetworkable'};
  this->IEventRegisterCallback::__vftable = (IEventRegisterCallback_vtbl *)&CServerNetworkProperty::`vftable'{for `IEventRegisterCallback'};
  engine->CleanUpEntityClusterList(this: engine, a2: &this->m_PVSInfo);
  m_pPev = this->m_pPev;
  if ( m_pPev != nullptr )
  {
    m_pPev->m_pUnk = nullptr;
    m_pPev->m_fStateFlags = 0;
    engine->RemoveEdict(this: engine, a2: this->m_pPev);
    this->m_pPev = nullptr;
  }
  CEventRegister::~CEventRegister(this: &this->m_TimerEvent);
  this->IServerNetworkable::__vftable = (CServerNetworkProperty_vtbl *)&IServerNetworkable::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10212DF0
// Name: public: virtual void CServerNetworkProperty::FireEvent(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerNetworkProperty::FireEvent(CServerNetworkProperty *this)
{
  CBaseEdict *m_pOuter; // ecx

  if ( this->m_TimerEvent.m_bRegistered )
  {
    m_pOuter = (CBaseEdict *)this->m_pOuter;
    m_pOuter->m_fStateFlags |= 0x101u;
    CBaseEdict::GetChangeAccessor(this: m_pOuter)->m_iChangeInfoSerialNumber = 0;
    this->m_TimerEvent.m_bRegistered &= ~1u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10409C70
// Name: CServerNetworkProperty_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CServerNetworkProperty_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CServerNetworkProperty>(__formal: nullptr);
  CServerNetworkProperty_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10212E50
// Name: struct datamap_t __near * DataMapInit<class CServerNetworkProperty>(class CServerNetworkProperty __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CServerNetworkProperty>()
{
  if ( (_S2_198 & 1) == 0 )
  {
    _S2_198 |= 1u;
    nameHolder_376.m_pszBase = "CServerNetworkProperty";
    nameHolder_376.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_376.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_376.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_376.m_Names.m_Size = 0;
    nameHolder_376.m_Names.m_pElements = nullptr;
    nameHolder_376.m_nLenBase = 22;
    atexit(func: DataMapInit_CServerNetworkProperty__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CServerNetworkProperty::m_DataMap.baseMap = nullptr;
  CServerNetworkProperty::m_DataMap.dataNumFields = 1;
  CServerNetworkProperty::m_DataMap.dataDesc = &dataDesc_359[1];
  return &CServerNetworkProperty::m_DataMap;
}
