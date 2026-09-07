// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_stickybolt.cpp
// Functions: 9
// ============================================================

#include "game\client\c_stickybolt.h"

//------------------------------------------------------------------------------
// Address: 0x102525D0
// Name: public: virtual void BoltImpactPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BoltImpactPrecache::CResourcePrecacher::Cache(
        BoltImpactPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MODEL,
    a3: "models/crossbow_bolt.mdl",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10252600
// Name: void CreateCrossbowBolt(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CreateCrossbowBolt(const Vector *vecOrigin, const Vector *vecDirection)
{
  const struct model_t *v2; // edi
  float v3; // xmm1_4
  float v4; // xmm2_4
  float v5; // xmm3_4
  float v6; // xmm3_4
  QAngle vAngles; // [esp+18h] [ebp-24h] BYREF
  float v8; // [esp+24h] [ebp-18h] BYREF
  float v9; // [esp+28h] [ebp-14h]
  float v10; // [esp+2Ch] [ebp-10h]
  float v11; // [esp+30h] [ebp-Ch] BYREF
  float v12; // [esp+34h] [ebp-8h]
  float v13; // [esp+38h] [ebp-4h]

  v2 = engine->LoadModel(this: engine, a2: "models/crossbow_bolt.mdl", a3: 0);
  VectorAngles(forward: vecDirection, angles: &vAngles);
  v3 = vecDirection->y * 8.0;
  v4 = vecDirection->z * 8.0;
  if ( *(int *)(gpGlobals.m_Index + 20) <= 1 )
  {
    v8 = 0.0;
    v9 = 0.0;
    v10 = 0.0;
    v6 = vecOrigin->x - (float)(vecDirection->x * 8.0);
    v12 = vecOrigin->y - v3;
    v13 = vecOrigin->z - v4;
    v11 = v6;
    ((void (__thiscall *)(ITempEnts *, const struct model_t *, float *, QAngle *, float *, int, int))tempents->SpawnTempModel)(
      a1: tempents,
      a2: v2,
      a3: &v11,
      a4: &vAngles,
      a5: &v8,
      a6: 1065353216,
      a7: 0x400000);
  }
  else
  {
    v11 = 0.0;
    v12 = 0.0;
    v13 = 0.0;
    v5 = vecOrigin->x - (float)(vecDirection->x * 8.0);
    v9 = vecOrigin->y - v3;
    v10 = vecOrigin->z - v4;
    v8 = v5;
    ((void (__thiscall *)(ITempEnts *, const struct model_t *, float *, QAngle *, float *, int, _DWORD))tempents->SpawnTempModel)(
      a1: tempents,
      a2: v2,
      a3: &v8,
      a4: &vAngles,
      a5: &v11,
      a6: 1106247680,
      a7: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10252740
// Name: void StickRagdollNow(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall StickRagdollNow(int a1@<ebp>, const Vector *vecOrigin, const Vector *vecDirection)
{
  float v3; // xmm2_4
  float v4; // xmm3_4
  float v5; // xmm0_4
  float x; // xmm4_4
  float y; // xmm5_4
  float z; // xmm6_4
  float v9; // xmm3_4
  float v10; // xmm0_4
  float v11; // edx
  int v12; // [esp-Ch] [ebp-134h] BYREF
  CGameTrace tr; // [esp+0h] [ebp-128h] BYREF
  _BYTE ragdollEnum_4[188]; // [esp+5Ch] [ebp-CCh] OVERLAPPED BYREF
  float v15; // [esp+118h] [ebp-10h]
  int v16; // [esp+11Ch] [ebp-Ch]
  void *v17; // [esp+120h] [ebp-8h]
  void *retaddr; // [esp+128h] [ebp+0h]

  v16 = a1;
  v17 = retaddr;
  v3 = vecDirection->z * 16.0;
  v4 = vecOrigin->x + (float)(vecDirection->x * 16.0);
  *(float *)&ragdollEnum_4[184] = vecOrigin->y + (float)(vecDirection->y * 16.0);
  v5 = vecOrigin->z + v3;
  *(_DWORD *)&ragdollEnum_4[160] = 0;
  *(float *)&ragdollEnum_4[180] = v4;
  v15 = v5;
  UTIL_TraceLine(
    vecAbsStart: vecOrigin,
    vecAbsEnd: (const Vector *)&ragdollEnum_4[180],
    mask: 0x400Bu,
    ignore: nullptr,
    collisionGroup: 0,
    ptr: (CGameTrace *)&v12);
  if ( (tr.allsolid & 4) == 0 )
  {
    x = vecOrigin->x;
    y = vecOrigin->y;
    z = vecOrigin->z;
    v9 = vecDirection->z * 128.0;
    v10 = (float)(vecOrigin->x - (float)(vecDirection->x * 128.0)) - vecOrigin->x;
    *(float *)&ragdollEnum_4[116] = (float)(y - (float)(vecDirection->y * 128.0)) - y;
    *(float *)&ragdollEnum_4[112] = v10;
    *(float *)&ragdollEnum_4[120] = (float)(z - v9) - z;
    v11 = vecOrigin->z;
    memset(&ragdollEnum_4[144], 0, 12);
    memset(&ragdollEnum_4[128], 0, 12);
    *(float *)&ragdollEnum_4[100] = y;
    *(_DWORD *)&ragdollEnum_4[64] = 0;
    ragdollEnum_4[165] = (float)((float)((float)(*(float *)&ragdollEnum_4[116] * *(float *)&ragdollEnum_4[116])
                                       + (float)(v10 * v10))
                               + (float)(*(float *)&ragdollEnum_4[120] * *(float *)&ragdollEnum_4[120])) != 0.0;
    *(_DWORD *)&ragdollEnum_4[160] = 0;
    *(float *)&ragdollEnum_4[104] = z;
    *(_QWORD *)&ragdollEnum_4[180] = *(_QWORD *)&vecOrigin->x;
    ragdollEnum_4[164] = 1;
    *(float *)&ragdollEnum_4[96] = x;
    tr.m_pEnt = (struct CBaseEntity *)&CRagdollBoltEnumerator::`vftable';
    qmemcpy(ragdollEnum_4, &ragdollEnum_4[96], 64);
    v15 = v11;
    *(_QWORD *)&ragdollEnum_4[80] = *(_QWORD *)&ragdollEnum_4[180];
    *(_DWORD *)&ragdollEnum_4[64] = 0;
    *(_WORD *)&ragdollEnum_4[68] = __PAIR16__(ragdollEnum_4[165], 1);
    *(float *)&ragdollEnum_4[88] = v11;
    partition->EnumerateElementsAlongRay(
      this: partition,
      a2: 8,
      a3: (const Ray_t *)&ragdollEnum_4[96],
      a4: false,
      a5: (IPartitionEnumerator *)&tr.m_pEnt);
    CreateCrossbowBolt(vecOrigin, vecDirection);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10252950
// Name: void StickyBoltCallback(class CEffectData const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl StickyBoltCallback(const CEffectData *data)
{
  int savedregs; // [esp+0h] [ebp+0h] BYREF

  StickRagdollNow(a1: (int)&savedregs, vecOrigin: &data->m_vOrigin, vecDirection: &data->m_vNormal);
}

//------------------------------------------------------------------------------
// Address: 0x10252970
// Name: public: virtual enum IterationRetval_t CRagdollBoltEnumerator::EnumElement(class IHandleEntity __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRagdollBoltEnumerator::EnumElement(CRagdollBoltEnumerator *this, IHandleEntity *pHandleEntity)
{
  const CBaseHandle *(__thiscall *GetRefEHandle)(IHandleEntity *); // edx
  CBaseHandle *v4; // eax
  C_BaseEntity *BaseEntityFromHandle; // edi
  C_BaseEntity_vtbl *v6; // ecx
  IPhysicsObject *v7; // esi
  IPhysicsObject *WorldPhysObject; // ebx
  double v9; // st7
  const Vector *(__thiscall *GetAbsOrigin)(IClientEntity *); // edx
  float attenuation; // [esp+34h] [ebp-100h]
  CGameTrace tr; // [esp+44h] [ebp-F0h] BYREF
  CPASAttenuationFilter filter; // [esp+98h] [ebp-9Ch] BYREF
  EmitSound_t ep; // [esp+B8h] [ebp-7Ch] BYREF
  constraint_ballsocketparams_t ballsocket; // [esp+100h] [ebp-34h] BYREF
  CRagdollBoltEnumerator *v17; // [esp+130h] [ebp-4h]

  GetRefEHandle = pHandleEntity->GetRefEHandle;
  v17 = this;
  v4 = GetRefEHandle(this: pHandleEntity);
  BaseEntityFromHandle = CClientEntityList::GetBaseEntityFromHandle(
                           this: (CClientEntityList *)cl_entitylist.m_Index,
                           hEnt: (CBaseHandle)v4->m_Index);
  if ( BaseEntityFromHandle == nullptr )
    return 0;
  enginetrace->ClipRayToEntity(
    this: enginetrace,
    a2: &this->m_rayShot,
    a3: 1174421507u,
    a4: BaseEntityFromHandle,
    a5: &tr);
  if ( tr.physicsbone < 0 )
    return 0;
  v6 = BaseEntityFromHandle[1].IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v6 == nullptr )
    return 0;
  if ( tr.physicsbone >= (int)v6->SetRefEHandle )
    return 0;
  v7 = *((IPhysicsObject **)&v6->GetBaseEntity + 6 * tr.physicsbone);
  if ( v7 == nullptr )
    return 0;
  if ( tr.fraction >= 1.0 )
    return 0;
  WorldPhysObject = GetWorldPhysObject();
  if ( WorldPhysObject == nullptr )
    return 0;
  v9 = ((double (__thiscall *)(IPhysicsObject *))v7->GetMass)(a1: v7);
  attenuation = v9 + v9;
  ((void (__thiscall *)(IPhysicsObject *, _DWORD))v7->SetMass)(a1: v7, a2: LODWORD(attenuation));
  ballsocket.constraint.forceLimit = 0.0;
  ballsocket.constraint.torqueLimit = 0.0;
  ballsocket.constraint.strength = 1.0;
  ballsocket.constraint.bodyMassScale[0] = 1.0;
  ballsocket.constraint.bodyMassScale[1] = 1.0;
  ballsocket.constraint.isActive = true;
  memset((void *)&ballsocket, 0, 24);
  WorldPhysObject->WorldToLocal(this: WorldPhysObject, a2: ballsocket.constraintPosition, a3: &v17->m_vWorld);
  v7->WorldToLocal(this: v7, a2: &ballsocket.constraintPosition[1], a3: &tr.endpos);
  physenv->CreateBallsocketConstraint(this: physenv, a2: WorldPhysObject, a3: v7, a4: nullptr, a5: &ballsocket);
  CPASAttenuationFilter::CPASAttenuationFilter(this: &filter, entity: BaseEntityFromHandle, attenuation: 0.80000001);
  EmitSound_t::EmitSound_t(this: &ep);
  GetAbsOrigin = BaseEntityFromHandle->GetAbsOrigin;
  ep.m_nChannel = 2;
  ep.m_pSoundName = "Weapon_Crossbow.BoltSkewer";
  ep.m_flVolume = 1.0;
  ep.m_SoundLevel = SNDLVL_NORM;
  ep.m_pOrigin = GetAbsOrigin(this: BaseEntityFromHandle);
  C_BaseEntity::EmitSound(&filter, iEntIndex: 0, params: &ep);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&ep.m_UtlVecSoundOrigin);
  C_RecipientFilter::~C_RecipientFilter(this: &filter);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1042AF10
// Name: BoltImpactPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int BoltImpactPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106EF254;
  BoltImpactPrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106EF254;
  dword_106EF254 = (int)&BoltImpactPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042AF30
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
// Address: 0x1042AF50
// Name: _dynamic_initializer_for____g_C_TEMetalSparks__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____g_C_TEMetalSparks__()
{
  C_BaseTempEntity::C_BaseTempEntity(this: &_g_C_TEMetalSparks);
  _g_C_TEMetalSparks.C_BaseTempEntity::IClientUnknown::IHandleEntity::__vftable = (C_TEMetalSparks_vtbl *)&C_TEMetalSparks::`vftable'{for `IClientUnknown'};
  _g_C_TEMetalSparks.C_BaseTempEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_TEMetalSparks::`vftable'{for `IClientNetworkable'};
  _g_C_TEMetalSparks.m_vecPos.x = 0.0;
  _g_C_TEMetalSparks.m_vecPos.y = 0.0;
  _g_C_TEMetalSparks.m_vecPos.z = 0.0;
  _g_C_TEMetalSparks.m_vecDir.x = 0.0;
  _g_C_TEMetalSparks.m_vecDir.y = 0.0;
  _g_C_TEMetalSparks.m_vecDir.z = 0.0;
  _g_C_TEMetalSparks.m_pModel = nullptr;
  return atexit(func: dynamic_atexit_destructor_for____g_C_TEMetalSparks__);
}

//------------------------------------------------------------------------------
// Address: 0x1042AFC0
// Name: _dynamic_initializer_for____g_C_TEMetalSparksClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_TEMetalSparksClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_TEMetalSparksClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_TEMetalSparksClientClass;
  return result;
}
