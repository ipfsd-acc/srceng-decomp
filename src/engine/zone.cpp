// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/zone.cpp
// Functions: 10
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x101FEED0
// Name: int HunkAllocSortFunc(void const __near *,void const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl HunkAllocSortFunc(_DWORD *a, _DWORD *b)
{
  return 2 * (a[1] <= b[1]) - 1;
}

//------------------------------------------------------------------------------
// Address: 0x101FEEF0
// Name: int Hunk_MallocSize(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl Hunk_MallocSize()
{
  return CMemoryStack::GetSize(this: &g_HunkMemoryStack);
}

//------------------------------------------------------------------------------
// Address: 0x101FEF00
// Name: int Hunk_LowMark(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Hunk_LowMark()
{
  return g_HunkMemoryStack.m_pNextAlloc - g_HunkMemoryStack.m_pBase;
}

//------------------------------------------------------------------------------
// Address: 0x101FEF10
// Name: void Hunk_Print(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Hunk_Print()
{
  unsigned int Size; // eax

  _Msg(a1: "Total used memory:      %d\n", g_HunkMemoryStack.m_pNextAlloc - g_HunkMemoryStack.m_pBase);
  Size = CMemoryStack::GetSize(this: &g_HunkMemoryStack);
  _Msg(a1: "Total committed memory: %d\n", Size);
}

//------------------------------------------------------------------------------
// Address: 0x101FEF50
// Name: void Memory_Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Memory_Shutdown()
{
  CMemoryStack::FreeAll(this: &g_HunkMemoryStack, bDecommit: true);
  g_pDataCache->SetSize(this: g_pDataCache, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x101FEF70
// Name: void Hunk_OnMapStart(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Hunk_OnMapStart(int nEstimatedBytes)
{
  int v1; // esi

  v1 = nEstimatedBytes;
  if ( nEstimatedBytes <= 41943040 )
    v1 = 41943040;
  if ( developer.m_pParent != nullptr && developer.m_pParent->m_Value.m_nValue != 0 )
    DevMsg(a1: "Hunk_OnMapStart: %d\n", v1);
  if ( v1 > 0 && CMemoryStack::GetSize(this: &g_HunkMemoryStack) != v1 )
    CMemoryStack::CommitTo(this: &g_HunkMemoryStack, pNextAlloc: &g_HunkMemoryStack.m_pBase[v1]);
}

//------------------------------------------------------------------------------
// Address: 0x101FEFD0
// Name: void Memory_Init(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Memory_Init()
{
  int v0; // esi
  signed int v1; // edi
  int v2; // eax

  v0 = 50331648;
  if ( !CMemoryStack::Init(
          this: &g_HunkMemoryStack,
          pszAllocOwner: "g_HunkMemoryStack",
          maxSize: 0x3000000u,
          commitSize: 0x10000u,
          initialCommit: 0x2800000u,
          alignment: 0x10u) )
  {
    do
    {
      v1 = v0 / 2;
      _Warning(a1: "Unable to allocate %d MB of memory, trying %d MB instead\n", v0, v0 / 2);
      v0 = v1;
      if ( v1 < 50331648 )
        _Error(a1: "Failed to allocate minimum memory requirement for game (%d MB)\n", 48);
    }
    while ( !CMemoryStack::Init(
               this: &g_HunkMemoryStack,
               pszAllocOwner: "g_HunkMemoryStack",
               maxSize: v1,
               commitSize: 0x10000u,
               initialCommit: 0x2800000u,
               alignment: 0x10u) );
  }
  v2 = host_parms.memsize + g_HunkMemoryStack.m_pBase - g_HunkMemoryStack.m_pNextAlloc;
  if ( v2 < 0x100000 )
    v2 = 0x100000;
  g_pDataCache->SetSize(this: g_pDataCache, a2: v2);
}

//------------------------------------------------------------------------------
// Address: 0x101FF080
// Name: hunk_print_allocations
// Source: json
//------------------------------------------------------------------------------
void __cdecl hunk_print_allocations()
{
  signed int v0; // edi
  int *v1; // ebx
  int Inorder; // eax
  int *v3; // esi
  int elem; // ecx
  signed int i; // esi
  int total; // [esp+Ch] [ebp-4h]

  _Msg(a1: "Hunk allocations:\n");
  v0 = 0;
  v1 = (int *)MemAlloc_Alloc(
                nSize: (unsigned __int64)(unsigned int)g_HunkAllocationsByName.m_Elements.m_Tree.m_NumElements >> 29 != 0
              ? -1
              : 8 * g_HunkAllocationsByName.m_Elements.m_Tree.m_NumElements);
  total = 0;
  Inorder = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::FirstInorder(this: &g_HunkAllocationsByName.m_Elements.m_Tree);
  if ( Inorder != -1 )
  {
    v3 = v1;
    do
    {
      elem = g_HunkAllocationsByName.m_Elements.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.elem;
      if ( elem != 0 )
      {
        *v3 = Inorder;
        v3[1] = elem;
        ++v0;
        v3 += 2;
        total += elem;
      }
      Inorder = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::NextInorder(
                  this: &g_HunkAllocationsByName.m_Elements.m_Tree,
                  i: Inorder);
    }
    while ( Inorder != -1 );
  }
  qsort(base: v1, num: v0, width: 8u, comp: (int (__cdecl *)(const void *, const void *))HunkAllocSortFunc);
  _Msg(a1: "    %55s:%10d\n", "TOTAL:", total);
  for ( i = 0; i < v0; ++i )
    _Msg(
      a1: "    %55s:%10d\n",
      g_HunkAllocationsByName.m_Elements.m_Tree.m_Elements.m_pMemory[v1[2 * i]].m_Data.key,
      v1[2 * i + 1]);
  free(pMem: v1);
}

//------------------------------------------------------------------------------
// Address: 0x101FF170
// Name: void Hunk_FreeToLowMark(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Hunk_FreeToLowMark(unsigned int mark)
{
  CMemoryStack::FreeToAllocPoint(this: &g_HunkMemoryStack, mark, bDecommit: false);
  CUtlDict<int,int>::RemoveAll(this: &g_HunkAllocationsByName);
}

//------------------------------------------------------------------------------
// Address: 0x101FF190
// Name: void __near * Hunk_AllocName(int,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl Hunk_AllocName(unsigned int size, char *name, bool bClear)
{
  char *v3; // esi
  int v4; // eax
  unsigned int m_alignment; // ecx
  unsigned int v6; // esi
  unsigned __int8 *v7; // edi
  unsigned __int8 *m_pNextAlloc; // ebx
  CUtlMap<char const *,int,int>::Node_t search; // [esp+Ch] [ebp-8h] BYREF

  if ( hunk_track_allocation_types.m_pParent != nullptr && hunk_track_allocation_types.m_pParent->m_Value.m_nValue != 0 )
  {
    v3 = name;
    if ( name == nullptr )
      v3 = "unknown";
    search.key = v3;
    v4 = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Find(
           this: &g_HunkAllocationsByName.m_Elements.m_Tree,
           &search);
    if ( v4 == -1 )
      g_HunkAllocationsByName.m_Elements.m_Tree.m_Elements.m_pMemory[CUtlDict<int,int>::Insert(
                                                                       this: &g_HunkAllocationsByName,
                                                                       pName: v3)].m_Data.elem = size;
    else
      g_HunkAllocationsByName.m_Elements.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem += size;
  }
  m_alignment = size;
  if ( size <= g_HunkMemoryStack.m_alignment )
    m_alignment = g_HunkMemoryStack.m_alignment;
  v6 = ~(g_HunkMemoryStack.m_alignment - 1) & (g_HunkMemoryStack.m_alignment + m_alignment - 1);
  v7 = &g_HunkMemoryStack.m_pNextAlloc[v6];
  m_pNextAlloc = g_HunkMemoryStack.m_pNextAlloc;
  if ( &g_HunkMemoryStack.m_pNextAlloc[v6] <= g_HunkMemoryStack.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &g_HunkMemoryStack, pNextAlloc: &g_HunkMemoryStack.m_pNextAlloc[v6]) != 0 )
  {
    if ( bClear )
      memset(dst: m_pNextAlloc, value: 0, count: v6);
    g_HunkMemoryStack.m_pNextAlloc = v7;
    if ( m_pNextAlloc != nullptr )
      return m_pNextAlloc;
  }
  _Error(a1: "Engine hunk overflow!\n");
  return nullptr;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x101FF130
// Name: int HunkAllocSortFunc(void const __near *,void const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl HunkAllocSortFunc(_DWORD *a, _DWORD *b)
{
  return 2 * (a[1] <= b[1]) - 1;
}

//------------------------------------------------------------------------------
// Address: 0x101FF150
// Name: int Hunk_LowMark(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Hunk_LowMark()
{
  return g_HunkMemoryStack.m_pNextAlloc - g_HunkMemoryStack.m_pBase;
}

//------------------------------------------------------------------------------
// Address: 0x101FF160
// Name: int Hunk_MallocSize(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Hunk_MallocSize()
{
  return CMemoryStack::GetSize(this: &g_HunkMemoryStack);
}

//------------------------------------------------------------------------------
// Address: 0x101FF1B0
// Name: void Memory_Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Memory_Shutdown()
{
  CMemoryStack::FreeAll(this: &g_HunkMemoryStack, bDecommit: true);
  g_pDataCache->SetSize(this: g_pDataCache, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x101FF1D0
// Name: void Hunk_OnMapStart(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Hunk_OnMapStart(int nEstimatedBytes)
{
  int v1; // esi

  v1 = nEstimatedBytes;
  if ( nEstimatedBytes <= 41943040 )
    v1 = 41943040;
  if ( developer.m_pParent != nullptr && developer.m_pParent->m_Value.m_nValue != 0 )
    DevMsg(a1: "Hunk_OnMapStart: %d\n", v1);
  if ( v1 > 0 && CMemoryStack::GetSize(this: &g_HunkMemoryStack) != v1 )
    CMemoryStack::CommitTo(this: &g_HunkMemoryStack, pNextAlloc: &g_HunkMemoryStack.m_pBase[v1]);
}

//------------------------------------------------------------------------------
// Address: 0x101FF230
// Name: void Memory_Init(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Memory_Init()
{
  int v0; // esi
  signed int v1; // edi
  int v2; // eax

  v0 = 50331648;
  if ( !CMemoryStack::Init(
          this: &g_HunkMemoryStack,
          pszAllocOwner: "g_HunkMemoryStack",
          maxSize: 0x3000000u,
          commitSize: 0x10000u,
          initialCommit: 0x2800000u,
          alignment: 0x10u) )
  {
    do
    {
      v1 = v0 / 2;
      _Warning(a1: "Unable to allocate %d MB of memory, trying %d MB instead\n", v0, v0 / 2);
      v0 = v1;
      if ( v1 < 50331648 )
        _Error(a1: "Failed to allocate minimum memory requirement for game (%d MB)\n", 48);
    }
    while ( !CMemoryStack::Init(
               this: &g_HunkMemoryStack,
               pszAllocOwner: "g_HunkMemoryStack",
               maxSize: v1,
               commitSize: 0x10000u,
               initialCommit: 0x2800000u,
               alignment: 0x10u) );
  }
  v2 = host_parms.memsize + g_HunkMemoryStack.m_pBase - g_HunkMemoryStack.m_pNextAlloc;
  if ( v2 < 0x100000 )
    v2 = 0x100000;
  g_pDataCache->SetSize(this: g_pDataCache, a2: v2);
}

//------------------------------------------------------------------------------
// Address: 0x101FF2E0
// Name: hunk_print_allocations
// Source: json
//------------------------------------------------------------------------------
void __cdecl hunk_print_allocations()
{
  signed int v0; // edi
  int *v1; // ebx
  int Inorder; // eax
  int *v3; // esi
  int elem; // ecx
  signed int i; // esi
  int total; // [esp+Ch] [ebp-4h]

  _Msg(a1: "Hunk allocations:\n");
  v0 = 0;
  v1 = (int *)MemAlloc_Alloc(
                nSize: (unsigned __int64)(unsigned int)g_HunkAllocationsByName.m_Elements.m_Tree.m_NumElements >> 29 != 0
              ? -1
              : 8 * g_HunkAllocationsByName.m_Elements.m_Tree.m_NumElements);
  total = 0;
  Inorder = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::FirstInorder(this: &g_HunkAllocationsByName.m_Elements.m_Tree);
  if ( Inorder != -1 )
  {
    v3 = v1;
    do
    {
      elem = g_HunkAllocationsByName.m_Elements.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.elem;
      if ( elem != 0 )
      {
        *v3 = Inorder;
        v3[1] = elem;
        ++v0;
        v3 += 2;
        total += elem;
      }
      Inorder = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::NextInorder(
                  this: &g_HunkAllocationsByName.m_Elements.m_Tree,
                  i: Inorder);
    }
    while ( Inorder != -1 );
  }
  qsort(base: v1, num: v0, width: 8u, comp: (int (__cdecl *)(const void *, const void *))HunkAllocSortFunc);
  _Msg(a1: "    %55s:%10d\n", "TOTAL:", total);
  for ( i = 0; i < v0; ++i )
    _Msg(
      a1: "    %55s:%10d\n",
      g_HunkAllocationsByName.m_Elements.m_Tree.m_Elements.m_pMemory[v1[2 * i]].m_Data.key,
      v1[2 * i + 1]);
  free(pMem: v1);
}

//------------------------------------------------------------------------------
// Address: 0x101FF3D0
// Name: void Hunk_FreeToLowMark(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Hunk_FreeToLowMark(unsigned int mark)
{
  CMemoryStack::FreeToAllocPoint(this: &g_HunkMemoryStack, mark, bDecommit: false);
  CUtlDict<int,int>::RemoveAll(this: &g_HunkAllocationsByName);
}

//------------------------------------------------------------------------------
// Address: 0x101FF3F0
// Name: void __near * Hunk_AllocName(int,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl Hunk_AllocName(unsigned int size, char *name, bool bClear)
{
  char *v3; // esi
  int v4; // eax
  unsigned int m_alignment; // ecx
  unsigned int v6; // esi
  unsigned __int8 *v7; // edi
  unsigned __int8 *m_pNextAlloc; // ebx
  CUtlMap<char const *,int,int>::Node_t search; // [esp+Ch] [ebp-8h] BYREF

  if ( hunk_track_allocation_types.m_pParent != nullptr && hunk_track_allocation_types.m_pParent->m_Value.m_nValue != 0 )
  {
    v3 = name;
    if ( name == nullptr )
      v3 = "unknown";
    search.key = v3;
    v4 = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Find(
           this: &g_HunkAllocationsByName.m_Elements.m_Tree,
           &search);
    if ( v4 == -1 )
      g_HunkAllocationsByName.m_Elements.m_Tree.m_Elements.m_pMemory[CUtlDict<int,int>::Insert(
                                                                       this: &g_HunkAllocationsByName,
                                                                       pName: v3)].m_Data.elem = size;
    else
      g_HunkAllocationsByName.m_Elements.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem += size;
  }
  m_alignment = size;
  if ( size <= g_HunkMemoryStack.m_alignment )
    m_alignment = g_HunkMemoryStack.m_alignment;
  v6 = ~(g_HunkMemoryStack.m_alignment - 1) & (g_HunkMemoryStack.m_alignment + m_alignment - 1);
  v7 = &g_HunkMemoryStack.m_pNextAlloc[v6];
  m_pNextAlloc = g_HunkMemoryStack.m_pNextAlloc;
  if ( &g_HunkMemoryStack.m_pNextAlloc[v6] <= g_HunkMemoryStack.m_pCommitLimit
    || CMemoryStack::CommitTo(this: &g_HunkMemoryStack, pNextAlloc: &g_HunkMemoryStack.m_pNextAlloc[v6]) )
  {
    if ( bClear )
      memset(dst: m_pNextAlloc, value: 0, count: v6);
    g_HunkMemoryStack.m_pNextAlloc = v7;
    if ( m_pNextAlloc != nullptr )
      return m_pNextAlloc;
  }
  _Error(a1: "Engine hunk overflow!\n");
  return nullptr;
}

} // namespace engine_xlsp
