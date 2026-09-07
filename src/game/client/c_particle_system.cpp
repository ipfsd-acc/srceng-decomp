// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_particle_system.cpp
// Functions: 22
// ============================================================

#include "game\client\c_particle_system.h"

//------------------------------------------------------------------------------
// Address: 0x10078B50
// Name: public: virtual class ClientClass __near * C_ParticleSystem::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_ParticleSystem::GetClientClass(C_ParticleSystem *this)
{
  return &__g_C_ParticleSystemClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10078E20
// Name: public: virtual void C_ParticleSystem::PreDataUpdate(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_ParticleSystem::PreDataUpdate(C_ParticleSystem *this, DataUpdateType_t updateType)
{
  BYTE1(this->m_iEffectIndex) = this->m_iEffectIndex;
  C_BaseEntity::PreDataUpdate(this, updateType);
}

//------------------------------------------------------------------------------
// Address: 0x10078E40
// Name: public: CParticleSnapshot::CParticleSnapshot(void)
// Source: json
//------------------------------------------------------------------------------
CParticleSnapshot *__thiscall CParticleSnapshot::CParticleSnapshot(CParticleSnapshot *this)
{
  memset(
    dst: (int)this->m_Container.m_nDataType,
    value: (unsigned __int8 *)0xFF,
    count: sizeof(this->m_Container.m_nDataType));
  memset(
    dst: (int)this->m_Container.m_pSeparateDataMemory,
    value: nullptr,
    count: sizeof(this->m_Container.m_pSeparateDataMemory));
  this->m_Container.m_pConstantDataMemory = nullptr;
  this->m_Container.m_pDataMemory = nullptr;
  this->m_Container.m_nNumQuadsPerRow = 0;
  this->m_Container.m_nSlices = 0;
  this->m_Container.m_nRows = 0;
  this->m_Container.m_nPaddedColumns = 0;
  this->m_Container.m_nColumns = 0;
  this->m_Container.m_nFieldPresentMask = 0;
  this->m_Container.m_eThreadMode = SOATHREADMODE_NONE;
  CParticleSnapshot::Purge(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10078EA0
// Name: public: void CParticleCollection::SetControlPointParent(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleCollection::SetControlPointParent(CParticleCollection *this, int nWhichPoint, int n)
{
  int m_nNumControlPointsAllocated; // eax
  int v4; // eax
  int m_nHighestCP; // eax
  CParticleCollection *i; // esi

  m_nNumControlPointsAllocated = this->m_nNumControlPointsAllocated;
  if ( nWhichPoint < m_nNumControlPointsAllocated )
  {
    v4 = m_nNumControlPointsAllocated - 1;
    if ( nWhichPoint < v4 )
      v4 = nWhichPoint;
    this->m_pCPInfo[v4].m_ControlPoint.m_nParent = n;
    m_nHighestCP = this->m_nHighestCP;
    if ( m_nHighestCP <= nWhichPoint )
      m_nHighestCP = nWhichPoint;
    this->m_nHighestCP = m_nHighestCP;
  }
  for ( i = this->m_Children.m_pHead; i != nullptr; i = i->m_pNext )
    CParticleCollection::SetControlPointParent(this: i, nWhichPoint, n);
}

//------------------------------------------------------------------------------
// Address: 0x10078F00
// Name: public: void CParticleCollection::SetControlPointSnapshot(int,class CParticleSnapshot __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleCollection::SetControlPointSnapshot(
        CParticleCollection *this,
        int nWhichPoint,
        CParticleSnapshot *pSnapshot)
{
  int m_nNumControlPointsAllocated; // eax
  int v4; // eax
  CParticleCollection *i; // esi

  m_nNumControlPointsAllocated = this->m_nNumControlPointsAllocated;
  if ( nWhichPoint < m_nNumControlPointsAllocated )
  {
    v4 = m_nNumControlPointsAllocated - 1;
    if ( nWhichPoint < v4 )
      v4 = nWhichPoint;
    this->m_pCPInfo[v4].m_ControlPoint.m_pSnapshot = pSnapshot;
  }
  for ( i = this->m_Children.m_pHead; i != nullptr; i = i->m_pNext )
    CParticleCollection::SetControlPointSnapshot(this: i, nWhichPoint, pSnapshot);
}

//------------------------------------------------------------------------------
// Address: 0x10078F50
// Name: public: void CNewParticleEffect::SetSortOrigin(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNewParticleEffect::SetSortOrigin(CNewParticleEffect *this, const Vector *vSortOrigin)
{
  this->m_vSortOrigin = *vSortOrigin;
}

//------------------------------------------------------------------------------
// Address: 0x10078F80
// Name: void ParticleEffectStopCallback(class CEffectData const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ParticleEffectStopCallback(const CEffectData *data)
{
  unsigned int m_Index; // ecx
  C_BaseEntity *v2; // eax
  C_BaseEntity *v3; // esi
  CParticleSystemDefinition *PrecachedParticleSystem; // eax
  const char *Name; // eax

  m_Index = data->m_hEntity.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
  {
    v2 = C_BaseEntity::Instance(hEnt: data->m_hEntity);
    v3 = v2;
    if ( v2 != nullptr )
    {
      if ( data->m_nHitBox <= 0 )
      {
        CParticleProperty::StopEmission(
          this: &v2->m_Particles,
          pEffect: nullptr,
          bWakeOnStop: true,
          bDestroyAsleepSystems: true,
          bForceRemoveInstantly: false,
          bPlayEndCap: true);
      }
      else if ( v2->entindex(this: &v2->IClientNetworkable) != 0 )
      {
        PrecachedParticleSystem = CParticleSystemMgr::FindPrecachedParticleSystem(
                                    this: g_pParticleSystemMgr,
                                    nPrecacheIndex: data->m_nHitBox);
        if ( PrecachedParticleSystem != nullptr )
        {
          Name = CParticleSystemDefinition::GetName(this: PrecachedParticleSystem);
          CParticleProperty::StopParticlesNamed(
            this: &v3->m_Particles,
            pszEffectName: Name,
            bForceRemoveInstantly: true,
            nSplitScreenPlayerSlot: -1);
        }
      }
      else if ( data->m_nHitBox > 0 )
      {
        CNewParticleEffect::RemoveParticleEffect(nPrecacheIndex: data->m_nHitBox);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10079040
// Name: public: virtual void C_ParticleSystem::PostDataUpdate(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_ParticleSystem::PostDataUpdate(C_ParticleSystem *this, DataUpdateType_t updateType)
{
  CParticleSnapshot *v3; // eax
  CUtlReference<CNewParticleEffect> *v4; // eax
  CFmtStrN<256> *v5; // eax
  CUtlReference<CNewParticleEffect> *m_pPrev; // edi
  char m_iEffectIndex; // al
  int v8; // eax
  int v9; // eax
  float *p_y; // edi
  const Vector *v11; // ebx
  CFmtStrN<256> v12; // [esp+Ch] [ebp-10Ch] BYREF

  C_BaseEntity::PostDataUpdate(this, updateType);
  if ( updateType != DATA_UPDATE_CREATED )
  {
    m_iEffectIndex = this->m_iEffectIndex;
    if ( BYTE1(this->m_iEffectIndex) != m_iEffectIndex )
    {
      if ( m_iEffectIndex != 0 )
      {
        (*(void (__stdcall **)(_DWORD))(*((_DWORD *)this - 2) + 456))(a1: *(_DWORD *)(gpGlobals.m_Index + 12));
      }
      else
      {
        v8 = *((_DWORD *)&this->m_bIsBlurred + 1);
        if ( v8 != 0 )
        {
          v9 = v8 - 1;
          if ( v9 != 0 )
          {
            if ( v9 == 1 )
              CParticleProperty::StopEmission(
                this: (CParticleProperty *)&this->m_Collision.m_vecSurroundingMaxs.y,
                pEffect: nullptr,
                bWakeOnStop: false,
                bDestroyAsleepSystems: false,
                bForceRemoveInstantly: false,
                bPlayEndCap: true);
          }
          else
          {
            CParticleProperty::StopEmissionAndDestroyImmediately(
              this: (CParticleProperty *)&this->m_Collision.m_vecSurroundingMaxs.y,
              pEffect: nullptr);
          }
        }
        else
        {
          CParticleProperty::StopEmission(
            this: (CParticleProperty *)&this->m_Collision.m_vecSurroundingMaxs.y,
            pEffect: nullptr,
            bWakeOnStop: false,
            bDestroyAsleepSystems: false,
            bForceRemoveInstantly: false,
            bPlayEndCap: false);
        }
      }
    }
    if ( LOBYTE(this->m_iEffectIndex) != 0
      && CParticleProperty::IsValidEffect(
           this: (CParticleProperty *)&this->m_Collision.m_vecSurroundingMaxs.y,
           pEffect: (const CNewParticleEffect *)this->m_pEffect.m_pNext) )
    {
      p_y = &this->m_vServerControlPoints[3].y;
      v11 = (const Vector *)&this->m_szSnapshotFileName[252];
      do
      {
        if ( *(_BYTE *)p_y == 0xFF )
          break;
        CNewParticleEffect::SetControlPoint(
          this: (CNewParticleEffect *)this->m_pEffect.m_pNext,
          nWhichPoint: *(unsigned __int8 *)p_y,
          v: v11);
        p_y = (float *)((char *)p_y + 1);
        ++v11;
      }
      while ( (float *)((char *)p_y - 2748 - (_DWORD)this) != (float *)4 );
    }
  }
  else
  {
    if ( this->m_bActive )
    {
      v3 = (CParticleSnapshot *)MemAlloc_Alloc(nSize: 0x408u);
      v4 = v3 != nullptr ? (CUtlReference<CNewParticleEffect> *)CParticleSnapshot::CParticleSnapshot(this: v3) : nullptr;
      this->m_pEffect.m_pPrev = v4;
      v5 = CFmtStrN<256>::CFmtStrN<256>(this: &v12, pszFormat: "particles/%s.psf", (const char *)&this->m_bActive);
      if ( !CParticleSnapshot::Unserialize(this: (CParticleSnapshot *)this->m_pEffect.m_pPrev, pFullPath: v5->m_szBuf) )
      {
        m_pPrev = this->m_pEffect.m_pPrev;
        if ( m_pPrev != nullptr )
        {
          CParticleSnapshot::Purge(this: (CParticleSnapshot *)this->m_pEffect.m_pPrev);
          CSOAContainer::~CSOAContainer(this: (CSOAContainer *)m_pPrev);
          C_BaseEntity::operator delete(pMem: m_pPrev);
        }
        this->m_pEffect.m_pPrev = nullptr;
      }
    }
    if ( LOBYTE(this->m_iEffectIndex) != 0 )
      (*(void (__stdcall **)(_DWORD))(*((_DWORD *)this - 2) + 456))(a1: *(_DWORD *)(gpGlobals.m_Index + 12));
  }
}

//------------------------------------------------------------------------------
// Address: 0x100791F0
// Name: public: C_ParticleSystem::C_ParticleSystem(void)
// Source: json
//------------------------------------------------------------------------------
C_ParticleSystem *__thiscall C_ParticleSystem::C_ParticleSystem(C_ParticleSystem *this)
{
  C_BaseEntity::C_BaseEntity(this);
  this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_ParticleSystem_vtbl *)&C_ParticleSystem::`vftable'{for `IClientUnknown'};
  this->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_ParticleSystem::`vftable'{for `IClientRenderable'};
  this->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_ParticleSystem::`vftable'{for `IClientNetworkable'};
  this->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_ParticleSystem::`vftable'{for `IClientThinkable'};
  this->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_ParticleSystem::`vftable';
  this->m_pEffect.m_pPrev = nullptr;
  this->m_pEffect.m_pNext = nullptr;
  this->m_pEffect.m_pObject = nullptr;
  this->m_pSnapshot = nullptr;
  memset((void *)this->m_hControlPointEnts, 0xFFu, sizeof(this->m_hControlPointEnts));
  memset(dst: (int)this->m_szSnapshotFileName, value: nullptr, count: sizeof(this->m_szSnapshotFileName));
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10079260
// Name: protected: virtual C_ParticleSystem::~C_ParticleSystem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_ParticleSystem::~C_ParticleSystem(C_ParticleSystem *this)
{
  CParticleSnapshot *m_pSnapshot; // edi
  CNewParticleEffect *m_pObject; // eax

  m_pSnapshot = this->m_pSnapshot;
  this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_ParticleSystem_vtbl *)&C_ParticleSystem::`vftable'{for `IClientUnknown'};
  this->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_ParticleSystem::`vftable'{for `IClientRenderable'};
  this->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_ParticleSystem::`vftable'{for `IClientNetworkable'};
  this->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_ParticleSystem::`vftable'{for `IClientThinkable'};
  this->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_ParticleSystem::`vftable';
  if ( m_pSnapshot != nullptr )
  {
    CParticleSnapshot::Purge(this: m_pSnapshot);
    CSOAContainer::~CSOAContainer(this: &m_pSnapshot->m_Container);
    C_BaseEntity::operator delete(pMem: m_pSnapshot);
    this->m_pSnapshot = nullptr;
  }
  m_pObject = this->m_pEffect.m_pObject;
  if ( m_pObject != nullptr )
  {
    CUtlIntrusiveDList<CUtlReference<CNewParticleEffect>>::RemoveNode(
      this: (CUtlIntrusiveDList<CUtlReference<CSheet> > *)&m_pObject->m_References,
      which: (CUtlReference<CSheet> *)&this->m_pEffect);
    this->m_pEffect.m_pObject = nullptr;
  }
  C_BaseEntity::~C_BaseEntity(this);
}

//------------------------------------------------------------------------------
// Address: 0x100792E0
// Name: void StartParticleEffect(class CEffectData const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl StartParticleEffect(const CEffectData *data, int nSplitScreenPlayerSlot)
{
  unsigned int m_Index; // ecx
  C_BaseEntity *v3; // eax
  C_BaseEntity *v4; // edi
  CNewParticleEffect *Precached; // eax
  CUtlReference<CNewParticleEffect> *m_pHead; // ecx
  CNewParticleEffect *m_pObject; // ecx
  int m_nOtherEntIndex; // esi
  C_BaseEntity *BaseEntity; // eax
  CParticleSystemDefinition *PrecachedParticleSystem; // eax
  CNewParticleEffect *v11; // eax
  CUtlReference<CNewParticleEffect> *v12; // ecx
  Vector v13; // [esp-10h] [ebp-4Ch]
  Vector vecForward; // [esp+Ch] [ebp-30h] BYREF
  Vector vecRight; // [esp+18h] [ebp-24h] BYREF
  Vector vecUp; // [esp+24h] [ebp-18h] BYREF
  CUtlReference<CNewParticleEffect> pEffect; // [esp+30h] [ebp-Ch] BYREF

  if ( SuppressingParticleEffects() || data->m_nHitBox == 0 )
    return;
  if ( (data->m_fFlags & 1) != 0 )
  {
    m_Index = data->m_hEntity.m_Index;
    if ( m_Index != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
    {
      v3 = C_BaseEntity::Instance(hEnt: data->m_hEntity);
      v4 = v3;
      if ( v3 != nullptr && (!v3->IsDormant(this: &v3->IClientNetworkable) || (data->m_fFlags & 4) != 0) )
      {
        if ( (data->m_fFlags & 2) != 0 )
          CParticleProperty::StopEmission(
            this: &v4->m_Particles,
            pEffect: nullptr,
            bWakeOnStop: false,
            bDestroyAsleepSystems: false,
            bForceRemoveInstantly: false,
            bPlayEndCap: false);
        Precached = CParticleProperty::CreatePrecached(
                      this: &v4->m_Particles,
                      nPrecacheIndex: data->m_nHitBox,
                      iAttachType: (ParticleAttachment_t)data->m_nDamageType,
                      iAttachmentPoint: data->m_nAttachmentIndex,
                      vecOriginOffset: vec3_origin,
                      matOffset: nullptr);
        pEffect.m_pPrev = nullptr;
        pEffect.m_pNext = nullptr;
        pEffect.m_pObject = Precached;
        if ( Precached != nullptr )
        {
          pEffect.m_pNext = Precached->m_References.m_pHead;
          m_pHead = Precached->m_References.m_pHead;
          if ( m_pHead != nullptr )
            m_pHead->m_pPrev = &pEffect;
          pEffect.m_pPrev = nullptr;
          Precached->m_References.m_pHead = &pEffect;
          m_pObject = pEffect.m_pObject;
          if ( pEffect.m_pObject != nullptr )
          {
            if ( pEffect.m_pObject->m_pDef.m_pObject == nullptr )
              goto LABEL_23;
            if ( data->m_nDamageType == 2 )
            {
              CNewParticleEffect::SetDrawOnlyForSplitScreenUser(this: pEffect.m_pObject, nSlot: nSplitScreenPlayerSlot);
              CNewParticleEffect::SetSortOrigin(this: pEffect.m_pObject, vSortOrigin: &data->m_vOrigin);
              CNewParticleEffect::SetControlPoint(this: pEffect.m_pObject, nWhichPoint: 0, v: &data->m_vOrigin);
              CNewParticleEffect::SetControlPoint(this: pEffect.m_pObject, nWhichPoint: 1, v: &data->m_vStart);
              AngleVectors(angles: &data->m_vAngles, forward: &vecForward, right: &vecRight, up: &vecUp);
              CNewParticleEffect::SetControlPointOrientation(
                this: pEffect.m_pObject,
                nWhichPoint: 0,
                forward: &vecForward,
                right: &vecRight,
                up: &vecUp);
            }
            else
            {
              m_nOtherEntIndex = data->m_nOtherEntIndex;
              if ( m_nOtherEntIndex <= 0 )
                goto LABEL_23;
              BaseEntity = CClientEntityList::GetBaseEntity(
                             this: (CClientEntityList *)cl_entitylist.m_Index,
                             entnum: m_nOtherEntIndex);
              if ( BaseEntity != nullptr )
              {
                *(_QWORD *)&vecUp.x = 0;
                vecUp.z = 50.0;
                *(_QWORD *)&v13.x = 0;
                v13.z = 50.0;
                CParticleProperty::AddControlPoint(
                  this: &v4->m_Particles,
                  pEffect: pEffect.m_pObject,
                  iPoint: 1,
                  pEntity: BaseEntity,
                  iAttachType: PATTACH_ABSORIGIN_FOLLOW,
                  pszAttachmentName: nullptr,
                  vecOriginOffset: v13,
                  matOffset: nullptr);
              }
            }
            goto LABEL_22;
          }
        }
      }
    }
  }
  else
  {
    PrecachedParticleSystem = CParticleSystemMgr::FindPrecachedParticleSystem(
                                this: g_pParticleSystemMgr,
                                nPrecacheIndex: data->m_nHitBox);
    if ( PrecachedParticleSystem == nullptr )
    {
      _Warning(a1: "StartParticleEffect:  Failed to find precached particle system for %d!!\n", data->m_nHitBox);
      return;
    }
    v11 = CNewParticleEffect::CreateOrAggregate(
            pOwner: nullptr,
            pDef: PrecachedParticleSystem,
            vecAggregatePosition: &data->m_vOrigin,
            pDebugName: nullptr,
            nSplitScreenSlot: nSplitScreenPlayerSlot);
    pEffect.m_pPrev = nullptr;
    pEffect.m_pNext = nullptr;
    pEffect.m_pObject = v11;
    if ( v11 != nullptr )
    {
      pEffect.m_pNext = v11->m_References.m_pHead;
      v12 = v11->m_References.m_pHead;
      if ( v12 != nullptr )
        v12->m_pPrev = &pEffect;
      pEffect.m_pPrev = nullptr;
      v11->m_References.m_pHead = &pEffect;
      m_pObject = pEffect.m_pObject;
      if ( pEffect.m_pObject != nullptr )
      {
        if ( pEffect.m_pObject->m_pDef.m_pObject == nullptr )
        {
LABEL_23:
          if ( m_pObject != nullptr )
          {
            if ( pEffect.m_pPrev != nullptr )
            {
              pEffect.m_pPrev->m_pNext = pEffect.m_pNext;
              if ( pEffect.m_pNext != nullptr )
                pEffect.m_pNext->m_pPrev = pEffect.m_pPrev;
            }
            else if ( m_pObject->m_References.m_pHead == &pEffect )
            {
              m_pObject->m_References.m_pHead = pEffect.m_pNext;
              if ( pEffect.m_pNext != nullptr )
                pEffect.m_pNext->m_pPrev = nullptr;
            }
          }
          return;
        }
        CNewParticleEffect::SetSortOrigin(this: pEffect.m_pObject, vSortOrigin: &data->m_vOrigin);
        CNewParticleEffect::SetControlPoint(this: pEffect.m_pObject, nWhichPoint: 0, v: &data->m_vOrigin);
        CNewParticleEffect::SetControlPoint(this: pEffect.m_pObject, nWhichPoint: 1, v: &data->m_vStart);
        AngleVectors(angles: &data->m_vAngles, forward: &vecUp, right: &vecRight, up: &vecForward);
        CNewParticleEffect::SetControlPointOrientation(
          this: pEffect.m_pObject,
          nWhichPoint: 0,
          forward: &vecUp,
          right: &vecRight,
          up: &vecForward);
LABEL_22:
        m_pObject = pEffect.m_pObject;
        goto LABEL_23;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100795F0
// Name: void ParticleEffectCallback(class CEffectData const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ParticleEffectCallback(const CEffectData *data)
{
  g_pPrecacheSystem->EndLimitedResourceAccess(this: g_pPrecacheSystem);
  StartParticleEffect(data, nSplitScreenPlayerSlot: -1);
}

//------------------------------------------------------------------------------
// Address: 0x10079690
// Name: public: virtual void C_ParticleSystem::ClientThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_ParticleSystem::ClientThink(C_ParticleSystem *this)
{
  const char *ParticleSystemNameFromIndex; // eax
  CNewParticleEffect *v3; // esi
  CUtlIntrusiveDList<CUtlReference<CSheet> > *v4; // eax
  float *p_y; // edi
  CUtlReference<CNewParticleEffect> *m_pHead; // eax
  int v7; // edi
  CUtlReference<CNewParticleEffect> *v8; // ecx
  C_BaseEntity **v9; // eax
  unsigned __int8 v10; // al
  Vector *v11; // edi
  const Vector *v12; // ebx
  CUtlReference<CNewParticleEffect> *m_pNext; // ebx
  int m_nNumControlPointsAllocated; // eax
  CParticleCollection *i; // edi
  int flTimeDelta; // [esp+24h] [ebp-Ch]
  float flTimeDeltaa; // [esp+24h] [ebp-Ch]
  CUtlReference<CNewParticleEffect> **p_m_pPrev; // [esp+28h] [ebp-8h]

  if ( !*(&this->m_bIsBlurred + 4) )
    return;
  ParticleSystemNameFromIndex = GetParticleSystemNameFromIndex(nIndex: this->m_CalcAbsoluteVelocityMutex.m_depth);
  if ( ParticleSystemNameFromIndex == nullptr || *ParticleSystemNameFromIndex == 0 )
    return;
  v3 = CParticleProperty::Create(
         this: (CParticleProperty *)&this->m_Collision.m_vecSurroundingMaxs,
         pszParticleName: ParticleSystemNameFromIndex,
         iAttachType: PATTACH_ABSORIGIN_FOLLOW,
         iAttachmentPoint: -1,
         vecOriginOffset: vec3_origin,
         matOffset: nullptr);
  v4 = *(CUtlIntrusiveDList<CUtlReference<CSheet> > **)this->m_iServerControlPointAssignments;
  p_y = &this->m_vServerControlPoints[3].y;
  if ( v4 == (CUtlIntrusiveDList<CUtlReference<CSheet> > *)v3 )
    goto LABEL_11;
  if ( v4 != nullptr )
  {
    CUtlIntrusiveDList<CUtlReference<CNewParticleEffect>>::RemoveNode(
      this: v4 + 232,
      which: (CUtlReference<CSheet> *)&this->m_vServerControlPoints[3].y);
    *(_DWORD *)this->m_iServerControlPointAssignments = 0;
  }
  *(_DWORD *)this->m_iServerControlPointAssignments = v3;
  if ( v3 != nullptr )
  {
    *p_y = *(float *)&v3->m_References.m_pHead;
    m_pHead = v3->m_References.m_pHead;
    if ( m_pHead != nullptr )
      m_pHead->m_pPrev = (CUtlReference<CNewParticleEffect> *)p_y;
    this->m_vServerControlPoints[3].z = 0.0;
    v3->m_References.m_pHead = (CUtlReference<CNewParticleEffect> *)p_y;
LABEL_11:
    if ( v3 != nullptr )
    {
      v7 = 1;
      p_m_pPrev = &this->m_pEffect.m_pPrev;
      for ( flTimeDelta = 63; flTimeDelta != 0; --flTimeDelta )
      {
        v8 = *p_m_pPrev;
        if ( *p_m_pPrev != (CUtlReference<CNewParticleEffect> *)-1 )
        {
          v9 = (C_BaseEntity **)&g_pEntityList->m_EntPtrArray[(unsigned __int16)v8];
          if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)v8].m_SerialNumber == (unsigned int)v8 >> 16
            && *v9 != nullptr )
          {
            CParticleProperty::AddControlPoint(
              this: (CParticleProperty *)&this->m_Collision.m_vecSurroundingMaxs,
              pEffect: v3,
              iPoint: v7,
              pEntity: *v9,
              iAttachType: PATTACH_ABSORIGIN_FOLLOW,
              pszAttachmentName: nullptr,
              vecOriginOffset: vec3_origin,
              matOffset: nullptr);
          }
        }
        v10 = *((_BYTE *)&this->m_hControlPointEnts[59].m_Index + v7 + 3);
        if ( v10 != 0 )
          CParticleCollection::SetControlPointParent(this: &v3->CParticleCollection, nWhichPoint: v7, n: v10);
        ++p_m_pPrev;
        ++v7;
      }
      v11 = &this->m_vServerControlPoints[3];
      v12 = (const Vector *)&this->m_szSnapshotFileName[248];
      do
      {
        if ( LOBYTE(v11->x) == 0xFF )
          break;
        CNewParticleEffect::SetControlPoint(this: v3, nWhichPoint: LOBYTE(v11->x), v: v12);
        v11 = (Vector *)((char *)v11 + 1);
        ++v12;
      }
      while ( (Vector *)((char *)v11 - 2744 - (_DWORD)this) != (Vector *)4 );
      m_pNext = this->m_pEffect.m_pNext;
      if ( m_pNext != nullptr )
      {
        m_nNumControlPointsAllocated = v3->m_nNumControlPointsAllocated;
        if ( m_nNumControlPointsAllocated > 0 )
          v3->m_pCPInfo[m_nNumControlPointsAllocated - 1 > 0 ? 0 : m_nNumControlPointsAllocated - 1].m_ControlPoint.m_pSnapshot = (CParticleSnapshot *)m_pNext;
        for ( i = v3->m_Children.m_pHead; i != nullptr; i = i->m_pNext )
          CParticleCollection::SetControlPointSnapshot(this: i, nWhichPoint: 0, pSnapshot: (CParticleSnapshot *)m_pNext);
      }
      CParticleProperty::OnParticleSystemUpdated(
        this: (CParticleProperty *)&this->m_Collision.m_vecSurroundingMaxs,
        pEffect: v3,
        flTimeDelta: 0.0);
      flTimeDeltaa = *(float *)(gpGlobals.m_Index + 12) - *(float *)&this->m_iEffectIndex;
      if ( flTimeDeltaa > 0.0099999998 )
      {
        CVProfile::EnterScope(
          this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
          a2: "C_ParticleSystem::ClientThink SkipToTime",
          a3: 0,
          a4: "Particle Simulation",
          a5: false,
          a6: 4);
        CParticleCollection::SkipToTime(this: &v3->CParticleCollection, t: flTimeDeltaa);
        CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104129B0
// Name: DT_ParticleSystem::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_ParticleSystem::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_ParticleSystem::g_RecvTable);
  return atexit(func: DT_ParticleSystem::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104129D0
// Name: DT_ParticleSystem::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_ParticleSystem::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_ParticleSystem::ignored>();
  DT_ParticleSystem::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10412A00
// Name: ParticleEffectPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int ParticleEffectPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106EF254;
  ParticleEffectPrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106EF254;
  dword_106EF254 = (int)&ParticleEffectPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10412A40
// Name: ParticleEffectStopPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int ParticleEffectStopPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106EF254;
  ParticleEffectStopPrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106EF254;
  dword_106EF254 = (int)&ParticleEffectStopPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430710
// Name: DT_ParticleSystem::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_ParticleSystem::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_ParticleSystem::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10079610
// Name: _C_ParticleSystem_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_ParticleSystem_CreateObject(int entnum, int serialNum)
{
  C_ParticleSystem *v2; // eax
  C_ParticleSystem *v3; // eax
  C_ParticleSystem *v4; // esi

  v2 = (C_ParticleSystem *)C_BaseEntity::operator new(stAllocateBlock: 0xC18u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_ParticleSystem::C_ParticleSystem(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x104129E0
// Name: _dynamic_initializer_for__ClientEffectReg_ParticleEffectCallback__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CClientEffectRegistration *dynamic_initializer_for__ClientEffectReg_ParticleEffectCallback__()
{
  return CClientEffectRegistration::CClientEffectRegistration(
           this: &ClientEffectReg_ParticleEffectCallback,
           pEffectName: "ParticleEffect",
           fn: ParticleEffectCallback);
}

//------------------------------------------------------------------------------
// Address: 0x10412A20
// Name: _dynamic_initializer_for__ClientEffectReg_ParticleEffectStopCallback__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CClientEffectRegistration *dynamic_initializer_for__ClientEffectReg_ParticleEffectStopCallback__()
{
  return CClientEffectRegistration::CClientEffectRegistration(
           this: &ClientEffectReg_ParticleEffectStopCallback,
           pEffectName: "ParticleEffectStop",
           fn: ParticleEffectStopCallback);
}

//------------------------------------------------------------------------------
// Address: 0x10412A60
// Name: _dynamic_initializer_for____g_C_PhysBoxClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_PhysBoxClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_PhysBoxClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_PhysBoxClientClass;
  return result;
}
