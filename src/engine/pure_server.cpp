// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/pure_server.cpp
// Functions: 30
// ============================================================

#include "engine\pure_server.h"

//------------------------------------------------------------------------------
// Address: 0x10010E00
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CSaveRestore::RestoreLookupTable,int>::Node_t,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSaveRestore::RestoreLookupTable,int>::Node_t,int>,int>::Grow(
        CUtlMemory<SndInfo_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  SndInfo_t *m_pMemory; // edx
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
        m_nAllocationCount = 1;
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
    v7 = 52 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (SndInfo_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (SndInfo_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CC510
// Name: IsProtectedBySvPure2
// Source: json
//------------------------------------------------------------------------------
char __cdecl IsProtectedBySvPure2(char *pFilename)
{
  const char *v1; // edi
  unsigned int v2; // esi
  char v3; // al
  char tempStr[512]; // [esp+Ch] [ebp-204h] BYREF
  unsigned int v6; // [esp+20Ch] [ebp-4h]

  v6 = 0;
  while ( 1 )
  {
    v1 = g_SvPure2_ProtectedDirs[v6 / 4];
    v2 = _V_strlen(str: v1);
    if ( _V_strlen(str: pFilename) < (int)(v2 + 1) )
      return 0;
    memcpy(dst: (unsigned __int8 *)tempStr, src: (unsigned __int8 *)pFilename, count: v2);
    tempStr[v2] = 0;
    if ( _V_stricmp(s1: tempStr, s2: v1) == 0 )
    {
      v3 = pFilename[v2];
      if ( v3 == 47 || v3 == 92 )
        break;
    }
    v6 += 4;
    if ( v6 >= 0xC )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101CC5A0
// Name: public: bool CPureServerWhitelist::IsInFullyPureMode(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPureServerWhitelist::IsInFullyPureMode(CPureServerWhitelist *this)
{
  return this->m_bFullyPureMode;
}

//------------------------------------------------------------------------------
// Address: 0x101CC5B0
// Name: private: void CPureServerWhitelist::PrintCommand(char const __near *,char const __near *,int,class CPureServerWhitelist::CCommand __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPureServerWhitelist::PrintCommand(
        CPureServerWhitelist *this,
        const char *pFileSpec,
        const char *pExt,
        int maxPathnameLen,
        CPureServerWhitelist::CCommand *pCommand)
{
  int v5; // eax
  char *v6; // ecx
  int v7; // eax
  int v8; // edi
  char tempFileSpec[260]; // [esp+8h] [ebp-104h] BYREF

  V_strncpy(pDest: tempFileSpec, pSrc: pFileSpec, maxLen: 260);
  v5 = _V_strlen(str: tempFileSpec);
  if ( v5 > 0 )
  {
    v6 = &tempFileSpec[v5 - 1];
    if ( tempFileSpec[v5 - 1] == 47 || *v6 == 92 )
      *v6 = 0;
  }
  if ( pExt != nullptr )
    _Msg(a1: "%s%c%s", tempFileSpec, 92, pExt);
  else
    _Msg(a1: "%s", tempFileSpec);
  v7 = _V_strlen(str: pFileSpec);
  if ( v7 < maxPathnameLen + 6 )
  {
    v8 = maxPathnameLen + 6 - v7;
    do
    {
      _Msg(a1: " ");
      --v8;
    }
    while ( v8 != 0 );
  }
  _Msg(a1: "\t");
  if ( pCommand->m_bAllowFromDisk )
  {
    if ( pCommand->m_bCheckCRC )
      _Msg(a1: "allow_from_disk+check_crc");
    else
      _Msg(a1: "allow_from_disk");
  }
  else
  {
    _Msg(a1: "from_steam");
  }
  _Msg(a1: "\n");
}

//------------------------------------------------------------------------------
// Address: 0x101CC6A0
// Name: public: class IFileList __near * CPureServerWhitelist::GetAllowFromDiskList(void)
// Source: json
//------------------------------------------------------------------------------
CPureServerWhitelist::CAllowFromDiskList *__thiscall CPureServerWhitelist::GetAllowFromDiskList(
        CPureServerWhitelist *this)
{
  ++this->m_RefCount;
  return &this->m_AllowFromDiskList;
}

//------------------------------------------------------------------------------
// Address: 0x101CC6B0
// Name: public: class IFileList __near * CPureServerWhitelist::GetForceMatchList(void)
// Source: json
//------------------------------------------------------------------------------
CPureServerWhitelist::CForceMatchList *__thiscall CPureServerWhitelist::GetForceMatchList(CPureServerWhitelist *this)
{
  ++this->m_RefCount;
  return &this->m_ForceMatchList;
}

//------------------------------------------------------------------------------
// Address: 0x101CD570
// Name: public: void CUtlDict<class CPureServerWhitelist::CCommand __near *,int>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<CPureServerWhitelist::CCommand *,int>::RemoveAll(
        CUtlDict<CPureServerWhitelist::CCommand *,int> *this)
{
  int i; // esi

  for ( i = CUtlRBTree<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int,CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int,CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int,CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x101CD5C0
// Name: public: void CUtlDict<class CPureServerWhitelist::CCommand __near *,int>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<CPureServerWhitelist::CCommand *,int>::PurgeAndDeleteElements(
        CUtlDict<CPureServerWhitelist::CCommand *,int> *this)
{
  int i; // edi
  CPureServerWhitelist::CCommand *elem; // esi

  for ( i = CUtlRBTree<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int,CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int,CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
    elem = this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.elem;
    if ( elem != nullptr )
      free(pMem: elem);
  }
  CUtlRBTree<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int,CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x101CD620
// Name: public: void CPureServerWhitelist::EnableFullyPureMode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPureServerWhitelist::EnableFullyPureMode(CPureServerWhitelist *this)
{
  CUtlDict<CPureServerWhitelist::CCommand *,int>::PurgeAndDeleteElements(this: &this->m_FileCommands);
  CUtlDict<CPureServerWhitelist::CCommand *,int>::PurgeAndDeleteElements(this: &this->m_RecursiveDirCommands);
  CUtlDict<CPureServerWhitelist::CCommand *,int>::PurgeAndDeleteElements(this: &this->m_NonRecursiveDirCommands);
  this->m_bFullyPureMode = true;
}

//------------------------------------------------------------------------------
// Address: 0x101CD650
// Name: private: void CPureServerWhitelist::UpdateCommandStats(class CUtlDict<class CPureServerWhitelist::CCommand __near *,int> __near &,int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPureServerWhitelist::UpdateCommandStats(
        CPureServerWhitelist *this,
        CUtlDict<CPureServerWhitelist::CCommand *,int> *commands,
        int *pHighest,
        int *pLongestPathName)
{
  int i; // esi
  int m_LoadOrder; // ecx
  int v6; // eax

  for ( i = CUtlRBTree<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int,CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int>,int>>::FirstInorder(this: &commands->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int,CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int>,int>>::NextInorder(
              this: &commands->m_Elements.m_Tree,
              i) )
  {
    m_LoadOrder = commands->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.elem->m_LoadOrder;
    if ( *pHighest > m_LoadOrder )
      m_LoadOrder = *pHighest;
    *pHighest = m_LoadOrder;
    v6 = _V_strlen(str: commands->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
    if ( *pLongestPathName > v6 )
      v6 = *pLongestPathName;
    *pLongestPathName = v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CD6D0
// Name: private: int CPureServerWhitelist::FindCommandByLoadOrder(class CUtlDict<class CPureServerWhitelist::CCommand __near *,int> __near &,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPureServerWhitelist::FindCommandByLoadOrder(
        CPureServerWhitelist *this,
        CUtlDict<CPureServerWhitelist::CCommand *,int> *commands,
        int iLoadOrder)
{
  int result; // eax

  result = CUtlRBTree<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int,CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int>,int>>::FirstInorder(this: &commands->m_Elements.m_Tree);
  if ( result == -1 )
    return -1;
  while ( commands->m_Elements.m_Tree.m_Elements.m_pMemory[result].m_Data.elem->m_LoadOrder != iLoadOrder )
  {
    result = CUtlRBTree<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int,CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int>,int>>::NextInorder(
               this: &commands->m_Elements.m_Tree,
               i: result);
    if ( result == -1 )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101CD720
// Name: public: void CPureServerWhitelist::PrintWhitelistContents(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPureServerWhitelist::PrintWhitelistContents(CPureServerWhitelist *this)
{
  int v2; // edi
  CUtlDict<CPureServerWhitelist::CCommand *,int> *p_m_FileCommands; // ebx
  int Inorder; // eax
  int v5; // eax
  int CommandByLoadOrder; // eax
  int highestLoadOrder; // [esp+Ch] [ebp-8h] BYREF
  int longestPathName; // [esp+10h] [ebp-4h] BYREF

  v2 = 0;
  p_m_FileCommands = &this->m_FileCommands;
  highestLoadOrder = 0;
  longestPathName = 0;
  CPureServerWhitelist::UpdateCommandStats(
    this,
    commands: &this->m_FileCommands,
    pHighest: &highestLoadOrder,
    pLongestPathName: &longestPathName);
  CPureServerWhitelist::UpdateCommandStats(
    this,
    commands: &this->m_RecursiveDirCommands,
    pHighest: &highestLoadOrder,
    pLongestPathName: &longestPathName);
  CPureServerWhitelist::UpdateCommandStats(
    this,
    commands: &this->m_NonRecursiveDirCommands,
    pHighest: &highestLoadOrder,
    pLongestPathName: &longestPathName);
  if ( highestLoadOrder >= 0 )
  {
    do
    {
      Inorder = CUtlRBTree<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int,CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int>,int>>::FirstInorder(this: &p_m_FileCommands->m_Elements.m_Tree);
      if ( Inorder == -1 )
      {
LABEL_5:
        v5 = CUtlRBTree<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int,CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_RecursiveDirCommands.m_Elements.m_Tree);
        if ( v5 == -1 )
        {
LABEL_8:
          CommandByLoadOrder = CPureServerWhitelist::FindCommandByLoadOrder(
                                 this,
                                 commands: &this->m_NonRecursiveDirCommands,
                                 iLoadOrder: v2);
          if ( CommandByLoadOrder != -1 )
            CPureServerWhitelist::PrintCommand(
              this,
              pFileSpec: this->m_NonRecursiveDirCommands.m_Elements.m_Tree.m_Elements.m_pMemory[CommandByLoadOrder].m_Data.key,
              pExt: "*.*",
              maxPathnameLen: longestPathName,
              pCommand: this->m_NonRecursiveDirCommands.m_Elements.m_Tree.m_Elements.m_pMemory[CommandByLoadOrder].m_Data.elem);
        }
        else
        {
          while ( this->m_RecursiveDirCommands.m_Elements.m_Tree.m_Elements.m_pMemory[v5].m_Data.elem->m_LoadOrder != v2 )
          {
            v5 = CUtlRBTree<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int,CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int>,int>>::NextInorder(
                   this: &this->m_RecursiveDirCommands.m_Elements.m_Tree,
                   i: v5);
            if ( v5 == -1 )
              goto LABEL_8;
          }
          CPureServerWhitelist::PrintCommand(
            this,
            pFileSpec: this->m_RecursiveDirCommands.m_Elements.m_Tree.m_Elements.m_pMemory[v5].m_Data.key,
            pExt: "...",
            maxPathnameLen: longestPathName,
            pCommand: this->m_RecursiveDirCommands.m_Elements.m_Tree.m_Elements.m_pMemory[v5].m_Data.elem);
        }
      }
      else
      {
        while ( p_m_FileCommands->m_Elements.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.elem->m_LoadOrder != v2 )
        {
          Inorder = CUtlRBTree<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int,CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int>,int>>::NextInorder(
                      this: &p_m_FileCommands->m_Elements.m_Tree,
                      i: Inorder);
          if ( Inorder == -1 )
            goto LABEL_5;
        }
        CPureServerWhitelist::PrintCommand(
          this,
          pFileSpec: this->m_FileCommands.m_Elements.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.key,
          pExt: nullptr,
          maxPathnameLen: longestPathName,
          pCommand: this->m_FileCommands.m_Elements.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.elem);
      }
      ++v2;
    }
    while ( v2 <= highestLoadOrder );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CD860
// Name: private: void CPureServerWhitelist::EncodeCommandList(class CUtlDict<class CPureServerWhitelist::CCommand __near *,int> __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPureServerWhitelist::EncodeCommandList(
        CPureServerWhitelist *this,
        CUtlDict<CPureServerWhitelist::CCommand *,int> *theList,
        CUtlBuffer *buf)
{
  CUtlDict<CPureServerWhitelist::CCommand *,int> *v4; // edi
  int Inorder; // eax
  int v6; // eax
  CPureServerWhitelist::CCommand *elem; // edi
  unsigned __int8 m_bAllowFromDisk; // bl
  unsigned __int16 m_LoadOrder; // bx
  int m_NumElements; // [esp-4h] [ebp-14h]
  int v11; // [esp+8h] [ebp-8h]
  __int16 inputBuffer[2]; // [esp+Ch] [ebp-4h] BYREF
  int i; // [esp+1Ch] [ebp+Ch]

  v4 = theList;
  m_NumElements = theList->m_Elements.m_Tree.m_NumElements;
  if ( (buf->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: buf, pFmt: "%d", m_NumElements);
  else
    CUtlBuffer::PutTypeBin<int>(this: buf, src: m_NumElements);
  Inorder = CUtlRBTree<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int,CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int>,int>>::FirstInorder(this: &theList->m_Elements.m_Tree);
  i = Inorder;
  if ( Inorder != -1 )
  {
    while ( 1 )
    {
      v6 = Inorder;
      elem = v4->m_Elements.m_Tree.m_Elements.m_pMemory[v6].m_Data.elem;
      v11 = v6 * 24;
      m_bAllowFromDisk = elem->m_bAllowFromDisk;
      if ( elem->m_bCheckCRC )
        m_bAllowFromDisk |= 2u;
      if ( (buf->m_Flags & 1) != 0 )
      {
        CUtlBuffer::Printf(this: buf, pFmt: "%hu", m_bAllowFromDisk);
      }
      else if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
      {
        buf->m_Memory.m_pMemory[buf->m_Put++ - buf->m_nOffset] = m_bAllowFromDisk;
        CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
      }
      m_LoadOrder = elem->m_LoadOrder;
      if ( (buf->m_Flags & 1) != 0 )
      {
        CUtlBuffer::Printf(this: buf, pFmt: "%hu", elem->m_LoadOrder);
      }
      else
      {
        *(_DWORD *)inputBuffer = elem->m_LoadOrder;
        if ( CUtlBuffer::CheckPut(this: buf, nSize: 2) )
        {
          if ( (*(_BYTE *)&buf->m_Byteswap & 1) != 0 )
            CByteswap::SwapBufferToTargetEndian<unsigned short>(
              this: &buf->m_Byteswap,
              outputBuffer: &buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset],
              inputBuffer,
              count: 1);
          else
            *(_WORD *)&buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = m_LoadOrder;
          buf->m_Put += 2;
          CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
        }
      }
      v4 = theList;
      CUtlBuffer::PutString(
        this: buf,
        pString: *(const char **)((char *)&theList->m_Elements.m_Tree.m_Elements.m_pMemory->m_Data.key + v11));
      i = CUtlRBTree<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int,CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int>,int>>::NextInorder(
            this: &theList->m_Elements.m_Tree,
            i);
      if ( i == -1 )
        break;
      Inorder = i;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CD9C0
// Name: private: void CPureServerWhitelist::InternalCacheFileCRCs(class CUtlDict<class CPureServerWhitelist::CCommand __near *,int> __near &,enum ECacheCRCType)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPureServerWhitelist::InternalCacheFileCRCs(
        CPureServerWhitelist *this,
        CUtlDict<CPureServerWhitelist::CCommand *,int> *theList,
        ECacheCRCType eType)
{
  CPureServerWhitelist *v3; // ebx
  int i; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int> *v5; // eax

  v3 = this;
  for ( i = CUtlRBTree<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int,CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int>,int>>::FirstInorder(this: &theList->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int,CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int>,int>>::NextInorder(
              this: &theList->m_Elements.m_Tree,
              i) )
  {
    v5 = &theList->m_Elements.m_Tree.m_Elements.m_pMemory[i];
    if ( v5->m_Data.elem->m_bCheckCRC )
    {
      v3->m_pFileSystem->CacheFileCRCs(
        this: v3->m_pFileSystem,
        a2: v5->m_Data.key,
        a3: eType,
        a4: &v3->m_ForceMatchList);
      v3 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CDA30
// Name: private: class CPureServerWhitelist::CCommand __near * CPureServerWhitelist::CheckEntry(class CUtlDict<class CPureServerWhitelist::CCommand __near *,int> __near &,char const __near *,class CPureServerWhitelist::CCommand __near *)
// Source: json
//------------------------------------------------------------------------------
CPureServerWhitelist::CCommand *__thiscall CPureServerWhitelist::CheckEntry(
        CPureServerWhitelist *this,
        CUtlDict<CPureServerWhitelist::CCommand *,int> *dict,
        const char *pEntryName,
        CPureServerWhitelist::CCommand *pBestEntry)
{
  int v4; // eax
  CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t search; // [esp+0h] [ebp-8h] BYREF

  if ( pEntryName == nullptr )
    return pBestEntry;
  search.key = pEntryName;
  v4 = CUtlRBTree<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int,CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int>,int>>::Find(
         this: &dict->m_Elements.m_Tree,
         &search);
  if ( v4 == -1 )
    return pBestEntry;
  if ( pBestEntry != nullptr
    && dict->m_Elements.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem->m_LoadOrder <= pBestEntry->m_LoadOrder )
  {
    return pBestEntry;
  }
  return dict->m_Elements.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem;
}

//------------------------------------------------------------------------------
// Address: 0x101CDAA0
// Name: private: CPureServerWhitelist::CPureServerWhitelist(void)
// Source: json
//------------------------------------------------------------------------------
CPureServerWhitelist *__thiscall CPureServerWhitelist::CPureServerWhitelist(CPureServerWhitelist *this)
{
  CPureServerWhitelist *result; // eax

  result = this;
  this->m_FileCommands.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_FileCommands.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_FileCommands.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_FileCommands.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_FileCommands.m_Elements.m_Tree.m_Root = -1;
  this->m_FileCommands.m_Elements.m_Tree.m_NumElements = 0;
  this->m_FileCommands.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_FileCommands.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_FileCommands.m_Elements.m_Tree.m_pElements = this->m_FileCommands.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( this->m_FileCommands.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_FileCommands.m_Elements.m_Tree.m_LessFunc.m_LessFunc = CaselessStringLessThan;
  this->m_RecursiveDirCommands.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_RecursiveDirCommands.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_RecursiveDirCommands.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_RecursiveDirCommands.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_RecursiveDirCommands.m_Elements.m_Tree.m_Root = -1;
  this->m_RecursiveDirCommands.m_Elements.m_Tree.m_NumElements = 0;
  this->m_RecursiveDirCommands.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_RecursiveDirCommands.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_RecursiveDirCommands.m_Elements.m_Tree.m_pElements = this->m_RecursiveDirCommands.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( this->m_RecursiveDirCommands.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_RecursiveDirCommands.m_Elements.m_Tree.m_LessFunc.m_LessFunc = CaselessStringLessThan;
  this->m_NonRecursiveDirCommands.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_NonRecursiveDirCommands.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_NonRecursiveDirCommands.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_NonRecursiveDirCommands.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_NonRecursiveDirCommands.m_Elements.m_Tree.m_Root = -1;
  this->m_NonRecursiveDirCommands.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_NonRecursiveDirCommands.m_Elements.m_Tree.m_NumElements = 0;
  this->m_NonRecursiveDirCommands.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_NonRecursiveDirCommands.m_Elements.m_Tree.m_pElements = this->m_NonRecursiveDirCommands.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( this->m_NonRecursiveDirCommands.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_NonRecursiveDirCommands.m_Elements.m_Tree.m_LessFunc.m_LessFunc = CaselessStringLessThan;
  this->m_AllowFromDiskList.__vftable = (CPureServerWhitelist::CAllowFromDiskList_vtbl *)&CPureServerWhitelist::CAllowFromDiskList::`vftable';
  this->m_ForceMatchList.__vftable = (CPureServerWhitelist::CForceMatchList_vtbl *)&CPureServerWhitelist::CForceMatchList::`vftable';
  this->m_pFileSystem = nullptr;
  this->m_LoadCounter = 0;
  this->m_AllowFromDiskList.m_pWhitelist = this;
  this->m_ForceMatchList.m_pWhitelist = this;
  this->m_RefCount = 1;
  this->m_bFullyPureMode = false;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101CDB60
// Name: private: CPureServerWhitelist::~CPureServerWhitelist(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPureServerWhitelist::~CPureServerWhitelist(CPureServerWhitelist *this)
{
  CPureServerWhitelist *v1; // esi
  CUtlDict<CPureServerWhitelist::CCommand *,int> *p_m_FileCommands; // edi
  CUtlDict<CPureServerWhitelist::CCommand *,int> *p_m_RecursiveDirCommands; // ebx

  v1 = this;
  p_m_FileCommands = &this->m_FileCommands;
  CUtlDict<CPureServerWhitelist::CCommand *,int>::PurgeAndDeleteElements(this: &this->m_FileCommands);
  p_m_RecursiveDirCommands = &v1->m_RecursiveDirCommands;
  CUtlDict<CPureServerWhitelist::CCommand *,int>::PurgeAndDeleteElements(this: &v1->m_RecursiveDirCommands);
  CUtlDict<CPureServerWhitelist::CCommand *,int>::PurgeAndDeleteElements(this: &v1->m_NonRecursiveDirCommands);
  v1->m_pFileSystem = nullptr;
  v1->m_LoadCounter = 0;
  v1 = (CPureServerWhitelist *)((char *)v1 + 80);
  CUtlDict<CPureServerWhitelist::CCommand *,int>::RemoveAll(this: (CUtlDict<CPureServerWhitelist::CCommand *,int> *)v1);
  CUtlRBTree<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int,CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int,CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int>,int>>(this: (CUtlRBTree<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int,CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int>,int> > *)v1);
  CUtlDict<CPureServerWhitelist::CCommand *,int>::RemoveAll(this: p_m_RecursiveDirCommands);
  CUtlRBTree<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int,CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int,CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int>,int>>(this: &p_m_RecursiveDirCommands->m_Elements.m_Tree);
  CUtlDict<CPureServerWhitelist::CCommand *,int>::RemoveAll(this: p_m_FileCommands);
  CUtlRBTree<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int,CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int,CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int>,int>>(this: &p_m_FileCommands->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x101CDBD0
// Name: public: void CPureServerWhitelist::Encode(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPureServerWhitelist::Encode(CPureServerWhitelist *this, CUtlBuffer *buf)
{
  bool m_bFullyPureMode; // bl
  int m_Put; // eax

  CPureServerWhitelist::EncodeCommandList(this, theList: &this->m_FileCommands, buf);
  CPureServerWhitelist::EncodeCommandList(this, theList: &this->m_RecursiveDirCommands, buf);
  CPureServerWhitelist::EncodeCommandList(this, theList: &this->m_NonRecursiveDirCommands, buf);
  m_bFullyPureMode = this->m_bFullyPureMode;
  if ( (buf->m_Flags & 1) != 0 )
  {
    m_Put = buf->m_Put;
    if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: buf);
  }
  if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
  {
    buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = m_bFullyPureMode;
    CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CDC60
// Name: public: void CPureServerWhitelist::CacheFileCRCs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPureServerWhitelist::CacheFileCRCs(CPureServerWhitelist *this)
{
  CPureServerWhitelist::InternalCacheFileCRCs(this, theList: &this->m_FileCommands, eType: k_eCacheCRCType_SingleFile);
  CPureServerWhitelist::InternalCacheFileCRCs(
    this,
    theList: &this->m_NonRecursiveDirCommands,
    eType: k_eCacheCRCType_Directory);
  CPureServerWhitelist::InternalCacheFileCRCs(
    this,
    theList: &this->m_RecursiveDirCommands,
    eType: k_eCacheCRCType_Directory_Recursive);
}

//------------------------------------------------------------------------------
// Address: 0x101CDC90
// Name: private: class CPureServerWhitelist::CCommand __near * CPureServerWhitelist::GetBestEntry(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CPureServerWhitelist::CCommand *__thiscall CPureServerWhitelist::GetBestEntry(
        CPureServerWhitelist *this,
        const char *pFilename)
{
  CPureServerWhitelist::CCommand *v4; // eax
  CPureServerWhitelist::CCommand *elem; // esi
  int v6; // eax
  char relativeFilename[260]; // [esp+8h] [ebp-210h] BYREF
  char relativeDir[260]; // [esp+10Ch] [ebp-10Ch] BYREF
  CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t search; // [esp+210h] [ebp-8h] BYREF

  V_strncpy(pDest: relativeFilename, pSrc: pFilename, maxLen: 260);
  if ( V_IsAbsolutePath(pStr: relativeFilename)
    && !this->m_pFileSystem->FullPathToRelativePath(
          this: this->m_pFileSystem,
          a2: pFilename,
          a3: relativeFilename,
          a4: 260) )
  {
    return nullptr;
  }
  V_FixSlashes(pname: relativeFilename, separator: 92);
  if ( !V_ExtractFilePath(path: relativeFilename, dest: relativeDir, destSize: 260) )
    relativeDir[0] = 0;
  v4 = CPureServerWhitelist::CheckEntry(
         this,
         dict: &this->m_FileCommands,
         pEntryName: relativeFilename,
         pBestEntry: nullptr);
  elem = v4;
  if ( relativeDir[0] != 0 )
  {
    elem = CPureServerWhitelist::CheckEntry(
             this,
             dict: &this->m_NonRecursiveDirCommands,
             pEntryName: relativeDir,
             pBestEntry: v4);
    if ( relativeDir[0] != 0 )
    {
      do
      {
        search.key = relativeDir;
        v6 = CUtlRBTree<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int,CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int>,int>>::Find(
               this: &this->m_RecursiveDirCommands.m_Elements.m_Tree,
               &search);
        if ( v6 != -1
          && (elem == nullptr
           || this->m_RecursiveDirCommands.m_Elements.m_Tree.m_Elements.m_pMemory[v6].m_Data.elem->m_LoadOrder > elem->m_LoadOrder) )
        {
          elem = this->m_RecursiveDirCommands.m_Elements.m_Tree.m_Elements.m_pMemory[v6].m_Data.elem;
        }
      }
      while ( V_StripLastDir(dirName: relativeDir, maxlen: 260) && relativeDir[0] != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x101CDDD0
// Name: public: virtual bool CPureServerWhitelist::CAllowFromDiskList::IsFileInList(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CPureServerWhitelist::CAllowFromDiskList::IsFileInList(
        CPureServerWhitelist::CAllowFromDiskList *this,
        const char *pFilename)
{
  CPureServerWhitelist *m_pWhitelist; // ecx
  CPureServerWhitelist::CCommand *BestEntry; // eax

  m_pWhitelist = this->m_pWhitelist;
  if ( m_pWhitelist->m_bFullyPureMode )
    return !IsProtectedBySvPure2(pFilename);
  BestEntry = CPureServerWhitelist::GetBestEntry(this: m_pWhitelist, pFilename);
  return BestEntry == nullptr || BestEntry->m_bAllowFromDisk;
}

//------------------------------------------------------------------------------
// Address: 0x101CDE10
// Name: public: virtual bool CPureServerWhitelist::CForceMatchList::IsFileInList(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPureServerWhitelist::CForceMatchList::IsFileInList(
        CPureServerWhitelist::CForceMatchList *this,
        const char *pFilename)
{
  CPureServerWhitelist *m_pWhitelist; // ecx
  CPureServerWhitelist::CCommand *BestEntry; // eax

  m_pWhitelist = this->m_pWhitelist;
  if ( m_pWhitelist->m_bFullyPureMode )
    return false;
  BestEntry = CPureServerWhitelist::GetBestEntry(this: m_pWhitelist, pFilename);
  return BestEntry != nullptr && BestEntry->m_bCheckCRC;
}

//------------------------------------------------------------------------------
// Address: 0x101CDE40
// Name: public: static class CPureServerWhitelist __near * CPureServerWhitelist::Create(class IFileSystem __near *)
// Source: json
//------------------------------------------------------------------------------
CPureServerWhitelist *__cdecl CPureServerWhitelist::Create(IFileSystem *pFileSystem)
{
  CPureServerWhitelist *v1; // eax
  CPureServerWhitelist *v2; // esi

  v1 = (CPureServerWhitelist *)MemAlloc_Alloc(nSize: 0x8Cu);
  if ( v1 != nullptr )
    v2 = CPureServerWhitelist::CPureServerWhitelist(this: v1);
  else
    v2 = nullptr;
  CUtlDict<CPureServerWhitelist::CCommand *,int>::PurgeAndDeleteElements(this: &v2->m_FileCommands);
  CUtlDict<CPureServerWhitelist::CCommand *,int>::PurgeAndDeleteElements(this: &v2->m_RecursiveDirCommands);
  CUtlDict<CPureServerWhitelist::CCommand *,int>::PurgeAndDeleteElements(this: &v2->m_NonRecursiveDirCommands);
  v2->m_LoadCounter = 0;
  v2->m_pFileSystem = pFileSystem;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x101CDE90
// Name: public: void CPureServerWhitelist::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPureServerWhitelist::Release(CPureServerWhitelist *this)
{
  if ( --this->m_RefCount <= 0 )
  {
    CPureServerWhitelist::~CPureServerWhitelist(this);
    free(pMem: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CDEB0
// Name: public: virtual void CPureServerWhitelist::CForceMatchList::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPureServerWhitelist::CForceMatchList::Release(CPureServerWhitelist::CForceMatchList *this)
{
  CPureServerWhitelist *m_pWhitelist; // esi

  m_pWhitelist = this->m_pWhitelist;
  if ( --m_pWhitelist->m_RefCount <= 0 )
  {
    CPureServerWhitelist::~CPureServerWhitelist(this: m_pWhitelist);
    free(pMem: m_pWhitelist);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CDED0
// Name: public: bool CPureServerWhitelist::LoadFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CPureServerWhitelist::LoadFromKeyValues(CPureServerWhitelist *this, KeyValues *kv)
{
  KeyValues *FirstValue; // ebx
  const char *Name; // esi
  const char *String; // eax
  const char *v5; // edi
  char v6; // bl
  int v7; // esi
  CPureServerWhitelist::CCommand *v8; // edi
  CPureServerWhitelist *v9; // eax
  const char *v10; // esi
  CUtlRBTree<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int,CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int>,int> > *p_m_Tree; // esi
  const char *v12; // eax
  const char *v13; // ebx
  char *v14; // ecx
  int v15; // eax
  char v16; // dl
  const char *v17; // eax
  int v18; // eax
  int v19; // edx
  int v20; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int> *v21; // ecx
  int v22; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int> *m_pMemory; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int> *v24; // eax
  CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t *p_m_Data; // eax
  char szPathName[260]; // [esp+4h] [ebp-240h] BYREF
  char filePath[260]; // [esp+108h] [ebp-13Ch] BYREF
  CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t search; // [esp+20Ch] [ebp-38h] BYREF
  CSplitString mods; // [esp+214h] [ebp-30h] BYREF
  CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t insert; // [esp+22Ch] [ebp-18h] BYREF
  int parent; // [esp+234h] [ebp-10h] BYREF
  KeyValues *pCurItem; // [esp+238h] [ebp-Ch]
  CPureServerWhitelist *v34; // [esp+23Ch] [ebp-8h]
  bool bFromSteam; // [esp+243h] [ebp-1h]

  v34 = this;
  FirstValue = KeyValues::GetFirstValue(this: kv);
  pCurItem = FirstValue;
  if ( FirstValue != nullptr )
  {
    while ( 1 )
    {
      Name = KeyValues::GetName(this: FirstValue);
      String = KeyValues::GetString(this: FirstValue, keyName: nullptr, defaultValue: defaultValue);
      v5 = String;
      if ( Name != nullptr && String != nullptr )
      {
        V_strncpy(pDest: szPathName, pSrc: Name, maxLen: 260);
        V_FixSlashes(pname: szPathName, separator: 92);
        bFromSteam = false;
        HIBYTE(kv) = 0;
        v6 = 0;
        CSplitString::CSplitString(this: &mods, pString: v5, pSeparator: "+");
        v7 = 0;
        if ( mods.m_Size > 0 )
        {
          do
          {
            if ( _V_stricmp(s1: mods.m_Memory.m_pMemory[v7], s2: "from_steam") != 0 )
            {
              if ( _V_stricmp(s1: mods.m_Memory.m_pMemory[v7], s2: "allow_from_disk") != 0 )
              {
                if ( _V_stricmp(s1: mods.m_Memory.m_pMemory[v7], s2: "check_crc") != 0 )
                  _Warning(a1: "Unknown modifier in whitelist file: %s.\n", mods.m_Memory.m_pMemory[v7]);
                else
                  v6 = 1;
              }
              else
              {
                HIBYTE(kv) = 1;
              }
            }
            else
            {
              bFromSteam = true;
            }
            ++v7;
          }
          while ( v7 < mods.m_Size );
          if ( bFromSteam && (HIBYTE(kv) != 0 || v6 != 0) )
          {
            v6 = 0;
            HIBYTE(kv) = 0;
            _Warning(a1: "Whitelist: from_steam not compatible with other modifiers (used on %s).\n", szPathName);
            _Warning(a1: "           Other markers removed.\n");
          }
        }
        v8 = (CPureServerWhitelist::CCommand *)MemAlloc_Alloc(nSize: 4u);
        v9 = v34;
        v8->m_LoadOrder = v34->m_LoadCounter;
        ++v9->m_LoadCounter;
        v8->m_bAllowFromDisk = HIBYTE(kv);
        v8->m_bCheckCRC = v6;
        v10 = V_UnqualifiedFileName(in: szPathName);
        if ( _V_stricmp(s1: v10, s2: "...") != 0 )
        {
          if ( _V_stricmp(s1: v10, s2: "*.*") != 0 )
            p_m_Tree = &v34->m_FileCommands.m_Elements.m_Tree;
          else
            p_m_Tree = &v34->m_NonRecursiveDirCommands.m_Elements.m_Tree;
        }
        else
        {
          p_m_Tree = &v34->m_RecursiveDirCommands.m_Elements.m_Tree;
        }
        if ( p_m_Tree == (CUtlRBTree<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int,CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int>,int> > *)&v34->m_RecursiveDirCommands
          || p_m_Tree == (CUtlRBTree<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int,CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int>,int> > *)&v34->m_NonRecursiveDirCommands )
        {
          V_ExtractFilePath(path: szPathName, dest: filePath, destSize: 260);
        }
        else
        {
          V_strncpy(pDest: filePath, pSrc: szPathName, maxLen: 260);
        }
        V_FixSlashes(pname: filePath, separator: 92);
        search.key = filePath;
        if ( CUtlRBTree<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int,CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int>,int>>::Find(
               this: p_m_Tree,
               &search) == -1 )
        {
          v12 = (const char *)_g_pMemAlloc->Alloc_2(
                                this: _g_pMemAlloc,
                                a2: &filePath[strlen(filePath) + 1] - &filePath[1] + 1);
          v13 = v12;
          if ( v12 != nullptr )
          {
            v14 = filePath;
            v15 = v12 - filePath;
            do
            {
              v16 = *v14;
              v14[v15] = *v14;
              ++v14;
            }
            while ( v16 != 0 );
            v17 = v13;
          }
          else
          {
            v17 = nullptr;
          }
          insert.key = v17;
          insert.elem = v8;
          parent = -1;
          HIBYTE(kv) = 0;
          CUtlRBTree<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int,CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int>,int>>::FindInsertionPosition(
            this: p_m_Tree,
            &insert,
            &parent,
            leftchild: (bool *)&kv + 3);
          v18 = CUtlRBTree<CDmxSerializationDictionary::DmxElementInfo_t,int,bool (__cdecl *)(CDmxSerializationDictionary::DmxElementInfo_t const &,CDmxSerializationDictionary::DmxElementInfo_t const &),CUtlMemory<UtlRBTreeNode_t<CDmxSerializationDictionary::DmxElementInfo_t,int>,int>>::NewNode(this: (CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *)p_m_Tree);
          v19 = parent;
          v20 = v18;
          v21 = &p_m_Tree->m_Elements.m_pMemory[v18];
          v21->m_Parent = parent;
          v21->m_Right = -1;
          v21->m_Left = -1;
          v21->m_Tag = 0;
          if ( v19 == -1 )
          {
            p_m_Tree->m_Root = v18;
          }
          else
          {
            v22 = v19;
            m_pMemory = p_m_Tree->m_Elements.m_pMemory;
            if ( HIBYTE(kv) != 0 )
              m_pMemory[v22].m_Left = v18;
            else
              m_pMemory[v22].m_Right = v18;
          }
          CUtlRBTree<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int,CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int>,int>>::InsertRebalance(
            this: p_m_Tree,
            elem: v18);
          v24 = p_m_Tree->m_Elements.m_pMemory;
          ++p_m_Tree->m_NumElements;
          p_m_Data = &v24[v20].m_Data;
          if ( p_m_Data != nullptr )
            *p_m_Data = insert;
        }
        else
        {
          _Error(a1: "Pure server whitelist entry '%s' is a duplicate.\n", filePath);
        }
        CSplitString::~CSplitString(this: &mods);
        FirstValue = pCurItem;
      }
      pCurItem = KeyValues::GetNextValue(this: FirstValue);
      if ( pCurItem == nullptr )
        break;
      FirstValue = pCurItem;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101CE200
// Name: private: void CPureServerWhitelist::DecodeCommandList(class CUtlDict<class CPureServerWhitelist::CCommand __near *,int> __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPureServerWhitelist::DecodeCommandList(
        CPureServerWhitelist *this,
        CUtlDict<CPureServerWhitelist::CCommand *,int> *theList,
        CUtlBuffer *buf)
{
  CUtlBuffer *v3; // ebx
  int Int; // eax
  CUtlDict<CPureServerWhitelist::CCommand *,int> *v5; // edi
  CPureServerWhitelist::CCommand *v6; // esi
  unsigned __int8 UnsignedShort; // al
  const char *v8; // eax
  const char *v9; // ebx
  char *v10; // ecx
  int v11; // eax
  char v12; // dl
  const char *v13; // eax
  int v14; // eax
  int v15; // edx
  int v16; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int> *v17; // ecx
  int v18; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int> *m_pMemory; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int> *v20; // eax
  CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t *p_m_Data; // eax
  char str[260]; // [esp+4h] [ebp-114h] BYREF
  CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t insert; // [esp+108h] [ebp-10h] BYREF
  int parent; // [esp+110h] [ebp-8h] BYREF
  int v25; // [esp+114h] [ebp-4h]

  v3 = buf;
  Int = CUtlBuffer::GetInt(this: buf);
  if ( Int > 0 )
  {
    v5 = theList;
    v25 = Int;
    while ( 1 )
    {
      v6 = (CPureServerWhitelist::CCommand *)MemAlloc_Alloc(nSize: 4u);
      if ( (v3->m_Flags & 1) != 0 )
      {
        UnsignedShort = CUtlBuffer::GetUnsignedShort(this: v3);
      }
      else if ( CUtlBuffer::CheckGet(this: v3, nSize: 1) )
      {
        UnsignedShort = v3->m_Memory.m_pMemory[v3->m_Get - v3->m_nOffset];
        ++v3->m_Get;
      }
      else
      {
        UnsignedShort = 0;
      }
      v6->m_bAllowFromDisk = UnsignedShort & 1;
      v6->m_bCheckCRC = (UnsignedShort & 2) != 0;
      v6->m_LoadOrder = CUtlBuffer::GetUnsignedShort(this: v3);
      CUtlBuffer::GetString(this: v3, pString: str, nMaxChars: 259);
      V_FixSlashes(pname: str, separator: 92);
      v8 = (const char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(str) + 1);
      v9 = v8;
      if ( v8 != nullptr )
      {
        v10 = str;
        v11 = v8 - str;
        do
        {
          v12 = *v10;
          v10[v11] = *v10;
          ++v10;
        }
        while ( v12 != 0 );
        v13 = v9;
      }
      else
      {
        v13 = nullptr;
      }
      insert.key = v13;
      insert.elem = v6;
      parent = -1;
      HIBYTE(theList) = 0;
      CUtlRBTree<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int,CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int>,int>>::FindInsertionPosition(
        this: &v5->m_Elements.m_Tree,
        &insert,
        &parent,
        leftchild: (bool *)&theList + 3);
      v14 = CUtlRBTree<CDmxSerializationDictionary::DmxElementInfo_t,int,bool (__cdecl *)(CDmxSerializationDictionary::DmxElementInfo_t const &,CDmxSerializationDictionary::DmxElementInfo_t const &),CUtlMemory<UtlRBTreeNode_t<CDmxSerializationDictionary::DmxElementInfo_t,int>,int>>::NewNode(this: (CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *)v5);
      v15 = parent;
      v16 = v14;
      v17 = &v5->m_Elements.m_Tree.m_Elements.m_pMemory[v14];
      v17->m_Parent = parent;
      v17->m_Right = -1;
      v17->m_Left = -1;
      v17->m_Tag = 0;
      if ( v15 == -1 )
      {
        v5->m_Elements.m_Tree.m_Root = v14;
      }
      else
      {
        v18 = v15;
        m_pMemory = v5->m_Elements.m_Tree.m_Elements.m_pMemory;
        if ( HIBYTE(theList) != 0 )
          m_pMemory[v18].m_Left = v14;
        else
          m_pMemory[v18].m_Right = v14;
      }
      CUtlRBTree<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int,CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int>,int>>::InsertRebalance(
        this: &v5->m_Elements.m_Tree,
        elem: v14);
      v20 = v5->m_Elements.m_Tree.m_Elements.m_pMemory;
      ++v5->m_Elements.m_Tree.m_NumElements;
      p_m_Data = &v20[v16].m_Data;
      if ( p_m_Data != nullptr )
        *p_m_Data = insert;
      if ( --v25 == 0 )
        break;
      v3 = buf;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CE390
// Name: public: void CPureServerWhitelist::Decode(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPureServerWhitelist::Decode(CPureServerWhitelist *this, CUtlBuffer *buf)
{
  unsigned __int8 v3; // cl

  CPureServerWhitelist::DecodeCommandList(this, theList: &this->m_FileCommands, buf);
  CPureServerWhitelist::DecodeCommandList(this, theList: &this->m_RecursiveDirCommands, buf);
  CPureServerWhitelist::DecodeCommandList(this, theList: &this->m_NonRecursiveDirCommands, buf);
  if ( buf->m_nMaxPut - buf->m_Get < 1 )
  {
    this->m_bFullyPureMode = false;
  }
  else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
  {
    v3 = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
    this->m_bFullyPureMode = v3 != 0;
  }
  else
  {
    this->m_bFullyPureMode = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B2C30
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class CSosOperator __near *,int>::Node_t,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperator *,int>::Node_t,int>,int>::Grow(
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
// Address: 0x101CE420
// Name: __CreateCEngineUniformRandomStreamIUniformRandomStream_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CEngineUniformRandomStream *__cdecl _CreateCEngineUniformRandomStreamIUniformRandomStream_interface()
{
  return &s_EngineRandomStream;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x100463A0
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class CSosOperator __near *,int>::Node_t,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperator *,int>::Node_t,int>,int>::Grow(
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
// Address: 0x100E9560
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,struct CSaveRestore::RestoreLookupTable,int>::Node_t,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSaveRestore::RestoreLookupTable,int>::Node_t,int>,int>::Grow(
        CUtlMemory<SndInfo_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  SndInfo_t *m_pMemory; // edx
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
        m_nAllocationCount = 1;
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
    v7 = 52 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (SndInfo_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (SndInfo_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CC8D0
// Name: IsProtectedBySvPure2
// Source: json
//------------------------------------------------------------------------------
char __cdecl IsProtectedBySvPure2(char *pFilename)
{
  const char *v1; // edi
  unsigned int v2; // esi
  char v3; // al
  char tempStr[512]; // [esp+Ch] [ebp-204h] BYREF
  unsigned int v6; // [esp+20Ch] [ebp-4h]

  v6 = 0;
  while ( 1 )
  {
    v1 = g_SvPure2_ProtectedDirs[v6 / 4];
    v2 = _V_strlen(str: v1);
    if ( _V_strlen(str: pFilename) < (int)(v2 + 1) )
      return 0;
    memcpy(dst: (unsigned __int8 *)tempStr, src: (unsigned __int8 *)pFilename, count: v2);
    tempStr[v2] = 0;
    if ( _V_stricmp(s1: tempStr, s2: v1) == 0 )
    {
      v3 = pFilename[v2];
      if ( v3 == 47 || v3 == 92 )
        break;
    }
    v6 += 4;
    if ( v6 >= 0xC )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101CC960
// Name: public: bool CPureServerWhitelist::IsInFullyPureMode(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPureServerWhitelist::IsInFullyPureMode(CPureServerWhitelist *this)
{
  return this->m_bFullyPureMode;
}

//------------------------------------------------------------------------------
// Address: 0x101CC970
// Name: private: void CPureServerWhitelist::PrintCommand(char const __near *,char const __near *,int,class CPureServerWhitelist::CCommand __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPureServerWhitelist::PrintCommand(
        CPureServerWhitelist *this,
        const char *pFileSpec,
        const char *pExt,
        int maxPathnameLen,
        CPureServerWhitelist::CCommand *pCommand)
{
  int v5; // eax
  char *v6; // ecx
  int v7; // eax
  int v8; // edi
  char tempFileSpec[260]; // [esp+8h] [ebp-104h] BYREF

  V_strncpy(pDest: tempFileSpec, pSrc: pFileSpec, maxLen: 260);
  v5 = _V_strlen(str: tempFileSpec);
  if ( v5 > 0 )
  {
    v6 = &tempFileSpec[v5 - 1];
    if ( tempFileSpec[v5 - 1] == 47 || *v6 == 92 )
      *v6 = 0;
  }
  if ( pExt != nullptr )
    _Msg(a1: "%s%c%s", tempFileSpec, 92, pExt);
  else
    _Msg(a1: "%s", tempFileSpec);
  v7 = _V_strlen(str: pFileSpec);
  if ( v7 < maxPathnameLen + 6 )
  {
    v8 = maxPathnameLen + 6 - v7;
    do
    {
      _Msg(a1: " ");
      --v8;
    }
    while ( v8 != 0 );
  }
  _Msg(a1: "\t");
  if ( pCommand->m_bAllowFromDisk )
  {
    if ( pCommand->m_bCheckCRC )
      _Msg(a1: "allow_from_disk+check_crc");
    else
      _Msg(a1: "allow_from_disk");
  }
  else
  {
    _Msg(a1: "from_steam");
  }
  _Msg(a1: "\n");
}

//------------------------------------------------------------------------------
// Address: 0x101CCA60
// Name: public: class IFileList __near * CPureServerWhitelist::GetAllowFromDiskList(void)
// Source: json
//------------------------------------------------------------------------------
CPureServerWhitelist::CAllowFromDiskList *__thiscall CPureServerWhitelist::GetAllowFromDiskList(
        CPureServerWhitelist *this)
{
  ++this->m_RefCount;
  return &this->m_AllowFromDiskList;
}

//------------------------------------------------------------------------------
// Address: 0x101CCA70
// Name: public: class IFileList __near * CPureServerWhitelist::GetForceMatchList(void)
// Source: json
//------------------------------------------------------------------------------
CPureServerWhitelist::CForceMatchList *__thiscall CPureServerWhitelist::GetForceMatchList(CPureServerWhitelist *this)
{
  ++this->m_RefCount;
  return &this->m_ForceMatchList;
}

//------------------------------------------------------------------------------
// Address: 0x101CD950
// Name: public: void CUtlDict<class CPureServerWhitelist::CCommand __near *,int>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<CPureServerWhitelist::CCommand *,int>::RemoveAll(
        CUtlDict<CPureServerWhitelist::CCommand *,int> *this)
{
  int i; // esi

  for ( i = CUtlRBTree<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int,CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int,CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int,CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x101CD9A0
// Name: public: void CUtlDict<class CPureServerWhitelist::CCommand __near *,int>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<CPureServerWhitelist::CCommand *,int>::PurgeAndDeleteElements(
        CUtlDict<CPureServerWhitelist::CCommand *,int> *this)
{
  int i; // edi
  CPureServerWhitelist::CCommand *elem; // esi

  for ( i = CUtlRBTree<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int,CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int,CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
    elem = this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.elem;
    if ( elem != nullptr )
      free(pMem: elem);
  }
  CUtlRBTree<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int,CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x101CDA00
// Name: public: void CPureServerWhitelist::EnableFullyPureMode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPureServerWhitelist::EnableFullyPureMode(CPureServerWhitelist *this)
{
  CUtlDict<CPureServerWhitelist::CCommand *,int>::PurgeAndDeleteElements(this: &this->m_FileCommands);
  CUtlDict<CPureServerWhitelist::CCommand *,int>::PurgeAndDeleteElements(this: &this->m_RecursiveDirCommands);
  CUtlDict<CPureServerWhitelist::CCommand *,int>::PurgeAndDeleteElements(this: &this->m_NonRecursiveDirCommands);
  this->m_bFullyPureMode = true;
}

//------------------------------------------------------------------------------
// Address: 0x101CDAB0
// Name: private: int CPureServerWhitelist::FindCommandByLoadOrder(class CUtlDict<class CPureServerWhitelist::CCommand __near *,int> __near &,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CPureServerWhitelist::FindCommandByLoadOrder(
        CPureServerWhitelist *this,
        CUtlDict<CPureServerWhitelist::CCommand *,int> *commands,
        int iLoadOrder)
{
  int result; // eax

  result = CUtlRBTree<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int,CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int>,int>>::FirstInorder(this: &commands->m_Elements.m_Tree);
  if ( result == -1 )
    return -1;
  while ( commands->m_Elements.m_Tree.m_Elements.m_pMemory[result].m_Data.elem->m_LoadOrder != iLoadOrder )
  {
    result = CUtlRBTree<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int,CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int>,int>>::NextInorder(
               this: &commands->m_Elements.m_Tree,
               i: result);
    if ( result == -1 )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101CDB00
// Name: public: void CPureServerWhitelist::PrintWhitelistContents(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPureServerWhitelist::PrintWhitelistContents(CPureServerWhitelist *this)
{
  int v2; // edi
  CUtlDict<CPureServerWhitelist::CCommand *,int> *p_m_FileCommands; // ebx
  int Inorder; // eax
  int v5; // eax
  int CommandByLoadOrder; // eax
  int highestLoadOrder; // [esp+Ch] [ebp-8h] BYREF
  int longestPathName; // [esp+10h] [ebp-4h] BYREF

  v2 = 0;
  p_m_FileCommands = &this->m_FileCommands;
  highestLoadOrder = 0;
  longestPathName = 0;
  CPureServerWhitelist::UpdateCommandStats(
    this,
    commands: &this->m_FileCommands,
    pHighest: &highestLoadOrder,
    pLongestPathName: &longestPathName);
  CPureServerWhitelist::UpdateCommandStats(
    this,
    commands: &this->m_RecursiveDirCommands,
    pHighest: &highestLoadOrder,
    pLongestPathName: &longestPathName);
  CPureServerWhitelist::UpdateCommandStats(
    this,
    commands: &this->m_NonRecursiveDirCommands,
    pHighest: &highestLoadOrder,
    pLongestPathName: &longestPathName);
  if ( highestLoadOrder >= 0 )
  {
    do
    {
      Inorder = CUtlRBTree<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int,CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int>,int>>::FirstInorder(this: &p_m_FileCommands->m_Elements.m_Tree);
      if ( Inorder == -1 )
      {
LABEL_5:
        v5 = CUtlRBTree<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int,CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_RecursiveDirCommands.m_Elements.m_Tree);
        if ( v5 == -1 )
        {
LABEL_8:
          CommandByLoadOrder = CPureServerWhitelist::FindCommandByLoadOrder(
                                 this,
                                 commands: &this->m_NonRecursiveDirCommands,
                                 iLoadOrder: v2);
          if ( CommandByLoadOrder != -1 )
            CPureServerWhitelist::PrintCommand(
              this,
              pFileSpec: this->m_NonRecursiveDirCommands.m_Elements.m_Tree.m_Elements.m_pMemory[CommandByLoadOrder].m_Data.key,
              pExt: "*.*",
              maxPathnameLen: longestPathName,
              pCommand: this->m_NonRecursiveDirCommands.m_Elements.m_Tree.m_Elements.m_pMemory[CommandByLoadOrder].m_Data.elem);
        }
        else
        {
          while ( this->m_RecursiveDirCommands.m_Elements.m_Tree.m_Elements.m_pMemory[v5].m_Data.elem->m_LoadOrder != v2 )
          {
            v5 = CUtlRBTree<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int,CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int>,int>>::NextInorder(
                   this: &this->m_RecursiveDirCommands.m_Elements.m_Tree,
                   i: v5);
            if ( v5 == -1 )
              goto LABEL_8;
          }
          CPureServerWhitelist::PrintCommand(
            this,
            pFileSpec: this->m_RecursiveDirCommands.m_Elements.m_Tree.m_Elements.m_pMemory[v5].m_Data.key,
            pExt: "...",
            maxPathnameLen: longestPathName,
            pCommand: this->m_RecursiveDirCommands.m_Elements.m_Tree.m_Elements.m_pMemory[v5].m_Data.elem);
        }
      }
      else
      {
        while ( p_m_FileCommands->m_Elements.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.elem->m_LoadOrder != v2 )
        {
          Inorder = CUtlRBTree<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int,CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int>,int>>::NextInorder(
                      this: &p_m_FileCommands->m_Elements.m_Tree,
                      i: Inorder);
          if ( Inorder == -1 )
            goto LABEL_5;
        }
        CPureServerWhitelist::PrintCommand(
          this,
          pFileSpec: this->m_FileCommands.m_Elements.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.key,
          pExt: nullptr,
          maxPathnameLen: longestPathName,
          pCommand: this->m_FileCommands.m_Elements.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.elem);
      }
      ++v2;
    }
    while ( v2 <= highestLoadOrder );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CDC40
// Name: private: void CPureServerWhitelist::EncodeCommandList(class CUtlDict<class CPureServerWhitelist::CCommand __near *,int> __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPureServerWhitelist::EncodeCommandList(
        CPureServerWhitelist *this,
        CUtlDict<CPureServerWhitelist::CCommand *,int> *theList,
        CUtlBuffer *buf)
{
  CUtlDict<CPureServerWhitelist::CCommand *,int> *v4; // edi
  int Inorder; // eax
  int v6; // eax
  CPureServerWhitelist::CCommand *elem; // edi
  unsigned __int8 m_bAllowFromDisk; // bl
  unsigned __int16 m_LoadOrder; // bx
  int m_NumElements; // [esp-4h] [ebp-14h]
  int v11; // [esp+8h] [ebp-8h]
  __int16 inputBuffer[2]; // [esp+Ch] [ebp-4h] BYREF
  int i; // [esp+1Ch] [ebp+Ch]

  v4 = theList;
  m_NumElements = theList->m_Elements.m_Tree.m_NumElements;
  if ( (buf->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: buf, pFmt: "%d", m_NumElements);
  else
    CUtlBuffer::PutTypeBin<int>(this: buf, src: m_NumElements);
  Inorder = CUtlRBTree<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int,CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int>,int>>::FirstInorder(this: &theList->m_Elements.m_Tree);
  i = Inorder;
  if ( Inorder != -1 )
  {
    while ( 1 )
    {
      v6 = Inorder;
      elem = v4->m_Elements.m_Tree.m_Elements.m_pMemory[v6].m_Data.elem;
      v11 = v6 * 24;
      m_bAllowFromDisk = elem->m_bAllowFromDisk;
      if ( elem->m_bCheckCRC )
        m_bAllowFromDisk |= 2u;
      if ( (buf->m_Flags & 1) != 0 )
      {
        CUtlBuffer::Printf(this: buf, pFmt: "%hu", m_bAllowFromDisk);
      }
      else if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
      {
        buf->m_Memory.m_pMemory[buf->m_Put++ - buf->m_nOffset] = m_bAllowFromDisk;
        CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
      }
      m_LoadOrder = elem->m_LoadOrder;
      if ( (buf->m_Flags & 1) != 0 )
      {
        CUtlBuffer::Printf(this: buf, pFmt: "%hu", elem->m_LoadOrder);
      }
      else
      {
        *(_DWORD *)inputBuffer = elem->m_LoadOrder;
        if ( CUtlBuffer::CheckPut(this: buf, nSize: 2) )
        {
          if ( (*(_BYTE *)&buf->m_Byteswap & 1) != 0 )
            CByteswap::SwapBufferToTargetEndian<unsigned short>(
              this: &buf->m_Byteswap,
              outputBuffer: (__int16 *)&buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset],
              inputBuffer,
              count: 1);
          else
            *(_WORD *)&buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = m_LoadOrder;
          buf->m_Put += 2;
          CUtlBuffer::AddNullTermination(this: buf, nPut: buf->m_Put);
        }
      }
      v4 = theList;
      CUtlBuffer::PutString(
        this: buf,
        pString: *(const char **)((char *)&theList->m_Elements.m_Tree.m_Elements.m_pMemory->m_Data.key + v11));
      i = CUtlRBTree<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int,CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int>,int>>::NextInorder(
            this: &theList->m_Elements.m_Tree,
            i);
      if ( i == -1 )
        break;
      Inorder = i;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CDDA0
// Name: private: void CPureServerWhitelist::InternalCacheFileCRCs(class CUtlDict<class CPureServerWhitelist::CCommand __near *,int> __near &,enum ECacheCRCType)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPureServerWhitelist::InternalCacheFileCRCs(
        CPureServerWhitelist *this,
        CUtlDict<CPureServerWhitelist::CCommand *,int> *theList,
        ECacheCRCType eType)
{
  CPureServerWhitelist *v3; // ebx
  int i; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int> *v5; // eax

  v3 = this;
  for ( i = CUtlRBTree<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int,CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int>,int>>::FirstInorder(this: &theList->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int,CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int>,int>>::NextInorder(
              this: &theList->m_Elements.m_Tree,
              i) )
  {
    v5 = &theList->m_Elements.m_Tree.m_Elements.m_pMemory[i];
    if ( v5->m_Data.elem->m_bCheckCRC )
    {
      v3->m_pFileSystem->CacheFileCRCs(
        this: v3->m_pFileSystem,
        a2: v5->m_Data.key,
        a3: eType,
        a4: &v3->m_ForceMatchList);
      v3 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CDE80
// Name: private: CPureServerWhitelist::CPureServerWhitelist(void)
// Source: json
//------------------------------------------------------------------------------
CPureServerWhitelist *__thiscall CPureServerWhitelist::CPureServerWhitelist(CPureServerWhitelist *this)
{
  CPureServerWhitelist *result; // eax

  result = this;
  this->m_FileCommands.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_FileCommands.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_FileCommands.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_FileCommands.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_FileCommands.m_Elements.m_Tree.m_Root = -1;
  this->m_FileCommands.m_Elements.m_Tree.m_NumElements = 0;
  this->m_FileCommands.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_FileCommands.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_FileCommands.m_Elements.m_Tree.m_pElements = this->m_FileCommands.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( this->m_FileCommands.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_FileCommands.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  this->m_RecursiveDirCommands.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_RecursiveDirCommands.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_RecursiveDirCommands.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_RecursiveDirCommands.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_RecursiveDirCommands.m_Elements.m_Tree.m_Root = -1;
  this->m_RecursiveDirCommands.m_Elements.m_Tree.m_NumElements = 0;
  this->m_RecursiveDirCommands.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_RecursiveDirCommands.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_RecursiveDirCommands.m_Elements.m_Tree.m_pElements = this->m_RecursiveDirCommands.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( this->m_RecursiveDirCommands.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_RecursiveDirCommands.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  this->m_NonRecursiveDirCommands.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_NonRecursiveDirCommands.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_NonRecursiveDirCommands.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_NonRecursiveDirCommands.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_NonRecursiveDirCommands.m_Elements.m_Tree.m_Root = -1;
  this->m_NonRecursiveDirCommands.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_NonRecursiveDirCommands.m_Elements.m_Tree.m_NumElements = 0;
  this->m_NonRecursiveDirCommands.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_NonRecursiveDirCommands.m_Elements.m_Tree.m_pElements = this->m_NonRecursiveDirCommands.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( this->m_NonRecursiveDirCommands.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_NonRecursiveDirCommands.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  this->m_AllowFromDiskList.__vftable = (CPureServerWhitelist::CAllowFromDiskList_vtbl *)&CPureServerWhitelist::CAllowFromDiskList::`vftable';
  this->m_ForceMatchList.__vftable = (CPureServerWhitelist::CForceMatchList_vtbl *)&CPureServerWhitelist::CForceMatchList::`vftable';
  this->m_pFileSystem = nullptr;
  this->m_LoadCounter = 0;
  this->m_AllowFromDiskList.m_pWhitelist = this;
  this->m_ForceMatchList.m_pWhitelist = this;
  this->m_RefCount = 1;
  this->m_bFullyPureMode = false;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101CDF40
// Name: private: CPureServerWhitelist::~CPureServerWhitelist(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPureServerWhitelist::~CPureServerWhitelist(CPureServerWhitelist *this)
{
  CPureServerWhitelist *v1; // esi
  CUtlDict<CPureServerWhitelist::CCommand *,int> *p_m_FileCommands; // edi
  CUtlDict<CPureServerWhitelist::CCommand *,int> *p_m_RecursiveDirCommands; // ebx

  v1 = this;
  p_m_FileCommands = &this->m_FileCommands;
  CUtlDict<CPureServerWhitelist::CCommand *,int>::PurgeAndDeleteElements(this: &this->m_FileCommands);
  p_m_RecursiveDirCommands = &v1->m_RecursiveDirCommands;
  CUtlDict<CPureServerWhitelist::CCommand *,int>::PurgeAndDeleteElements(this: &v1->m_RecursiveDirCommands);
  CUtlDict<CPureServerWhitelist::CCommand *,int>::PurgeAndDeleteElements(this: &v1->m_NonRecursiveDirCommands);
  v1->m_pFileSystem = nullptr;
  v1->m_LoadCounter = 0;
  v1 = (CPureServerWhitelist *)((char *)v1 + 80);
  CUtlDict<CPureServerWhitelist::CCommand *,int>::RemoveAll(this: (CUtlDict<CPureServerWhitelist::CCommand *,int> *)v1);
  CUtlRBTree<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int,CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int,CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int>,int>>(this: (CUtlRBTree<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int,CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int>,int> > *)v1);
  CUtlDict<CPureServerWhitelist::CCommand *,int>::RemoveAll(this: p_m_RecursiveDirCommands);
  CUtlRBTree<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int,CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int,CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int>,int>>(this: &p_m_RecursiveDirCommands->m_Elements.m_Tree);
  CUtlDict<CPureServerWhitelist::CCommand *,int>::RemoveAll(this: p_m_FileCommands);
  CUtlRBTree<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int,CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int,CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int>,int>>(this: &p_m_FileCommands->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x101CDFB0
// Name: public: void CPureServerWhitelist::Encode(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPureServerWhitelist::Encode(CPureServerWhitelist *this, CUtlBuffer *buf)
{
  bool m_bFullyPureMode; // bl
  int m_Put; // eax

  CPureServerWhitelist::EncodeCommandList(this, theList: &this->m_FileCommands, buf);
  CPureServerWhitelist::EncodeCommandList(this, theList: &this->m_RecursiveDirCommands, buf);
  CPureServerWhitelist::EncodeCommandList(this, theList: &this->m_NonRecursiveDirCommands, buf);
  m_bFullyPureMode = this->m_bFullyPureMode;
  if ( (buf->m_Flags & 1) != 0 )
  {
    m_Put = buf->m_Put;
    if ( m_Put != 0 && buf->m_Memory.m_pMemory[m_Put - buf->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: buf);
  }
  if ( CUtlBuffer::CheckPut(this: buf, nSize: 1) )
  {
    buf->m_Memory.m_pMemory[buf->m_Put - buf->m_nOffset] = m_bFullyPureMode;
    CUtlBuffer::AddNullTermination(this: buf, nPut: ++buf->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CE040
// Name: public: void CPureServerWhitelist::CacheFileCRCs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPureServerWhitelist::CacheFileCRCs(CPureServerWhitelist *this)
{
  CPureServerWhitelist::InternalCacheFileCRCs(this, theList: &this->m_FileCommands, eType: k_eCacheCRCType_SingleFile);
  CPureServerWhitelist::InternalCacheFileCRCs(
    this,
    theList: &this->m_NonRecursiveDirCommands,
    eType: k_eCacheCRCType_Directory);
  CPureServerWhitelist::InternalCacheFileCRCs(
    this,
    theList: &this->m_RecursiveDirCommands,
    eType: k_eCacheCRCType_Directory_Recursive);
}

//------------------------------------------------------------------------------
// Address: 0x101CE070
// Name: private: class CPureServerWhitelist::CCommand __near * CPureServerWhitelist::GetBestEntry(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CPureServerWhitelist::CCommand *__thiscall CPureServerWhitelist::GetBestEntry(
        CPureServerWhitelist *this,
        const char *pFilename)
{
  CPureServerWhitelist::CCommand *v4; // eax
  CPureServerWhitelist::CCommand *elem; // esi
  int v6; // eax
  char relativeFilename[260]; // [esp+8h] [ebp-210h] BYREF
  char relativeDir[260]; // [esp+10Ch] [ebp-10Ch] BYREF
  CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t search; // [esp+210h] [ebp-8h] BYREF

  V_strncpy(pDest: relativeFilename, pSrc: pFilename, maxLen: 260);
  if ( V_IsAbsolutePath(pStr: relativeFilename)
    && !this->m_pFileSystem->FullPathToRelativePath(
          this: this->m_pFileSystem,
          a2: pFilename,
          a3: relativeFilename,
          a4: 260) )
  {
    return nullptr;
  }
  V_FixSlashes(pname: relativeFilename, separator: 92);
  if ( !V_ExtractFilePath(path: relativeFilename, dest: relativeDir, destSize: 260) )
    relativeDir[0] = 0;
  v4 = CPureServerWhitelist::CheckEntry(
         this,
         dict: &this->m_FileCommands,
         pEntryName: relativeFilename,
         pBestEntry: nullptr);
  elem = v4;
  if ( relativeDir[0] != 0 )
  {
    elem = CPureServerWhitelist::CheckEntry(
             this,
             dict: &this->m_NonRecursiveDirCommands,
             pEntryName: relativeDir,
             pBestEntry: v4);
    if ( relativeDir[0] != 0 )
    {
      do
      {
        search.key = relativeDir;
        v6 = CUtlRBTree<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int,CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int>,int>>::Find(
               this: &this->m_RecursiveDirCommands.m_Elements.m_Tree,
               &search);
        if ( v6 != -1
          && (elem == nullptr
           || this->m_RecursiveDirCommands.m_Elements.m_Tree.m_Elements.m_pMemory[v6].m_Data.elem->m_LoadOrder > elem->m_LoadOrder) )
        {
          elem = this->m_RecursiveDirCommands.m_Elements.m_Tree.m_Elements.m_pMemory[v6].m_Data.elem;
        }
      }
      while ( V_StripLastDir(dirName: relativeDir, maxlen: 260) && relativeDir[0] != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x101CE1B0
// Name: public: virtual bool CPureServerWhitelist::CAllowFromDiskList::IsFileInList(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CPureServerWhitelist::CAllowFromDiskList::IsFileInList(
        CPureServerWhitelist::CAllowFromDiskList *this,
        char *pFilename)
{
  CPureServerWhitelist *m_pWhitelist; // ecx
  CPureServerWhitelist::CCommand *BestEntry; // eax

  m_pWhitelist = this->m_pWhitelist;
  if ( m_pWhitelist->m_bFullyPureMode )
    return IsProtectedBySvPure2(pFilename) == 0;
  BestEntry = CPureServerWhitelist::GetBestEntry(this: m_pWhitelist, pFilename);
  return BestEntry == nullptr || BestEntry->m_bAllowFromDisk;
}

//------------------------------------------------------------------------------
// Address: 0x101CE1F0
// Name: public: virtual bool CPureServerWhitelist::CForceMatchList::IsFileInList(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPureServerWhitelist::CForceMatchList::IsFileInList(
        CPureServerWhitelist::CForceMatchList *this,
        const char *pFilename)
{
  CPureServerWhitelist *m_pWhitelist; // ecx
  CPureServerWhitelist::CCommand *BestEntry; // eax

  m_pWhitelist = this->m_pWhitelist;
  if ( m_pWhitelist->m_bFullyPureMode )
    return false;
  BestEntry = CPureServerWhitelist::GetBestEntry(this: m_pWhitelist, pFilename);
  return BestEntry != nullptr && BestEntry->m_bCheckCRC;
}

//------------------------------------------------------------------------------
// Address: 0x101CE220
// Name: public: static class CPureServerWhitelist __near * CPureServerWhitelist::Create(class IFileSystem __near *)
// Source: json
//------------------------------------------------------------------------------
CPureServerWhitelist *__cdecl CPureServerWhitelist::Create(IFileSystem *pFileSystem)
{
  CPureServerWhitelist *v1; // eax
  CPureServerWhitelist *v2; // esi

  v1 = (CPureServerWhitelist *)MemAlloc_Alloc(nSize: 0x8Cu);
  if ( v1 != nullptr )
    v2 = CPureServerWhitelist::CPureServerWhitelist(this: v1);
  else
    v2 = nullptr;
  CUtlDict<CPureServerWhitelist::CCommand *,int>::PurgeAndDeleteElements(this: &v2->m_FileCommands);
  CUtlDict<CPureServerWhitelist::CCommand *,int>::PurgeAndDeleteElements(this: &v2->m_RecursiveDirCommands);
  CUtlDict<CPureServerWhitelist::CCommand *,int>::PurgeAndDeleteElements(this: &v2->m_NonRecursiveDirCommands);
  v2->m_LoadCounter = 0;
  v2->m_pFileSystem = pFileSystem;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x101CE270
// Name: public: void CPureServerWhitelist::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPureServerWhitelist::Release(CPureServerWhitelist *this)
{
  if ( --this->m_RefCount <= 0 )
  {
    CPureServerWhitelist::~CPureServerWhitelist(this);
    free(pMem: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CE290
// Name: public: virtual void CPureServerWhitelist::CForceMatchList::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPureServerWhitelist::CForceMatchList::Release(CPureServerWhitelist::CForceMatchList *this)
{
  CPureServerWhitelist *m_pWhitelist; // esi

  m_pWhitelist = this->m_pWhitelist;
  if ( --m_pWhitelist->m_RefCount <= 0 )
  {
    CPureServerWhitelist::~CPureServerWhitelist(this: m_pWhitelist);
    free(pMem: m_pWhitelist);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CE2B0
// Name: public: bool CPureServerWhitelist::LoadFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CPureServerWhitelist::LoadFromKeyValues(CPureServerWhitelist *this, KeyValues *kv)
{
  KeyValues *FirstValue; // ebx
  const char *Name; // esi
  const char *String; // eax
  const char *v5; // edi
  char v6; // bl
  int v7; // esi
  CPureServerWhitelist::CCommand *v8; // edi
  CPureServerWhitelist *v9; // eax
  const char *v10; // esi
  CUtlRBTree<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int,CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int>,int> > *p_m_Tree; // esi
  const char *v12; // eax
  const char *v13; // ebx
  char *v14; // ecx
  int v15; // eax
  char v16; // dl
  const char *v17; // eax
  int v18; // eax
  int v19; // edx
  int v20; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int> *v21; // ecx
  int v22; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int> *m_pMemory; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int> *v24; // eax
  CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t *p_m_Data; // eax
  char szPathName[260]; // [esp+4h] [ebp-240h] BYREF
  char filePath[260]; // [esp+108h] [ebp-13Ch] BYREF
  CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t search; // [esp+20Ch] [ebp-38h] BYREF
  CSplitString mods; // [esp+214h] [ebp-30h] BYREF
  CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t insert; // [esp+22Ch] [ebp-18h] BYREF
  int parent; // [esp+234h] [ebp-10h] BYREF
  KeyValues *pCurItem; // [esp+238h] [ebp-Ch]
  CPureServerWhitelist *v34; // [esp+23Ch] [ebp-8h]
  bool bFromSteam; // [esp+243h] [ebp-1h]

  v34 = this;
  FirstValue = KeyValues::GetFirstValue(this: kv);
  pCurItem = FirstValue;
  if ( FirstValue != nullptr )
  {
    while ( 1 )
    {
      Name = KeyValues::GetName(this: FirstValue);
      String = KeyValues::GetString(this: FirstValue, keyName: nullptr, defaultValue: defaultValue);
      v5 = String;
      if ( Name != nullptr && String != nullptr )
      {
        V_strncpy(pDest: szPathName, pSrc: Name, maxLen: 260);
        V_FixSlashes(pname: szPathName, separator: 92);
        bFromSteam = false;
        HIBYTE(kv) = 0;
        v6 = 0;
        CSplitString::CSplitString(this: &mods, pString: v5, pSeparator: "+");
        v7 = 0;
        if ( mods.m_Size > 0 )
        {
          do
          {
            if ( _V_stricmp(s1: mods.m_Memory.m_pMemory[v7], s2: "from_steam") != 0 )
            {
              if ( _V_stricmp(s1: mods.m_Memory.m_pMemory[v7], s2: "allow_from_disk") != 0 )
              {
                if ( _V_stricmp(s1: mods.m_Memory.m_pMemory[v7], s2: "check_crc") != 0 )
                  _Warning(a1: "Unknown modifier in whitelist file: %s.\n", mods.m_Memory.m_pMemory[v7]);
                else
                  v6 = 1;
              }
              else
              {
                HIBYTE(kv) = 1;
              }
            }
            else
            {
              bFromSteam = true;
            }
            ++v7;
          }
          while ( v7 < mods.m_Size );
          if ( bFromSteam && (HIBYTE(kv) != 0 || v6 != 0) )
          {
            v6 = 0;
            HIBYTE(kv) = 0;
            _Warning(a1: "Whitelist: from_steam not compatible with other modifiers (used on %s).\n", szPathName);
            _Warning(a1: "           Other markers removed.\n");
          }
        }
        v8 = (CPureServerWhitelist::CCommand *)MemAlloc_Alloc(nSize: 4u);
        v9 = v34;
        v8->m_LoadOrder = v34->m_LoadCounter;
        ++v9->m_LoadCounter;
        v8->m_bAllowFromDisk = HIBYTE(kv);
        v8->m_bCheckCRC = v6;
        v10 = V_UnqualifiedFileName(in: szPathName);
        if ( _V_stricmp(s1: v10, s2: "...") != 0 )
        {
          if ( _V_stricmp(s1: v10, s2: "*.*") != 0 )
            p_m_Tree = &v34->m_FileCommands.m_Elements.m_Tree;
          else
            p_m_Tree = &v34->m_NonRecursiveDirCommands.m_Elements.m_Tree;
        }
        else
        {
          p_m_Tree = &v34->m_RecursiveDirCommands.m_Elements.m_Tree;
        }
        if ( p_m_Tree == (CUtlRBTree<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int,CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int>,int> > *)&v34->m_RecursiveDirCommands
          || p_m_Tree == (CUtlRBTree<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int,CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int>,int> > *)&v34->m_NonRecursiveDirCommands )
        {
          V_ExtractFilePath(path: szPathName, dest: filePath, destSize: 260);
        }
        else
        {
          V_strncpy(pDest: filePath, pSrc: szPathName, maxLen: 260);
        }
        V_FixSlashes(pname: filePath, separator: 92);
        search.key = filePath;
        if ( CUtlRBTree<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int,CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int>,int>>::Find(
               this: p_m_Tree,
               &search) == -1 )
        {
          v12 = (const char *)_g_pMemAlloc->Alloc_2(
                                this: _g_pMemAlloc,
                                a2: &filePath[strlen(filePath) + 1] - &filePath[1] + 1);
          v13 = v12;
          if ( v12 != nullptr )
          {
            v14 = filePath;
            v15 = v12 - filePath;
            do
            {
              v16 = *v14;
              v14[v15] = *v14;
              ++v14;
            }
            while ( v16 != 0 );
            v17 = v13;
          }
          else
          {
            v17 = nullptr;
          }
          insert.key = v17;
          insert.elem = v8;
          parent = -1;
          HIBYTE(kv) = 0;
          CUtlRBTree<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int,CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int>,int>>::FindInsertionPosition(
            this: p_m_Tree,
            &insert,
            &parent,
            leftchild: (bool *)&kv + 3);
          v18 = CUtlRBTree<CDmxSerializationDictionary::DmxElementInfo_t,int,bool (__cdecl *)(CDmxSerializationDictionary::DmxElementInfo_t const &,CDmxSerializationDictionary::DmxElementInfo_t const &),CUtlMemory<UtlRBTreeNode_t<CDmxSerializationDictionary::DmxElementInfo_t,int>,int>>::NewNode(this: (CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *)p_m_Tree);
          v19 = parent;
          v20 = v18;
          v21 = &p_m_Tree->m_Elements.m_pMemory[v18];
          v21->m_Parent = parent;
          v21->m_Right = -1;
          v21->m_Left = -1;
          v21->m_Tag = 0;
          if ( v19 == -1 )
          {
            p_m_Tree->m_Root = v18;
          }
          else
          {
            v22 = v19;
            m_pMemory = p_m_Tree->m_Elements.m_pMemory;
            if ( HIBYTE(kv) != 0 )
              m_pMemory[v22].m_Left = v18;
            else
              m_pMemory[v22].m_Right = v18;
          }
          CUtlRBTree<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int,CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int>,int>>::InsertRebalance(
            this: p_m_Tree,
            elem: v18);
          v24 = p_m_Tree->m_Elements.m_pMemory;
          ++p_m_Tree->m_NumElements;
          p_m_Data = &v24[v20].m_Data;
          if ( p_m_Data != nullptr )
            *p_m_Data = insert;
        }
        else
        {
          _Error(a1: "Pure server whitelist entry '%s' is a duplicate.\n", filePath);
        }
        CSplitString::~CSplitString(this: &mods);
        FirstValue = pCurItem;
      }
      pCurItem = KeyValues::GetNextValue(this: FirstValue);
      if ( pCurItem == nullptr )
        break;
      FirstValue = pCurItem;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101CE5E0
// Name: private: void CPureServerWhitelist::DecodeCommandList(class CUtlDict<class CPureServerWhitelist::CCommand __near *,int> __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPureServerWhitelist::DecodeCommandList(
        CPureServerWhitelist *this,
        CUtlDict<CPureServerWhitelist::CCommand *,int> *theList,
        CUtlBuffer *buf)
{
  CUtlBuffer *v3; // ebx
  int Int; // eax
  CUtlDict<CPureServerWhitelist::CCommand *,int> *v5; // edi
  CPureServerWhitelist::CCommand *v6; // esi
  unsigned __int8 UnsignedShort; // al
  const char *v8; // eax
  const char *v9; // ebx
  char *v10; // ecx
  int v11; // eax
  char v12; // dl
  const char *v13; // eax
  int v14; // eax
  int v15; // edx
  int v16; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int> *v17; // ecx
  int v18; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int> *m_pMemory; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int> *v20; // eax
  CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t *p_m_Data; // eax
  char str[260]; // [esp+4h] [ebp-114h] BYREF
  CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t insert; // [esp+108h] [ebp-10h] BYREF
  int parent; // [esp+110h] [ebp-8h] BYREF
  int v25; // [esp+114h] [ebp-4h]

  v3 = buf;
  Int = CUtlBuffer::GetInt(this: buf);
  if ( Int > 0 )
  {
    v5 = theList;
    v25 = Int;
    while ( 1 )
    {
      v6 = (CPureServerWhitelist::CCommand *)MemAlloc_Alloc(nSize: 4u);
      if ( (v3->m_Flags & 1) != 0 )
      {
        UnsignedShort = CUtlBuffer::GetUnsignedShort(this: v3);
      }
      else if ( CUtlBuffer::CheckGet(this: v3, nSize: 1) )
      {
        UnsignedShort = v3->m_Memory.m_pMemory[v3->m_Get - v3->m_nOffset];
        ++v3->m_Get;
      }
      else
      {
        UnsignedShort = 0;
      }
      v6->m_bAllowFromDisk = UnsignedShort & 1;
      v6->m_bCheckCRC = (UnsignedShort & 2) != 0;
      v6->m_LoadOrder = CUtlBuffer::GetUnsignedShort(this: v3);
      CUtlBuffer::GetString(this: v3, pString: str, nMaxChars: 259);
      V_FixSlashes(pname: str, separator: 92);
      v8 = (const char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(str) + 1);
      v9 = v8;
      if ( v8 != nullptr )
      {
        v10 = str;
        v11 = v8 - str;
        do
        {
          v12 = *v10;
          v10[v11] = *v10;
          ++v10;
        }
        while ( v12 != 0 );
        v13 = v9;
      }
      else
      {
        v13 = nullptr;
      }
      insert.key = v13;
      insert.elem = v6;
      parent = -1;
      HIBYTE(theList) = 0;
      CUtlRBTree<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int,CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int>,int>>::FindInsertionPosition(
        this: &v5->m_Elements.m_Tree,
        &insert,
        &parent,
        leftchild: (bool *)&theList + 3);
      v14 = CUtlRBTree<CDmxSerializationDictionary::DmxElementInfo_t,int,bool (__cdecl *)(CDmxSerializationDictionary::DmxElementInfo_t const &,CDmxSerializationDictionary::DmxElementInfo_t const &),CUtlMemory<UtlRBTreeNode_t<CDmxSerializationDictionary::DmxElementInfo_t,int>,int>>::NewNode(this: (CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *)v5);
      v15 = parent;
      v16 = v14;
      v17 = &v5->m_Elements.m_Tree.m_Elements.m_pMemory[v14];
      v17->m_Parent = parent;
      v17->m_Right = -1;
      v17->m_Left = -1;
      v17->m_Tag = 0;
      if ( v15 == -1 )
      {
        v5->m_Elements.m_Tree.m_Root = v14;
      }
      else
      {
        v18 = v15;
        m_pMemory = v5->m_Elements.m_Tree.m_Elements.m_pMemory;
        if ( HIBYTE(theList) != 0 )
          m_pMemory[v18].m_Left = v14;
        else
          m_pMemory[v18].m_Right = v14;
      }
      CUtlRBTree<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int,CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPureServerWhitelist::CCommand *,int>::Node_t,int>,int>>::InsertRebalance(
        this: &v5->m_Elements.m_Tree,
        elem: v14);
      v20 = v5->m_Elements.m_Tree.m_Elements.m_pMemory;
      ++v5->m_Elements.m_Tree.m_NumElements;
      p_m_Data = &v20[v16].m_Data;
      if ( p_m_Data != nullptr )
        *p_m_Data = insert;
      if ( --v25 == 0 )
        break;
      v3 = buf;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CE770
// Name: public: void CPureServerWhitelist::Decode(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPureServerWhitelist::Decode(CPureServerWhitelist *this, CUtlBuffer *buf)
{
  unsigned __int8 v3; // cl

  CPureServerWhitelist::DecodeCommandList(this, theList: &this->m_FileCommands, buf);
  CPureServerWhitelist::DecodeCommandList(this, theList: &this->m_RecursiveDirCommands, buf);
  CPureServerWhitelist::DecodeCommandList(this, theList: &this->m_NonRecursiveDirCommands, buf);
  if ( buf->m_nMaxPut - buf->m_Get < 1 )
  {
    this->m_bFullyPureMode = false;
  }
  else if ( CUtlBuffer::CheckGet(this: buf, nSize: 1) )
  {
    v3 = buf->m_Memory.m_pMemory[buf->m_Get++ - buf->m_nOffset];
    this->m_bFullyPureMode = v3 != 0;
  }
  else
  {
    this->m_bFullyPureMode = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CE800
// Name: __CreateCEngineUniformRandomStreamIUniformRandomStream_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CEngineUniformRandomStream *__cdecl _CreateCEngineUniformRandomStreamIUniformRandomStream_interface()
{
  return &s_EngineRandomStream;
}

} // namespace engine_xlsp
