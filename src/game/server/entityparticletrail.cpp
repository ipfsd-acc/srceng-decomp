// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/entityparticletrail.cpp
// Functions: 18
// ============================================================

#include "game\server\entityparticletrail.h"

//------------------------------------------------------------------------------
// Address: 0x10110120
// Name: private: virtual struct datamap_t __near * CEntityParticleTrail::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CEntityParticleTrail::GetDataDescMap(CEntityParticleTrail *this)
{
  return &CEntityParticleTrail::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10110130
// Name: public: virtual class ServerClass __near * CEntityParticleTrail::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CEntityParticleTrail::GetServerClass(CEntityParticleTrail *this)
{
  return &g_CEntityParticleTrail_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x10110140
// Name: public: virtual void CEntityParticleTrail::UpdateOnRemove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityParticleTrail::UpdateOnRemove(CEntityParticleTrail *this)
{
  g_pNotify->ClearEntity(this: g_pNotify, a2: this);
  CBaseEntity::UpdateOnRemove(this);
}

//------------------------------------------------------------------------------
// Address: 0x10110160
// Name: public: virtual void CEntityParticleTrail::NotifySystemEvent(class CBaseEntity __near *,enum notify_system_event_t,struct notify_system_event_params_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityParticleTrail::NotifySystemEvent(
        CEntityParticleTrail *this,
        CBaseEntity *pNotify,
        notify_system_event_t eventType,
        const notify_system_event_params_t *params)
{
  float m_Value; // xmm0_4
  const char *v6; // [esp+8h] [ebp-Ch]

  CBaseCombatWeapon::AddViewmodelBob((vgui::TreeView *)this, itemIndex: (int)pNotify, x: eventType, y: (int)params);
  if ( eventType == NOTIFY_EVENT_DESTROY )
  {
    CBaseParticleEntity::FollowEntity(this, pEntity: nullptr);
    g_pNotify->ClearEntity(this: g_pNotify, a2: this);
    if ( this->m_nRefCount != 0 )
    {
      m_Value = this->m_Info.m_flLifetime.m_Value;
      v6 = s_pRetireContext;
      this->m_nRefCount = 0;
      CBaseEntity::ThinkSet(this, func: CBaseEntity::SUB_Remove, thinkTime: m_Value + gpGlobals->curtime, szContext: v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101101E0
// Name: public: virtual void CEntityParticleTrail::NetworkVar_m_Info::NetworkStateChanged(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityParticleTrail::NetworkVar_m_Info::NetworkStateChanged(
        CEntityParticleTrail::NetworkVar_m_Info *this,
        void *pVar)
{
  char *v2; // eax
  CBaseEdict *v3; // ecx

  v2 = (char *)this - 856;
  if ( *((_BYTE *)this - 772) != 0 )
  {
    v2[88] |= 1u;
  }
  else
  {
    v3 = *((CBaseEdict **)v2 + 6);
    if ( v3 != nullptr )
      CBaseEdict::StateChanged(this: v3, offset: (_WORD)pVar - (_WORD)v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10110300
// Name: public: virtual void CEntityParticleTrail::SetTransmit(class CCheckTransmitInfo __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityParticleTrail::SetTransmit(CEntityParticleTrail *this, CCheckTransmitInfo *pInfo, int bAlways)
{
  edict_t *m_pPev; // eax
  unsigned int m_Index; // ecx
  int v6; // eax
  CEntInfo *v7; // edx
  unsigned int v8; // ecx
  int v9; // eax
  bool v10; // zf
  CEntInfo *v11; // eax

  m_pPev = this->m_Network.m_pPev;
  if ( m_pPev != nullptr )
    m_pPev -= (int)gpGlobals->pEdicts;
  if ( ((1 << ((unsigned __int8)m_pPev & 0x1F)) & pInfo->m_pTransmitEdict->m_Ints[(unsigned int)m_pPev >> 5]) == 0 )
  {
    CBaseEntity::SetTransmit(this, pInfo, bAlways);
    m_Index = this->m_hConstraintEntity.m_Value.m_Index;
    if ( m_Index != -1 )
    {
      v6 = (unsigned __int16)m_Index;
      v7 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
      v8 = HIWORD(m_Index);
      if ( v7->m_SerialNumber == v8 && v7->m_pEntity != nullptr )
      {
        v9 = v6;
        v10 = g_pEntityList->m_EntPtrArray[v9].m_SerialNumber == v8;
        v11 = &g_pEntityList->m_EntPtrArray[v9];
        if ( v10 )
          ((void (__thiscall *)(IHandleEntity *, CCheckTransmitInfo *, int))v11->m_pEntity->__vftable[7].SetRefEHandle)(
            a1: v11->m_pEntity,
            a2: pInfo,
            a3: bAlways);
        else
          (*(void (__stdcall **)(CCheckTransmitInfo *, int))(MEMORY[0] + 88))(a1: pInfo, a2: bAlways);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101103B0
// Name: public: static void CEntityParticleTrail::Destroy(class CBaseEntity __near *,struct EntityParticleTrailInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CEntityParticleTrail::Destroy(CBaseEntity *pTarget, const EntityParticleTrailInfo_t *info)
{
  const char *pszValue; // eax
  int MaterialIndex; // ebx
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // eax
  IHandleEntity *v6; // edx
  IHandleEntity_vtbl *v7; // eax
  IHandleEntity *v8; // edi
  CBaseParticleEntity *v9; // eax
  CBaseParticleEntity *v10; // esi

  pszValue = info->m_strMaterialName.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  MaterialIndex = GetMaterialIndex(pMaterialName: pszValue);
  m_Index = pTarget->m_hMoveChild.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  v6 = m_pEntity;
  if ( m_pEntity != nullptr )
  {
    do
    {
      v7 = v6[56].__vftable;
      if ( v7 == (IHandleEntity_vtbl *)-1
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_SerialNumber != (unsigned int)v7 >> 16 )
      {
        v8 = nullptr;
      }
      else
      {
        v8 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_pEntity;
      }
      v9 = (CBaseParticleEntity *)__RTDynamicCast(
                                    inptr: v6,
                                    VfDelta: 0,
                                    SrcType: &CBaseEntity `RTTI Type Descriptor',
                                    TargetType: &CEntityParticleTrail `RTTI Type Descriptor',
                                    isReference: 0);
      v10 = v9;
      if ( v9 != nullptr
        && v9[1].__vftable == (CBaseParticleEntity_vtbl *)MaterialIndex
        && (*(_DWORD *)&v9[1].m_Network.m_PVSInfo.m_nHeadNode)-- == 1 )
      {
        CBaseParticleEntity::FollowEntity(this: v9, pEntity: nullptr);
        g_pNotify->ClearEntity(this: g_pNotify, a2: v10);
        CBaseEntity::ThinkSet(
          this: v10,
          func: CBaseEntity::SUB_Remove,
          thinkTime: *(float *)&v10[1].m_Network.CBaseEntity::__vftable + gpGlobals->curtime,
          szContext: s_pRetireContext);
      }
      v6 = v8;
    }
    while ( v8 != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10110550
// Name: public: virtual void CEntityParticleTrail::NetworkVar_m_Info::NetworkStateChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEntityParticleTrail::NetworkVar_m_Info::NetworkStateChanged(
        CEntityParticleTrail::NetworkVar_m_Info *this)
{
  CBaseEdict *v1; // ecx

  if ( *((_BYTE *)this - 772) != 0 )
  {
    *((_BYTE *)this - 768) |= 1u;
  }
  else
  {
    v1 = *((CBaseEdict **)this - 208);
    if ( v1 != nullptr )
    {
      v1->m_fStateFlags |= 0x101u;
      CBaseEdict::GetChangeAccessor(this: v1)->m_iChangeInfoSerialNumber = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10110580
// Name: public: static class CEntityParticleTrail __near * CEntityParticleTrail::Create(class CBaseEntity __near *,struct EntityParticleTrailInfo_t const __near &,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
CEntityParticleTrail *__cdecl CEntityParticleTrail::Create(
        CBaseEntity *pTarget,
        const EntityParticleTrailInfo_t *info,
        CBaseEntity *pConstraintEntity)
{
  const char *pszValue; // eax
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // edx
  IHandleEntity_vtbl *v6; // eax
  IHandleEntity *v7; // edi
  CBaseEntity *v8; // eax
  CBaseEntity *v9; // esi
  CEntityParticleTrail *result; // eax
  CEntityParticleTrail *v11; // esi
  CBaseEdict *v12; // ecx
  CEntityParticleTrail::NetworkVar_m_Info_vtbl *v13; // edx
  int iMaterialName; // [esp+10h] [ebp-4h]

  pszValue = info->m_strMaterialName.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  iMaterialName = GetMaterialIndex(pMaterialName: pszValue);
  m_Index = pTarget->m_hMoveChild.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  if ( m_pEntity != nullptr )
  {
    while ( 1 )
    {
      v6 = m_pEntity[56].__vftable;
      if ( v6 == (IHandleEntity_vtbl *)-1
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber != (unsigned int)v6 >> 16 )
      {
        v7 = nullptr;
      }
      else
      {
        v7 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_pEntity;
      }
      v8 = (CBaseEntity *)__RTDynamicCast(
                            inptr: m_pEntity,
                            VfDelta: 0,
                            SrcType: &CBaseEntity `RTTI Type Descriptor',
                            TargetType: &CEntityParticleTrail `RTTI Type Descriptor',
                            isReference: 0);
      v9 = v8;
      if ( v8 != nullptr && v8[1].__vftable == (CBaseEntity_vtbl *)iMaterialName )
        break;
      m_pEntity = v7;
      if ( v7 == nullptr )
        goto LABEL_15;
    }
    if ( *(_DWORD *)&v8[1].m_Network.m_PVSInfo.m_nHeadNode == 0 )
      CBaseEntity::ThinkSet(this: v8, func: nullptr, thinkTime: gpGlobals->curtime, szContext: s_pRetireContext);
    ++*(_DWORD *)&v9[1].m_Network.m_PVSInfo.m_nHeadNode;
    return (CEntityParticleTrail *)v9;
  }
  else
  {
LABEL_15:
    result = (CEntityParticleTrail *)CreateEntityByName(
                                       className: "env_particle_trail",
                                       iForceEdictIndex: -1,
                                       bNotify: true);
    v11 = result;
    if ( result != nullptr )
    {
      CNetworkHandleBase<CBaseEntity,CEntityParticleTrail::NetworkVar_m_hConstraintEntity>::Set(
        this: &result->m_hConstraintEntity,
        val: pConstraintEntity);
      if ( v11->m_iMaterialName.m_Value != iMaterialName )
      {
        if ( v11->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&v11->m_Network + 76) |= 1u;
        }
        else
        {
          v12 = &v11->m_Network.m_pPev->CBaseEdict;
          if ( v12 != nullptr )
            CBaseEdict::StateChanged(this: v12, offset: 0x354u);
        }
        v11->m_iMaterialName.m_Value = iMaterialName;
      }
      v11->m_Info.m_strMaterialName.pszValue = info->m_strMaterialName.pszValue;
      v11->m_Info.m_flLifetime.m_Value = info->m_flLifetime.m_Value;
      v11->m_Info.m_flStartSize.m_Value = info->m_flStartSize.m_Value;
      v13 = v11->m_Info.__vftable;
      v11->m_Info.m_flEndSize.m_Value = info->m_flEndSize.m_Value;
      ((void (*)(void))v13->NetworkStateChanged_2)();
      v11->m_nRefCount = 1;
      CBaseParticleEntity::FollowEntity(this: v11, pEntity: pTarget);
      g_pNotify->AddEntity(this: g_pNotify, a2: v11, a3: pTarget);
      v11->Spawn(this: v11);
      return v11;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10402480
// Name: CEntityParticleTrail_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CEntityParticleTrail_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CEntityParticleTrail>();
  CEntityParticleTrail_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104024B0
// Name: DT_EntityParticleTrail::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_EntityParticleTrail::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_EntityParticleTrail::g_SendTable);
  return atexit(func: DT_EntityParticleTrail::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104024D0
// Name: DT_EntityParticleTrail::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_EntityParticleTrail::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_EntityParticleTrail::ignored>();
  DT_EntityParticleTrail::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041AC90
// Name: DT_EntityParticleTrail::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_EntityParticleTrail::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_EntityParticleTrail::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10110740
// Name: class CEntityParticleTrail __near * _CreateEntityTemplate<class CEntityParticleTrail>(class CEntityParticleTrail __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CEntityParticleTrail *__cdecl _CreateEntityTemplate<CEntityParticleTrail>(
        CEntityParticleTrail *newEnt,
        const char *className)
{
  CBaseParticleEntity *v2; // eax
  CBaseParticleEntity *v3; // esi

  v2 = (CBaseParticleEntity *)CBaseEntity::operator new(stAllocateBlock: 0x374u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseParticleEntity::CBaseParticleEntity(this: v2);
    v3->__vftable = (CBaseParticleEntity_vtbl *)&CEntityParticleTrail::`vftable';
    EntityParticleTrailInfo_t::EntityParticleTrailInfo_t(this: (EntityParticleTrailInfo_t *)&v3[1].m_pfnMoveDone);
    v3[1].m_pfnMoveDone = (void (__thiscall *)(CBaseEntity *))&CEntityParticleTrail::NetworkVar_m_Info::`vftable';
    v3[1].m_Network.m_pPev = (edict_t *)-1;
    v3->PostConstructor(this: v3, a2: className);
    return (CEntityParticleTrail *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10402490
// Name: _dynamic_initializer_for__g_CEntityParticleTrail_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CEntityParticleTrail_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CEntityParticleTrail_ClassReg,
           pNetworkName: "CEntityParticleTrail",
           pTable: &DT_EntityParticleTrail::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x104024E0
// Name: _dynamic_initializer_for__env_particle_trail__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_particle_trail__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CEntityParticleTrail> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_particle_trail,
           a3: "env_particle_trail");
}

//------------------------------------------------------------------------------
// Address: 0x1041ACA0
// Name: _ServerClassInit_DT_EntityParticleTrail::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_EntityParticleTrail::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S3_45;
  for ( i = 4; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041ACC0
// Name: _DataMapInit_CEntityParticleTrail__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CEntityParticleTrail__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_155);
}
