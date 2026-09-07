// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/audio/private/snd_op_sys/sos_op_iterate_merge_speakers.cpp
// Functions: 13
// ============================================================

#include "engine\audio\private\snd_op_sys\sos_op_iterate_merge_speakers.h"

//------------------------------------------------------------------------------
// Address: 0x100482A0
// Name: public: virtual void CSosOperatorIterateAndMergeSpeakers::SetDefaults(void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorIterateAndMergeSpeakers::SetDefaults(
        CSosOperatorIterateAndMergeSpeakers *this,
        _DWORD *pVoidMem)
{
  pVoidMem[22] = 0;
  pVoidMem[23] = -1;
  pVoidMem[24] = 0;
  pVoidMem[30] = -1;
  pVoidMem[25] = 0;
  pVoidMem[31] = -1;
  pVoidMem[26] = 0;
  pVoidMem[32] = -1;
  pVoidMem[27] = 0;
  pVoidMem[33] = -1;
  pVoidMem[28] = 0;
  pVoidMem[34] = -1;
  pVoidMem[29] = 0;
  pVoidMem[35] = -1;
  pVoidMem[36] = 0;
  pVoidMem[37] = 0;
  pVoidMem[38] = 0;
  pVoidMem[39] = 0;
  pVoidMem[40] = 0;
  pVoidMem[41] = 0;
  pVoidMem[21] = 0;
  pVoidMem[19] = 8;
  pVoidMem[20] = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10048340
// Name: public: virtual void CSosOperatorIterateAndMergeSpeakers::Print(void __near *,class CSosOperatorStack __near *,int,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorIterateAndMergeSpeakers::Print(
        CSosOperatorIterateAndMergeSpeakers *this,
        CSosOperator_t *pVoidMem,
        CSosOperatorStack *pStack,
        const char *nOpIndex,
        int nLevel)
{
  CSosOperator::PrintBaseParams(this, pVoidMem, pStack, nOpIndex, nLevel);
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
    LoggingSystem_Log(
      a1: LOG_SND_OPERATORS,
      a2: LS_MESSAGE,
      a3: OpColor,
      a4: "%*sIterate Op: %s\n",
      nLevel,
      "    ",
      (const char *)&pVoidMem[1]);
}

//------------------------------------------------------------------------------
// Address: 0x100483A0
// Name: public: virtual void CSosOperatorIterateAndMergeSpeakers::ParseKV(class CSosOperatorStack __near *,void __near *,class KeyValues __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorIterateAndMergeSpeakers::ParseKV(
        CSosOperatorIterateAndMergeSpeakers *this,
        CSosOperatorStack *pStack,
        char *pVoidMem,
        KeyValues *pOpKeys)
{
  KeyValues *i; // ebx
  const char *Name; // esi
  const char *String; // eax
  const char *v7; // edi

  for ( i = KeyValues::GetFirstSubKey(this: pOpKeys); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    Name = KeyValues::GetName(this: i);
    String = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: defaultValue);
    v7 = String;
    if ( Name != nullptr
      && *Name != 0
      && String != nullptr
      && *String != 0
      && CSosOperator::BaseParseKV(
           this,
           pStack,
           pStructMem: (CSosOperator_t *)pVoidMem,
           pParamString: Name,
           pValueString: String) == 0 )
    {
      if ( V_strcasecmp(s1: Name, s2: "iterate_operator") != 0 )
      {
        if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
          _LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: 1, a3: "Error: Unknown sound operator attribute %s\n", Name);
      }
      else
      {
        V_strncpy(pDest: pVoidMem + 12, pSrc: v7, maxLen: 64);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10048470
// Name: public: virtual void CSosOperatorIterateAndMergeSpeakers::Execute(void __near *,struct channel_t __near *,class CScratchPad __near *,class CSosOperatorStack __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorIterateAndMergeSpeakers::Execute(
        CSosOperatorIterateAndMergeSpeakers *this,
        int pVoidMem,
        channel_t *pChannel,
        CScratchPad *pScratchPad,
        CSosOperatorStack *pStack,
        int nOpIndex)
{
  int v7; // edx
  int v8; // ecx
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  int nCurIndex; // [esp+0h] [ebp-8h]
  int nLastIndex; // [esp+10h] [ebp+8h]

  if ( pChannel != nullptr )
  {
    v7 = *(_DWORD *)(pVoidMem + 76);
    v8 = (int)*(float *)(pVoidMem + 84);
    nCurIndex = v8;
    nLastIndex = (int)*(float *)(pVoidMem + 88);
    if ( nLastIndex >= v7 )
      nLastIndex = v7;
    if ( v8 == 0 )
    {
      *(_DWORD *)(pVoidMem + 144) = 0;
      *(_DWORD *)(pVoidMem + 148) = 0;
      *(_DWORD *)(pVoidMem + 152) = 0;
      *(_DWORD *)(pVoidMem + 156) = 0;
      *(_DWORD *)(pVoidMem + 160) = 0;
      *(_DWORD *)(pVoidMem + 164) = 0;
    }
    v9 = *(float *)(pVoidMem + 96);
    if ( v9 <= *(float *)(pVoidMem + 144) )
      v9 = *(float *)(pVoidMem + 144);
    v10 = *(float *)(pVoidMem + 148);
    *(float *)(pVoidMem + 144) = v9;
    v11 = *(float *)(pVoidMem + 100);
    if ( v11 <= v10 )
      v11 = v10;
    v12 = *(float *)(pVoidMem + 152);
    *(float *)(pVoidMem + 148) = v11;
    v13 = *(float *)(pVoidMem + 104);
    if ( v13 <= v12 )
      v13 = v12;
    v14 = *(float *)(pVoidMem + 156);
    *(float *)(pVoidMem + 152) = v13;
    v15 = *(float *)(pVoidMem + 108);
    if ( v15 <= v14 )
      v15 = v14;
    v16 = *(float *)(pVoidMem + 160);
    *(float *)(pVoidMem + 156) = v15;
    v17 = *(float *)(pVoidMem + 112);
    if ( v17 <= v16 )
      v17 = v16;
    v18 = *(float *)(pVoidMem + 164);
    *(float *)(pVoidMem + 160) = v17;
    v19 = *(float *)(pVoidMem + 116);
    if ( v19 <= v18 )
      v19 = v18;
    *(float *)(pVoidMem + 164) = v19;
    if ( snd_sos_show_operator_updates.m_pParent != nullptr
      && snd_sos_show_operator_updates.m_pParent->m_Value.m_nValue != 0 )
    {
      this->Print(this, a2: (void *)pVoidMem, a3: pStack, a4: nOpIndex, a5: 0);
      v8 = nCurIndex;
    }
    if ( v8 >= nLastIndex )
    {
      *(_DWORD *)(pVoidMem + 84) = 0;
    }
    else
    {
      *(float *)(pVoidMem + 84) = (float)(v8 + 1);
      CSosOperatorStack::ExecuteIterator(
        this: pStack,
        pChannel,
        pScratchPad,
        pStopMemBlock: (const void *)pVoidMem,
        pOperatorName: (const char *)(pVoidMem + 12),
        pnOperatorIndex: (int *)(pVoidMem + 80));
    }
  }
  else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
  {
    _LoggingSystem_Log(
      a1: LOG_SND_OPERATORS,
      a2: 1,
      a3: "Error: Sound operator %s requires valid channel pointer, being called without one\n",
      pStack->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_pMemory[nOpIndex].m_Data.key);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10048640
// Name: public: CSosOperatorIterateAndMergeSpeakers::CSosOperatorIterateAndMergeSpeakers(void)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorIterateAndMergeSpeakers *__thiscall CSosOperatorIterateAndMergeSpeakers::CSosOperatorIterateAndMergeSpeakers(
        CSosOperatorIterateAndMergeSpeakers *this)
{
  int v2; // eax
  int v3; // eax
  CSosOperatorSystem *SoundOperatorSystem; // eax
  int m_Size; // [esp-8h] [ebp-28h]
  int v7; // [esp-8h] [ebp-28h]
  CSosOperator::InputData_t inputData; // [esp+Ch] [ebp-14h] BYREF
  int nIndex; // [esp+1Ch] [ebp-4h] BYREF

  CSosOperator::CSosOperator(this);
  this->__vftable = (CSosOperatorIterateAndMergeSpeakers_vtbl *)&CSosOperatorIterateAndMergeSpeakers::`vftable';
  m_Size = this->m_vInputs.m_Size;
  inputData.m_nOffset = 88;
  inputData.m_nOffsetOffset = 92;
  inputData.m_Type = SO_FLOAT;
  inputData.m_nCount = 1;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: m_Size,
             src: &inputData);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_max_iterations", element: &nIndex);
  v2 = this->m_vOutputs.m_Size;
  inputData.m_nCount = 1;
  inputData.m_nOffsetOffset = 84;
  inputData.m_Type = SO_FLOAT;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: v2,
             src: (const Vector *)&inputData.m_nOffsetOffset);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output_index", element: &nIndex);
  v7 = this->m_vOutputs.m_Size;
  inputData.m_nOffsetOffset = 144;
  inputData.m_Type = SO_FLOAT;
  inputData.m_nCount = 6;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: v7,
             src: (const Vector *)&inputData.m_nOffsetOffset);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output", element: &nIndex);
  v3 = this->m_vInputs.m_Size;
  inputData.m_nCount = 6;
  inputData.m_nOffset = 96;
  inputData.m_nOffsetOffset = 120;
  inputData.m_Type = SO_FLOAT;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: v3,
             src: &inputData);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input", element: &nIndex);
  nIndex = (int)this;
  SoundOperatorSystem = CSosOperatorSystem::GetSoundOperatorSystem();
  CUtlDict<CSosOperator *,int>::Insert(
    this: &SoundOperatorSystem->m_vOperatorCollection,
    pName: "iterate_merge_speakers",
    element: (CSosOperator *const *)&nIndex);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10310280
// Name: _dynamic_initializer_for__speak__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__speak__()
{
  ConCommand::ConCommand(
    this: &speak,
    pName: "speak",
    callback: (void (__cdecl *)())S_Say,
    pHelpString: "Play a constructed sentence.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__speak__);
}

//------------------------------------------------------------------------------
// Address: 0x10320C40
// Name: _dynamic_atexit_destructor_for__speak__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__speak__()
{
  ConCommand::~ConCommand(this: &speak);
}

//------------------------------------------------------------------------------
// Address: 0x103102B0
// Name: _dynamic_initializer_for__stopsound__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__stopsound__()
{
  ConCommand::ConCommand(
    this: &stopsound,
    pName: "stopsound",
    callback: (void (__cdecl *)())S_StopAllSoundsC,
    pHelpString: nullptr,
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__stopsound__);
}

//------------------------------------------------------------------------------
// Address: 0x103102E0
// Name: _dynamic_initializer_for__soundlist__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__soundlist__()
{
  ConCommand::ConCommand(
    this: &soundlist,
    pName: "soundlist",
    callback: (void (__cdecl *)())S_SoundList,
    pHelpString: "List all known sounds.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__soundlist__);
}

//------------------------------------------------------------------------------
// Address: 0x10310310
// Name: _dynamic_initializer_for__soundinfo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__soundinfo__()
{
  ConCommand::ConCommand(
    this: &soundinfo,
    pName: "soundinfo",
    callback: (void (__cdecl *)())S_SoundInfo_f,
    pHelpString: "Describe the current sound device.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__soundinfo__);
}

//------------------------------------------------------------------------------
// Address: 0x10320C50
// Name: _dynamic_atexit_destructor_for__stopsound__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__stopsound__()
{
  ConCommand::~ConCommand(this: &stopsound);
}

//------------------------------------------------------------------------------
// Address: 0x10320C60
// Name: _dynamic_atexit_destructor_for__soundlist__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__soundlist__()
{
  ConCommand::~ConCommand(this: &soundlist);
}

//------------------------------------------------------------------------------
// Address: 0x10320C70
// Name: _dynamic_atexit_destructor_for__soundinfo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__soundinfo__()
{
  ConCommand::~ConCommand(this: &soundinfo);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10048010
// Name: public: virtual void CSosOperatorIterateAndMergeSpeakers::SetDefaults(void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorIterateAndMergeSpeakers::SetDefaults(
        CSosOperatorIterateAndMergeSpeakers *this,
        _DWORD *pVoidMem)
{
  pVoidMem[22] = 0;
  pVoidMem[23] = -1;
  pVoidMem[24] = 0;
  pVoidMem[30] = -1;
  pVoidMem[25] = 0;
  pVoidMem[31] = -1;
  pVoidMem[26] = 0;
  pVoidMem[32] = -1;
  pVoidMem[27] = 0;
  pVoidMem[33] = -1;
  pVoidMem[28] = 0;
  pVoidMem[34] = -1;
  pVoidMem[29] = 0;
  pVoidMem[35] = -1;
  pVoidMem[36] = 0;
  pVoidMem[37] = 0;
  pVoidMem[38] = 0;
  pVoidMem[39] = 0;
  pVoidMem[40] = 0;
  pVoidMem[41] = 0;
  pVoidMem[21] = 0;
  pVoidMem[19] = 8;
  pVoidMem[20] = -1;
}

//------------------------------------------------------------------------------
// Address: 0x100480B0
// Name: public: virtual void CSosOperatorIterateAndMergeSpeakers::Print(void __near *,class CSosOperatorStack __near *,int,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorIterateAndMergeSpeakers::Print(
        CSosOperatorIterateAndMergeSpeakers *this,
        CSosOperator_t *pVoidMem,
        CSosOperatorStack *pStack,
        const char *nOpIndex,
        int nLevel)
{
  CSosOperator::PrintBaseParams(this, pVoidMem, pStack, nOpIndex, nLevel);
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
    LoggingSystem_Log(
      a1: LOG_SND_OPERATORS,
      a2: LS_MESSAGE,
      a3: OpColor,
      a4: "%*sIterate Op: %s\n",
      nLevel,
      "    ",
      (const char *)&pVoidMem[1]);
}

//------------------------------------------------------------------------------
// Address: 0x10048110
// Name: public: virtual void CSosOperatorIterateAndMergeSpeakers::ParseKV(class CSosOperatorStack __near *,void __near *,class KeyValues __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorIterateAndMergeSpeakers::ParseKV(
        CSosOperatorIterateAndMergeSpeakers *this,
        CSosOperatorStack *pStack,
        char *pVoidMem,
        KeyValues *pOpKeys)
{
  KeyValues *i; // ebx
  const char *Name; // esi
  const char *String; // eax
  const char *v7; // edi

  for ( i = KeyValues::GetFirstSubKey(this: pOpKeys); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    Name = KeyValues::GetName(this: i);
    String = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: defaultValue);
    v7 = String;
    if ( Name != nullptr
      && *Name != 0
      && String != nullptr
      && *String != 0
      && CSosOperator::BaseParseKV(
           this,
           pStack,
           pStructMem: (CSosOperator_t *)pVoidMem,
           pParamString: Name,
           pValueString: String) == 0 )
    {
      if ( V_strcasecmp(s1: Name, s2: "iterate_operator") != 0 )
      {
        if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
          _LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: 1, a3: "Error: Unknown sound operator attribute %s\n", Name);
      }
      else
      {
        V_strncpy(pDest: pVoidMem + 12, pSrc: v7, maxLen: 64);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100481E0
// Name: public: virtual void CSosOperatorIterateAndMergeSpeakers::Execute(void __near *,struct channel_t __near *,class CScratchPad __near *,class CSosOperatorStack __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorIterateAndMergeSpeakers::Execute(
        CSosOperatorIterateAndMergeSpeakers *this,
        int pVoidMem,
        channel_t *pChannel,
        CScratchPad *pScratchPad,
        CSosOperatorStack *pStack,
        int nOpIndex)
{
  int v7; // edx
  int v8; // ecx
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  int nCurIndex; // [esp+0h] [ebp-8h]
  int nLastIndex; // [esp+10h] [ebp+8h]

  if ( pChannel != nullptr )
  {
    v7 = *(_DWORD *)(pVoidMem + 76);
    v8 = (int)*(float *)(pVoidMem + 84);
    nCurIndex = v8;
    nLastIndex = (int)*(float *)(pVoidMem + 88);
    if ( nLastIndex >= v7 )
      nLastIndex = v7;
    if ( v8 == 0 )
    {
      *(_DWORD *)(pVoidMem + 144) = 0;
      *(_DWORD *)(pVoidMem + 148) = 0;
      *(_DWORD *)(pVoidMem + 152) = 0;
      *(_DWORD *)(pVoidMem + 156) = 0;
      *(_DWORD *)(pVoidMem + 160) = 0;
      *(_DWORD *)(pVoidMem + 164) = 0;
    }
    v9 = *(float *)(pVoidMem + 96);
    if ( v9 <= *(float *)(pVoidMem + 144) )
      v9 = *(float *)(pVoidMem + 144);
    v10 = *(float *)(pVoidMem + 148);
    *(float *)(pVoidMem + 144) = v9;
    v11 = *(float *)(pVoidMem + 100);
    if ( v11 <= v10 )
      v11 = v10;
    v12 = *(float *)(pVoidMem + 152);
    *(float *)(pVoidMem + 148) = v11;
    v13 = *(float *)(pVoidMem + 104);
    if ( v13 <= v12 )
      v13 = v12;
    v14 = *(float *)(pVoidMem + 156);
    *(float *)(pVoidMem + 152) = v13;
    v15 = *(float *)(pVoidMem + 108);
    if ( v15 <= v14 )
      v15 = v14;
    v16 = *(float *)(pVoidMem + 160);
    *(float *)(pVoidMem + 156) = v15;
    v17 = *(float *)(pVoidMem + 112);
    if ( v17 <= v16 )
      v17 = v16;
    v18 = *(float *)(pVoidMem + 164);
    *(float *)(pVoidMem + 160) = v17;
    v19 = *(float *)(pVoidMem + 116);
    if ( v19 <= v18 )
      v19 = v18;
    *(float *)(pVoidMem + 164) = v19;
    if ( snd_sos_show_operator_updates.m_pParent != nullptr
      && snd_sos_show_operator_updates.m_pParent->m_Value.m_nValue != 0 )
    {
      this->Print(this, a2: (void *)pVoidMem, a3: pStack, a4: nOpIndex, a5: 0);
      v8 = nCurIndex;
    }
    if ( v8 >= nLastIndex )
    {
      *(_DWORD *)(pVoidMem + 84) = 0;
    }
    else
    {
      *(float *)(pVoidMem + 84) = (float)(v8 + 1);
      CSosOperatorStack::ExecuteIterator(
        this: pStack,
        pChannel,
        pScratchPad,
        pStopMemBlock: (const void *)pVoidMem,
        pOperatorName: (const char *)(pVoidMem + 12),
        pnOperatorIndex: (int *)(pVoidMem + 80));
    }
  }
  else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
  {
    _LoggingSystem_Log(
      a1: LOG_SND_OPERATORS,
      a2: 1,
      a3: "Error: Sound operator %s requires valid channel pointer, being called without one\n",
      pStack->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_pMemory[nOpIndex].m_Data.key);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100483B0
// Name: public: CSosOperatorIterateAndMergeSpeakers::CSosOperatorIterateAndMergeSpeakers(void)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorIterateAndMergeSpeakers *__thiscall CSosOperatorIterateAndMergeSpeakers::CSosOperatorIterateAndMergeSpeakers(
        CSosOperatorIterateAndMergeSpeakers *this)
{
  int v2; // eax
  int v3; // eax
  CSosOperatorSystem *SoundOperatorSystem; // eax
  int m_Size; // [esp-8h] [ebp-28h]
  int v7; // [esp-8h] [ebp-28h]
  CSosOperator::InputData_t inputData; // [esp+Ch] [ebp-14h] BYREF
  int nIndex; // [esp+1Ch] [ebp-4h] BYREF

  CSosOperator::CSosOperator(this);
  this->__vftable = (CSosOperatorIterateAndMergeSpeakers_vtbl *)&CSosOperatorIterateAndMergeSpeakers::`vftable';
  m_Size = this->m_vInputs.m_Size;
  inputData.m_nOffset = 88;
  inputData.m_nOffsetOffset = 92;
  inputData.m_Type = SO_FLOAT;
  inputData.m_nCount = 1;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: m_Size,
             src: &inputData);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_max_iterations", element: &nIndex);
  v2 = this->m_vOutputs.m_Size;
  inputData.m_nCount = 1;
  inputData.m_nOffsetOffset = 84;
  inputData.m_Type = SO_FLOAT;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: v2,
             src: (const Vector *)&inputData.m_nOffsetOffset);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output_index", element: &nIndex);
  v7 = this->m_vOutputs.m_Size;
  inputData.m_nOffsetOffset = 144;
  inputData.m_Type = SO_FLOAT;
  inputData.m_nCount = 6;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: v7,
             src: (const Vector *)&inputData.m_nOffsetOffset);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output", element: &nIndex);
  v3 = this->m_vInputs.m_Size;
  inputData.m_nCount = 6;
  inputData.m_nOffset = 96;
  inputData.m_nOffsetOffset = 120;
  inputData.m_Type = SO_FLOAT;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: v3,
             src: &inputData);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input", element: &nIndex);
  nIndex = (int)this;
  SoundOperatorSystem = CSosOperatorSystem::GetSoundOperatorSystem();
  CUtlDict<CSosOperator *,int>::Insert(
    this: &SoundOperatorSystem->m_vOperatorCollection,
    pName: "iterate_merge_speakers",
    element: (CSosOperator *const *)&nIndex);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10310460
// Name: _dynamic_initializer_for__speak__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__speak__()
{
  ConCommand::ConCommand(
    this: &speak,
    pName: "speak",
    callback: S_Say,
    pHelpString: "Play a constructed sentence.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__speak__);
}

//------------------------------------------------------------------------------
// Address: 0x10320E10
// Name: _dynamic_atexit_destructor_for__speak__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__speak__()
{
  ConCommand::~ConCommand(this: &speak);
}

//------------------------------------------------------------------------------
// Address: 0x10310490
// Name: _dynamic_initializer_for__stopsound__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__stopsound__()
{
  ConCommand::ConCommand(
    this: &stopsound,
    pName: "stopsound",
    callback: (void (__cdecl *)())S_StopAllSoundsC,
    pHelpString: nullptr,
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__stopsound__);
}

//------------------------------------------------------------------------------
// Address: 0x103104C0
// Name: _dynamic_initializer_for__soundlist__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__soundlist__()
{
  ConCommand::ConCommand(
    this: &soundlist,
    pName: "soundlist",
    callback: (void (__cdecl *)())S_SoundList,
    pHelpString: "List all known sounds.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__soundlist__);
}

//------------------------------------------------------------------------------
// Address: 0x103104F0
// Name: _dynamic_initializer_for__soundinfo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__soundinfo__()
{
  ConCommand::ConCommand(
    this: &soundinfo,
    pName: "soundinfo",
    callback: (void (__cdecl *)())S_SoundInfo_f,
    pHelpString: "Describe the current sound device.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__soundinfo__);
}

//------------------------------------------------------------------------------
// Address: 0x10320E20
// Name: _dynamic_atexit_destructor_for__stopsound__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__stopsound__()
{
  ConCommand::~ConCommand(this: &stopsound);
}

//------------------------------------------------------------------------------
// Address: 0x10320E30
// Name: _dynamic_atexit_destructor_for__soundlist__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__soundlist__()
{
  ConCommand::~ConCommand(this: &soundlist);
}

//------------------------------------------------------------------------------
// Address: 0x10320E40
// Name: _dynamic_atexit_destructor_for__soundinfo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__soundinfo__()
{
  ConCommand::~ConCommand(this: &soundinfo);
}

} // namespace engine_xlsp
