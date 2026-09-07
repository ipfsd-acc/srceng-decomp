// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tier1/commandbuffer.cpp
// Functions: 13
// ============================================================

#include "tier1\commandbuffer.h"

//------------------------------------------------------------------------------
// Address: 0x10276990
// Name: public: void CCommandBuffer::SetWaitDelayTime(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommandBuffer::SetWaitDelayTime(CCommandBuffer *this, int nTickDelay)
{
  this->m_nWaitDelayTicks = nTickDelay;
}

//------------------------------------------------------------------------------
// Address: 0x102769A0
// Name: private: void CCommandBuffer::GetNextCommandLength(char const __near *,int,int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommandBuffer::GetNextCommandLength(
        CCommandBuffer *this,
        const char *pText,
        int nMaxLen,
        int *pCommandLength,
        int *pNextCommandOffset)
{
  int v5; // esi
  bool v6; // bl
  char v7; // dl
  int i; // eax
  char v9; // cl

  v5 = 0;
  v6 = false;
  v7 = 0;
  for ( i = 0; i < nMaxLen; ++i )
  {
    v9 = pText[i];
    if ( v7 != 0 )
      goto LABEL_12;
    if ( v9 == 34 )
    {
      v6 = !v6;
    }
    else
    {
      if ( v6 )
        goto LABEL_12;
      if ( v9 != 47 )
      {
        if ( v9 == 59 )
          break;
LABEL_12:
        if ( v9 == 10 )
          break;
        goto LABEL_13;
      }
      if ( i < nMaxLen - 1 && pText[i + 1] == 47 )
      {
        v7 = 1;
        ++i;
      }
      else
      {
        v7 = 0;
      }
    }
LABEL_13:
    v5 += v7 == 0;
  }
  *pCommandLength = v5;
  *pNextCommandOffset = i;
}

//------------------------------------------------------------------------------
// Address: 0x10276A20
// Name: public: bool CCommandBuffer::IsProcessingCommands(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCommandBuffer::IsProcessingCommands(CCommandBuffer *this)
{
  return this->m_bIsProcessingCommands;
}

//------------------------------------------------------------------------------
// Address: 0x10276AC0
// Name: public: void CCommandBuffer::BeginProcessingCommands(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommandBuffer::BeginProcessingCommands(CCommandBuffer *this, int nDeltaTicks)
{
  int v2; // eax
  int m_Head; // edx

  if ( nDeltaTicks != 0 )
  {
    v2 = this->m_nCurrentTick + nDeltaTicks - 1;
    m_Head = this->m_Commands.m_Head;
    this->m_bIsProcessingCommands = true;
    this->m_nLastTickToProcess = v2;
    this->m_hNextCommand = m_Head;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10276B00
// Name: public: int CCommandBuffer::GetNextCommandHandle(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCommandBuffer::GetNextCommandHandle(CCommandBuffer *this)
{
  return this->m_Commands.m_Head;
}

//------------------------------------------------------------------------------
// Address: 0x10276D20
// Name: private: void CCommandBuffer::Compact(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommandBuffer::Compact(CCommandBuffer *this)
{
  _DWORD *m_Head; // esi
  unsigned int v3; // ebx
  unsigned __int8 dst[8192]; // [esp+8h] [ebp-2000h] BYREF

  m_Head = (_DWORD *)this->m_Commands.m_Head;
  for ( this->m_nArgSBufferSize = 0; m_Head != nullptr; m_Head = (_DWORD *)m_Head[4] )
  {
    v3 = m_Head[2];
    memcpy(dst: &dst[this->m_nArgSBufferSize], src: (unsigned __int8 *)&this->m_pArgSBuffer[m_Head[1]], count: v3);
    m_Head[1] = this->m_nArgSBufferSize;
    this->m_nArgSBufferSize += v3;
  }
  memcpy(dst: (unsigned __int8 *)this, src: dst, count: this->m_nArgSBufferSize);
}

//------------------------------------------------------------------------------
// Address: 0x10276F80
// Name: public: CCommandBuffer::~CCommandBuffer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommandBuffer::~CCommandBuffer(CCommandBuffer *this)
{
  CUtlFixedLinkedList<CCommandBuffer::Command_t> *p_m_Commands; // edi
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *m_pBlocks; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *v3; // [esp-4h] [ebp-Ch]

  p_m_Commands = &this->m_Commands;
  CUtlLinkedList<CCommandBuffer::Command_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int>>>::RemoveAll(this: &this->m_Commands);
  m_pBlocks = p_m_Commands->m_Memory.m_pBlocks;
  if ( p_m_Commands->m_Memory.m_pBlocks != nullptr )
  {
    do
    {
      v3 = m_pBlocks;
      m_pBlocks = m_pBlocks->m_pNext;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3);
    }
    while ( m_pBlocks != nullptr );
    p_m_Commands->m_Memory.m_pBlocks = nullptr;
    p_m_Commands->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10276FC0
// Name: private: void CCommandBuffer::InsertCommandAtAppropriateTime(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommandBuffer::InsertCommandAtAppropriateTime(CCommandBuffer *this, _DWORD *hCommand)
{
  _DWORD *i; // ebx
  CUtlFixedLinkedList<CCommandBuffer::Command_t> *p_m_Commands; // edi
  _DWORD *v4; // eax
  int v5; // eax
  int m_Tail; // eax

  for ( i = (_DWORD *)this->m_Commands.m_Head; i != nullptr; i = (_DWORD *)i[4] )
  {
    if ( *i > *hCommand )
      break;
  }
  p_m_Commands = &this->m_Commands;
  if ( hCommand != nullptr
    && !CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int>>::IsIdxAfter(
          this: &this->m_Commands.m_Memory,
          i: (unsigned int)hCommand,
          it: &this->m_Commands.m_LastAlloc) )
  {
    v4 = (_DWORD *)hCommand[3];
    if ( v4 != hCommand )
    {
      if ( v4 != nullptr )
        v4[4] = hCommand[4];
      else
        p_m_Commands->m_Head = hCommand[4];
      v5 = hCommand[4];
      if ( v5 != 0 )
        *(_DWORD *)(v5 + 12) = hCommand[3];
      else
        p_m_Commands->m_Tail = hCommand[3];
      hCommand[4] = hCommand;
      hCommand[3] = hCommand;
      --p_m_Commands->m_ElementCount;
    }
  }
  hCommand[4] = i;
  if ( i != nullptr )
  {
    m_Tail = i[3];
    hCommand[3] = m_Tail;
    i[3] = hCommand;
  }
  else
  {
    m_Tail = p_m_Commands->m_Tail;
    hCommand[3] = m_Tail;
    p_m_Commands->m_Tail = (int)hCommand;
  }
  if ( m_Tail != 0 )
  {
    *(_DWORD *)(m_Tail + 16) = hCommand;
    ++p_m_Commands->m_ElementCount;
  }
  else
  {
    ++p_m_Commands->m_ElementCount;
    p_m_Commands->m_Head = (int)hCommand;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10277070
// Name: private: bool CCommandBuffer::InsertCommand(char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCommandBuffer::InsertCommand(CCommandBuffer *this, char *pArgS, int nCommandSize, int nTick)
{
  int m_nArgSBufferSize; // eax
  _DWORD *v7; // eax

  if ( nCommandSize >= 511 )
  {
    _Warning(a1: "WARNING: Command too long... ignoring!\n%s\n", pArgS);
    return 0;
  }
  m_nArgSBufferSize = this->m_nArgSBufferSize;
  if ( m_nArgSBufferSize + nCommandSize + 1 > this->m_nMaxArgSBufferLength )
  {
    CCommandBuffer::Compact(this);
    m_nArgSBufferSize = this->m_nArgSBufferSize;
    if ( m_nArgSBufferSize + nCommandSize + 1 > this->m_nMaxArgSBufferLength )
      return 0;
  }
  memcpy(
    dst: (unsigned __int8 *)&this->m_pArgSBuffer[m_nArgSBufferSize],
    src: (unsigned __int8 *)pArgS,
    count: nCommandSize);
  this->m_pArgSBuffer[nCommandSize + this->m_nArgSBufferSize] = 0;
  v7 = (_DWORD *)CUtlLinkedList<CCommandBuffer::Command_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int>>>::AllocInternal(
                   this: &this->m_Commands,
                   multilist: false);
  *v7 = nTick;
  v7[1] = this->m_nArgSBufferSize;
  v7[2] = nCommandSize + 1;
  this->m_nArgSBufferSize += nCommandSize + 1;
  if ( this->m_bIsProcessingCommands && nTick <= this->m_nCurrentTick )
  {
    CUtlLinkedList<CCommandBuffer::Command_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int>>>::LinkBefore(
      this: &this->m_Commands,
      before: this->m_hNextCommand,
      elem: (int)v7);
    return 1;
  }
  else
  {
    CCommandBuffer::InsertCommandAtAppropriateTime(this, hCommand: v7);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10277150
// Name: public: bool CCommandBuffer::AddText(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCommandBuffer::AddText(CCommandBuffer *this, char *pText, int nTickDelay)
{
  CCommandBuffer *v3; // ebx
  int v4; // ecx
  int v6; // esi
  void *v7; // esp
  const char *v8; // edi
  characterset_t *v9; // eax
  int v10; // eax
  unsigned __int8 *m_pMemory; // edx
  char v12[12]; // [esp+0h] [ebp-4Ch] BYREF
  CUtlBuffer bufParse; // [esp+Ch] [ebp-40h] BYREF
  int nOffsetToNextCommand; // [esp+3Ch] [ebp-10h] BYREF
  int nCommandLength; // [esp+40h] [ebp-Ch] BYREF
  int nLen; // [esp+44h] [ebp-8h]
  CCommandBuffer *v17; // [esp+48h] [ebp-4h]
  int nTick; // [esp+58h] [ebp+Ch]

  v3 = this;
  v17 = this;
  v4 = _V_strlen(str: pText);
  nLen = v4;
  nTick = nTickDelay + v3->m_nCurrentTick;
  if ( v4 <= 0 )
    return 1;
  while ( 1 )
  {
    CCommandBuffer::GetNextCommandLength(
      this: v3,
      pText,
      nMaxLen: v4,
      pCommandLength: &nCommandLength,
      pNextCommandOffset: &nOffsetToNextCommand);
    v6 = nCommandLength;
    if ( nCommandLength > 0 )
    {
      v7 = alloca(nCommandLength + 1);
      CUtlBuffer::CUtlBuffer(this: &bufParse, pBuffer: pText, nSize: nCommandLength, nFlags: 9);
      v12[0] = 0;
      v8 = nullptr;
      if ( bufParse.m_Error == 0 )
        break;
      m_pMemory = bufParse.m_Memory.m_pMemory;
LABEL_17:
      if ( bufParse.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
    }
LABEL_25:
    v4 = -1 - nOffsetToNextCommand + nLen;
    nLen = v4;
    pText += nOffsetToNextCommand + 1;
    if ( v4 <= 0 )
      return 1;
    v3 = v17;
  }
  v9 = CCommand::DefaultBreakSet();
  v10 = CUtlBuffer::ParseToken(this: &bufParse, pBreaks: v9, pTokenBuf: v12, nMaxLen: v6 + 1, bParseComments: true);
  m_pMemory = bufParse.m_Memory.m_pMemory;
  if ( v10 > 0 && v6 + 1 != v10 )
  {
    if ( bufParse.m_nMaxPut - bufParse.m_Get <= 0 )
      v8 = nullptr;
    else
      v8 = (const char *)&bufParse.m_Memory.m_pMemory[bufParse.m_Get - bufParse.m_nOffset];
  }
  if ( v12[0] == 0 )
    goto LABEL_17;
  if ( _V_stricmp(s1: v12, s2: "wait") == 0 && v17->m_bWaitEnabled )
  {
    if ( v8 != nullptr )
      nTick += atoi(nptr: v8);
    else
      nTick += v17->m_nWaitDelayTicks;
LABEL_22:
    if ( bufParse.m_Memory.m_nGrowSize >= 0 && bufParse.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bufParse.m_Memory.m_pMemory);
    goto LABEL_25;
  }
  if ( CCommandBuffer::InsertCommand(this: v17, pArgS: pText, nCommandSize: v6, nTick) != 0 )
    goto LABEL_22;
  if ( bufParse.m_Memory.m_nGrowSize >= 0 && bufParse.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bufParse.m_Memory.m_pMemory);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10277300
// Name: public: CCommandBuffer::CCommandBuffer(void)
// Source: json
//------------------------------------------------------------------------------
CCommandBuffer *__thiscall CCommandBuffer::CCommandBuffer(CCommandBuffer *this)
{
  CUtlFixedLinkedList<CCommandBuffer::Command_t> *p_m_Commands; // ecx

  p_m_Commands = &this->m_Commands;
  p_m_Commands->m_Memory.m_pBlocks = nullptr;
  this->m_Commands.m_Memory.m_nAllocationCount = 0;
  this->m_Commands.m_Memory.m_nGrowSize = 32;
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int>>::Grow(this: &p_m_Commands->m_Memory, num: 32);
  this->m_Commands.m_LastAlloc.m_pBlockHeader = nullptr;
  this->m_Commands.m_LastAlloc.m_nIndex = -1;
  this->m_Commands.m_Head = 0;
  this->m_Commands.m_Tail = 0;
  this->m_Commands.m_FirstFree = 0;
  this->m_Commands.m_ElementCount = 0;
  this->m_Commands.m_NumAlloced = 0;
  this->m_Commands.m_pElements = nullptr;
  CCommand::CCommand(this: &this->m_CurrentCommand);
  this->m_hNextCommand = 0;
  this->m_nCurrentTick = 0;
  this->m_nArgSBufferSize = 0;
  this->m_bIsProcessingCommands = false;
  this->m_nWaitDelayTicks = 1;
  this->m_nLastTickToProcess = -1;
  this->m_nMaxArgSBufferLength = 0x2000;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102773B0
// Name: public: bool CCommandBuffer::DequeueNextCommand(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCommandBuffer::DequeueNextCommand(CCommandBuffer *this)
{
  int *m_Head; // edi

  CCommand::Reset(this: &this->m_CurrentCommand);
  if ( this->m_Commands.m_ElementCount == 0 )
    return 0;
  m_Head = (int *)this->m_Commands.m_Head;
  if ( *m_Head > this->m_nLastTickToProcess )
    return 0;
  this->m_nCurrentTick = *m_Head;
  if ( m_Head[2] > 0 )
    CCommand::Tokenize(this: &this->m_CurrentCommand, pCommand: &this->m_pArgSBuffer[m_Head[1]], pBreakSet: nullptr);
  CUtlLinkedList<CCommandBuffer::Command_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int>>>::Free(
    this: &this->m_Commands,
    elem: (int)m_Head);
  this->m_hNextCommand = this->m_Commands.m_Head;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10277430
// Name: public: void CCommandBuffer::EndProcessingCommands(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommandBuffer::EndProcessingCommands(CCommandBuffer *this)
{
  int *m_Head; // esi
  int *v3; // eax
  int v4; // eax

  m_Head = (int *)this->m_Commands.m_Head;
  this->m_nCurrentTick = this->m_nLastTickToProcess + 1;
  this->m_bIsProcessingCommands = false;
  this->m_hNextCommand = 0;
  if ( m_Head != nullptr )
  {
    while ( *m_Head < this->m_nCurrentTick )
    {
      _Msg(a1: "Warning: Skipping command %s\n", (const char *)this->m_pArgSBuffer[m_Head[1]]);
      if ( !CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int>>::IsIdxAfter(
              this: &this->m_Commands.m_Memory,
              i: (unsigned int)m_Head,
              it: &this->m_Commands.m_LastAlloc) )
      {
        v3 = (int *)m_Head[3];
        if ( v3 != m_Head )
        {
          if ( v3 != nullptr )
            v3[4] = m_Head[4];
          else
            this->m_Commands.m_Head = m_Head[4];
          v4 = m_Head[4];
          if ( v4 != 0 )
            *(_DWORD *)(v4 + 12) = m_Head[3];
          else
            this->m_Commands.m_Tail = m_Head[3];
          m_Head[4] = (int)m_Head;
          m_Head[3] = (int)m_Head;
          --this->m_Commands.m_ElementCount;
        }
      }
      m_Head[4] = this->m_Commands.m_FirstFree;
      this->m_Commands.m_FirstFree = (int)m_Head;
    }
    CCommandBuffer::Compact(this);
  }
  else
  {
    this->m_nArgSBufferSize = 0;
  }
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10276A10
// Name: public: void CCommandBuffer::SetWaitDelayTime(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommandBuffer::SetWaitDelayTime(CCommandBuffer *this, int nTickDelay)
{
  this->m_nWaitDelayTicks = nTickDelay;
}

//------------------------------------------------------------------------------
// Address: 0x10276AA0
// Name: public: bool CCommandBuffer::IsProcessingCommands(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCommandBuffer::IsProcessingCommands(CCommandBuffer *this)
{
  return this->m_bIsProcessingCommands;
}

//------------------------------------------------------------------------------
// Address: 0x10276B40
// Name: public: void CCommandBuffer::BeginProcessingCommands(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommandBuffer::BeginProcessingCommands(CCommandBuffer *this, int nDeltaTicks)
{
  int v2; // eax
  int m_Head; // edx

  if ( nDeltaTicks != 0 )
  {
    v2 = this->m_nCurrentTick + nDeltaTicks - 1;
    m_Head = this->m_Commands.m_Head;
    this->m_bIsProcessingCommands = true;
    this->m_nLastTickToProcess = v2;
    this->m_hNextCommand = m_Head;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10276B80
// Name: public: int CCommandBuffer::GetNextCommandHandle(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCommandBuffer::GetNextCommandHandle(CCommandBuffer *this)
{
  return this->m_Commands.m_Head;
}

//------------------------------------------------------------------------------
// Address: 0x10276DA0
// Name: private: void CCommandBuffer::Compact(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommandBuffer::Compact(CCommandBuffer *this)
{
  _DWORD *m_Head; // esi
  unsigned int v3; // ebx
  unsigned __int8 dst[8192]; // [esp+8h] [ebp-2000h] BYREF

  m_Head = (_DWORD *)this->m_Commands.m_Head;
  for ( this->m_nArgSBufferSize = 0; m_Head != nullptr; m_Head = (_DWORD *)m_Head[4] )
  {
    v3 = m_Head[2];
    memcpy(dst: &dst[this->m_nArgSBufferSize], src: (unsigned __int8 *)&this->m_pArgSBuffer[m_Head[1]], count: v3);
    m_Head[1] = this->m_nArgSBufferSize;
    this->m_nArgSBufferSize += v3;
  }
  memcpy(dst: (unsigned __int8 *)this, src: dst, count: this->m_nArgSBufferSize);
}

//------------------------------------------------------------------------------
// Address: 0x10277000
// Name: public: CCommandBuffer::~CCommandBuffer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommandBuffer::~CCommandBuffer(CCommandBuffer *this)
{
  CUtlFixedLinkedList<CCommandBuffer::Command_t> *p_m_Commands; // edi
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *m_pBlocks; // esi
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int> >::BlockHeader_t *v3; // [esp-4h] [ebp-Ch]

  p_m_Commands = &this->m_Commands;
  CUtlLinkedList<CCommandBuffer::Command_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int>>>::RemoveAll(this: &this->m_Commands);
  m_pBlocks = p_m_Commands->m_Memory.m_pBlocks;
  if ( p_m_Commands->m_Memory.m_pBlocks != nullptr )
  {
    do
    {
      v3 = m_pBlocks;
      m_pBlocks = m_pBlocks->m_pNext;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3);
    }
    while ( m_pBlocks != nullptr );
    p_m_Commands->m_Memory.m_pBlocks = nullptr;
    p_m_Commands->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10277040
// Name: private: void CCommandBuffer::InsertCommandAtAppropriateTime(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommandBuffer::InsertCommandAtAppropriateTime(CCommandBuffer *this, _DWORD *hCommand)
{
  _DWORD *i; // ebx
  CUtlFixedLinkedList<CCommandBuffer::Command_t> *p_m_Commands; // edi
  _DWORD *v4; // eax
  int v5; // eax
  int m_Tail; // eax

  for ( i = (_DWORD *)this->m_Commands.m_Head; i != nullptr; i = (_DWORD *)i[4] )
  {
    if ( *i > *hCommand )
      break;
  }
  p_m_Commands = &this->m_Commands;
  if ( hCommand != nullptr
    && !CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int>>::IsIdxAfter(
          this: &this->m_Commands.m_Memory,
          i: (unsigned int)hCommand,
          it: &this->m_Commands.m_LastAlloc) )
  {
    v4 = (_DWORD *)hCommand[3];
    if ( v4 != hCommand )
    {
      if ( v4 != nullptr )
        v4[4] = hCommand[4];
      else
        p_m_Commands->m_Head = hCommand[4];
      v5 = hCommand[4];
      if ( v5 != 0 )
        *(_DWORD *)(v5 + 12) = hCommand[3];
      else
        p_m_Commands->m_Tail = hCommand[3];
      hCommand[4] = hCommand;
      hCommand[3] = hCommand;
      --p_m_Commands->m_ElementCount;
    }
  }
  hCommand[4] = i;
  if ( i != nullptr )
  {
    m_Tail = i[3];
    hCommand[3] = m_Tail;
    i[3] = hCommand;
  }
  else
  {
    m_Tail = p_m_Commands->m_Tail;
    hCommand[3] = m_Tail;
    p_m_Commands->m_Tail = (int)hCommand;
  }
  if ( m_Tail != 0 )
  {
    *(_DWORD *)(m_Tail + 16) = hCommand;
    ++p_m_Commands->m_ElementCount;
  }
  else
  {
    ++p_m_Commands->m_ElementCount;
    p_m_Commands->m_Head = (int)hCommand;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102770F0
// Name: private: bool CCommandBuffer::InsertCommand(char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCommandBuffer::InsertCommand(CCommandBuffer *this, char *pArgS, int nCommandSize, int nTick)
{
  int m_nArgSBufferSize; // eax
  _DWORD *v7; // eax

  if ( nCommandSize >= 511 )
  {
    _Warning(a1: "WARNING: Command too long... ignoring!\n%s\n", pArgS);
    return 0;
  }
  m_nArgSBufferSize = this->m_nArgSBufferSize;
  if ( m_nArgSBufferSize + nCommandSize + 1 > this->m_nMaxArgSBufferLength )
  {
    CCommandBuffer::Compact(this);
    m_nArgSBufferSize = this->m_nArgSBufferSize;
    if ( m_nArgSBufferSize + nCommandSize + 1 > this->m_nMaxArgSBufferLength )
      return 0;
  }
  memcpy(
    dst: (unsigned __int8 *)&this->m_pArgSBuffer[m_nArgSBufferSize],
    src: (unsigned __int8 *)pArgS,
    count: nCommandSize);
  this->m_pArgSBuffer[nCommandSize + this->m_nArgSBufferSize] = 0;
  v7 = (_DWORD *)CUtlLinkedList<CCommandBuffer::Command_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int>>>::AllocInternal(
                   this: &this->m_Commands,
                   multilist: false);
  *v7 = nTick;
  v7[1] = this->m_nArgSBufferSize;
  v7[2] = nCommandSize + 1;
  this->m_nArgSBufferSize += nCommandSize + 1;
  if ( this->m_bIsProcessingCommands && nTick <= this->m_nCurrentTick )
  {
    CUtlLinkedList<CCommandBuffer::Command_t,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int>>>::LinkBefore(
      this: &this->m_Commands,
      before: this->m_hNextCommand,
      elem: (int)v7);
    return 1;
  }
  else
  {
    CCommandBuffer::InsertCommandAtAppropriateTime(this, hCommand: v7);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102771D0
// Name: public: bool CCommandBuffer::AddText(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCommandBuffer::AddText(CCommandBuffer *this, char *pText, int nTickDelay)
{
  CCommandBuffer *v3; // ebx
  int v4; // ecx
  int v6; // esi
  void *v7; // esp
  const char *v8; // edi
  characterset_t *v9; // eax
  int v10; // eax
  unsigned __int8 *m_pMemory; // edx
  char v12[12]; // [esp+0h] [ebp-4Ch] BYREF
  CUtlBuffer bufParse; // [esp+Ch] [ebp-40h] BYREF
  int nOffsetToNextCommand; // [esp+3Ch] [ebp-10h] BYREF
  int nCommandLength; // [esp+40h] [ebp-Ch] BYREF
  int nLen; // [esp+44h] [ebp-8h]
  CCommandBuffer *v17; // [esp+48h] [ebp-4h]
  int nTick; // [esp+58h] [ebp+Ch]

  v3 = this;
  v17 = this;
  v4 = _V_strlen(str: pText);
  nLen = v4;
  nTick = nTickDelay + v3->m_nCurrentTick;
  if ( v4 <= 0 )
    return 1;
  while ( 1 )
  {
    CCommandBuffer::GetNextCommandLength(
      this: v3,
      pText,
      nMaxLen: v4,
      pCommandLength: &nCommandLength,
      pNextCommandOffset: &nOffsetToNextCommand);
    v6 = nCommandLength;
    if ( nCommandLength > 0 )
    {
      v7 = alloca(nCommandLength + 1);
      CUtlBuffer::CUtlBuffer(this: &bufParse, pBuffer: (unsigned __int8 *)pText, nSize: nCommandLength, nFlags: 9u);
      v12[0] = 0;
      v8 = nullptr;
      if ( bufParse.m_Error == 0 )
        break;
      m_pMemory = bufParse.m_Memory.m_pMemory;
LABEL_17:
      if ( bufParse.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
    }
LABEL_25:
    v4 = -1 - nOffsetToNextCommand + nLen;
    nLen = v4;
    pText += nOffsetToNextCommand + 1;
    if ( v4 <= 0 )
      return 1;
    v3 = v17;
  }
  v9 = CCommand::DefaultBreakSet();
  v10 = CUtlBuffer::ParseToken(this: &bufParse, pBreaks: v9, pTokenBuf: v12, nMaxLen: v6 + 1, bParseComments: 1);
  m_pMemory = bufParse.m_Memory.m_pMemory;
  if ( v10 > 0 && v6 + 1 != v10 )
  {
    if ( bufParse.m_nMaxPut - bufParse.m_Get <= 0 )
      v8 = nullptr;
    else
      v8 = (const char *)&bufParse.m_Memory.m_pMemory[bufParse.m_Get - bufParse.m_nOffset];
  }
  if ( v12[0] == 0 )
    goto LABEL_17;
  if ( _V_stricmp(s1: v12, s2: "wait") == 0 && v17->m_bWaitEnabled )
  {
    if ( v8 != nullptr )
      nTick += atoi(nptr: v8);
    else
      nTick += v17->m_nWaitDelayTicks;
LABEL_22:
    if ( bufParse.m_Memory.m_nGrowSize >= 0 && bufParse.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bufParse.m_Memory.m_pMemory);
    goto LABEL_25;
  }
  if ( CCommandBuffer::InsertCommand(this: v17, pArgS: pText, nCommandSize: v6, nTick) != 0 )
    goto LABEL_22;
  if ( bufParse.m_Memory.m_nGrowSize >= 0 && bufParse.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bufParse.m_Memory.m_pMemory);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10277380
// Name: public: CCommandBuffer::CCommandBuffer(void)
// Source: json
//------------------------------------------------------------------------------
CCommandBuffer *__thiscall CCommandBuffer::CCommandBuffer(CCommandBuffer *this)
{
  CUtlFixedLinkedList<CCommandBuffer::Command_t> *p_m_Commands; // ecx

  p_m_Commands = &this->m_Commands;
  p_m_Commands->m_Memory.m_pBlocks = nullptr;
  this->m_Commands.m_Memory.m_nAllocationCount = 0;
  this->m_Commands.m_Memory.m_nGrowSize = 32;
  CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int>>::Grow(this: &p_m_Commands->m_Memory, num: 32);
  this->m_Commands.m_LastAlloc.m_pBlockHeader = nullptr;
  this->m_Commands.m_LastAlloc.m_nIndex = -1;
  this->m_Commands.m_Head = 0;
  this->m_Commands.m_Tail = 0;
  this->m_Commands.m_FirstFree = 0;
  this->m_Commands.m_ElementCount = 0;
  this->m_Commands.m_NumAlloced = 0;
  this->m_Commands.m_pElements = nullptr;
  CCommand::CCommand(this: &this->m_CurrentCommand);
  this->m_hNextCommand = 0;
  this->m_nCurrentTick = 0;
  this->m_nArgSBufferSize = 0;
  this->m_bIsProcessingCommands = false;
  this->m_nWaitDelayTicks = 1;
  this->m_nLastTickToProcess = -1;
  this->m_nMaxArgSBufferLength = 0x2000;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102774B0
// Name: public: void CCommandBuffer::EndProcessingCommands(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommandBuffer::EndProcessingCommands(CCommandBuffer *this)
{
  int *m_Head; // esi
  int *v3; // eax
  int v4; // eax

  m_Head = (int *)this->m_Commands.m_Head;
  this->m_nCurrentTick = this->m_nLastTickToProcess + 1;
  this->m_bIsProcessingCommands = false;
  this->m_hNextCommand = 0;
  if ( m_Head != nullptr )
  {
    while ( *m_Head < this->m_nCurrentTick )
    {
      _Msg(a1: "Warning: Skipping command %s\n", (const char *)this->m_pArgSBuffer[m_Head[1]]);
      if ( !CUtlFixedMemory<UtlLinkedListElem_t<CCommandBuffer::Command_t,int>>::IsIdxAfter(
              this: &this->m_Commands.m_Memory,
              i: (unsigned int)m_Head,
              it: &this->m_Commands.m_LastAlloc) )
      {
        v3 = (int *)m_Head[3];
        if ( v3 != m_Head )
        {
          if ( v3 != nullptr )
            v3[4] = m_Head[4];
          else
            this->m_Commands.m_Head = m_Head[4];
          v4 = m_Head[4];
          if ( v4 != 0 )
            *(_DWORD *)(v4 + 12) = m_Head[3];
          else
            this->m_Commands.m_Tail = m_Head[3];
          m_Head[4] = (int)m_Head;
          m_Head[3] = (int)m_Head;
          --this->m_Commands.m_ElementCount;
        }
      }
      m_Head[4] = this->m_Commands.m_FirstFree;
      this->m_Commands.m_FirstFree = (int)m_Head;
    }
    CCommandBuffer::Compact(this);
  }
  else
  {
    this->m_nArgSBufferSize = 0;
  }
}

} // namespace engine_xlsp
