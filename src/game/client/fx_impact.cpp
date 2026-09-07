// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/fx_impact.cpp
// Functions: 15
// ============================================================

#include "game\client\fx_impact.h"

//------------------------------------------------------------------------------
// Address: 0x100DCBE0
// Name: char const __near * GetImpactDecal(class C_BaseEntity __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl GetImpactDecal(C_BaseEntity *pEntity, int iMaterial, int iDamageType)
{
  const char *v4; // eax

  if ( pEntity == nullptr )
    return decalsystem->TranslateDecalForGameMaterial(this: decalsystem, a2: "Impact.Concrete", a3: iMaterial);
  v4 = pEntity->DamageDecal(this: pEntity, a2: iDamageType, a3: iMaterial);
  return decalsystem->TranslateDecalForGameMaterial(this: decalsystem, a2: v4, a3: iMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x100DCC30
// Name: public: virtual void PrecacheImpactsPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PrecacheImpactsPrecache::CResourcePrecacher::Cache(
        PrecacheImpactsPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  unsigned int i; // edi
  const char *m_pName; // eax
  const char *m_pNameNoFlecks; // eax
  unsigned int j; // edi
  const char *v9; // eax
  const char *v10; // eax

  for ( i = 0; i < 26; ++i )
  {
    m_pName = s_pImpactEffect[i].m_pName;
    if ( m_pName != nullptr )
      pPrecacheHandler->CacheResource(
        this: pPrecacheHandler,
        a2: PARTICLE_SYSTEM,
        a3: m_pName,
        a4: bPrecache,
        a5: hResourceList,
        a6: s_pImpactEffectIndex[i]);
    m_pNameNoFlecks = s_pImpactEffect[i].m_pNameNoFlecks;
    if ( m_pNameNoFlecks != nullptr )
      pPrecacheHandler->CacheResource(
        this: pPrecacheHandler,
        a2: PARTICLE_SYSTEM,
        a3: m_pNameNoFlecks,
        a4: bPrecache,
        a5: hResourceList,
        a6: &s_pImpactEffectIndex[i][1]);
  }
  for ( j = 0; j < 11; ++j )
  {
    v9 = s_pImpactEffect2[j].m_pName;
    if ( v9 != nullptr )
      pPrecacheHandler->CacheResource(
        this: pPrecacheHandler,
        a2: PARTICLE_SYSTEM,
        a3: v9,
        a4: bPrecache,
        a5: hResourceList,
        a6: s_pImpactEffect2Index[j]);
    v10 = s_pImpactEffect2[j].m_pNameNoFlecks;
    if ( v10 != nullptr )
      pPrecacheHandler->CacheResource(
        this: pPrecacheHandler,
        a2: PARTICLE_SYSTEM,
        a3: v10,
        a4: bPrecache,
        a5: hResourceList,
        a6: &s_pImpactEffect2Index[j][1]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DCCF0
// Name: void SetImpactSoundRoute(void (*)(char const __near *,class Vector const __near &))
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetImpactSoundRoute(void (__cdecl *fn)(const char *, const Vector *))
{
  g_pImpactSoundRouteFn = fn;
}

//------------------------------------------------------------------------------
// Address: 0x100DCD00
// Name: void PlayImpactSound(class C_BaseEntity __near *,class CGameTrace __near &,class Vector __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PlayImpactSound(C_BaseEntity *pEntity, CGameTrace *tr, Vector *vecServerOrigin, int nServerSurfaceProp)
{
  int surfaceProps; // eax
  surfacedata_t *v5; // edi
  float z; // xmm0_4
  const char *v7; // esi
  IUniformRandomStream *v8; // ecx
  int v9; // xmm1_4
  CLocalPlayerFilter filter; // [esp+18h] [ebp-2Ch] BYREF
  Vector vecOrigin; // [esp+38h] [ebp-Ch] BYREF
  float flRicoChance; // [esp+50h] [ebp+Ch]

  if ( tr->fraction < 1.0 || tr->allsolid || tr->startsolid )
  {
    if ( pEntity != (C_BaseEntity *)tr->m_pEnt || (surfaceProps = nServerSurfaceProp, nServerSurfaceProp == 0) )
      surfaceProps = tr->surface.surfaceProps;
  }
  else
  {
    surfaceProps = nServerSurfaceProp;
  }
  v5 = physprops->GetSurfaceData(this: physprops, a2: surfaceProps);
  if ( tr->fraction >= 1.0 )
  {
    vecOrigin.x = vecServerOrigin->x;
    vecOrigin.y = vecServerOrigin->y;
    z = vecServerOrigin->z;
  }
  else
  {
    vecOrigin.x = tr->endpos.x;
    vecOrigin.y = tr->endpos.y;
    z = tr->endpos.z;
  }
  vecOrigin.z = z;
  if ( v5->sounds.bulletImpact != 0 )
  {
    v7 = physprops->GetString(this: physprops, a2: v5->sounds.bulletImpact);
    if ( g_pImpactSoundRouteFn != nullptr )
    {
      g_pImpactSoundRouteFn(a1: v7, a2: &vecOrigin);
    }
    else
    {
      CLocalPlayerFilter::CLocalPlayerFilter(this: &filter);
      C_BaseEntity::EmitSound(
        &filter,
        iEntIndex: 0,
        soundname: v7,
        handle: &v5->soundhandles.bulletImpact,
        pOrigin: &vecOrigin,
        soundtime: 0.0,
        duration: nullptr);
      C_RecipientFilter::~C_RecipientFilter(this: &filter);
    }
    flRicoChance = 0.0;
    switch ( v5->game.material )
    {
      case 1u:
      case 2u:
      case 0x44u:
      case 0x4Cu:
        *(float *)&v9 = 1.0;
        goto LABEL_19;
      case 3u:
      case 0x43u:
      case 0x4Du:
      case 0x50u:
      case 0x51u:
      case 0x52u:
      case 0x54u:
        *(float *)&v9 = 5.0;
        goto LABEL_19;
      case 4u:
      case 5u:
      case 7u:
      case 0x47u:
      case 0x56u:
      case 0x57u:
        *(float *)&v9 = 3.0;
LABEL_19:
        flRicoChance = *(float *)&v9;
        break;
      default:
        break;
    }
    if ( (double)flRicoChance >= _RandomFloat(this: v8, a2: 0.0, a3: 10.0) )
      FX_RicochetSound(pos: &vecOrigin);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DCEE0
// Name: class C_BaseEntity __near * ParseImpactData(class CEffectData const __near &,class Vector __near *,class Vector __near *,class Vector __near *,short __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__cdecl ParseImpactData(
        const CEffectData *data,
        Vector *vecOrigin,
        Vector *vecStart,
        Vector *vecShotDir,
        __int16 *nSurfaceProp,
        int *iMaterial,
        int *iDamageType,
        int *iHitbox)
{
  C_BaseEntity *Entity; // edi
  float v9; // xmm1_4
  float v10; // xmm2_4

  Entity = CEffectData::GetEntity(this: data);
  *vecOrigin = data->m_vOrigin;
  *vecStart = data->m_vStart;
  *nSurfaceProp = data->m_nSurfaceProp;
  *iDamageType = data->m_nDamageType;
  *iHitbox = data->m_nHitBox;
  v9 = vecOrigin->y - vecStart->y;
  v10 = vecOrigin->z - vecStart->z;
  vecShotDir->x = vecOrigin->x - vecStart->x;
  vecShotDir->y = v9;
  vecShotDir->z = v10;
  VectorNormalize(vec: vecShotDir);
  *iMaterial = *(unsigned __int16 *)(((int (__stdcall *)(_DWORD))physprops->GetSurfaceData)(a1: data->m_nSurfaceProp)
                                   + 76);
  return Entity;
}

//------------------------------------------------------------------------------
// Address: 0x100DCF90
// Name: public: virtual enum IterationRetval_t CRagdollEnumerator::EnumElement(class IHandleEntity __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRagdollEnumerator::EnumElement(CRagdollEnumerator *this, IHandleEntity *pHandleEntity)
{
  CBaseHandle *v3; // eax
  C_BaseEntity *BaseEntityFromHandle; // eax
  IHandleEntity *v5; // esi
  CGameTrace tr; // [esp+8h] [ebp-54h] BYREF

  v3 = pHandleEntity->GetRefEHandle(this: pHandleEntity);
  BaseEntityFromHandle = CClientEntityList::GetBaseEntityFromHandle(
                           this: (CClientEntityList *)cl_entitylist.m_Index,
                           hEnt: (CBaseHandle)v3->m_Index);
  v5 = BaseEntityFromHandle;
  if ( BaseEntityFromHandle == nullptr )
    return 0;
  if ( WasRagdollCreatedOnCurrentTick(pRagdoll: BaseEntityFromHandle) != 0 )
    return 0;
  if ( v5[165].__vftable == nullptr )
    return 0;
  enginetrace->ClipRayToEntity(this: enginetrace, a2: &this->m_rayShot, a3: 1174421507u, a4: v5, a5: &tr);
  if ( tr.fraction >= 1.0 )
    return 0;
  ((void (__thiscall *)(IHandleEntity *, CGameTrace *, int, _DWORD))v5->__vftable[43].SetRefEHandle)(
    a1: v5,
    a2: &tr,
    a3: this->m_iDamageType,
    a4: 0);
  this->m_bHit = true;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100DD030
// Name: SetImpactControlPoint
// Source: json
//------------------------------------------------------------------------------
void __usercall SetImpactControlPoint(
        CNewParticleEffect *pEffect@<edi>,
        int nPoint@<esi>,
        const Vector *vecImpactPoint,
        const Vector *vecForward,
        C_BaseEntity *pEntity)
{
  Vector vecImpactZ; // [esp+4h] [ebp-18h] BYREF
  Vector vecImpactY; // [esp+10h] [ebp-Ch] BYREF

  VectorVectors(forward: vecForward, right: &vecImpactY, up: &vecImpactZ);
  vecImpactY.x = vecImpactY.x * -1.0;
  vecImpactY.y = vecImpactY.y * -1.0;
  vecImpactY.z = vecImpactY.z * -1.0;
  CNewParticleEffect::SetControlPoint(this: pEffect, nWhichPoint: nPoint, v: vecImpactPoint);
  if ( r_impacts_alt_orientation.m_pParent != nullptr && r_impacts_alt_orientation.m_pParent->m_Value.m_nValue != 0 )
    CNewParticleEffect::SetControlPointOrientation(
      this: pEffect,
      nWhichPoint: nPoint,
      forward: &vecImpactZ,
      right: &vecImpactY,
      up: vecForward);
  else
    CNewParticleEffect::SetControlPointOrientation(
      this: pEffect,
      nWhichPoint: nPoint,
      forward: vecForward,
      right: &vecImpactY,
      up: &vecImpactZ);
  CNewParticleEffect::SetControlPointEntity(this: pEffect, nWhichPoint: nPoint, pEntity);
}

//------------------------------------------------------------------------------
// Address: 0x100DD0D0
// Name: bool FX_AffectRagdolls(class Vector,class Vector,int)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
bool __usercall FX_AffectRagdolls@<al>(int a1@<ebp>, Vector vecOrigin, Vector vecStart, int iDamageType)
{
  void **v5; // [esp-Ch] [ebp-CCh] BYREF
  _BYTE ragdollEnum_4[184]; // [esp+4h] [ebp-BCh] OVERLAPPED BYREF
  _UNKNOWN *retaddr; // [esp+C0h] [ebp+0h]

  *(_DWORD *)&ragdollEnum_4[176] = a1;
  *(_DWORD *)&ragdollEnum_4[180] = retaddr;
  if ( s_RagdollLRU.m_iSimulatedRagdollCount > 1 )
    return false;
  *(float *)&ragdollEnum_4[116] = vecOrigin.y - vecStart.y;
  *(float *)&ragdollEnum_4[112] = vecOrigin.x - vecStart.x;
  *(float *)&ragdollEnum_4[120] = vecOrigin.z - vecStart.z;
  ragdollEnum_4[165] = (float)((float)((float)(*(float *)&ragdollEnum_4[116] * *(float *)&ragdollEnum_4[116])
                                     + (float)(*(float *)&ragdollEnum_4[112] * *(float *)&ragdollEnum_4[112]))
                             + (float)(*(float *)&ragdollEnum_4[120] * *(float *)&ragdollEnum_4[120])) != 0.0;
  *(_DWORD *)&ragdollEnum_4[160] = 0;
  ragdollEnum_4[164] = 1;
  memset(&ragdollEnum_4[144], 0, 12);
  memset(&ragdollEnum_4[128], 0, 12);
  *(Vector *)&ragdollEnum_4[96] = vecStart;
  v5 = &CRagdollEnumerator::`vftable';
  qmemcpy(ragdollEnum_4, &ragdollEnum_4[96], 64);
  *(_DWORD *)&ragdollEnum_4[64] = 0;
  *(_WORD *)&ragdollEnum_4[68] = __PAIR16__(ragdollEnum_4[165], 1);
  ragdollEnum_4[84] = 0;
  *(_DWORD *)&ragdollEnum_4[80] = iDamageType;
  partition->EnumerateElementsAlongRay(
    this: partition,
    a2: 8,
    a3: (const Ray_t *)&ragdollEnum_4[96],
    a4: false,
    a5: (IPartitionEnumerator *)&v5);
  return ragdollEnum_4[84];
}

//------------------------------------------------------------------------------
// Address: 0x100DD210
// Name: void RagdollImpactCallback(class CEffectData const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RagdollImpactCallback(const CEffectData *data)
{
  int savedregs; // [esp+0h] [ebp+0h] BYREF

  FX_AffectRagdolls(
    a1: (int)&savedregs,
    vecOrigin: data->m_vOrigin,
    vecStart: data->m_vStart,
    iDamageType: data->m_nDamageType);
}

//------------------------------------------------------------------------------
// Address: 0x100DD250
// Name: bool Impact(class Vector __near &,class Vector __near &,int,int,int,class C_BaseEntity __near *,class CGameTrace __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
char __usercall Impact@<al>(
        int a1@<ebp>,
        int a2@<edi>,
        int a3@<esi>,
        Vector *vecOrigin,
        Vector *vecStart,
        int iMaterial,
        int iDamageType,
        int iHitbox,
        C_BaseEntity *pEntity,
        CGameTrace *tr,
        char nFlags,
        int maxLODToDecal)
{
  double v12; // st7
  C_BaseEntity_vtbl *v13; // edx
  bool (__thiscall *IsClientCreated)(C_BaseEntity *); // eax
  __int64 v15; // xmm0_8
  float z; // edx
  __int64 v17; // xmm0_8
  float v18; // ecx
  const char *(__thiscall *DamageDecal)(C_BaseEntity *, int, int); // edx
  const char *v20; // eax
  const char *v21; // eax
  void (__thiscall *AddDecalToStaticProp)(IStaticPropMgrClient *, const Vector *, const Vector *, int, int, bool, CGameTrace *); // edx
  void (__thiscall *AddDecal)(C_BaseEntity *, const Vector *, const Vector *, const Vector *, int, int, bool, CGameTrace *, int); // edx
  int v24; // ecx
  float x; // xmm3_4
  float y; // xmm4_4
  float v27; // xmm5_4
  int (__thiscall *entindex)(IClientNetworkable *); // edx
  ICollideable *v29; // eax
  void (__thiscall *ClipRayToEntity)(IEngineTrace *, const Ray_t *, unsigned int, IHandleEntity *, CGameTrace *); // eax
  int v32; // [esp-14h] [ebp-94h]
  int v33; // [esp-10h] [ebp-90h]
  float v34; // [esp-Ch] [ebp-8Ch] BYREF
  float v35; // [esp-8h] [ebp-88h]
  float v36; // [esp-4h] [ebp-84h]
  Ray_t ray; // [esp+0h] [ebp-80h] BYREF
  float v38; // [esp+50h] [ebp-30h] BYREF
  float v39; // [esp+54h] [ebp-2Ch]
  _BYTE v40[28]; // [esp+58h] [ebp-28h] OVERLAPPED BYREF
  int decalNumber; // [esp+74h] [ebp-Ch] BYREF
  CMDLCacheCriticalSection cacheCriticalSection; // [esp+78h] [ebp-8h]
  IMDLCache *retaddr; // [esp+80h] [ebp+0h]

  decalNumber = a1;
  cacheCriticalSection.m_pCache = retaddr;
  ((void (__stdcall *)(int, int, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, const matrix3x4_t *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, IMDLCache *, _DWORD))mdlcache->BeginLock)(
    a1: a2,
    a2: a3,
    a3: v32,
    a4: v33,
    a5: LODWORD(v34),
    a6: LODWORD(v35),
    a7: LODWORD(v36),
    a8: LODWORD(ray.m_Start.x),
    a9: LODWORD(ray.m_Start.y),
    a10: LODWORD(ray.m_Start.z),
    a11: LODWORD(ray.m_Start.w),
    a12: LODWORD(ray.m_Delta.x),
    a13: LODWORD(ray.m_Delta.y),
    a14: LODWORD(ray.m_Delta.z),
    a15: LODWORD(ray.m_Delta.w),
    a16: LODWORD(ray.m_StartOffset.x),
    a17: LODWORD(ray.m_StartOffset.y),
    a18: LODWORD(ray.m_StartOffset.z),
    a19: LODWORD(ray.m_StartOffset.w),
    a20: LODWORD(ray.m_Extents.x),
    a21: LODWORD(ray.m_Extents.y),
    a22: LODWORD(ray.m_Extents.z),
    a23: LODWORD(ray.m_Extents.w),
    a24: ray.m_pWorldAxisTransform,
    a25: *(_DWORD *)&ray.m_IsRay,
    a26: *(_DWORD *)(&ray.m_IsSwept + 3),
    a27: *(_DWORD *)(&ray.m_IsSwept + 7),
    a28: LODWORD(v38),
    a29: LODWORD(v39),
    a30: *(_DWORD *)v40,
    a31: *(_DWORD *)&v40[4],
    a32: *(_DWORD *)&v40[8],
    a33: *(_DWORD *)&v40[12],
    a34: *(_DWORD *)&v40[16],
    a35: mdlcache,
    a36: *(_DWORD *)&v40[24]);
  memset(dst: (int)tr, value: nullptr, count: sizeof(CGameTrace));
  tr->fraction = 1.0;
  v38 = vecOrigin->x - vecStart->x;
  v39 = vecOrigin->y - vecStart->y;
  *(float *)v40 = vecOrigin->z - vecStart->z;
  v12 = VectorNormalize(vec: (Vector *)&v38);
  v13 = pEntity->IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  *(float *)&v40[16] = v12 + 8.0;
  IsClientCreated = v13->IsClientCreated;
  *(float *)&v40[4] = (float)(v38 * *(float *)&v40[16]) + vecStart->x;
  *(float *)&v40[8] = (float)(v39 * *(float *)&v40[16]) + vecStart->y;
  *(float *)&v40[12] = (float)(*(float *)v40 * *(float *)&v40[16]) + vecStart->z;
  v40[27] = 0;
  if ( !IsClientCreated(this: pEntity) )
  {
    v15 = *(_QWORD *)&vecStart->x;
    z = vecStart->z;
    *(_DWORD *)&v40[24] = iDamageType;
    *(_QWORD *)&v40[12] = v15;
    v17 = *(_QWORD *)&vecOrigin->x;
    v18 = vecOrigin->z;
    *(float *)&v40[20] = z;
    *(_QWORD *)v40 = v17;
    *(float *)&v40[8] = v18;
    v40[27] = FX_AffectRagdolls(
                a1: (int)&decalNumber,
                vecOrigin: *(Vector *)v40,
                vecStart: *(Vector *)&v40[12],
                iDamageType);
  }
  if ( (nFlags & 1) != 0 )
  {
    x = vecStart->x;
    y = vecStart->y;
    v27 = vecStart->z;
    ray.m_Start.z = *(float *)&v40[8] - y;
    ray.m_Start.y = *(float *)&v40[4] - x;
    ray.m_Start.w = *(float *)&v40[12] - v27;
    BYTE1(ray.m_Extents.z) = (float)((float)((float)(ray.m_Start.z * ray.m_Start.z)
                                           + (float)(ray.m_Start.y * ray.m_Start.y))
                                   + (float)(ray.m_Start.w * ray.m_Start.w)) != 0.0;
    entindex = pEntity->entindex;
    LOBYTE(ray.m_Extents.z) = 1;
    memset(&ray.m_StartOffset.y, 0, 12);
    ray.m_Extents.y = 0.0;
    memset(&ray.m_Delta.y, 0, 12);
    v34 = x;
    v35 = y;
    v36 = v27;
    if ( entindex(this: &pEntity->IClientNetworkable) != 0 || iHitbox == 0 )
    {
      ClipRayToEntity = enginetrace->ClipRayToEntity;
      *(_DWORD *)&v40[24] = tr;
      ((void (__thiscall *)(IEngineTrace *, float *, int, C_BaseEntity *))ClipRayToEntity)(
        a1: enginetrace,
        a2: &v34,
        a3: 1174421507,
        a4: pEntity);
    }
    else
    {
      v29 = staticpropmgr->GetStaticPropByIndex(this: staticpropmgr, a2: iHitbox - 1);
      enginetrace->ClipRayToCollideable(this: enginetrace, a2: (const Ray_t *)&v34, a3: 1174421507u, a4: v29, a5: tr);
    }
  }
  else
  {
    DamageDecal = pEntity->DamageDecal;
    *(_DWORD *)&v40[24] = iMaterial;
    v20 = (const char *)((int (__thiscall *)(C_BaseEntity *, int))DamageDecal)(a1: pEntity, a2: iDamageType);
    v21 = decalsystem->TranslateDecalForGameMaterial(this: decalsystem, a2: v20, a3: iMaterial);
    *(_DWORD *)&v40[16] = decalsystem->GetDecalIndexForName(this: decalsystem, a2: v21);
    if ( *(_DWORD *)&v40[16] == -1 )
      goto LABEL_17;
    if ( ((int (__thiscall *)(IClientNetworkable *, _DWORD))pEntity->entindex)(
           a1: &pEntity->IClientNetworkable,
           a2: *(_DWORD *)&v40[24]) != 0
      || iHitbox == 0 )
    {
      AddDecal = pEntity->AddDecal;
      *(_DWORD *)&v40[24] = maxLODToDecal;
      *(_DWORD *)&v40[20] = tr;
      v24 = *(_DWORD *)&v40[16];
      *(_DWORD *)&v40[16] = 1;
      *(_DWORD *)&v40[12] = v24;
      *(_DWORD *)&v40[8] = iHitbox;
      *(_DWORD *)&v40[4] = vecOrigin;
      ((void (__thiscall *)(C_BaseEntity *, Vector *, _BYTE *))AddDecal)(a1: pEntity, a2: vecStart, a3: &v40[4]);
    }
    else
    {
      AddDecalToStaticProp = staticpropmgr->AddDecalToStaticProp;
      *(_DWORD *)&v40[24] = tr;
      *(_DWORD *)&v40[20] = 1;
      *(_DWORD *)&v40[12] = iHitbox - 1;
      *(_DWORD *)&v40[8] = &v40[4];
      ((void (__thiscall *)(IStaticPropMgrClient *, Vector *))AddDecalToStaticProp)(a1: staticpropmgr, a2: vecStart);
    }
  }
  if ( tr->fraction != 1.0 && (v40[27] == 0 || (nFlags & 2) != 0) )
  {
    (*(void (__thiscall **)(_DWORD))(**(_DWORD **)&v40[20] + 124))(a1: *(_DWORD *)&v40[20]);
    return 1;
  }
LABEL_17:
  (*(void (__thiscall **)(_DWORD))(**(_DWORD **)&v40[20] + 124))(a1: *(_DWORD *)&v40[20]);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100DD560
// Name: PerformNewCustomEffects
// Source: json
//------------------------------------------------------------------------------
void __usercall PerformNewCustomEffects(
        int iMaterial@<eax>,
        const Vector *vecOrigin,
        CGameTrace *tr,
        const Vector *shotDir,
        int iScale,
        char nFlags)
{
  int m_nValue; // edx
  char v7; // dl
  ImpactEffect_t *v8; // esi
  int v9; // edi
  int *v10; // ecx
  int v11; // eax
  int v12; // edi
  ImpactEffect_t *v13; // eax
  const char *m_pName; // esi
  const char *m_pNameNoFlecks; // eax
  float y; // xmm2_4
  float x; // xmm4_4
  float z; // xmm6_4
  float v19; // xmm0_4
  float v20; // xmm3_4
  float v21; // xmm1_4
  float v22; // xmm5_4
  float fraction; // xmm0_4
  Vector *p_endpos; // eax
  float v25; // edx
  CNewParticleEffect *v26; // eax
  CNewParticleEffect *v27; // edi
  Vector vecColor; // [esp+0h] [ebp-34h] BYREF
  Vector vecShotBackward; // [esp+Ch] [ebp-28h] BYREF
  Vector vecReflect; // [esp+18h] [ebp-1Ch] BYREF
  Vector vecImpactPoint; // [esp+24h] [ebp-10h] BYREF
  CNewParticleEffect *pEffect; // [esp+30h] [ebp-4h]

  if ( r_drawflecks.m_pParent != nullptr )
    m_nValue = r_drawflecks.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  v7 = m_nValue == 0;
  if ( v7 == 0 )
    v7 = nFlags & 1;
  if ( (unsigned int)(iMaterial - 1) > 9 )
  {
    if ( (unsigned int)(iMaterial - 65) > 0x19 )
    {
      DevMsg(a1: "Invalid surface property.  Double-check surfaceproperties_manifest.txt\n");
      return;
    }
    v8 = s_pImpactEffect;
    v9 = 65;
    v10 = &RecvProps_107[4].m_ElementStride + 2 * iMaterial;
  }
  else
  {
    v8 = s_pImpactEffect2;
    v9 = 1;
    v10 = (int *)(&g_FleckMergeList.m_merge + 8 * iMaterial);
  }
  v11 = iMaterial - v9;
  v12 = *v10;
  v13 = &v8[v11];
  m_pName = v13->m_pName;
  if ( v7 != 0 )
  {
    m_pNameNoFlecks = v13->m_pNameNoFlecks;
    if ( m_pNameNoFlecks != nullptr )
    {
      v12 = v10[1];
      m_pName = m_pNameNoFlecks;
    }
  }
  if ( m_pName != nullptr )
  {
    y = shotDir->y;
    x = shotDir->x;
    z = shotDir->z;
    v19 = (float)((float)((float)(tr->plane.normal.y * y) + (float)(tr->plane.normal.x * shotDir->x))
                + (float)(tr->plane.normal.z * z))
        * -2.0;
    v20 = (float)(tr->plane.normal.x * v19) + shotDir->x;
    v21 = (float)(tr->plane.normal.y * v19) + y;
    v22 = (float)(tr->plane.normal.z * v19) + z;
    fraction = tr->fraction;
    vecReflect.x = v20;
    vecReflect.y = v21;
    vecReflect.z = v22;
    vecShotBackward.x = x * -1.0;
    vecShotBackward.y = y * -1.0;
    vecShotBackward.z = z * -1.0;
    p_endpos = &tr->endpos;
    if ( fraction == 1.0 )
      p_endpos = vecOrigin;
    v25 = p_endpos->z;
    *(_QWORD *)&vecImpactPoint.x = *(_QWORD *)&p_endpos->x;
    vecImpactPoint.z = v25;
    v26 = CNewParticleEffect::CreateOrAggregatePrecached(
            pOwner: nullptr,
            nPrecacheIndex: v12,
            vecAggregatePosition: &vecImpactPoint,
            pDebugName: nullptr,
            nSplitScreenUser: -1);
    v27 = nullptr;
    pEffect = v26;
    if ( v26 != nullptr )
    {
      CNewParticleEffect::AddRef(this: v26);
      v27 = pEffect;
    }
    if ( v27->m_pDef.m_pObject != nullptr )
    {
      SetImpactControlPoint(
        pEffect: v27,
        nPoint: 0,
        &vecImpactPoint,
        vecForward: &tr->plane.normal,
        pEntity: (C_BaseEntity *)tr->m_pEnt);
      SetImpactControlPoint(
        pEffect: v27,
        nPoint: 1,
        &vecImpactPoint,
        vecForward: &vecReflect,
        pEntity: (C_BaseEntity *)tr->m_pEnt);
      SetImpactControlPoint(
        pEffect: v27,
        nPoint: 2,
        &vecImpactPoint,
        vecForward: &vecShotBackward,
        pEntity: (C_BaseEntity *)tr->m_pEnt);
      vecColor.x = (float)iScale;
      vecColor.y = (float)iScale;
      vecColor.z = (float)iScale;
      CNewParticleEffect::SetControlPoint(this: v27, nWhichPoint: 3, v: &vecColor);
      if ( (v27->m_pDef.m_pObject->CParticleCollection::m_nControlPointReadMask & 0x10) != 0 )
      {
        GetColorForSurface(a1: (int)tr, trace: tr, color: &vecColor);
        CNewParticleEffect::SetControlPoint(this: v27, nWhichPoint: 4, v: &vecColor);
      }
    }
    CNewParticleEffect::Release(this: v27);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100DD780
// Name: void PerformCustomEffects(class Vector const __near &,class CGameTrace __near &,class Vector const __near &,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PerformCustomEffects(
        const Vector *vecOrigin,
        CGameTrace *tr,
        const Vector *shotDir,
        int iMaterial,
        int iScale,
        char nFlags)
{
  if ( (tr->surface.flags & 0x384) == 0 )
    PerformNewCustomEffects(iMaterial, vecOrigin, tr, shotDir, iScale, nFlags);
}

//------------------------------------------------------------------------------
// Address: 0x10415EA0
// Name: RagdollImpactPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int RagdollImpactPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106EF254;
  RagdollImpactPrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106EF254;
  dword_106EF254 = (int)&RagdollImpactPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10415EC0
// Name: PrecacheImpactsPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
CBaseResourcePrecacher *PrecacheImpactsPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  CBaseResourcePrecacher *result; // eax

  result = CBaseResourcePrecacher::sm_pFirst[0];
  PrecacheImpactsPrecache::s_ResourcePrecacher.m_pNext = CBaseResourcePrecacher::sm_pFirst[0];
  CBaseResourcePrecacher::sm_pFirst[0] = &PrecacheImpactsPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10415EE0
// Name: _dynamic_initializer_for__ClientEffectReg_ShellEjectCallback__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CClientEffectRegistration *dynamic_initializer_for__ClientEffectReg_ShellEjectCallback__()
{
  return CClientEffectRegistration::CClientEffectRegistration(
           this: &ClientEffectReg_ShellEjectCallback,
           pEffectName: "ShellEject",
           fn: ShellEjectCallback);
}
