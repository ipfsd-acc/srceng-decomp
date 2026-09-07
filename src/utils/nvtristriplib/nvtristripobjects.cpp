// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/nvtristriplib/nvtristripobjects.cpp
// Functions: 39
// ============================================================

#include "utils\nvtristriplib\nvtristripobjects.h"

//------------------------------------------------------------------------------
// Address: 0x005B60D0
// Name: public: bool NvStripInfo::IsInStrip(class NvFaceInfo const __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall NvStripInfo::IsInStrip(NvStripInfo *this, const NvFaceInfo *faceInfo)
{
  int m_stripId; // edx

  if ( faceInfo == nullptr )
    return false;
  if ( this->m_experimentId < 0 )
    m_stripId = faceInfo->m_stripId;
  else
    m_stripId = faceInfo->m_testStripId;
  return m_stripId == this->m_stripId;
}

//------------------------------------------------------------------------------
// Address: 0x005B6110
// Name: public: static void NvStripifier::GetSharedVertices(class NvFaceInfo __near *,class NvFaceInfo __near *,int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NvStripifier::GetSharedVertices(NvFaceInfo *faceA, NvFaceInfo *faceB, int *vertex0, int *vertex1)
{
  int m_v0; // ecx

  *vertex0 = -1;
  *vertex1 = -1;
  m_v0 = faceB->m_v0;
  if ( faceB->m_v0 == faceA->m_v0 || m_v0 == faceA->m_v1 || m_v0 == faceA->m_v2 )
  {
    if ( *vertex0 != -1 )
      goto LABEL_16;
    *vertex0 = m_v0;
  }
  m_v0 = faceB->m_v1;
  if ( m_v0 == faceA->m_v0 || m_v0 == faceA->m_v1 || m_v0 == faceA->m_v2 )
  {
    if ( *vertex0 == -1 )
    {
      *vertex0 = m_v0;
      goto LABEL_11;
    }
LABEL_16:
    *vertex1 = m_v0;
    return;
  }
LABEL_11:
  m_v0 = faceB->m_v2;
  if ( m_v0 == faceA->m_v0 || m_v0 == faceA->m_v1 || m_v0 == faceA->m_v2 )
  {
    if ( *vertex0 == -1 )
    {
      *vertex0 = m_v0;
      return;
    }
    goto LABEL_16;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005B6180
// Name: public: static bool NvStripifier::IsDegenerate(class NvFaceInfo const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl NvStripifier::IsDegenerate(const NvFaceInfo *face)
{
  int m_v1; // edx
  bool result; // al
  int m_v2; // eax

  m_v1 = face->m_v1;
  result = face->m_v0 == m_v1 || (m_v2 = face->m_v2, face->m_v0 == m_v2) || m_v1 == m_v2;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005B61B0
// Name: protected: void NvStripifier::UpdateCacheFace(class VertexCache __near *,class NvFaceInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NvStripifier::UpdateCacheFace(NvStripifier *this, VertexCache *vcache, NvFaceInfo *face)
{
  int numEntries; // edx
  int v4; // ecx
  int *entries; // esi
  int m_v0; // esi
  int i; // ecx
  int v8; // edi
  int *v9; // edx
  int v10; // esi
  int v11; // ecx
  int *v12; // edx
  int v13; // ecx
  int j; // esi
  int v15; // edi
  int *v16; // edx
  int v17; // esi
  int v18; // ecx
  int *v19; // edx
  int v20; // ecx
  int k; // esi
  int v22; // edi
  int *v23; // edx

  numEntries = vcache->numEntries;
  v4 = 0;
  if ( numEntries <= 0 )
  {
LABEL_5:
    m_v0 = face->m_v0;
    for ( i = numEntries - 2; i >= 0; v9[1] = v8 )
    {
      v8 = vcache->entries[i];
      v9 = &vcache->entries[i--];
    }
    *vcache->entries = m_v0;
  }
  else
  {
    entries = vcache->entries;
    while ( *entries != face->m_v0 )
    {
      ++v4;
      ++entries;
      if ( v4 >= numEntries )
        goto LABEL_5;
    }
  }
  v10 = vcache->numEntries;
  v11 = 0;
  if ( v10 <= 0 )
  {
LABEL_12:
    v13 = vcache->numEntries - 2;
    for ( j = face->m_v1; v13 >= 0; v16[1] = v15 )
    {
      v15 = vcache->entries[v13];
      v16 = &vcache->entries[v13--];
    }
    *vcache->entries = j;
  }
  else
  {
    v12 = vcache->entries;
    while ( *v12 != face->m_v1 )
    {
      ++v11;
      ++v12;
      if ( v11 >= v10 )
        goto LABEL_12;
    }
  }
  v17 = vcache->numEntries;
  v18 = 0;
  if ( v17 <= 0 )
  {
LABEL_19:
    v20 = vcache->numEntries - 2;
    for ( k = face->m_v2; v20 >= 0; v23[1] = v22 )
    {
      v22 = vcache->entries[v20];
      v23 = &vcache->entries[v20--];
    }
    *vcache->entries = k;
  }
  else
  {
    v19 = vcache->entries;
    while ( *v19 != face->m_v2 )
    {
      ++v18;
      ++v19;
      if ( v18 >= v17 )
        goto LABEL_19;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005B6270
// Name: public: static struct std::_Tree_nod<class std::_Tset_traits<class NvFaceInfo __near *,struct std::less<class NvFaceInfo __near *>,class std::allocator<class NvFaceInfo __near *>,0>>::_Node __near * std::_Tree_val<class std::_Tset_traits<class NvFaceInfo __near *,struct std::less<class NvFaceInfo __near *>,class std::allocator<class NvFaceInfo __near *>,0>>::_Max(struct std::_Tree_nod<class std::_Tset_traits<class NvFaceInfo __near *,struct std::less<class NvFaceInfo __near *>,class std::allocator<class NvFaceInfo __near *>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *__cdecl std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0>>::_Max(
        std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *_Pnode)
{
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *result; // eax
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *i; // ecx

  result = _Pnode;
  for ( i = _Pnode->_Right; i->_Isnil == 0; i = i->_Right )
    result = i;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005B6290
// Name: public: static struct std::_Tree_nod<class std::_Tset_traits<class NvFaceInfo __near *,struct std::less<class NvFaceInfo __near *>,class std::allocator<class NvFaceInfo __near *>,0>>::_Node __near * std::_Tree_val<class std::_Tset_traits<class NvFaceInfo __near *,struct std::less<class NvFaceInfo __near *>,class std::allocator<class NvFaceInfo __near *>,0>>::_Min(struct std::_Tree_nod<class std::_Tset_traits<class NvFaceInfo __near *,struct std::less<class NvFaceInfo __near *>,class std::allocator<class NvFaceInfo __near *>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *__cdecl std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0>>::_Min(
        std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *_Pnode)
{
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *result; // eax
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *i; // ecx

  result = _Pnode;
  for ( i = _Pnode->_Left; i->_Isnil == 0; i = i->_Left )
    result = i;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005B62B0
// Name: public: class std::_Tree_unchecked_const_iterator<class std::_Tree_val<class std::_Tset_traits<class NvFaceInfo __near *,struct std::less<class NvFaceInfo __near *>,class std::allocator<class NvFaceInfo __near *>,0>>,struct std::_Iterator_base0> __near & std::_Tree_unchecked_const_iterator<class std::_Tree_val<class std::_Tset_traits<class NvFaceInfo __near *,struct std::less<class NvFaceInfo __near *>,class std::allocator<class NvFaceInfo __near *>,0>>,struct std::_Iterator_base0>::operator++(void)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >,std::_Iterator_base0> *__thiscall std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0>>,std::_Iterator_base0>::operator++(
        std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >,std::_Iterator_base0> *this)
{
  std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >,std::_Iterator_base0> *result; // eax
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *Ptr; // edx
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *Right; // ecx
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *j; // edx
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *i; // edx

  result = this;
  Ptr = this->_Ptr;
  if ( this->_Ptr->_Isnil == 0 )
  {
    Right = Ptr->_Right;
    if ( Right->_Isnil != 0 )
    {
      for ( i = Ptr->_Parent; i->_Isnil == 0; i = i->_Parent )
      {
        if ( result->_Ptr != i->_Right )
          break;
        result->_Ptr = i;
      }
      result->_Ptr = i;
    }
    else
    {
      for ( j = Right->_Left; j->_Isnil == 0; j = j->_Left )
        Right = j;
      result->_Ptr = Right;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005B6300
// Name: public: class std::_Tree_unchecked_const_iterator<class std::_Tree_val<class std::_Tset_traits<class NvFaceInfo __near *,struct std::less<class NvFaceInfo __near *>,class std::allocator<class NvFaceInfo __near *>,0>>,struct std::_Iterator_base0> __near & std::_Tree_unchecked_const_iterator<class std::_Tree_val<class std::_Tset_traits<class NvFaceInfo __near *,struct std::less<class NvFaceInfo __near *>,class std::allocator<class NvFaceInfo __near *>,0>>,struct std::_Iterator_base0>::operator--(void)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >,std::_Iterator_base0> *__thiscall std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0>>,std::_Iterator_base0>::operator--(
        std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >,std::_Iterator_base0> *this)
{
  std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >,std::_Iterator_base0> *result; // eax
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *Ptr; // ecx
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *Left; // edx
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *Right; // ecx
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *v5; // edx

  result = this;
  Ptr = this->_Ptr;
  if ( Ptr->_Isnil != 0 )
  {
    result->_Ptr = Ptr->_Right;
    return result;
  }
  Left = Ptr->_Left;
  if ( Ptr->_Left->_Isnil == 0 )
  {
    Right = Left->_Right;
    if ( Right->_Isnil == 0 )
    {
      do
      {
        v5 = Right;
        Right = Right->_Right;
      }
      while ( Right->_Isnil == 0 );
      result->_Ptr = v5;
      return result;
    }
LABEL_11:
    result->_Ptr = Left;
    return result;
  }
  for ( Left = Ptr->_Parent; Left->_Isnil == 0; Left = Left->_Parent )
  {
    if ( result->_Ptr != Left->_Left )
      break;
    result->_Ptr = Left;
  }
  if ( result->_Ptr->_Isnil == 0 )
    goto LABEL_11;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005B6360
// Name: protected: static class NvEdgeInfo __near * NvStripifier::FindEdgeInfo(class std::vector<class NvEdgeInfo __near *,class std::allocator<class NvEdgeInfo __near *>> __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
NvEdgeInfo *__cdecl NvStripifier::FindEdgeInfo(std::vector<NvEdgeInfo *> *edgeInfos, int v0, int v1)
{
  NvEdgeInfo *result; // eax
  int m_v0; // ecx

  result = edgeInfos->_Myfirst[v0];
  while ( result != nullptr )
  {
    m_v0 = result->m_v0;
    if ( m_v0 == v0 )
    {
      if ( result->m_v1 == v1 )
        return result;
      result = result->m_nextV0;
    }
    else
    {
      if ( m_v0 == v1 )
        return result;
      result = result->m_nextV1;
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x005B63A0
// Name: protected: int NvStripifier::FindStartPoint(class std::vector<class NvFaceInfo __near *,class std::allocator<class NvFaceInfo __near *>> __near &,class std::vector<class NvEdgeInfo __near *,class std::allocator<class NvEdgeInfo __near *>> __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall NvStripifier::FindStartPoint(
        NvStripifier *this,
        std::vector<NvFaceInfo *> *faceInfos,
        std::vector<NvEdgeInfo *> *edgeInfos)
{
  NvEdgeInfo **Myfirst; // eax
  NvFaceInfo **v4; // ebx
  int m_v0; // edx
  int m_v1; // edi
  NvEdgeInfo *v7; // ecx
  int v8; // esi
  NvFaceInfo *m_face1; // ecx
  int v10; // esi
  int m_v2; // edi
  NvEdgeInfo *v12; // ecx
  int v13; // edx
  NvFaceInfo *m_face0; // ecx
  int v15; // esi
  int v16; // edi
  NvEdgeInfo *v17; // ecx
  int v18; // edx
  NvFaceInfo *v19; // ecx
  unsigned int v21; // [esp+0h] [ebp-10h]
  int bestIndex; // [esp+4h] [ebp-Ch]
  int bestCtr; // [esp+8h] [ebp-8h]
  unsigned int i; // [esp+Ch] [ebp-4h]
  int ctr; // [esp+18h] [ebp+8h]

  bestCtr = -1;
  bestIndex = -1;
  i = 0;
  v21 = faceInfos->_Mylast - faceInfos->_Myfirst;
  if ( v21 == 0 )
    return bestIndex;
  Myfirst = edgeInfos->_Myfirst;
  v4 = faceInfos->_Myfirst;
  do
  {
    m_v0 = (*v4)->m_v0;
    m_v1 = (*v4)->m_v1;
    v7 = Myfirst[m_v0];
    ctr = 0;
    while ( v7 != nullptr )
    {
      v8 = v7->m_v0;
      if ( v8 == m_v0 )
      {
        if ( v7->m_v1 == m_v1 )
          goto LABEL_11;
        v7 = v7->m_nextV0;
      }
      else
      {
        if ( v8 == m_v1 )
          goto LABEL_11;
        v7 = v7->m_nextV1;
      }
    }
    v7 = nullptr;
    if ( m_v0 == m_v1 )
    {
LABEL_15:
      ctr = 1;
      goto LABEL_16;
    }
LABEL_11:
    if ( v7->m_face0 == *v4 )
      m_face1 = v7->m_face1;
    else
      m_face1 = v7->m_face0;
    if ( m_face1 == nullptr )
      goto LABEL_15;
LABEL_16:
    v10 = (*v4)->m_v1;
    m_v2 = (*v4)->m_v2;
    v12 = Myfirst[v10];
    while ( v12 != nullptr )
    {
      v13 = v12->m_v0;
      if ( v13 == v10 )
      {
        if ( v12->m_v1 == m_v2 )
          goto LABEL_24;
        v12 = v12->m_nextV0;
      }
      else
      {
        if ( v13 == m_v2 )
          goto LABEL_24;
        v12 = v12->m_nextV1;
      }
    }
    v12 = nullptr;
    if ( v10 == m_v2 )
    {
LABEL_28:
      ++ctr;
      goto LABEL_29;
    }
LABEL_24:
    if ( v12->m_face0 == *v4 )
      m_face0 = v12->m_face1;
    else
      m_face0 = v12->m_face0;
    if ( m_face0 == nullptr )
      goto LABEL_28;
LABEL_29:
    v15 = (*v4)->m_v2;
    v16 = (*v4)->m_v0;
    v17 = Myfirst[v15];
    while ( v17 != nullptr )
    {
      v18 = v17->m_v0;
      if ( v18 == v15 )
      {
        if ( v17->m_v1 == v16 )
          goto LABEL_37;
        v17 = v17->m_nextV0;
      }
      else
      {
        if ( v18 == v16 )
          goto LABEL_37;
        v17 = v17->m_nextV1;
      }
    }
    v17 = nullptr;
    if ( v15 == v16 )
    {
LABEL_41:
      ++ctr;
      goto LABEL_42;
    }
LABEL_37:
    if ( v17->m_face0 == *v4 )
      v19 = v17->m_face1;
    else
      v19 = v17->m_face0;
    if ( v19 == nullptr )
      goto LABEL_41;
LABEL_42:
    if ( ctr > bestCtr )
    {
      bestCtr = ctr;
      bestIndex = i;
    }
    ++v4;
    ++i;
  }
  while ( i < v21 );
  if ( bestCtr == 0 )
    return -1;
  return bestIndex;
}

//------------------------------------------------------------------------------
// Address: 0x005B6500
// Name: protected: static int NvStripifier::GetNextIndex(class std::vector<unsigned short,class std::allocator<unsigned short>> const __near &,class NvFaceInfo __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl NvStripifier::GetNextIndex(const std::vector<unsigned short> *indices, NvFaceInfo *face)
{
  int v2; // eax
  int v3; // edx
  int v4; // ecx
  int m_v2; // ebx
  int m_v0; // esi
  int m_v1; // edi

  v2 = indices->_Mylast - indices->_Myfirst;
  v3 = indices->_Myfirst[v2 - 2];
  v4 = indices->_Myfirst[v2 - 1];
  m_v2 = face->m_v2;
  m_v0 = face->m_v0;
  m_v1 = face->m_v1;
  if ( face->m_v0 != v3 && m_v0 != v4 )
  {
    if ( m_v1 != v3 && m_v1 != v4 || m_v2 != v3 && m_v2 != v4 )
    {
      printf(format: "GetNextIndex: Triangle doesn't have all of its vertices\n");
      printf(format: "GetNextIndex: Duplicate triangle probably got us derailed\n");
    }
    return m_v0;
  }
  if ( m_v1 != v3 && m_v1 != v4 )
  {
    if ( m_v0 != v3 && m_v0 != v4 || m_v2 != v3 && m_v2 != v4 )
    {
      printf(format: "GetNextIndex: Triangle doesn't have all of its vertices\n");
      printf(format: "GetNextIndex: Duplicate triangle probably got us derailed\n");
    }
    return m_v1;
  }
  if ( m_v2 == v3 || m_v2 == v4 )
  {
    if ( m_v0 == m_v1 || m_v0 == m_v2 )
      return m_v0;
    if ( m_v1 == m_v2 )
      return m_v1;
    return -1;
  }
  else
  {
    if ( m_v0 != v3 && m_v0 != v4 || m_v1 != v3 && m_v1 != v4 )
    {
      printf(format: "GetNextIndex: Triangle doesn't have all of its vertices\n");
      printf(format: "GetNextIndex: Duplicate triangle probably got us derailed\n");
    }
    return m_v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005B65E0
// Name: public: bool NvStripInfo::Unique(class std::vector<class NvFaceInfo __near *,class std::allocator<class NvFaceInfo __near *>> __near &,class NvFaceInfo __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall NvStripInfo::Unique(NvStripInfo *this, std::vector<NvFaceInfo *> *faceVec, NvFaceInfo *face)
{
  unsigned int v3; // edx
  int v4; // ebx
  NvFaceInfo **i; // esi
  NvFaceInfo *v6; // eax
  int m_v0; // ecx
  NvFaceInfo *v8; // eax
  int m_v1; // ecx
  NvFaceInfo *v10; // eax
  int m_v2; // ecx
  bool bv2; // [esp+Dh] [ebp-3h]
  bool bv1; // [esp+Eh] [ebp-2h]
  bool bv0; // [esp+Fh] [ebp-1h]

  v3 = faceVec->_Mylast - faceVec->_Myfirst;
  v4 = 0;
  bv2 = false;
  bv1 = false;
  bv0 = false;
  if ( v3 == 0 )
    return 1;
  for ( i = faceVec->_Myfirst; ; ++i )
  {
    if ( !bv0 )
    {
      v6 = *i;
      m_v0 = face->m_v0;
      if ( (*i)->m_v0 == face->m_v0 || v6->m_v1 == m_v0 || v6->m_v2 == m_v0 )
        bv0 = true;
    }
    if ( !bv1 )
    {
      v8 = *i;
      m_v1 = face->m_v1;
      if ( (*i)->m_v0 == m_v1 || v8->m_v1 == m_v1 || v8->m_v2 == m_v1 )
        bv1 = true;
    }
    if ( !bv2 )
    {
      v10 = *i;
      m_v2 = face->m_v2;
      if ( (*i)->m_v0 == m_v2 || v10->m_v1 == m_v2 || v10->m_v2 == m_v2 )
        bv2 = true;
    }
    if ( bv0 && bv1 && bv2 )
      break;
    if ( ++v4 >= v3 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x005B66A0
// Name: public: bool NvStripInfo::SharesEdge(class NvFaceInfo const __near *,class std::vector<class NvEdgeInfo __near *,class std::allocator<class NvEdgeInfo __near *>> __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall NvStripInfo::SharesEdge(
        NvStripInfo *this,
        const NvFaceInfo *faceInfo,
        std::vector<NvEdgeInfo *> *edgeInfos)
{
  int m_v0; // ebx
  int m_v1; // edx
  NvEdgeInfo *v6; // eax
  int v7; // ecx
  NvFaceInfo *m_face0; // ecx
  int v9; // ecx
  NvFaceInfo *m_face1; // eax
  int m_v2; // edi
  NvEdgeInfo *EdgeInfo; // eax
  NvFaceInfo *v14; // ecx
  NvEdgeInfo *v16; // edi
  bool result; // al

  m_v0 = faceInfo->m_v0;
  m_v1 = faceInfo->m_v1;
  v6 = edgeInfos->_Myfirst[faceInfo->m_v0];
  while ( v6 != nullptr )
  {
    v7 = v6->m_v0;
    if ( v7 == m_v0 )
    {
      if ( v6->m_v1 == m_v1 )
        goto LABEL_9;
      v6 = v6->m_nextV0;
    }
    else
    {
      if ( v7 == m_v1 )
        goto LABEL_9;
      v6 = v6->m_nextV1;
    }
  }
  v6 = nullptr;
LABEL_9:
  m_face0 = v6->m_face0;
  if ( m_face0 != nullptr )
  {
    v9 = this->m_experimentId < 0 ? m_face0->m_stripId : m_face0->m_testStripId;
    if ( v9 == this->m_stripId )
      return true;
  }
  m_face1 = v6->m_face1;
  if ( m_face1 != nullptr
    && (this->m_experimentId < 0 ? m_face1->m_stripId == this->m_stripId : m_face1->m_testStripId == this->m_stripId) )
  {
    return true;
  }
  m_v2 = faceInfo->m_v2;
  EdgeInfo = NvStripifier::FindEdgeInfo(edgeInfos, v0: m_v1, v1: m_v2);
  v14 = EdgeInfo->m_face0;
  if ( v14 != nullptr
    && (this->m_experimentId < 0 ? v14->m_stripId == this->m_stripId : v14->m_testStripId == this->m_stripId) )
  {
    return true;
  }
  if ( NvStripInfo::IsInStrip(this, faceInfo: EdgeInfo->m_face1) )
    return true;
  v16 = NvStripifier::FindEdgeInfo(edgeInfos, v0: m_v2, v1: m_v0);
  if ( NvStripInfo::IsInStrip(this, faceInfo: v16->m_face0) )
    return true;
  result = NvStripInfo::IsInStrip(this, faceInfo: v16->m_face1);
  if ( result )
    return true;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005B67B0
// Name: protected: bool NvStripifier::FindTraversal(class std::vector<class NvFaceInfo __near *,class std::allocator<class NvFaceInfo __near *>> __near &,class std::vector<class NvEdgeInfo __near *,class std::allocator<class NvEdgeInfo __near *>> __near &,class NvStripInfo __near *,class NvStripStartInfo __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall NvStripifier::FindTraversal(
        NvStripifier *this,
        std::vector<NvFaceInfo *> *faceInfos,
        std::vector<NvEdgeInfo *> *edgeInfos,
        NvStripInfo *strip,
        NvStripStartInfo *startInfo)
{
  NvEdgeInfo *v6; // edi
  NvFaceInfo *m_face0; // esi
  int *p_m_v0; // eax
  int m_experimentId; // ecx
  int v10; // edx
  int v11; // edx
  bool v12; // zf
  NvFaceInfo *untouchedFace; // [esp+Ch] [ebp-4h]
  int v; // [esp+20h] [ebp+10h]

  if ( strip->m_startInfo.m_toV1 )
    v = strip->m_startInfo.m_startEdge->m_v1;
  else
    v = strip->m_startInfo.m_startEdge->m_v0;
  v6 = edgeInfos->_Myfirst[v];
  untouchedFace = nullptr;
  while ( v6 != nullptr )
  {
    m_face0 = v6->m_face0;
    p_m_v0 = &v6->m_face1->m_v0;
    if ( m_face0 != nullptr )
    {
      m_experimentId = strip->m_experimentId;
      v10 = m_experimentId < 0 ? m_face0->m_stripId : m_face0->m_testStripId;
      if ( v10 != strip->m_stripId )
      {
        if ( p_m_v0 == nullptr )
          goto LABEL_23;
        if ( p_m_v0[3] < 0 && (m_experimentId < 0 || p_m_v0[5] != m_experimentId) )
        {
          untouchedFace = v6->m_face1;
          break;
        }
      }
    }
    if ( p_m_v0 != nullptr )
    {
      v11 = strip->m_experimentId;
      v12 = v11 < 0 ? p_m_v0[3] == strip->m_stripId : p_m_v0[4] == strip->m_stripId;
      if ( !v12 && m_face0 != nullptr && m_face0->m_stripId < 0 && (v11 < 0 || m_face0->m_experimentId != v11) )
      {
        untouchedFace = v6->m_face0;
        break;
      }
    }
LABEL_23:
    if ( v6->m_v0 == v )
      v6 = v6->m_nextV0;
    else
      v6 = v6->m_nextV1;
  }
  startInfo->m_startFace = untouchedFace;
  startInfo->m_startEdge = v6;
  if ( v6 != nullptr )
  {
    if ( NvStripInfo::SharesEdge(this: strip, faceInfo: untouchedFace, edgeInfos) )
    {
      startInfo->m_toV1 = v6->m_v0 == v;
      return untouchedFace != nullptr;
    }
    startInfo->m_toV1 = v6->m_v1 == v;
  }
  return untouchedFace != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x005B68D0
// Name: protected: void NvStripifier::UpdateCacheStrip(class VertexCache __near *,class NvStripInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NvStripifier::UpdateCacheStrip(NvStripifier *this, VertexCache *vcache, NvStripInfo *strip)
{
  unsigned int v3; // ecx
  int numEntries; // esi
  int v5; // edx
  int m_v0; // edi
  int *entries; // ecx
  int v8; // ecx
  int j; // esi
  int v10; // edi
  int *v11; // edx
  int v12; // esi
  int v13; // ecx
  int *v14; // edx
  int m_v1; // esi
  int k; // ecx
  int v17; // edi
  int *v18; // edx
  int v19; // esi
  int v20; // ecx
  int *v21; // edx
  int m_v2; // esi
  int m; // ecx
  int v24; // edi
  int *v25; // edx
  int i; // [esp+4h] [ebp-4h]

  v3 = 0;
  for ( i = 0; v3 < strip->m_faces._Mylast - strip->m_faces._Myfirst; i = v3 )
  {
    numEntries = vcache->numEntries;
    v5 = 0;
    if ( numEntries <= 0 )
    {
LABEL_6:
      v8 = vcache->numEntries - 2;
      for ( j = strip->m_faces._Myfirst[i]->m_v0; v8 >= 0; v11[1] = v10 )
      {
        v10 = vcache->entries[v8];
        v11 = &vcache->entries[v8--];
      }
      *vcache->entries = j;
    }
    else
    {
      m_v0 = strip->m_faces._Myfirst[v3]->m_v0;
      entries = vcache->entries;
      while ( *entries != m_v0 )
      {
        ++v5;
        ++entries;
        if ( v5 >= numEntries )
          goto LABEL_6;
      }
    }
    v12 = vcache->numEntries;
    v13 = 0;
    if ( v12 <= 0 )
    {
LABEL_13:
      m_v1 = strip->m_faces._Myfirst[i]->m_v1;
      for ( k = vcache->numEntries - 2; k >= 0; v18[1] = v17 )
      {
        v17 = vcache->entries[k];
        v18 = &vcache->entries[k--];
      }
      *vcache->entries = m_v1;
    }
    else
    {
      v14 = vcache->entries;
      while ( *v14 != strip->m_faces._Myfirst[i]->m_v1 )
      {
        ++v13;
        ++v14;
        if ( v13 >= v12 )
          goto LABEL_13;
      }
    }
    v19 = vcache->numEntries;
    v20 = 0;
    if ( v19 <= 0 )
    {
LABEL_20:
      m_v2 = strip->m_faces._Myfirst[i]->m_v2;
      for ( m = vcache->numEntries - 2; m >= 0; v25[1] = v24 )
      {
        v24 = vcache->entries[m];
        v25 = &vcache->entries[m--];
      }
      *vcache->entries = m_v2;
    }
    else
    {
      v21 = vcache->entries;
      while ( *v21 != strip->m_faces._Myfirst[i]->m_v2 )
      {
        ++v20;
        ++v21;
        if ( v20 >= v19 )
          goto LABEL_20;
      }
    }
    v3 = i + 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005B6A00
// Name: protected: float NvStripifier::CalcNumHitsStrip(class VertexCache __near *,class NvStripInfo __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall NvStripifier::CalcNumHitsStrip(NvStripifier *this, VertexCache *vcache, NvStripInfo *strip)
{
  unsigned int v4; // edi
  int v5; // ecx
  int numEntries; // eax
  int v7; // edx
  int *entries; // ecx
  int v9; // edx
  int *v10; // ecx
  int v11; // edx
  int *v12; // ecx
  int numFaces; // [esp+8h] [ebp-8h]
  int numHits; // [esp+Ch] [ebp-4h]
  NvStripInfo *stripa; // [esp+1Ch] [ebp+Ch]

  v4 = 0;
  v5 = strip->m_faces._Mylast - strip->m_faces._Myfirst;
  numHits = 0;
  numFaces = 0;
  stripa = (NvStripInfo *)v5;
  if ( v5 != 0 )
  {
    numEntries = vcache->numEntries;
    numFaces = v5;
    do
    {
      v7 = 0;
      if ( numEntries > 0 )
      {
        entries = vcache->entries;
        while ( *entries != strip->m_faces._Myfirst[v4]->m_v0 )
        {
          ++v7;
          ++entries;
          if ( v7 >= numEntries )
            goto LABEL_9;
        }
        ++numHits;
      }
LABEL_9:
      v9 = 0;
      if ( numEntries > 0 )
      {
        v10 = vcache->entries;
        while ( *v10 != strip->m_faces._Myfirst[v4]->m_v1 )
        {
          ++v9;
          ++v10;
          if ( v9 >= numEntries )
            goto LABEL_15;
        }
        ++numHits;
      }
LABEL_15:
      v11 = 0;
      if ( numEntries > 0 )
      {
        v12 = vcache->entries;
        while ( *v12 != strip->m_faces._Myfirst[v4]->m_v2 )
        {
          ++v11;
          ++v12;
          if ( v11 >= numEntries )
            goto LABEL_21;
        }
        ++numHits;
      }
LABEL_21:
      ++v4;
    }
    while ( v4 < (unsigned int)stripa );
  }
  return (double)numHits / (double)numFaces;
}

//------------------------------------------------------------------------------
// Address: 0x005B6AC0
// Name: protected: int NvStripifier::NumNeighbors(class NvFaceInfo __near *,class std::vector<class NvEdgeInfo __near *,class std::allocator<class NvEdgeInfo __near *>> __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall NvStripifier::NumNeighbors(NvStripifier *this, NvFaceInfo *face, std::vector<NvEdgeInfo *> *edgeInfoVec)
{
  NvEdgeInfo **Myfirst; // eax
  int m_v0; // ebx
  NvEdgeInfo *v5; // ecx
  int m_v1; // esi
  int v7; // edx
  NvFaceInfo *m_face1; // ecx
  NvEdgeInfo *v9; // ecx
  int m_v2; // edi
  int v11; // edx
  NvFaceInfo *m_face0; // ecx
  int v13; // esi
  NvEdgeInfo *v14; // ecx
  int v15; // edx
  NvFaceInfo *v16; // ecx
  int result; // eax
  int numNeighbors; // [esp+Ch] [ebp-4h]

  Myfirst = edgeInfoVec->_Myfirst;
  m_v0 = face->m_v0;
  v5 = edgeInfoVec->_Myfirst[face->m_v0];
  m_v1 = face->m_v1;
  numNeighbors = 0;
  while ( v5 != nullptr )
  {
    v7 = v5->m_v0;
    if ( v7 == m_v0 )
    {
      if ( v5->m_v1 == m_v1 )
        goto LABEL_9;
      v5 = v5->m_nextV0;
    }
    else
    {
      if ( v7 == m_v1 )
        goto LABEL_9;
      v5 = v5->m_nextV1;
    }
  }
  v5 = nullptr;
  if ( m_v0 != m_v1 )
  {
LABEL_9:
    if ( v5->m_face0 == face )
      m_face1 = v5->m_face1;
    else
      m_face1 = v5->m_face0;
    if ( m_face1 != nullptr )
      numNeighbors = 1;
  }
  v9 = Myfirst[m_v1];
  m_v2 = face->m_v2;
  while ( v9 != nullptr )
  {
    v11 = v9->m_v0;
    if ( v11 == m_v1 )
    {
      if ( v9->m_v1 == m_v2 )
        goto LABEL_22;
      v9 = v9->m_nextV0;
    }
    else
    {
      if ( v11 == m_v2 )
        goto LABEL_22;
      v9 = v9->m_nextV1;
    }
  }
  v9 = nullptr;
  if ( m_v1 == m_v2 )
  {
    v13 = numNeighbors;
  }
  else
  {
LABEL_22:
    if ( v9->m_face0 == face )
      m_face0 = v9->m_face1;
    else
      m_face0 = v9->m_face0;
    v13 = numNeighbors;
    if ( m_face0 != nullptr )
      v13 = numNeighbors + 1;
  }
  v14 = Myfirst[m_v2];
  while ( v14 != nullptr )
  {
    v15 = v14->m_v0;
    if ( v15 == m_v2 )
    {
      if ( v14->m_v1 == m_v0 )
        goto LABEL_36;
      v14 = v14->m_nextV0;
    }
    else
    {
      if ( v15 == m_v0 )
        goto LABEL_36;
      v14 = v14->m_nextV1;
    }
  }
  v14 = nullptr;
  if ( m_v2 == m_v0 )
    return v13;
LABEL_36:
  if ( v14->m_face0 == face )
    v16 = v14->m_face1;
  else
    v16 = v14->m_face0;
  result = v13 + 1;
  if ( v16 == nullptr )
    return v13;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005B6BC0
// Name: protected: float NvStripifier::AvgStripSize(class std::vector<class NvStripInfo __near *,class std::allocator<class NvStripInfo __near *>> const __near &)
// Source: json
//------------------------------------------------------------------------------
double __thiscall NvStripifier::AvgStripSize(NvStripifier *this, const std::vector<NvStripInfo *> *strips)
{
  NvStripInfo **Myfirst; // ecx
  int v3; // esi
  int v4; // edi
  int v5; // eax
  unsigned int v6; // edx
  NvStripInfo *v7; // eax
  int v8; // ebx
  NvStripInfo **v10; // [esp+Ch] [ebp-Ch]
  int v11; // [esp+10h] [ebp-8h]
  int v12; // [esp+14h] [ebp-4h]
  int i; // [esp+20h] [ebp+8h]

  Myfirst = strips->_Myfirst;
  v3 = strips->_Mylast - strips->_Myfirst;
  v4 = 0;
  v5 = 0;
  v11 = 0;
  v12 = 0;
  v10 = strips->_Myfirst;
  if ( v3 >= 2 )
  {
    v6 = ((unsigned int)(v3 - 2) >> 1) + 1;
    i = 2 * v6;
    do
    {
      v7 = *Myfirst;
      v8 = (char *)(*Myfirst)->m_faces._Mylast - (char *)(*Myfirst)->m_faces._Myfirst;
      Myfirst += 2;
      v11 += (v8 >> 2) - v7->m_numDegenerates;
      v12 += (*(Myfirst - 1))->m_faces._Mylast - (*(Myfirst - 1))->m_faces._Myfirst - (*(Myfirst - 1))->m_numDegenerates;
      --v6;
    }
    while ( v6 != 0 );
    v5 = i;
    Myfirst = v10;
  }
  if ( v5 < v3 )
    v4 = Myfirst[v5]->m_faces._Mylast - Myfirst[v5]->m_faces._Myfirst - Myfirst[v5]->m_numDegenerates;
  return (double)(v4 + v11 + v12) / (double)v3;
}

//------------------------------------------------------------------------------
// Address: 0x005B6CC0
// Name: protected: void std::_Tree<class std::_Tset_traits<class NvFaceInfo __near *,struct std::less<class NvFaceInfo __near *>,class std::allocator<class NvFaceInfo __near *>,0>>::_Lrotate(struct std::_Tree_nod<class std::_Tset_traits<class NvFaceInfo __near *,struct std::less<class NvFaceInfo __near *>,class std::allocator<class NvFaceInfo __near *>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0>>::_Lrotate(
        std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> > *this,
        std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *_Wherenode)
{
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *Right; // eax
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *Myhead; // ecx
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *Parent; // ecx

  Right = _Wherenode->_Right;
  _Wherenode->_Right = Right->_Left;
  if ( Right->_Left->_Isnil == 0 )
    Right->_Left->_Parent = _Wherenode;
  Right->_Parent = _Wherenode->_Parent;
  Myhead = this->_Myhead;
  if ( _Wherenode == Myhead->_Parent )
  {
    Myhead->_Parent = Right;
    Right->_Left = _Wherenode;
    _Wherenode->_Parent = Right;
  }
  else
  {
    Parent = _Wherenode->_Parent;
    if ( _Wherenode == Parent->_Left )
      Parent->_Left = Right;
    else
      Parent->_Right = Right;
    Right->_Left = _Wherenode;
    _Wherenode->_Parent = Right;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005B6D20
// Name: protected: void std::_Tree<class std::_Tset_traits<class NvFaceInfo __near *,struct std::less<class NvFaceInfo __near *>,class std::allocator<class NvFaceInfo __near *>,0>>::_Rrotate(struct std::_Tree_nod<class std::_Tset_traits<class NvFaceInfo __near *,struct std::less<class NvFaceInfo __near *>,class std::allocator<class NvFaceInfo __near *>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0>>::_Rrotate(
        std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> > *this,
        std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *_Wherenode)
{
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *Left; // eax
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *Right; // esi
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *Myhead; // ecx
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *Parent; // ecx

  Left = _Wherenode->_Left;
  _Wherenode->_Left = _Wherenode->_Left->_Right;
  Right = Left->_Right;
  if ( Right->_Isnil == 0 )
    Right->_Parent = _Wherenode;
  Left->_Parent = _Wherenode->_Parent;
  Myhead = this->_Myhead;
  if ( _Wherenode == Myhead->_Parent )
  {
    Myhead->_Parent = Left;
    Left->_Right = _Wherenode;
    _Wherenode->_Parent = Left;
  }
  else
  {
    Parent = _Wherenode->_Parent;
    if ( _Wherenode == Parent->_Right )
      Parent->_Right = Left;
    else
      Parent->_Left = Left;
    Left->_Right = _Wherenode;
    _Wherenode->_Parent = Left;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005B6D80
// Name: void std::_Cons_val<class std::allocator<class NvFaceInfo __near *>,class NvFaceInfo __near *,class NvFaceInfo __near * __near &>(class std::allocator<class NvFaceInfo __near *> __near &,class NvFaceInfo __near * __near *,class NvFaceInfo __near * __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Cons_val<std::allocator<NvFaceInfo *>,NvFaceInfo *,NvFaceInfo * &>(
        std::allocator<NvFaceInfo *> *_Alval,
        NvFaceInfo **_Pdest,
        NvFaceInfo **_Src)
{
  if ( _Pdest != nullptr )
    *_Pdest = *_Src;
}

//------------------------------------------------------------------------------
// Address: 0x005B6E20
// Name: protected: class std::_Tree_const_iterator<class std::_Tree_val<class std::_Tset_traits<class NvFaceInfo __near *,struct std::less<class NvFaceInfo __near *>,class std::allocator<class NvFaceInfo __near *>,0>>> std::_Tree<class std::_Tset_traits<class NvFaceInfo __near *,struct std::less<class NvFaceInfo __near *>,class std::allocator<class NvFaceInfo __near *>,0>>::_Insert(bool,struct std::_Tree_nod<class std::_Tset_traits<class NvFaceInfo __near *,struct std::less<class NvFaceInfo __near *>,class std::allocator<class NvFaceInfo __near *>,0>>::_Node __near *,struct std::_Tree_nod<class std::_Tset_traits<class NvFaceInfo __near *,struct std::less<class NvFaceInfo __near *>,class std::allocator<class NvFaceInfo __near *>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> > > *__thiscall std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0>>::_Insert(
        std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> > *this,
        std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> > > *result,
        bool _Addleft,
        std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *_Wherenode,
        std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *_Newnode)
{
  unsigned int Mysize; // eax
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *v6; // edi
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *Myhead; // edx
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *v8; // edx
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *v9; // edx
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *v10; // eax
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *Parent; // edx
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *v12; // esi
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *Right; // esi
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *v14; // edx
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *v15; // esi
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *v16; // esi
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *v17; // edx
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *Left; // esi
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *v19; // edi
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *v20; // edi
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *v21; // edi
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *v22; // esi
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *v23; // edx
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *v24; // esi
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *v25; // esi
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *v26; // esi
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *v27; // edi
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *v28; // edi
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *v29; // ecx

  Mysize = this->_Mysize;
  if ( Mysize >= 0x3FFFFFFE )
  {
    free(pMem: _Newnode);
    std::_Xlength_error(_Message: "map/set<T> too long");
  }
  this->_Mysize = Mysize + 1;
  v6 = _Newnode;
  _Newnode->_Parent = _Wherenode;
  Myhead = this->_Myhead;
  if ( _Wherenode == Myhead )
  {
    Myhead->_Parent = _Newnode;
    this->_Myhead->_Left = _Newnode;
    this->_Myhead->_Right = _Newnode;
  }
  else if ( _Addleft )
  {
    _Wherenode->_Left = _Newnode;
    v8 = this->_Myhead;
    if ( _Wherenode == v8->_Left )
      v8->_Left = _Newnode;
  }
  else
  {
    _Wherenode->_Right = _Newnode;
    v9 = this->_Myhead;
    if ( _Wherenode == v9->_Right )
      v9->_Right = _Newnode;
  }
  v10 = _Newnode;
  while ( v10->_Parent->_Color == 0 )
  {
    Parent = v10->_Parent;
    v12 = Parent->_Parent;
    if ( Parent == v12->_Left )
    {
      Right = v12->_Right;
      if ( Right->_Color != 0 )
      {
        if ( v10 == Parent->_Right )
        {
          v10 = v10->_Parent;
          v14 = Parent->_Right;
          v10->_Right = v14->_Left;
          if ( v14->_Left->_Isnil == 0 )
            v14->_Left->_Parent = v10;
          v14->_Parent = v10->_Parent;
          v15 = this->_Myhead;
          if ( v10 == v15->_Parent )
          {
            v15->_Parent = v14;
          }
          else
          {
            v16 = v10->_Parent;
            if ( v10 == v16->_Left )
              v16->_Left = v14;
            else
              v16->_Right = v14;
          }
          v14->_Left = v10;
          v10->_Parent = v14;
        }
        v10->_Parent->_Color = 1;
        v10->_Parent->_Parent->_Color = 0;
        v17 = v10->_Parent->_Parent;
        Left = v17->_Left;
        v17->_Left = v17->_Left->_Right;
        v19 = Left->_Right;
        if ( v19->_Isnil == 0 )
          v19->_Parent = v17;
        Left->_Parent = v17->_Parent;
        v20 = this->_Myhead;
        if ( v17 == v20->_Parent )
        {
          v20->_Parent = Left;
          Left->_Right = v17;
        }
        else
        {
          v21 = v17->_Parent;
          if ( v17 == v21->_Right )
            v21->_Right = Left;
          else
            v21->_Left = Left;
          Left->_Right = v17;
        }
LABEL_50:
        v6 = _Newnode;
        v17->_Parent = Left;
        continue;
      }
      Parent->_Color = 1;
      Right->_Color = 1;
      v10->_Parent->_Parent->_Color = 0;
      v10 = v10->_Parent->_Parent;
    }
    else
    {
      v22 = v12->_Left;
      if ( v22->_Color != 0 )
      {
        if ( v10 == Parent->_Left )
        {
          v10 = v10->_Parent;
          v23 = Parent->_Left;
          v10->_Left = v23->_Right;
          v24 = v23->_Right;
          if ( v24->_Isnil == 0 )
            v24->_Parent = v10;
          v23->_Parent = v10->_Parent;
          v25 = this->_Myhead;
          if ( v10 == v25->_Parent )
          {
            v25->_Parent = v23;
          }
          else
          {
            v26 = v10->_Parent;
            if ( v10 == v26->_Right )
              v26->_Right = v23;
            else
              v26->_Left = v23;
          }
          v23->_Right = v10;
          v10->_Parent = v23;
        }
        v10->_Parent->_Color = 1;
        v10->_Parent->_Parent->_Color = 0;
        v17 = v10->_Parent->_Parent;
        Left = v17->_Right;
        v17->_Right = Left->_Left;
        if ( Left->_Left->_Isnil == 0 )
          Left->_Left->_Parent = v17;
        Left->_Parent = v17->_Parent;
        v27 = this->_Myhead;
        if ( v17 == v27->_Parent )
        {
          v27->_Parent = Left;
        }
        else
        {
          v28 = v17->_Parent;
          if ( v17 == v28->_Left )
            v28->_Left = Left;
          else
            v28->_Right = Left;
        }
        Left->_Left = v17;
        goto LABEL_50;
      }
      Parent->_Color = 1;
      v22->_Color = 1;
      v10->_Parent->_Parent->_Color = 0;
      v10 = v10->_Parent->_Parent;
    }
  }
  v29 = this->_Myhead->_Parent;
  result->_Ptr = v6;
  v29->_Color = 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005B7050
// Name: public: struct std::_Tree_nod<class std::_Tset_traits<class NvFaceInfo __near *,struct std::less<class NvFaceInfo __near *>,class std::allocator<class NvFaceInfo __near *>,0>>::_Node __near * std::_Tree_val<class std::_Tset_traits<class NvFaceInfo __near *,struct std::less<class NvFaceInfo __near *>,class std::allocator<class NvFaceInfo __near *>,0>>::_Buynode<class NvFaceInfo __near * __near &>(class NvFaceInfo __near * __near &)
// Source: json
//------------------------------------------------------------------------------
NvFaceInfo **__thiscall std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0>>::_Buynode<NvFaceInfo * &>(
        std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> > *this,
        NvFaceInfo **_Val)
{
  NvFaceInfo **v3; // esi
  int v5; // [esp+0h] [ebp-2Ch] BYREF
  std::exception pExceptionObject; // [esp+Ch] [ebp-20h] BYREF
  void *pMem; // [esp+18h] [ebp-14h]
  int *v8; // [esp+1Ch] [ebp-10h]
  int v9; // [esp+28h] [ebp-4h]

  v8 = &v5;
  v3 = (NvFaceInfo **)MemAlloc_Alloc(nSize: 0x14u);
  pMem = v3;
  if ( v3 == nullptr )
  {
    _Val = nullptr;
    std::exception::exception(this: &pExceptionObject, _What: (const char *const *)&_Val);
    pExceptionObject.__vftable = (std::exception_vtbl *)&std::bad_alloc::`vftable';
    _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI2_AVbad_alloc_std__);
  }
  *v3 = (NvFaceInfo *)this->_Myhead;
  v3[1] = (NvFaceInfo *)this->_Myhead;
  v3[2] = (NvFaceInfo *)this->_Myhead;
  *((_WORD *)v3 + 8) = 0;
  v9 = 0;
  std::_Cons_val<std::allocator<NvFaceInfo *>,NvFaceInfo *,NvFaceInfo * &>(
    _Alval: &this->_Alval,
    _Pdest: v3 + 3,
    _Src: _Val);
  v9 = -1;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x005B71D0
// Name: public: class std::_Tree_const_iterator<class std::_Tree_val<class std::_Tset_traits<class NvFaceInfo __near *,struct std::less<class NvFaceInfo __near *>,class std::allocator<class NvFaceInfo __near *>,0>>> std::_Tree<class std::_Tset_traits<class NvFaceInfo __near *,struct std::less<class NvFaceInfo __near *>,class std::allocator<class NvFaceInfo __near *>,0>>::erase(class std::_Tree_const_iterator<class std::_Tree_val<class std::_Tset_traits<class NvFaceInfo __near *,struct std::less<class NvFaceInfo __near *>,class std::allocator<class NvFaceInfo __near *>,0>>>)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> > > *__thiscall std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0>>::erase(
        std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> > *this,
        std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> > > *result,
        std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> > > _Where)
{
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *Ptr; // ebx
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *Right; // edi
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *v5; // eax
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *Parent; // esi
  std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> > *v7; // ecx
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *Myhead; // eax
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *v9; // eax
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *v10; // ecx
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *v11; // ecx
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *v12; // ecx
  char Color; // cl
  std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> > *i; // ecx
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *Left; // eax
  unsigned int Mysize; // eax
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *_Erasednode; // [esp+10h] [ebp-8h]

  Ptr = _Where._Ptr;
  if ( _Where._Ptr->_Isnil != 0 )
    std::_Xout_of_range(_Message: "invalid map/set<T> iterator");
  _Erasednode = _Where._Ptr;
  std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0>>,std::_Iterator_base0>::operator++(this: &_Where);
  if ( Ptr->_Left->_Isnil != 0 )
  {
    Right = Ptr->_Right;
LABEL_8:
    Parent = Ptr->_Parent;
    if ( Right->_Isnil == 0 )
      Right->_Parent = Parent;
    v7 = this;
    Myhead = this->_Myhead;
    if ( Myhead->_Parent == Ptr )
    {
      Myhead->_Parent = Right;
    }
    else if ( Parent->_Left == Ptr )
    {
      Parent->_Left = Right;
    }
    else
    {
      Parent->_Right = Right;
    }
    if ( this->_Myhead->_Left == Ptr )
    {
      if ( Right->_Isnil != 0 )
      {
        v9 = Parent;
      }
      else
      {
        v9 = std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0>>::_Min(_Pnode: Right);
        v7 = this;
      }
      v7->_Myhead->_Left = v9;
    }
    v10 = v7->_Myhead;
    if ( v10->_Right == Ptr )
    {
      if ( Right->_Isnil != 0 )
        v10->_Right = Parent;
      else
        v10->_Right = std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0>>::_Max(_Pnode: Right);
    }
    goto LABEL_35;
  }
  if ( Ptr->_Right->_Isnil != 0 )
  {
    Right = Ptr->_Left;
    goto LABEL_8;
  }
  v5 = _Where._Ptr;
  Right = _Where._Ptr->_Right;
  if ( _Where._Ptr == Ptr )
    goto LABEL_8;
  Ptr->_Left->_Parent = _Where._Ptr;
  v5->_Left = Ptr->_Left;
  if ( v5 == Ptr->_Right )
  {
    Parent = v5;
  }
  else
  {
    Parent = v5->_Parent;
    if ( Right->_Isnil == 0 )
      Right->_Parent = Parent;
    Parent->_Left = Right;
    v5->_Right = Ptr->_Right;
    Ptr->_Right->_Parent = v5;
  }
  v11 = this->_Myhead;
  if ( v11->_Parent == Ptr )
  {
    v11->_Parent = v5;
  }
  else
  {
    v12 = Ptr->_Parent;
    if ( v12->_Left == Ptr )
      v12->_Left = v5;
    else
      v12->_Right = v5;
  }
  v5->_Parent = Ptr->_Parent;
  Color = v5->_Color;
  v5->_Color = Ptr->_Color;
  Ptr->_Color = Color;
LABEL_35:
  if ( _Erasednode->_Color == 1 )
  {
    for ( i = this; Right != i->_Myhead->_Parent; Parent = Parent->_Parent )
    {
      if ( Right->_Color != 1 )
        break;
      Left = Parent->_Left;
      if ( Right == Parent->_Left )
      {
        Left = Parent->_Right;
        if ( Left->_Color == 0 )
        {
          Left->_Color = 1;
          Parent->_Color = 0;
          std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0>>::_Lrotate(
            this: i,
            _Wherenode: Parent);
          Left = Parent->_Right;
          i = this;
        }
        if ( Left->_Isnil != 0 )
          goto LABEL_53;
        if ( Left->_Left->_Color != 1 || Left->_Right->_Color != 1 )
        {
          if ( Left->_Right->_Color == 1 )
          {
            Left->_Left->_Color = 1;
            Left->_Color = 0;
            std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0>>::_Rrotate(
              this: i,
              _Wherenode: Left);
            Left = Parent->_Right;
            i = this;
          }
          Left->_Color = Parent->_Color;
          Parent->_Color = 1;
          Left->_Right->_Color = 1;
          std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0>>::_Lrotate(
            this: i,
            _Wherenode: Parent);
          break;
        }
      }
      else
      {
        if ( Left->_Color == 0 )
        {
          Left->_Color = 1;
          Parent->_Color = 0;
          std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0>>::_Rrotate(
            this: i,
            _Wherenode: Parent);
          Left = Parent->_Left;
          i = this;
        }
        if ( Left->_Isnil != 0 )
          goto LABEL_53;
        if ( Left->_Right->_Color != 1 || Left->_Left->_Color != 1 )
        {
          if ( Left->_Left->_Color == 1 )
          {
            Left->_Right->_Color = 1;
            Left->_Color = 0;
            std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0>>::_Lrotate(
              this: i,
              _Wherenode: Left);
            Left = Parent->_Left;
            i = this;
          }
          Left->_Color = Parent->_Color;
          Parent->_Color = 1;
          Left->_Left->_Color = 1;
          std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0>>::_Rrotate(
            this: i,
            _Wherenode: Parent);
          break;
        }
      }
      Left->_Color = 0;
LABEL_53:
      Right = Parent;
    }
    Right->_Color = 1;
  }
  free(pMem: _Erasednode);
  Mysize = this->_Mysize;
  if ( Mysize != 0 )
    this->_Mysize = Mysize - 1;
  result->_Ptr = _Where._Ptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005B7420
// Name: protected: void std::_Tree<class std::_Tset_traits<class NvFaceInfo __near *,struct std::less<class NvFaceInfo __near *>,class std::allocator<class NvFaceInfo __near *>,0>>::_Erase(struct std::_Tree_nod<class std::_Tset_traits<class NvFaceInfo __near *,struct std::less<class NvFaceInfo __near *>,class std::allocator<class NvFaceInfo __near *>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0>>::_Erase(
        std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> > *this,
        std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *_Rootnode)
{
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *v2; // edi
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *i; // esi

  v2 = _Rootnode;
  for ( i = _Rootnode; i->_Isnil == 0; v2 = i )
  {
    std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0>>::_Erase(
      this,
      _Rootnode: i->_Right);
    i = i->_Left;
    free(pMem: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005B7460
// Name: public: struct std::pair<class std::_Tree_const_iterator<class std::_Tree_val<class std::_Tset_traits<class NvFaceInfo __near *,struct std::less<class NvFaceInfo __near *>,class std::allocator<class NvFaceInfo __near *>,0>>>,bool> std::_Tree<class std::_Tset_traits<class NvFaceInfo __near *,struct std::less<class NvFaceInfo __near *>,class std::allocator<class NvFaceInfo __near *>,0>>::_Linsert(struct std::_Tree_nod<class std::_Tset_traits<class NvFaceInfo __near *,struct std::less<class NvFaceInfo __near *>,class std::allocator<class NvFaceInfo __near *>,0>>::_Node __near *,bool)
// Source: json
//------------------------------------------------------------------------------
std::pair<std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> > >,bool> *__thiscall std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0>>::_Linsert(
        std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> > *this,
        std::pair<std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> > >,bool> *result,
        std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *_Node,
        std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> > > _Leftish)
{
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *v4; // edx
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *Myhead; // ecx
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *Parent; // eax
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *v8; // esi
  bool v9; // cl
  NvFaceInfo *Myval; // edi
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *Ptr; // edi
  bool _Addleft; // [esp+Ch] [ebp-4h]

  v4 = _Node;
  Myhead = this->_Myhead;
  Parent = Myhead->_Parent;
  v8 = Myhead;
  v9 = true;
  _Addleft = true;
  if ( Parent->_Isnil == 0 )
  {
    Myval = _Node->_Myval;
    do
    {
      v8 = Parent;
      if ( LOBYTE(_Leftish._Ptr) != 0 )
        v9 = Parent->_Myval >= Myval;
      else
        v9 = Myval < Parent->_Myval;
      _Addleft = v9;
      if ( v9 )
        Parent = Parent->_Left;
      else
        Parent = Parent->_Right;
    }
    while ( Parent->_Isnil == 0 );
  }
  Ptr = v8;
  _Leftish._Ptr = v8;
  if ( v9 )
  {
    if ( v8 == this->_Myhead->_Left )
    {
      result->first = (std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> > >)std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0>>::_Insert(this, result: &_Leftish, _Addleft: true, _Wherenode: v8, _Newnode: _Node)->_Ptr;
      result->second = true;
      return result;
    }
    std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0>>,std::_Iterator_base0>::operator--(this: &_Leftish);
    Ptr = _Leftish._Ptr;
    v4 = _Node;
  }
  if ( Ptr->_Myval >= v4->_Myval )
  {
    free(pMem: v4);
    result->first._Ptr = Ptr;
    result->second = false;
  }
  else
  {
    result->first = (std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> > >)std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0>>::_Insert(this, result: &_Leftish, _Addleft, _Wherenode: v8, _Newnode: v4)->_Ptr;
    result->second = true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005B7540
// Name: public: NvStripifier::NvStripifier(void)
// Source: json
//------------------------------------------------------------------------------
NvStripifier *__thiscall NvStripifier::NvStripifier(NvStripifier *this)
{
  this->indices._Myfirst = nullptr;
  this->indices._Mylast = nullptr;
  this->indices._Myend = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005B7550
// Name: public: NvStripifier::~NvStripifier(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NvStripifier::~NvStripifier(NvStripifier *this)
{
  if ( this->indices._Myfirst != nullptr )
    free(pMem: this->indices._Myfirst);
  this->indices._Myfirst = nullptr;
  this->indices._Mylast = nullptr;
  this->indices._Myend = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x005B7710
// Name: public: void std::_Tree<class std::_Tset_traits<class NvFaceInfo __near *,struct std::less<class NvFaceInfo __near *>,class std::allocator<class NvFaceInfo __near *>,0>>::clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0>>::clear(
        std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> > *this)
{
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *Parent; // ebx
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *i; // esi

  Parent = this->_Myhead->_Parent;
  for ( i = Parent; i->_Isnil == 0; Parent = i )
  {
    std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0>>::_Erase(
      this,
      _Rootnode: i->_Right);
    i = i->_Left;
    free(pMem: Parent);
  }
  this->_Myhead->_Parent = this->_Myhead;
  this->_Myhead->_Left = this->_Myhead;
  this->_Myhead->_Right = this->_Myhead;
  this->_Mysize = 0;
}

//------------------------------------------------------------------------------
// Address: 0x005B7760
// Name: public: void NvStripInfo::Combine(class std::vector<class NvFaceInfo __near *,class std::allocator<class NvFaceInfo __near *>> const __near &,class std::vector<class NvFaceInfo __near *,class std::allocator<class NvFaceInfo __near *>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NvStripInfo::Combine(
        NvStripInfo *this,
        const std::vector<NvFaceInfo *> *forward,
        const std::vector<NvFaceInfo *> *backward)
{
  const std::vector<NvFaceInfo *> *v3; // eax
  int v4; // ebx
  const std::vector<NvFaceInfo *> *v6; // eax
  int v7; // ebx
  NvFaceInfo **v8; // esi
  NvFaceInfo **Mylast; // eax
  NvFaceInfo **v10; // edx
  NvFaceInfo **v11; // ecx
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // ecx
  unsigned int v15; // ecx
  NvFaceInfo **v16; // eax
  NvFaceInfo **Myend; // ecx
  NvFaceInfo **Myfirst; // edx
  unsigned int v19; // eax
  unsigned int v20; // eax
  unsigned int v21; // ecx
  unsigned int v22; // ecx
  NvFaceInfo **v23; // eax
  NvFaceInfo **v24; // esi
  NvFaceInfo **v25; // eax
  NvFaceInfo **v26; // edx
  NvFaceInfo **v27; // ecx
  int v28; // esi
  unsigned int v29; // eax
  unsigned int v30; // eax
  unsigned int v31; // ecx
  unsigned int v32; // ecx
  NvFaceInfo **v33; // eax
  NvFaceInfo **v34; // ecx
  NvFaceInfo **v35; // edx
  unsigned int v36; // eax
  unsigned int v37; // eax
  unsigned int v38; // ecx
  unsigned int v39; // ecx
  NvFaceInfo **v40; // eax
  int i; // [esp+10h] [ebp-4h]
  int ia; // [esp+10h] [ebp-4h]
  int ib; // [esp+10h] [ebp-4h]
  const std::vector<NvFaceInfo *> *backwarda; // [esp+20h] [ebp+Ch]

  v3 = backward;
  v4 = backward->_Mylast - backward->_Myfirst - 1;
  i = v4;
  if ( v4 >= 0 )
  {
    while ( 1 )
    {
      v8 = &v3->_Myfirst[v4];
      Mylast = this->m_faces._Mylast;
      if ( v8 >= Mylast || (v10 = this->m_faces._Myfirst) > v8 )
      {
        Myend = this->m_faces._Myend;
        if ( Mylast == Myend )
        {
          Myfirst = this->m_faces._Myfirst;
          v19 = Mylast - Myfirst;
          if ( v19 > 0x3FFFFFFE )
LABEL_31:
            std::_Xlength_error(_Message: "vector<T> too long");
          v20 = v19 + 1;
          v21 = Myend - Myfirst;
          if ( v20 > v21 )
          {
            if ( 0x3FFFFFFF - (v21 >> 1) >= v21 )
              v22 = (v21 >> 1) + v21;
            else
              v22 = 0;
            if ( v22 < v20 )
              v22 = v20;
            std::vector<int>::reserve(this: (std::vector<int> *)&this->m_faces, _Count: v22);
            v4 = i;
          }
        }
        v23 = this->m_faces._Mylast;
        if ( v23 != nullptr )
          *v23 = *v8;
      }
      else
      {
        v11 = this->m_faces._Myend;
        ib = v8 - v10;
        if ( Mylast == v11 )
        {
          v12 = Mylast - v10;
          if ( v12 > 0x3FFFFFFE )
            goto LABEL_31;
          v13 = v12 + 1;
          v14 = v11 - v10;
          if ( v13 > v14 )
          {
            if ( 0x3FFFFFFF - (v14 >> 1) >= v14 )
              v15 = (v14 >> 1) + v14;
            else
              v15 = 0;
            if ( v15 < v13 )
              v15 = v13;
            std::vector<int>::reserve(this: (std::vector<int> *)&this->m_faces, _Count: v15);
          }
        }
        v16 = this->m_faces._Mylast;
        if ( v16 != nullptr )
          *v16 = this->m_faces._Myfirst[ib];
      }
      ++this->m_faces._Mylast;
      i = --v4;
      if ( v4 < 0 )
        break;
      v3 = backward;
    }
  }
  v6 = forward;
  backwarda = nullptr;
  v7 = forward->_Mylast - forward->_Myfirst;
  ia = v7;
  if ( v7 > 0 )
  {
    while ( 1 )
    {
      v24 = &v6->_Myfirst[(_DWORD)backwarda];
      v25 = this->m_faces._Mylast;
      if ( v24 >= v25 || (v26 = this->m_faces._Myfirst) > v24 )
      {
        v34 = this->m_faces._Myend;
        if ( v25 == v34 )
        {
          v35 = this->m_faces._Myfirst;
          v36 = v25 - v35;
          if ( v36 > 0x3FFFFFFE )
            goto LABEL_31;
          v37 = v36 + 1;
          v38 = v34 - v35;
          if ( v37 > v38 )
          {
            if ( 0x3FFFFFFF - (v38 >> 1) >= v38 )
              v39 = (v38 >> 1) + v38;
            else
              v39 = 0;
            if ( v39 < v37 )
              v39 = v37;
            std::vector<int>::reserve(this: (std::vector<int> *)&this->m_faces, _Count: v39);
            v7 = ia;
          }
        }
        v40 = this->m_faces._Mylast;
        if ( v40 != nullptr )
          *v40 = *v24;
      }
      else
      {
        v27 = this->m_faces._Myend;
        v28 = v24 - v26;
        if ( v25 == v27 )
        {
          v29 = v25 - v26;
          if ( v29 > 0x3FFFFFFE )
            goto LABEL_31;
          v30 = v29 + 1;
          v31 = v27 - v26;
          if ( v30 > v31 )
          {
            if ( 0x3FFFFFFF - (v31 >> 1) >= v31 )
              v32 = (v31 >> 1) + v31;
            else
              v32 = 0;
            if ( v32 < v30 )
              v32 = v30;
            std::vector<int>::reserve(this: (std::vector<int> *)&this->m_faces, _Count: v32);
            v7 = ia;
          }
        }
        v33 = this->m_faces._Mylast;
        if ( v33 != nullptr )
          *v33 = this->m_faces._Myfirst[v28];
      }
      ++this->m_faces._Mylast;
      backwarda = (const std::vector<NvFaceInfo *> *)((char *)backwarda + 1);
      if ( (int)backwarda >= v7 )
        break;
      v6 = forward;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005B7AE0
// Name: public: class std::_Tree_const_iterator<class std::_Tree_val<class std::_Tset_traits<class NvFaceInfo __near *,struct std::less<class NvFaceInfo __near *>,class std::allocator<class NvFaceInfo __near *>,0>>> std::_Tree<class std::_Tset_traits<class NvFaceInfo __near *,struct std::less<class NvFaceInfo __near *>,class std::allocator<class NvFaceInfo __near *>,0>>::erase(class std::_Tree_const_iterator<class std::_Tree_val<class std::_Tset_traits<class NvFaceInfo __near *,struct std::less<class NvFaceInfo __near *>,class std::allocator<class NvFaceInfo __near *>,0>>>,class std::_Tree_const_iterator<class std::_Tree_val<class std::_Tset_traits<class NvFaceInfo __near *,struct std::less<class NvFaceInfo __near *>,class std::allocator<class NvFaceInfo __near *>,0>>>)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> > > *__thiscall std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0>>::erase(
        std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> > *this,
        std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> > > *result,
        std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> > > _First,
        std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> > > _Last)
{
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *Myhead; // eax
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *Ptr; // ecx
  std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> > > v8; // edx
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *Right; // eax
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *v10; // ecx
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *j; // eax
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *i; // eax
  std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> > > v13; // [esp+4h] [ebp-4h] BYREF

  Myhead = this->_Myhead;
  Ptr = _First._Ptr;
  if ( _First._Ptr == Myhead->_Left && _Last._Ptr == Myhead )
  {
    std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0>>::clear(this);
    result->_Ptr = this->_Myhead->_Left;
    return result;
  }
  else
  {
    for ( ; _First._Ptr != _Last._Ptr; Ptr = _First._Ptr )
    {
      v8._Ptr = Ptr;
      if ( Ptr->_Isnil == 0 )
      {
        Right = Ptr->_Right;
        if ( Right->_Isnil != 0 )
        {
          for ( i = Ptr->_Parent; i->_Isnil == 0; i = i->_Parent )
          {
            if ( Ptr != i->_Right )
              break;
            Ptr = i;
          }
          _First._Ptr = i;
        }
        else
        {
          v10 = Ptr->_Right;
          for ( j = Right->_Left; j->_Isnil == 0; j = j->_Left )
            v10 = j;
          _First._Ptr = v10;
        }
      }
      std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0>>::erase(
        this,
        result: &v13,
        _Where: v8);
    }
    result->_Ptr = Ptr;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005B7B80
// Name: protected: void NvStripifier::BuildStripifyInfo(class std::vector<class NvFaceInfo __near *,class std::allocator<class NvFaceInfo __near *>> __near &,class std::vector<class NvEdgeInfo __near *,class std::allocator<class NvEdgeInfo __near *>> __near &,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NvStripifier::BuildStripifyInfo(
        NvStripifier *this,
        std::vector<NvFaceInfo *> *faceInfos,
        std::vector<NvEdgeInfo *> *edgeInfos,
        const unsigned __int16 maxIndex)
{
  __int64 v4; // rax
  signed int v5; // edi
  int v6; // eax
  int v7; // edi
  int v8; // esi
  int v9; // ebx
  NvFaceInfo *v10; // eax
  NvEdgeInfo *v11; // eax
  int m_v0; // ecx
  NvEdgeInfo *v13; // eax
  NvEdgeInfo *v14; // eax
  int v15; // ecx
  NvFaceInfo *v16; // edx
  NvEdgeInfo *v17; // eax
  NvEdgeInfo *v18; // esi
  int v19; // eax
  NvFaceInfo *v20; // edx
  NvEdgeInfo *v21; // eax
  NvFaceInfo *v22; // edx
  NvFaceInfo **Mylast; // eax
  NvFaceInfo **Myfirst; // edx
  NvFaceInfo **Myend; // ecx
  int v26; // esi
  unsigned int v27; // eax
  unsigned int v28; // eax
  unsigned int v29; // ecx
  unsigned int v30; // ecx
  NvFaceInfo **v31; // eax
  NvFaceInfo **v32; // edi
  unsigned int v33; // ecx
  NvFaceInfo **v34; // edx
  NvFaceInfo *v35; // eax
  std::vector<NvFaceInfo *> *v36; // ecx
  NvFaceInfo **v37; // eax
  std::vector<NvFaceInfo *> *v38; // ecx
  NvFaceInfo **v39; // eax
  NvFaceInfo **v40; // eax
  std::vector<NvFaceInfo *> *v41; // esi
  NvFaceInfo **v42; // ecx
  unsigned int v43; // eax
  unsigned int v44; // eax
  unsigned int v45; // ecx
  unsigned int v46; // ecx
  NvFaceInfo **v47; // eax
  signed int v48; // [esp+Ch] [ebp-28h]
  int i; // [esp+1Ch] [ebp-18h]
  int index; // [esp+20h] [ebp-14h]
  NvEdgeInfo *edgeInfo12; // [esp+24h] [ebp-10h]
  NvEdgeInfo *edgeInfo01; // [esp+28h] [ebp-Ch]
  NvFaceInfo *faceInfo; // [esp+2Ch] [ebp-8h] BYREF
  bool bFaceUpdated[4]; // [esp+30h] [ebp-4h] BYREF
  char maxIndex_3; // [esp+47h] [ebp+13h]

  v4 = 1431655766LL * (this->indices._Mylast - this->indices._Myfirst);
  v5 = HIDWORD(v4) + (HIDWORD(v4) >> 31);
  v48 = v5;
  std::vector<int>::reserve(this: (std::vector<int> *)faceInfos, _Count: v5);
  std::vector<NvEdgeInfo *>::resize(this: edgeInfos, _Newsize: maxIndex + 1);
  v6 = 0;
  if ( maxIndex != -1 )
  {
    do
      edgeInfos->_Myfirst[v6++] = nullptr;
    while ( v6 < maxIndex + 1 );
  }
  index = 0;
  i = 0;
  if ( v5 <= 0 )
    return;
  do
  {
    v7 = this->indices._Myfirst[index];
    v8 = this->indices._Myfirst[index + 1];
    v9 = this->indices._Myfirst[index + 2];
    maxIndex_3 = 1;
    memset(bFaceUpdated, 0, 3);
    index += 3;
    if ( (_WORD)v7 == (_WORD)v8 || (_WORD)v7 == (_WORD)v9 || (_WORD)v8 == (_WORD)v9 )
      goto LABEL_102;
    v10 = (NvFaceInfo *)MemAlloc_Alloc(nSize: 0x18u);
    if ( v10 != nullptr )
    {
      v10->m_v0 = v7;
      v10->m_v1 = v8;
      v10->m_v2 = v9;
      v10->m_stripId = -1;
      v10->m_testStripId = -1;
      v10->m_experimentId = -1;
      faceInfo = v10;
    }
    else
    {
      faceInfo = nullptr;
    }
    v11 = edgeInfos->_Myfirst[v7];
    while ( v11 != nullptr )
    {
      m_v0 = v11->m_v0;
      if ( m_v0 == v7 )
      {
        if ( v11->m_v1 == v8 )
          goto LABEL_19;
        v11 = v11->m_nextV0;
      }
      else
      {
        if ( m_v0 == v8 )
        {
LABEL_19:
          edgeInfo01 = v11;
          if ( v11->m_face1 == nullptr )
          {
            v11->m_face1 = faceInfo;
            bFaceUpdated[0] = true;
          }
          goto LABEL_21;
        }
        v11 = v11->m_nextV1;
      }
    }
    maxIndex_3 = 0;
    v13 = (NvEdgeInfo *)MemAlloc_Alloc(nSize: 0x1Cu);
    if ( v13 != nullptr )
    {
      v13->m_v0 = v7;
      v13->m_v1 = v8;
      v13->m_face0 = nullptr;
      v13->m_face1 = nullptr;
      v13->m_nextV0 = nullptr;
      v13->m_nextV1 = nullptr;
      v13->m_refCount = 2;
      edgeInfo01 = v13;
    }
    else
    {
      edgeInfo01 = nullptr;
      v13 = nullptr;
    }
    v13->m_nextV0 = edgeInfos->_Myfirst[v7];
    v13->m_nextV1 = edgeInfos->_Myfirst[v8];
    edgeInfos->_Myfirst[v7] = v13;
    v16 = faceInfo;
    edgeInfos->_Myfirst[v8] = v13;
    v13->m_face0 = v16;
LABEL_21:
    v14 = edgeInfos->_Myfirst[v8];
    if ( v14 == nullptr )
    {
LABEL_30:
      maxIndex_3 = 0;
      v17 = (NvEdgeInfo *)MemAlloc_Alloc(nSize: 0x1Cu);
      if ( v17 != nullptr )
      {
        v17->m_v0 = v8;
        v17->m_v1 = v9;
        v17->m_face0 = nullptr;
        v17->m_face1 = nullptr;
        v17->m_nextV0 = nullptr;
        v17->m_nextV1 = nullptr;
        v17->m_refCount = 2;
        edgeInfo12 = v17;
      }
      else
      {
        edgeInfo12 = nullptr;
        v17 = nullptr;
      }
      v17->m_nextV0 = edgeInfos->_Myfirst[v8];
      v17->m_nextV1 = edgeInfos->_Myfirst[v9];
      edgeInfos->_Myfirst[v8] = v17;
      v20 = faceInfo;
      edgeInfos->_Myfirst[v9] = v17;
      v17->m_face0 = v20;
      goto LABEL_34;
    }
    while ( 1 )
    {
      v15 = v14->m_v0;
      if ( v15 != v8 )
        break;
      if ( v14->m_v1 == v9 )
        goto LABEL_32;
      v14 = v14->m_nextV0;
LABEL_29:
      if ( v14 == nullptr )
        goto LABEL_30;
    }
    if ( v15 != v9 )
    {
      v14 = v14->m_nextV1;
      goto LABEL_29;
    }
LABEL_32:
    edgeInfo12 = v14;
    if ( v14->m_face1 == nullptr )
    {
      v14->m_face1 = faceInfo;
      bFaceUpdated[1] = true;
    }
LABEL_34:
    v18 = edgeInfos->_Myfirst[v9];
    if ( v18 == nullptr )
    {
LABEL_43:
      v21 = (NvEdgeInfo *)MemAlloc_Alloc(nSize: 0x1Cu);
      if ( v21 != nullptr )
      {
        v21->m_v0 = v9;
        v21->m_v1 = v7;
        v21->m_face0 = nullptr;
        v21->m_face1 = nullptr;
        v21->m_nextV0 = nullptr;
        v21->m_nextV1 = nullptr;
        v21->m_refCount = 2;
      }
      else
      {
        v21 = nullptr;
      }
      v21->m_nextV0 = edgeInfos->_Myfirst[v9];
      v21->m_nextV1 = edgeInfos->_Myfirst[v7];
      edgeInfos->_Myfirst[v9] = v21;
      v22 = faceInfo;
      edgeInfos->_Myfirst[v7] = v21;
      v21->m_face0 = v22;
LABEL_47:
      Mylast = faceInfos->_Mylast;
      if ( &faceInfo < Mylast )
      {
        Myfirst = faceInfos->_Myfirst;
        if ( faceInfos->_Myfirst <= &faceInfo )
        {
          Myend = faceInfos->_Myend;
          v26 = &faceInfo - Myfirst;
          if ( Mylast != Myend )
          {
LABEL_87:
            v40 = faceInfos->_Mylast;
            if ( v40 != nullptr )
              *v40 = faceInfos->_Myfirst[v26];
            ++faceInfos->_Mylast;
            goto LABEL_102;
          }
          v27 = Mylast - Myfirst;
          if ( v27 <= 0x3FFFFFFE )
          {
            v28 = v27 + 1;
            v29 = Myend - Myfirst;
            if ( v28 > v29 )
            {
              if ( 0x3FFFFFFF - (v29 >> 1) >= v29 )
                v30 = (v29 >> 1) + v29;
              else
                v30 = 0;
              if ( v30 < v28 )
                v30 = v28;
              std::vector<int>::reserve(this: (std::vector<int> *)faceInfos, _Count: v30);
            }
            goto LABEL_87;
          }
LABEL_104:
          std::_Xlength_error(_Message: "vector<T> too long");
        }
      }
      v41 = faceInfos;
      v42 = faceInfos->_Myend;
      if ( Mylast == v42 )
      {
        v43 = Mylast - faceInfos->_Myfirst;
        if ( v43 > 0x3FFFFFFE )
          goto LABEL_104;
        v44 = v43 + 1;
        v45 = v42 - faceInfos->_Myfirst;
        if ( v44 > v45 )
        {
          if ( 0x3FFFFFFF - (v45 >> 1) >= v45 )
            v46 = (v45 >> 1) + v45;
          else
            v46 = 0;
          if ( v46 < v44 )
            v46 = v44;
          std::vector<int>::reserve(this: (std::vector<int> *)faceInfos, _Count: v46);
          v41 = faceInfos;
        }
      }
      v47 = v41->_Mylast;
      if ( v47 != nullptr )
        *v47 = faceInfo;
      ++v41->_Mylast;
      goto LABEL_102;
    }
    while ( 2 )
    {
      v19 = v18->m_v0;
      if ( v19 == v9 )
      {
        if ( v18->m_v1 == v7 )
          goto LABEL_54;
        v18 = v18->m_nextV0;
LABEL_42:
        if ( v18 == nullptr )
          goto LABEL_43;
        continue;
      }
      break;
    }
    if ( v19 != v7 )
    {
      v18 = v18->m_nextV1;
      goto LABEL_42;
    }
LABEL_54:
    if ( v18->m_face1 == nullptr )
    {
      v18->m_face1 = faceInfo;
      bFaceUpdated[2] = true;
    }
    if ( maxIndex_3 == 0 )
      goto LABEL_47;
    v31 = faceInfos->_Mylast;
    v32 = faceInfos->_Myfirst;
    v33 = 0;
    if ( v31 - faceInfos->_Myfirst == 0 )
    {
LABEL_65:
      if ( &faceInfo >= v31 || v32 > &faceInfo )
      {
        v38 = faceInfos;
        if ( v31 == faceInfos->_Myend )
        {
          std::vector<NvFaceInfo *>::_Reserve(this: (std::vector<int> *)faceInfos, _Count: 1u);
          v38 = faceInfos;
        }
        v39 = v38->_Mylast;
        if ( v39 != nullptr )
          *v39 = faceInfo;
        ++v38->_Mylast;
      }
      else
      {
        v36 = faceInfos;
        if ( v31 == faceInfos->_Myend )
        {
          std::vector<NvFaceInfo *>::_Reserve(this: (std::vector<int> *)faceInfos, _Count: 1u);
          v36 = faceInfos;
        }
        v37 = v36->_Mylast;
        if ( v37 != nullptr )
          *v37 = v36->_Myfirst[&faceInfo - v32];
        ++v36->_Mylast;
      }
      goto LABEL_102;
    }
    v34 = faceInfos->_Myfirst;
    while ( 2 )
    {
      v35 = *v34;
      if ( (*v34)->m_v0 != faceInfo->m_v0 )
      {
LABEL_63:
        ++v33;
        ++v34;
        if ( v33 >= faceInfos->_Mylast - faceInfos->_Myfirst )
        {
          v31 = faceInfos->_Mylast;
          goto LABEL_65;
        }
        continue;
      }
      break;
    }
    if ( v35->m_v1 != faceInfo->m_v1 || v35->m_v2 != faceInfo->m_v2 )
    {
      v32 = faceInfos->_Myfirst;
      goto LABEL_63;
    }
    free(pMem: faceInfo);
    if ( bFaceUpdated[0] )
      edgeInfo01->m_face1 = nullptr;
    if ( bFaceUpdated[1] )
      edgeInfo12->m_face1 = nullptr;
    if ( bFaceUpdated[2] )
      v18->m_face1 = nullptr;
LABEL_102:
    ++i;
  }
  while ( i < v48 );
}

//------------------------------------------------------------------------------
// Address: 0x005B8030
// Name: public: void NvStripInfo::Build(class std::vector<class NvEdgeInfo __near *,class std::allocator<class NvEdgeInfo __near *>> __near &,class std::vector<class NvFaceInfo __near *,class std::allocator<class NvFaceInfo __near *>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NvStripInfo::Build(
        NvStripInfo *this,
        std::vector<NvEdgeInfo *> *edgeInfos,
        std::vector<NvFaceInfo *> *faceInfos)
{
  int m_experimentId; // ecx
  NvFaceInfo *m_startFace; // eax
  bool m_toV1; // cl
  NvEdgeInfo *m_startEdge; // eax
  int m_v0; // edx
  int m_v1; // esi
  int NextIndex; // edi
  NvFaceInfo *v11; // eax
  int v12; // ebx
  int m_stripId; // ecx
  int v14; // eax
  int v15; // eax
  NvEdgeInfo **Myfirst; // edx
  int v17; // esi
  NvEdgeInfo *v18; // eax
  int v19; // ecx
  NvFaceInfo *v20; // eax
  int v21; // ecx
  NvEdgeInfo *v22; // eax
  int v23; // ecx
  NvFaceInfo *m_face1; // eax
  int v25; // ecx
  NvFaceInfo *v26; // eax
  NvFaceInfo *v27; // edi
  NvFaceInfo **v28; // eax
  int v29; // esi
  NvStripInfo *v30; // ecx
  int v31; // eax
  unsigned __int16 *v32; // eax
  unsigned __int16 *v33; // edx
  int v34; // esi
  NvFaceInfo **Mylast; // edx
  NvFaceInfo **v36; // edx
  NvFaceInfo **v37; // edi
  int v38; // esi
  unsigned int v39; // eax
  unsigned int v40; // eax
  unsigned int v41; // ecx
  unsigned int v42; // ecx
  unsigned int v43; // eax
  unsigned int v44; // eax
  unsigned int v45; // ecx
  unsigned int v46; // ecx
  NvStripInfo *v47; // ecx
  int v48; // eax
  NvFaceInfo *v49; // edx
  NvFaceInfo *v50; // eax
  unsigned __int16 v51; // si
  unsigned __int16 *v52; // edi
  unsigned __int16 *v53; // edx
  int v54; // esi
  unsigned int v55; // eax
  unsigned int v56; // eax
  unsigned int v57; // ecx
  unsigned int v58; // ecx
  unsigned int v59; // eax
  unsigned int v60; // eax
  unsigned int v61; // ecx
  unsigned int v62; // ecx
  NvFaceInfo *v63; // eax
  int v64; // ecx
  NvFaceInfo **v65; // edi
  NvFaceInfo **Myend; // eax
  unsigned int v67; // ebx
  NvFaceInfo **v68; // ecx
  NvFaceInfo **v69; // edx
  int v70; // esi
  unsigned int v71; // eax
  unsigned int v72; // eax
  unsigned int v73; // ecx
  unsigned int v74; // ecx
  unsigned int v75; // eax
  unsigned int v76; // eax
  unsigned int v77; // ecx
  unsigned int v78; // ecx
  unsigned __int16 v79; // si
  unsigned __int16 *v80; // edi
  unsigned __int16 *v81; // edx
  int v82; // esi
  unsigned int v83; // eax
  unsigned int v84; // eax
  unsigned int v85; // ecx
  unsigned int v86; // ecx
  unsigned int v87; // eax
  unsigned int v88; // eax
  unsigned int v89; // ecx
  unsigned int v90; // ecx
  int v91; // ebx
  unsigned __int16 *v92; // edx
  int v93; // esi
  unsigned int v94; // eax
  unsigned int v95; // eax
  unsigned int v96; // ecx
  unsigned int v97; // ecx
  unsigned int v98; // eax
  unsigned int v99; // eax
  unsigned int v100; // ecx
  unsigned int v101; // ecx
  int v102; // edi
  unsigned __int16 *v103; // edx
  unsigned __int16 *v104; // ecx
  int v105; // esi
  unsigned int v106; // eax
  unsigned int v107; // eax
  unsigned int v108; // ecx
  unsigned int v109; // ecx
  unsigned int v110; // eax
  unsigned int v111; // eax
  unsigned int v112; // ecx
  unsigned int v113; // ecx
  NvFaceInfo *v114; // eax
  int v115; // ecx
  NvFaceInfo *v116; // esi
  int v117; // eax
  int v118; // edi
  NvFaceInfo *v119; // ebx
  NvEdgeInfo **v120; // edx
  NvEdgeInfo *v121; // eax
  NvFaceInfo *v122; // ecx
  NvFaceInfo *m_face0; // eax
  int v124; // ecx
  NvEdgeInfo *v125; // eax
  NvFaceInfo *v126; // ecx
  NvFaceInfo *v127; // eax
  int v128; // ecx
  NvFaceInfo **v129; // eax
  NvFaceInfo *v130; // ecx
  int v131; // edx
  NvFaceInfo *v132; // edi
  NvFaceInfo **v133; // edx
  NvFaceInfo **v134; // edx
  NvFaceInfo **v135; // ebx
  int v136; // esi
  unsigned int v137; // eax
  unsigned int v138; // eax
  unsigned int v139; // ecx
  unsigned int v140; // ecx
  unsigned int v141; // eax
  unsigned int v142; // eax
  unsigned int v143; // ecx
  unsigned int v144; // ecx
  NvStripInfo *v145; // edx
  int v146; // eax
  unsigned __int16 *v147; // edi
  unsigned __int16 *v148; // ebx
  int v149; // esi
  unsigned int v150; // eax
  unsigned int v151; // eax
  unsigned int v152; // ecx
  unsigned int v153; // ecx
  unsigned int v154; // eax
  unsigned int v155; // eax
  unsigned int v156; // ecx
  unsigned int v157; // ecx
  NvFaceInfo *v158; // ecx
  unsigned __int16 *v159; // edi
  NvFaceInfo **v160; // eax
  NvFaceInfo **v161; // edx
  int v162; // esi
  unsigned int v163; // eax
  unsigned int v164; // eax
  unsigned int v165; // ecx
  unsigned int v166; // ecx
  unsigned int v167; // eax
  unsigned int v168; // eax
  unsigned int v169; // ecx
  unsigned int v170; // ecx
  NvFaceInfo **v171; // edx
  int v172; // esi
  unsigned int v173; // eax
  unsigned int v174; // eax
  unsigned int v175; // ecx
  unsigned int v176; // ecx
  unsigned int v177; // eax
  unsigned int v178; // eax
  unsigned int v179; // ecx
  unsigned int v180; // ecx
  NvFaceInfo *v181; // ecx
  NvStripInfo *v182; // edx
  int v183; // eax
  int v184; // edx
  int v185; // esi
  unsigned int v186; // eax
  unsigned int v187; // eax
  unsigned int v188; // ecx
  unsigned int v189; // ecx
  unsigned int v190; // eax
  unsigned int v191; // eax
  unsigned int v192; // ecx
  unsigned int v193; // ecx
  NvFaceInfo *v194; // eax
  int v195; // ecx
  std::vector<NvFaceInfo *> forwardFaces; // [esp+Ch] [ebp-60h] BYREF
  std::vector<NvFaceInfo *> backwardFaces; // [esp+1Ch] [ebp-50h] BYREF
  std::vector<NvFaceInfo *> tempAllFaces; // [esp+2Ch] [ebp-40h] BYREF
  std::vector<unsigned short> scratchIndices; // [esp+3Ch] [ebp-30h] BYREF
  int v2; // [esp+4Ch] [ebp-20h]
  int testnv0; // [esp+50h] [ebp-1Ch]
  int i; // [esp+54h] [ebp-18h] BYREF
  int v1; // [esp+58h] [ebp-14h] BYREF
  int testnv1; // [esp+5Ch] [ebp-10h] BYREF
  NvFaceInfo *tempFace; // [esp+60h] [ebp-Ch] BYREF
  NvStripInfo *v206; // [esp+64h] [ebp-8h]
  NvFaceInfo *nextFace; // [esp+68h] [ebp-4h] BYREF

  v206 = this;
  memset(&scratchIndices, 0, 12);
  memset(&forwardFaces, 0, 12);
  memset(&backwardFaces, 0, 12);
  std::vector<int>::push_back(this: (std::vector<int> *)&forwardFaces, _Val: (int *)this);
  m_experimentId = this->m_experimentId;
  m_startFace = this->m_startInfo.m_startFace;
  if ( m_experimentId < 0 )
  {
    m_startFace->m_experimentId = -1;
    m_startFace->m_stripId = this->m_stripId;
  }
  else
  {
    m_startFace->m_experimentId = m_experimentId;
    m_startFace->m_testStripId = this->m_stripId;
  }
  m_toV1 = this->m_startInfo.m_toV1;
  m_startEdge = this->m_startInfo.m_startEdge;
  if ( m_toV1 )
    m_v0 = m_startEdge->m_v0;
  else
    m_v0 = m_startEdge->m_v1;
  testnv0 = m_v0;
  if ( m_toV1 )
    m_v1 = m_startEdge->m_v1;
  else
    m_v1 = m_startEdge->m_v0;
  v1 = m_v1;
  i = (unsigned __int16)m_v0;
  std::vector<unsigned short>::push_back(this: &scratchIndices, _Val: (unsigned __int16 *)&i);
  i = (unsigned __int16)m_v1;
  std::vector<unsigned short>::push_back(this: &scratchIndices, _Val: (unsigned __int16 *)&i);
  NextIndex = NvStripifier::GetNextIndex(indices: &scratchIndices, face: v206->m_startInfo.m_startFace);
  i = (unsigned __int16)NextIndex;
  v2 = NextIndex;
  std::vector<unsigned short>::push_back(this: &scratchIndices, _Val: (unsigned __int16 *)&i);
  v11 = (NvFaceInfo *)edgeInfos->_Myfirst[m_v1];
  v12 = m_v1;
  while ( v11 != nullptr )
  {
    m_stripId = v11->m_stripId;
    if ( m_stripId == m_v1 )
    {
      if ( v11->m_testStripId == NextIndex )
        goto LABEL_18;
      v11 = (NvFaceInfo *)v11->m_experimentId;
    }
    else
    {
      if ( m_stripId == NextIndex )
        goto LABEL_18;
      v11 = (NvFaceInfo *)v11[1].m_v0;
    }
  }
  v11 = nullptr;
  if ( m_v1 != NextIndex )
  {
LABEL_18:
    if ( (NvFaceInfo *)v11->m_v1 == v206->m_startInfo.m_startFace )
      v11 = (NvFaceInfo *)v11->m_v2;
    else
      v11 = (NvFaceInfo *)v11->m_v1;
  }
  nextFace = v11;
  if ( v11 != nullptr )
  {
    while ( 1 )
    {
      if ( nextFace->m_stripId >= 0 )
        goto LABEL_148;
      v14 = v206->m_experimentId;
      if ( v14 >= 0 && nextFace->m_experimentId == v14 )
        goto LABEL_148;
      i = NextIndex;
      v15 = NvStripifier::GetNextIndex(indices: &scratchIndices, face: nextFace);
      Myfirst = edgeInfos->_Myfirst;
      v17 = v15;
      v18 = edgeInfos->_Myfirst[NextIndex];
      testnv1 = v17;
      while ( v18 != nullptr )
      {
        v19 = v18->m_v0;
        if ( v19 == NextIndex )
        {
          if ( v18->m_v1 == v17 )
            goto LABEL_33;
          v18 = v18->m_nextV0;
        }
        else
        {
          if ( v19 == v17 )
            goto LABEL_33;
          v18 = v18->m_nextV1;
        }
      }
      v18 = nullptr;
      if ( NextIndex == v17 )
        goto LABEL_41;
LABEL_33:
      v20 = v18->m_face0 == nextFace ? v18->m_face1 : v18->m_face0;
      if ( v20 == nullptr )
        break;
      if ( v20->m_stripId >= 0 )
        break;
      v21 = v206->m_experimentId;
      if ( v21 >= 0 && v20->m_experimentId == v21 )
        break;
LABEL_83:
      Mylast = forwardFaces._Mylast;
      if ( &nextFace >= forwardFaces._Mylast || forwardFaces._Myfirst > &nextFace )
      {
        if ( forwardFaces._Mylast == forwardFaces._Myend )
        {
          v43 = forwardFaces._Mylast - forwardFaces._Myfirst;
          if ( v43 > 0x3FFFFFFE )
            goto LABEL_181;
          v44 = v43 + 1;
          v45 = forwardFaces._Myend - forwardFaces._Myfirst;
          if ( v44 > v45 )
          {
            if ( 0x3FFFFFFF - (v45 >> 1) >= v45 )
              v46 = (v45 >> 1) + v45;
            else
              v46 = 0;
            if ( v46 < v44 )
              v46 = v44;
            std::vector<int>::reserve(this: (std::vector<int> *)&forwardFaces, _Count: v46);
            Mylast = forwardFaces._Mylast;
          }
        }
        if ( Mylast != nullptr )
          *Mylast = nextFace;
        forwardFaces._Mylast = Mylast + 1;
      }
      else
      {
        v36 = forwardFaces._Myfirst;
        v37 = forwardFaces._Mylast;
        v38 = &nextFace - forwardFaces._Myfirst;
        if ( forwardFaces._Mylast == forwardFaces._Myend )
        {
          v39 = forwardFaces._Mylast - forwardFaces._Myfirst;
          if ( v39 > 0x3FFFFFFE )
            goto LABEL_181;
          v40 = v39 + 1;
          v41 = forwardFaces._Myend - forwardFaces._Myfirst;
          if ( v40 > v41 )
          {
            if ( 0x3FFFFFFF - (v41 >> 1) >= v41 )
              v42 = (v41 >> 1) + v41;
            else
              v42 = 0;
            if ( v42 < v40 )
              v42 = v40;
            std::vector<int>::reserve(this: (std::vector<int> *)&forwardFaces, _Count: v42);
            v37 = forwardFaces._Mylast;
            v36 = forwardFaces._Myfirst;
          }
        }
        if ( v37 != nullptr )
          *v37 = v36[v38];
        forwardFaces._Mylast = v37 + 1;
      }
      v47 = v206;
      v48 = v206->m_experimentId;
      if ( v48 < 0 )
      {
        v50 = nextFace;
        nextFace->m_experimentId = -1;
        v50->m_stripId = v47->m_stripId;
      }
      else
      {
        v49 = nextFace;
        nextFace->m_experimentId = v48;
        v49->m_testStripId = v47->m_stripId;
      }
      v51 = testnv1;
      v52 = scratchIndices._Mylast;
      v53 = scratchIndices._Myfirst;
      tempFace = (NvFaceInfo *)(unsigned __int16)testnv1;
      if ( (unsigned __int16 *)&tempFace >= scratchIndices._Mylast
        || scratchIndices._Myfirst > (unsigned __int16 *)&tempFace )
      {
        if ( scratchIndices._Mylast == scratchIndices._Myend )
        {
          v59 = scratchIndices._Mylast - scratchIndices._Myfirst;
          if ( v59 > 0x7FFFFFFE )
            goto LABEL_181;
          v60 = v59 + 1;
          v61 = scratchIndices._Myend - scratchIndices._Myfirst;
          if ( v60 > v61 )
          {
            if ( 0x7FFFFFFF - (v61 >> 1) >= v61 )
              v62 = (v61 >> 1) + v61;
            else
              v62 = 0;
            if ( v62 < v60 )
              v62 = v60;
            std::vector<unsigned short>::reserve(this: &scratchIndices, _Count: v62);
            v52 = scratchIndices._Mylast;
          }
        }
        if ( v52 != nullptr )
          *v52 = v51;
      }
      else
      {
        v54 = ((char *)&tempFace - (char *)scratchIndices._Myfirst) >> 1;
        if ( scratchIndices._Mylast == scratchIndices._Myend )
        {
          v55 = scratchIndices._Mylast - scratchIndices._Myfirst;
          if ( v55 > 0x7FFFFFFE )
            goto LABEL_181;
          v56 = v55 + 1;
          v57 = scratchIndices._Myend - scratchIndices._Myfirst;
          if ( v56 > v57 )
          {
            if ( 0x7FFFFFFF - (v57 >> 1) >= v57 )
              v58 = (v57 >> 1) + v57;
            else
              v58 = 0;
            if ( v58 < v56 )
              v58 = v56;
            std::vector<unsigned short>::reserve(this: &scratchIndices, _Count: v58);
            v52 = scratchIndices._Mylast;
            v53 = scratchIndices._Myfirst;
          }
        }
        if ( v52 != nullptr )
          *v52 = v53[v54];
      }
      v12 = i;
      v63 = (NvFaceInfo *)edgeInfos->_Myfirst[i];
      scratchIndices._Mylast = v52 + 1;
      NextIndex = testnv1;
      while ( v63 != nullptr )
      {
        v64 = v63->m_stripId;
        if ( v64 == i )
        {
          if ( v63->m_testStripId == testnv1 )
            goto LABEL_144;
          v63 = (NvFaceInfo *)v63->m_experimentId;
        }
        else
        {
          if ( v64 == testnv1 )
            goto LABEL_144;
          v63 = (NvFaceInfo *)v63[1].m_v0;
        }
      }
      v63 = nullptr;
      if ( i != testnv1 )
      {
LABEL_144:
        if ( (NvFaceInfo *)v63->m_v1 == nextFace )
          v63 = (NvFaceInfo *)v63->m_v2;
        else
          v63 = (NvFaceInfo *)v63->m_v1;
      }
      nextFace = v63;
      if ( v63 == nullptr )
        goto LABEL_148;
    }
    v17 = testnv1;
LABEL_41:
    v22 = Myfirst[v12];
    while ( v22 != nullptr )
    {
      v23 = v22->m_v0;
      if ( v23 == v12 )
      {
        if ( v22->m_v1 == v17 )
          goto LABEL_49;
        v22 = v22->m_nextV0;
      }
      else
      {
        if ( v23 == v17 )
          goto LABEL_49;
        v22 = v22->m_nextV1;
      }
    }
    v22 = nullptr;
    if ( v12 != v17 )
    {
LABEL_49:
      if ( v22->m_face0 == nextFace )
        m_face1 = v22->m_face1;
      else
        m_face1 = v22->m_face0;
      if ( m_face1 != nullptr && m_face1->m_stripId < 0 )
      {
        v25 = v206->m_experimentId;
        if ( v25 < 0 || m_face1->m_experimentId != v25 )
        {
          v26 = (NvFaceInfo *)MemAlloc_Alloc(nSize: 0x18u);
          if ( v26 != nullptr )
          {
            v26->m_v1 = NextIndex;
            v26->m_v0 = v12;
            v26->m_v2 = v12;
            v26->m_stripId = -1;
            v26->m_testStripId = -1;
            v26->m_experimentId = -1;
            v27 = v26;
          }
          else
          {
            v27 = nullptr;
          }
          v28 = forwardFaces._Mylast;
          tempFace = v27;
          if ( &tempFace >= forwardFaces._Mylast || forwardFaces._Myfirst > &tempFace )
          {
            if ( forwardFaces._Mylast == forwardFaces._Myend )
            {
              std::vector<NvFaceInfo *>::_Reserve(this: (std::vector<int> *)&forwardFaces, _Count: 1u);
              v28 = forwardFaces._Mylast;
            }
            if ( v28 != nullptr )
              *v28 = v27;
          }
          else
          {
            v29 = &tempFace - forwardFaces._Myfirst;
            if ( forwardFaces._Mylast == forwardFaces._Myend )
            {
              std::vector<NvFaceInfo *>::_Reserve(this: (std::vector<int> *)&forwardFaces, _Count: 1u);
              v28 = forwardFaces._Mylast;
            }
            if ( v28 != nullptr )
              *v28 = forwardFaces._Myfirst[v29];
          }
          v30 = v206;
          forwardFaces._Mylast = v28 + 1;
          v31 = v206->m_experimentId;
          if ( v31 < 0 )
          {
            v27->m_experimentId = -1;
            v27->m_stripId = v30->m_stripId;
          }
          else
          {
            v27->m_experimentId = v31;
            v27->m_testStripId = v30->m_stripId;
          }
          tempFace = (NvFaceInfo *)(unsigned __int16)v12;
          v32 = scratchIndices._Mylast;
          if ( (unsigned __int16 *)&tempFace >= scratchIndices._Mylast
            || (v33 = scratchIndices._Myfirst, scratchIndices._Myfirst > (unsigned __int16 *)&tempFace) )
          {
            if ( scratchIndices._Mylast == scratchIndices._Myend )
            {
              std::vector<unsigned short>::_Reserve(this: &scratchIndices, _Count: 1u);
              v30 = v206;
              v32 = scratchIndices._Mylast;
            }
            if ( v32 != nullptr )
              *v32 = v12;
          }
          else
          {
            v34 = ((char *)&tempFace - (char *)scratchIndices._Myfirst) >> 1;
            if ( scratchIndices._Mylast == scratchIndices._Myend )
            {
              std::vector<unsigned short>::_Reserve(this: &scratchIndices, _Count: 1u);
              v30 = v206;
              v32 = scratchIndices._Mylast;
              v33 = scratchIndices._Myfirst;
            }
            if ( v32 != nullptr )
              *v32 = v33[v34];
          }
          ++v30->m_numDegenerates;
          scratchIndices._Mylast = v32 + 1;
          i = v12;
        }
      }
    }
    goto LABEL_83;
  }
LABEL_148:
  v65 = forwardFaces._Myfirst;
  Myend = nullptr;
  v67 = forwardFaces._Mylast - forwardFaces._Myfirst;
  v68 = nullptr;
  v69 = nullptr;
  memset(&tempAllFaces, 0, 12);
  i = 0;
  testnv1 = v67;
  if ( v67 != 0 )
  {
    while ( 1 )
    {
      if ( v65 >= v69 || v68 > v65 )
      {
        if ( v69 == Myend )
        {
          v75 = v69 - v68;
          if ( v75 > 0x3FFFFFFE )
            goto LABEL_181;
          v76 = v75 + 1;
          v77 = tempAllFaces._Myend - tempAllFaces._Myfirst;
          if ( v76 > v77 )
          {
            if ( 0x3FFFFFFF - (v77 >> 1) >= v77 )
              v78 = (v77 >> 1) + v77;
            else
              v78 = 0;
            if ( v78 < v76 )
              v78 = v76;
            std::vector<int>::reserve(this: (std::vector<int> *)&tempAllFaces, _Count: v78);
            v69 = tempAllFaces._Mylast;
          }
        }
        if ( v69 != nullptr )
          *v69 = *v65;
      }
      else
      {
        v70 = v65 - v68;
        if ( v69 == Myend )
        {
          v71 = v69 - tempAllFaces._Myfirst;
          if ( v71 > 0x3FFFFFFE )
            goto LABEL_181;
          v72 = v71 + 1;
          v73 = tempAllFaces._Myend - tempAllFaces._Myfirst;
          if ( v72 > v73 )
          {
            if ( 0x3FFFFFFF - (v73 >> 1) >= v73 )
              v74 = (v73 >> 1) + v73;
            else
              v74 = 0;
            if ( v74 < v72 )
              v74 = v72;
            std::vector<int>::reserve(this: (std::vector<int> *)&tempAllFaces, _Count: v74);
            v67 = testnv1;
          }
          v69 = tempAllFaces._Mylast;
        }
        if ( v69 != nullptr )
          *v69 = tempAllFaces._Myfirst[v70];
      }
      ++v69;
      ++v65;
      tempAllFaces._Mylast = v69;
      if ( ++i >= v67 )
        break;
      v68 = tempAllFaces._Myfirst;
      Myend = tempAllFaces._Myend;
    }
  }
  std::vector<unsigned short>::resize(this: &scratchIndices, _Newsize: 0);
  v79 = v2;
  v80 = scratchIndices._Myfirst;
  testnv1 = (unsigned __int16)v2;
  v81 = scratchIndices._Mylast;
  if ( (unsigned __int16 *)&testnv1 >= scratchIndices._Mylast || scratchIndices._Myfirst > (unsigned __int16 *)&testnv1 )
  {
    if ( scratchIndices._Mylast == scratchIndices._Myend )
    {
      v87 = scratchIndices._Mylast - scratchIndices._Myfirst;
      if ( v87 > 0x7FFFFFFE )
        std::_Xlength_error(_Message: "vector<T> too long");
      v88 = v87 + 1;
      v89 = scratchIndices._Myend - scratchIndices._Myfirst;
      if ( v88 > v89 )
      {
        if ( 0x7FFFFFFF - (v89 >> 1) >= v89 )
          v90 = (v89 >> 1) + v89;
        else
          v90 = 0;
        if ( v90 < v88 )
          v90 = v88;
        std::vector<unsigned short>::reserve(this: &scratchIndices, _Count: v90);
        v81 = scratchIndices._Mylast;
        v80 = scratchIndices._Myfirst;
      }
    }
    if ( v81 != nullptr )
      *v81 = v79;
  }
  else
  {
    v82 = ((char *)&testnv1 - (char *)scratchIndices._Myfirst) >> 1;
    if ( scratchIndices._Mylast == scratchIndices._Myend )
    {
      v83 = scratchIndices._Mylast - scratchIndices._Myfirst;
      if ( v83 > 0x7FFFFFFE )
LABEL_181:
        std::_Xlength_error(_Message: "vector<T> too long");
      v84 = v83 + 1;
      v85 = scratchIndices._Myend - scratchIndices._Myfirst;
      if ( v84 > v85 )
      {
        if ( 0x7FFFFFFF - (v85 >> 1) >= v85 )
          v86 = (v85 >> 1) + v85;
        else
          v86 = 0;
        if ( v86 < v84 )
          v86 = v84;
        std::vector<unsigned short>::reserve(this: &scratchIndices, _Count: v86);
        v81 = scratchIndices._Mylast;
        v80 = scratchIndices._Myfirst;
      }
    }
    if ( v81 != nullptr )
      *v81 = v80[v82];
  }
  v91 = v1;
  v92 = v81 + 1;
  scratchIndices._Mylast = v92;
  testnv1 = (unsigned __int16)v1;
  if ( &testnv1 >= (int *)v92 || v80 > (unsigned __int16 *)&testnv1 )
  {
    if ( v92 == scratchIndices._Myend )
    {
      v98 = v92 - v80;
      if ( v98 > 0x7FFFFFFE )
        std::_Xlength_error(_Message: "vector<T> too long");
      v99 = v98 + 1;
      v100 = scratchIndices._Myend - v80;
      if ( v99 > v100 )
      {
        if ( 0x7FFFFFFF - (v100 >> 1) >= v100 )
          v101 = (v100 >> 1) + v100;
        else
          v101 = 0;
        if ( v101 < v99 )
          v101 = v99;
        std::vector<unsigned short>::reserve(this: &scratchIndices, _Count: v101);
        v92 = scratchIndices._Mylast;
      }
    }
    if ( v92 != nullptr )
      *v92 = v91;
  }
  else
  {
    v93 = ((char *)&testnv1 - (char *)v80) >> 1;
    if ( v92 == scratchIndices._Myend )
    {
      v94 = v92 - v80;
      if ( v94 > 0x7FFFFFFE )
        std::_Xlength_error(_Message: "vector<T> too long");
      v95 = v94 + 1;
      v96 = scratchIndices._Myend - v80;
      if ( v95 > v96 )
      {
        if ( 0x7FFFFFFF - (v96 >> 1) >= v96 )
          v97 = (v96 >> 1) + v96;
        else
          v97 = 0;
        if ( v97 < v95 )
          v97 = v95;
        std::vector<unsigned short>::reserve(this: &scratchIndices, _Count: v97);
        v92 = scratchIndices._Mylast;
        v80 = scratchIndices._Myfirst;
      }
    }
    if ( v92 != nullptr )
      *v92 = v80[v93];
  }
  v102 = testnv0;
  v103 = v92 + 1;
  testnv1 = (unsigned __int16)testnv0;
  v104 = scratchIndices._Myfirst;
  scratchIndices._Mylast = v103;
  if ( &testnv1 >= (int *)v103 || scratchIndices._Myfirst > (unsigned __int16 *)&testnv1 )
  {
    if ( v103 == scratchIndices._Myend )
    {
      v110 = v103 - scratchIndices._Myfirst;
      if ( v110 > 0x7FFFFFFE )
        std::_Xlength_error(_Message: "vector<T> too long");
      v111 = v110 + 1;
      v112 = scratchIndices._Myend - scratchIndices._Myfirst;
      if ( v111 > v112 )
      {
        if ( 0x7FFFFFFF - (v112 >> 1) >= v112 )
          v113 = (v112 >> 1) + v112;
        else
          v113 = 0;
        if ( v113 < v111 )
          v113 = v111;
        std::vector<unsigned short>::reserve(this: &scratchIndices, _Count: v113);
        v103 = scratchIndices._Mylast;
      }
    }
    if ( v103 != nullptr )
      *v103 = v102;
  }
  else
  {
    v105 = ((char *)&testnv1 - (char *)scratchIndices._Myfirst) >> 1;
    if ( v103 == scratchIndices._Myend )
    {
      v106 = v103 - scratchIndices._Myfirst;
      if ( v106 > 0x7FFFFFFE )
        std::_Xlength_error(_Message: "vector<T> too long");
      v107 = v106 + 1;
      v108 = scratchIndices._Myend - scratchIndices._Myfirst;
      if ( v107 > v108 )
      {
        if ( 0x7FFFFFFF - (v108 >> 1) >= v108 )
          v109 = (v108 >> 1) + v108;
        else
          v109 = 0;
        if ( v109 < v107 )
          v109 = v107;
        std::vector<unsigned short>::reserve(this: &scratchIndices, _Count: v109);
        v91 = v1;
      }
      v104 = scratchIndices._Myfirst;
      v103 = scratchIndices._Mylast;
    }
    if ( v103 != nullptr )
      *v103 = v104[v105];
  }
  scratchIndices._Mylast = v103 + 1;
  v114 = (NvFaceInfo *)edgeInfos->_Myfirst[v91];
  tempFace = (NvFaceInfo *)v91;
  v1 = v102;
  while ( v114 != nullptr )
  {
    v115 = v114->m_stripId;
    if ( v115 == v91 )
    {
      if ( v114->m_testStripId == v102 )
        goto LABEL_264;
      v114 = (NvFaceInfo *)v114->m_experimentId;
    }
    else
    {
      if ( v115 == v102 )
        goto LABEL_264;
      v114 = (NvFaceInfo *)v114[1].m_v0;
    }
  }
  v114 = nullptr;
  if ( v91 != v102 )
  {
LABEL_264:
    if ( (NvFaceInfo *)v114->m_v1 == v206->m_startInfo.m_startFace )
      v114 = (NvFaceInfo *)v114->m_v2;
    else
      v114 = (NvFaceInfo *)v114->m_v1;
  }
  v116 = v114;
  nextFace = v114;
  if ( v114 != nullptr )
  {
    while ( v116->m_stripId < 0 )
    {
      v117 = v206->m_experimentId;
      if ( v117 >= 0 && v116->m_experimentId == v117 )
        break;
      if ( NvStripInfo::Unique(this: v206, faceVec: &tempAllFaces, face: v116) == 0 )
        break;
      v118 = v1;
      testnv0 = v1;
      v119 = (NvFaceInfo *)NvStripifier::GetNextIndex(indices: &scratchIndices, face: v116);
      v120 = edgeInfos->_Myfirst;
      v121 = edgeInfos->_Myfirst[v118];
      i = (int)v119;
      while ( v121 != nullptr )
      {
        v122 = (NvFaceInfo *)v121->m_v0;
        if ( v122 == (NvFaceInfo *)v118 )
        {
          if ( (NvFaceInfo *)v121->m_v1 == v119 )
            goto LABEL_280;
          v121 = v121->m_nextV0;
        }
        else
        {
          if ( v122 == v119 )
            goto LABEL_280;
          v121 = v121->m_nextV1;
        }
      }
      v121 = nullptr;
      if ( (NvFaceInfo *)v118 != v119 )
      {
LABEL_280:
        if ( v121->m_face0 == v116 )
          m_face0 = v121->m_face1;
        else
          m_face0 = v121->m_face0;
        if ( m_face0 != nullptr && m_face0->m_stripId < 0 )
        {
          v124 = v206->m_experimentId;
          if ( v124 < 0 || m_face0->m_experimentId != v124 )
            goto LABEL_359;
        }
      }
      v125 = v120[(_DWORD)tempFace];
      while ( v125 != nullptr )
      {
        v126 = (NvFaceInfo *)v125->m_v0;
        if ( v126 == tempFace )
        {
          if ( (NvFaceInfo *)v125->m_v1 == v119 )
            goto LABEL_295;
          v125 = v125->m_nextV0;
        }
        else
        {
          if ( v126 == v119 )
            goto LABEL_295;
          v125 = v125->m_nextV1;
        }
      }
      v125 = nullptr;
      if ( tempFace == v119 )
      {
LABEL_359:
        v148 = scratchIndices._Myfirst;
        v159 = scratchIndices._Mylast;
        goto LABEL_360;
      }
LABEL_295:
      if ( v125->m_face0 == v116 )
        v127 = v125->m_face1;
      else
        v127 = v125->m_face0;
      if ( v127 == nullptr )
        goto LABEL_359;
      if ( v127->m_stripId >= 0 )
        goto LABEL_359;
      v128 = v206->m_experimentId;
      if ( v128 >= 0 && v127->m_experimentId == v128 )
        goto LABEL_359;
      v129 = (NvFaceInfo **)MemAlloc_Alloc(nSize: 0x18u);
      if ( v129 != nullptr )
      {
        v130 = tempFace;
        v131 = v1;
        *v129 = tempFace;
        v129[2] = v130;
        v129[1] = (NvFaceInfo *)v131;
        v129[3] = (NvFaceInfo *)-1;
        v129[4] = (NvFaceInfo *)-1;
        v129[5] = (NvFaceInfo *)-1;
        v132 = (NvFaceInfo *)v129;
      }
      else
      {
        v132 = nullptr;
      }
      v133 = backwardFaces._Mylast;
      testnv1 = (int)v132;
      if ( (NvFaceInfo **)&testnv1 >= backwardFaces._Mylast || backwardFaces._Myfirst > (NvFaceInfo **)&testnv1 )
      {
        if ( backwardFaces._Mylast == backwardFaces._Myend )
        {
          v141 = backwardFaces._Mylast - backwardFaces._Myfirst;
          if ( v141 > 0x3FFFFFFE )
            goto LABEL_181;
          v142 = v141 + 1;
          v143 = backwardFaces._Myend - backwardFaces._Myfirst;
          if ( v142 > v143 )
          {
            if ( 0x3FFFFFFF - (v143 >> 1) >= v143 )
              v144 = (v143 >> 1) + v143;
            else
              v144 = 0;
            if ( v144 < v142 )
              v144 = v142;
            std::vector<int>::reserve(this: (std::vector<int> *)&backwardFaces, _Count: v144);
            v133 = backwardFaces._Mylast;
          }
        }
        if ( v133 != nullptr )
          *v133 = v132;
        backwardFaces._Mylast = v133 + 1;
      }
      else
      {
        v134 = backwardFaces._Myfirst;
        v135 = backwardFaces._Mylast;
        v136 = ((char *)&testnv1 - (char *)backwardFaces._Myfirst) >> 2;
        if ( backwardFaces._Mylast == backwardFaces._Myend )
        {
          v137 = backwardFaces._Mylast - backwardFaces._Myfirst;
          if ( v137 > 0x3FFFFFFE )
            goto LABEL_181;
          v138 = v137 + 1;
          v139 = backwardFaces._Myend - backwardFaces._Myfirst;
          if ( v138 > v139 )
          {
            if ( 0x3FFFFFFF - (v139 >> 1) >= v139 )
              v140 = (v139 >> 1) + v139;
            else
              v140 = 0;
            if ( v140 < v138 )
              v140 = v138;
            std::vector<int>::reserve(this: (std::vector<int> *)&backwardFaces, _Count: v140);
            v134 = backwardFaces._Myfirst;
            v135 = backwardFaces._Mylast;
          }
        }
        if ( v135 != nullptr )
          *v135 = v134[v136];
        backwardFaces._Mylast = v135 + 1;
      }
      v145 = v206;
      v146 = v206->m_experimentId;
      if ( v146 < 0 )
      {
        v132->m_experimentId = -1;
        v132->m_stripId = v145->m_stripId;
      }
      else
      {
        v132->m_experimentId = v146;
        v132->m_testStripId = v145->m_stripId;
      }
      v147 = scratchIndices._Mylast;
      v148 = scratchIndices._Myfirst;
      v1 = (unsigned __int16)tempFace;
      if ( (unsigned __int16 *)&v1 >= scratchIndices._Mylast || scratchIndices._Myfirst > (unsigned __int16 *)&v1 )
      {
        if ( scratchIndices._Mylast == scratchIndices._Myend )
        {
          v154 = scratchIndices._Mylast - scratchIndices._Myfirst;
          if ( v154 > 0x7FFFFFFE )
            goto LABEL_181;
          v155 = v154 + 1;
          v156 = scratchIndices._Myend - scratchIndices._Myfirst;
          if ( v155 > v156 )
          {
            if ( 0x7FFFFFFF - (v156 >> 1) >= v156 )
              v157 = (v156 >> 1) + v156;
            else
              v157 = 0;
            if ( v157 < v155 )
              v157 = v155;
            std::vector<unsigned short>::reserve(this: &scratchIndices, _Count: v157);
            v147 = scratchIndices._Mylast;
            v148 = scratchIndices._Myfirst;
            v145 = v206;
          }
        }
        if ( v147 != nullptr )
          *v147 = (unsigned __int16)tempFace;
      }
      else
      {
        v149 = ((char *)&v1 - (char *)scratchIndices._Myfirst) >> 1;
        if ( scratchIndices._Mylast == scratchIndices._Myend )
        {
          v150 = scratchIndices._Mylast - scratchIndices._Myfirst;
          if ( v150 > 0x7FFFFFFE )
            goto LABEL_181;
          v151 = v150 + 1;
          v152 = scratchIndices._Myend - scratchIndices._Myfirst;
          if ( v151 > v152 )
          {
            if ( 0x7FFFFFFF - (v152 >> 1) >= v152 )
              v153 = (v152 >> 1) + v152;
            else
              v153 = 0;
            if ( v153 < v151 )
              v153 = v151;
            std::vector<unsigned short>::reserve(this: &scratchIndices, _Count: v153);
            v147 = scratchIndices._Mylast;
            v148 = scratchIndices._Myfirst;
            v145 = v206;
          }
        }
        if ( v147 != nullptr )
          *v147 = v148[v149];
      }
      v158 = tempFace;
      v116 = nextFace;
      v159 = v147 + 1;
      ++v145->m_numDegenerates;
      scratchIndices._Mylast = v159;
      testnv0 = (int)v158;
LABEL_360:
      v160 = backwardFaces._Mylast;
      v161 = backwardFaces._Myfirst;
      if ( &nextFace >= backwardFaces._Mylast || backwardFaces._Myfirst > &nextFace )
      {
        if ( backwardFaces._Mylast == backwardFaces._Myend )
        {
          v167 = backwardFaces._Mylast - backwardFaces._Myfirst;
          if ( v167 > 0x3FFFFFFE )
            goto LABEL_181;
          v168 = v167 + 1;
          v169 = backwardFaces._Myend - backwardFaces._Myfirst;
          if ( v168 > v169 )
          {
            if ( 0x3FFFFFFF - (v169 >> 1) >= v169 )
              v170 = (v169 >> 1) + v169;
            else
              v170 = 0;
            if ( v170 < v168 )
              v170 = v168;
            std::vector<int>::reserve(this: (std::vector<int> *)&backwardFaces, _Count: v170);
            v116 = nextFace;
          }
          v160 = backwardFaces._Mylast;
        }
        if ( v160 != nullptr )
          *v160 = v116;
      }
      else
      {
        v162 = &nextFace - backwardFaces._Myfirst;
        if ( backwardFaces._Mylast == backwardFaces._Myend )
        {
          v163 = backwardFaces._Mylast - backwardFaces._Myfirst;
          if ( v163 > 0x3FFFFFFE )
            goto LABEL_181;
          v164 = v163 + 1;
          v165 = backwardFaces._Myend - backwardFaces._Myfirst;
          if ( v164 > v165 )
          {
            if ( 0x3FFFFFFF - (v165 >> 1) >= v165 )
              v166 = (v165 >> 1) + v165;
            else
              v166 = 0;
            if ( v166 < v164 )
              v166 = v164;
            std::vector<int>::reserve(this: (std::vector<int> *)&backwardFaces, _Count: v166);
            v148 = scratchIndices._Myfirst;
            v161 = backwardFaces._Myfirst;
          }
          v160 = backwardFaces._Mylast;
        }
        if ( v160 != nullptr )
          *v160 = v161[v162];
      }
      v171 = tempAllFaces._Mylast;
      backwardFaces._Mylast = v160 + 1;
      if ( &nextFace >= tempAllFaces._Mylast || tempAllFaces._Myfirst > &nextFace )
      {
        if ( tempAllFaces._Mylast == tempAllFaces._Myend )
        {
          v177 = tempAllFaces._Mylast - tempAllFaces._Myfirst;
          if ( v177 > 0x3FFFFFFE )
            goto LABEL_181;
          v178 = v177 + 1;
          v179 = tempAllFaces._Myend - tempAllFaces._Myfirst;
          if ( v178 > v179 )
          {
            if ( 0x3FFFFFFF - (v179 >> 1) >= v179 )
              v180 = (v179 >> 1) + v179;
            else
              v180 = 0;
            if ( v180 < v178 )
              v180 = v178;
            std::vector<int>::reserve(this: (std::vector<int> *)&tempAllFaces, _Count: v180);
            v171 = tempAllFaces._Mylast;
          }
        }
        if ( v171 != nullptr )
          *v171 = nextFace;
      }
      else
      {
        v172 = &nextFace - tempAllFaces._Myfirst;
        if ( tempAllFaces._Mylast == tempAllFaces._Myend )
        {
          v173 = tempAllFaces._Mylast - tempAllFaces._Myfirst;
          if ( v173 > 0x3FFFFFFE )
            goto LABEL_181;
          v174 = v173 + 1;
          v175 = tempAllFaces._Myend - tempAllFaces._Myfirst;
          if ( v174 > v175 )
          {
            if ( 0x3FFFFFFF - (v175 >> 1) >= v175 )
              v176 = (v175 >> 1) + v175;
            else
              v176 = 0;
            if ( v176 < v174 )
              v176 = v174;
            std::vector<int>::reserve(this: (std::vector<int> *)&tempAllFaces, _Count: v176);
            v148 = scratchIndices._Myfirst;
          }
          v171 = tempAllFaces._Mylast;
        }
        if ( v171 != nullptr )
          *v171 = tempAllFaces._Myfirst[v172];
      }
      v181 = nextFace;
      tempAllFaces._Mylast = v171 + 1;
      v182 = v206;
      v183 = v206->m_experimentId;
      if ( v183 < 0 )
      {
        nextFace->m_experimentId = -1;
        v181->m_stripId = v182->m_stripId;
      }
      else
      {
        nextFace->m_experimentId = v183;
        v181->m_testStripId = v182->m_stripId;
      }
      v184 = i;
      v1 = (unsigned __int16)i;
      if ( &v1 >= (int *)v159 || v148 > (unsigned __int16 *)&v1 )
      {
        if ( v159 == scratchIndices._Myend )
        {
          v190 = v159 - v148;
          if ( v190 > 0x7FFFFFFE )
            goto LABEL_181;
          v191 = v190 + 1;
          v192 = scratchIndices._Myend - v148;
          if ( v191 > v192 )
          {
            if ( 0x7FFFFFFF - (v192 >> 1) >= v192 )
              v193 = (v192 >> 1) + v192;
            else
              v193 = 0;
            if ( v193 < v191 )
              v193 = v191;
            std::vector<unsigned short>::reserve(this: &scratchIndices, _Count: v193);
            v159 = scratchIndices._Mylast;
            v184 = i;
          }
        }
        if ( v159 != nullptr )
          *v159 = v184;
      }
      else
      {
        v185 = ((char *)&v1 - (char *)v148) >> 1;
        if ( v159 == scratchIndices._Myend )
        {
          v186 = v159 - v148;
          if ( v186 > 0x7FFFFFFE )
            goto LABEL_181;
          v187 = v186 + 1;
          v188 = scratchIndices._Myend - v148;
          if ( v187 > v188 )
          {
            if ( 0x7FFFFFFF - (v188 >> 1) >= v188 )
              v189 = (v188 >> 1) + v188;
            else
              v189 = 0;
            if ( v189 < v187 )
              v189 = v187;
            std::vector<unsigned short>::reserve(this: &scratchIndices, _Count: v189);
            v159 = scratchIndices._Mylast;
            v148 = scratchIndices._Myfirst;
            v184 = i;
          }
        }
        if ( v159 != nullptr )
          *v159 = v148[v185];
      }
      v194 = (NvFaceInfo *)edgeInfos->_Myfirst[testnv0];
      scratchIndices._Mylast = v159 + 1;
      tempFace = (NvFaceInfo *)testnv0;
      v1 = v184;
      while ( v194 != nullptr )
      {
        v195 = v194->m_stripId;
        if ( v195 == testnv0 )
        {
          if ( v194->m_testStripId == v184 )
            goto LABEL_446;
          v194 = (NvFaceInfo *)v194->m_experimentId;
        }
        else
        {
          if ( v195 == v184 )
            goto LABEL_446;
          v194 = (NvFaceInfo *)v194[1].m_v0;
        }
      }
      v194 = nullptr;
      if ( testnv0 != v184 )
      {
LABEL_446:
        if ( (NvFaceInfo *)v194->m_v1 == nextFace )
          v194 = (NvFaceInfo *)v194->m_v2;
        else
          v194 = (NvFaceInfo *)v194->m_v1;
      }
      nextFace = v194;
      if ( v194 == nullptr )
        break;
      v116 = v194;
    }
  }
  NvStripInfo::Combine(this: v206, forward: &forwardFaces, backward: &backwardFaces);
  if ( tempAllFaces._Myfirst != nullptr )
    free(pMem: tempAllFaces._Myfirst);
  if ( backwardFaces._Myfirst != nullptr )
    free(pMem: backwardFaces._Myfirst);
  if ( forwardFaces._Myfirst != nullptr )
    free(pMem: forwardFaces._Myfirst);
  if ( scratchIndices._Myfirst != nullptr )
    free(pMem: scratchIndices._Myfirst);
}

//------------------------------------------------------------------------------
// Address: 0x005B8FD0
// Name: protected: void NvStripifier::CommitStrips(class std::vector<class NvStripInfo __near *,class std::allocator<class NvStripInfo __near *>> __near &,class std::vector<class NvStripInfo __near *,class std::allocator<class NvStripInfo __near *>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NvStripifier::CommitStrips(
        NvStripifier *this,
        NvStripInfo *allStrips,
        const std::vector<NvStripInfo *> *strips)
{
  std::vector<int> *v3; // ebx
  std::vector<NvStripInfo *> *v4; // esi
  int *Mylast; // eax
  int *Myfirst; // edx
  int *v7; // ecx
  int v8; // esi
  unsigned int v9; // eax
  unsigned int v10; // eax
  unsigned int v11; // ecx
  unsigned int v12; // ecx
  int *v13; // eax
  int *Myend; // ecx
  unsigned int v15; // eax
  unsigned int v16; // eax
  unsigned int v17; // ecx
  unsigned int v18; // ecx
  _DWORD *v19; // eax
  NvStripInfo *v20; // eax
  int v21; // edi
  int v22; // edx
  NvStripInfo **m_experimentId; // esi
  NvFaceInfo *v24; // ecx
  std::vector<NvStripInfo *> *v25; // esi
  int numStrips; // [esp+0h] [ebp-8h]
  int i; // [esp+4h] [ebp-4h]

  i = 0;
  numStrips = strips->_Mylast - strips->_Myfirst;
  if ( numStrips > 0 )
  {
    v3 = (std::vector<int> *)allStrips;
    do
    {
      v4 = (std::vector<NvStripInfo *> *)strips->_Myfirst[i];
      v4[2]._Myfirst = (NvStripInfo **)-1;
      Mylast = v3->_Mylast;
      allStrips = (NvStripInfo *)v4;
      if ( &allStrips >= (NvStripInfo **)Mylast || (Myfirst = v3->_Myfirst, v3->_Myfirst > (int *)&allStrips) )
      {
        Myend = v3->_Myend;
        if ( Mylast == Myend )
        {
          v15 = Mylast - v3->_Myfirst;
          if ( v15 > 0x3FFFFFFE )
LABEL_34:
            std::_Xlength_error(_Message: "vector<T> too long");
          v16 = v15 + 1;
          v17 = Myend - v3->_Myfirst;
          if ( v16 > v17 )
          {
            if ( 0x3FFFFFFF - (v17 >> 1) >= v17 )
              v18 = (v17 >> 1) + v17;
            else
              v18 = 0;
            if ( v18 < v16 )
              v18 = v16;
            std::vector<int>::reserve(this: v3, _Count: v18);
          }
        }
        v19 = v3->_Mylast;
        if ( v19 != nullptr )
          *v19 = v4;
      }
      else
      {
        v7 = v3->_Myend;
        v8 = ((char *)&allStrips - (char *)Myfirst) >> 2;
        if ( Mylast == v7 )
        {
          v9 = Mylast - Myfirst;
          if ( v9 > 0x3FFFFFFE )
            goto LABEL_34;
          v10 = v9 + 1;
          v11 = v7 - Myfirst;
          if ( v10 > v11 )
          {
            if ( 0x3FFFFFFF - (v11 >> 1) >= v11 )
              v12 = (v11 >> 1) + v11;
            else
              v12 = 0;
            if ( v12 < v10 )
              v12 = v10;
            std::vector<int>::reserve(this: v3, _Count: v12);
          }
        }
        v13 = v3->_Mylast;
        if ( v13 != nullptr )
          *v13 = v3->_Myfirst[v8];
      }
      ++v3->_Mylast;
      v20 = strips->_Myfirst[i];
      v21 = 0;
      v22 = v20->m_faces._Mylast - v20->m_faces._Myfirst;
      if ( v22 > 0 )
      {
        do
        {
          m_experimentId = (NvStripInfo **)allStrips->m_experimentId;
          v24 = v20->m_faces._Myfirst[v21];
          if ( (int)m_experimentId < 0 )
          {
            v25 = (std::vector<NvStripInfo *> *)allStrips;
            v24->m_experimentId = -1;
            v24->m_stripId = *(_DWORD *)&v25[1]._Alval.std::_Allocator_base<NvStripInfo *>;
          }
          else
          {
            v24->m_experimentId = (int)m_experimentId;
            v24->m_testStripId = allStrips->m_stripId;
          }
          ++v21;
        }
        while ( v21 < v22 );
      }
      ++i;
    }
    while ( i < numStrips );
  }
}

//------------------------------------------------------------------------------
// Address: 0x005B9150
// Name: protected: void NvStripifier::RemoveSmallStrips(class std::vector<class NvStripInfo __near *,class std::allocator<class NvStripInfo __near *>> __near &,class std::vector<class NvStripInfo __near *,class std::allocator<class NvStripInfo __near *>> __near &,class std::vector<class NvFaceInfo __near *,class std::allocator<class NvFaceInfo __near *>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NvStripifier::RemoveSmallStrips(
        NvStripifier *this,
        std::vector<NvStripInfo *> *allStrips,
        std::vector<int> *allBigStrips,
        std::vector<NvFaceInfo *> *faceList)
{
  unsigned __int8 *Myfirst; // esi
  unsigned __int8 *Mylast; // ecx
  unsigned __int8 *v6; // ecx
  unsigned __int8 *v7; // esi
  NvStripInfo **v8; // eax
  NvFaceInfo **v9; // edi
  NvFaceInfo **v10; // ebx
  int v11; // ecx
  NvStripInfo **v12; // esi
  std::vector<NvFaceInfo *> *p_m_faces; // eax
  int v14; // ecx
  NvFaceInfo **Myend; // edx
  NvFaceInfo **v16; // esi
  int v17; // esi
  unsigned int v18; // eax
  unsigned int v19; // eax
  unsigned int v20; // ecx
  unsigned int v21; // ecx
  unsigned int v22; // eax
  unsigned int v23; // eax
  unsigned int v24; // ecx
  unsigned int v25; // ecx
  NvStripInfo *v26; // eax
  int v27; // esi
  NvStripInfo *v28; // esi
  std::vector<int> *v29; // edx
  NvStripInfo **v30; // eax
  signed int v31; // esi
  int *v32; // eax
  NvStripInfo *v33; // ecx
  unsigned int v34; // edx
  unsigned int v35; // edi
  VertexCache *v36; // esi
  int cacheSize; // eax
  int k; // eax
  unsigned int v39; // eax
  NvFaceInfo *v40; // edi
  int numEntries; // eax
  int v42; // ebx
  int v43; // ecx
  int *entries; // edx
  int v45; // ecx
  int *v46; // edx
  int v47; // ecx
  int *v48; // edx
  std::vector<NvFaceInfo *> *v49; // edi
  int v50; // eax
  NvFaceInfo **v51; // esi
  NvFaceInfo **v52; // eax
  NvFaceInfo **v53; // edx
  NvFaceInfo **v54; // ecx
  int v55; // esi
  unsigned int v56; // eax
  unsigned int v57; // eax
  unsigned int v58; // ecx
  unsigned int v59; // ecx
  NvFaceInfo **v60; // eax
  NvFaceInfo **v61; // ecx
  unsigned int v62; // eax
  unsigned int v63; // eax
  unsigned int v64; // ecx
  unsigned int v65; // ecx
  NvFaceInfo **v66; // eax
  std::vector<NvFaceInfo *> tempFaceList; // [esp+Ch] [ebp-24h] BYREF
  int bestIndex; // [esp+1Ch] [ebp-14h]
  unsigned int v69; // [esp+20h] [ebp-10h]
  NvStripifier *v70; // [esp+24h] [ebp-Ch]
  int j; // [esp+28h] [ebp-8h]
  int i; // [esp+2Ch] [ebp-4h]
  int allStripsa; // [esp+38h] [ebp+8h]
  VertexCache *vcache; // [esp+3Ch] [ebp+Ch]

  Myfirst = (unsigned __int8 *)faceList->_Myfirst;
  v70 = this;
  Mylast = (unsigned __int8 *)faceList->_Mylast;
  if ( Myfirst != Mylast )
  {
    memmove(dst: Myfirst, src: Mylast, count: 0);
    faceList->_Mylast = (NvFaceInfo **)Myfirst;
  }
  v6 = (unsigned __int8 *)allBigStrips->_Mylast;
  v7 = (unsigned __int8 *)allBigStrips->_Myfirst;
  if ( (unsigned __int8 *)allBigStrips->_Myfirst != v6 )
  {
    memmove(dst: v7, src: v6, count: 0);
    allBigStrips->_Mylast = (int *)v7;
  }
  v8 = allStrips->_Myfirst;
  v9 = nullptr;
  v10 = nullptr;
  v11 = allStrips->_Mylast - allStrips->_Myfirst;
  memset(&tempFaceList, 0, 12);
  i = 0;
  if ( v11 != 0 )
  {
    do
    {
      v12 = &v8[i];
      p_m_faces = &(*v12)->m_faces;
      if ( (unsigned int)((*v12)->m_faces._Mylast - p_m_faces->_Myfirst) < v70->minStripLength )
      {
        v14 = (char *)(*v12)->m_faces._Mylast - (char *)(*v12)->m_faces._Myfirst;
        j = 0;
        if ( v14 >> 2 != 0 )
        {
          Myend = tempFaceList._Myend;
          do
          {
            v16 = &p_m_faces->_Myfirst[j];
            if ( v16 >= v9 || v10 > v16 )
            {
              if ( v9 == Myend )
              {
                v22 = v9 - v10;
                if ( v22 > 0x3FFFFFFE )
LABEL_55:
                  std::_Xlength_error(_Message: "vector<T> too long");
                v23 = v22 + 1;
                v24 = Myend - v10;
                if ( v23 > v24 )
                {
                  if ( 0x3FFFFFFF - (v24 >> 1) >= v24 )
                    v25 = (v24 >> 1) + v24;
                  else
                    v25 = 0;
                  if ( v25 < v23 )
                    v25 = v23;
                  std::vector<int>::reserve(this: (std::vector<int> *)&tempFaceList, _Count: v25);
                  v9 = tempFaceList._Mylast;
                  v10 = tempFaceList._Myfirst;
                  Myend = tempFaceList._Myend;
                }
              }
              if ( v9 != nullptr )
                *v9 = *v16;
            }
            else
            {
              v17 = v16 - v10;
              if ( v9 == Myend )
              {
                v18 = v9 - v10;
                if ( v18 > 0x3FFFFFFE )
                  goto LABEL_55;
                v19 = v18 + 1;
                v20 = Myend - v10;
                if ( v19 > v20 )
                {
                  if ( 0x3FFFFFFF - (v20 >> 1) >= v20 )
                    v21 = (v20 >> 1) + v20;
                  else
                    v21 = 0;
                  if ( v21 < v19 )
                    v21 = v19;
                  std::vector<int>::reserve(this: (std::vector<int> *)&tempFaceList, _Count: v21);
                  v9 = tempFaceList._Mylast;
                  v10 = tempFaceList._Myfirst;
                  Myend = tempFaceList._Myend;
                }
              }
              if ( v9 != nullptr )
                *v9 = v10[v17];
            }
            v26 = allStrips->_Myfirst[i];
            v27 = (char *)v26->m_faces._Mylast - (char *)v26->m_faces._Myfirst;
            p_m_faces = &v26->m_faces;
            tempFaceList._Mylast = ++v9;
            ++j;
          }
          while ( j < (unsigned int)(v27 >> 2) );
        }
        v28 = allStrips->_Myfirst[i];
        if ( v28 != nullptr )
        {
          if ( v28->m_faces._Myfirst != nullptr )
            free(pMem: v28->m_faces._Myfirst);
          v28->m_faces._Myfirst = nullptr;
          v28->m_faces._Mylast = nullptr;
          v28->m_faces._Myend = nullptr;
          free(pMem: v28);
        }
        goto LABEL_50;
      }
      v29 = allBigStrips;
      v30 = (NvStripInfo **)allBigStrips->_Mylast;
      if ( v12 >= v30 || allBigStrips->_Myfirst > (int *)v12 )
      {
        if ( v30 == (NvStripInfo **)allBigStrips->_Myend )
        {
          std::vector<NvFaceInfo *>::_Reserve(this: allBigStrips, _Count: 1u);
          v29 = allBigStrips;
        }
        v32 = v29->_Mylast;
        if ( v32 == nullptr )
          goto LABEL_49;
        v33 = *v12;
      }
      else
      {
        v31 = ((char *)v12 - (char *)allBigStrips->_Myfirst) >> 2;
        if ( v30 == (NvStripInfo **)allBigStrips->_Myend )
        {
          std::vector<NvFaceInfo *>::_Reserve(this: allBigStrips, _Count: 1u);
          v29 = allBigStrips;
        }
        v32 = v29->_Mylast;
        if ( v32 == nullptr )
          goto LABEL_49;
        v33 = (NvStripInfo *)v29->_Myfirst[v31];
      }
      *v32 = (int)v33;
LABEL_49:
      ++v29->_Mylast;
LABEL_50:
      v8 = allStrips->_Myfirst;
      v34 = allStrips->_Mylast - allStrips->_Myfirst;
      ++i;
    }
    while ( i < v34 );
  }
  v35 = v9 - v10;
  v69 = v35;
  i = (int)MemAlloc_Alloc(nSize: v35);
  memset(dst: (unsigned __int8 *)i, value: 0, count: v35);
  v36 = (VertexCache *)MemAlloc_Alloc(nSize: 8u);
  if ( v36 != nullptr )
  {
    cacheSize = v70->cacheSize;
    v36->numEntries = cacheSize;
    v36->entries = (int *)MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)cacheSize >> 30 != 0 ? -1 : 4 * cacheSize);
    for ( k = 0; k < v36->numEntries; ++k )
      v36->entries[k] = -1;
    vcache = v36;
  }
  else
  {
    vcache = nullptr;
  }
  bestIndex = 0;
  while ( 1 )
  {
    v39 = 0;
    j = -1;
    allStripsa = 0;
    if ( v69 != 0 )
    {
      do
      {
        if ( *(_BYTE *)(v39 + i) == 0 )
        {
          v40 = tempFaceList._Myfirst[allStripsa];
          numEntries = vcache->numEntries;
          v42 = 0;
          v43 = 0;
          if ( numEntries > 0 )
          {
            entries = vcache->entries;
            while ( *entries != v40->m_v0 )
            {
              ++v43;
              ++entries;
              if ( v43 >= numEntries )
                goto LABEL_66;
            }
            v42 = 1;
          }
LABEL_66:
          v45 = 0;
          if ( numEntries > 0 )
          {
            v46 = vcache->entries;
            while ( *v46 != v40->m_v1 )
            {
              ++v45;
              ++v46;
              if ( v45 >= numEntries )
                goto LABEL_72;
            }
            ++v42;
          }
LABEL_72:
          v47 = 0;
          if ( numEntries > 0 )
          {
            v48 = vcache->entries;
            while ( *v48 != v40->m_v2 )
            {
              ++v47;
              ++v48;
              if ( v47 >= numEntries )
                goto LABEL_78;
            }
            ++v42;
          }
LABEL_78:
          if ( v42 > j )
          {
            j = v42;
            bestIndex = allStripsa;
          }
        }
        v39 = allStripsa + 1;
        allStripsa = v39;
      }
      while ( v39 < v69 );
      v10 = tempFaceList._Myfirst;
    }
    v49 = faceList;
    if ( (float)j == -1.0 )
      break;
    v50 = bestIndex;
    *(_BYTE *)(bestIndex + i) = 1;
    v51 = &v10[v50];
    NvStripifier::UpdateCacheFace(this: v70, vcache, face: *v51);
    v52 = faceList->_Mylast;
    if ( v51 >= v52 || (v53 = faceList->_Myfirst, faceList->_Myfirst > v51) )
    {
      v61 = faceList->_Myend;
      if ( v52 == v61 )
      {
        v62 = v52 - faceList->_Myfirst;
        if ( v62 > 0x3FFFFFFE )
          goto LABEL_55;
        v63 = v62 + 1;
        v64 = v61 - faceList->_Myfirst;
        if ( v63 > v64 )
        {
          if ( 0x3FFFFFFF - (v64 >> 1) >= v64 )
            v65 = (v64 >> 1) + v64;
          else
            v65 = 0;
          v49 = faceList;
          if ( v65 < v63 )
            v65 = v63;
          std::vector<int>::reserve(this: (std::vector<int> *)faceList, _Count: v65);
        }
      }
      v66 = v49->_Mylast;
      if ( v66 != nullptr )
        *v66 = *v51;
      ++v49->_Mylast;
    }
    else
    {
      v54 = faceList->_Myend;
      v55 = v51 - v53;
      if ( v52 == v54 )
      {
        v56 = v52 - v53;
        if ( v56 > 0x3FFFFFFE )
          goto LABEL_55;
        v57 = v56 + 1;
        v58 = v54 - v53;
        if ( v57 > v58 )
        {
          if ( 0x3FFFFFFF - (v58 >> 1) >= v58 )
            v59 = (v58 >> 1) + v58;
          else
            v59 = 0;
          v49 = faceList;
          if ( v59 < v57 )
            v59 = v57;
          std::vector<int>::reserve(this: (std::vector<int> *)faceList, _Count: v59);
        }
      }
      v60 = v49->_Mylast;
      if ( v60 != nullptr )
        *v60 = v49->_Myfirst[v55];
      ++v49->_Mylast;
    }
  }
  if ( vcache != nullptr )
  {
    free(pMem: vcache->entries);
    vcache->entries = nullptr;
    free(pMem: vcache);
  }
  free(pMem: (void *)i);
  if ( v10 != nullptr )
    free(pMem: v10);
}

//------------------------------------------------------------------------------
// Address: 0x005B9630
// Name: public: void NvStripifier::CreateStrips(class std::vector<class NvStripInfo __near *,class std::allocator<class NvStripInfo __near *>> const __near &,class std::vector<int,class std::allocator<int>> __near &,bool,unsigned int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NvStripifier::CreateStrips(
        NvStripifier *this,
        const std::vector<NvStripInfo *> *allStrips,
        int stripIndices,
        bool bStitchStrips,
        unsigned int *numSeparateStrips)
{
  std::vector<int> *v5; // esi
  NvStripInfo *v6; // eax
  int v7; // ecx
  int *v8; // eax
  int v9; // edx
  int v10; // ebx
  int *v11; // eax
  int v12; // ecx
  int m_v1; // edx
  int m_v2; // ecx
  int v15; // edi
  int v16; // edx
  int v17; // eax
  int v18; // ecx
  int *Mylast; // eax
  int v20; // edi
  int *v21; // eax
  int *v22; // eax
  _DWORD *v23; // ecx
  bool v24; // zf
  _DWORD *v25; // eax
  bool v26; // zf
  int *v27; // eax
  int v28; // edi
  int *v29; // eax
  int *v30; // eax
  int *v31; // eax
  int *Myfirst; // edx
  int *v33; // ecx
  int v34; // edi
  unsigned int v35; // eax
  unsigned int v36; // eax
  unsigned int v37; // ecx
  unsigned int v38; // ecx
  int *v39; // eax
  int *Myend; // ecx
  unsigned int v41; // eax
  unsigned int v42; // eax
  unsigned int v43; // ecx
  unsigned int v44; // ecx
  int *v45; // eax
  int *v46; // eax
  int *v47; // edx
  int *v48; // ecx
  int v49; // edi
  unsigned int v50; // eax
  unsigned int v51; // eax
  unsigned int v52; // ecx
  unsigned int v53; // ecx
  int *v54; // eax
  int *v55; // ecx
  unsigned int v56; // eax
  unsigned int v57; // eax
  unsigned int v58; // ecx
  unsigned int v59; // ecx
  int *v60; // eax
  int *v61; // eax
  int *v62; // edx
  int *v63; // ecx
  int v64; // edi
  unsigned int v65; // eax
  unsigned int v66; // eax
  unsigned int v67; // ecx
  unsigned int v68; // ecx
  int *v69; // eax
  int *v70; // ecx
  unsigned int v71; // eax
  unsigned int v72; // eax
  unsigned int v73; // ecx
  unsigned int v74; // ecx
  int *v75; // eax
  __int64 v76; // xmm0_8
  int *v77; // eax
  int v78; // edx
  int *v79; // edi
  int v80; // ecx
  int v81; // ebx
  int v82; // ecx
  int v83; // ecx
  int *v84; // edx
  int *v85; // ecx
  int v86; // edi
  unsigned int v87; // eax
  unsigned int v88; // eax
  unsigned int v89; // ecx
  unsigned int v90; // ecx
  int *v91; // eax
  int *v92; // ecx
  unsigned int v93; // eax
  unsigned int v94; // eax
  unsigned int v95; // ecx
  unsigned int v96; // ecx
  int *v97; // eax
  int v98; // ecx
  int *v99; // edi
  int *v100; // edx
  int *v101; // ecx
  int v102; // edi
  unsigned int v103; // eax
  unsigned int v104; // eax
  unsigned int v105; // ecx
  unsigned int v106; // ecx
  int *v107; // eax
  int *v108; // ecx
  unsigned int v109; // eax
  unsigned int v110; // eax
  unsigned int v111; // ecx
  unsigned int v112; // ecx
  int *v113; // eax
  int *v114; // ecx
  int *v115; // edx
  int *v116; // ecx
  int v117; // edi
  unsigned int v118; // eax
  unsigned int v119; // eax
  unsigned int v120; // ecx
  unsigned int v121; // ecx
  int *v122; // eax
  int *v123; // ecx
  unsigned int v124; // eax
  unsigned int v125; // eax
  unsigned int v126; // ecx
  unsigned int v127; // ecx
  int *v128; // eax
  int *v129; // edx
  int *v130; // ecx
  int v131; // edi
  unsigned int v132; // eax
  unsigned int v133; // eax
  unsigned int v134; // ecx
  unsigned int v135; // ecx
  int *v136; // eax
  int *v137; // ecx
  unsigned int v138; // eax
  unsigned int v139; // eax
  unsigned int v140; // ecx
  unsigned int v141; // ecx
  int *v142; // eax
  unsigned int *v143; // eax
  NvFaceInfo tLastFace; // [esp+0h] [ebp-54h] BYREF
  NvFaceInfo tFirstFace; // [esp+18h] [ebp-3Ch] BYREF
  int nShared1; // [esp+30h] [ebp-24h] BYREF
  int nShared0; // [esp+34h] [ebp-20h] BYREF
  int nStripCount; // [esp+38h] [ebp-1Ch]
  int accountForNegatives; // [esp+3Ch] [ebp-18h]
  int nStripFaceCount; // [esp+40h] [ebp-14h]
  int nUnique; // [esp+44h] [ebp-10h] BYREF
  int j; // [esp+48h] [ebp-Ch]
  int v153; // [esp+4Ch] [ebp-8h]
  int i; // [esp+50h] [ebp-4h]

  nStripCount = allStrips->_Mylast - allStrips->_Myfirst;
  accountForNegatives = 0;
  i = 0;
  if ( nStripCount > 0 )
  {
    v5 = (std::vector<int> *)stripIndices;
    do
    {
      v6 = allStrips->_Myfirst[i];
      v7 = (char *)v6->m_faces._Mylast - (char *)v6->m_faces._Myfirst;
      stripIndices = (int)v6;
      v8 = (int *)*v6->m_faces._Myfirst;
      tFirstFace.m_v0 = *v8;
      v9 = v8[1];
      tFirstFace.m_v2 = v8[2];
      nStripFaceCount = v7 >> 2;
      tFirstFace.m_v1 = v9;
      memset(&tFirstFace.m_stripId, 255, 12);
      if ( v7 >> 2 <= 1 )
        goto LABEL_31;
      v10 = *(_DWORD *)(stripIndices + 12);
      v11 = *(int **)(v10 + 4);
      v12 = *v11;
      if ( tFirstFace.m_v0 == *v11 || tFirstFace.m_v0 == v11[1] || tFirstFace.m_v0 == v11[2] )
      {
        m_v1 = tFirstFace.m_v1;
        if ( tFirstFace.m_v1 != v12 && tFirstFace.m_v1 != v11[1] && tFirstFace.m_v1 != v11[2] )
          goto LABEL_18;
        m_v1 = tFirstFace.m_v2;
        if ( tFirstFace.m_v2 == v12 || tFirstFace.m_v2 == v11[1] || tFirstFace.m_v2 == v11[2] )
          m_v2 = -1;
        else
          m_v2 = tFirstFace.m_v2;
      }
      else
      {
        m_v1 = tFirstFace.m_v2;
        m_v2 = tFirstFace.m_v0;
      }
      if ( m_v2 == tFirstFace.m_v1 )
      {
        m_v1 = tFirstFace.m_v1;
LABEL_18:
        tFirstFace.m_v1 = tFirstFace.m_v0;
        goto LABEL_21;
      }
      if ( m_v2 == m_v1 )
      {
        tFirstFace.m_v2 = tFirstFace.m_v0;
LABEL_21:
        tFirstFace.m_v0 = m_v1;
      }
      if ( nStripFaceCount > 2 )
      {
        v15 = v11[1];
        if ( *v11 == v15 || (v16 = v11[2], *v11 == v16) || v15 == v16 )
        {
          if ( tFirstFace.m_v1 == v15 )
          {
            v17 = tFirstFace.m_v1;
LABEL_30:
            v18 = tFirstFace.m_v2;
            tFirstFace.m_v2 = v17;
            tFirstFace.m_v1 = v18;
          }
        }
        else
        {
          NvStripifier::GetSharedVertices(
            faceA: *(NvFaceInfo **)(v10 + 8),
            faceB: &tFirstFace,
            vertex0: &nShared0,
            vertex1: &nShared1);
          v17 = tFirstFace.m_v1;
          if ( nShared0 == tFirstFace.m_v1 && nShared1 == -1 )
            goto LABEL_30;
        }
      }
LABEL_31:
      if ( i != 0 && bStitchStrips )
      {
        Mylast = v5->_Mylast;
        if ( &tFirstFace >= (NvFaceInfo *)Mylast || v5->_Myfirst > (int *)&tFirstFace )
        {
          if ( Mylast == v5->_Myend )
            std::vector<NvFaceInfo *>::_Reserve(this: v5, _Count: 1u);
          v22 = v5->_Mylast;
          if ( v22 != nullptr )
            *v22 = tFirstFace.m_v0;
        }
        else
        {
          v20 = ((char *)&tFirstFace - (char *)v5->_Myfirst) >> 2;
          if ( Mylast == v5->_Myend )
            std::vector<NvFaceInfo *>::_Reserve(this: v5, _Count: 1u);
          v21 = v5->_Mylast;
          if ( v21 != nullptr )
            *v21 = v5->_Myfirst[v20];
        }
        ++v5->_Mylast;
        v23 = **(_DWORD ***)(stripIndices + 12);
        if ( *v23 == tFirstFace.m_v0 )
        {
          v24 = v23[1] == tFirstFace.m_v1;
        }
        else if ( v23[1] == tFirstFace.m_v0 )
        {
          v24 = v23[2] == tFirstFace.m_v1;
        }
        else
        {
          v24 = *v23 == tFirstFace.m_v1;
        }
        if ( ((v5->_Mylast - v5->_Myfirst - accountForNegatives) % 2 == 0) != v24 )
          std::vector<int>::push_back(this: v5, _Val: &tFirstFace.m_v0);
      }
      else
      {
        v25 = **(_DWORD ***)(stripIndices + 12);
        if ( *v25 == tFirstFace.m_v0 )
        {
          v26 = v25[1] == tFirstFace.m_v1;
        }
        else if ( v25[1] == tFirstFace.m_v0 )
        {
          v26 = v25[2] == tFirstFace.m_v1;
        }
        else
        {
          v26 = *v25 == tFirstFace.m_v1;
        }
        if ( !v26 )
        {
          v27 = v5->_Mylast;
          if ( &tFirstFace >= (NvFaceInfo *)v27 || v5->_Myfirst > (int *)&tFirstFace )
          {
            if ( v27 == v5->_Myend )
              std::vector<NvFaceInfo *>::_Reserve(this: v5, _Count: 1u);
            v30 = v5->_Mylast;
            if ( v30 != nullptr )
              *v30 = tFirstFace.m_v0;
          }
          else
          {
            v28 = ((char *)&tFirstFace - (char *)v5->_Myfirst) >> 2;
            if ( v27 == v5->_Myend )
              std::vector<NvFaceInfo *>::_Reserve(this: v5, _Count: 1u);
            v29 = v5->_Mylast;
            if ( v29 != nullptr )
              *v29 = v5->_Myfirst[v28];
          }
          ++v5->_Mylast;
        }
      }
      v31 = v5->_Mylast;
      if ( &tFirstFace >= (NvFaceInfo *)v31 || (Myfirst = v5->_Myfirst, v5->_Myfirst > (int *)&tFirstFace) )
      {
        Myend = v5->_Myend;
        if ( v31 == Myend )
        {
          v41 = v31 - v5->_Myfirst;
          if ( v41 > 0x3FFFFFFE )
            goto LABEL_264;
          v42 = v41 + 1;
          v43 = Myend - v5->_Myfirst;
          if ( v42 > v43 )
          {
            if ( 0x3FFFFFFF - (v43 >> 1) >= v43 )
              v44 = (v43 >> 1) + v43;
            else
              v44 = 0;
            if ( v44 < v42 )
              v44 = v42;
            std::vector<int>::reserve(this: v5, _Count: v44);
          }
        }
        v45 = v5->_Mylast;
        if ( v45 != nullptr )
          *v45 = tFirstFace.m_v0;
      }
      else
      {
        v33 = v5->_Myend;
        v34 = ((char *)&tFirstFace - (char *)Myfirst) >> 2;
        if ( v31 == v33 )
        {
          v35 = v31 - Myfirst;
          if ( v35 > 0x3FFFFFFE )
            goto LABEL_264;
          v36 = v35 + 1;
          v37 = v33 - Myfirst;
          if ( v36 > v37 )
          {
            if ( 0x3FFFFFFF - (v37 >> 1) >= v37 )
              v38 = (v37 >> 1) + v37;
            else
              v38 = 0;
            if ( v38 < v36 )
              v38 = v36;
            std::vector<int>::reserve(this: v5, _Count: v38);
          }
        }
        v39 = v5->_Mylast;
        if ( v39 != nullptr )
          *v39 = v5->_Myfirst[v34];
      }
      v46 = ++v5->_Mylast;
      if ( &tFirstFace.m_v1 >= v46 || (v47 = v5->_Myfirst, v5->_Myfirst > &tFirstFace.m_v1) )
      {
        v55 = v5->_Myend;
        if ( v46 == v55 )
        {
          v56 = v46 - v5->_Myfirst;
          if ( v56 > 0x3FFFFFFE )
            goto LABEL_264;
          v57 = v56 + 1;
          v58 = v55 - v5->_Myfirst;
          if ( v57 > v58 )
          {
            if ( 0x3FFFFFFF - (v58 >> 1) >= v58 )
              v59 = (v58 >> 1) + v58;
            else
              v59 = 0;
            if ( v59 < v57 )
              v59 = v57;
            std::vector<int>::reserve(this: v5, _Count: v59);
          }
        }
        v60 = v5->_Mylast;
        if ( v60 != nullptr )
          *v60 = tFirstFace.m_v1;
      }
      else
      {
        v48 = v5->_Myend;
        v49 = &tFirstFace.m_v1 - v47;
        if ( v46 == v48 )
        {
          v50 = v46 - v47;
          if ( v50 > 0x3FFFFFFE )
            goto LABEL_264;
          v51 = v50 + 1;
          v52 = v48 - v47;
          if ( v51 > v52 )
          {
            if ( 0x3FFFFFFF - (v52 >> 1) >= v52 )
              v53 = (v52 >> 1) + v52;
            else
              v53 = 0;
            if ( v53 < v51 )
              v53 = v51;
            std::vector<int>::reserve(this: v5, _Count: v53);
          }
        }
        v54 = v5->_Mylast;
        if ( v54 != nullptr )
          *v54 = v5->_Myfirst[v49];
      }
      v61 = ++v5->_Mylast;
      if ( &tFirstFace.m_v2 >= v61 || (v62 = v5->_Myfirst, v5->_Myfirst > &tFirstFace.m_v2) )
      {
        v70 = v5->_Myend;
        if ( v61 == v70 )
        {
          v71 = v61 - v5->_Myfirst;
          if ( v71 > 0x3FFFFFFE )
            goto LABEL_264;
          v72 = v71 + 1;
          v73 = v70 - v5->_Myfirst;
          if ( v72 > v73 )
          {
            if ( 0x3FFFFFFF - (v73 >> 1) >= v73 )
              v74 = (v73 >> 1) + v73;
            else
              v74 = 0;
            if ( v74 < v72 )
              v74 = v72;
            std::vector<int>::reserve(this: v5, _Count: v74);
          }
        }
        v75 = v5->_Mylast;
        if ( v75 != nullptr )
          *v75 = tFirstFace.m_v2;
      }
      else
      {
        v63 = v5->_Myend;
        v64 = &tFirstFace.m_v2 - v62;
        if ( v61 == v63 )
        {
          v65 = v61 - v62;
          if ( v65 > 0x3FFFFFFE )
            goto LABEL_264;
          v66 = v65 + 1;
          v67 = v63 - v62;
          if ( v66 > v67 )
          {
            if ( 0x3FFFFFFF - (v67 >> 1) >= v67 )
              v68 = (v67 >> 1) + v67;
            else
              v68 = 0;
            if ( v68 < v66 )
              v68 = v66;
            std::vector<int>::reserve(this: v5, _Count: v68);
          }
        }
        v69 = v5->_Mylast;
        if ( v69 != nullptr )
          *v69 = v5->_Myfirst[v64];
      }
      v76 = *(_QWORD *)&tFirstFace.m_v0;
      v77 = ++v5->_Mylast;
      tLastFace.m_v1 = HIDWORD(v76);
      *(_QWORD *)&tLastFace.m_v2 = *(_QWORD *)&tFirstFace.m_v2;
      *(_QWORD *)&tLastFace.m_testStripId = *(_QWORD *)&tFirstFace.m_testStripId;
      j = 1;
      if ( nStripFaceCount > 1 )
      {
        v78 = v76;
        while ( 1 )
        {
          v79 = *(int **)(*(_DWORD *)(stripIndices + 12) + 4 * j);
          v80 = *v79;
          if ( *v79 != v78 && v80 != tLastFace.m_v1 && v80 != tLastFace.m_v2 )
            break;
          v82 = v79[1];
          if ( v82 != v78 && v82 != tLastFace.m_v1 && v82 != tLastFace.m_v2 )
          {
            v81 = v79[1];
            goto LABEL_154;
          }
          v83 = v79[2];
          if ( v83 == v78 || v83 == tLastFace.m_v1 || v83 == tLastFace.m_v2 )
          {
            v81 = -1;
            goto LABEL_154;
          }
          v81 = v79[2];
          v153 = v81;
LABEL_155:
          nUnique = v81;
          if ( v81 == -1 )
          {
            v99 = v79 + 2;
            if ( v99 >= v77 || (v100 = v5->_Myfirst, v5->_Myfirst > v99) )
            {
              v108 = v5->_Myend;
              if ( v77 == v108 )
              {
                v109 = v77 - v5->_Myfirst;
                if ( v109 > 0x3FFFFFFE )
                  goto LABEL_264;
                v110 = v109 + 1;
                v111 = v108 - v5->_Myfirst;
                if ( v110 > v111 )
                {
                  if ( 0x3FFFFFFF - (v111 >> 1) >= v111 )
                    v112 = (v111 >> 1) + v111;
                  else
                    v112 = 0;
                  if ( v112 < v110 )
                    v112 = v110;
                  std::vector<int>::reserve(this: v5, _Count: v112);
                }
              }
              v113 = v5->_Mylast;
              if ( v113 != nullptr )
                *v113 = *v99;
            }
            else
            {
              v101 = v5->_Myend;
              v102 = v99 - v100;
              if ( v77 == v101 )
              {
                v103 = v77 - v100;
                if ( v103 > 0x3FFFFFFE )
                  goto LABEL_264;
                v104 = v103 + 1;
                v105 = v101 - v100;
                if ( v104 > v105 )
                {
                  if ( 0x3FFFFFFF - (v105 >> 1) >= v105 )
                    v106 = (v105 >> 1) + v105;
                  else
                    v106 = 0;
                  if ( v106 < v104 )
                    v106 = v104;
                  std::vector<int>::reserve(this: v5, _Count: v106);
                }
              }
              v107 = v5->_Mylast;
              if ( v107 != nullptr )
                *v107 = v5->_Myfirst[v102];
            }
            ++v5->_Mylast;
            v114 = *(int **)(*(_DWORD *)(stripIndices + 12) + 4 * j);
            v78 = *v114;
            tLastFace.m_v1 = v114[1];
            tLastFace.m_v2 = v114[2];
          }
          else
          {
            if ( &nUnique >= v77 || (v84 = v5->_Myfirst, v5->_Myfirst > &nUnique) )
            {
              v92 = v5->_Myend;
              if ( v77 == v92 )
              {
                v93 = v77 - v5->_Myfirst;
                if ( v93 > 0x3FFFFFFE )
                  goto LABEL_264;
                v94 = v93 + 1;
                v95 = v92 - v5->_Myfirst;
                if ( v94 > v95 )
                {
                  if ( 0x3FFFFFFF - (v95 >> 1) >= v95 )
                    v96 = (v95 >> 1) + v95;
                  else
                    v96 = 0;
                  if ( v96 < v94 )
                    v96 = v94;
                  std::vector<int>::reserve(this: v5, _Count: v96);
                }
              }
              v97 = v5->_Mylast;
              if ( v97 != nullptr )
                *v97 = v81;
            }
            else
            {
              v85 = v5->_Myend;
              v86 = &nUnique - v84;
              if ( v77 == v85 )
              {
                v87 = v77 - v84;
                if ( v87 > 0x3FFFFFFE )
                  goto LABEL_264;
                v88 = v87 + 1;
                v89 = v85 - v84;
                if ( v88 > v89 )
                {
                  if ( 0x3FFFFFFF - (v89 >> 1) >= v89 )
                    v90 = (v89 >> 1) + v89;
                  else
                    v90 = 0;
                  if ( v90 < v88 )
                    v90 = v88;
                  std::vector<int>::reserve(this: v5, _Count: v90);
                  v81 = v153;
                }
              }
              v91 = v5->_Mylast;
              if ( v91 != nullptr )
                *v91 = v5->_Myfirst[v86];
            }
            v98 = tLastFace.m_v2;
            v78 = tLastFace.m_v1;
            ++v5->_Mylast;
            tLastFace.m_v1 = v98;
            tLastFace.m_v2 = v81;
          }
          v77 = v5->_Mylast;
          if ( ++j >= nStripFaceCount )
            goto LABEL_207;
        }
        v81 = *v79;
LABEL_154:
        v153 = v81;
        goto LABEL_155;
      }
LABEL_207:
      if ( bStitchStrips )
      {
        if ( i != nStripCount - 1 )
        {
          if ( &tLastFace.m_v2 >= v77 || (v115 = v5->_Myfirst, v5->_Myfirst > &tLastFace.m_v2) )
          {
            v123 = v5->_Myend;
            if ( v77 == v123 )
            {
              v124 = v77 - v5->_Myfirst;
              if ( v124 > 0x3FFFFFFE )
                goto LABEL_264;
              v125 = v124 + 1;
              v126 = v123 - v5->_Myfirst;
              if ( v125 > v126 )
              {
                if ( 0x3FFFFFFF - (v126 >> 1) >= v126 )
                  v127 = (v126 >> 1) + v126;
                else
                  v127 = 0;
                if ( v127 < v125 )
                  v127 = v125;
                std::vector<int>::reserve(this: v5, _Count: v127);
              }
            }
            v128 = v5->_Mylast;
            if ( v128 != nullptr )
              *v128 = tLastFace.m_v2;
            ++v5->_Mylast;
          }
          else
          {
            v116 = v5->_Myend;
            v117 = &tLastFace.m_v2 - v115;
            if ( v77 == v116 )
            {
              v118 = v77 - v115;
              if ( v118 > 0x3FFFFFFE )
                goto LABEL_264;
              v119 = v118 + 1;
              v120 = v116 - v115;
              if ( v119 > v120 )
              {
                if ( 0x3FFFFFFF - (v120 >> 1) >= v120 )
                  v121 = (v120 >> 1) + v120;
                else
                  v121 = 0;
                if ( v121 < v119 )
                  v121 = v119;
                std::vector<int>::reserve(this: v5, _Count: v121);
              }
            }
            v122 = v5->_Mylast;
            if ( v122 != nullptr )
              *v122 = v5->_Myfirst[v117];
            ++v5->_Mylast;
          }
        }
      }
      else
      {
        stripIndices = -1;
        if ( &stripIndices >= v77 || (v129 = v5->_Myfirst, v5->_Myfirst > &stripIndices) )
        {
          v137 = v5->_Myend;
          if ( v77 == v137 )
          {
            v138 = v77 - v5->_Myfirst;
            if ( v138 > 0x3FFFFFFE )
LABEL_264:
              std::_Xlength_error(_Message: "vector<T> too long");
            v139 = v138 + 1;
            v140 = v137 - v5->_Myfirst;
            if ( v139 > v140 )
            {
              if ( 0x3FFFFFFF - (v140 >> 1) >= v140 )
                v141 = (v140 >> 1) + v140;
              else
                v141 = 0;
              if ( v141 < v139 )
                v141 = v139;
              std::vector<int>::reserve(this: v5, _Count: v141);
            }
          }
          v142 = v5->_Mylast;
          if ( v142 != nullptr )
            *v142 = -1;
        }
        else
        {
          v130 = v5->_Myend;
          v131 = &stripIndices - v129;
          if ( v77 == v130 )
          {
            v132 = v77 - v129;
            if ( v132 > 0x3FFFFFFE )
              goto LABEL_264;
            v133 = v132 + 1;
            v134 = v130 - v129;
            if ( v133 > v134 )
            {
              if ( 0x3FFFFFFF - (v134 >> 1) >= v134 )
                v135 = (v134 >> 1) + v134;
              else
                v135 = 0;
              if ( v135 < v133 )
                v135 = v133;
              std::vector<int>::reserve(this: v5, _Count: v135);
            }
          }
          v136 = v5->_Mylast;
          if ( v136 != nullptr )
            *v136 = v5->_Myfirst[v131];
        }
        v143 = numSeparateStrips;
        ++v5->_Mylast;
        ++accountForNegatives;
        ++*v143;
      }
      ++i;
    }
    while ( i < nStripCount );
  }
  if ( bStitchStrips )
    *numSeparateStrips = 1;
}

//------------------------------------------------------------------------------
// Address: 0x005B9F30
// Name: protected: void NvStripifier::SplitUpStripsAndOptimize(class std::vector<class NvStripInfo __near *,class std::allocator<class NvStripInfo __near *>> __near &,class std::vector<class NvStripInfo __near *,class std::allocator<class NvStripInfo __near *>> __near &,class std::vector<class NvEdgeInfo __near *,class std::allocator<class NvEdgeInfo __near *>> __near &,class std::vector<class NvFaceInfo __near *,class std::allocator<class NvFaceInfo __near *>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NvStripifier::SplitUpStripsAndOptimize(
        NvStripifier *this,
        std::vector<NvStripInfo *> *allStrips,
        std::vector<NvStripInfo *> *outStrips,
        std::vector<NvEdgeInfo *> *edgeInfos,
        std::vector<NvFaceInfo *> *outFaceList)
{
  NvStripifier *v5; // eax
  NvStripInfo **Myfirst; // ecx
  int v7; // edx
  NvStripInfo *v8; // edx
  unsigned int v9; // eax
  int v10; // ecx
  NvFaceInfo **v11; // ebx
  int m_v0; // esi
  int m_v1; // edi
  int m_v2; // ecx
  int v15; // esi
  int v16; // eax
  int v17; // edx
  int v18; // eax
  NvStripInfo *v19; // eax
  int v20; // edx
  int v21; // ebx
  float v22; // edi
  NvFaceInfo **v23; // edx
  NvFaceInfo *v24; // eax
  int v25; // ecx
  NvFaceInfo **v26; // esi
  int v27; // edx
  int v28; // eax
  NvStripInfo *v29; // edi
  NvFaceInfo **v30; // eax
  NvFaceInfo **v31; // edx
  NvFaceInfo **v32; // ecx
  int v33; // esi
  unsigned int v34; // eax
  unsigned int v35; // eax
  unsigned int v36; // ecx
  unsigned int v37; // ecx
  NvFaceInfo **v38; // eax
  NvFaceInfo **v39; // ecx
  NvFaceInfo **v40; // edx
  unsigned int v41; // eax
  unsigned int v42; // eax
  unsigned int v43; // ecx
  unsigned int v44; // ecx
  NvFaceInfo **v45; // eax
  NvFaceInfo **v46; // eax
  NvFaceInfo **v47; // edx
  NvFaceInfo **v48; // ecx
  int v49; // esi
  unsigned int v50; // eax
  unsigned int v51; // eax
  unsigned int v52; // ecx
  unsigned int v53; // ecx
  NvFaceInfo **v54; // eax
  NvFaceInfo **v55; // ecx
  NvFaceInfo **v56; // edx
  unsigned int v57; // eax
  unsigned int v58; // eax
  unsigned int v59; // ecx
  unsigned int v60; // ecx
  NvFaceInfo **v61; // eax
  char *v62; // esi
  int v63; // ecx
  int v64; // edx
  int v65; // eax
  NvStripInfo *v66; // edi
  NvFaceInfo **v67; // eax
  NvFaceInfo **v68; // edx
  NvFaceInfo **v69; // ecx
  int v70; // esi
  unsigned int v71; // eax
  unsigned int v72; // eax
  unsigned int v73; // ecx
  unsigned int v74; // ecx
  NvFaceInfo **v75; // eax
  NvFaceInfo **v76; // ecx
  NvFaceInfo **v77; // edx
  unsigned int v78; // eax
  unsigned int v79; // eax
  unsigned int v80; // ecx
  unsigned int v81; // ecx
  NvFaceInfo **v82; // eax
  NvStripInfo *v83; // edi
  NvFaceInfo **v84; // eax
  NvFaceInfo **v85; // edx
  NvFaceInfo **v86; // ecx
  int v87; // esi
  unsigned int v88; // eax
  unsigned int v89; // eax
  unsigned int v90; // ecx
  unsigned int v91; // ecx
  NvFaceInfo **v92; // eax
  NvFaceInfo **v93; // ecx
  NvFaceInfo **v94; // edx
  unsigned int v95; // eax
  unsigned int v96; // eax
  unsigned int v97; // ecx
  unsigned int v98; // ecx
  NvFaceInfo **v99; // eax
  NvStripInfo **v100; // esi
  NvStripInfo **v101; // edx
  int v102; // edi
  unsigned int v103; // eax
  unsigned int v104; // eax
  unsigned int v105; // ecx
  unsigned int v106; // ecx
  unsigned int v107; // eax
  unsigned int v108; // eax
  unsigned int v109; // ecx
  unsigned int v110; // ecx
  int v111; // esi
  NvStripInfo *v112; // eax
  int v113; // ecx
  NvFaceInfo **v114; // esi
  int v115; // ecx
  int v116; // edx
  int v117; // eax
  NvStripInfo *v118; // edi
  NvFaceInfo **v119; // eax
  NvFaceInfo **v120; // edx
  NvFaceInfo **v121; // ecx
  int v122; // esi
  unsigned int v123; // eax
  unsigned int v124; // eax
  unsigned int v125; // ecx
  unsigned int v126; // ecx
  NvFaceInfo **v127; // eax
  NvFaceInfo **v128; // ecx
  NvFaceInfo **v129; // edx
  unsigned int v130; // eax
  unsigned int v131; // eax
  unsigned int v132; // ecx
  unsigned int v133; // ecx
  NvFaceInfo **v134; // eax
  NvStripInfo *v135; // edi
  NvFaceInfo **v136; // eax
  NvFaceInfo **v137; // edx
  NvFaceInfo **v138; // ecx
  int v139; // esi
  unsigned int v140; // eax
  unsigned int v141; // eax
  unsigned int v142; // ecx
  unsigned int v143; // ecx
  NvFaceInfo **v144; // eax
  NvFaceInfo **v145; // ecx
  NvFaceInfo **v146; // edx
  unsigned int v147; // eax
  unsigned int v148; // eax
  unsigned int v149; // ecx
  unsigned int v150; // ecx
  NvFaceInfo **v151; // eax
  NvStripInfo **v152; // esi
  NvStripInfo **v153; // edx
  int v154; // edi
  unsigned int v155; // eax
  unsigned int v156; // eax
  unsigned int v157; // ecx
  unsigned int v158; // ecx
  unsigned int v159; // eax
  unsigned int v160; // eax
  unsigned int v161; // ecx
  unsigned int v162; // ecx
  NvStripInfo *v163; // eax
  float v164; // ecx
  int v165; // edx
  NvStripInfo *v166; // edi
  NvStripInfo *v167; // eax
  int v168; // edx
  std::vector<NvFaceInfo *> *p_m_faces; // eax
  NvFaceInfo **v170; // esi
  NvFaceInfo **Mylast; // eax
  NvFaceInfo **v172; // edx
  NvFaceInfo **v173; // ecx
  int v174; // esi
  unsigned int v175; // eax
  unsigned int v176; // eax
  unsigned int v177; // ecx
  unsigned int v178; // ecx
  NvFaceInfo **v179; // eax
  NvFaceInfo **Myend; // ecx
  NvFaceInfo **v181; // edx
  unsigned int v182; // eax
  unsigned int v183; // eax
  unsigned int v184; // ecx
  unsigned int v185; // ecx
  NvFaceInfo **v186; // eax
  NvStripInfo *v187; // eax
  int v188; // edx
  NvStripInfo **v189; // edx
  int v190; // edi
  unsigned int v191; // eax
  unsigned int v192; // eax
  unsigned int v193; // ecx
  unsigned int v194; // ecx
  unsigned int v195; // eax
  unsigned int v196; // eax
  unsigned int v197; // ecx
  unsigned int v198; // ecx
  unsigned int v199; // edx
  unsigned __int8 *v200; // ecx
  unsigned __int8 *v201; // esi
  VertexCache *v202; // esi
  int cacheSize; // eax
  int j; // eax
  float v205; // eax
  unsigned int v206; // esi
  int v207; // ecx
  NvFaceInfo **v208; // edi
  unsigned int v209; // ebx
  int v210; // eax
  double v211; // st7
  NvStripInfo **v212; // ebx
  NvStripInfo **v213; // eax
  NvStripInfo **v214; // edx
  NvStripInfo **v215; // ecx
  int v216; // edi
  unsigned int v217; // eax
  unsigned int v218; // eax
  unsigned int v219; // ecx
  unsigned int v220; // ecx
  NvStripInfo **v221; // eax
  NvStripInfo **v222; // ecx
  unsigned int v223; // eax
  unsigned int v224; // eax
  unsigned int v225; // ecx
  unsigned int v226; // ecx
  NvStripInfo **v227; // eax
  unsigned int v228; // edi
  float v229; // xmm0_4
  NvStripInfo *v230; // esi
  double v231; // st7
  NvFaceInfo *v232; // eax
  int v233; // ebx
  int v234; // edx
  int v235; // edi
  int v236; // ecx
  int *v237; // esi
  int v238; // eax
  int v239; // esi
  int v240; // eax
  int v241; // eax
  int *v242; // ecx
  int v243; // esi
  int v244; // eax
  _DWORD *v245; // eax
  bool v246; // zf
  NvStripInfo **v247; // edi
  NvStripInfo **v248; // eax
  NvStripInfo **v249; // edx
  NvStripInfo **v250; // ecx
  int v251; // ebx
  unsigned int v252; // eax
  unsigned int v253; // eax
  unsigned int v254; // ecx
  unsigned int v255; // ecx
  NvStripInfo **v256; // eax
  NvStripInfo **v257; // ecx
  unsigned int v258; // eax
  unsigned int v259; // eax
  unsigned int v260; // ecx
  unsigned int v261; // ecx
  NvStripInfo **v262; // eax
  int tFirstFace_8; // [esp+14h] [ebp-64h]
  std::vector<NvStripInfo *> tempStrips; // [esp+24h] [ebp-54h] BYREF
  NvStripStartInfo startInfo; // [esp+34h] [ebp-44h] BYREF
  int v266; // [esp+40h] [ebp-38h]
  int currCost; // [esp+44h] [ebp-34h]
  float bestNumHits; // [esp+48h] [ebp-30h]
  int numNeighbors; // [esp+4Ch] [ebp-2Ch]
  unsigned int minCost; // [esp+50h] [ebp-28h]
  int ctr; // [esp+54h] [ebp-24h]
  NvStripifier *v272; // [esp+58h] [ebp-20h]
  int bestIndex; // [esp+5Ch] [ebp-1Ch]
  int firstIndex; // [esp+60h] [ebp-18h]
  int v275; // [esp+64h] [ebp-14h]
  int faceCtr; // [esp+68h] [ebp-10h]
  int i; // [esp+6Ch] [ebp-Ch]
  NvStripInfo *currentStrip; // [esp+70h] [ebp-8h] BYREF
  bool bFirstTime; // [esp+77h] [ebp-1h]
  unsigned int bWantsCW; // [esp+80h] [ebp+8h]
  bool bWantsCW_3; // [esp+83h] [ebp+Bh]
  float nShared1a; // [esp+88h] [ebp+10h]
  int nShared1; // [esp+88h] [ebp+10h]
  VertexCache *vcache; // [esp+8Ch] [ebp+14h]

  v5 = this;
  numNeighbors = this->cacheSize;
  Myfirst = allStrips->_Myfirst;
  v7 = allStrips->_Mylast - allStrips->_Myfirst;
  v272 = v5;
  memset(&tempStrips, 0, 12);
  i = 0;
  if ( v7 != 0 )
  {
    while ( 1 )
    {
      v8 = Myfirst[i];
      v9 = 0;
      v10 = v8->m_faces._Mylast - v8->m_faces._Myfirst;
      startInfo.m_startEdge = nullptr;
      *(_DWORD *)&startInfo.m_toV1 = 0;
      LOBYTE(v266) = 0;
      ctr = 0;
      if ( v10 != 0 )
      {
        v11 = v8->m_faces._Myfirst;
        do
        {
          m_v0 = (*v11)->m_v0;
          m_v1 = (*v11)->m_v1;
          if ( m_v0 != m_v1 )
          {
            m_v2 = (*v11)->m_v2;
            if ( m_v0 != m_v2 && m_v1 != m_v2 )
              ++ctr;
          }
          ++v9;
          ++v11;
        }
        while ( v9 < v8->m_faces._Mylast - v8->m_faces._Myfirst );
      }
      v15 = numNeighbors;
      if ( ctr <= numNeighbors )
      {
        v163 = (NvStripInfo *)MemAlloc_Alloc(nSize: 0x2Cu);
        v164 = 0.0;
        if ( v163 != nullptr )
        {
          v165 = v266;
          *(_QWORD *)&v163->m_startInfo.m_startFace = *(_QWORD *)&startInfo.m_startEdge;
          *(_DWORD *)&v163->m_startInfo.m_toV1 = v165;
          v163->m_faces._Myfirst = nullptr;
          v163->m_faces._Mylast = nullptr;
          v163->m_faces._Myend = nullptr;
          v163->m_stripId = 0;
          v163->m_experimentId = -1;
          v163->visited = false;
          v163->m_numDegenerates = 0;
          v166 = v163;
        }
        else
        {
          v166 = nullptr;
        }
        v167 = allStrips->_Myfirst[i];
        v168 = (char *)v167->m_faces._Mylast - (char *)v167->m_faces._Myfirst;
        p_m_faces = &v167->m_faces;
        currentStrip = v166;
        bestNumHits = 0.0;
        if ( v168 >> 2 != 0 )
        {
          do
          {
            v170 = &p_m_faces->_Myfirst[LODWORD(v164)];
            Mylast = v166->m_faces._Mylast;
            if ( v170 >= Mylast || (v172 = v166->m_faces._Myfirst) > v170 )
            {
              Myend = v166->m_faces._Myend;
              if ( Mylast == Myend )
              {
                v181 = v166->m_faces._Myfirst;
                v182 = Mylast - v181;
                if ( v182 > 0x3FFFFFFE )
                  goto LABEL_323;
                v183 = v182 + 1;
                v184 = Myend - v181;
                if ( v183 > v184 )
                {
                  if ( 0x3FFFFFFF - (v184 >> 1) >= v184 )
                    v185 = (v184 >> 1) + v184;
                  else
                    v185 = 0;
                  if ( v185 < v183 )
                    v185 = v183;
                  std::vector<int>::reserve(this: (std::vector<int> *)&v166->m_faces, _Count: v185);
                }
              }
              v186 = v166->m_faces._Mylast;
              if ( v186 != nullptr )
                *v186 = *v170;
            }
            else
            {
              v173 = v166->m_faces._Myend;
              v174 = v170 - v172;
              if ( Mylast == v173 )
              {
                v175 = Mylast - v172;
                if ( v175 > 0x3FFFFFFE )
                  goto LABEL_323;
                v176 = v175 + 1;
                v177 = v173 - v172;
                if ( v176 > v177 )
                {
                  if ( 0x3FFFFFFF - (v177 >> 1) >= v177 )
                    v178 = (v177 >> 1) + v177;
                  else
                    v178 = 0;
                  if ( v178 < v176 )
                    v178 = v176;
                  std::vector<int>::reserve(this: (std::vector<int> *)&v166->m_faces, _Count: v178);
                }
              }
              v179 = v166->m_faces._Mylast;
              if ( v179 != nullptr )
                *v179 = v166->m_faces._Myfirst[v174];
            }
            ++v166->m_faces._Mylast;
            v187 = allStrips->_Myfirst[i];
            v188 = (char *)v187->m_faces._Mylast - (char *)v187->m_faces._Myfirst;
            p_m_faces = &v187->m_faces;
            LODWORD(v164) = LODWORD(bestNumHits) + 1;
            bestNumHits = v164;
          }
          while ( LODWORD(v164) < v188 >> 2 );
          v166 = currentStrip;
        }
        v152 = tempStrips._Mylast;
        v189 = tempStrips._Myfirst;
        if ( &currentStrip >= tempStrips._Mylast || tempStrips._Myfirst > &currentStrip )
        {
          if ( tempStrips._Mylast == tempStrips._Myend )
          {
            v195 = tempStrips._Mylast - tempStrips._Myfirst;
            if ( v195 > 0x3FFFFFFE )
              goto LABEL_323;
            v196 = v195 + 1;
            v197 = tempStrips._Myend - tempStrips._Myfirst;
            if ( v196 > v197 )
            {
              if ( 0x3FFFFFFF - (v197 >> 1) >= v197 )
                v198 = (v197 >> 1) + v197;
              else
                v198 = 0;
              if ( v198 < v196 )
                v198 = v196;
              std::vector<int>::reserve(this: (std::vector<int> *)&tempStrips, _Count: v198);
              v152 = tempStrips._Mylast;
            }
          }
          if ( v152 != nullptr )
            *v152 = v166;
        }
        else
        {
          v190 = &currentStrip - tempStrips._Myfirst;
          if ( tempStrips._Mylast == tempStrips._Myend )
          {
            v191 = tempStrips._Mylast - tempStrips._Myfirst;
            if ( v191 > 0x3FFFFFFE )
              goto LABEL_323;
            v192 = v191 + 1;
            v193 = tempStrips._Myend - tempStrips._Myfirst;
            if ( v192 > v193 )
            {
              if ( 0x3FFFFFFF - (v193 >> 1) >= v193 )
                v194 = (v193 >> 1) + v193;
              else
                v194 = 0;
              if ( v194 < v192 )
                v194 = v192;
              std::vector<int>::reserve(this: (std::vector<int> *)&tempStrips, _Count: v194);
              v152 = tempStrips._Mylast;
              v189 = tempStrips._Myfirst;
            }
          }
          if ( v152 != nullptr )
            *v152 = v189[v190];
        }
      }
      else
      {
        v16 = ctr / numNeighbors;
        v17 = ctr % numNeighbors;
        bestIndex = 0;
        ctr = 0;
        minCost = v16;
        firstIndex = v17;
        if ( v16 <= 0 )
        {
          v18 = 0;
          goto LABEL_161;
        }
        while ( 1 )
        {
          v19 = (NvStripInfo *)MemAlloc_Alloc(nSize: 0x2Cu);
          if ( v19 != nullptr )
          {
            v20 = v266;
            *(_QWORD *)&v19->m_startInfo.m_startFace = *(_QWORD *)&startInfo.m_startEdge;
            *(_DWORD *)&v19->m_startInfo.m_toV1 = v20;
            v19->m_faces._Myfirst = nullptr;
            v19->m_faces._Mylast = nullptr;
            v19->m_faces._Myend = nullptr;
            v19->m_stripId = 0;
            v19->m_experimentId = -1;
            v19->visited = false;
            v19->m_numDegenerates = 0;
            currentStrip = v19;
          }
          else
          {
            currentStrip = nullptr;
          }
          currCost = ctr + 1;
          v21 = bestIndex + v15 * ctr;
          faceCtr = v21;
          bFirstTime = true;
          if ( v21 < bestIndex + v15 * (ctr + 1) )
          {
            LODWORD(v22) = bestIndex + v15 * (ctr + 1);
            bestNumHits = v22;
            v275 = v21 + 1;
            while ( 1 )
            {
              v23 = allStrips->_Myfirst[i]->m_faces._Myfirst;
              v24 = v23[v21];
              v25 = v24->m_v0;
              v26 = &v23[v21];
              v27 = v24->m_v1;
              if ( v24->m_v0 != v27 )
              {
                v28 = v24->m_v2;
                if ( v25 != v28 && v27 != v28 )
                  break;
              }
              ++bestIndex;
              LODWORD(bestNumHits) = LODWORD(v22) + 1;
              if ( (v275 != LODWORD(v22) + 1 || ctr == minCost - 1 && (unsigned int)(firstIndex - 1) <= 2)
                && !bFirstTime )
              {
                v29 = currentStrip;
                v30 = currentStrip->m_faces._Mylast;
                if ( v26 >= v30 || (v31 = currentStrip->m_faces._Myfirst) > v26 )
                {
                  v39 = currentStrip->m_faces._Myend;
                  if ( v30 == v39 )
                  {
                    v40 = currentStrip->m_faces._Myfirst;
                    v41 = v30 - v40;
                    if ( v41 > 0x3FFFFFFE )
                      goto LABEL_323;
                    v42 = v41 + 1;
                    v43 = v39 - v40;
                    if ( v42 > v43 )
                    {
                      if ( 0x3FFFFFFF - (v43 >> 1) >= v43 )
                        v44 = (v43 >> 1) + v43;
                      else
                        v44 = 0;
                      if ( v44 < v42 )
                        v44 = v42;
                      std::vector<int>::reserve(this: (std::vector<int> *)&currentStrip->m_faces, _Count: v44);
                      v21 = faceCtr;
                    }
                  }
                  v45 = v29->m_faces._Mylast;
                  if ( v45 != nullptr )
                    *v45 = *v26;
                }
                else
                {
                  v32 = currentStrip->m_faces._Myend;
                  v33 = v26 - v31;
                  if ( v30 == v32 )
                  {
                    v34 = v30 - v31;
                    if ( v34 > 0x3FFFFFFE )
                      goto LABEL_323;
                    v35 = v34 + 1;
                    v36 = v32 - v31;
                    if ( v35 > v36 )
                    {
                      if ( 0x3FFFFFFF - (v36 >> 1) >= v36 )
                        v37 = (v36 >> 1) + v36;
                      else
                        v37 = 0;
                      if ( v37 < v35 )
                        v37 = v35;
                      std::vector<int>::reserve(this: (std::vector<int> *)&currentStrip->m_faces, _Count: v37);
                      v21 = faceCtr;
                    }
                  }
                  v38 = v29->m_faces._Mylast;
                  if ( v38 != nullptr )
                    *v38 = v29->m_faces._Myfirst[v33];
                }
LABEL_75:
                ++v29->m_faces._Mylast;
                ++v21;
                ++v275;
                goto LABEL_76;
              }
              ++v21;
              ++v275;
LABEL_76:
              v22 = bestNumHits;
              faceCtr = v21;
              if ( v21 >= SLODWORD(bestNumHits) )
                goto LABEL_77;
            }
            v29 = currentStrip;
            v46 = currentStrip->m_faces._Mylast;
            if ( v26 >= v46 || (v47 = currentStrip->m_faces._Myfirst) > v26 )
            {
              v55 = currentStrip->m_faces._Myend;
              if ( v46 == v55 )
              {
                v56 = currentStrip->m_faces._Myfirst;
                v57 = v46 - v56;
                if ( v57 > 0x3FFFFFFE )
                  goto LABEL_323;
                v58 = v57 + 1;
                v59 = v55 - v56;
                if ( v58 > v59 )
                {
                  if ( 0x3FFFFFFF - (v59 >> 1) >= v59 )
                    v60 = (v59 >> 1) + v59;
                  else
                    v60 = 0;
                  if ( v60 < v58 )
                    v60 = v58;
                  std::vector<int>::reserve(this: (std::vector<int> *)&currentStrip->m_faces, _Count: v60);
                  v21 = faceCtr;
                }
              }
              v61 = v29->m_faces._Mylast;
              if ( v61 != nullptr )
                *v61 = *v26;
            }
            else
            {
              v48 = currentStrip->m_faces._Myend;
              v49 = v26 - v47;
              if ( v46 == v48 )
              {
                v50 = v46 - v47;
                if ( v50 > 0x3FFFFFFE )
                  goto LABEL_323;
                v51 = v50 + 1;
                v52 = v48 - v47;
                if ( v51 > v52 )
                {
                  if ( 0x3FFFFFFF - (v52 >> 1) >= v52 )
                    v53 = (v52 >> 1) + v52;
                  else
                    v53 = 0;
                  if ( v53 < v51 )
                    v53 = v51;
                  std::vector<int>::reserve(this: (std::vector<int> *)&currentStrip->m_faces, _Count: v53);
                  v21 = faceCtr;
                }
              }
              v54 = v29->m_faces._Mylast;
              if ( v54 != nullptr )
                *v54 = v29->m_faces._Myfirst[v49];
            }
            bFirstTime = false;
            goto LABEL_75;
          }
LABEL_77:
          if ( ctr == minCost - 1 && (unsigned int)(firstIndex - 1) <= 2 )
          {
            ctr = 0;
            v275 = 4 * v21;
            while ( 1 )
            {
              v62 = (char *)allStrips->_Myfirst[i]->m_faces._Myfirst + v275;
              v63 = **(_DWORD **)v62;
              v64 = *(_DWORD *)(*(_DWORD *)v62 + 4);
              if ( v63 == v64 || (v65 = *(_DWORD *)(*(_DWORD *)v62 + 8), v63 == v65) || v64 == v65 )
              {
                v83 = currentStrip;
                v84 = currentStrip->m_faces._Mylast;
                if ( v62 >= (char *)v84 || (v85 = currentStrip->m_faces._Myfirst) > (NvFaceInfo **)v62 )
                {
                  v93 = currentStrip->m_faces._Myend;
                  if ( v84 == v93 )
                  {
                    v94 = currentStrip->m_faces._Myfirst;
                    v95 = v84 - v94;
                    if ( v95 > 0x3FFFFFFE )
                      goto LABEL_323;
                    v96 = v95 + 1;
                    v97 = v93 - v94;
                    if ( v96 > v97 )
                    {
                      if ( 0x3FFFFFFF - (v97 >> 1) >= v97 )
                        v98 = (v97 >> 1) + v97;
                      else
                        v98 = 0;
                      if ( v98 < v96 )
                        v98 = v96;
                      std::vector<int>::reserve(this: (std::vector<int> *)&currentStrip->m_faces, _Count: v98);
                    }
                  }
                  v99 = v83->m_faces._Mylast;
                  if ( v99 != nullptr )
                    *v99 = *(NvFaceInfo **)v62;
                }
                else
                {
                  v86 = currentStrip->m_faces._Myend;
                  v87 = (v62 - (char *)v85) >> 2;
                  if ( v84 == v86 )
                  {
                    v88 = v84 - v85;
                    if ( v88 > 0x3FFFFFFE )
                      goto LABEL_323;
                    v89 = v88 + 1;
                    v90 = v86 - v85;
                    if ( v89 > v90 )
                    {
                      if ( 0x3FFFFFFF - (v90 >> 1) >= v90 )
                        v91 = (v90 >> 1) + v90;
                      else
                        v91 = 0;
                      if ( v91 < v89 )
                        v91 = v89;
                      std::vector<int>::reserve(this: (std::vector<int> *)&currentStrip->m_faces, _Count: v91);
                    }
                  }
                  v92 = v83->m_faces._Mylast;
                  if ( v92 != nullptr )
                    *v92 = v83->m_faces._Myfirst[v87];
                }
                ++v83->m_faces._Mylast;
                v275 += 4;
                ++bestIndex;
                goto LABEL_133;
              }
              v66 = currentStrip;
              v67 = currentStrip->m_faces._Mylast;
              if ( v62 >= (char *)v67 )
                break;
              v68 = currentStrip->m_faces._Myfirst;
              if ( v68 > (NvFaceInfo **)v62 )
                break;
              v69 = currentStrip->m_faces._Myend;
              v70 = (v62 - (char *)v68) >> 2;
              if ( v67 == v69 )
              {
                v71 = v67 - v68;
                if ( v71 > 0x3FFFFFFE )
                  goto LABEL_323;
                v72 = v71 + 1;
                v73 = v69 - v68;
                if ( v72 > v73 )
                {
                  if ( 0x3FFFFFFF - (v73 >> 1) >= v73 )
                    v74 = (v73 >> 1) + v73;
                  else
                    v74 = 0;
                  if ( v74 < v72 )
                    v74 = v72;
                  std::vector<int>::reserve(this: (std::vector<int> *)&currentStrip->m_faces, _Count: v74);
                }
              }
              v75 = v66->m_faces._Mylast;
              if ( v75 == nullptr )
                goto LABEL_107;
              *v75 = v66->m_faces._Myfirst[v70];
              ++v66->m_faces._Mylast;
              v275 += 4;
              ++ctr;
LABEL_133:
              if ( ctr >= firstIndex )
              {
                firstIndex = 0;
                goto LABEL_135;
              }
            }
            v76 = currentStrip->m_faces._Myend;
            if ( v67 == v76 )
            {
              v77 = currentStrip->m_faces._Myfirst;
              v78 = v67 - v77;
              if ( v78 > 0x3FFFFFFE )
                goto LABEL_323;
              v79 = v78 + 1;
              v80 = v76 - v77;
              if ( v79 > v80 )
              {
                if ( 0x3FFFFFFF - (v80 >> 1) >= v80 )
                  v81 = (v80 >> 1) + v80;
                else
                  v81 = 0;
                if ( v81 < v79 )
                  v81 = v79;
                std::vector<int>::reserve(this: (std::vector<int> *)&currentStrip->m_faces, _Count: v81);
              }
            }
            v82 = v66->m_faces._Mylast;
            if ( v82 != nullptr )
              *v82 = *(NvFaceInfo **)v62;
LABEL_107:
            ++v66->m_faces._Mylast;
            v275 += 4;
            ++ctr;
            goto LABEL_133;
          }
LABEL_135:
          v100 = tempStrips._Mylast;
          v101 = tempStrips._Myfirst;
          if ( &currentStrip >= tempStrips._Mylast || tempStrips._Myfirst > &currentStrip )
          {
            if ( tempStrips._Mylast == tempStrips._Myend )
            {
              v107 = tempStrips._Mylast - tempStrips._Myfirst;
              if ( v107 > 0x3FFFFFFE )
                goto LABEL_323;
              v108 = v107 + 1;
              v109 = tempStrips._Myend - tempStrips._Myfirst;
              if ( v108 > v109 )
              {
                if ( 0x3FFFFFFF - (v109 >> 1) >= v109 )
                  v110 = (v109 >> 1) + v109;
                else
                  v110 = 0;
                if ( v110 < v108 )
                  v110 = v108;
                std::vector<int>::reserve(this: (std::vector<int> *)&tempStrips, _Count: v110);
                v100 = tempStrips._Mylast;
              }
            }
            if ( v100 != nullptr )
              *v100 = currentStrip;
          }
          else
          {
            v102 = &currentStrip - tempStrips._Myfirst;
            if ( tempStrips._Mylast == tempStrips._Myend )
            {
              v103 = tempStrips._Mylast - tempStrips._Myfirst;
              if ( v103 > 0x3FFFFFFE )
                goto LABEL_323;
              v104 = v103 + 1;
              v105 = tempStrips._Myend - tempStrips._Myfirst;
              if ( v104 > v105 )
              {
                if ( 0x3FFFFFFF - (v105 >> 1) >= v105 )
                  v106 = (v105 >> 1) + v105;
                else
                  v106 = 0;
                if ( v106 < v104 )
                  v106 = v104;
                std::vector<int>::reserve(this: (std::vector<int> *)&tempStrips, _Count: v106);
                v100 = tempStrips._Mylast;
                v101 = tempStrips._Myfirst;
              }
            }
            if ( v100 != nullptr )
              *v100 = v101[v102];
          }
          v18 = currCost;
          tempStrips._Mylast = v100 + 1;
          ctr = currCost;
          if ( currCost >= (int)minCost )
            break;
          v15 = numNeighbors;
        }
        v15 = numNeighbors;
LABEL_161:
        v111 = bestIndex + v18 * v15;
        if ( firstIndex == 0 )
          goto LABEL_302;
        v112 = (NvStripInfo *)MemAlloc_Alloc(nSize: 0x2Cu);
        if ( v112 != nullptr )
        {
          v113 = v266;
          *(_QWORD *)&v112->m_startInfo.m_startFace = *(_QWORD *)&startInfo.m_startEdge;
          *(_DWORD *)&v112->m_startInfo.m_toV1 = v113;
          v112->m_faces._Myfirst = nullptr;
          v112->m_faces._Mylast = nullptr;
          v112->m_faces._Myend = nullptr;
          v112->m_stripId = 0;
          v112->m_experimentId = -1;
          v112->visited = false;
          v112->m_numDegenerates = 0;
          currentStrip = v112;
        }
        else
        {
          currentStrip = nullptr;
        }
        *(float *)&minCost = 0.0;
        bFirstTime = true;
        if ( firstIndex > 0 )
        {
          v275 = 4 * v111;
          do
          {
            v114 = (NvFaceInfo **)((char *)allStrips->_Myfirst[i]->m_faces._Myfirst + v275);
            v115 = (*v114)->m_v0;
            v116 = (*v114)->m_v1;
            if ( v115 == v116 || (v117 = (*v114)->m_v2, v115 == v117) || v116 == v117 )
            {
              if ( bFirstTime )
              {
                v275 += 4;
                continue;
              }
              v135 = currentStrip;
              v136 = currentStrip->m_faces._Mylast;
              if ( v114 >= v136 || (v137 = currentStrip->m_faces._Myfirst) > v114 )
              {
                v145 = currentStrip->m_faces._Myend;
                if ( v136 == v145 )
                {
                  v146 = currentStrip->m_faces._Myfirst;
                  v147 = v136 - v146;
                  if ( v147 > 0x3FFFFFFE )
                    goto LABEL_323;
                  v148 = v147 + 1;
                  v149 = v145 - v146;
                  if ( v148 > v149 )
                  {
                    if ( 0x3FFFFFFF - (v149 >> 1) >= v149 )
                      v150 = (v149 >> 1) + v149;
                    else
                      v150 = 0;
                    if ( v150 < v148 )
                      v150 = v148;
                    std::vector<int>::reserve(this: (std::vector<int> *)&currentStrip->m_faces, _Count: v150);
                  }
                }
                v151 = v135->m_faces._Mylast;
                if ( v151 != nullptr )
                  *v151 = *v114;
LABEL_220:
                ++v135->m_faces._Mylast;
                v275 += 4;
                continue;
              }
              v138 = currentStrip->m_faces._Myend;
              v139 = v114 - v137;
              if ( v136 == v138 )
              {
                v140 = v136 - v137;
                if ( v140 > 0x3FFFFFFE )
                  goto LABEL_323;
                v141 = v140 + 1;
                v142 = v138 - v137;
                if ( v141 > v142 )
                {
                  if ( 0x3FFFFFFF - (v142 >> 1) >= v142 )
                    v143 = (v142 >> 1) + v142;
                  else
                    v143 = 0;
                  if ( v143 < v141 )
                    v143 = v141;
                  std::vector<int>::reserve(this: (std::vector<int> *)&currentStrip->m_faces, _Count: v143);
                }
              }
              v144 = v135->m_faces._Mylast;
              if ( v144 == nullptr )
                goto LABEL_220;
              *v144 = v135->m_faces._Myfirst[v139];
              ++v135->m_faces._Mylast;
              v275 += 4;
            }
            else
            {
              v118 = currentStrip;
              v119 = currentStrip->m_faces._Mylast;
              ++minCost;
              bFirstTime = false;
              if ( v114 >= v119 || (v120 = currentStrip->m_faces._Myfirst) > v114 )
              {
                v128 = currentStrip->m_faces._Myend;
                if ( v119 == v128 )
                {
                  v129 = currentStrip->m_faces._Myfirst;
                  v130 = v119 - v129;
                  if ( v130 > 0x3FFFFFFE )
                    goto LABEL_323;
                  v131 = v130 + 1;
                  v132 = v128 - v129;
                  if ( v131 > v132 )
                  {
                    if ( 0x3FFFFFFF - (v132 >> 1) >= v132 )
                      v133 = (v132 >> 1) + v132;
                    else
                      v133 = 0;
                    if ( v133 < v131 )
                      v133 = v131;
                    std::vector<int>::reserve(this: (std::vector<int> *)&currentStrip->m_faces, _Count: v133);
                  }
                }
                v134 = v118->m_faces._Mylast;
                if ( v134 != nullptr )
                  *v134 = *v114;
LABEL_194:
                ++v118->m_faces._Mylast;
                v275 += 4;
                continue;
              }
              v121 = currentStrip->m_faces._Myend;
              v122 = v114 - v120;
              if ( v119 == v121 )
              {
                v123 = v119 - v120;
                if ( v123 > 0x3FFFFFFE )
                  goto LABEL_323;
                v124 = v123 + 1;
                v125 = v121 - v120;
                if ( v124 > v125 )
                {
                  if ( 0x3FFFFFFF - (v125 >> 1) >= v125 )
                    v126 = (v125 >> 1) + v125;
                  else
                    v126 = 0;
                  if ( v126 < v124 )
                    v126 = v124;
                  std::vector<int>::reserve(this: (std::vector<int> *)&currentStrip->m_faces, _Count: v126);
                }
              }
              v127 = v118->m_faces._Mylast;
              if ( v127 == nullptr )
                goto LABEL_194;
              *v127 = v118->m_faces._Myfirst[v122];
              ++v118->m_faces._Mylast;
              v275 += 4;
            }
          }
          while ( (int)minCost < firstIndex );
        }
        v152 = tempStrips._Mylast;
        v153 = tempStrips._Myfirst;
        if ( &currentStrip >= tempStrips._Mylast || tempStrips._Myfirst > &currentStrip )
        {
          if ( tempStrips._Mylast == tempStrips._Myend )
          {
            v159 = tempStrips._Mylast - tempStrips._Myfirst;
            if ( v159 > 0x3FFFFFFE )
              goto LABEL_323;
            v160 = v159 + 1;
            v161 = tempStrips._Myend - tempStrips._Myfirst;
            if ( v160 > v161 )
            {
              if ( 0x3FFFFFFF - (v161 >> 1) >= v161 )
                v162 = (v161 >> 1) + v161;
              else
                v162 = 0;
              if ( v162 < v160 )
                v162 = v160;
              std::vector<int>::reserve(this: (std::vector<int> *)&tempStrips, _Count: v162);
              v152 = tempStrips._Mylast;
            }
          }
          if ( v152 != nullptr )
            *v152 = currentStrip;
        }
        else
        {
          v154 = &currentStrip - tempStrips._Myfirst;
          if ( tempStrips._Mylast == tempStrips._Myend )
          {
            v155 = tempStrips._Mylast - tempStrips._Myfirst;
            if ( v155 > 0x3FFFFFFE )
              goto LABEL_323;
            v156 = v155 + 1;
            v157 = tempStrips._Myend - tempStrips._Myfirst;
            if ( v156 > v157 )
            {
              if ( 0x3FFFFFFF - (v157 >> 1) >= v157 )
                v158 = (v157 >> 1) + v157;
              else
                v158 = 0;
              if ( v158 < v156 )
                v158 = v156;
              std::vector<int>::reserve(this: (std::vector<int> *)&tempStrips, _Count: v158);
              v152 = tempStrips._Mylast;
              v153 = tempStrips._Myfirst;
            }
          }
          if ( v152 != nullptr )
            *v152 = v153[v154];
        }
      }
      tempStrips._Mylast = v152 + 1;
LABEL_302:
      Myfirst = allStrips->_Myfirst;
      v199 = allStrips->_Mylast - allStrips->_Myfirst;
      if ( ++i >= v199 )
      {
        v5 = v272;
        break;
      }
    }
  }
  memset(&startInfo, 0, sizeof(startInfo));
  NvStripifier::RemoveSmallStrips(
    this: v5,
    allStrips: &tempStrips,
    allBigStrips: (std::vector<int> *)&startInfo,
    faceList: outFaceList);
  v200 = (unsigned __int8 *)outStrips->_Mylast;
  v201 = (unsigned __int8 *)outStrips->_Myfirst;
  if ( (unsigned __int8 *)outStrips->_Myfirst != v200 )
  {
    memmove(dst: v201, src: v200, count: 0);
    outStrips->_Mylast = (NvStripInfo **)v201;
  }
  ctr = ((char *)startInfo.m_startEdge - (char *)startInfo.m_startFace) >> 2;
  if ( ctr != 0 )
  {
    v202 = (VertexCache *)MemAlloc_Alloc(nSize: 8u);
    if ( v202 != nullptr )
    {
      cacheSize = v272->cacheSize;
      v202->numEntries = cacheSize;
      v202->entries = (int *)MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)cacheSize >> 30 != 0 ? -1 : 4 * cacheSize);
      for ( j = 0; j < v202->numEntries; ++j )
        v202->entries[j] = -1;
      vcache = v202;
    }
    else
    {
      vcache = nullptr;
    }
    bestIndex = 0;
    firstIndex = 0;
    *(float *)&minCost = 10000.0;
    for ( bWantsCW = 0; bWantsCW < ctr; ++bWantsCW )
    {
      v205 = *((float *)&startInfo.m_startFace->m_v0 + bWantsCW);
      v206 = 0;
      v207 = (*(_DWORD *)(LODWORD(v205) + 16) - *(_DWORD *)(LODWORD(v205) + 12)) >> 2;
      numNeighbors = 0;
      bestNumHits = v205;
      if ( v207 != 0 )
      {
        v208 = *(NvFaceInfo ***)(LODWORD(v205) + 12);
        v209 = (*(_DWORD *)(LODWORD(v205) + 16) - (int)v208) >> 2;
        do
        {
          v210 = NvStripifier::NumNeighbors(this: v272, face: *v208, edgeInfoVec: edgeInfos);
          numNeighbors += v210;
          ++v206;
          ++v208;
        }
        while ( v206 < v209 );
      }
      currCost = (*(_DWORD *)(LODWORD(bestNumHits) + 16) - *(_DWORD *)(LODWORD(bestNumHits) + 12)) >> 2;
      v211 = (double)numNeighbors / (double)(unsigned int)currCost;
      *(float *)&currCost = v211;
      if ( *(float *)&minCost > v211 )
      {
        minCost = currCost;
        firstIndex = bWantsCW;
      }
    }
    v212 = (NvStripInfo **)(&startInfo.m_startFace->m_v0 + firstIndex);
    NvStripifier::UpdateCacheStrip(this: v272, vcache, strip: *v212);
    v213 = outStrips->_Mylast;
    if ( v212 >= v213 || (v214 = outStrips->_Myfirst, outStrips->_Myfirst > v212) )
    {
      v222 = outStrips->_Myend;
      if ( v213 == v222 )
      {
        v223 = v213 - outStrips->_Myfirst;
        if ( v223 > 0x3FFFFFFE )
          std::_Xlength_error(_Message: "vector<T> too long");
        v224 = v223 + 1;
        v225 = v222 - outStrips->_Myfirst;
        if ( v224 > v225 )
        {
          if ( 0x3FFFFFFF - (v225 >> 1) >= v225 )
            v226 = (v225 >> 1) + v225;
          else
            v226 = 0;
          if ( v226 < v224 )
            v226 = v224;
          std::vector<int>::reserve(this: (std::vector<int> *)outStrips, _Count: v226);
        }
      }
      v227 = outStrips->_Mylast;
      if ( v227 != nullptr )
        *v227 = *v212;
    }
    else
    {
      v215 = outStrips->_Myend;
      v216 = v212 - v214;
      if ( v213 == v215 )
      {
        v217 = v213 - v214;
        if ( v217 > 0x3FFFFFFE )
          goto LABEL_323;
        v218 = v217 + 1;
        v219 = v215 - v214;
        if ( v218 > v219 )
        {
          if ( 0x3FFFFFFF - (v219 >> 1) >= v219 )
            v220 = (v219 >> 1) + v219;
          else
            v220 = 0;
          if ( v220 < v218 )
            v220 = v218;
          std::vector<int>::reserve(this: (std::vector<int> *)outStrips, _Count: v220);
        }
      }
      v221 = outStrips->_Mylast;
      if ( v221 != nullptr )
        *v221 = outStrips->_Myfirst[v216];
    }
    ++outStrips->_Mylast;
    (*v212)->visited = true;
    bWantsCW_3 = (((*v212)->m_faces._Mylast - (*v212)->m_faces._Myfirst) & 1) == 0;
LABEL_346:
    *(float *)&v228 = 0.0;
    v229 = -1.0;
    bestNumHits = -1.0;
    *(float *)&minCost = 0.0;
    if ( ctr != 0 )
    {
      while ( 1 )
      {
        v230 = (NvStripInfo *)*(&startInfo.m_startFace->m_v0 + v228);
        v246 = !v230->visited;
        numNeighbors = (int)v230;
        if ( v246 )
        {
          v231 = NvStripifier::CalcNumHitsStrip(this: v272, vcache, strip: v230);
          if ( v231 <= bestNumHits )
          {
            nShared1a = v231;
            if ( nShared1a >= v229 )
            {
              v232 = *v230->m_faces._Myfirst;
              v233 = v232->m_v2;
              v234 = v232->m_v0;
              v235 = v232->m_v1;
              v236 = v230->m_faces._Mylast - v230->m_faces._Myfirst;
              tFirstFace_8 = v233;
              if ( v236 > 1 )
              {
                v237 = *(int **)(*(_DWORD *)(numNeighbors + 12) + 4);
                v238 = *v237;
                if ( v234 != *v237 && v234 != v237[1] && v234 != v237[2] )
                {
                  v239 = v234;
                  goto LABEL_364;
                }
                if ( v235 != v238 && v235 != v237[1] && v235 != v237[2] )
                  goto LABEL_365;
                v239 = v233 == v238 || v233 == v237[1] || v233 == v237[2] ? -1 : v233;
LABEL_364:
                if ( v239 != v235 )
                {
                  if ( v239 == v233 )
                  {
                    v241 = v234;
                    v234 = v233;
                    v233 = v241;
                    tFirstFace_8 = v241;
                  }
                }
                else
                {
LABEL_365:
                  v240 = v234;
                  v234 = v235;
                  v235 = v240;
                }
                if ( v236 > 2 )
                {
                  v242 = *(int **)(*(_DWORD *)(numNeighbors + 12) + 8);
                  v243 = *v242;
                  v244 = -1;
                  nShared1 = -1;
                  if ( v234 == *v242 || v234 == v242[1] || v234 == v242[2] )
                    v244 = v234;
                  if ( v235 == v243 || v235 == v242[1] || v235 == v242[2] )
                  {
                    if ( v244 == -1 )
                    {
                      v244 = v235;
                      goto LABEL_378;
                    }
                    nShared1 = v235;
                  }
                  else
                  {
LABEL_378:
                    v233 = tFirstFace_8;
                    if ( tFirstFace_8 == v243 || tFirstFace_8 == v242[1] || tFirstFace_8 == v242[2] )
                    {
                      if ( v244 == -1 )
                        v244 = tFirstFace_8;
                      else
                        nShared1 = tFirstFace_8;
                    }
                  }
                  if ( v244 == v235 && nShared1 == -1 )
                    v235 = v233;
                }
              }
              v245 = **(_DWORD ***)(numNeighbors + 12);
              if ( *v245 == v234 )
              {
                v246 = v245[1] == v235;
              }
              else if ( v245[1] == v234 )
              {
                v246 = v245[2] == v235;
              }
              else
              {
                v246 = *v245 == v235;
              }
              if ( bWantsCW_3 == v246 )
                bestIndex = minCost;
            }
          }
          else
          {
            v229 = v231;
            bestNumHits = v231;
            bestIndex = v228;
          }
        }
        v228 = minCost + 1;
        minCost = v228;
        if ( v228 >= ctr )
        {
          if ( v229 == -1.0 )
            break;
          v247 = (NvStripInfo **)(&startInfo.m_startFace->m_v0 + bestIndex);
          (*v247)->visited = true;
          NvStripifier::UpdateCacheStrip(this: v272, vcache, strip: *v247);
          v248 = outStrips->_Mylast;
          if ( v247 >= v248 || (v249 = outStrips->_Myfirst, outStrips->_Myfirst > v247) )
          {
            v257 = outStrips->_Myend;
            if ( v248 != v257 )
            {
LABEL_419:
              v262 = outStrips->_Mylast;
              if ( v262 != nullptr )
                *v262 = *v247;
              goto LABEL_421;
            }
            v258 = v248 - outStrips->_Myfirst;
            if ( v258 <= 0x3FFFFFFE )
            {
              v259 = v258 + 1;
              v260 = v257 - outStrips->_Myfirst;
              if ( v259 > v260 )
              {
                if ( 0x3FFFFFFF - (v260 >> 1) >= v260 )
                  v261 = (v260 >> 1) + v260;
                else
                  v261 = 0;
                if ( v261 < v259 )
                  v261 = v259;
                std::vector<int>::reserve(this: (std::vector<int> *)outStrips, _Count: v261);
              }
              goto LABEL_419;
            }
LABEL_323:
            std::_Xlength_error(_Message: "vector<T> too long");
          }
          v250 = outStrips->_Myend;
          v251 = v247 - v249;
          if ( v248 != v250 )
            goto LABEL_408;
          v252 = v248 - v249;
          if ( v252 > 0x3FFFFFFE )
            goto LABEL_323;
          v253 = v252 + 1;
          v254 = v250 - v249;
          if ( v253 > v254 )
          {
            if ( 0x3FFFFFFF - (v254 >> 1) >= v254 )
              v255 = (v254 >> 1) + v254;
            else
              v255 = 0;
            if ( v255 < v253 )
              v255 = v253;
            std::vector<int>::reserve(this: (std::vector<int> *)outStrips, _Count: v255);
          }
LABEL_408:
          v256 = outStrips->_Mylast;
          if ( v256 != nullptr )
            *v256 = outStrips->_Myfirst[v251];
LABEL_421:
          ++outStrips->_Mylast;
          if ( ((LOBYTE((*v247)->m_faces._Mylast) - LOBYTE((*v247)->m_faces._Myfirst)) & 4) != 0 )
            bWantsCW_3 = !bWantsCW_3;
          goto LABEL_346;
        }
      }
    }
    if ( vcache != nullptr )
    {
      free(pMem: vcache->entries);
      vcache->entries = nullptr;
      free(pMem: vcache);
    }
  }
  if ( startInfo.m_startFace != nullptr )
    free(pMem: startInfo.m_startFace);
  if ( tempStrips._Myfirst != nullptr )
    free(pMem: tempStrips._Myfirst);
}

//------------------------------------------------------------------------------
// Address: 0x005BB050
// Name: protected: void NvStripifier::FindAllStrips(class std::vector<class NvStripInfo __near *,class std::allocator<class NvStripInfo __near *>> __near &,class std::vector<class NvFaceInfo __near *,class std::allocator<class NvFaceInfo __near *>> __near &,class std::vector<class NvEdgeInfo __near *,class std::allocator<class NvEdgeInfo __near *>> __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NvStripifier::FindAllStrips(
        NvStripifier *this,
        NvStripInfo *allStrips,
        std::vector<NvFaceInfo *> *allFaceInfos,
        std::vector<NvEdgeInfo *> *allEdgeInfos,
        int numSamples)
{
  int v5; // edi
  int v6; // esi
  int v7; // ecx
  int *v8; // eax
  int v9; // ecx
  std::vector<NvStripInfo *> *v10; // edx
  _DWORD *j; // eax
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *v12; // eax
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *Myhead; // edi
  std::vector<NvFaceInfo *> *v14; // edx
  NvStripifier *v15; // ebx
  int v16; // esi
  bool v17; // zf
  int StartPoint; // eax
  NvFaceInfo **Myfirst; // edx
  int v20; // ecx
  NvFaceInfo *v21; // ebx
  NvStripifier *v22; // eax
  float v23; // xmm0_4
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *Parent; // eax
  NvStripInfo *v25; // ecx
  NvStripInfo **p_strip20; // eax
  NvFaceInfo **v27; // eax
  NvEdgeInfo *v28; // eax
  int m_v1; // esi
  int m_v0; // ecx
  NvEdgeInfo *v31; // esi
  NvStripInfo *v32; // eax
  int v33; // ecx
  int v34; // edx
  NvStripInfo *v35; // edi
  std::vector<int> *v36; // esi
  int *Mylast; // eax
  int *v38; // edx
  int *v39; // ecx
  int v40; // edi
  unsigned int v41; // eax
  unsigned int v42; // eax
  unsigned int v43; // ecx
  unsigned int v44; // ecx
  int *v45; // eax
  int *Myend; // ecx
  unsigned int v47; // eax
  unsigned int v48; // eax
  unsigned int v49; // ecx
  unsigned int v50; // ecx
  _DWORD *v51; // eax
  NvEdgeInfo *v52; // eax
  int v53; // esi
  int v54; // ecx
  NvEdgeInfo *v55; // esi
  NvStripInfo *v56; // eax
  int v57; // ecx
  int v58; // edx
  NvStripInfo *v59; // edi
  std::vector<int> *v60; // esi
  int *v61; // eax
  int *v62; // edx
  int *v63; // ecx
  int v64; // edi
  unsigned int v65; // eax
  unsigned int v66; // eax
  unsigned int v67; // ecx
  unsigned int v68; // ecx
  int *v69; // eax
  int *v70; // ecx
  unsigned int v71; // eax
  unsigned int v72; // eax
  unsigned int v73; // ecx
  unsigned int v74; // ecx
  _DWORD *v75; // eax
  int v76; // edx
  NvEdgeInfo *v77; // eax
  int m_v2; // esi
  int v79; // ecx
  NvEdgeInfo *v80; // esi
  NvStripInfo *v81; // eax
  int v82; // ecx
  int v83; // edx
  NvStripInfo *v84; // edi
  std::vector<int> *v85; // esi
  int *v86; // eax
  int *v87; // edx
  int *v88; // ecx
  int v89; // edi
  unsigned int v90; // eax
  unsigned int v91; // eax
  unsigned int v92; // ecx
  unsigned int v93; // ecx
  int *v94; // eax
  int *v95; // ecx
  unsigned int v96; // eax
  unsigned int v97; // eax
  unsigned int v98; // ecx
  unsigned int v99; // ecx
  _DWORD *v100; // eax
  int v101; // edx
  NvEdgeInfo *v102; // eax
  int v103; // esi
  int v104; // ecx
  NvEdgeInfo *v105; // esi
  NvStripInfo *v106; // eax
  int v107; // ecx
  int v108; // edx
  NvStripInfo *v109; // edi
  std::vector<int> *v110; // esi
  int *v111; // eax
  int *v112; // edx
  int *v113; // ecx
  int v114; // edi
  unsigned int v115; // eax
  unsigned int v116; // eax
  unsigned int v117; // ecx
  unsigned int v118; // ecx
  int *v119; // eax
  int *v120; // ecx
  unsigned int v121; // eax
  unsigned int v122; // eax
  unsigned int v123; // ecx
  unsigned int v124; // ecx
  _DWORD *v125; // eax
  int v126; // edx
  NvEdgeInfo *v127; // eax
  int v128; // esi
  int v129; // ecx
  NvEdgeInfo *v130; // esi
  NvStripInfo *v131; // eax
  int v132; // ecx
  int v133; // edx
  NvStripInfo *v134; // edi
  std::vector<int> *v135; // esi
  int *v136; // eax
  int *v137; // edx
  int *v138; // ecx
  int v139; // edi
  unsigned int v140; // eax
  unsigned int v141; // eax
  unsigned int v142; // ecx
  unsigned int v143; // ecx
  int *v144; // eax
  int *v145; // ecx
  unsigned int v146; // eax
  unsigned int v147; // eax
  unsigned int v148; // ecx
  unsigned int v149; // ecx
  _DWORD *v150; // eax
  int v151; // edx
  NvEdgeInfo *v152; // eax
  int v153; // esi
  int v154; // ecx
  NvEdgeInfo *v155; // esi
  NvStripInfo *v156; // eax
  int v157; // ecx
  int v158; // edx
  NvStripInfo *v159; // edi
  std::vector<int> *v160; // esi
  int *v161; // eax
  int *v162; // edx
  int *v163; // ecx
  int v164; // edi
  unsigned int v165; // eax
  unsigned int v166; // eax
  unsigned int v167; // ecx
  unsigned int v168; // ecx
  int *v169; // eax
  int *v170; // ecx
  unsigned int v171; // eax
  unsigned int v172; // eax
  unsigned int v173; // ecx
  unsigned int v174; // ecx
  _DWORD *v175; // eax
  std::vector<NvStripInfo *> *v176; // esi
  std::vector<NvEdgeInfo *> *v177; // edi
  NvStripInfo *v178; // eax
  NvFaceInfo *v179; // edi
  int v180; // ecx
  NvStripInfo *v181; // ebx
  NvStripInfo **v182; // eax
  NvStripInfo **v183; // edx
  NvStripInfo **v184; // ecx
  int v185; // edi
  unsigned int v186; // eax
  unsigned int v187; // eax
  unsigned int v188; // ecx
  unsigned int v189; // ecx
  NvStripInfo **v190; // eax
  NvStripInfo **v191; // ecx
  unsigned int v192; // eax
  unsigned int v193; // eax
  unsigned int v194; // ecx
  unsigned int v195; // ecx
  NvStripInfo **v196; // eax
  std::vector<NvEdgeInfo *> *v197; // eax
  int v198; // ebx
  int v199; // esi
  std::vector<NvStripInfo *> *v200; // edi
  double v201; // st6
  NvStripInfo *v202; // eax
  int v203; // ebx
  int v204; // edi
  int v205; // esi
  std::allocator<NvStripInfo *> *p_Alval; // ebx
  std::vector<NvStripInfo *> *v207; // esi
  int k; // edi
  NvStripInfo **v209; // eax
  NvStripInfo *v210; // [esp-8h] [ebp-C0h]
  std::pair<std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> > >,bool> result; // [esp+Ch] [ebp-ACh] BYREF
  std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> > > v212; // [esp+14h] [ebp-A4h] BYREF
  double bestValue; // [esp+18h] [ebp-A0h]
  unsigned __int64 v214; // [esp+20h] [ebp-98h]
  int v215; // [esp+28h] [ebp-90h]
  unsigned __int64 v216; // [esp+2Ch] [ebp-8Ch]
  int v217; // [esp+34h] [ebp-84h]
  unsigned __int64 v218; // [esp+38h] [ebp-80h]
  int v219; // [esp+40h] [ebp-78h]
  unsigned __int64 v220; // [esp+44h] [ebp-74h]
  int v221; // [esp+4Ch] [ebp-6Ch]
  unsigned __int64 v222; // [esp+50h] [ebp-68h]
  int v223; // [esp+58h] [ebp-60h]
  int v224; // [esp+5Ch] [ebp-5Ch]
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *v225; // [esp+60h] [ebp-58h] BYREF
  NvStripStartInfo startInfo; // [esp+64h] [ebp-54h] BYREF
  std::exception pExceptionObject; // [esp+70h] [ebp-48h] BYREF
  int loopCtr; // [esp+7Ch] [ebp-3Ch]
  std::set<NvFaceInfo *> resetPoints; // [esp+80h] [ebp-38h] BYREF
  float value; // [esp+90h] [ebp-28h] BYREF
  NvStripifier *v231; // [esp+94h] [ebp-24h]
  int i; // [esp+98h] [ebp-20h]
  bool done; // [esp+9Fh] [ebp-19h]
  int experimentId; // [esp+A0h] [ebp-18h]
  std::vector<NvStripInfo *> *experiments; // [esp+A4h] [ebp-14h]
  int stripId; // [esp+A8h] [ebp-10h]
  int experimentIndex; // [esp+ACh] [ebp-Ch]
  NvStripInfo *stripIter; // [esp+B0h] [ebp-8h] BYREF
  NvStripInfo *strip20; // [esp+B4h] [ebp-4h] BYREF

  v5 = numSamples;
  v6 = 6 * numSamples;
  v231 = this;
  experimentId = 0;
  stripId = 0;
  done = false;
  loopCtr = 0;
  v224 = 6 * numSamples;
  while ( 2 )
  {
    ++loopCtr;
    v7 = (unsigned __int64)(unsigned int)v6 >> 28 != 0 ? -1 : 16 * v6;
    v8 = (int *)MemAlloc_Alloc(nSize: __CFADD__(v7, 4) ? -1 : v7 + 4);
    if ( v8 != nullptr )
    {
      v9 = v6 - 1;
      v10 = (std::vector<NvStripInfo *> *)(v8 + 1);
      *v8 = v6;
      for ( j = v8 + 1; v9 >= 0; --v9 )
      {
        *j = 0;
        j[1] = 0;
        j[2] = 0;
        j += 4;
      }
      experiments = v10;
    }
    else
    {
      experiments = nullptr;
    }
    experimentIndex = 0;
    resetPoints._Mysize = 0;
    v12 = (std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *)MemAlloc_Alloc(nSize: 0x14u);
    if ( v12 == nullptr )
    {
      allEdgeInfos = nullptr;
      std::exception::exception(this: &pExceptionObject, _What: (const char *const *)&allEdgeInfos);
      pExceptionObject.__vftable = (std::exception_vtbl *)&std::bad_alloc::`vftable';
      _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI2_AVbad_alloc_std__);
    }
    resetPoints._Myhead = v12;
    v12->_Left = v12;
    resetPoints._Myhead->_Parent = resetPoints._Myhead;
    resetPoints._Myhead->_Right = resetPoints._Myhead;
    resetPoints._Myhead->_Color = 1;
    resetPoints._Myhead->_Isnil = 1;
    i = 0;
    if ( v5 <= 0 )
      goto LABEL_256;
    Myhead = resetPoints._Myhead;
    do
    {
      v14 = allFaceInfos;
      v15 = v231;
      v16 = allFaceInfos->_Mylast - allFaceInfos->_Myfirst;
      v17 = !v231->bFirstTimeResetPoint;
      stripIter = nullptr;
      if ( v17 )
      {
        StartPoint = (int)(float)((float)((float)v16 - 1.0) * v231->meshJump);
      }
      else
      {
        StartPoint = NvStripifier::FindStartPoint(this: v231, faceInfos: allFaceInfos, edgeInfos: allEdgeInfos);
        v14 = allFaceInfos;
        v15->bFirstTimeResetPoint = false;
      }
      if ( StartPoint == -1 )
        StartPoint = (int)(float)((float)((float)v16 - 1.0) * v15->meshJump);
      Myfirst = v14->_Myfirst;
      v20 = StartPoint;
      while ( 1 )
      {
        v21 = Myfirst[v20];
        if ( v21->m_stripId < 0 )
          break;
        if ( ++v20 >= v16 )
          v20 = 0;
        if ( v20 == StartPoint )
        {
          v21 = (NvFaceInfo *)stripIter;
          goto LABEL_22;
        }
      }
      stripIter = (NvStripInfo *)Myfirst[v20];
LABEL_22:
      v22 = v231;
      v23 = v231->meshJump + 0.1;
      v231->meshJump = v23;
      if ( v23 > 1.0 )
        v22->meshJump = 0.050000001;
      value = *(float *)&v21;
      if ( v21 == nullptr )
      {
        done = true;
        break;
      }
      Parent = Myhead->_Parent;
      v25 = (NvStripInfo *)Myhead;
      while ( Parent->_Isnil == 0 )
      {
        if ( Parent->_Myval >= v21 )
        {
          v25 = (NvStripInfo *)Parent;
          Parent = Parent->_Left;
        }
        else
        {
          Parent = Parent->_Right;
        }
      }
      strip20 = v25;
      if ( v25 == (NvStripInfo *)Myhead || (NvFaceInfo **)v21 < v25->m_faces._Myfirst )
      {
        v225 = Myhead;
        p_strip20 = (NvStripInfo **)&v225;
      }
      else
      {
        p_strip20 = &strip20;
      }
      if ( *p_strip20 != (NvStripInfo *)Myhead )
        goto LABEL_253;
      v27 = std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0>>::_Buynode<NvFaceInfo * &>(
              this: &resetPoints,
              _Val: (NvFaceInfo **)&value);
      std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0>>::_Linsert(
        this: &resetPoints,
        &result,
        _Node: (std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *)v27,
        _Leftish: 0);
      v28 = allEdgeInfos->_Myfirst[v21->m_v0];
      m_v1 = v21->m_v1;
      if ( v28 == nullptr )
      {
LABEL_43:
        v31 = nullptr;
        goto LABEL_44;
      }
      while ( 1 )
      {
        m_v0 = v28->m_v0;
        if ( m_v0 != v21->m_v0 )
          break;
        if ( v28->m_v1 == m_v1 )
          goto LABEL_46;
        v28 = v28->m_nextV0;
LABEL_42:
        if ( v28 == nullptr )
          goto LABEL_43;
      }
      if ( m_v0 != m_v1 )
      {
        v28 = v28->m_nextV1;
        goto LABEL_42;
      }
LABEL_46:
      v31 = v28;
LABEL_44:
      v32 = (NvStripInfo *)MemAlloc_Alloc(nSize: 0x2Cu);
      if ( v32 != nullptr )
      {
        v33 = stripId;
        v218 = __PAIR64__((unsigned int)v31, (unsigned int)v21);
        *(_QWORD *)&v32->m_startInfo.m_startFace = __PAIR64__((unsigned int)v31, (unsigned int)v21);
        LOBYTE(v219) = 1;
        *(_DWORD *)&v32->m_startInfo.m_toV1 = v219;
        v34 = experimentId;
        v32->m_faces._Myfirst = nullptr;
        v32->m_faces._Mylast = nullptr;
        v32->m_faces._Myend = nullptr;
        v32->m_stripId = v33;
        v32->m_experimentId = v34;
        v32->visited = false;
        v32->m_numDegenerates = 0;
        v35 = v32;
        stripId = v33 + 1;
        experimentId = v34 + 1;
      }
      else
      {
        v35 = nullptr;
      }
      v36 = (std::vector<int> *)&experiments[experimentIndex++];
      Mylast = v36->_Mylast;
      strip20 = v35;
      if ( &strip20 >= (NvStripInfo **)Mylast || (v38 = v36->_Myfirst, v36->_Myfirst > (int *)&strip20) )
      {
        Myend = v36->_Myend;
        if ( Mylast == Myend )
        {
          v47 = Mylast - v36->_Myfirst;
          if ( v47 > 0x3FFFFFFE )
            goto LABEL_314;
          v48 = v47 + 1;
          v49 = Myend - v36->_Myfirst;
          if ( v48 > v49 )
          {
            if ( 0x3FFFFFFF - (v49 >> 1) >= v49 )
              v50 = (v49 >> 1) + v49;
            else
              v50 = 0;
            if ( v50 < v48 )
              v50 = v48;
            std::vector<int>::reserve(this: v36, _Count: v50);
            v21 = (NvFaceInfo *)stripIter;
          }
        }
        v51 = v36->_Mylast;
        if ( v51 != nullptr )
          *v51 = v35;
        goto LABEL_72;
      }
      v39 = v36->_Myend;
      v40 = ((char *)&strip20 - (char *)v38) >> 2;
      if ( Mylast != v39 )
        goto LABEL_59;
      v41 = Mylast - v38;
      if ( v41 > 0x3FFFFFFE )
        goto LABEL_314;
      v42 = v41 + 1;
      v43 = v39 - v38;
      if ( v42 > v43 )
      {
        if ( 0x3FFFFFFF - (v43 >> 1) >= v43 )
          v44 = (v43 >> 1) + v43;
        else
          v44 = 0;
        if ( v44 < v42 )
          v44 = v42;
        std::vector<int>::reserve(this: v36, _Count: v44);
        v21 = (NvFaceInfo *)stripIter;
      }
LABEL_59:
      v45 = v36->_Mylast;
      if ( v45 != nullptr )
        *v45 = v36->_Myfirst[v40];
LABEL_72:
      ++v36->_Mylast;
      v52 = allEdgeInfos->_Myfirst[v21->m_v0];
      v53 = v21->m_v1;
      if ( v52 == nullptr )
      {
LABEL_79:
        v55 = nullptr;
        goto LABEL_80;
      }
      while ( 2 )
      {
        v54 = v52->m_v0;
        if ( v54 == v21->m_v0 )
        {
          if ( v52->m_v1 == v53 )
            break;
          v52 = v52->m_nextV0;
          goto LABEL_78;
        }
        if ( v54 != v53 )
        {
          v52 = v52->m_nextV1;
LABEL_78:
          if ( v52 == nullptr )
            goto LABEL_79;
          continue;
        }
        break;
      }
      v55 = v52;
LABEL_80:
      v56 = (NvStripInfo *)MemAlloc_Alloc(nSize: 0x2Cu);
      if ( v56 != nullptr )
      {
        v57 = stripId;
        v214 = __PAIR64__((unsigned int)v55, (unsigned int)v21);
        *(_QWORD *)&v56->m_startInfo.m_startFace = __PAIR64__((unsigned int)v55, (unsigned int)v21);
        LOBYTE(v215) = 0;
        *(_DWORD *)&v56->m_startInfo.m_toV1 = v215;
        v58 = experimentId;
        v56->m_faces._Myfirst = nullptr;
        v56->m_faces._Mylast = nullptr;
        v56->m_faces._Myend = nullptr;
        v56->m_stripId = v57;
        v56->m_experimentId = v58;
        v56->visited = false;
        v56->m_numDegenerates = 0;
        v59 = v56;
        stripId = v57 + 1;
        experimentId = v58 + 1;
      }
      else
      {
        v59 = nullptr;
      }
      v60 = (std::vector<int> *)&experiments[experimentIndex++];
      v61 = v60->_Mylast;
      strip20 = v59;
      if ( &strip20 >= (NvStripInfo **)v61 || (v62 = v60->_Myfirst, v60->_Myfirst > (int *)&strip20) )
      {
        v70 = v60->_Myend;
        if ( v61 != v70 )
        {
LABEL_106:
          v75 = v60->_Mylast;
          if ( v75 != nullptr )
            *v75 = v59;
          goto LABEL_108;
        }
        v71 = v61 - v60->_Myfirst;
        if ( v71 <= 0x3FFFFFFE )
        {
          v72 = v71 + 1;
          v73 = v70 - v60->_Myfirst;
          if ( v72 > v73 )
          {
            if ( 0x3FFFFFFF - (v73 >> 1) >= v73 )
              v74 = (v73 >> 1) + v73;
            else
              v74 = 0;
            if ( v74 < v72 )
              v74 = v72;
            std::vector<int>::reserve(this: v60, _Count: v74);
            v21 = (NvFaceInfo *)stripIter;
          }
          goto LABEL_106;
        }
        goto LABEL_314;
      }
      v63 = v60->_Myend;
      v64 = ((char *)&strip20 - (char *)v62) >> 2;
      if ( v61 != v63 )
        goto LABEL_95;
      v65 = v61 - v62;
      if ( v65 > 0x3FFFFFFE )
        goto LABEL_314;
      v66 = v65 + 1;
      v67 = v63 - v62;
      if ( v66 > v67 )
      {
        if ( 0x3FFFFFFF - (v67 >> 1) >= v67 )
          v68 = (v67 >> 1) + v67;
        else
          v68 = 0;
        if ( v68 < v66 )
          v68 = v66;
        std::vector<int>::reserve(this: v60, _Count: v68);
        v21 = (NvFaceInfo *)stripIter;
      }
LABEL_95:
      v69 = v60->_Mylast;
      if ( v69 != nullptr )
        *v69 = v60->_Myfirst[v64];
LABEL_108:
      ++v60->_Mylast;
      v76 = v21->m_v1;
      v77 = allEdgeInfos->_Myfirst[v76];
      m_v2 = v21->m_v2;
      if ( v77 == nullptr )
      {
LABEL_115:
        v80 = nullptr;
        goto LABEL_116;
      }
      while ( 2 )
      {
        v79 = v77->m_v0;
        if ( v79 == v76 )
        {
          if ( v77->m_v1 == m_v2 )
            break;
          v77 = v77->m_nextV0;
          goto LABEL_114;
        }
        if ( v79 != m_v2 )
        {
          v77 = v77->m_nextV1;
LABEL_114:
          if ( v77 == nullptr )
            goto LABEL_115;
          continue;
        }
        break;
      }
      v80 = v77;
LABEL_116:
      v81 = (NvStripInfo *)MemAlloc_Alloc(nSize: 0x2Cu);
      if ( v81 != nullptr )
      {
        v82 = stripId;
        v222 = __PAIR64__((unsigned int)v80, (unsigned int)v21);
        *(_QWORD *)&v81->m_startInfo.m_startFace = __PAIR64__((unsigned int)v80, (unsigned int)v21);
        LOBYTE(v223) = 1;
        *(_DWORD *)&v81->m_startInfo.m_toV1 = v223;
        v83 = experimentId;
        v81->m_faces._Myfirst = nullptr;
        v81->m_faces._Mylast = nullptr;
        v81->m_faces._Myend = nullptr;
        v81->m_stripId = v82;
        v81->m_experimentId = v83;
        v81->visited = false;
        v81->m_numDegenerates = 0;
        v84 = v81;
        stripId = v82 + 1;
        experimentId = v83 + 1;
      }
      else
      {
        v84 = nullptr;
      }
      v85 = (std::vector<int> *)&experiments[experimentIndex++];
      v86 = v85->_Mylast;
      strip20 = v84;
      if ( &strip20 >= (NvStripInfo **)v86 || (v87 = v85->_Myfirst, v85->_Myfirst > (int *)&strip20) )
      {
        v95 = v85->_Myend;
        if ( v86 == v95 )
        {
          v96 = v86 - v85->_Myfirst;
          if ( v96 > 0x3FFFFFFE )
            goto LABEL_314;
          v97 = v96 + 1;
          v98 = v95 - v85->_Myfirst;
          if ( v97 > v98 )
          {
            if ( 0x3FFFFFFF - (v98 >> 1) >= v98 )
              v99 = (v98 >> 1) + v98;
            else
              v99 = 0;
            if ( v99 < v97 )
              v99 = v97;
            std::vector<int>::reserve(this: v85, _Count: v99);
            v21 = (NvFaceInfo *)stripIter;
          }
        }
        v100 = v85->_Mylast;
        if ( v100 != nullptr )
          *v100 = v84;
        goto LABEL_144;
      }
      v88 = v85->_Myend;
      v89 = ((char *)&strip20 - (char *)v87) >> 2;
      if ( v86 != v88 )
        goto LABEL_131;
      v90 = v86 - v87;
      if ( v90 > 0x3FFFFFFE )
        goto LABEL_314;
      v91 = v90 + 1;
      v92 = v88 - v87;
      if ( v91 > v92 )
      {
        if ( 0x3FFFFFFF - (v92 >> 1) >= v92 )
          v93 = (v92 >> 1) + v92;
        else
          v93 = 0;
        if ( v93 < v91 )
          v93 = v91;
        std::vector<int>::reserve(this: v85, _Count: v93);
        v21 = (NvFaceInfo *)stripIter;
      }
LABEL_131:
      v94 = v85->_Mylast;
      if ( v94 != nullptr )
        *v94 = v85->_Myfirst[v89];
LABEL_144:
      ++v85->_Mylast;
      v101 = v21->m_v1;
      v102 = allEdgeInfos->_Myfirst[v101];
      v103 = v21->m_v2;
      if ( v102 == nullptr )
      {
LABEL_151:
        v105 = nullptr;
        goto LABEL_152;
      }
      while ( 2 )
      {
        v104 = v102->m_v0;
        if ( v104 == v101 )
        {
          if ( v102->m_v1 == v103 )
            break;
          v102 = v102->m_nextV0;
          goto LABEL_150;
        }
        if ( v104 != v103 )
        {
          v102 = v102->m_nextV1;
LABEL_150:
          if ( v102 == nullptr )
            goto LABEL_151;
          continue;
        }
        break;
      }
      v105 = v102;
LABEL_152:
      v106 = (NvStripInfo *)MemAlloc_Alloc(nSize: 0x2Cu);
      if ( v106 != nullptr )
      {
        v107 = stripId;
        v220 = __PAIR64__((unsigned int)v105, (unsigned int)v21);
        *(_QWORD *)&v106->m_startInfo.m_startFace = __PAIR64__((unsigned int)v105, (unsigned int)v21);
        LOBYTE(v221) = 0;
        *(_DWORD *)&v106->m_startInfo.m_toV1 = v221;
        v108 = experimentId;
        v106->m_faces._Myfirst = nullptr;
        v106->m_faces._Mylast = nullptr;
        v106->m_faces._Myend = nullptr;
        v106->m_stripId = v107;
        v106->m_experimentId = v108;
        v106->visited = false;
        v106->m_numDegenerates = 0;
        v109 = v106;
        stripId = v107 + 1;
        experimentId = v108 + 1;
      }
      else
      {
        v109 = nullptr;
      }
      v110 = (std::vector<int> *)&experiments[experimentIndex++];
      v111 = v110->_Mylast;
      strip20 = v109;
      if ( &strip20 >= (NvStripInfo **)v111 || (v112 = v110->_Myfirst, v110->_Myfirst > (int *)&strip20) )
      {
        v120 = v110->_Myend;
        if ( v111 != v120 )
        {
LABEL_178:
          v125 = v110->_Mylast;
          if ( v125 != nullptr )
            *v125 = v109;
          goto LABEL_180;
        }
        v121 = v111 - v110->_Myfirst;
        if ( v121 <= 0x3FFFFFFE )
        {
          v122 = v121 + 1;
          v123 = v120 - v110->_Myfirst;
          if ( v122 > v123 )
          {
            if ( 0x3FFFFFFF - (v123 >> 1) >= v123 )
              v124 = (v123 >> 1) + v123;
            else
              v124 = 0;
            if ( v124 < v122 )
              v124 = v122;
            std::vector<int>::reserve(this: v110, _Count: v124);
            v21 = (NvFaceInfo *)stripIter;
          }
          goto LABEL_178;
        }
        goto LABEL_314;
      }
      v113 = v110->_Myend;
      v114 = ((char *)&strip20 - (char *)v112) >> 2;
      if ( v111 != v113 )
        goto LABEL_167;
      v115 = v111 - v112;
      if ( v115 > 0x3FFFFFFE )
        goto LABEL_314;
      v116 = v115 + 1;
      v117 = v113 - v112;
      if ( v116 > v117 )
      {
        if ( 0x3FFFFFFF - (v117 >> 1) >= v117 )
          v118 = (v117 >> 1) + v117;
        else
          v118 = 0;
        if ( v118 < v116 )
          v118 = v116;
        std::vector<int>::reserve(this: v110, _Count: v118);
        v21 = (NvFaceInfo *)stripIter;
      }
LABEL_167:
      v119 = v110->_Mylast;
      if ( v119 != nullptr )
        *v119 = v110->_Myfirst[v114];
LABEL_180:
      ++v110->_Mylast;
      v126 = v21->m_v2;
      v127 = allEdgeInfos->_Myfirst[v126];
      v128 = v21->m_v0;
      if ( v127 == nullptr )
      {
LABEL_187:
        v130 = nullptr;
        goto LABEL_188;
      }
      while ( 2 )
      {
        v129 = v127->m_v0;
        if ( v129 == v126 )
        {
          if ( v127->m_v1 == v128 )
            break;
          v127 = v127->m_nextV0;
          goto LABEL_186;
        }
        if ( v129 != v128 )
        {
          v127 = v127->m_nextV1;
LABEL_186:
          if ( v127 == nullptr )
            goto LABEL_187;
          continue;
        }
        break;
      }
      v130 = v127;
LABEL_188:
      v131 = (NvStripInfo *)MemAlloc_Alloc(nSize: 0x2Cu);
      if ( v131 != nullptr )
      {
        v132 = stripId;
        v216 = __PAIR64__((unsigned int)v130, (unsigned int)v21);
        *(_QWORD *)&v131->m_startInfo.m_startFace = __PAIR64__((unsigned int)v130, (unsigned int)v21);
        LOBYTE(v217) = 1;
        *(_DWORD *)&v131->m_startInfo.m_toV1 = v217;
        v133 = experimentId;
        v131->m_faces._Myfirst = nullptr;
        v131->m_faces._Mylast = nullptr;
        v131->m_faces._Myend = nullptr;
        v131->m_stripId = v132;
        v131->m_experimentId = v133;
        v131->visited = false;
        v131->m_numDegenerates = 0;
        v134 = v131;
        stripId = v132 + 1;
        experimentId = v133 + 1;
      }
      else
      {
        v134 = nullptr;
      }
      v135 = (std::vector<int> *)&experiments[experimentIndex++];
      v136 = v135->_Mylast;
      strip20 = v134;
      if ( &strip20 >= (NvStripInfo **)v136 || (v137 = v135->_Myfirst, v135->_Myfirst > (int *)&strip20) )
      {
        v145 = v135->_Myend;
        if ( v136 == v145 )
        {
          v146 = v136 - v135->_Myfirst;
          if ( v146 > 0x3FFFFFFE )
            goto LABEL_314;
          v147 = v146 + 1;
          v148 = v145 - v135->_Myfirst;
          if ( v147 > v148 )
          {
            if ( 0x3FFFFFFF - (v148 >> 1) >= v148 )
              v149 = (v148 >> 1) + v148;
            else
              v149 = 0;
            if ( v149 < v147 )
              v149 = v147;
            std::vector<int>::reserve(this: v135, _Count: v149);
            v21 = (NvFaceInfo *)stripIter;
          }
        }
        v150 = v135->_Mylast;
        if ( v150 != nullptr )
          *v150 = v134;
        goto LABEL_216;
      }
      v138 = v135->_Myend;
      v139 = ((char *)&strip20 - (char *)v137) >> 2;
      if ( v136 != v138 )
        goto LABEL_203;
      v140 = v136 - v137;
      if ( v140 > 0x3FFFFFFE )
        goto LABEL_314;
      v141 = v140 + 1;
      v142 = v138 - v137;
      if ( v141 > v142 )
      {
        if ( 0x3FFFFFFF - (v142 >> 1) >= v142 )
          v143 = (v142 >> 1) + v142;
        else
          v143 = 0;
        if ( v143 < v141 )
          v143 = v141;
        std::vector<int>::reserve(this: v135, _Count: v143);
        v21 = (NvFaceInfo *)stripIter;
      }
LABEL_203:
      v144 = v135->_Mylast;
      if ( v144 != nullptr )
        *v144 = v135->_Myfirst[v139];
LABEL_216:
      ++v135->_Mylast;
      v151 = v21->m_v2;
      v152 = allEdgeInfos->_Myfirst[v151];
      v153 = v21->m_v0;
      if ( v152 == nullptr )
      {
LABEL_223:
        v155 = nullptr;
        goto LABEL_224;
      }
      while ( 2 )
      {
        v154 = v152->m_v0;
        if ( v154 == v151 )
        {
          if ( v152->m_v1 == v153 )
            break;
          v152 = v152->m_nextV0;
          goto LABEL_222;
        }
        if ( v154 != v153 )
        {
          v152 = v152->m_nextV1;
LABEL_222:
          if ( v152 == nullptr )
            goto LABEL_223;
          continue;
        }
        break;
      }
      v155 = v152;
LABEL_224:
      v156 = (NvStripInfo *)MemAlloc_Alloc(nSize: 0x2Cu);
      if ( v156 != nullptr )
      {
        v157 = stripId;
        *(_QWORD *)&pExceptionObject.__vftable = __PAIR64__((unsigned int)v155, (unsigned int)v21);
        *(_QWORD *)&v156->m_startInfo.m_startFace = __PAIR64__((unsigned int)v155, (unsigned int)v21);
        pExceptionObject._Mydofree = false;
        *(_DWORD *)&v156->m_startInfo.m_toV1 = *(_DWORD *)&pExceptionObject._Mydofree;
        v158 = experimentId;
        v156->m_faces._Myfirst = nullptr;
        v156->m_faces._Mylast = nullptr;
        v156->m_faces._Myend = nullptr;
        v156->m_stripId = v157;
        v156->m_experimentId = v158;
        v156->visited = false;
        v156->m_numDegenerates = 0;
        v159 = v156;
        stripId = v157 + 1;
        experimentId = v158 + 1;
      }
      else
      {
        v159 = nullptr;
      }
      v160 = (std::vector<int> *)&experiments[experimentIndex++];
      v161 = v160->_Mylast;
      strip20 = v159;
      if ( &strip20 >= (NvStripInfo **)v161 || (v162 = v160->_Myfirst, v160->_Myfirst > (int *)&strip20) )
      {
        v170 = v160->_Myend;
        if ( v161 != v170 )
        {
LABEL_250:
          v175 = v160->_Mylast;
          if ( v175 != nullptr )
            *v175 = v159;
          goto LABEL_252;
        }
        v171 = v161 - v160->_Myfirst;
        if ( v171 <= 0x3FFFFFFE )
        {
          v172 = v171 + 1;
          v173 = v170 - v160->_Myfirst;
          if ( v172 > v173 )
          {
            if ( 0x3FFFFFFF - (v173 >> 1) >= v173 )
              v174 = (v173 >> 1) + v173;
            else
              v174 = 0;
            if ( v174 < v172 )
              v174 = v172;
            std::vector<int>::reserve(this: v160, _Count: v174);
          }
          goto LABEL_250;
        }
LABEL_314:
        std::_Xlength_error(_Message: "vector<T> too long");
      }
      v163 = v160->_Myend;
      v164 = ((char *)&strip20 - (char *)v162) >> 2;
      if ( v161 != v163 )
        goto LABEL_239;
      v165 = v161 - v162;
      if ( v165 > 0x3FFFFFFE )
        goto LABEL_314;
      v166 = v165 + 1;
      v167 = v163 - v162;
      if ( v166 > v167 )
      {
        if ( 0x3FFFFFFF - (v167 >> 1) >= v167 )
          v168 = (v167 >> 1) + v167;
        else
          v168 = 0;
        if ( v168 < v166 )
          v168 = v166;
        std::vector<int>::reserve(this: v160, _Count: v168);
      }
LABEL_239:
      v169 = v160->_Mylast;
      if ( v169 != nullptr )
        *v169 = v160->_Myfirst[v164];
LABEL_252:
      ++v160->_Mylast;
      Myhead = resetPoints._Myhead;
LABEL_253:
      ++i;
    }
    while ( i < numSamples );
LABEL_256:
    i = 0;
    if ( experimentIndex > 0 )
    {
      v176 = experiments;
      do
      {
        v177 = allEdgeInfos;
        NvStripInfo::Build(this: *v176->_Myfirst, edgeInfos: allEdgeInfos, faceInfos: allFaceInfos);
        v210 = *v176->_Myfirst;
        value = *(float *)&v210->m_experimentId;
        memset(&startInfo, 0, 9);
        if ( NvStripifier::FindTraversal(this: v231, faceInfos: allFaceInfos, edgeInfos: v177, strip: v210, &startInfo) )
        {
          do
          {
            v178 = (NvStripInfo *)MemAlloc_Alloc(nSize: 0x2Cu);
            if ( v178 != nullptr )
            {
              v179 = (NvFaceInfo *)LODWORD(value);
              v178->m_startInfo = startInfo;
              v180 = stripId;
              v178->m_faces._Myfirst = nullptr;
              v178->m_faces._Mylast = nullptr;
              v178->m_faces._Myend = nullptr;
              v178->m_stripId = v180;
              v178->m_experimentId = (int)v179;
              v178->visited = false;
              v178->m_numDegenerates = 0;
              v181 = v178;
              stripId = v180 + 1;
            }
            else
            {
              v181 = nullptr;
            }
            stripIter = v181;
            NvStripInfo::Build(this: v181, edgeInfos: allEdgeInfos, faceInfos: allFaceInfos);
            v182 = v176->_Mylast;
            if ( &stripIter >= v182 || (v183 = v176->_Myfirst, v176->_Myfirst > &stripIter) )
            {
              v191 = v176->_Myend;
              if ( v182 == v191 )
              {
                v192 = v182 - v176->_Myfirst;
                if ( v192 > 0x3FFFFFFE )
                  goto LABEL_314;
                v193 = v192 + 1;
                v194 = v191 - v176->_Myfirst;
                if ( v193 > v194 )
                {
                  if ( 0x3FFFFFFF - (v194 >> 1) >= v194 )
                    v195 = (v194 >> 1) + v194;
                  else
                    v195 = 0;
                  if ( v195 < v193 )
                    v195 = v193;
                  std::vector<int>::reserve(this: (std::vector<int> *)v176, _Count: v195);
                }
              }
              v196 = v176->_Mylast;
              if ( v196 != nullptr )
                *v196 = v181;
            }
            else
            {
              v184 = v176->_Myend;
              v185 = &stripIter - v183;
              if ( v182 == v184 )
              {
                v186 = v182 - v183;
                if ( v186 > 0x3FFFFFFE )
                  goto LABEL_314;
                v187 = v186 + 1;
                v188 = v184 - v183;
                if ( v187 > v188 )
                {
                  if ( 0x3FFFFFFF - (v188 >> 1) >= v188 )
                    v189 = (v188 >> 1) + v188;
                  else
                    v189 = 0;
                  if ( v189 < v187 )
                    v189 = v187;
                  std::vector<int>::reserve(this: (std::vector<int> *)v176, _Count: v189);
                  v181 = stripIter;
                }
              }
              v190 = v176->_Mylast;
              if ( v190 != nullptr )
                *v190 = v176->_Myfirst[v185];
            }
            v197 = allEdgeInfos;
            ++v176->_Mylast;
          }
          while ( NvStripifier::FindTraversal(
                    this: v231,
                    faceInfos: allFaceInfos,
                    edgeInfos: v197,
                    strip: v181,
                    &startInfo) );
        }
        ++v176;
        ++i;
      }
      while ( i < experimentIndex );
    }
    v198 = 0;
    v199 = 0;
    i = 0;
    bestValue = 0.0;
    if ( experimentIndex > 0 )
    {
      v200 = experiments;
      do
      {
        v201 = NvStripifier::AvgStripSize(this: v231, strips: v200)
             + (double)(unsigned int)(v200->_Mylast - v200->_Myfirst) * 0.0;
        value = v201;
        if ( v201 > bestValue )
        {
          bestValue = value;
          v198 = v199;
        }
        ++v199;
        ++v200;
      }
      while ( v199 < experimentIndex );
      i = v198;
    }
    NvStripifier::CommitStrips(this: v231, allStrips, strips: &experiments[v198]);
    stripIter = nullptr;
    if ( experimentIndex > 0 )
    {
      strip20 = (NvStripInfo *)experiments;
      do
      {
        if ( stripIter != (NvStripInfo *)i )
        {
          v202 = strip20;
          v203 = 0;
          v204 = ((char *)strip20->m_startInfo.m_startEdge - (char *)strip20->m_startInfo.m_startFace) >> 2;
          if ( v204 > 0 )
          {
            while ( 1 )
            {
              v205 = *(&v202->m_startInfo.m_startFace->m_v0 + v203);
              if ( v205 != 0 )
              {
                if ( *(_DWORD *)(v205 + 12) != 0 )
                  free(pMem: *(void **)(v205 + 12));
                *(_DWORD *)(v205 + 12) = 0;
                *(_DWORD *)(v205 + 16) = 0;
                *(_DWORD *)(v205 + 20) = 0;
                free(pMem: (void *)v205);
              }
              if ( ++v203 >= v204 )
                break;
              v202 = strip20;
            }
          }
        }
        strip20 = (NvStripInfo *)((char *)strip20 + 16);
        stripIter = (NvStripInfo *)((char *)stripIter + 1);
      }
      while ( (int)stripIter < experimentIndex );
    }
    if ( experiments != nullptr )
    {
      p_Alval = &experiments[-1]._Alval;
      v207 = &experiments[*(_DWORD *)&experiments[-1]._Alval.std::_Allocator_base<NvStripInfo *>];
      for ( k = *(_DWORD *)&experiments[-1]._Alval.std::_Allocator_base<NvStripInfo *> - 1; k >= 0; v207->_Myend = nullptr )
      {
        v209 = v207[-1]._Myfirst;
        --v207;
        if ( v209 != nullptr )
          free(pMem: v209);
        --k;
        v207->_Myfirst = nullptr;
        v207->_Mylast = nullptr;
      }
      free(pMem: p_Alval);
    }
    std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0>>::erase(
      this: &resetPoints,
      result: &v212,
      _First: (std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> > >)resetPoints._Myhead->_Left,
      _Last: (std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> > >)resetPoints._Myhead);
    free(pMem: resetPoints._Myhead);
    if ( !done )
    {
      v6 = v224;
      v5 = numSamples;
      continue;
    }
    break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005BBDF0
// Name: public: void NvStripifier::Stripify(class std::vector<unsigned short,class std::allocator<unsigned short>> const __near &,int,int,unsigned short,class std::vector<class NvStripInfo __near *,class std::allocator<class NvStripInfo __near *>> __near &,class std::vector<class NvFaceInfo __near *,class std::allocator<class NvFaceInfo __near *>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NvStripifier::Stripify(
        NvStripifier *this,
        const std::vector<unsigned short> *in_indices,
        int in_cacheSize,
        int in_minStripLength,
        unsigned __int16 maxIndex,
        std::vector<NvStripInfo *> *outStrips,
        std::vector<NvFaceInfo *> *outFaceList)
{
  int v8; // eax
  unsigned int v9; // ebx
  unsigned int v10; // edi
  NvStripInfo *v11; // esi
  NvEdgeInfo **Myfirst; // esi
  unsigned int v13; // ebx
  unsigned int i; // edi
  NvEdgeInfo *v15; // eax
  NvEdgeInfo *m_nextV0; // esi
  std::vector<NvFaceInfo *> allFaceInfos; // [esp+0h] [ebp-30h] BYREF
  std::vector<NvStripInfo *> allStrips; // [esp+10h] [ebp-20h] BYREF
  std::vector<NvEdgeInfo *> allEdgeInfos; // [esp+20h] [ebp-10h] BYREF

  v8 = in_cacheSize - 6;
  this->meshJump = 0.0;
  this->bFirstTimeResetPoint = true;
  if ( in_cacheSize - 6 < 1 )
    v8 = 1;
  this->cacheSize = v8;
  this->minStripLength = in_minStripLength;
  std::vector<unsigned short>::operator=(this: &this->indices, _Right: in_indices);
  v9 = 0;
  memset(&allFaceInfos, 0, 12);
  memset(&allEdgeInfos, 0, 12);
  NvStripifier::BuildStripifyInfo(this, faceInfos: &allFaceInfos, edgeInfos: &allEdgeInfos, maxIndex);
  memset(&allStrips, 0, 12);
  NvStripifier::FindAllStrips(this, (NvStripInfo *)&allStrips, &allFaceInfos, &allEdgeInfos, numSamples: 10);
  NvStripifier::SplitUpStripsAndOptimize(this, &allStrips, outStrips, edgeInfos: &allEdgeInfos, outFaceList);
  v10 = allStrips._Mylast - allStrips._Myfirst;
  if ( v10 != 0 )
  {
    do
    {
      v11 = allStrips._Myfirst[v9];
      if ( v11 != nullptr )
      {
        if ( v11->m_faces._Myfirst != nullptr )
          free(pMem: v11->m_faces._Myfirst);
        v11->m_faces._Myfirst = nullptr;
        v11->m_faces._Mylast = nullptr;
        v11->m_faces._Myend = nullptr;
        free(pMem: v11);
      }
      ++v9;
    }
    while ( v9 < v10 );
  }
  Myfirst = allEdgeInfos._Myfirst;
  v13 = allEdgeInfos._Mylast - allEdgeInfos._Myfirst;
  for ( i = 0; i < v13; ++i )
  {
    v15 = Myfirst[i];
    if ( v15 != nullptr )
    {
      do
      {
        if ( v15->m_v0 == i )
          m_nextV0 = v15->m_nextV0;
        else
          m_nextV0 = v15->m_nextV1;
        if ( v15->m_refCount-- == 1 )
          free(pMem: v15);
        v15 = m_nextV0;
      }
      while ( m_nextV0 != nullptr );
      Myfirst = allEdgeInfos._Myfirst;
    }
  }
  if ( allStrips._Myfirst != nullptr )
    free(pMem: allStrips._Myfirst);
  if ( Myfirst != nullptr )
    free(pMem: Myfirst);
  if ( allFaceInfos._Myfirst != nullptr )
    free(pMem: allFaceInfos._Myfirst);
}

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x005AF000
// Name: public: bool NvStripInfo::IsInStrip(class NvFaceInfo const __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall NvStripInfo::IsInStrip(NvStripInfo *this, const NvFaceInfo *faceInfo)
{
  int m_stripId; // edx

  if ( faceInfo == nullptr )
    return false;
  if ( this->m_experimentId < 0 )
    m_stripId = faceInfo->m_stripId;
  else
    m_stripId = faceInfo->m_testStripId;
  return m_stripId == this->m_stripId;
}

//------------------------------------------------------------------------------
// Address: 0x005AF040
// Name: public: static void NvStripifier::GetSharedVertices(class NvFaceInfo __near *,class NvFaceInfo __near *,int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NvStripifier::GetSharedVertices(NvFaceInfo *faceA, NvFaceInfo *faceB, int *vertex0, int *vertex1)
{
  int m_v0; // ecx

  *vertex0 = -1;
  *vertex1 = -1;
  m_v0 = faceB->m_v0;
  if ( faceB->m_v0 == faceA->m_v0 || m_v0 == faceA->m_v1 || m_v0 == faceA->m_v2 )
  {
    if ( *vertex0 != -1 )
      goto LABEL_16;
    *vertex0 = m_v0;
  }
  m_v0 = faceB->m_v1;
  if ( m_v0 == faceA->m_v0 || m_v0 == faceA->m_v1 || m_v0 == faceA->m_v2 )
  {
    if ( *vertex0 == -1 )
    {
      *vertex0 = m_v0;
      goto LABEL_11;
    }
LABEL_16:
    *vertex1 = m_v0;
    return;
  }
LABEL_11:
  m_v0 = faceB->m_v2;
  if ( m_v0 == faceA->m_v0 || m_v0 == faceA->m_v1 || m_v0 == faceA->m_v2 )
  {
    if ( *vertex0 == -1 )
    {
      *vertex0 = m_v0;
      return;
    }
    goto LABEL_16;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005AF0B0
// Name: public: static bool NvStripifier::IsDegenerate(class NvFaceInfo const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl NvStripifier::IsDegenerate(const NvFaceInfo *face)
{
  int m_v1; // edx
  bool result; // al
  int m_v2; // eax

  m_v1 = face->m_v1;
  result = face->m_v0 == m_v1 || (m_v2 = face->m_v2, face->m_v0 == m_v2) || m_v1 == m_v2;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AF0E0
// Name: protected: void NvStripifier::UpdateCacheFace(class VertexCache __near *,class NvFaceInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NvStripifier::UpdateCacheFace(NvStripifier *this, VertexCache *vcache, NvFaceInfo *face)
{
  int numEntries; // edx
  int v4; // ecx
  int *entries; // esi
  int m_v0; // esi
  int i; // ecx
  int v8; // edi
  int *v9; // edx
  int v10; // esi
  int v11; // ecx
  int *v12; // edx
  int v13; // ecx
  int j; // esi
  int v15; // edi
  int *v16; // edx
  int v17; // esi
  int v18; // ecx
  int *v19; // edx
  int v20; // ecx
  int k; // esi
  int v22; // edi
  int *v23; // edx

  numEntries = vcache->numEntries;
  v4 = 0;
  if ( numEntries <= 0 )
  {
LABEL_5:
    m_v0 = face->m_v0;
    for ( i = numEntries - 2; i >= 0; v9[1] = v8 )
    {
      v8 = vcache->entries[i];
      v9 = &vcache->entries[i--];
    }
    *vcache->entries = m_v0;
  }
  else
  {
    entries = vcache->entries;
    while ( *entries != face->m_v0 )
    {
      ++v4;
      ++entries;
      if ( v4 >= numEntries )
        goto LABEL_5;
    }
  }
  v10 = vcache->numEntries;
  v11 = 0;
  if ( v10 <= 0 )
  {
LABEL_12:
    v13 = vcache->numEntries - 2;
    for ( j = face->m_v1; v13 >= 0; v16[1] = v15 )
    {
      v15 = vcache->entries[v13];
      v16 = &vcache->entries[v13--];
    }
    *vcache->entries = j;
  }
  else
  {
    v12 = vcache->entries;
    while ( *v12 != face->m_v1 )
    {
      ++v11;
      ++v12;
      if ( v11 >= v10 )
        goto LABEL_12;
    }
  }
  v17 = vcache->numEntries;
  v18 = 0;
  if ( v17 <= 0 )
  {
LABEL_19:
    v20 = vcache->numEntries - 2;
    for ( k = face->m_v2; v20 >= 0; v23[1] = v22 )
    {
      v22 = vcache->entries[v20];
      v23 = &vcache->entries[v20--];
    }
    *vcache->entries = k;
  }
  else
  {
    v19 = vcache->entries;
    while ( *v19 != face->m_v2 )
    {
      ++v18;
      ++v19;
      if ( v18 >= v17 )
        goto LABEL_19;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005AF1A0
// Name: public: static struct std::_Tree_nod<class std::_Tset_traits<class NvFaceInfo __near *,struct std::less<class NvFaceInfo __near *>,class std::allocator<class NvFaceInfo __near *>,0>>::_Node __near * std::_Tree_val<class std::_Tset_traits<class NvFaceInfo __near *,struct std::less<class NvFaceInfo __near *>,class std::allocator<class NvFaceInfo __near *>,0>>::_Max(struct std::_Tree_nod<class std::_Tset_traits<class NvFaceInfo __near *,struct std::less<class NvFaceInfo __near *>,class std::allocator<class NvFaceInfo __near *>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *__cdecl std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0>>::_Max(
        std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *_Pnode)
{
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *result; // eax
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *i; // ecx

  result = _Pnode;
  for ( i = _Pnode->_Right; i->_Isnil == 0; i = i->_Right )
    result = i;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AF1C0
// Name: public: static struct std::_Tree_nod<class std::_Tset_traits<class NvFaceInfo __near *,struct std::less<class NvFaceInfo __near *>,class std::allocator<class NvFaceInfo __near *>,0>>::_Node __near * std::_Tree_val<class std::_Tset_traits<class NvFaceInfo __near *,struct std::less<class NvFaceInfo __near *>,class std::allocator<class NvFaceInfo __near *>,0>>::_Min(struct std::_Tree_nod<class std::_Tset_traits<class NvFaceInfo __near *,struct std::less<class NvFaceInfo __near *>,class std::allocator<class NvFaceInfo __near *>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *__cdecl std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0>>::_Min(
        std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *_Pnode)
{
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *result; // eax
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *i; // ecx

  result = _Pnode;
  for ( i = _Pnode->_Left; i->_Isnil == 0; i = i->_Left )
    result = i;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AF1E0
// Name: public: class std::_Tree_unchecked_const_iterator<class std::_Tree_val<class std::_Tset_traits<class NvFaceInfo __near *,struct std::less<class NvFaceInfo __near *>,class std::allocator<class NvFaceInfo __near *>,0>>,struct std::_Iterator_base0> __near & std::_Tree_unchecked_const_iterator<class std::_Tree_val<class std::_Tset_traits<class NvFaceInfo __near *,struct std::less<class NvFaceInfo __near *>,class std::allocator<class NvFaceInfo __near *>,0>>,struct std::_Iterator_base0>::operator++(void)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >,std::_Iterator_base0> *__thiscall std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0>>,std::_Iterator_base0>::operator++(
        std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >,std::_Iterator_base0> *this)
{
  std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >,std::_Iterator_base0> *result; // eax
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *Ptr; // edx
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *Right; // ecx
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *j; // edx
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *i; // edx

  result = this;
  Ptr = this->_Ptr;
  if ( this->_Ptr->_Isnil == 0 )
  {
    Right = Ptr->_Right;
    if ( Right->_Isnil != 0 )
    {
      for ( i = Ptr->_Parent; i->_Isnil == 0; i = i->_Parent )
      {
        if ( result->_Ptr != i->_Right )
          break;
        result->_Ptr = i;
      }
      result->_Ptr = i;
    }
    else
    {
      for ( j = Right->_Left; j->_Isnil == 0; j = j->_Left )
        Right = j;
      result->_Ptr = Right;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AF230
// Name: public: class std::_Tree_unchecked_const_iterator<class std::_Tree_val<class std::_Tset_traits<class NvFaceInfo __near *,struct std::less<class NvFaceInfo __near *>,class std::allocator<class NvFaceInfo __near *>,0>>,struct std::_Iterator_base0> __near & std::_Tree_unchecked_const_iterator<class std::_Tree_val<class std::_Tset_traits<class NvFaceInfo __near *,struct std::less<class NvFaceInfo __near *>,class std::allocator<class NvFaceInfo __near *>,0>>,struct std::_Iterator_base0>::operator--(void)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >,std::_Iterator_base0> *__thiscall std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0>>,std::_Iterator_base0>::operator--(
        std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >,std::_Iterator_base0> *this)
{
  std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >,std::_Iterator_base0> *result; // eax
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *Ptr; // ecx
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *Left; // edx
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *Right; // ecx
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *v5; // edx

  result = this;
  Ptr = this->_Ptr;
  if ( Ptr->_Isnil != 0 )
  {
    result->_Ptr = Ptr->_Right;
    return result;
  }
  Left = Ptr->_Left;
  if ( Ptr->_Left->_Isnil == 0 )
  {
    Right = Left->_Right;
    if ( Right->_Isnil == 0 )
    {
      do
      {
        v5 = Right;
        Right = Right->_Right;
      }
      while ( Right->_Isnil == 0 );
      result->_Ptr = v5;
      return result;
    }
LABEL_11:
    result->_Ptr = Left;
    return result;
  }
  for ( Left = Ptr->_Parent; Left->_Isnil == 0; Left = Left->_Parent )
  {
    if ( result->_Ptr != Left->_Left )
      break;
    result->_Ptr = Left;
  }
  if ( result->_Ptr->_Isnil == 0 )
    goto LABEL_11;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AF290
// Name: protected: static class NvEdgeInfo __near * NvStripifier::FindEdgeInfo(class std::vector<class NvEdgeInfo __near *,class std::allocator<class NvEdgeInfo __near *>> __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
NvEdgeInfo *__cdecl NvStripifier::FindEdgeInfo(std::vector<NvEdgeInfo *> *edgeInfos, int v0, int v1)
{
  NvEdgeInfo *result; // eax
  int m_v0; // ecx

  result = edgeInfos->_Myfirst[v0];
  while ( result != nullptr )
  {
    m_v0 = result->m_v0;
    if ( m_v0 == v0 )
    {
      if ( result->m_v1 == v1 )
        return result;
      result = result->m_nextV0;
    }
    else
    {
      if ( m_v0 == v1 )
        return result;
      result = result->m_nextV1;
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x005AF2D0
// Name: protected: int NvStripifier::FindStartPoint(class std::vector<class NvFaceInfo __near *,class std::allocator<class NvFaceInfo __near *>> __near &,class std::vector<class NvEdgeInfo __near *,class std::allocator<class NvEdgeInfo __near *>> __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall NvStripifier::FindStartPoint(
        NvStripifier *this,
        std::vector<NvFaceInfo *> *faceInfos,
        std::vector<NvEdgeInfo *> *edgeInfos)
{
  NvEdgeInfo **Myfirst; // eax
  NvFaceInfo **v4; // ebx
  int m_v0; // edx
  int m_v1; // edi
  NvEdgeInfo *v7; // ecx
  int v8; // esi
  NvFaceInfo *m_face1; // ecx
  int v10; // esi
  int m_v2; // edi
  NvEdgeInfo *v12; // ecx
  int v13; // edx
  NvFaceInfo *m_face0; // ecx
  int v15; // esi
  int v16; // edi
  NvEdgeInfo *v17; // ecx
  int v18; // edx
  NvFaceInfo *v19; // ecx
  unsigned int v21; // [esp+0h] [ebp-10h]
  int bestIndex; // [esp+4h] [ebp-Ch]
  int bestCtr; // [esp+8h] [ebp-8h]
  unsigned int i; // [esp+Ch] [ebp-4h]
  int ctr; // [esp+18h] [ebp+8h]

  bestCtr = -1;
  bestIndex = -1;
  i = 0;
  v21 = faceInfos->_Mylast - faceInfos->_Myfirst;
  if ( v21 == 0 )
    return bestIndex;
  Myfirst = edgeInfos->_Myfirst;
  v4 = faceInfos->_Myfirst;
  do
  {
    m_v0 = (*v4)->m_v0;
    m_v1 = (*v4)->m_v1;
    v7 = Myfirst[m_v0];
    ctr = 0;
    while ( v7 != nullptr )
    {
      v8 = v7->m_v0;
      if ( v8 == m_v0 )
      {
        if ( v7->m_v1 == m_v1 )
          goto LABEL_11;
        v7 = v7->m_nextV0;
      }
      else
      {
        if ( v8 == m_v1 )
          goto LABEL_11;
        v7 = v7->m_nextV1;
      }
    }
    v7 = nullptr;
    if ( m_v0 == m_v1 )
    {
LABEL_15:
      ctr = 1;
      goto LABEL_16;
    }
LABEL_11:
    if ( v7->m_face0 == *v4 )
      m_face1 = v7->m_face1;
    else
      m_face1 = v7->m_face0;
    if ( m_face1 == nullptr )
      goto LABEL_15;
LABEL_16:
    v10 = (*v4)->m_v1;
    m_v2 = (*v4)->m_v2;
    v12 = Myfirst[v10];
    while ( v12 != nullptr )
    {
      v13 = v12->m_v0;
      if ( v13 == v10 )
      {
        if ( v12->m_v1 == m_v2 )
          goto LABEL_24;
        v12 = v12->m_nextV0;
      }
      else
      {
        if ( v13 == m_v2 )
          goto LABEL_24;
        v12 = v12->m_nextV1;
      }
    }
    v12 = nullptr;
    if ( v10 == m_v2 )
    {
LABEL_28:
      ++ctr;
      goto LABEL_29;
    }
LABEL_24:
    if ( v12->m_face0 == *v4 )
      m_face0 = v12->m_face1;
    else
      m_face0 = v12->m_face0;
    if ( m_face0 == nullptr )
      goto LABEL_28;
LABEL_29:
    v15 = (*v4)->m_v2;
    v16 = (*v4)->m_v0;
    v17 = Myfirst[v15];
    while ( v17 != nullptr )
    {
      v18 = v17->m_v0;
      if ( v18 == v15 )
      {
        if ( v17->m_v1 == v16 )
          goto LABEL_37;
        v17 = v17->m_nextV0;
      }
      else
      {
        if ( v18 == v16 )
          goto LABEL_37;
        v17 = v17->m_nextV1;
      }
    }
    v17 = nullptr;
    if ( v15 == v16 )
    {
LABEL_41:
      ++ctr;
      goto LABEL_42;
    }
LABEL_37:
    if ( v17->m_face0 == *v4 )
      v19 = v17->m_face1;
    else
      v19 = v17->m_face0;
    if ( v19 == nullptr )
      goto LABEL_41;
LABEL_42:
    if ( ctr > bestCtr )
    {
      bestCtr = ctr;
      bestIndex = i;
    }
    ++v4;
    ++i;
  }
  while ( i < v21 );
  if ( bestCtr == 0 )
    return -1;
  return bestIndex;
}

//------------------------------------------------------------------------------
// Address: 0x005AF430
// Name: protected: static int NvStripifier::GetNextIndex(class std::vector<unsigned short,class std::allocator<unsigned short>> const __near &,class NvFaceInfo __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl NvStripifier::GetNextIndex(const std::vector<unsigned short> *indices, NvFaceInfo *face)
{
  int v2; // eax
  int v3; // edx
  int v4; // ecx
  int m_v2; // ebx
  int m_v0; // esi
  int m_v1; // edi

  v2 = indices->_Mylast - indices->_Myfirst;
  v3 = indices->_Myfirst[v2 - 2];
  v4 = indices->_Myfirst[v2 - 1];
  m_v2 = face->m_v2;
  m_v0 = face->m_v0;
  m_v1 = face->m_v1;
  if ( face->m_v0 != v3 && m_v0 != v4 )
  {
    if ( m_v1 != v3 && m_v1 != v4 || m_v2 != v3 && m_v2 != v4 )
    {
      printf(format: "GetNextIndex: Triangle doesn't have all of its vertices\n");
      printf(format: "GetNextIndex: Duplicate triangle probably got us derailed\n");
    }
    return m_v0;
  }
  if ( m_v1 != v3 && m_v1 != v4 )
  {
    if ( m_v0 != v3 && m_v0 != v4 || m_v2 != v3 && m_v2 != v4 )
    {
      printf(format: "GetNextIndex: Triangle doesn't have all of its vertices\n");
      printf(format: "GetNextIndex: Duplicate triangle probably got us derailed\n");
    }
    return m_v1;
  }
  if ( m_v2 == v3 || m_v2 == v4 )
  {
    if ( m_v0 == m_v1 || m_v0 == m_v2 )
      return m_v0;
    if ( m_v1 == m_v2 )
      return m_v1;
    return -1;
  }
  else
  {
    if ( m_v0 != v3 && m_v0 != v4 || m_v1 != v3 && m_v1 != v4 )
    {
      printf(format: "GetNextIndex: Triangle doesn't have all of its vertices\n");
      printf(format: "GetNextIndex: Duplicate triangle probably got us derailed\n");
    }
    return m_v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005AF510
// Name: public: bool NvStripInfo::Unique(class std::vector<class NvFaceInfo __near *,class std::allocator<class NvFaceInfo __near *>> __near &,class NvFaceInfo __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall NvStripInfo::Unique(NvStripInfo *this, std::vector<NvFaceInfo *> *faceVec, NvFaceInfo *face)
{
  unsigned int v3; // edx
  int v4; // ebx
  NvFaceInfo **i; // esi
  NvFaceInfo *v6; // eax
  int m_v0; // ecx
  NvFaceInfo *v8; // eax
  int m_v1; // ecx
  NvFaceInfo *v10; // eax
  int m_v2; // ecx
  bool bv2; // [esp+Dh] [ebp-3h]
  bool bv1; // [esp+Eh] [ebp-2h]
  bool bv0; // [esp+Fh] [ebp-1h]

  v3 = faceVec->_Mylast - faceVec->_Myfirst;
  v4 = 0;
  bv2 = false;
  bv1 = false;
  bv0 = false;
  if ( v3 == 0 )
    return 1;
  for ( i = faceVec->_Myfirst; ; ++i )
  {
    if ( !bv0 )
    {
      v6 = *i;
      m_v0 = face->m_v0;
      if ( (*i)->m_v0 == face->m_v0 || v6->m_v1 == m_v0 || v6->m_v2 == m_v0 )
        bv0 = true;
    }
    if ( !bv1 )
    {
      v8 = *i;
      m_v1 = face->m_v1;
      if ( (*i)->m_v0 == m_v1 || v8->m_v1 == m_v1 || v8->m_v2 == m_v1 )
        bv1 = true;
    }
    if ( !bv2 )
    {
      v10 = *i;
      m_v2 = face->m_v2;
      if ( (*i)->m_v0 == m_v2 || v10->m_v1 == m_v2 || v10->m_v2 == m_v2 )
        bv2 = true;
    }
    if ( bv0 && bv1 && bv2 )
      break;
    if ( ++v4 >= v3 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x005AF5D0
// Name: public: bool NvStripInfo::SharesEdge(class NvFaceInfo const __near *,class std::vector<class NvEdgeInfo __near *,class std::allocator<class NvEdgeInfo __near *>> __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall NvStripInfo::SharesEdge(
        NvStripInfo *this,
        const NvFaceInfo *faceInfo,
        std::vector<NvEdgeInfo *> *edgeInfos)
{
  int m_v0; // ebx
  int m_v1; // edx
  NvEdgeInfo *v6; // eax
  int v7; // ecx
  NvFaceInfo *m_face0; // ecx
  int v9; // ecx
  NvFaceInfo *m_face1; // eax
  int m_v2; // edi
  NvEdgeInfo *EdgeInfo; // eax
  NvFaceInfo *v14; // ecx
  NvEdgeInfo *v16; // edi
  bool result; // al

  m_v0 = faceInfo->m_v0;
  m_v1 = faceInfo->m_v1;
  v6 = edgeInfos->_Myfirst[faceInfo->m_v0];
  while ( v6 != nullptr )
  {
    v7 = v6->m_v0;
    if ( v7 == m_v0 )
    {
      if ( v6->m_v1 == m_v1 )
        goto LABEL_9;
      v6 = v6->m_nextV0;
    }
    else
    {
      if ( v7 == m_v1 )
        goto LABEL_9;
      v6 = v6->m_nextV1;
    }
  }
  v6 = nullptr;
LABEL_9:
  m_face0 = v6->m_face0;
  if ( m_face0 != nullptr )
  {
    v9 = this->m_experimentId < 0 ? m_face0->m_stripId : m_face0->m_testStripId;
    if ( v9 == this->m_stripId )
      return true;
  }
  m_face1 = v6->m_face1;
  if ( m_face1 != nullptr
    && (this->m_experimentId < 0 ? m_face1->m_stripId == this->m_stripId : m_face1->m_testStripId == this->m_stripId) )
  {
    return true;
  }
  m_v2 = faceInfo->m_v2;
  EdgeInfo = NvStripifier::FindEdgeInfo(edgeInfos, v0: m_v1, v1: m_v2);
  v14 = EdgeInfo->m_face0;
  if ( v14 != nullptr
    && (this->m_experimentId < 0 ? v14->m_stripId == this->m_stripId : v14->m_testStripId == this->m_stripId) )
  {
    return true;
  }
  if ( NvStripInfo::IsInStrip(this, faceInfo: EdgeInfo->m_face1) )
    return true;
  v16 = NvStripifier::FindEdgeInfo(edgeInfos, v0: m_v2, v1: m_v0);
  if ( NvStripInfo::IsInStrip(this, faceInfo: v16->m_face0) )
    return true;
  result = NvStripInfo::IsInStrip(this, faceInfo: v16->m_face1);
  if ( result )
    return true;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AF6E0
// Name: protected: bool NvStripifier::FindTraversal(class std::vector<class NvFaceInfo __near *,class std::allocator<class NvFaceInfo __near *>> __near &,class std::vector<class NvEdgeInfo __near *,class std::allocator<class NvEdgeInfo __near *>> __near &,class NvStripInfo __near *,class NvStripStartInfo __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall NvStripifier::FindTraversal(
        NvStripifier *this,
        std::vector<NvFaceInfo *> *faceInfos,
        std::vector<NvEdgeInfo *> *edgeInfos,
        NvStripInfo *strip,
        NvStripStartInfo *startInfo)
{
  NvEdgeInfo *v6; // edi
  NvFaceInfo *m_face0; // esi
  int *p_m_v0; // eax
  int m_experimentId; // ecx
  int v10; // edx
  int v11; // edx
  bool v12; // zf
  NvFaceInfo *untouchedFace; // [esp+Ch] [ebp-4h]
  int v; // [esp+20h] [ebp+10h]

  if ( strip->m_startInfo.m_toV1 )
    v = strip->m_startInfo.m_startEdge->m_v1;
  else
    v = strip->m_startInfo.m_startEdge->m_v0;
  v6 = edgeInfos->_Myfirst[v];
  untouchedFace = nullptr;
  while ( v6 != nullptr )
  {
    m_face0 = v6->m_face0;
    p_m_v0 = &v6->m_face1->m_v0;
    if ( m_face0 != nullptr )
    {
      m_experimentId = strip->m_experimentId;
      v10 = m_experimentId < 0 ? m_face0->m_stripId : m_face0->m_testStripId;
      if ( v10 != strip->m_stripId )
      {
        if ( p_m_v0 == nullptr )
          goto LABEL_23;
        if ( p_m_v0[3] < 0 && (m_experimentId < 0 || p_m_v0[5] != m_experimentId) )
        {
          untouchedFace = v6->m_face1;
          break;
        }
      }
    }
    if ( p_m_v0 != nullptr )
    {
      v11 = strip->m_experimentId;
      v12 = v11 < 0 ? p_m_v0[3] == strip->m_stripId : p_m_v0[4] == strip->m_stripId;
      if ( !v12 && m_face0 != nullptr && m_face0->m_stripId < 0 && (v11 < 0 || m_face0->m_experimentId != v11) )
      {
        untouchedFace = v6->m_face0;
        break;
      }
    }
LABEL_23:
    if ( v6->m_v0 == v )
      v6 = v6->m_nextV0;
    else
      v6 = v6->m_nextV1;
  }
  startInfo->m_startFace = untouchedFace;
  startInfo->m_startEdge = v6;
  if ( v6 != nullptr )
  {
    if ( NvStripInfo::SharesEdge(this: strip, faceInfo: untouchedFace, edgeInfos) )
    {
      startInfo->m_toV1 = v6->m_v0 == v;
      return untouchedFace != nullptr;
    }
    startInfo->m_toV1 = v6->m_v1 == v;
  }
  return untouchedFace != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x005AF800
// Name: protected: void NvStripifier::UpdateCacheStrip(class VertexCache __near *,class NvStripInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NvStripifier::UpdateCacheStrip(NvStripifier *this, VertexCache *vcache, NvStripInfo *strip)
{
  unsigned int v3; // ecx
  int numEntries; // esi
  int v5; // edx
  int m_v0; // edi
  int *entries; // ecx
  int v8; // ecx
  int j; // esi
  int v10; // edi
  int *v11; // edx
  int v12; // esi
  int v13; // ecx
  int *v14; // edx
  int m_v1; // esi
  int k; // ecx
  int v17; // edi
  int *v18; // edx
  int v19; // esi
  int v20; // ecx
  int *v21; // edx
  int m_v2; // esi
  int m; // ecx
  int v24; // edi
  int *v25; // edx
  int i; // [esp+4h] [ebp-4h]

  v3 = 0;
  for ( i = 0; v3 < strip->m_faces._Mylast - strip->m_faces._Myfirst; i = v3 )
  {
    numEntries = vcache->numEntries;
    v5 = 0;
    if ( numEntries <= 0 )
    {
LABEL_6:
      v8 = vcache->numEntries - 2;
      for ( j = strip->m_faces._Myfirst[i]->m_v0; v8 >= 0; v11[1] = v10 )
      {
        v10 = vcache->entries[v8];
        v11 = &vcache->entries[v8--];
      }
      *vcache->entries = j;
    }
    else
    {
      m_v0 = strip->m_faces._Myfirst[v3]->m_v0;
      entries = vcache->entries;
      while ( *entries != m_v0 )
      {
        ++v5;
        ++entries;
        if ( v5 >= numEntries )
          goto LABEL_6;
      }
    }
    v12 = vcache->numEntries;
    v13 = 0;
    if ( v12 <= 0 )
    {
LABEL_13:
      m_v1 = strip->m_faces._Myfirst[i]->m_v1;
      for ( k = vcache->numEntries - 2; k >= 0; v18[1] = v17 )
      {
        v17 = vcache->entries[k];
        v18 = &vcache->entries[k--];
      }
      *vcache->entries = m_v1;
    }
    else
    {
      v14 = vcache->entries;
      while ( *v14 != strip->m_faces._Myfirst[i]->m_v1 )
      {
        ++v13;
        ++v14;
        if ( v13 >= v12 )
          goto LABEL_13;
      }
    }
    v19 = vcache->numEntries;
    v20 = 0;
    if ( v19 <= 0 )
    {
LABEL_20:
      m_v2 = strip->m_faces._Myfirst[i]->m_v2;
      for ( m = vcache->numEntries - 2; m >= 0; v25[1] = v24 )
      {
        v24 = vcache->entries[m];
        v25 = &vcache->entries[m--];
      }
      *vcache->entries = m_v2;
    }
    else
    {
      v21 = vcache->entries;
      while ( *v21 != strip->m_faces._Myfirst[i]->m_v2 )
      {
        ++v20;
        ++v21;
        if ( v20 >= v19 )
          goto LABEL_20;
      }
    }
    v3 = i + 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005AF930
// Name: protected: float NvStripifier::CalcNumHitsStrip(class VertexCache __near *,class NvStripInfo __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall NvStripifier::CalcNumHitsStrip(NvStripifier *this, VertexCache *vcache, NvStripInfo *strip)
{
  unsigned int v4; // edi
  int v5; // ecx
  int numEntries; // eax
  int v7; // edx
  int *entries; // ecx
  int v9; // edx
  int *v10; // ecx
  int v11; // edx
  int *v12; // ecx
  int numFaces; // [esp+8h] [ebp-8h]
  int numHits; // [esp+Ch] [ebp-4h]
  NvStripInfo *stripa; // [esp+1Ch] [ebp+Ch]

  v4 = 0;
  v5 = strip->m_faces._Mylast - strip->m_faces._Myfirst;
  numHits = 0;
  numFaces = 0;
  stripa = (NvStripInfo *)v5;
  if ( v5 != 0 )
  {
    numEntries = vcache->numEntries;
    numFaces = v5;
    do
    {
      v7 = 0;
      if ( numEntries > 0 )
      {
        entries = vcache->entries;
        while ( *entries != strip->m_faces._Myfirst[v4]->m_v0 )
        {
          ++v7;
          ++entries;
          if ( v7 >= numEntries )
            goto LABEL_9;
        }
        ++numHits;
      }
LABEL_9:
      v9 = 0;
      if ( numEntries > 0 )
      {
        v10 = vcache->entries;
        while ( *v10 != strip->m_faces._Myfirst[v4]->m_v1 )
        {
          ++v9;
          ++v10;
          if ( v9 >= numEntries )
            goto LABEL_15;
        }
        ++numHits;
      }
LABEL_15:
      v11 = 0;
      if ( numEntries > 0 )
      {
        v12 = vcache->entries;
        while ( *v12 != strip->m_faces._Myfirst[v4]->m_v2 )
        {
          ++v11;
          ++v12;
          if ( v11 >= numEntries )
            goto LABEL_21;
        }
        ++numHits;
      }
LABEL_21:
      ++v4;
    }
    while ( v4 < (unsigned int)stripa );
  }
  return (double)numHits / (double)numFaces;
}

//------------------------------------------------------------------------------
// Address: 0x005AF9F0
// Name: protected: int NvStripifier::NumNeighbors(class NvFaceInfo __near *,class std::vector<class NvEdgeInfo __near *,class std::allocator<class NvEdgeInfo __near *>> __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall NvStripifier::NumNeighbors(NvStripifier *this, NvFaceInfo *face, std::vector<NvEdgeInfo *> *edgeInfoVec)
{
  NvEdgeInfo **Myfirst; // eax
  int m_v0; // ebx
  NvEdgeInfo *v5; // ecx
  int m_v1; // esi
  int v7; // edx
  NvFaceInfo *m_face1; // ecx
  NvEdgeInfo *v9; // ecx
  int m_v2; // edi
  int v11; // edx
  NvFaceInfo *m_face0; // ecx
  int v13; // esi
  NvEdgeInfo *v14; // ecx
  int v15; // edx
  NvFaceInfo *v16; // ecx
  int result; // eax
  int numNeighbors; // [esp+Ch] [ebp-4h]

  Myfirst = edgeInfoVec->_Myfirst;
  m_v0 = face->m_v0;
  v5 = edgeInfoVec->_Myfirst[face->m_v0];
  m_v1 = face->m_v1;
  numNeighbors = 0;
  while ( v5 != nullptr )
  {
    v7 = v5->m_v0;
    if ( v7 == m_v0 )
    {
      if ( v5->m_v1 == m_v1 )
        goto LABEL_9;
      v5 = v5->m_nextV0;
    }
    else
    {
      if ( v7 == m_v1 )
        goto LABEL_9;
      v5 = v5->m_nextV1;
    }
  }
  v5 = nullptr;
  if ( m_v0 != m_v1 )
  {
LABEL_9:
    if ( v5->m_face0 == face )
      m_face1 = v5->m_face1;
    else
      m_face1 = v5->m_face0;
    if ( m_face1 != nullptr )
      numNeighbors = 1;
  }
  v9 = Myfirst[m_v1];
  m_v2 = face->m_v2;
  while ( v9 != nullptr )
  {
    v11 = v9->m_v0;
    if ( v11 == m_v1 )
    {
      if ( v9->m_v1 == m_v2 )
        goto LABEL_22;
      v9 = v9->m_nextV0;
    }
    else
    {
      if ( v11 == m_v2 )
        goto LABEL_22;
      v9 = v9->m_nextV1;
    }
  }
  v9 = nullptr;
  if ( m_v1 == m_v2 )
  {
    v13 = numNeighbors;
  }
  else
  {
LABEL_22:
    if ( v9->m_face0 == face )
      m_face0 = v9->m_face1;
    else
      m_face0 = v9->m_face0;
    v13 = numNeighbors;
    if ( m_face0 != nullptr )
      v13 = numNeighbors + 1;
  }
  v14 = Myfirst[m_v2];
  while ( v14 != nullptr )
  {
    v15 = v14->m_v0;
    if ( v15 == m_v2 )
    {
      if ( v14->m_v1 == m_v0 )
        goto LABEL_36;
      v14 = v14->m_nextV0;
    }
    else
    {
      if ( v15 == m_v0 )
        goto LABEL_36;
      v14 = v14->m_nextV1;
    }
  }
  v14 = nullptr;
  if ( m_v2 == m_v0 )
    return v13;
LABEL_36:
  if ( v14->m_face0 == face )
    v16 = v14->m_face1;
  else
    v16 = v14->m_face0;
  result = v13 + 1;
  if ( v16 == nullptr )
    return v13;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AFAF0
// Name: protected: float NvStripifier::AvgStripSize(class std::vector<class NvStripInfo __near *,class std::allocator<class NvStripInfo __near *>> const __near &)
// Source: json
//------------------------------------------------------------------------------
double __thiscall NvStripifier::AvgStripSize(NvStripifier *this, const std::vector<NvStripInfo *> *strips)
{
  NvStripInfo **Myfirst; // ecx
  int v3; // esi
  int v4; // edi
  int v5; // eax
  unsigned int v6; // edx
  NvStripInfo *v7; // eax
  int v8; // ebx
  NvStripInfo **v10; // [esp+Ch] [ebp-Ch]
  int v11; // [esp+10h] [ebp-8h]
  int v12; // [esp+14h] [ebp-4h]
  int i; // [esp+20h] [ebp+8h]

  Myfirst = strips->_Myfirst;
  v3 = strips->_Mylast - strips->_Myfirst;
  v4 = 0;
  v5 = 0;
  v11 = 0;
  v12 = 0;
  v10 = strips->_Myfirst;
  if ( v3 >= 2 )
  {
    v6 = ((unsigned int)(v3 - 2) >> 1) + 1;
    i = 2 * v6;
    do
    {
      v7 = *Myfirst;
      v8 = (char *)(*Myfirst)->m_faces._Mylast - (char *)(*Myfirst)->m_faces._Myfirst;
      Myfirst += 2;
      v11 += (v8 >> 2) - v7->m_numDegenerates;
      v12 += (*(Myfirst - 1))->m_faces._Mylast - (*(Myfirst - 1))->m_faces._Myfirst - (*(Myfirst - 1))->m_numDegenerates;
      --v6;
    }
    while ( v6 != 0 );
    v5 = i;
    Myfirst = v10;
  }
  if ( v5 < v3 )
    v4 = Myfirst[v5]->m_faces._Mylast - Myfirst[v5]->m_faces._Myfirst - Myfirst[v5]->m_numDegenerates;
  return (double)(v4 + v11 + v12) / (double)v3;
}

//------------------------------------------------------------------------------
// Address: 0x005AFBF0
// Name: protected: void std::_Tree<class std::_Tset_traits<class NvFaceInfo __near *,struct std::less<class NvFaceInfo __near *>,class std::allocator<class NvFaceInfo __near *>,0>>::_Lrotate(struct std::_Tree_nod<class std::_Tset_traits<class NvFaceInfo __near *,struct std::less<class NvFaceInfo __near *>,class std::allocator<class NvFaceInfo __near *>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0>>::_Lrotate(
        std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> > *this,
        std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *_Wherenode)
{
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *Right; // eax
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *Myhead; // ecx
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *Parent; // ecx

  Right = _Wherenode->_Right;
  _Wherenode->_Right = Right->_Left;
  if ( Right->_Left->_Isnil == 0 )
    Right->_Left->_Parent = _Wherenode;
  Right->_Parent = _Wherenode->_Parent;
  Myhead = this->_Myhead;
  if ( _Wherenode == Myhead->_Parent )
  {
    Myhead->_Parent = Right;
    Right->_Left = _Wherenode;
    _Wherenode->_Parent = Right;
  }
  else
  {
    Parent = _Wherenode->_Parent;
    if ( _Wherenode == Parent->_Left )
      Parent->_Left = Right;
    else
      Parent->_Right = Right;
    Right->_Left = _Wherenode;
    _Wherenode->_Parent = Right;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005AFC50
// Name: protected: void std::_Tree<class std::_Tset_traits<class NvFaceInfo __near *,struct std::less<class NvFaceInfo __near *>,class std::allocator<class NvFaceInfo __near *>,0>>::_Rrotate(struct std::_Tree_nod<class std::_Tset_traits<class NvFaceInfo __near *,struct std::less<class NvFaceInfo __near *>,class std::allocator<class NvFaceInfo __near *>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0>>::_Rrotate(
        std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> > *this,
        std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *_Wherenode)
{
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *Left; // eax
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *Right; // esi
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *Myhead; // ecx
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *Parent; // ecx

  Left = _Wherenode->_Left;
  _Wherenode->_Left = _Wherenode->_Left->_Right;
  Right = Left->_Right;
  if ( Right->_Isnil == 0 )
    Right->_Parent = _Wherenode;
  Left->_Parent = _Wherenode->_Parent;
  Myhead = this->_Myhead;
  if ( _Wherenode == Myhead->_Parent )
  {
    Myhead->_Parent = Left;
    Left->_Right = _Wherenode;
    _Wherenode->_Parent = Left;
  }
  else
  {
    Parent = _Wherenode->_Parent;
    if ( _Wherenode == Parent->_Right )
      Parent->_Right = Left;
    else
      Parent->_Left = Left;
    Left->_Right = _Wherenode;
    _Wherenode->_Parent = Left;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005AFCB0
// Name: void std::_Cons_val<class std::allocator<class NvFaceInfo __near *>,class NvFaceInfo __near *,class NvFaceInfo __near * __near &>(class std::allocator<class NvFaceInfo __near *> __near &,class NvFaceInfo __near * __near *,class NvFaceInfo __near * __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Cons_val<std::allocator<NvFaceInfo *>,NvFaceInfo *,NvFaceInfo * &>(
        std::allocator<NvFaceInfo *> *_Alval,
        NvFaceInfo **_Pdest,
        NvFaceInfo **_Src)
{
  if ( _Pdest != nullptr )
    *_Pdest = *_Src;
}

//------------------------------------------------------------------------------
// Address: 0x005AFD50
// Name: protected: class std::_Tree_const_iterator<class std::_Tree_val<class std::_Tset_traits<class NvFaceInfo __near *,struct std::less<class NvFaceInfo __near *>,class std::allocator<class NvFaceInfo __near *>,0>>> std::_Tree<class std::_Tset_traits<class NvFaceInfo __near *,struct std::less<class NvFaceInfo __near *>,class std::allocator<class NvFaceInfo __near *>,0>>::_Insert(bool,struct std::_Tree_nod<class std::_Tset_traits<class NvFaceInfo __near *,struct std::less<class NvFaceInfo __near *>,class std::allocator<class NvFaceInfo __near *>,0>>::_Node __near *,struct std::_Tree_nod<class std::_Tset_traits<class NvFaceInfo __near *,struct std::less<class NvFaceInfo __near *>,class std::allocator<class NvFaceInfo __near *>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> > > *__thiscall std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0>>::_Insert(
        std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> > *this,
        std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> > > *result,
        bool _Addleft,
        std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *_Wherenode,
        std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *_Newnode)
{
  unsigned int Mysize; // eax
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *v6; // edi
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *Myhead; // edx
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *v8; // edx
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *v9; // edx
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *v10; // eax
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *Parent; // edx
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *v12; // esi
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *Right; // esi
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *v14; // edx
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *v15; // esi
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *v16; // esi
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *v17; // edx
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *Left; // esi
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *v19; // edi
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *v20; // edi
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *v21; // edi
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *v22; // esi
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *v23; // edx
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *v24; // esi
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *v25; // esi
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *v26; // esi
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *v27; // edi
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *v28; // edi
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *v29; // ecx

  Mysize = this->_Mysize;
  if ( Mysize >= 0x3FFFFFFE )
  {
    free(pMem: _Newnode);
    std::_Xlength_error(_Message: "map/set<T> too long");
  }
  this->_Mysize = Mysize + 1;
  v6 = _Newnode;
  _Newnode->_Parent = _Wherenode;
  Myhead = this->_Myhead;
  if ( _Wherenode == Myhead )
  {
    Myhead->_Parent = _Newnode;
    this->_Myhead->_Left = _Newnode;
    this->_Myhead->_Right = _Newnode;
  }
  else if ( _Addleft )
  {
    _Wherenode->_Left = _Newnode;
    v8 = this->_Myhead;
    if ( _Wherenode == v8->_Left )
      v8->_Left = _Newnode;
  }
  else
  {
    _Wherenode->_Right = _Newnode;
    v9 = this->_Myhead;
    if ( _Wherenode == v9->_Right )
      v9->_Right = _Newnode;
  }
  v10 = _Newnode;
  while ( v10->_Parent->_Color == 0 )
  {
    Parent = v10->_Parent;
    v12 = Parent->_Parent;
    if ( Parent == v12->_Left )
    {
      Right = v12->_Right;
      if ( Right->_Color != 0 )
      {
        if ( v10 == Parent->_Right )
        {
          v10 = v10->_Parent;
          v14 = Parent->_Right;
          v10->_Right = v14->_Left;
          if ( v14->_Left->_Isnil == 0 )
            v14->_Left->_Parent = v10;
          v14->_Parent = v10->_Parent;
          v15 = this->_Myhead;
          if ( v10 == v15->_Parent )
          {
            v15->_Parent = v14;
          }
          else
          {
            v16 = v10->_Parent;
            if ( v10 == v16->_Left )
              v16->_Left = v14;
            else
              v16->_Right = v14;
          }
          v14->_Left = v10;
          v10->_Parent = v14;
        }
        v10->_Parent->_Color = 1;
        v10->_Parent->_Parent->_Color = 0;
        v17 = v10->_Parent->_Parent;
        Left = v17->_Left;
        v17->_Left = v17->_Left->_Right;
        v19 = Left->_Right;
        if ( v19->_Isnil == 0 )
          v19->_Parent = v17;
        Left->_Parent = v17->_Parent;
        v20 = this->_Myhead;
        if ( v17 == v20->_Parent )
        {
          v20->_Parent = Left;
          Left->_Right = v17;
        }
        else
        {
          v21 = v17->_Parent;
          if ( v17 == v21->_Right )
            v21->_Right = Left;
          else
            v21->_Left = Left;
          Left->_Right = v17;
        }
LABEL_50:
        v6 = _Newnode;
        v17->_Parent = Left;
        continue;
      }
      Parent->_Color = 1;
      Right->_Color = 1;
      v10->_Parent->_Parent->_Color = 0;
      v10 = v10->_Parent->_Parent;
    }
    else
    {
      v22 = v12->_Left;
      if ( v22->_Color != 0 )
      {
        if ( v10 == Parent->_Left )
        {
          v10 = v10->_Parent;
          v23 = Parent->_Left;
          v10->_Left = v23->_Right;
          v24 = v23->_Right;
          if ( v24->_Isnil == 0 )
            v24->_Parent = v10;
          v23->_Parent = v10->_Parent;
          v25 = this->_Myhead;
          if ( v10 == v25->_Parent )
          {
            v25->_Parent = v23;
          }
          else
          {
            v26 = v10->_Parent;
            if ( v10 == v26->_Right )
              v26->_Right = v23;
            else
              v26->_Left = v23;
          }
          v23->_Right = v10;
          v10->_Parent = v23;
        }
        v10->_Parent->_Color = 1;
        v10->_Parent->_Parent->_Color = 0;
        v17 = v10->_Parent->_Parent;
        Left = v17->_Right;
        v17->_Right = Left->_Left;
        if ( Left->_Left->_Isnil == 0 )
          Left->_Left->_Parent = v17;
        Left->_Parent = v17->_Parent;
        v27 = this->_Myhead;
        if ( v17 == v27->_Parent )
        {
          v27->_Parent = Left;
        }
        else
        {
          v28 = v17->_Parent;
          if ( v17 == v28->_Left )
            v28->_Left = Left;
          else
            v28->_Right = Left;
        }
        Left->_Left = v17;
        goto LABEL_50;
      }
      Parent->_Color = 1;
      v22->_Color = 1;
      v10->_Parent->_Parent->_Color = 0;
      v10 = v10->_Parent->_Parent;
    }
  }
  v29 = this->_Myhead->_Parent;
  result->_Ptr = v6;
  v29->_Color = 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AFF80
// Name: public: struct std::_Tree_nod<class std::_Tset_traits<class NvFaceInfo __near *,struct std::less<class NvFaceInfo __near *>,class std::allocator<class NvFaceInfo __near *>,0>>::_Node __near * std::_Tree_val<class std::_Tset_traits<class NvFaceInfo __near *,struct std::less<class NvFaceInfo __near *>,class std::allocator<class NvFaceInfo __near *>,0>>::_Buynode<class NvFaceInfo __near * __near &>(class NvFaceInfo __near * __near &)
// Source: json
//------------------------------------------------------------------------------
NvFaceInfo **__thiscall std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0>>::_Buynode<NvFaceInfo * &>(
        std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> > *this,
        NvFaceInfo **_Val)
{
  NvFaceInfo **v3; // esi
  int v5; // [esp+0h] [ebp-2Ch] BYREF
  std::exception pExceptionObject; // [esp+Ch] [ebp-20h] BYREF
  void *pMem; // [esp+18h] [ebp-14h]
  int *v8; // [esp+1Ch] [ebp-10h]
  int v9; // [esp+28h] [ebp-4h]

  v8 = &v5;
  v3 = (NvFaceInfo **)MemAlloc_Alloc(nSize: 0x14u);
  pMem = v3;
  if ( v3 == nullptr )
  {
    _Val = nullptr;
    std::exception::exception(this: &pExceptionObject, _What: (const char *const *)&_Val);
    pExceptionObject.__vftable = (std::exception_vtbl *)&std::bad_alloc::`vftable';
    _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI2_AVbad_alloc_std__);
  }
  *v3 = (NvFaceInfo *)this->_Myhead;
  v3[1] = (NvFaceInfo *)this->_Myhead;
  v3[2] = (NvFaceInfo *)this->_Myhead;
  *((_WORD *)v3 + 8) = 0;
  v9 = 0;
  std::_Cons_val<std::allocator<NvFaceInfo *>,NvFaceInfo *,NvFaceInfo * &>(
    _Alval: &this->_Alval,
    _Pdest: v3 + 3,
    _Src: _Val);
  v9 = -1;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x005B0100
// Name: public: class std::_Tree_const_iterator<class std::_Tree_val<class std::_Tset_traits<class NvFaceInfo __near *,struct std::less<class NvFaceInfo __near *>,class std::allocator<class NvFaceInfo __near *>,0>>> std::_Tree<class std::_Tset_traits<class NvFaceInfo __near *,struct std::less<class NvFaceInfo __near *>,class std::allocator<class NvFaceInfo __near *>,0>>::erase(class std::_Tree_const_iterator<class std::_Tree_val<class std::_Tset_traits<class NvFaceInfo __near *,struct std::less<class NvFaceInfo __near *>,class std::allocator<class NvFaceInfo __near *>,0>>>)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> > > *__thiscall std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0>>::erase(
        std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> > *this,
        std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> > > *result,
        std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> > > _Where)
{
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *Ptr; // ebx
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *Right; // edi
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *v5; // eax
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *Parent; // esi
  std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> > *v7; // ecx
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *Myhead; // eax
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *v9; // eax
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *v10; // ecx
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *v11; // ecx
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *v12; // ecx
  char Color; // cl
  std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> > *i; // ecx
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *Left; // eax
  unsigned int Mysize; // eax
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *_Erasednode; // [esp+10h] [ebp-8h]

  Ptr = _Where._Ptr;
  if ( _Where._Ptr->_Isnil != 0 )
    std::_Xout_of_range(_Message: "invalid map/set<T> iterator");
  _Erasednode = _Where._Ptr;
  std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0>>,std::_Iterator_base0>::operator++(this: &_Where);
  if ( Ptr->_Left->_Isnil != 0 )
  {
    Right = Ptr->_Right;
LABEL_8:
    Parent = Ptr->_Parent;
    if ( Right->_Isnil == 0 )
      Right->_Parent = Parent;
    v7 = this;
    Myhead = this->_Myhead;
    if ( Myhead->_Parent == Ptr )
    {
      Myhead->_Parent = Right;
    }
    else if ( Parent->_Left == Ptr )
    {
      Parent->_Left = Right;
    }
    else
    {
      Parent->_Right = Right;
    }
    if ( this->_Myhead->_Left == Ptr )
    {
      if ( Right->_Isnil != 0 )
      {
        v9 = Parent;
      }
      else
      {
        v9 = std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0>>::_Min(_Pnode: Right);
        v7 = this;
      }
      v7->_Myhead->_Left = v9;
    }
    v10 = v7->_Myhead;
    if ( v10->_Right == Ptr )
    {
      if ( Right->_Isnil != 0 )
        v10->_Right = Parent;
      else
        v10->_Right = std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0>>::_Max(_Pnode: Right);
    }
    goto LABEL_35;
  }
  if ( Ptr->_Right->_Isnil != 0 )
  {
    Right = Ptr->_Left;
    goto LABEL_8;
  }
  v5 = _Where._Ptr;
  Right = _Where._Ptr->_Right;
  if ( _Where._Ptr == Ptr )
    goto LABEL_8;
  Ptr->_Left->_Parent = _Where._Ptr;
  v5->_Left = Ptr->_Left;
  if ( v5 == Ptr->_Right )
  {
    Parent = v5;
  }
  else
  {
    Parent = v5->_Parent;
    if ( Right->_Isnil == 0 )
      Right->_Parent = Parent;
    Parent->_Left = Right;
    v5->_Right = Ptr->_Right;
    Ptr->_Right->_Parent = v5;
  }
  v11 = this->_Myhead;
  if ( v11->_Parent == Ptr )
  {
    v11->_Parent = v5;
  }
  else
  {
    v12 = Ptr->_Parent;
    if ( v12->_Left == Ptr )
      v12->_Left = v5;
    else
      v12->_Right = v5;
  }
  v5->_Parent = Ptr->_Parent;
  Color = v5->_Color;
  v5->_Color = Ptr->_Color;
  Ptr->_Color = Color;
LABEL_35:
  if ( _Erasednode->_Color == 1 )
  {
    for ( i = this; Right != i->_Myhead->_Parent; Parent = Parent->_Parent )
    {
      if ( Right->_Color != 1 )
        break;
      Left = Parent->_Left;
      if ( Right == Parent->_Left )
      {
        Left = Parent->_Right;
        if ( Left->_Color == 0 )
        {
          Left->_Color = 1;
          Parent->_Color = 0;
          std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0>>::_Lrotate(
            this: i,
            _Wherenode: Parent);
          Left = Parent->_Right;
          i = this;
        }
        if ( Left->_Isnil != 0 )
          goto LABEL_53;
        if ( Left->_Left->_Color != 1 || Left->_Right->_Color != 1 )
        {
          if ( Left->_Right->_Color == 1 )
          {
            Left->_Left->_Color = 1;
            Left->_Color = 0;
            std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0>>::_Rrotate(
              this: i,
              _Wherenode: Left);
            Left = Parent->_Right;
            i = this;
          }
          Left->_Color = Parent->_Color;
          Parent->_Color = 1;
          Left->_Right->_Color = 1;
          std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0>>::_Lrotate(
            this: i,
            _Wherenode: Parent);
          break;
        }
      }
      else
      {
        if ( Left->_Color == 0 )
        {
          Left->_Color = 1;
          Parent->_Color = 0;
          std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0>>::_Rrotate(
            this: i,
            _Wherenode: Parent);
          Left = Parent->_Left;
          i = this;
        }
        if ( Left->_Isnil != 0 )
          goto LABEL_53;
        if ( Left->_Right->_Color != 1 || Left->_Left->_Color != 1 )
        {
          if ( Left->_Left->_Color == 1 )
          {
            Left->_Right->_Color = 1;
            Left->_Color = 0;
            std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0>>::_Lrotate(
              this: i,
              _Wherenode: Left);
            Left = Parent->_Left;
            i = this;
          }
          Left->_Color = Parent->_Color;
          Parent->_Color = 1;
          Left->_Left->_Color = 1;
          std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0>>::_Rrotate(
            this: i,
            _Wherenode: Parent);
          break;
        }
      }
      Left->_Color = 0;
LABEL_53:
      Right = Parent;
    }
    Right->_Color = 1;
  }
  free(pMem: _Erasednode);
  Mysize = this->_Mysize;
  if ( Mysize != 0 )
    this->_Mysize = Mysize - 1;
  result->_Ptr = _Where._Ptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005B0350
// Name: protected: void std::_Tree<class std::_Tset_traits<class NvFaceInfo __near *,struct std::less<class NvFaceInfo __near *>,class std::allocator<class NvFaceInfo __near *>,0>>::_Erase(struct std::_Tree_nod<class std::_Tset_traits<class NvFaceInfo __near *,struct std::less<class NvFaceInfo __near *>,class std::allocator<class NvFaceInfo __near *>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0>>::_Erase(
        std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> > *this,
        std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *_Rootnode)
{
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *v2; // edi
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *i; // esi

  v2 = _Rootnode;
  for ( i = _Rootnode; i->_Isnil == 0; v2 = i )
  {
    std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0>>::_Erase(
      this,
      _Rootnode: i->_Right);
    i = i->_Left;
    free(pMem: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005B0390
// Name: public: struct std::pair<class std::_Tree_const_iterator<class std::_Tree_val<class std::_Tset_traits<class NvFaceInfo __near *,struct std::less<class NvFaceInfo __near *>,class std::allocator<class NvFaceInfo __near *>,0>>>,bool> std::_Tree<class std::_Tset_traits<class NvFaceInfo __near *,struct std::less<class NvFaceInfo __near *>,class std::allocator<class NvFaceInfo __near *>,0>>::_Linsert(struct std::_Tree_nod<class std::_Tset_traits<class NvFaceInfo __near *,struct std::less<class NvFaceInfo __near *>,class std::allocator<class NvFaceInfo __near *>,0>>::_Node __near *,bool)
// Source: json
//------------------------------------------------------------------------------
std::pair<std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> > >,bool> *__thiscall std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0>>::_Linsert(
        std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> > *this,
        std::pair<std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> > >,bool> *result,
        std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *_Node,
        std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> > > _Leftish)
{
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *v4; // edx
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *Myhead; // ecx
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *Parent; // eax
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *v8; // esi
  bool v9; // cl
  NvFaceInfo *Myval; // edi
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *Ptr; // edi
  bool _Addleft; // [esp+Ch] [ebp-4h]

  v4 = _Node;
  Myhead = this->_Myhead;
  Parent = Myhead->_Parent;
  v8 = Myhead;
  v9 = true;
  _Addleft = true;
  if ( Parent->_Isnil == 0 )
  {
    Myval = _Node->_Myval;
    do
    {
      v8 = Parent;
      if ( LOBYTE(_Leftish._Ptr) != 0 )
        v9 = Parent->_Myval >= Myval;
      else
        v9 = Myval < Parent->_Myval;
      _Addleft = v9;
      if ( v9 )
        Parent = Parent->_Left;
      else
        Parent = Parent->_Right;
    }
    while ( Parent->_Isnil == 0 );
  }
  Ptr = v8;
  _Leftish._Ptr = v8;
  if ( v9 )
  {
    if ( v8 == this->_Myhead->_Left )
    {
      result->first = (std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> > >)std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0>>::_Insert(this, result: &_Leftish, _Addleft: true, _Wherenode: v8, _Newnode: _Node)->_Ptr;
      result->second = true;
      return result;
    }
    std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0>>,std::_Iterator_base0>::operator--(this: &_Leftish);
    Ptr = _Leftish._Ptr;
    v4 = _Node;
  }
  if ( Ptr->_Myval >= v4->_Myval )
  {
    free(pMem: v4);
    result->first._Ptr = Ptr;
    result->second = false;
  }
  else
  {
    result->first = (std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> > >)std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0>>::_Insert(this, result: &_Leftish, _Addleft, _Wherenode: v8, _Newnode: v4)->_Ptr;
    result->second = true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005B0470
// Name: public: NvStripifier::NvStripifier(void)
// Source: json
//------------------------------------------------------------------------------
NvStripifier *__thiscall NvStripifier::NvStripifier(NvStripifier *this)
{
  this->indices._Myfirst = nullptr;
  this->indices._Mylast = nullptr;
  this->indices._Myend = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005B0480
// Name: public: NvStripifier::~NvStripifier(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NvStripifier::~NvStripifier(NvStripifier *this)
{
  if ( this->indices._Myfirst != nullptr )
    free(pMem: this->indices._Myfirst);
  this->indices._Myfirst = nullptr;
  this->indices._Mylast = nullptr;
  this->indices._Myend = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x005B06B0
// Name: public: void std::_Tree<class std::_Tset_traits<class NvFaceInfo __near *,struct std::less<class NvFaceInfo __near *>,class std::allocator<class NvFaceInfo __near *>,0>>::clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0>>::clear(
        std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> > *this)
{
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *Parent; // ebx
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *i; // esi

  Parent = this->_Myhead->_Parent;
  for ( i = Parent; i->_Isnil == 0; Parent = i )
  {
    std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0>>::_Erase(
      this,
      _Rootnode: i->_Right);
    i = i->_Left;
    free(pMem: Parent);
  }
  this->_Myhead->_Parent = this->_Myhead;
  this->_Myhead->_Left = this->_Myhead;
  this->_Myhead->_Right = this->_Myhead;
  this->_Mysize = 0;
}

//------------------------------------------------------------------------------
// Address: 0x005B0700
// Name: public: void NvStripInfo::Combine(class std::vector<class NvFaceInfo __near *,class std::allocator<class NvFaceInfo __near *>> const __near &,class std::vector<class NvFaceInfo __near *,class std::allocator<class NvFaceInfo __near *>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NvStripInfo::Combine(
        NvStripInfo *this,
        const std::vector<NvFaceInfo *> *forward,
        const std::vector<NvFaceInfo *> *backward)
{
  const std::vector<NvFaceInfo *> *v3; // eax
  int v4; // ebx
  const std::vector<NvFaceInfo *> *v6; // eax
  int v7; // ebx
  NvFaceInfo **v8; // esi
  NvFaceInfo **Mylast; // eax
  NvFaceInfo **v10; // edx
  NvFaceInfo **v11; // ecx
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // ecx
  unsigned int v15; // ecx
  NvFaceInfo **v16; // eax
  NvFaceInfo **Myend; // ecx
  NvFaceInfo **Myfirst; // edx
  unsigned int v19; // eax
  unsigned int v20; // eax
  unsigned int v21; // ecx
  unsigned int v22; // ecx
  NvFaceInfo **v23; // eax
  NvFaceInfo **v24; // esi
  NvFaceInfo **v25; // eax
  NvFaceInfo **v26; // edx
  NvFaceInfo **v27; // ecx
  int v28; // esi
  unsigned int v29; // eax
  unsigned int v30; // eax
  unsigned int v31; // ecx
  unsigned int v32; // ecx
  NvFaceInfo **v33; // eax
  NvFaceInfo **v34; // ecx
  NvFaceInfo **v35; // edx
  unsigned int v36; // eax
  unsigned int v37; // eax
  unsigned int v38; // ecx
  unsigned int v39; // ecx
  NvFaceInfo **v40; // eax
  int i; // [esp+10h] [ebp-4h]
  int ia; // [esp+10h] [ebp-4h]
  int ib; // [esp+10h] [ebp-4h]
  const std::vector<NvFaceInfo *> *backwarda; // [esp+20h] [ebp+Ch]

  v3 = backward;
  v4 = backward->_Mylast - backward->_Myfirst - 1;
  i = v4;
  if ( v4 >= 0 )
  {
    while ( 1 )
    {
      v8 = &v3->_Myfirst[v4];
      Mylast = this->m_faces._Mylast;
      if ( v8 >= Mylast || (v10 = this->m_faces._Myfirst) > v8 )
      {
        Myend = this->m_faces._Myend;
        if ( Mylast == Myend )
        {
          Myfirst = this->m_faces._Myfirst;
          v19 = Mylast - Myfirst;
          if ( v19 > 0x3FFFFFFE )
LABEL_31:
            std::_Xlength_error(_Message: "vector<T> too long");
          v20 = v19 + 1;
          v21 = Myend - Myfirst;
          if ( v20 > v21 )
          {
            if ( 0x3FFFFFFF - (v21 >> 1) >= v21 )
              v22 = (v21 >> 1) + v21;
            else
              v22 = 0;
            if ( v22 < v20 )
              v22 = v20;
            std::vector<int>::reserve(this: (std::vector<int> *)&this->m_faces, _Count: v22);
            v4 = i;
          }
        }
        v23 = this->m_faces._Mylast;
        if ( v23 != nullptr )
          *v23 = *v8;
      }
      else
      {
        v11 = this->m_faces._Myend;
        ib = v8 - v10;
        if ( Mylast == v11 )
        {
          v12 = Mylast - v10;
          if ( v12 > 0x3FFFFFFE )
            goto LABEL_31;
          v13 = v12 + 1;
          v14 = v11 - v10;
          if ( v13 > v14 )
          {
            if ( 0x3FFFFFFF - (v14 >> 1) >= v14 )
              v15 = (v14 >> 1) + v14;
            else
              v15 = 0;
            if ( v15 < v13 )
              v15 = v13;
            std::vector<int>::reserve(this: (std::vector<int> *)&this->m_faces, _Count: v15);
          }
        }
        v16 = this->m_faces._Mylast;
        if ( v16 != nullptr )
          *v16 = this->m_faces._Myfirst[ib];
      }
      ++this->m_faces._Mylast;
      i = --v4;
      if ( v4 < 0 )
        break;
      v3 = backward;
    }
  }
  v6 = forward;
  backwarda = nullptr;
  v7 = forward->_Mylast - forward->_Myfirst;
  ia = v7;
  if ( v7 > 0 )
  {
    while ( 1 )
    {
      v24 = &v6->_Myfirst[(_DWORD)backwarda];
      v25 = this->m_faces._Mylast;
      if ( v24 >= v25 || (v26 = this->m_faces._Myfirst) > v24 )
      {
        v34 = this->m_faces._Myend;
        if ( v25 == v34 )
        {
          v35 = this->m_faces._Myfirst;
          v36 = v25 - v35;
          if ( v36 > 0x3FFFFFFE )
            goto LABEL_31;
          v37 = v36 + 1;
          v38 = v34 - v35;
          if ( v37 > v38 )
          {
            if ( 0x3FFFFFFF - (v38 >> 1) >= v38 )
              v39 = (v38 >> 1) + v38;
            else
              v39 = 0;
            if ( v39 < v37 )
              v39 = v37;
            std::vector<int>::reserve(this: (std::vector<int> *)&this->m_faces, _Count: v39);
            v7 = ia;
          }
        }
        v40 = this->m_faces._Mylast;
        if ( v40 != nullptr )
          *v40 = *v24;
      }
      else
      {
        v27 = this->m_faces._Myend;
        v28 = v24 - v26;
        if ( v25 == v27 )
        {
          v29 = v25 - v26;
          if ( v29 > 0x3FFFFFFE )
            goto LABEL_31;
          v30 = v29 + 1;
          v31 = v27 - v26;
          if ( v30 > v31 )
          {
            if ( 0x3FFFFFFF - (v31 >> 1) >= v31 )
              v32 = (v31 >> 1) + v31;
            else
              v32 = 0;
            if ( v32 < v30 )
              v32 = v30;
            std::vector<int>::reserve(this: (std::vector<int> *)&this->m_faces, _Count: v32);
            v7 = ia;
          }
        }
        v33 = this->m_faces._Mylast;
        if ( v33 != nullptr )
          *v33 = this->m_faces._Myfirst[v28];
      }
      ++this->m_faces._Mylast;
      backwarda = (const std::vector<NvFaceInfo *> *)((char *)backwarda + 1);
      if ( (int)backwarda >= v7 )
        break;
      v6 = forward;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005B0A10
// Name: public: class std::_Tree_const_iterator<class std::_Tree_val<class std::_Tset_traits<class NvFaceInfo __near *,struct std::less<class NvFaceInfo __near *>,class std::allocator<class NvFaceInfo __near *>,0>>> std::_Tree<class std::_Tset_traits<class NvFaceInfo __near *,struct std::less<class NvFaceInfo __near *>,class std::allocator<class NvFaceInfo __near *>,0>>::erase(class std::_Tree_const_iterator<class std::_Tree_val<class std::_Tset_traits<class NvFaceInfo __near *,struct std::less<class NvFaceInfo __near *>,class std::allocator<class NvFaceInfo __near *>,0>>>,class std::_Tree_const_iterator<class std::_Tree_val<class std::_Tset_traits<class NvFaceInfo __near *,struct std::less<class NvFaceInfo __near *>,class std::allocator<class NvFaceInfo __near *>,0>>>)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> > > *__thiscall std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0>>::erase(
        std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> > *this,
        std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> > > *result,
        std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> > > _First,
        std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> > > _Last)
{
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *Myhead; // eax
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *Ptr; // ecx
  std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> > > v8; // edx
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *Right; // eax
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *v10; // ecx
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *j; // eax
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *i; // eax
  std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> > > v13; // [esp+4h] [ebp-4h] BYREF

  Myhead = this->_Myhead;
  Ptr = _First._Ptr;
  if ( _First._Ptr == Myhead->_Left && _Last._Ptr == Myhead )
  {
    std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0>>::clear(this);
    result->_Ptr = this->_Myhead->_Left;
    return result;
  }
  else
  {
    for ( ; _First._Ptr != _Last._Ptr; Ptr = _First._Ptr )
    {
      v8._Ptr = Ptr;
      if ( Ptr->_Isnil == 0 )
      {
        Right = Ptr->_Right;
        if ( Right->_Isnil != 0 )
        {
          for ( i = Ptr->_Parent; i->_Isnil == 0; i = i->_Parent )
          {
            if ( Ptr != i->_Right )
              break;
            Ptr = i;
          }
          _First._Ptr = i;
        }
        else
        {
          v10 = Ptr->_Right;
          for ( j = Right->_Left; j->_Isnil == 0; j = j->_Left )
            v10 = j;
          _First._Ptr = v10;
        }
      }
      std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0>>::erase(
        this,
        result: &v13,
        _Where: v8);
    }
    result->_Ptr = Ptr;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005B0AB0
// Name: protected: void NvStripifier::BuildStripifyInfo(class std::vector<class NvFaceInfo __near *,class std::allocator<class NvFaceInfo __near *>> __near &,class std::vector<class NvEdgeInfo __near *,class std::allocator<class NvEdgeInfo __near *>> __near &,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NvStripifier::BuildStripifyInfo(
        NvStripifier *this,
        std::vector<NvFaceInfo *> *faceInfos,
        std::vector<NvEdgeInfo *> *edgeInfos,
        const unsigned __int16 maxIndex)
{
  __int64 v4; // rax
  signed int v5; // edi
  int v6; // eax
  int v7; // edi
  int v8; // esi
  int v9; // ebx
  NvFaceInfo *v10; // eax
  NvEdgeInfo *v11; // eax
  int m_v0; // ecx
  NvEdgeInfo *v13; // eax
  NvEdgeInfo *v14; // eax
  int v15; // ecx
  NvFaceInfo *v16; // edx
  NvEdgeInfo *v17; // eax
  NvEdgeInfo *v18; // esi
  int v19; // eax
  NvFaceInfo *v20; // edx
  NvEdgeInfo *v21; // eax
  NvFaceInfo *v22; // edx
  NvFaceInfo **Mylast; // eax
  NvFaceInfo **Myfirst; // edx
  NvFaceInfo **Myend; // ecx
  int v26; // esi
  unsigned int v27; // eax
  unsigned int v28; // eax
  unsigned int v29; // ecx
  unsigned int v30; // ecx
  NvFaceInfo **v31; // eax
  NvFaceInfo **v32; // edi
  unsigned int v33; // ecx
  NvFaceInfo **v34; // edx
  NvFaceInfo *v35; // eax
  std::vector<NvFaceInfo *> *v36; // ecx
  NvFaceInfo **v37; // eax
  std::vector<NvFaceInfo *> *v38; // ecx
  NvFaceInfo **v39; // eax
  NvFaceInfo **v40; // eax
  std::vector<NvFaceInfo *> *v41; // esi
  NvFaceInfo **v42; // ecx
  unsigned int v43; // eax
  unsigned int v44; // eax
  unsigned int v45; // ecx
  unsigned int v46; // ecx
  NvFaceInfo **v47; // eax
  signed int v48; // [esp+Ch] [ebp-28h]
  int i; // [esp+1Ch] [ebp-18h]
  int index; // [esp+20h] [ebp-14h]
  NvEdgeInfo *edgeInfo12; // [esp+24h] [ebp-10h]
  NvEdgeInfo *edgeInfo01; // [esp+28h] [ebp-Ch]
  NvFaceInfo *faceInfo; // [esp+2Ch] [ebp-8h] BYREF
  bool bFaceUpdated[4]; // [esp+30h] [ebp-4h] BYREF
  char maxIndex_3; // [esp+47h] [ebp+13h]

  v4 = 1431655766LL * (this->indices._Mylast - this->indices._Myfirst);
  v5 = HIDWORD(v4) + (HIDWORD(v4) >> 31);
  v48 = v5;
  std::vector<int>::reserve(this: (std::vector<int> *)faceInfos, _Count: v5);
  std::vector<NvEdgeInfo *>::resize(this: edgeInfos, _Newsize: maxIndex + 1);
  v6 = 0;
  if ( maxIndex != -1 )
  {
    do
      edgeInfos->_Myfirst[v6++] = nullptr;
    while ( v6 < maxIndex + 1 );
  }
  index = 0;
  i = 0;
  if ( v5 <= 0 )
    return;
  do
  {
    v7 = this->indices._Myfirst[index];
    v8 = this->indices._Myfirst[index + 1];
    v9 = this->indices._Myfirst[index + 2];
    maxIndex_3 = 1;
    memset(bFaceUpdated, 0, 3);
    index += 3;
    if ( (_WORD)v7 == (_WORD)v8 || (_WORD)v7 == (_WORD)v9 || (_WORD)v8 == (_WORD)v9 )
      goto LABEL_102;
    v10 = (NvFaceInfo *)MemAlloc_Alloc(nSize: 0x18u);
    if ( v10 != nullptr )
    {
      v10->m_v0 = v7;
      v10->m_v1 = v8;
      v10->m_v2 = v9;
      v10->m_stripId = -1;
      v10->m_testStripId = -1;
      v10->m_experimentId = -1;
      faceInfo = v10;
    }
    else
    {
      faceInfo = nullptr;
    }
    v11 = edgeInfos->_Myfirst[v7];
    while ( v11 != nullptr )
    {
      m_v0 = v11->m_v0;
      if ( m_v0 == v7 )
      {
        if ( v11->m_v1 == v8 )
          goto LABEL_19;
        v11 = v11->m_nextV0;
      }
      else
      {
        if ( m_v0 == v8 )
        {
LABEL_19:
          edgeInfo01 = v11;
          if ( v11->m_face1 == nullptr )
          {
            v11->m_face1 = faceInfo;
            bFaceUpdated[0] = true;
          }
          goto LABEL_21;
        }
        v11 = v11->m_nextV1;
      }
    }
    maxIndex_3 = 0;
    v13 = (NvEdgeInfo *)MemAlloc_Alloc(nSize: 0x1Cu);
    if ( v13 != nullptr )
    {
      v13->m_v0 = v7;
      v13->m_v1 = v8;
      v13->m_face0 = nullptr;
      v13->m_face1 = nullptr;
      v13->m_nextV0 = nullptr;
      v13->m_nextV1 = nullptr;
      v13->m_refCount = 2;
      edgeInfo01 = v13;
    }
    else
    {
      edgeInfo01 = nullptr;
      v13 = nullptr;
    }
    v13->m_nextV0 = edgeInfos->_Myfirst[v7];
    v13->m_nextV1 = edgeInfos->_Myfirst[v8];
    edgeInfos->_Myfirst[v7] = v13;
    v16 = faceInfo;
    edgeInfos->_Myfirst[v8] = v13;
    v13->m_face0 = v16;
LABEL_21:
    v14 = edgeInfos->_Myfirst[v8];
    if ( v14 == nullptr )
    {
LABEL_30:
      maxIndex_3 = 0;
      v17 = (NvEdgeInfo *)MemAlloc_Alloc(nSize: 0x1Cu);
      if ( v17 != nullptr )
      {
        v17->m_v0 = v8;
        v17->m_v1 = v9;
        v17->m_face0 = nullptr;
        v17->m_face1 = nullptr;
        v17->m_nextV0 = nullptr;
        v17->m_nextV1 = nullptr;
        v17->m_refCount = 2;
        edgeInfo12 = v17;
      }
      else
      {
        edgeInfo12 = nullptr;
        v17 = nullptr;
      }
      v17->m_nextV0 = edgeInfos->_Myfirst[v8];
      v17->m_nextV1 = edgeInfos->_Myfirst[v9];
      edgeInfos->_Myfirst[v8] = v17;
      v20 = faceInfo;
      edgeInfos->_Myfirst[v9] = v17;
      v17->m_face0 = v20;
      goto LABEL_34;
    }
    while ( 1 )
    {
      v15 = v14->m_v0;
      if ( v15 != v8 )
        break;
      if ( v14->m_v1 == v9 )
        goto LABEL_32;
      v14 = v14->m_nextV0;
LABEL_29:
      if ( v14 == nullptr )
        goto LABEL_30;
    }
    if ( v15 != v9 )
    {
      v14 = v14->m_nextV1;
      goto LABEL_29;
    }
LABEL_32:
    edgeInfo12 = v14;
    if ( v14->m_face1 == nullptr )
    {
      v14->m_face1 = faceInfo;
      bFaceUpdated[1] = true;
    }
LABEL_34:
    v18 = edgeInfos->_Myfirst[v9];
    if ( v18 == nullptr )
    {
LABEL_43:
      v21 = (NvEdgeInfo *)MemAlloc_Alloc(nSize: 0x1Cu);
      if ( v21 != nullptr )
      {
        v21->m_v0 = v9;
        v21->m_v1 = v7;
        v21->m_face0 = nullptr;
        v21->m_face1 = nullptr;
        v21->m_nextV0 = nullptr;
        v21->m_nextV1 = nullptr;
        v21->m_refCount = 2;
      }
      else
      {
        v21 = nullptr;
      }
      v21->m_nextV0 = edgeInfos->_Myfirst[v9];
      v21->m_nextV1 = edgeInfos->_Myfirst[v7];
      edgeInfos->_Myfirst[v9] = v21;
      v22 = faceInfo;
      edgeInfos->_Myfirst[v7] = v21;
      v21->m_face0 = v22;
LABEL_47:
      Mylast = faceInfos->_Mylast;
      if ( &faceInfo < Mylast )
      {
        Myfirst = faceInfos->_Myfirst;
        if ( faceInfos->_Myfirst <= &faceInfo )
        {
          Myend = faceInfos->_Myend;
          v26 = &faceInfo - Myfirst;
          if ( Mylast != Myend )
          {
LABEL_87:
            v40 = faceInfos->_Mylast;
            if ( v40 != nullptr )
              *v40 = faceInfos->_Myfirst[v26];
            ++faceInfos->_Mylast;
            goto LABEL_102;
          }
          v27 = Mylast - Myfirst;
          if ( v27 <= 0x3FFFFFFE )
          {
            v28 = v27 + 1;
            v29 = Myend - Myfirst;
            if ( v28 > v29 )
            {
              if ( 0x3FFFFFFF - (v29 >> 1) >= v29 )
                v30 = (v29 >> 1) + v29;
              else
                v30 = 0;
              if ( v30 < v28 )
                v30 = v28;
              std::vector<int>::reserve(this: (std::vector<int> *)faceInfos, _Count: v30);
            }
            goto LABEL_87;
          }
LABEL_104:
          std::_Xlength_error(_Message: "vector<T> too long");
        }
      }
      v41 = faceInfos;
      v42 = faceInfos->_Myend;
      if ( Mylast == v42 )
      {
        v43 = Mylast - faceInfos->_Myfirst;
        if ( v43 > 0x3FFFFFFE )
          goto LABEL_104;
        v44 = v43 + 1;
        v45 = v42 - faceInfos->_Myfirst;
        if ( v44 > v45 )
        {
          if ( 0x3FFFFFFF - (v45 >> 1) >= v45 )
            v46 = (v45 >> 1) + v45;
          else
            v46 = 0;
          if ( v46 < v44 )
            v46 = v44;
          std::vector<int>::reserve(this: (std::vector<int> *)faceInfos, _Count: v46);
          v41 = faceInfos;
        }
      }
      v47 = v41->_Mylast;
      if ( v47 != nullptr )
        *v47 = faceInfo;
      ++v41->_Mylast;
      goto LABEL_102;
    }
    while ( 2 )
    {
      v19 = v18->m_v0;
      if ( v19 == v9 )
      {
        if ( v18->m_v1 == v7 )
          goto LABEL_54;
        v18 = v18->m_nextV0;
LABEL_42:
        if ( v18 == nullptr )
          goto LABEL_43;
        continue;
      }
      break;
    }
    if ( v19 != v7 )
    {
      v18 = v18->m_nextV1;
      goto LABEL_42;
    }
LABEL_54:
    if ( v18->m_face1 == nullptr )
    {
      v18->m_face1 = faceInfo;
      bFaceUpdated[2] = true;
    }
    if ( maxIndex_3 == 0 )
      goto LABEL_47;
    v31 = faceInfos->_Mylast;
    v32 = faceInfos->_Myfirst;
    v33 = 0;
    if ( v31 - faceInfos->_Myfirst == 0 )
    {
LABEL_65:
      if ( &faceInfo >= v31 || v32 > &faceInfo )
      {
        v38 = faceInfos;
        if ( v31 == faceInfos->_Myend )
        {
          std::vector<NvFaceInfo *>::_Reserve(this: (std::vector<int> *)faceInfos, _Count: 1u);
          v38 = faceInfos;
        }
        v39 = v38->_Mylast;
        if ( v39 != nullptr )
          *v39 = faceInfo;
        ++v38->_Mylast;
      }
      else
      {
        v36 = faceInfos;
        if ( v31 == faceInfos->_Myend )
        {
          std::vector<NvFaceInfo *>::_Reserve(this: (std::vector<int> *)faceInfos, _Count: 1u);
          v36 = faceInfos;
        }
        v37 = v36->_Mylast;
        if ( v37 != nullptr )
          *v37 = v36->_Myfirst[&faceInfo - v32];
        ++v36->_Mylast;
      }
      goto LABEL_102;
    }
    v34 = faceInfos->_Myfirst;
    while ( 2 )
    {
      v35 = *v34;
      if ( (*v34)->m_v0 != faceInfo->m_v0 )
      {
LABEL_63:
        ++v33;
        ++v34;
        if ( v33 >= faceInfos->_Mylast - faceInfos->_Myfirst )
        {
          v31 = faceInfos->_Mylast;
          goto LABEL_65;
        }
        continue;
      }
      break;
    }
    if ( v35->m_v1 != faceInfo->m_v1 || v35->m_v2 != faceInfo->m_v2 )
    {
      v32 = faceInfos->_Myfirst;
      goto LABEL_63;
    }
    free(pMem: faceInfo);
    if ( bFaceUpdated[0] )
      edgeInfo01->m_face1 = nullptr;
    if ( bFaceUpdated[1] )
      edgeInfo12->m_face1 = nullptr;
    if ( bFaceUpdated[2] )
      v18->m_face1 = nullptr;
LABEL_102:
    ++i;
  }
  while ( i < v48 );
}

//------------------------------------------------------------------------------
// Address: 0x005B0F60
// Name: public: void NvStripInfo::Build(class std::vector<class NvEdgeInfo __near *,class std::allocator<class NvEdgeInfo __near *>> __near &,class std::vector<class NvFaceInfo __near *,class std::allocator<class NvFaceInfo __near *>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NvStripInfo::Build(
        NvStripInfo *this,
        std::vector<NvEdgeInfo *> *edgeInfos,
        std::vector<NvFaceInfo *> *faceInfos)
{
  int m_experimentId; // ecx
  NvFaceInfo *m_startFace; // eax
  bool m_toV1; // cl
  NvEdgeInfo *m_startEdge; // eax
  int m_v0; // edx
  int m_v1; // esi
  int NextIndex; // edi
  NvFaceInfo *v11; // eax
  int v12; // ebx
  int m_stripId; // ecx
  int v14; // eax
  int v15; // eax
  NvEdgeInfo **Myfirst; // edx
  int v17; // esi
  NvEdgeInfo *v18; // eax
  int v19; // ecx
  NvFaceInfo *v20; // eax
  int v21; // ecx
  NvEdgeInfo *v22; // eax
  int v23; // ecx
  NvFaceInfo *m_face1; // eax
  int v25; // ecx
  NvFaceInfo *v26; // eax
  NvFaceInfo *v27; // edi
  NvFaceInfo **v28; // eax
  int v29; // esi
  NvStripInfo *v30; // ecx
  int v31; // eax
  unsigned __int16 *v32; // eax
  unsigned __int16 *v33; // edx
  int v34; // esi
  NvFaceInfo **Mylast; // edx
  NvFaceInfo **v36; // edx
  NvFaceInfo **v37; // edi
  int v38; // esi
  unsigned int v39; // eax
  unsigned int v40; // eax
  unsigned int v41; // ecx
  unsigned int v42; // ecx
  unsigned int v43; // eax
  unsigned int v44; // eax
  unsigned int v45; // ecx
  unsigned int v46; // ecx
  NvStripInfo *v47; // ecx
  int v48; // eax
  NvFaceInfo *v49; // edx
  NvFaceInfo *v50; // eax
  unsigned __int16 v51; // si
  unsigned __int16 *v52; // edi
  unsigned __int16 *v53; // edx
  int v54; // esi
  unsigned int v55; // eax
  unsigned int v56; // eax
  unsigned int v57; // ecx
  unsigned int v58; // ecx
  unsigned int v59; // eax
  unsigned int v60; // eax
  unsigned int v61; // ecx
  unsigned int v62; // ecx
  NvFaceInfo *v63; // eax
  int v64; // ecx
  NvFaceInfo **v65; // edi
  NvFaceInfo **Myend; // eax
  unsigned int v67; // ebx
  NvFaceInfo **v68; // ecx
  NvFaceInfo **v69; // edx
  int v70; // esi
  unsigned int v71; // eax
  unsigned int v72; // eax
  unsigned int v73; // ecx
  unsigned int v74; // ecx
  unsigned int v75; // eax
  unsigned int v76; // eax
  unsigned int v77; // ecx
  unsigned int v78; // ecx
  unsigned __int16 v79; // si
  unsigned __int16 *v80; // edi
  unsigned __int16 *v81; // edx
  int v82; // esi
  unsigned int v83; // eax
  unsigned int v84; // eax
  unsigned int v85; // ecx
  unsigned int v86; // ecx
  unsigned int v87; // eax
  unsigned int v88; // eax
  unsigned int v89; // ecx
  unsigned int v90; // ecx
  int v91; // ebx
  unsigned __int16 *v92; // edx
  int v93; // esi
  unsigned int v94; // eax
  unsigned int v95; // eax
  unsigned int v96; // ecx
  unsigned int v97; // ecx
  unsigned int v98; // eax
  unsigned int v99; // eax
  unsigned int v100; // ecx
  unsigned int v101; // ecx
  int v102; // edi
  unsigned __int16 *v103; // edx
  unsigned __int16 *v104; // ecx
  int v105; // esi
  unsigned int v106; // eax
  unsigned int v107; // eax
  unsigned int v108; // ecx
  unsigned int v109; // ecx
  unsigned int v110; // eax
  unsigned int v111; // eax
  unsigned int v112; // ecx
  unsigned int v113; // ecx
  NvFaceInfo *v114; // eax
  int v115; // ecx
  NvFaceInfo *v116; // esi
  int v117; // eax
  int v118; // edi
  NvFaceInfo *v119; // ebx
  NvEdgeInfo **v120; // edx
  NvEdgeInfo *v121; // eax
  NvFaceInfo *v122; // ecx
  NvFaceInfo *m_face0; // eax
  int v124; // ecx
  NvEdgeInfo *v125; // eax
  NvFaceInfo *v126; // ecx
  NvFaceInfo *v127; // eax
  int v128; // ecx
  NvFaceInfo **v129; // eax
  NvFaceInfo *v130; // ecx
  int v131; // edx
  NvFaceInfo *v132; // edi
  NvFaceInfo **v133; // edx
  NvFaceInfo **v134; // edx
  NvFaceInfo **v135; // ebx
  int v136; // esi
  unsigned int v137; // eax
  unsigned int v138; // eax
  unsigned int v139; // ecx
  unsigned int v140; // ecx
  unsigned int v141; // eax
  unsigned int v142; // eax
  unsigned int v143; // ecx
  unsigned int v144; // ecx
  NvStripInfo *v145; // edx
  int v146; // eax
  unsigned __int16 *v147; // edi
  unsigned __int16 *v148; // ebx
  int v149; // esi
  unsigned int v150; // eax
  unsigned int v151; // eax
  unsigned int v152; // ecx
  unsigned int v153; // ecx
  unsigned int v154; // eax
  unsigned int v155; // eax
  unsigned int v156; // ecx
  unsigned int v157; // ecx
  NvFaceInfo *v158; // ecx
  unsigned __int16 *v159; // edi
  NvFaceInfo **v160; // eax
  NvFaceInfo **v161; // edx
  int v162; // esi
  unsigned int v163; // eax
  unsigned int v164; // eax
  unsigned int v165; // ecx
  unsigned int v166; // ecx
  unsigned int v167; // eax
  unsigned int v168; // eax
  unsigned int v169; // ecx
  unsigned int v170; // ecx
  NvFaceInfo **v171; // edx
  int v172; // esi
  unsigned int v173; // eax
  unsigned int v174; // eax
  unsigned int v175; // ecx
  unsigned int v176; // ecx
  unsigned int v177; // eax
  unsigned int v178; // eax
  unsigned int v179; // ecx
  unsigned int v180; // ecx
  NvFaceInfo *v181; // ecx
  NvStripInfo *v182; // edx
  int v183; // eax
  int v184; // edx
  int v185; // esi
  unsigned int v186; // eax
  unsigned int v187; // eax
  unsigned int v188; // ecx
  unsigned int v189; // ecx
  unsigned int v190; // eax
  unsigned int v191; // eax
  unsigned int v192; // ecx
  unsigned int v193; // ecx
  NvFaceInfo *v194; // eax
  int v195; // ecx
  std::vector<NvFaceInfo *> forwardFaces; // [esp+Ch] [ebp-60h] BYREF
  std::vector<NvFaceInfo *> backwardFaces; // [esp+1Ch] [ebp-50h] BYREF
  std::vector<NvFaceInfo *> tempAllFaces; // [esp+2Ch] [ebp-40h] BYREF
  std::vector<unsigned short> scratchIndices; // [esp+3Ch] [ebp-30h] BYREF
  int v2; // [esp+4Ch] [ebp-20h]
  int testnv0; // [esp+50h] [ebp-1Ch]
  int i; // [esp+54h] [ebp-18h] BYREF
  int v1; // [esp+58h] [ebp-14h] BYREF
  int testnv1; // [esp+5Ch] [ebp-10h] BYREF
  NvFaceInfo *tempFace; // [esp+60h] [ebp-Ch] BYREF
  NvStripInfo *v206; // [esp+64h] [ebp-8h]
  NvFaceInfo *nextFace; // [esp+68h] [ebp-4h] BYREF

  v206 = this;
  memset(&scratchIndices, 0, 12);
  memset(&forwardFaces, 0, 12);
  memset(&backwardFaces, 0, 12);
  std::vector<int>::push_back(this: (std::vector<int> *)&forwardFaces, _Val: (int *)this);
  m_experimentId = this->m_experimentId;
  m_startFace = this->m_startInfo.m_startFace;
  if ( m_experimentId < 0 )
  {
    m_startFace->m_experimentId = -1;
    m_startFace->m_stripId = this->m_stripId;
  }
  else
  {
    m_startFace->m_experimentId = m_experimentId;
    m_startFace->m_testStripId = this->m_stripId;
  }
  m_toV1 = this->m_startInfo.m_toV1;
  m_startEdge = this->m_startInfo.m_startEdge;
  if ( m_toV1 )
    m_v0 = m_startEdge->m_v0;
  else
    m_v0 = m_startEdge->m_v1;
  testnv0 = m_v0;
  if ( m_toV1 )
    m_v1 = m_startEdge->m_v1;
  else
    m_v1 = m_startEdge->m_v0;
  v1 = m_v1;
  i = (unsigned __int16)m_v0;
  std::vector<unsigned short>::push_back(this: &scratchIndices, _Val: (unsigned __int16 *)&i);
  i = (unsigned __int16)m_v1;
  std::vector<unsigned short>::push_back(this: &scratchIndices, _Val: (unsigned __int16 *)&i);
  NextIndex = NvStripifier::GetNextIndex(indices: &scratchIndices, face: v206->m_startInfo.m_startFace);
  i = (unsigned __int16)NextIndex;
  v2 = NextIndex;
  std::vector<unsigned short>::push_back(this: &scratchIndices, _Val: (unsigned __int16 *)&i);
  v11 = (NvFaceInfo *)edgeInfos->_Myfirst[m_v1];
  v12 = m_v1;
  while ( v11 != nullptr )
  {
    m_stripId = v11->m_stripId;
    if ( m_stripId == m_v1 )
    {
      if ( v11->m_testStripId == NextIndex )
        goto LABEL_18;
      v11 = (NvFaceInfo *)v11->m_experimentId;
    }
    else
    {
      if ( m_stripId == NextIndex )
        goto LABEL_18;
      v11 = (NvFaceInfo *)v11[1].m_v0;
    }
  }
  v11 = nullptr;
  if ( m_v1 != NextIndex )
  {
LABEL_18:
    if ( (NvFaceInfo *)v11->m_v1 == v206->m_startInfo.m_startFace )
      v11 = (NvFaceInfo *)v11->m_v2;
    else
      v11 = (NvFaceInfo *)v11->m_v1;
  }
  nextFace = v11;
  if ( v11 != nullptr )
  {
    while ( 1 )
    {
      if ( nextFace->m_stripId >= 0 )
        goto LABEL_148;
      v14 = v206->m_experimentId;
      if ( v14 >= 0 && nextFace->m_experimentId == v14 )
        goto LABEL_148;
      i = NextIndex;
      v15 = NvStripifier::GetNextIndex(indices: &scratchIndices, face: nextFace);
      Myfirst = edgeInfos->_Myfirst;
      v17 = v15;
      v18 = edgeInfos->_Myfirst[NextIndex];
      testnv1 = v17;
      while ( v18 != nullptr )
      {
        v19 = v18->m_v0;
        if ( v19 == NextIndex )
        {
          if ( v18->m_v1 == v17 )
            goto LABEL_33;
          v18 = v18->m_nextV0;
        }
        else
        {
          if ( v19 == v17 )
            goto LABEL_33;
          v18 = v18->m_nextV1;
        }
      }
      v18 = nullptr;
      if ( NextIndex == v17 )
        goto LABEL_41;
LABEL_33:
      v20 = v18->m_face0 == nextFace ? v18->m_face1 : v18->m_face0;
      if ( v20 == nullptr )
        break;
      if ( v20->m_stripId >= 0 )
        break;
      v21 = v206->m_experimentId;
      if ( v21 >= 0 && v20->m_experimentId == v21 )
        break;
LABEL_83:
      Mylast = forwardFaces._Mylast;
      if ( &nextFace >= forwardFaces._Mylast || forwardFaces._Myfirst > &nextFace )
      {
        if ( forwardFaces._Mylast == forwardFaces._Myend )
        {
          v43 = forwardFaces._Mylast - forwardFaces._Myfirst;
          if ( v43 > 0x3FFFFFFE )
            goto LABEL_181;
          v44 = v43 + 1;
          v45 = forwardFaces._Myend - forwardFaces._Myfirst;
          if ( v44 > v45 )
          {
            if ( 0x3FFFFFFF - (v45 >> 1) >= v45 )
              v46 = (v45 >> 1) + v45;
            else
              v46 = 0;
            if ( v46 < v44 )
              v46 = v44;
            std::vector<int>::reserve(this: (std::vector<int> *)&forwardFaces, _Count: v46);
            Mylast = forwardFaces._Mylast;
          }
        }
        if ( Mylast != nullptr )
          *Mylast = nextFace;
        forwardFaces._Mylast = Mylast + 1;
      }
      else
      {
        v36 = forwardFaces._Myfirst;
        v37 = forwardFaces._Mylast;
        v38 = &nextFace - forwardFaces._Myfirst;
        if ( forwardFaces._Mylast == forwardFaces._Myend )
        {
          v39 = forwardFaces._Mylast - forwardFaces._Myfirst;
          if ( v39 > 0x3FFFFFFE )
            goto LABEL_181;
          v40 = v39 + 1;
          v41 = forwardFaces._Myend - forwardFaces._Myfirst;
          if ( v40 > v41 )
          {
            if ( 0x3FFFFFFF - (v41 >> 1) >= v41 )
              v42 = (v41 >> 1) + v41;
            else
              v42 = 0;
            if ( v42 < v40 )
              v42 = v40;
            std::vector<int>::reserve(this: (std::vector<int> *)&forwardFaces, _Count: v42);
            v37 = forwardFaces._Mylast;
            v36 = forwardFaces._Myfirst;
          }
        }
        if ( v37 != nullptr )
          *v37 = v36[v38];
        forwardFaces._Mylast = v37 + 1;
      }
      v47 = v206;
      v48 = v206->m_experimentId;
      if ( v48 < 0 )
      {
        v50 = nextFace;
        nextFace->m_experimentId = -1;
        v50->m_stripId = v47->m_stripId;
      }
      else
      {
        v49 = nextFace;
        nextFace->m_experimentId = v48;
        v49->m_testStripId = v47->m_stripId;
      }
      v51 = testnv1;
      v52 = scratchIndices._Mylast;
      v53 = scratchIndices._Myfirst;
      tempFace = (NvFaceInfo *)(unsigned __int16)testnv1;
      if ( (unsigned __int16 *)&tempFace >= scratchIndices._Mylast
        || scratchIndices._Myfirst > (unsigned __int16 *)&tempFace )
      {
        if ( scratchIndices._Mylast == scratchIndices._Myend )
        {
          v59 = scratchIndices._Mylast - scratchIndices._Myfirst;
          if ( v59 > 0x7FFFFFFE )
            goto LABEL_181;
          v60 = v59 + 1;
          v61 = scratchIndices._Myend - scratchIndices._Myfirst;
          if ( v60 > v61 )
          {
            if ( 0x7FFFFFFF - (v61 >> 1) >= v61 )
              v62 = (v61 >> 1) + v61;
            else
              v62 = 0;
            if ( v62 < v60 )
              v62 = v60;
            std::vector<unsigned short>::reserve(this: &scratchIndices, _Count: v62);
            v52 = scratchIndices._Mylast;
          }
        }
        if ( v52 != nullptr )
          *v52 = v51;
      }
      else
      {
        v54 = ((char *)&tempFace - (char *)scratchIndices._Myfirst) >> 1;
        if ( scratchIndices._Mylast == scratchIndices._Myend )
        {
          v55 = scratchIndices._Mylast - scratchIndices._Myfirst;
          if ( v55 > 0x7FFFFFFE )
            goto LABEL_181;
          v56 = v55 + 1;
          v57 = scratchIndices._Myend - scratchIndices._Myfirst;
          if ( v56 > v57 )
          {
            if ( 0x7FFFFFFF - (v57 >> 1) >= v57 )
              v58 = (v57 >> 1) + v57;
            else
              v58 = 0;
            if ( v58 < v56 )
              v58 = v56;
            std::vector<unsigned short>::reserve(this: &scratchIndices, _Count: v58);
            v52 = scratchIndices._Mylast;
            v53 = scratchIndices._Myfirst;
          }
        }
        if ( v52 != nullptr )
          *v52 = v53[v54];
      }
      v12 = i;
      v63 = (NvFaceInfo *)edgeInfos->_Myfirst[i];
      scratchIndices._Mylast = v52 + 1;
      NextIndex = testnv1;
      while ( v63 != nullptr )
      {
        v64 = v63->m_stripId;
        if ( v64 == i )
        {
          if ( v63->m_testStripId == testnv1 )
            goto LABEL_144;
          v63 = (NvFaceInfo *)v63->m_experimentId;
        }
        else
        {
          if ( v64 == testnv1 )
            goto LABEL_144;
          v63 = (NvFaceInfo *)v63[1].m_v0;
        }
      }
      v63 = nullptr;
      if ( i != testnv1 )
      {
LABEL_144:
        if ( (NvFaceInfo *)v63->m_v1 == nextFace )
          v63 = (NvFaceInfo *)v63->m_v2;
        else
          v63 = (NvFaceInfo *)v63->m_v1;
      }
      nextFace = v63;
      if ( v63 == nullptr )
        goto LABEL_148;
    }
    v17 = testnv1;
LABEL_41:
    v22 = Myfirst[v12];
    while ( v22 != nullptr )
    {
      v23 = v22->m_v0;
      if ( v23 == v12 )
      {
        if ( v22->m_v1 == v17 )
          goto LABEL_49;
        v22 = v22->m_nextV0;
      }
      else
      {
        if ( v23 == v17 )
          goto LABEL_49;
        v22 = v22->m_nextV1;
      }
    }
    v22 = nullptr;
    if ( v12 != v17 )
    {
LABEL_49:
      if ( v22->m_face0 == nextFace )
        m_face1 = v22->m_face1;
      else
        m_face1 = v22->m_face0;
      if ( m_face1 != nullptr && m_face1->m_stripId < 0 )
      {
        v25 = v206->m_experimentId;
        if ( v25 < 0 || m_face1->m_experimentId != v25 )
        {
          v26 = (NvFaceInfo *)MemAlloc_Alloc(nSize: 0x18u);
          if ( v26 != nullptr )
          {
            v26->m_v1 = NextIndex;
            v26->m_v0 = v12;
            v26->m_v2 = v12;
            v26->m_stripId = -1;
            v26->m_testStripId = -1;
            v26->m_experimentId = -1;
            v27 = v26;
          }
          else
          {
            v27 = nullptr;
          }
          v28 = forwardFaces._Mylast;
          tempFace = v27;
          if ( &tempFace >= forwardFaces._Mylast || forwardFaces._Myfirst > &tempFace )
          {
            if ( forwardFaces._Mylast == forwardFaces._Myend )
            {
              std::vector<NvFaceInfo *>::_Reserve(this: (std::vector<int> *)&forwardFaces, _Count: 1u);
              v28 = forwardFaces._Mylast;
            }
            if ( v28 != nullptr )
              *v28 = v27;
          }
          else
          {
            v29 = &tempFace - forwardFaces._Myfirst;
            if ( forwardFaces._Mylast == forwardFaces._Myend )
            {
              std::vector<NvFaceInfo *>::_Reserve(this: (std::vector<int> *)&forwardFaces, _Count: 1u);
              v28 = forwardFaces._Mylast;
            }
            if ( v28 != nullptr )
              *v28 = forwardFaces._Myfirst[v29];
          }
          v30 = v206;
          forwardFaces._Mylast = v28 + 1;
          v31 = v206->m_experimentId;
          if ( v31 < 0 )
          {
            v27->m_experimentId = -1;
            v27->m_stripId = v30->m_stripId;
          }
          else
          {
            v27->m_experimentId = v31;
            v27->m_testStripId = v30->m_stripId;
          }
          tempFace = (NvFaceInfo *)(unsigned __int16)v12;
          v32 = scratchIndices._Mylast;
          if ( (unsigned __int16 *)&tempFace >= scratchIndices._Mylast
            || (v33 = scratchIndices._Myfirst, scratchIndices._Myfirst > (unsigned __int16 *)&tempFace) )
          {
            if ( scratchIndices._Mylast == scratchIndices._Myend )
            {
              std::vector<unsigned short>::_Reserve(this: &scratchIndices, _Count: 1u);
              v30 = v206;
              v32 = scratchIndices._Mylast;
            }
            if ( v32 != nullptr )
              *v32 = v12;
          }
          else
          {
            v34 = ((char *)&tempFace - (char *)scratchIndices._Myfirst) >> 1;
            if ( scratchIndices._Mylast == scratchIndices._Myend )
            {
              std::vector<unsigned short>::_Reserve(this: &scratchIndices, _Count: 1u);
              v30 = v206;
              v32 = scratchIndices._Mylast;
              v33 = scratchIndices._Myfirst;
            }
            if ( v32 != nullptr )
              *v32 = v33[v34];
          }
          ++v30->m_numDegenerates;
          scratchIndices._Mylast = v32 + 1;
          i = v12;
        }
      }
    }
    goto LABEL_83;
  }
LABEL_148:
  v65 = forwardFaces._Myfirst;
  Myend = nullptr;
  v67 = forwardFaces._Mylast - forwardFaces._Myfirst;
  v68 = nullptr;
  v69 = nullptr;
  memset(&tempAllFaces, 0, 12);
  i = 0;
  testnv1 = v67;
  if ( v67 != 0 )
  {
    while ( 1 )
    {
      if ( v65 >= v69 || v68 > v65 )
      {
        if ( v69 == Myend )
        {
          v75 = v69 - v68;
          if ( v75 > 0x3FFFFFFE )
            goto LABEL_181;
          v76 = v75 + 1;
          v77 = tempAllFaces._Myend - tempAllFaces._Myfirst;
          if ( v76 > v77 )
          {
            if ( 0x3FFFFFFF - (v77 >> 1) >= v77 )
              v78 = (v77 >> 1) + v77;
            else
              v78 = 0;
            if ( v78 < v76 )
              v78 = v76;
            std::vector<int>::reserve(this: (std::vector<int> *)&tempAllFaces, _Count: v78);
            v69 = tempAllFaces._Mylast;
          }
        }
        if ( v69 != nullptr )
          *v69 = *v65;
      }
      else
      {
        v70 = v65 - v68;
        if ( v69 == Myend )
        {
          v71 = v69 - tempAllFaces._Myfirst;
          if ( v71 > 0x3FFFFFFE )
            goto LABEL_181;
          v72 = v71 + 1;
          v73 = tempAllFaces._Myend - tempAllFaces._Myfirst;
          if ( v72 > v73 )
          {
            if ( 0x3FFFFFFF - (v73 >> 1) >= v73 )
              v74 = (v73 >> 1) + v73;
            else
              v74 = 0;
            if ( v74 < v72 )
              v74 = v72;
            std::vector<int>::reserve(this: (std::vector<int> *)&tempAllFaces, _Count: v74);
            v67 = testnv1;
          }
          v69 = tempAllFaces._Mylast;
        }
        if ( v69 != nullptr )
          *v69 = tempAllFaces._Myfirst[v70];
      }
      ++v69;
      ++v65;
      tempAllFaces._Mylast = v69;
      if ( ++i >= v67 )
        break;
      v68 = tempAllFaces._Myfirst;
      Myend = tempAllFaces._Myend;
    }
  }
  std::vector<unsigned short>::resize(this: &scratchIndices, _Newsize: 0);
  v79 = v2;
  v80 = scratchIndices._Myfirst;
  testnv1 = (unsigned __int16)v2;
  v81 = scratchIndices._Mylast;
  if ( (unsigned __int16 *)&testnv1 >= scratchIndices._Mylast || scratchIndices._Myfirst > (unsigned __int16 *)&testnv1 )
  {
    if ( scratchIndices._Mylast == scratchIndices._Myend )
    {
      v87 = scratchIndices._Mylast - scratchIndices._Myfirst;
      if ( v87 > 0x7FFFFFFE )
        std::_Xlength_error(_Message: "vector<T> too long");
      v88 = v87 + 1;
      v89 = scratchIndices._Myend - scratchIndices._Myfirst;
      if ( v88 > v89 )
      {
        if ( 0x7FFFFFFF - (v89 >> 1) >= v89 )
          v90 = (v89 >> 1) + v89;
        else
          v90 = 0;
        if ( v90 < v88 )
          v90 = v88;
        std::vector<unsigned short>::reserve(this: &scratchIndices, _Count: v90);
        v81 = scratchIndices._Mylast;
        v80 = scratchIndices._Myfirst;
      }
    }
    if ( v81 != nullptr )
      *v81 = v79;
  }
  else
  {
    v82 = ((char *)&testnv1 - (char *)scratchIndices._Myfirst) >> 1;
    if ( scratchIndices._Mylast == scratchIndices._Myend )
    {
      v83 = scratchIndices._Mylast - scratchIndices._Myfirst;
      if ( v83 > 0x7FFFFFFE )
LABEL_181:
        std::_Xlength_error(_Message: "vector<T> too long");
      v84 = v83 + 1;
      v85 = scratchIndices._Myend - scratchIndices._Myfirst;
      if ( v84 > v85 )
      {
        if ( 0x7FFFFFFF - (v85 >> 1) >= v85 )
          v86 = (v85 >> 1) + v85;
        else
          v86 = 0;
        if ( v86 < v84 )
          v86 = v84;
        std::vector<unsigned short>::reserve(this: &scratchIndices, _Count: v86);
        v81 = scratchIndices._Mylast;
        v80 = scratchIndices._Myfirst;
      }
    }
    if ( v81 != nullptr )
      *v81 = v80[v82];
  }
  v91 = v1;
  v92 = v81 + 1;
  scratchIndices._Mylast = v92;
  testnv1 = (unsigned __int16)v1;
  if ( &testnv1 >= (int *)v92 || v80 > (unsigned __int16 *)&testnv1 )
  {
    if ( v92 == scratchIndices._Myend )
    {
      v98 = v92 - v80;
      if ( v98 > 0x7FFFFFFE )
        std::_Xlength_error(_Message: "vector<T> too long");
      v99 = v98 + 1;
      v100 = scratchIndices._Myend - v80;
      if ( v99 > v100 )
      {
        if ( 0x7FFFFFFF - (v100 >> 1) >= v100 )
          v101 = (v100 >> 1) + v100;
        else
          v101 = 0;
        if ( v101 < v99 )
          v101 = v99;
        std::vector<unsigned short>::reserve(this: &scratchIndices, _Count: v101);
        v92 = scratchIndices._Mylast;
      }
    }
    if ( v92 != nullptr )
      *v92 = v91;
  }
  else
  {
    v93 = ((char *)&testnv1 - (char *)v80) >> 1;
    if ( v92 == scratchIndices._Myend )
    {
      v94 = v92 - v80;
      if ( v94 > 0x7FFFFFFE )
        std::_Xlength_error(_Message: "vector<T> too long");
      v95 = v94 + 1;
      v96 = scratchIndices._Myend - v80;
      if ( v95 > v96 )
      {
        if ( 0x7FFFFFFF - (v96 >> 1) >= v96 )
          v97 = (v96 >> 1) + v96;
        else
          v97 = 0;
        if ( v97 < v95 )
          v97 = v95;
        std::vector<unsigned short>::reserve(this: &scratchIndices, _Count: v97);
        v92 = scratchIndices._Mylast;
        v80 = scratchIndices._Myfirst;
      }
    }
    if ( v92 != nullptr )
      *v92 = v80[v93];
  }
  v102 = testnv0;
  v103 = v92 + 1;
  testnv1 = (unsigned __int16)testnv0;
  v104 = scratchIndices._Myfirst;
  scratchIndices._Mylast = v103;
  if ( &testnv1 >= (int *)v103 || scratchIndices._Myfirst > (unsigned __int16 *)&testnv1 )
  {
    if ( v103 == scratchIndices._Myend )
    {
      v110 = v103 - scratchIndices._Myfirst;
      if ( v110 > 0x7FFFFFFE )
        std::_Xlength_error(_Message: "vector<T> too long");
      v111 = v110 + 1;
      v112 = scratchIndices._Myend - scratchIndices._Myfirst;
      if ( v111 > v112 )
      {
        if ( 0x7FFFFFFF - (v112 >> 1) >= v112 )
          v113 = (v112 >> 1) + v112;
        else
          v113 = 0;
        if ( v113 < v111 )
          v113 = v111;
        std::vector<unsigned short>::reserve(this: &scratchIndices, _Count: v113);
        v103 = scratchIndices._Mylast;
      }
    }
    if ( v103 != nullptr )
      *v103 = v102;
  }
  else
  {
    v105 = ((char *)&testnv1 - (char *)scratchIndices._Myfirst) >> 1;
    if ( v103 == scratchIndices._Myend )
    {
      v106 = v103 - scratchIndices._Myfirst;
      if ( v106 > 0x7FFFFFFE )
        std::_Xlength_error(_Message: "vector<T> too long");
      v107 = v106 + 1;
      v108 = scratchIndices._Myend - scratchIndices._Myfirst;
      if ( v107 > v108 )
      {
        if ( 0x7FFFFFFF - (v108 >> 1) >= v108 )
          v109 = (v108 >> 1) + v108;
        else
          v109 = 0;
        if ( v109 < v107 )
          v109 = v107;
        std::vector<unsigned short>::reserve(this: &scratchIndices, _Count: v109);
        v91 = v1;
      }
      v104 = scratchIndices._Myfirst;
      v103 = scratchIndices._Mylast;
    }
    if ( v103 != nullptr )
      *v103 = v104[v105];
  }
  scratchIndices._Mylast = v103 + 1;
  v114 = (NvFaceInfo *)edgeInfos->_Myfirst[v91];
  tempFace = (NvFaceInfo *)v91;
  v1 = v102;
  while ( v114 != nullptr )
  {
    v115 = v114->m_stripId;
    if ( v115 == v91 )
    {
      if ( v114->m_testStripId == v102 )
        goto LABEL_264;
      v114 = (NvFaceInfo *)v114->m_experimentId;
    }
    else
    {
      if ( v115 == v102 )
        goto LABEL_264;
      v114 = (NvFaceInfo *)v114[1].m_v0;
    }
  }
  v114 = nullptr;
  if ( v91 != v102 )
  {
LABEL_264:
    if ( (NvFaceInfo *)v114->m_v1 == v206->m_startInfo.m_startFace )
      v114 = (NvFaceInfo *)v114->m_v2;
    else
      v114 = (NvFaceInfo *)v114->m_v1;
  }
  v116 = v114;
  nextFace = v114;
  if ( v114 != nullptr )
  {
    while ( v116->m_stripId < 0 )
    {
      v117 = v206->m_experimentId;
      if ( v117 >= 0 && v116->m_experimentId == v117 )
        break;
      if ( NvStripInfo::Unique(this: v206, faceVec: &tempAllFaces, face: v116) == 0 )
        break;
      v118 = v1;
      testnv0 = v1;
      v119 = (NvFaceInfo *)NvStripifier::GetNextIndex(indices: &scratchIndices, face: v116);
      v120 = edgeInfos->_Myfirst;
      v121 = edgeInfos->_Myfirst[v118];
      i = (int)v119;
      while ( v121 != nullptr )
      {
        v122 = (NvFaceInfo *)v121->m_v0;
        if ( v122 == (NvFaceInfo *)v118 )
        {
          if ( (NvFaceInfo *)v121->m_v1 == v119 )
            goto LABEL_280;
          v121 = v121->m_nextV0;
        }
        else
        {
          if ( v122 == v119 )
            goto LABEL_280;
          v121 = v121->m_nextV1;
        }
      }
      v121 = nullptr;
      if ( (NvFaceInfo *)v118 != v119 )
      {
LABEL_280:
        if ( v121->m_face0 == v116 )
          m_face0 = v121->m_face1;
        else
          m_face0 = v121->m_face0;
        if ( m_face0 != nullptr && m_face0->m_stripId < 0 )
        {
          v124 = v206->m_experimentId;
          if ( v124 < 0 || m_face0->m_experimentId != v124 )
            goto LABEL_359;
        }
      }
      v125 = v120[(_DWORD)tempFace];
      while ( v125 != nullptr )
      {
        v126 = (NvFaceInfo *)v125->m_v0;
        if ( v126 == tempFace )
        {
          if ( (NvFaceInfo *)v125->m_v1 == v119 )
            goto LABEL_295;
          v125 = v125->m_nextV0;
        }
        else
        {
          if ( v126 == v119 )
            goto LABEL_295;
          v125 = v125->m_nextV1;
        }
      }
      v125 = nullptr;
      if ( tempFace == v119 )
      {
LABEL_359:
        v148 = scratchIndices._Myfirst;
        v159 = scratchIndices._Mylast;
        goto LABEL_360;
      }
LABEL_295:
      if ( v125->m_face0 == v116 )
        v127 = v125->m_face1;
      else
        v127 = v125->m_face0;
      if ( v127 == nullptr )
        goto LABEL_359;
      if ( v127->m_stripId >= 0 )
        goto LABEL_359;
      v128 = v206->m_experimentId;
      if ( v128 >= 0 && v127->m_experimentId == v128 )
        goto LABEL_359;
      v129 = (NvFaceInfo **)MemAlloc_Alloc(nSize: 0x18u);
      if ( v129 != nullptr )
      {
        v130 = tempFace;
        v131 = v1;
        *v129 = tempFace;
        v129[2] = v130;
        v129[1] = (NvFaceInfo *)v131;
        v129[3] = (NvFaceInfo *)-1;
        v129[4] = (NvFaceInfo *)-1;
        v129[5] = (NvFaceInfo *)-1;
        v132 = (NvFaceInfo *)v129;
      }
      else
      {
        v132 = nullptr;
      }
      v133 = backwardFaces._Mylast;
      testnv1 = (int)v132;
      if ( (NvFaceInfo **)&testnv1 >= backwardFaces._Mylast || backwardFaces._Myfirst > (NvFaceInfo **)&testnv1 )
      {
        if ( backwardFaces._Mylast == backwardFaces._Myend )
        {
          v141 = backwardFaces._Mylast - backwardFaces._Myfirst;
          if ( v141 > 0x3FFFFFFE )
            goto LABEL_181;
          v142 = v141 + 1;
          v143 = backwardFaces._Myend - backwardFaces._Myfirst;
          if ( v142 > v143 )
          {
            if ( 0x3FFFFFFF - (v143 >> 1) >= v143 )
              v144 = (v143 >> 1) + v143;
            else
              v144 = 0;
            if ( v144 < v142 )
              v144 = v142;
            std::vector<int>::reserve(this: (std::vector<int> *)&backwardFaces, _Count: v144);
            v133 = backwardFaces._Mylast;
          }
        }
        if ( v133 != nullptr )
          *v133 = v132;
        backwardFaces._Mylast = v133 + 1;
      }
      else
      {
        v134 = backwardFaces._Myfirst;
        v135 = backwardFaces._Mylast;
        v136 = ((char *)&testnv1 - (char *)backwardFaces._Myfirst) >> 2;
        if ( backwardFaces._Mylast == backwardFaces._Myend )
        {
          v137 = backwardFaces._Mylast - backwardFaces._Myfirst;
          if ( v137 > 0x3FFFFFFE )
            goto LABEL_181;
          v138 = v137 + 1;
          v139 = backwardFaces._Myend - backwardFaces._Myfirst;
          if ( v138 > v139 )
          {
            if ( 0x3FFFFFFF - (v139 >> 1) >= v139 )
              v140 = (v139 >> 1) + v139;
            else
              v140 = 0;
            if ( v140 < v138 )
              v140 = v138;
            std::vector<int>::reserve(this: (std::vector<int> *)&backwardFaces, _Count: v140);
            v134 = backwardFaces._Myfirst;
            v135 = backwardFaces._Mylast;
          }
        }
        if ( v135 != nullptr )
          *v135 = v134[v136];
        backwardFaces._Mylast = v135 + 1;
      }
      v145 = v206;
      v146 = v206->m_experimentId;
      if ( v146 < 0 )
      {
        v132->m_experimentId = -1;
        v132->m_stripId = v145->m_stripId;
      }
      else
      {
        v132->m_experimentId = v146;
        v132->m_testStripId = v145->m_stripId;
      }
      v147 = scratchIndices._Mylast;
      v148 = scratchIndices._Myfirst;
      v1 = (unsigned __int16)tempFace;
      if ( (unsigned __int16 *)&v1 >= scratchIndices._Mylast || scratchIndices._Myfirst > (unsigned __int16 *)&v1 )
      {
        if ( scratchIndices._Mylast == scratchIndices._Myend )
        {
          v154 = scratchIndices._Mylast - scratchIndices._Myfirst;
          if ( v154 > 0x7FFFFFFE )
            goto LABEL_181;
          v155 = v154 + 1;
          v156 = scratchIndices._Myend - scratchIndices._Myfirst;
          if ( v155 > v156 )
          {
            if ( 0x7FFFFFFF - (v156 >> 1) >= v156 )
              v157 = (v156 >> 1) + v156;
            else
              v157 = 0;
            if ( v157 < v155 )
              v157 = v155;
            std::vector<unsigned short>::reserve(this: &scratchIndices, _Count: v157);
            v147 = scratchIndices._Mylast;
            v148 = scratchIndices._Myfirst;
            v145 = v206;
          }
        }
        if ( v147 != nullptr )
          *v147 = (unsigned __int16)tempFace;
      }
      else
      {
        v149 = ((char *)&v1 - (char *)scratchIndices._Myfirst) >> 1;
        if ( scratchIndices._Mylast == scratchIndices._Myend )
        {
          v150 = scratchIndices._Mylast - scratchIndices._Myfirst;
          if ( v150 > 0x7FFFFFFE )
            goto LABEL_181;
          v151 = v150 + 1;
          v152 = scratchIndices._Myend - scratchIndices._Myfirst;
          if ( v151 > v152 )
          {
            if ( 0x7FFFFFFF - (v152 >> 1) >= v152 )
              v153 = (v152 >> 1) + v152;
            else
              v153 = 0;
            if ( v153 < v151 )
              v153 = v151;
            std::vector<unsigned short>::reserve(this: &scratchIndices, _Count: v153);
            v147 = scratchIndices._Mylast;
            v148 = scratchIndices._Myfirst;
            v145 = v206;
          }
        }
        if ( v147 != nullptr )
          *v147 = v148[v149];
      }
      v158 = tempFace;
      v116 = nextFace;
      v159 = v147 + 1;
      ++v145->m_numDegenerates;
      scratchIndices._Mylast = v159;
      testnv0 = (int)v158;
LABEL_360:
      v160 = backwardFaces._Mylast;
      v161 = backwardFaces._Myfirst;
      if ( &nextFace >= backwardFaces._Mylast || backwardFaces._Myfirst > &nextFace )
      {
        if ( backwardFaces._Mylast == backwardFaces._Myend )
        {
          v167 = backwardFaces._Mylast - backwardFaces._Myfirst;
          if ( v167 > 0x3FFFFFFE )
            goto LABEL_181;
          v168 = v167 + 1;
          v169 = backwardFaces._Myend - backwardFaces._Myfirst;
          if ( v168 > v169 )
          {
            if ( 0x3FFFFFFF - (v169 >> 1) >= v169 )
              v170 = (v169 >> 1) + v169;
            else
              v170 = 0;
            if ( v170 < v168 )
              v170 = v168;
            std::vector<int>::reserve(this: (std::vector<int> *)&backwardFaces, _Count: v170);
            v116 = nextFace;
          }
          v160 = backwardFaces._Mylast;
        }
        if ( v160 != nullptr )
          *v160 = v116;
      }
      else
      {
        v162 = &nextFace - backwardFaces._Myfirst;
        if ( backwardFaces._Mylast == backwardFaces._Myend )
        {
          v163 = backwardFaces._Mylast - backwardFaces._Myfirst;
          if ( v163 > 0x3FFFFFFE )
            goto LABEL_181;
          v164 = v163 + 1;
          v165 = backwardFaces._Myend - backwardFaces._Myfirst;
          if ( v164 > v165 )
          {
            if ( 0x3FFFFFFF - (v165 >> 1) >= v165 )
              v166 = (v165 >> 1) + v165;
            else
              v166 = 0;
            if ( v166 < v164 )
              v166 = v164;
            std::vector<int>::reserve(this: (std::vector<int> *)&backwardFaces, _Count: v166);
            v148 = scratchIndices._Myfirst;
            v161 = backwardFaces._Myfirst;
          }
          v160 = backwardFaces._Mylast;
        }
        if ( v160 != nullptr )
          *v160 = v161[v162];
      }
      v171 = tempAllFaces._Mylast;
      backwardFaces._Mylast = v160 + 1;
      if ( &nextFace >= tempAllFaces._Mylast || tempAllFaces._Myfirst > &nextFace )
      {
        if ( tempAllFaces._Mylast == tempAllFaces._Myend )
        {
          v177 = tempAllFaces._Mylast - tempAllFaces._Myfirst;
          if ( v177 > 0x3FFFFFFE )
            goto LABEL_181;
          v178 = v177 + 1;
          v179 = tempAllFaces._Myend - tempAllFaces._Myfirst;
          if ( v178 > v179 )
          {
            if ( 0x3FFFFFFF - (v179 >> 1) >= v179 )
              v180 = (v179 >> 1) + v179;
            else
              v180 = 0;
            if ( v180 < v178 )
              v180 = v178;
            std::vector<int>::reserve(this: (std::vector<int> *)&tempAllFaces, _Count: v180);
            v171 = tempAllFaces._Mylast;
          }
        }
        if ( v171 != nullptr )
          *v171 = nextFace;
      }
      else
      {
        v172 = &nextFace - tempAllFaces._Myfirst;
        if ( tempAllFaces._Mylast == tempAllFaces._Myend )
        {
          v173 = tempAllFaces._Mylast - tempAllFaces._Myfirst;
          if ( v173 > 0x3FFFFFFE )
            goto LABEL_181;
          v174 = v173 + 1;
          v175 = tempAllFaces._Myend - tempAllFaces._Myfirst;
          if ( v174 > v175 )
          {
            if ( 0x3FFFFFFF - (v175 >> 1) >= v175 )
              v176 = (v175 >> 1) + v175;
            else
              v176 = 0;
            if ( v176 < v174 )
              v176 = v174;
            std::vector<int>::reserve(this: (std::vector<int> *)&tempAllFaces, _Count: v176);
            v148 = scratchIndices._Myfirst;
          }
          v171 = tempAllFaces._Mylast;
        }
        if ( v171 != nullptr )
          *v171 = tempAllFaces._Myfirst[v172];
      }
      v181 = nextFace;
      tempAllFaces._Mylast = v171 + 1;
      v182 = v206;
      v183 = v206->m_experimentId;
      if ( v183 < 0 )
      {
        nextFace->m_experimentId = -1;
        v181->m_stripId = v182->m_stripId;
      }
      else
      {
        nextFace->m_experimentId = v183;
        v181->m_testStripId = v182->m_stripId;
      }
      v184 = i;
      v1 = (unsigned __int16)i;
      if ( &v1 >= (int *)v159 || v148 > (unsigned __int16 *)&v1 )
      {
        if ( v159 == scratchIndices._Myend )
        {
          v190 = v159 - v148;
          if ( v190 > 0x7FFFFFFE )
            goto LABEL_181;
          v191 = v190 + 1;
          v192 = scratchIndices._Myend - v148;
          if ( v191 > v192 )
          {
            if ( 0x7FFFFFFF - (v192 >> 1) >= v192 )
              v193 = (v192 >> 1) + v192;
            else
              v193 = 0;
            if ( v193 < v191 )
              v193 = v191;
            std::vector<unsigned short>::reserve(this: &scratchIndices, _Count: v193);
            v159 = scratchIndices._Mylast;
            v184 = i;
          }
        }
        if ( v159 != nullptr )
          *v159 = v184;
      }
      else
      {
        v185 = ((char *)&v1 - (char *)v148) >> 1;
        if ( v159 == scratchIndices._Myend )
        {
          v186 = v159 - v148;
          if ( v186 > 0x7FFFFFFE )
            goto LABEL_181;
          v187 = v186 + 1;
          v188 = scratchIndices._Myend - v148;
          if ( v187 > v188 )
          {
            if ( 0x7FFFFFFF - (v188 >> 1) >= v188 )
              v189 = (v188 >> 1) + v188;
            else
              v189 = 0;
            if ( v189 < v187 )
              v189 = v187;
            std::vector<unsigned short>::reserve(this: &scratchIndices, _Count: v189);
            v159 = scratchIndices._Mylast;
            v148 = scratchIndices._Myfirst;
            v184 = i;
          }
        }
        if ( v159 != nullptr )
          *v159 = v148[v185];
      }
      v194 = (NvFaceInfo *)edgeInfos->_Myfirst[testnv0];
      scratchIndices._Mylast = v159 + 1;
      tempFace = (NvFaceInfo *)testnv0;
      v1 = v184;
      while ( v194 != nullptr )
      {
        v195 = v194->m_stripId;
        if ( v195 == testnv0 )
        {
          if ( v194->m_testStripId == v184 )
            goto LABEL_446;
          v194 = (NvFaceInfo *)v194->m_experimentId;
        }
        else
        {
          if ( v195 == v184 )
            goto LABEL_446;
          v194 = (NvFaceInfo *)v194[1].m_v0;
        }
      }
      v194 = nullptr;
      if ( testnv0 != v184 )
      {
LABEL_446:
        if ( (NvFaceInfo *)v194->m_v1 == nextFace )
          v194 = (NvFaceInfo *)v194->m_v2;
        else
          v194 = (NvFaceInfo *)v194->m_v1;
      }
      nextFace = v194;
      if ( v194 == nullptr )
        break;
      v116 = v194;
    }
  }
  NvStripInfo::Combine(this: v206, forward: &forwardFaces, backward: &backwardFaces);
  if ( tempAllFaces._Myfirst != nullptr )
    free(pMem: tempAllFaces._Myfirst);
  if ( backwardFaces._Myfirst != nullptr )
    free(pMem: backwardFaces._Myfirst);
  if ( forwardFaces._Myfirst != nullptr )
    free(pMem: forwardFaces._Myfirst);
  if ( scratchIndices._Myfirst != nullptr )
    free(pMem: scratchIndices._Myfirst);
}

//------------------------------------------------------------------------------
// Address: 0x005B1F00
// Name: protected: void NvStripifier::CommitStrips(class std::vector<class NvStripInfo __near *,class std::allocator<class NvStripInfo __near *>> __near &,class std::vector<class NvStripInfo __near *,class std::allocator<class NvStripInfo __near *>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NvStripifier::CommitStrips(
        NvStripifier *this,
        NvStripInfo *allStrips,
        const std::vector<NvStripInfo *> *strips)
{
  std::vector<int> *v3; // ebx
  std::vector<NvStripInfo *> *v4; // esi
  int *Mylast; // eax
  int *Myfirst; // edx
  int *v7; // ecx
  int v8; // esi
  unsigned int v9; // eax
  unsigned int v10; // eax
  unsigned int v11; // ecx
  unsigned int v12; // ecx
  int *v13; // eax
  int *Myend; // ecx
  unsigned int v15; // eax
  unsigned int v16; // eax
  unsigned int v17; // ecx
  unsigned int v18; // ecx
  _DWORD *v19; // eax
  NvStripInfo *v20; // eax
  int v21; // edi
  int v22; // edx
  NvStripInfo **m_experimentId; // esi
  NvFaceInfo *v24; // ecx
  std::vector<NvStripInfo *> *v25; // esi
  int numStrips; // [esp+0h] [ebp-8h]
  int i; // [esp+4h] [ebp-4h]

  i = 0;
  numStrips = strips->_Mylast - strips->_Myfirst;
  if ( numStrips > 0 )
  {
    v3 = (std::vector<int> *)allStrips;
    do
    {
      v4 = (std::vector<NvStripInfo *> *)strips->_Myfirst[i];
      v4[2]._Myfirst = (NvStripInfo **)-1;
      Mylast = v3->_Mylast;
      allStrips = (NvStripInfo *)v4;
      if ( &allStrips >= (NvStripInfo **)Mylast || (Myfirst = v3->_Myfirst, v3->_Myfirst > (int *)&allStrips) )
      {
        Myend = v3->_Myend;
        if ( Mylast == Myend )
        {
          v15 = Mylast - v3->_Myfirst;
          if ( v15 > 0x3FFFFFFE )
LABEL_34:
            std::_Xlength_error(_Message: "vector<T> too long");
          v16 = v15 + 1;
          v17 = Myend - v3->_Myfirst;
          if ( v16 > v17 )
          {
            if ( 0x3FFFFFFF - (v17 >> 1) >= v17 )
              v18 = (v17 >> 1) + v17;
            else
              v18 = 0;
            if ( v18 < v16 )
              v18 = v16;
            std::vector<int>::reserve(this: v3, _Count: v18);
          }
        }
        v19 = v3->_Mylast;
        if ( v19 != nullptr )
          *v19 = v4;
      }
      else
      {
        v7 = v3->_Myend;
        v8 = ((char *)&allStrips - (char *)Myfirst) >> 2;
        if ( Mylast == v7 )
        {
          v9 = Mylast - Myfirst;
          if ( v9 > 0x3FFFFFFE )
            goto LABEL_34;
          v10 = v9 + 1;
          v11 = v7 - Myfirst;
          if ( v10 > v11 )
          {
            if ( 0x3FFFFFFF - (v11 >> 1) >= v11 )
              v12 = (v11 >> 1) + v11;
            else
              v12 = 0;
            if ( v12 < v10 )
              v12 = v10;
            std::vector<int>::reserve(this: v3, _Count: v12);
          }
        }
        v13 = v3->_Mylast;
        if ( v13 != nullptr )
          *v13 = v3->_Myfirst[v8];
      }
      ++v3->_Mylast;
      v20 = strips->_Myfirst[i];
      v21 = 0;
      v22 = v20->m_faces._Mylast - v20->m_faces._Myfirst;
      if ( v22 > 0 )
      {
        do
        {
          m_experimentId = (NvStripInfo **)allStrips->m_experimentId;
          v24 = v20->m_faces._Myfirst[v21];
          if ( (int)m_experimentId < 0 )
          {
            v25 = (std::vector<NvStripInfo *> *)allStrips;
            v24->m_experimentId = -1;
            v24->m_stripId = *(_DWORD *)&v25[1]._Alval.std::_Allocator_base<NvStripInfo *>;
          }
          else
          {
            v24->m_experimentId = (int)m_experimentId;
            v24->m_testStripId = allStrips->m_stripId;
          }
          ++v21;
        }
        while ( v21 < v22 );
      }
      ++i;
    }
    while ( i < numStrips );
  }
}

//------------------------------------------------------------------------------
// Address: 0x005B2080
// Name: protected: void NvStripifier::RemoveSmallStrips(class std::vector<class NvStripInfo __near *,class std::allocator<class NvStripInfo __near *>> __near &,class std::vector<class NvStripInfo __near *,class std::allocator<class NvStripInfo __near *>> __near &,class std::vector<class NvFaceInfo __near *,class std::allocator<class NvFaceInfo __near *>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NvStripifier::RemoveSmallStrips(
        NvStripifier *this,
        std::vector<NvStripInfo *> *allStrips,
        std::vector<int> *allBigStrips,
        std::vector<NvFaceInfo *> *faceList)
{
  unsigned __int8 *Myfirst; // esi
  unsigned __int8 *Mylast; // ecx
  unsigned __int8 *v6; // ecx
  unsigned __int8 *v7; // esi
  NvStripInfo **v8; // eax
  NvFaceInfo **v9; // edi
  NvFaceInfo **v10; // ebx
  int v11; // ecx
  NvStripInfo **v12; // esi
  std::vector<NvFaceInfo *> *p_m_faces; // eax
  int v14; // ecx
  NvFaceInfo **Myend; // edx
  NvFaceInfo **v16; // esi
  int v17; // esi
  unsigned int v18; // eax
  unsigned int v19; // eax
  unsigned int v20; // ecx
  unsigned int v21; // ecx
  unsigned int v22; // eax
  unsigned int v23; // eax
  unsigned int v24; // ecx
  unsigned int v25; // ecx
  NvStripInfo *v26; // eax
  int v27; // esi
  NvStripInfo *v28; // esi
  std::vector<int> *v29; // edx
  NvStripInfo **v30; // eax
  signed int v31; // esi
  int *v32; // eax
  NvStripInfo *v33; // ecx
  unsigned int v34; // edx
  unsigned int v35; // edi
  VertexCache *v36; // esi
  int cacheSize; // eax
  int k; // eax
  unsigned int v39; // eax
  NvFaceInfo *v40; // edi
  int numEntries; // eax
  int v42; // ebx
  int v43; // ecx
  int *entries; // edx
  int v45; // ecx
  int *v46; // edx
  int v47; // ecx
  int *v48; // edx
  std::vector<NvFaceInfo *> *v49; // edi
  int v50; // eax
  NvFaceInfo **v51; // esi
  NvFaceInfo **v52; // eax
  NvFaceInfo **v53; // edx
  NvFaceInfo **v54; // ecx
  int v55; // esi
  unsigned int v56; // eax
  unsigned int v57; // eax
  unsigned int v58; // ecx
  unsigned int v59; // ecx
  NvFaceInfo **v60; // eax
  NvFaceInfo **v61; // ecx
  unsigned int v62; // eax
  unsigned int v63; // eax
  unsigned int v64; // ecx
  unsigned int v65; // ecx
  NvFaceInfo **v66; // eax
  std::vector<NvFaceInfo *> tempFaceList; // [esp+Ch] [ebp-24h] BYREF
  int bestIndex; // [esp+1Ch] [ebp-14h]
  unsigned int v69; // [esp+20h] [ebp-10h]
  NvStripifier *v70; // [esp+24h] [ebp-Ch]
  int j; // [esp+28h] [ebp-8h]
  int i; // [esp+2Ch] [ebp-4h]
  int allStripsa; // [esp+38h] [ebp+8h]
  VertexCache *vcache; // [esp+3Ch] [ebp+Ch]

  Myfirst = (unsigned __int8 *)faceList->_Myfirst;
  v70 = this;
  Mylast = (unsigned __int8 *)faceList->_Mylast;
  if ( Myfirst != Mylast )
  {
    memmove(dst: Myfirst, src: Mylast, count: 0);
    faceList->_Mylast = (NvFaceInfo **)Myfirst;
  }
  v6 = (unsigned __int8 *)allBigStrips->_Mylast;
  v7 = (unsigned __int8 *)allBigStrips->_Myfirst;
  if ( (unsigned __int8 *)allBigStrips->_Myfirst != v6 )
  {
    memmove(dst: v7, src: v6, count: 0);
    allBigStrips->_Mylast = (int *)v7;
  }
  v8 = allStrips->_Myfirst;
  v9 = nullptr;
  v10 = nullptr;
  v11 = allStrips->_Mylast - allStrips->_Myfirst;
  memset(&tempFaceList, 0, 12);
  i = 0;
  if ( v11 != 0 )
  {
    do
    {
      v12 = &v8[i];
      p_m_faces = &(*v12)->m_faces;
      if ( (unsigned int)((*v12)->m_faces._Mylast - p_m_faces->_Myfirst) < v70->minStripLength )
      {
        v14 = (char *)(*v12)->m_faces._Mylast - (char *)(*v12)->m_faces._Myfirst;
        j = 0;
        if ( v14 >> 2 != 0 )
        {
          Myend = tempFaceList._Myend;
          do
          {
            v16 = &p_m_faces->_Myfirst[j];
            if ( v16 >= v9 || v10 > v16 )
            {
              if ( v9 == Myend )
              {
                v22 = v9 - v10;
                if ( v22 > 0x3FFFFFFE )
LABEL_55:
                  std::_Xlength_error(_Message: "vector<T> too long");
                v23 = v22 + 1;
                v24 = Myend - v10;
                if ( v23 > v24 )
                {
                  if ( 0x3FFFFFFF - (v24 >> 1) >= v24 )
                    v25 = (v24 >> 1) + v24;
                  else
                    v25 = 0;
                  if ( v25 < v23 )
                    v25 = v23;
                  std::vector<int>::reserve(this: (std::vector<int> *)&tempFaceList, _Count: v25);
                  v9 = tempFaceList._Mylast;
                  v10 = tempFaceList._Myfirst;
                  Myend = tempFaceList._Myend;
                }
              }
              if ( v9 != nullptr )
                *v9 = *v16;
            }
            else
            {
              v17 = v16 - v10;
              if ( v9 == Myend )
              {
                v18 = v9 - v10;
                if ( v18 > 0x3FFFFFFE )
                  goto LABEL_55;
                v19 = v18 + 1;
                v20 = Myend - v10;
                if ( v19 > v20 )
                {
                  if ( 0x3FFFFFFF - (v20 >> 1) >= v20 )
                    v21 = (v20 >> 1) + v20;
                  else
                    v21 = 0;
                  if ( v21 < v19 )
                    v21 = v19;
                  std::vector<int>::reserve(this: (std::vector<int> *)&tempFaceList, _Count: v21);
                  v9 = tempFaceList._Mylast;
                  v10 = tempFaceList._Myfirst;
                  Myend = tempFaceList._Myend;
                }
              }
              if ( v9 != nullptr )
                *v9 = v10[v17];
            }
            v26 = allStrips->_Myfirst[i];
            v27 = (char *)v26->m_faces._Mylast - (char *)v26->m_faces._Myfirst;
            p_m_faces = &v26->m_faces;
            tempFaceList._Mylast = ++v9;
            ++j;
          }
          while ( j < (unsigned int)(v27 >> 2) );
        }
        v28 = allStrips->_Myfirst[i];
        if ( v28 != nullptr )
        {
          if ( v28->m_faces._Myfirst != nullptr )
            free(pMem: v28->m_faces._Myfirst);
          v28->m_faces._Myfirst = nullptr;
          v28->m_faces._Mylast = nullptr;
          v28->m_faces._Myend = nullptr;
          free(pMem: v28);
        }
        goto LABEL_50;
      }
      v29 = allBigStrips;
      v30 = (NvStripInfo **)allBigStrips->_Mylast;
      if ( v12 >= v30 || allBigStrips->_Myfirst > (int *)v12 )
      {
        if ( v30 == (NvStripInfo **)allBigStrips->_Myend )
        {
          std::vector<NvFaceInfo *>::_Reserve(this: allBigStrips, _Count: 1u);
          v29 = allBigStrips;
        }
        v32 = v29->_Mylast;
        if ( v32 == nullptr )
          goto LABEL_49;
        v33 = *v12;
      }
      else
      {
        v31 = ((char *)v12 - (char *)allBigStrips->_Myfirst) >> 2;
        if ( v30 == (NvStripInfo **)allBigStrips->_Myend )
        {
          std::vector<NvFaceInfo *>::_Reserve(this: allBigStrips, _Count: 1u);
          v29 = allBigStrips;
        }
        v32 = v29->_Mylast;
        if ( v32 == nullptr )
          goto LABEL_49;
        v33 = (NvStripInfo *)v29->_Myfirst[v31];
      }
      *v32 = (int)v33;
LABEL_49:
      ++v29->_Mylast;
LABEL_50:
      v8 = allStrips->_Myfirst;
      v34 = allStrips->_Mylast - allStrips->_Myfirst;
      ++i;
    }
    while ( i < v34 );
  }
  v35 = v9 - v10;
  v69 = v35;
  i = (int)MemAlloc_Alloc(nSize: v35);
  memset(dst: (unsigned __int8 *)i, value: 0, count: v35);
  v36 = (VertexCache *)MemAlloc_Alloc(nSize: 8u);
  if ( v36 != nullptr )
  {
    cacheSize = v70->cacheSize;
    v36->numEntries = cacheSize;
    v36->entries = (int *)MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)cacheSize >> 30 != 0 ? -1 : 4 * cacheSize);
    for ( k = 0; k < v36->numEntries; ++k )
      v36->entries[k] = -1;
    vcache = v36;
  }
  else
  {
    vcache = nullptr;
  }
  bestIndex = 0;
  while ( 1 )
  {
    v39 = 0;
    j = -1;
    allStripsa = 0;
    if ( v69 != 0 )
    {
      do
      {
        if ( *(_BYTE *)(v39 + i) == 0 )
        {
          v40 = tempFaceList._Myfirst[allStripsa];
          numEntries = vcache->numEntries;
          v42 = 0;
          v43 = 0;
          if ( numEntries > 0 )
          {
            entries = vcache->entries;
            while ( *entries != v40->m_v0 )
            {
              ++v43;
              ++entries;
              if ( v43 >= numEntries )
                goto LABEL_66;
            }
            v42 = 1;
          }
LABEL_66:
          v45 = 0;
          if ( numEntries > 0 )
          {
            v46 = vcache->entries;
            while ( *v46 != v40->m_v1 )
            {
              ++v45;
              ++v46;
              if ( v45 >= numEntries )
                goto LABEL_72;
            }
            ++v42;
          }
LABEL_72:
          v47 = 0;
          if ( numEntries > 0 )
          {
            v48 = vcache->entries;
            while ( *v48 != v40->m_v2 )
            {
              ++v47;
              ++v48;
              if ( v47 >= numEntries )
                goto LABEL_78;
            }
            ++v42;
          }
LABEL_78:
          if ( v42 > j )
          {
            j = v42;
            bestIndex = allStripsa;
          }
        }
        v39 = allStripsa + 1;
        allStripsa = v39;
      }
      while ( v39 < v69 );
      v10 = tempFaceList._Myfirst;
    }
    v49 = faceList;
    if ( (float)j == -1.0 )
      break;
    v50 = bestIndex;
    *(_BYTE *)(bestIndex + i) = 1;
    v51 = &v10[v50];
    NvStripifier::UpdateCacheFace(this: v70, vcache, face: *v51);
    v52 = faceList->_Mylast;
    if ( v51 >= v52 || (v53 = faceList->_Myfirst, faceList->_Myfirst > v51) )
    {
      v61 = faceList->_Myend;
      if ( v52 == v61 )
      {
        v62 = v52 - faceList->_Myfirst;
        if ( v62 > 0x3FFFFFFE )
          goto LABEL_55;
        v63 = v62 + 1;
        v64 = v61 - faceList->_Myfirst;
        if ( v63 > v64 )
        {
          if ( 0x3FFFFFFF - (v64 >> 1) >= v64 )
            v65 = (v64 >> 1) + v64;
          else
            v65 = 0;
          v49 = faceList;
          if ( v65 < v63 )
            v65 = v63;
          std::vector<int>::reserve(this: (std::vector<int> *)faceList, _Count: v65);
        }
      }
      v66 = v49->_Mylast;
      if ( v66 != nullptr )
        *v66 = *v51;
      ++v49->_Mylast;
    }
    else
    {
      v54 = faceList->_Myend;
      v55 = v51 - v53;
      if ( v52 == v54 )
      {
        v56 = v52 - v53;
        if ( v56 > 0x3FFFFFFE )
          goto LABEL_55;
        v57 = v56 + 1;
        v58 = v54 - v53;
        if ( v57 > v58 )
        {
          if ( 0x3FFFFFFF - (v58 >> 1) >= v58 )
            v59 = (v58 >> 1) + v58;
          else
            v59 = 0;
          v49 = faceList;
          if ( v59 < v57 )
            v59 = v57;
          std::vector<int>::reserve(this: (std::vector<int> *)faceList, _Count: v59);
        }
      }
      v60 = v49->_Mylast;
      if ( v60 != nullptr )
        *v60 = v49->_Myfirst[v55];
      ++v49->_Mylast;
    }
  }
  if ( vcache != nullptr )
  {
    free(pMem: vcache->entries);
    vcache->entries = nullptr;
    free(pMem: vcache);
  }
  free(pMem: (void *)i);
  if ( v10 != nullptr )
    free(pMem: v10);
}

//------------------------------------------------------------------------------
// Address: 0x005B2560
// Name: public: void NvStripifier::CreateStrips(class std::vector<class NvStripInfo __near *,class std::allocator<class NvStripInfo __near *>> const __near &,class std::vector<int,class std::allocator<int>> __near &,bool,unsigned int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NvStripifier::CreateStrips(
        NvStripifier *this,
        const std::vector<NvStripInfo *> *allStrips,
        int stripIndices,
        bool bStitchStrips,
        unsigned int *numSeparateStrips)
{
  std::vector<int> *v5; // esi
  NvStripInfo *v6; // eax
  int v7; // ecx
  int *v8; // eax
  int v9; // edx
  int v10; // ebx
  int *v11; // eax
  int v12; // ecx
  int m_v1; // edx
  int m_v2; // ecx
  int v15; // edi
  int v16; // edx
  int v17; // eax
  int v18; // ecx
  int *Mylast; // eax
  int v20; // edi
  int *v21; // eax
  int *v22; // eax
  _DWORD *v23; // ecx
  bool v24; // zf
  _DWORD *v25; // eax
  bool v26; // zf
  int *v27; // eax
  int v28; // edi
  int *v29; // eax
  int *v30; // eax
  int *v31; // eax
  int *Myfirst; // edx
  int *v33; // ecx
  int v34; // edi
  unsigned int v35; // eax
  unsigned int v36; // eax
  unsigned int v37; // ecx
  unsigned int v38; // ecx
  int *v39; // eax
  int *Myend; // ecx
  unsigned int v41; // eax
  unsigned int v42; // eax
  unsigned int v43; // ecx
  unsigned int v44; // ecx
  int *v45; // eax
  int *v46; // eax
  int *v47; // edx
  int *v48; // ecx
  int v49; // edi
  unsigned int v50; // eax
  unsigned int v51; // eax
  unsigned int v52; // ecx
  unsigned int v53; // ecx
  int *v54; // eax
  int *v55; // ecx
  unsigned int v56; // eax
  unsigned int v57; // eax
  unsigned int v58; // ecx
  unsigned int v59; // ecx
  int *v60; // eax
  int *v61; // eax
  int *v62; // edx
  int *v63; // ecx
  int v64; // edi
  unsigned int v65; // eax
  unsigned int v66; // eax
  unsigned int v67; // ecx
  unsigned int v68; // ecx
  int *v69; // eax
  int *v70; // ecx
  unsigned int v71; // eax
  unsigned int v72; // eax
  unsigned int v73; // ecx
  unsigned int v74; // ecx
  int *v75; // eax
  __int64 v76; // xmm0_8
  int *v77; // eax
  int v78; // edx
  int *v79; // edi
  int v80; // ecx
  int v81; // ebx
  int v82; // ecx
  int v83; // ecx
  int *v84; // edx
  int *v85; // ecx
  int v86; // edi
  unsigned int v87; // eax
  unsigned int v88; // eax
  unsigned int v89; // ecx
  unsigned int v90; // ecx
  int *v91; // eax
  int *v92; // ecx
  unsigned int v93; // eax
  unsigned int v94; // eax
  unsigned int v95; // ecx
  unsigned int v96; // ecx
  int *v97; // eax
  int v98; // ecx
  int *v99; // edi
  int *v100; // edx
  int *v101; // ecx
  int v102; // edi
  unsigned int v103; // eax
  unsigned int v104; // eax
  unsigned int v105; // ecx
  unsigned int v106; // ecx
  int *v107; // eax
  int *v108; // ecx
  unsigned int v109; // eax
  unsigned int v110; // eax
  unsigned int v111; // ecx
  unsigned int v112; // ecx
  int *v113; // eax
  int *v114; // ecx
  int *v115; // edx
  int *v116; // ecx
  int v117; // edi
  unsigned int v118; // eax
  unsigned int v119; // eax
  unsigned int v120; // ecx
  unsigned int v121; // ecx
  int *v122; // eax
  int *v123; // ecx
  unsigned int v124; // eax
  unsigned int v125; // eax
  unsigned int v126; // ecx
  unsigned int v127; // ecx
  int *v128; // eax
  int *v129; // edx
  int *v130; // ecx
  int v131; // edi
  unsigned int v132; // eax
  unsigned int v133; // eax
  unsigned int v134; // ecx
  unsigned int v135; // ecx
  int *v136; // eax
  int *v137; // ecx
  unsigned int v138; // eax
  unsigned int v139; // eax
  unsigned int v140; // ecx
  unsigned int v141; // ecx
  int *v142; // eax
  unsigned int *v143; // eax
  NvFaceInfo tLastFace; // [esp+0h] [ebp-54h] BYREF
  NvFaceInfo tFirstFace; // [esp+18h] [ebp-3Ch] BYREF
  int nShared1; // [esp+30h] [ebp-24h] BYREF
  int nShared0; // [esp+34h] [ebp-20h] BYREF
  int nStripCount; // [esp+38h] [ebp-1Ch]
  int accountForNegatives; // [esp+3Ch] [ebp-18h]
  int nStripFaceCount; // [esp+40h] [ebp-14h]
  int nUnique; // [esp+44h] [ebp-10h] BYREF
  int j; // [esp+48h] [ebp-Ch]
  int v153; // [esp+4Ch] [ebp-8h]
  int i; // [esp+50h] [ebp-4h]

  nStripCount = allStrips->_Mylast - allStrips->_Myfirst;
  accountForNegatives = 0;
  i = 0;
  if ( nStripCount > 0 )
  {
    v5 = (std::vector<int> *)stripIndices;
    do
    {
      v6 = allStrips->_Myfirst[i];
      v7 = (char *)v6->m_faces._Mylast - (char *)v6->m_faces._Myfirst;
      stripIndices = (int)v6;
      v8 = (int *)*v6->m_faces._Myfirst;
      tFirstFace.m_v0 = *v8;
      v9 = v8[1];
      tFirstFace.m_v2 = v8[2];
      nStripFaceCount = v7 >> 2;
      tFirstFace.m_v1 = v9;
      memset(&tFirstFace.m_stripId, 255, 12);
      if ( v7 >> 2 <= 1 )
        goto LABEL_31;
      v10 = *(_DWORD *)(stripIndices + 12);
      v11 = *(int **)(v10 + 4);
      v12 = *v11;
      if ( tFirstFace.m_v0 == *v11 || tFirstFace.m_v0 == v11[1] || tFirstFace.m_v0 == v11[2] )
      {
        m_v1 = tFirstFace.m_v1;
        if ( tFirstFace.m_v1 != v12 && tFirstFace.m_v1 != v11[1] && tFirstFace.m_v1 != v11[2] )
          goto LABEL_18;
        m_v1 = tFirstFace.m_v2;
        if ( tFirstFace.m_v2 == v12 || tFirstFace.m_v2 == v11[1] || tFirstFace.m_v2 == v11[2] )
          m_v2 = -1;
        else
          m_v2 = tFirstFace.m_v2;
      }
      else
      {
        m_v1 = tFirstFace.m_v2;
        m_v2 = tFirstFace.m_v0;
      }
      if ( m_v2 == tFirstFace.m_v1 )
      {
        m_v1 = tFirstFace.m_v1;
LABEL_18:
        tFirstFace.m_v1 = tFirstFace.m_v0;
        goto LABEL_21;
      }
      if ( m_v2 == m_v1 )
      {
        tFirstFace.m_v2 = tFirstFace.m_v0;
LABEL_21:
        tFirstFace.m_v0 = m_v1;
      }
      if ( nStripFaceCount > 2 )
      {
        v15 = v11[1];
        if ( *v11 == v15 || (v16 = v11[2], *v11 == v16) || v15 == v16 )
        {
          if ( tFirstFace.m_v1 == v15 )
          {
            v17 = tFirstFace.m_v1;
LABEL_30:
            v18 = tFirstFace.m_v2;
            tFirstFace.m_v2 = v17;
            tFirstFace.m_v1 = v18;
          }
        }
        else
        {
          NvStripifier::GetSharedVertices(
            faceA: *(NvFaceInfo **)(v10 + 8),
            faceB: &tFirstFace,
            vertex0: &nShared0,
            vertex1: &nShared1);
          v17 = tFirstFace.m_v1;
          if ( nShared0 == tFirstFace.m_v1 && nShared1 == -1 )
            goto LABEL_30;
        }
      }
LABEL_31:
      if ( i != 0 && bStitchStrips )
      {
        Mylast = v5->_Mylast;
        if ( &tFirstFace >= (NvFaceInfo *)Mylast || v5->_Myfirst > (int *)&tFirstFace )
        {
          if ( Mylast == v5->_Myend )
            std::vector<NvFaceInfo *>::_Reserve(this: v5, _Count: 1u);
          v22 = v5->_Mylast;
          if ( v22 != nullptr )
            *v22 = tFirstFace.m_v0;
        }
        else
        {
          v20 = ((char *)&tFirstFace - (char *)v5->_Myfirst) >> 2;
          if ( Mylast == v5->_Myend )
            std::vector<NvFaceInfo *>::_Reserve(this: v5, _Count: 1u);
          v21 = v5->_Mylast;
          if ( v21 != nullptr )
            *v21 = v5->_Myfirst[v20];
        }
        ++v5->_Mylast;
        v23 = **(_DWORD ***)(stripIndices + 12);
        if ( *v23 == tFirstFace.m_v0 )
        {
          v24 = v23[1] == tFirstFace.m_v1;
        }
        else if ( v23[1] == tFirstFace.m_v0 )
        {
          v24 = v23[2] == tFirstFace.m_v1;
        }
        else
        {
          v24 = *v23 == tFirstFace.m_v1;
        }
        if ( ((v5->_Mylast - v5->_Myfirst - accountForNegatives) % 2 == 0) != v24 )
          std::vector<int>::push_back(this: v5, _Val: &tFirstFace.m_v0);
      }
      else
      {
        v25 = **(_DWORD ***)(stripIndices + 12);
        if ( *v25 == tFirstFace.m_v0 )
        {
          v26 = v25[1] == tFirstFace.m_v1;
        }
        else if ( v25[1] == tFirstFace.m_v0 )
        {
          v26 = v25[2] == tFirstFace.m_v1;
        }
        else
        {
          v26 = *v25 == tFirstFace.m_v1;
        }
        if ( !v26 )
        {
          v27 = v5->_Mylast;
          if ( &tFirstFace >= (NvFaceInfo *)v27 || v5->_Myfirst > (int *)&tFirstFace )
          {
            if ( v27 == v5->_Myend )
              std::vector<NvFaceInfo *>::_Reserve(this: v5, _Count: 1u);
            v30 = v5->_Mylast;
            if ( v30 != nullptr )
              *v30 = tFirstFace.m_v0;
          }
          else
          {
            v28 = ((char *)&tFirstFace - (char *)v5->_Myfirst) >> 2;
            if ( v27 == v5->_Myend )
              std::vector<NvFaceInfo *>::_Reserve(this: v5, _Count: 1u);
            v29 = v5->_Mylast;
            if ( v29 != nullptr )
              *v29 = v5->_Myfirst[v28];
          }
          ++v5->_Mylast;
        }
      }
      v31 = v5->_Mylast;
      if ( &tFirstFace >= (NvFaceInfo *)v31 || (Myfirst = v5->_Myfirst, v5->_Myfirst > (int *)&tFirstFace) )
      {
        Myend = v5->_Myend;
        if ( v31 == Myend )
        {
          v41 = v31 - v5->_Myfirst;
          if ( v41 > 0x3FFFFFFE )
            goto LABEL_264;
          v42 = v41 + 1;
          v43 = Myend - v5->_Myfirst;
          if ( v42 > v43 )
          {
            if ( 0x3FFFFFFF - (v43 >> 1) >= v43 )
              v44 = (v43 >> 1) + v43;
            else
              v44 = 0;
            if ( v44 < v42 )
              v44 = v42;
            std::vector<int>::reserve(this: v5, _Count: v44);
          }
        }
        v45 = v5->_Mylast;
        if ( v45 != nullptr )
          *v45 = tFirstFace.m_v0;
      }
      else
      {
        v33 = v5->_Myend;
        v34 = ((char *)&tFirstFace - (char *)Myfirst) >> 2;
        if ( v31 == v33 )
        {
          v35 = v31 - Myfirst;
          if ( v35 > 0x3FFFFFFE )
            goto LABEL_264;
          v36 = v35 + 1;
          v37 = v33 - Myfirst;
          if ( v36 > v37 )
          {
            if ( 0x3FFFFFFF - (v37 >> 1) >= v37 )
              v38 = (v37 >> 1) + v37;
            else
              v38 = 0;
            if ( v38 < v36 )
              v38 = v36;
            std::vector<int>::reserve(this: v5, _Count: v38);
          }
        }
        v39 = v5->_Mylast;
        if ( v39 != nullptr )
          *v39 = v5->_Myfirst[v34];
      }
      v46 = ++v5->_Mylast;
      if ( &tFirstFace.m_v1 >= v46 || (v47 = v5->_Myfirst, v5->_Myfirst > &tFirstFace.m_v1) )
      {
        v55 = v5->_Myend;
        if ( v46 == v55 )
        {
          v56 = v46 - v5->_Myfirst;
          if ( v56 > 0x3FFFFFFE )
            goto LABEL_264;
          v57 = v56 + 1;
          v58 = v55 - v5->_Myfirst;
          if ( v57 > v58 )
          {
            if ( 0x3FFFFFFF - (v58 >> 1) >= v58 )
              v59 = (v58 >> 1) + v58;
            else
              v59 = 0;
            if ( v59 < v57 )
              v59 = v57;
            std::vector<int>::reserve(this: v5, _Count: v59);
          }
        }
        v60 = v5->_Mylast;
        if ( v60 != nullptr )
          *v60 = tFirstFace.m_v1;
      }
      else
      {
        v48 = v5->_Myend;
        v49 = &tFirstFace.m_v1 - v47;
        if ( v46 == v48 )
        {
          v50 = v46 - v47;
          if ( v50 > 0x3FFFFFFE )
            goto LABEL_264;
          v51 = v50 + 1;
          v52 = v48 - v47;
          if ( v51 > v52 )
          {
            if ( 0x3FFFFFFF - (v52 >> 1) >= v52 )
              v53 = (v52 >> 1) + v52;
            else
              v53 = 0;
            if ( v53 < v51 )
              v53 = v51;
            std::vector<int>::reserve(this: v5, _Count: v53);
          }
        }
        v54 = v5->_Mylast;
        if ( v54 != nullptr )
          *v54 = v5->_Myfirst[v49];
      }
      v61 = ++v5->_Mylast;
      if ( &tFirstFace.m_v2 >= v61 || (v62 = v5->_Myfirst, v5->_Myfirst > &tFirstFace.m_v2) )
      {
        v70 = v5->_Myend;
        if ( v61 == v70 )
        {
          v71 = v61 - v5->_Myfirst;
          if ( v71 > 0x3FFFFFFE )
            goto LABEL_264;
          v72 = v71 + 1;
          v73 = v70 - v5->_Myfirst;
          if ( v72 > v73 )
          {
            if ( 0x3FFFFFFF - (v73 >> 1) >= v73 )
              v74 = (v73 >> 1) + v73;
            else
              v74 = 0;
            if ( v74 < v72 )
              v74 = v72;
            std::vector<int>::reserve(this: v5, _Count: v74);
          }
        }
        v75 = v5->_Mylast;
        if ( v75 != nullptr )
          *v75 = tFirstFace.m_v2;
      }
      else
      {
        v63 = v5->_Myend;
        v64 = &tFirstFace.m_v2 - v62;
        if ( v61 == v63 )
        {
          v65 = v61 - v62;
          if ( v65 > 0x3FFFFFFE )
            goto LABEL_264;
          v66 = v65 + 1;
          v67 = v63 - v62;
          if ( v66 > v67 )
          {
            if ( 0x3FFFFFFF - (v67 >> 1) >= v67 )
              v68 = (v67 >> 1) + v67;
            else
              v68 = 0;
            if ( v68 < v66 )
              v68 = v66;
            std::vector<int>::reserve(this: v5, _Count: v68);
          }
        }
        v69 = v5->_Mylast;
        if ( v69 != nullptr )
          *v69 = v5->_Myfirst[v64];
      }
      v76 = *(_QWORD *)&tFirstFace.m_v0;
      v77 = ++v5->_Mylast;
      tLastFace.m_v1 = HIDWORD(v76);
      *(_QWORD *)&tLastFace.m_v2 = *(_QWORD *)&tFirstFace.m_v2;
      *(_QWORD *)&tLastFace.m_testStripId = *(_QWORD *)&tFirstFace.m_testStripId;
      j = 1;
      if ( nStripFaceCount > 1 )
      {
        v78 = v76;
        while ( 1 )
        {
          v79 = *(int **)(*(_DWORD *)(stripIndices + 12) + 4 * j);
          v80 = *v79;
          if ( *v79 != v78 && v80 != tLastFace.m_v1 && v80 != tLastFace.m_v2 )
            break;
          v82 = v79[1];
          if ( v82 != v78 && v82 != tLastFace.m_v1 && v82 != tLastFace.m_v2 )
          {
            v81 = v79[1];
            goto LABEL_154;
          }
          v83 = v79[2];
          if ( v83 == v78 || v83 == tLastFace.m_v1 || v83 == tLastFace.m_v2 )
          {
            v81 = -1;
            goto LABEL_154;
          }
          v81 = v79[2];
          v153 = v81;
LABEL_155:
          nUnique = v81;
          if ( v81 == -1 )
          {
            v99 = v79 + 2;
            if ( v99 >= v77 || (v100 = v5->_Myfirst, v5->_Myfirst > v99) )
            {
              v108 = v5->_Myend;
              if ( v77 == v108 )
              {
                v109 = v77 - v5->_Myfirst;
                if ( v109 > 0x3FFFFFFE )
                  goto LABEL_264;
                v110 = v109 + 1;
                v111 = v108 - v5->_Myfirst;
                if ( v110 > v111 )
                {
                  if ( 0x3FFFFFFF - (v111 >> 1) >= v111 )
                    v112 = (v111 >> 1) + v111;
                  else
                    v112 = 0;
                  if ( v112 < v110 )
                    v112 = v110;
                  std::vector<int>::reserve(this: v5, _Count: v112);
                }
              }
              v113 = v5->_Mylast;
              if ( v113 != nullptr )
                *v113 = *v99;
            }
            else
            {
              v101 = v5->_Myend;
              v102 = v99 - v100;
              if ( v77 == v101 )
              {
                v103 = v77 - v100;
                if ( v103 > 0x3FFFFFFE )
                  goto LABEL_264;
                v104 = v103 + 1;
                v105 = v101 - v100;
                if ( v104 > v105 )
                {
                  if ( 0x3FFFFFFF - (v105 >> 1) >= v105 )
                    v106 = (v105 >> 1) + v105;
                  else
                    v106 = 0;
                  if ( v106 < v104 )
                    v106 = v104;
                  std::vector<int>::reserve(this: v5, _Count: v106);
                }
              }
              v107 = v5->_Mylast;
              if ( v107 != nullptr )
                *v107 = v5->_Myfirst[v102];
            }
            ++v5->_Mylast;
            v114 = *(int **)(*(_DWORD *)(stripIndices + 12) + 4 * j);
            v78 = *v114;
            tLastFace.m_v1 = v114[1];
            tLastFace.m_v2 = v114[2];
          }
          else
          {
            if ( &nUnique >= v77 || (v84 = v5->_Myfirst, v5->_Myfirst > &nUnique) )
            {
              v92 = v5->_Myend;
              if ( v77 == v92 )
              {
                v93 = v77 - v5->_Myfirst;
                if ( v93 > 0x3FFFFFFE )
                  goto LABEL_264;
                v94 = v93 + 1;
                v95 = v92 - v5->_Myfirst;
                if ( v94 > v95 )
                {
                  if ( 0x3FFFFFFF - (v95 >> 1) >= v95 )
                    v96 = (v95 >> 1) + v95;
                  else
                    v96 = 0;
                  if ( v96 < v94 )
                    v96 = v94;
                  std::vector<int>::reserve(this: v5, _Count: v96);
                }
              }
              v97 = v5->_Mylast;
              if ( v97 != nullptr )
                *v97 = v81;
            }
            else
            {
              v85 = v5->_Myend;
              v86 = &nUnique - v84;
              if ( v77 == v85 )
              {
                v87 = v77 - v84;
                if ( v87 > 0x3FFFFFFE )
                  goto LABEL_264;
                v88 = v87 + 1;
                v89 = v85 - v84;
                if ( v88 > v89 )
                {
                  if ( 0x3FFFFFFF - (v89 >> 1) >= v89 )
                    v90 = (v89 >> 1) + v89;
                  else
                    v90 = 0;
                  if ( v90 < v88 )
                    v90 = v88;
                  std::vector<int>::reserve(this: v5, _Count: v90);
                  v81 = v153;
                }
              }
              v91 = v5->_Mylast;
              if ( v91 != nullptr )
                *v91 = v5->_Myfirst[v86];
            }
            v98 = tLastFace.m_v2;
            v78 = tLastFace.m_v1;
            ++v5->_Mylast;
            tLastFace.m_v1 = v98;
            tLastFace.m_v2 = v81;
          }
          v77 = v5->_Mylast;
          if ( ++j >= nStripFaceCount )
            goto LABEL_207;
        }
        v81 = *v79;
LABEL_154:
        v153 = v81;
        goto LABEL_155;
      }
LABEL_207:
      if ( bStitchStrips )
      {
        if ( i != nStripCount - 1 )
        {
          if ( &tLastFace.m_v2 >= v77 || (v115 = v5->_Myfirst, v5->_Myfirst > &tLastFace.m_v2) )
          {
            v123 = v5->_Myend;
            if ( v77 == v123 )
            {
              v124 = v77 - v5->_Myfirst;
              if ( v124 > 0x3FFFFFFE )
                goto LABEL_264;
              v125 = v124 + 1;
              v126 = v123 - v5->_Myfirst;
              if ( v125 > v126 )
              {
                if ( 0x3FFFFFFF - (v126 >> 1) >= v126 )
                  v127 = (v126 >> 1) + v126;
                else
                  v127 = 0;
                if ( v127 < v125 )
                  v127 = v125;
                std::vector<int>::reserve(this: v5, _Count: v127);
              }
            }
            v128 = v5->_Mylast;
            if ( v128 != nullptr )
              *v128 = tLastFace.m_v2;
            ++v5->_Mylast;
          }
          else
          {
            v116 = v5->_Myend;
            v117 = &tLastFace.m_v2 - v115;
            if ( v77 == v116 )
            {
              v118 = v77 - v115;
              if ( v118 > 0x3FFFFFFE )
                goto LABEL_264;
              v119 = v118 + 1;
              v120 = v116 - v115;
              if ( v119 > v120 )
              {
                if ( 0x3FFFFFFF - (v120 >> 1) >= v120 )
                  v121 = (v120 >> 1) + v120;
                else
                  v121 = 0;
                if ( v121 < v119 )
                  v121 = v119;
                std::vector<int>::reserve(this: v5, _Count: v121);
              }
            }
            v122 = v5->_Mylast;
            if ( v122 != nullptr )
              *v122 = v5->_Myfirst[v117];
            ++v5->_Mylast;
          }
        }
      }
      else
      {
        stripIndices = -1;
        if ( &stripIndices >= v77 || (v129 = v5->_Myfirst, v5->_Myfirst > &stripIndices) )
        {
          v137 = v5->_Myend;
          if ( v77 == v137 )
          {
            v138 = v77 - v5->_Myfirst;
            if ( v138 > 0x3FFFFFFE )
LABEL_264:
              std::_Xlength_error(_Message: "vector<T> too long");
            v139 = v138 + 1;
            v140 = v137 - v5->_Myfirst;
            if ( v139 > v140 )
            {
              if ( 0x3FFFFFFF - (v140 >> 1) >= v140 )
                v141 = (v140 >> 1) + v140;
              else
                v141 = 0;
              if ( v141 < v139 )
                v141 = v139;
              std::vector<int>::reserve(this: v5, _Count: v141);
            }
          }
          v142 = v5->_Mylast;
          if ( v142 != nullptr )
            *v142 = -1;
        }
        else
        {
          v130 = v5->_Myend;
          v131 = &stripIndices - v129;
          if ( v77 == v130 )
          {
            v132 = v77 - v129;
            if ( v132 > 0x3FFFFFFE )
              goto LABEL_264;
            v133 = v132 + 1;
            v134 = v130 - v129;
            if ( v133 > v134 )
            {
              if ( 0x3FFFFFFF - (v134 >> 1) >= v134 )
                v135 = (v134 >> 1) + v134;
              else
                v135 = 0;
              if ( v135 < v133 )
                v135 = v133;
              std::vector<int>::reserve(this: v5, _Count: v135);
            }
          }
          v136 = v5->_Mylast;
          if ( v136 != nullptr )
            *v136 = v5->_Myfirst[v131];
        }
        v143 = numSeparateStrips;
        ++v5->_Mylast;
        ++accountForNegatives;
        ++*v143;
      }
      ++i;
    }
    while ( i < nStripCount );
  }
  if ( bStitchStrips )
    *numSeparateStrips = 1;
}

//------------------------------------------------------------------------------
// Address: 0x005B2E60
// Name: protected: void NvStripifier::SplitUpStripsAndOptimize(class std::vector<class NvStripInfo __near *,class std::allocator<class NvStripInfo __near *>> __near &,class std::vector<class NvStripInfo __near *,class std::allocator<class NvStripInfo __near *>> __near &,class std::vector<class NvEdgeInfo __near *,class std::allocator<class NvEdgeInfo __near *>> __near &,class std::vector<class NvFaceInfo __near *,class std::allocator<class NvFaceInfo __near *>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NvStripifier::SplitUpStripsAndOptimize(
        NvStripifier *this,
        std::vector<NvStripInfo *> *allStrips,
        std::vector<NvStripInfo *> *outStrips,
        std::vector<NvEdgeInfo *> *edgeInfos,
        std::vector<NvFaceInfo *> *outFaceList)
{
  NvStripifier *v5; // eax
  NvStripInfo **Myfirst; // ecx
  int v7; // edx
  NvStripInfo *v8; // edx
  unsigned int v9; // eax
  int v10; // ecx
  NvFaceInfo **v11; // ebx
  int m_v0; // esi
  int m_v1; // edi
  int m_v2; // ecx
  int v15; // esi
  int v16; // eax
  int v17; // edx
  int v18; // eax
  NvStripInfo *v19; // eax
  int v20; // edx
  int v21; // ebx
  float v22; // edi
  NvFaceInfo **v23; // edx
  NvFaceInfo *v24; // eax
  int v25; // ecx
  NvFaceInfo **v26; // esi
  int v27; // edx
  int v28; // eax
  NvStripInfo *v29; // edi
  NvFaceInfo **v30; // eax
  NvFaceInfo **v31; // edx
  NvFaceInfo **v32; // ecx
  int v33; // esi
  unsigned int v34; // eax
  unsigned int v35; // eax
  unsigned int v36; // ecx
  unsigned int v37; // ecx
  NvFaceInfo **v38; // eax
  NvFaceInfo **v39; // ecx
  NvFaceInfo **v40; // edx
  unsigned int v41; // eax
  unsigned int v42; // eax
  unsigned int v43; // ecx
  unsigned int v44; // ecx
  NvFaceInfo **v45; // eax
  NvFaceInfo **v46; // eax
  NvFaceInfo **v47; // edx
  NvFaceInfo **v48; // ecx
  int v49; // esi
  unsigned int v50; // eax
  unsigned int v51; // eax
  unsigned int v52; // ecx
  unsigned int v53; // ecx
  NvFaceInfo **v54; // eax
  NvFaceInfo **v55; // ecx
  NvFaceInfo **v56; // edx
  unsigned int v57; // eax
  unsigned int v58; // eax
  unsigned int v59; // ecx
  unsigned int v60; // ecx
  NvFaceInfo **v61; // eax
  char *v62; // esi
  int v63; // ecx
  int v64; // edx
  int v65; // eax
  NvStripInfo *v66; // edi
  NvFaceInfo **v67; // eax
  NvFaceInfo **v68; // edx
  NvFaceInfo **v69; // ecx
  int v70; // esi
  unsigned int v71; // eax
  unsigned int v72; // eax
  unsigned int v73; // ecx
  unsigned int v74; // ecx
  NvFaceInfo **v75; // eax
  NvFaceInfo **v76; // ecx
  NvFaceInfo **v77; // edx
  unsigned int v78; // eax
  unsigned int v79; // eax
  unsigned int v80; // ecx
  unsigned int v81; // ecx
  NvFaceInfo **v82; // eax
  NvStripInfo *v83; // edi
  NvFaceInfo **v84; // eax
  NvFaceInfo **v85; // edx
  NvFaceInfo **v86; // ecx
  int v87; // esi
  unsigned int v88; // eax
  unsigned int v89; // eax
  unsigned int v90; // ecx
  unsigned int v91; // ecx
  NvFaceInfo **v92; // eax
  NvFaceInfo **v93; // ecx
  NvFaceInfo **v94; // edx
  unsigned int v95; // eax
  unsigned int v96; // eax
  unsigned int v97; // ecx
  unsigned int v98; // ecx
  NvFaceInfo **v99; // eax
  NvStripInfo **v100; // esi
  NvStripInfo **v101; // edx
  int v102; // edi
  unsigned int v103; // eax
  unsigned int v104; // eax
  unsigned int v105; // ecx
  unsigned int v106; // ecx
  unsigned int v107; // eax
  unsigned int v108; // eax
  unsigned int v109; // ecx
  unsigned int v110; // ecx
  int v111; // esi
  NvStripInfo *v112; // eax
  int v113; // ecx
  NvFaceInfo **v114; // esi
  int v115; // ecx
  int v116; // edx
  int v117; // eax
  NvStripInfo *v118; // edi
  NvFaceInfo **v119; // eax
  NvFaceInfo **v120; // edx
  NvFaceInfo **v121; // ecx
  int v122; // esi
  unsigned int v123; // eax
  unsigned int v124; // eax
  unsigned int v125; // ecx
  unsigned int v126; // ecx
  NvFaceInfo **v127; // eax
  NvFaceInfo **v128; // ecx
  NvFaceInfo **v129; // edx
  unsigned int v130; // eax
  unsigned int v131; // eax
  unsigned int v132; // ecx
  unsigned int v133; // ecx
  NvFaceInfo **v134; // eax
  NvStripInfo *v135; // edi
  NvFaceInfo **v136; // eax
  NvFaceInfo **v137; // edx
  NvFaceInfo **v138; // ecx
  int v139; // esi
  unsigned int v140; // eax
  unsigned int v141; // eax
  unsigned int v142; // ecx
  unsigned int v143; // ecx
  NvFaceInfo **v144; // eax
  NvFaceInfo **v145; // ecx
  NvFaceInfo **v146; // edx
  unsigned int v147; // eax
  unsigned int v148; // eax
  unsigned int v149; // ecx
  unsigned int v150; // ecx
  NvFaceInfo **v151; // eax
  NvStripInfo **v152; // esi
  NvStripInfo **v153; // edx
  int v154; // edi
  unsigned int v155; // eax
  unsigned int v156; // eax
  unsigned int v157; // ecx
  unsigned int v158; // ecx
  unsigned int v159; // eax
  unsigned int v160; // eax
  unsigned int v161; // ecx
  unsigned int v162; // ecx
  NvStripInfo *v163; // eax
  float v164; // ecx
  int v165; // edx
  NvStripInfo *v166; // edi
  NvStripInfo *v167; // eax
  int v168; // edx
  std::vector<NvFaceInfo *> *p_m_faces; // eax
  NvFaceInfo **v170; // esi
  NvFaceInfo **Mylast; // eax
  NvFaceInfo **v172; // edx
  NvFaceInfo **v173; // ecx
  int v174; // esi
  unsigned int v175; // eax
  unsigned int v176; // eax
  unsigned int v177; // ecx
  unsigned int v178; // ecx
  NvFaceInfo **v179; // eax
  NvFaceInfo **Myend; // ecx
  NvFaceInfo **v181; // edx
  unsigned int v182; // eax
  unsigned int v183; // eax
  unsigned int v184; // ecx
  unsigned int v185; // ecx
  NvFaceInfo **v186; // eax
  NvStripInfo *v187; // eax
  int v188; // edx
  NvStripInfo **v189; // edx
  int v190; // edi
  unsigned int v191; // eax
  unsigned int v192; // eax
  unsigned int v193; // ecx
  unsigned int v194; // ecx
  unsigned int v195; // eax
  unsigned int v196; // eax
  unsigned int v197; // ecx
  unsigned int v198; // ecx
  unsigned int v199; // edx
  unsigned __int8 *v200; // ecx
  unsigned __int8 *v201; // esi
  VertexCache *v202; // esi
  int cacheSize; // eax
  int j; // eax
  float v205; // eax
  unsigned int v206; // esi
  int v207; // ecx
  NvFaceInfo **v208; // edi
  unsigned int v209; // ebx
  int v210; // eax
  double v211; // st7
  NvStripInfo **v212; // ebx
  NvStripInfo **v213; // eax
  NvStripInfo **v214; // edx
  NvStripInfo **v215; // ecx
  int v216; // edi
  unsigned int v217; // eax
  unsigned int v218; // eax
  unsigned int v219; // ecx
  unsigned int v220; // ecx
  NvStripInfo **v221; // eax
  NvStripInfo **v222; // ecx
  unsigned int v223; // eax
  unsigned int v224; // eax
  unsigned int v225; // ecx
  unsigned int v226; // ecx
  NvStripInfo **v227; // eax
  unsigned int v228; // edi
  float v229; // xmm0_4
  NvStripInfo *v230; // esi
  double v231; // st7
  NvFaceInfo *v232; // eax
  int v233; // ebx
  int v234; // edx
  int v235; // edi
  int v236; // ecx
  int *v237; // esi
  int v238; // eax
  int v239; // esi
  int v240; // eax
  int v241; // eax
  int *v242; // ecx
  int v243; // esi
  int v244; // eax
  _DWORD *v245; // eax
  bool v246; // zf
  NvStripInfo **v247; // edi
  NvStripInfo **v248; // eax
  NvStripInfo **v249; // edx
  NvStripInfo **v250; // ecx
  int v251; // ebx
  unsigned int v252; // eax
  unsigned int v253; // eax
  unsigned int v254; // ecx
  unsigned int v255; // ecx
  NvStripInfo **v256; // eax
  NvStripInfo **v257; // ecx
  unsigned int v258; // eax
  unsigned int v259; // eax
  unsigned int v260; // ecx
  unsigned int v261; // ecx
  NvStripInfo **v262; // eax
  int tFirstFace_8; // [esp+14h] [ebp-64h]
  std::vector<NvStripInfo *> tempStrips; // [esp+24h] [ebp-54h] BYREF
  NvStripStartInfo startInfo; // [esp+34h] [ebp-44h] BYREF
  int v266; // [esp+40h] [ebp-38h]
  int currCost; // [esp+44h] [ebp-34h]
  float bestNumHits; // [esp+48h] [ebp-30h]
  int numNeighbors; // [esp+4Ch] [ebp-2Ch]
  unsigned int minCost; // [esp+50h] [ebp-28h]
  int ctr; // [esp+54h] [ebp-24h]
  NvStripifier *v272; // [esp+58h] [ebp-20h]
  int bestIndex; // [esp+5Ch] [ebp-1Ch]
  int firstIndex; // [esp+60h] [ebp-18h]
  int v275; // [esp+64h] [ebp-14h]
  int faceCtr; // [esp+68h] [ebp-10h]
  int i; // [esp+6Ch] [ebp-Ch]
  NvStripInfo *currentStrip; // [esp+70h] [ebp-8h] BYREF
  bool bFirstTime; // [esp+77h] [ebp-1h]
  unsigned int bWantsCW; // [esp+80h] [ebp+8h]
  bool bWantsCW_3; // [esp+83h] [ebp+Bh]
  float nShared1a; // [esp+88h] [ebp+10h]
  int nShared1; // [esp+88h] [ebp+10h]
  VertexCache *vcache; // [esp+8Ch] [ebp+14h]

  v5 = this;
  numNeighbors = this->cacheSize;
  Myfirst = allStrips->_Myfirst;
  v7 = allStrips->_Mylast - allStrips->_Myfirst;
  v272 = v5;
  memset(&tempStrips, 0, 12);
  i = 0;
  if ( v7 != 0 )
  {
    while ( 1 )
    {
      v8 = Myfirst[i];
      v9 = 0;
      v10 = v8->m_faces._Mylast - v8->m_faces._Myfirst;
      startInfo.m_startEdge = nullptr;
      *(_DWORD *)&startInfo.m_toV1 = 0;
      LOBYTE(v266) = 0;
      ctr = 0;
      if ( v10 != 0 )
      {
        v11 = v8->m_faces._Myfirst;
        do
        {
          m_v0 = (*v11)->m_v0;
          m_v1 = (*v11)->m_v1;
          if ( m_v0 != m_v1 )
          {
            m_v2 = (*v11)->m_v2;
            if ( m_v0 != m_v2 && m_v1 != m_v2 )
              ++ctr;
          }
          ++v9;
          ++v11;
        }
        while ( v9 < v8->m_faces._Mylast - v8->m_faces._Myfirst );
      }
      v15 = numNeighbors;
      if ( ctr <= numNeighbors )
      {
        v163 = (NvStripInfo *)MemAlloc_Alloc(nSize: 0x2Cu);
        v164 = 0.0;
        if ( v163 != nullptr )
        {
          v165 = v266;
          *(_QWORD *)&v163->m_startInfo.m_startFace = *(_QWORD *)&startInfo.m_startEdge;
          *(_DWORD *)&v163->m_startInfo.m_toV1 = v165;
          v163->m_faces._Myfirst = nullptr;
          v163->m_faces._Mylast = nullptr;
          v163->m_faces._Myend = nullptr;
          v163->m_stripId = 0;
          v163->m_experimentId = -1;
          v163->visited = false;
          v163->m_numDegenerates = 0;
          v166 = v163;
        }
        else
        {
          v166 = nullptr;
        }
        v167 = allStrips->_Myfirst[i];
        v168 = (char *)v167->m_faces._Mylast - (char *)v167->m_faces._Myfirst;
        p_m_faces = &v167->m_faces;
        currentStrip = v166;
        bestNumHits = 0.0;
        if ( v168 >> 2 != 0 )
        {
          do
          {
            v170 = &p_m_faces->_Myfirst[LODWORD(v164)];
            Mylast = v166->m_faces._Mylast;
            if ( v170 >= Mylast || (v172 = v166->m_faces._Myfirst) > v170 )
            {
              Myend = v166->m_faces._Myend;
              if ( Mylast == Myend )
              {
                v181 = v166->m_faces._Myfirst;
                v182 = Mylast - v181;
                if ( v182 > 0x3FFFFFFE )
                  goto LABEL_323;
                v183 = v182 + 1;
                v184 = Myend - v181;
                if ( v183 > v184 )
                {
                  if ( 0x3FFFFFFF - (v184 >> 1) >= v184 )
                    v185 = (v184 >> 1) + v184;
                  else
                    v185 = 0;
                  if ( v185 < v183 )
                    v185 = v183;
                  std::vector<int>::reserve(this: (std::vector<int> *)&v166->m_faces, _Count: v185);
                }
              }
              v186 = v166->m_faces._Mylast;
              if ( v186 != nullptr )
                *v186 = *v170;
            }
            else
            {
              v173 = v166->m_faces._Myend;
              v174 = v170 - v172;
              if ( Mylast == v173 )
              {
                v175 = Mylast - v172;
                if ( v175 > 0x3FFFFFFE )
                  goto LABEL_323;
                v176 = v175 + 1;
                v177 = v173 - v172;
                if ( v176 > v177 )
                {
                  if ( 0x3FFFFFFF - (v177 >> 1) >= v177 )
                    v178 = (v177 >> 1) + v177;
                  else
                    v178 = 0;
                  if ( v178 < v176 )
                    v178 = v176;
                  std::vector<int>::reserve(this: (std::vector<int> *)&v166->m_faces, _Count: v178);
                }
              }
              v179 = v166->m_faces._Mylast;
              if ( v179 != nullptr )
                *v179 = v166->m_faces._Myfirst[v174];
            }
            ++v166->m_faces._Mylast;
            v187 = allStrips->_Myfirst[i];
            v188 = (char *)v187->m_faces._Mylast - (char *)v187->m_faces._Myfirst;
            p_m_faces = &v187->m_faces;
            LODWORD(v164) = LODWORD(bestNumHits) + 1;
            bestNumHits = v164;
          }
          while ( LODWORD(v164) < v188 >> 2 );
          v166 = currentStrip;
        }
        v152 = tempStrips._Mylast;
        v189 = tempStrips._Myfirst;
        if ( &currentStrip >= tempStrips._Mylast || tempStrips._Myfirst > &currentStrip )
        {
          if ( tempStrips._Mylast == tempStrips._Myend )
          {
            v195 = tempStrips._Mylast - tempStrips._Myfirst;
            if ( v195 > 0x3FFFFFFE )
              goto LABEL_323;
            v196 = v195 + 1;
            v197 = tempStrips._Myend - tempStrips._Myfirst;
            if ( v196 > v197 )
            {
              if ( 0x3FFFFFFF - (v197 >> 1) >= v197 )
                v198 = (v197 >> 1) + v197;
              else
                v198 = 0;
              if ( v198 < v196 )
                v198 = v196;
              std::vector<int>::reserve(this: (std::vector<int> *)&tempStrips, _Count: v198);
              v152 = tempStrips._Mylast;
            }
          }
          if ( v152 != nullptr )
            *v152 = v166;
        }
        else
        {
          v190 = &currentStrip - tempStrips._Myfirst;
          if ( tempStrips._Mylast == tempStrips._Myend )
          {
            v191 = tempStrips._Mylast - tempStrips._Myfirst;
            if ( v191 > 0x3FFFFFFE )
              goto LABEL_323;
            v192 = v191 + 1;
            v193 = tempStrips._Myend - tempStrips._Myfirst;
            if ( v192 > v193 )
            {
              if ( 0x3FFFFFFF - (v193 >> 1) >= v193 )
                v194 = (v193 >> 1) + v193;
              else
                v194 = 0;
              if ( v194 < v192 )
                v194 = v192;
              std::vector<int>::reserve(this: (std::vector<int> *)&tempStrips, _Count: v194);
              v152 = tempStrips._Mylast;
              v189 = tempStrips._Myfirst;
            }
          }
          if ( v152 != nullptr )
            *v152 = v189[v190];
        }
      }
      else
      {
        v16 = ctr / numNeighbors;
        v17 = ctr % numNeighbors;
        bestIndex = 0;
        ctr = 0;
        minCost = v16;
        firstIndex = v17;
        if ( v16 <= 0 )
        {
          v18 = 0;
          goto LABEL_161;
        }
        while ( 1 )
        {
          v19 = (NvStripInfo *)MemAlloc_Alloc(nSize: 0x2Cu);
          if ( v19 != nullptr )
          {
            v20 = v266;
            *(_QWORD *)&v19->m_startInfo.m_startFace = *(_QWORD *)&startInfo.m_startEdge;
            *(_DWORD *)&v19->m_startInfo.m_toV1 = v20;
            v19->m_faces._Myfirst = nullptr;
            v19->m_faces._Mylast = nullptr;
            v19->m_faces._Myend = nullptr;
            v19->m_stripId = 0;
            v19->m_experimentId = -1;
            v19->visited = false;
            v19->m_numDegenerates = 0;
            currentStrip = v19;
          }
          else
          {
            currentStrip = nullptr;
          }
          currCost = ctr + 1;
          v21 = bestIndex + v15 * ctr;
          faceCtr = v21;
          bFirstTime = true;
          if ( v21 < bestIndex + v15 * (ctr + 1) )
          {
            LODWORD(v22) = bestIndex + v15 * (ctr + 1);
            bestNumHits = v22;
            v275 = v21 + 1;
            while ( 1 )
            {
              v23 = allStrips->_Myfirst[i]->m_faces._Myfirst;
              v24 = v23[v21];
              v25 = v24->m_v0;
              v26 = &v23[v21];
              v27 = v24->m_v1;
              if ( v24->m_v0 != v27 )
              {
                v28 = v24->m_v2;
                if ( v25 != v28 && v27 != v28 )
                  break;
              }
              ++bestIndex;
              LODWORD(bestNumHits) = LODWORD(v22) + 1;
              if ( (v275 != LODWORD(v22) + 1 || ctr == minCost - 1 && (unsigned int)(firstIndex - 1) <= 2)
                && !bFirstTime )
              {
                v29 = currentStrip;
                v30 = currentStrip->m_faces._Mylast;
                if ( v26 >= v30 || (v31 = currentStrip->m_faces._Myfirst) > v26 )
                {
                  v39 = currentStrip->m_faces._Myend;
                  if ( v30 == v39 )
                  {
                    v40 = currentStrip->m_faces._Myfirst;
                    v41 = v30 - v40;
                    if ( v41 > 0x3FFFFFFE )
                      goto LABEL_323;
                    v42 = v41 + 1;
                    v43 = v39 - v40;
                    if ( v42 > v43 )
                    {
                      if ( 0x3FFFFFFF - (v43 >> 1) >= v43 )
                        v44 = (v43 >> 1) + v43;
                      else
                        v44 = 0;
                      if ( v44 < v42 )
                        v44 = v42;
                      std::vector<int>::reserve(this: (std::vector<int> *)&currentStrip->m_faces, _Count: v44);
                      v21 = faceCtr;
                    }
                  }
                  v45 = v29->m_faces._Mylast;
                  if ( v45 != nullptr )
                    *v45 = *v26;
                }
                else
                {
                  v32 = currentStrip->m_faces._Myend;
                  v33 = v26 - v31;
                  if ( v30 == v32 )
                  {
                    v34 = v30 - v31;
                    if ( v34 > 0x3FFFFFFE )
                      goto LABEL_323;
                    v35 = v34 + 1;
                    v36 = v32 - v31;
                    if ( v35 > v36 )
                    {
                      if ( 0x3FFFFFFF - (v36 >> 1) >= v36 )
                        v37 = (v36 >> 1) + v36;
                      else
                        v37 = 0;
                      if ( v37 < v35 )
                        v37 = v35;
                      std::vector<int>::reserve(this: (std::vector<int> *)&currentStrip->m_faces, _Count: v37);
                      v21 = faceCtr;
                    }
                  }
                  v38 = v29->m_faces._Mylast;
                  if ( v38 != nullptr )
                    *v38 = v29->m_faces._Myfirst[v33];
                }
LABEL_75:
                ++v29->m_faces._Mylast;
                ++v21;
                ++v275;
                goto LABEL_76;
              }
              ++v21;
              ++v275;
LABEL_76:
              v22 = bestNumHits;
              faceCtr = v21;
              if ( v21 >= SLODWORD(bestNumHits) )
                goto LABEL_77;
            }
            v29 = currentStrip;
            v46 = currentStrip->m_faces._Mylast;
            if ( v26 >= v46 || (v47 = currentStrip->m_faces._Myfirst) > v26 )
            {
              v55 = currentStrip->m_faces._Myend;
              if ( v46 == v55 )
              {
                v56 = currentStrip->m_faces._Myfirst;
                v57 = v46 - v56;
                if ( v57 > 0x3FFFFFFE )
                  goto LABEL_323;
                v58 = v57 + 1;
                v59 = v55 - v56;
                if ( v58 > v59 )
                {
                  if ( 0x3FFFFFFF - (v59 >> 1) >= v59 )
                    v60 = (v59 >> 1) + v59;
                  else
                    v60 = 0;
                  if ( v60 < v58 )
                    v60 = v58;
                  std::vector<int>::reserve(this: (std::vector<int> *)&currentStrip->m_faces, _Count: v60);
                  v21 = faceCtr;
                }
              }
              v61 = v29->m_faces._Mylast;
              if ( v61 != nullptr )
                *v61 = *v26;
            }
            else
            {
              v48 = currentStrip->m_faces._Myend;
              v49 = v26 - v47;
              if ( v46 == v48 )
              {
                v50 = v46 - v47;
                if ( v50 > 0x3FFFFFFE )
                  goto LABEL_323;
                v51 = v50 + 1;
                v52 = v48 - v47;
                if ( v51 > v52 )
                {
                  if ( 0x3FFFFFFF - (v52 >> 1) >= v52 )
                    v53 = (v52 >> 1) + v52;
                  else
                    v53 = 0;
                  if ( v53 < v51 )
                    v53 = v51;
                  std::vector<int>::reserve(this: (std::vector<int> *)&currentStrip->m_faces, _Count: v53);
                  v21 = faceCtr;
                }
              }
              v54 = v29->m_faces._Mylast;
              if ( v54 != nullptr )
                *v54 = v29->m_faces._Myfirst[v49];
            }
            bFirstTime = false;
            goto LABEL_75;
          }
LABEL_77:
          if ( ctr == minCost - 1 && (unsigned int)(firstIndex - 1) <= 2 )
          {
            ctr = 0;
            v275 = 4 * v21;
            while ( 1 )
            {
              v62 = (char *)allStrips->_Myfirst[i]->m_faces._Myfirst + v275;
              v63 = **(_DWORD **)v62;
              v64 = *(_DWORD *)(*(_DWORD *)v62 + 4);
              if ( v63 == v64 || (v65 = *(_DWORD *)(*(_DWORD *)v62 + 8), v63 == v65) || v64 == v65 )
              {
                v83 = currentStrip;
                v84 = currentStrip->m_faces._Mylast;
                if ( v62 >= (char *)v84 || (v85 = currentStrip->m_faces._Myfirst) > (NvFaceInfo **)v62 )
                {
                  v93 = currentStrip->m_faces._Myend;
                  if ( v84 == v93 )
                  {
                    v94 = currentStrip->m_faces._Myfirst;
                    v95 = v84 - v94;
                    if ( v95 > 0x3FFFFFFE )
                      goto LABEL_323;
                    v96 = v95 + 1;
                    v97 = v93 - v94;
                    if ( v96 > v97 )
                    {
                      if ( 0x3FFFFFFF - (v97 >> 1) >= v97 )
                        v98 = (v97 >> 1) + v97;
                      else
                        v98 = 0;
                      if ( v98 < v96 )
                        v98 = v96;
                      std::vector<int>::reserve(this: (std::vector<int> *)&currentStrip->m_faces, _Count: v98);
                    }
                  }
                  v99 = v83->m_faces._Mylast;
                  if ( v99 != nullptr )
                    *v99 = *(NvFaceInfo **)v62;
                }
                else
                {
                  v86 = currentStrip->m_faces._Myend;
                  v87 = (v62 - (char *)v85) >> 2;
                  if ( v84 == v86 )
                  {
                    v88 = v84 - v85;
                    if ( v88 > 0x3FFFFFFE )
                      goto LABEL_323;
                    v89 = v88 + 1;
                    v90 = v86 - v85;
                    if ( v89 > v90 )
                    {
                      if ( 0x3FFFFFFF - (v90 >> 1) >= v90 )
                        v91 = (v90 >> 1) + v90;
                      else
                        v91 = 0;
                      if ( v91 < v89 )
                        v91 = v89;
                      std::vector<int>::reserve(this: (std::vector<int> *)&currentStrip->m_faces, _Count: v91);
                    }
                  }
                  v92 = v83->m_faces._Mylast;
                  if ( v92 != nullptr )
                    *v92 = v83->m_faces._Myfirst[v87];
                }
                ++v83->m_faces._Mylast;
                v275 += 4;
                ++bestIndex;
                goto LABEL_133;
              }
              v66 = currentStrip;
              v67 = currentStrip->m_faces._Mylast;
              if ( v62 >= (char *)v67 )
                break;
              v68 = currentStrip->m_faces._Myfirst;
              if ( v68 > (NvFaceInfo **)v62 )
                break;
              v69 = currentStrip->m_faces._Myend;
              v70 = (v62 - (char *)v68) >> 2;
              if ( v67 == v69 )
              {
                v71 = v67 - v68;
                if ( v71 > 0x3FFFFFFE )
                  goto LABEL_323;
                v72 = v71 + 1;
                v73 = v69 - v68;
                if ( v72 > v73 )
                {
                  if ( 0x3FFFFFFF - (v73 >> 1) >= v73 )
                    v74 = (v73 >> 1) + v73;
                  else
                    v74 = 0;
                  if ( v74 < v72 )
                    v74 = v72;
                  std::vector<int>::reserve(this: (std::vector<int> *)&currentStrip->m_faces, _Count: v74);
                }
              }
              v75 = v66->m_faces._Mylast;
              if ( v75 == nullptr )
                goto LABEL_107;
              *v75 = v66->m_faces._Myfirst[v70];
              ++v66->m_faces._Mylast;
              v275 += 4;
              ++ctr;
LABEL_133:
              if ( ctr >= firstIndex )
              {
                firstIndex = 0;
                goto LABEL_135;
              }
            }
            v76 = currentStrip->m_faces._Myend;
            if ( v67 == v76 )
            {
              v77 = currentStrip->m_faces._Myfirst;
              v78 = v67 - v77;
              if ( v78 > 0x3FFFFFFE )
                goto LABEL_323;
              v79 = v78 + 1;
              v80 = v76 - v77;
              if ( v79 > v80 )
              {
                if ( 0x3FFFFFFF - (v80 >> 1) >= v80 )
                  v81 = (v80 >> 1) + v80;
                else
                  v81 = 0;
                if ( v81 < v79 )
                  v81 = v79;
                std::vector<int>::reserve(this: (std::vector<int> *)&currentStrip->m_faces, _Count: v81);
              }
            }
            v82 = v66->m_faces._Mylast;
            if ( v82 != nullptr )
              *v82 = *(NvFaceInfo **)v62;
LABEL_107:
            ++v66->m_faces._Mylast;
            v275 += 4;
            ++ctr;
            goto LABEL_133;
          }
LABEL_135:
          v100 = tempStrips._Mylast;
          v101 = tempStrips._Myfirst;
          if ( &currentStrip >= tempStrips._Mylast || tempStrips._Myfirst > &currentStrip )
          {
            if ( tempStrips._Mylast == tempStrips._Myend )
            {
              v107 = tempStrips._Mylast - tempStrips._Myfirst;
              if ( v107 > 0x3FFFFFFE )
                goto LABEL_323;
              v108 = v107 + 1;
              v109 = tempStrips._Myend - tempStrips._Myfirst;
              if ( v108 > v109 )
              {
                if ( 0x3FFFFFFF - (v109 >> 1) >= v109 )
                  v110 = (v109 >> 1) + v109;
                else
                  v110 = 0;
                if ( v110 < v108 )
                  v110 = v108;
                std::vector<int>::reserve(this: (std::vector<int> *)&tempStrips, _Count: v110);
                v100 = tempStrips._Mylast;
              }
            }
            if ( v100 != nullptr )
              *v100 = currentStrip;
          }
          else
          {
            v102 = &currentStrip - tempStrips._Myfirst;
            if ( tempStrips._Mylast == tempStrips._Myend )
            {
              v103 = tempStrips._Mylast - tempStrips._Myfirst;
              if ( v103 > 0x3FFFFFFE )
                goto LABEL_323;
              v104 = v103 + 1;
              v105 = tempStrips._Myend - tempStrips._Myfirst;
              if ( v104 > v105 )
              {
                if ( 0x3FFFFFFF - (v105 >> 1) >= v105 )
                  v106 = (v105 >> 1) + v105;
                else
                  v106 = 0;
                if ( v106 < v104 )
                  v106 = v104;
                std::vector<int>::reserve(this: (std::vector<int> *)&tempStrips, _Count: v106);
                v100 = tempStrips._Mylast;
                v101 = tempStrips._Myfirst;
              }
            }
            if ( v100 != nullptr )
              *v100 = v101[v102];
          }
          v18 = currCost;
          tempStrips._Mylast = v100 + 1;
          ctr = currCost;
          if ( currCost >= (int)minCost )
            break;
          v15 = numNeighbors;
        }
        v15 = numNeighbors;
LABEL_161:
        v111 = bestIndex + v18 * v15;
        if ( firstIndex == 0 )
          goto LABEL_302;
        v112 = (NvStripInfo *)MemAlloc_Alloc(nSize: 0x2Cu);
        if ( v112 != nullptr )
        {
          v113 = v266;
          *(_QWORD *)&v112->m_startInfo.m_startFace = *(_QWORD *)&startInfo.m_startEdge;
          *(_DWORD *)&v112->m_startInfo.m_toV1 = v113;
          v112->m_faces._Myfirst = nullptr;
          v112->m_faces._Mylast = nullptr;
          v112->m_faces._Myend = nullptr;
          v112->m_stripId = 0;
          v112->m_experimentId = -1;
          v112->visited = false;
          v112->m_numDegenerates = 0;
          currentStrip = v112;
        }
        else
        {
          currentStrip = nullptr;
        }
        *(float *)&minCost = 0.0;
        bFirstTime = true;
        if ( firstIndex > 0 )
        {
          v275 = 4 * v111;
          do
          {
            v114 = (NvFaceInfo **)((char *)allStrips->_Myfirst[i]->m_faces._Myfirst + v275);
            v115 = (*v114)->m_v0;
            v116 = (*v114)->m_v1;
            if ( v115 == v116 || (v117 = (*v114)->m_v2, v115 == v117) || v116 == v117 )
            {
              if ( bFirstTime )
              {
                v275 += 4;
                continue;
              }
              v135 = currentStrip;
              v136 = currentStrip->m_faces._Mylast;
              if ( v114 >= v136 || (v137 = currentStrip->m_faces._Myfirst) > v114 )
              {
                v145 = currentStrip->m_faces._Myend;
                if ( v136 == v145 )
                {
                  v146 = currentStrip->m_faces._Myfirst;
                  v147 = v136 - v146;
                  if ( v147 > 0x3FFFFFFE )
                    goto LABEL_323;
                  v148 = v147 + 1;
                  v149 = v145 - v146;
                  if ( v148 > v149 )
                  {
                    if ( 0x3FFFFFFF - (v149 >> 1) >= v149 )
                      v150 = (v149 >> 1) + v149;
                    else
                      v150 = 0;
                    if ( v150 < v148 )
                      v150 = v148;
                    std::vector<int>::reserve(this: (std::vector<int> *)&currentStrip->m_faces, _Count: v150);
                  }
                }
                v151 = v135->m_faces._Mylast;
                if ( v151 != nullptr )
                  *v151 = *v114;
LABEL_220:
                ++v135->m_faces._Mylast;
                v275 += 4;
                continue;
              }
              v138 = currentStrip->m_faces._Myend;
              v139 = v114 - v137;
              if ( v136 == v138 )
              {
                v140 = v136 - v137;
                if ( v140 > 0x3FFFFFFE )
                  goto LABEL_323;
                v141 = v140 + 1;
                v142 = v138 - v137;
                if ( v141 > v142 )
                {
                  if ( 0x3FFFFFFF - (v142 >> 1) >= v142 )
                    v143 = (v142 >> 1) + v142;
                  else
                    v143 = 0;
                  if ( v143 < v141 )
                    v143 = v141;
                  std::vector<int>::reserve(this: (std::vector<int> *)&currentStrip->m_faces, _Count: v143);
                }
              }
              v144 = v135->m_faces._Mylast;
              if ( v144 == nullptr )
                goto LABEL_220;
              *v144 = v135->m_faces._Myfirst[v139];
              ++v135->m_faces._Mylast;
              v275 += 4;
            }
            else
            {
              v118 = currentStrip;
              v119 = currentStrip->m_faces._Mylast;
              ++minCost;
              bFirstTime = false;
              if ( v114 >= v119 || (v120 = currentStrip->m_faces._Myfirst) > v114 )
              {
                v128 = currentStrip->m_faces._Myend;
                if ( v119 == v128 )
                {
                  v129 = currentStrip->m_faces._Myfirst;
                  v130 = v119 - v129;
                  if ( v130 > 0x3FFFFFFE )
                    goto LABEL_323;
                  v131 = v130 + 1;
                  v132 = v128 - v129;
                  if ( v131 > v132 )
                  {
                    if ( 0x3FFFFFFF - (v132 >> 1) >= v132 )
                      v133 = (v132 >> 1) + v132;
                    else
                      v133 = 0;
                    if ( v133 < v131 )
                      v133 = v131;
                    std::vector<int>::reserve(this: (std::vector<int> *)&currentStrip->m_faces, _Count: v133);
                  }
                }
                v134 = v118->m_faces._Mylast;
                if ( v134 != nullptr )
                  *v134 = *v114;
LABEL_194:
                ++v118->m_faces._Mylast;
                v275 += 4;
                continue;
              }
              v121 = currentStrip->m_faces._Myend;
              v122 = v114 - v120;
              if ( v119 == v121 )
              {
                v123 = v119 - v120;
                if ( v123 > 0x3FFFFFFE )
                  goto LABEL_323;
                v124 = v123 + 1;
                v125 = v121 - v120;
                if ( v124 > v125 )
                {
                  if ( 0x3FFFFFFF - (v125 >> 1) >= v125 )
                    v126 = (v125 >> 1) + v125;
                  else
                    v126 = 0;
                  if ( v126 < v124 )
                    v126 = v124;
                  std::vector<int>::reserve(this: (std::vector<int> *)&currentStrip->m_faces, _Count: v126);
                }
              }
              v127 = v118->m_faces._Mylast;
              if ( v127 == nullptr )
                goto LABEL_194;
              *v127 = v118->m_faces._Myfirst[v122];
              ++v118->m_faces._Mylast;
              v275 += 4;
            }
          }
          while ( (int)minCost < firstIndex );
        }
        v152 = tempStrips._Mylast;
        v153 = tempStrips._Myfirst;
        if ( &currentStrip >= tempStrips._Mylast || tempStrips._Myfirst > &currentStrip )
        {
          if ( tempStrips._Mylast == tempStrips._Myend )
          {
            v159 = tempStrips._Mylast - tempStrips._Myfirst;
            if ( v159 > 0x3FFFFFFE )
              goto LABEL_323;
            v160 = v159 + 1;
            v161 = tempStrips._Myend - tempStrips._Myfirst;
            if ( v160 > v161 )
            {
              if ( 0x3FFFFFFF - (v161 >> 1) >= v161 )
                v162 = (v161 >> 1) + v161;
              else
                v162 = 0;
              if ( v162 < v160 )
                v162 = v160;
              std::vector<int>::reserve(this: (std::vector<int> *)&tempStrips, _Count: v162);
              v152 = tempStrips._Mylast;
            }
          }
          if ( v152 != nullptr )
            *v152 = currentStrip;
        }
        else
        {
          v154 = &currentStrip - tempStrips._Myfirst;
          if ( tempStrips._Mylast == tempStrips._Myend )
          {
            v155 = tempStrips._Mylast - tempStrips._Myfirst;
            if ( v155 > 0x3FFFFFFE )
              goto LABEL_323;
            v156 = v155 + 1;
            v157 = tempStrips._Myend - tempStrips._Myfirst;
            if ( v156 > v157 )
            {
              if ( 0x3FFFFFFF - (v157 >> 1) >= v157 )
                v158 = (v157 >> 1) + v157;
              else
                v158 = 0;
              if ( v158 < v156 )
                v158 = v156;
              std::vector<int>::reserve(this: (std::vector<int> *)&tempStrips, _Count: v158);
              v152 = tempStrips._Mylast;
              v153 = tempStrips._Myfirst;
            }
          }
          if ( v152 != nullptr )
            *v152 = v153[v154];
        }
      }
      tempStrips._Mylast = v152 + 1;
LABEL_302:
      Myfirst = allStrips->_Myfirst;
      v199 = allStrips->_Mylast - allStrips->_Myfirst;
      if ( ++i >= v199 )
      {
        v5 = v272;
        break;
      }
    }
  }
  memset(&startInfo, 0, sizeof(startInfo));
  NvStripifier::RemoveSmallStrips(
    this: v5,
    allStrips: &tempStrips,
    allBigStrips: (std::vector<int> *)&startInfo,
    faceList: outFaceList);
  v200 = (unsigned __int8 *)outStrips->_Mylast;
  v201 = (unsigned __int8 *)outStrips->_Myfirst;
  if ( (unsigned __int8 *)outStrips->_Myfirst != v200 )
  {
    memmove(dst: v201, src: v200, count: 0);
    outStrips->_Mylast = (NvStripInfo **)v201;
  }
  ctr = ((char *)startInfo.m_startEdge - (char *)startInfo.m_startFace) >> 2;
  if ( ctr != 0 )
  {
    v202 = (VertexCache *)MemAlloc_Alloc(nSize: 8u);
    if ( v202 != nullptr )
    {
      cacheSize = v272->cacheSize;
      v202->numEntries = cacheSize;
      v202->entries = (int *)MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)cacheSize >> 30 != 0 ? -1 : 4 * cacheSize);
      for ( j = 0; j < v202->numEntries; ++j )
        v202->entries[j] = -1;
      vcache = v202;
    }
    else
    {
      vcache = nullptr;
    }
    bestIndex = 0;
    firstIndex = 0;
    *(float *)&minCost = 10000.0;
    for ( bWantsCW = 0; bWantsCW < ctr; ++bWantsCW )
    {
      v205 = *((float *)&startInfo.m_startFace->m_v0 + bWantsCW);
      v206 = 0;
      v207 = (*(_DWORD *)(LODWORD(v205) + 16) - *(_DWORD *)(LODWORD(v205) + 12)) >> 2;
      numNeighbors = 0;
      bestNumHits = v205;
      if ( v207 != 0 )
      {
        v208 = *(NvFaceInfo ***)(LODWORD(v205) + 12);
        v209 = (*(_DWORD *)(LODWORD(v205) + 16) - (int)v208) >> 2;
        do
        {
          v210 = NvStripifier::NumNeighbors(this: v272, face: *v208, edgeInfoVec: edgeInfos);
          numNeighbors += v210;
          ++v206;
          ++v208;
        }
        while ( v206 < v209 );
      }
      currCost = (*(_DWORD *)(LODWORD(bestNumHits) + 16) - *(_DWORD *)(LODWORD(bestNumHits) + 12)) >> 2;
      v211 = (double)numNeighbors / (double)(unsigned int)currCost;
      *(float *)&currCost = v211;
      if ( *(float *)&minCost > v211 )
      {
        minCost = currCost;
        firstIndex = bWantsCW;
      }
    }
    v212 = (NvStripInfo **)(&startInfo.m_startFace->m_v0 + firstIndex);
    NvStripifier::UpdateCacheStrip(this: v272, vcache, strip: *v212);
    v213 = outStrips->_Mylast;
    if ( v212 >= v213 || (v214 = outStrips->_Myfirst, outStrips->_Myfirst > v212) )
    {
      v222 = outStrips->_Myend;
      if ( v213 == v222 )
      {
        v223 = v213 - outStrips->_Myfirst;
        if ( v223 > 0x3FFFFFFE )
          std::_Xlength_error(_Message: "vector<T> too long");
        v224 = v223 + 1;
        v225 = v222 - outStrips->_Myfirst;
        if ( v224 > v225 )
        {
          if ( 0x3FFFFFFF - (v225 >> 1) >= v225 )
            v226 = (v225 >> 1) + v225;
          else
            v226 = 0;
          if ( v226 < v224 )
            v226 = v224;
          std::vector<int>::reserve(this: (std::vector<int> *)outStrips, _Count: v226);
        }
      }
      v227 = outStrips->_Mylast;
      if ( v227 != nullptr )
        *v227 = *v212;
    }
    else
    {
      v215 = outStrips->_Myend;
      v216 = v212 - v214;
      if ( v213 == v215 )
      {
        v217 = v213 - v214;
        if ( v217 > 0x3FFFFFFE )
          goto LABEL_323;
        v218 = v217 + 1;
        v219 = v215 - v214;
        if ( v218 > v219 )
        {
          if ( 0x3FFFFFFF - (v219 >> 1) >= v219 )
            v220 = (v219 >> 1) + v219;
          else
            v220 = 0;
          if ( v220 < v218 )
            v220 = v218;
          std::vector<int>::reserve(this: (std::vector<int> *)outStrips, _Count: v220);
        }
      }
      v221 = outStrips->_Mylast;
      if ( v221 != nullptr )
        *v221 = outStrips->_Myfirst[v216];
    }
    ++outStrips->_Mylast;
    (*v212)->visited = true;
    bWantsCW_3 = (((*v212)->m_faces._Mylast - (*v212)->m_faces._Myfirst) & 1) == 0;
LABEL_346:
    *(float *)&v228 = 0.0;
    v229 = -1.0;
    bestNumHits = -1.0;
    *(float *)&minCost = 0.0;
    if ( ctr != 0 )
    {
      while ( 1 )
      {
        v230 = (NvStripInfo *)*(&startInfo.m_startFace->m_v0 + v228);
        v246 = !v230->visited;
        numNeighbors = (int)v230;
        if ( v246 )
        {
          v231 = NvStripifier::CalcNumHitsStrip(this: v272, vcache, strip: v230);
          if ( v231 <= bestNumHits )
          {
            nShared1a = v231;
            if ( nShared1a >= v229 )
            {
              v232 = *v230->m_faces._Myfirst;
              v233 = v232->m_v2;
              v234 = v232->m_v0;
              v235 = v232->m_v1;
              v236 = v230->m_faces._Mylast - v230->m_faces._Myfirst;
              tFirstFace_8 = v233;
              if ( v236 > 1 )
              {
                v237 = *(int **)(*(_DWORD *)(numNeighbors + 12) + 4);
                v238 = *v237;
                if ( v234 != *v237 && v234 != v237[1] && v234 != v237[2] )
                {
                  v239 = v234;
                  goto LABEL_364;
                }
                if ( v235 != v238 && v235 != v237[1] && v235 != v237[2] )
                  goto LABEL_365;
                v239 = v233 == v238 || v233 == v237[1] || v233 == v237[2] ? -1 : v233;
LABEL_364:
                if ( v239 != v235 )
                {
                  if ( v239 == v233 )
                  {
                    v241 = v234;
                    v234 = v233;
                    v233 = v241;
                    tFirstFace_8 = v241;
                  }
                }
                else
                {
LABEL_365:
                  v240 = v234;
                  v234 = v235;
                  v235 = v240;
                }
                if ( v236 > 2 )
                {
                  v242 = *(int **)(*(_DWORD *)(numNeighbors + 12) + 8);
                  v243 = *v242;
                  v244 = -1;
                  nShared1 = -1;
                  if ( v234 == *v242 || v234 == v242[1] || v234 == v242[2] )
                    v244 = v234;
                  if ( v235 == v243 || v235 == v242[1] || v235 == v242[2] )
                  {
                    if ( v244 == -1 )
                    {
                      v244 = v235;
                      goto LABEL_378;
                    }
                    nShared1 = v235;
                  }
                  else
                  {
LABEL_378:
                    v233 = tFirstFace_8;
                    if ( tFirstFace_8 == v243 || tFirstFace_8 == v242[1] || tFirstFace_8 == v242[2] )
                    {
                      if ( v244 == -1 )
                        v244 = tFirstFace_8;
                      else
                        nShared1 = tFirstFace_8;
                    }
                  }
                  if ( v244 == v235 && nShared1 == -1 )
                    v235 = v233;
                }
              }
              v245 = **(_DWORD ***)(numNeighbors + 12);
              if ( *v245 == v234 )
              {
                v246 = v245[1] == v235;
              }
              else if ( v245[1] == v234 )
              {
                v246 = v245[2] == v235;
              }
              else
              {
                v246 = *v245 == v235;
              }
              if ( bWantsCW_3 == v246 )
                bestIndex = minCost;
            }
          }
          else
          {
            v229 = v231;
            bestNumHits = v231;
            bestIndex = v228;
          }
        }
        v228 = minCost + 1;
        minCost = v228;
        if ( v228 >= ctr )
        {
          if ( v229 == -1.0 )
            break;
          v247 = (NvStripInfo **)(&startInfo.m_startFace->m_v0 + bestIndex);
          (*v247)->visited = true;
          NvStripifier::UpdateCacheStrip(this: v272, vcache, strip: *v247);
          v248 = outStrips->_Mylast;
          if ( v247 >= v248 || (v249 = outStrips->_Myfirst, outStrips->_Myfirst > v247) )
          {
            v257 = outStrips->_Myend;
            if ( v248 != v257 )
            {
LABEL_419:
              v262 = outStrips->_Mylast;
              if ( v262 != nullptr )
                *v262 = *v247;
              goto LABEL_421;
            }
            v258 = v248 - outStrips->_Myfirst;
            if ( v258 <= 0x3FFFFFFE )
            {
              v259 = v258 + 1;
              v260 = v257 - outStrips->_Myfirst;
              if ( v259 > v260 )
              {
                if ( 0x3FFFFFFF - (v260 >> 1) >= v260 )
                  v261 = (v260 >> 1) + v260;
                else
                  v261 = 0;
                if ( v261 < v259 )
                  v261 = v259;
                std::vector<int>::reserve(this: (std::vector<int> *)outStrips, _Count: v261);
              }
              goto LABEL_419;
            }
LABEL_323:
            std::_Xlength_error(_Message: "vector<T> too long");
          }
          v250 = outStrips->_Myend;
          v251 = v247 - v249;
          if ( v248 != v250 )
            goto LABEL_408;
          v252 = v248 - v249;
          if ( v252 > 0x3FFFFFFE )
            goto LABEL_323;
          v253 = v252 + 1;
          v254 = v250 - v249;
          if ( v253 > v254 )
          {
            if ( 0x3FFFFFFF - (v254 >> 1) >= v254 )
              v255 = (v254 >> 1) + v254;
            else
              v255 = 0;
            if ( v255 < v253 )
              v255 = v253;
            std::vector<int>::reserve(this: (std::vector<int> *)outStrips, _Count: v255);
          }
LABEL_408:
          v256 = outStrips->_Mylast;
          if ( v256 != nullptr )
            *v256 = outStrips->_Myfirst[v251];
LABEL_421:
          ++outStrips->_Mylast;
          if ( ((LOBYTE((*v247)->m_faces._Mylast) - LOBYTE((*v247)->m_faces._Myfirst)) & 4) != 0 )
            bWantsCW_3 = !bWantsCW_3;
          goto LABEL_346;
        }
      }
    }
    if ( vcache != nullptr )
    {
      free(pMem: vcache->entries);
      vcache->entries = nullptr;
      free(pMem: vcache);
    }
  }
  if ( startInfo.m_startFace != nullptr )
    free(pMem: startInfo.m_startFace);
  if ( tempStrips._Myfirst != nullptr )
    free(pMem: tempStrips._Myfirst);
}

//------------------------------------------------------------------------------
// Address: 0x005B3F80
// Name: protected: void NvStripifier::FindAllStrips(class std::vector<class NvStripInfo __near *,class std::allocator<class NvStripInfo __near *>> __near &,class std::vector<class NvFaceInfo __near *,class std::allocator<class NvFaceInfo __near *>> __near &,class std::vector<class NvEdgeInfo __near *,class std::allocator<class NvEdgeInfo __near *>> __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NvStripifier::FindAllStrips(
        NvStripifier *this,
        NvStripInfo *allStrips,
        std::vector<NvFaceInfo *> *allFaceInfos,
        std::vector<NvEdgeInfo *> *allEdgeInfos,
        int numSamples)
{
  int v5; // edi
  int v6; // esi
  int v7; // ecx
  int *v8; // eax
  int v9; // ecx
  std::vector<NvStripInfo *> *v10; // edx
  _DWORD *j; // eax
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *v12; // eax
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *Myhead; // edi
  std::vector<NvFaceInfo *> *v14; // edx
  NvStripifier *v15; // ebx
  int v16; // esi
  bool v17; // zf
  int StartPoint; // eax
  NvFaceInfo **Myfirst; // edx
  int v20; // ecx
  NvFaceInfo *v21; // ebx
  NvStripifier *v22; // eax
  float v23; // xmm0_4
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *Parent; // eax
  NvStripInfo *v25; // ecx
  NvStripInfo **p_strip20; // eax
  NvFaceInfo **v27; // eax
  NvEdgeInfo *v28; // eax
  int m_v1; // esi
  int m_v0; // ecx
  NvEdgeInfo *v31; // esi
  NvStripInfo *v32; // eax
  int v33; // ecx
  int v34; // edx
  NvStripInfo *v35; // edi
  std::vector<int> *v36; // esi
  int *Mylast; // eax
  int *v38; // edx
  int *v39; // ecx
  int v40; // edi
  unsigned int v41; // eax
  unsigned int v42; // eax
  unsigned int v43; // ecx
  unsigned int v44; // ecx
  int *v45; // eax
  int *Myend; // ecx
  unsigned int v47; // eax
  unsigned int v48; // eax
  unsigned int v49; // ecx
  unsigned int v50; // ecx
  _DWORD *v51; // eax
  NvEdgeInfo *v52; // eax
  int v53; // esi
  int v54; // ecx
  NvEdgeInfo *v55; // esi
  NvStripInfo *v56; // eax
  int v57; // ecx
  int v58; // edx
  NvStripInfo *v59; // edi
  std::vector<int> *v60; // esi
  int *v61; // eax
  int *v62; // edx
  int *v63; // ecx
  int v64; // edi
  unsigned int v65; // eax
  unsigned int v66; // eax
  unsigned int v67; // ecx
  unsigned int v68; // ecx
  int *v69; // eax
  int *v70; // ecx
  unsigned int v71; // eax
  unsigned int v72; // eax
  unsigned int v73; // ecx
  unsigned int v74; // ecx
  _DWORD *v75; // eax
  int v76; // edx
  NvEdgeInfo *v77; // eax
  int m_v2; // esi
  int v79; // ecx
  NvEdgeInfo *v80; // esi
  NvStripInfo *v81; // eax
  int v82; // ecx
  int v83; // edx
  NvStripInfo *v84; // edi
  std::vector<int> *v85; // esi
  int *v86; // eax
  int *v87; // edx
  int *v88; // ecx
  int v89; // edi
  unsigned int v90; // eax
  unsigned int v91; // eax
  unsigned int v92; // ecx
  unsigned int v93; // ecx
  int *v94; // eax
  int *v95; // ecx
  unsigned int v96; // eax
  unsigned int v97; // eax
  unsigned int v98; // ecx
  unsigned int v99; // ecx
  _DWORD *v100; // eax
  int v101; // edx
  NvEdgeInfo *v102; // eax
  int v103; // esi
  int v104; // ecx
  NvEdgeInfo *v105; // esi
  NvStripInfo *v106; // eax
  int v107; // ecx
  int v108; // edx
  NvStripInfo *v109; // edi
  std::vector<int> *v110; // esi
  int *v111; // eax
  int *v112; // edx
  int *v113; // ecx
  int v114; // edi
  unsigned int v115; // eax
  unsigned int v116; // eax
  unsigned int v117; // ecx
  unsigned int v118; // ecx
  int *v119; // eax
  int *v120; // ecx
  unsigned int v121; // eax
  unsigned int v122; // eax
  unsigned int v123; // ecx
  unsigned int v124; // ecx
  _DWORD *v125; // eax
  int v126; // edx
  NvEdgeInfo *v127; // eax
  int v128; // esi
  int v129; // ecx
  NvEdgeInfo *v130; // esi
  NvStripInfo *v131; // eax
  int v132; // ecx
  int v133; // edx
  NvStripInfo *v134; // edi
  std::vector<int> *v135; // esi
  int *v136; // eax
  int *v137; // edx
  int *v138; // ecx
  int v139; // edi
  unsigned int v140; // eax
  unsigned int v141; // eax
  unsigned int v142; // ecx
  unsigned int v143; // ecx
  int *v144; // eax
  int *v145; // ecx
  unsigned int v146; // eax
  unsigned int v147; // eax
  unsigned int v148; // ecx
  unsigned int v149; // ecx
  _DWORD *v150; // eax
  int v151; // edx
  NvEdgeInfo *v152; // eax
  int v153; // esi
  int v154; // ecx
  NvEdgeInfo *v155; // esi
  NvStripInfo *v156; // eax
  int v157; // ecx
  int v158; // edx
  NvStripInfo *v159; // edi
  std::vector<int> *v160; // esi
  int *v161; // eax
  int *v162; // edx
  int *v163; // ecx
  int v164; // edi
  unsigned int v165; // eax
  unsigned int v166; // eax
  unsigned int v167; // ecx
  unsigned int v168; // ecx
  int *v169; // eax
  int *v170; // ecx
  unsigned int v171; // eax
  unsigned int v172; // eax
  unsigned int v173; // ecx
  unsigned int v174; // ecx
  _DWORD *v175; // eax
  std::vector<NvStripInfo *> *v176; // esi
  std::vector<NvEdgeInfo *> *v177; // edi
  NvStripInfo *v178; // eax
  NvFaceInfo *v179; // edi
  int v180; // ecx
  NvStripInfo *v181; // ebx
  NvStripInfo **v182; // eax
  NvStripInfo **v183; // edx
  NvStripInfo **v184; // ecx
  int v185; // edi
  unsigned int v186; // eax
  unsigned int v187; // eax
  unsigned int v188; // ecx
  unsigned int v189; // ecx
  NvStripInfo **v190; // eax
  NvStripInfo **v191; // ecx
  unsigned int v192; // eax
  unsigned int v193; // eax
  unsigned int v194; // ecx
  unsigned int v195; // ecx
  NvStripInfo **v196; // eax
  std::vector<NvEdgeInfo *> *v197; // eax
  int v198; // ebx
  int v199; // esi
  std::vector<NvStripInfo *> *v200; // edi
  double v201; // st6
  NvStripInfo *v202; // eax
  int v203; // ebx
  int v204; // edi
  int v205; // esi
  std::allocator<NvStripInfo *> *p_Alval; // ebx
  std::vector<NvStripInfo *> *v207; // esi
  int k; // edi
  NvStripInfo **v209; // eax
  NvStripInfo *v210; // [esp-8h] [ebp-C0h]
  std::pair<std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> > >,bool> result; // [esp+Ch] [ebp-ACh] BYREF
  std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> > > v212; // [esp+14h] [ebp-A4h] BYREF
  double bestValue; // [esp+18h] [ebp-A0h]
  unsigned __int64 v214; // [esp+20h] [ebp-98h]
  int v215; // [esp+28h] [ebp-90h]
  unsigned __int64 v216; // [esp+2Ch] [ebp-8Ch]
  int v217; // [esp+34h] [ebp-84h]
  unsigned __int64 v218; // [esp+38h] [ebp-80h]
  int v219; // [esp+40h] [ebp-78h]
  unsigned __int64 v220; // [esp+44h] [ebp-74h]
  int v221; // [esp+4Ch] [ebp-6Ch]
  unsigned __int64 v222; // [esp+50h] [ebp-68h]
  int v223; // [esp+58h] [ebp-60h]
  int v224; // [esp+5Ch] [ebp-5Ch]
  std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *v225; // [esp+60h] [ebp-58h] BYREF
  NvStripStartInfo startInfo; // [esp+64h] [ebp-54h] BYREF
  std::exception pExceptionObject; // [esp+70h] [ebp-48h] BYREF
  int loopCtr; // [esp+7Ch] [ebp-3Ch]
  std::set<NvFaceInfo *> resetPoints; // [esp+80h] [ebp-38h] BYREF
  float value; // [esp+90h] [ebp-28h] BYREF
  NvStripifier *v231; // [esp+94h] [ebp-24h]
  int i; // [esp+98h] [ebp-20h]
  bool done; // [esp+9Fh] [ebp-19h]
  int experimentId; // [esp+A0h] [ebp-18h]
  std::vector<NvStripInfo *> *experiments; // [esp+A4h] [ebp-14h]
  int stripId; // [esp+A8h] [ebp-10h]
  int experimentIndex; // [esp+ACh] [ebp-Ch]
  NvStripInfo *stripIter; // [esp+B0h] [ebp-8h] BYREF
  NvStripInfo *strip20; // [esp+B4h] [ebp-4h] BYREF

  v5 = numSamples;
  v6 = 6 * numSamples;
  v231 = this;
  experimentId = 0;
  stripId = 0;
  done = false;
  loopCtr = 0;
  v224 = 6 * numSamples;
  while ( 2 )
  {
    ++loopCtr;
    v7 = (unsigned __int64)(unsigned int)v6 >> 28 != 0 ? -1 : 16 * v6;
    v8 = (int *)MemAlloc_Alloc(nSize: __CFADD__(v7, 4) ? -1 : v7 + 4);
    if ( v8 != nullptr )
    {
      v9 = v6 - 1;
      v10 = (std::vector<NvStripInfo *> *)(v8 + 1);
      *v8 = v6;
      for ( j = v8 + 1; v9 >= 0; --v9 )
      {
        *j = 0;
        j[1] = 0;
        j[2] = 0;
        j += 4;
      }
      experiments = v10;
    }
    else
    {
      experiments = nullptr;
    }
    experimentIndex = 0;
    resetPoints._Mysize = 0;
    v12 = (std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *)MemAlloc_Alloc(nSize: 0x14u);
    if ( v12 == nullptr )
    {
      allEdgeInfos = nullptr;
      std::exception::exception(this: &pExceptionObject, _What: (const char *const *)&allEdgeInfos);
      pExceptionObject.__vftable = (std::exception_vtbl *)&std::bad_alloc::`vftable';
      _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI2_AVbad_alloc_std__);
    }
    resetPoints._Myhead = v12;
    v12->_Left = v12;
    resetPoints._Myhead->_Parent = resetPoints._Myhead;
    resetPoints._Myhead->_Right = resetPoints._Myhead;
    resetPoints._Myhead->_Color = 1;
    resetPoints._Myhead->_Isnil = 1;
    i = 0;
    if ( v5 <= 0 )
      goto LABEL_256;
    Myhead = resetPoints._Myhead;
    do
    {
      v14 = allFaceInfos;
      v15 = v231;
      v16 = allFaceInfos->_Mylast - allFaceInfos->_Myfirst;
      v17 = !v231->bFirstTimeResetPoint;
      stripIter = nullptr;
      if ( v17 )
      {
        StartPoint = (int)(float)((float)((float)v16 - 1.0) * v231->meshJump);
      }
      else
      {
        StartPoint = NvStripifier::FindStartPoint(this: v231, faceInfos: allFaceInfos, edgeInfos: allEdgeInfos);
        v14 = allFaceInfos;
        v15->bFirstTimeResetPoint = false;
      }
      if ( StartPoint == -1 )
        StartPoint = (int)(float)((float)((float)v16 - 1.0) * v15->meshJump);
      Myfirst = v14->_Myfirst;
      v20 = StartPoint;
      while ( 1 )
      {
        v21 = Myfirst[v20];
        if ( v21->m_stripId < 0 )
          break;
        if ( ++v20 >= v16 )
          v20 = 0;
        if ( v20 == StartPoint )
        {
          v21 = (NvFaceInfo *)stripIter;
          goto LABEL_22;
        }
      }
      stripIter = (NvStripInfo *)Myfirst[v20];
LABEL_22:
      v22 = v231;
      v23 = v231->meshJump + 0.1;
      v231->meshJump = v23;
      if ( v23 > 1.0 )
        v22->meshJump = 0.050000001;
      value = *(float *)&v21;
      if ( v21 == nullptr )
      {
        done = true;
        break;
      }
      Parent = Myhead->_Parent;
      v25 = (NvStripInfo *)Myhead;
      while ( Parent->_Isnil == 0 )
      {
        if ( Parent->_Myval >= v21 )
        {
          v25 = (NvStripInfo *)Parent;
          Parent = Parent->_Left;
        }
        else
        {
          Parent = Parent->_Right;
        }
      }
      strip20 = v25;
      if ( v25 == (NvStripInfo *)Myhead || (NvFaceInfo **)v21 < v25->m_faces._Myfirst )
      {
        v225 = Myhead;
        p_strip20 = (NvStripInfo **)&v225;
      }
      else
      {
        p_strip20 = &strip20;
      }
      if ( *p_strip20 != (NvStripInfo *)Myhead )
        goto LABEL_253;
      v27 = std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0>>::_Buynode<NvFaceInfo * &>(
              this: &resetPoints,
              _Val: (NvFaceInfo **)&value);
      std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0>>::_Linsert(
        this: &resetPoints,
        &result,
        _Node: (std::_Tree_nod<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> >::_Node *)v27,
        _Leftish: 0);
      v28 = allEdgeInfos->_Myfirst[v21->m_v0];
      m_v1 = v21->m_v1;
      if ( v28 == nullptr )
      {
LABEL_43:
        v31 = nullptr;
        goto LABEL_44;
      }
      while ( 1 )
      {
        m_v0 = v28->m_v0;
        if ( m_v0 != v21->m_v0 )
          break;
        if ( v28->m_v1 == m_v1 )
          goto LABEL_46;
        v28 = v28->m_nextV0;
LABEL_42:
        if ( v28 == nullptr )
          goto LABEL_43;
      }
      if ( m_v0 != m_v1 )
      {
        v28 = v28->m_nextV1;
        goto LABEL_42;
      }
LABEL_46:
      v31 = v28;
LABEL_44:
      v32 = (NvStripInfo *)MemAlloc_Alloc(nSize: 0x2Cu);
      if ( v32 != nullptr )
      {
        v33 = stripId;
        v218 = __PAIR64__((unsigned int)v31, (unsigned int)v21);
        *(_QWORD *)&v32->m_startInfo.m_startFace = __PAIR64__((unsigned int)v31, (unsigned int)v21);
        LOBYTE(v219) = 1;
        *(_DWORD *)&v32->m_startInfo.m_toV1 = v219;
        v34 = experimentId;
        v32->m_faces._Myfirst = nullptr;
        v32->m_faces._Mylast = nullptr;
        v32->m_faces._Myend = nullptr;
        v32->m_stripId = v33;
        v32->m_experimentId = v34;
        v32->visited = false;
        v32->m_numDegenerates = 0;
        v35 = v32;
        stripId = v33 + 1;
        experimentId = v34 + 1;
      }
      else
      {
        v35 = nullptr;
      }
      v36 = (std::vector<int> *)&experiments[experimentIndex++];
      Mylast = v36->_Mylast;
      strip20 = v35;
      if ( &strip20 >= (NvStripInfo **)Mylast || (v38 = v36->_Myfirst, v36->_Myfirst > (int *)&strip20) )
      {
        Myend = v36->_Myend;
        if ( Mylast == Myend )
        {
          v47 = Mylast - v36->_Myfirst;
          if ( v47 > 0x3FFFFFFE )
            goto LABEL_314;
          v48 = v47 + 1;
          v49 = Myend - v36->_Myfirst;
          if ( v48 > v49 )
          {
            if ( 0x3FFFFFFF - (v49 >> 1) >= v49 )
              v50 = (v49 >> 1) + v49;
            else
              v50 = 0;
            if ( v50 < v48 )
              v50 = v48;
            std::vector<int>::reserve(this: v36, _Count: v50);
            v21 = (NvFaceInfo *)stripIter;
          }
        }
        v51 = v36->_Mylast;
        if ( v51 != nullptr )
          *v51 = v35;
        goto LABEL_72;
      }
      v39 = v36->_Myend;
      v40 = ((char *)&strip20 - (char *)v38) >> 2;
      if ( Mylast != v39 )
        goto LABEL_59;
      v41 = Mylast - v38;
      if ( v41 > 0x3FFFFFFE )
        goto LABEL_314;
      v42 = v41 + 1;
      v43 = v39 - v38;
      if ( v42 > v43 )
      {
        if ( 0x3FFFFFFF - (v43 >> 1) >= v43 )
          v44 = (v43 >> 1) + v43;
        else
          v44 = 0;
        if ( v44 < v42 )
          v44 = v42;
        std::vector<int>::reserve(this: v36, _Count: v44);
        v21 = (NvFaceInfo *)stripIter;
      }
LABEL_59:
      v45 = v36->_Mylast;
      if ( v45 != nullptr )
        *v45 = v36->_Myfirst[v40];
LABEL_72:
      ++v36->_Mylast;
      v52 = allEdgeInfos->_Myfirst[v21->m_v0];
      v53 = v21->m_v1;
      if ( v52 == nullptr )
      {
LABEL_79:
        v55 = nullptr;
        goto LABEL_80;
      }
      while ( 2 )
      {
        v54 = v52->m_v0;
        if ( v54 == v21->m_v0 )
        {
          if ( v52->m_v1 == v53 )
            break;
          v52 = v52->m_nextV0;
          goto LABEL_78;
        }
        if ( v54 != v53 )
        {
          v52 = v52->m_nextV1;
LABEL_78:
          if ( v52 == nullptr )
            goto LABEL_79;
          continue;
        }
        break;
      }
      v55 = v52;
LABEL_80:
      v56 = (NvStripInfo *)MemAlloc_Alloc(nSize: 0x2Cu);
      if ( v56 != nullptr )
      {
        v57 = stripId;
        v214 = __PAIR64__((unsigned int)v55, (unsigned int)v21);
        *(_QWORD *)&v56->m_startInfo.m_startFace = __PAIR64__((unsigned int)v55, (unsigned int)v21);
        LOBYTE(v215) = 0;
        *(_DWORD *)&v56->m_startInfo.m_toV1 = v215;
        v58 = experimentId;
        v56->m_faces._Myfirst = nullptr;
        v56->m_faces._Mylast = nullptr;
        v56->m_faces._Myend = nullptr;
        v56->m_stripId = v57;
        v56->m_experimentId = v58;
        v56->visited = false;
        v56->m_numDegenerates = 0;
        v59 = v56;
        stripId = v57 + 1;
        experimentId = v58 + 1;
      }
      else
      {
        v59 = nullptr;
      }
      v60 = (std::vector<int> *)&experiments[experimentIndex++];
      v61 = v60->_Mylast;
      strip20 = v59;
      if ( &strip20 >= (NvStripInfo **)v61 || (v62 = v60->_Myfirst, v60->_Myfirst > (int *)&strip20) )
      {
        v70 = v60->_Myend;
        if ( v61 != v70 )
        {
LABEL_106:
          v75 = v60->_Mylast;
          if ( v75 != nullptr )
            *v75 = v59;
          goto LABEL_108;
        }
        v71 = v61 - v60->_Myfirst;
        if ( v71 <= 0x3FFFFFFE )
        {
          v72 = v71 + 1;
          v73 = v70 - v60->_Myfirst;
          if ( v72 > v73 )
          {
            if ( 0x3FFFFFFF - (v73 >> 1) >= v73 )
              v74 = (v73 >> 1) + v73;
            else
              v74 = 0;
            if ( v74 < v72 )
              v74 = v72;
            std::vector<int>::reserve(this: v60, _Count: v74);
            v21 = (NvFaceInfo *)stripIter;
          }
          goto LABEL_106;
        }
        goto LABEL_314;
      }
      v63 = v60->_Myend;
      v64 = ((char *)&strip20 - (char *)v62) >> 2;
      if ( v61 != v63 )
        goto LABEL_95;
      v65 = v61 - v62;
      if ( v65 > 0x3FFFFFFE )
        goto LABEL_314;
      v66 = v65 + 1;
      v67 = v63 - v62;
      if ( v66 > v67 )
      {
        if ( 0x3FFFFFFF - (v67 >> 1) >= v67 )
          v68 = (v67 >> 1) + v67;
        else
          v68 = 0;
        if ( v68 < v66 )
          v68 = v66;
        std::vector<int>::reserve(this: v60, _Count: v68);
        v21 = (NvFaceInfo *)stripIter;
      }
LABEL_95:
      v69 = v60->_Mylast;
      if ( v69 != nullptr )
        *v69 = v60->_Myfirst[v64];
LABEL_108:
      ++v60->_Mylast;
      v76 = v21->m_v1;
      v77 = allEdgeInfos->_Myfirst[v76];
      m_v2 = v21->m_v2;
      if ( v77 == nullptr )
      {
LABEL_115:
        v80 = nullptr;
        goto LABEL_116;
      }
      while ( 2 )
      {
        v79 = v77->m_v0;
        if ( v79 == v76 )
        {
          if ( v77->m_v1 == m_v2 )
            break;
          v77 = v77->m_nextV0;
          goto LABEL_114;
        }
        if ( v79 != m_v2 )
        {
          v77 = v77->m_nextV1;
LABEL_114:
          if ( v77 == nullptr )
            goto LABEL_115;
          continue;
        }
        break;
      }
      v80 = v77;
LABEL_116:
      v81 = (NvStripInfo *)MemAlloc_Alloc(nSize: 0x2Cu);
      if ( v81 != nullptr )
      {
        v82 = stripId;
        v222 = __PAIR64__((unsigned int)v80, (unsigned int)v21);
        *(_QWORD *)&v81->m_startInfo.m_startFace = __PAIR64__((unsigned int)v80, (unsigned int)v21);
        LOBYTE(v223) = 1;
        *(_DWORD *)&v81->m_startInfo.m_toV1 = v223;
        v83 = experimentId;
        v81->m_faces._Myfirst = nullptr;
        v81->m_faces._Mylast = nullptr;
        v81->m_faces._Myend = nullptr;
        v81->m_stripId = v82;
        v81->m_experimentId = v83;
        v81->visited = false;
        v81->m_numDegenerates = 0;
        v84 = v81;
        stripId = v82 + 1;
        experimentId = v83 + 1;
      }
      else
      {
        v84 = nullptr;
      }
      v85 = (std::vector<int> *)&experiments[experimentIndex++];
      v86 = v85->_Mylast;
      strip20 = v84;
      if ( &strip20 >= (NvStripInfo **)v86 || (v87 = v85->_Myfirst, v85->_Myfirst > (int *)&strip20) )
      {
        v95 = v85->_Myend;
        if ( v86 == v95 )
        {
          v96 = v86 - v85->_Myfirst;
          if ( v96 > 0x3FFFFFFE )
            goto LABEL_314;
          v97 = v96 + 1;
          v98 = v95 - v85->_Myfirst;
          if ( v97 > v98 )
          {
            if ( 0x3FFFFFFF - (v98 >> 1) >= v98 )
              v99 = (v98 >> 1) + v98;
            else
              v99 = 0;
            if ( v99 < v97 )
              v99 = v97;
            std::vector<int>::reserve(this: v85, _Count: v99);
            v21 = (NvFaceInfo *)stripIter;
          }
        }
        v100 = v85->_Mylast;
        if ( v100 != nullptr )
          *v100 = v84;
        goto LABEL_144;
      }
      v88 = v85->_Myend;
      v89 = ((char *)&strip20 - (char *)v87) >> 2;
      if ( v86 != v88 )
        goto LABEL_131;
      v90 = v86 - v87;
      if ( v90 > 0x3FFFFFFE )
        goto LABEL_314;
      v91 = v90 + 1;
      v92 = v88 - v87;
      if ( v91 > v92 )
      {
        if ( 0x3FFFFFFF - (v92 >> 1) >= v92 )
          v93 = (v92 >> 1) + v92;
        else
          v93 = 0;
        if ( v93 < v91 )
          v93 = v91;
        std::vector<int>::reserve(this: v85, _Count: v93);
        v21 = (NvFaceInfo *)stripIter;
      }
LABEL_131:
      v94 = v85->_Mylast;
      if ( v94 != nullptr )
        *v94 = v85->_Myfirst[v89];
LABEL_144:
      ++v85->_Mylast;
      v101 = v21->m_v1;
      v102 = allEdgeInfos->_Myfirst[v101];
      v103 = v21->m_v2;
      if ( v102 == nullptr )
      {
LABEL_151:
        v105 = nullptr;
        goto LABEL_152;
      }
      while ( 2 )
      {
        v104 = v102->m_v0;
        if ( v104 == v101 )
        {
          if ( v102->m_v1 == v103 )
            break;
          v102 = v102->m_nextV0;
          goto LABEL_150;
        }
        if ( v104 != v103 )
        {
          v102 = v102->m_nextV1;
LABEL_150:
          if ( v102 == nullptr )
            goto LABEL_151;
          continue;
        }
        break;
      }
      v105 = v102;
LABEL_152:
      v106 = (NvStripInfo *)MemAlloc_Alloc(nSize: 0x2Cu);
      if ( v106 != nullptr )
      {
        v107 = stripId;
        v220 = __PAIR64__((unsigned int)v105, (unsigned int)v21);
        *(_QWORD *)&v106->m_startInfo.m_startFace = __PAIR64__((unsigned int)v105, (unsigned int)v21);
        LOBYTE(v221) = 0;
        *(_DWORD *)&v106->m_startInfo.m_toV1 = v221;
        v108 = experimentId;
        v106->m_faces._Myfirst = nullptr;
        v106->m_faces._Mylast = nullptr;
        v106->m_faces._Myend = nullptr;
        v106->m_stripId = v107;
        v106->m_experimentId = v108;
        v106->visited = false;
        v106->m_numDegenerates = 0;
        v109 = v106;
        stripId = v107 + 1;
        experimentId = v108 + 1;
      }
      else
      {
        v109 = nullptr;
      }
      v110 = (std::vector<int> *)&experiments[experimentIndex++];
      v111 = v110->_Mylast;
      strip20 = v109;
      if ( &strip20 >= (NvStripInfo **)v111 || (v112 = v110->_Myfirst, v110->_Myfirst > (int *)&strip20) )
      {
        v120 = v110->_Myend;
        if ( v111 != v120 )
        {
LABEL_178:
          v125 = v110->_Mylast;
          if ( v125 != nullptr )
            *v125 = v109;
          goto LABEL_180;
        }
        v121 = v111 - v110->_Myfirst;
        if ( v121 <= 0x3FFFFFFE )
        {
          v122 = v121 + 1;
          v123 = v120 - v110->_Myfirst;
          if ( v122 > v123 )
          {
            if ( 0x3FFFFFFF - (v123 >> 1) >= v123 )
              v124 = (v123 >> 1) + v123;
            else
              v124 = 0;
            if ( v124 < v122 )
              v124 = v122;
            std::vector<int>::reserve(this: v110, _Count: v124);
            v21 = (NvFaceInfo *)stripIter;
          }
          goto LABEL_178;
        }
        goto LABEL_314;
      }
      v113 = v110->_Myend;
      v114 = ((char *)&strip20 - (char *)v112) >> 2;
      if ( v111 != v113 )
        goto LABEL_167;
      v115 = v111 - v112;
      if ( v115 > 0x3FFFFFFE )
        goto LABEL_314;
      v116 = v115 + 1;
      v117 = v113 - v112;
      if ( v116 > v117 )
      {
        if ( 0x3FFFFFFF - (v117 >> 1) >= v117 )
          v118 = (v117 >> 1) + v117;
        else
          v118 = 0;
        if ( v118 < v116 )
          v118 = v116;
        std::vector<int>::reserve(this: v110, _Count: v118);
        v21 = (NvFaceInfo *)stripIter;
      }
LABEL_167:
      v119 = v110->_Mylast;
      if ( v119 != nullptr )
        *v119 = v110->_Myfirst[v114];
LABEL_180:
      ++v110->_Mylast;
      v126 = v21->m_v2;
      v127 = allEdgeInfos->_Myfirst[v126];
      v128 = v21->m_v0;
      if ( v127 == nullptr )
      {
LABEL_187:
        v130 = nullptr;
        goto LABEL_188;
      }
      while ( 2 )
      {
        v129 = v127->m_v0;
        if ( v129 == v126 )
        {
          if ( v127->m_v1 == v128 )
            break;
          v127 = v127->m_nextV0;
          goto LABEL_186;
        }
        if ( v129 != v128 )
        {
          v127 = v127->m_nextV1;
LABEL_186:
          if ( v127 == nullptr )
            goto LABEL_187;
          continue;
        }
        break;
      }
      v130 = v127;
LABEL_188:
      v131 = (NvStripInfo *)MemAlloc_Alloc(nSize: 0x2Cu);
      if ( v131 != nullptr )
      {
        v132 = stripId;
        v216 = __PAIR64__((unsigned int)v130, (unsigned int)v21);
        *(_QWORD *)&v131->m_startInfo.m_startFace = __PAIR64__((unsigned int)v130, (unsigned int)v21);
        LOBYTE(v217) = 1;
        *(_DWORD *)&v131->m_startInfo.m_toV1 = v217;
        v133 = experimentId;
        v131->m_faces._Myfirst = nullptr;
        v131->m_faces._Mylast = nullptr;
        v131->m_faces._Myend = nullptr;
        v131->m_stripId = v132;
        v131->m_experimentId = v133;
        v131->visited = false;
        v131->m_numDegenerates = 0;
        v134 = v131;
        stripId = v132 + 1;
        experimentId = v133 + 1;
      }
      else
      {
        v134 = nullptr;
      }
      v135 = (std::vector<int> *)&experiments[experimentIndex++];
      v136 = v135->_Mylast;
      strip20 = v134;
      if ( &strip20 >= (NvStripInfo **)v136 || (v137 = v135->_Myfirst, v135->_Myfirst > (int *)&strip20) )
      {
        v145 = v135->_Myend;
        if ( v136 == v145 )
        {
          v146 = v136 - v135->_Myfirst;
          if ( v146 > 0x3FFFFFFE )
            goto LABEL_314;
          v147 = v146 + 1;
          v148 = v145 - v135->_Myfirst;
          if ( v147 > v148 )
          {
            if ( 0x3FFFFFFF - (v148 >> 1) >= v148 )
              v149 = (v148 >> 1) + v148;
            else
              v149 = 0;
            if ( v149 < v147 )
              v149 = v147;
            std::vector<int>::reserve(this: v135, _Count: v149);
            v21 = (NvFaceInfo *)stripIter;
          }
        }
        v150 = v135->_Mylast;
        if ( v150 != nullptr )
          *v150 = v134;
        goto LABEL_216;
      }
      v138 = v135->_Myend;
      v139 = ((char *)&strip20 - (char *)v137) >> 2;
      if ( v136 != v138 )
        goto LABEL_203;
      v140 = v136 - v137;
      if ( v140 > 0x3FFFFFFE )
        goto LABEL_314;
      v141 = v140 + 1;
      v142 = v138 - v137;
      if ( v141 > v142 )
      {
        if ( 0x3FFFFFFF - (v142 >> 1) >= v142 )
          v143 = (v142 >> 1) + v142;
        else
          v143 = 0;
        if ( v143 < v141 )
          v143 = v141;
        std::vector<int>::reserve(this: v135, _Count: v143);
        v21 = (NvFaceInfo *)stripIter;
      }
LABEL_203:
      v144 = v135->_Mylast;
      if ( v144 != nullptr )
        *v144 = v135->_Myfirst[v139];
LABEL_216:
      ++v135->_Mylast;
      v151 = v21->m_v2;
      v152 = allEdgeInfos->_Myfirst[v151];
      v153 = v21->m_v0;
      if ( v152 == nullptr )
      {
LABEL_223:
        v155 = nullptr;
        goto LABEL_224;
      }
      while ( 2 )
      {
        v154 = v152->m_v0;
        if ( v154 == v151 )
        {
          if ( v152->m_v1 == v153 )
            break;
          v152 = v152->m_nextV0;
          goto LABEL_222;
        }
        if ( v154 != v153 )
        {
          v152 = v152->m_nextV1;
LABEL_222:
          if ( v152 == nullptr )
            goto LABEL_223;
          continue;
        }
        break;
      }
      v155 = v152;
LABEL_224:
      v156 = (NvStripInfo *)MemAlloc_Alloc(nSize: 0x2Cu);
      if ( v156 != nullptr )
      {
        v157 = stripId;
        *(_QWORD *)&pExceptionObject.__vftable = __PAIR64__((unsigned int)v155, (unsigned int)v21);
        *(_QWORD *)&v156->m_startInfo.m_startFace = __PAIR64__((unsigned int)v155, (unsigned int)v21);
        pExceptionObject._Mydofree = false;
        *(_DWORD *)&v156->m_startInfo.m_toV1 = *(_DWORD *)&pExceptionObject._Mydofree;
        v158 = experimentId;
        v156->m_faces._Myfirst = nullptr;
        v156->m_faces._Mylast = nullptr;
        v156->m_faces._Myend = nullptr;
        v156->m_stripId = v157;
        v156->m_experimentId = v158;
        v156->visited = false;
        v156->m_numDegenerates = 0;
        v159 = v156;
        stripId = v157 + 1;
        experimentId = v158 + 1;
      }
      else
      {
        v159 = nullptr;
      }
      v160 = (std::vector<int> *)&experiments[experimentIndex++];
      v161 = v160->_Mylast;
      strip20 = v159;
      if ( &strip20 >= (NvStripInfo **)v161 || (v162 = v160->_Myfirst, v160->_Myfirst > (int *)&strip20) )
      {
        v170 = v160->_Myend;
        if ( v161 != v170 )
        {
LABEL_250:
          v175 = v160->_Mylast;
          if ( v175 != nullptr )
            *v175 = v159;
          goto LABEL_252;
        }
        v171 = v161 - v160->_Myfirst;
        if ( v171 <= 0x3FFFFFFE )
        {
          v172 = v171 + 1;
          v173 = v170 - v160->_Myfirst;
          if ( v172 > v173 )
          {
            if ( 0x3FFFFFFF - (v173 >> 1) >= v173 )
              v174 = (v173 >> 1) + v173;
            else
              v174 = 0;
            if ( v174 < v172 )
              v174 = v172;
            std::vector<int>::reserve(this: v160, _Count: v174);
          }
          goto LABEL_250;
        }
LABEL_314:
        std::_Xlength_error(_Message: "vector<T> too long");
      }
      v163 = v160->_Myend;
      v164 = ((char *)&strip20 - (char *)v162) >> 2;
      if ( v161 != v163 )
        goto LABEL_239;
      v165 = v161 - v162;
      if ( v165 > 0x3FFFFFFE )
        goto LABEL_314;
      v166 = v165 + 1;
      v167 = v163 - v162;
      if ( v166 > v167 )
      {
        if ( 0x3FFFFFFF - (v167 >> 1) >= v167 )
          v168 = (v167 >> 1) + v167;
        else
          v168 = 0;
        if ( v168 < v166 )
          v168 = v166;
        std::vector<int>::reserve(this: v160, _Count: v168);
      }
LABEL_239:
      v169 = v160->_Mylast;
      if ( v169 != nullptr )
        *v169 = v160->_Myfirst[v164];
LABEL_252:
      ++v160->_Mylast;
      Myhead = resetPoints._Myhead;
LABEL_253:
      ++i;
    }
    while ( i < numSamples );
LABEL_256:
    i = 0;
    if ( experimentIndex > 0 )
    {
      v176 = experiments;
      do
      {
        v177 = allEdgeInfos;
        NvStripInfo::Build(this: *v176->_Myfirst, edgeInfos: allEdgeInfos, faceInfos: allFaceInfos);
        v210 = *v176->_Myfirst;
        value = *(float *)&v210->m_experimentId;
        memset(&startInfo, 0, 9);
        if ( NvStripifier::FindTraversal(this: v231, faceInfos: allFaceInfos, edgeInfos: v177, strip: v210, &startInfo) )
        {
          do
          {
            v178 = (NvStripInfo *)MemAlloc_Alloc(nSize: 0x2Cu);
            if ( v178 != nullptr )
            {
              v179 = (NvFaceInfo *)LODWORD(value);
              v178->m_startInfo = startInfo;
              v180 = stripId;
              v178->m_faces._Myfirst = nullptr;
              v178->m_faces._Mylast = nullptr;
              v178->m_faces._Myend = nullptr;
              v178->m_stripId = v180;
              v178->m_experimentId = (int)v179;
              v178->visited = false;
              v178->m_numDegenerates = 0;
              v181 = v178;
              stripId = v180 + 1;
            }
            else
            {
              v181 = nullptr;
            }
            stripIter = v181;
            NvStripInfo::Build(this: v181, edgeInfos: allEdgeInfos, faceInfos: allFaceInfos);
            v182 = v176->_Mylast;
            if ( &stripIter >= v182 || (v183 = v176->_Myfirst, v176->_Myfirst > &stripIter) )
            {
              v191 = v176->_Myend;
              if ( v182 == v191 )
              {
                v192 = v182 - v176->_Myfirst;
                if ( v192 > 0x3FFFFFFE )
                  goto LABEL_314;
                v193 = v192 + 1;
                v194 = v191 - v176->_Myfirst;
                if ( v193 > v194 )
                {
                  if ( 0x3FFFFFFF - (v194 >> 1) >= v194 )
                    v195 = (v194 >> 1) + v194;
                  else
                    v195 = 0;
                  if ( v195 < v193 )
                    v195 = v193;
                  std::vector<int>::reserve(this: (std::vector<int> *)v176, _Count: v195);
                }
              }
              v196 = v176->_Mylast;
              if ( v196 != nullptr )
                *v196 = v181;
            }
            else
            {
              v184 = v176->_Myend;
              v185 = &stripIter - v183;
              if ( v182 == v184 )
              {
                v186 = v182 - v183;
                if ( v186 > 0x3FFFFFFE )
                  goto LABEL_314;
                v187 = v186 + 1;
                v188 = v184 - v183;
                if ( v187 > v188 )
                {
                  if ( 0x3FFFFFFF - (v188 >> 1) >= v188 )
                    v189 = (v188 >> 1) + v188;
                  else
                    v189 = 0;
                  if ( v189 < v187 )
                    v189 = v187;
                  std::vector<int>::reserve(this: (std::vector<int> *)v176, _Count: v189);
                  v181 = stripIter;
                }
              }
              v190 = v176->_Mylast;
              if ( v190 != nullptr )
                *v190 = v176->_Myfirst[v185];
            }
            v197 = allEdgeInfos;
            ++v176->_Mylast;
          }
          while ( NvStripifier::FindTraversal(
                    this: v231,
                    faceInfos: allFaceInfos,
                    edgeInfos: v197,
                    strip: v181,
                    &startInfo) );
        }
        ++v176;
        ++i;
      }
      while ( i < experimentIndex );
    }
    v198 = 0;
    v199 = 0;
    i = 0;
    bestValue = 0.0;
    if ( experimentIndex > 0 )
    {
      v200 = experiments;
      do
      {
        v201 = NvStripifier::AvgStripSize(this: v231, strips: v200)
             + (double)(unsigned int)(v200->_Mylast - v200->_Myfirst) * 0.0;
        value = v201;
        if ( v201 > bestValue )
        {
          bestValue = value;
          v198 = v199;
        }
        ++v199;
        ++v200;
      }
      while ( v199 < experimentIndex );
      i = v198;
    }
    NvStripifier::CommitStrips(this: v231, allStrips, strips: &experiments[v198]);
    stripIter = nullptr;
    if ( experimentIndex > 0 )
    {
      strip20 = (NvStripInfo *)experiments;
      do
      {
        if ( stripIter != (NvStripInfo *)i )
        {
          v202 = strip20;
          v203 = 0;
          v204 = ((char *)strip20->m_startInfo.m_startEdge - (char *)strip20->m_startInfo.m_startFace) >> 2;
          if ( v204 > 0 )
          {
            while ( 1 )
            {
              v205 = *(&v202->m_startInfo.m_startFace->m_v0 + v203);
              if ( v205 != 0 )
              {
                if ( *(_DWORD *)(v205 + 12) != 0 )
                  free(pMem: *(void **)(v205 + 12));
                *(_DWORD *)(v205 + 12) = 0;
                *(_DWORD *)(v205 + 16) = 0;
                *(_DWORD *)(v205 + 20) = 0;
                free(pMem: (void *)v205);
              }
              if ( ++v203 >= v204 )
                break;
              v202 = strip20;
            }
          }
        }
        strip20 = (NvStripInfo *)((char *)strip20 + 16);
        stripIter = (NvStripInfo *)((char *)stripIter + 1);
      }
      while ( (int)stripIter < experimentIndex );
    }
    if ( experiments != nullptr )
    {
      p_Alval = &experiments[-1]._Alval;
      v207 = &experiments[*(_DWORD *)&experiments[-1]._Alval.std::_Allocator_base<NvStripInfo *>];
      for ( k = *(_DWORD *)&experiments[-1]._Alval.std::_Allocator_base<NvStripInfo *> - 1; k >= 0; v207->_Myend = nullptr )
      {
        v209 = v207[-1]._Myfirst;
        --v207;
        if ( v209 != nullptr )
          free(pMem: v209);
        --k;
        v207->_Myfirst = nullptr;
        v207->_Mylast = nullptr;
      }
      free(pMem: p_Alval);
    }
    std::_Tree<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0>>::erase(
      this: &resetPoints,
      result: &v212,
      _First: (std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> > >)resetPoints._Myhead->_Left,
      _Last: (std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<NvFaceInfo *,std::less<NvFaceInfo *>,std::allocator<NvFaceInfo *>,0> > >)resetPoints._Myhead);
    free(pMem: resetPoints._Myhead);
    if ( !done )
    {
      v6 = v224;
      v5 = numSamples;
      continue;
    }
    break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005B4D20
// Name: public: void NvStripifier::Stripify(class std::vector<unsigned short,class std::allocator<unsigned short>> const __near &,int,int,unsigned short,class std::vector<class NvStripInfo __near *,class std::allocator<class NvStripInfo __near *>> __near &,class std::vector<class NvFaceInfo __near *,class std::allocator<class NvFaceInfo __near *>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall NvStripifier::Stripify(
        NvStripifier *this,
        const std::vector<unsigned short> *in_indices,
        int in_cacheSize,
        int in_minStripLength,
        unsigned __int16 maxIndex,
        std::vector<NvStripInfo *> *outStrips,
        std::vector<NvFaceInfo *> *outFaceList)
{
  int v8; // eax
  unsigned int v9; // ebx
  unsigned int v10; // edi
  NvStripInfo *v11; // esi
  NvEdgeInfo **Myfirst; // esi
  unsigned int v13; // ebx
  unsigned int i; // edi
  NvEdgeInfo *v15; // eax
  NvEdgeInfo *m_nextV0; // esi
  std::vector<NvFaceInfo *> allFaceInfos; // [esp+0h] [ebp-30h] BYREF
  std::vector<NvStripInfo *> allStrips; // [esp+10h] [ebp-20h] BYREF
  std::vector<NvEdgeInfo *> allEdgeInfos; // [esp+20h] [ebp-10h] BYREF

  v8 = in_cacheSize - 6;
  this->meshJump = 0.0;
  this->bFirstTimeResetPoint = true;
  if ( in_cacheSize - 6 < 1 )
    v8 = 1;
  this->cacheSize = v8;
  this->minStripLength = in_minStripLength;
  std::vector<unsigned short>::operator=(this: &this->indices, _Right: in_indices);
  v9 = 0;
  memset(&allFaceInfos, 0, 12);
  memset(&allEdgeInfos, 0, 12);
  NvStripifier::BuildStripifyInfo(this, faceInfos: &allFaceInfos, edgeInfos: &allEdgeInfos, maxIndex);
  memset(&allStrips, 0, 12);
  NvStripifier::FindAllStrips(this, (NvStripInfo *)&allStrips, &allFaceInfos, &allEdgeInfos, numSamples: 10);
  NvStripifier::SplitUpStripsAndOptimize(this, &allStrips, outStrips, edgeInfos: &allEdgeInfos, outFaceList);
  v10 = allStrips._Mylast - allStrips._Myfirst;
  if ( v10 != 0 )
  {
    do
    {
      v11 = allStrips._Myfirst[v9];
      if ( v11 != nullptr )
      {
        if ( v11->m_faces._Myfirst != nullptr )
          free(pMem: v11->m_faces._Myfirst);
        v11->m_faces._Myfirst = nullptr;
        v11->m_faces._Mylast = nullptr;
        v11->m_faces._Myend = nullptr;
        free(pMem: v11);
      }
      ++v9;
    }
    while ( v9 < v10 );
  }
  Myfirst = allEdgeInfos._Myfirst;
  v13 = allEdgeInfos._Mylast - allEdgeInfos._Myfirst;
  for ( i = 0; i < v13; ++i )
  {
    v15 = Myfirst[i];
    if ( v15 != nullptr )
    {
      do
      {
        if ( v15->m_v0 == i )
          m_nextV0 = v15->m_nextV0;
        else
          m_nextV0 = v15->m_nextV1;
        if ( v15->m_refCount-- == 1 )
          free(pMem: v15);
        v15 = m_nextV0;
      }
      while ( m_nextV0 != nullptr );
      Myfirst = allEdgeInfos._Myfirst;
    }
  }
  if ( allStrips._Myfirst != nullptr )
    free(pMem: allStrips._Myfirst);
  if ( Myfirst != nullptr )
    free(pMem: Myfirst);
  if ( allFaceInfos._Myfirst != nullptr )
    free(pMem: allFaceInfos._Myfirst);
}

} // namespace studiomdl
