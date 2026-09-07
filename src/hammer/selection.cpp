// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/selection.cpp
// Functions: 25
// ============================================================

#include "hammer\selection.h"

//------------------------------------------------------------------------------
// Address: 0x100A2770
// Name: public: void CSelection::GetLastValidBounds(class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSelection::GetLastValidBounds(CSelection *this, Vector *vecMins, Vector *vecMaxs)
{
  *vecMins = this->m_LastValidBounds.bmins;
  *vecMaxs = this->m_LastValidBounds.bmaxs;
}

//------------------------------------------------------------------------------
// Address: 0x100A27C0
// Name: public: bool CSelection::IsEmpty(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CSelection::IsEmpty(CSelection *this)
{
  return this->m_SelectionList.m_Size == 0;
}

//------------------------------------------------------------------------------
// Address: 0x100A27E0
// Name: public: void CSelection::GetBoundsForTranslation(class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSelection::GetBoundsForTranslation(CSelection *this, Vector *vecMins, Vector *vecMaxs)
{
  int v3; // edi
  CMapClass *m_pObject; // ebx
  _DWORD *v6; // eax
  int v7; // eax
  int i; // ebx
  CMapClass *v9; // edi
  _DWORD *v10; // eax
  int v11; // eax
  double x; // xmm0_8
  float y; // xmm1_4
  float v14; // xmm0_4
  double v15; // xmm0_8
  double v16; // xmm1_8
  float z; // xmm1_4
  float v18; // xmm0_4
  double v19; // xmm0_8
  double v20; // xmm1_8
  float v21; // xmm0_4
  double v22; // xmm0_8
  float v23; // xmm1_4
  float v24; // xmm0_4
  double v25; // xmm0_8
  double v26; // xmm1_8
  float v27; // xmm1_4
  float v28; // xmm0_4
  double v29; // xmm0_8
  double v30; // xmm1_8
  float v31; // xmm0_4
  Vector maxs; // [esp+0h] [ebp-1Ch] BYREF
  Vector mins; // [esp+Ch] [ebp-10h] BYREF
  int nSolids; // [esp+18h] [ebp-4h]

  vecMins->x = 99999.0;
  vecMins->y = 99999.0;
  vecMins->z = 0.0;
  v3 = 0;
  vecMaxs->x = -99999.0;
  vecMaxs->y = -99999.0;
  vecMaxs->z = 0.0;
  for ( nSolids = 0; v3 < this->m_SelectionList.m_Size; ++v3 )
  {
    m_pObject = this->m_SelectionList.m_Memory.m_pMemory[v3 >> ((unsigned __int64)*((int *)&this->m_SelectionList.m_Memory
                                                                                  + 2) >> 27)][v3
                                                                                             & ((32
                                                                                               * *((_DWORD *)&this->m_SelectionList.m_Memory
                                                                                                 + 2)) >> 5)].m_pObject;
    v6 = __RTDynamicCast(
           inptr: m_pObject,
           VfDelta: 0,
           SrcType: &CMapClass `RTTI Type Descriptor',
           TargetType: &CEditGameClass `RTTI Type Descriptor',
           isReference: 0);
    if ( v6 != nullptr && (v7 = v6[8]) != 0 && *(_BYTE *)(v7 + 9) != 0
      || __RTDynamicCast(
           inptr: m_pObject,
           VfDelta: 0,
           SrcType: &CMapClass `RTTI Type Descriptor',
           TargetType: &CMapSolid `RTTI Type Descriptor',
           isReference: 0) != nullptr )
    {
      ++nSolids;
    }
  }
  for ( i = 0; i < this->m_SelectionList.m_Size; vecMaxs->z = v31 )
  {
    v9 = this->m_SelectionList.m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&this->m_SelectionList.m_Memory + 2) >> 27)][i & ((32 * *((_DWORD *)&this->m_SelectionList.m_Memory + 2)) >> 5)].m_pObject;
    v10 = __RTDynamicCast(
            inptr: v9,
            VfDelta: 0,
            SrcType: &CMapClass `RTTI Type Descriptor',
            TargetType: &CEditGameClass `RTTI Type Descriptor',
            isReference: 0);
    if ( v10 != nullptr && (v11 = v10[8]) != 0 && *(_BYTE *)(v11 + 9) != 0
      || __RTDynamicCast(
           inptr: v9,
           VfDelta: 0,
           SrcType: &CMapClass `RTTI Type Descriptor',
           TargetType: &CMapSolid `RTTI Type Descriptor',
           isReference: 0) != nullptr )
    {
      CMapClass::GetRender2DBox(this: v9, &mins, &maxs);
    }
    else if ( nSolids == 0 )
    {
      v9->GetOrigin(this: v9, a2: &mins);
      maxs = mins;
    }
    x = mins.x;
    if ( mins.x > (double)vecMins->x )
      x = vecMins->x;
    y = vecMins->y;
    v14 = x;
    vecMins->x = v14;
    v15 = mins.y;
    v16 = y;
    if ( mins.y > v16 )
      v15 = v16;
    z = vecMins->z;
    v18 = v15;
    vecMins->y = v18;
    v19 = mins.z;
    v20 = z;
    if ( mins.z > v20 )
      v19 = v20;
    v21 = v19;
    vecMins->z = v21;
    v22 = maxs.x;
    if ( maxs.x < (double)vecMaxs->x )
      v22 = vecMaxs->x;
    v23 = vecMaxs->y;
    v24 = v22;
    vecMaxs->x = v24;
    v25 = maxs.y;
    v26 = v23;
    if ( maxs.y < v26 )
      v25 = v26;
    v27 = vecMaxs->z;
    v28 = v25;
    vecMaxs->y = v28;
    v29 = maxs.z;
    v30 = v27;
    if ( maxs.z < v30 )
      v29 = v30;
    v31 = v29;
    ++i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A2A40
// Name: protected: void CSelection::UpdateSelectionBounds(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSelection::UpdateSelectionBounds(CSelection *this)
{
  int v2; // ebx
  CMapClass *m_pObject; // edi
  float x; // xmm0_4
  float y; // xmm1_4
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  Vector mins; // [esp+Ch] [ebp-28h] BYREF
  Vector maxs; // [esp+18h] [ebp-1Ch] BYREF
  Vector2D logicalMaxs; // [esp+24h] [ebp-10h] BYREF
  Vector2D logicalMins; // [esp+2Ch] [ebp-8h] BYREF

  BoundBox::ResetBounds(this: &this->m_Bounds);
  v2 = 0;
  this->m_vecLogicalMins.y = 99999.0;
  this->m_vecLogicalMins.x = 99999.0;
  this->m_vecLogicalMaxs.y = -99999.0;
  for ( this->m_vecLogicalMaxs.x = -99999.0; v2 < this->m_SelectionList.m_Size; this->m_vecLogicalMaxs.y = v10 )
  {
    m_pObject = this->m_SelectionList.m_Memory.m_pMemory[v2 >> ((unsigned __int64)*((int *)&this->m_SelectionList.m_Memory
                                                                                  + 2) >> 27)][v2
                                                                                             & ((32
                                                                                               * *((_DWORD *)&this->m_SelectionList.m_Memory
                                                                                                 + 2)) >> 5)].m_pObject;
    CMapClass::GetRender2DBox(this: m_pObject, &mins, &maxs);
    BoundBox::UpdateBounds(this: &this->m_Bounds, &mins, &maxs);
    m_pObject->GetRenderLogicalBox(this: m_pObject, a2: &logicalMins, a3: &logicalMaxs);
    x = this->m_vecLogicalMins.x;
    if ( x > logicalMins.x )
      x = logicalMins.x;
    y = logicalMins.y;
    this->m_vecLogicalMins.x = x;
    v6 = this->m_vecLogicalMins.y;
    if ( v6 > y )
      v6 = y;
    v7 = logicalMaxs.x;
    this->m_vecLogicalMins.y = v6;
    v8 = this->m_vecLogicalMaxs.x;
    if ( v7 > v8 )
      v8 = v7;
    v9 = logicalMaxs.y;
    this->m_vecLogicalMaxs.x = v8;
    v10 = this->m_vecLogicalMaxs.y;
    if ( v9 > v10 )
      v10 = v9;
    ++v2;
  }
  if ( BoundBox::IsValidBox(this: &this->m_Bounds) )
  {
    this->m_LastValidBounds.bmins.x = this->m_Bounds.bmins.x;
    this->m_LastValidBounds.bmins.y = this->m_Bounds.bmins.y;
    this->m_LastValidBounds.bmins.z = this->m_Bounds.bmins.z;
    this->m_LastValidBounds.bmaxs.x = this->m_Bounds.bmaxs.x;
    this->m_LastValidBounds.bmaxs.y = this->m_Bounds.bmaxs.y;
    this->m_LastValidBounds.bmaxs.z = this->m_Bounds.bmaxs.z;
  }
  this->m_bBoundsDirty = false;
}

//------------------------------------------------------------------------------
// Address: 0x100A2B80
// Name: public: bool CSelection::GetBoundsCenter(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSelection::GetBoundsCenter(CSelection *this, Vector *vecCenter)
{
  if ( this->m_bBoundsDirty )
    CSelection::UpdateSelectionBounds(this);
  if ( this->m_SelectionList.m_Size == 0 )
    return 0;
  BoundBox::GetBoundsCenter(this: &this->m_Bounds, ptdest: vecCenter);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100A2BC0
// Name: public: bool CSelection::GetLogicalBoundsCenter(class Vector2D __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSelection::GetLogicalBoundsCenter(CSelection *this, Vector2D *vecCenter)
{
  float v4; // xmm1_4

  if ( this->m_bBoundsDirty )
    CSelection::UpdateSelectionBounds(this);
  if ( this->m_SelectionList.m_Size == 0 )
    return 0;
  v4 = (float)(this->m_vecLogicalMaxs.y + this->m_vecLogicalMins.y) * 0.5;
  vecCenter->x = (float)(this->m_vecLogicalMaxs.x + this->m_vecLogicalMins.x) * 0.5;
  vecCenter->y = v4;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100A2C20
// Name: public: bool CSelection::IsAnEntitySelected(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSelection::IsAnEntitySelected(CSelection *this)
{
  int m_Size; // ebx
  int v3; // esi

  m_Size = this->m_SelectionList.m_Size;
  if ( m_Size <= 0 )
    return 0;
  v3 = 0;
  while ( __RTDynamicCast(
            inptr: this->m_SelectionList.m_Memory.m_pMemory[v3 >> ((unsigned __int64)*((int *)&this->m_SelectionList.m_Memory
                                                                              + 2) >> 27)][v3
                                                                                         & ((32
                                                                                           * *((_DWORD *)&this->m_SelectionList.m_Memory
                                                                                             + 2)) >> 5)].m_pObject,
            VfDelta: 0,
            SrcType: &CMapClass `RTTI Type Descriptor',
            TargetType: &CMapEntity `RTTI Type Descriptor',
            isReference: 0) == nullptr )
  {
    if ( ++v3 >= m_Size )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100A2C80
// Name: public: bool CSelection::IsEditable(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSelection::IsEditable(CSelection *this)
{
  int m_Size; // ebx
  int v3; // esi
  CMapClass *m_pObject; // ecx

  m_Size = this->m_SelectionList.m_Size;
  if ( m_Size <= 0 )
    return 1;
  v3 = 0;
  while ( 1 )
  {
    m_pObject = this->m_SelectionList.m_Memory.m_pMemory[v3 >> ((unsigned __int64)*((int *)&this->m_SelectionList.m_Memory
                                                                                  + 2) >> 27)][v3
                                                                                             & ((32
                                                                                               * *((_DWORD *)&this->m_SelectionList.m_Memory
                                                                                                 + 2)) >> 5)].m_pObject;
    if ( !m_pObject->IsEditable(this: m_pObject) )
      break;
    if ( ++v3 >= m_Size )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100A2CE0
// Name: public: bool CSelection::IsCopyable(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSelection::IsCopyable(CSelection *this)
{
  int m_Size; // ebx
  int v3; // esi
  CMapClass *m_pObject; // ecx

  m_Size = this->m_SelectionList.m_Size;
  if ( m_Size <= 0 )
    return 1;
  v3 = 0;
  while ( 1 )
  {
    m_pObject = this->m_SelectionList.m_Memory.m_pMemory[v3 >> ((unsigned __int64)*((int *)&this->m_SelectionList.m_Memory
                                                                                  + 2) >> 27)][v3
                                                                                             & ((32
                                                                                               * *((_DWORD *)&this->m_SelectionList.m_Memory
                                                                                                 + 2)) >> 5)].m_pObject;
    if ( m_pObject->IsMapClass(this: m_pObject, a2: CManifestInstance::__Type) != 0 )
      break;
    if ( ++v3 >= m_Size )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100A2D40
// Name: public: bool CSelection::GetBounds(class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSelection::GetBounds(CSelection *this, Vector *vecMins, Vector *vecMaxs)
{
  if ( this->m_bBoundsDirty )
    CSelection::UpdateSelectionBounds(this);
  if ( this->m_SelectionList.m_Size == 0 )
    return 0;
  *vecMins = this->m_Bounds.bmins;
  *vecMaxs = this->m_Bounds.bmaxs;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100A2D90
// Name: public: bool CSelection::GetLogicalBounds(class Vector2D __near &,class Vector2D __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSelection::GetLogicalBounds(CSelection *this, Vector2D *vecMins, Vector2D *vecMaxs)
{
  if ( this->m_bBoundsDirty )
    CSelection::UpdateSelectionBounds(this);
  if ( this->m_SelectionList.m_Size == 0 )
    return 0;
  *vecMins = this->m_vecLogicalMins;
  *vecMaxs = this->m_vecLogicalMaxs;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100A2DE0
// Name: public: bool CSelection::IsSelected(class CMapClass __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSelection::IsSelected(CSelection *this, CMapClass *pobj)
{
  CUtlReference<CMapClass> *m_pHead; // edx
  bool result; // al
  CUtlReference<CMapClass> src; // [esp+4h] [ebp-18h] BYREF
  int v5; // [esp+18h] [ebp-4h]

  src.m_pPrev = nullptr;
  src.m_pNext = nullptr;
  src.m_pObject = pobj;
  if ( pobj != nullptr )
  {
    m_pHead = pobj->m_References.m_pHead;
    src.m_pNext = m_pHead;
    if ( m_pHead != nullptr )
      m_pHead->m_pPrev = &src;
    src.m_pPrev = nullptr;
    pobj->m_References.m_pHead = &src;
  }
  v5 = 0;
  result = CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::Find(
             this: &this->m_SelectionList,
             &src) != -1;
  v5 = -1;
  if ( src.m_pObject != nullptr )
  {
    if ( src.m_pPrev != nullptr )
    {
      src.m_pPrev->m_pNext = src.m_pNext;
      if ( src.m_pNext != nullptr )
        src.m_pNext->m_pPrev = src.m_pPrev;
    }
    else if ( src.m_pObject->m_References.m_pHead == &src )
    {
      src.m_pObject->m_References.m_pHead = src.m_pNext;
      if ( src.m_pNext != nullptr )
        src.m_pNext->m_pPrev = nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A2EA0
// Name: public: void CSelection::SetSelectionState(enum SelectionState_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSelection::SetSelectionState(CSelection *this, SelectionState_t eSelectionState)
{
  int i; // esi
  CMapClass *m_pObject; // eax
  CUtlReference<CMapClass> *v5; // ecx
  CMapClass *v6; // ecx
  CUtlReference<CMapClass> *m_pHead; // [esp+Ch] [ebp-18h] BYREF
  CUtlReference<CMapClass> *v8; // [esp+10h] [ebp-14h]
  CMapClass *v9; // [esp+14h] [ebp-10h]
  int v10; // [esp+20h] [ebp-4h]

  for ( i = 0; i < this->m_SelectionList.m_Size; ++i )
  {
    m_pObject = this->m_SelectionList.m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&this->m_SelectionList.m_Memory
                                                                                 + 2) >> 27)][i
                                                                                            & ((32
                                                                                              * *((_DWORD *)&this->m_SelectionList.m_Memory
                                                                                                + 2)) >> 5)].m_pObject;
    if ( m_pObject != nullptr )
    {
      v9 = this->m_SelectionList.m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&this->m_SelectionList.m_Memory + 2) >> 27)][i & ((32 * *((_DWORD *)&this->m_SelectionList.m_Memory + 2)) >> 5)].m_pObject;
      m_pHead = m_pObject->m_References.m_pHead;
      v5 = m_pObject->m_References.m_pHead;
      if ( v5 != nullptr )
        v5->m_pPrev = (CUtlReference<CMapClass> *)&m_pHead;
      v8 = nullptr;
      m_pObject->m_References.m_pHead = (CUtlReference<CMapClass> *)&m_pHead;
    }
    v6 = v9;
    v10 = -1;
    if ( v9 != nullptr )
    {
      if ( v8 != nullptr )
      {
        v8->m_pNext = m_pHead;
        if ( m_pHead != nullptr )
          m_pHead->m_pPrev = v8;
      }
      else if ( (CUtlReference<CMapClass> **)v9->m_References.m_pHead == &m_pHead )
      {
        v9->m_References.m_pHead = m_pHead;
        if ( m_pHead != nullptr )
          m_pHead->m_pPrev = nullptr;
      }
      v8 = nullptr;
      m_pHead = nullptr;
      v9 = nullptr;
    }
    v6->SetSelectionState(this: v6, a2: eSelectionState);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A2F90
// Name: public: bool CSelection::RemoveDead(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSelection::RemoveDead(CSelection *this)
{
  bool result; // al
  int v2; // edi
  CUtlReferenceVector<CMapClass> *p_m_SelectionList; // ebx
  CMapClass *m_pObject; // esi
  CSelection *v5; // [esp+4h] [ebp-8h]
  bool bFoundOne; // [esp+Bh] [ebp-1h]

  result = false;
  v2 = this->m_SelectionList.m_Size - 1;
  v5 = this;
  bFoundOne = false;
  if ( v2 >= 0 )
  {
    p_m_SelectionList = &this->m_SelectionList;
    do
    {
      m_pObject = p_m_SelectionList->m_Memory.m_pMemory[v2 >> ((unsigned __int64)*((int *)&p_m_SelectionList->m_Memory
                                                                                 + 2) >> 27)][v2
                                                                                            & ((32
                                                                                              * *((_DWORD *)&p_m_SelectionList->m_Memory
                                                                                                + 2)) >> 5)].m_pObject;
      if ( m_pObject->GetParent(this: m_pObject) == nullptr )
      {
        CUtlReferenceVector<CMapClass>::FastRemove(this: p_m_SelectionList, elem: v2);
        m_pObject->SetSelectionState(this: m_pObject, a2: SELECT_NONE);
        bFoundOne = true;
      }
      --v2;
    }
    while ( v2 >= 0 );
    this = v5;
    result = bFoundOne;
  }
  this->m_bBoundsDirty = true;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A3010
// Name: public: bool CSelection::RemoveInvisibles(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSelection::RemoveInvisibles(CSelection *this)
{
  bool result; // al
  int v2; // esi
  CUtlReferenceVector<CMapClass> *p_m_SelectionList; // ebx
  CMapClass *m_pObject; // edi
  CSelection *v5; // [esp+4h] [ebp-4h]

  result = false;
  v2 = this->m_SelectionList.m_Size - 1;
  v5 = this;
  if ( v2 >= 0 )
  {
    p_m_SelectionList = &this->m_SelectionList;
    do
    {
      m_pObject = p_m_SelectionList->m_Memory.m_pMemory[v2 >> ((unsigned __int64)*((int *)&p_m_SelectionList->m_Memory
                                                                                 + 2) >> 27)][v2
                                                                                            & ((32
                                                                                              * *((_DWORD *)&p_m_SelectionList->m_Memory
                                                                                                + 2)) >> 5)].m_pObject;
      if ( (*((_BYTE *)m_pObject + 180) & 2) == 0 )
      {
        CUtlReferenceVector<CMapClass>::FastRemove(this: p_m_SelectionList, elem: v2);
        m_pObject->SetSelectionState(this: m_pObject, a2: SELECT_NONE);
        result = true;
      }
      --v2;
    }
    while ( v2 >= 0 );
    this = v5;
  }
  this->m_bBoundsDirty = true;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A3080
// Name: public: void CSelection::AddHit(class CMapClass __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSelection::AddHit(CSelection *this, CMapClass *pObject)
{
  CUtlReference<CMapClass> *m_pHead; // eax
  CUtlReferenceVector<CMapClass> *p_m_HitList; // esi
  bool v4; // dl
  CUtlReference<CMapClass> *v5; // eax
  CUtlReference<CMapClass> src; // [esp+Ch] [ebp-18h] BYREF
  int v7; // [esp+20h] [ebp-4h]

  src.m_pPrev = nullptr;
  src.m_pNext = nullptr;
  src.m_pObject = pObject;
  if ( pObject != nullptr )
  {
    m_pHead = pObject->m_References.m_pHead;
    src.m_pNext = m_pHead;
    if ( m_pHead != nullptr )
      m_pHead->m_pPrev = &src;
    src.m_pPrev = nullptr;
    pObject->m_References.m_pHead = &src;
  }
  v7 = 0;
  p_m_HitList = &this->m_HitList;
  v4 = CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::Find(
         this: &this->m_HitList,
         &src) == -1;
  v7 = -1;
  if ( src.m_pObject != nullptr )
  {
    if ( src.m_pPrev != nullptr )
    {
      src.m_pPrev->m_pNext = src.m_pNext;
      if ( src.m_pNext != nullptr )
        src.m_pNext->m_pPrev = src.m_pPrev;
    }
    else if ( src.m_pObject->m_References.m_pHead == &src )
    {
      src.m_pObject->m_References.m_pHead = src.m_pNext;
      if ( src.m_pNext != nullptr )
        src.m_pNext->m_pPrev = nullptr;
    }
    memset(&src, 0, sizeof(src));
  }
  if ( v4 )
  {
    src.m_pPrev = nullptr;
    src.m_pNext = nullptr;
    src.m_pObject = pObject;
    if ( pObject != nullptr )
    {
      v5 = pObject->m_References.m_pHead;
      src.m_pNext = v5;
      if ( v5 != nullptr )
        v5->m_pPrev = &src;
      src.m_pPrev = nullptr;
      pObject->m_References.m_pHead = &src;
    }
    v7 = 1;
    CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::InsertBefore(
      this: p_m_HitList,
      elem: p_m_HitList->m_Size,
      &src);
    v7 = -1;
    if ( src.m_pObject != nullptr )
    {
      if ( src.m_pPrev != nullptr )
      {
        src.m_pPrev->m_pNext = src.m_pNext;
        if ( src.m_pNext != nullptr )
          src.m_pNext->m_pPrev = src.m_pPrev;
      }
      else if ( src.m_pObject->m_References.m_pHead == &src )
      {
        src.m_pObject->m_References.m_pHead = src.m_pNext;
        if ( src.m_pNext != nullptr )
          src.m_pNext->m_pPrev = nullptr;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A31D0
// Name: public: void CSelection::ClearHitList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSelection::ClearHitList(CSelection *this)
{
  CUtlReferenceVector<CMapClass>::RemoveAll(this: &this->m_HitList);
  this->m_iCurHit = -1;
}

//------------------------------------------------------------------------------
// Address: 0x100A31F0
// Name: public: bool CSelection::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSelection::RemoveAll(CSelection *this)
{
  int i; // esi
  CMapClass *m_pObject; // ecx

  for ( i = 0; i < this->m_SelectionList.m_Size; ++i )
  {
    m_pObject = this->m_SelectionList.m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&this->m_SelectionList.m_Memory
                                                                                 + 2) >> 27)][i
                                                                                            & ((32
                                                                                              * *((_DWORD *)&this->m_SelectionList.m_Memory
                                                                                                + 2)) >> 5)].m_pObject;
    m_pObject->SetSelectionState(this: m_pObject, a2: SELECT_NONE);
  }
  CUtlReferenceVector<CMapClass>::RemoveAll(this: &this->m_SelectionList);
  this->m_bBoundsDirty = true;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100A3250
// Name: public: bool CSelection::SelectObject(class CMapClass __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSelection::SelectObject(CSelection *this, CMapClass *pObj, __int16 cmd)
{
  CSelection *v3; // edi
  CUtlReference<CMapClass> *m_pHead; // eax
  CUtlReferenceVector<CMapClass> *p_m_SelectionList; // edi
  int v6; // eax
  __int16 v7; // dx
  CUtlReference<CMapClass> *v8; // eax
  CMainFrame *MainWnd; // eax
  CMainFrame *v10; // eax
  CUtlReference<CMapClass> src; // [esp+Ch] [ebp-1Ch] BYREF
  CSelection *v13; // [esp+18h] [ebp-10h]
  int v14; // [esp+24h] [ebp-4h]

  v3 = this;
  v13 = this;
  if ( pObj == nullptr )
  {
    if ( this->m_SelectionList.m_Size != 0 )
    {
      if ( (cmd & 0x10) != 0 )
        CSelection::RemoveAll(this);
      goto LABEL_41;
    }
    return 0;
  }
  m_pHead = pObj->m_References.m_pHead;
  src.m_pPrev = nullptr;
  src.m_pObject = pObj;
  src.m_pNext = m_pHead;
  if ( m_pHead != nullptr )
    m_pHead->m_pPrev = &src;
  src.m_pPrev = nullptr;
  pObj->m_References.m_pHead = &src;
  v14 = 0;
  p_m_SelectionList = &this->m_SelectionList;
  v6 = CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::Find(
         this: &this->m_SelectionList,
         &src);
  v14 = -1;
  if ( src.m_pObject != nullptr )
  {
    if ( src.m_pPrev != nullptr )
    {
      src.m_pPrev->m_pNext = src.m_pNext;
      if ( src.m_pNext != nullptr )
        src.m_pNext->m_pPrev = src.m_pPrev;
    }
    else if ( src.m_pObject->m_References.m_pHead == &src )
    {
      src.m_pObject->m_References.m_pHead = src.m_pNext;
      if ( src.m_pNext != nullptr )
        src.m_pNext->m_pPrev = nullptr;
    }
    memset(&src, 0, sizeof(src));
  }
  LOBYTE(v7) = cmd;
  if ( (cmd & 1) != 0 )
  {
    if ( v6 == -1 )
      v7 = cmd | 2;
    else
      v7 = cmd | 4;
    cmd = v7;
  }
  if ( (v7 & 2) != 0 )
  {
    if ( (v7 & 0x10) != 0 )
    {
      if ( v6 != -1 && v13->m_SelectionList.m_Size == 1 )
        return 0;
      CSelection::RemoveAll(this: v13);
    }
    else if ( v6 != -1 )
    {
      return 0;
    }
    v8 = pObj->m_References.m_pHead;
    src.m_pPrev = nullptr;
    src.m_pObject = pObj;
    src.m_pNext = v8;
    if ( v8 != nullptr )
      v8->m_pPrev = &src;
    src.m_pPrev = nullptr;
    pObj->m_References.m_pHead = &src;
    v14 = 1;
    CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::InsertBefore(
      this: p_m_SelectionList,
      elem: p_m_SelectionList->m_Size,
      &src);
    v14 = -1;
    if ( src.m_pObject != nullptr )
    {
      if ( src.m_pPrev != nullptr )
      {
        src.m_pPrev->m_pNext = src.m_pNext;
        if ( src.m_pNext != nullptr )
        {
          src.m_pNext->m_pPrev = src.m_pPrev;
          memset(&src, 0, sizeof(src));
          pObj->SetSelectionState(this: pObj, a2: SELECT_NORMAL);
          goto LABEL_40;
        }
      }
      else if ( src.m_pObject->m_References.m_pHead == &src )
      {
        src.m_pObject->m_References.m_pHead = src.m_pNext;
        if ( src.m_pNext != nullptr )
          src.m_pNext->m_pPrev = nullptr;
      }
      memset(&src, 0, sizeof(src));
    }
    pObj->SetSelectionState(this: pObj, a2: SELECT_NORMAL);
    goto LABEL_40;
  }
  if ( (v7 & 4) == 0 || v6 == -1 )
    return 0;
  CUtlReferenceVector<CMapClass>::FastRemove(this: p_m_SelectionList, elem: v6);
  pObj->SetSelectionState(this: pObj, a2: SELECT_NONE);
LABEL_40:
  v3 = v13;
LABEL_41:
  v3->m_bBoundsDirty = true;
  if ( (cmd & 0x400) != 0 )
  {
    MainWnd = GetMainWnd();
    CObjectProperties::SaveData(this: MainWnd->pObjectProperties, reason: SAVEDATA_SELECTION_CHANGED);
  }
  v10 = GetMainWnd();
  CObjectProperties::MarkDataDirty(this: v10->pObjectProperties);
  CMapDoc::UpdateAllViews(this: v3->m_pDocument, nFlags: 8, ub: nullptr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100A3480
// Name: public: void CSelection::SelectObjectList(class CUtlReferenceVector<class CMapClass> const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSelection::SelectObjectList(
        CSelection *this,
        const CUtlReferenceVector<CMapClass> *pList,
        __int16 cmd)
{
  __int16 v3; // bx
  CMainFrame *MainWnd; // eax
  int i; // esi
  CMapClass *m_pObject; // eax
  CUtlReference<CMapClass> *v8; // ecx
  CMapClass *v9; // ecx
  CMapClass *v10; // eax
  CUtlReference<CMapClass> *m_pHead; // [esp+Ch] [ebp-1Ch] BYREF
  CUtlReference<CMapClass> *v12; // [esp+10h] [ebp-18h]
  CMapClass *v13; // [esp+14h] [ebp-14h]
  CSelection *v14; // [esp+18h] [ebp-10h]
  int v15; // [esp+24h] [ebp-4h]

  v3 = cmd;
  v14 = this;
  if ( (cmd & 0x400) != 0 )
  {
    MainWnd = GetMainWnd();
    CObjectProperties::SaveData(this: MainWnd->pObjectProperties, reason: SAVEDATA_SELECTION_CHANGED);
    v3 = cmd & 0xFBFF;
    cmd &= ~0x400u;
  }
  if ( (v3 & 0x10) != 0 )
  {
    CSelection::RemoveAll(this);
    cmd = v3 & 0xFFEF;
  }
  if ( pList != nullptr )
  {
    for ( i = 0; i < pList->m_Size; ++i )
    {
      m_pObject = pList->m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&pList->m_Memory + 2) >> 27)][i & ((32 * *((_DWORD *)&pList->m_Memory + 2)) >> 5)].m_pObject;
      if ( m_pObject != nullptr )
      {
        v13 = pList->m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&pList->m_Memory + 2) >> 27)][i & ((32 * *((_DWORD *)&pList->m_Memory + 2)) >> 5)].m_pObject;
        m_pHead = m_pObject->m_References.m_pHead;
        v8 = m_pObject->m_References.m_pHead;
        if ( v8 != nullptr )
          v8->m_pPrev = (CUtlReference<CMapClass> *)&m_pHead;
        v12 = nullptr;
        m_pObject->m_References.m_pHead = (CUtlReference<CMapClass> *)&m_pHead;
      }
      v9 = v13;
      v15 = -1;
      if ( v13 != nullptr )
      {
        if ( v12 != nullptr )
        {
          v12->m_pNext = m_pHead;
          if ( m_pHead != nullptr )
            m_pHead->m_pPrev = v12;
        }
        else if ( (CUtlReference<CMapClass> **)v13->m_References.m_pHead == &m_pHead )
        {
          v13->m_References.m_pHead = m_pHead;
          if ( m_pHead != nullptr )
            m_pHead->m_pPrev = nullptr;
        }
        v12 = nullptr;
        m_pHead = nullptr;
        v13 = nullptr;
      }
      v10 = v9->PrepareSelection(this: v9, a2: v14->m_eSelectMode);
      if ( v10 != nullptr )
        CSelection::SelectObject(this: v14, pObj: v10, cmd);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A35D0
// Name: public: virtual CSelection::~CSelection(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSelection::~CSelection(CSelection *this)
{
  this->__vftable = (CSelection_vtbl *)&CSelection::`vftable';
  CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::~CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>(this: &this->m_HitList);
  CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::~CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>(this: &this->m_SelectionList);
}

//------------------------------------------------------------------------------
// Address: 0x100A3630
// Name: public: void CSelection::Init(class CMapDoc __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSelection::Init(CSelection *this, CMapDoc *pDocument)
{
  this->m_pDocument = pDocument;
  this->m_eSelectMode = selectGroups;
  CUtlReferenceVector<CMapClass>::RemoveAll(this: &this->m_SelectionList);
  CUtlReferenceVector<CMapClass>::RemoveAll(this: &this->m_HitList);
  this->m_iCurHit = -1;
  this->m_LastValidBounds.bmins.x = 0.0;
  this->m_LastValidBounds.bmins.y = 0.0;
  this->m_LastValidBounds.bmins.z = 0.0;
  this->m_LastValidBounds.bmaxs.x = 64.0;
  this->m_LastValidBounds.bmaxs.y = 64.0;
  this->m_LastValidBounds.bmaxs.z = 64.0;
  CSelection::UpdateSelectionBounds(this);
}

//------------------------------------------------------------------------------
// Address: 0x100A36A0
// Name: public: void CSelection::SetMode(enum SelectMode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSelection::SetMode(CSelection *this, SelectMode_t eNewSelectMode)
{
  SelectMode_t v2; // ebx
  SelectMode_t m_eSelectMode; // eax
  int v5; // esi
  CMapClass *m_pObject; // ebx
  CMainFrame *v7; // eax
  CMainFrame *v8; // eax
  int i; // esi
  CMapClass *v10; // ecx
  CMapClass *v11; // eax
  int j; // esi
  CMainFrame *MainWnd; // eax
  CMainFrame *v14; // eax
  CUtlReferenceVector<CMapClass> NewList; // [esp+Ch] [ebp-24h] BYREF
  int nSelCount; // [esp+20h] [ebp-10h]
  int v17; // [esp+2Ch] [ebp-4h]

  v2 = eNewSelectMode;
  m_eSelectMode = this->m_eSelectMode;
  v5 = 0;
  this->m_eSelectMode = eNewSelectMode;
  if ( m_eSelectMode == selectSolids || m_eSelectMode == selectObjects && eNewSelectMode == selectGroups )
  {
    if ( this->m_SelectionList.m_Size != 0 )
    {
      CSelection::RemoveAll(this);
      this->m_bBoundsDirty = true;
      MainWnd = GetMainWnd();
      CObjectProperties::SaveData(this: MainWnd->pObjectProperties, reason: SAVEDATA_SELECTION_CHANGED);
      v14 = GetMainWnd();
      CObjectProperties::MarkDataDirty(this: v14->pObjectProperties);
      CMapDoc::UpdateAllViews(this: this->m_pDocument, nFlags: 8, ub: nullptr);
    }
  }
  else
  {
    memset(&NewList, 0, 12);
    CUtlBlockMemory<CUtlReference<CMapEntity>,int>::Init(this: &NewList.m_Memory, nGrowSize: 0, nInitSize: 0);
    NewList.m_Size = 0;
    NewList.m_pElements = nullptr;
    v17 = 5;
    nSelCount = this->m_SelectionList.m_Size;
    if ( nSelCount > 0 )
    {
      do
      {
        m_pObject = this->m_SelectionList.m_Memory.m_pMemory[v5 >> ((unsigned __int64)*((int *)&this->m_SelectionList.m_Memory
                                                                                      + 2) >> 27)][v5
                                                                                                 & ((32 * *((_DWORD *)&this->m_SelectionList.m_Memory + 2)) >> 5)].m_pObject;
        AddLeavesToListCallback(pObject: m_pObject, pList: &NewList);
        CMapClass::EnumChildren(
          this: m_pObject,
          pfn: (int (__cdecl *)(CMapClass *, unsigned int))AddLeavesToListCallback,
          dwParam: (unsigned int)&NewList,
          Type: nullptr);
        ++v5;
      }
      while ( v5 < nSelCount );
      v2 = eNewSelectMode;
    }
    if ( this->m_SelectionList.m_Size != 0 )
    {
      CSelection::RemoveAll(this);
      this->m_bBoundsDirty = true;
      v7 = GetMainWnd();
      CObjectProperties::SaveData(this: v7->pObjectProperties, reason: SAVEDATA_SELECTION_CHANGED);
      v8 = GetMainWnd();
      CObjectProperties::MarkDataDirty(this: v8->pObjectProperties);
      CMapDoc::UpdateAllViews(this: this->m_pDocument, nFlags: 8, ub: nullptr);
    }
    for ( i = 0; i < NewList.m_Size; ++i )
    {
      v10 = NewList.m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&NewList.m_Memory + 2) >> 27)][i & ((32 * *((_DWORD *)&NewList.m_Memory + 2)) >> 5)].m_pObject;
      v11 = v10->PrepareSelection(this: v10, a2: v2);
      if ( v11 != nullptr )
        CSelection::SelectObject(this, pObj: v11, cmd: 2);
    }
    v17 = 10;
    CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::RemoveAll(this: &NewList);
    if ( NewList.m_Memory.m_pMemory != nullptr )
    {
      for ( j = 0; j < NewList.m_Memory.m_nBlocks; ++j )
        free(pMem: NewList.m_Memory.m_pMemory[j]);
      NewList.m_Memory.m_nBlocks = 0;
      free(pMem: NewList.m_Memory.m_pMemory);
      NewList.m_Memory.m_pMemory = nullptr;
    }
    NewList.m_pElements = nullptr;
    v17 = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A38D0
// Name: public: void CSelection::SetCurrentHit(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSelection::SetCurrentHit(CSelection *this, int iIndex, bool bCascading)
{
  int m_iCurHit; // edx
  int m_Size; // ecx
  int v6; // eax
  CMapEntity *m_pObject; // edi
  CUtlReference<CMapClass> *m_pHead; // eax
  unsigned __int16 i; // di
  CUtlRBTree<CMapClass *,unsigned short,bool (__cdecl*)(CMapClass * const &,CMapClass * const &),CUtlMemory<UtlRBTreeNode_t<CMapClass *,unsigned short>,unsigned short> > tree; // [esp+8h] [ebp-48h] BYREF
  CUtlReferenceVector<CMapClass> list; // [esp+24h] [ebp-2Ch] BYREF
  CUtlReference<CMapClass> src; // [esp+38h] [ebp-18h] BYREF
  int v13; // [esp+4Ch] [ebp-4h]

  if ( this->m_HitList.m_Size != 0 )
  {
    m_iCurHit = this->m_iCurHit;
    if ( m_iCurHit != -1 )
      CSelection::SelectObject(
        this,
        pObj: this->m_HitList.m_Memory.m_pMemory[m_iCurHit >> (*((int *)&this->m_HitList.m_Memory + 2) >> 27)][m_iCurHit & ((32 * *((_DWORD *)&this->m_HitList.m_Memory + 2)) >> 5)].m_pObject,
        cmd: 1025);
    if ( iIndex == -1 )
    {
      ++this->m_iCurHit;
    }
    else if ( iIndex == -2 )
    {
      --this->m_iCurHit;
    }
    else
    {
      this->m_iCurHit = iIndex;
    }
    m_Size = this->m_HitList.m_Size;
    v6 = this->m_iCurHit;
    if ( v6 < m_Size )
    {
      if ( v6 < 0 )
        this->m_iCurHit = m_Size - 1;
    }
    else
    {
      this->m_iCurHit = 0;
    }
    m_pObject = (CMapEntity *)this->m_HitList.m_Memory.m_pMemory[this->m_iCurHit >> (*((int *)&this->m_HitList.m_Memory
                                                                                     + 2) >> 27)][this->m_iCurHit
                                                                                                & ((32
                                                                                                  * *((_DWORD *)&this->m_HitList.m_Memory + 2)) >> 5)].m_pObject;
    if ( bCascading )
    {
      tree.m_LessFunc = (bool (__cdecl *)(CMapClass *const *, CMapClass *const *))CPreviewImagePropertiesCache::PreviewImageLessFunc;
      memset(&tree.m_Elements, 0, sizeof(tree.m_Elements));
      *(_DWORD *)&tree.m_Root = 0xFFFF;
      *(_DWORD *)&tree.m_FirstFree = -1;
      tree.m_pElements = nullptr;
      v13 = 1;
      CMapDoc::BuildCascadingSelectionList(this: this->m_pDocument, pObj: m_pObject, list: &tree, bRecursive: false);
      memset(&list, 0, 12);
      CUtlBlockMemory<CUtlReference<CMapEntity>,int>::Init(this: &list.m_Memory, nGrowSize: 0, nInitSize: 0);
      list.m_Size = 0;
      list.m_pElements = nullptr;
      LOBYTE(v13) = 5;
      src.m_pPrev = nullptr;
      src.m_pNext = nullptr;
      src.m_pObject = m_pObject;
      if ( m_pObject != nullptr )
      {
        m_pHead = m_pObject->CMapClass::m_References.m_pHead;
        src.m_pNext = m_pHead;
        if ( m_pHead != nullptr )
          m_pHead->m_pPrev = &src;
        src.m_pPrev = nullptr;
        m_pObject->CMapClass::m_References.m_pHead = &src;
      }
      LOBYTE(v13) = 6;
      CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::InsertBefore(
        this: &list,
        elem: list.m_Size,
        &src);
      LOBYTE(v13) = 5;
      if ( src.m_pObject != nullptr )
      {
        if ( src.m_pPrev != nullptr )
        {
          src.m_pPrev->m_pNext = src.m_pNext;
          if ( src.m_pNext != nullptr )
            src.m_pNext->m_pPrev = src.m_pPrev;
        }
        else if ( src.m_pObject->m_References.m_pHead == &src )
        {
          src.m_pObject->m_References.m_pHead = src.m_pNext;
          if ( src.m_pNext != nullptr )
            src.m_pNext->m_pPrev = nullptr;
        }
        memset(&src, 0, sizeof(src));
      }
      CSelection::IsSelected(this, pobj: m_pObject);
      for ( i = CUtlRBTree<CMapClass *,unsigned short,bool (__cdecl *)(CMapClass * const &,CMapClass * const &),CUtlMemory<UtlRBTreeNode_t<CMapClass *,unsigned short>,unsigned short>>::FirstInorder(this: &tree);
            i != 0xFFFF;
            i = CUtlRBTree<CMapClass *,unsigned short,bool (__cdecl *)(CMapClass * const &,CMapClass * const &),CUtlMemory<UtlRBTreeNode_t<CMapClass *,unsigned short>,unsigned short>>::NextInorder(
                  this: &tree,
                  i) )
      {
        CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::InsertBefore(
          this: &list,
          elem: list.m_Size,
          src: &list.m_Memory.m_pMemory[(int)i >> ((unsigned __int64)*((int *)&list.m_Memory + 2) >> 27)][i & ((32 * *((_DWORD *)&list.m_Memory + 2)) >> 5)]);
        CSelection::IsSelected(
          this,
          pobj: list.m_Memory.m_pMemory[(int)i >> ((unsigned __int64)*((int *)&list.m_Memory + 2) >> 27)][i & ((32 * *((_DWORD *)&list.m_Memory + 2)) >> 5)].m_pObject);
      }
      CSelection::SelectObjectList(this, pList: &list, cmd: 2);
      LOBYTE(v13) = 1;
      CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::~CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>(this: &list);
      v13 = 9;
      CUtlRBTree<CMapClass *,unsigned short,bool (__cdecl *)(CMapClass * const &,CMapClass * const &),CUtlMemory<UtlRBTreeNode_t<CMapClass *,unsigned short>,unsigned short>>::RemoveAll(this: &tree);
      tree.m_FirstFree = -1;
      if ( tree.m_Elements.m_nGrowSize >= 0 )
      {
        if ( tree.m_Elements.m_pMemory != nullptr )
        {
          free(pMem: tree.m_Elements.m_pMemory);
          tree.m_Elements.m_pMemory = nullptr;
        }
        tree.m_Elements.m_nAllocationCount = 0;
      }
      tree.m_LastAlloc.index = -1;
      v13 = -1;
      if ( tree.m_Elements.m_nGrowSize >= 0 )
      {
        if ( tree.m_Elements.m_pMemory != nullptr )
        {
          free(pMem: tree.m_Elements.m_pMemory);
          tree.m_Elements.m_pMemory = nullptr;
        }
        tree.m_Elements.m_nAllocationCount = 0;
      }
    }
    else
    {
      CSelection::SelectObject(this, pObj: m_pObject, cmd: 1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A3BC0
// Name: public: CSelection::CSelection(void)
// Source: json
//------------------------------------------------------------------------------
CSelection *__thiscall CSelection::CSelection(CSelection *this)
{
  CUtlReferenceVector<CMapClass> *p_m_SelectionList; // edi

  p_m_SelectionList = &this->m_SelectionList;
  this->__vftable = (CSelection_vtbl *)&CSelection::`vftable';
  this->m_SelectionList.m_Memory.m_pMemory = nullptr;
  this->m_SelectionList.m_Memory.m_nBlocks = 0;
  *((_DWORD *)&this->m_SelectionList.m_Memory + 2) = 0;
  CUtlBlockMemory<CUtlReference<CMapEntity>,int>::Init(
    this: &this->m_SelectionList.m_Memory,
    nGrowSize: 0,
    nInitSize: 0);
  p_m_SelectionList->m_Size = 0;
  p_m_SelectionList->m_pElements = nullptr;
  BoundBox::BoundBox(this: &this->m_Bounds);
  BoundBox::BoundBox(this: &this->m_LastValidBounds);
  this->m_HitList.m_Memory.m_pMemory = nullptr;
  this->m_HitList.m_Memory.m_nBlocks = 0;
  *((_DWORD *)&this->m_HitList.m_Memory + 2) = 0;
  CUtlBlockMemory<CUtlReference<CMapEntity>,int>::Init(this: &this->m_HitList.m_Memory, nGrowSize: 0, nInitSize: 0);
  this->m_HitList.m_Size = 0;
  this->m_HitList.m_pElements = nullptr;
  this->m_pDocument = nullptr;
  return this;
}
