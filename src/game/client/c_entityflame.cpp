// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_entityflame.cpp
// Functions: 15
// ============================================================

#include "game\client\c_entityflame.h"

//------------------------------------------------------------------------------
// Address: 0x10065700
// Name: public: virtual class ClientClass __near * C_EntityFlame::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_EntityFlame::GetClientClass(C_EntityFlame *this)
{
  return &__g_C_EntityFlameClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x100657B0
// Name: public: C_EntityFlame::C_EntityFlame(void)
// Source: json
//------------------------------------------------------------------------------
C_EntityFlame *__thiscall C_EntityFlame::C_EntityFlame(C_EntityFlame *this)
{
  C_BaseEntity::C_BaseEntity(this);
  this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_EntityFlame_vtbl *)&C_EntityFlame::`vftable'{for `IClientUnknown'};
  this->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_EntityFlame::`vftable'{for `IClientRenderable'};
  this->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_EntityFlame::`vftable'{for `IClientNetworkable'};
  this->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_EntityFlame::`vftable'{for `IClientThinkable'};
  this->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_EntityFlame::`vftable';
  this->m_hEntAttached.m_Index = -1;
  this->m_hEffect.m_pPrev = nullptr;
  this->m_hEffect.m_pNext = nullptr;
  this->m_hEffect.m_pObject = nullptr;
  this->m_hOldAttached.m_Index = -1;
  C_BaseEntity::AddToEntityList(this, listId: ENTITY_LIST_SIMULATE);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10065860
// Name: private: void C_EntityFlame::StopEffect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_EntityFlame::StopEffect(C_EntityFlame *this)
{
  CNewParticleEffect *m_pObject; // eax
  CNewParticleEffect *v3; // eax
  unsigned int m_Index; // ecx
  int v5; // eax
  CEntInfo *v6; // edx
  unsigned int v7; // ecx
  int v8; // eax
  bool v9; // zf
  C_BaseEntity **v10; // eax
  C_BaseEntity *v11; // eax
  unsigned int v12; // ecx
  C_BaseEntity *m_pEntity; // eax
  unsigned int v14; // ecx
  C_BaseEntity *v15; // eax
  unsigned int v16; // ecx
  C_BaseEntity *v17; // eax

  m_pObject = this->m_hEffect.m_pObject;
  if ( m_pObject != nullptr )
  {
    CParticleProperty::StopEmission(
      this: &this->m_Particles,
      pEffect: m_pObject,
      bWakeOnStop: true,
      bDestroyAsleepSystems: false,
      bForceRemoveInstantly: false,
      bPlayEndCap: false);
    v3 = this->m_hEffect.m_pObject;
    if ( v3 != nullptr )
    {
      CUtlIntrusiveDList<CUtlReference<CNewParticleEffect>>::RemoveNode(
        this: (CUtlIntrusiveDList<CUtlReference<CSheet> > *)&v3->m_References,
        which: (CUtlReference<CSheet> *)&this->m_hEffect);
      this->m_hEffect.m_pObject = nullptr;
    }
  }
  m_Index = this->m_hEntAttached.m_Index;
  if ( m_Index != -1 )
  {
    v5 = (unsigned __int16)m_Index;
    v6 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v7 = HIWORD(m_Index);
    if ( v6->m_SerialNumber == v7 && v6->m_pEntity != nullptr )
    {
      v8 = v5;
      v9 = g_pEntityList->m_EntPtrArray[v8].m_SerialNumber == v7;
      v10 = (C_BaseEntity **)&g_pEntityList->m_EntPtrArray[v8];
      if ( v9 )
        v11 = *v10;
      else
        v11 = nullptr;
      C_BaseEntity::RemoveFlag(this: v11, flagsToRemove: 0x10000000);
      v12 = this->m_hEntAttached.m_Index;
      if ( v12 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v12].m_SerialNumber != HIWORD(v12) )
        m_pEntity = nullptr;
      else
        m_pEntity = (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v12].m_pEntity;
      C_BaseEntity::SetEffectEntity(this: m_pEntity, pEffectEnt: nullptr);
      v14 = this->m_hEntAttached.m_Index;
      if ( v14 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v14].m_SerialNumber != HIWORD(v14) )
        v15 = nullptr;
      else
        v15 = (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v14].m_pEntity;
      C_BaseEntity::StopSound(this: v15, soundname: "General.BurningFlesh");
      v16 = this->m_hEntAttached.m_Index;
      if ( v16 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v16].m_SerialNumber != HIWORD(v16) )
        v17 = nullptr;
      else
        v17 = (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v16].m_pEntity;
      C_BaseEntity::StopSound(this: v17, soundname: "General.BurningObject");
      this->m_hEntAttached.m_Index = -1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100659B0
// Name: public: virtual void C_EntityFlame::UpdateOnRemove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_EntityFlame::UpdateOnRemove(C_EntityFlame *this)
{
  C_EntityFlame::StopEffect(this);
  C_BaseEntity::UpdateOnRemove(this);
}

//------------------------------------------------------------------------------
// Address: 0x100659C0
// Name: private: void C_EntityFlame::CreateEffect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_EntityFlame::CreateEffect(C_EntityFlame *this)
{
  CNewParticleEffect *m_pObject; // eax
  CNewParticleEffect *v3; // eax
  unsigned int m_Index; // ecx
  C_BaseEntity *m_pEntity; // eax
  const char *v6; // edx
  CNewParticleEffect *v7; // ebx
  CNewParticleEffect *v8; // eax
  CUtlReference<CNewParticleEffect> *p_m_hEffect; // edi
  CUtlReference<CNewParticleEffect> *m_pHead; // eax
  CNewParticleEffect *v11; // ecx
  CNewParticleEffect *v12; // ebx
  const Vector *v13; // eax
  CNewParticleEffect *v14; // ebx
  const Vector *v15; // eax
  C_BaseEntity *pEntity; // [esp+Ch] [ebp-4h]

  m_pObject = this->m_hEffect.m_pObject;
  if ( m_pObject != nullptr )
  {
    this->m_hOldAttached.m_Index = this->m_hEntAttached.m_Index;
    CParticleProperty::StopEmission(
      this: &this->m_Particles,
      pEffect: m_pObject,
      bWakeOnStop: true,
      bDestroyAsleepSystems: false,
      bForceRemoveInstantly: false,
      bPlayEndCap: false);
    v3 = this->m_hEffect.m_pObject;
    if ( v3 != nullptr )
    {
      CUtlIntrusiveDList<CUtlReference<CNewParticleEffect>>::RemoveNode(
        this: (CUtlIntrusiveDList<CUtlReference<CSheet> > *)&v3->m_References,
        which: (CUtlReference<CSheet> *)&this->m_hEffect);
      this->m_hEffect.m_pObject = nullptr;
    }
  }
  m_Index = this->m_hEntAttached.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
  {
    pEntity = nullptr;
  }
  else
  {
    m_pEntity = (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    pEntity = m_pEntity;
    if ( m_pEntity != nullptr && !C_BaseEntity::IsAbleToHaveFireEffect(this: m_pEntity) )
      return;
  }
  v6 = "burning_gib_01";
  if ( !this->m_bCheapEffect )
    v6 = "burning_character";
  v7 = CParticleProperty::Create(
         this: &this->m_Particles,
         pszParticleName: v6,
         iAttachType: PATTACH_ABSORIGIN_FOLLOW,
         iAttachmentPoint: -1,
         vecOriginOffset: vec3_origin,
         matOffset: nullptr);
  v8 = this->m_hEffect.m_pObject;
  p_m_hEffect = &this->m_hEffect;
  if ( v8 != v7 )
  {
    if ( v8 != nullptr )
    {
      CUtlIntrusiveDList<CUtlReference<CNewParticleEffect>>::RemoveNode(
        this: (CUtlIntrusiveDList<CUtlReference<CSheet> > *)&v8->m_References,
        which: (CUtlReference<CSheet> *)&this->m_hEffect);
      this->m_hEffect.m_pObject = nullptr;
    }
    this->m_hEffect.m_pObject = v7;
    if ( v7 != nullptr )
    {
      p_m_hEffect->m_pNext = v7->m_References.m_pHead;
      m_pHead = v7->m_References.m_pHead;
      if ( m_pHead != nullptr )
        m_pHead->m_pPrev = p_m_hEffect;
      this->m_hEffect.m_pPrev = nullptr;
      v7->m_References.m_pHead = p_m_hEffect;
    }
  }
  v11 = this->m_hEffect.m_pObject;
  if ( v11 != nullptr )
  {
    this->m_hOldAttached.m_Index = this->m_hEntAttached.m_Index;
    CParticleProperty::AddControlPoint(
      this: &this->m_Particles,
      pEffect: v11,
      iPoint: 1,
      pEntity,
      iAttachType: PATTACH_ABSORIGIN_FOLLOW,
      pszAttachmentName: nullptr,
      vecOriginOffset: vec3_origin,
      matOffset: nullptr);
    v12 = this->m_hEffect.m_pObject;
    v13 = this->GetAbsOrigin(this);
    CNewParticleEffect::SetControlPoint(this: v12, nWhichPoint: 0, v: v13);
    v14 = this->m_hEffect.m_pObject;
    v15 = this->GetAbsOrigin(this);
    CNewParticleEffect::SetControlPoint(this: v14, nWhichPoint: 1, v: v15);
    CNewParticleEffect::SetControlPointEntity(this: this->m_hEffect.m_pObject, nWhichPoint: 0, pEntity);
    CNewParticleEffect::SetControlPointEntity(this: this->m_hEffect.m_pObject, nWhichPoint: 1, pEntity);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10065B90
// Name: public: virtual void C_EntityFlame::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_EntityFlame::OnDataChanged(C_EntityFlame *this, DataUpdateType_t updateType)
{
  CUtlReference<CNewParticleEffect> *m_pPrev; // ecx
  IHandleEntity *m_pEntity; // edi
  unsigned int v5; // ecx
  IHandleEntity *v6; // eax

  if ( updateType == DATA_UPDATE_CREATED
    || updateType == DATA_UPDATE_DATATABLE_CHANGED
    && ((m_pPrev = this->m_hEffect.m_pPrev) == (CUtlReference<CNewParticleEffect> *)-1
     || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_pPrev].m_SerialNumber != (unsigned int)m_pPrev >> 16
      ? (m_pEntity = nullptr)
      : (m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_pPrev].m_pEntity),
        (v5 = *(_DWORD *)&this->m_bIsBlurred) == -1
     || g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_SerialNumber != HIWORD(v5)
      ? (v6 = nullptr)
      : (v6 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_pEntity),
        v6 != m_pEntity) )
  {
    C_EntityFlame::CreateEffect(this: (C_EntityFlame *)((char *)this - 8));
  }
  C_BaseEntity::OnDataChanged(this, type: updateType);
}

//------------------------------------------------------------------------------
// Address: 0x10065C20
// Name: public: virtual void C_EntityFlame::ClientThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_EntityFlame::ClientThink(C_EntityFlame *this)
{
  C_EntityFlame::StopEffect(this: (C_EntityFlame *)((char *)this - 12));
  (*(void (__thiscall **)(char *))(*((_DWORD *)this - 1) + 4))(a1: (char *)this - 4);
}

//------------------------------------------------------------------------------
// Address: 0x10065C40
// Name: public: virtual C_EntityFlame::~C_EntityFlame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_EntityFlame::~C_EntityFlame(C_EntityFlame *this)
{
  CNewParticleEffect *m_pObject; // eax

  this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_EntityFlame_vtbl *)&C_EntityFlame::`vftable'{for `IClientUnknown'};
  this->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_EntityFlame::`vftable'{for `IClientRenderable'};
  this->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_EntityFlame::`vftable'{for `IClientNetworkable'};
  this->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_EntityFlame::`vftable'{for `IClientThinkable'};
  this->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_EntityFlame::`vftable';
  C_EntityFlame::StopEffect(this);
  m_pObject = this->m_hEffect.m_pObject;
  if ( m_pObject != nullptr )
  {
    CUtlIntrusiveDList<CUtlReference<CNewParticleEffect>>::RemoveNode(
      this: (CUtlIntrusiveDList<CUtlReference<CSheet> > *)&m_pObject->m_References,
      which: (CUtlReference<CSheet> *)&this->m_hEffect);
    this->m_hEffect.m_pObject = nullptr;
  }
  C_BaseEntity::~C_BaseEntity(this);
}

//------------------------------------------------------------------------------
// Address: 0x10411A00
// Name: DT_EntityFlame::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_EntityFlame::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_EntityFlame::g_RecvTable);
  return atexit(func: DT_EntityFlame::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10411A20
// Name: DT_EntityFlame::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_EntityFlame::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_EntityFlame::ignored>();
  DT_EntityFlame::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430170
// Name: DT_EntityFlame::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_EntityFlame::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_EntityFlame::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10065810
// Name: _C_EntityFlame_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_EntityFlame_CreateObject(int entnum, int serialNum)
{
  C_EntityFlame *v2; // eax
  C_EntityFlame *v3; // eax
  C_EntityFlame *v4; // esi

  v2 = (C_EntityFlame *)C_BaseEntity::operator new(stAllocateBlock: 0x998u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_EntityFlame::C_EntityFlame(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x10411A30
// Name: _dynamic_initializer_for__cl_blobulator_freezing_max_metaball_radius__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_blobulator_freezing_max_metaball_radius__()
{
  ConVar::ConVar(
    this: &cl_blobulator_freezing_max_metaball_radius,
    pName: "cl_blobulator_freezing_max_metaball_radius",
    pDefaultValue: "12.0",
    flags: 0,
    pHelpString: "Setting this can create more complex surfaces on large hitboxes at the cost of performance.",
    bMin: true,
    fMin: 12.0,
    bMax: true,
    fMax: 100.0);
  return atexit(func: dynamic_atexit_destructor_for__cl_blobulator_freezing_max_metaball_radius__);
}

//------------------------------------------------------------------------------
// Address: 0x10411A80
// Name: _dynamic_initializer_for____g_C_EntityFreezingClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_EntityFreezingClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_EntityFreezingClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_EntityFreezingClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430180
// Name: _dynamic_atexit_destructor_for__cl_blobulator_freezing_max_metaball_radius__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_blobulator_freezing_max_metaball_radius__()
{
  ConVar::~ConVar(this: &cl_blobulator_freezing_max_metaball_radius);
}
