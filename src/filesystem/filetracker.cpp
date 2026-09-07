// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: filesystem/filetracker.cpp
// Functions: 18
// ============================================================

#include "filesystem\filetracker.h"

//------------------------------------------------------------------------------
// Address: 0x10018520
// Name: private: unsigned long CFileTracker::CalculateCRCForFile(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CFileTracker::CalculateCRCForFile(CFileTracker *this, void *fp)
{
  unsigned int v4; // eax
  IBaseFileSystem *v5; // ecx
  unsigned int v6; // eax
  int v7; // esi
  unsigned int v8; // ecx
  unsigned int v9; // eax
  bool v10; // zf
  int v11; // eax
  _BYTE pBuffer[32768]; // [esp+Ch] [ebp-8014h] BYREF
  int nBuffer; // [esp+800Ch] [ebp-14h]
  int v15; // [esp+8010h] [ebp-10h]
  unsigned int v16; // [esp+8014h] [ebp-Ch]
  int v17; // [esp+8018h] [ebp-8h]
  unsigned int pulCRC; // [esp+801Ch] [ebp-4h] BYREF
  int i; // [esp+8028h] [ebp+8h]

  v4 = this->m_pFileSystem->Tell(this: &this->m_pFileSystem->IBaseFileSystem, a2: fp);
  v5 = &this->m_pFileSystem->IBaseFileSystem;
  v15 = v4;
  v5->Seek(this: v5, a2: fp, a3: 0, a4: FILESYSTEM_SEEK_HEAD);
  CRC32_Init(&pulCRC);
  v6 = this->m_pFileSystem->Size_2(this: &this->m_pFileSystem->IBaseFileSystem, a2: fp);
  v7 = (v6 >> 15) + 1;
  v16 = v6;
  v17 = 0;
  if ( v6 >> 15 != -1 )
  {
    v8 = 0x8000;
    for ( i = 0x8000; ; v8 = i )
    {
      if ( v8 < v6 )
        v6 = v8;
      v9 = v6 - v8;
      v10 = v9 == -32768;
      v11 = v9 + 0x8000;
      nBuffer = v11;
      if ( v10 )
        break;
      this->m_pFileSystem->Read(this: &this->m_pFileSystem->IBaseFileSystem, a2: pBuffer, a3: v11, a4: fp);
      CRC32_ProcessBuffer(&pulCRC, pBuffer, nBuffer);
      i += 0x8000;
      if ( ++v17 >= v7 )
        break;
      v6 = v16;
    }
  }
  CRC32_Final(&pulCRC);
  this->m_pFileSystem->Seek(this: &this->m_pFileSystem->IBaseFileSystem, a2: fp, a3: v15, a4: FILESYSTEM_SEEK_HEAD);
  return pulCRC;
}

//------------------------------------------------------------------------------
// Address: 0x1001A700
// Name: public: void CFileTracker::MarkAllCRCsVerified(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileTracker::MarkAllCRCsVerified(CFileTracker *this, bool bLockMutex)
{
  int m_Head; // eax
  UtlLinkedListElem_t<CFileInfo *,unsigned short> *m_pMemory; // ecx
  int v5; // eax
  UtlLinkedListElem_t<CFileInfo *,unsigned short> *v6; // ecx

  if ( bLockMutex )
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_Mutex);
  m_Head = this->m_NeedsVerificationList.m_Head;
  if ( m_Head != 0xFFFF )
  {
    m_pMemory = this->m_NeedsVerificationList.m_Memory.m_pMemory;
    do
    {
      v5 = (unsigned __int16)m_Head;
      m_pMemory[v5].m_Element->m_iNeedsVerificationListIndex = -1;
      m_pMemory = this->m_NeedsVerificationList.m_Memory.m_pMemory;
      m_Head = this->m_NeedsVerificationList.m_Memory.m_pMemory[v5].m_Next;
    }
    while ( m_Head != 0xFFFF );
  }
  CUtlLinkedList<CZip *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CZip *,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_NeedsVerificationList);
  if ( this->m_NeedsVerificationList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_NeedsVerificationList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_NeedsVerificationList.m_Memory.m_pMemory);
      this->m_NeedsVerificationList.m_Memory.m_pMemory = nullptr;
    }
    this->m_NeedsVerificationList.m_Memory.m_nAllocationCount = 0;
  }
  this->m_NeedsVerificationList.m_FirstFree = -1;
  v6 = this->m_NeedsVerificationList.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_NeedsVerificationList.m_NumAlloced = -65536;
  this->m_NeedsVerificationList.m_pElements = v6;
  if ( bLockMutex )
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_Mutex);
}

//------------------------------------------------------------------------------
// Address: 0x1001A990
// Name: public: int CFileTracker::GetUnverifiedCRCFiles(class CUnverifiedCRCFile __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileTracker::GetUnverifiedCRCFiles(CFileTracker *this, CUnverifiedCRCFile *pFiles, int nMaxFiles)
{
  _RTL_CRITICAL_SECTION *p_m_Mutex; // esi
  int m_Head; // ecx
  int v6; // ebx
  CFileInfo *m_Element; // esi
  bool v8; // zf
  const char *v9; // eax
  unsigned int m_CRC; // eax
  int v11; // esi
  int iNext; // [esp+Ch] [ebp-10h]
  _RTL_CRITICAL_SECTION *generated_id_6; // [esp+10h] [ebp-Ch]
  int iOutFile; // [esp+14h] [ebp-8h]
  unsigned __int16 i; // [esp+18h] [ebp-4h]
  unsigned int *pFilesa; // [esp+24h] [ebp+8h]

  p_m_Mutex = (_RTL_CRITICAL_SECTION *)&this->m_Mutex;
  generated_id_6 = (_RTL_CRITICAL_SECTION *)&this->m_Mutex;
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_Mutex);
  m_Head = this->m_NeedsVerificationList.m_Head;
  iOutFile = 0;
  i = this->m_NeedsVerificationList.m_Head;
  if ( m_Head == 0xFFFF )
  {
LABEL_8:
    LeaveCriticalSection(lpCriticalSection: p_m_Mutex);
    return iOutFile;
  }
  else
  {
    pFilesa = &pFiles->m_CRC;
    while ( 1 )
    {
      v6 = (unsigned __int16)m_Head;
      m_Element = this->m_NeedsVerificationList.m_Memory.m_pMemory[v6].m_Element;
      iNext = this->m_NeedsVerificationList.m_Memory.m_pMemory[v6].m_Next;
      CUtlLinkedList<CFileInfo *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFileInfo *,unsigned short>,unsigned short>>::Unlink(
        this: &this->m_NeedsVerificationList,
        elem: m_Head);
      this->m_NeedsVerificationList.m_Memory.m_pMemory[v6].m_Next = this->m_NeedsVerificationList.m_FirstFree;
      this->m_NeedsVerificationList.m_FirstFree = i;
      v8 = (m_Element->m_Flags & 1) == 0;
      m_Element->m_iNeedsVerificationListIndex = -1;
      if ( v8 )
      {
        V_strncpy(
          pDest: (char *)pFilesa - 260,
          pSrc: m_Element->m_pPathIDFileList->m_Files.m_Elements.m_Tree.m_Elements.m_pMemory[m_Element->m_PathIDFileListDictIndex].m_Data.key,
          maxLen: 260);
        v9 = CUtlSymbol::String(this: &m_Element->m_pPathIDFileList->m_PathID);
        V_strncpy(pDest: (char *)pFilesa - 520, pSrc: v9, maxLen: 260);
        m_CRC = m_Element->m_CRC;
        v11 = iOutFile + 1;
        *pFilesa = m_CRC;
        iOutFile = v11;
        pFilesa += 131;
        if ( v11 >= nMaxFiles )
          break;
      }
      i = iNext;
      if ( iNext == 0xFFFF )
      {
        p_m_Mutex = generated_id_6;
        goto LABEL_8;
      }
      LOWORD(m_Head) = iNext;
    }
    LeaveCriticalSection(lpCriticalSection: generated_id_6);
    return v11;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001AAF0
// Name: public: CFileTracker::CFileTracker(class CBaseFileSystem __near *)
// Source: json
//------------------------------------------------------------------------------
CFileTracker *__thiscall CFileTracker::CFileTracker(CFileTracker *this, CBaseFileSystem *pFileSystem)
{
  this->m_NeedsVerificationList.m_Memory.m_pMemory = nullptr;
  this->m_NeedsVerificationList.m_Memory.m_nAllocationCount = 0;
  this->m_NeedsVerificationList.m_Memory.m_nGrowSize = 0;
  this->m_NeedsVerificationList.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_NeedsVerificationList.m_FirstFree = 0xFFFF;
  this->m_NeedsVerificationList.m_pElements = this->m_NeedsVerificationList.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_NeedsVerificationList.m_Head = -1;
  this->m_NeedsVerificationList.m_NumAlloced = 0;
  this->m_PathIDs.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_PathIDs.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_PathIDs.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_PathIDs.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_PathIDs.m_Elements.m_Tree.m_Root = -1;
  this->m_PathIDs.m_Elements.m_Tree.m_NumElements = 0;
  this->m_PathIDs.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_PathIDs.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_PathIDs.m_Elements.m_Tree.m_pElements = this->m_PathIDs.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( this->m_PathIDs.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_PathIDs.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  CThreadMutex::CThreadMutex(this: &this->m_Mutex);
  this->m_pFileSystem = pFileSystem;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1001AB70
// Name: public: int CFileTracker::GetFileInfos(class CFileInfo __near * __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileTracker::GetFileInfos(
        CFileTracker *this,
        CFileInfo **ppFileInfos,
        int nMaxFileInfos,
        const char *pFilename)
{
  _RTL_CRITICAL_SECTION *p_m_Mutex; // edi
  int Inorder; // esi
  CPathIDFileList *elem; // edi
  int v8; // eax
  CFileInfo *v9; // eax
  int v10; // ecx
  CUtlMap<char const *,CFileInfo *,int>::Node_t search; // [esp+Ch] [ebp-10h] BYREF
  CAutoLockT<CThreadMutex> generated_id_2; // [esp+14h] [ebp-8h]
  int nOut; // [esp+18h] [ebp-4h]

  p_m_Mutex = (_RTL_CRITICAL_SECTION *)&this->m_Mutex;
  generated_id_2.m_lock = &this->m_Mutex;
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_Mutex);
  nOut = 0;
  Inorder = CUtlRBTree<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int,CUtlMap<char const *,CPathIDFileList *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_PathIDs.m_Elements.m_Tree);
  if ( Inorder != -1 )
  {
    do
    {
      elem = this->m_PathIDs.m_Elements.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.elem;
      if ( pFilename != nullptr )
      {
        search.key = pFilename;
        v8 = CUtlRBTree<CUtlMap<char const *,CFileInfo *,int>::Node_t,int,CUtlMap<char const *,CFileInfo *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CFileInfo *,int>::Node_t,int>,int>>::Find(
               this: &elem->m_Files.m_Elements.m_Tree,
               &search);
        if ( v8 != -1 )
        {
          v9 = elem->m_Files.m_Elements.m_Tree.m_Elements.m_pMemory[v8].m_Data.elem;
          if ( v9 != nullptr )
          {
            v10 = nOut;
            if ( nOut < nMaxFileInfos )
            {
              ppFileInfos[nOut] = v9;
              nOut = v10 + 1;
            }
          }
        }
      }
      Inorder = CUtlRBTree<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int,CUtlMap<char const *,CPathIDFileList *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int>,int>>::NextInorder(
                  this: &this->m_PathIDs.m_Elements.m_Tree,
                  i: Inorder);
    }
    while ( Inorder != -1 );
    p_m_Mutex = (_RTL_CRITICAL_SECTION *)generated_id_2.m_lock;
  }
  LeaveCriticalSection(lpCriticalSection: p_m_Mutex);
  return nOut;
}

//------------------------------------------------------------------------------
// Address: 0x1001AC10
// Name: public: void CFileTracker::MarkAllCRCsUnverified(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileTracker::MarkAllCRCsUnverified(CFileTracker *this)
{
  _RTL_CRITICAL_SECTION *p_m_Mutex; // edi
  int Inorder; // eax
  CPathIDFileList *elem; // edi
  int v5; // ebx
  unsigned __int16 v6; // ax
  int v7; // edi
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CFileInfo *,unsigned short> *m_pMemory; // eax
  int v10; // ecx
  int m_Tail; // edx
  UtlLinkedListElem_t<CFileInfo *,unsigned short> *v12; // eax
  UtlLinkedListElem_t<CFileInfo *,unsigned short> *v13; // eax
  CThreadMutex *generated_id_5; // [esp+8h] [ebp-14h]
  CPathIDFileList *pPath; // [esp+Ch] [ebp-10h]
  int j; // [esp+10h] [ebp-Ch]
  CFileInfo *pInfo; // [esp+14h] [ebp-8h]
  int i; // [esp+18h] [ebp-4h]

  p_m_Mutex = (_RTL_CRITICAL_SECTION *)&this->m_Mutex;
  generated_id_5 = &this->m_Mutex;
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_Mutex);
  CFileTracker::MarkAllCRCsVerified(this, bLockMutex: true);
  Inorder = CUtlRBTree<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int,CUtlMap<char const *,CPathIDFileList *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_PathIDs.m_Elements.m_Tree);
  i = Inorder;
  if ( Inorder != -1 )
  {
    while ( 1 )
    {
      elem = this->m_PathIDs.m_Elements.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.elem;
      pPath = elem;
      v5 = CUtlRBTree<CUtlMap<char const *,CFileInfo *,int>::Node_t,int,CUtlMap<char const *,CFileInfo *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CFileInfo *,int>::Node_t,int>,int>>::FirstInorder(this: &elem->m_Files.m_Elements.m_Tree);
      for ( j = v5; v5 != -1; j = v5 )
      {
        pInfo = elem->m_Files.m_Elements.m_Tree.m_Elements.m_pMemory[v5].m_Data.elem;
        if ( (pInfo->m_Flags & 1) == 0 && (pInfo->m_Flags & 2) != 0 )
        {
          v6 = CUtlLinkedList<CFileInfo *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFileInfo *,unsigned short>,unsigned short>>::AllocInternal(
                 this: &this->m_NeedsVerificationList,
                 multilist: false);
          v7 = v6;
          if ( v6 == 0xFFFF )
          {
            v8 = -1;
          }
          else
          {
            CUtlLinkedList<CFileInfo *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFileInfo *,unsigned short>,unsigned short>>::Unlink(
              this: &this->m_NeedsVerificationList,
              elem: v6);
            m_pMemory = this->m_NeedsVerificationList.m_Memory.m_pMemory;
            v10 = v7;
            m_pMemory[v10].m_Next = -1;
            m_Tail = this->m_NeedsVerificationList.m_Tail;
            m_pMemory[v10].m_Previous = m_Tail;
            this->m_NeedsVerificationList.m_Tail = v7;
            if ( (_WORD)m_Tail == 0xFFFF )
              this->m_NeedsVerificationList.m_Head = v7;
            else
              this->m_NeedsVerificationList.m_Memory.m_pMemory[m_Tail].m_Next = v7;
            v12 = this->m_NeedsVerificationList.m_Memory.m_pMemory;
            ++this->m_NeedsVerificationList.m_ElementCount;
            v13 = &v12[v10];
            if ( v13 != nullptr )
              v13->m_Element = pInfo;
            v5 = j;
            v8 = v7;
          }
          elem = pPath;
          pInfo->m_iNeedsVerificationListIndex = v8;
        }
        v5 = CUtlRBTree<CUtlMap<char const *,CFileInfo *,int>::Node_t,int,CUtlMap<char const *,CFileInfo *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CFileInfo *,int>::Node_t,int>,int>>::NextInorder(
               this: &elem->m_Files.m_Elements.m_Tree,
               i: v5);
      }
      i = CUtlRBTree<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int,CUtlMap<char const *,CPathIDFileList *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int>,int>>::NextInorder(
            this: &this->m_PathIDs.m_Elements.m_Tree,
            i);
      if ( i == -1 )
        break;
      Inorder = i;
    }
    p_m_Mutex = (_RTL_CRITICAL_SECTION *)generated_id_5;
  }
  LeaveCriticalSection(lpCriticalSection: p_m_Mutex);
}

//------------------------------------------------------------------------------
// Address: 0x1001AD50
// Name: public: CPathIDFileList::CPathIDFileList(void)
// Source: json
//------------------------------------------------------------------------------
CPathIDFileList *__thiscall CPathIDFileList::CPathIDFileList(CPathIDFileList *this)
{
  CPathIDFileList *result; // eax
  UtlLinkedListElem_t<CFileInfo *,int> *m_pMemory; // edx

  result = this;
  this->m_PathID.m_Id = -1;
  this->m_Files.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_Files.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_Files.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_Files.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_Files.m_Elements.m_Tree.m_Root = -1;
  this->m_Files.m_Elements.m_Tree.m_NumElements = 0;
  this->m_Files.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_Files.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_Files.m_Elements.m_Tree.m_pElements = this->m_Files.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( this->m_Files.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_Files.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThanIgnoreSlashes;
  this->m_UnverifiedCRCFiles.m_Memory.m_pMemory = nullptr;
  this->m_UnverifiedCRCFiles.m_Memory.m_nAllocationCount = 0;
  this->m_UnverifiedCRCFiles.m_Memory.m_nGrowSize = 0;
  this->m_UnverifiedCRCFiles.m_LastAlloc.index = -1;
  this->m_UnverifiedCRCFiles.m_Head = -1;
  this->m_UnverifiedCRCFiles.m_Tail = -1;
  this->m_UnverifiedCRCFiles.m_FirstFree = -1;
  m_pMemory = this->m_UnverifiedCRCFiles.m_Memory.m_pMemory;
  this->m_UnverifiedCRCFiles.m_ElementCount = 0;
  this->m_UnverifiedCRCFiles.m_NumAlloced = 0;
  this->m_UnverifiedCRCFiles.m_pElements = m_pMemory;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001B0D0
// Name: private: class CPathIDFileList __near * CFileTracker::GetPathIDFileList(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CPathIDFileList *__thiscall CFileTracker::GetPathIDFileList(CFileTracker *this, CPathIDFileList *pPathID, int bAutoAdd)
{
  _RTL_CRITICAL_SECTION *p_m_Mutex; // ebx
  char *v5; // edi
  int v6; // eax
  CPathIDFileList *v7; // eax
  char *v8; // esi
  CPathIDFileList *elem; // esi
  CUtlMap<char const *,CPathIDFileList *,int>::Node_t search; // [esp+Ch] [ebp-Ch] BYREF
  CUtlDict<CPathIDFileList *,int> *p_m_PathIDs; // [esp+14h] [ebp-4h]

  p_m_Mutex = (_RTL_CRITICAL_SECTION *)&this->m_Mutex;
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_Mutex);
  v5 = (char *)pPathID;
  if ( pPathID == nullptr )
    v5 = (char *)setName;
  search.key = v5;
  p_m_PathIDs = &this->m_PathIDs;
  v6 = CUtlRBTree<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int,CUtlMap<char const *,CPathIDFileList *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int>,int>>::Find(
         this: &this->m_PathIDs.m_Elements.m_Tree,
         &search);
  if ( v6 == -1 )
  {
    if ( (_BYTE)bAutoAdd != 0 )
    {
      v7 = (CPathIDFileList *)operator new(nSize: 0x50u);
      if ( v7 != nullptr )
        v8 = (char *)CPathIDFileList::CPathIDFileList(this: v7);
      else
        v8 = nullptr;
      pPathID = (CPathIDFileList *)v8;
      CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&bAutoAdd + 1, pStr: v5);
      *(_WORD *)v8 = HIWORD(bAutoAdd);
      CUtlDict<CPathIDFileList *,int>::Insert(this: p_m_PathIDs, pName: v5, element: &pPathID);
      LeaveCriticalSection(lpCriticalSection: p_m_Mutex);
      return (CPathIDFileList *)v8;
    }
    else
    {
      LeaveCriticalSection(lpCriticalSection: p_m_Mutex);
      return nullptr;
    }
  }
  else
  {
    elem = this->m_PathIDs.m_Elements.m_Tree.m_Elements.m_pMemory[v6].m_Data.elem;
    LeaveCriticalSection(lpCriticalSection: p_m_Mutex);
    return elem;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001B190
// Name: public: CFileTracker::~CFileTracker(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileTracker::~CFileTracker(CFileTracker *this)
{
  _RTL_CRITICAL_SECTION *p_m_Mutex; // edi

  p_m_Mutex = (_RTL_CRITICAL_SECTION *)&this->m_Mutex;
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_Mutex);
  CUtlDict<CPathIDFileList *,int>::PurgeAndDeleteElements(this: &this->m_PathIDs);
  LeaveCriticalSection(lpCriticalSection: p_m_Mutex);
  CThreadMutex::~CThreadMutex(this: (CThreadMutex *)p_m_Mutex);
  CUtlDict<CPathIDFileList *,int>::RemoveAll(this: &this->m_PathIDs);
  CUtlRBTree<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int,CUtlMap<char const *,CPathIDFileList *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int,CUtlMap<char const *,CPathIDFileList *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int>,int>>(this: &this->m_PathIDs.m_Elements.m_Tree);
  CUtlLinkedList<CZip *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CZip *,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_NeedsVerificationList);
  if ( this->m_NeedsVerificationList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_NeedsVerificationList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_NeedsVerificationList.m_Memory.m_pMemory);
      this->m_NeedsVerificationList.m_Memory.m_pMemory = nullptr;
    }
    this->m_NeedsVerificationList.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001B200
// Name: public: void CFileTracker::NoteFileLoadedFromDisk(char const __near *,char const __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileTracker::NoteFileLoadedFromDisk(CFileTracker *this, char *pFilename, char *pPathID, void *fp)
{
  char *v5; // esi
  CPathIDFileList *PathIDFileList; // ebx
  const char *v7; // eax
  int v8; // eax
  CFileInfo *elem; // ebx
  char *v10; // eax
  char *v11; // esi
  CUtlDict<CFileInfo *,int> *p_m_Files; // ecx
  unsigned int v13; // eax
  bool v14; // zf
  unsigned __int16 v15; // ax
  int v16; // esi
  unsigned __int16 v17; // ax
  UtlLinkedListElem_t<CFileInfo *,unsigned short> *v18; // eax
  CUtlMap<char const *,CFileInfo *,int>::Node_t search; // [esp+Ch] [ebp-10h] BYREF
  CPathIDFileList *pPath; // [esp+14h] [ebp-8h]
  CAutoLockT<CThreadMutex> generated_id_0; // [esp+18h] [ebp-4h]

  generated_id_0.m_lock = &this->m_Mutex;
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_Mutex);
  v5 = pPathID;
  if ( pPathID == nullptr )
    v5 = (char *)setName;
  PathIDFileList = CFileTracker::GetPathIDFileList(this, pPathID: (CPathIDFileList *)v5, bAutoAdd: 1);
  v7 = pFilename;
  pPath = PathIDFileList;
  if ( pFilename == nullptr )
    goto LABEL_6;
  search.key = pFilename;
  v8 = CUtlRBTree<CUtlMap<char const *,CFileInfo *,int>::Node_t,int,CUtlMap<char const *,CFileInfo *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CFileInfo *,int>::Node_t,int>,int>>::Find(
         this: &PathIDFileList->m_Files.m_Elements.m_Tree,
         &search);
  if ( v8 == -1 )
  {
    v7 = pFilename;
LABEL_6:
    elem = nullptr;
    goto LABEL_8;
  }
  elem = PathIDFileList->m_Files.m_Elements.m_Tree.m_Elements.m_pMemory[v8].m_Data.elem;
  v7 = pFilename;
LABEL_8:
  if ( (this->m_pFileSystem->m_WhitelistSpewFlags & 1) != 0 )
  {
    if ( elem == nullptr )
    {
      _Warning(a1: "(Unique   ): [%s]\\%s", v5, v7);
      goto LABEL_14;
    }
    _Warning(a1: "(Duplicate): [%s]\\%s", v5, v7);
  }
  if ( elem != nullptr )
  {
    elem->m_Flags &= 8u;
    goto LABEL_18;
  }
LABEL_14:
  v10 = (char *)operator new(nSize: 0x14u);
  if ( v10 != nullptr )
  {
    *((_DWORD *)v10 + 4) = -1;
    v11 = v10;
  }
  else
  {
    v11 = nullptr;
  }
  p_m_Files = &pPath->m_Files;
  pPathID = v11;
  *((_DWORD *)v11 + 2) = pPath;
  *((_DWORD *)v11 + 3) = CUtlDict<CFileInfo *,int>::Insert(
                           this: p_m_Files,
                           pName: pFilename,
                           element: (CFileInfo *const *)&pPathID);
  elem = (CFileInfo *)v11;
  *(_WORD *)v11 = 0;
LABEL_18:
  if ( fp != nullptr )
  {
    v13 = CFileTracker::CalculateCRCForFile(this, fp);
    elem->m_Flags |= 0xAu;
    v14 = elem->m_iNeedsVerificationListIndex == -1;
    elem->m_CRC = v13;
    if ( v14 )
    {
      v15 = CUtlLinkedList<CFileInfo *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFileInfo *,unsigned short>,unsigned short>>::AllocInternal(
              this: &this->m_NeedsVerificationList,
              multilist: false);
      v16 = v15;
      if ( v15 == 0xFFFF )
      {
        v17 = -1;
      }
      else
      {
        CUtlLinkedList<CZip *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CZip *,unsigned short>,unsigned short>>::LinkBefore(
          this: &this->m_NeedsVerificationList,
          before: 0xFFFFu,
          elem: v15);
        v18 = &this->m_NeedsVerificationList.m_Memory.m_pMemory[v16];
        if ( v18 != nullptr )
          v18->m_Element = elem;
        v17 = v16;
      }
      elem->m_iNeedsVerificationListIndex = v17;
    }
    if ( (this->m_pFileSystem->m_WhitelistSpewFlags & 1) != 0 )
      _Warning(a1: " - %lu\n", elem->m_CRC);
  }
  else if ( (this->m_pFileSystem->m_WhitelistSpewFlags & 1) != 0 )
  {
    _Warning(a1: "\n");
  }
  LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)generated_id_0.m_lock);
}

//------------------------------------------------------------------------------
// Address: 0x1001B390
// Name: public: void CFileTracker::NoteFileFailedToLoad(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileTracker::NoteFileFailedToLoad(CFileTracker *this, const char *pFilename, CPathIDFileList *pPathID)
{
  CPathIDFileList *PathIDFileList; // esi
  int v4; // eax
  CFileInfo *elem; // eax
  CUtlMap<char const *,CFileInfo *,int>::Node_t search; // [esp+4h] [ebp-8h] BYREF

  PathIDFileList = CFileTracker::GetPathIDFileList(this, pPathID, bAutoAdd: 1);
  if ( pFilename != nullptr )
  {
    search.key = pFilename;
    v4 = CUtlRBTree<CUtlMap<char const *,CFileInfo *,int>::Node_t,int,CUtlMap<char const *,CFileInfo *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CFileInfo *,int>::Node_t,int>,int>>::Find(
           this: &PathIDFileList->m_Files.m_Elements.m_Tree,
           &search);
    if ( v4 != -1 )
    {
      elem = PathIDFileList->m_Files.m_Elements.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem;
      if ( elem != nullptr )
        elem->m_Flags |= 0x10u;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001B3E0
// Name: public: class CFileInfo __near * CFileTracker::GetFileInfo(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CFileInfo *__thiscall CFileTracker::GetFileInfo(CFileTracker *this, const char *pFilename, CPathIDFileList *pPathID)
{
  _RTL_CRITICAL_SECTION *p_m_Mutex; // esi
  const char *elem; // eax
  int v6; // eax
  CPathIDFileList *v8; // edi
  int v9; // eax
  CFileInfo *v10; // edi
  CUtlMap<char const *,CPathIDFileList *,int>::Node_t search; // [esp+Ch] [ebp-8h] BYREF

  p_m_Mutex = (_RTL_CRITICAL_SECTION *)&this->m_Mutex;
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_Mutex);
  search.elem = pPathID;
  EnterCriticalSection(lpCriticalSection: p_m_Mutex);
  elem = setName;
  if ( pPathID != nullptr )
    elem = (const char *)search.elem;
  search.key = elem;
  v6 = CUtlRBTree<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int,CUtlMap<char const *,CPathIDFileList *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int>,int>>::Find(
         this: &this->m_PathIDs.m_Elements.m_Tree,
         &search);
  if ( v6 == -1 )
  {
    LeaveCriticalSection(lpCriticalSection: p_m_Mutex);
    LeaveCriticalSection(lpCriticalSection: p_m_Mutex);
    return nullptr;
  }
  else
  {
    v8 = this->m_PathIDs.m_Elements.m_Tree.m_Elements.m_pMemory[v6].m_Data.elem;
    LeaveCriticalSection(lpCriticalSection: p_m_Mutex);
    if ( v8 != nullptr
      && pFilename != nullptr
      && (search.key = pFilename,
          (v9 = CUtlRBTree<CUtlMap<char const *,CFileInfo *,int>::Node_t,int,CUtlMap<char const *,CFileInfo *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CFileInfo *,int>::Node_t,int>,int>>::Find(
                  this: &v8->m_Files.m_Elements.m_Tree,
                  (const CUtlMap<char const *,CFileInfo *,int>::Node_t *)&search)) != -1) )
    {
      v10 = v8->m_Files.m_Elements.m_Tree.m_Elements.m_pMemory[v9].m_Data.elem;
      LeaveCriticalSection(lpCriticalSection: p_m_Mutex);
      return v10;
    }
    else
    {
      LeaveCriticalSection(lpCriticalSection: p_m_Mutex);
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001B4A0
// Name: public: void CFileTracker::NoteFileLoadedFromSteam(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileTracker::NoteFileLoadedFromSteam(
        CFileTracker *this,
        char *pFilename,
        char *pPathID,
        bool bForcedLoadFromSteam)
{
  CPathIDFileList *PathIDFileList; // eax
  char *v6; // ebx
  CPathIDFileList *v7; // esi
  int v8; // eax
  char *elem; // edi
  char *v10; // eax
  bool v11; // zf
  CUtlMap<char const *,CFileInfo *,int>::Node_t search; // [esp+Ch] [ebp-10h] BYREF
  CAutoLockT<CThreadMutex> generated_id_3; // [esp+14h] [ebp-8h]
  CFileTracker *v14; // [esp+18h] [ebp-4h]

  v14 = this;
  generated_id_3.m_lock = &this->m_Mutex;
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_Mutex);
  if ( pPathID == nullptr )
    pPathID = (char *)setName;
  PathIDFileList = CFileTracker::GetPathIDFileList(this, (CPathIDFileList *)pPathID, bAutoAdd: 1);
  v6 = pFilename;
  v7 = PathIDFileList;
  if ( pFilename == nullptr
    || (search.key = pFilename,
        (v8 = CUtlRBTree<CUtlMap<char const *,CFileInfo *,int>::Node_t,int,CUtlMap<char const *,CFileInfo *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CFileInfo *,int>::Node_t,int>,int>>::Find(
                this: &PathIDFileList->m_Files.m_Elements.m_Tree,
                &search)) == -1)
    || (elem = (char *)v7->m_Files.m_Elements.m_Tree.m_Elements.m_pMemory[v8].m_Data.elem) == nullptr )
  {
    v10 = (char *)operator new(nSize: 0x14u);
    if ( v10 != nullptr )
    {
      *((_DWORD *)v10 + 4) = -1;
      elem = v10;
    }
    else
    {
      elem = nullptr;
    }
    pFilename = elem;
    *((_DWORD *)elem + 2) = v7;
    *((_DWORD *)elem + 3) = CUtlDict<CFileInfo *,int>::Insert(
                              this: &v7->m_Files,
                              pName: v6,
                              element: (CFileInfo *const *)&pFilename);
  }
  if ( (v14->m_pFileSystem->m_WhitelistSpewFlags & 1) != 0 )
    _Warning(a1: "From Steam: [%s]\\%s\n", pPathID, v6);
  v11 = !bForcedLoadFromSteam;
  *(_WORD *)elem = 1;
  if ( !v11 )
    *(_WORD *)elem = 5;
  LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)generated_id_3.m_lock);
}

//------------------------------------------------------------------------------
// Address: 0x1001B580
// Name: public: enum EFileCRCStatus CFileTracker::CheckCachedFileCRC(char const __near *,char const __near *,unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileTracker::CheckCachedFileCRC(
        CFileTracker *this,
        CPathIDFileList *pPathID,
        const char *pRelativeFilename,
        unsigned int *pCRC)
{
  CFileInfo *FileInfo; // eax

  FileInfo = CFileTracker::GetFileInfo(this, pFilename: pRelativeFilename, pPathID);
  if ( FileInfo == nullptr || (FileInfo->m_Flags & 8) == 0 )
    return 0;
  *pCRC = FileInfo->m_CRC;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1001B5B0
// Name: private: void CFileTracker::CalculateMissingCRC(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileTracker::CalculateMissingCRC(CFileTracker *this, const char *pFilename, CPathIDFileList *pPathID)
{
  CFileHandle *v3; // ebx
  CFileInfo *FileInfo; // eax
  CFileInfo *v6; // esi
  CFileHandle *FileInSearchPaths; // ebx
  int nOldFlags; // [esp+Ch] [ebp-4h]

  v3 = (CFileHandle *)pPathID;
  nOldFlags = -1;
  FileInfo = CFileTracker::GetFileInfo(this, pFilename, pPathID);
  v6 = FileInfo;
  pPathID = (CPathIDFileList *)FileInfo;
  if ( FileInfo != nullptr )
    nOldFlags = FileInfo->m_Flags;
  FileInSearchPaths = CBaseFileSystem::FindFileInSearchPaths(
                        this: this->m_pFileSystem,
                        pFileName: pFilename,
                        pOptions: "rb",
                        pathID: v3,
                        flags: 2u,
                        ppszResolvedFilename: nullptr,
                        bTrackCRCs: true);
  if ( FileInSearchPaths != nullptr )
  {
    if ( v6 != nullptr )
    {
      if ( nOldFlags != -1 )
        v6->m_Flags = nOldFlags;
      EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_Mutex);
      if ( (v6->m_Flags & 2) == 0 )
      {
        v6->m_CRC = CFileTracker::CalculateCRCForFile(this, fp: FileInSearchPaths);
        v6->m_Flags |= 0xAu;
        if ( v6->m_iNeedsVerificationListIndex == -1 )
          v6->m_iNeedsVerificationListIndex = (unsigned __int16)CUtlLinkedList<CFileInfo *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFileInfo *,unsigned short>,unsigned short>>::AddToTail(
                                                                  this: &this->m_NeedsVerificationList,
                                                                  src: (CFileInfo **)&pPathID);
      }
      LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_Mutex);
    }
    this->m_pFileSystem->Close(this: &this->m_pFileSystem->IBaseFileSystem, a2: FileInSearchPaths);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001B660
// Name: public: void CFileTracker::CalculateMissingCRCs(class IFileList __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileTracker::CalculateMissingCRCs(CFileTracker *this, IFileList *pWantCRCList)
{
  CFileTracker *v2; // ebx
  int m_Head; // edi
  int Inorder; // eax
  int v5; // edi
  CFileInfo *elem; // ebx
  int v7; // eax
  int v8; // esi
  UtlLinkedListElem_t<CFileInfo *,int> *m_pMemory; // edx
  UtlLinkedListElem_t<CFileInfo *,int> *v10; // eax
  int m_Tail; // ecx
  int j; // eax
  int v13; // eax
  CFileInfo *m_Element; // esi
  UtlLinkedListElem_t<CFileInfo *,int> *v15; // edi
  CPathIDFileList *v16; // eax
  CUtlLinkedList<CFileInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileInfo *,int>,int> > needCRCList; // [esp+Ch] [ebp-34h] BYREF
  CFileTracker *v18; // [esp+34h] [ebp-Ch]
  CPathIDFileList *pPath; // [esp+38h] [ebp-8h]
  int i; // [esp+3Ch] [ebp-4h]

  v2 = this;
  v18 = this;
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_Mutex);
  m_Head = -1;
  memset(&needCRCList, 0, 12);
  needCRCList.m_LastAlloc.index = -1;
  memset(&needCRCList.m_Head, 255, 12);
  needCRCList.m_ElementCount = 0;
  needCRCList.m_NumAlloced = 0;
  needCRCList.m_pElements = nullptr;
  Inorder = CUtlRBTree<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int,CUtlMap<char const *,CPathIDFileList *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int>,int>>::FirstInorder(this: &v2->m_PathIDs.m_Elements.m_Tree);
  i = Inorder;
  if ( Inorder != -1 )
  {
    while ( 1 )
    {
      pPath = v2->m_PathIDs.m_Elements.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.elem;
      v5 = CUtlRBTree<CUtlMap<char const *,CFileInfo *,int>::Node_t,int,CUtlMap<char const *,CFileInfo *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CFileInfo *,int>::Node_t,int>,int>>::FirstInorder(this: &pPath->m_Files.m_Elements.m_Tree);
      if ( v5 != -1 )
      {
        do
        {
          elem = pPath->m_Files.m_Elements.m_Tree.m_Elements.m_pMemory[v5].m_Data.elem;
          if ( (elem->m_Flags & 3) == 0
            && pWantCRCList->IsFileInList(
                 this: pWantCRCList,
                 a2: elem->m_pPathIDFileList->m_Files.m_Elements.m_Tree.m_Elements.m_pMemory[elem->m_PathIDFileListDictIndex].m_Data.key) != 0 )
          {
            v7 = CUtlLinkedList<CFileInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileInfo *,int>,int>>::AllocInternal(
                   this: &needCRCList,
                   multilist: false);
            v8 = v7;
            if ( v7 != -1 )
            {
              CUtlLinkedList<CFileInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileInfo *,int>,int>>::Unlink(
                this: &needCRCList,
                elem: v7);
              m_pMemory = needCRCList.m_Memory.m_pMemory;
              v10 = &needCRCList.m_Memory.m_pMemory[v8];
              m_Tail = needCRCList.m_Tail;
              v10->m_Next = -1;
              v10->m_Previous = m_Tail;
              needCRCList.m_Tail = v8;
              if ( m_Tail == -1 )
                needCRCList.m_Head = v8;
              else
                m_pMemory[m_Tail].m_Next = v8;
              ++needCRCList.m_ElementCount;
              if ( v10 != nullptr )
                v10->m_Element = elem;
            }
          }
          v5 = CUtlRBTree<CUtlMap<char const *,CFileInfo *,int>::Node_t,int,CUtlMap<char const *,CFileInfo *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CFileInfo *,int>::Node_t,int>,int>>::NextInorder(
                 this: &pPath->m_Files.m_Elements.m_Tree,
                 i: v5);
        }
        while ( v5 != -1 );
        v2 = v18;
      }
      i = CUtlRBTree<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int,CUtlMap<char const *,CPathIDFileList *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int>,int>>::NextInorder(
            this: &v2->m_PathIDs.m_Elements.m_Tree,
            i);
      if ( i == -1 )
        break;
      Inorder = i;
    }
    m_Head = needCRCList.m_Head;
  }
  LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&v2->m_Mutex);
  for ( j = m_Head; j != -1; j = v15->m_Next )
  {
    v13 = j;
    m_Element = needCRCList.m_Memory.m_pMemory[v13].m_Element;
    v15 = &needCRCList.m_Memory.m_pMemory[v13];
    v16 = (CPathIDFileList *)CUtlSymbol::String(this: &m_Element->m_pPathIDFileList->m_PathID);
    CFileTracker::CalculateMissingCRC(
      this: v2,
      pFilename: m_Element->m_pPathIDFileList->m_Files.m_Elements.m_Tree.m_Elements.m_pMemory[m_Element->m_PathIDFileListDictIndex].m_Data.key,
      pPathID: v16);
  }
  CUtlLinkedList<CFileInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileInfo *,int>,int>>::RemoveAll(this: &needCRCList);
  if ( needCRCList.m_Memory.m_nGrowSize >= 0 && needCRCList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: needCRCList.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1001B810
// Name: public: void CFileTracker::CacheFileCRC(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileTracker::CacheFileCRC(CFileTracker *this, CPathIDFileList *pPathID, const char *pRelativeFilename)
{
  CFileInfo *FileInfo; // esi
  CPathIDFileList *v5; // eax

  FileInfo = CFileTracker::GetFileInfo(this, pFilename: pRelativeFilename, pPathID);
  if ( FileInfo != nullptr
    || (CFileTracker::CalculateMissingCRC(this, pFilename: pRelativeFilename, pPathID),
        (FileInfo = CFileTracker::GetFileInfo(this, pFilename: pRelativeFilename, pPathID)) != nullptr) )
  {
    if ( (FileInfo->m_Flags & 8) == 0 )
    {
      v5 = (CPathIDFileList *)CUtlSymbol::String(this: &FileInfo->m_pPathIDFileList->m_PathID);
      CFileTracker::CalculateMissingCRC(
        this,
        pFilename: FileInfo->m_pPathIDFileList->m_Files.m_Elements.m_Tree.m_Elements.m_pMemory[FileInfo->m_PathIDFileListDictIndex].m_Data.key,
        pPathID: v5);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001B880
// Name: public: void CFileTracker::CacheFileCRC_Copy(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileTracker::CacheFileCRC_Copy(
        CFileTracker *this,
        CPathIDFileList *pPathID,
        CFileInfo *pRelativeFilename,
        CPathIDFileList *pPathIDToCopyFrom)
{
  CPathIDFileList *v5; // edi
  CFileInfo *FileInfo; // eax
  CFileInfo *v8; // edi
  CPathIDFileList *v9; // edi
  CPathIDFileList *v10; // eax
  CPathIDFileList *PathIDFileList; // eax
  CPathIDFileList *v12; // esi
  int v13; // eax
  _DWORD *p_m_Id; // eax
  CPathIDFileList *v15; // eax
  CPathIDFileList *v16; // edi
  CUtlMap<char const *,CFileInfo *,int>::Node_t search; // [esp+Ch] [ebp-8h] BYREF
  CFileInfo *pSourceInfo; // [esp+20h] [ebp+Ch]

  v5 = pPathIDToCopyFrom;
  FileInfo = CFileTracker::GetFileInfo(this, pFilename: (const char *)pRelativeFilename, pPathID: pPathIDToCopyFrom);
  pSourceInfo = FileInfo;
  if ( FileInfo != nullptr && (FileInfo->m_Flags & 8) != 0 )
    goto LABEL_9;
  v8 = CFileTracker::GetFileInfo(this, pFilename: (const char *)pRelativeFilename, pPathID: v5);
  if ( v8 != nullptr
    || (v9 = pPathIDToCopyFrom,
        CFileTracker::CalculateMissingCRC(this, pFilename: (const char *)pRelativeFilename, pPathID: pPathIDToCopyFrom),
        (v8 = CFileTracker::GetFileInfo(this, pFilename: (const char *)pRelativeFilename, pPathID: v9)) != nullptr) )
  {
    if ( (v8->m_Flags & 8) == 0 )
    {
      v10 = (CPathIDFileList *)CUtlSymbol::String(this: &v8->m_pPathIDFileList->m_PathID);
      CFileTracker::CalculateMissingCRC(
        this,
        pFilename: v8->m_pPathIDFileList->m_Files.m_Elements.m_Tree.m_Elements.m_pMemory[v8->m_PathIDFileListDictIndex].m_Data.key,
        pPathID: v10);
    }
  }
  if ( (pSourceInfo->m_Flags & 8) != 0 )
  {
LABEL_9:
    PathIDFileList = CFileTracker::GetPathIDFileList(this, pPathID, bAutoAdd: 1);
    v12 = PathIDFileList;
    if ( pRelativeFilename == nullptr
      || (search.key = (const char *)pRelativeFilename,
          (v13 = CUtlRBTree<CUtlMap<char const *,CFileInfo *,int>::Node_t,int,CUtlMap<char const *,CFileInfo *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CFileInfo *,int>::Node_t,int>,int>>::Find(
                   this: &PathIDFileList->m_Files.m_Elements.m_Tree,
                   &search)) == -1)
      || (p_m_Id = &v12->m_Files.m_Elements.m_Tree.m_Elements.m_pMemory[v13].m_Data.elem->m_Flags) == nullptr )
    {
      v15 = (CPathIDFileList *)operator new(nSize: 0x14u);
      if ( v15 != nullptr )
      {
        v15->m_Files.m_Elements.m_Tree.m_Elements.m_nGrowSize = -1;
        v16 = v15;
      }
      else
      {
        v16 = nullptr;
      }
      pPathIDToCopyFrom = v16;
      v16->m_Files.m_Elements.m_Tree.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,CFileInfo *,int>::Node_t,int> *)v12;
      v16->m_Files.m_Elements.m_Tree.m_Elements.m_nAllocationCount = CUtlDict<CFileInfo *,int>::Insert(
                                                                       this: &v12->m_Files,
                                                                       pName: (char *)pRelativeFilename,
                                                                       element: (CFileInfo *const *)&pPathIDToCopyFrom);
      p_m_Id = &v16->m_PathID.m_Id;
    }
    p_m_Id[1] = pSourceInfo->m_CRC;
    *(_WORD *)p_m_Id = pSourceInfo->m_Flags;
  }
  else
  {
    CFileTracker::CacheFileCRC(this, pPathID, (const char *)pRelativeFilename);
  }
}

// ============================================================
// Overlay from dedicated (Missing functions)
// ============================================================
namespace dedicated {

//------------------------------------------------------------------------------
// Address: 0x1000EF30
// Name: public: void CUtlDict<class CUtlVector<class CStoreIDEntry,class CUtlMemory<class CStoreIDEntry,int>> __near *,int>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int>> *,int>::PurgeAndDeleteElements(
        CUtlDict<CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int> > *,int> *this)
{
  int i; // edi
  CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int> > *elem; // esi
  bool v4; // sf
  CStoreIDEntry *m_pMemory; // eax

  for ( i = CUtlRBTree<CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int>> *,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int>> *,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
    elem = this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.elem;
    if ( elem != nullptr )
    {
      v4 = elem->m_Memory.m_nGrowSize < 0;
      elem->m_Size = 0;
      if ( !v4 )
      {
        if ( elem->m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: elem->m_Memory.m_pMemory);
          elem->m_Memory.m_pMemory = nullptr;
        }
        elem->m_Memory.m_nAllocationCount = 0;
      }
      v4 = elem->m_Memory.m_nGrowSize < 0;
      m_pMemory = elem->m_Memory.m_pMemory;
      elem->m_pElements = elem->m_Memory.m_pMemory;
      if ( !v4 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          elem->m_Memory.m_pMemory = nullptr;
        }
        elem->m_Memory.m_nAllocationCount = 0;
      }
      free(pMem: elem);
    }
  }
  CUtlRBTree<CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int>> *,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x1000FD70
// Name: public: int CUtlMap<char const __near *,class CUtlVector<class CStoreIDEntry,class CUtlMemory<class CStoreIDEntry,int>> __near *,int>::Insert(char const __near * const __near &,class CUtlVector<class CStoreIDEntry,class CUtlMemory<class CStoreIDEntry,int>> __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int>> *,int>::Insert(
        CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int> > *,int> *this,
        const char **key,
        int insert)
{
  CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int> > *v4; // eax
  int v5; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int> > *,int>::Node_t,int> *m_pMemory; // ecx
  CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int> > *,int>::Node_t node; // [esp+8h] [ebp-8h] BYREF

  v4 = *(CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int> > **)insert;
  node.key = *key;
  node.elem = v4;
  insert = -1;
  LOBYTE(key) = 0;
  CUtlRBTree<CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int>> *,int>::Node_t,int>,int>>::FindInsertionPosition(
    this: &this->m_Tree,
    insert: &node,
    parent: &insert,
    leftchild: (bool *)&key);
  v5 = CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::NewNode((CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *)this);
  CUtlRBTree<CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int>> *,int>::Node_t,int>,int>>::LinkToParent(
    this: &this->m_Tree,
    i: v5,
    parent: insert,
    isLeft: (bool)key);
  m_pMemory = this->m_Tree.m_Elements.m_pMemory;
  ++this->m_Tree.m_NumElements;
  if ( &m_pMemory[v5] != (UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int> > *,int>::Node_t,int> *)-16 )
    m_pMemory[v5].m_Data = node;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10013320
// Name: public: int CUtlDict<class CUtlVector<class CStoreIDEntry,class CUtlMemory<class CStoreIDEntry,int>> __near *,int>::Insert(char const __near *,class CUtlVector<class CStoreIDEntry,class CUtlMemory<class CStoreIDEntry,int>> __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int>> *,int>::Insert(
        CUtlDict<CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int> > *,int> *this,
        char *pName,
        CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int> > *const *element)
{
  const char *v3; // edi
  char *v5; // eax

  v3 = pName;
  if ( pName != nullptr && (v5 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v5, v3);
  else
    v5 = nullptr;
  pName = v5;
  return CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int>> *,int>::Insert(
           this: &this->m_Elements,
           key: (const char **)&pName,
           insert: (int)element);
}

//------------------------------------------------------------------------------
// Address: 0x1001D740
// Name: private: unsigned long CFileTracker::CalculateCRCForFile(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CFileTracker::CalculateCRCForFile(CFileTracker *this, void *fp)
{
  unsigned int v4; // eax
  IBaseFileSystem *v5; // ecx
  unsigned int v6; // eax
  int v7; // esi
  unsigned int v8; // ecx
  unsigned int v9; // eax
  bool v10; // zf
  int v11; // eax
  _BYTE pBuffer[32768]; // [esp+Ch] [ebp-8014h] BYREF
  int nBuffer; // [esp+800Ch] [ebp-14h]
  int v15; // [esp+8010h] [ebp-10h]
  unsigned int v16; // [esp+8014h] [ebp-Ch]
  int v17; // [esp+8018h] [ebp-8h]
  unsigned int pulCRC; // [esp+801Ch] [ebp-4h] BYREF
  int i; // [esp+8028h] [ebp+8h]

  v4 = this->m_pFileSystem->Tell(this: &this->m_pFileSystem->IBaseFileSystem, a2: fp);
  v5 = &this->m_pFileSystem->IBaseFileSystem;
  v15 = v4;
  v5->Seek(this: v5, a2: fp, a3: 0, a4: FILESYSTEM_SEEK_HEAD);
  CRC32_Init(&pulCRC);
  v6 = this->m_pFileSystem->Size_2(this: &this->m_pFileSystem->IBaseFileSystem, a2: fp);
  v7 = (v6 >> 15) + 1;
  v16 = v6;
  v17 = 0;
  if ( v6 >> 15 != -1 )
  {
    v8 = 0x8000;
    for ( i = 0x8000; ; v8 = i )
    {
      if ( v8 < v6 )
        v6 = v8;
      v9 = v6 - v8;
      v10 = v9 == -32768;
      v11 = v9 + 0x8000;
      nBuffer = v11;
      if ( v10 )
        break;
      this->m_pFileSystem->Read(this: &this->m_pFileSystem->IBaseFileSystem, a2: pBuffer, a3: v11, a4: fp);
      CRC32_ProcessBuffer(&pulCRC, pBuffer, nBuffer);
      i += 0x8000;
      if ( ++v17 >= v7 )
        break;
      v6 = v16;
    }
  }
  CRC32_Final(&pulCRC);
  this->m_pFileSystem->Seek(this: &this->m_pFileSystem->IBaseFileSystem, a2: fp, a3: v15, a4: FILESYSTEM_SEEK_HEAD);
  return pulCRC;
}

//------------------------------------------------------------------------------
// Address: 0x1001D840
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class CUtlVector<class CStoreIDEntry,class CUtlMemory<class CStoreIDEntry,int>> __near *,int>::Node_t,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int>> *,int>::Node_t,int>,int>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 2;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 24 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001F830
// Name: public: void CFileTracker::MarkAllCRCsVerified(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileTracker::MarkAllCRCsVerified(CFileTracker *this, bool bLockMutex)
{
  int m_Head; // eax
  UtlLinkedListElem_t<CFileInfo *,unsigned short> *m_pMemory; // ecx
  int v5; // eax
  UtlLinkedListElem_t<CFileInfo *,unsigned short> *v6; // ecx

  if ( bLockMutex )
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_Mutex);
  m_Head = this->m_NeedsVerificationList.m_Head;
  if ( m_Head != 0xFFFF )
  {
    m_pMemory = this->m_NeedsVerificationList.m_Memory.m_pMemory;
    do
    {
      v5 = (unsigned __int16)m_Head;
      m_pMemory[v5].m_Element->m_iNeedsVerificationListIndex = -1;
      m_pMemory = this->m_NeedsVerificationList.m_Memory.m_pMemory;
      m_Head = this->m_NeedsVerificationList.m_Memory.m_pMemory[v5].m_Next;
    }
    while ( m_Head != 0xFFFF );
  }
  CUtlLinkedList<CZip *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CZip *,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_NeedsVerificationList);
  if ( this->m_NeedsVerificationList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_NeedsVerificationList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_NeedsVerificationList.m_Memory.m_pMemory);
      this->m_NeedsVerificationList.m_Memory.m_pMemory = nullptr;
    }
    this->m_NeedsVerificationList.m_Memory.m_nAllocationCount = 0;
  }
  this->m_NeedsVerificationList.m_FirstFree = -1;
  v6 = this->m_NeedsVerificationList.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_NeedsVerificationList.m_NumAlloced = -65536;
  this->m_NeedsVerificationList.m_pElements = v6;
  if ( bLockMutex )
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_Mutex);
}

//------------------------------------------------------------------------------
// Address: 0x1001F930
// Name: public: void CUtlDict<class CPathIDFileList __near *,int>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<CPathIDFileList *,int>::RemoveAll(CUtlDict<CPathIDFileList *,int> *this)
{
  int i; // esi

  for ( i = CUtlRBTree<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int,CUtlMap<char const *,CPathIDFileList *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int,CUtlMap<char const *,CPathIDFileList *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int,CUtlMap<char const *,CPathIDFileList *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x1001FA60
// Name: public: void CUtlDict<class CFileInfo __near *,int>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<CFileInfo *,int>::PurgeAndDeleteElements(CUtlDict<CFileInfo *,int> *this)
{
  int i; // edi
  CFileInfo *elem; // esi

  for ( i = CUtlRBTree<CUtlMap<char const *,CFileInfo *,int>::Node_t,int,CUtlMap<char const *,CFileInfo *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CFileInfo *,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,CFileInfo *,int>::Node_t,int,CUtlMap<char const *,CFileInfo *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CFileInfo *,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
    elem = this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.elem;
    if ( elem != nullptr )
      free(pMem: elem);
  }
  CUtlRBTree<CUtlMap<char const *,CFileInfo *,int>::Node_t,int,CUtlMap<char const *,CFileInfo *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CFileInfo *,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x1001FAC0
// Name: public: int CFileTracker::GetUnverifiedCRCFiles(class CUnverifiedCRCFile __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileTracker::GetUnverifiedCRCFiles(CFileTracker *this, CUnverifiedCRCFile *pFiles, int nMaxFiles)
{
  _RTL_CRITICAL_SECTION *p_m_Mutex; // esi
  int m_Head; // ecx
  int v6; // ebx
  CFileInfo *m_Element; // esi
  bool v8; // zf
  const char *v9; // eax
  unsigned int m_CRC; // eax
  int v11; // esi
  int iNext; // [esp+Ch] [ebp-10h]
  _RTL_CRITICAL_SECTION *generated_id_6; // [esp+10h] [ebp-Ch]
  int iOutFile; // [esp+14h] [ebp-8h]
  unsigned __int16 i; // [esp+18h] [ebp-4h]
  unsigned int *pFilesa; // [esp+24h] [ebp+8h]

  p_m_Mutex = (_RTL_CRITICAL_SECTION *)&this->m_Mutex;
  generated_id_6 = (_RTL_CRITICAL_SECTION *)&this->m_Mutex;
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_Mutex);
  m_Head = this->m_NeedsVerificationList.m_Head;
  iOutFile = 0;
  i = this->m_NeedsVerificationList.m_Head;
  if ( m_Head == 0xFFFF )
  {
LABEL_8:
    LeaveCriticalSection(lpCriticalSection: p_m_Mutex);
    return iOutFile;
  }
  else
  {
    pFilesa = &pFiles->m_CRC;
    while ( 1 )
    {
      v6 = (unsigned __int16)m_Head;
      m_Element = this->m_NeedsVerificationList.m_Memory.m_pMemory[v6].m_Element;
      iNext = this->m_NeedsVerificationList.m_Memory.m_pMemory[v6].m_Next;
      CUtlLinkedList<CFileInfo *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFileInfo *,unsigned short>,unsigned short>>::Unlink(
        this: &this->m_NeedsVerificationList,
        elem: m_Head);
      this->m_NeedsVerificationList.m_Memory.m_pMemory[v6].m_Next = this->m_NeedsVerificationList.m_FirstFree;
      this->m_NeedsVerificationList.m_FirstFree = i;
      v8 = (m_Element->m_Flags & 1) == 0;
      m_Element->m_iNeedsVerificationListIndex = -1;
      if ( v8 )
      {
        V_strncpy(
          pDest: (char *)pFilesa - 260,
          pSrc: m_Element->m_pPathIDFileList->m_Files.m_Elements.m_Tree.m_Elements.m_pMemory[m_Element->m_PathIDFileListDictIndex].m_Data.key,
          maxLen: 260);
        v9 = CUtlSymbol::String(this: &m_Element->m_pPathIDFileList->m_PathID);
        V_strncpy(pDest: (char *)pFilesa - 520, pSrc: v9, maxLen: 260);
        m_CRC = m_Element->m_CRC;
        v11 = iOutFile + 1;
        *pFilesa = m_CRC;
        iOutFile = v11;
        pFilesa += 131;
        if ( v11 >= nMaxFiles )
          break;
      }
      i = iNext;
      if ( iNext == 0xFFFF )
      {
        p_m_Mutex = generated_id_6;
        goto LABEL_8;
      }
      LOWORD(m_Head) = iNext;
    }
    LeaveCriticalSection(lpCriticalSection: generated_id_6);
    return v11;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001FC20
// Name: public: CFileTracker::CFileTracker(class CBaseFileSystem __near *)
// Source: json
//------------------------------------------------------------------------------
CFileTracker *__thiscall CFileTracker::CFileTracker(CFileTracker *this, CBaseFileSystem *pFileSystem)
{
  this->m_NeedsVerificationList.m_Memory.m_pMemory = nullptr;
  this->m_NeedsVerificationList.m_Memory.m_nAllocationCount = 0;
  this->m_NeedsVerificationList.m_Memory.m_nGrowSize = 0;
  this->m_NeedsVerificationList.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_NeedsVerificationList.m_FirstFree = 0xFFFF;
  this->m_NeedsVerificationList.m_pElements = this->m_NeedsVerificationList.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_NeedsVerificationList.m_Head = -1;
  this->m_NeedsVerificationList.m_NumAlloced = 0;
  this->m_PathIDs.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_PathIDs.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_PathIDs.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_PathIDs.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_PathIDs.m_Elements.m_Tree.m_Root = -1;
  this->m_PathIDs.m_Elements.m_Tree.m_NumElements = 0;
  this->m_PathIDs.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_PathIDs.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_PathIDs.m_Elements.m_Tree.m_pElements = this->m_PathIDs.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( this->m_PathIDs.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_PathIDs.m_Elements.m_Tree.m_LessFunc.m_LessFunc = CaselessStringLessThan;
  CThreadMutex::CThreadMutex(this: &this->m_Mutex);
  this->m_pFileSystem = pFileSystem;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1001FCA0
// Name: public: int CFileTracker::GetFileInfos(class CFileInfo __near * __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileTracker::GetFileInfos(
        CFileTracker *this,
        CFileInfo **ppFileInfos,
        int nMaxFileInfos,
        const char *pFilename)
{
  _RTL_CRITICAL_SECTION *p_m_Mutex; // edi
  int Inorder; // esi
  CPathIDFileList *elem; // edi
  int v8; // eax
  CFileInfo *v9; // eax
  int v10; // ecx
  CUtlMap<char const *,CFileInfo *,int>::Node_t search; // [esp+Ch] [ebp-10h] BYREF
  CAutoLockT<CThreadMutex> generated_id_2; // [esp+14h] [ebp-8h]
  int nOut; // [esp+18h] [ebp-4h]

  p_m_Mutex = (_RTL_CRITICAL_SECTION *)&this->m_Mutex;
  generated_id_2.m_lock = &this->m_Mutex;
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_Mutex);
  nOut = 0;
  Inorder = CUtlRBTree<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int,CUtlMap<char const *,CPathIDFileList *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_PathIDs.m_Elements.m_Tree);
  if ( Inorder != -1 )
  {
    do
    {
      elem = this->m_PathIDs.m_Elements.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.elem;
      if ( pFilename != nullptr )
      {
        search.key = pFilename;
        v8 = CUtlRBTree<CUtlMap<char const *,CFileInfo *,int>::Node_t,int,CUtlMap<char const *,CFileInfo *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CFileInfo *,int>::Node_t,int>,int>>::Find(
               this: &elem->m_Files.m_Elements.m_Tree,
               &search);
        if ( v8 != -1 )
        {
          v9 = elem->m_Files.m_Elements.m_Tree.m_Elements.m_pMemory[v8].m_Data.elem;
          if ( v9 != nullptr )
          {
            v10 = nOut;
            if ( nOut < nMaxFileInfos )
            {
              ppFileInfos[nOut] = v9;
              nOut = v10 + 1;
            }
          }
        }
      }
      Inorder = CUtlRBTree<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int,CUtlMap<char const *,CPathIDFileList *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int>,int>>::NextInorder(
                  this: &this->m_PathIDs.m_Elements.m_Tree,
                  i: Inorder);
    }
    while ( Inorder != -1 );
    p_m_Mutex = (_RTL_CRITICAL_SECTION *)generated_id_2.m_lock;
  }
  LeaveCriticalSection(lpCriticalSection: p_m_Mutex);
  return nOut;
}

//------------------------------------------------------------------------------
// Address: 0x1001FD40
// Name: public: void CFileTracker::MarkAllCRCsUnverified(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileTracker::MarkAllCRCsUnverified(CFileTracker *this)
{
  _RTL_CRITICAL_SECTION *p_m_Mutex; // edi
  int Inorder; // eax
  CPathIDFileList *elem; // edi
  int v5; // ebx
  unsigned __int16 v6; // ax
  int v7; // edi
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CFileInfo *,unsigned short> *m_pMemory; // eax
  int v10; // ecx
  int m_Tail; // edx
  UtlLinkedListElem_t<CFileInfo *,unsigned short> *v12; // eax
  UtlLinkedListElem_t<CFileInfo *,unsigned short> *v13; // eax
  CThreadMutex *generated_id_5; // [esp+8h] [ebp-14h]
  CPathIDFileList *pPath; // [esp+Ch] [ebp-10h]
  int j; // [esp+10h] [ebp-Ch]
  CFileInfo *pInfo; // [esp+14h] [ebp-8h]
  int i; // [esp+18h] [ebp-4h]

  p_m_Mutex = (_RTL_CRITICAL_SECTION *)&this->m_Mutex;
  generated_id_5 = &this->m_Mutex;
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_Mutex);
  CFileTracker::MarkAllCRCsVerified(this, bLockMutex: true);
  Inorder = CUtlRBTree<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int,CUtlMap<char const *,CPathIDFileList *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_PathIDs.m_Elements.m_Tree);
  i = Inorder;
  if ( Inorder != -1 )
  {
    while ( 1 )
    {
      elem = this->m_PathIDs.m_Elements.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.elem;
      pPath = elem;
      v5 = CUtlRBTree<CUtlMap<char const *,CFileInfo *,int>::Node_t,int,CUtlMap<char const *,CFileInfo *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CFileInfo *,int>::Node_t,int>,int>>::FirstInorder(this: &elem->m_Files.m_Elements.m_Tree);
      for ( j = v5; v5 != -1; j = v5 )
      {
        pInfo = elem->m_Files.m_Elements.m_Tree.m_Elements.m_pMemory[v5].m_Data.elem;
        if ( (pInfo->m_Flags & 1) == 0 && (pInfo->m_Flags & 2) != 0 )
        {
          v6 = CUtlLinkedList<CFileInfo *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFileInfo *,unsigned short>,unsigned short>>::AllocInternal(
                 this: &this->m_NeedsVerificationList,
                 multilist: false);
          v7 = v6;
          if ( v6 == 0xFFFF )
          {
            v8 = -1;
          }
          else
          {
            CUtlLinkedList<CFileInfo *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFileInfo *,unsigned short>,unsigned short>>::Unlink(
              this: &this->m_NeedsVerificationList,
              elem: v6);
            m_pMemory = this->m_NeedsVerificationList.m_Memory.m_pMemory;
            v10 = v7;
            m_pMemory[v10].m_Next = -1;
            m_Tail = this->m_NeedsVerificationList.m_Tail;
            m_pMemory[v10].m_Previous = m_Tail;
            this->m_NeedsVerificationList.m_Tail = v7;
            if ( (_WORD)m_Tail == 0xFFFF )
              this->m_NeedsVerificationList.m_Head = v7;
            else
              this->m_NeedsVerificationList.m_Memory.m_pMemory[m_Tail].m_Next = v7;
            v12 = this->m_NeedsVerificationList.m_Memory.m_pMemory;
            ++this->m_NeedsVerificationList.m_ElementCount;
            v13 = &v12[v10];
            if ( v13 != nullptr )
              v13->m_Element = pInfo;
            v5 = j;
            v8 = v7;
          }
          elem = pPath;
          pInfo->m_iNeedsVerificationListIndex = v8;
        }
        v5 = CUtlRBTree<CUtlMap<char const *,CFileInfo *,int>::Node_t,int,CUtlMap<char const *,CFileInfo *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CFileInfo *,int>::Node_t,int>,int>>::NextInorder(
               this: &elem->m_Files.m_Elements.m_Tree,
               i: v5);
      }
      i = CUtlRBTree<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int,CUtlMap<char const *,CPathIDFileList *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int>,int>>::NextInorder(
            this: &this->m_PathIDs.m_Elements.m_Tree,
            i);
      if ( i == -1 )
        break;
      Inorder = i;
    }
    p_m_Mutex = (_RTL_CRITICAL_SECTION *)generated_id_5;
  }
  LeaveCriticalSection(lpCriticalSection: p_m_Mutex);
}

//------------------------------------------------------------------------------
// Address: 0x1001FE80
// Name: public: CPathIDFileList::CPathIDFileList(void)
// Source: json
//------------------------------------------------------------------------------
CPathIDFileList *__thiscall CPathIDFileList::CPathIDFileList(CPathIDFileList *this)
{
  CPathIDFileList *result; // eax
  UtlLinkedListElem_t<CFileInfo *,int> *m_pMemory; // edx

  result = this;
  this->m_PathID.m_Id = -1;
  this->m_Files.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_Files.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_Files.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_Files.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_Files.m_Elements.m_Tree.m_Root = -1;
  this->m_Files.m_Elements.m_Tree.m_NumElements = 0;
  this->m_Files.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_Files.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_Files.m_Elements.m_Tree.m_pElements = this->m_Files.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( this->m_Files.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_Files.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThanIgnoreSlashes;
  this->m_UnverifiedCRCFiles.m_Memory.m_pMemory = nullptr;
  this->m_UnverifiedCRCFiles.m_Memory.m_nAllocationCount = 0;
  this->m_UnverifiedCRCFiles.m_Memory.m_nGrowSize = 0;
  this->m_UnverifiedCRCFiles.m_LastAlloc.index = -1;
  this->m_UnverifiedCRCFiles.m_Head = -1;
  this->m_UnverifiedCRCFiles.m_Tail = -1;
  this->m_UnverifiedCRCFiles.m_FirstFree = -1;
  m_pMemory = this->m_UnverifiedCRCFiles.m_Memory.m_pMemory;
  this->m_UnverifiedCRCFiles.m_ElementCount = 0;
  this->m_UnverifiedCRCFiles.m_NumAlloced = 0;
  this->m_UnverifiedCRCFiles.m_pElements = m_pMemory;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001FEE0
// Name: public: int CUtlMap<char const __near *,class CFileInfo __near *,int>::Insert(char const __near * const __near &,class CFileInfo __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlMap<char const *,CFileInfo *,int>::Insert(
        CUtlMap<char const *,CFileInfo *,int> *this,
        const char **key,
        int insert)
{
  CFileInfo *v4; // eax
  int v5; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CFileInfo *,int>::Node_t,int> *m_pMemory; // ecx
  CUtlMap<char const *,CFileInfo *,int>::Node_t node; // [esp+8h] [ebp-8h] BYREF

  v4 = *(CFileInfo **)insert;
  node.key = *key;
  node.elem = v4;
  insert = -1;
  LOBYTE(key) = 0;
  CUtlRBTree<CUtlMap<char const *,CFileInfo *,int>::Node_t,int,CUtlMap<char const *,CFileInfo *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CFileInfo *,int>::Node_t,int>,int>>::FindInsertionPosition(
    this: &this->m_Tree,
    insert: &node,
    parent: &insert,
    leftchild: (bool *)&key);
  v5 = CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::NewNode((CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *)this);
  CUtlRBTree<CUtlMap<char const *,CFileInfo *,int>::Node_t,int,CUtlMap<char const *,CFileInfo *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CFileInfo *,int>::Node_t,int>,int>>::LinkToParent(
    this: &this->m_Tree,
    i: v5,
    parent: insert,
    isLeft: (bool)key);
  m_pMemory = this->m_Tree.m_Elements.m_pMemory;
  ++this->m_Tree.m_NumElements;
  if ( &m_pMemory[v5] != (UtlRBTreeNode_t<CUtlMap<char const *,CFileInfo *,int>::Node_t,int> *)-16 )
    m_pMemory[v5].m_Data = node;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1001FF60
// Name: public: int CUtlMap<char const __near *,class CPathIDFileList __near *,int>::Insert(char const __near * const __near &,class CPathIDFileList __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlMap<char const *,CPathIDFileList *,int>::Insert(
        CUtlMap<char const *,CPathIDFileList *,int> *this,
        const char **key,
        int insert)
{
  CPathIDFileList *v4; // eax
  int v5; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int> *m_pMemory; // ecx
  CUtlMap<char const *,CPathIDFileList *,int>::Node_t node; // [esp+8h] [ebp-8h] BYREF

  v4 = *(CPathIDFileList **)insert;
  node.key = *key;
  node.elem = v4;
  insert = -1;
  LOBYTE(key) = 0;
  CUtlRBTree<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int,CUtlMap<char const *,CPathIDFileList *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int>,int>>::FindInsertionPosition(
    this: &this->m_Tree,
    insert: &node,
    parent: &insert,
    leftchild: (bool *)&key);
  v5 = CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::NewNode((CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *)this);
  CUtlRBTree<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int,CUtlMap<char const *,CPathIDFileList *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int>,int>>::LinkToParent(
    this: &this->m_Tree,
    i: v5,
    parent: insert,
    isLeft: (bool)key);
  m_pMemory = this->m_Tree.m_Elements.m_pMemory;
  ++this->m_Tree.m_NumElements;
  if ( &m_pMemory[v5] != (UtlRBTreeNode_t<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int> *)-16 )
    m_pMemory[v5].m_Data = node;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1001FFE0
// Name: public: int CUtlDict<class CFileInfo __near *,int>::Insert(char const __near *,class CFileInfo __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<CFileInfo *,int>::Insert(
        CUtlDict<CFileInfo *,int> *this,
        char *pName,
        CFileInfo *const *element)
{
  const char *v3; // edi
  char *v5; // eax

  v3 = pName;
  if ( pName != nullptr && (v5 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v5, v3);
  else
    v5 = nullptr;
  pName = v5;
  return CUtlMap<char const *,CFileInfo *,int>::Insert(
           this: &this->m_Elements,
           key: (const char **)&pName,
           insert: (int)element);
}

//------------------------------------------------------------------------------
// Address: 0x10020040
// Name: public: int CUtlDict<class CPathIDFileList __near *,int>::Insert(char const __near *,class CPathIDFileList __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<CPathIDFileList *,int>::Insert(
        CUtlDict<CPathIDFileList *,int> *this,
        char *pName,
        CPathIDFileList *const *element)
{
  const char *v3; // edi
  char *v5; // eax

  v3 = pName;
  if ( pName != nullptr && (v5 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v5, v3);
  else
    v5 = nullptr;
  pName = v5;
  return CUtlMap<char const *,CPathIDFileList *,int>::Insert(
           this: &this->m_Elements,
           key: (const char **)&pName,
           insert: (int)element);
}

//------------------------------------------------------------------------------
// Address: 0x100200A0
// Name: public: void CUtlDict<class CPathIDFileList __near *,int>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<CPathIDFileList *,int>::PurgeAndDeleteElements(CUtlDict<CPathIDFileList *,int> *this)
{
  CUtlDict<CPathIDFileList *,int> *v1; // edi
  int Inorder; // eax
  int v3; // esi
  CPathIDFileList *elem; // edi
  CUtlRBTree<CUtlMap<char const *,CFileInfo *,int>::Node_t,int,CUtlMap<char const *,CFileInfo *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CFileInfo *,int>::Node_t,int>,int> > *p_m_Tree; // esi
  int i; // edi
  CPathIDFileList *pMem; // [esp+4h] [ebp-Ch]
  int index; // [esp+Ch] [ebp-4h]

  v1 = this;
  Inorder = CUtlRBTree<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int,CUtlMap<char const *,CPathIDFileList *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
  index = Inorder;
  if ( Inorder != -1 )
  {
    while ( 1 )
    {
      v3 = Inorder;
      _g_pMemAlloc->Free_2(
        this: _g_pMemAlloc,
        a2: (void *)v1->m_Elements.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.key);
      elem = v1->m_Elements.m_Tree.m_Elements.m_pMemory[v3].m_Data.elem;
      pMem = elem;
      if ( elem != nullptr )
      {
        p_m_Tree = &elem->m_Files.m_Elements.m_Tree;
        CUtlDict<CFileInfo *,int>::PurgeAndDeleteElements(this: &elem->m_Files);
        CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::RemoveAll(this: (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)&elem->m_UnverifiedCRCFiles);
        if ( elem->m_UnverifiedCRCFiles.m_Memory.m_nGrowSize >= 0 )
        {
          if ( elem->m_UnverifiedCRCFiles.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: elem->m_UnverifiedCRCFiles.m_Memory.m_pMemory);
            elem->m_UnverifiedCRCFiles.m_Memory.m_pMemory = nullptr;
          }
          elem->m_UnverifiedCRCFiles.m_Memory.m_nAllocationCount = 0;
        }
        for ( i = CUtlRBTree<CUtlMap<char const *,CFileInfo *,int>::Node_t,int,CUtlMap<char const *,CFileInfo *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CFileInfo *,int>::Node_t,int>,int>>::FirstInorder(this: &elem->m_Files.m_Elements.m_Tree);
              i != -1;
              i = CUtlRBTree<CUtlMap<char const *,CFileInfo *,int>::Node_t,int,CUtlMap<char const *,CFileInfo *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CFileInfo *,int>::Node_t,int>,int>>::NextInorder(
                    this: p_m_Tree,
                    i) )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)p_m_Tree->m_Elements.m_pMemory[i].m_Data.key);
        }
        CUtlRBTree<CUtlMap<char const *,CFileInfo *,int>::Node_t,int,CUtlMap<char const *,CFileInfo *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CFileInfo *,int>::Node_t,int>,int>>::RemoveAll(this: p_m_Tree);
        CUtlRBTree<CUtlMap<char const *,CFileInfo *,int>::Node_t,int,CUtlMap<char const *,CFileInfo *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CFileInfo *,int>::Node_t,int>,int>>::RemoveAll(this: p_m_Tree);
        p_m_Tree->m_FirstFree = -1;
        if ( p_m_Tree->m_Elements.m_nGrowSize >= 0 )
        {
          if ( p_m_Tree->m_Elements.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_Tree->m_Elements.m_pMemory);
            p_m_Tree->m_Elements.m_pMemory = nullptr;
          }
          p_m_Tree->m_Elements.m_nAllocationCount = 0;
        }
        p_m_Tree->m_LastAlloc.index = -1;
        if ( p_m_Tree->m_Elements.m_nGrowSize >= 0 )
        {
          if ( p_m_Tree->m_Elements.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_Tree->m_Elements.m_pMemory);
            p_m_Tree->m_Elements.m_pMemory = nullptr;
          }
          p_m_Tree->m_Elements.m_nAllocationCount = 0;
        }
        free(pMem);
      }
      v1 = this;
      index = CUtlRBTree<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int,CUtlMap<char const *,CPathIDFileList *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int>,int>>::NextInorder(
                this: &this->m_Elements.m_Tree,
                i: index);
      if ( index == -1 )
        break;
      Inorder = index;
    }
  }
  CUtlRBTree<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int,CUtlMap<char const *,CPathIDFileList *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int>,int>>::RemoveAll(this: &v1->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x10020200
// Name: private: class CPathIDFileList __near * CFileTracker::GetPathIDFileList(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CPathIDFileList *__thiscall CFileTracker::GetPathIDFileList(CFileTracker *this, CPathIDFileList *pPathID, int bAutoAdd)
{
  _RTL_CRITICAL_SECTION *p_m_Mutex; // ebx
  char *v5; // edi
  int v6; // eax
  CPathIDFileList *v7; // eax
  char *v8; // esi
  CPathIDFileList *elem; // esi
  CUtlMap<char const *,CPathIDFileList *,int>::Node_t search; // [esp+Ch] [ebp-Ch] BYREF
  CUtlDict<CPathIDFileList *,int> *p_m_PathIDs; // [esp+14h] [ebp-4h]

  p_m_Mutex = (_RTL_CRITICAL_SECTION *)&this->m_Mutex;
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_Mutex);
  v5 = (char *)pPathID;
  if ( pPathID == nullptr )
    v5 = (char *)defaultValue;
  search.key = v5;
  p_m_PathIDs = &this->m_PathIDs;
  v6 = CUtlRBTree<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int,CUtlMap<char const *,CPathIDFileList *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int>,int>>::Find(
         this: &this->m_PathIDs.m_Elements.m_Tree,
         &search);
  if ( v6 == -1 )
  {
    if ( (_BYTE)bAutoAdd != 0 )
    {
      v7 = (CPathIDFileList *)operator new(nSize: 0x50u);
      if ( v7 != nullptr )
        v8 = (char *)CPathIDFileList::CPathIDFileList(this: v7);
      else
        v8 = nullptr;
      pPathID = (CPathIDFileList *)v8;
      CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&bAutoAdd + 1, pStr: v5);
      *(_WORD *)v8 = HIWORD(bAutoAdd);
      CUtlDict<CPathIDFileList *,int>::Insert(this: p_m_PathIDs, pName: v5, element: &pPathID);
      LeaveCriticalSection(lpCriticalSection: p_m_Mutex);
      return (CPathIDFileList *)v8;
    }
    else
    {
      LeaveCriticalSection(lpCriticalSection: p_m_Mutex);
      return nullptr;
    }
  }
  else
  {
    elem = this->m_PathIDs.m_Elements.m_Tree.m_Elements.m_pMemory[v6].m_Data.elem;
    LeaveCriticalSection(lpCriticalSection: p_m_Mutex);
    return elem;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100202C0
// Name: public: CFileTracker::~CFileTracker(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileTracker::~CFileTracker(CFileTracker *this)
{
  _RTL_CRITICAL_SECTION *p_m_Mutex; // edi

  p_m_Mutex = (_RTL_CRITICAL_SECTION *)&this->m_Mutex;
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_Mutex);
  CUtlDict<CPathIDFileList *,int>::PurgeAndDeleteElements(this: &this->m_PathIDs);
  LeaveCriticalSection(lpCriticalSection: p_m_Mutex);
  CThreadMutex::~CThreadMutex(this: (CThreadMutex *)p_m_Mutex);
  CUtlDict<CPathIDFileList *,int>::RemoveAll(this: &this->m_PathIDs);
  CUtlRBTree<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int,CUtlMap<char const *,CPathIDFileList *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int,CUtlMap<char const *,CPathIDFileList *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int>,int>>(this: &this->m_PathIDs.m_Elements.m_Tree);
  CUtlLinkedList<CZip *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CZip *,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_NeedsVerificationList);
  if ( this->m_NeedsVerificationList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_NeedsVerificationList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_NeedsVerificationList.m_Memory.m_pMemory);
      this->m_NeedsVerificationList.m_Memory.m_pMemory = nullptr;
    }
    this->m_NeedsVerificationList.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10020330
// Name: public: void CFileTracker::NoteFileLoadedFromDisk(char const __near *,char const __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileTracker::NoteFileLoadedFromDisk(CFileTracker *this, char *pFilename, char *pPathID, void *fp)
{
  char *v5; // esi
  CPathIDFileList *PathIDFileList; // ebx
  const char *v7; // eax
  int v8; // eax
  CFileInfo *elem; // ebx
  char *v10; // eax
  char *v11; // esi
  CUtlDict<CFileInfo *,int> *p_m_Files; // ecx
  unsigned int v13; // eax
  bool v14; // zf
  unsigned __int16 v15; // ax
  int v16; // esi
  unsigned __int16 v17; // ax
  UtlLinkedListElem_t<CFileInfo *,unsigned short> *v18; // eax
  CUtlMap<char const *,CFileInfo *,int>::Node_t search; // [esp+Ch] [ebp-10h] BYREF
  CPathIDFileList *pPath; // [esp+14h] [ebp-8h]
  CAutoLockT<CThreadMutex> generated_id_0; // [esp+18h] [ebp-4h]

  generated_id_0.m_lock = &this->m_Mutex;
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_Mutex);
  v5 = pPathID;
  if ( pPathID == nullptr )
    v5 = (char *)defaultValue;
  PathIDFileList = CFileTracker::GetPathIDFileList(this, pPathID: (CPathIDFileList *)v5, bAutoAdd: 1);
  v7 = pFilename;
  pPath = PathIDFileList;
  if ( pFilename == nullptr )
    goto LABEL_6;
  search.key = pFilename;
  v8 = CUtlRBTree<CUtlMap<char const *,CFileInfo *,int>::Node_t,int,CUtlMap<char const *,CFileInfo *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CFileInfo *,int>::Node_t,int>,int>>::Find(
         this: &PathIDFileList->m_Files.m_Elements.m_Tree,
         &search);
  if ( v8 == -1 )
  {
    v7 = pFilename;
LABEL_6:
    elem = nullptr;
    goto LABEL_8;
  }
  elem = PathIDFileList->m_Files.m_Elements.m_Tree.m_Elements.m_pMemory[v8].m_Data.elem;
  v7 = pFilename;
LABEL_8:
  if ( (this->m_pFileSystem->m_WhitelistSpewFlags & 1) != 0 )
  {
    if ( elem == nullptr )
    {
      _Warning(a1: "(Unique   ): [%s]\\%s", v5, v7);
      goto LABEL_14;
    }
    _Warning(a1: "(Duplicate): [%s]\\%s", v5, v7);
  }
  if ( elem != nullptr )
  {
    elem->m_Flags &= 8u;
    goto LABEL_18;
  }
LABEL_14:
  v10 = (char *)operator new(nSize: 0x14u);
  if ( v10 != nullptr )
  {
    *((_DWORD *)v10 + 4) = -1;
    v11 = v10;
  }
  else
  {
    v11 = nullptr;
  }
  p_m_Files = &pPath->m_Files;
  pPathID = v11;
  *((_DWORD *)v11 + 2) = pPath;
  *((_DWORD *)v11 + 3) = CUtlDict<CFileInfo *,int>::Insert(
                           this: p_m_Files,
                           pName: pFilename,
                           element: (CFileInfo *const *)&pPathID);
  elem = (CFileInfo *)v11;
  *(_WORD *)v11 = 0;
LABEL_18:
  if ( fp != nullptr )
  {
    v13 = CFileTracker::CalculateCRCForFile(this, fp);
    elem->m_Flags |= 0xAu;
    v14 = elem->m_iNeedsVerificationListIndex == -1;
    elem->m_CRC = v13;
    if ( v14 )
    {
      v15 = CUtlLinkedList<CFileInfo *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFileInfo *,unsigned short>,unsigned short>>::AllocInternal(
              this: &this->m_NeedsVerificationList,
              multilist: false);
      v16 = v15;
      if ( v15 == 0xFFFF )
      {
        v17 = -1;
      }
      else
      {
        CUtlLinkedList<CZip *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CZip *,unsigned short>,unsigned short>>::LinkBefore(
          this: &this->m_NeedsVerificationList,
          before: 0xFFFFu,
          elem: v15);
        v18 = &this->m_NeedsVerificationList.m_Memory.m_pMemory[v16];
        if ( v18 != nullptr )
          v18->m_Element = elem;
        v17 = v16;
      }
      elem->m_iNeedsVerificationListIndex = v17;
    }
    if ( (this->m_pFileSystem->m_WhitelistSpewFlags & 1) != 0 )
      _Warning(a1: " - %lu\n", elem->m_CRC);
  }
  else if ( (this->m_pFileSystem->m_WhitelistSpewFlags & 1) != 0 )
  {
    _Warning(a1: "\n");
  }
  LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)generated_id_0.m_lock);
}

//------------------------------------------------------------------------------
// Address: 0x100204C0
// Name: public: void CFileTracker::NoteFileFailedToLoad(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileTracker::NoteFileFailedToLoad(CFileTracker *this, const char *pFilename, CPathIDFileList *pPathID)
{
  CPathIDFileList *PathIDFileList; // esi
  int v4; // eax
  CFileInfo *elem; // eax
  CUtlMap<char const *,CFileInfo *,int>::Node_t search; // [esp+4h] [ebp-8h] BYREF

  PathIDFileList = CFileTracker::GetPathIDFileList(this, pPathID, bAutoAdd: 1);
  if ( pFilename != nullptr )
  {
    search.key = pFilename;
    v4 = CUtlRBTree<CUtlMap<char const *,CFileInfo *,int>::Node_t,int,CUtlMap<char const *,CFileInfo *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CFileInfo *,int>::Node_t,int>,int>>::Find(
           this: &PathIDFileList->m_Files.m_Elements.m_Tree,
           &search);
    if ( v4 != -1 )
    {
      elem = PathIDFileList->m_Files.m_Elements.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem;
      if ( elem != nullptr )
        elem->m_Flags |= 0x10u;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10020510
// Name: public: class CFileInfo __near * CFileTracker::GetFileInfo(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CFileInfo *__thiscall CFileTracker::GetFileInfo(CFileTracker *this, const char *pFilename, CPathIDFileList *pPathID)
{
  _RTL_CRITICAL_SECTION *p_m_Mutex; // esi
  const char *elem; // eax
  int v6; // eax
  CPathIDFileList *v8; // edi
  int v9; // eax
  CFileInfo *v10; // edi
  CUtlMap<char const *,CPathIDFileList *,int>::Node_t search; // [esp+Ch] [ebp-8h] BYREF

  p_m_Mutex = (_RTL_CRITICAL_SECTION *)&this->m_Mutex;
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_Mutex);
  search.elem = pPathID;
  EnterCriticalSection(lpCriticalSection: p_m_Mutex);
  elem = defaultValue;
  if ( pPathID != nullptr )
    elem = (const char *)search.elem;
  search.key = elem;
  v6 = CUtlRBTree<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int,CUtlMap<char const *,CPathIDFileList *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int>,int>>::Find(
         this: &this->m_PathIDs.m_Elements.m_Tree,
         &search);
  if ( v6 == -1 )
  {
    LeaveCriticalSection(lpCriticalSection: p_m_Mutex);
    LeaveCriticalSection(lpCriticalSection: p_m_Mutex);
    return nullptr;
  }
  else
  {
    v8 = this->m_PathIDs.m_Elements.m_Tree.m_Elements.m_pMemory[v6].m_Data.elem;
    LeaveCriticalSection(lpCriticalSection: p_m_Mutex);
    if ( v8 != nullptr
      && pFilename != nullptr
      && (search.key = pFilename,
          (v9 = CUtlRBTree<CUtlMap<char const *,CFileInfo *,int>::Node_t,int,CUtlMap<char const *,CFileInfo *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CFileInfo *,int>::Node_t,int>,int>>::Find(
                  this: &v8->m_Files.m_Elements.m_Tree,
                  (const CUtlMap<char const *,CFileInfo *,int>::Node_t *)&search)) != -1) )
    {
      v10 = v8->m_Files.m_Elements.m_Tree.m_Elements.m_pMemory[v9].m_Data.elem;
      LeaveCriticalSection(lpCriticalSection: p_m_Mutex);
      return v10;
    }
    else
    {
      LeaveCriticalSection(lpCriticalSection: p_m_Mutex);
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100205D0
// Name: public: void CFileTracker::NoteFileLoadedFromSteam(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileTracker::NoteFileLoadedFromSteam(
        CFileTracker *this,
        char *pFilename,
        char *pPathID,
        bool bForcedLoadFromSteam)
{
  CPathIDFileList *PathIDFileList; // eax
  char *v6; // ebx
  CPathIDFileList *v7; // esi
  int v8; // eax
  char *elem; // edi
  char *v10; // eax
  bool v11; // zf
  CUtlMap<char const *,CFileInfo *,int>::Node_t search; // [esp+Ch] [ebp-10h] BYREF
  CAutoLockT<CThreadMutex> generated_id_3; // [esp+14h] [ebp-8h]
  CFileTracker *v14; // [esp+18h] [ebp-4h]

  v14 = this;
  generated_id_3.m_lock = &this->m_Mutex;
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_Mutex);
  if ( pPathID == nullptr )
    pPathID = (char *)defaultValue;
  PathIDFileList = CFileTracker::GetPathIDFileList(this, (CPathIDFileList *)pPathID, bAutoAdd: 1);
  v6 = pFilename;
  v7 = PathIDFileList;
  if ( pFilename == nullptr
    || (search.key = pFilename,
        (v8 = CUtlRBTree<CUtlMap<char const *,CFileInfo *,int>::Node_t,int,CUtlMap<char const *,CFileInfo *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CFileInfo *,int>::Node_t,int>,int>>::Find(
                this: &PathIDFileList->m_Files.m_Elements.m_Tree,
                &search)) == -1)
    || (elem = (char *)v7->m_Files.m_Elements.m_Tree.m_Elements.m_pMemory[v8].m_Data.elem) == nullptr )
  {
    v10 = (char *)operator new(nSize: 0x14u);
    if ( v10 != nullptr )
    {
      *((_DWORD *)v10 + 4) = -1;
      elem = v10;
    }
    else
    {
      elem = nullptr;
    }
    pFilename = elem;
    *((_DWORD *)elem + 2) = v7;
    *((_DWORD *)elem + 3) = CUtlDict<CFileInfo *,int>::Insert(
                              this: &v7->m_Files,
                              pName: v6,
                              element: (CFileInfo *const *)&pFilename);
  }
  if ( (v14->m_pFileSystem->m_WhitelistSpewFlags & 1) != 0 )
    _Warning(a1: "From Steam: [%s]\\%s\n", pPathID, v6);
  v11 = !bForcedLoadFromSteam;
  *(_WORD *)elem = 1;
  if ( !v11 )
    *(_WORD *)elem = 5;
  LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)generated_id_3.m_lock);
}

//------------------------------------------------------------------------------
// Address: 0x100206B0
// Name: public: enum EFileCRCStatus CFileTracker::CheckCachedFileCRC(char const __near *,char const __near *,unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileTracker::CheckCachedFileCRC(
        CFileTracker *this,
        CPathIDFileList *pPathID,
        const char *pRelativeFilename,
        unsigned int *pCRC)
{
  CFileInfo *FileInfo; // eax

  FileInfo = CFileTracker::GetFileInfo(this, pFilename: pRelativeFilename, pPathID);
  if ( FileInfo == nullptr || (FileInfo->m_Flags & 8) == 0 )
    return 0;
  *pCRC = FileInfo->m_CRC;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100206E0
// Name: private: void CFileTracker::CalculateMissingCRC(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileTracker::CalculateMissingCRC(CFileTracker *this, const char *pFilename, CFileInfo *pPathID)
{
  CFileHandle *v3; // ebx
  CFileInfo *FileInfo; // eax
  CFileInfo *v6; // esi
  CFileHandle *FileInSearchPaths; // ebx
  int nOldFlags; // [esp+Ch] [ebp-4h]

  v3 = (CFileHandle *)pPathID;
  nOldFlags = -1;
  FileInfo = CFileTracker::GetFileInfo(this, pFilename, (CPathIDFileList *)pPathID);
  v6 = FileInfo;
  pPathID = FileInfo;
  if ( FileInfo != nullptr )
    nOldFlags = FileInfo->m_Flags;
  FileInSearchPaths = CBaseFileSystem::FindFileInSearchPaths(
                        this: this->m_pFileSystem,
                        pFileName: pFilename,
                        pOptions: "rb",
                        pathID: v3,
                        flags: 2u,
                        ppszResolvedFilename: nullptr,
                        bTrackCRCs: true);
  if ( FileInSearchPaths != nullptr )
  {
    if ( v6 != nullptr )
    {
      if ( nOldFlags != -1 )
        v6->m_Flags = nOldFlags;
      EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_Mutex);
      if ( (v6->m_Flags & 2) == 0 )
      {
        v6->m_CRC = CFileTracker::CalculateCRCForFile(this, fp: FileInSearchPaths);
        v6->m_Flags |= 0xAu;
        if ( v6->m_iNeedsVerificationListIndex == -1 )
          v6->m_iNeedsVerificationListIndex = (unsigned __int16)CUtlLinkedList<CFileInfo *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFileInfo *,unsigned short>,unsigned short>>::AddToTail(
                                                                  this: &this->m_NeedsVerificationList,
                                                                  src: &pPathID);
      }
      LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_Mutex);
    }
    this->m_pFileSystem->Close(this: &this->m_pFileSystem->IBaseFileSystem, a2: FileInSearchPaths);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10020790
// Name: public: void CFileTracker::CalculateMissingCRCs(class IFileList __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileTracker::CalculateMissingCRCs(CFileTracker *this, IFileList *pWantCRCList)
{
  CFileTracker *v2; // ebx
  int m_Head; // edi
  int Inorder; // eax
  int v5; // edi
  CFileInfo *elem; // ebx
  int v7; // eax
  int v8; // esi
  UtlLinkedListElem_t<CFileInfo *,int> *m_pMemory; // edx
  UtlLinkedListElem_t<CFileInfo *,int> *v10; // eax
  int m_Tail; // ecx
  int j; // eax
  int v13; // eax
  CFileInfo *m_Element; // esi
  UtlLinkedListElem_t<CFileInfo *,int> *v15; // edi
  CFileInfo *v16; // eax
  CUtlLinkedList<CFileInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileInfo *,int>,int> > needCRCList; // [esp+Ch] [ebp-34h] BYREF
  CFileTracker *v18; // [esp+34h] [ebp-Ch]
  CPathIDFileList *pPath; // [esp+38h] [ebp-8h]
  int i; // [esp+3Ch] [ebp-4h]

  v2 = this;
  v18 = this;
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_Mutex);
  m_Head = -1;
  memset(&needCRCList, 0, 12);
  needCRCList.m_LastAlloc.index = -1;
  memset(&needCRCList.m_Head, 255, 12);
  needCRCList.m_ElementCount = 0;
  needCRCList.m_NumAlloced = 0;
  needCRCList.m_pElements = nullptr;
  Inorder = CUtlRBTree<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int,CUtlMap<char const *,CPathIDFileList *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int>,int>>::FirstInorder(this: &v2->m_PathIDs.m_Elements.m_Tree);
  i = Inorder;
  if ( Inorder != -1 )
  {
    while ( 1 )
    {
      pPath = v2->m_PathIDs.m_Elements.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.elem;
      v5 = CUtlRBTree<CUtlMap<char const *,CFileInfo *,int>::Node_t,int,CUtlMap<char const *,CFileInfo *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CFileInfo *,int>::Node_t,int>,int>>::FirstInorder(this: &pPath->m_Files.m_Elements.m_Tree);
      if ( v5 != -1 )
      {
        do
        {
          elem = pPath->m_Files.m_Elements.m_Tree.m_Elements.m_pMemory[v5].m_Data.elem;
          if ( (elem->m_Flags & 3) == 0
            && pWantCRCList->IsFileInList(
                 this: pWantCRCList,
                 a2: elem->m_pPathIDFileList->m_Files.m_Elements.m_Tree.m_Elements.m_pMemory[elem->m_PathIDFileListDictIndex].m_Data.key) != 0 )
          {
            v7 = CUtlLinkedList<CFileInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileInfo *,int>,int>>::AllocInternal(
                   this: &needCRCList,
                   multilist: false);
            v8 = v7;
            if ( v7 != -1 )
            {
              CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
                this: (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)&needCRCList,
                elem: v7);
              m_pMemory = needCRCList.m_Memory.m_pMemory;
              v10 = &needCRCList.m_Memory.m_pMemory[v8];
              m_Tail = needCRCList.m_Tail;
              v10->m_Next = -1;
              v10->m_Previous = m_Tail;
              needCRCList.m_Tail = v8;
              if ( m_Tail == -1 )
                needCRCList.m_Head = v8;
              else
                m_pMemory[m_Tail].m_Next = v8;
              ++needCRCList.m_ElementCount;
              if ( v10 != nullptr )
                v10->m_Element = elem;
            }
          }
          v5 = CUtlRBTree<CUtlMap<char const *,CFileInfo *,int>::Node_t,int,CUtlMap<char const *,CFileInfo *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CFileInfo *,int>::Node_t,int>,int>>::NextInorder(
                 this: &pPath->m_Files.m_Elements.m_Tree,
                 i: v5);
        }
        while ( v5 != -1 );
        v2 = v18;
      }
      i = CUtlRBTree<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int,CUtlMap<char const *,CPathIDFileList *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int>,int>>::NextInorder(
            this: &v2->m_PathIDs.m_Elements.m_Tree,
            i);
      if ( i == -1 )
        break;
      Inorder = i;
    }
    m_Head = needCRCList.m_Head;
  }
  LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&v2->m_Mutex);
  for ( j = m_Head; j != -1; j = v15->m_Next )
  {
    v13 = j;
    m_Element = needCRCList.m_Memory.m_pMemory[v13].m_Element;
    v15 = &needCRCList.m_Memory.m_pMemory[v13];
    v16 = (CFileInfo *)CUtlSymbol::String(this: &m_Element->m_pPathIDFileList->m_PathID);
    CFileTracker::CalculateMissingCRC(
      this: v2,
      pFilename: m_Element->m_pPathIDFileList->m_Files.m_Elements.m_Tree.m_Elements.m_pMemory[m_Element->m_PathIDFileListDictIndex].m_Data.key,
      pPathID: v16);
  }
  CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::RemoveAll(this: (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)&needCRCList);
  if ( needCRCList.m_Memory.m_nGrowSize >= 0 && needCRCList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: needCRCList.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10020940
// Name: public: void CFileTracker::CacheFileCRC(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileTracker::CacheFileCRC(CFileTracker *this, CPathIDFileList *pPathID, const char *pRelativeFilename)
{
  CFileInfo *FileInfo; // esi
  CFileInfo *v5; // eax

  FileInfo = CFileTracker::GetFileInfo(this, pFilename: pRelativeFilename, pPathID);
  if ( FileInfo != nullptr
    || (CFileTracker::CalculateMissingCRC(this, pFilename: pRelativeFilename, (CFileInfo *)pPathID),
        (FileInfo = CFileTracker::GetFileInfo(this, pFilename: pRelativeFilename, pPathID)) != nullptr) )
  {
    if ( (FileInfo->m_Flags & 8) == 0 )
    {
      v5 = (CFileInfo *)CUtlSymbol::String(this: &FileInfo->m_pPathIDFileList->m_PathID);
      CFileTracker::CalculateMissingCRC(
        this,
        pFilename: FileInfo->m_pPathIDFileList->m_Files.m_Elements.m_Tree.m_Elements.m_pMemory[FileInfo->m_PathIDFileListDictIndex].m_Data.key,
        pPathID: v5);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100209B0
// Name: public: void CFileTracker::CacheFileCRC_Copy(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileTracker::CacheFileCRC_Copy(
        CFileTracker *this,
        CPathIDFileList *pPathID,
        CFileInfo *pRelativeFilename,
        CPathIDFileList *pPathIDToCopyFrom)
{
  CPathIDFileList *v5; // edi
  CFileInfo *FileInfo; // eax
  CFileInfo *v8; // edi
  CPathIDFileList *v9; // edi
  CFileInfo *v10; // eax
  CPathIDFileList *PathIDFileList; // eax
  CPathIDFileList *v12; // esi
  int v13; // eax
  _DWORD *p_m_Id; // eax
  CPathIDFileList *v15; // eax
  CPathIDFileList *v16; // edi
  CUtlMap<char const *,CFileInfo *,int>::Node_t search; // [esp+Ch] [ebp-8h] BYREF
  CFileInfo *pSourceInfo; // [esp+20h] [ebp+Ch]

  v5 = pPathIDToCopyFrom;
  FileInfo = CFileTracker::GetFileInfo(this, pFilename: (const char *)pRelativeFilename, pPathID: pPathIDToCopyFrom);
  pSourceInfo = FileInfo;
  if ( FileInfo != nullptr && (FileInfo->m_Flags & 8) != 0 )
    goto LABEL_9;
  v8 = CFileTracker::GetFileInfo(this, pFilename: (const char *)pRelativeFilename, pPathID: v5);
  if ( v8 != nullptr
    || (v9 = pPathIDToCopyFrom,
        CFileTracker::CalculateMissingCRC(
          this,
          pFilename: (const char *)pRelativeFilename,
          pPathID: (CFileInfo *)pPathIDToCopyFrom),
        (v8 = CFileTracker::GetFileInfo(this, pFilename: (const char *)pRelativeFilename, pPathID: v9)) != nullptr) )
  {
    if ( (v8->m_Flags & 8) == 0 )
    {
      v10 = (CFileInfo *)CUtlSymbol::String(this: &v8->m_pPathIDFileList->m_PathID);
      CFileTracker::CalculateMissingCRC(
        this,
        pFilename: v8->m_pPathIDFileList->m_Files.m_Elements.m_Tree.m_Elements.m_pMemory[v8->m_PathIDFileListDictIndex].m_Data.key,
        pPathID: v10);
    }
  }
  if ( (pSourceInfo->m_Flags & 8) != 0 )
  {
LABEL_9:
    PathIDFileList = CFileTracker::GetPathIDFileList(this, pPathID, bAutoAdd: 1);
    v12 = PathIDFileList;
    if ( pRelativeFilename == nullptr
      || (search.key = (const char *)pRelativeFilename,
          (v13 = CUtlRBTree<CUtlMap<char const *,CFileInfo *,int>::Node_t,int,CUtlMap<char const *,CFileInfo *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CFileInfo *,int>::Node_t,int>,int>>::Find(
                   this: &PathIDFileList->m_Files.m_Elements.m_Tree,
                   &search)) == -1)
      || (p_m_Id = &v12->m_Files.m_Elements.m_Tree.m_Elements.m_pMemory[v13].m_Data.elem->m_Flags) == nullptr )
    {
      v15 = (CPathIDFileList *)operator new(nSize: 0x14u);
      if ( v15 != nullptr )
      {
        v15->m_Files.m_Elements.m_Tree.m_Elements.m_nGrowSize = -1;
        v16 = v15;
      }
      else
      {
        v16 = nullptr;
      }
      pPathIDToCopyFrom = v16;
      v16->m_Files.m_Elements.m_Tree.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,CFileInfo *,int>::Node_t,int> *)v12;
      v16->m_Files.m_Elements.m_Tree.m_Elements.m_nAllocationCount = CUtlDict<CFileInfo *,int>::Insert(
                                                                       this: &v12->m_Files,
                                                                       pName: (char *)pRelativeFilename,
                                                                       element: (CFileInfo *const *)&pPathIDToCopyFrom);
      p_m_Id = &v16->m_PathID.m_Id;
    }
    p_m_Id[1] = pSourceInfo->m_CRC;
    *(_WORD *)p_m_Id = pSourceInfo->m_Flags;
  }
  else
  {
    CFileTracker::CacheFileCRC(this, pPathID, (const char *)pRelativeFilename);
  }
}

} // namespace dedicated

// ============================================================
// Overlay from FileSystem_Steam (Missing functions)
// ============================================================
namespace FileSystem_Steam {

//------------------------------------------------------------------------------
// Address: 0x100036A0
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class CUtlVector<class CStoreIDEntry,class CUtlMemory<class CStoreIDEntry,int>> __near *,int>::Node_t,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int>> *,int>::Node_t,int>,int>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int> > *,int>::Node_t,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int> > *,int>::Node_t,int> *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 2;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 24 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int> > *,int>::Node_t,int> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int> > *,int>::Node_t,int> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000A6F0
// Name: public: void CUtlDict<class CUtlVector<class CStoreIDEntry,class CUtlMemory<class CStoreIDEntry,int>> __near *,int>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int>> *,int>::PurgeAndDeleteElements(
        CUtlDict<CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int> > *,int> *this)
{
  int i; // edi
  CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int> > *elem; // esi
  bool v4; // sf
  CStoreIDEntry *m_pMemory; // eax

  for ( i = CUtlRBTree<CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int>> *,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int>> *,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
    elem = this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.elem;
    if ( elem != nullptr )
    {
      v4 = elem->m_Memory.m_nGrowSize < 0;
      elem->m_Size = 0;
      if ( !v4 )
      {
        if ( elem->m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: elem->m_Memory.m_pMemory);
          elem->m_Memory.m_pMemory = nullptr;
        }
        elem->m_Memory.m_nAllocationCount = 0;
      }
      v4 = elem->m_Memory.m_nGrowSize < 0;
      m_pMemory = elem->m_Memory.m_pMemory;
      elem->m_pElements = elem->m_Memory.m_pMemory;
      if ( !v4 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          elem->m_Memory.m_pMemory = nullptr;
        }
        elem->m_Memory.m_nAllocationCount = 0;
      }
      free(pMem: elem);
    }
  }
  CUtlRBTree<CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int>> *,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x1000B4D0
// Name: public: int CUtlMap<char const __near *,class CUtlVector<class CStoreIDEntry,class CUtlMemory<class CStoreIDEntry,int>> __near *,int>::Insert(char const __near * const __near &,class CUtlVector<class CStoreIDEntry,class CUtlMemory<class CStoreIDEntry,int>> __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int>> *,int>::Insert(
        CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int> > *,int> *this,
        const char **key,
        int insert)
{
  CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int> > *v4; // eax
  int v5; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int> > *,int>::Node_t,int> *m_pMemory; // ecx
  CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int> > *,int>::Node_t node; // [esp+8h] [ebp-8h] BYREF

  v4 = *(CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int> > **)insert;
  node.key = *key;
  node.elem = v4;
  insert = -1;
  LOBYTE(key) = 0;
  CUtlRBTree<CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int>> *,int>::Node_t,int>,int>>::FindInsertionPosition(
    this: &this->m_Tree,
    insert: &node,
    parent: &insert,
    leftchild: (bool *)&key);
  v5 = CUtlRBTree<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int,CUtlMap<char const *,CPathIDFileList *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int>,int>>::NewNode(this: &this->m_Tree);
  CUtlRBTree<CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int>> *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int>> *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int>> *,int>::Node_t,int>,int>>::LinkToParent(
    this: &this->m_Tree,
    i: v5,
    parent: insert,
    isLeft: (bool)key);
  m_pMemory = this->m_Tree.m_Elements.m_pMemory;
  ++this->m_Tree.m_NumElements;
  if ( &m_pMemory[v5] != (UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int> > *,int>::Node_t,int> *)-16 )
    m_pMemory[v5].m_Data = node;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1000EA80
// Name: public: int CUtlDict<class CUtlVector<class CStoreIDEntry,class CUtlMemory<class CStoreIDEntry,int>> __near *,int>::Insert(char const __near *,class CUtlVector<class CStoreIDEntry,class CUtlMemory<class CStoreIDEntry,int>> __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int>> *,int>::Insert(
        CUtlDict<CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int> > *,int> *this,
        char *pName,
        CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int> > *const *element)
{
  const char *v3; // edi
  char *v5; // eax

  v3 = pName;
  if ( pName != nullptr && (v5 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v5, v3);
  else
    v5 = nullptr;
  pName = v5;
  return CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int>> *,int>::Insert(
           this: &this->m_Elements,
           key: (const char **)&pName,
           insert: (int)element);
}

//------------------------------------------------------------------------------
// Address: 0x10015690
// Name: private: unsigned long CFileTracker::CalculateCRCForFile(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CFileTracker::CalculateCRCForFile(CFileTracker *this, void *fp)
{
  unsigned int v4; // eax
  IBaseFileSystem *v5; // ecx
  unsigned int v6; // eax
  int v7; // esi
  unsigned int v8; // ecx
  unsigned int v9; // eax
  bool v10; // zf
  int v11; // eax
  _BYTE pBuffer[32768]; // [esp+Ch] [ebp-8014h] BYREF
  int nBuffer; // [esp+800Ch] [ebp-14h]
  int v15; // [esp+8010h] [ebp-10h]
  unsigned int v16; // [esp+8014h] [ebp-Ch]
  int v17; // [esp+8018h] [ebp-8h]
  unsigned int pulCRC; // [esp+801Ch] [ebp-4h] BYREF
  int i; // [esp+8028h] [ebp+8h]

  v4 = this->m_pFileSystem->Tell(this: &this->m_pFileSystem->IBaseFileSystem, a2: fp);
  v5 = &this->m_pFileSystem->IBaseFileSystem;
  v15 = v4;
  v5->Seek(this: v5, a2: fp, a3: 0, a4: FILESYSTEM_SEEK_HEAD);
  CRC32_Init(&pulCRC);
  v6 = this->m_pFileSystem->Size_2(this: &this->m_pFileSystem->IBaseFileSystem, a2: fp);
  v7 = (v6 >> 15) + 1;
  v16 = v6;
  v17 = 0;
  if ( v6 >> 15 != -1 )
  {
    v8 = 0x8000;
    for ( i = 0x8000; ; v8 = i )
    {
      if ( v8 < v6 )
        v6 = v8;
      v9 = v6 - v8;
      v10 = v9 == -32768;
      v11 = v9 + 0x8000;
      nBuffer = v11;
      if ( v10 )
        break;
      this->m_pFileSystem->Read(this: &this->m_pFileSystem->IBaseFileSystem, a2: pBuffer, a3: v11, a4: fp);
      CRC32_ProcessBuffer(&pulCRC, pBuffer, nBuffer);
      i += 0x8000;
      if ( ++v17 >= v7 )
        break;
      v6 = v16;
    }
  }
  CRC32_Final(&pulCRC);
  this->m_pFileSystem->Seek(this: &this->m_pFileSystem->IBaseFileSystem, a2: fp, a3: v15, a4: FILESYSTEM_SEEK_HEAD);
  return pulCRC;
}

//------------------------------------------------------------------------------
// Address: 0x10017870
// Name: public: void CFileTracker::MarkAllCRCsVerified(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileTracker::MarkAllCRCsVerified(CFileTracker *this, bool bLockMutex)
{
  int m_Head; // eax
  UtlLinkedListElem_t<CFileInfo *,unsigned short> *m_pMemory; // ecx
  int v5; // eax
  UtlLinkedListElem_t<CFileInfo *,unsigned short> *v6; // ecx

  if ( bLockMutex )
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_Mutex);
  m_Head = this->m_NeedsVerificationList.m_Head;
  if ( m_Head != 0xFFFF )
  {
    m_pMemory = this->m_NeedsVerificationList.m_Memory.m_pMemory;
    do
    {
      v5 = (unsigned __int16)m_Head;
      m_pMemory[v5].m_Element->m_iNeedsVerificationListIndex = -1;
      m_pMemory = this->m_NeedsVerificationList.m_Memory.m_pMemory;
      m_Head = this->m_NeedsVerificationList.m_Memory.m_pMemory[v5].m_Next;
    }
    while ( m_Head != 0xFFFF );
  }
  CUtlLinkedList<CZip *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CZip *,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_NeedsVerificationList);
  if ( this->m_NeedsVerificationList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_NeedsVerificationList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_NeedsVerificationList.m_Memory.m_pMemory);
      this->m_NeedsVerificationList.m_Memory.m_pMemory = nullptr;
    }
    this->m_NeedsVerificationList.m_Memory.m_nAllocationCount = 0;
  }
  this->m_NeedsVerificationList.m_FirstFree = -1;
  v6 = this->m_NeedsVerificationList.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_NeedsVerificationList.m_NumAlloced = -65536;
  this->m_NeedsVerificationList.m_pElements = v6;
  if ( bLockMutex )
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_Mutex);
}

//------------------------------------------------------------------------------
// Address: 0x10017970
// Name: public: void CUtlDict<class CPathIDFileList __near *,int>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<CPathIDFileList *,int>::RemoveAll(CUtlDict<CPathIDFileList *,int> *this)
{
  int i; // esi

  for ( i = CUtlRBTree<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int,CUtlMap<char const *,CPathIDFileList *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int,CUtlMap<char const *,CPathIDFileList *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int,CUtlMap<char const *,CPathIDFileList *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x10017AA0
// Name: public: void CUtlDict<class CFileInfo __near *,int>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<CFileInfo *,int>::PurgeAndDeleteElements(CUtlDict<CFileInfo *,int> *this)
{
  int i; // edi
  CFileInfo *elem; // esi

  for ( i = CUtlRBTree<CUtlMap<char const *,CFileInfo *,int>::Node_t,int,CUtlMap<char const *,CFileInfo *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CFileInfo *,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,CFileInfo *,int>::Node_t,int,CUtlMap<char const *,CFileInfo *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CFileInfo *,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
    elem = this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.elem;
    if ( elem != nullptr )
      free(pMem: elem);
  }
  CUtlRBTree<CUtlMap<char const *,CFileInfo *,int>::Node_t,int,CUtlMap<char const *,CFileInfo *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CFileInfo *,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x10017B00
// Name: public: int CFileTracker::GetUnverifiedCRCFiles(class CUnverifiedCRCFile __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileTracker::GetUnverifiedCRCFiles(CFileTracker *this, CUnverifiedCRCFile *pFiles, int nMaxFiles)
{
  _RTL_CRITICAL_SECTION *p_m_Mutex; // esi
  int m_Head; // ecx
  int v6; // ebx
  CFileInfo *m_Element; // esi
  bool v8; // zf
  const char *v9; // eax
  unsigned int m_CRC; // eax
  int v11; // esi
  int iNext; // [esp+Ch] [ebp-10h]
  _RTL_CRITICAL_SECTION *generated_id_6; // [esp+10h] [ebp-Ch]
  int iOutFile; // [esp+14h] [ebp-8h]
  unsigned __int16 i; // [esp+18h] [ebp-4h]
  unsigned int *pFilesa; // [esp+24h] [ebp+8h]

  p_m_Mutex = (_RTL_CRITICAL_SECTION *)&this->m_Mutex;
  generated_id_6 = (_RTL_CRITICAL_SECTION *)&this->m_Mutex;
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_Mutex);
  m_Head = this->m_NeedsVerificationList.m_Head;
  iOutFile = 0;
  i = this->m_NeedsVerificationList.m_Head;
  if ( m_Head == 0xFFFF )
  {
LABEL_8:
    LeaveCriticalSection(lpCriticalSection: p_m_Mutex);
    return iOutFile;
  }
  else
  {
    pFilesa = &pFiles->m_CRC;
    while ( 1 )
    {
      v6 = (unsigned __int16)m_Head;
      m_Element = this->m_NeedsVerificationList.m_Memory.m_pMemory[v6].m_Element;
      iNext = this->m_NeedsVerificationList.m_Memory.m_pMemory[v6].m_Next;
      CUtlLinkedList<CFileInfo *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFileInfo *,unsigned short>,unsigned short>>::Unlink(
        this: &this->m_NeedsVerificationList,
        elem: m_Head);
      this->m_NeedsVerificationList.m_Memory.m_pMemory[v6].m_Next = this->m_NeedsVerificationList.m_FirstFree;
      this->m_NeedsVerificationList.m_FirstFree = i;
      v8 = (m_Element->m_Flags & 1) == 0;
      m_Element->m_iNeedsVerificationListIndex = -1;
      if ( v8 )
      {
        V_strncpy(
          pDest: (char *)pFilesa - 260,
          pSrc: m_Element->m_pPathIDFileList->m_Files.m_Elements.m_Tree.m_Elements.m_pMemory[m_Element->m_PathIDFileListDictIndex].m_Data.key,
          maxLen: 260);
        v9 = CUtlSymbol::String(this: &m_Element->m_pPathIDFileList->m_PathID);
        V_strncpy(pDest: (char *)pFilesa - 520, pSrc: v9, maxLen: 260);
        m_CRC = m_Element->m_CRC;
        v11 = iOutFile + 1;
        *pFilesa = m_CRC;
        iOutFile = v11;
        pFilesa += 131;
        if ( v11 >= nMaxFiles )
          break;
      }
      i = iNext;
      if ( iNext == 0xFFFF )
      {
        p_m_Mutex = generated_id_6;
        goto LABEL_8;
      }
      LOWORD(m_Head) = iNext;
    }
    LeaveCriticalSection(lpCriticalSection: generated_id_6);
    return v11;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10017C60
// Name: public: CFileTracker::CFileTracker(class CBaseFileSystem __near *)
// Source: json
//------------------------------------------------------------------------------
CFileTracker *__thiscall CFileTracker::CFileTracker(CFileTracker *this, CBaseFileSystem *pFileSystem)
{
  this->m_NeedsVerificationList.m_Memory.m_pMemory = nullptr;
  this->m_NeedsVerificationList.m_Memory.m_nAllocationCount = 0;
  this->m_NeedsVerificationList.m_Memory.m_nGrowSize = 0;
  this->m_NeedsVerificationList.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_NeedsVerificationList.m_FirstFree = 0xFFFF;
  this->m_NeedsVerificationList.m_pElements = this->m_NeedsVerificationList.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_NeedsVerificationList.m_Head = -1;
  this->m_NeedsVerificationList.m_NumAlloced = 0;
  this->m_PathIDs.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_PathIDs.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_PathIDs.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_PathIDs.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_PathIDs.m_Elements.m_Tree.m_Root = -1;
  this->m_PathIDs.m_Elements.m_Tree.m_NumElements = 0;
  this->m_PathIDs.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_PathIDs.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_PathIDs.m_Elements.m_Tree.m_pElements = this->m_PathIDs.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( this->m_PathIDs.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_PathIDs.m_Elements.m_Tree.m_LessFunc.m_LessFunc = CaselessStringLessThan;
  CThreadMutex::CThreadMutex(this: &this->m_Mutex);
  this->m_pFileSystem = pFileSystem;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10017CE0
// Name: public: int CFileTracker::GetFileInfos(class CFileInfo __near * __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileTracker::GetFileInfos(
        CFileTracker *this,
        CFileInfo **ppFileInfos,
        int nMaxFileInfos,
        const char *pFilename)
{
  _RTL_CRITICAL_SECTION *p_m_Mutex; // edi
  int Inorder; // esi
  CPathIDFileList *elem; // edi
  int v8; // eax
  CFileInfo *v9; // eax
  int v10; // ecx
  CUtlMap<char const *,CFileInfo *,int>::Node_t search; // [esp+Ch] [ebp-10h] BYREF
  CAutoLockT<CThreadMutex> generated_id_2; // [esp+14h] [ebp-8h]
  int nOut; // [esp+18h] [ebp-4h]

  p_m_Mutex = (_RTL_CRITICAL_SECTION *)&this->m_Mutex;
  generated_id_2.m_lock = &this->m_Mutex;
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_Mutex);
  nOut = 0;
  Inorder = CUtlRBTree<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int,CUtlMap<char const *,CPathIDFileList *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_PathIDs.m_Elements.m_Tree);
  if ( Inorder != -1 )
  {
    do
    {
      elem = this->m_PathIDs.m_Elements.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.elem;
      if ( pFilename != nullptr )
      {
        search.key = pFilename;
        v8 = CUtlRBTree<CUtlMap<char const *,CFileInfo *,int>::Node_t,int,CUtlMap<char const *,CFileInfo *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CFileInfo *,int>::Node_t,int>,int>>::Find(
               this: &elem->m_Files.m_Elements.m_Tree,
               &search);
        if ( v8 != -1 )
        {
          v9 = elem->m_Files.m_Elements.m_Tree.m_Elements.m_pMemory[v8].m_Data.elem;
          if ( v9 != nullptr )
          {
            v10 = nOut;
            if ( nOut < nMaxFileInfos )
            {
              ppFileInfos[nOut] = v9;
              nOut = v10 + 1;
            }
          }
        }
      }
      Inorder = CUtlRBTree<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int,CUtlMap<char const *,CPathIDFileList *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int>,int>>::NextInorder(
                  this: &this->m_PathIDs.m_Elements.m_Tree,
                  i: Inorder);
    }
    while ( Inorder != -1 );
    p_m_Mutex = (_RTL_CRITICAL_SECTION *)generated_id_2.m_lock;
  }
  LeaveCriticalSection(lpCriticalSection: p_m_Mutex);
  return nOut;
}

//------------------------------------------------------------------------------
// Address: 0x10017D80
// Name: public: void CFileTracker::MarkAllCRCsUnverified(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileTracker::MarkAllCRCsUnverified(CFileTracker *this)
{
  _RTL_CRITICAL_SECTION *p_m_Mutex; // edi
  int Inorder; // eax
  CPathIDFileList *elem; // edi
  int v5; // ebx
  unsigned __int16 v6; // ax
  int v7; // edi
  unsigned __int16 v8; // ax
  UtlLinkedListElem_t<CFileInfo *,unsigned short> *m_pMemory; // eax
  int v10; // ecx
  int m_Tail; // edx
  UtlLinkedListElem_t<CFileInfo *,unsigned short> *v12; // eax
  UtlLinkedListElem_t<CFileInfo *,unsigned short> *v13; // eax
  CThreadMutex *generated_id_5; // [esp+8h] [ebp-14h]
  CPathIDFileList *pPath; // [esp+Ch] [ebp-10h]
  int j; // [esp+10h] [ebp-Ch]
  CFileInfo *pInfo; // [esp+14h] [ebp-8h]
  int i; // [esp+18h] [ebp-4h]

  p_m_Mutex = (_RTL_CRITICAL_SECTION *)&this->m_Mutex;
  generated_id_5 = &this->m_Mutex;
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_Mutex);
  CFileTracker::MarkAllCRCsVerified(this, bLockMutex: true);
  Inorder = CUtlRBTree<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int,CUtlMap<char const *,CPathIDFileList *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_PathIDs.m_Elements.m_Tree);
  i = Inorder;
  if ( Inorder != -1 )
  {
    while ( 1 )
    {
      elem = this->m_PathIDs.m_Elements.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.elem;
      pPath = elem;
      v5 = CUtlRBTree<CUtlMap<char const *,CFileInfo *,int>::Node_t,int,CUtlMap<char const *,CFileInfo *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CFileInfo *,int>::Node_t,int>,int>>::FirstInorder(this: &elem->m_Files.m_Elements.m_Tree);
      for ( j = v5; v5 != -1; j = v5 )
      {
        pInfo = elem->m_Files.m_Elements.m_Tree.m_Elements.m_pMemory[v5].m_Data.elem;
        if ( (pInfo->m_Flags & 1) == 0 && (pInfo->m_Flags & 2) != 0 )
        {
          v6 = CUtlLinkedList<CFileInfo *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFileInfo *,unsigned short>,unsigned short>>::AllocInternal(
                 this: &this->m_NeedsVerificationList,
                 multilist: false);
          v7 = v6;
          if ( v6 == 0xFFFF )
          {
            v8 = -1;
          }
          else
          {
            CUtlLinkedList<CFileInfo *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFileInfo *,unsigned short>,unsigned short>>::Unlink(
              this: &this->m_NeedsVerificationList,
              elem: v6);
            m_pMemory = this->m_NeedsVerificationList.m_Memory.m_pMemory;
            v10 = v7;
            m_pMemory[v10].m_Next = -1;
            m_Tail = this->m_NeedsVerificationList.m_Tail;
            m_pMemory[v10].m_Previous = m_Tail;
            this->m_NeedsVerificationList.m_Tail = v7;
            if ( (_WORD)m_Tail == 0xFFFF )
              this->m_NeedsVerificationList.m_Head = v7;
            else
              this->m_NeedsVerificationList.m_Memory.m_pMemory[m_Tail].m_Next = v7;
            v12 = this->m_NeedsVerificationList.m_Memory.m_pMemory;
            ++this->m_NeedsVerificationList.m_ElementCount;
            v13 = &v12[v10];
            if ( v13 != nullptr )
              v13->m_Element = pInfo;
            v5 = j;
            v8 = v7;
          }
          elem = pPath;
          pInfo->m_iNeedsVerificationListIndex = v8;
        }
        v5 = CUtlRBTree<CUtlMap<char const *,CFileInfo *,int>::Node_t,int,CUtlMap<char const *,CFileInfo *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CFileInfo *,int>::Node_t,int>,int>>::NextInorder(
               this: &elem->m_Files.m_Elements.m_Tree,
               i: v5);
      }
      i = CUtlRBTree<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int,CUtlMap<char const *,CPathIDFileList *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int>,int>>::NextInorder(
            this: &this->m_PathIDs.m_Elements.m_Tree,
            i);
      if ( i == -1 )
        break;
      Inorder = i;
    }
    p_m_Mutex = (_RTL_CRITICAL_SECTION *)generated_id_5;
  }
  LeaveCriticalSection(lpCriticalSection: p_m_Mutex);
}

//------------------------------------------------------------------------------
// Address: 0x10017EC0
// Name: public: CPathIDFileList::CPathIDFileList(void)
// Source: json
//------------------------------------------------------------------------------
CPathIDFileList *__thiscall CPathIDFileList::CPathIDFileList(CPathIDFileList *this)
{
  CPathIDFileList *result; // eax
  UtlLinkedListElem_t<CFileInfo *,int> *m_pMemory; // edx

  result = this;
  this->m_PathID.m_Id = -1;
  this->m_Files.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_Files.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_Files.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_Files.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_Files.m_Elements.m_Tree.m_Root = -1;
  this->m_Files.m_Elements.m_Tree.m_NumElements = 0;
  this->m_Files.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_Files.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_Files.m_Elements.m_Tree.m_pElements = this->m_Files.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( this->m_Files.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_Files.m_Elements.m_Tree.m_LessFunc.m_LessFunc = CaselessStringLessThanIgnoreSlashes;
  this->m_UnverifiedCRCFiles.m_Memory.m_pMemory = nullptr;
  this->m_UnverifiedCRCFiles.m_Memory.m_nAllocationCount = 0;
  this->m_UnverifiedCRCFiles.m_Memory.m_nGrowSize = 0;
  this->m_UnverifiedCRCFiles.m_LastAlloc.index = -1;
  this->m_UnverifiedCRCFiles.m_Head = -1;
  this->m_UnverifiedCRCFiles.m_Tail = -1;
  this->m_UnverifiedCRCFiles.m_FirstFree = -1;
  m_pMemory = this->m_UnverifiedCRCFiles.m_Memory.m_pMemory;
  this->m_UnverifiedCRCFiles.m_ElementCount = 0;
  this->m_UnverifiedCRCFiles.m_NumAlloced = 0;
  this->m_UnverifiedCRCFiles.m_pElements = m_pMemory;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10017F20
// Name: public: int CUtlMap<char const __near *,class CFileInfo __near *,int>::Insert(char const __near * const __near &,class CFileInfo __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlMap<char const *,CFileInfo *,int>::Insert(
        CUtlMap<char const *,CFileInfo *,int> *this,
        const char **key,
        int insert)
{
  CFileInfo *v4; // eax
  int v5; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CFileInfo *,int>::Node_t,int> *m_pMemory; // ecx
  CUtlMap<char const *,CFileInfo *,int>::Node_t node; // [esp+8h] [ebp-8h] BYREF

  v4 = *(CFileInfo **)insert;
  node.key = *key;
  node.elem = v4;
  insert = -1;
  LOBYTE(key) = 0;
  CUtlRBTree<CUtlMap<char const *,CFileInfo *,int>::Node_t,int,CUtlMap<char const *,CFileInfo *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CFileInfo *,int>::Node_t,int>,int>>::FindInsertionPosition(
    this: &this->m_Tree,
    insert: &node,
    parent: &insert,
    leftchild: (bool *)&key);
  v5 = CUtlRBTree<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int,CUtlMap<char const *,CPathIDFileList *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int>,int>>::NewNode((CUtlRBTree<CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int> > *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int> > *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int> > *,int>::Node_t,int>,int> > *)this);
  CUtlRBTree<CUtlMap<char const *,CFileInfo *,int>::Node_t,int,CUtlMap<char const *,CFileInfo *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CFileInfo *,int>::Node_t,int>,int>>::LinkToParent(
    this: &this->m_Tree,
    i: v5,
    parent: insert,
    isLeft: (bool)key);
  m_pMemory = this->m_Tree.m_Elements.m_pMemory;
  ++this->m_Tree.m_NumElements;
  if ( &m_pMemory[v5] != (UtlRBTreeNode_t<CUtlMap<char const *,CFileInfo *,int>::Node_t,int> *)-16 )
    m_pMemory[v5].m_Data = node;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10017FA0
// Name: public: int CUtlMap<char const __near *,class CPathIDFileList __near *,int>::Insert(char const __near * const __near &,class CPathIDFileList __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlMap<char const *,CPathIDFileList *,int>::Insert(
        CUtlMap<char const *,CPathIDFileList *,int> *this,
        const char **key,
        int insert)
{
  CPathIDFileList *v4; // eax
  int v5; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int> *m_pMemory; // ecx
  CUtlMap<char const *,CPathIDFileList *,int>::Node_t node; // [esp+8h] [ebp-8h] BYREF

  v4 = *(CPathIDFileList **)insert;
  node.key = *key;
  node.elem = v4;
  insert = -1;
  LOBYTE(key) = 0;
  CUtlRBTree<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int,CUtlMap<char const *,CPathIDFileList *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int>,int>>::FindInsertionPosition(
    this: &this->m_Tree,
    insert: &node,
    parent: &insert,
    leftchild: (bool *)&key);
  v5 = CUtlRBTree<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int,CUtlMap<char const *,CPathIDFileList *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int>,int>>::NewNode((CUtlRBTree<CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int> > *,int>::Node_t,int,CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int> > *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlVector<CStoreIDEntry,CUtlMemory<CStoreIDEntry,int> > *,int>::Node_t,int>,int> > *)this);
  CUtlRBTree<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int,CUtlMap<char const *,CPathIDFileList *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int>,int>>::LinkToParent(
    this: &this->m_Tree,
    i: v5,
    parent: insert,
    isLeft: (bool)key);
  m_pMemory = this->m_Tree.m_Elements.m_pMemory;
  ++this->m_Tree.m_NumElements;
  if ( &m_pMemory[v5] != (UtlRBTreeNode_t<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int> *)-16 )
    m_pMemory[v5].m_Data = node;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10018020
// Name: public: int CUtlDict<class CFileInfo __near *,int>::Insert(char const __near *,class CFileInfo __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<CFileInfo *,int>::Insert(
        CUtlDict<CFileInfo *,int> *this,
        char *pName,
        CFileInfo *const *element)
{
  const char *v3; // edi
  char *v5; // eax

  v3 = pName;
  if ( pName != nullptr && (v5 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v5, v3);
  else
    v5 = nullptr;
  pName = v5;
  return CUtlMap<char const *,CFileInfo *,int>::Insert(
           this: &this->m_Elements,
           key: (const char **)&pName,
           insert: (int)element);
}

//------------------------------------------------------------------------------
// Address: 0x10018080
// Name: public: int CUtlDict<class CPathIDFileList __near *,int>::Insert(char const __near *,class CPathIDFileList __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<CPathIDFileList *,int>::Insert(
        CUtlDict<CPathIDFileList *,int> *this,
        char *pName,
        CPathIDFileList *const *element)
{
  const char *v3; // edi
  char *v5; // eax

  v3 = pName;
  if ( pName != nullptr && (v5 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v5, v3);
  else
    v5 = nullptr;
  pName = v5;
  return CUtlMap<char const *,CPathIDFileList *,int>::Insert(
           this: &this->m_Elements,
           key: (const char **)&pName,
           insert: (int)element);
}

//------------------------------------------------------------------------------
// Address: 0x100180E0
// Name: public: void CUtlDict<class CPathIDFileList __near *,int>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<CPathIDFileList *,int>::PurgeAndDeleteElements(CUtlDict<CPathIDFileList *,int> *this)
{
  CUtlDict<CPathIDFileList *,int> *v1; // edi
  int Inorder; // eax
  int v3; // esi
  CPathIDFileList *elem; // edi
  CUtlRBTree<CUtlMap<char const *,CFileInfo *,int>::Node_t,int,CUtlMap<char const *,CFileInfo *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CFileInfo *,int>::Node_t,int>,int> > *p_m_Tree; // esi
  int i; // edi
  CPathIDFileList *pMem; // [esp+4h] [ebp-Ch]
  int index; // [esp+Ch] [ebp-4h]

  v1 = this;
  Inorder = CUtlRBTree<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int,CUtlMap<char const *,CPathIDFileList *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
  index = Inorder;
  if ( Inorder != -1 )
  {
    while ( 1 )
    {
      v3 = Inorder;
      _g_pMemAlloc->Free_2(
        this: _g_pMemAlloc,
        a2: (void *)v1->m_Elements.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.key);
      elem = v1->m_Elements.m_Tree.m_Elements.m_pMemory[v3].m_Data.elem;
      pMem = elem;
      if ( elem != nullptr )
      {
        p_m_Tree = &elem->m_Files.m_Elements.m_Tree;
        CUtlDict<CFileInfo *,int>::PurgeAndDeleteElements(this: &elem->m_Files);
        CUtlLinkedList<CFileInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileInfo *,int>,int>>::RemoveAll(this: &elem->m_UnverifiedCRCFiles);
        if ( elem->m_UnverifiedCRCFiles.m_Memory.m_nGrowSize >= 0 )
        {
          if ( elem->m_UnverifiedCRCFiles.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: elem->m_UnverifiedCRCFiles.m_Memory.m_pMemory);
            elem->m_UnverifiedCRCFiles.m_Memory.m_pMemory = nullptr;
          }
          elem->m_UnverifiedCRCFiles.m_Memory.m_nAllocationCount = 0;
        }
        for ( i = CUtlRBTree<CUtlMap<char const *,CFileInfo *,int>::Node_t,int,CUtlMap<char const *,CFileInfo *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CFileInfo *,int>::Node_t,int>,int>>::FirstInorder(this: &elem->m_Files.m_Elements.m_Tree);
              i != -1;
              i = CUtlRBTree<CUtlMap<char const *,CFileInfo *,int>::Node_t,int,CUtlMap<char const *,CFileInfo *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CFileInfo *,int>::Node_t,int>,int>>::NextInorder(
                    this: p_m_Tree,
                    i) )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)p_m_Tree->m_Elements.m_pMemory[i].m_Data.key);
        }
        CUtlRBTree<CUtlMap<char const *,CFileInfo *,int>::Node_t,int,CUtlMap<char const *,CFileInfo *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CFileInfo *,int>::Node_t,int>,int>>::RemoveAll(this: p_m_Tree);
        CUtlRBTree<CUtlMap<char const *,CFileInfo *,int>::Node_t,int,CUtlMap<char const *,CFileInfo *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CFileInfo *,int>::Node_t,int>,int>>::RemoveAll(this: p_m_Tree);
        p_m_Tree->m_FirstFree = -1;
        if ( p_m_Tree->m_Elements.m_nGrowSize >= 0 )
        {
          if ( p_m_Tree->m_Elements.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_Tree->m_Elements.m_pMemory);
            p_m_Tree->m_Elements.m_pMemory = nullptr;
          }
          p_m_Tree->m_Elements.m_nAllocationCount = 0;
        }
        p_m_Tree->m_LastAlloc.index = -1;
        if ( p_m_Tree->m_Elements.m_nGrowSize >= 0 )
        {
          if ( p_m_Tree->m_Elements.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_Tree->m_Elements.m_pMemory);
            p_m_Tree->m_Elements.m_pMemory = nullptr;
          }
          p_m_Tree->m_Elements.m_nAllocationCount = 0;
        }
        free(pMem);
      }
      v1 = this;
      index = CUtlRBTree<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int,CUtlMap<char const *,CPathIDFileList *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int>,int>>::NextInorder(
                this: &this->m_Elements.m_Tree,
                i: index);
      if ( index == -1 )
        break;
      Inorder = index;
    }
  }
  CUtlRBTree<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int,CUtlMap<char const *,CPathIDFileList *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int>,int>>::RemoveAll(this: &v1->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x10018240
// Name: private: class CPathIDFileList __near * CFileTracker::GetPathIDFileList(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CPathIDFileList *__thiscall CFileTracker::GetPathIDFileList(CFileTracker *this, CPathIDFileList *pPathID, int bAutoAdd)
{
  _RTL_CRITICAL_SECTION *p_m_Mutex; // ebx
  char *v5; // edi
  int v6; // eax
  CPathIDFileList *v7; // eax
  char *v8; // esi
  CPathIDFileList *elem; // esi
  CUtlMap<char const *,CPathIDFileList *,int>::Node_t search; // [esp+Ch] [ebp-Ch] BYREF
  CUtlDict<CPathIDFileList *,int> *p_m_PathIDs; // [esp+14h] [ebp-4h]

  p_m_Mutex = (_RTL_CRITICAL_SECTION *)&this->m_Mutex;
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_Mutex);
  v5 = (char *)pPathID;
  if ( pPathID == nullptr )
    v5 = (char *)setName;
  search.key = v5;
  p_m_PathIDs = &this->m_PathIDs;
  v6 = CUtlRBTree<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int,CUtlMap<char const *,CPathIDFileList *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int>,int>>::Find(
         this: &this->m_PathIDs.m_Elements.m_Tree,
         &search);
  if ( v6 == -1 )
  {
    if ( (_BYTE)bAutoAdd != 0 )
    {
      v7 = (CPathIDFileList *)operator new(nSize: 0x50u);
      if ( v7 != nullptr )
        v8 = (char *)CPathIDFileList::CPathIDFileList(this: v7);
      else
        v8 = nullptr;
      pPathID = (CPathIDFileList *)v8;
      CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&bAutoAdd + 1, pStr: v5);
      *(_WORD *)v8 = HIWORD(bAutoAdd);
      CUtlDict<CPathIDFileList *,int>::Insert(this: p_m_PathIDs, pName: v5, element: &pPathID);
      LeaveCriticalSection(lpCriticalSection: p_m_Mutex);
      return (CPathIDFileList *)v8;
    }
    else
    {
      LeaveCriticalSection(lpCriticalSection: p_m_Mutex);
      return nullptr;
    }
  }
  else
  {
    elem = this->m_PathIDs.m_Elements.m_Tree.m_Elements.m_pMemory[v6].m_Data.elem;
    LeaveCriticalSection(lpCriticalSection: p_m_Mutex);
    return elem;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018300
// Name: public: CFileTracker::~CFileTracker(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileTracker::~CFileTracker(CFileTracker *this)
{
  _RTL_CRITICAL_SECTION *p_m_Mutex; // edi

  p_m_Mutex = (_RTL_CRITICAL_SECTION *)&this->m_Mutex;
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_Mutex);
  CUtlDict<CPathIDFileList *,int>::PurgeAndDeleteElements(this: &this->m_PathIDs);
  LeaveCriticalSection(lpCriticalSection: p_m_Mutex);
  CThreadMutex::~CThreadMutex(this: (CThreadMutex *)p_m_Mutex);
  CUtlDict<CPathIDFileList *,int>::RemoveAll(this: &this->m_PathIDs);
  CUtlRBTree<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int,CUtlMap<char const *,CPathIDFileList *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int,CUtlMap<char const *,CPathIDFileList *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int>,int>>(this: &this->m_PathIDs.m_Elements.m_Tree);
  CUtlLinkedList<CZip *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CZip *,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_NeedsVerificationList);
  if ( this->m_NeedsVerificationList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_NeedsVerificationList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_NeedsVerificationList.m_Memory.m_pMemory);
      this->m_NeedsVerificationList.m_Memory.m_pMemory = nullptr;
    }
    this->m_NeedsVerificationList.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018370
// Name: public: void CFileTracker::NoteFileLoadedFromDisk(char const __near *,char const __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileTracker::NoteFileLoadedFromDisk(CFileTracker *this, char *pFilename, char *pPathID, void *fp)
{
  char *v5; // esi
  CPathIDFileList *PathIDFileList; // ebx
  const char *v7; // eax
  int v8; // eax
  CFileInfo *elem; // ebx
  char *v10; // eax
  char *v11; // esi
  CUtlDict<CFileInfo *,int> *p_m_Files; // ecx
  unsigned int v13; // eax
  bool v14; // zf
  unsigned __int16 v15; // ax
  int v16; // esi
  unsigned __int16 v17; // ax
  UtlLinkedListElem_t<CFileInfo *,unsigned short> *v18; // eax
  CUtlMap<char const *,CFileInfo *,int>::Node_t search; // [esp+Ch] [ebp-10h] BYREF
  CPathIDFileList *pPath; // [esp+14h] [ebp-8h]
  CAutoLockT<CThreadMutex> generated_id_0; // [esp+18h] [ebp-4h]

  generated_id_0.m_lock = &this->m_Mutex;
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_Mutex);
  v5 = pPathID;
  if ( pPathID == nullptr )
    v5 = (char *)setName;
  PathIDFileList = CFileTracker::GetPathIDFileList(this, pPathID: (CPathIDFileList *)v5, bAutoAdd: 1);
  v7 = pFilename;
  pPath = PathIDFileList;
  if ( pFilename == nullptr )
    goto LABEL_6;
  search.key = pFilename;
  v8 = CUtlRBTree<CUtlMap<char const *,CFileInfo *,int>::Node_t,int,CUtlMap<char const *,CFileInfo *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CFileInfo *,int>::Node_t,int>,int>>::Find(
         this: &PathIDFileList->m_Files.m_Elements.m_Tree,
         &search);
  if ( v8 == -1 )
  {
    v7 = pFilename;
LABEL_6:
    elem = nullptr;
    goto LABEL_8;
  }
  elem = PathIDFileList->m_Files.m_Elements.m_Tree.m_Elements.m_pMemory[v8].m_Data.elem;
  v7 = pFilename;
LABEL_8:
  if ( (this->m_pFileSystem->m_WhitelistSpewFlags & 1) != 0 )
  {
    if ( elem == nullptr )
    {
      _Warning(a1: "(Unique   ): [%s]\\%s", v5, v7);
      goto LABEL_14;
    }
    _Warning(a1: "(Duplicate): [%s]\\%s", v5, v7);
  }
  if ( elem != nullptr )
  {
    elem->m_Flags &= 8u;
    goto LABEL_18;
  }
LABEL_14:
  v10 = (char *)operator new(nSize: 0x14u);
  if ( v10 != nullptr )
  {
    *((_DWORD *)v10 + 4) = -1;
    v11 = v10;
  }
  else
  {
    v11 = nullptr;
  }
  p_m_Files = &pPath->m_Files;
  pPathID = v11;
  *((_DWORD *)v11 + 2) = pPath;
  *((_DWORD *)v11 + 3) = CUtlDict<CFileInfo *,int>::Insert(
                           this: p_m_Files,
                           pName: pFilename,
                           element: (CFileInfo *const *)&pPathID);
  elem = (CFileInfo *)v11;
  *(_WORD *)v11 = 0;
LABEL_18:
  if ( fp != nullptr )
  {
    v13 = CFileTracker::CalculateCRCForFile(this, fp);
    elem->m_Flags |= 0xAu;
    v14 = elem->m_iNeedsVerificationListIndex == -1;
    elem->m_CRC = v13;
    if ( v14 )
    {
      v15 = CUtlLinkedList<CFileInfo *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFileInfo *,unsigned short>,unsigned short>>::AllocInternal(
              this: &this->m_NeedsVerificationList,
              multilist: false);
      v16 = v15;
      if ( v15 == 0xFFFF )
      {
        v17 = -1;
      }
      else
      {
        CUtlLinkedList<CZip *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CZip *,unsigned short>,unsigned short>>::LinkBefore(
          this: &this->m_NeedsVerificationList,
          before: 0xFFFFu,
          elem: v15);
        v18 = &this->m_NeedsVerificationList.m_Memory.m_pMemory[v16];
        if ( v18 != nullptr )
          v18->m_Element = elem;
        v17 = v16;
      }
      elem->m_iNeedsVerificationListIndex = v17;
    }
    if ( (this->m_pFileSystem->m_WhitelistSpewFlags & 1) != 0 )
      _Warning(a1: " - %lu\n", elem->m_CRC);
  }
  else if ( (this->m_pFileSystem->m_WhitelistSpewFlags & 1) != 0 )
  {
    _Warning(a1: "\n");
  }
  LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)generated_id_0.m_lock);
}

//------------------------------------------------------------------------------
// Address: 0x10018500
// Name: public: void CFileTracker::NoteFileFailedToLoad(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileTracker::NoteFileFailedToLoad(CFileTracker *this, const char *pFilename, CPathIDFileList *pPathID)
{
  CPathIDFileList *PathIDFileList; // esi
  int v4; // eax
  CFileInfo *elem; // eax
  CUtlMap<char const *,CFileInfo *,int>::Node_t search; // [esp+4h] [ebp-8h] BYREF

  PathIDFileList = CFileTracker::GetPathIDFileList(this, pPathID, bAutoAdd: 1);
  if ( pFilename != nullptr )
  {
    search.key = pFilename;
    v4 = CUtlRBTree<CUtlMap<char const *,CFileInfo *,int>::Node_t,int,CUtlMap<char const *,CFileInfo *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CFileInfo *,int>::Node_t,int>,int>>::Find(
           this: &PathIDFileList->m_Files.m_Elements.m_Tree,
           &search);
    if ( v4 != -1 )
    {
      elem = PathIDFileList->m_Files.m_Elements.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem;
      if ( elem != nullptr )
        elem->m_Flags |= 0x10u;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018550
// Name: public: class CFileInfo __near * CFileTracker::GetFileInfo(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CFileInfo *__thiscall CFileTracker::GetFileInfo(CFileTracker *this, const char *pFilename, CPathIDFileList *pPathID)
{
  _RTL_CRITICAL_SECTION *p_m_Mutex; // esi
  const char *elem; // eax
  int v6; // eax
  CPathIDFileList *v8; // edi
  int v9; // eax
  CFileInfo *v10; // edi
  CUtlMap<char const *,CPathIDFileList *,int>::Node_t search; // [esp+Ch] [ebp-8h] BYREF

  p_m_Mutex = (_RTL_CRITICAL_SECTION *)&this->m_Mutex;
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_Mutex);
  search.elem = pPathID;
  EnterCriticalSection(lpCriticalSection: p_m_Mutex);
  elem = setName;
  if ( pPathID != nullptr )
    elem = (const char *)search.elem;
  search.key = elem;
  v6 = CUtlRBTree<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int,CUtlMap<char const *,CPathIDFileList *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int>,int>>::Find(
         this: &this->m_PathIDs.m_Elements.m_Tree,
         &search);
  if ( v6 == -1 )
  {
    LeaveCriticalSection(lpCriticalSection: p_m_Mutex);
    LeaveCriticalSection(lpCriticalSection: p_m_Mutex);
    return nullptr;
  }
  else
  {
    v8 = this->m_PathIDs.m_Elements.m_Tree.m_Elements.m_pMemory[v6].m_Data.elem;
    LeaveCriticalSection(lpCriticalSection: p_m_Mutex);
    if ( v8 != nullptr
      && pFilename != nullptr
      && (search.key = pFilename,
          (v9 = CUtlRBTree<CUtlMap<char const *,CFileInfo *,int>::Node_t,int,CUtlMap<char const *,CFileInfo *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CFileInfo *,int>::Node_t,int>,int>>::Find(
                  this: &v8->m_Files.m_Elements.m_Tree,
                  (const CUtlMap<char const *,CFileInfo *,int>::Node_t *)&search)) != -1) )
    {
      v10 = v8->m_Files.m_Elements.m_Tree.m_Elements.m_pMemory[v9].m_Data.elem;
      LeaveCriticalSection(lpCriticalSection: p_m_Mutex);
      return v10;
    }
    else
    {
      LeaveCriticalSection(lpCriticalSection: p_m_Mutex);
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018610
// Name: public: void CFileTracker::NoteFileLoadedFromSteam(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileTracker::NoteFileLoadedFromSteam(
        CFileTracker *this,
        char *pFilename,
        char *pPathID,
        bool bForcedLoadFromSteam)
{
  CPathIDFileList *PathIDFileList; // eax
  char *v6; // ebx
  CPathIDFileList *v7; // esi
  int v8; // eax
  char *elem; // edi
  char *v10; // eax
  bool v11; // zf
  CUtlMap<char const *,CFileInfo *,int>::Node_t search; // [esp+Ch] [ebp-10h] BYREF
  CAutoLockT<CThreadMutex> generated_id_3; // [esp+14h] [ebp-8h]
  CFileTracker *v14; // [esp+18h] [ebp-4h]

  v14 = this;
  generated_id_3.m_lock = &this->m_Mutex;
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_Mutex);
  if ( pPathID == nullptr )
    pPathID = (char *)setName;
  PathIDFileList = CFileTracker::GetPathIDFileList(this, (CPathIDFileList *)pPathID, bAutoAdd: 1);
  v6 = pFilename;
  v7 = PathIDFileList;
  if ( pFilename == nullptr
    || (search.key = pFilename,
        (v8 = CUtlRBTree<CUtlMap<char const *,CFileInfo *,int>::Node_t,int,CUtlMap<char const *,CFileInfo *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CFileInfo *,int>::Node_t,int>,int>>::Find(
                this: &PathIDFileList->m_Files.m_Elements.m_Tree,
                &search)) == -1)
    || (elem = (char *)v7->m_Files.m_Elements.m_Tree.m_Elements.m_pMemory[v8].m_Data.elem) == nullptr )
  {
    v10 = (char *)operator new(nSize: 0x14u);
    if ( v10 != nullptr )
    {
      *((_DWORD *)v10 + 4) = -1;
      elem = v10;
    }
    else
    {
      elem = nullptr;
    }
    pFilename = elem;
    *((_DWORD *)elem + 2) = v7;
    *((_DWORD *)elem + 3) = CUtlDict<CFileInfo *,int>::Insert(
                              this: &v7->m_Files,
                              pName: v6,
                              element: (CFileInfo *const *)&pFilename);
  }
  if ( (v14->m_pFileSystem->m_WhitelistSpewFlags & 1) != 0 )
    _Warning(a1: "From Steam: [%s]\\%s\n", pPathID, v6);
  v11 = !bForcedLoadFromSteam;
  *(_WORD *)elem = 1;
  if ( !v11 )
    *(_WORD *)elem = 5;
  LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)generated_id_3.m_lock);
}

//------------------------------------------------------------------------------
// Address: 0x100186F0
// Name: public: enum EFileCRCStatus CFileTracker::CheckCachedFileCRC(char const __near *,char const __near *,unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileTracker::CheckCachedFileCRC(
        CFileTracker *this,
        CPathIDFileList *pPathID,
        const char *pRelativeFilename,
        unsigned int *pCRC)
{
  CFileInfo *FileInfo; // eax

  FileInfo = CFileTracker::GetFileInfo(this, pFilename: pRelativeFilename, pPathID);
  if ( FileInfo == nullptr || (FileInfo->m_Flags & 8) == 0 )
    return 0;
  *pCRC = FileInfo->m_CRC;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10018720
// Name: private: void CFileTracker::CalculateMissingCRC(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileTracker::CalculateMissingCRC(CFileTracker *this, const char *pFilename, CFileInfo *pPathID)
{
  CFileHandle *v3; // ebx
  CFileInfo *FileInfo; // eax
  CFileInfo *v6; // esi
  CFileHandle *FileInSearchPaths; // ebx
  int nOldFlags; // [esp+Ch] [ebp-4h]

  v3 = (CFileHandle *)pPathID;
  nOldFlags = -1;
  FileInfo = CFileTracker::GetFileInfo(this, pFilename, (CPathIDFileList *)pPathID);
  v6 = FileInfo;
  pPathID = FileInfo;
  if ( FileInfo != nullptr )
    nOldFlags = FileInfo->m_Flags;
  FileInSearchPaths = CBaseFileSystem::FindFileInSearchPaths(
                        this: this->m_pFileSystem,
                        pFileName: pFilename,
                        pOptions: "rb",
                        pathID: v3,
                        flags: 2u,
                        ppszResolvedFilename: nullptr,
                        bTrackCRCs: true);
  if ( FileInSearchPaths != nullptr )
  {
    if ( v6 != nullptr )
    {
      if ( nOldFlags != -1 )
        v6->m_Flags = nOldFlags;
      EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_Mutex);
      if ( (v6->m_Flags & 2) == 0 )
      {
        v6->m_CRC = CFileTracker::CalculateCRCForFile(this, fp: FileInSearchPaths);
        v6->m_Flags |= 0xAu;
        if ( v6->m_iNeedsVerificationListIndex == -1 )
          v6->m_iNeedsVerificationListIndex = (unsigned __int16)CUtlLinkedList<CFileInfo *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFileInfo *,unsigned short>,unsigned short>>::AddToTail(
                                                                  this: &this->m_NeedsVerificationList,
                                                                  src: &pPathID);
      }
      LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_Mutex);
    }
    this->m_pFileSystem->Close(this: &this->m_pFileSystem->IBaseFileSystem, a2: FileInSearchPaths);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100187D0
// Name: public: void CFileTracker::CalculateMissingCRCs(class IFileList __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileTracker::CalculateMissingCRCs(CFileTracker *this, IFileList *pWantCRCList)
{
  CFileTracker *v2; // ebx
  int m_Head; // edi
  int Inorder; // eax
  int v5; // edi
  CFileInfo *elem; // ebx
  int v7; // eax
  int v8; // esi
  UtlLinkedListElem_t<CFileInfo *,int> *m_pMemory; // edx
  UtlLinkedListElem_t<CFileInfo *,int> *v10; // eax
  int m_Tail; // ecx
  int j; // eax
  int v13; // eax
  CFileInfo *m_Element; // esi
  UtlLinkedListElem_t<CFileInfo *,int> *v15; // edi
  CFileInfo *v16; // eax
  CUtlLinkedList<CFileInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileInfo *,int>,int> > needCRCList; // [esp+Ch] [ebp-34h] BYREF
  CFileTracker *v18; // [esp+34h] [ebp-Ch]
  CPathIDFileList *pPath; // [esp+38h] [ebp-8h]
  int i; // [esp+3Ch] [ebp-4h]

  v2 = this;
  v18 = this;
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_Mutex);
  m_Head = -1;
  memset(&needCRCList, 0, 12);
  needCRCList.m_LastAlloc.index = -1;
  memset(&needCRCList.m_Head, 255, 12);
  needCRCList.m_ElementCount = 0;
  needCRCList.m_NumAlloced = 0;
  needCRCList.m_pElements = nullptr;
  Inorder = CUtlRBTree<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int,CUtlMap<char const *,CPathIDFileList *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int>,int>>::FirstInorder(this: &v2->m_PathIDs.m_Elements.m_Tree);
  i = Inorder;
  if ( Inorder != -1 )
  {
    while ( 1 )
    {
      pPath = v2->m_PathIDs.m_Elements.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.elem;
      v5 = CUtlRBTree<CUtlMap<char const *,CFileInfo *,int>::Node_t,int,CUtlMap<char const *,CFileInfo *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CFileInfo *,int>::Node_t,int>,int>>::FirstInorder(this: &pPath->m_Files.m_Elements.m_Tree);
      if ( v5 != -1 )
      {
        do
        {
          elem = pPath->m_Files.m_Elements.m_Tree.m_Elements.m_pMemory[v5].m_Data.elem;
          if ( (elem->m_Flags & 3) == 0
            && pWantCRCList->IsFileInList(
                 this: pWantCRCList,
                 a2: elem->m_pPathIDFileList->m_Files.m_Elements.m_Tree.m_Elements.m_pMemory[elem->m_PathIDFileListDictIndex].m_Data.key) != 0 )
          {
            v7 = CUtlLinkedList<CFileInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileInfo *,int>,int>>::AllocInternal(
                   this: &needCRCList,
                   multilist: false);
            v8 = v7;
            if ( v7 != -1 )
            {
              CUtlLinkedList<CFileInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileInfo *,int>,int>>::Unlink(
                this: &needCRCList,
                elem: v7);
              m_pMemory = needCRCList.m_Memory.m_pMemory;
              v10 = &needCRCList.m_Memory.m_pMemory[v8];
              m_Tail = needCRCList.m_Tail;
              v10->m_Next = -1;
              v10->m_Previous = m_Tail;
              needCRCList.m_Tail = v8;
              if ( m_Tail == -1 )
                needCRCList.m_Head = v8;
              else
                m_pMemory[m_Tail].m_Next = v8;
              ++needCRCList.m_ElementCount;
              if ( v10 != nullptr )
                v10->m_Element = elem;
            }
          }
          v5 = CUtlRBTree<CUtlMap<char const *,CFileInfo *,int>::Node_t,int,CUtlMap<char const *,CFileInfo *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CFileInfo *,int>::Node_t,int>,int>>::NextInorder(
                 this: &pPath->m_Files.m_Elements.m_Tree,
                 i: v5);
        }
        while ( v5 != -1 );
        v2 = v18;
      }
      i = CUtlRBTree<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int,CUtlMap<char const *,CPathIDFileList *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPathIDFileList *,int>::Node_t,int>,int>>::NextInorder(
            this: &v2->m_PathIDs.m_Elements.m_Tree,
            i);
      if ( i == -1 )
        break;
      Inorder = i;
    }
    m_Head = needCRCList.m_Head;
  }
  LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&v2->m_Mutex);
  for ( j = m_Head; j != -1; j = v15->m_Next )
  {
    v13 = j;
    m_Element = needCRCList.m_Memory.m_pMemory[v13].m_Element;
    v15 = &needCRCList.m_Memory.m_pMemory[v13];
    v16 = (CFileInfo *)CUtlSymbol::String(this: &m_Element->m_pPathIDFileList->m_PathID);
    CFileTracker::CalculateMissingCRC(
      this: v2,
      pFilename: m_Element->m_pPathIDFileList->m_Files.m_Elements.m_Tree.m_Elements.m_pMemory[m_Element->m_PathIDFileListDictIndex].m_Data.key,
      pPathID: v16);
  }
  CUtlLinkedList<CFileInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileInfo *,int>,int>>::RemoveAll(this: &needCRCList);
  if ( needCRCList.m_Memory.m_nGrowSize >= 0 && needCRCList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: needCRCList.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10018980
// Name: public: void CFileTracker::CacheFileCRC(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileTracker::CacheFileCRC(CFileTracker *this, CPathIDFileList *pPathID, const char *pRelativeFilename)
{
  CFileInfo *FileInfo; // esi
  CFileInfo *v5; // eax

  FileInfo = CFileTracker::GetFileInfo(this, pFilename: pRelativeFilename, pPathID);
  if ( FileInfo != nullptr
    || (CFileTracker::CalculateMissingCRC(this, pFilename: pRelativeFilename, (CFileInfo *)pPathID),
        (FileInfo = CFileTracker::GetFileInfo(this, pFilename: pRelativeFilename, pPathID)) != nullptr) )
  {
    if ( (FileInfo->m_Flags & 8) == 0 )
    {
      v5 = (CFileInfo *)CUtlSymbol::String(this: &FileInfo->m_pPathIDFileList->m_PathID);
      CFileTracker::CalculateMissingCRC(
        this,
        pFilename: FileInfo->m_pPathIDFileList->m_Files.m_Elements.m_Tree.m_Elements.m_pMemory[FileInfo->m_PathIDFileListDictIndex].m_Data.key,
        pPathID: v5);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100189F0
// Name: public: void CFileTracker::CacheFileCRC_Copy(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileTracker::CacheFileCRC_Copy(
        CFileTracker *this,
        CPathIDFileList *pPathID,
        CFileInfo *pRelativeFilename,
        CPathIDFileList *pPathIDToCopyFrom)
{
  CPathIDFileList *v5; // edi
  CFileInfo *FileInfo; // eax
  CFileInfo *v8; // edi
  CPathIDFileList *v9; // edi
  CFileInfo *v10; // eax
  CPathIDFileList *PathIDFileList; // eax
  CPathIDFileList *v12; // esi
  int v13; // eax
  _DWORD *p_m_Id; // eax
  CPathIDFileList *v15; // eax
  CPathIDFileList *v16; // edi
  CUtlMap<char const *,CFileInfo *,int>::Node_t search; // [esp+Ch] [ebp-8h] BYREF
  CFileInfo *pSourceInfo; // [esp+20h] [ebp+Ch]

  v5 = pPathIDToCopyFrom;
  FileInfo = CFileTracker::GetFileInfo(this, pFilename: (const char *)pRelativeFilename, pPathID: pPathIDToCopyFrom);
  pSourceInfo = FileInfo;
  if ( FileInfo != nullptr && (FileInfo->m_Flags & 8) != 0 )
    goto LABEL_9;
  v8 = CFileTracker::GetFileInfo(this, pFilename: (const char *)pRelativeFilename, pPathID: v5);
  if ( v8 != nullptr
    || (v9 = pPathIDToCopyFrom,
        CFileTracker::CalculateMissingCRC(
          this,
          pFilename: (const char *)pRelativeFilename,
          pPathID: (CFileInfo *)pPathIDToCopyFrom),
        (v8 = CFileTracker::GetFileInfo(this, pFilename: (const char *)pRelativeFilename, pPathID: v9)) != nullptr) )
  {
    if ( (v8->m_Flags & 8) == 0 )
    {
      v10 = (CFileInfo *)CUtlSymbol::String(this: &v8->m_pPathIDFileList->m_PathID);
      CFileTracker::CalculateMissingCRC(
        this,
        pFilename: v8->m_pPathIDFileList->m_Files.m_Elements.m_Tree.m_Elements.m_pMemory[v8->m_PathIDFileListDictIndex].m_Data.key,
        pPathID: v10);
    }
  }
  if ( (pSourceInfo->m_Flags & 8) != 0 )
  {
LABEL_9:
    PathIDFileList = CFileTracker::GetPathIDFileList(this, pPathID, bAutoAdd: 1);
    v12 = PathIDFileList;
    if ( pRelativeFilename == nullptr
      || (search.key = (const char *)pRelativeFilename,
          (v13 = CUtlRBTree<CUtlMap<char const *,CFileInfo *,int>::Node_t,int,CUtlMap<char const *,CFileInfo *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CFileInfo *,int>::Node_t,int>,int>>::Find(
                   this: &PathIDFileList->m_Files.m_Elements.m_Tree,
                   &search)) == -1)
      || (p_m_Id = &v12->m_Files.m_Elements.m_Tree.m_Elements.m_pMemory[v13].m_Data.elem->m_Flags) == nullptr )
    {
      v15 = (CPathIDFileList *)operator new(nSize: 0x14u);
      if ( v15 != nullptr )
      {
        v15->m_Files.m_Elements.m_Tree.m_Elements.m_nGrowSize = -1;
        v16 = v15;
      }
      else
      {
        v16 = nullptr;
      }
      pPathIDToCopyFrom = v16;
      v16->m_Files.m_Elements.m_Tree.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,CFileInfo *,int>::Node_t,int> *)v12;
      v16->m_Files.m_Elements.m_Tree.m_Elements.m_nAllocationCount = CUtlDict<CFileInfo *,int>::Insert(
                                                                       this: &v12->m_Files,
                                                                       pName: (char *)pRelativeFilename,
                                                                       element: (CFileInfo *const *)&pPathIDToCopyFrom);
      p_m_Id = &v16->m_PathID.m_Id;
    }
    p_m_Id[1] = pSourceInfo->m_CRC;
    *(_WORD *)p_m_Id = pSourceInfo->m_Flags;
  }
  else
  {
    CFileTracker::CacheFileCRC(this, pPathID, (const char *)pRelativeFilename);
  }
}

} // namespace FileSystem_Steam
