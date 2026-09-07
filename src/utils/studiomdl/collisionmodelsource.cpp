// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/studiomdl/collisionmodelsource.cpp
// Functions: 12
// ============================================================

#include "utils\studiomdl\collisionmodelsource.h"

//------------------------------------------------------------------------------
// Address: 0x00406440
// Name: int FindLocalBoneNamed(struct s_source_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FindLocalBoneNamed(const s_source_t *pSource, const char *pName)
{
  int v2; // edi
  s_node_t *localBone; // ebx
  s_node_t *i; // ebx
  const char *pNamea; // [esp+18h] [ebp+Ch]

  if ( pName == nullptr )
    return -1;
  v2 = 0;
  if ( pSource->numbones > 0 )
  {
    localBone = pSource->localBone;
    while ( _V_stricmp(s1: pName, s2: localBone->name) != 0 )
    {
      ++v2;
      ++localBone;
      if ( v2 >= pSource->numbones )
        goto LABEL_6;
    }
    return v2;
  }
LABEL_6:
  v2 = 0;
  pNamea = RenameBone(pName);
  if ( pSource->numbones <= 0 )
    return -1;
  for ( i = pSource->localBone; _V_stricmp(s1: pNamea, s2: i->name) != 0; ++i )
  {
    if ( ++v2 >= pSource->numbones )
      return -1;
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x004064D0
// Name: public: int CCollisionModelSource::FindLocalBoneNamed(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCollisionModelSource::FindLocalBoneNamed(CCollisionModelSource *this, const char *pName)
{
  return FindLocalBoneNamed(pSource: this->m_pModel, pName);
}

//------------------------------------------------------------------------------
// Address: 0x004064F0
// Name: void GlobalFace(struct s_face_t __near *,struct s_mesh_t __near *,struct s_face_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GlobalFace(s_face_t *pout, s_mesh_t *pmesh, s_face_t *pin)
{
  pout->a = pmesh->vertexoffset + pin->a;
  pout->b = pmesh->vertexoffset + pin->b;
  pout->c = pmesh->vertexoffset + pin->c;
}

//------------------------------------------------------------------------------
// Address: 0x00406520
// Name: public: void CCollisionModelSource::ConvertToWorldSpace(class CUtlVector<class Vector,class CUtlMemory<class Vector,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionModelSource::ConvertToWorldSpace(
        CCollisionModelSource *this,
        CUtlVector<Vector,CUtlMemory<Vector,int> > *worldVerts)
{
  int v3; // esi
  s_source_t *v4; // edx
  Vector *v5; // eax
  int v6; // edx
  int v7; // ecx
  int v8; // ecx
  int v9; // ebx
  int v10; // ecx
  float v11; // xmm0_4
  bool v12; // zf
  s_source_t *v13; // ebx
  s_source_t *m_pModel; // edx
  Vector *m_pMemory; // eax
  int v16; // edx
  int v17; // ebx
  float v18; // xmm0_4
  float v19; // xmm1_4
  s_source_t *v20; // ebx
  matrix3x4_t pBoneToWorld[1024]; // [esp+20h] [ebp-C058h] BYREF
  matrix3x4_t out; // [esp+C020h] [ebp-58h] BYREF
  float in1[3]; // [esp+C050h] [ebp-28h] BYREF
  float v24; // [esp+C05Ch] [ebp-1Ch] BYREF
  float v25; // [esp+C060h] [ebp-18h]
  float v26; // [esp+C064h] [ebp-14h]
  int v27; // [esp+C068h] [ebp-10h]
  int v28; // [esp+C06Ch] [ebp-Ch]
  int v29; // [esp+C070h] [ebp-8h]
  int v30; // [esp+C074h] [ebp-4h]

  v3 = 0;
  if ( this->m_bAssumeWorldspace )
  {
    BuildRawTransforms(
      psource: this->m_pModel,
      pAnimationName: "BindPose",
      frame: 0,
      scale: this->m_pModel->scale,
      shift: &this->m_pModel->adjust,
      rotate: &this->m_pModel->rotation,
      flags: 0,
      boneToWorld: pBoneToWorld);
    m_pModel = this->m_pModel;
    v28 = 0;
    if ( m_pModel->numvertices > 0 )
    {
      m_pMemory = worldVerts->m_Memory.m_pMemory;
      v16 = 0;
      v30 = 0;
      do
      {
        m_pMemory[v3].x = 0.0;
        m_pMemory[v3].y = 0.0;
        m_pMemory[v3].z = 0.0;
        if ( *(int *)((char *)&this->m_pModel->vertex->boneweight.numbones + v16) > 0 )
        {
          v17 = v16 + 72;
          v29 = *(int *)((char *)&this->m_pModel->vertex->boneweight.numbones + v16);
          do
          {
            VectorTransform(
              in1: (const float *)((char *)&this->m_pModel->vertex->position.x + v16),
              in2: &pBoneToWorld[*(_DWORD *)((char *)this->m_pModel->vertex + v17 - 12)],
              out: &v24);
            v18 = *(float *)((char *)&this->m_pModel->vertex->material + v17);
            m_pMemory = worldVerts->m_Memory.m_pMemory;
            v16 = v30;
            m_pMemory[v3].x = (float)(v24 * v18) + worldVerts->m_Memory.m_pMemory[v3].x;
            m_pMemory[v3].y = (float)(v25 * v18) + m_pMemory[v3].y;
            v19 = (float)(v26 * v18) + m_pMemory[v3].z;
            v17 += 4;
            v12 = v29-- == 1;
            m_pMemory[v3].z = v19;
          }
          while ( !v12 );
        }
        v20 = this->m_pModel;
        v16 += 84;
        ++v3;
        ++v28;
        v30 = v16;
      }
      while ( v28 < v20->numvertices );
    }
  }
  else
  {
    CalcBoneTransforms(panimation: g_panimation[0], frame: 0, pBoneToWorld);
    v4 = this->m_pModel;
    v28 = 0;
    if ( v4->numvertices > 0 )
    {
      v5 = worldVerts->m_Memory.m_pMemory;
      v6 = 0;
      v30 = 0;
      do
      {
        v5[v3].x = 0.0;
        v5[v3].y = 0.0;
        v5[v3].z = 0.0;
        v7 = *(int *)((char *)&this->m_pModel->vertex->boneweight.numbones + v6);
        if ( v7 > 0 )
        {
          v27 = v6 + 72;
          v29 = v7;
          do
          {
            v8 = *(_DWORD *)((char *)this->m_pModel->vertex + v27 - 12);
            v9 = this->m_pModel->boneLocalToGlobal[v8];
            ConcatTransforms(in1: &this->m_pModel->boneToPose[v8], in2: &g_bonetable[v9].srcRealign, &out);
            VectorITransform(
              in1: (const float *)((char *)&this->m_pModel->vertex->position.x + v30),
              in2: &out,
              out: in1);
            VectorTransform(in1, in2: &pBoneToWorld[v9], out: &v24);
            v5 = worldVerts->m_Memory.m_pMemory;
            v10 = v27;
            v11 = *(float *)((char *)&this->m_pModel->vertex->material + v27);
            v5[v3].x = (float)(v24 * v11) + worldVerts->m_Memory.m_pMemory[v3].x;
            v5[v3].y = (float)(v25 * v11) + v5[v3].y;
            v12 = v29-- == 1;
            v5[v3].z = (float)(v26 * v11) + v5[v3].z;
            v27 = v10 + 4;
          }
          while ( !v12 );
          v6 = v30;
        }
        v13 = this->m_pModel;
        v6 += 84;
        ++v3;
        ++v28;
        v30 = v6;
      }
      while ( v28 < v13->numvertices );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004067F0
// Name: public: void CCollisionModelSource::ConvertToBoneSpace(int,class CUtlVector<class Vector,class CUtlMemory<class Vector,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionModelSource::ConvertToBoneSpace(
        CCollisionModelSource *this,
        int boneIndex,
        CUtlVector<Vector,CUtlMemory<Vector,int> > *boneVerts)
{
  s_source_t *m_pModel; // ecx
  int v5; // eax
  s_source_t *v6; // eax
  int v7; // ebx
  int v8; // edi
  int v9; // esi
  matrix3x4_t boneToPose; // [esp+Ch] [ebp-34h] BYREF
  CCollisionModelSource *v11; // [esp+3Ch] [ebp-4h]

  m_pModel = this->m_pModel;
  v5 = m_pModel->boneLocalToGlobal[boneIndex];
  v11 = this;
  if ( v5 >= 0 )
  {
    ConcatTransforms(in1: &m_pModel->boneToPose[boneIndex], in2: &g_bonetable[v5].srcRealign, out: &boneToPose);
  }
  else
  {
    MdlWarning(fmt: "Error! physics for unused bone %s\n", m_pModel->localBone[boneIndex].name);
    MatrixCopy(in: &this->m_pModel->boneToPose[boneIndex], out: &boneToPose);
  }
  v6 = this->m_pModel;
  v7 = 0;
  if ( this->m_pModel->numvertices > 0 )
  {
    v8 = 0;
    v9 = 0;
    do
    {
      VectorITransform(in1: &v6->vertex[v8].position.x, in2: &boneToPose, out: &boneVerts->m_Memory.m_pMemory[v9].x);
      v6 = v11->m_pModel;
      ++v7;
      ++v9;
      ++v8;
    }
    while ( v7 < v11->m_pModel->numvertices );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004068C0
// Name: public: bool CCollisionModelSource::ShouldProcessBone(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCollisionModelSource::ShouldProcessBone(CCollisionModelSource *this, int boneIndex)
{
  return boneIndex >= 0 && this->m_bonemap.m_Memory.m_pMemory[boneIndex] == boneIndex;
}

//------------------------------------------------------------------------------
// Address: 0x004068E0
// Name: public: void CCollisionModelSource::SkipBone(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionModelSource::SkipBone(CCollisionModelSource *this, int boneIndex)
{
  if ( boneIndex >= 0 )
    this->m_bonemap.m_Memory.m_pMemory[boneIndex] = -1;
}

//------------------------------------------------------------------------------
// Address: 0x00406900
// Name: public: void CCollisionModelSource::MergeBones(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionModelSource::MergeBones(CCollisionModelSource *this, int parent, int child)
{
  int v3; // eax
  int *m_pMemory; // esi
  int v5; // edx
  int v6; // edi
  int numbones; // ecx

  v3 = parent;
  if ( parent >= 0 && child >= 0 )
  {
    m_pMemory = this->m_bonemap.m_Memory.m_pMemory;
    v5 = parent;
    v6 = 0;
    if ( m_pMemory[parent] != parent )
    {
      numbones = this->m_pModel->numbones;
      do
      {
        v3 = m_pMemory[v5];
        if ( ++v6 > numbones )
          break;
        if ( v3 < 0 )
          break;
        v5 = v3;
      }
      while ( m_pMemory[v3] != v3 );
    }
    m_pMemory[child] = v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406960
// Name: public: void CCollisionModelSource::MergeBones(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionModelSource::MergeBones(CCollisionModelSource *this, const char *parent, const char *child)
{
  int v4; // eax
  int LocalBoneNamed; // [esp-4h] [ebp-8h]

  LocalBoneNamed = FindLocalBoneNamed(pSource: this->m_pModel, pName: child);
  v4 = FindLocalBoneNamed(pSource: this->m_pModel, pName: parent);
  CCollisionModelSource::MergeBones(this, parent: v4, child: LocalBoneNamed);
}

//------------------------------------------------------------------------------
// Address: 0x004069A0
// Name: public: void CCollisionModelSource::Simplify(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionModelSource::Simplify(CCollisionModelSource *this)
{
  CCollisionModelSource *v1; // edi
  s_source_t *m_pModel; // eax
  int v3; // edx
  s_source_t *v4; // esi
  int parent; // eax
  int v6; // ecx
  int *m_pMemory; // edi
  int v8; // edx
  int v9; // ebx
  int v10; // eax
  int numbones; // esi
  s_bonetable_t *v12; // esi
  int LocalBoneNamed; // ebx
  int v14; // eax
  int *v15; // edx
  int v16; // ecx
  int v17; // esi
  int v18; // edi
  int v20; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]

  v1 = this;
  m_pModel = this->m_pModel;
  v3 = 0;
  i = 0;
  if ( this->m_pModel->numbones > 0 )
  {
    v20 = 396;
    do
    {
      if ( m_pModel->boneLocalToGlobal[v3] < 0 && v3 >= 0 )
        v1->m_bonemap.m_Memory.m_pMemory[v3] = -1;
      v4 = v1->m_pModel;
      parent = *(_DWORD *)&v1->m_pModel->filename[v20];
      v6 = v3;
      if ( parent >= 0 )
      {
        do
        {
          if ( v4->boneLocalToGlobal[parent] != v1->m_pModel->boneLocalToGlobal[v3] )
            break;
          v6 = parent;
          parent = v4->localBone[parent].parent;
        }
        while ( parent >= 0 );
        if ( v6 != v3 && v6 >= 0 && v3 >= 0 )
        {
          m_pMemory = v1->m_bonemap.m_Memory.m_pMemory;
          v8 = v6;
          v9 = 0;
          v10 = v6;
          if ( m_pMemory[v6] != v6 )
          {
            numbones = v4->numbones;
            do
            {
              v10 = m_pMemory[v8];
              if ( ++v9 > numbones )
                break;
              if ( v10 < 0 )
                break;
              v8 = v10;
            }
            while ( m_pMemory[v10] != v10 );
          }
          m_pMemory[i] = v10;
          v1 = this;
          v3 = i;
        }
      }
      m_pModel = v1->m_pModel;
      v20 += 132;
      i = ++v3;
    }
    while ( v3 < v1->m_pModel->numbones );
  }
  v12 = &g_bonetable[g_rootIndex];
  LocalBoneNamed = FindLocalBoneNamed(pSource: v1->m_pModel, pName: v1->m_rootName);
  v14 = FindLocalBoneNamed(pSource: v1->m_pModel, pName: v12->name);
  if ( v14 >= 0 && LocalBoneNamed >= 0 )
  {
    v15 = v1->m_bonemap.m_Memory.m_pMemory;
    v16 = v14;
    v17 = 0;
    if ( v15[v14] != v14 )
    {
      v18 = v1->m_pModel->numbones;
      do
      {
        v14 = v15[v16];
        if ( ++v17 > v18 )
          break;
        if ( v14 < 0 )
          break;
        v16 = v14;
      }
      while ( v15[v14] != v14 );
    }
    v15[LocalBoneNamed] = v14;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406B00
// Name: public: bool CCollisionModelSource::FaceHasVertOnBone(struct s_face_t const __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCollisionModelSource::FaceHasVertOnBone(
        CCollisionModelSource *this,
        const s_face_t *face,
        int boneIndex)
{
  s_vertexinfo_t *vertex; // ebx
  unsigned int a; // eax
  int numbones; // esi
  int p_boneweight; // eax
  int v8; // edx
  int *v9; // edi
  int v10; // eax
  unsigned int b; // eax
  int v12; // edi
  int v13; // eax
  int v14; // edx
  int *v15; // esi
  int v16; // eax
  unsigned int c; // eax
  int v18; // edi
  int v19; // eax
  int v20; // edx
  int *i; // esi
  int v22; // eax
  CCollisionModelSource *v23; // [esp+0h] [ebp-4h]

  v23 = this;
  if ( boneIndex < 0 )
    return 1;
  vertex = this->m_pModel->vertex;
  a = face->a;
  numbones = vertex[a].boneweight.numbones;
  p_boneweight = (int)&vertex[a].boneweight;
  v8 = 0;
  if ( numbones <= 0 )
  {
LABEL_9:
    b = face->b;
    v12 = vertex[b].boneweight.numbones;
    v13 = (int)&vertex[b].boneweight;
    v14 = 0;
    if ( v12 <= 0 )
    {
LABEL_15:
      c = face->c;
      v18 = vertex[c].boneweight.numbones;
      v19 = (int)&vertex[c].boneweight;
      v20 = 0;
      if ( v18 <= 0 )
        return 0;
      for ( i = (int *)(v19 + 4); ; ++i )
      {
        v22 = *i;
        if ( *i >= 0 )
          v22 = this->m_bonemap.m_Memory.m_pMemory[v22];
        if ( v22 == boneIndex )
          break;
        if ( ++v20 >= v18 )
          return 0;
      }
    }
    else
    {
      v15 = (int *)(v13 + 4);
      while ( 1 )
      {
        v16 = *v15;
        if ( *v15 >= 0 )
          v16 = this->m_bonemap.m_Memory.m_pMemory[v16];
        if ( v16 == boneIndex )
          break;
        this = v23;
        ++v14;
        ++v15;
        if ( v14 >= v12 )
          goto LABEL_15;
      }
    }
  }
  else
  {
    v9 = (int *)(p_boneweight + 4);
    while ( 1 )
    {
      v10 = *v9;
      if ( *v9 >= 0 )
        v10 = this->m_bonemap.m_Memory.m_pMemory[v10];
      if ( v10 == boneIndex )
        break;
      this = v23;
      ++v8;
      ++v9;
      if ( v8 >= numbones )
        goto LABEL_9;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00406BF0
// Name: public: void CCollisionModelSource::InitBoneMap(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionModelSource::InitBoneMap(CCollisionModelSource *this)
{
  int i; // eax
  int numbones; // [esp-4h] [ebp-Ch]

  numbones = this->m_pModel->numbones;
  this->m_bonemap.m_Size = 0;
  CUtlVector<s_bone_t *,CUtlMemory<s_bone_t *,int>>::InsertMultipleBefore(
    this: (CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int> > *)&this->m_bonemap,
    elem: 0,
    num: numbones);
  for ( i = 0; i < this->m_pModel->numbones; ++i )
    this->m_bonemap.m_Memory.m_pMemory[i] = i;
}

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x00405B30
// Name: int FindLocalBoneNamed(struct s_source_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FindLocalBoneNamed(const s_source_t *pSource, const char *pName)
{
  int v2; // edi
  s_node_t *localBone; // ebx
  s_node_t *i; // ebx
  const char *pNamea; // [esp+18h] [ebp+Ch]

  if ( pName == nullptr )
    return -1;
  v2 = 0;
  if ( pSource->numbones > 0 )
  {
    localBone = pSource->localBone;
    while ( _V_stricmp(s1: pName, s2: localBone->name) != 0 )
    {
      ++v2;
      ++localBone;
      if ( v2 >= pSource->numbones )
        goto LABEL_6;
    }
    return v2;
  }
LABEL_6:
  v2 = 0;
  pNamea = RenameBone(pName);
  if ( pSource->numbones <= 0 )
    return -1;
  for ( i = pSource->localBone; _V_stricmp(s1: pNamea, s2: i->name) != 0; ++i )
  {
    if ( ++v2 >= pSource->numbones )
      return -1;
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x00405BC0
// Name: public: int CCollisionModelSource::FindLocalBoneNamed(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCollisionModelSource::FindLocalBoneNamed(CCollisionModelSource *this, const char *pName)
{
  return FindLocalBoneNamed(pSource: this->m_pModel, pName);
}

//------------------------------------------------------------------------------
// Address: 0x00405BE0
// Name: void GlobalFace(struct s_face_t __near *,struct s_mesh_t __near *,struct s_face_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GlobalFace(s_face_t *pout, s_mesh_t *pmesh, s_face_t *pin)
{
  pout->a = pmesh->vertexoffset + pin->a;
  pout->b = pmesh->vertexoffset + pin->b;
  pout->c = pmesh->vertexoffset + pin->c;
}

//------------------------------------------------------------------------------
// Address: 0x00405C10
// Name: public: void CCollisionModelSource::ConvertToWorldSpace(class CUtlVector<class Vector,class CUtlMemory<class Vector,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionModelSource::ConvertToWorldSpace(
        CCollisionModelSource *this,
        CUtlVector<Vector,CUtlMemory<Vector,int> > *worldVerts)
{
  int v3; // esi
  s_source_t *v4; // edx
  Vector *v5; // eax
  int v6; // edx
  int v7; // ecx
  int v8; // ecx
  int v9; // ebx
  int v10; // ecx
  float v11; // xmm0_4
  bool v12; // zf
  s_source_t *v13; // ebx
  s_source_t *m_pModel; // edx
  Vector *m_pMemory; // eax
  int v16; // edx
  int v17; // ebx
  float v18; // xmm0_4
  float v19; // xmm1_4
  s_source_t *v20; // ebx
  matrix3x4_t pBoneToWorld[1024]; // [esp+20h] [ebp-C058h] BYREF
  matrix3x4_t out; // [esp+C020h] [ebp-58h] BYREF
  float in1[3]; // [esp+C050h] [ebp-28h] BYREF
  float v24; // [esp+C05Ch] [ebp-1Ch] BYREF
  float v25; // [esp+C060h] [ebp-18h]
  float v26; // [esp+C064h] [ebp-14h]
  int v27; // [esp+C068h] [ebp-10h]
  int v28; // [esp+C06Ch] [ebp-Ch]
  int v29; // [esp+C070h] [ebp-8h]
  int v30; // [esp+C074h] [ebp-4h]

  v3 = 0;
  if ( this->m_bAssumeWorldspace )
  {
    BuildRawTransforms(
      psource: this->m_pModel,
      pAnimationName: "BindPose",
      frame: 0,
      scale: this->m_pModel->scale,
      shift: &this->m_pModel->adjust,
      rotate: &this->m_pModel->rotation,
      flags: 0,
      boneToWorld: pBoneToWorld);
    m_pModel = this->m_pModel;
    v28 = 0;
    if ( m_pModel->numvertices > 0 )
    {
      m_pMemory = worldVerts->m_Memory.m_pMemory;
      v16 = 0;
      v30 = 0;
      do
      {
        m_pMemory[v3].x = 0.0;
        m_pMemory[v3].y = 0.0;
        m_pMemory[v3].z = 0.0;
        if ( *(int *)((char *)&this->m_pModel->vertex->boneweight.numbones + v16) > 0 )
        {
          v17 = v16 + 72;
          v29 = *(int *)((char *)&this->m_pModel->vertex->boneweight.numbones + v16);
          do
          {
            VectorTransform(
              in1: (const float *)((char *)&this->m_pModel->vertex->position.x + v16),
              in2: &pBoneToWorld[*(_DWORD *)((char *)this->m_pModel->vertex + v17 - 12)],
              out: &v24);
            v18 = *(float *)((char *)&this->m_pModel->vertex->material + v17);
            m_pMemory = worldVerts->m_Memory.m_pMemory;
            v16 = v30;
            m_pMemory[v3].x = (float)(v24 * v18) + worldVerts->m_Memory.m_pMemory[v3].x;
            m_pMemory[v3].y = (float)(v25 * v18) + m_pMemory[v3].y;
            v19 = (float)(v26 * v18) + m_pMemory[v3].z;
            v17 += 4;
            v12 = v29-- == 1;
            m_pMemory[v3].z = v19;
          }
          while ( !v12 );
        }
        v20 = this->m_pModel;
        v16 += 84;
        ++v3;
        ++v28;
        v30 = v16;
      }
      while ( v28 < v20->numvertices );
    }
  }
  else
  {
    CalcBoneTransforms(panimation: g_panimation[0], frame: 0, pBoneToWorld);
    v4 = this->m_pModel;
    v28 = 0;
    if ( v4->numvertices > 0 )
    {
      v5 = worldVerts->m_Memory.m_pMemory;
      v6 = 0;
      v30 = 0;
      do
      {
        v5[v3].x = 0.0;
        v5[v3].y = 0.0;
        v5[v3].z = 0.0;
        v7 = *(int *)((char *)&this->m_pModel->vertex->boneweight.numbones + v6);
        if ( v7 > 0 )
        {
          v27 = v6 + 72;
          v29 = v7;
          do
          {
            v8 = *(_DWORD *)((char *)this->m_pModel->vertex + v27 - 12);
            v9 = this->m_pModel->boneLocalToGlobal[v8];
            ConcatTransforms(in1: &this->m_pModel->boneToPose[v8], in2: &g_bonetable[v9].srcRealign, &out);
            VectorITransform(
              in1: (const float *)((char *)&this->m_pModel->vertex->position.x + v30),
              in2: &out,
              out: in1);
            VectorTransform(in1, in2: &pBoneToWorld[v9], out: &v24);
            v5 = worldVerts->m_Memory.m_pMemory;
            v10 = v27;
            v11 = *(float *)((char *)&this->m_pModel->vertex->material + v27);
            v5[v3].x = (float)(v24 * v11) + worldVerts->m_Memory.m_pMemory[v3].x;
            v5[v3].y = (float)(v25 * v11) + v5[v3].y;
            v12 = v29-- == 1;
            v5[v3].z = (float)(v26 * v11) + v5[v3].z;
            v27 = v10 + 4;
          }
          while ( !v12 );
          v6 = v30;
        }
        v13 = this->m_pModel;
        v6 += 84;
        ++v3;
        ++v28;
        v30 = v6;
      }
      while ( v28 < v13->numvertices );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405EE0
// Name: public: void CCollisionModelSource::ConvertToBoneSpace(int,class CUtlVector<class Vector,class CUtlMemory<class Vector,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionModelSource::ConvertToBoneSpace(
        CCollisionModelSource *this,
        int boneIndex,
        CUtlVector<Vector,CUtlMemory<Vector,int> > *boneVerts)
{
  s_source_t *m_pModel; // ecx
  int v5; // eax
  s_source_t *v6; // eax
  int v7; // ebx
  int v8; // edi
  int v9; // esi
  matrix3x4_t boneToPose; // [esp+Ch] [ebp-34h] BYREF
  CCollisionModelSource *v11; // [esp+3Ch] [ebp-4h]

  m_pModel = this->m_pModel;
  v5 = m_pModel->boneLocalToGlobal[boneIndex];
  v11 = this;
  if ( v5 >= 0 )
  {
    ConcatTransforms(in1: &m_pModel->boneToPose[boneIndex], in2: &g_bonetable[v5].srcRealign, out: &boneToPose);
  }
  else
  {
    MdlWarning(fmt: "Error! physics for unused bone %s\n", m_pModel->localBone[boneIndex].name);
    MatrixCopy(in: &this->m_pModel->boneToPose[boneIndex], out: &boneToPose);
  }
  v6 = this->m_pModel;
  v7 = 0;
  if ( this->m_pModel->numvertices > 0 )
  {
    v8 = 0;
    v9 = 0;
    do
    {
      VectorITransform(in1: &v6->vertex[v8].position.x, in2: &boneToPose, out: &boneVerts->m_Memory.m_pMemory[v9].x);
      v6 = v11->m_pModel;
      ++v7;
      ++v9;
      ++v8;
    }
    while ( v7 < v11->m_pModel->numvertices );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405FB0
// Name: public: bool CCollisionModelSource::ShouldProcessBone(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCollisionModelSource::ShouldProcessBone(CCollisionModelSource *this, int boneIndex)
{
  return boneIndex >= 0 && this->m_bonemap.m_Memory.m_pMemory[boneIndex] == boneIndex;
}

//------------------------------------------------------------------------------
// Address: 0x00405FD0
// Name: public: void CCollisionModelSource::SkipBone(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionModelSource::SkipBone(CCollisionModelSource *this, int boneIndex)
{
  if ( boneIndex >= 0 )
    this->m_bonemap.m_Memory.m_pMemory[boneIndex] = -1;
}

//------------------------------------------------------------------------------
// Address: 0x00405FF0
// Name: public: void CCollisionModelSource::MergeBones(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionModelSource::MergeBones(CCollisionModelSource *this, int parent, int child)
{
  int v3; // eax
  int *m_pMemory; // esi
  int v5; // edx
  int v6; // edi
  int numbones; // ecx

  v3 = parent;
  if ( parent >= 0 && child >= 0 )
  {
    m_pMemory = this->m_bonemap.m_Memory.m_pMemory;
    v5 = parent;
    v6 = 0;
    if ( m_pMemory[parent] != parent )
    {
      numbones = this->m_pModel->numbones;
      do
      {
        v3 = m_pMemory[v5];
        if ( ++v6 > numbones )
          break;
        if ( v3 < 0 )
          break;
        v5 = v3;
      }
      while ( m_pMemory[v3] != v3 );
    }
    m_pMemory[child] = v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406050
// Name: public: void CCollisionModelSource::MergeBones(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionModelSource::MergeBones(CCollisionModelSource *this, const char *parent, const char *child)
{
  int v4; // eax
  int LocalBoneNamed; // [esp-4h] [ebp-8h]

  LocalBoneNamed = FindLocalBoneNamed(pSource: this->m_pModel, pName: child);
  v4 = FindLocalBoneNamed(pSource: this->m_pModel, pName: parent);
  CCollisionModelSource::MergeBones(this, parent: v4, child: LocalBoneNamed);
}

//------------------------------------------------------------------------------
// Address: 0x00406090
// Name: public: void CCollisionModelSource::Simplify(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionModelSource::Simplify(CCollisionModelSource *this)
{
  CCollisionModelSource *v1; // edi
  s_source_t *m_pModel; // eax
  int v3; // edx
  s_source_t *v4; // esi
  int parent; // eax
  int v6; // ecx
  int *m_pMemory; // edi
  int v8; // edx
  int v9; // ebx
  int v10; // eax
  int numbones; // esi
  s_bonetable_t *v12; // esi
  int LocalBoneNamed; // ebx
  int v14; // eax
  int *v15; // edx
  int v16; // ecx
  int v17; // esi
  int v18; // edi
  int v20; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]

  v1 = this;
  m_pModel = this->m_pModel;
  v3 = 0;
  i = 0;
  if ( this->m_pModel->numbones > 0 )
  {
    v20 = 396;
    do
    {
      if ( m_pModel->boneLocalToGlobal[v3] < 0 && v3 >= 0 )
        v1->m_bonemap.m_Memory.m_pMemory[v3] = -1;
      v4 = v1->m_pModel;
      parent = *(_DWORD *)&v1->m_pModel->filename[v20];
      v6 = v3;
      if ( parent >= 0 )
      {
        do
        {
          if ( v4->boneLocalToGlobal[parent] != v1->m_pModel->boneLocalToGlobal[v3] )
            break;
          v6 = parent;
          parent = v4->localBone[parent].parent;
        }
        while ( parent >= 0 );
        if ( v6 != v3 && v6 >= 0 && v3 >= 0 )
        {
          m_pMemory = v1->m_bonemap.m_Memory.m_pMemory;
          v8 = v6;
          v9 = 0;
          v10 = v6;
          if ( m_pMemory[v6] != v6 )
          {
            numbones = v4->numbones;
            do
            {
              v10 = m_pMemory[v8];
              if ( ++v9 > numbones )
                break;
              if ( v10 < 0 )
                break;
              v8 = v10;
            }
            while ( m_pMemory[v10] != v10 );
          }
          m_pMemory[i] = v10;
          v1 = this;
          v3 = i;
        }
      }
      m_pModel = v1->m_pModel;
      v20 += 132;
      i = ++v3;
    }
    while ( v3 < v1->m_pModel->numbones );
  }
  v12 = &g_bonetable[g_rootIndex];
  LocalBoneNamed = FindLocalBoneNamed(pSource: v1->m_pModel, pName: v1->m_rootName);
  v14 = FindLocalBoneNamed(pSource: v1->m_pModel, pName: v12->name);
  if ( v14 >= 0 && LocalBoneNamed >= 0 )
  {
    v15 = v1->m_bonemap.m_Memory.m_pMemory;
    v16 = v14;
    v17 = 0;
    if ( v15[v14] != v14 )
    {
      v18 = v1->m_pModel->numbones;
      do
      {
        v14 = v15[v16];
        if ( ++v17 > v18 )
          break;
        if ( v14 < 0 )
          break;
        v16 = v14;
      }
      while ( v15[v14] != v14 );
    }
    v15[LocalBoneNamed] = v14;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004061F0
// Name: public: bool CCollisionModelSource::FaceHasVertOnBone(struct s_face_t const __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCollisionModelSource::FaceHasVertOnBone(
        CCollisionModelSource *this,
        const s_face_t *face,
        int boneIndex)
{
  s_vertexinfo_t *vertex; // ebx
  unsigned int a; // eax
  int numbones; // esi
  int p_boneweight; // eax
  int v8; // edx
  int *v9; // edi
  int v10; // eax
  unsigned int b; // eax
  int v12; // edi
  int v13; // eax
  int v14; // edx
  int *v15; // esi
  int v16; // eax
  unsigned int c; // eax
  int v18; // edi
  int v19; // eax
  int v20; // edx
  int *i; // esi
  int v22; // eax
  CCollisionModelSource *v23; // [esp+0h] [ebp-4h]

  v23 = this;
  if ( boneIndex < 0 )
    return 1;
  vertex = this->m_pModel->vertex;
  a = face->a;
  numbones = vertex[a].boneweight.numbones;
  p_boneweight = (int)&vertex[a].boneweight;
  v8 = 0;
  if ( numbones <= 0 )
  {
LABEL_9:
    b = face->b;
    v12 = vertex[b].boneweight.numbones;
    v13 = (int)&vertex[b].boneweight;
    v14 = 0;
    if ( v12 <= 0 )
    {
LABEL_15:
      c = face->c;
      v18 = vertex[c].boneweight.numbones;
      v19 = (int)&vertex[c].boneweight;
      v20 = 0;
      if ( v18 <= 0 )
        return 0;
      for ( i = (int *)(v19 + 4); ; ++i )
      {
        v22 = *i;
        if ( *i >= 0 )
          v22 = this->m_bonemap.m_Memory.m_pMemory[v22];
        if ( v22 == boneIndex )
          break;
        if ( ++v20 >= v18 )
          return 0;
      }
    }
    else
    {
      v15 = (int *)(v13 + 4);
      while ( 1 )
      {
        v16 = *v15;
        if ( *v15 >= 0 )
          v16 = this->m_bonemap.m_Memory.m_pMemory[v16];
        if ( v16 == boneIndex )
          break;
        this = v23;
        ++v14;
        ++v15;
        if ( v14 >= v12 )
          goto LABEL_15;
      }
    }
  }
  else
  {
    v9 = (int *)(p_boneweight + 4);
    while ( 1 )
    {
      v10 = *v9;
      if ( *v9 >= 0 )
        v10 = this->m_bonemap.m_Memory.m_pMemory[v10];
      if ( v10 == boneIndex )
        break;
      this = v23;
      ++v8;
      ++v9;
      if ( v8 >= numbones )
        goto LABEL_9;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004062E0
// Name: public: void CCollisionModelSource::InitBoneMap(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCollisionModelSource::InitBoneMap(CCollisionModelSource *this)
{
  int i; // eax
  int numbones; // [esp-4h] [ebp-Ch]

  numbones = this->m_pModel->numbones;
  this->m_bonemap.m_Size = 0;
  CUtlVector<s_bone_t *,CUtlMemory<s_bone_t *,int>>::InsertMultipleBefore(
    this: (CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int> > *)&this->m_bonemap,
    elem: 0,
    num: numbones);
  for ( i = 0; i < this->m_pModel->numbones; ++i )
    this->m_bonemap.m_Memory.m_pMemory[i] = i;
}

} // namespace studiomdl
