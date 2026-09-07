// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/audio/private/snd_op_sys/sos_system.cpp
// Functions: 44
// ============================================================

#include "engine\audio\private\snd_op_sys\sos_system.h"

//------------------------------------------------------------------------------
// Address: 0x1004F4D0
// Name: public: void CSosOperatorStack::SetStopType(enum SOSStopType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorStack::SetStopType(CSosOperatorStack *this, SOSStopType_t stopType)
{
  if ( stopType != SOS_STOP_NONE )
    this->m_stopType = stopType;
}

//------------------------------------------------------------------------------
// Address: 0x1004F4F0
// Name: public: bool CSosOperatorStackList::HasStack(enum CSosOperatorStack::SOSType_t)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSosOperatorStackList::HasStack(CSosOperatorStackList *this, CSosOperatorStack::SOSType_t SosType)
{
  bool v3; // zf

  if ( SosType == SOS_UPDATE )
  {
    v3 = this->m_vUpdateStack == nullptr;
  }
  else
  {
    if ( SosType != SOS_CUE )
      return SosType == SOS_STOP && this->m_vStopStack != nullptr;
    v3 = this->m_vCueStack == nullptr;
  }
  return !v3;
}

//------------------------------------------------------------------------------
// Address: 0x1004F530
// Name: public: class CSosOperatorStack __near * CSosOperatorStackList::GetStack(enum CSosOperatorStack::SOSType_t)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorStack *__thiscall CSosOperatorStackList::GetStack(
        CSosOperatorStackList *this,
        CSosOperatorStack::SOSType_t SosType)
{
  switch ( SosType )
  {
    case SOS_UPDATE:
      return this->m_vUpdateStack;
    case SOS_CUE:
      return this->m_vCueStack;
    case SOS_STOP:
      return this->m_vStopStack;
    default:
      break;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1004F560
// Name: public: void CSosOperatorStackList::SetScriptHandle(short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorStackList::SetScriptHandle(CSosOperatorStackList *this, __int16 nHandle)
{
  CSosOperatorStack *m_vCueStack; // eax
  CSosOperatorStack *m_vStopStack; // ecx

  m_vCueStack = this->m_vCueStack;
  if ( m_vCueStack != nullptr )
    m_vCueStack->m_nScriptHandle = nHandle;
  if ( this->m_vUpdateStack != nullptr )
    this->m_vUpdateStack->m_nScriptHandle = nHandle;
  m_vStopStack = this->m_vStopStack;
  if ( m_vStopStack != nullptr )
    m_vStopStack->m_nScriptHandle = nHandle;
}

//------------------------------------------------------------------------------
// Address: 0x1004F5A0
// Name: public: void CSosOperatorStackList::SetChannelGuid(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorStackList::SetChannelGuid(CSosOperatorStackList *this, int nGuid)
{
  CSosOperatorStack *m_vCueStack; // eax
  CSosOperatorStack *m_vStopStack; // ecx

  m_vCueStack = this->m_vCueStack;
  if ( m_vCueStack != nullptr )
    m_vCueStack->m_nChannelGuid = nGuid;
  if ( this->m_vUpdateStack != nullptr )
    this->m_vUpdateStack->m_nChannelGuid = nGuid;
  m_vStopStack = this->m_vStopStack;
  if ( m_vStopStack != nullptr )
    m_vStopStack->m_nChannelGuid = nGuid;
}

//------------------------------------------------------------------------------
// Address: 0x1004F5D0
// Name: public: void CSosOperatorStackList::SetStartTime(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorStackList::SetStartTime(CSosOperatorStackList *this, float flStartTime)
{
  CSosOperatorStack *m_vCueStack; // eax
  CSosOperatorStack *m_vStopStack; // ecx

  m_vCueStack = this->m_vCueStack;
  if ( m_vCueStack != nullptr )
    m_vCueStack->m_flStartTime = flStartTime;
  if ( this->m_vUpdateStack != nullptr )
    this->m_vUpdateStack->m_flStartTime = flStartTime;
  m_vStopStack = this->m_vStopStack;
  if ( m_vStopStack != nullptr )
    m_vStopStack->m_flStartTime = flStartTime;
}

//------------------------------------------------------------------------------
// Address: 0x1004F610
// Name: public: void CSosOperatorStackList::SetStopTime(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorStackList::SetStopTime(CSosOperatorStackList *this, float flStopTime)
{
  CSosOperatorStack *m_vCueStack; // eax
  CSosOperatorStack *m_vStopStack; // ecx

  m_vCueStack = this->m_vCueStack;
  this->m_flStopTime = flStopTime;
  if ( m_vCueStack != nullptr )
    m_vCueStack->m_flStopTime = flStopTime;
  if ( this->m_vUpdateStack != nullptr )
    this->m_vUpdateStack->m_flStopTime = flStopTime;
  m_vStopStack = this->m_vStopStack;
  if ( m_vStopStack != nullptr )
    m_vStopStack->m_flStopTime = flStopTime;
}

//------------------------------------------------------------------------------
// Address: 0x1004F650
// Name: public: void CSosOperatorStackList::SetStopType(enum SOSStopType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorStackList::SetStopType(CSosOperatorStackList *this, SOSStopType_t stopType)
{
  CSosOperatorStack *m_vCueStack; // edx
  CSosOperatorStack *m_vStopStack; // ecx

  m_vCueStack = this->m_vCueStack;
  this->m_stopType = stopType;
  if ( m_vCueStack != nullptr && stopType != SOS_STOP_NONE )
    m_vCueStack->m_stopType = stopType;
  if ( this->m_vUpdateStack != nullptr && stopType != SOS_STOP_NONE )
    this->m_vUpdateStack->m_stopType = stopType;
  m_vStopStack = this->m_vStopStack;
  if ( m_vStopStack != nullptr && stopType != SOS_STOP_NONE )
    m_vStopStack->m_stopType = stopType;
}

//------------------------------------------------------------------------------
// Address: 0x1004F690
// Name: public: void CSosOperatorSystem::Update(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorSystem::Update(CSosOperatorSystem *this)
{
  CSosEntryMatchList::Update(this: &this->m_sosEntryBlockList);
}

//------------------------------------------------------------------------------
// Address: 0x1004F6A0
// Name: public: CSosEntryMatchList::CSosEntryMatchList(void)
// Source: json
//------------------------------------------------------------------------------
CSosEntryMatchList *__thiscall CSosEntryMatchList::CSosEntryMatchList(CSosEntryMatchList *this)
{
  int i; // edi
  _WORD *v3; // eax
  unsigned int bit; // [esp+Ch] [ebp-4h]

  bit = 1;
  for ( i = 0; i < 32; ++i )
  {
    v3 = MemAlloc_Alloc(nSize: 0xA0u);
    if ( v3 != nullptr )
    {
      *(_BYTE *)v3 = 10;
      v3[32] = 2560;
      *(_WORD *)((char *)v3 + 129) = 0;
      *((_DWORD *)v3 + 33) = -1;
      *((_BYTE *)v3 + 136) = 0;
      *((_DWORD *)v3 + 35) = -1;
      *((_BYTE *)v3 + 144) = 0;
    }
    else
    {
      v3 = nullptr;
    }
    this->m_vEntryMatchList[i] = (CSosManagedEntryMatch *)v3;
    *(_BYTE *)v3 = 10;
    v3[32] = 2560;
    *(_WORD *)((char *)v3 + 129) = 0;
    *((_DWORD *)v3 + 33) = -1;
    *((_BYTE *)v3 + 136) = 0;
    *((_DWORD *)v3 + 35) = -1;
    *((_BYTE *)v3 + 144) = 0;
    *(_WORD *)((char *)v3 + 149) = 0;
    *((_DWORD *)v3 + 38) = -1082130432;
    *((_DWORD *)v3 + 39) = -1082130432;
    *((_BYTE *)v3 + 148) = 1;
    this->m_Free |= bit;
    bit *= 2;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1004F770
// Name: public: int CSosOperatorStack::GetOperatorOffset(int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CSosOperatorStack::GetOperatorOffset(CSosOperatorStack *this, int nIndex)
{
  int v3; // esi
  CSosOperator *v6; // ecx
  unsigned int memOffset; // [esp+14h] [ebp+8h]

  v3 = 0;
  if ( nIndex < 0 || nIndex >= this->m_vStack.m_Size )
    return -1;
  memOffset = 0;
  if ( nIndex > 0 )
  {
    do
    {
      v6 = this->m_vStack.m_Memory.m_pMemory[v3];
      if ( v6 != nullptr )
        memOffset += v6->GetSize(this: v6);
      ++v3;
    }
    while ( v3 < nIndex );
  }
  return memOffset;
}

//------------------------------------------------------------------------------
// Address: 0x1004F7C0
// Name: public: void CSosOperatorStack::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorStack::Shutdown(CSosOperatorStack *this)
{
  int v1; // edi
  char *v3; // ebx
  CSosOperator *v4; // ecx
  CSosOperator *v5; // ecx
  unsigned int TotalSize; // [esp+8h] [ebp-4h]

  v1 = 0;
  for ( TotalSize = 0; v1 < this->m_vStack.m_Size; ++v1 )
  {
    v3 = (char *)this->m_pMemPool + TotalSize;
    CSosOperator::ResolveInputValues(
      this: this->m_vStack.m_Memory.m_pMemory[v1],
      pStructMem: v3,
      pStackMem: (char *)this->m_pMemPool);
    v4 = this->m_vStack.m_Memory.m_pMemory[v1];
    v4->StackShutdown(this: v4, a2: v3, a3: this, a4: v1);
    v5 = this->m_vStack.m_Memory.m_pMemory[v1];
    TotalSize += v5->GetSize(this: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004F820
// Name: public: void CSosOperatorStack::Execute(struct channel_t __near *,class CScratchPad __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorStack::Execute(CSosOperatorStack *this, channel_t *pChannel, CScratchPad *pScratchPad)
{
  int v3; // edi
  char *v5; // ebx
  CSosOperator *v6; // ecx
  CSosOperator *v7; // ecx
  CSosOperator *v8; // ecx
  unsigned int TotalSize; // [esp+8h] [ebp-4h]

  v3 = 0;
  if ( snd_sos_show_operator_updates.m_pParent != nullptr
    && snd_sos_show_operator_updates.m_pParent->m_Value.m_nValue != 0
    && (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
  {
    LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: LS_MESSAGE, a3: StackColor, a4: "Operator Stack: %s\n", this->m_nName);
  }
  if ( pChannel == nullptr )
    pChannel = S_FindChannelByGuid(guid: this->m_nChannelGuid);
  TotalSize = 0;
  if ( this->m_vStack.m_Size > 0 )
  {
    do
    {
      v5 = (char *)this->m_pMemPool + TotalSize;
      CSosOperator::ResolveInputValues(
        this: this->m_vStack.m_Memory.m_pMemory[v3],
        pStructMem: v5,
        pStackMem: (char *)this->m_pMemPool);
      if ( *(float *)v5 <= 0.0 || v5[8] != 0 && v5[9] != 0 )
      {
        if ( snd_sos_show_operator_updates.m_pParent != nullptr
          && snd_sos_show_operator_updates.m_pParent->m_Value.m_nValue != 0 )
        {
          v7 = this->m_vStack.m_Memory.m_pMemory[v3];
          v7->Print(this: v7, a2: v5, a3: this, a4: v3, a5: 1);
        }
      }
      else
      {
        v6 = this->m_vStack.m_Memory.m_pMemory[v3];
        v6->Execute(this: v6, a2: v5, a3: pChannel, a4: pScratchPad, a5: this, a6: v3);
        v5[9] = 1;
      }
      v8 = this->m_vStack.m_Memory.m_pMemory[v3];
      TotalSize += v8->GetSize(this: v8);
      ++v3;
    }
    while ( v3 < this->m_vStack.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004F930
// Name: public: void CSosOperatorStack::Print(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorStack::Print(CSosOperatorStack *this, unsigned int nLevel)
{
  int v2; // edi
  CSosOperator *v5; // ecx
  CSosOperator *v6; // ecx
  unsigned int TotalSize; // [esp+14h] [ebp+8h]

  v2 = 0;
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
    LoggingSystem_Log(
      a1: LOG_SND_OPERATORS,
      a2: LS_MESSAGE,
      a3: StackColor,
      a4: "\n%*sOperator Stack: %s\n%*sSize: %i\n",
      nLevel,
      "    ",
      this->m_nName,
      nLevel,
      "    ",
      this->m_nMemSize);
  TotalSize = 0;
  if ( this->m_vStack.m_Size > 0 )
  {
    do
    {
      v5 = this->m_vStack.m_Memory.m_pMemory[v2];
      v5->Print(this: v5, a2: (char *)this->m_pMemPool + TotalSize, a3: this, a4: v2, a5: nLevel);
      v6 = this->m_vStack.m_Memory.m_pMemory[v2];
      TotalSize += v6->GetSize(this: v6);
      ++v2;
    }
    while ( v2 < this->m_vStack.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004F9C0
// Name: public: void CSosOperatorStackList::Execute(enum CSosOperatorStack::SOSType_t,struct channel_t __near *,class CScratchPad __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorStackList::Execute(
        CSosOperatorStackList *this,
        CSosOperatorStack::SOSType_t SosType,
        channel_t *pChannel,
        CScratchPad *pScratchPad)
{
  CSosOperatorStack *m_vCueStack; // ecx
  SOSStopType_t m_stopType; // eax

  if ( SosType == SOS_UPDATE )
  {
    if ( this->m_vUpdateStack != nullptr )
    {
      m_stopType = this->m_stopType;
      if ( m_stopType != SOS_STOP_NONE )
        this->m_vUpdateStack->m_stopType = m_stopType;
      CSosOperatorStack::Execute(this: this->m_vUpdateStack, pChannel, pScratchPad);
      CSosOperatorStackList::SetStopType(this, stopType: this->m_vUpdateStack->m_stopType);
    }
  }
  else
  {
    if ( SosType == SOS_CUE )
    {
      m_vCueStack = this->m_vCueStack;
    }
    else
    {
      if ( SosType != SOS_STOP )
        return;
      m_vCueStack = this->m_vStopStack;
    }
    if ( m_vCueStack != nullptr )
      CSosOperatorStack::Execute(this: m_vCueStack, pChannel, pScratchPad);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004FA30
// Name: public: void CSosOperatorStackList::Print(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorStackList::Print(CSosOperatorStackList *this)
{
  CSosOperatorStack *m_vCueStack; // ecx
  CSosOperatorStack *m_vStopStack; // ecx

  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: 0) != 0 )
    LoggingSystem_Log(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: LS_MESSAGE, a3: StackColor, a4: "\nStack List:\n");
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: 0) != 0 )
    LoggingSystem_Log(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: LS_MESSAGE, a3: StackColor, a4: "\nCUE Operators:\n");
  m_vCueStack = this->m_vCueStack;
  if ( m_vCueStack != nullptr )
    CSosOperatorStack::Print(this: m_vCueStack, nLevel: 1u);
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: 0) != 0 )
    LoggingSystem_Log(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: LS_MESSAGE, a3: StackColor, a4: "\nUPDATE Operators:\n");
  if ( this->m_vUpdateStack != nullptr )
    CSosOperatorStack::Print(this: this->m_vUpdateStack, nLevel: 1u);
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: 0) != 0 )
    LoggingSystem_Log(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: LS_MESSAGE, a3: StackColor, a4: "\nSTOP Operators:\n");
  m_vStopStack = this->m_vStopStack;
  if ( m_vStopStack != nullptr )
    CSosOperatorStack::Print(this: m_vStopStack, nLevel: 1u);
}

//------------------------------------------------------------------------------
// Address: 0x1004FB20
// Name: public: void CSosOperatorStackList::StopStacks(enum SOSStopType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorStackList::StopStacks(CSosOperatorStackList *this, SOSStopType_t stopType)
{
  CSosOperatorStack *m_vCueStack; // eax
  CSosOperatorStack *m_vStopStack; // esi
  CSosOperatorStack *v5; // eax
  CSosOperatorStack *v6; // eax
  CSosOperatorStack *v7; // ecx
  float stopTypea; // [esp+Ch] [ebp+8h]

  if ( stopType == SOS_STOP_FORCE )
  {
    m_vCueStack = this->m_vCueStack;
    this->m_stopType = SOS_STOP_FORCE;
    if ( m_vCueStack != nullptr )
      m_vCueStack->m_stopType = SOS_STOP_FORCE;
    if ( this->m_vUpdateStack != nullptr )
      this->m_vUpdateStack->m_stopType = SOS_STOP_FORCE;
    m_vStopStack = this->m_vStopStack;
    if ( m_vStopStack != nullptr )
      m_vStopStack->m_stopType = SOS_STOP_FORCE;
  }
  else if ( this->m_stopType == SOS_STOP_NONE && stopType != SOS_STOP_NONE )
  {
    CSosOperatorStackList::SetStopType(this, stopType);
    stopTypea = g_pSoundServices->GetHostTime(this: g_pSoundServices);
    v5 = this->m_vCueStack;
    this->m_flStopTime = stopTypea;
    if ( v5 != nullptr )
      v5->m_flStopTime = stopTypea;
    if ( this->m_vUpdateStack != nullptr )
      this->m_vUpdateStack->m_flStopTime = stopTypea;
    v6 = this->m_vStopStack;
    if ( v6 != nullptr )
      v6->m_flStopTime = stopTypea;
    v7 = this->m_vStopStack;
    if ( v7 != nullptr )
      CSosOperatorStack::Execute(this: v7, pChannel: nullptr, pScratchPad: &g_scratchpad);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004FBD0
// Name: public: CTSQueue<int,0,1>::CTSQueue<int,0,1>(void)
// Source: json
//------------------------------------------------------------------------------
CTSQueue<int,0,1> *__thiscall CTSQueue<int,0,1>::CTSQueue<int,0,1>(CTSQueue<int,0,1> *this)
{
  CTSListBase *p_m_FreeNodes; // ebx
  CTSQueue<int,0,1>::Node_t *v3; // eax

  p_m_FreeNodes = &this->m_FreeNodes;
  this->m_Count.m_value = 0;
  if ( (((_BYTE)this + 24) & 7) != 0 )
  {
    _Error(a1: "CTSListBase: Misaligned list\n");
    __debugbreak();
  }
  p_m_FreeNodes->m_Head.value.Next = nullptr;
  p_m_FreeNodes->m_Head.value32.DepthAndSequence = 0;
  if ( ((unsigned __int8)this & 7) != 0 )
  {
    _Error(a1: "CTSQueue: Misaligned queue\n");
    __debugbreak();
    _Error(a1: "CTSQueue: Misaligned queue\n");
    __debugbreak();
  }
  _InterlockedExchange(&this->m_Count.m_value, 0);
  this->m_Tail.value.sequence = 0;
  this->m_Head.value.sequence = 0;
  v3 = (CTSQueue<int,0,1>::Node_t *)MemAlloc_Alloc(nSize: 8u);
  this->m_Tail.value.pNode = v3;
  this->m_Head.value.pNode = v3;
  v3->pNext = (CTSQueue<int,0,1>::Node_t *)this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10050EF0
// Name: public: void CSosOperatorStackCollection::Print(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorStackCollection::Print(CSosOperatorStackCollection *this)
{
  unsigned __int8 (__cdecl *v1)(int, _DWORD); // ebx
  unsigned int v3; // edi
  int v4; // ebx
  unsigned int v5; // edi
  int v6; // ebx
  unsigned int v7; // edi
  int v8; // ebx
  unsigned int v9; // edi
  int v10; // ebx

  v1 = (unsigned __int8 (__cdecl *)(int, _DWORD))_LoggingSystem_IsChannelEnabled;
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
    LoggingSystem_Log(
      a1: LOG_SND_OPERATORS,
      a2: LS_MESSAGE,
      a3: CollectionColor,
      a4: "\n\nSound Operators Collection:\n");
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
    LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: LS_MESSAGE, a3: CollectionColor, a4: "\n%*sCue Stacks:\n", 1, "    ");
  v3 = 0;
  if ( this->m_vCueStacks.m_Elements.m_Tree.m_NumElements != 0 )
  {
    v4 = 0;
    do
    {
      CSosOperatorStack::Print(
        this: this->m_vCueStacks.m_Elements.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem,
        nLevel: 3u);
      ++v3;
      ++v4;
    }
    while ( v3 < this->m_vCueStacks.m_Elements.m_Tree.m_NumElements );
    v1 = (unsigned __int8 (__cdecl *)(int, _DWORD))_LoggingSystem_IsChannelEnabled;
  }
  if ( v1(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
    LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: LS_MESSAGE, a3: CollectionColor, a4: "\n%*sStart Stacks:\n", 1, "    ");
  v5 = 0;
  if ( this->m_vStartStacks.m_Elements.m_Tree.m_NumElements != 0 )
  {
    v6 = 0;
    do
    {
      CSosOperatorStack::Print(
        this: this->m_vStartStacks.m_Elements.m_Tree.m_Elements.m_pMemory[v6].m_Data.elem,
        nLevel: 3u);
      ++v5;
      ++v6;
    }
    while ( v5 < this->m_vStartStacks.m_Elements.m_Tree.m_NumElements );
    v1 = (unsigned __int8 (__cdecl *)(int, _DWORD))_LoggingSystem_IsChannelEnabled;
  }
  if ( v1(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
    LoggingSystem_Log(
      a1: LOG_SND_OPERATORS,
      a2: LS_MESSAGE,
      a3: CollectionColor,
      a4: "\n%*sUpdate Stacks:\n",
      1,
      "    ");
  v7 = 0;
  if ( this->m_vUpdateStacks.m_Elements.m_Tree.m_NumElements != 0 )
  {
    v8 = 0;
    do
    {
      CSosOperatorStack::Print(
        this: this->m_vUpdateStacks.m_Elements.m_Tree.m_Elements.m_pMemory[v8].m_Data.elem,
        nLevel: 3u);
      ++v7;
      ++v8;
    }
    while ( v7 < this->m_vUpdateStacks.m_Elements.m_Tree.m_NumElements );
    v1 = (unsigned __int8 (__cdecl *)(int, _DWORD))_LoggingSystem_IsChannelEnabled;
  }
  if ( v1(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
    LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: LS_MESSAGE, a3: CollectionColor, a4: "\n%*sStop Stacks:\n", 1, "    ");
  v9 = 0;
  if ( this->m_vStopStacks.m_Elements.m_Tree.m_NumElements != 0 )
  {
    v10 = 0;
    do
    {
      CSosOperatorStack::Print(
        this: this->m_vStopStacks.m_Elements.m_Tree.m_Elements.m_pMemory[v10].m_Data.elem,
        nLevel: 3u);
      ++v9;
      ++v10;
    }
    while ( v9 < this->m_vStopStacks.m_Elements.m_Tree.m_NumElements );
    v1 = (unsigned __int8 (__cdecl *)(int, _DWORD))_LoggingSystem_IsChannelEnabled;
  }
  if ( v1(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
    LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: LS_MESSAGE, a3: CollectionColor, a4: "\n");
}

//------------------------------------------------------------------------------
// Address: 0x100510F0
// Name: public: void CSosOperatorSystem::StartQueuedEntries(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorSystem::StartQueuedEntries(CSosOperatorSystem *this)
{
  CTSQueue<StartSoundParams_t,0,1> *p_m_sosStartEntryQueue; // ebx
  CTSQueue<StartSoundParams_t,0,1>::Node_t *v2; // eax
  TSLNodeBase_t *v3; // edi
  StartSoundParams_t soundParams; // [esp+0h] [ebp-64h] BYREF

  if ( this->m_sosStartEntryQueue.m_Count.m_value != 0 )
  {
    p_m_sosStartEntryQueue = &this->m_sosStartEntryQueue;
    while ( 1 )
    {
      *((_BYTE *)&soundParams + 96) = *((_BYTE *)&soundParams + 96) & 0xC0 | 2;
      memset(&soundParams, 0, 40);
      soundParams.fvol = 1.0;
      soundParams.soundlevel = SNDLVL_NORM;
      soundParams.flags = 0;
      soundParams.pitch = 100;
      soundParams.delay = 0.0;
      soundParams.speakerentity = -1;
      soundParams.initialStreamPosition = 0;
      soundParams.skipInitialSamples = 0;
      soundParams.m_nQueuedGUID = -1;
      soundParams.m_nSoundScriptHandle = -1;
      memset(&soundParams.m_pSoundEntryName, 0, 16);
      v2 = CTSQueue<StartSoundParams_t,0,1>::Pop(this: p_m_sosStartEntryQueue);
      v3 = (TSLNodeBase_t *)v2;
      if ( v2 == nullptr )
        break;
      StartSoundParams_t::operator=(this: &soundParams, __that: &v2->elem);
      CTSListBase::Push(this: &p_m_sosStartEntryQueue->m_FreeNodes, pNode: v3);
      S_StartSoundEntry(pStartParams: &soundParams, nSeed: -1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100511D0
// Name: public: void CSosOperatorSystem::StopQueuedChannels(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorSystem::StopQueuedChannels(CSosOperatorSystem *this)
{
  CTSQueue<int,0,1> *p_m_sosStopChannelQueue; // edi
  CTSQueue<int,0,1>::Node_t *v2; // eax
  int elem; // esi

  if ( this->m_sosStopChannelQueue.m_Count.m_value != 0 )
  {
    p_m_sosStopChannelQueue = &this->m_sosStopChannelQueue;
    while ( 1 )
    {
      v2 = CTSQueue<loopback_t *,0,1>::Pop(this: p_m_sosStopChannelQueue);
      if ( v2 == nullptr )
        break;
      elem = v2->elem;
      CTSListBase::Push(this: &p_m_sosStopChannelQueue->m_FreeNodes, pNode: (TSLNodeBase_t *)v2);
      if ( elem != -1 )
        S_StopSoundByGuid(guid: elem, bForceSync: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100513E0
// Name: public: class CSosOperator __near * CSosOperatorStack::FindOperator(char const __near *,void __near * __near *)
// Source: json
//------------------------------------------------------------------------------
CSosOperator *__thiscall CSosOperatorStack::FindOperator(
        CSosOperatorStack *this,
        const char *pName,
        void **pStructHandle)
{
  int v4; // ebx
  int v5; // esi
  CSosOperator *v6; // ecx
  CUtlMap<char const *,int,int>::Node_t search; // [esp+Ch] [ebp-8h] BYREF
  int nOpIndex; // [esp+1Ch] [ebp+8h]

  if ( pName != nullptr )
  {
    search.key = pName;
    nOpIndex = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Find(
                 this: &this->m_vOperatorMap.m_Elements.m_Tree,
                 &search);
  }
  else
  {
    nOpIndex = -1;
  }
  v4 = 0;
  v5 = 0;
  *pStructHandle = this->m_pMemPool;
  if ( nOpIndex <= 0 )
    return this->m_vStack.m_Memory.m_pMemory[nOpIndex];
  while ( 1 )
  {
    v6 = this->m_vStack.m_Memory.m_pMemory[v5];
    if ( v6 == nullptr )
      break;
    v4 += v6->GetSize(this: v6);
    ++v5;
    *pStructHandle = (char *)this->m_pMemPool + v4;
    if ( v5 >= nOpIndex )
      return this->m_vStack.m_Memory.m_pMemory[nOpIndex];
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10051460
// Name: public: int CSosOperatorStack::GetOperatorOutputOffset(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CSosOperatorStack::GetOperatorOutputOffset(
        CSosOperatorStack *this,
        const char *pOperatorName,
        const char *pOutputName)
{
  int v4; // eax
  CSosOperator *v6; // edi
  unsigned int OperatorOffset; // esi
  CUtlMap<char const *,int,int>::Node_t search; // [esp+8h] [ebp-8h] BYREF

  if ( pOperatorName != nullptr
    && (search.key = pOperatorName,
        (v4 = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Find(
                this: &this->m_vOperatorMap.m_Elements.m_Tree,
                &search)) >= 0)
    && v4 < this->m_vStack.m_Size )
  {
    v6 = this->m_vStack.m_Memory.m_pMemory[v4];
    OperatorOffset = CSosOperatorStack::GetOperatorOffset(this, nIndex: v4);
    return OperatorOffset + CSosOperator::GetOutputOffset(this: v6, pOutputName);
  }
  else
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
      _LoggingSystem_Log(
        a1: LOG_SND_OPERATORS,
        a2: 1,
        a3: "Error: Unable to find referenced operator: %s",
        pOperatorName);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100514F0
// Name: public: void CSosOperatorStack::ExecuteIterator(struct channel_t __near *,class CScratchPad __near *,void const __near *,char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorStack::ExecuteIterator(
        CSosOperatorStack *this,
        channel_t *pChannel,
        CScratchPad *pScratchPad,
        float *pStopMemBlock,
        const char *pOperatorName,
        int *pnOperatorIndex)
{
  int v7; // eax
  int v8; // esi
  char *m_pMemPool; // eax
  float *v10; // ebx
  CSosOperator *v11; // ecx
  CSosOperator *v12; // ecx
  CSosOperator *v13; // ecx
  CUtlMap<char const *,int,int>::Node_t search; // [esp+Ch] [ebp-8h] BYREF
  unsigned int TotalSize; // [esp+2Ch] [ebp+18h]

  if ( snd_sos_show_operator_updates.m_pParent != nullptr
    && snd_sos_show_operator_updates.m_pParent->m_Value.m_nValue != 0
    && (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
  {
    LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: LS_MESSAGE, a3: StackColor, a4: "Operator Stack: %s\n", this->m_nName);
  }
  search.elem = *pnOperatorIndex;
  if ( search.elem >= 0 )
    goto LABEL_10;
  if ( pOperatorName != nullptr )
  {
    search.key = pOperatorName;
    v7 = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Find(
           this: &this->m_vOperatorMap.m_Elements.m_Tree,
           &search);
    if ( v7 >= 0 && v7 < this->m_vStack.m_Size )
    {
      search.elem = v7;
      *pnOperatorIndex = v7;
LABEL_10:
      v8 = 0;
      for ( TotalSize = 0; v8 < this->m_vStack.m_Size; ++v8 )
      {
        m_pMemPool = (char *)this->m_pMemPool;
        v10 = (float *)&m_pMemPool[TotalSize];
        if ( v8 >= search.elem )
        {
          CSosOperator::ResolveInputValues(
            this: this->m_vStack.m_Memory.m_pMemory[v8],
            pStructMem: &m_pMemPool[TotalSize],
            pStackMem: (char *)this->m_pMemPool);
          if ( *v10 <= 0.0 || *((_BYTE *)v10 + 8) != 0 && *((_BYTE *)v10 + 9) != 0 )
          {
            if ( snd_sos_show_operator_updates.m_pParent != nullptr
              && snd_sos_show_operator_updates.m_pParent->m_Value.m_nValue != 0 )
            {
              v12 = this->m_vStack.m_Memory.m_pMemory[v8];
              v12->Print(this: v12, a2: v10, a3: this, a4: v8, a5: 1);
            }
          }
          else
          {
            v11 = this->m_vStack.m_Memory.m_pMemory[v8];
            v11->Execute(this: v11, a2: v10, a3: pChannel, a4: pScratchPad, a5: this, a6: v8);
            *((_BYTE *)v10 + 9) = 1;
          }
          if ( v10 == pStopMemBlock )
            break;
        }
        v13 = this->m_vStack.m_Memory.m_pMemory[v8];
        TotalSize += v13->GetSize(this: v13);
      }
      return;
    }
  }
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
    _LoggingSystem_Log(
      a1: LOG_SND_OPERATORS,
      a2: 1,
      a3: "Error: Execute iterator unable to find sound operator %s\n",
      pOperatorName);
}

//------------------------------------------------------------------------------
// Address: 0x10051660
// Name: public: CSosOperatorStackCollection::CSosOperatorStackCollection(void)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorStackCollection *__thiscall CSosOperatorStackCollection::CSosOperatorStackCollection(
        CSosOperatorStackCollection *this)
{
  CSosOperatorStackCollection *result; // eax

  result = this;
  this->m_vAllStacks.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_vAllStacks.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_vAllStacks.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_vAllStacks.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_vAllStacks.m_Elements.m_Tree.m_Root = -1;
  this->m_vAllStacks.m_Elements.m_Tree.m_NumElements = 0;
  this->m_vAllStacks.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_vAllStacks.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_vAllStacks.m_Elements.m_Tree.m_pElements = this->m_vAllStacks.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( this->m_vAllStacks.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_vAllStacks.m_Elements.m_Tree.m_LessFunc.m_LessFunc = CaselessStringLessThan;
  this->m_vUpdateStacks.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_vUpdateStacks.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_vUpdateStacks.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_vUpdateStacks.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_vUpdateStacks.m_Elements.m_Tree.m_Root = -1;
  this->m_vUpdateStacks.m_Elements.m_Tree.m_NumElements = 0;
  this->m_vUpdateStacks.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_vUpdateStacks.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_vUpdateStacks.m_Elements.m_Tree.m_pElements = this->m_vUpdateStacks.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( this->m_vUpdateStacks.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_vUpdateStacks.m_Elements.m_Tree.m_LessFunc.m_LessFunc = CaselessStringLessThan;
  this->m_vStartStacks.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_vStartStacks.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_vStartStacks.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_vStartStacks.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_vStartStacks.m_Elements.m_Tree.m_Root = -1;
  this->m_vStartStacks.m_Elements.m_Tree.m_NumElements = 0;
  this->m_vStartStacks.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_vStartStacks.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_vStartStacks.m_Elements.m_Tree.m_pElements = this->m_vStartStacks.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( this->m_vStartStacks.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_vStartStacks.m_Elements.m_Tree.m_LessFunc.m_LessFunc = CaselessStringLessThan;
  this->m_vStopStacks.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_vStopStacks.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_vStopStacks.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_vStopStacks.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_vStopStacks.m_Elements.m_Tree.m_Root = -1;
  this->m_vStopStacks.m_Elements.m_Tree.m_NumElements = 0;
  this->m_vStopStacks.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_vStopStacks.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_vStopStacks.m_Elements.m_Tree.m_pElements = this->m_vStopStacks.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( this->m_vStopStacks.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_vStopStacks.m_Elements.m_Tree.m_LessFunc.m_LessFunc = CaselessStringLessThan;
  this->m_vCueStacks.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_vCueStacks.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_vCueStacks.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_vCueStacks.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_vCueStacks.m_Elements.m_Tree.m_Root = -1;
  this->m_vCueStacks.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_vCueStacks.m_Elements.m_Tree.m_NumElements = 0;
  this->m_vCueStacks.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_vCueStacks.m_Elements.m_Tree.m_pElements = this->m_vCueStacks.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( this->m_vCueStacks.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_vCueStacks.m_Elements.m_Tree.m_LessFunc.m_LessFunc = CaselessStringLessThan;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100517E0
// Name: public: CSosOperatorStack::CSosOperatorStack(enum CSosOperatorStack::SOSType_t)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorStack *__thiscall CSosOperatorStack::CSosOperatorStack(
        CSosOperatorStack *this,
        CSosOperatorStack::SOSType_t SosType)
{
  CSosOperatorStack *result; // eax

  result = this;
  this->m_vStack.m_Memory.m_pMemory = nullptr;
  this->m_vStack.m_Memory.m_nAllocationCount = 0;
  this->m_vStack.m_Memory.m_nGrowSize = 0;
  this->m_vStack.m_Size = 0;
  this->m_vStack.m_pElements = nullptr;
  this->m_vOperatorMap.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_vOperatorMap.m_Elements.m_Tree.m_Root = -1;
  this->m_vOperatorMap.m_Elements.m_Tree.m_NumElements = 0;
  this->m_vOperatorMap.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_vOperatorMap.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_vOperatorMap.m_Elements.m_Tree.m_pElements = this->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( this->m_vOperatorMap.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_vOperatorMap.m_Elements.m_Tree.m_LessFunc.m_LessFunc = CaselessStringLessThan;
  this->m_SOSType = SosType;
  this->m_pMemPool = nullptr;
  this->m_nMemSize = 0;
  this->m_nChannelGuid = -1;
  this->m_flStartTime = -1.0;
  this->m_nScriptHandle = -1;
  this->m_stopType = SOS_STOP_NONE;
  this->m_flStopTime = -1.0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10051870
// Name: public: CSosOperatorStack::~CSosOperatorStack(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorStack::~CSosOperatorStack(CSosOperatorStack *this)
{
  void *m_pMemPool; // eax

  m_pMemPool = this->m_pMemPool;
  if ( m_pMemPool != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemPool);
  CUtlDict<int,int>::RemoveAll(this: &this->m_vOperatorMap);
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>(this: &this->m_vOperatorMap.m_Elements.m_Tree);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_vStack);
}

//------------------------------------------------------------------------------
// Address: 0x100518B0
// Name: public: void CSosOperatorStackCollection::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorStackCollection::Clear(CSosOperatorStackCollection *this)
{
  CSosOperatorStack *elem; // edi
  CSosOperator **m_pMemory; // eax
  CUtlRBTree<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int,CUtlMap<char const *,CSosOperatorStack *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int>,int> > *p_m_Tree; // edi
  int j; // esi
  CSosOperatorStackCollection *v5; // eax
  CSosOperatorStack *v6; // ebx
  int k; // edi
  CSosOperator **v8; // eax
  CUtlRBTree<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int,CUtlMap<char const *,CSosOperatorStack *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int>,int> > *v9; // edi
  int m; // esi
  CSosOperatorStackCollection *v11; // eax
  CSosOperatorStack *v12; // ebx
  int n; // edi
  CSosOperator **v14; // eax
  CUtlRBTree<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int,CUtlMap<char const *,CSosOperatorStack *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int>,int> > *v15; // edi
  int ii; // esi
  CSosOperatorStackCollection *v17; // eax
  CSosOperatorStack *v18; // ebx
  int jj; // edi
  CSosOperator **v20; // eax
  CUtlRBTree<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int,CUtlMap<char const *,CSosOperatorStack *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int>,int> > *v21; // ebx
  CUtlRBTree<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int,CUtlMap<char const *,CSosOperatorStack *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int>,int> > *v22; // edi
  int Inorder; // esi
  int kk; // esi
  unsigned int v25; // [esp+Ch] [ebp-10h]
  unsigned int v26; // [esp+Ch] [ebp-10h]
  unsigned int v27; // [esp+Ch] [ebp-10h]
  unsigned int i; // [esp+10h] [ebp-Ch]
  unsigned int ia; // [esp+10h] [ebp-Ch]
  unsigned int ib; // [esp+10h] [ebp-Ch]
  unsigned int ic; // [esp+10h] [ebp-Ch]
  int v32; // [esp+14h] [ebp-8h]
  CSosOperatorStackCollection *v33; // [esp+18h] [ebp-4h]

  v33 = this;
  i = 0;
  if ( this->m_vUpdateStacks.m_Elements.m_Tree.m_NumElements != 0 )
  {
    v32 = 0;
    do
    {
      elem = this->m_vUpdateStacks.m_Elements.m_Tree.m_Elements.m_pMemory[v32].m_Data.elem;
      if ( elem != nullptr )
      {
        if ( elem->m_pMemPool != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: elem->m_pMemPool);
        CUtlDict<int,int>::RemoveAll(this: &elem->m_vOperatorMap);
        CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RemoveAll(this: &elem->m_vOperatorMap.m_Elements.m_Tree);
        elem->m_vOperatorMap.m_Elements.m_Tree.m_FirstFree = -1;
        if ( elem->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_nGrowSize >= 0 )
        {
          if ( elem->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: elem->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_pMemory);
            elem->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
          }
          elem->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
        }
        elem->m_vOperatorMap.m_Elements.m_Tree.m_LastAlloc.index = -1;
        if ( elem->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_nGrowSize >= 0 )
        {
          if ( elem->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: elem->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_pMemory);
            elem->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
          }
          elem->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
        }
        elem->m_vStack.m_Size = 0;
        if ( elem->m_vStack.m_Memory.m_nGrowSize >= 0 )
        {
          if ( elem->m_vStack.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: elem->m_vStack.m_Memory.m_pMemory);
            elem->m_vStack.m_Memory.m_pMemory = nullptr;
          }
          elem->m_vStack.m_Memory.m_nAllocationCount = 0;
        }
        m_pMemory = elem->m_vStack.m_Memory.m_pMemory;
        elem->m_vStack.m_pElements = m_pMemory;
        if ( elem->m_vStack.m_Memory.m_nGrowSize >= 0 )
        {
          if ( m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
            elem->m_vStack.m_Memory.m_pMemory = nullptr;
          }
          elem->m_vStack.m_Memory.m_nAllocationCount = 0;
        }
        free(pMem: elem);
        this = v33;
      }
      ++v32;
      ++i;
    }
    while ( i < this->m_vUpdateStacks.m_Elements.m_Tree.m_NumElements );
  }
  p_m_Tree = &v33->m_vUpdateStacks.m_Elements.m_Tree;
  for ( j = CUtlRBTree<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int,CUtlMap<char const *,CSosOperatorStack *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int>,int>>::FirstInorder(this: &v33->m_vUpdateStacks.m_Elements.m_Tree);
        j != -1;
        j = CUtlRBTree<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int,CUtlMap<char const *,CSosOperatorStack *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int>,int>>::NextInorder(
              this: p_m_Tree,
              i: j) )
  {
    _g_pMemAlloc->Free_2(
      this: _g_pMemAlloc,
      a2: (void *)v33->m_vUpdateStacks.m_Elements.m_Tree.m_Elements.m_pMemory[j].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int,CUtlMap<char const *,CSosOperatorStack *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int>,int>>::RemoveAll(this: p_m_Tree);
  v5 = v33;
  v25 = 0;
  if ( v33->m_vStartStacks.m_Elements.m_Tree.m_NumElements != 0 )
  {
    ia = 0;
    do
    {
      v6 = v5->m_vStartStacks.m_Elements.m_Tree.m_Elements.m_pMemory[ia].m_Data.elem;
      if ( v6 != nullptr )
      {
        if ( v6->m_pMemPool != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6->m_pMemPool);
        for ( k = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::FirstInorder(this: &v6->m_vOperatorMap.m_Elements.m_Tree);
              k != -1;
              k = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::NextInorder(
                    this: &v6->m_vOperatorMap.m_Elements.m_Tree,
                    i: k) )
        {
          _g_pMemAlloc->Free_2(
            this: _g_pMemAlloc,
            a2: (void *)v6->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_pMemory[k].m_Data.key);
        }
        CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RemoveAll(this: &v6->m_vOperatorMap.m_Elements.m_Tree);
        CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RemoveAll(this: &v6->m_vOperatorMap.m_Elements.m_Tree);
        v6->m_vOperatorMap.m_Elements.m_Tree.m_FirstFree = -1;
        if ( v6->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_nGrowSize >= 0 )
        {
          if ( v6->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_pMemory);
            v6->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
          }
          v6->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
        }
        v6->m_vOperatorMap.m_Elements.m_Tree.m_LastAlloc.index = -1;
        if ( v6->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_nGrowSize >= 0 )
        {
          if ( v6->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_pMemory);
            v6->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
          }
          v6->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
        }
        v6->m_vStack.m_Size = 0;
        if ( v6->m_vStack.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v6->m_vStack.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6->m_vStack.m_Memory.m_pMemory);
            v6->m_vStack.m_Memory.m_pMemory = nullptr;
          }
          v6->m_vStack.m_Memory.m_nAllocationCount = 0;
        }
        v8 = v6->m_vStack.m_Memory.m_pMemory;
        v6->m_vStack.m_pElements = v8;
        if ( v6->m_vStack.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v8 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v8);
            v6->m_vStack.m_Memory.m_pMemory = nullptr;
          }
          v6->m_vStack.m_Memory.m_nAllocationCount = 0;
        }
        free(pMem: v6);
        v5 = v33;
      }
      ++ia;
      ++v25;
    }
    while ( v25 < v5->m_vStartStacks.m_Elements.m_Tree.m_NumElements );
  }
  v9 = &v33->m_vStartStacks.m_Elements.m_Tree;
  for ( m = CUtlRBTree<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int,CUtlMap<char const *,CSosOperatorStack *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int>,int>>::FirstInorder(this: &v33->m_vStartStacks.m_Elements.m_Tree);
        m != -1;
        m = CUtlRBTree<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int,CUtlMap<char const *,CSosOperatorStack *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int>,int>>::NextInorder(
              this: v9,
              i: m) )
  {
    _g_pMemAlloc->Free_2(
      this: _g_pMemAlloc,
      a2: (void *)v33->m_vStartStacks.m_Elements.m_Tree.m_Elements.m_pMemory[m].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int,CUtlMap<char const *,CSosOperatorStack *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int>,int>>::RemoveAll(this: v9);
  v11 = v33;
  v26 = 0;
  if ( v33->m_vStopStacks.m_Elements.m_Tree.m_NumElements != 0 )
  {
    ib = 0;
    do
    {
      v12 = v11->m_vStopStacks.m_Elements.m_Tree.m_Elements.m_pMemory[ib].m_Data.elem;
      if ( v12 != nullptr )
      {
        if ( v12->m_pMemPool != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v12->m_pMemPool);
        for ( n = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::FirstInorder(this: &v12->m_vOperatorMap.m_Elements.m_Tree);
              n != -1;
              n = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::NextInorder(
                    this: &v12->m_vOperatorMap.m_Elements.m_Tree,
                    i: n) )
        {
          _g_pMemAlloc->Free_2(
            this: _g_pMemAlloc,
            a2: (void *)v12->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_pMemory[n].m_Data.key);
        }
        CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RemoveAll(this: &v12->m_vOperatorMap.m_Elements.m_Tree);
        CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RemoveAll(this: &v12->m_vOperatorMap.m_Elements.m_Tree);
        v12->m_vOperatorMap.m_Elements.m_Tree.m_FirstFree = -1;
        if ( v12->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_nGrowSize >= 0 )
        {
          if ( v12->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v12->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_pMemory);
            v12->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
          }
          v12->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
        }
        v12->m_vOperatorMap.m_Elements.m_Tree.m_LastAlloc.index = -1;
        if ( v12->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_nGrowSize >= 0 )
        {
          if ( v12->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v12->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_pMemory);
            v12->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
          }
          v12->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
        }
        v12->m_vStack.m_Size = 0;
        if ( v12->m_vStack.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v12->m_vStack.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v12->m_vStack.m_Memory.m_pMemory);
            v12->m_vStack.m_Memory.m_pMemory = nullptr;
          }
          v12->m_vStack.m_Memory.m_nAllocationCount = 0;
        }
        v14 = v12->m_vStack.m_Memory.m_pMemory;
        v12->m_vStack.m_pElements = v14;
        if ( v12->m_vStack.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v14 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v14);
            v12->m_vStack.m_Memory.m_pMemory = nullptr;
          }
          v12->m_vStack.m_Memory.m_nAllocationCount = 0;
        }
        free(pMem: v12);
        v11 = v33;
      }
      ++ib;
      ++v26;
    }
    while ( v26 < v11->m_vStopStacks.m_Elements.m_Tree.m_NumElements );
  }
  v15 = &v33->m_vStopStacks.m_Elements.m_Tree;
  for ( ii = CUtlRBTree<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int,CUtlMap<char const *,CSosOperatorStack *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int>,int>>::FirstInorder(this: &v33->m_vStopStacks.m_Elements.m_Tree);
        ii != -1;
        ii = CUtlRBTree<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int,CUtlMap<char const *,CSosOperatorStack *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int>,int>>::NextInorder(
               this: v15,
               i: ii) )
  {
    _g_pMemAlloc->Free_2(
      this: _g_pMemAlloc,
      a2: (void *)v33->m_vStopStacks.m_Elements.m_Tree.m_Elements.m_pMemory[ii].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int,CUtlMap<char const *,CSosOperatorStack *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int>,int>>::RemoveAll(this: v15);
  v17 = v33;
  v27 = 0;
  if ( v33->m_vCueStacks.m_Elements.m_Tree.m_NumElements != 0 )
  {
    ic = 0;
    do
    {
      v18 = v17->m_vCueStacks.m_Elements.m_Tree.m_Elements.m_pMemory[ic].m_Data.elem;
      if ( v18 != nullptr )
      {
        if ( v18->m_pMemPool != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v18->m_pMemPool);
        for ( jj = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::FirstInorder(this: &v18->m_vOperatorMap.m_Elements.m_Tree);
              jj != -1;
              jj = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::NextInorder(
                     this: &v18->m_vOperatorMap.m_Elements.m_Tree,
                     i: jj) )
        {
          _g_pMemAlloc->Free_2(
            this: _g_pMemAlloc,
            a2: (void *)v18->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_pMemory[jj].m_Data.key);
        }
        CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RemoveAll(this: &v18->m_vOperatorMap.m_Elements.m_Tree);
        CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RemoveAll(this: &v18->m_vOperatorMap.m_Elements.m_Tree);
        v18->m_vOperatorMap.m_Elements.m_Tree.m_FirstFree = -1;
        if ( v18->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_nGrowSize >= 0 )
        {
          if ( v18->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v18->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_pMemory);
            v18->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
          }
          v18->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
        }
        v18->m_vOperatorMap.m_Elements.m_Tree.m_LastAlloc.index = -1;
        if ( v18->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_nGrowSize >= 0 )
        {
          if ( v18->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v18->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_pMemory);
            v18->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
          }
          v18->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
        }
        v18->m_vStack.m_Size = 0;
        if ( v18->m_vStack.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v18->m_vStack.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v18->m_vStack.m_Memory.m_pMemory);
            v18->m_vStack.m_Memory.m_pMemory = nullptr;
          }
          v18->m_vStack.m_Memory.m_nAllocationCount = 0;
        }
        v20 = v18->m_vStack.m_Memory.m_pMemory;
        v18->m_vStack.m_pElements = v20;
        if ( v18->m_vStack.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v20 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v20);
            v18->m_vStack.m_Memory.m_pMemory = nullptr;
          }
          v18->m_vStack.m_Memory.m_nAllocationCount = 0;
        }
        free(pMem: v18);
        v17 = v33;
      }
      ++ic;
      ++v27;
    }
    while ( v27 < v17->m_vCueStacks.m_Elements.m_Tree.m_NumElements );
  }
  v21 = &v33->m_vAllStacks.m_Elements.m_Tree;
  v22 = &v33->m_vCueStacks.m_Elements.m_Tree;
  Inorder = CUtlRBTree<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int,CUtlMap<char const *,CSosOperatorStack *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int>,int>>::FirstInorder(this: &v33->m_vCueStacks.m_Elements.m_Tree);
  if ( Inorder != -1 )
  {
    do
    {
      _g_pMemAlloc->Free_2(
        this: _g_pMemAlloc,
        a2: (void *)v33->m_vCueStacks.m_Elements.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.key);
      Inorder = CUtlRBTree<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int,CUtlMap<char const *,CSosOperatorStack *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int>,int>>::NextInorder(
                  this: v22,
                  i: Inorder);
    }
    while ( Inorder != -1 );
    v21 = &v33->m_vAllStacks.m_Elements.m_Tree;
  }
  CUtlRBTree<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int,CUtlMap<char const *,CSosOperatorStack *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int>,int>>::RemoveAll(this: v22);
  for ( kk = CUtlRBTree<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int,CUtlMap<char const *,CSosOperatorStack *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int>,int>>::FirstInorder(this: v21);
        kk != -1;
        kk = CUtlRBTree<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int,CUtlMap<char const *,CSosOperatorStack *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int>,int>>::NextInorder(
               this: v21,
               i: kk) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)v21->m_Elements.m_pMemory[kk].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int,CUtlMap<char const *,CSosOperatorStack *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int>,int>>::RemoveAll(this: v21);
}

//------------------------------------------------------------------------------
// Address: 0x10051FB0
// Name: public: void CSosOperatorStack::AddToTail(class CSosOperator __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorStack::AddToTail(CSosOperatorStack *this, CSosOperator *pOperator, const char *pName)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CSosOperator **m_pMemory; // ecx
  int v7; // eax
  CSosOperator **v8; // eax

  m_nAllocationCount = this->m_vStack.m_Memory.m_nAllocationCount;
  m_Size = this->m_vStack.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<INetMessage *,int>::Grow(
      this: (CUtlMemory<S3RGBA,int> *)&this->m_vStack,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_vStack.m_Size;
  m_pMemory = this->m_vStack.m_Memory.m_pMemory;
  v7 = this->m_vStack.m_Size - m_Size - 1;
  this->m_vStack.m_pElements = m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
  v8 = &this->m_vStack.m_Memory.m_pMemory[m_Size];
  if ( v8 != nullptr )
    *v8 = pOperator;
  pOperator = (CSosOperator *)m_Size;
  CUtlDict<int,int>::Insert(this: &this->m_vOperatorMap, pName, element: (const int *)&pOperator);
}

//------------------------------------------------------------------------------
// Address: 0x10052030
// Name: public: void CSosOperatorStack::Copy(class CSosOperatorStack __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorStack::Copy(CSosOperatorStack *this, CSosOperatorStack *pSrcStack, unsigned int nMemOffset)
{
  CSosOperatorStack *v3; // esi
  CSosOperatorStack *v4; // ebx
  char *m_pMemPool; // edx
  void *v6; // ecx
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> > *p_m_Tree; // edi
  CSosOperator *v8; // edx
  const char *key; // esi
  int v10; // eax
  int m_nAllocationCount; // eax
  CUtlMemory<S3RGBA,int> *p_m_vStack; // esi
  int m_Size; // ebx
  S3RGBA *m_pMemory; // ecx
  int v15; // eax
  CSosOperator **v16; // eax
  const char *v17; // esi
  const char *v18; // eax
  const char *v19; // ecx
  int v20; // esi
  char v21; // dl
  int v22; // eax
  const char *v23; // edx
  int v24; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v25; // ecx
  int v26; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v27; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v28; // eax
  CUtlMap<char const *,int,int>::Node_t *p_m_Data; // esi
  unsigned int v30; // ebx
  CSosOperator *v31; // esi
  int v32; // eax
  unsigned int m_nMemSize; // [esp-4h] [ebp-38h]
  CUtlMap<char const *,int,int>::Node_t search; // [esp+8h] [ebp-2Ch] BYREF
  CUtlMap<char const *,int,int>::Node_t insert; // [esp+10h] [ebp-24h] BYREF
  unsigned int nTotalOffset; // [esp+18h] [ebp-1Ch]
  CSosOperator *pOperator; // [esp+1Ch] [ebp-18h]
  CSosOperatorStack *v38; // [esp+20h] [ebp-14h]
  const char *pName; // [esp+24h] [ebp-10h] BYREF
  unsigned int v40; // [esp+28h] [ebp-Ch]
  int i; // [esp+2Ch] [ebp-8h]
  bool leftchild; // [esp+33h] [ebp-1h] BYREF

  v3 = pSrcStack;
  v4 = this;
  m_pMemPool = (char *)this->m_pMemPool;
  v6 = pSrcStack->m_pMemPool;
  m_nMemSize = pSrcStack->m_nMemSize;
  v38 = v4;
  _V_memcpy(dest: &m_pMemPool[nMemOffset], src: v6, count: m_nMemSize);
  nTotalOffset = 0;
  i = 0;
  if ( pSrcStack->m_vStack.m_Size > 0 )
  {
    p_m_Tree = &v4->m_vOperatorMap.m_Elements.m_Tree;
    v40 = 0;
    while ( 1 )
    {
      v8 = v3->m_vStack.m_Memory.m_pMemory[i];
      key = v3->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_pMemory[v40 / 0x18].m_Data.key;
      pOperator = v8;
      pName = key;
      if ( key != nullptr )
      {
        search.key = key;
        v10 = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Find(
                this: p_m_Tree,
                &search);
        if ( v10 >= 0 && v10 < p_m_Tree->m_Elements.m_nAllocationCount && v10 <= p_m_Tree->m_LastAlloc.index )
        {
          if ( (`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_104433A8 = -1;
            dword_104433AC = -1;
            dword_104433B0 = 1;
          }
          if ( p_m_Tree->m_Elements.m_pMemory[v10].m_Left != v10
            && (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
          {
            _LoggingSystem_Log(
              a1: LOG_SND_OPERATORS,
              a2: 1,
              a3: "Error: Importing operator with same name as existing operator: %s\n",
              key);
          }
        }
      }
      m_nAllocationCount = v4->m_vStack.m_Memory.m_nAllocationCount;
      p_m_vStack = (CUtlMemory<S3RGBA,int> *)&v4->m_vStack;
      m_Size = v4->m_vStack.m_Size;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<INetMessage *,int>::Grow(this: p_m_vStack, num: m_Size - m_nAllocationCount + 1);
      ++p_m_vStack[1].m_pMemory;
      m_pMemory = p_m_vStack->m_pMemory;
      v15 = (int)p_m_vStack[1].m_pMemory - m_Size - 1;
      p_m_vStack[1].m_nAllocationCount = (int)p_m_vStack->m_pMemory;
      if ( v15 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v15);
      v16 = (CSosOperator **)&p_m_vStack->m_pMemory[m_Size];
      if ( v16 != nullptr )
        *v16 = pOperator;
      v17 = pName;
      if ( pName != nullptr
        && (v18 = (const char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
      {
        v19 = v17;
        v20 = v18 - pName;
        do
        {
          v21 = *v19;
          v19[v20] = *v19;
          ++v19;
        }
        while ( v21 != 0 );
      }
      else
      {
        v18 = nullptr;
      }
      insert.key = v18;
      insert.elem = m_Size;
      pName = (const char *)-1;
      leftchild = false;
      CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::FindInsertionPosition(
        this: p_m_Tree,
        &insert,
        parent: (int *)&pName,
        &leftchild);
      v22 = CUtlRBTree<CDmxSerializationDictionary::DmxElementInfo_t,int,bool (__cdecl *)(CDmxSerializationDictionary::DmxElementInfo_t const &,CDmxSerializationDictionary::DmxElementInfo_t const &),CUtlMemory<UtlRBTreeNode_t<CDmxSerializationDictionary::DmxElementInfo_t,int>,int>>::NewNode(this: (CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *)p_m_Tree);
      v23 = pName;
      v24 = v22;
      v25 = &p_m_Tree->m_Elements.m_pMemory[v22];
      v25->m_Parent = (int)pName;
      v25->m_Right = -1;
      v25->m_Left = -1;
      v25->m_Tag = 0;
      if ( v23 == (const char *)-1 )
      {
        p_m_Tree->m_Root = v22;
      }
      else
      {
        v26 = (int)v23;
        v27 = p_m_Tree->m_Elements.m_pMemory;
        if ( leftchild )
          v27[v26].m_Left = v22;
        else
          v27[v26].m_Right = v22;
      }
      CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::InsertRebalance(
        this: p_m_Tree,
        elem: v22);
      v28 = p_m_Tree->m_Elements.m_pMemory;
      ++p_m_Tree->m_NumElements;
      p_m_Data = &v28[v24].m_Data;
      if ( p_m_Data != nullptr )
        *p_m_Data = insert;
      v30 = nTotalOffset;
      v31 = pOperator;
      CSosOperator::OffsetConnections(
        this: pOperator,
        pVoidMem: (char *)v38->m_pMemPool + nTotalOffset + nMemOffset,
        nOffset: nMemOffset);
      v32 = v31->GetSize(this: v31);
      v40 += 24;
      nTotalOffset = v32 + v30;
      if ( ++i >= pSrcStack->m_vStack.m_Size )
        break;
      v4 = v38;
      v3 = pSrcStack;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100522B0
// Name: public: CSosOperatorStackList::~CSosOperatorStackList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorStackList::~CSosOperatorStackList(CSosOperatorStackList *this)
{
  CSosOperatorStack *m_vCueStack; // ecx
  CSosOperatorStack *v3; // edi
  CSosOperatorStack *m_vUpdateStack; // edi
  CSosOperatorStack *m_vStopStack; // ecx
  CSosOperatorStack *v6; // esi

  m_vCueStack = this->m_vCueStack;
  if ( m_vCueStack != nullptr )
  {
    CSosOperatorStack::Shutdown(this: m_vCueStack);
    v3 = this->m_vCueStack;
    if ( v3 != nullptr )
    {
      if ( v3->m_pMemPool != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_pMemPool);
      CUtlDict<int,int>::RemoveAll(this: &v3->m_vOperatorMap);
      CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>(this: &v3->m_vOperatorMap.m_Elements.m_Tree);
      CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v3->m_vStack);
      free(pMem: v3);
    }
  }
  if ( this->m_vUpdateStack != nullptr )
  {
    CSosOperatorStack::Shutdown(this: this->m_vUpdateStack);
    m_vUpdateStack = this->m_vUpdateStack;
    if ( this->m_vUpdateStack != nullptr )
    {
      if ( m_vUpdateStack->m_pMemPool != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_vUpdateStack->m_pMemPool);
      CUtlDict<int,int>::RemoveAll(this: &m_vUpdateStack->m_vOperatorMap);
      CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>(this: &m_vUpdateStack->m_vOperatorMap.m_Elements.m_Tree);
      CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&m_vUpdateStack->m_vStack);
      free(pMem: m_vUpdateStack);
    }
  }
  m_vStopStack = this->m_vStopStack;
  if ( m_vStopStack != nullptr )
  {
    CSosOperatorStack::Shutdown(this: m_vStopStack);
    v6 = this->m_vStopStack;
    if ( v6 != nullptr )
    {
      if ( v6->m_pMemPool != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6->m_pMemPool);
      CUtlDict<int,int>::RemoveAll(this: &v6->m_vOperatorMap);
      CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>(this: &v6->m_vOperatorMap.m_Elements.m_Tree);
      CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v6->m_vStack);
      free(pMem: v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100523A0
// Name: public: CSosOperatorStackCollection::~CSosOperatorStackCollection(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorStackCollection::~CSosOperatorStackCollection(CSosOperatorStackCollection *this)
{
  CSosOperatorStackCollection::Clear(this);
  CUtlDict<CSosOperatorStack *,int>::RemoveAll(this: &this->m_vCueStacks);
  CUtlRBTree<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int,CUtlMap<char const *,CSosOperatorStack *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int,CUtlMap<char const *,CSosOperatorStack *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int>,int>>(this: &this->m_vCueStacks.m_Elements.m_Tree);
  CUtlDict<CSosOperatorStack *,int>::RemoveAll(this: &this->m_vStopStacks);
  CUtlRBTree<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int,CUtlMap<char const *,CSosOperatorStack *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int,CUtlMap<char const *,CSosOperatorStack *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int>,int>>(this: &this->m_vStopStacks.m_Elements.m_Tree);
  CUtlDict<CSosOperatorStack *,int>::RemoveAll(this: &this->m_vStartStacks);
  CUtlRBTree<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int,CUtlMap<char const *,CSosOperatorStack *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int,CUtlMap<char const *,CSosOperatorStack *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int>,int>>(this: &this->m_vStartStacks.m_Elements.m_Tree);
  CUtlDict<CSosOperatorStack *,int>::RemoveAll(this: &this->m_vUpdateStacks);
  CUtlRBTree<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int,CUtlMap<char const *,CSosOperatorStack *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int,CUtlMap<char const *,CSosOperatorStack *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int>,int>>(this: &this->m_vUpdateStacks.m_Elements.m_Tree);
  CUtlDict<CSosOperatorStack *,int>::RemoveAll(this: &this->m_vAllStacks);
  CUtlRBTree<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int,CUtlMap<char const *,CSosOperatorStack *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int,CUtlMap<char const *,CSosOperatorStack *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int>,int>>(this: &this->m_vAllStacks.m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x10052400
// Name: public: CSosOperatorSystem::CSosOperatorSystem(void)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorSystem *__thiscall CSosOperatorSystem::CSosOperatorSystem(CSosOperatorSystem *this)
{
  CSosOperatorStackCollection::CSosOperatorStackCollection(this: &this->m_MasterStackCollection);
  this->m_vOperatorCollection.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_vOperatorCollection.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_vOperatorCollection.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_vOperatorCollection.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_vOperatorCollection.m_Elements.m_Tree.m_Root = -1;
  this->m_vOperatorCollection.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_vOperatorCollection.m_Elements.m_Tree.m_NumElements = 0;
  this->m_vOperatorCollection.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_vOperatorCollection.m_Elements.m_Tree.m_pElements = this->m_vOperatorCollection.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( this->m_vOperatorCollection.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_vOperatorCollection.m_Elements.m_Tree.m_LessFunc.m_LessFunc = CaselessStringLessThan;
  CSosEntryMatchList::CSosEntryMatchList(this: &this->m_sosEntryBlockList);
  CTSQueue<StartSoundParams_t,0,1>::CTSQueue<StartSoundParams_t,0,1>(this: &this->m_sosStartEntryQueue);
  CTSQueue<int,0,1>::CTSQueue<int,0,1>(this: &this->m_sosStopChannelQueue);
  this->m_bHasInitialized = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10052490
// Name: public: CSosOperatorSystem::~CSosOperatorSystem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorSystem::~CSosOperatorSystem(CSosOperatorSystem *this)
{
  void **m_vEntryMatchList; // esi
  int i; // ebx

  CTSQueue<int,0,1>::Purge(this: &this->m_sosStopChannelQueue);
  free(pMem: this->m_sosStopChannelQueue.m_Head.value.pNode);
  CTSListBase::Detach(this: &this->m_sosStopChannelQueue.m_FreeNodes);
  CTSQueue<StartSoundParams_t,0,1>::Purge(this: &this->m_sosStartEntryQueue);
  free(pMem: this->m_sosStartEntryQueue.m_Head.value.pNode);
  CTSListBase::Detach(this: &this->m_sosStartEntryQueue.m_FreeNodes);
  m_vEntryMatchList = (void **)this->m_sosEntryBlockList.m_vEntryMatchList;
  for ( i = 32; i != 0; --i )
  {
    free(pMem: *m_vEntryMatchList);
    *m_vEntryMatchList++ = nullptr;
  }
  CUtlDict<CSosOperator *,int>::RemoveAll(this: &this->m_vOperatorCollection);
  CUtlRBTree<CUtlMap<char const *,CSosOperator *,int>::Node_t,int,CUtlMap<char const *,CSosOperator *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperator *,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CSosOperator *,int>::Node_t,int,CUtlMap<char const *,CSosOperator *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperator *,int>::Node_t,int>,int>>(this: &this->m_vOperatorCollection.m_Elements.m_Tree);
  CSosOperatorStackCollection::~CSosOperatorStackCollection(this: &this->m_MasterStackCollection);
}

//------------------------------------------------------------------------------
// Address: 0x10052530
// Name: public: static class CSosOperatorSystem __near * CSosOperatorSystem::GetSoundOperatorSystem(void)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorSystem *__cdecl CSosOperatorSystem::GetSoundOperatorSystem()
{
  if ( (_S1_2 & 1) == 0 )
  {
    _S1_2 |= 1u;
    CSosOperatorSystem::CSosOperatorSystem(this: &s_SoundOperatorSystem);
    atexit(func: CSosOperatorSystem::GetSoundOperatorSystem_::_2_::_dynamic_atexit_destructor_for__s_SoundOperatorSystem__);
  }
  return &s_SoundOperatorSystem;
}

//------------------------------------------------------------------------------
// Address: 0x10052560
// Name: public: void CSosOperatorStack::ParseKV(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorStack::ParseKV(CSosOperatorStack *this, KeyValues *pOperatorsKV)
{
  KeyValues *FirstSubKey; // edi
  const char *Name; // ebx
  const char *String; // esi
  int v5; // eax
  CUtlDict<int,int> *p_m_vOperatorMap; // edi
  int v7; // esi
  int v8; // eax
  int v9; // eax
  CSosOperatorStack *v10; // esi
  CSosOperator *Operator; // eax
  int v12; // esi
  CSosOperator *v13; // esi
  const char *v14; // eax
  int v15; // eax
  CSosOperatorStack *v16; // edi
  unsigned int v17; // ebx
  KeyValues *v18; // ebx
  const char *v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // esi
  CSosOperatorStack *elem; // esi
  int v24; // ebx
  unsigned int v25; // esi
  void *v26; // eax
  CSosOperatorStack *v27; // ecx
  int Inorder; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,CSosOperator *,int>::Node_t,int> *m_pMemory; // edi
  CUtlDict<CSosOperator *,int> testDict; // [esp+8h] [ebp-64h] BYREF
  CUtlMap<char const *,CSosOperatorStack *,int>::Node_t v31; // [esp+2Ch] [ebp-40h] BYREF
  CUtlMap<char const *,CSosOperator *,int>::Node_t v32; // [esp+34h] [ebp-38h] BYREF
  CUtlMap<char const *,int,int>::Node_t v33; // [esp+3Ch] [ebp-30h] BYREF
  CUtlMap<char const *,int,int>::Node_t v34; // [esp+44h] [ebp-28h] BYREF
  CUtlMap<char const *,CSosOperator *,int>::Node_t search; // [esp+4Ch] [ebp-20h] BYREF
  void *pStructMem; // [esp+54h] [ebp-18h] BYREF
  const char *pOpType; // [esp+58h] [ebp-14h] BYREF
  int i; // [esp+5Ch] [ebp-10h]
  KeyValues *pOperator; // [esp+60h] [ebp-Ch]
  CSosOperatorStack *v40; // [esp+64h] [ebp-8h]
  unsigned int TotalSize; // [esp+68h] [ebp-4h]

  v40 = this;
  TotalSize = 0;
  FirstSubKey = KeyValues::GetFirstSubKey(this: pOperatorsKV);
  pOperator = FirstSubKey;
  memset(&testDict.m_Elements.m_Tree.m_Elements, 0, sizeof(testDict.m_Elements.m_Tree.m_Elements));
  testDict.m_Elements.m_Tree.m_Root = -1;
  testDict.m_Elements.m_Tree.m_NumElements = 0;
  testDict.m_Elements.m_Tree.m_FirstFree = -1;
  testDict.m_Elements.m_Tree.m_LastAlloc.index = -1;
  testDict.m_Elements.m_Tree.m_pElements = nullptr;
  testDict.m_Elements.m_Tree.m_LessFunc.m_LessFunc = CaselessStringLessThan;
  i = 0;
  do
  {
    while ( FirstSubKey != nullptr )
    {
      Name = KeyValues::GetName(this: FirstSubKey);
      String = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: defaultValue);
      if ( KeyValues::GetFirstSubKey(this: FirstSubKey) == nullptr )
      {
        if ( Name != nullptr
          && *Name != 0
          && _V_stricmp(s1: Name, s2: "import_stack") == 0
          && String != nullptr
          && *String != 0 )
        {
          if ( (_S1_2 & 1) == 0 )
          {
            _S1_2 |= 1u;
            CSosOperatorSystem::CSosOperatorSystem(this: &s_SoundOperatorSystem);
            atexit(func: CSosOperatorSystem::GetSoundOperatorSystem_::_2_::_dynamic_atexit_destructor_for__s_SoundOperatorSystem__);
          }
          v31.key = String;
          v21 = CUtlRBTree<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int,CUtlMap<char const *,CSosOperatorStack *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int>,int>>::Find(
                  this: &s_SoundOperatorSystem.m_MasterStackCollection.m_vAllStacks.m_Elements.m_Tree,
                  search: &v31);
          v22 = v21;
          if ( v21 >= 0
            && v21 < s_SoundOperatorSystem.m_MasterStackCollection.m_vAllStacks.m_Elements.m_Tree.m_Elements.m_nAllocationCount
            && v21 <= s_SoundOperatorSystem.m_MasterStackCollection.m_vAllStacks.m_Elements.m_Tree.m_LastAlloc.index
            && CUtlRBTree<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int,CUtlMap<char const *,CSosOperatorStack *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int>,int>>::LeftChild(
                 this: &s_SoundOperatorSystem.m_MasterStackCollection.m_vAllStacks.m_Elements.m_Tree,
                 i: v21) != v21 )
          {
            elem = s_SoundOperatorSystem.m_MasterStackCollection.m_vAllStacks.m_Elements.m_Tree.m_Elements.m_pMemory[v22].m_Data.elem;
            if ( elem != nullptr )
            {
              if ( i == 1 )
                CSosOperatorStack::Copy(this: v40, pSrcStack: elem, nMemOffset: TotalSize);
              TotalSize += elem->m_nMemSize;
            }
          }
        }
        goto LABEL_69;
      }
      pOpType = KeyValues::GetString(this: FirstSubKey, keyName: "operator", defaultValue: "math_float");
      if ( Name != nullptr )
      {
        search.key = Name;
        v5 = CUtlRBTree<CUtlMap<char const *,CSosOperator *,int>::Node_t,int,CUtlMap<char const *,CSosOperator *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperator *,int>::Node_t,int>,int>>::Find(
               this: &testDict.m_Elements.m_Tree,
               &search);
        p_m_vOperatorMap = &v40->m_vOperatorMap;
        v7 = v5;
        v34.key = Name;
        v8 = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Find(
               this: &v40->m_vOperatorMap.m_Elements.m_Tree,
               search: &v34);
        if ( v7 >= 0
          && v7 < testDict.m_Elements.m_Tree.m_Elements.m_nAllocationCount
          && v7 <= testDict.m_Elements.m_Tree.m_LastAlloc.index )
        {
          if ( (`CUtlRBTree<CUtlMap<char const *,CSosOperator *,int>::Node_t,int,CUtlMap<char const *,CSosOperator *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperator *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,CSosOperator *,int>::Node_t,int,CUtlMap<char const *,CSosOperator *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperator *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<char const *,CSosOperator *,int>::Node_t,int,CUtlMap<char const *,CSosOperator *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperator *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_104BF878 = -1;
            dword_104BF87C = -1;
            dword_104BF880 = 1;
          }
          if ( testDict.m_Elements.m_Tree.m_Elements.m_pMemory[v7].m_Left != v7 && i == 0 )
            goto LABEL_21;
        }
      }
      else
      {
        v8 = -1;
      }
      p_m_vOperatorMap = &v40->m_vOperatorMap;
      if ( v8 < 0
        || v8 >= v40->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_nAllocationCount
        || v8 > v40->m_vOperatorMap.m_Elements.m_Tree.m_LastAlloc.index )
      {
        goto LABEL_33;
      }
      if ( (`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_104433A8 = -1;
        dword_104433AC = -1;
        dword_104433B0 = 1;
      }
      if ( v40->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_pMemory[v8].m_Left == v8 )
      {
LABEL_33:
        if ( pOpType != nullptr && *pOpType != 0 )
        {
          if ( (_S1_2 & 1) == 0 )
          {
            _S1_2 |= 1u;
            CSosOperatorSystem::CSosOperatorSystem(this: &s_SoundOperatorSystem);
            atexit(func: CSosOperatorSystem::GetSoundOperatorSystem_::_2_::_dynamic_atexit_destructor_for__s_SoundOperatorSystem__);
          }
          v32.key = pOpType;
          v12 = CUtlRBTree<CUtlMap<char const *,CSosOperator *,int>::Node_t,int,CUtlMap<char const *,CSosOperator *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperator *,int>::Node_t,int>,int>>::Find(
                  this: &s_SoundOperatorSystem.m_vOperatorCollection.m_Elements.m_Tree,
                  search: &v32);
          if ( (_S1_2 & 1) == 0 )
          {
            _S1_2 |= 1u;
            CSosOperatorSystem::CSosOperatorSystem(this: &s_SoundOperatorSystem);
            atexit(func: CSosOperatorSystem::GetSoundOperatorSystem_::_2_::_dynamic_atexit_destructor_for__s_SoundOperatorSystem__);
          }
          if ( v12 < 0
            || v12 >= s_SoundOperatorSystem.m_vOperatorCollection.m_Elements.m_Tree.m_Elements.m_nAllocationCount
            || v12 > s_SoundOperatorSystem.m_vOperatorCollection.m_Elements.m_Tree.m_LastAlloc.index )
          {
            goto LABEL_49;
          }
          if ( (`CUtlRBTree<CUtlMap<char const *,CSosOperator *,int>::Node_t,int,CUtlMap<char const *,CSosOperator *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperator *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,CSosOperator *,int>::Node_t,int,CUtlMap<char const *,CSosOperator *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperator *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<char const *,CSosOperator *,int>::Node_t,int,CUtlMap<char const *,CSosOperator *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperator *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_104BF878 = -1;
            dword_104BF87C = -1;
            dword_104BF880 = 1;
          }
          if ( s_SoundOperatorSystem.m_vOperatorCollection.m_Elements.m_Tree.m_Elements.m_pMemory[v12].m_Left == v12 )
          {
LABEL_49:
            if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
              _LoggingSystem_Log(
                a1: LOG_SND_OPERATORS,
                a2: 1,
                a3: "Error: Operator: %s : Unknown sound operator type %s\n",
                Name,
                pOpType);
          }
          else
          {
            if ( (_S1_2 & 1) == 0 )
            {
              _S1_2 |= 1u;
              CSosOperatorSystem::CSosOperatorSystem(this: &s_SoundOperatorSystem);
              atexit(func: CSosOperatorSystem::GetSoundOperatorSystem_::_2_::_dynamic_atexit_destructor_for__s_SoundOperatorSystem__);
            }
            v13 = s_SoundOperatorSystem.m_vOperatorCollection.m_Elements.m_Tree.m_Elements.m_pMemory[v12].m_Data.elem;
            pOpType = (const char *)v13;
            if ( v13 != nullptr )
            {
              if ( i != 0 )
              {
                if ( i == 1 )
                {
                  v16 = v40;
                  v17 = TotalSize;
                  CSosOperator::SetBaseDefaults(this: v13, pVoidMem: (char *)v40->m_pMemPool + TotalSize);
                  v13->SetDefaults(this: v13, a2: (char *)v16->m_pMemPool + v17);
                  v18 = pOperator;
                  v13->ParseKV(this: v13, a2: v16, a3: (char *)v16->m_pMemPool + TotalSize, a4: pOperator);
                  v19 = KeyValues::GetName(this: v18);
                  CSosOperatorStack::AddToTail(this: v16, pOperator: v13, pName: v19);
                }
                v20 = v13->GetSize(this: v13);
                TotalSize += v20;
              }
              else
              {
                v14 = KeyValues::GetName(this: pOperator);
                CUtlDict<CSosOperator *,int>::Insert(
                  this: &testDict,
                  pName: v14,
                  element: (CSosOperator *const *)&pOpType);
                v15 = v13->GetSize(this: v13);
                TotalSize += v15;
              }
            }
          }
        }
        goto LABEL_69;
      }
LABEL_21:
      if ( i == 1 )
      {
        if ( Name != nullptr )
        {
          v33.key = Name;
          v9 = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Find(
                 this: &p_m_vOperatorMap->m_Elements.m_Tree,
                 search: &v33);
        }
        else
        {
          v9 = -1;
        }
        if ( v9 >= 0
          && v9 < p_m_vOperatorMap->m_Elements.m_Tree.m_Elements.m_nAllocationCount
          && v9 <= p_m_vOperatorMap->m_Elements.m_Tree.m_LastAlloc.index )
        {
          if ( (`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_104433A8 = -1;
            dword_104433AC = -1;
            dword_104433B0 = 1;
          }
          if ( p_m_vOperatorMap->m_Elements.m_Tree.m_Elements.m_pMemory[v9].m_Left != v9 )
          {
            v10 = v40;
            Operator = CSosOperatorStack::FindOperator(this: v40, pName: Name, pStructHandle: &pStructMem);
            Operator->ParseKV(this: Operator, a2: v10, a3: pStructMem, a4: pOperator);
          }
        }
      }
LABEL_69:
      FirstSubKey = KeyValues::GetNextKey(this: pOperator);
      pOperator = FirstSubKey;
    }
    v24 = i;
    if ( i == 0 )
    {
      v25 = TotalSize;
      if ( TotalSize != 0 )
      {
        v26 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: TotalSize);
        v27 = v40;
        v40->m_pMemPool = v26;
        v27->m_nMemSize = v25;
      }
      TotalSize = 0;
      FirstSubKey = KeyValues::GetFirstSubKey(this: pOperatorsKV);
      pOperator = FirstSubKey;
    }
    i = v24 + 1;
  }
  while ( v24 + 1 < 2 );
  Inorder = CUtlRBTree<CUtlMap<char const *,CSosOperator *,int>::Node_t,int,CUtlMap<char const *,CSosOperator *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperator *,int>::Node_t,int>,int>>::FirstInorder(this: &testDict.m_Elements.m_Tree);
  if ( Inorder != -1 )
  {
    m_pMemory = testDict.m_Elements.m_Tree.m_Elements.m_pMemory;
    do
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)m_pMemory[Inorder].m_Data.key);
      Inorder = CUtlRBTree<CUtlMap<char const *,CSosOperator *,int>::Node_t,int,CUtlMap<char const *,CSosOperator *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperator *,int>::Node_t,int>,int>>::NextInorder(
                  this: &testDict.m_Elements.m_Tree,
                  i: Inorder);
    }
    while ( Inorder != -1 );
  }
  CUtlRBTree<CUtlMap<char const *,CSosOperator *,int>::Node_t,int,CUtlMap<char const *,CSosOperator *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperator *,int>::Node_t,int>,int>>::RemoveAll(this: &testDict.m_Elements.m_Tree);
  CUtlRBTree<CUtlMap<char const *,CSosOperator *,int>::Node_t,int,CUtlMap<char const *,CSosOperator *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperator *,int>::Node_t,int>,int>>::RemoveAll(this: &testDict.m_Elements.m_Tree);
  if ( testDict.m_Elements.m_Tree.m_Elements.m_nGrowSize >= 0
    && testDict.m_Elements.m_Tree.m_Elements.m_pMemory != nullptr )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: testDict.m_Elements.m_Tree.m_Elements.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10052B50
// Name: public: void CSosOperatorStackList::ParseKV(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorStackList::ParseKV(CSosOperatorStackList *this, KeyValues *pOperatorsKV)
{
  KeyValues *i; // ebx
  const char *Name; // eax
  const char *v4; // edi
  CSosOperatorStack::SOSType_t v5; // esi
  CSosOperatorStack *v6; // eax
  CSosOperatorStack *v7; // esi

  for ( i = KeyValues::GetFirstSubKey(this: pOperatorsKV); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    Name = KeyValues::GetName(this: i);
    v4 = Name;
    if ( Name == nullptr || *Name == 0 )
      continue;
    if ( _V_strcmp(s1: Name, s2: "update_stack") != 0 )
    {
      if ( _V_strcmp(s1: v4, s2: "start_stack") == 0 )
        continue;
      if ( _V_strcmp(s1: v4, s2: "stop_stack") != 0 )
      {
        if ( _V_strcmp(s1: v4, s2: "cue_stack") != 0 )
        {
          if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
            _LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: 1, a3: "Error: Unknown sound operator stack type: %s\n", v4);
          continue;
        }
        v5 = SOS_CUE;
      }
      else
      {
        v5 = SOS_STOP;
      }
    }
    else
    {
      v5 = SOS_UPDATE;
    }
    v6 = (CSosOperatorStack *)MemAlloc_Alloc(nSize: 0x98u);
    if ( v6 != nullptr )
      v7 = CSosOperatorStack::CSosOperatorStack(this: v6, SosType: v5);
    else
      v7 = nullptr;
    _V_strcpy(dest: v7->m_nName, src: v4);
    switch ( v7->m_SOSType )
    {
      case SOS_UPDATE:
        this->m_vUpdateStack = v7;
LABEL_20:
        CSosOperatorStack::ParseKV(this: v7, pOperatorsKV: i);
        continue;
      case SOS_CUE:
        this->m_vCueStack = v7;
        CSosOperatorStack::ParseKV(this: v7, pOperatorsKV: i);
        break;
      case SOS_STOP:
        this->m_vStopStack = v7;
        CSosOperatorStack::ParseKV(this: v7, pOperatorsKV: i);
        break;
      default:
        goto LABEL_20;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10052C90
// Name: class CSosOperatorStack __near * S_GetStartStack(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorStack *__cdecl S_GetStartStack(KeyValues *pOperatorsKV)
{
  KeyValues *FirstSubKey; // edi
  const char *Name; // eax
  const char *v3; // esi
  CSosOperatorStack *v5; // eax
  CSosOperatorStack *v6; // eax
  CSosOperatorStack *v7; // ebx

  FirstSubKey = KeyValues::GetFirstSubKey(this: pOperatorsKV);
  if ( FirstSubKey == nullptr )
    return nullptr;
  while ( 1 )
  {
    Name = KeyValues::GetName(this: FirstSubKey);
    v3 = Name;
    if ( Name != nullptr && *Name != 0 && _V_strcmp(s1: Name, s2: "start_stack") == 0 )
      break;
    FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
    if ( FirstSubKey == nullptr )
      return nullptr;
  }
  v5 = (CSosOperatorStack *)MemAlloc_Alloc(nSize: 0x98u);
  if ( v5 == nullptr )
    return nullptr;
  v6 = CSosOperatorStack::CSosOperatorStack(this: v5, SosType: SOS_START);
  v7 = v6;
  if ( v6 != nullptr )
  {
    _V_strcpy(dest: v6->m_nName, src: v3);
    CSosOperatorStack::ParseKV(this: v7, pOperatorsKV: FirstSubKey);
    if ( snd_sos_show_operator_init.m_pParent != nullptr && snd_sos_show_operator_init.m_pParent->m_Value.m_nValue != 0 )
    {
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: 0) != 0 )
        LoggingSystem_Log(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: LS_MESSAGE, a3: StackColor, a4: "\nSTART Operators:\n");
      CSosOperatorStack::Print(this: v7, nLevel: 1u);
    }
  }
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x10052D70
// Name: class CSosOperatorStackList __near * S_InitChannelOperators(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorStackList *__cdecl S_InitChannelOperators(KeyValues *pOperatorsKV)
{
  CSosOperatorStackList *result; // eax
  CSosOperatorStackList *v2; // eax
  CSosOperatorStackList *v3; // esi

  result = nullptr;
  if ( pOperatorsKV != nullptr )
  {
    v2 = (CSosOperatorStackList *)MemAlloc_Alloc(nSize: 0x18u);
    if ( v2 != nullptr )
    {
      v2->m_vUpdateStack = nullptr;
      v2->m_vStopStack = nullptr;
      v2->m_vCueStack = nullptr;
      v2->m_stopType = SOS_STOP_NONE;
      v2->m_flStopTime = -1.0;
      v3 = v2;
    }
    else
    {
      v3 = nullptr;
    }
    CSosOperatorStackList::ParseKV(this: v3, pOperatorsKV);
    if ( v3 != nullptr
      && snd_sos_show_operator_init.m_pParent != nullptr
      && snd_sos_show_operator_init.m_pParent->m_Value.m_nValue != 0 )
    {
      CSosOperatorStackList::Print(this: v3);
    }
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10052DF0
// Name: public: void CSosOperatorStackCollection::ParseKV(enum CSosOperatorStack::SOSType_t,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorStackCollection::ParseKV(
        CSosOperatorStackCollection *this,
        CSosOperatorStack::SOSType_t SosType,
        KeyValues *pStackType)
{
  KeyValues *FirstSubKey; // eax
  const char *Name; // esi
  _DWORD *v5; // eax
  _DWORD *v6; // ebx
  CSosOperatorStackCollection *v7; // ebx
  int i; // edi
  int v9; // ecx
  void (__thiscall *Free_2)(IMemAlloc *, void *); // edx
  void *v11; // eax
  KeyValues *pStack; // [esp+4h] [ebp-8h]

  FirstSubKey = KeyValues::GetFirstSubKey(this: pStackType);
  pStack = FirstSubKey;
  if ( FirstSubKey != nullptr )
  {
    while ( 1 )
    {
      Name = KeyValues::GetName(this: FirstSubKey);
      v5 = MemAlloc_Alloc(nSize: 0x98u);
      if ( v5 != nullptr )
      {
        v5[19] = 0;
        v5[20] = 0;
        v5[21] = 0;
        v5[22] = 0;
        v5[23] = 0;
        v5[24] = 0;
        v5[25] = 0;
        v5[26] = 0;
        v5[27] = 0;
        v5[28] = -1;
        v5[29] = 0;
        v5[30] = -1;
        v5[31] = -1;
        v5[32] = v5[25];
        if ( v5[24] == 0 )
          v5[24] = CaselessStringLessThan;
        v5[16] = SosType;
        v5[17] = 0;
        v5[18] = 0;
        v5[33] = -1;
        v5[34] = -1082130432;
        *((_WORD *)v5 + 70) = -1;
        v5[36] = 0;
        v5[37] = -1082130432;
        v6 = v5;
      }
      else
      {
        v6 = nullptr;
      }
      pStackType = (KeyValues *)v6;
      _V_strcpy(dest: (char *)v6, src: Name);
      CSosOperatorStack::ParseKV(this: (CSosOperatorStack *)v6, pOperatorsKV: pStack);
      switch ( SosType )
      {
        case SOS_UPDATE:
          v7 = this;
          CUtlDict<CSosOperatorStack *,int>::Insert(
            this: &this->m_vUpdateStacks,
            pName: Name,
            element: (CSosOperatorStack *const *)&pStackType);
          goto LABEL_11;
        case SOS_CUE:
          v7 = this;
          CUtlDict<CSosOperatorStack *,int>::Insert(
            this: &this->m_vCueStacks,
            pName: Name,
            element: (CSosOperatorStack *const *)&pStackType);
LABEL_11:
          CUtlDict<CSosOperatorStack *,int>::Insert(
            this: &v7->m_vAllStacks,
            pName: Name,
            element: (CSosOperatorStack *const *)&pStackType);
          break;
        case SOS_START:
          CUtlDict<CSosOperatorStack *,int>::Insert(
            this: &this->m_vStartStacks,
            pName: Name,
            element: (CSosOperatorStack *const *)&pStackType);
          CUtlDict<CSosOperatorStack *,int>::Insert(
            this: &this->m_vAllStacks,
            pName: Name,
            element: (CSosOperatorStack *const *)&pStackType);
          break;
        case SOS_STOP:
          CUtlDict<CSosOperatorStack *,int>::Insert(
            this: &this->m_vStopStacks,
            pName: Name,
            element: (CSosOperatorStack *const *)&pStackType);
          CUtlDict<CSosOperatorStack *,int>::Insert(
            this: &this->m_vAllStacks,
            pName: Name,
            element: (CSosOperatorStack *const *)&pStackType);
          break;
        default:
          if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
            _LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: 1, a3: "Error: Unknown sound operator stack type");
          if ( v6 != nullptr )
          {
            if ( v6[17] != 0 )
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)v6[17]);
            for ( i = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::FirstInorder(this: (CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> > *)(v6 + 24));
                  i != -1;
                  i = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::NextInorder(
                        this: (CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> > *)(v6 + 24),
                        i) )
            {
              v9 = v6[25];
              Free_2 = _g_pMemAlloc->Free_2;
              pStackType = (KeyValues *)_g_pMemAlloc;
              Free_2(this: _g_pMemAlloc, a2: *(void **)(v9 + 24 * i + 16));
            }
            CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RemoveAll(this: (CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> > *)(v6 + 24));
            CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RemoveAll(this: (CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> > *)(v6 + 24));
            v6[30] = -1;
            if ( (int)v6[27] >= 0 )
            {
              if ( v6[25] != 0 )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)v6[25]);
                v6[25] = 0;
              }
              v6[26] = 0;
            }
            v6[31] = -1;
            if ( (int)v6[27] >= 0 )
            {
              if ( v6[25] != 0 )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)v6[25]);
                v6[25] = 0;
              }
              v6[26] = 0;
            }
            v6[22] = 0;
            if ( (int)v6[21] >= 0 )
            {
              if ( v6[19] != 0 )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)v6[19]);
                v6[19] = 0;
              }
              v6[20] = 0;
            }
            v11 = (void *)v6[19];
            v6[23] = v11;
            if ( (int)v6[21] >= 0 )
            {
              if ( v11 != nullptr )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v11);
                v6[19] = 0;
              }
              v6[20] = 0;
            }
            free(pMem: v6);
          }
          break;
      }
      pStack = KeyValues::GetNextKey(this: pStack);
      if ( pStack == nullptr )
        break;
      FirstSubKey = pStack;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100530C0
// Name: public: void CSosOperatorSystem::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorSystem::Init(CSosOperatorSystem *this)
{
  CSosOperatorSystem *v1; // esi
  bool v2; // zf
  KeyValues *v3; // eax
  KeyValues *NextKey; // ebx
  CSosOperatorStack::SOSType_t v5; // edi
  const char *Name; // eax
  const char *v7; // esi
  unsigned int crc; // [esp+4h] [ebp-Ch] BYREF
  CSosOperatorStackCollection *p_m_MasterStackCollection; // [esp+8h] [ebp-8h]
  KeyValues *pSoundOperatorStacksKV; // [esp+Ch] [ebp-4h]

  v1 = this;
  v2 = !this->m_bHasInitialized;
  p_m_MasterStackCollection = &this->m_MasterStackCollection;
  if ( v2 )
  {
    this->m_bHasInitialized = true;
    CRC32_Init(pulCRC: &crc);
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
    {
      NextKey = KeyValues::KeyValues(this: v3, setName: "scripts/sound_operator_stacks.txt");
      pSoundOperatorStacksKV = NextKey;
    }
    else
    {
      pSoundOperatorStacksKV = nullptr;
      NextKey = nullptr;
    }
    if ( g_pFullFileSystem->LoadKeyValues(
           this: g_pFullFileSystem,
           a2: NextKey,
           a3: TYPE_SOUNDOPERATORS,
           a4: "scripts/sound_operator_stacks.txt",
           a5: "GAME") )
    {
      if ( NextKey != nullptr )
      {
        while ( 1 )
        {
          v5 = SOS_NONE;
          Name = KeyValues::GetName(this: NextKey);
          v7 = Name;
          if ( Name != nullptr && *Name != 0 )
          {
            if ( _V_strcmp(s1: Name, s2: "update_stacks") != 0 )
            {
              if ( _V_strcmp(s1: v7, s2: "start_stacks") != 0 )
              {
                if ( _V_strcmp(s1: v7, s2: "stop_stacks") != 0 )
                {
                  if ( _V_strcmp(s1: v7, s2: "cue_stacks") != 0 )
                  {
                    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
                      _LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: 1, a3: "Unknown sound operator stack arg %s", v7);
                    goto LABEL_12;
                  }
                  v5 = SOS_CUE;
                }
                else
                {
                  v5 = SOS_STOP;
                }
              }
              else
              {
                v5 = SOS_START;
              }
            }
            else
            {
              v5 = SOS_UPDATE;
            }
          }
          CSosOperatorStackCollection::ParseKV(this: p_m_MasterStackCollection, SosType: v5, pStackType: NextKey);
          NextKey = KeyValues::GetNextKey(this: NextKey);
LABEL_12:
          if ( NextKey == nullptr )
          {
            v1 = (CSosOperatorSystem *)p_m_MasterStackCollection;
            NextKey = pSoundOperatorStacksKV;
            break;
          }
        }
      }
    }
    else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
    {
      _LoggingSystem_Log(
        a1: LOG_SND_OPERATORS,
        a2: 1,
        a3: "Warning: Unable to load sound operators file '%s'\n",
        "scripts/sound_operator_stacks.txt");
    }
    KeyValues::deleteThis(this: NextKey);
    CRC32_Final(pulCRC: &crc);
    if ( snd_sos_show_operator_init.m_pParent != nullptr && snd_sos_show_operator_init.m_pParent->m_Value.m_nValue != 0 )
      CSosOperatorStackCollection::Print(this: &v1->m_MasterStackCollection);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10053270
// Name: void S_SOSFlush(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl S_SOSFlush()
{
  if ( (_S1_2 & 1) == 0 )
  {
    _S1_2 |= 1u;
    CSosOperatorSystem::CSosOperatorSystem(this: &s_SoundOperatorSystem);
    atexit(func: CSosOperatorSystem::GetSoundOperatorSystem_::_2_::_dynamic_atexit_destructor_for__s_SoundOperatorSystem__);
  }
  CSosOperatorStackCollection::Clear(this: &s_SoundOperatorSystem.m_MasterStackCollection);
  s_SoundOperatorSystem.m_bHasInitialized = false;
  CSosOperatorSystem::Init(this: &s_SoundOperatorSystem);
}

//------------------------------------------------------------------------------
// Address: 0x1013F750
// Name: public: void CTSQueue<int,0,1>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTSQueue<int,0,1>::Purge(CTSQueue<int,0,1> *this)
{
  CTSQueue<int,0,1>::Node_t *i; // eax
  CTSListBase *p_m_FreeNodes; // edi
  TSLNodeBase_t *Next; // esi
  int DepthAndSequence; // eax

  for ( i = CTSQueue<loopback_t *,0,1>::Pop(this); i != nullptr; i = CTSQueue<loopback_t *,0,1>::Pop(this) )
    free(pMem: i);
  p_m_FreeNodes = &this->m_FreeNodes;
  while ( 1 )
  {
    Next = p_m_FreeNodes->m_Head.value.Next;
    DepthAndSequence = p_m_FreeNodes->m_Head.value32.DepthAndSequence;
    if ( p_m_FreeNodes->m_Head.value.Next == nullptr )
      break;
    while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                               a1: p_m_FreeNodes,
                               a2: Next->Next,
                               a3: DepthAndSequence - 1,
                               a4: Next,
                               a5: DepthAndSequence) == 0 )
    {
      _mm_pause();
      Next = p_m_FreeNodes->m_Head.value.Next;
      DepthAndSequence = p_m_FreeNodes->m_Head.value32.DepthAndSequence;
      if ( p_m_FreeNodes->m_Head.value.Next == nullptr )
        goto LABEL_7;
    }
    free(pMem: Next);
  }
LABEL_7:
  this->m_Head.value.sequence = 0;
  this->m_Tail.value.sequence = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10321FC0
// Name: _CSosOperatorSystem::GetSoundOperatorSystem_::_2_::_dynamic_atexit_destructor_for__s_SoundOperatorSystem__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CSosOperatorSystem::GetSoundOperatorSystem_::_2_::_dynamic_atexit_destructor_for__s_SoundOperatorSystem__()
{
  CSosOperatorSystem::~CSosOperatorSystem(this: &s_SoundOperatorSystem);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1004F250
// Name: public: void CSosOperatorStack::SetStopType(enum SOSStopType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorStack::SetStopType(CSosOperatorStack *this, SOSStopType_t stopType)
{
  if ( stopType != SOS_STOP_NONE )
    this->m_stopType = stopType;
}

//------------------------------------------------------------------------------
// Address: 0x1004F270
// Name: public: bool CSosOperatorStackList::HasStack(enum CSosOperatorStack::SOSType_t)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSosOperatorStackList::HasStack(CSosOperatorStackList *this, CSosOperatorStack::SOSType_t SosType)
{
  bool v3; // zf

  if ( SosType == SOS_UPDATE )
  {
    v3 = this->m_vUpdateStack == nullptr;
  }
  else
  {
    if ( SosType != SOS_CUE )
      return SosType == SOS_STOP && this->m_vStopStack != nullptr;
    v3 = this->m_vCueStack == nullptr;
  }
  return !v3;
}

//------------------------------------------------------------------------------
// Address: 0x1004F2B0
// Name: public: class CSosOperatorStack __near * CSosOperatorStackList::GetStack(enum CSosOperatorStack::SOSType_t)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorStack *__thiscall CSosOperatorStackList::GetStack(
        CSosOperatorStackList *this,
        CSosOperatorStack::SOSType_t SosType)
{
  switch ( SosType )
  {
    case SOS_UPDATE:
      return this->m_vUpdateStack;
    case SOS_CUE:
      return this->m_vCueStack;
    case SOS_STOP:
      return this->m_vStopStack;
    default:
      break;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1004F2E0
// Name: public: void CSosOperatorStackList::SetScriptHandle(short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorStackList::SetScriptHandle(CSosOperatorStackList *this, __int16 nHandle)
{
  CSosOperatorStack *m_vCueStack; // eax
  CSosOperatorStack *m_vStopStack; // ecx

  m_vCueStack = this->m_vCueStack;
  if ( m_vCueStack != nullptr )
    m_vCueStack->m_nScriptHandle = nHandle;
  if ( this->m_vUpdateStack != nullptr )
    this->m_vUpdateStack->m_nScriptHandle = nHandle;
  m_vStopStack = this->m_vStopStack;
  if ( m_vStopStack != nullptr )
    m_vStopStack->m_nScriptHandle = nHandle;
}

//------------------------------------------------------------------------------
// Address: 0x1004F320
// Name: public: void CSosOperatorStackList::SetChannelGuid(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorStackList::SetChannelGuid(CSosOperatorStackList *this, int nGuid)
{
  CSosOperatorStack *m_vCueStack; // eax
  CSosOperatorStack *m_vStopStack; // ecx

  m_vCueStack = this->m_vCueStack;
  if ( m_vCueStack != nullptr )
    m_vCueStack->m_nChannelGuid = nGuid;
  if ( this->m_vUpdateStack != nullptr )
    this->m_vUpdateStack->m_nChannelGuid = nGuid;
  m_vStopStack = this->m_vStopStack;
  if ( m_vStopStack != nullptr )
    m_vStopStack->m_nChannelGuid = nGuid;
}

//------------------------------------------------------------------------------
// Address: 0x1004F350
// Name: public: void CSosOperatorStackList::SetStartTime(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorStackList::SetStartTime(CSosOperatorStackList *this, float flStartTime)
{
  CSosOperatorStack *m_vCueStack; // eax
  CSosOperatorStack *m_vStopStack; // ecx

  m_vCueStack = this->m_vCueStack;
  if ( m_vCueStack != nullptr )
    m_vCueStack->m_flStartTime = flStartTime;
  if ( this->m_vUpdateStack != nullptr )
    this->m_vUpdateStack->m_flStartTime = flStartTime;
  m_vStopStack = this->m_vStopStack;
  if ( m_vStopStack != nullptr )
    m_vStopStack->m_flStartTime = flStartTime;
}

//------------------------------------------------------------------------------
// Address: 0x1004F390
// Name: public: void CSosOperatorStackList::SetStopTime(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorStackList::SetStopTime(CSosOperatorStackList *this, float flStopTime)
{
  CSosOperatorStack *m_vCueStack; // eax
  CSosOperatorStack *m_vStopStack; // ecx

  m_vCueStack = this->m_vCueStack;
  this->m_flStopTime = flStopTime;
  if ( m_vCueStack != nullptr )
    m_vCueStack->m_flStopTime = flStopTime;
  if ( this->m_vUpdateStack != nullptr )
    this->m_vUpdateStack->m_flStopTime = flStopTime;
  m_vStopStack = this->m_vStopStack;
  if ( m_vStopStack != nullptr )
    m_vStopStack->m_flStopTime = flStopTime;
}

//------------------------------------------------------------------------------
// Address: 0x1004F3D0
// Name: public: void CSosOperatorStackList::SetStopType(enum SOSStopType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorStackList::SetStopType(CSosOperatorStackList *this, SOSStopType_t stopType)
{
  CSosOperatorStack *m_vCueStack; // edx
  CSosOperatorStack *m_vStopStack; // ecx

  m_vCueStack = this->m_vCueStack;
  this->m_stopType = stopType;
  if ( m_vCueStack != nullptr && stopType != SOS_STOP_NONE )
    m_vCueStack->m_stopType = stopType;
  if ( this->m_vUpdateStack != nullptr && stopType != SOS_STOP_NONE )
    this->m_vUpdateStack->m_stopType = stopType;
  m_vStopStack = this->m_vStopStack;
  if ( m_vStopStack != nullptr && stopType != SOS_STOP_NONE )
    m_vStopStack->m_stopType = stopType;
}

//------------------------------------------------------------------------------
// Address: 0x1004F410
// Name: public: void CSosOperatorSystem::Update(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorSystem::Update(CSosOperatorSystem *this)
{
  CSosEntryMatchList::Update(this: &this->m_sosEntryBlockList);
}

//------------------------------------------------------------------------------
// Address: 0x1004F420
// Name: public: CSosEntryMatchList::CSosEntryMatchList(void)
// Source: json
//------------------------------------------------------------------------------
CSosEntryMatchList *__thiscall CSosEntryMatchList::CSosEntryMatchList(CSosEntryMatchList *this)
{
  int i; // edi
  _WORD *v3; // eax
  unsigned int bit; // [esp+Ch] [ebp-4h]

  bit = 1;
  for ( i = 0; i < 32; ++i )
  {
    v3 = MemAlloc_Alloc(nSize: 0xA0u);
    if ( v3 != nullptr )
    {
      *(_BYTE *)v3 = 10;
      v3[32] = 2560;
      *(_WORD *)((char *)v3 + 129) = 0;
      *((_DWORD *)v3 + 33) = -1;
      *((_BYTE *)v3 + 136) = 0;
      *((_DWORD *)v3 + 35) = -1;
      *((_BYTE *)v3 + 144) = 0;
    }
    else
    {
      v3 = nullptr;
    }
    this->m_vEntryMatchList[i] = (CSosManagedEntryMatch *)v3;
    *(_BYTE *)v3 = 10;
    v3[32] = 2560;
    *(_WORD *)((char *)v3 + 129) = 0;
    *((_DWORD *)v3 + 33) = -1;
    *((_BYTE *)v3 + 136) = 0;
    *((_DWORD *)v3 + 35) = -1;
    *((_BYTE *)v3 + 144) = 0;
    *(_WORD *)((char *)v3 + 149) = 0;
    *((_DWORD *)v3 + 38) = -1082130432;
    *((_DWORD *)v3 + 39) = -1082130432;
    *((_BYTE *)v3 + 148) = 1;
    this->m_Free |= bit;
    bit *= 2;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1004F540
// Name: public: void CSosOperatorStack::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorStack::Shutdown(CSosOperatorStack *this)
{
  int v1; // edi
  char *v3; // ebx
  CSosOperator *v4; // ecx
  CSosOperator *v5; // ecx
  unsigned int TotalSize; // [esp+8h] [ebp-4h]

  v1 = 0;
  for ( TotalSize = 0; v1 < this->m_vStack.m_Size; ++v1 )
  {
    v3 = (char *)this->m_pMemPool + TotalSize;
    CSosOperator::ResolveInputValues(
      this: this->m_vStack.m_Memory.m_pMemory[v1],
      pStructMem: v3,
      pStackMem: (char *)this->m_pMemPool);
    v4 = this->m_vStack.m_Memory.m_pMemory[v1];
    v4->StackShutdown(this: v4, a2: v3, a3: this, a4: v1);
    v5 = this->m_vStack.m_Memory.m_pMemory[v1];
    TotalSize += v5->GetSize(this: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004F6B0
// Name: public: void CSosOperatorStack::Print(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorStack::Print(CSosOperatorStack *this, unsigned int nLevel)
{
  int v2; // edi
  CSosOperator *v5; // ecx
  CSosOperator *v6; // ecx
  unsigned int TotalSize; // [esp+14h] [ebp+8h]

  v2 = 0;
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
    LoggingSystem_Log(
      a1: LOG_SND_OPERATORS,
      a2: LS_MESSAGE,
      a3: StackColor,
      a4: "\n%*sOperator Stack: %s\n%*sSize: %i\n",
      nLevel,
      "    ",
      this->m_nName,
      nLevel,
      "    ",
      this->m_nMemSize);
  TotalSize = 0;
  if ( this->m_vStack.m_Size > 0 )
  {
    do
    {
      v5 = this->m_vStack.m_Memory.m_pMemory[v2];
      v5->Print(this: v5, a2: (char *)this->m_pMemPool + TotalSize, a3: this, a4: v2, a5: nLevel);
      v6 = this->m_vStack.m_Memory.m_pMemory[v2];
      TotalSize += v6->GetSize(this: v6);
      ++v2;
    }
    while ( v2 < this->m_vStack.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004F740
// Name: public: void CSosOperatorStackList::Execute(enum CSosOperatorStack::SOSType_t,struct channel_t __near *,class CScratchPad __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorStackList::Execute(
        CSosOperatorStackList *this,
        CSosOperatorStack::SOSType_t SosType,
        channel_t *pChannel,
        CScratchPad *pScratchPad)
{
  CSosOperatorStack *m_vCueStack; // ecx
  SOSStopType_t m_stopType; // eax

  if ( SosType == SOS_UPDATE )
  {
    if ( this->m_vUpdateStack != nullptr )
    {
      m_stopType = this->m_stopType;
      if ( m_stopType != SOS_STOP_NONE )
        this->m_vUpdateStack->m_stopType = m_stopType;
      CSosOperatorStack::Execute(this: this->m_vUpdateStack, pChannel, pScratchPad);
      CSosOperatorStackList::SetStopType(this, stopType: this->m_vUpdateStack->m_stopType);
    }
  }
  else
  {
    if ( SosType == SOS_CUE )
    {
      m_vCueStack = this->m_vCueStack;
    }
    else
    {
      if ( SosType != SOS_STOP )
        return;
      m_vCueStack = this->m_vStopStack;
    }
    if ( m_vCueStack != nullptr )
      CSosOperatorStack::Execute(this: m_vCueStack, pChannel, pScratchPad);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004F7B0
// Name: public: void CSosOperatorStackList::Print(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorStackList::Print(CSosOperatorStackList *this)
{
  CSosOperatorStack *m_vCueStack; // ecx
  CSosOperatorStack *m_vStopStack; // ecx

  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: 0) != 0 )
    LoggingSystem_Log(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: LS_MESSAGE, a3: StackColor, a4: "\nStack List:\n");
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: 0) != 0 )
    LoggingSystem_Log(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: LS_MESSAGE, a3: StackColor, a4: "\nCUE Operators:\n");
  m_vCueStack = this->m_vCueStack;
  if ( m_vCueStack != nullptr )
    CSosOperatorStack::Print(this: m_vCueStack, nLevel: 1u);
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: 0) != 0 )
    LoggingSystem_Log(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: LS_MESSAGE, a3: StackColor, a4: "\nUPDATE Operators:\n");
  if ( this->m_vUpdateStack != nullptr )
    CSosOperatorStack::Print(this: this->m_vUpdateStack, nLevel: 1u);
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: 0) != 0 )
    LoggingSystem_Log(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: LS_MESSAGE, a3: StackColor, a4: "\nSTOP Operators:\n");
  m_vStopStack = this->m_vStopStack;
  if ( m_vStopStack != nullptr )
    CSosOperatorStack::Print(this: m_vStopStack, nLevel: 1u);
}

//------------------------------------------------------------------------------
// Address: 0x1004F8A0
// Name: public: void CSosOperatorStackList::StopStacks(enum SOSStopType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorStackList::StopStacks(CSosOperatorStackList *this, SOSStopType_t stopType)
{
  CSosOperatorStack *m_vCueStack; // eax
  CSosOperatorStack *m_vStopStack; // esi
  CSosOperatorStack *v5; // eax
  CSosOperatorStack *v6; // eax
  CSosOperatorStack *v7; // ecx
  float stopTypea; // [esp+Ch] [ebp+8h]

  if ( stopType == SOS_STOP_FORCE )
  {
    m_vCueStack = this->m_vCueStack;
    this->m_stopType = SOS_STOP_FORCE;
    if ( m_vCueStack != nullptr )
      m_vCueStack->m_stopType = SOS_STOP_FORCE;
    if ( this->m_vUpdateStack != nullptr )
      this->m_vUpdateStack->m_stopType = SOS_STOP_FORCE;
    m_vStopStack = this->m_vStopStack;
    if ( m_vStopStack != nullptr )
      m_vStopStack->m_stopType = SOS_STOP_FORCE;
  }
  else if ( this->m_stopType == SOS_STOP_NONE && stopType != SOS_STOP_NONE )
  {
    CSosOperatorStackList::SetStopType(this, stopType);
    stopTypea = g_pSoundServices->GetHostTime(this: g_pSoundServices);
    v5 = this->m_vCueStack;
    this->m_flStopTime = stopTypea;
    if ( v5 != nullptr )
      v5->m_flStopTime = stopTypea;
    if ( this->m_vUpdateStack != nullptr )
      this->m_vUpdateStack->m_flStopTime = stopTypea;
    v6 = this->m_vStopStack;
    if ( v6 != nullptr )
      v6->m_flStopTime = stopTypea;
    v7 = this->m_vStopStack;
    if ( v7 != nullptr )
      CSosOperatorStack::Execute(this: v7, pChannel: nullptr, pScratchPad: &g_scratchpad);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10050CA0
// Name: public: void CSosOperatorStackCollection::Print(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorStackCollection::Print(CSosOperatorStackCollection *this)
{
  unsigned __int8 (__cdecl *v1)(int, _DWORD); // ebx
  unsigned int v3; // edi
  int v4; // ebx
  unsigned int v5; // edi
  int v6; // ebx
  unsigned int v7; // edi
  int v8; // ebx
  unsigned int v9; // edi
  int v10; // ebx

  v1 = (unsigned __int8 (__cdecl *)(int, _DWORD))_LoggingSystem_IsChannelEnabled;
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
    LoggingSystem_Log(
      a1: LOG_SND_OPERATORS,
      a2: LS_MESSAGE,
      a3: CollectionColor,
      a4: "\n\nSound Operators Collection:\n");
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
    LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: LS_MESSAGE, a3: CollectionColor, a4: "\n%*sCue Stacks:\n", 1, "    ");
  v3 = 0;
  if ( this->m_vCueStacks.m_Elements.m_Tree.m_NumElements != 0 )
  {
    v4 = 0;
    do
    {
      CSosOperatorStack::Print(
        this: this->m_vCueStacks.m_Elements.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem,
        nLevel: 3u);
      ++v3;
      ++v4;
    }
    while ( v3 < this->m_vCueStacks.m_Elements.m_Tree.m_NumElements );
    v1 = (unsigned __int8 (__cdecl *)(int, _DWORD))_LoggingSystem_IsChannelEnabled;
  }
  if ( v1(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
    LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: LS_MESSAGE, a3: CollectionColor, a4: "\n%*sStart Stacks:\n", 1, "    ");
  v5 = 0;
  if ( this->m_vStartStacks.m_Elements.m_Tree.m_NumElements != 0 )
  {
    v6 = 0;
    do
    {
      CSosOperatorStack::Print(
        this: this->m_vStartStacks.m_Elements.m_Tree.m_Elements.m_pMemory[v6].m_Data.elem,
        nLevel: 3u);
      ++v5;
      ++v6;
    }
    while ( v5 < this->m_vStartStacks.m_Elements.m_Tree.m_NumElements );
    v1 = (unsigned __int8 (__cdecl *)(int, _DWORD))_LoggingSystem_IsChannelEnabled;
  }
  if ( v1(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
    LoggingSystem_Log(
      a1: LOG_SND_OPERATORS,
      a2: LS_MESSAGE,
      a3: CollectionColor,
      a4: "\n%*sUpdate Stacks:\n",
      1,
      "    ");
  v7 = 0;
  if ( this->m_vUpdateStacks.m_Elements.m_Tree.m_NumElements != 0 )
  {
    v8 = 0;
    do
    {
      CSosOperatorStack::Print(
        this: this->m_vUpdateStacks.m_Elements.m_Tree.m_Elements.m_pMemory[v8].m_Data.elem,
        nLevel: 3u);
      ++v7;
      ++v8;
    }
    while ( v7 < this->m_vUpdateStacks.m_Elements.m_Tree.m_NumElements );
    v1 = (unsigned __int8 (__cdecl *)(int, _DWORD))_LoggingSystem_IsChannelEnabled;
  }
  if ( v1(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
    LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: LS_MESSAGE, a3: CollectionColor, a4: "\n%*sStop Stacks:\n", 1, "    ");
  v9 = 0;
  if ( this->m_vStopStacks.m_Elements.m_Tree.m_NumElements != 0 )
  {
    v10 = 0;
    do
    {
      CSosOperatorStack::Print(
        this: this->m_vStopStacks.m_Elements.m_Tree.m_Elements.m_pMemory[v10].m_Data.elem,
        nLevel: 3u);
      ++v9;
      ++v10;
    }
    while ( v9 < this->m_vStopStacks.m_Elements.m_Tree.m_NumElements );
    v1 = (unsigned __int8 (__cdecl *)(int, _DWORD))_LoggingSystem_IsChannelEnabled;
  }
  if ( v1(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
    LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: LS_MESSAGE, a3: CollectionColor, a4: "\n");
}

//------------------------------------------------------------------------------
// Address: 0x10050EA0
// Name: public: void CSosOperatorSystem::StartQueuedEntries(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorSystem::StartQueuedEntries(CSosOperatorSystem *this)
{
  CTSQueue<StartSoundParams_t,0,1> *i; // ebx
  CTSQueue<StartSoundParams_t,0,1>::Node_t *v2; // eax
  TSLNodeBase_t *v3; // edi
  StartSoundParams_t soundParams; // [esp+0h] [ebp-64h] BYREF
  CTSQueue<StartSoundParams_t,0,1>::Node_t *savedregs; // [esp+64h] [ebp+0h] BYREF

  if ( this->m_sosStartEntryQueue.m_Count.m_value != 0 )
  {
    for ( i = &this->m_sosStartEntryQueue;
          ;
          S_StartSoundEntry(a1: (int)i, a2: (int)v3, a3: 0, pStartParams: &soundParams, nSeed: -1) )
    {
      *((_BYTE *)&soundParams + 96) = *((_BYTE *)&soundParams + 96) & 0xC0 | 2;
      memset(&soundParams, 0, 40);
      soundParams.fvol = 1.0;
      soundParams.soundlevel = SNDLVL_NORM;
      soundParams.flags = 0;
      soundParams.pitch = 100;
      soundParams.delay = 0.0;
      soundParams.speakerentity = -1;
      soundParams.initialStreamPosition = 0;
      soundParams.skipInitialSamples = 0;
      soundParams.m_nQueuedGUID = -1;
      soundParams.m_nSoundScriptHandle = -1;
      memset(&soundParams.m_pSoundEntryName, 0, 16);
      v2 = CTSQueue<StartSoundParams_t,0,1>::Pop(this: i, a2: &savedregs);
      v3 = (TSLNodeBase_t *)v2;
      if ( v2 == nullptr )
        break;
      StartSoundParams_t::operator=(this: &soundParams, __that: &v2->elem);
      CTSListBase::Push(this: &i->m_FreeNodes, pNode: v3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10050F80
// Name: public: void CSosOperatorSystem::StopQueuedChannels(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorSystem::StopQueuedChannels(CSosOperatorSystem *this)
{
  CTSQueue<int,0,1> *p_m_sosStopChannelQueue; // edi
  CTSQueue<int,0,1>::Node_t *v2; // eax
  int elem; // esi

  if ( this->m_sosStopChannelQueue.m_Count.m_value != 0 )
  {
    p_m_sosStopChannelQueue = &this->m_sosStopChannelQueue;
    while ( 1 )
    {
      v2 = CTSQueue<loopback_t *,0,1>::Pop(this: p_m_sosStopChannelQueue);
      if ( v2 == nullptr )
        break;
      elem = v2->elem;
      CTSListBase::Push(this: &p_m_sosStopChannelQueue->m_FreeNodes, pNode: (TSLNodeBase_t *)v2);
      if ( elem != -1 )
        S_StopSoundByGuid(guid: elem, bForceSync: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10051190
// Name: public: class CSosOperator __near * CSosOperatorStack::FindOperator(char const __near *,void __near * __near *)
// Source: json
//------------------------------------------------------------------------------
CSosOperator *__thiscall CSosOperatorStack::FindOperator(
        CSosOperatorStack *this,
        const char *pName,
        void **pStructHandle)
{
  int v4; // ebx
  int v5; // esi
  CSosOperator *v6; // ecx
  CUtlMap<char const *,int,int>::Node_t search; // [esp+Ch] [ebp-8h] BYREF
  int nOpIndex; // [esp+1Ch] [ebp+8h]

  if ( pName != nullptr )
  {
    search.key = pName;
    nOpIndex = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Find(
                 this: &this->m_vOperatorMap.m_Elements.m_Tree,
                 &search);
  }
  else
  {
    nOpIndex = -1;
  }
  v4 = 0;
  v5 = 0;
  *pStructHandle = this->m_pMemPool;
  if ( nOpIndex <= 0 )
    return this->m_vStack.m_Memory.m_pMemory[nOpIndex];
  while ( 1 )
  {
    v6 = this->m_vStack.m_Memory.m_pMemory[v5];
    if ( v6 == nullptr )
      break;
    v4 += v6->GetSize(this: v6);
    ++v5;
    *pStructHandle = (char *)this->m_pMemPool + v4;
    if ( v5 >= nOpIndex )
      return this->m_vStack.m_Memory.m_pMemory[nOpIndex];
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10051210
// Name: public: int CSosOperatorStack::GetOperatorOutputOffset(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CSosOperatorStack::GetOperatorOutputOffset(
        CSosOperatorStack *this,
        const char *pOperatorName,
        const char *pOutputName)
{
  int v4; // eax
  CSosOperator *v6; // edi
  int OperatorOffset; // esi
  CUtlMap<char const *,int,int>::Node_t search; // [esp+8h] [ebp-8h] BYREF

  if ( pOperatorName != nullptr
    && (search.key = pOperatorName,
        (v4 = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Find(
                this: &this->m_vOperatorMap.m_Elements.m_Tree,
                &search)) >= 0)
    && v4 < this->m_vStack.m_Size )
  {
    v6 = this->m_vStack.m_Memory.m_pMemory[v4];
    OperatorOffset = CSosOperatorStack::GetOperatorOffset(this, nIndex: v4);
    return OperatorOffset + CSosOperator::GetOutputOffset(this: v6, pOutputName);
  }
  else
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
      _LoggingSystem_Log(
        a1: LOG_SND_OPERATORS,
        a2: 1,
        a3: "Error: Unable to find referenced operator: %s",
        pOperatorName);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100512A0
// Name: public: void CSosOperatorStack::ExecuteIterator(struct channel_t __near *,class CScratchPad __near *,void const __near *,char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorStack::ExecuteIterator(
        CSosOperatorStack *this,
        channel_t *pChannel,
        CScratchPad *pScratchPad,
        float *pStopMemBlock,
        const char *pOperatorName,
        int *pnOperatorIndex)
{
  int v7; // eax
  int v8; // esi
  char *m_pMemPool; // eax
  float *v10; // ebx
  CSosOperator *v11; // ecx
  CSosOperator *v12; // ecx
  CSosOperator *v13; // ecx
  CUtlMap<char const *,int,int>::Node_t search; // [esp+Ch] [ebp-8h] BYREF
  unsigned int TotalSize; // [esp+2Ch] [ebp+18h]

  if ( snd_sos_show_operator_updates.m_pParent != nullptr
    && snd_sos_show_operator_updates.m_pParent->m_Value.m_nValue != 0
    && (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
  {
    LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: LS_MESSAGE, a3: StackColor, a4: "Operator Stack: %s\n", this->m_nName);
  }
  search.elem = *pnOperatorIndex;
  if ( search.elem >= 0 )
    goto LABEL_10;
  if ( pOperatorName != nullptr )
  {
    search.key = pOperatorName;
    v7 = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Find(
           this: &this->m_vOperatorMap.m_Elements.m_Tree,
           &search);
    if ( v7 >= 0 && v7 < this->m_vStack.m_Size )
    {
      search.elem = v7;
      *pnOperatorIndex = v7;
LABEL_10:
      v8 = 0;
      for ( TotalSize = 0; v8 < this->m_vStack.m_Size; ++v8 )
      {
        m_pMemPool = (char *)this->m_pMemPool;
        v10 = (float *)&m_pMemPool[TotalSize];
        if ( v8 >= search.elem )
        {
          CSosOperator::ResolveInputValues(
            this: this->m_vStack.m_Memory.m_pMemory[v8],
            pStructMem: &m_pMemPool[TotalSize],
            pStackMem: (char *)this->m_pMemPool);
          if ( *v10 <= 0.0 || *((_BYTE *)v10 + 8) != 0 && *((_BYTE *)v10 + 9) != 0 )
          {
            if ( snd_sos_show_operator_updates.m_pParent != nullptr
              && snd_sos_show_operator_updates.m_pParent->m_Value.m_nValue != 0 )
            {
              v12 = this->m_vStack.m_Memory.m_pMemory[v8];
              v12->Print(this: v12, a2: v10, a3: this, a4: v8, a5: 1);
            }
          }
          else
          {
            v11 = this->m_vStack.m_Memory.m_pMemory[v8];
            v11->Execute(this: v11, a2: v10, a3: pChannel, a4: pScratchPad, a5: this, a6: v8);
            *((_BYTE *)v10 + 9) = 1;
          }
          if ( v10 == pStopMemBlock )
            break;
        }
        v13 = this->m_vStack.m_Memory.m_pMemory[v8];
        TotalSize += v13->GetSize(this: v13);
      }
      return;
    }
  }
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
    _LoggingSystem_Log(
      a1: LOG_SND_OPERATORS,
      a2: 1,
      a3: "Error: Execute iterator unable to find sound operator %s\n",
      pOperatorName);
}

//------------------------------------------------------------------------------
// Address: 0x10051410
// Name: public: CSosOperatorStackCollection::CSosOperatorStackCollection(void)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorStackCollection *__thiscall CSosOperatorStackCollection::CSosOperatorStackCollection(
        CSosOperatorStackCollection *this)
{
  CSosOperatorStackCollection *result; // eax

  result = this;
  this->m_vAllStacks.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_vAllStacks.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_vAllStacks.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_vAllStacks.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_vAllStacks.m_Elements.m_Tree.m_Root = -1;
  this->m_vAllStacks.m_Elements.m_Tree.m_NumElements = 0;
  this->m_vAllStacks.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_vAllStacks.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_vAllStacks.m_Elements.m_Tree.m_pElements = this->m_vAllStacks.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( this->m_vAllStacks.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_vAllStacks.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  this->m_vUpdateStacks.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_vUpdateStacks.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_vUpdateStacks.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_vUpdateStacks.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_vUpdateStacks.m_Elements.m_Tree.m_Root = -1;
  this->m_vUpdateStacks.m_Elements.m_Tree.m_NumElements = 0;
  this->m_vUpdateStacks.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_vUpdateStacks.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_vUpdateStacks.m_Elements.m_Tree.m_pElements = this->m_vUpdateStacks.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( this->m_vUpdateStacks.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_vUpdateStacks.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  this->m_vStartStacks.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_vStartStacks.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_vStartStacks.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_vStartStacks.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_vStartStacks.m_Elements.m_Tree.m_Root = -1;
  this->m_vStartStacks.m_Elements.m_Tree.m_NumElements = 0;
  this->m_vStartStacks.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_vStartStacks.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_vStartStacks.m_Elements.m_Tree.m_pElements = this->m_vStartStacks.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( this->m_vStartStacks.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_vStartStacks.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  this->m_vStopStacks.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_vStopStacks.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_vStopStacks.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_vStopStacks.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_vStopStacks.m_Elements.m_Tree.m_Root = -1;
  this->m_vStopStacks.m_Elements.m_Tree.m_NumElements = 0;
  this->m_vStopStacks.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_vStopStacks.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_vStopStacks.m_Elements.m_Tree.m_pElements = this->m_vStopStacks.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( this->m_vStopStacks.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_vStopStacks.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  this->m_vCueStacks.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_vCueStacks.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_vCueStacks.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_vCueStacks.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_vCueStacks.m_Elements.m_Tree.m_Root = -1;
  this->m_vCueStacks.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_vCueStacks.m_Elements.m_Tree.m_NumElements = 0;
  this->m_vCueStacks.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_vCueStacks.m_Elements.m_Tree.m_pElements = this->m_vCueStacks.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( this->m_vCueStacks.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_vCueStacks.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10051590
// Name: public: CSosOperatorStack::CSosOperatorStack(enum CSosOperatorStack::SOSType_t)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorStack *__thiscall CSosOperatorStack::CSosOperatorStack(
        CSosOperatorStack *this,
        CSosOperatorStack::SOSType_t SosType)
{
  CSosOperatorStack *result; // eax

  result = this;
  this->m_vStack.m_Memory.m_pMemory = nullptr;
  this->m_vStack.m_Memory.m_nAllocationCount = 0;
  this->m_vStack.m_Memory.m_nGrowSize = 0;
  this->m_vStack.m_Size = 0;
  this->m_vStack.m_pElements = nullptr;
  this->m_vOperatorMap.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_vOperatorMap.m_Elements.m_Tree.m_Root = -1;
  this->m_vOperatorMap.m_Elements.m_Tree.m_NumElements = 0;
  this->m_vOperatorMap.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_vOperatorMap.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_vOperatorMap.m_Elements.m_Tree.m_pElements = this->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( this->m_vOperatorMap.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_vOperatorMap.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  this->m_SOSType = SosType;
  this->m_pMemPool = nullptr;
  this->m_nMemSize = 0;
  this->m_nChannelGuid = -1;
  this->m_flStartTime = -1.0;
  this->m_nScriptHandle = -1;
  this->m_stopType = SOS_STOP_NONE;
  this->m_flStopTime = -1.0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10051620
// Name: public: CSosOperatorStack::~CSosOperatorStack(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorStack::~CSosOperatorStack(CSosOperatorStack *this)
{
  void *m_pMemPool; // eax

  m_pMemPool = this->m_pMemPool;
  if ( m_pMemPool != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemPool);
  CUtlDict<int,int>::RemoveAll(this: &this->m_vOperatorMap);
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>(this: &this->m_vOperatorMap.m_Elements.m_Tree);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_vStack);
}

//------------------------------------------------------------------------------
// Address: 0x10051D60
// Name: public: void CSosOperatorStack::AddToTail(class CSosOperator __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorStack::AddToTail(CSosOperatorStack *this, CSosOperator *pOperator, char *pName)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CSosOperator **m_pMemory; // ecx
  int v7; // eax
  CSosOperator **v8; // eax

  m_nAllocationCount = this->m_vStack.m_Memory.m_nAllocationCount;
  m_Size = this->m_vStack.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<INetMessage *,int>::Grow(
      this: (CUtlMemory<S3RGBA,int> *)&this->m_vStack,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_vStack.m_Size;
  m_pMemory = this->m_vStack.m_Memory.m_pMemory;
  v7 = this->m_vStack.m_Size - m_Size - 1;
  this->m_vStack.m_pElements = m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
  v8 = &this->m_vStack.m_Memory.m_pMemory[m_Size];
  if ( v8 != nullptr )
    *v8 = pOperator;
  pOperator = (CSosOperator *)m_Size;
  CUtlDict<int,int>::Insert(this: &this->m_vOperatorMap, pName, element: (const int *)&pOperator);
}

//------------------------------------------------------------------------------
// Address: 0x10051DE0
// Name: public: void CSosOperatorStack::Copy(class CSosOperatorStack __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorStack::Copy(CSosOperatorStack *this, CSosOperatorStack *pSrcStack, unsigned int nMemOffset)
{
  CSosOperatorStack *v3; // esi
  CSosOperatorStack *v4; // ebx
  char *m_pMemPool; // edx
  void *v6; // ecx
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> > *p_m_Tree; // edi
  CSosOperator *v8; // edx
  const char *key; // esi
  int v10; // eax
  int m_nAllocationCount; // eax
  CUtlMemory<S3RGBA,int> *p_m_vStack; // esi
  int m_Size; // ebx
  S3RGBA *m_pMemory; // ecx
  int v15; // eax
  CSosOperator **v16; // eax
  const char *v17; // esi
  const char *v18; // eax
  const char *v19; // ecx
  int v20; // esi
  char v21; // dl
  int v22; // eax
  const char *v23; // edx
  int v24; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v25; // ecx
  int v26; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v27; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int> *v28; // eax
  CUtlMap<char const *,int,int>::Node_t *p_m_Data; // esi
  unsigned int v30; // ebx
  CSosOperator *v31; // esi
  int v32; // eax
  unsigned int m_nMemSize; // [esp-4h] [ebp-38h]
  CUtlMap<char const *,int,int>::Node_t search; // [esp+8h] [ebp-2Ch] BYREF
  CUtlMap<char const *,int,int>::Node_t insert; // [esp+10h] [ebp-24h] BYREF
  unsigned int nTotalOffset; // [esp+18h] [ebp-1Ch]
  CSosOperator *pOperator; // [esp+1Ch] [ebp-18h]
  CSosOperatorStack *v38; // [esp+20h] [ebp-14h]
  const char *pName; // [esp+24h] [ebp-10h] BYREF
  unsigned int v40; // [esp+28h] [ebp-Ch]
  int i; // [esp+2Ch] [ebp-8h]
  bool leftchild; // [esp+33h] [ebp-1h] BYREF

  v3 = pSrcStack;
  v4 = this;
  m_pMemPool = (char *)this->m_pMemPool;
  v6 = pSrcStack->m_pMemPool;
  m_nMemSize = pSrcStack->m_nMemSize;
  v38 = v4;
  _V_memcpy(dest: &m_pMemPool[nMemOffset], src: v6, count: m_nMemSize);
  nTotalOffset = 0;
  i = 0;
  if ( pSrcStack->m_vStack.m_Size > 0 )
  {
    p_m_Tree = &v4->m_vOperatorMap.m_Elements.m_Tree;
    v40 = 0;
    while ( 1 )
    {
      v8 = v3->m_vStack.m_Memory.m_pMemory[i];
      key = v3->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_pMemory[v40 / 0x18].m_Data.key;
      pOperator = v8;
      pName = key;
      if ( key != nullptr )
      {
        search.key = key;
        v10 = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Find(
                this: p_m_Tree,
                &search);
        if ( v10 >= 0 && v10 < p_m_Tree->m_Elements.m_nAllocationCount && v10 <= p_m_Tree->m_LastAlloc.index )
        {
          if ( (`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_104433A8 = -1;
            dword_104433AC = -1;
            dword_104433B0 = 1;
          }
          if ( p_m_Tree->m_Elements.m_pMemory[v10].m_Left != v10
            && (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
          {
            _LoggingSystem_Log(
              a1: LOG_SND_OPERATORS,
              a2: 1,
              a3: "Error: Importing operator with same name as existing operator: %s\n",
              key);
          }
        }
      }
      m_nAllocationCount = v4->m_vStack.m_Memory.m_nAllocationCount;
      p_m_vStack = (CUtlMemory<S3RGBA,int> *)&v4->m_vStack;
      m_Size = v4->m_vStack.m_Size;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<INetMessage *,int>::Grow(this: p_m_vStack, num: m_Size - m_nAllocationCount + 1);
      ++p_m_vStack[1].m_pMemory;
      m_pMemory = p_m_vStack->m_pMemory;
      v15 = (int)p_m_vStack[1].m_pMemory - m_Size - 1;
      p_m_vStack[1].m_nAllocationCount = (int)p_m_vStack->m_pMemory;
      if ( v15 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v15);
      v16 = (CSosOperator **)&p_m_vStack->m_pMemory[m_Size];
      if ( v16 != nullptr )
        *v16 = pOperator;
      v17 = pName;
      if ( pName != nullptr
        && (v18 = (const char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
      {
        v19 = v17;
        v20 = v18 - pName;
        do
        {
          v21 = *v19;
          v19[v20] = *v19;
          ++v19;
        }
        while ( v21 != 0 );
      }
      else
      {
        v18 = nullptr;
      }
      insert.key = v18;
      insert.elem = m_Size;
      pName = (const char *)-1;
      leftchild = false;
      CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::FindInsertionPosition(
        this: p_m_Tree,
        &insert,
        parent: (int *)&pName,
        &leftchild);
      v22 = CUtlRBTree<CDmxSerializationDictionary::DmxElementInfo_t,int,bool (__cdecl *)(CDmxSerializationDictionary::DmxElementInfo_t const &,CDmxSerializationDictionary::DmxElementInfo_t const &),CUtlMemory<UtlRBTreeNode_t<CDmxSerializationDictionary::DmxElementInfo_t,int>,int>>::NewNode(this: (CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *)p_m_Tree);
      v23 = pName;
      v24 = v22;
      v25 = &p_m_Tree->m_Elements.m_pMemory[v22];
      v25->m_Parent = (int)pName;
      v25->m_Right = -1;
      v25->m_Left = -1;
      v25->m_Tag = 0;
      if ( v23 == (const char *)-1 )
      {
        p_m_Tree->m_Root = v22;
      }
      else
      {
        v26 = (int)v23;
        v27 = p_m_Tree->m_Elements.m_pMemory;
        if ( leftchild )
          v27[v26].m_Left = v22;
        else
          v27[v26].m_Right = v22;
      }
      CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::InsertRebalance(
        this: p_m_Tree,
        elem: v22);
      v28 = p_m_Tree->m_Elements.m_pMemory;
      ++p_m_Tree->m_NumElements;
      p_m_Data = &v28[v24].m_Data;
      if ( p_m_Data != nullptr )
        *p_m_Data = insert;
      v30 = nTotalOffset;
      v31 = pOperator;
      CSosOperator::OffsetConnections(
        this: pOperator,
        pVoidMem: (char *)v38->m_pMemPool + nTotalOffset + nMemOffset,
        nOffset: nMemOffset);
      v32 = v31->GetSize(this: v31);
      v40 += 24;
      nTotalOffset = v32 + v30;
      if ( ++i >= pSrcStack->m_vStack.m_Size )
        break;
      v4 = v38;
      v3 = pSrcStack;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10052060
// Name: public: CSosOperatorStackList::~CSosOperatorStackList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorStackList::~CSosOperatorStackList(CSosOperatorStackList *this)
{
  CSosOperatorStack *m_vCueStack; // ecx
  CSosOperatorStack *v3; // edi
  CSosOperatorStack *m_vUpdateStack; // edi
  CSosOperatorStack *m_vStopStack; // ecx
  CSosOperatorStack *v6; // esi

  m_vCueStack = this->m_vCueStack;
  if ( m_vCueStack != nullptr )
  {
    CSosOperatorStack::Shutdown(this: m_vCueStack);
    v3 = this->m_vCueStack;
    if ( v3 != nullptr )
    {
      if ( v3->m_pMemPool != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_pMemPool);
      CUtlDict<int,int>::RemoveAll(this: &v3->m_vOperatorMap);
      CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>(this: &v3->m_vOperatorMap.m_Elements.m_Tree);
      CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v3->m_vStack);
      free(pMem: v3);
    }
  }
  if ( this->m_vUpdateStack != nullptr )
  {
    CSosOperatorStack::Shutdown(this: this->m_vUpdateStack);
    m_vUpdateStack = this->m_vUpdateStack;
    if ( this->m_vUpdateStack != nullptr )
    {
      if ( m_vUpdateStack->m_pMemPool != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_vUpdateStack->m_pMemPool);
      CUtlDict<int,int>::RemoveAll(this: &m_vUpdateStack->m_vOperatorMap);
      CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>(this: &m_vUpdateStack->m_vOperatorMap.m_Elements.m_Tree);
      CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&m_vUpdateStack->m_vStack);
      free(pMem: m_vUpdateStack);
    }
  }
  m_vStopStack = this->m_vStopStack;
  if ( m_vStopStack != nullptr )
  {
    CSosOperatorStack::Shutdown(this: m_vStopStack);
    v6 = this->m_vStopStack;
    if ( v6 != nullptr )
    {
      if ( v6->m_pMemPool != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6->m_pMemPool);
      CUtlDict<int,int>::RemoveAll(this: &v6->m_vOperatorMap);
      CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>(this: &v6->m_vOperatorMap.m_Elements.m_Tree);
      CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v6->m_vStack);
      free(pMem: v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10052150
// Name: public: CSosOperatorStackCollection::~CSosOperatorStackCollection(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorStackCollection::~CSosOperatorStackCollection(CSosOperatorStackCollection *this)
{
  CSosOperatorStackCollection::Clear(this);
  CUtlDict<CSosOperatorStack *,int>::RemoveAll(this: &this->m_vCueStacks);
  CUtlRBTree<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int,CUtlMap<char const *,CSosOperatorStack *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int,CUtlMap<char const *,CSosOperatorStack *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int>,int>>(this: &this->m_vCueStacks.m_Elements.m_Tree);
  CUtlDict<CSosOperatorStack *,int>::RemoveAll(this: &this->m_vStopStacks);
  CUtlRBTree<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int,CUtlMap<char const *,CSosOperatorStack *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int,CUtlMap<char const *,CSosOperatorStack *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int>,int>>(this: &this->m_vStopStacks.m_Elements.m_Tree);
  CUtlDict<CSosOperatorStack *,int>::RemoveAll(this: &this->m_vStartStacks);
  CUtlRBTree<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int,CUtlMap<char const *,CSosOperatorStack *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int,CUtlMap<char const *,CSosOperatorStack *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int>,int>>(this: &this->m_vStartStacks.m_Elements.m_Tree);
  CUtlDict<CSosOperatorStack *,int>::RemoveAll(this: &this->m_vUpdateStacks);
  CUtlRBTree<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int,CUtlMap<char const *,CSosOperatorStack *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int,CUtlMap<char const *,CSosOperatorStack *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int>,int>>(this: &this->m_vUpdateStacks.m_Elements.m_Tree);
  CUtlDict<CSosOperatorStack *,int>::RemoveAll(this: &this->m_vAllStacks);
  CUtlRBTree<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int,CUtlMap<char const *,CSosOperatorStack *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int,CUtlMap<char const *,CSosOperatorStack *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int>,int>>(this: &this->m_vAllStacks.m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x100521B0
// Name: public: CSosOperatorSystem::CSosOperatorSystem(void)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorSystem *__thiscall CSosOperatorSystem::CSosOperatorSystem(CSosOperatorSystem *this)
{
  CSosOperatorStackCollection::CSosOperatorStackCollection(this: &this->m_MasterStackCollection);
  this->m_vOperatorCollection.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_vOperatorCollection.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_vOperatorCollection.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_vOperatorCollection.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_vOperatorCollection.m_Elements.m_Tree.m_Root = -1;
  this->m_vOperatorCollection.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_vOperatorCollection.m_Elements.m_Tree.m_NumElements = 0;
  this->m_vOperatorCollection.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_vOperatorCollection.m_Elements.m_Tree.m_pElements = this->m_vOperatorCollection.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( this->m_vOperatorCollection.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_vOperatorCollection.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  CSosEntryMatchList::CSosEntryMatchList(this: &this->m_sosEntryBlockList);
  CTSQueue<StartSoundParams_t,0,1>::CTSQueue<StartSoundParams_t,0,1>(this: &this->m_sosStartEntryQueue);
  CTSQueue<int,0,1>::CTSQueue<int,0,1>(this: &this->m_sosStopChannelQueue);
  this->m_bHasInitialized = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10052240
// Name: public: CSosOperatorSystem::~CSosOperatorSystem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorSystem::~CSosOperatorSystem(CSosOperatorSystem *this)
{
  void **m_vEntryMatchList; // esi
  int i; // ebx

  CTSQueue<int,0,1>::Purge(this: &this->m_sosStopChannelQueue);
  free(pMem: this->m_sosStopChannelQueue.m_Head.value.pNode);
  CTSListBase::Detach(this: &this->m_sosStopChannelQueue.m_FreeNodes);
  CTSQueue<StartSoundParams_t,0,1>::Purge(this: &this->m_sosStartEntryQueue);
  free(pMem: this->m_sosStartEntryQueue.m_Head.value.pNode);
  CTSListBase::Detach(this: &this->m_sosStartEntryQueue.m_FreeNodes);
  m_vEntryMatchList = (void **)this->m_sosEntryBlockList.m_vEntryMatchList;
  for ( i = 32; i != 0; --i )
  {
    free(pMem: *m_vEntryMatchList);
    *m_vEntryMatchList++ = nullptr;
  }
  CUtlDict<CSosOperator *,int>::RemoveAll(this: &this->m_vOperatorCollection);
  CUtlRBTree<CUtlMap<char const *,CSosOperator *,int>::Node_t,int,CUtlMap<char const *,CSosOperator *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperator *,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CSosOperator *,int>::Node_t,int,CUtlMap<char const *,CSosOperator *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperator *,int>::Node_t,int>,int>>(this: &this->m_vOperatorCollection.m_Elements.m_Tree);
  CSosOperatorStackCollection::~CSosOperatorStackCollection(this: &this->m_MasterStackCollection);
}

//------------------------------------------------------------------------------
// Address: 0x100522E0
// Name: public: static class CSosOperatorSystem __near * CSosOperatorSystem::GetSoundOperatorSystem(void)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorSystem *__cdecl CSosOperatorSystem::GetSoundOperatorSystem()
{
  if ( (_S1_2 & 1) == 0 )
  {
    _S1_2 |= 1u;
    CSosOperatorSystem::CSosOperatorSystem(this: &s_SoundOperatorSystem);
    atexit(func: CSosOperatorSystem::GetSoundOperatorSystem_::_2_::_dynamic_atexit_destructor_for__s_SoundOperatorSystem__);
  }
  return &s_SoundOperatorSystem;
}

//------------------------------------------------------------------------------
// Address: 0x10052310
// Name: public: void CSosOperatorStack::ParseKV(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorStack::ParseKV(CSosOperatorStack *this, KeyValues *pOperatorsKV)
{
  KeyValues *FirstSubKey; // edi
  const char *Name; // ebx
  const char *String; // esi
  int v5; // eax
  CUtlDict<int,int> *p_m_vOperatorMap; // edi
  int v7; // esi
  int v8; // eax
  int v9; // eax
  CSosOperatorStack *v10; // esi
  CSosOperator *Operator; // eax
  int v12; // esi
  CSosOperator *v13; // esi
  char *v14; // eax
  int v15; // eax
  CSosOperatorStack *v16; // edi
  unsigned int v17; // ebx
  KeyValues *v18; // ebx
  char *v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // esi
  CSosOperatorStack *elem; // esi
  int v24; // ebx
  unsigned int v25; // esi
  void *v26; // eax
  CSosOperatorStack *v27; // ecx
  int Inorder; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,CSosOperator *,int>::Node_t,int> *m_pMemory; // edi
  CUtlDict<CSosOperator *,int> testDict; // [esp+8h] [ebp-64h] BYREF
  CUtlMap<char const *,CSosOperatorStack *,int>::Node_t v31; // [esp+2Ch] [ebp-40h] BYREF
  CUtlMap<char const *,CSosOperator *,int>::Node_t v32; // [esp+34h] [ebp-38h] BYREF
  CUtlMap<char const *,int,int>::Node_t v33; // [esp+3Ch] [ebp-30h] BYREF
  CUtlMap<char const *,int,int>::Node_t v34; // [esp+44h] [ebp-28h] BYREF
  CUtlMap<char const *,CSosOperator *,int>::Node_t search; // [esp+4Ch] [ebp-20h] BYREF
  void *pStructMem; // [esp+54h] [ebp-18h] BYREF
  const char *pOpType; // [esp+58h] [ebp-14h] BYREF
  int i; // [esp+5Ch] [ebp-10h]
  KeyValues *pOperator; // [esp+60h] [ebp-Ch]
  CSosOperatorStack *v40; // [esp+64h] [ebp-8h]
  unsigned int TotalSize; // [esp+68h] [ebp-4h]

  v40 = this;
  TotalSize = 0;
  FirstSubKey = KeyValues::GetFirstSubKey(this: pOperatorsKV);
  pOperator = FirstSubKey;
  memset(&testDict.m_Elements.m_Tree.m_Elements, 0, sizeof(testDict.m_Elements.m_Tree.m_Elements));
  testDict.m_Elements.m_Tree.m_Root = -1;
  testDict.m_Elements.m_Tree.m_NumElements = 0;
  testDict.m_Elements.m_Tree.m_FirstFree = -1;
  testDict.m_Elements.m_Tree.m_LastAlloc.index = -1;
  testDict.m_Elements.m_Tree.m_pElements = nullptr;
  testDict.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  i = 0;
  do
  {
    while ( FirstSubKey != nullptr )
    {
      Name = KeyValues::GetName(this: FirstSubKey);
      String = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: defaultValue);
      if ( KeyValues::GetFirstSubKey(this: FirstSubKey) == nullptr )
      {
        if ( Name != nullptr
          && *Name != 0
          && _V_stricmp(s1: Name, s2: "import_stack") == 0
          && String != nullptr
          && *String != 0 )
        {
          if ( (_S1_2 & 1) == 0 )
          {
            _S1_2 |= 1u;
            CSosOperatorSystem::CSosOperatorSystem(this: &s_SoundOperatorSystem);
            atexit(func: CSosOperatorSystem::GetSoundOperatorSystem_::_2_::_dynamic_atexit_destructor_for__s_SoundOperatorSystem__);
          }
          v31.key = String;
          v21 = CUtlRBTree<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int,CUtlMap<char const *,CSosOperatorStack *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int>,int>>::Find(
                  this: &s_SoundOperatorSystem.m_MasterStackCollection.m_vAllStacks.m_Elements.m_Tree,
                  search: &v31);
          v22 = v21;
          if ( v21 >= 0
            && v21 < s_SoundOperatorSystem.m_MasterStackCollection.m_vAllStacks.m_Elements.m_Tree.m_Elements.m_nAllocationCount
            && v21 <= s_SoundOperatorSystem.m_MasterStackCollection.m_vAllStacks.m_Elements.m_Tree.m_LastAlloc.index
            && CUtlRBTree<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int,CUtlMap<char const *,CSosOperatorStack *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperatorStack *,int>::Node_t,int>,int>>::LeftChild(
                 this: &s_SoundOperatorSystem.m_MasterStackCollection.m_vAllStacks.m_Elements.m_Tree,
                 i: v21) != v21 )
          {
            elem = s_SoundOperatorSystem.m_MasterStackCollection.m_vAllStacks.m_Elements.m_Tree.m_Elements.m_pMemory[v22].m_Data.elem;
            if ( elem != nullptr )
            {
              if ( i == 1 )
                CSosOperatorStack::Copy(this: v40, pSrcStack: elem, nMemOffset: TotalSize);
              TotalSize += elem->m_nMemSize;
            }
          }
        }
        goto LABEL_69;
      }
      pOpType = KeyValues::GetString(this: FirstSubKey, keyName: "operator", defaultValue: "math_float");
      if ( Name != nullptr )
      {
        search.key = Name;
        v5 = CUtlRBTree<CUtlMap<char const *,CSosOperator *,int>::Node_t,int,CUtlMap<char const *,CSosOperator *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperator *,int>::Node_t,int>,int>>::Find(
               this: &testDict.m_Elements.m_Tree,
               &search);
        p_m_vOperatorMap = &v40->m_vOperatorMap;
        v7 = v5;
        v34.key = Name;
        v8 = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Find(
               this: &v40->m_vOperatorMap.m_Elements.m_Tree,
               search: &v34);
        if ( v7 >= 0
          && v7 < testDict.m_Elements.m_Tree.m_Elements.m_nAllocationCount
          && v7 <= testDict.m_Elements.m_Tree.m_LastAlloc.index )
        {
          if ( (`CUtlRBTree<CUtlMap<char const *,CSosOperator *,int>::Node_t,int,CUtlMap<char const *,CSosOperator *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperator *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,CSosOperator *,int>::Node_t,int,CUtlMap<char const *,CSosOperator *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperator *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<char const *,CSosOperator *,int>::Node_t,int,CUtlMap<char const *,CSosOperator *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperator *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_104BF878 = -1;
            dword_104BF87C = -1;
            dword_104BF880 = 1;
          }
          if ( testDict.m_Elements.m_Tree.m_Elements.m_pMemory[v7].m_Left != v7 && i == 0 )
            goto LABEL_21;
        }
      }
      else
      {
        v8 = -1;
      }
      p_m_vOperatorMap = &v40->m_vOperatorMap;
      if ( v8 < 0
        || v8 >= v40->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_nAllocationCount
        || v8 > v40->m_vOperatorMap.m_Elements.m_Tree.m_LastAlloc.index )
      {
        goto LABEL_33;
      }
      if ( (`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_104433A8 = -1;
        dword_104433AC = -1;
        dword_104433B0 = 1;
      }
      if ( v40->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_pMemory[v8].m_Left == v8 )
      {
LABEL_33:
        if ( pOpType != nullptr && *pOpType != 0 )
        {
          if ( (_S1_2 & 1) == 0 )
          {
            _S1_2 |= 1u;
            CSosOperatorSystem::CSosOperatorSystem(this: &s_SoundOperatorSystem);
            atexit(func: CSosOperatorSystem::GetSoundOperatorSystem_::_2_::_dynamic_atexit_destructor_for__s_SoundOperatorSystem__);
          }
          v32.key = pOpType;
          v12 = CUtlRBTree<CUtlMap<char const *,CSosOperator *,int>::Node_t,int,CUtlMap<char const *,CSosOperator *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperator *,int>::Node_t,int>,int>>::Find(
                  this: &s_SoundOperatorSystem.m_vOperatorCollection.m_Elements.m_Tree,
                  search: &v32);
          if ( (_S1_2 & 1) == 0 )
          {
            _S1_2 |= 1u;
            CSosOperatorSystem::CSosOperatorSystem(this: &s_SoundOperatorSystem);
            atexit(func: CSosOperatorSystem::GetSoundOperatorSystem_::_2_::_dynamic_atexit_destructor_for__s_SoundOperatorSystem__);
          }
          if ( v12 < 0
            || v12 >= s_SoundOperatorSystem.m_vOperatorCollection.m_Elements.m_Tree.m_Elements.m_nAllocationCount
            || v12 > s_SoundOperatorSystem.m_vOperatorCollection.m_Elements.m_Tree.m_LastAlloc.index )
          {
            goto LABEL_49;
          }
          if ( (`CUtlRBTree<CUtlMap<char const *,CSosOperator *,int>::Node_t,int,CUtlMap<char const *,CSosOperator *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperator *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,CSosOperator *,int>::Node_t,int,CUtlMap<char const *,CSosOperator *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperator *,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<char const *,CSosOperator *,int>::Node_t,int,CUtlMap<char const *,CSosOperator *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperator *,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_104BF878 = -1;
            dword_104BF87C = -1;
            dword_104BF880 = 1;
          }
          if ( s_SoundOperatorSystem.m_vOperatorCollection.m_Elements.m_Tree.m_Elements.m_pMemory[v12].m_Left == v12 )
          {
LABEL_49:
            if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
              _LoggingSystem_Log(
                a1: LOG_SND_OPERATORS,
                a2: 1,
                a3: "Error: Operator: %s : Unknown sound operator type %s\n",
                Name,
                pOpType);
          }
          else
          {
            if ( (_S1_2 & 1) == 0 )
            {
              _S1_2 |= 1u;
              CSosOperatorSystem::CSosOperatorSystem(this: &s_SoundOperatorSystem);
              atexit(func: CSosOperatorSystem::GetSoundOperatorSystem_::_2_::_dynamic_atexit_destructor_for__s_SoundOperatorSystem__);
            }
            v13 = s_SoundOperatorSystem.m_vOperatorCollection.m_Elements.m_Tree.m_Elements.m_pMemory[v12].m_Data.elem;
            pOpType = (const char *)v13;
            if ( v13 != nullptr )
            {
              if ( i != 0 )
              {
                if ( i == 1 )
                {
                  v16 = v40;
                  v17 = TotalSize;
                  CSosOperator::SetBaseDefaults(this: v13, pVoidMem: (char *)v40->m_pMemPool + TotalSize);
                  v13->SetDefaults(this: v13, a2: (char *)v16->m_pMemPool + v17);
                  v18 = pOperator;
                  v13->ParseKV(this: v13, a2: v16, a3: (char *)v16->m_pMemPool + TotalSize, a4: pOperator);
                  v19 = (char *)KeyValues::GetName(this: v18);
                  CSosOperatorStack::AddToTail(this: v16, pOperator: v13, pName: v19);
                }
                v20 = v13->GetSize(this: v13);
                TotalSize += v20;
              }
              else
              {
                v14 = (char *)KeyValues::GetName(this: pOperator);
                CUtlDict<CSosOperator *,int>::Insert(
                  this: &testDict,
                  pName: v14,
                  element: (CSosOperator *const *)&pOpType);
                v15 = v13->GetSize(this: v13);
                TotalSize += v15;
              }
            }
          }
        }
        goto LABEL_69;
      }
LABEL_21:
      if ( i == 1 )
      {
        if ( Name != nullptr )
        {
          v33.key = Name;
          v9 = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Find(
                 this: &p_m_vOperatorMap->m_Elements.m_Tree,
                 search: &v33);
        }
        else
        {
          v9 = -1;
        }
        if ( v9 >= 0
          && v9 < p_m_vOperatorMap->m_Elements.m_Tree.m_Elements.m_nAllocationCount
          && v9 <= p_m_vOperatorMap->m_Elements.m_Tree.m_LastAlloc.index )
        {
          if ( (`CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_104433A8 = -1;
            dword_104433AC = -1;
            dword_104433B0 = 1;
          }
          if ( p_m_vOperatorMap->m_Elements.m_Tree.m_Elements.m_pMemory[v9].m_Left != v9 )
          {
            v10 = v40;
            Operator = CSosOperatorStack::FindOperator(this: v40, pName: Name, pStructHandle: &pStructMem);
            Operator->ParseKV(this: Operator, a2: v10, a3: pStructMem, a4: pOperator);
          }
        }
      }
LABEL_69:
      FirstSubKey = KeyValues::GetNextKey(this: pOperator);
      pOperator = FirstSubKey;
    }
    v24 = i;
    if ( i == 0 )
    {
      v25 = TotalSize;
      if ( TotalSize != 0 )
      {
        v26 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: TotalSize);
        v27 = v40;
        v40->m_pMemPool = v26;
        v27->m_nMemSize = v25;
      }
      TotalSize = 0;
      FirstSubKey = KeyValues::GetFirstSubKey(this: pOperatorsKV);
      pOperator = FirstSubKey;
    }
    i = v24 + 1;
  }
  while ( v24 + 1 < 2 );
  Inorder = CUtlRBTree<CUtlMap<char const *,CSosOperator *,int>::Node_t,int,CUtlMap<char const *,CSosOperator *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperator *,int>::Node_t,int>,int>>::FirstInorder(this: &testDict.m_Elements.m_Tree);
  if ( Inorder != -1 )
  {
    m_pMemory = testDict.m_Elements.m_Tree.m_Elements.m_pMemory;
    do
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)m_pMemory[Inorder].m_Data.key);
      Inorder = CUtlRBTree<CUtlMap<char const *,CSosOperator *,int>::Node_t,int,CUtlMap<char const *,CSosOperator *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperator *,int>::Node_t,int>,int>>::NextInorder(
                  this: &testDict.m_Elements.m_Tree,
                  i: Inorder);
    }
    while ( Inorder != -1 );
  }
  CUtlRBTree<CUtlMap<char const *,CSosOperator *,int>::Node_t,int,CUtlMap<char const *,CSosOperator *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperator *,int>::Node_t,int>,int>>::RemoveAll(this: &testDict.m_Elements.m_Tree);
  CUtlRBTree<CUtlMap<char const *,CSosOperator *,int>::Node_t,int,CUtlMap<char const *,CSosOperator *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSosOperator *,int>::Node_t,int>,int>>::RemoveAll(this: &testDict.m_Elements.m_Tree);
  if ( testDict.m_Elements.m_Tree.m_Elements.m_nGrowSize >= 0
    && testDict.m_Elements.m_Tree.m_Elements.m_pMemory != nullptr )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: testDict.m_Elements.m_Tree.m_Elements.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10052900
// Name: public: void CSosOperatorStackList::ParseKV(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorStackList::ParseKV(CSosOperatorStackList *this, KeyValues *pOperatorsKV)
{
  KeyValues *i; // ebx
  const char *Name; // eax
  const char *v4; // edi
  CSosOperatorStack::SOSType_t v5; // esi
  CSosOperatorStack *v6; // eax
  CSosOperatorStack *v7; // esi

  for ( i = KeyValues::GetFirstSubKey(this: pOperatorsKV); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    Name = KeyValues::GetName(this: i);
    v4 = Name;
    if ( Name == nullptr || *Name == 0 )
      continue;
    if ( _V_strcmp(s1: Name, s2: "update_stack") != 0 )
    {
      if ( _V_strcmp(s1: v4, s2: "start_stack") == 0 )
        continue;
      if ( _V_strcmp(s1: v4, s2: "stop_stack") != 0 )
      {
        if ( _V_strcmp(s1: v4, s2: "cue_stack") != 0 )
        {
          if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
            _LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: 1, a3: "Error: Unknown sound operator stack type: %s\n", v4);
          continue;
        }
        v5 = SOS_CUE;
      }
      else
      {
        v5 = SOS_STOP;
      }
    }
    else
    {
      v5 = SOS_UPDATE;
    }
    v6 = (CSosOperatorStack *)MemAlloc_Alloc(nSize: 0x98u);
    if ( v6 != nullptr )
      v7 = CSosOperatorStack::CSosOperatorStack(this: v6, SosType: v5);
    else
      v7 = nullptr;
    _V_strcpy(dest: v7->m_nName, src: v4);
    switch ( v7->m_SOSType )
    {
      case SOS_UPDATE:
        this->m_vUpdateStack = v7;
LABEL_20:
        CSosOperatorStack::ParseKV(this: v7, pOperatorsKV: i);
        continue;
      case SOS_CUE:
        this->m_vCueStack = v7;
        CSosOperatorStack::ParseKV(this: v7, pOperatorsKV: i);
        break;
      case SOS_STOP:
        this->m_vStopStack = v7;
        CSosOperatorStack::ParseKV(this: v7, pOperatorsKV: i);
        break;
      default:
        goto LABEL_20;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10052A40
// Name: class CSosOperatorStack __near * S_GetStartStack(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorStack *__cdecl S_GetStartStack(KeyValues *pOperatorsKV)
{
  KeyValues *FirstSubKey; // edi
  const char *Name; // eax
  const char *v3; // esi
  CSosOperatorStack *v5; // eax
  CSosOperatorStack *v6; // eax
  CSosOperatorStack *v7; // ebx

  FirstSubKey = KeyValues::GetFirstSubKey(this: pOperatorsKV);
  if ( FirstSubKey == nullptr )
    return nullptr;
  while ( 1 )
  {
    Name = KeyValues::GetName(this: FirstSubKey);
    v3 = Name;
    if ( Name != nullptr && *Name != 0 && _V_strcmp(s1: Name, s2: "start_stack") == 0 )
      break;
    FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
    if ( FirstSubKey == nullptr )
      return nullptr;
  }
  v5 = (CSosOperatorStack *)MemAlloc_Alloc(nSize: 0x98u);
  if ( v5 == nullptr )
    return nullptr;
  v6 = CSosOperatorStack::CSosOperatorStack(this: v5, SosType: SOS_START);
  v7 = v6;
  if ( v6 != nullptr )
  {
    _V_strcpy(dest: v6->m_nName, src: v3);
    CSosOperatorStack::ParseKV(this: v7, pOperatorsKV: FirstSubKey);
    if ( snd_sos_show_operator_init.m_pParent != nullptr && snd_sos_show_operator_init.m_pParent->m_Value.m_nValue != 0 )
    {
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: 0) != 0 )
        LoggingSystem_Log(a1: LOG_SOUND_OPERATOR_SYSTEM, a2: LS_MESSAGE, a3: StackColor, a4: "\nSTART Operators:\n");
      CSosOperatorStack::Print(this: v7, nLevel: 1u);
    }
  }
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x10052B20
// Name: class CSosOperatorStackList __near * S_InitChannelOperators(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorStackList *__cdecl S_InitChannelOperators(KeyValues *pOperatorsKV)
{
  CSosOperatorStackList *result; // eax
  CSosOperatorStackList *v2; // eax
  CSosOperatorStackList *v3; // esi

  result = nullptr;
  if ( pOperatorsKV != nullptr )
  {
    v2 = (CSosOperatorStackList *)MemAlloc_Alloc(nSize: 0x18u);
    if ( v2 != nullptr )
    {
      v2->m_vUpdateStack = nullptr;
      v2->m_vStopStack = nullptr;
      v2->m_vCueStack = nullptr;
      v2->m_stopType = SOS_STOP_NONE;
      v2->m_flStopTime = -1.0;
      v3 = v2;
    }
    else
    {
      v3 = nullptr;
    }
    CSosOperatorStackList::ParseKV(this: v3, pOperatorsKV);
    if ( v3 != nullptr
      && snd_sos_show_operator_init.m_pParent != nullptr
      && snd_sos_show_operator_init.m_pParent->m_Value.m_nValue != 0 )
    {
      CSosOperatorStackList::Print(this: v3);
    }
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10052BA0
// Name: public: void CSosOperatorStackCollection::ParseKV(enum CSosOperatorStack::SOSType_t,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorStackCollection::ParseKV(
        CSosOperatorStackCollection *this,
        CSosOperatorStack::SOSType_t SosType,
        KeyValues *pStackType)
{
  KeyValues *FirstSubKey; // eax
  char *Name; // esi
  _DWORD *v5; // eax
  _DWORD *v6; // ebx
  CSosOperatorStackCollection *v7; // ebx
  int i; // edi
  int v9; // ecx
  void (__thiscall *Free_2)(IMemAlloc *, void *); // edx
  void *v11; // eax
  KeyValues *pStack; // [esp+4h] [ebp-8h]

  FirstSubKey = KeyValues::GetFirstSubKey(this: pStackType);
  pStack = FirstSubKey;
  if ( FirstSubKey != nullptr )
  {
    while ( 1 )
    {
      Name = (char *)KeyValues::GetName(this: FirstSubKey);
      v5 = MemAlloc_Alloc(nSize: 0x98u);
      if ( v5 != nullptr )
      {
        v5[19] = 0;
        v5[20] = 0;
        v5[21] = 0;
        v5[22] = 0;
        v5[23] = 0;
        v5[24] = 0;
        v5[25] = 0;
        v5[26] = 0;
        v5[27] = 0;
        v5[28] = -1;
        v5[29] = 0;
        v5[30] = -1;
        v5[31] = -1;
        v5[32] = v5[25];
        if ( v5[24] == 0 )
          v5[24] = CaselessStringLessThan;
        v5[16] = SosType;
        v5[17] = 0;
        v5[18] = 0;
        v5[33] = -1;
        v5[34] = -1082130432;
        *((_WORD *)v5 + 70) = -1;
        v5[36] = 0;
        v5[37] = -1082130432;
        v6 = v5;
      }
      else
      {
        v6 = nullptr;
      }
      pStackType = (KeyValues *)v6;
      _V_strcpy(dest: (char *)v6, src: Name);
      CSosOperatorStack::ParseKV(this: (CSosOperatorStack *)v6, pOperatorsKV: pStack);
      switch ( SosType )
      {
        case SOS_UPDATE:
          v7 = this;
          CUtlDict<CSosOperatorStack *,int>::Insert(
            this: &this->m_vUpdateStacks,
            pName: Name,
            element: (CSosOperatorStack *const *)&pStackType);
          goto LABEL_11;
        case SOS_CUE:
          v7 = this;
          CUtlDict<CSosOperatorStack *,int>::Insert(
            this: &this->m_vCueStacks,
            pName: Name,
            element: (CSosOperatorStack *const *)&pStackType);
LABEL_11:
          CUtlDict<CSosOperatorStack *,int>::Insert(
            this: &v7->m_vAllStacks,
            pName: Name,
            element: (CSosOperatorStack *const *)&pStackType);
          break;
        case SOS_START:
          CUtlDict<CSosOperatorStack *,int>::Insert(
            this: &this->m_vStartStacks,
            pName: Name,
            element: (CSosOperatorStack *const *)&pStackType);
          CUtlDict<CSosOperatorStack *,int>::Insert(
            this: &this->m_vAllStacks,
            pName: Name,
            element: (CSosOperatorStack *const *)&pStackType);
          break;
        case SOS_STOP:
          CUtlDict<CSosOperatorStack *,int>::Insert(
            this: &this->m_vStopStacks,
            pName: Name,
            element: (CSosOperatorStack *const *)&pStackType);
          CUtlDict<CSosOperatorStack *,int>::Insert(
            this: &this->m_vAllStacks,
            pName: Name,
            element: (CSosOperatorStack *const *)&pStackType);
          break;
        default:
          if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
            _LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: 1, a3: "Error: Unknown sound operator stack type");
          if ( v6 != nullptr )
          {
            if ( v6[17] != 0 )
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)v6[17]);
            for ( i = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::FirstInorder(this: (CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> > *)(v6 + 24));
                  i != -1;
                  i = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::NextInorder(
                        this: (CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> > *)(v6 + 24),
                        i) )
            {
              v9 = v6[25];
              Free_2 = _g_pMemAlloc->Free_2;
              pStackType = (KeyValues *)_g_pMemAlloc;
              Free_2(this: _g_pMemAlloc, a2: *(void **)(v9 + 24 * i + 16));
            }
            CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RemoveAll(this: (CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> > *)(v6 + 24));
            CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::RemoveAll(this: (CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int> > *)(v6 + 24));
            v6[30] = -1;
            if ( (int)v6[27] >= 0 )
            {
              if ( v6[25] != 0 )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)v6[25]);
                v6[25] = 0;
              }
              v6[26] = 0;
            }
            v6[31] = -1;
            if ( (int)v6[27] >= 0 )
            {
              if ( v6[25] != 0 )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)v6[25]);
                v6[25] = 0;
              }
              v6[26] = 0;
            }
            v6[22] = 0;
            if ( (int)v6[21] >= 0 )
            {
              if ( v6[19] != 0 )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)v6[19]);
                v6[19] = 0;
              }
              v6[20] = 0;
            }
            v11 = (void *)v6[19];
            v6[23] = v11;
            if ( (int)v6[21] >= 0 )
            {
              if ( v11 != nullptr )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v11);
                v6[19] = 0;
              }
              v6[20] = 0;
            }
            free(pMem: v6);
          }
          break;
      }
      pStack = KeyValues::GetNextKey(this: pStack);
      if ( pStack == nullptr )
        break;
      FirstSubKey = pStack;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10052E70
// Name: public: void CSosOperatorSystem::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorSystem::Init(CSosOperatorSystem *this)
{
  CSosOperatorSystem *v1; // esi
  bool v2; // zf
  KeyValues *v3; // eax
  KeyValues *NextKey; // ebx
  CSosOperatorStack::SOSType_t v5; // edi
  const char *Name; // eax
  const char *v7; // esi
  unsigned int crc; // [esp+4h] [ebp-Ch] BYREF
  CSosOperatorStackCollection *p_m_MasterStackCollection; // [esp+8h] [ebp-8h]
  KeyValues *pSoundOperatorStacksKV; // [esp+Ch] [ebp-4h]

  v1 = this;
  v2 = !this->m_bHasInitialized;
  p_m_MasterStackCollection = &this->m_MasterStackCollection;
  if ( v2 )
  {
    this->m_bHasInitialized = true;
    CRC32_Init(pulCRC: &crc);
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
    {
      NextKey = KeyValues::KeyValues(this: v3, setName: "scripts/sound_operator_stacks.txt");
      pSoundOperatorStacksKV = NextKey;
    }
    else
    {
      pSoundOperatorStacksKV = nullptr;
      NextKey = nullptr;
    }
    if ( g_pFullFileSystem->LoadKeyValues(
           this: g_pFullFileSystem,
           a2: NextKey,
           a3: TYPE_SOUNDOPERATORS,
           a4: "scripts/sound_operator_stacks.txt",
           a5: "GAME") )
    {
      if ( NextKey != nullptr )
      {
        while ( 1 )
        {
          v5 = SOS_NONE;
          Name = KeyValues::GetName(this: NextKey);
          v7 = Name;
          if ( Name != nullptr && *Name != 0 )
          {
            if ( _V_strcmp(s1: Name, s2: "update_stacks") != 0 )
            {
              if ( _V_strcmp(s1: v7, s2: "start_stacks") != 0 )
              {
                if ( _V_strcmp(s1: v7, s2: "stop_stacks") != 0 )
                {
                  if ( _V_strcmp(s1: v7, s2: "cue_stacks") != 0 )
                  {
                    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
                      _LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: 1, a3: "Unknown sound operator stack arg %s", v7);
                    goto LABEL_12;
                  }
                  v5 = SOS_CUE;
                }
                else
                {
                  v5 = SOS_STOP;
                }
              }
              else
              {
                v5 = SOS_START;
              }
            }
            else
            {
              v5 = SOS_UPDATE;
            }
          }
          CSosOperatorStackCollection::ParseKV(this: p_m_MasterStackCollection, SosType: v5, pStackType: NextKey);
          NextKey = KeyValues::GetNextKey(this: NextKey);
LABEL_12:
          if ( NextKey == nullptr )
          {
            v1 = (CSosOperatorSystem *)p_m_MasterStackCollection;
            NextKey = pSoundOperatorStacksKV;
            break;
          }
        }
      }
    }
    else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
    {
      _LoggingSystem_Log(
        a1: LOG_SND_OPERATORS,
        a2: 1,
        a3: "Warning: Unable to load sound operators file '%s'\n",
        "scripts/sound_operator_stacks.txt");
    }
    KeyValues::deleteThis(this: NextKey);
    CRC32_Final(pulCRC: &crc);
    if ( snd_sos_show_operator_init.m_pParent != nullptr && snd_sos_show_operator_init.m_pParent->m_Value.m_nValue != 0 )
      CSosOperatorStackCollection::Print(this: &v1->m_MasterStackCollection);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10053020
// Name: void S_SOSFlush(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl S_SOSFlush()
{
  if ( (_S1_2 & 1) == 0 )
  {
    _S1_2 |= 1u;
    CSosOperatorSystem::CSosOperatorSystem(this: &s_SoundOperatorSystem);
    atexit(func: CSosOperatorSystem::GetSoundOperatorSystem_::_2_::_dynamic_atexit_destructor_for__s_SoundOperatorSystem__);
  }
  CSosOperatorStackCollection::Clear(this: &s_SoundOperatorSystem.m_MasterStackCollection);
  s_SoundOperatorSystem.m_bHasInitialized = false;
  CSosOperatorSystem::Init(this: &s_SoundOperatorSystem);
}

//------------------------------------------------------------------------------
// Address: 0x1013E7F0
// Name: public: CTSQueue<int,0,1>::CTSQueue<int,0,1>(void)
// Source: json
//------------------------------------------------------------------------------
CTSQueue<int,0,1> *__thiscall CTSQueue<int,0,1>::CTSQueue<int,0,1>(CTSQueue<int,0,1> *this)
{
  CTSListBase *p_m_FreeNodes; // ebx
  CTSQueue<int,0,1>::Node_t *v3; // eax

  p_m_FreeNodes = &this->m_FreeNodes;
  this->m_Count.m_value = 0;
  if ( (((_BYTE)this + 24) & 7) != 0 )
  {
    _Error(a1: "CTSListBase: Misaligned list\n");
    __debugbreak();
  }
  p_m_FreeNodes->m_Head.value.Next = nullptr;
  p_m_FreeNodes->m_Head.value32.DepthAndSequence = 0;
  if ( ((unsigned __int8)this & 7) != 0 )
  {
    _Error(a1: "CTSQueue: Misaligned queue\n");
    __debugbreak();
    _Error(a1: "CTSQueue: Misaligned queue\n");
    __debugbreak();
  }
  _InterlockedExchange(&this->m_Count.m_value, 0);
  this->m_Tail.value.sequence = 0;
  this->m_Head.value.sequence = 0;
  v3 = (CTSQueue<int,0,1>::Node_t *)MemAlloc_Alloc(nSize: 8u);
  this->m_Tail.value.pNode = v3;
  this->m_Head.value.pNode = v3;
  v3->pNext = (CTSQueue<int,0,1>::Node_t *)this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1013F8B0
// Name: public: void CTSQueue<int,0,1>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTSQueue<int,0,1>::Purge(CTSQueue<int,0,1> *this)
{
  CTSQueue<int,0,1>::Node_t *i; // eax
  CTSListBase *p_m_FreeNodes; // edi
  TSLNodeBase_t *Next; // esi
  int DepthAndSequence; // eax

  for ( i = CTSQueue<loopback_t *,0,1>::Pop(this); i != nullptr; i = CTSQueue<loopback_t *,0,1>::Pop(this) )
    free(pMem: i);
  p_m_FreeNodes = &this->m_FreeNodes;
  while ( 1 )
  {
    Next = p_m_FreeNodes->m_Head.value.Next;
    DepthAndSequence = p_m_FreeNodes->m_Head.value32.DepthAndSequence;
    if ( p_m_FreeNodes->m_Head.value.Next == nullptr )
      break;
    while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                               a1: p_m_FreeNodes,
                               a2: Next->Next,
                               a3: DepthAndSequence - 1,
                               a4: Next,
                               a5: DepthAndSequence) == 0 )
    {
      _mm_pause();
      Next = p_m_FreeNodes->m_Head.value.Next;
      DepthAndSequence = p_m_FreeNodes->m_Head.value32.DepthAndSequence;
      if ( p_m_FreeNodes->m_Head.value.Next == nullptr )
        goto LABEL_7;
    }
    free(pMem: Next);
  }
LABEL_7:
  this->m_Head.value.sequence = 0;
  this->m_Tail.value.sequence = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10322190
// Name: _CSosOperatorSystem::GetSoundOperatorSystem_::_2_::_dynamic_atexit_destructor_for__s_SoundOperatorSystem__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CSosOperatorSystem::GetSoundOperatorSystem_::_2_::_dynamic_atexit_destructor_for__s_SoundOperatorSystem__()
{
  CSosOperatorSystem::~CSosOperatorSystem(this: &s_SoundOperatorSystem);
}

} // namespace engine_xlsp
