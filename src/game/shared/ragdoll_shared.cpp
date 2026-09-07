// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/ragdoll_shared.cpp
// Functions: 27
// ============================================================

#include "game\shared\ragdoll_shared.h"

//------------------------------------------------------------------------------
// Address: 0x10161710
// Name: void RagdollSetupAnimatedFriction(class IPhysicsEnvironment __near *,struct ragdoll_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall RagdollSetupAnimatedFriction(
        int a1@<esi>,
        IPhysicsEnvironment *pPhysEnv,
        ragdoll_t *ragdoll,
        int iModelIndex)
{
  vcollide_t *v4; // eax
  int v5; // esi
  const char *v6; // eax

  v4 = modelinfo->GetVCollide(this: modelinfo, a2: iModelIndex);
  if ( v4 != nullptr )
  {
    v5 = ((int (__thiscall *)(IPhysicsCollision *, vcollide_t *, int))physcollision->VPhysicsKeyParserCreate)(
           a1: physcollision,
           a2: v4,
           a3: a1);
    while ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 8))(a1: v5) == 0 )
    {
      v6 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v5 + 4))(a1: v5);
      if ( _V_stricmp(s1: v6, s2: "animatedfriction") != 0 )
        (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 36))(a1: v5);
      else
        (*(void (__thiscall **)(int, ragdollanimatedfriction_t *, _DWORD))(*(_DWORD *)v5 + 44))(
          a1: v5,
          a2: &ragdoll->animfriction,
          a3: 0);
    }
    ((void (__thiscall *)(IPhysicsCollision *))physcollision->VPhysicsKeyParserDestroy)(a1: physcollision);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101617B0
// Name: void RagdollDestroy(struct ragdoll_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RagdollDestroy(ragdoll_t *ragdoll)
{
  int v1; // ebx
  IPhysicsConstraint **p_pConstraint; // esi
  int v3; // ebx
  IPhysicsObject **p_pObject; // esi

  if ( ragdoll->listCount != 0 )
  {
    v1 = 0;
    if ( ragdoll->listCount > 0 )
    {
      p_pConstraint = &ragdoll->list[0].pConstraint;
      do
      {
        physenv->DestroyConstraint(this: physenv, a2: *p_pConstraint);
        *p_pConstraint = nullptr;
        ++v1;
        p_pConstraint += 6;
      }
      while ( v1 < ragdoll->listCount );
    }
    v3 = 0;
    if ( ragdoll->listCount > 0 )
    {
      p_pObject = &ragdoll->list[0].pObject;
      do
      {
        if ( *p_pObject != nullptr )
          physenv->DestroyObject(this: physenv, a2: *p_pObject);
        *p_pObject = nullptr;
        ++v3;
        p_pObject += 6;
      }
      while ( v3 < ragdoll->listCount );
    }
    physenv->DestroyConstraintGroup(this: physenv, a2: ragdoll->pGroup);
    ragdoll->pGroup = nullptr;
    ragdoll->listCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10161840
// Name: bool RagdollIsAsleep(struct ragdoll_t const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl RagdollIsAsleep(const ragdoll_t *ragdoll)
{
  int v1; // edi
  IPhysicsObject **i; // esi

  v1 = 0;
  if ( ragdoll->listCount <= 0 )
    return 1;
  for ( i = &ragdoll->list[0].pObject; *i == nullptr || (*i)->IsAsleep(this: *i); i += 6 )
  {
    if ( ++v1 >= ragdoll->listCount )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10161880
// Name: public: virtual void CRagdollLRURetirement::FrameUpdatePostEntityThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRagdollLRURetirement::FrameUpdatePostEntityThink(CRagdollLRURetirement *this)
{
  ((void (__stdcall *)(_DWORD))this->Update)(a1: 0);
}

//------------------------------------------------------------------------------
// Address: 0x101618A0
// Name: void RagdollSetupCollisions(struct ragdoll_t __near &,struct vcollide_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall RagdollSetupCollisions(int a1@<ebx>, ragdoll_t *ragdoll, vcollide_t *pCollide, unsigned int modelIndex)
{
  IPhysicsCollisionSet *v5; // ebx
  IVPhysicsKeyParser *v6; // esi
  const char *v7; // eax
  void (__thiscall *ParseCollisionRules)(IVPhysicsKeyParser *, ragdollcollisionrules_t *, IVPhysicsKeyHandler *); // edx
  ragdoll_t *v9; // ecx
  int listCount; // eax
  int v11; // edi
  int v12; // esi
  int v13; // esi
  int *p_parentIndex; // edi
  ragdollcollisionrules_t rules; // [esp+4h] [ebp-8h] BYREF
  char bFoundRules_3; // [esp+1Bh] [ebp+Fh]

  if ( pCollide != nullptr && physics->FindCollisionSet(this: physics, a2: modelIndex) == nullptr )
  {
    v5 = (IPhysicsCollisionSet *)((int (__stdcall *)(unsigned int, int))physics->FindOrCreateCollisionSet)(
                                   a1: modelIndex,
                                   a2: *(_WORD *)pCollide & 0x7FFF);
    if ( v5 != nullptr )
    {
      bFoundRules_3 = 0;
      v6 = (IVPhysicsKeyParser *)((int (__thiscall *)(IPhysicsCollision *, vcollide_t *, int))physcollision->VPhysicsKeyParserCreate)(
                                   a1: physcollision,
                                   a2: pCollide,
                                   a3: a1);
      while ( !v6->Finished(this: v6) )
      {
        v7 = v6->GetCurrentBlockName(this: v6);
        if ( _V_stricmp(s1: v7, s2: "collisionrules") != 0 )
        {
          v6->SkipBlock(this: v6);
        }
        else
        {
          ParseCollisionRules = v6->ParseCollisionRules;
          rules.pCollisionSet = v5;
          rules.bSelfCollisions = 1;
          ParseCollisionRules(this: v6, a2: &rules, a3: nullptr);
          bFoundRules_3 = 1;
        }
      }
      physcollision->VPhysicsKeyParserDestroy(this: physcollision, a2: v6);
      if ( bFoundRules_3 == 0 )
      {
        v9 = ragdoll;
        listCount = ragdoll->listCount;
        v11 = 0;
        if ( ragdoll->listCount > 0 )
        {
          do
          {
            v12 = v11 + 1;
            if ( v11 + 1 < listCount )
            {
              do
                v5->EnableCollisions(this: v5, a2: v11, a3: v12++);
              while ( v12 < ragdoll->listCount );
              v12 = v11 + 1;
              v9 = ragdoll;
            }
            listCount = v9->listCount;
            v11 = v12;
          }
          while ( v12 < v9->listCount );
        }
        v13 = 0;
        if ( v9->listCount > 0 )
        {
          p_parentIndex = &v9->list[0].parentIndex;
          do
          {
            if ( *p_parentIndex >= 0 )
            {
              v5->DisableCollisions(this: v5, a2: v13, a3: *p_parentIndex);
              v9 = ragdoll;
            }
            ++v13;
            p_parentIndex += 6;
          }
          while ( v13 < v9->listCount );
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101619E0
// Name: void RagdollActivate(struct ragdoll_t __near &,struct vcollide_t __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RagdollActivate(ragdoll_t *ragdoll, vcollide_t *pCollide, unsigned int modelIndex, bool bForceWake)
{
  IPhysicsObject **p_pObject; // edi
  IPhysicsObject *v6; // esi
  unsigned __int16 v7; // ax
  int v8; // esi
  IPhysicsObject **v9; // edi
  int i; // [esp+14h] [ebp+8h]

  RagdollSetupCollisions(a1: (int)ragdoll, ragdoll, pCollide, modelIndex);
  i = 0;
  if ( ragdoll->listCount > 0 )
  {
    p_pObject = &ragdoll->list[0].pObject;
    do
    {
      v6 = *p_pObject;
      v7 = (*p_pObject)->GetGameFlags(this: *p_pObject);
      v6->SetGameFlags(this: v6, a2: v7 | 0x10);
      (*p_pObject)->EnableCollisions(this: *p_pObject, a2: true);
      if ( bForceWake )
        (*p_pObject)->Wake(this: *p_pObject);
      p_pObject += 6;
      ++i;
    }
    while ( i < ragdoll->listCount );
  }
  if ( ragdoll->pGroup != nullptr )
  {
    ragdoll->pGroup->Activate(this: ragdoll->pGroup);
    if ( !bForceWake )
    {
      v8 = 0;
      if ( ragdoll->listCount > 0 )
      {
        v9 = &ragdoll->list[0].pObject;
        do
        {
          (*v9)->Sleep(this: *v9);
          ++v8;
          v9 += 6;
        }
        while ( v8 < ragdoll->listCount );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10161A90
// Name: void RagdollApplyAnimationAsVelocity(struct ragdoll_t __near &,struct matrix3x4_t const __near *,struct matrix3x4_t const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RagdollApplyAnimationAsVelocity(
        ragdoll_t *ragdoll,
        const matrix3x4_t *pPrevBones,
        const matrix3x4_t *pCurrentBones,
        float dt)
{
  int v4; // ebx
  IPhysicsObject **p_pObject; // esi
  int *boneIndex; // edi
  Vector velocity; // [esp+10h] [ebp-24h] BYREF
  Vector localAngVelocity; // [esp+1Ch] [ebp-18h] BYREF
  Vector angVel; // [esp+28h] [ebp-Ch] BYREF

  v4 = 0;
  if ( ragdoll->listCount > 0 )
  {
    p_pObject = &ragdoll->list[0].pObject;
    boneIndex = ragdoll->boneIndex;
    do
    {
      CalcBoneDerivatives(&velocity, &angVel, prev: &pPrevBones[*boneIndex], current: &pCurrentBones[*boneIndex], dt);
      (*p_pObject)->WorldToLocalVector(this: *p_pObject, a2: &localAngVelocity, a3: &angVel);
      (*p_pObject)->AddVelocity(this: *p_pObject, a2: &velocity, a3: &localAngVelocity);
      ++v4;
      ++boneIndex;
      p_pObject += 6;
    }
    while ( v4 < ragdoll->listCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10161B20
// Name: int RagdollExtractBoneIndices(int __near *,class CStudioHdr __near *,struct vcollide_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl RagdollExtractBoneIndices(int *boneIndexOut, CStudioHdr *pStudioHdr, vcollide_t *pCollide)
{
  int v3; // edi
  IVPhysicsKeyParser *v4; // esi
  const char *v5; // eax
  int v6; // eax
  IVPhysicsKeyParser_vtbl *v7; // edx
  solid_t solid; // [esp+8h] [ebp-640h] BYREF

  v3 = 0;
  v4 = physcollision->VPhysicsKeyParserCreate(this: physcollision, a2: pCollide);
  while ( !v4->Finished(this: v4) )
  {
    v5 = v4->GetCurrentBlockName(this: v4);
    v6 = _V_stricmp(s1: v5, s2: "solid");
    v7 = v4->__vftable;
    if ( v6 != 0 )
    {
      v7->SkipBlock(this: v4);
    }
    else
    {
      v7->ParseSolid(this: v4, a2: &solid, a3: nullptr);
      if ( v3 < 32 )
        boneIndexOut[v3++] = Studio_BoneIndexByName((mstudiobone_t *)pStudioHdr, pName: solid.name);
    }
  }
  physcollision->VPhysicsKeyParserDestroy(this: physcollision, a2: v4);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10161BD0
// Name: bool RagdollGetBoneMatrix(struct ragdoll_t const __near &,class CBoneAccessor __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl RagdollGetBoneMatrix(const ragdoll_t *ragdoll, CBoneAccessor *pBoneToWorld, int objectIndex)
{
  int v3; // eax
  int v5; // esi
  int parentIndex; // eax
  Vector out; // [esp+4h] [ebp-Ch] BYREF

  v3 = ragdoll->boneIndex[objectIndex];
  if ( v3 < 0 || ragdoll->list[objectIndex].pObject == nullptr )
    return 0;
  v5 = v3;
  ragdoll->list[objectIndex].pObject->GetPositionMatrix(
    this: ragdoll->list[objectIndex].pObject,
    a2: &pBoneToWorld->m_pBones[v3]);
  parentIndex = ragdoll->list[objectIndex].parentIndex;
  if ( parentIndex >= 0 && !ragdoll->allowStretch )
  {
    VectorTransform(
      in1: &ragdoll->list[objectIndex].originParentSpace.x,
      in2: &pBoneToWorld->m_pBones[ragdoll->boneIndex[parentIndex]],
      out: &out.x);
    MatrixSetColumn(in: &out, column: 3, out: &pBoneToWorld->m_pBones[v5]);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10161C70
// Name: void RagdollComputeApproximateBbox(struct ragdoll_t const __near &,class Vector const __near &,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RagdollComputeApproximateBbox(
        const ragdoll_t *ragdoll,
        const Vector *origin,
        Vector *outMins,
        Vector *outMaxs)
{
  int v4; // edi
  IPhysicsObject **p_pObject; // esi
  IPhysicsCollision_vtbl *v6; // ebx
  int v7; // eax
  double x; // xmm2_8
  float v9; // xmm2_4
  double v10; // xmm1_8
  float v11; // xmm1_4
  double y; // xmm2_8
  float v13; // xmm2_4
  double v14; // xmm1_8
  float v15; // xmm1_4
  double z; // xmm2_8
  float v17; // xmm2_4
  double v18; // xmm0_8
  Vector objectOrg; // [esp+8h] [ebp-28h] BYREF
  Vector maxs; // [esp+14h] [ebp-1Ch] BYREF
  Vector mins; // [esp+20h] [ebp-10h] BYREF
  float radius; // [esp+2Ch] [ebp-4h]

  ClearBounds(&mins, &maxs);
  v4 = 0;
  if ( ragdoll->listCount > 0 )
  {
    p_pObject = &ragdoll->list[0].pObject;
    do
    {
      (*p_pObject)->GetPosition(this: *p_pObject, a2: &objectOrg, a3: nullptr);
      v6 = physcollision->__vftable;
      v7 = (int)(*p_pObject)->GetCollide(this: *p_pObject);
      radius = v6->CollideGetRadius(this: physcollision, a2: (const struct CPhysCollide *)v7);
      x = maxs.x;
      if ( maxs.x < (double)(float)(objectOrg.x + radius) )
        x = (float)(objectOrg.x + radius);
      v9 = x;
      maxs.x = v9;
      v10 = (float)(objectOrg.x - radius);
      if ( mins.x <= v10 )
        v10 = mins.x;
      v11 = v10;
      mins.x = v11;
      y = maxs.y;
      if ( maxs.y < (double)(float)(objectOrg.y + radius) )
        y = (float)(objectOrg.y + radius);
      v13 = y;
      maxs.y = v13;
      v14 = (float)(objectOrg.y - radius);
      if ( mins.y <= v14 )
        v14 = mins.y;
      v15 = v14;
      mins.y = v15;
      z = maxs.z;
      if ( maxs.z < (double)(float)(objectOrg.z + radius) )
        z = (float)(objectOrg.z + radius);
      v17 = z;
      maxs.z = v17;
      v18 = (float)(objectOrg.z - radius);
      if ( mins.z <= v18 )
        v18 = mins.z;
      ++v4;
      p_pObject += 6;
      mins.z = v18;
    }
    while ( v4 < ragdoll->listCount );
  }
  *outMins = mins;
  *outMaxs = maxs;
}

//------------------------------------------------------------------------------
// Address: 0x10161E30
// Name: class C_EntityDissolve __near * DissolveEffect(class C_BaseAnimating __near *,float)
// Source: json
//------------------------------------------------------------------------------
C_EntityDissolve *__cdecl DissolveEffect(C_BaseAnimating *pTarget, float flTime)
{
  C_EntityDissolve *v2; // eax
  C_EntityDissolve *v3; // esi
  const Vector *v5; // eax

  v2 = (C_EntityDissolve *)C_BaseEntity::operator new(stAllocateBlock: 0x9C8u);
  if ( v2 != nullptr )
    v3 = C_EntityDissolve::C_EntityDissolve(this: v2);
  else
    v3 = nullptr;
  if ( v3->InitializeAsClientEntity(this: v3, a2: "sprites/blueglow1.vmt", a3: false) )
  {
    C_BaseEntity::AddFlag(this: pTarget, flags: 0x20000000);
    C_BaseEntity::SetParent(this: v3, pParentEntity: pTarget, iParentAttachment: 0);
    v3->OnDataChanged(this: &v3->IClientNetworkable, a2: DATA_UPDATE_CREATED);
    v5 = pTarget->GetAbsOrigin(this: pTarget);
    C_BaseEntity::SetAbsOrigin(this: v3, absOrigin: v5);
    v3->m_flStartTime = flTime;
    v3->m_flFadeOutStart = 2.0;
    v3->m_flFadeOutModelStart = 1.9;
    v3->m_flFadeOutModelLength = 0.1;
    v3->m_flFadeInLength = 1.0;
    v3->m_nDissolveType = 0;
    v3->m_flNextSparkTime = 0.0;
    v3->m_flFadeOutLength = 0.0;
    v3->m_flFadeInStart = 0.0;
    v3->m_bLinkedToServerEnt = false;
    C_BaseEntity::SetEffectEntity(this: pTarget, pEffectEnt: v3);
    return v3;
  }
  else
  {
    C_BaseEntity::Remove(this: v3);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10161F40
// Name: public: void CRagdollLowViolenceManager::SetLowViolence(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRagdollLowViolenceManager::SetLowViolence(CRagdollLowViolenceManager *this, const char *pMapName)
{
  int v3; // eax

  this->m_bLowViolence = UTIL_IsLowViolence();
  if ( hl2_episodic.m_pParent != nullptr && hl2_episodic.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( _V_stricmp(s1: pMapName, s2: "ep1_citadel_02") != 0 && _V_stricmp(s1: pMapName, s2: "ep1_citadel_02b") != 0 )
    {
      v3 = _V_stricmp(s1: pMapName, s2: "ep1_citadel_03");
      goto LABEL_10;
    }
  }
  else if ( _V_stricmp(s1: pMapName, s2: "d3_citadel_03") != 0
         && _V_stricmp(s1: pMapName, s2: "d3_citadel_04") != 0
         && _V_stricmp(s1: pMapName, s2: "d3_citadel_05") != 0 )
  {
    v3 = _V_stricmp(s1: pMapName, s2: "d3_breen_01");
LABEL_10:
    if ( v3 != 0 )
      return;
  }
  this->m_bLowViolence = false;
}

//------------------------------------------------------------------------------
// Address: 0x10161FE0
// Name: RagdollAddSolids
// Source: json
//------------------------------------------------------------------------------
void __cdecl RagdollAddSolids(
        IPhysicsEnvironment *pPhysEnv,
        ragdoll_t *ragdoll,
        const ragdollparams_t *params,
        cache_ragdollsolid_t *pSolids,
        int solidCount,
        const cache_ragdollconstraint_t *pConstraints,
        int constraintCount)
{
  const ragdollparams_t *v7; // edx
  const studiohdr_t *m_pStudioHdr; // eax
  int studiohdr2index; // ecx
  int v10; // ebx
  int v11; // esi
  char *v12; // ecx
  int v13; // eax
  char *name; // eax
  int v15; // esi
  int *p_parentIndex; // eax
  int j; // ecx
  __int16 *p_childIndex; // esi
  IPhysicsObject **p_pObject; // ebx
  __int16 *p_boneIndex; // esi
  int v21; // edi
  IPhysicsObject *v22; // eax
  int v23; // ecx
  int v24; // edi
  IPhysicsObject *pObject; // ecx
  IPhysicsObject *v26; // edi
  unsigned __int16 v27; // ax
  matrix3x4_t xform; // [esp+Ch] [ebp-44h] BYREF
  Vector position; // [esp+3Ch] [ebp-14h] BYREF
  int i; // [esp+48h] [ebp-8h]
  char *v31; // [esp+4Ch] [ebp-4h]
  int *constraintCounta; // [esp+70h] [ebp+20h]

  v7 = params;
  m_pStudioHdr = params->pStudioHdr->m_pStudioHdr;
  studiohdr2index = m_pStudioHdr->studiohdr2index;
  v10 = constraintCount;
  if ( studiohdr2index != 0
    && (v11 = *(_DWORD *)&m_pStudioHdr->name[studiohdr2index + 8], v12 = (char *)m_pStudioHdr + studiohdr2index,
                                                                   v11 != 0)
    && &v12[v11] != nullptr )
  {
    v13 = *((_DWORD *)v12 + 5);
    if ( v13 == 0 )
    {
      v31 = nullptr;
      goto LABEL_9;
    }
    name = &v12[v13];
  }
  else
  {
    name = m_pStudioHdr->name;
  }
  v31 = name;
LABEL_9:
  v15 = solidCount;
  if ( solidCount > 0 )
  {
    p_parentIndex = &ragdoll->list[0].parentIndex;
    for ( j = solidCount; j != 0; --j )
    {
      *p_parentIndex = -1;
      p_parentIndex += 6;
    }
  }
  if ( constraintCount > 0 )
  {
    p_childIndex = &pConstraints->childIndex;
    do
    {
      ragdoll->list[*p_childIndex].parentIndex = *(p_childIndex - 1);
      MatrixGetColumn(
        in: (const matrix3x4_t *)(p_childIndex - 25),
        column: 3,
        out: &ragdoll->list[*p_childIndex].originParentSpace);
      p_childIndex += 50;
      --v10;
    }
    while ( v10 != 0 );
    v7 = params;
    v15 = solidCount;
  }
  i = 0;
  if ( v15 <= 0 )
  {
    ragdoll->listCount = v15;
  }
  else
  {
    p_pObject = &ragdoll->list[0].pObject;
    constraintCounta = ragdoll->boneIndex;
    p_boneIndex = &pSolids->boneIndex;
    while ( 1 )
    {
      if ( v7->fixedConstraints )
        *((_DWORD *)p_boneIndex - 11) = 1148846080;
      *constraintCounta = *p_boneIndex;
      *((_DWORD *)p_boneIndex - 6) = v31;
      v21 = *((_DWORD *)p_boneIndex - 1);
      *((_DWORD *)p_boneIndex - 5) = v7->pGameData;
      v22 = pPhysEnv->CreatePolyObject(
              this: pPhysEnv,
              a2: v7->pCollide->solids[p_boneIndex[1]],
              a3: v21,
              a4: &vec3_origin,
              a5: &vec3_angle,
              a6: p_boneIndex - 24);
      v23 = i;
      *p_pObject = v22;
      v22->SetGameIndex(this: v22, a2: v23);
      v24 = (int)p_pObject[2];
      MatrixCopy(in: &params->pCurrentBones[*constraintCounta], out: &xform);
      if ( v24 >= 0 )
      {
        pObject = ragdoll->list[v24].pObject;
        pObject->LocalToWorld(this: pObject, a2: &position, a3: (const Vector *)p_pObject - 1);
        MatrixSetColumn(in: &position, column: 3, out: &xform);
      }
      (*p_pObject)->SetPositionMatrix(this: *p_pObject, a2: &xform, a3: true);
      v26 = *p_pObject;
      v27 = (*p_pObject)->GetGameFlags(this: *p_pObject);
      v26->SetGameFlags(this: v26, a2: v27 | 8);
      ++constraintCounta;
      p_boneIndex += 26;
      p_pObject += 6;
      if ( ++i >= solidCount )
        break;
      v7 = params;
    }
    ragdoll->listCount = solidCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101621C0
// Name: RagdollAddConstraints
// Source: json
//------------------------------------------------------------------------------
void __usercall RagdollAddConstraints(
        ragdoll_t *ragdoll@<edi>,
        const cache_ragdollconstraint_t *pConstraints@<ecx>,
        int constraintCount@<eax>,
        IPhysicsEnvironment *pPhysEnv,
        const ragdollparams_t *params)
{
  __int16 *p_childIndex; // esi
  float jointFrictionScale; // xmm0_4
  int v7; // eax
  int v8; // ebx
  __int64 v9; // xmm0_8
  IPhysicsObject *v10; // ecx
  void (__thiscall *GetPositionMatrix)(IPhysicsObject *, matrix3x4_t *); // edx
  IPhysicsConstraint *(__thiscall *CreateFixedConstraint)(IPhysicsEnvironment *, IPhysicsObject *, IPhysicsObject *, IPhysicsConstraintGroup *, const constraint_fixedparams_t *); // eax
  IPhysicsObject *v13; // edx
  int v14; // ebx
  IPhysicsObject *v15; // edx
  IPhysicsConstraint *(__thiscall *CreateRagdollConstraint)(IPhysicsEnvironment *, IPhysicsObject *, IPhysicsObject *, IPhysicsConstraintGroup *, const constraint_ragdollparams_t *); // edx
  IPhysicsObject *v17; // ecx
  int v18; // eax
  IPhysicsObject *v19; // [esp-14h] [ebp-1ACh]
  IPhysicsConstraintGroup *pGroup; // [esp-10h] [ebp-1A8h]
  IPhysicsConstraintGroup *v21; // [esp-10h] [ebp-1A8h]
  matrix3x4_t out; // [esp+0h] [ebp-198h] BYREF
  matrix3x4_t in2; // [esp+30h] [ebp-168h] BYREF
  matrix3x4_t in; // [esp+60h] [ebp-138h] BYREF
  constraint_fixedparams_t fixed; // [esp+90h] [ebp-108h] BYREF
  constraint_ragdollparams_t constraint; // [esp+D8h] [ebp-C0h] BYREF
  IPhysicsObject *pObject; // [esp+18Ch] [ebp-Ch]
  int i; // [esp+190h] [ebp-8h]
  int childIndex; // [esp+194h] [ebp-4h]

  if ( constraintCount > 0 )
  {
    p_childIndex = &pConstraints->childIndex;
    for ( i = constraintCount; i != 0; --i )
    {
      constraint.constraint.forceLimit = 0.0;
      constraint.constraint.torqueLimit = 0.0;
      constraint.constraint.strength = 1.0;
      constraint.constraint.bodyMassScale[0] = 1.0;
      constraint.constraint.bodyMassScale[1] = 1.0;
      constraint.constraint.isActive = true;
      constraint.isActive = true;
      SetIdentityMatrix(matrix: &constraint.constraintToReference);
      SetIdentityMatrix(matrix: &constraint.constraintToAttached);
      constraint.parentIndex = -1;
      constraint.childIndex = -1;
      memset(constraint.axes, 0, 49);
      constraint.useClockwiseRotations = false;
      _V_memcpy(dest: constraint.axes, src: p_childIndex - 49, count: 48);
      jointFrictionScale = params->jointFrictionScale;
      if ( jointFrictionScale > 0.0 )
      {
        constraint.axes[0].torque = jointFrictionScale * constraint.axes[0].torque;
        constraint.axes[1].torque = jointFrictionScale * constraint.axes[1].torque;
        constraint.axes[2].torque = jointFrictionScale * constraint.axes[2].torque;
      }
      v7 = *p_childIndex;
      v8 = *(p_childIndex - 1);
      *(_QWORD *)&constraint.constraintToAttached.m_flMatVal[0][0] = *(_QWORD *)(p_childIndex - 25);
      *(_QWORD *)&constraint.constraintToAttached.m_flMatVal[0][2] = *(_QWORD *)(p_childIndex - 21);
      *(_OWORD *)&constraint.constraintToAttached.m_flMatVal[1][0] = *(_OWORD *)(p_childIndex - 17);
      *(_QWORD *)&constraint.constraintToAttached.m_flMatVal[2][0] = *(_QWORD *)(p_childIndex - 9);
      v9 = *(_QWORD *)(p_childIndex - 5);
      childIndex = v7;
      constraint.childIndex = v7;
      constraint.parentIndex = v8;
      constraint.useClockwiseRotations = true;
      *(_QWORD *)&constraint.constraintToAttached.m_flMatVal[2][2] = v9;
      SetIdentityMatrix(matrix: &constraint.constraintToReference);
      if ( params->fixedConstraints )
      {
        SetIdentityMatrix(matrix: &fixed.attachedRefXform);
        fixed.constraint.forceLimit = 0.0;
        fixed.constraint.torqueLimit = 0.0;
        fixed.constraint.strength = 1.0;
        fixed.constraint.bodyMassScale[0] = 1.0;
        fixed.constraint.bodyMassScale[1] = 1.0;
        fixed.constraint.isActive = true;
        pObject = ragdoll->list[constraint.parentIndex].pObject;
        v10 = ragdoll->list[childIndex].pObject;
        GetPositionMatrix = v10->GetPositionMatrix;
        childIndex = (int)ragdoll + 24 * childIndex;
        GetPositionMatrix(this: v10, a2: &in);
        MatrixInvert(&in, &out);
        pObject->GetPositionMatrix(this: pObject, a2: &in2);
        ConcatTransforms(in1: &out, &in2, out: &fixed.attachedRefXform);
        CreateFixedConstraint = pPhysEnv->CreateFixedConstraint;
        pGroup = ragdoll->pGroup;
        v13 = ragdoll->list[v8].pObject;
        v14 = childIndex;
        v19 = v13;
        v15 = *(IPhysicsObject **)(childIndex + 24);
        fixed.constraint.forceLimit = 0.0;
        fixed.constraint.torqueLimit = 0.0;
        fixed.constraint.strength = 1.0;
        fixed.constraint.bodyMassScale[0] = 1.0;
        fixed.constraint.bodyMassScale[1] = 1.0;
        fixed.constraint.isActive = true;
        *(_DWORD *)(v14 + 28) = CreateFixedConstraint(this: pPhysEnv, a2: v15, a3: v19, a4: pGroup, a5: &fixed);
      }
      else
      {
        CreateRagdollConstraint = pPhysEnv->CreateRagdollConstraint;
        v21 = ragdoll->pGroup;
        v17 = ragdoll->list[v8].pObject;
        childIndex = (int)ragdoll + 24 * childIndex;
        v18 = (int)CreateRagdollConstraint(
                     this: pPhysEnv,
                     a2: *(IPhysicsObject **)(childIndex + 24),
                     a3: v17,
                     a4: v21,
                     a5: &constraint);
        *(_DWORD *)(childIndex + 28) = v18;
      }
      p_childIndex += 50;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101624A0
// Name: ParseRagdollIntoCache
// Source: json
//------------------------------------------------------------------------------
cache_ragdoll_t *__cdecl ParseRagdollIntoCache(CStudioHdr *pStudioHdr, vcollide_t *pCollide, int modelIndex)
{
  __int16 v3; // bx
  __int16 v4; // di
  IVPhysicsKeyParser *v5; // esi
  char *v6; // ebx
  const char *v7; // edi
  __int16 v8; // ax
  IPhysicsSurfaceProps *v9; // ecx
  int v10; // eax
  int v11; // ecx
  matrix3x4_t *v12; // edi
  int v13; // eax
  int v14; // ecx
  int v15; // edx
  void (__thiscall *ParseCollisionRules)(IVPhysicsKeyParser *, ragdollcollisionrules_t *, IVPhysicsKeyHandler *); // edx
  int v17; // ebx
  int v18; // edi
  __int16 *v19; // esi
  _BYTE v21[3200]; // [esp+Ch] [ebp-1A24h] BYREF
  _BYTE v22[44]; // [esp+C8Ch] [ebp-DA4h] BYREF
  char v23[1620]; // [esp+CB8h] [ebp-D78h] BYREF
  char pName[1024]; // [esp+130Ch] [ebp-724h] BYREF
  char v25[524]; // [esp+170Ch] [ebp-324h] BYREF
  __int16 v26; // [esp+1918h] [ebp-118h]
  __int64 v27; // [esp+1920h] [ebp-110h]
  __int64 v28; // [esp+1928h] [ebp-108h]
  __int64 v29; // [esp+1930h] [ebp-100h]
  __int64 v30; // [esp+1938h] [ebp-F8h]
  __int64 v31; // [esp+1940h] [ebp-F0h]
  int v32; // [esp+1948h] [ebp-E8h]
  char v33; // [esp+194Ch] [ebp-E4h] BYREF
  int v34; // [esp+19C4h] [ebp-6Ch]
  int v35; // [esp+19C8h] [ebp-68h]
  _BYTE src[52]; // [esp+19CCh] [ebp-64h] BYREF
  int dest; // [esp+1A00h] [ebp-30h] BYREF
  ragdollanimatedfriction_t v38; // [esp+1A04h] [ebp-2Ch] BYREF
  __int16 v39; // [esp+1A18h] [ebp-18h]
  __int16 v40; // [esp+1A1Ah] [ebp-16h]
  int v41; // [esp+1A1Ch] [ebp-14h] BYREF
  int v42; // [esp+1A20h] [ebp-10h]
  void *v43; // [esp+1A24h] [ebp-Ch]
  int v44; // [esp+1A28h] [ebp-8h]
  int v45; // [esp+1A2Ch] [ebp-4h]
  int savedregs; // [esp+1A30h] [ebp+0h] BYREF

  v3 = 0;
  v4 = 0;
  v5 = physcollision->VPhysicsKeyParserCreate(this: physcollision, a2: pCollide);
  v45 = 0;
  v44 = 0;
  _V_memset(&dest, fill: 0, count: 28);
  if ( !v5->Finished(this: v5) )
  {
    v43 = v21;
    v6 = v23;
    do
    {
      v7 = v5->GetCurrentBlockName(this: v5);
      if ( _V_stricmp(s1: v7, s2: "solid") != 0 )
      {
        if ( _V_stricmp(s1: v7, s2: "ragdollconstraint") != 0 )
        {
          if ( _V_stricmp(s1: v7, s2: "collisionrules") != 0 )
          {
            if ( _V_stricmp(s1: v7, s2: "animatedfriction") != 0 )
              v5->SkipBlock(this: v5);
            else
              v5->ParseRagdollAnimatedFriction(this: v5, a2: &v38, a3: nullptr);
          }
          else
          {
            v42 = ((int (__stdcall *)(int, int))physics->FindOrCreateCollisionSet)(
                    a1: modelIndex,
                    a2: *(_WORD *)pCollide & 0x7FFF);
            ParseCollisionRules = v5->ParseCollisionRules;
            v41 = 1;
            ParseCollisionRules(this: v5, a2: (ragdollcollisionrules_t *)&v41, a3: nullptr);
            dest = v42;
          }
        }
        else
        {
          v5->ParseRagdollConstraint(this: v5, a2: (constraint_ragdollparams_t *)&v33, a3: nullptr);
          if ( v35 != v34 && v35 >= 0 && v34 >= 0 )
          {
            v12 = (matrix3x4_t *)v43;
            ++v45;
            v43 = (char *)v43 + 100;
            _V_memcpy(dest: (void *)v12, src, count: 48);
            v13 = v34;
            v14 = v35;
            LOWORD(v12[2].m_flMatVal[0][0]) = v34;
            v15 = *(__int16 *)&v23[52 * v13 + 4];
            HIWORD(v12[2].m_flMatVal[0][0]) = v14;
            Studio_CalcBoneToBoneTransform(
              a1: (unsigned int)&savedregs,
              pStudioHdr,
              inputBoneIndex: *(__int16 *)&v23[52 * v14 + 4],
              outputBoneIndex: v15,
              matrixOut: v12 + 1);
          }
        }
      }
      else
      {
        v5->ParseSolid(this: v5, a2: (solid_t *)pName, a3: &g_SolidSetup);
        v8 = Studio_BoneIndexByName((mstudiobone_t *)pStudioHdr, pName);
        *((_WORD *)v6 + 2) = v8;
        if ( v8 < 0 )
        {
          _Msg(a1: "ParseRagdollIntoCache:  Couldn't Lookup Bone %s\n", pName);
        }
        else
        {
          v9 = physprops;
          *((_WORD *)v6 + 3) = v26;
          v10 = v9->GetSurfaceIndex(this: v9, a2: v25);
          *(_DWORD *)v6 = v10;
          if ( v10 < 0 )
            *(_DWORD *)v6 = physprops->GetSurfaceIndex(this: physprops, a2: "default");
          v11 = v32;
          ++v44;
          *(_QWORD *)(v6 - 44) = v27;
          *(_QWORD *)(v6 - 36) = v28;
          *(_QWORD *)(v6 - 28) = v29;
          *(_QWORD *)(v6 - 20) = v30;
          *(_QWORD *)(v6 - 12) = v31;
          *((_DWORD *)v6 - 1) = v11;
          *(v6 - 4) = 0;
          v6 += 52;
        }
      }
    }
    while ( !v5->Finished(this: v5) );
    v4 = v45;
    v3 = v44;
  }
  physcollision->VPhysicsKeyParserDestroy(this: physcollision, a2: v5);
  v39 = v3;
  v40 = v4;
  v17 = 52 * v3;
  v18 = 100 * v4;
  v19 = (__int16 *)physcollision->VCollideAllocUserData(this: physcollision, a2: pCollide, a3: v18 + v17 + 28);
  _V_memcpy(dest: v19, src: &dest, count: 28);
  _V_memcpy(dest: v19 + 14, src: v22, count: v17);
  _V_memcpy(dest: &v19[26 * v19[12] + 14], src: v21, count: v18);
  return (cache_ragdoll_t *)v19;
}

//------------------------------------------------------------------------------
// Address: 0x101627B0
// Name: RagdollCreateObjects
// Source: json
//------------------------------------------------------------------------------
void __usercall RagdollCreateObjects(
        ragdoll_t *ragdoll@<eax>,
        IPhysicsEnvironment *pPhysEnv,
        const ragdollparams_t *params)
{
  vcollide_t *pCollide; // eax
  cache_ragdoll_t *pUserData; // esi
  IPhysicsConstraintGroup *(__thiscall *CreateConstraintGroup)(IPhysicsEnvironment *, const constraint_groupparams_t *); // eax
  constraint_groupparams_t group; // [esp+Ch] [ebp-Ch] BYREF

  ragdoll->listCount = 0;
  ragdoll->pGroup = nullptr;
  ragdoll->allowStretch = params->allowStretch;
  memset(dst: (int)ragdoll->list, value: nullptr, count: sizeof(ragdoll->list));
  *(_QWORD *)&ragdoll->animfriction.minFriction = 0;
  *(_QWORD *)&ragdoll->animfriction.timeIn = 0;
  ragdoll->animfriction.timeHold = 0.0;
  pCollide = params->pCollide;
  if ( pCollide != nullptr )
  {
    if ( (*(_WORD *)pCollide & 0x7FFFu) <= 0x20 )
    {
      pUserData = (cache_ragdoll_t *)pCollide->pUserData;
      if ( pUserData == nullptr )
        pUserData = ParseRagdollIntoCache(pStudioHdr: params->pStudioHdr, pCollide, modelIndex: params->modelIndex);
      CreateConstraintGroup = pPhysEnv->CreateConstraintGroup;
      group.additionalIterations = 0;
      group.minErrorTicks = 15;
      group.errorTolerance = 3.0;
      ragdoll->pGroup = CreateConstraintGroup(this: pPhysEnv, a2: &group);
      RagdollAddSolids(
        pPhysEnv,
        ragdoll,
        params,
        pSolids: (cache_ragdollsolid_t *)&pUserData[1],
        solidCount: pUserData->solidCount,
        pConstraints: (const cache_ragdollconstraint_t *)((char *)&pUserData[1] + 52 * pUserData->solidCount),
        constraintCount: pUserData->constraintCount);
      RagdollAddConstraints(
        ragdoll,
        pConstraints: (const cache_ragdollconstraint_t *)((char *)&pUserData[1] + 52 * pUserData->solidCount),
        constraintCount: pUserData->constraintCount,
        pPhysEnv,
        params);
    }
    else
    {
      _Warning(
        a1: "Ragdoll solid count %d exceeds maximum limit of %d - Ragdoll not created",
        *(_WORD *)pCollide & 0x7FFF,
        32);
    }
  }
  else
  {
    _Warning(a1: "Ragdoll has no pCollide!");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101628D0
// Name: bool RagdollCreate(struct ragdoll_t __near &,struct ragdollparams_t const __near &,class IPhysicsEnvironment __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl RagdollCreate(ragdoll_t *ragdoll, const ragdollparams_t *params, IPhysicsEnvironment *pPhysEnv)
{
  const ragdollparams_t *v3; // ebx
  int listCount; // eax
  int forceBoneIndex; // ecx
  int v8; // edi
  IPhysicsObject **p_pObject; // ebx
  double v10; // st7
  float z; // edx
  float v12; // eax
  IPhysicsObject **v13; // edi
  int v14; // edi
  IPhysicsObject **v15; // ebx
  double v16; // st7
  IPhysicsObject *v17; // ecx
  float v18[3]; // [esp+8h] [ebp-28h] BYREF
  Vector nudgeForce; // [esp+14h] [ebp-1Ch] BYREF
  Vector forcePosition; // [esp+20h] [ebp-10h] BYREF
  int forceBone; // [esp+2Ch] [ebp-4h]
  float totalMass; // [esp+38h] [ebp+8h]

  v3 = params;
  RagdollCreateObjects(ragdoll, pPhysEnv, params);
  listCount = ragdoll->listCount;
  if ( ragdoll->listCount == 0 )
    return 0;
  forceBoneIndex = params->forceBoneIndex;
  v8 = 0;
  forceBone = forceBoneIndex;
  totalMass = 0.0;
  if ( listCount <= 0 )
    goto LABEL_7;
  p_pObject = &ragdoll->list[0].pObject;
  do
  {
    v10 = ((double (__thiscall *)(IPhysicsObject *))(*p_pObject)->GetMass)(a1: *p_pObject);
    ++v8;
    p_pObject += 6;
    totalMass = v10 + totalMass;
  }
  while ( v8 < ragdoll->listCount );
  forceBoneIndex = forceBone;
  v3 = params;
  if ( totalMass <= 1.0 )
LABEL_7:
    totalMass = 1.0;
  z = v3->forceVector.z;
  v12 = v3->forcePosition.z;
  *(_QWORD *)&nudgeForce.x = *(_QWORD *)&v3->forceVector.x;
  nudgeForce.z = z;
  *(_QWORD *)&forcePosition.x = *(_QWORD *)&v3->forcePosition.x;
  forcePosition.z = v12;
  if ( forceBoneIndex >= 0 && forceBoneIndex < ragdoll->listCount )
  {
    v13 = &ragdoll->list[forceBoneIndex].pObject;
    (*v13)->ApplyForceCenter(this: *v13, a2: &nudgeForce);
    (*v13)->GetPosition(this: *v13, a2: &forcePosition, a3: nullptr);
    forceBoneIndex = forceBone;
  }
  if ( vec3_origin.x != forcePosition.x || vec3_origin.y != forcePosition.y || vec3_origin.z != forcePosition.z )
  {
    v14 = 0;
    if ( ragdoll->listCount > 0 )
    {
      v15 = &ragdoll->list[0].pObject;
      do
      {
        if ( forceBoneIndex != v14 )
        {
          v16 = ((double (__thiscall *)(IPhysicsObject *))(*v15)->GetMass)(a1: *v15) / totalMass;
          v17 = *v15;
          v18[0] = nudgeForce.x * v16;
          v18[1] = nudgeForce.y * v16;
          v18[2] = v16 * nudgeForce.z;
          v17->ApplyForceOffset(this: v17, a2: (const Vector *)v18, a3: &forcePosition);
          forceBoneIndex = forceBone;
        }
        ++v14;
        v15 += 6;
      }
      while ( v14 < ragdoll->listCount );
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10162A30
// Name: void RagdollSolveSeparation(struct ragdoll_t __near &,class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __usercall RagdollSolveSeparation(float a1@<ebp>, ragdoll_t *ragdoll, C_BaseEntity *pEntity)
{
  int v3; // eax
  int *p_parentIndex; // esi
  bool v5; // zf
  IPhysicsObject *pObject; // ecx
  double v7; // st7
  IPhysicsObject *v8; // ecx
  double v9; // st6
  float x; // eax
  IPhysicsObject **p_pObject; // esi
  IPhysicsObject *v12; // ecx
  IPhysicsObject *v13; // ecx
  unsigned __int8 needsFix[256]; // [esp+0h] [ebp-1D8h] BYREF
  CGameTrace tr; // [esp+100h] [ebp-D8h] BYREF
  matrix3x4_t xform; // [esp+158h] [ebp-80h] BYREF
  int v17; // [esp+18Ch] [ebp-4Ch]
  Vector v18; // [esp+19Ch] [ebp-3Ch] BYREF
  Vector start; // [esp+1A8h] [ebp-30h] BYREF
  float v20; // [esp+1B4h] [ebp-24h]
  Vector target; // [esp+1B8h] [ebp-20h] BYREF
  Vector velocity; // [esp+1C4h] [ebp-14h] BYREF
  int i; // [esp+1D0h] [ebp-8h]
  int retaddr; // [esp+1D8h] [ebp+0h]

  velocity.z = a1;
  i = retaddr;
  v3 = 0;
  velocity.y = 0.0;
  velocity.x = 0.0;
  if ( ragdoll->listCount <= 0 )
    goto LABEL_24;
  p_parentIndex = &ragdoll->list[0].parentIndex;
  do
  {
    v5 = *(p_parentIndex - 1) == 0;
    *((_BYTE *)&velocity.z + v3 - 472) = 0;
    if ( !v5 && *p_parentIndex >= 0 )
    {
      (*(void (__thiscall **)(_DWORD, Vector *, _DWORD))(*(_DWORD *)*(p_parentIndex - 2) + 192))(
        a1: *(p_parentIndex - 2),
        a2: &v18,
        a3: 0);
      pObject = ragdoll->list[*p_parentIndex].pObject;
      pObject->LocalToWorld(this: pObject, a2: &target, a3: (const Vector *)(p_parentIndex - 5));
      if ( *((_BYTE *)&velocity.z + *p_parentIndex - 472) != 0 )
      {
        ++LODWORD(velocity.y);
        *((_BYTE *)&velocity.z + LODWORD(velocity.x) - 472) = 1;
        goto LABEL_16;
      }
      start.y = target.x - v18.x;
      start.z = target.y - v18.y;
      v20 = target.z - v18.z;
      if ( (float)((float)((float)(start.y * start.y) + (float)(start.z * start.z)) + (float)(v20 * v20)) > 1.0 )
      {
        v7 = ((double (__thiscall *)(_DWORD))*(_DWORD *)(*(_DWORD *)*(p_parentIndex - 2) + 116))(a1: *(p_parentIndex - 2));
        v8 = ragdoll->list[*p_parentIndex].pObject;
        start.x = v7 + v7;
        v9 = ((double (__thiscall *)(IPhysicsObject *))v8->GetMass)(a1: v8);
        if ( v9 > start.x )
        {
          *((_BYTE *)&velocity.z + LODWORD(velocity.x) - 472) = 1;
LABEL_15:
          ++LODWORD(velocity.y);
          goto LABEL_16;
        }
        if ( PhysHasContactWithOtherInDirection(
               pPhysics: (IPhysicsObject *)*(p_parentIndex - 2),
               dir: (Vector *)&start.y) )
        {
          v17 = 0;
          Ray_t::Init(this: (Ray_t *)&tr.m_pEnt, start: &target, end: &v18);
          UTIL_TraceRay(
            ray: (const Ray_t *)&tr.m_pEnt,
            mask: 0x200400Bu,
            ignore: pEntity,
            collisionGroup: 0,
            ptr: (CGameTrace *)&needsFix[244]);
          if ( tr.plane.normal.z < 1.0 || tr.plane.pad[0] != 0 || tr.plane.pad[1] != 0 )
          {
            *((_BYTE *)&velocity.z + LODWORD(velocity.x) - 472) = 1;
            goto LABEL_15;
          }
        }
      }
    }
LABEL_16:
    v3 = LODWORD(velocity.x) + 1;
    p_parentIndex += 6;
    LODWORD(velocity.x) = v3;
  }
  while ( v3 < ragdoll->listCount );
  if ( LODWORD(velocity.y) == 0 )
  {
LABEL_24:
    ragdoll->pGroup->ClearErrorState(this: ragdoll->pGroup);
    return;
  }
  x = 0.0;
  velocity.x = 0.0;
  if ( ragdoll->listCount > 0 )
  {
    p_pObject = &ragdoll->list[0].pObject;
    do
    {
      if ( *((_BYTE *)&velocity.z + LODWORD(x) - 472) != 0 )
      {
        v12 = ragdoll->list[(_DWORD)p_pObject[2]].pObject;
        v12->LocalToWorld(this: v12, a2: (Vector *)&start.y, a3: (const Vector *)p_pObject - 1);
        v13 = ragdoll->list[(_DWORD)p_pObject[2]].pObject;
        v13->GetVelocityAtPoint(this: v13, a2: (Vector *)&start.y, a3: &target);
        (*p_pObject)->GetPositionMatrix(this: *p_pObject, a2: (matrix3x4_t *)&xform.m_flMatVal[1][1]);
        MatrixSetColumn(in: (Vector *)&start.y, column: 3, out: (matrix3x4_t *)&xform.m_flMatVal[1][1]);
        (*p_pObject)->SetPositionMatrix(this: *p_pObject, a2: (matrix3x4_t *)&xform.m_flMatVal[1][1], a3: true);
        (*p_pObject)->SetVelocity(this: *p_pObject, a2: &target, a3: &vec3_origin);
        x = velocity.x;
      }
      ++LODWORD(x);
      p_pObject += 6;
      velocity.x = x;
    }
    while ( SLODWORD(x) < ragdoll->listCount );
  }
  _DevMsg(a1: 2, a2: "TICK:%5d:Ragdoll separation count: %d\n");
}

//------------------------------------------------------------------------------
// Address: 0x10162CE0
// Name: bool ShouldRemoveThisRagdoll(class C_BaseAnimating __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ShouldRemoveThisRagdoll(C_BaseAnimating *pRagdoll)
{
  Vector *v1; // eax
  CRagdoll *m_pRagdoll; // ecx
  float x; // [esp+40h] [ebp-3Ch] BYREF
  float y; // [esp+44h] [ebp-38h]
  float v6; // [esp+48h] [ebp-34h]
  float v7; // [esp+4Ch] [ebp-30h] BYREF
  float v8; // [esp+50h] [ebp-2Ch]
  float v9; // [esp+54h] [ebp-28h]
  Vector vMins; // [esp+58h] [ebp-24h] BYREF
  Vector vMaxs; // [esp+64h] [ebp-18h] BYREF
  Vector origin; // [esp+70h] [ebp-Ch] BYREF

  if ( g_RagdollLVManager.m_bLowViolence )
    return 1;
  v1 = pRagdoll->m_pRagdoll->GetRagdollOrigin(this: pRagdoll->m_pRagdoll);
  m_pRagdoll = pRagdoll->m_pRagdoll;
  origin = *v1;
  m_pRagdoll->GetRagdollBounds(this: m_pRagdoll, a2: &vMins, a3: &vMaxs);
  v9 = origin.z + vMaxs.z;
  y = vMins.y + origin.y;
  v7 = origin.x + vMaxs.x;
  v8 = origin.y + vMaxs.y;
  x = vMins.x + origin.x;
  v6 = vMins.z + origin.z;
  if ( engine->IsBoxInViewCluster(this: engine, a2: (const Vector *)&x, a3: (const Vector *)&v7) == 0 )
  {
    if ( g_debug_ragdoll_removal.m_pParent != nullptr && g_debug_ragdoll_removal.m_pParent->m_Value.m_nValue != 0 )
    {
      x = 0.0;
      y = 0.0;
      v6 = 0.0;
      ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, Vector *, float *, _DWORD, int, _DWORD, int, int))debugoverlay->AddBoxOverlay)(
        a1: debugoverlay,
        a2: &origin,
        a3: &vMins,
        a4: &vMaxs,
        a5: &x,
        a6: 0,
        a7: 255,
        a8: 0,
        a9: 16,
        a10: 1084227584);
      x = origin.x;
      y = origin.y;
      v6 = origin.z + 64.0;
      ((void (__thiscall *)(IVDebugOverlay *, Vector *, float *, _DWORD, int, _DWORD, int, int))debugoverlay->AddLineOverlay)(
        a1: debugoverlay,
        a2: &origin,
        a3: &x,
        a4: 0,
        a5: 255,
        a6: 0,
        a7: 1,
        a8: 1084227584);
    }
    return 1;
  }
  v6 = origin.z + vMaxs.z;
  v8 = vMins.y + origin.y;
  x = origin.x + vMaxs.x;
  y = origin.y + vMaxs.y;
  v7 = vMins.x + origin.x;
  v9 = vMins.z + origin.z;
  if ( !engine->CullBox(this: engine, a2: (const Vector *)&v7, a3: (const Vector *)&x) )
    return 0;
  if ( g_debug_ragdoll_removal.m_pParent != nullptr && g_debug_ragdoll_removal.m_pParent->m_Value.m_nValue != 0 )
  {
    x = 0.0;
    y = 0.0;
    v6 = 0.0;
    ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, Vector *, float *, _DWORD, _DWORD, int, int, int))debugoverlay->AddBoxOverlay)(
      a1: debugoverlay,
      a2: &origin,
      a3: &vMins,
      a4: &vMaxs,
      a5: &x,
      a6: 0,
      a7: 0,
      a8: 255,
      a9: 16,
      a10: 1084227584);
    x = origin.x;
    y = origin.y;
    v6 = origin.z + 64.0;
    ((void (__thiscall *)(IVDebugOverlay *, Vector *, float *, _DWORD, _DWORD, int, int, int))debugoverlay->AddLineOverlay)(
      a1: debugoverlay,
      a2: &origin,
      a3: &x,
      a4: 0,
      a5: 0,
      a6: 255,
      a7: 1,
      a8: 1084227584);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10163120
// Name: class C_EntityFlame __near * FireEffect(class C_BaseAnimating __near *,class C_BaseEntity __near *,float __near *,float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
C_EntityFlame *__cdecl FireEffect(C_BaseAnimating *pTarget)
{
  C_EntityFlame *v1; // eax
  C_EntityFlame *v2; // esi
  const Vector *v4; // eax
  const Vector *v5; // ebx
  int SoundSourceIndex; // eax
  CPASAttenuationFilter filter; // [esp+20h] [ebp-20h] BYREF

  v1 = (C_EntityFlame *)C_BaseEntity::operator new(stAllocateBlock: 0x998u);
  if ( v1 != nullptr )
    v2 = C_EntityFlame::C_EntityFlame(this: v1);
  else
    v2 = nullptr;
  if ( v2->InitializeAsClientEntity(this: v2, a2: nullptr, a3: false) )
  {
    C_BaseEntity::RemoveFromLeafSystem(this: v2);
    C_BaseEntity::AddFlag(this: pTarget, flags: 0x10000000);
    C_BaseEntity::SetParent(this: v2, pParentEntity: pTarget, iParentAttachment: 0);
    if ( pTarget != nullptr )
      v2->m_hEntAttached.m_Index = pTarget->GetRefEHandle(this: pTarget)->m_Index;
    else
      v2->m_hEntAttached.m_Index = -1;
    v2->OnDataChanged(this: &v2->IClientNetworkable, a2: DATA_UPDATE_CREATED);
    v4 = pTarget->GetAbsOrigin(this: pTarget);
    C_BaseEntity::SetAbsOrigin(this: v2, absOrigin: v4);
    v5 = pTarget->GetAbsOrigin(this: pTarget);
    C_RecipientFilter::C_RecipientFilter(this: &filter);
    filter.__vftable = (CPASAttenuationFilter_vtbl *)&CPASFilter::`vftable';
    C_RecipientFilter::AddRecipientsByPVS(this: &filter, origin: v5);
    filter.__vftable = (CPASAttenuationFilter_vtbl *)&CPASAttenuationFilter::`vftable';
    SoundSourceIndex = C_BaseEntity::GetSoundSourceIndex(this: pTarget);
    C_BaseEntity::EmitSound(
      &filter,
      iEntIndex: SoundSourceIndex,
      soundname: "General.BurningFlesh",
      pOrigin: nullptr,
      soundtime: 0.0,
      duration: nullptr);
    ((void (__thiscall *)(C_EntityFlame *, _DWORD))v2->SetNextClientThink)(
      a1: v2,
      a2: *(float *)(gpGlobals.m_Index + 12) + 7.0);
    C_RecipientFilter::~C_RecipientFilter(this: &filter);
    return v2;
  }
  else
  {
    C_BaseEntity::Remove(this: v2);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10163250
// Name: public: void C_BaseAnimating::IgniteRagdoll(class C_BaseAnimating __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::IgniteRagdoll(C_BaseAnimating *this, C_BaseAnimating *pSource)
{
  unsigned int m_Index; // ecx
  IHandleEntity *m_pEntity; // eax
  C_BaseEntity *v5; // esi
  C_BaseAnimating *v6; // eax
  C_BaseEntity *v7; // edi
  C_EntityFlame *v8; // eax

  m_Index = pSource->m_hEffectEntity.m_Index;
  if ( m_Index != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
  {
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    if ( m_pEntity != nullptr )
    {
      v5 = (C_BaseEntity *)__RTDynamicCast(
                             inptr: m_pEntity,
                             VfDelta: 0,
                             SrcType: &C_BaseEntity `RTTI Type Descriptor',
                             TargetType: &C_EntityFlame `RTTI Type Descriptor',
                             isReference: 0);
      v6 = (C_BaseAnimating *)__RTDynamicCast(
                                inptr: this,
                                VfDelta: 0,
                                SrcType: &C_BaseAnimating `RTTI Type Descriptor',
                                TargetType: &C_ClientRagdoll `RTTI Type Descriptor',
                                isReference: 0);
      v7 = v6;
      if ( v5 != nullptr )
      {
        v8 = FireEffect(pTarget: v6, pServerFire: v5, flScaleEnd: nullptr, flTimeStart: nullptr, flTimeEnd: nullptr);
        C_BaseEntity::SetEffectEntity(this: v7, pEffectEnt: v8);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101632E0
// Name: public: virtual void CRagdollLRURetirement::LevelInitPreEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRagdollLRURetirement::LevelInitPreEntity(CRagdollLRURetirement *this)
{
  this->m_iMaxRagdolls = -1;
  CUtlLinkedList<CBreakableHelper::BreakableList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBreakableHelper::BreakableList_t,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<CEnvWindShared::WindVariationEvent_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared::WindVariationEvent_t,unsigned short>,unsigned short> > *)&this->m_LRUImportantRagdolls);
  CUtlLinkedList<CBreakableHelper::BreakableList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBreakableHelper::BreakableList_t,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<CEnvWindShared::WindVariationEvent_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared::WindVariationEvent_t,unsigned short>,unsigned short> > *)&this->m_LRU);
}

//------------------------------------------------------------------------------
// Address: 0x10163300
// Name: public: void C_BaseAnimating::TransferDissolveFrom(class C_BaseAnimating __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseAnimating::TransferDissolveFrom(C_BaseAnimating *this, C_BaseAnimating *pSource)
{
  unsigned int m_Index; // ecx
  IHandleEntity *m_pEntity; // eax
  float *v5; // edi
  C_BaseAnimating *v6; // eax
  float flTime; // xmm0_4
  C_EntityDissolve *v8; // esi
  int v9; // eax
  int v10; // edx

  m_Index = pSource->m_hEffectEntity.m_Index;
  if ( m_Index != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
  {
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    if ( m_pEntity != nullptr )
    {
      v5 = (float *)__RTDynamicCast(
                      inptr: m_pEntity,
                      VfDelta: 0,
                      SrcType: &C_BaseEntity `RTTI Type Descriptor',
                      TargetType: &C_EntityDissolve `RTTI Type Descriptor',
                      isReference: 0);
      if ( v5 != nullptr )
      {
        v6 = (C_BaseAnimating *)__RTDynamicCast(
                                  inptr: this,
                                  VfDelta: 0,
                                  SrcType: &C_BaseAnimating `RTTI Type Descriptor',
                                  TargetType: &C_ClientRagdoll `RTTI Type Descriptor',
                                  isReference: 0);
        if ( v6 != nullptr )
        {
          flTime = v5[609];
          *(float *)&v6[1].C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = flTime;
          v8 = DissolveEffect(pTarget: v6, flTime);
          if ( v8 != nullptr )
          {
            C_BaseEntity::SetRenderMode(
              this: v8,
              nRenderMode: (RenderMode_t)*((unsigned __int8 *)v5 + 591),
              bForceUpdate: false);
            C_BaseEntity::SetRenderFX(
              this: v8,
              nRenderFX: (RenderFx_t)*((unsigned __int8 *)v5 + 590),
              flStartTime: 3.4028235e38,
              flDuration: 0.0);
            if ( v8->m_clrRender.m_Value.r != 0xFF )
              v8->m_clrRender.m_Value.r = -1;
            if ( v8->m_clrRender.m_Value.g != 0xFF )
              v8->m_clrRender.m_Value.g = -1;
            if ( v8->m_clrRender.m_Value.b != 0xFF )
              v8->m_clrRender.m_Value.b = -1;
            C_BaseEntity::SetRenderAlpha(this: v8, a: 0xFFu);
            C_BaseEntity::SetRenderAlpha(this: (C_BaseEntity *)v5, a: 0);
            v8->m_vDissolverOrigin.x = v5[618];
            v8->m_vDissolverOrigin.y = v5[619];
            v8->m_vDissolverOrigin.z = v5[620];
            v9 = *((_DWORD *)v5 + 616);
            v8->m_nDissolveType = v9;
            if ( v9 == 3 )
            {
              v10 = *((_DWORD *)v5 + 621);
              v8->m_flFadeOutStart = 0.2;
              v8->m_nMagnitude = v10;
              v8->m_flFadeOutModelStart = 0.1;
              v8->m_flFadeOutModelLength = 0.050000001;
              v8->m_flFadeInLength = 0.1;
            }
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101634A0
// Name: public: CRagdollLRURetirement::CRagdollLRURetirement(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CRagdollLRURetirement *__thiscall CRagdollLRURetirement::CRagdollLRURetirement(
        CRagdollLRURetirement *this,
        const char *name)
{
  UtlLinkedListElem_t<CRagdollEntry,unsigned short> *m_pMemory; // edx

  CAutoGameSystemPerFrame::CAutoGameSystemPerFrame(this, name);
  this->__vftable = (CRagdollLRURetirement_vtbl *)&CRagdollLRURetirement::`vftable';
  this->m_LRU.m_Memory.m_pMemory = nullptr;
  this->m_LRU.m_Memory.m_nAllocationCount = 0;
  this->m_LRU.m_Memory.m_nGrowSize = 0;
  this->m_LRU.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_LRU.m_FirstFree = 0xFFFF;
  this->m_LRU.m_pElements = this->m_LRU.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_LRU.m_Head = -1;
  this->m_LRU.m_NumAlloced = 0;
  this->m_LRUImportantRagdolls.m_Memory.m_pMemory = nullptr;
  this->m_LRUImportantRagdolls.m_Memory.m_nAllocationCount = 0;
  this->m_LRUImportantRagdolls.m_Memory.m_nGrowSize = 0;
  this->m_LRUImportantRagdolls.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_LRUImportantRagdolls.m_FirstFree = 0xFFFF;
  m_pMemory = this->m_LRUImportantRagdolls.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_LRUImportantRagdolls.m_Head = -1;
  this->m_LRUImportantRagdolls.m_NumAlloced = 0;
  this->m_LRUImportantRagdolls.m_pElements = m_pMemory;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10163510
// Name: public: virtual CRagdollLRURetirement::~CRagdollLRURetirement(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRagdollLRURetirement::~CRagdollLRURetirement(CRagdollLRURetirement *this)
{
  CUtlLinkedList<CBreakableHelper::BreakableList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBreakableHelper::BreakableList_t,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<CEnvWindShared::WindVariationEvent_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared::WindVariationEvent_t,unsigned short>,unsigned short> > *)&this->m_LRUImportantRagdolls);
  if ( this->m_LRUImportantRagdolls.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_LRUImportantRagdolls.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_LRUImportantRagdolls.m_Memory.m_pMemory);
      this->m_LRUImportantRagdolls.m_Memory.m_pMemory = nullptr;
    }
    this->m_LRUImportantRagdolls.m_Memory.m_nAllocationCount = 0;
  }
  CUtlLinkedList<CBreakableHelper::BreakableList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBreakableHelper::BreakableList_t,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<CEnvWindShared::WindVariationEvent_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared::WindVariationEvent_t,unsigned short>,unsigned short> > *)&this->m_LRU);
  if ( this->m_LRU.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_LRU.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_LRU.m_Memory.m_pMemory);
      this->m_LRU.m_Memory.m_pMemory = nullptr;
    }
    this->m_LRU.m_Memory.m_nAllocationCount = 0;
  }
  IGameSystemPerFrame::~IGameSystemPerFrame(this);
}

//------------------------------------------------------------------------------
// Address: 0x101635C0
// Name: public: virtual void CRagdollLRURetirement::Update(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRagdollLRURetirement::Update(CRagdollLRURetirement *this, float frametime)
{
  CRagdollLRURetirement *v2; // edi
  unsigned __int16 m_Head; // ax
  UtlLinkedListElem_t<CRagdollEntry,unsigned short> *m_pMemory; // ecx
  int v5; // esi
  unsigned int m_Index; // eax
  UtlLinkedListElem_t<CRagdollEntry,unsigned short> *v7; // ebx
  IHandleEntity *m_pEntity; // ecx
  IHandleEntity_vtbl *v9; // edx
  float m_flForcedRetireTime; // xmm0_4
  unsigned __int16 v11; // bx
  UtlLinkedListElem_t<CRagdollEntry,unsigned short> *v12; // eax
  int v13; // esi
  int m_Next; // ecx
  unsigned int v15; // eax
  C_BaseAnimating *v16; // ecx
  IPhysicsObject *m_pPhysicsObject; // eax
  bool v18; // al
  unsigned __int16 v19; // bx
  UtlLinkedListElem_t<CRagdollEntry,unsigned short> *v20; // ecx
  unsigned int v21; // esi
  unsigned int v22; // eax
  IHandleEntity *v23; // ecx
  IHandleEntity_vtbl *v24; // edx
  UtlLinkedListElem_t<CRagdollEntry,unsigned short> *v25; // [esp+Ch] [ebp-14h]
  int next; // [esp+10h] [ebp-10h]
  int nexta; // [esp+10h] [ebp-10h]
  int nextb; // [esp+10h] [ebp-10h]
  int iMaxRagdollCount; // [esp+14h] [ebp-Ch]
  unsigned __int16 i; // [esp+1Ch] [ebp-4h]
  int ia; // [esp+1Ch] [ebp-4h]
  unsigned __int16 ib; // [esp+1Ch] [ebp-4h]

  v2 = this;
  iMaxRagdollCount = this->m_iMaxRagdolls;
  if ( iMaxRagdollCount == -1 )
  {
    if ( g_ragdoll_maxcount.m_pParent != nullptr )
      iMaxRagdollCount = g_ragdoll_maxcount.m_pParent->m_Value.m_nValue;
    else
      iMaxRagdollCount = 0;
  }
  if ( g_RagdollLVManager.m_bLowViolence )
    iMaxRagdollCount = 0;
  this->m_iRagdollCount = 0;
  this->m_iSimulatedRagdollCount = 0;
  m_Head = this->m_LRU.m_Head;
  i = m_Head;
  if ( m_Head != 0xFFFF )
  {
    while ( 1 )
    {
      m_pMemory = v2->m_LRU.m_Memory.m_pMemory;
      v5 = m_Head;
      m_Index = m_pMemory[v5].m_Element.m_hRagdoll.m_Index;
      v7 = &m_pMemory[v5];
      v25 = &m_pMemory[v5];
      next = m_pMemory[v5].m_Next;
      if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      {
        m_pEntity = nullptr;
      }
      else
      {
        m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
        if ( m_pEntity != nullptr )
        {
          v9 = m_pEntity[591].__vftable;
          if ( v9 != (IHandleEntity_vtbl *)-1 )
          {
            if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)v9].m_SerialNumber == (unsigned int)v9 >> 16
              && g_pEntityList->m_EntPtrArray[(unsigned __int16)v9].m_pEntity != nullptr )
            {
              goto LABEL_21;
            }
            v7 = v25;
          }
        }
      }
      m_flForcedRetireTime = v7->m_Element.m_flForcedRetireTime;
      if ( m_flForcedRetireTime != 0.0 && m_flForcedRetireTime <= *(float *)(gpGlobals.m_Index + 12) )
      {
        ((void (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[40].SetRefEHandle)(a1: m_pEntity);
        CUtlLinkedList<CBreakableHelper::BreakableList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBreakableHelper::BreakableList_t,unsigned short>,unsigned short>>::Unlink(
          this: &v2->m_LRU,
          elem: i);
        v2->m_LRU.m_Memory.m_pMemory[v5].m_Next = v2->m_LRU.m_FirstFree;
        v2->m_LRU.m_FirstFree = i;
      }
LABEL_21:
      i = next;
      if ( next >= 0xFFFF )
        break;
      m_Head = next;
    }
  }
  v11 = v2->m_LRU.m_Head;
  if ( v11 != 0xFFFF )
  {
    do
    {
      v12 = v2->m_LRU.m_Memory.m_pMemory;
      v13 = v11;
      m_Next = v12[v13].m_Next;
      v15 = v12[v13].m_Element.m_hRagdoll.m_Index;
      nexta = m_Next;
      if ( v15 != -1
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)v15].m_SerialNumber == HIWORD(v15)
        && (v16 = (C_BaseAnimating *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v15].m_pEntity,
            ia = (int)v16,
            v16 != nullptr) )
      {
        ++this->m_iRagdollCount;
        m_pPhysicsObject = v16->m_pPhysicsObject;
        if ( m_pPhysicsObject != nullptr )
        {
          v18 = m_pPhysicsObject->IsAsleep(this: v16->m_pPhysicsObject);
          v16 = (C_BaseAnimating *)ia;
          if ( !v18 )
            ++this->m_iSimulatedRagdollCount;
        }
        if ( this->m_LRU.m_ElementCount > iMaxRagdollCount && ShouldRemoveThisRagdoll(pRagdoll: v16) == 1 )
        {
          (*(void (__thiscall **)(int))(*(_DWORD *)ia + 484))(a1: ia);
          CUtlLinkedList<CBreakableHelper::BreakableList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBreakableHelper::BreakableList_t,unsigned short>,unsigned short>>::Unlink(
            this: &v2->m_LRU,
            elem: v11);
          v2->m_LRU.m_Memory.m_pMemory[v11].m_Next = v2->m_LRU.m_FirstFree;
          v2->m_LRU.m_FirstFree = v11;
          return;
        }
      }
      else
      {
        CUtlLinkedList<CBreakableHelper::BreakableList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBreakableHelper::BreakableList_t,unsigned short>,unsigned short>>::Unlink(
          this: &v2->m_LRU,
          elem: v11);
        v2->m_LRU.m_Memory.m_pMemory[v13].m_Next = v2->m_LRU.m_FirstFree;
        v2->m_LRU.m_FirstFree = v11;
      }
      v11 = nexta;
    }
    while ( nexta < 0xFFFF );
    v2 = this;
  }
  v19 = v2->m_LRU.m_Head;
  ib = v19;
  if ( v19 != 0xFFFF )
  {
    do
    {
      if ( this->m_LRU.m_ElementCount <= iMaxRagdollCount )
        return;
      v20 = this->m_LRU.m_Memory.m_pMemory;
      v21 = v19;
      v22 = v20[v21].m_Element.m_hRagdoll.m_Index;
      nextb = v20[v21].m_Next;
      if ( v22 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v22].m_SerialNumber != HIWORD(v22) )
      {
        v23 = nullptr;
      }
      else
      {
        v23 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v22].m_pEntity;
        if ( v23 != nullptr )
        {
          v24 = v23[591].__vftable;
          if ( v24 != (IHandleEntity_vtbl *)-1 )
          {
            if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)v24].m_SerialNumber == (unsigned int)v24 >> 16
              && g_pEntityList->m_EntPtrArray[(unsigned __int16)v24].m_pEntity != nullptr )
            {
              goto LABEL_46;
            }
            v19 = ib;
          }
        }
      }
      ((void (__thiscall *)(IHandleEntity *))v23->__vftable[40].SetRefEHandle)(a1: v23);
      CUtlLinkedList<CBreakableHelper::BreakableList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBreakableHelper::BreakableList_t,unsigned short>,unsigned short>>::Unlink(
        this: &this->m_LRU,
        elem: v19);
      this->m_LRU.m_Memory.m_pMemory[v21].m_Next = this->m_LRU.m_FirstFree;
      this->m_LRU.m_FirstFree = v19;
LABEL_46:
      v19 = nextb;
      ib = nextb;
    }
    while ( nextb < 0xFFFF );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101638D0
// Name: public: void CRagdollLRURetirement::MoveToTopOfLRU(class C_BaseAnimating __near *,bool,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRagdollLRURetirement::MoveToTopOfLRU(
        CRagdollLRURetirement *this,
        C_BaseAnimating *pRagdoll,
        bool bImportant,
        float flForcedRetireTime)
{
  CUtlLinkedList<CRagdollEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRagdollEntry,unsigned short>,unsigned short> > *p_m_LRUImportantRagdolls; // esi
  unsigned __int16 v6; // ax
  int v7; // edi
  int v8; // eax
  int m_nValue; // eax
  int m_Head; // ebx
  unsigned int v11; // eax
  IHandleEntity *m_pEntity; // ecx
  unsigned __int16 m_Next; // si
  CUtlLinkedList<CRagdollEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRagdollEntry,unsigned short>,unsigned short> > *p_m_LRU; // edi
  UtlLinkedListElem_t<CRagdollEntry,unsigned short> *m_pMemory; // ebx
  unsigned int v16; // eax
  C_BaseAnimating *v17; // ecx
  unsigned int v18; // ebx
  int v19; // edi
  UtlLinkedListElem_t<CRagdollEntry,unsigned short> *v20; // eax
  unsigned int m_Index; // [esp+Ch] [ebp-8h]
  CUtlLinkedList<CRagdollEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRagdollEntry,unsigned short>,unsigned short> > *bImportanta; // [esp+20h] [ebp+Ch]

  if ( bImportant )
  {
    if ( pRagdoll != nullptr )
      m_Index = pRagdoll->GetRefEHandle(this: pRagdoll)->m_Index;
    else
      m_Index = -1;
    p_m_LRUImportantRagdolls = &this->m_LRUImportantRagdolls;
    v6 = CUtlLinkedList<CRagdollEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRagdollEntry,unsigned short>,unsigned short>>::AllocInternal(
           this: &this->m_LRUImportantRagdolls,
           multilist: false);
    v7 = v6;
    if ( v6 != 0xFFFF )
    {
      CUtlLinkedList<CBreakableHelper::BreakableList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBreakableHelper::BreakableList_t,unsigned short>,unsigned short>>::LinkBefore(
        this: &this->m_LRUImportantRagdolls,
        before: 0xFFFFu,
        elem: v6);
      v8 = (int)&p_m_LRUImportantRagdolls->m_Memory.m_pMemory[v7];
      if ( v8 != 0 )
      {
        *(_DWORD *)v8 = m_Index;
        *(float *)(v8 + 4) = flForcedRetireTime;
      }
    }
    if ( g_ragdoll_important_maxcount.m_pParent != nullptr )
      m_nValue = g_ragdoll_important_maxcount.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    if ( this->m_LRUImportantRagdolls.m_ElementCount > m_nValue )
    {
      m_Head = this->m_LRUImportantRagdolls.m_Head;
      v11 = p_m_LRUImportantRagdolls->m_Memory.m_pMemory[m_Head].m_Element.m_hRagdoll.m_Index;
      if ( v11 != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_SerialNumber == HIWORD(v11) )
      {
        m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_pEntity;
        if ( m_pEntity != nullptr )
        {
          ((void (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[40].SetRefEHandle)(a1: m_pEntity);
          CUtlLinkedList<CBreakableHelper::BreakableList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBreakableHelper::BreakableList_t,unsigned short>,unsigned short>>::Unlink(
            this: p_m_LRUImportantRagdolls,
            elem: m_Head);
          p_m_LRUImportantRagdolls->m_Memory.m_pMemory[m_Head].m_Next = p_m_LRUImportantRagdolls->m_FirstFree;
          p_m_LRUImportantRagdolls->m_FirstFree = m_Head;
        }
      }
    }
  }
  else
  {
    m_Next = this->m_LRU.m_Head;
    if ( m_Next != 0xFFFF )
    {
      p_m_LRU = &this->m_LRU;
      m_pMemory = this->m_LRU.m_Memory.m_pMemory;
      bImportanta = &this->m_LRU;
      while ( 1 )
      {
        v16 = m_pMemory[m_Next].m_Element.m_hRagdoll.m_Index;
        if ( v16 == -1
          || (p_m_LRU = bImportanta, g_pEntityList->m_EntPtrArray[(unsigned __int16)v16].m_SerialNumber != HIWORD(v16)) )
        {
          v17 = nullptr;
        }
        else
        {
          v17 = (C_BaseAnimating *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v16].m_pEntity;
        }
        if ( v17 == pRagdoll )
          break;
        m_Next = m_pMemory[m_Next].m_Next;
        if ( m_Next == 0xFFFF )
          goto LABEL_26;
      }
      CUtlLinkedList<CBreakableHelper::BreakableList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBreakableHelper::BreakableList_t,unsigned short>,unsigned short>>::Unlink(
        this: p_m_LRU,
        elem: m_Next);
      p_m_LRU->m_Memory.m_pMemory[m_Next].m_Next = p_m_LRU->m_FirstFree;
      p_m_LRU->m_FirstFree = m_Next;
    }
LABEL_26:
    if ( pRagdoll != nullptr )
      v18 = pRagdoll->GetRefEHandle(this: pRagdoll)->m_Index;
    else
      v18 = -1;
    v19 = (unsigned __int16)CUtlLinkedList<CRagdollEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRagdollEntry,unsigned short>,unsigned short>>::AllocInternal(
                              this: &this->m_LRU,
                              multilist: false);
    if ( (_WORD)v19 != 0xFFFF )
    {
      CUtlLinkedList<CBreakableHelper::BreakableList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBreakableHelper::BreakableList_t,unsigned short>,unsigned short>>::LinkBefore(
        this: &this->m_LRU,
        before: 0xFFFFu,
        elem: v19);
      v20 = &this->m_LRU.m_Memory.m_pMemory[v19];
      if ( v20 != nullptr )
      {
        v20->m_Element.m_hRagdoll.m_Index = v18;
        v20->m_Element.m_flForcedRetireTime = flForcedRetireTime;
      }
    }
  }
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x101F1E50
// Name: void RagdollSetupCollisions(struct ragdoll_t __near &,struct vcollide_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall RagdollSetupCollisions(int a1@<ebx>, ragdoll_t *ragdoll, vcollide_t *pCollide, unsigned int modelIndex)
{
  IPhysicsCollisionSet *v5; // ebx
  IVPhysicsKeyParser *v6; // esi
  const char *v7; // eax
  void (__thiscall *ParseCollisionRules)(IVPhysicsKeyParser *, ragdollcollisionrules_t *, IVPhysicsKeyHandler *); // edx
  ragdoll_t *v9; // ecx
  int listCount; // eax
  int v11; // edi
  int v12; // esi
  int v13; // esi
  int *p_parentIndex; // edi
  ragdollcollisionrules_t rules; // [esp+4h] [ebp-8h] BYREF
  char bFoundRules_3; // [esp+1Bh] [ebp+Fh]

  if ( pCollide != nullptr && physics->FindCollisionSet(this: physics, a2: modelIndex) == nullptr )
  {
    v5 = (IPhysicsCollisionSet *)((int (__stdcall *)(unsigned int, int))physics->FindOrCreateCollisionSet)(
                                   a1: modelIndex,
                                   a2: *(_WORD *)pCollide & 0x7FFF);
    if ( v5 != nullptr )
    {
      bFoundRules_3 = 0;
      v6 = (IVPhysicsKeyParser *)((int (__thiscall *)(IPhysicsCollision *, vcollide_t *, int))physcollision->VPhysicsKeyParserCreate)(
                                   a1: physcollision,
                                   a2: pCollide,
                                   a3: a1);
      while ( !v6->Finished(this: v6) )
      {
        v7 = v6->GetCurrentBlockName(this: v6);
        if ( _V_stricmp(s1: v7, s2: "collisionrules") != 0 )
        {
          v6->SkipBlock(this: v6);
        }
        else
        {
          ParseCollisionRules = v6->ParseCollisionRules;
          rules.pCollisionSet = v5;
          rules.bSelfCollisions = 1;
          ParseCollisionRules(this: v6, a2: &rules, a3: nullptr);
          bFoundRules_3 = 1;
        }
      }
      physcollision->VPhysicsKeyParserDestroy(this: physcollision, a2: v6);
      if ( bFoundRules_3 == 0 )
      {
        v9 = ragdoll;
        listCount = ragdoll->listCount;
        v11 = 0;
        if ( ragdoll->listCount > 0 )
        {
          do
          {
            v12 = v11 + 1;
            if ( v11 + 1 < listCount )
            {
              do
                v5->EnableCollisions(this: v5, a2: v11, a3: v12++);
              while ( v12 < ragdoll->listCount );
              v12 = v11 + 1;
              v9 = ragdoll;
            }
            listCount = v9->listCount;
            v11 = v12;
          }
          while ( v12 < v9->listCount );
        }
        v13 = 0;
        if ( v9->listCount > 0 )
        {
          p_parentIndex = &v9->list[0].parentIndex;
          do
          {
            if ( *p_parentIndex >= 0 )
            {
              v5->DisableCollisions(this: v5, a2: v13, a3: *p_parentIndex);
              v9 = ragdoll;
            }
            ++v13;
            p_parentIndex += 6;
          }
          while ( v13 < v9->listCount );
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F1F90
// Name: void RagdollDestroy(struct ragdoll_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RagdollDestroy(ragdoll_t *ragdoll)
{
  int v1; // ebx
  IPhysicsConstraint **p_pConstraint; // esi
  int v3; // ebx
  IPhysicsObject **p_pObject; // esi

  if ( ragdoll->listCount != 0 )
  {
    v1 = 0;
    if ( ragdoll->listCount > 0 )
    {
      p_pConstraint = &ragdoll->list[0].pConstraint;
      do
      {
        physenv->DestroyConstraint(this: physenv, a2: *p_pConstraint);
        *p_pConstraint = nullptr;
        ++v1;
        p_pConstraint += 6;
      }
      while ( v1 < ragdoll->listCount );
    }
    v3 = 0;
    if ( ragdoll->listCount > 0 )
    {
      p_pObject = &ragdoll->list[0].pObject;
      do
      {
        if ( *p_pObject != nullptr )
          physenv->DestroyObject(this: physenv, a2: *p_pObject);
        *p_pObject = nullptr;
        ++v3;
        p_pObject += 6;
      }
      while ( v3 < ragdoll->listCount );
    }
    physenv->DestroyConstraintGroup(this: physenv, a2: ragdoll->pGroup);
    ragdoll->pGroup = nullptr;
    ragdoll->listCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F2020
// Name: bool RagdollIsAsleep(struct ragdoll_t const __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl RagdollIsAsleep(const ragdoll_t *ragdoll)
{
  int v1; // edi
  IPhysicsObject **i; // esi

  v1 = 0;
  if ( ragdoll->listCount <= 0 )
    return 1;
  for ( i = &ragdoll->list[0].pObject; *i == nullptr || (*i)->IsAsleep(this: *i); i += 6 )
  {
    if ( ++v1 >= ragdoll->listCount )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101F2060
// Name: public: virtual void CRagdollLRURetirement::FrameUpdatePostEntityThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRagdollLRURetirement::FrameUpdatePostEntityThink(CRagdollLRURetirement *this)
{
  ((void (__stdcall *)(_DWORD))this->Update)(a1: 0);
}

//------------------------------------------------------------------------------
// Address: 0x101F2080
// Name: void RagdollActivate(struct ragdoll_t __near &,struct vcollide_t __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RagdollActivate(ragdoll_t *ragdoll, vcollide_t *pCollide, unsigned int modelIndex, bool bForceWake)
{
  IPhysicsObject **p_pObject; // edi
  IPhysicsObject *v6; // esi
  unsigned __int16 v7; // ax
  int v8; // esi
  IPhysicsObject **v9; // edi
  int i; // [esp+14h] [ebp+8h]

  RagdollSetupCollisions(a1: (int)ragdoll, ragdoll, pCollide, modelIndex);
  i = 0;
  if ( ragdoll->listCount > 0 )
  {
    p_pObject = &ragdoll->list[0].pObject;
    do
    {
      v6 = *p_pObject;
      v7 = (*p_pObject)->GetGameFlags(this: *p_pObject);
      v6->SetGameFlags(this: v6, a2: v7 | 0x10);
      (*p_pObject)->EnableCollisions(this: *p_pObject, a2: true);
      if ( bForceWake )
        (*p_pObject)->Wake(this: *p_pObject);
      p_pObject += 6;
      ++i;
    }
    while ( i < ragdoll->listCount );
  }
  if ( ragdoll->pGroup != nullptr )
  {
    ragdoll->pGroup->Activate(this: ragdoll->pGroup);
    if ( !bForceWake )
    {
      v8 = 0;
      if ( ragdoll->listCount > 0 )
      {
        v9 = &ragdoll->list[0].pObject;
        do
        {
          (*v9)->Sleep(this: *v9);
          ++v8;
          v9 += 6;
        }
        while ( v8 < ragdoll->listCount );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F2130
// Name: void RagdollApplyAnimationAsVelocity(struct ragdoll_t __near &,struct matrix3x4_t const __near *,struct matrix3x4_t const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RagdollApplyAnimationAsVelocity(
        ragdoll_t *ragdoll,
        const matrix3x4_t *pPrevBones,
        const matrix3x4_t *pCurrentBones,
        float dt)
{
  int v4; // ebx
  IPhysicsObject **p_pObject; // esi
  int *boneIndex; // edi
  Vector velocity; // [esp+10h] [ebp-24h] BYREF
  Vector localAngVelocity; // [esp+1Ch] [ebp-18h] BYREF
  Vector angVel; // [esp+28h] [ebp-Ch] BYREF

  v4 = 0;
  if ( ragdoll->listCount > 0 )
  {
    p_pObject = &ragdoll->list[0].pObject;
    boneIndex = ragdoll->boneIndex;
    do
    {
      CalcBoneDerivatives(&velocity, &angVel, prev: &pPrevBones[*boneIndex], current: &pCurrentBones[*boneIndex], dt);
      (*p_pObject)->WorldToLocalVector(this: *p_pObject, a2: &localAngVelocity, a3: &angVel);
      (*p_pObject)->AddVelocity(this: *p_pObject, a2: &velocity, a3: &localAngVelocity);
      ++v4;
      ++boneIndex;
      p_pObject += 6;
    }
    while ( v4 < ragdoll->listCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F21C0
// Name: bool RagdollGetBoneMatrix(struct ragdoll_t const __near &,class CBoneAccessor __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl RagdollGetBoneMatrix(const ragdoll_t *ragdoll, CBoneAccessor *pBoneToWorld, int objectIndex)
{
  int v3; // eax
  int v5; // esi
  int parentIndex; // eax
  Vector out; // [esp+4h] [ebp-Ch] BYREF

  v3 = ragdoll->boneIndex[objectIndex];
  if ( v3 < 0 || ragdoll->list[objectIndex].pObject == nullptr )
    return 0;
  v5 = v3;
  ragdoll->list[objectIndex].pObject->GetPositionMatrix(
    this: ragdoll->list[objectIndex].pObject,
    a2: &pBoneToWorld->m_pBones[v3]);
  parentIndex = ragdoll->list[objectIndex].parentIndex;
  if ( parentIndex >= 0 && !ragdoll->allowStretch )
  {
    VectorTransform(
      in1: &ragdoll->list[objectIndex].originParentSpace.x,
      in2: &pBoneToWorld->m_pBones[ragdoll->boneIndex[parentIndex]],
      out: &out.x);
    MatrixSetColumn(in: &out, column: 3, out: &pBoneToWorld->m_pBones[v5]);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101F2310
// Name: public: void CRagdollLowViolenceManager::SetLowViolence(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRagdollLowViolenceManager::SetLowViolence(CRagdollLowViolenceManager *this, const char *pMapName)
{
  int v3; // eax

  this->m_bLowViolence = UTIL_IsLowViolence();
  if ( g_pGameRules != nullptr && g_pGameRules->IsMultiplayer(this: g_pGameRules) )
    this->m_bLowViolence = false;
  if ( hl2_episodic.m_pParent != nullptr && hl2_episodic.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( _V_stricmp(s1: pMapName, s2: "ep1_citadel_02") != 0 && _V_stricmp(s1: pMapName, s2: "ep1_citadel_02b") != 0 )
    {
      v3 = _V_stricmp(s1: pMapName, s2: "ep1_citadel_03");
      goto LABEL_13;
    }
  }
  else if ( _V_stricmp(s1: pMapName, s2: "d3_citadel_03") != 0
         && _V_stricmp(s1: pMapName, s2: "d3_citadel_04") != 0
         && _V_stricmp(s1: pMapName, s2: "d3_citadel_05") != 0 )
  {
    v3 = _V_stricmp(s1: pMapName, s2: "d3_breen_01");
LABEL_13:
    if ( v3 != 0 )
      return;
  }
  this->m_bLowViolence = false;
}

//------------------------------------------------------------------------------
// Address: 0x101F23D0
// Name: RagdollAddSolids
// Source: json
//------------------------------------------------------------------------------
void __cdecl RagdollAddSolids(
        IPhysicsEnvironment *pPhysEnv,
        ragdoll_t *ragdoll,
        const ragdollparams_t *params,
        cache_ragdollsolid_t *pSolids,
        int solidCount,
        const cache_ragdollconstraint_t *pConstraints,
        int constraintCount)
{
  const ragdollparams_t *v7; // edx
  const studiohdr_t *m_pStudioHdr; // eax
  int studiohdr2index; // ecx
  int v10; // ebx
  int v11; // esi
  char *v12; // ecx
  int v13; // eax
  char *name; // eax
  int v15; // esi
  int *p_parentIndex; // eax
  int j; // ecx
  __int16 *p_childIndex; // esi
  IPhysicsObject **p_pObject; // ebx
  __int16 *p_boneIndex; // esi
  int v21; // edi
  IPhysicsObject *v22; // eax
  int v23; // ecx
  int v24; // edi
  IPhysicsObject *pObject; // ecx
  IPhysicsObject *v26; // edi
  unsigned __int16 v27; // ax
  matrix3x4_t xform; // [esp+Ch] [ebp-44h] BYREF
  Vector position; // [esp+3Ch] [ebp-14h] BYREF
  int i; // [esp+48h] [ebp-8h]
  char *v31; // [esp+4Ch] [ebp-4h]
  int *constraintCounta; // [esp+70h] [ebp+20h]

  v7 = params;
  m_pStudioHdr = params->pStudioHdr->m_pStudioHdr;
  studiohdr2index = m_pStudioHdr->studiohdr2index;
  v10 = constraintCount;
  if ( studiohdr2index != 0
    && (v11 = *(_DWORD *)&m_pStudioHdr->name[studiohdr2index + 8], v12 = (char *)m_pStudioHdr + studiohdr2index,
                                                                   v11 != 0)
    && &v12[v11] != nullptr )
  {
    v13 = *((_DWORD *)v12 + 5);
    if ( v13 == 0 )
    {
      v31 = nullptr;
      goto LABEL_9;
    }
    name = &v12[v13];
  }
  else
  {
    name = m_pStudioHdr->name;
  }
  v31 = name;
LABEL_9:
  v15 = solidCount;
  if ( solidCount > 0 )
  {
    p_parentIndex = &ragdoll->list[0].parentIndex;
    for ( j = solidCount; j != 0; --j )
    {
      *p_parentIndex = -1;
      p_parentIndex += 6;
    }
  }
  if ( constraintCount > 0 )
  {
    p_childIndex = &pConstraints->childIndex;
    do
    {
      ragdoll->list[*p_childIndex].parentIndex = *(p_childIndex - 1);
      MatrixGetColumn(
        in: (const matrix3x4_t *)(p_childIndex - 25),
        column: 3,
        out: &ragdoll->list[*p_childIndex].originParentSpace);
      p_childIndex += 50;
      --v10;
    }
    while ( v10 != 0 );
    v7 = params;
    v15 = solidCount;
  }
  i = 0;
  if ( v15 <= 0 )
  {
    ragdoll->listCount = v15;
  }
  else
  {
    p_pObject = &ragdoll->list[0].pObject;
    constraintCounta = ragdoll->boneIndex;
    p_boneIndex = &pSolids->boneIndex;
    while ( 1 )
    {
      if ( v7->fixedConstraints )
        *((_DWORD *)p_boneIndex - 11) = 1148846080;
      *constraintCounta = *p_boneIndex;
      *((_DWORD *)p_boneIndex - 6) = v31;
      v21 = *((_DWORD *)p_boneIndex - 1);
      *((_DWORD *)p_boneIndex - 5) = v7->pGameData;
      v22 = pPhysEnv->CreatePolyObject(
              this: pPhysEnv,
              a2: v7->pCollide->solids[p_boneIndex[1]],
              a3: v21,
              a4: &vec3_origin,
              a5: &vec3_angle,
              a6: p_boneIndex - 24);
      v23 = i;
      *p_pObject = v22;
      v22->SetGameIndex(this: v22, a2: v23);
      v24 = (int)p_pObject[2];
      MatrixCopy(in: &params->pCurrentBones[*constraintCounta], out: &xform);
      if ( v24 >= 0 )
      {
        pObject = ragdoll->list[v24].pObject;
        pObject->LocalToWorld(this: pObject, a2: &position, a3: (const Vector *)p_pObject - 1);
        MatrixSetColumn(in: &position, column: 3, out: &xform);
      }
      (*p_pObject)->SetPositionMatrix(this: *p_pObject, a2: &xform, a3: true);
      v26 = *p_pObject;
      v27 = (*p_pObject)->GetGameFlags(this: *p_pObject);
      v26->SetGameFlags(this: v26, a2: v27 | 8);
      ++constraintCounta;
      p_boneIndex += 26;
      p_pObject += 6;
      if ( ++i >= solidCount )
        break;
      v7 = params;
    }
    ragdoll->listCount = solidCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F25B0
// Name: RagdollAddConstraints
// Source: json
//------------------------------------------------------------------------------
void __usercall RagdollAddConstraints(
        ragdoll_t *ragdoll@<edi>,
        const cache_ragdollconstraint_t *pConstraints@<ecx>,
        int constraintCount@<eax>,
        IPhysicsEnvironment *pPhysEnv,
        const ragdollparams_t *params)
{
  __int16 *p_childIndex; // esi
  float jointFrictionScale; // xmm0_4
  int v7; // eax
  int v8; // ebx
  __int64 v9; // xmm0_8
  IPhysicsObject *v10; // ecx
  void (__thiscall *GetPositionMatrix)(IPhysicsObject *, matrix3x4_t *); // edx
  IPhysicsConstraint *(__thiscall *CreateFixedConstraint)(IPhysicsEnvironment *, IPhysicsObject *, IPhysicsObject *, IPhysicsConstraintGroup *, const constraint_fixedparams_t *); // eax
  IPhysicsObject *v13; // edx
  int v14; // ebx
  IPhysicsObject *v15; // edx
  IPhysicsConstraint *(__thiscall *CreateRagdollConstraint)(IPhysicsEnvironment *, IPhysicsObject *, IPhysicsObject *, IPhysicsConstraintGroup *, const constraint_ragdollparams_t *); // edx
  IPhysicsObject *v17; // ecx
  int v18; // eax
  IPhysicsObject *v19; // [esp-14h] [ebp-1ACh]
  IPhysicsConstraintGroup *pGroup; // [esp-10h] [ebp-1A8h]
  IPhysicsConstraintGroup *v21; // [esp-10h] [ebp-1A8h]
  matrix3x4_t out; // [esp+0h] [ebp-198h] BYREF
  matrix3x4_t in2; // [esp+30h] [ebp-168h] BYREF
  matrix3x4_t in; // [esp+60h] [ebp-138h] BYREF
  constraint_fixedparams_t fixed; // [esp+90h] [ebp-108h] BYREF
  constraint_ragdollparams_t constraint; // [esp+D8h] [ebp-C0h] BYREF
  IPhysicsObject *pObject; // [esp+18Ch] [ebp-Ch]
  int i; // [esp+190h] [ebp-8h]
  int childIndex; // [esp+194h] [ebp-4h]

  if ( constraintCount > 0 )
  {
    p_childIndex = &pConstraints->childIndex;
    for ( i = constraintCount; i != 0; --i )
    {
      constraint.constraint.forceLimit = 0.0;
      constraint.constraint.torqueLimit = 0.0;
      constraint.constraint.strength = 1.0;
      constraint.constraint.bodyMassScale[0] = 1.0;
      constraint.constraint.bodyMassScale[1] = 1.0;
      constraint.constraint.isActive = true;
      constraint.isActive = true;
      SetIdentityMatrix(matrix: &constraint.constraintToReference);
      SetIdentityMatrix(matrix: &constraint.constraintToAttached);
      constraint.parentIndex = -1;
      constraint.childIndex = -1;
      memset(constraint.axes, 0, 49);
      constraint.useClockwiseRotations = false;
      _V_memcpy(dest: constraint.axes, src: p_childIndex - 49, count: 48);
      jointFrictionScale = params->jointFrictionScale;
      if ( jointFrictionScale > 0.0 )
      {
        constraint.axes[0].torque = jointFrictionScale * constraint.axes[0].torque;
        constraint.axes[1].torque = jointFrictionScale * constraint.axes[1].torque;
        constraint.axes[2].torque = jointFrictionScale * constraint.axes[2].torque;
      }
      v7 = *p_childIndex;
      v8 = *(p_childIndex - 1);
      *(_QWORD *)&constraint.constraintToAttached.m_flMatVal[0][0] = *(_QWORD *)(p_childIndex - 25);
      *(_QWORD *)&constraint.constraintToAttached.m_flMatVal[0][2] = *(_QWORD *)(p_childIndex - 21);
      *(_OWORD *)&constraint.constraintToAttached.m_flMatVal[1][0] = *(_OWORD *)(p_childIndex - 17);
      *(_QWORD *)&constraint.constraintToAttached.m_flMatVal[2][0] = *(_QWORD *)(p_childIndex - 9);
      v9 = *(_QWORD *)(p_childIndex - 5);
      childIndex = v7;
      constraint.childIndex = v7;
      constraint.parentIndex = v8;
      constraint.useClockwiseRotations = true;
      *(_QWORD *)&constraint.constraintToAttached.m_flMatVal[2][2] = v9;
      SetIdentityMatrix(matrix: &constraint.constraintToReference);
      if ( params->fixedConstraints )
      {
        SetIdentityMatrix(matrix: &fixed.attachedRefXform);
        fixed.constraint.forceLimit = 0.0;
        fixed.constraint.torqueLimit = 0.0;
        fixed.constraint.strength = 1.0;
        fixed.constraint.bodyMassScale[0] = 1.0;
        fixed.constraint.bodyMassScale[1] = 1.0;
        fixed.constraint.isActive = true;
        pObject = ragdoll->list[constraint.parentIndex].pObject;
        v10 = ragdoll->list[childIndex].pObject;
        GetPositionMatrix = v10->GetPositionMatrix;
        childIndex = (int)ragdoll + 24 * childIndex;
        GetPositionMatrix(this: v10, a2: &in);
        MatrixInvert(&in, &out);
        pObject->GetPositionMatrix(this: pObject, a2: &in2);
        ConcatTransforms(in1: &out, &in2, out: &fixed.attachedRefXform);
        CreateFixedConstraint = pPhysEnv->CreateFixedConstraint;
        pGroup = ragdoll->pGroup;
        v13 = ragdoll->list[v8].pObject;
        v14 = childIndex;
        v19 = v13;
        v15 = *(IPhysicsObject **)(childIndex + 24);
        fixed.constraint.forceLimit = 0.0;
        fixed.constraint.torqueLimit = 0.0;
        fixed.constraint.strength = 1.0;
        fixed.constraint.bodyMassScale[0] = 1.0;
        fixed.constraint.bodyMassScale[1] = 1.0;
        fixed.constraint.isActive = true;
        *(_DWORD *)(v14 + 28) = CreateFixedConstraint(this: pPhysEnv, a2: v15, a3: v19, a4: pGroup, a5: &fixed);
      }
      else
      {
        CreateRagdollConstraint = pPhysEnv->CreateRagdollConstraint;
        v21 = ragdoll->pGroup;
        v17 = ragdoll->list[v8].pObject;
        childIndex = (int)ragdoll + 24 * childIndex;
        v18 = (int)CreateRagdollConstraint(
                     this: pPhysEnv,
                     a2: *(IPhysicsObject **)(childIndex + 24),
                     a3: v17,
                     a4: v21,
                     a5: &constraint);
        *(_DWORD *)(childIndex + 28) = v18;
      }
      p_childIndex += 50;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F2890
// Name: ParseRagdollIntoCache
// Source: json
//------------------------------------------------------------------------------
cache_ragdoll_t *__cdecl ParseRagdollIntoCache(CStudioHdr *pStudioHdr, vcollide_t *pCollide, int modelIndex)
{
  __int16 v3; // bx
  __int16 v4; // di
  IVPhysicsKeyParser *v5; // esi
  char *v6; // ebx
  const char *v7; // edi
  __int16 v8; // ax
  IPhysicsSurfaceProps *v9; // ecx
  int v10; // eax
  int v11; // ecx
  matrix3x4_t *v12; // edi
  int v13; // eax
  int v14; // ecx
  int v15; // edx
  void (__thiscall *ParseCollisionRules)(IVPhysicsKeyParser *, ragdollcollisionrules_t *, IVPhysicsKeyHandler *); // edx
  int v17; // ebx
  int v18; // edi
  __int16 *v19; // esi
  _BYTE v21[3200]; // [esp+Ch] [ebp-1A24h] BYREF
  _BYTE v22[44]; // [esp+C8Ch] [ebp-DA4h] BYREF
  char v23[1620]; // [esp+CB8h] [ebp-D78h] BYREF
  char pName[1024]; // [esp+130Ch] [ebp-724h] BYREF
  char v25[524]; // [esp+170Ch] [ebp-324h] BYREF
  __int16 v26; // [esp+1918h] [ebp-118h]
  __int64 v27; // [esp+1920h] [ebp-110h]
  __int64 v28; // [esp+1928h] [ebp-108h]
  __int64 v29; // [esp+1930h] [ebp-100h]
  __int64 v30; // [esp+1938h] [ebp-F8h]
  __int64 v31; // [esp+1940h] [ebp-F0h]
  int v32; // [esp+1948h] [ebp-E8h]
  char v33; // [esp+194Ch] [ebp-E4h] BYREF
  int v34; // [esp+19C4h] [ebp-6Ch]
  int v35; // [esp+19C8h] [ebp-68h]
  _BYTE src[52]; // [esp+19CCh] [ebp-64h] BYREF
  int dest; // [esp+1A00h] [ebp-30h] BYREF
  ragdollanimatedfriction_t v38; // [esp+1A04h] [ebp-2Ch] BYREF
  __int16 v39; // [esp+1A18h] [ebp-18h]
  __int16 v40; // [esp+1A1Ah] [ebp-16h]
  int v41; // [esp+1A1Ch] [ebp-14h] BYREF
  int v42; // [esp+1A20h] [ebp-10h]
  void *v43; // [esp+1A24h] [ebp-Ch]
  int v44; // [esp+1A28h] [ebp-8h]
  int v45; // [esp+1A2Ch] [ebp-4h]

  v3 = 0;
  v4 = 0;
  v5 = physcollision->VPhysicsKeyParserCreate(this: physcollision, a2: pCollide);
  v45 = 0;
  v44 = 0;
  _V_memset(&dest, fill: 0, count: 28);
  if ( !v5->Finished(this: v5) )
  {
    v43 = v21;
    v6 = v23;
    do
    {
      v7 = v5->GetCurrentBlockName(this: v5);
      if ( _V_stricmp(s1: v7, s2: "solid") != 0 )
      {
        if ( _V_stricmp(s1: v7, s2: "ragdollconstraint") != 0 )
        {
          if ( _V_stricmp(s1: v7, s2: "collisionrules") != 0 )
          {
            if ( _V_stricmp(s1: v7, s2: "animatedfriction") != 0 )
              v5->SkipBlock(this: v5);
            else
              v5->ParseRagdollAnimatedFriction(this: v5, a2: &v38, a3: nullptr);
          }
          else
          {
            v42 = ((int (__stdcall *)(int, int))physics->FindOrCreateCollisionSet)(
                    a1: modelIndex,
                    a2: *(_WORD *)pCollide & 0x7FFF);
            ParseCollisionRules = v5->ParseCollisionRules;
            v41 = 1;
            ParseCollisionRules(this: v5, a2: (ragdollcollisionrules_t *)&v41, a3: nullptr);
            dest = v42;
          }
        }
        else
        {
          v5->ParseRagdollConstraint(this: v5, a2: (constraint_ragdollparams_t *)&v33, a3: nullptr);
          if ( v35 != v34 && v35 >= 0 && v34 >= 0 )
          {
            v12 = (matrix3x4_t *)v43;
            ++v45;
            v43 = (char *)v43 + 100;
            _V_memcpy(dest: (void *)v12, src, count: 48);
            v13 = v34;
            v14 = v35;
            LOWORD(v12[2].m_flMatVal[0][0]) = v34;
            v15 = *(__int16 *)&v23[52 * v13 + 4];
            HIWORD(v12[2].m_flMatVal[0][0]) = v14;
            Studio_CalcBoneToBoneTransform(
              pStudioHdr,
              inputBoneIndex: *(__int16 *)&v23[52 * v14 + 4],
              outputBoneIndex: v15,
              matrixOut: v12 + 1);
          }
        }
      }
      else
      {
        v5->ParseSolid(this: v5, a2: (solid_t *)pName, a3: &g_SolidSetup);
        v8 = Studio_BoneIndexByName(pStudioHdr, pName);
        *((_WORD *)v6 + 2) = v8;
        if ( v8 < 0 )
        {
          _Msg(a1: "ParseRagdollIntoCache:  Couldn't Lookup Bone %s\n", pName);
        }
        else
        {
          v9 = physprops;
          *((_WORD *)v6 + 3) = v26;
          v10 = v9->GetSurfaceIndex(this: v9, a2: v25);
          *(_DWORD *)v6 = v10;
          if ( v10 < 0 )
            *(_DWORD *)v6 = physprops->GetSurfaceIndex(this: physprops, a2: "default");
          v11 = v32;
          ++v44;
          *(_QWORD *)(v6 - 44) = v27;
          *(_QWORD *)(v6 - 36) = v28;
          *(_QWORD *)(v6 - 28) = v29;
          *(_QWORD *)(v6 - 20) = v30;
          *(_QWORD *)(v6 - 12) = v31;
          *((_DWORD *)v6 - 1) = v11;
          *(v6 - 4) = 0;
          v6 += 52;
        }
      }
    }
    while ( !v5->Finished(this: v5) );
    v4 = v45;
    v3 = v44;
  }
  physcollision->VPhysicsKeyParserDestroy(this: physcollision, a2: v5);
  v39 = v3;
  v40 = v4;
  v17 = 52 * v3;
  v18 = 100 * v4;
  v19 = (__int16 *)physcollision->VCollideAllocUserData(this: physcollision, a2: pCollide, a3: v18 + v17 + 28);
  _V_memcpy(dest: v19, src: &dest, count: 28);
  _V_memcpy(dest: v19 + 14, src: v22, count: v17);
  _V_memcpy(dest: &v19[26 * v19[12] + 14], src: v21, count: v18);
  return (cache_ragdoll_t *)v19;
}

//------------------------------------------------------------------------------
// Address: 0x101F2BA0
// Name: RagdollCreateObjects
// Source: json
//------------------------------------------------------------------------------
void __usercall RagdollCreateObjects(
        ragdoll_t *ragdoll@<eax>,
        IPhysicsEnvironment *pPhysEnv,
        const ragdollparams_t *params)
{
  vcollide_t *pCollide; // eax
  cache_ragdoll_t *pUserData; // esi
  IPhysicsConstraintGroup *(__thiscall *CreateConstraintGroup)(IPhysicsEnvironment *, const constraint_groupparams_t *); // eax
  constraint_groupparams_t group; // [esp+Ch] [ebp-Ch] BYREF

  ragdoll->listCount = 0;
  ragdoll->pGroup = nullptr;
  ragdoll->allowStretch = params->allowStretch;
  memset(dst: (int)ragdoll->list, value: nullptr, count: sizeof(ragdoll->list));
  *(_QWORD *)&ragdoll->animfriction.minFriction = 0;
  *(_QWORD *)&ragdoll->animfriction.timeIn = 0;
  ragdoll->animfriction.timeHold = 0.0;
  pCollide = params->pCollide;
  if ( pCollide != nullptr )
  {
    if ( (*(_WORD *)pCollide & 0x7FFFu) <= 0x20 )
    {
      pUserData = (cache_ragdoll_t *)pCollide->pUserData;
      if ( pUserData == nullptr )
        pUserData = ParseRagdollIntoCache(pStudioHdr: params->pStudioHdr, pCollide, modelIndex: params->modelIndex);
      CreateConstraintGroup = pPhysEnv->CreateConstraintGroup;
      group.additionalIterations = 0;
      group.minErrorTicks = 15;
      group.errorTolerance = 3.0;
      ragdoll->pGroup = CreateConstraintGroup(this: pPhysEnv, a2: &group);
      RagdollAddSolids(
        pPhysEnv,
        ragdoll,
        params,
        pSolids: (cache_ragdollsolid_t *)&pUserData[1],
        solidCount: pUserData->solidCount,
        pConstraints: (const cache_ragdollconstraint_t *)((char *)&pUserData[1] + 52 * pUserData->solidCount),
        constraintCount: pUserData->constraintCount);
      RagdollAddConstraints(
        ragdoll,
        pConstraints: (const cache_ragdollconstraint_t *)((char *)&pUserData[1] + 52 * pUserData->solidCount),
        constraintCount: pUserData->constraintCount,
        pPhysEnv,
        params);
    }
    else
    {
      _Warning(
        a1: "Ragdoll solid count %d exceeds maximum limit of %d - Ragdoll not created",
        *(_WORD *)pCollide & 0x7FFF,
        32);
    }
  }
  else
  {
    _Warning(a1: "Ragdoll has no pCollide!");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F2CC0
// Name: bool RagdollCreate(struct ragdoll_t __near &,struct ragdollparams_t const __near &,class IPhysicsEnvironment __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl RagdollCreate(ragdoll_t *ragdoll, const ragdollparams_t *params, IPhysicsEnvironment *pPhysEnv)
{
  const ragdollparams_t *v3; // ebx
  int listCount; // eax
  int forceBoneIndex; // ecx
  int v8; // edi
  IPhysicsObject **p_pObject; // ebx
  double v10; // st7
  float z; // edx
  float v12; // eax
  IPhysicsObject **v13; // edi
  int v14; // edi
  IPhysicsObject **v15; // ebx
  double v16; // st7
  IPhysicsObject *v17; // ecx
  float v18[3]; // [esp+8h] [ebp-28h] BYREF
  Vector nudgeForce; // [esp+14h] [ebp-1Ch] BYREF
  Vector forcePosition; // [esp+20h] [ebp-10h] BYREF
  int forceBone; // [esp+2Ch] [ebp-4h]
  float totalMass; // [esp+38h] [ebp+8h]

  v3 = params;
  RagdollCreateObjects(ragdoll, pPhysEnv, params);
  listCount = ragdoll->listCount;
  if ( ragdoll->listCount == 0 )
    return 0;
  forceBoneIndex = params->forceBoneIndex;
  v8 = 0;
  forceBone = forceBoneIndex;
  totalMass = 0.0;
  if ( listCount <= 0 )
    goto LABEL_7;
  p_pObject = &ragdoll->list[0].pObject;
  do
  {
    v10 = ((double (__thiscall *)(IPhysicsObject *))(*p_pObject)->GetMass)(a1: *p_pObject);
    ++v8;
    p_pObject += 6;
    totalMass = v10 + totalMass;
  }
  while ( v8 < ragdoll->listCount );
  forceBoneIndex = forceBone;
  v3 = params;
  if ( totalMass <= 1.0 )
LABEL_7:
    totalMass = 1.0;
  z = v3->forceVector.z;
  v12 = v3->forcePosition.z;
  *(_QWORD *)&nudgeForce.x = *(_QWORD *)&v3->forceVector.x;
  nudgeForce.z = z;
  *(_QWORD *)&forcePosition.x = *(_QWORD *)&v3->forcePosition.x;
  forcePosition.z = v12;
  if ( forceBoneIndex >= 0 && forceBoneIndex < ragdoll->listCount )
  {
    v13 = &ragdoll->list[forceBoneIndex].pObject;
    (*v13)->ApplyForceCenter(this: *v13, a2: &nudgeForce);
    (*v13)->GetPosition(this: *v13, a2: &forcePosition, a3: nullptr);
    forceBoneIndex = forceBone;
  }
  if ( vec3_origin.x != forcePosition.x || vec3_origin.y != forcePosition.y || vec3_origin.z != forcePosition.z )
  {
    v14 = 0;
    if ( ragdoll->listCount > 0 )
    {
      v15 = &ragdoll->list[0].pObject;
      do
      {
        if ( forceBoneIndex != v14 )
        {
          v16 = ((double (__thiscall *)(IPhysicsObject *))(*v15)->GetMass)(a1: *v15) / totalMass;
          v17 = *v15;
          v18[0] = nudgeForce.x * v16;
          v18[1] = nudgeForce.y * v16;
          v18[2] = v16 * nudgeForce.z;
          v17->ApplyForceOffset(this: v17, a2: (const Vector *)v18, a3: &forcePosition);
          forceBoneIndex = forceBone;
        }
        ++v14;
        v15 += 6;
      }
      while ( v14 < ragdoll->listCount );
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101F2E20
// Name: void RagdollSolveSeparation(struct ragdoll_t __near &,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __usercall RagdollSolveSeparation(float a1@<ebp>, ragdoll_t *ragdoll, CBaseEntity *pEntity)
{
  int v3; // eax
  int *p_parentIndex; // esi
  bool v5; // zf
  IPhysicsObject *pObject; // ecx
  double v7; // st7
  IPhysicsObject *v8; // ecx
  double v9; // st6
  float x; // eax
  IPhysicsObject **p_pObject; // esi
  IPhysicsObject *v12; // ecx
  IPhysicsObject *v13; // ecx
  unsigned __int8 needsFix[256]; // [esp+0h] [ebp-1D8h] BYREF
  CGameTrace tr; // [esp+100h] [ebp-D8h] BYREF
  matrix3x4_t xform; // [esp+158h] [ebp-80h] BYREF
  int v17; // [esp+18Ch] [ebp-4Ch]
  Vector v18; // [esp+19Ch] [ebp-3Ch] BYREF
  Vector start; // [esp+1A8h] [ebp-30h] BYREF
  float v20; // [esp+1B4h] [ebp-24h]
  Vector target; // [esp+1B8h] [ebp-20h] BYREF
  Vector velocity; // [esp+1C4h] [ebp-14h] BYREF
  int i; // [esp+1D0h] [ebp-8h]
  int retaddr; // [esp+1D8h] [ebp+0h]

  velocity.z = a1;
  i = retaddr;
  v3 = 0;
  velocity.y = 0.0;
  velocity.x = 0.0;
  if ( ragdoll->listCount <= 0 )
    goto LABEL_24;
  p_parentIndex = &ragdoll->list[0].parentIndex;
  do
  {
    v5 = *(p_parentIndex - 1) == 0;
    *((_BYTE *)&velocity.z + v3 - 472) = 0;
    if ( !v5 && *p_parentIndex >= 0 )
    {
      (*(void (__thiscall **)(_DWORD, Vector *, _DWORD))(*(_DWORD *)*(p_parentIndex - 2) + 192))(
        a1: *(p_parentIndex - 2),
        a2: &v18,
        a3: 0);
      pObject = ragdoll->list[*p_parentIndex].pObject;
      pObject->LocalToWorld(this: pObject, a2: &target, a3: (const Vector *)(p_parentIndex - 5));
      if ( *((_BYTE *)&velocity.z + *p_parentIndex - 472) != 0 )
      {
        ++LODWORD(velocity.y);
        *((_BYTE *)&velocity.z + LODWORD(velocity.x) - 472) = 1;
        goto LABEL_16;
      }
      start.y = target.x - v18.x;
      start.z = target.y - v18.y;
      v20 = target.z - v18.z;
      if ( (float)((float)((float)(start.y * start.y) + (float)(start.z * start.z)) + (float)(v20 * v20)) > 1.0 )
      {
        v7 = ((double (__thiscall *)(_DWORD))*(_DWORD *)(*(_DWORD *)*(p_parentIndex - 2) + 116))(a1: *(p_parentIndex - 2));
        v8 = ragdoll->list[*p_parentIndex].pObject;
        start.x = v7 + v7;
        v9 = ((double (__thiscall *)(IPhysicsObject *))v8->GetMass)(a1: v8);
        if ( v9 > start.x )
        {
          *((_BYTE *)&velocity.z + LODWORD(velocity.x) - 472) = 1;
LABEL_15:
          ++LODWORD(velocity.y);
          goto LABEL_16;
        }
        if ( PhysHasContactWithOtherInDirection(
               pPhysics: (IPhysicsObject *)*(p_parentIndex - 2),
               dir: (Vector *)&start.y) )
        {
          v17 = 0;
          Ray_t::Init(this: (Ray_t *)&tr.m_pEnt, start: &target, end: &v18);
          UTIL_TraceRay(
            ray: (const Ray_t *)&tr.m_pEnt,
            mask: 0x200400Bu,
            ignore: pEntity,
            collisionGroup: 0,
            ptr: (CGameTrace *)&needsFix[244]);
          if ( tr.plane.normal.z < 1.0 || tr.plane.pad[0] != 0 || tr.plane.pad[1] != 0 )
          {
            *((_BYTE *)&velocity.z + LODWORD(velocity.x) - 472) = 1;
            goto LABEL_15;
          }
        }
      }
    }
LABEL_16:
    v3 = LODWORD(velocity.x) + 1;
    p_parentIndex += 6;
    LODWORD(velocity.x) = v3;
  }
  while ( v3 < ragdoll->listCount );
  if ( LODWORD(velocity.y) == 0 )
  {
LABEL_24:
    ragdoll->pGroup->ClearErrorState(this: ragdoll->pGroup);
    return;
  }
  x = 0.0;
  velocity.x = 0.0;
  if ( ragdoll->listCount > 0 )
  {
    p_pObject = &ragdoll->list[0].pObject;
    do
    {
      if ( *((_BYTE *)&velocity.z + LODWORD(x) - 472) != 0 )
      {
        v12 = ragdoll->list[(_DWORD)p_pObject[2]].pObject;
        v12->LocalToWorld(this: v12, a2: (Vector *)&start.y, a3: (const Vector *)p_pObject - 1);
        v13 = ragdoll->list[(_DWORD)p_pObject[2]].pObject;
        v13->GetVelocityAtPoint(this: v13, a2: (Vector *)&start.y, a3: &target);
        (*p_pObject)->GetPositionMatrix(this: *p_pObject, a2: (matrix3x4_t *)&xform.m_flMatVal[1][1]);
        MatrixSetColumn(in: (Vector *)&start.y, column: 3, out: (matrix3x4_t *)&xform.m_flMatVal[1][1]);
        (*p_pObject)->SetPositionMatrix(this: *p_pObject, a2: (matrix3x4_t *)&xform.m_flMatVal[1][1], a3: true);
        (*p_pObject)->SetVelocity(this: *p_pObject, a2: &target, a3: &vec3_origin);
        x = velocity.x;
      }
      ++LODWORD(x);
      p_pObject += 6;
      velocity.x = x;
    }
    while ( SLODWORD(x) < ragdoll->listCount );
  }
  _DevMsg(a1: 2, a2: "TICK:%5d:Ragdoll separation count: %d\n", gpGlobals->tickcount, velocity.y);
}

//------------------------------------------------------------------------------
// Address: 0x101F30D0
// Name: bool ShouldRemoveThisRagdoll(class CBaseAnimating __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ShouldRemoveThisRagdoll(CBaseAnimating *pRagdoll)
{
  CBasePlayer *LocalPlayer; // edi
  int m_iEFlags; // ecx
  int v4; // ecx
  Vector target; // [esp+10h] [ebp-Ch] BYREF
  int savedregs; // [esp+1Ch] [ebp+0h] BYREF

  if ( g_RagdollLVManager.m_bLowViolence )
    return 1;
  LocalPlayer = UTIL_GetLocalPlayer();
  if ( UTIL_FindClientInPVS(pEdict: pRagdoll->m_Network.m_pPev) == nullptr )
  {
    if ( g_debug_ragdoll_removal.m_pParent != nullptr && g_debug_ragdoll_removal.m_pParent->m_Value.m_nValue != 0 )
    {
      if ( (pRagdoll->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: pRagdoll, a2: (int)&savedregs);
      m_iEFlags = pRagdoll->m_iEFlags;
      target.x = pRagdoll->m_vecAbsOrigin.x;
      target.y = pRagdoll->m_vecAbsOrigin.y;
      target.z = pRagdoll->m_vecAbsOrigin.z + 64.0;
      if ( (m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: pRagdoll, a2: (int)&savedregs);
      NDebugOverlay::Line(origin: &pRagdoll->m_vecAbsOrigin, &target, r: 0, g: 255, b: 0, noDepthTest: 1, duration: 5.0);
    }
    return 1;
  }
  if ( !LocalPlayer->FInViewCone(this: LocalPlayer, a2: pRagdoll) )
  {
    if ( g_debug_ragdoll_removal.m_pParent != nullptr && g_debug_ragdoll_removal.m_pParent->m_Value.m_nValue != 0 )
    {
      if ( (pRagdoll->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: pRagdoll, a2: (int)&savedregs);
      v4 = pRagdoll->m_iEFlags;
      target.x = pRagdoll->m_vecAbsOrigin.x;
      target.y = pRagdoll->m_vecAbsOrigin.y;
      target.z = pRagdoll->m_vecAbsOrigin.z + 64.0;
      if ( (v4 & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: pRagdoll, a2: (int)&savedregs);
      NDebugOverlay::Line(origin: &pRagdoll->m_vecAbsOrigin, &target, r: 0, g: 0, b: 255, noDepthTest: 1, duration: 5.0);
    }
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101F3420
// Name: public: virtual void CRagdollLRURetirement::LevelInitPreEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRagdollLRURetirement::LevelInitPreEntity(CRagdollLRURetirement *this)
{
  this->m_iMaxRagdolls = -1;
  CUtlLinkedList<CRagdollEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRagdollEntry,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<CEnvWindShared::WindVariationEvent_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared::WindVariationEvent_t,unsigned short>,unsigned short> > *)&this->m_LRUImportantRagdolls);
  CUtlLinkedList<CRagdollEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRagdollEntry,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<CEnvWindShared::WindVariationEvent_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared::WindVariationEvent_t,unsigned short>,unsigned short> > *)&this->m_LRU);
}

//------------------------------------------------------------------------------
// Address: 0x101F3440
// Name: public: void CBaseAnimating::TransferDissolveFrom(class CBaseAnimating __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBaseAnimating::TransferDissolveFrom(CBaseAnimating *this@<ecx>, int a2@<ebx>, CBaseAnimating *pAnim)
{
  CEntityDissolve *v4; // ebx
  CBaseEntity *EffectEntity; // eax
  char *v6; // eax
  char *v7; // esi
  CBaseEdict *v8; // ecx
  CBaseEdict *v9; // ecx
  CBaseEdict *v10; // ecx
  CBaseEdict *v11; // ecx

  if ( pAnim != nullptr && (pAnim->m_fFlags.m_Value & 0x20000000) != 0 )
  {
    v4 = CEntityDissolve::Create(a1: a2, pTarget: (CBasePlayer *)this, pSource: pAnim);
    if ( v4 != nullptr )
    {
      CBaseEntity::AddFlag(this, flags: 0x20000000);
      this->m_flDissolveStartTime = pAnim->m_flDissolveStartTime;
      EffectEntity = CBaseEntity::GetEffectEntity(this: pAnim);
      v6 = (char *)__RTDynamicCast(
                     inptr: EffectEntity,
                     VfDelta: 0,
                     SrcType: &CBaseEntity `RTTI Type Descriptor',
                     TargetType: &CEntityDissolve `RTTI Type Descriptor',
                     isReference: 0);
      v7 = v6;
      if ( v6 != nullptr )
      {
        CEntityDissolve::SetDissolverOrigin(this: v4, vOrigin: *(Vector *)(v6 + 884));
        CBeam::SetBeamFlags(this: (CBeam *)v4, flags: *((_DWORD *)v7 + 220));
        if ( *((_DWORD *)v7 + 220) == 3 )
        {
          CEntityDissolve::SetMagnitude(this: v4, iMagnitude: *((_DWORD *)v7 + 224));
          if ( v4->m_flFadeOutStart.m_Value != 0.2 )
          {
            if ( v4->m_Network.m_TimerEvent.m_bRegistered )
            {
              *((_BYTE *)&v4->m_Network + 76) |= 1u;
            }
            else
            {
              v8 = &v4->m_Network.m_pPev->CBaseEdict;
              if ( v8 != nullptr )
                CBaseEdict::StateChanged(this: v8, offset: 0x368u);
            }
            v4->m_flFadeOutStart.m_Value = 0.2;
          }
          if ( v4->m_flFadeOutModelStart.m_Value != 0.1 )
          {
            if ( v4->m_Network.m_TimerEvent.m_bRegistered )
            {
              *((_BYTE *)&v4->m_Network + 76) |= 1u;
            }
            else
            {
              v9 = &v4->m_Network.m_pPev->CBaseEdict;
              if ( v9 != nullptr )
                CBaseEdict::StateChanged(this: v9, offset: 0x360u);
            }
            v4->m_flFadeOutModelStart.m_Value = 0.1;
          }
          if ( v4->m_flFadeOutModelLength.m_Value != 0.050000001 )
          {
            if ( v4->m_Network.m_TimerEvent.m_bRegistered )
            {
              *((_BYTE *)&v4->m_Network + 76) |= 1u;
            }
            else
            {
              v10 = &v4->m_Network.m_pPev->CBaseEdict;
              if ( v10 != nullptr )
                CBaseEdict::StateChanged(this: v10, offset: 0x364u);
            }
            v4->m_flFadeOutModelLength.m_Value = 0.050000001;
          }
          if ( v4->m_flFadeInLength.m_Value != 0.1 )
          {
            if ( v4->m_Network.m_TimerEvent.m_bRegistered )
            {
              *((_BYTE *)&v4->m_Network + 76) |= 1u;
            }
            else
            {
              v11 = &v4->m_Network.m_pPev->CBaseEdict;
              if ( v11 != nullptr )
                CBaseEdict::StateChanged(this: v11, offset: 0x35Cu);
            }
            v4->m_flFadeInLength.m_Value = 0.1;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F3630
// Name: public: CRagdollLRURetirement::CRagdollLRURetirement(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CRagdollLRURetirement *__thiscall CRagdollLRURetirement::CRagdollLRURetirement(
        CRagdollLRURetirement *this,
        const char *name)
{
  UtlLinkedListElem_t<CRagdollEntry,unsigned short> *m_pMemory; // edx

  CAutoGameSystemPerFrame::CAutoGameSystemPerFrame(this, name);
  this->__vftable = (CRagdollLRURetirement_vtbl *)&CRagdollLRURetirement::`vftable';
  this->m_LRU.m_Memory.m_pMemory = nullptr;
  this->m_LRU.m_Memory.m_nAllocationCount = 0;
  this->m_LRU.m_Memory.m_nGrowSize = 0;
  this->m_LRU.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_LRU.m_FirstFree = 0xFFFF;
  this->m_LRU.m_pElements = this->m_LRU.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_LRU.m_Head = -1;
  this->m_LRU.m_NumAlloced = 0;
  this->m_LRUImportantRagdolls.m_Memory.m_pMemory = nullptr;
  this->m_LRUImportantRagdolls.m_Memory.m_nAllocationCount = 0;
  this->m_LRUImportantRagdolls.m_Memory.m_nGrowSize = 0;
  this->m_LRUImportantRagdolls.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_LRUImportantRagdolls.m_FirstFree = 0xFFFF;
  m_pMemory = this->m_LRUImportantRagdolls.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_LRUImportantRagdolls.m_Head = -1;
  this->m_LRUImportantRagdolls.m_NumAlloced = 0;
  this->m_LRUImportantRagdolls.m_pElements = m_pMemory;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101F36A0
// Name: public: virtual CRagdollLRURetirement::~CRagdollLRURetirement(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRagdollLRURetirement::~CRagdollLRURetirement(CRagdollLRURetirement *this)
{
  CUtlLinkedList<CRagdollEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRagdollEntry,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<CEnvWindShared::WindVariationEvent_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared::WindVariationEvent_t,unsigned short>,unsigned short> > *)&this->m_LRUImportantRagdolls);
  if ( this->m_LRUImportantRagdolls.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_LRUImportantRagdolls.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_LRUImportantRagdolls.m_Memory.m_pMemory);
      this->m_LRUImportantRagdolls.m_Memory.m_pMemory = nullptr;
    }
    this->m_LRUImportantRagdolls.m_Memory.m_nAllocationCount = 0;
  }
  CUtlLinkedList<CRagdollEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRagdollEntry,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<CEnvWindShared::WindVariationEvent_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CEnvWindShared::WindVariationEvent_t,unsigned short>,unsigned short> > *)&this->m_LRU);
  if ( this->m_LRU.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_LRU.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_LRU.m_Memory.m_pMemory);
      this->m_LRU.m_Memory.m_pMemory = nullptr;
    }
    this->m_LRU.m_Memory.m_nAllocationCount = 0;
  }
  IGameSystemPerFrame::~IGameSystemPerFrame(this);
}

//------------------------------------------------------------------------------
// Address: 0x101F3750
// Name: public: virtual void CRagdollLRURetirement::Update(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRagdollLRURetirement::Update(CRagdollLRURetirement *this, float frametime)
{
  unsigned int m_Head; // ebx
  int v4; // esi
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // edx
  unsigned int v7; // eax
  float m_flForcedRetireTime; // xmm0_4
  unsigned __int16 v9; // bx
  UtlLinkedListElem_t<CRagdollEntry,unsigned short> *m_pMemory; // ecx
  unsigned int v11; // esi
  unsigned int v12; // eax
  CBaseAnimating *v13; // ecx
  IPhysicsObject *m_pPhysicsObject; // eax
  bool v15; // al
  unsigned __int16 v16; // bx
  UtlLinkedListElem_t<CRagdollEntry,unsigned short> *v17; // ecx
  unsigned int v18; // esi
  unsigned int v19; // eax
  CBaseEntity *v20; // edx
  unsigned int v21; // eax
  UtlLinkedListElem_t<CRagdollEntry,unsigned short> *v22; // [esp+14h] [ebp-14h]
  CBaseEntity *v23; // [esp+18h] [ebp-10h]
  int next; // [esp+20h] [ebp-8h]
  int nexta; // [esp+20h] [ebp-8h]
  int nextb; // [esp+20h] [ebp-8h]
  int iMaxRagdollCount; // [esp+24h] [ebp-4h]

  iMaxRagdollCount = this->m_iMaxRagdolls;
  if ( iMaxRagdollCount == -1 )
  {
    if ( g_ragdoll_maxcount.m_pParent != nullptr )
      iMaxRagdollCount = g_ragdoll_maxcount.m_pParent->m_Value.m_nValue;
    else
      iMaxRagdollCount = 0;
  }
  if ( g_RagdollLVManager.m_bLowViolence )
    iMaxRagdollCount = 0;
  m_Head = this->m_LRU.m_Head;
  this->m_iRagdollCount = 0;
  this->m_iSimulatedRagdollCount = 0;
  if ( m_Head < 0xFFFF )
  {
    while ( 1 )
    {
      v4 = (unsigned __int16)m_Head;
      v22 = &this->m_LRU.m_Memory.m_pMemory[v4];
      m_Index = v22->m_Element.m_hRagdoll.m_Index;
      next = v22->m_Next;
      if ( v22->m_Element.m_hRagdoll.m_Index == -1
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      {
        break;
      }
      m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      if ( m_pEntity == nullptr )
        goto LABEL_15;
      v7 = m_pEntity->m_hEffectEntity.m_Value.m_Index;
      if ( v7 == -1
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_SerialNumber != HIWORD(v7)
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_pEntity == nullptr )
      {
        goto LABEL_15;
      }
LABEL_18:
      LOWORD(m_Head) = next;
      if ( next >= 0xFFFF )
        goto LABEL_19;
    }
    m_pEntity = nullptr;
LABEL_15:
    m_flForcedRetireTime = v22->m_Element.m_flForcedRetireTime;
    if ( m_flForcedRetireTime != 0.0 && m_flForcedRetireTime <= gpGlobals->curtime )
    {
      CBaseEntity::SUB_StartFadeOut(this: m_pEntity, delay: 0.0, notSolid: true);
      CUtlLinkedList<CRagdollEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRagdollEntry,unsigned short>,unsigned short>>::Unlink(
        this: (CUtlLinkedList<CMapEntityRef,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMapEntityRef,unsigned short>,unsigned short> > *)&this->m_LRU,
        elem: m_Head);
      this->m_LRU.m_Memory.m_pMemory[v4].m_Next = this->m_LRU.m_FirstFree;
      this->m_LRU.m_FirstFree = m_Head;
    }
    goto LABEL_18;
  }
LABEL_19:
  v9 = this->m_LRU.m_Head;
  if ( v9 != 0xFFFF )
  {
    do
    {
      m_pMemory = this->m_LRU.m_Memory.m_pMemory;
      v11 = v9;
      v12 = m_pMemory[v11].m_Element.m_hRagdoll.m_Index;
      nexta = m_pMemory[v11].m_Next;
      if ( v12 != -1
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)v12].m_SerialNumber == HIWORD(v12)
        && (v13 = (CBaseAnimating *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v12].m_pEntity,
            v23 = v13,
            v13 != nullptr) )
      {
        ++this->m_iRagdollCount;
        m_pPhysicsObject = v13->m_pPhysicsObject;
        if ( m_pPhysicsObject != nullptr )
        {
          v15 = m_pPhysicsObject->IsAsleep(this: v13->m_pPhysicsObject);
          v13 = (CBaseAnimating *)v23;
          if ( !v15 )
            ++this->m_iSimulatedRagdollCount;
        }
        if ( this->m_LRU.m_ElementCount > iMaxRagdollCount && ShouldRemoveThisRagdoll(pRagdoll: v13) == 1 )
        {
          CBaseEntity::SUB_StartFadeOut(this: v23, delay: 0.0, notSolid: true);
          CUtlLinkedList<CRagdollEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRagdollEntry,unsigned short>,unsigned short>>::Unlink(
            this: (CUtlLinkedList<CMapEntityRef,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMapEntityRef,unsigned short>,unsigned short> > *)&this->m_LRU,
            elem: v9);
          this->m_LRU.m_Memory.m_pMemory[v9].m_Next = this->m_LRU.m_FirstFree;
          this->m_LRU.m_FirstFree = v9;
          return;
        }
      }
      else
      {
        CUtlLinkedList<CRagdollEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRagdollEntry,unsigned short>,unsigned short>>::Unlink(
          this: (CUtlLinkedList<CMapEntityRef,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMapEntityRef,unsigned short>,unsigned short> > *)&this->m_LRU,
          elem: v9);
        this->m_LRU.m_Memory.m_pMemory[v11].m_Next = this->m_LRU.m_FirstFree;
        this->m_LRU.m_FirstFree = v9;
      }
      v9 = nexta;
    }
    while ( nexta < 0xFFFF );
  }
  v16 = this->m_LRU.m_Head;
  if ( v16 != 0xFFFF )
  {
    do
    {
      if ( this->m_LRU.m_ElementCount <= iMaxRagdollCount )
        return;
      v17 = this->m_LRU.m_Memory.m_pMemory;
      v18 = v16;
      v19 = v17[v18].m_Element.m_hRagdoll.m_Index;
      nextb = v17[v18].m_Next;
      if ( v19 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v19].m_SerialNumber != HIWORD(v19) )
      {
        v20 = nullptr;
      }
      else
      {
        v20 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v19].m_pEntity;
        if ( v20 != nullptr )
        {
          v21 = v20->m_hEffectEntity.m_Value.m_Index;
          if ( v21 != -1
            && g_pEntityList->m_EntPtrArray[(unsigned __int16)v21].m_SerialNumber == HIWORD(v21)
            && g_pEntityList->m_EntPtrArray[(unsigned __int16)v21].m_pEntity != nullptr )
          {
            goto LABEL_41;
          }
        }
      }
      CBaseEntity::SUB_StartFadeOut(this: v20, delay: 0.0, notSolid: true);
      CUtlLinkedList<CRagdollEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRagdollEntry,unsigned short>,unsigned short>>::Unlink(
        this: (CUtlLinkedList<CMapEntityRef,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMapEntityRef,unsigned short>,unsigned short> > *)&this->m_LRU,
        elem: v16);
      this->m_LRU.m_Memory.m_pMemory[v18].m_Next = this->m_LRU.m_FirstFree;
      this->m_LRU.m_FirstFree = v16;
LABEL_41:
      v16 = nextb;
    }
    while ( nextb < 0xFFFF );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F3A60
// Name: public: void CRagdollLRURetirement::MoveToTopOfLRU(class CBaseAnimating __near *,bool,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRagdollLRURetirement::MoveToTopOfLRU(
        CRagdollLRURetirement *this,
        CBaseAnimating *pRagdoll,
        bool bImportant,
        float flForcedRetireTime)
{
  CUtlLinkedList<CMapEntityRef,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMapEntityRef,unsigned short>,unsigned short> > *p_m_LRUImportantRagdolls; // esi
  unsigned __int16 v6; // ax
  int v7; // edi
  int v8; // eax
  int m_nValue; // eax
  int m_Head; // ebx
  unsigned int m_iEdict; // eax
  CBaseEntity *m_pEntity; // ecx
  unsigned __int16 m_Next; // si
  CUtlLinkedList<CMapEntityRef,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMapEntityRef,unsigned short>,unsigned short> > *p_m_LRU; // edi
  UtlLinkedListElem_t<CRagdollEntry,unsigned short> *m_pMemory; // ebx
  unsigned int v16; // eax
  CBaseAnimating *v17; // ecx
  unsigned int v18; // ebx
  unsigned __int16 v19; // ax
  int v20; // edi
  UtlLinkedListElem_t<CRagdollEntry,unsigned short> *v21; // eax
  unsigned int m_Index; // [esp+14h] [ebp-8h]
  CUtlLinkedList<CRagdollEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRagdollEntry,unsigned short>,unsigned short> > *bImportanta; // [esp+28h] [ebp+Ch]

  if ( bImportant )
  {
    if ( pRagdoll != nullptr )
      m_Index = pRagdoll->GetRefEHandle(this: pRagdoll)->m_Index;
    else
      m_Index = -1;
    p_m_LRUImportantRagdolls = (CUtlLinkedList<CMapEntityRef,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMapEntityRef,unsigned short>,unsigned short> > *)&this->m_LRUImportantRagdolls;
    v6 = CUtlLinkedList<CRagdollEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRagdollEntry,unsigned short>,unsigned short>>::AllocInternal(
           this: &this->m_LRUImportantRagdolls,
           multilist: false);
    v7 = v6;
    if ( v6 != 0xFFFF )
    {
      CUtlLinkedList<CMapEntityRef,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMapEntityRef,unsigned short>,unsigned short>>::LinkBefore(
        this: (CUtlLinkedList<CMapEntityRef,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMapEntityRef,unsigned short>,unsigned short> > *)&this->m_LRUImportantRagdolls,
        before: 0xFFFFu,
        elem: v6);
      v8 = (int)&p_m_LRUImportantRagdolls->m_Memory.m_pMemory[v7];
      if ( v8 != 0 )
      {
        *(_DWORD *)v8 = m_Index;
        *(float *)(v8 + 4) = flForcedRetireTime;
      }
    }
    if ( g_ragdoll_important_maxcount.m_pParent != nullptr )
      m_nValue = g_ragdoll_important_maxcount.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    if ( this->m_LRUImportantRagdolls.m_ElementCount > m_nValue )
    {
      m_Head = this->m_LRUImportantRagdolls.m_Head;
      m_iEdict = p_m_LRUImportantRagdolls->m_Memory.m_pMemory[m_Head].m_Element.m_iEdict;
      if ( m_iEdict != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_iEdict].m_SerialNumber == HIWORD(m_iEdict) )
      {
        m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_iEdict].m_pEntity;
        if ( m_pEntity != nullptr )
        {
          CBaseEntity::SUB_StartFadeOut(this: m_pEntity, delay: 0.0, notSolid: true);
          CUtlLinkedList<CRagdollEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRagdollEntry,unsigned short>,unsigned short>>::Unlink(
            this: p_m_LRUImportantRagdolls,
            elem: m_Head);
          p_m_LRUImportantRagdolls->m_Memory.m_pMemory[m_Head].m_Next = p_m_LRUImportantRagdolls->m_FirstFree;
          p_m_LRUImportantRagdolls->m_FirstFree = m_Head;
        }
      }
    }
  }
  else
  {
    m_Next = this->m_LRU.m_Head;
    if ( m_Next != 0xFFFF )
    {
      p_m_LRU = (CUtlLinkedList<CMapEntityRef,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMapEntityRef,unsigned short>,unsigned short> > *)&this->m_LRU;
      m_pMemory = this->m_LRU.m_Memory.m_pMemory;
      bImportanta = &this->m_LRU;
      while ( 1 )
      {
        v16 = m_pMemory[m_Next].m_Element.m_hRagdoll.m_Index;
        if ( v16 == -1
          || (p_m_LRU = (CUtlLinkedList<CMapEntityRef,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMapEntityRef,unsigned short>,unsigned short> > *)bImportanta,
              g_pEntityList->m_EntPtrArray[(unsigned __int16)v16].m_SerialNumber != HIWORD(v16)) )
        {
          v17 = nullptr;
        }
        else
        {
          v17 = (CBaseAnimating *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v16].m_pEntity;
        }
        if ( v17 == pRagdoll )
          break;
        m_Next = m_pMemory[m_Next].m_Next;
        if ( m_Next == 0xFFFF )
          goto LABEL_26;
      }
      CUtlLinkedList<CRagdollEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRagdollEntry,unsigned short>,unsigned short>>::Unlink(
        this: p_m_LRU,
        elem: m_Next);
      p_m_LRU->m_Memory.m_pMemory[m_Next].m_Next = p_m_LRU->m_FirstFree;
      p_m_LRU->m_FirstFree = m_Next;
    }
LABEL_26:
    if ( pRagdoll != nullptr )
      v18 = pRagdoll->GetRefEHandle(this: pRagdoll)->m_Index;
    else
      v18 = -1;
    v19 = CUtlLinkedList<CRagdollEntry,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CRagdollEntry,unsigned short>,unsigned short>>::AllocInternal(
            this: &this->m_LRU,
            multilist: false);
    v20 = v19;
    if ( v19 != 0xFFFF )
    {
      CUtlLinkedList<CMapEntityRef,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMapEntityRef,unsigned short>,unsigned short>>::LinkBefore(
        this: (CUtlLinkedList<CMapEntityRef,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMapEntityRef,unsigned short>,unsigned short> > *)&this->m_LRU,
        before: 0xFFFFu,
        elem: v19);
      v21 = &this->m_LRU.m_Memory.m_pMemory[v20];
      if ( v21 != nullptr )
      {
        v21->m_Element.m_hRagdoll.m_Index = v18;
        v21->m_Element.m_flForcedRetireTime = flForcedRetireTime;
      }
    }
  }
}

} // namespace server
