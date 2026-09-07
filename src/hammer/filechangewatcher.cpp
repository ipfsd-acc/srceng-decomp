// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/filechangewatcher.cpp
// Functions: 11
// ============================================================

#include "hammer\filechangewatcher.h"

//------------------------------------------------------------------------------
// Address: 0x10031BD0
// Name: bool StringLessThan(char const __near * const __near &,char const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl StringLessThan(const char **lhs, const char **rhs)
{
  int v3; // kr00_4

  if ( *lhs == nullptr )
    return false;
  if ( *rhs == nullptr )
    return true;
  v3 = strcmp(*lhs, *rhs);
  return v3 != 0 && -(v3 < 0) - ((v3 < 0) - 1) < 0;
}

//------------------------------------------------------------------------------
// Address: 0x10031C30
// Name: bool CaselessStringLessThan(char const __near * const __near &,char const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CaselessStringLessThan(const char **lhs, const char **rhs)
{
  if ( *lhs == nullptr )
    return false;
  if ( *rhs != nullptr )
    return _V_stricmp(s1: *lhs, s2: *rhs) < 0;
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x10032DB0
// Name: public: CFileChangeWatcher::CFileChangeWatcher(void)
// Source: json
//------------------------------------------------------------------------------
CFileChangeWatcher *__thiscall CFileChangeWatcher::CFileChangeWatcher(CFileChangeWatcher *this)
{
  CFileChangeWatcher::CDirWatch **m_pMemory; // edx

  this->m_DirWatches.m_Memory.m_pMemory = nullptr;
  this->m_DirWatches.m_Memory.m_nAllocationCount = 0;
  this->m_DirWatches.m_Memory.m_nGrowSize = 0;
  m_pMemory = this->m_DirWatches.m_Memory.m_pMemory;
  this->m_DirWatches.m_Size = 0;
  this->m_DirWatches.m_pElements = m_pMemory;
  this->m_pCallbacks = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10032E10
// Name: public: void CFileChangeWatcher::Term(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileChangeWatcher::Term(CFileChangeWatcher *this)
{
  int i; // edi
  int j; // edi

  for ( i = 0; i < this->m_DirWatches.m_Size; ++i )
  {
    CloseHandle(hObject: this->m_DirWatches.m_Memory.m_pMemory[i]->m_hDir);
    CloseHandle(hObject: this->m_DirWatches.m_Memory.m_pMemory[i]->m_hEvent);
  }
  for ( j = 0; j < this->m_DirWatches.m_Size; ++j )
    operator delete(p: this->m_DirWatches.m_Memory.m_pMemory[j]);
  this->m_DirWatches.m_Size = 0;
  if ( this->m_DirWatches.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_DirWatches.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_DirWatches.m_Memory.m_pMemory);
      this->m_DirWatches.m_Memory.m_pMemory = nullptr;
    }
    this->m_DirWatches.m_Memory.m_nAllocationCount = 0;
  }
  this->m_DirWatches.m_pElements = this->m_DirWatches.m_Memory.m_pMemory;
  this->m_pCallbacks = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10032FA0
// Name: public: CFileChangeWatcher::~CFileChangeWatcher(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileChangeWatcher::~CFileChangeWatcher(CFileChangeWatcher *this)
{
  CFileChangeWatcher::Term(this);
  this->m_DirWatches.m_Size = 0;
  if ( this->m_DirWatches.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_DirWatches.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_DirWatches.m_Memory.m_pMemory);
      this->m_DirWatches.m_Memory.m_pMemory = nullptr;
    }
    this->m_DirWatches.m_Memory.m_nAllocationCount = 0;
  }
  this->m_DirWatches.m_pElements = this->m_DirWatches.m_Memory.m_pMemory;
  if ( this->m_DirWatches.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_DirWatches.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_DirWatches.m_Memory.m_pMemory);
      this->m_DirWatches.m_Memory.m_pMemory = nullptr;
    }
    this->m_DirWatches.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10033030
// Name: public: void CFileChangeWatcher::Init(class CFileChangeWatcher::ICallbacks __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileChangeWatcher::Init(CFileChangeWatcher *this, CFileChangeWatcher::ICallbacks *pCallbacks)
{
  CFileChangeWatcher::Term(this);
  this->m_pCallbacks = pCallbacks;
}

//------------------------------------------------------------------------------
// Address: 0x10033050
// Name: public: bool CFileChangeWatcher::AddDirectory(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CFileChangeWatcher::AddDirectory(
        CFileChangeWatcher *this,
        const char *pSearchPathBase,
        const char *pDirName,
        bool bRecursive)
{
  HANDLE FileA; // ebx
  char *v7; // esi
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  CFileChangeWatcher::CDirWatch **m_pMemory; // ecx
  int v11; // eax
  CFileChangeWatcher::CDirWatch **v12; // ebx
  void *v13; // [esp-20h] [ebp-130h]
  char fullDirName[260]; // [esp+Ch] [ebp-104h] BYREF

  V_ComposeFileName(path: pSearchPathBase, filename: pDirName, dest: fullDirName, destSize: 260);
  FileA = CreateFileA(
            lpFileName: fullDirName,
            dwDesiredAccess: 0x80000000,
            dwShareMode: 7u,
            lpSecurityAttributes: nullptr,
            dwCreationDisposition: 3u,
            dwFlagsAndAttributes: 0x42000000u,
            hTemplateFile: nullptr);
  if ( FileA == (HANDLE)-1 )
  {
    _Warning(a1: "CFileChangeWatcher::AddDirectory - can't get a handle to directory %s.\n", pDirName);
    return 0;
  }
  else
  {
    v7 = (char *)operator new(nSize: 0x4328u);
    V_strncpy(pDest: v7, pSrc: pSearchPathBase, maxLen: 260);
    V_strncpy(pDest: v7 + 260, pSrc: pDirName, maxLen: 260);
    V_strncpy(pDest: v7 + 520, pSrc: fullDirName, maxLen: 260);
    *((_DWORD *)v7 + 201) = FileA;
    *((_DWORD *)v7 + 200) = CreateEventA(
                              lpEventAttributes: nullptr,
                              bManualReset: false,
                              bInitialState: false,
                              lpName: nullptr);
    *(_QWORD *)(v7 + 780) = 0;
    *(_QWORD *)(v7 + 788) = 0;
    *((_DWORD *)v7 + 199) = 0;
    v13 = *((void **)v7 + 201);
    *((_DWORD *)v7 + 199) = *((_DWORD *)v7 + 200);
    if ( ReadDirectoryChangesW(
           hDirectory: v13,
           lpBuffer: v7 + 808,
           nBufferLength: 0x4000u,
           bWatchSubtree: true,
           dwNotifyFilter: 0x19u,
           lpBytesReturned: nullptr,
           lpOverlapped: (LPOVERLAPPED)v7 + 39,
           lpCompletionRoutine: nullptr) )
    {
      m_Size = this->m_DirWatches.m_Size;
      m_nAllocationCount = this->m_DirWatches.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CVisGroup *,int>::Grow((CUtlMemory<CCullTreeNode *,int> *)this, num: m_Size - m_nAllocationCount + 1);
      ++this->m_DirWatches.m_Size;
      m_pMemory = this->m_DirWatches.m_Memory.m_pMemory;
      v11 = this->m_DirWatches.m_Size - m_Size - 1;
      this->m_DirWatches.m_pElements = this->m_DirWatches.m_Memory.m_pMemory;
      if ( v11 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v11);
      v12 = &this->m_DirWatches.m_Memory.m_pMemory[m_Size];
      if ( v12 != nullptr )
        *v12 = (CFileChangeWatcher::CDirWatch *)v7;
      return 1;
    }
    else
    {
      CloseHandle(hObject: *((HANDLE *)v7 + 200));
      CloseHandle(hObject: *((HANDLE *)v7 + 201));
      operator delete(p: v7);
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100331F0
// Name: public: CUtlMap<char const __near *,int,int>::~CUtlMap<char const __near *,int,int>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMap<char const *,int,int>::~CUtlMap<char const *,int,int>(CUtlMap<char const *,int,int> *this)
{
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>(this: &this->m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x10033230
// Name: public: void CUtlDict<int,int>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<int,int>::RemoveAll(CUtlDict<int,int> *this)
{
  int i; // esi

  for ( i = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    free(pMem: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x10033310
// Name: public: CUtlDict<int,int>::~CUtlDict<int,int>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<int,int>::~CUtlDict<int,int>(CUtlDict<int,int> *this)
{
  CUtlDict<int,int>::RemoveAll(this);
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x10033360
// Name: public: int CFileChangeWatcher::Update(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileChangeWatcher::Update(CFileChangeWatcher *this)
{
  _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // eax
  void *v2; // esp
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *m_pMemory; // edi
  CFileChangeWatcher::CDirWatch *v4; // esi
  DWORD v5; // ebx
  char *j; // edi
  bool v7; // zf
  unsigned int v8; // esi
  int v9; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v10; // ecx
  int v11; // edx
  int v12; // esi
  int v13; // edx
  CUtlMap<char const *,int,int>::Node_t *p_m_Data; // eax
  int v15; // esi
  const char *m_FullDirName; // ebx
  const char *key; // edi
  int k; // esi
  int m; // esi
  int m_nGrowSize; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v21; // eax
  void *m_hDir; // [esp-1Ch] [ebp-1584h]
  unsigned __int8 v24[2]; // [esp+0h] [ebp-1568h] BYREF
  char v25[1024]; // [esp+1000h] [ebp-568h] BYREF
  char v26[260]; // [esp+1400h] [ebp-168h] BYREF
  vgui::ToolWindow *v27; // [esp+1504h] [ebp-64h]
  CUtlMap<char const *,int,int>::Node_t v28; // [esp+1508h] [ebp-60h] BYREF
  char *v29; // [esp+1510h] [ebp-58h]
  CUtlMap<char const *,int,int>::Node_t v30; // [esp+1514h] [ebp-54h] BYREF
  DWORD v31; // [esp+151Ch] [ebp-4Ch] BYREF
  int v32; // [esp+1520h] [ebp-48h] BYREF
  CFileChangeWatcher::CDirWatch *v33; // [esp+1524h] [ebp-44h]
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> > v34; // [esp+1528h] [ebp-40h] BYREF
  int i; // [esp+154Ch] [ebp-1Ch]
  int v36; // [esp+1550h] [ebp-18h]
  CFileChangeWatcher *v37; // [esp+1554h] [ebp-14h]
  bool v38; // [esp+155Bh] [ebp-Dh] BYREF
  _EXCEPTION_REGISTRATION_RECORD *v39; // [esp+155Ch] [ebp-Ch]
  void *v40; // [esp+1560h] [ebp-8h]
  int v41; // [esp+1564h] [ebp-4h]

  v41 = -1;
  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  v40 = &_ehhandler__Update_CFileChangeWatcher__QAEHXZ;
  v39 = ExceptionList;
  v2 = alloca(5468);
  m_pMemory = nullptr;
  memset(&v34.m_Elements, 0, sizeof(v34.m_Elements));
  v37 = this;
  v34.m_Root = -1;
  v34.m_NumElements = 0;
  v34.m_FirstFree = -1;
  v34.m_LastAlloc.index = -1;
  v34.m_pElements = nullptr;
  v34.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  v41 = 3;
  v36 = 0;
  for ( i = 0; i < v37->m_DirWatches.m_Size; m_pMemory = v34.m_Elements.m_pMemory )
  {
    v4 = this->m_DirWatches.m_Memory.m_pMemory[i];
    v31 = 0;
    m_hDir = v4->m_hDir;
    v33 = v4;
    if ( GetOverlappedResult(
           hFile: m_hDir,
           lpOverlapped: &v4->m_Overlapped,
           lpNumberOfBytesTransferred: &v31,
           bWait: false) )
    {
      v5 = v31;
      for ( j = v4->m_Buffer; v5 >= 0x10; v5 -= *(_DWORD *)v29 )
      {
        v7 = v37->m_pCallbacks == nullptr;
        v29 = j;
        if ( !v7 )
        {
          v8 = *((_DWORD *)j + 2);
          if ( v8 >= 0x7FF )
            v8 = 2047;
          memcpy(dst: v24, src: (unsigned __int8 *)j + 12, count: v8);
          *(_WORD *)&v24[2 * ((int)v8 / 2)] = 0;
          _V_UnicodeToUTF8(a1: v24, a2: v25, a3: 1024);
          v28.key = v25;
          if ( CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Find(
                 this: &v34,
                 search: &v28) == -1 )
          {
            v30.key = _strdup(string: v25);
            v30.elem = 0;
            v32 = -1;
            v38 = false;
            CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::FindInsertionPosition(
              this: &v34,
              insert: &v30,
              parent: &v32,
              leftchild: &v38);
            v9 = CUtlRBTree<CUtlMap<char const *,CUtlReferenceVector<CMapEntity> *,int>::Node_t,int,CUtlMap<char const *,CUtlReferenceVector<CMapEntity> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlReferenceVector<CMapEntity> *,int>::Node_t,int>,int>>::NewNode(
                   this: &v34,
                   a2: j);
            v10 = v34.m_Elements.m_pMemory;
            v11 = v32;
            v12 = v9;
            v34.m_Elements.m_pMemory[v12].m_Parent = v32;
            v10[v12].m_Right = -1;
            v10[v12].m_Left = -1;
            v10[v12].m_Tag = 0;
            if ( v11 == -1 )
            {
              v34.m_Root = v9;
            }
            else
            {
              v13 = v11;
              if ( v38 )
                v10[v13].m_Left = v9;
              else
                v10[v13].m_Right = v9;
            }
            CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::InsertRebalance(
              this: &v34,
              elem: v9);
            p_m_Data = &v34.m_Elements.m_pMemory[v12].m_Data;
            ++v34.m_NumElements;
            v32 = (int)p_m_Data;
            v27 = (vgui::ToolWindow *)p_m_Data;
            LOBYTE(v41) = 4;
            if ( &v34.m_Elements.m_pMemory[v12] != (UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *)-16 )
              *p_m_Data = v30;
            LOBYTE(v41) = 3;
            ++v36;
          }
          v4 = v33;
        }
        if ( *(_DWORD *)j == 0 )
          break;
        j += *(_DWORD *)j;
      }
      ReadDirectoryChangesW(
        hDirectory: v4->m_hDir,
        lpBuffer: v4->m_Buffer,
        nBufferLength: 0x4000u,
        bWatchSubtree: true,
        dwNotifyFilter: 0x19u,
        lpBytesReturned: nullptr,
        lpOverlapped: &v4->m_Overlapped,
        lpCompletionRoutine: nullptr);
    }
    else
    {
      v15 = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::FirstInorder(this: &v34);
      if ( v15 != -1 )
      {
        m_FullDirName = v33->m_FullDirName;
        do
        {
          key = v34.m_Elements.m_pMemory[v15].m_Data.key;
          V_ComposeFileName(path: m_FullDirName, filename: key, dest: v26, destSize: 260);
          v37->m_pCallbacks->OnFileChange(this: v37->m_pCallbacks, a2: key, a3: v26);
          v15 = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::NextInorder(
                  this: &v34,
                  i: v15);
        }
        while ( v15 != -1 );
        m_pMemory = v34.m_Elements.m_pMemory;
      }
      for ( k = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::FirstInorder(this: &v34);
            k != -1;
            k = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::NextInorder(
                  this: &v34,
                  i: k) )
      {
        free(pMem: (void *)m_pMemory[k].m_Data.key);
      }
      CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RemoveAll(this: &v34);
      ++i;
    }
    this = v37;
  }
  v41 = 5;
  for ( m = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::FirstInorder(this: &v34);
        m != -1;
        m = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::NextInorder(
              this: &v34,
              i: m) )
  {
    free(pMem: (void *)m_pMemory[m].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RemoveAll(this: &v34);
  v41 = 7;
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RemoveAll(this: &v34);
  m_nGrowSize = v34.m_Elements.m_nGrowSize;
  v21 = v34.m_Elements.m_pMemory;
  v34.m_FirstFree = -1;
  if ( v34.m_Elements.m_nGrowSize >= 0 )
  {
    if ( v34.m_Elements.m_pMemory != nullptr )
    {
      free(pMem: v34.m_Elements.m_pMemory);
      v21 = nullptr;
      v34.m_Elements.m_pMemory = nullptr;
    }
    v34.m_Elements.m_nAllocationCount = 0;
  }
  v34.m_LastAlloc.index = -1;
  v41 = -1;
  if ( m_nGrowSize >= 0 )
  {
    if ( v21 != nullptr )
    {
      free(pMem: v21);
      v34.m_Elements.m_pMemory = nullptr;
    }
    v34.m_Elements.m_nAllocationCount = 0;
  }
  return v36;
}
