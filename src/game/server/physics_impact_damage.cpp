// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/physics_impact_damage.cpp
// Functions: 4
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10190B80
// Name: float ReadDamageTable(struct impactentry_t __near *,int,float,bool)
// Source: json
//------------------------------------------------------------------------------
double __cdecl ReadDamageTable(impactentry_t *pTable, int tableCount, float impulse, bool bDebug)
{
  int v4; // esi
  impactentry_t *v5; // eax

  if ( pTable == nullptr )
    return 0.0;
  v4 = 0;
  if ( tableCount < 4 )
  {
LABEL_9:
    while ( v4 < tableCount )
    {
      if ( pTable[v4].impulse > impulse )
        break;
      ++v4;
    }
  }
  else
  {
    v5 = pTable + 2;
    while ( v5[-2].impulse <= impulse )
    {
      if ( v5[-1].impulse > impulse )
      {
        ++v4;
        break;
      }
      if ( v5->impulse > impulse )
      {
        v4 += 2;
        break;
      }
      if ( v5[1].impulse > impulse )
      {
        v4 += 3;
        break;
      }
      v4 += 4;
      v5 += 4;
      if ( v4 >= tableCount - 3 )
        goto LABEL_9;
    }
  }
  if ( v4 <= 0 )
    return 0.0;
  if ( bDebug )
    _Msg(a1: "Damage %.0f, energy %.0f\n", pTable[v4 - 1].damage, fsqrt(impulse));
  return pTable[v4 - 1].damage;
}

//------------------------------------------------------------------------------
// Address: 0x10190C80
// Name: float CalculatePhysicsImpactDamage(int,struct gamevcollisionevent_t __near *,struct impactdamagetable_t const __near &,float,bool,int __near &,bool)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
double __usercall CalculatePhysicsImpactDamage@<st0>(
        float a1@<ebp>,
        int index,
        gamevcollisionevent_t *pEvent,
        const impactdamagetable_t *table,
        float energyScale,
        bool allowStaticDamage,
        int *damageType,
        bool bDamageFromHeldObjects)
{
  void *v8; // esp
  BOOL v9; // edi
  IPhysicsObject *v11; // ecx
  char *v12; // eax
  IPhysicsObject *v13; // ecx
  IPhysicsObject_vtbl *v14; // edx
  float v15; // xmm0_4
  unsigned __int16 (__thiscall *GetGameFlags)(IPhysicsObject *); // eax
  CBasePlayer *LocalPlayer; // eax
  float largeMassMin; // xmm1_4
  double DamageTable; // st7
  IPhysicsObject *v20; // ecx
  IPhysicsObject_vtbl *v21; // edx
  float *v22; // eax
  float v23; // xmm1_4
  __int128 v24; // xmm0
  float v25; // xmm2_4
  float (__thiscall *GetMass)(IPhysicsObject *); // eax
  float v27; // xmm2_4
  __int128 v28; // xmm0
  float v29; // xmm3_4
  float *v30; // eax
  __int128 v31; // xmm0
  float v32; // xmm2_4
  float v33; // xmm1_4
  float v34; // xmm2_4
  float v35; // xmm1_4
  __int128 v36; // xmm0
  bool v37; // cf
  float v38; // xmm1_4
  float v39; // xmm3_4
  float v40; // xmm0_4
  float v41; // xmm2_4
  IPhysicsObject *v42; // ecx
  float (__thiscall *GetInvMass)(IPhysicsObject *); // eax
  bool v44; // al
  IPhysicsObject_vtbl *v45; // edx
  CGlobalVars *v46; // ecx
  float v47; // xmm0_4
  float v48; // xmm0_4
  impactentry_t *linearTable; // edx
  double v50; // st7
  IPhysicsObject *v51; // esi
  bool (__thiscall *IsStatic)(IPhysicsObject *); // edx
  CBasePlayer *v53; // eax
  double v54; // st7
  _QWORD v55[514]; // [esp+30h] [ebp-104Ch] BYREF
  __int128 v56; // [esp+1040h] [ebp-3Ch] BYREF
  float v57; // [esp+105Ch] [ebp-20h] BYREF
  float EntityMass; // [esp+1060h] [ebp-1Ch]
  float v59; // [esp+1064h] [ebp-18h]
  int v60; // [esp+1068h] [ebp-14h]
  float v61[4]; // [esp+106Ch] [ebp-10h] BYREF
  float retaddr; // [esp+107Ch] [ebp+0h]

  v61[1] = a1;
  v61[2] = retaddr;
  v8 = alloca(4168);
  *damageType = 1;
  v9 = index == 0;
  if ( pEvent->pEntities[0] == pEvent->pEntities[1]
    || (((int (__thiscall *)(IPhysicsObject *))pEvent->pObjects[v9]->GetGameFlags)(a1: pEvent->pObjects[v9]) & 0x800) != 0
    && (pEvent->pEntities[index]->IsNPC(this: pEvent->pEntities[index])
     || pEvent->pEntities[index]->IsPlayer(this: pEvent->pEntities[index])) )
  {
    return 0.0;
  }
  if ( (((int (__thiscall *)(IPhysicsObject *))pEvent->pObjects[v9]->GetGameFlags)(a1: pEvent->pObjects[v9]) & 8) != 0
    && pEvent->pEntities[index]->IsPlayer(this: pEvent->pEntities[index]) )
  {
    v11 = pEvent->pObjects[v9];
    v12 = (char *)pEvent + 12 * v9;
    v60 = (int)(v12 + 32);
    v11->GetImplicitVelocity(this: v11, a2: (Vector *)(v12 + 32), a3: (Vector *)(v12 + 80));
  }
  if ( (((int (__thiscall *)(IPhysicsObject *))pEvent->pObjects[v9]->GetGameFlags)(a1: pEvent->pObjects[v9]) & 0x200) != 0
    && (pEvent->pEntities[index]->m_iEFlags & 0x8000000) == 0 )
  {
    *damageType |= 0x4000000u;
    return 1000.0;
  }
  if ( energyScale <= 0.0
    || (((int (__thiscall *)(IPhysicsObject *))pEvent->pObjects[v9]->GetGameFlags)(a1: pEvent->pObjects[v9]) & 0x402) != 0
    || !bDamageFromHeldObjects
    && (((int (__thiscall *)(IPhysicsObject *))pEvent->pObjects[v9]->GetGameFlags)(a1: pEvent->pObjects[v9]) & 4) != 0 )
  {
    return 0.0;
  }
  if ( (((int (__thiscall *)(IPhysicsObject *))pEvent->pObjects[v9]->GetGameFlags)(a1: pEvent->pObjects[v9]) & 0x10) != 0 )
  {
    *(float *)&v60 = COERCE_FLOAT(
                       pEvent->pEntities[v9]->VPhysicsGetObjectList(
                         this: pEvent->pEntities[v9],
                         a2: (IPhysicsObject **)v55,
                         a3: 1024));
    v61[0] = 0.0;
    if ( v60 > 0 )
    {
      while ( ((*(int (__thiscall **)(_DWORD))(**((_DWORD **)v55 + LODWORD(v61[0])) + 76))(a1: *((_DWORD *)v55
                                                                                               + LODWORD(v61[0])))
             & 0x402) == 0 )
      {
        ++LODWORD(v61[0]);
        if ( SLODWORD(v61[0]) >= v60 )
          goto LABEL_20;
      }
      return 0.0;
    }
  }
LABEL_20:
  if ( (((int (__thiscall *)(IPhysicsObject *))pEvent->pObjects[index]->GetGameFlags)(a1: pEvent->pObjects[index]) & 4) != 0 )
  {
    if ( !pEvent->pEntities[v9]->IsPlayer(this: pEvent->pEntities[v9]) )
    {
      allowStaticDamage = false;
      goto LABEL_23;
    }
    return 0.0;
  }
LABEL_23:
  v13 = pEvent->pObjects[v9];
  v14 = v13->__vftable;
  v15 = (float)((float)(pEvent->preVelocity[v9].x * pEvent->preVelocity[v9].x)
              + (float)(pEvent->preVelocity[v9].y * pEvent->preVelocity[v9].y))
      + (float)(pEvent->preVelocity[v9].z * pEvent->preVelocity[v9].z);
  v60 = (int)pEvent + 12 * v9;
  GetGameFlags = v14->GetGameFlags;
  v61[0] = v15;
  v59 = 0.0;
  if ( (((int (__thiscall *)(IPhysicsObject *))GetGameFlags)(a1: v13) & 1) != 0 )
    v59 = (float)((float)(*(float *)(v60 + 80) * *(float *)(v60 + 80))
                + (float)(*(float *)(v60 + 84) * *(float *)(v60 + 84)))
        + (float)(*(float *)(v60 + 88) * *(float *)(v60 + 88));
  EntityMass = pEvent->pObjects[v9]->GetMass(this: pEvent->pObjects[v9]);
  if ( (((int (__thiscall *)(IPhysicsObject *))pEvent->pObjects[v9]->GetGameFlags)(a1: pEvent->pObjects[v9]) & 4) != 0
    && gpGlobals->maxClients == 1 )
  {
    LocalPlayer = UTIL_GetLocalPlayer();
    if ( LocalPlayer != nullptr )
      EntityMass = LocalPlayer->GetHeldObjectMass(this: LocalPlayer, a2: pEvent->pObjects[v9]);
  }
  if ( pEvent->pEntities[v9] != nullptr
    && (((int (__thiscall *)(IPhysicsObject *))pEvent->pObjects[v9]->GetGameFlags)(a1: pEvent->pObjects[v9]) & 0x10) != 0 )
  {
    EntityMass = PhysGetEntityMass(pEntity: pEvent->pEntities[v9]);
  }
  if ( (((int (__thiscall *)(IPhysicsObject *))pEvent->pObjects[v9]->GetGameFlags)(a1: pEvent->pObjects[v9]) & 0x20) != 0 )
  {
    largeMassMin = table->largeMassMin;
    EntityMass = largeMassMin;
    if ( energyScale < 2.0 )
      energyScale = 2.0;
  }
  else
  {
    largeMassMin = EntityMass;
  }
  if ( !allowStaticDamage
    && (table->minMass > largeMassMin
     || table->smallMassMax > largeMassMin && table->smallMassMinSpeedSqr > v61[0]
     || table->minSpeedSqr > v61[0] && table->minRotSpeedSqr > v59) )
  {
    return 0.0;
  }
  if ( CBaseEntity::IsFloating(this: pEvent->pEntities[index])
    && pEvent->pEntities[v9] != g_WorldEntity
    && energyScale < 3.0 )
  {
    energyScale = 3.0;
  }
  v61[0] = 0.0;
  if ( v59 > table->minRotSpeedSqr )
  {
    pEvent->pObjects[v9]->GetInertia(this: pEvent->pObjects[v9], result: (Vector *)((char *)&v56 + 4));
    DamageTable = ReadDamageTable(
                    pTable: table->angularTable,
                    tableCount: table->angularCount,
                    impulse: (float)(fabs(*(float *)(v60 + 88) * *((float *)&v56 + 3))
                          + (float)(fabs(*(float *)(v60 + 84) * *((float *)&v56 + 2))
                                  + fabs(*(float *)(v60 + 80) * *((float *)&v56 + 1))))
                  * energyScale,
                    bDebug: false);
    v61[0] = DamageTable;
    if ( DamageTable > 0.0 )
      *damageType |= 4u;
  }
  v20 = pEvent->pObjects[index];
  v21 = v20->__vftable;
  v22 = (float *)((char *)pEvent + 12 * index);
  v23 = v22[15];
  v24 = 0;
  v25 = v22[14];
  *(float *)&v24 = fsqrt((float)((float)(v22[8] * v22[8]) + (float)(v22[9] * v22[9])) + (float)(v22[10] * v22[10]));
  v56 = v24;
  *(float *)&v24 = v22[16];
  GetMass = v21->GetMass;
  v27 = (float)((float)(v25 * v25) + (float)(v23 * v23)) + (float)(*(float *)&v24 * *(float *)&v24);
  v28 = 0;
  *(float *)&v28 = fsqrt(v27);
  *(_OWORD *)&v55[512] = v28;
  v59 = *(float *)&v56 - *(float *)&v28;
  v57 = GetMass(this: v20);
  v29 = v59;
  if ( v59 > 0.0 && table->myMinVelocity > v59 )
    v29 = 0.0;
  v30 = (float *)v60;
  v31 = 0;
  v32 = *(float *)(v60 + 56);
  v33 = *(float *)(v60 + 60);
  *(float *)&v31 = fsqrt((float)((float)(v30[9] * v30[9]) + (float)(v30[10] * v30[10])) + (float)(v30[8] * v30[8]));
  *(_OWORD *)&v55[512] = v31;
  v34 = (float)(v32 * v32) + (float)(v33 * v33);
  v35 = *(float *)&v31;
  v36 = 0;
  v37 = EntityMass < table->largeMassMin;
  *(float *)&v36 = fsqrt(v34 + (float)(v30[16] * v30[16]));
  v56 = v36;
  v38 = v35 - *(float *)&v36;
  v39 = (float)(v29 * v29) * v57;
  v40 = (float)(v38 * v38) * EntityMass;
  if ( !v37 )
  {
    v40 = v40 * table->largeMassScale;
    v41 = *(float *)(v60 + 40) - *(float *)(v60 + 64);
    if ( v38 > 0.0 && v41 < 0.0 && *(float *)(v60 + 40) < 0.0 )
      v40 = v40
          * (float)((float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(v41 / v38) & _mask__AbsFloat_)
                          * (float)(table->largeMassFallingScale - 1.0))
                  + 1.0);
  }
  v42 = pEvent->pObjects[index];
  GetInvMass = v42->GetInvMass;
  v59 = v40 + v39;
  *(float *)&v60 = GetInvMass(this: v42);
  v44 = pEvent->pObjects[index]->IsMoveable(this: pEvent->pObjects[index]);
  v45 = pEvent->pObjects[index]->__vftable;
  if ( v44 )
  {
    if ( (((int (*)(void))v45->GetGameFlags)() & 4) != 0 )
    {
      v46 = gpGlobals;
      if ( gpGlobals->maxClients == 1 )
      {
        v53 = UTIL_GetLocalPlayer();
        if ( v53 != nullptr )
        {
          v54 = ((double (__thiscall *)(CBasePlayer *, IPhysicsObject *))v53->GetHeldObjectMass)(
                  a1: v53,
                  a2: pEvent->pObjects[index]);
          v57 = v54;
          if ( v54 > 0.0 )
          {
            v47 = 1.0 / v57;
            goto LABEL_60;
          }
        }
      }
    }
  }
  else
  {
    *(float *)&v60 = 1.0 / ((double (*)(void))v45->GetMass)();
  }
  v47 = *(float *)&v60;
LABEL_60:
  v48 = (float)(v47 * energyScale) * v59;
  linearTable = table->linearTable;
  v59 = *(float *)&v46;
  v50 = ReadDamageTable(pTable: linearTable, tableCount: table->linearCount, impulse: v48, bDebug: false);
  v51 = pEvent->pObjects[v9];
  IsStatic = v51->IsStatic;
  v61[0] = v50 + v61[0];
  if ( IsStatic(this: v51) || table->smallMassMax <= EntityMass || table->smallMassCap <= 0.0 )
    return v61[0];
  v57 = 0.0;
  return clamp<float,int,float>(val: v61, minVal: (const int *)&v57, maxVal: &table->smallMassCap);
}

//------------------------------------------------------------------------------
// Address: 0x10191330
// Name: float CalculateDefaultPhysicsDamage(int,struct gamevcollisionevent_t __near *,float,bool,int __near &,struct string_t,bool)
// Source: json
//------------------------------------------------------------------------------
double __cdecl CalculateDefaultPhysicsDamage(
        int index,
        gamevcollisionevent_t *pEvent,
        float energyScale,
        bool allowStaticDamage,
        int *damageType,
        string_t iszDamageTableName,
        bool bDamageFromHeldObjects)
{
  const char *pszValue; // eax
  int v8; // esi
  int savedregs; // [esp+14h] [ebp+0h] BYREF

  pszValue = iszDamageTableName.pszValue;
  if ( iszDamageTableName.pszValue == nullptr )
    return CalculatePhysicsImpactDamage(
             a1: COERCE_FLOAT(&savedregs),
             index,
             pEvent,
             table: &gDefaultNPCImpactDamageTable,
             energyScale,
             allowStaticDamage,
             damageType,
             bDamageFromHeldObjects);
  v8 = 0;
  while ( 1 )
  {
    if ( pszValue == nullptr )
      pszValue = locale;
    if ( _V_strcmp(s1: gDamageTableRegistry[v8].pszTableName, s2: pszValue) == 0 )
      break;
    if ( (unsigned int)++v8 >= 4 )
    {
      _Warning(a1: "Failed to find custom physics damage table name: %s\n", iszDamageTableName.pszValue);
      return CalculatePhysicsImpactDamage(
               a1: COERCE_FLOAT(&savedregs),
               index,
               pEvent,
               table: &gDefaultNPCImpactDamageTable,
               energyScale,
               allowStaticDamage,
               damageType,
               bDamageFromHeldObjects);
    }
    pszValue = iszDamageTableName.pszValue;
  }
  return CalculatePhysicsImpactDamage(
           a1: COERCE_FLOAT(&savedregs),
           index,
           pEvent,
           table: gDamageTableRegistry[v8].pTable,
           energyScale,
           allowStaticDamage,
           damageType,
           bDamageFromHeldObjects);
}

//------------------------------------------------------------------------------
// Address: 0x101913F0
// Name: float CalculateObjectStress(class IPhysicsObject __near *,class CBaseEntity __near *,struct vphysics_objectstress_t __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
double __usercall CalculateObjectStress@<st0>(
        float a1@<ebp>,
        int a2@<edi>,
        int a3@<esi>,
        IPhysicsObject *pObject,
        CBaseEntity *pInputOwnerEntity,
        vphysics_objectstress_t *pOutput)
{
  CBaseEntity *v6; // esi
  CBaseEntity **m_pMemory; // edi
  int v8; // eax
  CBaseEntity **v9; // esi
  CBaseEntity *v10; // ecx
  CBaseEntity **v11; // edi
  CBaseEntity_vtbl **v12; // eax
  int v13; // eax
  IPhysicsObject *v14; // edi
  IPhysicsObject_vtbl *v15; // edx
  int v16; // esi
  float (__thiscall *GetMass)(IPhysicsObject *); // eax
  double v18; // st7
  _DWORD *v19; // eax
  int v20; // edx
  CWorld *WorldEntity; // edi
  unsigned int m_Index; // ecx
  int v23; // eax
  CEntInfo *v24; // edx
  unsigned int v25; // ecx
  int v26; // eax
  bool v27; // zf
  float *v28; // eax
  float v29; // eax
  int v30; // edi
  CBaseEntity **v31; // ecx
  CBaseEntity **v32; // eax
  CBaseEntity **v33; // esi
  CBaseEntity **v34; // ecx
  float *v35; // eax
  int v36; // eax
  int v37; // eax
  float *v38; // eax
  float v39; // xmm2_4
  float v40; // xmm3_4
  float v41; // xmm0_4
  _DWORD *v42; // eax
  int v43; // eax
  float v44; // xmm4_4
  float x; // xmm5_4
  float v46; // xmm6_4
  _DWORD *v47; // edx
  float *v48; // ecx
  float *v49; // edx
  __int128 v50; // xmm0
  float v51; // xmm0_4
  float v52; // xmm0_4
  float v53; // xmm2_4
  float v54; // xmm7_4
  float v55; // xmm0_4
  float v56; // xmm0_4
  float v57; // xmm1_4
  void (__thiscall *GetGravity)(IPhysicsEnvironment *, Vector *); // eax
  __int128 v59; // xmm0
  IPhysicsShadowController *(__thiscall *GetShadowController)(IPhysicsObject *); // eax
  void (__thiscall *GetLastImpulse)(IPhysicsShadowController *, Vector *); // edx
  int v62; // ecx
  float (__thiscall *GetSimulationTimestep)(IPhysicsEnvironment *); // edx
  __int128 v64; // xmm0
  double v65; // st7
  float v66; // xmm5_4
  float v67; // xmm6_4
  float v68; // xmm4_4
  double v69; // st7
  __int128 v70; // xmm1
  float v71; // xmm0_4
  float v72; // xmm1_4
  float v73; // xmm3_4
  float v74; // xmm2_4
  __int128 v75; // xmm0
  double v76; // st7
  double v77; // st7
  float v78; // xmm0_4
  float v79; // xmm3_4
  float y; // xmm2_4
  float z; // xmm1_4
  float v82; // xmm0_4
  bool (__thiscall *IsMoveable)(IPhysicsObject *); // eax
  bool (__thiscall *IsStatic)(IPhysicsObject *); // eax
  float v85; // xmm0_4
  bool v86; // sf
  bool v87; // of
  char v88; // dl
  __int128 v89; // xmm0
  float v93[3]; // [esp-Ch] [ebp-A8h] BYREF
  __int128 gravVector; // [esp+0h] [ebp-9Ch] OVERLAPPED
  __int128 v95; // [esp+10h] [ebp-8Ch]
  int v96; // [esp+24h] [ebp-78h]
  _DWORD *v97; // [esp+28h] [ebp-74h]
  _DWORD *v98; // [esp+2Ch] [ebp-70h] BYREF
  IPhysicsFrictionSnapshot *pSnapshot; // [esp+30h] [ebp-6Ch]
  IPhysicsObject *pOther; // [esp+34h] [ebp-68h]
  CUtlVector<Vector,CUtlMemory<Vector,int> > objectForce; // [esp+38h] [ebp-64h]
  CBaseEntity *pOtherEntity; // [esp+4Ch] [ebp-50h] BYREF
  int force; // [esp+50h] [ebp-4Ch]
  float objMass; // [esp+54h] [ebp-48h]
  CUtlVector<CBaseEntity *,CUtlMemory<CBaseEntity *,int> > pObjectList; // [esp+58h] [ebp-44h] BYREF
  Vector lastVel; // [esp+6Ch] [ebp-30h] BYREF
  _BYTE externalForce_3[17]; // [esp+7Bh] [ebp-21h] OVERLAPPED BYREF
  Vector negativeForce; // [esp+8Ch] [ebp-10h]
  float retaddr; // [esp+9Ch] [ebp+0h]

  negativeForce.y = a1;
  negativeForce.z = retaddr;
  pOtherEntity = nullptr;
  force = 0;
  objMass = 0.0;
  pObjectList.m_Memory.m_pMemory = nullptr;
  pObjectList.m_Memory.m_nAllocationCount = 0;
  v98 = nullptr;
  pSnapshot = nullptr;
  pOther = nullptr;
  objectForce.m_Memory.m_pMemory = nullptr;
  objectForce.m_Memory.m_nAllocationCount = 0;
  externalForce_3[0] = 0;
  CUtlMemory<CNavLadder *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)&pOtherEntity, num: 1);
  v6 = pOtherEntity;
  m_pMemory = (CBaseEntity **)((char *)pObjectList.m_Memory.m_pMemory + 1);
  v8 = (int)pObjectList.m_Memory.m_pMemory++;
  pObjectList.m_Memory.m_nAllocationCount = (int)pOtherEntity;
  if ( v8 > 0 )
    _V_memmove(dest: &pOtherEntity->m_pfnMoveDone, src: pOtherEntity, count: 4 * v8);
  if ( v6 != nullptr )
    v6->__vftable = nullptr;
  CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
    this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&v98,
    elem: 0,
    src: (const QAngle *)&vec3_origin);
  v9 = m_pMemory;
  if ( (int)m_pMemory + 1 > force )
  {
    CUtlMemory<CNavLadder *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&pOtherEntity,
      num: (int)m_pMemory - force + 1);
    m_pMemory = pObjectList.m_Memory.m_pMemory;
  }
  v10 = pOtherEntity;
  v11 = (CBaseEntity **)((char *)m_pMemory + 1);
  pObjectList.m_Memory.m_pMemory = v11;
  pObjectList.m_Memory.m_nAllocationCount = (int)pOtherEntity;
  if ( (char *)v11 - (char *)v9 - 1 > 0 )
  {
    _V_memmove(
      dest: &pOtherEntity->m_pfnMoveDone + (_DWORD)v9,
      src: &pOtherEntity->__vftable + (_DWORD)v9,
      count: 4 * ((char *)v11 - (char *)v9 - 1));
    v10 = pOtherEntity;
  }
  v12 = &v10->__vftable + (_DWORD)v9;
  if ( v12 != nullptr )
    *v12 = nullptr;
  CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
    this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&v98,
    elem: (int)objectForce.m_Memory.m_pMemory,
    src: (const QAngle *)&vec3_origin);
  v13 = ((int (__thiscall *)(CBaseEntity *, int, int))pInputOwnerEntity->MyCombatCharacterPointer)(
          a1: pInputOwnerEntity,
          a2,
          a3);
  v14 = pObject;
  v15 = pObject->__vftable;
  *(_DWORD *)&externalForce_3[1] = v13;
  v16 = (int)v15->CreateFrictionSnapshot(this: pObject);
  GetMass = pObject->GetMass;
  v96 = v16;
  *(float *)&objectForce.m_pElements = GetMass(this: pObject);
  if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v16 + 4))(a1: v16) != 0 )
  {
    while ( 1 )
    {
      v18 = ((double (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)v16 + 24))(a1: v16);
      *(float *)&objectForce.m_Size = v18;
      if ( v18 > 0.0 )
        break;
LABEL_52:
      (*(void (__thiscall **)(int))(*(_DWORD *)v16 + 48))(a1: v16);
      if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v16 + 4))(a1: v16) == 0 )
        goto LABEL_53;
    }
    v19 = (_DWORD *)(*(int (__thiscall **)(int, int))(*(_DWORD *)v16 + 8))(a1: v16, a2: 1);
    v20 = *v19;
    v97 = v19;
    WorldEntity = (CWorld *)(*(int (__thiscall **)(_DWORD *))(v20 + 68))(a1: v19);
    objectForce.m_Memory.m_nGrowSize = (int)WorldEntity;
    if ( WorldEntity == nullptr )
    {
      WorldEntity = GetWorldEntity();
      objectForce.m_Memory.m_nGrowSize = (int)WorldEntity;
    }
    m_Index = WorldEntity->m_hOwnerEntity.m_Value.m_Index;
    LODWORD(negativeForce.x) = WorldEntity;
    if ( m_Index != -1 )
    {
      v23 = (unsigned __int16)m_Index;
      v24 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
      v25 = HIWORD(m_Index);
      if ( v24->m_SerialNumber == v25 && v24->m_pEntity != nullptr )
      {
        v26 = v23;
        v27 = g_pEntityList->m_EntPtrArray[v26].m_SerialNumber == v25;
        v28 = (float *)&g_pEntityList->m_EntPtrArray[v26];
        if ( v27 )
          v29 = *v28;
        else
          v29 = 0.0;
        negativeForce.x = v29;
      }
    }
    if ( (*(unsigned __int8 (__thiscall **)(_DWORD *))(*v97 + 40))(a1: v97) != 0 )
    {
      if ( *(_DWORD *)&externalForce_3[1] != 0
        && ((*(int (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)&externalForce_3[1] + 1252))(
              a1: *(_DWORD *)&externalForce_3[1],
              a2: LODWORD(negativeForce.x)) == 3
         || WorldEntity->m_flNavIgnoreUntilTime >= gpGlobals->curtime) )
      {
        v30 = 1;
      }
      else if ( ((*(int (__thiscall **)(_DWORD *))(*v97 + 76))(a1: v97) & 4) != 0 )
      {
        v30 = 1;
      }
      else
      {
        if ( ((double (__thiscall *)(_DWORD *))*(_DWORD *)(*v97 + 116))(a1: v97) >= 500.0
          && CBaseEntity::GetGroundEntity(this: pInputOwnerEntity) != WorldEntity )
        {
          externalForce_3[0] = 1;
        }
        v31 = pObjectList.m_Memory.m_pMemory;
        v32 = (CBaseEntity **)((char *)pObjectList.m_Memory.m_pMemory - 1);
        v30 = (int)pObjectList.m_Memory.m_pMemory;
        if ( (int)pObjectList.m_Memory.m_pMemory - 1 < 2 )
          goto LABEL_38;
        while ( *((_DWORD *)&pOtherEntity->__vftable + (_DWORD)v32) != LODWORD(negativeForce.x) )
        {
          v32 = (CBaseEntity **)((char *)v32 - 1);
          if ( (int)v32 < 2 )
            goto LABEL_38;
        }
        v30 = (int)v32;
        if ( v32 == pObjectList.m_Memory.m_pMemory )
        {
LABEL_38:
          v33 = pObjectList.m_Memory.m_pMemory;
          if ( (int)pObjectList.m_Memory.m_pMemory + 1 > force )
          {
            CUtlMemory<CNavLadder *,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)&pOtherEntity,
              num: (int)pObjectList.m_Memory.m_pMemory - force + 1);
            v31 = pObjectList.m_Memory.m_pMemory;
          }
          v34 = (CBaseEntity **)((char *)v31 + 1);
          pObjectList.m_Memory.m_pMemory = v34;
          pObjectList.m_Memory.m_nAllocationCount = (int)pOtherEntity;
          if ( (char *)v34 - (char *)v33 - 1 > 0 )
            _V_memmove(
              dest: &pOtherEntity->m_pfnMoveDone + (_DWORD)v33,
              src: &pOtherEntity->__vftable + (_DWORD)v33,
              count: 4 * ((char *)v34 - (char *)v33 - 1));
          v35 = (float *)(&pOtherEntity->__vftable + (_DWORD)v33);
          if ( v35 != nullptr )
            *v35 = negativeForce.x;
          CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
            this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&v98,
            elem: (int)objectForce.m_Memory.m_pMemory,
            src: (const QAngle *)&vec3_origin);
        }
        if ( v30 == 0 )
          goto LABEL_51;
      }
      if ( pInputOwnerEntity->m_MoveType.m_Value != 6 && *(_BYTE *)(objectForce.m_Memory.m_nGrowSize + 214) != 6 )
      {
        if ( (*(int (__thiscall **)(_DWORD *))(*v97 + 284))(a1: v97) == 0
          || (v36 = (*(int (__thiscall **)(_DWORD *))(*v97 + 284))(a1: v97),
              (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v36 + 32))(a1: v36) == 0) )
        {
          objectForce.m_Size = 0;
        }
      }
    }
    else
    {
      v30 = 0;
    }
LABEL_51:
    (*(void (__thiscall **)(int, int *))(*(_DWORD *)v96 + 20))(a1: v96, a2: &pObjectList.m_Memory.m_nGrowSize);
    v16 = v96;
    v37 = 3 * v30;
    v14 = pObject;
    v38 = (float *)&v98[v37];
    v39 = *(float *)&pObjectList.m_pElements * *(float *)&objectForce.m_Size;
    v40 = *v38 + (float)(*(float *)&pObjectList.m_Memory.m_nGrowSize * *(float *)&objectForce.m_Size);
    v38[1] = v38[1] + (float)(*(float *)&pObjectList.m_Size * *(float *)&objectForce.m_Size);
    v41 = v38[2] + v39;
    *v38 = v40;
    v38[2] = v41;
    goto LABEL_52;
  }
LABEL_53:
  v14->DestroyFrictionSnapshot(this: v14, a2: (IPhysicsFrictionSnapshot *)v16);
  v42 = v98;
  v98[3] = 0;
  v42[4] = 0;
  v42[5] = 0;
  v43 = (int)pObjectList.m_Memory.m_pMemory - 1;
  v44 = 0.0;
  *(Vector *)&externalForce_3[5] = vec3_origin;
  x = vec3_origin.x;
  *(Vector *)&pObjectList.m_Memory.m_nGrowSize = vec3_origin;
  v46 = vec3_origin.x;
  negativeForce.x = 0.0;
  if ( (int)pObjectList.m_Memory.m_pMemory - 1 < 0 )
  {
    v56 = *(float *)&externalForce_3[13];
    v53 = *(float *)&externalForce_3[9];
    v57 = *(float *)&pObjectList.m_pElements;
    v54 = *(float *)&pObjectList.m_Size;
  }
  else
  {
    v47 = &v98[3 * v43];
    v48 = (float *)(v47 + 1);
    v49 = (float *)(v47 + 2);
    do
    {
      v50 = 0;
      *(float *)&v50 = fsqrt((float)((float)(*v48 * *v48) + (float)(*(v48 - 1) * *(v48 - 1))) + (float)(v48[1] * v48[1]));
      v95 = v50;
      v51 = *(v49 - 2);
      v44 = v44 + *(float *)&v95;
      if ( v51 >= 0.0 )
        v46 = v46 + v51;
      else
        x = x - v51;
      v52 = *(v49 - 1);
      v53 = *(float *)&externalForce_3[9];
      v54 = *(float *)&pObjectList.m_Size;
      if ( v52 >= 0.0 )
      {
        v54 = *(float *)&pObjectList.m_Size + v52;
        *(float *)&pObjectList.m_Size = *(float *)&pObjectList.m_Size + v52;
      }
      else
      {
        v53 = *(float *)&externalForce_3[9] - v52;
        *(float *)&externalForce_3[9] = *(float *)&externalForce_3[9] - v52;
      }
      v55 = *v49;
      if ( *v49 >= 0.0 )
      {
        v57 = *(float *)&pObjectList.m_pElements + v55;
        v56 = *(float *)&externalForce_3[13];
        *(float *)&pObjectList.m_pElements = v57;
      }
      else
      {
        v56 = *(float *)&externalForce_3[13] - v55;
        v57 = *(float *)&pObjectList.m_pElements;
        *(float *)&externalForce_3[13] = v56;
      }
      v48 -= 3;
      v49 -= 3;
      --v43;
    }
    while ( v43 >= 0 );
    negativeForce.x = v44;
  }
  lastVel = vec3_origin;
  if ( v46 <= x )
  {
    *(float *)&externalForce_3[5] = x - v46;
    lastVel.x = v46;
  }
  else
  {
    *(float *)&externalForce_3[5] = v46 - x;
    lastVel.x = x;
  }
  if ( v54 <= v53 )
  {
    *(float *)&externalForce_3[9] = v53 - v54;
    lastVel.y = v54;
  }
  else
  {
    *(float *)&externalForce_3[9] = v54 - v53;
    lastVel.y = v53;
  }
  if ( v57 <= v56 )
  {
    *(float *)&externalForce_3[13] = v56 - v57;
    lastVel.z = v57;
  }
  else
  {
    *(float *)&externalForce_3[13] = v57 - v56;
    lastVel.z = v56;
  }
  GetGravity = physenv->GetGravity;
  LODWORD(negativeForce.x) = v93;
  ((void (__thiscall *)(IPhysicsEnvironment *))GetGravity)(a1: physenv);
  v27 = pInputOwnerEntity->m_MoveType.m_Value == 6;
  *(float *)&externalForce_3[1] = v93[1] * v93[1];
  v59 = 0;
  *(float *)&v59 = fsqrt((float)((float)(v93[1] * v93[1]) + (float)(v93[2] * v93[2])) + (float)(v93[0] * v93[0]));
  v95 = v59;
  if ( v27 || !v14->IsMoveable(this: v14) )
  {
    v66 = *(float *)&externalForce_3[9];
    v68 = *(float *)&externalForce_3[5];
    v67 = *(float *)&externalForce_3[13];
LABEL_93:
    z = lastVel.z;
    y = lastVel.y;
    v79 = lastVel.x;
    goto LABEL_94;
  }
  GetShadowController = v14->GetShadowController;
  memset(&pObjectList.m_Memory.m_nGrowSize, 0, 12);
  if ( (int)GetShadowController(this: v14) != 0 )
  {
    GetLastImpulse = v14->GetShadowController(this: v14)->GetLastImpulse;
    ((void (__stdcall *)(int *))GetLastImpulse)(a1: &pObjectList.m_Memory.m_nGrowSize);
  }
  else if ( (((int (__thiscall *)(IPhysicsObject *))v14->GetCallbackFlags)(a1: v14) & 0x2000) != 0 )
  {
    v62 = pInputOwnerEntity->IsPlayer(this: pInputOwnerEntity) ? LODWORD(pInputOwnerEntity[3].m_vecOrigin.m_Value.x) : 0;
    if ( v62 != 0 )
      (*(void (__stdcall **)(int *))(*(_DWORD *)v62 + 44))(a1: &pObjectList.m_Memory.m_nGrowSize);
  }
  GetSimulationTimestep = physenv->GetSimulationTimestep;
  v64 = 0;
  *(float *)&v64 = fsqrt(
                     (float)((float)(*(float *)&pObjectList.m_Size * *(float *)&pObjectList.m_Size)
                           + (float)(*(float *)&pObjectList.m_pElements * *(float *)&pObjectList.m_pElements))
                   + (float)(*(float *)&pObjectList.m_Memory.m_nGrowSize * *(float *)&pObjectList.m_Memory.m_nGrowSize));
  gravVector = v64;
  v65 = ((double (__thiscall *)(IPhysicsEnvironment *))GetSimulationTimestep)(a1: physenv);
  v66 = *(float *)&externalForce_3[9];
  v67 = *(float *)&externalForce_3[13];
  v68 = *(float *)&externalForce_3[5];
  v69 = 1.0 / v65 * *(float *)&gravVector * *(float *)&objectForce.m_pElements;
  *(float *)&externalForce_3[1] = v69;
  if ( v69 <= 0.0 )
    goto LABEL_93;
  v70 = 0;
  *(float *)&v70 = fsqrt(
                     (float)((float)(*(float *)&externalForce_3[9] * *(float *)&externalForce_3[9])
                           + (float)(*(float *)&externalForce_3[13] * *(float *)&externalForce_3[13]))
                   + (float)(*(float *)&externalForce_3[5] * *(float *)&externalForce_3[5]));
  gravVector = v70;
  if ( *(float *)&externalForce_3[1] <= *(float *)&v70 )
    goto LABEL_93;
  v71 = 1.0 - (float)(*(float *)&gravVector / *(float *)&externalForce_3[1]);
  v72 = *(float *)&externalForce_3[5] * v71;
  v73 = *(float *)&externalForce_3[13] * v71;
  *(float *)&externalForce_3[5] = (float)(*(float *)&externalForce_3[5] * v71) + *(float *)&externalForce_3[5];
  *(float *)&externalForce_3[9] = (float)(*(float *)&externalForce_3[9] * v71) + *(float *)&externalForce_3[9];
  v74 = (float)(v66 * v71) * (float)(v66 * v71);
  v75 = 0;
  *(float *)&v75 = fsqrt((float)(v74 + (float)(v73 * v73)) + (float)(v72 * v72));
  gravVector = v75;
  negativeForce.x = negativeForce.x - *(float *)&v75;
  v76 = VectorNormalize(vec: &lastVel);
  v77 = v76 - *(float *)&gravVector;
  *(float *)&externalForce_3[1] = v77;
  if ( v77 >= 0.0 )
    v78 = *(float *)&externalForce_3[1];
  else
    v78 = 0.0;
  v67 = *(float *)&externalForce_3[13];
  v68 = *(float *)&externalForce_3[5];
  v66 = *(float *)&externalForce_3[9];
  v79 = lastVel.x * v78;
  y = lastVel.y * v78;
  z = lastVel.z * v78;
LABEL_94:
  v82 = 1.0;
  if ( *(float *)&v95 > 0.0 )
    v82 = 1.0 / *(float *)&v95;
  IsMoveable = v14->IsMoveable;
  negativeForce.x = v82 * negativeForce.x;
  *(float *)&externalForce_3[5] = v68 * v82;
  *(float *)&externalForce_3[9] = v66 * v82;
  *(float *)&externalForce_3[13] = v67 * v82;
  lastVel.x = v79 * v82;
  lastVel.y = y * v82;
  lastVel.z = z * v82;
  if ( IsMoveable(this: v14) )
  {
    if ( negativeForce.x <= *(float *)&objectForce.m_pElements )
      goto LABEL_102;
    v85 = (float)((float)(negativeForce.x - *(float *)&objectForce.m_pElements) * 0.5)
        + *(float *)&objectForce.m_pElements;
  }
  else
  {
    IsStatic = v14->IsStatic;
    lastVel = *(Vector *)&externalForce_3[5];
    memset(&externalForce_3[5], 0, 12);
    if ( IsStatic(this: v14) )
      goto LABEL_102;
    v85 = negativeForce.x + *(float *)&objectForce.m_pElements;
  }
  negativeForce.x = v85;
LABEL_102:
  if ( pOutput != nullptr )
  {
    v87 = __OFSUB__(pObjectList.m_Memory.m_pMemory, 2);
    v27 = pObjectList.m_Memory.m_pMemory == (CBaseEntity **)2;
    v86 = (int)pObjectList.m_Memory.m_pMemory - 2 < 0;
    v88 = externalForce_3[0];
    LODWORD(v95) = fsqrt(
                     (float)((float)(*(float *)&externalForce_3[9] * *(float *)&externalForce_3[9])
                           + (float)(*(float *)&externalForce_3[13] * *(float *)&externalForce_3[13]))
                   + (float)(*(float *)&externalForce_3[5] * *(float *)&externalForce_3[5]));
    LODWORD(pOutput->exertedStress) = v95;
    *(float *)&externalForce_3[1] = lastVel.y * lastVel.y;
    v89 = 0;
    *(float *)&v89 = fsqrt(
                       (float)((float)(lastVel.y * lastVel.y) + (float)(lastVel.z * lastVel.z))
                     + (float)(lastVel.x * lastVel.x));
    v95 = v89;
    LODWORD(pOutput->receivedStress) = v89;
    pOutput->hasNonStaticStress = !(v86 ^ v87 | v27);
    pOutput->hasLargeObjectContact = v88;
  }
  if ( (int)pOther >= 0 && v98 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v98);
  if ( objMass >= 0.0 && pOtherEntity != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pOtherEntity);
  return negativeForce.x;
}
