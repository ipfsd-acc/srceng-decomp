// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/studiomdl/collisionmodel.cpp
// Functions: 53
// ============================================================

#include "utils\studiomdl\collisionmodel.h"

//------------------------------------------------------------------------------
// Address: 0x00401C50
// Name: public: Vector::Vector(void)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall Vector::Vector(Vector *this)
{
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00401C60
// Name: char __near * MemAlloc_StrDup(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl MemAlloc_StrDup(const char *pString)
{
  char *result; // eax

  if ( pString == nullptr )
    return nullptr;
  result = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pString) + 1);
  if ( result == nullptr )
    return nullptr;
  strcpy(result, pString);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00401CB0
// Name: public: int CJointedModel::BoneIndex(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CJointedModel::BoneIndex(CJointedModel *this, const char *pName)
{
  s_source_t *m_pModel; // eax
  int v4; // esi
  int i; // edi
  const char *pNamea; // [esp+14h] [ebp+8h]

  pNamea = RenameBone(pName);
  m_pModel = this->m_pModel;
  v4 = 0;
  if ( this->m_pModel->numbones <= 0 )
    return -1;
  for ( i = 0; _V_stricmp(s1: m_pModel->localBone[i].name, s2: pNamea) != 0; ++i )
  {
    m_pModel = this->m_pModel;
    if ( ++v4 >= this->m_pModel->numbones )
      return -1;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00401D20
// Name: public: int CJointedModel::CollisionIndex(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CJointedModel::CollisionIndex(CJointedModel *this, const char *pName)
{
  CPhysCollisionModel *m_pCollisionList; // esi
  int v4; // edi

  if ( pName == nullptr )
    return -1;
  m_pCollisionList = this->m_pCollisionList;
  v4 = 0;
  if ( m_pCollisionList == nullptr )
    return -1;
  while ( _V_stricmp(s1: pName, s2: m_pCollisionList->m_name) != 0 )
  {
    m_pCollisionList = m_pCollisionList->m_pNext;
    ++v4;
    if ( m_pCollisionList == nullptr )
      return -1;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00401D70
// Name: public: void CJointedModel::SortCollisionList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CJointedModel::SortCollisionList(CJointedModel *this)
{
  CJointedModel *v1; // esi
  int m_collisionCount; // eax
  CPhysCollisionModel **v3; // edi
  CPhysCollisionModel *m_pCollisionList; // eax
  CPhysCollisionModel **v5; // ecx
  int v6; // ebx
  const char **p_m_parent; // eax
  int i; // esi
  int j; // eax
  CPhysCollisionModel *pPhys; // [esp+4h] [ebp-Ch]
  bool swapped; // [esp+Fh] [ebp-1h]

  v1 = this;
  m_collisionCount = this->m_collisionCount;
  if ( m_collisionCount != 0 )
  {
    v3 = (CPhysCollisionModel **)MemAlloc_Alloc(
                                   nSize: (unsigned __int64)(unsigned int)m_collisionCount >> 30 != 0
                                 ? -1
                                 : 4 * m_collisionCount);
    m_pCollisionList = v1->m_pCollisionList;
    if ( m_pCollisionList != nullptr )
    {
      v5 = v3;
      do
      {
        *v5 = m_pCollisionList;
        m_pCollisionList = m_pCollisionList->m_pNext;
        ++v5;
      }
      while ( m_pCollisionList != nullptr );
    }
    do
    {
      v6 = 0;
      swapped = false;
      if ( v1->m_collisionCount <= 0 )
        break;
      do
      {
        p_m_parent = &v3[v6]->m_parent;
        pPhys = (CPhysCollisionModel *)p_m_parent;
        if ( *p_m_parent != nullptr && _V_stricmp(s1: p_m_parent[1], s2: *p_m_parent) != 0 )
        {
          for ( i = 0; i < this->m_collisionCount; ++i )
          {
            if ( i != v6 && _V_stricmp(s1: pPhys->m_parent, s2: v3[i]->m_name) == 0 )
              break;
          }
          if ( i <= v6 || i >= this->m_collisionCount )
          {
            v1 = this;
          }
          else
          {
            v3[v6] = v3[i];
            v3[i] = pPhys;
            swapped = true;
            v1 = this;
          }
        }
        ++v6;
      }
      while ( v6 < v1->m_collisionCount );
    }
    while ( swapped );
    for ( j = 0; j < v1->m_collisionCount - 1; ++j )
      v3[j]->m_pNext = v3[j + 1];
    v3[j]->m_pNext = nullptr;
    v1->m_pCollisionList = *v3;
    free(pMem: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401EB0
// Name: public: void CJointedModel::AppendCollisionPair(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CJointedModel::AppendCollisionPair(CJointedModel *this, const char *pName0, const char *pName1)
{
  collisionpair_t *v4; // edi
  int LocalBoneNamed; // eax
  s_node_t *v6; // eax
  int v7; // eax
  s_node_t *v8; // eax

  v4 = (collisionpair_t *)MemAlloc_Alloc(nSize: 0x14u);
  v4->obj0 = -1;
  v4->obj1 = -1;
  LocalBoneNamed = CCollisionModelSource::FindLocalBoneNamed(this, pName: pName0);
  if ( LocalBoneNamed < 0 )
    v6 = nullptr;
  else
    v6 = &this->m_pModel->localBone[LocalBoneNamed];
  v4->pName0 = (const char *)v6;
  v7 = CCollisionModelSource::FindLocalBoneNamed(this, pName: pName1);
  if ( v7 < 0 )
    v8 = nullptr;
  else
    v8 = &this->m_pModel->localBone[v7];
  v4->pName1 = (const char *)v8;
  v4->pNext = this->m_pCollisionPairs;
  this->m_pCollisionPairs = v4;
}

//------------------------------------------------------------------------------
// Address: 0x00401F30
// Name: public: void CJointedModel::ForceMassCenter(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CJointedModel::ForceMassCenter(CJointedModel *this, const Vector *centerOfMass)
{
  this->m_isMassCenterForced = true;
  this->m_massCenterForced = *centerOfMass;
}

//------------------------------------------------------------------------------
// Address: 0x00401F60
// Name: public: class CPhysCollisionModel __near * CJointedModel::GetCollisionModel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CPhysCollisionModel *__thiscall CJointedModel::GetCollisionModel(CJointedModel *this, const char *pName)
{
  CPhysCollisionModel *m_pCollisionList; // esi

  if ( pName == nullptr )
    return nullptr;
  m_pCollisionList = this->m_pCollisionList;
  if ( m_pCollisionList == nullptr )
    return nullptr;
  while ( _V_stricmp(s1: pName, s2: m_pCollisionList->m_name) != 0 )
  {
    m_pCollisionList = m_pCollisionList->m_pNext;
    if ( m_pCollisionList == nullptr )
      return nullptr;
  }
  return m_pCollisionList;
}

//------------------------------------------------------------------------------
// Address: 0x00401FB0
// Name: public: void CJointedModel::AddConstraint(char const __near *,int,enum jointlimit_t,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CJointedModel::AddConstraint(
        CJointedModel *this,
        const char *pJointName,
        int axis,
        jointlimit_t jointType,
        float limitMin,
        float limitMax,
        float friction)
{
  float *v8; // eax

  v8 = (float *)MemAlloc_Alloc(nSize: 0x1Cu);
  if ( v8 != nullptr )
  {
    v8[3] = limitMin;
    v8[4] = limitMax;
    *((_DWORD *)v8 + 1) = axis;
    *((_DWORD *)v8 + 2) = jointType;
    v8[5] = friction * 0.2;
    *(_DWORD *)v8 = pJointName;
  }
  else
  {
    v8 = nullptr;
  }
  v8[6] = *(float *)&this->m_pConstraintList;
  ++this->m_constraintCount;
  this->m_pConstraintList = (CJointConstraint *)v8;
}

//------------------------------------------------------------------------------
// Address: 0x00402020
// Name: public: void CJointedModel::ComputeMass(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CJointedModel::ComputeMass(CJointedModel *this)
{
  CPhysCollisionModel *m_pCollisionList; // esi
  const char *SurfaceProp; // eax
  int v4; // eax
  float thickness; // [esp+24h] [ebp-8h] BYREF
  float density; // [esp+28h] [ebp-4h] BYREF

  if ( this->m_totalMass < 0.0 )
  {
    m_pCollisionList = this->m_pCollisionList;
    for ( this->m_totalMass = 0.0; m_pCollisionList != nullptr; m_pCollisionList = m_pCollisionList->m_pNext )
    {
      SurfaceProp = GetSurfaceProp(pJointName: m_pCollisionList->m_name);
      v4 = physprops->GetSurfaceIndex(this: physprops, a2: SurfaceProp);
      physprops->GetPhysicsProperties(this: physprops, a2: v4, a3: &density, a4: &thickness, a5: nullptr, a6: nullptr);
      if ( thickness <= 0.0 )
        this->m_totalMass = (float)((float)(m_pCollisionList->m_volume * 0.000016387063) * density) + this->m_totalMass;
      else
        this->m_totalMass = (float)((float)((float)(m_pCollisionList->m_surfaceArea * thickness) * 0.000016387063)
                                  * density)
                          + this->m_totalMass;
    }
    if ( !g_quiet )
      printf(format: "Computed Mass: %.2f kg\n", this->m_totalMass);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402120
// Name: public: class CPhysCollisionModel __near * CJointedModel::InitCollisionModel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CPhysCollisionModel *__thiscall CJointedModel::InitCollisionModel(CJointedModel *this, const char *pJointName)
{
  CPhysCollisionModel *CollisionModel; // esi
  int v4; // ebx
  unsigned __int8 *v6; // eax
  int parent; // eax
  double m_defaultRotdamping; // st7

  CollisionModel = CJointedModel::GetCollisionModel(this, pName: pJointName);
  if ( CollisionModel == nullptr )
  {
    v4 = CJointedModel::BoneIndex(this, pName: pJointName);
    if ( v4 < 0 )
      return nullptr;
    v6 = (unsigned __int8 *)MemAlloc_Alloc(nSize: 0x30u);
    CollisionModel = (CPhysCollisionModel *)v6;
    if ( v6 != nullptr )
      memset(dst: v6, value: 0, count: 0x30u);
    else
      CollisionModel = nullptr;
    CollisionModel->m_name = this->m_pModel->localBone[v4].name;
    parent = this->m_pModel->localBone[v4].parent;
    if ( parent < 0 )
      CollisionModel->m_parent = nullptr;
    else
      CollisionModel->m_parent = this->m_pModel->localBone[parent].name;
    CollisionModel->m_damping = this->m_defaultDamping;
    CollisionModel->m_inertia = this->m_defaultInertia;
    m_defaultRotdamping = this->m_defaultRotdamping;
    CollisionModel->m_massBias = 1.0;
    CollisionModel->m_rotdamping = m_defaultRotdamping;
    CollisionModel->m_dragCoefficient = this->m_defaultDrag;
    if ( this->m_isMassCenterForced )
      physcollision->CollideSetMassCenter(
        this: physcollision,
        a2: CollisionModel->m_pCollisionData,
        a3: &this->m_massCenterForced);
    CollisionModel->m_pNext = this->m_pCollisionList;
    ++this->m_collisionCount;
    this->m_pCollisionList = CollisionModel;
  }
  return CollisionModel;
}

//------------------------------------------------------------------------------
// Address: 0x00402220
// Name: void BuildVertWeldTable(int __near *,struct s_source_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildVertWeldTable(int *weldTable, s_source_t *pmodel)
{
  s_source_t *v2; // eax
  int v3; // esi
  int v4; // ecx
  int v5; // edi
  s_vertexinfo_t *vertex; // edx
  float x; // xmm3_4
  float y; // xmm4_4
  float z; // xmm5_4
  float *p_z; // eax
  float *v11; // edx
  s_vertexinfo_t *v12; // [esp-8h] [ebp-14h]
  float *v13; // [esp-4h] [ebp-10h]

  v2 = pmodel;
  v3 = 0;
  if ( pmodel->numvertices <= 0 )
    return;
  v4 = 0;
  do
  {
    v5 = 0;
    if ( v3 <= 0 )
    {
LABEL_10:
      weldTable[v3] = v3;
      goto LABEL_11;
    }
    vertex = v2->vertex;
    x = vertex[v4].position.x;
    y = vertex[v4].position.y;
    z = vertex[v4].position.z;
    v12 = vertex;
    p_z = &vertex->normal.z;
    v11 = &vertex->position.z;
    v13 = v11;
    while ( g_WeldVertEpsilon < fsqrt(
                                  (float)((float)((float)(*(v11 - 1) - y) * (float)(*(v11 - 1) - y))
                                        + (float)((float)(*v11 - z) * (float)(*v11 - z)))
                                + (float)((float)(*(v11 - 2) - x) * (float)(*(v11 - 2) - x))) )
    {
LABEL_8:
      ++v5;
      v11 += 21;
      p_z += 21;
      v13 = v11;
      if ( v5 >= v3 )
      {
        v2 = pmodel;
        goto LABEL_10;
      }
    }
    if ( (float)((float)((float)(*(p_z - 1) * v12[v4].normal.y) + (float)(*(p_z - 2) * v12[v4].normal.x))
               + (float)(v12[v4].normal.z * *p_z)) <= g_WeldNormalEpsilon )
    {
      v11 = v13;
      goto LABEL_8;
    }
    weldTable[v3] = v5;
    v2 = pmodel;
LABEL_11:
    ++v3;
    ++v4;
  }
  while ( v3 < v2->numvertices );
}

//------------------------------------------------------------------------------
// Address: 0x00402350
// Name: public: char const __near * CJointedModel::FixParent(char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CJointedModel::FixParent(CJointedModel *this, const char *pParentName)
{
  const char *name; // edi
  CPhysCollisionModel *m_pCollisionList; // esi
  int LocalBoneNamed; // eax
  s_source_t *m_pModel; // ecx
  int parent; // eax
  int v8; // eax

  name = pParentName;
  if ( pParentName == nullptr )
    return nullptr;
  while ( 1 )
  {
    m_pCollisionList = this->m_pCollisionList;
    if ( m_pCollisionList != nullptr )
      break;
LABEL_5:
    LocalBoneNamed = CCollisionModelSource::FindLocalBoneNamed(this, pName: name);
    if ( LocalBoneNamed >= 0 )
    {
      m_pModel = this->m_pModel;
      parent = this->m_pModel->localBone[LocalBoneNamed].parent;
      if ( parent >= 0 )
      {
        v8 = parent;
        name = m_pModel->localBone[v8].name;
        if ( &m_pModel->filename[v8 * 132] != (char *)-268 )
          continue;
      }
    }
    return nullptr;
  }
  while ( _V_stricmp(s1: name, s2: m_pCollisionList->m_name) != 0 )
  {
    m_pCollisionList = m_pCollisionList->m_pNext;
    if ( m_pCollisionList == nullptr )
      goto LABEL_5;
  }
  return name;
}

//------------------------------------------------------------------------------
// Address: 0x004023D0
// Name: bool IsApproximatelyPlanar(class Vector __near * __near *,int,float)
// Source: json
//------------------------------------------------------------------------------
char __usercall IsApproximatelyPlanar@<al>(float a1@<ebp>, Vector **verts, int vertCount, float epsilon)
{
  int v4; // edx
  int v5; // edi
  Vector *v6; // ecx
  float x; // xmm3_4
  float y; // xmm4_4
  float v9; // xmm5_4
  Vector *v10; // ecx
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  int v14; // ecx
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm0_4
  float v19; // [esp-Ch] [ebp-2Ch]
  float v20; // [esp-8h] [ebp-28h]
  Vector edge0; // [esp+0h] [ebp-20h] BYREF
  Vector normal; // [esp+Ch] [ebp-14h]
  void *v23; // [esp+18h] [ebp-8h]
  void *retaddr; // [esp+20h] [ebp+0h]

  normal.z = a1;
  v23 = retaddr;
  v4 = vertCount;
  if ( vertCount < 4 )
    return 1;
  LODWORD(normal.y) = 1;
  v5 = 2;
  while ( v5 < v4 )
  {
    v6 = verts[LODWORD(normal.y)];
    x = v6->x;
    y = v6->y;
    v9 = v6->z - (*verts)->z;
    v10 = verts[v5];
    v11 = v10->y - (*verts)->y;
    v12 = v10->x - (*verts)->x;
    v13 = v10->z - (*verts)->z;
    v19 = x - (*verts)->x;
    v20 = y - (*verts)->y;
    edge0.x = (float)(v13 * v20) - (float)(v11 * v9);
    edge0.y = (float)(v9 * v12) - (float)(v13 * v19);
    edge0.z = (float)(v11 * v19) - (float)(v12 * v20);
    if ( VectorNormalize(vec: &edge0) > 0.001 )
      goto LABEL_9;
    normal.x = v20 * v20;
    if ( fsqrt((float)((float)(v20 * v20) + (float)(v9 * v9)) + (float)(v19 * v19)) < 0.001 )
      ++LODWORD(normal.y);
    ++v5;
    if ( SLODWORD(normal.y) >= vertCount )
    {
LABEL_9:
      v4 = vertCount;
      break;
    }
    v4 = vertCount;
  }
  v14 = 0;
  v15 = (float)((float)((*verts)->y * edge0.y) + (float)((*verts)->x * edge0.x)) + (float)((*verts)->z * edge0.z);
  v16 = v15;
  if ( v4 <= 0 )
    return 1;
  while ( 1 )
  {
    v17 = (float)((float)(verts[v14]->y * edge0.y) + (float)(verts[v14]->x * edge0.x))
        + (float)(verts[v14]->z * edge0.z);
    if ( v15 <= v17 )
    {
      if ( v17 > v16 )
        v16 = (float)((float)(verts[v14]->y * edge0.y) + (float)(verts[v14]->x * edge0.x))
            + (float)(verts[v14]->z * edge0.z);
    }
    else
    {
      v15 = (float)((float)(verts[v14]->y * edge0.y) + (float)(verts[v14]->x * edge0.x))
          + (float)(verts[v14]->z * edge0.z);
    }
    if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(v16 - v15) & _mask__AbsFloat_) > epsilon )
      break;
    if ( ++v14 >= v4 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004025E0
// Name: int ReadArgs(char (__near * const)[256],int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ReadArgs(char (*pArgs)[256], int maxCount)
{
  int i; // esi

  for ( i = 0; i < maxCount; ++pArgs )
  {
    if ( TokenAvailable() == 0 )
      break;
    GetToken(crossline: 0);
    strncpy(dest: (unsigned __int8 *)pArgs, source: (unsigned __int8 *)token, count: 0x100u);
    ++i;
  }
  return i;
}

//------------------------------------------------------------------------------
// Address: 0x00402630
// Name: void CCmd_JointConstrain(class CJointedModel __near &,char const __near *,char const __near *,char const __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CCmd_JointConstrain(
        CJointedModel *joints,
        const char *pJointName,
        const char *pJointAxis,
        const char *pJointType,
        const char *pLimitMin,
        const char *pLimitMax,
        const char *pFriction)
{
  int LocalBoneNamed; // eax
  s_node_t *v8; // ebx
  int v9; // esi
  jointlimit_t v10; // eax
  float limitMin; // [esp+18h] [ebp-4h]
  float limitMax; // [esp+34h] [ebp+18h]
  float friction; // [esp+38h] [ebp+1Ch]

  if ( pLimitMin != nullptr )
    limitMin = atof(nptr: pLimitMin);
  else
    limitMin = 0.0;
  if ( pLimitMax != nullptr )
    limitMax = atof(nptr: pLimitMax);
  else
    limitMax = 0.0;
  if ( pFriction != nullptr )
    friction = atof(nptr: pFriction);
  else
    friction = 0.0;
  LocalBoneNamed = CCollisionModelSource::FindLocalBoneNamed(this: joints, pName: pJointName);
  if ( !g_bCreateMakefile && LocalBoneNamed < 0 )
  {
    MdlWarning(fmt: "Can't find joint %s\n", pJointName);
    return;
  }
  v8 = &joints->m_pModel->localBone[LocalBoneNamed];
  if ( pJointAxis == nullptr || (unsigned int)(v9 = tolower(c: *pJointAxis) - 120) > 2 || limitMin > limitMax )
    MdlError(fmt: "Invalid joint constraint for %s\nCan't build ragdoll!\n", v8->name);
  v10 = _V_stricmp(s1: pJointType, s2: "free");
  if ( v10 == JOINT_FREE )
    goto LABEL_21;
  if ( _V_stricmp(s1: pJointType, s2: "fixed") == 0 )
  {
    v10 = JOINT_FIXED;
LABEL_21:
    CJointedModel::AddConstraint(
      this: joints,
      pJointName: v8->name,
      axis: v9,
      jointType: v10,
      limitMin,
      limitMax,
      friction);
    return;
  }
  if ( _V_stricmp(s1: pJointType, s2: "limit") == 0 )
  {
    v10 = JOINT_LIMIT;
    goto LABEL_21;
  }
  MdlWarning(fmt: "Unknown joint type %s (must be free, fixed, or limit)\n", pJointType);
}

//------------------------------------------------------------------------------
// Address: 0x004027B0
// Name: void CCmd_JointSkip(class CJointedModel __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CCmd_JointSkip(CJointedModel *joints, const char *pName)
{
  int LocalBoneNamed; // eax

  LocalBoneNamed = CCollisionModelSource::FindLocalBoneNamed(this: joints, pName);
  if ( LocalBoneNamed >= 0 )
    CCollisionModelSource::SkipBone(this: joints, boneIndex: LocalBoneNamed);
  else
    MdlWarning(fmt: "Can't skip joint %s, not found\n", pName);
}

//------------------------------------------------------------------------------
// Address: 0x004027F0
// Name: void CCmd_JointRoot(class CJointedModel __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CCmd_JointRoot(CJointedModel *joints, const char *pBone)
{
  strcpy(joints->m_rootName, pBone);
}

//------------------------------------------------------------------------------
// Address: 0x00402810
// Name: void CCmd_JoinAnimatedFriction(class CJointedModel __near &,char const __near *,char const __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CCmd_JoinAnimatedFriction(
        CJointedModel *joints,
        const char *pMinFriction,
        const char *pMaxFriction,
        const char *pTimeIn,
        const char *pTimeHold,
        const char *pTimeOut)
{
  float v6; // xmm0_4
  float v7; // xmm0_4
  float v8; // xmm0_4
  const char *v9; // eax
  int v10; // eax
  float pTimeIna; // [esp+14h] [ebp+14h]
  float pTimeInb; // [esp+14h] [ebp+14h]
  float pTimeInc; // [esp+14h] [ebp+14h]

  if ( pTimeIn != nullptr )
  {
    pTimeIna = atof(nptr: pTimeIn);
    v6 = pTimeIna;
  }
  else
  {
    v6 = 0.0;
  }
  joints->m_flFrictionTimeIn = v6;
  if ( pTimeOut != nullptr )
  {
    pTimeInb = atof(nptr: pTimeOut);
    v7 = pTimeInb;
  }
  else
  {
    v7 = 0.0;
  }
  joints->m_flFrictionTimeOut = v7;
  if ( pTimeHold != nullptr )
  {
    pTimeInc = atof(nptr: pTimeHold);
    v8 = pTimeInc;
  }
  else
  {
    v8 = 0.0;
  }
  v9 = pMinFriction;
  joints->m_flFrictionTimeHold = v8;
  if ( pMinFriction != nullptr )
    v9 = (const char *)atoi(nptr: pMinFriction);
  joints->m_iMinAnimatedFriction = (int)v9;
  if ( pMaxFriction != nullptr )
  {
    v10 = atoi(nptr: pMaxFriction);
    joints->m_bHasAnimatedFriction = true;
    joints->m_iMaxAnimatedFriction = v10;
  }
  else
  {
    joints->m_bHasAnimatedFriction = true;
    joints->m_iMaxAnimatedFriction = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004028D0
// Name: LoadSurfaceProps
// Source: json
//------------------------------------------------------------------------------
char __usercall LoadSurfaceProps@<al>(int a1@<ebx>, int a2@<edi>, int a3@<esi>, const char *pMaterialFilename)
{
  void *v5; // ebx
  int v6; // edi
  void *v7; // esi

  if ( physprops == nullptr )
    return 0;
  v5 = g_pFileSystem->Open(this: g_pFileSystem, a2: pMaterialFilename, a3: "rb", a4: "GAME");
  if ( v5 == nullptr )
    return 0;
  v6 = ((int (__thiscall *)(IBaseFileSystem *, void *, int, int, int))g_pFileSystem->Size_2)(
         a1: g_pFileSystem,
         a2: v5,
         a3: a2,
         a4: a3,
         a5: a1);
  v7 = MemAlloc_Alloc(nSize: v6 + 1);
  g_pFileSystem->Read(this: g_pFileSystem, a2: v7, a3: v6, a4: v5);
  ((void (__thiscall *)(IBaseFileSystem *))g_pFileSystem->Close)(a1: g_pFileSystem);
  *((_BYTE *)v7 + v6) = 0;
  physprops->ParseSurfaceData(this: physprops, a2: pMaterialFilename, a3: (const char *)v7);
  free(pMem: v7);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00402970
// Name: void LoadSurfacePropsAll(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall LoadSurfacePropsAll(int a1@<ebx>)
{
  KeyValues *v1; // eax
  KeyValues *v2; // edi
  KeyValues *i; // esi
  const char *Name; // eax
  const char *String; // eax

  if ( !bIsLoaded )
  {
    v1 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v1 != nullptr )
      v2 = KeyValues::KeyValues(this: v1, setName: "scripts/surfaceproperties_manifest.txt");
    else
      v2 = nullptr;
    if ( KeyValues::LoadFromFile(
           this: v2,
           filesystem: g_pFileSystem,
           resourceName: "scripts/surfaceproperties_manifest.txt",
           pathID: "GAME",
           pfnEvaluateSymbolProc: nullptr) )
    {
      bIsLoaded = true;
      for ( i = KeyValues::GetFirstSubKey(this: v2); i != nullptr; i = KeyValues::GetNextKey(this: i) )
      {
        Name = KeyValues::GetName(this: i);
        if ( _V_stricmp(s1: Name, s2: "file") == 0 )
        {
          String = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: pDeltaStateName);
          LoadSurfaceProps(a1, a2: (int)v2, a3: (int)i, pMaterialFilename: String);
        }
      }
    }
    KeyValues::deleteThis(this: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402A20
// Name: void BuildRagdollConstraint(class CPhysCollisionModel __near *,struct constraint_ragdollparams_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildRagdollConstraint(CPhysCollisionModel *pPhys, constraint_ragdollparams_t *ragdoll)
{
  int v2; // eax
  bool v3; // sf
  CJointConstraint *i; // edi
  const char *m_pJointName; // eax
  CPhysCollisionModel *m_pCollisionList; // esi
  int v7; // ebx
  const char *v8; // ebx
  CPhysCollisionModel *v9; // esi
  const char *m_parent; // eax
  CPhysCollisionModel *v11; // esi
  int v12; // ebx
  jointlimit_t m_jointType; // eax
  __int32 v14; // eax
  double m_limitMin; // st7
  float m_friction; // xmm1_4
  constraint_axislimit_t *v17; // eax
  float v18; // xmm0_4
  constraint_axislimit_t *v19; // eax
  const char *v20; // [esp+8h] [ebp-4h]
  int index; // [esp+14h] [ebp+8h]
  int indexa; // [esp+14h] [ebp+8h]

  memset(dst: (unsigned __int8 *)ragdoll, value: 0, count: sizeof(constraint_ragdollparams_t));
  ragdoll->parentIndex = CJointedModel::CollisionIndex(this: &g_JointedModel, pName: pPhys->m_parent);
  v2 = CJointedModel::CollisionIndex(this: &g_JointedModel, pName: pPhys->m_name);
  v3 = ragdoll->parentIndex < 0;
  ragdoll->childIndex = v2;
  if ( v3 || v2 < 0 )
  {
    MdlWarning(fmt: "Constraint between bone %s and %s\n", pPhys->m_name, pPhys->m_parent);
    if ( ragdoll->childIndex < 0 )
      MdlWarning(fmt: "\"%s\" does not appear in collision model!!!\n", pPhys->m_name);
    if ( ragdoll->parentIndex < 0 )
      MdlWarning(fmt: "\"%s\" does not appear in collision model!!!\n", pPhys->m_parent);
    MdlError(fmt: "Bad constraint in ragdoll\n");
  }
  for ( i = g_JointedModel.m_pConstraintList; i != nullptr; i = i->m_pNext )
  {
    m_pJointName = i->m_pJointName;
    index = (int)i->m_pJointName;
    if ( i->m_pJointName != nullptr
      && (m_pCollisionList = g_JointedModel.m_pCollisionList, v7 = 0, g_JointedModel.m_pCollisionList != nullptr) )
    {
      while ( _V_stricmp(s1: m_pJointName, s2: m_pCollisionList->m_name) != 0 )
      {
        m_pCollisionList = m_pCollisionList->m_pNext;
        ++v7;
        if ( m_pCollisionList == nullptr )
          goto LABEL_11;
        m_pJointName = (const char *)index;
      }
      indexa = v7;
    }
    else
    {
LABEL_11:
      indexa = -1;
    }
    v8 = i->m_pJointName;
    if ( i->m_pJointName != nullptr
      && (v9 = g_JointedModel.m_pCollisionList, g_JointedModel.m_pCollisionList != nullptr) )
    {
      while ( _V_stricmp(s1: v8, s2: v9->m_name) != 0 )
      {
        v9 = v9->m_pNext;
        if ( v9 == nullptr )
          goto LABEL_16;
      }
    }
    else
    {
LABEL_16:
      v9 = nullptr;
    }
    if ( indexa < 0 )
      MdlError(fmt: "Rotation constraint on bone \"%s\" which does not appear in collision model!!!\n", i->m_pJointName);
    m_parent = v9->m_parent;
    v20 = v9->m_parent;
    if ( v9->m_parent == nullptr )
      goto LABEL_32;
    v11 = g_JointedModel.m_pCollisionList;
    v12 = 0;
    if ( g_JointedModel.m_pCollisionList == nullptr )
      goto LABEL_32;
    while ( _V_stricmp(s1: m_parent, s2: v11->m_name) != 0 )
    {
      v11 = v11->m_pNext;
      ++v12;
      if ( v11 == nullptr )
        goto LABEL_32;
      m_parent = v20;
    }
    if ( v12 < 0 )
    {
LABEL_32:
      if ( _V_stricmp(s1: i->m_pJointName, s2: g_JointedModel.m_rootName) != 0 )
        MdlError(fmt: "Rotation constraint on bone \"%s\" which has no parent!!!\n", i->m_pJointName);
    }
    if ( indexa != ragdoll->childIndex )
      continue;
    m_jointType = i->m_jointType;
    if ( m_jointType != JOINT_FREE )
    {
      v14 = m_jointType - 1;
      if ( v14 != 0 )
      {
        if ( v14 == 1 )
        {
          m_limitMin = i->m_limitMin;
          m_friction = i->m_friction;
          v17 = &ragdoll->axes[i->m_axis];
          v17->maxRotation = i->m_limitMax;
          v17->minRotation = m_limitMin;
          v17->angularVelocity = 0.0;
          v17->torque = m_friction;
        }
        continue;
      }
      v18 = 0.0;
      v19 = &ragdoll->axes[i->m_axis];
      v19->minRotation = 0.0;
      v19->maxRotation = 0.0;
      v19->angularVelocity = 0.0;
    }
    else
    {
      v18 = i->m_friction;
      v19 = &ragdoll->axes[i->m_axis];
      v19->minRotation = -360.0;
      v19->maxRotation = 360.0;
      v19->angularVelocity = 0.0;
    }
    v19->torque = v18;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402C60
// Name: float GetCollisionModelMass(void)
// Source: json
//------------------------------------------------------------------------------
double __cdecl GetCollisionModelMass()
{
  return g_JointedModel.m_totalMass;
}

//------------------------------------------------------------------------------
// Address: 0x00402C70
// Name: void CollisionModel_ExpandBBox(class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CollisionModel_ExpandBBox(Vector *mins, Vector *maxs)
{
  Vector collideMaxs; // [esp+0h] [ebp-18h] BYREF
  Vector collideMins; // [esp+Ch] [ebp-Ch] BYREF

  if ( !g_JointedModel.m_isJointed && g_JointedModel.m_pCollisionList != nullptr )
  {
    physcollision->CollideGetAABB(
      this: physcollision,
      a2: &collideMins,
      a3: &collideMaxs,
      a4: g_JointedModel.m_pCollisionList->m_pCollisionData,
      a5: &vec3_origin,
      a6: &vec3_angle);
    collideMins.x = collideMins.x - 0.25;
    collideMins.y = collideMins.y - 0.25;
    collideMins.z = collideMins.z - 0.25;
    collideMaxs.x = collideMaxs.x + 0.25;
    collideMaxs.y = collideMaxs.y + 0.25;
    collideMaxs.z = collideMaxs.z + 0.25;
    AddPointToBounds(v: &collideMins, mins, maxs);
    AddPointToBounds(v: &collideMaxs, mins, maxs);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402D40
// Name: void CollisionModel_SetName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CollisionModel_SetName(const char *pName)
{
  int v1; // eax
  int v2; // esi

  if ( g_JointedModel.m_pOverrideName != nullptr )
    free(pMem: g_JointedModel.m_pOverrideName);
  if ( pName != nullptr )
  {
    v1 = _V_strlen(str: pName);
    if ( v1 != 0 )
    {
      v2 = v1 + 1;
      g_JointedModel.m_pOverrideName = (char *)MemAlloc_Alloc(nSize: v1 + 1);
      V_strncpy(pDest: g_JointedModel.m_pOverrideName, pSrc: pName, maxLen: v2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402D90
// Name: public: CPlainAutoPtr<class CP4File>::CPlainAutoPtr<class CP4File>(class CP4File __near *)
// Source: json
//------------------------------------------------------------------------------
CPlainAutoPtr<CP4File> *__thiscall CPlainAutoPtr<CP4File>::CPlainAutoPtr<CP4File>(
        CPlainAutoPtr<CP4File> *this,
        CP4File *p)
{
  this->m_p = p;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00402DA0
// Name: float clamp<float,float,float>(float const __near &,float const __near &,float const __near &)
// Source: json
//------------------------------------------------------------------------------
double __cdecl clamp<float,float,float>(const float *val, const float *minVal, const float *maxVal)
{
  if ( *minVal > *val )
    return *minVal;
  if ( *val <= *maxVal )
    return *val;
  return *maxVal;
}

//------------------------------------------------------------------------------
// Address: 0x00402DF0
// Name: void CreateCollide(class CPhysCollisionModel __near *,class CPhysConvex __near * __near *,int,struct boundingvolume_t const __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall CreateCollide(
        float a1@<ebp>,
        CPhysCollisionModel *pBase,
        struct CPhysConvex **pElements,
        int elementCount,
        const boundingvolume_t *bv)
{
  int v5; // edi
  double v6; // st7
  float v7; // xmm2_4
  float v8; // xmm1_4
  float v9; // xmm4_4
  float v10; // xmm0_4
  int v11; // eax
  float v12; // xmm1_4
  float v13; // xmm0_4
  __int128 v14; // xmm0
  _DWORD v15[3]; // [esp-Ch] [ebp-3Ch] BYREF
  _BYTE params[20]; // [esp+0h] [ebp-30h] OVERLAPPED
  Vector tmp; // [esp+14h] [ebp-1Ch]
  Vector size; // [esp+20h] [ebp-10h]
  float retaddr; // [esp+30h] [ebp+0h]

  size.y = a1;
  size.z = retaddr;
  if ( pBase != nullptr )
  {
    v5 = 0;
    pBase->m_volume = 0.0;
    for ( pBase->m_surfaceArea = 0.0; v5 < elementCount; pBase->m_surfaceArea = v6 + pBase->m_surfaceArea )
    {
      pBase->m_volume = ((double (__thiscall *)(IPhysicsCollision *, struct CPhysConvex *))physcollision->ConvexVolume)(
                          a1: physcollision,
                          a2: pElements[v5])
                      + pBase->m_volume;
      v6 = ((double (__thiscall *)(IPhysicsCollision *, struct CPhysConvex *))physcollision->ConvexSurfaceArea)(
             a1: physcollision,
             a2: pElements[v5++]);
    }
    v7 = bv->maxs.x - bv->mins.x;
    v8 = bv->maxs.y - bv->mins.y;
    v9 = bv->maxs.z - bv->mins.z;
    v10 = v9 * v8;
    v11 = v8 > v7;
    LOWORD(v15[1]) = 0;
    *(_DWORD *)params = 0;
    v15[0] = 16777473;
    tmp.x = v7;
    tmp.y = v8;
    tmp.z = v9;
    if ( (float)(v9 * v8) < 0.0 || v10 > (float)(v9 * v7) )
      v10 = v9 * v7;
    if ( v9 > *(&tmp.x + v11) )
      v11 = 2;
    v12 = v8 * v7;
    if ( v10 < 0.0 || v10 > v12 )
      v10 = v12;
    v13 = v10 * 0.000099999997;
    if ( v13 >= 0.25 )
    {
      if ( v13 <= 128.0 )
        *(float *)&v15[2] = v13;
      else
        v15[2] = 1124073472;
    }
    else
    {
      v15[2] = 1048576000;
    }
    *(Vector *)&params[8] = tmp;
    *(_DWORD *)&params[4 * v11 + 8] = 0;
    size.x = *(float *)&params[12] * *(float *)&params[12];
    v14 = 0;
    *(float *)&v14 = fsqrt(
                       (float)((float)(*(float *)&params[12] * *(float *)&params[12])
                             + (float)(*(float *)&params[16] * *(float *)&params[16]))
                     + (float)(*(float *)&params[8] * *(float *)&params[8]));
    *(_OWORD *)&params[4] = v14;
    if ( *(float *)&v14 > 0.0 && (float)(*(&tmp.x + v11) / *(float *)&params[4]) > 9.0 )
      pBase->m_rotdamping = 1.0;
    pBase->m_pCollisionData = physcollision->ConvertConvexToCollideParams(
                                this: physcollision,
                                a2: pElements,
                                a3: elementCount,
                                a4: v15);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403080
// Name: public: char const __near * CDmElement::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmElement::GetName(CDmElement *this)
{
  const char *result; // eax

  result = this->m_Name.m_Storage.u.m_pAsString;
  if ( result == (const char *)-1 )
    return pDeltaStateName;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00403090
// Name: public: void CJointedModel::FixBoneList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CJointedModel::FixBoneList(CJointedModel *this)
{
  CPhysCollisionModel *i; // esi
  int LocalBoneNamed; // eax
  s_source_t *m_pModel; // ecx
  int j; // edx
  int v6; // ebx
  s_source_t *v7; // ecx
  int parent; // edx
  int v9; // edx
  int v10; // eax

  if ( this->m_isJointed )
  {
    for ( i = this->m_pCollisionList; i != nullptr; i = i->m_pNext )
    {
      LocalBoneNamed = CCollisionModelSource::FindLocalBoneNamed(this, pName: i->m_name);
      if ( LocalBoneNamed < 0 )
        goto LABEL_13;
      m_pModel = this->m_pModel;
      for ( j = 0;
            m_pModel->boneLocalToGlobal[LocalBoneNamed] < 0;
            LocalBoneNamed = m_pModel->localBone[LocalBoneNamed].parent )
      {
        v6 = j++;
        if ( v6 > 1024 )
          break;
      }
      if ( LocalBoneNamed < 0 )
      {
LABEL_13:
        MdlWarning(fmt: "Physics for unknown bone %s\n", i->m_name);
      }
      else
      {
        i->m_name = g_bonetable[m_pModel->boneLocalToGlobal[LocalBoneNamed]].name;
        i->m_parent = nullptr;
        v7 = this->m_pModel;
        parent = this->m_pModel->localBone[LocalBoneNamed].parent;
        if ( parent >= 0 && parent != LocalBoneNamed )
        {
          v9 = this->m_bonemap.m_Memory.m_pMemory[parent];
          v10 = v7->boneLocalToGlobal[v9];
          if ( v10 >= 0 )
            i->m_parent = g_bonetable[v10].name;
          else
            i->m_parent = v7->localBone[v9].name;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403180
// Name: void CCmd_JointConstrain(class CJointedModel __near &,int,char const __near *,class CDmeJointConstrain __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CCmd_JointConstrain(
        CJointedModel *joints,
        unsigned int nAxis,
        const char *pJointName,
        CDmeJointConstrain *pJointConstrain)
{
  int LocalBoneNamed; // eax
  const char *m_pAsString; // esi
  int v6; // eax
  float limitMin; // xmm0_4
  float limitMax; // xmm1_4
  s_node_t *v9; // ecx
  jointlimit_t m_Storage; // eax

  if ( pJointConstrain != nullptr )
  {
    LocalBoneNamed = FindLocalBoneNamed(pSource: joints->m_pModel, pName: pJointName);
    if ( g_bCreateMakefile || LocalBoneNamed >= 0 )
    {
      v6 = LocalBoneNamed;
      limitMin = pJointConstrain->m_aLimitMin.m_Storage;
      limitMax = pJointConstrain->m_aLimitMax.m_Storage;
      v9 = &joints->m_pModel->localBone[v6];
      if ( nAxis > 2 || limitMin > limitMax )
        MdlError(fmt: "Invalid joint constraint for %s\nCan't build ragdoll!\n", joints->m_pModel->localBone[v6].name);
      m_Storage = pJointConstrain->m_nType.m_Storage;
      if ( (unsigned int)m_Storage > JOINT_LIMIT )
        MdlWarning(
          fmt: "Invalid joint constraint for %s, Unknown joint type %d (must be 0:free, 1:fixed, or 2:limit)\n",
          v9->name,
          pJointConstrain->m_nType.m_Storage);
      else
        CJointedModel::AddConstraint(
          this: joints,
          pJointName: v9->name,
          axis: nAxis,
          jointType: m_Storage,
          limitMin,
          limitMax,
          friction: pJointConstrain->m_flFriction.m_Storage);
    }
    else
    {
      m_pAsString = pJointConstrain->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 )
        m_pAsString = pDeltaStateName;
      MdlWarning(fmt: "Can't find joint %s\n", m_pAsString);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403250
// Name: void CCmd_JoinAnimatedFriction(class CJointedModel __near &,class CDmeJointAnimatedFriction __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CCmd_JoinAnimatedFriction(CJointedModel *joints, CDmeJointAnimatedFriction *pJaf)
{
  if ( pJaf != nullptr )
  {
    joints->m_flFrictionTimeIn = (float)pJaf->m_tTimeIn.m_Storage.m_tms * 0.000099999997;
    joints->m_flFrictionTimeOut = (float)pJaf->m_tTimeOut.m_Storage.m_tms * 0.000099999997;
    joints->m_flFrictionTimeHold = (float)pJaf->m_tTimeHold.m_Storage.m_tms * 0.000099999997;
    joints->m_iMinAnimatedFriction = pJaf->m_nMinFriction.m_Storage;
    joints->m_iMaxAnimatedFriction = pJaf->m_nMaxFriction.m_Storage;
    joints->m_bHasAnimatedFriction = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004032C0
// Name: public: void CJointedModel::FixCollisionHierarchy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CJointedModel::FixCollisionHierarchy(CJointedModel *this)
{
  CPhysCollisionModel *m_pCollisionList; // esi
  CJointConstraint *i; // esi
  CPhysCollisionModel *v4; // esi
  int v5; // ebx
  int *p_physicsBoneIndex; // eax
  unsigned int v7; // ecx
  int v8; // edi
  int GlobalBone; // eax
  int *v10; // edx
  int parent; // eax
  int v12; // eax
  int physicsBoneIndex; // ecx

  m_pCollisionList = this->m_pCollisionList;
  if ( m_pCollisionList != nullptr )
  {
    CJointedModel::FixBoneList(this);
    do
    {
      m_pCollisionList->m_parent = CJointedModel::FixParent(this, pParentName: m_pCollisionList->m_parent);
      m_pCollisionList = m_pCollisionList->m_pNext;
    }
    while ( m_pCollisionList != nullptr );
    CJointedModel::SortCollisionList(this);
    for ( i = g_JointedModel.m_pConstraintList; i != nullptr; i = i->m_pNext )
      i->m_pJointName = CJointedModel::FixParent(this, pParentName: i->m_pJointName);
    v4 = this->m_pCollisionList;
    v5 = g_numbones;
    if ( (int)g_numbones > 0 )
    {
      p_physicsBoneIndex = &g_bonetable[0].physicsBoneIndex;
      v7 = g_numbones;
      do
      {
        *p_physicsBoneIndex = -1;
        p_physicsBoneIndex += 116;
        --v7;
      }
      while ( v7 != 0 );
    }
    v8 = 0;
    if ( v4 != nullptr )
    {
      do
      {
        GlobalBone = findGlobalBone(name: v4->m_name);
        if ( GlobalBone >= 0 )
          g_bonetable[GlobalBone].physicsBoneIndex = v8;
        v4 = v4->m_pNext;
        ++v8;
      }
      while ( v4 != nullptr );
      v5 = g_numbones;
    }
    if ( v5 > 0 )
    {
      v10 = &g_bonetable[0].physicsBoneIndex;
      do
      {
        if ( *v10 < 0 )
        {
          parent = *(v10 - 74);
          if ( parent < 0 )
          {
LABEL_20:
            *v10 = 0;
          }
          else
          {
            while ( 1 )
            {
              v12 = parent;
              physicsBoneIndex = g_bonetable[v12].physicsBoneIndex;
              if ( physicsBoneIndex >= 0 )
                break;
              parent = g_bonetable[v12].parent;
              if ( parent < 0 )
                goto LABEL_20;
            }
            *v10 = physicsBoneIndex;
          }
        }
        v10 += 116;
        --v5;
      }
      while ( v5 != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004033D0
// Name: public: CPlainAutoPtr<class CP4File>::~CPlainAutoPtr<class CP4File>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlainAutoPtr<CP4File>::~CPlainAutoPtr<CP4File>(CPlainAutoPtr<CP4File> *this)
{
  CP4File *m_p; // ecx

  m_p = this->m_p;
  this->m_p = nullptr;
  if ( m_p != nullptr )
    ((void (__thiscall *)(CP4File *, int))m_p->dtr_CP4File)(a1: m_p, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x004033F0
// Name: void CollisionModel_Write(long)
// Source: json
//------------------------------------------------------------------------------
void __usercall CollisionModel_Write(int a1@<edi>, int checkSum)
{
  CPhysCollisionModel *m_pCollisionList; // ebx
  int v3; // eax
  char v4; // cl
  char *v5; // eax
  char v6; // cl
  char *m_pOverrideName; // eax
  char *v8; // edx
  unsigned int v9; // eax
  char *v10; // edi
  char v11; // cl
  CPhysCollisionModel *v12; // eax
  float i; // xmm0_4
  float v14; // xmm2_4
  CP4File *v15; // edi
  bool (__thiscall *Edit)(CP4File *); // eax
  _iobuf *v17; // esi
  CPhysCollisionModel *v18; // eax
  CPhysCollisionModel *j; // edi
  char *v20; // ebx
  CPhysCollisionModel *v21; // edi
  int v22; // ebx
  float v23; // xmm1_4
  float v24; // xmm0_4
  const char *SurfaceProp; // eax
  float m_dragCoefficient; // xmm0_4
  float m_massBias; // xmm0_4
  CPhysCollisionModel *v28; // eax
  int parentIndex; // edi
  int childIndex; // ebx
  collisionpair_t *k; // edi
  int v32; // eax
  int obj0; // ecx
  int m; // edi
  char buf[512]; // [esp+24h] [ebp-4D4h] BYREF
  char filename[512]; // [esp+224h] [ebp-2D4h] BYREF
  constraint_ragdollparams_t ragdoll; // [esp+424h] [ebp-D4h] BYREF
  phyheader_s header; // [esp+4D8h] [ebp-20h] BYREF
  CPlainAutoPtr<CP4File> spFile; // [esp+4E8h] [ebp-10h]
  float volume; // [esp+4ECh] [ebp-Ch]
  char terminator; // [esp+4F3h] [ebp-5h] BYREF
  int size; // [esp+4F4h] [ebp-4h] BYREF

  m_pCollisionList = g_JointedModel.m_pCollisionList;
  if ( g_JointedModel.m_pCollisionList != nullptr )
  {
    v3 = 0;
    do
    {
      v4 = gamedir[v3];
      filename[v3++] = v4;
    }
    while ( v4 != 0 );
    v5 = &buf[511];
    do
      v6 = *++v5;
    while ( v6 != 0 );
    strcpy(v5, "models/");
    m_pOverrideName = g_JointedModel.m_pOverrideName;
    if ( g_JointedModel.m_pOverrideName == nullptr )
      m_pOverrideName = g_outname;
    v8 = m_pOverrideName;
    v9 = strlen(m_pOverrideName) + 1;
    v10 = &buf[511];
    do
      v11 = *++v10;
    while ( v11 != 0 );
    qmemcpy(v10, v8, v9);
    v12 = m_pCollisionList;
    for ( i = 0.0; v12 != nullptr; i = v14 + i )
    {
      v14 = v12->m_massBias * v12->m_volume;
      v12 = v12->m_pNext;
    }
    volume = i;
    if ( i <= 0.0 )
    {
      i = 1.0;
      volume = 1.0;
    }
    if ( !g_quiet )
      printf(format: "Collision model volume %.2f in^3\n", i);
    V_SetExtension(path: filename, extension: ".phy", pathStringLength: 512);
    v15 = CP4Factory::AccessFile(this: g_p4factory, szFilename: filename);
    Edit = v15->Edit;
    spFile.m_p = v15;
    ((void (__thiscall *)(CP4File *, int))Edit)(a1: v15, a2: a1);
    v17 = fopen(file: filename, mode: "wb");
    if ( v17 != nullptr )
    {
      v18 = g_JointedModel.m_pCollisionList;
      header.size = 16;
      header.id = 0;
      header.checkSum = checkSum;
      for ( header.solidCount = 0; v18 != nullptr; v18 = v18->m_pNext )
        ++header.solidCount;
      fwrite(buffer: &header, size: 0x10u, count: 1u, stream: v17);
      for ( j = g_JointedModel.m_pCollisionList; j != nullptr; j = j->m_pNext )
      {
        size = physcollision->CollideSize(this: physcollision, a2: j->m_pCollisionData);
        fwrite(buffer: &size, size: 4u, count: 1u, stream: v17);
        v20 = (char *)MemAlloc_Alloc(nSize: size);
        physcollision->CollideWrite(this: physcollision, a2: v20, a3: j->m_pCollisionData, a4: false);
        fwrite(buffer: v20, size, count: 1u, stream: v17);
        free(pMem: v20);
      }
      v21 = g_JointedModel.m_pCollisionList;
      v22 = 0;
      if ( g_JointedModel.m_pCollisionList != nullptr )
      {
        v23 = 1.0 / volume;
        for ( volume = 1.0 / volume; ; v23 = volume )
        {
          v24 = (float)((float)(v21->m_volume * v21->m_massBias) * v23) * g_JointedModel.m_totalMass;
          v21->m_mass = v24;
          if ( v24 < 1.0 )
            v21->m_mass = 1.0;
          fprintf(str: v17, format: "solid {\n");
          fprintf(str: v17, format: "\"%s\" \"%d\"\n", "index", v22);
          fprintf(str: v17, format: "\"%s\" \"%s\"\n", "name", v21->m_name);
          if ( v21->m_parent != nullptr )
            fprintf(str: v17, format: "\"%s\" \"%s\"\n", "parent", v21->m_parent);
          fprintf(str: v17, format: "\"%s\" \"%f\"\n", "mass", v21->m_mass);
          SurfaceProp = GetSurfaceProp(pJointName: v21->m_name);
          fprintf(str: v17, format: "\"%s\" \"%s\"\n", "surfaceprop", SurfaceProp);
          fprintf(str: v17, format: "\"%s\" \"%f\"\n", "damping", v21->m_damping);
          fprintf(str: v17, format: "\"%s\" \"%f\"\n", "rotdamping", v21->m_rotdamping);
          m_dragCoefficient = v21->m_dragCoefficient;
          if ( m_dragCoefficient != -1.0 )
            fprintf(str: v17, format: "\"%s\" \"%f\"\n", "drag", m_dragCoefficient);
          fprintf(str: v17, format: "\"%s\" \"%f\"\n", "inertia", v21->m_inertia);
          fprintf(str: v17, format: "\"%s\" \"%f\"\n", "volume", v21->m_volume);
          m_massBias = v21->m_massBias;
          if ( m_massBias != 1.0 )
            fprintf(str: v17, format: "\"%s\" \"%f\"\n", "massbias", m_massBias);
          fprintf(str: v17, format: "}\n");
          v21 = v21->m_pNext;
          ++v22;
          if ( v21 == nullptr )
            break;
        }
      }
      v28 = g_JointedModel.m_pCollisionList;
      size = (int)g_JointedModel.m_pCollisionList;
      if ( g_JointedModel.m_pCollisionList != nullptr )
      {
        while ( 1 )
        {
          if ( v28->m_parent != nullptr )
          {
            BuildRagdollConstraint(pPhys: v28, &ragdoll);
            parentIndex = ragdoll.parentIndex;
            childIndex = ragdoll.childIndex;
            if ( ragdoll.parentIndex != ragdoll.childIndex )
            {
              fprintf(str: v17, format: "ragdollconstraint {\n");
              fprintf(str: v17, format: "\"%s\" \"%d\"\n", "parent", parentIndex);
              fprintf(str: v17, format: "\"%s\" \"%d\"\n", "child", childIndex);
              fprintf(str: v17, format: "\"%s\" \"%f\"\n", "xmin", ragdoll.axes[0].minRotation);
              fprintf(str: v17, format: "\"%s\" \"%f\"\n", "xmax", ragdoll.axes[0].maxRotation);
              fprintf(str: v17, format: "\"%s\" \"%f\"\n", "xfriction", ragdoll.axes[0].torque);
              fprintf(str: v17, format: "\"%s\" \"%f\"\n", "ymin", ragdoll.axes[1].minRotation);
              fprintf(str: v17, format: "\"%s\" \"%f\"\n", "ymax", ragdoll.axes[1].maxRotation);
              fprintf(str: v17, format: "\"%s\" \"%f\"\n", "yfriction", ragdoll.axes[1].torque);
              fprintf(str: v17, format: "\"%s\" \"%f\"\n", "zmin", ragdoll.axes[2].minRotation);
              fprintf(str: v17, format: "\"%s\" \"%f\"\n", "zmax", ragdoll.axes[2].maxRotation);
              fprintf(str: v17, format: "\"%s\" \"%f\"\n", "zfriction", ragdoll.axes[2].torque);
              fprintf(str: v17, format: "}\n");
            }
            v28 = (CPhysCollisionModel *)size;
          }
          size = (int)v28->m_pNext;
          if ( size == 0 )
            break;
          v28 = (CPhysCollisionModel *)size;
        }
      }
      if ( g_JointedModel.m_noSelfCollisions )
      {
        fprintf(str: v17, format: "collisionrules {\n");
        fprintf(str: v17, format: "\"%s\" \"%d\"\n", "selfcollisions", 0);
        fprintf(str: v17, format: "}\n");
      }
      else if ( g_JointedModel.m_pCollisionPairs != nullptr )
      {
        fprintf(str: v17, format: "collisionrules {\n");
        for ( k = g_JointedModel.m_pCollisionPairs; k != nullptr; k = k->pNext )
        {
          k->obj0 = CJointedModel::CollisionIndex(this: &g_JointedModel, pName: k->pName0);
          v32 = CJointedModel::CollisionIndex(this: &g_JointedModel, pName: k->pName1);
          obj0 = k->obj0;
          k->obj1 = v32;
          if ( obj0 < 0 || v32 < 0 || obj0 == v32 )
            MdlWarning(fmt: "Invalid collision pair (%s, %s)\n", k->pName0, k->pName1);
          else
            fprintf(str: v17, format: "\"%s\" \"%d,%d\"\n", "collisionpair", obj0, v32);
        }
        fprintf(str: v17, format: "}\n");
      }
      if ( g_JointedModel.m_bHasAnimatedFriction )
      {
        fprintf(str: v17, format: "animatedfriction {\n");
        fprintf(str: v17, format: "\"%s\" \"%f\"\n", "animfrictionmin", (float)g_JointedModel.m_iMinAnimatedFriction);
        fprintf(str: v17, format: "\"%s\" \"%f\"\n", "animfrictionmax", (float)g_JointedModel.m_iMaxAnimatedFriction);
        fprintf(str: v17, format: "\"%s\" \"%f\"\n", "animfrictiontimein", g_JointedModel.m_flFrictionTimeIn);
        fprintf(str: v17, format: "\"%s\" \"%f\"\n", "animfrictiontimeout", g_JointedModel.m_flFrictionTimeOut);
        fprintf(str: v17, format: "\"%s\" \"%f\"\n", "animfrictiontimehold", g_JointedModel.m_flFrictionTimeHold);
        fprintf(str: v17, format: "}\n");
      }
      fprintf(str: v17, format: "editparams {\n");
      fprintf(str: v17, format: "\"%s\" \"%s\"\n", "rootname", g_JointedModel.m_rootName);
      fprintf(str: v17, format: "\"%s\" \"%f\"\n", "totalmass", g_JointedModel.m_totalMass);
      if ( g_JointedModel.m_allowConcave )
        fprintf(str: v17, format: "\"%s\" \"%d\"\n", "concave", 1);
      for ( m = 0; m < g_JointedModel.m_mergeList.m_Size; ++m )
      {
        V_snprintf(
          pDest: buf,
          maxLen: 512,
          pFormat: "%s,%s",
          g_JointedModel.m_mergeList.m_Memory.m_pMemory[m].pParent,
          g_JointedModel.m_mergeList.m_Memory.m_pMemory[m].pChild);
        fprintf(str: v17, format: "\"%s\" \"%s\"\n", "jointmerge", buf);
      }
      fprintf(str: v17, format: "}\n");
      terminator = 0;
      if ( g_JointedModel.m_textCommands.m_Size != 0 )
        fwrite(
          buffer: g_JointedModel.m_textCommands.m_Memory.m_pMemory,
          size: g_JointedModel.m_textCommands.m_Size,
          count: 1u,
          stream: v17);
      fwrite(buffer: &terminator, size: 1u, count: 1u, stream: v17);
      fclose(stream: v17);
      spFile.m_p->Add(this: spFile.m_p);
      ((void (__thiscall *)(CP4File *, int))spFile.m_p->dtr_CP4File)(a1: spFile.m_p, a2: 1);
    }
    else
    {
      MdlWarning(fmt: "Error writing %s!!!\n", filename);
      ((void (__thiscall *)(CP4File *, int))v15->dtr_CP4File)(a1: v15, a2: 1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403D50
// Name: public: void CJointedModel::AddText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CJointedModel::AddText(CJointedModel *this, char *pText)
{
  signed int v2; // edi
  int m_Size; // ebx
  CUtlMemory<unsigned char,int> *p_m_textCommands; // esi
  int m_nAllocationCount; // eax
  unsigned __int8 *m_pMemory; // ecx
  int v7; // eax

  v2 = strlen(pText);
  m_Size = this->m_textCommands.m_Size;
  p_m_textCommands = (CUtlMemory<unsigned char,int> *)&this->m_textCommands;
  if ( v2 != 0 )
  {
    m_nAllocationCount = this->m_textCommands.m_Memory.m_nAllocationCount;
    if ( m_Size + v2 > m_nAllocationCount )
      CUtlMemory<char,int>::Grow(this: p_m_textCommands, num: v2 + m_Size - m_nAllocationCount);
    p_m_textCommands[1].m_pMemory += v2;
    m_pMemory = p_m_textCommands->m_pMemory;
    v7 = (int)&p_m_textCommands[1].m_pMemory[-m_Size - v2];
    p_m_textCommands[1].m_nAllocationCount = (int)p_m_textCommands->m_pMemory;
    if ( v7 > 0 && v2 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + v2], src: &m_pMemory[m_Size], count: v7);
  }
  memcpy(dst: &p_m_textCommands->m_pMemory[m_Size], src: (unsigned __int8 *)pText, count: v2);
}

//------------------------------------------------------------------------------
// Address: 0x00403DE0
// Name: public: void CJointedModel::AddMergeCommand(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CJointedModel::AddMergeCommand(CJointedModel *this, const char *pParent, const char *pChild)
{
  int m_nAllocationCount; // eax
  CUtlMemory<CDmeMesh::FaceSet_t,int> *p_m_mergeList; // esi
  int m_Size; // edi
  CDmeMesh::FaceSet_t *m_pMemory; // ecx
  int v7; // eax
  char *v8; // eax
  char *v9; // eax

  m_nAllocationCount = this->m_mergeList.m_Memory.m_nAllocationCount;
  p_m_mergeList = (CUtlMemory<CDmeMesh::FaceSet_t,int> *)&this->m_mergeList;
  m_Size = this->m_mergeList.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<mergelist_t,int>::Grow(this: p_m_mergeList, num: m_Size - m_nAllocationCount + 1);
  ++p_m_mergeList[1].m_pMemory;
  m_pMemory = p_m_mergeList->m_pMemory;
  v7 = (int)p_m_mergeList[1].m_pMemory - m_Size - 1;
  p_m_mergeList[1].m_nAllocationCount = (int)p_m_mergeList->m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 8 * v7);
  if ( pParent != nullptr
    && (v8 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pParent) + 1)) != nullptr )
  {
    strcpy(v8, pParent);
  }
  else
  {
    v8 = nullptr;
  }
  p_m_mergeList->m_pMemory[m_Size].m_pMesh = (IMesh *)v8;
  if ( pChild != nullptr )
  {
    v9 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pChild) + 1);
    if ( v9 != nullptr )
    {
      strcpy(v9, pChild);
      *(_DWORD *)&p_m_mergeList->m_pMemory[m_Size].m_bBuilt = v9;
    }
    else
    {
      *(_DWORD *)&p_m_mergeList->m_pMemory[m_Size].m_bBuilt = 0;
    }
  }
  else
  {
    *(_DWORD *)&p_m_mergeList->m_pMemory[m_Size].m_bBuilt = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403F00
// Name: void BuildConvexListByVertID(struct s_source_t __near *,class CUtlVector<struct convexlist_t,class CUtlMemory<struct convexlist_t,int>> __near &,class CUtlVector<int,class CUtlMemory<int,int>> __near &,class CUtlVector<int,class CUtlMemory<int,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildConvexListByVertID(
        s_source_t *pmodel,
        CUtlMemory<CDmeMesh::FaceSet_t,int> *convexList,
        CUtlVector<int,CUtlMemory<int,int> > *vertList,
        CUtlVector<int,CUtlMemory<int,int> > *vertID)
{
  s_source_t *v4; // edi
  int numvertices; // eax
  int v6; // ebx
  CUtlVector<int,CUtlMemory<int,int> > *v7; // ecx
  int v8; // edx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v12; // eax
  int *v13; // eax
  int v14; // edi
  int v15; // eax
  convexlist_t *v16; // ecx
  int v17; // eax
  convexlist_t *v18; // edi
  int current; // [esp+8h] [ebp-10h]
  int current_4; // [esp+Ch] [ebp-Ch]
  int v21; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]

  v4 = pmodel;
  numvertices = pmodel->numvertices;
  v6 = 0;
  for ( i = 0; v6 < numvertices; i = v6 )
  {
    v7 = vertID;
    v8 = vertID->m_Memory.m_pMemory[v6];
    v21 = v8;
    if ( v8 >= 0 && v8 <= v4->numfaces )
    {
      current = vertList->m_Size;
      current_4 = 0;
      if ( v6 < numvertices )
      {
        do
        {
          if ( v7->m_Memory.m_pMemory[v6] == v8 )
          {
            m_Size = vertList->m_Size;
            m_nAllocationCount = vertList->m_Memory.m_nAllocationCount;
            if ( m_Size + 1 > m_nAllocationCount )
              CUtlMemory<IDmFormatUpdater *,int>::Grow(
                this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)vertList,
                num: m_Size - m_nAllocationCount + 1);
            ++vertList->m_Size;
            m_pMemory = vertList->m_Memory.m_pMemory;
            v12 = vertList->m_Size - m_Size - 1;
            vertList->m_pElements = vertList->m_Memory.m_pMemory;
            if ( v12 > 0 )
              _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v12);
            v13 = &vertList->m_Memory.m_pMemory[m_Size];
            if ( v13 != nullptr )
              *v13 = v6;
            v7 = vertID;
            ++current_4;
            vertID->m_Memory.m_pMemory[v6] = -1;
            v8 = v21;
          }
          ++v6;
        }
        while ( v6 < pmodel->numvertices );
      }
      v14 = (int)convexList[1].m_pMemory;
      v15 = convexList->m_nAllocationCount;
      if ( v14 + 1 > v15 )
        CUtlMemory<mergelist_t,int>::Grow(this: convexList, num: v14 - v15 + 1);
      ++convexList[1].m_pMemory;
      v16 = (convexlist_t *)convexList->m_pMemory;
      v17 = (int)convexList[1].m_pMemory - v14 - 1;
      convexList[1].m_nAllocationCount = (int)convexList->m_pMemory;
      if ( v17 > 0 )
        _V_memmove(dest: &v16[v14 + 1], src: &v16[v14], count: 8 * v17);
      v6 = i;
      v18 = (convexlist_t *)&convexList->m_pMemory[v14];
      if ( v18 != nullptr )
      {
        v18->firstVertIndex = current;
        v18->numVertIndex = current_4;
      }
    }
    v4 = pmodel;
    numvertices = pmodel->numvertices;
    ++v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404040
// Name: bool BuildConvexesForLists(class CUtlVector<class CPhysConvex __near *,class CUtlMemory<class CPhysConvex __near *,int>> __near &,class CUtlVector<struct convexlist_t,class CUtlMemory<struct convexlist_t,int>> const __near &,class CUtlVector<int,class CUtlMemory<int,int>> const __near &,class CUtlVector<class Vector,class CUtlMemory<class Vector,int>> const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl BuildConvexesForLists(
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *convexOut,
        const CUtlVector<convexlist_t,CUtlMemory<convexlist_t,int> > *convexList,
        const CUtlVector<int,CUtlMemory<int,int> > *vertList,
        const CUtlVector<Vector,CUtlMemory<Vector,int> > *worldspaceVerts,
        bool bRemove2d)
{
  const CUtlVector<convexlist_t,CUtlMemory<convexlist_t,int> > *v5; // edx
  int v6; // ecx
  Vector **v7; // esi
  bool result; // al
  const convexlist_t *v9; // edx
  int m_Size; // esi
  int v11; // ebx
  int v12; // edi
  Vector **m_pMemory; // ecx
  Vector **v14; // eax
  Vector **v15; // edi
  struct CPhysConvex *v16; // ebx
  int v17; // esi
  int m_nAllocationCount; // eax
  struct CPhysConvex **v19; // ecx
  int v20; // eax
  struct CPhysConvex **v21; // esi
  CUtlVector<Vector *,CUtlMemory<Vector *,int> > vertsThisConvex; // [esp+14h] [ebp-24h] BYREF
  Vector *pVert; // [esp+28h] [ebp-10h]
  int i; // [esp+2Ch] [ebp-Ch]
  const convexlist_t *elem; // [esp+30h] [ebp-8h]
  bool bValid; // [esp+37h] [ebp-1h]
  int savedregs; // [esp+38h] [ebp+0h] BYREF

  v5 = convexList;
  v6 = 0;
  v7 = nullptr;
  result = true;
  bValid = true;
  memset(&vertsThisConvex, 0, sizeof(vertsThisConvex));
  i = 0;
  if ( convexList->m_Size > 0 )
  {
    while ( 1 )
    {
      v9 = &v5->m_Memory.m_pMemory[v6];
      m_Size = 0;
      v11 = 0;
      elem = v9;
      vertsThisConvex.m_Size = 0;
      if ( v9->numVertIndex <= 0 )
        goto LABEL_21;
      do
      {
        pVert = &worldspaceVerts->m_Memory.m_pMemory[vertList->m_Memory.m_pMemory[v11 + v9->firstVertIndex]];
        v12 = m_Size;
        if ( m_Size + 1 > vertsThisConvex.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&vertsThisConvex,
            num: m_Size - vertsThisConvex.m_Memory.m_nAllocationCount + 1);
          m_Size = vertsThisConvex.m_Size;
          v9 = elem;
        }
        m_pMemory = vertsThisConvex.m_Memory.m_pMemory;
        vertsThisConvex.m_Size = ++m_Size;
        vertsThisConvex.m_pElements = vertsThisConvex.m_Memory.m_pMemory;
        if ( m_Size - v12 - 1 > 0 )
        {
          _V_memmove(
            dest: &vertsThisConvex.m_Memory.m_pMemory[v12 + 1],
            src: &vertsThisConvex.m_Memory.m_pMemory[v12],
            count: 4 * (m_Size - v12 - 1));
          v9 = elem;
          m_pMemory = vertsThisConvex.m_Memory.m_pMemory;
        }
        v14 = &m_pMemory[v12];
        if ( v14 != nullptr )
          *v14 = pVert;
        ++v11;
      }
      while ( v11 < v9->numVertIndex );
      if ( m_Size > 2 )
      {
        v15 = vertsThisConvex.m_Memory.m_pMemory;
        if ( IsApproximatelyPlanar(
               a1: COERCE_FLOAT(&savedregs),
               verts: vertsThisConvex.m_Memory.m_pMemory,
               vertCount: m_Size,
               epsilon: 0.5) == 0 )
          goto LABEL_14;
        if ( !bRemove2d )
          break;
      }
LABEL_21:
      v5 = convexList;
      v6 = i + 1;
      i = v6;
      if ( v6 >= convexList->m_Size )
      {
        result = bValid;
        v7 = vertsThisConvex.m_Memory.m_pMemory;
        goto LABEL_23;
      }
    }
    MdlWarning(fmt: "Model has 2-dimensional geometry (less than %.3f inches thick on any axis)!!!\n", 0.5);
    bValid = false;
LABEL_14:
    v16 = physcollision->ConvexFromVerts(this: physcollision, a2: v15, a3: m_Size);
    if ( v16 != nullptr )
    {
      physcollision->SetConvexGameData(this: physcollision, a2: v16, a3: 0);
      v17 = (int)convexOut[1].m_pMemory;
      m_nAllocationCount = convexOut->m_nAllocationCount;
      if ( v17 + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: convexOut, num: v17 - m_nAllocationCount + 1);
      ++convexOut[1].m_pMemory;
      v19 = (struct CPhysConvex **)convexOut->m_pMemory;
      v20 = (int)convexOut[1].m_pMemory - v17 - 1;
      convexOut[1].m_nAllocationCount = (int)convexOut->m_pMemory;
      if ( v20 > 0 )
        _V_memmove(dest: &v19[v17 + 1], src: &v19[v17], count: 4 * v20);
      v21 = (struct CPhysConvex **)&convexOut->m_pMemory[v17];
      if ( v21 != nullptr )
        *v21 = v16;
    }
    goto LABEL_21;
  }
LABEL_23:
  if ( vertsThisConvex.m_Memory.m_nGrowSize >= 0 && v7 != nullptr )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v7);
    return bValid;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00404210
// Name: void CCmd_JointMerge(class CJointedModel __near &,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CCmd_JointMerge(CJointedModel *joints, const char *pParent, const char *pChild)
{
  CJointedModel::AddMergeCommand(this: joints, pParent, pChild);
  CCollisionModelSource::MergeBones(this: joints, parent: pParent, child: pChild);
}

//------------------------------------------------------------------------------
// Address: 0x00404240
// Name: void ParseCollisionCommands(class CJointedModel __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ParseCollisionCommands(CJointedModel *joints)
{
  int v1; // eax
  char v2; // cl
  int v3; // esi
  unsigned __int8 *v4; // edi
  int v5; // esi
  unsigned __int8 *v6; // edi
  int v7; // esi
  unsigned __int8 *v8; // edi
  int v9; // esi
  unsigned __int8 *v10; // edi
  char *p_pFriction; // esi
  CPhysCollisionModel *v12; // eax
  CPhysCollisionModel *v13; // eax
  CPhysCollisionModel *v14; // eax
  CPhysCollisionModel *inited; // eax
  char dest[256]; // [esp+0h] [ebp-1214h] BYREF
  char pChild[256]; // [esp+100h] [ebp-1114h] BYREF
  char nptr[256]; // [esp+200h] [ebp-1014h] BYREF
  char pLimitMin[256]; // [esp+300h] [ebp-F14h] BYREF
  char pLimitMax[256]; // [esp+400h] [ebp-E14h] BYREF
  char pFriction; // [esp+500h] [ebp-D14h] BYREF
  char s1[512]; // [esp+1000h] [ebp-214h] BYREF
  Vector centerOfMass; // [esp+1200h] [ebp-14h] BYREF
  float v24; // [esp+120Ch] [ebp-8h]
  float v25; // [esp+1210h] [ebp-4h]

  while ( GetToken(crossline: 1) != 0 )
  {
    if ( strcmp(token, "}") == 0 )
      break;
    v1 = 0;
    do
    {
      v2 = token[v1];
      s1[v1++] = v2;
    }
    while ( v2 != 0 );
    if ( _V_stricmp(s1, s2: "$mass") != 0 )
    {
      if ( _V_stricmp(s1, s2: "$automass") != 0 )
      {
        if ( _V_stricmp(s1, s2: "$inertia") != 0 )
        {
          if ( _V_stricmp(s1, s2: "$damping") != 0 )
          {
            if ( _V_stricmp(s1, s2: "$rotdamping") != 0 )
            {
              if ( _V_stricmp(s1, s2: "$drag") != 0 )
              {
                if ( _V_stricmp(s1, s2: "$rollingDrag") != 0 )
                {
                  if ( _V_stricmp(s1, s2: "$maxconvexpieces") != 0 )
                  {
                    if ( _V_stricmp(s1, s2: "$remove2d") != 0 )
                    {
                      if ( _V_stricmp(s1, s2: "$concaveperjoint") != 0 )
                      {
                        if ( _V_stricmp(s1, s2: "$weldposition") != 0 )
                        {
                          if ( _V_stricmp(s1, s2: "$weldnormal") != 0 )
                          {
                            if ( _V_stricmp(s1, s2: "$concave") != 0 )
                            {
                              if ( _V_stricmp(s1, s2: "$masscenter") != 0 )
                              {
                                if ( _V_stricmp(s1, s2: "$jointskip") != 0 )
                                {
                                  if ( _V_stricmp(s1, s2: "$jointmerge") != 0 )
                                  {
                                    if ( _V_stricmp(s1, s2: "$rootbone") != 0 )
                                    {
                                      if ( _V_stricmp(s1, s2: "$jointconstrain") != 0 )
                                      {
                                        if ( _V_stricmp(s1, s2: "$jointinertia") != 0 )
                                        {
                                          if ( _V_stricmp(s1, s2: "$jointdamping") != 0 )
                                          {
                                            if ( _V_stricmp(s1, s2: "$jointrotdamping") != 0 )
                                            {
                                              if ( _V_stricmp(s1, s2: "$jointmassbias") != 0 )
                                              {
                                                if ( _V_stricmp(s1, s2: "$noselfcollisions") != 0 )
                                                {
                                                  if ( _V_stricmp(s1, s2: "$jointcollide") != 0 )
                                                  {
                                                    if ( _V_stricmp(s1, s2: "$animatedfriction") != 0 )
                                                    {
                                                      if ( _V_stricmp(s1, s2: "$assumeworldspace") != 0 )
                                                        MdlWarning(fmt: "Unknown command %s in collision series\n", s1);
                                                      else
                                                        joints->m_bAssumeWorldspace = true;
                                                    }
                                                    else if ( ReadArgs(pArgs: (char (*)[256])dest, maxCount: 5) == 5 )
                                                    {
                                                      CCmd_JoinAnimatedFriction(
                                                        joints,
                                                        pMinFriction: dest,
                                                        pMaxFriction: pChild,
                                                        pTimeIn: nptr,
                                                        pTimeHold: pLimitMin,
                                                        pTimeOut: pLimitMax);
                                                    }
                                                  }
                                                  else
                                                  {
                                                    ReadArgs(pArgs: (char (*)[256])dest, maxCount: 2);
                                                    CJointedModel::AppendCollisionPair(
                                                      this: joints,
                                                      pName0: dest,
                                                      pName1: pChild);
                                                  }
                                                }
                                                else
                                                {
                                                  joints->m_noSelfCollisions = true;
                                                }
                                              }
                                              else
                                              {
                                                ReadArgs(pArgs: (char (*)[256])dest, maxCount: 2);
                                                v25 = atof(nptr: pChild);
                                                inited = CJointedModel::InitCollisionModel(
                                                           this: joints,
                                                           pJointName: dest);
                                                if ( inited != nullptr )
                                                  inited->m_massBias = v25;
                                              }
                                            }
                                            else
                                            {
                                              ReadArgs(pArgs: (char (*)[256])dest, maxCount: 2);
                                              v25 = atof(nptr: pChild);
                                              v14 = CJointedModel::InitCollisionModel(this: joints, pJointName: dest);
                                              if ( v14 != nullptr )
                                                v14->m_rotdamping = v25;
                                            }
                                          }
                                          else
                                          {
                                            ReadArgs(pArgs: (char (*)[256])dest, maxCount: 2);
                                            v25 = atof(nptr: pChild);
                                            v13 = CJointedModel::InitCollisionModel(this: joints, pJointName: dest);
                                            if ( v13 != nullptr )
                                              v13->m_damping = v25;
                                          }
                                        }
                                        else
                                        {
                                          ReadArgs(pArgs: (char (*)[256])dest, maxCount: 2);
                                          v25 = atof(nptr: pChild);
                                          v12 = CJointedModel::InitCollisionModel(this: joints, pJointName: dest);
                                          if ( v12 != nullptr )
                                            v12->m_inertia = v25;
                                        }
                                      }
                                      else
                                      {
                                        p_pFriction = &pFriction;
                                        if ( ReadArgs(pArgs: (char (*)[256])dest, maxCount: 6) < 6 )
                                          p_pFriction = "1.0";
                                        CCmd_JointConstrain(
                                          joints,
                                          pJointName: dest,
                                          pJointAxis: pChild,
                                          pJointType: nptr,
                                          pLimitMin,
                                          pLimitMax,
                                          pFriction: p_pFriction);
                                      }
                                    }
                                    else
                                    {
                                      ReadArgs(pArgs: (char (*)[256])dest, maxCount: 1);
                                      CCmd_JointRoot(joints, pBone: dest);
                                    }
                                  }
                                  else
                                  {
                                    ReadArgs(pArgs: (char (*)[256])dest, maxCount: 2);
                                    CCmd_JointMerge(joints, pParent: dest, pChild);
                                  }
                                }
                                else
                                {
                                  ReadArgs(pArgs: (char (*)[256])dest, maxCount: 1);
                                  CCmd_JointSkip(joints, pName: dest);
                                }
                              }
                              else
                              {
                                ReadArgs(pArgs: (char (*)[256])dest, maxCount: 3);
                                v25 = atof(nptr);
                                v24 = atof(nptr: pChild);
                                centerOfMass.x = atof(nptr: dest);
                                centerOfMass.y = v24;
                                centerOfMass.z = v25;
                                CJointedModel::ForceMassCenter(this: joints, &centerOfMass);
                              }
                            }
                            else
                            {
                              joints->m_allowConcave = true;
                            }
                          }
                          else
                          {
                            ReadArgs(pArgs: (char (*)[256])dest, maxCount: 1);
                            g_WeldNormalEpsilon = atof(nptr: dest);
                          }
                        }
                        else
                        {
                          ReadArgs(pArgs: (char (*)[256])dest, maxCount: 1);
                          g_WeldVertEpsilon = atof(nptr: dest);
                        }
                      }
                      else
                      {
                        joints->m_allowConcaveJoints = true;
                      }
                    }
                    else
                    {
                      joints->m_remove2d = true;
                    }
                  }
                  else
                  {
                    ReadArgs(pArgs: (char (*)[256])dest, maxCount: 1);
                    joints->m_maxConvex = atoi(nptr: dest);
                  }
                }
                else
                {
                  ReadArgs(pArgs: (char (*)[256])dest, maxCount: 1);
                }
              }
              else
              {
                ReadArgs(pArgs: (char (*)[256])dest, maxCount: 1);
                joints->m_defaultDrag = atof(nptr: dest);
              }
            }
            else
            {
              v9 = 0;
              v10 = (unsigned __int8 *)dest;
              do
              {
                if ( TokenAvailable() == 0 )
                  break;
                GetToken(crossline: 0);
                strncpy(dest: v10, source: (unsigned __int8 *)token, count: 0x100u);
                ++v9;
                v10 += 256;
              }
              while ( v9 < 1 );
              joints->m_defaultRotdamping = atof(nptr: dest);
            }
          }
          else
          {
            v7 = 0;
            v8 = (unsigned __int8 *)dest;
            do
            {
              if ( TokenAvailable() == 0 )
                break;
              GetToken(crossline: 0);
              strncpy(dest: v8, source: (unsigned __int8 *)token, count: 0x100u);
              ++v7;
              v8 += 256;
            }
            while ( v7 < 1 );
            joints->m_defaultDamping = atof(nptr: dest);
          }
        }
        else
        {
          v5 = 0;
          v6 = (unsigned __int8 *)dest;
          do
          {
            if ( TokenAvailable() == 0 )
              break;
            GetToken(crossline: 0);
            strncpy(dest: v6, source: (unsigned __int8 *)token, count: 0x100u);
            ++v5;
            v6 += 256;
          }
          while ( v5 < 1 );
          joints->m_defaultInertia = atof(nptr: dest);
        }
      }
      else
      {
        joints->m_totalMass = -1.0;
      }
    }
    else
    {
      v3 = 0;
      v4 = (unsigned __int8 *)dest;
      do
      {
        if ( TokenAvailable() == 0 )
          break;
        GetToken(crossline: 0);
        strncpy(dest: v4, source: (unsigned __int8 *)token, count: 0x100u);
        ++v3;
        v4 += 256;
      }
      while ( v3 < 1 );
      joints->m_totalMass = atof(nptr: dest);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404A50
// Name: void Cmd_CollisionText(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Cmd_CollisionText()
{
  int v0; // ebx
  int m_Size; // eax
  int v2; // edi
  int v3; // esi
  char *m_pMemory; // ecx
  int v5; // eax
  char *v6; // eax

  v0 = 1;
  if ( GetToken(crossline: 1) != 0 && token[0] == 123 && GetToken(crossline: 1) != 0 )
  {
    do
    {
      if ( strcmp(token, "}") == 0 )
      {
        if ( --v0 <= 0 )
          return;
        m_Size = g_JointedModel.m_textCommands.m_Size;
        v2 = g_JointedModel.m_textCommands.m_Size;
        v3 = g_JointedModel.m_textCommands.m_Size;
        if ( g_JointedModel.m_textCommands.m_Size + 3 > g_JointedModel.m_textCommands.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<char,int>::Grow(
            this: (CUtlMemory<unsigned char,int> *)&g_JointedModel.m_textCommands,
            num: g_JointedModel.m_textCommands.m_Size - g_JointedModel.m_textCommands.m_Memory.m_nAllocationCount + 3);
          m_Size = g_JointedModel.m_textCommands.m_Size;
        }
        m_pMemory = g_JointedModel.m_textCommands.m_Memory.m_pMemory;
        g_JointedModel.m_textCommands.m_Size = m_Size + 3;
        v5 = m_Size - v3;
        g_JointedModel.m_textCommands.m_pElements = g_JointedModel.m_textCommands.m_Memory.m_pMemory;
        if ( v5 > 0 )
        {
          _V_memmove(
            dest: &g_JointedModel.m_textCommands.m_Memory.m_pMemory[v3 + 3],
            src: &g_JointedModel.m_textCommands.m_Memory.m_pMemory[v3],
            count: v5);
          m_pMemory = g_JointedModel.m_textCommands.m_Memory.m_pMemory;
        }
        v6 = &m_pMemory[v2];
        *(_WORD *)v6 = *(_WORD *)asc_5F8320;
        v6[2] = 10;
      }
      else if ( strcmp(token, "{") == 0 )
      {
        CJointedModel::AddText(this: &g_JointedModel, pText: "{");
        ++v0;
      }
      else if ( v0 <= 1 )
      {
        CJointedModel::AddText(this: &g_JointedModel, pText: token);
        CJointedModel::AddText(this: &g_JointedModel, pText: " ");
      }
      else
      {
        CJointedModel::AddText(this: &g_JointedModel, pText: "\"");
        CJointedModel::AddText(this: &g_JointedModel, pText: token);
        CJointedModel::AddText(this: &g_JointedModel, pText: "\" ");
      }
    }
    while ( GetToken(crossline: 1) != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404BF0
// Name: int DoCollisionModel(bool)
// Source: json
//------------------------------------------------------------------------------
int __usercall DoCollisionModel@<eax>(int a1@<ebx>, bool separateJoints)
{
  int result; // eax
  struct CSysModule *Module; // eax
  int (__stdcall *v4)(const char *, _DWORD); // esi
  int v5; // edi
  int v6; // ebx
  int v7; // esi
  char name[512]; // [esp+0h] [ebp-200h] BYREF

  result = GetToken(crossline: 0);
  if ( result != 0 )
  {
    strncpy(dest: (unsigned __int8 *)name, source: (unsigned __int8 *)token, count: 0x200u);
    PhysicsDLLPath(pPathname: "VPHYSICS.DLL");
    Module = Sys_LoadModule(pModuleName: "vphysics.dll");
    result = (int)Sys_GetFactory(pModule: Module);
    v4 = (int (__stdcall *)(const char *, _DWORD))result;
    if ( result != 0 )
    {
      physcollision = (IPhysicsCollision *)((int (__stdcall *)(const char *))result)(a1: "VPhysicsCollision007");
      physprops = (IPhysicsSurfaceProps *)v4(a1: "VPhysicsSurfaceProps001", a2: 0);
      LoadSurfacePropsAll(a1);
      v5 = g_nummaterials;
      v6 = g_numtextures;
      result = (int)Load_Source(name, ext: "SMD", reverse: false, isActiveModel: false);
      v7 = result;
      if ( result != 0 )
      {
        if ( v5 != 0 && v6 != 0 && (v6 != g_numtextures || v5 != g_nummaterials) )
        {
          g_numtextures = v6;
          g_nummaterials = v5;
          *(_DWORD *)(result + 200972) = 0;
        }
        g_JointedModel.m_pModel = (s_source_t *)result;
        CCollisionModelSource::InitBoneMap(this: &g_JointedModel);
        g_JointedModel.m_totalVerts = *(_DWORD *)(v7 + 202128);
        if ( GetToken(crossline: 1) != 0 )
        {
          if ( strcmp(token, "{") != 0 )
          {
            UnGetToken();
            g_JointedModel.m_isJointed = separateJoints;
            return 1;
          }
          ParseCollisionCommands(joints: &g_JointedModel);
        }
        g_JointedModel.m_isJointed = separateJoints;
        return 1;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00404D80
// Name: void ParseCollisionCommands(class CJointedModel __near &,class CDmeCollisionModel __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ParseCollisionCommands(CJointedModel *joints, CDmeCollisionModel *pCollisionModel, bool bStaticProp)
{
  float m_Storage; // xmm0_4
  float v4; // xmm0_4
  CDmeCollisionModel *v5; // ebx
  const char *m_pAttribute; // eax
  char *v7; // edx
  char v8; // cl
  CDmeJointAnimatedFriction *v9; // eax
  const char *v10; // edi
  int LocalBoneNamed; // eax
  int v12; // eax
  float *v13; // edi
  int v14; // eax
  CPhysCollisionModel *inited; // eax
  CPhysCollisionModel *v16; // eax
  CPhysCollisionModel *v17; // eax
  CPhysCollisionModel *v18; // eax
  CDmeJointConstrain *v19; // eax
  CDmeJointConstrain *v20; // eax
  CDmeJointConstrain *v21; // eax
  collisionpair_t *v22; // ebx
  int v23; // eax
  s_node_t *v24; // eax
  int v25; // eax
  s_node_t *v26; // eax
  CDmeCollisionJoints *pCollisionJoints; // [esp+1Ch] [ebp-24h]
  s_node_t *pJointName; // [esp+20h] [ebp-20h]
  float v29; // [esp+24h] [ebp-1Ch]
  float v30; // [esp+28h] [ebp-18h]
  float v31; // [esp+2Ch] [ebp-14h]
  float v32; // [esp+30h] [ebp-10h]
  int nValidCollisionJointCount; // [esp+34h] [ebp-Ch]
  int j; // [esp+38h] [ebp-8h]
  int ja; // [esp+38h] [ebp-8h]
  char *pName; // [esp+3Ch] [ebp-4h]
  char *pNamea; // [esp+3Ch] [ebp-4h]
  char *pNameb; // [esp+3Ch] [ebp-4h]
  int i; // [esp+4Ch] [ebp+Ch]
  int ia; // [esp+4Ch] [ebp+Ch]

  g_JointedModel.m_isJointed = false;
  if ( pCollisionModel != nullptr )
  {
    if ( pCollisionModel->m_bAutomaticMassComputation.m_Storage )
      joints->m_totalMass = -1.0;
    else
      joints->m_totalMass = pCollisionModel->m_flMass.m_Storage;
    joints->m_defaultInertia = pCollisionModel->m_flInertia.m_Storage;
    joints->m_defaultDamping = pCollisionModel->m_flDamping.m_Storage;
    joints->m_defaultRotdamping = pCollisionModel->m_flRotationalDamping.m_Storage;
    joints->m_defaultDrag = pCollisionModel->m_flDrag.m_Storage;
    joints->m_maxConvex = pCollisionModel->m_nMaxConvexPieces.m_Storage;
    if ( pCollisionModel->m_bRemove2D.m_Storage )
      joints->m_remove2d = true;
    m_Storage = pCollisionModel->m_flWeldPositionTolerance.m_Storage;
    if ( m_Storage >= 0.0 )
      g_WeldVertEpsilon = pCollisionModel->m_flWeldPositionTolerance.m_Storage;
    else
      MdlWarning(
        fmt: "1003: Invalid negative weld position tolerance (%f), ignoring and using %f\n",
        m_Storage,
        g_WeldVertEpsilon);
    v4 = pCollisionModel->m_flWeldNormalTolerance.m_Storage;
    if ( v4 >= 0.0 )
    {
      if ( v4 <= g_WeldNormalEpsilon )
        g_WeldNormalEpsilon = pCollisionModel->m_flWeldNormalTolerance.m_Storage;
      else
        MdlWarning(
          fmt: "1005: Weld normal tolerance too high (%f), should be slightly less than 1, ignoring and using %f\n",
          v4,
          g_WeldNormalEpsilon);
    }
    else
    {
      MdlWarning(
        fmt: "1004: Invalid negative weld normal tolerance (%f), ignoring and using %f\n",
        v4,
        g_WeldNormalEpsilon);
    }
    if ( pCollisionModel->m_bConcave.m_Storage )
      joints->m_allowConcave = true;
    if ( pCollisionModel->m_bForceMassCenter.m_Storage )
    {
      joints->m_isMassCenterForced = true;
      joints->m_massCenterForced = pCollisionModel->m_vecMassCenter.m_Storage;
    }
    joints->m_bAssumeWorldspace = pCollisionModel->m_bAssumeWorldSpace.m_Storage;
    v5 = ((int (__thiscall *)(_DWORD, _DWORD))pCollisionModel->IsA)(
           a1: pCollisionModel,
           a2: (CUtlSymbolLarge)CDmeCollisionJoints::m_classType.u.m_Id)
       ? pCollisionModel
       : nullptr;
    pCollisionJoints = (CDmeCollisionJoints *)v5;
    if ( !bStaticProp && v5 != nullptr )
    {
      if ( LOBYTE(v5[1].__vftable) != 0 )
        joints->m_allowConcaveJoints = true;
      if ( v5[1].m_Id.m_Value[4] == 0 )
      {
        joints->m_noSelfCollisions = true;
        if ( v5[1].m_Id.m_Value[4] == 0 )
          joints->m_noSelfCollisions = true;
      }
      m_pAttribute = (const char *)v5[1].m_Name.m_pAttribute;
      if ( m_pAttribute == (const char *)-1 )
        m_pAttribute = pDeltaStateName;
      v7 = (char *)((char *)joints - m_pAttribute);
      do
      {
        v8 = *m_pAttribute;
        v7[(_DWORD)m_pAttribute + 36] = *m_pAttribute;
        ++m_pAttribute;
      }
      while ( v8 != 0 );
      v9 = (CDmeJointAnimatedFriction *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                          a1: g_pDataModel.u,
                                          a2: *((_DWORD *)&v5[1].m_ref + 1));
      CCmd_JoinAnimatedFriction(joints, pJaf: v9);
      for ( i = 0; i < v5[1].m_fileId; ++i )
      {
        v10 = pDeltaStateName;
        if ( *((_DWORD *)&v5[1].m_ref.m_attributes.m_pNext->m_hAttribute + i) != -1 )
          v10 = *((const char **)&v5[1].m_ref.m_attributes.m_pNext->m_hAttribute + i);
        LocalBoneNamed = CCollisionModelSource::FindLocalBoneNamed(this: joints, pName: v10);
        if ( LocalBoneNamed >= 0 )
          CCollisionModelSource::SkipBone(this: joints, boneIndex: LocalBoneNamed);
        else
          MdlWarning(fmt: "Can't skip joint %s, not found\n", v10);
      }
      nValidCollisionJointCount = 0;
      ia = 0;
      if ( (int)v5[1].m_bAutomaticMassComputation.m_pAttribute <= 0 )
        goto LABEL_72;
      do
      {
        v12 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                a1: g_pDataModel.u,
                a2: *(_DWORD *)(LODWORD(v5[1].m_flMass.m_Storage) + 4 * ia));
        v13 = (float *)v12;
        if ( v12 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v12 + 16))(
               a1: v12,
               a2: CDmeCollisionJoint::m_classType.u) != 0 )
        {
          pName = (char *)pDeltaStateName;
          if ( *((_DWORD *)v13 + 5) != -1 )
            pName = *((char **)v13 + 5);
          v14 = FindLocalBoneNamed(pSource: joints->m_pModel, pName);
          if ( g_bCreateMakefile || v14 >= 0 )
          {
            pJointName = &joints->m_pModel->localBone[v14];
            v32 = v13[17];
            inited = CJointedModel::InitCollisionModel(this: joints, pJointName: pJointName->name);
            if ( inited != nullptr )
              inited->m_massBias = v32;
            v31 = v13[23];
            v16 = CJointedModel::InitCollisionModel(this: joints, pJointName: pJointName->name);
            if ( v16 != nullptr )
              v16->m_inertia = v31;
            v30 = v13[19];
            v17 = CJointedModel::InitCollisionModel(this: joints, pJointName: pJointName->name);
            if ( v17 != nullptr )
              v17->m_damping = v30;
            v29 = v13[21];
            v18 = CJointedModel::InitCollisionModel(this: joints, pJointName: pJointName->name);
            if ( v18 != nullptr )
              v18->m_rotdamping = v29;
            v19 = (CDmeJointConstrain *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                          a1: g_pDataModel.u,
                                          a2: *((_DWORD *)v13 + 25));
            CCmd_JointConstrain(joints, nAxis: 0, pJointName: pJointName->name, pJointConstrain: v19);
            v20 = (CDmeJointConstrain *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                          a1: g_pDataModel.u,
                                          a2: *((_DWORD *)v13 + 28));
            CCmd_JointConstrain(joints, nAxis: 1u, pJointName: pJointName->name, pJointConstrain: v20);
            v21 = (CDmeJointConstrain *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                          a1: g_pDataModel.u,
                                          a2: *((_DWORD *)v13 + 31));
            CCmd_JointConstrain(joints, nAxis: 2u, pJointName: pJointName->name, pJointConstrain: v21);
            for ( j = 0; j < *((_DWORD *)v13 + 37); ++j )
            {
              pNamea = (char *)pDeltaStateName;
              if ( *(_DWORD *)(*((_DWORD *)v13 + 34) + 4 * j) != -1 )
                pNamea = *(char **)(*((_DWORD *)v13 + 34) + 4 * j);
              CJointedModel::AddMergeCommand(this: joints, pParent: pJointName->name, pChild: pNamea);
              CCollisionModelSource::MergeBones(this: joints, parent: pJointName->name, child: pNamea);
            }
            for ( ja = 0; ja < *((_DWORD *)v13 + 37); ++ja )
            {
              pNameb = (char *)pDeltaStateName;
              if ( *(_DWORD *)(*((_DWORD *)v13 + 40) + 4 * ja) != -1 )
                pNameb = *(char **)(*((_DWORD *)v13 + 40) + 4 * ja);
              v22 = (collisionpair_t *)MemAlloc_Alloc(nSize: 0x14u);
              v22->obj0 = -1;
              v22->obj1 = -1;
              v23 = CCollisionModelSource::FindLocalBoneNamed(this: joints, pName: pJointName->name);
              if ( v23 < 0 )
                v24 = nullptr;
              else
                v24 = &joints->m_pModel->localBone[v23];
              v22->pName0 = (const char *)v24;
              v25 = CCollisionModelSource::FindLocalBoneNamed(this: joints, pName: pNameb);
              if ( v25 < 0 )
                v26 = nullptr;
              else
                v26 = &joints->m_pModel->localBone[v25];
              v22->pName1 = (const char *)v26;
              v22->pNext = joints->m_pCollisionPairs;
              joints->m_pCollisionPairs = v22;
            }
            ++nValidCollisionJointCount;
            v5 = pCollisionJoints;
          }
          else
          {
            MdlWarning(
              fmt: "1001: root.collisionModel.joints[ %d ] refers to joint \"%s\" but that joint wasn't defined in the model\n",
              ia,
              pName);
          }
        }
        else
        {
          MdlWarning(fmt: "1000: root.collisionModel.joints[ %d ] exists but undefined\n", ia);
        }
        ++ia;
      }
      while ( ia < (int)v5[1].m_bAutomaticMassComputation.m_pAttribute );
      if ( nValidCollisionJointCount <= 0 )
LABEL_72:
        MdlWarning(fmt: "1002: Jointed collision model defined but no valid CDmeCollisionJoints, making non-jointed\n");
      else
        g_JointedModel.m_isJointed = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004052E0
// Name: int DoCollisionModel(struct s_source_t __near *,class CDmElement __near *,bool)
// Source: json
//------------------------------------------------------------------------------
int __usercall DoCollisionModel@<eax>(int a1@<ebx>, s_source_t *pSource, CDmeCollisionModel *pInfo, bool bStaticProp)
{
  void *(__cdecl *PhysicsFactory)(const char *, int *); // eax
  void *(__cdecl *v6)(const char *, int *); // esi

  if ( pInfo == nullptr )
    return 0;
  if ( !((int (__thiscall *)(_DWORD, _DWORD))pInfo->IsA)(
          a1: pInfo,
          a2: (CUtlSymbolLarge)CDmeCollisionModel::m_classType.u.m_Id) )
    return 0;
  PhysicsDLLPath(pPathname: "VPHYSICS.DLL");
  PhysicsFactory = GetPhysicsFactory();
  v6 = PhysicsFactory;
  if ( PhysicsFactory == nullptr )
    return 0;
  physcollision = (IPhysicsCollision *)PhysicsFactory(a1: "VPhysicsCollision007", a2: nullptr);
  physprops = (IPhysicsSurfaceProps *)v6(a1: "VPhysicsSurfaceProps001", a2: nullptr);
  LoadSurfacePropsAll(a1);
  g_JointedModel.m_pModel = pSource;
  CCollisionModelSource::InitBoneMap(this: &g_JointedModel);
  g_JointedModel.m_totalVerts = pSource->numvertices;
  ParseCollisionCommands(joints: &g_JointedModel, pCollisionModel: pInfo, bStaticProp);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00405380
// Name: void LoadCollisionText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoadCollisionText(const char *pszKeyValues)
{
  KeyValues *v1; // eax
  KeyValues *v2; // eax
  KeyValues *NextKey; // edi
  KeyValues *v4; // ebx
  char *Name; // eax
  KeyValues *i; // esi
  char *v7; // eax
  char *String; // eax

  if ( pszKeyValues != nullptr )
  {
    v1 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v1 != nullptr )
    {
      v2 = KeyValues::KeyValues(this: v1, setName: "collisionText");
      NextKey = v2;
      if ( v2 != nullptr )
      {
        v4 = v2;
        KeyValues::UsesEscapeSequences(this: v2, state: true);
        if ( KeyValues::LoadFromBuffer(
               this: NextKey,
               resourceName: "collisionText",
               pBuffer: pszKeyValues,
               pFileSystem: nullptr,
               pPathID: nullptr,
               pfnEvaluateSymbolProc: nullptr) )
        {
          do
          {
            Name = (char *)KeyValues::GetName(this: NextKey);
            CJointedModel::AddText(this: &g_JointedModel, pText: Name);
            CJointedModel::AddText(this: &g_JointedModel, pText: " {");
            for ( i = KeyValues::GetFirstValue(this: NextKey); i != nullptr; i = KeyValues::GetNextValue(this: i) )
            {
              CJointedModel::AddText(this: &g_JointedModel, pText: " \"");
              v7 = (char *)KeyValues::GetName(this: i);
              CJointedModel::AddText(this: &g_JointedModel, pText: v7);
              CJointedModel::AddText(this: &g_JointedModel, pText: "\" \"");
              String = (char *)KeyValues::GetString(this: i, keyName: nullptr, defaultValue: pDeltaStateName);
              CJointedModel::AddText(this: &g_JointedModel, pText: String);
              CJointedModel::AddText(this: &g_JointedModel, pText: "\"");
            }
            CJointedModel::AddText(this: &g_JointedModel, pText: asc_5F8320);
            NextKey = KeyValues::GetNextKey(this: NextKey);
          }
          while ( NextKey != nullptr );
        }
        KeyValues::deleteThis(this: v4);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004054D0
// Name: void BuildSingleConvexForFaceList(struct s_source_t __near *,class CUtlVector<struct convexlist_t,class CUtlMemory<struct convexlist_t,int>> __near &,class CUtlVector<int,class CUtlMemory<int,int>> __near &,class CUtlVector<struct s_face_t,class CUtlMemory<struct s_face_t,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildSingleConvexForFaceList(
        s_source_t *pmodel,
        CUtlMemory<CDmeMesh::FaceSet_t,int> *convexList,
        CUtlVector<int,CUtlMemory<int,int> > *vertList,
        const CUtlVector<s_face_t,CUtlMemory<s_face_t,int> > *faceList)
{
  s_source_t *v4; // ebx
  int *m_pMemory; // esi
  int i; // eax
  int v7; // ecx
  int v8; // edx
  s_face_t *v9; // eax
  int numvertices; // [esp-4h] [ebp-24h]
  CUtlVector<int,CUtlMemory<int,int> > vertID; // [esp+Ch] [ebp-14h] BYREF

  v4 = pmodel;
  numvertices = pmodel->numvertices;
  memset(&vertID, 0, sizeof(vertID));
  CUtlVector<s_bone_t *,CUtlMemory<s_bone_t *,int>>::InsertMultipleBefore(
    this: (CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int> > *)&vertID,
    elem: 0,
    num: numvertices);
  m_pMemory = vertID.m_Memory.m_pMemory;
  for ( i = 0; i < pmodel->numvertices; ++i )
    m_pMemory[i] = -1;
  v7 = 0;
  if ( faceList->m_Size > 0 )
  {
    v8 = 0;
    do
    {
      v9 = faceList->m_Memory.m_pMemory;
      m_pMemory[faceList->m_Memory.m_pMemory[v8].a] = 1;
      m_pMemory[v9[v8].b] = 1;
      ++v7;
      m_pMemory[v9[v8++].c] = 1;
    }
    while ( v7 < faceList->m_Size );
    v4 = pmodel;
  }
  BuildConvexListByVertID(pmodel: v4, convexList, vertList, &vertID);
  if ( vertID.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x004055A0
// Name: void BuildConvexListForFaceList(struct s_source_t __near *,class CUtlVector<struct convexlist_t,class CUtlMemory<struct convexlist_t,int>> __near &,class CUtlVector<int,class CUtlMemory<int,int>> __near &,class CUtlVector<struct s_face_t,class CUtlMemory<struct s_face_t,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildConvexListForFaceList(
        s_source_t *pmodel,
        CUtlMemory<CDmeMesh::FaceSet_t,int> *convexList,
        CUtlVector<int,CUtlMemory<int,int> > *vertList,
        const CUtlVector<s_face_t,CUtlMemory<s_face_t,int> > *faceList)
{
  s_source_t *v4; // edi
  int *m_pMemory; // ebx
  int v6; // ecx
  int *v7; // esi
  int v8; // edx
  int *v9; // eax
  const CUtlVector<s_face_t,CUtlMemory<s_face_t,int> > *v10; // eax
  _QWORD *v11; // eax
  int v12; // edx
  int v13; // edi
  int v14; // eax
  int v15; // ecx
  int numvertices; // [esp-4h] [ebp-54h]
  int v17; // [esp-4h] [ebp-54h]
  CUtlVector<int,CUtlMemory<int,int> > vertID; // [esp+Ch] [ebp-44h] BYREF
  CUtlVector<int,CUtlMemory<int,int> > weldTable; // [esp+20h] [ebp-30h] BYREF
  s_face_t globalFace; // [esp+34h] [ebp-1Ch]
  int v21; // [esp+44h] [ebp-Ch]
  int i; // [esp+48h] [ebp-8h]
  int marked; // [esp+4Ch] [ebp-4h]

  v4 = pmodel;
  numvertices = pmodel->numvertices;
  memset(&weldTable, 0, sizeof(weldTable));
  CUtlVector<s_bone_t *,CUtlMemory<s_bone_t *,int>>::InsertMultipleBefore(
    this: (CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int> > *)&weldTable,
    elem: 0,
    num: numvertices);
  m_pMemory = weldTable.m_Memory.m_pMemory;
  BuildVertWeldTable(weldTable: weldTable.m_Memory.m_pMemory, pmodel);
  v17 = pmodel->numvertices;
  memset(&vertID, 0, sizeof(vertID));
  CUtlVector<s_bone_t *,CUtlMemory<s_bone_t *,int>>::InsertMultipleBefore(
    this: (CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int> > *)&vertID,
    elem: 0,
    num: v17);
  v6 = 0;
  v7 = vertID.m_Memory.m_pMemory;
  if ( pmodel->numvertices > 0 )
  {
    v8 = (char *)m_pMemory - (char *)vertID.m_Memory.m_pMemory;
    v9 = vertID.m_Memory.m_pMemory;
    v21 = (char *)m_pMemory - (char *)vertID.m_Memory.m_pMemory;
    do
    {
      if ( *(int *)((char *)v9 + v8) == v6 )
      {
        *v9 = pmodel->numfaces + 1;
        v8 = v21;
      }
      else
      {
        *v9 = -1;
      }
      ++v6;
      ++v9;
    }
    while ( v6 < pmodel->numvertices );
  }
  v10 = faceList;
  do
  {
    marked = 0;
    i = 0;
    if ( v10->m_Size <= 0 )
      break;
    v21 = 0;
    do
    {
      v11 = (_QWORD *)((char *)&v10->m_Memory.m_pMemory->a + v21);
      *(_QWORD *)&globalFace.a = *v11;
      v12 = m_pMemory[globalFace.a];
      v13 = m_pMemory[globalFace.b];
      *(_QWORD *)&globalFace.c = v11[1];
      v14 = i;
      globalFace.c = m_pMemory[globalFace.c];
      v15 = v7[v12];
      if ( i >= v15 )
        v14 = v7[v12];
      if ( v14 >= v7[v13] )
        v14 = v7[v13];
      if ( v14 >= v7[globalFace.c] )
        v14 = v7[globalFace.c];
      if ( v15 != v14 )
      {
        v7[v12] = v14;
        ++marked;
      }
      if ( v7[v13] != v14 )
      {
        ++marked;
        v7[v13] = v14;
      }
      if ( v7[globalFace.c] != v14 )
      {
        ++marked;
        v7[globalFace.c] = v14;
      }
      v10 = faceList;
      v21 += 16;
      m_pMemory = weldTable.m_Memory.m_pMemory;
      ++i;
    }
    while ( i < faceList->m_Size );
    v4 = pmodel;
  }
  while ( marked != 0 );
  BuildConvexListByVertID(pmodel: v4, convexList, vertList, &vertID);
  if ( vertID.m_Memory.m_nGrowSize >= 0 && v7 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v7);
  if ( weldTable.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00405750
// Name: public: int CJointedModel::ProcessJointedModel(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CJointedModel::ProcessJointedModel(CJointedModel *this)
{
  int v1; // esi
  s_source_t *m_pModel; // eax
  s_source_t *v4; // edx
  Vector *m_pMemory; // ecx
  int numvertices; // edi
  int m_Size; // eax
  s_source_t *v8; // ecx
  bool v9; // al
  CPhysCollisionModel *v10; // ecx
  s_mesh_t *v11; // esi
  s_face_t *v12; // eax
  int v13; // eax
  int v14; // edi
  int v15; // eax
  s_face_t *v16; // edi
  s_source_t *v17; // edx
  int v18; // edi
  int m; // esi
  int v20; // edi
  CPhysCollisionModel *inited; // eax
  int v22; // ecx
  s_source_t *v23; // edx
  int v24; // ecx
  int *p_numVertIndex; // edi
  int j; // esi
  int v27; // edi
  int k; // esi
  CPhysCollisionModel *v29; // esi
  CPhysCollisionModel **p_m_pCollisionList; // eax
  CPhysCollisionModel *v31; // ecx
  Vector *v32; // eax
  s_source_t *v33; // ecx
  CPhysCollisionModel *m_pCollisionList; // ecx
  CPhysCollisionModel *m_pNext; // edi
  CPhysCollisionModel **p_m_pNext; // eax
  CPhysCollisionModel *v37; // edx
  boundingvolume_t bv; // [esp+1Ch] [ebp-9Ch] BYREF
  s_face_t globalFace; // [esp+34h] [ebp-84h] BYREF
  CUtlVector<int,CUtlMemory<int,int> > vertList; // [esp+44h] [ebp-74h] BYREF
  CUtlVector<convexlist_t,CUtlMemory<convexlist_t,int> > convexList; // [esp+58h] [ebp-60h] BYREF
  CUtlVector<CPhysConvex *,CUtlMemory<CPhysConvex *,int> > convexOut; // [esp+6Ch] [ebp-4Ch] BYREF
  CUtlVector<s_face_t,CUtlMemory<s_face_t,int> > faceList; // [esp+80h] [ebp-38h] BYREF
  CUtlVector<Vector,CUtlMemory<Vector,int> > bonespaceVerts; // [esp+94h] [ebp-24h] BYREF
  CPhysCollisionModel *pPhys; // [esp+A8h] [ebp-10h]
  int i; // [esp+ACh] [ebp-Ch]
  int vertCount; // [esp+B0h] [ebp-8h]
  int boneIndex; // [esp+B4h] [ebp-4h]
  int savedregs; // [esp+B8h] [ebp+0h] BYREF

  v1 = 0;
  if ( !g_quiet )
    printf(format: "Processing jointed collision model\n");
  m_pModel = this->m_pModel;
  boneIndex = 0;
  if ( m_pModel->numbones > 0 )
  {
    while ( !CCollisionModelSource::ShouldProcessBone(this, boneIndex) )
    {
LABEL_76:
      v33 = this->m_pModel;
      v1 = 0;
      if ( ++boneIndex >= v33->numbones )
        goto LABEL_77;
    }
    v4 = this->m_pModel;
    m_pMemory = nullptr;
    memset(&bonespaceVerts, 0, sizeof(bonespaceVerts));
    numvertices = v4->numvertices;
    m_Size = 0;
    if ( numvertices != 0 )
    {
      if ( numvertices > 0 )
      {
        CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>::Grow(
          this: (CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int> *)&bonespaceVerts,
          num: numvertices);
        m_Size = bonespaceVerts.m_Size;
        m_pMemory = bonespaceVerts.m_Memory.m_pMemory;
      }
      bonespaceVerts.m_Size = numvertices + m_Size;
      bonespaceVerts.m_pElements = m_pMemory;
      if ( m_Size > 0 && numvertices > 0 )
        _V_memmove(dest: &m_pMemory[numvertices], src: m_pMemory, count: 12 * m_Size);
    }
    CCollisionModelSource::ConvertToBoneSpace(this, boneIndex, boneVerts: &bonespaceVerts);
    v8 = this->m_pModel;
    v9 = false;
    memset(&faceList, 0, sizeof(faceList));
    memset(&convexList, 0, sizeof(convexList));
    memset(&vertList, 0, sizeof(vertList));
    memset(&convexOut, 0, sizeof(convexOut));
    i = 0;
    if ( v8->nummeshes > 0 )
    {
      vertCount = 201488;
      do
      {
        v10 = nullptr;
        v11 = &this->m_pModel->mesh[*(_DWORD *)&this->m_pModel->filename[vertCount]];
        pPhys = nullptr;
        if ( v11->numfaces > 0 )
        {
          do
          {
            v12 = &this->m_pModel->face[(int)v10 + v11->faceoffset];
            memset(&globalFace, 255, sizeof(globalFace));
            GlobalFace(pout: &globalFace, pmesh: v11, pin: v12);
            if ( CCollisionModelSource::FaceHasVertOnBone(this, face: &globalFace, boneIndex) )
            {
              v13 = faceList.m_Size;
              v14 = faceList.m_Size;
              if ( faceList.m_Size + 1 > faceList.m_Memory.m_nAllocationCount )
              {
                CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
                  this: (CUtlMemory<ActiveLayer_t<CUtlSymbolLarge>,int> *)&faceList,
                  num: faceList.m_Size - faceList.m_Memory.m_nAllocationCount + 1);
                v13 = faceList.m_Size;
              }
              faceList.m_Size = v13 + 1;
              v15 = v13 - v14;
              faceList.m_pElements = faceList.m_Memory.m_pMemory;
              if ( v15 > 0 )
                _V_memmove(
                  dest: &faceList.m_Memory.m_pMemory[v14 + 1],
                  src: &faceList.m_Memory.m_pMemory[v14],
                  count: 16 * v15);
              v16 = &faceList.m_Memory.m_pMemory[v14];
              if ( v16 != nullptr )
                *v16 = globalFace;
            }
            v10 = (CPhysCollisionModel *)((char *)&pPhys->m_parent + 1);
            pPhys = v10;
          }
          while ( (int)v10 < v11->numfaces );
        }
        if ( this->m_allowConcaveJoints )
          BuildConvexListForFaceList(
            pmodel: this->m_pModel,
            (CUtlMemory<CDmeMesh::FaceSet_t,int> *)&convexList,
            &vertList,
            &faceList);
        else
          BuildSingleConvexForFaceList(
            pmodel: this->m_pModel,
            (CUtlMemory<CDmeMesh::FaceSet_t,int> *)&convexList,
            &vertList,
            &faceList);
        v9 = BuildConvexesForLists(
               (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&convexOut,
               &convexList,
               &vertList,
               worldspaceVerts: &bonespaceVerts,
               bRemove2d: this->m_remove2d);
        v17 = this->m_pModel;
        vertCount += 4;
        ++i;
      }
      while ( i < v17->nummeshes );
      v1 = convexList.m_Size;
    }
    v18 = convexOut.m_Size;
    if ( convexOut.m_Size <= this->m_maxConvex )
    {
      if ( v9 )
      {
        if ( convexOut.m_Size != 0 )
        {
          v20 = boneIndex;
          inited = CJointedModel::InitCollisionModel(this, pJointName: this->m_pModel->localBone[boneIndex].name);
          inited->m_mass = 1.0;
          v22 = 132 * (boneIndex + 3);
          inited->m_name = this->m_pModel->localBone[v20].name;
          v23 = this->m_pModel;
          v24 = *(_DWORD *)&this->m_pModel->filename[v22];
          pPhys = inited;
          if ( v24 < 0 )
            inited->m_parent = nullptr;
          else
            inited->m_parent = v23->localBone[v24].name;
          ClearBounds(mins: &bv.mins, maxs: &bv.maxs);
          vertCount = 0;
          if ( v1 > 0 )
          {
            p_numVertIndex = &convexList.m_Memory.m_pMemory->numVertIndex;
            for ( i = v1; i != 0; --i )
            {
              for ( j = 0; j < *p_numVertIndex; ++j )
              {
                AddPointToBounds(
                  v: &bonespaceVerts.m_Memory.m_pMemory[vertList.m_Memory.m_pMemory[j + *(p_numVertIndex - 1)]],
                  mins: &bv.mins,
                  maxs: &bv.maxs);
                ++vertCount;
              }
              p_numVertIndex += 2;
            }
          }
          v27 = convexOut.m_Size;
          for ( k = 0; k < convexOut.m_Size; ++k )
          {
            physcollision->SetConvexGameData(
              this: physcollision,
              a2: convexOut.m_Memory.m_pMemory[k],
              a3: this->m_pModel->boneLocalToGlobal[boneIndex] + 1);
            v27 = convexOut.m_Size;
          }
          v29 = pPhys;
          CreateCollide(
            a1: COERCE_FLOAT(&savedregs),
            pBase: pPhys,
            pElements: convexOut.m_Memory.m_pMemory,
            elementCount: v27,
            &bv);
          if ( !g_quiet )
            printf(
              format: "%-24s (%3d verts, %d convex elements) volume: %4.2f\n",
              v29->m_name,
              vertCount,
              v27,
              v29->m_volume);
          p_m_pCollisionList = &this->m_pCollisionList;
          if ( this->m_pCollisionList != nullptr )
          {
            while ( 1 )
            {
              v31 = *p_m_pCollisionList;
              if ( *p_m_pCollisionList == v29 )
                break;
              p_m_pCollisionList = &v31->m_pNext;
              if ( v31->m_pNext == nullptr )
                goto LABEL_54;
            }
            *p_m_pCollisionList = v29->m_pNext;
            --this->m_collisionCount;
            v29->m_pNext = nullptr;
          }
LABEL_54:
          if ( this->m_isMassCenterForced )
            physcollision->CollideSetMassCenter(
              this: physcollision,
              a2: v29->m_pCollisionData,
              a3: &this->m_massCenterForced);
          v29->m_pNext = this->m_pCollisionList;
          ++this->m_collisionCount;
          this->m_pCollisionList = v29;
        }
        goto LABEL_57;
      }
    }
    else
    {
      MdlWarning(fmt: "COSTLY COLLISION MODEL!!!! (%d parts - %d allowed)\n", convexOut.m_Size, this->m_maxConvex);
    }
    if ( v18 != 0 )
    {
      MdlWarning(fmt: "Error with convex elements of %s, building single convex!!!!\n", this->m_pModel->filename);
      for ( m = 0; m < v18; ++m )
        physcollision->ConvexFree(this: physcollision, a2: convexOut.m_Memory.m_pMemory[m]);
      if ( convexOut.m_Memory.m_nGrowSize >= 0 && convexOut.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: convexOut.m_Memory.m_pMemory);
        convexOut.m_Memory.m_pMemory = nullptr;
      }
    }
LABEL_57:
    if ( convexOut.m_Memory.m_nGrowSize >= 0 && convexOut.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: convexOut.m_Memory.m_pMemory);
    if ( vertList.m_Memory.m_nGrowSize >= 0 && vertList.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: vertList.m_Memory.m_pMemory);
    if ( convexList.m_Memory.m_nGrowSize >= 0 && convexList.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: convexList.m_Memory.m_pMemory);
    if ( faceList.m_Memory.m_nGrowSize >= 0 && faceList.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: faceList.m_Memory.m_pMemory);
    v32 = bonespaceVerts.m_Memory.m_pMemory;
    bonespaceVerts.m_Size = 0;
    if ( bonespaceVerts.m_Memory.m_nGrowSize >= 0 )
    {
      if ( bonespaceVerts.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bonespaceVerts.m_Memory.m_pMemory);
        v32 = nullptr;
        bonespaceVerts.m_Memory.m_pMemory = nullptr;
      }
      bonespaceVerts.m_Memory.m_nAllocationCount = 0;
    }
    bonespaceVerts.m_pElements = v32;
    if ( bonespaceVerts.m_Memory.m_nGrowSize >= 0 && v32 != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v32);
    goto LABEL_76;
  }
LABEL_77:
  m_pCollisionList = this->m_pCollisionList;
  if ( m_pCollisionList != nullptr )
  {
    do
    {
      m_pNext = m_pCollisionList->m_pNext;
      if ( m_pCollisionList->m_pCollisionData == nullptr )
      {
        p_m_pNext = &this->m_pCollisionList;
        if ( this->m_pCollisionList != nullptr )
        {
          while ( 1 )
          {
            v37 = *p_m_pNext;
            if ( *p_m_pNext == m_pCollisionList )
              break;
            p_m_pNext = &v37->m_pNext;
            if ( v37->m_pNext == nullptr )
              goto LABEL_84;
          }
          *p_m_pNext = m_pNext;
          --this->m_collisionCount;
          m_pCollisionList->m_pNext = nullptr;
        }
LABEL_84:
        free(pMem: m_pCollisionList);
      }
      m_pCollisionList = m_pNext;
    }
    while ( m_pNext != nullptr );
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00405D20
// Name: public: int CJointedModel::ProcessSingleBody(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CJointedModel::ProcessSingleBody(CJointedModel *this)
{
  int m_Size; // edi
  s_source_t *m_pModel; // esi
  int v4; // ebx
  int v5; // ecx
  bool v6; // al
  s_mesh_t *v7; // ebx
  bool v8; // cc
  s_face_t *v9; // edx
  int v10; // esi
  s_face_t *m_pMemory; // ecx
  s_face_t *v12; // esi
  int v13; // eax
  int v14; // ecx
  int v15; // ebx
  convexlist_t *v16; // eax
  int v17; // ebx
  int v18; // eax
  int *v19; // ebx
  unsigned __int8 *v20; // eax
  unsigned __int8 *v21; // ebx
  float *v22; // eax
  double v23; // st7
  int v24; // eax
  char *v25; // eax
  CJointedModel *v26; // esi
  Vector *v27; // eax
  int numvertices; // [esp-4h] [ebp-2A4h]
  char tmp[512]; // [esp+Ch] [ebp-294h] BYREF
  boundingvolume_t mins; // [esp+20Ch] [ebp-94h] BYREF
  s_source_t *pmodel; // [esp+228h] [ebp-78h]
  CUtlVector<s_face_t,CUtlMemory<s_face_t,int> > faceList; // [esp+22Ch] [ebp-74h] BYREF
  CUtlVector<convexlist_t,CUtlMemory<convexlist_t,int> > convexList; // [esp+240h] [ebp-60h] BYREF
  CUtlVector<Vector,CUtlMemory<Vector,int> > worldspaceVerts; // [esp+254h] [ebp-4Ch] BYREF
  int j; // [esp+268h] [ebp-38h]
  CUtlVector<int,CUtlMemory<int,int> > vertList; // [esp+26Ch] [ebp-34h] BYREF
  CUtlVector<CPhysConvex *,CUtlMemory<CPhysConvex *,int> > convexOut; // [esp+280h] [ebp-20h] BYREF
  CJointedModel *v39; // [esp+294h] [ebp-Ch]
  int i; // [esp+298h] [ebp-8h]
  int meshindex; // [esp+29Ch] [ebp-4h]
  int savedregs; // [esp+2A0h] [ebp+0h] BYREF

  m_Size = 0;
  m_pModel = this->m_pModel;
  memset(&worldspaceVerts, 0, sizeof(worldspaceVerts));
  numvertices = m_pModel->numvertices;
  v39 = this;
  pmodel = m_pModel;
  CUtlVector<QAngle,CUtlMemory<QAngle,int>>::InsertMultipleBefore(
    this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&worldspaceVerts,
    elem: 0,
    num: numvertices);
  CCollisionModelSource::ConvertToWorldSpace(this, worldVerts: &worldspaceVerts);
  v4 = 0;
  v5 = 0;
  v6 = false;
  memset(&faceList, 0, sizeof(faceList));
  memset(&convexList, 0, sizeof(convexList));
  memset(&vertList, 0, sizeof(vertList));
  memset(&convexOut, 0, sizeof(convexOut));
  if ( v39->m_allowConcave )
  {
    i = 0;
    if ( m_pModel->nummeshes > 0 )
    {
      meshindex = (int)m_pModel->meshindex;
      do
      {
        v7 = &m_pModel->mesh[*(_DWORD *)meshindex];
        v8 = v7->numfaces <= 0;
        j = 0;
        if ( !v8 )
        {
          do
          {
            v9 = &m_pModel->face[j + v7->faceoffset];
            memset(&mins.mins.z, 255, 16);
            GlobalFace(pout: (s_face_t *)&mins.mins.z, pmesh: v7, pin: v9);
            v10 = m_Size;
            if ( m_Size + 1 > faceList.m_Memory.m_nAllocationCount )
            {
              CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
                this: (CUtlMemory<ActiveLayer_t<CUtlSymbolLarge>,int> *)&faceList,
                num: m_Size - faceList.m_Memory.m_nAllocationCount + 1);
              m_Size = faceList.m_Size;
            }
            m_pMemory = faceList.m_Memory.m_pMemory;
            faceList.m_Size = ++m_Size;
            faceList.m_pElements = faceList.m_Memory.m_pMemory;
            if ( m_Size - v10 - 1 > 0 )
            {
              _V_memmove(
                dest: &faceList.m_Memory.m_pMemory[v10 + 1],
                src: &faceList.m_Memory.m_pMemory[v10],
                count: 16 * (m_Size - v10 - 1));
              m_pMemory = faceList.m_Memory.m_pMemory;
            }
            v12 = &m_pMemory[v10];
            if ( v12 != nullptr )
            {
              *(_QWORD *)&v12->a = *(_QWORD *)&mins.mins.z;
              *(_QWORD *)&v12->c = *(_QWORD *)&mins.maxs.y;
            }
            m_pModel = pmodel;
            ++j;
          }
          while ( j < v7->numfaces );
        }
        meshindex += 4;
        ++i;
      }
      while ( i < m_pModel->nummeshes );
    }
    BuildConvexListForFaceList(
      pmodel: m_pModel,
      (CUtlMemory<CDmeMesh::FaceSet_t,int> *)&convexList,
      &vertList,
      &faceList);
    v6 = BuildConvexesForLists(
           (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&convexOut,
           &convexList,
           &vertList,
           &worldspaceVerts,
           bRemove2d: v39->m_remove2d);
    v4 = convexList.m_Size;
    v5 = convexOut.m_Size;
  }
  if ( v5 > v39->m_maxConvex )
  {
    MdlWarning(fmt: "COSTLY COLLISION MODEL!!!! (%d parts - %d allowed)\n", v5, v39->m_maxConvex);
    v5 = convexOut.m_Size;
  }
  else if ( v6 )
  {
    if ( v5 != 0 )
    {
LABEL_42:
      if ( !g_quiet )
        printf(format: "Model has %d convex sub-parts\n", v5);
      v20 = (unsigned __int8 *)MemAlloc_Alloc(nSize: 0x30u);
      v21 = v20;
      if ( v20 != nullptr )
        memset(dst: v20, value: 0, count: 0x30u);
      else
        v21 = nullptr;
      v22 = (float *)v39;
      *((float *)v21 + 5) = v39->m_defaultDamping;
      *((float *)v21 + 7) = v22[55];
      v23 = v22[54];
      *((_DWORD *)v21 + 9) = 1065353216;
      *((float *)v21 + 6) = v23;
      *((float *)v21 + 8) = v22[56];
      ClearBounds(mins: &mins.mins, maxs: &mins.maxs);
      i = worldspaceVerts.m_Size - 2;
      if ( worldspaceVerts.m_Size - 2 >= 0 )
      {
        v24 = 12 * (worldspaceVerts.m_Size - 2);
        for ( meshindex = v24; ; v24 = meshindex )
        {
          AddPointToBounds(
            v: (const Vector *)((char *)worldspaceVerts.m_Memory.m_pMemory + v24),
            mins: &mins.mins,
            maxs: &mins.maxs);
          meshindex -= 12;
          if ( --i < 0 )
            break;
        }
      }
      CreateCollide(
        a1: COERCE_FLOAT(&savedregs),
        pBase: (CPhysCollisionModel *)v21,
        pElements: convexOut.m_Memory.m_pMemory,
        elementCount: convexOut.m_Size,
        bv: &mins);
      *((_DWORD *)v21 + 2) = 1065353216;
      V_FileBase(in: m_pModel->filename, out: tmp, maxlen: 512);
      v25 = (char *)MemAlloc_Alloc(nSize: strlen(tmp) + 1);
      strcpy(v25, tmp);
      v26 = v39;
      *((_DWORD *)v21 + 1) = v25;
      *(_DWORD *)v21 = 0;
      if ( v26->m_isMassCenterForced )
        physcollision->CollideSetMassCenter(
          this: physcollision,
          a2: *((struct CPhysCollide **)v21 + 10),
          a3: &v26->m_massCenterForced);
      *((_DWORD *)v21 + 11) = v26->m_pCollisionList;
      ++v26->m_collisionCount;
      v26->m_pCollisionList = (CPhysCollisionModel *)v21;
      goto LABEL_54;
    }
LABEL_26:
    v13 = v4;
    pmodel = (s_source_t *)m_pModel->numvertices;
    i = v4;
    if ( v4 + 1 > convexList.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<mergelist_t,int>::Grow(
        this: (CUtlMemory<CDmeMesh::FaceSet_t,int> *)&convexList,
        num: v4 - convexList.m_Memory.m_nAllocationCount + 1);
      v4 = convexList.m_Size;
      v13 = i;
    }
    v14 = vertList.m_Size;
    convexList.m_Size = v4 + 1;
    v15 = v4 - v13;
    convexList.m_pElements = convexList.m_Memory.m_pMemory;
    if ( v15 > 0 )
    {
      _V_memmove(
        dest: &convexList.m_Memory.m_pMemory[v13 + 1],
        src: &convexList.m_Memory.m_pMemory[v13],
        count: 8 * v15);
      v13 = i;
      v14 = vertList.m_Size;
    }
    v16 = &convexList.m_Memory.m_pMemory[v13];
    if ( v16 != nullptr )
    {
      v16->firstVertIndex = 0;
      v16->numVertIndex = (int)pmodel;
    }
    for ( meshindex = 0; meshindex < m_pModel->numvertices; ++meshindex )
    {
      v17 = v14;
      if ( v14 + 1 > vertList.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&vertList,
          num: v14 - vertList.m_Memory.m_nAllocationCount + 1);
        v14 = vertList.m_Size;
      }
      v18 = ++v14 - v17 - 1;
      vertList.m_Size = v14;
      vertList.m_pElements = vertList.m_Memory.m_pMemory;
      if ( v18 > 0 )
      {
        _V_memmove(dest: &vertList.m_Memory.m_pMemory[v17 + 1], src: &vertList.m_Memory.m_pMemory[v17], count: 4 * v18);
        v14 = vertList.m_Size;
      }
      v19 = &vertList.m_Memory.m_pMemory[v17];
      if ( v19 != nullptr )
        *v19 = meshindex;
    }
    BuildConvexesForLists(
      (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&convexOut,
      &convexList,
      &vertList,
      &worldspaceVerts,
      bRemove2d: true);
    if ( convexOut.m_Size != 0 )
    {
      v5 = convexOut.m_Size;
      goto LABEL_42;
    }
LABEL_54:
    if ( convexOut.m_Memory.m_nGrowSize >= 0 && convexOut.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: convexOut.m_Memory.m_pMemory);
    if ( vertList.m_Memory.m_nGrowSize >= 0 && vertList.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: vertList.m_Memory.m_pMemory);
    if ( convexList.m_Memory.m_nGrowSize >= 0 && convexList.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: convexList.m_Memory.m_pMemory);
    if ( faceList.m_Memory.m_nGrowSize >= 0 && faceList.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: faceList.m_Memory.m_pMemory);
    v27 = worldspaceVerts.m_Memory.m_pMemory;
    worldspaceVerts.m_Size = 0;
    if ( worldspaceVerts.m_Memory.m_nGrowSize >= 0 )
    {
      if ( worldspaceVerts.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: worldspaceVerts.m_Memory.m_pMemory);
        v27 = nullptr;
        worldspaceVerts.m_Memory.m_pMemory = nullptr;
      }
      worldspaceVerts.m_Memory.m_nAllocationCount = 0;
    }
    worldspaceVerts.m_pElements = v27;
    if ( worldspaceVerts.m_Memory.m_nGrowSize >= 0 && v27 != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v27);
    return 1;
  }
  if ( v5 != 0 )
  {
    MdlWarning(fmt: "Error with convex elements of %s, building single convex!!!!\n", m_pModel->filename);
    for ( meshindex = 0; meshindex < convexOut.m_Size; ++meshindex )
      physcollision->ConvexFree(this: physcollision, a2: convexOut.m_Memory.m_pMemory[meshindex]);
    convexOut.m_Size = 0;
    if ( convexOut.m_Memory.m_nGrowSize >= 0 )
    {
      if ( convexOut.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: convexOut.m_Memory.m_pMemory);
        convexOut.m_Memory.m_pMemory = nullptr;
      }
      convexOut.m_Memory.m_nAllocationCount = 0;
    }
    convexOut.m_pElements = convexOut.m_Memory.m_pMemory;
  }
  goto LABEL_26;
}

//------------------------------------------------------------------------------
// Address: 0x004062D0
// Name: void CollisionModel_Build(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CollisionModel_Build()
{
  if ( g_JointedModel.m_pModel != nullptr )
  {
    CCollisionModelSource::Simplify(this: &g_JointedModel);
    if ( g_JointedModel.m_isJointed )
      CJointedModel::ProcessJointedModel(this: &g_JointedModel);
    else
      CJointedModel::ProcessSingleBody(this: &g_JointedModel);
    CJointedModel::FixCollisionHierarchy(this: &g_JointedModel);
    if ( !g_quiet )
      printf(format: "Collision model completed.\n");
    CJointedModel::ComputeMass(this: &g_JointedModel);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406330
// Name: public: CJointedModel::CJointedModel(void)
// Source: json
//------------------------------------------------------------------------------
CJointedModel *__thiscall CJointedModel::CJointedModel(CJointedModel *this)
{
  this->m_bonemap.m_Memory.m_pMemory = nullptr;
  this->m_bonemap.m_Memory.m_nAllocationCount = 0;
  this->m_bonemap.m_Memory.m_nGrowSize = 0;
  this->m_bonemap.m_pElements = nullptr;
  this->m_textCommands.m_Memory.m_pMemory = nullptr;
  this->m_textCommands.m_Memory.m_nAllocationCount = 0;
  this->m_textCommands.m_Memory.m_nGrowSize = 0;
  this->m_textCommands.m_Size = 0;
  this->m_textCommands.m_pElements = nullptr;
  this->m_mergeList.m_Memory.m_pMemory = nullptr;
  this->m_mergeList.m_Memory.m_nAllocationCount = 0;
  this->m_mergeList.m_Memory.m_nGrowSize = 0;
  this->m_mergeList.m_Size = 0;
  this->m_mergeList.m_pElements = nullptr;
  this->m_totalMass = 1.0;
  this->m_pModel = nullptr;
  this->m_collisionCount = 0;
  this->m_pCollisionList = nullptr;
  this->m_pCollisionPairs = nullptr;
  this->m_bonemap.m_Size = 0;
  this->m_defaultInertia = 1.0;
  this->m_pConstraintList = nullptr;
  this->m_constraintCount = 0;
  this->m_totalVerts = 0;
  this->m_defaultDamping = 0.0;
  this->m_defaultRotdamping = 0.0;
  this->m_defaultDrag = -1.0;
  this->m_allowConcave = false;
  this->m_allowConcaveJoints = false;
  this->m_remove2d = false;
  this->m_maxConvex = 40;
  *(_WORD *)&this->m_isMassCenterForced = 0;
  this->m_massCenterForced.x = 0.0;
  this->m_massCenterForced.y = 0.0;
  this->m_massCenterForced.z = 0.0;
  this->m_flFrictionTimeIn = 0.0;
  this->m_flFrictionTimeOut = 0.0;
  this->m_iMinAnimatedFriction = 1;
  this->m_iMaxAnimatedFriction = 1;
  this->m_bHasAnimatedFriction = false;
  this->m_pOverrideName = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0041CAB0
// Name: private: class Vector __near & OptimizedModel::COptimizedModel::GetOrigVertPosition(struct mstudiomodel_t __near *,struct mstudiomesh_t __near *,struct OptimizedModel::Vertex_t __near *)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall OptimizedModel::COptimizedModel::GetOrigVertPosition(
        OptimizedModel::COptimizedModel *this,
        mstudiomodel_t *pStudioModel,
        mstudiomesh_t *pStudioMesh,
        OptimizedModel::Vertex_t *pVert)
{
  mstudio_meshvertexdata_t *vertData; // [esp+20h] [ebp-4h]

  mstudiomodel_t::GetVertexData(
    this: (mstudiomodel_t *)((char *)pStudioMesh + pStudioMesh->modelindex),
    pModelData: nullptr);
  pStudioMesh->vertexdata.modelvertexdata = (const mstudio_modelvertexdata_t *)((char *)&pStudioMesh->unused[6]
                                                                              + pStudioMesh->modelindex);
  if ( pStudioMesh->vertexdata.modelvertexdata->pVertexData != nullptr )
    vertData = &pStudioMesh->vertexdata;
  else
    vertData = nullptr;
  return (Vector *)((char *)vertData->modelvertexdata->pVertexData
                  + 48
                  * ((int)vertData[-1].modelvertexdata
                   + pVert->origMeshVertID
                   + (unsigned int)vertData->modelvertexdata[-3].pVertexData / 0x30)
                  + 16);
}

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x00401C70
// Name: char __near * MemAlloc_StrDup(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl MemAlloc_StrDup(const char *pString)
{
  char *result; // eax

  if ( pString == nullptr )
    return nullptr;
  result = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pString) + 1);
  if ( result == nullptr )
    return nullptr;
  strcpy(result, pString);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00401CC0
// Name: public: int CJointedModel::BoneIndex(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CJointedModel::BoneIndex(CJointedModel *this, const char *pName)
{
  s_source_t *m_pModel; // eax
  int v4; // esi
  int i; // edi
  const char *pNamea; // [esp+14h] [ebp+8h]

  pNamea = RenameBone(pName);
  m_pModel = this->m_pModel;
  v4 = 0;
  if ( this->m_pModel->numbones <= 0 )
    return -1;
  for ( i = 0; _V_stricmp(s1: m_pModel->localBone[i].name, s2: pNamea) != 0; ++i )
  {
    m_pModel = this->m_pModel;
    if ( ++v4 >= this->m_pModel->numbones )
      return -1;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00401D30
// Name: public: int CJointedModel::CollisionIndex(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CJointedModel::CollisionIndex(CJointedModel *this, const char *pName)
{
  CPhysCollisionModel *m_pCollisionList; // esi
  int v4; // edi

  if ( pName == nullptr )
    return -1;
  m_pCollisionList = this->m_pCollisionList;
  v4 = 0;
  if ( m_pCollisionList == nullptr )
    return -1;
  while ( _V_stricmp(s1: pName, s2: m_pCollisionList->m_name) != 0 )
  {
    m_pCollisionList = m_pCollisionList->m_pNext;
    ++v4;
    if ( m_pCollisionList == nullptr )
      return -1;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00401D80
// Name: public: void CJointedModel::SortCollisionList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CJointedModel::SortCollisionList(CJointedModel *this)
{
  CJointedModel *v1; // esi
  int m_collisionCount; // eax
  CPhysCollisionModel **v3; // edi
  CPhysCollisionModel *m_pCollisionList; // eax
  CPhysCollisionModel **v5; // ecx
  int v6; // ebx
  const char **p_m_parent; // eax
  int i; // esi
  int j; // eax
  CPhysCollisionModel *pPhys; // [esp+4h] [ebp-Ch]
  bool swapped; // [esp+Fh] [ebp-1h]

  v1 = this;
  m_collisionCount = this->m_collisionCount;
  if ( m_collisionCount != 0 )
  {
    v3 = (CPhysCollisionModel **)MemAlloc_Alloc(
                                   nSize: (unsigned __int64)(unsigned int)m_collisionCount >> 30 != 0
                                 ? -1
                                 : 4 * m_collisionCount);
    m_pCollisionList = v1->m_pCollisionList;
    if ( m_pCollisionList != nullptr )
    {
      v5 = v3;
      do
      {
        *v5 = m_pCollisionList;
        m_pCollisionList = m_pCollisionList->m_pNext;
        ++v5;
      }
      while ( m_pCollisionList != nullptr );
    }
    do
    {
      v6 = 0;
      swapped = false;
      if ( v1->m_collisionCount <= 0 )
        break;
      do
      {
        p_m_parent = &v3[v6]->m_parent;
        pPhys = (CPhysCollisionModel *)p_m_parent;
        if ( *p_m_parent != nullptr && _V_stricmp(s1: p_m_parent[1], s2: *p_m_parent) != 0 )
        {
          for ( i = 0; i < this->m_collisionCount; ++i )
          {
            if ( i != v6 && _V_stricmp(s1: pPhys->m_parent, s2: v3[i]->m_name) == 0 )
              break;
          }
          if ( i <= v6 || i >= this->m_collisionCount )
          {
            v1 = this;
          }
          else
          {
            v3[v6] = v3[i];
            v3[i] = pPhys;
            swapped = true;
            v1 = this;
          }
        }
        ++v6;
      }
      while ( v6 < v1->m_collisionCount );
    }
    while ( swapped );
    for ( j = 0; j < v1->m_collisionCount - 1; ++j )
      v3[j]->m_pNext = v3[j + 1];
    v3[j]->m_pNext = nullptr;
    v1->m_pCollisionList = *v3;
    free(pMem: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401EC0
// Name: public: void CJointedModel::AppendCollisionPair(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CJointedModel::AppendCollisionPair(CJointedModel *this, const char *pName0, const char *pName1)
{
  collisionpair_t *v4; // edi
  int LocalBoneNamed; // eax
  s_node_t *v6; // eax
  int v7; // eax
  s_node_t *v8; // eax

  v4 = (collisionpair_t *)MemAlloc_Alloc(nSize: 0x14u);
  v4->obj0 = -1;
  v4->obj1 = -1;
  LocalBoneNamed = CCollisionModelSource::FindLocalBoneNamed(this, pName: pName0);
  if ( LocalBoneNamed < 0 )
    v6 = nullptr;
  else
    v6 = &this->m_pModel->localBone[LocalBoneNamed];
  v4->pName0 = (const char *)v6;
  v7 = CCollisionModelSource::FindLocalBoneNamed(this, pName: pName1);
  if ( v7 < 0 )
    v8 = nullptr;
  else
    v8 = &this->m_pModel->localBone[v7];
  v4->pName1 = (const char *)v8;
  v4->pNext = this->m_pCollisionPairs;
  this->m_pCollisionPairs = v4;
}

//------------------------------------------------------------------------------
// Address: 0x00401F40
// Name: public: void CJointedModel::ForceMassCenter(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CJointedModel::ForceMassCenter(CJointedModel *this, const Vector *centerOfMass)
{
  this->m_isMassCenterForced = true;
  this->m_massCenterForced = *centerOfMass;
}

//------------------------------------------------------------------------------
// Address: 0x00401F70
// Name: public: class CPhysCollisionModel __near * CJointedModel::GetCollisionModel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CPhysCollisionModel *__thiscall CJointedModel::GetCollisionModel(CJointedModel *this, const char *pName)
{
  CPhysCollisionModel *m_pCollisionList; // esi

  if ( pName == nullptr )
    return nullptr;
  m_pCollisionList = this->m_pCollisionList;
  if ( m_pCollisionList == nullptr )
    return nullptr;
  while ( _V_stricmp(s1: pName, s2: m_pCollisionList->m_name) != 0 )
  {
    m_pCollisionList = m_pCollisionList->m_pNext;
    if ( m_pCollisionList == nullptr )
      return nullptr;
  }
  return m_pCollisionList;
}

//------------------------------------------------------------------------------
// Address: 0x00401FC0
// Name: public: void CJointedModel::AddConstraint(char const __near *,int,enum jointlimit_t,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CJointedModel::AddConstraint(
        CJointedModel *this,
        const char *pJointName,
        int axis,
        jointlimit_t jointType,
        float limitMin,
        float limitMax,
        float friction)
{
  float *v8; // eax

  v8 = (float *)MemAlloc_Alloc(nSize: 0x1Cu);
  if ( v8 != nullptr )
  {
    v8[3] = limitMin;
    v8[4] = limitMax;
    *((_DWORD *)v8 + 1) = axis;
    *((_DWORD *)v8 + 2) = jointType;
    v8[5] = friction * 0.2;
    *(_DWORD *)v8 = pJointName;
  }
  else
  {
    v8 = nullptr;
  }
  v8[6] = *(float *)&this->m_pConstraintList;
  ++this->m_constraintCount;
  this->m_pConstraintList = (CJointConstraint *)v8;
}

//------------------------------------------------------------------------------
// Address: 0x00402030
// Name: public: void CJointedModel::ComputeMass(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CJointedModel::ComputeMass(CJointedModel *this)
{
  CPhysCollisionModel *m_pCollisionList; // esi
  const char *SurfaceProp; // eax
  int v4; // eax
  float thickness; // [esp+24h] [ebp-8h] BYREF
  float density; // [esp+28h] [ebp-4h] BYREF

  if ( this->m_totalMass < 0.0 )
  {
    m_pCollisionList = this->m_pCollisionList;
    for ( this->m_totalMass = 0.0; m_pCollisionList != nullptr; m_pCollisionList = m_pCollisionList->m_pNext )
    {
      SurfaceProp = GetSurfaceProp(pJointName: m_pCollisionList->m_name);
      v4 = physprops->GetSurfaceIndex(this: physprops, a2: SurfaceProp);
      physprops->GetPhysicsProperties(this: physprops, a2: v4, a3: &density, a4: &thickness, a5: nullptr, a6: nullptr);
      if ( thickness <= 0.0 )
        this->m_totalMass = (float)((float)(m_pCollisionList->m_volume * 0.000016387063) * density) + this->m_totalMass;
      else
        this->m_totalMass = (float)((float)((float)(m_pCollisionList->m_surfaceArea * thickness) * 0.000016387063)
                                  * density)
                          + this->m_totalMass;
    }
    if ( !g_quiet )
      printf(format: "Computed Mass: %.2f kg\n", this->m_totalMass);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402130
// Name: public: class CPhysCollisionModel __near * CJointedModel::InitCollisionModel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CPhysCollisionModel *__thiscall CJointedModel::InitCollisionModel(CJointedModel *this, const char *pJointName)
{
  CPhysCollisionModel *CollisionModel; // esi
  int v4; // ebx
  unsigned __int8 *v6; // eax
  int parent; // eax
  double m_defaultRotdamping; // st7

  CollisionModel = CJointedModel::GetCollisionModel(this, pName: pJointName);
  if ( CollisionModel == nullptr )
  {
    v4 = CJointedModel::BoneIndex(this, pName: pJointName);
    if ( v4 < 0 )
      return nullptr;
    v6 = (unsigned __int8 *)MemAlloc_Alloc(nSize: 0x30u);
    CollisionModel = (CPhysCollisionModel *)v6;
    if ( v6 != nullptr )
      memset(dst: v6, value: 0, count: 0x30u);
    else
      CollisionModel = nullptr;
    CollisionModel->m_name = this->m_pModel->localBone[v4].name;
    parent = this->m_pModel->localBone[v4].parent;
    if ( parent < 0 )
      CollisionModel->m_parent = nullptr;
    else
      CollisionModel->m_parent = this->m_pModel->localBone[parent].name;
    CollisionModel->m_damping = this->m_defaultDamping;
    CollisionModel->m_inertia = this->m_defaultInertia;
    m_defaultRotdamping = this->m_defaultRotdamping;
    CollisionModel->m_massBias = 1.0;
    CollisionModel->m_rotdamping = m_defaultRotdamping;
    CollisionModel->m_dragCoefficient = this->m_defaultDrag;
    if ( this->m_isMassCenterForced )
      physcollision->CollideSetMassCenter(
        this: physcollision,
        a2: CollisionModel->m_pCollisionData,
        a3: &this->m_massCenterForced);
    CollisionModel->m_pNext = this->m_pCollisionList;
    ++this->m_collisionCount;
    this->m_pCollisionList = CollisionModel;
  }
  return CollisionModel;
}

//------------------------------------------------------------------------------
// Address: 0x00402230
// Name: void BuildVertWeldTable(int __near *,struct s_source_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildVertWeldTable(int *weldTable, s_source_t *pmodel)
{
  s_source_t *v2; // eax
  int v3; // esi
  int v4; // ecx
  int v5; // edi
  s_vertexinfo_t *vertex; // edx
  float x; // xmm3_4
  float y; // xmm4_4
  float z; // xmm5_4
  float *p_z; // eax
  float *v11; // edx
  s_vertexinfo_t *v12; // [esp-8h] [ebp-14h]
  float *v13; // [esp-4h] [ebp-10h]

  v2 = pmodel;
  v3 = 0;
  if ( pmodel->numvertices <= 0 )
    return;
  v4 = 0;
  do
  {
    v5 = 0;
    if ( v3 <= 0 )
    {
LABEL_10:
      weldTable[v3] = v3;
      goto LABEL_11;
    }
    vertex = v2->vertex;
    x = vertex[v4].position.x;
    y = vertex[v4].position.y;
    z = vertex[v4].position.z;
    v12 = vertex;
    p_z = &vertex->normal.z;
    v11 = &vertex->position.z;
    v13 = v11;
    while ( g_WeldVertEpsilon < fsqrt(
                                  (float)((float)((float)(*(v11 - 1) - y) * (float)(*(v11 - 1) - y))
                                        + (float)((float)(*v11 - z) * (float)(*v11 - z)))
                                + (float)((float)(*(v11 - 2) - x) * (float)(*(v11 - 2) - x))) )
    {
LABEL_8:
      ++v5;
      v11 += 21;
      p_z += 21;
      v13 = v11;
      if ( v5 >= v3 )
      {
        v2 = pmodel;
        goto LABEL_10;
      }
    }
    if ( (float)((float)((float)(*(p_z - 1) * v12[v4].normal.y) + (float)(*(p_z - 2) * v12[v4].normal.x))
               + (float)(v12[v4].normal.z * *p_z)) <= g_WeldNormalEpsilon )
    {
      v11 = v13;
      goto LABEL_8;
    }
    weldTable[v3] = v5;
    v2 = pmodel;
LABEL_11:
    ++v3;
    ++v4;
  }
  while ( v3 < v2->numvertices );
}

//------------------------------------------------------------------------------
// Address: 0x00402360
// Name: public: char const __near * CJointedModel::FixParent(char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CJointedModel::FixParent(CJointedModel *this, const char *pParentName)
{
  const char *name; // edi
  CPhysCollisionModel *m_pCollisionList; // esi
  int LocalBoneNamed; // eax
  s_source_t *m_pModel; // ecx
  int parent; // eax
  int v8; // eax

  name = pParentName;
  if ( pParentName == nullptr )
    return nullptr;
  while ( 1 )
  {
    m_pCollisionList = this->m_pCollisionList;
    if ( m_pCollisionList != nullptr )
      break;
LABEL_5:
    LocalBoneNamed = CCollisionModelSource::FindLocalBoneNamed(this, pName: name);
    if ( LocalBoneNamed >= 0 )
    {
      m_pModel = this->m_pModel;
      parent = this->m_pModel->localBone[LocalBoneNamed].parent;
      if ( parent >= 0 )
      {
        v8 = parent;
        name = m_pModel->localBone[v8].name;
        if ( &m_pModel->filename[v8 * 132] != (char *)-268 )
          continue;
      }
    }
    return nullptr;
  }
  while ( _V_stricmp(s1: name, s2: m_pCollisionList->m_name) != 0 )
  {
    m_pCollisionList = m_pCollisionList->m_pNext;
    if ( m_pCollisionList == nullptr )
      goto LABEL_5;
  }
  return name;
}

//------------------------------------------------------------------------------
// Address: 0x004023E0
// Name: bool IsApproximatelyPlanar(class Vector __near * __near *,int,float)
// Source: json
//------------------------------------------------------------------------------
char __usercall IsApproximatelyPlanar@<al>(float a1@<ebp>, Vector **verts, int vertCount, float epsilon)
{
  int v4; // edx
  int v5; // edi
  Vector *v6; // ecx
  float x; // xmm3_4
  float y; // xmm4_4
  float v9; // xmm5_4
  Vector *v10; // ecx
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  int v14; // ecx
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm0_4
  float v19; // [esp-Ch] [ebp-2Ch]
  float v20; // [esp-8h] [ebp-28h]
  Vector edge0; // [esp+0h] [ebp-20h] BYREF
  Vector normal; // [esp+Ch] [ebp-14h]
  void *v23; // [esp+18h] [ebp-8h]
  void *retaddr; // [esp+20h] [ebp+0h]

  normal.z = a1;
  v23 = retaddr;
  v4 = vertCount;
  if ( vertCount < 4 )
    return 1;
  LODWORD(normal.y) = 1;
  v5 = 2;
  while ( v5 < v4 )
  {
    v6 = verts[LODWORD(normal.y)];
    x = v6->x;
    y = v6->y;
    v9 = v6->z - (*verts)->z;
    v10 = verts[v5];
    v11 = v10->y - (*verts)->y;
    v12 = v10->x - (*verts)->x;
    v13 = v10->z - (*verts)->z;
    v19 = x - (*verts)->x;
    v20 = y - (*verts)->y;
    edge0.x = (float)(v13 * v20) - (float)(v11 * v9);
    edge0.y = (float)(v9 * v12) - (float)(v13 * v19);
    edge0.z = (float)(v11 * v19) - (float)(v12 * v20);
    if ( VectorNormalize(vec: &edge0) > 0.001 )
      goto LABEL_9;
    normal.x = v20 * v20;
    if ( fsqrt((float)((float)(v20 * v20) + (float)(v9 * v9)) + (float)(v19 * v19)) < 0.001 )
      ++LODWORD(normal.y);
    ++v5;
    if ( SLODWORD(normal.y) >= vertCount )
    {
LABEL_9:
      v4 = vertCount;
      break;
    }
    v4 = vertCount;
  }
  v14 = 0;
  v15 = (float)((float)((*verts)->y * edge0.y) + (float)((*verts)->x * edge0.x)) + (float)((*verts)->z * edge0.z);
  v16 = v15;
  if ( v4 <= 0 )
    return 1;
  while ( 1 )
  {
    v17 = (float)((float)(verts[v14]->y * edge0.y) + (float)(verts[v14]->x * edge0.x))
        + (float)(verts[v14]->z * edge0.z);
    if ( v15 <= v17 )
    {
      if ( v17 > v16 )
        v16 = (float)((float)(verts[v14]->y * edge0.y) + (float)(verts[v14]->x * edge0.x))
            + (float)(verts[v14]->z * edge0.z);
    }
    else
    {
      v15 = (float)((float)(verts[v14]->y * edge0.y) + (float)(verts[v14]->x * edge0.x))
          + (float)(verts[v14]->z * edge0.z);
    }
    if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(v16 - v15) & _mask__AbsFloat_) > epsilon )
      break;
    if ( ++v14 >= v4 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004025F0
// Name: int ReadArgs(char (__near * const)[256],int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ReadArgs(char (*pArgs)[256], int maxCount)
{
  int i; // esi

  for ( i = 0; i < maxCount; ++pArgs )
  {
    if ( TokenAvailable() == 0 )
      break;
    GetToken(crossline: 0);
    strncpy(dest: (unsigned __int8 *)pArgs, source: (unsigned __int8 *)token, count: 0x100u);
    ++i;
  }
  return i;
}

//------------------------------------------------------------------------------
// Address: 0x00402640
// Name: void CCmd_JointConstrain(class CJointedModel __near &,char const __near *,char const __near *,char const __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CCmd_JointConstrain(
        CJointedModel *joints,
        const char *pJointName,
        const char *pJointAxis,
        const char *pJointType,
        const char *pLimitMin,
        const char *pLimitMax,
        const char *pFriction)
{
  int LocalBoneNamed; // eax
  s_node_t *v8; // ebx
  int v9; // esi
  jointlimit_t v10; // eax
  float limitMin; // [esp+18h] [ebp-4h]
  float limitMax; // [esp+34h] [ebp+18h]
  float friction; // [esp+38h] [ebp+1Ch]

  if ( pLimitMin != nullptr )
    limitMin = atof(nptr: pLimitMin);
  else
    limitMin = 0.0;
  if ( pLimitMax != nullptr )
    limitMax = atof(nptr: pLimitMax);
  else
    limitMax = 0.0;
  if ( pFriction != nullptr )
    friction = atof(nptr: pFriction);
  else
    friction = 0.0;
  LocalBoneNamed = CCollisionModelSource::FindLocalBoneNamed(this: joints, pName: pJointName);
  if ( !g_bCreateMakefile && LocalBoneNamed < 0 )
  {
    MdlWarning(fmt: "Can't find joint %s\n", pJointName);
    return;
  }
  v8 = &joints->m_pModel->localBone[LocalBoneNamed];
  if ( pJointAxis == nullptr || (unsigned int)(v9 = tolower(c: *pJointAxis) - 120) > 2 || limitMin > limitMax )
    MdlError(fmt: "Invalid joint constraint for %s\nCan't build ragdoll!\n", v8->name);
  v10 = _V_stricmp(s1: pJointType, s2: "free");
  if ( v10 == JOINT_FREE )
    goto LABEL_21;
  if ( _V_stricmp(s1: pJointType, s2: "fixed") == 0 )
  {
    v10 = JOINT_FIXED;
LABEL_21:
    CJointedModel::AddConstraint(
      this: joints,
      pJointName: v8->name,
      axis: v9,
      jointType: v10,
      limitMin,
      limitMax,
      friction);
    return;
  }
  if ( _V_stricmp(s1: pJointType, s2: "limit") == 0 )
  {
    v10 = JOINT_LIMIT;
    goto LABEL_21;
  }
  MdlWarning(fmt: "Unknown joint type %s (must be free, fixed, or limit)\n", pJointType);
}

//------------------------------------------------------------------------------
// Address: 0x004027C0
// Name: void CCmd_JointSkip(class CJointedModel __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CCmd_JointSkip(CJointedModel *joints, const char *pName)
{
  int LocalBoneNamed; // eax

  LocalBoneNamed = CCollisionModelSource::FindLocalBoneNamed(this: joints, pName);
  if ( LocalBoneNamed >= 0 )
    CCollisionModelSource::SkipBone(this: joints, boneIndex: LocalBoneNamed);
  else
    MdlWarning(fmt: "Can't skip joint %s, not found\n", pName);
}

//------------------------------------------------------------------------------
// Address: 0x00402800
// Name: void CCmd_JointRoot(class CJointedModel __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CCmd_JointRoot(CJointedModel *joints, const char *pBone)
{
  strcpy(joints->m_rootName, pBone);
}

//------------------------------------------------------------------------------
// Address: 0x00402820
// Name: void CCmd_JoinAnimatedFriction(class CJointedModel __near &,char const __near *,char const __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CCmd_JoinAnimatedFriction(
        CJointedModel *joints,
        const char *pMinFriction,
        const char *pMaxFriction,
        const char *pTimeIn,
        const char *pTimeHold,
        const char *pTimeOut)
{
  float v6; // xmm0_4
  float v7; // xmm0_4
  float v8; // xmm0_4
  const char *v9; // eax
  int v10; // eax
  float pTimeIna; // [esp+14h] [ebp+14h]
  float pTimeInb; // [esp+14h] [ebp+14h]
  float pTimeInc; // [esp+14h] [ebp+14h]

  if ( pTimeIn != nullptr )
  {
    pTimeIna = atof(nptr: pTimeIn);
    v6 = pTimeIna;
  }
  else
  {
    v6 = 0.0;
  }
  joints->m_flFrictionTimeIn = v6;
  if ( pTimeOut != nullptr )
  {
    pTimeInb = atof(nptr: pTimeOut);
    v7 = pTimeInb;
  }
  else
  {
    v7 = 0.0;
  }
  joints->m_flFrictionTimeOut = v7;
  if ( pTimeHold != nullptr )
  {
    pTimeInc = atof(nptr: pTimeHold);
    v8 = pTimeInc;
  }
  else
  {
    v8 = 0.0;
  }
  v9 = pMinFriction;
  joints->m_flFrictionTimeHold = v8;
  if ( pMinFriction != nullptr )
    v9 = (const char *)atoi(nptr: pMinFriction);
  joints->m_iMinAnimatedFriction = (int)v9;
  if ( pMaxFriction != nullptr )
  {
    v10 = atoi(nptr: pMaxFriction);
    joints->m_bHasAnimatedFriction = true;
    joints->m_iMaxAnimatedFriction = v10;
  }
  else
  {
    joints->m_bHasAnimatedFriction = true;
    joints->m_iMaxAnimatedFriction = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004028E0
// Name: LoadSurfaceProps
// Source: json
//------------------------------------------------------------------------------
char __usercall LoadSurfaceProps@<al>(int a1@<ebx>, int a2@<edi>, int a3@<esi>, const char *pMaterialFilename)
{
  void *v5; // ebx
  int v6; // edi
  void *v7; // esi

  if ( physprops == nullptr )
    return 0;
  v5 = g_pFileSystem->Open(this: g_pFileSystem, a2: pMaterialFilename, a3: "rb", a4: "GAME");
  if ( v5 == nullptr )
    return 0;
  v6 = ((int (__thiscall *)(IBaseFileSystem *, void *, int, int, int))g_pFileSystem->Size_2)(
         a1: g_pFileSystem,
         a2: v5,
         a3: a2,
         a4: a3,
         a5: a1);
  v7 = MemAlloc_Alloc(nSize: v6 + 1);
  g_pFileSystem->Read(this: g_pFileSystem, a2: v7, a3: v6, a4: v5);
  ((void (__thiscall *)(IBaseFileSystem *))g_pFileSystem->Close)(a1: g_pFileSystem);
  *((_BYTE *)v7 + v6) = 0;
  physprops->ParseSurfaceData(this: physprops, a2: pMaterialFilename, a3: (const char *)v7);
  free(pMem: v7);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00402980
// Name: void LoadSurfacePropsAll(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall LoadSurfacePropsAll(int a1@<ebx>)
{
  KeyValues *v1; // eax
  KeyValues *v2; // edi
  KeyValues *i; // esi
  const char *Name; // eax
  const char *String; // eax

  if ( !bIsLoaded )
  {
    v1 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v1 != nullptr )
      v2 = KeyValues::KeyValues(this: v1, setName: "scripts/surfaceproperties_manifest.txt");
    else
      v2 = nullptr;
    if ( KeyValues::LoadFromFile(
           this: v2,
           filesystem: g_pFileSystem,
           resourceName: "scripts/surfaceproperties_manifest.txt",
           pathID: "GAME",
           pfnEvaluateSymbolProc: nullptr) )
    {
      bIsLoaded = true;
      for ( i = KeyValues::GetFirstSubKey(this: v2); i != nullptr; i = KeyValues::GetNextKey(this: i) )
      {
        Name = KeyValues::GetName(this: i);
        if ( _V_stricmp(s1: Name, s2: "file") == 0 )
        {
          String = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: pDeltaStateName);
          LoadSurfaceProps(a1, a2: (int)v2, a3: (int)i, pMaterialFilename: String);
        }
      }
    }
    KeyValues::deleteThis(this: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402A30
// Name: void BuildRagdollConstraint(class CPhysCollisionModel __near *,struct constraint_ragdollparams_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildRagdollConstraint(CPhysCollisionModel *pPhys, constraint_ragdollparams_t *ragdoll)
{
  int v2; // eax
  bool v3; // sf
  CJointConstraint *i; // edi
  const char *m_pJointName; // eax
  CPhysCollisionModel *m_pCollisionList; // esi
  int v7; // ebx
  const char *v8; // ebx
  CPhysCollisionModel *v9; // esi
  const char *m_parent; // eax
  CPhysCollisionModel *v11; // esi
  int v12; // ebx
  jointlimit_t m_jointType; // eax
  __int32 v14; // eax
  double m_limitMin; // st7
  float m_friction; // xmm1_4
  constraint_axislimit_t *v17; // eax
  float v18; // xmm0_4
  constraint_axislimit_t *v19; // eax
  const char *v20; // [esp+8h] [ebp-4h]
  int index; // [esp+14h] [ebp+8h]
  int indexa; // [esp+14h] [ebp+8h]

  memset(dst: (unsigned __int8 *)ragdoll, value: 0, count: sizeof(constraint_ragdollparams_t));
  ragdoll->parentIndex = CJointedModel::CollisionIndex(this: &g_JointedModel, pName: pPhys->m_parent);
  v2 = CJointedModel::CollisionIndex(this: &g_JointedModel, pName: pPhys->m_name);
  v3 = ragdoll->parentIndex < 0;
  ragdoll->childIndex = v2;
  if ( v3 || v2 < 0 )
  {
    MdlWarning(fmt: "Constraint between bone %s and %s\n", pPhys->m_name, pPhys->m_parent);
    if ( ragdoll->childIndex < 0 )
      MdlWarning(fmt: "\"%s\" does not appear in collision model!!!\n", pPhys->m_name);
    if ( ragdoll->parentIndex < 0 )
      MdlWarning(fmt: "\"%s\" does not appear in collision model!!!\n", pPhys->m_parent);
    MdlError(fmt: "Bad constraint in ragdoll\n");
  }
  for ( i = g_JointedModel.m_pConstraintList; i != nullptr; i = i->m_pNext )
  {
    m_pJointName = i->m_pJointName;
    index = (int)i->m_pJointName;
    if ( i->m_pJointName != nullptr
      && (m_pCollisionList = g_JointedModel.m_pCollisionList, v7 = 0, g_JointedModel.m_pCollisionList != nullptr) )
    {
      while ( _V_stricmp(s1: m_pJointName, s2: m_pCollisionList->m_name) != 0 )
      {
        m_pCollisionList = m_pCollisionList->m_pNext;
        ++v7;
        if ( m_pCollisionList == nullptr )
          goto LABEL_11;
        m_pJointName = (const char *)index;
      }
      indexa = v7;
    }
    else
    {
LABEL_11:
      indexa = -1;
    }
    v8 = i->m_pJointName;
    if ( i->m_pJointName != nullptr
      && (v9 = g_JointedModel.m_pCollisionList, g_JointedModel.m_pCollisionList != nullptr) )
    {
      while ( _V_stricmp(s1: v8, s2: v9->m_name) != 0 )
      {
        v9 = v9->m_pNext;
        if ( v9 == nullptr )
          goto LABEL_16;
      }
    }
    else
    {
LABEL_16:
      v9 = nullptr;
    }
    if ( indexa < 0 )
      MdlError(fmt: "Rotation constraint on bone \"%s\" which does not appear in collision model!!!\n", i->m_pJointName);
    m_parent = v9->m_parent;
    v20 = v9->m_parent;
    if ( v9->m_parent == nullptr )
      goto LABEL_32;
    v11 = g_JointedModel.m_pCollisionList;
    v12 = 0;
    if ( g_JointedModel.m_pCollisionList == nullptr )
      goto LABEL_32;
    while ( _V_stricmp(s1: m_parent, s2: v11->m_name) != 0 )
    {
      v11 = v11->m_pNext;
      ++v12;
      if ( v11 == nullptr )
        goto LABEL_32;
      m_parent = v20;
    }
    if ( v12 < 0 )
    {
LABEL_32:
      if ( _V_stricmp(s1: i->m_pJointName, s2: g_JointedModel.m_rootName) != 0 )
        MdlError(fmt: "Rotation constraint on bone \"%s\" which has no parent!!!\n", i->m_pJointName);
    }
    if ( indexa != ragdoll->childIndex )
      continue;
    m_jointType = i->m_jointType;
    if ( m_jointType != JOINT_FREE )
    {
      v14 = m_jointType - 1;
      if ( v14 != 0 )
      {
        if ( v14 == 1 )
        {
          m_limitMin = i->m_limitMin;
          m_friction = i->m_friction;
          v17 = &ragdoll->axes[i->m_axis];
          v17->maxRotation = i->m_limitMax;
          v17->minRotation = m_limitMin;
          v17->angularVelocity = 0.0;
          v17->torque = m_friction;
        }
        continue;
      }
      v18 = 0.0;
      v19 = &ragdoll->axes[i->m_axis];
      v19->minRotation = 0.0;
      v19->maxRotation = 0.0;
      v19->angularVelocity = 0.0;
    }
    else
    {
      v18 = i->m_friction;
      v19 = &ragdoll->axes[i->m_axis];
      v19->minRotation = -360.0;
      v19->maxRotation = 360.0;
      v19->angularVelocity = 0.0;
    }
    v19->torque = v18;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402C80
// Name: void CollisionModel_ExpandBBox(class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CollisionModel_ExpandBBox(Vector *mins, Vector *maxs)
{
  Vector collideMaxs; // [esp+0h] [ebp-18h] BYREF
  Vector collideMins; // [esp+Ch] [ebp-Ch] BYREF

  if ( !g_JointedModel.m_isJointed && g_JointedModel.m_pCollisionList != nullptr )
  {
    physcollision->CollideGetAABB(
      this: physcollision,
      a2: &collideMins,
      a3: &collideMaxs,
      a4: g_JointedModel.m_pCollisionList->m_pCollisionData,
      a5: &vec3_origin,
      a6: &vec3_angle);
    collideMins.x = collideMins.x - 0.25;
    collideMins.y = collideMins.y - 0.25;
    collideMins.z = collideMins.z - 0.25;
    collideMaxs.x = collideMaxs.x + 0.25;
    collideMaxs.y = collideMaxs.y + 0.25;
    collideMaxs.z = collideMaxs.z + 0.25;
    AddPointToBounds(v: &collideMins, mins, maxs);
    AddPointToBounds(v: &collideMaxs, mins, maxs);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402D50
// Name: void CollisionModel_SetName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CollisionModel_SetName(const char *pName)
{
  int v1; // eax
  int v2; // esi

  if ( g_JointedModel.m_pOverrideName != nullptr )
    free(pMem: g_JointedModel.m_pOverrideName);
  if ( pName != nullptr )
  {
    v1 = _V_strlen(str: pName);
    if ( v1 != 0 )
    {
      v2 = v1 + 1;
      g_JointedModel.m_pOverrideName = (char *)MemAlloc_Alloc(nSize: v1 + 1);
      V_strncpy(pDest: g_JointedModel.m_pOverrideName, pSrc: pName, maxLen: v2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402DB0
// Name: float clamp<float,float,float>(float const __near &,float const __near &,float const __near &)
// Source: json
//------------------------------------------------------------------------------
double __cdecl clamp<float,float,float>(const float *val, const float *minVal, const float *maxVal)
{
  if ( *minVal > *val )
    return *minVal;
  if ( *val <= *maxVal )
    return *val;
  return *maxVal;
}

//------------------------------------------------------------------------------
// Address: 0x00402E00
// Name: void CreateCollide(class CPhysCollisionModel __near *,class CPhysConvex __near * __near *,int,struct boundingvolume_t const __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall CreateCollide(
        float a1@<ebp>,
        CPhysCollisionModel *pBase,
        struct CPhysConvex **pElements,
        int elementCount,
        const boundingvolume_t *bv)
{
  int v5; // edi
  double v6; // st7
  float v7; // xmm2_4
  float v8; // xmm1_4
  float v9; // xmm4_4
  float v10; // xmm0_4
  int v11; // eax
  float v12; // xmm1_4
  float v13; // xmm0_4
  __int128 v14; // xmm0
  _DWORD v15[3]; // [esp-Ch] [ebp-3Ch] BYREF
  _BYTE params[20]; // [esp+0h] [ebp-30h] OVERLAPPED
  Vector tmp; // [esp+14h] [ebp-1Ch]
  Vector size; // [esp+20h] [ebp-10h]
  float retaddr; // [esp+30h] [ebp+0h]

  size.y = a1;
  size.z = retaddr;
  if ( pBase != nullptr )
  {
    v5 = 0;
    pBase->m_volume = 0.0;
    for ( pBase->m_surfaceArea = 0.0; v5 < elementCount; pBase->m_surfaceArea = v6 + pBase->m_surfaceArea )
    {
      pBase->m_volume = ((double (__thiscall *)(IPhysicsCollision *, struct CPhysConvex *))physcollision->ConvexVolume)(
                          a1: physcollision,
                          a2: pElements[v5])
                      + pBase->m_volume;
      v6 = ((double (__thiscall *)(IPhysicsCollision *, struct CPhysConvex *))physcollision->ConvexSurfaceArea)(
             a1: physcollision,
             a2: pElements[v5++]);
    }
    v7 = bv->maxs.x - bv->mins.x;
    v8 = bv->maxs.y - bv->mins.y;
    v9 = bv->maxs.z - bv->mins.z;
    v10 = v9 * v8;
    v11 = v8 > v7;
    LOWORD(v15[1]) = 0;
    *(_DWORD *)params = 0;
    v15[0] = 16777473;
    tmp.x = v7;
    tmp.y = v8;
    tmp.z = v9;
    if ( (float)(v9 * v8) < 0.0 || v10 > (float)(v9 * v7) )
      v10 = v9 * v7;
    if ( v9 > *(&tmp.x + v11) )
      v11 = 2;
    v12 = v8 * v7;
    if ( v10 < 0.0 || v10 > v12 )
      v10 = v12;
    v13 = v10 * 0.000099999997;
    if ( v13 >= 0.25 )
    {
      if ( v13 <= 128.0 )
        *(float *)&v15[2] = v13;
      else
        v15[2] = 1124073472;
    }
    else
    {
      v15[2] = 1048576000;
    }
    *(Vector *)&params[8] = tmp;
    *(_DWORD *)&params[4 * v11 + 8] = 0;
    size.x = *(float *)&params[12] * *(float *)&params[12];
    v14 = 0;
    *(float *)&v14 = fsqrt(
                       (float)((float)(*(float *)&params[12] * *(float *)&params[12])
                             + (float)(*(float *)&params[16] * *(float *)&params[16]))
                     + (float)(*(float *)&params[8] * *(float *)&params[8]));
    *(_OWORD *)&params[4] = v14;
    if ( *(float *)&v14 > 0.0 && (float)(*(&tmp.x + v11) / *(float *)&params[4]) > 9.0 )
      pBase->m_rotdamping = 1.0;
    pBase->m_pCollisionData = physcollision->ConvertConvexToCollideParams(
                                this: physcollision,
                                a2: pElements,
                                a3: elementCount,
                                a4: v15);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402FF0
// Name: public: void CJointedModel::FixBoneList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CJointedModel::FixBoneList(CJointedModel *this)
{
  CPhysCollisionModel *i; // esi
  int LocalBoneNamed; // eax
  s_source_t *m_pModel; // ecx
  int j; // edx
  int v6; // ebx
  s_source_t *v7; // ecx
  int parent; // edx
  int v9; // edx
  int v10; // eax

  if ( this->m_isJointed )
  {
    for ( i = this->m_pCollisionList; i != nullptr; i = i->m_pNext )
    {
      LocalBoneNamed = CCollisionModelSource::FindLocalBoneNamed(this, pName: i->m_name);
      if ( LocalBoneNamed < 0 )
        goto LABEL_13;
      m_pModel = this->m_pModel;
      for ( j = 0;
            m_pModel->boneLocalToGlobal[LocalBoneNamed] < 0;
            LocalBoneNamed = m_pModel->localBone[LocalBoneNamed].parent )
      {
        v6 = j++;
        if ( v6 > 1024 )
          break;
      }
      if ( LocalBoneNamed < 0 )
      {
LABEL_13:
        MdlWarning(fmt: "Physics for unknown bone %s\n", i->m_name);
      }
      else
      {
        i->m_name = g_bonetable[m_pModel->boneLocalToGlobal[LocalBoneNamed]].name;
        i->m_parent = nullptr;
        v7 = this->m_pModel;
        parent = this->m_pModel->localBone[LocalBoneNamed].parent;
        if ( parent >= 0 && parent != LocalBoneNamed )
        {
          v9 = this->m_bonemap.m_Memory.m_pMemory[parent];
          v10 = v7->boneLocalToGlobal[v9];
          if ( v10 >= 0 )
            i->m_parent = g_bonetable[v10].name;
          else
            i->m_parent = v7->localBone[v9].name;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004030E0
// Name: public: void CJointedModel::FixCollisionHierarchy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CJointedModel::FixCollisionHierarchy(CJointedModel *this)
{
  CPhysCollisionModel *m_pCollisionList; // esi
  CJointConstraint *i; // esi
  CPhysCollisionModel *v4; // esi
  int v5; // ebx
  int *p_physicsBoneIndex; // eax
  unsigned int v7; // ecx
  int v8; // edi
  int GlobalBone; // eax
  int *v10; // edx
  int parent; // eax
  int v12; // eax
  int physicsBoneIndex; // ecx

  m_pCollisionList = this->m_pCollisionList;
  if ( m_pCollisionList != nullptr )
  {
    CJointedModel::FixBoneList(this);
    do
    {
      m_pCollisionList->m_parent = CJointedModel::FixParent(this, pParentName: m_pCollisionList->m_parent);
      m_pCollisionList = m_pCollisionList->m_pNext;
    }
    while ( m_pCollisionList != nullptr );
    CJointedModel::SortCollisionList(this);
    for ( i = g_JointedModel.m_pConstraintList; i != nullptr; i = i->m_pNext )
      i->m_pJointName = CJointedModel::FixParent(this, pParentName: i->m_pJointName);
    v4 = this->m_pCollisionList;
    v5 = g_numbones;
    if ( (int)g_numbones > 0 )
    {
      p_physicsBoneIndex = &g_bonetable[0].physicsBoneIndex;
      v7 = g_numbones;
      do
      {
        *p_physicsBoneIndex = -1;
        p_physicsBoneIndex += 116;
        --v7;
      }
      while ( v7 != 0 );
    }
    v8 = 0;
    if ( v4 != nullptr )
    {
      do
      {
        GlobalBone = findGlobalBone(name: v4->m_name);
        if ( GlobalBone >= 0 )
          g_bonetable[GlobalBone].physicsBoneIndex = v8;
        v4 = v4->m_pNext;
        ++v8;
      }
      while ( v4 != nullptr );
      v5 = g_numbones;
    }
    if ( v5 > 0 )
    {
      v10 = &g_bonetable[0].physicsBoneIndex;
      do
      {
        if ( *v10 < 0 )
        {
          parent = *(v10 - 74);
          if ( parent < 0 )
          {
LABEL_20:
            *v10 = 0;
          }
          else
          {
            while ( 1 )
            {
              v12 = parent;
              physicsBoneIndex = g_bonetable[v12].physicsBoneIndex;
              if ( physicsBoneIndex >= 0 )
                break;
              parent = g_bonetable[v12].parent;
              if ( parent < 0 )
                goto LABEL_20;
            }
            *v10 = physicsBoneIndex;
          }
        }
        v10 += 116;
        --v5;
      }
      while ( v5 != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004031F0
// Name: public: CPlainAutoPtr<class CP4File>::~CPlainAutoPtr<class CP4File>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlainAutoPtr<CP4File>::~CPlainAutoPtr<CP4File>(CPlainAutoPtr<CP4File> *this)
{
  CP4File *m_p; // ecx

  m_p = this->m_p;
  this->m_p = nullptr;
  if ( m_p != nullptr )
    ((void (__thiscall *)(CP4File *, int))m_p->dtr_CP4File)(a1: m_p, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x00403210
// Name: void CollisionModel_Write(long)
// Source: json
//------------------------------------------------------------------------------
void __usercall CollisionModel_Write(int a1@<edi>, int checkSum)
{
  CPhysCollisionModel *m_pCollisionList; // ebx
  int v3; // eax
  char v4; // cl
  char *v5; // eax
  char v6; // cl
  char *m_pOverrideName; // eax
  char *v8; // edx
  unsigned int v9; // eax
  char *v10; // edi
  char v11; // cl
  CPhysCollisionModel *v12; // eax
  float i; // xmm0_4
  float v14; // xmm2_4
  CP4File *v15; // edi
  bool (__thiscall *Edit)(CP4File *); // eax
  _iobuf *v17; // esi
  CPhysCollisionModel *v18; // eax
  CPhysCollisionModel *j; // edi
  char *v20; // ebx
  CPhysCollisionModel *v21; // edi
  int v22; // ebx
  float v23; // xmm1_4
  float v24; // xmm0_4
  const char *SurfaceProp; // eax
  float m_dragCoefficient; // xmm0_4
  float m_massBias; // xmm0_4
  CPhysCollisionModel *v28; // eax
  int parentIndex; // edi
  int childIndex; // ebx
  collisionpair_t *k; // edi
  int v32; // eax
  int obj0; // ecx
  int m; // edi
  char buf[512]; // [esp+24h] [ebp-4D4h] BYREF
  char filename[512]; // [esp+224h] [ebp-2D4h] BYREF
  constraint_ragdollparams_t ragdoll; // [esp+424h] [ebp-D4h] BYREF
  phyheader_s header; // [esp+4D8h] [ebp-20h] BYREF
  CPlainAutoPtr<CP4File> spFile; // [esp+4E8h] [ebp-10h]
  float volume; // [esp+4ECh] [ebp-Ch]
  char terminator; // [esp+4F3h] [ebp-5h] BYREF
  int size; // [esp+4F4h] [ebp-4h] BYREF

  m_pCollisionList = g_JointedModel.m_pCollisionList;
  if ( g_JointedModel.m_pCollisionList != nullptr )
  {
    v3 = 0;
    do
    {
      v4 = gamedir[v3];
      filename[v3++] = v4;
    }
    while ( v4 != 0 );
    v5 = &buf[511];
    do
      v6 = *++v5;
    while ( v6 != 0 );
    strcpy(v5, "models/");
    m_pOverrideName = g_JointedModel.m_pOverrideName;
    if ( g_JointedModel.m_pOverrideName == nullptr )
      m_pOverrideName = g_outname;
    v8 = m_pOverrideName;
    v9 = strlen(m_pOverrideName) + 1;
    v10 = &buf[511];
    do
      v11 = *++v10;
    while ( v11 != 0 );
    qmemcpy(v10, v8, v9);
    v12 = m_pCollisionList;
    for ( i = 0.0; v12 != nullptr; i = v14 + i )
    {
      v14 = v12->m_massBias * v12->m_volume;
      v12 = v12->m_pNext;
    }
    volume = i;
    if ( i <= 0.0 )
    {
      i = 1.0;
      volume = 1.0;
    }
    if ( !g_quiet )
      printf(format: "Collision model volume %.2f in^3\n", i);
    V_SetExtension(path: filename, extension: ".phy", pathStringLength: 512);
    v15 = CP4Factory::AccessFile(this: g_p4factory, szFilename: filename);
    Edit = v15->Edit;
    spFile.m_p = v15;
    ((void (__thiscall *)(CP4File *, int))Edit)(a1: v15, a2: a1);
    v17 = fopen(file: filename, mode: "wb");
    if ( v17 != nullptr )
    {
      v18 = g_JointedModel.m_pCollisionList;
      header.size = 16;
      header.id = 0;
      header.checkSum = checkSum;
      for ( header.solidCount = 0; v18 != nullptr; v18 = v18->m_pNext )
        ++header.solidCount;
      fwrite(buffer: &header, size: 0x10u, count: 1u, stream: v17);
      for ( j = g_JointedModel.m_pCollisionList; j != nullptr; j = j->m_pNext )
      {
        size = physcollision->CollideSize(this: physcollision, a2: j->m_pCollisionData);
        fwrite(buffer: &size, size: 4u, count: 1u, stream: v17);
        v20 = (char *)MemAlloc_Alloc(nSize: size);
        physcollision->CollideWrite(this: physcollision, a2: v20, a3: j->m_pCollisionData, a4: false);
        fwrite(buffer: v20, size, count: 1u, stream: v17);
        free(pMem: v20);
      }
      v21 = g_JointedModel.m_pCollisionList;
      v22 = 0;
      if ( g_JointedModel.m_pCollisionList != nullptr )
      {
        v23 = 1.0 / volume;
        for ( volume = 1.0 / volume; ; v23 = volume )
        {
          v24 = (float)((float)(v21->m_volume * v21->m_massBias) * v23) * g_JointedModel.m_totalMass;
          v21->m_mass = v24;
          if ( v24 < 1.0 )
            v21->m_mass = 1.0;
          fprintf(str: v17, format: "solid {\n");
          fprintf(str: v17, format: "\"%s\" \"%d\"\n", "index", v22);
          fprintf(str: v17, format: "\"%s\" \"%s\"\n", "name", v21->m_name);
          if ( v21->m_parent != nullptr )
            fprintf(str: v17, format: "\"%s\" \"%s\"\n", "parent", v21->m_parent);
          fprintf(str: v17, format: "\"%s\" \"%f\"\n", "mass", v21->m_mass);
          SurfaceProp = GetSurfaceProp(pJointName: v21->m_name);
          fprintf(str: v17, format: "\"%s\" \"%s\"\n", "surfaceprop", SurfaceProp);
          fprintf(str: v17, format: "\"%s\" \"%f\"\n", "damping", v21->m_damping);
          fprintf(str: v17, format: "\"%s\" \"%f\"\n", "rotdamping", v21->m_rotdamping);
          m_dragCoefficient = v21->m_dragCoefficient;
          if ( m_dragCoefficient != -1.0 )
            fprintf(str: v17, format: "\"%s\" \"%f\"\n", "drag", m_dragCoefficient);
          fprintf(str: v17, format: "\"%s\" \"%f\"\n", "inertia", v21->m_inertia);
          fprintf(str: v17, format: "\"%s\" \"%f\"\n", "volume", v21->m_volume);
          m_massBias = v21->m_massBias;
          if ( m_massBias != 1.0 )
            fprintf(str: v17, format: "\"%s\" \"%f\"\n", "massbias", m_massBias);
          fprintf(str: v17, format: "}\n");
          v21 = v21->m_pNext;
          ++v22;
          if ( v21 == nullptr )
            break;
        }
      }
      v28 = g_JointedModel.m_pCollisionList;
      size = (int)g_JointedModel.m_pCollisionList;
      if ( g_JointedModel.m_pCollisionList != nullptr )
      {
        while ( 1 )
        {
          if ( v28->m_parent != nullptr )
          {
            BuildRagdollConstraint(pPhys: v28, &ragdoll);
            parentIndex = ragdoll.parentIndex;
            childIndex = ragdoll.childIndex;
            if ( ragdoll.parentIndex != ragdoll.childIndex )
            {
              fprintf(str: v17, format: "ragdollconstraint {\n");
              fprintf(str: v17, format: "\"%s\" \"%d\"\n", "parent", parentIndex);
              fprintf(str: v17, format: "\"%s\" \"%d\"\n", "child", childIndex);
              fprintf(str: v17, format: "\"%s\" \"%f\"\n", "xmin", ragdoll.axes[0].minRotation);
              fprintf(str: v17, format: "\"%s\" \"%f\"\n", "xmax", ragdoll.axes[0].maxRotation);
              fprintf(str: v17, format: "\"%s\" \"%f\"\n", "xfriction", ragdoll.axes[0].torque);
              fprintf(str: v17, format: "\"%s\" \"%f\"\n", "ymin", ragdoll.axes[1].minRotation);
              fprintf(str: v17, format: "\"%s\" \"%f\"\n", "ymax", ragdoll.axes[1].maxRotation);
              fprintf(str: v17, format: "\"%s\" \"%f\"\n", "yfriction", ragdoll.axes[1].torque);
              fprintf(str: v17, format: "\"%s\" \"%f\"\n", "zmin", ragdoll.axes[2].minRotation);
              fprintf(str: v17, format: "\"%s\" \"%f\"\n", "zmax", ragdoll.axes[2].maxRotation);
              fprintf(str: v17, format: "\"%s\" \"%f\"\n", "zfriction", ragdoll.axes[2].torque);
              fprintf(str: v17, format: "}\n");
            }
            v28 = (CPhysCollisionModel *)size;
          }
          size = (int)v28->m_pNext;
          if ( size == 0 )
            break;
          v28 = (CPhysCollisionModel *)size;
        }
      }
      if ( g_JointedModel.m_noSelfCollisions )
      {
        fprintf(str: v17, format: "collisionrules {\n");
        fprintf(str: v17, format: "\"%s\" \"%d\"\n", "selfcollisions", 0);
        fprintf(str: v17, format: "}\n");
      }
      else if ( g_JointedModel.m_pCollisionPairs != nullptr )
      {
        fprintf(str: v17, format: "collisionrules {\n");
        for ( k = g_JointedModel.m_pCollisionPairs; k != nullptr; k = k->pNext )
        {
          k->obj0 = CJointedModel::CollisionIndex(this: &g_JointedModel, pName: k->pName0);
          v32 = CJointedModel::CollisionIndex(this: &g_JointedModel, pName: k->pName1);
          obj0 = k->obj0;
          k->obj1 = v32;
          if ( obj0 < 0 || v32 < 0 || obj0 == v32 )
            MdlWarning(fmt: "Invalid collision pair (%s, %s)\n", k->pName0, k->pName1);
          else
            fprintf(str: v17, format: "\"%s\" \"%d,%d\"\n", "collisionpair", obj0, v32);
        }
        fprintf(str: v17, format: "}\n");
      }
      if ( g_JointedModel.m_bHasAnimatedFriction )
      {
        fprintf(str: v17, format: "animatedfriction {\n");
        fprintf(str: v17, format: "\"%s\" \"%f\"\n", "animfrictionmin", (float)g_JointedModel.m_iMinAnimatedFriction);
        fprintf(str: v17, format: "\"%s\" \"%f\"\n", "animfrictionmax", (float)g_JointedModel.m_iMaxAnimatedFriction);
        fprintf(str: v17, format: "\"%s\" \"%f\"\n", "animfrictiontimein", g_JointedModel.m_flFrictionTimeIn);
        fprintf(str: v17, format: "\"%s\" \"%f\"\n", "animfrictiontimeout", g_JointedModel.m_flFrictionTimeOut);
        fprintf(str: v17, format: "\"%s\" \"%f\"\n", "animfrictiontimehold", g_JointedModel.m_flFrictionTimeHold);
        fprintf(str: v17, format: "}\n");
      }
      fprintf(str: v17, format: "editparams {\n");
      fprintf(str: v17, format: "\"%s\" \"%s\"\n", "rootname", g_JointedModel.m_rootName);
      fprintf(str: v17, format: "\"%s\" \"%f\"\n", "totalmass", g_JointedModel.m_totalMass);
      if ( g_JointedModel.m_allowConcave )
        fprintf(str: v17, format: "\"%s\" \"%d\"\n", "concave", 1);
      for ( m = 0; m < g_JointedModel.m_mergeList.m_Size; ++m )
      {
        V_snprintf(
          pDest: buf,
          maxLen: 512,
          pFormat: "%s,%s",
          g_JointedModel.m_mergeList.m_Memory.m_pMemory[m].pParent,
          g_JointedModel.m_mergeList.m_Memory.m_pMemory[m].pChild);
        fprintf(str: v17, format: "\"%s\" \"%s\"\n", "jointmerge", buf);
      }
      fprintf(str: v17, format: "}\n");
      terminator = 0;
      if ( g_JointedModel.m_textCommands.m_Size != 0 )
        fwrite(
          buffer: g_JointedModel.m_textCommands.m_Memory.m_pMemory,
          size: g_JointedModel.m_textCommands.m_Size,
          count: 1u,
          stream: v17);
      fwrite(buffer: &terminator, size: 1u, count: 1u, stream: v17);
      fclose(stream: v17);
      spFile.m_p->Add(this: spFile.m_p);
      ((void (__thiscall *)(CP4File *, int))spFile.m_p->dtr_CP4File)(a1: spFile.m_p, a2: 1);
    }
    else
    {
      MdlWarning(fmt: "Error writing %s!!!\n", filename);
      ((void (__thiscall *)(CP4File *, int))v15->dtr_CP4File)(a1: v15, a2: 1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403B80
// Name: public: void CJointedModel::AddText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CJointedModel::AddText(CJointedModel *this, char *pText)
{
  signed int v2; // edi
  int m_Size; // ebx
  CUtlMemory<unsigned char,int> *p_m_textCommands; // esi
  int m_nAllocationCount; // eax
  unsigned __int8 *m_pMemory; // ecx
  int v7; // eax

  v2 = strlen(pText);
  m_Size = this->m_textCommands.m_Size;
  p_m_textCommands = (CUtlMemory<unsigned char,int> *)&this->m_textCommands;
  if ( v2 != 0 )
  {
    m_nAllocationCount = this->m_textCommands.m_Memory.m_nAllocationCount;
    if ( m_Size + v2 > m_nAllocationCount )
      CUtlMemory<char,int>::Grow(this: p_m_textCommands, num: v2 + m_Size - m_nAllocationCount);
    p_m_textCommands[1].m_pMemory += v2;
    m_pMemory = p_m_textCommands->m_pMemory;
    v7 = (int)&p_m_textCommands[1].m_pMemory[-m_Size - v2];
    p_m_textCommands[1].m_nAllocationCount = (int)p_m_textCommands->m_pMemory;
    if ( v7 > 0 && v2 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + v2], src: &m_pMemory[m_Size], count: v7);
  }
  memcpy(dst: &p_m_textCommands->m_pMemory[m_Size], src: (unsigned __int8 *)pText, count: v2);
}

//------------------------------------------------------------------------------
// Address: 0x00403C10
// Name: public: void CJointedModel::AddMergeCommand(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CJointedModel::AddMergeCommand(CJointedModel *this, const char *pParent, const char *pChild)
{
  int m_nAllocationCount; // eax
  CUtlMemory<CDmeMesh::FaceSet_t,int> *p_m_mergeList; // esi
  int m_Size; // edi
  CDmeMesh::FaceSet_t *m_pMemory; // ecx
  int v7; // eax
  char *v8; // eax
  char *v9; // eax

  m_nAllocationCount = this->m_mergeList.m_Memory.m_nAllocationCount;
  p_m_mergeList = (CUtlMemory<CDmeMesh::FaceSet_t,int> *)&this->m_mergeList;
  m_Size = this->m_mergeList.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<mergelist_t,int>::Grow(this: p_m_mergeList, num: m_Size - m_nAllocationCount + 1);
  ++p_m_mergeList[1].m_pMemory;
  m_pMemory = p_m_mergeList->m_pMemory;
  v7 = (int)p_m_mergeList[1].m_pMemory - m_Size - 1;
  p_m_mergeList[1].m_nAllocationCount = (int)p_m_mergeList->m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 8 * v7);
  if ( pParent != nullptr
    && (v8 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pParent) + 1)) != nullptr )
  {
    strcpy(v8, pParent);
  }
  else
  {
    v8 = nullptr;
  }
  p_m_mergeList->m_pMemory[m_Size].m_pMesh = (IMesh *)v8;
  if ( pChild != nullptr )
  {
    v9 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pChild) + 1);
    if ( v9 != nullptr )
    {
      strcpy(v9, pChild);
      *(_DWORD *)&p_m_mergeList->m_pMemory[m_Size].m_bBuilt = v9;
    }
    else
    {
      *(_DWORD *)&p_m_mergeList->m_pMemory[m_Size].m_bBuilt = 0;
    }
  }
  else
  {
    *(_DWORD *)&p_m_mergeList->m_pMemory[m_Size].m_bBuilt = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403D30
// Name: void BuildConvexListByVertID(struct s_source_t __near *,class CUtlVector<struct convexlist_t,class CUtlMemory<struct convexlist_t,int>> __near &,class CUtlVector<int,class CUtlMemory<int,int>> __near &,class CUtlVector<int,class CUtlMemory<int,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildConvexListByVertID(
        s_source_t *pmodel,
        CUtlMemory<CDmeMesh::FaceSet_t,int> *convexList,
        CUtlVector<int,CUtlMemory<int,int> > *vertList,
        CUtlVector<int,CUtlMemory<int,int> > *vertID)
{
  s_source_t *v4; // edi
  int numvertices; // eax
  int v6; // ebx
  CUtlVector<int,CUtlMemory<int,int> > *v7; // ecx
  int v8; // edx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v12; // eax
  int *v13; // eax
  int v14; // edi
  int v15; // eax
  convexlist_t *v16; // ecx
  int v17; // eax
  convexlist_t *v18; // edi
  int current; // [esp+8h] [ebp-10h]
  int current_4; // [esp+Ch] [ebp-Ch]
  int v21; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]

  v4 = pmodel;
  numvertices = pmodel->numvertices;
  v6 = 0;
  for ( i = 0; v6 < numvertices; i = v6 )
  {
    v7 = vertID;
    v8 = vertID->m_Memory.m_pMemory[v6];
    v21 = v8;
    if ( v8 >= 0 && v8 <= v4->numfaces )
    {
      current = vertList->m_Size;
      current_4 = 0;
      if ( v6 < numvertices )
      {
        do
        {
          if ( v7->m_Memory.m_pMemory[v6] == v8 )
          {
            m_Size = vertList->m_Size;
            m_nAllocationCount = vertList->m_Memory.m_nAllocationCount;
            if ( m_Size + 1 > m_nAllocationCount )
              CUtlMemory<IDmFormatUpdater *,int>::Grow(
                this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)vertList,
                num: m_Size - m_nAllocationCount + 1);
            ++vertList->m_Size;
            m_pMemory = vertList->m_Memory.m_pMemory;
            v12 = vertList->m_Size - m_Size - 1;
            vertList->m_pElements = vertList->m_Memory.m_pMemory;
            if ( v12 > 0 )
              _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v12);
            v13 = &vertList->m_Memory.m_pMemory[m_Size];
            if ( v13 != nullptr )
              *v13 = v6;
            v7 = vertID;
            ++current_4;
            vertID->m_Memory.m_pMemory[v6] = -1;
            v8 = v21;
          }
          ++v6;
        }
        while ( v6 < pmodel->numvertices );
      }
      v14 = (int)convexList[1].m_pMemory;
      v15 = convexList->m_nAllocationCount;
      if ( v14 + 1 > v15 )
        CUtlMemory<mergelist_t,int>::Grow(this: convexList, num: v14 - v15 + 1);
      ++convexList[1].m_pMemory;
      v16 = (convexlist_t *)convexList->m_pMemory;
      v17 = (int)convexList[1].m_pMemory - v14 - 1;
      convexList[1].m_nAllocationCount = (int)convexList->m_pMemory;
      if ( v17 > 0 )
        _V_memmove(dest: &v16[v14 + 1], src: &v16[v14], count: 8 * v17);
      v6 = i;
      v18 = (convexlist_t *)&convexList->m_pMemory[v14];
      if ( v18 != nullptr )
      {
        v18->firstVertIndex = current;
        v18->numVertIndex = current_4;
      }
    }
    v4 = pmodel;
    numvertices = pmodel->numvertices;
    ++v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403E70
// Name: bool BuildConvexesForLists(class CUtlVector<class CPhysConvex __near *,class CUtlMemory<class CPhysConvex __near *,int>> __near &,class CUtlVector<struct convexlist_t,class CUtlMemory<struct convexlist_t,int>> const __near &,class CUtlVector<int,class CUtlMemory<int,int>> const __near &,class CUtlVector<class Vector,class CUtlMemory<class Vector,int>> const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl BuildConvexesForLists(
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *convexOut,
        const CUtlVector<convexlist_t,CUtlMemory<convexlist_t,int> > *convexList,
        const CUtlVector<int,CUtlMemory<int,int> > *vertList,
        const CUtlVector<Vector,CUtlMemory<Vector,int> > *worldspaceVerts,
        bool bRemove2d)
{
  const CUtlVector<convexlist_t,CUtlMemory<convexlist_t,int> > *v5; // edx
  int v6; // ecx
  Vector **v7; // esi
  bool result; // al
  const convexlist_t *v9; // edx
  int m_Size; // esi
  int v11; // ebx
  int v12; // edi
  Vector **m_pMemory; // ecx
  Vector **v14; // eax
  Vector **v15; // edi
  struct CPhysConvex *v16; // ebx
  int v17; // esi
  int m_nAllocationCount; // eax
  struct CPhysConvex **v19; // ecx
  int v20; // eax
  struct CPhysConvex **v21; // esi
  CUtlVector<Vector *,CUtlMemory<Vector *,int> > vertsThisConvex; // [esp+14h] [ebp-24h] BYREF
  Vector *pVert; // [esp+28h] [ebp-10h]
  int i; // [esp+2Ch] [ebp-Ch]
  const convexlist_t *elem; // [esp+30h] [ebp-8h]
  bool bValid; // [esp+37h] [ebp-1h]
  int savedregs; // [esp+38h] [ebp+0h] BYREF

  v5 = convexList;
  v6 = 0;
  v7 = nullptr;
  result = true;
  bValid = true;
  memset(&vertsThisConvex, 0, sizeof(vertsThisConvex));
  i = 0;
  if ( convexList->m_Size > 0 )
  {
    while ( 1 )
    {
      v9 = &v5->m_Memory.m_pMemory[v6];
      m_Size = 0;
      v11 = 0;
      elem = v9;
      vertsThisConvex.m_Size = 0;
      if ( v9->numVertIndex <= 0 )
        goto LABEL_21;
      do
      {
        pVert = &worldspaceVerts->m_Memory.m_pMemory[vertList->m_Memory.m_pMemory[v11 + v9->firstVertIndex]];
        v12 = m_Size;
        if ( m_Size + 1 > vertsThisConvex.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&vertsThisConvex,
            num: m_Size - vertsThisConvex.m_Memory.m_nAllocationCount + 1);
          m_Size = vertsThisConvex.m_Size;
          v9 = elem;
        }
        m_pMemory = vertsThisConvex.m_Memory.m_pMemory;
        vertsThisConvex.m_Size = ++m_Size;
        vertsThisConvex.m_pElements = vertsThisConvex.m_Memory.m_pMemory;
        if ( m_Size - v12 - 1 > 0 )
        {
          _V_memmove(
            dest: &vertsThisConvex.m_Memory.m_pMemory[v12 + 1],
            src: &vertsThisConvex.m_Memory.m_pMemory[v12],
            count: 4 * (m_Size - v12 - 1));
          v9 = elem;
          m_pMemory = vertsThisConvex.m_Memory.m_pMemory;
        }
        v14 = &m_pMemory[v12];
        if ( v14 != nullptr )
          *v14 = pVert;
        ++v11;
      }
      while ( v11 < v9->numVertIndex );
      if ( m_Size > 2 )
      {
        v15 = vertsThisConvex.m_Memory.m_pMemory;
        if ( IsApproximatelyPlanar(
               a1: COERCE_FLOAT(&savedregs),
               verts: vertsThisConvex.m_Memory.m_pMemory,
               vertCount: m_Size,
               epsilon: 0.5) == 0 )
          goto LABEL_14;
        if ( !bRemove2d )
          break;
      }
LABEL_21:
      v5 = convexList;
      v6 = i + 1;
      i = v6;
      if ( v6 >= convexList->m_Size )
      {
        result = bValid;
        v7 = vertsThisConvex.m_Memory.m_pMemory;
        goto LABEL_23;
      }
    }
    MdlWarning(fmt: "Model has 2-dimensional geometry (less than %.3f inches thick on any axis)!!!\n", 0.5);
    bValid = false;
LABEL_14:
    v16 = physcollision->ConvexFromVerts(this: physcollision, a2: v15, a3: m_Size);
    if ( v16 != nullptr )
    {
      physcollision->SetConvexGameData(this: physcollision, a2: v16, a3: 0);
      v17 = (int)convexOut[1].m_pMemory;
      m_nAllocationCount = convexOut->m_nAllocationCount;
      if ( v17 + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: convexOut, num: v17 - m_nAllocationCount + 1);
      ++convexOut[1].m_pMemory;
      v19 = (struct CPhysConvex **)convexOut->m_pMemory;
      v20 = (int)convexOut[1].m_pMemory - v17 - 1;
      convexOut[1].m_nAllocationCount = (int)convexOut->m_pMemory;
      if ( v20 > 0 )
        _V_memmove(dest: &v19[v17 + 1], src: &v19[v17], count: 4 * v20);
      v21 = (struct CPhysConvex **)&convexOut->m_pMemory[v17];
      if ( v21 != nullptr )
        *v21 = v16;
    }
    goto LABEL_21;
  }
LABEL_23:
  if ( vertsThisConvex.m_Memory.m_nGrowSize >= 0 && v7 != nullptr )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v7);
    return bValid;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00404070
// Name: void ParseCollisionCommands(class CJointedModel __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ParseCollisionCommands(CJointedModel *joints)
{
  int v1; // eax
  char v2; // cl
  int v3; // esi
  unsigned __int8 *v4; // edi
  int v5; // esi
  unsigned __int8 *v6; // edi
  int v7; // esi
  unsigned __int8 *v8; // edi
  int v9; // esi
  unsigned __int8 *v10; // edi
  char *p_pFriction; // esi
  CPhysCollisionModel *v12; // eax
  CPhysCollisionModel *v13; // eax
  CPhysCollisionModel *v14; // eax
  CPhysCollisionModel *inited; // eax
  char dest[256]; // [esp+0h] [ebp-1214h] BYREF
  char pChild[256]; // [esp+100h] [ebp-1114h] BYREF
  char nptr[256]; // [esp+200h] [ebp-1014h] BYREF
  char pLimitMin[256]; // [esp+300h] [ebp-F14h] BYREF
  char pLimitMax[256]; // [esp+400h] [ebp-E14h] BYREF
  char pFriction; // [esp+500h] [ebp-D14h] BYREF
  char s1[512]; // [esp+1000h] [ebp-214h] BYREF
  Vector centerOfMass; // [esp+1200h] [ebp-14h] BYREF
  float v24; // [esp+120Ch] [ebp-8h]
  float v25; // [esp+1210h] [ebp-4h]

  while ( GetToken(crossline: 1) != 0 )
  {
    if ( strcmp(token, "}") == 0 )
      break;
    v1 = 0;
    do
    {
      v2 = token[v1];
      s1[v1++] = v2;
    }
    while ( v2 != 0 );
    if ( _V_stricmp(s1, s2: "$mass") != 0 )
    {
      if ( _V_stricmp(s1, s2: "$automass") != 0 )
      {
        if ( _V_stricmp(s1, s2: "$inertia") != 0 )
        {
          if ( _V_stricmp(s1, s2: "$damping") != 0 )
          {
            if ( _V_stricmp(s1, s2: "$rotdamping") != 0 )
            {
              if ( _V_stricmp(s1, s2: "$drag") != 0 )
              {
                if ( _V_stricmp(s1, s2: "$rollingDrag") != 0 )
                {
                  if ( _V_stricmp(s1, s2: "$maxconvexpieces") != 0 )
                  {
                    if ( _V_stricmp(s1, s2: "$remove2d") != 0 )
                    {
                      if ( _V_stricmp(s1, s2: "$concaveperjoint") != 0 )
                      {
                        if ( _V_stricmp(s1, s2: "$weldposition") != 0 )
                        {
                          if ( _V_stricmp(s1, s2: "$weldnormal") != 0 )
                          {
                            if ( _V_stricmp(s1, s2: "$concave") != 0 )
                            {
                              if ( _V_stricmp(s1, s2: "$masscenter") != 0 )
                              {
                                if ( _V_stricmp(s1, s2: "$jointskip") != 0 )
                                {
                                  if ( _V_stricmp(s1, s2: "$jointmerge") != 0 )
                                  {
                                    if ( _V_stricmp(s1, s2: "$rootbone") != 0 )
                                    {
                                      if ( _V_stricmp(s1, s2: "$jointconstrain") != 0 )
                                      {
                                        if ( _V_stricmp(s1, s2: "$jointinertia") != 0 )
                                        {
                                          if ( _V_stricmp(s1, s2: "$jointdamping") != 0 )
                                          {
                                            if ( _V_stricmp(s1, s2: "$jointrotdamping") != 0 )
                                            {
                                              if ( _V_stricmp(s1, s2: "$jointmassbias") != 0 )
                                              {
                                                if ( _V_stricmp(s1, s2: "$noselfcollisions") != 0 )
                                                {
                                                  if ( _V_stricmp(s1, s2: "$jointcollide") != 0 )
                                                  {
                                                    if ( _V_stricmp(s1, s2: "$animatedfriction") != 0 )
                                                    {
                                                      if ( _V_stricmp(s1, s2: "$assumeworldspace") != 0 )
                                                        MdlWarning(fmt: "Unknown command %s in collision series\n", s1);
                                                      else
                                                        joints->m_bAssumeWorldspace = true;
                                                    }
                                                    else if ( ReadArgs(pArgs: (char (*)[256])dest, maxCount: 5) == 5 )
                                                    {
                                                      CCmd_JoinAnimatedFriction(
                                                        joints,
                                                        pMinFriction: dest,
                                                        pMaxFriction: pChild,
                                                        pTimeIn: nptr,
                                                        pTimeHold: pLimitMin,
                                                        pTimeOut: pLimitMax);
                                                    }
                                                  }
                                                  else
                                                  {
                                                    ReadArgs(pArgs: (char (*)[256])dest, maxCount: 2);
                                                    CJointedModel::AppendCollisionPair(
                                                      this: joints,
                                                      pName0: dest,
                                                      pName1: pChild);
                                                  }
                                                }
                                                else
                                                {
                                                  joints->m_noSelfCollisions = true;
                                                }
                                              }
                                              else
                                              {
                                                ReadArgs(pArgs: (char (*)[256])dest, maxCount: 2);
                                                v25 = atof(nptr: pChild);
                                                inited = CJointedModel::InitCollisionModel(
                                                           this: joints,
                                                           pJointName: dest);
                                                if ( inited != nullptr )
                                                  inited->m_massBias = v25;
                                              }
                                            }
                                            else
                                            {
                                              ReadArgs(pArgs: (char (*)[256])dest, maxCount: 2);
                                              v25 = atof(nptr: pChild);
                                              v14 = CJointedModel::InitCollisionModel(this: joints, pJointName: dest);
                                              if ( v14 != nullptr )
                                                v14->m_rotdamping = v25;
                                            }
                                          }
                                          else
                                          {
                                            ReadArgs(pArgs: (char (*)[256])dest, maxCount: 2);
                                            v25 = atof(nptr: pChild);
                                            v13 = CJointedModel::InitCollisionModel(this: joints, pJointName: dest);
                                            if ( v13 != nullptr )
                                              v13->m_damping = v25;
                                          }
                                        }
                                        else
                                        {
                                          ReadArgs(pArgs: (char (*)[256])dest, maxCount: 2);
                                          v25 = atof(nptr: pChild);
                                          v12 = CJointedModel::InitCollisionModel(this: joints, pJointName: dest);
                                          if ( v12 != nullptr )
                                            v12->m_inertia = v25;
                                        }
                                      }
                                      else
                                      {
                                        p_pFriction = &pFriction;
                                        if ( ReadArgs(pArgs: (char (*)[256])dest, maxCount: 6) < 6 )
                                          p_pFriction = "1.0";
                                        CCmd_JointConstrain(
                                          joints,
                                          pJointName: dest,
                                          pJointAxis: pChild,
                                          pJointType: nptr,
                                          pLimitMin,
                                          pLimitMax,
                                          pFriction: p_pFriction);
                                      }
                                    }
                                    else
                                    {
                                      ReadArgs(pArgs: (char (*)[256])dest, maxCount: 1);
                                      CCmd_JointRoot(joints, pBone: dest);
                                    }
                                  }
                                  else
                                  {
                                    ReadArgs(pArgs: (char (*)[256])dest, maxCount: 2);
                                    CCmd_JointMerge(joints, pParent: dest, pChild);
                                  }
                                }
                                else
                                {
                                  ReadArgs(pArgs: (char (*)[256])dest, maxCount: 1);
                                  CCmd_JointSkip(joints, pName: dest);
                                }
                              }
                              else
                              {
                                ReadArgs(pArgs: (char (*)[256])dest, maxCount: 3);
                                v25 = atof(nptr);
                                v24 = atof(nptr: pChild);
                                centerOfMass.x = atof(nptr: dest);
                                centerOfMass.y = v24;
                                centerOfMass.z = v25;
                                CJointedModel::ForceMassCenter(this: joints, &centerOfMass);
                              }
                            }
                            else
                            {
                              joints->m_allowConcave = true;
                            }
                          }
                          else
                          {
                            ReadArgs(pArgs: (char (*)[256])dest, maxCount: 1);
                            g_WeldNormalEpsilon = atof(nptr: dest);
                          }
                        }
                        else
                        {
                          ReadArgs(pArgs: (char (*)[256])dest, maxCount: 1);
                          g_WeldVertEpsilon = atof(nptr: dest);
                        }
                      }
                      else
                      {
                        joints->m_allowConcaveJoints = true;
                      }
                    }
                    else
                    {
                      joints->m_remove2d = true;
                    }
                  }
                  else
                  {
                    ReadArgs(pArgs: (char (*)[256])dest, maxCount: 1);
                    joints->m_maxConvex = atoi(nptr: dest);
                  }
                }
                else
                {
                  ReadArgs(pArgs: (char (*)[256])dest, maxCount: 1);
                }
              }
              else
              {
                ReadArgs(pArgs: (char (*)[256])dest, maxCount: 1);
                joints->m_defaultDrag = atof(nptr: dest);
              }
            }
            else
            {
              v9 = 0;
              v10 = (unsigned __int8 *)dest;
              do
              {
                if ( TokenAvailable() == 0 )
                  break;
                GetToken(crossline: 0);
                strncpy(dest: v10, source: (unsigned __int8 *)token, count: 0x100u);
                ++v9;
                v10 += 256;
              }
              while ( v9 < 1 );
              joints->m_defaultRotdamping = atof(nptr: dest);
            }
          }
          else
          {
            v7 = 0;
            v8 = (unsigned __int8 *)dest;
            do
            {
              if ( TokenAvailable() == 0 )
                break;
              GetToken(crossline: 0);
              strncpy(dest: v8, source: (unsigned __int8 *)token, count: 0x100u);
              ++v7;
              v8 += 256;
            }
            while ( v7 < 1 );
            joints->m_defaultDamping = atof(nptr: dest);
          }
        }
        else
        {
          v5 = 0;
          v6 = (unsigned __int8 *)dest;
          do
          {
            if ( TokenAvailable() == 0 )
              break;
            GetToken(crossline: 0);
            strncpy(dest: v6, source: (unsigned __int8 *)token, count: 0x100u);
            ++v5;
            v6 += 256;
          }
          while ( v5 < 1 );
          joints->m_defaultInertia = atof(nptr: dest);
        }
      }
      else
      {
        joints->m_totalMass = -1.0;
      }
    }
    else
    {
      v3 = 0;
      v4 = (unsigned __int8 *)dest;
      do
      {
        if ( TokenAvailable() == 0 )
          break;
        GetToken(crossline: 0);
        strncpy(dest: v4, source: (unsigned __int8 *)token, count: 0x100u);
        ++v3;
        v4 += 256;
      }
      while ( v3 < 1 );
      joints->m_totalMass = atof(nptr: dest);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404880
// Name: void Cmd_CollisionText(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Cmd_CollisionText()
{
  int v0; // ebx
  int m_Size; // eax
  int v2; // edi
  int v3; // esi
  char *m_pMemory; // ecx
  int v5; // eax
  char *v6; // eax

  v0 = 1;
  if ( GetToken(crossline: 1) != 0 && token[0] == 123 && GetToken(crossline: 1) != 0 )
  {
    do
    {
      if ( strcmp(token, "}") == 0 )
      {
        if ( --v0 <= 0 )
          return;
        m_Size = g_JointedModel.m_textCommands.m_Size;
        v2 = g_JointedModel.m_textCommands.m_Size;
        v3 = g_JointedModel.m_textCommands.m_Size;
        if ( g_JointedModel.m_textCommands.m_Size + 3 > g_JointedModel.m_textCommands.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<char,int>::Grow(
            this: (CUtlMemory<unsigned char,int> *)&g_JointedModel.m_textCommands,
            num: g_JointedModel.m_textCommands.m_Size - g_JointedModel.m_textCommands.m_Memory.m_nAllocationCount + 3);
          m_Size = g_JointedModel.m_textCommands.m_Size;
        }
        m_pMemory = g_JointedModel.m_textCommands.m_Memory.m_pMemory;
        g_JointedModel.m_textCommands.m_Size = m_Size + 3;
        v5 = m_Size - v3;
        g_JointedModel.m_textCommands.m_pElements = g_JointedModel.m_textCommands.m_Memory.m_pMemory;
        if ( v5 > 0 )
        {
          _V_memmove(
            dest: &g_JointedModel.m_textCommands.m_Memory.m_pMemory[v3 + 3],
            src: &g_JointedModel.m_textCommands.m_Memory.m_pMemory[v3],
            count: v5);
          m_pMemory = g_JointedModel.m_textCommands.m_Memory.m_pMemory;
        }
        v6 = &m_pMemory[v2];
        *(_WORD *)v6 = *(_WORD *)asc_5F12C0;
        v6[2] = 10;
      }
      else if ( strcmp(token, "{") == 0 )
      {
        CJointedModel::AddText(this: &g_JointedModel, pText: "{");
        ++v0;
      }
      else if ( v0 <= 1 )
      {
        CJointedModel::AddText(this: &g_JointedModel, pText: token);
        CJointedModel::AddText(this: &g_JointedModel, pText: " ");
      }
      else
      {
        CJointedModel::AddText(this: &g_JointedModel, pText: "\"");
        CJointedModel::AddText(this: &g_JointedModel, pText: token);
        CJointedModel::AddText(this: &g_JointedModel, pText: "\" ");
      }
    }
    while ( GetToken(crossline: 1) != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404A20
// Name: int DoCollisionModel(bool)
// Source: json
//------------------------------------------------------------------------------
int __usercall DoCollisionModel@<eax>(int a1@<ebx>, bool separateJoints)
{
  int result; // eax
  struct CSysModule *Module; // eax
  int (__stdcall *v4)(const char *, _DWORD); // esi
  int v5; // edi
  int v6; // ebx
  int v7; // esi
  char name[512]; // [esp+0h] [ebp-200h] BYREF

  result = GetToken(crossline: 0);
  if ( result != 0 )
  {
    strncpy(dest: (unsigned __int8 *)name, source: (unsigned __int8 *)token, count: 0x200u);
    PhysicsDLLPath(pPathname: "VPHYSICS.DLL");
    Module = Sys_LoadModule(pModuleName: "vphysics.dll");
    result = (int)Sys_GetFactory(pModule: Module);
    v4 = (int (__stdcall *)(const char *, _DWORD))result;
    if ( result != 0 )
    {
      physcollision = (IPhysicsCollision *)((int (__stdcall *)(const char *))result)(a1: "VPhysicsCollision007");
      physprops = (IPhysicsSurfaceProps *)v4(a1: "VPhysicsSurfaceProps001", a2: 0);
      LoadSurfacePropsAll(a1);
      v5 = g_nummaterials;
      v6 = g_numtextures;
      result = (int)Load_Source(name, ext: "SMD", reverse: false, isActiveModel: false);
      v7 = result;
      if ( result != 0 )
      {
        if ( v5 != 0 && v6 != 0 && (v6 != g_numtextures || v5 != g_nummaterials) )
        {
          g_numtextures = v6;
          g_nummaterials = v5;
          *(_DWORD *)(result + 200972) = 0;
        }
        g_JointedModel.m_pModel = (s_source_t *)result;
        CCollisionModelSource::InitBoneMap(this: &g_JointedModel);
        g_JointedModel.m_totalVerts = *(_DWORD *)(v7 + 202128);
        if ( GetToken(crossline: 1) != 0 )
        {
          if ( strcmp(token, "{") != 0 )
          {
            UnGetToken();
            g_JointedModel.m_isJointed = separateJoints;
            return 1;
          }
          ParseCollisionCommands(joints: &g_JointedModel);
        }
        g_JointedModel.m_isJointed = separateJoints;
        return 1;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00404BC0
// Name: void BuildSingleConvexForFaceList(struct s_source_t __near *,class CUtlVector<struct convexlist_t,class CUtlMemory<struct convexlist_t,int>> __near &,class CUtlVector<int,class CUtlMemory<int,int>> __near &,class CUtlVector<struct s_face_t,class CUtlMemory<struct s_face_t,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildSingleConvexForFaceList(
        s_source_t *pmodel,
        CUtlMemory<CDmeMesh::FaceSet_t,int> *convexList,
        CUtlVector<int,CUtlMemory<int,int> > *vertList,
        const CUtlVector<s_face_t,CUtlMemory<s_face_t,int> > *faceList)
{
  s_source_t *v4; // ebx
  int *m_pMemory; // esi
  int i; // eax
  int v7; // ecx
  int v8; // edx
  s_face_t *v9; // eax
  int numvertices; // [esp-4h] [ebp-24h]
  CUtlVector<int,CUtlMemory<int,int> > vertID; // [esp+Ch] [ebp-14h] BYREF

  v4 = pmodel;
  numvertices = pmodel->numvertices;
  memset(&vertID, 0, sizeof(vertID));
  CUtlVector<s_bone_t *,CUtlMemory<s_bone_t *,int>>::InsertMultipleBefore(
    this: (CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int> > *)&vertID,
    elem: 0,
    num: numvertices);
  m_pMemory = vertID.m_Memory.m_pMemory;
  for ( i = 0; i < pmodel->numvertices; ++i )
    m_pMemory[i] = -1;
  v7 = 0;
  if ( faceList->m_Size > 0 )
  {
    v8 = 0;
    do
    {
      v9 = faceList->m_Memory.m_pMemory;
      m_pMemory[faceList->m_Memory.m_pMemory[v8].a] = 1;
      m_pMemory[v9[v8].b] = 1;
      ++v7;
      m_pMemory[v9[v8++].c] = 1;
    }
    while ( v7 < faceList->m_Size );
    v4 = pmodel;
  }
  BuildConvexListByVertID(pmodel: v4, convexList, vertList, &vertID);
  if ( vertID.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00404C90
// Name: void BuildConvexListForFaceList(struct s_source_t __near *,class CUtlVector<struct convexlist_t,class CUtlMemory<struct convexlist_t,int>> __near &,class CUtlVector<int,class CUtlMemory<int,int>> __near &,class CUtlVector<struct s_face_t,class CUtlMemory<struct s_face_t,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildConvexListForFaceList(
        s_source_t *pmodel,
        CUtlMemory<CDmeMesh::FaceSet_t,int> *convexList,
        CUtlVector<int,CUtlMemory<int,int> > *vertList,
        const CUtlVector<s_face_t,CUtlMemory<s_face_t,int> > *faceList)
{
  s_source_t *v4; // edi
  int *m_pMemory; // ebx
  int v6; // ecx
  int *v7; // esi
  int v8; // edx
  int *v9; // eax
  const CUtlVector<s_face_t,CUtlMemory<s_face_t,int> > *v10; // eax
  _QWORD *v11; // eax
  int v12; // edx
  int v13; // edi
  int v14; // eax
  int v15; // ecx
  int numvertices; // [esp-4h] [ebp-54h]
  int v17; // [esp-4h] [ebp-54h]
  CUtlVector<int,CUtlMemory<int,int> > vertID; // [esp+Ch] [ebp-44h] BYREF
  CUtlVector<int,CUtlMemory<int,int> > weldTable; // [esp+20h] [ebp-30h] BYREF
  s_face_t globalFace; // [esp+34h] [ebp-1Ch]
  int v21; // [esp+44h] [ebp-Ch]
  int i; // [esp+48h] [ebp-8h]
  int marked; // [esp+4Ch] [ebp-4h]

  v4 = pmodel;
  numvertices = pmodel->numvertices;
  memset(&weldTable, 0, sizeof(weldTable));
  CUtlVector<s_bone_t *,CUtlMemory<s_bone_t *,int>>::InsertMultipleBefore(
    this: (CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int> > *)&weldTable,
    elem: 0,
    num: numvertices);
  m_pMemory = weldTable.m_Memory.m_pMemory;
  BuildVertWeldTable(weldTable: weldTable.m_Memory.m_pMemory, pmodel);
  v17 = pmodel->numvertices;
  memset(&vertID, 0, sizeof(vertID));
  CUtlVector<s_bone_t *,CUtlMemory<s_bone_t *,int>>::InsertMultipleBefore(
    this: (CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int> > *)&vertID,
    elem: 0,
    num: v17);
  v6 = 0;
  v7 = vertID.m_Memory.m_pMemory;
  if ( pmodel->numvertices > 0 )
  {
    v8 = (char *)m_pMemory - (char *)vertID.m_Memory.m_pMemory;
    v9 = vertID.m_Memory.m_pMemory;
    v21 = (char *)m_pMemory - (char *)vertID.m_Memory.m_pMemory;
    do
    {
      if ( *(int *)((char *)v9 + v8) == v6 )
      {
        *v9 = pmodel->numfaces + 1;
        v8 = v21;
      }
      else
      {
        *v9 = -1;
      }
      ++v6;
      ++v9;
    }
    while ( v6 < pmodel->numvertices );
  }
  v10 = faceList;
  do
  {
    marked = 0;
    i = 0;
    if ( v10->m_Size <= 0 )
      break;
    v21 = 0;
    do
    {
      v11 = (_QWORD *)((char *)&v10->m_Memory.m_pMemory->a + v21);
      *(_QWORD *)&globalFace.a = *v11;
      v12 = m_pMemory[globalFace.a];
      v13 = m_pMemory[globalFace.b];
      *(_QWORD *)&globalFace.c = v11[1];
      v14 = i;
      globalFace.c = m_pMemory[globalFace.c];
      v15 = v7[v12];
      if ( i >= v15 )
        v14 = v7[v12];
      if ( v14 >= v7[v13] )
        v14 = v7[v13];
      if ( v14 >= v7[globalFace.c] )
        v14 = v7[globalFace.c];
      if ( v15 != v14 )
      {
        v7[v12] = v14;
        ++marked;
      }
      if ( v7[v13] != v14 )
      {
        ++marked;
        v7[v13] = v14;
      }
      if ( v7[globalFace.c] != v14 )
      {
        ++marked;
        v7[globalFace.c] = v14;
      }
      v10 = faceList;
      v21 += 16;
      m_pMemory = weldTable.m_Memory.m_pMemory;
      ++i;
    }
    while ( i < faceList->m_Size );
    v4 = pmodel;
  }
  while ( marked != 0 );
  BuildConvexListByVertID(pmodel: v4, convexList, vertList, &vertID);
  if ( vertID.m_Memory.m_nGrowSize >= 0 && v7 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v7);
  if ( weldTable.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00404E40
// Name: public: int CJointedModel::ProcessJointedModel(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CJointedModel::ProcessJointedModel(CJointedModel *this)
{
  int v1; // esi
  s_source_t *m_pModel; // eax
  s_source_t *v4; // edx
  Vector *m_pMemory; // ecx
  int numvertices; // edi
  int m_Size; // eax
  s_source_t *v8; // ecx
  bool v9; // al
  CPhysCollisionModel *v10; // ecx
  s_mesh_t *v11; // esi
  s_face_t *v12; // eax
  int v13; // eax
  int v14; // edi
  int v15; // eax
  s_face_t *v16; // edi
  s_source_t *v17; // edx
  int v18; // edi
  int m; // esi
  int v20; // edi
  CPhysCollisionModel *inited; // eax
  int v22; // ecx
  s_source_t *v23; // edx
  int v24; // ecx
  int *p_numVertIndex; // edi
  int j; // esi
  int v27; // edi
  int k; // esi
  CPhysCollisionModel *v29; // esi
  CPhysCollisionModel **p_m_pCollisionList; // eax
  CPhysCollisionModel *v31; // ecx
  Vector *v32; // eax
  s_source_t *v33; // ecx
  CPhysCollisionModel *m_pCollisionList; // ecx
  CPhysCollisionModel *m_pNext; // edi
  CPhysCollisionModel **p_m_pNext; // eax
  CPhysCollisionModel *v37; // edx
  boundingvolume_t bv; // [esp+1Ch] [ebp-9Ch] BYREF
  s_face_t globalFace; // [esp+34h] [ebp-84h] BYREF
  CUtlVector<int,CUtlMemory<int,int> > vertList; // [esp+44h] [ebp-74h] BYREF
  CUtlVector<convexlist_t,CUtlMemory<convexlist_t,int> > convexList; // [esp+58h] [ebp-60h] BYREF
  CUtlVector<CPhysConvex *,CUtlMemory<CPhysConvex *,int> > convexOut; // [esp+6Ch] [ebp-4Ch] BYREF
  CUtlVector<s_face_t,CUtlMemory<s_face_t,int> > faceList; // [esp+80h] [ebp-38h] BYREF
  CUtlVector<Vector,CUtlMemory<Vector,int> > bonespaceVerts; // [esp+94h] [ebp-24h] BYREF
  CPhysCollisionModel *pPhys; // [esp+A8h] [ebp-10h]
  int i; // [esp+ACh] [ebp-Ch]
  int vertCount; // [esp+B0h] [ebp-8h]
  int boneIndex; // [esp+B4h] [ebp-4h]
  int savedregs; // [esp+B8h] [ebp+0h] BYREF

  v1 = 0;
  if ( !g_quiet )
    printf(format: "Processing jointed collision model\n");
  m_pModel = this->m_pModel;
  boneIndex = 0;
  if ( m_pModel->numbones > 0 )
  {
    while ( !CCollisionModelSource::ShouldProcessBone(this, boneIndex) )
    {
LABEL_76:
      v33 = this->m_pModel;
      v1 = 0;
      if ( ++boneIndex >= v33->numbones )
        goto LABEL_77;
    }
    v4 = this->m_pModel;
    m_pMemory = nullptr;
    memset(&bonespaceVerts, 0, sizeof(bonespaceVerts));
    numvertices = v4->numvertices;
    m_Size = 0;
    if ( numvertices != 0 )
    {
      if ( numvertices > 0 )
      {
        CUtlMemory<CDmElementDictionary::DeletionInfo_t,int>::Grow(
          this: (CUtlMemory<UtlLinkedListElem_t<IUndoElement *,int>,int> *)&bonespaceVerts,
          num: numvertices);
        m_Size = bonespaceVerts.m_Size;
        m_pMemory = bonespaceVerts.m_Memory.m_pMemory;
      }
      bonespaceVerts.m_Size = numvertices + m_Size;
      bonespaceVerts.m_pElements = m_pMemory;
      if ( m_Size > 0 && numvertices > 0 )
        _V_memmove(dest: &m_pMemory[numvertices], src: m_pMemory, count: 12 * m_Size);
    }
    CCollisionModelSource::ConvertToBoneSpace(this, boneIndex, boneVerts: &bonespaceVerts);
    v8 = this->m_pModel;
    v9 = false;
    memset(&faceList, 0, sizeof(faceList));
    memset(&convexList, 0, sizeof(convexList));
    memset(&vertList, 0, sizeof(vertList));
    memset(&convexOut, 0, sizeof(convexOut));
    i = 0;
    if ( v8->nummeshes > 0 )
    {
      vertCount = 201488;
      do
      {
        v10 = nullptr;
        v11 = &this->m_pModel->mesh[*(_DWORD *)&this->m_pModel->filename[vertCount]];
        pPhys = nullptr;
        if ( v11->numfaces > 0 )
        {
          do
          {
            v12 = &this->m_pModel->face[(int)v10 + v11->faceoffset];
            memset(&globalFace, 255, sizeof(globalFace));
            GlobalFace(pout: &globalFace, pmesh: v11, pin: v12);
            if ( CCollisionModelSource::FaceHasVertOnBone(this, face: &globalFace, boneIndex) )
            {
              v13 = faceList.m_Size;
              v14 = faceList.m_Size;
              if ( faceList.m_Size + 1 > faceList.m_Memory.m_nAllocationCount )
              {
                CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
                  this: (CUtlMemory<ActiveLayer_t<CUtlSymbolLarge>,int> *)&faceList,
                  num: faceList.m_Size - faceList.m_Memory.m_nAllocationCount + 1);
                v13 = faceList.m_Size;
              }
              faceList.m_Size = v13 + 1;
              v15 = v13 - v14;
              faceList.m_pElements = faceList.m_Memory.m_pMemory;
              if ( v15 > 0 )
                _V_memmove(
                  dest: &faceList.m_Memory.m_pMemory[v14 + 1],
                  src: &faceList.m_Memory.m_pMemory[v14],
                  count: 16 * v15);
              v16 = &faceList.m_Memory.m_pMemory[v14];
              if ( v16 != nullptr )
                *v16 = globalFace;
            }
            v10 = (CPhysCollisionModel *)((char *)&pPhys->m_parent + 1);
            pPhys = v10;
          }
          while ( (int)v10 < v11->numfaces );
        }
        if ( this->m_allowConcaveJoints )
          BuildConvexListForFaceList(
            pmodel: this->m_pModel,
            (CUtlMemory<CDmeMesh::FaceSet_t,int> *)&convexList,
            &vertList,
            &faceList);
        else
          BuildSingleConvexForFaceList(
            pmodel: this->m_pModel,
            (CUtlMemory<CDmeMesh::FaceSet_t,int> *)&convexList,
            &vertList,
            &faceList);
        v9 = BuildConvexesForLists(
               (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&convexOut,
               &convexList,
               &vertList,
               worldspaceVerts: &bonespaceVerts,
               bRemove2d: this->m_remove2d);
        v17 = this->m_pModel;
        vertCount += 4;
        ++i;
      }
      while ( i < v17->nummeshes );
      v1 = convexList.m_Size;
    }
    v18 = convexOut.m_Size;
    if ( convexOut.m_Size <= this->m_maxConvex )
    {
      if ( v9 )
      {
        if ( convexOut.m_Size != 0 )
        {
          v20 = boneIndex;
          inited = CJointedModel::InitCollisionModel(this, pJointName: this->m_pModel->localBone[boneIndex].name);
          inited->m_mass = 1.0;
          v22 = 132 * (boneIndex + 3);
          inited->m_name = this->m_pModel->localBone[v20].name;
          v23 = this->m_pModel;
          v24 = *(_DWORD *)&this->m_pModel->filename[v22];
          pPhys = inited;
          if ( v24 < 0 )
            inited->m_parent = nullptr;
          else
            inited->m_parent = v23->localBone[v24].name;
          ClearBounds(mins: &bv.mins, maxs: &bv.maxs);
          vertCount = 0;
          if ( v1 > 0 )
          {
            p_numVertIndex = &convexList.m_Memory.m_pMemory->numVertIndex;
            for ( i = v1; i != 0; --i )
            {
              for ( j = 0; j < *p_numVertIndex; ++j )
              {
                AddPointToBounds(
                  v: &bonespaceVerts.m_Memory.m_pMemory[vertList.m_Memory.m_pMemory[j + *(p_numVertIndex - 1)]],
                  mins: &bv.mins,
                  maxs: &bv.maxs);
                ++vertCount;
              }
              p_numVertIndex += 2;
            }
          }
          v27 = convexOut.m_Size;
          for ( k = 0; k < convexOut.m_Size; ++k )
          {
            physcollision->SetConvexGameData(
              this: physcollision,
              a2: convexOut.m_Memory.m_pMemory[k],
              a3: this->m_pModel->boneLocalToGlobal[boneIndex] + 1);
            v27 = convexOut.m_Size;
          }
          v29 = pPhys;
          CreateCollide(
            a1: COERCE_FLOAT(&savedregs),
            pBase: pPhys,
            pElements: convexOut.m_Memory.m_pMemory,
            elementCount: v27,
            &bv);
          if ( !g_quiet )
            printf(
              format: "%-24s (%3d verts, %d convex elements) volume: %4.2f\n",
              v29->m_name,
              vertCount,
              v27,
              v29->m_volume);
          p_m_pCollisionList = &this->m_pCollisionList;
          if ( this->m_pCollisionList != nullptr )
          {
            while ( 1 )
            {
              v31 = *p_m_pCollisionList;
              if ( *p_m_pCollisionList == v29 )
                break;
              p_m_pCollisionList = &v31->m_pNext;
              if ( v31->m_pNext == nullptr )
                goto LABEL_54;
            }
            *p_m_pCollisionList = v29->m_pNext;
            --this->m_collisionCount;
            v29->m_pNext = nullptr;
          }
LABEL_54:
          if ( this->m_isMassCenterForced )
            physcollision->CollideSetMassCenter(
              this: physcollision,
              a2: v29->m_pCollisionData,
              a3: &this->m_massCenterForced);
          v29->m_pNext = this->m_pCollisionList;
          ++this->m_collisionCount;
          this->m_pCollisionList = v29;
        }
        goto LABEL_57;
      }
    }
    else
    {
      MdlWarning(fmt: "COSTLY COLLISION MODEL!!!! (%d parts - %d allowed)\n", convexOut.m_Size, this->m_maxConvex);
    }
    if ( v18 != 0 )
    {
      MdlWarning(fmt: "Error with convex elements of %s, building single convex!!!!\n", this->m_pModel->filename);
      for ( m = 0; m < v18; ++m )
        physcollision->ConvexFree(this: physcollision, a2: convexOut.m_Memory.m_pMemory[m]);
      if ( convexOut.m_Memory.m_nGrowSize >= 0 && convexOut.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: convexOut.m_Memory.m_pMemory);
        convexOut.m_Memory.m_pMemory = nullptr;
      }
    }
LABEL_57:
    if ( convexOut.m_Memory.m_nGrowSize >= 0 && convexOut.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: convexOut.m_Memory.m_pMemory);
    if ( vertList.m_Memory.m_nGrowSize >= 0 && vertList.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: vertList.m_Memory.m_pMemory);
    if ( convexList.m_Memory.m_nGrowSize >= 0 && convexList.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: convexList.m_Memory.m_pMemory);
    if ( faceList.m_Memory.m_nGrowSize >= 0 && faceList.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: faceList.m_Memory.m_pMemory);
    v32 = bonespaceVerts.m_Memory.m_pMemory;
    bonespaceVerts.m_Size = 0;
    if ( bonespaceVerts.m_Memory.m_nGrowSize >= 0 )
    {
      if ( bonespaceVerts.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bonespaceVerts.m_Memory.m_pMemory);
        v32 = nullptr;
        bonespaceVerts.m_Memory.m_pMemory = nullptr;
      }
      bonespaceVerts.m_Memory.m_nAllocationCount = 0;
    }
    bonespaceVerts.m_pElements = v32;
    if ( bonespaceVerts.m_Memory.m_nGrowSize >= 0 && v32 != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v32);
    goto LABEL_76;
  }
LABEL_77:
  m_pCollisionList = this->m_pCollisionList;
  if ( m_pCollisionList != nullptr )
  {
    do
    {
      m_pNext = m_pCollisionList->m_pNext;
      if ( m_pCollisionList->m_pCollisionData == nullptr )
      {
        p_m_pNext = &this->m_pCollisionList;
        if ( this->m_pCollisionList != nullptr )
        {
          while ( 1 )
          {
            v37 = *p_m_pNext;
            if ( *p_m_pNext == m_pCollisionList )
              break;
            p_m_pNext = &v37->m_pNext;
            if ( v37->m_pNext == nullptr )
              goto LABEL_84;
          }
          *p_m_pNext = m_pNext;
          --this->m_collisionCount;
          m_pCollisionList->m_pNext = nullptr;
        }
LABEL_84:
        free(pMem: m_pCollisionList);
      }
      m_pCollisionList = m_pNext;
    }
    while ( m_pNext != nullptr );
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00405410
// Name: public: int CJointedModel::ProcessSingleBody(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CJointedModel::ProcessSingleBody(CJointedModel *this)
{
  int m_Size; // edi
  s_source_t *m_pModel; // esi
  int v4; // ebx
  int v5; // ecx
  bool v6; // al
  s_mesh_t *v7; // ebx
  bool v8; // cc
  s_face_t *v9; // edx
  int v10; // esi
  s_face_t *m_pMemory; // ecx
  s_face_t *v12; // esi
  int v13; // eax
  int v14; // ecx
  int v15; // ebx
  convexlist_t *v16; // eax
  int v17; // ebx
  int v18; // eax
  int *v19; // ebx
  unsigned __int8 *v20; // eax
  unsigned __int8 *v21; // ebx
  float *v22; // eax
  double v23; // st7
  int v24; // eax
  char *v25; // eax
  CJointedModel *v26; // esi
  Vector *v27; // eax
  int numvertices; // [esp-4h] [ebp-2A4h]
  char tmp[512]; // [esp+Ch] [ebp-294h] BYREF
  boundingvolume_t mins; // [esp+20Ch] [ebp-94h] BYREF
  s_source_t *pmodel; // [esp+228h] [ebp-78h]
  CUtlVector<s_face_t,CUtlMemory<s_face_t,int> > faceList; // [esp+22Ch] [ebp-74h] BYREF
  CUtlVector<convexlist_t,CUtlMemory<convexlist_t,int> > convexList; // [esp+240h] [ebp-60h] BYREF
  CUtlVector<Vector,CUtlMemory<Vector,int> > worldspaceVerts; // [esp+254h] [ebp-4Ch] BYREF
  int j; // [esp+268h] [ebp-38h]
  CUtlVector<int,CUtlMemory<int,int> > vertList; // [esp+26Ch] [ebp-34h] BYREF
  CUtlVector<CPhysConvex *,CUtlMemory<CPhysConvex *,int> > convexOut; // [esp+280h] [ebp-20h] BYREF
  CJointedModel *v39; // [esp+294h] [ebp-Ch]
  int i; // [esp+298h] [ebp-8h]
  int meshindex; // [esp+29Ch] [ebp-4h]
  int savedregs; // [esp+2A0h] [ebp+0h] BYREF

  m_Size = 0;
  m_pModel = this->m_pModel;
  memset(&worldspaceVerts, 0, sizeof(worldspaceVerts));
  numvertices = m_pModel->numvertices;
  v39 = this;
  pmodel = m_pModel;
  CUtlVector<QAngle,CUtlMemory<QAngle,int>>::InsertMultipleBefore(
    this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&worldspaceVerts,
    elem: 0,
    num: numvertices);
  CCollisionModelSource::ConvertToWorldSpace(this, worldVerts: &worldspaceVerts);
  v4 = 0;
  v5 = 0;
  v6 = false;
  memset(&faceList, 0, sizeof(faceList));
  memset(&convexList, 0, sizeof(convexList));
  memset(&vertList, 0, sizeof(vertList));
  memset(&convexOut, 0, sizeof(convexOut));
  if ( v39->m_allowConcave )
  {
    i = 0;
    if ( m_pModel->nummeshes > 0 )
    {
      meshindex = (int)m_pModel->meshindex;
      do
      {
        v7 = &m_pModel->mesh[*(_DWORD *)meshindex];
        v8 = v7->numfaces <= 0;
        j = 0;
        if ( !v8 )
        {
          do
          {
            v9 = &m_pModel->face[j + v7->faceoffset];
            memset(&mins.mins.z, 255, 16);
            GlobalFace(pout: (s_face_t *)&mins.mins.z, pmesh: v7, pin: v9);
            v10 = m_Size;
            if ( m_Size + 1 > faceList.m_Memory.m_nAllocationCount )
            {
              CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
                this: (CUtlMemory<ActiveLayer_t<CUtlSymbolLarge>,int> *)&faceList,
                num: m_Size - faceList.m_Memory.m_nAllocationCount + 1);
              m_Size = faceList.m_Size;
            }
            m_pMemory = faceList.m_Memory.m_pMemory;
            faceList.m_Size = ++m_Size;
            faceList.m_pElements = faceList.m_Memory.m_pMemory;
            if ( m_Size - v10 - 1 > 0 )
            {
              _V_memmove(
                dest: &faceList.m_Memory.m_pMemory[v10 + 1],
                src: &faceList.m_Memory.m_pMemory[v10],
                count: 16 * (m_Size - v10 - 1));
              m_pMemory = faceList.m_Memory.m_pMemory;
            }
            v12 = &m_pMemory[v10];
            if ( v12 != nullptr )
            {
              *(_QWORD *)&v12->a = *(_QWORD *)&mins.mins.z;
              *(_QWORD *)&v12->c = *(_QWORD *)&mins.maxs.y;
            }
            m_pModel = pmodel;
            ++j;
          }
          while ( j < v7->numfaces );
        }
        meshindex += 4;
        ++i;
      }
      while ( i < m_pModel->nummeshes );
    }
    BuildConvexListForFaceList(
      pmodel: m_pModel,
      (CUtlMemory<CDmeMesh::FaceSet_t,int> *)&convexList,
      &vertList,
      &faceList);
    v6 = BuildConvexesForLists(
           (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&convexOut,
           &convexList,
           &vertList,
           &worldspaceVerts,
           bRemove2d: v39->m_remove2d);
    v4 = convexList.m_Size;
    v5 = convexOut.m_Size;
  }
  if ( v5 > v39->m_maxConvex )
  {
    MdlWarning(fmt: "COSTLY COLLISION MODEL!!!! (%d parts - %d allowed)\n", v5, v39->m_maxConvex);
    v5 = convexOut.m_Size;
  }
  else if ( v6 )
  {
    if ( v5 != 0 )
    {
LABEL_42:
      if ( !g_quiet )
        printf(format: "Model has %d convex sub-parts\n", v5);
      v20 = (unsigned __int8 *)MemAlloc_Alloc(nSize: 0x30u);
      v21 = v20;
      if ( v20 != nullptr )
        memset(dst: v20, value: 0, count: 0x30u);
      else
        v21 = nullptr;
      v22 = (float *)v39;
      *((float *)v21 + 5) = v39->m_defaultDamping;
      *((float *)v21 + 7) = v22[55];
      v23 = v22[54];
      *((_DWORD *)v21 + 9) = 1065353216;
      *((float *)v21 + 6) = v23;
      *((float *)v21 + 8) = v22[56];
      ClearBounds(mins: &mins.mins, maxs: &mins.maxs);
      i = worldspaceVerts.m_Size - 2;
      if ( worldspaceVerts.m_Size - 2 >= 0 )
      {
        v24 = 12 * (worldspaceVerts.m_Size - 2);
        for ( meshindex = v24; ; v24 = meshindex )
        {
          AddPointToBounds(
            v: (const Vector *)((char *)worldspaceVerts.m_Memory.m_pMemory + v24),
            mins: &mins.mins,
            maxs: &mins.maxs);
          meshindex -= 12;
          if ( --i < 0 )
            break;
        }
      }
      CreateCollide(
        a1: COERCE_FLOAT(&savedregs),
        pBase: (CPhysCollisionModel *)v21,
        pElements: convexOut.m_Memory.m_pMemory,
        elementCount: convexOut.m_Size,
        bv: &mins);
      *((_DWORD *)v21 + 2) = 1065353216;
      V_FileBase(in: m_pModel->filename, out: tmp, maxlen: 512);
      v25 = (char *)MemAlloc_Alloc(nSize: strlen(tmp) + 1);
      strcpy(v25, tmp);
      v26 = v39;
      *((_DWORD *)v21 + 1) = v25;
      *(_DWORD *)v21 = 0;
      if ( v26->m_isMassCenterForced )
        physcollision->CollideSetMassCenter(
          this: physcollision,
          a2: *((struct CPhysCollide **)v21 + 10),
          a3: &v26->m_massCenterForced);
      *((_DWORD *)v21 + 11) = v26->m_pCollisionList;
      ++v26->m_collisionCount;
      v26->m_pCollisionList = (CPhysCollisionModel *)v21;
      goto LABEL_54;
    }
LABEL_26:
    v13 = v4;
    pmodel = (s_source_t *)m_pModel->numvertices;
    i = v4;
    if ( v4 + 1 > convexList.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<mergelist_t,int>::Grow(
        this: (CUtlMemory<CDmeMesh::FaceSet_t,int> *)&convexList,
        num: v4 - convexList.m_Memory.m_nAllocationCount + 1);
      v4 = convexList.m_Size;
      v13 = i;
    }
    v14 = vertList.m_Size;
    convexList.m_Size = v4 + 1;
    v15 = v4 - v13;
    convexList.m_pElements = convexList.m_Memory.m_pMemory;
    if ( v15 > 0 )
    {
      _V_memmove(
        dest: &convexList.m_Memory.m_pMemory[v13 + 1],
        src: &convexList.m_Memory.m_pMemory[v13],
        count: 8 * v15);
      v13 = i;
      v14 = vertList.m_Size;
    }
    v16 = &convexList.m_Memory.m_pMemory[v13];
    if ( v16 != nullptr )
    {
      v16->firstVertIndex = 0;
      v16->numVertIndex = (int)pmodel;
    }
    for ( meshindex = 0; meshindex < m_pModel->numvertices; ++meshindex )
    {
      v17 = v14;
      if ( v14 + 1 > vertList.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&vertList,
          num: v14 - vertList.m_Memory.m_nAllocationCount + 1);
        v14 = vertList.m_Size;
      }
      v18 = ++v14 - v17 - 1;
      vertList.m_Size = v14;
      vertList.m_pElements = vertList.m_Memory.m_pMemory;
      if ( v18 > 0 )
      {
        _V_memmove(dest: &vertList.m_Memory.m_pMemory[v17 + 1], src: &vertList.m_Memory.m_pMemory[v17], count: 4 * v18);
        v14 = vertList.m_Size;
      }
      v19 = &vertList.m_Memory.m_pMemory[v17];
      if ( v19 != nullptr )
        *v19 = meshindex;
    }
    BuildConvexesForLists(
      (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&convexOut,
      &convexList,
      &vertList,
      &worldspaceVerts,
      bRemove2d: true);
    if ( convexOut.m_Size != 0 )
    {
      v5 = convexOut.m_Size;
      goto LABEL_42;
    }
LABEL_54:
    if ( convexOut.m_Memory.m_nGrowSize >= 0 && convexOut.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: convexOut.m_Memory.m_pMemory);
    if ( vertList.m_Memory.m_nGrowSize >= 0 && vertList.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: vertList.m_Memory.m_pMemory);
    if ( convexList.m_Memory.m_nGrowSize >= 0 && convexList.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: convexList.m_Memory.m_pMemory);
    if ( faceList.m_Memory.m_nGrowSize >= 0 && faceList.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: faceList.m_Memory.m_pMemory);
    v27 = worldspaceVerts.m_Memory.m_pMemory;
    worldspaceVerts.m_Size = 0;
    if ( worldspaceVerts.m_Memory.m_nGrowSize >= 0 )
    {
      if ( worldspaceVerts.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: worldspaceVerts.m_Memory.m_pMemory);
        v27 = nullptr;
        worldspaceVerts.m_Memory.m_pMemory = nullptr;
      }
      worldspaceVerts.m_Memory.m_nAllocationCount = 0;
    }
    worldspaceVerts.m_pElements = v27;
    if ( worldspaceVerts.m_Memory.m_nGrowSize >= 0 && v27 != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v27);
    return 1;
  }
  if ( v5 != 0 )
  {
    MdlWarning(fmt: "Error with convex elements of %s, building single convex!!!!\n", m_pModel->filename);
    for ( meshindex = 0; meshindex < convexOut.m_Size; ++meshindex )
      physcollision->ConvexFree(this: physcollision, a2: convexOut.m_Memory.m_pMemory[meshindex]);
    convexOut.m_Size = 0;
    if ( convexOut.m_Memory.m_nGrowSize >= 0 )
    {
      if ( convexOut.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: convexOut.m_Memory.m_pMemory);
        convexOut.m_Memory.m_pMemory = nullptr;
      }
      convexOut.m_Memory.m_nAllocationCount = 0;
    }
    convexOut.m_pElements = convexOut.m_Memory.m_pMemory;
  }
  goto LABEL_26;
}

//------------------------------------------------------------------------------
// Address: 0x004059C0
// Name: void CollisionModel_Build(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CollisionModel_Build()
{
  if ( g_JointedModel.m_pModel != nullptr )
  {
    CCollisionModelSource::Simplify(this: &g_JointedModel);
    if ( g_JointedModel.m_isJointed )
      CJointedModel::ProcessJointedModel(this: &g_JointedModel);
    else
      CJointedModel::ProcessSingleBody(this: &g_JointedModel);
    CJointedModel::FixCollisionHierarchy(this: &g_JointedModel);
    if ( !g_quiet )
      printf(format: "Collision model completed.\n");
    CJointedModel::ComputeMass(this: &g_JointedModel);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405A20
// Name: public: CJointedModel::CJointedModel(void)
// Source: json
//------------------------------------------------------------------------------
CJointedModel *__thiscall CJointedModel::CJointedModel(CJointedModel *this)
{
  this->m_bonemap.m_Memory.m_pMemory = nullptr;
  this->m_bonemap.m_Memory.m_nAllocationCount = 0;
  this->m_bonemap.m_Memory.m_nGrowSize = 0;
  this->m_bonemap.m_pElements = nullptr;
  this->m_textCommands.m_Memory.m_pMemory = nullptr;
  this->m_textCommands.m_Memory.m_nAllocationCount = 0;
  this->m_textCommands.m_Memory.m_nGrowSize = 0;
  this->m_textCommands.m_Size = 0;
  this->m_textCommands.m_pElements = nullptr;
  this->m_mergeList.m_Memory.m_pMemory = nullptr;
  this->m_mergeList.m_Memory.m_nAllocationCount = 0;
  this->m_mergeList.m_Memory.m_nGrowSize = 0;
  this->m_mergeList.m_Size = 0;
  this->m_mergeList.m_pElements = nullptr;
  this->m_totalMass = 1.0;
  this->m_pModel = nullptr;
  this->m_collisionCount = 0;
  this->m_pCollisionList = nullptr;
  this->m_pCollisionPairs = nullptr;
  this->m_bonemap.m_Size = 0;
  this->m_defaultInertia = 1.0;
  this->m_pConstraintList = nullptr;
  this->m_constraintCount = 0;
  this->m_totalVerts = 0;
  this->m_defaultDamping = 0.0;
  this->m_defaultRotdamping = 0.0;
  this->m_defaultDrag = -1.0;
  this->m_allowConcave = false;
  this->m_allowConcaveJoints = false;
  this->m_remove2d = false;
  this->m_maxConvex = 40;
  *(_WORD *)&this->m_isMassCenterForced = 0;
  this->m_massCenterForced.x = 0.0;
  this->m_massCenterForced.y = 0.0;
  this->m_massCenterForced.z = 0.0;
  this->m_flFrictionTimeIn = 0.0;
  this->m_flFrictionTimeOut = 0.0;
  this->m_iMinAnimatedFriction = 1;
  this->m_iMaxAnimatedFriction = 1;
  this->m_bHasAnimatedFriction = false;
  this->m_pOverrideName = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00415720
// Name: private: class Vector __near & OptimizedModel::COptimizedModel::GetOrigVertPosition(struct mstudiomodel_t __near *,struct mstudiomesh_t __near *,struct OptimizedModel::Vertex_t __near *)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall OptimizedModel::COptimizedModel::GetOrigVertPosition(
        OptimizedModel::COptimizedModel *this,
        mstudiomodel_t *pStudioModel,
        mstudiomesh_t *pStudioMesh,
        OptimizedModel::Vertex_t *pVert)
{
  mstudio_meshvertexdata_t *vertData; // [esp+20h] [ebp-4h]

  mstudiomodel_t::GetVertexData(
    this: (mstudiomodel_t *)((char *)pStudioMesh + pStudioMesh->modelindex),
    pModelData: nullptr);
  pStudioMesh->vertexdata.modelvertexdata = (const mstudio_modelvertexdata_t *)((char *)&pStudioMesh->unused[6]
                                                                              + pStudioMesh->modelindex);
  if ( pStudioMesh->vertexdata.modelvertexdata->pVertexData != nullptr )
    vertData = &pStudioMesh->vertexdata;
  else
    vertData = nullptr;
  return (Vector *)((char *)vertData->modelvertexdata->pVertexData
                  + 48
                  * ((int)vertData[-1].modelvertexdata
                   + pVert->origMeshVertID
                   + (unsigned int)vertData->modelvertexdata[-3].pVertexData / 0x30)
                  + 16);
}

} // namespace studiomdl
