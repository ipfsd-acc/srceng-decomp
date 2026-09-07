// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/dispmanager.cpp
// Functions: 31
// ============================================================

#include "hammer\dispmanager.h"

//------------------------------------------------------------------------------
// Address: 0x1001D080
// Name: public: virtual IWorldEditDispMgr::~IWorldEditDispMgr(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IWorldEditDispMgr::~IWorldEditDispMgr(IWorldEditDispMgr *this)
{
  this->__vftable = (IWorldEditDispMgr_vtbl *)&IWorldEditDispMgr::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1001D0C0
// Name: public: void CMapDisp::AddCornerNeighbor(int,unsigned short,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapDisp::AddCornerNeighbor(CMapDisp *this, int direction, unsigned __int16 handle, int orient)
{
  int v4; // esi

  v4 = this->m_CornerNeighborCounts[direction];
  if ( v4 < 4 )
  {
    this->m_CornerNeighbors[direction][v4] = handle;
    this->m_CornerNeighborOrientations[direction][this->m_CornerNeighborCounts[direction]++] = orient;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001D110
// Name: public: void CMapDisp::GetCornerNeighbor(int,int,unsigned short __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapDisp::GetCornerNeighbor(
        CMapDisp *this,
        int direction,
        int cornerIndex,
        unsigned __int16 *handle,
        int *orient)
{
  int v5; // eax

  *handle = -1;
  *orient = 0;
  if ( cornerIndex < this->m_CornerNeighborCounts[direction] )
  {
    v5 = cornerIndex + 4 * direction;
    *handle = this->m_CornerNeighbors[0][v5];
    *orient = this->m_CornerNeighborOrientations[0][v5];
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001D160
// Name: void DestroyWorldEditDispMgr(class IWorldEditDispMgr __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DestroyWorldEditDispMgr(IWorldEditDispMgr **pDispMgr)
{
  if ( *pDispMgr != nullptr )
  {
    ((void (__thiscall *)(_DWORD, int))(*pDispMgr)->dtr_IWorldEditDispMgr)(a1: *pDispMgr, a2: 1);
    *pDispMgr = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001D180
// Name: public: virtual int CWorldEditDispMgr::NumSharedPoints(class CMapDisp __near *,class CMapDisp __near *,int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWorldEditDispMgr::NumSharedPoints(
        CWorldEditDispMgr *this,
        CMapDisp *pDisp,
        CMapDisp *pNeighborDisp,
        int *edge1,
        int *edge2)
{
  int v5; // eax
  float *p_z; // edi
  int *v7; // ebx
  float *v8; // edx
  int i; // esi
  int v10; // ecx
  Vector pt2; // [esp+0h] [ebp-1Ch]
  Vector pt1; // [esp+Ch] [ebp-10h]
  int ptCount; // [esp+18h] [ebp-4h]
  float *pNeighborDispa; // [esp+28h] [ebp+Ch]
  int *edge2a; // [esp+30h] [ebp+14h]

  pNeighborDispa = &pNeighborDisp->m_CoreDispInfo.m_Surf.m_Points[0].z;
  v5 = 0;
  p_z = &pDisp->m_CoreDispInfo.m_Surf.m_Points[0].z;
  ptCount = 0;
  v7 = edge2;
  edge2a = (int *)((char *)edge1 - (char *)edge2);
  do
  {
    v8 = pNeighborDispa;
    pt1 = *(Vector *)(p_z - 2);
    for ( i = 0; i < 4; ++i )
    {
      pt2 = *(Vector *)(v8 - 2);
      v10 = 0;
      while ( fabs(*(float *)((char *)&pt1.x + v10) - *(float *)((char *)&pt2.x + v10)) <= 0.0099999998 )
      {
        v10 += 4;
        if ( v10 >= 12 )
          goto LABEL_8;
      }
      v8 += 3;
    }
LABEL_8:
    if ( i != 4 )
    {
      ++ptCount;
      *(int *)((char *)v7 + (_DWORD)edge2a) = v5;
      *v7++ = i;
    }
    ++v5;
    p_z += 3;
  }
  while ( v5 < 4 );
  return ptCount;
}

//------------------------------------------------------------------------------
// Address: 0x1001D270
// Name: private: int CWorldEditDispMgr::GetEdgeIndex(int __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWorldEditDispMgr::GetEdgeIndex(CWorldEditDispMgr *this, int *edge)
{
  int v2; // eax
  int v3; // edx
  int v5; // edx
  int v6; // edx

  v2 = *edge;
  if ( *edge == 0 && edge[1] == 1 )
    return 0;
  if ( v2 == 1 )
  {
    v3 = edge[1];
    if ( v3 == 0 )
      return 0;
    if ( v3 == 2 )
      return 1;
  }
  if ( v2 == 2 )
  {
    v5 = edge[1];
    if ( v5 == 1 )
      return 1;
    if ( v5 == 3 )
      return 2;
  }
  if ( v2 == 3 )
  {
    v6 = edge[1];
    if ( v6 == 2 )
      return 2;
    if ( v6 == 0 )
      return 3;
  }
  if ( v2 != 0 || edge[1] != 3 )
    return -1;
  else
    return 3;
}

//------------------------------------------------------------------------------
// Address: 0x1001D2F0
// Name: public: virtual void CWorldEditDispMgr::PreUndo(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorldEditDispMgr::PreUndo(CWorldEditDispMgr *this, const char *pszMarkName)
{
  CHistory *History; // eax

  History = GetHistory();
  CHistory::MarkUndoPosition(this: History, pSelection: nullptr, pszName: pszMarkName, bFromOpposite: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1001D3B0
// Name: private: void CWorldEditDispMgr::TestNeighbors(class CMapDisp __near *,class CMapDisp __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorldEditDispMgr::TestNeighbors(CWorldEditDispMgr *this, CMapDisp *pDisp, CMapDisp *pNeighborDisp)
{
  int v4; // eax
  int v5; // edi
  int v6; // esi
  CMapAtom *v7; // eax
  int EdgeIndex; // edi
  int v9; // eax
  int v10; // esi
  int edge2[4]; // [esp+Ch] [ebp-20h] BYREF
  int edge1[4]; // [esp+1Ch] [ebp-10h] BYREF

  v4 = this->NumSharedPoints(this, a2: pDisp, a3: pNeighborDisp, a4: edge1, a5: edge2);
  if ( v4 == 1 )
  {
    switch ( edge1[0] )
    {
      case 0:
        v5 = 0;
        break;
      case 1:
        v5 = 2;
        break;
      case 2:
        v5 = 3;
        break;
      case 3:
        v5 = 1;
        break;
      default:
        v5 = -1;
        break;
    }
    switch ( edge2[0] )
    {
      case 0:
        v6 = 0;
        break;
      case 1:
        v6 = 2;
        break;
      case 2:
        v6 = 3;
        break;
      case 3:
        v6 = 1;
        break;
      default:
        v6 = -1;
        break;
    }
    if ( v5 != -1 && v6 != -1 )
    {
      v7 = pNeighborDisp->GetParent(this: pNeighborDisp);
      CMapDisp::AddCornerNeighbor(this: pDisp, direction: v5, handle: (unsigned __int16)v7[21].__vftable, orient: v6);
    }
  }
  else if ( v4 == 2 )
  {
    EdgeIndex = CWorldEditDispMgr::GetEdgeIndex(this, edge: edge1);
    v9 = CWorldEditDispMgr::GetEdgeIndex(this, edge: edge2);
    v10 = v9;
    if ( EdgeIndex != -1 && v9 != -1 )
    {
      pDisp->m_EdgeNeighbors[EdgeIndex] = (unsigned __int16)pNeighborDisp->GetParent(this: pNeighborDisp)[21].__vftable;
      pDisp->m_EdgeNeighborOrientations[EdgeIndex] = v10;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001D4E0
// Name: public: virtual int CWorldEditDispMgr::SelectCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWorldEditDispMgr::SelectCount(CWorldEditDispMgr *this)
{
  return this->m_SelectList.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x1001D4F0
// Name: public: virtual void CWorldEditDispMgr::CatmullClarkSubdivide(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorldEditDispMgr::CatmullClarkSubdivide(CWorldEditDispMgr *this)
{
  HCURSOR CursorA; // eax
  int m_Size; // ebx
  int i; // edi
  CMapDisp *v5; // eax
  int j; // edi
  CMapDisp *v7; // eax
  int k; // edi
  CMapDisp *v9; // eax
  HICON__ *oldCursor; // [esp+Ch] [ebp-4h]

  CursorA = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F02);
  oldCursor = SetCursor(hCursor: CursorA);
  this->PreUndo(this, a2: "Subdivision");
  m_Size = this->m_SelectList.m_Size;
  for ( i = 0; i < m_Size; ++i )
  {
    v5 = this->GetFromSelect(this, a2: i);
    if ( v5 != nullptr )
      this->Undo(this, a2: v5->m_EditHandle, a3: false);
  }
  this->PostUndo(this);
  this->m_pSubdivMesh->Init(this: this->m_pSubdivMesh);
  for ( j = 0; j < m_Size; ++j )
  {
    v7 = this->GetFromSelect(this, a2: j);
    if ( v7 != nullptr )
      this->m_pSubdivMesh->AddDispTo(this: this->m_pSubdivMesh, a2: v7);
  }
  this->m_pSubdivMesh->DoCatmullClarkSubdivision(this: this->m_pSubdivMesh);
  for ( k = 0; k < m_Size; ++k )
  {
    v9 = this->GetFromSelect(this, a2: k);
    if ( v9 != nullptr )
      this->m_pSubdivMesh->GetDispFrom(this: this->m_pSubdivMesh, a2: v9);
  }
  this->m_pSubdivMesh->Shutdown(this: this->m_pSubdivMesh);
  SetCursor(hCursor: oldCursor);
}

//------------------------------------------------------------------------------
// Address: 0x1001D5D0
// Name: public: virtual class CMapDisp __near * CEditDispMgr::GetDisp(unsigned short)
// Source: json
//------------------------------------------------------------------------------
UtlLinkedListElem_t<CMapDisp,unsigned short> *__thiscall CEditDispMgr::GetDisp(
        CEditDispMgr *this,
        unsigned __int16 handle)
{
  UtlLinkedListElem_t<CMapDisp,unsigned short> *m_pMemory; // eax
  int v3; // edx

  if ( handle >= this->m_AllocList.m_Memory.m_nAllocationCount )
    return nullptr;
  if ( handle > this->m_AllocList.m_LastAlloc.index )
    return nullptr;
  m_pMemory = this->m_AllocList.m_Memory.m_pMemory;
  v3 = handle;
  if ( m_pMemory[v3].m_Previous == handle && m_pMemory[v3].m_Next != handle )
    return nullptr;
  else
    return &m_pMemory[v3];
}

//------------------------------------------------------------------------------
// Address: 0x1001D620
// Name: public: virtual void CWorldEditDispMgr::FindWorldNeighbors(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorldEditDispMgr::FindWorldNeighbors(CWorldEditDispMgr *this, int handle)
{
  CMapDisp *v3; // ebx
  int v4; // edi
  CMapDisp *v5; // eax
  int count; // [esp+10h] [ebp+8h]

  v3 = this->GetFromWorld(this, a2: handle);
  if ( v3 != nullptr )
  {
    v4 = 0;
    count = this->WorldCount(this);
    if ( count > 0 )
    {
      do
      {
        v5 = this->GetFromWorld_2(this, a2: v4);
        if ( v5 != nullptr && v5 != v3 && v3->m_CoreDispInfo.m_Power == v5->m_CoreDispInfo.m_Power )
          CWorldEditDispMgr::TestNeighbors(this, pDisp: v3, pNeighborDisp: v5);
        ++v4;
      }
      while ( v4 < count );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001D680
// Name: public: virtual void CWorldEditDispMgr::SelectClear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorldEditDispMgr::SelectClear(CWorldEditDispMgr *this)
{
  this->m_SelectList.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001D980
// Name: public: virtual void CWorldEditDispMgr::RemoveFromWorld(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorldEditDispMgr::RemoveFromWorld(CWorldEditDispMgr *this, unsigned __int16 handle)
{
  int m_Size; // edx
  int v4; // eax
  unsigned __int16 *i; // ecx

  m_Size = this->m_WorldList.m_Size;
  v4 = 0;
  if ( m_Size > 0 )
  {
    for ( i = this->m_WorldList.m_Memory.m_pMemory; *i != handle; ++i )
    {
      if ( ++v4 >= m_Size )
        return;
    }
    if ( v4 != -1 )
    {
      if ( m_Size - v4 - 1 > 0 )
        _V_memmove(
          dest: &this->m_WorldList.m_Memory.m_pMemory[v4],
          src: &this->m_WorldList.m_Memory.m_pMemory[v4 + 1],
          count: 2 * (m_Size - v4 - 1));
      --this->m_WorldList.m_Size;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001D9E0
// Name: public: virtual void CWorldEditDispMgr::RemoveFromSelect(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorldEditDispMgr::RemoveFromSelect(CWorldEditDispMgr *this, unsigned __int16 handle)
{
  int m_Size; // edx
  int v4; // eax
  unsigned __int16 *i; // ecx

  m_Size = this->m_SelectList.m_Size;
  v4 = 0;
  if ( m_Size > 0 )
  {
    for ( i = this->m_SelectList.m_Memory.m_pMemory; *i != handle; ++i )
    {
      if ( ++v4 >= m_Size )
        return;
    }
    if ( v4 != -1 )
    {
      if ( m_Size - handle - 1 > 0 )
        _V_memmove(
          dest: &this->m_SelectList.m_Memory.m_pMemory[handle],
          src: &this->m_SelectList.m_Memory.m_pMemory[handle + 1],
          count: 2 * (m_Size - handle - 1));
      --this->m_SelectList.m_Size;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001DA40
// Name: public: virtual bool CWorldEditDispMgr::IsInSelect(unsigned short)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWorldEditDispMgr::IsInSelect(CWorldEditDispMgr *this, unsigned __int16 handle)
{
  int m_Size; // edx
  int v3; // eax
  unsigned __int16 *m_pMemory; // ecx

  m_Size = this->m_SelectList.m_Size;
  v3 = 0;
  if ( m_Size <= 0 )
  {
LABEL_5:
    v3 = -1;
  }
  else
  {
    m_pMemory = this->m_SelectList.m_Memory.m_pMemory;
    while ( *m_pMemory != handle )
    {
      ++v3;
      ++m_pMemory;
      if ( v3 >= m_Size )
        goto LABEL_5;
    }
  }
  return v3 != -1;
}

//------------------------------------------------------------------------------
// Address: 0x1001DA80
// Name: private: bool CWorldEditDispMgr::IsInKeptList(class CMapClass __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWorldEditDispMgr::IsInKeptList(CWorldEditDispMgr *this, CMapClass *pObject)
{
  int m_Size; // edx
  int v3; // eax
  CMapClass **i; // ecx

  m_Size = this->m_aKeptList.m_Size;
  v3 = 0;
  if ( m_Size <= 0 )
    return false;
  for ( i = this->m_aKeptList.m_Memory.m_pMemory; *i != pObject; ++i )
  {
    if ( ++v3 >= m_Size )
      return false;
  }
  return v3 != -1;
}

//------------------------------------------------------------------------------
// Address: 0x1001DAC0
// Name: public: virtual void CWorldEditDispMgr::PostUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorldEditDispMgr::PostUndo(CWorldEditDispMgr *this)
{
  this->m_aKeptList.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001DBE0
// Name: public: virtual CEditDispMgr::~CEditDispMgr(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEditDispMgr::~CEditDispMgr(CEditDispMgr *this)
{
  CUtlLinkedList<CMapDisp,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMapDisp,unsigned short>,unsigned short> > *p_m_AllocList; // esi
  UtlLinkedListElem_t<CMapDisp,unsigned short> *m_pMemory; // eax

  this->__vftable = (CEditDispMgr_vtbl *)&CEditDispMgr::`vftable';
  p_m_AllocList = &this->m_AllocList;
  CUtlLinkedList<CMapDisp,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMapDisp,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_AllocList);
  if ( p_m_AllocList->m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_AllocList->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_AllocList->m_Memory.m_pMemory);
      p_m_AllocList->m_Memory.m_pMemory = nullptr;
    }
    p_m_AllocList->m_Memory.m_nAllocationCount = 0;
  }
  p_m_AllocList->m_FirstFree = -1;
  m_pMemory = p_m_AllocList->m_Memory.m_pMemory;
  *(_DWORD *)&p_m_AllocList->m_NumAlloced = -65536;
  p_m_AllocList->m_pElements = m_pMemory;
  CUtlLinkedList<CMapDisp,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMapDisp,unsigned short>,unsigned short>>::RemoveAll(this: p_m_AllocList);
  if ( p_m_AllocList->m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_AllocList->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_AllocList->m_Memory.m_pMemory);
      p_m_AllocList->m_Memory.m_pMemory = nullptr;
    }
    p_m_AllocList->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001DCD0
// Name: public: virtual void CEditDispMgr::Destroy(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEditDispMgr::Destroy(CEditDispMgr *this, unsigned __int16 handle)
{
  CUtlLinkedList<CMapDisp,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMapDisp,unsigned short>,unsigned short> > *p_m_AllocList; // esi
  int v4; // edi
  UtlLinkedListElem_t<CMapDisp,unsigned short> *handlea; // [esp+14h] [ebp+8h]

  p_m_AllocList = &this->m_AllocList;
  if ( handle >= this->m_AllocList.m_Memory.m_nAllocationCount
    || handle > this->m_AllocList.m_LastAlloc.index
    || (v4 = handle, p_m_AllocList->m_Memory.m_pMemory[v4].m_Previous == handle)
    && p_m_AllocList->m_Memory.m_pMemory[v4].m_Next != handle )
  {
    if ( !bNoToAll )
    {
      if ( AfxMessageBox(lpszText: "CEditDispMgr::Destroy - invalid handle.\nWrite minidump?\n", nType: 4u, nIDHelp: 0) == 6 )
        _WriteMiniDump();
      else
        bNoToAll = true;
    }
  }
  else
  {
    CUtlLinkedList<CMapDisp,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMapDisp,unsigned short>,unsigned short>>::Unlink(
      this: &this->m_AllocList,
      elem: handle);
    handlea = &p_m_AllocList->m_Memory.m_pMemory[v4];
    CMapDisp::~CMapDisp(this: &handlea->m_Element);
    handlea->m_Next = p_m_AllocList->m_FirstFree;
    p_m_AllocList->m_FirstFree = handle;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001DD70
// Name: public: CWorldEditDispMgr::CWorldEditDispMgr(void)
// Source: json
//------------------------------------------------------------------------------
CWorldEditDispMgr *__thiscall CWorldEditDispMgr::CWorldEditDispMgr(CWorldEditDispMgr *this)
{
  unsigned __int16 *m_pMemory; // edx
  unsigned __int16 *v3; // edx

  this->__vftable = (CWorldEditDispMgr_vtbl *)&IWorldEditDispMgr::`vftable';
  this->__vftable = (CWorldEditDispMgr_vtbl *)&CWorldEditDispMgr::`vftable';
  this->m_WorldList.m_Memory.m_pMemory = nullptr;
  this->m_WorldList.m_Memory.m_nAllocationCount = 0;
  this->m_WorldList.m_Memory.m_nGrowSize = 0;
  m_pMemory = this->m_WorldList.m_Memory.m_pMemory;
  this->m_WorldList.m_Size = 0;
  this->m_WorldList.m_pElements = m_pMemory;
  this->m_SelectList.m_Memory.m_pMemory = nullptr;
  this->m_SelectList.m_Memory.m_nAllocationCount = 0;
  this->m_SelectList.m_Memory.m_nGrowSize = 0;
  v3 = this->m_SelectList.m_Memory.m_pMemory;
  this->m_SelectList.m_Size = 0;
  this->m_SelectList.m_pElements = v3;
  this->m_aKeptList.m_Memory.m_pMemory = nullptr;
  this->m_aKeptList.m_Memory.m_nAllocationCount = 0;
  this->m_aKeptList.m_Memory.m_nGrowSize = 0;
  this->m_aKeptList.m_Size = 0;
  this->m_aKeptList.m_pElements = this->m_aKeptList.m_Memory.m_pMemory;
  this->m_pSubdivMesh = CreateEditDispSubdivMesh();
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1001DE20
// Name: public: virtual CWorldEditDispMgr::~CWorldEditDispMgr(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorldEditDispMgr::~CWorldEditDispMgr(CWorldEditDispMgr *this)
{
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *p_m_SelectList; // edi
  CUtlVector<CMapClass *,CUtlMemory<CMapClass *,int> > *p_m_aKeptList; // esi
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *p_m_WorldList; // esi

  this->__vftable = (CWorldEditDispMgr_vtbl *)&CWorldEditDispMgr::`vftable';
  this->m_WorldList.m_Size = 0;
  if ( this->m_WorldList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_WorldList.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_WorldList.m_Memory.m_pMemory);
      this->m_WorldList.m_Memory.m_pMemory = nullptr;
    }
    this->m_WorldList.m_Memory.m_nAllocationCount = 0;
  }
  p_m_SelectList = &this->m_SelectList;
  this->m_WorldList.m_pElements = this->m_WorldList.m_Memory.m_pMemory;
  this->m_SelectList.m_Size = 0;
  if ( this->m_SelectList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_SelectList->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_SelectList->m_Memory.m_pMemory);
      p_m_SelectList->m_Memory.m_pMemory = nullptr;
    }
    this->m_SelectList.m_Memory.m_nAllocationCount = 0;
  }
  this->m_SelectList.m_pElements = this->m_SelectList.m_Memory.m_pMemory;
  DestroyEditDispSubdivMesh(pSubdivMesh: &this->m_pSubdivMesh);
  p_m_aKeptList = &this->m_aKeptList;
  p_m_aKeptList->m_Size = 0;
  if ( p_m_aKeptList->m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_aKeptList->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_aKeptList->m_Memory.m_pMemory);
      p_m_aKeptList->m_Memory.m_pMemory = nullptr;
    }
    p_m_aKeptList->m_Memory.m_nAllocationCount = 0;
  }
  p_m_aKeptList->m_pElements = p_m_aKeptList->m_Memory.m_pMemory;
  p_m_aKeptList->m_Size = 0;
  if ( p_m_aKeptList->m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_aKeptList->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_aKeptList->m_Memory.m_pMemory);
      p_m_aKeptList->m_Memory.m_pMemory = nullptr;
    }
    p_m_aKeptList->m_Memory.m_nAllocationCount = 0;
  }
  p_m_aKeptList->m_pElements = p_m_aKeptList->m_Memory.m_pMemory;
  if ( p_m_aKeptList->m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_aKeptList->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_aKeptList->m_Memory.m_pMemory);
      p_m_aKeptList->m_Memory.m_pMemory = nullptr;
    }
    p_m_aKeptList->m_Memory.m_nAllocationCount = 0;
  }
  p_m_SelectList->m_Size = 0;
  if ( p_m_SelectList->m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_SelectList->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_SelectList->m_Memory.m_pMemory);
      p_m_SelectList->m_Memory.m_pMemory = nullptr;
    }
    p_m_SelectList->m_Memory.m_nAllocationCount = 0;
  }
  p_m_SelectList->m_pElements = p_m_SelectList->m_Memory.m_pMemory;
  if ( p_m_SelectList->m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_SelectList->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_SelectList->m_Memory.m_pMemory);
      p_m_SelectList->m_Memory.m_pMemory = nullptr;
    }
    p_m_SelectList->m_Memory.m_nAllocationCount = 0;
  }
  p_m_WorldList = &this->m_WorldList;
  this->m_WorldList.m_Size = 0;
  if ( this->m_WorldList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_WorldList->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_WorldList->m_Memory.m_pMemory);
      p_m_WorldList->m_Memory.m_pMemory = nullptr;
    }
    this->m_WorldList.m_Memory.m_nAllocationCount = 0;
  }
  this->m_WorldList.m_pElements = this->m_WorldList.m_Memory.m_pMemory;
  if ( this->m_WorldList.m_Memory.m_nGrowSize < 0 )
  {
    this->__vftable = (CWorldEditDispMgr_vtbl *)&IWorldEditDispMgr::`vftable';
  }
  else
  {
    if ( p_m_WorldList->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_WorldList->m_Memory.m_pMemory);
      p_m_WorldList->m_Memory.m_pMemory = nullptr;
    }
    this->m_WorldList.m_Memory.m_nAllocationCount = 0;
    this->__vftable = (CWorldEditDispMgr_vtbl *)&IWorldEditDispMgr::`vftable';
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001DFF0
// Name: public: virtual void CWorldEditDispMgr::AddToSelect(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorldEditDispMgr::AddToSelect(CWorldEditDispMgr *this, unsigned __int16 handle)
{
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *p_m_SelectList; // esi
  int m_Size; // ecx
  int v4; // eax
  unsigned __int16 *m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v7; // edi
  unsigned __int16 *v8; // ecx
  int v9; // eax

  p_m_SelectList = &this->m_SelectList;
  m_Size = this->m_SelectList.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    goto LABEL_7;
  m_pMemory = p_m_SelectList->m_Memory.m_pMemory;
  while ( *m_pMemory != handle )
  {
    ++v4;
    ++m_pMemory;
    if ( v4 >= m_Size )
      goto LABEL_7;
  }
  if ( v4 == -1 )
  {
LABEL_7:
    m_nAllocationCount = p_m_SelectList->m_Memory.m_nAllocationCount;
    v7 = m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CUtlSymbol,int>::Grow(this: &p_m_SelectList->m_Memory, num: m_Size - m_nAllocationCount + 1);
    ++p_m_SelectList->m_Size;
    v8 = p_m_SelectList->m_Memory.m_pMemory;
    v9 = p_m_SelectList->m_Size - v7 - 1;
    p_m_SelectList->m_pElements = p_m_SelectList->m_Memory.m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &v8[v7 + 1], src: &v8[v7], count: 2 * v9);
    p_m_SelectList->m_Memory.m_pMemory[v7] = handle;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001E070
// Name: class IEditDispMgr __near * EditDispMgr(void)
// Source: json
//------------------------------------------------------------------------------
CEditDispMgr *__cdecl EditDispMgr()
{
  if ( (_S1 & 1) == 0 )
  {
    _S1 |= 1u;
    s_EditDispMgr.__vftable = (CEditDispMgr_vtbl *)&CEditDispMgr::`vftable';
    s_EditDispMgr.m_AllocList.m_Memory.m_pMemory = nullptr;
    s_EditDispMgr.m_AllocList.m_Memory.m_nAllocationCount = 0;
    s_EditDispMgr.m_AllocList.m_Memory.m_nGrowSize = 0;
    s_EditDispMgr.m_AllocList.m_LastAlloc.index = -1;
    *(_DWORD *)&s_EditDispMgr.m_AllocList.m_FirstFree = 0xFFFF;
    *(_DWORD *)&s_EditDispMgr.m_AllocList.m_Head = -1;
    s_EditDispMgr.m_AllocList.m_NumAlloced = 0;
    s_EditDispMgr.m_AllocList.m_pElements = nullptr;
    atexit(func: EditDispMgr_::_2_::_dynamic_atexit_destructor_for__s_EditDispMgr__);
  }
  return &s_EditDispMgr;
}

//------------------------------------------------------------------------------
// Address: 0x1001E130
// Name: public: virtual unsigned short CEditDispMgr::Create(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEditDispMgr::Create(CEditDispMgr *this)
{
  CUtlLinkedList<CMapDisp,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMapDisp,unsigned short>,unsigned short> > *p_m_AllocList; // edi
  int v2; // esi
  int result; // eax

  p_m_AllocList = &this->m_AllocList;
  v2 = CUtlLinkedList<CMapDisp,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMapDisp,unsigned short>,unsigned short>>::AllocInternal(
         this: &this->m_AllocList,
         multilist: false);
  result = 0xFFFF;
  if ( (_WORD)v2 != 0xFFFF )
  {
    CUtlLinkedList<CMapDisp,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CMapDisp,unsigned short>,unsigned short>>::LinkBefore(
      this: p_m_AllocList,
      before: 0xFFFFu,
      elem: v2);
    if ( &p_m_AllocList->m_Memory.m_pMemory[v2] != nullptr )
      CMapDisp::CMapDisp(this: &p_m_AllocList->m_Memory.m_pMemory[v2].m_Element);
    p_m_AllocList->m_Memory.m_pMemory[v2].m_Element.m_EditHandle = v2;
    return v2;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001E1C0
// Name: class IWorldEditDispMgr __near * CreateWorldEditDispMgr(void)
// Source: json
//------------------------------------------------------------------------------
CWorldEditDispMgr *__cdecl CreateWorldEditDispMgr()
{
  CWorldEditDispMgr *v0; // eax

  v0 = (CWorldEditDispMgr *)operator new(nSize: 0x44u);
  if ( v0 != nullptr )
    return CWorldEditDispMgr::CWorldEditDispMgr(this: v0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1001E250
// Name: public: virtual class CMapDisp __near * CWorldEditDispMgr::GetFromWorld(int)
// Source: json
//------------------------------------------------------------------------------
CMapDisp *__thiscall CWorldEditDispMgr::GetFromWorld(CWorldEditDispMgr *this, int iWorldList)
{
  int v2; // esi
  CEditDispMgr *v3; // eax

  v2 = this->m_WorldList.m_Memory.m_pMemory[iWorldList];
  v3 = EditDispMgr();
  return v3->GetDisp(this: v3, a2: v2);
}

//------------------------------------------------------------------------------
// Address: 0x1001E280
// Name: public: virtual class CMapDisp __near * CWorldEditDispMgr::GetFromWorld(unsigned short)
// Source: json
//------------------------------------------------------------------------------
CMapDisp *__thiscall CWorldEditDispMgr::GetFromWorld(CWorldEditDispMgr *this, int handle)
{
  int m_Size; // edx
  int v3; // eax
  unsigned __int16 *i; // ecx
  CEditDispMgr *v6; // eax

  m_Size = this->m_WorldList.m_Size;
  v3 = 0;
  if ( m_Size <= 0 )
    return nullptr;
  for ( i = this->m_WorldList.m_Memory.m_pMemory; *i != (_WORD)handle; ++i )
  {
    if ( ++v3 >= m_Size )
      return nullptr;
  }
  if ( v3 == -1 )
    return nullptr;
  v6 = EditDispMgr();
  return v6->GetDisp(this: v6, a2: handle);
}

//------------------------------------------------------------------------------
// Address: 0x1001E2C0
// Name: public: virtual void CWorldEditDispMgr::AddToWorld(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorldEditDispMgr::AddToWorld(CWorldEditDispMgr *this, int handle)
{
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *p_m_WorldList; // esi
  int m_Size; // ecx
  int v4; // eax
  unsigned __int16 *m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v7; // edi
  unsigned __int16 *v8; // ecx
  int v9; // eax
  CEditDispMgr *v10; // eax
  CMapDisp *v11; // eax

  p_m_WorldList = &this->m_WorldList;
  m_Size = this->m_WorldList.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    goto LABEL_7;
  m_pMemory = p_m_WorldList->m_Memory.m_pMemory;
  while ( *m_pMemory != (_WORD)handle )
  {
    ++v4;
    ++m_pMemory;
    if ( v4 >= m_Size )
      goto LABEL_7;
  }
  if ( v4 == -1 )
  {
LABEL_7:
    m_nAllocationCount = p_m_WorldList->m_Memory.m_nAllocationCount;
    v7 = m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CUtlSymbol,int>::Grow(this: &p_m_WorldList->m_Memory, num: m_Size - m_nAllocationCount + 1);
    ++p_m_WorldList->m_Size;
    v8 = p_m_WorldList->m_Memory.m_pMemory;
    v9 = p_m_WorldList->m_Size - v7 - 1;
    p_m_WorldList->m_pElements = p_m_WorldList->m_Memory.m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &v8[v7 + 1], src: &v8[v7], count: 2 * v9);
    p_m_WorldList->m_Memory.m_pMemory[v7] = handle;
  }
  v10 = EditDispMgr();
  v11 = v10->GetDisp(this: v10, a2: handle);
  if ( v11 != nullptr )
    CMapDisp::UpdateData(this: v11);
}

//------------------------------------------------------------------------------
// Address: 0x1001E350
// Name: public: virtual class CMapDisp __near * CWorldEditDispMgr::GetFromSelect(int)
// Source: json
//------------------------------------------------------------------------------
CMapDisp *__thiscall CWorldEditDispMgr::GetFromSelect(CWorldEditDispMgr *this, int iSelectList)
{
  int v2; // esi
  CEditDispMgr *v3; // eax

  v2 = this->m_SelectList.m_Memory.m_pMemory[iSelectList];
  v3 = EditDispMgr();
  return v3->GetDisp(this: v3, a2: v2);
}

//------------------------------------------------------------------------------
// Address: 0x1001E380
// Name: public: virtual void CWorldEditDispMgr::Undo(unsigned short,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CWorldEditDispMgr::Undo(CWorldEditDispMgr *this@<ecx>, int a2@<ebx>, int hDisp, bool bAddNeighbors)
{
  CEditDispMgr *v5; // eax
  int v6; // eax
  int v7; // eax
  CMapClass *v8; // eax
  CMapClass *v9; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CMapClass **m_pMemory; // ecx
  int v13; // eax
  CMapClass **v14; // eax
  CHistory *History; // eax
  int v16; // edi
  int v17; // esi
  CEditDispMgr *v18; // eax
  int v19; // eax
  int v20; // esi
  CEditDispMgr *v21; // eax
  int v22; // eax
  int v23; // eax
  CMapClass *v24; // ebx
  int v25; // edi
  int v26; // eax
  CMapClass **v27; // ecx
  int v28; // eax
  CMapClass **v29; // eax
  CHistory *v30; // eax
  CEditDispMgr *v31; // eax
  int v32; // eax
  int v33; // ebx
  CEditDispMgr *v34; // eax
  int v35; // eax
  int v36; // esi
  CEditDispMgr *v37; // eax
  int v38; // eax
  int v39; // eax
  CMapClass *v40; // ebx
  int v41; // edi
  int v42; // eax
  CMapClass **v43; // ecx
  int v44; // eax
  CMapClass **v45; // eax
  CHistory *v46; // eax
  int nCornerCount; // [esp+8h] [ebp-10h]
  int v49; // [esp+Ch] [ebp-Ch]
  int v50; // [esp+10h] [ebp-8h]
  int iCorner; // [esp+24h] [ebp+Ch]

  if ( (_WORD)hDisp != 0xFFFF )
  {
    v5 = EditDispMgr();
    v6 = (int)v5->GetDisp(this: v5, a2: hDisp);
    if ( v6 != 0 )
    {
      v7 = (*(int (__thiscall **)(int))(*(_DWORD *)v6 + 36))(a1: v6);
      v8 = (CMapClass *)(*(int (__thiscall **)(int))(*(_DWORD *)v7 + 36))(a1: v7);
      v9 = v8;
      if ( v8 != nullptr )
      {
        if ( !CWorldEditDispMgr::IsInKeptList(this, pObject: v8) )
        {
          m_Size = this->m_aKeptList.m_Size;
          m_nAllocationCount = this->m_aKeptList.m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<CVisGroup *,int>::Grow(
              this: (CUtlMemory<CCullTreeNode *,int> *)&this->m_aKeptList,
              num: m_Size - m_nAllocationCount + 1);
          ++this->m_aKeptList.m_Size;
          m_pMemory = this->m_aKeptList.m_Memory.m_pMemory;
          v13 = this->m_aKeptList.m_Size - m_Size - 1;
          this->m_aKeptList.m_pElements = m_pMemory;
          if ( v13 > 0 )
            _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v13);
          v14 = &this->m_aKeptList.m_Memory.m_pMemory[m_Size];
          if ( v14 != nullptr )
            *v14 = v9;
          History = GetHistory();
          CHistory::Keep(this: History, pObject: v9);
        }
        if ( bAddNeighbors )
        {
          v16 = 924;
          v17 = 900;
          v50 = 924;
          v49 = 900;
          do
          {
            v18 = EditDispMgr();
            v19 = ((int (__thiscall *)(CEditDispMgr *, int, int))v18->GetDisp)(a1: v18, a2: hDisp, a3: a2);
            if ( v19 != 0 )
            {
              v20 = *(unsigned __int16 *)(v17 + v19);
              if ( (_WORD)v20 != 0xFFFF )
              {
                v21 = EditDispMgr();
                v22 = (int)v21->GetDisp(this: v21, a2: v20);
                v23 = (*(int (__thiscall **)(int))(*(_DWORD *)v22 + 36))(a1: v22);
                v24 = (CMapClass *)(*(int (__thiscall **)(int))(*(_DWORD *)v23 + 36))(a1: v23);
                if ( !CWorldEditDispMgr::IsInKeptList(this, pObject: v24) )
                {
                  v25 = this->m_aKeptList.m_Size;
                  v26 = this->m_aKeptList.m_Memory.m_nAllocationCount;
                  if ( v25 + 1 > v26 )
                    CUtlMemory<CVisGroup *,int>::Grow(
                      this: (CUtlMemory<CCullTreeNode *,int> *)&this->m_aKeptList,
                      num: v25 - v26 + 1);
                  ++this->m_aKeptList.m_Size;
                  v27 = this->m_aKeptList.m_Memory.m_pMemory;
                  v28 = this->m_aKeptList.m_Size - v25 - 1;
                  this->m_aKeptList.m_pElements = v27;
                  if ( v28 > 0 )
                    _V_memmove(dest: &v27[v25 + 1], src: &v27[v25], count: 4 * v28);
                  v29 = &this->m_aKeptList.m_Memory.m_pMemory[v25];
                  if ( v29 != nullptr )
                    *v29 = v24;
                  v30 = GetHistory();
                  CHistory::Keep(this: v30, pObject: v24);
                  v16 = v50;
                }
              }
            }
            v31 = EditDispMgr();
            a2 = hDisp;
            v32 = ((int (__thiscall *)(CEditDispMgr *))v31->GetDisp)(a1: v31);
            if ( v32 != 0 )
            {
              v33 = 0;
              nCornerCount = *(_DWORD *)(v16 + v32);
              iCorner = 0;
              if ( nCornerCount > 0 )
              {
                do
                {
                  v34 = EditDispMgr();
                  v35 = (int)v34->GetDisp(this: v34, a2: hDisp);
                  if ( v35 != 0 )
                  {
                    v36 = 0xFFFF;
                    if ( v33 < *(_DWORD *)(v16 + v35) )
                      v36 = *(unsigned __int16 *)(v35 + 2 * (v16 + v33) - 908);
                    v37 = EditDispMgr();
                    v38 = (int)v37->GetDisp(this: v37, a2: v36);
                    if ( v38 != 0 )
                    {
                      v39 = (*(int (__thiscall **)(int))(*(_DWORD *)v38 + 36))(a1: v38);
                      v40 = (CMapClass *)(*(int (__thiscall **)(int))(*(_DWORD *)v39 + 36))(a1: v39);
                      if ( !CWorldEditDispMgr::IsInKeptList(this, pObject: v40) )
                      {
                        v41 = this->m_aKeptList.m_Size;
                        v42 = this->m_aKeptList.m_Memory.m_nAllocationCount;
                        if ( v41 + 1 > v42 )
                          CUtlMemory<CVisGroup *,int>::Grow(
                            this: (CUtlMemory<CCullTreeNode *,int> *)&this->m_aKeptList,
                            num: v41 - v42 + 1);
                        ++this->m_aKeptList.m_Size;
                        v43 = this->m_aKeptList.m_Memory.m_pMemory;
                        v44 = this->m_aKeptList.m_Size - v41 - 1;
                        this->m_aKeptList.m_pElements = v43;
                        if ( v44 > 0 )
                          _V_memmove(dest: &v43[v41 + 1], src: &v43[v41], count: 4 * v44);
                        v45 = &this->m_aKeptList.m_Memory.m_pMemory[v41];
                        if ( v45 != nullptr )
                          *v45 = v40;
                        v46 = GetHistory();
                        CHistory::Keep(this: v46, pObject: v40);
                        v16 = v50;
                      }
                      v33 = iCorner;
                    }
                  }
                  iCorner = ++v33;
                }
                while ( v33 < nCornerCount );
              }
            }
            v17 = v49 + 2;
            v16 += 4;
            v49 = v17;
            v50 = v16;
          }
          while ( v17 < 908 );
        }
      }
    }
  }
}
