// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/audio/private/snd_op_sys/sos_op_block_entry.cpp
// Functions: 6
// ============================================================

#include "engine\audio\private\snd_op_sys\sos_op_block_entry.h"

//------------------------------------------------------------------------------
// Address: 0x10046330
// Name: public: virtual void CSosOperatorBlockEntry::SetDefaults(void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorBlockEntry::SetDefaults(CSosOperatorBlockEntry *this, char *pVoidMem)
{
  V_strncpy(pDest: pVoidMem + 28, pSrc: defaultValue, maxLen: 64);
  V_strncpy(pDest: pVoidMem + 93, pSrc: defaultValue, maxLen: 64);
  pVoidMem[92] = 0;
  *(_DWORD *)(pVoidMem + 157) = 0;
  *((_DWORD *)pVoidMem + 41) = -1;
  *((_DWORD *)pVoidMem + 5) = 0;
  *((_DWORD *)pVoidMem + 6) = -1;
  *((_DWORD *)pVoidMem + 3) = 1065353216;
  *((_DWORD *)pVoidMem + 4) = -1;
}

//------------------------------------------------------------------------------
// Address: 0x100463A0
// Name: public: virtual void CSosOperatorBlockEntry::Print(void __near *,class CSosOperatorStack __near *,int,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorBlockEntry::Print(
        CSosOperatorBlockEntry *this,
        CSosOperator_t *pVoidMem,
        CSosOperatorStack *pStack,
        const char *nOpIndex,
        int nLevel)
{
  const char *m_flExecuteOffset; // eax
  const char *p_m_bHasExecuted; // eax
  const char *v7; // eax
  const char *v8; // eax
  const char *v9; // eax

  CSosOperator::PrintBaseParams(this, pVoidMem, pStack, nOpIndex, nLevel);
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
  {
    m_flExecuteOffset = (const char *)pVoidMem[2].m_flExecuteOffset;
    if ( !pVoidMem[7].m_bExecuteOnce )
      m_flExecuteOffset = "\"\"";
    LoggingSystem_Log(
      a1: LOG_SND_OPERATORS,
      a2: LS_MESSAGE,
      a3: OpColor,
      a4: "%*smatch_entry: %s\n",
      nLevel,
      "    ",
      m_flExecuteOffset);
  }
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
  {
    p_m_bHasExecuted = (const char *)&pVoidMem[7].m_bHasExecuted;
    if ( BYTE1(pVoidMem[13].m_flExecute[0]) == 0 )
      p_m_bHasExecuted = "\"\"";
    LoggingSystem_Log(
      a1: LOG_SND_OPERATORS,
      a2: LS_MESSAGE,
      a3: OpColor,
      a4: "%*smatch_sound: %s\n",
      nLevel,
      "    ",
      p_m_bHasExecuted);
  }
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
  {
    v7 = "true";
    if ( HIBYTE(pVoidMem[13].m_flExecute[0]) == 0 )
      v7 = "false";
    LoggingSystem_Log(
      a1: LOG_SND_OPERATORS,
      a2: LS_MESSAGE,
      a3: OpColor,
      a4: "%*smatch_entity: %s\n",
      nLevel,
      "    ",
      v7);
  }
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
  {
    v8 = "true";
    if ( HIBYTE(pVoidMem[13].m_flExecute[0]) == 0 )
      v8 = "false";
    LoggingSystem_Log(
      a1: LOG_SND_OPERATORS,
      a2: LS_MESSAGE,
      a3: OpColor,
      a4: "%*smatch_channel: %s\n",
      nLevel,
      "    ",
      v8);
  }
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
  {
    v9 = "true";
    if ( BYTE2(pVoidMem[13].m_flExecute[0]) == 0 )
      v9 = "false";
    LoggingSystem_Log(
      a1: LOG_SND_OPERATORS,
      a2: LS_MESSAGE,
      a3: OpColor,
      a4: "%*smatch_substring: %s\n",
      nLevel,
      "    ",
      v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10046530
// Name: public: virtual void CSosOperatorBlockEntry::ParseKV(class CSosOperatorStack __near *,void __near *,class KeyValues __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorBlockEntry::ParseKV(
        CSosOperatorBlockEntry *this,
        CSosOperatorStack *pStack,
        _BYTE *pVoidMem,
        KeyValues *pOpKeys)
{
  KeyValues *FirstSubKey; // edi
  const char *Name; // esi
  const char *String; // eax
  const char *v7; // edi
  KeyValues *pParams; // [esp+18h] [ebp+10h]

  FirstSubKey = KeyValues::GetFirstSubKey(this: pOpKeys);
  pParams = FirstSubKey;
  if ( FirstSubKey != nullptr )
  {
    while ( 1 )
    {
      Name = KeyValues::GetName(this: FirstSubKey);
      String = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: defaultValue);
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
        if ( V_strcasecmp(s1: Name, s2: "match_entry") != 0 )
        {
          if ( V_strcasecmp(s1: Name, s2: "match_entity") != 0 )
          {
            if ( V_strcasecmp(s1: Name, s2: "match_channel") != 0 )
            {
              if ( V_strcasecmp(s1: Name, s2: "match_substring") != 0 )
              {
                if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
                  _LoggingSystem_Log(
                    a1: LOG_SND_OPERATORS,
                    a2: 1,
                    a3: "Error: Unknown sound operator attribute %s\n",
                    Name);
              }
              else
              {
                pVoidMem[158] = V_strcasecmp(s1: v7, s2: "true") == 0;
              }
            }
            else
            {
              pVoidMem[160] = V_strcasecmp(s1: v7, s2: "true") == 0;
            }
          }
          else
          {
            pVoidMem[159] = V_strcasecmp(s1: v7, s2: "true") == 0;
          }
        }
        else
        {
          pVoidMem[92] = 1;
          V_strncpy(pDest: pVoidMem + 28, pSrc: v7, maxLen: 64);
        }
      }
      pParams = KeyValues::GetNextKey(this: pParams);
      if ( pParams == nullptr )
        break;
      FirstSubKey = pParams;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10047140
// Name: public: virtual void CSosOperatorBlockEntry::Execute(void __near *,struct channel_t __near *,class CScratchPad __near *,class CSosOperatorStack __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorBlockEntry::Execute(
        CSosOperatorBlockEntry *this,
        void *pVoidMem,
        channel_t *pChannel,
        CScratchPad *pScratchPad,
        CSosOperatorStack *pStack,
        int nOpIndex)
{
  CSosOperatorBlockEntry *v7; // esi
  CSosOperatorSystem *SoundOperatorSystem; // eax
  unsigned int FreeEntryIndex; // ebx
  CSosOperatorSystem *v10; // eax
  CSosManagedEntryMatch *EntryFromIndex; // esi
  char v12; // al
  CSosOperatorSystem *v13; // eax
  CSosManagedEntryMatch *v14; // eax
  double v15; // st7
  unsigned int v16; // [esp-4h] [ebp-14h]
  float pVoidMema; // [esp+18h] [ebp+8h]

  v7 = this;
  if ( *((int *)pVoidMem + 41) < 0 )
  {
    SoundOperatorSystem = CSosOperatorSystem::GetSoundOperatorSystem();
    FreeEntryIndex = CSosEntryMatchList::GetFreeEntryIndex(this: &SoundOperatorSystem->m_sosEntryBlockList);
    v10 = CSosOperatorSystem::GetSoundOperatorSystem();
    EntryFromIndex = CSosEntryMatchList::GetEntryFromIndex(this: &v10->m_sosEntryBlockList, nIndex: FreeEntryIndex);
    if ( EntryFromIndex == nullptr )
    {
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
        _LoggingSystem_Log(
          a1: LOG_SND_OPERATORS,
          a2: 1,
          a3: "Error: Operator %s, EntryMatchList has no free slots!\n",
          pStack->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_pMemory[nOpIndex].m_Data.key);
      return;
    }
    v12 = *((_BYTE *)pVoidMem + 92);
    *((_DWORD *)pVoidMem + 41) = FreeEntryIndex;
    EntryFromIndex->m_bMatchString1 = v12;
    V_strncpy(pDest: EntryFromIndex->m_nMatchString1, pSrc: (const char *)pVoidMem + 28, maxLen: 64);
    EntryFromIndex->m_bMatchSubString = *((_BYTE *)pVoidMem + 158);
    EntryFromIndex->m_bMatchInt1 = *((_BYTE *)pVoidMem + 160);
    EntryFromIndex->m_nMatchInt1 = pScratchPad->m_nChannel;
    EntryFromIndex->m_bMatchInt2 = *((_BYTE *)pVoidMem + 159);
    EntryFromIndex->m_nMatchInt2 = pScratchPad->m_nSoundSource;
    EntryFromIndex->m_flStartTime = g_pSoundServices->GetClientTime(this: g_pSoundServices);
    v7 = this;
  }
  v16 = *((_DWORD *)pVoidMem + 41);
  v13 = CSosOperatorSystem::GetSoundOperatorSystem();
  v14 = CSosEntryMatchList::GetEntryFromIndex(this: &v13->m_sosEntryBlockList, nIndex: v16);
  if ( v14 != nullptr )
  {
    v14->m_bActive = *((float *)pVoidMem + 3) > 0.0;
    pVoidMema = *((float *)pVoidMem + 5);
    if ( *((float *)pVoidMem + 5) < 0.0 )
      v15 = 0.0;
    else
      v15 = pVoidMema;
    v14->m_flDuration = v15;
    v14->m_bTimed = true;
  }
  if ( snd_sos_show_operator_updates.m_pParent != nullptr
    && snd_sos_show_operator_updates.m_pParent->m_Value.m_nValue != 0 )
  {
    v7->Print(this: v7, a2: pVoidMem, a3: pStack, a4: nOpIndex, a5: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10047420
// Name: public: CSosOperatorBlockEntry::CSosOperatorBlockEntry(void)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorBlockEntry *__thiscall CSosOperatorBlockEntry::CSosOperatorBlockEntry(CSosOperatorBlockEntry *this)
{
  int v2; // eax
  CSosOperatorSystem *SoundOperatorSystem; // eax
  int m_Size; // [esp-8h] [ebp-28h]
  CSosOperator::InputData_t inputData; // [esp+Ch] [ebp-14h] BYREF
  int nIndex; // [esp+1Ch] [ebp-4h] BYREF

  CSosOperator::CSosOperator(this);
  this->__vftable = (CSosOperatorBlockEntry_vtbl *)&CSosOperatorBlockEntry::`vftable';
  m_Size = this->m_vInputs.m_Size;
  inputData.m_nOffset = 20;
  inputData.m_nOffsetOffset = 24;
  inputData.m_Type = SO_FLOAT;
  inputData.m_nCount = 1;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: m_Size,
             src: &inputData);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_duration", element: &nIndex);
  v2 = this->m_vInputs.m_Size;
  inputData.m_nCount = 1;
  inputData.m_nOffset = 12;
  inputData.m_nOffsetOffset = 16;
  inputData.m_Type = SO_FLOAT;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: v2,
             src: &inputData);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_active", element: &nIndex);
  nIndex = (int)this;
  SoundOperatorSystem = CSosOperatorSystem::GetSoundOperatorSystem();
  CUtlDict<CSosOperator *,int>::Insert(
    this: &SoundOperatorSystem->m_vOperatorCollection,
    pName: "sys_block_entries",
    element: (CSosOperator *const *)&nIndex);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10048770
// Name: public: virtual unsigned int CSosOperatorBlockEntry::GetSize(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CSosOperatorBlockEntry::GetSize(CSosOperatorBlockEntry *this)
{
  return 168;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10046020
// Name: public: virtual void CSosOperatorBlockEntry::SetDefaults(void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorBlockEntry::SetDefaults(CSosOperatorBlockEntry *this, char *pVoidMem)
{
  V_strncpy(pDest: pVoidMem + 28, pSrc: defaultValue, maxLen: 64);
  V_strncpy(pDest: pVoidMem + 93, pSrc: defaultValue, maxLen: 64);
  pVoidMem[92] = 0;
  *(_DWORD *)(pVoidMem + 157) = 0;
  *((_DWORD *)pVoidMem + 41) = -1;
  *((_DWORD *)pVoidMem + 5) = 0;
  *((_DWORD *)pVoidMem + 6) = -1;
  *((_DWORD *)pVoidMem + 3) = 1065353216;
  *((_DWORD *)pVoidMem + 4) = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10046090
// Name: public: virtual void CSosOperatorBlockEntry::Print(void __near *,class CSosOperatorStack __near *,int,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorBlockEntry::Print(
        CSosOperatorBlockEntry *this,
        CSosOperator_t *pVoidMem,
        CSosOperatorStack *pStack,
        const char *nOpIndex,
        int nLevel)
{
  const char *m_flExecuteOffset; // eax
  const char *p_m_bHasExecuted; // eax
  const char *v7; // eax
  const char *v8; // eax
  const char *v9; // eax

  CSosOperator::PrintBaseParams(this, pVoidMem, pStack, nOpIndex, nLevel);
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
  {
    m_flExecuteOffset = (const char *)pVoidMem[2].m_flExecuteOffset;
    if ( !pVoidMem[7].m_bExecuteOnce )
      m_flExecuteOffset = "\"\"";
    LoggingSystem_Log(
      a1: LOG_SND_OPERATORS,
      a2: LS_MESSAGE,
      a3: OpColor,
      a4: "%*smatch_entry: %s\n",
      nLevel,
      "    ",
      m_flExecuteOffset);
  }
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
  {
    p_m_bHasExecuted = (const char *)&pVoidMem[7].m_bHasExecuted;
    if ( BYTE1(pVoidMem[13].m_flExecute[0]) == 0 )
      p_m_bHasExecuted = "\"\"";
    LoggingSystem_Log(
      a1: LOG_SND_OPERATORS,
      a2: LS_MESSAGE,
      a3: OpColor,
      a4: "%*smatch_sound: %s\n",
      nLevel,
      "    ",
      p_m_bHasExecuted);
  }
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
  {
    v7 = "true";
    if ( HIBYTE(pVoidMem[13].m_flExecute[0]) == 0 )
      v7 = "false";
    LoggingSystem_Log(
      a1: LOG_SND_OPERATORS,
      a2: LS_MESSAGE,
      a3: OpColor,
      a4: "%*smatch_entity: %s\n",
      nLevel,
      "    ",
      v7);
  }
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
  {
    v8 = "true";
    if ( HIBYTE(pVoidMem[13].m_flExecute[0]) == 0 )
      v8 = "false";
    LoggingSystem_Log(
      a1: LOG_SND_OPERATORS,
      a2: LS_MESSAGE,
      a3: OpColor,
      a4: "%*smatch_channel: %s\n",
      nLevel,
      "    ",
      v8);
  }
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
  {
    v9 = "true";
    if ( BYTE2(pVoidMem[13].m_flExecute[0]) == 0 )
      v9 = "false";
    LoggingSystem_Log(
      a1: LOG_SND_OPERATORS,
      a2: LS_MESSAGE,
      a3: OpColor,
      a4: "%*smatch_substring: %s\n",
      nLevel,
      "    ",
      v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10046220
// Name: public: virtual void CSosOperatorBlockEntry::ParseKV(class CSosOperatorStack __near *,void __near *,class KeyValues __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorBlockEntry::ParseKV(
        CSosOperatorBlockEntry *this,
        CSosOperatorStack *pStack,
        _BYTE *pVoidMem,
        KeyValues *pOpKeys)
{
  KeyValues *FirstSubKey; // edi
  const char *Name; // esi
  const char *String; // eax
  const char *v7; // edi
  KeyValues *pParams; // [esp+18h] [ebp+10h]

  FirstSubKey = KeyValues::GetFirstSubKey(this: pOpKeys);
  pParams = FirstSubKey;
  if ( FirstSubKey != nullptr )
  {
    while ( 1 )
    {
      Name = KeyValues::GetName(this: FirstSubKey);
      String = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: defaultValue);
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
        if ( V_strcasecmp(s1: Name, s2: "match_entry") != 0 )
        {
          if ( V_strcasecmp(s1: Name, s2: "match_entity") != 0 )
          {
            if ( V_strcasecmp(s1: Name, s2: "match_channel") != 0 )
            {
              if ( V_strcasecmp(s1: Name, s2: "match_substring") != 0 )
              {
                if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
                  _LoggingSystem_Log(
                    a1: LOG_SND_OPERATORS,
                    a2: 1,
                    a3: "Error: Unknown sound operator attribute %s\n",
                    Name);
              }
              else
              {
                pVoidMem[158] = V_strcasecmp(s1: v7, s2: "true") == 0;
              }
            }
            else
            {
              pVoidMem[160] = V_strcasecmp(s1: v7, s2: "true") == 0;
            }
          }
          else
          {
            pVoidMem[159] = V_strcasecmp(s1: v7, s2: "true") == 0;
          }
        }
        else
        {
          pVoidMem[92] = 1;
          V_strncpy(pDest: pVoidMem + 28, pSrc: v7, maxLen: 64);
        }
      }
      pParams = KeyValues::GetNextKey(this: pParams);
      if ( pParams == nullptr )
        break;
      FirstSubKey = pParams;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10046ED0
// Name: public: virtual void CSosOperatorBlockEntry::Execute(void __near *,struct channel_t __near *,class CScratchPad __near *,class CSosOperatorStack __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorBlockEntry::Execute(
        CSosOperatorBlockEntry *this,
        void *pVoidMem,
        channel_t *pChannel,
        CScratchPad *pScratchPad,
        CSosOperatorStack *pStack,
        int nOpIndex)
{
  CSosOperatorBlockEntry *v7; // esi
  CSosOperatorSystem *SoundOperatorSystem; // eax
  unsigned int FreeEntryIndex; // ebx
  CSosOperatorSystem *v10; // eax
  CSosManagedEntryMatch *EntryFromIndex; // esi
  char v12; // al
  CSosOperatorSystem *v13; // eax
  CSosManagedEntryMatch *v14; // eax
  double v15; // st7
  unsigned int v16; // [esp-4h] [ebp-14h]
  float pVoidMema; // [esp+18h] [ebp+8h]

  v7 = this;
  if ( *((int *)pVoidMem + 41) < 0 )
  {
    SoundOperatorSystem = CSosOperatorSystem::GetSoundOperatorSystem();
    FreeEntryIndex = CSosEntryMatchList::GetFreeEntryIndex(this: &SoundOperatorSystem->m_sosEntryBlockList);
    v10 = CSosOperatorSystem::GetSoundOperatorSystem();
    EntryFromIndex = CSosEntryMatchList::GetEntryFromIndex(this: &v10->m_sosEntryBlockList, nIndex: FreeEntryIndex);
    if ( EntryFromIndex == nullptr )
    {
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
        _LoggingSystem_Log(
          a1: LOG_SND_OPERATORS,
          a2: 1,
          a3: "Error: Operator %s, EntryMatchList has no free slots!\n",
          pStack->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_pMemory[nOpIndex].m_Data.key);
      return;
    }
    v12 = *((_BYTE *)pVoidMem + 92);
    *((_DWORD *)pVoidMem + 41) = FreeEntryIndex;
    EntryFromIndex->m_bMatchString1 = v12;
    V_strncpy(pDest: EntryFromIndex->m_nMatchString1, pSrc: (const char *)pVoidMem + 28, maxLen: 64);
    EntryFromIndex->m_bMatchSubString = *((_BYTE *)pVoidMem + 158);
    EntryFromIndex->m_bMatchInt1 = *((_BYTE *)pVoidMem + 160);
    EntryFromIndex->m_nMatchInt1 = pScratchPad->m_nChannel;
    EntryFromIndex->m_bMatchInt2 = *((_BYTE *)pVoidMem + 159);
    EntryFromIndex->m_nMatchInt2 = pScratchPad->m_nSoundSource;
    EntryFromIndex->m_flStartTime = g_pSoundServices->GetClientTime(this: g_pSoundServices);
    v7 = this;
  }
  v16 = *((_DWORD *)pVoidMem + 41);
  v13 = CSosOperatorSystem::GetSoundOperatorSystem();
  v14 = CSosEntryMatchList::GetEntryFromIndex(this: &v13->m_sosEntryBlockList, nIndex: v16);
  if ( v14 != nullptr )
  {
    v14->m_bActive = *((float *)pVoidMem + 3) > 0.0;
    pVoidMema = *((float *)pVoidMem + 5);
    if ( *((float *)pVoidMem + 5) < 0.0 )
      v15 = 0.0;
    else
      v15 = pVoidMema;
    v14->m_flDuration = v15;
    v14->m_bTimed = true;
  }
  if ( snd_sos_show_operator_updates.m_pParent != nullptr
    && snd_sos_show_operator_updates.m_pParent->m_Value.m_nValue != 0 )
  {
    v7->Print(this: v7, a2: pVoidMem, a3: pStack, a4: nOpIndex, a5: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100471B0
// Name: public: CSosOperatorBlockEntry::CSosOperatorBlockEntry(void)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorBlockEntry *__thiscall CSosOperatorBlockEntry::CSosOperatorBlockEntry(CSosOperatorBlockEntry *this)
{
  int v2; // eax
  CSosOperatorSystem *SoundOperatorSystem; // eax
  int m_Size; // [esp-8h] [ebp-28h]
  CSosOperator::InputData_t inputData; // [esp+Ch] [ebp-14h] BYREF
  int nIndex; // [esp+1Ch] [ebp-4h] BYREF

  CSosOperator::CSosOperator(this);
  this->__vftable = (CSosOperatorBlockEntry_vtbl *)&CSosOperatorBlockEntry::`vftable';
  m_Size = this->m_vInputs.m_Size;
  inputData.m_nOffset = 20;
  inputData.m_nOffsetOffset = 24;
  inputData.m_Type = SO_FLOAT;
  inputData.m_nCount = 1;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: m_Size,
             src: &inputData);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_duration", element: &nIndex);
  v2 = this->m_vInputs.m_Size;
  inputData.m_nCount = 1;
  inputData.m_nOffset = 12;
  inputData.m_nOffsetOffset = 16;
  inputData.m_Type = SO_FLOAT;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: v2,
             src: &inputData);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_active", element: &nIndex);
  nIndex = (int)this;
  SoundOperatorSystem = CSosOperatorSystem::GetSoundOperatorSystem();
  CUtlDict<CSosOperator *,int>::Insert(
    this: &SoundOperatorSystem->m_vOperatorCollection,
    pName: "sys_block_entries",
    element: (CSosOperator *const *)&nIndex);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10047270
// Name: public: virtual unsigned int CSosOperatorBlockEntry::GetSize(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CSosOperatorBlockEntry::GetSize(CSosOperatorBlockEntry *this)
{
  return 168;
}

} // namespace engine_xlsp
