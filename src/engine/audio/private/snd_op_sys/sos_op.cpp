// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/audio/private/snd_op_sys/sos_op.cpp
// Functions: 11
// ============================================================

#include "engine\audio\private\snd_op_sys\sos_op.h"

//------------------------------------------------------------------------------
// Address: 0x10045960
// Name: Register_LOG_SND_OPERATORS_Tags
// Source: json
//------------------------------------------------------------------------------
int Register_LOG_SND_OPERATORS_Tags()
{
  _LoggingSystem_AddTagToCurrentChannel(a1: "SndOperators");
  return _LoggingSystem_AddTagToCurrentChannel(a1: "SND");
}

//------------------------------------------------------------------------------
// Address: 0x10045980
// Name: public: void CSosOperator::SetBaseDefaults(void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperator::SetBaseDefaults(CSosOperator *this, _DWORD *pVoidMem)
{
  *pVoidMem = 1065353216;
  pVoidMem[1] = -1;
  *((_WORD *)pVoidMem + 4) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100459D0
// Name: public: int CSosOperator::ParseValueRef(class CSosOperatorStack __near *,char const __near *,char const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSosOperator::ParseValueRef(
        CSosOperator *this,
        CSosOperatorStack *pStack,
        const char *pParamString,
        const char *pValueString)
{
  const char *v4; // edi
  const char *v5; // esi
  int OperatorOutputOffset; // edi
  const char *v8; // eax
  int v9; // eax
  char pDest[64]; // [esp+0h] [ebp-80h] BYREF
  char tempString[64]; // [esp+40h] [ebp-40h] BYREF

  if ( *pValueString != 64 )
    return -1;
  V_strncpy(pDest: tempString, pSrc: pValueString + 1, maxLen: 64);
  v4 = strtok(string: tempString, control: ".");
  v5 = strtok(string: nullptr, control: defaultValue);
  OperatorOutputOffset = CSosOperatorStack::GetOperatorOutputOffset(this: pStack, pOperatorName: v4, pOutputName: v5);
  if ( OperatorOutputOffset < 0 )
    return -1;
  V_strncpy(pDest, pSrc: v5, maxLen: 64);
  v8 = strtok(string: nullptr, control: "]");
  if ( v8 != nullptr && *v8 != 0 )
  {
    v9 = V_atoi(str: v8);
    if ( v9 > -1 )
      OperatorOutputOffset += v9;
  }
  return OperatorOutputOffset;
}

//------------------------------------------------------------------------------
// Address: 0x10045A80
// Name: public: void CSosOperator::PrintIO(struct CSosOperator_t __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperator::PrintIO(CSosOperator *this, CSosOperator_t *pStructMem, int nLevel)
{
  CSosOperator *v3; // ebx
  CSosOperator::InputData_t *v4; // esi
  const char *key; // edi
  Color *v6; // eax
  struct Color v7; // ebx
  const char *v8; // eax
  CSosOperator::OutputData_t *v9; // esi
  const char *v10; // edi
  char *v11; // ebx
  int i; // edi
  char *v13; // [esp+Ch] [ebp-1Ch]
  char *pInput; // [esp+14h] [ebp-14h]
  char *pInputa; // [esp+14h] [ebp-14h]
  int v17; // [esp+18h] [ebp-10h]
  int v18; // [esp+18h] [ebp-10h]
  int v19; // [esp+1Ch] [ebp-Ch]
  int v20; // [esp+1Ch] [ebp-Ch]
  int v21; // [esp+20h] [ebp-8h]
  char v22; // [esp+27h] [ebp-1h]

  v3 = this;
  if ( this->m_vInputs.m_Size > 0 )
  {
    v17 = 0;
    v19 = 0;
    pInput = (char *)this->m_vInputs.m_Size;
    do
    {
      v4 = &v3->m_vInputs.m_Memory.m_pMemory[v19];
      key = v3->m_vInputMap.m_Elements.m_Tree.m_Elements.m_pMemory[v17].m_Data.key;
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
        LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: LS_MESSAGE, a3: OpColor, a4: "%*s%s: ", nLevel, "    ", key);
      v22 = 0;
      v13 = (char *)pStructMem + v4->m_nOffset;
      v21 = 0;
      if ( v4->m_nCount > 0 )
      {
        do
        {
          v22 |= *(_DWORD *)((char *)&pStructMem->m_flExecute[v21] + v4->m_nOffsetOffset) >= 0;
          v6 = &ConnectColor;
          if ( *(int *)((char *)&pStructMem->m_flExecute[v21] + v4->m_nOffsetOffset) < 0 )
            v6 = &OpColor;
          v7 = *v6;
          if ( v4->m_Type != SO_FLOAT )
          {
            if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
              LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: LS_MESSAGE, a3: v7, a4: " UNKNOWN DATA TYPE %i ", v4->m_Type);
          }
          else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
          {
            LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: LS_MESSAGE, a3: v7, a4: "%f ", *(float *)&v13[4 * v21]);
          }
          ++v21;
        }
        while ( v21 < v4->m_nCount );
        v3 = this;
      }
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
      {
        v8 = " (connected)";
        if ( v22 == 0 )
          v8 = defaultValue;
        LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: LS_MESSAGE, a3: ConnectColor, a4: "%s\n", v8);
      }
      ++v19;
      ++v17;
      --pInput;
    }
    while ( pInput != nullptr );
  }
  if ( v3->m_vOutputs.m_Size > 0 )
  {
    v20 = 0;
    v18 = 0;
    pInputa = (char *)v3->m_vOutputs.m_Size;
    while ( 1 )
    {
      v9 = &v3->m_vOutputs.m_Memory.m_pMemory[v18];
      v10 = v3->m_vOutputMap.m_Elements.m_Tree.m_Elements.m_pMemory[v20].m_Data.key;
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
        LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: LS_MESSAGE, a3: OpColor, a4: "%*s%s: ", nLevel, "    ", v10);
      v11 = (char *)pStructMem + v9->m_nOffset;
      for ( i = 0; i < v9->m_nCount; ++i )
      {
        if ( v9->m_Type != SO_FLOAT )
        {
          if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
            LoggingSystem_Log(
              a1: LOG_SND_OPERATORS,
              a2: LS_MESSAGE,
              a3: OpColor,
              a4: " UNKNOWN DATA TYPE %i ",
              v9->m_Type);
        }
        else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
        {
          LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: LS_MESSAGE, a3: OpColor, a4: "%f ", *(float *)&v11[4 * i]);
        }
      }
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
        LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: LS_MESSAGE, a3: OpColor, a4: "\n");
      ++v18;
      ++v20;
      if ( --pInputa == nullptr )
        break;
      v3 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10045D70
// Name: public: void CSosOperator::PrintBaseParams(void __near *,class CSosOperatorStack __near *,int,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperator::PrintBaseParams(
        CSosOperator *this,
        CSosOperator_t *pVoidMem,
        CSosOperatorStack *pStack,
        const char *nOpIndex,
        int nLevel)
{
  Color *v5; // eax
  struct Color v6; // esi
  const char *v7; // eax
  const char *pName; // [esp+14h] [ebp+10h]

  pName = pStack->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_pMemory[(_DWORD)nOpIndex].m_Data.key;
  if ( pVoidMem->m_flExecute[0] <= 0.0 || pVoidMem->m_bExecuteOnce && pVoidMem->m_bHasExecuted )
    v5 = &NotExecuteColor;
  else
    v5 = &OpNameColor;
  v6 = *v5;
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
    LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: LS_MESSAGE, a3: v6, a4: "\n%*sName: %s\n", nLevel, "    ", pName);
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
  {
    v7 = "true";
    if ( !pVoidMem->m_bExecuteOnce )
      v7 = "false";
    LoggingSystem_Log(
      a1: LOG_SND_OPERATORS,
      a2: LS_MESSAGE,
      a3: OpColor,
      a4: "\n%*sExecute Once: %s\n",
      nLevel,
      "    ",
      v7);
  }
  CSosOperator::PrintIO(this, pStructMem: pVoidMem, nLevel);
}

//------------------------------------------------------------------------------
// Address: 0x10045E60
// Name: public: void CSosOperator::ResolveInputValues(void __near *,void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperator::ResolveInputValues(CSosOperator *this, char *pStructMem, char *pStackMem)
{
  CSosOperator *v3; // edx
  int v4; // eax
  int v5; // edi
  char *v6; // ecx
  char *v7; // ebx
  int v8; // esi
  int v9; // eax
  int v10; // [esp+0h] [ebp-14h]
  unsigned int i; // [esp+8h] [ebp-Ch]
  __int16 nDataCount; // [esp+Ch] [ebp-8h]
  char *nDataCounta; // [esp+Ch] [ebp-8h]
  int v15; // [esp+10h] [ebp-4h]

  v3 = this;
  i = 0;
  if ( this->m_vInputMap.m_Elements.m_Tree.m_NumElements != 0 )
  {
    v15 = 0;
    do
    {
      v4 = (int)&v3->m_vInputs.m_Memory.m_pMemory[v3->m_vInputMap.m_Elements.m_Tree.m_Elements.m_pMemory[v15].m_Data.elem];
      v5 = 0;
      nDataCount = *(_WORD *)(v4 + 12);
      v6 = &pStructMem[*(_DWORD *)v4];
      v7 = &pStructMem[*(_DWORD *)(v4 + 4)];
      if ( *(_DWORD *)(v4 + 8) == 0 )
        v5 = 4;
      v8 = 0;
      v10 = nDataCount;
      if ( nDataCount > 0 )
      {
        nDataCounta = &pStructMem[*(_DWORD *)v4];
        do
        {
          v9 = *(_DWORD *)&v7[4 * v8];
          if ( v9 > -1 )
          {
            _V_memcpy(dest: v6, src: &pStackMem[v9], count: v5);
            v3 = this;
          }
          ++v8;
          v6 = &nDataCounta[v5];
          nDataCounta += v5;
        }
        while ( v8 < v10 );
      }
      ++v15;
      ++i;
    }
    while ( i < v3->m_vInputMap.m_Elements.m_Tree.m_NumElements );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10045F00
// Name: public: void CSosOperator::OffsetConnections(void __near *,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperator::OffsetConnections(CSosOperator *this, char *pVoidMem, unsigned int nOffset)
{
  unsigned int v3; // edi
  int v4; // esi
  int *v5; // eax

  v3 = 0;
  if ( this->m_vInputMap.m_Elements.m_Tree.m_NumElements != 0 )
  {
    v4 = 0;
    do
    {
      v5 = (int *)&pVoidMem[this->m_vInputs.m_Memory.m_pMemory[this->m_vInputMap.m_Elements.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem].m_nOffsetOffset];
      if ( *v5 > -1 )
        *v5 += nOffset;
      ++v3;
      ++v4;
    }
    while ( v3 < this->m_vInputMap.m_Elements.m_Tree.m_NumElements );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10045F40
// Name: public: virtual void CSosOperator::StackShutdown(void __near *,class CSosOperatorStack __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperator::StackShutdown(
        CSosOperator *this,
        void *pVoidMem,
        CSosOperatorStack *pStack,
        int nOpIndex)
{
  if ( snd_sos_show_operator_shutdown.m_pParent != nullptr
    && snd_sos_show_operator_shutdown.m_pParent->m_Value.m_nValue != 0
    && (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
  {
    LoggingSystem_Log(
      a1: LOG_SND_OPERATORS,
      a2: LS_MESSAGE,
      a3: OpColor,
      a4: "Stack Shutdown: Stack: %s : Operator: %s\n",
      pStack->m_nName,
      pStack->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_pMemory[nOpIndex].m_Data.key);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10045FA0
// Name: public: bool CSosOperator::BaseParseKV(class CSosOperatorStack __near *,struct CSosOperator_t __near *,char const __near *,char const __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSosOperator::BaseParseKV(
        CSosOperator *this,
        CSosOperatorStack *pStack,
        CSosOperator_t *pStructMem,
        const char *pParamString,
        const char *pValueString)
{
  int v7; // ebx
  const char *v8; // esi
  const char *v9; // eax
  int v10; // esi
  CSosOperator::InputData_t *v11; // esi
  unsigned int m_nOffsetOffset; // edi
  int v13; // eax
  int v14; // edx
  int *v15; // edi
  int v16; // ecx
  unsigned int m_nOffset; // esi
  int v18; // edx
  int *v19; // eax
  char tempString[64]; // [esp+Ch] [ebp-50h] BYREF
  interval_t interval; // [esp+4Ch] [ebp-10h] BYREF
  int nCount; // [esp+54h] [ebp-8h]
  bool bFillInputArray; // [esp+5Bh] [ebp-1h]
  int nOutputOffset; // [esp+64h] [ebp+8h]
  float flValue; // [esp+6Ch] [ebp+10h]

  LODWORD(interval.range) = this;
  if ( pParamString == nullptr || *pParamString == 0 || pValueString == nullptr || *pValueString == 0 )
    return 0;
  if ( V_strcasecmp(s1: pParamString, s2: "operator") == 0 )
    return 1;
  if ( V_strcasecmp(s1: pParamString, s2: "execute_once") == 0 )
  {
    pStructMem->m_bExecuteOnce = V_strcasecmp(s1: pValueString, s2: "true") == 0;
    return 1;
  }
  v7 = -1;
  V_strncpy(pDest: tempString, pSrc: pParamString, maxLen: 64);
  v8 = strtok(string: tempString, control: "[");
  v9 = strtok(string: nullptr, control: "]");
  bFillInputArray = false;
  if ( v9 != nullptr && *v9 != 0 )
  {
    if ( *v9 == 42 )
      bFillInputArray = true;
    else
      v7 = V_atoi(str: v9);
  }
  v10 = CUtlDict<int,int>::Find(this: &this->m_vInputMap, pName: v8);
  if ( !CUtlVector<CSosOperator::InputData_t,CUtlMemory<CSosOperator::InputData_t,int>>::IsValidIndex(
          this: (vgui::ImageList *)&this->m_vInputs,
          imageIndex: v10) )
    return 0;
  v11 = &this->m_vInputs.m_Memory.m_pMemory[v10];
  m_nOffsetOffset = v11->m_nOffsetOffset;
  nCount = (unsigned __int16)v11->m_nCount;
  v13 = CSosOperator::ParseValueRef(this: (CSosOperator *)LODWORD(interval.range), pStack, pParamString, pValueString);
  nOutputOffset = v13;
  if ( v13 <= -1 )
  {
    m_nOffset = v11->m_nOffset;
    interval = ReadInterval(pString: pValueString);
    flValue = RandomInterval(&interval);
    if ( v7 <= -1 )
    {
      v18 = (__int16)nCount;
      if ( (__int16)nCount > 0 )
      {
        v19 = (int *)((char *)pStructMem + m_nOffsetOffset);
        do
        {
          *(float *)((char *)v19 + m_nOffset - m_nOffsetOffset) = flValue;
          *v19++ = nOutputOffset;
          --v18;
        }
        while ( v18 != 0 );
      }
      return 1;
    }
    else
    {
      if ( v7 >= (__int16)nCount )
        return 1;
      *(float *)((char *)&pStructMem->m_flExecute[v7] + m_nOffset) = flValue;
      *(float *)((char *)&pStructMem->m_flExecute[v7] + m_nOffsetOffset) = NAN;
      return 1;
    }
  }
  else if ( v7 <= -1 )
  {
    v14 = (__int16)nCount;
    if ( (__int16)nCount > 0 )
    {
      v15 = (int *)((char *)pStructMem + m_nOffsetOffset);
      v16 = v13;
      do
      {
        if ( bFillInputArray )
          *v15 = v13;
        else
          *v15 = v16;
        v16 += 4;
        ++v15;
        --v14;
      }
      while ( v14 != 0 );
    }
    return 1;
  }
  else if ( v7 >= (__int16)nCount )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
      _LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: 1, a3: "Error: Illegal array access: %s", pParamString);
    return 1;
  }
  else
  {
    *(_DWORD *)((char *)&pStructMem->m_flExecute[v7] + m_nOffsetOffset) = v13;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100461E0
// Name: public: int CSosOperator::GetOutputOffset(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CSosOperator::GetOutputOffset(CSosOperator *this, const char *pOutputName)
{
  int v3; // eax
  CUtlMap<char const *,int,int>::Node_t search; // [esp+8h] [ebp-8h] BYREF

  if ( pOutputName != nullptr )
  {
    search.key = pOutputName;
    v3 = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Find(
           this: &this->m_vOutputMap.m_Elements.m_Tree,
           &search);
    if ( v3 >= 0 && v3 < this->m_vOutputs.m_Size )
      return this->m_vOutputs.m_Memory.m_pMemory[v3].m_nOffset;
  }
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
    _LoggingSystem_Log(
      a1: LOG_SND_OPERATORS,
      a2: 1,
      a3: "Error: Unable to find referenced sound operator output: %s",
      pOutputName);
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10046260
// Name: public: CSosOperator::CSosOperator(void)
// Source: json
//------------------------------------------------------------------------------
CSosOperator *__thiscall CSosOperator::CSosOperator(CSosOperator *this)
{
  int m_Size; // [esp-8h] [ebp-24h]
  CSosOperator::InputData_t inputData; // [esp+8h] [ebp-14h] BYREF
  int nIndex; // [esp+18h] [ebp-4h] BYREF

  this->__vftable = (CSosOperator_vtbl *)&CSosOperator::`vftable';
  this->m_vOutputMap.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_vOutputMap.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_vOutputMap.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_vOutputMap.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_vOutputMap.m_Elements.m_Tree.m_Root = -1;
  this->m_vOutputMap.m_Elements.m_Tree.m_NumElements = 0;
  this->m_vOutputMap.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_vOutputMap.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_vOutputMap.m_Elements.m_Tree.m_pElements = this->m_vOutputMap.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( this->m_vOutputMap.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_vOutputMap.m_Elements.m_Tree.m_LessFunc.m_LessFunc = CaselessStringLessThan;
  this->m_vOutputs.m_Memory.m_pMemory = nullptr;
  this->m_vOutputs.m_Memory.m_nAllocationCount = 0;
  this->m_vOutputs.m_Memory.m_nGrowSize = 0;
  this->m_vOutputs.m_Size = 0;
  this->m_vOutputs.m_pElements = nullptr;
  this->m_vInputMap.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_vInputMap.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_vInputMap.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_vInputMap.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_vInputMap.m_Elements.m_Tree.m_Root = -1;
  this->m_vInputMap.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_vInputMap.m_Elements.m_Tree.m_NumElements = 0;
  this->m_vInputMap.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_vInputMap.m_Elements.m_Tree.m_pElements = this->m_vInputMap.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( this->m_vInputMap.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_vInputMap.m_Elements.m_Tree.m_LessFunc.m_LessFunc = CaselessStringLessThan;
  this->m_vInputs.m_Memory.m_pMemory = nullptr;
  this->m_vInputs.m_Memory.m_nAllocationCount = 0;
  this->m_vInputs.m_Memory.m_nGrowSize = 0;
  this->m_vInputs.m_Size = 0;
  this->m_vInputs.m_pElements = nullptr;
  inputData.m_nOffset = 0;
  inputData.m_Type = SO_FLOAT;
  inputData.m_nCount = 1;
  m_Size = this->m_vInputs.m_Size;
  inputData.m_nOffsetOffset = 4;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: m_Size,
             src: &inputData);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_execute", element: &nIndex);
  return this;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10045670
// Name: Register_LOG_SND_OPERATORS_Tags
// Source: json
//------------------------------------------------------------------------------
int Register_LOG_SND_OPERATORS_Tags()
{
  _LoggingSystem_AddTagToCurrentChannel(a1: "SndOperators");
  return _LoggingSystem_AddTagToCurrentChannel(a1: "SND");
}

//------------------------------------------------------------------------------
// Address: 0x10045690
// Name: public: void CSosOperator::SetBaseDefaults(void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperator::SetBaseDefaults(CSosOperator *this, _DWORD *pVoidMem)
{
  *pVoidMem = 1065353216;
  pVoidMem[1] = -1;
  *((_WORD *)pVoidMem + 4) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100456C0
// Name: public: int CSosOperator::ParseValueRef(class CSosOperatorStack __near *,char const __near *,char const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSosOperator::ParseValueRef(
        CSosOperator *this,
        CSosOperatorStack *pStack,
        const char *pParamString,
        const char *pValueString)
{
  const char *v4; // edi
  const char *v5; // esi
  int OperatorOutputOffset; // edi
  const char *v8; // eax
  int v9; // eax
  char pDest[64]; // [esp+0h] [ebp-80h] BYREF
  char tempString[64]; // [esp+40h] [ebp-40h] BYREF

  if ( *pValueString != 64 )
    return -1;
  V_strncpy(pDest: tempString, pSrc: pValueString + 1, maxLen: 64);
  v4 = strtok(string: tempString, control: ".");
  v5 = strtok(string: nullptr, control: defaultValue);
  OperatorOutputOffset = CSosOperatorStack::GetOperatorOutputOffset(this: pStack, pOperatorName: v4, pOutputName: v5);
  if ( OperatorOutputOffset < 0 )
    return -1;
  V_strncpy(pDest, pSrc: v5, maxLen: 64);
  v8 = strtok(string: nullptr, control: "]");
  if ( v8 != nullptr && *v8 != 0 )
  {
    v9 = V_atoi(str: v8);
    if ( v9 > -1 )
      OperatorOutputOffset += v9;
  }
  return OperatorOutputOffset;
}

//------------------------------------------------------------------------------
// Address: 0x10045770
// Name: public: void CSosOperator::PrintIO(struct CSosOperator_t __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperator::PrintIO(CSosOperator *this, CSosOperator_t *pStructMem, int nLevel)
{
  CSosOperator *v3; // ebx
  CSosOperator::InputData_t *v4; // esi
  const char *key; // edi
  Color *v6; // eax
  struct Color v7; // ebx
  const char *v8; // eax
  CSosOperator::OutputData_t *v9; // esi
  const char *v10; // edi
  char *v11; // ebx
  int i; // edi
  char *pInput; // [esp+14h] [ebp-1Ch]
  int m_Size; // [esp+1Ch] [ebp-14h]
  int v16; // [esp+1Ch] [ebp-14h]
  int v17; // [esp+20h] [ebp-10h]
  int v18; // [esp+20h] [ebp-10h]
  int v19; // [esp+24h] [ebp-Ch]
  int v20; // [esp+24h] [ebp-Ch]
  int j; // [esp+28h] [ebp-8h]
  char bAnyConnected; // [esp+2Fh] [ebp-1h]

  v3 = this;
  if ( this->m_vInputs.m_Size > 0 )
  {
    v17 = 0;
    v19 = 0;
    m_Size = this->m_vInputs.m_Size;
    do
    {
      v4 = &v3->m_vInputs.m_Memory.m_pMemory[v19];
      key = v3->m_vInputMap.m_Elements.m_Tree.m_Elements.m_pMemory[v17].m_Data.key;
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
        LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: LS_MESSAGE, a3: OpColor, a4: "%*s%s: ", nLevel, "    ", key);
      bAnyConnected = 0;
      pInput = (char *)pStructMem + v4->m_nOffset;
      j = 0;
      if ( v4->m_nCount > 0 )
      {
        do
        {
          bAnyConnected |= *(_DWORD *)((char *)&pStructMem->m_flExecute[j] + v4->m_nOffsetOffset) >= 0;
          v6 = &ConnectColor;
          if ( *(int *)((char *)&pStructMem->m_flExecute[j] + v4->m_nOffsetOffset) < 0 )
            v6 = &OpColor;
          v7 = *v6;
          if ( v4->m_Type != SO_FLOAT )
          {
            if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
              LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: LS_MESSAGE, a3: v7, a4: " UNKNOWN DATA TYPE %i ", v4->m_Type);
          }
          else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
          {
            LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: LS_MESSAGE, a3: v7, a4: "%f ", *(float *)&pInput[4 * j]);
          }
          ++j;
        }
        while ( j < v4->m_nCount );
        v3 = this;
      }
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
      {
        v8 = " (connected)";
        if ( bAnyConnected == 0 )
          v8 = defaultValue;
        LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: LS_MESSAGE, a3: ConnectColor, a4: "%s\n", v8);
      }
      ++v19;
      ++v17;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
  if ( v3->m_vOutputs.m_Size > 0 )
  {
    v20 = 0;
    v18 = 0;
    v16 = v3->m_vOutputs.m_Size;
    while ( 1 )
    {
      v9 = &v3->m_vOutputs.m_Memory.m_pMemory[v18];
      v10 = v3->m_vOutputMap.m_Elements.m_Tree.m_Elements.m_pMemory[v20].m_Data.key;
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
        LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: LS_MESSAGE, a3: OpColor, a4: "%*s%s: ", nLevel, "    ", v10);
      v11 = (char *)pStructMem + v9->m_nOffset;
      for ( i = 0; i < v9->m_nCount; ++i )
      {
        if ( v9->m_Type != SO_FLOAT )
        {
          if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
            LoggingSystem_Log(
              a1: LOG_SND_OPERATORS,
              a2: LS_MESSAGE,
              a3: OpColor,
              a4: " UNKNOWN DATA TYPE %i ",
              v9->m_Type);
        }
        else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
        {
          LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: LS_MESSAGE, a3: OpColor, a4: "%f ", *(float *)&v11[4 * i]);
        }
      }
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
        LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: LS_MESSAGE, a3: OpColor, a4: "\n");
      ++v18;
      ++v20;
      if ( --v16 == 0 )
        break;
      v3 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10045A60
// Name: public: void CSosOperator::PrintBaseParams(void __near *,class CSosOperatorStack __near *,int,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperator::PrintBaseParams(
        CSosOperator *this,
        CSosOperator_t *pVoidMem,
        CSosOperatorStack *pStack,
        const char *nOpIndex,
        int nLevel)
{
  Color *v5; // eax
  struct Color v6; // esi
  const char *v7; // eax
  const char *pName; // [esp+14h] [ebp+10h]

  pName = pStack->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_pMemory[(_DWORD)nOpIndex].m_Data.key;
  if ( pVoidMem->m_flExecute[0] <= 0.0 || pVoidMem->m_bExecuteOnce && pVoidMem->m_bHasExecuted )
    v5 = &NotExecuteColor;
  else
    v5 = &OpNameColor;
  v6 = *v5;
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
    LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: LS_MESSAGE, a3: v6, a4: "\n%*sName: %s\n", nLevel, "    ", pName);
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
  {
    v7 = "true";
    if ( !pVoidMem->m_bExecuteOnce )
      v7 = "false";
    LoggingSystem_Log(
      a1: LOG_SND_OPERATORS,
      a2: LS_MESSAGE,
      a3: OpColor,
      a4: "\n%*sExecute Once: %s\n",
      nLevel,
      "    ",
      v7);
  }
  CSosOperator::PrintIO(this, pStructMem: pVoidMem, nLevel);
}

//------------------------------------------------------------------------------
// Address: 0x10045B50
// Name: public: void CSosOperator::ResolveInputValues(void __near *,void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperator::ResolveInputValues(CSosOperator *this, char *pStructMem, char *pStackMem)
{
  CSosOperator *v3; // edx
  int v4; // eax
  int v5; // edi
  char *v6; // ecx
  char *v7; // ebx
  int v8; // esi
  int v9; // eax
  int v10; // [esp+0h] [ebp-14h]
  unsigned int i; // [esp+8h] [ebp-Ch]
  __int16 nDataCount; // [esp+Ch] [ebp-8h]
  char *nDataCounta; // [esp+Ch] [ebp-8h]
  int v15; // [esp+10h] [ebp-4h]

  v3 = this;
  i = 0;
  if ( this->m_vInputMap.m_Elements.m_Tree.m_NumElements != 0 )
  {
    v15 = 0;
    do
    {
      v4 = (int)&v3->m_vInputs.m_Memory.m_pMemory[v3->m_vInputMap.m_Elements.m_Tree.m_Elements.m_pMemory[v15].m_Data.elem];
      v5 = 0;
      nDataCount = *(_WORD *)(v4 + 12);
      v6 = &pStructMem[*(_DWORD *)v4];
      v7 = &pStructMem[*(_DWORD *)(v4 + 4)];
      if ( *(_DWORD *)(v4 + 8) == 0 )
        v5 = 4;
      v8 = 0;
      v10 = nDataCount;
      if ( nDataCount > 0 )
      {
        nDataCounta = &pStructMem[*(_DWORD *)v4];
        do
        {
          v9 = *(_DWORD *)&v7[4 * v8];
          if ( v9 > -1 )
          {
            _V_memcpy(dest: v6, src: &pStackMem[v9], count: v5);
            v3 = this;
          }
          ++v8;
          v6 = &nDataCounta[v5];
          nDataCounta += v5;
        }
        while ( v8 < v10 );
      }
      ++v15;
      ++i;
    }
    while ( i < v3->m_vInputMap.m_Elements.m_Tree.m_NumElements );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10045BF0
// Name: public: void CSosOperator::OffsetConnections(void __near *,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperator::OffsetConnections(CSosOperator *this, char *pVoidMem, unsigned int nOffset)
{
  unsigned int v3; // edi
  int v4; // esi
  int *v5; // eax

  v3 = 0;
  if ( this->m_vInputMap.m_Elements.m_Tree.m_NumElements != 0 )
  {
    v4 = 0;
    do
    {
      v5 = (int *)&pVoidMem[this->m_vInputs.m_Memory.m_pMemory[this->m_vInputMap.m_Elements.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem].m_nOffsetOffset];
      if ( *v5 > -1 )
        *v5 += nOffset;
      ++v3;
      ++v4;
    }
    while ( v3 < this->m_vInputMap.m_Elements.m_Tree.m_NumElements );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10045C30
// Name: public: virtual void CSosOperator::StackShutdown(void __near *,class CSosOperatorStack __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperator::StackShutdown(
        CSosOperator *this,
        void *pVoidMem,
        CSosOperatorStack *pStack,
        int nOpIndex)
{
  if ( snd_sos_show_operator_shutdown.m_pParent != nullptr
    && snd_sos_show_operator_shutdown.m_pParent->m_Value.m_nValue != 0
    && (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
  {
    LoggingSystem_Log(
      a1: LOG_SND_OPERATORS,
      a2: LS_MESSAGE,
      a3: OpColor,
      a4: "Stack Shutdown: Stack: %s : Operator: %s\n",
      pStack->m_nName,
      pStack->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_pMemory[nOpIndex].m_Data.key);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10045C90
// Name: public: bool CSosOperator::BaseParseKV(class CSosOperatorStack __near *,struct CSosOperator_t __near *,char const __near *,char const __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSosOperator::BaseParseKV(
        CSosOperator *this,
        CSosOperatorStack *pStack,
        CSosOperator_t *pStructMem,
        const char *pParamString,
        const char *pValueString)
{
  int v7; // ebx
  const char *v8; // esi
  const char *v9; // eax
  int v10; // esi
  CSosOperator::InputData_t *v11; // esi
  unsigned int m_nOffsetOffset; // edi
  int v13; // eax
  int v14; // edx
  int *v15; // edi
  int v16; // ecx
  unsigned int m_nOffset; // esi
  int v18; // edx
  int *v19; // eax
  char tempString[64]; // [esp+Ch] [ebp-50h] BYREF
  interval_t interval; // [esp+4Ch] [ebp-10h] BYREF
  int nCount; // [esp+54h] [ebp-8h]
  bool bFillInputArray; // [esp+5Bh] [ebp-1h]
  int nOutputOffset; // [esp+64h] [ebp+8h]
  float flValue; // [esp+6Ch] [ebp+10h]

  LODWORD(interval.range) = this;
  if ( pParamString == nullptr || *pParamString == 0 || pValueString == nullptr || *pValueString == 0 )
    return 0;
  if ( V_strcasecmp(s1: pParamString, s2: "operator") == 0 )
    return 1;
  if ( V_strcasecmp(s1: pParamString, s2: "execute_once") == 0 )
  {
    pStructMem->m_bExecuteOnce = V_strcasecmp(s1: pValueString, s2: "true") == 0;
    return 1;
  }
  v7 = -1;
  V_strncpy(pDest: tempString, pSrc: pParamString, maxLen: 64);
  v8 = strtok(string: tempString, control: "[");
  v9 = strtok(string: nullptr, control: "]");
  bFillInputArray = false;
  if ( v9 != nullptr && *v9 != 0 )
  {
    if ( *v9 == 42 )
      bFillInputArray = true;
    else
      v7 = V_atoi(str: v9);
  }
  v10 = CUtlDict<int,int>::Find(this: &this->m_vInputMap, pName: v8);
  if ( !CUtlVector<CSosOperator::InputData_t,CUtlMemory<CSosOperator::InputData_t,int>>::IsValidIndex(
          this: (vgui::ImageList *)&this->m_vInputs,
          imageIndex: v10) )
    return 0;
  v11 = &this->m_vInputs.m_Memory.m_pMemory[v10];
  m_nOffsetOffset = v11->m_nOffsetOffset;
  nCount = (unsigned __int16)v11->m_nCount;
  v13 = CSosOperator::ParseValueRef(this: (CSosOperator *)LODWORD(interval.range), pStack, pParamString, pValueString);
  nOutputOffset = v13;
  if ( v13 <= -1 )
  {
    m_nOffset = v11->m_nOffset;
    interval = ReadInterval(pString: pValueString);
    flValue = RandomInterval(&interval);
    if ( v7 <= -1 )
    {
      v18 = (__int16)nCount;
      if ( (__int16)nCount > 0 )
      {
        v19 = (int *)((char *)pStructMem + m_nOffsetOffset);
        do
        {
          *(float *)((char *)v19 + m_nOffset - m_nOffsetOffset) = flValue;
          *v19++ = nOutputOffset;
          --v18;
        }
        while ( v18 != 0 );
      }
      return 1;
    }
    else
    {
      if ( v7 >= (__int16)nCount )
        return 1;
      *(float *)((char *)&pStructMem->m_flExecute[v7] + m_nOffset) = flValue;
      *(float *)((char *)&pStructMem->m_flExecute[v7] + m_nOffsetOffset) = NAN;
      return 1;
    }
  }
  else if ( v7 <= -1 )
  {
    v14 = (__int16)nCount;
    if ( (__int16)nCount > 0 )
    {
      v15 = (int *)((char *)pStructMem + m_nOffsetOffset);
      v16 = v13;
      do
      {
        if ( bFillInputArray )
          *v15 = v13;
        else
          *v15 = v16;
        v16 += 4;
        ++v15;
        --v14;
      }
      while ( v14 != 0 );
    }
    return 1;
  }
  else if ( v7 >= (__int16)nCount )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
      _LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: 1, a3: "Error: Illegal array access: %s", pParamString);
    return 1;
  }
  else
  {
    *(_DWORD *)((char *)&pStructMem->m_flExecute[v7] + m_nOffsetOffset) = v13;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10045ED0
// Name: public: int CSosOperator::GetOutputOffset(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CSosOperator::GetOutputOffset(CSosOperator *this, const char *pOutputName)
{
  int v3; // eax
  CUtlMap<char const *,int,int>::Node_t search; // [esp+8h] [ebp-8h] BYREF

  if ( pOutputName != nullptr )
  {
    search.key = pOutputName;
    v3 = CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Find(
           this: &this->m_vOutputMap.m_Elements.m_Tree,
           &search);
    if ( v3 >= 0 && v3 < this->m_vOutputs.m_Size )
      return this->m_vOutputs.m_Memory.m_pMemory[v3].m_nOffset;
  }
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
    _LoggingSystem_Log(
      a1: LOG_SND_OPERATORS,
      a2: 1,
      a3: "Error: Unable to find referenced sound operator output: %s",
      pOutputName);
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10045F50
// Name: public: CSosOperator::CSosOperator(void)
// Source: json
//------------------------------------------------------------------------------
CSosOperator *__thiscall CSosOperator::CSosOperator(CSosOperator *this)
{
  int m_Size; // [esp-8h] [ebp-24h]
  CSosOperator::InputData_t inputData; // [esp+8h] [ebp-14h] BYREF
  int nIndex; // [esp+18h] [ebp-4h] BYREF

  this->__vftable = (CSosOperator_vtbl *)&CSosOperator::`vftable';
  this->m_vOutputMap.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_vOutputMap.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_vOutputMap.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_vOutputMap.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_vOutputMap.m_Elements.m_Tree.m_Root = -1;
  this->m_vOutputMap.m_Elements.m_Tree.m_NumElements = 0;
  this->m_vOutputMap.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_vOutputMap.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_vOutputMap.m_Elements.m_Tree.m_pElements = this->m_vOutputMap.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( this->m_vOutputMap.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_vOutputMap.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  this->m_vOutputs.m_Memory.m_pMemory = nullptr;
  this->m_vOutputs.m_Memory.m_nAllocationCount = 0;
  this->m_vOutputs.m_Memory.m_nGrowSize = 0;
  this->m_vOutputs.m_Size = 0;
  this->m_vOutputs.m_pElements = nullptr;
  this->m_vInputMap.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_vInputMap.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_vInputMap.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_vInputMap.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_vInputMap.m_Elements.m_Tree.m_Root = -1;
  this->m_vInputMap.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_vInputMap.m_Elements.m_Tree.m_NumElements = 0;
  this->m_vInputMap.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_vInputMap.m_Elements.m_Tree.m_pElements = this->m_vInputMap.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( this->m_vInputMap.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_vInputMap.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  this->m_vInputs.m_Memory.m_pMemory = nullptr;
  this->m_vInputs.m_Memory.m_nAllocationCount = 0;
  this->m_vInputs.m_Memory.m_nGrowSize = 0;
  this->m_vInputs.m_Size = 0;
  this->m_vInputs.m_pElements = nullptr;
  inputData.m_nOffset = 0;
  inputData.m_Type = SO_FLOAT;
  inputData.m_nCount = 1;
  m_Size = this->m_vInputs.m_Size;
  inputData.m_nOffsetOffset = 4;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: m_Size,
             src: &inputData);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_execute", element: &nIndex);
  return this;
}

} // namespace engine_xlsp
