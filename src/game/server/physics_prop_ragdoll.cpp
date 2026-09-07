// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/physics_prop_ragdoll.cpp
// Functions: 67
// ============================================================

#include "game\server\physics_prop_ragdoll.h"

//------------------------------------------------------------------------------
// Address: 0x1019C6F0
// Name: public: virtual class ServerClass __near * CRagdollProp::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CRagdollProp::GetServerClass(CRagdollProp *this)
{
  return &g_CRagdollProp_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x1019C700
// Name: public: virtual struct datamap_t __near * CRagdollProp::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CRagdollProp::GetDataDescMap(CRagdollProp *this)
{
  return &CRagdollProp::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1019C710
// Name: public: virtual void CRagdollProp::OnSave(class IEntitySaveUtils __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRagdollProp::OnSave(CRagdollProp *this, IEntitySaveUtils *pUtils)
{
  int savedregs; // [esp+4h] [ebp+0h] BYREF

  if ( this->m_ragdoll.listCount != 0 )
  {
    CBaseEntity::VPhysicsSetObject(this, pPhysics: nullptr);
    CBaseEntity::VPhysicsSetObject(this, pPhysics: this->m_ragdoll.list[0].pObject);
    CBaseEntity::OnSave(this, a2: (int)&savedregs, pUtils);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019C750
// Name: public: virtual void CRagdollProp::UpdateOnRemove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRagdollProp::UpdateOnRemove(CRagdollProp *this)
{
  int v1; // esi
  ragdoll_t *p_m_ragdoll; // ebx
  IPhysicsObject **p_pObject; // edi
  CRagdollProp *v4; // [esp+8h] [ebp-4h]

  v1 = 0;
  p_m_ragdoll = &this->m_ragdoll;
  v4 = this;
  if ( this->m_ragdoll.listCount > 0 )
  {
    p_pObject = &this->m_ragdoll.list[0].pObject;
    do
    {
      if ( *p_pObject != nullptr )
      {
        g_pPhysSaveRestoreManager->ForgetModel(this: g_pPhysSaveRestoreManager, a2: *p_pObject);
        this = v4;
      }
      ++v1;
      p_pObject += 6;
    }
    while ( v1 < p_m_ragdoll->listCount );
  }
  CBaseEntity::VPhysicsSetObject(this, pPhysics: nullptr);
  RagdollDestroy(ragdoll: p_m_ragdoll);
  CBaseEntity::UpdateOnRemove(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x1019C7B0
// Name: public: virtual int CRagdollProp::ObjectCaps(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRagdollProp::ObjectCaps(CRagdollProp *this)
{
  return CBaseEntity::ObjectCaps(this) | 0x40000000;
}

//------------------------------------------------------------------------------
// Address: 0x1019C7C0
// Name: public: virtual void CRagdollProp::ModifyOrAppendCriteria(class ResponseRules::CriteriaSet __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRagdollProp::ModifyOrAppendCriteria(CRagdollProp *this, ResponseRules::CriteriaSet *set)
{
  const char *pszValue; // esi

  CBaseAnimating::ModifyOrAppendCriteria(this, set);
  if ( this->m_strSourceClassName.pszValue != nullptr )
  {
    ResponseRules::CriteriaSet::RemoveCriteria(this: set, criteria: "classname");
    pszValue = this->m_strSourceClassName.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    ResponseRules::CriteriaSet::AppendCriteria(this: set, pCriteriaName: "classname", value: pszValue, weight: 1.0);
    ResponseRules::CriteriaSet::AppendCriteria(this: set, pCriteriaName: "ragdoll", value: "1", weight: 1.0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019C840
// Name: public: bool CRagdollProp::HasPhysgunInteraction(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CRagdollProp::HasPhysgunInteraction(CRagdollProp *this, const char *pszKeyName, const char *pszValue)
{
  KeyValues *v4; // eax
  KeyValues *v5; // edi
  IVModelInfo_vtbl *v6; // ebx
  model_t *v7; // eax
  const char *v8; // eax
  KeyValues *Key; // eax
  const char *String; // eax
  int v12; // [esp-14h] [ebp-24h]
  const char *Model; // [esp-10h] [ebp-20h]

  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: locale);
  else
    v5 = nullptr;
  v6 = modelinfo->__vftable;
  Model = (const char *)CBaseEntity::GetModel(this);
  v12 = ((int (__thiscall *)(IVModelInfo *))v6->GetModelKeyValueText)(a1: modelinfo);
  v7 = CBaseEntity::GetModel(this);
  v8 = (const char *)((int (__thiscall *)(IVModelInfo *, model_t *, int))v6->GetModelName)(
                       a1: modelinfo,
                       a2: v7,
                       a3: v12);
  if ( KeyValues::LoadFromBuffer(
         this: v5,
         resourceName: v8,
         pBuffer: Model,
         pFileSystem: nullptr,
         pPathID: nullptr,
         pfnEvaluateSymbolProc: nullptr)
    && (Key = KeyValues::FindKey(this: v5, keyName: "physgun_interactions", bCreate: false)) != nullptr
    && (String = KeyValues::GetString(this: Key, keyName: pszKeyName, defaultValue: locale)) != nullptr
    && *String != 0
    && _V_stricmp(s1: String, s2: pszValue) == 0 )
  {
    KeyValues::deleteThis(this: v5);
    return 1;
  }
  else
  {
    KeyValues::deleteThis(this: v5);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019C910
// Name: public: virtual void CRagdollProp::TraceAttack(class CTakeDamageInfo const __near &,class Vector const __near &,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRagdollProp::TraceAttack(
        CRagdollProp *this,
        const CTakeDamageInfo *info,
        const Vector *dir,
        CGameTrace *ptr)
{
  __int16 physicsbone; // ax

  physicsbone = ptr->physicsbone;
  if ( physicsbone >= 0 && physicsbone < this->m_ragdoll.listCount )
    CBaseEntity::VPhysicsSwapObject(this, pSwap: this->m_ragdoll.list[physicsbone].pObject);
  CBaseEntity::TraceAttack(this, info, vecDir: dir, ptr);
}

//------------------------------------------------------------------------------
// Address: 0x1019C960
// Name: public: virtual int CRagdollProp::VPhysicsGetObjectList(class IPhysicsObject __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRagdollProp::VPhysicsGetObjectList(CRagdollProp *this, IPhysicsObject **pList, int listMax)
{
  int v3; // eax
  IPhysicsObject **p_pObject; // edx

  v3 = 0;
  if ( this->m_ragdoll.listCount > 0 )
  {
    p_pObject = &this->m_ragdoll.list[0].pObject;
    do
    {
      if ( v3 < listMax )
        pList[v3] = *p_pObject;
      ++v3;
      p_pObject += 6;
    }
    while ( v3 < this->m_ragdoll.listCount );
  }
  return this->m_ragdoll.listCount;
}

//------------------------------------------------------------------------------
// Address: 0x1019C9B0
// Name: public: virtual int CRagdollProp::DrawDebugTextOverlays(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRagdollProp::DrawDebugTextOverlays(CRagdollProp *this)
{
  int result; // eax
  bool v3; // zf
  int listCount; // ecx
  int v5; // ebx
  IPhysicsObject **p_pObject; // edi
  const char *MassEquivalent; // eax
  int v8; // edi
  char tempstr[512]; // [esp+20h] [ebp-208h] BYREF
  int text_offset; // [esp+220h] [ebp-8h]
  float mass; // [esp+224h] [ebp-4h]

  result = CBaseAnimating::DrawDebugTextOverlays(this);
  v3 = (this->m_debugOverlays & 1) == 0;
  text_offset = result;
  if ( !v3 )
  {
    listCount = this->m_ragdoll.listCount;
    if ( listCount != 0 )
    {
      v5 = 0;
      mass = 0.0;
      if ( listCount > 0 )
      {
        p_pObject = &this->m_ragdoll.list[0].pObject;
        do
        {
          if ( *p_pObject != nullptr )
            mass = ((double (__thiscall *)(IPhysicsObject *))(*p_pObject)->GetMass)(a1: *p_pObject) + mass;
          ++v5;
          p_pObject += 6;
        }
        while ( v5 < this->m_ragdoll.listCount );
      }
      MassEquivalent = GetMassEquivalent(flMass: mass);
      V_snprintf(
        pDest: tempstr,
        maxLen: 512,
        pFormat: "Mass: %.2f kg / %.2f lb (%s)",
        mass,
        (float)(mass * 2.2),
        MassEquivalent);
      v8 = text_offset;
      CBaseEntity::EntityText(this, text_offset, text: tempstr, duration: 0.0, r: 255, g: 255, b: 255, a: 255);
      return v8 + 1;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1019CAA0
// Name: public: virtual class ServerClass __near * CRagdollPropAttached::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CRagdollPropAttached::GetServerClass(CRagdollPropAttached *this)
{
  return &g_CRagdollPropAttached_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x1019CAB0
// Name: public: virtual struct datamap_t __near * CRagdollPropAttached::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CRagdollPropAttached::GetDataDescMap(CRagdollPropAttached *this)
{
  return &CRagdollPropAttached::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1019CAC0
// Name: bool Ragdoll_IsPropRagdoll(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl Ragdoll_IsPropRagdoll(CBaseEntity *pEntity)
{
  return __RTDynamicCast(
           inptr: pEntity,
           VfDelta: 0,
           SrcType: &CBaseEntity `RTTI Type Descriptor',
           TargetType: &CRagdollProp `RTTI Type Descriptor',
           isReference: 0) != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1019CAF0
// Name: struct ragdoll_t __near * Ragdoll_GetRagdoll(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
ragdoll_t *__cdecl Ragdoll_GetRagdoll(CBaseEntity *pEntity)
{
  char *v1; // eax

  v1 = (char *)__RTDynamicCast(
                 inptr: pEntity,
                 VfDelta: 0,
                 SrcType: &CBaseEntity `RTTI Type Descriptor',
                 TargetType: &CRagdollProp `RTTI Type Descriptor',
                 isReference: 0);
  if ( v1 != nullptr )
    return (ragdoll_t *)(v1 + 1168);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1019CB20
// Name: public: void CRagdollProp::DisableMotion(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRagdollProp::DisableMotion(CRagdollProp *this)
{
  int v2; // esi
  IPhysicsObject **p_pObject; // edi

  v2 = 0;
  if ( this->m_ragdoll.listCount > 0 )
  {
    p_pObject = &this->m_ragdoll.list[0].pObject;
    do
    {
      if ( *p_pObject != nullptr )
        (*p_pObject)->EnableMotion(this: *p_pObject, a2: false);
      ++v2;
      p_pObject += 6;
    }
    while ( v2 < this->m_ragdoll.listCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019CB60
// Name: public: void CRagdollProp::InputEnableMotion(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRagdollProp::InputEnableMotion(CRagdollProp *this, inputdata_t *inputdata)
{
  int v2; // edi
  IPhysicsObject **p_pObject; // ebx
  IPhysicsObject *v4; // esi
  CRagdollProp *v5; // [esp+4h] [ebp-4h]

  v2 = 0;
  v5 = this;
  if ( this->m_ragdoll.listCount > 0 )
  {
    p_pObject = &this->m_ragdoll.list[0].pObject;
    do
    {
      v4 = *p_pObject;
      if ( *p_pObject != nullptr )
      {
        v4->EnableMotion(this: v4, a2: true);
        v4->Wake(this: v4);
        this = v5;
      }
      ++v2;
      p_pObject += 6;
    }
    while ( v2 < this->m_ragdoll.listCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019CBC0
// Name: public: void CRagdollProp::InputDisableMotion(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRagdollProp::InputDisableMotion(CRagdollProp *this, inputdata_t *inputdata)
{
  int v3; // esi
  IPhysicsObject **p_pObject; // edi

  v3 = 0;
  if ( this->m_ragdoll.listCount > 0 )
  {
    p_pObject = &this->m_ragdoll.list[0].pObject;
    do
    {
      if ( *p_pObject != nullptr )
        (*p_pObject)->EnableMotion(this: *p_pObject, a2: false);
      ++v3;
      p_pObject += 6;
    }
    while ( v3 < this->m_ragdoll.listCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019CC10
// Name: public: virtual void CRagdollProp::OnRestore(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRagdollProp::OnRestore(CRagdollProp *this)
{
  IVModelInfo_vtbl *v2; // ebx
  int v3; // eax
  vcollide_t *v4; // eax
  int v5; // [esp-10h] [ebp-10h]

  this->m_ragdoll.list[0].pObject = this->m_pPhysicsObject;
  this->m_ragdoll.list[0].parentIndex = -1;
  this->m_ragdoll.list[0].originParentSpace.x = 0.0;
  this->m_ragdoll.list[0].originParentSpace.y = 0.0;
  this->m_ragdoll.list[0].originParentSpace.z = 0.0;
  CBaseAnimating::OnRestore(this);
  if ( this->m_ragdoll.listCount != 0 )
  {
    v2 = modelinfo->__vftable;
    v3 = this->GetModelIndex(this);
    v5 = ((int (__thiscall *)(CRagdollProp *, int))this->GetModelIndex)(a1: this, a2: v3);
    v4 = (vcollide_t *)((int (__thiscall *)(IVModelInfo *))v2->GetVCollide)(a1: modelinfo);
    RagdollSetupCollisions(ragdoll: &this->m_ragdoll, pCollide: v4, modelIndex: v5);
    this->VPhysicsUpdate(this, a2: this->m_pPhysicsObject);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019CCF0
// Name: public: void CRagdollProp::ClearFlagsThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRagdollProp::ClearFlagsThink(CRagdollProp *this)
{
  IPhysicsObject *m_pPhysicsObject; // esi
  unsigned __int16 v3; // ax

  m_pPhysicsObject = this->m_pPhysicsObject;
  v3 = m_pPhysicsObject->GetGameFlags(this: m_pPhysicsObject);
  m_pPhysicsObject->SetGameFlags(this: m_pPhysicsObject, a2: v3 & 0xFEFF);
  this->m_bFirstCollisionAfterLaunch = false;
  CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1019CD40
// Name: public: virtual class Vector CRagdollProp::PhysGunLaunchAngularImpulse(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
Vector *__thiscall CRagdollProp::PhysGunLaunchAngularImpulse(CRagdollProp *this, Vector *result)
{
  IUniformRandomStream *v2; // ecx
  IUniformRandomStream *v4; // ecx
  IUniformRandomStream *v5; // ecx

  if ( CRagdollProp::HasPhysgunInteraction(
         this: (CRagdollProp *)((char *)this - 1164),
         pszKeyName: "onlaunch",
         pszValue: "spin_zaxis") != 0 )
  {
    *(_QWORD *)&result->x = 0;
    result->z = 0.0;
    return result;
  }
  else
  {
    result->x = _RandomFloat(this: v2, a2: -600.0, a3: 600.0);
    result->y = _RandomFloat(this: v4, a2: -600.0, a3: 600.0);
    result->z = _RandomFloat(this: v5, a2: -600.0, a3: 600.0);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019CE10
// Name: public: void CRagdollProp::SetDebrisThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRagdollProp::SetDebrisThink(CRagdollProp *this)
{
  int v2; // esi
  IPhysicsObject **p_pObject; // edi

  CBaseEntity::SetCollisionGroup(this, collisionGroup: 1);
  v2 = 0;
  if ( this->m_ragdoll.listCount > 0 )
  {
    p_pObject = &this->m_ragdoll.list[0].pObject;
    do
    {
      (*p_pObject)->RecheckCollisionFilter(this: *p_pObject);
      ++v2;
      p_pObject += 6;
    }
    while ( v2 < this->m_ragdoll.listCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019CFA0
// Name: public: void CRagdollProp::InputStartRadgollBoogie(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRagdollProp::InputStartRadgollBoogie(CRagdollProp *this, inputdata_t *inputdata)
{
  float flLengthTime; // xmm0_4

  if ( inputdata->value.fieldType != FIELD_FLOAT || (flLengthTime = inputdata->value.flVal) <= 0.0 )
    flLengthTime = 5.0;
  CRagdollBoogie::Create(
    pTarget: this,
    flMagnitude: 100.0,
    flStartTime: gpGlobals->curtime,
    flLengthTime,
    nSpawnFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1019D020
// Name: public: void CRagdollProp::NetworkVar_m_ragPos::Set(int,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRagdollProp::NetworkVar_m_ragPos::Set(
        CRagdollProp::NetworkVar_m_ragPos *this,
        int i,
        const Vector *val)
{
  const Vector *v3; // eax
  __int16 v4; // di
  unsigned int v5; // edx
  char *v6; // eax
  CBaseEdict *v7; // edx
  Vector *ia; // [esp+14h] [ebp+8h]

  v3 = val;
  v4 = i;
  ia = &this->m_Value[i];
  v5 = 12;
  while ( *(_DWORD *)((char *)&v3->x + (char *)ia - (char *)val) == LODWORD(v3->x) )
  {
    v5 -= 4;
    v3 = (const Vector *)((char *)v3 + 4);
    if ( v5 < 4 )
      return;
  }
  v6 = (char *)this - 2100;
  if ( *((_BYTE *)this - 2016) != 0 )
  {
    v6[88] |= 1u;
  }
  else
  {
    v7 = *((CBaseEdict **)v6 + 6);
    if ( v7 != nullptr )
      CBaseEdict::StateChanged(this: v7, offset: 12 * v4 + 2100);
  }
  *ia = *val;
}

//------------------------------------------------------------------------------
// Address: 0x1019D0B0
// Name: public: void CRagdollProp::NetworkVar_m_ragAngles::Set(int,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRagdollProp::NetworkVar_m_ragAngles::Set(
        CRagdollProp::NetworkVar_m_ragAngles *this,
        int i,
        const QAngle *val)
{
  const QAngle *v3; // eax
  __int16 v4; // di
  unsigned int v5; // edx
  char *v6; // eax
  CBaseEdict *v7; // edx
  QAngle *ia; // [esp+14h] [ebp+8h]

  v3 = val;
  v4 = i;
  ia = &this->m_Value[i];
  v5 = 12;
  while ( *(_DWORD *)((char *)&v3->x + (char *)ia - (char *)val) == LODWORD(v3->x) )
  {
    v5 -= 4;
    v3 = (const QAngle *)((char *)v3 + 4);
    if ( v5 < 4 )
      return;
  }
  v6 = (char *)this - 2484;
  if ( *((_BYTE *)this - 2400) != 0 )
  {
    v6[88] |= 1u;
  }
  else
  {
    v7 = *((CBaseEdict **)v6 + 6);
    if ( v7 != nullptr )
      CBaseEdict::StateChanged(this: v7, offset: 12 * v4 + 2484);
  }
  *ia = *val;
}

//------------------------------------------------------------------------------
// Address: 0x1019D2E0
// Name: public: CRagdollProp::CRagdollProp(void)
// Source: json
//------------------------------------------------------------------------------
CRagdollProp *__thiscall CRagdollProp::CRagdollProp(CRagdollProp *this)
{
  CBaseAnimating::CBaseAnimating(this);
  this->CDefaultPlayerPickupVPhysics::IPlayerPickupVPhysics::__vftable = (CDefaultPlayerPickupVPhysics_vtbl *)&CDefaultPlayerPickupVPhysics::`vftable';
  this->CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable = (CRagdollProp_vtbl *)&CRagdollProp::`vftable'{for `CBaseAnimating'};
  this->CDefaultPlayerPickupVPhysics::IPlayerPickupVPhysics::__vftable = (CDefaultPlayerPickupVPhysics_vtbl *)&CRagdollProp::`vftable'{for `CDefaultPlayerPickupVPhysics'};
  this->m_hUnragdoll.m_Value.m_Index = -1;
  this->m_hDamageEntity.m_Index = -1;
  this->m_hKiller.m_Index = -1;
  this->m_hPhysicsAttacker.m_Index = -1;
  this->m_strSourceClassName.pszValue = nullptr;
  this->m_anglesOverrideString.pszValue = nullptr;
  this->m_ragdoll.listCount = 0;
  this->m_allAsleep = false;
  CBaseEntity::SetGlobalFadeScale(this, flFadeScale: 1.0);
  this->m_flDefaultFadeScale = 1.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1019D360
// Name: public: virtual void CRagdollProp::OnPhysGunPickup(class CBasePlayer __near *,enum PhysGunPickup_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRagdollProp::OnPhysGunPickup(CRagdollProp *this, CBasePlayer *pPhysGunUser, PhysGunPickup_t reason)
{
  int v4; // ebx
  PVSInfo_t *p_m_PVSInfo; // esi
  float flLengthTime; // [esp+8h] [ebp-14h]
  int flForcedRetireTime; // [esp+Ch] [ebp-10h]

  v4 = 0;
  if ( pPhysGunUser != nullptr )
    this->m_ragdoll.list[22].parentIndex = pPhysGunUser->GetRefEHandle(this: pPhysGunUser)->m_Index;
  else
    this->m_ragdoll.list[22].parentIndex = -1;
  this->m_ragdoll.list[23].originParentSpace.x = gpGlobals->curtime;
  if ( LOBYTE(this->m_ragdoll.list[23].pConstraint) != 0 )
    this->m_ragdoll.list[23].pObject = nullptr;
  LOBYTE(this->m_ragdoll.list[23].pConstraint) = 1;
  if ( CRagdollProp::HasPhysgunInteraction(
         this: (CRagdollProp *)((char *)this - 1164),
         pszKeyName: "onpickup",
         pszValue: "boogie") != 0 )
  {
    if ( reason == PUNTED_BY_CANNON )
    {
      flForcedRetireTime = 0x10000;
      flLengthTime = 3.0;
    }
    else
    {
      flForcedRetireTime = 0;
      flLengthTime = 2.0;
    }
    CRagdollBoogie::Create(
      pTarget: (CRagdollProp *)((char *)this - 1164),
      flMagnitude: 150.0,
      flStartTime: gpGlobals->curtime,
      flLengthTime,
      nSpawnFlags: flForcedRetireTime);
  }
  if ( (*((_DWORD *)this - 101) & 0x1000) != 0 )
    CRagdollLRURetirement::MoveToTopOfLRU(
      this: &s_RagdollLRU,
      pRagdoll: (CRagdollProp *)((char *)this - 1164),
      bImportant: false,
      flForcedRetireTime: 0.0);
  if ( (*((_DWORD *)this - 101) & 0x40) != 0 && (int)this->m_pfnMoveDone > 0 )
  {
    p_m_PVSInfo = &this->m_Network.m_PVSInfo;
    do
    {
      (*(void (__thiscall **)(_DWORD))(**(_DWORD **)&p_m_PVSInfo->m_nHeadNode + 96))(a1: *(_DWORD *)&p_m_PVSInfo->m_nHeadNode);
      (*(void (__thiscall **)(_DWORD, int))(**(_DWORD **)&p_m_PVSInfo->m_nHeadNode + 60))(
        a1: *(_DWORD *)&p_m_PVSInfo->m_nHeadNode,
        a2: 1);
      ++v4;
      p_m_PVSInfo = (PVSInfo_t *)((char *)p_m_PVSInfo + 24);
    }
    while ( v4 < (int)this->m_pfnMoveDone );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019D490
// Name: public: virtual void CRagdollProp::OnPhysGunDrop(class CBasePlayer __near *,enum PhysGunDrop_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRagdollProp::OnPhysGunDrop(CRagdollProp *this, CBasePlayer *pPhysGunUser, PhysGunDrop_t Reason)
{
  float v4; // xmm1_4
  int v5; // edi
  float v6; // xmm2_4
  float v7; // xmm3_4
  PVSInfo_t *p_m_PVSInfo; // ebx
  void (__thiscall *m_pfnMoveDone)(CBaseEntity *); // eax
  float v10; // xmm0_4
  int v11; // ebx
  PVSInfo_t *v12; // edi
  int v13; // ecx
  int v14; // edi
  unsigned __int16 v15; // ax
  Vector vecDir; // [esp+1Ch] [ebp-24h] BYREF
  Vector vecDelta; // [esp+28h] [ebp-18h] BYREF
  Vector vecAverageCenter; // [esp+34h] [ebp-Ch] BYREF

  if ( pPhysGunUser != nullptr )
    this->m_ragdoll.list[22].parentIndex = pPhysGunUser->GetRefEHandle(this: pPhysGunUser)->m_Index;
  else
    this->m_ragdoll.list[22].parentIndex = -1;
  this->m_ragdoll.list[23].originParentSpace.x = gpGlobals->curtime;
  if ( CRagdollProp::HasPhysgunInteraction(
         this: (CRagdollProp *)((char *)this - 1164),
         pszKeyName: "onpickup",
         pszValue: "boogie") != 0 )
    CRagdollBoogie::Create(
      pTarget: (CRagdollProp *)((char *)this - 1164),
      flMagnitude: 150.0,
      flStartTime: gpGlobals->curtime,
      flLengthTime: 3.0,
      nSpawnFlags: 0x10000);
  if ( (*((_DWORD *)this - 101) & 0x1000) != 0 )
    CRagdollLRURetirement::MoveToTopOfLRU(
      this: &s_RagdollLRU,
      pRagdoll: (CRagdollProp *)((char *)this - 1164),
      bImportant: false,
      flForcedRetireTime: 0.0);
  if ( *((_DWORD *)this - 210) == 3 )
    CBaseEntity::ThinkSet(
      this: (CRagdollProp *)((char *)this - 1164),
      func: (void (__thiscall *)(CBaseEntity *))CRagdollProp::SetDebrisThink,
      thinkTime: gpGlobals->curtime + 5.0,
      szContext: s_pDebrisContext);
  if ( Reason == LAUNCHED_BY_CANNON )
  {
    if ( CRagdollProp::HasPhysgunInteraction(
           this: (CRagdollProp *)((char *)this - 1164),
           pszKeyName: "onlaunch",
           pszValue: "spin_zaxis") != 0 )
    {
      v4 = 0.0;
      v5 = 0;
      v6 = 0.0;
      v7 = 0.0;
      memset((void *)&vecAverageCenter, 0, sizeof(vecAverageCenter));
      if ( (int)this->m_pfnMoveDone > 0 )
      {
        p_m_PVSInfo = &this->m_Network.m_PVSInfo;
        do
        {
          (*(void (__thiscall **)(_DWORD, Vector *, _DWORD))(**(_DWORD **)&p_m_PVSInfo->m_nHeadNode + 192))(
            a1: *(_DWORD *)&p_m_PVSInfo->m_nHeadNode,
            a2: &vecDelta,
            a3: 0);
          v4 = vecAverageCenter.x + vecDelta.x;
          v6 = vecDelta.y + vecAverageCenter.y;
          v7 = vecDelta.z + vecAverageCenter.z;
          ++v5;
          p_m_PVSInfo = (PVSInfo_t *)((char *)p_m_PVSInfo + 24);
          vecAverageCenter.x = vecAverageCenter.x + vecDelta.x;
          vecAverageCenter.y = vecDelta.y + vecAverageCenter.y;
          vecAverageCenter.z = vecDelta.z + vecAverageCenter.z;
        }
        while ( v5 < (int)this->m_pfnMoveDone );
      }
      m_pfnMoveDone = this->m_pfnMoveDone;
      v10 = 1.0 / (float)(int)m_pfnMoveDone;
      v11 = 0;
      vecAverageCenter.x = v4 * v10;
      vecAverageCenter.y = v6 * v10;
      vecAverageCenter.z = v7 * v10;
      if ( (int)m_pfnMoveDone > 0 )
      {
        v12 = &this->m_Network.m_PVSInfo;
        do
        {
          (*(void (__thiscall **)(_DWORD, Vector *, _DWORD))(**(_DWORD **)&v12->m_nHeadNode + 192))(
            a1: *(_DWORD *)&v12->m_nHeadNode,
            a2: &vecDelta,
            a3: 0);
          v13 = *(_DWORD *)&v12->m_nHeadNode;
          vecDelta.z = vecDelta.z - vecAverageCenter.z;
          vecDelta.y = vecDelta.y - vecAverageCenter.y;
          vecDelta.x = vecDelta.x - vecAverageCenter.x;
          vecDir.x = (float)((float)(vecDelta.z * 0.0) - vecDelta.y) * 100.0;
          vecDir.y = (float)(vecDelta.x - (float)(vecDelta.z * 0.0)) * 100.0;
          vecDir.z = (float)((float)(vecDelta.y * 0.0) - (float)(vecDelta.x * 0.0)) * 100.0;
          (*(void (__thiscall **)(int, Vector *, _DWORD))(*(_DWORD *)v13 + 212))(a1: v13, a2: &vecDir, a3: 0);
          ++v11;
          v12 = (PVSInfo_t *)((char *)v12 + 24);
        }
        while ( v11 < (int)this->m_pfnMoveDone );
      }
    }
    v14 = *((_DWORD *)this - 209);
    v15 = (*(int (__thiscall **)(int))(*(_DWORD *)v14 + 76))(a1: v14);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v14 + 72))(a1: v14, a2: v15 | 0x100);
    BYTE1(this->m_ragdoll.list[22].originParentSpace.z) = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019D730
// Name: public: virtual class CBasePlayer __near * CRagdollProp::HasPhysicsAttacker(float)
// Source: json
//------------------------------------------------------------------------------
CBasePlayer *__thiscall CRagdollProp::HasPhysicsAttacker(CRagdollProp *this, float dt)
{
  unsigned int m_Index; // ecx

  if ( this->m_flLastPhysicsInfluenceTime < (float)(gpGlobals->curtime - dt) )
    return nullptr;
  m_Index = this->m_hPhysicsAttacker.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (CBasePlayer *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x1019D790
// Name: public: void CRagdollProp::HandleFirstCollisionInteractions(int,struct gamevcollisionevent_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRagdollProp::HandleFirstCollisionInteractions(
        CRagdollProp *this,
        int index,
        gamevcollisionevent_t *pEvent)
{
  const CBaseHandle *(__thiscall *GetRefEHandle)(struct CBaseEntity *); // edx
  _DWORD *v5; // eax
  CRagdollProp_vtbl *v6; // edx
  IPhysicsObject *m_pPhysicsObject; // ecx
  float v8; // xmm2_4
  float v9; // xmm3_4
  int v10; // eax
  int v11; // eax
  char HasPhysgunInteraction; // bl
  float v13; // xmm2_4
  float v14; // xmm3_4
  CGameTrace tr; // [esp+4h] [ebp-74h] BYREF
  Vector vecPosition; // [esp+60h] [ebp-18h] BYREF
  Vector vecPos; // [esp+6Ch] [ebp-Ch] BYREF
  IHandleEntity savedregs; // [esp+78h] [ebp+0h] BYREF

  if ( this->m_pPhysicsObject != nullptr )
  {
    if ( CRagdollProp::HasPhysgunInteraction(this, pszKeyName: "onfirstimpact", pszValue: "break") != 0 )
    {
      CTakeDamageInfo::CTakeDamageInfo(this: (CTakeDamageInfo *)&tr);
      GetRefEHandle = this->GetRefEHandle;
      *(float *)&tr.contents = (float)this->m_iHealth.m_Value;
      v5 = (_DWORD *)GetRefEHandle(this);
      v6 = this->CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
      *(_DWORD *)&tr.plane.type = *v5;
      LODWORD(tr.plane.dist) = v6->GetRefEHandle(this)->m_Index;
      m_pPhysicsObject = this->m_pPhysicsObject;
      tr.surface.name = nullptr;
      m_pPhysicsObject->GetVelocity(this: m_pPhysicsObject, a2: &vecPos, a3: nullptr);
      this->m_pPhysicsObject->GetPosition(this: this->m_pPhysicsObject, a2: &vecPosition, a3: nullptr);
      tr.startpos = vecPos;
      tr.endpos = vecPosition;
      CBaseEntity::TakeDamage(this, a2: (int)this, inputInfo: (const CTakeDamageInfo *)&tr);
    }
    else
    {
      if ( CRagdollProp::HasPhysgunInteraction(this, pszKeyName: "onfirstimpact", pszValue: "paintsplat") != 0 )
      {
        this->m_pPhysicsObject->GetPosition(this: this->m_pPhysicsObject, a2: &vecPos, a3: nullptr);
        v8 = pEvent->preVelocity[0].z * 1.5;
        v9 = vecPos.x + (float)(pEvent->preVelocity[0].x * 1.5);
        vecPosition.y = vecPos.y + (float)(pEvent->preVelocity[0].y * 1.5);
        vecPosition.x = v9;
        vecPosition.z = vecPos.z + v8;
        UTIL_TraceLine(
          a1: &savedregs,
          a2: (int)this,
          vecAbsStart: &vecPos,
          vecAbsEnd: &vecPosition,
          mask: 0x46004003u,
          ignore: this,
          collisionGroup: 0,
          ptr: (CGameTrace *)&tr.startpos.z);
        v10 = random->RandomInt(this: random, a2: 1, a3: 3) - 1;
        if ( v10 != 0 )
        {
          v11 = v10 - 1;
          if ( v11 != 0 )
          {
            if ( v11 == 1 )
              UTIL_DecalTrace(pTrace: (CGameTrace *)&tr.startpos.z, decalName: "PaintSplatPink");
          }
          else
          {
            UTIL_DecalTrace(pTrace: (CGameTrace *)&tr.startpos.z, decalName: "PaintSplatGreen");
          }
        }
        else
        {
          UTIL_DecalTrace(pTrace: (CGameTrace *)&tr.startpos.z, decalName: "PaintSplatBlue");
        }
      }
      HasPhysgunInteraction = CRagdollProp::HasPhysgunInteraction(
                                this,
                                pszKeyName: "onfirstimpact",
                                pszValue: "alienbloodsplat");
      if ( HasPhysgunInteraction != 0
        || CRagdollProp::HasPhysgunInteraction(this, pszKeyName: "onfirstimpact", pszValue: "bloodsplat") != 0 )
      {
        this->m_pPhysicsObject->GetPosition(this: this->m_pPhysicsObject, a2: &vecPos, a3: nullptr);
        v13 = pEvent->preVelocity[0].z * 1.5;
        v14 = vecPos.x + (float)(pEvent->preVelocity[0].x * 1.5);
        vecPosition.y = vecPos.y + (float)(pEvent->preVelocity[0].y * 1.5);
        vecPosition.x = v14;
        vecPosition.z = vecPos.z + v13;
        UTIL_TraceLine(
          a1: &savedregs,
          a2: (int)this,
          vecAbsStart: &vecPos,
          vecAbsEnd: &vecPosition,
          mask: 0x46004003u,
          ignore: this,
          collisionGroup: 0,
          ptr: (CGameTrace *)&tr.startpos.z);
        UTIL_BloodDecalTrace(pTrace: (CGameTrace *)&tr.startpos.z, bloodColor: HasPhysgunInteraction != 0 ? 2 : 0);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019DA20
// Name: public: virtual int CRagdollProp::OnTakeDamage(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRagdollProp::OnTakeDamage(CRagdollProp *this, const CTakeDamageInfo *info)
{
  unsigned int m_Index; // eax
  unsigned int v4; // eax
  CTakeDamageInfo subInfo; // [esp+4h] [ebp-5Ch] BYREF

  m_Index = this->m_hDamageEntity.m_Index;
  if ( m_Index == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
  {
    return CBaseEntity::OnTakeDamage(this, info);
  }
  CTakeDamageInfo::CTakeDamageInfo(this: &subInfo, __that: info);
  v4 = this->m_hDamageEntity.m_Index;
  subInfo.m_bitsDamageType |= 0x400000u;
  if ( v4 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_SerialNumber != HIWORD(v4) )
    return (*(int (__stdcall **)(CTakeDamageInfo *))(MEMORY[0] + 264))(a1: &subInfo);
  else
    return ((int (__thiscall *)(IHandleEntity *, CTakeDamageInfo *))g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_pEntity->__vftable[22].dtr_IHandleEntity)(
             a1: g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_pEntity,
             a2: &subInfo);
}

//------------------------------------------------------------------------------
// Address: 0x1019DAE0
// Name: public: virtual void CRagdollProp::VPhysicsUpdate(class IPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CRagdollProp::VPhysicsUpdate(CRagdollProp *this@<ecx>, int a2@<ebp>, IPhysicsObject *pPhysics)
{
  void *v3; // esp
  unsigned int tickcount; // eax
  CRagdollProp *v5; // edi
  int v6; // esi
  const VMatrix *v7; // edi
  float v8; // xmm0_4
  float *v9; // eax
  CBaseEdict *v10; // ecx
  CRagdollProp::NetworkVar_m_ragAngles *v11; // ecx
  bool IsAsleep; // al
  int v13; // esi
  bool v14; // cc
  float y; // xmm1_4
  float z; // xmm2_4
  CRagdollProp::NetworkVar_m_ragAngles *p_pObject; // eax
  float *v18; // esi
  int i; // eax
  float v20; // xmm0_4
  float v21; // xmm0_4
  int v22; // eax
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm2_4
  float v26; // xmm3_4
  float v27; // xmm0_4
  unsigned __int16 v28; // [esp+4h] [ebp-30B0h]
  _QWORD v29[1536]; // [esp+18h] [ebp-309Ch] BYREF
  matrix3x4_t v30; // [esp+3020h] [ebp-94h] BYREF
  QAngle v31; // [esp+3050h] [ebp-64h] BYREF
  CBoneAccessor v32; // [esp+305Ch] [ebp-58h] BYREF
  Vector v33; // [esp+306Ch] [ebp-48h] BYREF
  Vector v34; // [esp+3078h] [ebp-3Ch] BYREF
  edict_t *m_pPev; // [esp+3084h] [ebp-30h]
  int *boneIndex; // [esp+3088h] [ebp-2Ch]
  int v37; // [esp+308Ch] [ebp-28h]
  Vector v38; // [esp+3090h] [ebp-24h] BYREF
  float *p_z; // [esp+309Ch] [ebp-18h]
  CRagdollProp *v40; // [esp+30A0h] [ebp-14h]
  CRagdollProp::NetworkVar_m_ragAngles *p_m_ragAngles; // [esp+30A4h] [ebp-10h]
  int v42; // [esp+30A8h] [ebp-Ch]
  void *v43; // [esp+30ACh] [ebp-8h]
  void *retaddr; // [esp+30B4h] [ebp+0h]

  v42 = a2;
  v43 = retaddr;
  v3 = alloca(12440);
  tickcount = gpGlobals->tickcount;
  v5 = this;
  v40 = this;
  if ( this->m_lastUpdateTickCount != tickcount )
  {
    v6 = 0;
    this->m_lastUpdateTickCount = tickcount;
    if ( this->m_ragdoll.listCount > 0 )
    {
      p_m_ragAngles = &this->m_ragAngles;
      p_z = &this->m_ragPos.m_Value[0].z;
      boneIndex = this->m_ragdoll.boneIndex;
      v37 = 384;
      do
      {
        v32.m_pBones = (matrix3x4a_t *)v29;
        v32.m_pAnimating = nullptr;
        if ( RagdollGetBoneMatrix(ragdoll: &v5->m_ragdoll, pBoneToWorld: &v32, objectIndex: v6) )
        {
          v7 = (const VMatrix *)&v29[6 * *boneIndex];
          MatrixAngles(a1: v6, src: v7, vAngles: &v31);
          v34.x = v7->m[0][3];
          v34.y = v7->m[1][3];
          v8 = v7->m[2][3];
          v5 = v40;
          v34.z = v8;
          CRagdollProp::NetworkVar_m_ragPos::Set(this: &v40->m_ragPos, i: v6, val: &v34);
          CRagdollProp::NetworkVar_m_ragAngles::Set(this: &v5->m_ragAngles, i: v6, val: &v31);
          v9 = p_z;
        }
        else
        {
          if ( v5->m_Network.m_TimerEvent.m_bRegistered )
          {
            *((_BYTE *)&v5->m_Network + 76) |= 1u;
          }
          else
          {
            m_pPev = v5->m_Network.m_pPev;
            if ( m_pPev != nullptr )
              CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 12 * v6 + 2100);
          }
          v9 = p_z;
          *(p_z - 2) = 0.0;
          *(v9 - 1) = 0.0;
          *v9 = 0.0;
          if ( v5->m_Network.m_TimerEvent.m_bRegistered )
          {
            *((_BYTE *)&v5->m_Network + 76) |= 1u;
          }
          else
          {
            v10 = &v5->m_Network.m_pPev->CBaseEdict;
            if ( v10 != nullptr )
            {
              CBaseEdict::StateChanged(this: v10, offset: 12 * v6 + 2484);
              v9 = p_z;
            }
          }
          v11 = p_m_ragAngles;
          p_m_ragAngles->m_Value[0].x = 0.0;
          v11->m_Value[0].y = 0.0;
          *(float *)((char *)v9 + v37) = 0.0;
        }
        ++boneIndex;
        p_m_ragAngles = (CRagdollProp::NetworkVar_m_ragAngles *)((char *)p_m_ragAngles + 12);
        ++v6;
        p_z = v9 + 3;
      }
      while ( v6 < v5->m_ragdoll.listCount );
    }
    IsAsleep = RagdollIsAsleep(ragdoll: &v5->m_ragdoll);
    v5->m_allAsleep = IsAsleep;
    if ( IsAsleep )
    {
      v5->m_strSourceClassName.pszValue = nullptr;
    }
    else if ( v5->m_ragdoll.pGroup->IsInErrorState(this: v5->m_ragdoll.pGroup) )
    {
      RagdollSolveSeparation(ragdoll: &v5->m_ragdoll, pEntity: v5);
    }
    if ( v5->m_allAsleep && v5->m_CollisionGroup.m_Value == 3 )
    {
      CBaseEntity::SetCollisionGroup(this: v5, collisionGroup: 1);
      v13 = 0;
      if ( v5->m_ragdoll.listCount > 0 )
      {
        p_m_ragAngles = (CRagdollProp::NetworkVar_m_ragAngles *)&v5->m_ragdoll.list[0].pObject;
        do
        {
          (*(void (__thiscall **)(_DWORD))(*(_DWORD *)LODWORD(p_m_ragAngles->m_Value[0].x) + 104))(a1: LODWORD(p_m_ragAngles->m_Value[0].x));
          p_m_ragAngles = (CRagdollProp::NetworkVar_m_ragAngles *)((char *)p_m_ragAngles + 24);
          ++v13;
        }
        while ( v13 < v5->m_ragdoll.listCount );
      }
      CBaseEntity::ThinkSet(this: v5, func: nullptr, thinkTime: gpGlobals->curtime, szContext: s_pDebrisContext);
    }
    v14 = v5->m_ragdoll.listCount <= 0;
    y = v5->m_ragPos.m_Value[0].y;
    z = v5->m_ragPos.m_Value[0].z;
    v34.x = v5->m_ragPos.m_Value[0].x;
    v34.y = y;
    v34.z = z;
    v38 = v34;
    v40 = nullptr;
    if ( !v14 )
    {
      p_pObject = (CRagdollProp::NetworkVar_m_ragAngles *)&v5->m_ragdoll.list[0].pObject;
      p_m_ragAngles = (CRagdollProp::NetworkVar_m_ragAngles *)&v5->m_ragdoll.list[0].pObject;
      v18 = &v5->m_ragdollMins[0].z;
      do
      {
        if ( LODWORD(p_pObject->m_Value[0].x) != 0 )
        {
          (*(void (__thiscall **)(_DWORD, matrix3x4_t *))(*(_DWORD *)LODWORD(p_pObject->m_Value[0].x) + 196))(
            a1: LODWORD(p_pObject->m_Value[0].x),
            a2: &v30);
          TransformAABB(
            transform: &v30,
            vecMinsIn: (const Vector *)(v18 - 2),
            vecMaxsIn: (const Vector *)(v18 + 94),
            vecMinsOut: &v33,
            vecMaxsOut: (Vector *)&v32.m_pBones);
          for ( i = 0; i < 12; i += 4 )
          {
            v20 = *(float *)((char *)&v33.x + i);
            if ( *(float *)((char *)&v34.x + i) > v20 )
              *(float *)((char *)&v34.x + i) = v20;
            v21 = *(float *)((char *)&v32.m_pBones + i);
            if ( v21 > *(float *)((char *)&v38.x + i) )
              *(float *)((char *)&v38.x + i) = v21;
          }
          p_pObject = p_m_ragAngles;
        }
        else
        {
          *(v18 - 2) = 0.0;
          *(v18 - 1) = 0.0;
          *v18 = 0.0;
          v18[94] = 0.0;
          v18[95] = 0.0;
          v18[96] = 0.0;
        }
        p_pObject = (CRagdollProp::NetworkVar_m_ragAngles *)((char *)p_pObject + 24);
        v18 += 3;
        v40 = (CRagdollProp *)((char *)v40 + 1);
        p_m_ragAngles = p_pObject;
      }
      while ( (int)v40 < v5->m_ragdoll.listCount );
    }
    CBaseEntity::SetAbsOrigin(this: v5, absOrigin: v5->m_ragPos.m_Value);
    CBaseEntity::SetAbsAngles(this: v5, absAngles: &vec3_angle);
    v22 = (int)v5->m_Collision.GetCollisionOrigin(this: &v5->m_Collision);
    v28 = v5->m_Collision.m_usSolidFlags.m_Value | 0x40;
    v37 = v22;
    CCollisionProperty::SetSolidFlags(this: &v5->m_Collision, flags: v28);
    CCollisionProperty::SetSurroundingBoundsType(
      this: &v5->m_Collision,
      type: USE_COLLISION_BOUNDS_NEVER_VPHYSICS,
      pMins: nullptr,
      pMaxs: nullptr);
    v23 = v34.y - *(float *)(v37 + 4);
    v24 = v38.x - *(float *)v37;
    v25 = v38.y - *(float *)(v37 + 4);
    v33.z = v38.z - *(float *)(v37 + 8);
    v26 = v34.x - *(float *)v37;
    v38.y = v23;
    v27 = v34.z - *(float *)(v37 + 8);
    v33.x = v24;
    v33.y = v25;
    v38.x = v26;
    v38.z = v27;
    CBaseEntity::SetCollisionBounds(this: v5, mins: &v38, maxs: &v33);
    CCollisionProperty::MarkSurroundingBoundsDirty(this: &v5->m_Collision);
    CBaseEntity::PhysicsTouchTriggers(this: v5, pPrevAbsOrigin: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019DF40
// Name: public: virtual void CRagdollProp::DrawDebugGeometryOverlays(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRagdollProp::DrawDebugGeometryOverlays(CRagdollProp *this)
{
  int v2; // ebx
  IPhysicsObject **p_pObject; // esi
  CFmtStrN<256> str; // [esp+28h] [ebp-11Ch] BYREF
  Vector pos; // [esp+134h] [ebp-10h] BYREF
  float mass; // [esp+140h] [ebp-4h]

  if ( (this->m_debugOverlays & 4) != 0 )
    CBaseAnimating::DrawServerHitboxes(this, duration: 0.0, monocolor: false);
  if ( (this->m_debugOverlays & 8) != 0 )
  {
    v2 = 0;
    if ( this->m_ragdoll.listCount > 0 )
    {
      p_pObject = &this->m_ragdoll.list[0].pObject;
      do
      {
        if ( *p_pObject != nullptr )
        {
          mass = (*p_pObject)->GetMass(this: *p_pObject);
          (*p_pObject)->GetPosition(this: *p_pObject, a2: &pos, a3: nullptr);
          CFmtStrN<256>::CFmtStrN<256>(this: &str, pszFormat: "mass %.1f", mass);
          NDebugOverlay::EntityTextAtPosition(
            origin: &pos,
            text_offset: 0,
            text: str.m_szBuf,
            duration: 0.0,
            r: 0,
            g: 255,
            b: 0,
            a: 255);
        }
        ++v2;
        p_pObject += 6;
      }
      while ( v2 < this->m_ragdoll.listCount );
    }
  }
  CBaseEntity::DrawDebugGeometryOverlays(this);
}

//------------------------------------------------------------------------------
// Address: 0x1019E010
// Name: private: void CRagdollPropAttached::Detach(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRagdollPropAttached::Detach(CRagdollPropAttached *this)
{
  int v2; // ebx
  IPhysicsObject **p_pObject; // edi
  IPhysicsObject *v4; // ecx
  int v5; // edi
  IPhysicsObject **v6; // ebx
  float rotdamping; // [esp+Ch] [ebp-8h] BYREF
  float damping; // [esp+10h] [ebp-4h] BYREF

  v2 = 0;
  this->SetParent(this, a2: nullptr, a3: -1);
  this->SetOwnerEntity(this, a2: nullptr);
  CBaseEntity::SetAbsAngles(this, absAngles: &vec3_angle);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_VPHYSICS, moveCollide: MOVECOLLIDE_DEFAULT);
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value & 0xFFFB);
  physenv->DestroyConstraint(this: physenv, a2: this->m_pAttachConstraint);
  this->m_pAttachConstraint = nullptr;
  if ( this->m_ragdoll.listCount > 0 )
  {
    p_pObject = &this->m_ragdoll.list[0].pObject;
    do
    {
      (*p_pObject)->GetDamping(this: *p_pObject, a2: &damping, a3: &rotdamping);
      v4 = *p_pObject;
      damping = damping * 0.02;
      rotdamping = rotdamping * 0.02;
      v4->SetDamping(this: v4, a2: &damping, a3: &damping);
      ++v2;
      p_pObject += 6;
    }
    while ( v2 < this->m_ragdoll.listCount );
  }
  CBaseEntity::SetCollisionGroup(this, collisionGroup: 1);
  v5 = 0;
  if ( this->m_ragdoll.listCount > 0 )
  {
    v6 = &this->m_ragdoll.list[0].pObject;
    do
    {
      (*v6)->RecheckCollisionFilter(this: *v6);
      ++v5;
      v6 += 6;
    }
    while ( v5 < this->m_ragdoll.listCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019E120
// Name: public: void CRagdollProp::GetAngleOverrideFromCurrentState(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRagdollProp::GetAngleOverrideFromCurrentState(CRagdollProp *this, char *pOut, unsigned int size)
{
  int v3; // edi
  float *p_y; // esi
  CFmtStrN<256> str; // [esp+24h] [ebp-110h] BYREF
  CRagdollProp *v6; // [esp+130h] [ebp-4h]

  v3 = 0;
  *pOut = 0;
  v6 = this;
  if ( this->m_ragdoll.listCount > 0 )
  {
    p_y = &this->m_ragAngles.m_Value[0].y;
    do
    {
      if ( v3 != 0 )
        V_strncat(pDest: pOut, pSrc: ",", destBufferSize: size, max_chars_to_copy: -1);
      CFmtStrN<256>::CFmtStrN<256>(this: &str, pszFormat: "%d,%.2f %.2f %.2f", v3, *(p_y - 1), *p_y, p_y[1]);
      V_strncat(pDest: pOut, pSrc: str.m_szBuf, destBufferSize: size, max_chars_to_copy: -1);
      ++v3;
      p_y += 3;
    }
    while ( v3 < v6->m_ragdoll.listCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019E1E0
// Name: void Ragdoll_GetAngleOverrideString(char __near *,int,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Ragdoll_GetAngleOverrideString(char *pOut, unsigned int size, CBaseEntity *pEntity)
{
  CRagdollProp *v3; // eax

  v3 = (CRagdollProp *)__RTDynamicCast(
                         inptr: pEntity,
                         VfDelta: 0,
                         SrcType: &CBaseEntity `RTTI Type Descriptor',
                         TargetType: &CRagdollProp `RTTI Type Descriptor',
                         isReference: 0);
  if ( v3 != nullptr )
    CRagdollProp::GetAngleOverrideFromCurrentState(this: v3, pOut, size);
}

//------------------------------------------------------------------------------
// Address: 0x1019E220
// Name: public: virtual void CRagdollProp::VPhysicsCollision(int,struct gamevcollisionevent_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRagdollProp::VPhysicsCollision(CRagdollProp *this, int index, CBaseEntity *pEvent)
{
  CRagdollProp *v6; // eax
  IPhysicsObject *m_pPhysicsObject; // ecx
  double v8; // st7
  edict_t *v9; // eax
  double v10; // st7
  double v11; // st6
  float v12; // xmm1_4
  float v13; // xmm2_4
  const CTakeDamageInfo *v14; // eax
  CTakeDamageInfo v15; // [esp+34h] [ebp-80h] BYREF
  Vector damagePos; // [esp+90h] [ebp-24h] BYREF
  Vector damageForce; // [esp+9Ch] [ebp-18h] BYREF
  float v18; // [esp+A8h] [ebp-Ch]
  CBaseEntity *pHitEntity; // [esp+ACh] [ebp-8h]
  int damageType; // [esp+B0h] [ebp-4h] BYREF
  BOOL indexa; // [esp+BCh] [ebp+8h]
  CRagdollProp *damage; // [esp+C0h] [ebp+Ch]
  float damagea; // [esp+C0h] [ebp+Ch]

  CBaseEntity::VPhysicsCollision(this, (surfacedata_t *)index, pEvent);
  indexa = index == 0;
  v6 = *((CRagdollProp **)&pEvent->m_flSimulationTime.m_Value + indexa);
  damage = v6;
  if ( v6 == this )
    return;
  m_pPhysicsObject = this->m_pPhysicsObject;
  if ( m_pPhysicsObject == nullptr )
    goto LABEL_7;
  if ( (((int (__thiscall *)(IPhysicsObject *))m_pPhysicsObject->GetGameFlags)(a1: m_pPhysicsObject) & 4) == 0 )
  {
LABEL_6:
    v6 = damage;
LABEL_7:
    if ( v6 != nullptr
      && (CRagdollProp *)((int (__thiscall *)(CRagdollProp *, int))this->HasPhysicsAttacker)(a1: this, a2: 1056964608) == damage )
    {
      return;
    }
    goto LABEL_9;
  }
  if ( damage != nullptr )
  {
    if ( damage == (CRagdollProp *)((int (__thiscall *)(CRagdollProp *, int))this->HasPhysicsAttacker)(
                                     a1: this,
                                     a2: 2139095039) )
      return;
    goto LABEL_6;
  }
LABEL_9:
  if ( this->m_bFirstCollisionAfterLaunch )
    CRagdollProp::HandleFirstCollisionInteractions(this, index, (gamevcollisionevent_t *)pEvent);
  if ( this->m_takedamage.m_Value != 0 )
  {
    damageType = 0;
    v8 = CalculateDefaultPhysicsDamage(
           index,
           (gamevcollisionevent_t *)pEvent,
           energyScale: 1.0,
           allowStaticDamage: true,
           &damageType,
           iszDamageTableName: 0,
           bDamageFromHeldObjects: false);
    damagea = v8;
    if ( v8 > 0.0 )
    {
      if ( this->m_bFirstCollisionAfterLaunch )
        damagea = damagea * 10.0;
      pHitEntity = *((CBaseEntity **)&pEvent->m_flSimulationTime.m_Value + indexa);
      if ( pHitEntity == nullptr )
      {
        v9 = INDEXENT(iEdictNum: 0);
        pHitEntity = GetContainingEntity(pent: v9);
      }
      (*(void (__thiscall **)(_DWORD, Vector *))(**(_DWORD **)&pEvent->m_Network.m_PVSInfo.m_nHeadNode + 4))(
        a1: *(_DWORD *)&pEvent->m_Network.m_PVSInfo.m_nHeadNode,
        a2: &damagePos);
      v10 = ((double (__thiscall *)(_DWORD))*(_DWORD *)(**((_DWORD **)&pEvent->__vftable + index) + 116))(a1: *((_DWORD *)&pEvent->__vftable + index));
      v18 = v10;
      v11 = *((float *)&pEvent->m_Network.m_pServerClass + 3 * index) * v10;
      damageForce.x = v18 * *(float *)&pEvent->m_Network.m_PVSInfo.m_pClustersInline[6 * index + 2];
      damageForce.y = v11;
      damageForce.z = v10 * *((float *)&pEvent->m_Network.m_hParent.m_Index + 3 * index);
      if ( vec3_origin.x == damageForce.x && vec3_origin.y == damageForce.y && vec3_origin.z == damageForce.z )
      {
        v18 = ((double (__thiscall *)(_DWORD))*(_DWORD *)(**((_DWORD **)&pEvent->__vftable + indexa) + 116))(a1: *((_DWORD *)&pEvent->__vftable + indexa));
        v12 = *((float *)&pEvent->m_Network.m_pServerClass + 3 * indexa) * v18;
        v13 = *((float *)&pEvent->m_Network.m_hParent.m_Index + 3 * indexa) * v18;
        damageForce.x = *(float *)&pEvent->m_Network.m_PVSInfo.m_pClustersInline[6 * indexa + 2] * v18;
        damageForce.y = v12;
        damageForce.z = v13;
      }
      v14 = CTakeDamageInfo::CTakeDamageInfo(
              this: &v15,
              pInflictor: pHitEntity,
              pAttacker: pHitEntity,
              &damageForce,
              damagePosition: &damagePos,
              flDamage: damagea,
              bitsDamageType: damageType,
              iKillType: 0,
              reportedPosition: nullptr,
              iObjectsPenetrated: 0);
      PhysCallbackDamage(pEntity: this, info: v14, event: (gamevcollisionevent_t *)pEvent, hurtIndex: index);
    }
  }
  if ( this->m_bFirstCollisionAfterLaunch )
  {
    CBaseEntity::ThinkSet(
      this,
      func: (void (__thiscall *)(CBaseEntity *))CRagdollProp::ClearFlagsThink,
      thinkTime: 0.0,
      szContext: nullptr);
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019E490
// Name: public: virtual void CRagdollProp::SetupBones(class matrix3x4a_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRagdollProp::SetupBones(CRagdollProp *this, matrix3x4a_t *pBoneToWorld, int boneMask)
{
  ragdoll_t *p_m_ragdoll; // ebx
  int v5; // esi
  void (*BeginLock)(void); // eax
  CStudioHdr *m_pStudioHdr; // eax
  IPhysicsObject **p_pObject; // edi
  int v9; // esi
  matrix3x4a_t *v10; // ebx
  const RadianEuler *v11; // edi
  bool sim[256]; // [esp+Ch] [ebp-14Ch] BYREF
  matrix3x4_t matBoneLocal; // [esp+10Ch] [ebp-4Ch] BYREF
  CBoneAccessor boneaccessor; // [esp+13Ch] [ebp-1Ch] BYREF
  CMDLCacheCriticalSection cacheCriticalSection; // [esp+14Ch] [ebp-Ch]
  int *boneIndex; // [esp+150h] [ebp-8h]
  CStudioHdr *pStudioHdr; // [esp+154h] [ebp-4h]
  int savedregs; // [esp+158h] [ebp+0h] BYREF

  p_m_ragdoll = &this->m_ragdoll;
  v5 = 0;
  if ( this->m_ragdoll.listCount != 0 )
  {
    CBaseAnimating::UpdateModelScale(this);
    BeginLock = (void (*)(void))mdlcache->BeginLock;
    cacheCriticalSection.m_pCache = mdlcache;
    BeginLock();
    if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
      CBaseAnimating::LockStudioHdr(this);
    m_pStudioHdr = this->m_pStudioHdr;
    if ( m_pStudioHdr == nullptr || (pStudioHdr = this->m_pStudioHdr, m_pStudioHdr->m_pStudioHdr == nullptr) )
      pStudioHdr = nullptr;
    memset(dst: (int)sim, value: nullptr, count: pStudioHdr->m_pStudioHdr->numbones);
    boneaccessor.m_pAnimating = nullptr;
    boneaccessor.m_pBones = pBoneToWorld;
    if ( p_m_ragdoll->listCount > 0 )
    {
      boneIndex = this->m_ragdoll.boneIndex;
      p_pObject = &this->m_ragdoll.list[0].pObject;
      do
      {
        if ( *p_pObject != nullptr
          && RagdollGetBoneMatrix(ragdoll: p_m_ragdoll, pBoneToWorld: &boneaccessor, objectIndex: v5) )
        {
          sim[*boneIndex] = true;
        }
        ++boneIndex;
        ++v5;
        p_pObject += 6;
      }
      while ( v5 < p_m_ragdoll->listCount );
    }
    v9 = 0;
    if ( pStudioHdr->m_pStudioHdr->numbones > 0 )
    {
      v10 = pBoneToWorld;
      v11 = (const RadianEuler *)&pStudioHdr->m_pStudioHdr->name[pStudioHdr->m_pStudioHdr->boneindex + 48];
      do
      {
        if ( !sim[v9] && (boneMask & pStudioHdr->m_boneFlags.m_Memory.m_pMemory[v9]) != 0 )
        {
          AngleMatrix(angles: v11, position: (const Vector *)&v11[-3].z, matrix: &matBoneLocal);
          ConcatTransforms(in1: &pBoneToWorld[LODWORD(v11[-5].y)], in2: &matBoneLocal, out: v10);
        }
        ++v9;
        ++v10;
        v11 += 18;
      }
      while ( v9 < pStudioHdr->m_pStudioHdr->numbones );
    }
    cacheCriticalSection.m_pCache->EndLock(this: cacheCriticalSection.m_pCache);
  }
  else
  {
    CBaseAnimating::SetupBones(this, a2: (int)&savedregs, pBoneToWorld, (CBoneCache *)boneMask);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019E600
// Name: public: virtual bool CRagdollProp::TestCollision(struct Ray_t const __near &,unsigned int,class CGameTrace __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CRagdollProp::TestCollision(CRagdollProp *this, const Ray_t *ray, unsigned int mask, CGameTrace *trace)
{
  IMDLCache *m_pCache; // ebx
  void (__thiscall *BeginLock)(IMDLCache *); // edx
  CRagdollProp *v6; // edi
  CStudioHdr *m_pStudioHdr; // eax
  void (__thiscall *EndLock)(IMDLCache *); // edx
  IMDLCache *v9; // ecx
  bool v11; // cc
  IPhysicsObject **p_pObject; // ebx
  IPhysicsCollision_vtbl *v13; // edi
  int v14; // eax
  IPhysicsObject *v15; // ecx
  int v16; // eax
  int hitgroup; // ecx
  float fractionleftsolid; // xmm0_4
  __int16 physicsbone; // dx
  CBaseEntity *m_pEnt; // ecx
  int hitbox; // edx
  CGameTrace tr; // [esp+8h] [ebp-78h] BYREF
  Vector position; // [esp+5Ch] [ebp-24h] BYREF
  QAngle angles; // [esp+68h] [ebp-18h] BYREF
  CMDLCacheCriticalSection cacheCriticalSection; // [esp+74h] [ebp-Ch]
  CRagdollProp *v26; // [esp+78h] [ebp-8h]
  int i; // [esp+7Ch] [ebp-4h]

  m_pCache = mdlcache;
  BeginLock = mdlcache->BeginLock;
  v6 = this;
  v26 = this;
  cacheCriticalSection.m_pCache = mdlcache;
  BeginLock(this: mdlcache);
  if ( v6->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this: v6) != nullptr )
    CBaseAnimating::LockStudioHdr(this: v6);
  m_pStudioHdr = v6->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    EndLock = m_pCache->EndLock;
    v9 = m_pCache;
LABEL_7:
    EndLock(this: v9);
    return 0;
  }
  v11 = v6->m_ragdoll.listCount <= 0;
  i = 0;
  if ( !v11 )
  {
    p_pObject = &v6->m_ragdoll.list[0].pObject;
    do
    {
      if ( *p_pObject != nullptr )
      {
        (*p_pObject)->GetPosition(this: *p_pObject, a2: &position, a3: &angles);
        v13 = physcollision->__vftable;
        v14 = ((int (__thiscall *)(IPhysicsObject *, Vector *, QAngle *, CGameTrace *))(*p_pObject)->GetCollide)(
                a1: *p_pObject,
                a2: &position,
                a3: &angles,
                a4: &tr);
        ((void (__thiscall *)(IPhysicsCollision *, const Ray_t *, int))v13->TraceBox_2)(
          a1: physcollision,
          a2: ray,
          a3: v14);
        if ( trace->fraction > tr.fraction )
        {
          v15 = *p_pObject;
          tr.physicsbone = i;
          tr.surface.surfaceProps = v15->GetMaterialIndex(this: v15);
          CBaseTrace::operator=(this: trace, __that: &tr);
          v16 = *(_DWORD *)&tr.surface.surfaceProps;
          hitgroup = tr.hitgroup;
          fractionleftsolid = tr.fractionleftsolid;
          trace->surface.name = tr.surface.name;
          physicsbone = tr.physicsbone;
          *(_DWORD *)&trace->surface.surfaceProps = v16;
          LOWORD(v16) = tr.worldSurfaceIndex;
          trace->hitgroup = hitgroup;
          m_pEnt = tr.m_pEnt;
          trace->physicsbone = physicsbone;
          hitbox = tr.hitbox;
          trace->fractionleftsolid = fractionleftsolid;
          trace->worldSurfaceIndex = v16;
          trace->m_pEnt = m_pEnt;
          trace->hitbox = hitbox;
        }
        v6 = v26;
      }
      else
      {
        DevWarning(a1: "Bogus object in Ragdoll Prop's ragdoll list!\n");
      }
      p_pObject += 6;
      ++i;
    }
    while ( i < v6->m_ragdoll.listCount );
    m_pCache = cacheCriticalSection.m_pCache;
  }
  EndLock = m_pCache->EndLock;
  v9 = m_pCache;
  if ( trace->fraction >= 1.0 )
    goto LABEL_7;
  EndLock(this: m_pCache);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1019E790
// Name: public: virtual void CRagdollProp::Teleport(class Vector const __near *,class QAngle const __near *,class Vector const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRagdollProp::Teleport(
        CRagdollProp *this,
        const Vector *newPosition,
        const QAngle *newAngles,
        const Vector *newVelocity,
        bool bUseSlowHighAccuracyContacts)
{
  int i; // esi
  IPhysicsObject **p_pObject; // ebx
  matrix3x4_t newMatrix; // [esp+8h] [ebp-180h] BYREF
  matrix3x4_t startMatrixInv; // [esp+38h] [ebp-150h] BYREF
  matrix3x4_t matrix; // [esp+68h] [ebp-120h] BYREF
  matrix3x4_t obj0source; // [esp+98h] [ebp-F0h] BYREF
  matrix3x4_t xform; // [esp+C8h] [ebp-C0h] BYREF
  matrix3x4_t endMatrix; // [esp+F8h] [ebp-90h] BYREF
  matrix3x4_t obj0Target; // [esp+128h] [ebp-60h] BYREF
  QAngle obj0Angles; // [esp+158h] [ebp-30h] BYREF
  QAngle v16; // [esp+164h] [ebp-24h] BYREF
  Vector obj0Pos; // [esp+170h] [ebp-18h] BYREF
  Vector val; // [esp+17Ch] [ebp-Ch] BYREF
  int savedregs; // [esp+188h] [ebp+0h] BYREF

  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  MatrixInvert(in: &this->m_rgflCoordinateFrame, out: &startMatrixInv);
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  MatrixCopy(in: &this->m_rgflCoordinateFrame, out: &endMatrix);
  if ( newAngles != nullptr )
    AngleMatrix(angles: newAngles, matrix: &endMatrix);
  if ( newPosition != nullptr )
    MatrixSetColumn(in: newPosition, column: 3, out: &endMatrix);
  ConcatTransforms(in1: &endMatrix, in2: &startMatrixInv, out: &xform);
  CBaseEntity::VPhysicsSwapObject(this, pSwap: this->m_ragdoll.list[0].pObject);
  this->m_ragdoll.list[0].pObject->GetPositionMatrix(this: this->m_ragdoll.list[0].pObject, a2: &obj0source);
  ConcatTransforms(in1: &xform, in2: &obj0source, out: &obj0Target);
  MatrixAngles(a1: (int)&this->m_rgflCoordinateFrame, src: (const VMatrix *)&obj0Target, vAngles: &obj0Angles);
  obj0Pos.x = obj0Target.m_flMatVal[0][3];
  obj0Pos.y = obj0Target.m_flMatVal[1][3];
  obj0Pos.z = obj0Target.m_flMatVal[2][3];
  CBaseAnimating::Teleport(
    this,
    newPosition: &obj0Pos,
    newAngles: &obj0Angles,
    newVelocity,
    bUseSlowHighAccuracyContacts);
  for ( i = 1; i < this->m_ragdoll.listCount; ++i )
  {
    p_pObject = &this->m_ragdoll.list[i].pObject;
    (*p_pObject)->GetPositionMatrix(this: *p_pObject, a2: &matrix);
    ConcatTransforms(in1: &xform, in2: &matrix, out: &newMatrix);
    (*p_pObject)->SetPositionMatrix(this: *p_pObject, a2: &newMatrix, a3: true);
    (*p_pObject)->GetPosition(this: *p_pObject, a2: &val, a3: &v16);
    CRagdollProp::NetworkVar_m_ragPos::Set(this: &this->m_ragPos, i, &val);
    CRagdollProp::NetworkVar_m_ragAngles::Set(this: &this->m_ragAngles, i, val: &v16);
    if ( i == 0 )
    {
      CBaseEntity::SetAbsOrigin(this, absOrigin: this->m_ragPos.m_Value);
      CBaseEntity::PhysicsTouchTriggers(this, pPrevAbsOrigin: nullptr);
    }
  }
  this->m_ragdoll.list[0].pObject->GetPosition(
    this: this->m_ragdoll.list[0].pObject,
    a2: (Vector *)&v16,
    a3: (QAngle *)&val);
  CRagdollProp::NetworkVar_m_ragPos::Set(this: &this->m_ragPos, i: 0, val: (const Vector *)&v16);
  CRagdollProp::NetworkVar_m_ragAngles::Set(this: &this->m_ragAngles, i: 0, (const QAngle *)&val);
  CBaseEntity::SetAbsOrigin(this, absOrigin: this->m_ragPos.m_Value);
  CBaseEntity::PhysicsTouchTriggers(this, pPrevAbsOrigin: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1019EA50
// Name: public: virtual void CRagdollPropAttached::VPhysicsUpdate(class IPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRagdollPropAttached::VPhysicsUpdate(CRagdollPropAttached *this, IPhysicsObject *pPhysics)
{
  int savedregs; // [esp+4h] [ebp+0h] BYREF

  if ( this->m_bShouldDetach )
  {
    CRagdollPropAttached::Detach(this);
    this->m_bShouldDetach = false;
  }
  CRagdollProp::VPhysicsUpdate(this, a2: (int)&savedregs, pPhysics);
}

//------------------------------------------------------------------------------
// Address: 0x1019EAC0
// Name: public: void CRagdollProp::InitRagdollAnimation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRagdollProp::InitRagdollAnimation(CRagdollProp *this)
{
  CGlobalVars *v1; // edi
  edict_t *m_pPev; // ecx
  edict_t *v4; // ecx
  edict_t *v5; // ecx
  int v6; // eax

  v1 = gpGlobals;
  if ( this->m_flAnimTime.m_Value != gpGlobals->curtime )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x64u);
    }
    this->m_flAnimTime.m_Value = v1->curtime;
  }
  if ( this->m_flPlaybackRate.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v4 = this->m_Network.m_pPev;
      if ( v4 != nullptr )
        CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0x37Cu);
    }
    this->m_flPlaybackRate.m_Value = 0.0;
  }
  if ( this->m_flCycle.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v5 = this->m_Network.m_pPev;
      if ( v5 != nullptr )
        CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0x3ACu);
    }
    this->m_flCycle.m_Value = 0.0;
  }
  v6 = CBaseAnimating::SelectWeightedSequence(this, activity: ACT_DIERAGDOLL);
  if ( v6 >= 0 )
    CBaseAnimating::ResetSequence(this, nSequence: v6);
  else
    CBaseAnimating::ResetSequence(this, nSequence: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1019EBB0
// Name: public: void CRagdollProp::InitRagdoll(class Vector const __near &,int,class Vector const __near &,struct matrix3x4_t __near *,struct matrix3x4_t __near *,float,int,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRagdollProp::InitRagdoll(
        CRagdollProp *this,
        const Vector *forceVector,
        int forceBone,
        const Vector *forcePos,
        matrix3x4_t *pPrevBones,
        matrix3x4_t *pBoneToWorld,
        float dt,
        CBaseEntity::NetworkVar_m_Collision *collisionGroup,
        IPhysicsObject **activateRagdoll,
        bool bWakeRagdoll)
{
  CBaseEntity::NetworkVar_m_Collision *v10; // edi
  CBaseEntity::NetworkVar_m_Collision *p_m_Collision; // ebx
  int (__thiscall *GetModelIndex)(struct CBaseEntity *); // edx
  vcollide_t *v14; // eax
  bool v15; // zf
  CStudioHdr *m_pStudioHdr; // eax
  float z; // xmm0_4
  int m_Value; // eax
  const char *pszValue; // eax
  const char *i; // ebx
  int v21; // edi
  CFmtStrN<256> *v22; // edi
  const char *v23; // eax
  const char *DebugName; // eax
  matrix3x4_t *v25; // ebx
  int parentIndex; // eax
  ragdollelement_t *v27; // edi
  int v28; // eax
  int v29; // edi
  IPhysicsObject *pObject; // ecx
  IPhysSaveRestoreManager_vtbl *v31; // ebx
  int v32; // eax
  IPhysicsCollision_vtbl *v33; // ebx
  int v34; // eax
  const char *thinkTime; // [esp+18h] [ebp-970h]
  bool thinkTime_4; // [esp+1Ch] [ebp-96Ch]
  char szToken[2048]; // [esp+2Ch] [ebp-95Ch] BYREF
  CFmtStrN<256> v38; // [esp+82Ch] [ebp-15Ch] BYREF
  ragdollparams_t params; // [esp+938h] [ebp-50h] BYREF
  QAngle angles; // [esp+970h] [ebp-18h] BYREF
  Vector out; // [esp+97Ch] [ebp-Ch] BYREF
  int savedregs; // [esp+988h] [ebp+0h] BYREF
  const char *pStr; // [esp+990h] [ebp+8h]

  v10 = collisionGroup;
  CBaseEntity::SetCollisionGroup(this, (int)collisionGroup);
  if ( v10 == (CBaseEntity::NetworkVar_m_Collision *)3 )
    CBaseEntity::ThinkSet(
      this,
      func: (void (__thiscall *)(CBaseEntity *))CRagdollProp::SetDebrisThink,
      thinkTime: gpGlobals->curtime + 5.0,
      szContext: s_pDebrisContext);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_VPHYSICS, moveCollide: MOVECOLLIDE_DEFAULT);
  p_m_Collision = &this->m_Collision;
  collisionGroup = &this->m_Collision;
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_VPHYSICS);
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 3);
  if ( this->m_takedamage.m_Value != 1 )
  {
    this->NetworkStateChanged_m_takedamage(this, a2: &this->m_takedamage);
    this->m_takedamage.m_Value = 1;
  }
  GetModelIndex = this->GetModelIndex;
  params.pGameData = this;
  params.modelIndex = GetModelIndex(this);
  v14 = modelinfo->GetVCollide(this: modelinfo, a2: params.modelIndex);
  v15 = this->m_pStudioHdr == nullptr;
  params.pCollide = v14;
  if ( v15 && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr
    || (v15 = m_pStudioHdr->m_pStudioHdr == nullptr, params.pStudioHdr = this->m_pStudioHdr, v15) )
  {
    params.pStudioHdr = nullptr;
  }
  params.forceVector = *forceVector;
  params.forcePosition.x = forcePos->x;
  params.forcePosition.y = forcePos->y;
  z = forcePos->z;
  m_Value = this->m_spawnflags.m_Value;
  params.forceBoneIndex = forceBone;
  params.pCurrentBones = pBoneToWorld;
  params.forcePosition.z = z;
  params.jointFrictionScale = 1.0;
  params.allowStretch = (m_Value & 0x8000) != 0;
  params.fixedConstraints = false;
  RagdollCreate(ragdoll: &this->m_ragdoll, &params, pPhysEnv: physenv);
  RagdollApplyAnimationAsVelocity(ragdoll: &this->m_ragdoll, pPrevBones, pCurrentBones: pBoneToWorld, dt);
  if ( this->m_anglesOverrideString.pszValue != nullptr && _V_strlen(str: this->m_anglesOverrideString.pszValue) > 0 )
  {
    pszValue = this->m_anglesOverrideString.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    for ( i = nexttoken(token: szToken, str: pszValue, sep: 44);
          szToken[0] != 0;
          i = nexttoken(token: szToken, str: pStr, sep: 44) )
    {
      v21 = atoi(nptr: szToken);
      pStr = nexttoken(token: szToken, str: i, sep: 44);
      if ( v21 < this->m_ragdoll.listCount )
      {
        if ( szToken[0] != 0 )
        {
          UTIL_StringToVector(pVector: &angles.x, pString: szToken);
          v25 = &pBoneToWorld[this->m_ragdoll.boneIndex[v21]];
          AngleMatrix(&angles, matrix: v25);
          parentIndex = this->m_ragdoll.list[v21].parentIndex;
          v27 = &this->m_ragdoll.list[v21];
          if ( parentIndex < 0 )
          {
            if ( (this->m_iEFlags & 0x800) != 0 )
              CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
            out = this->m_vecAbsOrigin;
          }
          else
          {
            VectorTransform(
              in1: &v27->originParentSpace.x,
              in2: &pBoneToWorld[this->m_ragdoll.boneIndex[parentIndex]],
              out: &out.x);
          }
          MatrixSetColumn(in: &out, column: 3, out: v25);
          v27->pObject->SetPositionMatrix(this: v27->pObject, a2: v25, a3: true);
        }
      }
      else
      {
        if ( (this->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
        if ( (this->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
        if ( (this->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
        v22 = CFmtStrN<256>::CFmtStrN<256>(
                this: &v38,
                pszFormat: "(%f, %f, %f)",
                this->m_vecAbsOrigin.x,
                this->m_vecAbsOrigin.y,
                this->m_vecAbsOrigin.z);
        v23 = *(const char **)((int (__thiscall *)(CRagdollProp *, int *))this->GetModelName)(a1: this, a2: &forceBone);
        if ( v23 == nullptr )
          v23 = locale;
        thinkTime = v23;
        DebugName = CBaseEntity::GetDebugName(this);
        _Warning(
          a1: "Bad ragdoll pose in entity %s, model (%s) at %s, model changed?\n",
          DebugName,
          thinkTime,
          v22->m_szBuf);
      }
    }
    p_m_Collision = collisionGroup;
  }
  if ( (_BYTE)activateRagdoll != 0 )
  {
    thinkTime_4 = bWakeRagdoll;
    v28 = this->GetModelIndex(this);
    RagdollActivate(ragdoll: &this->m_ragdoll, pCollide: params.pCollide, modelIndex: v28, bForceWake: thinkTime_4);
  }
  v29 = 0;
  if ( this->m_ragdoll.listCount > 0 )
  {
    do
    {
      pObject = this->m_ragdoll.list[v29].pObject;
      activateRagdoll = &this->m_ragdoll.list[v29].pObject;
      pObject->GetPosition(this: pObject, a2: (Vector *)&angles, a3: (QAngle *)&out);
      CRagdollProp::NetworkVar_m_ragPos::Set(this: &this->m_ragPos, i: v29, val: (const Vector *)&angles);
      CRagdollProp::NetworkVar_m_ragAngles::Set(this: &this->m_ragAngles, i: v29, val: (const QAngle *)&out);
      if ( v29 == 0 )
      {
        CBaseEntity::SetAbsOrigin(this, absOrigin: this->m_ragPos.m_Value);
        CBaseEntity::PhysicsTouchTriggers(this, pPrevAbsOrigin: nullptr);
      }
      v31 = g_pPhysSaveRestoreManager->__vftable;
      v32 = this->GetModelIndex(this);
      v31->AssociateModel_2(this: g_pPhysSaveRestoreManager, a2: *activateRagdoll, a3: v32);
      v33 = physcollision->__vftable;
      v34 = ((int (__thiscall *)(IPhysicsObject *, Vector *, QAngle *))(*activateRagdoll)->GetCollide)(
              a1: *activateRagdoll,
              a2: &vec3_origin,
              a3: &vec3_angle);
      ((void (__thiscall *)(IPhysicsCollision *, Vector *, Vector *, int))v33->CollideGetAABB)(
        a1: physcollision,
        a2: &this->m_ragdollMins[v29],
        a3: &this->m_ragdollMaxs[v29],
        a4: v34);
      ++v29;
    }
    while ( v29 < this->m_ragdoll.listCount );
    p_m_Collision = collisionGroup;
  }
  CBaseEntity::VPhysicsSetObject(this, pPhysics: this->m_ragdoll.list[0].pObject);
  CCollisionProperty::SetSurroundingBoundsType(this: p_m_Collision, type: USE_HITBOXES, pMins: nullptr, pMaxs: nullptr);
  CCollisionProperty::SetSolidFlags(this: p_m_Collision, flags: p_m_Collision->m_usSolidFlags.m_Value & 0xFFBF);
}

//------------------------------------------------------------------------------
// Address: 0x1019F0C0
// Name: public: virtual void CRagdollProp::SetDamageEntity(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRagdollProp::SetDamageEntity(CRagdollProp *this, CBaseEntity *pEntity)
{
  CNetworkVarBase<char,CBaseEntity::NetworkVar_m_takedamage> *p_m_takedamage; // esi

  if ( pEntity != nullptr )
  {
    this->m_hDamageEntity.m_Index = pEntity->GetRefEHandle(this: pEntity)->m_Index;
    this->m_takedamage.m_Value = pEntity->m_takedamage.m_Value;
  }
  else
  {
    this->m_hDamageEntity.m_Index = -1;
    p_m_takedamage = &this->m_takedamage;
    if ( this->m_takedamage.m_Value != 1 )
    {
      this->NetworkStateChanged_m_takedamage(this, a2: &this->m_takedamage);
      p_m_takedamage->m_Value = 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019F130
// Name: class CBaseAnimating __near * CreateServerRagdollSubmodel(class CBaseAnimating __near *,char const __near *,class Vector const __near &,class QAngle const __near &,int)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
CRagdollProp *__usercall CreateServerRagdollSubmodel@<eax>(
        int a1@<ebp>,
        int a2@<edi>,
        int a3@<esi>,
        CBaseAnimating *pOwner,
        const char *pModelName,
        const Vector *position,
        const QAngle *angles,
        CBaseEntity::NetworkVar_m_Collision *collisionGroup)
{
  void *v8; // esp
  CRagdollProp *NoSpawn; // esi
  const char *v10; // eax
  void (__thiscall *SetParent)(CBaseEntity *, CBaseEntity *, int); // eax
  matrix3x4_t v14[256]; // [esp+40h] [ebp-601Ch] BYREF
  matrix3x4_t v15[255]; // [esp+3040h] [ebp-301Ch] BYREF
  CBaseAnimating *v16; // [esp+6044h] [ebp-18h]
  int v17; // [esp+6048h] [ebp-14h]
  char v18[4]; // [esp+604Ch] [ebp-10h] BYREF
  int v19; // [esp+6050h] [ebp-Ch]
  void *v20; // [esp+6054h] [ebp-8h]
  void *retaddr; // [esp+605Ch] [ebp+0h]

  v19 = a1;
  v20 = retaddr;
  v8 = alloca(24600);
  NoSpawn = (CRagdollProp *)CBaseEntity::CreateNoSpawn(
                              szName: "prop_ragdoll",
                              vecOrigin: position,
                              vecAngles: angles,
                              pOwner);
  NoSpawn->m_ModelName.pszValue = *(const char **)AllocPooledString(pszValue: v18, pszValuea: pModelName).pszValue;
  CBaseEntity::DispatchUpdateTransmitState(this: NoSpawn);
  v10 = *(const char **)((int (__thiscall *)(CRagdollProp *, char *, int, int))NoSpawn->GetModelName)(
                          a1: NoSpawn,
                          a2: v18,
                          a3: a2,
                          a4: a3);
  if ( v10 == nullptr )
    v10 = locale;
  ((void (__thiscall *)(CRagdollProp *, const char *, int, void *))NoSpawn->SetModel)(
    a1: NoSpawn,
    a2: v10,
    a3: v19,
    a4: v20);
  CBaseAnimating::ResetSequence(this: NoSpawn, nSequence: 0);
  SetParent = NoSpawn->SetParent;
  v17 = -1;
  v16 = pOwner;
  ((void (__thiscall *)(CRagdollProp *))SetParent)(a1: NoSpawn);
  NoSpawn->SetupBones(this: NoSpawn, a2: (matrix3x4a_t *)v15, a3: 524032);
  NoSpawn->SetParent(this: NoSpawn, a2: nullptr, a3: -1);
  CRagdollProp::InitRagdoll(
    this: NoSpawn,
    forceVector: &vec3_origin,
    forceBone: -1,
    forcePos: &vec3_origin,
    pPrevBones: v15,
    pBoneToWorld: v14,
    dt: 0.1,
    collisionGroup,
    activateRagdoll: (IPhysicsObject **)1,
    bWakeRagdoll: true);
  return NoSpawn;
}

//------------------------------------------------------------------------------
// Address: 0x1019F250
// Name: public: void CRagdollPropAttached::InitRagdollAttached(class IPhysicsObject __near *,class Vector const __near &,int,struct matrix3x4_t __near *,struct matrix3x4_t __near *,float,int,class CBaseAnimating __near *,int,class Vector const __near &,int,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRagdollPropAttached::InitRagdollAttached(
        CRagdollPropAttached *this,
        IPhysicsObject *pAttached,
        const Vector *forceVector,
        int forceBone,
        matrix3x4_t *pPrevBones,
        matrix3x4_t *pBoneToWorld,
        float dt,
        CBaseEntity::NetworkVar_m_Collision *collisionGroup,
        float pFollow,
        int boneIndexRoot,
        const Vector *boneLocalOrigin,
        float parentBoneAttach,
        const Vector *worldAttachOrigin)
{
  float v13; // edi
  int v14; // ebx
  CStudioHdr *m_pStudioHdr; // eax
  IPhysicsObject *pObject; // ebx
  float v18; // ecx
  float v19; // xmm1_4
  void (__thiscall *GetPositionMatrix)(IPhysicsObject *, matrix3x4_t *); // edx
  IPhysicsConstraint *v21; // eax
  CBaseAnimating *v22; // edi
  IVModelInfo_vtbl *v23; // ebx
  vcollide_t *v24; // eax
  IPhysicsObject **p_pObject; // ebx
  IPhysicsObject *v26; // ecx
  int v27; // ebx
  edict_t *m_pPev; // ecx
  int v29; // ebx
  edict_t *v30; // ecx
  const Vector *v31; // ebx
  edict_t *v32; // ecx
  edict_t *v33; // ecx
  int v34; // [esp+8h] [ebp-1BCh]
  char v35; // [esp+Ch] [ebp-1B8h]
  matrix3x4_t worldToReference; // [esp+1Ch] [ebp-1A8h] BYREF
  matrix3x4_t worldToAttached; // [esp+4Ch] [ebp-178h] BYREF
  matrix3x4_t constraintToWorld; // [esp+7Ch] [ebp-148h] BYREF
  matrix3x4_t tmp; // [esp+ACh] [ebp-118h] BYREF
  constraint_ragdollparams_t constraint; // [esp+DCh] [ebp-E8h] BYREF
  Vector offsetWS; // [esp+190h] [ebp-34h] BYREF
  Vector attachmentPointRagdollSpace; // [esp+19Ch] [ebp-28h] BYREF
  QAngle followAng; // [esp+1A8h] [ebp-1Ch] BYREF
  Vector vTemp; // [esp+1B4h] [ebp-10h] BYREF
  int ragdollAttachedIndex; // [esp+1C0h] [ebp-4h]
  int savedregs; // [esp+1C4h] [ebp+0h] BYREF
  int i; // [esp+1E4h] [ebp+20h]

  v13 = parentBoneAttach;
  v14 = 0;
  ragdollAttachedIndex = 0;
  if ( SLODWORD(parentBoneAttach) > 0 )
  {
    if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
      CBaseAnimating::LockStudioHdr(this);
    m_pStudioHdr = this->m_pStudioHdr;
    if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
      m_pStudioHdr = nullptr;
    ragdollAttachedIndex = *(int *)((char *)&m_pStudioHdr->m_pStudioHdr->numhitboxsets
                                  + 216 * LODWORD(v13)
                                  + m_pStudioHdr->m_pStudioHdr->boneindex);
    v14 = ragdollAttachedIndex;
  }
  CRagdollProp::InitRagdoll(
    this,
    forceVector,
    forceBone,
    forcePos: &vec3_origin,
    pPrevBones,
    pBoneToWorld,
    dt,
    collisionGroup,
    activateRagdoll: nullptr,
    bWakeRagdoll: true);
  pObject = this->m_ragdoll.list[v14].pObject;
  pObject->WorldToLocal(this: pObject, a2: &attachmentPointRagdollSpace, a3: worldAttachOrigin);
  constraint_ragdollparams_t::Defaults(this: &constraint);
  pAttached->LocalToWorld(this: pAttached, a2: &offsetWS, a3: boneLocalOrigin);
  v18 = pFollow;
  if ( (*(_DWORD *)(LODWORD(pFollow) + 196) & 0x800) != 0 )
  {
    CBaseEntity::CalcAbsolutePosition(this: (CBaseEntity *)LODWORD(pFollow), a2: (int)&savedregs);
    v18 = pFollow;
  }
  v19 = *(float *)(LODWORD(v18) + 476);
  followAng.x = 0.0;
  followAng.y = v19;
  followAng.z = 0.0;
  AngleMatrix(angles: &followAng, position: &offsetWS, matrix: &constraintToWorld);
  GetPositionMatrix = pAttached->GetPositionMatrix;
  constraint.axes[0].minRotation = -2.0;
  constraint.axes[0].maxRotation = 2.0;
  constraint.axes[0].angularVelocity = 0.0;
  memset(&constraint.axes[1], 0, sizeof(constraint.axes[1]));
  constraint.axes[2].minRotation = -15.0;
  constraint.axes[2].angularVelocity = 0.0;
  constraint.axes[0].torque = 20.0;
  constraint.axes[2].maxRotation = 15.0;
  constraint.axes[2].torque = 20.0;
  constraint.constraint.bodyMassScale[1] = 50.0;
  GetPositionMatrix(this: pAttached, a2: &tmp);
  MatrixInvert(in: &tmp, out: &worldToAttached);
  pObject->GetPositionMatrix(this: pObject, a2: &tmp);
  MatrixInvert(in: &tmp, out: &worldToReference);
  ConcatTransforms(in1: &worldToReference, in2: &constraintToWorld, out: &constraint.constraintToReference);
  ConcatTransforms(in1: &worldToAttached, in2: &constraintToWorld, out: &constraint.constraintToAttached);
  MatrixSetColumn(in: &attachmentPointRagdollSpace, column: 3, out: &constraint.constraintToReference);
  PhysDisableEntityCollisions(pObject0: pAttached, pObject1: this->m_ragdoll.list[0].pObject);
  v21 = physenv->CreateRagdollConstraint(
          this: physenv,
          a2: pObject,
          a3: pAttached,
          a4: this->m_ragdoll.pGroup,
          a5: &constraint);
  v22 = (CBaseAnimating *)LODWORD(pFollow);
  this->m_pAttachConstraint = v21;
  this->SetParent(this, a2: v22, a3: -1);
  this->SetOwnerEntity(this, a2: v22);
  v23 = modelinfo->__vftable;
  v35 = ((int (__thiscall *)(CRagdollPropAttached *, int))this->GetModelIndex)(a1: this, a2: 1);
  v34 = this->GetModelIndex(this);
  v24 = (vcollide_t *)((int (__thiscall *)(IVModelInfo *))v23->GetVCollide)(a1: modelinfo);
  RagdollActivate(ragdoll: &this->m_ragdoll, pCollide: v24, modelIndex: v34, bForceWake: v35);
  i = 0;
  if ( this->m_ragdoll.listCount > 0 )
  {
    p_pObject = &this->m_ragdoll.list[0].pObject;
    do
    {
      (*p_pObject)->GetDamping(this: *p_pObject, a2: &parentBoneAttach, a3: &pFollow);
      v26 = *p_pObject;
      parentBoneAttach = parentBoneAttach * 50.0;
      pFollow = pFollow * 50.0;
      v26->SetDamping(this: v26, a2: &parentBoneAttach, a3: &pFollow);
      p_pObject += 6;
      ++i;
    }
    while ( i < this->m_ragdoll.listCount );
  }
  v27 = boneIndexRoot;
  if ( this->m_boneIndexAttached.m_Value != boneIndexRoot )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xE70u);
    }
    this->m_boneIndexAttached.m_Value = v27;
  }
  v29 = ragdollAttachedIndex;
  if ( this->m_ragdollAttachedObjectIndex.m_Value != ragdollAttachedIndex )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v30 = this->m_Network.m_pPev;
      if ( v30 != nullptr )
        CBaseEdict::StateChanged(this: &v30->CBaseEdict, offset: 0xE74u);
    }
    this->m_ragdollAttachedObjectIndex.m_Value = v29;
  }
  v31 = boneLocalOrigin;
  if ( boneLocalOrigin->x != this->m_attachmentPointBoneSpace.m_Value.x
    || boneLocalOrigin->y != this->m_attachmentPointBoneSpace.m_Value.y
    || boneLocalOrigin->z != this->m_attachmentPointBoneSpace.m_Value.z )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v32 = this->m_Network.m_pPev;
      if ( v32 != nullptr )
        CBaseEdict::StateChanged(this: &v32->CBaseEdict, offset: 0xE78u);
    }
    this->m_attachmentPointBoneSpace.m_Value.x = v31->x;
    this->m_attachmentPointBoneSpace.m_Value.y = v31->y;
    this->m_attachmentPointBoneSpace.m_Value.z = v31->z;
  }
  MatrixGetColumn(in: &constraint.constraintToReference, column: 3, out: &vTemp);
  if ( vTemp.x != this->m_attachmentPointRagdollSpace.m_Value.x
    || vTemp.y != this->m_attachmentPointRagdollSpace.m_Value.y
    || vTemp.z != this->m_attachmentPointRagdollSpace.m_Value.z )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v33 = this->m_Network.m_pPev;
      if ( v33 != nullptr )
        CBaseEdict::StateChanged(this: &v33->CBaseEdict, offset: 0xE84u);
    }
    this->m_attachmentPointRagdollSpace.m_Value = vTemp;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019F6F0
// Name: class CRagdollProp __near * CreateServerRagdollAttached(class CBaseAnimating __near *,class Vector const __near &,int,int,class IPhysicsObject __near *,class CBaseAnimating __near *,int,class Vector const __near &,int,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
CRagdollPropAttached *__usercall CreateServerRagdollAttached@<eax>(
        int a1@<ebp>,
        int a2@<edi>,
        int a3@<esi>,
        CBaseAnimating *pAnimating,
        const Vector *vecForce,
        int forceBone,
        CBaseEntity::NetworkVar_m_Collision *collisionGroup,
        IPhysicsObject *pAttached,
        CBaseAnimating *pParentEntity,
        int boneAttach,
        const Vector *originAttached,
        float parentBoneAttach,
        const Vector *boneOrigin)
{
  void *v13; // esp
  IVModelInfo_vtbl *v14; // edi
  int v15; // eax
  CRagdollPropAttached *result; // eax
  CRagdollPropAttached *NoSpawn; // edi
  void (__thiscall *SetupBones)(CBaseAnimating *, matrix3x4a_t *, int); // edx
  matrix3x4_t v20[255]; // [esp+38h] [ebp-300Ch] BYREF
  int v21; // [esp+302Ch] [ebp-18h]
  _DWORD v22[3]; // [esp+3038h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+3044h] [ebp+0h]

  v22[0] = a1;
  v22[1] = retaddr;
  v13 = alloca(12296);
  v14 = modelinfo->__vftable;
  v15 = ((int (__thiscall *)(CBaseAnimating *, int, int))pAnimating->GetModelIndex)(a1: pAnimating, a2, a3);
  result = (CRagdollPropAttached *)v14->GetVCollide(this: modelinfo, a2: v15);
  if ( result != nullptr )
  {
    if ( (pAnimating->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: pAnimating, a2: (int)v22);
    NoSpawn = (CRagdollPropAttached *)CBaseEntity::CreateNoSpawn(
                                        szName: "prop_ragdoll_attached",
                                        vecOrigin: &pAnimating->m_vecAbsOrigin,
                                        vecAngles: &vec3_angle,
                                        pOwner: nullptr);
    CBaseAnimating::CopyAnimationDataFrom(this: NoSpawn, pSource: pAnimating);
    CRagdollProp::InitRagdollAnimation(this: NoSpawn);
    SetupBones = pAnimating->SetupBones;
    v21 = 524032;
    ((void (__thiscall *)(CBaseAnimating *, matrix3x4_t *))SetupBones)(a1: pAnimating, a2: v20);
    CRagdollPropAttached::InitRagdollAttached(
      this: NoSpawn,
      pAttached,
      forceVector: vecForce,
      forceBone,
      pPrevBones: v20,
      pBoneToWorld: v20,
      dt: 0.1,
      collisionGroup,
      pFollow: *(float *)&pParentEntity,
      boneIndexRoot: boneAttach,
      boneLocalOrigin: boneOrigin,
      parentBoneAttach,
      worldAttachOrigin: originAttached);
    return NoSpawn;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1019F7F0
// Name: void DetachAttachedRagdollsForEntity(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DetachAttachedRagdollsForEntity(CBaseEntity *pRagdollParent)
{
  int i; // esi
  _BYTE *v2; // eax
  CBaseEntity **m_pMemory; // eax
  CUtlVector<CBaseEntity *,CUtlMemory<CBaseEntity *,int> > list; // [esp+8h] [ebp-14h] BYREF

  memset(&list, 0, sizeof(list));
  GetAllChildren(pParent: pRagdollParent, &list);
  for ( i = list.m_Size - 1; i >= 0; --i )
  {
    v2 = __RTDynamicCast(
           inptr: list.m_Memory.m_pMemory[i],
           VfDelta: 0,
           SrcType: &CBaseEntity `RTTI Type Descriptor',
           TargetType: &CRagdollPropAttached `RTTI Type Descriptor',
           isReference: 0);
    if ( v2 != nullptr )
      v2[3728] = 1;
  }
  m_pMemory = list.m_Memory.m_pMemory;
  list.m_Size = 0;
  if ( list.m_Memory.m_nGrowSize >= 0 )
  {
    if ( list.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: list.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      list.m_Memory.m_pMemory = nullptr;
    }
    list.m_Memory.m_nAllocationCount = 0;
  }
  list.m_pElements = m_pMemory;
  if ( list.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1019F8F0
// Name: public: virtual void CRagdollProp::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __usercall CRagdollProp::Spawn(CRagdollProp *this@<ecx>, int a2@<ebp>, int a3@<edi>, int a4@<esi>)
{
  void *v4; // esp
  string_t (__thiscall *GetModelName)(struct CBaseEntity *); // edx
  const char *v7; // eax
  CStudioHdr *m_pStudioHdr; // eax
  bool v9; // zf
  edict_t *m_pPev; // ecx
  edict_t *v11; // ecx
  int m_Value; // eax
  matrix3x4_t v14[255]; // [esp+28h] [ebp-301Ch] BYREF
  const studiohdr_t *flFadeScale; // [esp+3030h] [ebp-14h]
  int v16; // [esp+3034h] [ebp-10h] BYREF
  _DWORD v17[3]; // [esp+3038h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+3044h] [ebp+0h]

  v17[0] = a2;
  v17[1] = retaddr;
  v4 = alloca(12312);
  this->m_flDefaultFadeScale = CBaseEntity::GetGlobalFadeScale(this);
  ((void (__thiscall *)(CRagdollProp *, int, int))this->Precache)(a1: this, a2: a3, a3: a4);
  GetModelName = this->GetModelName;
  v16 = (int)&v16;
  v7 = *(const char **)((int (__thiscall *)(CRagdollProp *))GetModelName)(a1: this);
  if ( v7 == nullptr )
    v7 = locale;
  this->SetModel(this, a2: v7);
  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    m_pStudioHdr = nullptr;
  v9 = (m_pStudioHdr->m_pStudioHdr->flags & 0x800) == 0;
  flFadeScale = m_pStudioHdr->m_pStudioHdr;
  if ( v9 )
  {
    CBaseEntity::SetGlobalFadeScale(this, flFadeScale: this->m_flDefaultFadeScale);
  }
  else
  {
    CBaseEntity::SetGlobalFadeScale(this, flFadeScale: 0.0);
    this->m_flDefaultFadeScale = 0.0;
  }
  CBaseAnimating::SetupBones(this, a2: (int)v17, pBoneToWorld: (matrix3x4a_t *)v14, boneMask: (CBoneCache *)0x7FF00);
  CBaseEntity::SetAbsAngles(this, absAngles: &vec3_angle);
  CRagdollProp::InitRagdoll(
    this,
    forceVector: &vec3_origin,
    forceBone: 0,
    forcePos: &vec3_origin,
    pPrevBones: v14,
    pBoneToWorld: v14,
    dt: 0.0,
    collisionGroup: (CBaseEntity::NetworkVar_m_Collision *)((this->m_spawnflags.m_Value & 4) != 0),
    activateRagdoll: (IPhysicsObject **)1,
    bWakeRagdoll: (this->m_spawnflags.m_Value & 0x10000) == 0);
  this->m_lastUpdateTickCount = 0;
  if ( this->m_flBlendWeight.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xB64u);
    }
    this->m_flBlendWeight.m_Value = 0.0;
  }
  if ( this->m_nOverlaySequence.m_Value != -1 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v11 = this->m_Network.m_pPev;
      if ( v11 != nullptr )
        CBaseEdict::StateChanged(this: &v11->CBaseEdict, offset: 0xB68u);
    }
    this->m_nOverlaySequence.m_Value = -1;
  }
  m_Value = this->m_spawnflags.m_Value;
  if ( (m_Value & 0x2000) == 0 )
    this->m_iEFlags |= 0x8000000u;
  if ( (m_Value & 0x4000) != 0 )
    CRagdollProp::DisableMotion(this);
  if ( this->m_bStartDisabled )
    CBaseEntity::AddEffects(this, nEffects: 32);
}

//------------------------------------------------------------------------------
// Address: 0x1019FAE0
// Name: private: void CRagdollProp::FadeOutThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRagdollProp::FadeOutThink(CRagdollProp *this)
{
  float curtime; // xmm1_4
  float v3; // xmm0_4
  float m_flFadeTime; // xmm1_4
  int v5; // ebx
  edict_t *m_pPev; // ecx
  edict_t *v7; // ecx
  edict_t *v8; // ecx
  CBasePlayer *LocalPlayer; // eax
  CTakeDamageInfo info; // [esp+14h] [ebp-5Ch] BYREF

  curtime = gpGlobals->curtime;
  v3 = curtime - this->m_flFadeOutStartTime;
  if ( v3 >= 0.0 )
  {
    m_flFadeTime = this->m_flFadeTime;
    if ( m_flFadeTime <= v3 )
    {
      LocalPlayer = UTIL_GetLocalPlayer();
      CTakeDamageInfo::CTakeDamageInfo(
        this: &info,
        pInflictor: LocalPlayer,
        pAttacker: LocalPlayer,
        flDamage: 10000.0,
        bitsDamageType: 0,
        iKillType: 0,
        iObjectsPenetrated: 0);
      CBaseEntity::TakeDamage(this, a2: (int)this, inputInfo: &info);
      UTIL_Remove(oldObj: this);
    }
    else
    {
      v5 = (int)(float)((float)(1.0 - (float)(v3 / m_flFadeTime)) * 255.0);
      if ( this->m_nRenderMode.m_Value != 2 )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          m_pPev = this->m_Network.m_pPev;
          if ( m_pPev != nullptr )
            CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xB5u);
        }
        this->m_nRenderMode.m_Value = 2;
      }
      if ( this->m_clrRender.m_Value.a != (_BYTE)v5 )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          v7 = this->m_Network.m_pPev;
          if ( v7 != nullptr )
            CBaseEdict::StateChanged(this: &v7->CBaseEdict, offset: 0xB8u);
        }
        this->m_clrRender.m_Value.a = v5;
      }
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v8 = this->m_Network.m_pPev;
        if ( v8 != nullptr )
        {
          v8->m_fStateFlags |= 0x101u;
          CBaseEdict::GetChangeAccessor(this: &v8->CBaseEdict)->m_iChangeInfoSerialNumber = 0;
        }
      }
      CBaseEntity::ThinkSet(
        this,
        func: (void (__thiscall *)(CBaseEntity *))CRagdollProp::FadeOutThink,
        thinkTime: gpGlobals->interval_per_tick + gpGlobals->curtime,
        szContext: s_pFadeOutContext);
    }
  }
  else
  {
    CBaseEntity::ThinkSet(
      this,
      func: (void (__thiscall *)(CBaseEntity *))CRagdollProp::FadeOutThink,
      thinkTime: curtime + 0.1,
      szContext: s_pFadeOutContext);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019FD20
// Name: class CBaseEntity __near * CreateServerRagdoll(class CBaseAnimating __near *,int,class CTakeDamageInfo const __near &,int,bool)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
CRagdollProp *__usercall CreateServerRagdoll@<eax>(
        int a1@<ebp>,
        int a2@<edi>,
        int a3@<esi>,
        CBaseAnimating *pAnimating,
        int forceBone,
        const CTakeDamageInfo *info,
        CBaseEntity::NetworkVar_m_Collision *collisionGroup,
        bool bUseLRURetirement)
{
  void *v8; // esp
  IPhysicsObject *m_pPhysicsObject; // ecx
  CRagdollProp *NoSpawn; // edi
  unsigned int v11; // eax
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  const char *pszValue; // eax
  int m_Value; // edi
  unsigned __int16 m_fBoneCacheFlags; // dx
  bool v17; // zf
  CStudioHdr *m_pStudioHdr; // eax
  float v19; // xmm1_4
  float v20; // xmm5_4
  void (__thiscall *SetupBones)(CBaseAnimating *, matrix3x4a_t *, int); // edx
  edict_t *m_pPev; // ecx
  void (__thiscall *v23)(CBaseAnimating *, matrix3x4a_t *, int); // edx
  edict_t *v24; // ecx
  unsigned int v25; // edx
  float z; // eax
  float v27; // xmm2_4
  int v28; // xmm0_4
  float v29; // xmm1_4
  __int128 v30; // xmm4
  CStudioHdr *v31; // eax
  CStudioHdr *v32; // eax
  int numbones; // eax
  matrix3x4_t *v34; // edi
  float v35; // ecx
  int v36; // eax
  int v37; // edi
  CStudioHdr *v38; // eax
  double Mass; // st7
  float v40; // xmm0_4
  int HitboxBone; // eax
  int PhysicsBone; // eax
  int *v43; // edi
  __int64 v44; // xmm0_8
  int v45; // eax
  double (__thiscall *v46)(int *); // edx
  void (__thiscall *v47)(int *, char *); // edx
  __int64 v48; // xmm0_8
  float v49; // ecx
  float v50; // eax
  __int64 v51; // xmm0_8
  CRagdollProp *v52; // edi
  int v53; // eax
  int v54; // edx
  edict_t *v55; // ecx
  const Vector *v56; // eax
  CBaseEntity::NetworkVar_m_Collision_vtbl *v57; // edx
  CRagdollProp *v58; // esi
  matrix3x4_t v61[256]; // [esp+40h] [ebp-627Ch] BYREF
  CRagdollProp v62[3]; // [esp+3040h] [ebp-327Ch] BYREF
  int v63[129]; // [esp+6048h] [ebp-274h] BYREF
  Vector v64; // [esp+624Ch] [ebp-70h] BYREF
  Vector v65; // [esp+6258h] [ebp-64h] BYREF
  QAngle v66; // [esp+6264h] [ebp-58h] BYREF
  _QWORD v67[2]; // [esp+6270h] [ebp-4Ch] BYREF
  int v68; // [esp+6284h] [ebp-38h]
  Vector v69; // [esp+6288h] [ebp-34h] BYREF
  CRagdollProp *v70; // [esp+6294h] [ebp-28h]
  int flCycleFrom; // [esp+6298h] [ebp-24h]
  float flCycleTo; // [esp+629Ch] [ebp-20h]
  __int64 v73; // [esp+62A0h] [ebp-1Ch] BYREF
  int dist; // [esp+62A8h] [ebp-14h]
  int v75; // [esp+62ACh] [ebp-10h]
  _DWORD v76[3]; // [esp+62B0h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+62BCh] [ebp+0h]

  v76[0] = a1;
  v76[1] = retaddr;
  v8 = alloca(25208);
  if ( (info->m_bitsDamageType & 0x11) != 0 )
  {
    m_pPhysicsObject = pAnimating->m_pPhysicsObject;
    if ( m_pPhysicsObject != nullptr )
    {
      m_pPhysicsObject->GetShadowPosition(this: m_pPhysicsObject, a2: (Vector *)((char *)v67 + 4), a3: nullptr);
      CBaseEntity::SetAbsOrigin(this: pAnimating, absOrigin: (const Vector *)((char *)v67 + 4));
    }
  }
  if ( (pAnimating->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: pAnimating, a2: (int)v76);
  NoSpawn = (CRagdollProp *)CBaseEntity::CreateNoSpawn(
                              szName: "prop_ragdoll",
                              vecOrigin: &pAnimating->m_vecAbsOrigin,
                              vecAngles: &vec3_angle,
                              pOwner: nullptr);
  v70 = NoSpawn;
  CBaseAnimating::CopyAnimationDataFrom(this: NoSpawn, pSource: pAnimating);
  ((void (__thiscall *)(CRagdollProp *, CBaseAnimating *, int, int))NoSpawn->SetOwnerEntity)(
    a1: NoSpawn,
    a2: pAnimating,
    a3: a2,
    a4: a3);
  CRagdollProp::InitRagdollAnimation(this: NoSpawn);
  v11 = (unsigned int)pAnimating->m_iEFlags >> 27;
  *(float *)&v75 = 0.1;
  if ( (v11 & 1) != 0 )
    NoSpawn->m_iEFlags |= 0x8000000u;
  m_Index = info->m_hInflictor.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  if ( m_pEntity != nullptr )
    NoSpawn->m_hKiller.m_Index = m_pEntity->GetRefEHandle(this: m_pEntity)->m_Index;
  else
    NoSpawn->m_hKiller.m_Index = -1;
  pszValue = pAnimating->m_iClassname.pszValue;
  if ( pszValue == nullptr || *pszValue == 0 )
    pszValue = nullptr;
  NoSpawn->m_strSourceClassName.pszValue = pszValue;
  m_Value = pAnimating->m_nSequence.m_Value;
  m_fBoneCacheFlags = pAnimating->m_fBoneCacheFlags;
  v17 = pAnimating->m_pStudioHdr == nullptr;
  v68 = m_fBoneCacheFlags;
  pAnimating->m_fBoneCacheFlags = m_fBoneCacheFlags | 1;
  if ( v17 && CBaseEntity::GetModel(this: pAnimating) != nullptr )
    CBaseAnimating::LockStudioHdr(this: pAnimating);
  m_pStudioHdr = pAnimating->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    m_pStudioHdr = nullptr;
  *(float *)&flCycleFrom = CBaseAnimating::SequenceDuration(
                             this: pAnimating,
                             pStudioHdr: m_pStudioHdr,
                             iSequence: m_Value);
  v19 = pAnimating->m_flCycle.m_Value;
  if ( (float)(v19 * *(float *)&flCycleFrom) <= 0.1 && (float)(v19 * *(float *)&flCycleFrom) > 0.0 )
    *(float *)&v75 = pAnimating->m_flCycle.m_Value * *(float *)&flCycleFrom;
  v20 = (float)(1.0 / *(float *)&flCycleFrom) * *(float *)&v75;
  if ( (float)(v19 - v20) >= 0.0 )
  {
    if ( (float)(v19 - v20) <= 1.0 )
      flCycleTo = v19 - v20;
    else
      flCycleTo = 1.0;
  }
  else
  {
    flCycleTo = 0.0;
  }
  SetupBones = pAnimating->SetupBones;
  *(float *)&flCycleFrom = v19;
  SetupBones(this: pAnimating, a2: (matrix3x4a_t *)v61, a3: 524032);
  if ( pAnimating->m_flCycle.m_Value != flCycleTo )
  {
    if ( pAnimating->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&pAnimating->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = pAnimating->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x3ACu);
    }
    pAnimating->m_flCycle.m_Value = flCycleTo;
  }
  v23 = pAnimating->SetupBones;
  v75 = 524032;
  ((void (__thiscall *)(CBaseAnimating *, CRagdollProp *))v23)(a1: pAnimating, a2: v62);
  if ( pAnimating->m_flCycle.m_Value != *(float *)&flCycleFrom )
  {
    if ( pAnimating->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&pAnimating->m_Network + 76) |= 1u;
    }
    else
    {
      v24 = pAnimating->m_Network.m_pPev;
      if ( v24 != nullptr )
        CBaseEdict::StateChanged(this: &v24->CBaseEdict, offset: 0x3ACu);
    }
    pAnimating->m_flCycle.m_Value = *(float *)&flCycleFrom;
  }
  v25 = (unsigned int)pAnimating->m_iEFlags >> 12;
  pAnimating->m_fBoneCacheFlags = v68 | pAnimating->m_fBoneCacheFlags & 0xFFFE;
  if ( (v25 & 1) != 0 )
    CBaseEntity::CalcAbsoluteVelocity(this: pAnimating, a2: (int)v76);
  z = pAnimating->m_vecAbsVelocity.z;
  v73 = *(_QWORD *)&pAnimating->m_vecAbsVelocity.x;
  v27 = *(float *)&v73;
  *(float *)&dist = z;
  *(float *)&v28 = z;
  v29 = *((float *)&v73 + 1);
  v30 = 0;
  *(float *)&v30 = fsqrt((float)((float)(*(float *)&v28 * *(float *)&v28) + (float)(v27 * v27)) + (float)(v29 * v29));
  *(_OWORD *)v67 = v30;
  if ( *(float *)&v30 == 0.0 && *(float *)&v75 > 0.0 )
  {
    if ( pAnimating->m_pStudioHdr == nullptr )
    {
      if ( CBaseEntity::GetModel(this: pAnimating) != nullptr )
        CBaseAnimating::LockStudioHdr(this: pAnimating);
      v27 = *(float *)&v73;
      v29 = *((float *)&v73 + 1);
      v28 = dist;
    }
    v31 = pAnimating->m_pStudioHdr;
    if ( v31 != nullptr && v31->m_pStudioHdr != nullptr )
    {
      if ( Studio_SeqMovement(
             pStudioHdr: v31,
             iSequence: pAnimating->m_nSequence.m_Value,
             flCycleFrom: pAnimating->m_flCycle.m_Value,
             flCycleTo: pAnimating->m_flCycle.m_Value,
             poseParameter: pAnimating->m_flPoseParameter.m_Value,
             deltaPos: (Vector *)((char *)v67 + 4),
             deltaAngles: &v66) )
      {
        if ( (pAnimating->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: pAnimating, a2: (int)v76);
        VectorRotate(in1: (const float *)v67 + 1, in2: &pAnimating->m_rgflCoordinateFrame, out: (float *)&v73);
        v27 = (float)(1.0 / *(float *)&v75) * *(float *)&v73;
        v29 = *((float *)&v73 + 1) * (float)(1.0 / *(float *)&v75);
        *(float *)&v28 = *(float *)&dist * (float)(1.0 / *(float *)&v75);
        *(float *)&v73 = v27;
        *((float *)&v73 + 1) = v29;
        dist = v28;
      }
      else
      {
        v28 = dist;
        v29 = *((float *)&v73 + 1);
        v27 = *(float *)&v73;
      }
    }
  }
  if ( (float)((float)((float)(v27 * v27) + (float)(v29 * v29)) + (float)(*(float *)&v28 * *(float *)&v28)) > 0.0 )
  {
    if ( pAnimating->m_pStudioHdr == nullptr )
    {
      if ( CBaseEntity::GetModel(this: pAnimating) != nullptr )
        CBaseAnimating::LockStudioHdr(this: pAnimating);
      v27 = *(float *)&v73;
      v29 = *((float *)&v73 + 1);
      v28 = dist;
    }
    v32 = pAnimating->m_pStudioHdr;
    if ( v32 == nullptr || v32->m_pStudioHdr == nullptr )
      v32 = nullptr;
    numbones = v32->m_pStudioHdr->numbones;
    *(float *)&v73 = v27 * *(float *)&v75;
    *((float *)&v73 + 1) = v29 * *(float *)&v75;
    *(float *)&dist = *(float *)&v28 * *(float *)&v75;
    if ( numbones > 0 )
    {
      v34 = (matrix3x4_t *)v62;
      flCycleFrom = numbones;
      do
      {
        MatrixGetColumn(in: v34, column: 3, out: &v69);
        v69.x = v69.x - *(float *)&v73;
        v69.y = v69.y - *((float *)&v73 + 1);
        v69.z = v69.z - *(float *)&dist;
        MatrixSetColumn(in: &v69, column: 3, out: v34++);
        --flCycleFrom;
      }
      while ( *(float *)&flCycleFrom != 0.0 );
    }
  }
  if ( (info->m_bitsDamageType & 0x10) != 0 && pAnimating->MyNPCPointer(this: pAnimating) != nullptr )
  {
    CRagdollProp::InitRagdoll(
      this: v70,
      forceVector: &vec3_origin,
      forceBone: -1,
      forcePos: &vec3_origin,
      pPrevBones: (matrix3x4_t *)v62,
      pBoneToWorld: v61,
      dt: *(float *)&v75,
      collisionGroup,
      activateRagdoll: (IPhysicsObject **)1,
      bWakeRagdoll: true);
    v35 = info->m_vecDamagePosition.z;
    v66.z = -1.0;
    *(_QWORD *)&v69.x = *(_QWORD *)&info->m_vecDamagePosition.x;
    v66.x = 0.0;
    v66.y = 0.0;
    v69.z = v35;
    *(float *)&v36 = COERCE_FLOAT(
                       CBaseAnimating::GetHitboxesFrontside(
                         this: pAnimating,
                         boxList: v63,
                         boxMax: 128,
                         normal: (const Vector *)&v66,
                         dist: (float)((float)(v69.y + v69.x) * 0.0) - (float)(v35 * 1.0)));
    v17 = pAnimating->m_pStudioHdr == nullptr;
    v37 = v36;
    flCycleFrom = v36;
    if ( v17 && CBaseEntity::GetModel(this: pAnimating) != nullptr )
      CBaseAnimating::LockStudioHdr(this: pAnimating);
    v38 = pAnimating->m_pStudioHdr;
    if ( v38 == nullptr || v38->m_pStudioHdr == nullptr )
      v38 = nullptr;
    Mass = Studio_GetMass(pstudiohdr: v38);
    flCycleTo = Mass;
    if ( Mass >= 1.0 )
    {
      v40 = flCycleTo;
      if ( flCycleTo > 10000.0 )
        v40 = 10000.0;
    }
    else
    {
      v40 = 1.0;
    }
    flCycleTo = 1.0 / v40;
    *(float *)&v75 = 0.0;
    if ( v37 > 0 )
    {
      do
      {
        HitboxBone = CBaseAnimating::GetHitboxBone(this: pAnimating, hitboxIndex: v63[v75]);
        PhysicsBone = CBaseAnimating::GetPhysicsBone(this: pAnimating, boneIndex: HitboxBone);
        v43 = *((int **)&v70->m_Network + 6 * PhysicsBone + 295);
        v44 = *(_QWORD *)&info->m_vecDamageForce.x;
        v45 = *v43;
        v69.z = info->m_vecDamageForce.z;
        v46 = *(double (__thiscall **)(int *))(v45 + 116);
        *(_QWORD *)&v69.x = v44;
        *(float *)&v68 = v46(a1: v43);
        v47 = *(void (__thiscall **)(int *, char *))(*v43 + 240);
        *((float *)v67 + 1) = (float)(v69.x * *(float *)&v68) * flCycleTo;
        *(float *)&v67[1] = (float)(v69.y * *(float *)&v68) * flCycleTo;
        *((float *)&v67[1] + 1) = (float)(v69.z * *(float *)&v68) * flCycleTo;
        v47(a1: v43, a2: (char *)v67 + 4);
        ++v75;
      }
      while ( v75 < flCycleFrom );
    }
  }
  else
  {
    v48 = *(_QWORD *)&info->m_vecDamagePosition.x;
    v49 = info->m_vecDamageForce.z;
    v50 = info->m_vecDamagePosition.z;
    dist = 1;
    v73 = (unsigned int)collisionGroup | 0x100000000LL;
    flCycleTo = v49;
    *(_QWORD *)((char *)v67 + 4) = v48;
    v51 = *(_QWORD *)&info->m_vecDamageForce.x;
    *((float *)&v67[1] + 1) = v50;
    *(_QWORD *)&v66.x = v51;
    v66.z = v49;
    CRagdollProp::InitRagdoll(
      this: v62,
      forceVector: (const Vector *)&v66,
      forceBone,
      forcePos: (const Vector *)((char *)v67 + 4),
      pPrevBones: (matrix3x4_t *)v62,
      pBoneToWorld: v61,
      dt: *(float *)&v75,
      collisionGroup,
      activateRagdoll: (IPhysicsObject **)1,
      bWakeRagdoll: true);
  }
  if ( (pAnimating->m_fFlags.m_Value & 0x20000000) != 0 )
  {
    CBaseAnimating::TransferDissolveFrom(this: v70, pAnim: pAnimating);
  }
  else if ( bUseLRURetirement )
  {
    v52 = v70;
    v53 = v70->m_spawnflags.m_Value;
    v54 = v53 | 0x1000;
    v68 = v53 | 0x1000;
    if ( v53 != (v53 | 0x1000) )
    {
      if ( v70->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&v70->m_Network + 76) |= 1u;
      }
      else
      {
        v55 = v70->m_Network.m_pPev;
        if ( v55 != nullptr )
        {
          CBaseEdict::StateChanged(this: &v55->CBaseEdict, offset: 0x2F8u);
          v54 = v68;
        }
      }
      v52->m_spawnflags.m_Value = v54;
    }
    CRagdollLRURetirement::MoveToTopOfLRU(
      this: &s_RagdollLRU,
      pRagdoll: v70,
      bImportant: false,
      flForcedRetireTime: 0.0);
  }
  v56 = pAnimating->m_Collision.OBBMins(this: &pAnimating->m_Collision);
  v57 = pAnimating->m_Collision.CBaseEntity::__vftable;
  v64.x = v56->x;
  v64.y = v56->y;
  v57->OBBMaxs(this: &pAnimating->m_Collision);
  v58 = v70;
  CCollisionProperty::SetCollisionBounds(this: &v70->m_Collision, mins: &v64, maxs: &v65);
  return v58;
}

//------------------------------------------------------------------------------
// Address: 0x101A0580
// Name: public: void CRagdollProp::FadeOut(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRagdollProp::FadeOut(CRagdollProp *this, float flDelay, float fadeTime)
{
  float v4; // xmm0_4

  if ( CBaseEntity::GetNextThink(this, szContext: s_pFadeOutContext) < gpGlobals->curtime )
  {
    v4 = fadeTime;
    if ( fadeTime == -1.0 )
      v4 = 0.5;
    this->m_flFadeTime = v4;
    this->m_flFadeOutStartTime = gpGlobals->curtime + flDelay;
    CBaseEntity::SetGlobalFadeScale(this, flFadeScale: 0.0);
    CBaseEntity::ThinkSet(
      this,
      func: (void (__thiscall *)(CBaseEntity *))CRagdollProp::FadeOutThink,
      thinkTime: (float)(gpGlobals->curtime + flDelay) + 0.0099999998,
      szContext: s_pFadeOutContext);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A0630
// Name: public: void CRagdollProp::InputFadeAndRemove(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRagdollProp::InputFadeAndRemove(CRagdollProp *this, inputdata_t *inputdata)
{
  float fadeTime; // xmm0_4

  if ( inputdata->value.fieldType != FIELD_FLOAT || (fadeTime = inputdata->value.flVal) == 0.0 )
    fadeTime = 1.0;
  CRagdollProp::FadeOut(this, flDelay: 0.0, fadeTime);
}

//------------------------------------------------------------------------------
// Address: 0x101E72E0
// Name: public: void CRagdollProp::InputTurnOn(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRagdollProp::InputTurnOn(CRagdollProp *this, inputdata_t *inputdata)
{
  unsigned int v3; // esi
  edict_t *m_pPev; // ecx

  v3 = this->m_fEffects.m_Value & 0xFFFFFFDF;
  if ( this->m_fEffects.m_Value != v3 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xA4u);
    }
    this->m_fEffects.m_Value = v3;
  }
  if ( this->m_Network.m_pPev != nullptr )
    this->m_Network.m_pPev->m_fStateFlags |= 0x80u;
  CBaseEntity::DispatchUpdateTransmitState(this);
}

//------------------------------------------------------------------------------
// Address: 0x104076E0
// Name: DT_Ragdoll::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_Ragdoll::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_Ragdoll::g_SendTable);
  return atexit(func: DT_Ragdoll::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10407700
// Name: DT_Ragdoll::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_Ragdoll::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_Ragdoll::ignored>();
  DT_Ragdoll::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10407710
// Name: CRagdollProp_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CRagdollProp_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CRagdollProp>(__formal: nullptr);
  CRagdollProp_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10407760
// Name: DT_Ragdoll_Attached::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_Ragdoll_Attached::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_Ragdoll_Attached::g_SendTable);
  return atexit(func: DT_Ragdoll_Attached::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10407780
// Name: DT_Ragdoll_Attached::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_Ragdoll_Attached::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_Ragdoll_Attached::ignored>();
  DT_Ragdoll_Attached::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10407790
// Name: CRagdollPropAttached_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CRagdollPropAttached_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CRagdollPropAttached>(__formal: nullptr);
  CRagdollPropAttached_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041CDE0
// Name: DT_Ragdoll::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_Ragdoll::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_Ragdoll::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041CDF0
// Name: DT_Ragdoll_Attached::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_Ragdoll_Attached::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_Ragdoll_Attached::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1019FC50
// Name: struct datamap_t __near * DataMapInit<class CRagdollPropAttached>(class CRagdollPropAttached __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CRagdollPropAttached>()
{
  if ( (_S6_17 & 1) == 0 )
  {
    _S6_17 |= 1u;
    nameHolder_311.m_pszBase = "CRagdollPropAttached";
    nameHolder_311.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_311.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_311.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_311.m_Names.m_Size = 0;
    nameHolder_311.m_Names.m_pElements = nullptr;
    nameHolder_311.m_nLenBase = 20;
    atexit(func: DataMapInit_CRagdollPropAttached__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CRagdollPropAttached::m_DataMap.baseMap = &CRagdollProp::m_DataMap;
  if ( (_S6_17 & 2) == 0 )
  {
    _S6_17 |= 2u;
    dataDesc_298[6].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSCONSTRAINT);
    dataDesc_298[6].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_298[6].td = 0;
    *(_QWORD *)&dataDesc_298[6].override_field = 0;
    *(_QWORD *)&dataDesc_298[6].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_298[6].flatOffset[1] = 0;
  }
  CRagdollPropAttached::m_DataMap.dataNumFields = 6;
  CRagdollPropAttached::m_DataMap.dataDesc = &dataDesc_298[1];
  return &CRagdollPropAttached::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101A06B0
// Name: struct datamap_t __near * DataMapInit<class CRagdollProp>(class CRagdollProp __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CRagdollProp>()
{
  char *Name; // eax
  CPhysObjSaveRestoreOps *PhysObjSaveRestoreOps; // eax
  CPhysObjSaveRestoreOps *v2; // eax
  CPhysObjSaveRestoreOps *v3; // eax
  CPhysObjSaveRestoreOps *v4; // eax
  CPhysObjSaveRestoreOps *v5; // eax
  CPhysObjSaveRestoreOps *v6; // eax
  CPhysObjSaveRestoreOps *v7; // eax
  CPhysObjSaveRestoreOps *v8; // eax
  CPhysObjSaveRestoreOps *v9; // eax
  CPhysObjSaveRestoreOps *v10; // eax
  CPhysObjSaveRestoreOps *v11; // eax
  CPhysObjSaveRestoreOps *v12; // eax
  CPhysObjSaveRestoreOps *v13; // eax
  CPhysObjSaveRestoreOps *v14; // eax
  CPhysObjSaveRestoreOps *v15; // eax
  CPhysObjSaveRestoreOps *v16; // eax
  CPhysObjSaveRestoreOps *v17; // eax
  CPhysObjSaveRestoreOps *v18; // eax

  if ( (_S3_91 & 1) == 0 )
  {
    _S3_91 |= 1u;
    nameHolder_312.m_pszBase = "CRagdollProp";
    nameHolder_312.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_312.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_312.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_312.m_Names.m_Size = 0;
    nameHolder_312.m_Names.m_pElements = nullptr;
    nameHolder_312.m_nLenBase = 12;
    atexit(func: DataMapInit_CRagdollProp__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CRagdollProp::m_DataMap.baseMap = &CBaseAnimating::m_DataMap;
  if ( (_S3_91 & 2) == 0 )
  {
    _S3_91 |= 2u;
    dataDesc_299[28].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_312,
                                   pszIdentifier: "SetDebrisThink");
    dataDesc_299[28].fieldOffset = 0;
    *(_DWORD *)&dataDesc_299[28].fieldSize = 2097153;
    dataDesc_299[28].externalName = nullptr;
    dataDesc_299[28].pSaveRestoreOps = nullptr;
    dataDesc_299[28].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CRagdollProp::SetDebrisThink;
    *(_QWORD *)&dataDesc_299[28].td = 0;
    *(_QWORD *)&dataDesc_299[28].override_field = 0;
    *(_QWORD *)&dataDesc_299[28].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_299[28].flatOffset[1] = 0;
    dataDesc_299[29].fieldType = FIELD_VOID;
    dataDesc_299[29].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                   this: &nameHolder_312,
                                   pszIdentifier: "ClearFlagsThink");
    dataDesc_299[29].fieldOffset = 0;
    *(_DWORD *)&dataDesc_299[29].fieldSize = 2097153;
    dataDesc_299[29].externalName = nullptr;
    dataDesc_299[29].pSaveRestoreOps = nullptr;
    dataDesc_299[29].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CRagdollProp::ClearFlagsThink;
    *(_QWORD *)&dataDesc_299[29].td = 0;
    *(_QWORD *)&dataDesc_299[29].override_field = 0;
    *(_QWORD *)&dataDesc_299[29].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_299[29].flatOffset[1] = 0;
    dataDesc_299[30].fieldType = FIELD_VOID;
    Name = CDatadescGeneratedNameHolder::GenerateName(this: &nameHolder_312, pszIdentifier: "FadeOutThink");
    *(_QWORD *)&dataDesc_299[30].td = 0;
    *(_QWORD *)&dataDesc_299[30].override_field = 0;
    *(_QWORD *)&dataDesc_299[30].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_299[30].flatOffset[1] = 0;
    dataDesc_299[31].fieldTolerance = 0.0;
    dataDesc_299[32].fieldTolerance = 0.0;
    dataDesc_299[30].fieldName = Name;
    dataDesc_299[30].fieldOffset = 0;
    *(_DWORD *)&dataDesc_299[30].fieldSize = 2097153;
    dataDesc_299[30].externalName = nullptr;
    dataDesc_299[30].pSaveRestoreOps = nullptr;
    dataDesc_299[30].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CRagdollProp::FadeOutThink;
    dataDesc_299[31].fieldType = FIELD_INTEGER;
    dataDesc_299[31].fieldName = "m_ragdoll.listCount";
    dataDesc_299[31].fieldOffset = 1168;
    *(_DWORD *)&dataDesc_299[31].fieldSize = 131073;
    dataDesc_299[31].externalName = nullptr;
    dataDesc_299[31].pSaveRestoreOps = nullptr;
    dataDesc_299[31].inputFunc = nullptr;
    dataDesc_299[31].td = nullptr;
    dataDesc_299[31].fieldSizeInBytes = 4;
    dataDesc_299[31].override_field = nullptr;
    dataDesc_299[31].override_count = 0;
    *(_QWORD *)dataDesc_299[31].flatOffset = 0;
    *(_DWORD *)&dataDesc_299[31].flatGroup = 0;
    dataDesc_299[32].fieldType = FIELD_BOOLEAN;
    dataDesc_299[32].fieldName = "m_ragdoll.allowStretch";
    dataDesc_299[32].fieldOffset = 1172;
    *(_DWORD *)&dataDesc_299[32].fieldSize = 131073;
    dataDesc_299[32].externalName = nullptr;
    dataDesc_299[32].pSaveRestoreOps = nullptr;
    dataDesc_299[32].inputFunc = nullptr;
    dataDesc_299[32].td = nullptr;
    dataDesc_299[32].fieldSizeInBytes = 1;
    dataDesc_299[32].override_field = nullptr;
    dataDesc_299[32].override_count = 0;
    *(_QWORD *)dataDesc_299[32].flatOffset = 0;
    *(_DWORD *)&dataDesc_299[32].flatGroup = 0;
    dataDesc_299[33].fieldType = FIELD_CUSTOM;
    dataDesc_299[33].fieldName = "m_ragdoll.pGroup";
    dataDesc_299[33].fieldOffset = 1176;
    *(_DWORD *)&dataDesc_299[33].fieldSize = 131073;
    dataDesc_299[33].externalName = nullptr;
    PhysObjSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSCONSTRAINTGROUP);
    *(_QWORD *)&dataDesc_299[33].td = 0;
    *(_QWORD *)&dataDesc_299[33].override_field = 0;
    *(_QWORD *)&dataDesc_299[33].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_299[33].flatOffset[1] = 0;
    dataDesc_299[34].fieldTolerance = 0.0;
    dataDesc_299[35].fieldTolerance = 0.0;
    dataDesc_299[33].pSaveRestoreOps = PhysObjSaveRestoreOps;
    dataDesc_299[33].inputFunc = nullptr;
    dataDesc_299[34].fieldType = FIELD_FLOAT;
    dataDesc_299[34].fieldName = "m_flDefaultFadeScale";
    dataDesc_299[34].fieldOffset = 2924;
    *(_DWORD *)&dataDesc_299[34].fieldSize = 131073;
    dataDesc_299[34].externalName = nullptr;
    dataDesc_299[34].pSaveRestoreOps = nullptr;
    dataDesc_299[34].inputFunc = nullptr;
    dataDesc_299[34].td = nullptr;
    dataDesc_299[34].fieldSizeInBytes = 4;
    dataDesc_299[34].override_field = nullptr;
    dataDesc_299[34].override_count = 0;
    *(_QWORD *)dataDesc_299[34].flatOffset = 0;
    *(_DWORD *)&dataDesc_299[34].flatGroup = 0;
    dataDesc_299[35].fieldType = FIELD_VECTOR;
    dataDesc_299[35].fieldName = "m_ragdoll.list[1].originParentSpace";
    dataDesc_299[35].fieldOffset = 1204;
    *(_DWORD *)&dataDesc_299[35].fieldSize = 131073;
    dataDesc_299[35].externalName = nullptr;
    dataDesc_299[35].pSaveRestoreOps = nullptr;
    dataDesc_299[35].inputFunc = nullptr;
    dataDesc_299[35].td = nullptr;
    dataDesc_299[35].fieldSizeInBytes = 12;
    dataDesc_299[35].override_field = nullptr;
    dataDesc_299[35].override_count = 0;
    *(_QWORD *)dataDesc_299[35].flatOffset = 0;
    *(_DWORD *)&dataDesc_299[35].flatGroup = 0;
    dataDesc_299[36].fieldType = FIELD_CUSTOM;
    dataDesc_299[36].fieldName = "m_ragdoll.list[1].pObject";
    dataDesc_299[36].fieldOffset = 1216;
    *(_DWORD *)&dataDesc_299[36].fieldSize = 131073;
    dataDesc_299[36].externalName = nullptr;
    dataDesc_299[36].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSOBJECT);
    dataDesc_299[36].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_299[36].td = 0;
    *(_QWORD *)&dataDesc_299[36].override_field = 0;
    *(_QWORD *)&dataDesc_299[36].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_299[36].flatOffset[1] = 0;
    dataDesc_299[37].fieldType = FIELD_CUSTOM;
    dataDesc_299[37].fieldName = "m_ragdoll.list[1].pConstraint";
    dataDesc_299[37].fieldOffset = 1220;
    *(_DWORD *)&dataDesc_299[37].fieldSize = 131073;
    dataDesc_299[37].externalName = nullptr;
    dataDesc_299[37].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSCONSTRAINT);
    dataDesc_299[37].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_299[37].td = 0;
    *(_QWORD *)&dataDesc_299[37].override_field = 0;
    *(_QWORD *)&dataDesc_299[37].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_299[37].flatOffset[1] = 0;
    dataDesc_299[38].fieldType = FIELD_INTEGER;
    dataDesc_299[38].fieldName = "m_ragdoll.list[1].parentIndex";
    dataDesc_299[38].fieldOffset = 1224;
    *(_DWORD *)&dataDesc_299[38].fieldSize = 131073;
    dataDesc_299[38].externalName = nullptr;
    dataDesc_299[38].pSaveRestoreOps = nullptr;
    dataDesc_299[38].inputFunc = nullptr;
    dataDesc_299[38].td = nullptr;
    dataDesc_299[38].fieldSizeInBytes = 4;
    dataDesc_299[38].fieldTolerance = 0.0;
    dataDesc_299[39].fieldTolerance = 0.0;
    dataDesc_299[38].override_field = nullptr;
    dataDesc_299[38].override_count = 0;
    *(_QWORD *)dataDesc_299[38].flatOffset = 0;
    *(_DWORD *)&dataDesc_299[38].flatGroup = 0;
    dataDesc_299[39].fieldType = FIELD_VECTOR;
    dataDesc_299[39].fieldName = "m_ragdoll.list[2].originParentSpace";
    dataDesc_299[39].fieldOffset = 1228;
    *(_DWORD *)&dataDesc_299[39].fieldSize = 131073;
    dataDesc_299[39].externalName = nullptr;
    dataDesc_299[39].pSaveRestoreOps = nullptr;
    dataDesc_299[39].inputFunc = nullptr;
    dataDesc_299[39].td = nullptr;
    dataDesc_299[39].fieldSizeInBytes = 12;
    dataDesc_299[39].override_field = nullptr;
    dataDesc_299[39].override_count = 0;
    *(_QWORD *)dataDesc_299[39].flatOffset = 0;
    *(_DWORD *)&dataDesc_299[39].flatGroup = 0;
    dataDesc_299[40].fieldType = FIELD_CUSTOM;
    dataDesc_299[40].fieldName = "m_ragdoll.list[2].pObject";
    dataDesc_299[40].fieldOffset = 1240;
    *(_DWORD *)&dataDesc_299[40].fieldSize = 131073;
    dataDesc_299[40].externalName = nullptr;
    dataDesc_299[40].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSOBJECT);
    dataDesc_299[40].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_299[40].td = 0;
    *(_QWORD *)&dataDesc_299[40].override_field = 0;
    *(_QWORD *)&dataDesc_299[40].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_299[40].flatOffset[1] = 0;
    dataDesc_299[41].fieldType = FIELD_CUSTOM;
    dataDesc_299[41].fieldName = "m_ragdoll.list[2].pConstraint";
    dataDesc_299[41].fieldOffset = 1244;
    *(_DWORD *)&dataDesc_299[41].fieldSize = 131073;
    dataDesc_299[41].externalName = nullptr;
    v2 = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSCONSTRAINT);
    *(_QWORD *)&dataDesc_299[41].td = 0;
    *(_QWORD *)&dataDesc_299[41].override_field = 0;
    *(_QWORD *)&dataDesc_299[41].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_299[41].flatOffset[1] = 0;
    dataDesc_299[42].fieldTolerance = 0.0;
    dataDesc_299[43].fieldTolerance = 0.0;
    dataDesc_299[41].pSaveRestoreOps = v2;
    dataDesc_299[41].inputFunc = nullptr;
    dataDesc_299[42].fieldType = FIELD_INTEGER;
    dataDesc_299[42].fieldName = "m_ragdoll.list[2].parentIndex";
    dataDesc_299[42].fieldOffset = 1248;
    *(_DWORD *)&dataDesc_299[42].fieldSize = 131073;
    dataDesc_299[42].externalName = nullptr;
    dataDesc_299[42].pSaveRestoreOps = nullptr;
    dataDesc_299[42].inputFunc = nullptr;
    dataDesc_299[42].td = nullptr;
    dataDesc_299[42].fieldSizeInBytes = 4;
    dataDesc_299[42].override_field = nullptr;
    dataDesc_299[42].override_count = 0;
    *(_QWORD *)dataDesc_299[42].flatOffset = 0;
    *(_DWORD *)&dataDesc_299[42].flatGroup = 0;
    dataDesc_299[43].fieldType = FIELD_VECTOR;
    dataDesc_299[43].fieldName = "m_ragdoll.list[3].originParentSpace";
    dataDesc_299[43].fieldOffset = 1252;
    *(_DWORD *)&dataDesc_299[43].fieldSize = 131073;
    dataDesc_299[43].externalName = nullptr;
    dataDesc_299[43].pSaveRestoreOps = nullptr;
    dataDesc_299[43].inputFunc = nullptr;
    dataDesc_299[43].td = nullptr;
    dataDesc_299[43].fieldSizeInBytes = 12;
    dataDesc_299[43].override_field = nullptr;
    dataDesc_299[43].override_count = 0;
    *(_QWORD *)dataDesc_299[43].flatOffset = 0;
    *(_DWORD *)&dataDesc_299[43].flatGroup = 0;
    dataDesc_299[44].fieldType = FIELD_CUSTOM;
    dataDesc_299[44].fieldName = "m_ragdoll.list[3].pObject";
    dataDesc_299[44].fieldOffset = 1264;
    *(_DWORD *)&dataDesc_299[44].fieldSize = 131073;
    dataDesc_299[44].externalName = nullptr;
    dataDesc_299[44].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSOBJECT);
    dataDesc_299[44].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_299[44].td = 0;
    *(_QWORD *)&dataDesc_299[44].override_field = 0;
    *(_QWORD *)&dataDesc_299[44].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_299[44].flatOffset[1] = 0;
    dataDesc_299[45].fieldType = FIELD_CUSTOM;
    dataDesc_299[45].fieldName = "m_ragdoll.list[3].pConstraint";
    dataDesc_299[45].fieldOffset = 1268;
    *(_DWORD *)&dataDesc_299[45].fieldSize = 131073;
    dataDesc_299[45].externalName = nullptr;
    v3 = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSCONSTRAINT);
    *(_QWORD *)&dataDesc_299[45].td = 0;
    *(_QWORD *)&dataDesc_299[45].override_field = 0;
    *(_QWORD *)&dataDesc_299[45].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_299[45].flatOffset[1] = 0;
    dataDesc_299[46].fieldTolerance = 0.0;
    dataDesc_299[47].fieldTolerance = 0.0;
    dataDesc_299[45].pSaveRestoreOps = v3;
    dataDesc_299[45].inputFunc = nullptr;
    dataDesc_299[46].fieldType = FIELD_INTEGER;
    dataDesc_299[46].fieldName = "m_ragdoll.list[3].parentIndex";
    dataDesc_299[46].fieldOffset = 1272;
    *(_DWORD *)&dataDesc_299[46].fieldSize = 131073;
    dataDesc_299[46].externalName = nullptr;
    dataDesc_299[46].pSaveRestoreOps = nullptr;
    dataDesc_299[46].inputFunc = nullptr;
    dataDesc_299[46].td = nullptr;
    dataDesc_299[46].fieldSizeInBytes = 4;
    dataDesc_299[46].override_field = nullptr;
    dataDesc_299[46].override_count = 0;
    *(_QWORD *)dataDesc_299[46].flatOffset = 0;
    *(_DWORD *)&dataDesc_299[46].flatGroup = 0;
    dataDesc_299[47].fieldType = FIELD_VECTOR;
    dataDesc_299[47].fieldName = "m_ragdoll.list[4].originParentSpace";
    dataDesc_299[47].fieldOffset = 1276;
    *(_DWORD *)&dataDesc_299[47].fieldSize = 131073;
    dataDesc_299[47].externalName = nullptr;
    dataDesc_299[47].pSaveRestoreOps = nullptr;
    dataDesc_299[47].inputFunc = nullptr;
    dataDesc_299[47].td = nullptr;
    dataDesc_299[47].fieldSizeInBytes = 12;
    dataDesc_299[47].override_field = nullptr;
    dataDesc_299[47].override_count = 0;
    *(_QWORD *)dataDesc_299[47].flatOffset = 0;
    *(_DWORD *)&dataDesc_299[47].flatGroup = 0;
    dataDesc_299[48].fieldType = FIELD_CUSTOM;
    dataDesc_299[48].fieldName = "m_ragdoll.list[4].pObject";
    dataDesc_299[48].fieldOffset = 1288;
    *(_DWORD *)&dataDesc_299[48].fieldSize = 131073;
    dataDesc_299[48].externalName = nullptr;
    dataDesc_299[48].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSOBJECT);
    dataDesc_299[48].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_299[48].td = 0;
    *(_QWORD *)&dataDesc_299[48].override_field = 0;
    *(_QWORD *)&dataDesc_299[48].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_299[48].flatOffset[1] = 0;
    dataDesc_299[49].fieldType = FIELD_CUSTOM;
    dataDesc_299[49].fieldName = "m_ragdoll.list[4].pConstraint";
    dataDesc_299[49].fieldOffset = 1292;
    *(_DWORD *)&dataDesc_299[49].fieldSize = 131073;
    dataDesc_299[49].externalName = nullptr;
    dataDesc_299[49].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSCONSTRAINT);
    *(_QWORD *)&dataDesc_299[49].td = 0;
    *(_QWORD *)&dataDesc_299[49].override_field = 0;
    *(_QWORD *)&dataDesc_299[49].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_299[49].flatOffset[1] = 0;
    dataDesc_299[50].fieldTolerance = 0.0;
    dataDesc_299[51].fieldTolerance = 0.0;
    dataDesc_299[49].inputFunc = nullptr;
    dataDesc_299[50].fieldType = FIELD_INTEGER;
    dataDesc_299[50].fieldName = "m_ragdoll.list[4].parentIndex";
    dataDesc_299[50].fieldOffset = 1296;
    *(_DWORD *)&dataDesc_299[50].fieldSize = 131073;
    dataDesc_299[50].externalName = nullptr;
    dataDesc_299[50].pSaveRestoreOps = nullptr;
    dataDesc_299[50].inputFunc = nullptr;
    dataDesc_299[50].td = nullptr;
    dataDesc_299[50].fieldSizeInBytes = 4;
    dataDesc_299[50].override_field = nullptr;
    dataDesc_299[50].override_count = 0;
    *(_QWORD *)dataDesc_299[50].flatOffset = 0;
    *(_DWORD *)&dataDesc_299[50].flatGroup = 0;
    dataDesc_299[51].fieldType = FIELD_VECTOR;
    dataDesc_299[51].fieldName = "m_ragdoll.list[5].originParentSpace";
    dataDesc_299[51].fieldOffset = 1300;
    *(_DWORD *)&dataDesc_299[51].fieldSize = 131073;
    dataDesc_299[51].externalName = nullptr;
    dataDesc_299[51].pSaveRestoreOps = nullptr;
    dataDesc_299[51].inputFunc = nullptr;
    dataDesc_299[51].td = nullptr;
    dataDesc_299[51].fieldSizeInBytes = 12;
    dataDesc_299[51].override_field = nullptr;
    dataDesc_299[51].override_count = 0;
    *(_QWORD *)dataDesc_299[51].flatOffset = 0;
    *(_DWORD *)&dataDesc_299[51].flatGroup = 0;
    dataDesc_299[52].fieldType = FIELD_CUSTOM;
    dataDesc_299[52].fieldName = "m_ragdoll.list[5].pObject";
    dataDesc_299[52].fieldOffset = 1312;
    *(_DWORD *)&dataDesc_299[52].fieldSize = 131073;
    dataDesc_299[52].externalName = nullptr;
    dataDesc_299[52].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSOBJECT);
    dataDesc_299[52].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_299[52].td = 0;
    *(_QWORD *)&dataDesc_299[52].override_field = 0;
    *(_QWORD *)&dataDesc_299[52].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_299[52].flatOffset[1] = 0;
    dataDesc_299[53].fieldType = FIELD_CUSTOM;
    dataDesc_299[53].fieldName = "m_ragdoll.list[5].pConstraint";
    dataDesc_299[53].fieldOffset = 1316;
    *(_DWORD *)&dataDesc_299[53].fieldSize = 131073;
    dataDesc_299[53].externalName = nullptr;
    v4 = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSCONSTRAINT);
    *(_QWORD *)&dataDesc_299[53].td = 0;
    *(_QWORD *)&dataDesc_299[53].override_field = 0;
    *(_QWORD *)&dataDesc_299[53].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_299[53].flatOffset[1] = 0;
    dataDesc_299[53].pSaveRestoreOps = v4;
    dataDesc_299[53].inputFunc = nullptr;
    dataDesc_299[54].fieldType = FIELD_INTEGER;
    dataDesc_299[54].fieldName = "m_ragdoll.list[5].parentIndex";
    dataDesc_299[54].fieldOffset = 1320;
    *(_DWORD *)&dataDesc_299[54].fieldSize = 131073;
    dataDesc_299[54].externalName = nullptr;
    dataDesc_299[54].pSaveRestoreOps = nullptr;
    dataDesc_299[54].inputFunc = nullptr;
    dataDesc_299[54].td = nullptr;
    dataDesc_299[54].fieldSizeInBytes = 4;
    dataDesc_299[54].override_field = nullptr;
    dataDesc_299[54].override_count = 0;
    dataDesc_299[54].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_299[54].flatOffset = 0;
    *(_DWORD *)&dataDesc_299[54].flatGroup = 0;
    dataDesc_299[55].fieldTolerance = 0.0;
    dataDesc_299[55].fieldType = FIELD_VECTOR;
    dataDesc_299[55].fieldName = "m_ragdoll.list[6].originParentSpace";
    dataDesc_299[55].fieldOffset = 1324;
    *(_DWORD *)&dataDesc_299[55].fieldSize = 131073;
    dataDesc_299[55].externalName = nullptr;
    dataDesc_299[55].pSaveRestoreOps = nullptr;
    dataDesc_299[55].inputFunc = nullptr;
    dataDesc_299[55].td = nullptr;
    dataDesc_299[55].fieldSizeInBytes = 12;
    dataDesc_299[55].override_field = nullptr;
    dataDesc_299[55].override_count = 0;
    *(_QWORD *)dataDesc_299[55].flatOffset = 0;
    *(_DWORD *)&dataDesc_299[55].flatGroup = 0;
    dataDesc_299[56].fieldType = FIELD_CUSTOM;
    dataDesc_299[56].fieldName = "m_ragdoll.list[6].pObject";
    dataDesc_299[56].fieldOffset = 1336;
    *(_DWORD *)&dataDesc_299[56].fieldSize = 131073;
    dataDesc_299[56].externalName = nullptr;
    dataDesc_299[56].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSOBJECT);
    dataDesc_299[56].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_299[56].td = 0;
    *(_QWORD *)&dataDesc_299[56].override_field = 0;
    *(_QWORD *)&dataDesc_299[56].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_299[56].flatOffset[1] = 0;
    dataDesc_299[57].fieldType = FIELD_CUSTOM;
    dataDesc_299[57].fieldName = "m_ragdoll.list[6].pConstraint";
    dataDesc_299[57].fieldOffset = 1340;
    *(_DWORD *)&dataDesc_299[57].fieldSize = 131073;
    dataDesc_299[57].externalName = nullptr;
    v5 = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSCONSTRAINT);
    *(_QWORD *)&dataDesc_299[57].td = 0;
    *(_QWORD *)&dataDesc_299[57].override_field = 0;
    *(_QWORD *)&dataDesc_299[57].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_299[57].flatOffset[1] = 0;
    dataDesc_299[58].fieldTolerance = 0.0;
    dataDesc_299[59].fieldTolerance = 0.0;
    dataDesc_299[57].pSaveRestoreOps = v5;
    dataDesc_299[57].inputFunc = nullptr;
    dataDesc_299[58].fieldType = FIELD_INTEGER;
    dataDesc_299[58].fieldName = "m_ragdoll.list[6].parentIndex";
    dataDesc_299[58].fieldOffset = 1344;
    *(_DWORD *)&dataDesc_299[58].fieldSize = 131073;
    dataDesc_299[58].externalName = nullptr;
    dataDesc_299[58].pSaveRestoreOps = nullptr;
    dataDesc_299[58].inputFunc = nullptr;
    dataDesc_299[58].td = nullptr;
    dataDesc_299[58].fieldSizeInBytes = 4;
    dataDesc_299[58].override_field = nullptr;
    dataDesc_299[58].override_count = 0;
    *(_QWORD *)dataDesc_299[58].flatOffset = 0;
    *(_DWORD *)&dataDesc_299[58].flatGroup = 0;
    dataDesc_299[59].fieldType = FIELD_VECTOR;
    dataDesc_299[59].fieldName = "m_ragdoll.list[7].originParentSpace";
    dataDesc_299[59].fieldOffset = 1348;
    *(_DWORD *)&dataDesc_299[59].fieldSize = 131073;
    dataDesc_299[59].externalName = nullptr;
    dataDesc_299[59].pSaveRestoreOps = nullptr;
    dataDesc_299[59].inputFunc = nullptr;
    dataDesc_299[59].td = nullptr;
    dataDesc_299[59].fieldSizeInBytes = 12;
    dataDesc_299[59].override_field = nullptr;
    dataDesc_299[59].override_count = 0;
    *(_QWORD *)dataDesc_299[59].flatOffset = 0;
    *(_DWORD *)&dataDesc_299[59].flatGroup = 0;
    dataDesc_299[60].fieldType = FIELD_CUSTOM;
    dataDesc_299[60].fieldName = "m_ragdoll.list[7].pObject";
    dataDesc_299[60].fieldOffset = 1360;
    *(_DWORD *)&dataDesc_299[60].fieldSize = 131073;
    dataDesc_299[60].externalName = nullptr;
    dataDesc_299[60].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSOBJECT);
    dataDesc_299[60].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_299[60].td = 0;
    *(_QWORD *)&dataDesc_299[60].override_field = 0;
    *(_QWORD *)&dataDesc_299[60].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_299[60].flatOffset[1] = 0;
    dataDesc_299[61].fieldType = FIELD_CUSTOM;
    dataDesc_299[61].fieldName = "m_ragdoll.list[7].pConstraint";
    dataDesc_299[61].fieldOffset = 1364;
    *(_DWORD *)&dataDesc_299[61].fieldSize = 131073;
    dataDesc_299[61].externalName = nullptr;
    v6 = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSCONSTRAINT);
    *(_QWORD *)&dataDesc_299[61].td = 0;
    *(_QWORD *)&dataDesc_299[61].override_field = 0;
    *(_QWORD *)&dataDesc_299[61].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_299[61].flatOffset[1] = 0;
    dataDesc_299[62].fieldTolerance = 0.0;
    dataDesc_299[63].fieldTolerance = 0.0;
    dataDesc_299[61].pSaveRestoreOps = v6;
    dataDesc_299[61].inputFunc = nullptr;
    dataDesc_299[62].fieldType = FIELD_INTEGER;
    dataDesc_299[62].fieldName = "m_ragdoll.list[7].parentIndex";
    dataDesc_299[62].fieldOffset = 1368;
    *(_DWORD *)&dataDesc_299[62].fieldSize = 131073;
    dataDesc_299[62].externalName = nullptr;
    dataDesc_299[62].pSaveRestoreOps = nullptr;
    dataDesc_299[62].inputFunc = nullptr;
    dataDesc_299[62].td = nullptr;
    dataDesc_299[62].fieldSizeInBytes = 4;
    dataDesc_299[62].override_field = nullptr;
    dataDesc_299[62].override_count = 0;
    *(_QWORD *)dataDesc_299[62].flatOffset = 0;
    *(_DWORD *)&dataDesc_299[62].flatGroup = 0;
    dataDesc_299[63].fieldType = FIELD_VECTOR;
    dataDesc_299[63].fieldName = "m_ragdoll.list[8].originParentSpace";
    dataDesc_299[63].fieldOffset = 1372;
    *(_DWORD *)&dataDesc_299[63].fieldSize = 131073;
    dataDesc_299[63].externalName = nullptr;
    dataDesc_299[63].pSaveRestoreOps = nullptr;
    dataDesc_299[63].inputFunc = nullptr;
    dataDesc_299[63].td = nullptr;
    dataDesc_299[63].fieldSizeInBytes = 12;
    dataDesc_299[63].override_field = nullptr;
    dataDesc_299[63].override_count = 0;
    *(_QWORD *)dataDesc_299[63].flatOffset = 0;
    *(_DWORD *)&dataDesc_299[63].flatGroup = 0;
    dataDesc_299[64].fieldType = FIELD_CUSTOM;
    dataDesc_299[64].fieldName = "m_ragdoll.list[8].pObject";
    dataDesc_299[64].fieldOffset = 1384;
    *(_DWORD *)&dataDesc_299[64].fieldSize = 131073;
    dataDesc_299[64].externalName = nullptr;
    dataDesc_299[64].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSOBJECT);
    dataDesc_299[64].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_299[64].td = 0;
    *(_QWORD *)&dataDesc_299[64].override_field = 0;
    *(_QWORD *)&dataDesc_299[64].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_299[64].flatOffset[1] = 0;
    dataDesc_299[65].fieldType = FIELD_CUSTOM;
    dataDesc_299[65].fieldName = "m_ragdoll.list[8].pConstraint";
    dataDesc_299[65].fieldOffset = 1388;
    *(_DWORD *)&dataDesc_299[65].fieldSize = 131073;
    dataDesc_299[65].externalName = nullptr;
    dataDesc_299[65].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSCONSTRAINT);
    dataDesc_299[65].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_299[65].td = 0;
    *(_QWORD *)&dataDesc_299[65].override_field = 0;
    *(_QWORD *)&dataDesc_299[65].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_299[65].flatOffset[1] = 0;
    dataDesc_299[66].fieldTolerance = 0.0;
    dataDesc_299[67].fieldTolerance = 0.0;
    dataDesc_299[66].fieldType = FIELD_INTEGER;
    dataDesc_299[66].fieldName = "m_ragdoll.list[8].parentIndex";
    dataDesc_299[66].fieldOffset = 1392;
    *(_DWORD *)&dataDesc_299[66].fieldSize = 131073;
    dataDesc_299[66].externalName = nullptr;
    dataDesc_299[66].pSaveRestoreOps = nullptr;
    dataDesc_299[66].inputFunc = nullptr;
    dataDesc_299[66].td = nullptr;
    dataDesc_299[66].fieldSizeInBytes = 4;
    dataDesc_299[66].override_field = nullptr;
    dataDesc_299[66].override_count = 0;
    *(_QWORD *)dataDesc_299[66].flatOffset = 0;
    *(_DWORD *)&dataDesc_299[66].flatGroup = 0;
    dataDesc_299[67].fieldType = FIELD_VECTOR;
    dataDesc_299[67].fieldName = "m_ragdoll.list[9].originParentSpace";
    dataDesc_299[67].fieldOffset = 1396;
    *(_DWORD *)&dataDesc_299[67].fieldSize = 131073;
    dataDesc_299[67].externalName = nullptr;
    dataDesc_299[67].pSaveRestoreOps = nullptr;
    dataDesc_299[67].inputFunc = nullptr;
    dataDesc_299[67].td = nullptr;
    dataDesc_299[67].fieldSizeInBytes = 12;
    dataDesc_299[67].override_field = nullptr;
    dataDesc_299[67].override_count = 0;
    *(_QWORD *)dataDesc_299[67].flatOffset = 0;
    *(_DWORD *)&dataDesc_299[67].flatGroup = 0;
    dataDesc_299[68].fieldType = FIELD_CUSTOM;
    dataDesc_299[68].fieldName = "m_ragdoll.list[9].pObject";
    dataDesc_299[68].fieldOffset = 1408;
    *(_DWORD *)&dataDesc_299[68].fieldSize = 131073;
    dataDesc_299[68].externalName = nullptr;
    dataDesc_299[68].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSOBJECT);
    dataDesc_299[68].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_299[68].td = 0;
    *(_QWORD *)&dataDesc_299[68].override_field = 0;
    *(_QWORD *)&dataDesc_299[68].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_299[68].flatOffset[1] = 0;
    dataDesc_299[69].fieldType = FIELD_CUSTOM;
    dataDesc_299[69].fieldName = "m_ragdoll.list[9].pConstraint";
    dataDesc_299[69].fieldOffset = 1412;
    *(_DWORD *)&dataDesc_299[69].fieldSize = 131073;
    dataDesc_299[69].externalName = nullptr;
    v7 = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSCONSTRAINT);
    *(_QWORD *)&dataDesc_299[69].td = 0;
    *(_QWORD *)&dataDesc_299[69].override_field = 0;
    *(_QWORD *)&dataDesc_299[69].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_299[69].flatOffset[1] = 0;
    dataDesc_299[69].pSaveRestoreOps = v7;
    dataDesc_299[69].inputFunc = nullptr;
    dataDesc_299[70].fieldType = FIELD_INTEGER;
    dataDesc_299[70].fieldName = "m_ragdoll.list[9].parentIndex";
    dataDesc_299[70].fieldOffset = 1416;
    *(_DWORD *)&dataDesc_299[70].fieldSize = 131073;
    dataDesc_299[70].externalName = nullptr;
    dataDesc_299[70].pSaveRestoreOps = nullptr;
    dataDesc_299[70].inputFunc = nullptr;
    dataDesc_299[70].td = nullptr;
    dataDesc_299[70].fieldSizeInBytes = 4;
    dataDesc_299[70].override_field = nullptr;
    dataDesc_299[70].override_count = 0;
    dataDesc_299[70].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_299[70].flatOffset = 0;
    *(_DWORD *)&dataDesc_299[70].flatGroup = 0;
    dataDesc_299[71].fieldType = FIELD_VECTOR;
    dataDesc_299[71].fieldName = "m_ragdoll.list[10].originParentSpace";
    dataDesc_299[71].fieldOffset = 1420;
    *(_DWORD *)&dataDesc_299[71].fieldSize = 131073;
    dataDesc_299[71].externalName = nullptr;
    dataDesc_299[71].pSaveRestoreOps = nullptr;
    dataDesc_299[71].fieldTolerance = 0.0;
    dataDesc_299[71].inputFunc = nullptr;
    dataDesc_299[71].td = nullptr;
    dataDesc_299[71].fieldSizeInBytes = 12;
    dataDesc_299[71].override_field = nullptr;
    dataDesc_299[71].override_count = 0;
    *(_QWORD *)dataDesc_299[71].flatOffset = 0;
    *(_DWORD *)&dataDesc_299[71].flatGroup = 0;
    dataDesc_299[72].fieldType = FIELD_CUSTOM;
    dataDesc_299[72].fieldName = "m_ragdoll.list[10].pObject";
    dataDesc_299[72].fieldOffset = 1432;
    *(_DWORD *)&dataDesc_299[72].fieldSize = 131073;
    dataDesc_299[72].externalName = nullptr;
    dataDesc_299[72].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSOBJECT);
    dataDesc_299[72].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_299[72].td = 0;
    *(_QWORD *)&dataDesc_299[72].override_field = 0;
    *(_QWORD *)&dataDesc_299[72].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_299[72].flatOffset[1] = 0;
    dataDesc_299[73].fieldType = FIELD_CUSTOM;
    dataDesc_299[73].fieldName = "m_ragdoll.list[10].pConstraint";
    dataDesc_299[73].fieldOffset = 1436;
    *(_DWORD *)&dataDesc_299[73].fieldSize = 131073;
    dataDesc_299[73].externalName = nullptr;
    v8 = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSCONSTRAINT);
    *(_QWORD *)&dataDesc_299[73].td = 0;
    *(_QWORD *)&dataDesc_299[73].override_field = 0;
    *(_QWORD *)&dataDesc_299[73].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_299[73].flatOffset[1] = 0;
    dataDesc_299[74].fieldTolerance = 0.0;
    dataDesc_299[75].fieldTolerance = 0.0;
    dataDesc_299[73].pSaveRestoreOps = v8;
    dataDesc_299[73].inputFunc = nullptr;
    dataDesc_299[74].fieldType = FIELD_INTEGER;
    dataDesc_299[74].fieldName = "m_ragdoll.list[10].parentIndex";
    dataDesc_299[74].fieldOffset = 1440;
    *(_DWORD *)&dataDesc_299[74].fieldSize = 131073;
    dataDesc_299[74].externalName = nullptr;
    dataDesc_299[74].pSaveRestoreOps = nullptr;
    dataDesc_299[74].inputFunc = nullptr;
    dataDesc_299[74].td = nullptr;
    dataDesc_299[74].fieldSizeInBytes = 4;
    dataDesc_299[74].override_field = nullptr;
    dataDesc_299[74].override_count = 0;
    *(_QWORD *)dataDesc_299[74].flatOffset = 0;
    *(_DWORD *)&dataDesc_299[74].flatGroup = 0;
    dataDesc_299[75].fieldType = FIELD_VECTOR;
    dataDesc_299[75].fieldName = "m_ragdoll.list[11].originParentSpace";
    dataDesc_299[75].fieldOffset = 1444;
    *(_DWORD *)&dataDesc_299[75].fieldSize = 131073;
    dataDesc_299[75].externalName = nullptr;
    dataDesc_299[75].pSaveRestoreOps = nullptr;
    dataDesc_299[75].inputFunc = nullptr;
    dataDesc_299[75].td = nullptr;
    dataDesc_299[75].fieldSizeInBytes = 12;
    dataDesc_299[75].override_field = nullptr;
    dataDesc_299[75].override_count = 0;
    *(_QWORD *)dataDesc_299[75].flatOffset = 0;
    *(_DWORD *)&dataDesc_299[75].flatGroup = 0;
    dataDesc_299[76].fieldType = FIELD_CUSTOM;
    dataDesc_299[76].fieldName = "m_ragdoll.list[11].pObject";
    dataDesc_299[76].fieldOffset = 1456;
    *(_DWORD *)&dataDesc_299[76].fieldSize = 131073;
    dataDesc_299[76].externalName = nullptr;
    dataDesc_299[76].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSOBJECT);
    dataDesc_299[76].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_299[76].td = 0;
    *(_QWORD *)&dataDesc_299[76].override_field = 0;
    *(_QWORD *)&dataDesc_299[76].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_299[76].flatOffset[1] = 0;
    dataDesc_299[77].fieldType = FIELD_CUSTOM;
    dataDesc_299[77].fieldName = "m_ragdoll.list[11].pConstraint";
    dataDesc_299[77].fieldOffset = 1460;
    *(_DWORD *)&dataDesc_299[77].fieldSize = 131073;
    dataDesc_299[77].externalName = nullptr;
    v9 = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSCONSTRAINT);
    *(_QWORD *)&dataDesc_299[77].td = 0;
    *(_QWORD *)&dataDesc_299[77].override_field = 0;
    *(_QWORD *)&dataDesc_299[77].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_299[77].flatOffset[1] = 0;
    dataDesc_299[78].fieldTolerance = 0.0;
    dataDesc_299[79].fieldTolerance = 0.0;
    dataDesc_299[77].pSaveRestoreOps = v9;
    dataDesc_299[77].inputFunc = nullptr;
    dataDesc_299[78].fieldType = FIELD_INTEGER;
    dataDesc_299[78].fieldName = "m_ragdoll.list[11].parentIndex";
    dataDesc_299[78].fieldOffset = 1464;
    *(_DWORD *)&dataDesc_299[78].fieldSize = 131073;
    dataDesc_299[78].externalName = nullptr;
    dataDesc_299[78].pSaveRestoreOps = nullptr;
    dataDesc_299[78].inputFunc = nullptr;
    dataDesc_299[78].td = nullptr;
    dataDesc_299[78].fieldSizeInBytes = 4;
    dataDesc_299[78].override_field = nullptr;
    dataDesc_299[78].override_count = 0;
    *(_QWORD *)dataDesc_299[78].flatOffset = 0;
    *(_DWORD *)&dataDesc_299[78].flatGroup = 0;
    dataDesc_299[79].fieldType = FIELD_VECTOR;
    dataDesc_299[79].fieldName = "m_ragdoll.list[12].originParentSpace";
    dataDesc_299[79].fieldOffset = 1468;
    *(_DWORD *)&dataDesc_299[79].fieldSize = 131073;
    dataDesc_299[79].externalName = nullptr;
    dataDesc_299[79].pSaveRestoreOps = nullptr;
    dataDesc_299[79].inputFunc = nullptr;
    dataDesc_299[79].td = nullptr;
    dataDesc_299[79].fieldSizeInBytes = 12;
    dataDesc_299[79].override_field = nullptr;
    dataDesc_299[79].override_count = 0;
    *(_QWORD *)dataDesc_299[79].flatOffset = 0;
    *(_DWORD *)&dataDesc_299[79].flatGroup = 0;
    dataDesc_299[80].fieldType = FIELD_CUSTOM;
    dataDesc_299[80].fieldName = "m_ragdoll.list[12].pObject";
    dataDesc_299[80].fieldOffset = 1480;
    *(_DWORD *)&dataDesc_299[80].fieldSize = 131073;
    dataDesc_299[80].externalName = nullptr;
    dataDesc_299[80].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSOBJECT);
    dataDesc_299[80].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_299[80].td = 0;
    *(_QWORD *)&dataDesc_299[80].override_field = 0;
    *(_QWORD *)&dataDesc_299[80].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_299[80].flatOffset[1] = 0;
    dataDesc_299[81].fieldType = FIELD_CUSTOM;
    dataDesc_299[81].fieldName = "m_ragdoll.list[12].pConstraint";
    dataDesc_299[81].fieldOffset = 1484;
    *(_DWORD *)&dataDesc_299[81].fieldSize = 131073;
    dataDesc_299[81].externalName = nullptr;
    dataDesc_299[81].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSCONSTRAINT);
    dataDesc_299[81].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_299[81].td = 0;
    *(_QWORD *)&dataDesc_299[81].override_field = 0;
    *(_QWORD *)&dataDesc_299[81].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_299[81].flatOffset[1] = 0;
    dataDesc_299[82].fieldType = FIELD_INTEGER;
    dataDesc_299[82].fieldName = "m_ragdoll.list[12].parentIndex";
    dataDesc_299[82].fieldOffset = 1488;
    *(_DWORD *)&dataDesc_299[82].fieldSize = 131073;
    dataDesc_299[82].externalName = nullptr;
    dataDesc_299[82].pSaveRestoreOps = nullptr;
    dataDesc_299[82].inputFunc = nullptr;
    dataDesc_299[82].fieldTolerance = 0.0;
    dataDesc_299[83].fieldTolerance = 0.0;
    dataDesc_299[82].td = nullptr;
    dataDesc_299[82].fieldSizeInBytes = 4;
    dataDesc_299[82].override_field = nullptr;
    dataDesc_299[82].override_count = 0;
    *(_QWORD *)dataDesc_299[82].flatOffset = 0;
    *(_DWORD *)&dataDesc_299[82].flatGroup = 0;
    dataDesc_299[83].fieldType = FIELD_VECTOR;
    dataDesc_299[83].fieldName = "m_ragdoll.list[13].originParentSpace";
    dataDesc_299[83].fieldOffset = 1492;
    *(_DWORD *)&dataDesc_299[83].fieldSize = 131073;
    dataDesc_299[83].externalName = nullptr;
    dataDesc_299[83].pSaveRestoreOps = nullptr;
    dataDesc_299[83].inputFunc = nullptr;
    dataDesc_299[83].td = nullptr;
    dataDesc_299[83].fieldSizeInBytes = 12;
    dataDesc_299[83].override_field = nullptr;
    dataDesc_299[83].override_count = 0;
    *(_QWORD *)dataDesc_299[83].flatOffset = 0;
    *(_DWORD *)&dataDesc_299[83].flatGroup = 0;
    dataDesc_299[84].fieldType = FIELD_CUSTOM;
    dataDesc_299[84].fieldName = "m_ragdoll.list[13].pObject";
    dataDesc_299[84].fieldOffset = 1504;
    *(_DWORD *)&dataDesc_299[84].fieldSize = 131073;
    dataDesc_299[84].externalName = nullptr;
    dataDesc_299[84].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSOBJECT);
    dataDesc_299[84].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_299[84].td = 0;
    *(_QWORD *)&dataDesc_299[84].override_field = 0;
    *(_QWORD *)&dataDesc_299[84].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_299[84].flatOffset[1] = 0;
    dataDesc_299[85].fieldType = FIELD_CUSTOM;
    dataDesc_299[85].fieldName = "m_ragdoll.list[13].pConstraint";
    dataDesc_299[85].fieldOffset = 1508;
    *(_DWORD *)&dataDesc_299[85].fieldSize = 131073;
    dataDesc_299[85].externalName = nullptr;
    v10 = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSCONSTRAINT);
    *(_QWORD *)&dataDesc_299[85].td = 0;
    *(_QWORD *)&dataDesc_299[85].override_field = 0;
    *(_QWORD *)&dataDesc_299[85].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_299[85].flatOffset[1] = 0;
    dataDesc_299[86].fieldTolerance = 0.0;
    dataDesc_299[87].fieldTolerance = 0.0;
    dataDesc_299[85].pSaveRestoreOps = v10;
    dataDesc_299[85].inputFunc = nullptr;
    dataDesc_299[86].fieldType = FIELD_INTEGER;
    dataDesc_299[86].fieldName = "m_ragdoll.list[13].parentIndex";
    dataDesc_299[86].fieldOffset = 1512;
    *(_DWORD *)&dataDesc_299[86].fieldSize = 131073;
    dataDesc_299[86].externalName = nullptr;
    dataDesc_299[86].pSaveRestoreOps = nullptr;
    dataDesc_299[86].inputFunc = nullptr;
    dataDesc_299[86].td = nullptr;
    dataDesc_299[86].fieldSizeInBytes = 4;
    dataDesc_299[86].override_field = nullptr;
    dataDesc_299[86].override_count = 0;
    *(_QWORD *)dataDesc_299[86].flatOffset = 0;
    *(_DWORD *)&dataDesc_299[86].flatGroup = 0;
    dataDesc_299[87].fieldType = FIELD_VECTOR;
    dataDesc_299[87].fieldName = "m_ragdoll.list[14].originParentSpace";
    dataDesc_299[87].fieldOffset = 1516;
    *(_DWORD *)&dataDesc_299[87].fieldSize = 131073;
    dataDesc_299[87].externalName = nullptr;
    dataDesc_299[87].pSaveRestoreOps = nullptr;
    dataDesc_299[87].inputFunc = nullptr;
    dataDesc_299[87].td = nullptr;
    dataDesc_299[87].fieldSizeInBytes = 12;
    dataDesc_299[87].override_field = nullptr;
    dataDesc_299[87].override_count = 0;
    *(_QWORD *)dataDesc_299[87].flatOffset = 0;
    *(_DWORD *)&dataDesc_299[87].flatGroup = 0;
    dataDesc_299[88].fieldType = FIELD_CUSTOM;
    dataDesc_299[88].fieldName = "m_ragdoll.list[14].pObject";
    dataDesc_299[88].fieldOffset = 1528;
    *(_DWORD *)&dataDesc_299[88].fieldSize = 131073;
    dataDesc_299[88].externalName = nullptr;
    dataDesc_299[88].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSOBJECT);
    dataDesc_299[88].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_299[88].td = 0;
    *(_QWORD *)&dataDesc_299[88].override_field = 0;
    *(_QWORD *)&dataDesc_299[88].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_299[88].flatOffset[1] = 0;
    dataDesc_299[89].fieldType = FIELD_CUSTOM;
    dataDesc_299[89].fieldName = "m_ragdoll.list[14].pConstraint";
    dataDesc_299[89].fieldOffset = 1532;
    *(_DWORD *)&dataDesc_299[89].fieldSize = 131073;
    dataDesc_299[89].externalName = nullptr;
    v11 = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSCONSTRAINT);
    *(_QWORD *)&dataDesc_299[89].td = 0;
    *(_QWORD *)&dataDesc_299[89].override_field = 0;
    *(_QWORD *)&dataDesc_299[89].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_299[89].flatOffset[1] = 0;
    dataDesc_299[90].fieldTolerance = 0.0;
    dataDesc_299[91].fieldTolerance = 0.0;
    dataDesc_299[89].pSaveRestoreOps = v11;
    dataDesc_299[89].inputFunc = nullptr;
    dataDesc_299[90].fieldType = FIELD_INTEGER;
    dataDesc_299[90].fieldName = "m_ragdoll.list[14].parentIndex";
    dataDesc_299[90].fieldOffset = 1536;
    *(_DWORD *)&dataDesc_299[90].fieldSize = 131073;
    dataDesc_299[90].externalName = nullptr;
    dataDesc_299[90].pSaveRestoreOps = nullptr;
    dataDesc_299[90].inputFunc = nullptr;
    dataDesc_299[90].td = nullptr;
    dataDesc_299[90].fieldSizeInBytes = 4;
    dataDesc_299[90].override_field = nullptr;
    dataDesc_299[90].override_count = 0;
    *(_QWORD *)dataDesc_299[90].flatOffset = 0;
    *(_DWORD *)&dataDesc_299[90].flatGroup = 0;
    dataDesc_299[91].fieldType = FIELD_VECTOR;
    dataDesc_299[91].fieldName = "m_ragdoll.list[15].originParentSpace";
    dataDesc_299[91].fieldOffset = 1540;
    *(_DWORD *)&dataDesc_299[91].fieldSize = 131073;
    dataDesc_299[91].externalName = nullptr;
    dataDesc_299[91].pSaveRestoreOps = nullptr;
    dataDesc_299[91].inputFunc = nullptr;
    dataDesc_299[91].td = nullptr;
    dataDesc_299[91].fieldSizeInBytes = 12;
    dataDesc_299[91].override_field = nullptr;
    dataDesc_299[91].override_count = 0;
    *(_QWORD *)dataDesc_299[91].flatOffset = 0;
    *(_DWORD *)&dataDesc_299[91].flatGroup = 0;
    dataDesc_299[92].fieldType = FIELD_CUSTOM;
    dataDesc_299[92].fieldName = "m_ragdoll.list[15].pObject";
    dataDesc_299[92].fieldOffset = 1552;
    *(_DWORD *)&dataDesc_299[92].fieldSize = 131073;
    dataDesc_299[92].externalName = nullptr;
    dataDesc_299[92].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSOBJECT);
    dataDesc_299[92].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_299[92].td = 0;
    *(_QWORD *)&dataDesc_299[92].override_field = 0;
    *(_QWORD *)&dataDesc_299[92].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_299[92].flatOffset[1] = 0;
    dataDesc_299[93].fieldType = FIELD_CUSTOM;
    dataDesc_299[93].fieldName = "m_ragdoll.list[15].pConstraint";
    dataDesc_299[93].fieldOffset = 1556;
    *(_DWORD *)&dataDesc_299[93].fieldSize = 131073;
    dataDesc_299[93].externalName = nullptr;
    v12 = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSCONSTRAINT);
    *(_QWORD *)&dataDesc_299[93].td = 0;
    *(_QWORD *)&dataDesc_299[93].override_field = 0;
    *(_QWORD *)&dataDesc_299[93].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_299[93].flatOffset[1] = 0;
    dataDesc_299[94].fieldTolerance = 0.0;
    dataDesc_299[95].fieldTolerance = 0.0;
    dataDesc_299[93].pSaveRestoreOps = v12;
    dataDesc_299[93].inputFunc = nullptr;
    dataDesc_299[94].fieldType = FIELD_INTEGER;
    dataDesc_299[94].fieldName = "m_ragdoll.list[15].parentIndex";
    dataDesc_299[94].fieldOffset = 1560;
    *(_DWORD *)&dataDesc_299[94].fieldSize = 131073;
    dataDesc_299[94].externalName = nullptr;
    dataDesc_299[94].pSaveRestoreOps = nullptr;
    dataDesc_299[94].inputFunc = nullptr;
    dataDesc_299[94].td = nullptr;
    dataDesc_299[94].fieldSizeInBytes = 4;
    dataDesc_299[94].override_field = nullptr;
    dataDesc_299[94].override_count = 0;
    *(_QWORD *)dataDesc_299[94].flatOffset = 0;
    *(_DWORD *)&dataDesc_299[94].flatGroup = 0;
    dataDesc_299[95].fieldType = FIELD_VECTOR;
    dataDesc_299[95].fieldName = "m_ragdoll.list[16].originParentSpace";
    dataDesc_299[95].fieldOffset = 1564;
    *(_DWORD *)&dataDesc_299[95].fieldSize = 131073;
    dataDesc_299[95].externalName = nullptr;
    dataDesc_299[95].pSaveRestoreOps = nullptr;
    dataDesc_299[95].inputFunc = nullptr;
    dataDesc_299[95].td = nullptr;
    dataDesc_299[95].fieldSizeInBytes = 12;
    dataDesc_299[95].override_field = nullptr;
    dataDesc_299[95].override_count = 0;
    *(_QWORD *)dataDesc_299[95].flatOffset = 0;
    *(_DWORD *)&dataDesc_299[95].flatGroup = 0;
    dataDesc_299[96].fieldType = FIELD_CUSTOM;
    dataDesc_299[96].fieldName = "m_ragdoll.list[16].pObject";
    dataDesc_299[96].fieldOffset = 1576;
    *(_DWORD *)&dataDesc_299[96].fieldSize = 131073;
    dataDesc_299[96].externalName = nullptr;
    dataDesc_299[96].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSOBJECT);
    dataDesc_299[96].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_299[96].td = 0;
    *(_QWORD *)&dataDesc_299[96].override_field = 0;
    *(_QWORD *)&dataDesc_299[96].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_299[96].flatOffset[1] = 0;
    dataDesc_299[97].fieldType = FIELD_CUSTOM;
    dataDesc_299[97].fieldName = "m_ragdoll.list[16].pConstraint";
    dataDesc_299[97].fieldOffset = 1580;
    *(_DWORD *)&dataDesc_299[97].fieldSize = 131073;
    dataDesc_299[97].externalName = nullptr;
    v13 = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSCONSTRAINT);
    *(_QWORD *)&dataDesc_299[97].td = 0;
    *(_QWORD *)&dataDesc_299[97].override_field = 0;
    *(_QWORD *)&dataDesc_299[97].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_299[97].flatOffset[1] = 0;
    dataDesc_299[97].pSaveRestoreOps = v13;
    dataDesc_299[97].inputFunc = nullptr;
    dataDesc_299[98].fieldType = FIELD_INTEGER;
    dataDesc_299[98].fieldName = "m_ragdoll.list[16].parentIndex";
    dataDesc_299[98].fieldOffset = 1584;
    *(_DWORD *)&dataDesc_299[98].fieldSize = 131073;
    dataDesc_299[98].externalName = nullptr;
    dataDesc_299[98].pSaveRestoreOps = nullptr;
    dataDesc_299[98].inputFunc = nullptr;
    dataDesc_299[98].td = nullptr;
    dataDesc_299[98].fieldSizeInBytes = 4;
    dataDesc_299[98].override_field = nullptr;
    dataDesc_299[98].override_count = 0;
    dataDesc_299[98].fieldTolerance = 0.0;
    dataDesc_299[99].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_299[98].flatOffset = 0;
    *(_DWORD *)&dataDesc_299[98].flatGroup = 0;
    dataDesc_299[99].fieldType = FIELD_VECTOR;
    dataDesc_299[99].fieldName = "m_ragdoll.list[17].originParentSpace";
    dataDesc_299[99].fieldOffset = 1588;
    *(_DWORD *)&dataDesc_299[99].fieldSize = 131073;
    dataDesc_299[99].externalName = nullptr;
    dataDesc_299[99].pSaveRestoreOps = nullptr;
    dataDesc_299[99].inputFunc = nullptr;
    dataDesc_299[99].td = nullptr;
    dataDesc_299[99].fieldSizeInBytes = 12;
    dataDesc_299[99].override_field = nullptr;
    dataDesc_299[99].override_count = 0;
    *(_QWORD *)dataDesc_299[99].flatOffset = 0;
    *(_DWORD *)&dataDesc_299[99].flatGroup = 0;
    dataDesc_299[100].fieldType = FIELD_CUSTOM;
    dataDesc_299[100].fieldName = "m_ragdoll.list[17].pObject";
    dataDesc_299[100].fieldOffset = 1600;
    *(_DWORD *)&dataDesc_299[100].fieldSize = 131073;
    dataDesc_299[100].externalName = nullptr;
    dataDesc_299[100].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSOBJECT);
    dataDesc_299[100].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_299[100].td = 0;
    *(_QWORD *)&dataDesc_299[100].override_field = 0;
    *(_QWORD *)&dataDesc_299[100].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_299[100].flatOffset[1] = 0;
    dataDesc_299[101].fieldType = FIELD_CUSTOM;
    dataDesc_299[101].fieldName = "m_ragdoll.list[17].pConstraint";
    dataDesc_299[101].fieldOffset = 1604;
    *(_DWORD *)&dataDesc_299[101].fieldSize = 131073;
    dataDesc_299[101].externalName = nullptr;
    v14 = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSCONSTRAINT);
    *(_QWORD *)&dataDesc_299[101].td = 0;
    *(_QWORD *)&dataDesc_299[101].override_field = 0;
    *(_QWORD *)&dataDesc_299[101].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_299[101].flatOffset[1] = 0;
    dataDesc_299[102].fieldTolerance = 0.0;
    dataDesc_299[103].fieldTolerance = 0.0;
    dataDesc_299[101].pSaveRestoreOps = v14;
    dataDesc_299[101].inputFunc = nullptr;
    dataDesc_299[102].fieldType = FIELD_INTEGER;
    dataDesc_299[102].fieldName = "m_ragdoll.list[17].parentIndex";
    dataDesc_299[102].fieldOffset = 1608;
    *(_DWORD *)&dataDesc_299[102].fieldSize = 131073;
    dataDesc_299[102].externalName = nullptr;
    dataDesc_299[102].pSaveRestoreOps = nullptr;
    dataDesc_299[102].inputFunc = nullptr;
    dataDesc_299[102].td = nullptr;
    dataDesc_299[102].fieldSizeInBytes = 4;
    dataDesc_299[102].override_field = nullptr;
    dataDesc_299[102].override_count = 0;
    *(_QWORD *)dataDesc_299[102].flatOffset = 0;
    *(_DWORD *)&dataDesc_299[102].flatGroup = 0;
    dataDesc_299[103].fieldType = FIELD_VECTOR;
    dataDesc_299[103].fieldName = "m_ragdoll.list[18].originParentSpace";
    dataDesc_299[103].fieldOffset = 1612;
    *(_DWORD *)&dataDesc_299[103].fieldSize = 131073;
    dataDesc_299[103].externalName = nullptr;
    dataDesc_299[103].pSaveRestoreOps = nullptr;
    dataDesc_299[103].inputFunc = nullptr;
    dataDesc_299[103].td = nullptr;
    dataDesc_299[103].fieldSizeInBytes = 12;
    dataDesc_299[103].override_field = nullptr;
    dataDesc_299[103].override_count = 0;
    *(_QWORD *)dataDesc_299[103].flatOffset = 0;
    *(_DWORD *)&dataDesc_299[103].flatGroup = 0;
    dataDesc_299[104].fieldType = FIELD_CUSTOM;
    dataDesc_299[104].fieldName = "m_ragdoll.list[18].pObject";
    dataDesc_299[104].fieldOffset = 1624;
    *(_DWORD *)&dataDesc_299[104].fieldSize = 131073;
    dataDesc_299[104].externalName = nullptr;
    dataDesc_299[104].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSOBJECT);
    dataDesc_299[104].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_299[104].td = 0;
    *(_QWORD *)&dataDesc_299[104].override_field = 0;
    *(_QWORD *)&dataDesc_299[104].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_299[104].flatOffset[1] = 0;
    dataDesc_299[105].fieldType = FIELD_CUSTOM;
    dataDesc_299[105].fieldName = "m_ragdoll.list[18].pConstraint";
    dataDesc_299[105].fieldOffset = 1628;
    *(_DWORD *)&dataDesc_299[105].fieldSize = 131073;
    dataDesc_299[105].externalName = nullptr;
    v15 = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSCONSTRAINT);
    *(_QWORD *)&dataDesc_299[105].td = 0;
    *(_QWORD *)&dataDesc_299[105].override_field = 0;
    *(_QWORD *)&dataDesc_299[105].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_299[105].flatOffset[1] = 0;
    dataDesc_299[106].fieldTolerance = 0.0;
    dataDesc_299[107].fieldTolerance = 0.0;
    dataDesc_299[105].pSaveRestoreOps = v15;
    dataDesc_299[105].inputFunc = nullptr;
    dataDesc_299[106].fieldType = FIELD_INTEGER;
    dataDesc_299[106].fieldName = "m_ragdoll.list[18].parentIndex";
    dataDesc_299[106].fieldOffset = 1632;
    *(_DWORD *)&dataDesc_299[106].fieldSize = 131073;
    dataDesc_299[106].externalName = nullptr;
    dataDesc_299[106].pSaveRestoreOps = nullptr;
    dataDesc_299[106].inputFunc = nullptr;
    dataDesc_299[106].td = nullptr;
    dataDesc_299[106].fieldSizeInBytes = 4;
    dataDesc_299[106].override_field = nullptr;
    dataDesc_299[106].override_count = 0;
    *(_QWORD *)dataDesc_299[106].flatOffset = 0;
    *(_DWORD *)&dataDesc_299[106].flatGroup = 0;
    dataDesc_299[107].fieldType = FIELD_VECTOR;
    dataDesc_299[107].fieldName = "m_ragdoll.list[19].originParentSpace";
    dataDesc_299[107].fieldOffset = 1636;
    *(_DWORD *)&dataDesc_299[107].fieldSize = 131073;
    dataDesc_299[107].externalName = nullptr;
    dataDesc_299[107].pSaveRestoreOps = nullptr;
    dataDesc_299[107].inputFunc = nullptr;
    dataDesc_299[107].td = nullptr;
    dataDesc_299[107].fieldSizeInBytes = 12;
    dataDesc_299[107].override_field = nullptr;
    dataDesc_299[107].override_count = 0;
    *(_QWORD *)dataDesc_299[107].flatOffset = 0;
    *(_DWORD *)&dataDesc_299[107].flatGroup = 0;
    dataDesc_299[108].fieldType = FIELD_CUSTOM;
    dataDesc_299[108].fieldName = "m_ragdoll.list[19].pObject";
    dataDesc_299[108].fieldOffset = 1648;
    *(_DWORD *)&dataDesc_299[108].fieldSize = 131073;
    dataDesc_299[108].externalName = nullptr;
    dataDesc_299[108].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSOBJECT);
    dataDesc_299[108].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_299[108].td = 0;
    *(_QWORD *)&dataDesc_299[108].override_field = 0;
    *(_QWORD *)&dataDesc_299[108].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_299[108].flatOffset[1] = 0;
    dataDesc_299[109].fieldType = FIELD_CUSTOM;
    dataDesc_299[109].fieldName = "m_ragdoll.list[19].pConstraint";
    dataDesc_299[109].fieldOffset = 1652;
    *(_DWORD *)&dataDesc_299[109].fieldSize = 131073;
    dataDesc_299[109].externalName = nullptr;
    dataDesc_299[109].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSCONSTRAINT);
    dataDesc_299[109].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_299[109].td = 0;
    *(_QWORD *)&dataDesc_299[109].override_field = 0;
    *(_QWORD *)&dataDesc_299[109].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_299[109].flatOffset[1] = 0;
    dataDesc_299[110].fieldTolerance = 0.0;
    dataDesc_299[111].fieldTolerance = 0.0;
    dataDesc_299[110].fieldType = FIELD_INTEGER;
    dataDesc_299[110].fieldName = "m_ragdoll.list[19].parentIndex";
    dataDesc_299[110].fieldOffset = 1656;
    *(_DWORD *)&dataDesc_299[110].fieldSize = 131073;
    dataDesc_299[110].externalName = nullptr;
    dataDesc_299[110].pSaveRestoreOps = nullptr;
    dataDesc_299[110].inputFunc = nullptr;
    dataDesc_299[110].td = nullptr;
    dataDesc_299[110].fieldSizeInBytes = 4;
    dataDesc_299[110].override_field = nullptr;
    dataDesc_299[110].override_count = 0;
    *(_QWORD *)dataDesc_299[110].flatOffset = 0;
    *(_DWORD *)&dataDesc_299[110].flatGroup = 0;
    dataDesc_299[111].fieldType = FIELD_VECTOR;
    dataDesc_299[111].fieldName = "m_ragdoll.list[20].originParentSpace";
    dataDesc_299[111].fieldOffset = 1660;
    *(_DWORD *)&dataDesc_299[111].fieldSize = 131073;
    dataDesc_299[111].externalName = nullptr;
    dataDesc_299[111].pSaveRestoreOps = nullptr;
    dataDesc_299[111].inputFunc = nullptr;
    dataDesc_299[111].td = nullptr;
    dataDesc_299[111].fieldSizeInBytes = 12;
    dataDesc_299[111].override_field = nullptr;
    dataDesc_299[111].override_count = 0;
    *(_QWORD *)dataDesc_299[111].flatOffset = 0;
    *(_DWORD *)&dataDesc_299[111].flatGroup = 0;
    dataDesc_299[112].fieldType = FIELD_CUSTOM;
    dataDesc_299[112].fieldName = "m_ragdoll.list[20].pObject";
    dataDesc_299[112].fieldOffset = 1672;
    *(_DWORD *)&dataDesc_299[112].fieldSize = 131073;
    dataDesc_299[112].externalName = nullptr;
    dataDesc_299[112].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSOBJECT);
    dataDesc_299[112].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_299[112].td = 0;
    *(_QWORD *)&dataDesc_299[112].override_field = 0;
    *(_QWORD *)&dataDesc_299[112].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_299[112].flatOffset[1] = 0;
    dataDesc_299[113].fieldType = FIELD_CUSTOM;
    dataDesc_299[113].fieldName = "m_ragdoll.list[20].pConstraint";
    dataDesc_299[113].fieldOffset = 1676;
    *(_DWORD *)&dataDesc_299[113].fieldSize = 131073;
    dataDesc_299[113].externalName = nullptr;
    v16 = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSCONSTRAINT);
    *(_QWORD *)&dataDesc_299[113].td = 0;
    *(_QWORD *)&dataDesc_299[113].override_field = 0;
    *(_QWORD *)&dataDesc_299[113].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_299[113].flatOffset[1] = 0;
    dataDesc_299[113].pSaveRestoreOps = v16;
    dataDesc_299[113].inputFunc = nullptr;
    dataDesc_299[114].fieldType = FIELD_INTEGER;
    dataDesc_299[114].fieldName = "m_ragdoll.list[20].parentIndex";
    dataDesc_299[114].fieldOffset = 1680;
    *(_DWORD *)&dataDesc_299[114].fieldSize = 131073;
    dataDesc_299[114].externalName = nullptr;
    dataDesc_299[114].pSaveRestoreOps = nullptr;
    dataDesc_299[114].inputFunc = nullptr;
    dataDesc_299[114].td = nullptr;
    dataDesc_299[114].fieldSizeInBytes = 4;
    dataDesc_299[114].override_field = nullptr;
    dataDesc_299[114].override_count = 0;
    dataDesc_299[114].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_299[114].flatOffset = 0;
    *(_DWORD *)&dataDesc_299[114].flatGroup = 0;
    dataDesc_299[115].fieldType = FIELD_VECTOR;
    dataDesc_299[115].fieldName = "m_ragdoll.list[21].originParentSpace";
    dataDesc_299[115].fieldOffset = 1684;
    *(_DWORD *)&dataDesc_299[115].fieldSize = 131073;
    dataDesc_299[115].fieldTolerance = 0.0;
    dataDesc_299[115].externalName = nullptr;
    dataDesc_299[115].pSaveRestoreOps = nullptr;
    dataDesc_299[115].inputFunc = nullptr;
    dataDesc_299[115].td = nullptr;
    dataDesc_299[115].fieldSizeInBytes = 12;
    dataDesc_299[115].override_field = nullptr;
    dataDesc_299[115].override_count = 0;
    *(_QWORD *)dataDesc_299[115].flatOffset = 0;
    *(_DWORD *)&dataDesc_299[115].flatGroup = 0;
    dataDesc_299[116].fieldType = FIELD_CUSTOM;
    dataDesc_299[116].fieldName = "m_ragdoll.list[21].pObject";
    dataDesc_299[116].fieldOffset = 1696;
    *(_DWORD *)&dataDesc_299[116].fieldSize = 131073;
    dataDesc_299[116].externalName = nullptr;
    dataDesc_299[116].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSOBJECT);
    dataDesc_299[116].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_299[116].td = 0;
    *(_QWORD *)&dataDesc_299[116].override_field = 0;
    *(_QWORD *)&dataDesc_299[116].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_299[116].flatOffset[1] = 0;
    dataDesc_299[117].fieldType = FIELD_CUSTOM;
    dataDesc_299[117].fieldName = "m_ragdoll.list[21].pConstraint";
    dataDesc_299[117].fieldOffset = 1700;
    *(_DWORD *)&dataDesc_299[117].fieldSize = 131073;
    dataDesc_299[117].externalName = nullptr;
    v17 = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSCONSTRAINT);
    *(_QWORD *)&dataDesc_299[117].td = 0;
    *(_QWORD *)&dataDesc_299[117].override_field = 0;
    *(_QWORD *)&dataDesc_299[117].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_299[117].flatOffset[1] = 0;
    dataDesc_299[118].fieldTolerance = 0.0;
    dataDesc_299[119].fieldTolerance = 0.0;
    dataDesc_299[117].pSaveRestoreOps = v17;
    dataDesc_299[117].inputFunc = nullptr;
    dataDesc_299[118].fieldType = FIELD_INTEGER;
    dataDesc_299[118].fieldName = "m_ragdoll.list[21].parentIndex";
    dataDesc_299[118].fieldOffset = 1704;
    *(_DWORD *)&dataDesc_299[118].fieldSize = 131073;
    dataDesc_299[118].externalName = nullptr;
    dataDesc_299[118].pSaveRestoreOps = nullptr;
    dataDesc_299[118].inputFunc = nullptr;
    dataDesc_299[118].td = nullptr;
    dataDesc_299[118].fieldSizeInBytes = 4;
    dataDesc_299[118].override_field = nullptr;
    dataDesc_299[118].override_count = 0;
    *(_QWORD *)dataDesc_299[118].flatOffset = 0;
    *(_DWORD *)&dataDesc_299[118].flatGroup = 0;
    dataDesc_299[119].fieldType = FIELD_VECTOR;
    dataDesc_299[119].fieldName = "m_ragdoll.list[22].originParentSpace";
    dataDesc_299[119].fieldOffset = 1708;
    *(_DWORD *)&dataDesc_299[119].fieldSize = 131073;
    dataDesc_299[119].externalName = nullptr;
    dataDesc_299[119].pSaveRestoreOps = nullptr;
    dataDesc_299[119].inputFunc = nullptr;
    dataDesc_299[119].td = nullptr;
    dataDesc_299[119].fieldSizeInBytes = 12;
    dataDesc_299[119].override_field = nullptr;
    dataDesc_299[119].override_count = 0;
    *(_QWORD *)dataDesc_299[119].flatOffset = 0;
    *(_DWORD *)&dataDesc_299[119].flatGroup = 0;
    dataDesc_299[120].fieldType = FIELD_CUSTOM;
    dataDesc_299[120].fieldName = "m_ragdoll.list[22].pObject";
    dataDesc_299[120].fieldOffset = 1720;
    *(_DWORD *)&dataDesc_299[120].fieldSize = 131073;
    dataDesc_299[120].externalName = nullptr;
    dataDesc_299[120].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSOBJECT);
    dataDesc_299[120].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_299[120].td = 0;
    *(_QWORD *)&dataDesc_299[120].override_field = 0;
    *(_QWORD *)&dataDesc_299[120].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_299[120].flatOffset[1] = 0;
    dataDesc_299[121].fieldType = FIELD_CUSTOM;
    dataDesc_299[121].fieldName = "m_ragdoll.list[22].pConstraint";
    dataDesc_299[121].fieldOffset = 1724;
    *(_DWORD *)&dataDesc_299[121].fieldSize = 131073;
    dataDesc_299[121].externalName = nullptr;
    v18 = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSCONSTRAINT);
    *(_QWORD *)&dataDesc_299[121].td = 0;
    *(_QWORD *)&dataDesc_299[121].override_field = 0;
    *(_QWORD *)&dataDesc_299[121].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_299[121].flatOffset[1] = 0;
    dataDesc_299[122].fieldTolerance = 0.0;
    dataDesc_299[123].fieldTolerance = 0.0;
    dataDesc_299[121].pSaveRestoreOps = v18;
    dataDesc_299[121].inputFunc = nullptr;
    dataDesc_299[122].fieldType = FIELD_INTEGER;
    dataDesc_299[122].fieldName = "m_ragdoll.list[22].parentIndex";
    dataDesc_299[122].fieldOffset = 1728;
    *(_DWORD *)&dataDesc_299[122].fieldSize = 131073;
    dataDesc_299[122].externalName = nullptr;
    dataDesc_299[122].pSaveRestoreOps = nullptr;
    dataDesc_299[122].inputFunc = nullptr;
    dataDesc_299[122].td = nullptr;
    dataDesc_299[122].fieldSizeInBytes = 4;
    dataDesc_299[122].override_field = nullptr;
    dataDesc_299[122].override_count = 0;
    *(_QWORD *)dataDesc_299[122].flatOffset = 0;
    *(_DWORD *)&dataDesc_299[122].flatGroup = 0;
    dataDesc_299[123].fieldType = FIELD_VECTOR;
    dataDesc_299[123].fieldName = "m_ragdoll.list[23].originParentSpace";
    dataDesc_299[123].fieldOffset = 1732;
    *(_DWORD *)&dataDesc_299[123].fieldSize = 131073;
    dataDesc_299[123].externalName = nullptr;
    dataDesc_299[123].pSaveRestoreOps = nullptr;
    dataDesc_299[123].inputFunc = nullptr;
    dataDesc_299[123].td = nullptr;
    dataDesc_299[123].fieldSizeInBytes = 12;
    dataDesc_299[123].override_field = nullptr;
    dataDesc_299[123].override_count = 0;
    *(_QWORD *)dataDesc_299[123].flatOffset = 0;
    *(_DWORD *)&dataDesc_299[123].flatGroup = 0;
    dataDesc_299[124].fieldType = FIELD_CUSTOM;
    dataDesc_299[124].fieldName = "m_ragdoll.list[23].pObject";
    dataDesc_299[124].fieldOffset = 1744;
    *(_DWORD *)&dataDesc_299[124].fieldSize = 131073;
    dataDesc_299[124].externalName = nullptr;
    dataDesc_299[124].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSOBJECT);
    dataDesc_299[124].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_299[124].td = 0;
    *(_QWORD *)&dataDesc_299[124].override_field = 0;
    *(_QWORD *)&dataDesc_299[124].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_299[124].flatOffset[1] = 0;
    dataDesc_299[125].fieldType = FIELD_CUSTOM;
    dataDesc_299[125].fieldName = "m_ragdoll.list[23].pConstraint";
    dataDesc_299[125].fieldOffset = 1748;
    *(_DWORD *)&dataDesc_299[125].fieldSize = 131073;
    dataDesc_299[125].externalName = nullptr;
    dataDesc_299[125].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSCONSTRAINT);
    dataDesc_299[125].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_299[125].td = 0;
    *(_QWORD *)&dataDesc_299[125].override_field = 0;
    *(_QWORD *)&dataDesc_299[125].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_299[125].flatOffset[1] = 0;
    dataDesc_299[126].fieldType = FIELD_INTEGER;
    dataDesc_299[126].fieldName = "m_ragdoll.list[23].parentIndex";
    dataDesc_299[126].fieldOffset = 1752;
    *(_DWORD *)&dataDesc_299[126].fieldSize = 131073;
    dataDesc_299[126].fieldTolerance = 0.0;
    dataDesc_299[126].fieldSizeInBytes = 4;
    dataDesc_299[126].externalName = nullptr;
    dataDesc_299[126].pSaveRestoreOps = nullptr;
    dataDesc_299[126].inputFunc = nullptr;
    dataDesc_299[126].td = nullptr;
    dataDesc_299[126].override_field = nullptr;
    dataDesc_299[126].override_count = 0;
    *(_QWORD *)dataDesc_299[126].flatOffset = 0;
    *(_DWORD *)&dataDesc_299[126].flatGroup = 0;
  }
  CRagdollProp::m_DataMap.dataNumFields = 126;
  CRagdollProp::m_DataMap.dataDesc = &dataDesc_299[1];
  return &CRagdollProp::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1041CE00
// Name: _ServerClassInit_DT_Ragdoll_Attached::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_Ragdoll_Attached::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S5_23;
  for ( i = 5; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041CE20
// Name: _ServerClassInit_DT_Ragdoll::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_Ragdoll::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_167;
  for ( i = 8; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041CE40
// Name: _DataMapInit_CRagdollPropAttached__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CRagdollPropAttached__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_311);
}

//------------------------------------------------------------------------------
// Address: 0x1041CE50
// Name: _DataMapInit_CRagdollProp__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CRagdollProp__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_312);
}
