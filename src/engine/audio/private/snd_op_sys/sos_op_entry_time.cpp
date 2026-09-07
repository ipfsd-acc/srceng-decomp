// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/audio/private/snd_op_sys/sos_op_entry_time.cpp
// Functions: 4
// ============================================================

#include "engine\audio\private\snd_op_sys\sos_op_entry_time.h"

//------------------------------------------------------------------------------
// Address: 0x10047D20
// Name: public: virtual void CSosOperatorEntryTime::SetDefaults(void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorEntryTime::SetDefaults(CSosOperatorEntryTime *this, char *pVoidMem)
{
  *((_DWORD *)pVoidMem + 3) = 0;
  *((_DWORD *)pVoidMem + 4) = 0;
  *(_QWORD *)(pVoidMem + 20) = 0;
  *((_DWORD *)pVoidMem + 8) = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10047D50
// Name: public: virtual void CSosOperatorEntryTime::ParseKV(class CSosOperatorStack __near *,void __near *,class KeyValues __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorEntryTime::ParseKV(
        CSosOperatorEntryTime *this,
        CSosOperatorStack *pStack,
        CSosOperator_t *pVoidMem,
        KeyValues *pOpKeys)
{
  KeyValues *i; // ebx
  const char *Name; // esi
  const char *String; // eax
  const char *v7; // edi
  int v8; // eax

  for ( i = KeyValues::GetFirstSubKey(this: pOpKeys); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    Name = KeyValues::GetName(this: i);
    String = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: defaultValue);
    v7 = String;
    if ( Name != nullptr
      && *Name != 0
      && String != nullptr
      && *String != 0
      && CSosOperator::BaseParseKV(this, pStack, pStructMem: pVoidMem, pParamString: Name, pValueString: String) == 0 )
    {
      if ( V_strcasecmp(s1: Name, s2: "entry") != 0 )
      {
        if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
          _LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: 1, a3: "Error: Unknown sound operator attribute %s\n", Name);
      }
      else
      {
        if ( g_pSoundEmitterSystem == nullptr )
        {
          DevWarning(a1: "Error: SoundEmitterSystem not initialized in engine!");
          return;
        }
        v8 = g_pSoundEmitterSystem->GetSoundIndex(this: g_pSoundEmitterSystem, a2: v7);
        *(_DWORD *)&pVoidMem[2].m_bExecuteOnce = v8;
        if ( !g_pSoundEmitterSystem->IsValidIndex(this: g_pSoundEmitterSystem, a2: v8) )
        {
          DevMsg(a1: "Error: Invalid SoundEntry index %i from entry %s", *(_DWORD *)&pVoidMem[2].m_bExecuteOnce, v7);
          return;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10047E80
// Name: public: virtual void CSosOperatorEntryTime::Execute(void __near *,struct channel_t __near *,class CScratchPad __near *,class CSosOperatorStack __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorEntryTime::Execute(
        CSosOperatorEntryTime *this,
        int *pVoidMem,
        channel_t *pChannel,
        CScratchPad *pScratchPad,
        CSosOperatorStack *pStack,
        int nOpIndex)
{
  channel_t *ChannelByGuid; // eax
  CSosOperatorStack *v7; // ebx
  channel_t *v8; // esi
  CSosOperatorStackList *m_pStackList; // ecx
  CSosOperatorStack *Stack; // ebx
  double v11; // st7

  if ( pVoidMem[8] <= -1 )
  {
    v7 = pStack;
    ChannelByGuid = S_FindChannelByGuid(guid: pStack->m_nChannelGuid);
  }
  else
  {
    ChannelByGuid = S_FindChannelByScriptHandle(nHandle: *((_WORD *)pVoidMem + 16));
    v7 = pStack;
  }
  v8 = ChannelByGuid;
  if ( ChannelByGuid != nullptr )
  {
    m_pStackList = ChannelByGuid->m_pStackList;
    if ( m_pStackList != nullptr )
    {
      Stack = CSosOperatorStackList::GetStack(this: m_pStackList, SosType: SOS_UPDATE);
      if ( Stack != nullptr )
        *((float *)pVoidMem + 5) = ((double (__thiscall *)(ISoundServices *))g_pSoundServices->GetHostTime)(a1: g_pSoundServices)
                                 - Stack->m_flStartTime;
      v7 = pStack;
    }
    *((float *)pVoidMem + 4) = S_GetElapsedTime(pChannel: v8) * 0.01;
    *((float *)pVoidMem + 3) = S_SoundDuration(pChannel: v8);
    if ( v7->m_flStopTime >= 0.0 )
      v11 = ((double (__thiscall *)(ISoundServices *))g_pSoundServices->GetHostTime)(a1: g_pSoundServices)
          - v7->m_flStopTime;
    else
      v11 = -1.0;
    *((float *)pVoidMem + 6) = v11;
    if ( snd_sos_show_operator_updates.m_pParent != nullptr
      && snd_sos_show_operator_updates.m_pParent->m_Value.m_nValue != 0 )
    {
      this->Print(this, a2: pVoidMem, a3: v7, a4: nOpIndex, a5: 0);
    }
  }
  else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
  {
    _LoggingSystem_Log(
      a1: LOG_SND_OPERATORS,
      a2: 1,
      a3: "Error: Sound operator %s requires valid channel pointer, being called without one\n",
      v7->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_pMemory[nOpIndex].m_Data.key);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10047FA0
// Name: public: CSosOperatorEntryTime::CSosOperatorEntryTime(void)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorEntryTime *__thiscall CSosOperatorEntryTime::CSosOperatorEntryTime(CSosOperatorEntryTime *this)
{
  int v2; // eax
  CSosOperatorSystem *SoundOperatorSystem; // eax
  int m_Size; // [esp-8h] [ebp-24h]
  int v6; // [esp-8h] [ebp-24h]
  int v7; // [esp-8h] [ebp-24h]
  CSosOperator::OutputData_t outputData; // [esp+Ch] [ebp-10h] BYREF
  int nIndex; // [esp+18h] [ebp-4h] BYREF

  CSosOperator::CSosOperator(this);
  this->__vftable = (CSosOperatorEntryTime_vtbl *)&CSosOperatorEntryTime::`vftable';
  m_Size = this->m_vOutputs.m_Size;
  outputData.m_nOffset = 20;
  outputData.m_Type = SO_FLOAT;
  outputData.m_nCount = 1;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: m_Size,
             src: (const Vector *)&outputData);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output_entry_elapsed", element: &nIndex);
  v2 = this->m_vOutputs.m_Size;
  outputData.m_nCount = 1;
  outputData.m_nOffset = 16;
  outputData.m_Type = SO_FLOAT;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: v2,
             src: (const Vector *)&outputData);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output_sound_elapsed", element: &nIndex);
  v6 = this->m_vOutputs.m_Size;
  outputData.m_nOffset = 24;
  outputData.m_Type = SO_FLOAT;
  outputData.m_nCount = 1;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: v6,
             src: (const Vector *)&outputData);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output_stop_elapsed", element: &nIndex);
  v7 = this->m_vOutputs.m_Size;
  outputData.m_nOffset = 12;
  outputData.m_Type = SO_FLOAT;
  outputData.m_nCount = 1;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: v7,
             src: (const Vector *)&outputData);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output_sound_duration", element: &nIndex);
  nIndex = (int)this;
  SoundOperatorSystem = CSosOperatorSystem::GetSoundOperatorSystem();
  CUtlDict<CSosOperator *,int>::Insert(
    this: &SoundOperatorSystem->m_vOperatorCollection,
    pName: "get_entry_time",
    element: (CSosOperator *const *)&nIndex);
  return this;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10047A90
// Name: public: virtual void CSosOperatorEntryTime::SetDefaults(void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorEntryTime::SetDefaults(CSosOperatorEntryTime *this, char *pVoidMem)
{
  *((_DWORD *)pVoidMem + 3) = 0;
  *((_DWORD *)pVoidMem + 4) = 0;
  *(_QWORD *)(pVoidMem + 20) = 0;
  *((_DWORD *)pVoidMem + 8) = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10047AC0
// Name: public: virtual void CSosOperatorEntryTime::ParseKV(class CSosOperatorStack __near *,void __near *,class KeyValues __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorEntryTime::ParseKV(
        CSosOperatorEntryTime *this,
        CSosOperatorStack *pStack,
        CSosOperator_t *pVoidMem,
        KeyValues *pOpKeys)
{
  KeyValues *i; // ebx
  const char *Name; // esi
  const char *String; // eax
  const char *v7; // edi
  int v8; // eax

  for ( i = KeyValues::GetFirstSubKey(this: pOpKeys); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    Name = KeyValues::GetName(this: i);
    String = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: defaultValue);
    v7 = String;
    if ( Name != nullptr
      && *Name != 0
      && String != nullptr
      && *String != 0
      && CSosOperator::BaseParseKV(this, pStack, pStructMem: pVoidMem, pParamString: Name, pValueString: String) == 0 )
    {
      if ( V_strcasecmp(s1: Name, s2: "entry") != 0 )
      {
        if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
          _LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: 1, a3: "Error: Unknown sound operator attribute %s\n", Name);
      }
      else
      {
        if ( g_pSoundEmitterSystem == nullptr )
        {
          DevWarning(a1: "Error: SoundEmitterSystem not initialized in engine!");
          return;
        }
        v8 = g_pSoundEmitterSystem->GetSoundIndex(this: g_pSoundEmitterSystem, a2: v7);
        *(_DWORD *)&pVoidMem[2].m_bExecuteOnce = v8;
        if ( !g_pSoundEmitterSystem->IsValidIndex(this: g_pSoundEmitterSystem, a2: v8) )
        {
          DevMsg(a1: "Error: Invalid SoundEntry index %i from entry %s", *(_DWORD *)&pVoidMem[2].m_bExecuteOnce, v7);
          return;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10047BF0
// Name: public: virtual void CSosOperatorEntryTime::Execute(void __near *,struct channel_t __near *,class CScratchPad __near *,class CSosOperatorStack __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorEntryTime::Execute(
        CSosOperatorEntryTime *this,
        int *pVoidMem,
        channel_t *pChannel,
        CScratchPad *pScratchPad,
        CSosOperatorStack *pStack,
        int nOpIndex)
{
  channel_t *ChannelByGuid; // eax
  CSosOperatorStack *v7; // ebx
  channel_t *v8; // esi
  CSosOperatorStackList *m_pStackList; // ecx
  CSosOperatorStack *Stack; // ebx
  double v11; // st7

  if ( pVoidMem[8] <= -1 )
  {
    v7 = pStack;
    ChannelByGuid = S_FindChannelByGuid(guid: pStack->m_nChannelGuid);
  }
  else
  {
    ChannelByGuid = S_FindChannelByScriptHandle(nHandle: *((_WORD *)pVoidMem + 16));
    v7 = pStack;
  }
  v8 = ChannelByGuid;
  if ( ChannelByGuid != nullptr )
  {
    m_pStackList = ChannelByGuid->m_pStackList;
    if ( m_pStackList != nullptr )
    {
      Stack = CSosOperatorStackList::GetStack(this: m_pStackList, SosType: SOS_UPDATE);
      if ( Stack != nullptr )
        *((float *)pVoidMem + 5) = ((double (__thiscall *)(ISoundServices *))g_pSoundServices->GetHostTime)(a1: g_pSoundServices)
                                 - Stack->m_flStartTime;
      v7 = pStack;
    }
    *((float *)pVoidMem + 4) = S_GetElapsedTime(pChannel: v8) * 0.01;
    *((float *)pVoidMem + 3) = S_SoundDuration(pChannel: v8);
    if ( v7->m_flStopTime >= 0.0 )
      v11 = ((double (__thiscall *)(ISoundServices *))g_pSoundServices->GetHostTime)(a1: g_pSoundServices)
          - v7->m_flStopTime;
    else
      v11 = -1.0;
    *((float *)pVoidMem + 6) = v11;
    if ( snd_sos_show_operator_updates.m_pParent != nullptr
      && snd_sos_show_operator_updates.m_pParent->m_Value.m_nValue != 0 )
    {
      this->Print(this, a2: pVoidMem, a3: v7, a4: nOpIndex, a5: 0);
    }
  }
  else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
  {
    _LoggingSystem_Log(
      a1: LOG_SND_OPERATORS,
      a2: 1,
      a3: "Error: Sound operator %s requires valid channel pointer, being called without one\n",
      v7->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_pMemory[nOpIndex].m_Data.key);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10047D10
// Name: public: CSosOperatorEntryTime::CSosOperatorEntryTime(void)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorEntryTime *__thiscall CSosOperatorEntryTime::CSosOperatorEntryTime(CSosOperatorEntryTime *this)
{
  int v2; // eax
  CSosOperatorSystem *SoundOperatorSystem; // eax
  int m_Size; // [esp-8h] [ebp-24h]
  int v6; // [esp-8h] [ebp-24h]
  int v7; // [esp-8h] [ebp-24h]
  CSosOperator::OutputData_t outputData; // [esp+Ch] [ebp-10h] BYREF
  int nIndex; // [esp+18h] [ebp-4h] BYREF

  CSosOperator::CSosOperator(this);
  this->__vftable = (CSosOperatorEntryTime_vtbl *)&CSosOperatorEntryTime::`vftable';
  m_Size = this->m_vOutputs.m_Size;
  outputData.m_nOffset = 20;
  outputData.m_Type = SO_FLOAT;
  outputData.m_nCount = 1;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: m_Size,
             src: (const Vector *)&outputData);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output_entry_elapsed", element: &nIndex);
  v2 = this->m_vOutputs.m_Size;
  outputData.m_nCount = 1;
  outputData.m_nOffset = 16;
  outputData.m_Type = SO_FLOAT;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: v2,
             src: (const Vector *)&outputData);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output_sound_elapsed", element: &nIndex);
  v6 = this->m_vOutputs.m_Size;
  outputData.m_nOffset = 24;
  outputData.m_Type = SO_FLOAT;
  outputData.m_nCount = 1;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: v6,
             src: (const Vector *)&outputData);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output_stop_elapsed", element: &nIndex);
  v7 = this->m_vOutputs.m_Size;
  outputData.m_nOffset = 12;
  outputData.m_Type = SO_FLOAT;
  outputData.m_nCount = 1;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: v7,
             src: (const Vector *)&outputData);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output_sound_duration", element: &nIndex);
  nIndex = (int)this;
  SoundOperatorSystem = CSosOperatorSystem::GetSoundOperatorSystem();
  CUtlDict<CSosOperator *,int>::Insert(
    this: &SoundOperatorSystem->m_vOperatorCollection,
    pName: "get_entry_time",
    element: (CSosOperator *const *)&nIndex);
  return this;
}

} // namespace engine_xlsp
