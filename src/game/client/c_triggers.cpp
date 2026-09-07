// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_triggers.cpp
// Functions: 29
// ============================================================

#include "game\client\c_triggers.h"

//------------------------------------------------------------------------------
// Address: 0x10071250
// Name: public: virtual void C_EntityClassList<class C_FuncReflectiveGlass>::LevelShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_EntityClassList<C_FuncReflectiveGlass>::LevelShutdown(C_EntityClassList<C_FuncReflectiveGlass> *this)
{
  C_EntityClassList<C_FuncReflectiveGlass>::m_pClassList = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1007ED60
// Name: public: virtual void C_EntityClassList<class C_PointCamera>::LevelShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_EntityClassList<C_PointCamera>::LevelShutdown(C_EntityClassList<C_PointCamera> *this)
{
  C_EntityClassList<C_PointCamera>::m_pClassList = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10092FC0
// Name: private: virtual class ClientClass __near * C_BaseTrigger::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_BaseTrigger::GetClientClass(C_BaseTrigger *this)
{
  return &__g_C_BaseTriggerClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10093090
// Name: public: virtual class ClientClass __near * C_TriggerPlayerMovement::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_TriggerPlayerMovement::GetClientClass(C_TriggerPlayerMovement *this)
{
  return &__g_C_TriggerPlayerMovementClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10093110
// Name: private: virtual class ClientClass __near * C_BaseVPhysicsTrigger::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_BaseVPhysicsTrigger::GetClientClass(C_BaseVPhysicsTrigger *this)
{
  return &__g_C_BaseVPhysicsTriggerClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10093190
// Name: public: virtual void C_EntityClassList<class C_TriggerPlayerMovement>::LevelShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_EntityClassList<C_TriggerPlayerMovement>::LevelShutdown(
        C_EntityClassList<C_TriggerPlayerMovement> *this)
{
  C_EntityClassList<C_TriggerPlayerMovement>::m_pClassList = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100931A0
// Name: public: virtual C_TriggerPlayerMovement::~C_TriggerPlayerMovement(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TriggerPlayerMovement::~C_TriggerPlayerMovement(C_TriggerPlayerMovement *this)
{
  C_TriggerPlayerMovement *v1; // eax
  C_TriggerPlayerMovement **p_m_pNext; // edx

  this->C_BaseTrigger::C_BaseToggle::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_TriggerPlayerMovement_vtbl *)&C_TriggerPlayerMovement::`vftable'{for `IClientUnknown'};
  this->C_BaseTrigger::C_BaseToggle::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_TriggerPlayerMovement::`vftable'{for `IClientRenderable'};
  this->C_BaseTrigger::C_BaseToggle::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TriggerPlayerMovement::`vftable'{for `IClientNetworkable'};
  this->C_BaseTrigger::C_BaseToggle::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_TriggerPlayerMovement::`vftable'{for `IClientThinkable'};
  this->C_BaseTrigger::C_BaseToggle::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_TriggerPlayerMovement::`vftable';
  v1 = C_EntityClassList<C_TriggerPlayerMovement>::m_pClassList;
  p_m_pNext = &C_EntityClassList<C_TriggerPlayerMovement>::m_pClassList;
  if ( C_EntityClassList<C_TriggerPlayerMovement>::m_pClassList != nullptr )
  {
    while ( v1 != this )
    {
      p_m_pNext = &v1->m_pNext;
      v1 = v1->m_pNext;
      if ( v1 == nullptr )
        goto LABEL_4;
    }
    *p_m_pNext = v1->m_pNext;
  }
LABEL_4:
  C_BaseEntity::~C_BaseEntity(this);
}

//------------------------------------------------------------------------------
// Address: 0x10093200
// Name: protected: virtual void C_TriggerPlayerMovement::UpdatePartitionListEntry(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TriggerPlayerMovement::UpdatePartitionListEntry(C_TriggerPlayerMovement *this)
{
  if ( this->m_bClientSidePredicted )
    partition->RemoveAndInsert(this: partition, a2: 140, a3: 256, a4: this->m_Collision.m_Partition);
  else
    C_BaseEntity::UpdatePartitionListEntry(this);
}

//------------------------------------------------------------------------------
// Address: 0x10093230
// Name: public: virtual void C_TriggerPlayerMovement::StartTouch(class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TriggerPlayerMovement::StartTouch(C_TriggerPlayerMovement *this, C_BasePlayer *pOther)
{
  if ( pOther != nullptr && pOther->IsPlayer(this: pOther) )
  {
    if ( (this->m_spawnflags & 0x800) != 0 )
      C_BasePlayer::ForceButtons(this: pOther, nButtons: 4);
    if ( (this->m_spawnflags & 0x1000) != 0 )
      C_BasePlayer::ForceButtons(this: pOther, nButtons: 0x20000);
    if ( (this->m_spawnflags & 0x80) != 0 )
      pOther->m_Local.m_bAllowAutoMovement = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100932A0
// Name: public: virtual void C_TriggerPlayerMovement::EndTouch(class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_TriggerPlayerMovement::EndTouch(C_TriggerPlayerMovement *this, C_BasePlayer *pOther)
{
  if ( pOther != nullptr && pOther->IsPlayer(this: pOther) )
  {
    if ( (this->m_spawnflags & 0x800) != 0 )
      C_BasePlayer::UnforceButtons(this: pOther, nButtons: 4);
    if ( (this->m_spawnflags & 0x1000) != 0 )
      C_BasePlayer::UnforceButtons(this: pOther, nButtons: 0x20000);
    if ( (this->m_spawnflags & 0x80) != 0 )
      pOther->m_Local.m_bAllowAutoMovement = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100934A0
// Name: public: CFastTouchTriggers<class C_TriggerPlayerMovement>::CFastTouchTriggers<class C_TriggerPlayerMovement>(class C_BaseEntity __near *,class C_TriggerPlayerMovement __near *)
// Source: json
//------------------------------------------------------------------------------
CFastTouchTriggers<C_TriggerPlayerMovement> *__thiscall CFastTouchTriggers<C_TriggerPlayerMovement>::CFastTouchTriggers<C_TriggerPlayerMovement>(
        CFastTouchTriggers<C_TriggerPlayerMovement> *this,
        C_BaseEntity *pEnt,
        C_TriggerPlayerMovement *pTriggers)
{
  ICollideable *v4; // eax
  unsigned int v5; // eax
  ICollideable *m_pCollide; // edi
  int v7; // eax
  ICollideable_vtbl *v8; // edx
  float *v9; // eax
  float v10; // xmm0_4
  float *v11; // ebx
  ICollideable *v12; // ecx
  const Vector *v13; // eax
  Vector vecMins; // [esp+8h] [ebp-18h] BYREF
  Vector vecMaxs; // [esp+14h] [ebp-Ch] BYREF

  this->m_pTriggers = pTriggers;
  this->m_Ray.m_pWorldAxisTransform = nullptr;
  this->m_pEnt = pEnt;
  v4 = pEnt->GetCollideable(this: pEnt);
  this->m_pCollide = v4;
  v5 = v4->GetRequiredTriggerFlags(this: v4);
  m_pCollide = this->m_pCollide;
  this->m_nRequiredTriggerFlags = v5;
  v7 = m_pCollide->GetSolid(this: m_pCollide);
  v8 = m_pCollide->__vftable;
  if ( v7 == 2 )
  {
    vecMins = *v8->OBBMins(this: m_pCollide);
    v9 = (float *)m_pCollide->OBBMaxs(this: m_pCollide);
    vecMaxs.x = *v9;
    vecMaxs.y = v9[1];
    v10 = v9[2];
  }
  else
  {
    v11 = (float *)v8->GetCollisionOrigin(this: m_pCollide);
    m_pCollide->WorldSpaceSurroundingBounds(this: m_pCollide, a2: &vecMins, a3: &vecMaxs);
    vecMins.x = vecMins.x - *v11;
    vecMins.y = vecMins.y - v11[1];
    vecMins.z = vecMins.z - v11[2];
    vecMaxs.x = vecMaxs.x - *v11;
    vecMaxs.y = vecMaxs.y - v11[1];
    v10 = vecMaxs.z - v11[2];
  }
  v12 = this->m_pCollide;
  vecMaxs.z = v10;
  v13 = v12->GetCollisionOrigin(this: v12);
  Ray_t::Init(this: &this->m_Ray, start: v13, end: v13, mins: &vecMins, maxs: &vecMaxs);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100935D0
// Name: void TouchTriggerPlayerMovement(class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall TouchTriggerPlayerMovement(int a1@<ebp>, C_BaseEntity *pEntity)
{
  C_BaseEntity *i; // esi
  ICollideable *v3; // edi
  int v4; // eax
  bool v5; // zf
  float *v6; // edi
  float *v7; // eax
  float v8; // xmm1_4
  float v9; // xmm2_4
  _DWORD v10[22]; // [esp-BCh] [ebp-16Ch] BYREF
  CGameTrace v11; // [esp-64h] [ebp-114h] BYREF
  _BYTE v12[12]; // [esp-Ch] [ebp-BCh] BYREF
  _BYTE helper_68[32]; // [esp+44h] [ebp-6Ch] OVERLAPPED BYREF
  __m128 v14; // [esp+64h] [ebp-4Ch] BYREF
  __m128 v15; // [esp+74h] [ebp-3Ch] BYREF
  __m128 v16; // [esp+84h] [ebp-2Ch] BYREF
  __m128 v17; // [esp+94h] [ebp-1Ch] BYREF
  _DWORD v18[3]; // [esp+A4h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+B0h] [ebp+0h]

  v18[0] = a1;
  v18[1] = retaddr;
  CFastTouchTriggers<C_TriggerPlayerMovement>::CFastTouchTriggers<C_TriggerPlayerMovement>(
    this: (CFastTouchTriggers<C_TriggerPlayerMovement> *)v12,
    pEnt: pEntity,
    pTriggers: C_EntityClassList<C_TriggerPlayerMovement>::m_pClassList);
  for ( i = *(C_BaseEntity **)&helper_68[12];
        i != nullptr;
        i = (C_BaseEntity *)LODWORD(i[1].m_VarMap.m_lastInterpolationTime) )
  {
    if ( !i->IsDormant(this: &i->IClientNetworkable) )
    {
      v3 = i->GetCollideable(this: i);
      v4 = v3->GetSolidFlags(this: v3);
      if ( *(_DWORD *)&helper_68[8] == 0 || (*(_DWORD *)&helper_68[8] & v4) != *(_DWORD *)&helper_68[8] )
      {
        if ( (v4 & 0x80u) == 0 )
        {
          enginetrace->ClipRayToCollideable(
            this: enginetrace,
            a2: (const Ray_t *)v12,
            a3: 33570827u,
            a4: v3,
            a5: (CGameTrace *)v10);
          v5 = (v10[12] & 0x200400B) == 0;
        }
        else
        {
          v3->WorldSpaceTriggerBounds(this: v3, a2: (Vector *)&v15, a3: (Vector *)&helper_68[16]);
          v14 = Four_Zeros;
          v17 = *(__m128 *)&helper_68[16];
          v16 = v15;
          v5 = !IsBoxIntersectingRay(
                  boxMin: &v16,
                  boxMax: &v17,
                  a3: (int)v18,
                  ray: (const Ray_t *)v12,
                  fl4Tolerance: &v14);
        }
        if ( !v5 )
        {
          UTIL_ClearTrace(trace: &v11);
          v6 = (float *)i->GetAbsOrigin(this: i);
          v7 = (float *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)helper_68 + 40))(a1: *(_DWORD *)helper_68);
          v8 = (float)(v6[1] + v7[1]) * 0.5;
          v9 = (float)(v6[2] + v7[2]) * 0.5;
          v11.endpos.x = (float)(*v6 + *v7) * 0.5;
          v11.endpos.y = v8;
          v11.endpos.z = v9;
          C_BaseEntity::PhysicsMarkEntitiesAsTouching(this: *(C_BaseEntity **)helper_68, other: i, trace: &v11);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10413DC0
// Name: DT_BaseTrigger::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseTrigger::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_BaseTrigger::g_RecvTable);
  return atexit(func: DT_BaseTrigger::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10413DE0
// Name: DT_BaseTrigger::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseTrigger::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_BaseTrigger::ignored>();
  DT_BaseTrigger::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10413E10
// Name: DT_TriggerPlayerMovement::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TriggerPlayerMovement::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_TriggerPlayerMovement::g_RecvTable);
  return atexit(func: DT_TriggerPlayerMovement::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10413E30
// Name: DT_TriggerPlayerMovement::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TriggerPlayerMovement::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_TriggerPlayerMovement::ignored>();
  DT_TriggerPlayerMovement::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10413E80
// Name: DT_BaseVPhysicsTrigger::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseVPhysicsTrigger::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_BaseVPhysicsTrigger::g_RecvTable);
  return atexit(func: DT_BaseVPhysicsTrigger::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10413EA0
// Name: DT_BaseVPhysicsTrigger::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseVPhysicsTrigger::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_BaseVPhysicsTrigger::ignored>();
  DT_BaseVPhysicsTrigger::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430CB0
// Name: DT_BaseTrigger::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_BaseTrigger::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_BaseTrigger::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10430CC0
// Name: DT_TriggerPlayerMovement::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TriggerPlayerMovement::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_TriggerPlayerMovement::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10430CD0
// Name: DT_BaseVPhysicsTrigger::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_BaseVPhysicsTrigger::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_BaseVPhysicsTrigger::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10093310
// Name: _C_BaseVPhysicsTrigger_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_BaseVPhysicsTrigger_CreateObject(int entnum, int serialNum)
{
  C_BaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_BaseEntity *)C_BaseEntity::operator new(stAllocateBlock: 0x988u);
  v3 = &v2->IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_BaseEntity::C_BaseEntity(this: v2);
  *v3 = &C_BaseVPhysicsTrigger::`vftable'{for `IClientUnknown'};
  v3[1] = &C_BaseVPhysicsTrigger::`vftable'{for `IClientRenderable'};
  v3[2] = &C_BaseVPhysicsTrigger::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_BaseVPhysicsTrigger::`vftable'{for `IClientThinkable'};
  v3[4] = &C_BaseVPhysicsTrigger::`vftable';
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x10093380
// Name: _C_BaseTrigger_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_BaseTrigger_CreateObject(int entnum, int serialNum)
{
  C_BaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_BaseEntity *)C_BaseEntity::operator new(stAllocateBlock: 0x9B8u);
  v3 = &v2->IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_BaseEntity::C_BaseEntity(this: v2);
  v3[608] = -1;
  *v3 = &C_BaseTrigger::`vftable'{for `IClientUnknown'};
  v3[1] = &C_BaseTrigger::`vftable'{for `IClientRenderable'};
  v3[2] = &C_BaseTrigger::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_BaseTrigger::`vftable'{for `IClientThinkable'};
  v3[4] = &C_BaseTrigger::`vftable';
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x100933F0
// Name: _C_TriggerPlayerMovement_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_TriggerPlayerMovement_CreateObject(int entnum, int serialNum)
{
  C_BaseEntity *v2; // eax
  C_TriggerPlayerMovement *v3; // esi

  v2 = (C_BaseEntity *)C_BaseEntity::operator new(stAllocateBlock: 0x9C0u);
  v3 = (C_TriggerPlayerMovement *)v2;
  if ( v2 == nullptr )
    return nullptr;
  C_BaseEntity::C_BaseEntity(this: v2);
  v3->m_hPredictionOwner.m_Index = -1;
  v3->C_BaseTrigger::C_BaseToggle::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_TriggerPlayerMovement_vtbl *)&C_TriggerPlayerMovement::`vftable'{for `IClientUnknown'};
  v3->C_BaseTrigger::C_BaseToggle::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_TriggerPlayerMovement::`vftable'{for `IClientRenderable'};
  v3->C_BaseTrigger::C_BaseToggle::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TriggerPlayerMovement::`vftable'{for `IClientNetworkable'};
  v3->C_BaseTrigger::C_BaseToggle::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_TriggerPlayerMovement::`vftable'{for `IClientThinkable'};
  v3->C_BaseTrigger::C_BaseToggle::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_TriggerPlayerMovement::`vftable';
  v3->m_pNext = C_EntityClassList<C_TriggerPlayerMovement>::m_pClassList;
  C_EntityClassList<C_TriggerPlayerMovement>::m_pClassList = v3;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v3->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x10413DF0
// Name: _dynamic_initializer_for____g_C_TriggerPlayerMovementClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_TriggerPlayerMovementClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_TriggerPlayerMovementClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_TriggerPlayerMovementClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10413E40
// Name: _dynamic_initializer_for__g_TriggerPlayerMovementList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TriggerPlayerMovementList__()
{
  C_BaseEntityClassList::C_BaseEntityClassList(this: &g_TriggerPlayerMovementList);
  g_TriggerPlayerMovementList.__vftable = (C_EntityClassList<C_TriggerPlayerMovement>_vtbl *)&C_EntityClassList<C_TriggerPlayerMovement>::`vftable';
  return atexit(func: dynamic_atexit_destructor_for__g_TriggerPlayerMovementList__);
}

//------------------------------------------------------------------------------
// Address: 0x10413E60
// Name: _dynamic_initializer_for____g_C_BaseVPhysicsTriggerClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_BaseVPhysicsTriggerClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_BaseVPhysicsTriggerClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_BaseVPhysicsTriggerClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10413EB0
// Name: _dynamic_initializer_for____g_C_PropVehicleChoreoGenericClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_PropVehicleChoreoGenericClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_PropVehicleChoreoGenericClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_PropVehicleChoreoGenericClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430CE0
// Name: _dynamic_atexit_destructor_for__g_TriggerPlayerMovementList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_TriggerPlayerMovementList__()
{
  C_BaseEntityClassList::~C_BaseEntityClassList(this: &g_TriggerPlayerMovementList);
}
