// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/cstrike15/weapon_knife.cpp
// Functions: 26
// ============================================================

#include "game\shared\cstrike15\weapon_knife.h"

//------------------------------------------------------------------------------
// Address: 0x1022FFE0
// Name: public: virtual class ClientClass __near * C_Knife::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_Knife::GetClientClass(C_Knife *this)
{
  return &__g_C_KnifeClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x102300E0
// Name: public: virtual struct datamap_t __near * C_Knife::GetPredDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall C_Knife::GetPredDescMap(C_Knife *this)
{
  return &C_Knife::m_PredMap;
}

//------------------------------------------------------------------------------
// Address: 0x102300F0
// Name: public: virtual void weapon_knifePrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_knifePrecache::CResourcePrecacher::Cache(
        weapon_knifePrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_knife",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10230120
// Name: public: virtual void C_Knife::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall C_Knife::Precache(C_Knife *this@<ecx>, int a2@<ebx>)
{
  C_WeaponCSBase::Precache(this, a2);
  C_BaseEntity::PrecacheScriptSound(soundname: "Weapon_Knife.Deploy");
  C_BaseEntity::PrecacheScriptSound(soundname: "Weapon_Knife.Slash");
  C_BaseEntity::PrecacheScriptSound(soundname: "Weapon_Knife.Stab");
  C_BaseEntity::PrecacheScriptSound(soundname: "Weapon_Knife.Hit");
  PrecacheEffect(pEffectName: "KnifeSlash");
}

//------------------------------------------------------------------------------
// Address: 0x10230160
// Name: public: virtual bool C_Knife::Deploy(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_Knife::Deploy(C_Knife *this)
{
  const Vector *v2; // edi
  int v3; // eax
  int v4; // eax
  int v5; // ebx
  IMDLCache *v6; // edi
  int v7; // eax
  bool v8; // bl
  CPASAttenuationFilter filter; // [esp+14h] [ebp-20h] BYREF

  v2 = this->GetAbsOrigin(this);
  C_RecipientFilter::C_RecipientFilter(this: &filter);
  filter.__vftable = (CPASAttenuationFilter_vtbl *)&CPASFilter::`vftable';
  C_RecipientFilter::AddRecipientsByPVS(this: &filter, origin: v2);
  filter.__vftable = (CPASAttenuationFilter_vtbl *)&CPASAttenuationFilter::`vftable';
  C_RecipientFilter::UsePredictionRules(this: &filter);
  v3 = ((int (*)(void))this->entindex)();
  C_BaseEntity::EmitSound(
    &filter,
    iEntIndex: v3,
    soundname: "Weapon_Knife.Deploy",
    pOrigin: nullptr,
    soundtime: 0.0,
    duration: nullptr);
  C_WeaponCSBase::GetPlayerOwner(this);
  v5 = v4;
  if ( v4 != 0 )
  {
    v6 = g_pMDLCache;
    g_pMDLCache->BeginLock(this: g_pMDLCache);
    v7 = (*(int (__thiscall **)(int))(*(_DWORD *)v5 + 332))(a1: v5);
    C_BaseAnimating::SetBodygroup(this, iGroup: 0, iValue: v7 != 2);
    v6->EndLock(this: v6);
  }
  v8 = C_WeaponCSBase::Deploy(this);
  C_RecipientFilter::~C_RecipientFilter(this: &filter);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x10230230
// Name: public: void C_Knife::Smack(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_Knife::Smack(C_Knife *this)
{
  int v2; // eax
  unsigned int m_Index; // ecx
  struct CBaseEntity *m_pEntity; // eax
  const char *v5; // eax
  __int16 surfaceProps; // dx
  int hitbox; // eax
  struct CBaseEntity *m_pEnt; // ecx
  float z; // xmm0_4
  int v10; // eax
  int v11; // [esp-8h] [ebp-BCh]
  int v12; // [esp-8h] [ebp-BCh]
  const char *v13; // [esp-4h] [ebp-B8h]
  CPASAttenuationFilter v14; // [esp+10h] [ebp-A4h] BYREF
  CPASFilter filter; // [esp+30h] [ebp-84h] BYREF
  CEffectData data; // [esp+50h] [ebp-64h] BYREF

  C_WeaponCSBase::GetPlayerOwner(this);
  if ( v2 != 0 )
  {
    m_Index = this->m_pTraceHitEnt.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = (struct CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    this->m_trHit.m_pEnt = m_pEntity;
    if ( m_pEntity != nullptr && (this->m_trHit.surface.flags & 4) == 0 && this->m_trHit.fraction != 1.0 )
    {
      CPASAttenuationFilter::CPASAttenuationFilter(this: &v14, entity: this, attenuation: 0.80000001);
      C_RecipientFilter::UsePredictionRules(this: &v14);
      if ( (*(unsigned __int8 (__thiscall **)(struct CBaseEntity *))(*(_DWORD *)this->m_trHit.m_pEnt + 584))(a1: this->m_trHit.m_pEnt) != 0 )
      {
        v5 = "Weapon_Knife.Stab";
        if ( this->m_lastAttackType != Secondary_Mode )
          v5 = "Weapon_Knife.Hit";
        v13 = v5;
        v11 = this->entindex(this: &this->IClientNetworkable);
        C_BaseEntity::EmitSound(
          filter: &v14,
          iEntIndex: v11,
          soundname: v13,
          pOrigin: nullptr,
          soundtime: 0.0,
          duration: nullptr);
      }
      else
      {
        v12 = ((int (*)(void))this->entindex)();
        C_BaseEntity::EmitSound(
          filter: &v14,
          iEntIndex: v12,
          soundname: "Weapon_Knife.HitWall",
          pOrigin: nullptr,
          soundtime: 0.0,
          duration: nullptr);
      }
      C_RecipientFilter::~C_RecipientFilter(this: &v14);
      CEffectData::CEffectData(this: &data);
      surfaceProps = this->m_trHit.surface.surfaceProps;
      hitbox = this->m_trHit.hitbox;
      m_pEnt = this->m_trHit.m_pEnt;
      data.m_vOrigin = this->m_trHit.endpos;
      data.m_vStart.x = this->m_trHit.startpos.x;
      data.m_vStart.y = this->m_trHit.startpos.y;
      z = this->m_trHit.startpos.z;
      data.m_nHitBox = hitbox;
      data.m_vStart.z = z;
      data.m_nSurfaceProp = surfaceProps;
      data.m_nDamageType = 4;
      data.m_hEntity.m_Index = *(_DWORD *)(*(int (__thiscall **)(struct CBaseEntity *))(*(_DWORD *)m_pEnt + 8))(a1: m_pEnt);
      C_RecipientFilter::C_RecipientFilter(this: &filter);
      filter.__vftable = (CPASFilter_vtbl *)&CPASFilter::`vftable';
      C_RecipientFilter::AddRecipientsByPVS(this: &filter, origin: &data.m_vOrigin);
      C_WeaponCSBase::GetPlayerOwner(this);
      data.m_vAngles = *(QAngle *)(*(int (__thiscall **)(int))(*(_DWORD *)v10 + 44))(a1: v10);
      data.m_fFlags = 1;
      DispatchEffect(&filter, delay: 0.0, pName: "KnifeSlash", &data);
      C_RecipientFilter::~C_RecipientFilter(this: &filter);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10230460
// Name: public: virtual void C_Knife::WeaponIdle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_Knife::WeaponIdle(C_Knife *this)
{
  int v2; // eax

  if ( this->m_flTimeWeaponIdle.m_Value <= *(float *)(gpGlobals.m_Index + 12) )
  {
    C_WeaponCSBase::GetPlayerOwner(this);
    if ( v2 != 0 )
    {
      ((void (__thiscall *)(C_Knife *, _DWORD))this->SetWeaponIdleTime)(
        a1: this,
        a2: *(float *)(gpGlobals.m_Index + 12) + 20.0);
      this->SendWeaponAnim(this, a2: 183);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102304C0
// Name: public: virtual void C_Knife::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_Knife::Spawn(C_Knife *this)
{
  this->Precache(this);
  if ( this->m_iClip1.m_Value != -1 )
    this->m_iClip1.m_Value = -1;
  C_BaseCombatWeapon::Spawn(this);
}

//------------------------------------------------------------------------------
// Address: 0x102304F0
// Name: void FindHullIntersection(class Vector const __near &,class CGameTrace __near &,class Vector const __near &,class Vector const __near &,class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall FindHullIntersection(
        float a1@<ebp>,
        const Vector *vecSrc,
        CGameTrace *tr,
        const Vector *mins,
        const Vector *maxs,
        C_BaseEntity *pEntity)
{
  float z; // eax
  float v7; // edx
  float x; // xmm3_4
  float y; // xmm4_4
  float v10; // xmm5_4
  float v11; // ecx
  int v12; // edx
  int v13; // eax
  float v14; // xmm0_4
  __int16 v15; // cx
  struct CBaseEntity *v16; // eax
  int v17; // ecx
  float v18; // xmm2_4
  float v19; // xmm0_4
  float v20; // xmm4_4
  float v21; // xmm5_4
  float v22; // xmm6_4
  float v23; // xmm6_4
  float v24; // xmm4_4
  float v25; // xmm5_4
  float v26; // xmm3_4
  __int128 v27; // xmm0
  __int16 v28; // kr00_2
  __int16 v29; // dx
  float v30; // xmm0_4
  float v31; // xmm0_4
  unsigned __int16 v32; // cx
  float v33; // xmm0_4
  int v34; // eax
  float v35; // xmm0_4
  const char *v36; // ecx
  int v37; // edx
  int v38; // eax
  struct CBaseEntity *v39; // eax
  int v40; // ecx
  float v41; // xmm0_4
  CTraceFilterSimple v42; // [esp+24h] [ebp-12Ch] BYREF
  __int128 v43; // [esp+34h] [ebp-11Ch]
  _DWORD v44[4]; // [esp+44h] [ebp-10Ch] BYREF
  float v45; // [esp+54h] [ebp-FCh]
  float v46; // [esp+58h] [ebp-F8h]
  float v47; // [esp+5Ch] [ebp-F4h]
  int v48; // [esp+64h] [ebp-ECh]
  int v49; // [esp+68h] [ebp-E8h]
  int v50; // [esp+6Ch] [ebp-E4h]
  int v51; // [esp+74h] [ebp-DCh]
  int v52; // [esp+78h] [ebp-D8h]
  int v53; // [esp+7Ch] [ebp-D4h]
  int v54; // [esp+84h] [ebp-CCh]
  char v55; // [esp+88h] [ebp-C8h]
  bool v56; // [esp+89h] [ebp-C7h]
  __int64 v57; // [esp+9Ch] [ebp-B4h] BYREF
  float v58; // [esp+A4h] [ebp-ACh] BYREF
  Vector minmaxs[2]; // [esp+A8h] [ebp-A8h] BYREF
  _BYTE tmpTrace[92]; // [esp+C0h] [ebp-90h] OVERLAPPED BYREF
  int v61; // [esp+11Ch] [ebp-34h]
  int j; // [esp+120h] [ebp-30h]
  float v63; // [esp+124h] [ebp-2Ch]
  int i; // [esp+128h] [ebp-28h]
  float *v65; // [esp+12Ch] [ebp-24h]
  float *distance; // [esp+130h] [ebp-20h]
  float *v67; // [esp+134h] [ebp-1Ch]
  Vector v68; // [esp+138h] [ebp-18h] BYREF
  Vector vecEnd; // [esp+144h] [ebp-Ch]
  float retaddr; // [esp+150h] [ebp+0h]

  vecEnd.x = a1;
  vecEnd.y = retaddr;
  z = mins->z;
  v7 = tr->endpos.z;
  v57 = *(_QWORD *)&mins->x;
  x = vecSrc->x;
  y = vecSrc->y;
  v10 = vecSrc->z;
  v58 = z;
  v11 = maxs->z;
  *(_QWORD *)&minmaxs[0].x = *(_QWORD *)&maxs->x;
  *(_QWORD *)&v68.x = *(_QWORD *)&tr->endpos.x;
  minmaxs[0].z = v11;
  v63 = 1000000.0;
  *(float *)&tmpTrace[80] = x + (float)((float)(v68.x - x) * 2.0);
  *(float *)&tmpTrace[84] = y + (float)((float)(v68.y - y) * 2.0);
  *(float *)&tmpTrace[88] = v10 + (float)((float)(v7 - v10) * 2.0);
  v68 = *(Vector *)&tmpTrace[80];
  UTIL_TraceLine(
    vecAbsStart: vecSrc,
    vecAbsEnd: &v68,
    mask: 0x200400Bu,
    ignore: pEntity,
    collisionGroup: 0,
    ptr: (CGameTrace *)&minmaxs[1]);
  if ( *(float *)&tmpTrace[32] >= 1.0 )
  {
    distance = (float *)&v57;
    for ( i = 2; i != 0; --i )
    {
      v68.x = *distance + *(float *)&tmpTrace[80];
      v67 = (float *)&v57 + 1;
      for ( j = 2; j != 0; --j )
      {
        v18 = *v67 + *(float *)&tmpTrace[84];
        v68.y = v18;
        v65 = &v58;
        v61 = 2;
        while ( 1 )
        {
          v19 = *v65;
          v20 = vecSrc->x;
          v21 = vecSrc->y;
          v22 = vecSrc->z;
          v46 = v18 - v21;
          v45 = v68.x - v20;
          v47 = (float)(v19 + *(float *)&tmpTrace[88]) - v22;
          v56 = (float)((float)((float)(v46 * v46) + (float)(v45 * v45)) + (float)(v47 * v47)) != 0.0;
          v53 = 0;
          v52 = 0;
          v51 = 0;
          v54 = 0;
          v55 = 1;
          v50 = 0;
          v49 = 0;
          v48 = 0;
          *(float *)v44 = v20;
          *(float *)&v44[1] = v21;
          *(float *)&v44[2] = v22;
          CTraceFilterSimple::CTraceFilterSimple(
            this: &v42,
            passedict: pEntity,
            collisionGroup: 0,
            pExtraShouldHitFunc: nullptr);
          enginetrace->TraceRay(
            this: enginetrace,
            a2: (const Ray_t *)v44,
            a3: 33570827u,
            a4: &v42,
            a5: (CGameTrace *)&minmaxs[1]);
          if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
            DebugDrawLine(
              vecAbsStart: &minmaxs[1],
              vecAbsEnd: (const Vector *)tmpTrace,
              r: 255,
              g: 0,
              b: 0,
              test: true,
              duration: -1.0);
          v23 = *(float *)&tmpTrace[32];
          if ( *(float *)&tmpTrace[32] < 1.0 )
          {
            v24 = *(float *)&tmpTrace[4];
            v25 = *(float *)&tmpTrace[8];
            v26 = *(float *)tmpTrace;
            v27 = 0;
            *(float *)&v27 = fsqrt(
                               (float)((float)((float)(*(float *)&tmpTrace[4] - vecSrc->y)
                                             * (float)(*(float *)&tmpTrace[4] - vecSrc->y))
                                     + (float)((float)(*(float *)&tmpTrace[8] - vecSrc->z)
                                             * (float)(*(float *)&tmpTrace[8] - vecSrc->z)))
                             + (float)((float)(*(float *)tmpTrace - vecSrc->x) * (float)(*(float *)tmpTrace - vecSrc->x)));
            v43 = v27;
            if ( v63 > *(float *)&v27 )
            {
              v28 = *(_WORD *)&tmpTrace[28];
              v29 = *(_WORD *)&tmpTrace[30];
              tr->startpos = minmaxs[1];
              v30 = *(float *)&tmpTrace[12];
              tr->endpos.x = v26;
              tr->endpos.y = v24;
              tr->endpos.z = v25;
              tr->plane.normal.x = v30;
              tr->plane.normal.y = *(float *)&tmpTrace[16];
              v31 = *(float *)&tmpTrace[20];
              tr->plane.signbits = HIBYTE(v28);
              v32 = *(_WORD *)&tmpTrace[40];
              tr->plane.normal.z = v31;
              v33 = *(float *)&tmpTrace[24];
              tr->plane.type = v28;
              v34 = *(_DWORD *)&tmpTrace[36];
              tr->plane.dist = v33;
              v35 = *(float *)&tmpTrace[44];
              *(_WORD *)tr->plane.pad = v29;
              LOBYTE(v29) = tmpTrace[42];
              tr->contents = v34;
              LOBYTE(v34) = tmpTrace[43];
              tr->dispFlags = v32;
              v36 = *(const char **)&tmpTrace[48];
              tr->allsolid = v29;
              v37 = *(_DWORD *)&tmpTrace[52];
              tr->surface.name = v36;
              LOWORD(v36) = *(_WORD *)&tmpTrace[60];
              tr->startsolid = v34;
              v38 = *(_DWORD *)&tmpTrace[56];
              *(_DWORD *)&tr->surface.surfaceProps = v37;
              LOWORD(v37) = *(_WORD *)&tmpTrace[62];
              tr->hitgroup = v38;
              v39 = *(struct CBaseEntity **)&tmpTrace[64];
              tr->physicsbone = (__int16)v36;
              v40 = *(_DWORD *)&tmpTrace[68];
              tr->fractionleftsolid = v35;
              v41 = *(float *)&v43;
              tr->fraction = v23;
              tr->worldSurfaceIndex = v37;
              tr->m_pEnt = v39;
              tr->hitbox = v40;
              v63 = v41;
            }
          }
          v65 += 3;
          if ( --v61 == 0 )
            break;
          v18 = v68.y;
        }
        v67 += 3;
      }
      distance += 3;
    }
  }
  else
  {
    CBaseTrace::operator=(this: tr, __that: (const CBaseTrace *)&minmaxs[1]);
    v12 = *(_DWORD *)&tmpTrace[52];
    v13 = *(_DWORD *)&tmpTrace[56];
    v14 = *(float *)&tmpTrace[44];
    tr->surface.name = *(const char **)&tmpTrace[48];
    v15 = *(_WORD *)&tmpTrace[60];
    *(_DWORD *)&tr->surface.surfaceProps = v12;
    LOWORD(v12) = *(_WORD *)&tmpTrace[62];
    tr->hitgroup = v13;
    v16 = *(struct CBaseEntity **)&tmpTrace[64];
    tr->physicsbone = v15;
    v17 = *(_DWORD *)&tmpTrace[68];
    tr->fractionleftsolid = v14;
    tr->worldSurfaceIndex = v12;
    tr->m_pEnt = v16;
    tr->hitbox = v17;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10230970
// Name: public: bool C_Knife::SwingOrStab(enum CSWeaponMode)
// Source: json
//------------------------------------------------------------------------------
char __userpurge C_Knife::SwingOrStab@<al>(C_Knife *this@<ecx>, int a2@<ebx>, CSWeaponMode weaponMode)
{
  C_CSPlayer *v4; // eax
  C_CSPlayer *v5; // edi
  const QAngle *(__thiscall *EyeAngles)(C_BaseEntity *); // eax
  const QAngle *v8; // eax
  const CViewVectors *v9; // eax
  char v10; // bl
  float v11; // xmm0_4
  float v12; // xmm0_4
  float *v13; // ecx
  float v14; // xmm0_4
  const Vector *v15; // edi
  int v16; // eax
  int hitgroup; // ecx
  int v18; // eax
  float fractionleftsolid; // xmm0_4
  __int16 physicsbone; // dx
  struct CBaseEntity *m_pEnt; // ecx
  int hitbox; // edx
  float v23; // xmm0_4
  Vector *p_m_vDuckHullMax; // [esp+10h] [ebp-B4h]
  PlayerAnimEvent_t v25; // [esp+10h] [ebp-B4h]
  CGameTrace tr; // [esp+20h] [ebp-A4h] BYREF
  CPASAttenuationFilter filter; // [esp+74h] [ebp-50h] BYREF
  Vector vForward; // [esp+94h] [ebp-30h] BYREF
  Vector vecEnd; // [esp+A0h] [ebp-24h] BYREF
  Vector vecSrc; // [esp+ACh] [ebp-18h] BYREF
  float fSecDelay; // [esp+B8h] [ebp-Ch]
  float fPrimDelay; // [esp+BCh] [ebp-8h]
  bool bDidHit; // [esp+C3h] [ebp-1h]
  IHandleEntity savedregs; // [esp+C4h] [ebp+0h] BYREF

  C_WeaponCSBase::GetPlayerOwner(this);
  v5 = v4;
  if ( v4 == nullptr )
    return 0;
  EyeAngles = v4->EyeAngles;
  fPrimDelay = (float)(weaponMode != Primary_Mode ? 32 : 48);
  v8 = EyeAngles(this: v5);
  AngleVectors(angles: v8, forward: &vForward);
  ((void (__thiscall *)(C_CSPlayer *, Vector *, int))v5->Weapon_ShootPosition)(a1: v5, a2: &vecSrc, a3: a2);
  vecEnd.y = vecSrc.y + (float)(vForward.y * fPrimDelay);
  vecEnd.x = vecSrc.x + (float)(vForward.x * fPrimDelay);
  vecEnd.z = vecSrc.z + (float)(vForward.z * fPrimDelay);
  UTIL_TraceLine(
    a1: &savedregs,
    a2: (int)this,
    vecAbsStart: &vecSrc,
    vecAbsEnd: &vecEnd,
    mask: 0x200400Bu,
    ignore: v5,
    collisionGroup: 0,
    ptr: &tr);
  if ( tr.fraction >= 1.0 )
  {
    UTIL_TraceHull(
      a1: &savedregs,
      a2: (int)this,
      vecAbsStart: &vecSrc,
      vecAbsEnd: &vecEnd,
      hullMin: &head_hull_mins,
      hullMax: &head_hull_maxs,
      mask: 0x200400Bu,
      ignore: v5,
      collisionGroup: 0,
      ptr: &tr);
    if ( tr.fraction >= 1.0 )
    {
LABEL_10:
      bDidHit = false;
      v10 = 0;
      goto LABEL_11;
    }
    if ( tr.m_pEnt == nullptr || C_BaseEntity::IsBSPModel(this: (C_BaseEntity *)tr.m_pEnt) )
    {
      p_m_vDuckHullMax = &g_pGameRules->GetViewVectors(this: g_pGameRules)->m_vDuckHullMax;
      v9 = g_pGameRules->GetViewVectors(this: g_pGameRules);
      FindHullIntersection(
        a1: COERCE_FLOAT(&savedregs),
        &vecSrc,
        &tr,
        mins: &v9->m_vDuckHullMin,
        maxs: p_m_vDuckHullMax,
        pEntity: v5);
    }
  }
  if ( tr.fraction >= 1.0 )
    goto LABEL_10;
  v10 = 1;
LABEL_11:
  if ( weaponMode == Secondary_Mode )
  {
    this->SendWeaponAnim(this, a2: v10 != 0 ? 199 : 205);
    if ( v10 != 0 )
    {
      v11 = 1.1;
      fPrimDelay = 1.1;
    }
    else
    {
      v11 = 1.0;
      fPrimDelay = 1.0;
    }
    v25 = PLAYERANIMEVENT_FIRE_GUN_SECONDARY;
  }
  else
  {
    this->SendWeaponAnim(this, a2: v10 != 0 ? 198 : 204);
    if ( v10 != 0 )
    {
      v11 = 0.5;
      fPrimDelay = 0.5;
    }
    else
    {
      fPrimDelay = 0.40000001;
      v11 = 0.5;
    }
    v25 = PLAYERANIMEVENT_FIRE_GUN_PRIMARY;
  }
  fSecDelay = v11;
  C_CSPlayer::DoAnimationEvent(this: v5, event: v25, nData: 0);
  v12 = fPrimDelay + *(float *)(gpGlobals.m_Index + 12);
  v13 = (float *)(gpGlobals.m_Index + 12);
  if ( this->m_flNextPrimaryAttack.m_Value != v12 )
    this->m_flNextPrimaryAttack.m_Value = v12;
  v14 = fSecDelay + *v13;
  if ( this->m_flNextSecondaryAttack.m_Value != v14 )
    this->m_flNextSecondaryAttack.m_Value = v14;
  ((void (__thiscall *)(C_Knife *, _DWORD))this->SetWeaponIdleTime)(a1: this, a2: *v13 + 2.0);
  if ( v10 != 0 )
  {
    CBaseTrace::operator=(this: &this->m_trHit, __that: &tr);
    hitgroup = tr.hitgroup;
    v18 = *(_DWORD *)&tr.surface.surfaceProps;
    fractionleftsolid = tr.fractionleftsolid;
    this->m_trHit.surface.name = tr.surface.name;
    physicsbone = tr.physicsbone;
    this->m_trHit.hitgroup = hitgroup;
    m_pEnt = tr.m_pEnt;
    *(_DWORD *)&this->m_trHit.surface.surfaceProps = v18;
    LOWORD(v18) = tr.worldSurfaceIndex;
    this->m_trHit.physicsbone = physicsbone;
    hitbox = tr.hitbox;
    this->m_trHit.fractionleftsolid = fractionleftsolid;
    this->m_trHit.worldSurfaceIndex = v18;
    this->m_trHit.m_pEnt = m_pEnt;
    this->m_trHit.hitbox = hitbox;
    if ( m_pEnt != nullptr )
      this->m_pTraceHitEnt.m_Index = *(_DWORD *)(*(int (__thiscall **)(struct CBaseEntity *))(*(_DWORD *)m_pEnt + 8))(a1: m_pEnt);
    else
      this->m_pTraceHitEnt.m_Index = -1;
    this->m_lastAttackType = weaponMode;
    if ( (float)((float)(weaponMode == Secondary_Mode) + *(float *)(gpGlobals.m_Index + 12)) == 0.0 )
      v23 = 0.1;
    else
      v23 = 0.2;
    if ( this->m_flSmackTime.m_Value != v23 )
      this->m_flSmackTime.m_Value = v23;
    return v10;
  }
  else
  {
    v15 = this->GetAbsOrigin(this);
    C_RecipientFilter::C_RecipientFilter(this: &filter);
    filter.__vftable = (CPASAttenuationFilter_vtbl *)&CPASFilter::`vftable';
    C_RecipientFilter::AddRecipientsByPVS(this: &filter, origin: v15);
    filter.__vftable = (CPASAttenuationFilter_vtbl *)&CPASAttenuationFilter::`vftable';
    C_RecipientFilter::UsePredictionRules(this: &filter);
    v16 = ((int (*)(void))this->entindex)();
    C_BaseEntity::EmitSound(
      &filter,
      iEntIndex: v16,
      soundname: "Weapon_Knife.Slash",
      pOrigin: nullptr,
      soundtime: 0.0,
      duration: nullptr);
    C_RecipientFilter::~C_RecipientFilter(this: &filter);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10230D50
// Name: public: virtual void C_Knife::ItemPostFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_Knife::ItemPostFrame(C_Knife *this)
{
  float m_Value; // xmm0_4

  m_Value = this->m_flSmackTime.m_Value;
  if ( m_Value > 0.0 && *(float *)(gpGlobals.m_Index + 12) > m_Value )
  {
    C_Knife::Smack(this);
    if ( this->m_flSmackTime.m_Value != -1.0 )
      this->m_flSmackTime.m_Value = -1.0;
  }
  C_WeaponCSBase::ItemPostFrame(this);
}

//------------------------------------------------------------------------------
// Address: 0x10230DB0
// Name: public: virtual enum CSWeaponID C_Knife::GetCSWeaponID(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_Knife::GetCSWeaponID(C_Knife *this)
{
  return 31;
}

//------------------------------------------------------------------------------
// Address: 0x10230DC0
// Name: public: virtual void C_Knife::PrimaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall C_Knife::PrimaryAttack(C_Knife *this@<ecx>, int a2@<ebx>)
{
  int v3; // eax

  C_WeaponCSBase::GetPlayerOwner(this);
  if ( v3 != 0 )
    C_Knife::SwingOrStab(this, a2, weaponMode: Primary_Mode);
}

//------------------------------------------------------------------------------
// Address: 0x10230DE0
// Name: public: virtual void C_Knife::SecondaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall C_Knife::SecondaryAttack(C_Knife *this@<ecx>, int a2@<ebx>)
{
  int v3; // eax

  C_WeaponCSBase::GetPlayerOwner(this);
  if ( v3 != 0 && *(_BYTE *)(v3 + 6776) == 0 && !C_CSGameRules::IsFreezePeriod(this: (CBaseAchievement *)g_pGameRules) )
    C_Knife::SwingOrStab(this, a2, weaponMode: Secondary_Mode);
}

//------------------------------------------------------------------------------
// Address: 0x10230E80
// Name: CC_KnifeFactory
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__cdecl CC_KnifeFactory()
{
  C_WeaponCSBase *v0; // eax
  _DWORD *v1; // esi

  v0 = (C_WeaponCSBase *)C_BaseEntity::operator new(stAllocateBlock: 0xE10u);
  v1 = &v0->C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v0 == nullptr )
    return nullptr;
  C_WeaponCSBase::C_WeaponCSBase(this: v0);
  *v1 = &C_Knife::`vftable'{for `IClientUnknown'};
  v1[1] = &C_Knife::`vftable'{for `IClientRenderable'};
  v1[2] = &C_Knife::`vftable'{for `IClientNetworkable'};
  v1[3] = &C_Knife::`vftable'{for `IClientThinkable'};
  v1[4] = &C_Knife::`vftable';
  v1[897] = -1;
  return (C_BaseEntity *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x10428DB0
// Name: DT_LocalActiveWeaponKnifeData::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_LocalActiveWeaponKnifeData::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_LocalActiveWeaponKnifeData::g_RecvTable);
  return atexit(func: DT_LocalActiveWeaponKnifeData::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10428DD0
// Name: DT_LocalActiveWeaponKnifeData::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_LocalActiveWeaponKnifeData::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_LocalActiveWeaponKnifeData::ignored>();
  DT_LocalActiveWeaponKnifeData::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10428DE0
// Name: DT_WeaponKnife::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponKnife::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_WeaponKnife::g_RecvTable);
  return atexit(func: DT_WeaponKnife::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10428E00
// Name: DT_WeaponKnife::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponKnife::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_WeaponKnife::ignored>();
  DT_WeaponKnife::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10428E10
// Name: C_Knife_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__
// Source: json
//------------------------------------------------------------------------------
void C_Knife_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__()
{
  C_Knife::m_PredMap.dataNumFields = 1;
  C_Knife::m_PredMap.dataDesc = (typedescription_t *)&unk_105B62B4;
}

//------------------------------------------------------------------------------
// Address: 0x10428E60
// Name: weapon_knifePrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
CBaseResourcePrecacher *weapon_knifePrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  CBaseResourcePrecacher *result; // eax

  result = CBaseResourcePrecacher::sm_pFirst[0];
  weapon_knifePrecache::s_ResourcePrecacher.m_pNext = CBaseResourcePrecacher::sm_pFirst[0];
  CBaseResourcePrecacher::sm_pFirst[0] = &weapon_knifePrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104360D0
// Name: DT_LocalActiveWeaponKnifeData::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_LocalActiveWeaponKnifeData::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_LocalActiveWeaponKnifeData::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x104360E0
// Name: DT_WeaponKnife::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponKnife::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_WeaponKnife::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10230E10
// Name: _C_Knife_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_Knife_CreateObject(int entnum, int serialNum)
{
  C_WeaponCSBase *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_WeaponCSBase *)C_BaseEntity::operator new(stAllocateBlock: 0xE10u);
  v3 = &v2->C_BaseCombatWeapon::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_WeaponCSBase::C_WeaponCSBase(this: v2);
  *v3 = &C_Knife::`vftable'{for `IClientUnknown'};
  v3[1] = &C_Knife::`vftable'{for `IClientRenderable'};
  v3[2] = &C_Knife::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_Knife::`vftable'{for `IClientThinkable'};
  v3[4] = &C_Knife::`vftable';
  v3[897] = -1;
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x10428E30
// Name: _dynamic_initializer_for__g_Cweapon_knifeFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Cweapon_knifeFoo__()
{
  CClassMap *ClassMap; // eax
  int result; // eax

  ClassMap = GetClassMap();
  result = ((int (__thiscall *)(CClassMap *, const char *, const char *, int, C_BaseEntity *(__cdecl *)()))ClassMap->Add)(
             a1: ClassMap,
             a2: "weapon_knife",
             a3: "C_Knife",
             a4: 3600,
             a5: CC_KnifeFactory);
  __g_C_KnifeClientClass.m_pMapClassname = "weapon_knife";
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10428E80
// Name: _dynamic_initializer_for____g_C_WeaponM249ClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_WeaponM249ClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_WeaponM249ClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_WeaponM249ClientClass;
  return result;
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x102ED6E0
// Name: public: virtual class ServerClass __near * CKnife::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CKnife::GetServerClass(CKnife *this)
{
  return &g_CKnife_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x102ED6F0
// Name: public: virtual void weapon_knifePrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall weapon_knifePrecache::CResourcePrecacher::Cache(
        weapon_knifePrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "weapon_knife",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102ED720
// Name: public: virtual struct datamap_t __near * CKnife::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CKnife::GetDataDescMap(CKnife *this)
{
  return &CKnife::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x102ED730
// Name: public: virtual void CKnife::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKnife::Precache(CKnife *this)
{
  CWeaponCSBase::Precache(this);
  CBaseEntity::PrecacheScriptSound(soundname: "Weapon_Knife.Deploy");
  CBaseEntity::PrecacheScriptSound(soundname: "Weapon_Knife.Slash");
  CBaseEntity::PrecacheScriptSound(soundname: "Weapon_Knife.Stab");
  CBaseEntity::PrecacheScriptSound(soundname: "Weapon_Knife.Hit");
  PrecacheEffect(pEffectName: "KnifeSlash");
}

//------------------------------------------------------------------------------
// Address: 0x102ED770
// Name: public: virtual bool CKnife::Deploy(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CKnife::Deploy(CKnife *this)
{
  const Vector *v2; // edi
  Vector *(__thiscall *GetSoundEmissionOrigin)(CBaseEntity *, Vector *); // edx
  const Vector *v4; // eax
  edict_t *m_pPev; // eax
  CCSPlayer *PlayerOwner; // ebx
  IMDLCache *v7; // edi
  int TeamNumber; // eax
  bool v9; // bl
  CPASAttenuationFilter filter; // [esp+1Ch] [ebp-2Ch] BYREF
  float attenuation[3]; // [esp+3Ch] [ebp-Ch] BYREF
  int savedregs; // [esp+48h] [ebp+0h] BYREF

  v2 = (const Vector *)((int (__thiscall *)(CKnife *))this->GetSoundEmissionOrigin)(a1: this);
  CRecipientFilter::CRecipientFilter(this: &filter);
  filter.__vftable = (CPASAttenuationFilter_vtbl *)&CPASFilter::`vftable';
  CRecipientFilter::AddRecipientsByPAS(this: &filter, origin: v2);
  GetSoundEmissionOrigin = this->GetSoundEmissionOrigin;
  filter.__vftable = (CPASAttenuationFilter_vtbl *)&CPASAttenuationFilter::`vftable';
  v4 = (const Vector *)((int (__thiscall *)(CKnife *, float *, int))GetSoundEmissionOrigin)(
                         a1: this,
                         a2: attenuation,
                         a3: 1061997773);
  CPASAttenuationFilter::Filter(this: &filter, a2: (int)&savedregs, origin: v4, attenuation: COERCE_FLOAT(attenuation));
  CRecipientFilter::UsePredictionRules(this: &filter);
  m_pPev = this->m_Network.m_pPev;
  if ( m_pPev != nullptr )
    m_pPev -= (int)gpGlobals->pEdicts;
  CBaseEntity::EmitSound(
    &filter,
    iEntIndex: (int)m_pPev,
    soundname: "Weapon_Knife.Deploy",
    pOrigin: nullptr,
    soundtime: 0.0,
    duration: nullptr);
  PlayerOwner = CWeaponCSBase::GetPlayerOwner(this);
  if ( PlayerOwner != nullptr )
  {
    v7 = g_pMDLCache;
    g_pMDLCache->BeginLock(this: g_pMDLCache);
    TeamNumber = CBaseEntity::GetTeamNumber(this: PlayerOwner);
    CBaseAnimating::SetBodygroup(this, iGroup: 0, iValue: TeamNumber != 2);
    v7->EndLock(this: v7);
  }
  v9 = CWeaponCSBase::Deploy(this);
  CRecipientFilter::~CRecipientFilter(this: &filter);
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x102ED870
// Name: public: void CKnife::Smack(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKnife::Smack(CKnife *this)
{
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // eax
  const char *v4; // eax
  int hitbox; // eax
  __int16 surfaceProps; // dx
  CBaseEntity *m_pEnt; // ecx
  signed int m_pPev; // eax
  CCSPlayer *PlayerOwner; // eax
  CCSPlayer *v10; // eax
  CCSPlayer *v11; // esi
  edict_t *v12; // [esp-8h] [ebp-BCh]
  edict_t *v13; // [esp-8h] [ebp-BCh]
  const char *v14; // [esp-4h] [ebp-B8h]
  CPASAttenuationFilter v15; // [esp+10h] [ebp-A4h] BYREF
  CEffectData data; // [esp+30h] [ebp-84h] BYREF
  CPASFilter filter; // [esp+94h] [ebp-20h] BYREF
  int savedregs; // [esp+B4h] [ebp+0h] BYREF

  if ( CWeaponCSBase::GetPlayerOwner(this) != nullptr )
  {
    m_Index = this->m_pTraceHitEnt.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    this->m_trHit.m_pEnt = m_pEntity;
    if ( m_pEntity != nullptr && (this->m_trHit.surface.flags & 4) == 0 && this->m_trHit.fraction != 1.0 )
    {
      CPASAttenuationFilter::CPASAttenuationFilter(this: &v15, entity: this, attenuation: 0.80000001);
      CRecipientFilter::UsePredictionRules(this: &v15);
      if ( this->m_trHit.m_pEnt->IsPlayer(this: this->m_trHit.m_pEnt) )
      {
        v4 = "Weapon_Knife.Stab";
        if ( this->m_lastAttackType != Secondary_Mode )
          v4 = "Weapon_Knife.Hit";
        v14 = v4;
        v12 = CBaseEntity::entindex(this);
        CBaseEntity::EmitSound(
          filter: &v15,
          iEntIndex: (int)v12,
          soundname: v14,
          pOrigin: nullptr,
          soundtime: 0.0,
          duration: nullptr);
      }
      else
      {
        v13 = CBaseEntity::entindex(this);
        CBaseEntity::EmitSound(
          filter: &v15,
          iEntIndex: (int)v13,
          soundname: "Weapon_Knife.HitWall",
          pOrigin: nullptr,
          soundtime: 0.0,
          duration: nullptr);
      }
      CRecipientFilter::~CRecipientFilter(this: &v15);
      CEffectData::CEffectData(this: &data);
      hitbox = this->m_trHit.hitbox;
      surfaceProps = this->m_trHit.surface.surfaceProps;
      m_pEnt = this->m_trHit.m_pEnt;
      data.m_vOrigin = this->m_trHit.endpos;
      data.m_vStart = this->m_trHit.startpos;
      data.m_nSurfaceProp = surfaceProps;
      data.m_nDamageType = 4;
      data.m_nHitBox = hitbox;
      m_pPev = (signed int)m_pEnt->m_Network.m_pPev;
      if ( m_pPev != 0 )
        m_pPev = (signed int)(m_pPev - (unsigned int)gpGlobals->pEdicts) >> 4;
      data.m_nEntIndex = m_pPev;
      CRecipientFilter::CRecipientFilter(this: &filter);
      filter.__vftable = (CPASFilter_vtbl *)&CPASFilter::`vftable';
      CRecipientFilter::AddRecipientsByPAS(this: &filter, origin: &data.m_vOrigin);
      PlayerOwner = CWeaponCSBase::GetPlayerOwner(this);
      CRecipientFilter::RemoveRecipient(this: &filter, player: (signed int)PlayerOwner);
      v10 = CWeaponCSBase::GetPlayerOwner(this);
      v11 = v10;
      if ( (v10->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: v10, a2: (int)&savedregs);
      data.m_vAngles = v11->m_angAbsRotation;
      data.m_fFlags = 1;
      DispatchEffect(&filter, flDelay: 0.0, pName: "KnifeSlash", &data);
      CRecipientFilter::~CRecipientFilter(this: &filter);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EDAD0
// Name: public: virtual void CKnife::WeaponIdle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKnife::WeaponIdle(CKnife *this)
{
  vgui::ToggleButton *PlayerOwner; // eax

  if ( this->m_flTimeWeaponIdle.m_Value <= gpGlobals->curtime )
  {
    PlayerOwner = (vgui::ToggleButton *)CWeaponCSBase::GetPlayerOwner(this);
    if ( PlayerOwner != nullptr && !IAI_BehaviorBridge::BehaviorBridge_IsCurTaskContinuousMove(this: PlayerOwner) )
    {
      ((void (__thiscall *)(CKnife *, _DWORD))this->SetWeaponIdleTime)(a1: this, a2: gpGlobals->curtime + 20.0);
      this->SendWeaponAnim(this, a2: 183);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EDB50
// Name: void __near * SendProxy_SendActiveLocalKnifeDataTable(class SendProp const __near *,void const __near *,void const __near *,class CSendProxyRecipients __near *,int)
// Source: json
//------------------------------------------------------------------------------
CBaseCombatWeapon *__cdecl SendProxy_SendActiveLocalKnifeDataTable(
        const SendProp *pProp,
        const void *pStruct,
        CBaseCombatWeapon *pVarData,
        CSendProxyRecipients *pRecipients)
{
  CBaseCombatCharacter *Owner; // esi
  edict_t *m_pPev; // eax

  if ( pVarData == nullptr )
    return nullptr;
  Owner = CBaseCombatWeapon::GetOwner(this: pVarData);
  if ( Owner == nullptr || !Owner->IsPlayer(this: Owner) )
    return nullptr;
  m_pPev = Owner->m_Network.m_pPev;
  if ( m_pPev != nullptr )
    CSendProxyRecipients::SetOnly(this: pRecipients, iClient: m_pPev - gpGlobals->pEdicts - 1);
  else
    CSendProxyRecipients::SetOnly(this: pRecipients, iClient: -1);
  return pVarData;
}

//------------------------------------------------------------------------------
// Address: 0x102EDCD0
// Name: void FindHullIntersection(class Vector const __near &,class CGameTrace __near &,class Vector const __near &,class Vector const __near &,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall FindHullIntersection(
        float a1@<ebp>,
        const Vector *vecSrc,
        CGameTrace *tr,
        const Vector *mins,
        const Vector *maxs,
        CBaseEntity *pEntity)
{
  float z; // eax
  float v7; // edx
  float x; // xmm3_4
  float y; // xmm4_4
  float v10; // xmm5_4
  float v11; // ecx
  int v12; // edx
  int v13; // eax
  float v14; // xmm0_4
  __int16 v15; // cx
  CBaseEntity *v16; // eax
  int v17; // ecx
  float v18; // xmm2_4
  float v19; // xmm0_4
  float v20; // xmm4_4
  float v21; // xmm5_4
  float v22; // xmm6_4
  float v23; // xmm6_4
  float v24; // xmm4_4
  float v25; // xmm5_4
  float v26; // xmm3_4
  __int128 v27; // xmm0
  __int16 v28; // kr00_2
  __int16 v29; // dx
  float v30; // xmm0_4
  float v31; // xmm0_4
  unsigned __int16 v32; // cx
  float v33; // xmm0_4
  int v34; // eax
  float v35; // xmm0_4
  const char *v36; // ecx
  int v37; // edx
  int v38; // eax
  CBaseEntity *v39; // eax
  int v40; // ecx
  float v41; // xmm0_4
  CTraceFilterSimple v42; // [esp+24h] [ebp-12Ch] BYREF
  __int128 v43; // [esp+34h] [ebp-11Ch]
  _DWORD v44[4]; // [esp+44h] [ebp-10Ch] BYREF
  float v45; // [esp+54h] [ebp-FCh]
  float v46; // [esp+58h] [ebp-F8h]
  float v47; // [esp+5Ch] [ebp-F4h]
  int v48; // [esp+64h] [ebp-ECh]
  int v49; // [esp+68h] [ebp-E8h]
  int v50; // [esp+6Ch] [ebp-E4h]
  int v51; // [esp+74h] [ebp-DCh]
  int v52; // [esp+78h] [ebp-D8h]
  int v53; // [esp+7Ch] [ebp-D4h]
  int v54; // [esp+84h] [ebp-CCh]
  char v55; // [esp+88h] [ebp-C8h]
  bool v56; // [esp+89h] [ebp-C7h]
  __int64 v57; // [esp+9Ch] [ebp-B4h] BYREF
  float v58; // [esp+A4h] [ebp-ACh] BYREF
  Vector minmaxs[2]; // [esp+A8h] [ebp-A8h] BYREF
  _BYTE tmpTrace[92]; // [esp+C0h] [ebp-90h] OVERLAPPED BYREF
  int v61; // [esp+11Ch] [ebp-34h]
  int j; // [esp+120h] [ebp-30h]
  float v63; // [esp+124h] [ebp-2Ch]
  int i; // [esp+128h] [ebp-28h]
  float *v65; // [esp+12Ch] [ebp-24h]
  float *distance; // [esp+130h] [ebp-20h]
  float *v67; // [esp+134h] [ebp-1Ch]
  Vector v68; // [esp+138h] [ebp-18h] BYREF
  Vector vecEnd; // [esp+144h] [ebp-Ch] BYREF
  float retaddr; // [esp+150h] [ebp+0h]

  vecEnd.x = a1;
  vecEnd.y = retaddr;
  z = mins->z;
  v7 = tr->endpos.z;
  v57 = *(_QWORD *)&mins->x;
  x = vecSrc->x;
  y = vecSrc->y;
  v10 = vecSrc->z;
  v58 = z;
  v11 = maxs->z;
  *(_QWORD *)&minmaxs[0].x = *(_QWORD *)&maxs->x;
  *(_QWORD *)&v68.x = *(_QWORD *)&tr->endpos.x;
  minmaxs[0].z = v11;
  v63 = 1000000.0;
  *(float *)&tmpTrace[80] = x + (float)((float)(v68.x - x) * 2.0);
  *(float *)&tmpTrace[84] = y + (float)((float)(v68.y - y) * 2.0);
  *(float *)&tmpTrace[88] = v10 + (float)((float)(v7 - v10) * 2.0);
  v68 = *(Vector *)&tmpTrace[80];
  UTIL_TraceLine(
    a1: (const IHandleEntity *)&vecEnd,
    a2: (int)tr,
    vecAbsStart: vecSrc,
    vecAbsEnd: &v68,
    mask: 0x200400Bu,
    ignore: pEntity,
    collisionGroup: 0,
    ptr: (CGameTrace *)&minmaxs[1]);
  if ( *(float *)&tmpTrace[32] >= 1.0 )
  {
    distance = (float *)&v57;
    for ( i = 2; i != 0; --i )
    {
      v68.x = *distance + *(float *)&tmpTrace[80];
      v67 = (float *)&v57 + 1;
      for ( j = 2; j != 0; --j )
      {
        v18 = *v67 + *(float *)&tmpTrace[84];
        v68.y = v18;
        v65 = &v58;
        v61 = 2;
        while ( 1 )
        {
          v19 = *v65;
          v20 = vecSrc->x;
          v21 = vecSrc->y;
          v22 = vecSrc->z;
          v46 = v18 - v21;
          v45 = v68.x - v20;
          v47 = (float)(v19 + *(float *)&tmpTrace[88]) - v22;
          v56 = (float)((float)((float)(v46 * v46) + (float)(v45 * v45)) + (float)(v47 * v47)) != 0.0;
          v53 = 0;
          v52 = 0;
          v51 = 0;
          v54 = 0;
          v55 = 1;
          v50 = 0;
          v49 = 0;
          v48 = 0;
          *(float *)v44 = v20;
          *(float *)&v44[1] = v21;
          *(float *)&v44[2] = v22;
          CTraceFilterSimple::CTraceFilterSimple(
            this: &v42,
            passedict: pEntity,
            collisionGroup: 0,
            pExtraShouldHitFunc: nullptr);
          enginetrace->TraceRay(
            this: enginetrace,
            a2: (const Ray_t *)v44,
            a3: 33570827u,
            a4: &v42,
            a5: (CGameTrace *)&minmaxs[1]);
          if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
            DebugDrawLine(
              vecAbsStart: &minmaxs[1],
              vecAbsEnd: (const Vector *)tmpTrace,
              r: 255,
              g: 0,
              b: 0,
              test: 1,
              duration: -1.0);
          v23 = *(float *)&tmpTrace[32];
          if ( *(float *)&tmpTrace[32] < 1.0 )
          {
            v24 = *(float *)&tmpTrace[4];
            v25 = *(float *)&tmpTrace[8];
            v26 = *(float *)tmpTrace;
            v27 = 0;
            *(float *)&v27 = fsqrt(
                               (float)((float)((float)(*(float *)&tmpTrace[4] - vecSrc->y)
                                             * (float)(*(float *)&tmpTrace[4] - vecSrc->y))
                                     + (float)((float)(*(float *)&tmpTrace[8] - vecSrc->z)
                                             * (float)(*(float *)&tmpTrace[8] - vecSrc->z)))
                             + (float)((float)(*(float *)tmpTrace - vecSrc->x) * (float)(*(float *)tmpTrace - vecSrc->x)));
            v43 = v27;
            if ( v63 > *(float *)&v27 )
            {
              v28 = *(_WORD *)&tmpTrace[28];
              v29 = *(_WORD *)&tmpTrace[30];
              tr->startpos = minmaxs[1];
              v30 = *(float *)&tmpTrace[12];
              tr->endpos.x = v26;
              tr->endpos.y = v24;
              tr->endpos.z = v25;
              tr->plane.normal.x = v30;
              tr->plane.normal.y = *(float *)&tmpTrace[16];
              v31 = *(float *)&tmpTrace[20];
              tr->plane.signbits = HIBYTE(v28);
              v32 = *(_WORD *)&tmpTrace[40];
              tr->plane.normal.z = v31;
              v33 = *(float *)&tmpTrace[24];
              tr->plane.type = v28;
              v34 = *(_DWORD *)&tmpTrace[36];
              tr->plane.dist = v33;
              v35 = *(float *)&tmpTrace[44];
              *(_WORD *)tr->plane.pad = v29;
              LOBYTE(v29) = tmpTrace[42];
              tr->contents = v34;
              LOBYTE(v34) = tmpTrace[43];
              tr->dispFlags = v32;
              v36 = *(const char **)&tmpTrace[48];
              tr->allsolid = v29;
              v37 = *(_DWORD *)&tmpTrace[52];
              tr->surface.name = v36;
              LOWORD(v36) = *(_WORD *)&tmpTrace[60];
              tr->startsolid = v34;
              v38 = *(_DWORD *)&tmpTrace[56];
              *(_DWORD *)&tr->surface.surfaceProps = v37;
              LOWORD(v37) = *(_WORD *)&tmpTrace[62];
              tr->hitgroup = v38;
              v39 = *(CBaseEntity **)&tmpTrace[64];
              tr->physicsbone = (__int16)v36;
              v40 = *(_DWORD *)&tmpTrace[68];
              tr->fractionleftsolid = v35;
              v41 = *(float *)&v43;
              tr->fraction = v23;
              tr->worldSurfaceIndex = v37;
              tr->m_pEnt = v39;
              tr->hitbox = v40;
              v63 = v41;
            }
          }
          v65 += 3;
          if ( --v61 == 0 )
            break;
          v18 = v68.y;
        }
        v67 += 3;
      }
      distance += 3;
    }
  }
  else
  {
    CBaseTrace::operator=(this: tr, __that: (const CBaseTrace *)&minmaxs[1]);
    v12 = *(_DWORD *)&tmpTrace[52];
    v13 = *(_DWORD *)&tmpTrace[56];
    v14 = *(float *)&tmpTrace[44];
    tr->surface.name = *(const char **)&tmpTrace[48];
    v15 = *(_WORD *)&tmpTrace[60];
    *(_DWORD *)&tr->surface.surfaceProps = v12;
    LOWORD(v12) = *(_WORD *)&tmpTrace[62];
    tr->hitgroup = v13;
    v16 = *(CBaseEntity **)&tmpTrace[64];
    tr->physicsbone = v15;
    v17 = *(_DWORD *)&tmpTrace[68];
    tr->fractionleftsolid = v14;
    tr->worldSurfaceIndex = v12;
    tr->m_pEnt = v16;
    tr->hitbox = v17;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EE150
// Name: public: virtual void CKnife::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKnife::Spawn(CKnife *this)
{
  edict_t *m_pPev; // ecx

  this->Precache(this);
  if ( this->m_iClip1.m_Value != -1 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_iClip1.m_Value = -1;
      CWeaponCSBase::Spawn(this);
      return;
    }
    m_pPev = this->m_Network.m_pPev;
    if ( m_pPev != nullptr )
      CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x4B0u);
    this->m_iClip1.m_Value = -1;
  }
  CWeaponCSBase::Spawn(this);
}

//------------------------------------------------------------------------------
// Address: 0x102EE1B0
// Name: public: bool CKnife::SwingOrStab(enum CSWeaponMode)
// Source: json
//------------------------------------------------------------------------------
bool __userpurge CKnife::SwingOrStab@<al>(CKnife *this@<ecx>, int a2@<ebx>, CSWeaponMode weaponMode)
{
  CCSPlayer *PlayerOwner; // eax
  CCSPlayer *v5; // esi
  bool result; // al
  const QAngle *(__thiscall *EyeAngles)(CBaseEntity *); // eax
  const QAngle *v8; // eax
  const CViewVectors *v9; // eax
  char v10; // bl
  float v11; // xmm0_4
  bool IsCurTaskContinuousMove; // al
  float v13; // xmm1_4
  float v14; // xmm0_4
  float m_Value; // xmm1_4
  edict_t *m_pPev; // ecx
  float v17; // xmm0_4
  float v18; // xmm1_4
  edict_t *v19; // ecx
  edict_t *v20; // edi
  CBaseEntity *m_pEnt; // ebx
  float v22; // xmm1_4
  const QAngle *AbsAngles; // eax
  const Vector *AbsOrigin; // eax
  float v25; // xmm1_4
  int m_nValue; // eax
  int v27; // edx
  int hitgroup; // eax
  float fractionleftsolid; // xmm0_4
  CBaseEntity *v30; // ecx
  int hitbox; // eax
  float v32; // xmm0_4
  edict_t *v33; // ecx
  Vector *attenuationa; // [esp+1Ch] [ebp-178h]
  PlayerAnimEvent_t attenuation; // [esp+1Ch] [ebp-178h]
  CTakeDamageInfo glassDamage; // [esp+2Ch] [ebp-168h] BYREF
  CTakeDamageInfo info; // [esp+88h] [ebp-10Ch] BYREF
  CPASAttenuationFilter filter; // [esp+E4h] [ebp-B0h] BYREF
  CGameTrace tr; // [esp+104h] [ebp-90h] BYREF
  Vector vTragetForward; // [esp+158h] [ebp-3Ch] BYREF
  Vector vecSrc; // [esp+164h] [ebp-30h] BYREF
  Vector vForward; // [esp+170h] [ebp-24h] BYREF
  Vector vecAbsEnd; // [esp+17Ch] [ebp-18h] BYREF
  bool bFirstSwing; // [esp+18Bh] [ebp-9h]
  float flDamage; // [esp+18Ch] [ebp-8h]
  bool bDidHit; // [esp+193h] [ebp-1h]
  IHandleEntity savedregs; // [esp+194h] [ebp+0h] BYREF

  PlayerOwner = CWeaponCSBase::GetPlayerOwner(this);
  v5 = PlayerOwner;
  if ( PlayerOwner == nullptr )
    return false;
  CCSPlayer::PlayerUsedKnife(this: PlayerOwner);
  EyeAngles = v5->EyeAngles;
  flDamage = (float)(weaponMode != Primary_Mode ? 32 : 48);
  v8 = EyeAngles(this: v5);
  AngleVectors(angles: v8, forward: &vForward);
  ((void (__thiscall *)(CCSPlayer *, Vector *, int))v5->Weapon_ShootPosition)(a1: v5, a2: &vecSrc, a3: a2);
  vecAbsEnd.y = vecSrc.y + (float)(vForward.y * flDamage);
  vecAbsEnd.x = vecSrc.x + (float)(vForward.x * flDamage);
  vecAbsEnd.z = vecSrc.z + (float)(vForward.z * flDamage);
  UTIL_TraceLine(
    a1: &savedregs,
    a2: (int)v5,
    vecAbsStart: &vecSrc,
    &vecAbsEnd,
    mask: 0x200400Bu,
    ignore: v5,
    collisionGroup: 0,
    ptr: &tr);
  CTakeDamageInfo::CTakeDamageInfo(
    this: &glassDamage,
    pInflictor: v5,
    pAttacker: v5,
    flDamage: 42.0,
    bitsDamageType: 4098,
    iKillType: 0,
    iObjectsPenetrated: 0);
  CBaseEntity::TraceAttackToTriggers(
    this,
    a2: (int)&savedregs,
    info: &glassDamage,
    start: &tr.startpos,
    end: &tr.endpos,
    dir: &vForward);
  if ( tr.fraction >= 1.0 )
  {
    UTIL_TraceHull(
      a1: &savedregs,
      a2: (int)v5,
      vecAbsStart: &vecSrc,
      &vecAbsEnd,
      hullMin: &head_hull_mins,
      hullMax: &head_hull_maxs,
      mask: 0x200400Bu,
      ignore: v5,
      collisionGroup: 0,
      ptr: &tr);
    if ( tr.fraction >= 1.0 )
      goto LABEL_10;
    if ( tr.m_pEnt == nullptr || CBaseEntity::IsBSPModel(this: tr.m_pEnt) )
    {
      attenuationa = &g_pGameRules->GetViewVectors(this: g_pGameRules)->m_vDuckHullMax;
      v9 = g_pGameRules->GetViewVectors(this: g_pGameRules);
      FindHullIntersection(
        a1: COERCE_FLOAT(&savedregs),
        &vecSrc,
        &tr,
        mins: &v9->m_vDuckHullMin,
        maxs: attenuationa,
        pEntity: v5);
    }
  }
  if ( tr.fraction < 1.0 )
  {
    v10 = 1;
    bDidHit = true;
    goto LABEL_11;
  }
LABEL_10:
  bDidHit = false;
  v10 = 0;
LABEL_11:
  bFirstSwing = gpGlobals->curtime > this->m_flNextPrimaryAttack.m_Value + 0.4;
  if ( weaponMode == Secondary_Mode )
  {
    this->SendWeaponAnim(this, a2: v10 != 0 ? 199 : 205);
    if ( v10 != 0 )
    {
      v11 = 1.1;
      flDamage = 1.1;
    }
    else
    {
      v11 = 1.0;
      flDamage = 1.0;
    }
    attenuation = PLAYERANIMEVENT_FIRE_GUN_SECONDARY;
  }
  else
  {
    this->SendWeaponAnim(this, a2: v10 != 0 ? 198 : 204);
    if ( v10 != 0 )
    {
      v11 = 0.5;
      flDamage = 0.5;
    }
    else
    {
      flDamage = 0.40000001;
      v11 = 0.5;
    }
    attenuation = PLAYERANIMEVENT_FIRE_GUN_PRIMARY;
  }
  vecAbsEnd.z = v11;
  CCSPlayer::DoAnimationEvent(this: v5, event: attenuation, nData: 0);
  IsCurTaskContinuousMove = IAI_BehaviorBridge::BehaviorBridge_IsCurTaskContinuousMove(this: (vgui::ToggleButton *)v5);
  v13 = flDamage;
  if ( IsCurTaskContinuousMove )
  {
    v13 = flDamage + 0.69999999;
    vecAbsEnd.z = vecAbsEnd.z + 0.69999999;
  }
  v14 = gpGlobals->curtime + v13;
  m_Value = this->m_flNextPrimaryAttack.m_Value;
  flDamage = v14;
  if ( m_Value != v14 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
      {
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x494u);
        v14 = flDamage;
      }
    }
    this->m_flNextPrimaryAttack.m_Value = v14;
  }
  v18 = this->m_flNextSecondaryAttack.m_Value;
  flDamage = gpGlobals->curtime + vecAbsEnd.z;
  v17 = flDamage;
  if ( v18 != flDamage )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v19 = this->m_Network.m_pPev;
      if ( v19 != nullptr )
      {
        CBaseEdict::StateChanged(this: &v19->CBaseEdict, offset: 0x498u);
        v17 = flDamage;
      }
    }
    this->m_flNextSecondaryAttack.m_Value = v17;
  }
  ((void (__thiscall *)(CKnife *, _DWORD))this->SetWeaponIdleTime)(a1: this, a2: gpGlobals->curtime + 2.0);
  if ( bDidHit )
  {
    m_pEnt = tr.m_pEnt;
    v5->SetAnimation(this: v5, a2: PLAYER_ATTACK1);
    ClearMultiDamage();
    if ( weaponMode == Secondary_Mode )
    {
      v22 = 65.0;
      flDamage = 65.0;
      if ( m_pEnt != nullptr )
      {
        if ( !m_pEnt->IsPlayer(this: m_pEnt) )
          goto LABEL_46;
        AbsAngles = CBaseEntity::GetAbsAngles(this: m_pEnt);
        AngleVectors(angles: AbsAngles, forward: &vTragetForward);
        LODWORD(vecAbsEnd.z) = CBaseEntity::GetAbsOrigin(this: v5);
        AbsOrigin = CBaseEntity::GetAbsOrigin(this: m_pEnt);
        v25 = AbsOrigin->y - *(float *)(LODWORD(vecAbsEnd.z) + 4);
        vecAbsEnd.y = AbsOrigin->x - *(float *)LODWORD(vecAbsEnd.z);
        vecAbsEnd.z = v25;
        Vector2DNormalize(v: (Vector2D *)&vecAbsEnd.y);
        if ( (float)((float)(vTragetForward.y * vecAbsEnd.z) + (float)(vTragetForward.x * vecAbsEnd.y)) > 0.80000001 )
          v22 = 195.0;
        else
LABEL_46:
          v22 = flDamage;
      }
    }
    else if ( bFirstSwing )
    {
      v22 = 50.0;
    }
    else
    {
      v22 = 40.0;
    }
    if ( KnifeDamageScale.m_pParent != nullptr )
      m_nValue = KnifeDamageScale.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    flDamage = (float)((float)m_nValue * 0.0099999998) * v22;
    CTakeDamageInfo::CTakeDamageInfo(
      this: &info,
      pInflictor: v5,
      pAttacker: v5,
      flDamage,
      bitsDamageType: 4098,
      iKillType: 0,
      iObjectsPenetrated: 0);
    CalculateMeleeDamageForce(&info, vecMeleeDir: &vForward, vecForceOrigin: &tr.endpos, flScale: 1.0 / flDamage);
    CBaseEntity::DispatchTraceAttack(this: m_pEnt, &info, vecDir: &vForward, ptr: &tr);
    ApplyMultiDamage();
    CBaseTrace::operator=(this: &this->m_trHit, __that: &tr);
    v27 = *(_DWORD *)&tr.surface.surfaceProps;
    hitgroup = tr.hitgroup;
    fractionleftsolid = tr.fractionleftsolid;
    this->m_trHit.surface.name = tr.surface.name;
    this->m_trHit.physicsbone = tr.physicsbone;
    v30 = tr.m_pEnt;
    *(_DWORD *)&this->m_trHit.surface.surfaceProps = v27;
    LOWORD(v27) = tr.worldSurfaceIndex;
    this->m_trHit.hitgroup = hitgroup;
    hitbox = tr.hitbox;
    this->m_trHit.fractionleftsolid = fractionleftsolid;
    this->m_trHit.worldSurfaceIndex = v27;
    this->m_trHit.m_pEnt = v30;
    this->m_trHit.hitbox = hitbox;
    if ( v30 != nullptr )
      this->m_pTraceHitEnt.m_Index = v30->GetRefEHandle(this: v30)->m_Index;
    else
      this->m_pTraceHitEnt.m_Index = -1;
    this->m_lastAttackType = weaponMode;
    if ( (float)((float)(weaponMode == Secondary_Mode) + gpGlobals->curtime) == 0.0 )
      v32 = 0.1;
    else
      v32 = 0.2;
    if ( this->m_flSmackTime.m_Value != v32 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        result = bDidHit;
        this->m_flSmackTime.m_Value = v32;
        return result;
      }
      v33 = this->m_Network.m_pPev;
      if ( v33 != nullptr )
        CBaseEdict::StateChanged(this: &v33->CBaseEdict, offset: 0x618u);
      this->m_flSmackTime.m_Value = v32;
    }
    return bDidHit;
  }
  else
  {
    CPASAttenuationFilter::CPASAttenuationFilter(this: &filter, entity: this, attenuation: 0.80000001);
    CRecipientFilter::UsePredictionRules(this: &filter);
    v20 = this->m_Network.m_pPev;
    if ( v20 != nullptr )
      v20 -= (int)gpGlobals->pEdicts;
    CBaseEntity::EmitSound(
      &filter,
      iEntIndex: (int)v20,
      soundname: "Weapon_Knife.Slash",
      pOrigin: nullptr,
      soundtime: 0.0,
      duration: nullptr);
    CRecipientFilter::~CRecipientFilter(this: &filter);
    return bDidHit;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EE850
// Name: public: virtual void CKnife::ItemPostFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKnife::ItemPostFrame(CKnife *this)
{
  float m_Value; // xmm0_4
  edict_t *m_pPev; // ecx

  m_Value = this->m_flSmackTime.m_Value;
  if ( m_Value > 0.0 && gpGlobals->curtime > m_Value )
  {
    CKnife::Smack(this);
    if ( this->m_flSmackTime.m_Value != -1.0 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x618u);
      }
      this->m_flSmackTime.m_Value = -1.0;
    }
  }
  CWeaponCSBase::ItemPostFrame(this, a2: (int)this);
}

//------------------------------------------------------------------------------
// Address: 0x102EE8D0
// Name: public: virtual enum CSWeaponID CKnife::GetCSWeaponID(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CKnife::GetCSWeaponID(CKnife *this)
{
  return 31;
}

//------------------------------------------------------------------------------
// Address: 0x102EE8E0
// Name: public: virtual void CKnife::PrimaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CKnife::PrimaryAttack(CKnife *this@<ecx>, int a2@<ebx>)
{
  CCSPlayer *PlayerOwner; // esi

  PlayerOwner = CWeaponCSBase::GetPlayerOwner(this);
  if ( PlayerOwner != nullptr )
  {
    ((void (__stdcall *)(CCSPlayer *, int, Vector *, QAngle *, _DWORD))lagcompensation->StartLagCompensation)(
      a1: PlayerOwner,
      a2: 2,
      a3: &vec3_origin,
      a4: &vec3_angle,
      a5: 0);
    CKnife::SwingOrStab(this, a2, weaponMode: Primary_Mode);
    lagcompensation->FinishLagCompensation(this: lagcompensation, a2: PlayerOwner);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102EE930
// Name: public: virtual void CKnife::SecondaryAttack(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CKnife::SecondaryAttack(CKnife *this@<ecx>, int a2@<ebx>)
{
  CCSPlayer *PlayerOwner; // eax
  CBasePlayer *v4; // esi

  PlayerOwner = CWeaponCSBase::GetPlayerOwner(this);
  v4 = PlayerOwner;
  if ( PlayerOwner != nullptr
    && !PlayerOwner->m_bIsDefusing.m_Value
    && !CCSGameRules::IsFreezePeriod(this: (CCSGameRules *)g_pGameRules) )
  {
    ((void (__stdcall *)(CBasePlayer *, int, Vector *, QAngle *, _DWORD))lagcompensation->StartLagCompensation)(
      a1: v4,
      a2: 2,
      a3: &vec3_origin,
      a4: &vec3_angle,
      a5: 0);
    CKnife::SwingOrStab(this, a2, weaponMode: Secondary_Mode);
    lagcompensation->FinishLagCompensation(this: lagcompensation, a2: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10412970
// Name: DT_LocalActiveWeaponKnifeData::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_LocalActiveWeaponKnifeData::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_LocalActiveWeaponKnifeData::g_SendTable);
  return atexit(func: DT_LocalActiveWeaponKnifeData::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10412990
// Name: DT_LocalActiveWeaponKnifeData::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_LocalActiveWeaponKnifeData::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_LocalActiveWeaponKnifeData::ignored>();
  DT_LocalActiveWeaponKnifeData::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104129A0
// Name: DT_WeaponKnife::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponKnife::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_WeaponKnife::g_SendTable);
  return atexit(func: DT_WeaponKnife::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104129C0
// Name: DT_WeaponKnife::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_WeaponKnife::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_WeaponKnife::ignored>();
  DT_WeaponKnife::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104129F0
// Name: weapon_knifePrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int weapon_knifePrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106DA8A4;
  weapon_knifePrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106DA8A4;
  dword_106DA8A4 = (int)&weapon_knifePrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10412A10
// Name: CKnife_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CKnife_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CKnife>(__formal: nullptr);
  CKnife_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420B80
// Name: DT_LocalActiveWeaponKnifeData::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_LocalActiveWeaponKnifeData::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_LocalActiveWeaponKnifeData::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10420B90
// Name: DT_WeaponKnife::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_WeaponKnife::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_WeaponKnife::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x102EE9A0
// Name: struct datamap_t __near * DataMapInit<class CKnife>(class CKnife __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CKnife>()
{
  if ( (_S4_74 & 1) == 0 )
  {
    _S4_74 |= 1u;
    nameHolder_498.m_pszBase = "CKnife";
    nameHolder_498.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_498.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_498.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_498.m_Names.m_Size = 0;
    nameHolder_498.m_Names.m_pElements = nullptr;
    nameHolder_498.m_nLenBase = 6;
    atexit(func: DataMapInit_CKnife__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CKnife::m_DataMap.baseMap = &CWeaponCSBase::m_DataMap;
  if ( (_S4_74 & 2) == 0 )
  {
    _S4_74 |= 2u;
    dataDesc_513[1].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_498,
                                  pszIdentifier: "Smack");
    dataDesc_513[1].fieldOffset = 0;
    *(_DWORD *)&dataDesc_513[1].fieldSize = 2097153;
    dataDesc_513[1].externalName = nullptr;
    dataDesc_513[1].pSaveRestoreOps = nullptr;
    dataDesc_513[1].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CKnife::Smack;
    *(_QWORD *)&dataDesc_513[1].td = 0;
    *(_QWORD *)&dataDesc_513[1].override_field = 0;
    *(_QWORD *)&dataDesc_513[1].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_513[1].flatOffset[1] = 0;
  }
  CKnife::m_DataMap.dataNumFields = 1;
  CKnife::m_DataMap.dataDesc = &dataDesc_513[1];
  return &CKnife::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10412A20
// Name: _dynamic_initializer_for__KnifeDamageScale__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__KnifeDamageScale__()
{
  ConVar::ConVar(this: &KnifeDamageScale, pName: "knife_damage_scale", pDefaultValue: "100", flags: 2);
  return atexit(func: dynamic_atexit_destructor_for__KnifeDamageScale__);
}

//------------------------------------------------------------------------------
// Address: 0x10412A50
// Name: _dynamic_initializer_for__g_CWeaponM249_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CWeaponM249_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CWeaponM249_ClassReg,
           pNetworkName: "CWeaponM249",
           pTable: &DT_WeaponM249::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10420BA0
// Name: _ServerClassInit_DT_WeaponKnife::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_WeaponKnife::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S3_161;
  for ( i = 2; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x10420BC0
// Name: _dynamic_atexit_destructor_for__KnifeDamageScale__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__KnifeDamageScale__()
{
  ConVar::~ConVar(this: &KnifeDamageScale);
}

//------------------------------------------------------------------------------
// Address: 0x10420BD0
// Name: _ServerClassInit_DT_LocalActiveWeaponKnifeData::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_LocalActiveWeaponKnifeData::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_285;
  for ( i = 1; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x10420BF0
// Name: _DataMapInit_CKnife__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CKnife__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_498);
}

} // namespace server
