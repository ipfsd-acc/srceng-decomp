// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/ragdollboogie.cpp
// Functions: 15
// ============================================================

#include "game\server\ragdollboogie.h"

//------------------------------------------------------------------------------
// Address: 0x101F3C50
// Name: private: virtual struct datamap_t __near * CRagdollBoogie::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CRagdollBoogie::GetDataDescMap(CRagdollBoogie *this)
{
  return &CRagdollBoogie::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101F3C60
// Name: float SimpleSplineRemapVal(float,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl SimpleSplineRemapVal(float val, float A, float B, float C, float D)
{
  float cVal; // [esp+10h] [ebp+10h]

  if ( A == B )
  {
    if ( val < B )
      return C;
    else
      return D;
  }
  else
  {
    cVal = (float)(val - A) / (float)(B - A);
    return C + (D - C) * (3.0 * (float)(cVal * cVal) - ((float)(cVal * cVal) + (float)(cVal * cVal)) * cVal);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F3CE0
// Name: public: virtual void CRagdollBoogie::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRagdollBoogie::Precache(CRagdollBoogie *this)
{
  PrecacheEffect(pEffectName: "TeslaHitboxes");
}

//------------------------------------------------------------------------------
// Address: 0x101F3CF0
// Name: private: void CRagdollBoogie::ZapThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRagdollBoogie::ZapThink(CRagdollBoogie *this)
{
  unsigned int m_Index; // ecx
  int v3; // eax
  CEntInfo *v4; // edx
  unsigned int v5; // ecx
  int v6; // eax
  bool v7; // zf
  CEntInfo *v8; // eax
  IHandleEntity *v9; // ecx
  int v10; // eax
  CBaseAnimating *v11; // esi
  CStudioHdr *m_pStudioHdr; // edi
  CBaseEntity *MoveParent; // eax
  unsigned int v14; // eax
  float v15; // xmm0_4
  float thinkTime; // [esp+8h] [ebp-78h]
  const char *v17; // [esp+Ch] [ebp-74h]
  CEffectData data; // [esp+1Ch] [ebp-64h] BYREF

  m_Index = this->m_hMoveParent.m_Value.m_Index;
  if ( m_Index != -1 )
  {
    v3 = (unsigned __int16)m_Index;
    v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v5 = HIWORD(m_Index);
    if ( v4->m_SerialNumber == v5 && v4->m_pEntity != nullptr )
    {
      v6 = v3;
      v7 = g_pEntityList->m_EntPtrArray[v6].m_SerialNumber == v5;
      v8 = &g_pEntityList->m_EntPtrArray[v6];
      v9 = v7 ? v8->m_pEntity : nullptr;
      v10 = (int)v9->__vftable[17].GetRefEHandle(this: v9);
      v11 = (CBaseAnimating *)v10;
      if ( v10 != 0 )
      {
        if ( *(_DWORD *)(v10 + 1144) == 0 && CBaseEntity::GetModel(this: (CBaseEntity *)v10) != nullptr )
          CBaseAnimating::LockStudioHdr(this: v11);
        m_pStudioHdr = v11->m_pStudioHdr;
        if ( m_pStudioHdr != nullptr
          && m_pStudioHdr->m_pStudioHdr != nullptr
          && *(int *)((char *)&m_pStudioHdr->m_pStudioHdr->version
                    + 12 * CBaseAnimating::GetHitboxSet(this: v11)
                    + m_pStudioHdr->m_pStudioHdr->hitboxsetindex) != 0 )
        {
          if ( this->m_nSuppressionCount == 0 )
          {
            CEffectData::CEffectData(this: &data);
            MoveParent = CBaseEntity::GetMoveParent(this);
            data.m_nEntIndex = (int)CBaseEntity::entindex(this: MoveParent);
            v14 = (unsigned int)this->m_spawnflags.m_Value >> 17;
            data.m_flMagnitude = 4.0;
            if ( (v14 & 1) != 0 )
              v15 = 1.0;
            else
              v15 = 2.0;
            data.m_flScale = v15;
            DispatchEffect(pName: "TeslaHitboxes", &data);
          }
          v17 = s_pZapContext;
          thinkTime = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                        a1: random,
                        a2: 1036831949,
                        a3: 1050253722)
                    + gpGlobals->curtime;
          CBaseEntity::ThinkSet(
            this,
            func: (void (__thiscall *)(CBaseEntity *))CRagdollBoogie::ZapThink,
            thinkTime,
            szContext: v17);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F3E70
// Name: public: static void CRagdollBoogie::IncrementSuppressionCount(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRagdollBoogie::IncrementSuppressionCount(CBaseEntity *pTarget)
{
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // esi
  _DWORD *v3; // eax
  IHandleEntity_vtbl *v4; // eax
  IHandleEntity *v5; // eax

  m_Index = pTarget->m_hMoveChild.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  if ( m_pEntity != nullptr )
  {
    do
    {
      v3 = __RTDynamicCast(
             inptr: m_pEntity,
             VfDelta: 0,
             SrcType: &CBaseEntity `RTTI Type Descriptor',
             TargetType: &CRagdollBoogie `RTTI Type Descriptor',
             isReference: 0);
      if ( v3 != nullptr )
        ++v3[216];
      v4 = m_pEntity[56].__vftable;
      if ( v4 == (IHandleEntity_vtbl *)-1
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_SerialNumber != (unsigned int)v4 >> 16 )
      {
        v5 = nullptr;
      }
      else
      {
        v5 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_pEntity;
      }
      m_pEntity = v5;
    }
    while ( v5 != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F3F10
// Name: public: static void CRagdollBoogie::DecrementSuppressionCount(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRagdollBoogie::DecrementSuppressionCount(CBaseEntity *pTarget)
{
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // edx
  IHandleEntity_vtbl *v3; // eax
  IHandleEntity *v4; // esi
  IServerNetworkable *v5; // eax

  m_Index = pTarget->m_hMoveChild.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  if ( m_pEntity != nullptr )
  {
    do
    {
      v3 = m_pEntity[56].__vftable;
      if ( v3 == (IHandleEntity_vtbl *)-1
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)v3].m_SerialNumber != (unsigned int)v3 >> 16 )
      {
        v4 = nullptr;
      }
      else
      {
        v4 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v3].m_pEntity;
      }
      v5 = (IServerNetworkable *)__RTDynamicCast(
                                   inptr: m_pEntity,
                                   VfDelta: 0,
                                   SrcType: &CBaseEntity `RTTI Type Descriptor',
                                   TargetType: &CRagdollBoogie `RTTI Type Descriptor',
                                   isReference: 0);
      if ( v5 != nullptr && (int)--v5[216].__vftable <= 0 )
      {
        v5[216].__vftable = nullptr;
        if ( (float)(gpGlobals->curtime - *(float *)&v5[213].__vftable) >= *(float *)&v5[214].__vftable )
          PhysCallbackRemove(pRemove: v5 + 3);
      }
      m_pEntity = v4;
    }
    while ( v4 != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F3FF0
// Name: private: void CRagdollBoogie::AttachToEntity(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRagdollBoogie::AttachToEntity(CRagdollBoogie *this, CBaseEntity *pTarget)
{
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // esi
  unsigned int v5; // eax
  IHandleEntity *v6; // edi
  _DWORD *v7; // eax

  this->m_nSuppressionCount = 0;
  m_Index = pTarget->m_hMoveChild.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  if ( m_pEntity != nullptr )
  {
    do
    {
      v5 = m_pEntity->m_hMovePeer.m_Index;
      if ( v5 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_SerialNumber != HIWORD(v5) )
        v6 = nullptr;
      else
        v6 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_pEntity;
      v7 = __RTDynamicCast(
             inptr: m_pEntity,
             VfDelta: 0,
             SrcType: &CBaseEntity `RTTI Type Descriptor',
             TargetType: &CRagdollBoogie `RTTI Type Descriptor',
             isReference: 0);
      if ( v7 != nullptr )
      {
        this->m_nSuppressionCount = v7[216];
        UTIL_Remove(oldObj: m_pEntity);
      }
      m_pEntity = (CBaseEntity *)v6;
    }
    while ( v6 != nullptr );
  }
  CBaseEntity::FollowEntity(this, pBaseEntity: pTarget, bBoneMerge: true);
}

//------------------------------------------------------------------------------
// Address: 0x101F40C0
// Name: private: void CRagdollBoogie::BoogieThink(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CRagdollBoogie::BoogieThink(CRagdollBoogie *this@<ecx>, int a2@<edi>)
{
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  CRagdollProp *v5; // esi
  float m_flBoogieLength; // xmm1_4
  float v7; // xmm0_4
  int v8; // edi
  IPhysicsObject **p_pObject; // esi
  IUniformRandomStream *v10; // ecx
  IUniformRandomStream *v11; // ecx
  IUniformRandomStream *v12; // ecx
  int v13; // [esp+8h] [ebp-34h]
  float v14; // [esp+10h] [ebp-2Ch]
  float vecForce_8; // [esp+1Ch] [ebp-20h]
  CRagdollProp *pRagdoll; // [esp+2Ch] [ebp-10h]
  float flMass; // [esp+30h] [ebp-Ch]
  float flForce; // [esp+38h] [ebp-4h]

  m_Index = this->m_hMoveParent.m_Value.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  v5 = (CRagdollProp *)__RTDynamicCast(
                         inptr: m_pEntity,
                         VfDelta: 0,
                         SrcType: &CBaseEntity `RTTI Type Descriptor',
                         TargetType: &CRagdollProp `RTTI Type Descriptor',
                         isReference: 0);
  pRagdoll = v5;
  if ( v5 == nullptr )
  {
    UTIL_Remove(oldObj: this);
    return;
  }
  m_flBoogieLength = this->m_flBoogieLength;
  if ( m_flBoogieLength == 0.0 )
    goto LABEL_13;
  v7 = gpGlobals->curtime - this->m_flStartTime;
  if ( v7 < m_flBoogieLength )
  {
    if ( v7 < 0.0 )
    {
LABEL_17:
      v14 = ((double (__thiscall *)(IUniformRandomStream *))random->RandomFloat)(a1: random) + gpGlobals->curtime;
      CBaseEntity::SetNextThink(this, thinkTime: v14, szContext: (const char *)0x3DCCCCCD);
      return;
    }
LABEL_13:
    if ( this->m_nSuppressionCount == 0 )
    {
      v13 = a2;
      v8 = 0;
      if ( v5->m_ragdoll.listCount > 0 )
      {
        p_pObject = &v5->m_ragdoll.list[0].pObject;
        do
        {
          flMass = ((double (__thiscall *)(IPhysicsObject *, int))(*p_pObject)->GetMass)(a1: *p_pObject, a2: v13);
          flForce = this->m_flMagnitude * flMass;
          _RandomFloat(this: v10, a2: COERCE_FLOAT(LODWORD(flForce) ^ _mask__NegFloat_), a3: flForce);
          _RandomFloat(this: v11, a2: COERCE_FLOAT(LODWORD(flForce) ^ _mask__NegFloat_), a3: flForce);
          vecForce_8 = _RandomFloat(this: v12, a2: COERCE_FLOAT(LODWORD(flForce) ^ _mask__NegFloat_), a3: flForce);
          (*p_pObject)->ApplyForceCenter(this: *p_pObject, a2: (const Vector *)LODWORD(vecForce_8));
          ++v8;
          p_pObject += 6;
        }
        while ( v8 < pRagdoll->m_ragdoll.listCount );
      }
    }
    goto LABEL_17;
  }
  if ( this->m_nSuppressionCount == 0 )
    UTIL_Remove(oldObj: this);
  CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101F42F0
// Name: public: virtual void CRagdollBoogie::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRagdollBoogie::Spawn(CRagdollBoogie *this)
{
  float thinkTime; // [esp+8h] [ebp-Ch]
  const char *v3; // [esp+Ch] [ebp-8h]

  this->Precache(this);
  CAI_BaseNPC::OnSetSchedule((vgui::Panel *)this);
  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CRagdollBoogie::BoogieThink,
    thinkTime: 0.0,
    szContext: nullptr);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.0099999998, szContext: nullptr);
  if ( (this->m_spawnflags.m_Value & 0x10000) != 0 )
  {
    v3 = s_pZapContext;
    thinkTime = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                  a1: random,
                  a2: 1036831949,
                  a3: 1050253722)
              + gpGlobals->curtime;
    CBaseEntity::ThinkSet(
      this,
      func: (void (__thiscall *)(CBaseEntity *))CRagdollBoogie::ZapThink,
      thinkTime,
      szContext: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F4390
// Name: public: static class CRagdollBoogie __near * CRagdollBoogie::Create(class CBaseEntity __near *,float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
IServerNetworkable *__cdecl CRagdollBoogie::Create(
        CBaseEntity *pTarget,
        float flMagnitude,
        float flStartTime,
        float flLengthTime,
        int nSpawnFlags)
{
  IServerNetworkable *result; // eax
  CRagdollBoogie *v6; // esi
  int v7; // eax
  int v8; // ebx
  CBaseEdict *v9; // ecx
  void (__thiscall *Spawn)(struct CRagdollBoogie *); // eax

  result = (IServerNetworkable *)__RTDynamicCast(
                                   inptr: pTarget,
                                   VfDelta: 0,
                                   SrcType: &CBaseEntity `RTTI Type Descriptor',
                                   TargetType: &CRagdollProp `RTTI Type Descriptor',
                                   isReference: 0);
  if ( result != nullptr )
  {
    result = CreateEntityByName(className: "env_ragdoll_boogie", iForceEdictIndex: -1, bNotify: true);
    v6 = (CRagdollBoogie *)result;
    if ( result != nullptr )
    {
      v7 = (int)result[190].__vftable;
      v8 = nSpawnFlags | v7;
      if ( v7 != (nSpawnFlags | v7) )
      {
        if ( v6->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&v6->m_Network + 76) |= 1u;
        }
        else
        {
          v9 = &v6->m_Network.m_pPev->CBaseEdict;
          if ( v9 != nullptr )
            CBaseEdict::StateChanged(this: v9, offset: 0x2F8u);
        }
        v6->m_spawnflags.m_Value = v8;
      }
      CRagdollBoogie::AttachToEntity(this: v6, pTarget);
      Spawn = v6->Spawn;
      v6->m_flStartTime = flStartTime;
      v6->m_flBoogieLength = flLengthTime;
      v6->m_flMagnitude = flMagnitude;
      Spawn(this: v6);
      return (IServerNetworkable *)v6;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104095D0
// Name: CRagdollBoogie_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CRagdollBoogie_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CRagdollBoogie>(__formal: nullptr);
  CRagdollBoogie_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F4450
// Name: struct datamap_t __near * DataMapInit<class CRagdollBoogie>(class CRagdollBoogie __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CRagdollBoogie>()
{
  if ( (_S2_192 & 1) == 0 )
  {
    _S2_192 |= 1u;
    nameHolder_364.m_pszBase = "CRagdollBoogie";
    nameHolder_364.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_364.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_364.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_364.m_Names.m_Size = 0;
    nameHolder_364.m_Names.m_pElements = nullptr;
    nameHolder_364.m_nLenBase = 14;
    atexit(func: DataMapInit_CRagdollBoogie__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CRagdollBoogie::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S2_192 & 2) == 0 )
  {
    _S2_192 |= 2u;
    dataDesc_347[4].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_364,
                                  pszIdentifier: "BoogieThink");
    dataDesc_347[4].flags = 32;
    dataDesc_347[4].fieldOffset = 0;
    dataDesc_347[4].fieldSize = 1;
    dataDesc_347[4].externalName = nullptr;
    dataDesc_347[4].pSaveRestoreOps = nullptr;
    dataDesc_347[4].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CRagdollBoogie::BoogieThink;
    *(_QWORD *)&dataDesc_347[4].td = 0;
    *(_QWORD *)&dataDesc_347[4].override_field = 0;
    *(_QWORD *)&dataDesc_347[4].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_347[4].flatOffset[1] = 0;
    dataDesc_347[5].fieldType = FIELD_VOID;
    dataDesc_347[5].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_364,
                                  pszIdentifier: "ZapThink");
    dataDesc_347[5].fieldOffset = 0;
    *(_DWORD *)&dataDesc_347[5].fieldSize = 2097153;
    dataDesc_347[5].externalName = nullptr;
    dataDesc_347[5].pSaveRestoreOps = nullptr;
    dataDesc_347[5].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CRagdollBoogie::ZapThink;
    *(_QWORD *)&dataDesc_347[5].td = 0;
    *(_QWORD *)&dataDesc_347[5].override_field = 0;
    *(_QWORD *)&dataDesc_347[5].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_347[5].flatOffset[1] = 0;
  }
  CRagdollBoogie::m_DataMap.dataNumFields = 5;
  CRagdollBoogie::m_DataMap.dataDesc = &dataDesc_347[1];
  return &CRagdollBoogie::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x104095E0
// Name: _dynamic_initializer_for__env_ragdoll_boogie__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__env_ragdoll_boogie__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CRagdollBoogie> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &env_ragdoll_boogie,
           a3: "env_ragdoll_boogie");
}

//------------------------------------------------------------------------------
// Address: 0x10409600
// Name: _dynamic_initializer_for__g_RecipientFilterPredictionSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_RecipientFilterPredictionSystem__()
{
  g_RecipientFilterPredictionSystem.m_pNextSystem = IPredictionSystem::g_pPredictionSystems;
  IPredictionSystem::g_pPredictionSystems = &g_RecipientFilterPredictionSystem;
  return atexit(func: dynamic_atexit_destructor_for__g_RecipientFilterPredictionSystem__);
}

//------------------------------------------------------------------------------
// Address: 0x10409620
// Name: _dynamic_initializer_for__g_Registry__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Registry__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_Registry__);
}
