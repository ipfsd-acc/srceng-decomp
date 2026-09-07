// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/audio/private/snd_op_sys/sos_op_stop_entry.cpp
// Functions: 10
// ============================================================

#include "engine\audio\private\snd_op_sys\sos_op_stop_entry.h"

//------------------------------------------------------------------------------
// Address: 0x1004E6D0
// Name: public: virtual void CSosOperatorStopEntry::SetDefaults(void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorStopEntry::SetDefaults(CSosOperatorStopEntry *this, char *pVoidMem)
{
  V_strncpy(pDest: pVoidMem + 28, pSrc: defaultValue, maxLen: 64);
  V_strncpy(pDest: pVoidMem + 93, pSrc: defaultValue, maxLen: 64);
  *(_DWORD *)(pVoidMem + 157) = 0;
  *(_WORD *)(pVoidMem + 161) = 1;
  pVoidMem[92] = 0;
  *((_DWORD *)pVoidMem + 3) = 1065353216;
  *((_DWORD *)pVoidMem + 4) = -1;
  *((_DWORD *)pVoidMem + 5) = 0;
  *((_DWORD *)pVoidMem + 6) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1004E740
// Name: ChannelLongestElapsedTimeSortFunc
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl ChannelLongestElapsedTimeSortFunc(const int *nChannelIndexA, const int *nChannelIndexB)
{
  float nChannelIndexAa; // [esp+8h] [ebp+8h]

  nChannelIndexAa = S_GetElapsedTimeByGuid(guid: channels[*nChannelIndexA].guid);
  return nChannelIndexAa > S_GetElapsedTimeByGuid(guid: channels[*nChannelIndexB].guid);
}

//------------------------------------------------------------------------------
// Address: 0x1004E790
// Name: public: virtual void CSosOperatorStopEntry::Print(void __near *,class CSosOperatorStack __near *,int,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorStopEntry::Print(
        CSosOperatorStopEntry *this,
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
  const char *v10; // eax

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
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
  {
    v10 = "true";
    if ( BYTE1(pVoidMem[13].m_flExecuteOffset[0]) == 0 )
      v10 = "false";
    LoggingSystem_Log(
      a1: LOG_SND_OPERATORS,
      a2: LS_MESSAGE,
      a3: OpColor,
      a4: "%*sstop_oldest: %s\n",
      nLevel,
      "    ",
      v10);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004E970
// Name: public: virtual void CSosOperatorStopEntry::ParseKV(class CSosOperatorStack __near *,void __near *,class KeyValues __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorStopEntry::ParseKV(
        CSosOperatorStopEntry *this,
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
          if ( V_strcasecmp(s1: Name, s2: "match_sound") != 0 )
          {
            if ( V_strcasecmp(s1: Name, s2: "match_entity") != 0 )
            {
              if ( V_strcasecmp(s1: Name, s2: "match_channel") != 0 )
              {
                if ( V_strcasecmp(s1: Name, s2: "match_substring") != 0 )
                {
                  if ( V_strcasecmp(s1: Name, s2: "stop_oldest") != 0 )
                  {
                    if ( V_strcasecmp(s1: Name, s2: "stop_this_entry") != 0 )
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
                      pVoidMem[162] = V_strcasecmp(s1: v7, s2: "true") == 0;
                    }
                  }
                  else
                  {
                    pVoidMem[161] = V_strcasecmp(s1: v7, s2: "true") == 0;
                  }
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
            pVoidMem[157] = 1;
            V_strncpy(pDest: pVoidMem + 93, pSrc: v7, maxLen: 64);
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
// Address: 0x1004EC00
// Name: public: void CSosOperatorSystem::QueueStopChannel(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorSystem::QueueStopChannel(CSosOperatorSystem *this, int nChannelGuid)
{
  CTSQueue<StartSoundParams_t,0,1> *p_m_sosStopChannelQueue; // esi
  CTSQueue<StartSoundParams_t,0,1>::Node_t *v3; // eax

  p_m_sosStopChannelQueue = (CTSQueue<StartSoundParams_t,0,1> *)&this->m_sosStopChannelQueue;
  v3 = (CTSQueue<StartSoundParams_t,0,1>::Node_t *)CTSListBase::Pop(this: &this->m_sosStopChannelQueue.m_FreeNodes);
  if ( v3 != nullptr || (v3 = (CTSQueue<StartSoundParams_t,0,1>::Node_t *)MemAlloc_Alloc(nSize: 8u)) != nullptr )
  {
    v3->elem.userdata = nChannelGuid;
    CTSQueue<CFunctor *,0,1>::Push(this: p_m_sosStopChannelQueue, pNode: v3);
  }
  else
  {
    CTSQueue<CFunctor *,0,1>::Push(this: p_m_sosStopChannelQueue, pNode: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004EC60
// Name: public: virtual void CSosOperatorStopEntry::Execute(void __near *,struct channel_t __near *,class CScratchPad __near *,class CSosOperatorStack __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorStopEntry::Execute(
        CSosOperatorStopEntry *this,
        char *pVoidMem,
        channel_t *pChannel,
        CScratchPad *pScratchPad,
        CSosOperatorStack *pStack,
        int nOpIndex)
{
  bool v7; // zf
  const char *v8; // eax
  CSosOperatorSystem *v9; // eax
  char v10; // al
  char v11; // cl
  int m_nChannel; // edx
  char v13; // cl
  int m_nSoundSource; // edx
  _DWORD *v15; // edi
  int v16; // ebx
  int v17; // eax
  unsigned int v18; // edi
  __int16 v19; // ax
  const char *v20; // eax
  int v21; // eax
  int v22; // edi
  int m_nMatchInt1; // ecx
  _DWORD *v24; // eax
  ConVar *m_pParent; // eax
  float *v26; // ecx
  int v27; // esi
  const char *v28; // eax
  CTSQueue<StartSoundParams_t,0,1> *SoundOperatorSystem; // ebx
  TSLNodeBase_t *Next; // esi
  int DepthAndSequence; // eax
  CTSListBase *p_m_FreeNodes; // edi
  CTSQueue<StartSoundParams_t,0,1>::Node_t *v33; // eax
  double v34; // [esp+10h] [ebp-2E4h]
  double v35; // [esp+14h] [ebp-2E0h]
  int guid; // [esp+18h] [ebp-2DCh]
  CChannelList list; // [esp+24h] [ebp-2D0h] BYREF
  char pDest[28]; // [esp+1ACh] [ebp-148h] BYREF
  CSosEntryMatch sosChanMatch; // [esp+1C8h] [ebp-12Ch] BYREF
  CSosEntryMatch sosEntryMatch; // [esp+25Ch] [ebp-98h] BYREF
  int v41; // [esp+2F0h] [ebp-4h]
  int vMatchingIndices; // [esp+2FCh] [ebp+8h]
  int vMatchingIndices_4; // [esp+300h] [ebp+Ch]
  int vMatchingIndices_8; // [esp+304h] [ebp+10h]
  int vMatchingIndices_16; // [esp+30Ch] [ebp+18h]

  v7 = pVoidMem[162] == 0;
  *(_DWORD *)&sosEntryMatch.m_nMatchString2[59] = this;
  if ( v7 )
  {
    *(_DWORD *)&sosEntryMatch.m_nMatchString2[39] = -1;
    *(_DWORD *)&sosEntryMatch.m_nMatchString2[47] = -1;
    v10 = pVoidMem[92];
    sosChanMatch.m_nMatchString2[55] = 10;
    sosEntryMatch.m_nMatchString1[37] = 10;
    *(_WORD *)&sosEntryMatch.m_nMatchString2[36] = 0;
    sosEntryMatch.m_nMatchString2[43] = 0;
    sosEntryMatch.m_nMatchString2[51] = 0;
    sosEntryMatch.m_nMatchString1[36] = v10;
    V_strncpy(pDest: &sosChanMatch.m_nMatchString2[55], pSrc: pVoidMem + 28, maxLen: 64);
    sosEntryMatch.m_nMatchString2[36] = pVoidMem[157];
    V_strncpy(pDest: &sosEntryMatch.m_nMatchString1[37], pSrc: pVoidMem + 93, maxLen: 64);
    v11 = pVoidMem[160];
    sosEntryMatch.m_nMatchString2[37] = pVoidMem[158];
    m_nChannel = pScratchPad->m_nChannel;
    sosEntryMatch.m_nMatchString2[43] = v11;
    v13 = pVoidMem[159];
    *(_DWORD *)&sosEntryMatch.m_nMatchString2[39] = m_nChannel;
    m_nSoundSource = pScratchPad->m_nSoundSource;
    v15 = nullptr;
    sosEntryMatch.m_nMatchString2[51] = v13;
    v16 = 0;
    *(_DWORD *)&sosEntryMatch.m_nMatchString2[47] = m_nSoundSource;
    memset(&sosEntryMatch.m_nMatchInt1, 0, 16);
    v41 = 0;
    CActiveChannels::GetActiveChannels(this: &g_ActiveChannels, &list);
    v17 = 0;
    vMatchingIndices_8 = 0;
    vMatchingIndices = 0;
    if ( list.m_count > 0 )
    {
      do
      {
        *(_DWORD *)&sosEntryMatch.m_nMatchString2[63] = list.m_list[v17];
        v18 = 332 * *(_DWORD *)&sosEntryMatch.m_nMatchString2[63];
        v7 = dword_1042ECB8[83 * *(_DWORD *)&sosEntryMatch.m_nMatchString2[63]] == 0;
        *(_DWORD *)&sosEntryMatch.m_nMatchString2[55] = 332 * *(_DWORD *)&sosEntryMatch.m_nMatchString2[63];
        if ( !v7 && (pChannel == nullptr || &channels[v18 / 0x14C] != pChannel) )
        {
          v19 = word_1042ECC4[166 * *(_DWORD *)&sosEntryMatch.m_nMatchString2[63]];
          if ( v19 >= 0 )
          {
            pDest[0] = 10;
            *(_WORD *)&sosChanMatch.m_nMatchString1[36] = 2560;
            *(_WORD *)&sosChanMatch.m_nMatchString2[36] = 0;
            *(_DWORD *)&sosChanMatch.m_nMatchString2[39] = -1;
            sosChanMatch.m_nMatchString2[43] = 0;
            *(_DWORD *)&sosChanMatch.m_nMatchString2[47] = -1;
            sosChanMatch.m_nMatchString2[51] = 0;
            if ( sosEntryMatch.m_nMatchString1[36] != 0 )
            {
              v20 = g_pSoundEmitterSystem->GetSoundName(this: g_pSoundEmitterSystem, a2: v19);
              V_strncpy(pDest, pSrc: v20, maxLen: 64);
            }
            else
            {
              sosEntryMatch.m_nMatchString1[36] = 0;
            }
            if ( sosEntryMatch.m_nMatchString2[36] != 0 )
              CSfxTable::GetFileName(
                this: (CSfxTable *)dword_1042ECB8[v18 / 4],
                pOutBuf: &sosChanMatch.m_nMatchString1[37],
                bufLen: 0x40u);
            v21 = dword_1042ED58[v18 / 4];
            *(_DWORD *)&sosChanMatch.m_nMatchString2[39] = dword_1042ED5C[v18 / 4];
            *(_DWORD *)&sosChanMatch.m_nMatchString2[47] = v21;
            if ( CSosEntryMatch::IsAMatch(
                   this: (CSosEntryMatch *)&sosChanMatch.m_nMatchString2[55],
                   pEntryMatch: (CSosEntryMatch *)pDest) )
            {
              v22 = v16;
              if ( v16 + 1 > *(int *)&sosEntryMatch.m_bMatchInt1 )
              {
                CUtlMemory<INetMessage *,int>::Grow(
                  this: (CUtlMemory<S3RGBA,int> *)&sosEntryMatch.m_nMatchInt1,
                  num: v16 - *(_DWORD *)&sosEntryMatch.m_bMatchInt1 + 1);
                v16 = *(_DWORD *)&sosEntryMatch.m_bMatchInt2;
              }
              m_nMatchInt1 = sosEntryMatch.m_nMatchInt1;
              *(_DWORD *)&sosEntryMatch.m_bMatchInt2 = ++v16;
              v41 = sosEntryMatch.m_nMatchInt1;
              if ( v16 - v22 - 1 > 0 )
              {
                _V_memmove(
                  dest: (void *)(sosEntryMatch.m_nMatchInt1 + 4 * v22 + 4),
                  src: (const void *)(sosEntryMatch.m_nMatchInt1 + 4 * v22),
                  count: 4 * (v16 - v22 - 1));
                m_nMatchInt1 = sosEntryMatch.m_nMatchInt1;
              }
              v24 = (_DWORD *)(m_nMatchInt1 + 4 * v22);
              if ( v24 != nullptr )
                *v24 = *(_DWORD *)&sosEntryMatch.m_nMatchString2[63];
              if ( pChannel != nullptr
                && (channel_t *)((char *)channels + *(_DWORD *)&sosEntryMatch.m_nMatchString2[55]) == pChannel )
              {
                vMatchingIndices_8 = v22;
              }
            }
          }
        }
        v17 = vMatchingIndices + 1;
        vMatchingIndices = v17;
      }
      while ( v17 < list.m_count );
      v15 = (_DWORD *)sosEntryMatch.m_nMatchInt1;
    }
    *((float *)pVoidMem + 5) = (float)v16;
    *((float *)pVoidMem + 6) = (float)vMatchingIndices_8;
    m_pParent = snd_sos_show_operator_updates.m_pParent;
    if ( snd_sos_show_operator_updates.m_pParent != nullptr
      && snd_sos_show_operator_updates.m_pParent->m_Value.m_nValue != 0 )
    {
      (*(void (__thiscall **)(_DWORD, char *, CSosOperatorStack *, int, _DWORD))(**(_DWORD **)&sosEntryMatch.m_nMatchString2[59]
                                                                               + 16))(
        a1: *(_DWORD *)&sosEntryMatch.m_nMatchString2[59],
        a2: pVoidMem,
        a3: pStack,
        a4: nOpIndex,
        a5: 0);
      m_pParent = snd_sos_show_operator_updates.m_pParent;
    }
    v26 = (float *)(pVoidMem + 12);
    if ( v16 > (int)*((float *)pVoidMem + 3) )
    {
      if ( pVoidMem[161] != 0 )
      {
        CUtlVector<char *,CUtlMemory<char *,int>>::Sort(
          this: (CUtlVector<int,CUtlMemory<int,int> > *)&sosEntryMatch.m_nMatchInt1,
          pfnCompare: ChannelLongestElapsedTimeSortFunc);
        m_pParent = snd_sos_show_operator_updates.m_pParent;
        v26 = (float *)(pVoidMem + 12);
      }
      v27 = (int)*v26;
      vMatchingIndices_4 = v27;
      if ( v27 < v16 )
      {
        while ( 1 )
        {
          if ( m_pParent != nullptr
            && m_pParent->m_Value.m_nValue != 0
            && (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
          {
            v34 = S_GetElapsedTime(pChannel: &channels[v15[v27]]) * 0.001;
            v28 = (const char *)((int (__stdcall *)(_DWORD))g_pSoundEmitterSystem->GetSoundName)(a1: word_1042ECC4[166 * v15[v27]]);
            LoggingSystem_Log(
              a1: LOG_SND_OPERATORS,
              a2: LS_MESSAGE,
              a3: OpColor,
              a4: "%*sStopping: %s : elapsed time: %f.2\n",
              1,
              "    ",
              v28,
              v34);
          }
          vMatchingIndices_16 = channels[v15[v27]].guid;
          SoundOperatorSystem = (CTSQueue<StartSoundParams_t,0,1> *)CSosOperatorSystem::GetSoundOperatorSystem();
          Next = SoundOperatorSystem[12].m_FreeNodes.m_Head.value.Next;
          DepthAndSequence = SoundOperatorSystem[12].m_FreeNodes.m_Head.value32.DepthAndSequence;
          p_m_FreeNodes = &SoundOperatorSystem[12].m_FreeNodes;
          if ( Next != nullptr )
          {
            while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                                       a1: &SoundOperatorSystem[12].m_FreeNodes,
                                       a2: Next->Next,
                                       a3: DepthAndSequence - 1,
                                       a4: Next,
                                       a5: DepthAndSequence) == 0 )
            {
              _mm_pause();
              Next = p_m_FreeNodes->m_Head.value.Next;
              DepthAndSequence = SoundOperatorSystem[12].m_FreeNodes.m_Head.value32.DepthAndSequence;
              if ( p_m_FreeNodes->m_Head.value.Next == nullptr )
                goto LABEL_48;
            }
            v33 = (CTSQueue<StartSoundParams_t,0,1>::Node_t *)Next;
            *((_DWORD *)&Next->Next + 1) = vMatchingIndices_16;
          }
          else
          {
LABEL_48:
            v33 = (CTSQueue<StartSoundParams_t,0,1>::Node_t *)MemAlloc_Alloc(nSize: 8u);
            if ( v33 != nullptr )
              v33->elem.userdata = vMatchingIndices_16;
            else
              v33 = nullptr;
          }
          CTSQueue<CFunctor *,0,1>::Push(this: SoundOperatorSystem + 12, pNode: v33);
          v15 = (_DWORD *)sosEntryMatch.m_nMatchInt1;
          if ( ++vMatchingIndices_4 >= *(int *)&sosEntryMatch.m_bMatchInt2 )
            break;
          m_pParent = snd_sos_show_operator_updates.m_pParent;
          v27 = vMatchingIndices_4;
        }
      }
    }
    if ( sosEntryMatch.m_nMatchInt2 >= 0 && v15 != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v15);
  }
  else if ( pChannel != nullptr )
  {
    if ( snd_sos_show_operator_updates.m_pParent != nullptr
      && snd_sos_show_operator_updates.m_pParent->m_Value.m_nValue != 0 )
    {
      this->Print(this, a2: pVoidMem, a3: pStack, a4: nOpIndex, a5: 0);
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
      {
        v35 = S_GetElapsedTime(pChannel) * 0.001;
        v8 = g_pSoundEmitterSystem->GetSoundName(this: g_pSoundEmitterSystem, a2: pChannel->m_nSoundScriptHandle);
        LoggingSystem_Log(
          a1: LOG_SND_OPERATORS,
          a2: LS_MESSAGE,
          a3: OpColor,
          a4: "%*sStopping: %s : elapsed time: %f.2\n",
          1,
          "    ",
          v8,
          v35);
      }
    }
    guid = pChannel->guid;
    v9 = CSosOperatorSystem::GetSoundOperatorSystem();
    CSosOperatorSystem::QueueStopChannel(this: v9, nChannelGuid: guid);
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
// Address: 0x1004F170
// Name: public: CSosOperatorStopEntry::CSosOperatorStopEntry(void)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorStopEntry *__thiscall CSosOperatorStopEntry::CSosOperatorStopEntry(CSosOperatorStopEntry *this)
{
  CSosOperatorSystem *SoundOperatorSystem; // eax
  int m_Size; // [esp-8h] [ebp-28h]
  int v5; // [esp-8h] [ebp-28h]
  int v6; // [esp-8h] [ebp-28h]
  CSosOperator::OutputData_t outputData; // [esp+Ch] [ebp-14h] BYREF
  __int16 v8; // [esp+18h] [ebp-8h]
  int nIndex; // [esp+1Ch] [ebp-4h] BYREF

  CSosOperator::CSosOperator(this);
  this->__vftable = (CSosOperatorStopEntry_vtbl *)&CSosOperatorStopEntry::`vftable';
  v8 = 1;
  m_Size = this->m_vInputs.m_Size;
  outputData.m_nOffset = 12;
  outputData.m_Type = 16;
  *(_DWORD *)&outputData.m_nCount = 0;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: m_Size,
             src: (const CSosOperator::InputData_t *)&outputData);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_max_entries", element: &nIndex);
  v5 = this->m_vOutputs.m_Size;
  outputData.m_Type = 20;
  *(_DWORD *)&outputData.m_nCount = 0;
  v8 = 1;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: v5,
             src: (const Vector *)&outputData.m_Type);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output_entries_matching", element: &nIndex);
  v6 = this->m_vOutputs.m_Size;
  outputData.m_Type = 24;
  *(_DWORD *)&outputData.m_nCount = 0;
  v8 = 1;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: v6,
             src: (const Vector *)&outputData.m_Type);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output_this_matches_index", element: &nIndex);
  nIndex = (int)this;
  SoundOperatorSystem = CSosOperatorSystem::GetSoundOperatorSystem();
  CUtlDict<CSosOperator *,int>::Insert(
    this: &SoundOperatorSystem->m_vOperatorCollection,
    pName: "sys_stop_entries",
    element: (CSosOperator *const *)&nIndex);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1004F260
// Name: public: virtual unsigned int CSosOperatorStopEntry::GetSize(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CSosOperatorStopEntry::GetSize(CSosOperatorStopEntry *this)
{
  return 164;
}

//------------------------------------------------------------------------------
// Address: 0x10312D40
// Name: _dynamic_initializer_for__stop_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__stop_command__()
{
  ConCommand::ConCommand(
    this: &stop_command,
    pName: "stop",
    callback: stop,
    pHelpString: "Finish recording demo.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__stop_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10322410
// Name: _dynamic_atexit_destructor_for__stop_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__stop_command__()
{
  ConCommand::~ConCommand(this: &stop_command);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1004E4D0
// Name: public: virtual void CSosOperatorStopEntry::SetDefaults(void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorStopEntry::SetDefaults(CSosOperatorStopEntry *this, char *pVoidMem)
{
  V_strncpy(pDest: pVoidMem + 28, pSrc: defaultValue, maxLen: 64);
  V_strncpy(pDest: pVoidMem + 93, pSrc: defaultValue, maxLen: 64);
  *(_DWORD *)(pVoidMem + 157) = 0;
  *(_WORD *)(pVoidMem + 161) = 1;
  pVoidMem[92] = 0;
  *((_DWORD *)pVoidMem + 3) = 1065353216;
  *((_DWORD *)pVoidMem + 4) = -1;
  *((_DWORD *)pVoidMem + 5) = 0;
  *((_DWORD *)pVoidMem + 6) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1004E540
// Name: ChannelLongestElapsedTimeSortFunc
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl ChannelLongestElapsedTimeSortFunc(const int *nChannelIndexA, const int *nChannelIndexB)
{
  float nChannelIndexAa; // [esp+8h] [ebp+8h]

  nChannelIndexAa = S_GetElapsedTimeByGuid(guid: channels[*nChannelIndexA].guid);
  return nChannelIndexAa > S_GetElapsedTimeByGuid(guid: channels[*nChannelIndexB].guid);
}

//------------------------------------------------------------------------------
// Address: 0x1004E590
// Name: public: virtual void CSosOperatorStopEntry::Print(void __near *,class CSosOperatorStack __near *,int,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorStopEntry::Print(
        CSosOperatorStopEntry *this,
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
  const char *v10; // eax

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
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
  {
    v10 = "true";
    if ( BYTE1(pVoidMem[13].m_flExecuteOffset[0]) == 0 )
      v10 = "false";
    LoggingSystem_Log(
      a1: LOG_SND_OPERATORS,
      a2: LS_MESSAGE,
      a3: OpColor,
      a4: "%*sstop_oldest: %s\n",
      nLevel,
      "    ",
      v10);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004E770
// Name: public: virtual void CSosOperatorStopEntry::ParseKV(class CSosOperatorStack __near *,void __near *,class KeyValues __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorStopEntry::ParseKV(
        CSosOperatorStopEntry *this,
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
          if ( V_strcasecmp(s1: Name, s2: "match_sound") != 0 )
          {
            if ( V_strcasecmp(s1: Name, s2: "match_entity") != 0 )
            {
              if ( V_strcasecmp(s1: Name, s2: "match_channel") != 0 )
              {
                if ( V_strcasecmp(s1: Name, s2: "match_substring") != 0 )
                {
                  if ( V_strcasecmp(s1: Name, s2: "stop_oldest") != 0 )
                  {
                    if ( V_strcasecmp(s1: Name, s2: "stop_this_entry") != 0 )
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
                      pVoidMem[162] = V_strcasecmp(s1: v7, s2: "true") == 0;
                    }
                  }
                  else
                  {
                    pVoidMem[161] = V_strcasecmp(s1: v7, s2: "true") == 0;
                  }
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
            pVoidMem[157] = 1;
            V_strncpy(pDest: pVoidMem + 93, pSrc: v7, maxLen: 64);
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
// Address: 0x1004E980
// Name: public: void CSosOperatorSystem::QueueStopChannel(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorSystem::QueueStopChannel(CSosOperatorSystem *this, loopback_t *nChannelGuid)
{
  CTSQueue<StartSoundParams_t,0,1> *p_m_sosStopChannelQueue; // esi
  CTSQueue<loopback_t *,0,1>::Node_t *v3; // eax

  p_m_sosStopChannelQueue = (CTSQueue<StartSoundParams_t,0,1> *)&this->m_sosStopChannelQueue;
  v3 = (CTSQueue<loopback_t *,0,1>::Node_t *)CTSListBase::Pop(this: &this->m_sosStopChannelQueue.m_FreeNodes);
  if ( v3 != nullptr || (v3 = (CTSQueue<loopback_t *,0,1>::Node_t *)MemAlloc_Alloc(nSize: 8u)) != nullptr )
  {
    v3->elem = nChannelGuid;
    CTSQueue<CFunctor *,0,1>::Push(this: p_m_sosStopChannelQueue, pNode: v3);
  }
  else
  {
    CTSQueue<CFunctor *,0,1>::Push(this: p_m_sosStopChannelQueue, pNode: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004E9E0
// Name: public: virtual void CSosOperatorStopEntry::Execute(void __near *,struct channel_t __near *,class CScratchPad __near *,class CSosOperatorStack __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorStopEntry::Execute(
        CSosOperatorStopEntry *this,
        char *pVoidMem,
        channel_t *pChannel,
        CScratchPad *pScratchPad,
        CSosOperatorStack *pStack,
        int nOpIndex)
{
  bool v7; // zf
  const char *v8; // eax
  CSosOperatorSystem *v9; // eax
  char v10; // al
  char v11; // cl
  int m_nChannel; // edx
  char v13; // cl
  int m_nSoundSource; // edx
  int *v15; // edi
  int m_Size; // ebx
  int v17; // eax
  unsigned int v18; // edi
  __int16 v19; // ax
  const char *v20; // eax
  int v21; // eax
  int v22; // edi
  int *m_pMemory; // ecx
  int *v24; // eax
  ConVar *m_pParent; // eax
  float *v26; // ecx
  int v27; // esi
  const char *v28; // eax
  CTSQueue<StartSoundParams_t,0,1> *SoundOperatorSystem; // ebx
  TSLNodeBase_t *Next; // esi
  int DepthAndSequence; // eax
  CTSListBase *p_m_FreeNodes; // edi
  CTSQueue<loopback_t *,0,1>::Node_t *v33; // eax
  double v34; // [esp+10h] [ebp-2E4h]
  double v35; // [esp+14h] [ebp-2E0h]
  loopback_t *guid; // [esp+18h] [ebp-2DCh]
  CChannelList list; // [esp+24h] [ebp-2D0h] BYREF
  CSosEntryMatch sosChanMatch; // [esp+1ACh] [ebp-148h] BYREF
  CSosEntryMatch sosEntryMatch; // [esp+240h] [ebp-B4h] BYREF
  unsigned int v40; // [esp+2D4h] [ebp-20h]
  CSosOperatorStopEntry *v41; // [esp+2D8h] [ebp-1Ch]
  int ch_idx; // [esp+2DCh] [ebp-18h]
  CUtlVector<int,CUtlMemory<int,int> > vMatchingIndices; // [esp+2E0h] [ebp-14h] BYREF
  int i; // [esp+2FCh] [ebp+8h]
  channel_t *pChannela; // [esp+300h] [ebp+Ch]
  int nThisIndex; // [esp+304h] [ebp+10h]
  int nOpIndexa; // [esp+30Ch] [ebp+18h]

  v7 = pVoidMem[162] == 0;
  v41 = this;
  if ( v7 )
  {
    sosEntryMatch.m_nMatchInt1 = -1;
    sosEntryMatch.m_nMatchInt2 = -1;
    v10 = pVoidMem[92];
    sosEntryMatch.m_nMatchString1[0] = 10;
    sosEntryMatch.m_nMatchString2[0] = 10;
    *(_WORD *)&sosEntryMatch.m_bMatchString2 = 0;
    sosEntryMatch.m_bMatchInt1 = false;
    sosEntryMatch.m_bMatchInt2 = false;
    sosEntryMatch.m_bMatchString1 = v10;
    V_strncpy(pDest: sosEntryMatch.m_nMatchString1, pSrc: pVoidMem + 28, maxLen: 64);
    sosEntryMatch.m_bMatchString2 = pVoidMem[157];
    V_strncpy(pDest: sosEntryMatch.m_nMatchString2, pSrc: pVoidMem + 93, maxLen: 64);
    v11 = pVoidMem[160];
    sosEntryMatch.m_bMatchSubString = pVoidMem[158];
    m_nChannel = pScratchPad->m_nChannel;
    sosEntryMatch.m_bMatchInt1 = v11;
    v13 = pVoidMem[159];
    sosEntryMatch.m_nMatchInt1 = m_nChannel;
    m_nSoundSource = pScratchPad->m_nSoundSource;
    v15 = nullptr;
    sosEntryMatch.m_bMatchInt2 = v13;
    m_Size = 0;
    sosEntryMatch.m_nMatchInt2 = m_nSoundSource;
    memset(&vMatchingIndices, 0, sizeof(vMatchingIndices));
    CActiveChannels::GetActiveChannels(this: &g_ActiveChannels, &list);
    v17 = 0;
    nThisIndex = 0;
    i = 0;
    if ( list.m_count > 0 )
    {
      do
      {
        ch_idx = list.m_list[v17];
        v18 = 332 * ch_idx;
        v7 = dword_1042ECB8[83 * ch_idx] == 0;
        v40 = 332 * ch_idx;
        if ( !v7 && (pChannel == nullptr || &channels[v18 / 0x14C] != pChannel) )
        {
          v19 = word_1042ECC4[166 * ch_idx];
          if ( v19 >= 0 )
          {
            sosChanMatch.m_nMatchString1[0] = 10;
            *(_WORD *)&sosChanMatch.m_bMatchString1 = 2560;
            *(_WORD *)&sosChanMatch.m_bMatchString2 = 0;
            sosChanMatch.m_nMatchInt1 = -1;
            sosChanMatch.m_bMatchInt1 = false;
            sosChanMatch.m_nMatchInt2 = -1;
            sosChanMatch.m_bMatchInt2 = false;
            if ( sosEntryMatch.m_bMatchString1 )
            {
              v20 = g_pSoundEmitterSystem->GetSoundName(this: g_pSoundEmitterSystem, a2: v19);
              V_strncpy(pDest: sosChanMatch.m_nMatchString1, pSrc: v20, maxLen: 64);
            }
            else
            {
              sosEntryMatch.m_bMatchString1 = false;
            }
            if ( sosEntryMatch.m_bMatchString2 )
              CSfxTable::GetFileName(
                this: (CSfxTable *)dword_1042ECB8[v18 / 4],
                pOutBuf: sosChanMatch.m_nMatchString2,
                bufLen: 0x40u);
            v21 = dword_1042ED58[v18 / 4];
            sosChanMatch.m_nMatchInt1 = dword_1042ED5C[v18 / 4];
            sosChanMatch.m_nMatchInt2 = v21;
            if ( CSosEntryMatch::IsAMatch(this: &sosEntryMatch, pEntryMatch: &sosChanMatch) )
            {
              v22 = m_Size;
              if ( m_Size + 1 > vMatchingIndices.m_Memory.m_nAllocationCount )
              {
                CUtlMemory<INetMessage *,int>::Grow(
                  this: (CUtlMemory<S3RGBA,int> *)&vMatchingIndices,
                  num: m_Size - vMatchingIndices.m_Memory.m_nAllocationCount + 1);
                m_Size = vMatchingIndices.m_Size;
              }
              m_pMemory = vMatchingIndices.m_Memory.m_pMemory;
              vMatchingIndices.m_Size = ++m_Size;
              vMatchingIndices.m_pElements = vMatchingIndices.m_Memory.m_pMemory;
              if ( m_Size - v22 - 1 > 0 )
              {
                _V_memmove(
                  dest: &vMatchingIndices.m_Memory.m_pMemory[v22 + 1],
                  src: &vMatchingIndices.m_Memory.m_pMemory[v22],
                  count: 4 * (m_Size - v22 - 1));
                m_pMemory = vMatchingIndices.m_Memory.m_pMemory;
              }
              v24 = &m_pMemory[v22];
              if ( v24 != nullptr )
                *v24 = ch_idx;
              if ( pChannel != nullptr && &channels[v40 / 0x14C] == pChannel )
                nThisIndex = v22;
            }
          }
        }
        v17 = i + 1;
        i = v17;
      }
      while ( v17 < list.m_count );
      v15 = vMatchingIndices.m_Memory.m_pMemory;
    }
    *((float *)pVoidMem + 5) = (float)m_Size;
    *((float *)pVoidMem + 6) = (float)nThisIndex;
    m_pParent = snd_sos_show_operator_updates.m_pParent;
    if ( snd_sos_show_operator_updates.m_pParent != nullptr
      && snd_sos_show_operator_updates.m_pParent->m_Value.m_nValue != 0 )
    {
      v41->Print(this: v41, a2: pVoidMem, a3: pStack, a4: nOpIndex, a5: 0);
      m_pParent = snd_sos_show_operator_updates.m_pParent;
    }
    v26 = (float *)(pVoidMem + 12);
    if ( m_Size > (int)*((float *)pVoidMem + 3) )
    {
      if ( pVoidMem[161] != 0 )
      {
        CUtlVector<char *,CUtlMemory<char *,int>>::Sort(
          this: &vMatchingIndices,
          pfnCompare: (int (__cdecl *)(const void *, const void *))ChannelLongestElapsedTimeSortFunc);
        m_pParent = snd_sos_show_operator_updates.m_pParent;
        v26 = (float *)(pVoidMem + 12);
      }
      v27 = (int)*v26;
      pChannela = (channel_t *)v27;
      if ( v27 < m_Size )
      {
        while ( 1 )
        {
          if ( m_pParent != nullptr
            && m_pParent->m_Value.m_nValue != 0
            && (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
          {
            v34 = S_GetElapsedTime(pChannel: &channels[v15[v27]]) * 0.001;
            v28 = (const char *)((int (__stdcall *)(_DWORD))g_pSoundEmitterSystem->GetSoundName)(a1: word_1042ECC4[166 * v15[v27]]);
            LoggingSystem_Log(
              a1: LOG_SND_OPERATORS,
              a2: LS_MESSAGE,
              a3: OpColor,
              a4: "%*sStopping: %s : elapsed time: %f.2\n",
              1,
              "    ",
              v28,
              v34);
          }
          nOpIndexa = channels[v15[v27]].guid;
          SoundOperatorSystem = (CTSQueue<StartSoundParams_t,0,1> *)CSosOperatorSystem::GetSoundOperatorSystem();
          Next = SoundOperatorSystem[12].m_FreeNodes.m_Head.value.Next;
          DepthAndSequence = SoundOperatorSystem[12].m_FreeNodes.m_Head.value32.DepthAndSequence;
          p_m_FreeNodes = &SoundOperatorSystem[12].m_FreeNodes;
          if ( Next != nullptr )
          {
            while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                                       a1: &SoundOperatorSystem[12].m_FreeNodes,
                                       a2: Next->Next,
                                       a3: DepthAndSequence - 1,
                                       a4: Next,
                                       a5: DepthAndSequence) == 0 )
            {
              _mm_pause();
              Next = p_m_FreeNodes->m_Head.value.Next;
              DepthAndSequence = SoundOperatorSystem[12].m_FreeNodes.m_Head.value32.DepthAndSequence;
              if ( p_m_FreeNodes->m_Head.value.Next == nullptr )
                goto LABEL_48;
            }
            v33 = (CTSQueue<loopback_t *,0,1>::Node_t *)Next;
            *((_DWORD *)&Next->Next + 1) = nOpIndexa;
          }
          else
          {
LABEL_48:
            v33 = (CTSQueue<loopback_t *,0,1>::Node_t *)MemAlloc_Alloc(nSize: 8u);
            if ( v33 != nullptr )
              v33->elem = (loopback_t *)nOpIndexa;
            else
              v33 = nullptr;
          }
          CTSQueue<CFunctor *,0,1>::Push(this: SoundOperatorSystem + 12, pNode: v33);
          v15 = vMatchingIndices.m_Memory.m_pMemory;
          pChannela = (channel_t *)((char *)pChannela + 1);
          if ( (int)pChannela >= vMatchingIndices.m_Size )
            break;
          m_pParent = snd_sos_show_operator_updates.m_pParent;
          v27 = (int)pChannela;
        }
      }
    }
    if ( vMatchingIndices.m_Memory.m_nGrowSize >= 0 && v15 != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v15);
  }
  else if ( pChannel != nullptr )
  {
    if ( snd_sos_show_operator_updates.m_pParent != nullptr
      && snd_sos_show_operator_updates.m_pParent->m_Value.m_nValue != 0 )
    {
      this->Print(this, a2: pVoidMem, a3: pStack, a4: nOpIndex, a5: 0);
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
      {
        v35 = S_GetElapsedTime(pChannel) * 0.001;
        v8 = g_pSoundEmitterSystem->GetSoundName(this: g_pSoundEmitterSystem, a2: pChannel->m_nSoundScriptHandle);
        LoggingSystem_Log(
          a1: LOG_SND_OPERATORS,
          a2: LS_MESSAGE,
          a3: OpColor,
          a4: "%*sStopping: %s : elapsed time: %f.2\n",
          1,
          "    ",
          v8,
          v35);
      }
    }
    guid = (loopback_t *)pChannel->guid;
    v9 = CSosOperatorSystem::GetSoundOperatorSystem();
    CSosOperatorSystem::QueueStopChannel(this: v9, nChannelGuid: guid);
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
// Address: 0x1004EEF0
// Name: public: CSosOperatorStopEntry::CSosOperatorStopEntry(void)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorStopEntry *__thiscall CSosOperatorStopEntry::CSosOperatorStopEntry(CSosOperatorStopEntry *this)
{
  CSosOperatorSystem *SoundOperatorSystem; // eax
  int m_Size; // [esp-8h] [ebp-28h]
  int v5; // [esp-8h] [ebp-28h]
  int v6; // [esp-8h] [ebp-28h]
  CSosOperator::OutputData_t outputData; // [esp+Ch] [ebp-14h] BYREF
  __int16 v8; // [esp+18h] [ebp-8h]
  int nIndex; // [esp+1Ch] [ebp-4h] BYREF

  CSosOperator::CSosOperator(this);
  this->__vftable = (CSosOperatorStopEntry_vtbl *)&CSosOperatorStopEntry::`vftable';
  v8 = 1;
  m_Size = this->m_vInputs.m_Size;
  outputData.m_nOffset = 12;
  outputData.m_Type = 16;
  *(_DWORD *)&outputData.m_nCount = 0;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: m_Size,
             src: (const CSosOperator::InputData_t *)&outputData);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_max_entries", element: &nIndex);
  v5 = this->m_vOutputs.m_Size;
  outputData.m_Type = 20;
  *(_DWORD *)&outputData.m_nCount = 0;
  v8 = 1;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: v5,
             src: (const Vector *)&outputData.m_Type);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output_entries_matching", element: &nIndex);
  v6 = this->m_vOutputs.m_Size;
  outputData.m_Type = 24;
  *(_DWORD *)&outputData.m_nCount = 0;
  v8 = 1;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: v6,
             src: (const Vector *)&outputData.m_Type);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output_this_matches_index", element: &nIndex);
  nIndex = (int)this;
  SoundOperatorSystem = CSosOperatorSystem::GetSoundOperatorSystem();
  CUtlDict<CSosOperator *,int>::Insert(
    this: &SoundOperatorSystem->m_vOperatorCollection,
    pName: "sys_stop_entries",
    element: (CSosOperator *const *)&nIndex);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1004EFE0
// Name: public: virtual unsigned int CSosOperatorStopEntry::GetSize(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CSosOperatorStopEntry::GetSize(CSosOperatorStopEntry *this)
{
  return 164;
}

//------------------------------------------------------------------------------
// Address: 0x10312F20
// Name: _dynamic_initializer_for__stop_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__stop_command__()
{
  ConCommand::ConCommand(
    this: &stop_command,
    pName: "stop",
    callback: stop,
    pHelpString: "Finish recording demo.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__stop_command__);
}

//------------------------------------------------------------------------------
// Address: 0x103225E0
// Name: _dynamic_atexit_destructor_for__stop_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__stop_command__()
{
  ConCommand::~ConCommand(this: &stop_command);
}

} // namespace engine_xlsp
