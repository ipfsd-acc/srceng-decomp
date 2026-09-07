// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_props.cpp
// Functions: 62
// ============================================================

#include "game\client\c_props.h"

//------------------------------------------------------------------------------
// Address: 0x100811A0
// Name: public: virtual class ClientClass __near * C_DynamicProp::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_DynamicProp::GetClientClass(C_DynamicProp *this)
{
  return &__g_C_DynamicPropClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10081230
// Name: public: virtual C_DynamicProp::~C_DynamicProp(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_DynamicProp::~C_DynamicProp(C_DynamicProp *this)
{
  this->C_BreakableProp::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_DynamicProp_vtbl *)&C_DynamicProp::`vftable'{for `IClientUnknown'};
  this->C_BreakableProp::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_DynamicProp::`vftable'{for `IClientRenderable'};
  this->C_BreakableProp::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_DynamicProp::`vftable'{for `IClientNetworkable'};
  this->C_BreakableProp::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_DynamicProp::`vftable'{for `IClientThinkable'};
  this->C_BreakableProp::C_BaseAnimating::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_DynamicProp::`vftable'{for `C_BaseAnimating'};
  this->C_BreakableProp::CDefaultPlayerPickupVPhysics::IPlayerPickupVPhysics::__vftable = (CDefaultPlayerPickupVPhysics_vtbl *)&C_DynamicProp::`vftable'{for `CDefaultPlayerPickupVPhysics'};
  C_BaseAnimating::~C_BaseAnimating(this);
}

//------------------------------------------------------------------------------
// Address: 0x10081270
// Name: public: virtual class ClientClass __near * C_BasePropDoor::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_BasePropDoor::GetClientClass(C_BasePropDoor *this)
{
  return &__g_C_BasePropDoorClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x100812F0
// Name: public: virtual void C_BasePropDoor::PostDataUpdate(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePropDoor::PostDataUpdate(C_BasePropDoor *this, DataUpdateType_t updateType)
{
  int v3; // ebx

  if ( updateType != DATA_UPDATE_CREATED )
  {
    v3 = (*(int (__thiscall **)(char *))(*((_DWORD *)this - 1) + 32))(a1: (char *)this - 4);
    C_BaseAnimating::PostDataUpdate(this, updateType);
    if ( v3 != (*(int (__thiscall **)(char *))(*((_DWORD *)this - 1) + 32))(a1: (char *)this - 4) )
      LOBYTE(this->m_vecCachedRenderMaxs.y) = 1;
  }
  else
  {
    C_BaseAnimating::PostDataUpdate(this, updateType: DATA_UPDATE_CREATED);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10081340
// Name: public: virtual class ClientClass __near * C_PropDoorRotating::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_PropDoorRotating::GetClientClass(C_PropDoorRotating *this)
{
  return &__g_C_PropDoorRotatingClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x100813C0
// Name: public: virtual class ClientClass __near * CPhysBoxMultiplayer::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall CPhysBoxMultiplayer::GetClientClass(CPhysBoxMultiplayer *this)
{
  return &__g_CPhysBoxMultiplayerClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10081470
// Name: private: virtual class ClientClass __near * CPhysicsPropMultiplayer::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall CPhysicsPropMultiplayer::GetClientClass(CPhysicsPropMultiplayer *this)
{
  return &__g_CPhysicsPropMultiplayerClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10081560
// Name: public: C_DynamicProp::C_DynamicProp(void)
// Source: json
//------------------------------------------------------------------------------
C_DynamicProp *__thiscall C_DynamicProp::C_DynamicProp(C_DynamicProp *this)
{
  C_BreakableProp::C_BreakableProp(this);
  this->C_BreakableProp::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_DynamicProp_vtbl *)&C_DynamicProp::`vftable'{for `IClientUnknown'};
  this->C_BreakableProp::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_DynamicProp::`vftable'{for `IClientRenderable'};
  this->C_BreakableProp::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_DynamicProp::`vftable'{for `IClientNetworkable'};
  this->C_BreakableProp::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_DynamicProp::`vftable'{for `IClientThinkable'};
  this->C_BreakableProp::C_BaseAnimating::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_DynamicProp::`vftable'{for `C_BaseAnimating'};
  this->C_BreakableProp::CDefaultPlayerPickupVPhysics::IPlayerPickupVPhysics::__vftable = (CDefaultPlayerPickupVPhysics_vtbl *)&C_DynamicProp::`vftable'{for `CDefaultPlayerPickupVPhysics'};
  this->m_iCachedFrameCount = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10081600
// Name: public: virtual void C_DynamicProp::GetRenderBounds(class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_DynamicProp::GetRenderBounds(C_DynamicProp *this, Vector *theMins, Vector *theMaxs)
{
  IVModelInfoClient_vtbl *v4; // edi
  IClientThinkable *v5; // eax

  if ( *(&this->m_bClientPhysics + 4) && this->GetClientThinkable(this) != nullptr )
  {
    v4 = modelinfo->__vftable;
    v5 = this->GetClientThinkable(this);
    if ( v4->GetStudiomodel(this: modelinfo, a2: (const struct model_t *)v5) == nullptr
      || *(_DWORD *)&this->m_builtRagdoll == -1 )
    {
      *theMins = vec3_origin;
      *theMaxs = vec3_origin;
    }
    else
    {
      if ( *(_DWORD *)(gpGlobals.m_Index + 4) != *(_DWORD *)&this->m_bUseHitboxesForRenderBox )
      {
        C_BaseAnimating::ComputeEntitySpaceHitboxSurroundingBox(
          this: (C_DynamicProp *)((char *)this - 4),
          pVecWorldMins: (Vector *)&this->m_iCachedFrameCount,
          pVecWorldMaxs: (Vector *)&this->m_vecCachedRenderMins.z);
        *(_DWORD *)&this->m_bUseHitboxesForRenderBox = *(_DWORD *)(gpGlobals.m_Index + 4);
      }
      *theMins = *(Vector *)&this->m_iCachedFrameCount;
      *theMaxs = *(Vector *)&this->m_vecCachedRenderMins.z;
    }
  }
  else
  {
    C_BaseAnimating::GetRenderBounds(this, theMins, theMaxs);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10081730
// Name: public: virtual unsigned int C_DynamicProp::ComputeClientSideAnimationFlags(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall C_DynamicProp::ComputeClientSideAnimationFlags(C_DynamicProp *this)
{
  CStudioHdr *m_pStudioHdr; // eax

  if ( this->m_nSequence == -1 )
    return 0;
  if ( this->m_pStudioHdr == nullptr && this->GetModel(this: &this->IClientRenderable) != nullptr )
    C_BaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr || m_pStudioHdr->m_pStudioHdr == nullptr )
    m_pStudioHdr = nullptr;
  if ( ((double (__thiscall *)(C_DynamicProp *, CStudioHdr *, int))this->GetSequenceCycleRate)(
         a1: this,
         a2: m_pStudioHdr,
         a3: this->m_nSequence) == 0.0 )
    return 0;
  else
    return C_OP_ConstrainDistance::GetWrittenAttributes((C_OP_RenderPoints *)this);
}

//------------------------------------------------------------------------------
// Address: 0x100817A0
// Name: public: virtual void C_BasePropDoor::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BasePropDoor::OnDataChanged(C_BasePropDoor *this, DataUpdateType_t type)
{
  bool bCreate; // [esp+10h] [ebp+8h]

  C_BreakableProp::OnDataChanged(this, type);
  bCreate = type == DATA_UPDATE_CREATED;
  if ( this->m_nLastRecordedFrame != 0 && LOBYTE(this->m_vecCachedRenderMaxs.y) != 0 )
  {
    (*(void (__thiscall **)(char *))(*((_DWORD *)this - 2) + 256))(a1: (char *)this - 8);
    LOBYTE(this->m_vecCachedRenderMaxs.y) = 0;
    bCreate = true;
  }
  VPhysicsShadowDataChanged(bCreate, pEntity: (C_BasePropDoor *)((char *)this - 8));
}

//------------------------------------------------------------------------------
// Address: 0x10081800
// Name: public: virtual bool C_BasePropDoor::TestCollision(struct Ray_t const __near &,unsigned int,class CGameTrace __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_BasePropDoor::TestCollision(
        C_BasePropDoor *this,
        const Ray_t *ray,
        unsigned int mask,
        CGameTrace *trace)
{
  IMDLCache *v6; // edi
  CStudioHdr *m_pStudioHdr; // eax
  IPhysicsObject *m_pPhysicsObject; // ebx
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int contents; // edx
  CStudioHdr *v13; // [esp+4h] [ebp-Ch]
  IPhysicsCollision_vtbl *v14; // [esp+8h] [ebp-8h]
  IMDLCache *cacheCriticalSection; // [esp+Ch] [ebp-4h]

  if ( this->m_pPhysicsObject == nullptr )
    return 0;
  v6 = mdlcache;
  cacheCriticalSection = mdlcache;
  mdlcache->BeginLock(this: mdlcache);
  if ( this->m_pStudioHdr == nullptr && this->GetModel(this: &this->IClientRenderable) != nullptr )
    C_BaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  v13 = m_pStudioHdr;
  if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr != nullptr )
  {
    m_pPhysicsObject = this->m_pPhysicsObject;
    v14 = physcollision->__vftable;
    v9 = ((int (__thiscall *)(C_BasePropDoor *, CGameTrace *))this->GetAbsAngles)(a1: this, a2: trace);
    v10 = ((int (__thiscall *)(C_BasePropDoor *, int))this->GetAbsOrigin)(a1: this, a2: v9);
    v11 = ((int (__thiscall *)(IPhysicsObject *, int))m_pPhysicsObject->GetCollide)(a1: m_pPhysicsObject, a2: v10);
    ((void (__thiscall *)(IPhysicsCollision *, const Ray_t *, int))v14->TraceBox_2)(a1: physcollision, a2: ray, a3: v11);
    if ( trace->fraction < 1.0 || trace->allsolid || trace->startsolid )
    {
      contents = v13->m_pStudioHdr->contents;
      trace->surface.flags = 0;
      trace->contents = contents;
      trace->surface.name = "**studio**";
      trace->surface.surfaceProps = v13->m_pStudioHdr->surfacepropLookup;
      cacheCriticalSection->EndLock(this: cacheCriticalSection);
      return 1;
    }
    else
    {
      cacheCriticalSection->EndLock(this: cacheCriticalSection);
      return 0;
    }
  }
  else
  {
    v6->EndLock(this: v6);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100819E0
// Name: public: bool C_DynamicProp::TestBoneFollowers(struct Ray_t const __near &,unsigned int,class CGameTrace __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_DynamicProp::TestBoneFollowers(
        C_DynamicProp *this,
        const Ray_t *ray,
        unsigned int fContentsMask,
        CGameTrace *tr)
{
  int v4; // edi
  int v5; // esi
  C_BaseEntity *v6; // ecx
  unsigned int m_Index; // edx
  IHandleEntity *m_pEntity; // eax
  C_BaseEntity *pList[128]; // [esp+Ch] [ebp-21Ch] BYREF
  Vector mins; // [esp+20Ch] [ebp-1Ch] BYREF
  Vector maxs; // [esp+218h] [ebp-10h] BYREF
  C_DynamicProp *v13; // [esp+224h] [ebp-4h]

  v13 = this;
  CCollisionProperty::CollisionAABBToWorldAABB(
    this: &this->m_Collision,
    entityMins: &this->m_Collision.m_vecMins.m_Value,
    entityMaxs: &this->m_Collision.m_vecMaxs.m_Value,
    pWorldMins: &mins,
    pWorldMaxs: &maxs);
  v4 = UTIL_EntitiesInBox(pList, listMax: 128, &mins, &maxs, flagMask: 0, partitionMask: 4);
  v5 = 0;
  if ( v4 <= 0 )
    return 0;
  while ( 1 )
  {
    v6 = pList[v5];
    m_Index = v6->m_hOwnerEntity.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    if ( m_pEntity == v13 && v6->TestCollision(this: v6, a2: ray, a3: fContentsMask, a4: tr) )
      break;
    if ( ++v5 >= v4 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10081AB0
// Name: public: virtual bool C_DynamicProp::TestCollision(struct Ray_t const __near &,unsigned int,class CGameTrace __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall C_DynamicProp::TestCollision(
        C_DynamicProp *this,
        const Ray_t *ray,
        unsigned int fContentsMask,
        CGameTrace *tr)
{
  unsigned __int16 m_Value; // ax

  m_Value = this->m_Collision.m_usSolidFlags.m_Value;
  if ( (m_Value & 4) != 0 && (m_Value & 2) != 0 && (this->m_Collision.m_usSolidFlags.m_Value & 1) != 0 )
    return C_DynamicProp::TestBoneFollowers(this, ray, fContentsMask, tr);
  else
    return C_BaseAnimating::TestCollision(this, ray, fContentsMask, tr);
}

//------------------------------------------------------------------------------
// Address: 0x10081BE0
// Name: _CPhysBoxMultiplayer_CreateObject
// Source: semantic_flat_class
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl CPhysBoxMultiplayer_CreateObject(int entnum, int serialNum)
{
  C_PhysBox *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_PhysBox *)C_BaseEntity::operator new(stAllocateBlock: 0x998u);
  v3 = &v2->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_PhysBox::C_PhysBox(this: v2);
  v3[610] = &IMultiplayerPhysics::`vftable';
  *v3 = &CPhysBoxMultiplayer::`vftable'{for `IClientUnknown'};
  v3[1] = &CPhysBoxMultiplayer::`vftable'{for `IClientRenderable'};
  v3[2] = &CPhysBoxMultiplayer::`vftable'{for `IClientNetworkable'};
  v3[3] = &CPhysBoxMultiplayer::`vftable'{for `IClientThinkable'};
  v3[4] = &CPhysBoxMultiplayer::`vftable'{for `C_PhysBox'};
  v3[610] = &CPhysBoxMultiplayer::`vftable'{for `IMultiplayerPhysics'};
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x10081C60
// Name: private: virtual bool CPhysicsPropMultiplayer::IsAsleep(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CPhysicsPropMultiplayer::IsAsleep(CPhysicsPropMultiplayer *this)
{
  return *((_BYTE *)this - 32) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10081C70
// Name: private: virtual float CPhysicsPropMultiplayer::GetMass(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CPhysicsPropMultiplayer::GetMass(CPhysicsPropMultiplayer *this)
{
  return *(float *)&this->C_PhysicsProp::C_BreakableProp::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable;
}

//------------------------------------------------------------------------------
// Address: 0x10081C80
// Name: private: virtual void CPhysicsPropMultiplayer::ComputeWorldSpaceSurroundingBox(class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsPropMultiplayer::ComputeWorldSpaceSurroundingBox(
        CPhysicsPropMultiplayer *this,
        Vector *mins,
        Vector *maxs)
{
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  if ( mins != nullptr && maxs != nullptr )
  {
    C_BaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    TransformAABB(
      transform: &this->m_rgflCoordinateFrame,
      vecMinsIn: &this->m_collisionMins.m_Value,
      vecMaxsIn: &this->m_collisionMaxs.m_Value,
      vecMinsOut: mins,
      vecMaxsOut: maxs);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10081D00
// Name: _CPhysicsPropMultiplayer_CreateObject
// Source: semantic_flat_class
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl CPhysicsPropMultiplayer_CreateObject(int entnum, int serialNum)
{
  C_PhysicsProp *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_PhysicsProp *)C_BaseEntity::operator new(stAllocateBlock: 0xD18u);
  v3 = &v2->C_BreakableProp::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_PhysicsProp::C_PhysicsProp(this: v2);
  v3[828] = &IMultiplayerPhysics::`vftable';
  *v3 = &CPhysicsPropMultiplayer::`vftable'{for `IClientUnknown'};
  v3[1] = &CPhysicsPropMultiplayer::`vftable'{for `IClientRenderable'};
  v3[2] = &CPhysicsPropMultiplayer::`vftable'{for `IClientNetworkable'};
  v3[3] = &CPhysicsPropMultiplayer::`vftable'{for `IClientThinkable'};
  v3[4] = &CPhysicsPropMultiplayer::`vftable'{for `C_BaseAnimating'};
  v3[814] = &CPhysicsPropMultiplayer::`vftable'{for `CDefaultPlayerPickupVPhysics'};
  v3[828] = &CPhysicsPropMultiplayer::`vftable';
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x10413010
// Name: DT_DynamicProp::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_DynamicProp::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_DynamicProp::g_RecvTable);
  return atexit(func: DT_DynamicProp::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10413030
// Name: DT_DynamicProp::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_DynamicProp::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_DynamicProp::ignored>();
  DT_DynamicProp::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10413060
// Name: DT_BasePropDoor::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_BasePropDoor::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_BasePropDoor::g_RecvTable);
  return atexit(func: DT_BasePropDoor::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10413080
// Name: DT_BasePropDoor::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_BasePropDoor::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_BasePropDoor::ignored>();
  DT_BasePropDoor::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104130B0
// Name: DT_PropDoorRotating::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_PropDoorRotating::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_PropDoorRotating::g_RecvTable);
  return atexit(func: DT_PropDoorRotating::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104130D0
// Name: DT_PropDoorRotating::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_PropDoorRotating::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_PropDoorRotating::ignored>();
  DT_PropDoorRotating::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10413100
// Name: DT_PhysBoxMultiplayer::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_PhysBoxMultiplayer::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_PhysBoxMultiplayer::g_RecvTable);
  return atexit(func: DT_PhysBoxMultiplayer::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10413120
// Name: DT_PhysBoxMultiplayer::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_PhysBoxMultiplayer::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_PhysBoxMultiplayer::ignored>();
  DT_PhysBoxMultiplayer::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10413150
// Name: DT_PhysicsPropMultiplayer::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_PhysicsPropMultiplayer::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_PhysicsPropMultiplayer::g_RecvTable);
  return atexit(func: DT_PhysicsPropMultiplayer::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10413170
// Name: DT_PhysicsPropMultiplayer::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_PhysicsPropMultiplayer::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_PhysicsPropMultiplayer::ignored>();
  DT_PhysicsPropMultiplayer::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041BC80
// Name: _dynamic_initializer_for__props_break_max_pieces__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__props_break_max_pieces__()
{
  ConVar::ConVar(
    this: &props_break_max_pieces,
    pName: "props_break_max_pieces",
    pDefaultValue: "-1",
    flags: 0x2000,
    pHelpString: "Maximum prop breakable piece count (-1 = model default)");
  return atexit(func: dynamic_atexit_destructor_for__props_break_max_pieces__);
}

//------------------------------------------------------------------------------
// Address: 0x1041BCB0
// Name: _dynamic_initializer_for__props_break_max_pieces_perframe__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__props_break_max_pieces_perframe__()
{
  ConVar::ConVar(
    this: &props_break_max_pieces_perframe,
    pName: "props_break_max_pieces_perframe",
    pDefaultValue: "-1",
    flags: 0x2000,
    pHelpString: "Maximum prop breakable piece count per frame (-1 = model default)");
  return atexit(func: dynamic_atexit_destructor_for__props_break_max_pieces_perframe__);
}

//------------------------------------------------------------------------------
// Address: 0x104308B0
// Name: DT_DynamicProp::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_DynamicProp::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_DynamicProp::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x104308C0
// Name: DT_BasePropDoor::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_BasePropDoor::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_BasePropDoor::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x104308D0
// Name: DT_PropDoorRotating::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_PropDoorRotating::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_PropDoorRotating::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x104308E0
// Name: DT_PhysBoxMultiplayer::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_PhysBoxMultiplayer::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_PhysBoxMultiplayer::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x104308F0
// Name: DT_PhysicsPropMultiplayer::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_PhysicsPropMultiplayer::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_PhysicsPropMultiplayer::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10433720
// Name: _dynamic_atexit_destructor_for__props_break_max_pieces__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__props_break_max_pieces__()
{
  ConVar::~ConVar(this: &props_break_max_pieces);
}

//------------------------------------------------------------------------------
// Address: 0x10433730
// Name: _dynamic_atexit_destructor_for__props_break_max_pieces_perframe__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__props_break_max_pieces_perframe__()
{
  ConVar::~ConVar(this: &props_break_max_pieces_perframe);
}

//------------------------------------------------------------------------------
// Address: 0x10081960
// Name: _C_DynamicProp_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_DynamicProp_CreateObject(int entnum, int serialNum)
{
  C_BreakableProp *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_BreakableProp *)C_BaseEntity::operator new(stAllocateBlock: 0xCF0u);
  v3 = &v2->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_BreakableProp::C_BreakableProp(this: v2);
  *v3 = &C_DynamicProp::`vftable'{for `IClientUnknown'};
  v3[1] = &C_DynamicProp::`vftable'{for `IClientRenderable'};
  v3[2] = &C_DynamicProp::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_DynamicProp::`vftable'{for `IClientThinkable'};
  v3[4] = &C_DynamicProp::`vftable'{for `C_BaseAnimating'};
  v3[814] = &C_DynamicProp::`vftable'{for `CDefaultPlayerPickupVPhysics'};
  v3[821] = -1;
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x10081AE0
// Name: _C_BasePropDoor_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_BasePropDoor_CreateObject(int entnum, int serialNum)
{
  C_BreakableProp *v2; // eax
  C_BreakableProp *v3; // esi

  v2 = (C_BreakableProp *)C_BaseEntity::operator new(stAllocateBlock: 0xCF8u);
  v3 = v2;
  if ( v2 == nullptr )
    return nullptr;
  C_BreakableProp::C_BreakableProp(this: v2);
  v3[1].C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)-1;
  v3->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_BreakableProp_vtbl *)&C_BasePropDoor::`vftable'{for `IClientUnknown'};
  v3->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_BasePropDoor::`vftable'{for `IClientRenderable'};
  v3->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_BasePropDoor::`vftable'{for `IClientNetworkable'};
  v3->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_BasePropDoor::`vftable'{for `IClientThinkable'};
  v3->C_BaseAnimating::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_BasePropDoor::`vftable'{for `C_BaseAnimating'};
  v3->CDefaultPlayerPickupVPhysics::IPlayerPickupVPhysics::__vftable = (CDefaultPlayerPickupVPhysics_vtbl *)&C_BasePropDoor::`vftable'{for `CDefaultPlayerPickupVPhysics'};
  LOBYTE(v3[1].m_VarMap.m_Entries.m_Memory.m_pMemory) = 0;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v3->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x10081B60
// Name: _C_PropDoorRotating_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_PropDoorRotating_CreateObject(int entnum, int serialNum)
{
  C_BreakableProp *v2; // eax
  C_BreakableProp *v3; // esi

  v2 = (C_BreakableProp *)C_BaseEntity::operator new(stAllocateBlock: 0xCF8u);
  v3 = v2;
  if ( v2 == nullptr )
    return nullptr;
  C_BreakableProp::C_BreakableProp(this: v2);
  v3[1].C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)-1;
  LOBYTE(v3[1].m_VarMap.m_Entries.m_Memory.m_pMemory) = 0;
  v3->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_BreakableProp_vtbl *)&C_PropDoorRotating::`vftable'{for `IClientUnknown'};
  v3->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_PropDoorRotating::`vftable'{for `IClientRenderable'};
  v3->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_PropDoorRotating::`vftable'{for `IClientNetworkable'};
  v3->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_PropDoorRotating::`vftable'{for `IClientThinkable'};
  v3->C_BaseAnimating::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_PropDoorRotating::`vftable'{for `C_BaseAnimating'};
  v3->CDefaultPlayerPickupVPhysics::IPlayerPickupVPhysics::__vftable = (CDefaultPlayerPickupVPhysics_vtbl *)&C_PropDoorRotating::`vftable'{for `CDefaultPlayerPickupVPhysics'};
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v3->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x10413040
// Name: _dynamic_initializer_for____g_C_BasePropDoorClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_BasePropDoorClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_BasePropDoorClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_BasePropDoorClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10413090
// Name: _dynamic_initializer_for____g_C_PropDoorRotatingClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_PropDoorRotatingClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_PropDoorRotatingClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_PropDoorRotatingClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104130E0
// Name: _dynamic_initializer_for____g_CPhysBoxMultiplayerClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_CPhysBoxMultiplayerClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_CPhysBoxMultiplayerClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_CPhysBoxMultiplayerClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10413130
// Name: _dynamic_initializer_for____g_CPhysicsPropMultiplayerClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_CPhysicsPropMultiplayerClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_CPhysicsPropMultiplayerClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_CPhysicsPropMultiplayerClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10413180
// Name: _dynamic_initializer_for____g_C_RagdollManagerClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_RagdollManagerClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_RagdollManagerClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_RagdollManagerClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041BCE0
// Name: _dynamic_initializer_for__cl_burninggibs__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_burninggibs__()
{
  ConVar::ConVar(
    this: &cl_burninggibs,
    pName: "cl_burninggibs",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "A burning player that gibs has burning gibs.");
  return atexit(func: dynamic_atexit_destructor_for__cl_burninggibs__);
}

//------------------------------------------------------------------------------
// Address: 0x1041BD10
// Name: _dynamic_initializer_for__g_PropDataSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_PropDataSystem__()
{
  CPropData::CPropData(this: &g_PropDataSystem);
  return atexit(func: dynamic_atexit_destructor_for__g_PropDataSystem__);
}

//------------------------------------------------------------------------------
// Address: 0x1041BD30
// Name: _dynamic_initializer_for__g_CHealthFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CHealthFoo__()
{
  CMaterialProxyDict *MaterialProxyDict; // eax

  MaterialProxyDict = GetMaterialProxyDict();
  return ((int (__thiscall *)(CMaterialProxyDict *, const char *, IMaterialProxy *(__cdecl *)()))MaterialProxyDict->Add)(
           a1: MaterialProxyDict,
           a2: "Health",
           a3: CCProxyHealthFactory);
}

//------------------------------------------------------------------------------
// Address: 0x1041BD50
// Name: _dynamic_initializer_for__g_CPlayerProximityFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CPlayerProximityFoo__()
{
  CMaterialProxyDict *MaterialProxyDict; // eax

  MaterialProxyDict = GetMaterialProxyDict();
  return ((int (__thiscall *)(CMaterialProxyDict *, const char *, IMaterialProxy *(__cdecl *)()))MaterialProxyDict->Add)(
           a1: MaterialProxyDict,
           a2: "PlayerProximity",
           a3: CCPlayerProximityProxyFactory);
}

//------------------------------------------------------------------------------
// Address: 0x1041BD70
// Name: _dynamic_initializer_for__g_CPlayerTeamMatchFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CPlayerTeamMatchFoo__()
{
  CMaterialProxyDict *MaterialProxyDict; // eax

  MaterialProxyDict = GetMaterialProxyDict();
  return ((int (__thiscall *)(CMaterialProxyDict *, const char *, IMaterialProxy *(__cdecl *)()))MaterialProxyDict->Add)(
           a1: MaterialProxyDict,
           a2: "PlayerTeamMatch",
           a3: CCPlayerTeamMatchProxyFactory);
}

//------------------------------------------------------------------------------
// Address: 0x1041BD90
// Name: _dynamic_initializer_for__g_CPlayerViewFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CPlayerViewFoo__()
{
  CMaterialProxyDict *MaterialProxyDict; // eax

  MaterialProxyDict = GetMaterialProxyDict();
  return ((int (__thiscall *)(CMaterialProxyDict *, const char *, IMaterialProxy *(__cdecl *)()))MaterialProxyDict->Add)(
           a1: MaterialProxyDict,
           a2: "PlayerView",
           a3: CCPlayerViewProxyFactory);
}

//------------------------------------------------------------------------------
// Address: 0x1041BDB0
// Name: _dynamic_initializer_for__g_CPlayerSpeedFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CPlayerSpeedFoo__()
{
  CMaterialProxyDict *MaterialProxyDict; // eax

  MaterialProxyDict = GetMaterialProxyDict();
  return ((int (__thiscall *)(CMaterialProxyDict *, const char *, IMaterialProxy *(__cdecl *)()))MaterialProxyDict->Add)(
           a1: MaterialProxyDict,
           a2: "PlayerSpeed",
           a3: CCPlayerSpeedProxyFactory);
}

//------------------------------------------------------------------------------
// Address: 0x1041BDD0
// Name: _dynamic_initializer_for__g_CPlayerPositionFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CPlayerPositionFoo__()
{
  CMaterialProxyDict *MaterialProxyDict; // eax

  MaterialProxyDict = GetMaterialProxyDict();
  return ((int (__thiscall *)(CMaterialProxyDict *, const char *, IMaterialProxy *(__cdecl *)()))MaterialProxyDict->Add)(
           a1: MaterialProxyDict,
           a2: "PlayerPosition",
           a3: CCPlayerPositionProxyFactory);
}

//------------------------------------------------------------------------------
// Address: 0x1041BDF0
// Name: _dynamic_initializer_for__g_CEntitySpeedFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CEntitySpeedFoo__()
{
  CMaterialProxyDict *MaterialProxyDict; // eax

  MaterialProxyDict = GetMaterialProxyDict();
  return ((int (__thiscall *)(CMaterialProxyDict *, const char *, IMaterialProxy *(__cdecl *)()))MaterialProxyDict->Add)(
           a1: MaterialProxyDict,
           a2: "EntitySpeed",
           a3: CCEntitySpeedProxyFactory);
}

//------------------------------------------------------------------------------
// Address: 0x1041BE10
// Name: _dynamic_initializer_for__g_CEntityRandomFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CEntityRandomFoo__()
{
  CMaterialProxyDict *MaterialProxyDict; // eax

  MaterialProxyDict = GetMaterialProxyDict();
  return ((int (__thiscall *)(CMaterialProxyDict *, const char *, IMaterialProxy *(__cdecl *)()))MaterialProxyDict->Add)(
           a1: MaterialProxyDict,
           a2: "EntityRandom",
           a3: CCEntityRandomProxyFactory);
}

//------------------------------------------------------------------------------
// Address: 0x1041BE30
// Name: _dynamic_initializer_for__g_CPlayerLogoFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CPlayerLogoFoo__()
{
  CMaterialProxyDict *MaterialProxyDict; // eax

  MaterialProxyDict = GetMaterialProxyDict();
  return ((int (__thiscall *)(CMaterialProxyDict *, const char *, IMaterialProxy *(__cdecl *)()))MaterialProxyDict->Add)(
           a1: MaterialProxyDict,
           a2: "PlayerLogo",
           a3: CCPlayerLogoProxyFactory);
}

//------------------------------------------------------------------------------
// Address: 0x1041BE50
// Name: _dynamic_initializer_for__g_CPlayerLogoOnModelFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CPlayerLogoOnModelFoo__()
{
  CMaterialProxyDict *MaterialProxyDict; // eax

  MaterialProxyDict = GetMaterialProxyDict();
  return ((int (__thiscall *)(CMaterialProxyDict *, const char *, IMaterialProxy *(__cdecl *)()))MaterialProxyDict->Add)(
           a1: MaterialProxyDict,
           a2: "PlayerLogoOnModel",
           a3: CCPlayerLogoOnModelProxyFactory);
}

//------------------------------------------------------------------------------
// Address: 0x1041BE70
// Name: _dynamic_initializer_for__g_CPupilFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CPupilFoo__()
{
  CMaterialProxyDict *MaterialProxyDict; // eax

  MaterialProxyDict = GetMaterialProxyDict();
  return ((int (__thiscall *)(CMaterialProxyDict *, const char *, IMaterialProxy *(__cdecl *)()))MaterialProxyDict->Add)(
           a1: MaterialProxyDict,
           a2: "Pupil",
           a3: CCPupilProxyFactory);
}

//------------------------------------------------------------------------------
// Address: 0x10433740
// Name: _dynamic_atexit_destructor_for__cl_burninggibs__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_burninggibs__()
{
  ConVar::~ConVar(this: &cl_burninggibs);
}

//------------------------------------------------------------------------------
// Address: 0x10433750
// Name: _dynamic_atexit_destructor_for__g_PropDataSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_PropDataSystem__()
{
  CUtlVector<CParticleSystemMgr::RenderCache_t,CUtlMemory<CParticleSystemMgr::RenderCache_t,int>>::~CUtlVector<CParticleSystemMgr::RenderCache_t,CUtlMemory<CParticleSystemMgr::RenderCache_t,int>>(this: (CUtlVector<CParticleSystemMgr::RenderCache_t,CUtlMemory<CParticleSystemMgr::RenderCache_t,int> > *)&g_PropDataSystem.m_BreakableChunks);
  IGameSystem::~IGameSystem(this: &g_PropDataSystem);
}

//------------------------------------------------------------------------------
// Address: 0x10433770
// Name: _dynamic_atexit_destructor_for__cl_ragdoll_self_collision__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_ragdoll_self_collision__()
{
  ConVar::~ConVar(this: &cl_ragdoll_self_collision);
}
