// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/steamjet.cpp
// Functions: 831
// ============================================================

#include "game\server\steamjet.h"

//------------------------------------------------------------------------------
// Address: 0x10042900
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CAssaultPoint>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CAssaultPoint>::Create(
        CEntityFactory<CAssaultPoint> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CAssaultPoint>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10042A20
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CRallyPoint>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CRallyPoint>::Create(
        CEntityFactory<CRallyPoint> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CRallyPoint>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x100438A0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CAI_AssaultGoal>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IServerNetworkable *__thiscall CEntityFactory<CAI_AssaultGoal>::Create(
        CEntityFactory<CAI_AssaultGoal> *this,
        const char *pClassName)
{
  CAI_GoalEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CAI_GoalEntity *)CBaseEntity::operator new(stAllocateBlock: 0x398u);
  v3 = &v2->CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
  if ( v2 != nullptr )
  {
    CAI_GoalEntity::CAI_GoalEntity(this: v2);
    *v3 = &CAI_AssaultGoal::`vftable'{for `CBaseEntity'};
    v3[213] = &CAI_AssaultGoal::`vftable'{for `IEntityListener'};
  }
  else
  {
    v3 = nullptr;
  }
  (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: pClassName);
  return (IServerNetworkable *)(v3 + 3);
}

//------------------------------------------------------------------------------
// Address: 0x100448C0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CAI_FightFromCoverGoal>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CAI_FightFromCoverGoal>::Create(
        CEntityFactory<CAI_FightFromCoverGoal> *this,
        const char *pClassName)
{
  CAI_FightFromCoverGoal *v2; // eax
  CAI_FightFromCoverGoal *v3; // esi

  v2 = (CAI_FightFromCoverGoal *)CBaseEntity::operator new(stAllocateBlock: 0x3BCu);
  if ( v2 != nullptr )
    v3 = CAI_FightFromCoverGoal::CAI_FightFromCoverGoal(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10046730
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CAI_FollowGoal>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IServerNetworkable *__thiscall CEntityFactory<CAI_FollowGoal>::Create(
        CEntityFactory<CAI_FollowGoal> *this,
        const char *pClassName)
{
  CAI_GoalEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CAI_GoalEntity *)CBaseEntity::operator new(stAllocateBlock: 0x38Cu);
  v3 = &v2->CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
  if ( v2 != nullptr )
  {
    CAI_GoalEntity::CAI_GoalEntity(this: v2);
    *v3 = &CAI_FollowGoal::`vftable'{for `CBaseEntity'};
    v3[213] = &CAI_FollowGoal::`vftable'{for `IEntityListener'};
  }
  else
  {
    v3 = nullptr;
  }
  (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: pClassName);
  return (IServerNetworkable *)(v3 + 3);
}

//------------------------------------------------------------------------------
// Address: 0x10047800
// Name: public: virtual unsigned int CEntityFactory<class CAI_LeadGoal>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CAI_LeadGoal>::GetEntitySize(CEntityFactory<CAI_LeadGoal> *this)
{
  return 1108;
}

//------------------------------------------------------------------------------
// Address: 0x10047810
// Name: public: virtual unsigned int CEntityFactory<class CAI_LeadGoal_Weapon>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CAI_LeadGoal_Weapon>::GetEntitySize(CEntityFactory<CAI_LeadGoal_Weapon> *this)
{
  return 1116;
}

//------------------------------------------------------------------------------
// Address: 0x10048220
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CAI_LeadGoal>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CAI_LeadGoal>::Create(
        CEntityFactory<CAI_LeadGoal> *this,
        const char *pClassName)
{
  CAI_LeadGoal *v2; // eax
  CAI_LeadGoal *v3; // esi

  v2 = (CAI_LeadGoal *)CBaseEntity::operator new(stAllocateBlock: 0x454u);
  if ( v2 != nullptr )
    v3 = CAI_LeadGoal::CAI_LeadGoal(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10048330
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CAI_LeadGoal_Weapon>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CAI_LeadGoal_Weapon>::Create(
        CEntityFactory<CAI_LeadGoal_Weapon> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CAI_LeadGoal_Weapon>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x100485E0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CRopeAnchor>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IServerNetworkable *__thiscall CEntityFactory<CRopeAnchor>::Create(
        CEntityFactory<CRopeAnchor> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x358u);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    *v3 = &CRopeAnchor::`vftable';
    v3[213] = -1;
  }
  else
  {
    v3 = nullptr;
  }
  (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: pClassName);
  return (IServerNetworkable *)(v3 + 3);
}

//------------------------------------------------------------------------------
// Address: 0x10048A40
// Name: public: virtual void CEntityFactory<class CItemNvgs>::Destroy(class IServerNetworkable __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityFactory<CItemNvgs>::Destroy(
        CEntityFactory<CAI_AssaultGoal> *this,
        IServerNetworkable *pNetworkable)
{
  if ( pNetworkable != nullptr )
    pNetworkable->Release(this: pNetworkable);
}

//------------------------------------------------------------------------------
// Address: 0x10049030
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CAI_BattleLine>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CAI_BattleLine>::Create(
        CEntityFactory<CAI_BattleLine> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CAI_BattleLine>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x100493A0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CAI_StandoffGoal>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CAI_StandoffGoal>::Create(
        CEntityFactory<CAI_StandoffGoal> *this,
        const char *pClassName)
{
  CAI_StandoffGoal *v2; // eax
  CAI_StandoffGoal *v3; // esi

  v2 = (CAI_StandoffGoal *)CBaseEntity::operator new(stAllocateBlock: 0x3B8u);
  if ( v2 != nullptr )
    v3 = CAI_StandoffGoal::CAI_StandoffGoal(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1004CE40
// Name: struct datamap_t __near * DataMapInit<struct ResponseRules::ResponseParams>(struct ResponseRules::ResponseParams __near *)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<ResponseRules::ResponseParams>()
{
  if ( (_S2_14 & 1) == 0 )
  {
    _S2_14 |= 1u;
    nameHolder_38.m_pszBase = "AI_ResponseParams";
    nameHolder_38.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_38.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_38.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_38.m_Names.m_Size = 0;
    nameHolder_38.m_Names.m_pElements = nullptr;
    nameHolder_38.m_nLenBase = 17;
    atexit(func: DataMapInit_ResponseRules::ResponseParams__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  ResponseRules::ResponseParams::m_DataMap.baseMap = nullptr;
  ResponseRules::ResponseParams::m_DataMap.dataNumFields = 5;
  ResponseRules::ResponseParams::m_DataMap.dataDesc = &dataDesc_37[1];
  return &ResponseRules::ResponseParams::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1004CEC0
// Name: struct datamap_t __near * DataMapInit<class ResponseRules::CRR_Response>(class ResponseRules::CRR_Response __near *)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<ResponseRules::CRR_Response>()
{
  if ( (_S3_9 & 1) == 0 )
  {
    _S3_9 |= 1u;
    nameHolder_39.m_pszBase = "AI_Response";
    nameHolder_39.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_39.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_39.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_39.m_Names.m_Size = 0;
    nameHolder_39.m_Names.m_pElements = nullptr;
    nameHolder_39.m_nLenBase = 11;
    atexit(func: DataMapInit_ResponseRules::CRR_Response__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  ResponseRules::CRR_Response::m_DataMap.baseMap = nullptr;
  ResponseRules::CRR_Response::m_DataMap.dataNumFields = 4;
  ResponseRules::CRR_Response::m_DataMap.dataDesc = &dataDesc_38[1];
  return &ResponseRules::CRR_Response::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1004EBE0
// Name: public: virtual unsigned int CEntityFactory<class CFuncMonitor>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CFuncMonitor>::GetEntitySize(CEntityFactory<CAI_RadialLinkController> *this)
{
  return 872;
}

//------------------------------------------------------------------------------
// Address: 0x1004F000
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CAI_DynamicLink>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CAI_DynamicLink>::Create(
        CEntityFactory<CAI_DynamicLink> *this,
        const char *pClassName)
{
  CAI_DynamicLink *v2; // eax
  CAI_DynamicLink *v3; // esi

  v2 = (CAI_DynamicLink *)CBaseEntity::operator new(stAllocateBlock: 0x37Cu);
  if ( v2 != nullptr )
    v3 = CAI_DynamicLink::CAI_DynamicLink(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1004F5A0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CAI_RadialLinkController>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CAI_RadialLinkController>::Create(
        CEntityFactory<CAI_RadialLinkController> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x368u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CAI_RadialLinkController::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10050190
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CAI_DynamicLinkController>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CAI_DynamicLinkController>::Create(
        CEntityFactory<CAI_DynamicLinkController> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CAI_DynamicLinkController>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10053D80
// Name: public: virtual unsigned int CEntityFactory<class CAI_Hint>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CAI_Hint>::GetEntitySize(CEntityFactory<CAI_Hint> *this)
{
  return 992;
}

//------------------------------------------------------------------------------
// Address: 0x10055D40
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CAI_Hint>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CAI_Hint>::Create(
        CEntityFactory<CAI_Hint> *this,
        const char *pClassName)
{
  CAI_Hint *v2; // eax
  CAI_Hint *v3; // esi

  v2 = (CAI_Hint *)CBaseEntity::operator new(stAllocateBlock: 0x3E0u);
  if ( v2 != nullptr )
    v3 = CAI_Hint::CAI_Hint(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10057350
// Name: public: virtual unsigned int CEntityFactory<class CNodeEnt>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CNodeEnt>::GetEntitySize(CEntityFactory<CNodeEnt> *this)
{
  return 916;
}

//------------------------------------------------------------------------------
// Address: 0x10057360
// Name: public: virtual unsigned int CEntityFactory<class CAI_TestHull>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CAI_TestHull>::GetEntitySize(CEntityFactory<CAI_TestHull> *this)
{
  return 3720;
}

//------------------------------------------------------------------------------
// Address: 0x10057500
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CAI_TestHull>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CAI_TestHull>::Create(
        CEntityFactory<CAI_TestHull> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CAI_TestHull>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x100575C0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CNodeEnt>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IServerNetworkable *__thiscall CEntityFactory<CNodeEnt>::Create(CEntityFactory<CNodeEnt> *this, const char *pClassName)
{
  CBaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x394u);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: true);
    *v3 = &CNodeEnt::`vftable';
    v3[201] = 0;
  }
  else
  {
    v3 = nullptr;
  }
  (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: pClassName);
  return (IServerNetworkable *)(v3 + 3);
}

//------------------------------------------------------------------------------
// Address: 0x1006E530
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CAI_NetworkManager>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CAI_NetworkManager>::Create(
        CEntityFactory<CAI_NetworkManager> *this,
        const char *pClassName)
{
  CAI_NetworkManager *v2; // eax
  CAI_NetworkManager *v3; // esi

  v2 = (CAI_NetworkManager *)CBaseEntity::operator new(stAllocateBlock: 0x390u);
  if ( v2 != nullptr )
    v3 = CAI_NetworkManager::CAI_NetworkManager(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1007CAB0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CAI_AllySpeechManager>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CAI_AllySpeechManager>::Create(
        CEntityFactory<CAI_AllySpeechManager> *this,
        const char *pClassName)
{
  CAI_AllySpeechManager *v2; // eax
  CAI_AllySpeechManager *v3; // esi

  v2 = (CAI_AllySpeechManager *)CBaseEntity::operator new(stAllocateBlock: 0x378u);
  if ( v2 != nullptr )
    v3 = CAI_AllySpeechManager::CAI_AllySpeechManager(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1007FBE0
// Name: struct datamap_t __near * DataMapInit<struct ResponseRules::ParserResponse>(struct ResponseRules::ParserResponse __near *)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<ResponseRules::ParserResponse>()
{
  if ( (_S2_29 & 1) == 0 )
  {
    _S2_29 |= 1u;
    nameHolder_59.m_pszBase = "ParserResponse";
    nameHolder_59.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_59.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_59.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_59.m_Names.m_Size = 0;
    nameHolder_59.m_Names.m_pElements = nullptr;
    nameHolder_59.m_nLenBase = 14;
    atexit(func: DataMapInit_ResponseRules::ParserResponse__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  ResponseRules::ParserResponse::m_DataMap.baseMap = nullptr;
  ResponseRules::ParserResponse::m_DataMap.dataNumFields = 1;
  ResponseRules::ParserResponse::m_DataMap.dataDesc = &dataDesc_57[1];
  return &ResponseRules::ParserResponse::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1007FC60
// Name: struct datamap_t __near * DataMapInit<struct ResponseRules::ResponseGroup>(struct ResponseRules::ResponseGroup __near *)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<ResponseRules::ResponseGroup>()
{
  if ( (_S3_14 & 1) == 0 )
  {
    _S3_14 |= 1u;
    nameHolder_60.m_pszBase = "ResponseGroup";
    nameHolder_60.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_60.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_60.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_60.m_Names.m_Size = 0;
    nameHolder_60.m_Names.m_pElements = nullptr;
    nameHolder_60.m_nLenBase = 13;
    atexit(func: DataMapInit_ResponseRules::ResponseGroup__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  ResponseRules::ResponseGroup::m_DataMap.baseMap = nullptr;
  ResponseRules::ResponseGroup::m_DataMap.dataNumFields = 3;
  ResponseRules::ResponseGroup::m_DataMap.dataDesc = &dataDesc_58[1];
  return &ResponseRules::ResponseGroup::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10083530
// Name: public: virtual unsigned int CEntityFactory<class CAI_ScriptConditions>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CAI_ScriptConditions>::GetEntitySize(CEntityFactory<CAI_ScriptConditions> *this)
{
  return 1088;
}

//------------------------------------------------------------------------------
// Address: 0x10085650
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CAI_ScriptConditions>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CAI_ScriptConditions>::Create(
        CEntityFactory<CAI_ScriptConditions> *this,
        const char *pClassName)
{
  CAI_ScriptConditions *v2; // eax
  CAI_ScriptConditions *v3; // esi

  v2 = (CAI_ScriptConditions *)CBaseEntity::operator new(stAllocateBlock: 0x440u);
  if ( v2 != nullptr )
    v3 = CAI_ScriptConditions::CAI_ScriptConditions(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1008A480
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CAI_SpeechFilter>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CAI_SpeechFilter>::Create(
        CEntityFactory<CAI_SpeechFilter> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CAI_SpeechFilter>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10091E10
// Name: public: virtual unsigned int CEntityFactory<class CAmbientGeneric>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CAmbientGeneric>::GetEntitySize(CEntityFactory<CAmbientGeneric> *this)
{
  return 984;
}

//------------------------------------------------------------------------------
// Address: 0x10092370
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CAmbientGeneric>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IServerNetworkable *__thiscall CEntityFactory<CAmbientGeneric>::Create(
        CEntityFactory<CAmbientGeneric> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x3D8u);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    *v3 = &CAmbientGeneric::`vftable';
    v3[244] = -1;
  }
  else
  {
    v3 = nullptr;
  }
  (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: pClassName);
  return (IServerNetworkable *)(v3 + 3);
}

//------------------------------------------------------------------------------
// Address: 0x100CF8F0
// Name: public: virtual unsigned int CEntityFactory<class CBaseFlex>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CBaseFlex>::GetEntitySize(CEntityFactory<CBaseFlex> *this)
{
  return 1664;
}

//------------------------------------------------------------------------------
// Address: 0x100CF900
// Name: public: virtual unsigned int CEntityFactory<class CGenericFlexCycler>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CGenericFlexCycler>::GetEntitySize(CEntityFactory<CGenericFlexCycler> *this)
{
  return 1968;
}

//------------------------------------------------------------------------------
// Address: 0x100D4E00
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CBaseFlex>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CBaseFlex>::Create(
        CEntityFactory<CBaseFlex> *this,
        const char *pClassName)
{
  CBaseFlex *v2; // eax
  CBaseFlex *v3; // esi

  v2 = (CBaseFlex *)CBaseEntity::operator new(stAllocateBlock: 0x680u);
  if ( v2 != nullptr )
    v3 = CBaseFlex::CBaseFlex(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x100D5720
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CGenericFlexCycler>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CGenericFlexCycler>::Create(
        CEntityFactory<CGenericFlexCycler> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CGenericFlexCycler>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x100D5BA0
// Name: public: virtual unsigned int CEntityFactory<class CBaseGrenade>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CBaseGrenade>::GetEntitySize(CEntityFactory<CBaseGrenade> *this)
{
  return 1204;
}

//------------------------------------------------------------------------------
// Address: 0x100D7710
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CBaseGrenade>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CBaseGrenade>::Create(
        CEntityFactory<CBaseGrenade> *this,
        const char *pClassName)
{
  CBaseGrenade *v2; // eax
  CBaseGrenade *v3; // esi

  v2 = (CBaseGrenade *)CBaseEntity::operator new(stAllocateBlock: 0x4B4u);
  if ( v2 != nullptr )
    v3 = CBaseGrenade::CBaseGrenade(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x100DE140
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CBaseViewModel>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CBaseViewModel>::Create(
        CEntityFactory<CBaseViewModel> *this,
        const char *pClassName)
{
  CBaseViewModel *v2; // eax
  CBaseViewModel *v3; // esi

  v2 = (CBaseViewModel *)CBaseEntity::operator new(stAllocateBlock: 0x4D0u);
  if ( v2 != nullptr )
    v3 = CBaseViewModel::CBaseViewModel(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x100DE590
// Name: public: virtual unsigned int CEntityFactory<class CFuncTrain>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CFuncTrain>::GetEntitySize(CEntityFactory<CBeam> *this)
{
  return 1020;
}

//------------------------------------------------------------------------------
// Address: 0x100DF3F0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CInfoTarget>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CInfoTarget>::Create(
        CEntityFactory<CInfoTarget> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x354u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CInfoTarget::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x100DFC40
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CBeam>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CBeam>::Create(CEntityFactory<CBeam> *this, const char *pClassName)
{
  CBeam *v2; // eax
  CBeam *v3; // esi

  v2 = (CBeam *)CBaseEntity::operator new(stAllocateBlock: 0x3FCu);
  if ( v2 != nullptr )
    v3 = CBeam::CBeam(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x100E0270
// Name: public: virtual unsigned int CEntityFactory<class CBeamSpotlight>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CBeamSpotlight>::GetEntitySize(CEntityFactory<CAssaultPoint> *this)
{
  return 940;
}

//------------------------------------------------------------------------------
// Address: 0x100E0BF0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CBeamSpotlight>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CBeamSpotlight>::Create(
        CEntityFactory<CBeamSpotlight> *this,
        const char *pClassName)
{
  CBeamSpotlight *v2; // eax
  CBeamSpotlight *v3; // esi

  v2 = (CBeamSpotlight *)CBaseEntity::operator new(stAllocateBlock: 0x3ACu);
  if ( v2 != nullptr )
    v3 = CBeamSpotlight::CBeamSpotlight(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x100E12C0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CFuncWall>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CFuncWall>::Create(
        CEntityFactory<CFuncWall> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x358u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CFuncWall::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x100E19D0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CFuncWallToggle>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CFuncWallToggle>::Create(
        CEntityFactory<CFuncWallToggle> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x358u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CFuncWallToggle::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x100E1A10
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CFuncVehicleClip>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CFuncVehicleClip>::Create(
        CEntityFactory<CFuncVehicleClip> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x354u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CFuncVehicleClip::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x100E1A50
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CFuncIllusionary>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CFuncIllusionary>::Create(
        CEntityFactory<CFuncIllusionary> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x354u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CFuncIllusionary::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x100E1DD0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CFuncVPhysicsClip>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IServerNetworkable *__thiscall CEntityFactory<CFuncVPhysicsClip>::Create(
        CEntityFactory<CFuncVPhysicsClip> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x360u);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    *v3 = &CFuncVPhysicsClip::`vftable';
    v3[214] = -1;
  }
  else
  {
    v3 = nullptr;
  }
  (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: pClassName);
  return (IServerNetworkable *)(v3 + 3);
}

//------------------------------------------------------------------------------
// Address: 0x100E21E0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CFuncConveyor>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CFuncConveyor>::Create(
        CEntityFactory<CFuncConveyor> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CFuncConveyor>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x100E2200
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CFuncRotating>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CFuncRotating>::Create(
        CEntityFactory<CFuncRotating> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CFuncRotating>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x100E41E0
// Name: public: virtual unsigned int CEntityFactory<class CTriggerOnce>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CTriggerOnce>::GetEntitySize(CEntityFactory<CRotButton> *this)
{
  return 1176;
}

//------------------------------------------------------------------------------
// Address: 0x100E41F0
// Name: public: virtual unsigned int CEntityFactory<class CMomentaryRotButton>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CMomentaryRotButton>::GetEntitySize(CEntityFactory<CMomentaryRotButton> *this)
{
  return 1352;
}

//------------------------------------------------------------------------------
// Address: 0x100E5620
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CBaseButton>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CBaseButton>::Create(
        CEntityFactory<CBaseButton> *this,
        const char *pClassName)
{
  CBaseButton *v2; // eax
  CBaseButton *v3; // esi

  v2 = (CBaseButton *)CBaseEntity::operator new(stAllocateBlock: 0x498u);
  if ( v2 != nullptr )
    v3 = CBaseButton::CBaseButton(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x100E5660
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CRotButton>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CRotButton>::Create(
        CEntityFactory<CRotButton> *this,
        const char *pClassName)
{
  CBaseButton *v2; // eax
  CBaseButton *v3; // esi

  v2 = (CBaseButton *)CBaseEntity::operator new(stAllocateBlock: 0x498u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseButton::CBaseButton(this: v2);
    v3->__vftable = (CBaseButton_vtbl *)&CRotButton::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x100E56A0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CMomentaryRotButton>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CMomentaryRotButton>::Create(
        CEntityFactory<CMomentaryRotButton> *this,
        const char *pClassName)
{
  CMomentaryRotButton *v2; // eax
  CMomentaryRotButton *v3; // esi

  v2 = (CMomentaryRotButton *)CBaseEntity::operator new(stAllocateBlock: 0x548u);
  if ( v2 != nullptr )
    v3 = CMomentaryRotButton::CMomentaryRotButton(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x100E9EE0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CEventQueueSaveLoadProxy>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CEventQueueSaveLoadProxy>::Create(
        CEntityFactory<CEventQueueSaveLoadProxy> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x354u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: true);
    v3->__vftable = (CBaseEntity_vtbl *)&CEventQueueSaveLoadProxy::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x100EA200
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CBaseProjectile>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IServerNetworkable *__thiscall CEntityFactory<CBaseProjectile>::Create(
        CEntityFactory<CBaseProjectile> *this,
        const char *pClassName)
{
  CBaseAnimating *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseAnimating *)CBaseEntity::operator new(stAllocateBlock: 0x498u);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseAnimating::CBaseAnimating(this: v2);
    *v3 = &CBaseProjectile::`vftable';
    v3[293] = -1;
  }
  else
  {
    v3 = nullptr;
  }
  (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: pClassName);
  return (IServerNetworkable *)(v3 + 3);
}

//------------------------------------------------------------------------------
// Address: 0x100EDBD0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CPointClientCommand>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CPointClientCommand>::Create(
        CEntityFactory<CPointClientCommand> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x354u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CPointClientCommand::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x100EDC10
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CPointServerCommand>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CPointServerCommand>::Create(
        CEntityFactory<CPointServerCommand> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x354u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CPointServerCommand::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x100EDC50
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CPointBroadcastClientCommand>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CPointBroadcastClientCommand>::Create(
        CEntityFactory<CPointBroadcastClientCommand> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x354u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CPointBroadcastClientCommand::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x100F3C30
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CColorCorrection>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CColorCorrection>::Create(
        CEntityFactory<CColorCorrection> *this,
        const char *pClassName)
{
  CColorCorrection *v2; // eax
  CColorCorrection *v3; // esi

  v2 = (CColorCorrection *)CBaseEntity::operator new(stAllocateBlock: 0x48Cu);
  if ( v2 != nullptr )
    v3 = CColorCorrection::CColorCorrection(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x100F4630
// Name: public: virtual unsigned int CEntityFactory<class CColorCorrectionVolume>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CColorCorrectionVolume>::GetEntitySize(
        CEntityFactory<CColorCorrectionVolume> *this)
{
  return 1444;
}

//------------------------------------------------------------------------------
// Address: 0x100F5250
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CColorCorrectionVolume>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CColorCorrectionVolume>::Create(
        CEntityFactory<CColorCorrectionVolume> *this,
        const char *pClassName)
{
  CColorCorrectionVolume *v2; // eax
  CColorCorrectionVolume *v3; // esi

  v2 = (CColorCorrectionVolume *)CBaseEntity::operator new(stAllocateBlock: 0x5A4u);
  if ( v2 != nullptr )
    v3 = CColorCorrectionVolume::CColorCorrectionVolume(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x100F5840
// Name: public: virtual unsigned int CEntityFactory<class CPointCommentaryNode>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CPointCommentaryNode>::GetEntitySize(CEntityFactory<CPointCommentaryNode> *this)
{
  return 1332;
}

//------------------------------------------------------------------------------
// Address: 0x100F6830
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CCommentaryViewPosition>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CCommentaryViewPosition>::Create(
        CEntityFactory<CCommentaryViewPosition> *this,
        const char *pClassName)
{
  CSprite *v2; // eax
  CSprite *v3; // esi

  v2 = (CSprite *)CBaseEntity::operator new(stAllocateBlock: 0x3A4u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CSprite::CSprite(this: v2);
    v3->__vftable = (CSprite_vtbl *)&CCommentaryViewPosition::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x100F7470
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CPointCommentaryNode>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CPointCommentaryNode>::Create(
        CEntityFactory<CPointCommentaryNode> *this,
        const char *pClassName)
{
  CPointCommentaryNode *v2; // eax
  CPointCommentaryNode *v3; // esi

  v2 = (CPointCommentaryNode *)CBaseEntity::operator new(stAllocateBlock: 0x534u);
  if ( v2 != nullptr )
    v3 = CPointCommentaryNode::CPointCommentaryNode(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x100F74B0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CCommentaryAuto>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CCommentaryAuto>::Create(
        CEntityFactory<CCommentaryAuto> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CCommentaryAuto>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x100F9B10
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CTargetCDAudioRep>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CTargetCDAudioRep>::Create(
        CEntityFactory<CTargetCDAudioRep> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x358u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CTargetCDAudioRep::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x100F9B50
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CTargetChangeGravity>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CTargetChangeGravity>::Create(
        CEntityFactory<CTargetChangeGravity> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x35Cu);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CTargetChangeGravity::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x100FA010
// Name: public: virtual unsigned int CEntityFactory<class CDynamicLight>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CDynamicLight>::GetEntitySize(CEntityFactory<CAI_BattleLine> *this)
{
  return 876;
}

//------------------------------------------------------------------------------
// Address: 0x100FA240
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CRagdollMagnet>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CRagdollMagnet>::Create(
        CEntityFactory<CRagdollMagnet> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x36Cu);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CRagdollMagnet::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x100FF540
// Name: public: virtual unsigned int CEntityFactory<class CRotDoor>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CRotDoor>::GetEntitySize(CEntityFactory<CRotDoor> *this)
{
  return 1288;
}

//------------------------------------------------------------------------------
// Address: 0x100FFC10
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CBaseDoor>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CBaseDoor>::Create(
        CEntityFactory<CBaseDoor> *this,
        const char *pClassName)
{
  CBaseDoor *v2; // eax
  CBaseDoor *v3; // esi

  v2 = (CBaseDoor *)CBaseEntity::operator new(stAllocateBlock: 0x504u);
  if ( v2 != nullptr )
    v3 = CBaseDoor::CBaseDoor(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x100FFC50
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CRotDoor>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CRotDoor>::Create(
        CEntityFactory<CRotDoor> *this,
        const char *pClassName)
{
  CBaseDoor *v2; // eax
  CBaseDoor *v3; // esi

  v2 = (CBaseDoor *)CBaseEntity::operator new(stAllocateBlock: 0x508u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseDoor::CBaseDoor(this: v2);
    v3->__vftable = (CBaseDoor_vtbl *)&CRotDoor::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10103BC0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CDynamicLight>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CDynamicLight>::Create(
        CEntityFactory<CDynamicLight> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x36Cu);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CDynamicLight::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10105F00
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CGibShooter>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CGibShooter>::Create(
        CEntityFactory<CGibShooter> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x394u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CGibShooter::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10105F40
// Name: public: virtual unsigned int CEntityFactory<class CTestEffect>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CTestEffect>::GetEntitySize(CEntityFactory<CTestEffect> *this)
{
  return 1056;
}

//------------------------------------------------------------------------------
// Address: 0x10105F50
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CPrecipitationBlocker>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CPrecipitationBlocker>::Create(
        CEntityFactory<CPrecipitationBlocker> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x354u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CPrecipitationBlocker::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10105FC0
// Name: public: virtual unsigned int CEntityFactory<class CEnvWind>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CEnvWind>::GetEntitySize(CEntityFactory<CEnvWind> *this)
{
  return 1424;
}

//------------------------------------------------------------------------------
// Address: 0x10107120
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CBubbling>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CBubbling>::Create(
        CEntityFactory<CBubbling> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x364u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CBubbling::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10107160
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CEnvTracer>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CEnvTracer>::Create(
        CEntityFactory<CEnvTracer> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x364u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CEnvTracer::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101071A0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CEnvShooter>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IServerNetworkable *__thiscall CEntityFactory<CEnvShooter>::Create(
        CEntityFactory<CEnvShooter> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x3A0u);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    *v3 = &CEnvShooter::`vftable';
    v3[231] = 1065353216;
  }
  else
  {
    v3 = nullptr;
  }
  (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: pClassName);
  return (IServerNetworkable *)(v3 + 3);
}

//------------------------------------------------------------------------------
// Address: 0x101071F0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CTestEffect>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CTestEffect>::Create(
        CEntityFactory<CTestEffect> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x420u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CTestEffect::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10107230
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CBlood>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CBlood>::Create(CEntityFactory<CBlood> *this, const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x368u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CBlood::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10107270
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CEnvFunnel>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CEnvFunnel>::Create(
        CEntityFactory<CEnvFunnel> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x358u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CEnvFunnel::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101072B0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CEnvBeverage>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CEnvBeverage>::Create(
        CEntityFactory<CEnvBeverage> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x35Cu);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CEnvBeverage::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101072F0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CItemSoda>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CItemSoda>::Create(
        CEntityFactory<CItemSoda> *this,
        const char *pClassName)
{
  CBaseAnimating *v2; // eax
  CBaseAnimating *v3; // esi

  v2 = (CBaseAnimating *)CBaseEntity::operator new(stAllocateBlock: 0x48Cu);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseAnimating::CBaseAnimating(this: v2);
    v3->__vftable = (CBaseAnimating_vtbl *)&CItemSoda::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10107330
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CDetailBlocker>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CDetailBlocker>::Create(
        CEntityFactory<CDetailBlocker> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x354u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: true);
    v3->__vftable = (CBaseEntity_vtbl *)&CDetailBlocker::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10107370
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CPhysicsWire>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CPhysicsWire>::Create(
        CEntityFactory<CPhysicsWire> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x358u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CPhysicsWire::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101073B0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CEnvMuzzleFlash>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CEnvMuzzleFlash>::Create(
        CEntityFactory<CEnvMuzzleFlash> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x35Cu);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CEnvMuzzleFlash::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101073F0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CEnvSplash>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CEnvSplash>::Create(
        CEntityFactory<CEnvSplash> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x358u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CEnvSplash::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10107430
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CEnvGunfire>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CEnvGunfire>::Create(
        CEntityFactory<CEnvGunfire> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CEnvGunfire>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10107450
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CEnvViewPunch>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CEnvViewPunch>::Create(
        CEntityFactory<CEnvViewPunch> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x364u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CEnvViewPunch::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10107920
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CRotorWashShooter>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CRotorWashShooter>::Create(
        CEntityFactory<CRotorWashShooter> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CRotorWashShooter>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10107940
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CEnvWind>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CEnvWind>::Create(
        CEntityFactory<CEnvWind> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CEnvWind>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10107960
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CEmbers>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CEmbers>::Create(
        CEntityFactory<CEmbers> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x364u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CEmbers::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10108610
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CPrecipitation>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CPrecipitation>::Create(
        CEntityFactory<CPrecipitation> *this,
        const char *pClassName)
{
  CPrecipitation *v2; // eax
  CPrecipitation *v3; // esi

  v2 = (CPrecipitation *)CBaseEntity::operator new(stAllocateBlock: 0x358u);
  if ( v2 != nullptr )
    v3 = CPrecipitation::CPrecipitation(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10108650
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CEnvQuadraticBeam>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CEnvQuadraticBeam>::Create(
        CEntityFactory<CEnvQuadraticBeam> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x374u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CEnvQuadraticBeam::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1010AF70
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CEntityBlocker>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CEntityBlocker>::Create(
        CEntityFactory<CEntityBlocker> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x354u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CEntityBlocker::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1010BB00
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CEntityDissolve>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CEntityDissolve>::Create(
        CEntityFactory<CEntityDissolve> *this,
        const char *pClassName)
{
  CEntityDissolve *v2; // eax
  CEntityDissolve *v3; // esi

  v2 = (CEntityDissolve *)CBaseEntity::operator new(stAllocateBlock: 0x384u);
  if ( v2 != nullptr )
    v3 = CEntityDissolve::CEntityDissolve(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1010C290
// Name: public: virtual unsigned int CEntityFactory<class CEntityFlame>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CEntityFlame>::GetEntitySize(CEntityFactory<CAI_AssaultGoal> *this)
{
  return 920;
}

//------------------------------------------------------------------------------
// Address: 0x1010C360
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CEnvEntityIgniter>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CEnvEntityIgniter>::Create(
        CEntityFactory<CEnvEntityIgniter> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x358u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CEnvEntityIgniter::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1010D0A0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CEntityFlame>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CEntityFlame>::Create(
        CEntityFactory<CEntityFlame> *this,
        const char *pClassName)
{
  CEntityFlame *v2; // eax
  CEntityFlame *v3; // esi

  v2 = (CEntityFlame *)CBaseEntity::operator new(stAllocateBlock: 0x398u);
  if ( v2 != nullptr )
    v3 = CEntityFlame::CEntityFlame(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1010D250
// Name: public: virtual unsigned int CEntityFactory<class CEntityFreezing>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CEntityFreezing>::GetEntitySize(CEntityFactory<CEntityFreezing> *this)
{
  return 1072;
}

//------------------------------------------------------------------------------
// Address: 0x1010D3E0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CEntityFreezing>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CEntityFreezing>::Create(
        CEntityFactory<CEntityFreezing> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x430u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CEntityFreezing::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101107B0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CEntityParticleTrail>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CEntityParticleTrail>::Create(
        CEntityFactory<CEntityParticleTrail> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CEntityParticleTrail>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10110E70
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CEnvAmbientLight>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CEnvAmbientLight>::Create(
        CEntityFactory<CEnvAmbientLight> *this,
        const char *pClassName)
{
  CSpatialEntity *v2; // eax
  CSpatialEntity *v3; // esi

  v2 = (CSpatialEntity *)CBaseEntity::operator new(stAllocateBlock: 0x394u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CSpatialEntity::CSpatialEntity(this: v2);
    v3->__vftable = (CSpatialEntity_vtbl *)&CEnvAmbientLight::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10111110
// Name: public: virtual unsigned int CEntityFactory<class CDebugHistory>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CDebugHistory>::GetEntitySize(CEntityFactory<CDebugHistory> *this)
{
  return 1280872;
}

//------------------------------------------------------------------------------
// Address: 0x10111120
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CDebugHistory>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CDebugHistory>::Create(
        CEntityFactory<CDebugHistory> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x138B68u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CDebugHistory::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10111340
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CEnvDetailController>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CEnvDetailController>::Create(
        CEntityFactory<CEnvDetailController> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CEnvDetailController *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x35Cu);
  v3 = (CEnvDetailController *)v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CEnvDetailController_vtbl *)&CEnvDetailController::`vftable';
    s_detailController = v3;
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10111AE0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CEnvDOFController>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IServerNetworkable *__thiscall CEntityFactory<CEnvDOFController>::Create(
        CEntityFactory<CEnvDOFController> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x37Cu);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    *v3 = &CEnvDOFController::`vftable';
    v3[215] = -1;
  }
  else
  {
    v3 = nullptr;
  }
  (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: pClassName);
  return (IServerNetworkable *)(v3 + 3);
}

//------------------------------------------------------------------------------
// Address: 0x10112350
// Name: public: virtual unsigned int CEntityFactory<class CEnvEffectsScript>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CEnvEffectsScript>::GetEntitySize(CEntityFactory<CEnvEffectsScript> *this)
{
  return 1188;
}

//------------------------------------------------------------------------------
// Address: 0x10112CB0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CEnvEffectsScript>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CEnvEffectsScript>::Create(
        CEntityFactory<CEnvEffectsScript> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CEnvEffectsScript>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10113830
// Name: public: virtual unsigned int CEntityFactory<class CEnvEntityMaker>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CEnvEntityMaker>::GetEntitySize(CEntityFactory<CEnvEntityMaker> *this)
{
  return 972;
}

//------------------------------------------------------------------------------
// Address: 0x10114620
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CEnvEntityMaker>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CEnvEntityMaker>::Create(
        CEntityFactory<CEnvEntityMaker> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CEnvEntityMaker>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101150A0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CEnvInstructorHint>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CEnvInstructorHint>::Create(
        CEntityFactory<CEnvInstructorHint> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x390u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CEnvInstructorHint::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101150E0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CInfoInstructorHintTarget>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CInfoInstructorHintTarget>::Create(
        CEntityFactory<CInfoInstructorHintTarget> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x354u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CInfoInstructorHintTarget::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10115570
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CEnvParticleScript>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CEnvParticleScript>::Create(
        CEntityFactory<CEnvParticleScript> *this,
        const char *pClassName)
{
  CBaseAnimating *v2; // eax
  CBaseAnimating *v3; // esi

  v2 = (CBaseAnimating *)CBaseEntity::operator new(stAllocateBlock: 0x490u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseAnimating::CBaseAnimating(this: v2);
    v3->__vftable = (CBaseAnimating_vtbl *)&CEnvParticleScript::`vftable';
    CBaseAnimating::UseClientSideAnimation(this: v3);
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10115B30
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CEnvPlayerSurfaceTrigger>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CEnvPlayerSurfaceTrigger>::Create(
        CEntityFactory<CEnvPlayerSurfaceTrigger> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CEnvPlayerSurfaceTrigger>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101173A0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CEnvProjectedTexture>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CEnvProjectedTexture>::Create(
        CEntityFactory<CEnvProjectedTexture> *this,
        const char *pClassName)
{
  CEnvProjectedTexture *v2; // eax
  CEnvProjectedTexture *v3; // esi

  v2 = (CEnvProjectedTexture *)CBaseEntity::operator new(stAllocateBlock: 0x4A0u);
  if ( v2 != nullptr )
    v3 = CEnvProjectedTexture::CEnvProjectedTexture(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10117580
// Name: public: virtual unsigned int CEntityFactory<class CEnvDustPuff>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CEnvDustPuff>::GetEntitySize(CEntityFactory<CTargetChangeGravity> *this)
{
  return 860;
}

//------------------------------------------------------------------------------
// Address: 0x10117730
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CEnvScreenEffect>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CEnvScreenEffect>::Create(
        CEntityFactory<CEnvScreenEffect> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x35Cu);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->m_iEFlags |= 0x80u;
    v3->__vftable = (CBaseEntity_vtbl *)&CEnvScreenEffect::`vftable';
    CBaseEntity::DispatchUpdateTransmitState(this: v3);
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10117C10
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CEnvScreenOverlay>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CEnvScreenOverlay>::Create(
        CEntityFactory<CEnvScreenOverlay> *this,
        const char *pClassName)
{
  CEnvScreenOverlay *v2; // eax
  CEnvScreenOverlay *v3; // esi

  v2 = (CEnvScreenOverlay *)CBaseEntity::operator new(stAllocateBlock: 0x3B0u);
  if ( v2 != nullptr )
    v3 = CEnvScreenOverlay::CEnvScreenOverlay(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10118970
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CTextureToggle>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CTextureToggle>::Create(
        CEntityFactory<CTextureToggle> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x354u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CTextureToggle::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10118D10
// Name: public: virtual unsigned int CEntityFactory<class CTriggerTeleport>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CTriggerTeleport>::GetEntitySize(CEntityFactory<CTonemapTrigger> *this)
{
  return 1160;
}

//------------------------------------------------------------------------------
// Address: 0x10119CB0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CEnvTonemapController>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CEnvTonemapController>::Create(
        CEntityFactory<CEnvTonemapController> *this,
        const char *pClassName)
{
  CEnvTonemapController *v2; // eax
  CEnvTonemapController *v3; // esi

  v2 = (CEnvTonemapController *)CBaseEntity::operator new(stAllocateBlock: 0x38Cu);
  if ( v2 != nullptr )
    v3 = CEnvTonemapController::CEnvTonemapController(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1011A400
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CTonemapTrigger>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IServerNetworkable *__thiscall CEntityFactory<CTonemapTrigger>::Create(
        CEntityFactory<CTonemapTrigger> *this,
        const char *pClassName)
{
  CBaseTrigger *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseTrigger *)CBaseEntity::operator new(stAllocateBlock: 0x488u);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseTrigger::CBaseTrigger(this: v2);
    *v3 = &CTonemapTrigger::`vftable';
    v3[289] = -1;
  }
  else
  {
    v3 = nullptr;
  }
  (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: pClassName);
  return (IServerNetworkable *)(v3 + 3);
}

//------------------------------------------------------------------------------
// Address: 0x1011AE00
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CEnvZoom>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CEnvZoom>::Create(
        CEntityFactory<CEnvZoom> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x35Cu);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CEnvZoom::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1011B3C0
// Name: public: virtual unsigned int CEntityFactory<class CEnvBeam>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CEnvBeam>::GetEntitySize(CEntityFactory<CEnvBeam> *this)
{
  return 1132;
}

//------------------------------------------------------------------------------
// Address: 0x1011CA40
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CEnvBeam>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CEnvBeam>::Create(
        CEntityFactory<CEnvBeam> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CEnvBeam>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1011D2E0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CEnvFade>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CEnvFade>::Create(
        CEntityFactory<CEnvFade> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CEnvFade>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1011D560
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CEnvHudHint>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CEnvHudHint>::Create(
        CEntityFactory<CEnvHudHint> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x358u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CEnvHudHint::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1011D6D0
// Name: public: virtual unsigned int CEntityFactory<class CEnvLaser>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CEnvLaser>::GetEntitySize(CEntityFactory<CEnvLaser> *this)
{
  return 1048;
}

//------------------------------------------------------------------------------
// Address: 0x1011D8B0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CEnvLaser>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CEnvLaser>::Create(
        CEntityFactory<CEnvLaser> *this,
        const char *pClassName)
{
  CBeam *v2; // eax
  CBeam *v3; // esi

  v2 = (CBeam *)CBaseEntity::operator new(stAllocateBlock: 0x418u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBeam::CBeam(this: v2);
    v3->__vftable = (CBeam_vtbl *)&CEnvLaser::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1011E5C0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CMessage>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CMessage>::Create(
        CEntityFactory<CMessage> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CMessage>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1011E5E0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CCredits>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CCredits>::Create(
        CEntityFactory<CCredits> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CCredits>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1011E600
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class COuttroStats>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<COuttroStats>::Create(
        CEntityFactory<COuttroStats> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<COuttroStats>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1011F760
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CEnvMicrophone>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CEnvMicrophone>::Create(
        CEntityFactory<CEnvMicrophone> *this,
        const char *pClassName)
{
  CEnvMicrophone *v2; // eax
  CEnvMicrophone *v3; // esi

  v2 = (CEnvMicrophone *)CBaseEntity::operator new(stAllocateBlock: 0x4CCu);
  if ( v2 != nullptr )
    v3 = CEnvMicrophone::CEnvMicrophone(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10120370
// Name: public: virtual unsigned int CEntityFactory<class CAreaPortal>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CAreaPortal>::GetEntitySize(CEntityFactory<CAI_SpeechFilter> *this)
{
  return 868;
}

//------------------------------------------------------------------------------
// Address: 0x10120A90
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CEnvTilt>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CEnvTilt>::Create(
        CEntityFactory<CEnvTilt> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x364u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CEnvTilt::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10120AD0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CEnvShake>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IServerNetworkable *__thiscall CEntityFactory<CEnvShake>::Create(
        CEntityFactory<CEnvShake> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x390u);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    *v3 = &CEnvShake::`vftable';
    v3[224] = &CPhysicsShake::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: pClassName);
  return (IServerNetworkable *)(v3 + 3);
}

//------------------------------------------------------------------------------
// Address: 0x10121530
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CEnvSpark>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CEnvSpark>::Create(
        CEntityFactory<CEnvSpark> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CEnvSpark>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10123280
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CShower>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CShower>::Create(
        CEntityFactory<CShower> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x354u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CShower::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101232C0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CEnvExplosion>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CEnvExplosion>::Create(
        CEntityFactory<CEnvExplosion> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CEnvExplosion>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10123A90
// Name: public: virtual unsigned int CEntityFactory<class FilterDamageType>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<FilterDamageType>::GetEntitySize(CEntityFactory<CRallyPoint> *this)
{
  return 908;
}

//------------------------------------------------------------------------------
// Address: 0x10124540
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CBaseFilter>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CBaseFilter>::Create(
        CEntityFactory<CBaseFilter> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CBaseFilter>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10124560
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CFilterMultiple>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CFilterMultiple>::Create(
        CEntityFactory<CFilterMultiple> *this,
        const char *pClassName)
{
  CFilterMultiple *v2; // eax
  CFilterMultiple *v3; // esi

  v2 = (CFilterMultiple *)CBaseEntity::operator new(stAllocateBlock: 0x3DCu);
  if ( v2 != nullptr )
    v3 = CFilterMultiple::CFilterMultiple(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101245A0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CFilterName>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CFilterName>::Create(
        CEntityFactory<CFilterName> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CFilterName>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101245C0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CFilterModel>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CFilterModel>::Create(
        CEntityFactory<CFilterModel> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CFilterModel>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101245E0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CFilterContext>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CFilterContext>::Create(
        CEntityFactory<CFilterContext> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CFilterContext>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10124600
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CFilterClass>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CFilterClass>::Create(
        CEntityFactory<CFilterClass> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CFilterClass>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10124620
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class FilterTeam>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<FilterTeam>::Create(
        CEntityFactory<FilterTeam> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<FilterTeam>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10124640
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CFilterMassGreater>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CFilterMassGreater>::Create(
        CEntityFactory<CFilterMassGreater> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CFilterMassGreater>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10124660
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class FilterDamageType>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<FilterDamageType>::Create(
        CEntityFactory<FilterDamageType> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<FilterDamageType>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10124680
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CFilterEnemy>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CFilterEnemy>::Create(
        CEntityFactory<CFilterEnemy> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CFilterEnemy>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10125380
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CEnvFireSource>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CEnvFireSource>::Create(
        CEntityFactory<CEnvFireSource> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x360u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CEnvFireSource::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10125DB0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CFire>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CFire>::Create(CEntityFactory<CFire> *this, const char *pClassName)
{
  CFire *v2; // eax
  CFire *v3; // esi

  v2 = (CFire *)CBaseEntity::operator new(stAllocateBlock: 0x3C0u);
  if ( v2 != nullptr )
    v3 = CFire::CFire(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10125DF0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CEnvFireSensor>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CEnvFireSensor>::Create(
        CEntityFactory<CEnvFireSensor> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CEnvFireSensor>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10127B10
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CFireSmoke>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CFireSmoke>::Create(
        CEntityFactory<CFireSmoke> *this,
        const char *pClassName)
{
  CFireSmoke *v2; // eax
  CFireSmoke *v3; // esi

  v2 = (CFireSmoke *)CBaseEntity::operator new(stAllocateBlock: 0x36Cu);
  if ( v2 != nullptr )
    v3 = CFireSmoke::CFireSmoke(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10127DE0
// Name: public: virtual unsigned int CEntityFactory<class CFish>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CFish>::GetEntitySize(CEntityFactory<CFish> *this)
{
  return 1336;
}

//------------------------------------------------------------------------------
// Address: 0x1012A310
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CFish>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CFish>::Create(CEntityFactory<CFish> *this, const char *pClassName)
{
  CFish *v2; // eax
  CFish *v3; // esi

  v2 = (CFish *)CBaseEntity::operator new(stAllocateBlock: 0x538u);
  if ( v2 != nullptr )
    v3 = CFish::CFish(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1012A350
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CFishPool>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CFishPool>::Create(
        CEntityFactory<CFishPool> *this,
        const char *pClassName)
{
  CFishPool *v2; // eax
  CFishPool *v3; // esi

  v2 = (CFishPool *)CBaseEntity::operator new(stAllocateBlock: 0x394u);
  if ( v2 != nullptr )
    v3 = CFishPool::CFishPool(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1012A960
// Name: public: virtual unsigned int CEntityFactory<class CFlexExpresser>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CFlexExpresser>::GetEntitySize(CEntityFactory<CFlexExpresser> *this)
{
  return 1980;
}

//------------------------------------------------------------------------------
// Address: 0x1012AF10
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CFlexExpresser>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CFlexExpresser>::Create(
        CEntityFactory<CFlexExpresser> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CFlexExpresser>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1012CA00
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CFogController>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CFogController>::Create(
        CEntityFactory<CFogController> *this,
        const char *pClassName)
{
  CFogController *v2; // eax
  CFogController *v3; // esi

  v2 = (CFogController *)CBaseEntity::operator new(stAllocateBlock: 0x3A8u);
  if ( v2 != nullptr )
    v3 = CFogController::CFogController(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1012CA40
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CFogTrigger>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IServerNetworkable *__thiscall CEntityFactory<CFogTrigger>::Create(
        CEntityFactory<CFogTrigger> *this,
        const char *pClassName)
{
  CBaseTrigger *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseTrigger *)CBaseEntity::operator new(stAllocateBlock: 0x4CCu);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseTrigger::CBaseTrigger(this: v2);
    *v3 = &CFogTrigger::`vftable';
    v3[288] = &fogparams_t::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: pClassName);
  return (IServerNetworkable *)(v3 + 3);
}

//------------------------------------------------------------------------------
// Address: 0x1012CDD0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CFogVolume>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CFogVolume>::Create(
        CEntityFactory<CFogVolume> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CFogVolume>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10130D70
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CAreaPortal>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IServerNetworkable *__thiscall CEntityFactory<CAreaPortal>::Create(
        CEntityFactory<CAreaPortal> *this,
        const char *pClassName)
{
  CFuncAreaPortalBase *v2; // eax
  _DWORD *v3; // esi

  v2 = (CFuncAreaPortalBase *)CBaseEntity::operator new(stAllocateBlock: 0x364u);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CFuncAreaPortalBase::CFuncAreaPortalBase(this: v2);
    *v3 = &CAreaPortal::`vftable';
    v3[216] = 1;
  }
  else
  {
    v3 = nullptr;
  }
  (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: pClassName);
  return (IServerNetworkable *)(v3 + 3);
}

//------------------------------------------------------------------------------
// Address: 0x10131720
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CFuncAreaPortalWindow>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CFuncAreaPortalWindow>::Create(
        CEntityFactory<CFuncAreaPortalWindow> *this,
        const char *pClassName)
{
  CFuncAreaPortalWindow *v2; // eax
  CFuncAreaPortalWindow *v3; // esi

  v2 = (CFuncAreaPortalWindow *)CBaseEntity::operator new(stAllocateBlock: 0x374u);
  if ( v2 != nullptr )
    v3 = CFuncAreaPortalWindow::CFuncAreaPortalWindow(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10131E20
// Name: public: virtual unsigned int CEntityFactory<class CBreakable>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CBreakable>::GetEntitySize(CEntityFactory<CPushable> *this)
{
  return 1028;
}

//------------------------------------------------------------------------------
// Address: 0x10132890
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CBreakable>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CBreakable>::Create(
        CEntityFactory<CBreakable> *this,
        const char *pClassName)
{
  CBreakable *v2; // eax
  CBreakable *v3; // esi

  v2 = (CBreakable *)CBaseEntity::operator new(stAllocateBlock: 0x404u);
  if ( v2 != nullptr )
    v3 = CBreakable::CBreakable(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101328D0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CPushable>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CPushable>::Create(
        CEntityFactory<CPushable> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CPushable>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10134B90
// Name: public: virtual unsigned int CEntityFactory<class CBreakableSurface>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CBreakableSurface>::GetEntitySize(CEntityFactory<CBreakableSurface> *this)
{
  return 2416;
}

//------------------------------------------------------------------------------
// Address: 0x101351D0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CWindowPane>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CWindowPane>::Create(
        CEntityFactory<CWindowPane> *this,
        const char *pClassName)
{
  CBaseAnimating *v2; // eax
  CBaseAnimating *v3; // esi

  v2 = (CBaseAnimating *)CBaseEntity::operator new(stAllocateBlock: 0x48Cu);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseAnimating::CBaseAnimating(this: v2);
    v3->__vftable = (CBaseAnimating_vtbl *)&CWindowPane::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101370A0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CBreakableSurface>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CBreakableSurface>::Create(
        CEntityFactory<CBreakableSurface> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CBreakableSurface>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101384A0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CEnvDustPuff>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CEnvDustPuff>::Create(
        CEntityFactory<CEnvDustPuff> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x35Cu);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CEnvDustPuff::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10138A20
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CFunc_DustMotes>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CFunc_DustMotes>::Create(
        CEntityFactory<CFunc_DustMotes> *this,
        const char *pClassName)
{
  CFunc_DustMotes *v2; // eax
  CFunc_DustMotes *v3; // esi

  v2 = (CFunc_DustMotes *)CBaseEntity::operator new(stAllocateBlock: 0x380u);
  if ( v2 != nullptr )
    v3 = CFunc_DustMotes::CFunc_DustMotes(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10138A60
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CFunc_DustCloud>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CFunc_DustCloud>::Create(
        CEntityFactory<CFunc_DustCloud> *this,
        const char *pClassName)
{
  CFunc_Dust *v2; // eax
  CFunc_Dust *v3; // esi

  v2 = (CFunc_Dust *)CBaseEntity::operator new(stAllocateBlock: 0x380u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CFunc_Dust::CFunc_Dust(this: v2);
    v3->__vftable = (CFunc_Dust_vtbl *)&CFunc_DustCloud::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10139060
// Name: public: virtual unsigned int CEntityFactory<class CFuncInstanceIoProxy>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CFuncInstanceIoProxy>::GetEntitySize(CEntityFactory<CFuncInstanceIoProxy> *this)
{
  return 1572;
}

//------------------------------------------------------------------------------
// Address: 0x10139440
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CFuncInstanceIoProxy>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CFuncInstanceIoProxy>::Create(
        CEntityFactory<CFuncInstanceIoProxy> *this,
        const char *pClassName)
{
  CFuncInstanceIoProxy *v2; // eax
  CFuncInstanceIoProxy *v3; // esi

  v2 = (CFuncInstanceIoProxy *)CBaseEntity::operator new(stAllocateBlock: 0x624u);
  if ( v2 != nullptr )
    v3 = CFuncInstanceIoProxy::CFuncInstanceIoProxy(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1013A280
// Name: public: virtual unsigned int CEntityFactory<class CFuncLadder>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CFuncLadder>::GetEntitySize(CEntityFactory<CFuncLadder> *this)
{
  return 964;
}

//------------------------------------------------------------------------------
// Address: 0x1013A490
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CInfoLadderDismount>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CInfoLadderDismount>::Create(
        CEntityFactory<CInfoLadderDismount> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x354u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CInfoLadderDismount::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1013B600
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CFuncLadder>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CFuncLadder>::Create(
        CEntityFactory<CFuncLadder> *this,
        const char *pClassName)
{
  CFuncLadder *v2; // eax
  CFuncLadder *v3; // esi

  v2 = (CFuncLadder *)CBaseEntity::operator new(stAllocateBlock: 0x3C4u);
  if ( v2 != nullptr )
    v3 = CFuncLadder::CFuncLadder(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1013B670
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CFuncLadderEndPoint>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CFuncLadderEndPoint>::Create(
        CEntityFactory<CFuncLadderEndPoint> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x354u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CFuncLadderEndPoint::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1013B9B0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CFunc_LOD>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CFunc_LOD>::Create(
        CEntityFactory<CFunc_LOD> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x35Cu);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CFunc_LOD::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1013BDD0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CFuncMonitor>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IServerNetworkable *__thiscall CEntityFactory<CFuncMonitor>::Create(
        CEntityFactory<CFuncMonitor> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x368u);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    *v3 = &CFuncMonitor::`vftable';
    v3[217] = -1;
  }
  else
  {
    v3 = nullptr;
  }
  (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: pClassName);
  return (IServerNetworkable *)(v3 + 3);
}

//------------------------------------------------------------------------------
// Address: 0x1013C8B0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CFuncMoveLinear>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CFuncMoveLinear>::Create(
        CEntityFactory<CFuncMoveLinear> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CFuncMoveLinear>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1013D360
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CFuncOccluder>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CFuncOccluder>::Create(
        CEntityFactory<CFuncOccluder> *this,
        const char *pClassName)
{
  CFuncOccluder *v2; // eax
  CFuncOccluder *v3; // esi

  v2 = (CFuncOccluder *)CBaseEntity::operator new(stAllocateBlock: 0x35Cu);
  if ( v2 != nullptr )
    v3 = CFuncOccluder::CFuncOccluder(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1013D4C0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CFuncReflectiveGlass>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CFuncReflectiveGlass>::Create(
        CEntityFactory<CFuncReflectiveGlass> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x364u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CFuncReflectiveGlass::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1013D590
// Name: public: virtual unsigned int CEntityFactory<class CFuncSmokeVolume>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CFuncSmokeVolume>::GetEntitySize(CEntityFactory<CFuncSmokeVolume> *this)
{
  return 1148;
}

//------------------------------------------------------------------------------
// Address: 0x1013DA10
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CFuncSmokeVolume>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CFuncSmokeVolume>::Create(
        CEntityFactory<CFuncSmokeVolume> *this,
        const char *pClassName)
{
  CFuncSmokeVolume *v2; // eax
  CFuncSmokeVolume *v3; // esi

  v2 = (CFuncSmokeVolume *)CBaseEntity::operator new(stAllocateBlock: 0x47Cu);
  if ( v2 != nullptr )
    v3 = CFuncSmokeVolume::CFuncSmokeVolume(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1013DF60
// Name: public: virtual unsigned int CEntityFactory<class CGameUI>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CGameUI>::GetEntitySize(CEntityFactory<CGameUI> *this)
{
  return 1304;
}

//------------------------------------------------------------------------------
// Address: 0x1013EC90
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CGameUI>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CGameUI>::Create(
        CEntityFactory<CGameUI> *this,
        const char *pClassName)
{
  CGameUI *v2; // eax
  CGameUI *v3; // esi

  v2 = (CGameUI *)CBaseEntity::operator new(stAllocateBlock: 0x518u);
  if ( v2 != nullptr )
    v3 = CGameUI::CGameUI(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1014E2D0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CPointGamestatsCounter>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CPointGamestatsCounter>::Create(
        CEntityFactory<CPointGamestatsCounter> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x35Cu);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CPointGamestatsCounter::`vftable';
    v3[1].__vftable = nullptr;
    LOBYTE(v3[1].m_pfnMoveDone) = 0;
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10153200
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CGameWeaponManager>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CGameWeaponManager>::Create(
        CEntityFactory<CGameWeaponManager> *this,
        const char *pClassName)
{
  CGameWeaponManager *v2; // eax
  CGameWeaponManager *v3; // esi

  v2 = (CGameWeaponManager *)CBaseEntity::operator new(stAllocateBlock: 0x378u);
  if ( v2 != nullptr )
    v3 = CGameWeaponManager::CGameWeaponManager(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10153410
// Name: public: virtual unsigned int CEntityFactory<class CGenericActor>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CGenericActor>::GetEntitySize(CEntityFactory<CGenericActor> *this)
{
  return 4256;
}

//------------------------------------------------------------------------------
// Address: 0x10153D90
// Name: public: virtual unsigned int CEntityFactory<class CFlextalkActor>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CFlextalkActor>::GetEntitySize(CEntityFactory<CFlextalkActor> *this)
{
  return 4560;
}

//------------------------------------------------------------------------------
// Address: 0x101550E0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CGenericActor>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CGenericActor>::Create(
        CEntityFactory<CGenericActor> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CGenericActor>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10155180
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CFlextalkActor>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CFlextalkActor>::Create(
        CEntityFactory<CFlextalkActor> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CFlextalkActor>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101554F0
// Name: public: virtual unsigned int CEntityFactory<class CGenericNPC>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CGenericNPC>::GetEntitySize(CEntityFactory<CGenericNPC> *this)
{
  return 3716;
}

//------------------------------------------------------------------------------
// Address: 0x10155500
// Name: public: virtual unsigned int CEntityFactory<class CNPC_Furniture>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CNPC_Furniture>::GetEntitySize(CEntityFactory<CNPC_Furniture> *this)
{
  return 4276;
}

//------------------------------------------------------------------------------
// Address: 0x10155570
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CGenericNPC>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CGenericNPC>::Create(
        CEntityFactory<CGenericNPC> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CGenericNPC>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10155D00
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CNPC_Furniture>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CNPC_Furniture>::Create(
        CEntityFactory<CNPC_Furniture> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CNPC_Furniture>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10156830
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CRagGib>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CRagGib>::Create(
        CEntityFactory<CRagGib> *this,
        const char *pClassName)
{
  CBaseAnimating *v2; // eax
  CBaseAnimating *v3; // esi

  v2 = (CBaseAnimating *)CBaseEntity::operator new(stAllocateBlock: 0x48Cu);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseAnimating::CBaseAnimating(this: v2);
    v3->__vftable = (CBaseAnimating_vtbl *)&CRagGib::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10156B40
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CGib>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CGib>::Create(CEntityFactory<CGib> *this, const char *pClassName)
{
  return &_CreateEntityTemplate<CGib>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10159880
// Name: public: virtual unsigned int CEntityFactory<class CGunTarget>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CGunTarget>::GetEntitySize(CEntityFactory<CGunTarget> *this)
{
  return 1004;
}

//------------------------------------------------------------------------------
// Address: 0x10159C00
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CGunTarget>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CGunTarget>::Create(
        CEntityFactory<CGunTarget> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CGunTarget>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1015AD00
// Name: public: virtual unsigned int CEntityFactory<class CWeaponCycler>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CWeaponCycler>::GetEntitySize(CEntityFactory<CWeaponCycler> *this)
{
  return 1412;
}

//------------------------------------------------------------------------------
// Address: 0x1015AD10
// Name: public: virtual unsigned int CEntityFactory<class CWreckage>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CWreckage>::GetEntitySize(CEntityFactory<CWreckage> *this)
{
  return 3724;
}

//------------------------------------------------------------------------------
// Address: 0x1015AD20
// Name: public: virtual unsigned int CEntityFactory<class CBlendingCycler>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CBlendingCycler>::GetEntitySize(CEntityFactory<CBlendingCycler> *this)
{
  return 3740;
}

//------------------------------------------------------------------------------
// Address: 0x1015AF50
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CWeaponCycler>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CWeaponCycler>::Create(
        CEntityFactory<CWeaponCycler> *this,
        const char *pClassName)
{
  CBaseCombatWeapon *v2; // eax
  CBaseCombatWeapon *v3; // esi

  v2 = (CBaseCombatWeapon *)CBaseEntity::operator new(stAllocateBlock: 0x584u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseCombatWeapon::CBaseCombatWeapon(this: v2);
    v3->__vftable = (CBaseCombatWeapon_vtbl *)&CWeaponCycler::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1015AF90
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CWreckage>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CWreckage>::Create(
        CEntityFactory<CWreckage> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CWreckage>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1015B400
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CGenericCycler>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CGenericCycler>::Create(
        CEntityFactory<CGenericCycler> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CGenericCycler>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1015B420
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CBlendingCycler>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CBlendingCycler>::Create(
        CEntityFactory<CBlendingCycler> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CBlendingCycler>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101624D0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CInfoCameraLink>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CInfoCameraLink>::Create(
        CEntityFactory<CInfoCameraLink> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CInfoCameraLink>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101625B0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CInfoOverlayAccessor>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CInfoOverlayAccessor>::Create(
        CEntityFactory<CInfoOverlayAccessor> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x358u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CInfoOverlayAccessor::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101628B0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CInfoRemarkable>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CInfoRemarkable>::Create(
        CEntityFactory<CInfoRemarkable> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x35Cu);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CInfoRemarkable::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10162B80
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CInfoIntermission>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CInfoIntermission>::Create(
        CEntityFactory<CInfoIntermission> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x354u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CInfoIntermission::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10163450
// Name: public: virtual unsigned int CEntityFactory<class CWorldItem>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CWorldItem>::GetEntitySize(CEntityFactory<CEnvParticleScript> *this)
{
  return 1168;
}

//------------------------------------------------------------------------------
// Address: 0x101636B0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CWorldItem>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CWorldItem>::Create(
        CEntityFactory<CWorldItem> *this,
        const char *pClassName)
{
  CBaseAnimating *v2; // eax
  CBaseAnimating *v3; // esi

  v2 = (CBaseAnimating *)CBaseEntity::operator new(stAllocateBlock: 0x490u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseAnimating::CBaseAnimating(this: v2);
    v3->__vftable = (CBaseAnimating_vtbl *)&CWorldItem::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10164AD0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CLightGlow>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CLightGlow>::Create(
        CEntityFactory<CLightGlow> *this,
        const char *pClassName)
{
  CLightGlow *v2; // eax
  CLightGlow *v3; // esi

  v2 = (CLightGlow *)CBaseEntity::operator new(stAllocateBlock: 0x370u);
  if ( v2 != nullptr )
    v3 = CLightGlow::CLightGlow(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10164E00
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CLight>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CLight>::Create(CEntityFactory<CLight> *this, const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x364u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CLight::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10164E40
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CEnvLight>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CEnvLight>::Create(
        CEntityFactory<CEnvLight> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x364u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CEnvLight::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101654B0
// Name: public: virtual unsigned int CEntityFactory<class CEntityDissolve>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CEntityDissolve>::GetEntitySize(CEntityFactory<CEntityDissolve> *this)
{
  return 900;
}

//------------------------------------------------------------------------------
// Address: 0x10165650
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CLogicEventListener>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CLogicEventListener>::Create(
        CEntityFactory<CLogicEventListener> *this,
        const char *pClassName)
{
  CLogicEventListener *v2; // eax
  CLogicEventListener *v3; // esi

  v2 = (CLogicEventListener *)CBaseEntity::operator new(stAllocateBlock: 0x384u);
  if ( v2 != nullptr )
    v3 = CLogicEventListener::CLogicEventListener(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101660B0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CLogicMeasureMovement>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CLogicMeasureMovement>::Create(
        CEntityFactory<CLogicMeasureMovement> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CLogicMeasureMovement>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10166470
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CLogicNavigation>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CLogicNavigation>::Create(
        CEntityFactory<CLogicNavigation> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CLogicNavigation>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101667C0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CLogicPlayerProxy>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CLogicPlayerProxy>::Create(
        CEntityFactory<CLogicPlayerProxy> *this,
        const char *pClassName)
{
  CLogicPlayerProxy *v2; // eax
  CLogicPlayerProxy *v3; // esi

  v2 = (CLogicPlayerProxy *)CBaseEntity::operator new(stAllocateBlock: 0x400u);
  if ( v2 != nullptr )
    v3 = CLogicPlayerProxy::CLogicPlayerProxy(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10166EA0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CLogicPlayMovie>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CLogicPlayMovie>::Create(
        CEntityFactory<CLogicPlayMovie> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CLogicPlayMovie>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10167360
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CLogicRandomOutputs>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CLogicRandomOutputs>::Create(
        CEntityFactory<CLogicRandomOutputs> *this,
        const char *pClassName)
{
  CLogicRandomOutputs *v2; // eax
  CLogicRandomOutputs *v3; // esi

  v2 = (CLogicRandomOutputs *)CBaseEntity::operator new(stAllocateBlock: 0x450u);
  if ( v2 != nullptr )
    v3 = CLogicRandomOutputs::CLogicRandomOutputs(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101678F0
// Name: public: virtual unsigned int CEntityFactory<class CLogicPlayerProxy>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CLogicPlayerProxy>::GetEntitySize(CEntityFactory<CLogicPlayerProxy> *this)
{
  return 1024;
}

//------------------------------------------------------------------------------
// Address: 0x101679A0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CLogicAuto>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CLogicAuto>::Create(
        CEntityFactory<CLogicAuto> *this,
        const char *pClassName)
{
  CLogicAuto *v2; // eax
  CLogicAuto *v3; // esi

  v2 = (CLogicAuto *)CBaseEntity::operator new(stAllocateBlock: 0x400u);
  if ( v2 != nullptr )
    v3 = CLogicAuto::CLogicAuto(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10169800
// Name: public: virtual unsigned int CEntityFactory<class CRagdollConstraint>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CRagdollConstraint>::GetEntitySize(CEntityFactory<CRotorWashShooter> *this)
{
  return 948;
}

//------------------------------------------------------------------------------
// Address: 0x10169810
// Name: public: virtual unsigned int CEntityFactory<class CAI_DynamicLinkController>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CAI_DynamicLinkController>::GetEntitySize(
        CEntityFactory<CAI_DynamicLinkController> *this)
{
  return 888;
}

//------------------------------------------------------------------------------
// Address: 0x10169820
// Name: public: virtual unsigned int CEntityFactory<class CMathRemap>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CMathRemap>::GetEntitySize(CEntityFactory<CEnvFade> *this)
{
  return 896;
}

//------------------------------------------------------------------------------
// Address: 0x10169830
// Name: public: virtual unsigned int CEntityFactory<class CMultiSource>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CMultiSource>::GetEntitySize(CEntityFactory<CMultiSource> *this)
{
  return 1140;
}

//------------------------------------------------------------------------------
// Address: 0x10169840
// Name: public: virtual unsigned int CEntityFactory<class CMathCounter>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CMathCounter>::GetEntitySize(CEntityFactory<CMathCounter> *this)
{
  return 1008;
}

//------------------------------------------------------------------------------
// Address: 0x10169850
// Name: public: virtual unsigned int CEntityFactory<class CLogicCase>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CLogicCase>::GetEntitySize(CEntityFactory<CLogicCase> *this)
{
  return 1348;
}

//------------------------------------------------------------------------------
// Address: 0x10169860
// Name: public: virtual unsigned int CEntityFactory<class CLogicBranchList>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CLogicBranchList>::GetEntitySize(CEntityFactory<CLogicBranchList> *this)
{
  return 1012;
}

//------------------------------------------------------------------------------
// Address: 0x1016AFD0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CLogicScript>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CLogicScript>::Create(
        CEntityFactory<CLogicScript> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x394u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CLogicScript::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1016B010
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CLogicAutosave>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CLogicAutosave>::Create(
        CEntityFactory<CLogicAutosave> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x360u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: true);
    v3->__vftable = (CBaseEntity_vtbl *)&CLogicAutosave::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1016B050
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CLogicCollisionPair>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CLogicCollisionPair>::Create(
        CEntityFactory<CLogicCollisionPair> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x360u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: true);
    v3->__vftable = (CBaseEntity_vtbl *)&CLogicCollisionPair::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1016B830
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CLogicCompareInteger>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CLogicCompareInteger>::Create(
        CEntityFactory<CLogicCompareInteger> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CLogicCompareInteger>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1016B850
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CLogicRegisterActivator>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CLogicRegisterActivator>::Create(
        CEntityFactory<CLogicRegisterActivator> *this,
        const char *pClassName)
{
  CLogicRegisterActivator *v2; // eax
  CLogicRegisterActivator *v3; // esi

  v2 = (CLogicRegisterActivator *)CBaseEntity::operator new(stAllocateBlock: 0x3BCu);
  if ( v2 != nullptr )
    v3 = CLogicRegisterActivator::CLogicRegisterActivator(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1016B890
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CTimerEntity>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CTimerEntity>::Create(
        CEntityFactory<CTimerEntity> *this,
        const char *pClassName)
{
  CTimerEntity *v2; // eax
  CTimerEntity *v3; // esi

  v2 = (CTimerEntity *)CBaseEntity::operator new(stAllocateBlock: 0x3B4u);
  if ( v2 != nullptr )
    v3 = CTimerEntity::CTimerEntity(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1016B8D0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CMultiSource>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CMultiSource>::Create(
        CEntityFactory<CMultiSource> *this,
        const char *pClassName)
{
  CMultiSource *v2; // eax
  CMultiSource *v3; // esi

  v2 = (CMultiSource *)CBaseEntity::operator new(stAllocateBlock: 0x474u);
  if ( v2 != nullptr )
    v3 = CMultiSource::CMultiSource(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1016B910
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CLogicActiveAutosave>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CLogicActiveAutosave>::Create(
        CEntityFactory<CLogicActiveAutosave> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x370u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: true);
    v3->__vftable = (CBaseEntity_vtbl *)&CLogicActiveAutosave::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1016BFE0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CLogicLineToEntity>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CLogicLineToEntity>::Create(
        CEntityFactory<CLogicLineToEntity> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CLogicLineToEntity>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1016C000
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CMathRemap>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CMathRemap>::Create(
        CEntityFactory<CMathRemap> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CMathRemap>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1016C020
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CMathColorBlend>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CMathColorBlend>::Create(
        CEntityFactory<CMathColorBlend> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CMathColorBlend>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1016C040
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CEnvGlobal>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CEnvGlobal>::Create(
        CEntityFactory<CEnvGlobal> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CEnvGlobal>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1016C060
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CMathCounter>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CMathCounter>::Create(
        CEntityFactory<CMathCounter> *this,
        const char *pClassName)
{
  CMathCounter *v2; // eax
  CMathCounter *v3; // esi

  v2 = (CMathCounter *)CBaseEntity::operator new(stAllocateBlock: 0x3F0u);
  if ( v2 != nullptr )
    v3 = CMathCounter::CMathCounter(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1016C0A0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CLogicCase>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CLogicCase>::Create(
        CEntityFactory<CLogicCase> *this,
        const char *pClassName)
{
  CLogicCase *v2; // eax
  CLogicCase *v3; // esi

  v2 = (CLogicCase *)CBaseEntity::operator new(stAllocateBlock: 0x544u);
  if ( v2 != nullptr )
    v3 = CLogicCase::CLogicCase(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1016C0E0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CLogicCompare>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CLogicCompare>::Create(
        CEntityFactory<CLogicCompare> *this,
        const char *pClassName)
{
  CLogicCompare *v2; // eax
  CLogicCompare *v3; // esi

  v2 = (CLogicCompare *)CBaseEntity::operator new(stAllocateBlock: 0x3BCu);
  if ( v2 != nullptr )
    v3 = CLogicCompare::CLogicCompare(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1016E950
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CLogicBranch>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CLogicBranch>::Create(
        CEntityFactory<CLogicBranch> *this,
        const char *pClassName)
{
  CLogicBranch *v2; // eax
  CLogicBranch *v3; // esi

  v2 = (CLogicBranch *)CBaseEntity::operator new(stAllocateBlock: 0x39Cu);
  if ( v2 != nullptr )
    v3 = CLogicBranch::CLogicBranch(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1016E990
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CLogicBranchList>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CLogicBranchList>::Create(
        CEntityFactory<CLogicBranchList> *this,
        const char *pClassName)
{
  CLogicBranchList *v2; // eax
  CLogicBranchList *v3; // esi

  v2 = (CLogicBranchList *)CBaseEntity::operator new(stAllocateBlock: 0x3F4u);
  if ( v2 != nullptr )
    v3 = CLogicBranchList::CLogicBranchList(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1016EC50
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CLogicRelay>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CLogicRelay>::Create(
        CEntityFactory<CLogicRelay> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CLogicRelay>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10171170
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CGameScore>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CGameScore>::Create(
        CEntityFactory<CGameScore> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x35Cu);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CGameScore::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101711B0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CGameEnd>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CGameEnd>::Create(
        CEntityFactory<CGameEnd> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x35Cu);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CGameEnd::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101711F0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CGameText>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CGameText>::Create(
        CEntityFactory<CGameText> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x388u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CGameText::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10171230
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CGamePlayerEquip>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CGamePlayerEquip>::Create(
        CEntityFactory<CGamePlayerEquip> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x45Cu);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CGamePlayerEquip::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10171270
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CGamePlayerTeam>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CGamePlayerTeam>::Create(
        CEntityFactory<CGamePlayerTeam> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x35Cu);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CGamePlayerTeam::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101712B0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CGamePlayerZone>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CGamePlayerZone>::Create(
        CEntityFactory<CGamePlayerZone> *this,
        const char *pClassName)
{
  CGamePlayerZone *v2; // eax
  CGamePlayerZone *v3; // esi

  v2 = (CGamePlayerZone *)CBaseEntity::operator new(stAllocateBlock: 0x3B8u);
  if ( v2 != nullptr )
    v3 = CGamePlayerZone::CGamePlayerZone(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101717E0
// Name: public: virtual unsigned int CEntityFactory<class CMaterialModifyControl>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CMaterialModifyControl>::GetEntitySize(
        CEntityFactory<CMaterialModifyControl> *this)
{
  return 1656;
}

//------------------------------------------------------------------------------
// Address: 0x10172300
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CMaterialModifyControl>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CMaterialModifyControl>::Create(
        CEntityFactory<CMaterialModifyControl> *this,
        const char *pClassName)
{
  CMaterialModifyControl *v2; // eax
  CMaterialModifyControl *v3; // esi

  v2 = (CMaterialModifyControl *)CBaseEntity::operator new(stAllocateBlock: 0x678u);
  if ( v2 != nullptr )
    v3 = CMaterialModifyControl::CMaterialModifyControl(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10172790
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CMessageEntity>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CMessageEntity>::Create(
        CEntityFactory<CMessageEntity> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x360u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CMessageEntity::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10172D30
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CFuncBrush>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CFuncBrush>::Create(
        CEntityFactory<CFuncBrush> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x364u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CFuncBrush::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101730C0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CTriggerBrush>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CTriggerBrush>::Create(
        CEntityFactory<CTriggerBrush> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CTriggerBrush>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10174A30
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CPathKeyFrame>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CPathKeyFrame>::Create(
        CEntityFactory<CPathKeyFrame> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x390u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: true);
    v3->__vftable = (CBaseEntity_vtbl *)&CPathKeyFrame::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10174A70
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CBaseMoveBehavior>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CBaseMoveBehavior>::Create(
        CEntityFactory<CBaseMoveBehavior> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x3BCu);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: true);
    v3->__vftable = (CBaseEntity_vtbl *)&CBaseMoveBehavior::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10174D50
// Name: public: virtual unsigned int CEntityFactory<class CMovieDisplay>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CMovieDisplay>::GetEntitySize(CEntityFactory<CBaseDoor> *this)
{
  return 1284;
}

//------------------------------------------------------------------------------
// Address: 0x10175340
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CMovieDisplay>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CMovieDisplay>::Create(
        CEntityFactory<CMovieDisplay> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x504u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CMovieDisplay::`vftable';
    LOBYTE(v3[1].m_pfnMoveDone) = 0;
    v3[1].m_rgflCoordinateFrame.m_flMatVal[2][2] = NAN;
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10178900
// Name: public: virtual unsigned int CEntityFactory<class CNPC_VehicleDriver>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CNPC_VehicleDriver>::GetEntitySize(CEntityFactory<CNPC_VehicleDriver> *this)
{
  return 3848;
}

//------------------------------------------------------------------------------
// Address: 0x1017B0E0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CNPC_VehicleDriver>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CNPC_VehicleDriver>::Create(
        CEntityFactory<CNPC_VehicleDriver> *this,
        const char *pClassName)
{
  CNPC_VehicleDriver *v2; // eax
  CNPC_VehicleDriver *v3; // esi

  v2 = (CNPC_VehicleDriver *)CBaseEntity::operator new(stAllocateBlock: 0xF08u);
  if ( v2 != nullptr )
    v3 = CNPC_VehicleDriver::CNPC_VehicleDriver(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1017BBB0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CParticleLight>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CParticleLight>::Create(
        CEntityFactory<CParticleLight> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CParticleLight>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1017C410
// Name: public: virtual unsigned int CEntityFactory<class CParticleSystem>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CParticleSystem>::GetEntitySize(CEntityFactory<CParticleSystem> *this)
{
  return 1756;
}

//------------------------------------------------------------------------------
// Address: 0x1017C9C0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CParticleSystem>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CParticleSystem>::Create(
        CEntityFactory<CParticleSystem> *this,
        const char *pClassName)
{
  CParticleSystem *v2; // eax
  CParticleSystem *v3; // esi

  v2 = (CParticleSystem *)CBaseEntity::operator new(stAllocateBlock: 0x6DCu);
  if ( v2 != nullptr )
    v3 = CParticleSystem::CParticleSystem(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1017D4C0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CPathCorner>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CPathCorner>::Create(
        CEntityFactory<CPathCorner> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CPathCorner>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1017D4E0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CPathCornerCrash>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CPathCornerCrash>::Create(
        CEntityFactory<CPathCornerCrash> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CPathCornerCrash>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1017E380
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CPathTrack>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CPathTrack>::Create(
        CEntityFactory<CPathTrack> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CPathTrack>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1017FA60
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CKeepUpright>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CKeepUpright>::Create(
        CEntityFactory<CKeepUpright> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CKeepUpright>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1017FFB0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CPhysThruster>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CPhysThruster>::Create(
        CEntityFactory<CPhysThruster> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CPhysThruster>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1017FFD0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CPhysTorque>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CPhysTorque>::Create(
        CEntityFactory<CPhysTorque> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CPhysTorque>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1017FFF0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CPhysMotor>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CPhysMotor>::Create(
        CEntityFactory<CPhysMotor> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CPhysMotor>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10181A90
// Name: public: virtual unsigned int CEntityFactory<class CBaseDMStart>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CBaseDMStart>::GetEntitySize(CEntityFactory<CRopeAnchor> *this)
{
  return 856;
}

//------------------------------------------------------------------------------
// Address: 0x10181AA0
// Name: public: virtual unsigned int CEntityFactory<class CFire>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CFire>::GetEntitySize(CEntityFactory<CFuncRotating> *this)
{
  return 960;
}

//------------------------------------------------------------------------------
// Address: 0x101830F0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CConstraintAnchor>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IServerNetworkable *__thiscall CEntityFactory<CConstraintAnchor>::Create(
        CEntityFactory<CConstraintAnchor> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x358u);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    *v3 = &CConstraintAnchor::`vftable';
    v3[213] = 1065353216;
  }
  else
  {
    v3 = nullptr;
  }
  (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: pClassName);
  return (IServerNetworkable *)(v3 + 3);
}

//------------------------------------------------------------------------------
// Address: 0x101831F0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CPhysConstraintSystem>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CPhysConstraintSystem>::Create(
        CEntityFactory<CPhysConstraintSystem> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x35Cu);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: true);
    v3->__vftable = (CBaseEntity_vtbl *)&CPhysConstraintSystem::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10184370
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CPhysHinge>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CPhysHinge>::Create(
        CEntityFactory<CPhysHinge> *this,
        const char *pClassName)
{
  CPhysHinge *v2; // eax
  CPhysHinge *v3; // esi

  v2 = (CPhysHinge *)CBaseEntity::operator new(stAllocateBlock: 0x3DCu);
  if ( v2 != nullptr )
    v3 = CPhysHinge::CPhysHinge(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101843B0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CPhysBallSocket>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CPhysBallSocket>::Create(
        CEntityFactory<CPhysBallSocket> *this,
        const char *pClassName)
{
  CPhysBallSocket *v2; // eax
  CPhysBallSocket *v3; // esi

  v2 = (CPhysBallSocket *)CBaseEntity::operator new(stAllocateBlock: 0x390u);
  if ( v2 != nullptr )
    v3 = CPhysBallSocket::CPhysBallSocket(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101843F0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CPhysSlideConstraint>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CPhysSlideConstraint>::Create(
        CEntityFactory<CPhysSlideConstraint> *this,
        const char *pClassName)
{
  CPhysSlideConstraint *v2; // eax
  CPhysSlideConstraint *v3; // esi

  v2 = (CPhysSlideConstraint *)CBaseEntity::operator new(stAllocateBlock: 0x3A8u);
  if ( v2 != nullptr )
    v3 = CPhysSlideConstraint::CPhysSlideConstraint(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10184430
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CPhysFixed>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CPhysFixed>::Create(
        CEntityFactory<CPhysFixed> *this,
        const char *pClassName)
{
  CPhysFixed *v2; // eax
  CPhysFixed *v3; // esi

  v2 = (CPhysFixed *)CBaseEntity::operator new(stAllocateBlock: 0x390u);
  if ( v2 != nullptr )
    v3 = CPhysFixed::CPhysFixed(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10184470
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CPhysPulley>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CPhysPulley>::Create(
        CEntityFactory<CPhysPulley> *this,
        const char *pClassName)
{
  CPhysPulley *v2; // eax
  CPhysPulley *v3; // esi

  v2 = (CPhysPulley *)CBaseEntity::operator new(stAllocateBlock: 0x3BCu);
  if ( v2 != nullptr )
    v3 = CPhysPulley::CPhysPulley(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101844B0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CPhysLength>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CPhysLength>::Create(
        CEntityFactory<CPhysLength> *this,
        const char *pClassName)
{
  CPhysLength *v2; // eax
  CPhysLength *v3; // esi

  v2 = (CPhysLength *)CBaseEntity::operator new(stAllocateBlock: 0x3C0u);
  if ( v2 != nullptr )
    v3 = CPhysLength::CPhysLength(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101844F0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CRagdollConstraint>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CRagdollConstraint>::Create(
        CEntityFactory<CRagdollConstraint> *this,
        const char *pClassName)
{
  CRagdollConstraint *v2; // eax
  CRagdollConstraint *v3; // esi

  v2 = (CRagdollConstraint *)CBaseEntity::operator new(stAllocateBlock: 0x3B4u);
  if ( v2 != nullptr )
    v3 = CRagdollConstraint::CRagdollConstraint(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1018D9D0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CBoneFollower>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CBoneFollower>::Create(
        CEntityFactory<CBoneFollower> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x364u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CBoneFollower::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1018E5C0
// Name: public: virtual unsigned int CEntityFactory<class CPhysicsCannister>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CPhysicsCannister>::GetEntitySize(CEntityFactory<CPhysicsCannister> *this)
{
  return 2428;
}

//------------------------------------------------------------------------------
// Address: 0x1018EDB0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CPhysicsCannister>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CPhysicsCannister>::Create(
        CEntityFactory<CPhysicsCannister> *this,
        const char *pClassName)
{
  CPhysicsCannister *v2; // eax
  CPhysicsCannister *v3; // esi

  v2 = (CPhysicsCannister *)CBaseEntity::operator new(stAllocateBlock: 0x97Cu);
  if ( v2 != nullptr )
    v3 = CPhysicsCannister::CPhysicsCannister(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1019C4B0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CPhysicsNPCSolver>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CPhysicsNPCSolver>::Create(
        CEntityFactory<CPhysicsNPCSolver> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CPhysicsNPCSolver>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1019C4D0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CPhysicsEntitySolver>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IServerNetworkable *__thiscall CEntityFactory<CPhysicsEntitySolver>::Create(
        CEntityFactory<CPhysicsEntitySolver> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x368u);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: true);
    *v3 = &CPhysicsEntitySolver::`vftable';
    v3[213] = -1;
    v3[214] = -1;
  }
  else
  {
    v3 = nullptr;
  }
  (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: pClassName);
  return (IServerNetworkable *)(v3 + 3);
}

//------------------------------------------------------------------------------
// Address: 0x1019D000
// Name: public: virtual unsigned int CEntityFactory<class CRagdollProp>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CRagdollProp>::GetEntitySize(CEntityFactory<CRagdollProp> *this)
{
  return 3696;
}

//------------------------------------------------------------------------------
// Address: 0x1019D010
// Name: public: virtual unsigned int CEntityFactory<class CRagdollPropAttached>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CRagdollPropAttached>::GetEntitySize(CEntityFactory<CRagdollPropAttached> *this)
{
  return 3736;
}

//------------------------------------------------------------------------------
// Address: 0x1019EA80
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CRagdollProp>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CRagdollProp>::Create(
        CEntityFactory<CRagdollProp> *this,
        const char *pClassName)
{
  CRagdollProp *v2; // eax
  CRagdollProp *v3; // esi

  v2 = (CRagdollProp *)CBaseEntity::operator new(stAllocateBlock: 0xE70u);
  if ( v2 != nullptr )
    v3 = CRagdollProp::CRagdollProp(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1019F8A0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CRagdollPropAttached>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CRagdollPropAttached>::Create(
        CEntityFactory<CRagdollPropAttached> *this,
        const char *pClassName)
{
  CRagdollProp *v2; // eax
  CRagdollProp *v3; // esi

  v2 = (CRagdollProp *)CBaseEntity::operator new(stAllocateBlock: 0xE98u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CRagdollProp::CRagdollProp(this: v2);
    v3->CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable = (CRagdollProp_vtbl *)&CRagdollPropAttached::`vftable'{for `CBaseAnimating'};
    v3->CDefaultPlayerPickupVPhysics::IPlayerPickupVPhysics::__vftable = (CDefaultPlayerPickupVPhysics_vtbl *)&CRagdollPropAttached::`vftable'{for `CDefaultPlayerPickupVPhysics'};
    LOBYTE(v3[1].m_Network.m_PVSInfo.m_pClusters) = 0;
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101A4500
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CStatueProp>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CStatueProp>::Create(
        CEntityFactory<CStatueProp> *this,
        const char *pClassName)
{
  CStatueProp *v2; // eax
  CStatueProp *v3; // esi

  v2 = (CStatueProp *)CBaseEntity::operator new(stAllocateBlock: 0x718u);
  if ( v2 != nullptr )
    v3 = CStatueProp::CStatueProp(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101AF560
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CPhysicsSpring>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CPhysicsSpring>::Create(
        CEntityFactory<CPhysicsSpring> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CPhysicsSpring>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101AF580
// Name: public: virtual unsigned int CEntityFactory<class CPhysBox>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CPhysBox>::GetEntitySize(CEntityFactory<CPhysBox> *this)
{
  return 1264;
}

//------------------------------------------------------------------------------
// Address: 0x101AF590
// Name: public: virtual unsigned int CEntityFactory<class CEnvDOFController>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CEnvDOFController>::GetEntitySize(CEntityFactory<CAI_DynamicLink> *this)
{
  return 892;
}

//------------------------------------------------------------------------------
// Address: 0x101AF5A0
// Name: public: virtual unsigned int CEntityFactory<class CItemSoda>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CItemSoda>::GetEntitySize(CEntityFactory<CColorCorrection> *this)
{
  return 1164;
}

//------------------------------------------------------------------------------
// Address: 0x101B03C0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CSimplePhysicsBrush>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CSimplePhysicsBrush>::Create(
        CEntityFactory<CSimplePhysicsBrush> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x354u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CSimplePhysicsBrush::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101B07E0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CPhysImpact>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CPhysImpact>::Create(
        CEntityFactory<CPhysImpact> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x360u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CPhysImpact::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101B0820
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CSimplePhysicsProp>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CSimplePhysicsProp>::Create(
        CEntityFactory<CSimplePhysicsProp> *this,
        const char *pClassName)
{
  CBaseAnimating *v2; // eax
  CBaseAnimating *v3; // esi

  v2 = (CBaseAnimating *)CBaseEntity::operator new(stAllocateBlock: 0x48Cu);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseAnimating::CBaseAnimating(this: v2);
    v3->__vftable = (CBaseAnimating_vtbl *)&CSimplePhysicsProp::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101B0860
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CInfoMassCenter>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CInfoMassCenter>::Create(
        CEntityFactory<CInfoMassCenter> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x354u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CInfoMassCenter::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101B1450
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CPhysExplosion>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CPhysExplosion>::Create(
        CEntityFactory<CPhysExplosion> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CPhysExplosion>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101B1470
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CPhysConvert>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CPhysConvert>::Create(
        CEntityFactory<CPhysConvert> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CPhysConvert>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101B3810
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CPhysBox>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CPhysBox>::Create(
        CEntityFactory<CPhysBox> *this,
        const char *pClassName)
{
  CPhysBox *v2; // eax
  CPhysBox *v3; // esi

  v2 = (CPhysBox *)CBaseEntity::operator new(stAllocateBlock: 0x4F0u);
  if ( v2 != nullptr )
    v3 = CPhysBox::CPhysBox(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101B3850
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CPhysMagnet>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CPhysMagnet>::Create(
        CEntityFactory<CPhysMagnet> *this,
        const char *pClassName)
{
  CPhysMagnet *v2; // eax
  CPhysMagnet *v3; // esi

  v2 = (CPhysMagnet *)CBaseEntity::operator new(stAllocateBlock: 0x4FCu);
  if ( v2 != nullptr )
    v3 = CPhysMagnet::CPhysMagnet(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101BD360
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CSprayCan>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CSprayCan>::Create(
        CEntityFactory<CSprayCan> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x354u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CSprayCan::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101BD3A0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CStripWeapons>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CStripWeapons>::Create(
        CEntityFactory<CStripWeapons> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x354u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CStripWeapons::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101BD3E0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CRevertSaved>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CRevertSaved>::Create(
        CEntityFactory<CRevertSaved> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x360u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CRevertSaved::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101BD420
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CMovementSpeedMod>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CMovementSpeedMod>::Create(
        CEntityFactory<CMovementSpeedMod> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x354u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CMovementSpeedMod::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101CF1E0
// Name: public: virtual unsigned int CEntityFactory<class CPlayerResource>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CPlayerResource>::GetEntitySize(CEntityFactory<CPlayerResource> *this)
{
  return 2676;
}

//------------------------------------------------------------------------------
// Address: 0x101CF980
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CPlayerResource>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CPlayerResource>::Create(
        CEntityFactory<CPlayerResource> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0xA74u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CPlayerResource::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101D11C0
// Name: public: virtual unsigned int CEntityFactory<class CDecal>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CDecal>::GetEntitySize(CEntityFactory<CFuncVPhysicsClip> *this)
{
  return 864;
}

//------------------------------------------------------------------------------
// Address: 0x101D11D0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CPointBonusMapsAccessor>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CPointBonusMapsAccessor>::Create(
        CEntityFactory<CPointBonusMapsAccessor> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x360u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CPointBonusMapsAccessor::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101D1A70
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CPointCamera>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CPointCamera>::Create(
        CEntityFactory<CPointCamera> *this,
        const char *pClassName)
{
  CPointCamera *v2; // eax
  CPointCamera *v3; // esi

  v2 = (CPointCamera *)CBaseEntity::operator new(stAllocateBlock: 0x380u);
  if ( v2 != nullptr )
    v3 = CPointCamera::CPointCamera(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101D20D0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CPointDevShotCamera>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CPointDevShotCamera>::Create(
        CEntityFactory<CPointDevShotCamera> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x35Cu);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CPointDevShotCamera::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101D2BE0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CPointEntityFinder>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CPointEntityFinder>::Create(
        CEntityFactory<CPointEntityFinder> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CPointEntityFinder>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101D35D0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CPointPlayerMoveConstraint>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CPointPlayerMoveConstraint>::Create(
        CEntityFactory<CPointPlayerMoveConstraint> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CPointPlayerMoveConstraint>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101D4690
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CPoseController>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CPoseController>::Create(
        CEntityFactory<CPoseController> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CPoseController>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101D4C10
// Name: public: virtual unsigned int CEntityFactory<class CPointSpotlight>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CPointSpotlight>::GetEntitySize(CEntityFactory<CPointSpotlight> *this)
{
  return 968;
}

//------------------------------------------------------------------------------
// Address: 0x101D4E90
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CPointSpotlight>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CPointSpotlight>::Create(
        CEntityFactory<CPointSpotlight> *this,
        const char *pClassName)
{
  CPointSpotlight *v2; // eax
  CPointSpotlight *v3; // esi

  v2 = (CPointSpotlight *)CBaseEntity::operator new(stAllocateBlock: 0x3C8u);
  if ( v2 != nullptr )
    v3 = CPointSpotlight::CPointSpotlight(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101D7C50
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CPointTemplate>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CPointTemplate>::Create(
        CEntityFactory<CPointTemplate> *this,
        const char *pClassName)
{
  CPointTemplate *v2; // eax
  CPointTemplate *v3; // esi

  v2 = (CPointTemplate *)CBaseEntity::operator new(stAllocateBlock: 0x3D4u);
  if ( v2 != nullptr )
    v3 = CPointTemplate::CPointTemplate(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101D7F90
// Name: public: virtual unsigned int CEntityFactory<class CPointAngleSensor>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CPointAngleSensor>::GetEntitySize(CEntityFactory<CPointTemplate> *this)
{
  return 980;
}

//------------------------------------------------------------------------------
// Address: 0x101D8CE0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CPointAngleSensor>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CPointAngleSensor>::Create(
        CEntityFactory<CPointAngleSensor> *this,
        const char *pClassName)
{
  CPointAngleSensor *v2; // eax
  CPointAngleSensor *v3; // esi

  v2 = (CPointAngleSensor *)CBaseEntity::operator new(stAllocateBlock: 0x3D4u);
  if ( v2 != nullptr )
    v3 = CPointAngleSensor::CPointAngleSensor(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101D8D20
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CPointProximitySensor>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CPointProximitySensor>::Create(
        CEntityFactory<CPointProximitySensor> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CPointProximitySensor>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101D96C0
// Name: public: virtual unsigned int CEntityFactory<class CPointAngularVelocitySensor>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CPointAngularVelocitySensor>::GetEntitySize(
        CEntityFactory<CPointAngularVelocitySensor> *this)
{
  return 1052;
}

//------------------------------------------------------------------------------
// Address: 0x101DA590
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CPointAngularVelocitySensor>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CPointAngularVelocitySensor>::Create(
        CEntityFactory<CPointAngularVelocitySensor> *this,
        const char *pClassName)
{
  CPointAngularVelocitySensor *v2; // eax
  CPointAngularVelocitySensor *v3; // esi

  v2 = (CPointAngularVelocitySensor *)CBaseEntity::operator new(stAllocateBlock: 0x41Cu);
  if ( v2 != nullptr )
    v3 = CPointAngularVelocitySensor::CPointAngularVelocitySensor(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101DA5D0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CPointVelocitySensor>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CPointVelocitySensor>::Create(
        CEntityFactory<CPointVelocitySensor> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CPointVelocitySensor>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101DAF70
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CPointHurt>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IServerNetworkable *__thiscall CEntityFactory<CPointHurt>::Create(
        CEntityFactory<CPointHurt> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x36Cu);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    *v3 = &CPointHurt::`vftable';
    v3[218] = -1;
  }
  else
  {
    v3 = nullptr;
  }
  (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: pClassName);
  return (IServerNetworkable *)(v3 + 3);
}

//------------------------------------------------------------------------------
// Address: 0x101DB660
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CPointTeleport>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CPointTeleport>::Create(
        CEntityFactory<CPointTeleport> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x36Cu);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CPointTeleport::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101DBFD0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CPostProcessController>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CPostProcessController>::Create(
        CEntityFactory<CPostProcessController> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CPostProcessController>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101DD060
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CPredictedViewModel>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IServerNetworkable *__thiscall CEntityFactory<CPredictedViewModel>::Create(
        CEntityFactory<CPredictedViewModel> *this,
        const char *pClassName)
{
  CBaseViewModel *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseViewModel *)CBaseEntity::operator new(stAllocateBlock: 0x4D0u);
  v3 = &v2->CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
  if ( v2 != nullptr )
  {
    CBaseViewModel::CBaseViewModel(this: v2);
    *v3 = &CPredictedViewModel::`vftable'{for `CBaseAnimating'};
    v3[291] = &CPredictedViewModel::`vftable'{for `IHasOwner'};
  }
  else
  {
    v3 = nullptr;
  }
  (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: pClassName);
  return (IServerNetworkable *)(v3 + 3);
}

//------------------------------------------------------------------------------
// Address: 0x101DD310
// Name: public: virtual unsigned int CEntityFactory<class CProp_Hallucination>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CProp_Hallucination>::GetEntitySize(CEntityFactory<CProp_Hallucination> *this)
{
  return 1180;
}

//------------------------------------------------------------------------------
// Address: 0x101DD440
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CProp_Hallucination>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CProp_Hallucination>::Create(
        CEntityFactory<CProp_Hallucination> *this,
        const char *pClassName)
{
  CBaseAnimating *v2; // eax
  CBaseAnimating *v3; // esi

  v2 = (CBaseAnimating *)CBaseEntity::operator new(stAllocateBlock: 0x49Cu);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseAnimating::CBaseAnimating(this: v2);
    v3->__vftable = (CBaseAnimating_vtbl *)&CProp_Hallucination::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101E0640
// Name: public: virtual unsigned int CEntityFactory<class CDynamicProp>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CDynamicProp>::GetEntitySize(CEntityFactory<CDynamicProp> *this)
{
  return 1624;
}

//------------------------------------------------------------------------------
// Address: 0x101E0650
// Name: public: virtual unsigned int CEntityFactory<class COrnamentProp>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<COrnamentProp>::GetEntitySize(CEntityFactory<COrnamentProp> *this)
{
  return 1628;
}

//------------------------------------------------------------------------------
// Address: 0x101E0660
// Name: public: virtual unsigned int CEntityFactory<class CPropDoorRotatingBreakable>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CPropDoorRotatingBreakable>::GetEntitySize(
        CEntityFactory<CPropDoorRotatingBreakable> *this)
{
  return 2144;
}

//------------------------------------------------------------------------------
// Address: 0x101E06D0
// Name: public: virtual unsigned int CEntityFactory<class CPhysicsProp>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CPhysicsProp>::GetEntitySize(CEntityFactory<CPhysSphere> *this)
{
  return 1776;
}

//------------------------------------------------------------------------------
// Address: 0x101E06E0
// Name: public: virtual unsigned int CEntityFactory<class CPhysMagnet>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CPhysMagnet>::GetEntitySize(CEntityFactory<CPhysMagnet> *this)
{
  return 1276;
}

//------------------------------------------------------------------------------
// Address: 0x101E06F0
// Name: public: virtual unsigned int CEntityFactory<class CStatueProp>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CStatueProp>::GetEntitySize(CEntityFactory<CStatueProp> *this)
{
  return 1816;
}

//------------------------------------------------------------------------------
// Address: 0x101E0700
// Name: public: virtual unsigned int CEntityFactory<class CPhysicsPropRespawnable>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CPhysicsPropRespawnable>::GetEntitySize(
        CEntityFactory<CPhysicsPropRespawnable> *this)
{
  return 1828;
}

//------------------------------------------------------------------------------
// Address: 0x101E0710
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CBaseEntity>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CBaseEntity>::Create(
        CEntityFactory<CBaseEntity> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x354u);
  if ( v2 != nullptr )
    v3 = CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101E2400
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CEnableMotionFixup>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CEnableMotionFixup>::Create(
        CEntityFactory<CEnableMotionFixup> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x354u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CEnableMotionFixup::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101E66F0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CDynamicProp>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CDynamicProp>::Create(
        CEntityFactory<CDynamicProp> *this,
        const char *pClassName)
{
  CDynamicProp *v2; // eax
  CDynamicProp *v3; // esi

  v2 = (CDynamicProp *)CBaseEntity::operator new(stAllocateBlock: 0x658u);
  if ( v2 != nullptr )
    v3 = CDynamicProp::CDynamicProp(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101E6730
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CPhysicsProp>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CPhysicsProp>::Create(
        CEntityFactory<CPhysicsProp> *this,
        const char *pClassName)
{
  CPhysicsProp *v2; // eax
  CPhysicsProp *v3; // esi

  v2 = (CPhysicsProp *)CBaseEntity::operator new(stAllocateBlock: 0x6F0u);
  if ( v2 != nullptr )
    v3 = CPhysicsProp::CPhysicsProp(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101E6770
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CPhysicsPropRespawnable>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CPhysicsPropRespawnable>::Create(
        CEntityFactory<CPhysicsPropRespawnable> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CPhysicsPropRespawnable>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101E96B0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class COrnamentProp>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<COrnamentProp>::Create(
        CEntityFactory<COrnamentProp> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<COrnamentProp>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101E96D0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CPhysSphere>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CPhysSphere>::Create(
        CEntityFactory<CPhysSphere> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CPhysSphere>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101E96F0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CPhysicsPropMultiplayer>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CPhysicsPropMultiplayer>::Create(
        CEntityFactory<CPhysicsPropMultiplayer> *this,
        const char *pClassName)
{
  CPhysicsPropMultiplayer *v2; // eax
  CPhysicsPropMultiplayer *v3; // esi

  v2 = (CPhysicsPropMultiplayer *)CBaseEntity::operator new(stAllocateBlock: 0x718u);
  if ( v2 != nullptr )
    v3 = CPhysicsPropMultiplayer::CPhysicsPropMultiplayer(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101EB950
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CPhysBoxMultiplayer>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CPhysBoxMultiplayer>::Create(
        CEntityFactory<CPhysBoxMultiplayer> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CPhysBoxMultiplayer>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101ED910
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CPropDoorRotatingBreakable>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CPropDoorRotatingBreakable>::Create(
        CEntityFactory<CPropDoorRotatingBreakable> *this,
        const char *pClassName)
{
  CPropDoorRotatingBreakable *v2; // eax
  CPropDoorRotatingBreakable *v3; // esi

  v2 = (CPropDoorRotatingBreakable *)CBaseEntity::operator new(stAllocateBlock: 0x860u);
  if ( v2 != nullptr )
    v3 = CPropDoorRotatingBreakable::CPropDoorRotatingBreakable(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101F0070
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CGameGibManager>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CGameGibManager>::Create(
        CEntityFactory<CGameGibManager> *this,
        const char *pClassName)
{
  CGameGibManager *v2; // eax
  CGameGibManager *v3; // esi

  v2 = (CGameGibManager *)CBaseEntity::operator new(stAllocateBlock: 0x384u);
  if ( v2 != nullptr )
    v3 = CGameGibManager::CGameGibManager(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101F1D90
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CRagdollManager>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CRagdollManager>::Create(
        CEntityFactory<CRagdollManager> *this,
        const char *pClassName)
{
  CRagdollManager *v2; // eax
  CRagdollManager *v3; // esi

  v2 = (CRagdollManager *)CBaseEntity::operator new(stAllocateBlock: 0x360u);
  if ( v2 != nullptr )
    v3 = CRagdollManager::CRagdollManager(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101F42B0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CRagdollBoogie>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CRagdollBoogie>::Create(
        CEntityFactory<CRagdollBoogie> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x364u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CRagdollBoogie::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x101F76B0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CRopeKeyframe>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CRopeKeyframe>::Create(
        CEntityFactory<CRopeKeyframe> *this,
        const char *pClassName)
{
  CRopeKeyframe *v2; // eax
  CRopeKeyframe *v3; // esi

  v2 = (CRopeKeyframe *)CBaseEntity::operator new(stAllocateBlock: 0x3A4u);
  if ( v2 != nullptr )
    v3 = CRopeKeyframe::CRopeKeyframe(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10200130
// Name: public: virtual unsigned int CEntityFactory<class CSceneEntity>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CSceneEntity>::GetEntitySize(CEntityFactory<CSceneEntity> *this)
{
  return 1576;
}

//------------------------------------------------------------------------------
// Address: 0x10200140
// Name: public: virtual unsigned int CEntityFactory<class CInstancedSceneEntity>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CInstancedSceneEntity>::GetEntitySize(
        CEntityFactory<CInstancedSceneEntity> *this)
{
  return 1724;
}

//------------------------------------------------------------------------------
// Address: 0x10200150
// Name: public: virtual unsigned int CEntityFactory<class CSceneListManager>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CSceneListManager>::GetEntitySize(CEntityFactory<CSceneListManager> *this)
{
  return 1000;
}

//------------------------------------------------------------------------------
// Address: 0x10208260
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CSceneListManager>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CSceneListManager>::Create(
        CEntityFactory<CSceneListManager> *this,
        const char *pClassName)
{
  CSceneListManager *v2; // eax
  CSceneListManager *v3; // esi

  v2 = (CSceneListManager *)CBaseEntity::operator new(stAllocateBlock: 0x3E8u);
  if ( v2 != nullptr )
    v3 = CSceneListManager::CSceneListManager(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10209BF0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CSceneEntity>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CSceneEntity>::Create(
        CEntityFactory<CSceneEntity> *this,
        const char *pClassName)
{
  CSceneEntity *v2; // eax
  CSceneEntity *v3; // esi

  v2 = (CSceneEntity *)CBaseEntity::operator new(stAllocateBlock: 0x628u);
  if ( v2 != nullptr )
    v3 = CSceneEntity::CSceneEntity(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10209C30
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CSceneManager>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CSceneManager>::Create(
        CEntityFactory<CSceneManager> *this,
        const char *pClassName)
{
  CSceneManager *v2; // eax
  CSceneManager *v3; // esi

  v2 = (CSceneManager *)CBaseEntity::operator new(stAllocateBlock: 0x390u);
  if ( v2 != nullptr )
    v3 = CSceneManager::CSceneManager(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1020B580
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CInstancedSceneEntity>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CInstancedSceneEntity>::Create(
        CEntityFactory<CInstancedSceneEntity> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CInstancedSceneEntity>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1020CEE0
// Name: public: virtual unsigned int CEntityFactory<class CAI_ScriptedSequence>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CAI_ScriptedSequence>::GetEntitySize(CEntityFactory<CAI_ScriptedSequence> *this)
{
  return 1340;
}

//------------------------------------------------------------------------------
// Address: 0x1020E740
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CAI_ScriptedSchedule>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IServerNetworkable *__thiscall CEntityFactory<CAI_ScriptedSchedule>::Create(
        CEntityFactory<CAI_ScriptedSchedule> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x37Cu);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    *v3 = &CAI_ScriptedSchedule::`vftable';
    v3[213] = -1;
    v3[214] = -1;
  }
  else
  {
    v3 = nullptr;
  }
  (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: pClassName);
  return (IServerNetworkable *)(v3 + 3);
}

//------------------------------------------------------------------------------
// Address: 0x1020F890
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CAI_ScriptedSequence>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CAI_ScriptedSequence>::Create(
        CEntityFactory<CAI_ScriptedSequence> *this,
        const char *pClassName)
{
  CAI_ScriptedSequence *v2; // eax
  CAI_ScriptedSequence *v3; // esi

  v2 = (CAI_ScriptedSequence *)CBaseEntity::operator new(stAllocateBlock: 0x53Cu);
  if ( v2 != nullptr )
    v3 = CAI_ScriptedSequence::CAI_ScriptedSequence(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1020F8D0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CAI_ScriptedSentence>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CAI_ScriptedSentence>::Create(
        CEntityFactory<CAI_ScriptedSentence> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CAI_ScriptedSentence>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10210D80
// Name: public: virtual unsigned int CEntityFactory<class CScriptedTarget>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CScriptedTarget>::GetEntitySize(CEntityFactory<CScriptedTarget> *this)
{
  return 3804;
}

//------------------------------------------------------------------------------
// Address: 0x102111B0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CScriptedTarget>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CScriptedTarget>::Create(
        CEntityFactory<CScriptedTarget> *this,
        const char *pClassName)
{
  CScriptedTarget *v2; // eax
  CScriptedTarget *v3; // esi

  v2 = (CScriptedTarget *)CBaseEntity::operator new(stAllocateBlock: 0xEDCu);
  if ( v2 != nullptr )
    v3 = CScriptedTarget::CScriptedTarget(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10213580
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CShadowControl>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CShadowControl>::Create(
        CEntityFactory<CShadowControl> *this,
        const char *pClassName)
{
  CShadowControl *v2; // eax
  CShadowControl *v3; // esi

  v2 = (CShadowControl *)CBaseEntity::operator new(stAllocateBlock: 0x36Cu);
  if ( v2 != nullptr )
    v3 = CShadowControl::CShadowControl(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10213E30
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CSkyboxSwapper>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CSkyboxSwapper>::Create(
        CEntityFactory<CSkyboxSwapper> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x358u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: true);
    v3->__vftable = (CBaseEntity_vtbl *)&CSkyboxSwapper::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10214290
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CSkyCamera>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CSkyCamera>::Create(
        CEntityFactory<CSkyCamera> *this,
        const char *pClassName)
{
  CSkyCamera *v2; // eax
  CSkyCamera *v3; // esi

  v2 = (CSkyCamera *)CBaseEntity::operator new(stAllocateBlock: 0x3C0u);
  if ( v2 != nullptr )
    v3 = CSkyCamera::CSkyCamera(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10214430
// Name: public: virtual unsigned int CEntityFactory<class CSlideshowDisplay>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CSlideshowDisplay>::GetEntitySize(CEntityFactory<CSlideshowDisplay> *this)
{
  return 1200;
}

//------------------------------------------------------------------------------
// Address: 0x102153D0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CSlideshowDisplay>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CSlideshowDisplay>::Create(
        CEntityFactory<CSlideshowDisplay> *this,
        const char *pClassName)
{
  CSlideshowDisplay *v2; // eax
  CSlideshowDisplay *v3; // esi

  v2 = (CSlideshowDisplay *)CBaseEntity::operator new(stAllocateBlock: 0x4B0u);
  if ( v2 != nullptr )
    v3 = CSlideshowDisplay::CSlideshowDisplay(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1021BE20
// Name: public: virtual unsigned int CEntityFactory<class CSoundEnt>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CSoundEnt>::GetEntitySize(CEntityFactory<CSoundEnt> *this)
{
  return 7520;
}

//------------------------------------------------------------------------------
// Address: 0x1021BEA0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CAISound>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CAISound>::Create(
        CEntityFactory<CAISound> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CAISound>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1021CF50
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CSoundEnt>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CSoundEnt>::Create(
        CEntityFactory<CSoundEnt> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CSoundEnt>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1021F900
// Name: public: virtual unsigned int CEntityFactory<class CPhysSlideConstraint>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CPhysSlideConstraint>::GetEntitySize(CEntityFactory<CFogController> *this)
{
  return 936;
}

//------------------------------------------------------------------------------
// Address: 0x1021FE00
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CEnvSoundscape>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CEnvSoundscape>::Create(
        CEntityFactory<CEnvSoundscape> *this,
        const char *pClassName)
{
  CEnvSoundscape *v2; // eax
  CEnvSoundscape *v3; // esi

  v2 = (CEnvSoundscape *)CBaseEntity::operator new(stAllocateBlock: 0x3A4u);
  if ( v2 != nullptr )
    v3 = CEnvSoundscape::CEnvSoundscape(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1021FE40
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CEnvSoundscapeTriggerable>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CEnvSoundscapeTriggerable>::Create(
        CEntityFactory<CEnvSoundscapeTriggerable> *this,
        const char *pClassName)
{
  CEnvSoundscapeTriggerable *v2; // eax
  CEnvSoundscapeTriggerable *v3; // esi

  v2 = (CEnvSoundscapeTriggerable *)CBaseEntity::operator new(stAllocateBlock: 0x3A4u);
  if ( v2 != nullptr )
    v3 = CEnvSoundscapeTriggerable::CEnvSoundscapeTriggerable(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10220620
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CEnvSoundscapeProxy>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CEnvSoundscapeProxy>::Create(
        CEntityFactory<CEnvSoundscapeProxy> *this,
        const char *pClassName)
{
  CEnvSoundscapeProxy *v2; // eax
  CEnvSoundscapeProxy *v3; // esi

  v2 = (CEnvSoundscapeProxy *)CBaseEntity::operator new(stAllocateBlock: 0x3A8u);
  if ( v2 != nullptr )
    v3 = CEnvSoundscapeProxy::CEnvSoundscapeProxy(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x102208A0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CTriggerSoundscape>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CTriggerSoundscape>::Create(
        CEntityFactory<CTriggerSoundscape> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CTriggerSoundscape>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10222FA0
// Name: public: virtual unsigned int CEntityFactory<class CFuncAreaPortalWindow>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CFuncAreaPortalWindow>::GetEntitySize(CEntityFactory<CEnvQuadraticBeam> *this)
{
  return 884;
}

//------------------------------------------------------------------------------
// Address: 0x102230B0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CSpotlightEnd>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CSpotlightEnd>::Create(
        CEntityFactory<CSpotlightEnd> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x374u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CSpotlightEnd::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10223530
// Name: public: virtual unsigned int CEntityFactory<class CTriggerBrush>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CTriggerBrush>::GetEntitySize(CEntityFactory<CCommentaryViewPosition> *this)
{
  return 932;
}

//------------------------------------------------------------------------------
// Address: 0x102240E0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CSprite>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CSprite>::Create(
        CEntityFactory<CSprite> *this,
        const char *pClassName)
{
  CSprite *v2; // eax
  CSprite *v3; // esi

  v2 = (CSprite *)CBaseEntity::operator new(stAllocateBlock: 0x3A4u);
  if ( v2 != nullptr )
    v3 = CSprite::CSprite(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10224680
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CSpriteOriented>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CSpriteOriented>::Create(
        CEntityFactory<CSpriteOriented> *this,
        const char *pClassName)
{
  CSprite *v2; // eax
  CSprite *v3; // esi

  v2 = (CSprite *)CBaseEntity::operator new(stAllocateBlock: 0x3A4u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CSprite::CSprite(this: v2);
    v3->__vftable = (CSprite_vtbl *)&CSpriteOriented::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10224CD0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CParticlePerformanceMonitor>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CParticlePerformanceMonitor>::Create(
        CEntityFactory<CParticlePerformanceMonitor> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x358u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CParticlePerformanceMonitor::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1022B6A0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CNullEntity>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CNullEntity>::Create(
        CEntityFactory<CNullEntity> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x354u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CNullEntity::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1022B6E0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CPointEntity>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CPointEntity>::Create(
        CEntityFactory<CPointEntity> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x354u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CPointEntity::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1022B770
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CBaseDMStart>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CBaseDMStart>::Create(
        CEntityFactory<CBaseDMStart> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x358u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CBaseDMStart::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1022BD60
// Name: public: virtual unsigned int CEntityFactory<class CPathKeyFrame>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CPathKeyFrame>::GetEntitySize(CEntityFactory<CAI_NetworkManager> *this)
{
  return 912;
}

//------------------------------------------------------------------------------
// Address: 0x1022C5E0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CSun>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CSun>::Create(CEntityFactory<CSun> *this, const char *pClassName)
{
  CSun *v2; // eax
  CSun *v3; // esi

  v2 = (CSun *)CBaseEntity::operator new(stAllocateBlock: 0x390u);
  if ( v2 != nullptr )
    v3 = CSun::CSun(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1022C780
// Name: public: virtual unsigned int CEntityFactory<class CSunlightShadowControl>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CSunlightShadowControl>::GetEntitySize(
        CEntityFactory<CSunlightShadowControl> *this)
{
  return 1156;
}

//------------------------------------------------------------------------------
// Address: 0x1022D340
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CSunlightShadowControl>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CSunlightShadowControl>::Create(
        CEntityFactory<CSunlightShadowControl> *this,
        const char *pClassName)
{
  CSunlightShadowControl *v2; // eax
  CSunlightShadowControl *v3; // esi

  v2 = (CSunlightShadowControl *)CBaseEntity::operator new(stAllocateBlock: 0x484u);
  if ( v2 != nullptr )
    v3 = CSunlightShadowControl::CSunlightShadowControl(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1022E130
// Name: public: virtual unsigned int CEntityFactory<class CFuncTankTrain>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CFuncTankTrain>::GetEntitySize(CEntityFactory<CLogicRandomOutputs> *this)
{
  return 1104;
}

//------------------------------------------------------------------------------
// Address: 0x1022E8B0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CTankTargetChange>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CTankTargetChange>::Create(
        CEntityFactory<CTankTargetChange> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CTankTargetChange>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1022E8D0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CTankTrainAI>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IServerNetworkable *__thiscall CEntityFactory<CTankTrainAI>::Create(
        CEntityFactory<CTankTrainAI> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x378u);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    *v3 = &CTankTrainAI::`vftable';
    v3[213] = -1;
    v3[214] = -1;
  }
  else
  {
    v3 = nullptr;
  }
  (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: pClassName);
  return (IServerNetworkable *)(v3 + 3);
}

//------------------------------------------------------------------------------
// Address: 0x1022E990
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CFuncTankTrain>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CFuncTankTrain>::Create(
        CEntityFactory<CFuncTankTrain> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CFuncTankTrain>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1022F3B0
// Name: public: virtual unsigned int CEntityFactory<class CEnvScreenOverlay>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CEnvScreenOverlay>::GetEntitySize(CEntityFactory<CEnvScreenOverlay> *this)
{
  return 944;
}

//------------------------------------------------------------------------------
// Address: 0x1022FC50
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CTeam>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CTeam>::Create(CEntityFactory<CTeam> *this, const char *pClassName)
{
  CTeam *v2; // eax
  CTeam *v3; // esi

  v2 = (CTeam *)CBaseEntity::operator new(stAllocateBlock: 0x3B0u);
  if ( v2 != nullptr )
    v3 = CTeam::CTeam(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10230620
// Name: public: virtual unsigned int CEntityFactory<class CPlasma>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CPlasma>::GetEntitySize(CEntityFactory<CFogVolume> *this)
{
  return 880;
}

//------------------------------------------------------------------------------
// Address: 0x10230630
// Name: public: virtual unsigned int CEntityFactory<class CGameText>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CGameText>::GetEntitySize(CEntityFactory<CBaseFilter> *this)
{
  return 904;
}

//------------------------------------------------------------------------------
// Address: 0x102307A0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CTeamSpawnPoint>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CTeamSpawnPoint>::Create(
        CEntityFactory<CTeamSpawnPoint> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CTeamSpawnPoint>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x102307C0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CTeamVehicleSpawnPoint>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CTeamVehicleSpawnPoint>::Create(
        CEntityFactory<CTeamVehicleSpawnPoint> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CTeamVehicleSpawnPoint>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10232E40
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CTesla>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CTesla>::Create(CEntityFactory<CTesla> *this, const char *pClassName)
{
  CTesla *v2; // eax
  CTesla *v3; // esi

  v2 = (CTesla *)CBaseEntity::operator new(stAllocateBlock: 0x38Cu);
  if ( v2 != nullptr )
    v3 = CTesla::CTesla(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10232F80
// Name: public: virtual unsigned int CEntityFactory<class CTriggerVolume>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CTriggerVolume>::GetEntitySize(CEntityFactory<CInfoTarget> *this)
{
  return 852;
}

//------------------------------------------------------------------------------
// Address: 0x10233050
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CHandleDummy>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CHandleDummy>::Create(
        CEntityFactory<CHandleDummy> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x354u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CHandleDummy::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x102332F0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CHandleTest>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CHandleTest>::Create(
        CEntityFactory<CHandleTest> *this,
        const char *pClassName)
{
  CHandleTest *v2; // eax
  CHandleTest *v3; // esi

  v2 = (CHandleTest *)CBaseEntity::operator new(stAllocateBlock: 0x35Cu);
  if ( v2 != nullptr )
    v3 = CHandleTest::CHandleTest(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10233600
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CTest_ProxyToggle_Networkable>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CTest_ProxyToggle_Networkable>::Create(
        CEntityFactory<CTest_ProxyToggle_Networkable> *this,
        const char *pClassName)
{
  CTest_ProxyToggle_Networkable *v2; // eax
  CTest_ProxyToggle_Networkable *v3; // esi

  v2 = (CTest_ProxyToggle_Networkable *)CBaseEntity::operator new(stAllocateBlock: 0x358u);
  if ( v2 != nullptr )
    v3 = CTest_ProxyToggle_Networkable::CTest_ProxyToggle_Networkable(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10233E90
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CTestTraceline>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CTestTraceline>::Create(
        CEntityFactory<CTestTraceline> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x354u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CTestTraceline::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10235240
// Name: public: virtual unsigned int CEntityFactory<class CFuncTrackTrain>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CFuncTrackTrain>::GetEntitySize(CEntityFactory<CFuncTrackTrain> *this)
{
  return 1080;
}

//------------------------------------------------------------------------------
// Address: 0x10235250
// Name: public: virtual unsigned int CEntityFactory<class CFuncTrackAuto>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CFuncTrackAuto>::GetEntitySize(CEntityFactory<CFuncMoveLinear> *this)
{
  return 1060;
}

//------------------------------------------------------------------------------
// Address: 0x10237270
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CFuncTrainControls>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CFuncTrainControls>::Create(
        CEntityFactory<CFuncTrainControls> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x354u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CFuncTrainControls::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x102379C0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CFuncPlat>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CFuncPlat>::Create(
        CEntityFactory<CFuncPlat> *this,
        const char *pClassName)
{
  CBaseToggle *v2; // eax
  CBaseToggle *v3; // esi

  v2 = (CBaseToggle *)CBaseEntity::operator new(stAllocateBlock: 0x3E8u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseToggle::CBaseToggle(this: v2);
    v3->__vftable = (CBaseToggle_vtbl *)&CFuncPlat::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10237A00
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CFuncTrain>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IServerNetworkable *__thiscall CEntityFactory<CFuncTrain>::Create(
        CEntityFactory<CFuncTrain> *this,
        const char *pClassName)
{
  CBaseToggle *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseToggle *)CBaseEntity::operator new(stAllocateBlock: 0x3FCu);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseToggle::CBaseToggle(this: v2);
    *v3 = &CFuncTrain::`vftable';
    v3[249] = -1;
    v3[251] = -1;
  }
  else
  {
    v3 = nullptr;
  }
  (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: pClassName);
  return (IServerNetworkable *)(v3 + 3);
}

//------------------------------------------------------------------------------
// Address: 0x10238190
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CFuncPlatRot>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CFuncPlatRot>::Create(
        CEntityFactory<CFuncPlatRot> *this,
        const char *pClassName)
{
  CBaseToggle *v2; // eax
  CBaseToggle *v3; // esi

  v2 = (CBaseToggle *)CBaseEntity::operator new(stAllocateBlock: 0x400u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseToggle::CBaseToggle(this: v2);
    v3->__vftable = (CBaseToggle_vtbl *)&CFuncPlatRot::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x102381D0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CFuncTrackTrain>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CFuncTrackTrain>::Create(
        CEntityFactory<CFuncTrackTrain> *this,
        const char *pClassName)
{
  CFuncTrackTrain *v2; // eax
  CFuncTrackTrain *v3; // esi

  v2 = (CFuncTrackTrain *)CBaseEntity::operator new(stAllocateBlock: 0x438u);
  if ( v2 != nullptr )
    v3 = CFuncTrackTrain::CFuncTrackTrain(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10238210
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CFuncTrackChange>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CFuncTrackChange>::Create(
        CEntityFactory<CFuncTrackChange> *this,
        const char *pClassName)
{
  CBaseToggle *v2; // eax
  CBaseToggle *v3; // esi

  v2 = (CBaseToggle *)CBaseEntity::operator new(stAllocateBlock: 0x424u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseToggle::CBaseToggle(this: v2);
    v3->__vftable = (CBaseToggle_vtbl *)&CFuncTrackChange::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10238250
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CFuncTrackAuto>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CFuncTrackAuto>::Create(
        CEntityFactory<CFuncTrackAuto> *this,
        const char *pClassName)
{
  CBaseToggle *v2; // eax
  CBaseToggle *v3; // esi

  v2 = (CBaseToggle *)CBaseEntity::operator new(stAllocateBlock: 0x424u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseToggle::CBaseToggle(this: v2);
    v3->__vftable = (CBaseToggle_vtbl *)&CFuncTrackAuto::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1023E1F0
// Name: public: virtual unsigned int CEntityFactory<class CTriggerHurt>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CTriggerHurt>::GetEntitySize(CEntityFactory<CTriggerHurt> *this)
{
  return 1252;
}

//------------------------------------------------------------------------------
// Address: 0x1023E200
// Name: public: virtual unsigned int CEntityFactory<class CChangeLevel>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CChangeLevel>::GetEntitySize(CEntityFactory<CChangeLevel> *this)
{
  return 1244;
}

//------------------------------------------------------------------------------
// Address: 0x1023E210
// Name: public: virtual unsigned int CEntityFactory<class CTriggerPush>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CTriggerPush>::GetEntitySize(CEntityFactory<CTriggerPush> *this)
{
  return 1172;
}

//------------------------------------------------------------------------------
// Address: 0x1023E220
// Name: public: virtual unsigned int CEntityFactory<class CLogicCompare>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CLogicCompare>::GetEntitySize(CEntityFactory<CAI_FightFromCoverGoal> *this)
{
  return 956;
}

//------------------------------------------------------------------------------
// Address: 0x1023E230
// Name: public: virtual unsigned int CEntityFactory<class CTriggerProximity>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CTriggerProximity>::GetEntitySize(CEntityFactory<CTriggerProximity> *this)
{
  return 1192;
}

//------------------------------------------------------------------------------
// Address: 0x1023E240
// Name: public: virtual unsigned int CEntityFactory<class CTriggerHierarchy>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CTriggerHierarchy>::GetEntitySize(CEntityFactory<CEnvProjectedTexture> *this)
{
  return 1184;
}

//------------------------------------------------------------------------------
// Address: 0x1023E250
// Name: public: virtual unsigned int CEntityFactory<class CTriggerImpact>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CTriggerImpact>::GetEntitySize(CEntityFactory<CTriggerImpact> *this)
{
  return 1212;
}

//------------------------------------------------------------------------------
// Address: 0x1023E260
// Name: public: virtual unsigned int CEntityFactory<class CHostageRescueZone>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CHostageRescueZone>::GetEntitySize(CEntityFactory<CTriggerAutoCrouch> *this)
{
  return 1152;
}

//------------------------------------------------------------------------------
// Address: 0x10240750
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CAI_ChangeTarget>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CAI_ChangeTarget>::Create(
        CEntityFactory<CAI_ChangeTarget> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x358u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CAI_ChangeTarget::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10240790
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CAI_ChangeHintGroup>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CAI_ChangeHintGroup>::Create(
        CEntityFactory<CAI_ChangeHintGroup> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x368u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CAI_ChangeHintGroup::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x102407D0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CTriggerViewProxy>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IServerNetworkable *__thiscall CEntityFactory<CTriggerViewProxy>::Create(
        CEntityFactory<CTriggerViewProxy> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x3BCu);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    *v3 = &CTriggerViewProxy::`vftable';
    v3[213] = -1;
  }
  else
  {
    v3 = nullptr;
  }
  (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: pClassName);
  return (IServerNetworkable *)(v3 + 3);
}

//------------------------------------------------------------------------------
// Address: 0x10240F80
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CTriggerVolume>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CTriggerVolume>::Create(
        CEntityFactory<CTriggerVolume> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x354u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CTriggerVolume::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10240FC0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CTriggerCamera>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CTriggerCamera>::Create(
        CEntityFactory<CTriggerCamera> *this,
        const char *pClassName)
{
  CTriggerCamera *v2; // eax
  CTriggerCamera *v3; // esi

  v2 = (CTriggerCamera *)CBaseEntity::operator new(stAllocateBlock: 0x3CCu);
  if ( v2 != nullptr )
    v3 = CTriggerCamera::CTriggerCamera(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10242FB0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CTriggerWind>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CTriggerWind>::Create(
        CEntityFactory<CTriggerWind> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CTriggerWind>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10242FD0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CTriggerVPhysicsMotion>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CTriggerVPhysicsMotion>::Create(
        CEntityFactory<CTriggerVPhysicsMotion> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CTriggerVPhysicsMotion>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10247D20
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CBaseTrigger>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CBaseTrigger>::Create(
        CEntityFactory<CBaseTrigger> *this,
        const char *pClassName)
{
  CBaseTrigger *v2; // eax
  CBaseTrigger *v3; // esi

  v2 = (CBaseTrigger *)CBaseEntity::operator new(stAllocateBlock: 0x480u);
  if ( v2 != nullptr )
    v3 = CBaseTrigger::CBaseTrigger(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10247D60
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CTriggerCameraMultiplayer>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CTriggerCameraMultiplayer>::Create(
        CEntityFactory<CTriggerCameraMultiplayer> *this,
        const char *pClassName)
{
  CTriggerCameraMultiplayer *v2; // eax
  CTriggerCameraMultiplayer *v3; // esi

  v2 = (CTriggerCameraMultiplayer *)CBaseEntity::operator new(stAllocateBlock: 0x3A4u);
  if ( v2 != nullptr )
    v3 = CTriggerCameraMultiplayer::CTriggerCameraMultiplayer(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10248EF0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CTriggerRemove>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CTriggerRemove>::Create(
        CEntityFactory<CTriggerRemove> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CTriggerRemove>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10248F10
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CTriggerHurt>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CTriggerHurt>::Create(
        CEntityFactory<CTriggerHurt> *this,
        const char *pClassName)
{
  CTriggerHurt *v2; // eax
  CTriggerHurt *v3; // esi

  v2 = (CTriggerHurt *)CBaseEntity::operator new(stAllocateBlock: 0x4E4u);
  if ( v2 != nullptr )
    v3 = CTriggerHurt::CTriggerHurt(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10248F50
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CTriggerMultiple>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CTriggerMultiple>::Create(
        CEntityFactory<CTriggerMultiple> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CTriggerMultiple>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10248F70
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CChangeLevel>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CChangeLevel>::Create(
        CEntityFactory<CChangeLevel> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CChangeLevel>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10248F90
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CTriggerPush>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CTriggerPush>::Create(
        CEntityFactory<CTriggerPush> *this,
        const char *pClassName)
{
  CBaseTrigger *v2; // eax
  CBaseTrigger *v3; // esi

  v2 = (CBaseTrigger *)CBaseEntity::operator new(stAllocateBlock: 0x494u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseTrigger::CBaseTrigger(this: v2);
    v3->__vftable = (CBaseTrigger_vtbl *)&CTriggerPush::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10248FD0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CTriggerTeleport>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CTriggerTeleport>::Create(
        CEntityFactory<CTriggerTeleport> *this,
        const char *pClassName)
{
  CBaseTrigger *v2; // eax
  CBaseTrigger *v3; // esi

  v2 = (CBaseTrigger *)CBaseEntity::operator new(stAllocateBlock: 0x488u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseTrigger::CBaseTrigger(this: v2);
    v3->__vftable = (CBaseTrigger_vtbl *)&CTriggerTeleport::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10249010
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CTriggerToggleSave>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CTriggerToggleSave>::Create(
        CEntityFactory<CTriggerToggleSave> *this,
        const char *pClassName)
{
  CBaseTrigger *v2; // eax
  CBaseTrigger *v3; // esi

  v2 = (CBaseTrigger *)CBaseEntity::operator new(stAllocateBlock: 0x484u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseTrigger::CBaseTrigger(this: v2);
    v3->__vftable = (CBaseTrigger_vtbl *)&CTriggerToggleSave::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10249050
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CTriggerSave>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CTriggerSave>::Create(
        CEntityFactory<CTriggerSave> *this,
        const char *pClassName)
{
  CBaseTrigger *v2; // eax
  CBaseTrigger *v3; // esi

  v2 = (CBaseTrigger *)CBaseEntity::operator new(stAllocateBlock: 0x48Cu);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseTrigger::CBaseTrigger(this: v2);
    v3->__vftable = (CBaseTrigger_vtbl *)&CTriggerSave::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10249090
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CTriggerGravity>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CTriggerGravity>::Create(
        CEntityFactory<CTriggerGravity> *this,
        const char *pClassName)
{
  CBaseTrigger *v2; // eax
  CBaseTrigger *v3; // esi

  v2 = (CBaseTrigger *)CBaseEntity::operator new(stAllocateBlock: 0x480u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseTrigger::CBaseTrigger(this: v2);
    v3->__vftable = (CBaseTrigger_vtbl *)&CTriggerGravity::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x102490D0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CTriggerCDAudio>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CTriggerCDAudio>::Create(
        CEntityFactory<CTriggerCDAudio> *this,
        const char *pClassName)
{
  CBaseTrigger *v2; // eax
  CBaseTrigger *v3; // esi

  v2 = (CBaseTrigger *)CBaseEntity::operator new(stAllocateBlock: 0x480u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseTrigger::CBaseTrigger(this: v2);
    v3->__vftable = (CBaseTrigger_vtbl *)&CTriggerCDAudio::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10249110
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CTriggerProximity>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CTriggerProximity>::Create(
        CEntityFactory<CTriggerProximity> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CTriggerProximity>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10249130
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CTriggerPlayerMovement>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CTriggerPlayerMovement>::Create(
        CEntityFactory<CTriggerPlayerMovement> *this,
        const char *pClassName)
{
  CBaseTrigger *v2; // eax
  CBaseTrigger *v3; // esi

  v2 = (CBaseTrigger *)CBaseEntity::operator new(stAllocateBlock: 0x480u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseTrigger::CBaseTrigger(this: v2);
    v3->__vftable = (CBaseTrigger_vtbl *)&CTriggerPlayerMovement::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10249170
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CServerRagdollTrigger>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CServerRagdollTrigger>::Create(
        CEntityFactory<CServerRagdollTrigger> *this,
        const char *pClassName)
{
  CBaseTrigger *v2; // eax
  CBaseTrigger *v3; // esi

  v2 = (CBaseTrigger *)CBaseEntity::operator new(stAllocateBlock: 0x480u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseTrigger::CBaseTrigger(this: v2);
    v3->__vftable = (CBaseTrigger_vtbl *)&CServerRagdollTrigger::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x102491B0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CTriggerAutoCrouch>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CTriggerAutoCrouch>::Create(
        CEntityFactory<CTriggerAutoCrouch> *this,
        const char *pClassName)
{
  CBaseTrigger *v2; // eax
  CBaseTrigger *v3; // esi

  v2 = (CBaseTrigger *)CBaseEntity::operator new(stAllocateBlock: 0x480u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseTrigger::CBaseTrigger(this: v2);
    v3->__vftable = (CBaseTrigger_vtbl *)&CTriggerAutoCrouch::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10249870
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CTriggerOnce>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CTriggerOnce>::Create(
        CEntityFactory<CTriggerOnce> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CTriggerOnce>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10249890
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CTriggerLook>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CTriggerLook>::Create(
        CEntityFactory<CTriggerLook> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CTriggerLook>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x102498B0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CTriggerHierarchy>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CTriggerHierarchy>::Create(
        CEntityFactory<CTriggerHierarchy> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CTriggerHierarchy>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x102498D0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CTriggerImpact>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CTriggerImpact>::Create(
        CEntityFactory<CTriggerImpact> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CTriggerImpact>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10253400
// Name: public: virtual unsigned int CEntityFactory<class CPropVehicle>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CPropVehicle>::GetEntitySize(CEntityFactory<CPropVehicle> *this)
{
  return 1508;
}

//------------------------------------------------------------------------------
// Address: 0x10253410
// Name: public: virtual unsigned int CEntityFactory<class CPropVehicleDriveable>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CPropVehicleDriveable>::GetEntitySize(
        CEntityFactory<CPropVehicleDriveable> *this)
{
  return 1744;
}

//------------------------------------------------------------------------------
// Address: 0x10254340
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CPropVehicle>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CPropVehicle>::Create(
        CEntityFactory<CPropVehicle> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CPropVehicle>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10254FF0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CPropVehicleDriveable>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CPropVehicleDriveable>::Create(
        CEntityFactory<CPropVehicleDriveable> *this,
        const char *pClassName)
{
  CPropVehicleDriveable *v2; // eax
  CPropVehicleDriveable *v3; // esi

  v2 = (CPropVehicleDriveable *)CBaseEntity::operator new(stAllocateBlock: 0x6D0u);
  if ( v2 != nullptr )
    v3 = CPropVehicleDriveable::CPropVehicleDriveable(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1025CDF0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CVGuiScreen>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CVGuiScreen>::Create(
        CEntityFactory<CVGuiScreen> *this,
        const char *pClassName)
{
  CVGuiScreen *v2; // eax
  CVGuiScreen *v3; // esi

  v2 = (CVGuiScreen *)CBaseEntity::operator new(stAllocateBlock: 0x378u);
  if ( v2 != nullptr )
    v3 = CVGuiScreen::CVGuiScreen(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10263820
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CWaterBullet>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CWaterBullet>::Create(
        CEntityFactory<CWaterBullet> *this,
        const char *pClassName)
{
  CBaseAnimating *v2; // eax
  CBaseAnimating *v3; // esi

  v2 = (CBaseAnimating *)CBaseEntity::operator new(stAllocateBlock: 0x48Cu);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseAnimating::CBaseAnimating(this: v2);
    v3->__vftable = (CBaseAnimating_vtbl *)&CWaterBullet::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10263C90
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CWaterLODControl>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CWaterLODControl>::Create(
        CEntityFactory<CWaterLODControl> *this,
        const char *pClassName)
{
  CWaterLODControl *v2; // eax
  CWaterLODControl *v3; // esi

  v2 = (CWaterLODControl *)CBaseEntity::operator new(stAllocateBlock: 0x35Cu);
  if ( v2 != nullptr )
    v3 = CWaterLODControl::CWaterLODControl(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10265290
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CWC_UpdateIgnoreList>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CWC_UpdateIgnoreList>::Create(
        CEntityFactory<CWC_UpdateIgnoreList> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x394u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CWC_UpdateIgnoreList::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10266F20
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CWeightButton>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CWeightButton>::Create(
        CEntityFactory<CWeightButton> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CWeightButton>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10268070
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CInfoGameEventProxy>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CInfoGameEventProxy>::Create(
        CEntityFactory<CInfoGameEventProxy> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x360u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CInfoGameEventProxy::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x102680B0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CDecal>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CDecal>::Create(CEntityFactory<CDecal> *this, const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x360u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CDecal::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x102680F0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CProjectedDecal>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CProjectedDecal>::Create(
        CEntityFactory<CProjectedDecal> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x35Cu);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CProjectedDecal::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x102687B0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CWorld>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CWorld>::Create(CEntityFactory<CWorld> *this, const char *pClassName)
{
  CWorld *v2; // eax
  CWorld *v3; // esi

  v2 = (CWorld *)CBaseEntity::operator new(stAllocateBlock: 0x394u);
  if ( v2 != nullptr )
    v3 = CWorld::CWorld(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10273DE0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CCSGameRulesProxy>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CCSGameRulesProxy>::Create(
        CEntityFactory<CCSGameRulesProxy> *this,
        const char *pClassName)
{
  CGameRulesProxy *v2; // eax
  CGameRulesProxy *v3; // esi

  v2 = (CGameRulesProxy *)CBaseEntity::operator new(stAllocateBlock: 0x354u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CGameRulesProxy::CGameRulesProxy(this: v2);
    v3->__vftable = (CGameRulesProxy_vtbl *)&CCSGameRulesProxy::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10280C70
// Name: public: virtual unsigned int CEntityFactory<class CCSRagdoll>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CCSRagdoll>::GetEntitySize(CEntityFactory<CCSRagdoll> *this)
{
  return 1220;
}

//------------------------------------------------------------------------------
// Address: 0x10280C80
// Name: public: virtual unsigned int CEntityFactory<class CCSPlayer>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CCSPlayer>::GetEntitySize(CEntityFactory<CCSPlayer> *this)
{
  return 7052;
}

//------------------------------------------------------------------------------
// Address: 0x1028F200
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CCSRagdoll>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CCSRagdoll>::Create(
        CEntityFactory<CCSRagdoll> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CCSRagdoll>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10291BB0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CCSPlayer>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CCSPlayer>::Create(
        CEntityFactory<CCSPlayer> *this,
        const char *pClassName)
{
  CCSPlayer *v2; // eax
  CCSPlayer *v3; // esi

  v2 = (CCSPlayer *)CBaseEntity::operator new(stAllocateBlock: 0x1B8Cu);
  if ( v2 != nullptr )
    v3 = CCSPlayer::CCSPlayer(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10292470
// Name: public: virtual unsigned int CEntityFactory<class CCSPlayerResource>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CCSPlayerResource>::GetEntitySize(CEntityFactory<CCSPlayerResource> *this)
{
  return 4768;
}

//------------------------------------------------------------------------------
// Address: 0x10294680
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CCSPlayerResource>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CCSPlayerResource>::Create(
        CEntityFactory<CCSPlayerResource> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x12A0u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CCSPlayerResource::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10296020
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CFootstepControl>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CFootstepControl>::Create(
        CEntityFactory<CFootstepControl> *this,
        const char *pClassName)
{
  CBaseTrigger *v2; // eax
  CBaseTrigger *v3; // esi

  v2 = (CBaseTrigger *)CBaseEntity::operator new(stAllocateBlock: 0x488u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseTrigger::CBaseTrigger(this: v2);
    v3->__vftable = (CBaseTrigger_vtbl *)&CFootstepControl::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10297E50
// Name: public: virtual unsigned int CEntityFactory<class CCSTeam>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CCSTeam>::GetEntitySize(CEntityFactory<CAI_StandoffGoal> *this)
{
  return 952;
}

//------------------------------------------------------------------------------
// Address: 0x10297EE0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CCSTeam>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CCSTeam>::Create(
        CEntityFactory<CCSTeam> *this,
        const char *pClassName)
{
  CTeam *v2; // eax
  CTeam *v3; // esi

  v2 = (CTeam *)CBaseEntity::operator new(stAllocateBlock: 0x3B8u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CTeam::CTeam(this: v2);
    v3->__vftable = (CTeam_vtbl *)&CCSTeam::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10299CB0
// Name: public: virtual unsigned int CEntityFactory<class CMolotovProjectile>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CMolotovProjectile>::GetEntitySize(CEntityFactory<CDecoyProjectile> *this)
{
  return 1236;
}

//------------------------------------------------------------------------------
// Address: 0x1029A660
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CDecoyProjectile>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IServerNetworkable *__thiscall CEntityFactory<CDecoyProjectile>::Create(
        CEntityFactory<CDecoyProjectile> *this,
        const char *pClassName)
{
  CBaseGrenade *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseGrenade *)CBaseEntity::operator new(stAllocateBlock: 0x4D4u);
  v3 = &v2->CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
  if ( v2 != nullptr )
  {
    CBaseGrenade::CBaseGrenade(this: v2);
    *v3 = &CDecoyProjectile::`vftable'{for `CBaseAnimating'};
    v3[291] = &CDecoyProjectile::`vftable'{for `CDefaultPlayerPickupVPhysics'};
  }
  else
  {
    v3 = nullptr;
  }
  (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: pClassName);
  return (IServerNetworkable *)(v3 + 3);
}

//------------------------------------------------------------------------------
// Address: 0x1029A7C0
// Name: public: virtual unsigned int CEntityFactory<class CFogTrigger>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CFogTrigger>::GetEntitySize(CEntityFactory<CEnvMicrophone> *this)
{
  return 1228;
}

//------------------------------------------------------------------------------
// Address: 0x1029B430
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CFlashbangProjectile>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CFlashbangProjectile>::Create(
        CEntityFactory<CFlashbangProjectile> *this,
        const char *pClassName)
{
  CFlashbangProjectile *v2; // eax
  CFlashbangProjectile *v3; // esi

  v2 = (CFlashbangProjectile *)CBaseEntity::operator new(stAllocateBlock: 0x4CCu);
  if ( v2 != nullptr )
    v3 = CFlashbangProjectile::CFlashbangProjectile(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1029B570
// Name: public: virtual unsigned int CEntityFactory<class CPredictedViewModel>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CPredictedViewModel>::GetEntitySize(CEntityFactory<CBaseViewModel> *this)
{
  return 1232;
}

//------------------------------------------------------------------------------
// Address: 0x1029BC00
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CBombTarget>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CBombTarget>::Create(
        CEntityFactory<CBombTarget> *this,
        const char *pClassName)
{
  CBombTarget *v2; // eax
  CBombTarget *v3; // esi

  v2 = (CBombTarget *)CBaseEntity::operator new(stAllocateBlock: 0x4D0u);
  if ( v2 != nullptr )
    v3 = CBombTarget::CBombTarget(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1029BE90
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CBuyZone>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IServerNetworkable *__thiscall CEntityFactory<CBuyZone>::Create(CEntityFactory<CBuyZone> *this, const char *pClassName)
{
  CBaseTrigger *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseTrigger *)CBaseEntity::operator new(stAllocateBlock: 0x484u);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseTrigger::CBaseTrigger(this: v2);
    *v3 = &CBuyZone::`vftable';
    v3[288] = -1;
  }
  else
  {
    v3 = nullptr;
  }
  (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: pClassName);
  return (IServerNetworkable *)(v3 + 3);
}

//------------------------------------------------------------------------------
// Address: 0x1029C070
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CHostageRescueZone>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CHostageRescueZone>::Create(
        CEntityFactory<CHostageRescueZone> *this,
        const char *pClassName)
{
  CBaseTrigger *v2; // eax
  CBaseTrigger *v3; // esi

  v2 = (CBaseTrigger *)CBaseEntity::operator new(stAllocateBlock: 0x480u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseTrigger::CBaseTrigger(this: v2);
    v3->__vftable = (CBaseTrigger_vtbl *)&CHostageRescueZone::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x102A3A30
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CHEGrenadeProjectile>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IServerNetworkable *__thiscall CEntityFactory<CHEGrenadeProjectile>::Create(
        CEntityFactory<CHEGrenadeProjectile> *this,
        const char *pClassName)
{
  CBaseGrenade *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseGrenade *)CBaseEntity::operator new(stAllocateBlock: 0x4CCu);
  v3 = &v2->CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
  if ( v2 != nullptr )
  {
    CBaseGrenade::CBaseGrenade(this: v2);
    *v3 = &CHEGrenadeProjectile::`vftable'{for `CBaseAnimating'};
    v3[291] = &CHEGrenadeProjectile::`vftable'{for `CDefaultPlayerPickupVPhysics'};
  }
  else
  {
    v3 = nullptr;
  }
  (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: pClassName);
  return (IServerNetworkable *)(v3 + 3);
}

//------------------------------------------------------------------------------
// Address: 0x102A3A90
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CInfoViewParameters>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CInfoViewParameters>::Create(
        CEntityFactory<CInfoViewParameters> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x358u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CInfoViewParameters::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x102A3B40
// Name: public: virtual unsigned int CEntityFactory<class CItemAmmo45ACP>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CItemAmmo45ACP>::GetEntitySize(CEntityFactory<CItemAmmo57MM> *this)
{
  return 1248;
}

//------------------------------------------------------------------------------
// Address: 0x102A3C70
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CItemAmmo50AE>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IServerNetworkable *__thiscall CEntityFactory<CItemAmmo50AE>::Create(
        CEntityFactory<CItemAmmo50AE> *this,
        const char *pClassName)
{
  CItem *v2; // eax
  _DWORD *v3; // esi

  v2 = (CItem *)CBaseEntity::operator new(stAllocateBlock: 0x4E0u);
  v3 = &v2->CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
  if ( v2 != nullptr )
  {
    CItem::CItem(this: v2);
    *v3 = &CItemAmmo50AE::`vftable'{for `CBaseAnimating'};
    v3[291] = &CItemAmmo50AE::`vftable'{for `CDefaultPlayerPickupVPhysics'};
  }
  else
  {
    v3 = nullptr;
  }
  (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: pClassName);
  return (IServerNetworkable *)(v3 + 3);
}

//------------------------------------------------------------------------------
// Address: 0x102A3CC0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CItemAmmo762MM>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IServerNetworkable *__thiscall CEntityFactory<CItemAmmo762MM>::Create(
        CEntityFactory<CItemAmmo762MM> *this,
        const char *pClassName)
{
  CItem *v2; // eax
  _DWORD *v3; // esi

  v2 = (CItem *)CBaseEntity::operator new(stAllocateBlock: 0x4E0u);
  v3 = &v2->CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
  if ( v2 != nullptr )
  {
    CItem::CItem(this: v2);
    *v3 = &CItemAmmo762MM::`vftable'{for `CBaseAnimating'};
    v3[291] = &CItemAmmo762MM::`vftable'{for `CDefaultPlayerPickupVPhysics'};
  }
  else
  {
    v3 = nullptr;
  }
  (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: pClassName);
  return (IServerNetworkable *)(v3 + 3);
}

//------------------------------------------------------------------------------
// Address: 0x102A3D10
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CItemAmmo556MM>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IServerNetworkable *__thiscall CEntityFactory<CItemAmmo556MM>::Create(
        CEntityFactory<CItemAmmo556MM> *this,
        const char *pClassName)
{
  CItem *v2; // eax
  _DWORD *v3; // esi

  v2 = (CItem *)CBaseEntity::operator new(stAllocateBlock: 0x4E0u);
  v3 = &v2->CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
  if ( v2 != nullptr )
  {
    CItem::CItem(this: v2);
    *v3 = &CItemAmmo556MM::`vftable'{for `CBaseAnimating'};
    v3[291] = &CItemAmmo556MM::`vftable'{for `CDefaultPlayerPickupVPhysics'};
  }
  else
  {
    v3 = nullptr;
  }
  (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: pClassName);
  return (IServerNetworkable *)(v3 + 3);
}

//------------------------------------------------------------------------------
// Address: 0x102A3D60
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CItemAmmo556MM_BOX>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IServerNetworkable *__thiscall CEntityFactory<CItemAmmo556MM_BOX>::Create(
        CEntityFactory<CItemAmmo556MM_BOX> *this,
        const char *pClassName)
{
  CItem *v2; // eax
  _DWORD *v3; // esi

  v2 = (CItem *)CBaseEntity::operator new(stAllocateBlock: 0x4E0u);
  v3 = &v2->CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
  if ( v2 != nullptr )
  {
    CItem::CItem(this: v2);
    *v3 = &CItemAmmo556MM_BOX::`vftable'{for `CBaseAnimating'};
    v3[291] = &CItemAmmo556MM_BOX::`vftable'{for `CDefaultPlayerPickupVPhysics'};
  }
  else
  {
    v3 = nullptr;
  }
  (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: pClassName);
  return (IServerNetworkable *)(v3 + 3);
}

//------------------------------------------------------------------------------
// Address: 0x102A3DB0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CItemAmmo338MAG>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IServerNetworkable *__thiscall CEntityFactory<CItemAmmo338MAG>::Create(
        CEntityFactory<CItemAmmo338MAG> *this,
        const char *pClassName)
{
  CItem *v2; // eax
  _DWORD *v3; // esi

  v2 = (CItem *)CBaseEntity::operator new(stAllocateBlock: 0x4E0u);
  v3 = &v2->CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
  if ( v2 != nullptr )
  {
    CItem::CItem(this: v2);
    *v3 = &CItemAmmo338MAG::`vftable'{for `CBaseAnimating'};
    v3[291] = &CItemAmmo338MAG::`vftable'{for `CDefaultPlayerPickupVPhysics'};
  }
  else
  {
    v3 = nullptr;
  }
  (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: pClassName);
  return (IServerNetworkable *)(v3 + 3);
}

//------------------------------------------------------------------------------
// Address: 0x102A3E00
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CItemAmmo9MM>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IServerNetworkable *__thiscall CEntityFactory<CItemAmmo9MM>::Create(
        CEntityFactory<CItemAmmo9MM> *this,
        const char *pClassName)
{
  CItem *v2; // eax
  _DWORD *v3; // esi

  v2 = (CItem *)CBaseEntity::operator new(stAllocateBlock: 0x4E0u);
  v3 = &v2->CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
  if ( v2 != nullptr )
  {
    CItem::CItem(this: v2);
    *v3 = &CItemAmmo9MM::`vftable'{for `CBaseAnimating'};
    v3[291] = &CItemAmmo9MM::`vftable'{for `CDefaultPlayerPickupVPhysics'};
  }
  else
  {
    v3 = nullptr;
  }
  (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: pClassName);
  return (IServerNetworkable *)(v3 + 3);
}

//------------------------------------------------------------------------------
// Address: 0x102A3E50
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CItemAmmoBuckshot>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IServerNetworkable *__thiscall CEntityFactory<CItemAmmoBuckshot>::Create(
        CEntityFactory<CItemAmmoBuckshot> *this,
        const char *pClassName)
{
  CItem *v2; // eax
  _DWORD *v3; // esi

  v2 = (CItem *)CBaseEntity::operator new(stAllocateBlock: 0x4E0u);
  v3 = &v2->CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
  if ( v2 != nullptr )
  {
    CItem::CItem(this: v2);
    *v3 = &CItemAmmoBuckshot::`vftable'{for `CBaseAnimating'};
    v3[291] = &CItemAmmoBuckshot::`vftable'{for `CDefaultPlayerPickupVPhysics'};
  }
  else
  {
    v3 = nullptr;
  }
  (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: pClassName);
  return (IServerNetworkable *)(v3 + 3);
}

//------------------------------------------------------------------------------
// Address: 0x102A3EA0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CItemAmmo45ACP>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IServerNetworkable *__thiscall CEntityFactory<CItemAmmo45ACP>::Create(
        CEntityFactory<CItemAmmo45ACP> *this,
        const char *pClassName)
{
  CItem *v2; // eax
  _DWORD *v3; // esi

  v2 = (CItem *)CBaseEntity::operator new(stAllocateBlock: 0x4E0u);
  v3 = &v2->CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
  if ( v2 != nullptr )
  {
    CItem::CItem(this: v2);
    *v3 = &CItemAmmo45ACP::`vftable'{for `CBaseAnimating'};
    v3[291] = &CItemAmmo45ACP::`vftable'{for `CDefaultPlayerPickupVPhysics'};
  }
  else
  {
    v3 = nullptr;
  }
  (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: pClassName);
  return (IServerNetworkable *)(v3 + 3);
}

//------------------------------------------------------------------------------
// Address: 0x102A3EF0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CItemAmmo357SIG>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IServerNetworkable *__thiscall CEntityFactory<CItemAmmo357SIG>::Create(
        CEntityFactory<CItemAmmo357SIG> *this,
        const char *pClassName)
{
  CItem *v2; // eax
  _DWORD *v3; // esi

  v2 = (CItem *)CBaseEntity::operator new(stAllocateBlock: 0x4E0u);
  v3 = &v2->CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
  if ( v2 != nullptr )
  {
    CItem::CItem(this: v2);
    *v3 = &CItemAmmo357SIG::`vftable'{for `CBaseAnimating'};
    v3[291] = &CItemAmmo357SIG::`vftable'{for `CDefaultPlayerPickupVPhysics'};
  }
  else
  {
    v3 = nullptr;
  }
  (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: pClassName);
  return (IServerNetworkable *)(v3 + 3);
}

//------------------------------------------------------------------------------
// Address: 0x102A3F40
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CItemAmmo57MM>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IServerNetworkable *__thiscall CEntityFactory<CItemAmmo57MM>::Create(
        CEntityFactory<CItemAmmo57MM> *this,
        const char *pClassName)
{
  CItem *v2; // eax
  _DWORD *v3; // esi

  v2 = (CItem *)CBaseEntity::operator new(stAllocateBlock: 0x4E0u);
  v3 = &v2->CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
  if ( v2 != nullptr )
  {
    CItem::CItem(this: v2);
    *v3 = &CItemAmmo57MM::`vftable'{for `CBaseAnimating'};
    v3[291] = &CItemAmmo57MM::`vftable'{for `CDefaultPlayerPickupVPhysics'};
  }
  else
  {
    v3 = nullptr;
  }
  (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: pClassName);
  return (IServerNetworkable *)(v3 + 3);
}

//------------------------------------------------------------------------------
// Address: 0x102A3FC0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CItemAssaultSuit>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IServerNetworkable *__thiscall CEntityFactory<CItemAssaultSuit>::Create(
        CEntityFactory<CItemAssaultSuit> *this,
        const char *pClassName)
{
  CItem *v2; // eax
  _DWORD *v3; // esi

  v2 = (CItem *)CBaseEntity::operator new(stAllocateBlock: 0x4E0u);
  v3 = &v2->CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
  if ( v2 != nullptr )
  {
    CItem::CItem(this: v2);
    *v3 = &CItemAssaultSuit::`vftable'{for `CBaseAnimating'};
    v3[291] = &CItemAssaultSuit::`vftable'{for `CDefaultPlayerPickupVPhysics'};
  }
  else
  {
    v3 = nullptr;
  }
  (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: pClassName);
  return (IServerNetworkable *)(v3 + 3);
}

//------------------------------------------------------------------------------
// Address: 0x102A42D0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CItemDefuser>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CItemDefuser>::Create(
        CEntityFactory<CItemDefuser> *this,
        const char *pClassName)
{
  CItem *v2; // eax
  CItem *v3; // esi

  v2 = (CItem *)CBaseEntity::operator new(stAllocateBlock: 0x4E0u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CItem::CItem(this: v2);
    v3->CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable = (CItem_vtbl *)&CItemDefuser::`vftable'{for `CBaseAnimating'};
    v3->CDefaultPlayerPickupVPhysics::IPlayerPickupVPhysics::__vftable = (CDefaultPlayerPickupVPhysics_vtbl *)&CItemDefuser::`vftable'{for `CDefaultPlayerPickupVPhysics'};
    g_pDefuserEntity = v3;
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x102A4650
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CItemKevlar>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IServerNetworkable *__thiscall CEntityFactory<CItemKevlar>::Create(
        CEntityFactory<CItemKevlar> *this,
        const char *pClassName)
{
  CItem *v2; // eax
  _DWORD *v3; // esi

  v2 = (CItem *)CBaseEntity::operator new(stAllocateBlock: 0x4E0u);
  v3 = &v2->CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
  if ( v2 != nullptr )
  {
    CItem::CItem(this: v2);
    *v3 = &CItemKevlar::`vftable'{for `CBaseAnimating'};
    v3[291] = &CItemKevlar::`vftable'{for `CDefaultPlayerPickupVPhysics'};
  }
  else
  {
    v3 = nullptr;
  }
  (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: pClassName);
  return (IServerNetworkable *)(v3 + 3);
}

//------------------------------------------------------------------------------
// Address: 0x102A46C0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CItemNvgs>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IServerNetworkable *__thiscall CEntityFactory<CItemNvgs>::Create(
        CEntityFactory<CItemNvgs> *this,
        const char *pClassName)
{
  CItem *v2; // eax
  _DWORD *v3; // esi

  v2 = (CItem *)CBaseEntity::operator new(stAllocateBlock: 0x4E0u);
  v3 = &v2->CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
  if ( v2 != nullptr )
  {
    CItem::CItem(this: v2);
    *v3 = &CItemNvgs::`vftable'{for `CBaseAnimating'};
    v3[291] = &CItemNvgs::`vftable'{for `CDefaultPlayerPickupVPhysics'};
  }
  else
  {
    v3 = nullptr;
  }
  (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: pClassName);
  return (IServerNetworkable *)(v3 + 3);
}

//------------------------------------------------------------------------------
// Address: 0x102A49F0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CMapInfo>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CMapInfo>::Create(
        CEntityFactory<CMapInfo> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CMapInfo>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x102A5590
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CMolotovProjectile>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CMolotovProjectile>::Create(
        CEntityFactory<CMolotovProjectile> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CMolotovProjectile>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x102A5690
// Name: public: virtual unsigned int CEntityFactory<class CFilterEnemy>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CFilterEnemy>::GetEntitySize(CEntityFactory<CCommentaryAuto> *this)
{
  return 924;
}

//------------------------------------------------------------------------------
// Address: 0x102A5730
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CSurroundTest>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CSurroundTest>::Create(
        CEntityFactory<CSurroundTest> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CSurroundTest>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x102A59E0
// Name: public: virtual unsigned int CEntityFactory<class CSmokeGrenadeProjectile>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CSmokeGrenadeProjectile>::GetEntitySize(
        CEntityFactory<CSmokeGrenadeProjectile> *this)
{
  return 1240;
}

//------------------------------------------------------------------------------
// Address: 0x102A5EE0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CSmokeGrenadeProjectile>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IServerNetworkable *__thiscall CEntityFactory<CSmokeGrenadeProjectile>::Create(
        CEntityFactory<CSmokeGrenadeProjectile> *this,
        const char *pClassName)
{
  CBaseGrenade *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseGrenade *)CBaseEntity::operator new(stAllocateBlock: 0x4D8u);
  v3 = &v2->CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
  if ( v2 != nullptr )
  {
    CBaseGrenade::CBaseGrenade(this: v2);
    *v3 = &CSmokeGrenadeProjectile::`vftable'{for `CBaseAnimating'};
    v3[291] = &CSmokeGrenadeProjectile::`vftable'{for `CDefaultPlayerPickupVPhysics'};
  }
  else
  {
    v3 = nullptr;
  }
  (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: pClassName);
  return (IServerNetworkable *)(v3 + 3);
}

//------------------------------------------------------------------------------
// Address: 0x102A7650
// Name: public: virtual unsigned int CEntityFactory<class CCSBot>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CCSBot>::GetEntitySize(CEntityFactory<CCSBot> *this)
{
  return 16904;
}

//------------------------------------------------------------------------------
// Address: 0x102A7660
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CCSBot>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CCSBot>::Create(CEntityFactory<CCSBot> *this, const char *pClassName)
{
  CCSBot *v2; // eax
  CCSBot *v3; // esi

  v2 = (CCSBot *)CBaseEntity::operator new(stAllocateBlock: 0x4208u);
  if ( v2 != nullptr )
    v3 = CCSBot::CCSBot(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x102D8EE0
// Name: public: virtual unsigned int CEntityFactory<class CInferno>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CInferno>::GetEntitySize(CEntityFactory<CFireCrackerBlast> *this)
{
  return 2760;
}

//------------------------------------------------------------------------------
// Address: 0x102D95E0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CInferno>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CInferno>::Create(
        CEntityFactory<CInferno> *this,
        const char *pClassName)
{
  CInferno *v2; // eax
  CInferno *v3; // esi

  v2 = (CInferno *)CBaseEntity::operator new(stAllocateBlock: 0xAC8u);
  if ( v2 != nullptr )
    v3 = CInferno::CInferno(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x102D9620
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CFireCrackerBlast>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CFireCrackerBlast>::Create(
        CEntityFactory<CFireCrackerBlast> *this,
        const char *pClassName)
{
  CInferno *v2; // eax
  CInferno *v3; // esi

  v2 = (CInferno *)CBaseEntity::operator new(stAllocateBlock: 0xAC8u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CInferno::CInferno(this: v2);
    v3->__vftable = (CInferno_vtbl *)&CFireCrackerBlast::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x102DBC60
// Name: public: virtual unsigned int CEntityFactory<class CHostage>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CHostage>::GetEntitySize(CEntityFactory<CHostage> *this)
{
  return 8680;
}

//------------------------------------------------------------------------------
// Address: 0x102DE950
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CHostage>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CHostage>::Create(
        CEntityFactory<CHostage> *this,
        const char *pClassName)
{
  CHostage *v2; // eax
  CHostage *v3; // esi

  v2 = (CHostage *)CBaseEntity::operator new(stAllocateBlock: 0x21E8u);
  if ( v2 != nullptr )
    v3 = CHostage::CHostage(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x102E2DF0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CAK47>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CAK47>::Create(CEntityFactory<CAK47> *this, const char *pClassName)
{
  CWeaponCSBaseGun *v2; // eax
  CWeaponCSBaseGun *v3; // esi

  v2 = (CWeaponCSBaseGun *)CBaseEntity::operator new(stAllocateBlock: 0x5C0u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CWeaponCSBaseGun::CWeaponCSBaseGun(this: v2);
    v3->__vftable = (CWeaponCSBaseGun_vtbl *)&CAK47::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x102E32D0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CWeaponAug>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CWeaponAug>::Create(
        CEntityFactory<CWeaponAug> *this,
        const char *pClassName)
{
  CWeaponCSBaseGun *v2; // eax
  CWeaponCSBaseGun *v3; // esi

  v2 = (CWeaponCSBaseGun *)CBaseEntity::operator new(stAllocateBlock: 0x5C0u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CWeaponCSBaseGun::CWeaponCSBaseGun(this: v2);
    v3->__vftable = (CWeaponCSBaseGun_vtbl *)&CWeaponAug::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x102E3930
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CWeaponAWP>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CWeaponAWP>::Create(
        CEntityFactory<CWeaponAWP> *this,
        const char *pClassName)
{
  CWeaponCSBaseGun *v2; // eax
  CWeaponCSBaseGun *v3; // esi

  v2 = (CWeaponCSBaseGun *)CBaseEntity::operator new(stAllocateBlock: 0x5C0u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CWeaponCSBaseGun::CWeaponCSBaseGun(this: v2);
    v3->__vftable = (CWeaponCSBaseGun_vtbl *)&CWeaponAWP::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x102E39F0
// Name: public: virtual unsigned int CEntityFactory<class CDecoyGrenade>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CDecoyGrenade>::GetEntitySize(CEntityFactory<CBaseCSGrenade> *this)
{
  return 1484;
}

//------------------------------------------------------------------------------
// Address: 0x102E4B50
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CBaseCSGrenade>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CBaseCSGrenade>::Create(
        CEntityFactory<CBaseCSGrenade> *this,
        const char *pClassName)
{
  CBaseCSGrenade *v2; // eax
  CBaseCSGrenade *v3; // esi

  v2 = (CBaseCSGrenade *)CBaseEntity::operator new(stAllocateBlock: 0x5CCu);
  if ( v2 != nullptr )
    v3 = CBaseCSGrenade::CBaseCSGrenade(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x102E4C90
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CWeaponBizon>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CWeaponBizon>::Create(
        CEntityFactory<CWeaponBizon> *this,
        const char *pClassName)
{
  CWeaponCSBaseGun *v2; // eax
  CWeaponCSBaseGun *v3; // esi

  v2 = (CWeaponCSBaseGun *)CBaseEntity::operator new(stAllocateBlock: 0x5C0u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CWeaponCSBaseGun::CWeaponCSBaseGun(this: v2);
    v3->__vftable = (CWeaponCSBaseGun_vtbl *)&CWeaponBizon::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x102E5330
// Name: public: virtual unsigned int CEntityFactory<class CC4>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CC4>::GetEntitySize(CEntityFactory<CC4> *this)
{
  return 1492;
}

//------------------------------------------------------------------------------
// Address: 0x102E7FD0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CPlantedC4>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CPlantedC4>::Create(
        CEntityFactory<CPlantedC4> *this,
        const char *pClassName)
{
  CPlantedC4 *v2; // eax
  CPlantedC4 *v3; // esi

  v2 = (CPlantedC4 *)CBaseEntity::operator new(stAllocateBlock: 0x4D4u);
  if ( v2 != nullptr )
    v3 = CPlantedC4::CPlantedC4(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x102E8010
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CPlantedC4Training>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CPlantedC4Training>::Create(
        CEntityFactory<CPlantedC4Training> *this,
        const char *pClassName)
{
  CPlantedC4 *v2; // eax
  CPlantedC4 *v3; // esi

  v2 = (CPlantedC4 *)CBaseEntity::operator new(stAllocateBlock: 0x4D4u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CPlantedC4::CPlantedC4(this: v2);
    v3->__vftable = (CPlantedC4_vtbl *)&CPlantedC4Training::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x102E8050
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CC4>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CC4>::Create(CEntityFactory<CC4> *this, const char *pClassName)
{
  CC4 *v2; // eax
  CC4 *v3; // esi

  v2 = (CC4 *)CBaseEntity::operator new(stAllocateBlock: 0x5D4u);
  if ( v2 != nullptr )
    v3 = CC4::CC4(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x102EA5F0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CWeaponCSBase>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CWeaponCSBase>::Create(
        CEntityFactory<CWeaponCSBase> *this,
        const char *pClassName)
{
  CWeaponCSBase *v2; // eax
  CWeaponCSBase *v3; // esi

  v2 = (CWeaponCSBase *)CBaseEntity::operator new(stAllocateBlock: 0x5C0u);
  if ( v2 != nullptr )
    v3 = CWeaponCSBase::CWeaponCSBase(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x102EADF0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CWeaponCSBaseGun>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CWeaponCSBaseGun>::Create(
        CEntityFactory<CWeaponCSBaseGun> *this,
        const char *pClassName)
{
  CWeaponCSBase *v2; // eax
  CWeaponCSBase *v3; // esi

  v2 = (CWeaponCSBase *)CBaseEntity::operator new(stAllocateBlock: 0x5C0u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CWeaponCSBase::CWeaponCSBase(this: v2);
    v3->__vftable = (CWeaponCSBase_vtbl *)&CWeaponCSBaseGun::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x102EAF20
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CDEagle>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CDEagle>::Create(
        CEntityFactory<CDEagle> *this,
        const char *pClassName)
{
  CWeaponCSBaseGun *v2; // eax
  CWeaponCSBaseGun *v3; // esi

  v2 = (CWeaponCSBaseGun *)CBaseEntity::operator new(stAllocateBlock: 0x5C0u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CWeaponCSBaseGun::CWeaponCSBaseGun(this: v2);
    v3->__vftable = (CWeaponCSBaseGun_vtbl *)&CDEagle::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x102EB110
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CDecoyGrenade>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CDecoyGrenade>::Create(
        CEntityFactory<CDecoyGrenade> *this,
        const char *pClassName)
{
  CBaseCSGrenade *v2; // eax
  CBaseCSGrenade *v3; // esi

  v2 = (CBaseCSGrenade *)CBaseEntity::operator new(stAllocateBlock: 0x5CCu);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseCSGrenade::CBaseCSGrenade(this: v2);
    v3->__vftable = (CBaseCSGrenade_vtbl *)&CDecoyGrenade::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x102EB330
// Name: public: virtual unsigned int CEntityFactory<class CWeaponNOVA>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CWeaponNOVA>::GetEntitySize(CEntityFactory<CWeaponElite> *this)
{
  return 1480;
}

//------------------------------------------------------------------------------
// Address: 0x102EB460
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CWeaponElite>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CWeaponElite>::Create(
        CEntityFactory<CWeaponElite> *this,
        const char *pClassName)
{
  CWeaponCSBaseGun *v2; // eax
  CWeaponCSBaseGun *v3; // esi

  v2 = (CWeaponCSBaseGun *)CBaseEntity::operator new(stAllocateBlock: 0x5C8u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CWeaponCSBaseGun::CWeaponCSBaseGun(this: v2);
    v3->__vftable = (CWeaponCSBaseGun_vtbl *)&CWeaponElite::`vftable';
    LOBYTE(v3[1].m_pfnMoveDone) = 0;
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x102EBE10
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CWeaponFamas>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CWeaponFamas>::Create(
        CEntityFactory<CWeaponFamas> *this,
        const char *pClassName)
{
  CWeaponFamas *v2; // eax
  CWeaponFamas *v3; // esi

  v2 = (CWeaponFamas *)CBaseEntity::operator new(stAllocateBlock: 0x5CCu);
  if ( v2 != nullptr )
    v3 = CWeaponFamas::CWeaponFamas(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x102EBFB0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CWeaponFiveSeven>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CWeaponFiveSeven>::Create(
        CEntityFactory<CWeaponFiveSeven> *this,
        const char *pClassName)
{
  CWeaponCSBaseGun *v2; // eax
  CWeaponCSBaseGun *v3; // esi

  v2 = (CWeaponCSBaseGun *)CBaseEntity::operator new(stAllocateBlock: 0x5C0u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CWeaponCSBaseGun::CWeaponCSBaseGun(this: v2);
    v3->__vftable = (CWeaponCSBaseGun_vtbl *)&CWeaponFiveSeven::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x102EC170
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CFlashbang>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CFlashbang>::Create(
        CEntityFactory<CFlashbang> *this,
        const char *pClassName)
{
  CBaseCSGrenade *v2; // eax
  CBaseCSGrenade *v3; // esi

  v2 = (CBaseCSGrenade *)CBaseEntity::operator new(stAllocateBlock: 0x5CCu);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseCSGrenade::CBaseCSGrenade(this: v2);
    v3->__vftable = (CBaseCSGrenade_vtbl *)&CFlashbang::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x102EC620
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CWeaponG3SG1>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CWeaponG3SG1>::Create(
        CEntityFactory<CWeaponG3SG1> *this,
        const char *pClassName)
{
  CWeaponCSBaseGun *v2; // eax
  CWeaponCSBaseGun *v3; // esi

  v2 = (CWeaponCSBaseGun *)CBaseEntity::operator new(stAllocateBlock: 0x5C0u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CWeaponCSBaseGun::CWeaponCSBaseGun(this: v2);
    v3->__vftable = (CWeaponCSBaseGun_vtbl *)&CWeaponG3SG1::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x102ECA10
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CWeaponGalil>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CWeaponGalil>::Create(
        CEntityFactory<CWeaponGalil> *this,
        const char *pClassName)
{
  CWeaponCSBaseGun *v2; // eax
  CWeaponCSBaseGun *v3; // esi

  v2 = (CWeaponCSBaseGun *)CBaseEntity::operator new(stAllocateBlock: 0x5C0u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CWeaponCSBaseGun::CWeaponCSBaseGun(this: v2);
    v3->__vftable = (CWeaponCSBaseGun_vtbl *)&CWeaponGalil::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x102ED300
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CWeaponGlock>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CWeaponGlock>::Create(
        CEntityFactory<CWeaponGlock> *this,
        const char *pClassName)
{
  CWeaponGlock *v2; // eax
  CWeaponGlock *v3; // esi

  v2 = (CWeaponGlock *)CBaseEntity::operator new(stAllocateBlock: 0x5CCu);
  if ( v2 != nullptr )
    v3 = CWeaponGlock::CWeaponGlock(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x102ED500
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CHEGrenade>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CHEGrenade>::Create(
        CEntityFactory<CHEGrenade> *this,
        const char *pClassName)
{
  CBaseCSGrenade *v2; // eax
  CBaseCSGrenade *v3; // esi

  v2 = (CBaseCSGrenade *)CBaseEntity::operator new(stAllocateBlock: 0x5CCu);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseCSGrenade::CBaseCSGrenade(this: v2);
    v3->__vftable = (CBaseCSGrenade_vtbl *)&CHEGrenade::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x102ED6A0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CWeaponHKP2000>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CWeaponHKP2000>::Create(
        CEntityFactory<CWeaponHKP2000> *this,
        const char *pClassName)
{
  CWeaponCSBaseGun *v2; // eax
  CWeaponCSBaseGun *v3; // esi

  v2 = (CWeaponCSBaseGun *)CBaseEntity::operator new(stAllocateBlock: 0x5C0u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CWeaponCSBaseGun::CWeaponCSBaseGun(this: v2);
    v3->__vftable = (CWeaponCSBaseGun_vtbl *)&CWeaponHKP2000::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x102EDB40
// Name: public: virtual unsigned int CEntityFactory<class CKnife>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CKnife>::GetEntitySize(CEntityFactory<CKnife> *this)
{
  return 1568;
}

//------------------------------------------------------------------------------
// Address: 0x102EEA90
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CKnife>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IServerNetworkable *__thiscall CEntityFactory<CKnife>::Create(CEntityFactory<CKnife> *this, const char *pClassName)
{
  CWeaponCSBase *v2; // eax
  _DWORD *v3; // esi

  v2 = (CWeaponCSBase *)CBaseEntity::operator new(stAllocateBlock: 0x620u);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CWeaponCSBase::CWeaponCSBase(this: v2);
    *v3 = &CKnife::`vftable';
    v3[389] = -1;
  }
  else
  {
    v3 = nullptr;
  }
  (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: pClassName);
  return (IServerNetworkable *)(v3 + 3);
}

//------------------------------------------------------------------------------
// Address: 0x102EEE10
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CWeaponM249>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CWeaponM249>::Create(
        CEntityFactory<CWeaponM249> *this,
        const char *pClassName)
{
  CWeaponCSBaseGun *v2; // eax
  CWeaponCSBaseGun *v3; // esi

  v2 = (CWeaponCSBaseGun *)CBaseEntity::operator new(stAllocateBlock: 0x5C0u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CWeaponCSBaseGun::CWeaponCSBaseGun(this: v2);
    v3->__vftable = (CWeaponCSBaseGun_vtbl *)&CWeaponM249::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x102EEFB0
// Name: public: virtual unsigned int CEntityFactory<class CWeaponM4A1>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CWeaponM4A1>::GetEntitySize(CEntityFactory<CWeaponM4A1> *this)
{
  return 1488;
}

//------------------------------------------------------------------------------
// Address: 0x102EF9D0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CWeaponM4A1>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CWeaponM4A1>::Create(
        CEntityFactory<CWeaponM4A1> *this,
        const char *pClassName)
{
  CWeaponM4A1 *v2; // eax
  CWeaponM4A1 *v3; // esi

  v2 = (CWeaponM4A1 *)CBaseEntity::operator new(stAllocateBlock: 0x5D0u);
  if ( v2 != nullptr )
    v3 = CWeaponM4A1::CWeaponM4A1(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x102EFD40
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CWeaponMAC10>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CWeaponMAC10>::Create(
        CEntityFactory<CWeaponMAC10> *this,
        const char *pClassName)
{
  CWeaponCSBaseGun *v2; // eax
  CWeaponCSBaseGun *v3; // esi

  v2 = (CWeaponCSBaseGun *)CBaseEntity::operator new(stAllocateBlock: 0x5C0u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CWeaponCSBaseGun::CWeaponCSBaseGun(this: v2);
    v3->__vftable = (CWeaponCSBaseGun_vtbl *)&CWeaponMAC10::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x102EFE50
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CWeaponMag7>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CWeaponMag7>::Create(
        CEntityFactory<CWeaponMag7> *this,
        const char *pClassName)
{
  CWeaponCSBaseGun *v2; // eax
  CWeaponCSBaseGun *v3; // esi

  v2 = (CWeaponCSBaseGun *)CBaseEntity::operator new(stAllocateBlock: 0x5C0u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CWeaponCSBaseGun::CWeaponCSBaseGun(this: v2);
    v3->__vftable = (CWeaponCSBaseGun_vtbl *)&CWeaponMag7::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x102F00A0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CMolotovGrenade>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CMolotovGrenade>::Create(
        CEntityFactory<CMolotovGrenade> *this,
        const char *pClassName)
{
  CBaseCSGrenade *v2; // eax
  CBaseCSGrenade *v3; // esi

  v2 = (CBaseCSGrenade *)CBaseEntity::operator new(stAllocateBlock: 0x5CCu);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseCSGrenade::CBaseCSGrenade(this: v2);
    v3->__vftable = (CBaseCSGrenade_vtbl *)&CMolotovGrenade::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x102F0410
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CWeaponMP7>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CWeaponMP7>::Create(
        CEntityFactory<CWeaponMP7> *this,
        const char *pClassName)
{
  CWeaponCSBaseGun *v2; // eax
  CWeaponCSBaseGun *v3; // esi

  v2 = (CWeaponCSBaseGun *)CBaseEntity::operator new(stAllocateBlock: 0x5C0u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CWeaponCSBaseGun::CWeaponCSBaseGun(this: v2);
    v3->__vftable = (CWeaponCSBaseGun_vtbl *)&CWeaponMP7::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x102F0780
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CWeaponMP9>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CWeaponMP9>::Create(
        CEntityFactory<CWeaponMP9> *this,
        const char *pClassName)
{
  CWeaponCSBaseGun *v2; // eax
  CWeaponCSBaseGun *v3; // esi

  v2 = (CWeaponCSBaseGun *)CBaseEntity::operator new(stAllocateBlock: 0x5C0u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CWeaponCSBaseGun::CWeaponCSBaseGun(this: v2);
    v3->__vftable = (CWeaponCSBaseGun_vtbl *)&CWeaponMP9::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x102F0890
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CWeaponNegev>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CWeaponNegev>::Create(
        CEntityFactory<CWeaponNegev> *this,
        const char *pClassName)
{
  CWeaponCSBaseGun *v2; // eax
  CWeaponCSBaseGun *v3; // esi

  v2 = (CWeaponCSBaseGun *)CBaseEntity::operator new(stAllocateBlock: 0x5C0u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CWeaponCSBaseGun::CWeaponCSBaseGun(this: v2);
    v3->__vftable = (CWeaponCSBaseGun_vtbl *)&CWeaponNegev::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x102F1000
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CWeaponNOVA>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CWeaponNOVA>::Create(
        CEntityFactory<CWeaponNOVA> *this,
        const char *pClassName)
{
  CWeaponNOVA *v2; // eax
  CWeaponNOVA *v3; // esi

  v2 = (CWeaponNOVA *)CBaseEntity::operator new(stAllocateBlock: 0x5C8u);
  if ( v2 != nullptr )
    v3 = CWeaponNOVA::CWeaponNOVA(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x102F1100
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CWeaponP250>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CWeaponP250>::Create(
        CEntityFactory<CWeaponP250> *this,
        const char *pClassName)
{
  CWeaponCSBaseGun *v2; // eax
  CWeaponCSBaseGun *v3; // esi

  v2 = (CWeaponCSBaseGun *)CBaseEntity::operator new(stAllocateBlock: 0x5C0u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CWeaponCSBaseGun::CWeaponCSBaseGun(this: v2);
    v3->__vftable = (CWeaponCSBaseGun_vtbl *)&CWeaponP250::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x102F1450
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CWeaponP90>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CWeaponP90>::Create(
        CEntityFactory<CWeaponP90> *this,
        const char *pClassName)
{
  CWeaponCSBaseGun *v2; // eax
  CWeaponCSBaseGun *v3; // esi

  v2 = (CWeaponCSBaseGun *)CBaseEntity::operator new(stAllocateBlock: 0x5C0u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CWeaponCSBaseGun::CWeaponCSBaseGun(this: v2);
    v3->__vftable = (CWeaponCSBaseGun_vtbl *)&CWeaponP90::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x102F1DB0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CWeaponSawedoff>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CWeaponSawedoff>::Create(
        CEntityFactory<CWeaponSawedoff> *this,
        const char *pClassName)
{
  CWeaponSawedoff *v2; // eax
  CWeaponSawedoff *v3; // esi

  v2 = (CWeaponSawedoff *)CBaseEntity::operator new(stAllocateBlock: 0x5C8u);
  if ( v2 != nullptr )
    v3 = CWeaponSawedoff::CWeaponSawedoff(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x102F2300
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CWeaponSCAR20>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CWeaponSCAR20>::Create(
        CEntityFactory<CWeaponSCAR20> *this,
        const char *pClassName)
{
  CWeaponCSBaseGun *v2; // eax
  CWeaponCSBaseGun *v3; // esi

  v2 = (CWeaponCSBaseGun *)CBaseEntity::operator new(stAllocateBlock: 0x5C0u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CWeaponCSBaseGun::CWeaponCSBaseGun(this: v2);
    v3->__vftable = (CWeaponCSBaseGun_vtbl *)&CWeaponSCAR20::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x102F2880
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CWeaponSG556>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CWeaponSG556>::Create(
        CEntityFactory<CWeaponSG556> *this,
        const char *pClassName)
{
  CWeaponCSBaseGun *v2; // eax
  CWeaponCSBaseGun *v3; // esi

  v2 = (CWeaponCSBaseGun *)CBaseEntity::operator new(stAllocateBlock: 0x5C0u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CWeaponCSBaseGun::CWeaponCSBaseGun(this: v2);
    v3->__vftable = (CWeaponCSBaseGun_vtbl *)&CWeaponSG556::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x102F2A40
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CSmokeGrenade>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CSmokeGrenade>::Create(
        CEntityFactory<CSmokeGrenade> *this,
        const char *pClassName)
{
  CBaseCSGrenade *v2; // eax
  CBaseCSGrenade *v3; // esi

  v2 = (CBaseCSGrenade *)CBaseEntity::operator new(stAllocateBlock: 0x5CCu);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseCSGrenade::CBaseCSGrenade(this: v2);
    v3->__vftable = (CBaseCSGrenade_vtbl *)&CSmokeGrenade::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x102F3000
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CWeaponSSG08>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CWeaponSSG08>::Create(
        CEntityFactory<CWeaponSSG08> *this,
        const char *pClassName)
{
  CWeaponCSBaseGun *v2; // eax
  CWeaponCSBaseGun *v3; // esi

  v2 = (CWeaponCSBaseGun *)CBaseEntity::operator new(stAllocateBlock: 0x5C0u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CWeaponCSBaseGun::CWeaponCSBaseGun(this: v2);
    v3->__vftable = (CWeaponCSBaseGun_vtbl *)&CWeaponSSG08::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x102F3150
// Name: public: virtual unsigned int CEntityFactory<class CWeaponTaser>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CWeaponTaser>::GetEntitySize(CEntityFactory<CWeaponTaser> *this)
{
  return 1476;
}

//------------------------------------------------------------------------------
// Address: 0x102F31F0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CWeaponTaser>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IServerNetworkable *__thiscall CEntityFactory<CWeaponTaser>::Create(
        CEntityFactory<CWeaponTaser> *this,
        const char *pClassName)
{
  CWeaponCSBaseGun *v2; // eax
  _DWORD *v3; // esi

  v2 = (CWeaponCSBaseGun *)CBaseEntity::operator new(stAllocateBlock: 0x5C4u);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CWeaponCSBaseGun::CWeaponCSBaseGun(this: v2);
    *v3 = &CWeaponTaser::`vftable';
    v3[368] = 0;
  }
  else
  {
    v3 = nullptr;
  }
  (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: pClassName);
  return (IServerNetworkable *)(v3 + 3);
}

//------------------------------------------------------------------------------
// Address: 0x102F3280
// Name: public: virtual unsigned int CEntityFactory<class CWeaponBizon>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CWeaponBizon>::GetEntitySize(CEntityFactory<CAK47> *this)
{
  return 1472;
}

//------------------------------------------------------------------------------
// Address: 0x102F3320
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CWeaponTec9>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CWeaponTec9>::Create(
        CEntityFactory<CWeaponTec9> *this,
        const char *pClassName)
{
  CWeaponCSBaseGun *v2; // eax
  CWeaponCSBaseGun *v3; // esi

  v2 = (CWeaponCSBaseGun *)CBaseEntity::operator new(stAllocateBlock: 0x5C0u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CWeaponCSBaseGun::CWeaponCSBaseGun(this: v2);
    v3->__vftable = (CWeaponCSBaseGun_vtbl *)&CWeaponTec9::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x102F36C0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CWeaponUMP45>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CWeaponUMP45>::Create(
        CEntityFactory<CWeaponUMP45> *this,
        const char *pClassName)
{
  CWeaponCSBaseGun *v2; // eax
  CWeaponCSBaseGun *v3; // esi

  v2 = (CWeaponCSBaseGun *)CBaseEntity::operator new(stAllocateBlock: 0x5C0u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CWeaponCSBaseGun::CWeaponCSBaseGun(this: v2);
    v3->__vftable = (CWeaponCSBaseGun_vtbl *)&CWeaponUMP45::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x102F4010
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CWeaponXM1014>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CWeaponXM1014>::Create(
        CEntityFactory<CWeaponXM1014> *this,
        const char *pClassName)
{
  CWeaponXM1014 *v2; // eax
  CWeaponXM1014 *v3; // esi

  v2 = (CWeaponXM1014 *)CBaseEntity::operator new(stAllocateBlock: 0x5C8u);
  if ( v2 != nullptr )
    v3 = CWeaponXM1014::CWeaponXM1014(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10309800
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CFuncNavBlocker>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CFuncNavBlocker>::Create(
        CEntityFactory<CFuncNavBlocker> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x378u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CFuncNavBlocker::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1030A020
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CFuncNavObstruction>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CFuncNavObstruction>::Create(
        CEntityFactory<CFuncNavObstruction> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CFuncNavObstruction>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10325590
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CTempEntTester>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CTempEntTester>::Create(
        CEntityFactory<CTempEntTester> *this,
        const char *pClassName)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x39Cu);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CTempEntTester::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10325660
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class MovieExplosion>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<MovieExplosion>::Create(
        CEntityFactory<MovieExplosion> *this,
        const char *pClassName)
{
  CBaseParticleEntity *v2; // eax
  CBaseParticleEntity *v3; // esi

  v2 = (CBaseParticleEntity *)CBaseEntity::operator new(stAllocateBlock: 0x354u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseParticleEntity::CBaseParticleEntity(this: v2);
    v3->__vftable = (CBaseParticleEntity_vtbl *)&MovieExplosion::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x103257A0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CParticleFire>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CParticleFire>::Create(
        CEntityFactory<CParticleFire> *this,
        const char *pClassName)
{
  CBaseParticleEntity *v2; // eax
  CBaseParticleEntity *v3; // esi

  v2 = (CBaseParticleEntity *)CBaseEntity::operator new(stAllocateBlock: 0x36Cu);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseParticleEntity::CBaseParticleEntity(this: v2);
    v3->__vftable = (CBaseParticleEntity_vtbl *)&CParticleFire::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10325D20
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class ParticleSmokeGrenade>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<ParticleSmokeGrenade>::Create(
        CEntityFactory<ParticleSmokeGrenade> *this,
        const char *pClassName)
{
  ParticleSmokeGrenade *v2; // eax
  ParticleSmokeGrenade *v3; // esi

  v2 = (ParticleSmokeGrenade *)CBaseEntity::operator new(stAllocateBlock: 0x380u);
  if ( v2 != nullptr )
    v3 = ParticleSmokeGrenade::ParticleSmokeGrenade(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x103261E0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CPlasma>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CPlasma>::Create(
        CEntityFactory<CPlasma> *this,
        const char *pClassName)
{
  CPlasma *v2; // eax
  CPlasma *v3; // esi

  v2 = (CPlasma *)CBaseEntity::operator new(stAllocateBlock: 0x370u);
  if ( v2 != nullptr )
    v3 = CPlasma::CPlasma(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10327030
// Name: public: virtual unsigned int CEntityFactory<class CEnvShooter>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CEnvShooter>::GetEntitySize(CEntityFactory<CEnvShooter> *this)
{
  return 928;
}

//------------------------------------------------------------------------------
// Address: 0x10327440
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CFireTrail>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CFireTrail>::Create(
        CEntityFactory<CFireTrail> *this,
        const char *pClassName)
{
  CBaseParticleEntity *v2; // eax
  CBaseParticleEntity *v3; // esi

  v2 = (CBaseParticleEntity *)CBaseEntity::operator new(stAllocateBlock: 0x35Cu);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseParticleEntity::CBaseParticleEntity(this: v2);
    v3->__vftable = (CBaseParticleEntity_vtbl *)&CFireTrail::`vftable';
  }
  else
  {
    v3 = nullptr;
  }
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x103284C0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class SmokeTrail>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<SmokeTrail>::Create(
        CEntityFactory<SmokeTrail> *this,
        const char *pClassName)
{
  SmokeTrail *v2; // eax
  SmokeTrail *v3; // esi

  v2 = (SmokeTrail *)CBaseEntity::operator new(stAllocateBlock: 0x3A0u);
  if ( v2 != nullptr )
    v3 = SmokeTrail::SmokeTrail(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10328500
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class RocketTrail>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<RocketTrail>::Create(
        CEntityFactory<RocketTrail> *this,
        const char *pClassName)
{
  RocketTrail *v2; // eax
  RocketTrail *v3; // esi

  v2 = (RocketTrail *)CBaseEntity::operator new(stAllocateBlock: 0x3A0u);
  if ( v2 != nullptr )
    v3 = RocketTrail::RocketTrail(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10328540
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class DustTrail>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<DustTrail>::Create(
        CEntityFactory<DustTrail> *this,
        const char *pClassName)
{
  DustTrail *v2; // eax
  DustTrail *v3; // esi

  v2 = (DustTrail *)CBaseEntity::operator new(stAllocateBlock: 0x394u);
  if ( v2 != nullptr )
    v3 = DustTrail::DustTrail(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10328CA0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class SporeTrail>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<SporeTrail>::Create(
        CEntityFactory<SporeTrail> *this,
        const char *pClassName)
{
  SporeTrail *v2; // eax
  SporeTrail *v3; // esi

  v2 = (SporeTrail *)CBaseEntity::operator new(stAllocateBlock: 0x378u);
  if ( v2 != nullptr )
    v3 = SporeTrail::SporeTrail(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10328CE0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class SporeExplosion>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<SporeExplosion>::Create(
        CEntityFactory<SporeExplosion> *this,
        const char *pClassName)
{
  SporeExplosion *v2; // eax
  SporeExplosion *v3; // esi

  v2 = (SporeExplosion *)CBaseEntity::operator new(stAllocateBlock: 0x370u);
  if ( v2 != nullptr )
    v3 = SporeExplosion::SporeExplosion(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x10328D70
// Name: public: virtual unsigned int CEntityFactory<class CFilterMultiple>::GetEntitySize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CEntityFactory<CFilterMultiple>::GetEntitySize(CEntityFactory<CFilterMultiple> *this)
{
  return 988;
}

//------------------------------------------------------------------------------
// Address: 0x10329D90
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CSmokeStack>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CSmokeStack>::Create(
        CEntityFactory<CSmokeStack> *this,
        const char *pClassName)
{
  CSmokeStack *v2; // eax
  CSmokeStack *v3; // esi

  v2 = (CSmokeStack *)CBaseEntity::operator new(stAllocateBlock: 0x3DCu);
  if ( v2 != nullptr )
    v3 = CSmokeStack::CSmokeStack(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1032A4C0
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CSpriteTrail>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CSpriteTrail>::Create(
        CEntityFactory<CSpriteTrail> *this,
        const char *pClassName)
{
  CSpriteTrail *v2; // eax
  CSpriteTrail *v3; // esi

  v2 = (CSpriteTrail *)CBaseEntity::operator new(stAllocateBlock: 0x3D4u);
  if ( v2 != nullptr )
    v3 = CSpriteTrail::CSpriteTrail(this: v2);
  else
    v3 = nullptr;
  v3->PostConstructor(this: v3, a2: pClassName);
  return &v3->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x1032A580
// Name: public: virtual class ServerClass __near * CSteamJet::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CSteamJet::GetServerClass(CSteamJet *this)
{
  return &g_CSteamJet_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x1032A590
// Name: public: virtual struct datamap_t __near * CSteamJet::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CSteamJet::GetDataDescMap(CSteamJet *this)
{
  return &CSteamJet::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1032A5A0
// Name: public: virtual void CSteamJet::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamJet::Precache(CSteamJet *this)
{
  PrecacheMaterial(pMaterialName: "particle/particle_smokegrenade");
  PrecacheMaterial(pMaterialName: "sprites/heatwave");
}

//------------------------------------------------------------------------------
// Address: 0x1032A890
// Name: public: virtual void CSteamJet::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamJet::Spawn(CSteamJet *this)
{
  edict_t *m_pPev; // ecx
  edict_t *v3; // ecx

  this->Precache(this);
  if ( (this->m_iClassname.pszValue == "env_steamjet"
     || CBaseEntity::ClassMatchesComplex(this, pszClassOrWildcard: "env_steamjet") != 0)
    && !this->m_bFaceLeft.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x370u);
    }
    this->m_bFaceLeft.m_Value = true;
  }
  if ( this->m_InitialState && this->m_bEmit.m_Value != 1 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_bEmit.m_Value = 1;
    }
    else
    {
      v3 = this->m_Network.m_pPev;
      if ( v3 != nullptr )
        CBaseEdict::StateChanged(this: &v3->CBaseEdict, offset: 0x36Cu);
      this->m_bEmit.m_Value = 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1032A940
// Name: public: virtual void CSteamJet::Use(class CBaseEntity __near *,class CBaseEntity __near *,enum USE_TYPE,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamJet::Use(
        CSteamJet *this,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller,
        USE_TYPE useType,
        float value)
{
  edict_t *m_pPev; // ecx
  edict_t *v7; // ecx

  if ( !pActivator->IsPlayer(this: pActivator) )
  {
    if ( useType == USE_ON )
    {
      if ( this->m_bEmit.m_Value != 1 )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
          this->m_bEmit.m_Value = 1;
        }
        else
        {
          m_pPev = this->m_Network.m_pPev;
          if ( m_pPev != nullptr )
            CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x36Cu);
          this->m_bEmit.m_Value = 1;
        }
      }
    }
    else if ( useType == USE_OFF && this->m_bEmit.m_Value != 0 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        this->m_bEmit.m_Value = 0;
      }
      else
      {
        v7 = this->m_Network.m_pPev;
        if ( v7 != nullptr )
          CBaseEdict::StateChanged(this: &v7->CBaseEdict, offset: 0x36Cu);
        this->m_bEmit.m_Value = 0;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1032AA00
// Name: protected: void CSteamJet::InputToggle(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamJet::InputToggle(CSteamJet *this, inputdata_t *data)
{
  CNetworkVarBase<int,CSteamJet::NetworkVar_m_bEmit> *p_m_bEmit; // esi
  int v3; // edi
  edict_t *m_pPev; // ecx

  p_m_bEmit = &this->m_bEmit;
  v3 = this->m_bEmit.m_Value == 0;
  if ( this->m_bEmit.m_Value != v3 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_bEmit->m_Value = v3;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x36Cu);
      p_m_bEmit->m_Value = v3;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1032AA50
// Name: protected: void CSteamJet::InputTurnOn(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamJet::InputTurnOn(CSteamJet *this, inputdata_t *data)
{
  CNetworkVarBase<int,CSteamJet::NetworkVar_m_bEmit> *p_m_bEmit; // esi
  edict_t *m_pPev; // ecx

  p_m_bEmit = &this->m_bEmit;
  if ( this->m_bEmit.m_Value != 1 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_bEmit->m_Value = 1;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x36Cu);
      p_m_bEmit->m_Value = 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1032AAA0
// Name: protected: void CSteamJet::InputTurnOff(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamJet::InputTurnOff(CSteamJet *this, inputdata_t *data)
{
  CNetworkVarBase<int,CSteamJet::NetworkVar_m_bEmit> *p_m_bEmit; // esi
  edict_t *m_pPev; // ecx

  p_m_bEmit = &this->m_bEmit;
  if ( this->m_bEmit.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_bEmit->m_Value = 0;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x36Cu);
      p_m_bEmit->m_Value = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1032AB90
// Name: public: virtual class IServerNetworkable __near * CEntityFactory<class CSteamJet>::Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CServerNetworkProperty *__thiscall CEntityFactory<CSteamJet>::Create(
        CEntityFactory<CSteamJet> *this,
        const char *pClassName)
{
  return &_CreateEntityTemplate<CSteamJet>(newEnt: nullptr, className: pClassName)->m_Network;
}

//------------------------------------------------------------------------------
// Address: 0x104158F0
// Name: DT_SteamJet::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_SteamJet::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_SteamJet::g_SendTable);
  return atexit(func: DT_SteamJet::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10415910
// Name: DT_SteamJet::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_SteamJet::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_SteamJet::ignored>();
  DT_SteamJet::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10415960
// Name: CSteamJet_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CSteamJet_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CSteamJet>(__formal: nullptr);
  CSteamJet_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421D50
// Name: DT_SteamJet::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_SteamJet::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_SteamJet::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10042920
// Name: class CRallyPoint __near * _CreateEntityTemplate<class CRallyPoint>(class CRallyPoint __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRallyPoint *__cdecl _CreateEntityTemplate<CRallyPoint>(CRallyPoint *newEnt, const char *className)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x38Cu);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CRallyPoint::`vftable';
    *(_DWORD *)&v3[1].m_Network.m_PVSInfo.m_nHeadNode = 0;
    v3[1].m_Network.m_PVSInfo.m_vCenter[0] = NAN;
    v3[1].m_Network.m_PVSInfo.m_vCenter[1] = 0.0;
    *(_DWORD *)v3[1].m_Network.m_PVSInfo.m_pClustersInline = -1;
    HIWORD(v3[1].m_Network.m_pOuter) = -1;
    v3->PostConstructor(this: v3, a2: className);
    return (CRallyPoint *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100438F0
// Name: struct datamap_t __near * DataMapInit<class CAI_FearBehavior>(class CAI_FearBehavior __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CAI_FearBehavior>()
{
  if ( (_S2_7 & 1) == 0 )
  {
    _S2_7 |= 1u;
    nameHolder_20.m_pszBase = "CAI_FearBehavior";
    nameHolder_20.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_20.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_20.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_20.m_Names.m_Size = 0;
    nameHolder_20.m_Names.m_pElements = nullptr;
    nameHolder_20.m_nLenBase = 16;
    atexit(func: DataMapInit_CAI_FearBehavior__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CAI_FearBehavior::m_DataMap.baseMap = &CAI_BehaviorBase::m_DataMap;
  CAI_FearBehavior::m_DataMap.dataNumFields = 6;
  CAI_FearBehavior::m_DataMap.dataDesc = &dataDesc_20[1];
  return &CAI_FearBehavior::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10044900
// Name: struct datamap_t __near * DataMapInit<class CAI_FightFromCoverBehavior>(class CAI_FightFromCoverBehavior __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CAI_FightFromCoverBehavior>()
{
  if ( (_S2_8 & 1) == 0 )
  {
    _S2_8 |= 1u;
    nameHolder_21.m_pszBase = "CAI_FightFromCoverBehavior";
    nameHolder_21.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_21.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_21.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_21.m_Names.m_Size = 0;
    nameHolder_21.m_Names.m_pElements = nullptr;
    nameHolder_21.m_nLenBase = 26;
    atexit(func: DataMapInit_CAI_FightFromCoverBehavior__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CAI_FightFromCoverBehavior::m_DataMap.baseMap = &CAI_BehaviorBase::m_DataMap;
  CAI_FightFromCoverBehavior::m_DataMap.dataNumFields = 3;
  CAI_FightFromCoverBehavior::m_DataMap.dataDesc = &dataDesc_21[1];
  return &CAI_FightFromCoverBehavior::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10044980
// Name: struct datamap_t __near * DataMapInit<class CAI_FightFromCoverGoal>(class CAI_FightFromCoverGoal __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CAI_FightFromCoverGoal>()
{
  if ( (_S3_4 & 1) == 0 )
  {
    _S3_4 |= 1u;
    nameHolder_22.m_pszBase = "CAI_FightFromCoverGoal";
    nameHolder_22.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_22.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_22.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_22.m_Names.m_Size = 0;
    nameHolder_22.m_Names.m_pElements = nullptr;
    nameHolder_22.m_nLenBase = 22;
    atexit(func: DataMapInit_CAI_FightFromCoverGoal__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CAI_FightFromCoverGoal::m_DataMap.baseMap = &CAI_GoalEntity::m_DataMap;
  if ( (_S3_4 & 2) == 0 )
  {
    _S3_4 |= 2u;
    dataDesc_22[9].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                 this: &nameHolder_22,
                                 pszIdentifier: "FrontThink");
    dataDesc_22[9].fieldOffset = 0;
    *(_DWORD *)&dataDesc_22[9].fieldSize = 2097153;
    dataDesc_22[9].externalName = nullptr;
    dataDesc_22[9].pSaveRestoreOps = nullptr;
    dataDesc_22[9].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAI_FightFromCoverGoal::FrontThink;
    *(_QWORD *)&dataDesc_22[9].td = 0;
    *(_QWORD *)&dataDesc_22[9].override_field = 0;
    *(_QWORD *)&dataDesc_22[9].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_22[9].flatOffset[1] = 0;
  }
  CAI_FightFromCoverGoal::m_DataMap.dataNumFields = 9;
  CAI_FightFromCoverGoal::m_DataMap.dataDesc = &dataDesc_22[1];
  return &CAI_FightFromCoverGoal::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10048260
// Name: class CAI_LeadGoal_Weapon __near * _CreateEntityTemplate<class CAI_LeadGoal_Weapon>(class CAI_LeadGoal_Weapon __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CAI_LeadGoal_Weapon *__cdecl _CreateEntityTemplate<CAI_LeadGoal_Weapon>(
        CAI_LeadGoal_Weapon *newEnt,
        const char *className)
{
  CAI_LeadGoal *v2; // eax
  _DWORD *v3; // esi

  v2 = (CAI_LeadGoal *)CBaseEntity::operator new(stAllocateBlock: 0x45Cu);
  v3 = &v2->CAI_GoalEntity::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
  if ( v2 != nullptr )
  {
    CAI_LeadGoal::CAI_LeadGoal(this: v2);
    *v3 = &CAI_LeadGoal_Weapon::`vftable'{for `CBaseEntity'};
    v3[213] = &CAI_LeadGoal_Weapon::`vftable'{for `IEntityListener'};
    v3[226] = &CAI_LeadGoal_Weapon::`vftable';
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CAI_LeadGoal_Weapon *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100493E0
// Name: struct datamap_t __near * DataMapInit<class CAI_BattleLine>(class CAI_BattleLine __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CAI_BattleLine>()
{
  if ( (_S2_12 & 1) == 0 )
  {
    _S2_12 |= 1u;
    nameHolder_33.m_pszBase = "CAI_BattleLine";
    nameHolder_33.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_33.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_33.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_33.m_Names.m_Size = 0;
    nameHolder_33.m_Names.m_pElements = nullptr;
    nameHolder_33.m_nLenBase = 14;
    atexit(func: DataMapInit_CAI_BattleLine__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CAI_BattleLine::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S2_12 & 2) == 0 )
  {
    _S2_12 |= 2u;
    dataDesc_33[7].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                 this: &nameHolder_33,
                                 pszIdentifier: "MovementThink");
    dataDesc_33[7].fieldOffset = 0;
    *(_DWORD *)&dataDesc_33[7].fieldSize = 2097153;
    dataDesc_33[7].externalName = nullptr;
    dataDesc_33[7].pSaveRestoreOps = nullptr;
    dataDesc_33[7].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAI_BattleLine::MovementThink;
    *(_QWORD *)&dataDesc_33[7].td = 0;
    *(_QWORD *)&dataDesc_33[7].override_field = 0;
    *(_QWORD *)&dataDesc_33[7].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_33[7].flatOffset[1] = 0;
  }
  CAI_BattleLine::m_DataMap.dataNumFields = 7;
  CAI_BattleLine::m_DataMap.dataDesc = &dataDesc_33[1];
  return &CAI_BattleLine::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10057370
// Name: class CAI_TestHull __near * _CreateEntityTemplate<class CAI_TestHull>(class CAI_TestHull __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CAI_TestHull *__cdecl _CreateEntityTemplate<CAI_TestHull>(CAI_TestHull *newEnt, const char *className)
{
  CAI_BaseNPC *v2; // eax
  _DWORD *v3; // esi

  v2 = (CAI_BaseNPC *)CBaseEntity::operator new(stAllocateBlock: 0xE88u);
  v3 = &v2->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
  if ( v2 != nullptr )
  {
    CAI_BaseNPC::CAI_BaseNPC(this: v2);
    *v3 = &CAI_TestHull::`vftable'{for `CBaseCombatCharacter'};
    v3[571] = &CAI_TestHull::`vftable'{for `CAI_DefMovementSink'};
    v3[572] = &CAI_TestHull::`vftable'{for `IAI_BehaviorBridge'};
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CAI_TestHull *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008A4A0
// Name: struct datamap_t __near * DataMapInit<class CAI_SpeechFilter>(class CAI_SpeechFilter __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CAI_SpeechFilter>()
{
  if ( (_S2_35 & 1) == 0 )
  {
    _S2_35 |= 1u;
    nameHolder_69.m_pszBase = "CAI_SpeechFilter";
    nameHolder_69.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_69.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_69.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_69.m_Names.m_Size = 0;
    nameHolder_69.m_Names.m_pElements = nullptr;
    nameHolder_69.m_nLenBase = 16;
    atexit(func: DataMapInit_CAI_SpeechFilter__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CAI_SpeechFilter::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CAI_SpeechFilter::m_DataMap.dataNumFields = 7;
  CAI_SpeechFilter::m_DataMap.dataDesc = &dataDesc_66[1];
  return &CAI_SpeechFilter::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100D7750
// Name: __CreateCServerGameTagsIServerGameTags_interface_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CServerGameTags *__cdecl _CreateCServerGameTagsIServerGameTags_interface_0()
{
  return &_g_CServerGameTags_singleton_0;
}

//------------------------------------------------------------------------------
// Address: 0x100E0C30
// Name: struct datamap_t __near * DataMapInit<class CBeamSpotlight>(class CBeamSpotlight __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CBeamSpotlight>()
{
  if ( (_S2_57 & 1) == 0 )
  {
    _S2_57 |= 1u;
    nameHolder_100.m_pszBase = "CBeamSpotlight";
    nameHolder_100.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_100.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_100.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_100.m_Names.m_Size = 0;
    nameHolder_100.m_Names.m_pElements = nullptr;
    nameHolder_100.m_nLenBase = 14;
    atexit(func: DataMapInit_CBeamSpotlight__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CBeamSpotlight::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S2_57 & 2) == 0 )
  {
    _S2_57 |= 2u;
    *(_QWORD *)&dataDesc_97[17].inputFunc = 0;
    *(_QWORD *)&dataDesc_97[17].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_97[17].override_count = 0;
    *(_QWORD *)dataDesc_97[17].flatOffset = 0;
    dataDesc_97[17].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_97[17].flatGroup = 0;
    dataDesc_97[18].fieldType = FIELD_CUSTOM;
    dataDesc_97[18].fieldName = "m_OnOff";
    dataDesc_97[18].fieldOffset = 916;
    *(_DWORD *)&dataDesc_97[18].fieldSize = 1441793;
    dataDesc_97[18].externalName = "OnLightOff";
    dataDesc_97[18].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_97[18].inputFunc = 0;
    *(_QWORD *)&dataDesc_97[18].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_97[18].override_count = 0;
    *(_QWORD *)dataDesc_97[18].flatOffset = 0;
    *(_DWORD *)&dataDesc_97[18].flatGroup = 0;
  }
  CBeamSpotlight::m_DataMap.dataNumFields = 18;
  CBeamSpotlight::m_DataMap.dataDesc = &dataDesc_97[1];
  return &CBeamSpotlight::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100E1E20
// Name: class CFuncConveyor __near * _CreateEntityTemplate<class CFuncConveyor>(class CFuncConveyor __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFuncConveyor *__cdecl _CreateEntityTemplate<CFuncConveyor>(CFuncConveyor *newEnt, const char *className)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // edi
  CBaseEdict *v4; // ecx

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x368u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CFuncConveyor::`vftable';
    if ( *(float *)&v3[1].m_Network.__vftable != 0.0 )
    {
      if ( v3->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&v3->m_Network + 76) |= 1u;
      }
      else
      {
        v4 = &v3->m_Network.m_pPev->CBaseEdict;
        if ( v4 != nullptr )
          CBaseEdict::StateChanged(this: v4, offset: 0x364u);
      }
      v3[1].m_Network.__vftable = nullptr;
    }
    v3->PostConstructor(this: v3, a2: className);
    return (CFuncConveyor *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E1EC0
// Name: class CFuncRotating __near * _CreateEntityTemplate<class CFuncRotating>(class CFuncRotating __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFuncRotating *__cdecl _CreateEntityTemplate<CFuncRotating>(CFuncRotating *newEnt, const char *className)
{
  CBaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x3C0u);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    *v3 = &CFuncRotating::`vftable';
    v3[228] = 0;
    v3[231] = -1;
    v3[232] = 0;
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CFuncRotating *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100E2220
// Name: struct datamap_t __near * DataMapInit<class CFuncWall>(class CFuncWall __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CFuncWall>()
{
  if ( (_S2_58 & 1) == 0 )
  {
    _S2_58 |= 1u;
    nameHolder_101.m_pszBase = "CFuncWall";
    nameHolder_101.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_101.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_101.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_101.m_Names.m_Size = 0;
    nameHolder_101.m_Names.m_pElements = nullptr;
    nameHolder_101.m_nLenBase = 9;
    atexit(func: DataMapInit_CFuncWall__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CFuncWall::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CFuncWall::m_DataMap.dataNumFields = 1;
  CFuncWall::m_DataMap.dataDesc = &dataDesc_98[1];
  return &CFuncWall::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100E2290
// Name: struct datamap_t __near * DataMapInit<class CFuncWallToggle>(class CFuncWallToggle __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CFuncWallToggle>()
{
  if ( (_S3_30 & 1) == 0 )
  {
    _S3_30 |= 1u;
    nameHolder_102.m_pszBase = "CFuncWallToggle";
    nameHolder_102.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_102.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_102.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_102.m_Names.m_Size = 0;
    nameHolder_102.m_Names.m_pElements = nullptr;
    nameHolder_102.m_nLenBase = 15;
    atexit(func: DataMapInit_CFuncWallToggle__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CFuncWallToggle::m_DataMap.baseMap = &CFuncWall::m_DataMap;
  CFuncWallToggle::m_DataMap.dataNumFields = 1;
  CFuncWallToggle::m_DataMap.dataDesc = &dataDesc_99[1];
  return &CFuncWallToggle::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100E2300
// Name: struct datamap_t __near * DataMapInit<class CFuncVehicleClip>(class CFuncVehicleClip __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CFuncVehicleClip>()
{
  if ( (_S4_16 & 1) == 0 )
  {
    _S4_16 |= 1u;
    nameHolder_103.m_pszBase = "CFuncVehicleClip";
    nameHolder_103.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_103.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_103.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_103.m_Names.m_Size = 0;
    nameHolder_103.m_Names.m_pElements = nullptr;
    nameHolder_103.m_nLenBase = 16;
    atexit(func: DataMapInit_CFuncVehicleClip__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CFuncVehicleClip::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CFuncVehicleClip::m_DataMap.dataNumFields = 2;
  CFuncVehicleClip::m_DataMap.dataDesc = &dataDesc_100[1];
  return &CFuncVehicleClip::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100E2380
// Name: struct datamap_t __near * DataMapInit<class CFuncConveyor>(class CFuncConveyor __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CFuncConveyor>()
{
  if ( (_S5_10 & 1) == 0 )
  {
    _S5_10 |= 1u;
    nameHolder_104.m_pszBase = "CFuncConveyor";
    nameHolder_104.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_104.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_104.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_104.m_Names.m_Size = 0;
    nameHolder_104.m_Names.m_pElements = nullptr;
    nameHolder_104.m_nLenBase = 13;
    atexit(func: DataMapInit_CFuncConveyor__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CFuncConveyor::m_DataMap.baseMap = &CFuncWall::m_DataMap;
  CFuncConveyor::m_DataMap.dataNumFields = 4;
  CFuncConveyor::m_DataMap.dataDesc = &dataDesc_101[1];
  return &CFuncConveyor::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100E9F20
// Name: struct datamap_t __near * DataMapInit<class CEventAction>(class CEventAction __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CEventAction>()
{
  if ( (_S2_60 & 1) == 0 )
  {
    _S2_60 |= 1u;
    nameHolder_109.m_pszBase = "CEventAction";
    nameHolder_109.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_109.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_109.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_109.m_Names.m_Size = 0;
    nameHolder_109.m_Names.m_pElements = nullptr;
    nameHolder_109.m_nLenBase = 12;
    atexit(func: DataMapInit_CEventAction__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CEventAction::m_DataMap.baseMap = nullptr;
  CEventAction::m_DataMap.dataNumFields = 6;
  CEventAction::m_DataMap.dataDesc = &dataDesc_106[1];
  return &CEventAction::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100E9FB0
// Name: struct datamap_t __near * DataMapInit<class CBaseEntityOutput>(class CBaseEntityOutput __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CBaseEntityOutput>()
{
  if ( (_S3_32 & 1) == 0 )
  {
    _S3_32 |= 1u;
    nameHolder_110.m_pszBase = "CBaseEntityOutput";
    nameHolder_110.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_110.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_110.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_110.m_Names.m_Size = 0;
    nameHolder_110.m_Names.m_pElements = nullptr;
    nameHolder_110.m_nLenBase = 17;
    atexit(func: DataMapInit_CBaseEntityOutput__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CBaseEntityOutput::m_DataMap.baseMap = nullptr;
  if ( (_S3_32 & 2) == 0 )
  {
    _S3_32 |= 2u;
    dataDesc_107[1].pSaveRestoreOps = variantFuncs;
    dataDesc_107[1].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_107[1].td = 0;
    *(_QWORD *)&dataDesc_107[1].override_field = 0;
    *(_QWORD *)&dataDesc_107[1].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_107[1].flatOffset[1] = 0;
  }
  CBaseEntityOutput::m_DataMap.dataNumFields = 1;
  CBaseEntityOutput::m_DataMap.dataDesc = &dataDesc_107[1];
  return &CBaseEntityOutput::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100EA070
// Name: struct datamap_t __near * DataMapInit<class CEventQueue>(class CEventQueue __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CEventQueue>()
{
  if ( (_S4_18 & 1) == 0 )
  {
    _S4_18 |= 1u;
    nameHolder_111.m_pszBase = "CEventQueue";
    nameHolder_111.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_111.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_111.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_111.m_Names.m_Size = 0;
    nameHolder_111.m_Names.m_pElements = nullptr;
    nameHolder_111.m_nLenBase = 11;
    atexit(func: DataMapInit_CEventQueue__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CEventQueue::m_DataMap.baseMap = nullptr;
  CEventQueue::m_DataMap.dataNumFields = 1;
  CEventQueue::m_DataMap.dataDesc = &dataDesc_108[1];
  return &CEventQueue::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100EDC90
// Name: struct datamap_t __near * DataMapInit<class CPointClientCommand>(class CPointClientCommand __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CPointClientCommand>()
{
  if ( (_S2_62 & 1) == 0 )
  {
    _S2_62 |= 1u;
    nameHolder_114.m_pszBase = "CPointClientCommand";
    nameHolder_114.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_114.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_114.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_114.m_Names.m_Size = 0;
    nameHolder_114.m_Names.m_pElements = nullptr;
    nameHolder_114.m_nLenBase = 19;
    atexit(func: DataMapInit_CPointClientCommand__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CPointClientCommand::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CPointClientCommand::m_DataMap.dataNumFields = 1;
  CPointClientCommand::m_DataMap.dataDesc = &dataDesc_111[1];
  return &CPointClientCommand::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100EDD00
// Name: struct datamap_t __near * DataMapInit<class CPointServerCommand>(class CPointServerCommand __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CPointServerCommand>()
{
  if ( (_S3_33 & 1) == 0 )
  {
    _S3_33 |= 1u;
    nameHolder_115.m_pszBase = "CPointServerCommand";
    nameHolder_115.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_115.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_115.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_115.m_Names.m_Size = 0;
    nameHolder_115.m_Names.m_pElements = nullptr;
    nameHolder_115.m_nLenBase = 19;
    atexit(func: DataMapInit_CPointServerCommand__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CPointServerCommand::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CPointServerCommand::m_DataMap.dataNumFields = 1;
  CPointServerCommand::m_DataMap.dataDesc = &dataDesc_112[1];
  return &CPointServerCommand::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100EDD70
// Name: struct datamap_t __near * DataMapInit<class CPointBroadcastClientCommand>(class CPointBroadcastClientCommand __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CPointBroadcastClientCommand>()
{
  if ( (_S4_19 & 1) == 0 )
  {
    _S4_19 |= 1u;
    nameHolder_116.m_pszBase = "CPointBroadcastClientCommand";
    nameHolder_116.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_116.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_116.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_116.m_Names.m_Size = 0;
    nameHolder_116.m_Names.m_pElements = nullptr;
    nameHolder_116.m_nLenBase = 28;
    atexit(func: DataMapInit_CPointBroadcastClientCommand__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CPointBroadcastClientCommand::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CPointBroadcastClientCommand::m_DataMap.dataNumFields = 1;
  CPointBroadcastClientCommand::m_DataMap.dataDesc = &dataDesc_113[1];
  return &CPointBroadcastClientCommand::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100F3C80
// Name: struct datamap_t __near * DataMapInit<class CColorCorrection>(class CColorCorrection __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CColorCorrection>()
{
  if ( (_S2_64 & 1) == 0 )
  {
    _S2_64 |= 1u;
    nameHolder_118.m_pszBase = "CColorCorrection";
    nameHolder_118.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_118.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_118.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_118.m_Names.m_Size = 0;
    nameHolder_118.m_Names.m_pElements = nullptr;
    nameHolder_118.m_nLenBase = 16;
    atexit(func: DataMapInit_CColorCorrection__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CColorCorrection::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S2_64 & 2) == 0 )
  {
    _S2_64 |= 2u;
    dataDesc_470[1].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_118,
                                  pszIdentifier: "FadeInThink");
    dataDesc_470[1].flags = 32;
    dataDesc_470[1].fieldOffset = 0;
    dataDesc_470[1].fieldSize = 1;
    dataDesc_470[1].externalName = nullptr;
    dataDesc_470[1].pSaveRestoreOps = nullptr;
    dataDesc_470[1].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CColorCorrection::FadeInThink;
    *(_QWORD *)&dataDesc_470[1].td = 0;
    *(_QWORD *)&dataDesc_470[1].override_field = 0;
    *(_QWORD *)&dataDesc_470[1].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_470[1].flatOffset[1] = 0;
    dataDesc_470[2].fieldType = FIELD_VOID;
    dataDesc_470[2].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_118,
                                  pszIdentifier: "FadeOutThink");
    dataDesc_470[2].fieldSize = 1;
    dataDesc_470[2].flags = 32;
    *(_QWORD *)&dataDesc_470[2].td = 0;
    *(_QWORD *)&dataDesc_470[2].override_field = 0;
    *(_QWORD *)&dataDesc_470[2].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_470[2].flatOffset[1] = 0;
    *(_QWORD *)dataDesc_470[3].flatOffset = 0;
    dataDesc_470[2].fieldOffset = 0;
    dataDesc_470[2].externalName = nullptr;
    dataDesc_470[2].pSaveRestoreOps = nullptr;
    dataDesc_470[2].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CColorCorrection::FadeOutThink;
    dataDesc_470[3].fieldType = FIELD_FLOAT;
    dataDesc_470[3].fieldName = "m_flCurWeight";
    dataDesc_470[3].fieldOffset = 896;
    dataDesc_470[3].fieldSize = 1;
    dataDesc_470[3].flags = 2;
    dataDesc_470[3].externalName = nullptr;
    dataDesc_470[3].pSaveRestoreOps = nullptr;
    dataDesc_470[3].inputFunc = nullptr;
    dataDesc_470[3].td = nullptr;
    dataDesc_470[3].fieldSizeInBytes = 4;
    dataDesc_470[3].override_field = nullptr;
    dataDesc_470[3].override_count = 0;
    dataDesc_470[3].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_470[3].flatGroup = 0;
    dataDesc_470[4].fieldType = FIELD_FLOAT;
    dataDesc_470[4].fieldName = "m_flTimeStartFadeIn";
    dataDesc_470[4].fieldOffset = 868;
    dataDesc_470[4].fieldSize = 1;
    dataDesc_470[4].flags = 2;
    dataDesc_470[4].externalName = nullptr;
    dataDesc_470[4].pSaveRestoreOps = nullptr;
    dataDesc_470[4].inputFunc = nullptr;
    dataDesc_470[4].td = nullptr;
    dataDesc_470[4].fieldSizeInBytes = 4;
    dataDesc_470[4].override_field = nullptr;
    dataDesc_470[4].override_count = 0;
    dataDesc_470[4].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_470[4].flatOffset = 0;
    *(_DWORD *)&dataDesc_470[4].flatGroup = 0;
    dataDesc_470[5].fieldType = FIELD_FLOAT;
    dataDesc_470[5].fieldName = "m_flTimeStartFadeOut";
    dataDesc_470[5].fieldOffset = 872;
    dataDesc_470[5].fieldSize = 1;
    dataDesc_470[5].flags = 2;
    dataDesc_470[5].externalName = nullptr;
    dataDesc_470[5].pSaveRestoreOps = nullptr;
    dataDesc_470[5].inputFunc = nullptr;
    dataDesc_470[5].td = nullptr;
    dataDesc_470[6].flags = 2;
    dataDesc_470[7].flags = 2;
    dataDesc_470[6].fieldSize = 1;
    dataDesc_470[7].fieldSize = 1;
    dataDesc_470[8].fieldSize = 1;
    dataDesc_470[8].flags = 6;
    *(_QWORD *)dataDesc_470[5].flatOffset = 0;
    dataDesc_470[9].fieldSize = 1;
    *(_QWORD *)dataDesc_470[6].flatOffset = 0;
    *(_QWORD *)dataDesc_470[7].flatOffset = 0;
    dataDesc_470[9].flags = 6;
    *(_QWORD *)dataDesc_470[8].flatOffset = 0;
    dataDesc_470[10].fieldSize = 1;
    dataDesc_470[5].fieldSizeInBytes = 4;
    dataDesc_470[5].override_field = nullptr;
    dataDesc_470[5].override_count = 0;
    dataDesc_470[5].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_470[5].flatGroup = 0;
    dataDesc_470[6].fieldType = FIELD_FLOAT;
    dataDesc_470[6].fieldName = "m_flStartFadeInWeight";
    dataDesc_470[6].fieldOffset = 860;
    dataDesc_470[6].externalName = nullptr;
    dataDesc_470[6].pSaveRestoreOps = nullptr;
    dataDesc_470[6].inputFunc = nullptr;
    dataDesc_470[6].td = nullptr;
    dataDesc_470[6].fieldSizeInBytes = 4;
    dataDesc_470[6].override_field = nullptr;
    dataDesc_470[6].override_count = 0;
    dataDesc_470[6].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_470[6].flatGroup = 0;
    dataDesc_470[7].fieldType = FIELD_FLOAT;
    dataDesc_470[7].fieldName = "m_flStartFadeOutWeight";
    dataDesc_470[7].fieldOffset = 864;
    dataDesc_470[7].externalName = nullptr;
    dataDesc_470[7].pSaveRestoreOps = nullptr;
    dataDesc_470[7].inputFunc = nullptr;
    dataDesc_470[7].td = nullptr;
    dataDesc_470[7].fieldSizeInBytes = 4;
    dataDesc_470[7].override_field = nullptr;
    dataDesc_470[7].override_count = 0;
    dataDesc_470[7].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_470[7].flatGroup = 0;
    dataDesc_470[8].fieldType = FIELD_FLOAT;
    dataDesc_470[8].fieldName = "m_MinFalloff";
    dataDesc_470[8].fieldOffset = 888;
    dataDesc_470[8].externalName = "minfalloff";
    dataDesc_470[8].pSaveRestoreOps = nullptr;
    dataDesc_470[8].inputFunc = nullptr;
    dataDesc_470[8].td = nullptr;
    dataDesc_470[8].fieldSizeInBytes = 4;
    dataDesc_470[8].override_field = nullptr;
    dataDesc_470[8].override_count = 0;
    dataDesc_470[8].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_470[8].flatGroup = 0;
    dataDesc_470[9].fieldType = FIELD_FLOAT;
    dataDesc_470[9].fieldName = "m_MaxFalloff";
    dataDesc_470[9].fieldOffset = 892;
    dataDesc_470[9].externalName = "maxfalloff";
    dataDesc_470[9].pSaveRestoreOps = nullptr;
    dataDesc_470[9].inputFunc = nullptr;
    dataDesc_470[9].td = nullptr;
    dataDesc_470[9].fieldSizeInBytes = 4;
    dataDesc_470[9].override_field = nullptr;
    dataDesc_470[9].override_count = 0;
    dataDesc_470[9].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_470[9].flatOffset = 0;
    *(_DWORD *)&dataDesc_470[9].flatGroup = 0;
    dataDesc_470[10].fieldType = FIELD_FLOAT;
    dataDesc_470[10].fieldName = "m_flMaxWeight";
    dataDesc_470[10].fieldOffset = 876;
    dataDesc_470[10].flags = 6;
    dataDesc_470[11].fieldSize = 1;
    dataDesc_470[11].flags = 6;
    dataDesc_470[12].fieldSize = 1;
    *(_QWORD *)dataDesc_470[10].flatOffset = 0;
    *(_QWORD *)dataDesc_470[11].flatOffset = 0;
    dataDesc_470[12].flags = 6;
    *(_QWORD *)dataDesc_470[12].flatOffset = 0;
    dataDesc_470[10].fieldSizeInBytes = 4;
    dataDesc_470[11].fieldSizeInBytes = 4;
    dataDesc_470[12].fieldSizeInBytes = 4;
    dataDesc_470[13].fieldSize = 1;
    dataDesc_470[13].fieldSizeInBytes = 4;
    *(_QWORD *)dataDesc_470[13].flatOffset = 0;
    dataDesc_470[10].externalName = "maxweight";
    dataDesc_470[10].pSaveRestoreOps = nullptr;
    dataDesc_470[10].inputFunc = nullptr;
    dataDesc_470[10].td = nullptr;
    dataDesc_470[10].override_field = nullptr;
    dataDesc_470[10].override_count = 0;
    dataDesc_470[10].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_470[10].flatGroup = 0;
    dataDesc_470[11].fieldType = FIELD_FLOAT;
    dataDesc_470[11].fieldName = "m_flFadeInDuration";
    dataDesc_470[11].fieldOffset = 852;
    dataDesc_470[11].externalName = "fadeInDuration";
    dataDesc_470[11].pSaveRestoreOps = nullptr;
    dataDesc_470[11].inputFunc = nullptr;
    dataDesc_470[11].td = nullptr;
    dataDesc_470[11].override_field = nullptr;
    dataDesc_470[11].override_count = 0;
    dataDesc_470[11].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_470[11].flatGroup = 0;
    dataDesc_470[12].fieldType = FIELD_FLOAT;
    dataDesc_470[12].fieldName = "m_flFadeOutDuration";
    dataDesc_470[12].fieldOffset = 856;
    dataDesc_470[12].externalName = "fadeOutDuration";
    dataDesc_470[12].pSaveRestoreOps = nullptr;
    dataDesc_470[12].inputFunc = nullptr;
    dataDesc_470[12].td = nullptr;
    dataDesc_470[12].override_field = nullptr;
    dataDesc_470[12].override_count = 0;
    dataDesc_470[12].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_470[12].flatGroup = 0;
    dataDesc_470[13].fieldType = FIELD_STRING;
    dataDesc_470[13].fieldName = "m_lookupFilename";
    dataDesc_470[13].fieldOffset = 1160;
    dataDesc_470[13].flags = 6;
    dataDesc_470[13].externalName = "filename";
    dataDesc_470[13].pSaveRestoreOps = nullptr;
    dataDesc_470[13].inputFunc = nullptr;
    dataDesc_470[13].td = nullptr;
    dataDesc_470[13].override_field = nullptr;
    dataDesc_470[13].override_count = 0;
    dataDesc_470[13].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_470[13].flatGroup = 0;
    dataDesc_470[14].fieldType = FIELD_BOOLEAN;
    dataDesc_470[14].fieldName = "m_bEnabled";
    dataDesc_470[14].fieldOffset = 881;
    dataDesc_470[14].fieldSize = 1;
    dataDesc_470[14].flags = 6;
    dataDesc_470[14].externalName = "enabled";
    dataDesc_470[14].pSaveRestoreOps = nullptr;
    dataDesc_470[14].inputFunc = nullptr;
    dataDesc_470[14].td = nullptr;
    dataDesc_470[14].fieldSizeInBytes = 1;
    dataDesc_470[14].override_field = nullptr;
    dataDesc_470[14].override_count = 0;
    dataDesc_470[14].fieldTolerance = 0.0;
    dataDesc_470[15].fieldTolerance = 0.0;
    dataDesc_470[16].fieldTolerance = 0.0;
    dataDesc_470[15].fieldType = FIELD_BOOLEAN;
    dataDesc_470[16].fieldType = FIELD_BOOLEAN;
    dataDesc_470[16].flags = 6;
    dataDesc_470[15].flags = 6;
    *(_QWORD *)dataDesc_470[16].flatOffset = 0;
    dataDesc_470[17].fieldSize = 1;
    *(_QWORD *)&dataDesc_470[17].td = 0;
    *(_QWORD *)&dataDesc_470[17].override_field = 0;
    *(_QWORD *)&dataDesc_470[17].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_470[17].flatOffset[1] = 0;
    dataDesc_470[15].fieldSize = 1;
    dataDesc_470[16].fieldSize = 1;
    dataDesc_470[17].flags = 8;
    dataDesc_470[18].fieldSize = 1;
    *(_QWORD *)dataDesc_470[14].flatOffset = 0;
    *(_QWORD *)&dataDesc_470[18].td = 0;
    *(_QWORD *)&dataDesc_470[18].override_field = 0;
    *(_QWORD *)&dataDesc_470[18].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_470[18].flatOffset[1] = 0;
    *(_DWORD *)&dataDesc_470[14].flatGroup = 0;
    dataDesc_470[15].fieldName = "m_bStartDisabled";
    dataDesc_470[15].fieldOffset = 880;
    dataDesc_470[15].externalName = "StartDisabled";
    dataDesc_470[15].pSaveRestoreOps = nullptr;
    dataDesc_470[15].inputFunc = nullptr;
    dataDesc_470[15].td = nullptr;
    dataDesc_470[15].fieldSizeInBytes = 1;
    dataDesc_470[15].override_field = nullptr;
    dataDesc_470[15].override_count = 0;
    *(_QWORD *)dataDesc_470[15].flatOffset = 0;
    *(_DWORD *)&dataDesc_470[15].flatGroup = 0;
    dataDesc_470[16].fieldName = "m_bExclusive";
    dataDesc_470[16].fieldOffset = 884;
    dataDesc_470[16].externalName = "exclusive";
    dataDesc_470[16].pSaveRestoreOps = nullptr;
    dataDesc_470[16].inputFunc = nullptr;
    dataDesc_470[16].td = nullptr;
    dataDesc_470[16].fieldSizeInBytes = 1;
    dataDesc_470[16].override_field = nullptr;
    dataDesc_470[16].override_count = 0;
    *(_DWORD *)&dataDesc_470[16].flatGroup = 0;
    dataDesc_470[17].fieldType = FIELD_VOID;
    dataDesc_470[17].fieldName = "InputEnable";
    dataDesc_470[17].fieldOffset = 0;
    dataDesc_470[17].externalName = "Enable";
    dataDesc_470[17].pSaveRestoreOps = nullptr;
    dataDesc_470[17].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CColorCorrection::InputEnable;
    dataDesc_470[18].fieldType = FIELD_VOID;
    dataDesc_470[18].fieldName = "InputDisable";
    dataDesc_470[18].fieldOffset = 0;
    dataDesc_470[18].flags = 8;
    dataDesc_470[18].externalName = "Disable";
    dataDesc_470[18].pSaveRestoreOps = nullptr;
    dataDesc_470[18].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CColorCorrection::InputDisable;
    dataDesc_470[19].fieldType = FIELD_FLOAT;
    dataDesc_470[19].fieldName = "InputSetFadeInDuration";
    dataDesc_470[19].fieldOffset = 0;
    *(_DWORD *)&dataDesc_470[19].fieldSize = 524289;
    dataDesc_470[19].externalName = "SetFadeInDuration";
    dataDesc_470[19].pSaveRestoreOps = nullptr;
    dataDesc_470[19].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CColorCorrection::InputSetFadeInDuration;
    *(_QWORD *)&dataDesc_470[19].td = 0;
    *(_QWORD *)&dataDesc_470[19].override_field = 0;
    *(_QWORD *)&dataDesc_470[19].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_470[19].flatOffset[1] = 0;
    dataDesc_470[20].fieldType = FIELD_FLOAT;
    dataDesc_470[20].fieldName = "InputSetFadeOutDuration";
    dataDesc_470[20].fieldOffset = 0;
    *(_DWORD *)&dataDesc_470[20].fieldSize = 524289;
    dataDesc_470[20].externalName = "SetFadeOutDuration";
    dataDesc_470[20].pSaveRestoreOps = nullptr;
    dataDesc_470[20].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CColorCorrection::InputSetFadeOutDuration;
    *(_QWORD *)&dataDesc_470[20].td = 0;
    *(_QWORD *)&dataDesc_470[20].override_field = 0;
    *(_QWORD *)&dataDesc_470[20].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_470[20].flatOffset[1] = 0;
  }
  CColorCorrection::m_DataMap.dataNumFields = 20;
  CColorCorrection::m_DataMap.dataDesc = &dataDesc_470[1];
  return &CColorCorrection::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100F9B90
// Name: struct datamap_t __near * DataMapInit<class CTargetCDAudioRep>(class CTargetCDAudioRep __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CTargetCDAudioRep>()
{
  if ( (_S2_68 & 1) == 0 )
  {
    _S2_68 |= 1u;
    nameHolder_126.m_pszBase = "CTargetCDAudioRep";
    nameHolder_126.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_126.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_126.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_126.m_Names.m_Size = 0;
    nameHolder_126.m_Names.m_pElements = nullptr;
    nameHolder_126.m_nLenBase = 17;
    atexit(func: DataMapInit_CTargetCDAudioRep__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CTargetCDAudioRep::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CTargetCDAudioRep::m_DataMap.dataNumFields = 2;
  CTargetCDAudioRep::m_DataMap.dataDesc = &dataDesc_121[1];
  return &CTargetCDAudioRep::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100F9C10
// Name: struct datamap_t __near * DataMapInit<class CTargetChangeGravity>(class CTargetChangeGravity __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CTargetChangeGravity>()
{
  if ( (_S3_38 & 1) == 0 )
  {
    _S3_38 |= 1u;
    nameHolder_127.m_pszBase = "CTargetChangeGravity";
    nameHolder_127.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_127.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_127.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_127.m_Names.m_Size = 0;
    nameHolder_127.m_Names.m_pElements = nullptr;
    nameHolder_127.m_nLenBase = 20;
    atexit(func: DataMapInit_CTargetChangeGravity__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CTargetChangeGravity::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CTargetChangeGravity::m_DataMap.dataNumFields = 4;
  CTargetChangeGravity::m_DataMap.dataDesc = &dataDesc_122[1];
  return &CTargetChangeGravity::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100FA280
// Name: struct datamap_t __near * DataMapInit<class CRagdollMagnet>(class CRagdollMagnet __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CRagdollMagnet>()
{
  if ( (_S2_69 & 1) == 0 )
  {
    _S2_69 |= 1u;
    nameHolder_128.m_pszBase = "CRagdollMagnet";
    nameHolder_128.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_128.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_128.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_128.m_Names.m_Size = 0;
    nameHolder_128.m_Names.m_pElements = nullptr;
    nameHolder_128.m_nLenBase = 14;
    atexit(func: DataMapInit_CRagdollMagnet__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CRagdollMagnet::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CRagdollMagnet::m_DataMap.dataNumFields = 6;
  CRagdollMagnet::m_DataMap.dataDesc = &dataDesc_123[1];
  return &CRagdollMagnet::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10105FE0
// Name: class CEnvGunfire __near * _CreateEntityTemplate<class CEnvGunfire>(class CEnvGunfire __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CEnvGunfire *__cdecl _CreateEntityTemplate<CEnvGunfire>(CEnvGunfire *newEnt, const char *className)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x3A4u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CEnvGunfire::`vftable';
    v3[1].m_Network.m_TimerEvent.m_flUpdateInterval = NAN;
    v3[1].m_Network.m_TimerEvent.m_pEventMgr = (CTimedEventMgr *)1065353216;
    LOBYTE(v3[1].m_Network.m_TimerEvent.m_flNextEventTime) = 0;
    v3->PostConstructor(this: v3, a2: className);
    return (CEnvGunfire *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10107490
// Name: class CRotorWashShooter __near * _CreateEntityTemplate<class CRotorWashShooter>(class CRotorWashShooter __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRotorWashShooter *__cdecl _CreateEntityTemplate<CRotorWashShooter>(CRotorWashShooter *newEnt, const char *className)
{
  CBaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x3B4u);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3[231] = 1065353216;
    v3[232] = &IRotorWashShooter::`vftable';
    *v3 = &CRotorWashShooter::`vftable'{for `CEnvShooter'};
    v3[232] = &CRotorWashShooter::`vftable'{for `IRotorWashShooter'};
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CRotorWashShooter *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10107500
// Name: class CEnvWind __near * _CreateEntityTemplate<class CEnvWind>(class CEnvWind __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CEnvWind *__cdecl _CreateEntityTemplate<CEnvWind>(CEnvWind *newEnt, const char *className)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x590u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3->__vftable = (CBaseEntity_vtbl *)&CEnvWind::`vftable';
    CEnvWindShared::CEnvWindShared(this: (CEnvWindShared *)&v3[1]);
    v3[1].__vftable = (CBaseEntity_vtbl *)&CEnvWind::NetworkVar_m_EnvWindShared::`vftable';
    v3->PostConstructor(this: v3, a2: className);
    return (CEnvWind *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10108690
// Name: struct datamap_t __near * DataMapInit<class CBubbling>(class CBubbling __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CBubbling>()
{
  if ( (_S2_73 & 1) == 0 )
  {
    _S2_73 |= 1u;
    nameHolder_132.m_pszBase = "CBubbling";
    nameHolder_132.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_132.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_132.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_132.m_Names.m_Size = 0;
    nameHolder_132.m_Names.m_pElements = nullptr;
    nameHolder_132.m_nLenBase = 9;
    atexit(func: DataMapInit_CBubbling__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CBubbling::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S2_73 & 2) == 0 )
  {
    _S2_73 |= 2u;
    dataDesc_127[5].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_132,
                                  pszIdentifier: "FizzThink");
    dataDesc_127[5].fieldSize = 1;
    *(_QWORD *)&dataDesc_127[5].td = 0;
    *(_QWORD *)&dataDesc_127[5].override_field = 0;
    *(_QWORD *)&dataDesc_127[5].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_127[5].flatOffset[1] = 0;
    dataDesc_127[5].flags = 32;
    dataDesc_127[6].fieldSize = 1;
    *(_QWORD *)&dataDesc_127[6].td = 0;
    *(_QWORD *)&dataDesc_127[6].override_field = 0;
    *(_QWORD *)&dataDesc_127[6].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_127[6].flatOffset[1] = 0;
    dataDesc_127[6].flags = 8;
    *(_QWORD *)&dataDesc_127[7].td = 0;
    *(_QWORD *)&dataDesc_127[7].override_field = 0;
    *(_QWORD *)&dataDesc_127[7].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_127[7].flatOffset[1] = 0;
    dataDesc_127[7].fieldSize = 1;
    dataDesc_127[7].flags = 8;
    dataDesc_127[8].fieldSize = 1;
    *(_QWORD *)&dataDesc_127[8].td = 0;
    *(_QWORD *)&dataDesc_127[8].override_field = 0;
    *(_QWORD *)&dataDesc_127[8].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_127[8].flatOffset[1] = 0;
    dataDesc_127[5].fieldOffset = 0;
    dataDesc_127[5].externalName = nullptr;
    dataDesc_127[5].pSaveRestoreOps = nullptr;
    dataDesc_127[5].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CBubbling::FizzThink;
    dataDesc_127[6].fieldType = FIELD_VOID;
    dataDesc_127[6].fieldName = "InputActivate";
    dataDesc_127[6].fieldOffset = 0;
    dataDesc_127[6].externalName = "Activate";
    dataDesc_127[6].pSaveRestoreOps = nullptr;
    dataDesc_127[6].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CBubbling::InputActivate;
    dataDesc_127[7].fieldType = FIELD_VOID;
    dataDesc_127[7].fieldName = "InputDeactivate";
    dataDesc_127[7].fieldOffset = 0;
    dataDesc_127[7].externalName = "Deactivate";
    dataDesc_127[7].pSaveRestoreOps = nullptr;
    dataDesc_127[7].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CBubbling::InputDeactivate;
    dataDesc_127[8].fieldType = FIELD_VOID;
    dataDesc_127[8].fieldName = "InputToggle";
    dataDesc_127[8].fieldOffset = 0;
    dataDesc_127[8].flags = 8;
    dataDesc_127[8].externalName = "Toggle";
    dataDesc_127[8].pSaveRestoreOps = nullptr;
    dataDesc_127[8].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CBubbling::InputToggle;
    dataDesc_127[9].fieldType = FIELD_INTEGER;
    dataDesc_127[9].fieldName = "InputSetCurrent";
    dataDesc_127[9].fieldOffset = 0;
    *(_DWORD *)&dataDesc_127[9].fieldSize = 524289;
    dataDesc_127[9].externalName = "SetCurrent";
    dataDesc_127[9].pSaveRestoreOps = nullptr;
    dataDesc_127[9].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CBubbling::InputSetCurrent;
    *(_QWORD *)&dataDesc_127[9].td = 0;
    *(_QWORD *)&dataDesc_127[9].override_field = 0;
    *(_QWORD *)&dataDesc_127[9].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_127[9].flatOffset[1] = 0;
    dataDesc_127[10].fieldType = FIELD_INTEGER;
    dataDesc_127[10].fieldName = "InputSetDensity";
    dataDesc_127[10].fieldOffset = 0;
    *(_QWORD *)&dataDesc_127[10].td = 0;
    *(_QWORD *)&dataDesc_127[10].override_field = 0;
    *(_QWORD *)&dataDesc_127[10].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_127[10].flatOffset[1] = 0;
    dataDesc_127[10].fieldSize = 1;
    dataDesc_127[10].flags = 8;
    dataDesc_127[10].externalName = "SetDensity";
    dataDesc_127[10].pSaveRestoreOps = nullptr;
    dataDesc_127[10].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CBubbling::InputSetDensity;
    dataDesc_127[11].fieldType = FIELD_INTEGER;
    dataDesc_127[11].fieldName = "InputSetFrequency";
    dataDesc_127[11].fieldOffset = 0;
    *(_DWORD *)&dataDesc_127[11].fieldSize = 524289;
    dataDesc_127[11].externalName = "SetFrequency";
    dataDesc_127[11].pSaveRestoreOps = nullptr;
    dataDesc_127[11].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CBubbling::InputSetFrequency;
    *(_QWORD *)&dataDesc_127[11].td = 0;
    *(_QWORD *)&dataDesc_127[11].override_field = 0;
    *(_QWORD *)&dataDesc_127[11].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_127[11].flatOffset[1] = 0;
  }
  CBubbling::m_DataMap.dataNumFields = 11;
  CBubbling::m_DataMap.dataDesc = &dataDesc_127[1];
  return &CBubbling::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101089F0
// Name: struct datamap_t __near * DataMapInit<class CEnvTracer>(class CEnvTracer __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CEnvTracer>()
{
  if ( (_S3_41 & 1) == 0 )
  {
    _S3_41 |= 1u;
    nameHolder_133.m_pszBase = "CEnvTracer";
    nameHolder_133.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_133.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_133.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_133.m_Names.m_Size = 0;
    nameHolder_133.m_Names.m_pElements = nullptr;
    nameHolder_133.m_nLenBase = 10;
    atexit(func: DataMapInit_CEnvTracer__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CEnvTracer::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S3_41 & 2) == 0 )
  {
    _S3_41 |= 2u;
    dataDesc_128[3].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_133,
                                  pszIdentifier: "TracerThink");
    dataDesc_128[3].fieldOffset = 0;
    *(_DWORD *)&dataDesc_128[3].fieldSize = 2097153;
    dataDesc_128[3].externalName = nullptr;
    dataDesc_128[3].pSaveRestoreOps = nullptr;
    dataDesc_128[3].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CEnvTracer::TracerThink;
    *(_QWORD *)&dataDesc_128[3].td = 0;
    *(_QWORD *)&dataDesc_128[3].override_field = 0;
    *(_QWORD *)&dataDesc_128[3].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_128[3].flatOffset[1] = 0;
  }
  CEnvTracer::m_DataMap.dataNumFields = 3;
  CEnvTracer::m_DataMap.dataDesc = &dataDesc_128[1];
  return &CEnvTracer::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10108AE0
// Name: struct datamap_t __near * DataMapInit<class CEnvShooter>(class CEnvShooter __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CEnvShooter>()
{
  if ( (_S5_13 & 1) == 0 )
  {
    _S5_13 |= 1u;
    nameHolder_134.m_pszBase = "CEnvShooter";
    nameHolder_134.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_134.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_134.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_134.m_Names.m_Size = 0;
    nameHolder_134.m_Names.m_pElements = nullptr;
    nameHolder_134.m_nLenBase = 11;
    atexit(func: DataMapInit_CEnvShooter__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CEnvShooter::m_DataMap.baseMap = &CGibShooter::m_DataMap;
  CEnvShooter::m_DataMap.dataNumFields = 3;
  CEnvShooter::m_DataMap.dataDesc = &dataDesc_129[1];
  return &CEnvShooter::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10108B60
// Name: struct datamap_t __near * DataMapInit<class CRotorWashShooter>(class CRotorWashShooter __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CRotorWashShooter>()
{
  if ( (_S6_10 & 1) == 0 )
  {
    _S6_10 |= 1u;
    nameHolder_135.m_pszBase = "CRotorWashShooter";
    nameHolder_135.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_135.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_135.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_135.m_Names.m_Size = 0;
    nameHolder_135.m_Names.m_pElements = nullptr;
    nameHolder_135.m_nLenBase = 17;
    atexit(func: DataMapInit_CRotorWashShooter__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CRotorWashShooter::m_DataMap.baseMap = &CEnvShooter::m_DataMap;
  CRotorWashShooter::m_DataMap.dataNumFields = 4;
  CRotorWashShooter::m_DataMap.dataDesc = &dataDesc_130[1];
  return &CRotorWashShooter::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1010BB40
// Name: struct datamap_t __near * DataMapInit<class CEntityDissolve>(class CEntityDissolve __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CEntityDissolve>()
{
  char *Name; // eax

  if ( (_S2_74 & 1) == 0 )
  {
    _S2_74 |= 1u;
    nameHolder_151.m_pszBase = "CEntityDissolve";
    nameHolder_151.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_151.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_151.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_151.m_Names.m_Size = 0;
    nameHolder_151.m_Names.m_pElements = nullptr;
    nameHolder_151.m_nLenBase = 15;
    atexit(func: DataMapInit_CEntityDissolve__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CEntityDissolve::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S2_74 & 2) == 0 )
  {
    _S2_74 |= 2u;
    dataDesc_143[11].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_151,
                                   pszIdentifier: "DissolveThink");
    dataDesc_143[11].fieldOffset = 0;
    *(_DWORD *)&dataDesc_143[11].fieldSize = 2097153;
    dataDesc_143[11].externalName = nullptr;
    dataDesc_143[11].pSaveRestoreOps = nullptr;
    dataDesc_143[11].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CEntityDissolve::DissolveThink;
    *(_QWORD *)&dataDesc_143[11].td = 0;
    *(_QWORD *)&dataDesc_143[11].override_field = 0;
    *(_QWORD *)&dataDesc_143[11].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_143[11].flatOffset[1] = 0;
    dataDesc_143[12].fieldType = FIELD_VOID;
    Name = CDatadescGeneratedNameHolder::GenerateName(this: &nameHolder_151, pszIdentifier: "ElectrocuteThink");
    *(_QWORD *)&dataDesc_143[12].td = 0;
    *(_QWORD *)&dataDesc_143[12].override_field = 0;
    *(_QWORD *)&dataDesc_143[12].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_143[12].flatOffset[1] = 0;
    dataDesc_143[12].fieldName = Name;
    dataDesc_143[12].fieldOffset = 0;
    *(_DWORD *)&dataDesc_143[12].fieldSize = 2097153;
    dataDesc_143[12].externalName = nullptr;
    dataDesc_143[12].pSaveRestoreOps = nullptr;
    dataDesc_143[12].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CEntityDissolve::ElectrocuteThink;
    dataDesc_143[13].fieldType = FIELD_STRING;
    dataDesc_143[13].fieldName = "InputDissolve";
    dataDesc_143[13].fieldOffset = 0;
    *(_DWORD *)&dataDesc_143[13].fieldSize = 524289;
    dataDesc_143[13].externalName = "Dissolve";
    dataDesc_143[13].pSaveRestoreOps = nullptr;
    dataDesc_143[13].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CEntityDissolve::InputDissolve;
    *(_QWORD *)&dataDesc_143[13].td = 0;
    *(_QWORD *)&dataDesc_143[13].override_field = 0;
    *(_QWORD *)&dataDesc_143[13].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_143[13].flatOffset[1] = 0;
  }
  CEntityDissolve::m_DataMap.dataNumFields = 13;
  CEntityDissolve::m_DataMap.dataDesc = &dataDesc_143[1];
  return &CEntityDissolve::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1010D420
// Name: struct datamap_t __near * DataMapInit<class CEntityFreezing>(class CEntityFreezing __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CEntityFreezing>()
{
  if ( (_S2_76 & 1) == 0 )
  {
    _S2_76 |= 1u;
    nameHolder_154.m_pszBase = "CEntityFreezing";
    nameHolder_154.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_154.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_154.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_154.m_Names.m_Size = 0;
    nameHolder_154.m_Names.m_pElements = nullptr;
    nameHolder_154.m_nLenBase = 15;
    atexit(func: DataMapInit_CEntityFreezing__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CEntityFreezing::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CEntityFreezing::m_DataMap.dataNumFields = 5;
  CEntityFreezing::m_DataMap.dataDesc = &dataDesc_146[1];
  return &CEntityFreezing::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101107D0
// Name: struct datamap_t __near * DataMapInit<class CEntityParticleTrail>(class CEntityParticleTrail __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CEntityParticleTrail>()
{
  if ( (_S2_77 & 1) == 0 )
  {
    _S2_77 |= 1u;
    nameHolder_155.m_pszBase = "CEntityParticleTrail";
    nameHolder_155.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_155.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_155.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_155.m_Names.m_Size = 0;
    nameHolder_155.m_Names.m_pElements = nullptr;
    nameHolder_155.m_nLenBase = 20;
    atexit(func: DataMapInit_CEntityParticleTrail__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CEntityParticleTrail::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CEntityParticleTrail::m_DataMap.dataNumFields = 3;
  CEntityParticleTrail::m_DataMap.dataDesc = &dataDesc_147[1];
  return &CEntityParticleTrail::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10114640
// Name: struct datamap_t __near * DataMapInit<class CEnvEntityMaker>(class CEnvEntityMaker __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CEnvEntityMaker>()
{
  if ( (_S2_84 & 1) == 0 )
  {
    _S2_84 |= 1u;
    nameHolder_161.m_pszBase = "CEnvEntityMaker";
    nameHolder_161.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_161.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_161.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_161.m_Names.m_Size = 0;
    nameHolder_161.m_Names.m_pElements = nullptr;
    nameHolder_161.m_nLenBase = 15;
    atexit(func: DataMapInit_CEnvEntityMaker__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CEnvEntityMaker::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S2_84 & 2) == 0 )
  {
    _S2_84 |= 2u;
    dataDesc_152[10].fieldSize = 1;
    *(_QWORD *)&dataDesc_152[9].inputFunc = 0;
    *(_QWORD *)&dataDesc_152[9].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_152[9].override_count = 0;
    *(_QWORD *)dataDesc_152[9].flatOffset = 0;
    dataDesc_152[10].flags = 22;
    dataDesc_152[12].fieldType = FIELD_STRING;
    *(_QWORD *)&dataDesc_152[10].inputFunc = 0;
    *(_QWORD *)&dataDesc_152[10].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_152[10].override_count = 0;
    *(_QWORD *)dataDesc_152[10].flatOffset = 0;
    dataDesc_152[9].pSaveRestoreOps = eventFuncs;
    dataDesc_152[10].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_152[11].td = 0;
    *(_QWORD *)&dataDesc_152[11].override_field = 0;
    *(_QWORD *)&dataDesc_152[11].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_152[11].flatOffset[1] = 0;
    dataDesc_152[12].flags = 8;
    *(_DWORD *)&dataDesc_152[9].flatGroup = 0;
    dataDesc_152[10].fieldType = FIELD_CUSTOM;
    dataDesc_152[10].fieldName = "m_pOutputOnFailedSpawn";
    dataDesc_152[10].fieldOffset = 948;
    dataDesc_152[10].externalName = "OnEntityFailedSpawn";
    *(_DWORD *)&dataDesc_152[10].flatGroup = 0;
    dataDesc_152[11].fieldType = FIELD_VOID;
    dataDesc_152[11].fieldName = "InputForceSpawn";
    dataDesc_152[11].fieldOffset = 0;
    dataDesc_152[11].fieldSize = 1;
    dataDesc_152[11].flags = 8;
    dataDesc_152[11].externalName = "ForceSpawn";
    dataDesc_152[11].pSaveRestoreOps = nullptr;
    dataDesc_152[11].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CEnvEntityMaker::InputForceSpawn;
    dataDesc_152[12].fieldName = "InputForceSpawnAtEntityOrigin";
    dataDesc_152[12].fieldOffset = 0;
    dataDesc_152[12].fieldSize = 1;
    dataDesc_152[12].externalName = "ForceSpawnAtEntityOrigin";
    dataDesc_152[12].pSaveRestoreOps = nullptr;
    dataDesc_152[12].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CEnvEntityMaker::InputForceSpawnAtEntityOrigin;
    *(_QWORD *)&dataDesc_152[12].td = 0;
    *(_QWORD *)&dataDesc_152[12].override_field = 0;
    *(_QWORD *)&dataDesc_152[12].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_152[12].flatOffset[1] = 0;
    dataDesc_152[13].fieldType = FIELD_VOID;
    dataDesc_152[13].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_161,
                                   pszIdentifier: "CheckSpawnThink");
    dataDesc_152[13].fieldOffset = 0;
    *(_DWORD *)&dataDesc_152[13].fieldSize = 2097153;
    dataDesc_152[13].externalName = nullptr;
    dataDesc_152[13].pSaveRestoreOps = nullptr;
    dataDesc_152[13].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CEnvEntityMaker::CheckSpawnThink;
    *(_QWORD *)&dataDesc_152[13].td = 0;
    *(_QWORD *)&dataDesc_152[13].override_field = 0;
    *(_QWORD *)&dataDesc_152[13].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_152[13].flatOffset[1] = 0;
  }
  CEnvEntityMaker::m_DataMap.dataNumFields = 13;
  CEnvEntityMaker::m_DataMap.dataDesc = &dataDesc_152[1];
  return &CEnvEntityMaker::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10115120
// Name: struct datamap_t __near * DataMapInit<class CEnvInstructorHint>(class CEnvInstructorHint __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CEnvInstructorHint>()
{
  if ( (_S2_85 & 1) == 0 )
  {
    _S2_85 |= 1u;
    nameHolder_162.m_pszBase = "CEnvInstructorHint";
    nameHolder_162.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_162.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_162.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_162.m_Names.m_Size = 0;
    nameHolder_162.m_Names.m_pElements = nullptr;
    nameHolder_162.m_nLenBase = 18;
    atexit(func: DataMapInit_CEnvInstructorHint__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CEnvInstructorHint::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CEnvInstructorHint::m_DataMap.dataNumFields = 22;
  CEnvInstructorHint::m_DataMap.dataDesc = &dataDesc_153[1];
  return &CEnvInstructorHint::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101151A0
// Name: struct datamap_t __near * DataMapInit<class CInfoInstructorHintTarget>(class CInfoInstructorHintTarget __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CInfoInstructorHintTarget>()
{
  if ( (_S3_49 & 1) == 0 )
  {
    _S3_49 |= 1u;
    nameHolder_163.m_pszBase = "CInfoInstructorHintTarget";
    nameHolder_163.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_163.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_163.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_163.m_Names.m_Size = 0;
    nameHolder_163.m_Names.m_pElements = nullptr;
    nameHolder_163.m_nLenBase = 25;
    atexit(func: DataMapInit_CInfoInstructorHintTarget__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CInfoInstructorHintTarget::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CInfoInstructorHintTarget::m_DataMap.dataNumFields = 1;
  CInfoInstructorHintTarget::m_DataMap.dataDesc = dataDesc_476;
  return &CInfoInstructorHintTarget::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10115B50
// Name: struct datamap_t __near * DataMapInit<class CEnvPlayerSurfaceTrigger>(class CEnvPlayerSurfaceTrigger __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CEnvPlayerSurfaceTrigger>()
{
  if ( (_S2_87 & 1) == 0 )
  {
    _S2_87 |= 1u;
    nameHolder_165.m_pszBase = "CEnvPlayerSurfaceTrigger";
    nameHolder_165.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_165.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_165.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_165.m_Names.m_Size = 0;
    nameHolder_165.m_Names.m_pElements = nullptr;
    nameHolder_165.m_nLenBase = 24;
    atexit(func: DataMapInit_CEnvPlayerSurfaceTrigger__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CEnvPlayerSurfaceTrigger::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S2_87 & 2) == 0 )
  {
    _S2_87 |= 2u;
    dataDesc_155[4].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_165,
                                  pszIdentifier: "UpdateMaterialThink");
    dataDesc_155[4].fieldSize = 1;
    *(_QWORD *)&dataDesc_155[4].td = 0;
    *(_QWORD *)&dataDesc_155[4].override_field = 0;
    *(_QWORD *)&dataDesc_155[4].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_155[4].flatOffset[1] = 0;
    dataDesc_155[5].fieldSize = 1;
    *(_QWORD *)&dataDesc_155[5].td = 0;
    *(_QWORD *)&dataDesc_155[5].override_field = 0;
    *(_QWORD *)&dataDesc_155[5].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_155[5].flatOffset[1] = 0;
    dataDesc_155[4].flags = 32;
    dataDesc_155[5].flags = 8;
    *(_QWORD *)&dataDesc_155[6].td = 0;
    *(_QWORD *)&dataDesc_155[6].override_field = 0;
    *(_QWORD *)&dataDesc_155[6].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_155[6].flatOffset[1] = 0;
    dataDesc_155[6].fieldSize = 1;
    dataDesc_155[6].flags = 8;
    dataDesc_155[7].fieldSize = 1;
    *(_QWORD *)&dataDesc_155[7].inputFunc = 0;
    *(_QWORD *)&dataDesc_155[7].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_155[7].override_count = 0;
    *(_QWORD *)dataDesc_155[7].flatOffset = 0;
    dataDesc_155[4].fieldOffset = 0;
    dataDesc_155[4].externalName = nullptr;
    dataDesc_155[4].pSaveRestoreOps = nullptr;
    dataDesc_155[4].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CEnvPlayerSurfaceTrigger::UpdateMaterialThink;
    dataDesc_155[5].fieldType = FIELD_VOID;
    dataDesc_155[5].fieldName = "InputDisable";
    dataDesc_155[5].fieldOffset = 0;
    dataDesc_155[5].externalName = "Disable";
    dataDesc_155[5].pSaveRestoreOps = nullptr;
    dataDesc_155[5].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CInfoGameEventProxy::InputDisable;
    dataDesc_155[6].fieldType = FIELD_VOID;
    dataDesc_155[6].fieldName = "InputEnable";
    dataDesc_155[6].fieldOffset = 0;
    dataDesc_155[6].externalName = "Enable";
    dataDesc_155[6].pSaveRestoreOps = nullptr;
    dataDesc_155[6].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CInfoGameEventProxy::InputEnable;
    dataDesc_155[7].fieldType = FIELD_CUSTOM;
    dataDesc_155[7].fieldName = "m_OnSurfaceChangedToTarget";
    dataDesc_155[7].fieldOffset = 864;
    dataDesc_155[7].flags = 22;
    dataDesc_155[7].externalName = "OnSurfaceChangedToTarget";
    dataDesc_155[7].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_155[7].flatGroup = 0;
    dataDesc_155[8].fieldType = FIELD_CUSTOM;
    dataDesc_155[8].fieldName = "m_OnSurfaceChangedFromTarget";
    dataDesc_155[8].fieldOffset = 888;
    *(_DWORD *)&dataDesc_155[8].fieldSize = 1441793;
    dataDesc_155[8].externalName = "OnSurfaceChangedFromTarget";
    dataDesc_155[8].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_155[8].inputFunc = 0;
    *(_QWORD *)&dataDesc_155[8].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_155[8].override_count = 0;
    *(_QWORD *)dataDesc_155[8].flatOffset = 0;
    *(_DWORD *)&dataDesc_155[8].flatGroup = 0;
  }
  CEnvPlayerSurfaceTrigger::m_DataMap.dataNumFields = 8;
  CEnvPlayerSurfaceTrigger::m_DataMap.dataDesc = &dataDesc_155[1];
  return &CEnvPlayerSurfaceTrigger::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10117C90
// Name: struct datamap_t __near * DataMapInit<class CEnvScreenOverlay>(class CEnvScreenOverlay __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CEnvScreenOverlay>()
{
  if ( (_S2_89 & 1) == 0 )
  {
    _S2_89 |= 1u;
    nameHolder_167.m_pszBase = "CEnvScreenOverlay";
    nameHolder_167.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_167.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_167.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_167.m_Names.m_Size = 0;
    nameHolder_167.m_Names.m_pElements = nullptr;
    nameHolder_167.m_nLenBase = 17;
    atexit(func: DataMapInit_CEnvScreenOverlay__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CEnvScreenOverlay::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S2_89 & 2) == 0 )
  {
    _S2_89 |= 2u;
    dataDesc_157[1].flags = 6;
    dataDesc_157[2].fieldSize = 1;
    dataDesc_157[2].flags = 6;
    dataDesc_157[3].fieldSize = 1;
    dataDesc_157[3].flags = 6;
    dataDesc_157[4].fieldSize = 1;
    *(_QWORD *)dataDesc_157[1].flatOffset = 0;
    dataDesc_157[4].flags = 6;
    *(_QWORD *)dataDesc_157[2].flatOffset = 0;
    dataDesc_157[1].fieldSize = 1;
    dataDesc_157[5].fieldSize = 1;
    *(_QWORD *)dataDesc_157[3].flatOffset = 0;
    dataDesc_157[1].fieldOffset = 852;
    dataDesc_157[1].externalName = "OverlayName1";
    dataDesc_157[1].pSaveRestoreOps = nullptr;
    dataDesc_157[1].inputFunc = nullptr;
    dataDesc_157[1].td = nullptr;
    dataDesc_157[1].fieldSizeInBytes = 4;
    dataDesc_157[1].override_field = nullptr;
    dataDesc_157[1].override_count = 0;
    dataDesc_157[1].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_157[1].flatGroup = 0;
    dataDesc_157[2].fieldType = FIELD_STRING;
    dataDesc_157[2].fieldName = "m_iszOverlayNames[1]";
    dataDesc_157[2].fieldOffset = 856;
    dataDesc_157[2].externalName = "OverlayName2";
    dataDesc_157[2].pSaveRestoreOps = nullptr;
    dataDesc_157[2].inputFunc = nullptr;
    dataDesc_157[2].td = nullptr;
    dataDesc_157[2].fieldSizeInBytes = 4;
    dataDesc_157[2].override_field = nullptr;
    dataDesc_157[2].override_count = 0;
    dataDesc_157[2].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_157[2].flatGroup = 0;
    dataDesc_157[3].fieldType = FIELD_STRING;
    dataDesc_157[3].fieldName = "m_iszOverlayNames[2]";
    dataDesc_157[3].fieldOffset = 860;
    dataDesc_157[3].externalName = "OverlayName3";
    dataDesc_157[3].pSaveRestoreOps = nullptr;
    dataDesc_157[3].inputFunc = nullptr;
    dataDesc_157[3].td = nullptr;
    dataDesc_157[3].fieldSizeInBytes = 4;
    dataDesc_157[3].override_field = nullptr;
    dataDesc_157[3].override_count = 0;
    dataDesc_157[3].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_157[3].flatGroup = 0;
    dataDesc_157[4].fieldType = FIELD_STRING;
    dataDesc_157[4].fieldName = "m_iszOverlayNames[3]";
    dataDesc_157[4].fieldOffset = 864;
    dataDesc_157[4].externalName = "OverlayName4";
    dataDesc_157[4].pSaveRestoreOps = nullptr;
    dataDesc_157[4].inputFunc = nullptr;
    dataDesc_157[4].td = nullptr;
    dataDesc_157[4].fieldSizeInBytes = 4;
    dataDesc_157[4].override_field = nullptr;
    dataDesc_157[4].override_count = 0;
    dataDesc_157[4].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_157[4].flatOffset = 0;
    *(_DWORD *)&dataDesc_157[4].flatGroup = 0;
    dataDesc_157[5].fieldType = FIELD_STRING;
    dataDesc_157[5].fieldName = "m_iszOverlayNames[4]";
    dataDesc_157[5].fieldOffset = 868;
    dataDesc_157[5].flags = 6;
    dataDesc_157[6].fieldSize = 1;
    dataDesc_157[6].flags = 6;
    dataDesc_157[7].fieldSize = 1;
    dataDesc_157[7].flags = 6;
    dataDesc_157[8].fieldSize = 1;
    *(_QWORD *)dataDesc_157[5].flatOffset = 0;
    *(_QWORD *)dataDesc_157[6].flatOffset = 0;
    dataDesc_157[8].flags = 6;
    *(_QWORD *)dataDesc_157[7].flatOffset = 0;
    dataDesc_157[9].fieldSize = 1;
    *(_QWORD *)dataDesc_157[8].flatOffset = 0;
    dataDesc_157[5].externalName = "OverlayName5";
    dataDesc_157[5].pSaveRestoreOps = nullptr;
    dataDesc_157[5].inputFunc = nullptr;
    dataDesc_157[5].td = nullptr;
    dataDesc_157[5].fieldSizeInBytes = 4;
    dataDesc_157[5].override_field = nullptr;
    dataDesc_157[5].override_count = 0;
    dataDesc_157[5].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_157[5].flatGroup = 0;
    dataDesc_157[6].fieldType = FIELD_STRING;
    dataDesc_157[6].fieldName = "m_iszOverlayNames[5]";
    dataDesc_157[6].fieldOffset = 872;
    dataDesc_157[6].externalName = "OverlayName6";
    dataDesc_157[6].pSaveRestoreOps = nullptr;
    dataDesc_157[6].inputFunc = nullptr;
    dataDesc_157[6].td = nullptr;
    dataDesc_157[6].fieldSizeInBytes = 4;
    dataDesc_157[6].override_field = nullptr;
    dataDesc_157[6].override_count = 0;
    dataDesc_157[6].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_157[6].flatGroup = 0;
    dataDesc_157[7].fieldType = FIELD_STRING;
    dataDesc_157[7].fieldName = "m_iszOverlayNames[6]";
    dataDesc_157[7].fieldOffset = 876;
    dataDesc_157[7].externalName = "OverlayName7";
    dataDesc_157[7].pSaveRestoreOps = nullptr;
    dataDesc_157[7].inputFunc = nullptr;
    dataDesc_157[7].td = nullptr;
    dataDesc_157[7].fieldSizeInBytes = 4;
    dataDesc_157[7].override_field = nullptr;
    dataDesc_157[7].override_count = 0;
    dataDesc_157[7].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_157[7].flatGroup = 0;
    dataDesc_157[8].fieldType = FIELD_STRING;
    dataDesc_157[8].fieldName = "m_iszOverlayNames[7]";
    dataDesc_157[8].fieldOffset = 880;
    dataDesc_157[8].externalName = "OverlayName8";
    dataDesc_157[8].pSaveRestoreOps = nullptr;
    dataDesc_157[8].inputFunc = nullptr;
    dataDesc_157[8].td = nullptr;
    dataDesc_157[8].fieldSizeInBytes = 4;
    dataDesc_157[8].override_field = nullptr;
    dataDesc_157[8].override_count = 0;
    dataDesc_157[8].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_157[8].flatGroup = 0;
    dataDesc_157[9].fieldType = FIELD_STRING;
    dataDesc_157[9].fieldName = "m_iszOverlayNames[8]";
    dataDesc_157[9].fieldOffset = 884;
    dataDesc_157[9].flags = 6;
    dataDesc_157[9].externalName = "OverlayName9";
    dataDesc_157[9].pSaveRestoreOps = nullptr;
    dataDesc_157[9].inputFunc = nullptr;
    dataDesc_157[9].td = nullptr;
    dataDesc_157[9].fieldSizeInBytes = 4;
    dataDesc_157[9].override_field = nullptr;
    dataDesc_157[9].override_count = 0;
    dataDesc_157[9].fieldTolerance = 0.0;
    dataDesc_157[10].fieldSize = 1;
    dataDesc_157[10].flags = 6;
    dataDesc_157[11].fieldSize = 1;
    dataDesc_157[11].flags = 6;
    dataDesc_157[12].fieldSize = 1;
    dataDesc_157[12].flags = 6;
    *(_QWORD *)dataDesc_157[9].flatOffset = 0;
    dataDesc_157[13].fieldSize = 1;
    *(_QWORD *)dataDesc_157[10].flatOffset = 0;
    dataDesc_157[13].flags = 6;
    *(_QWORD *)dataDesc_157[11].flatOffset = 0;
    dataDesc_157[14].fieldSize = 1;
    *(_QWORD *)dataDesc_157[12].flatOffset = 0;
    *(_DWORD *)&dataDesc_157[9].flatGroup = 0;
    dataDesc_157[10].fieldType = FIELD_STRING;
    dataDesc_157[10].fieldName = "m_iszOverlayNames[9]";
    dataDesc_157[10].fieldOffset = 888;
    dataDesc_157[10].externalName = "OverlayName10";
    dataDesc_157[10].pSaveRestoreOps = nullptr;
    dataDesc_157[10].inputFunc = nullptr;
    dataDesc_157[10].td = nullptr;
    dataDesc_157[10].fieldSizeInBytes = 4;
    dataDesc_157[10].override_field = nullptr;
    dataDesc_157[10].override_count = 0;
    dataDesc_157[10].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_157[10].flatGroup = 0;
    dataDesc_157[11].fieldType = FIELD_FLOAT;
    dataDesc_157[11].fieldName = "m_flOverlayTimes[0]";
    dataDesc_157[11].fieldOffset = 892;
    dataDesc_157[11].externalName = "OverlayTime1";
    dataDesc_157[11].pSaveRestoreOps = nullptr;
    dataDesc_157[11].inputFunc = nullptr;
    dataDesc_157[11].td = nullptr;
    dataDesc_157[11].fieldSizeInBytes = 4;
    dataDesc_157[11].override_field = nullptr;
    dataDesc_157[11].override_count = 0;
    dataDesc_157[11].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_157[11].flatGroup = 0;
    dataDesc_157[12].fieldType = FIELD_FLOAT;
    dataDesc_157[12].fieldName = "m_flOverlayTimes[1]";
    dataDesc_157[12].fieldOffset = 896;
    dataDesc_157[12].externalName = "OverlayTime2";
    dataDesc_157[12].pSaveRestoreOps = nullptr;
    dataDesc_157[12].inputFunc = nullptr;
    dataDesc_157[12].td = nullptr;
    dataDesc_157[12].fieldSizeInBytes = 4;
    dataDesc_157[12].override_field = nullptr;
    dataDesc_157[12].override_count = 0;
    dataDesc_157[12].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_157[12].flatGroup = 0;
    dataDesc_157[13].fieldType = FIELD_FLOAT;
    dataDesc_157[13].fieldName = "m_flOverlayTimes[2]";
    dataDesc_157[13].fieldOffset = 900;
    dataDesc_157[13].externalName = "OverlayTime3";
    dataDesc_157[13].pSaveRestoreOps = nullptr;
    dataDesc_157[13].inputFunc = nullptr;
    dataDesc_157[13].td = nullptr;
    dataDesc_157[13].fieldSizeInBytes = 4;
    dataDesc_157[13].override_field = nullptr;
    dataDesc_157[13].override_count = 0;
    dataDesc_157[13].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_157[13].flatOffset = 0;
    *(_DWORD *)&dataDesc_157[13].flatGroup = 0;
    dataDesc_157[14].fieldType = FIELD_FLOAT;
    dataDesc_157[14].fieldName = "m_flOverlayTimes[3]";
    dataDesc_157[14].fieldOffset = 904;
    dataDesc_157[14].flags = 6;
    dataDesc_157[15].fieldSize = 1;
    dataDesc_157[15].flags = 6;
    dataDesc_157[16].fieldSize = 1;
    dataDesc_157[16].flags = 6;
    dataDesc_157[17].fieldSize = 1;
    *(_QWORD *)dataDesc_157[14].flatOffset = 0;
    *(_QWORD *)dataDesc_157[15].flatOffset = 0;
    dataDesc_157[17].flags = 6;
    *(_QWORD *)dataDesc_157[16].flatOffset = 0;
    dataDesc_157[18].fieldSize = 1;
    *(_QWORD *)dataDesc_157[17].flatOffset = 0;
    dataDesc_157[14].externalName = "OverlayTime4";
    dataDesc_157[14].pSaveRestoreOps = nullptr;
    dataDesc_157[14].inputFunc = nullptr;
    dataDesc_157[14].td = nullptr;
    dataDesc_157[14].fieldSizeInBytes = 4;
    dataDesc_157[14].override_field = nullptr;
    dataDesc_157[14].override_count = 0;
    dataDesc_157[14].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_157[14].flatGroup = 0;
    dataDesc_157[15].fieldType = FIELD_FLOAT;
    dataDesc_157[15].fieldName = "m_flOverlayTimes[4]";
    dataDesc_157[15].fieldOffset = 908;
    dataDesc_157[15].externalName = "OverlayTime5";
    dataDesc_157[15].pSaveRestoreOps = nullptr;
    dataDesc_157[15].inputFunc = nullptr;
    dataDesc_157[15].td = nullptr;
    dataDesc_157[15].fieldSizeInBytes = 4;
    dataDesc_157[15].override_field = nullptr;
    dataDesc_157[15].override_count = 0;
    dataDesc_157[15].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_157[15].flatGroup = 0;
    dataDesc_157[16].fieldType = FIELD_FLOAT;
    dataDesc_157[16].fieldName = "m_flOverlayTimes[5]";
    dataDesc_157[16].fieldOffset = 912;
    dataDesc_157[16].externalName = "OverlayTime6";
    dataDesc_157[16].pSaveRestoreOps = nullptr;
    dataDesc_157[16].inputFunc = nullptr;
    dataDesc_157[16].td = nullptr;
    dataDesc_157[16].fieldSizeInBytes = 4;
    dataDesc_157[16].override_field = nullptr;
    dataDesc_157[16].override_count = 0;
    dataDesc_157[16].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_157[16].flatGroup = 0;
    dataDesc_157[17].fieldType = FIELD_FLOAT;
    dataDesc_157[17].fieldName = "m_flOverlayTimes[6]";
    dataDesc_157[17].fieldOffset = 916;
    dataDesc_157[17].externalName = "OverlayTime7";
    dataDesc_157[17].pSaveRestoreOps = nullptr;
    dataDesc_157[17].inputFunc = nullptr;
    dataDesc_157[17].td = nullptr;
    dataDesc_157[17].fieldSizeInBytes = 4;
    dataDesc_157[17].override_field = nullptr;
    dataDesc_157[17].override_count = 0;
    dataDesc_157[17].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_157[17].flatGroup = 0;
    dataDesc_157[18].fieldType = FIELD_FLOAT;
    dataDesc_157[18].fieldName = "m_flOverlayTimes[7]";
    dataDesc_157[18].fieldOffset = 920;
    dataDesc_157[18].flags = 6;
    dataDesc_157[18].externalName = "OverlayTime8";
    dataDesc_157[18].pSaveRestoreOps = nullptr;
    dataDesc_157[18].inputFunc = nullptr;
    dataDesc_157[18].td = nullptr;
    dataDesc_157[18].fieldSizeInBytes = 4;
    dataDesc_157[18].override_field = nullptr;
    dataDesc_157[18].override_count = 0;
    dataDesc_157[18].fieldTolerance = 0.0;
    dataDesc_157[19].fieldSize = 1;
    *(_QWORD *)dataDesc_157[18].flatOffset = 0;
    dataDesc_157[19].flags = 6;
    dataDesc_157[21].fieldSize = 1;
    *(_QWORD *)dataDesc_157[19].flatOffset = 0;
    dataDesc_157[20].fieldSize = 1;
    dataDesc_157[21].flags = 2;
    *(_QWORD *)dataDesc_157[20].flatOffset = 0;
    dataDesc_157[19].fieldSizeInBytes = 4;
    dataDesc_157[20].flags = 6;
    dataDesc_157[20].fieldSizeInBytes = 4;
    dataDesc_157[21].fieldSizeInBytes = 4;
    dataDesc_157[22].fieldSize = 1;
    dataDesc_157[22].fieldSizeInBytes = 4;
    *(_QWORD *)dataDesc_157[21].flatOffset = 0;
    *(_DWORD *)&dataDesc_157[18].flatGroup = 0;
    dataDesc_157[19].fieldType = FIELD_FLOAT;
    dataDesc_157[19].fieldName = "m_flOverlayTimes[8]";
    dataDesc_157[19].fieldOffset = 924;
    dataDesc_157[19].externalName = "OverlayTime9";
    dataDesc_157[19].pSaveRestoreOps = nullptr;
    dataDesc_157[19].inputFunc = nullptr;
    dataDesc_157[19].td = nullptr;
    dataDesc_157[19].override_field = nullptr;
    dataDesc_157[19].override_count = 0;
    dataDesc_157[19].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_157[19].flatGroup = 0;
    dataDesc_157[20].fieldType = FIELD_FLOAT;
    dataDesc_157[20].fieldName = "m_flOverlayTimes[9]";
    dataDesc_157[20].fieldOffset = 928;
    dataDesc_157[20].externalName = "OverlayTime10";
    dataDesc_157[20].pSaveRestoreOps = nullptr;
    dataDesc_157[20].inputFunc = nullptr;
    dataDesc_157[20].td = nullptr;
    dataDesc_157[20].override_field = nullptr;
    dataDesc_157[20].override_count = 0;
    dataDesc_157[20].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_157[20].flatGroup = 0;
    dataDesc_157[21].fieldType = FIELD_INTEGER;
    dataDesc_157[21].fieldName = "m_iDesiredOverlay";
    dataDesc_157[21].fieldOffset = 936;
    dataDesc_157[21].externalName = nullptr;
    dataDesc_157[21].pSaveRestoreOps = nullptr;
    dataDesc_157[21].inputFunc = nullptr;
    dataDesc_157[21].td = nullptr;
    dataDesc_157[21].override_field = nullptr;
    dataDesc_157[21].override_count = 0;
    dataDesc_157[21].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_157[21].flatGroup = 0;
    dataDesc_157[22].fieldType = FIELD_TIME;
    dataDesc_157[22].fieldName = "m_flStartTime";
    dataDesc_157[22].fieldOffset = 932;
    dataDesc_157[22].flags = 2;
    dataDesc_157[22].externalName = nullptr;
    dataDesc_157[22].pSaveRestoreOps = nullptr;
    dataDesc_157[22].inputFunc = nullptr;
    dataDesc_157[22].td = nullptr;
    dataDesc_157[22].override_field = nullptr;
    dataDesc_157[22].override_count = 0;
    dataDesc_157[22].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_157[22].flatOffset = 0;
    *(_DWORD *)&dataDesc_157[22].flatGroup = 0;
    dataDesc_157[23].fieldType = FIELD_BOOLEAN;
    dataDesc_157[23].fieldName = "m_bIsActive";
    dataDesc_157[23].fieldOffset = 940;
    dataDesc_157[23].fieldSize = 1;
    dataDesc_157[23].flags = 2;
    dataDesc_157[23].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_157[23].flatOffset = 0;
    *(_QWORD *)&dataDesc_157[24].td = 0;
    *(_QWORD *)&dataDesc_157[24].override_field = 0;
    *(_QWORD *)&dataDesc_157[24].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_157[24].flatOffset[1] = 0;
    *(_QWORD *)&dataDesc_157[25].td = 0;
    *(_QWORD *)&dataDesc_157[25].override_field = 0;
    *(_QWORD *)&dataDesc_157[25].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_157[25].flatOffset[1] = 0;
    dataDesc_157[23].externalName = nullptr;
    dataDesc_157[23].pSaveRestoreOps = nullptr;
    dataDesc_157[23].inputFunc = nullptr;
    dataDesc_157[23].td = nullptr;
    dataDesc_157[23].fieldSizeInBytes = 1;
    dataDesc_157[23].override_field = nullptr;
    dataDesc_157[23].override_count = 0;
    *(_DWORD *)&dataDesc_157[23].flatGroup = 0;
    dataDesc_157[24].fieldType = FIELD_VOID;
    dataDesc_157[24].fieldName = "InputStartOverlay";
    dataDesc_157[24].fieldOffset = 0;
    dataDesc_157[24].fieldSize = 1;
    dataDesc_157[24].flags = 8;
    dataDesc_157[24].externalName = "StartOverlays";
    dataDesc_157[24].pSaveRestoreOps = nullptr;
    dataDesc_157[24].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CEnvScreenOverlay::InputStartOverlay;
    dataDesc_157[25].fieldType = FIELD_VOID;
    dataDesc_157[25].fieldName = "InputStopOverlay";
    dataDesc_157[25].fieldOffset = 0;
    dataDesc_157[25].fieldSize = 1;
    dataDesc_157[25].flags = 8;
    dataDesc_157[25].externalName = "StopOverlays";
    dataDesc_157[25].pSaveRestoreOps = nullptr;
    dataDesc_157[25].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CEnvScreenOverlay::InputStopOverlay;
    dataDesc_157[26].fieldType = FIELD_INTEGER;
    dataDesc_157[26].fieldName = "InputSwitchOverlay";
    dataDesc_157[26].fieldOffset = 0;
    *(_DWORD *)&dataDesc_157[26].fieldSize = 524289;
    dataDesc_157[26].externalName = "SwitchOverlay";
    dataDesc_157[26].pSaveRestoreOps = nullptr;
    dataDesc_157[26].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CEnvScreenOverlay::InputSwitchOverlay;
    *(_QWORD *)&dataDesc_157[26].td = 0;
    *(_QWORD *)&dataDesc_157[26].override_field = 0;
    *(_QWORD *)&dataDesc_157[26].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_157[26].flatOffset[1] = 0;
  }
  CEnvScreenOverlay::m_DataMap.dataNumFields = 26;
  CEnvScreenOverlay::m_DataMap.dataDesc = &dataDesc_157[1];
  return &CEnvScreenOverlay::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101188E0
// Name: struct datamap_t __near * DataMapInit<class CEnvScreenEffect>(class CEnvScreenEffect __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CEnvScreenEffect>()
{
  if ( (_S4_25 & 1) == 0 )
  {
    _S4_25 |= 1u;
    nameHolder_168.m_pszBase = "CEnvScreenEffect";
    nameHolder_168.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_168.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_168.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_168.m_Names.m_Size = 0;
    nameHolder_168.m_Names.m_pElements = nullptr;
    nameHolder_168.m_nLenBase = 16;
    atexit(func: DataMapInit_CEnvScreenEffect__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CEnvScreenEffect::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CEnvScreenEffect::m_DataMap.dataNumFields = 4;
  CEnvScreenEffect::m_DataMap.dataDesc = &dataDesc_158[1];
  return &CEnvScreenEffect::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10119D00
// Name: struct datamap_t __near * DataMapInit<class CEnvTonemapController>(class CEnvTonemapController __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CEnvTonemapController>()
{
  if ( (_S2_91 & 1) == 0 )
  {
    _S2_91 |= 1u;
    nameHolder_170.m_pszBase = "CEnvTonemapController";
    nameHolder_170.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_170.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_170.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_170.m_Names.m_Size = 0;
    nameHolder_170.m_Names.m_pElements = nullptr;
    nameHolder_170.m_nLenBase = 21;
    atexit(func: DataMapInit_CEnvTonemapController__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CEnvTonemapController::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S2_91 & 2) == 0 )
  {
    _S2_91 |= 2u;
    dataDesc_160[17].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_170,
                                   pszIdentifier: "UpdateTonemapScaleBlend");
    dataDesc_160[17].fieldSize = 1;
    *(_QWORD *)&dataDesc_160[17].td = 0;
    *(_QWORD *)&dataDesc_160[17].override_field = 0;
    *(_QWORD *)&dataDesc_160[17].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_160[17].flatOffset[1] = 0;
    dataDesc_160[17].flags = 32;
    dataDesc_160[18].fieldSize = 1;
    *(_QWORD *)&dataDesc_160[18].td = 0;
    *(_QWORD *)&dataDesc_160[18].override_field = 0;
    *(_QWORD *)&dataDesc_160[18].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_160[18].flatOffset[1] = 0;
    dataDesc_160[18].flags = 8;
    dataDesc_160[19].fieldSize = 1;
    *(_QWORD *)&dataDesc_160[19].td = 0;
    *(_QWORD *)&dataDesc_160[19].override_field = 0;
    *(_QWORD *)&dataDesc_160[19].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_160[19].flatOffset[1] = 0;
    dataDesc_160[19].flags = 8;
    dataDesc_160[20].fieldSize = 1;
    *(_QWORD *)&dataDesc_160[20].td = 0;
    *(_QWORD *)&dataDesc_160[20].override_field = 0;
    *(_QWORD *)&dataDesc_160[20].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_160[20].flatOffset[1] = 0;
    dataDesc_160[17].fieldOffset = 0;
    dataDesc_160[17].externalName = nullptr;
    dataDesc_160[17].pSaveRestoreOps = nullptr;
    dataDesc_160[17].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CEnvTonemapController::UpdateTonemapScaleBlend;
    dataDesc_160[18].fieldType = FIELD_FLOAT;
    dataDesc_160[18].fieldName = "InputSetTonemapScale";
    dataDesc_160[18].fieldOffset = 0;
    dataDesc_160[18].externalName = "SetTonemapScale";
    dataDesc_160[18].pSaveRestoreOps = nullptr;
    dataDesc_160[18].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CEnvTonemapController::InputSetTonemapScale;
    dataDesc_160[19].fieldType = FIELD_STRING;
    dataDesc_160[19].fieldName = "InputBlendTonemapScale";
    dataDesc_160[19].fieldOffset = 0;
    dataDesc_160[19].externalName = "BlendTonemapScale";
    dataDesc_160[19].pSaveRestoreOps = nullptr;
    dataDesc_160[19].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CEnvTonemapController::InputBlendTonemapScale;
    dataDesc_160[20].fieldType = FIELD_FLOAT;
    dataDesc_160[20].fieldName = "InputSetTonemapRate";
    dataDesc_160[20].fieldOffset = 0;
    dataDesc_160[20].flags = 8;
    dataDesc_160[20].externalName = "SetTonemapRate";
    dataDesc_160[20].pSaveRestoreOps = nullptr;
    dataDesc_160[20].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CEnvTonemapController::InputSetTonemapRate;
    dataDesc_160[21].fieldType = FIELD_FLOAT;
    dataDesc_160[21].fieldName = "InputSetAutoExposureMin";
    dataDesc_160[21].fieldOffset = 0;
    dataDesc_160[21].fieldSize = 1;
    dataDesc_160[21].flags = 8;
    dataDesc_160[21].externalName = "SetAutoExposureMin";
    dataDesc_160[21].pSaveRestoreOps = nullptr;
    dataDesc_160[21].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CEnvTonemapController::InputSetAutoExposureMin;
    *(_QWORD *)&dataDesc_160[21].td = 0;
    *(_QWORD *)&dataDesc_160[21].override_field = 0;
    *(_QWORD *)&dataDesc_160[21].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_160[21].flatOffset[1] = 0;
    dataDesc_160[22].fieldType = FIELD_FLOAT;
    dataDesc_160[22].fieldName = "InputSetAutoExposureMax";
    dataDesc_160[22].fieldOffset = 0;
    dataDesc_160[22].fieldSize = 1;
    dataDesc_160[22].flags = 8;
    *(_QWORD *)&dataDesc_160[22].td = 0;
    *(_QWORD *)&dataDesc_160[22].override_field = 0;
    *(_QWORD *)&dataDesc_160[22].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_160[22].flatOffset[1] = 0;
    dataDesc_160[23].fieldSize = 1;
    dataDesc_160[23].flags = 8;
    *(_QWORD *)&dataDesc_160[23].td = 0;
    *(_QWORD *)&dataDesc_160[23].override_field = 0;
    *(_QWORD *)&dataDesc_160[23].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_160[23].flatOffset[1] = 0;
    dataDesc_160[24].fieldSize = 1;
    dataDesc_160[24].flags = 8;
    *(_QWORD *)&dataDesc_160[24].td = 0;
    *(_QWORD *)&dataDesc_160[24].override_field = 0;
    *(_QWORD *)&dataDesc_160[24].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_160[24].flatOffset[1] = 0;
    dataDesc_160[25].fieldSize = 1;
    dataDesc_160[25].flags = 8;
    dataDesc_160[26].fieldSize = 1;
    *(_QWORD *)&dataDesc_160[25].td = 0;
    *(_QWORD *)&dataDesc_160[25].override_field = 0;
    *(_QWORD *)&dataDesc_160[25].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_160[25].flatOffset[1] = 0;
    dataDesc_160[22].externalName = "SetAutoExposureMax";
    dataDesc_160[22].pSaveRestoreOps = nullptr;
    dataDesc_160[22].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CEnvTonemapController::InputSetAutoExposureMax;
    dataDesc_160[23].fieldType = FIELD_VOID;
    dataDesc_160[23].fieldName = "InputUseDefaultAutoExposure";
    dataDesc_160[23].fieldOffset = 0;
    dataDesc_160[23].externalName = "UseDefaultAutoExposure";
    dataDesc_160[23].pSaveRestoreOps = nullptr;
    dataDesc_160[23].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CEnvTonemapController::InputUseDefaultAutoExposure;
    dataDesc_160[24].fieldType = FIELD_VOID;
    dataDesc_160[24].fieldName = "InputUseDefaultBloomScale";
    dataDesc_160[24].fieldOffset = 0;
    dataDesc_160[24].externalName = "UseDefaultBloomScale";
    dataDesc_160[24].pSaveRestoreOps = nullptr;
    dataDesc_160[24].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CEnvTonemapController::InputUseDefaultBloomScale;
    dataDesc_160[25].fieldType = FIELD_FLOAT;
    dataDesc_160[25].fieldName = "InputSetBloomScale";
    dataDesc_160[25].fieldOffset = 0;
    dataDesc_160[25].externalName = "SetBloomScale";
    dataDesc_160[25].pSaveRestoreOps = nullptr;
    dataDesc_160[25].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CEnvTonemapController::InputSetBloomScale;
    dataDesc_160[26].fieldType = FIELD_FLOAT;
    dataDesc_160[26].fieldName = "InputSetBloomScaleRange";
    dataDesc_160[26].fieldOffset = 0;
    dataDesc_160[26].flags = 8;
    dataDesc_160[26].externalName = "SetBloomScaleRange";
    dataDesc_160[26].pSaveRestoreOps = nullptr;
    dataDesc_160[26].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CEnvTonemapController::InputSetBloomScaleRange;
    *(_QWORD *)&dataDesc_160[26].td = 0;
    *(_QWORD *)&dataDesc_160[26].override_field = 0;
    *(_QWORD *)&dataDesc_160[26].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_160[26].flatOffset[1] = 0;
    dataDesc_160[27].fieldType = FIELD_FLOAT;
    dataDesc_160[27].fieldName = "InputSetBloomExponent";
    dataDesc_160[27].fieldOffset = 0;
    dataDesc_160[27].fieldSize = 1;
    dataDesc_160[27].flags = 8;
    dataDesc_160[27].externalName = "SetBloomExponent";
    dataDesc_160[27].pSaveRestoreOps = nullptr;
    *(_QWORD *)&dataDesc_160[27].td = 0;
    *(_QWORD *)&dataDesc_160[27].override_field = 0;
    *(_QWORD *)&dataDesc_160[27].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_160[27].flatOffset[1] = 0;
    *(_QWORD *)&dataDesc_160[28].td = 0;
    *(_QWORD *)&dataDesc_160[28].override_field = 0;
    *(_QWORD *)&dataDesc_160[28].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_160[28].flatOffset[1] = 0;
    dataDesc_160[28].fieldSize = 1;
    *(_QWORD *)&dataDesc_160[29].td = 0;
    *(_QWORD *)&dataDesc_160[29].override_field = 0;
    *(_QWORD *)&dataDesc_160[29].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_160[29].flatOffset[1] = 0;
    dataDesc_160[28].flags = 8;
    dataDesc_160[29].fieldSize = 1;
    *(_QWORD *)&dataDesc_160[30].td = 0;
    *(_QWORD *)&dataDesc_160[30].override_field = 0;
    *(_QWORD *)&dataDesc_160[30].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_160[30].flatOffset[1] = 0;
    dataDesc_160[27].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CEnvTonemapController::InputSetBloomExponent;
    dataDesc_160[28].fieldType = FIELD_FLOAT;
    dataDesc_160[28].fieldName = "InputSetBloomSaturation";
    dataDesc_160[28].fieldOffset = 0;
    dataDesc_160[28].externalName = "SetBloomSaturation";
    dataDesc_160[28].pSaveRestoreOps = nullptr;
    dataDesc_160[28].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CEnvTonemapController::InputSetBloomSaturation;
    dataDesc_160[29].fieldType = FIELD_FLOAT;
    dataDesc_160[29].fieldName = "InputSetTonemapPercentTarget";
    dataDesc_160[29].fieldOffset = 0;
    dataDesc_160[29].flags = 8;
    dataDesc_160[29].externalName = "SetTonemapPercentTarget";
    dataDesc_160[29].pSaveRestoreOps = nullptr;
    dataDesc_160[29].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CEnvTonemapController::InputSetTonemapPercentTarget;
    dataDesc_160[30].fieldType = FIELD_FLOAT;
    dataDesc_160[30].fieldName = "InputSetTonemapPercentBrightPixels";
    dataDesc_160[30].fieldOffset = 0;
    *(_DWORD *)&dataDesc_160[30].fieldSize = 524289;
    dataDesc_160[30].externalName = "SetTonemapPercentBrightPixels";
    dataDesc_160[30].pSaveRestoreOps = nullptr;
    dataDesc_160[30].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CEnvTonemapController::InputSetTonemapPercentBrightPixels;
    dataDesc_160[31].fieldType = FIELD_FLOAT;
    dataDesc_160[31].fieldName = "InputSetTonemapMinAvgLum";
    dataDesc_160[31].fieldOffset = 0;
    *(_DWORD *)&dataDesc_160[31].fieldSize = 524289;
    dataDesc_160[31].externalName = "SetTonemapMinAvgLum";
    dataDesc_160[31].pSaveRestoreOps = nullptr;
    dataDesc_160[31].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CEnvTonemapController::InputSetTonemapMinAvgLum;
    *(_QWORD *)&dataDesc_160[31].td = 0;
    *(_QWORD *)&dataDesc_160[31].override_field = 0;
    *(_QWORD *)&dataDesc_160[31].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_160[31].flatOffset[1] = 0;
  }
  CEnvTonemapController::m_DataMap.dataNumFields = 31;
  CEnvTonemapController::m_DataMap.dataDesc = &dataDesc_160[1];
  return &CEnvTonemapController::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1011A390
// Name: struct datamap_t __near * DataMapInit<class CTonemapTrigger>(class CTonemapTrigger __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CTonemapTrigger>()
{
  if ( (_S4_26 & 1) == 0 )
  {
    _S4_26 |= 1u;
    nameHolder_171.m_pszBase = "CTonemapTrigger";
    nameHolder_171.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_171.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_171.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_171.m_Names.m_Size = 0;
    nameHolder_171.m_Names.m_pElements = nullptr;
    nameHolder_171.m_nLenBase = 15;
    atexit(func: DataMapInit_CTonemapTrigger__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CTonemapTrigger::m_DataMap.baseMap = &CBaseTrigger::m_DataMap;
  CTonemapTrigger::m_DataMap.dataNumFields = 1;
  CTonemapTrigger::m_DataMap.dataDesc = &dataDesc_161[1];
  return &CTonemapTrigger::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1011AE40
// Name: struct datamap_t __near * DataMapInit<class CEnvZoom>(class CEnvZoom __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CEnvZoom>()
{
  if ( (_S2_92 & 1) == 0 )
  {
    _S2_92 |= 1u;
    nameHolder_172.m_pszBase = "CEnvZoom";
    nameHolder_172.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_172.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_172.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_172.m_Names.m_Size = 0;
    nameHolder_172.m_Names.m_pElements = nullptr;
    nameHolder_172.m_nLenBase = 8;
    atexit(func: DataMapInit_CEnvZoom__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CEnvZoom::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CEnvZoom::m_DataMap.dataNumFields = 4;
  CEnvZoom::m_DataMap.dataDesc = &dataDesc_162[1];
  return &CEnvZoom::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1011D300
// Name: struct datamap_t __near * DataMapInit<class CEnvFade>(class CEnvFade __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CEnvFade>()
{
  if ( (_S2_94 & 1) == 0 )
  {
    _S2_94 |= 1u;
    nameHolder_174.m_pszBase = "CEnvFade";
    nameHolder_174.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_174.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_174.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_174.m_Names.m_Size = 0;
    nameHolder_174.m_Names.m_pElements = nullptr;
    nameHolder_174.m_nLenBase = 8;
    atexit(func: DataMapInit_CEnvFade__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CEnvFade::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S2_94 & 2) == 0 )
  {
    _S2_94 |= 2u;
    dataDesc_164[6].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_164[6].inputFunc = 0;
    *(_QWORD *)&dataDesc_164[6].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_164[6].override_count = 0;
    *(_QWORD *)dataDesc_164[6].flatOffset = 0;
    *(_DWORD *)&dataDesc_164[6].flatGroup = 0;
  }
  CEnvFade::m_DataMap.dataNumFields = 6;
  CEnvFade::m_DataMap.dataDesc = &dataDesc_164[1];
  return &CEnvFade::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1011D5A0
// Name: struct datamap_t __near * DataMapInit<class CEnvHudHint>(class CEnvHudHint __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CEnvHudHint>()
{
  if ( (_S2_95 & 1) == 0 )
  {
    _S2_95 |= 1u;
    nameHolder_175.m_pszBase = "CEnvHudHint";
    nameHolder_175.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_175.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_175.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_175.m_Names.m_Size = 0;
    nameHolder_175.m_Names.m_pElements = nullptr;
    nameHolder_175.m_nLenBase = 11;
    atexit(func: DataMapInit_CEnvHudHint__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CEnvHudHint::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CEnvHudHint::m_DataMap.dataNumFields = 3;
  CEnvHudHint::m_DataMap.dataDesc = &dataDesc_165[1];
  return &CEnvHudHint::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10120B20
// Name: struct datamap_t __near * DataMapInit<class CPhysicsShake>(class CPhysicsShake __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CPhysicsShake>()
{
  if ( (_S2_99 & 1) == 0 )
  {
    _S2_99 |= 1u;
    nameHolder_181.m_pszBase = "CPhysicsShake";
    nameHolder_181.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_181.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_181.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_181.m_Names.m_Size = 0;
    nameHolder_181.m_Names.m_pElements = nullptr;
    nameHolder_181.m_nLenBase = 13;
    atexit(func: DataMapInit_CPhysicsShake__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CPhysicsShake::m_DataMap.baseMap = nullptr;
  CPhysicsShake::m_DataMap.dataNumFields = 1;
  CPhysicsShake::m_DataMap.dataDesc = &dataDesc_171[1];
  return &CPhysicsShake::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10120BA0
// Name: struct datamap_t __near * DataMapInit<class CEnvShake>(class CEnvShake __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CEnvShake>()
{
  ISaveRestoreOps *PhysObjSaveRestoreOps; // eax

  if ( (_S3_55 & 1) == 0 )
  {
    _S3_55 |= 1u;
    nameHolder_182.m_pszBase = "CEnvShake";
    nameHolder_182.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_182.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_182.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_182.m_Names.m_Size = 0;
    nameHolder_182.m_Names.m_pElements = nullptr;
    nameHolder_182.m_nLenBase = 9;
    atexit(func: DataMapInit_CEnvShake__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CEnvShake::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S3_55 & 2) == 0 )
  {
    _S3_55 |= 2u;
    PhysObjSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSMOTIONCONTROLLER);
    *(_QWORD *)&dataDesc_172[9].td = 0;
    *(_QWORD *)&dataDesc_172[9].override_field = 0;
    *(_QWORD *)&dataDesc_172[9].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_172[9].flatOffset[1] = 0;
    dataDesc_172[9].pSaveRestoreOps = PhysObjSaveRestoreOps;
    dataDesc_172[10].fieldTolerance = 0.0;
    dataDesc_172[10].fieldSize = 1;
    *(_QWORD *)dataDesc_172[10].flatOffset = 0;
    dataDesc_172[10].flags = 2;
    dataDesc_172[11].fieldSize = 1;
    *(_QWORD *)&dataDesc_172[11].td = 0;
    *(_QWORD *)&dataDesc_172[11].override_field = 0;
    *(_QWORD *)&dataDesc_172[11].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_172[11].flatOffset[1] = 0;
    dataDesc_172[11].flags = 8;
    dataDesc_172[12].fieldSize = 1;
    *(_QWORD *)&dataDesc_172[12].td = 0;
    *(_QWORD *)&dataDesc_172[12].override_field = 0;
    *(_QWORD *)&dataDesc_172[12].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_172[12].flatOffset[1] = 0;
    dataDesc_172[9].inputFunc = nullptr;
    dataDesc_172[10].fieldType = FIELD_EMBEDDED;
    dataDesc_172[10].fieldName = "m_shakeCallback";
    dataDesc_172[10].fieldOffset = 896;
    dataDesc_172[10].externalName = nullptr;
    dataDesc_172[10].pSaveRestoreOps = nullptr;
    dataDesc_172[10].inputFunc = nullptr;
    dataDesc_172[10].td = &CPhysicsShake::m_DataMap;
    dataDesc_172[10].fieldSizeInBytes = 16;
    dataDesc_172[10].override_field = nullptr;
    dataDesc_172[10].override_count = 0;
    *(_DWORD *)&dataDesc_172[10].flatGroup = 0;
    dataDesc_172[11].fieldType = FIELD_VOID;
    dataDesc_172[11].fieldName = "InputStartShake";
    dataDesc_172[11].fieldOffset = 0;
    dataDesc_172[11].externalName = "StartShake";
    dataDesc_172[11].pSaveRestoreOps = nullptr;
    dataDesc_172[11].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CEnvShake::InputStartShake;
    dataDesc_172[12].fieldType = FIELD_VOID;
    dataDesc_172[12].fieldName = "InputStopShake";
    dataDesc_172[12].fieldOffset = 0;
    dataDesc_172[12].flags = 8;
    dataDesc_172[12].externalName = "StopShake";
    dataDesc_172[12].pSaveRestoreOps = nullptr;
    dataDesc_172[12].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CEnvShake::InputStopShake;
    dataDesc_172[13].fieldType = FIELD_FLOAT;
    dataDesc_172[13].fieldName = "InputAmplitude";
    dataDesc_172[13].fieldOffset = 0;
    *(_DWORD *)&dataDesc_172[13].fieldSize = 524289;
    dataDesc_172[13].externalName = "Amplitude";
    dataDesc_172[13].pSaveRestoreOps = nullptr;
    dataDesc_172[13].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CEnvShake::InputAmplitude;
    *(_QWORD *)&dataDesc_172[13].td = 0;
    *(_QWORD *)&dataDesc_172[13].override_field = 0;
    *(_QWORD *)&dataDesc_172[13].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_172[13].flatOffset[1] = 0;
    dataDesc_172[14].fieldType = FIELD_FLOAT;
    dataDesc_172[14].fieldName = "InputFrequency";
    dataDesc_172[14].fieldOffset = 0;
    *(_DWORD *)&dataDesc_172[14].fieldSize = 524289;
    dataDesc_172[14].externalName = "Frequency";
    dataDesc_172[14].pSaveRestoreOps = nullptr;
    dataDesc_172[14].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CEnvShake::InputFrequency;
    *(_QWORD *)&dataDesc_172[14].td = 0;
    *(_QWORD *)&dataDesc_172[14].override_field = 0;
    *(_QWORD *)&dataDesc_172[14].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_172[14].flatOffset[1] = 0;
  }
  CEnvShake::m_DataMap.dataNumFields = 14;
  CEnvShake::m_DataMap.dataDesc = &dataDesc_172[1];
  return &CEnvShake::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10120E80
// Name: struct datamap_t __near * DataMapInit<class CEnvTilt>(class CEnvTilt __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CEnvTilt>()
{
  if ( (_S4_28 & 1) == 0 )
  {
    _S4_28 |= 1u;
    nameHolder_183.m_pszBase = "CEnvTilt";
    nameHolder_183.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_183.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_183.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_183.m_Names.m_Size = 0;
    nameHolder_183.m_Names.m_pElements = nullptr;
    nameHolder_183.m_nLenBase = 8;
    atexit(func: DataMapInit_CEnvTilt__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CEnvTilt::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CEnvTilt::m_DataMap.dataNumFields = 6;
  CEnvTilt::m_DataMap.dataDesc = &dataDesc_173[1];
  return &CEnvTilt::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10121550
// Name: struct datamap_t __near * DataMapInit<class CEnvSpark>(class CEnvSpark __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CEnvSpark>()
{
  if ( (_S2_100 & 1) == 0 )
  {
    _S2_100 |= 1u;
    nameHolder_184.m_pszBase = "CEnvSpark";
    nameHolder_184.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_184.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_184.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_184.m_Names.m_Size = 0;
    nameHolder_184.m_Names.m_pElements = nullptr;
    nameHolder_184.m_nLenBase = 9;
    atexit(func: DataMapInit_CEnvSpark__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CEnvSpark::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S2_100 & 2) == 0 )
  {
    _S2_100 |= 2u;
    dataDesc_174[5].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_184,
                                  pszIdentifier: "SparkThink");
    dataDesc_174[5].fieldSize = 1;
    *(_QWORD *)&dataDesc_174[5].td = 0;
    *(_QWORD *)&dataDesc_174[5].override_field = 0;
    *(_QWORD *)&dataDesc_174[5].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_174[5].flatOffset[1] = 0;
    dataDesc_174[5].flags = 32;
    dataDesc_174[6].fieldSize = 1;
    *(_QWORD *)&dataDesc_174[6].td = 0;
    *(_QWORD *)&dataDesc_174[6].override_field = 0;
    *(_QWORD *)&dataDesc_174[6].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_174[6].flatOffset[1] = 0;
    dataDesc_174[6].flags = 8;
    dataDesc_174[7].fieldSize = 1;
    *(_QWORD *)&dataDesc_174[7].td = 0;
    *(_QWORD *)&dataDesc_174[7].override_field = 0;
    *(_QWORD *)&dataDesc_174[7].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_174[7].flatOffset[1] = 0;
    dataDesc_174[7].flags = 8;
    dataDesc_174[8].fieldSize = 1;
    *(_QWORD *)&dataDesc_174[8].td = 0;
    *(_QWORD *)&dataDesc_174[8].override_field = 0;
    *(_QWORD *)&dataDesc_174[8].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_174[8].flatOffset[1] = 0;
    dataDesc_174[5].fieldOffset = 0;
    dataDesc_174[5].externalName = nullptr;
    dataDesc_174[5].pSaveRestoreOps = nullptr;
    dataDesc_174[5].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CEnvSpark::SparkThink;
    dataDesc_174[6].fieldType = FIELD_VOID;
    dataDesc_174[6].fieldName = "InputStartSpark";
    dataDesc_174[6].fieldOffset = 0;
    dataDesc_174[6].externalName = "StartSpark";
    dataDesc_174[6].pSaveRestoreOps = nullptr;
    dataDesc_174[6].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CEnvSpark::InputStartSpark;
    dataDesc_174[7].fieldType = FIELD_VOID;
    dataDesc_174[7].fieldName = "InputStopSpark";
    dataDesc_174[7].fieldOffset = 0;
    dataDesc_174[7].externalName = "StopSpark";
    dataDesc_174[7].pSaveRestoreOps = nullptr;
    dataDesc_174[7].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CLogicMeasureMovement::InputDisable;
    dataDesc_174[8].fieldType = FIELD_VOID;
    dataDesc_174[8].fieldName = "InputToggleSpark";
    dataDesc_174[8].fieldOffset = 0;
    dataDesc_174[8].flags = 8;
    dataDesc_174[8].externalName = "ToggleSpark";
    dataDesc_174[8].pSaveRestoreOps = nullptr;
    dataDesc_174[8].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CEnvSpark::InputToggleSpark;
    dataDesc_174[9].fieldType = FIELD_VOID;
    dataDesc_174[9].fieldName = "InputSparkOnce";
    dataDesc_174[9].fieldOffset = 0;
    dataDesc_174[9].fieldSize = 1;
    dataDesc_174[9].flags = 8;
    dataDesc_174[9].externalName = "SparkOnce";
    dataDesc_174[9].pSaveRestoreOps = nullptr;
    dataDesc_174[9].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CEnvSpark::InputSparkOnce;
    *(_QWORD *)&dataDesc_174[9].td = 0;
    *(_QWORD *)&dataDesc_174[9].override_field = 0;
    *(_QWORD *)&dataDesc_174[9].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_174[9].flatOffset[1] = 0;
    dataDesc_174[10].fieldType = FIELD_CUSTOM;
    dataDesc_174[10].fieldName = "m_OnSpark";
    dataDesc_174[10].fieldOffset = 868;
    *(_DWORD *)&dataDesc_174[10].fieldSize = 1441793;
    dataDesc_174[10].externalName = "OnSpark";
    dataDesc_174[10].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_174[10].inputFunc = 0;
    *(_QWORD *)&dataDesc_174[10].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_174[10].override_count = 0;
    *(_QWORD *)dataDesc_174[10].flatOffset = 0;
    *(_DWORD *)&dataDesc_174[10].flatGroup = 0;
  }
  CEnvSpark::m_DataMap.dataNumFields = 10;
  CEnvSpark::m_DataMap.dataDesc = &dataDesc_174[1];
  return &CEnvSpark::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101246A0
// Name: struct datamap_t __near * DataMapInit<class CBaseFilter>(class CBaseFilter __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CBaseFilter>()
{
  if ( (_S2_102 & 1) == 0 )
  {
    _S2_102 |= 1u;
    nameHolder_186.m_pszBase = "CBaseFilter";
    nameHolder_186.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_186.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_186.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_186.m_Names.m_Size = 0;
    nameHolder_186.m_Names.m_pElements = nullptr;
    nameHolder_186.m_nLenBase = 11;
    atexit(func: DataMapInit_CBaseFilter__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CBaseFilter::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S2_102 & 2) == 0 )
  {
    _S2_102 |= 2u;
    *(_QWORD *)&dataDesc_176[3].inputFunc = 0;
    *(_QWORD *)&dataDesc_176[3].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_176[3].override_count = 0;
    *(_QWORD *)dataDesc_176[3].flatOffset = 0;
    dataDesc_176[3].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_176[3].flatGroup = 0;
    dataDesc_176[4].fieldType = FIELD_CUSTOM;
    dataDesc_176[4].fieldName = "m_OnFail";
    dataDesc_176[4].fieldOffset = 880;
    *(_DWORD *)&dataDesc_176[4].fieldSize = 1441793;
    dataDesc_176[4].externalName = "OnFail";
    dataDesc_176[4].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_176[4].inputFunc = 0;
    *(_QWORD *)&dataDesc_176[4].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_176[4].override_count = 0;
    *(_QWORD *)dataDesc_176[4].flatOffset = 0;
    *(_DWORD *)&dataDesc_176[4].flatGroup = 0;
  }
  CBaseFilter::m_DataMap.dataNumFields = 4;
  CBaseFilter::m_DataMap.dataDesc = &dataDesc_176[1];
  return &CBaseFilter::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101247D0
// Name: struct datamap_t __near * DataMapInit<class CFilterMultiple>(class CFilterMultiple __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CFilterMultiple>()
{
  if ( (_S3_56 & 1) == 0 )
  {
    _S3_56 |= 1u;
    nameHolder_187.m_pszBase = "CFilterMultiple";
    nameHolder_187.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_187.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_187.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_187.m_Names.m_Size = 0;
    nameHolder_187.m_Names.m_pElements = nullptr;
    nameHolder_187.m_nLenBase = 15;
    atexit(func: DataMapInit_CFilterMultiple__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CFilterMultiple::m_DataMap.baseMap = &CBaseFilter::m_DataMap;
  CFilterMultiple::m_DataMap.dataNumFields = 12;
  CFilterMultiple::m_DataMap.dataDesc = &dataDesc_177[1];
  return &CFilterMultiple::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10124850
// Name: struct datamap_t __near * DataMapInit<class CFilterName>(class CFilterName __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CFilterName>()
{
  if ( (_S4_29 & 1) == 0 )
  {
    _S4_29 |= 1u;
    nameHolder_188.m_pszBase = "CFilterName";
    nameHolder_188.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_188.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_188.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_188.m_Names.m_Size = 0;
    nameHolder_188.m_Names.m_pElements = nullptr;
    nameHolder_188.m_nLenBase = 11;
    atexit(func: DataMapInit_CFilterName__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CFilterName::m_DataMap.baseMap = &CBaseFilter::m_DataMap;
  CFilterName::m_DataMap.dataNumFields = 1;
  CFilterName::m_DataMap.dataDesc = &dataDesc_178[1];
  return &CFilterName::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101248C0
// Name: struct datamap_t __near * DataMapInit<class CFilterModel>(class CFilterModel __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CFilterModel>()
{
  if ( (_S5_15 & 1) == 0 )
  {
    _S5_15 |= 1u;
    nameHolder_189.m_pszBase = "CFilterModel";
    nameHolder_189.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_189.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_189.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_189.m_Names.m_Size = 0;
    nameHolder_189.m_Names.m_pElements = nullptr;
    nameHolder_189.m_nLenBase = 12;
    atexit(func: DataMapInit_CFilterModel__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CFilterModel::m_DataMap.baseMap = &CBaseFilter::m_DataMap;
  CFilterModel::m_DataMap.dataNumFields = 1;
  CFilterModel::m_DataMap.dataDesc = &dataDesc_179[1];
  return &CFilterModel::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10124930
// Name: struct datamap_t __near * DataMapInit<class CFilterContext>(class CFilterContext __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CFilterContext>()
{
  if ( (_S6_11 & 1) == 0 )
  {
    _S6_11 |= 1u;
    nameHolder_190.m_pszBase = "CFilterContext";
    nameHolder_190.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_190.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_190.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_190.m_Names.m_Size = 0;
    nameHolder_190.m_Names.m_pElements = nullptr;
    nameHolder_190.m_nLenBase = 14;
    atexit(func: DataMapInit_CFilterContext__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CFilterContext::m_DataMap.baseMap = &CBaseFilter::m_DataMap;
  CFilterContext::m_DataMap.dataNumFields = 1;
  CFilterContext::m_DataMap.dataDesc = &dataDesc_180[1];
  return &CFilterContext::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101249A0
// Name: struct datamap_t __near * DataMapInit<class CFilterClass>(class CFilterClass __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CFilterClass>()
{
  if ( (_S7_5 & 1) == 0 )
  {
    _S7_5 |= 1u;
    nameHolder_191.m_pszBase = "CFilterClass";
    nameHolder_191.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_191.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_191.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_191.m_Names.m_Size = 0;
    nameHolder_191.m_Names.m_pElements = nullptr;
    nameHolder_191.m_nLenBase = 12;
    atexit(func: DataMapInit_CFilterClass__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CFilterClass::m_DataMap.baseMap = &CBaseFilter::m_DataMap;
  CFilterClass::m_DataMap.dataNumFields = 1;
  CFilterClass::m_DataMap.dataDesc = &dataDesc_181[1];
  return &CFilterClass::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10124A10
// Name: struct datamap_t __near * DataMapInit<class FilterTeam>(class FilterTeam __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<FilterTeam>()
{
  if ( (_S8_3 & 1) == 0 )
  {
    _S8_3 |= 1u;
    nameHolder_192.m_pszBase = "FilterTeam";
    nameHolder_192.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_192.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_192.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_192.m_Names.m_Size = 0;
    nameHolder_192.m_Names.m_pElements = nullptr;
    nameHolder_192.m_nLenBase = 10;
    atexit(func: DataMapInit_FilterTeam__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  FilterTeam::m_DataMap.baseMap = &CBaseFilter::m_DataMap;
  FilterTeam::m_DataMap.dataNumFields = 1;
  FilterTeam::m_DataMap.dataDesc = &dataDesc_182[1];
  return &FilterTeam::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10124A80
// Name: struct datamap_t __near * DataMapInit<class CFilterMassGreater>(class CFilterMassGreater __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CFilterMassGreater>()
{
  if ( (_S9_2 & 1) == 0 )
  {
    _S9_2 |= 1u;
    nameHolder_193.m_pszBase = "CFilterMassGreater";
    nameHolder_193.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_193.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_193.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_193.m_Names.m_Size = 0;
    nameHolder_193.m_Names.m_pElements = nullptr;
    nameHolder_193.m_nLenBase = 18;
    atexit(func: DataMapInit_CFilterMassGreater__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CFilterMassGreater::m_DataMap.baseMap = &CBaseFilter::m_DataMap;
  CFilterMassGreater::m_DataMap.dataNumFields = 1;
  CFilterMassGreater::m_DataMap.dataDesc = &dataDesc_183[1];
  return &CFilterMassGreater::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10124AF0
// Name: struct datamap_t __near * DataMapInit<class FilterDamageType>(class FilterDamageType __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<FilterDamageType>()
{
  if ( (_S10_1 & 1) == 0 )
  {
    _S10_1 |= 1u;
    nameHolder_194.m_pszBase = "FilterDamageType";
    nameHolder_194.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_194.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_194.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_194.m_Names.m_Size = 0;
    nameHolder_194.m_Names.m_pElements = nullptr;
    nameHolder_194.m_nLenBase = 16;
    atexit(func: DataMapInit_FilterDamageType__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  FilterDamageType::m_DataMap.baseMap = &CBaseFilter::m_DataMap;
  FilterDamageType::m_DataMap.dataNumFields = 1;
  FilterDamageType::m_DataMap.dataDesc = &dataDesc_184[1];
  return &FilterDamageType::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10124B60
// Name: struct datamap_t __near * DataMapInit<class CFilterEnemy>(class CFilterEnemy __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CFilterEnemy>()
{
  if ( (_S11_1 & 1) == 0 )
  {
    _S11_1 |= 1u;
    nameHolder_195.m_pszBase = "CFilterEnemy";
    nameHolder_195.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_195.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_195.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_195.m_Names.m_Size = 0;
    nameHolder_195.m_Names.m_pElements = nullptr;
    nameHolder_195.m_nLenBase = 12;
    atexit(func: DataMapInit_CFilterEnemy__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CFilterEnemy::m_DataMap.baseMap = &CBaseFilter::m_DataMap;
  CFilterEnemy::m_DataMap.dataNumFields = 5;
  CFilterEnemy::m_DataMap.dataDesc = &dataDesc_185[1];
  return &CFilterEnemy::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10127B50
// Name: struct datamap_t __near * DataMapInit<class CBaseFire>(class CBaseFire __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CBaseFire>()
{
  if ( (_S2_104 & 1) == 0 )
  {
    _S2_104 |= 1u;
    nameHolder_199.m_pszBase = "CBaseFire";
    nameHolder_199.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_199.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_199.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_199.m_Names.m_Size = 0;
    nameHolder_199.m_Names.m_pElements = nullptr;
    nameHolder_199.m_nLenBase = 9;
    atexit(func: DataMapInit_CBaseFire__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CBaseFire::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CBaseFire::m_DataMap.dataNumFields = 4;
  CBaseFire::m_DataMap.dataDesc = &dataDesc_189[1];
  return &CBaseFire::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10127BD0
// Name: struct datamap_t __near * DataMapInit<class CFireSmoke>(class CFireSmoke __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CFireSmoke>()
{
  if ( (_S4_31 & 1) == 0 )
  {
    _S4_31 |= 1u;
    nameHolder_200.m_pszBase = "CFireSmoke";
    nameHolder_200.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_200.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_200.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_200.m_Names.m_Size = 0;
    nameHolder_200.m_Names.m_pElements = nullptr;
    nameHolder_200.m_nLenBase = 10;
    atexit(func: DataMapInit_CFireSmoke__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CFireSmoke::m_DataMap.baseMap = &CBaseFire::m_DataMap;
  CFireSmoke::m_DataMap.dataNumFields = 6;
  CFireSmoke::m_DataMap.dataDesc = &dataDesc_190[1];
  return &CFireSmoke::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1012AF30
// Name: struct datamap_t __near * DataMapInit<class CFlexExpresser>(class CFlexExpresser __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CFlexExpresser>()
{
  if ( (_S2_106 & 1) == 0 )
  {
    _S2_106 |= 1u;
    nameHolder_203.m_pszBase = "CFlexExpresser";
    nameHolder_203.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_203.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_203.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_203.m_Names.m_Size = 0;
    nameHolder_203.m_Names.m_pElements = nullptr;
    nameHolder_203.m_nLenBase = 14;
    atexit(func: DataMapInit_CFlexExpresser__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CFlexExpresser::m_DataMap.baseMap = &CFlexCycler::m_DataMap;
  CFlexExpresser::m_DataMap.dataNumFields = 2;
  CFlexExpresser::m_DataMap.dataDesc = &dataDesc_193[1];
  return &CFlexExpresser::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10130DC0
// Name: struct datamap_t __near * DataMapInit<class CAreaPortal>(class CAreaPortal __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CAreaPortal>()
{
  if ( (_S2_111 & 1) == 0 )
  {
    _S2_111 |= 1u;
    nameHolder_208.m_pszBase = "CAreaPortal";
    nameHolder_208.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_208.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_208.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_208.m_Names.m_Size = 0;
    nameHolder_208.m_Names.m_pElements = nullptr;
    nameHolder_208.m_nLenBase = 11;
    atexit(func: DataMapInit_CAreaPortal__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CAreaPortal::m_DataMap.baseMap = &CFuncAreaPortalBase::m_DataMap;
  CAreaPortal::m_DataMap.dataNumFields = 7;
  CAreaPortal::m_DataMap.dataDesc = &dataDesc_198[1];
  return &CAreaPortal::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10131760
// Name: struct datamap_t __near * DataMapInit<class CFuncAreaPortalWindow>(class CFuncAreaPortalWindow __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CFuncAreaPortalWindow>()
{
  if ( (_S3_61 & 1) == 0 )
  {
    _S3_61 |= 1u;
    nameHolder_210.m_pszBase = "CFuncAreaPortalWindow";
    nameHolder_210.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_210.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_210.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_210.m_Names.m_Size = 0;
    nameHolder_210.m_Names.m_pElements = nullptr;
    nameHolder_210.m_nLenBase = 21;
    atexit(func: DataMapInit_CFuncAreaPortalWindow__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CFuncAreaPortalWindow::m_DataMap.baseMap = &CFuncAreaPortalBase::m_DataMap;
  CFuncAreaPortalWindow::m_DataMap.dataNumFields = 7;
  CFuncAreaPortalWindow::m_DataMap.dataDesc = &dataDesc_200[1];
  return &CFuncAreaPortalWindow::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101370C0
// Name: struct datamap_t __near * DataMapInit<class CBreakableSurface>(class CBreakableSurface __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CBreakableSurface>()
{
  if ( (_S3_62 & 1) == 0 )
  {
    _S3_62 |= 1u;
    nameHolder_213.m_pszBase = "CBreakableSurface";
    nameHolder_213.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_213.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_213.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_213.m_Names.m_Size = 0;
    nameHolder_213.m_Names.m_pElements = nullptr;
    nameHolder_213.m_nLenBase = 17;
    atexit(func: DataMapInit_CBreakableSurface__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CBreakableSurface::m_DataMap.baseMap = &CBreakable::m_DataMap;
  if ( (_S3_62 & 2) == 0 )
  {
    _S3_62 |= 2u;
    dataDesc_202[18].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_213,
                                   pszIdentifier: "BreakThink");
    dataDesc_202[18].flags = 32;
    dataDesc_202[18].fieldOffset = 0;
    dataDesc_202[18].fieldSize = 1;
    dataDesc_202[18].externalName = nullptr;
    dataDesc_202[18].pSaveRestoreOps = nullptr;
    dataDesc_202[18].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CBreakableSurface::BreakThink;
    *(_QWORD *)&dataDesc_202[18].td = 0;
    *(_QWORD *)&dataDesc_202[18].override_field = 0;
    *(_QWORD *)&dataDesc_202[18].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_202[18].flatOffset[1] = 0;
    dataDesc_202[19].fieldType = FIELD_VOID;
    dataDesc_202[19].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_213,
                                   pszIdentifier: "SurfaceTouch");
    *(_QWORD *)&dataDesc_202[19].td = 0;
    *(_QWORD *)&dataDesc_202[19].override_field = 0;
    *(_QWORD *)&dataDesc_202[19].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_202[19].flatOffset[1] = 0;
    dataDesc_202[19].fieldOffset = 0;
    dataDesc_202[19].fieldSize = 1;
    dataDesc_202[19].flags = 32;
    dataDesc_202[19].externalName = nullptr;
    dataDesc_202[19].pSaveRestoreOps = nullptr;
    dataDesc_202[19].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CBreakableSurface::SurfaceTouch;
    dataDesc_202[20].fieldType = FIELD_VECTOR;
    dataDesc_202[20].fieldName = "InputShatter";
    dataDesc_202[20].fieldOffset = 0;
    *(_DWORD *)&dataDesc_202[20].fieldSize = 524289;
    dataDesc_202[20].externalName = "Shatter";
    dataDesc_202[20].pSaveRestoreOps = nullptr;
    dataDesc_202[20].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CBreakableSurface::InputShatter;
    *(_QWORD *)&dataDesc_202[20].td = 0;
    *(_QWORD *)&dataDesc_202[20].override_field = 0;
    *(_QWORD *)&dataDesc_202[20].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_202[20].flatOffset[1] = 0;
  }
  CBreakableSurface::m_DataMap.dataNumFields = 20;
  CBreakableSurface::m_DataMap.dataDesc = &dataDesc_202[1];
  return &CBreakableSurface::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10139480
// Name: struct datamap_t __near * DataMapInit<class CFuncInstanceIoProxy>(class CFuncInstanceIoProxy __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CFuncInstanceIoProxy>()
{
  if ( (_S2_117 & 1) == 0 )
  {
    _S2_117 |= 1u;
    nameHolder_216.m_pszBase = "CFuncInstanceIoProxy";
    nameHolder_216.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_216.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_216.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_216.m_Names.m_Size = 0;
    nameHolder_216.m_Names.m_pElements = nullptr;
    nameHolder_216.m_nLenBase = 20;
    atexit(func: DataMapInit_CFuncInstanceIoProxy__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CFuncInstanceIoProxy::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S2_117 & 2) == 0 )
  {
    _S2_117 |= 2u;
    dataDesc_205[32].fieldSize = 1;
    dataDesc_205[32].flags = 22;
    dataDesc_205[33].fieldSize = 1;
    dataDesc_205[33].flags = 22;
    dataDesc_205[34].fieldSize = 1;
    dataDesc_205[34].flags = 22;
    *(_QWORD *)&dataDesc_205[31].inputFunc = 0;
    *(_QWORD *)&dataDesc_205[31].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_205[31].override_count = 0;
    *(_QWORD *)dataDesc_205[31].flatOffset = 0;
    dataDesc_205[35].fieldSize = 1;
    *(_QWORD *)&dataDesc_205[32].inputFunc = 0;
    *(_QWORD *)&dataDesc_205[32].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_205[32].override_count = 0;
    *(_QWORD *)dataDesc_205[32].flatOffset = 0;
    *(_QWORD *)&dataDesc_205[33].inputFunc = 0;
    *(_QWORD *)&dataDesc_205[33].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_205[33].override_count = 0;
    *(_QWORD *)dataDesc_205[33].flatOffset = 0;
    dataDesc_205[35].flags = 22;
    *(_QWORD *)&dataDesc_205[34].inputFunc = 0;
    *(_QWORD *)&dataDesc_205[34].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_205[34].override_count = 0;
    *(_QWORD *)dataDesc_205[34].flatOffset = 0;
    dataDesc_205[36].fieldSize = 1;
    *(_QWORD *)&dataDesc_205[35].inputFunc = 0;
    *(_QWORD *)&dataDesc_205[35].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_205[35].override_count = 0;
    *(_QWORD *)dataDesc_205[35].flatOffset = 0;
    dataDesc_205[31].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_205[31].flatGroup = 0;
    dataDesc_205[32].fieldType = FIELD_CUSTOM;
    dataDesc_205[32].fieldName = "m_OnProxyRelay2";
    dataDesc_205[32].fieldOffset = 876;
    dataDesc_205[32].externalName = "OnProxyRelay2";
    dataDesc_205[32].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_205[32].flatGroup = 0;
    dataDesc_205[33].fieldType = FIELD_CUSTOM;
    dataDesc_205[33].fieldName = "m_OnProxyRelay3";
    dataDesc_205[33].fieldOffset = 900;
    dataDesc_205[33].externalName = "OnProxyRelay3";
    dataDesc_205[33].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_205[33].flatGroup = 0;
    dataDesc_205[34].fieldType = FIELD_CUSTOM;
    dataDesc_205[34].fieldName = "m_OnProxyRelay4";
    dataDesc_205[34].fieldOffset = 924;
    dataDesc_205[34].externalName = "OnProxyRelay4";
    dataDesc_205[34].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_205[34].flatGroup = 0;
    dataDesc_205[35].fieldType = FIELD_CUSTOM;
    dataDesc_205[35].fieldName = "m_OnProxyRelay5";
    dataDesc_205[35].fieldOffset = 948;
    dataDesc_205[35].externalName = "OnProxyRelay5";
    dataDesc_205[35].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_205[35].flatGroup = 0;
    dataDesc_205[36].fieldType = FIELD_CUSTOM;
    dataDesc_205[36].fieldName = "m_OnProxyRelay6";
    dataDesc_205[36].fieldOffset = 972;
    dataDesc_205[36].flags = 22;
    dataDesc_205[36].externalName = "OnProxyRelay6";
    dataDesc_205[36].pSaveRestoreOps = eventFuncs;
    dataDesc_205[37].fieldSize = 1;
    dataDesc_205[37].flags = 22;
    dataDesc_205[38].fieldSize = 1;
    dataDesc_205[38].flags = 22;
    dataDesc_205[39].fieldSize = 1;
    dataDesc_205[39].flags = 22;
    *(_QWORD *)&dataDesc_205[36].inputFunc = 0;
    *(_QWORD *)&dataDesc_205[36].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_205[36].override_count = 0;
    *(_QWORD *)dataDesc_205[36].flatOffset = 0;
    *(_QWORD *)&dataDesc_205[37].inputFunc = 0;
    *(_QWORD *)&dataDesc_205[37].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_205[37].override_count = 0;
    *(_QWORD *)dataDesc_205[37].flatOffset = 0;
    dataDesc_205[40].fieldSize = 1;
    *(_QWORD *)&dataDesc_205[38].inputFunc = 0;
    *(_QWORD *)&dataDesc_205[38].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_205[38].override_count = 0;
    *(_QWORD *)dataDesc_205[38].flatOffset = 0;
    dataDesc_205[40].flags = 22;
    *(_QWORD *)&dataDesc_205[39].inputFunc = 0;
    *(_QWORD *)&dataDesc_205[39].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_205[39].override_count = 0;
    *(_QWORD *)dataDesc_205[39].flatOffset = 0;
    dataDesc_205[41].fieldSize = 1;
    *(_QWORD *)&dataDesc_205[40].inputFunc = 0;
    *(_QWORD *)&dataDesc_205[40].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_205[40].override_count = 0;
    *(_QWORD *)dataDesc_205[40].flatOffset = 0;
    *(_DWORD *)&dataDesc_205[36].flatGroup = 0;
    dataDesc_205[37].fieldType = FIELD_CUSTOM;
    dataDesc_205[37].fieldName = "m_OnProxyRelay7";
    dataDesc_205[37].fieldOffset = 996;
    dataDesc_205[37].externalName = "OnProxyRelay7";
    dataDesc_205[37].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_205[37].flatGroup = 0;
    dataDesc_205[38].fieldType = FIELD_CUSTOM;
    dataDesc_205[38].fieldName = "m_OnProxyRelay8";
    dataDesc_205[38].fieldOffset = 1020;
    dataDesc_205[38].externalName = "OnProxyRelay8";
    dataDesc_205[38].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_205[38].flatGroup = 0;
    dataDesc_205[39].fieldType = FIELD_CUSTOM;
    dataDesc_205[39].fieldName = "m_OnProxyRelay9";
    dataDesc_205[39].fieldOffset = 1044;
    dataDesc_205[39].externalName = "OnProxyRelay9";
    dataDesc_205[39].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_205[39].flatGroup = 0;
    dataDesc_205[40].fieldType = FIELD_CUSTOM;
    dataDesc_205[40].fieldName = "m_OnProxyRelay10";
    dataDesc_205[40].fieldOffset = 1068;
    dataDesc_205[40].externalName = "OnProxyRelay10";
    dataDesc_205[40].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_205[40].flatGroup = 0;
    dataDesc_205[41].fieldType = FIELD_CUSTOM;
    dataDesc_205[41].fieldName = "m_OnProxyRelay11";
    dataDesc_205[41].fieldOffset = 1092;
    dataDesc_205[41].flags = 22;
    dataDesc_205[41].externalName = "OnProxyRelay11";
    dataDesc_205[41].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_205[41].inputFunc = 0;
    *(_QWORD *)&dataDesc_205[41].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_205[41].override_count = 0;
    *(_QWORD *)dataDesc_205[41].flatOffset = 0;
    *(_DWORD *)&dataDesc_205[41].flatGroup = 0;
    dataDesc_205[42].fieldType = FIELD_CUSTOM;
    dataDesc_205[42].fieldSize = 1;
    dataDesc_205[42].flags = 22;
    dataDesc_205[43].fieldSize = 1;
    dataDesc_205[43].flags = 22;
    dataDesc_205[44].fieldSize = 1;
    dataDesc_205[44].flags = 22;
    dataDesc_205[45].fieldSize = 1;
    *(_QWORD *)&dataDesc_205[42].inputFunc = 0;
    *(_QWORD *)&dataDesc_205[42].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_205[42].override_count = 0;
    *(_QWORD *)dataDesc_205[42].flatOffset = 0;
    dataDesc_205[45].flags = 22;
    *(_QWORD *)&dataDesc_205[43].inputFunc = 0;
    *(_QWORD *)&dataDesc_205[43].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_205[43].override_count = 0;
    *(_QWORD *)dataDesc_205[43].flatOffset = 0;
    dataDesc_205[46].fieldSize = 1;
    *(_QWORD *)&dataDesc_205[44].inputFunc = 0;
    *(_QWORD *)&dataDesc_205[44].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_205[44].override_count = 0;
    *(_QWORD *)dataDesc_205[44].flatOffset = 0;
    dataDesc_205[46].fieldOffset = 1212;
    dataDesc_205[46].flags = 22;
    dataDesc_205[47].fieldOffset = 1212;
    *(_QWORD *)&dataDesc_205[45].inputFunc = 0;
    *(_QWORD *)&dataDesc_205[45].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_205[45].override_count = 0;
    *(_QWORD *)dataDesc_205[45].flatOffset = 0;
    dataDesc_205[42].fieldName = "m_OnProxyRelay12";
    dataDesc_205[42].fieldOffset = 1116;
    dataDesc_205[42].externalName = "OnProxyRelay12";
    dataDesc_205[42].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_205[42].flatGroup = 0;
    dataDesc_205[43].fieldType = FIELD_CUSTOM;
    dataDesc_205[43].fieldName = "m_OnProxyRelay13";
    dataDesc_205[43].fieldOffset = 1140;
    dataDesc_205[43].externalName = "OnProxyRelay13";
    dataDesc_205[43].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_205[43].flatGroup = 0;
    dataDesc_205[44].fieldType = FIELD_CUSTOM;
    dataDesc_205[44].fieldName = "m_OnProxyRelay14";
    dataDesc_205[44].fieldOffset = 1164;
    dataDesc_205[44].externalName = "OnProxyRelay14";
    dataDesc_205[44].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_205[44].flatGroup = 0;
    dataDesc_205[45].fieldType = FIELD_CUSTOM;
    dataDesc_205[45].fieldName = "m_OnProxyRelay15";
    dataDesc_205[45].fieldOffset = 1188;
    dataDesc_205[45].externalName = "OnProxyRelay15";
    dataDesc_205[45].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_205[45].flatGroup = 0;
    dataDesc_205[46].fieldType = FIELD_CUSTOM;
    dataDesc_205[46].fieldName = "m_OnProxyRelay16";
    dataDesc_205[46].externalName = "OnProxyRelay16";
    dataDesc_205[46].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_205[46].inputFunc = 0;
    *(_QWORD *)&dataDesc_205[46].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_205[46].override_count = 0;
    *(_QWORD *)dataDesc_205[46].flatOffset = 0;
    *(_DWORD *)&dataDesc_205[46].flatGroup = 0;
    dataDesc_205[47].fieldType = FIELD_CUSTOM;
    dataDesc_205[47].fieldName = "m_OnProxyRelay16";
    dataDesc_205[47].fieldSize = 1;
    dataDesc_205[47].externalName = "OnProxyRelay16";
    dataDesc_205[48].fieldSize = 1;
    dataDesc_205[48].flags = 22;
    dataDesc_205[49].fieldSize = 1;
    dataDesc_205[49].flags = 22;
    dataDesc_205[50].fieldSize = 1;
    dataDesc_205[50].flags = 22;
    *(_QWORD *)&dataDesc_205[47].inputFunc = 0;
    *(_QWORD *)&dataDesc_205[47].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_205[47].override_count = 0;
    *(_QWORD *)dataDesc_205[47].flatOffset = 0;
    *(_QWORD *)&dataDesc_205[48].inputFunc = 0;
    *(_QWORD *)&dataDesc_205[48].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_205[48].override_count = 0;
    *(_QWORD *)dataDesc_205[48].flatOffset = 0;
    dataDesc_205[51].fieldSize = 1;
    *(_QWORD *)&dataDesc_205[49].inputFunc = 0;
    *(_QWORD *)&dataDesc_205[49].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_205[49].override_count = 0;
    *(_QWORD *)dataDesc_205[49].flatOffset = 0;
    dataDesc_205[51].flags = 22;
    *(_QWORD *)&dataDesc_205[50].inputFunc = 0;
    *(_QWORD *)&dataDesc_205[50].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_205[50].override_count = 0;
    *(_QWORD *)dataDesc_205[50].flatOffset = 0;
    dataDesc_205[52].fieldSize = 1;
    *(_QWORD *)&dataDesc_205[51].inputFunc = 0;
    *(_QWORD *)&dataDesc_205[51].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_205[51].override_count = 0;
    *(_QWORD *)dataDesc_205[51].flatOffset = 0;
    dataDesc_205[47].flags = 22;
    dataDesc_205[47].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_205[47].flatGroup = 0;
    dataDesc_205[48].fieldType = FIELD_CUSTOM;
    dataDesc_205[48].fieldName = "m_OnProxyRelay17";
    dataDesc_205[48].fieldOffset = 1236;
    dataDesc_205[48].externalName = "OnProxyRelay17";
    dataDesc_205[48].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_205[48].flatGroup = 0;
    dataDesc_205[49].fieldType = FIELD_CUSTOM;
    dataDesc_205[49].fieldName = "m_OnProxyRelay18";
    dataDesc_205[49].fieldOffset = 1260;
    dataDesc_205[49].externalName = "OnProxyRelay18";
    dataDesc_205[49].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_205[49].flatGroup = 0;
    dataDesc_205[50].fieldType = FIELD_CUSTOM;
    dataDesc_205[50].fieldName = "m_OnProxyRelay19";
    dataDesc_205[50].fieldOffset = 1284;
    dataDesc_205[50].externalName = "OnProxyRelay19";
    dataDesc_205[50].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_205[50].flatGroup = 0;
    dataDesc_205[51].fieldType = FIELD_CUSTOM;
    dataDesc_205[51].fieldName = "m_OnProxyRelay20";
    dataDesc_205[51].fieldOffset = 1308;
    dataDesc_205[51].externalName = "OnProxyRelay20";
    dataDesc_205[51].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_205[51].flatGroup = 0;
    dataDesc_205[52].fieldType = FIELD_CUSTOM;
    dataDesc_205[52].fieldName = "m_OnProxyRelay21";
    dataDesc_205[52].fieldOffset = 1332;
    dataDesc_205[52].flags = 22;
    dataDesc_205[52].externalName = "OnProxyRelay21";
    dataDesc_205[52].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_205[52].inputFunc = 0;
    dataDesc_205[53].fieldSize = 1;
    dataDesc_205[53].flags = 22;
    dataDesc_205[54].fieldSize = 1;
    dataDesc_205[54].flags = 22;
    dataDesc_205[55].fieldSize = 1;
    dataDesc_205[55].flags = 22;
    *(_QWORD *)&dataDesc_205[52].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_205[52].override_count = 0;
    *(_QWORD *)dataDesc_205[52].flatOffset = 0;
    *(_QWORD *)&dataDesc_205[53].inputFunc = 0;
    *(_QWORD *)&dataDesc_205[53].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_205[53].override_count = 0;
    *(_QWORD *)dataDesc_205[53].flatOffset = 0;
    dataDesc_205[56].fieldSize = 1;
    *(_QWORD *)&dataDesc_205[54].inputFunc = 0;
    *(_QWORD *)&dataDesc_205[54].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_205[54].override_count = 0;
    *(_QWORD *)dataDesc_205[54].flatOffset = 0;
    dataDesc_205[56].flags = 22;
    *(_QWORD *)&dataDesc_205[55].inputFunc = 0;
    *(_QWORD *)&dataDesc_205[55].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_205[55].override_count = 0;
    *(_QWORD *)dataDesc_205[55].flatOffset = 0;
    dataDesc_205[57].fieldSize = 1;
    *(_QWORD *)&dataDesc_205[56].inputFunc = 0;
    *(_QWORD *)&dataDesc_205[56].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_205[56].override_count = 0;
    *(_QWORD *)dataDesc_205[56].flatOffset = 0;
    *(_DWORD *)&dataDesc_205[52].flatGroup = 0;
    dataDesc_205[53].fieldType = FIELD_CUSTOM;
    dataDesc_205[53].fieldName = "m_OnProxyRelay22";
    dataDesc_205[53].fieldOffset = 1356;
    dataDesc_205[53].externalName = "OnProxyRelay22";
    dataDesc_205[53].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_205[53].flatGroup = 0;
    dataDesc_205[54].fieldType = FIELD_CUSTOM;
    dataDesc_205[54].fieldName = "m_OnProxyRelay23";
    dataDesc_205[54].fieldOffset = 1380;
    dataDesc_205[54].externalName = "OnProxyRelay23";
    dataDesc_205[54].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_205[54].flatGroup = 0;
    dataDesc_205[55].fieldType = FIELD_CUSTOM;
    dataDesc_205[55].fieldName = "m_OnProxyRelay24";
    dataDesc_205[55].fieldOffset = 1404;
    dataDesc_205[55].externalName = "OnProxyRelay24";
    dataDesc_205[55].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_205[55].flatGroup = 0;
    dataDesc_205[56].fieldType = FIELD_CUSTOM;
    dataDesc_205[56].fieldName = "m_OnProxyRelay25";
    dataDesc_205[56].fieldOffset = 1428;
    dataDesc_205[56].externalName = "OnProxyRelay25";
    dataDesc_205[56].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_205[56].flatGroup = 0;
    dataDesc_205[57].fieldType = FIELD_CUSTOM;
    dataDesc_205[57].fieldName = "m_OnProxyRelay26";
    dataDesc_205[57].fieldOffset = 1452;
    dataDesc_205[57].flags = 22;
    dataDesc_205[57].externalName = "OnProxyRelay26";
    dataDesc_205[57].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_205[57].inputFunc = 0;
    *(_QWORD *)&dataDesc_205[57].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_205[57].override_count = 0;
    *(_QWORD *)dataDesc_205[57].flatOffset = 0;
    *(_DWORD *)&dataDesc_205[57].flatGroup = 0;
    dataDesc_205[58].fieldType = FIELD_CUSTOM;
    dataDesc_205[58].fieldName = "m_OnProxyRelay27";
    dataDesc_205[58].fieldSize = 1;
    dataDesc_205[58].flags = 22;
    dataDesc_205[59].fieldSize = 1;
    *(_QWORD *)&dataDesc_205[58].inputFunc = 0;
    *(_QWORD *)&dataDesc_205[58].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_205[58].override_count = 0;
    *(_QWORD *)dataDesc_205[58].flatOffset = 0;
    dataDesc_205[59].flags = 22;
    *(_QWORD *)&dataDesc_205[59].inputFunc = 0;
    *(_QWORD *)&dataDesc_205[59].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_205[59].override_count = 0;
    *(_QWORD *)dataDesc_205[59].flatOffset = 0;
    dataDesc_205[60].fieldSize = 1;
    *(_QWORD *)&dataDesc_205[60].inputFunc = 0;
    *(_QWORD *)&dataDesc_205[60].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_205[60].override_count = 0;
    *(_QWORD *)dataDesc_205[60].flatOffset = 0;
    dataDesc_205[58].fieldOffset = 1476;
    dataDesc_205[58].externalName = "OnProxyRelay27";
    dataDesc_205[58].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_205[58].flatGroup = 0;
    dataDesc_205[59].fieldType = FIELD_CUSTOM;
    dataDesc_205[59].fieldName = "m_OnProxyRelay28";
    dataDesc_205[59].fieldOffset = 1500;
    dataDesc_205[59].externalName = "OnProxyRelay28";
    dataDesc_205[59].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_205[59].flatGroup = 0;
    dataDesc_205[60].fieldType = FIELD_CUSTOM;
    dataDesc_205[60].fieldName = "m_OnProxyRelay29";
    dataDesc_205[60].fieldOffset = 1524;
    dataDesc_205[60].flags = 22;
    dataDesc_205[60].externalName = "OnProxyRelay29";
    dataDesc_205[60].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_205[60].flatGroup = 0;
    dataDesc_205[61].fieldType = FIELD_CUSTOM;
    dataDesc_205[61].fieldName = "m_OnProxyRelay30";
    dataDesc_205[61].fieldOffset = 1548;
    *(_DWORD *)&dataDesc_205[61].fieldSize = 1441793;
    dataDesc_205[61].externalName = "OnProxyRelay30";
    dataDesc_205[61].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_205[61].inputFunc = 0;
    *(_QWORD *)&dataDesc_205[61].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_205[61].override_count = 0;
    *(_QWORD *)dataDesc_205[61].flatOffset = 0;
    *(_DWORD *)&dataDesc_205[61].flatGroup = 0;
  }
  CFuncInstanceIoProxy::m_DataMap.dataNumFields = 61;
  CFuncInstanceIoProxy::m_DataMap.dataDesc = &dataDesc_205[1];
  return &CFuncInstanceIoProxy::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1013BE20
// Name: struct datamap_t __near * DataMapInit<class CFuncMonitor>(class CFuncMonitor __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CFuncMonitor>()
{
  if ( (_S2_120 & 1) == 0 )
  {
    _S2_120 |= 1u;
    nameHolder_219.m_pszBase = "CFuncMonitor";
    nameHolder_219.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_219.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_219.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_219.m_Names.m_Size = 0;
    nameHolder_219.m_Names.m_pElements = nullptr;
    nameHolder_219.m_nLenBase = 12;
    atexit(func: DataMapInit_CFuncMonitor__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CFuncMonitor::m_DataMap.baseMap = &CFuncBrush::m_DataMap;
  CFuncMonitor::m_DataMap.dataNumFields = 2;
  CFuncMonitor::m_DataMap.dataDesc = &dataDesc_208[1];
  return &CFuncMonitor::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1013D3A0
// Name: struct datamap_t __near * DataMapInit<class CFuncOccluder>(class CFuncOccluder __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CFuncOccluder>()
{
  if ( (_S3_68 & 1) == 0 )
  {
    _S3_68 |= 1u;
    nameHolder_221.m_pszBase = "CFuncOccluder";
    nameHolder_221.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_221.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_221.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_221.m_Names.m_Size = 0;
    nameHolder_221.m_Names.m_pElements = nullptr;
    nameHolder_221.m_nLenBase = 13;
    atexit(func: DataMapInit_CFuncOccluder__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CFuncOccluder::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CFuncOccluder::m_DataMap.dataNumFields = 5;
  CFuncOccluder::m_DataMap.dataDesc = &dataDesc_210[1];
  return &CFuncOccluder::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1013D500
// Name: struct datamap_t __near * DataMapInit<class CFuncReflectiveGlass>(class CFuncReflectiveGlass __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CFuncReflectiveGlass>()
{
  if ( (_S2_123 & 1) == 0 )
  {
    _S2_123 |= 1u;
    nameHolder_222.m_pszBase = "CFuncReflectiveGlass";
    nameHolder_222.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_222.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_222.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_222.m_Names.m_Size = 0;
    nameHolder_222.m_Names.m_pElements = nullptr;
    nameHolder_222.m_nLenBase = 20;
    atexit(func: DataMapInit_CFuncReflectiveGlass__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CFuncReflectiveGlass::m_DataMap.baseMap = &CFuncBrush::m_DataMap;
  CFuncReflectiveGlass::m_DataMap.dataNumFields = 1;
  CFuncReflectiveGlass::m_DataMap.dataDesc = dataDesc_478;
  return &CFuncReflectiveGlass::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1013DA50
// Name: struct datamap_t __near * DataMapInit<class CFuncSmokeVolume>(class CFuncSmokeVolume __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CFuncSmokeVolume>()
{
  if ( (_S2_124 & 1) == 0 )
  {
    _S2_124 |= 1u;
    nameHolder_223.m_pszBase = "CFuncSmokeVolume";
    nameHolder_223.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_223.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_223.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_223.m_Names.m_Size = 0;
    nameHolder_223.m_Names.m_pElements = nullptr;
    nameHolder_223.m_nLenBase = 16;
    atexit(func: DataMapInit_CFuncSmokeVolume__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CFuncSmokeVolume::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CFuncSmokeVolume::m_DataMap.dataNumFields = 13;
  CFuncSmokeVolume::m_DataMap.dataDesc = &dataDesc_211[1];
  return &CFuncSmokeVolume::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1013ECD0
// Name: struct datamap_t __near * DataMapInit<class CGameUI>(class CGameUI __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CGameUI>()
{
  if ( (_S2_125 & 1) == 0 )
  {
    _S2_125 |= 1u;
    nameHolder_224.m_pszBase = "CGameUI";
    nameHolder_224.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_224.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_224.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_224.m_Names.m_Size = 0;
    nameHolder_224.m_Names.m_pElements = nullptr;
    nameHolder_224.m_nLenBase = 7;
    atexit(func: DataMapInit_CGameUI__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CGameUI::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S2_125 & 2) == 0 )
  {
    _S2_125 |= 2u;
    dataDesc_212[9].fieldSize = 1;
    dataDesc_212[9].flags = 22;
    dataDesc_212[10].fieldSize = 1;
    dataDesc_212[10].flags = 22;
    dataDesc_212[11].fieldSize = 1;
    dataDesc_212[11].flags = 22;
    *(_QWORD *)&dataDesc_212[8].inputFunc = 0;
    *(_QWORD *)&dataDesc_212[8].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_212[8].override_count = 0;
    *(_QWORD *)dataDesc_212[8].flatOffset = 0;
    *(_QWORD *)&dataDesc_212[9].inputFunc = 0;
    *(_QWORD *)&dataDesc_212[9].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_212[9].override_count = 0;
    *(_QWORD *)dataDesc_212[9].flatOffset = 0;
    dataDesc_212[12].fieldSize = 1;
    *(_QWORD *)&dataDesc_212[10].inputFunc = 0;
    *(_QWORD *)&dataDesc_212[10].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_212[10].override_count = 0;
    *(_QWORD *)dataDesc_212[10].flatOffset = 0;
    dataDesc_212[12].flags = 22;
    *(_QWORD *)&dataDesc_212[11].inputFunc = 0;
    *(_QWORD *)&dataDesc_212[11].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_212[11].override_count = 0;
    *(_QWORD *)dataDesc_212[11].flatOffset = 0;
    dataDesc_212[13].fieldSize = 1;
    *(_QWORD *)&dataDesc_212[12].inputFunc = 0;
    *(_QWORD *)&dataDesc_212[12].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_212[12].override_count = 0;
    *(_QWORD *)dataDesc_212[12].flatOffset = 0;
    dataDesc_212[8].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_212[8].flatGroup = 0;
    dataDesc_212[9].fieldType = FIELD_CUSTOM;
    dataDesc_212[9].fieldName = "m_playerOff";
    dataDesc_212[9].fieldOffset = 884;
    dataDesc_212[9].externalName = "PlayerOff";
    dataDesc_212[9].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_212[9].flatGroup = 0;
    dataDesc_212[10].fieldType = FIELD_CUSTOM;
    dataDesc_212[10].fieldName = "m_pressedMoveLeft";
    dataDesc_212[10].fieldOffset = 908;
    dataDesc_212[10].externalName = "PressedMoveLeft";
    dataDesc_212[10].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_212[10].flatGroup = 0;
    dataDesc_212[11].fieldType = FIELD_CUSTOM;
    dataDesc_212[11].fieldName = "m_pressedMoveRight";
    dataDesc_212[11].fieldOffset = 932;
    dataDesc_212[11].externalName = "PressedMoveRight";
    dataDesc_212[11].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_212[11].flatGroup = 0;
    dataDesc_212[12].fieldType = FIELD_CUSTOM;
    dataDesc_212[12].fieldName = "m_pressedForward";
    dataDesc_212[12].fieldOffset = 956;
    dataDesc_212[12].externalName = "PressedForward";
    dataDesc_212[12].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_212[12].flatGroup = 0;
    dataDesc_212[13].fieldType = FIELD_CUSTOM;
    dataDesc_212[13].fieldName = "m_pressedBack";
    dataDesc_212[13].fieldOffset = 980;
    dataDesc_212[13].flags = 22;
    dataDesc_212[13].externalName = "PressedBack";
    dataDesc_212[13].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_212[13].inputFunc = 0;
    dataDesc_212[14].fieldSize = 1;
    dataDesc_212[14].flags = 22;
    dataDesc_212[15].fieldSize = 1;
    dataDesc_212[15].flags = 22;
    dataDesc_212[16].fieldSize = 1;
    dataDesc_212[16].flags = 22;
    *(_QWORD *)&dataDesc_212[13].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_212[13].override_count = 0;
    *(_QWORD *)dataDesc_212[13].flatOffset = 0;
    *(_QWORD *)&dataDesc_212[14].inputFunc = 0;
    *(_QWORD *)&dataDesc_212[14].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_212[14].override_count = 0;
    *(_QWORD *)dataDesc_212[14].flatOffset = 0;
    dataDesc_212[17].fieldSize = 1;
    *(_QWORD *)&dataDesc_212[15].inputFunc = 0;
    *(_QWORD *)&dataDesc_212[15].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_212[15].override_count = 0;
    *(_QWORD *)dataDesc_212[15].flatOffset = 0;
    dataDesc_212[17].flags = 22;
    *(_QWORD *)&dataDesc_212[16].inputFunc = 0;
    *(_QWORD *)&dataDesc_212[16].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_212[16].override_count = 0;
    *(_QWORD *)dataDesc_212[16].flatOffset = 0;
    dataDesc_212[18].fieldSize = 1;
    *(_QWORD *)&dataDesc_212[17].inputFunc = 0;
    *(_QWORD *)&dataDesc_212[17].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_212[17].override_count = 0;
    *(_QWORD *)dataDesc_212[17].flatOffset = 0;
    *(_DWORD *)&dataDesc_212[13].flatGroup = 0;
    dataDesc_212[14].fieldType = FIELD_CUSTOM;
    dataDesc_212[14].fieldName = "m_pressedAttack";
    dataDesc_212[14].fieldOffset = 1004;
    dataDesc_212[14].externalName = "PressedAttack";
    dataDesc_212[14].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_212[14].flatGroup = 0;
    dataDesc_212[15].fieldType = FIELD_CUSTOM;
    dataDesc_212[15].fieldName = "m_pressedAttack2";
    dataDesc_212[15].fieldOffset = 1028;
    dataDesc_212[15].externalName = "PressedAttack2";
    dataDesc_212[15].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_212[15].flatGroup = 0;
    dataDesc_212[16].fieldType = FIELD_CUSTOM;
    dataDesc_212[16].fieldName = "m_unpressedMoveLeft";
    dataDesc_212[16].fieldOffset = 1052;
    dataDesc_212[16].externalName = "UnpressedMoveLeft";
    dataDesc_212[16].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_212[16].flatGroup = 0;
    dataDesc_212[17].fieldType = FIELD_CUSTOM;
    dataDesc_212[17].fieldName = "m_unpressedMoveRight";
    dataDesc_212[17].fieldOffset = 1076;
    dataDesc_212[17].externalName = "UnpressedMoveRight";
    dataDesc_212[17].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_212[17].flatGroup = 0;
    dataDesc_212[18].fieldType = FIELD_CUSTOM;
    dataDesc_212[18].fieldName = "m_unpressedForward";
    dataDesc_212[18].fieldOffset = 1100;
    dataDesc_212[18].flags = 22;
    dataDesc_212[18].externalName = "UnpressedForward";
    dataDesc_212[18].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_212[18].inputFunc = 0;
    *(_QWORD *)&dataDesc_212[18].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_212[18].override_count = 0;
    *(_QWORD *)dataDesc_212[18].flatOffset = 0;
    *(_DWORD *)&dataDesc_212[18].flatGroup = 0;
    dataDesc_212[19].fieldType = FIELD_CUSTOM;
    dataDesc_212[19].fieldName = "m_unpressedBack";
    dataDesc_212[19].fieldSize = 1;
    dataDesc_212[19].flags = 22;
    dataDesc_212[20].fieldSize = 1;
    dataDesc_212[20].flags = 22;
    dataDesc_212[21].fieldSize = 1;
    dataDesc_212[21].flags = 22;
    dataDesc_212[22].fieldSize = 1;
    dataDesc_212[22].flags = 22;
    *(_QWORD *)&dataDesc_212[19].inputFunc = 0;
    *(_QWORD *)&dataDesc_212[19].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_212[19].override_count = 0;
    *(_QWORD *)dataDesc_212[19].flatOffset = 0;
    dataDesc_212[23].fieldSize = 1;
    *(_QWORD *)&dataDesc_212[20].inputFunc = 0;
    *(_QWORD *)&dataDesc_212[20].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_212[20].override_count = 0;
    *(_QWORD *)dataDesc_212[20].flatOffset = 0;
    dataDesc_212[23].flags = 22;
    *(_QWORD *)&dataDesc_212[21].inputFunc = 0;
    *(_QWORD *)&dataDesc_212[21].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_212[21].override_count = 0;
    *(_QWORD *)dataDesc_212[21].flatOffset = 0;
    dataDesc_212[24].fieldSize = 1;
    *(_QWORD *)&dataDesc_212[22].inputFunc = 0;
    *(_QWORD *)&dataDesc_212[22].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_212[22].override_count = 0;
    *(_QWORD *)dataDesc_212[22].flatOffset = 0;
    dataDesc_212[19].fieldOffset = 1124;
    dataDesc_212[19].externalName = "UnpressedBack";
    dataDesc_212[19].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_212[19].flatGroup = 0;
    dataDesc_212[20].fieldType = FIELD_CUSTOM;
    dataDesc_212[20].fieldName = "m_unpressedAttack";
    dataDesc_212[20].fieldOffset = 1148;
    dataDesc_212[20].externalName = "UnpressedAttack";
    dataDesc_212[20].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_212[20].flatGroup = 0;
    dataDesc_212[21].fieldType = FIELD_CUSTOM;
    dataDesc_212[21].fieldName = "m_unpressedAttack2";
    dataDesc_212[21].fieldOffset = 1172;
    dataDesc_212[21].externalName = "UnpressedAttack2";
    dataDesc_212[21].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_212[21].flatGroup = 0;
    dataDesc_212[22].fieldType = FIELD_CUSTOM;
    dataDesc_212[22].fieldName = "m_xaxis";
    dataDesc_212[22].fieldOffset = 1196;
    dataDesc_212[22].externalName = "XAxis";
    dataDesc_212[22].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_212[22].flatGroup = 0;
    dataDesc_212[23].fieldType = FIELD_CUSTOM;
    dataDesc_212[23].fieldName = "m_yaxis";
    dataDesc_212[23].fieldOffset = 1220;
    dataDesc_212[23].externalName = "YAxis";
    dataDesc_212[23].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_212[23].inputFunc = 0;
    *(_QWORD *)&dataDesc_212[23].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_212[23].override_count = 0;
    *(_QWORD *)dataDesc_212[23].flatOffset = 0;
    *(_DWORD *)&dataDesc_212[23].flatGroup = 0;
    dataDesc_212[24].fieldType = FIELD_CUSTOM;
    dataDesc_212[24].fieldName = "m_attackaxis";
    dataDesc_212[24].fieldOffset = 1244;
    dataDesc_212[24].flags = 22;
    dataDesc_212[24].externalName = "AttackAxis";
    *(_QWORD *)&dataDesc_212[24].inputFunc = 0;
    *(_QWORD *)&dataDesc_212[24].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_212[24].override_count = 0;
    *(_QWORD *)dataDesc_212[24].flatOffset = 0;
    dataDesc_212[24].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_212[24].flatGroup = 0;
    dataDesc_212[25].fieldType = FIELD_CUSTOM;
    dataDesc_212[25].fieldName = "m_attack2axis";
    dataDesc_212[25].fieldOffset = 1268;
    *(_DWORD *)&dataDesc_212[25].fieldSize = 1441793;
    dataDesc_212[25].externalName = "Attack2Axis";
    dataDesc_212[25].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_212[25].inputFunc = 0;
    *(_QWORD *)&dataDesc_212[25].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_212[25].override_count = 0;
    *(_QWORD *)dataDesc_212[25].flatOffset = 0;
    *(_DWORD *)&dataDesc_212[25].flatGroup = 0;
  }
  CGameUI::m_DataMap.dataNumFields = 25;
  CGameUI::m_DataMap.dataDesc = &dataDesc_212[1];
  return &CGameUI::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1013F480
// Name: __CreateCServerGameTagsIServerGameTags_interface_1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CServerGameTags *__cdecl _CreateCServerGameTagsIServerGameTags_interface_1()
{
  return &_g_CServerGameTags_singleton_1;
}

//------------------------------------------------------------------------------
// Address: 0x10155100
// Name: class CFlextalkActor __near * _CreateEntityTemplate<class CFlextalkActor>(class CFlextalkActor __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFlextalkActor *__cdecl _CreateEntityTemplate<CFlextalkActor>(CFlextalkActor *newEnt, const char *className)
{
  CAI_BaseActor *v2; // eax
  _DWORD *v3; // esi

  v2 = (CAI_BaseActor *)CBaseEntity::operator new(stAllocateBlock: 0x11D0u);
  v3 = &v2->CAI_ExpresserHost<CAI_BaseHumanoid>::CAI_BaseHumanoid::CAI_BlendingHost<CAI_BehaviorHost<CAI_BaseNPC> >::CAI_BehaviorHost<CAI_BaseNPC>::CAI_BehaviorHostBase<CAI_BaseNPC>::CAI_BaseNPC::CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
  if ( v2 != nullptr )
  {
    CAI_BaseActor::CAI_BaseActor(this: v2);
    *v3 = &CFlextalkActor::`vftable'{for `CBaseCombatCharacter'};
    v3[571] = &CFlextalkActor::`vftable'{for `CAI_DefMovementSink'};
    v3[572] = &CFlextalkActor::`vftable'{for `IAI_BehaviorBridge'};
    v3[930] = &CFlextalkActor::`vftable';
    v3[1138] = 0;
    v3[1139] = 0;
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CFlextalkActor *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10155510
// Name: class CGenericNPC __near * _CreateEntityTemplate<class CGenericNPC>(class CGenericNPC __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CGenericNPC *__cdecl _CreateEntityTemplate<CGenericNPC>(CGenericNPC *newEnt, const char *className)
{
  CAI_BaseNPC *v2; // eax
  _DWORD *v3; // esi

  v2 = (CAI_BaseNPC *)CBaseEntity::operator new(stAllocateBlock: 0xE84u);
  v3 = &v2->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
  if ( v2 != nullptr )
  {
    CAI_BaseNPC::CAI_BaseNPC(this: v2);
    *v3 = &CGenericNPC::`vftable'{for `CBaseCombatCharacter'};
    v3[571] = &CGenericNPC::`vftable'{for `CAI_DefMovementSink'};
    v3[572] = &CGenericNPC::`vftable'{for `IAI_BehaviorBridge'};
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CGenericNPC *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015AD30
// Name: class CWreckage __near * _CreateEntityTemplate<class CWreckage>(class CWreckage __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CWreckage *__cdecl _CreateEntityTemplate<CWreckage>(CWreckage *newEnt, const char *className)
{
  CAI_BaseNPC *v2; // eax
  _DWORD *v3; // esi

  v2 = (CAI_BaseNPC *)CBaseEntity::operator new(stAllocateBlock: 0xE8Cu);
  v3 = &v2->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
  if ( v2 != nullptr )
  {
    CAI_BaseNPC::CAI_BaseNPC(this: v2);
    *v3 = &CWreckage::`vftable'{for `CBaseCombatCharacter'};
    v3[571] = &CWreckage::`vftable'{for `CAI_DefMovementSink'};
    v3[572] = &CWreckage::`vftable'{for `IAI_BehaviorBridge'};
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CWreckage *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015AFB0
// Name: class CGenericCycler __near * _CreateEntityTemplate<class CGenericCycler>(class CGenericCycler __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CGenericCycler *__cdecl _CreateEntityTemplate<CGenericCycler>(CGenericCycler *newEnt, const char *className)
{
  CAI_BaseNPC *v2; // eax
  _DWORD *v3; // esi

  v2 = (CAI_BaseNPC *)CBaseEntity::operator new(stAllocateBlock: 0xE88u);
  v3 = &v2->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
  if ( v2 != nullptr )
  {
    CAI_BaseNPC::CAI_BaseNPC(this: v2);
    *v3 = &CGenericCycler::`vftable'{for `CBaseCombatCharacter'};
    v3[571] = &CGenericCycler::`vftable'{for `CAI_DefMovementSink'};
    v3[572] = &CGenericCycler::`vftable'{for `IAI_BehaviorBridge'};
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CGenericCycler *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015B010
// Name: class CBlendingCycler __near * _CreateEntityTemplate<class CBlendingCycler>(class CBlendingCycler __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBlendingCycler *__cdecl _CreateEntityTemplate<CBlendingCycler>(CBlendingCycler *newEnt, const char *className)
{
  CAI_BaseNPC *v2; // eax
  _DWORD *v3; // esi

  v2 = (CAI_BaseNPC *)CBaseEntity::operator new(stAllocateBlock: 0xE9Cu);
  v3 = &v2->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
  if ( v2 != nullptr )
  {
    CAI_BaseNPC::CAI_BaseNPC(this: v2);
    *v3 = &CBlendingCycler::`vftable'{for `CBaseCombatCharacter'};
    v3[571] = &CBlendingCycler::`vftable'{for `CAI_DefMovementSink'};
    v3[572] = &CBlendingCycler::`vftable'{for `IAI_BehaviorBridge'};
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CBlendingCycler *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101625F0
// Name: struct datamap_t __near * DataMapInit<class CInfoOverlayAccessor>(class CInfoOverlayAccessor __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CInfoOverlayAccessor>()
{
  if ( (_S3_75 & 1) == 0 )
  {
    _S3_75 |= 1u;
    nameHolder_239.m_pszBase = "CInfoOverlayAccessor";
    nameHolder_239.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_239.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_239.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_239.m_Names.m_Size = 0;
    nameHolder_239.m_Names.m_pElements = nullptr;
    nameHolder_239.m_nLenBase = 20;
    atexit(func: DataMapInit_CInfoOverlayAccessor__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CInfoOverlayAccessor::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CInfoOverlayAccessor::m_DataMap.dataNumFields = 1;
  CInfoOverlayAccessor::m_DataMap.dataDesc = &dataDesc_226[1];
  return &CInfoOverlayAccessor::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10162950
// Name: struct datamap_t __near * DataMapInit<class CInfoRemarkable>(class CInfoRemarkable __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CInfoRemarkable>()
{
  if ( (_S2_138 & 1) == 0 )
  {
    _S2_138 |= 1u;
    nameHolder_240.m_pszBase = "CInfoRemarkable";
    nameHolder_240.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_240.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_240.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_240.m_Names.m_Size = 0;
    nameHolder_240.m_Names.m_pElements = nullptr;
    nameHolder_240.m_nLenBase = 15;
    atexit(func: DataMapInit_CInfoRemarkable__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CInfoRemarkable::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CInfoRemarkable::m_DataMap.dataNumFields = 1;
  CInfoRemarkable::m_DataMap.dataDesc = &dataDesc_227[1];
  return &CInfoRemarkable::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10164B10
// Name: struct datamap_t __near * DataMapInit<class CLightGlow>(class CLightGlow __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CLightGlow>()
{
  if ( (_S3_77 & 1) == 0 )
  {
    _S3_77 |= 1u;
    nameHolder_243.m_pszBase = "CLightGlow";
    nameHolder_243.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_243.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_243.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_243.m_Names.m_Size = 0;
    nameHolder_243.m_Names.m_pElements = nullptr;
    nameHolder_243.m_nLenBase = 10;
    atexit(func: DataMapInit_CLightGlow__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CLightGlow::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CLightGlow::m_DataMap.dataNumFields = 8;
  CLightGlow::m_DataMap.dataDesc = &dataDesc_230[1];
  return &CLightGlow::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10165690
// Name: struct datamap_t __near * DataMapInit<class CLogicEventListener>(class CLogicEventListener __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CLogicEventListener>()
{
  if ( (_S2_142 & 1) == 0 )
  {
    _S2_142 |= 1u;
    nameHolder_245.m_pszBase = "CLogicEventListener";
    nameHolder_245.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_245.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_245.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_245.m_Names.m_Size = 0;
    nameHolder_245.m_Names.m_pElements = nullptr;
    nameHolder_245.m_nLenBase = 19;
    atexit(func: DataMapInit_CLogicEventListener__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CLogicEventListener::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S2_142 & 2) == 0 )
  {
    _S2_142 |= 2u;
    dataDesc_232[6].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_232[6].inputFunc = 0;
    *(_QWORD *)&dataDesc_232[6].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_232[6].override_count = 0;
    *(_QWORD *)dataDesc_232[6].flatOffset = 0;
    *(_DWORD *)&dataDesc_232[6].flatGroup = 0;
  }
  CLogicEventListener::m_DataMap.dataNumFields = 6;
  CLogicEventListener::m_DataMap.dataDesc = &dataDesc_232[1];
  return &CLogicEventListener::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101660D0
// Name: struct datamap_t __near * DataMapInit<class CLogicMeasureMovement>(class CLogicMeasureMovement __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CLogicMeasureMovement>()
{
  if ( (_S2_143 & 1) == 0 )
  {
    _S2_143 |= 1u;
    nameHolder_246.m_pszBase = "CLogicMeasureMovement";
    nameHolder_246.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_246.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_246.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_246.m_Names.m_Size = 0;
    nameHolder_246.m_Names.m_pElements = nullptr;
    nameHolder_246.m_nLenBase = 21;
    atexit(func: DataMapInit_CLogicMeasureMovement__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CLogicMeasureMovement::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S2_143 & 2) == 0 )
  {
    _S2_143 |= 2u;
    dataDesc_233[17].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_246,
                                   pszIdentifier: "MeasureThink");
    dataDesc_233[17].fieldOffset = 0;
    *(_DWORD *)&dataDesc_233[17].fieldSize = 2097153;
    dataDesc_233[17].externalName = nullptr;
    dataDesc_233[17].pSaveRestoreOps = nullptr;
    dataDesc_233[17].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CLogicMeasureMovement::MeasureThink;
    *(_QWORD *)&dataDesc_233[17].td = 0;
    *(_QWORD *)&dataDesc_233[17].override_field = 0;
    *(_QWORD *)&dataDesc_233[17].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_233[17].flatOffset[1] = 0;
  }
  CLogicMeasureMovement::m_DataMap.dataNumFields = 17;
  CLogicMeasureMovement::m_DataMap.dataDesc = &dataDesc_233[1];
  return &CLogicMeasureMovement::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10166800
// Name: struct datamap_t __near * DataMapInit<class CLogicPlayerProxy>(class CLogicPlayerProxy __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CLogicPlayerProxy>()
{
  if ( (_S2_145 & 1) == 0 )
  {
    _S2_145 |= 1u;
    nameHolder_248.m_pszBase = "CLogicPlayerProxy";
    nameHolder_248.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_248.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_248.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_248.m_Names.m_Size = 0;
    nameHolder_248.m_Names.m_pElements = nullptr;
    nameHolder_248.m_nLenBase = 17;
    atexit(func: DataMapInit_CLogicPlayerProxy__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CLogicPlayerProxy::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S2_145 & 2) == 0 )
  {
    _S2_145 |= 2u;
    *(_QWORD *)&dataDesc_235[1].inputFunc = 0;
    *(_QWORD *)&dataDesc_235[1].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_235[1].override_count = 0;
    *(_QWORD *)dataDesc_235[1].flatOffset = 0;
    *(_QWORD *)&dataDesc_235[2].inputFunc = 0;
    *(_QWORD *)&dataDesc_235[2].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_235[2].override_count = 0;
    *(_QWORD *)dataDesc_235[2].flatOffset = 0;
    dataDesc_235[3].flags = 2;
    dataDesc_235[4].fieldSize = 1;
    dataDesc_235[3].fieldTolerance = 0.0;
    dataDesc_235[2].fieldSize = 1;
    *(_QWORD *)dataDesc_235[3].flatOffset = 0;
    dataDesc_235[4].flags = 22;
    *(_QWORD *)&dataDesc_235[4].inputFunc = 0;
    *(_QWORD *)&dataDesc_235[4].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_235[4].override_count = 0;
    *(_QWORD *)dataDesc_235[4].flatOffset = 0;
    dataDesc_235[2].flags = 22;
    dataDesc_235[5].fieldSize = 1;
    *(_QWORD *)&dataDesc_235[5].inputFunc = 0;
    *(_QWORD *)&dataDesc_235[5].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_235[5].override_count = 0;
    *(_QWORD *)dataDesc_235[5].flatOffset = 0;
    dataDesc_235[1].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_235[1].flatGroup = 0;
    dataDesc_235[2].fieldType = FIELD_CUSTOM;
    dataDesc_235[2].fieldName = "m_PlayerDied";
    dataDesc_235[2].fieldOffset = 900;
    dataDesc_235[2].externalName = "PlayerDied";
    dataDesc_235[2].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_235[2].flatGroup = 0;
    dataDesc_235[3].fieldType = FIELD_EHANDLE;
    dataDesc_235[3].fieldName = "m_hPlayer";
    dataDesc_235[3].fieldOffset = 1020;
    dataDesc_235[3].fieldSize = 1;
    dataDesc_235[3].externalName = nullptr;
    dataDesc_235[3].pSaveRestoreOps = nullptr;
    dataDesc_235[3].inputFunc = nullptr;
    dataDesc_235[3].td = nullptr;
    dataDesc_235[3].fieldSizeInBytes = 4;
    dataDesc_235[3].override_field = nullptr;
    dataDesc_235[3].override_count = 0;
    *(_DWORD *)&dataDesc_235[3].flatGroup = 0;
    dataDesc_235[4].fieldType = FIELD_CUSTOM;
    dataDesc_235[4].fieldName = "m_OnJump";
    dataDesc_235[4].fieldOffset = 972;
    dataDesc_235[4].externalName = "OnJump";
    dataDesc_235[4].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_235[4].flatGroup = 0;
    dataDesc_235[5].fieldType = FIELD_CUSTOM;
    dataDesc_235[5].fieldName = "m_OnDuck";
    dataDesc_235[5].fieldOffset = 924;
    dataDesc_235[5].flags = 22;
    dataDesc_235[5].externalName = "OnDuck";
    dataDesc_235[5].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_235[5].flatGroup = 0;
    dataDesc_235[6].fieldType = FIELD_CUSTOM;
    dataDesc_235[6].fieldName = "m_OnUnDuck";
    dataDesc_235[6].fieldOffset = 948;
    *(_DWORD *)&dataDesc_235[6].fieldSize = 1441793;
    dataDesc_235[6].externalName = "OnUnDuck";
    dataDesc_235[6].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_235[6].inputFunc = 0;
    *(_QWORD *)&dataDesc_235[6].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_235[6].override_count = 0;
    *(_QWORD *)dataDesc_235[6].flatOffset = 0;
    *(_DWORD *)&dataDesc_235[6].flatGroup = 0;
  }
  CLogicPlayerProxy::m_DataMap.dataNumFields = 6;
  CLogicPlayerProxy::m_DataMap.dataDesc = &dataDesc_235[1];
  return &CLogicPlayerProxy::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10166EC0
// Name: struct datamap_t __near * DataMapInit<class CLogicPlayMovie>(class CLogicPlayMovie __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CLogicPlayMovie>()
{
  if ( (_S2_146 & 1) == 0 )
  {
    _S2_146 |= 1u;
    nameHolder_249.m_pszBase = "CLogicPlayMovie";
    nameHolder_249.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_249.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_249.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_249.m_Names.m_Size = 0;
    nameHolder_249.m_Names.m_pElements = nullptr;
    nameHolder_249.m_nLenBase = 15;
    atexit(func: DataMapInit_CLogicPlayMovie__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CLogicPlayMovie::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S2_146 & 2) == 0 )
  {
    _S2_146 |= 2u;
    dataDesc_236[10].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_236[10].inputFunc = 0;
    *(_QWORD *)&dataDesc_236[10].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_236[10].override_count = 0;
    *(_QWORD *)dataDesc_236[10].flatOffset = 0;
    *(_DWORD *)&dataDesc_236[10].flatGroup = 0;
  }
  CLogicPlayMovie::m_DataMap.dataNumFields = 10;
  CLogicPlayMovie::m_DataMap.dataDesc = &dataDesc_236[1];
  return &CLogicPlayMovie::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101673A0
// Name: struct datamap_t __near * DataMapInit<class CLogicRandomOutputs>(class CLogicRandomOutputs __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CLogicRandomOutputs>()
{
  if ( (_S2_147 & 1) == 0 )
  {
    _S2_147 |= 1u;
    nameHolder_250.m_pszBase = "CLogicRandomOutputs";
    nameHolder_250.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_250.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_250.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_250.m_Names.m_Size = 0;
    nameHolder_250.m_Names.m_pElements = nullptr;
    nameHolder_250.m_nLenBase = 19;
    atexit(func: DataMapInit_CLogicRandomOutputs__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CLogicRandomOutputs::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S2_147 & 2) == 0 )
  {
    _S2_147 |= 2u;
    dataDesc_237[11].fieldSize = 1;
    dataDesc_237[11].flags = 22;
    dataDesc_237[12].fieldSize = 1;
    dataDesc_237[12].flags = 22;
    dataDesc_237[13].fieldSize = 1;
    dataDesc_237[13].flags = 22;
    *(_QWORD *)&dataDesc_237[10].inputFunc = 0;
    *(_QWORD *)&dataDesc_237[10].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_237[10].override_count = 0;
    *(_QWORD *)dataDesc_237[10].flatOffset = 0;
    *(_QWORD *)&dataDesc_237[11].inputFunc = 0;
    *(_QWORD *)&dataDesc_237[11].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_237[11].override_count = 0;
    *(_QWORD *)dataDesc_237[11].flatOffset = 0;
    dataDesc_237[14].fieldSize = 1;
    *(_QWORD *)&dataDesc_237[12].inputFunc = 0;
    *(_QWORD *)&dataDesc_237[12].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_237[12].override_count = 0;
    *(_QWORD *)dataDesc_237[12].flatOffset = 0;
    dataDesc_237[14].flags = 22;
    *(_QWORD *)&dataDesc_237[13].inputFunc = 0;
    *(_QWORD *)&dataDesc_237[13].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_237[13].override_count = 0;
    *(_QWORD *)dataDesc_237[13].flatOffset = 0;
    dataDesc_237[15].fieldSize = 1;
    *(_QWORD *)&dataDesc_237[14].inputFunc = 0;
    *(_QWORD *)&dataDesc_237[14].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_237[14].override_count = 0;
    *(_QWORD *)dataDesc_237[14].flatOffset = 0;
    dataDesc_237[10].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_237[10].flatGroup = 0;
    dataDesc_237[11].fieldType = FIELD_CUSTOM;
    dataDesc_237[11].fieldName = "m_Output[0]";
    dataDesc_237[11].fieldOffset = 852;
    dataDesc_237[11].externalName = "OnTrigger1";
    dataDesc_237[11].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_237[11].flatGroup = 0;
    dataDesc_237[12].fieldType = FIELD_CUSTOM;
    dataDesc_237[12].fieldName = "m_Output[1]";
    dataDesc_237[12].fieldOffset = 876;
    dataDesc_237[12].externalName = "OnTrigger2";
    dataDesc_237[12].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_237[12].flatGroup = 0;
    dataDesc_237[13].fieldType = FIELD_CUSTOM;
    dataDesc_237[13].fieldName = "m_Output[2]";
    dataDesc_237[13].fieldOffset = 900;
    dataDesc_237[13].externalName = "OnTrigger3";
    dataDesc_237[13].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_237[13].flatGroup = 0;
    dataDesc_237[14].fieldType = FIELD_CUSTOM;
    dataDesc_237[14].fieldName = "m_Output[3]";
    dataDesc_237[14].fieldOffset = 924;
    dataDesc_237[14].externalName = "OnTrigger4";
    dataDesc_237[14].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_237[14].flatGroup = 0;
    dataDesc_237[15].fieldType = FIELD_CUSTOM;
    dataDesc_237[15].fieldName = "m_Output[4]";
    dataDesc_237[15].fieldOffset = 948;
    dataDesc_237[15].flags = 22;
    dataDesc_237[15].externalName = "OnTrigger5";
    dataDesc_237[15].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_237[15].inputFunc = 0;
    dataDesc_237[16].fieldSize = 1;
    *(_QWORD *)&dataDesc_237[15].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_237[15].override_count = 0;
    *(_QWORD *)dataDesc_237[15].flatOffset = 0;
    dataDesc_237[16].flags = 22;
    *(_QWORD *)&dataDesc_237[16].inputFunc = 0;
    *(_QWORD *)&dataDesc_237[16].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_237[16].override_count = 0;
    *(_QWORD *)dataDesc_237[16].flatOffset = 0;
    dataDesc_237[17].fieldSize = 1;
    *(_QWORD *)&dataDesc_237[17].inputFunc = 0;
    *(_QWORD *)&dataDesc_237[17].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_237[17].override_count = 0;
    *(_QWORD *)dataDesc_237[17].flatOffset = 0;
    *(_DWORD *)&dataDesc_237[15].flatGroup = 0;
    dataDesc_237[16].fieldType = FIELD_CUSTOM;
    dataDesc_237[16].fieldName = "m_Output[5]";
    dataDesc_237[16].fieldOffset = 972;
    dataDesc_237[16].externalName = "OnTrigger6";
    dataDesc_237[16].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_237[16].flatGroup = 0;
    dataDesc_237[17].fieldType = FIELD_CUSTOM;
    dataDesc_237[17].fieldName = "m_Output[6]";
    dataDesc_237[17].fieldOffset = 996;
    dataDesc_237[17].flags = 22;
    dataDesc_237[17].externalName = "OnTrigger7";
    dataDesc_237[17].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_237[17].flatGroup = 0;
    dataDesc_237[18].fieldType = FIELD_CUSTOM;
    dataDesc_237[18].fieldName = "m_Output[7]";
    dataDesc_237[18].fieldOffset = 1020;
    *(_DWORD *)&dataDesc_237[18].fieldSize = 1441793;
    dataDesc_237[18].externalName = "OnTrigger8";
    dataDesc_237[18].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_237[18].inputFunc = 0;
    *(_QWORD *)&dataDesc_237[18].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_237[18].override_count = 0;
    *(_QWORD *)dataDesc_237[18].flatOffset = 0;
    *(_DWORD *)&dataDesc_237[18].flatGroup = 0;
  }
  CLogicRandomOutputs::m_DataMap.dataNumFields = 18;
  CLogicRandomOutputs::m_DataMap.dataDesc = &dataDesc_237[1];
  return &CLogicRandomOutputs::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101679E0
// Name: struct datamap_t __near * DataMapInit<class CLogicAuto>(class CLogicAuto __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CLogicAuto>()
{
  if ( (_S2_148 & 1) == 0 )
  {
    _S2_148 |= 1u;
    nameHolder_251.m_pszBase = "CLogicAuto";
    nameHolder_251.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_251.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_251.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_251.m_Names.m_Size = 0;
    nameHolder_251.m_Names.m_pElements = nullptr;
    nameHolder_251.m_nLenBase = 10;
    atexit(func: DataMapInit_CLogicAuto__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CLogicAuto::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S2_148 & 2) == 0 )
  {
    _S2_148 |= 2u;
    dataDesc_238[3].fieldSize = 1;
    dataDesc_238[3].flags = 22;
    dataDesc_238[4].fieldSize = 1;
    dataDesc_238[4].flags = 22;
    dataDesc_238[5].fieldSize = 1;
    dataDesc_238[5].flags = 22;
    *(_QWORD *)&dataDesc_238[2].inputFunc = 0;
    *(_QWORD *)&dataDesc_238[2].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_238[2].override_count = 0;
    *(_QWORD *)dataDesc_238[2].flatOffset = 0;
    *(_QWORD *)&dataDesc_238[3].inputFunc = 0;
    *(_QWORD *)&dataDesc_238[3].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_238[3].override_count = 0;
    *(_QWORD *)dataDesc_238[3].flatOffset = 0;
    dataDesc_238[6].fieldSize = 1;
    *(_QWORD *)&dataDesc_238[4].inputFunc = 0;
    *(_QWORD *)&dataDesc_238[4].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_238[4].override_count = 0;
    *(_QWORD *)dataDesc_238[4].flatOffset = 0;
    dataDesc_238[6].flags = 22;
    *(_QWORD *)&dataDesc_238[5].inputFunc = 0;
    *(_QWORD *)&dataDesc_238[5].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_238[5].override_count = 0;
    *(_QWORD *)dataDesc_238[5].flatOffset = 0;
    dataDesc_238[7].fieldSize = 1;
    *(_QWORD *)&dataDesc_238[6].inputFunc = 0;
    *(_QWORD *)&dataDesc_238[6].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_238[6].override_count = 0;
    *(_QWORD *)dataDesc_238[6].flatOffset = 0;
    dataDesc_238[2].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_238[2].flatGroup = 0;
    dataDesc_238[3].fieldType = FIELD_CUSTOM;
    dataDesc_238[3].fieldName = "m_OnNewGame";
    dataDesc_238[3].fieldOffset = 876;
    dataDesc_238[3].externalName = "OnNewGame";
    dataDesc_238[3].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_238[3].flatGroup = 0;
    dataDesc_238[4].fieldType = FIELD_CUSTOM;
    dataDesc_238[4].fieldName = "m_OnLoadGame";
    dataDesc_238[4].fieldOffset = 900;
    dataDesc_238[4].externalName = "OnLoadGame";
    dataDesc_238[4].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_238[4].flatGroup = 0;
    dataDesc_238[5].fieldType = FIELD_CUSTOM;
    dataDesc_238[5].fieldName = "m_OnMapTransition";
    dataDesc_238[5].fieldOffset = 924;
    dataDesc_238[5].externalName = "OnMapTransition";
    dataDesc_238[5].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_238[5].flatGroup = 0;
    dataDesc_238[6].fieldType = FIELD_CUSTOM;
    dataDesc_238[6].fieldName = "m_OnBackgroundMap";
    dataDesc_238[6].fieldOffset = 948;
    dataDesc_238[6].externalName = "OnBackgroundMap";
    dataDesc_238[6].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_238[6].flatGroup = 0;
    dataDesc_238[7].fieldType = FIELD_CUSTOM;
    dataDesc_238[7].fieldName = "m_OnMultiNewMap";
    dataDesc_238[7].fieldOffset = 972;
    dataDesc_238[7].flags = 22;
    dataDesc_238[7].externalName = "OnMultiNewMap";
    dataDesc_238[7].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_238[7].inputFunc = 0;
    *(_QWORD *)&dataDesc_238[7].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_238[7].override_count = 0;
    *(_QWORD *)dataDesc_238[7].flatOffset = 0;
    *(_DWORD *)&dataDesc_238[7].flatGroup = 0;
    dataDesc_238[8].fieldType = FIELD_CUSTOM;
    dataDesc_238[8].fieldName = "m_OnMultiNewRound";
    dataDesc_238[8].fieldOffset = 996;
    *(_DWORD *)&dataDesc_238[8].fieldSize = 1441793;
    dataDesc_238[8].externalName = "OnMultiNewRound";
    dataDesc_238[8].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_238[8].inputFunc = 0;
    *(_QWORD *)&dataDesc_238[8].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_238[8].override_count = 0;
    *(_QWORD *)dataDesc_238[8].flatOffset = 0;
    *(_DWORD *)&dataDesc_238[8].flatGroup = 0;
  }
  CLogicAuto::m_DataMap.dataNumFields = 8;
  CLogicAuto::m_DataMap.dataDesc = &dataDesc_238[1];
  return &CLogicAuto::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10167D20
// Name: __CreateCServerGameTagsIServerGameTags_interface_2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CServerGameTags *__cdecl _CreateCServerGameTagsIServerGameTags_interface_2()
{
  return &_g_CServerGameTags_singleton_2;
}

//------------------------------------------------------------------------------
// Address: 0x1016B090
// Name: class CLogicCompareInteger __near * _CreateEntityTemplate<class CLogicCompareInteger>(class CLogicCompareInteger __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CLogicCompareInteger *__cdecl _CreateEntityTemplate<CLogicCompareInteger>(
        CLogicCompareInteger *newEnt,
        const char *className)
{
  CBaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x394u);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: true);
    *v3 = &CLogicCompareInteger::`vftable';
    v3[213] = 0;
    v3[216] = -1;
    v3[217] = 0;
    v3[219] = 0;
    v3[222] = -1;
    v3[223] = 0;
    v3[227] = 0;
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CLogicCompareInteger *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016B950
// Name: class CLogicLineToEntity __near * _CreateEntityTemplate<class CLogicLineToEntity>(class CLogicLineToEntity __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CLogicLineToEntity *__cdecl _CreateEntityTemplate<CLogicLineToEntity>(
        CLogicLineToEntity *newEnt,
        const char *className)
{
  CBaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x378u);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: true);
    *v3 = &CLogicLineToEntity::`vftable';
    v3[213] = 0;
    v3[216] = -1;
    v3[217] = 0;
    v3[220] = -1;
    v3[221] = -1;
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CLogicLineToEntity *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016B9D0
// Name: class CMathRemap __near * _CreateEntityTemplate<class CMathRemap>(class CMathRemap __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMathRemap *__cdecl _CreateEntityTemplate<CMathRemap>(CMathRemap *newEnt, const char *className)
{
  CBaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x380u);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: true);
    *v3 = &CMathRemap::`vftable';
    v3[218] = 0;
    v3[221] = -1;
    v3[222] = 0;
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CMathRemap *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016BA40
// Name: class CMathColorBlend __near * _CreateEntityTemplate<class CMathColorBlend>(class CMathColorBlend __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMathColorBlend *__cdecl _CreateEntityTemplate<CMathColorBlend>(CMathColorBlend *newEnt, const char *className)
{
  CBaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x37Cu);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: true);
    *v3 = &CMathColorBlend::`vftable';
    v3[217] = 0;
    v3[220] = -1;
    v3[221] = 0;
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CMathColorBlend *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016BAB0
// Name: class CEnvGlobal __near * _CreateEntityTemplate<class CEnvGlobal>(class CEnvGlobal __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CEnvGlobal *__cdecl _CreateEntityTemplate<CEnvGlobal>(CEnvGlobal *newEnt, const char *className)
{
  CBaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x37Cu);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: true);
    *v3 = &CEnvGlobal::`vftable';
    v3[213] = 0;
    v3[216] = -1;
    v3[217] = 0;
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CEnvGlobal *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016C1C0
// Name: struct datamap_t __near * DataMapInit<class CLogicScript>(class CLogicScript __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CLogicScript>()
{
  if ( (_S2_149 & 1) == 0 )
  {
    _S2_149 |= 1u;
    nameHolder_252.m_pszBase = "CLogicScript";
    nameHolder_252.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_252.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_252.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_252.m_Names.m_Size = 0;
    nameHolder_252.m_Names.m_pElements = nullptr;
    nameHolder_252.m_nLenBase = 12;
    atexit(func: DataMapInit_CLogicScript__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CLogicScript::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CLogicScript::m_DataMap.dataNumFields = 16;
  CLogicScript::m_DataMap.dataDesc = &dataDesc_239[1];
  return &CLogicScript::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1016C240
// Name: struct datamap_t __near * DataMapInit<class CLogicCompareInteger>(class CLogicCompareInteger __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CLogicCompareInteger>()
{
  if ( (_S3_78 & 1) == 0 )
  {
    _S3_78 |= 1u;
    nameHolder_253.m_pszBase = "CLogicCompareInteger";
    nameHolder_253.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_253.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_253.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_253.m_Names.m_Size = 0;
    nameHolder_253.m_Names.m_pElements = nullptr;
    nameHolder_253.m_nLenBase = 20;
    atexit(func: DataMapInit_CLogicCompareInteger__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CLogicCompareInteger::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S3_78 & 2) == 0 )
  {
    _S3_78 |= 2u;
    dataDesc_240[1].pSaveRestoreOps = eventFuncs;
    dataDesc_240[2].fieldSize = 1;
    dataDesc_240[2].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_240[1].inputFunc = 0;
    *(_QWORD *)&dataDesc_240[1].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_240[1].override_count = 0;
    *(_QWORD *)dataDesc_240[1].flatOffset = 0;
    dataDesc_240[2].flags = 22;
    dataDesc_240[3].fieldSize = 1;
    *(_QWORD *)&dataDesc_240[2].inputFunc = 0;
    *(_QWORD *)&dataDesc_240[2].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_240[2].override_count = 0;
    *(_QWORD *)dataDesc_240[2].flatOffset = 0;
    dataDesc_240[3].fieldType = FIELD_INTEGER;
    dataDesc_240[3].flags = 6;
    dataDesc_240[4].fieldType = FIELD_INTEGER;
    dataDesc_240[3].fieldSizeInBytes = 4;
    dataDesc_240[4].fieldSize = 1;
    dataDesc_240[4].fieldSizeInBytes = 4;
    dataDesc_240[3].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_240[3].flatOffset = 0;
    dataDesc_240[4].fieldTolerance = 0.0;
    dataDesc_240[5].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_240[1].flatGroup = 0;
    dataDesc_240[2].fieldType = FIELD_CUSTOM;
    dataDesc_240[2].fieldName = "m_OnNotEqual";
    dataDesc_240[2].fieldOffset = 876;
    dataDesc_240[2].externalName = "OnNotEqual";
    *(_DWORD *)&dataDesc_240[2].flatGroup = 0;
    dataDesc_240[3].fieldName = "m_iIntegerValue";
    dataDesc_240[3].fieldOffset = 900;
    dataDesc_240[3].externalName = "IntegerValue";
    dataDesc_240[3].pSaveRestoreOps = nullptr;
    dataDesc_240[3].inputFunc = nullptr;
    dataDesc_240[3].td = nullptr;
    dataDesc_240[3].override_field = nullptr;
    dataDesc_240[3].override_count = 0;
    *(_DWORD *)&dataDesc_240[3].flatGroup = 0;
    dataDesc_240[4].fieldName = "m_iShouldCompareToValue";
    dataDesc_240[4].fieldOffset = 904;
    dataDesc_240[4].flags = 6;
    dataDesc_240[4].externalName = "ShouldComparetoValue";
    dataDesc_240[4].pSaveRestoreOps = nullptr;
    dataDesc_240[4].inputFunc = nullptr;
    dataDesc_240[4].td = nullptr;
    dataDesc_240[4].override_field = nullptr;
    dataDesc_240[4].override_count = 0;
    *(_QWORD *)dataDesc_240[4].flatOffset = 0;
    *(_DWORD *)&dataDesc_240[4].flatGroup = 0;
    dataDesc_240[5].fieldType = FIELD_INPUT;
    dataDesc_240[5].fieldName = "m_AllIntCompares";
    dataDesc_240[5].fieldOffset = 908;
    dataDesc_240[5].fieldSize = 1;
    dataDesc_240[5].flags = 2;
    dataDesc_240[5].externalName = nullptr;
    dataDesc_240[5].pSaveRestoreOps = nullptr;
    dataDesc_240[5].inputFunc = nullptr;
    dataDesc_240[5].td = nullptr;
    dataDesc_240[5].fieldSizeInBytes = 8;
    dataDesc_240[5].override_field = nullptr;
    dataDesc_240[5].override_count = 0;
    *(_QWORD *)dataDesc_240[5].flatOffset = 0;
    *(_DWORD *)&dataDesc_240[5].flatGroup = 0;
    dataDesc_240[6].fieldType = FIELD_INPUT;
    *(_QWORD *)&dataDesc_240[6].td = 0;
    *(_QWORD *)&dataDesc_240[6].override_field = 0;
    *(_QWORD *)&dataDesc_240[6].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_240[6].flatOffset[1] = 0;
    dataDesc_240[6].fieldName = "InputValue";
    dataDesc_240[6].fieldOffset = 0;
    dataDesc_240[6].fieldSize = 1;
    dataDesc_240[6].flags = 8;
    dataDesc_240[6].externalName = "InputValue";
    dataDesc_240[6].pSaveRestoreOps = nullptr;
    dataDesc_240[6].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CLogicCompareInteger::InputValue;
    dataDesc_240[7].fieldType = FIELD_INPUT;
    dataDesc_240[7].fieldName = "InputCompareValues";
    dataDesc_240[7].fieldOffset = 0;
    *(_DWORD *)&dataDesc_240[7].fieldSize = 524289;
    dataDesc_240[7].externalName = "CompareValues";
    dataDesc_240[7].pSaveRestoreOps = nullptr;
    dataDesc_240[7].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CLogicCompareInteger::InputCompareValues;
    *(_QWORD *)&dataDesc_240[7].td = 0;
    *(_QWORD *)&dataDesc_240[7].override_field = 0;
    *(_QWORD *)&dataDesc_240[7].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_240[7].flatOffset[1] = 0;
  }
  CLogicCompareInteger::m_DataMap.dataNumFields = 7;
  CLogicCompareInteger::m_DataMap.dataDesc = &dataDesc_240[1];
  return &CLogicCompareInteger::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1016C5A0
// Name: struct datamap_t __near * DataMapInit<class CLogicRegisterActivator>(class CLogicRegisterActivator __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CLogicRegisterActivator>()
{
  if ( (_S4_38 & 1) == 0 )
  {
    _S4_38 |= 1u;
    nameHolder_254.m_pszBase = "CLogicRegisterActivator";
    nameHolder_254.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_254.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_254.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_254.m_Names.m_Size = 0;
    nameHolder_254.m_Names.m_pElements = nullptr;
    nameHolder_254.m_nLenBase = 23;
    atexit(func: DataMapInit_CLogicRegisterActivator__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CLogicRegisterActivator::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S4_38 & 2) == 0 )
  {
    _S4_38 |= 2u;
    dataDesc_241[12].fieldSize = 1;
    *(_QWORD *)&dataDesc_241[11].inputFunc = 0;
    *(_QWORD *)&dataDesc_241[11].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_241[11].override_count = 0;
    *(_QWORD *)dataDesc_241[11].flatOffset = 0;
    dataDesc_241[12].flags = 22;
    *(_QWORD *)&dataDesc_241[12].inputFunc = 0;
    *(_QWORD *)&dataDesc_241[12].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_241[12].override_count = 0;
    *(_QWORD *)dataDesc_241[12].flatOffset = 0;
    dataDesc_241[13].fieldSize = 1;
    *(_QWORD *)&dataDesc_241[13].inputFunc = 0;
    *(_QWORD *)&dataDesc_241[13].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_241[13].override_count = 0;
    *(_QWORD *)dataDesc_241[13].flatOffset = 0;
    dataDesc_241[11].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_241[11].flatGroup = 0;
    dataDesc_241[12].fieldType = FIELD_CUSTOM;
    dataDesc_241[12].fieldName = "m_OnRegisteredActivate2";
    dataDesc_241[12].fieldOffset = 876;
    dataDesc_241[12].externalName = "OnRegisteredActivate2";
    dataDesc_241[12].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_241[12].flatGroup = 0;
    dataDesc_241[13].fieldType = FIELD_CUSTOM;
    dataDesc_241[13].fieldName = "m_OnRegisteredActivate3";
    dataDesc_241[13].fieldOffset = 900;
    dataDesc_241[13].flags = 22;
    dataDesc_241[13].externalName = "OnRegisteredActivate3";
    dataDesc_241[13].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_241[13].flatGroup = 0;
    dataDesc_241[14].fieldType = FIELD_CUSTOM;
    dataDesc_241[14].fieldName = "m_OnRegisteredActivate4";
    dataDesc_241[14].fieldOffset = 924;
    *(_DWORD *)&dataDesc_241[14].fieldSize = 1441793;
    dataDesc_241[14].externalName = "OnRegisteredActivate4";
    dataDesc_241[14].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_241[14].inputFunc = 0;
    *(_QWORD *)&dataDesc_241[14].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_241[14].override_count = 0;
    *(_QWORD *)dataDesc_241[14].flatOffset = 0;
    *(_DWORD *)&dataDesc_241[14].flatGroup = 0;
  }
  CLogicRegisterActivator::m_DataMap.dataNumFields = 14;
  CLogicRegisterActivator::m_DataMap.dataDesc = &dataDesc_241[1];
  return &CLogicRegisterActivator::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1016C7A0
// Name: struct datamap_t __near * DataMapInit<class CTimerEntity>(class CTimerEntity __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CTimerEntity>()
{
  if ( (_S5_18 & 1) == 0 )
  {
    _S5_18 |= 1u;
    nameHolder_255.m_pszBase = "CTimerEntity";
    nameHolder_255.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_255.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_255.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_255.m_Names.m_Size = 0;
    nameHolder_255.m_Names.m_pElements = nullptr;
    nameHolder_255.m_nLenBase = 12;
    atexit(func: DataMapInit_CTimerEntity__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CTimerEntity::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S5_18 & 2) == 0 )
  {
    _S5_18 |= 2u;
    *(_QWORD *)&dataDesc_242[15].inputFunc = 0;
    *(_QWORD *)&dataDesc_242[15].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_242[15].override_count = 0;
    *(_QWORD *)dataDesc_242[15].flatOffset = 0;
    dataDesc_242[16].fieldSize = 1;
    *(_QWORD *)&dataDesc_242[16].inputFunc = 0;
    *(_QWORD *)&dataDesc_242[16].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_242[16].override_count = 0;
    *(_QWORD *)dataDesc_242[16].flatOffset = 0;
    dataDesc_242[15].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_242[15].flatGroup = 0;
    dataDesc_242[16].fieldType = FIELD_CUSTOM;
    dataDesc_242[16].fieldName = "m_OnTimerHigh";
    dataDesc_242[16].fieldOffset = 876;
    dataDesc_242[16].flags = 22;
    dataDesc_242[16].externalName = "OnTimerHigh";
    dataDesc_242[16].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_242[16].flatGroup = 0;
    dataDesc_242[17].fieldType = FIELD_CUSTOM;
    dataDesc_242[17].fieldName = "m_OnTimerLow";
    dataDesc_242[17].fieldOffset = 900;
    *(_DWORD *)&dataDesc_242[17].fieldSize = 1441793;
    dataDesc_242[17].externalName = "OnTimerLow";
    dataDesc_242[17].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_242[17].inputFunc = 0;
    *(_QWORD *)&dataDesc_242[17].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_242[17].override_count = 0;
    *(_QWORD *)dataDesc_242[17].flatOffset = 0;
    *(_DWORD *)&dataDesc_242[17].flatGroup = 0;
  }
  CTimerEntity::m_DataMap.dataNumFields = 17;
  CTimerEntity::m_DataMap.dataDesc = &dataDesc_242[1];
  return &CTimerEntity::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1016C940
// Name: struct datamap_t __near * DataMapInit<class CLogicLineToEntity>(class CLogicLineToEntity __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CLogicLineToEntity>()
{
  if ( (_S6_13 & 1) == 0 )
  {
    _S6_13 |= 1u;
    nameHolder_256.m_pszBase = "CLogicLineToEntity";
    nameHolder_256.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_256.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_256.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_256.m_Names.m_Size = 0;
    nameHolder_256.m_Names.m_pElements = nullptr;
    nameHolder_256.m_nLenBase = 18;
    atexit(func: DataMapInit_CLogicLineToEntity__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CLogicLineToEntity::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S6_13 & 2) == 0 )
  {
    _S6_13 |= 2u;
    dataDesc_243[4].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_243[4].inputFunc = 0;
    *(_QWORD *)&dataDesc_243[4].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_243[4].override_count = 0;
    *(_QWORD *)dataDesc_243[4].flatOffset = 0;
    *(_DWORD *)&dataDesc_243[4].flatGroup = 0;
  }
  CLogicLineToEntity::m_DataMap.dataNumFields = 4;
  CLogicLineToEntity::m_DataMap.dataDesc = &dataDesc_243[1];
  return &CLogicLineToEntity::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1016CA10
// Name: struct datamap_t __near * DataMapInit<class CMathRemap>(class CMathRemap __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CMathRemap>()
{
  if ( (_S7_6 & 1) == 0 )
  {
    _S7_6 |= 1u;
    nameHolder_257.m_pszBase = "CMathRemap";
    nameHolder_257.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_257.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_257.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_257.m_Names.m_Size = 0;
    nameHolder_257.m_Names.m_pElements = nullptr;
    nameHolder_257.m_nLenBase = 10;
    atexit(func: DataMapInit_CMathRemap__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CMathRemap::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S7_6 & 2) == 0 )
  {
    _S7_6 |= 2u;
    dataDesc_244[3].fieldSize = 1;
    dataDesc_244[4].fieldSize = 1;
    dataDesc_244[4].flags = 6;
    dataDesc_244[5].fieldSize = 1;
    *(_QWORD *)dataDesc_244[3].flatOffset = 0;
    dataDesc_244[2].pSaveRestoreOps = eventFuncs;
    dataDesc_244[5].flags = 6;
    *(_QWORD *)dataDesc_244[4].flatOffset = 0;
    dataDesc_244[3].flags = 6;
    dataDesc_244[6].fieldSize = 1;
    *(_QWORD *)&dataDesc_244[2].inputFunc = 0;
    *(_QWORD *)&dataDesc_244[2].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_244[2].override_count = 0;
    *(_QWORD *)dataDesc_244[2].flatOffset = 0;
    *(_QWORD *)dataDesc_244[5].flatOffset = 0;
    *(_DWORD *)&dataDesc_244[2].flatGroup = 0;
    dataDesc_244[3].fieldType = FIELD_FLOAT;
    dataDesc_244[3].fieldName = "m_flInMin";
    dataDesc_244[3].fieldOffset = 852;
    dataDesc_244[3].externalName = "in1";
    dataDesc_244[3].pSaveRestoreOps = nullptr;
    dataDesc_244[3].inputFunc = nullptr;
    dataDesc_244[3].td = nullptr;
    dataDesc_244[3].fieldSizeInBytes = 4;
    dataDesc_244[3].override_field = nullptr;
    dataDesc_244[3].override_count = 0;
    dataDesc_244[3].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_244[3].flatGroup = 0;
    dataDesc_244[4].fieldType = FIELD_FLOAT;
    dataDesc_244[4].fieldName = "m_flInMax";
    dataDesc_244[4].fieldOffset = 856;
    dataDesc_244[4].externalName = "in2";
    dataDesc_244[4].pSaveRestoreOps = nullptr;
    dataDesc_244[4].inputFunc = nullptr;
    dataDesc_244[4].td = nullptr;
    dataDesc_244[4].fieldSizeInBytes = 4;
    dataDesc_244[4].override_field = nullptr;
    dataDesc_244[4].override_count = 0;
    dataDesc_244[4].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_244[4].flatGroup = 0;
    dataDesc_244[5].fieldType = FIELD_FLOAT;
    dataDesc_244[5].fieldName = "m_flOut1";
    dataDesc_244[5].fieldOffset = 860;
    dataDesc_244[5].externalName = "out1";
    dataDesc_244[5].pSaveRestoreOps = nullptr;
    dataDesc_244[5].inputFunc = nullptr;
    dataDesc_244[5].td = nullptr;
    dataDesc_244[5].fieldSizeInBytes = 4;
    dataDesc_244[5].override_field = nullptr;
    dataDesc_244[5].override_count = 0;
    dataDesc_244[5].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_244[5].flatGroup = 0;
    dataDesc_244[6].fieldType = FIELD_FLOAT;
    dataDesc_244[6].fieldName = "m_flOut2";
    dataDesc_244[6].fieldOffset = 864;
    dataDesc_244[6].flags = 6;
    dataDesc_244[6].externalName = "out2";
    dataDesc_244[6].pSaveRestoreOps = nullptr;
    dataDesc_244[6].inputFunc = nullptr;
    dataDesc_244[6].td = nullptr;
    dataDesc_244[6].fieldSizeInBytes = 4;
    dataDesc_244[6].override_field = nullptr;
    dataDesc_244[6].override_count = 0;
    dataDesc_244[6].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_244[6].flatOffset = 0;
    dataDesc_244[7].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_244[7].flatOffset = 0;
    dataDesc_244[7].fieldType = FIELD_BOOLEAN;
    dataDesc_244[7].flags = 2;
    *(_QWORD *)&dataDesc_244[8].td = 0;
    *(_QWORD *)&dataDesc_244[8].override_field = 0;
    *(_QWORD *)&dataDesc_244[8].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_244[8].flatOffset[1] = 0;
    *(_DWORD *)&dataDesc_244[6].flatGroup = 0;
    dataDesc_244[7].fieldName = "m_bEnabled";
    dataDesc_244[7].fieldOffset = 868;
    dataDesc_244[7].fieldSize = 1;
    dataDesc_244[7].externalName = nullptr;
    dataDesc_244[7].pSaveRestoreOps = nullptr;
    dataDesc_244[7].inputFunc = nullptr;
    dataDesc_244[7].td = nullptr;
    dataDesc_244[7].fieldSizeInBytes = 1;
    dataDesc_244[7].override_field = nullptr;
    dataDesc_244[7].override_count = 0;
    *(_DWORD *)&dataDesc_244[7].flatGroup = 0;
    dataDesc_244[8].fieldType = FIELD_VOID;
    dataDesc_244[8].fieldName = "InputEnable";
    dataDesc_244[8].fieldOffset = 0;
    dataDesc_244[8].fieldSize = 1;
    dataDesc_244[8].flags = 8;
    dataDesc_244[8].externalName = "Enable";
    dataDesc_244[8].pSaveRestoreOps = nullptr;
    dataDesc_244[8].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CLogicEventListener::InputEnable;
    dataDesc_244[9].fieldType = FIELD_VOID;
    dataDesc_244[9].fieldName = "InputDisable";
    dataDesc_244[9].fieldOffset = 0;
    *(_DWORD *)&dataDesc_244[9].fieldSize = 524289;
    dataDesc_244[9].externalName = "Disable";
    dataDesc_244[9].pSaveRestoreOps = nullptr;
    dataDesc_244[9].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CLogicEventListener::InputDisable;
    *(_QWORD *)&dataDesc_244[9].td = 0;
    *(_QWORD *)&dataDesc_244[9].override_field = 0;
    *(_QWORD *)&dataDesc_244[9].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_244[9].flatOffset[1] = 0;
  }
  CMathRemap::m_DataMap.dataNumFields = 9;
  CMathRemap::m_DataMap.dataDesc = &dataDesc_244[1];
  return &CMathRemap::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1016CE00
// Name: struct datamap_t __near * DataMapInit<class CMathColorBlend>(class CMathColorBlend __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CMathColorBlend>()
{
  if ( (_S8_4 & 1) == 0 )
  {
    _S8_4 |= 1u;
    nameHolder_258.m_pszBase = "CMathColorBlend";
    nameHolder_258.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_258.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_258.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_258.m_Names.m_Size = 0;
    nameHolder_258.m_Names.m_pElements = nullptr;
    nameHolder_258.m_nLenBase = 15;
    atexit(func: DataMapInit_CMathColorBlend__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CMathColorBlend::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S8_4 & 2) == 0 )
  {
    _S8_4 |= 2u;
    *(_QWORD *)&dataDesc_245[2].inputFunc = 0;
    *(_QWORD *)&dataDesc_245[2].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_245[2].override_count = 0;
    *(_QWORD *)dataDesc_245[2].flatOffset = 0;
    dataDesc_245[3].flags = 6;
    dataDesc_245[4].flags = 6;
    *(_QWORD *)dataDesc_245[3].flatOffset = 0;
    dataDesc_245[2].pSaveRestoreOps = eventFuncs;
    dataDesc_245[3].fieldSize = 1;
    dataDesc_245[4].fieldSize = 1;
    dataDesc_245[5].fieldSize = 1;
    dataDesc_245[3].fieldTolerance = 0.0;
    dataDesc_245[4].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_245[4].flatOffset = 0;
    dataDesc_245[5].fieldTolerance = 0.0;
    dataDesc_245[6].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_245[2].flatGroup = 0;
    dataDesc_245[3].fieldType = FIELD_FLOAT;
    dataDesc_245[3].fieldName = "m_flInMin";
    dataDesc_245[3].fieldOffset = 852;
    dataDesc_245[3].externalName = "inmin";
    dataDesc_245[3].pSaveRestoreOps = nullptr;
    dataDesc_245[3].inputFunc = nullptr;
    dataDesc_245[3].td = nullptr;
    dataDesc_245[3].fieldSizeInBytes = 4;
    dataDesc_245[3].override_field = nullptr;
    dataDesc_245[3].override_count = 0;
    *(_DWORD *)&dataDesc_245[3].flatGroup = 0;
    dataDesc_245[4].fieldType = FIELD_FLOAT;
    dataDesc_245[4].fieldName = "m_flInMax";
    dataDesc_245[4].fieldOffset = 856;
    dataDesc_245[4].externalName = "inmax";
    dataDesc_245[4].pSaveRestoreOps = nullptr;
    dataDesc_245[4].inputFunc = nullptr;
    dataDesc_245[4].td = nullptr;
    dataDesc_245[4].fieldSizeInBytes = 4;
    dataDesc_245[4].override_field = nullptr;
    dataDesc_245[4].override_count = 0;
    *(_DWORD *)&dataDesc_245[4].flatGroup = 0;
    dataDesc_245[5].fieldType = FIELD_COLOR32;
    dataDesc_245[5].fieldName = "m_OutColor1";
    dataDesc_245[5].fieldOffset = 860;
    dataDesc_245[5].flags = 6;
    dataDesc_245[5].externalName = "colormin";
    dataDesc_245[5].pSaveRestoreOps = nullptr;
    dataDesc_245[5].inputFunc = nullptr;
    dataDesc_245[5].td = nullptr;
    dataDesc_245[5].fieldSizeInBytes = 4;
    dataDesc_245[5].override_field = nullptr;
    dataDesc_245[5].override_count = 0;
    *(_QWORD *)dataDesc_245[5].flatOffset = 0;
    *(_DWORD *)&dataDesc_245[5].flatGroup = 0;
    dataDesc_245[6].fieldType = FIELD_COLOR32;
    dataDesc_245[6].fieldName = "m_OutColor2";
    dataDesc_245[6].fieldOffset = 864;
    *(_DWORD *)&dataDesc_245[6].fieldSize = 393217;
    dataDesc_245[6].externalName = "colormax";
    dataDesc_245[6].pSaveRestoreOps = nullptr;
    dataDesc_245[6].inputFunc = nullptr;
    dataDesc_245[6].td = nullptr;
    dataDesc_245[6].fieldSizeInBytes = 4;
    dataDesc_245[6].override_field = nullptr;
    dataDesc_245[6].override_count = 0;
    *(_QWORD *)dataDesc_245[6].flatOffset = 0;
    *(_DWORD *)&dataDesc_245[6].flatGroup = 0;
  }
  CMathColorBlend::m_DataMap.dataNumFields = 6;
  CMathColorBlend::m_DataMap.dataDesc = &dataDesc_245[1];
  return &CMathColorBlend::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1016D0A0
// Name: struct datamap_t __near * DataMapInit<class CEnvGlobal>(class CEnvGlobal __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CEnvGlobal>()
{
  if ( (_S9_3 & 1) == 0 )
  {
    _S9_3 |= 1u;
    nameHolder_259.m_pszBase = "CEnvGlobal";
    nameHolder_259.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_259.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_259.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_259.m_Names.m_Size = 0;
    nameHolder_259.m_Names.m_pElements = nullptr;
    nameHolder_259.m_nLenBase = 10;
    atexit(func: DataMapInit_CEnvGlobal__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CEnvGlobal::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S9_3 & 2) == 0 )
  {
    _S9_3 |= 2u;
    dataDesc_246[12].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_246[12].inputFunc = 0;
    *(_QWORD *)&dataDesc_246[12].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_246[12].override_count = 0;
    *(_QWORD *)dataDesc_246[12].flatOffset = 0;
    *(_DWORD *)&dataDesc_246[12].flatGroup = 0;
  }
  CEnvGlobal::m_DataMap.dataNumFields = 12;
  CEnvGlobal::m_DataMap.dataDesc = &dataDesc_246[1];
  return &CEnvGlobal::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1016D170
// Name: struct datamap_t __near * DataMapInit<class CMultiSource>(class CMultiSource __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CMultiSource>()
{
  if ( (_S10_2 & 1) == 0 )
  {
    _S10_2 |= 1u;
    nameHolder_260.m_pszBase = "CMultiSource";
    nameHolder_260.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_260.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_260.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_260.m_Names.m_Size = 0;
    nameHolder_260.m_Names.m_pElements = nullptr;
    nameHolder_260.m_nLenBase = 12;
    atexit(func: DataMapInit_CMultiSource__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CMultiSource::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S10_2 & 2) == 0 )
  {
    _S10_2 |= 2u;
    dataDesc_247[5].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_260,
                                  pszIdentifier: "Register");
    dataDesc_247[5].fieldSize = 1;
    *(_QWORD *)&dataDesc_247[5].td = 0;
    *(_QWORD *)&dataDesc_247[5].override_field = 0;
    *(_QWORD *)&dataDesc_247[5].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_247[5].flatOffset[1] = 0;
    dataDesc_247[5].fieldOffset = 0;
    dataDesc_247[5].flags = 32;
    dataDesc_247[5].externalName = nullptr;
    dataDesc_247[5].pSaveRestoreOps = nullptr;
    dataDesc_247[5].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CMultiSource::Register;
    dataDesc_247[6].fieldType = FIELD_CUSTOM;
    dataDesc_247[6].fieldName = "m_OnTrigger";
    dataDesc_247[6].fieldOffset = 1108;
    *(_DWORD *)&dataDesc_247[6].fieldSize = 1441793;
    dataDesc_247[6].externalName = "OnTrigger";
    dataDesc_247[6].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_247[6].inputFunc = 0;
    *(_QWORD *)&dataDesc_247[6].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_247[6].override_count = 0;
    *(_QWORD *)dataDesc_247[6].flatOffset = 0;
    *(_DWORD *)&dataDesc_247[6].flatGroup = 0;
  }
  CMultiSource::m_DataMap.dataNumFields = 6;
  CMultiSource::m_DataMap.dataDesc = &dataDesc_247[1];
  return &CMultiSource::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1016D2E0
// Name: struct datamap_t __near * DataMapInit<class CMathCounter>(class CMathCounter __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CMathCounter>()
{
  if ( (_S11_2 & 1) == 0 )
  {
    _S11_2 |= 1u;
    nameHolder_261.m_pszBase = "CMathCounter";
    nameHolder_261.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_261.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_261.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_261.m_Names.m_Size = 0;
    nameHolder_261.m_Names.m_pElements = nullptr;
    nameHolder_261.m_nLenBase = 12;
    atexit(func: DataMapInit_CMathCounter__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CMathCounter::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S11_2 & 2) == 0 )
  {
    _S11_2 |= 2u;
    dataDesc_248[20].fieldSize = 1;
    dataDesc_248[20].flags = 22;
    dataDesc_248[21].fieldSize = 1;
    dataDesc_248[21].flags = 22;
    *(_QWORD *)&dataDesc_248[19].inputFunc = 0;
    *(_QWORD *)&dataDesc_248[19].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_248[19].override_count = 0;
    *(_QWORD *)dataDesc_248[19].flatOffset = 0;
    *(_QWORD *)&dataDesc_248[20].inputFunc = 0;
    *(_QWORD *)&dataDesc_248[20].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_248[20].override_count = 0;
    *(_QWORD *)dataDesc_248[20].flatOffset = 0;
    dataDesc_248[22].fieldSize = 1;
    *(_QWORD *)&dataDesc_248[21].inputFunc = 0;
    *(_QWORD *)&dataDesc_248[21].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_248[21].override_count = 0;
    *(_QWORD *)dataDesc_248[21].flatOffset = 0;
    dataDesc_248[22].flags = 22;
    *(_QWORD *)&dataDesc_248[22].inputFunc = 0;
    *(_QWORD *)&dataDesc_248[22].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_248[22].override_count = 0;
    *(_QWORD *)dataDesc_248[22].flatOffset = 0;
    dataDesc_248[23].fieldSize = 1;
    *(_QWORD *)&dataDesc_248[23].inputFunc = 0;
    *(_QWORD *)&dataDesc_248[23].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_248[23].override_count = 0;
    *(_QWORD *)dataDesc_248[23].flatOffset = 0;
    dataDesc_248[19].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_248[19].flatGroup = 0;
    dataDesc_248[20].fieldType = FIELD_CUSTOM;
    dataDesc_248[20].fieldName = "m_OnHitMin";
    dataDesc_248[20].fieldOffset = 912;
    dataDesc_248[20].externalName = "OnHitMin";
    dataDesc_248[20].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_248[20].flatGroup = 0;
    dataDesc_248[21].fieldType = FIELD_CUSTOM;
    dataDesc_248[21].fieldName = "m_OnHitMax";
    dataDesc_248[21].fieldOffset = 936;
    dataDesc_248[21].externalName = "OnHitMax";
    dataDesc_248[21].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_248[21].flatGroup = 0;
    dataDesc_248[22].fieldType = FIELD_CUSTOM;
    dataDesc_248[22].fieldName = "m_OnChangedFromMin";
    dataDesc_248[22].fieldOffset = 960;
    dataDesc_248[22].externalName = "OnChangedFromMin";
    dataDesc_248[22].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_248[22].flatGroup = 0;
    dataDesc_248[23].fieldType = FIELD_CUSTOM;
    dataDesc_248[23].fieldName = "m_OnChangedFromMax";
    dataDesc_248[23].fieldOffset = 984;
    dataDesc_248[23].flags = 22;
    dataDesc_248[23].externalName = "OnChangedFromMax";
    dataDesc_248[23].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_248[23].flatGroup = 0;
    dataDesc_248[24].fieldType = FIELD_CUSTOM;
    dataDesc_248[24].fieldName = "m_OnGetValue";
    dataDesc_248[24].fieldOffset = 888;
    *(_DWORD *)&dataDesc_248[24].fieldSize = 1441793;
    dataDesc_248[24].externalName = "OnGetValue";
    dataDesc_248[24].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_248[24].inputFunc = 0;
    *(_QWORD *)&dataDesc_248[24].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_248[24].override_count = 0;
    *(_QWORD *)dataDesc_248[24].flatOffset = 0;
    *(_DWORD *)&dataDesc_248[24].flatGroup = 0;
  }
  CMathCounter::m_DataMap.dataNumFields = 24;
  CMathCounter::m_DataMap.dataDesc = &dataDesc_248[1];
  return &CMathCounter::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1016D5B0
// Name: struct datamap_t __near * DataMapInit<class CLogicCase>(class CLogicCase __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CLogicCase>()
{
  if ( (_S12_1 & 1) == 0 )
  {
    _S12_1 |= 1u;
    nameHolder_262.m_pszBase = "CLogicCase";
    nameHolder_262.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_262.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_262.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_262.m_Names.m_Size = 0;
    nameHolder_262.m_Names.m_pElements = nullptr;
    nameHolder_262.m_nLenBase = 10;
    atexit(func: DataMapInit_CLogicCase__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CLogicCase::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S12_1 & 2) == 0 )
  {
    _S12_1 |= 2u;
    dataDesc_249[24].fieldSize = 1;
    dataDesc_249[24].flags = 22;
    dataDesc_249[25].fieldSize = 1;
    dataDesc_249[25].flags = 22;
    dataDesc_249[26].fieldSize = 1;
    dataDesc_249[26].flags = 22;
    *(_QWORD *)&dataDesc_249[23].inputFunc = 0;
    *(_QWORD *)&dataDesc_249[23].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_249[23].override_count = 0;
    *(_QWORD *)dataDesc_249[23].flatOffset = 0;
    *(_QWORD *)&dataDesc_249[24].inputFunc = 0;
    *(_QWORD *)&dataDesc_249[24].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_249[24].override_count = 0;
    *(_QWORD *)dataDesc_249[24].flatOffset = 0;
    dataDesc_249[27].fieldSize = 1;
    *(_QWORD *)&dataDesc_249[25].inputFunc = 0;
    *(_QWORD *)&dataDesc_249[25].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_249[25].override_count = 0;
    *(_QWORD *)dataDesc_249[25].flatOffset = 0;
    dataDesc_249[27].flags = 22;
    *(_QWORD *)&dataDesc_249[26].inputFunc = 0;
    *(_QWORD *)&dataDesc_249[26].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_249[26].override_count = 0;
    *(_QWORD *)dataDesc_249[26].flatOffset = 0;
    dataDesc_249[28].fieldSize = 1;
    *(_QWORD *)&dataDesc_249[27].inputFunc = 0;
    *(_QWORD *)&dataDesc_249[27].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_249[27].override_count = 0;
    *(_QWORD *)dataDesc_249[27].flatOffset = 0;
    dataDesc_249[23].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_249[23].flatGroup = 0;
    dataDesc_249[24].fieldType = FIELD_CUSTOM;
    dataDesc_249[24].fieldName = "m_OnCase[1]";
    dataDesc_249[24].fieldOffset = 964;
    dataDesc_249[24].externalName = "OnCase02";
    dataDesc_249[24].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_249[24].flatGroup = 0;
    dataDesc_249[25].fieldType = FIELD_CUSTOM;
    dataDesc_249[25].fieldName = "m_OnCase[2]";
    dataDesc_249[25].fieldOffset = 988;
    dataDesc_249[25].externalName = "OnCase03";
    dataDesc_249[25].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_249[25].flatGroup = 0;
    dataDesc_249[26].fieldType = FIELD_CUSTOM;
    dataDesc_249[26].fieldName = "m_OnCase[3]";
    dataDesc_249[26].fieldOffset = 1012;
    dataDesc_249[26].externalName = "OnCase04";
    dataDesc_249[26].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_249[26].flatGroup = 0;
    dataDesc_249[27].fieldType = FIELD_CUSTOM;
    dataDesc_249[27].fieldName = "m_OnCase[4]";
    dataDesc_249[27].fieldOffset = 1036;
    dataDesc_249[27].externalName = "OnCase05";
    dataDesc_249[27].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_249[27].flatGroup = 0;
    dataDesc_249[28].fieldType = FIELD_CUSTOM;
    dataDesc_249[28].fieldName = "m_OnCase[5]";
    dataDesc_249[28].fieldOffset = 1060;
    dataDesc_249[28].flags = 22;
    dataDesc_249[28].externalName = "OnCase06";
    dataDesc_249[28].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_249[28].inputFunc = 0;
    dataDesc_249[29].fieldSize = 1;
    dataDesc_249[29].flags = 22;
    dataDesc_249[30].fieldSize = 1;
    dataDesc_249[30].flags = 22;
    dataDesc_249[31].fieldSize = 1;
    dataDesc_249[31].flags = 22;
    *(_QWORD *)&dataDesc_249[28].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_249[28].override_count = 0;
    *(_QWORD *)dataDesc_249[28].flatOffset = 0;
    *(_QWORD *)&dataDesc_249[29].inputFunc = 0;
    *(_QWORD *)&dataDesc_249[29].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_249[29].override_count = 0;
    *(_QWORD *)dataDesc_249[29].flatOffset = 0;
    dataDesc_249[32].fieldSize = 1;
    *(_QWORD *)&dataDesc_249[30].inputFunc = 0;
    *(_QWORD *)&dataDesc_249[30].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_249[30].override_count = 0;
    *(_QWORD *)dataDesc_249[30].flatOffset = 0;
    dataDesc_249[32].flags = 22;
    *(_QWORD *)&dataDesc_249[31].inputFunc = 0;
    *(_QWORD *)&dataDesc_249[31].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_249[31].override_count = 0;
    *(_QWORD *)dataDesc_249[31].flatOffset = 0;
    dataDesc_249[33].fieldSize = 1;
    *(_QWORD *)&dataDesc_249[32].inputFunc = 0;
    *(_QWORD *)&dataDesc_249[32].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_249[32].override_count = 0;
    *(_QWORD *)dataDesc_249[32].flatOffset = 0;
    *(_DWORD *)&dataDesc_249[28].flatGroup = 0;
    dataDesc_249[29].fieldType = FIELD_CUSTOM;
    dataDesc_249[29].fieldName = "m_OnCase[6]";
    dataDesc_249[29].fieldOffset = 1084;
    dataDesc_249[29].externalName = "OnCase07";
    dataDesc_249[29].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_249[29].flatGroup = 0;
    dataDesc_249[30].fieldType = FIELD_CUSTOM;
    dataDesc_249[30].fieldName = "m_OnCase[7]";
    dataDesc_249[30].fieldOffset = 1108;
    dataDesc_249[30].externalName = "OnCase08";
    dataDesc_249[30].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_249[30].flatGroup = 0;
    dataDesc_249[31].fieldType = FIELD_CUSTOM;
    dataDesc_249[31].fieldName = "m_OnCase[8]";
    dataDesc_249[31].fieldOffset = 1132;
    dataDesc_249[31].externalName = "OnCase09";
    dataDesc_249[31].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_249[31].flatGroup = 0;
    dataDesc_249[32].fieldType = FIELD_CUSTOM;
    dataDesc_249[32].fieldName = "m_OnCase[9]";
    dataDesc_249[32].fieldOffset = 1156;
    dataDesc_249[32].externalName = "OnCase10";
    dataDesc_249[32].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_249[32].flatGroup = 0;
    dataDesc_249[33].fieldType = FIELD_CUSTOM;
    dataDesc_249[33].fieldName = "m_OnCase[10]";
    dataDesc_249[33].fieldOffset = 1180;
    dataDesc_249[33].flags = 22;
    dataDesc_249[33].externalName = "OnCase11";
    dataDesc_249[33].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_249[33].inputFunc = 0;
    *(_QWORD *)&dataDesc_249[33].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_249[33].override_count = 0;
    *(_QWORD *)dataDesc_249[33].flatOffset = 0;
    *(_DWORD *)&dataDesc_249[33].flatGroup = 0;
    dataDesc_249[34].fieldType = FIELD_CUSTOM;
    dataDesc_249[34].fieldName = "m_OnCase[11]";
    dataDesc_249[34].fieldSize = 1;
    dataDesc_249[34].flags = 22;
    dataDesc_249[35].fieldSize = 1;
    dataDesc_249[35].flags = 22;
    dataDesc_249[36].fieldSize = 1;
    dataDesc_249[36].flags = 22;
    *(_QWORD *)&dataDesc_249[34].inputFunc = 0;
    *(_QWORD *)&dataDesc_249[34].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_249[34].override_count = 0;
    *(_QWORD *)dataDesc_249[34].flatOffset = 0;
    *(_QWORD *)&dataDesc_249[35].inputFunc = 0;
    *(_QWORD *)&dataDesc_249[35].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_249[35].override_count = 0;
    *(_QWORD *)dataDesc_249[35].flatOffset = 0;
    dataDesc_249[37].fieldSize = 1;
    *(_QWORD *)&dataDesc_249[36].inputFunc = 0;
    *(_QWORD *)&dataDesc_249[36].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_249[36].override_count = 0;
    *(_QWORD *)dataDesc_249[36].flatOffset = 0;
    dataDesc_249[37].flags = 22;
    *(_QWORD *)&dataDesc_249[37].inputFunc = 0;
    *(_QWORD *)&dataDesc_249[37].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_249[37].override_count = 0;
    *(_QWORD *)dataDesc_249[37].flatOffset = 0;
    dataDesc_249[38].fieldSize = 1;
    *(_QWORD *)&dataDesc_249[38].inputFunc = 0;
    *(_QWORD *)&dataDesc_249[38].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_249[38].override_count = 0;
    *(_QWORD *)dataDesc_249[38].flatOffset = 0;
    dataDesc_249[34].fieldOffset = 1204;
    dataDesc_249[34].externalName = "OnCase12";
    dataDesc_249[34].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_249[34].flatGroup = 0;
    dataDesc_249[35].fieldType = FIELD_CUSTOM;
    dataDesc_249[35].fieldName = "m_OnCase[12]";
    dataDesc_249[35].fieldOffset = 1228;
    dataDesc_249[35].externalName = "OnCase13";
    dataDesc_249[35].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_249[35].flatGroup = 0;
    dataDesc_249[36].fieldType = FIELD_CUSTOM;
    dataDesc_249[36].fieldName = "m_OnCase[13]";
    dataDesc_249[36].fieldOffset = 1252;
    dataDesc_249[36].externalName = "OnCase14";
    dataDesc_249[36].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_249[36].flatGroup = 0;
    dataDesc_249[37].fieldType = FIELD_CUSTOM;
    dataDesc_249[37].fieldName = "m_OnCase[14]";
    dataDesc_249[37].fieldOffset = 1276;
    dataDesc_249[37].externalName = "OnCase15";
    dataDesc_249[37].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_249[37].flatGroup = 0;
    dataDesc_249[38].fieldType = FIELD_CUSTOM;
    dataDesc_249[38].fieldName = "m_OnCase[15]";
    dataDesc_249[38].fieldOffset = 1300;
    dataDesc_249[38].flags = 22;
    dataDesc_249[38].externalName = "OnCase16";
    dataDesc_249[38].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_249[38].flatGroup = 0;
    dataDesc_249[39].fieldType = FIELD_CUSTOM;
    dataDesc_249[39].fieldName = "m_OnDefault";
    dataDesc_249[39].fieldOffset = 1324;
    *(_DWORD *)&dataDesc_249[39].fieldSize = 1441793;
    dataDesc_249[39].externalName = "OnDefault";
    dataDesc_249[39].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_249[39].inputFunc = 0;
    *(_QWORD *)&dataDesc_249[39].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_249[39].override_count = 0;
    *(_QWORD *)dataDesc_249[39].flatOffset = 0;
    *(_DWORD *)&dataDesc_249[39].flatGroup = 0;
  }
  CLogicCase::m_DataMap.dataNumFields = 39;
  CLogicCase::m_DataMap.dataDesc = &dataDesc_249[1];
  return &CLogicCase::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1016DD00
// Name: struct datamap_t __near * DataMapInit<class CLogicCompare>(class CLogicCompare __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CLogicCompare>()
{
  if ( (_S13_0 & 1) == 0 )
  {
    _S13_0 |= 1u;
    nameHolder_263.m_pszBase = "CLogicCompare";
    nameHolder_263.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_263.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_263.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_263.m_Names.m_Size = 0;
    nameHolder_263.m_Names.m_pElements = nullptr;
    nameHolder_263.m_nLenBase = 13;
    atexit(func: DataMapInit_CLogicCompare__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CLogicCompare::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S13_0 & 2) == 0 )
  {
    _S13_0 |= 2u;
    dataDesc_250[8].fieldSize = 1;
    *(_QWORD *)&dataDesc_250[7].inputFunc = 0;
    *(_QWORD *)&dataDesc_250[7].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_250[7].override_count = 0;
    *(_QWORD *)dataDesc_250[7].flatOffset = 0;
    dataDesc_250[8].flags = 22;
    *(_QWORD *)&dataDesc_250[8].inputFunc = 0;
    *(_QWORD *)&dataDesc_250[8].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_250[8].override_count = 0;
    *(_QWORD *)dataDesc_250[8].flatOffset = 0;
    dataDesc_250[9].fieldSize = 1;
    *(_QWORD *)&dataDesc_250[9].inputFunc = 0;
    *(_QWORD *)&dataDesc_250[9].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_250[9].override_count = 0;
    *(_QWORD *)dataDesc_250[9].flatOffset = 0;
    dataDesc_250[7].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_250[7].flatGroup = 0;
    dataDesc_250[8].fieldType = FIELD_CUSTOM;
    dataDesc_250[8].fieldName = "m_OnNotEqualTo";
    dataDesc_250[8].fieldOffset = 908;
    dataDesc_250[8].externalName = "OnNotEqualTo";
    dataDesc_250[8].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_250[8].flatGroup = 0;
    dataDesc_250[9].fieldType = FIELD_CUSTOM;
    dataDesc_250[9].fieldName = "m_OnGreaterThan";
    dataDesc_250[9].fieldOffset = 932;
    dataDesc_250[9].flags = 22;
    dataDesc_250[9].externalName = "OnGreaterThan";
    dataDesc_250[9].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_250[9].flatGroup = 0;
    dataDesc_250[10].fieldType = FIELD_CUSTOM;
    dataDesc_250[10].fieldName = "m_OnLessThan";
    dataDesc_250[10].fieldOffset = 860;
    *(_DWORD *)&dataDesc_250[10].fieldSize = 1441793;
    dataDesc_250[10].externalName = "OnLessThan";
    dataDesc_250[10].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_250[10].inputFunc = 0;
    *(_QWORD *)&dataDesc_250[10].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_250[10].override_count = 0;
    *(_QWORD *)dataDesc_250[10].flatOffset = 0;
    *(_DWORD *)&dataDesc_250[10].flatGroup = 0;
  }
  CLogicCompare::m_DataMap.dataNumFields = 10;
  CLogicCompare::m_DataMap.dataDesc = &dataDesc_250[1];
  return &CLogicCompare::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1016DF10
// Name: struct datamap_t __near * DataMapInit<class CLogicBranch>(class CLogicBranch __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CLogicBranch>()
{
  if ( (_S14_0 & 1) == 0 )
  {
    _S14_0 |= 1u;
    nameHolder_264.m_pszBase = "CLogicBranch";
    nameHolder_264.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_264.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_264.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_264.m_Names.m_Size = 0;
    nameHolder_264.m_Names.m_pElements = nullptr;
    nameHolder_264.m_nLenBase = 12;
    atexit(func: DataMapInit_CLogicBranch__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CLogicBranch::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S14_0 & 2) == 0 )
  {
    _S14_0 |= 2u;
    if ( (`CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int>>>'::`2'::`local static guard'
        & 1) == 0 )
    {
      `CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int>>>'::`2'::`local static guard' |= 1u;
      `CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int>>>'::`2'::ops = (int)&CUtlVectorDataOps<CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int>>,13>::`vftable';
    }
    *(_QWORD *)&dataDesc_251[2].td = 0;
    *(_QWORD *)&dataDesc_251[2].override_field = 0;
    *(_QWORD *)&dataDesc_251[2].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_251[2].flatOffset[1] = 0;
    dataDesc_251[3].fieldType = FIELD_BOOLEAN;
    dataDesc_251[4].fieldType = FIELD_BOOLEAN;
    dataDesc_251[3].fieldSize = 1;
    *(_QWORD *)&dataDesc_251[3].td = 0;
    *(_QWORD *)&dataDesc_251[3].override_field = 0;
    *(_QWORD *)&dataDesc_251[3].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_251[3].flatOffset[1] = 0;
    dataDesc_251[3].flags = 8;
    dataDesc_251[4].fieldSize = 1;
    *(_QWORD *)&dataDesc_251[4].td = 0;
    *(_QWORD *)&dataDesc_251[4].override_field = 0;
    *(_QWORD *)&dataDesc_251[4].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_251[4].flatOffset[1] = 0;
    dataDesc_251[4].flags = 8;
    dataDesc_251[5].fieldSize = 1;
    *(_QWORD *)&dataDesc_251[5].td = 0;
    *(_QWORD *)&dataDesc_251[5].override_field = 0;
    *(_QWORD *)&dataDesc_251[5].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_251[5].flatOffset[1] = 0;
    dataDesc_251[5].flags = 8;
    dataDesc_251[6].fieldSize = 1;
    *(_QWORD *)&dataDesc_251[6].td = 0;
    *(_QWORD *)&dataDesc_251[6].override_field = 0;
    *(_QWORD *)&dataDesc_251[6].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_251[6].flatOffset[1] = 0;
    dataDesc_251[2].pSaveRestoreOps = (ISaveRestoreOps *)&`CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int>>>'::`2'::ops;
    dataDesc_251[2].inputFunc = nullptr;
    dataDesc_251[3].fieldName = "InputSetValue";
    dataDesc_251[3].fieldOffset = 0;
    dataDesc_251[3].externalName = "SetValue";
    dataDesc_251[3].pSaveRestoreOps = nullptr;
    dataDesc_251[3].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CLogicBranch::InputSetValue;
    dataDesc_251[4].fieldName = "InputSetValueTest";
    dataDesc_251[4].fieldOffset = 0;
    dataDesc_251[4].externalName = "SetValueTest";
    dataDesc_251[4].pSaveRestoreOps = nullptr;
    dataDesc_251[4].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CLogicBranch::InputSetValueTest;
    dataDesc_251[5].fieldType = FIELD_VOID;
    dataDesc_251[5].fieldName = "InputToggle";
    dataDesc_251[5].fieldOffset = 0;
    dataDesc_251[5].externalName = "Toggle";
    dataDesc_251[5].pSaveRestoreOps = nullptr;
    dataDesc_251[5].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CLogicBranch::InputToggle;
    dataDesc_251[6].fieldType = FIELD_VOID;
    dataDesc_251[6].fieldName = "InputToggleTest";
    dataDesc_251[6].fieldOffset = 0;
    dataDesc_251[6].flags = 8;
    dataDesc_251[6].externalName = "ToggleTest";
    dataDesc_251[6].pSaveRestoreOps = nullptr;
    dataDesc_251[6].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CLogicBranch::InputToggleTest;
    dataDesc_251[7].fieldType = FIELD_VOID;
    dataDesc_251[7].fieldName = "InputTest";
    dataDesc_251[7].fieldOffset = 0;
    dataDesc_251[7].fieldSize = 1;
    dataDesc_251[7].flags = 8;
    dataDesc_251[7].externalName = "Test";
    dataDesc_251[7].pSaveRestoreOps = nullptr;
    dataDesc_251[7].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CLogicBranch::InputTest;
    *(_QWORD *)&dataDesc_251[7].td = 0;
    *(_QWORD *)&dataDesc_251[7].override_field = 0;
    *(_QWORD *)&dataDesc_251[7].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_251[7].flatOffset[1] = 0;
    dataDesc_251[8].flags = 22;
    *(_QWORD *)&dataDesc_251[8].inputFunc = 0;
    *(_QWORD *)&dataDesc_251[8].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_251[8].override_count = 0;
    *(_QWORD *)dataDesc_251[8].flatOffset = 0;
    dataDesc_251[8].fieldType = FIELD_CUSTOM;
    dataDesc_251[8].fieldName = "m_OnTrue";
    dataDesc_251[8].fieldOffset = 876;
    dataDesc_251[8].fieldSize = 1;
    dataDesc_251[8].externalName = "OnTrue";
    dataDesc_251[8].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_251[8].flatGroup = 0;
    dataDesc_251[9].fieldType = FIELD_CUSTOM;
    dataDesc_251[9].fieldName = "m_OnFalse";
    dataDesc_251[9].fieldOffset = 900;
    *(_DWORD *)&dataDesc_251[9].fieldSize = 1441793;
    dataDesc_251[9].externalName = "OnFalse";
    dataDesc_251[9].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_251[9].inputFunc = 0;
    *(_QWORD *)&dataDesc_251[9].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_251[9].override_count = 0;
    *(_QWORD *)dataDesc_251[9].flatOffset = 0;
    *(_DWORD *)&dataDesc_251[9].flatGroup = 0;
  }
  CLogicBranch::m_DataMap.dataNumFields = 9;
  CLogicBranch::m_DataMap.dataDesc = &dataDesc_251[1];
  return &CLogicBranch::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1016E2C0
// Name: struct datamap_t __near * DataMapInit<class CLogicAutosave>(class CLogicAutosave __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CLogicAutosave>()
{
  if ( (_S15 & 1) == 0 )
  {
    _S15 |= 1u;
    nameHolder_265.m_pszBase = "CLogicAutosave";
    nameHolder_265.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_265.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_265.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_265.m_Names.m_Size = 0;
    nameHolder_265.m_Names.m_pElements = nullptr;
    nameHolder_265.m_nLenBase = 14;
    atexit(func: DataMapInit_CLogicAutosave__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CLogicAutosave::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CLogicAutosave::m_DataMap.dataNumFields = 6;
  CLogicAutosave::m_DataMap.dataDesc = &dataDesc_252[1];
  return &CLogicAutosave::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1016E340
// Name: struct datamap_t __near * DataMapInit<class CLogicActiveAutosave>(class CLogicActiveAutosave __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CLogicActiveAutosave>()
{
  if ( (_S16_0 & 1) == 0 )
  {
    _S16_0 |= 1u;
    nameHolder_266.m_pszBase = "CLogicActiveAutosave";
    nameHolder_266.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_266.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_266.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_266.m_Names.m_Size = 0;
    nameHolder_266.m_Names.m_pElements = nullptr;
    nameHolder_266.m_nLenBase = 20;
    atexit(func: DataMapInit_CLogicActiveAutosave__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CLogicActiveAutosave::m_DataMap.baseMap = &CLogicAutosave::m_DataMap;
  if ( (_S16_0 & 2) == 0 )
  {
    _S16_0 |= 2u;
    dataDesc_253[5].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_266,
                                  pszIdentifier: "SaveThink");
    *(_QWORD *)&dataDesc_253[5].td = 0;
    *(_QWORD *)&dataDesc_253[5].override_field = 0;
    *(_QWORD *)&dataDesc_253[5].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_253[5].flatOffset[1] = 0;
    dataDesc_253[5].fieldSize = 1;
    *(_QWORD *)&dataDesc_253[6].td = 0;
    *(_QWORD *)&dataDesc_253[6].override_field = 0;
    *(_QWORD *)&dataDesc_253[6].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_253[6].flatOffset[1] = 0;
    dataDesc_253[5].fieldOffset = 0;
    dataDesc_253[5].flags = 32;
    dataDesc_253[5].externalName = nullptr;
    dataDesc_253[5].pSaveRestoreOps = nullptr;
    dataDesc_253[5].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CLogicActiveAutosave::SaveThink;
    dataDesc_253[6].fieldType = FIELD_VOID;
    dataDesc_253[6].fieldName = "InputEnable";
    dataDesc_253[6].fieldOffset = 0;
    dataDesc_253[6].fieldSize = 1;
    dataDesc_253[6].flags = 8;
    dataDesc_253[6].externalName = "Enable";
    dataDesc_253[6].pSaveRestoreOps = nullptr;
    dataDesc_253[6].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CLogicActiveAutosave::InputEnable;
    dataDesc_253[7].fieldType = FIELD_VOID;
    dataDesc_253[7].fieldName = "InputDisable";
    dataDesc_253[7].fieldOffset = 0;
    *(_DWORD *)&dataDesc_253[7].fieldSize = 524289;
    dataDesc_253[7].externalName = "Disable";
    dataDesc_253[7].pSaveRestoreOps = nullptr;
    dataDesc_253[7].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CLogicMeasureMovement::InputDisable;
    *(_QWORD *)&dataDesc_253[7].td = 0;
    *(_QWORD *)&dataDesc_253[7].override_field = 0;
    *(_QWORD *)&dataDesc_253[7].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_253[7].flatOffset[1] = 0;
  }
  CLogicActiveAutosave::m_DataMap.dataNumFields = 7;
  CLogicActiveAutosave::m_DataMap.dataDesc = &dataDesc_253[1];
  return &CLogicActiveAutosave::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1016E510
// Name: struct datamap_t __near * DataMapInit<class CLogicCollisionPair>(class CLogicCollisionPair __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CLogicCollisionPair>()
{
  if ( (_S17_0 & 1) == 0 )
  {
    _S17_0 |= 1u;
    nameHolder_267.m_pszBase = "CLogicCollisionPair";
    nameHolder_267.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_267.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_267.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_267.m_Names.m_Size = 0;
    nameHolder_267.m_Names.m_pElements = nullptr;
    nameHolder_267.m_nLenBase = 19;
    atexit(func: DataMapInit_CLogicCollisionPair__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CLogicCollisionPair::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CLogicCollisionPair::m_DataMap.dataNumFields = 6;
  CLogicCollisionPair::m_DataMap.dataDesc = &dataDesc_254[1];
  return &CLogicCollisionPair::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1016E590
// Name: struct datamap_t __near * DataMapInit<class CLogicBranchList>(class CLogicBranchList __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CLogicBranchList>()
{
  if ( (_S18_0 & 1) == 0 )
  {
    _S18_0 |= 1u;
    nameHolder_268.m_pszBase = "CLogicBranchList";
    nameHolder_268.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_268.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_268.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_268.m_Names.m_Size = 0;
    nameHolder_268.m_Names.m_pElements = nullptr;
    nameHolder_268.m_nLenBase = 16;
    atexit(func: DataMapInit_CLogicBranchList__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CLogicBranchList::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S18_0 & 2) == 0 )
  {
    _S18_0 |= 2u;
    if ( (`CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int>>>'::`2'::`local static guard'
        & 1) == 0 )
    {
      `CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int>>>'::`2'::`local static guard' |= 1u;
      `CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int>>>'::`2'::ops = (int)&CUtlVectorDataOps<CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int>>,13>::`vftable';
    }
    *(_QWORD *)&dataDesc_255[17].td = 0;
    *(_QWORD *)&dataDesc_255[17].override_field = 0;
    *(_QWORD *)&dataDesc_255[17].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_255[17].flatOffset[1] = 0;
    dataDesc_255[18].flags = 2;
    dataDesc_255[18].fieldTolerance = 0.0;
    dataDesc_255[18].fieldSize = 1;
    *(_QWORD *)dataDesc_255[18].flatOffset = 0;
    dataDesc_255[19].fieldType = FIELD_INPUT;
    dataDesc_255[20].fieldType = FIELD_INPUT;
    dataDesc_255[21].fieldType = FIELD_INPUT;
    *(_QWORD *)&dataDesc_255[19].td = 0;
    *(_QWORD *)&dataDesc_255[19].override_field = 0;
    *(_QWORD *)&dataDesc_255[19].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_255[19].flatOffset[1] = 0;
    dataDesc_255[21].flags = 8;
    *(_QWORD *)&dataDesc_255[20].td = 0;
    *(_QWORD *)&dataDesc_255[20].override_field = 0;
    *(_QWORD *)&dataDesc_255[20].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_255[20].flatOffset[1] = 0;
    dataDesc_255[19].flags = 8;
    dataDesc_255[20].flags = 8;
    dataDesc_255[22].flags = 22;
    *(_QWORD *)&dataDesc_255[21].td = 0;
    *(_QWORD *)&dataDesc_255[21].override_field = 0;
    *(_QWORD *)&dataDesc_255[21].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_255[21].flatOffset[1] = 0;
    dataDesc_255[17].pSaveRestoreOps = (ISaveRestoreOps *)&`CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int>>>'::`2'::ops;
    dataDesc_255[17].inputFunc = nullptr;
    dataDesc_255[18].fieldType = FIELD_INTEGER;
    dataDesc_255[18].fieldName = "m_eLastState";
    dataDesc_255[18].fieldOffset = 936;
    dataDesc_255[18].externalName = nullptr;
    dataDesc_255[18].pSaveRestoreOps = nullptr;
    dataDesc_255[18].inputFunc = nullptr;
    dataDesc_255[18].td = nullptr;
    dataDesc_255[18].fieldSizeInBytes = 4;
    dataDesc_255[18].override_field = nullptr;
    dataDesc_255[18].override_count = 0;
    *(_DWORD *)&dataDesc_255[18].flatGroup = 0;
    dataDesc_255[19].fieldName = "InputTest";
    dataDesc_255[19].fieldOffset = 0;
    dataDesc_255[19].fieldSize = 1;
    dataDesc_255[19].externalName = "Test";
    dataDesc_255[19].pSaveRestoreOps = nullptr;
    dataDesc_255[19].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CLogicBranchList::InputTest;
    dataDesc_255[20].fieldName = "Input_OnLogicBranchChanged";
    dataDesc_255[20].fieldOffset = 0;
    dataDesc_255[20].fieldSize = 1;
    dataDesc_255[20].externalName = "_OnLogicBranchChanged";
    dataDesc_255[20].pSaveRestoreOps = nullptr;
    dataDesc_255[20].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CLogicBranchList::Input_OnLogicBranchChanged;
    dataDesc_255[21].fieldName = "Input_OnLogicBranchRemoved";
    dataDesc_255[21].fieldOffset = 0;
    dataDesc_255[21].fieldSize = 1;
    dataDesc_255[21].externalName = "_OnLogicBranchRemoved";
    dataDesc_255[21].pSaveRestoreOps = nullptr;
    dataDesc_255[21].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CLogicBranchList::Input_OnLogicBranchRemoved;
    dataDesc_255[22].fieldType = FIELD_CUSTOM;
    dataDesc_255[22].fieldName = "m_OnAllTrue";
    dataDesc_255[22].fieldOffset = 940;
    dataDesc_255[22].fieldSize = 1;
    dataDesc_255[22].externalName = "OnAllTrue";
    dataDesc_255[22].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_255[22].inputFunc = 0;
    *(_QWORD *)&dataDesc_255[22].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_255[22].override_count = 0;
    *(_QWORD *)dataDesc_255[22].flatOffset = 0;
    dataDesc_255[23].fieldSize = 1;
    *(_QWORD *)&dataDesc_255[23].inputFunc = 0;
    *(_QWORD *)&dataDesc_255[23].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_255[23].override_count = 0;
    *(_QWORD *)dataDesc_255[23].flatOffset = 0;
    *(_DWORD *)&dataDesc_255[22].flatGroup = 0;
    dataDesc_255[23].fieldType = FIELD_CUSTOM;
    dataDesc_255[23].fieldName = "m_OnAllFalse";
    dataDesc_255[23].fieldOffset = 964;
    dataDesc_255[23].flags = 22;
    dataDesc_255[23].externalName = "OnAllFalse";
    dataDesc_255[23].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_255[23].flatGroup = 0;
    dataDesc_255[24].fieldType = FIELD_CUSTOM;
    dataDesc_255[24].fieldName = "m_OnMixed";
    dataDesc_255[24].fieldOffset = 988;
    *(_DWORD *)&dataDesc_255[24].fieldSize = 1441793;
    dataDesc_255[24].externalName = "OnMixed";
    dataDesc_255[24].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_255[24].inputFunc = 0;
    *(_QWORD *)&dataDesc_255[24].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_255[24].override_count = 0;
    *(_QWORD *)dataDesc_255[24].flatOffset = 0;
    *(_DWORD *)&dataDesc_255[24].flatGroup = 0;
  }
  CLogicBranchList::m_DataMap.dataNumFields = 24;
  CLogicBranchList::m_DataMap.dataDesc = &dataDesc_255[1];
  return &CLogicBranchList::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1016EC70
// Name: struct datamap_t __near * DataMapInit<class CLogicRelay>(class CLogicRelay __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CLogicRelay>()
{
  if ( (_S2_150 & 1) == 0 )
  {
    _S2_150 |= 1u;
    nameHolder_269.m_pszBase = "CLogicRelay";
    nameHolder_269.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_269.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_269.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_269.m_Names.m_Size = 0;
    nameHolder_269.m_Names.m_pElements = nullptr;
    nameHolder_269.m_nLenBase = 11;
    atexit(func: DataMapInit_CLogicRelay__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CLogicRelay::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S2_150 & 2) == 0 )
  {
    _S2_150 |= 2u;
    *(_QWORD *)&dataDesc_256[9].inputFunc = 0;
    *(_QWORD *)&dataDesc_256[9].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_256[9].override_count = 0;
    *(_QWORD *)dataDesc_256[9].flatOffset = 0;
    dataDesc_256[9].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_256[9].flatGroup = 0;
    dataDesc_256[10].fieldType = FIELD_CUSTOM;
    dataDesc_256[10].fieldName = "m_OnSpawn";
    dataDesc_256[10].fieldOffset = 876;
    *(_DWORD *)&dataDesc_256[10].fieldSize = 1441793;
    dataDesc_256[10].externalName = "OnSpawn";
    dataDesc_256[10].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_256[10].inputFunc = 0;
    *(_QWORD *)&dataDesc_256[10].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_256[10].override_count = 0;
    *(_QWORD *)dataDesc_256[10].flatOffset = 0;
    *(_DWORD *)&dataDesc_256[10].flatGroup = 0;
  }
  CLogicRelay::m_DataMap.dataNumFields = 10;
  CLogicRelay::m_DataMap.dataDesc = &dataDesc_256[1];
  return &CLogicRelay::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101712F0
// Name: struct datamap_t __near * DataMapInit<class CRuleEntity>(class CRuleEntity __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CRuleEntity>()
{
  if ( (_S2_151 & 1) == 0 )
  {
    _S2_151 |= 1u;
    nameHolder_270.m_pszBase = "CRuleEntity";
    nameHolder_270.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_270.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_270.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_270.m_Names.m_Size = 0;
    nameHolder_270.m_Names.m_pElements = nullptr;
    nameHolder_270.m_nLenBase = 11;
    atexit(func: DataMapInit_CRuleEntity__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CRuleEntity::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CRuleEntity::m_DataMap.dataNumFields = 1;
  CRuleEntity::m_DataMap.dataDesc = &dataDesc_257[1];
  return &CRuleEntity::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10171360
// Name: struct datamap_t __near * DataMapInit<class CRulePointEntity>(class CRulePointEntity __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CRulePointEntity>()
{
  if ( (_S3_79 & 1) == 0 )
  {
    _S3_79 |= 1u;
    nameHolder_271.m_pszBase = "CRulePointEntity";
    nameHolder_271.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_271.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_271.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_271.m_Names.m_Size = 0;
    nameHolder_271.m_Names.m_pElements = nullptr;
    nameHolder_271.m_nLenBase = 16;
    atexit(func: DataMapInit_CRulePointEntity__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CRulePointEntity::m_DataMap.baseMap = &CRuleEntity::m_DataMap;
  CRulePointEntity::m_DataMap.dataNumFields = 1;
  CRulePointEntity::m_DataMap.dataDesc = &dataDesc_258[1];
  return &CRulePointEntity::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101713D0
// Name: struct datamap_t __near * DataMapInit<class CGameScore>(class CGameScore __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CGameScore>()
{
  if ( (_S4_39 & 1) == 0 )
  {
    _S4_39 |= 1u;
    nameHolder_272.m_pszBase = "CGameScore";
    nameHolder_272.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_272.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_272.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_272.m_Names.m_Size = 0;
    nameHolder_272.m_Names.m_pElements = nullptr;
    nameHolder_272.m_nLenBase = 10;
    atexit(func: DataMapInit_CGameScore__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CGameScore::m_DataMap.baseMap = &CRulePointEntity::m_DataMap;
  CGameScore::m_DataMap.dataNumFields = 1;
  CGameScore::m_DataMap.dataDesc = &dataDesc_259[1];
  return &CGameScore::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10171440
// Name: struct datamap_t __near * DataMapInit<class CGameEnd>(class CGameEnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CGameEnd>()
{
  if ( (_S5_19 & 1) == 0 )
  {
    _S5_19 |= 1u;
    nameHolder_273.m_pszBase = "CGameEnd";
    nameHolder_273.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_273.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_273.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_273.m_Names.m_Size = 0;
    nameHolder_273.m_Names.m_pElements = nullptr;
    nameHolder_273.m_nLenBase = 8;
    atexit(func: DataMapInit_CGameEnd__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CGameEnd::m_DataMap.baseMap = &CRulePointEntity::m_DataMap;
  CGameEnd::m_DataMap.dataNumFields = 1;
  CGameEnd::m_DataMap.dataDesc = &dataDesc_260[1];
  return &CGameEnd::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101714B0
// Name: struct datamap_t __near * DataMapInit<class CGameText>(class CGameText __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CGameText>()
{
  if ( (_S6_14 & 1) == 0 )
  {
    _S6_14 |= 1u;
    nameHolder_274.m_pszBase = "CGameText";
    nameHolder_274.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_274.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_274.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_274.m_Names.m_Size = 0;
    nameHolder_274.m_Names.m_pElements = nullptr;
    nameHolder_274.m_nLenBase = 9;
    atexit(func: DataMapInit_CGameText__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CGameText::m_DataMap.baseMap = &CRulePointEntity::m_DataMap;
  CGameText::m_DataMap.dataNumFields = 16;
  CGameText::m_DataMap.dataDesc = &dataDesc_261[1];
  return &CGameText::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10171530
// Name: struct datamap_t __near * DataMapInit<class CGamePlayerZone>(class CGamePlayerZone __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CGamePlayerZone>()
{
  if ( (_S7_7 & 1) == 0 )
  {
    _S7_7 |= 1u;
    nameHolder_275.m_pszBase = "CGamePlayerZone";
    nameHolder_275.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_275.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_275.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_275.m_Names.m_Size = 0;
    nameHolder_275.m_Names.m_pElements = nullptr;
    nameHolder_275.m_nLenBase = 15;
    atexit(func: DataMapInit_CGamePlayerZone__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CGamePlayerZone::m_DataMap.baseMap = &CRuleEntity::m_DataMap;
  if ( (_S7_7 & 2) == 0 )
  {
    _S7_7 |= 2u;
    dataDesc_262[3].fieldSize = 1;
    *(_QWORD *)&dataDesc_262[2].inputFunc = 0;
    *(_QWORD *)&dataDesc_262[2].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_262[2].override_count = 0;
    *(_QWORD *)dataDesc_262[2].flatOffset = 0;
    dataDesc_262[3].flags = 22;
    *(_QWORD *)&dataDesc_262[3].inputFunc = 0;
    *(_QWORD *)&dataDesc_262[3].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_262[3].override_count = 0;
    *(_QWORD *)dataDesc_262[3].flatOffset = 0;
    dataDesc_262[4].fieldSize = 1;
    *(_QWORD *)&dataDesc_262[4].inputFunc = 0;
    *(_QWORD *)&dataDesc_262[4].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_262[4].override_count = 0;
    *(_QWORD *)dataDesc_262[4].flatOffset = 0;
    dataDesc_262[2].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_262[2].flatGroup = 0;
    dataDesc_262[3].fieldType = FIELD_CUSTOM;
    dataDesc_262[3].fieldName = "m_OnPlayerOutZone";
    dataDesc_262[3].fieldOffset = 880;
    dataDesc_262[3].externalName = "OnPlayerOutZone";
    dataDesc_262[3].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_262[3].flatGroup = 0;
    dataDesc_262[4].fieldType = FIELD_CUSTOM;
    dataDesc_262[4].fieldName = "m_PlayersInCount";
    dataDesc_262[4].fieldOffset = 904;
    dataDesc_262[4].flags = 22;
    dataDesc_262[4].externalName = "PlayersInCount";
    dataDesc_262[4].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_262[4].flatGroup = 0;
    dataDesc_262[5].fieldType = FIELD_CUSTOM;
    dataDesc_262[5].fieldName = "m_PlayersOutCount";
    dataDesc_262[5].fieldOffset = 928;
    *(_DWORD *)&dataDesc_262[5].fieldSize = 1441793;
    dataDesc_262[5].externalName = "PlayersOutCount";
    dataDesc_262[5].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_262[5].inputFunc = 0;
    *(_QWORD *)&dataDesc_262[5].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_262[5].override_count = 0;
    *(_QWORD *)dataDesc_262[5].flatOffset = 0;
    *(_DWORD *)&dataDesc_262[5].flatGroup = 0;
  }
  CGamePlayerZone::m_DataMap.dataNumFields = 5;
  CGamePlayerZone::m_DataMap.dataDesc = &dataDesc_262[1];
  return &CGamePlayerZone::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10171730
// Name: struct datamap_t __near * DataMapInit<class CGamePlayerEquip>(class CGamePlayerEquip __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CGamePlayerEquip>()
{
  if ( (_S8_5 & 1) == 0 )
  {
    _S8_5 |= 1u;
    nameHolder_276.m_pszBase = "CGamePlayerEquip";
    nameHolder_276.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_276.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_276.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_276.m_Names.m_Size = 0;
    nameHolder_276.m_Names.m_pElements = nullptr;
    nameHolder_276.m_nLenBase = 16;
    atexit(func: DataMapInit_CGamePlayerEquip__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CGamePlayerEquip::m_DataMap.baseMap = &CRulePointEntity::m_DataMap;
  CGamePlayerEquip::m_DataMap.dataNumFields = 3;
  CGamePlayerEquip::m_DataMap.dataDesc = &dataDesc_263[1];
  return &CGamePlayerEquip::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10172340
// Name: struct datamap_t __near * DataMapInit<class CMaterialModifyControl>(class CMaterialModifyControl __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CMaterialModifyControl>()
{
  if ( (_S2_152 & 1) == 0 )
  {
    _S2_152 |= 1u;
    nameHolder_277.m_pszBase = "CMaterialModifyControl";
    nameHolder_277.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_277.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_277.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_277.m_Names.m_Size = 0;
    nameHolder_277.m_Names.m_pElements = nullptr;
    nameHolder_277.m_nLenBase = 22;
    atexit(func: DataMapInit_CMaterialModifyControl__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CMaterialModifyControl::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CMaterialModifyControl::m_DataMap.dataNumFields = 16;
  CMaterialModifyControl::m_DataMap.dataDesc = &dataDesc_264[1];
  return &CMaterialModifyControl::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10174AB0
// Name: struct datamap_t __near * DataMapInit<class CPathKeyFrame>(class CPathKeyFrame __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CPathKeyFrame>()
{
  if ( (_S2_155 & 1) == 0 )
  {
    _S2_155 |= 1u;
    nameHolder_281.m_pszBase = "CPathKeyFrame";
    nameHolder_281.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_281.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_281.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_281.m_Names.m_Size = 0;
    nameHolder_281.m_Names.m_pElements = nullptr;
    nameHolder_281.m_nLenBase = 13;
    atexit(func: DataMapInit_CPathKeyFrame__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CPathKeyFrame::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CPathKeyFrame::m_DataMap.dataNumFields = 8;
  CPathKeyFrame::m_DataMap.dataDesc = &dataDesc_268[1];
  return &CPathKeyFrame::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10174B30
// Name: struct datamap_t __near * DataMapInit<class CBaseMoveBehavior>(class CBaseMoveBehavior __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CBaseMoveBehavior>()
{
  if ( (_S3_82 & 1) == 0 )
  {
    _S3_82 |= 1u;
    nameHolder_282.m_pszBase = "CBaseMoveBehavior";
    nameHolder_282.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_282.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_282.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_282.m_Names.m_Size = 0;
    nameHolder_282.m_Names.m_pElements = nullptr;
    nameHolder_282.m_nLenBase = 17;
    atexit(func: DataMapInit_CBaseMoveBehavior__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CBaseMoveBehavior::m_DataMap.baseMap = &CPathKeyFrame::m_DataMap;
  CBaseMoveBehavior::m_DataMap.dataNumFields = 11;
  CBaseMoveBehavior::m_DataMap.dataDesc = &dataDesc_269[1];
  return &CBaseMoveBehavior::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1017BBD0
// Name: struct datamap_t __near * DataMapInit<class CParticleLight>(class CParticleLight __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CParticleLight>()
{
  if ( (_S2_158 & 1) == 0 )
  {
    _S2_158 |= 1u;
    nameHolder_285.m_pszBase = "CParticleLight";
    nameHolder_285.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_285.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_285.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_285.m_Names.m_Size = 0;
    nameHolder_285.m_Names.m_pElements = nullptr;
    nameHolder_285.m_nLenBase = 14;
    atexit(func: DataMapInit_CParticleLight__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CParticleLight::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CParticleLight::m_DataMap.dataNumFields = 4;
  CParticleLight::m_DataMap.dataDesc = &dataDesc_272[1];
  return &CParticleLight::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1017D500
// Name: struct datamap_t __near * DataMapInit<class CPathCorner>(class CPathCorner __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CPathCorner>()
{
  if ( (_S2_159 & 1) == 0 )
  {
    _S2_159 |= 1u;
    nameHolder_287.m_pszBase = "CPathCorner";
    nameHolder_287.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_287.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_287.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_287.m_Names.m_Size = 0;
    nameHolder_287.m_Names.m_pElements = nullptr;
    nameHolder_287.m_nLenBase = 11;
    atexit(func: DataMapInit_CPathCorner__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CPathCorner::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S2_159 & 2) == 0 )
  {
    _S2_159 |= 2u;
    dataDesc_274[4].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_274[4].inputFunc = 0;
    *(_QWORD *)&dataDesc_274[4].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_274[4].override_count = 0;
    *(_QWORD *)dataDesc_274[4].flatOffset = 0;
    *(_DWORD *)&dataDesc_274[4].flatGroup = 0;
  }
  CPathCorner::m_DataMap.dataNumFields = 4;
  CPathCorner::m_DataMap.dataDesc = &dataDesc_274[1];
  return &CPathCorner::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10184530
// Name: struct datamap_t __near * DataMapInit<class CConstraintAnchor>(class CConstraintAnchor __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CConstraintAnchor>()
{
  if ( (_S2_162 & 1) == 0 )
  {
    _S2_162 |= 1u;
    nameHolder_296.m_pszBase = "CConstraintAnchor";
    nameHolder_296.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_296.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_296.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_296.m_Names.m_Size = 0;
    nameHolder_296.m_Names.m_pElements = nullptr;
    nameHolder_296.m_nLenBase = 17;
    atexit(func: DataMapInit_CConstraintAnchor__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CConstraintAnchor::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CConstraintAnchor::m_DataMap.dataNumFields = 1;
  CConstraintAnchor::m_DataMap.dataDesc = &dataDesc_283[1];
  return &CConstraintAnchor::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101845A0
// Name: struct datamap_t __near * DataMapInit<class CPhysConstraintSystem>(class CPhysConstraintSystem __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CPhysConstraintSystem>()
{
  ISaveRestoreOps *PhysObjSaveRestoreOps; // eax

  if ( (_S3_86 & 1) == 0 )
  {
    _S3_86 |= 1u;
    nameHolder_297.m_pszBase = "CPhysConstraintSystem";
    nameHolder_297.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_297.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_297.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_297.m_Names.m_Size = 0;
    nameHolder_297.m_Names.m_pElements = nullptr;
    nameHolder_297.m_nLenBase = 21;
    atexit(func: DataMapInit_CPhysConstraintSystem__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CPhysConstraintSystem::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S3_86 & 2) == 0 )
  {
    _S3_86 |= 2u;
    PhysObjSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSCONSTRAINTGROUP);
    *(_QWORD *)&dataDesc_284[1].td = 0;
    *(_QWORD *)&dataDesc_284[1].override_field = 0;
    *(_QWORD *)&dataDesc_284[1].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_284[1].flatOffset[1] = 0;
    dataDesc_284[2].fieldTolerance = 0.0;
    dataDesc_284[1].pSaveRestoreOps = PhysObjSaveRestoreOps;
    dataDesc_284[1].inputFunc = nullptr;
    dataDesc_284[2].fieldType = FIELD_INTEGER;
    dataDesc_284[2].fieldName = "m_additionalIterations";
    dataDesc_284[2].fieldOffset = 856;
    *(_DWORD *)&dataDesc_284[2].fieldSize = 393217;
    dataDesc_284[2].externalName = "additionaliterations";
    dataDesc_284[2].pSaveRestoreOps = nullptr;
    dataDesc_284[2].inputFunc = nullptr;
    dataDesc_284[2].td = nullptr;
    dataDesc_284[2].fieldSizeInBytes = 4;
    dataDesc_284[2].override_field = nullptr;
    dataDesc_284[2].override_count = 0;
    *(_QWORD *)dataDesc_284[2].flatOffset = 0;
    *(_DWORD *)&dataDesc_284[2].flatGroup = 0;
  }
  CPhysConstraintSystem::m_DataMap.dataNumFields = 2;
  CPhysConstraintSystem::m_DataMap.dataDesc = &dataDesc_284[1];
  return &CPhysConstraintSystem::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1018EDF0
// Name: struct datamap_t __near * DataMapInit<class CThrustController>(class CThrustController __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CThrustController>()
{
  if ( (_S2_164 & 1) == 0 )
  {
    _S2_164 |= 1u;
    nameHolder_307.m_pszBase = "CThrustController";
    nameHolder_307.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_307.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_307.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_307.m_Names.m_Size = 0;
    nameHolder_307.m_Names.m_pElements = nullptr;
    nameHolder_307.m_nLenBase = 17;
    atexit(func: DataMapInit_CThrustController__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CThrustController::m_DataMap.baseMap = nullptr;
  CThrustController::m_DataMap.dataNumFields = 3;
  CThrustController::m_DataMap.dataDesc = &dataDesc_294[1];
  return &CThrustController::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101A4540
// Name: struct datamap_t __near * DataMapInit<class CStatueProp>(class CStatueProp __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CStatueProp>()
{
  if ( (_S3_92 & 1) == 0 )
  {
    _S3_92 |= 1u;
    nameHolder_313.m_pszBase = "CStatueProp";
    nameHolder_313.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_313.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_313.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_313.m_Names.m_Size = 0;
    nameHolder_313.m_Names.m_pElements = nullptr;
    nameHolder_313.m_nLenBase = 11;
    atexit(func: DataMapInit_CStatueProp__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CStatueProp::m_DataMap.baseMap = &CPhysicsProp::m_DataMap;
  if ( (_S3_92 & 2) == 0 )
  {
    _S3_92 |= 2u;
    dataDesc_300[6].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_313,
                                  pszIdentifier: "CollisionPartnerThink");
    dataDesc_300[6].fieldOffset = 0;
    *(_DWORD *)&dataDesc_300[6].fieldSize = 2097153;
    dataDesc_300[6].externalName = nullptr;
    dataDesc_300[6].pSaveRestoreOps = nullptr;
    dataDesc_300[6].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CStatueProp::CollisionPartnerThink;
    *(_QWORD *)&dataDesc_300[6].td = 0;
    *(_QWORD *)&dataDesc_300[6].override_field = 0;
    *(_QWORD *)&dataDesc_300[6].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_300[6].flatOffset[1] = 0;
  }
  CStatueProp::m_DataMap.dataNumFields = 6;
  CStatueProp::m_DataMap.dataDesc = &dataDesc_300[1];
  return &CStatueProp::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101B08A0
// Name: class CPhysExplosion __near * _CreateEntityTemplate<class CPhysExplosion>(class CPhysExplosion __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CPhysExplosion *__cdecl _CreateEntityTemplate<CPhysExplosion>(CPhysExplosion *newEnt, const char *className)
{
  CBaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x37Cu);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    *v3 = &CPhysExplosion::`vftable';
    v3[217] = 0;
    v3[220] = -1;
    v3[221] = 0;
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CPhysExplosion *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B0910
// Name: class CPhysConvert __near * _CreateEntityTemplate<class CPhysConvert>(class CPhysConvert __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CPhysConvert *__cdecl _CreateEntityTemplate<CPhysConvert>(CPhysConvert *newEnt, const char *className)
{
  CBaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x374u);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: true);
    *v3 = &CPhysConvert::`vftable';
    v3[213] = 0;
    v3[216] = -1;
    v3[217] = 0;
    v3[220] = 0;
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CPhysConvert *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B3890
// Name: __CreateCServerGameTagsIServerGameTags_interface_3
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CServerGameTags *__cdecl _CreateCServerGameTagsIServerGameTags_interface_3()
{
  return &_g_CServerGameTags_singleton_3;
}

//------------------------------------------------------------------------------
// Address: 0x101CF9C0
// Name: struct datamap_t __near * DataMapInit<class CPlayerResource>(class CPlayerResource __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CPlayerResource>()
{
  if ( (_S3_96 & 1) == 0 )
  {
    _S3_96 |= 1u;
    nameHolder_328.m_pszBase = "CPlayerResource";
    nameHolder_328.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_328.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_328.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_328.m_Names.m_Size = 0;
    nameHolder_328.m_Names.m_pElements = nullptr;
    nameHolder_328.m_nLenBase = 15;
    atexit(func: DataMapInit_CPlayerResource__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CPlayerResource::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S3_96 & 2) == 0 )
  {
    _S3_96 |= 2u;
    dataDesc_480[1].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_328,
                                  pszIdentifier: "ResourceThink");
    dataDesc_480[1].fieldOffset = 0;
    *(_DWORD *)&dataDesc_480[1].fieldSize = 2097153;
    dataDesc_480[1].externalName = nullptr;
    dataDesc_480[1].pSaveRestoreOps = nullptr;
    dataDesc_480[1].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *)) __thiscall CAI_BattleLine::`vcall'{776,{flat}};
    *(_QWORD *)&dataDesc_480[1].td = 0;
    *(_QWORD *)&dataDesc_480[1].override_field = 0;
    *(_QWORD *)&dataDesc_480[1].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_480[1].flatOffset[1] = 0;
  }
  CPlayerResource::m_DataMap.dataNumFields = 1;
  CPlayerResource::m_DataMap.dataDesc = &dataDesc_480[1];
  return &CPlayerResource::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101D1210
// Name: struct datamap_t __near * DataMapInit<class CPointBonusMapsAccessor>(class CPointBonusMapsAccessor __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CPointBonusMapsAccessor>()
{
  if ( (_S2_174 & 1) == 0 )
  {
    _S2_174 |= 1u;
    nameHolder_334.m_pszBase = "CPointBonusMapsAccessor";
    nameHolder_334.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_334.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_334.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_334.m_Names.m_Size = 0;
    nameHolder_334.m_Names.m_pElements = nullptr;
    nameHolder_334.m_nLenBase = 23;
    atexit(func: DataMapInit_CPointBonusMapsAccessor__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CPointBonusMapsAccessor::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CPointBonusMapsAccessor::m_DataMap.dataNumFields = 5;
  CPointBonusMapsAccessor::m_DataMap.dataDesc = &dataDesc_320[1];
  return &CPointBonusMapsAccessor::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101D1AB0
// Name: struct datamap_t __near * DataMapInit<class CPointCamera>(class CPointCamera __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CPointCamera>()
{
  char *Name; // eax

  if ( (_S2_175 & 1) == 0 )
  {
    _S2_175 |= 1u;
    nameHolder_335.m_pszBase = "CPointCamera";
    nameHolder_335.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_335.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_335.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_335.m_Names.m_Size = 0;
    nameHolder_335.m_Names.m_pElements = nullptr;
    nameHolder_335.m_nLenBase = 12;
    atexit(func: DataMapInit_CPointCamera__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CPointCamera::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S2_175 & 2) == 0 )
  {
    _S2_175 |= 2u;
    Name = CDatadescGeneratedNameHolder::GenerateName(this: &nameHolder_335, pszIdentifier: "ChangeFOVThink");
    *(_QWORD *)&dataDesc_321[13].td = 0;
    *(_QWORD *)&dataDesc_321[13].override_field = 0;
    *(_QWORD *)&dataDesc_321[13].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_321[13].flatOffset[1] = 0;
    *(_QWORD *)&dataDesc_321[14].td = 0;
    *(_QWORD *)&dataDesc_321[14].override_field = 0;
    *(_QWORD *)&dataDesc_321[14].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_321[14].flatOffset[1] = 0;
    *(_QWORD *)&dataDesc_321[15].td = 0;
    *(_QWORD *)&dataDesc_321[15].override_field = 0;
    *(_QWORD *)&dataDesc_321[15].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_321[15].flatOffset[1] = 0;
    *(_QWORD *)&dataDesc_321[16].td = 0;
    *(_QWORD *)&dataDesc_321[16].override_field = 0;
    *(_QWORD *)&dataDesc_321[16].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_321[16].flatOffset[1] = 0;
    *(_QWORD *)&dataDesc_321[17].td = 0;
    *(_QWORD *)&dataDesc_321[17].override_field = 0;
    *(_QWORD *)&dataDesc_321[17].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_321[17].flatOffset[1] = 0;
    dataDesc_321[13].fieldName = Name;
    dataDesc_321[13].fieldOffset = 0;
    *(_DWORD *)&dataDesc_321[13].fieldSize = 2097153;
    dataDesc_321[13].externalName = nullptr;
    dataDesc_321[13].pSaveRestoreOps = nullptr;
    dataDesc_321[13].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPointCamera::ChangeFOVThink;
    dataDesc_321[14].fieldType = FIELD_STRING;
    dataDesc_321[14].fieldName = "InputChangeFOV";
    dataDesc_321[14].fieldOffset = 0;
    *(_DWORD *)&dataDesc_321[14].fieldSize = 524289;
    dataDesc_321[14].externalName = "ChangeFOV";
    dataDesc_321[14].pSaveRestoreOps = nullptr;
    dataDesc_321[14].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPointCamera::InputChangeFOV;
    dataDesc_321[15].fieldType = FIELD_VOID;
    dataDesc_321[15].fieldName = "InputSetOnAndTurnOthersOff";
    dataDesc_321[15].fieldOffset = 0;
    *(_DWORD *)&dataDesc_321[15].fieldSize = 524289;
    dataDesc_321[15].externalName = "SetOnAndTurnOthersOff";
    dataDesc_321[15].pSaveRestoreOps = nullptr;
    dataDesc_321[15].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPointCamera::InputSetOnAndTurnOthersOff;
    dataDesc_321[16].fieldType = FIELD_VOID;
    dataDesc_321[16].fieldName = "InputSetOn";
    dataDesc_321[16].fieldOffset = 0;
    *(_DWORD *)&dataDesc_321[16].fieldSize = 524289;
    dataDesc_321[16].externalName = "SetOn";
    dataDesc_321[16].pSaveRestoreOps = nullptr;
    dataDesc_321[16].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPointCamera::InputSetOn;
    dataDesc_321[17].fieldType = FIELD_VOID;
    dataDesc_321[17].fieldName = "InputSetOff";
    dataDesc_321[17].fieldOffset = 0;
    *(_DWORD *)&dataDesc_321[17].fieldSize = 524289;
    dataDesc_321[17].externalName = "SetOff";
    dataDesc_321[17].pSaveRestoreOps = nullptr;
    dataDesc_321[17].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPointCamera::InputSetOff;
    dataDesc_321[18].fieldType = FIELD_VOID;
    dataDesc_321[18].fieldName = "InputForceActive";
    dataDesc_321[18].fieldOffset = 0;
    *(_DWORD *)&dataDesc_321[18].fieldSize = 524289;
    dataDesc_321[18].externalName = "Activate";
    dataDesc_321[18].pSaveRestoreOps = nullptr;
    dataDesc_321[18].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPointCamera::InputForceActive;
    *(_QWORD *)&dataDesc_321[18].td = 0;
    *(_QWORD *)&dataDesc_321[18].override_field = 0;
    *(_QWORD *)&dataDesc_321[18].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_321[18].flatOffset[1] = 0;
    dataDesc_321[19].fieldType = FIELD_VOID;
    dataDesc_321[19].fieldName = "InputForceInactive";
    dataDesc_321[19].fieldOffset = 0;
    *(_DWORD *)&dataDesc_321[19].fieldSize = 524289;
    dataDesc_321[19].externalName = "Deactivate";
    dataDesc_321[19].pSaveRestoreOps = nullptr;
    dataDesc_321[19].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPointCamera::InputForceInactive;
    *(_QWORD *)&dataDesc_321[19].td = 0;
    *(_QWORD *)&dataDesc_321[19].override_field = 0;
    *(_QWORD *)&dataDesc_321[19].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_321[19].flatOffset[1] = 0;
  }
  CPointCamera::m_DataMap.dataNumFields = 19;
  CPointCamera::m_DataMap.dataDesc = &dataDesc_321[1];
  return &CPointCamera::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101D46B0
// Name: struct datamap_t __near * DataMapInit<class CPoseController>(class CPoseController __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CPoseController>()
{
  if ( (_S2_179 & 1) == 0 )
  {
    _S2_179 |= 1u;
    nameHolder_339.m_pszBase = "CPoseController";
    nameHolder_339.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_339.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_339.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_339.m_Names.m_Size = 0;
    nameHolder_339.m_Names.m_pElements = nullptr;
    nameHolder_339.m_nLenBase = 15;
    atexit(func: DataMapInit_CPoseController__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CPoseController::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S2_179 & 2) == 0 )
  {
    _S2_179 |= 2u;
    dataDesc_324[15].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_339,
                                   pszIdentifier: "Think");
    dataDesc_324[15].fieldSize = 1;
    *(_QWORD *)&dataDesc_324[15].td = 0;
    *(_QWORD *)&dataDesc_324[15].override_field = 0;
    *(_QWORD *)&dataDesc_324[15].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_324[15].flatOffset[1] = 0;
    dataDesc_324[15].flags = 32;
    dataDesc_324[16].fieldSize = 1;
    *(_QWORD *)&dataDesc_324[16].td = 0;
    *(_QWORD *)&dataDesc_324[16].override_field = 0;
    *(_QWORD *)&dataDesc_324[16].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_324[16].flatOffset[1] = 0;
    dataDesc_324[16].flags = 8;
    dataDesc_324[17].fieldSize = 1;
    *(_QWORD *)&dataDesc_324[17].td = 0;
    *(_QWORD *)&dataDesc_324[17].override_field = 0;
    *(_QWORD *)&dataDesc_324[17].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_324[17].flatOffset[1] = 0;
    dataDesc_324[17].flags = 8;
    dataDesc_324[18].fieldSize = 1;
    *(_QWORD *)&dataDesc_324[18].td = 0;
    *(_QWORD *)&dataDesc_324[18].override_field = 0;
    *(_QWORD *)&dataDesc_324[18].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_324[18].flatOffset[1] = 0;
    dataDesc_324[15].fieldOffset = 0;
    dataDesc_324[15].externalName = nullptr;
    dataDesc_324[15].pSaveRestoreOps = nullptr;
    dataDesc_324[15].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *)) __thiscall CBaseEntity::`vcall'{200,{flat}};
    dataDesc_324[16].fieldType = FIELD_STRING;
    dataDesc_324[16].fieldName = "InputSetPoseParameterName";
    dataDesc_324[16].fieldOffset = 0;
    dataDesc_324[16].externalName = "SetPoseParameterName";
    dataDesc_324[16].pSaveRestoreOps = nullptr;
    dataDesc_324[16].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPoseController::InputSetPoseParameterName;
    dataDesc_324[17].fieldType = FIELD_FLOAT;
    dataDesc_324[17].fieldName = "InputSetPoseValue";
    dataDesc_324[17].fieldOffset = 0;
    dataDesc_324[17].externalName = "SetPoseValue";
    dataDesc_324[17].pSaveRestoreOps = nullptr;
    dataDesc_324[17].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPoseController::InputSetPoseValue;
    dataDesc_324[18].fieldType = FIELD_FLOAT;
    dataDesc_324[18].fieldName = "InputSetInterpolationTime";
    dataDesc_324[18].fieldOffset = 0;
    dataDesc_324[18].flags = 8;
    dataDesc_324[18].externalName = "SetInterpolationTime";
    dataDesc_324[18].pSaveRestoreOps = nullptr;
    dataDesc_324[18].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPoseController::InputSetInterpolationTime;
    dataDesc_324[19].fieldType = FIELD_FLOAT;
    dataDesc_324[19].fieldName = "InputSetCycleFrequency";
    dataDesc_324[19].fieldOffset = 0;
    dataDesc_324[19].fieldSize = 1;
    dataDesc_324[19].flags = 8;
    dataDesc_324[19].externalName = "SetCycleFrequency";
    dataDesc_324[19].pSaveRestoreOps = nullptr;
    dataDesc_324[19].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPoseController::InputSetCycleFrequency;
    *(_QWORD *)&dataDesc_324[19].td = 0;
    *(_QWORD *)&dataDesc_324[19].override_field = 0;
    *(_QWORD *)&dataDesc_324[19].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_324[19].flatOffset[1] = 0;
    dataDesc_324[20].fieldType = FIELD_INTEGER;
    dataDesc_324[20].fieldName = "InputSetFModType";
    dataDesc_324[20].fieldOffset = 0;
    *(_QWORD *)&dataDesc_324[20].td = 0;
    *(_QWORD *)&dataDesc_324[20].override_field = 0;
    *(_QWORD *)&dataDesc_324[20].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_324[20].flatOffset[1] = 0;
    dataDesc_324[20].fieldSize = 1;
    *(_QWORD *)&dataDesc_324[21].td = 0;
    *(_QWORD *)&dataDesc_324[21].override_field = 0;
    *(_QWORD *)&dataDesc_324[21].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_324[21].flatOffset[1] = 0;
    dataDesc_324[20].flags = 8;
    dataDesc_324[21].fieldSize = 1;
    *(_QWORD *)&dataDesc_324[22].td = 0;
    *(_QWORD *)&dataDesc_324[22].override_field = 0;
    *(_QWORD *)&dataDesc_324[22].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_324[22].flatOffset[1] = 0;
    dataDesc_324[21].flags = 8;
    dataDesc_324[22].fieldSize = 1;
    *(_QWORD *)&dataDesc_324[23].td = 0;
    *(_QWORD *)&dataDesc_324[23].override_field = 0;
    *(_QWORD *)&dataDesc_324[23].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_324[23].flatOffset[1] = 0;
    dataDesc_324[22].flags = 8;
    dataDesc_324[23].fieldSize = 1;
    *(_QWORD *)&dataDesc_324[24].td = 0;
    *(_QWORD *)&dataDesc_324[24].override_field = 0;
    *(_QWORD *)&dataDesc_324[24].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_324[24].flatOffset[1] = 0;
    dataDesc_324[20].externalName = "SetFModType";
    dataDesc_324[20].pSaveRestoreOps = nullptr;
    dataDesc_324[20].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPoseController::InputSetFModType;
    dataDesc_324[21].fieldType = FIELD_FLOAT;
    dataDesc_324[21].fieldName = "InputSetFModTimeOffset";
    dataDesc_324[21].fieldOffset = 0;
    dataDesc_324[21].externalName = "SetFModTimeOffset";
    dataDesc_324[21].pSaveRestoreOps = nullptr;
    dataDesc_324[21].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPoseController::InputSetFModTimeOffset;
    dataDesc_324[22].fieldType = FIELD_FLOAT;
    dataDesc_324[22].fieldName = "InputSetFModRate";
    dataDesc_324[22].fieldOffset = 0;
    dataDesc_324[22].externalName = "SetFModRate";
    dataDesc_324[22].pSaveRestoreOps = nullptr;
    dataDesc_324[22].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPoseController::InputSetFModRate;
    dataDesc_324[23].fieldType = FIELD_FLOAT;
    dataDesc_324[23].fieldName = "InputSetFModAmplitude";
    dataDesc_324[23].fieldOffset = 0;
    dataDesc_324[23].flags = 8;
    dataDesc_324[23].externalName = "SetFModAmplitude";
    dataDesc_324[23].pSaveRestoreOps = nullptr;
    dataDesc_324[23].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPoseController::InputSetFModAmplitude;
    dataDesc_324[24].fieldType = FIELD_FLOAT;
    dataDesc_324[24].fieldName = "InputRandomizeFMod";
    dataDesc_324[24].fieldOffset = 0;
    *(_DWORD *)&dataDesc_324[24].fieldSize = 524289;
    dataDesc_324[24].externalName = "RandomizeFMod";
    dataDesc_324[24].pSaveRestoreOps = nullptr;
    dataDesc_324[24].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPoseController::InputRandomizeFMod;
    dataDesc_324[25].fieldType = FIELD_VOID;
    dataDesc_324[25].fieldName = "InputGetFMod";
    dataDesc_324[25].fieldOffset = 0;
    *(_DWORD *)&dataDesc_324[25].fieldSize = 524289;
    dataDesc_324[25].externalName = "GetFMod";
    dataDesc_324[25].pSaveRestoreOps = nullptr;
    dataDesc_324[25].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPoseController::InputGetFMod;
    *(_QWORD *)&dataDesc_324[25].td = 0;
    *(_QWORD *)&dataDesc_324[25].override_field = 0;
    *(_QWORD *)&dataDesc_324[25].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_324[25].flatOffset[1] = 0;
  }
  CPoseController::m_DataMap.dataNumFields = 25;
  CPoseController::m_DataMap.dataDesc = &dataDesc_324[1];
  return &CPoseController::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101D8D40
// Name: struct datamap_t __near * DataMapInit<class CPointAngleSensor>(class CPointAngleSensor __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CPointAngleSensor>()
{
  if ( (_S2_182 & 1) == 0 )
  {
    _S2_182 |= 1u;
    nameHolder_343.m_pszBase = "CPointAngleSensor";
    nameHolder_343.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_343.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_343.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_343.m_Names.m_Size = 0;
    nameHolder_343.m_Names.m_pElements = nullptr;
    nameHolder_343.m_nLenBase = 17;
    atexit(func: DataMapInit_CPointAngleSensor__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CPointAngleSensor::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S2_182 & 2) == 0 )
  {
    _S2_182 |= 2u;
    *(_QWORD *)&dataDesc_328[9].inputFunc = 0;
    *(_QWORD *)&dataDesc_328[9].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_328[9].override_count = 0;
    *(_QWORD *)dataDesc_328[9].flatOffset = 0;
    dataDesc_328[10].fieldSize = 1;
    *(_QWORD *)&dataDesc_328[10].inputFunc = 0;
    *(_QWORD *)&dataDesc_328[10].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_328[10].override_count = 0;
    *(_QWORD *)dataDesc_328[10].flatOffset = 0;
    dataDesc_328[10].flags = 22;
    *(_QWORD *)&dataDesc_328[11].inputFunc = 0;
    *(_QWORD *)&dataDesc_328[11].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_328[11].override_count = 0;
    *(_QWORD *)dataDesc_328[11].flatOffset = 0;
    dataDesc_328[10].fieldType = FIELD_CUSTOM;
    dataDesc_328[11].fieldType = FIELD_CUSTOM;
    dataDesc_328[12].fieldType = FIELD_CUSTOM;
    dataDesc_328[11].fieldSize = 1;
    *(_QWORD *)&dataDesc_328[12].inputFunc = 0;
    *(_QWORD *)&dataDesc_328[12].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_328[12].override_count = 0;
    *(_QWORD *)dataDesc_328[12].flatOffset = 0;
    dataDesc_328[12].fieldSize = 1;
    *(_QWORD *)&dataDesc_328[13].td = 0;
    *(_QWORD *)&dataDesc_328[13].override_field = 0;
    *(_QWORD *)&dataDesc_328[13].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_328[13].flatOffset[1] = 0;
    dataDesc_328[9].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_328[9].flatGroup = 0;
    dataDesc_328[10].fieldName = "m_OnNotFacingLookat";
    dataDesc_328[10].fieldOffset = 908;
    dataDesc_328[10].externalName = "OnNotFacingLookat";
    dataDesc_328[10].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_328[10].flatGroup = 0;
    dataDesc_328[11].fieldName = "m_TargetDir";
    dataDesc_328[11].fieldOffset = 932;
    dataDesc_328[11].flags = 22;
    dataDesc_328[11].externalName = "TargetDir";
    dataDesc_328[11].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_328[11].flatGroup = 0;
    dataDesc_328[12].fieldName = "m_FacingPercentage";
    dataDesc_328[12].fieldOffset = 956;
    dataDesc_328[12].flags = 22;
    dataDesc_328[12].externalName = "FacingPercentage";
    dataDesc_328[12].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_328[12].flatGroup = 0;
    dataDesc_328[13].fieldType = FIELD_VOID;
    dataDesc_328[13].fieldName = "InputEnable";
    dataDesc_328[13].fieldOffset = 0;
    *(_DWORD *)&dataDesc_328[13].fieldSize = 524289;
    dataDesc_328[13].externalName = "Enable";
    dataDesc_328[13].pSaveRestoreOps = nullptr;
    dataDesc_328[13].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPointAngleSensor::InputEnable;
    dataDesc_328[14].fieldType = FIELD_VOID;
    dataDesc_328[14].fieldName = "InputDisable";
    dataDesc_328[14].fieldOffset = 0;
    *(_DWORD *)&dataDesc_328[14].fieldSize = 524289;
    dataDesc_328[14].externalName = "Disable";
    dataDesc_328[14].pSaveRestoreOps = nullptr;
    dataDesc_328[14].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPointProximitySensor::InputDisable;
    *(_QWORD *)&dataDesc_328[14].td = 0;
    *(_QWORD *)&dataDesc_328[14].override_field = 0;
    *(_QWORD *)&dataDesc_328[14].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_328[14].flatOffset[1] = 0;
    dataDesc_328[15].fieldType = FIELD_VOID;
    *(_QWORD *)&dataDesc_328[15].td = 0;
    *(_QWORD *)&dataDesc_328[15].override_field = 0;
    *(_QWORD *)&dataDesc_328[15].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_328[15].flatOffset[1] = 0;
    *(_QWORD *)&dataDesc_328[16].td = 0;
    *(_QWORD *)&dataDesc_328[16].override_field = 0;
    *(_QWORD *)&dataDesc_328[16].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_328[16].flatOffset[1] = 0;
    dataDesc_328[15].fieldName = "InputToggle";
    dataDesc_328[15].fieldOffset = 0;
    *(_DWORD *)&dataDesc_328[15].fieldSize = 524289;
    dataDesc_328[15].externalName = "Toggle";
    dataDesc_328[15].pSaveRestoreOps = nullptr;
    dataDesc_328[15].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPointAngleSensor::InputToggle;
    dataDesc_328[16].fieldType = FIELD_VOID;
    dataDesc_328[16].fieldName = "InputTest";
    dataDesc_328[16].fieldOffset = 0;
    *(_DWORD *)&dataDesc_328[16].fieldSize = 524289;
    dataDesc_328[16].externalName = "Test";
    dataDesc_328[16].pSaveRestoreOps = nullptr;
    dataDesc_328[16].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPointAngleSensor::InputTest;
    dataDesc_328[17].fieldType = FIELD_STRING;
    dataDesc_328[17].fieldName = "InputSetTargetEntity";
    dataDesc_328[17].fieldOffset = 0;
    *(_DWORD *)&dataDesc_328[17].fieldSize = 524289;
    dataDesc_328[17].externalName = "SetTargetEntity";
    dataDesc_328[17].pSaveRestoreOps = nullptr;
    dataDesc_328[17].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPointAngleSensor::InputSetTargetEntity;
    *(_QWORD *)&dataDesc_328[17].td = 0;
    *(_QWORD *)&dataDesc_328[17].override_field = 0;
    *(_QWORD *)&dataDesc_328[17].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_328[17].flatOffset[1] = 0;
  }
  CPointAngleSensor::m_DataMap.dataNumFields = 17;
  CPointAngleSensor::m_DataMap.dataDesc = &dataDesc_328[1];
  return &CPointAngleSensor::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101D9120
// Name: struct datamap_t __near * DataMapInit<class CPointProximitySensor>(class CPointProximitySensor __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CPointProximitySensor>()
{
  if ( (_S3_101 & 1) == 0 )
  {
    _S3_101 |= 1u;
    nameHolder_344.m_pszBase = "CPointProximitySensor";
    nameHolder_344.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_344.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_344.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_344.m_Names.m_Size = 0;
    nameHolder_344.m_Names.m_pElements = nullptr;
    nameHolder_344.m_nLenBase = 21;
    atexit(func: DataMapInit_CPointProximitySensor__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CPointProximitySensor::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S3_101 & 2) == 0 )
  {
    _S3_101 |= 2u;
    *(_QWORD *)&dataDesc_329[3].inputFunc = 0;
    *(_QWORD *)&dataDesc_329[3].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_329[3].override_count = 0;
    *(_QWORD *)dataDesc_329[3].flatOffset = 0;
    *(_QWORD *)&dataDesc_329[4].td = 0;
    *(_QWORD *)&dataDesc_329[4].override_field = 0;
    *(_QWORD *)&dataDesc_329[4].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_329[4].flatOffset[1] = 0;
    *(_QWORD *)&dataDesc_329[5].td = 0;
    *(_QWORD *)&dataDesc_329[5].override_field = 0;
    *(_QWORD *)&dataDesc_329[5].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_329[5].flatOffset[1] = 0;
    dataDesc_329[3].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_329[6].td = 0;
    *(_QWORD *)&dataDesc_329[6].override_field = 0;
    *(_QWORD *)&dataDesc_329[6].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_329[6].flatOffset[1] = 0;
    *(_DWORD *)&dataDesc_329[3].flatGroup = 0;
    dataDesc_329[4].fieldType = FIELD_VOID;
    dataDesc_329[4].fieldName = "InputEnable";
    dataDesc_329[4].fieldOffset = 0;
    dataDesc_329[4].fieldSize = 1;
    dataDesc_329[4].flags = 8;
    dataDesc_329[4].externalName = "Enable";
    dataDesc_329[4].pSaveRestoreOps = nullptr;
    dataDesc_329[4].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPointProximitySensor::InputEnable;
    dataDesc_329[5].fieldType = FIELD_VOID;
    dataDesc_329[5].fieldName = "InputDisable";
    dataDesc_329[5].fieldOffset = 0;
    dataDesc_329[5].fieldSize = 1;
    dataDesc_329[5].flags = 8;
    dataDesc_329[5].externalName = "Disable";
    dataDesc_329[5].pSaveRestoreOps = nullptr;
    dataDesc_329[5].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPointProximitySensor::InputDisable;
    dataDesc_329[6].fieldType = FIELD_VOID;
    dataDesc_329[6].fieldName = "InputToggle";
    dataDesc_329[6].fieldOffset = 0;
    dataDesc_329[6].fieldSize = 1;
    dataDesc_329[6].flags = 8;
    dataDesc_329[6].externalName = "Toggle";
    dataDesc_329[6].pSaveRestoreOps = nullptr;
    dataDesc_329[6].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPointProximitySensor::InputToggle;
    dataDesc_329[7].fieldType = FIELD_STRING;
    dataDesc_329[7].fieldName = "InputSetTargetEntity";
    dataDesc_329[7].fieldOffset = 0;
    *(_DWORD *)&dataDesc_329[7].fieldSize = 524289;
    dataDesc_329[7].externalName = "SetTargetEntity";
    dataDesc_329[7].pSaveRestoreOps = nullptr;
    dataDesc_329[7].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPointProximitySensor::InputSetTargetEntity;
    *(_QWORD *)&dataDesc_329[7].td = 0;
    *(_QWORD *)&dataDesc_329[7].override_field = 0;
    *(_QWORD *)&dataDesc_329[7].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_329[7].flatOffset[1] = 0;
  }
  CPointProximitySensor::m_DataMap.dataNumFields = 7;
  CPointProximitySensor::m_DataMap.dataDesc = &dataDesc_329[1];
  return &CPointProximitySensor::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101DA5F0
// Name: struct datamap_t __near * DataMapInit<class CPointAngularVelocitySensor>(class CPointAngularVelocitySensor __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CPointAngularVelocitySensor>()
{
  if ( (_S2_183 & 1) == 0 )
  {
    _S2_183 |= 1u;
    nameHolder_345.m_pszBase = "CPointAngularVelocitySensor";
    nameHolder_345.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_345.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_345.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_345.m_Names.m_Size = 0;
    nameHolder_345.m_Names.m_pElements = nullptr;
    nameHolder_345.m_nLenBase = 27;
    atexit(func: DataMapInit_CPointAngularVelocitySensor__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CPointAngularVelocitySensor::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S2_183 & 2) == 0 )
  {
    _S2_183 |= 2u;
    dataDesc_330[12].fieldSize = 1;
    dataDesc_330[12].flags = 22;
    dataDesc_330[13].fieldSize = 1;
    dataDesc_330[13].flags = 22;
    *(_QWORD *)&dataDesc_330[11].inputFunc = 0;
    *(_QWORD *)&dataDesc_330[11].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_330[11].override_count = 0;
    *(_QWORD *)dataDesc_330[11].flatOffset = 0;
    *(_QWORD *)&dataDesc_330[12].inputFunc = 0;
    *(_QWORD *)&dataDesc_330[12].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_330[12].override_count = 0;
    *(_QWORD *)dataDesc_330[12].flatOffset = 0;
    dataDesc_330[14].fieldSize = 1;
    *(_QWORD *)&dataDesc_330[13].inputFunc = 0;
    *(_QWORD *)&dataDesc_330[13].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_330[13].override_count = 0;
    *(_QWORD *)dataDesc_330[13].flatOffset = 0;
    dataDesc_330[14].flags = 22;
    *(_QWORD *)&dataDesc_330[14].inputFunc = 0;
    *(_QWORD *)&dataDesc_330[14].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_330[14].override_count = 0;
    *(_QWORD *)dataDesc_330[14].flatOffset = 0;
    dataDesc_330[15].fieldSize = 1;
    *(_QWORD *)&dataDesc_330[15].inputFunc = 0;
    *(_QWORD *)&dataDesc_330[15].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_330[15].override_count = 0;
    *(_QWORD *)dataDesc_330[15].flatOffset = 0;
    dataDesc_330[11].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_330[11].flatGroup = 0;
    dataDesc_330[12].fieldType = FIELD_CUSTOM;
    dataDesc_330[12].fieldName = "m_OnLessThanOrEqualTo";
    dataDesc_330[12].fieldOffset = 956;
    dataDesc_330[12].externalName = "OnLessThanOrEqualTo";
    dataDesc_330[12].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_330[12].flatGroup = 0;
    dataDesc_330[13].fieldType = FIELD_CUSTOM;
    dataDesc_330[13].fieldName = "m_OnGreaterThan";
    dataDesc_330[13].fieldOffset = 980;
    dataDesc_330[13].externalName = "OnGreaterThan";
    dataDesc_330[13].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_330[13].flatGroup = 0;
    dataDesc_330[14].fieldType = FIELD_CUSTOM;
    dataDesc_330[14].fieldName = "m_OnGreaterThanOrEqualTo";
    dataDesc_330[14].fieldOffset = 1004;
    dataDesc_330[14].externalName = "OnGreaterThanOrEqualTo";
    dataDesc_330[14].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_330[14].flatGroup = 0;
    dataDesc_330[15].fieldType = FIELD_CUSTOM;
    dataDesc_330[15].fieldName = "m_OnEqualTo";
    dataDesc_330[15].fieldOffset = 1028;
    dataDesc_330[15].flags = 22;
    dataDesc_330[15].externalName = "OnEqualTo";
    dataDesc_330[15].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_330[15].flatGroup = 0;
    dataDesc_330[16].fieldType = FIELD_CUSTOM;
    dataDesc_330[16].fieldName = "m_AngularVelocity";
    dataDesc_330[16].fieldOffset = 908;
    *(_DWORD *)&dataDesc_330[16].fieldSize = 1441793;
    dataDesc_330[16].externalName = "AngularVelocity";
    dataDesc_330[16].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_330[16].inputFunc = 0;
    *(_QWORD *)&dataDesc_330[16].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_330[16].override_count = 0;
    *(_QWORD *)dataDesc_330[16].flatOffset = 0;
    dataDesc_330[17].fieldTolerance = 0.0;
    dataDesc_330[18].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_330[16].flatGroup = 0;
    dataDesc_330[17].fieldType = FIELD_VECTOR;
    dataDesc_330[17].fieldName = "m_vecAxis";
    dataDesc_330[17].fieldOffset = 892;
    *(_DWORD *)&dataDesc_330[17].fieldSize = 393217;
    dataDesc_330[17].externalName = "axis";
    dataDesc_330[17].pSaveRestoreOps = nullptr;
    dataDesc_330[17].inputFunc = nullptr;
    dataDesc_330[17].td = nullptr;
    dataDesc_330[17].fieldSizeInBytes = 12;
    dataDesc_330[17].override_field = nullptr;
    dataDesc_330[17].override_count = 0;
    *(_QWORD *)dataDesc_330[17].flatOffset = 0;
    *(_DWORD *)&dataDesc_330[17].flatGroup = 0;
    dataDesc_330[18].fieldType = FIELD_BOOLEAN;
    dataDesc_330[18].fieldName = "m_bUseHelper";
    dataDesc_330[18].fieldOffset = 904;
    *(_DWORD *)&dataDesc_330[18].fieldSize = 393217;
    dataDesc_330[18].externalName = "usehelper";
    dataDesc_330[18].pSaveRestoreOps = nullptr;
    dataDesc_330[18].inputFunc = nullptr;
    dataDesc_330[18].td = nullptr;
    dataDesc_330[18].fieldSizeInBytes = 1;
    dataDesc_330[18].override_field = nullptr;
    dataDesc_330[18].override_count = 0;
    *(_QWORD *)dataDesc_330[18].flatOffset = 0;
    *(_DWORD *)&dataDesc_330[18].flatGroup = 0;
  }
  CPointAngularVelocitySensor::m_DataMap.dataNumFields = 18;
  CPointAngularVelocitySensor::m_DataMap.dataDesc = &dataDesc_330[1];
  return &CPointAngularVelocitySensor::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101DA9B0
// Name: struct datamap_t __near * DataMapInit<class CPointVelocitySensor>(class CPointVelocitySensor __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CPointVelocitySensor>()
{
  if ( (_S3_102 & 1) == 0 )
  {
    _S3_102 |= 1u;
    nameHolder_346.m_pszBase = "CPointVelocitySensor";
    nameHolder_346.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_346.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_346.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_346.m_Names.m_Size = 0;
    nameHolder_346.m_Names.m_pElements = nullptr;
    nameHolder_346.m_nLenBase = 20;
    atexit(func: DataMapInit_CPointVelocitySensor__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CPointVelocitySensor::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S3_102 & 2) == 0 )
  {
    _S3_102 |= 2u;
    *(_QWORD *)&dataDesc_331[5].inputFunc = 0;
    *(_QWORD *)&dataDesc_331[5].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_331[5].override_count = 0;
    *(_QWORD *)dataDesc_331[5].flatOffset = 0;
    *(_QWORD *)&dataDesc_331[6].td = 0;
    *(_QWORD *)&dataDesc_331[6].override_field = 0;
    *(_QWORD *)&dataDesc_331[6].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_331[6].flatOffset[1] = 0;
    dataDesc_331[5].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_331[5].flatGroup = 0;
    dataDesc_331[6].fieldType = FIELD_VOID;
    dataDesc_331[6].fieldName = "InputEnable";
    dataDesc_331[6].fieldOffset = 0;
    dataDesc_331[6].fieldSize = 1;
    dataDesc_331[6].flags = 8;
    dataDesc_331[6].externalName = "Enable";
    dataDesc_331[6].pSaveRestoreOps = nullptr;
    dataDesc_331[6].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPointVelocitySensor::InputEnable;
    dataDesc_331[7].fieldType = FIELD_VOID;
    dataDesc_331[7].fieldName = "InputDisable";
    dataDesc_331[7].fieldOffset = 0;
    *(_DWORD *)&dataDesc_331[7].fieldSize = 524289;
    dataDesc_331[7].externalName = "Disable";
    dataDesc_331[7].pSaveRestoreOps = nullptr;
    dataDesc_331[7].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CLogicEventListener::InputDisable;
    *(_QWORD *)&dataDesc_331[7].td = 0;
    *(_QWORD *)&dataDesc_331[7].override_field = 0;
    *(_QWORD *)&dataDesc_331[7].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_331[7].flatOffset[1] = 0;
  }
  CPointVelocitySensor::m_DataMap.dataNumFields = 7;
  CPointVelocitySensor::m_DataMap.dataDesc = &dataDesc_331[1];
  return &CPointVelocitySensor::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101DAFD0
// Name: struct datamap_t __near * DataMapInit<class CPointHurt>(class CPointHurt __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CPointHurt>()
{
  char *Name; // eax

  if ( (_S2_184 & 1) == 0 )
  {
    _S2_184 |= 1u;
    nameHolder_347.m_pszBase = "CPointHurt";
    nameHolder_347.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_347.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_347.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_347.m_Names.m_Size = 0;
    nameHolder_347.m_Names.m_pElements = nullptr;
    nameHolder_347.m_nLenBase = 10;
    atexit(func: DataMapInit_CPointHurt__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CPointHurt::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S2_184 & 2) == 0 )
  {
    _S2_184 |= 2u;
    Name = CDatadescGeneratedNameHolder::GenerateName(this: &nameHolder_347, pszIdentifier: "HurtThink");
    *(_QWORD *)&dataDesc_332[6].td = 0;
    *(_QWORD *)&dataDesc_332[6].override_field = 0;
    *(_QWORD *)&dataDesc_332[6].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_332[6].flatOffset[1] = 0;
    *(_QWORD *)&dataDesc_332[7].td = 0;
    *(_QWORD *)&dataDesc_332[7].override_field = 0;
    *(_QWORD *)&dataDesc_332[7].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_332[7].flatOffset[1] = 0;
    *(_QWORD *)&dataDesc_332[8].td = 0;
    *(_QWORD *)&dataDesc_332[8].override_field = 0;
    *(_QWORD *)&dataDesc_332[8].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_332[8].flatOffset[1] = 0;
    *(_QWORD *)&dataDesc_332[9].td = 0;
    *(_QWORD *)&dataDesc_332[9].override_field = 0;
    *(_QWORD *)&dataDesc_332[9].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_332[9].flatOffset[1] = 0;
    *(_QWORD *)&dataDesc_332[10].td = 0;
    *(_QWORD *)&dataDesc_332[10].override_field = 0;
    *(_QWORD *)&dataDesc_332[10].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_332[10].flatOffset[1] = 0;
    dataDesc_332[11].fieldTolerance = 0.0;
    dataDesc_332[6].fieldName = Name;
    dataDesc_332[6].fieldOffset = 0;
    *(_DWORD *)&dataDesc_332[6].fieldSize = 2097153;
    dataDesc_332[6].externalName = nullptr;
    dataDesc_332[6].pSaveRestoreOps = nullptr;
    dataDesc_332[6].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPointHurt::HurtThink;
    dataDesc_332[7].fieldType = FIELD_VOID;
    dataDesc_332[7].fieldName = "InputTurnOn";
    dataDesc_332[7].fieldOffset = 0;
    *(_DWORD *)&dataDesc_332[7].fieldSize = 524289;
    dataDesc_332[7].externalName = "TurnOn";
    dataDesc_332[7].pSaveRestoreOps = nullptr;
    dataDesc_332[7].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPointHurt::InputTurnOn;
    dataDesc_332[8].fieldType = FIELD_VOID;
    dataDesc_332[8].fieldName = "InputTurnOff";
    dataDesc_332[8].fieldOffset = 0;
    *(_DWORD *)&dataDesc_332[8].fieldSize = 524289;
    dataDesc_332[8].externalName = "TurnOff";
    dataDesc_332[8].pSaveRestoreOps = nullptr;
    dataDesc_332[8].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPointHurt::InputTurnOff;
    dataDesc_332[9].fieldType = FIELD_VOID;
    dataDesc_332[9].fieldName = "InputToggle";
    dataDesc_332[9].fieldOffset = 0;
    *(_DWORD *)&dataDesc_332[9].fieldSize = 524289;
    dataDesc_332[9].externalName = "Toggle";
    dataDesc_332[9].pSaveRestoreOps = nullptr;
    dataDesc_332[9].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPointHurt::InputToggle;
    dataDesc_332[10].fieldType = FIELD_VOID;
    dataDesc_332[10].fieldName = "InputHurt";
    dataDesc_332[10].fieldOffset = 0;
    *(_DWORD *)&dataDesc_332[10].fieldSize = 524289;
    dataDesc_332[10].externalName = "Hurt";
    dataDesc_332[10].pSaveRestoreOps = nullptr;
    dataDesc_332[10].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPointHurt::InputHurt;
    dataDesc_332[11].fieldType = FIELD_EHANDLE;
    dataDesc_332[11].fieldName = "m_pActivator";
    dataDesc_332[11].fieldOffset = 872;
    *(_DWORD *)&dataDesc_332[11].fieldSize = 131073;
    dataDesc_332[11].externalName = nullptr;
    dataDesc_332[11].pSaveRestoreOps = nullptr;
    dataDesc_332[11].inputFunc = nullptr;
    dataDesc_332[11].td = nullptr;
    dataDesc_332[11].fieldSizeInBytes = 4;
    dataDesc_332[11].override_field = nullptr;
    dataDesc_332[11].override_count = 0;
    *(_QWORD *)dataDesc_332[11].flatOffset = 0;
    *(_DWORD *)&dataDesc_332[11].flatGroup = 0;
  }
  CPointHurt::m_DataMap.dataNumFields = 11;
  CPointHurt::m_DataMap.dataDesc = &dataDesc_332[1];
  return &CPointHurt::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101DB6A0
// Name: struct datamap_t __near * DataMapInit<class CPointTeleport>(class CPointTeleport __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CPointTeleport>()
{
  if ( (_S2_185 & 1) == 0 )
  {
    _S2_185 |= 1u;
    nameHolder_348.m_pszBase = "CPointTeleport";
    nameHolder_348.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_348.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_348.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_348.m_Names.m_Size = 0;
    nameHolder_348.m_Names.m_pElements = nullptr;
    nameHolder_348.m_nLenBase = 14;
    atexit(func: DataMapInit_CPointTeleport__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CPointTeleport::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CPointTeleport::m_DataMap.dataNumFields = 5;
  CPointTeleport::m_DataMap.dataDesc = &dataDesc_333[1];
  return &CPointTeleport::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101DBFF0
// Name: struct datamap_t __near * DataMapInit<class CPostProcessController>(class CPostProcessController __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CPostProcessController>()
{
  if ( (_S2_186 & 1) == 0 )
  {
    _S2_186 |= 1u;
    nameHolder_349.m_pszBase = "CPostProcessController";
    nameHolder_349.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_349.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_349.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_349.m_Names.m_Size = 0;
    nameHolder_349.m_Names.m_pElements = nullptr;
    nameHolder_349.m_nLenBase = 22;
    atexit(func: DataMapInit_CPostProcessController__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CPostProcessController::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S2_186 & 2) == 0 )
  {
    _S2_186 |= 2u;
    *(_QWORD *)dataDesc_334[1].flatOffset = 0;
    dataDesc_334[1].flags = 6;
    dataDesc_334[2].flags = 6;
    dataDesc_334[3].flags = 6;
    *(_QWORD *)dataDesc_334[2].flatOffset = 0;
    dataDesc_334[1].fieldSize = 1;
    dataDesc_334[2].fieldSize = 1;
    dataDesc_334[3].fieldSize = 1;
    dataDesc_334[4].fieldType = FIELD_TIME;
    dataDesc_334[4].fieldSize = 1;
    dataDesc_334[5].fieldType = FIELD_TIME;
    *(_QWORD *)dataDesc_334[3].flatOffset = 0;
    dataDesc_334[1].fieldOffset = 852;
    dataDesc_334[1].externalName = "fadetime";
    dataDesc_334[1].pSaveRestoreOps = nullptr;
    dataDesc_334[1].inputFunc = nullptr;
    dataDesc_334[1].td = nullptr;
    dataDesc_334[1].fieldSizeInBytes = 4;
    dataDesc_334[1].override_field = nullptr;
    dataDesc_334[1].override_count = 0;
    dataDesc_334[1].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_334[1].flatGroup = 0;
    dataDesc_334[2].fieldType = FIELD_FLOAT;
    dataDesc_334[2].fieldName = "m_flPostProcessParameters[ PPPN_LOCAL_CONTRAST_STRENGTH ]";
    dataDesc_334[2].fieldOffset = 856;
    dataDesc_334[2].externalName = "localcontraststrength";
    dataDesc_334[2].pSaveRestoreOps = nullptr;
    dataDesc_334[2].inputFunc = nullptr;
    dataDesc_334[2].td = nullptr;
    dataDesc_334[2].fieldSizeInBytes = 4;
    dataDesc_334[2].override_field = nullptr;
    dataDesc_334[2].override_count = 0;
    dataDesc_334[2].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_334[2].flatGroup = 0;
    dataDesc_334[3].fieldType = FIELD_FLOAT;
    dataDesc_334[3].fieldName = "m_flPostProcessParameters[ PPPN_LOCAL_CONTRAST_EDGE_STRENGTH ]";
    dataDesc_334[3].fieldOffset = 860;
    dataDesc_334[3].externalName = "localcontrastedgestrength";
    dataDesc_334[3].pSaveRestoreOps = nullptr;
    dataDesc_334[3].inputFunc = nullptr;
    dataDesc_334[3].td = nullptr;
    dataDesc_334[3].fieldSizeInBytes = 4;
    dataDesc_334[3].override_field = nullptr;
    dataDesc_334[3].override_count = 0;
    dataDesc_334[3].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_334[3].flatGroup = 0;
    dataDesc_334[4].fieldName = "m_flPostProcessParameters[ PPPN_VIGNETTE_START ]";
    dataDesc_334[4].fieldOffset = 864;
    dataDesc_334[4].flags = 6;
    dataDesc_334[4].externalName = "vignettestart";
    dataDesc_334[4].pSaveRestoreOps = nullptr;
    dataDesc_334[4].inputFunc = nullptr;
    dataDesc_334[4].td = nullptr;
    dataDesc_334[4].fieldSizeInBytes = 4;
    dataDesc_334[4].override_field = nullptr;
    dataDesc_334[4].override_count = 0;
    dataDesc_334[4].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_334[4].flatOffset = 0;
    *(_DWORD *)&dataDesc_334[4].flatGroup = 0;
    dataDesc_334[5].fieldName = "m_flPostProcessParameters[ PPPN_VIGNETTE_END ]";
    dataDesc_334[5].fieldOffset = 868;
    dataDesc_334[5].fieldSize = 1;
    dataDesc_334[5].flags = 6;
    dataDesc_334[5].externalName = "vignetteend";
    dataDesc_334[5].pSaveRestoreOps = nullptr;
    dataDesc_334[5].inputFunc = nullptr;
    dataDesc_334[5].td = nullptr;
    dataDesc_334[5].fieldSizeInBytes = 4;
    *(_QWORD *)dataDesc_334[5].flatOffset = 0;
    *(_QWORD *)dataDesc_334[6].flatOffset = 0;
    *(_QWORD *)dataDesc_334[7].flatOffset = 0;
    *(_QWORD *)dataDesc_334[8].flatOffset = 0;
    dataDesc_334[5].override_field = nullptr;
    dataDesc_334[5].override_count = 0;
    dataDesc_334[5].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_334[5].flatGroup = 0;
    dataDesc_334[6].fieldType = FIELD_FLOAT;
    dataDesc_334[6].fieldName = "m_flPostProcessParameters[ PPPN_VIGNETTE_BLUR_STRENGTH ]";
    dataDesc_334[6].fieldOffset = 872;
    dataDesc_334[6].fieldSize = 1;
    dataDesc_334[6].flags = 6;
    dataDesc_334[6].externalName = "vignetteblurstrength";
    dataDesc_334[6].pSaveRestoreOps = nullptr;
    dataDesc_334[6].inputFunc = nullptr;
    dataDesc_334[6].td = nullptr;
    dataDesc_334[6].fieldSizeInBytes = 4;
    dataDesc_334[6].override_field = nullptr;
    dataDesc_334[6].override_count = 0;
    dataDesc_334[6].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_334[6].flatGroup = 0;
    dataDesc_334[7].fieldType = FIELD_FLOAT;
    dataDesc_334[7].fieldName = "m_flPostProcessParameters[ PPPN_FADE_TO_BLACK_STRENGTH ]";
    dataDesc_334[7].fieldOffset = 876;
    dataDesc_334[7].fieldSize = 1;
    dataDesc_334[7].flags = 6;
    dataDesc_334[7].externalName = "fadetoblackstrength";
    dataDesc_334[7].pSaveRestoreOps = nullptr;
    dataDesc_334[7].inputFunc = nullptr;
    dataDesc_334[7].td = nullptr;
    dataDesc_334[7].fieldSizeInBytes = 4;
    dataDesc_334[7].override_field = nullptr;
    dataDesc_334[7].override_count = 0;
    dataDesc_334[7].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_334[7].flatGroup = 0;
    dataDesc_334[8].fieldType = FIELD_FLOAT;
    dataDesc_334[8].fieldName = "m_flPostProcessParameters[ PPPN_DEPTH_BLUR_FOCAL_DISTANCE ]";
    dataDesc_334[8].fieldOffset = 880;
    dataDesc_334[8].fieldSize = 1;
    dataDesc_334[8].flags = 6;
    dataDesc_334[8].externalName = "depthblurfocaldistance";
    dataDesc_334[8].pSaveRestoreOps = nullptr;
    dataDesc_334[8].inputFunc = nullptr;
    dataDesc_334[8].td = nullptr;
    dataDesc_334[8].fieldSizeInBytes = 4;
    dataDesc_334[8].override_field = nullptr;
    dataDesc_334[8].override_count = 0;
    dataDesc_334[8].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_334[8].flatGroup = 0;
    dataDesc_334[9].fieldType = FIELD_FLOAT;
    dataDesc_334[9].fieldName = "m_flPostProcessParameters[ PPPN_DEPTH_BLUR_STRENGTH ]";
    dataDesc_334[9].fieldOffset = 884;
    dataDesc_334[9].fieldSize = 1;
    dataDesc_334[9].flags = 6;
    dataDesc_334[9].externalName = "depthblurstrength";
    dataDesc_334[9].pSaveRestoreOps = nullptr;
    dataDesc_334[9].inputFunc = nullptr;
    dataDesc_334[9].td = nullptr;
    dataDesc_334[9].fieldSizeInBytes = 4;
    dataDesc_334[9].override_field = nullptr;
    dataDesc_334[9].override_count = 0;
    dataDesc_334[9].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_334[9].flatOffset = 0;
    *(_DWORD *)&dataDesc_334[9].flatGroup = 0;
    dataDesc_334[10].fieldType = FIELD_FLOAT;
    dataDesc_334[10].fieldName = "m_flPostProcessParameters[ PPPN_SCREEN_BLUR_STRENGTH ]";
    dataDesc_334[10].fieldOffset = 888;
    dataDesc_334[10].fieldSize = 1;
    dataDesc_334[10].flags = 6;
    dataDesc_334[10].externalName = "screenblurstrength";
    dataDesc_334[10].pSaveRestoreOps = nullptr;
    dataDesc_334[10].inputFunc = nullptr;
    dataDesc_334[10].td = nullptr;
    dataDesc_334[10].fieldSizeInBytes = 4;
    dataDesc_334[10].override_field = nullptr;
    dataDesc_334[10].fieldTolerance = 0.0;
    dataDesc_334[11].fieldTolerance = 0.0;
    dataDesc_334[11].fieldSizeInBytes = 4;
    dataDesc_334[11].fieldSize = 1;
    *(_QWORD *)dataDesc_334[11].flatOffset = 0;
    dataDesc_334[11].flags = 6;
    dataDesc_334[12].fieldSize = 1;
    *(_QWORD *)&dataDesc_334[12].td = 0;
    *(_QWORD *)&dataDesc_334[12].override_field = 0;
    *(_QWORD *)&dataDesc_334[12].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_334[12].flatOffset[1] = 0;
    dataDesc_334[12].flags = 8;
    dataDesc_334[13].fieldSize = 1;
    *(_QWORD *)&dataDesc_334[13].td = 0;
    *(_QWORD *)&dataDesc_334[13].override_field = 0;
    *(_QWORD *)&dataDesc_334[13].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_334[13].flatOffset[1] = 0;
    dataDesc_334[13].flags = 8;
    dataDesc_334[14].fieldSize = 1;
    *(_QWORD *)&dataDesc_334[14].td = 0;
    *(_QWORD *)&dataDesc_334[14].override_field = 0;
    *(_QWORD *)&dataDesc_334[14].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_334[14].flatOffset[1] = 0;
    dataDesc_334[10].override_count = 0;
    *(_QWORD *)dataDesc_334[10].flatOffset = 0;
    *(_DWORD *)&dataDesc_334[10].flatGroup = 0;
    dataDesc_334[11].fieldType = FIELD_FLOAT;
    dataDesc_334[11].fieldName = "m_flPostProcessParameters[ PPPN_FILM_GRAIN_STRENGTH ]";
    dataDesc_334[11].fieldOffset = 892;
    dataDesc_334[11].externalName = "filmgrainstrength";
    dataDesc_334[11].pSaveRestoreOps = nullptr;
    dataDesc_334[11].inputFunc = nullptr;
    dataDesc_334[11].td = nullptr;
    dataDesc_334[11].override_field = nullptr;
    dataDesc_334[11].override_count = 0;
    *(_DWORD *)&dataDesc_334[11].flatGroup = 0;
    dataDesc_334[12].fieldType = FIELD_FLOAT;
    dataDesc_334[12].fieldName = "InputSetFadeTime";
    dataDesc_334[12].fieldOffset = 0;
    dataDesc_334[12].externalName = "SetFadeTime";
    dataDesc_334[12].pSaveRestoreOps = nullptr;
    dataDesc_334[12].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPostProcessController::InputSetFadeTime;
    dataDesc_334[13].fieldType = FIELD_FLOAT;
    dataDesc_334[13].fieldName = "InputSetLocalContrastStrength";
    dataDesc_334[13].fieldOffset = 0;
    dataDesc_334[13].externalName = "SetLocalContrastStrength";
    dataDesc_334[13].pSaveRestoreOps = nullptr;
    dataDesc_334[13].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPostProcessController::InputSetLocalContrastStrength;
    dataDesc_334[14].fieldType = FIELD_FLOAT;
    dataDesc_334[14].fieldName = "InputSetLocalContrastEdgeStrength";
    dataDesc_334[14].fieldOffset = 0;
    dataDesc_334[14].flags = 8;
    dataDesc_334[14].externalName = "SetLocalContrastEdgeStrength";
    dataDesc_334[14].pSaveRestoreOps = nullptr;
    dataDesc_334[14].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPostProcessController::InputSetLocalContrastEdgeStrength;
    dataDesc_334[15].fieldType = FIELD_FLOAT;
    dataDesc_334[15].fieldName = "InputSetVignetteStart";
    dataDesc_334[15].fieldOffset = 0;
    dataDesc_334[15].fieldSize = 1;
    dataDesc_334[15].flags = 8;
    dataDesc_334[15].externalName = "SetVignetteStart";
    dataDesc_334[15].pSaveRestoreOps = nullptr;
    dataDesc_334[15].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPostProcessController::InputSetVignetteStart;
    *(_QWORD *)&dataDesc_334[15].td = 0;
    *(_QWORD *)&dataDesc_334[15].override_field = 0;
    *(_QWORD *)&dataDesc_334[15].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_334[15].flatOffset[1] = 0;
    dataDesc_334[16].fieldSize = 1;
    dataDesc_334[16].flags = 8;
    *(_QWORD *)&dataDesc_334[16].td = 0;
    *(_QWORD *)&dataDesc_334[16].override_field = 0;
    *(_QWORD *)&dataDesc_334[16].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_334[16].flatOffset[1] = 0;
    dataDesc_334[17].fieldSize = 1;
    dataDesc_334[17].flags = 8;
    *(_QWORD *)&dataDesc_334[17].td = 0;
    *(_QWORD *)&dataDesc_334[17].override_field = 0;
    *(_QWORD *)&dataDesc_334[17].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_334[17].flatOffset[1] = 0;
    dataDesc_334[18].fieldSize = 1;
    dataDesc_334[18].flags = 8;
    *(_QWORD *)&dataDesc_334[18].td = 0;
    *(_QWORD *)&dataDesc_334[18].override_field = 0;
    *(_QWORD *)&dataDesc_334[18].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_334[18].flatOffset[1] = 0;
    dataDesc_334[19].fieldSize = 1;
    dataDesc_334[19].flags = 8;
    *(_QWORD *)&dataDesc_334[19].td = 0;
    *(_QWORD *)&dataDesc_334[19].override_field = 0;
    *(_QWORD *)&dataDesc_334[19].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_334[19].flatOffset[1] = 0;
    dataDesc_334[20].fieldSize = 1;
    dataDesc_334[16].fieldType = FIELD_FLOAT;
    dataDesc_334[16].fieldName = "InputSetVignetteEnd";
    dataDesc_334[16].fieldOffset = 0;
    dataDesc_334[16].externalName = "SetVignetteEnd";
    dataDesc_334[16].pSaveRestoreOps = nullptr;
    dataDesc_334[16].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPostProcessController::InputSetVignetteEnd;
    dataDesc_334[17].fieldType = FIELD_FLOAT;
    dataDesc_334[17].fieldName = "InputSetVignetteBlurStrength";
    dataDesc_334[17].fieldOffset = 0;
    dataDesc_334[17].externalName = "SetVignetteBlurStrength";
    dataDesc_334[17].pSaveRestoreOps = nullptr;
    dataDesc_334[17].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPostProcessController::InputSetVignetteBlurStrength;
    dataDesc_334[18].fieldType = FIELD_FLOAT;
    dataDesc_334[18].fieldName = "InputSetFadeToBlackStrength";
    dataDesc_334[18].fieldOffset = 0;
    dataDesc_334[18].externalName = "SetFadeToBlackStrength";
    dataDesc_334[18].pSaveRestoreOps = nullptr;
    dataDesc_334[18].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPostProcessController::InputSetFadeToBlackStrength;
    dataDesc_334[19].fieldType = FIELD_FLOAT;
    dataDesc_334[19].fieldName = "InputSetDepthBlurFocalDistance";
    dataDesc_334[19].fieldOffset = 0;
    dataDesc_334[19].externalName = "SetDepthBlurFocalDistance";
    dataDesc_334[19].pSaveRestoreOps = nullptr;
    dataDesc_334[19].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPostProcessController::InputSetDepthBlurFocalDistance;
    dataDesc_334[20].fieldType = FIELD_FLOAT;
    dataDesc_334[20].fieldName = "InputSetDepthBlurStrength";
    dataDesc_334[20].fieldOffset = 0;
    dataDesc_334[20].flags = 8;
    dataDesc_334[20].externalName = "SetDepthBlurStrength";
    dataDesc_334[20].pSaveRestoreOps = nullptr;
    dataDesc_334[20].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPostProcessController::InputSetDepthBlurStrength;
    *(_QWORD *)&dataDesc_334[20].td = 0;
    *(_QWORD *)&dataDesc_334[20].override_field = 0;
    *(_QWORD *)&dataDesc_334[20].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_334[20].flatOffset[1] = 0;
    dataDesc_334[21].fieldType = FIELD_FLOAT;
    dataDesc_334[21].fieldName = "InputSetScreenBlurStrength";
    dataDesc_334[21].fieldOffset = 0;
    dataDesc_334[21].fieldSize = 1;
    *(_QWORD *)&dataDesc_334[21].td = 0;
    *(_QWORD *)&dataDesc_334[21].override_field = 0;
    *(_QWORD *)&dataDesc_334[21].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_334[21].flatOffset[1] = 0;
    dataDesc_334[21].flags = 8;
    dataDesc_334[21].externalName = "SetScreenBlurStrength";
    dataDesc_334[21].pSaveRestoreOps = nullptr;
    dataDesc_334[21].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPostProcessController::InputSetScreenBlurStrength;
    dataDesc_334[22].fieldType = FIELD_FLOAT;
    dataDesc_334[22].fieldName = "InputSetFilmGrainStrength";
    dataDesc_334[22].fieldOffset = 0;
    *(_DWORD *)&dataDesc_334[22].fieldSize = 524289;
    dataDesc_334[22].externalName = "SetFilmGrainStrength";
    dataDesc_334[22].pSaveRestoreOps = nullptr;
    dataDesc_334[22].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPostProcessController::InputSetFilmGrainStrength;
    *(_QWORD *)&dataDesc_334[22].td = 0;
    *(_QWORD *)&dataDesc_334[22].override_field = 0;
    *(_QWORD *)&dataDesc_334[22].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_334[22].flatOffset[1] = 0;
  }
  CPostProcessController::m_DataMap.dataNumFields = 22;
  CPostProcessController::m_DataMap.dataDesc = &dataDesc_334[1];
  return &CPostProcessController::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101F00B0
// Name: struct datamap_t __near * DataMapInit<class CGameGibManager>(class CGameGibManager __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CGameGibManager>()
{
  if ( (_S3_106 & 1) == 0 )
  {
    _S3_106 |= 1u;
    nameHolder_362.m_pszBase = "CGameGibManager";
    nameHolder_362.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_362.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_362.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_362.m_Names.m_Size = 0;
    nameHolder_362.m_Names.m_pElements = nullptr;
    nameHolder_362.m_nLenBase = 15;
    atexit(func: DataMapInit_CGameGibManager__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CGameGibManager::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CGameGibManager::m_DataMap.dataNumFields = 4;
  CGameGibManager::m_DataMap.dataDesc = &dataDesc_345[1];
  return &CGameGibManager::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101F1DD0
// Name: struct datamap_t __near * DataMapInit<class CRagdollManager>(class CRagdollManager __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CRagdollManager>()
{
  if ( (_S3_107 & 1) == 0 )
  {
    _S3_107 |= 1u;
    nameHolder_363.m_pszBase = "CRagdollManager";
    nameHolder_363.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_363.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_363.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_363.m_Names.m_Size = 0;
    nameHolder_363.m_Names.m_pElements = nullptr;
    nameHolder_363.m_nLenBase = 15;
    atexit(func: DataMapInit_CRagdollManager__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CRagdollManager::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CRagdollManager::m_DataMap.dataNumFields = 4;
  CRagdollManager::m_DataMap.dataDesc = &dataDesc_346[1];
  return &CRagdollManager::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101F76F0
// Name: struct datamap_t __near * DataMapInit<class CRopeKeyframe>(class CRopeKeyframe __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CRopeKeyframe>()
{
  if ( (_S3_108 & 1) == 0 )
  {
    _S3_108 |= 1u;
    nameHolder_365.m_pszBase = "CRopeKeyframe";
    nameHolder_365.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_365.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_365.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_365.m_Names.m_Size = 0;
    nameHolder_365.m_Names.m_pElements = nullptr;
    nameHolder_365.m_nLenBase = 13;
    atexit(func: DataMapInit_CRopeKeyframe__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CRopeKeyframe::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CRopeKeyframe::m_DataMap.dataNumFields = 23;
  CRopeKeyframe::m_DataMap.dataDesc = &dataDesc_348[1];
  return &CRopeKeyframe::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10209C70
// Name: void ScriptDeduceFunctionSignature<class CSceneEntity __near *,class CSceneEntity,bool,char const __near *,char const __near *>(struct ScriptFuncDescriptor_t __near *,class CSceneEntity __near *,bool (CSceneEntity::*)(char const __near *,char const __near *))
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ScriptDeduceFunctionSignature<CSceneEntity *,CSceneEntity,bool,char const *,char const *>(
        ScriptFuncDescriptor_t *pDesc)
{
  CUtlVector<int,CUtlMemory<int,int> > *p_m_Parameters; // esi
  IMemAlloc_vtbl *v2; // edx
  int v3; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v7; // eax
  int *v8; // eax
  int v9; // edi
  int v10; // eax
  int *v11; // ecx
  int v12; // eax
  int *v13; // eax

  pDesc->m_ReturnType = 6;
  pDesc->m_Parameters.m_Memory.m_nGrowSize = 1;
  p_m_Parameters = &pDesc->m_Parameters;
  if ( pDesc->m_Parameters.m_Memory.m_nAllocationCount < 2 && pDesc->m_Parameters.m_Memory.m_nGrowSize >= 0 )
  {
    pDesc->m_Parameters.m_Memory.m_nAllocationCount = 2;
    v2 = _g_pMemAlloc->__vftable;
    if ( p_m_Parameters->m_Memory.m_pMemory != nullptr )
      v3 = ((int (__stdcall *)(int *, int))v2->Realloc_2)(a1: p_m_Parameters->m_Memory.m_pMemory, a2: 8);
    else
      v3 = ((int (__stdcall *)(int))v2->Alloc_2)(a1: 8);
    p_m_Parameters->m_Memory.m_pMemory = (int *)v3;
  }
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  m_Size = pDesc->m_Parameters.m_Size;
  m_nAllocationCount = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters,
      num: m_Size - m_nAllocationCount + 1);
  ++pDesc->m_Parameters.m_Size;
  m_pMemory = p_m_Parameters->m_Memory.m_pMemory;
  v7 = pDesc->m_Parameters.m_Size - m_Size - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
  v8 = &p_m_Parameters->m_Memory.m_pMemory[m_Size];
  if ( v8 != nullptr )
    *v8 = 32;
  v9 = pDesc->m_Parameters.m_Size;
  v10 = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( v9 + 1 > v10 )
    CUtlMemory<CNavLadder *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters, num: v9 - v10 + 1);
  ++pDesc->m_Parameters.m_Size;
  v11 = p_m_Parameters->m_Memory.m_pMemory;
  v12 = pDesc->m_Parameters.m_Size - v9 - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v12 > 0 )
    _V_memmove(dest: &v11[v9 + 1], src: &v11[v9], count: 4 * v12);
  v13 = &p_m_Parameters->m_Memory.m_pMemory[v9];
  if ( v13 != nullptr )
    *v13 = 32;
}

//------------------------------------------------------------------------------
// Address: 0x10209D70
// Name: class CInstancedSceneEntity __near * _CreateEntityTemplate<class CInstancedSceneEntity>(class CInstancedSceneEntity __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CInstancedSceneEntity *__cdecl _CreateEntityTemplate<CInstancedSceneEntity>(
        CInstancedSceneEntity *newEnt,
        const char *className)
{
  CSceneEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CSceneEntity *)CBaseEntity::operator new(stAllocateBlock: 0x6BCu);
  v3 = &v2->CPointEntity::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
  if ( v2 != nullptr )
  {
    CSceneEntity::CSceneEntity(this: v2);
    *v3 = &CInstancedSceneEntity::`vftable'{for `CPointEntity'};
    v3[213] = &CInstancedSceneEntity::`vftable'{for `IChoreoEventCallback'};
    v3[394] = -1;
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CInstancedSceneEntity *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10209E40
// Name: struct datamap_t __near * DataMapInit<class CSceneEntity>(class CSceneEntity __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CSceneEntity>()
{
  if ( (_S5_28 & 1) == 0 )
  {
    _S5_28 |= 1u;
    nameHolder_371.m_pszBase = "CSceneEntity";
    nameHolder_371.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_371.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_371.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_371.m_Names.m_Size = 0;
    nameHolder_371.m_Names.m_pElements = nullptr;
    nameHolder_371.m_nLenBase = 12;
    atexit(func: DataMapInit_CSceneEntity__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CSceneEntity::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S5_28 & 2) == 0 )
  {
    _S5_28 |= 2u;
    if ( (`CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CBaseFlex>,CUtlMemory<CHandle<CBaseFlex>,int>>>'::`2'::`local static guard'
        & 1) == 0 )
    {
      `CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CBaseFlex>,CUtlMemory<CHandle<CBaseFlex>,int>>>'::`2'::`local static guard' |= 1u;
      `CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CBaseFlex>,CUtlMemory<CHandle<CBaseFlex>,int>>>'::`2'::ops = (int)&CUtlVectorDataOps<CUtlVector<CHandle<CBaseFlex>,CUtlMemory<CHandle<CBaseFlex>,int>>,13>::`vftable';
    }
    dataDesc_354[39].fieldSize = 1;
    dataDesc_354[38].pSaveRestoreOps = (ISaveRestoreOps *)&`CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CBaseFlex>,CUtlMemory<CHandle<CBaseFlex>,int>>>'::`2'::ops;
    dataDesc_354[38].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_354[38].td = 0;
    *(_QWORD *)&dataDesc_354[38].override_field = 0;
    *(_QWORD *)&dataDesc_354[38].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_354[38].flatOffset[1] = 0;
    dataDesc_354[39].fieldType = FIELD_CUSTOM;
    dataDesc_354[39].fieldName = "m_hRemoveActorList";
    dataDesc_354[39].fieldOffset = 1000;
    dataDesc_354[39].flags = 2;
    dataDesc_354[39].externalName = nullptr;
    if ( (`CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int>>>'::`2'::`local static guard'
        & 1) == 0 )
    {
      `CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int>>>'::`2'::`local static guard' |= 1u;
      `CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int>>>'::`2'::ops = (int)&CUtlVectorDataOps<CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int>>,13>::`vftable';
    }
    dataDesc_354[40].fieldSize = 1;
    dataDesc_354[40].flags = 2;
    dataDesc_354[41].fieldSize = 1;
    dataDesc_354[41].flags = 2;
    *(_QWORD *)&dataDesc_354[39].td = 0;
    *(_QWORD *)&dataDesc_354[39].override_field = 0;
    *(_QWORD *)&dataDesc_354[39].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_354[39].flatOffset[1] = 0;
    dataDesc_354[42].fieldSize = 1;
    *(_QWORD *)dataDesc_354[40].flatOffset = 0;
    dataDesc_354[42].flags = 2;
    *(_QWORD *)dataDesc_354[41].flatOffset = 0;
    dataDesc_354[43].fieldSize = 1;
    *(_QWORD *)dataDesc_354[42].flatOffset = 0;
    dataDesc_354[39].pSaveRestoreOps = (ISaveRestoreOps *)&`CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int>>>'::`2'::ops;
    dataDesc_354[39].inputFunc = nullptr;
    dataDesc_354[40].fieldType = FIELD_INTEGER;
    dataDesc_354[40].fieldName = "m_nInterruptCount";
    dataDesc_354[40].fieldOffset = 1492;
    dataDesc_354[40].externalName = nullptr;
    dataDesc_354[40].pSaveRestoreOps = nullptr;
    dataDesc_354[40].inputFunc = nullptr;
    dataDesc_354[40].td = nullptr;
    dataDesc_354[40].fieldSizeInBytes = 4;
    dataDesc_354[40].override_field = nullptr;
    dataDesc_354[40].override_count = 0;
    dataDesc_354[40].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_354[40].flatGroup = 0;
    dataDesc_354[41].fieldType = FIELD_BOOLEAN;
    dataDesc_354[41].fieldName = "m_bInterrupted";
    dataDesc_354[41].fieldOffset = 1496;
    dataDesc_354[41].externalName = nullptr;
    dataDesc_354[41].pSaveRestoreOps = nullptr;
    dataDesc_354[41].inputFunc = nullptr;
    dataDesc_354[41].td = nullptr;
    dataDesc_354[41].fieldSizeInBytes = 1;
    dataDesc_354[41].override_field = nullptr;
    dataDesc_354[41].override_count = 0;
    dataDesc_354[41].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_354[41].flatGroup = 0;
    dataDesc_354[42].fieldType = FIELD_EHANDLE;
    dataDesc_354[42].fieldName = "m_hInterruptScene";
    dataDesc_354[42].fieldOffset = 1500;
    dataDesc_354[42].externalName = nullptr;
    dataDesc_354[42].pSaveRestoreOps = nullptr;
    dataDesc_354[42].inputFunc = nullptr;
    dataDesc_354[42].td = nullptr;
    dataDesc_354[42].fieldSizeInBytes = 4;
    dataDesc_354[42].override_field = nullptr;
    dataDesc_354[42].override_count = 0;
    dataDesc_354[42].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_354[42].flatGroup = 0;
    dataDesc_354[43].fieldType = FIELD_BOOLEAN;
    dataDesc_354[43].fieldName = "m_bCompletedEarly";
    dataDesc_354[43].fieldOffset = 1504;
    dataDesc_354[43].flags = 2;
    dataDesc_354[43].externalName = nullptr;
    dataDesc_354[43].pSaveRestoreOps = nullptr;
    dataDesc_354[43].inputFunc = nullptr;
    dataDesc_354[43].td = nullptr;
    dataDesc_354[43].fieldSizeInBytes = 1;
    dataDesc_354[43].override_field = nullptr;
    dataDesc_354[43].override_count = 0;
    dataDesc_354[43].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_354[43].flatOffset = 0;
    dataDesc_354[44].fieldSize = 1;
    dataDesc_354[44].flags = 2;
    dataDesc_354[45].fieldSize = 1;
    dataDesc_354[45].flags = 2;
    dataDesc_354[46].fieldSize = 1;
    dataDesc_354[46].flags = 2;
    dataDesc_354[47].fieldSize = 1;
    *(_QWORD *)dataDesc_354[44].flatOffset = 0;
    dataDesc_354[47].flags = 2;
    *(_QWORD *)dataDesc_354[45].flatOffset = 0;
    dataDesc_354[48].fieldSize = 1;
    *(_QWORD *)dataDesc_354[46].flatOffset = 0;
    *(_DWORD *)&dataDesc_354[43].flatGroup = 0;
    dataDesc_354[44].fieldType = FIELD_BOOLEAN;
    dataDesc_354[44].fieldName = "m_bInterruptSceneFinished";
    dataDesc_354[44].fieldOffset = 1505;
    dataDesc_354[44].externalName = nullptr;
    dataDesc_354[44].pSaveRestoreOps = nullptr;
    dataDesc_354[44].inputFunc = nullptr;
    dataDesc_354[44].td = nullptr;
    dataDesc_354[44].fieldSizeInBytes = 1;
    dataDesc_354[44].override_field = nullptr;
    dataDesc_354[44].override_count = 0;
    dataDesc_354[44].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_354[44].flatGroup = 0;
    dataDesc_354[45].fieldType = FIELD_BOOLEAN;
    dataDesc_354[45].fieldName = "m_bGenerated";
    dataDesc_354[45].fieldOffset = 1549;
    dataDesc_354[45].externalName = nullptr;
    dataDesc_354[45].pSaveRestoreOps = nullptr;
    dataDesc_354[45].inputFunc = nullptr;
    dataDesc_354[45].td = nullptr;
    dataDesc_354[45].fieldSizeInBytes = 1;
    dataDesc_354[45].override_field = nullptr;
    dataDesc_354[45].override_count = 0;
    dataDesc_354[45].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_354[45].flatGroup = 0;
    dataDesc_354[46].fieldType = FIELD_STRING;
    dataDesc_354[46].fieldName = "m_iszSoundName";
    dataDesc_354[46].fieldOffset = 1552;
    dataDesc_354[46].externalName = nullptr;
    dataDesc_354[46].pSaveRestoreOps = nullptr;
    dataDesc_354[46].inputFunc = nullptr;
    dataDesc_354[46].td = nullptr;
    dataDesc_354[46].fieldSizeInBytes = 4;
    dataDesc_354[46].override_field = nullptr;
    dataDesc_354[46].override_count = 0;
    dataDesc_354[46].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_354[46].flatGroup = 0;
    dataDesc_354[47].fieldType = FIELD_EHANDLE;
    dataDesc_354[47].fieldName = "m_hActor";
    dataDesc_354[47].fieldOffset = 1556;
    dataDesc_354[47].externalName = nullptr;
    dataDesc_354[47].pSaveRestoreOps = nullptr;
    dataDesc_354[47].inputFunc = nullptr;
    dataDesc_354[47].td = nullptr;
    dataDesc_354[47].fieldSizeInBytes = 4;
    dataDesc_354[47].override_field = nullptr;
    dataDesc_354[47].override_count = 0;
    dataDesc_354[47].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_354[47].flatOffset = 0;
    *(_DWORD *)&dataDesc_354[47].flatGroup = 0;
    dataDesc_354[48].fieldType = FIELD_EHANDLE;
    dataDesc_354[48].fieldName = "m_hActivator";
    dataDesc_354[48].fieldOffset = 1560;
    dataDesc_354[48].flags = 2;
    dataDesc_354[48].externalName = nullptr;
    dataDesc_354[49].fieldSize = 1;
    dataDesc_354[48].pSaveRestoreOps = nullptr;
    dataDesc_354[48].inputFunc = nullptr;
    dataDesc_354[48].td = nullptr;
    dataDesc_354[48].fieldSizeInBytes = 4;
    dataDesc_354[48].override_field = nullptr;
    dataDesc_354[48].override_count = 0;
    dataDesc_354[48].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_354[48].flatOffset = 0;
    *(_DWORD *)&dataDesc_354[48].flatGroup = 0;
    dataDesc_354[49].fieldType = FIELD_CUSTOM;
    dataDesc_354[49].fieldName = "m_hNotifySceneCompletion";
    dataDesc_354[49].fieldOffset = 1508;
    dataDesc_354[49].flags = 2;
    dataDesc_354[49].externalName = nullptr;
    if ( (`CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CSceneEntity>,CUtlMemory<CHandle<CSceneEntity>,int>>>'::`2'::`local static guard'
        & 1) == 0 )
    {
      `CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CSceneEntity>,CUtlMemory<CHandle<CSceneEntity>,int>>>'::`2'::`local static guard' |= 1u;
      `CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CSceneEntity>,CUtlMemory<CHandle<CSceneEntity>,int>>>'::`2'::ops = (int)&CUtlVectorDataOps<CUtlVector<CHandle<CSceneEntity>,CUtlMemory<CHandle<CSceneEntity>,int>>,13>::`vftable';
    }
    dataDesc_354[50].fieldSize = 1;
    dataDesc_354[49].pSaveRestoreOps = (ISaveRestoreOps *)&`CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CSceneEntity>,CUtlMemory<CHandle<CSceneEntity>,int>>>'::`2'::ops;
    dataDesc_354[49].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_354[49].td = 0;
    *(_QWORD *)&dataDesc_354[49].override_field = 0;
    *(_QWORD *)&dataDesc_354[49].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_354[49].flatOffset[1] = 0;
    dataDesc_354[50].fieldType = FIELD_CUSTOM;
    dataDesc_354[50].fieldName = "m_hListManagers";
    dataDesc_354[50].fieldOffset = 1528;
    dataDesc_354[50].flags = 2;
    dataDesc_354[50].externalName = nullptr;
    if ( (`CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CSceneListManager>,CUtlMemory<CHandle<CSceneListManager>,int>>>'::`2'::`local static guard'
        & 1) == 0 )
    {
      `CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CSceneListManager>,CUtlMemory<CHandle<CSceneListManager>,int>>>'::`2'::`local static guard' |= 1u;
      `CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CSceneListManager>,CUtlMemory<CHandle<CSceneListManager>,int>>>'::`2'::ops = (int)&CUtlVectorDataOps<CUtlVector<CHandle<CSceneListManager>,CUtlMemory<CHandle<CSceneListManager>,int>>,13>::`vftable';
    }
    dataDesc_354[51].fieldSize = 1;
    dataDesc_354[51].flags = 2;
    dataDesc_354[52].fieldSize = 1;
    dataDesc_354[52].flags = 8;
    dataDesc_354[53].fieldSize = 1;
    dataDesc_354[53].flags = 8;
    *(_QWORD *)&dataDesc_354[50].td = 0;
    *(_QWORD *)&dataDesc_354[50].override_field = 0;
    *(_QWORD *)&dataDesc_354[50].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_354[50].flatOffset[1] = 0;
    dataDesc_354[54].fieldSize = 1;
    *(_QWORD *)dataDesc_354[51].flatOffset = 0;
    *(_QWORD *)&dataDesc_354[52].td = 0;
    *(_QWORD *)&dataDesc_354[52].override_field = 0;
    *(_QWORD *)&dataDesc_354[52].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_354[52].flatOffset[1] = 0;
    dataDesc_354[54].flags = 8;
    *(_QWORD *)&dataDesc_354[53].td = 0;
    *(_QWORD *)&dataDesc_354[53].override_field = 0;
    *(_QWORD *)&dataDesc_354[53].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_354[53].flatOffset[1] = 0;
    dataDesc_354[55].fieldSize = 1;
    *(_QWORD *)&dataDesc_354[54].td = 0;
    *(_QWORD *)&dataDesc_354[54].override_field = 0;
    *(_QWORD *)&dataDesc_354[54].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_354[54].flatOffset[1] = 0;
    dataDesc_354[50].pSaveRestoreOps = (ISaveRestoreOps *)&`CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CSceneListManager>,CUtlMemory<CHandle<CSceneListManager>,int>>>'::`2'::ops;
    dataDesc_354[50].inputFunc = nullptr;
    dataDesc_354[51].fieldType = FIELD_BOOLEAN;
    dataDesc_354[51].fieldName = "m_bMultiplayer";
    dataDesc_354[51].fieldOffset = 938;
    dataDesc_354[51].externalName = nullptr;
    dataDesc_354[51].pSaveRestoreOps = nullptr;
    dataDesc_354[51].inputFunc = nullptr;
    dataDesc_354[51].td = nullptr;
    dataDesc_354[51].fieldSizeInBytes = 1;
    dataDesc_354[51].override_field = nullptr;
    dataDesc_354[51].override_count = 0;
    dataDesc_354[51].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_354[51].flatGroup = 0;
    dataDesc_354[52].fieldType = FIELD_VOID;
    dataDesc_354[52].fieldName = "InputStartPlayback";
    dataDesc_354[52].fieldOffset = 0;
    dataDesc_354[52].externalName = "Start";
    dataDesc_354[52].pSaveRestoreOps = nullptr;
    dataDesc_354[52].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CSceneEntity::InputStartPlayback;
    dataDesc_354[53].fieldType = FIELD_VOID;
    dataDesc_354[53].fieldName = "InputPausePlayback";
    dataDesc_354[53].fieldOffset = 0;
    dataDesc_354[53].externalName = "Pause";
    dataDesc_354[53].pSaveRestoreOps = nullptr;
    dataDesc_354[53].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CSceneEntity::InputPausePlayback;
    dataDesc_354[54].fieldType = FIELD_VOID;
    dataDesc_354[54].fieldName = "InputResumePlayback";
    dataDesc_354[54].fieldOffset = 0;
    dataDesc_354[54].externalName = "Resume";
    dataDesc_354[54].pSaveRestoreOps = nullptr;
    dataDesc_354[54].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CSceneEntity::InputResumePlayback;
    dataDesc_354[55].fieldType = FIELD_VOID;
    dataDesc_354[55].fieldName = "InputCancelPlayback";
    dataDesc_354[55].fieldOffset = 0;
    dataDesc_354[55].flags = 8;
    dataDesc_354[55].externalName = "Cancel";
    dataDesc_354[55].pSaveRestoreOps = nullptr;
    dataDesc_354[55].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CSceneEntity::InputCancelPlayback;
    dataDesc_354[56].fieldSize = 1;
    dataDesc_354[56].flags = 8;
    dataDesc_354[57].fieldSize = 1;
    dataDesc_354[57].flags = 8;
    dataDesc_354[58].fieldSize = 1;
    dataDesc_354[58].flags = 8;
    *(_QWORD *)&dataDesc_354[55].td = 0;
    *(_QWORD *)&dataDesc_354[55].override_field = 0;
    *(_QWORD *)&dataDesc_354[55].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_354[55].flatOffset[1] = 0;
    *(_QWORD *)&dataDesc_354[56].td = 0;
    *(_QWORD *)&dataDesc_354[56].override_field = 0;
    *(_QWORD *)&dataDesc_354[56].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_354[56].flatOffset[1] = 0;
    dataDesc_354[59].fieldSize = 1;
    *(_QWORD *)&dataDesc_354[57].td = 0;
    *(_QWORD *)&dataDesc_354[57].override_field = 0;
    *(_QWORD *)&dataDesc_354[57].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_354[57].flatOffset[1] = 0;
    dataDesc_354[59].flags = 8;
    *(_QWORD *)&dataDesc_354[58].td = 0;
    *(_QWORD *)&dataDesc_354[58].override_field = 0;
    *(_QWORD *)&dataDesc_354[58].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_354[58].flatOffset[1] = 0;
    dataDesc_354[60].fieldSize = 1;
    *(_QWORD *)&dataDesc_354[59].td = 0;
    *(_QWORD *)&dataDesc_354[59].override_field = 0;
    *(_QWORD *)&dataDesc_354[59].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_354[59].flatOffset[1] = 0;
    dataDesc_354[56].fieldType = FIELD_VOID;
    dataDesc_354[56].fieldName = "InputCancelAtNextInterrupt";
    dataDesc_354[56].fieldOffset = 0;
    dataDesc_354[56].externalName = "CancelAtNextInterrupt";
    dataDesc_354[56].pSaveRestoreOps = nullptr;
    dataDesc_354[56].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CSceneEntity::InputCancelAtNextInterrupt;
    dataDesc_354[57].fieldType = FIELD_FLOAT;
    dataDesc_354[57].fieldName = "InputPitchShiftPlayback";
    dataDesc_354[57].fieldOffset = 0;
    dataDesc_354[57].externalName = "PitchShift";
    dataDesc_354[57].pSaveRestoreOps = nullptr;
    dataDesc_354[57].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CSceneEntity::InputPitchShiftPlayback;
    dataDesc_354[58].fieldType = FIELD_STRING;
    dataDesc_354[58].fieldName = "InputInterjectResponse";
    dataDesc_354[58].fieldOffset = 0;
    dataDesc_354[58].externalName = "InterjectResponse";
    dataDesc_354[58].pSaveRestoreOps = nullptr;
    dataDesc_354[58].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CSceneEntity::InputInterjectResponse;
    dataDesc_354[59].fieldType = FIELD_VOID;
    dataDesc_354[59].fieldName = "InputStopWaitingForActor";
    dataDesc_354[59].fieldOffset = 0;
    dataDesc_354[59].externalName = "StopWaitingForActor";
    dataDesc_354[59].pSaveRestoreOps = nullptr;
    dataDesc_354[59].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CSceneEntity::InputStopWaitingForActor;
    dataDesc_354[60].fieldType = FIELD_INTEGER;
    dataDesc_354[60].fieldName = "InputTriggerEvent";
    dataDesc_354[60].fieldOffset = 0;
    dataDesc_354[60].flags = 8;
    dataDesc_354[60].externalName = "Trigger";
    dataDesc_354[60].pSaveRestoreOps = nullptr;
    dataDesc_354[60].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CSceneEntity::InputTriggerEvent;
    *(_QWORD *)&dataDesc_354[60].td = 0;
    *(_QWORD *)&dataDesc_354[60].override_field = 0;
    *(_QWORD *)&dataDesc_354[60].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_354[60].flatOffset[1] = 0;
    dataDesc_354[61].fieldType = FIELD_INTEGER;
    dataDesc_354[61].fieldName = "m_iPlayerDeathBehavior";
    dataDesc_354[61].fieldSize = 1;
    dataDesc_354[61].flags = 6;
    dataDesc_354[62].fieldSize = 1;
    dataDesc_354[62].flags = 8;
    dataDesc_354[63].fieldSize = 1;
    dataDesc_354[63].flags = 8;
    *(_QWORD *)dataDesc_354[61].flatOffset = 0;
    dataDesc_354[64].fieldSize = 1;
    *(_QWORD *)&dataDesc_354[62].td = 0;
    *(_QWORD *)&dataDesc_354[62].override_field = 0;
    *(_QWORD *)&dataDesc_354[62].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_354[62].flatOffset[1] = 0;
    dataDesc_354[64].flags = 8;
    *(_QWORD *)&dataDesc_354[63].td = 0;
    *(_QWORD *)&dataDesc_354[63].override_field = 0;
    *(_QWORD *)&dataDesc_354[63].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_354[63].flatOffset[1] = 0;
    dataDesc_354[63].fieldType = FIELD_STRING;
    dataDesc_354[64].fieldType = FIELD_STRING;
    dataDesc_354[65].fieldType = FIELD_STRING;
    dataDesc_354[65].fieldSize = 1;
    dataDesc_354[66].fieldType = FIELD_STRING;
    *(_QWORD *)&dataDesc_354[64].td = 0;
    *(_QWORD *)&dataDesc_354[64].override_field = 0;
    *(_QWORD *)&dataDesc_354[64].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_354[64].flatOffset[1] = 0;
    dataDesc_354[61].fieldOffset = 1568;
    dataDesc_354[61].externalName = "onplayerdeath";
    dataDesc_354[61].pSaveRestoreOps = nullptr;
    dataDesc_354[61].inputFunc = nullptr;
    dataDesc_354[61].td = nullptr;
    dataDesc_354[61].fieldSizeInBytes = 4;
    dataDesc_354[61].override_field = nullptr;
    dataDesc_354[61].override_count = 0;
    dataDesc_354[61].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_354[61].flatGroup = 0;
    dataDesc_354[62].fieldType = FIELD_VOID;
    dataDesc_354[62].fieldName = "InputScriptPlayerDeath";
    dataDesc_354[62].fieldOffset = 0;
    dataDesc_354[62].externalName = "ScriptPlayerDeath";
    dataDesc_354[62].pSaveRestoreOps = nullptr;
    dataDesc_354[62].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CSceneEntity::InputScriptPlayerDeath;
    dataDesc_354[63].fieldName = "InputSetTarget1";
    dataDesc_354[63].fieldOffset = 0;
    dataDesc_354[63].externalName = "SetTarget1";
    dataDesc_354[63].pSaveRestoreOps = nullptr;
    dataDesc_354[63].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CSceneEntity::InputSetTarget1;
    dataDesc_354[64].fieldName = "InputSetTarget2";
    dataDesc_354[64].fieldOffset = 0;
    dataDesc_354[64].externalName = "SetTarget2";
    dataDesc_354[64].pSaveRestoreOps = nullptr;
    dataDesc_354[64].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CSceneEntity::InputSetTarget2;
    dataDesc_354[65].fieldName = "InputSetTarget3";
    dataDesc_354[65].fieldOffset = 0;
    dataDesc_354[65].flags = 8;
    dataDesc_354[65].externalName = "SetTarget3";
    dataDesc_354[65].pSaveRestoreOps = nullptr;
    dataDesc_354[65].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CSceneEntity::InputSetTarget3;
    *(_QWORD *)&dataDesc_354[65].td = 0;
    *(_QWORD *)&dataDesc_354[65].override_field = 0;
    *(_QWORD *)&dataDesc_354[65].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_354[65].flatOffset[1] = 0;
    dataDesc_354[66].fieldName = "InputSetTarget4";
    dataDesc_354[66].fieldOffset = 0;
    dataDesc_354[66].fieldSize = 1;
    dataDesc_354[66].flags = 8;
    dataDesc_354[67].flags = 22;
    dataDesc_354[68].fieldSize = 1;
    dataDesc_354[68].flags = 22;
    dataDesc_354[69].fieldSize = 1;
    dataDesc_354[69].flags = 22;
    *(_QWORD *)&dataDesc_354[66].td = 0;
    *(_QWORD *)&dataDesc_354[66].override_field = 0;
    *(_QWORD *)&dataDesc_354[66].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_354[66].flatOffset[1] = 0;
    *(_QWORD *)&dataDesc_354[67].inputFunc = 0;
    *(_QWORD *)&dataDesc_354[67].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_354[67].override_count = 0;
    *(_QWORD *)dataDesc_354[67].flatOffset = 0;
    dataDesc_354[70].fieldSize = 1;
    *(_QWORD *)&dataDesc_354[68].inputFunc = 0;
    *(_QWORD *)&dataDesc_354[68].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_354[68].override_count = 0;
    *(_QWORD *)dataDesc_354[68].flatOffset = 0;
    dataDesc_354[70].flags = 22;
    *(_QWORD *)&dataDesc_354[69].inputFunc = 0;
    *(_QWORD *)&dataDesc_354[69].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_354[69].override_count = 0;
    *(_QWORD *)dataDesc_354[69].flatOffset = 0;
    dataDesc_354[67].fieldSize = 1;
    dataDesc_354[71].fieldSize = 1;
    *(_QWORD *)&dataDesc_354[70].inputFunc = 0;
    *(_QWORD *)&dataDesc_354[70].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_354[70].override_count = 0;
    *(_QWORD *)dataDesc_354[70].flatOffset = 0;
    dataDesc_354[66].externalName = "SetTarget4";
    dataDesc_354[66].pSaveRestoreOps = nullptr;
    dataDesc_354[66].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CSceneEntity::InputSetTarget4;
    dataDesc_354[67].fieldType = FIELD_CUSTOM;
    dataDesc_354[67].fieldName = "m_OnStart";
    dataDesc_354[67].fieldOffset = 1028;
    dataDesc_354[67].externalName = "OnStart";
    dataDesc_354[67].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_354[67].flatGroup = 0;
    dataDesc_354[68].fieldType = FIELD_CUSTOM;
    dataDesc_354[68].fieldName = "m_OnCompletion";
    dataDesc_354[68].fieldOffset = 1052;
    dataDesc_354[68].externalName = "OnCompletion";
    dataDesc_354[68].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_354[68].flatGroup = 0;
    dataDesc_354[69].fieldType = FIELD_CUSTOM;
    dataDesc_354[69].fieldName = "m_OnCanceled";
    dataDesc_354[69].fieldOffset = 1076;
    dataDesc_354[69].externalName = "OnCanceled";
    dataDesc_354[69].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_354[69].flatGroup = 0;
    dataDesc_354[70].fieldType = FIELD_CUSTOM;
    dataDesc_354[70].fieldName = "m_OnTrigger1";
    dataDesc_354[70].fieldOffset = 1100;
    dataDesc_354[70].externalName = "OnTrigger1";
    dataDesc_354[70].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_354[70].flatGroup = 0;
    dataDesc_354[71].fieldType = FIELD_CUSTOM;
    dataDesc_354[71].fieldName = "m_OnTrigger2";
    dataDesc_354[71].fieldOffset = 1124;
    dataDesc_354[71].flags = 22;
    dataDesc_354[71].externalName = "OnTrigger2";
    dataDesc_354[71].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_354[71].inputFunc = 0;
    *(_QWORD *)&dataDesc_354[71].fieldSizeInBytes = 0;
    dataDesc_354[72].fieldSize = 1;
    dataDesc_354[72].flags = 22;
    dataDesc_354[73].fieldSize = 1;
    dataDesc_354[73].flags = 22;
    dataDesc_354[74].fieldSize = 1;
    dataDesc_354[74].flags = 22;
    *(_QWORD *)&dataDesc_354[71].override_count = 0;
    *(_QWORD *)dataDesc_354[71].flatOffset = 0;
    *(_QWORD *)&dataDesc_354[72].inputFunc = 0;
    *(_QWORD *)&dataDesc_354[72].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_354[72].override_count = 0;
    *(_QWORD *)dataDesc_354[72].flatOffset = 0;
    dataDesc_354[75].fieldSize = 1;
    *(_QWORD *)&dataDesc_354[73].inputFunc = 0;
    *(_QWORD *)&dataDesc_354[73].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_354[73].override_count = 0;
    *(_QWORD *)dataDesc_354[73].flatOffset = 0;
    dataDesc_354[75].flags = 22;
    *(_QWORD *)&dataDesc_354[74].inputFunc = 0;
    *(_QWORD *)&dataDesc_354[74].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_354[74].override_count = 0;
    *(_QWORD *)dataDesc_354[74].flatOffset = 0;
    dataDesc_354[76].fieldSize = 1;
    *(_QWORD *)&dataDesc_354[75].inputFunc = 0;
    *(_QWORD *)&dataDesc_354[75].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_354[75].override_count = 0;
    *(_QWORD *)dataDesc_354[75].flatOffset = 0;
    *(_DWORD *)&dataDesc_354[71].flatGroup = 0;
    dataDesc_354[72].fieldType = FIELD_CUSTOM;
    dataDesc_354[72].fieldName = "m_OnTrigger3";
    dataDesc_354[72].fieldOffset = 1148;
    dataDesc_354[72].externalName = "OnTrigger3";
    dataDesc_354[72].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_354[72].flatGroup = 0;
    dataDesc_354[73].fieldType = FIELD_CUSTOM;
    dataDesc_354[73].fieldName = "m_OnTrigger4";
    dataDesc_354[73].fieldOffset = 1172;
    dataDesc_354[73].externalName = "OnTrigger4";
    dataDesc_354[73].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_354[73].flatGroup = 0;
    dataDesc_354[74].fieldType = FIELD_CUSTOM;
    dataDesc_354[74].fieldName = "m_OnTrigger5";
    dataDesc_354[74].fieldOffset = 1196;
    dataDesc_354[74].externalName = "OnTrigger5";
    dataDesc_354[74].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_354[74].flatGroup = 0;
    dataDesc_354[75].fieldType = FIELD_CUSTOM;
    dataDesc_354[75].fieldName = "m_OnTrigger6";
    dataDesc_354[75].fieldOffset = 1220;
    dataDesc_354[75].externalName = "OnTrigger6";
    dataDesc_354[75].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_354[75].flatGroup = 0;
    dataDesc_354[76].fieldType = FIELD_CUSTOM;
    dataDesc_354[76].fieldName = "m_OnTrigger7";
    dataDesc_354[76].fieldOffset = 1244;
    dataDesc_354[76].flags = 22;
    dataDesc_354[76].externalName = "OnTrigger7";
    dataDesc_354[76].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_354[76].inputFunc = 0;
    *(_QWORD *)&dataDesc_354[76].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_354[76].override_count = 0;
    *(_QWORD *)dataDesc_354[76].flatOffset = 0;
    *(_DWORD *)&dataDesc_354[76].flatGroup = 0;
    dataDesc_354[77].fieldType = FIELD_CUSTOM;
    dataDesc_354[77].fieldName = "m_OnTrigger8";
    dataDesc_354[77].fieldOffset = 1268;
    dataDesc_354[77].fieldSize = 1;
    dataDesc_354[77].flags = 22;
    dataDesc_354[78].fieldSize = 1;
    dataDesc_354[78].flags = 22;
    dataDesc_354[79].fieldSize = 1;
    dataDesc_354[79].flags = 22;
    dataDesc_354[80].fieldSize = 1;
    dataDesc_354[80].flags = 22;
    *(_QWORD *)&dataDesc_354[77].inputFunc = 0;
    *(_QWORD *)&dataDesc_354[77].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_354[77].override_count = 0;
    *(_QWORD *)dataDesc_354[77].flatOffset = 0;
    dataDesc_354[81].fieldSize = 1;
    *(_QWORD *)&dataDesc_354[78].inputFunc = 0;
    *(_QWORD *)&dataDesc_354[78].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_354[78].override_count = 0;
    *(_QWORD *)dataDesc_354[78].flatOffset = 0;
    dataDesc_354[81].flags = 22;
    *(_QWORD *)&dataDesc_354[79].inputFunc = 0;
    *(_QWORD *)&dataDesc_354[79].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_354[79].override_count = 0;
    *(_QWORD *)dataDesc_354[79].flatOffset = 0;
    dataDesc_354[82].fieldSize = 1;
    *(_QWORD *)&dataDesc_354[80].inputFunc = 0;
    *(_QWORD *)&dataDesc_354[80].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_354[80].override_count = 0;
    *(_QWORD *)dataDesc_354[80].flatOffset = 0;
    dataDesc_354[77].externalName = "OnTrigger8";
    dataDesc_354[77].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_354[77].flatGroup = 0;
    dataDesc_354[78].fieldType = FIELD_CUSTOM;
    dataDesc_354[78].fieldName = "m_OnTrigger9";
    dataDesc_354[78].fieldOffset = 1292;
    dataDesc_354[78].externalName = "OnTrigger9";
    dataDesc_354[78].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_354[78].flatGroup = 0;
    dataDesc_354[79].fieldType = FIELD_CUSTOM;
    dataDesc_354[79].fieldName = "m_OnTrigger10";
    dataDesc_354[79].fieldOffset = 1316;
    dataDesc_354[79].externalName = "OnTrigger10";
    dataDesc_354[79].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_354[79].flatGroup = 0;
    dataDesc_354[80].fieldType = FIELD_CUSTOM;
    dataDesc_354[80].fieldName = "m_OnTrigger11";
    dataDesc_354[80].fieldOffset = 1340;
    dataDesc_354[80].externalName = "OnTrigger11";
    dataDesc_354[80].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_354[80].flatGroup = 0;
    dataDesc_354[81].fieldType = FIELD_CUSTOM;
    dataDesc_354[81].fieldName = "m_OnTrigger12";
    dataDesc_354[81].fieldOffset = 1364;
    dataDesc_354[81].externalName = "OnTrigger12";
    dataDesc_354[81].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_354[81].inputFunc = 0;
    *(_QWORD *)&dataDesc_354[81].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_354[81].override_count = 0;
    *(_QWORD *)dataDesc_354[81].flatOffset = 0;
    *(_DWORD *)&dataDesc_354[81].flatGroup = 0;
    dataDesc_354[82].fieldType = FIELD_CUSTOM;
    dataDesc_354[82].fieldName = "m_OnTrigger13";
    dataDesc_354[82].fieldOffset = 1388;
    dataDesc_354[82].flags = 22;
    dataDesc_354[82].externalName = "OnTrigger13";
    dataDesc_354[82].pSaveRestoreOps = eventFuncs;
    dataDesc_354[83].fieldSize = 1;
    *(_QWORD *)&dataDesc_354[82].inputFunc = 0;
    *(_QWORD *)&dataDesc_354[82].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_354[82].override_count = 0;
    *(_QWORD *)dataDesc_354[82].flatOffset = 0;
    dataDesc_354[83].flags = 22;
    *(_QWORD *)&dataDesc_354[83].inputFunc = 0;
    *(_QWORD *)&dataDesc_354[83].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_354[83].override_count = 0;
    *(_QWORD *)dataDesc_354[83].flatOffset = 0;
    dataDesc_354[84].fieldSize = 1;
    *(_QWORD *)&dataDesc_354[84].inputFunc = 0;
    *(_QWORD *)&dataDesc_354[84].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_354[84].override_count = 0;
    *(_QWORD *)dataDesc_354[84].flatOffset = 0;
    *(_DWORD *)&dataDesc_354[82].flatGroup = 0;
    dataDesc_354[83].fieldType = FIELD_CUSTOM;
    dataDesc_354[83].fieldName = "m_OnTrigger14";
    dataDesc_354[83].fieldOffset = 1412;
    dataDesc_354[83].externalName = "OnTrigger14";
    dataDesc_354[83].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_354[83].flatGroup = 0;
    dataDesc_354[84].fieldType = FIELD_CUSTOM;
    dataDesc_354[84].fieldName = "m_OnTrigger15";
    dataDesc_354[84].fieldOffset = 1436;
    dataDesc_354[84].flags = 22;
    dataDesc_354[84].externalName = "OnTrigger15";
    dataDesc_354[84].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_354[84].flatGroup = 0;
    dataDesc_354[85].fieldType = FIELD_CUSTOM;
    dataDesc_354[85].fieldName = "m_OnTrigger16";
    dataDesc_354[85].fieldOffset = 1460;
    *(_DWORD *)&dataDesc_354[85].fieldSize = 1441793;
    dataDesc_354[85].externalName = "OnTrigger16";
    dataDesc_354[85].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_354[85].inputFunc = 0;
    *(_QWORD *)&dataDesc_354[85].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_354[85].override_count = 0;
    *(_QWORD *)dataDesc_354[85].flatOffset = 0;
    *(_DWORD *)&dataDesc_354[85].flatGroup = 0;
  }
  CSceneEntity::m_DataMap.dataNumFields = 85;
  CSceneEntity::m_DataMap.dataDesc = &dataDesc_354[1];
  return &CSceneEntity::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x102111F0
// Name: struct datamap_t __near * DataMapInit<class CScriptedTarget>(class CScriptedTarget __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CScriptedTarget>()
{
  if ( (_S2_197 & 1) == 0 )
  {
    _S2_197 |= 1u;
    nameHolder_375.m_pszBase = "CScriptedTarget";
    nameHolder_375.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_375.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_375.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_375.m_Names.m_Size = 0;
    nameHolder_375.m_Names.m_pElements = nullptr;
    nameHolder_375.m_nLenBase = 15;
    atexit(func: DataMapInit_CScriptedTarget__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CScriptedTarget::m_DataMap.baseMap = &CAI_BaseNPC::m_DataMap;
  if ( (_S2_197 & 2) == 0 )
  {
    _S2_197 |= 2u;
    dataDesc_358[9].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_375,
                                  pszIdentifier: "ScriptThink");
    dataDesc_358[9].fieldSize = 1;
    *(_QWORD *)&dataDesc_358[9].td = 0;
    *(_QWORD *)&dataDesc_358[9].override_field = 0;
    *(_QWORD *)&dataDesc_358[9].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_358[9].flatOffset[1] = 0;
    dataDesc_358[10].fieldSize = 1;
    *(_QWORD *)&dataDesc_358[10].td = 0;
    *(_QWORD *)&dataDesc_358[10].override_field = 0;
    *(_QWORD *)&dataDesc_358[10].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_358[10].flatOffset[1] = 0;
    dataDesc_358[9].flags = 32;
    dataDesc_358[10].flags = 8;
    *(_QWORD *)&dataDesc_358[11].td = 0;
    *(_QWORD *)&dataDesc_358[11].override_field = 0;
    *(_QWORD *)&dataDesc_358[11].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_358[11].flatOffset[1] = 0;
    dataDesc_358[11].fieldSize = 1;
    dataDesc_358[11].flags = 8;
    dataDesc_358[12].fieldSize = 1;
    *(_QWORD *)&dataDesc_358[12].inputFunc = 0;
    *(_QWORD *)&dataDesc_358[12].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_358[12].override_count = 0;
    *(_QWORD *)dataDesc_358[12].flatOffset = 0;
    dataDesc_358[9].fieldOffset = 0;
    dataDesc_358[9].externalName = nullptr;
    dataDesc_358[9].pSaveRestoreOps = nullptr;
    dataDesc_358[9].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CScriptedTarget::ScriptThink;
    dataDesc_358[10].fieldType = FIELD_VOID;
    dataDesc_358[10].fieldName = "InputEnable";
    dataDesc_358[10].fieldOffset = 0;
    dataDesc_358[10].externalName = "Enable";
    dataDesc_358[10].pSaveRestoreOps = nullptr;
    dataDesc_358[10].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CScriptedTarget::InputEnable;
    dataDesc_358[11].fieldType = FIELD_VOID;
    dataDesc_358[11].fieldName = "InputDisable";
    dataDesc_358[11].fieldOffset = 0;
    dataDesc_358[11].externalName = "Disable";
    dataDesc_358[11].pSaveRestoreOps = nullptr;
    dataDesc_358[11].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CScriptedTarget::InputDisable;
    dataDesc_358[12].fieldType = FIELD_CUSTOM;
    dataDesc_358[12].fieldName = "m_AtTarget";
    dataDesc_358[12].fieldOffset = 3756;
    dataDesc_358[12].flags = 22;
    dataDesc_358[12].externalName = "AtTarget";
    dataDesc_358[12].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_358[12].flatGroup = 0;
    dataDesc_358[13].fieldType = FIELD_CUSTOM;
    dataDesc_358[13].fieldName = "m_LeaveTarget";
    dataDesc_358[13].fieldOffset = 3780;
    *(_DWORD *)&dataDesc_358[13].fieldSize = 1441793;
    dataDesc_358[13].externalName = "LeaveTarget";
    dataDesc_358[13].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_358[13].inputFunc = 0;
    *(_QWORD *)&dataDesc_358[13].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_358[13].override_count = 0;
    *(_QWORD *)dataDesc_358[13].flatOffset = 0;
    *(_DWORD *)&dataDesc_358[13].flatGroup = 0;
  }
  CScriptedTarget::m_DataMap.dataNumFields = 13;
  CScriptedTarget::m_DataMap.dataDesc = &dataDesc_358[1];
  return &CScriptedTarget::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10213E70
// Name: struct datamap_t __near * DataMapInit<class CSkyboxSwapper>(class CSkyboxSwapper __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CSkyboxSwapper>()
{
  if ( (_S2_201 & 1) == 0 )
  {
    _S2_201 |= 1u;
    nameHolder_384.m_pszBase = "CSkyboxSwapper";
    nameHolder_384.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_384.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_384.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_384.m_Names.m_Size = 0;
    nameHolder_384.m_Names.m_pElements = nullptr;
    nameHolder_384.m_nLenBase = 14;
    atexit(func: DataMapInit_CSkyboxSwapper__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CSkyboxSwapper::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CSkyboxSwapper::m_DataMap.dataNumFields = 2;
  CSkyboxSwapper::m_DataMap.dataDesc = &dataDesc_367[1];
  return &CSkyboxSwapper::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1021BE30
// Name: class CAISound __near * _CreateEntityTemplate<class CAISound>(class CAISound __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CAISound *__cdecl _CreateEntityTemplate<CAISound>(CAISound *newEnt, const char *className)
{
  CBaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x368u);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    *v3 = &CAISound::`vftable';
    v3[214] = 0;
    v3[215] = 0;
    v3[216] = 1050253722;
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CAISound *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021CF70
// Name: struct datamap_t __near * DataMapInit<class CSound>(class CSound __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CSound>()
{
  if ( (_S2_205 & 1) == 0 )
  {
    _S2_205 |= 1u;
    nameHolder_387.m_pszBase = "CSound";
    nameHolder_387.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_387.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_387.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_387.m_Names.m_Size = 0;
    nameHolder_387.m_Names.m_pElements = nullptr;
    nameHolder_387.m_nLenBase = 6;
    atexit(func: DataMapInit_CSound__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CSound::m_DataMap.baseMap = nullptr;
  CSound::m_DataMap.dataNumFields = 11;
  CSound::m_DataMap.dataDesc = &dataDesc_370[1];
  return &CSound::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1021D000
// Name: struct datamap_t __near * DataMapInit<class CSoundEnt>(class CSoundEnt __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CSoundEnt>()
{
  if ( (_S3_116 & 1) == 0 )
  {
    _S3_116 |= 1u;
    nameHolder_388.m_pszBase = "CSoundEnt";
    nameHolder_388.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_388.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_388.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_388.m_Names.m_Size = 0;
    nameHolder_388.m_Names.m_pElements = nullptr;
    nameHolder_388.m_nLenBase = 9;
    atexit(func: DataMapInit_CSoundEnt__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CSoundEnt::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CSoundEnt::m_DataMap.dataNumFields = 4;
  CSoundEnt::m_DataMap.dataDesc = &dataDesc_371[1];
  return &CSoundEnt::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1021D080
// Name: struct datamap_t __near * DataMapInit<class CAISound>(class CAISound __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CAISound>()
{
  if ( (_S4_54 & 1) == 0 )
  {
    _S4_54 |= 1u;
    nameHolder_389.m_pszBase = "CAISound";
    nameHolder_389.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_389.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_389.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_389.m_Names.m_Size = 0;
    nameHolder_389.m_Names.m_pElements = nullptr;
    nameHolder_389.m_nLenBase = 8;
    atexit(func: DataMapInit_CAISound__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CAISound::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CAISound::m_DataMap.dataNumFields = 7;
  CAISound::m_DataMap.dataDesc = &dataDesc_372[1];
  return &CAISound::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10220660
// Name: class CTriggerSoundscape __near * _CreateEntityTemplate<class CTriggerSoundscape>(class CTriggerSoundscape __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CTriggerSoundscape *__cdecl _CreateEntityTemplate<CTriggerSoundscape>(
        CTriggerSoundscape *newEnt,
        const char *className)
{
  CBaseTrigger *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseTrigger *)CBaseEntity::operator new(stAllocateBlock: 0x49Cu);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseTrigger::CBaseTrigger(this: v2);
    *v3 = &CTriggerSoundscape::`vftable';
    v3[288] = -1;
    v3[290] = 0;
    v3[291] = 0;
    v3[292] = 0;
    v3[293] = 0;
    v3[294] = 0;
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CTriggerSoundscape *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102208C0
// Name: struct datamap_t __near * DataMapInit<class CEnvSoundscapeProxy>(class CEnvSoundscapeProxy __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CEnvSoundscapeProxy>()
{
  if ( (_S2_207 & 1) == 0 )
  {
    _S2_207 |= 1u;
    nameHolder_394.m_pszBase = "CEnvSoundscapeProxy";
    nameHolder_394.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_394.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_394.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_394.m_Names.m_Size = 0;
    nameHolder_394.m_Names.m_pElements = nullptr;
    nameHolder_394.m_nLenBase = 19;
    atexit(func: DataMapInit_CEnvSoundscapeProxy__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CEnvSoundscapeProxy::m_DataMap.baseMap = &CEnvSoundscape::m_DataMap;
  CEnvSoundscapeProxy::m_DataMap.dataNumFields = 1;
  CEnvSoundscapeProxy::m_DataMap.dataDesc = &dataDesc_377[1];
  return &CEnvSoundscapeProxy::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10220930
// Name: struct datamap_t __near * DataMapInit<class CEnvSoundscape>(class CEnvSoundscape __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CEnvSoundscape>()
{
  if ( (_S3_118 & 1) == 0 )
  {
    _S3_118 |= 1u;
    nameHolder_395.m_pszBase = "CEnvSoundscape";
    nameHolder_395.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_395.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_395.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_395.m_Names.m_Size = 0;
    nameHolder_395.m_Names.m_pElements = nullptr;
    nameHolder_395.m_nLenBase = 14;
    atexit(func: DataMapInit_CEnvSoundscape__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CEnvSoundscape::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S3_118 & 2) == 0 )
  {
    _S3_118 |= 2u;
    dataDesc_378[16].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_378[16].inputFunc = 0;
    *(_QWORD *)&dataDesc_378[16].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_378[16].override_count = 0;
    *(_QWORD *)dataDesc_378[16].flatOffset = 0;
    *(_DWORD *)&dataDesc_378[16].flatGroup = 0;
  }
  CEnvSoundscape::m_DataMap.dataNumFields = 16;
  CEnvSoundscape::m_DataMap.dataDesc = &dataDesc_378[1];
  return &CEnvSoundscape::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10220A00
// Name: struct datamap_t __near * DataMapInit<class CEnvSoundscapeTriggerable>(class CEnvSoundscapeTriggerable __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CEnvSoundscapeTriggerable>()
{
  if ( (_S4_56 & 1) == 0 )
  {
    _S4_56 |= 1u;
    nameHolder_396.m_pszBase = "CEnvSoundscapeTriggerable";
    nameHolder_396.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_396.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_396.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_396.m_Names.m_Size = 0;
    nameHolder_396.m_Names.m_pElements = nullptr;
    nameHolder_396.m_nLenBase = 25;
    atexit(func: DataMapInit_CEnvSoundscapeTriggerable__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CEnvSoundscapeTriggerable::m_DataMap.baseMap = &CEnvSoundscape::m_DataMap;
  CEnvSoundscapeTriggerable::m_DataMap.dataNumFields = 1;
  CEnvSoundscapeTriggerable::m_DataMap.dataDesc = dataDesc_484;
  return &CEnvSoundscapeTriggerable::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x102246C0
// Name: struct datamap_t __near * DataMapInit<class CSprite>(class CSprite __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CSprite>()
{
  char *Name; // eax

  if ( (_S2_210 & 1) == 0 )
  {
    _S2_210 |= 1u;
    nameHolder_400.m_pszBase = "CSprite";
    nameHolder_400.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_400.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_400.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_400.m_Names.m_Size = 0;
    nameHolder_400.m_Names.m_pElements = nullptr;
    nameHolder_400.m_nLenBase = 7;
    atexit(func: DataMapInit_CSprite__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CSprite::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S2_210 & 2) == 0 )
  {
    _S2_210 |= 2u;
    dataDesc_380[21].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_400,
                                   pszIdentifier: "AnimateThink");
    dataDesc_380[21].flags = 32;
    dataDesc_380[21].fieldOffset = 0;
    dataDesc_380[21].fieldSize = 1;
    dataDesc_380[21].externalName = nullptr;
    dataDesc_380[21].pSaveRestoreOps = nullptr;
    dataDesc_380[21].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CSprite::AnimateThink;
    *(_QWORD *)&dataDesc_380[21].td = 0;
    *(_QWORD *)&dataDesc_380[21].override_field = 0;
    *(_QWORD *)&dataDesc_380[21].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_380[21].flatOffset[1] = 0;
    dataDesc_380[22].fieldType = FIELD_VOID;
    dataDesc_380[22].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_400,
                                   pszIdentifier: "ExpandThink");
    dataDesc_380[22].fieldOffset = 0;
    dataDesc_380[22].fieldSize = 1;
    dataDesc_380[22].flags = 32;
    dataDesc_380[22].externalName = nullptr;
    dataDesc_380[22].pSaveRestoreOps = nullptr;
    dataDesc_380[22].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CSprite::ExpandThink;
    *(_QWORD *)&dataDesc_380[22].td = 0;
    *(_QWORD *)&dataDesc_380[22].override_field = 0;
    *(_QWORD *)&dataDesc_380[22].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_380[22].flatOffset[1] = 0;
    dataDesc_380[23].fieldType = FIELD_VOID;
    Name = CDatadescGeneratedNameHolder::GenerateName(this: &nameHolder_400, pszIdentifier: "AnimateUntilDead");
    dataDesc_380[23].fieldSize = 1;
    dataDesc_380[23].fieldName = Name;
    dataDesc_380[23].fieldOffset = 0;
    dataDesc_380[23].flags = 32;
    dataDesc_380[23].externalName = nullptr;
    dataDesc_380[23].pSaveRestoreOps = nullptr;
    dataDesc_380[23].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CSprite::AnimateUntilDead;
    *(_QWORD *)&dataDesc_380[23].td = 0;
    *(_QWORD *)&dataDesc_380[23].override_field = 0;
    *(_QWORD *)&dataDesc_380[23].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_380[23].flatOffset[1] = 0;
    dataDesc_380[24].fieldType = FIELD_VOID;
    dataDesc_380[24].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_400,
                                   pszIdentifier: "BeginFadeOutThink");
    dataDesc_380[24].fieldSize = 1;
    dataDesc_380[24].fieldOffset = 0;
    dataDesc_380[24].flags = 32;
    dataDesc_380[24].externalName = nullptr;
    dataDesc_380[24].pSaveRestoreOps = nullptr;
    dataDesc_380[24].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CSprite::BeginFadeOutThink;
    *(_QWORD *)&dataDesc_380[24].td = 0;
    *(_QWORD *)&dataDesc_380[24].override_field = 0;
    *(_QWORD *)&dataDesc_380[24].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_380[24].flatOffset[1] = 0;
    dataDesc_380[25].fieldType = FIELD_FLOAT;
    dataDesc_380[25].fieldName = "m_flSpriteScale";
    dataDesc_380[25].fieldOffset = 880;
    dataDesc_380[25].fieldSize = 1;
    dataDesc_380[25].flags = 14;
    dataDesc_380[25].externalName = "SetScale";
    dataDesc_380[25].pSaveRestoreOps = nullptr;
    *(_QWORD *)&dataDesc_380[25].override_field = 0;
    *(_QWORD *)&dataDesc_380[25].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_380[25].flatOffset[1] = 0;
    dataDesc_380[26].fieldSize = 1;
    *(_QWORD *)&dataDesc_380[26].td = 0;
    *(_QWORD *)&dataDesc_380[26].override_field = 0;
    *(_QWORD *)&dataDesc_380[26].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_380[26].flatOffset[1] = 0;
    dataDesc_380[26].flags = 8;
    dataDesc_380[27].fieldSize = 1;
    *(_QWORD *)&dataDesc_380[27].td = 0;
    *(_QWORD *)&dataDesc_380[27].override_field = 0;
    *(_QWORD *)&dataDesc_380[27].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_380[27].flatOffset[1] = 0;
    dataDesc_380[27].flags = 8;
    dataDesc_380[28].fieldSize = 1;
    *(_QWORD *)&dataDesc_380[28].td = 0;
    *(_QWORD *)&dataDesc_380[28].override_field = 0;
    *(_QWORD *)&dataDesc_380[28].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_380[28].flatOffset[1] = 0;
    dataDesc_380[28].flags = 8;
    dataDesc_380[29].fieldSize = 1;
    *(_QWORD *)&dataDesc_380[29].td = 0;
    *(_QWORD *)&dataDesc_380[29].override_field = 0;
    *(_QWORD *)&dataDesc_380[29].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_380[29].flatOffset[1] = 0;
    dataDesc_380[25].inputFunc = nullptr;
    dataDesc_380[25].td = nullptr;
    dataDesc_380[25].fieldSizeInBytes = 4;
    dataDesc_380[26].fieldType = FIELD_VOID;
    dataDesc_380[26].fieldName = "InputHideSprite";
    dataDesc_380[26].fieldOffset = 0;
    dataDesc_380[26].externalName = "HideSprite";
    dataDesc_380[26].pSaveRestoreOps = nullptr;
    dataDesc_380[26].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CSprite::InputHideSprite;
    dataDesc_380[27].fieldType = FIELD_VOID;
    dataDesc_380[27].fieldName = "InputShowSprite";
    dataDesc_380[27].fieldOffset = 0;
    dataDesc_380[27].externalName = "ShowSprite";
    dataDesc_380[27].pSaveRestoreOps = nullptr;
    dataDesc_380[27].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CSprite::InputShowSprite;
    dataDesc_380[28].fieldType = FIELD_VOID;
    dataDesc_380[28].fieldName = "InputToggleSprite";
    dataDesc_380[28].fieldOffset = 0;
    dataDesc_380[28].externalName = "ToggleSprite";
    dataDesc_380[28].pSaveRestoreOps = nullptr;
    dataDesc_380[28].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CSprite::InputToggleSprite;
    dataDesc_380[29].fieldType = FIELD_FLOAT;
    dataDesc_380[29].fieldName = "InputColorRedValue";
    dataDesc_380[29].fieldOffset = 0;
    dataDesc_380[29].flags = 8;
    dataDesc_380[29].externalName = "ColorRedValue";
    dataDesc_380[29].pSaveRestoreOps = nullptr;
    dataDesc_380[29].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CBeam::InputColorRedValue;
    dataDesc_380[30].fieldType = FIELD_FLOAT;
    dataDesc_380[30].fieldName = "InputColorGreenValue";
    dataDesc_380[30].fieldOffset = 0;
    *(_DWORD *)&dataDesc_380[30].fieldSize = 524289;
    dataDesc_380[30].externalName = "ColorGreenValue";
    dataDesc_380[30].pSaveRestoreOps = nullptr;
    dataDesc_380[30].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CSprite::InputColorGreenValue;
    *(_QWORD *)&dataDesc_380[30].td = 0;
    *(_QWORD *)&dataDesc_380[30].override_field = 0;
    *(_QWORD *)&dataDesc_380[30].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_380[30].flatOffset[1] = 0;
    dataDesc_380[31].fieldType = FIELD_FLOAT;
    dataDesc_380[31].fieldName = "InputColorBlueValue";
    dataDesc_380[31].fieldOffset = 0;
    *(_DWORD *)&dataDesc_380[31].fieldSize = 524289;
    dataDesc_380[31].externalName = "ColorBlueValue";
    dataDesc_380[31].pSaveRestoreOps = nullptr;
    dataDesc_380[31].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CSprite::InputColorBlueValue;
    *(_QWORD *)&dataDesc_380[31].td = 0;
    *(_QWORD *)&dataDesc_380[31].override_field = 0;
    *(_QWORD *)&dataDesc_380[31].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_380[31].flatOffset[1] = 0;
  }
  CSprite::m_DataMap.dataNumFields = 31;
  CSprite::m_DataMap.dataDesc = &dataDesc_380[1];
  return &CSprite::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1022C620
// Name: struct datamap_t __near * DataMapInit<class CSun>(class CSun __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CSun>()
{
  if ( (_S3_124 & 1) == 0 )
  {
    _S3_124 |= 1u;
    nameHolder_404.m_pszBase = "CSun";
    nameHolder_404.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_404.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_404.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_404.m_Names.m_Size = 0;
    nameHolder_404.m_Names.m_pElements = nullptr;
    nameHolder_404.m_nLenBase = 4;
    atexit(func: DataMapInit_CSun__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CSun::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CSun::m_DataMap.dataNumFields = 14;
  CSun::m_DataMap.dataDesc = &dataDesc_384[1];
  return &CSun::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1022E920
// Name: class CFuncTankTrain __near * _CreateEntityTemplate<class CFuncTankTrain>(class CFuncTankTrain __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFuncTankTrain *__cdecl _CreateEntityTemplate<CFuncTankTrain>(CFuncTankTrain *newEnt, const char *className)
{
  CFuncTrackTrain *v2; // eax
  _DWORD *v3; // esi

  v2 = (CFuncTrackTrain *)CBaseEntity::operator new(stAllocateBlock: 0x450u);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CFuncTrackTrain::CFuncTrackTrain(this: v2);
    *v3 = &CFuncTankTrain::`vftable';
    v3[270] = 0;
    v3[273] = -1;
    v3[274] = 0;
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CFuncTankTrain *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1022E9B0
// Name: struct datamap_t __near * DataMapInit<class CFuncTankTrain>(class CFuncTankTrain __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CFuncTankTrain>()
{
  if ( (_S2_216 & 1) == 0 )
  {
    _S2_216 |= 1u;
    nameHolder_408.m_pszBase = "CFuncTankTrain";
    nameHolder_408.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_408.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_408.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_408.m_Names.m_Size = 0;
    nameHolder_408.m_Names.m_pElements = nullptr;
    nameHolder_408.m_nLenBase = 14;
    atexit(func: DataMapInit_CFuncTankTrain__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CFuncTankTrain::m_DataMap.baseMap = &CFuncTrackTrain::m_DataMap;
  if ( (_S2_216 & 2) == 0 )
  {
    _S2_216 |= 2u;
    dataDesc_388[1].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_388[1].inputFunc = 0;
    *(_QWORD *)&dataDesc_388[1].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_388[1].override_count = 0;
    *(_QWORD *)dataDesc_388[1].flatOffset = 0;
    *(_DWORD *)&dataDesc_388[1].flatGroup = 0;
  }
  CFuncTankTrain::m_DataMap.dataNumFields = 1;
  CFuncTankTrain::m_DataMap.dataDesc = &dataDesc_388[1];
  return &CFuncTankTrain::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1022EA70
// Name: struct datamap_t __near * DataMapInit<class CTankTargetChange>(class CTankTargetChange __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CTankTargetChange>()
{
  if ( (_S3_127 & 1) == 0 )
  {
    _S3_127 |= 1u;
    nameHolder_409.m_pszBase = "CTankTargetChange";
    nameHolder_409.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_409.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_409.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_409.m_Names.m_Size = 0;
    nameHolder_409.m_Names.m_pElements = nullptr;
    nameHolder_409.m_nLenBase = 17;
    atexit(func: DataMapInit_CTankTargetChange__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CTankTargetChange::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CTankTargetChange::m_DataMap.dataNumFields = 1;
  CTankTargetChange::m_DataMap.dataDesc = &dataDesc_389[1];
  return &CTankTargetChange::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1022EAE0
// Name: struct datamap_t __near * DataMapInit<class CTankTrainAI>(class CTankTrainAI __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CTankTrainAI>()
{
  ISaveRestoreOps *SoundSaveRestoreOps; // eax

  if ( (_S4_59 & 1) == 0 )
  {
    _S4_59 |= 1u;
    nameHolder_410.m_pszBase = "CTankTrainAI";
    nameHolder_410.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_410.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_410.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_410.m_Names.m_Size = 0;
    nameHolder_410.m_Names.m_pElements = nullptr;
    nameHolder_410.m_nLenBase = 12;
    atexit(func: DataMapInit_CTankTrainAI__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CTankTrainAI::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S4_59 & 2) == 0 )
  {
    _S4_59 |= 2u;
    dataDesc_390[4].pSaveRestoreOps = GetSoundSaveRestoreOps();
    dataDesc_390[4].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_390[4].td = 0;
    *(_QWORD *)&dataDesc_390[4].override_field = 0;
    *(_QWORD *)&dataDesc_390[4].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_390[4].flatOffset[1] = 0;
    dataDesc_390[5].fieldType = FIELD_CUSTOM;
    dataDesc_390[5].fieldName = "m_soundEngine";
    dataDesc_390[5].fieldOffset = 868;
    dataDesc_390[5].fieldSize = 1;
    dataDesc_390[5].flags = 2;
    dataDesc_390[5].externalName = nullptr;
    SoundSaveRestoreOps = GetSoundSaveRestoreOps();
    *(_QWORD *)dataDesc_390[6].flatOffset = 0;
    dataDesc_390[5].pSaveRestoreOps = SoundSaveRestoreOps;
    *(_QWORD *)&dataDesc_390[5].td = 0;
    *(_QWORD *)&dataDesc_390[5].override_field = 0;
    *(_QWORD *)&dataDesc_390[5].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_390[5].flatOffset[1] = 0;
    *(_QWORD *)dataDesc_390[7].flatOffset = 0;
    dataDesc_390[5].inputFunc = nullptr;
    dataDesc_390[6].fieldType = FIELD_STRING;
    dataDesc_390[6].fieldName = "m_startSoundName";
    dataDesc_390[6].fieldOffset = 872;
    *(_DWORD *)&dataDesc_390[6].fieldSize = 393217;
    dataDesc_390[6].externalName = "startsound";
    dataDesc_390[6].pSaveRestoreOps = nullptr;
    dataDesc_390[6].inputFunc = nullptr;
    dataDesc_390[6].td = nullptr;
    dataDesc_390[6].fieldSizeInBytes = 4;
    dataDesc_390[6].override_field = nullptr;
    dataDesc_390[6].override_count = 0;
    dataDesc_390[6].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_390[6].flatGroup = 0;
    dataDesc_390[7].fieldType = FIELD_STRING;
    dataDesc_390[7].fieldName = "m_engineSoundName";
    dataDesc_390[7].fieldOffset = 876;
    *(_DWORD *)&dataDesc_390[7].fieldSize = 393217;
    dataDesc_390[7].externalName = "enginesound";
    dataDesc_390[7].pSaveRestoreOps = nullptr;
    dataDesc_390[7].inputFunc = nullptr;
    dataDesc_390[7].td = nullptr;
    dataDesc_390[7].fieldSizeInBytes = 4;
    dataDesc_390[7].override_field = nullptr;
    dataDesc_390[7].override_count = 0;
    dataDesc_390[7].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_390[7].flatGroup = 0;
    dataDesc_390[8].fieldType = FIELD_STRING;
    dataDesc_390[8].fieldName = "m_movementSoundName";
    dataDesc_390[8].fieldOffset = 880;
    *(_DWORD *)&dataDesc_390[8].fieldSize = 393217;
    dataDesc_390[8].externalName = "movementsound";
    dataDesc_390[8].pSaveRestoreOps = nullptr;
    dataDesc_390[8].inputFunc = nullptr;
    dataDesc_390[8].td = nullptr;
    dataDesc_390[8].fieldSizeInBytes = 4;
    dataDesc_390[8].override_field = nullptr;
    dataDesc_390[8].override_count = 0;
    dataDesc_390[8].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_390[8].flatOffset = 0;
    *(_DWORD *)&dataDesc_390[8].flatGroup = 0;
    dataDesc_390[9].fieldType = FIELD_STRING;
    dataDesc_390[9].fieldName = "m_targetEntityName";
    dataDesc_390[9].fieldOffset = 884;
    dataDesc_390[9].fieldSize = 1;
    dataDesc_390[9].flags = 2;
    dataDesc_390[9].externalName = nullptr;
    dataDesc_390[9].pSaveRestoreOps = nullptr;
    dataDesc_390[9].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_390[9].flatOffset = 0;
    dataDesc_390[9].inputFunc = nullptr;
    dataDesc_390[9].td = nullptr;
    dataDesc_390[9].fieldSizeInBytes = 4;
    dataDesc_390[9].override_field = nullptr;
    dataDesc_390[9].override_count = 0;
    *(_DWORD *)&dataDesc_390[9].flatGroup = 0;
    dataDesc_390[10].fieldType = FIELD_STRING;
    dataDesc_390[10].fieldName = "InputTargetEntity";
    dataDesc_390[10].fieldOffset = 0;
    *(_DWORD *)&dataDesc_390[10].fieldSize = 524289;
    dataDesc_390[10].externalName = "TargetEntity";
    dataDesc_390[10].pSaveRestoreOps = nullptr;
    dataDesc_390[10].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CTankTrainAI::InputTargetEntity;
    *(_QWORD *)&dataDesc_390[10].td = 0;
    *(_QWORD *)&dataDesc_390[10].override_field = 0;
    *(_QWORD *)&dataDesc_390[10].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_390[10].flatOffset[1] = 0;
  }
  CTankTrainAI::m_DataMap.dataNumFields = 10;
  CTankTrainAI::m_DataMap.dataDesc = &dataDesc_390[1];
  return &CTankTrainAI::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x102306B0
// Name: class CTeamSpawnPoint __near * _CreateEntityTemplate<class CTeamSpawnPoint>(class CTeamSpawnPoint __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CTeamSpawnPoint *__cdecl _CreateEntityTemplate<CTeamSpawnPoint>(CTeamSpawnPoint *newEnt, const char *className)
{
  CBaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x370u);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    *v3 = &CTeamSpawnPoint::`vftable';
    v3[213] = 0;
    v3[216] = -1;
    v3[217] = 0;
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CTeamSpawnPoint *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10230720
// Name: class CTeamVehicleSpawnPoint __near * _CreateEntityTemplate<class CTeamVehicleSpawnPoint>(class CTeamVehicleSpawnPoint __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CTeamVehicleSpawnPoint *__cdecl _CreateEntityTemplate<CTeamVehicleSpawnPoint>(
        CTeamVehicleSpawnPoint *newEnt,
        const char *className)
{
  CBaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x388u);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3[213] = 0;
    v3[216] = -1;
    v3[217] = 0;
    *v3 = &CTeamVehicleSpawnPoint::`vftable';
    v3[220] = 0;
    v3[223] = -1;
    v3[224] = 0;
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CTeamVehicleSpawnPoint *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102307E0
// Name: struct datamap_t __near * DataMapInit<class CTeamSpawnPoint>(class CTeamSpawnPoint __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CTeamSpawnPoint>()
{
  if ( (_S2_219 & 1) == 0 )
  {
    _S2_219 |= 1u;
    nameHolder_412.m_pszBase = "CTeamSpawnPoint";
    nameHolder_412.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_412.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_412.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_412.m_Names.m_Size = 0;
    nameHolder_412.m_Names.m_pElements = nullptr;
    nameHolder_412.m_nLenBase = 15;
    atexit(func: DataMapInit_CTeamSpawnPoint__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CTeamSpawnPoint::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S2_219 & 2) == 0 )
  {
    _S2_219 |= 2u;
    dataDesc_392[4].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_392[4].inputFunc = 0;
    *(_QWORD *)&dataDesc_392[4].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_392[4].override_count = 0;
    *(_QWORD *)dataDesc_392[4].flatOffset = 0;
    *(_DWORD *)&dataDesc_392[4].flatGroup = 0;
  }
  CTeamSpawnPoint::m_DataMap.dataNumFields = 4;
  CTeamSpawnPoint::m_DataMap.dataDesc = &dataDesc_392[1];
  return &CTeamSpawnPoint::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x102308B0
// Name: struct datamap_t __near * DataMapInit<class CTeamVehicleSpawnPoint>(class CTeamVehicleSpawnPoint __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CTeamVehicleSpawnPoint>()
{
  if ( (_S3_129 & 1) == 0 )
  {
    _S3_129 |= 1u;
    nameHolder_413.m_pszBase = "CTeamVehicleSpawnPoint";
    nameHolder_413.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_413.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_413.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_413.m_Names.m_Size = 0;
    nameHolder_413.m_Names.m_pElements = nullptr;
    nameHolder_413.m_nLenBase = 22;
    atexit(func: DataMapInit_CTeamVehicleSpawnPoint__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CTeamVehicleSpawnPoint::m_DataMap.baseMap = &CTeamSpawnPoint::m_DataMap;
  if ( (_S3_129 & 2) == 0 )
  {
    _S3_129 |= 2u;
    dataDesc_393[1].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_393[1].inputFunc = 0;
    *(_QWORD *)&dataDesc_393[1].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_393[1].override_count = 0;
    *(_QWORD *)dataDesc_393[1].flatOffset = 0;
    *(_DWORD *)&dataDesc_393[1].flatGroup = 0;
  }
  CTeamVehicleSpawnPoint::m_DataMap.dataNumFields = 1;
  CTeamVehicleSpawnPoint::m_DataMap.dataDesc = &dataDesc_393[1];
  return &CTeamVehicleSpawnPoint::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10232E80
// Name: struct datamap_t __near * DataMapInit<class CTesla>(class CTesla __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CTesla>()
{
  if ( (_S2_222 & 1) == 0 )
  {
    _S2_222 |= 1u;
    nameHolder_416.m_pszBase = "CTesla";
    nameHolder_416.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_416.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_416.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_416.m_Names.m_Size = 0;
    nameHolder_416.m_Names.m_pElements = nullptr;
    nameHolder_416.m_nLenBase = 6;
    atexit(func: DataMapInit_CTesla__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CTesla::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S2_222 & 2) == 0 )
  {
    _S2_222 |= 2u;
    dataDesc_396[18].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_416,
                                   pszIdentifier: "ShootArcThink");
    dataDesc_396[18].fieldOffset = 0;
    *(_DWORD *)&dataDesc_396[18].fieldSize = 2097153;
    dataDesc_396[18].externalName = nullptr;
    dataDesc_396[18].pSaveRestoreOps = nullptr;
    dataDesc_396[18].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CTesla::ShootArcThink;
    *(_QWORD *)&dataDesc_396[18].td = 0;
    *(_QWORD *)&dataDesc_396[18].override_field = 0;
    *(_QWORD *)&dataDesc_396[18].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_396[18].flatOffset[1] = 0;
  }
  CTesla::m_DataMap.dataNumFields = 18;
  CTesla::m_DataMap.dataDesc = &dataDesc_396[1];
  return &CTesla::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10233ED0
// Name: struct datamap_t __near * DataMapInit<class CTestTraceline>(class CTestTraceline __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CTestTraceline>()
{
  if ( (_S3_133 & 1) == 0 )
  {
    _S3_133 |= 1u;
    nameHolder_417.m_pszBase = "CTestTraceline";
    nameHolder_417.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_417.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_417.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_417.m_Names.m_Size = 0;
    nameHolder_417.m_Names.m_pElements = nullptr;
    nameHolder_417.m_nLenBase = 14;
    atexit(func: DataMapInit_CTestTraceline__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CTestTraceline::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S3_133 & 2) == 0 )
  {
    _S3_133 |= 2u;
    dataDesc_487[1].fieldName = CDatadescGeneratedNameHolder::GenerateName(this: &nameHolder_417, pszIdentifier: "Spin");
    dataDesc_487[1].fieldOffset = 0;
    *(_DWORD *)&dataDesc_487[1].fieldSize = 2097153;
    dataDesc_487[1].externalName = nullptr;
    dataDesc_487[1].pSaveRestoreOps = nullptr;
    dataDesc_487[1].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CTestTraceline::Spin;
    *(_QWORD *)&dataDesc_487[1].td = 0;
    *(_QWORD *)&dataDesc_487[1].override_field = 0;
    *(_QWORD *)&dataDesc_487[1].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_487[1].flatOffset[1] = 0;
  }
  CTestTraceline::m_DataMap.dataNumFields = 1;
  CTestTraceline::m_DataMap.dataDesc = &dataDesc_487[1];
  return &CTestTraceline::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10241000
// Name: class CTriggerWind __near * _CreateEntityTemplate<class CTriggerWind>(class CTriggerWind __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CTriggerWind *__cdecl _CreateEntityTemplate<CTriggerWind>(CTriggerWind *newEnt, const char *className)
{
  CBaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x39Cu);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3[215] = -1;
    *v3 = &CTriggerWind::`vftable';
    v3[228] = &CPhysicsWind::`vftable';
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CTriggerWind *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10241060
// Name: class CTriggerVPhysicsMotion __near * _CreateEntityTemplate<class CTriggerVPhysicsMotion>(class CTriggerVPhysicsMotion __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CTriggerVPhysicsMotion *__cdecl _CreateEntityTemplate<CTriggerVPhysicsMotion>(
        CTriggerVPhysicsMotion *newEnt,
        const char *className)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x3B4u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3[1].m_pfnThink = (void (__thiscall *)(CBaseEntity *))-1;
    v3[1].m_Network.__vftable = (CServerNetworkProperty_vtbl *)&IMotionEvent::`vftable';
    v3->__vftable = (CBaseEntity_vtbl *)&CTriggerVPhysicsMotion::`vftable'{for `CBaseVPhysicsTrigger'};
    v3[1].m_Network.__vftable = (CServerNetworkProperty_vtbl *)&CTriggerVPhysicsMotion::`vftable'{for `IMotionEvent'};
    EntityParticleTrailInfo_t::EntityParticleTrailInfo_t(this: (EntityParticleTrailInfo_t *)&v3[1].m_Network.m_pOuter);
    v3->PostConstructor(this: v3, a2: className);
    return (CTriggerVPhysicsMotion *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10247DA0
// Name: void ScriptDeduceFunctionSignature<class CTriggerCamera __near *,class CTriggerCamera,void,int,float>(struct ScriptFuncDescriptor_t __near *,class CTriggerCamera __near *,void (CTriggerCamera::*)(int,float))
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ScriptDeduceFunctionSignature<CTriggerCamera *,CTriggerCamera,void,int,float>(
        ScriptFuncDescriptor_t *pDesc)
{
  CUtlVector<int,CUtlMemory<int,int> > *p_m_Parameters; // esi
  IMemAlloc_vtbl *v2; // edx
  int v3; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v7; // eax
  int *v8; // eax
  int v9; // edi
  int v10; // eax
  int *v11; // ecx
  int v12; // eax
  int *v13; // eax

  pDesc->m_ReturnType = 0;
  pDesc->m_Parameters.m_Memory.m_nGrowSize = 1;
  p_m_Parameters = &pDesc->m_Parameters;
  if ( pDesc->m_Parameters.m_Memory.m_nAllocationCount < 2 && pDesc->m_Parameters.m_Memory.m_nGrowSize >= 0 )
  {
    pDesc->m_Parameters.m_Memory.m_nAllocationCount = 2;
    v2 = _g_pMemAlloc->__vftable;
    if ( p_m_Parameters->m_Memory.m_pMemory != nullptr )
      v3 = ((int (__stdcall *)(int *, int))v2->Realloc_2)(a1: p_m_Parameters->m_Memory.m_pMemory, a2: 8);
    else
      v3 = ((int (__stdcall *)(int))v2->Alloc_2)(a1: 8);
    p_m_Parameters->m_Memory.m_pMemory = (int *)v3;
  }
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  m_Size = pDesc->m_Parameters.m_Size;
  m_nAllocationCount = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters,
      num: m_Size - m_nAllocationCount + 1);
  ++pDesc->m_Parameters.m_Size;
  m_pMemory = p_m_Parameters->m_Memory.m_pMemory;
  v7 = pDesc->m_Parameters.m_Size - m_Size - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
  v8 = &p_m_Parameters->m_Memory.m_pMemory[m_Size];
  if ( v8 != nullptr )
    *v8 = 5;
  v9 = pDesc->m_Parameters.m_Size;
  v10 = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( v9 + 1 > v10 )
    CUtlMemory<CNavLadder *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters, num: v9 - v10 + 1);
  ++pDesc->m_Parameters.m_Size;
  v11 = p_m_Parameters->m_Memory.m_pMemory;
  v12 = pDesc->m_Parameters.m_Size - v9 - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v12 > 0 )
    _V_memmove(dest: &v11[v9 + 1], src: &v11[v9], count: 4 * v12);
  v13 = &p_m_Parameters->m_Memory.m_pMemory[v9];
  if ( v13 != nullptr )
    *v13 = 1;
}

//------------------------------------------------------------------------------
// Address: 0x10247EA0
// Name: class CTriggerRemove __near * _CreateEntityTemplate<class CTriggerRemove>(class CTriggerRemove __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CTriggerRemove *__cdecl _CreateEntityTemplate<CTriggerRemove>(CTriggerRemove *newEnt, const char *className)
{
  CBaseTrigger *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseTrigger *)CBaseEntity::operator new(stAllocateBlock: 0x498u);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseTrigger::CBaseTrigger(this: v2);
    *v3 = &CTriggerRemove::`vftable';
    v3[288] = 0;
    v3[291] = -1;
    v3[292] = 0;
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CTriggerRemove *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10247F10
// Name: class CTriggerMultiple __near * _CreateEntityTemplate<class CTriggerMultiple>(class CTriggerMultiple __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CTriggerMultiple *__cdecl _CreateEntityTemplate<CTriggerMultiple>(CTriggerMultiple *newEnt, const char *className)
{
  CBaseTrigger *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseTrigger *)CBaseEntity::operator new(stAllocateBlock: 0x498u);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseTrigger::CBaseTrigger(this: v2);
    *v3 = &CTriggerMultiple::`vftable';
    v3[288] = 0;
    v3[291] = -1;
    v3[292] = 0;
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CTriggerMultiple *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10247F80
// Name: class CChangeLevel __near * _CreateEntityTemplate<class CChangeLevel>(class CChangeLevel __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CChangeLevel *__cdecl _CreateEntityTemplate<CChangeLevel>(CChangeLevel *newEnt, const char *className)
{
  CBaseTrigger *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseTrigger *)CBaseEntity::operator new(stAllocateBlock: 0x4DCu);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseTrigger::CBaseTrigger(this: v2);
    *v3 = &CChangeLevel::`vftable';
    v3[305] = 0;
    v3[308] = -1;
    v3[309] = 0;
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CChangeLevel *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10247FF0
// Name: class CTriggerProximity __near * _CreateEntityTemplate<class CTriggerProximity>(class CTriggerProximity __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CTriggerProximity *__cdecl _CreateEntityTemplate<CTriggerProximity>(CTriggerProximity *newEnt, const char *className)
{
  CBaseTrigger *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseTrigger *)CBaseEntity::operator new(stAllocateBlock: 0x4A8u);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseTrigger::CBaseTrigger(this: v2);
    *v3 = &CTriggerProximity::`vftable';
    v3[288] = -1;
    v3[292] = 0;
    v3[295] = -1;
    v3[296] = 0;
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CTriggerProximity *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102481A0
// Name: struct datamap_t __near * DataMapInit<class CTriggerHurt>(class CTriggerHurt __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CTriggerHurt>()
{
  if ( (_S5_33 & 1) == 0 )
  {
    _S5_33 |= 1u;
    nameHolder_446.m_pszBase = "CTriggerHurt";
    nameHolder_446.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_446.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_446.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_446.m_Names.m_Size = 0;
    nameHolder_446.m_Names.m_pElements = nullptr;
    nameHolder_446.m_nLenBase = 12;
    atexit(func: DataMapInit_CTriggerHurt__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CTriggerHurt::m_DataMap.baseMap = &CBaseTrigger::m_DataMap;
  if ( (_S5_33 & 2) == 0 )
  {
    _S5_33 |= 2u;
    dataDesc_494[1].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_446,
                                  pszIdentifier: "RadiationThink");
    dataDesc_494[1].flags = 32;
    dataDesc_494[1].fieldOffset = 0;
    dataDesc_494[1].fieldSize = 1;
    dataDesc_494[1].externalName = nullptr;
    dataDesc_494[1].pSaveRestoreOps = nullptr;
    dataDesc_494[1].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CTriggerHurt::RadiationThink;
    *(_QWORD *)&dataDesc_494[1].td = 0;
    *(_QWORD *)&dataDesc_494[1].override_field = 0;
    *(_QWORD *)&dataDesc_494[1].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_494[1].flatOffset[1] = 0;
    dataDesc_494[2].fieldType = FIELD_VOID;
    dataDesc_494[2].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_446,
                                  pszIdentifier: "HurtThink");
    dataDesc_494[2].fieldOffset = 0;
    dataDesc_494[2].fieldSize = 1;
    dataDesc_494[2].flags = 32;
    dataDesc_494[2].externalName = nullptr;
    dataDesc_494[2].pSaveRestoreOps = nullptr;
    dataDesc_494[2].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CTriggerHurt::HurtThink;
    *(_QWORD *)&dataDesc_494[2].td = 0;
    *(_QWORD *)&dataDesc_494[2].override_field = 0;
    *(_QWORD *)&dataDesc_494[2].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_494[2].flatOffset[1] = 0;
    dataDesc_494[3].fieldType = FIELD_VOID;
    dataDesc_494[3].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_446,
                                  pszIdentifier: "NavThink");
    dataDesc_494[3].fieldSize = 1;
    dataDesc_494[3].flags = 32;
    dataDesc_494[4].fieldSize = 1;
    dataDesc_494[4].flags = 2;
    *(_QWORD *)&dataDesc_494[3].td = 0;
    *(_QWORD *)&dataDesc_494[3].override_field = 0;
    *(_QWORD *)&dataDesc_494[3].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_494[3].flatOffset[1] = 0;
    dataDesc_494[3].fieldOffset = 0;
    dataDesc_494[3].externalName = nullptr;
    dataDesc_494[3].pSaveRestoreOps = nullptr;
    dataDesc_494[3].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CTriggerHurt::NavThink;
    dataDesc_494[4].fieldType = FIELD_FLOAT;
    dataDesc_494[4].fieldName = "m_flOriginalDamage";
    dataDesc_494[4].fieldOffset = 1152;
    dataDesc_494[4].externalName = nullptr;
    dataDesc_494[4].pSaveRestoreOps = nullptr;
    dataDesc_494[4].inputFunc = nullptr;
    dataDesc_494[4].td = nullptr;
    dataDesc_494[4].fieldSizeInBytes = 4;
    dataDesc_494[4].override_field = nullptr;
    dataDesc_494[4].override_count = 0;
    dataDesc_494[4].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_494[4].flatOffset = 0;
    *(_DWORD *)&dataDesc_494[4].flatGroup = 0;
    dataDesc_494[5].fieldType = FIELD_FLOAT;
    dataDesc_494[5].fieldName = "m_flDamage";
    dataDesc_494[5].fieldOffset = 1156;
    dataDesc_494[5].fieldSize = 1;
    dataDesc_494[5].flags = 6;
    dataDesc_494[6].fieldSize = 1;
    dataDesc_494[6].flags = 6;
    dataDesc_494[7].fieldType = FIELD_INTEGER;
    dataDesc_494[8].fieldType = FIELD_INTEGER;
    dataDesc_494[7].fieldSize = 1;
    dataDesc_494[8].fieldSize = 1;
    *(_QWORD *)dataDesc_494[5].flatOffset = 0;
    dataDesc_494[8].flags = 6;
    dataDesc_494[9].fieldType = FIELD_BOOLEAN;
    *(_QWORD *)dataDesc_494[6].flatOffset = 0;
    dataDesc_494[9].fieldSize = 1;
    *(_QWORD *)dataDesc_494[7].flatOffset = 0;
    dataDesc_494[5].externalName = "damage";
    dataDesc_494[5].pSaveRestoreOps = nullptr;
    dataDesc_494[5].inputFunc = nullptr;
    dataDesc_494[5].td = nullptr;
    dataDesc_494[5].fieldSizeInBytes = 4;
    dataDesc_494[5].override_field = nullptr;
    dataDesc_494[5].override_count = 0;
    dataDesc_494[5].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_494[5].flatGroup = 0;
    dataDesc_494[6].fieldType = FIELD_FLOAT;
    dataDesc_494[6].fieldName = "m_flDamageCap";
    dataDesc_494[6].fieldOffset = 1160;
    dataDesc_494[6].externalName = "damagecap";
    dataDesc_494[6].pSaveRestoreOps = nullptr;
    dataDesc_494[6].inputFunc = nullptr;
    dataDesc_494[6].td = nullptr;
    dataDesc_494[6].fieldSizeInBytes = 4;
    dataDesc_494[6].override_field = nullptr;
    dataDesc_494[6].override_count = 0;
    dataDesc_494[6].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_494[6].flatGroup = 0;
    dataDesc_494[7].fieldName = "m_bitsDamageInflict";
    dataDesc_494[7].fieldOffset = 1172;
    dataDesc_494[7].flags = 6;
    dataDesc_494[7].externalName = "damagetype";
    dataDesc_494[7].pSaveRestoreOps = nullptr;
    dataDesc_494[7].inputFunc = nullptr;
    dataDesc_494[7].td = nullptr;
    dataDesc_494[7].fieldSizeInBytes = 4;
    dataDesc_494[7].override_field = nullptr;
    dataDesc_494[7].override_count = 0;
    dataDesc_494[7].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_494[7].flatGroup = 0;
    dataDesc_494[8].fieldName = "m_damageModel";
    dataDesc_494[8].fieldOffset = 1176;
    dataDesc_494[8].externalName = "damagemodel";
    dataDesc_494[8].pSaveRestoreOps = nullptr;
    dataDesc_494[8].inputFunc = nullptr;
    dataDesc_494[8].td = nullptr;
    dataDesc_494[8].fieldSizeInBytes = 4;
    dataDesc_494[8].override_field = nullptr;
    dataDesc_494[8].override_count = 0;
    dataDesc_494[8].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_494[8].flatOffset = 0;
    *(_DWORD *)&dataDesc_494[8].flatGroup = 0;
    dataDesc_494[9].fieldName = "m_bNoDmgForce";
    dataDesc_494[9].fieldOffset = 1180;
    dataDesc_494[9].flags = 6;
    dataDesc_494[9].externalName = "nodmgforce";
    dataDesc_494[9].pSaveRestoreOps = nullptr;
    dataDesc_494[9].inputFunc = nullptr;
    dataDesc_494[9].td = nullptr;
    dataDesc_494[9].fieldSizeInBytes = 1;
    dataDesc_494[9].override_field = nullptr;
    dataDesc_494[10].fieldType = FIELD_TIME;
    dataDesc_494[11].fieldType = FIELD_TIME;
    dataDesc_494[10].fieldSize = 1;
    dataDesc_494[11].fieldSize = 1;
    dataDesc_494[11].flags = 2;
    dataDesc_494[10].flags = 2;
    dataDesc_494[12].fieldSize = 1;
    dataDesc_494[9].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_494[9].flatOffset = 0;
    dataDesc_494[10].fieldTolerance = 0.0;
    dataDesc_494[11].fieldTolerance = 0.0;
    dataDesc_494[9].override_count = 0;
    *(_DWORD *)&dataDesc_494[9].flatGroup = 0;
    dataDesc_494[10].fieldName = "m_flLastDmgTime";
    dataDesc_494[10].fieldOffset = 1164;
    dataDesc_494[10].externalName = nullptr;
    dataDesc_494[10].pSaveRestoreOps = nullptr;
    dataDesc_494[10].inputFunc = nullptr;
    dataDesc_494[10].td = nullptr;
    dataDesc_494[10].fieldSizeInBytes = 4;
    dataDesc_494[10].override_field = nullptr;
    dataDesc_494[10].override_count = 0;
    *(_QWORD *)dataDesc_494[10].flatOffset = 0;
    *(_DWORD *)&dataDesc_494[10].flatGroup = 0;
    dataDesc_494[11].fieldName = "m_flDmgResetTime";
    dataDesc_494[11].fieldOffset = 1168;
    dataDesc_494[11].externalName = nullptr;
    dataDesc_494[11].pSaveRestoreOps = nullptr;
    dataDesc_494[11].inputFunc = nullptr;
    dataDesc_494[11].td = nullptr;
    dataDesc_494[11].fieldSizeInBytes = 4;
    dataDesc_494[11].override_field = nullptr;
    dataDesc_494[11].override_count = 0;
    *(_QWORD *)dataDesc_494[11].flatOffset = 0;
    *(_DWORD *)&dataDesc_494[11].flatGroup = 0;
    dataDesc_494[12].fieldType = FIELD_CUSTOM;
    dataDesc_494[12].fieldName = "m_hurtEntities";
    dataDesc_494[12].fieldOffset = 1232;
    dataDesc_494[12].flags = 2;
    dataDesc_494[12].externalName = nullptr;
    if ( (`CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int>>>'::`2'::`local static guard'
        & 1) == 0 )
    {
      `CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int>>>'::`2'::`local static guard' |= 1u;
      `CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int>>>'::`2'::ops = (int)&CUtlVectorDataOps<CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int>>,13>::`vftable';
    }
    *(_QWORD *)&dataDesc_494[12].td = 0;
    *(_QWORD *)&dataDesc_494[12].override_field = 0;
    *(_QWORD *)&dataDesc_494[12].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_494[12].flatOffset[1] = 0;
    dataDesc_494[13].fieldSizeInBytes = 4;
    *(_QWORD *)&dataDesc_494[13].override_field = 0;
    *(_QWORD *)&dataDesc_494[13].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_494[13].flatOffset[1] = 0;
    dataDesc_494[13].fieldOffset = 1156;
    dataDesc_494[14].flags = 22;
    *(_QWORD *)&dataDesc_494[14].inputFunc = 0;
    *(_QWORD *)&dataDesc_494[14].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_494[14].override_count = 0;
    *(_QWORD *)dataDesc_494[14].flatOffset = 0;
    dataDesc_494[14].fieldType = FIELD_CUSTOM;
    dataDesc_494[15].fieldType = FIELD_CUSTOM;
    dataDesc_494[12].pSaveRestoreOps = (ISaveRestoreOps *)&`CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int>>>'::`2'::ops;
    dataDesc_494[12].inputFunc = nullptr;
    dataDesc_494[13].fieldType = FIELD_FLOAT;
    dataDesc_494[13].fieldName = "m_flDamage";
    dataDesc_494[13].fieldSize = 1;
    dataDesc_494[13].flags = 14;
    dataDesc_494[13].externalName = "SetDamage";
    dataDesc_494[13].pSaveRestoreOps = nullptr;
    dataDesc_494[13].inputFunc = nullptr;
    dataDesc_494[13].td = nullptr;
    dataDesc_494[14].fieldName = "m_OnHurt";
    dataDesc_494[14].fieldOffset = 1184;
    dataDesc_494[14].fieldSize = 1;
    dataDesc_494[14].externalName = "OnHurt";
    dataDesc_494[14].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_494[14].flatGroup = 0;
    dataDesc_494[15].fieldName = "m_OnHurtPlayer";
    dataDesc_494[15].fieldOffset = 1208;
    *(_DWORD *)&dataDesc_494[15].fieldSize = 1441793;
    dataDesc_494[15].externalName = "OnHurtPlayer";
    dataDesc_494[15].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_494[15].inputFunc = 0;
    *(_QWORD *)&dataDesc_494[15].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_494[15].override_count = 0;
    *(_QWORD *)dataDesc_494[15].flatOffset = 0;
    *(_DWORD *)&dataDesc_494[15].flatGroup = 0;
  }
  CTriggerHurt::m_DataMap.dataNumFields = 15;
  CTriggerHurt::m_DataMap.dataDesc = &dataDesc_494[1];
  return &CTriggerHurt::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x102491F0
// Name: class CTriggerOnce __near * _CreateEntityTemplate<class CTriggerOnce>(class CTriggerOnce __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CTriggerOnce *__cdecl _CreateEntityTemplate<CTriggerOnce>(CTriggerOnce *newEnt, const char *className)
{
  CBaseTrigger *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseTrigger *)CBaseEntity::operator new(stAllocateBlock: 0x498u);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseTrigger::CBaseTrigger(this: v2);
    v3[288] = 0;
    v3[291] = -1;
    v3[292] = 0;
    *v3 = &CTriggerOnce::`vftable';
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CTriggerOnce *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10249260
// Name: class CTriggerLook __near * _CreateEntityTemplate<class CTriggerLook>(class CTriggerLook __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CTriggerLook *__cdecl _CreateEntityTemplate<CTriggerLook>(CTriggerLook *newEnt, const char *className)
{
  CBaseTrigger *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseTrigger *)CBaseEntity::operator new(stAllocateBlock: 0x4D0u);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseTrigger::CBaseTrigger(this: v2);
    v3[288] = 0;
    v3[291] = -1;
    v3[292] = 0;
    *v3 = &CTriggerLook::`vftable';
    v3[294] = -1;
    v3[301] = -1;
    v3[302] = 0;
    v3[305] = -1;
    v3[306] = 0;
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CTriggerLook *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102492F0
// Name: class CTriggerHierarchy __near * _CreateEntityTemplate<class CTriggerHierarchy>(class CTriggerHierarchy __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CTriggerHierarchy *__cdecl _CreateEntityTemplate<CTriggerHierarchy>(CTriggerHierarchy *newEnt, const char *className)
{
  CBaseTrigger *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseTrigger *)CBaseEntity::operator new(stAllocateBlock: 0x4A0u);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseTrigger::CBaseTrigger(this: v2);
    v3[288] = 0;
    v3[291] = -1;
    v3[292] = 0;
    *v3 = &CTriggerHierarchy::`vftable';
    v3[295] = -1;
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CTriggerHierarchy *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10249360
// Name: class CTriggerImpact __near * _CreateEntityTemplate<class CTriggerImpact>(class CTriggerImpact __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CTriggerImpact *__cdecl _CreateEntityTemplate<CTriggerImpact>(CTriggerImpact *newEnt, const char *className)
{
  CBaseTrigger *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseTrigger *)CBaseEntity::operator new(stAllocateBlock: 0x4BCu);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseTrigger::CBaseTrigger(this: v2);
    v3[288] = 0;
    v3[291] = -1;
    v3[292] = 0;
    *v3 = &CTriggerImpact::`vftable';
    v3[297] = 0;
    v3[300] = -1;
    v3[301] = 0;
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CTriggerImpact *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102498F0
// Name: struct datamap_t __near * DataMapInit<class CChangeLevel>(class CChangeLevel __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CChangeLevel>()
{
  if ( (_S8_13 & 1) == 0 )
  {
    _S8_13 |= 1u;
    nameHolder_450.m_pszBase = "CChangeLevel";
    nameHolder_450.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_450.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_450.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_450.m_Names.m_Size = 0;
    nameHolder_450.m_Names.m_pElements = nullptr;
    nameHolder_450.m_nLenBase = 12;
    atexit(func: DataMapInit_CChangeLevel__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CChangeLevel::m_DataMap.baseMap = &CBaseTrigger::m_DataMap;
  if ( (_S8_13 & 2) == 0 )
  {
    _S8_13 |= 2u;
    dataDesc_422[3].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_450,
                                  pszIdentifier: "TouchChangeLevel");
    *(_QWORD *)&dataDesc_422[3].td = 0;
    *(_QWORD *)&dataDesc_422[3].override_field = 0;
    *(_QWORD *)&dataDesc_422[3].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_422[3].flatOffset[1] = 0;
    dataDesc_422[3].fieldSize = 1;
    dataDesc_422[4].fieldSize = 1;
    *(_QWORD *)&dataDesc_422[4].td = 0;
    *(_QWORD *)&dataDesc_422[4].override_field = 0;
    *(_QWORD *)&dataDesc_422[4].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_422[4].flatOffset[1] = 0;
    dataDesc_422[3].fieldOffset = 0;
    dataDesc_422[3].flags = 32;
    dataDesc_422[3].externalName = nullptr;
    dataDesc_422[3].pSaveRestoreOps = nullptr;
    dataDesc_422[3].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CChangeLevel::TouchChangeLevel;
    dataDesc_422[4].fieldType = FIELD_VOID;
    dataDesc_422[4].fieldName = "InputChangeLevel";
    dataDesc_422[4].fieldOffset = 0;
    dataDesc_422[4].flags = 8;
    dataDesc_422[4].externalName = "ChangeLevel";
    dataDesc_422[4].pSaveRestoreOps = nullptr;
    dataDesc_422[4].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CChangeLevel::InputChangeLevel;
    dataDesc_422[5].fieldType = FIELD_CUSTOM;
    dataDesc_422[5].fieldName = "m_OnChangeLevel";
    dataDesc_422[5].fieldOffset = 1220;
    *(_DWORD *)&dataDesc_422[5].fieldSize = 1441793;
    dataDesc_422[5].externalName = "OnChangeLevel";
    dataDesc_422[5].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_422[5].inputFunc = 0;
    *(_QWORD *)&dataDesc_422[5].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_422[5].override_count = 0;
    *(_QWORD *)dataDesc_422[5].flatOffset = 0;
    *(_DWORD *)&dataDesc_422[5].flatGroup = 0;
  }
  CChangeLevel::m_DataMap.dataNumFields = 5;
  CChangeLevel::m_DataMap.dataDesc = &dataDesc_422[1];
  return &CChangeLevel::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10255030
// Name: struct datamap_t __near * DataMapInit<class CFourWheelServerVehicle>(class CFourWheelServerVehicle __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CFourWheelServerVehicle>()
{
  if ( (_S2_230 & 1) == 0 )
  {
    _S2_230 |= 1u;
    nameHolder_453.m_pszBase = "CFourWheelServerVehicle";
    nameHolder_453.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_453.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_453.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_453.m_Names.m_Size = 0;
    nameHolder_453.m_Names.m_pElements = nullptr;
    nameHolder_453.m_nLenBase = 23;
    atexit(func: DataMapInit_CFourWheelServerVehicle__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CFourWheelServerVehicle::m_DataMap.baseMap = &CBaseServerVehicle::m_DataMap;
  CFourWheelServerVehicle::m_DataMap.dataNumFields = 1;
  CFourWheelServerVehicle::m_DataMap.dataDesc = &dataDesc_424[1];
  return &CFourWheelServerVehicle::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x102550A0
// Name: struct datamap_t __near * DataMapInit<class CPropVehicle>(class CPropVehicle __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CPropVehicle>()
{
  if ( (_S3_138 & 1) == 0 )
  {
    _S3_138 |= 1u;
    nameHolder_454.m_pszBase = "CPropVehicle";
    nameHolder_454.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_454.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_454.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_454.m_Names.m_Size = 0;
    nameHolder_454.m_Names.m_pElements = nullptr;
    nameHolder_454.m_nLenBase = 12;
    atexit(func: DataMapInit_CPropVehicle__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CPropVehicle::m_DataMap.baseMap = &CBaseAnimating::m_DataMap;
  if ( (_S3_138 & 2) == 0 )
  {
    _S3_138 |= 2u;
    dataDesc_425[2].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSVEHICLECONTROLLER);
    dataDesc_425[2].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_425[2].td = 0;
    *(_QWORD *)&dataDesc_425[2].override_field = 0;
    *(_QWORD *)&dataDesc_425[2].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_425[2].flatOffset[1] = 0;
    dataDesc_425[3].fieldType = FIELD_CUSTOM;
    dataDesc_425[3].fieldName = "m_VehiclePhysics.m_pWheels";
    dataDesc_425[3].fieldOffset = 1248;
    dataDesc_425[3].fieldSize = 4;
    dataDesc_425[3].flags = 2;
    dataDesc_425[3].externalName = nullptr;
    dataDesc_425[3].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSOBJECT);
    dataDesc_425[4].fieldSize = 1;
    dataDesc_425[4].flags = 2;
    dataDesc_425[5].fieldSize = 1;
    *(_QWORD *)&dataDesc_425[3].td = 0;
    *(_QWORD *)&dataDesc_425[3].override_field = 0;
    *(_QWORD *)&dataDesc_425[3].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_425[3].flatOffset[1] = 0;
    *(_QWORD *)dataDesc_425[4].flatOffset = 0;
    dataDesc_425[3].inputFunc = nullptr;
    dataDesc_425[4].fieldType = FIELD_INTEGER;
    dataDesc_425[4].fieldName = "m_nVehicleType";
    dataDesc_425[4].fieldOffset = 1480;
    dataDesc_425[4].externalName = nullptr;
    dataDesc_425[4].pSaveRestoreOps = nullptr;
    dataDesc_425[4].inputFunc = nullptr;
    dataDesc_425[4].td = nullptr;
    dataDesc_425[4].fieldSizeInBytes = 4;
    dataDesc_425[4].override_field = nullptr;
    dataDesc_425[4].override_count = 0;
    dataDesc_425[4].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_425[4].flatGroup = 0;
    dataDesc_425[5].fieldType = FIELD_EHANDLE;
    dataDesc_425[5].fieldName = "m_hPhysicsAttacker";
    dataDesc_425[5].fieldOffset = 1500;
    dataDesc_425[5].flags = 2;
    dataDesc_425[5].externalName = nullptr;
    dataDesc_425[5].pSaveRestoreOps = nullptr;
    dataDesc_425[5].inputFunc = nullptr;
    dataDesc_425[5].td = nullptr;
    dataDesc_425[5].fieldSizeInBytes = 4;
    dataDesc_425[5].override_field = nullptr;
    dataDesc_425[5].override_count = 0;
    dataDesc_425[5].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_425[5].flatOffset = 0;
    *(_DWORD *)&dataDesc_425[5].flatGroup = 0;
    dataDesc_425[6].fieldType = FIELD_TIME;
    dataDesc_425[6].fieldName = "m_flLastPhysicsInfluenceTime";
    dataDesc_425[6].fieldOffset = 1504;
    dataDesc_425[6].fieldSize = 1;
    dataDesc_425[6].flags = 2;
    dataDesc_425[6].externalName = nullptr;
    dataDesc_425[6].pSaveRestoreOps = nullptr;
    dataDesc_425[6].inputFunc = nullptr;
    dataDesc_425[6].td = nullptr;
    dataDesc_425[6].fieldSizeInBytes = 4;
    dataDesc_425[6].override_field = nullptr;
    dataDesc_425[6].override_count = 0;
    dataDesc_425[7].fieldType = FIELD_STRING;
    dataDesc_425[7].fieldSize = 1;
    dataDesc_425[6].fieldTolerance = 0.0;
    dataDesc_425[7].fieldTolerance = 0.0;
    dataDesc_425[8].fieldTolerance = 0.0;
    dataDesc_425[7].flags = 6;
    dataDesc_425[8].fieldSize = 1;
    dataDesc_425[8].flags = 2;
    *(_QWORD *)dataDesc_425[8].flatOffset = 0;
    dataDesc_425[9].fieldSize = 1;
    *(_QWORD *)&dataDesc_425[9].td = 0;
    *(_QWORD *)&dataDesc_425[9].override_field = 0;
    *(_QWORD *)&dataDesc_425[9].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_425[9].flatOffset[1] = 0;
    dataDesc_425[9].flags = 8;
    dataDesc_425[10].fieldSize = 1;
    *(_QWORD *)dataDesc_425[6].flatOffset = 0;
    *(_QWORD *)&dataDesc_425[10].td = 0;
    *(_QWORD *)&dataDesc_425[10].override_field = 0;
    *(_QWORD *)&dataDesc_425[10].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_425[10].flatOffset[1] = 0;
    *(_DWORD *)&dataDesc_425[6].flatGroup = 0;
    dataDesc_425[7].fieldName = "m_vehicleScript";
    dataDesc_425[7].fieldOffset = 1484;
    dataDesc_425[7].externalName = "VehicleScript";
    dataDesc_425[7].pSaveRestoreOps = nullptr;
    dataDesc_425[7].inputFunc = nullptr;
    dataDesc_425[7].td = nullptr;
    dataDesc_425[7].fieldSizeInBytes = 4;
    dataDesc_425[7].override_field = nullptr;
    dataDesc_425[7].override_count = 0;
    *(_QWORD *)dataDesc_425[7].flatOffset = 0;
    *(_DWORD *)&dataDesc_425[7].flatGroup = 0;
    dataDesc_425[8].fieldType = FIELD_VECTOR;
    dataDesc_425[8].fieldName = "m_vecSmoothedVelocity";
    dataDesc_425[8].fieldOffset = 1488;
    dataDesc_425[8].externalName = nullptr;
    dataDesc_425[8].pSaveRestoreOps = nullptr;
    dataDesc_425[8].inputFunc = nullptr;
    dataDesc_425[8].td = nullptr;
    dataDesc_425[8].fieldSizeInBytes = 12;
    dataDesc_425[8].override_field = nullptr;
    dataDesc_425[8].override_count = 0;
    *(_DWORD *)&dataDesc_425[8].flatGroup = 0;
    dataDesc_425[9].fieldType = FIELD_FLOAT;
    dataDesc_425[9].fieldName = "InputThrottle";
    dataDesc_425[9].fieldOffset = 0;
    dataDesc_425[9].externalName = "Throttle";
    dataDesc_425[9].pSaveRestoreOps = nullptr;
    dataDesc_425[9].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPropVehicle::InputThrottle;
    dataDesc_425[10].fieldType = FIELD_FLOAT;
    dataDesc_425[10].fieldName = "InputSteering";
    dataDesc_425[10].fieldOffset = 0;
    dataDesc_425[10].flags = 8;
    dataDesc_425[10].externalName = "Steer";
    dataDesc_425[10].pSaveRestoreOps = nullptr;
    dataDesc_425[10].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPropVehicle::InputSteering;
    dataDesc_425[11].fieldType = FIELD_FLOAT;
    dataDesc_425[11].fieldName = "InputAction";
    dataDesc_425[11].fieldOffset = 0;
    dataDesc_425[11].fieldSize = 1;
    dataDesc_425[11].flags = 8;
    dataDesc_425[11].externalName = "Action";
    dataDesc_425[11].pSaveRestoreOps = nullptr;
    dataDesc_425[11].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPropVehicle::InputAction;
    *(_QWORD *)&dataDesc_425[11].td = 0;
    *(_QWORD *)&dataDesc_425[11].override_field = 0;
    *(_QWORD *)&dataDesc_425[11].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_425[11].flatOffset[1] = 0;
    *(_QWORD *)&dataDesc_425[12].td = 0;
    *(_QWORD *)&dataDesc_425[12].override_field = 0;
    *(_QWORD *)&dataDesc_425[12].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_425[12].flatOffset[1] = 0;
    dataDesc_425[12].fieldType = FIELD_VOID;
    dataDesc_425[12].fieldName = "InputHandBrakeOn";
    dataDesc_425[12].fieldOffset = 0;
    dataDesc_425[12].fieldSize = 1;
    dataDesc_425[12].flags = 8;
    dataDesc_425[12].externalName = "HandBrakeOn";
    dataDesc_425[12].pSaveRestoreOps = nullptr;
    dataDesc_425[12].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPropVehicle::InputHandBrakeOn;
    dataDesc_425[13].fieldType = FIELD_VOID;
    dataDesc_425[13].fieldName = "InputHandBrakeOff";
    dataDesc_425[13].fieldOffset = 0;
    *(_DWORD *)&dataDesc_425[13].fieldSize = 524289;
    dataDesc_425[13].externalName = "HandBrakeOff";
    dataDesc_425[13].pSaveRestoreOps = nullptr;
    dataDesc_425[13].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CPropVehicle::InputHandBrakeOff;
    *(_QWORD *)&dataDesc_425[13].td = 0;
    *(_QWORD *)&dataDesc_425[13].override_field = 0;
    *(_QWORD *)&dataDesc_425[13].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_425[13].flatOffset[1] = 0;
  }
  CPropVehicle::m_DataMap.dataNumFields = 13;
  CPropVehicle::m_DataMap.dataDesc = &dataDesc_425[1];
  return &CPropVehicle::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10255630
// Name: struct datamap_t __near * DataMapInit<class CPropVehicleDriveable>(class CPropVehicleDriveable __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CPropVehicleDriveable>()
{
  if ( (_S5_35 & 1) == 0 )
  {
    _S5_35 |= 1u;
    nameHolder_455.m_pszBase = "CPropVehicleDriveable";
    nameHolder_455.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_455.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_455.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_455.m_Names.m_Size = 0;
    nameHolder_455.m_Names.m_pElements = nullptr;
    nameHolder_455.m_nLenBase = 21;
    atexit(func: DataMapInit_CPropVehicleDriveable__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CPropVehicleDriveable::m_DataMap.baseMap = &CPropVehicle::m_DataMap;
  if ( (_S5_35 & 2) == 0 )
  {
    _S5_35 |= 2u;
    dataDesc_426[7].fieldSize = 1;
    dataDesc_426[7].flags = 22;
    dataDesc_426[8].fieldSize = 1;
    dataDesc_426[8].flags = 22;
    *(_QWORD *)&dataDesc_426[6].inputFunc = 0;
    *(_QWORD *)&dataDesc_426[6].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_426[6].override_count = 0;
    *(_QWORD *)dataDesc_426[6].flatOffset = 0;
    *(_QWORD *)&dataDesc_426[7].inputFunc = 0;
    *(_QWORD *)&dataDesc_426[7].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_426[7].override_count = 0;
    *(_QWORD *)dataDesc_426[7].flatOffset = 0;
    dataDesc_426[9].fieldSize = 1;
    *(_QWORD *)&dataDesc_426[8].inputFunc = 0;
    *(_QWORD *)&dataDesc_426[8].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_426[8].override_count = 0;
    *(_QWORD *)dataDesc_426[8].flatOffset = 0;
    dataDesc_426[9].flags = 22;
    *(_QWORD *)&dataDesc_426[9].inputFunc = 0;
    *(_QWORD *)&dataDesc_426[9].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_426[9].override_count = 0;
    *(_QWORD *)dataDesc_426[9].flatOffset = 0;
    dataDesc_426[7].fieldType = FIELD_CUSTOM;
    dataDesc_426[8].fieldType = FIELD_CUSTOM;
    dataDesc_426[9].fieldType = FIELD_CUSTOM;
    dataDesc_426[10].fieldType = FIELD_CUSTOM;
    dataDesc_426[10].fieldSize = 1;
    dataDesc_426[11].fieldType = FIELD_CUSTOM;
    *(_QWORD *)&dataDesc_426[10].inputFunc = 0;
    *(_QWORD *)&dataDesc_426[10].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_426[10].override_count = 0;
    *(_QWORD *)dataDesc_426[10].flatOffset = 0;
    dataDesc_426[6].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_426[6].flatGroup = 0;
    dataDesc_426[7].fieldName = "m_playerOff";
    dataDesc_426[7].fieldOffset = 1544;
    dataDesc_426[7].externalName = "PlayerOff";
    dataDesc_426[7].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_426[7].flatGroup = 0;
    dataDesc_426[8].fieldName = "m_pressedAttack";
    dataDesc_426[8].fieldOffset = 1568;
    dataDesc_426[8].externalName = "PressedAttack";
    dataDesc_426[8].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_426[8].flatGroup = 0;
    dataDesc_426[9].fieldName = "m_pressedAttack2";
    dataDesc_426[9].fieldOffset = 1592;
    dataDesc_426[9].externalName = "PressedAttack2";
    dataDesc_426[9].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_426[9].flatGroup = 0;
    dataDesc_426[10].fieldName = "m_attackaxis";
    dataDesc_426[10].fieldOffset = 1616;
    dataDesc_426[10].flags = 22;
    dataDesc_426[10].externalName = "AttackAxis";
    dataDesc_426[10].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_426[10].flatGroup = 0;
    dataDesc_426[11].fieldName = "m_attack2axis";
    dataDesc_426[11].fieldOffset = 1640;
    dataDesc_426[11].fieldSize = 1;
    dataDesc_426[11].flags = 22;
    dataDesc_426[11].externalName = "Attack2Axis";
    dataDesc_426[11].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_426[11].inputFunc = 0;
    dataDesc_426[12].flags = 2;
    dataDesc_426[14].fieldSize = 1;
    *(_QWORD *)dataDesc_426[12].flatOffset = 0;
    dataDesc_426[13].fieldSize = 1;
    dataDesc_426[14].flags = 2;
    *(_QWORD *)dataDesc_426[13].flatOffset = 0;
    dataDesc_426[12].fieldSize = 1;
    dataDesc_426[13].flags = 66;
    dataDesc_426[15].fieldSize = 1;
    *(_QWORD *)&dataDesc_426[11].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_426[11].override_count = 0;
    *(_QWORD *)dataDesc_426[11].flatOffset = 0;
    *(_QWORD *)dataDesc_426[14].flatOffset = 0;
    *(_DWORD *)&dataDesc_426[11].flatGroup = 0;
    dataDesc_426[12].fieldType = FIELD_EHANDLE;
    dataDesc_426[12].fieldName = "m_hPlayer";
    dataDesc_426[12].fieldOffset = 1664;
    dataDesc_426[12].externalName = nullptr;
    dataDesc_426[12].pSaveRestoreOps = nullptr;
    dataDesc_426[12].inputFunc = nullptr;
    dataDesc_426[12].td = nullptr;
    dataDesc_426[12].fieldSizeInBytes = 4;
    dataDesc_426[12].override_field = nullptr;
    dataDesc_426[12].override_count = 0;
    dataDesc_426[12].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_426[12].flatGroup = 0;
    dataDesc_426[13].fieldType = FIELD_EMBEDDED;
    dataDesc_426[13].fieldName = "m_pServerVehicle";
    dataDesc_426[13].fieldOffset = 1516;
    dataDesc_426[13].externalName = nullptr;
    dataDesc_426[13].pSaveRestoreOps = nullptr;
    dataDesc_426[13].inputFunc = nullptr;
    dataDesc_426[13].td = &CFourWheelServerVehicle::m_DataMap;
    dataDesc_426[13].fieldSizeInBytes = 536;
    dataDesc_426[13].override_field = nullptr;
    dataDesc_426[13].override_count = 0;
    dataDesc_426[13].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_426[13].flatGroup = 0;
    dataDesc_426[14].fieldType = FIELD_INTEGER;
    dataDesc_426[14].fieldName = "m_nSpeed";
    dataDesc_426[14].fieldOffset = 1668;
    dataDesc_426[14].externalName = nullptr;
    dataDesc_426[14].pSaveRestoreOps = nullptr;
    dataDesc_426[14].inputFunc = nullptr;
    dataDesc_426[14].td = nullptr;
    dataDesc_426[14].fieldSizeInBytes = 4;
    dataDesc_426[14].override_field = nullptr;
    dataDesc_426[14].override_count = 0;
    dataDesc_426[14].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_426[14].flatGroup = 0;
    dataDesc_426[15].fieldType = FIELD_INTEGER;
    dataDesc_426[15].fieldName = "m_nRPM";
    dataDesc_426[15].fieldOffset = 1672;
    dataDesc_426[15].flags = 2;
    dataDesc_426[15].externalName = nullptr;
    dataDesc_426[15].pSaveRestoreOps = nullptr;
    dataDesc_426[15].inputFunc = nullptr;
    dataDesc_426[15].td = nullptr;
    dataDesc_426[15].fieldSizeInBytes = 4;
    dataDesc_426[15].override_field = nullptr;
    dataDesc_426[15].override_count = 0;
    dataDesc_426[15].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_426[15].flatOffset = 0;
    *(_DWORD *)&dataDesc_426[15].flatGroup = 0;
    dataDesc_426[16].fieldType = FIELD_FLOAT;
    dataDesc_426[16].fieldSize = 1;
    dataDesc_426[16].flags = 2;
    dataDesc_426[17].fieldType = FIELD_INTEGER;
    dataDesc_426[17].fieldSize = 1;
    dataDesc_426[18].fieldType = FIELD_INTEGER;
    dataDesc_426[17].flags = 2;
    dataDesc_426[18].fieldSize = 1;
    dataDesc_426[19].fieldSize = 1;
    *(_QWORD *)dataDesc_426[16].flatOffset = 0;
    dataDesc_426[19].flags = 2;
    *(_QWORD *)dataDesc_426[17].flatOffset = 0;
    dataDesc_426[18].flags = 2;
    dataDesc_426[20].fieldSize = 1;
    *(_QWORD *)dataDesc_426[18].flatOffset = 0;
    dataDesc_426[16].fieldName = "m_flThrottle";
    dataDesc_426[16].fieldOffset = 1676;
    dataDesc_426[16].externalName = nullptr;
    dataDesc_426[16].pSaveRestoreOps = nullptr;
    dataDesc_426[16].inputFunc = nullptr;
    dataDesc_426[16].td = nullptr;
    dataDesc_426[16].fieldSizeInBytes = 4;
    dataDesc_426[16].override_field = nullptr;
    dataDesc_426[16].override_count = 0;
    dataDesc_426[16].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_426[16].flatGroup = 0;
    dataDesc_426[17].fieldName = "m_nBoostTimeLeft";
    dataDesc_426[17].fieldOffset = 1680;
    dataDesc_426[17].externalName = nullptr;
    dataDesc_426[17].pSaveRestoreOps = nullptr;
    dataDesc_426[17].inputFunc = nullptr;
    dataDesc_426[17].td = nullptr;
    dataDesc_426[17].fieldSizeInBytes = 4;
    dataDesc_426[17].override_field = nullptr;
    dataDesc_426[17].override_count = 0;
    dataDesc_426[17].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_426[17].flatGroup = 0;
    dataDesc_426[18].fieldName = "m_nHasBoost";
    dataDesc_426[18].fieldOffset = 1684;
    dataDesc_426[18].externalName = nullptr;
    dataDesc_426[18].pSaveRestoreOps = nullptr;
    dataDesc_426[18].inputFunc = nullptr;
    dataDesc_426[18].td = nullptr;
    dataDesc_426[18].fieldSizeInBytes = 4;
    dataDesc_426[18].override_field = nullptr;
    dataDesc_426[18].override_count = 0;
    dataDesc_426[18].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_426[18].flatGroup = 0;
    dataDesc_426[19].fieldType = FIELD_BOOLEAN;
    dataDesc_426[19].fieldName = "m_nScannerDisabledWeapons";
    dataDesc_426[19].fieldOffset = 1714;
    dataDesc_426[19].externalName = nullptr;
    dataDesc_426[19].pSaveRestoreOps = nullptr;
    dataDesc_426[19].inputFunc = nullptr;
    dataDesc_426[19].td = nullptr;
    dataDesc_426[19].fieldSizeInBytes = 1;
    dataDesc_426[19].override_field = nullptr;
    dataDesc_426[19].override_count = 0;
    dataDesc_426[19].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_426[19].flatOffset = 0;
    *(_DWORD *)&dataDesc_426[19].flatGroup = 0;
    dataDesc_426[20].fieldType = FIELD_BOOLEAN;
    dataDesc_426[20].fieldName = "m_nScannerDisabledVehicle";
    dataDesc_426[20].fieldOffset = 1715;
    dataDesc_426[20].flags = 2;
    dataDesc_426[20].externalName = nullptr;
    dataDesc_426[20].pSaveRestoreOps = nullptr;
    dataDesc_426[21].fieldSize = 1;
    dataDesc_426[21].flags = 2;
    dataDesc_426[22].fieldSize = 1;
    dataDesc_426[22].flags = 2;
    *(_QWORD *)dataDesc_426[20].flatOffset = 0;
    dataDesc_426[23].fieldSize = 1;
    *(_QWORD *)dataDesc_426[21].flatOffset = 0;
    dataDesc_426[23].flags = 2;
    *(_QWORD *)dataDesc_426[22].flatOffset = 0;
    dataDesc_426[24].fieldSize = 1;
    *(_QWORD *)dataDesc_426[23].flatOffset = 0;
    dataDesc_426[20].inputFunc = nullptr;
    dataDesc_426[20].td = nullptr;
    dataDesc_426[20].fieldSizeInBytes = 1;
    dataDesc_426[20].override_field = nullptr;
    dataDesc_426[20].override_count = 0;
    dataDesc_426[20].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_426[20].flatGroup = 0;
    dataDesc_426[21].fieldType = FIELD_BOOLEAN;
    dataDesc_426[21].fieldName = "m_bUnableToFire";
    dataDesc_426[21].fieldOffset = 1712;
    dataDesc_426[21].externalName = nullptr;
    dataDesc_426[21].pSaveRestoreOps = nullptr;
    dataDesc_426[21].inputFunc = nullptr;
    dataDesc_426[21].td = nullptr;
    dataDesc_426[21].fieldSizeInBytes = 1;
    dataDesc_426[21].override_field = nullptr;
    dataDesc_426[21].override_count = 0;
    dataDesc_426[21].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_426[21].flatGroup = 0;
    dataDesc_426[22].fieldType = FIELD_POSITION_VECTOR;
    dataDesc_426[22].fieldName = "m_vecEyeExitEndpoint";
    dataDesc_426[22].fieldOffset = 1688;
    dataDesc_426[22].externalName = nullptr;
    dataDesc_426[22].pSaveRestoreOps = nullptr;
    dataDesc_426[22].inputFunc = nullptr;
    dataDesc_426[22].td = nullptr;
    dataDesc_426[22].fieldSizeInBytes = 12;
    dataDesc_426[22].override_field = nullptr;
    dataDesc_426[22].override_count = 0;
    dataDesc_426[22].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_426[22].flatGroup = 0;
    dataDesc_426[23].fieldType = FIELD_VECTOR;
    dataDesc_426[23].fieldName = "m_vecGunCrosshair";
    dataDesc_426[23].fieldOffset = 1700;
    dataDesc_426[23].externalName = nullptr;
    dataDesc_426[23].pSaveRestoreOps = nullptr;
    dataDesc_426[23].inputFunc = nullptr;
    dataDesc_426[23].td = nullptr;
    dataDesc_426[23].fieldSizeInBytes = 12;
    dataDesc_426[23].override_field = nullptr;
    dataDesc_426[23].override_count = 0;
    dataDesc_426[23].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_426[23].flatGroup = 0;
    dataDesc_426[24].fieldType = FIELD_BOOLEAN;
    dataDesc_426[24].fieldName = "m_bEngineLocked";
    dataDesc_426[24].fieldOffset = 1724;
    dataDesc_426[24].flags = 2;
    dataDesc_426[24].externalName = nullptr;
    dataDesc_426[24].pSaveRestoreOps = nullptr;
    dataDesc_426[24].inputFunc = nullptr;
    dataDesc_426[24].td = nullptr;
    dataDesc_426[24].fieldSizeInBytes = 1;
    dataDesc_426[24].override_field = nullptr;
    dataDesc_426[24].override_count = 0;
    dataDesc_426[24].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_426[24].flatOffset = 0;
    *(_DWORD *)&dataDesc_426[24].flatGroup = 0;
    dataDesc_426[25].fieldSize = 1;
    dataDesc_426[25].flags = 6;
    dataDesc_426[26].fieldSize = 1;
    dataDesc_426[25].fieldType = FIELD_BOOLEAN;
    dataDesc_426[26].flags = 2;
    dataDesc_426[27].fieldType = FIELD_BOOLEAN;
    dataDesc_426[28].fieldType = FIELD_BOOLEAN;
    dataDesc_426[27].fieldSize = 1;
    dataDesc_426[28].fieldSize = 1;
    *(_QWORD *)dataDesc_426[25].flatOffset = 0;
    dataDesc_426[28].flags = 2;
    *(_QWORD *)dataDesc_426[26].flatOffset = 0;
    dataDesc_426[29].fieldSize = 1;
    *(_QWORD *)dataDesc_426[27].flatOffset = 0;
    dataDesc_426[25].fieldName = "m_bLocked";
    dataDesc_426[25].fieldOffset = 1725;
    dataDesc_426[25].externalName = "VehicleLocked";
    dataDesc_426[25].pSaveRestoreOps = nullptr;
    dataDesc_426[25].inputFunc = nullptr;
    dataDesc_426[25].td = nullptr;
    dataDesc_426[25].fieldSizeInBytes = 1;
    dataDesc_426[25].override_field = nullptr;
    dataDesc_426[25].override_count = 0;
    dataDesc_426[25].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_426[25].flatGroup = 0;
    dataDesc_426[26].fieldType = FIELD_FLOAT;
    dataDesc_426[26].fieldName = "m_flMinimumSpeedToEnterExit";
    dataDesc_426[26].fieldOffset = 1728;
    dataDesc_426[26].externalName = nullptr;
    dataDesc_426[26].pSaveRestoreOps = nullptr;
    dataDesc_426[26].inputFunc = nullptr;
    dataDesc_426[26].td = nullptr;
    dataDesc_426[26].fieldSizeInBytes = 4;
    dataDesc_426[26].override_field = nullptr;
    dataDesc_426[26].override_count = 0;
    dataDesc_426[26].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_426[26].flatGroup = 0;
    dataDesc_426[27].fieldName = "m_bEnterAnimOn";
    dataDesc_426[27].fieldOffset = 1732;
    dataDesc_426[27].flags = 2;
    dataDesc_426[27].externalName = nullptr;
    dataDesc_426[27].pSaveRestoreOps = nullptr;
    dataDesc_426[27].inputFunc = nullptr;
    dataDesc_426[27].td = nullptr;
    dataDesc_426[27].fieldSizeInBytes = 1;
    dataDesc_426[27].override_field = nullptr;
    dataDesc_426[27].override_count = 0;
    dataDesc_426[27].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_426[27].flatGroup = 0;
    dataDesc_426[28].fieldName = "m_bExitAnimOn";
    dataDesc_426[28].fieldOffset = 1733;
    dataDesc_426[28].externalName = nullptr;
    dataDesc_426[28].pSaveRestoreOps = nullptr;
    dataDesc_426[28].inputFunc = nullptr;
    dataDesc_426[28].td = nullptr;
    dataDesc_426[28].fieldSizeInBytes = 1;
    dataDesc_426[28].override_field = nullptr;
    dataDesc_426[28].override_count = 0;
    dataDesc_426[28].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_426[28].flatOffset = 0;
    *(_DWORD *)&dataDesc_426[28].flatGroup = 0;
    dataDesc_426[29].fieldType = FIELD_TIME;
    dataDesc_426[29].fieldName = "m_flTurnOffKeepUpright";
    dataDesc_426[29].fieldOffset = 1736;
    dataDesc_426[29].flags = 2;
    dataDesc_426[29].externalName = nullptr;
    dataDesc_426[29].pSaveRestoreOps = nullptr;
    dataDesc_426[30].fieldSize = 1;
    dataDesc_426[29].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_426[29].flatOffset = 0;
    dataDesc_426[30].fieldTolerance = 0.0;
    dataDesc_426[31].fieldTolerance = 0.0;
    dataDesc_426[29].inputFunc = nullptr;
    dataDesc_426[29].td = nullptr;
    dataDesc_426[29].fieldSizeInBytes = 4;
    dataDesc_426[29].override_field = nullptr;
    dataDesc_426[29].override_count = 0;
    *(_DWORD *)&dataDesc_426[29].flatGroup = 0;
    dataDesc_426[30].fieldType = FIELD_EHANDLE;
    dataDesc_426[30].fieldName = "m_hNPCDriver";
    dataDesc_426[30].fieldOffset = 1716;
    dataDesc_426[30].flags = 2;
    dataDesc_426[30].externalName = nullptr;
    dataDesc_426[30].pSaveRestoreOps = nullptr;
    dataDesc_426[30].inputFunc = nullptr;
    dataDesc_426[30].td = nullptr;
    dataDesc_426[30].fieldSizeInBytes = 4;
    dataDesc_426[30].override_field = nullptr;
    dataDesc_426[30].override_count = 0;
    *(_QWORD *)dataDesc_426[30].flatOffset = 0;
    *(_DWORD *)&dataDesc_426[30].flatGroup = 0;
    dataDesc_426[31].fieldType = FIELD_EHANDLE;
    dataDesc_426[31].fieldName = "m_hKeepUpright";
    dataDesc_426[31].fieldOffset = 1720;
    *(_DWORD *)&dataDesc_426[31].fieldSize = 131073;
    dataDesc_426[31].externalName = nullptr;
    dataDesc_426[31].pSaveRestoreOps = nullptr;
    dataDesc_426[31].inputFunc = nullptr;
    dataDesc_426[31].td = nullptr;
    dataDesc_426[31].fieldSizeInBytes = 4;
    dataDesc_426[31].override_field = nullptr;
    dataDesc_426[31].override_count = 0;
    *(_QWORD *)dataDesc_426[31].flatOffset = 0;
    *(_DWORD *)&dataDesc_426[31].flatGroup = 0;
  }
  CPropVehicleDriveable::m_DataMap.dataNumFields = 31;
  CPropVehicleDriveable::m_DataMap.dataDesc = &dataDesc_426[1];
  return &CPropVehicleDriveable::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1025CE30
// Name: struct datamap_t __near * DataMapInit<class CVGuiScreen>(class CVGuiScreen __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CVGuiScreen>()
{
  if ( (_S3_140 & 1) == 0 )
  {
    _S3_140 |= 1u;
    nameHolder_462.m_pszBase = "CVGuiScreen";
    nameHolder_462.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_462.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_462.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_462.m_Names.m_Size = 0;
    nameHolder_462.m_Names.m_pElements = nullptr;
    nameHolder_462.m_nLenBase = 11;
    atexit(func: DataMapInit_CVGuiScreen__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CVGuiScreen::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CVGuiScreen::m_DataMap.dataNumFields = 10;
  CVGuiScreen::m_DataMap.dataDesc = &dataDesc_433[1];
  return &CVGuiScreen::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10263860
// Name: struct datamap_t __near * DataMapInit<class CWaterBullet>(class CWaterBullet __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CWaterBullet>()
{
  if ( (_S2_235 & 1) == 0 )
  {
    _S2_235 |= 1u;
    nameHolder_463.m_pszBase = "CWaterBullet";
    nameHolder_463.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_463.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_463.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_463.m_Names.m_Size = 0;
    nameHolder_463.m_Names.m_pElements = nullptr;
    nameHolder_463.m_nLenBase = 12;
    atexit(func: DataMapInit_CWaterBullet__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CWaterBullet::m_DataMap.baseMap = &CBaseAnimating::m_DataMap;
  if ( (_S2_235 & 2) == 0 )
  {
    _S2_235 |= 2u;
    dataDesc_496[1].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_463,
                                  pszIdentifier: "Touch");
    dataDesc_496[1].fieldOffset = 0;
    *(_DWORD *)&dataDesc_496[1].fieldSize = 2097153;
    dataDesc_496[1].externalName = nullptr;
    dataDesc_496[1].pSaveRestoreOps = nullptr;
    dataDesc_496[1].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *)) __thiscall CWaterBullet::`vcall'{404,{flat}};
    *(_QWORD *)&dataDesc_496[1].td = 0;
    *(_QWORD *)&dataDesc_496[1].override_field = 0;
    *(_QWORD *)&dataDesc_496[1].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_496[1].flatOffset[1] = 0;
    dataDesc_496[2].fieldType = FIELD_VOID;
    dataDesc_496[2].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_463,
                                  pszIdentifier: "BulletThink");
    dataDesc_496[2].fieldOffset = 0;
    *(_DWORD *)&dataDesc_496[2].fieldSize = 2097153;
    dataDesc_496[2].externalName = nullptr;
    dataDesc_496[2].pSaveRestoreOps = nullptr;
    dataDesc_496[2].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CWaterBullet::BulletThink;
    *(_QWORD *)&dataDesc_496[2].td = 0;
    *(_QWORD *)&dataDesc_496[2].override_field = 0;
    *(_QWORD *)&dataDesc_496[2].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_496[2].flatOffset[1] = 0;
  }
  CWaterBullet::m_DataMap.dataNumFields = 2;
  CWaterBullet::m_DataMap.dataDesc = &dataDesc_496[1];
  return &CWaterBullet::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10263CD0
// Name: struct datamap_t __near * DataMapInit<class CWaterLODControl>(class CWaterLODControl __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CWaterLODControl>()
{
  if ( (_S2_236 & 1) == 0 )
  {
    _S2_236 |= 1u;
    nameHolder_464.m_pszBase = "CWaterLODControl";
    nameHolder_464.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_464.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_464.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_464.m_Names.m_Size = 0;
    nameHolder_464.m_Names.m_pElements = nullptr;
    nameHolder_464.m_nLenBase = 16;
    atexit(func: DataMapInit_CWaterLODControl__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CWaterLODControl::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CWaterLODControl::m_DataMap.dataNumFields = 4;
  CWaterLODControl::m_DataMap.dataDesc = &dataDesc_434[1];
  return &CWaterLODControl::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x102652D0
// Name: struct datamap_t __near * DataMapInit<class CWC_UpdateIgnoreList>(class CWC_UpdateIgnoreList __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CWC_UpdateIgnoreList>()
{
  if ( (_S2_237 & 1) == 0 )
  {
    _S2_237 |= 1u;
    nameHolder_465.m_pszBase = "CWC_UpdateIgnoreList";
    nameHolder_465.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_465.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_465.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_465.m_Names.m_Size = 0;
    nameHolder_465.m_Names.m_pElements = nullptr;
    nameHolder_465.m_nLenBase = 20;
    atexit(func: DataMapInit_CWC_UpdateIgnoreList__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CWC_UpdateIgnoreList::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CWC_UpdateIgnoreList::m_DataMap.dataNumFields = 16;
  CWC_UpdateIgnoreList::m_DataMap.dataDesc = &dataDesc_435[1];
  return &CWC_UpdateIgnoreList::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10266F50
// Name: struct datamap_t __near * DataMapInit<class CWeightButton>(class CWeightButton __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CWeightButton>()
{
  if ( (_S2_238 & 1) == 0 )
  {
    _S2_238 |= 1u;
    nameHolder_466.m_pszBase = "CWeightButton";
    nameHolder_466.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_466.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_466.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_466.m_Names.m_Size = 0;
    nameHolder_466.m_Names.m_pElements = nullptr;
    nameHolder_466.m_nLenBase = 13;
    atexit(func: DataMapInit_CWeightButton__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CWeightButton::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S2_238 & 2) == 0 )
  {
    _S2_238 |= 2u;
    *(_QWORD *)&dataDesc_436[3].inputFunc = 0;
    *(_QWORD *)&dataDesc_436[3].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_436[3].override_count = 0;
    *(_QWORD *)dataDesc_436[3].flatOffset = 0;
    dataDesc_436[4].fieldSize = 1;
    dataDesc_436[3].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_436[3].flatGroup = 0;
    dataDesc_436[4].fieldType = FIELD_CUSTOM;
    dataDesc_436[4].fieldName = "m_OnReleased";
    dataDesc_436[4].fieldOffset = 876;
    dataDesc_436[4].flags = 22;
    dataDesc_436[4].externalName = "OnReleased";
    dataDesc_436[4].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_436[4].inputFunc = 0;
    *(_QWORD *)&dataDesc_436[4].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_436[4].override_count = 0;
    *(_QWORD *)dataDesc_436[4].flatOffset = 0;
    *(_DWORD *)&dataDesc_436[4].flatGroup = 0;
    dataDesc_436[5].fieldType = FIELD_VOID;
    dataDesc_436[5].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_466,
                                  pszIdentifier: "TriggerThink");
    dataDesc_436[5].fieldOffset = 0;
    *(_DWORD *)&dataDesc_436[5].fieldSize = 2097153;
    dataDesc_436[5].externalName = nullptr;
    dataDesc_436[5].pSaveRestoreOps = nullptr;
    dataDesc_436[5].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CWeightButton::TriggerThink;
    *(_QWORD *)&dataDesc_436[5].td = 0;
    *(_QWORD *)&dataDesc_436[5].override_field = 0;
    *(_QWORD *)&dataDesc_436[5].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_436[5].flatOffset[1] = 0;
  }
  CWeightButton::m_DataMap.dataNumFields = 5;
  CWeightButton::m_DataMap.dataDesc = &dataDesc_436[1];
  return &CWeightButton::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x102687F0
// Name: struct datamap_t __near * DataMapInit<class CInfoGameEventProxy>(class CInfoGameEventProxy __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CInfoGameEventProxy>()
{
  if ( (_S2_239 & 1) == 0 )
  {
    _S2_239 |= 1u;
    nameHolder_467.m_pszBase = "CInfoGameEventProxy";
    nameHolder_467.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_467.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_467.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_467.m_Names.m_Size = 0;
    nameHolder_467.m_Names.m_pElements = nullptr;
    nameHolder_467.m_nLenBase = 19;
    atexit(func: DataMapInit_CInfoGameEventProxy__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CInfoGameEventProxy::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CInfoGameEventProxy::m_DataMap.dataNumFields = 6;
  CInfoGameEventProxy::m_DataMap.dataDesc = &dataDesc_437[1];
  return &CInfoGameEventProxy::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10268870
// Name: struct datamap_t __near * DataMapInit<class CDecal>(class CDecal __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CDecal>()
{
  if ( (_S3_143 & 1) == 0 )
  {
    _S3_143 |= 1u;
    nameHolder_468.m_pszBase = "CDecal";
    nameHolder_468.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_468.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_468.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_468.m_Names.m_Size = 0;
    nameHolder_468.m_Names.m_pElements = nullptr;
    nameHolder_468.m_nLenBase = 6;
    atexit(func: DataMapInit_CDecal__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CDecal::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S3_143 & 2) == 0 )
  {
    _S3_143 |= 2u;
    dataDesc_438[4].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_468,
                                  pszIdentifier: "StaticDecal");
    dataDesc_438[4].flags = 32;
    dataDesc_438[4].fieldOffset = 0;
    dataDesc_438[4].fieldSize = 1;
    dataDesc_438[4].externalName = nullptr;
    dataDesc_438[4].pSaveRestoreOps = nullptr;
    dataDesc_438[4].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CDecal::StaticDecal;
    *(_QWORD *)&dataDesc_438[4].td = 0;
    *(_QWORD *)&dataDesc_438[4].override_field = 0;
    *(_QWORD *)&dataDesc_438[4].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_438[4].flatOffset[1] = 0;
    dataDesc_438[5].fieldType = FIELD_VOID;
    dataDesc_438[5].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_468,
                                  pszIdentifier: "TriggerDecal");
    *(_QWORD *)&dataDesc_438[5].td = 0;
    *(_QWORD *)&dataDesc_438[5].override_field = 0;
    *(_QWORD *)&dataDesc_438[5].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_438[5].flatOffset[1] = 0;
    dataDesc_438[5].fieldOffset = 0;
    dataDesc_438[5].fieldSize = 1;
    dataDesc_438[5].flags = 32;
    dataDesc_438[5].externalName = nullptr;
    dataDesc_438[5].pSaveRestoreOps = nullptr;
    dataDesc_438[5].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CDecal::TriggerDecal;
    dataDesc_438[6].fieldType = FIELD_VOID;
    dataDesc_438[6].fieldName = "InputActivate";
    dataDesc_438[6].fieldOffset = 0;
    *(_DWORD *)&dataDesc_438[6].fieldSize = 524289;
    dataDesc_438[6].externalName = "Activate";
    dataDesc_438[6].pSaveRestoreOps = nullptr;
    dataDesc_438[6].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CDecal::InputActivate;
    *(_QWORD *)&dataDesc_438[6].td = 0;
    *(_QWORD *)&dataDesc_438[6].override_field = 0;
    *(_QWORD *)&dataDesc_438[6].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_438[6].flatOffset[1] = 0;
  }
  CDecal::m_DataMap.dataNumFields = 6;
  CDecal::m_DataMap.dataDesc = &dataDesc_438[1];
  return &CDecal::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10268A40
// Name: struct datamap_t __near * DataMapInit<class CProjectedDecal>(class CProjectedDecal __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CProjectedDecal>()
{
  if ( (_S4_67 & 1) == 0 )
  {
    _S4_67 |= 1u;
    nameHolder_469.m_pszBase = "CProjectedDecal";
    nameHolder_469.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_469.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_469.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_469.m_Names.m_Size = 0;
    nameHolder_469.m_Names.m_pElements = nullptr;
    nameHolder_469.m_nLenBase = 15;
    atexit(func: DataMapInit_CProjectedDecal__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CProjectedDecal::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S4_67 & 2) == 0 )
  {
    _S4_67 |= 2u;
    dataDesc_439[3].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_469,
                                  pszIdentifier: "StaticDecal");
    dataDesc_439[3].flags = 32;
    dataDesc_439[3].fieldOffset = 0;
    dataDesc_439[3].fieldSize = 1;
    dataDesc_439[3].externalName = nullptr;
    dataDesc_439[3].pSaveRestoreOps = nullptr;
    dataDesc_439[3].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CProjectedDecal::StaticDecal;
    *(_QWORD *)&dataDesc_439[3].td = 0;
    *(_QWORD *)&dataDesc_439[3].override_field = 0;
    *(_QWORD *)&dataDesc_439[3].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_439[3].flatOffset[1] = 0;
    dataDesc_439[4].fieldType = FIELD_VOID;
    dataDesc_439[4].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_469,
                                  pszIdentifier: "TriggerDecal");
    *(_QWORD *)&dataDesc_439[4].td = 0;
    *(_QWORD *)&dataDesc_439[4].override_field = 0;
    *(_QWORD *)&dataDesc_439[4].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_439[4].flatOffset[1] = 0;
    dataDesc_439[4].fieldOffset = 0;
    dataDesc_439[4].fieldSize = 1;
    dataDesc_439[4].flags = 32;
    dataDesc_439[4].externalName = nullptr;
    dataDesc_439[4].pSaveRestoreOps = nullptr;
    dataDesc_439[4].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CProjectedDecal::TriggerDecal;
    dataDesc_439[5].fieldType = FIELD_VOID;
    dataDesc_439[5].fieldName = "InputActivate";
    dataDesc_439[5].fieldOffset = 0;
    *(_DWORD *)&dataDesc_439[5].fieldSize = 524289;
    dataDesc_439[5].externalName = "Activate";
    dataDesc_439[5].pSaveRestoreOps = nullptr;
    dataDesc_439[5].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CProjectedDecal::InputActivate;
    *(_QWORD *)&dataDesc_439[5].td = 0;
    *(_QWORD *)&dataDesc_439[5].override_field = 0;
    *(_QWORD *)&dataDesc_439[5].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_439[5].flatOffset[1] = 0;
  }
  CProjectedDecal::m_DataMap.dataNumFields = 5;
  CProjectedDecal::m_DataMap.dataDesc = &dataDesc_439[1];
  return &CProjectedDecal::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10268C10
// Name: struct datamap_t __near * DataMapInit<class CWorld>(class CWorld __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CWorld>()
{
  if ( (_S5_37 & 1) == 0 )
  {
    _S5_37 |= 1u;
    nameHolder_470.m_pszBase = "CWorld";
    nameHolder_470.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_470.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_470.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_470.m_Names.m_Size = 0;
    nameHolder_470.m_Names.m_pElements = nullptr;
    nameHolder_470.m_nLenBase = 6;
    atexit(func: DataMapInit_CWorld__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CWorld::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CWorld::m_DataMap.dataNumFields = 12;
  CWorld::m_DataMap.dataDesc = &dataDesc_440[1];
  return &CWorld::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10280C90
// Name: bool ForEachPlayer<class NotVIP>(class NotVIP __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl ForEachPlayer<NotVIP>()
{
  int i; // edi
  CBasePlayer *v1; // eax
  CBasePlayer *v2; // esi
  edict_t *m_pPev; // eax

  for ( i = 1; i <= gpGlobals->maxClients; ++i )
  {
    v1 = UTIL_PlayerByIndex(playerIndex: i);
    v2 = v1;
    if ( v1 != nullptr )
    {
      m_pPev = v1->m_Network.m_pPev;
      if ( m_pPev != nullptr
        && m_pPev - gpGlobals->pEdicts != 0
        && v2->IsPlayer(this: v2)
        && v2->m_iConnected != PlayerDisconnected )
      {
        LOBYTE(v2[1].m_Relationship.m_Memory.m_pMemory) = 0;
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102946C0
// Name: struct datamap_t __near * DataMapInit<class CCSPlayerResource>(class CCSPlayerResource __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CCSPlayerResource>()
{
  if ( (_S3_147 & 1) == 0 )
  {
    _S3_147 |= 1u;
    nameHolder_473.m_pszBase = "CCSPlayerResource";
    nameHolder_473.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_473.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_473.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_473.m_Names.m_Size = 0;
    nameHolder_473.m_Names.m_pElements = nullptr;
    nameHolder_473.m_nLenBase = 17;
    atexit(func: DataMapInit_CCSPlayerResource__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CCSPlayerResource::m_DataMap.baseMap = &CPlayerResource::m_DataMap;
  CCSPlayerResource::m_DataMap.dataNumFields = 1;
  CCSPlayerResource::m_DataMap.dataDesc = dataDesc_498;
  return &CCSPlayerResource::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10294730
// Name: __CreateCServerGameTagsIServerGameTags_interface_12
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CServerGameTags *__cdecl _CreateCServerGameTagsIServerGameTags_interface_12()
{
  return &_g_CServerGameTags_singleton_12;
}

//------------------------------------------------------------------------------
// Address: 0x1029B470
// Name: struct datamap_t __near * DataMapInit<class CFlashbangProjectile>(class CFlashbangProjectile __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CFlashbangProjectile>()
{
  if ( (_S2_249 & 1) == 0 )
  {
    _S2_249 |= 1u;
    nameHolder_478.m_pszBase = "CFlashbangProjectile";
    nameHolder_478.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_478.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_478.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_478.m_Names.m_Size = 0;
    nameHolder_478.m_Names.m_pElements = nullptr;
    nameHolder_478.m_nLenBase = 20;
    atexit(func: DataMapInit_CFlashbangProjectile__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CFlashbangProjectile::m_DataMap.baseMap = &CBaseCSGrenadeProjectile::m_DataMap;
  CFlashbangProjectile::m_DataMap.dataNumFields = 1;
  CFlashbangProjectile::m_DataMap.dataDesc = &dataDesc_445[1];
  return &CFlashbangProjectile::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x102A3AD0
// Name: struct datamap_t __near * DataMapInit<class CInfoViewParameters>(class CInfoViewParameters __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CInfoViewParameters>()
{
  if ( (_S2_253 & 1) == 0 )
  {
    _S2_253 |= 1u;
    nameHolder_482.m_pszBase = "CInfoViewParameters";
    nameHolder_482.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_482.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_482.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_482.m_Names.m_Size = 0;
    nameHolder_482.m_Names.m_pElements = nullptr;
    nameHolder_482.m_nLenBase = 19;
    atexit(func: DataMapInit_CInfoViewParameters__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CInfoViewParameters::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CInfoViewParameters::m_DataMap.dataNumFields = 1;
  CInfoViewParameters::m_DataMap.dataDesc = &dataDesc_446[1];
  return &CInfoViewParameters::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x102A4A10
// Name: struct datamap_t __near * DataMapInit<class CMapInfo>(class CMapInfo __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CMapInfo>()
{
  if ( (_S2_255 & 1) == 0 )
  {
    _S2_255 |= 1u;
    nameHolder_484.m_pszBase = "CMapInfo";
    nameHolder_484.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_484.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_484.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_484.m_Names.m_Size = 0;
    nameHolder_484.m_Names.m_pElements = nullptr;
    nameHolder_484.m_nLenBase = 8;
    atexit(func: DataMapInit_CMapInfo__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CMapInfo::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CMapInfo::m_DataMap.dataNumFields = 1;
  CMapInfo::m_DataMap.dataDesc = &dataDesc_447[1];
  return &CMapInfo::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x102A56A0
// Name: class CSurroundTest __near * _CreateEntityTemplate<class CSurroundTest>(class CSurroundTest __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSurroundTest *__cdecl _CreateEntityTemplate<CSurroundTest>(CSurroundTest *newEnt, const char *className)
{
  CBaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x39Cu);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    *v3 = &CSurroundTest::`vftable';
    v3[213] = 0;
    v3[216] = -1;
    v3[217] = 0;
    v3[219] = 0;
    v3[222] = -1;
    v3[223] = 0;
    v3[225] = 0;
    v3[228] = -1;
    v3[229] = 0;
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CSurroundTest *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A5750
// Name: struct datamap_t __near * DataMapInit<class CSurroundTest>(class CSurroundTest __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CSurroundTest>()
{
  if ( (_S2_257 & 1) == 0 )
  {
    _S2_257 |= 1u;
    nameHolder_485.m_pszBase = "CSurroundTest";
    nameHolder_485.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_485.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_485.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_485.m_Names.m_Size = 0;
    nameHolder_485.m_Names.m_pElements = nullptr;
    nameHolder_485.m_nLenBase = 13;
    atexit(func: DataMapInit_CSurroundTest__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CSurroundTest::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S2_257 & 2) == 0 )
  {
    _S2_257 |= 2u;
    *(_QWORD *)&dataDesc_448[2].inputFunc = 0;
    *(_QWORD *)&dataDesc_448[2].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_448[2].override_count = 0;
    *(_QWORD *)dataDesc_448[2].flatOffset = 0;
    dataDesc_448[3].fieldSize = 1;
    *(_QWORD *)&dataDesc_448[3].inputFunc = 0;
    *(_QWORD *)&dataDesc_448[3].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_448[3].override_count = 0;
    *(_QWORD *)dataDesc_448[3].flatOffset = 0;
    dataDesc_448[2].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_448[2].flatGroup = 0;
    dataDesc_448[3].fieldType = FIELD_CUSTOM;
    dataDesc_448[3].fieldName = "m_On4Speakers";
    dataDesc_448[3].fieldOffset = 876;
    dataDesc_448[3].flags = 22;
    dataDesc_448[3].externalName = "On4Speakers";
    dataDesc_448[3].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_448[3].flatGroup = 0;
    dataDesc_448[4].fieldType = FIELD_CUSTOM;
    dataDesc_448[4].fieldName = "m_On51Speakers";
    dataDesc_448[4].fieldOffset = 900;
    *(_DWORD *)&dataDesc_448[4].fieldSize = 1441793;
    dataDesc_448[4].externalName = "On51Speakers";
    dataDesc_448[4].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_448[4].inputFunc = 0;
    *(_QWORD *)&dataDesc_448[4].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_448[4].override_count = 0;
    *(_QWORD *)dataDesc_448[4].flatOffset = 0;
    *(_DWORD *)&dataDesc_448[4].flatGroup = 0;
  }
  CSurroundTest::m_DataMap.dataNumFields = 4;
  CSurroundTest::m_DataMap.dataDesc = &dataDesc_448[1];
  return &CSurroundTest::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x102A5F40
// Name: struct datamap_t __near * DataMapInit<class CSmokeGrenadeProjectile>(class CSmokeGrenadeProjectile __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CSmokeGrenadeProjectile>()
{
  if ( (_S2_258 & 1) == 0 )
  {
    _S2_258 |= 1u;
    nameHolder_486.m_pszBase = "CSmokeGrenadeProjectile";
    nameHolder_486.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_486.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_486.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_486.m_Names.m_Size = 0;
    nameHolder_486.m_Names.m_pElements = nullptr;
    nameHolder_486.m_nLenBase = 23;
    atexit(func: DataMapInit_CSmokeGrenadeProjectile__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CSmokeGrenadeProjectile::m_DataMap.baseMap = &CBaseCSGrenadeProjectile::m_DataMap;
  if ( (_S2_258 & 2) == 0 )
  {
    _S2_258 |= 2u;
    dataDesc_504[1].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_486,
                                  pszIdentifier: "Think_Detonate");
    dataDesc_504[1].flags = 32;
    dataDesc_504[1].fieldOffset = 0;
    dataDesc_504[1].fieldSize = 1;
    dataDesc_504[1].externalName = nullptr;
    dataDesc_504[1].pSaveRestoreOps = nullptr;
    dataDesc_504[1].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CSmokeGrenadeProjectile::Think_Detonate;
    *(_QWORD *)&dataDesc_504[1].td = 0;
    *(_QWORD *)&dataDesc_504[1].override_field = 0;
    *(_QWORD *)&dataDesc_504[1].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_504[1].flatOffset[1] = 0;
    dataDesc_504[2].fieldType = FIELD_VOID;
    dataDesc_504[2].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_486,
                                  pszIdentifier: "Think_Fade");
    dataDesc_504[2].fieldOffset = 0;
    dataDesc_504[2].fieldSize = 1;
    dataDesc_504[2].flags = 32;
    dataDesc_504[2].externalName = nullptr;
    dataDesc_504[2].pSaveRestoreOps = nullptr;
    dataDesc_504[2].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CSmokeGrenadeProjectile::Think_Fade;
    *(_QWORD *)&dataDesc_504[2].td = 0;
    *(_QWORD *)&dataDesc_504[2].override_field = 0;
    *(_QWORD *)&dataDesc_504[2].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_504[2].flatOffset[1] = 0;
    dataDesc_504[3].fieldType = FIELD_VOID;
    dataDesc_504[3].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_486,
                                  pszIdentifier: "Think_Remove");
    dataDesc_504[3].fieldOffset = 0;
    *(_DWORD *)&dataDesc_504[3].fieldSize = 2097153;
    dataDesc_504[3].externalName = nullptr;
    dataDesc_504[3].pSaveRestoreOps = nullptr;
    dataDesc_504[3].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CSmokeGrenadeProjectile::Think_Remove;
    *(_QWORD *)&dataDesc_504[3].td = 0;
    *(_QWORD *)&dataDesc_504[3].override_field = 0;
    *(_QWORD *)&dataDesc_504[3].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_504[3].flatOffset[1] = 0;
  }
  CSmokeGrenadeProjectile::m_DataMap.dataNumFields = 3;
  CSmokeGrenadeProjectile::m_DataMap.dataDesc = &dataDesc_504[1];
  return &CSmokeGrenadeProjectile::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x102DBC70
// Name: bool NavAreaBuildPath<class HostagePathCost>(class CNavArea __near *,class CNavArea __near *,class Vector const __near *,class HostagePathCost __near &,class CNavArea __near * __near *,float,int,bool)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl NavAreaBuildPath<HostagePathCost>(
        CNavArea *startArea,
        CNavArea *goalArea,
        const Vector *goalPos,
        HostagePathCost *costFunc,
        CNavArea **closestArea,
        float maxPathLength,
        int teamID,
        BOOL ignoreNavBlockers)
{
  int v8; // ecx
  CNavArea *v9; // edi
  const Vector *v10; // ecx
  const Vector *p_m_center; // eax
  CNavArea *v13; // esi
  int v14; // edi
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *m_pData; // eax
  int v16; // eax
  CNavArea *area; // esi
  float v18; // xmm0_4
  const CNavLadder *v19; // eax
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *v20; // eax
  double v21; // st7
  float v22; // xmm1_4
  float v23; // xmm0_4
  float v24; // xmm0_4
  float v25; // xmm0_4
  double v26; // xmm0_8
  float v27; // xmm0_4
  unsigned int m_openMarker; // eax
  __int64 v29; // [esp+70h] [ebp-48h]
  float z; // [esp+78h] [ebp-40h]
  float actualGoalPos; // [esp+7Ch] [ebp-3Ch]
  const CFuncElevator *actualGoalPos_4; // [esp+80h] [ebp-38h]
  float actualGoalPos_4a; // [esp+80h] [ebp-38h]
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator> *actualGoalPos_8; // [esp+84h] [ebp-34h]
  const CNavLadder *closestAreaDist; // [esp+88h] [ebp-30h]
  const CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator> *floorList; // [esp+90h] [ebp-28h]
  int ladder; // [esp+94h] [ebp-24h]
  int length; // [esp+98h] [ebp-20h]
  const CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator> *ladderList; // [esp+9Ch] [ebp-1Ch]
  NavAreaBuildPath::__l31::SearchType searchWhere; // [esp+A0h] [ebp-18h]
  CNavArea *dir; // [esp+A4h] [ebp-14h]
  bool how_2; // [esp+AAh] [ebp-Eh]
  char how_3; // [esp+ABh] [ebp-Dh]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "NavAreaBuildPath",
    a3: 0,
    a4: "NextBotSpiky",
    a5: false,
    a6: 4);
  if ( closestArea != nullptr )
    *closestArea = startArea;
  v8 = g_DebugPathfindCounter--;
  how_2 = v8 > 0;
  if ( startArea == nullptr )
    goto LABEL_8;
  v9 = goalArea;
  if ( goalArea != nullptr )
  {
    if ( !goalArea->IsBlocked(this: goalArea, a2: teamID, a3: ignoreNavBlockers) )
    {
      v10 = goalPos;
      goto LABEL_10;
    }
    goalArea = nullptr;
    v9 = nullptr;
  }
  v10 = goalPos;
  if ( goalPos == nullptr )
  {
LABEL_8:
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return 0;
  }
LABEL_10:
  startArea->m_parent = nullptr;
  startArea->m_parentHow = NUM_TRAVERSE_TYPES;
  if ( startArea == v9 )
  {
    v9->m_parent = nullptr;
    v9->m_parentHow = NUM_TRAVERSE_TYPES;
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return 1;
  }
  p_m_center = v10;
  if ( v10 == nullptr )
    p_m_center = &v9->m_center;
  v29 = *(_QWORD *)&p_m_center->x;
  z = p_m_center->z;
  CNavArea::ClearSearchLists();
  startArea->m_totalCost = fsqrt(
                             (float)((float)((float)(startArea->m_center.z - z) * (float)(startArea->m_center.z - z))
                                   + (float)((float)(startArea->m_center.x - *(float *)&v29)
                                           * (float)(startArea->m_center.x - *(float *)&v29)))
                           + (float)((float)(startArea->m_center.y - *((float *)&v29 + 1))
                                   * (float)(startArea->m_center.y - *((float *)&v29 + 1))));
  startArea->m_costSoFar = 0.0;
  startArea->m_pathLengthSoFar = 0.0;
  CNavArea::AddToOpenList(this: startArea);
  if ( closestArea != nullptr )
    *closestArea = startArea;
  v13 = CNavArea::m_openList;
  actualGoalPos = startArea->m_totalCost;
  if ( CNavArea::m_openList == nullptr )
    goto LABEL_8;
  while ( 1 )
  {
    CNavArea::RemoveFromOpenList(this: v13);
    v13->m_prevOpen = nullptr;
    v13->m_nextOpen = nullptr;
    if ( how_2 )
      ((void (__thiscall *)(CNavArea *, _DWORD, int, _DWORD, int, int, int, int))v13->DrawFilled)(
        a1: v13,
        a2: 0,
        a3: 255,
        a4: 0,
        a5: 128,
        a6: 1106247680,
        a7: 1,
        a8: 1084227584);
    if ( !v13->IsBlocked(this: v13, a2: teamID, a3: ignoreNavBlockers) )
      break;
LABEL_72:
    v13 = CNavArea::m_openList;
    if ( CNavArea::m_openList == nullptr )
      goto LABEL_8;
  }
  if ( v13 != v9 && (v9 != nullptr || goalPos == nullptr || !CNavArea::Contains(this: v13, pos: goalPos)) )
  {
    actualGoalPos_8 = v13->m_connect;
    v14 = 0;
    ladder = 0;
    length = 0;
    how_3 = 1;
    floorList = nullptr;
    searchWhere = SEARCH_FLOOR;
    while ( 1 )
    {
      while ( 1 )
      {
        closestAreaDist = nullptr;
        actualGoalPos_4 = nullptr;
        if ( ladder != 0 )
          break;
        m_pData = actualGoalPos_8->m_pData;
        if ( v14 < actualGoalPos_8->m_pData->m_Size )
        {
          area = m_pData->m_Elements[v14].area;
          v18 = m_pData->m_Elements[v14++].length;
LABEL_52:
          if ( area != dir && !area->IsBlocked(this: area, a2: teamID, a3: ignoreNavBlockers) )
          {
            v21 = HostagePathCost::operator()(
                    this: costFunc,
                    area,
                    fromArea: dir,
                    ladder: closestAreaDist,
                    elevator: actualGoalPos_4,
                    length: v18);
            if ( v21 >= 0.0 )
            {
              if ( maxPathLength > 0.0 )
              {
                v22 = area->m_center.y - dir->m_center.y;
                v23 = area->m_center.x - dir->m_center.x;
                v24 = dir->m_pathLengthSoFar
                    + fsqrt(
                        (float)((float)(v23 * v23) + (float)(v22 * v22))
                      + (float)((float)(area->m_center.z - dir->m_center.z) * (float)(area->m_center.z - dir->m_center.z)));
                if ( v24 > maxPathLength )
                  goto LABEL_25;
                area->m_pathLengthSoFar = v24;
              }
              actualGoalPos_4a = v21;
              if ( area->m_openMarker != CNavArea::m_masterMarker && area->m_marker != CNavArea::m_masterMarker
                || actualGoalPos_4a < area->m_costSoFar )
              {
                v25 = (float)((float)((float)(area->m_center.x - *(float *)&v29)
                                    * (float)(area->m_center.x - *(float *)&v29))
                            + (float)((float)(area->m_center.y - *((float *)&v29 + 1))
                                    * (float)(area->m_center.y - *((float *)&v29 + 1))))
                    + (float)((float)(area->m_center.z - z) * (float)(area->m_center.z - z));
                if ( v25 <= 0.0 )
                  v26 = 0.0;
                else
                  v26 = fsqrt(v25);
                v27 = v26;
                if ( closestArea != nullptr && actualGoalPos > v27 )
                {
                  *closestArea = area;
                  actualGoalPos = v27;
                }
                m_openMarker = area->m_openMarker;
                area->m_costSoFar = actualGoalPos_4a;
                area->m_totalCost = v27 + actualGoalPos_4a;
                if ( m_openMarker == CNavArea::m_masterMarker )
                  CNavArea::UpdateOnOpenList(this: area);
                else
                  CNavArea::AddToOpenList(this: area);
                area->m_parent = dir;
                area->m_parentHow = (NavTraverseType)ladderList;
              }
            }
          }
LABEL_25:
          v13 = dir;
        }
        else
        {
          v16 = length + 1;
          v14 = 0;
          length = v16;
          if ( v16 == 4 )
          {
            ladder = 1;
            floorList = (const CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator> *)v13->m_ladder;
            searchWhere = SEARCH_FLOOR;
          }
          else
          {
            actualGoalPos_8 = &v13->m_connect[v16];
          }
        }
      }
      if ( ladder != 1 )
        break;
      if ( v14 < floorList->m_pData->m_Size )
      {
        v19 = (const CNavLadder *)*(&floorList->m_pData->m_Elements[0].id + v14);
        closestAreaDist = v19;
        if ( how_3 == 0 )
        {
          area = v19->m_bottomArea;
          ++v14;
          goto LABEL_46;
        }
        switch ( searchWhere )
        {
          case SEARCH_FLOOR:
            area = v19->m_topForwardArea;
            searchWhere = SEARCH_LADDERS;
LABEL_46:
            if ( area == nullptr )
              goto LABEL_25;
LABEL_51:
            v18 = -1.0;
            goto LABEL_52;
          case SEARCH_LADDERS:
            area = v19->m_topLeftArea;
            searchWhere = SEARCH_ELEVATORS;
            goto LABEL_46;
          case SEARCH_ELEVATORS:
            area = v19->m_topRightArea;
            searchWhere = SEARCH_ELEVATORS|SEARCH_LADDERS;
            goto LABEL_46;
          default:
            break;
        }
        ++v14;
        searchWhere = SEARCH_FLOOR;
      }
      else
      {
        v14 = 0;
        if ( how_3 != 0 )
        {
          how_3 = 0;
          floorList = (const CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator> *)&v13->m_ladder[1];
        }
        else
        {
          ladder = 2;
        }
      }
    }
    actualGoalPos_4 = CNavArea::GetElevator(this: v13);
    if ( actualGoalPos_4 == nullptr || (v20 = v13->m_elevatorAreas.m_pData, v14 >= v20->m_Size) )
    {
      v9 = goalArea;
      v13->m_marker = CNavArea::m_masterMarker;
      goto LABEL_72;
    }
    area = v20->m_Elements[v14++].area;
    goto LABEL_51;
  }
  if ( closestArea != nullptr )
    *closestArea = v13;
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102E4CD0
// Name: __CreateCServerGameTagsIServerGameTags_interface_52
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CServerGameTags *__cdecl _CreateCServerGameTagsIServerGameTags_interface_52()
{
  return &_g_CServerGameTags_singleton_52;
}

//------------------------------------------------------------------------------
// Address: 0x102EA630
// Name: struct datamap_t __near * DataMapInit<class CWeaponCSBase>(class CWeaponCSBase __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CWeaponCSBase>()
{
  if ( (_S3_157 & 1) == 0 )
  {
    _S3_157 |= 1u;
    nameHolder_494.m_pszBase = "CWeaponCSBase";
    nameHolder_494.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_494.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_494.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_494.m_Names.m_Size = 0;
    nameHolder_494.m_Names.m_pElements = nullptr;
    nameHolder_494.m_nLenBase = 13;
    atexit(func: DataMapInit_CWeaponCSBase__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CWeaponCSBase::m_DataMap.baseMap = &CBaseCombatWeapon::m_DataMap;
  if ( (_S3_157 & 2) == 0 )
  {
    _S3_157 |= 2u;
    dataDesc_509[1].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_494,
                                  pszIdentifier: "FallThink");
    dataDesc_509[1].fieldOffset = 0;
    *(_DWORD *)&dataDesc_509[1].fieldSize = 2097153;
    dataDesc_509[1].externalName = nullptr;
    dataDesc_509[1].pSaveRestoreOps = nullptr;
    dataDesc_509[1].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *)) __thiscall CBaseCombatWeapon::`vcall'{1408,{flat}};
    *(_QWORD *)&dataDesc_509[1].td = 0;
    *(_QWORD *)&dataDesc_509[1].override_field = 0;
    *(_QWORD *)&dataDesc_509[1].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_509[1].flatOffset[1] = 0;
  }
  CWeaponCSBase::m_DataMap.dataNumFields = 1;
  CWeaponCSBase::m_DataMap.dataDesc = &dataDesc_509[1];
  return &CWeaponCSBase::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x103257E0
// Name: struct datamap_t __near * DataMapInit<class CParticleFire>(class CParticleFire __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CParticleFire>()
{
  if ( (_S3_166 & 1) == 0 )
  {
    _S3_166 |= 1u;
    nameHolder_503.m_pszBase = "CParticleFire";
    nameHolder_503.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_503.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_503.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_503.m_Names.m_Size = 0;
    nameHolder_503.m_Names.m_pElements = nullptr;
    nameHolder_503.m_nLenBase = 13;
    atexit(func: DataMapInit_CParticleFire__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CParticleFire::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CParticleFire::m_DataMap.dataNumFields = 2;
  CParticleFire::m_DataMap.dataDesc = &dataDesc_454[1];
  return &CParticleFire::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10325D60
// Name: struct datamap_t __near * DataMapInit<class ParticleSmokeGrenade>(class ParticleSmokeGrenade __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<ParticleSmokeGrenade>()
{
  if ( (_S3_167 & 1) == 0 )
  {
    _S3_167 |= 1u;
    nameHolder_504.m_pszBase = "ParticleSmokeGrenade";
    nameHolder_504.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_504.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_504.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_504.m_Names.m_Size = 0;
    nameHolder_504.m_Names.m_pElements = nullptr;
    nameHolder_504.m_nLenBase = 20;
    atexit(func: DataMapInit_ParticleSmokeGrenade__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  ParticleSmokeGrenade::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  ParticleSmokeGrenade::m_DataMap.dataNumFields = 6;
  ParticleSmokeGrenade::m_DataMap.dataDesc = &dataDesc_455[1];
  return &ParticleSmokeGrenade::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10326220
// Name: struct datamap_t __near * DataMapInit<class CPlasma>(class CPlasma __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CPlasma>()
{
  if ( (_S3_168 & 1) == 0 )
  {
    _S3_168 |= 1u;
    nameHolder_505.m_pszBase = "CPlasma";
    nameHolder_505.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_505.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_505.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_505.m_Names.m_Size = 0;
    nameHolder_505.m_Names.m_pElements = nullptr;
    nameHolder_505.m_nLenBase = 7;
    atexit(func: DataMapInit_CPlasma__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CPlasma::m_DataMap.baseMap = &CBaseFire::m_DataMap;
  CPlasma::m_DataMap.dataNumFields = 3;
  CPlasma::m_DataMap.dataDesc = &dataDesc_456[1];
  return &CPlasma::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10328580
// Name: struct datamap_t __near * DataMapInit<class SmokeTrail>(class SmokeTrail __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<SmokeTrail>()
{
  if ( (_S3_169 & 1) == 0 )
  {
    _S3_169 |= 1u;
    nameHolder_506.m_pszBase = "SmokeTrail";
    nameHolder_506.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_506.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_506.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_506.m_Names.m_Size = 0;
    nameHolder_506.m_Names.m_pElements = nullptr;
    nameHolder_506.m_nLenBase = 10;
    atexit(func: DataMapInit_SmokeTrail__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  SmokeTrail::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  SmokeTrail::m_DataMap.dataNumFields = 15;
  SmokeTrail::m_DataMap.dataDesc = &dataDesc_457[1];
  return &SmokeTrail::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10328600
// Name: struct datamap_t __near * DataMapInit<class RocketTrail>(class RocketTrail __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<RocketTrail>()
{
  if ( (_S5_41 & 1) == 0 )
  {
    _S5_41 |= 1u;
    nameHolder_507.m_pszBase = "RocketTrail";
    nameHolder_507.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_507.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_507.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_507.m_Names.m_Size = 0;
    nameHolder_507.m_Names.m_pElements = nullptr;
    nameHolder_507.m_nLenBase = 11;
    atexit(func: DataMapInit_RocketTrail__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  RocketTrail::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  RocketTrail::m_DataMap.dataNumFields = 15;
  RocketTrail::m_DataMap.dataDesc = &dataDesc_458[1];
  return &RocketTrail::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10328680
// Name: struct datamap_t __near * DataMapInit<class SporeTrail>(class SporeTrail __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<SporeTrail>()
{
  if ( (_S7_20 & 1) == 0 )
  {
    _S7_20 |= 1u;
    nameHolder_508.m_pszBase = "SporeTrail";
    nameHolder_508.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_508.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_508.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_508.m_Names.m_Size = 0;
    nameHolder_508.m_Names.m_pElements = nullptr;
    nameHolder_508.m_nLenBase = 10;
    atexit(func: DataMapInit_SporeTrail__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  SporeTrail::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  SporeTrail::m_DataMap.dataNumFields = 7;
  SporeTrail::m_DataMap.dataDesc = &dataDesc_459[1];
  return &SporeTrail::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1032A500
// Name: struct datamap_t __near * DataMapInit<class CSpriteTrail>(class CSpriteTrail __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CSpriteTrail>()
{
  if ( (_S2_319 & 1) == 0 )
  {
    _S2_319 |= 1u;
    nameHolder_514.m_pszBase = "CSpriteTrail";
    nameHolder_514.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_514.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_514.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_514.m_Names.m_Size = 0;
    nameHolder_514.m_Names.m_pElements = nullptr;
    nameHolder_514.m_nLenBase = 12;
    atexit(func: DataMapInit_CSpriteTrail__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CSpriteTrail::m_DataMap.baseMap = &CSprite::m_DataMap;
  CSpriteTrail::m_DataMap.dataNumFields = 10;
  CSpriteTrail::m_DataMap.dataDesc = &dataDesc_465[1];
  return &CSpriteTrail::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1032AAF0
// Name: class CSteamJet __near * _CreateEntityTemplate<class CSteamJet>(class CSteamJet __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSteamJet *__cdecl _CreateEntityTemplate<CSteamJet>(CSteamJet *newEnt, const char *className)
{
  CBaseParticleEntity *v2; // eax
  CBaseParticleEntity *v3; // edi
  CBaseEdict *v4; // ecx

  v2 = (CBaseParticleEntity *)CBaseEntity::operator new(stAllocateBlock: 0x37Cu);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseParticleEntity::CBaseParticleEntity(this: v2);
    v3->__vftable = (CBaseParticleEntity_vtbl *)&CSteamJet::`vftable';
    if ( *(float *)&v3[1].m_Network.m_PVSInfo.m_nAreaNum != 8.0 )
    {
      if ( v3->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&v3->m_Network + 76) |= 1u;
      }
      else
      {
        v4 = &v3->m_Network.m_pPev->CBaseEdict;
        if ( v4 != nullptr )
          CBaseEdict::StateChanged(this: v4, offset: 0x378u);
      }
      *(_DWORD *)&v3[1].m_Network.m_PVSInfo.m_nAreaNum = 1090519040;
    }
    v3->PostConstructor(this: v3, a2: className);
    return (CSteamJet *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1032ABB0
// Name: struct datamap_t __near * DataMapInit<class CSteamJet>(class CSteamJet __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CSteamJet>()
{
  if ( (_S3_172 & 1) == 0 )
  {
    _S3_172 |= 1u;
    nameHolder_515.m_pszBase = "CSteamJet";
    nameHolder_515.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_515.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_515.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_515.m_Names.m_Size = 0;
    nameHolder_515.m_Names.m_pElements = nullptr;
    nameHolder_515.m_nLenBase = 9;
    atexit(func: DataMapInit_CSteamJet__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CSteamJet::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  CSteamJet::m_DataMap.dataNumFields = 14;
  CSteamJet::m_DataMap.dataDesc = &dataDesc_466[1];
  return &CSteamJet::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10415920
// Name: _dynamic_initializer_for__env_steam__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_steam__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CSteamJet> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_steam,
           a3: "env_steam");
}

//------------------------------------------------------------------------------
// Address: 0x10415940
// Name: _dynamic_initializer_for__env_steamjet__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_steamjet__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CSteamJet> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_steamjet,
           a3: "env_steamjet");
}

//------------------------------------------------------------------------------
// Address: 0x10415970
// Name: _dynamic_initializer_for__g_TESystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TESystem__()
{
  g_TESystem.m_pNextSystem = IPredictionSystem::g_pPredictionSystems;
  IPredictionSystem::g_pPredictionSystems = &g_TESystem;
  return atexit(func: dynamic_atexit_destructor_for__g_TESystem__);
}

//------------------------------------------------------------------------------
// Address: 0x10415990
// Name: _dynamic_initializer_for__g_CTEMetalSparks_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CTEMetalSparks_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CTEMetalSparks_ClassReg,
           pNetworkName: "CTEMetalSparks",
           pTable: &DT_TEMetalSparks::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10421D60
// Name: _ServerClassInit_DT_SteamJet::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_SteamJet::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_320;
  for ( i = 12; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x10421D80
// Name: _DataMapInit_CSteamJet__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CSteamJet__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_515);
}

//------------------------------------------------------------------------------
// Address: 0x10421D90
// Name: _dynamic_atexit_destructor_for__g_TESystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_TESystem__()
{
  g_TESystem.__vftable = (CTempEntsSystem_vtbl *)&IPredictionSystem::`vftable';
}
