// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/audio/private/snd_op_sys/sos_op_output.cpp
// Functions: 6
// ============================================================

#include "engine\audio\private\snd_op_sys\sos_op_output.h"

//------------------------------------------------------------------------------
// Address: 0x1004C230
// Name: public: virtual void CSosOperatorOutput::SetDefaults(void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorOutput::SetDefaults(CSosOperatorOutput *this, _DWORD *pVoidMem)
{
  pVoidMem[3] = 0;
  pVoidMem[4] = -1;
  pVoidMem[5] = 0;
  pVoidMem[8] = -1;
  pVoidMem[6] = 0;
  pVoidMem[9] = -1;
  pVoidMem[7] = 0;
  pVoidMem[10] = -1;
  pVoidMem[11] = 0;
  pVoidMem[17] = -1;
  pVoidMem[12] = 0;
  pVoidMem[18] = -1;
  pVoidMem[13] = 0;
  pVoidMem[19] = -1;
  pVoidMem[14] = 0;
  pVoidMem[20] = -1;
  pVoidMem[15] = 0;
  pVoidMem[21] = -1;
  pVoidMem[16] = 0;
  pVoidMem[22] = -1;
  pVoidMem[23] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1004C2A0
// Name: public: virtual void CSosOperatorOutput::Print(void __near *,class CSosOperatorStack __near *,int,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorOutput::Print(
        CSosOperatorOutput *this,
        CSosOperator_t *pVoidMem,
        CSosOperatorStack *pStack,
        const char *nOpIndex,
        int nLevel)
{
  const char *v5; // esi

  CSosOperator::PrintBaseParams(this, pVoidMem, pStack, nOpIndex, nLevel);
  v5 = "none";
  switch ( *(_DWORD *)&pVoidMem[7].m_bExecuteOnce )
  {
    case 1:
      v5 = "volume";
      break;
    case 2:
      v5 = "dsp";
      break;
    case 3:
      v5 = "position";
      break;
    case 4:
      v5 = "speakers";
      break;
    case 5:
      v5 = "facing";
      break;
    case 6:
      v5 = "distvar";
      break;
    case 7:
      v5 = "pitch";
      break;
    case 8:
      v5 = "delay";
      break;
    case 9:
      v5 = "stop_hold";
      break;
    case 0xA:
      v5 = "mixlayer_trigger";
      break;
    case 0xB:
      v5 = "save_restore";
      break;
    case 0xC:
      v5 = "block_start";
      break;
    default:
      break;
  }
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
    LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: LS_MESSAGE, a3: OpColor, a4: "%*sOutput: %s\n", nLevel, "    ", v5);
}

//------------------------------------------------------------------------------
// Address: 0x1004C3A0
// Name: public: virtual void CSosOperatorOutput::ParseKV(class CSosOperatorStack __near *,void __near *,class KeyValues __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorOutput::ParseKV(
        CSosOperatorOutput *this,
        CSosOperatorStack *pStack,
        CSosOperator_t *pVoidMem,
        KeyValues *pOpKeys)
{
  KeyValues *FirstSubKey; // esi
  const char *Name; // edi
  const char *String; // eax
  const char *v7; // esi
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
        && CSosOperator::BaseParseKV(this, pStack, pStructMem: pVoidMem, pParamString: Name, pValueString: String) == 0 )
      {
        if ( V_strcasecmp(s1: Name, s2: "output") != 0 )
        {
          if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
            _LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: 1, a3: "Error: Unknown sound operator attribute %s\n", Name);
        }
        else if ( V_strcasecmp(s1: v7, s2: "volume") != 0 )
        {
          if ( V_strcasecmp(s1: v7, s2: "dsp") != 0 )
          {
            if ( V_strcasecmp(s1: v7, s2: "position") != 0 )
            {
              if ( V_strcasecmp(s1: v7, s2: "speakers") != 0 )
              {
                if ( V_strcasecmp(s1: v7, s2: "facing") != 0 )
                {
                  if ( V_strcasecmp(s1: v7, s2: "distvar") != 0 )
                  {
                    if ( V_strcasecmp(s1: v7, s2: "pitch") != 0 )
                    {
                      if ( V_strcasecmp(s1: v7, s2: "delay") != 0 )
                      {
                        if ( V_strcasecmp(s1: v7, s2: "stop_hold") != 0 )
                        {
                          if ( V_strcasecmp(s1: v7, s2: "mixlayer_trigger") != 0 )
                          {
                            if ( V_strcasecmp(s1: v7, s2: "save_restore") != 0 )
                            {
                              if ( V_strcasecmp(s1: v7, s2: "block_start") == 0 )
                                *(_DWORD *)&pVoidMem[7].m_bExecuteOnce = 12;
                            }
                            else
                            {
                              *(_DWORD *)&pVoidMem[7].m_bExecuteOnce = 11;
                            }
                          }
                          else
                          {
                            *(_DWORD *)&pVoidMem[7].m_bExecuteOnce = 10;
                          }
                        }
                        else
                        {
                          *(_DWORD *)&pVoidMem[7].m_bExecuteOnce = 9;
                        }
                      }
                      else
                      {
                        *(_DWORD *)&pVoidMem[7].m_bExecuteOnce = 8;
                      }
                    }
                    else
                    {
                      *(_DWORD *)&pVoidMem[7].m_bExecuteOnce = 7;
                    }
                  }
                  else
                  {
                    *(_DWORD *)&pVoidMem[7].m_bExecuteOnce = 6;
                  }
                }
                else
                {
                  *(_DWORD *)&pVoidMem[7].m_bExecuteOnce = 5;
                }
              }
              else
              {
                *(_DWORD *)&pVoidMem[7].m_bExecuteOnce = 4;
              }
            }
            else
            {
              *(_DWORD *)&pVoidMem[7].m_bExecuteOnce = 3;
            }
          }
          else
          {
            *(_DWORD *)&pVoidMem[7].m_bExecuteOnce = 2;
          }
        }
        else
        {
          *(_DWORD *)&pVoidMem[7].m_bExecuteOnce = 1;
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
// Address: 0x1004C5E0
// Name: public: virtual void CSosOperatorOutput::Execute(void __near *,struct channel_t __near *,class CScratchPad __near *,class CSosOperatorStack __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorOutput::Execute(
        CSosOperatorOutput *this,
        char *pVoidMem,
        channel_t *pChannel,
        CScratchPad *pScratchPad,
        CSosOperatorStack *pStack,
        int nOpIndex)
{
  int v7; // ecx
  SOSStopType_t m_stopType; // eax
  SOSStopType_t v9; // eax

  v7 = *((_DWORD *)pVoidMem + 23);
  switch ( v7 )
  {
    case 8:
      pScratchPad->m_flDelay = *((float *)pVoidMem + 3);
      goto LABEL_25;
    case 9:
      m_stopType = pStack->m_stopType;
      if ( m_stopType != SOS_STOP_NONE && m_stopType != SOS_STOP_FORCE )
      {
        v9 = SOS_STOP_HOLD;
        if ( *((float *)pVoidMem + 3) <= 0.0 )
          v9 = SOS_STOP_NORM;
        CSosOperatorStack::SetStopType(this: pStack, stopType: v9);
      }
      goto LABEL_25;
    case 12:
      pScratchPad->m_bBlockStart = *((float *)pVoidMem + 3) > 0.0;
LABEL_25:
      if ( snd_sos_show_operator_updates.m_pParent != nullptr
        && snd_sos_show_operator_updates.m_pParent->m_Value.m_nValue != 0 )
      {
        this->Print(this, a2: pVoidMem, a3: pStack, a4: nOpIndex, a5: 0);
      }
      return;
    default:
      break;
  }
  if ( pChannel != nullptr )
  {
    switch ( v7 )
    {
      case 2:
        pChannel->dspmix = *((float *)pVoidMem + 3);
        break;
      case 3:
        pChannel->origin = *(Vector *)(pVoidMem + 20);
        break;
      case 4:
        ChannelSetVolTargets(pch: pChannel, pvolumes: (float *)pVoidMem + 11, ivol_offset: 0, cvol: 6);
        break;
      case 5:
        pChannel->dspface = (float)(*((float *)pVoidMem + 3) * 2.0) - 1.0;
        break;
      case 6:
        pChannel->distmix = *((float *)pVoidMem + 3);
        break;
      case 7:
        pChannel->basePitch = (int)(float)(*((float *)pVoidMem + 3) * 100.0);
        pChannel->pitch = *((float *)pVoidMem + 3);
        break;
      case 10:
        pChannel->last_vol = *((float *)pVoidMem + 3);
        break;
      case 11:
        *((_BYTE *)&pChannel->flags + 2) ^= ((*((float *)pVoidMem + 3) > 0.0) ^ *((_BYTE *)&pChannel->flags + 2)) & 1;
        break;
      default:
        goto LABEL_25;
    }
    goto LABEL_25;
  }
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
    _LoggingSystem_Log(
      a1: LOG_SND_OPERATORS,
      a2: 1,
      a3: "Error: Sound operator %s requires valid channel pointer, being called without one\n",
      pStack->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_pMemory[nOpIndex].m_Data.key);
}

//------------------------------------------------------------------------------
// Address: 0x1004C7F0
// Name: public: CSosOperatorOutput::CSosOperatorOutput(void)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorOutput *__thiscall CSosOperatorOutput::CSosOperatorOutput(CSosOperatorOutput *this)
{
  int v2; // eax
  CSosOperatorSystem *SoundOperatorSystem; // eax
  int m_Size; // [esp-8h] [ebp-28h]
  int v6; // [esp-8h] [ebp-28h]
  CSosOperator::InputData_t inputData; // [esp+Ch] [ebp-14h] BYREF
  int nIndex; // [esp+1Ch] [ebp-4h] BYREF

  CSosOperator::CSosOperator(this);
  this->__vftable = (CSosOperatorOutput_vtbl *)&CSosOperatorOutput::`vftable';
  m_Size = this->m_vInputs.m_Size;
  inputData.m_nOffset = 44;
  inputData.m_nOffsetOffset = 68;
  inputData.m_Type = SO_FLOAT;
  inputData.m_nCount = 6;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: m_Size,
             src: &inputData);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_speakers", element: &nIndex);
  v2 = this->m_vInputs.m_Size;
  inputData.m_nCount = 3;
  inputData.m_nOffset = 20;
  inputData.m_nOffsetOffset = 32;
  inputData.m_Type = SO_FLOAT;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: v2,
             src: &inputData);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_vec3", element: &nIndex);
  v6 = this->m_vInputs.m_Size;
  inputData.m_nOffset = 12;
  inputData.m_nOffsetOffset = 16;
  inputData.m_Type = SO_FLOAT;
  inputData.m_nCount = 1;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: v6,
             src: &inputData);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input_float", element: &nIndex);
  nIndex = (int)this;
  SoundOperatorSystem = CSosOperatorSystem::GetSoundOperatorSystem();
  CUtlDict<CSosOperator *,int>::Insert(
    this: &SoundOperatorSystem->m_vOperatorCollection,
    pName: "sys_output",
    element: (CSosOperator *const *)&nIndex);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1004C900
// Name: public: virtual unsigned int CSosOperatorOutput::GetSize(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CSosOperatorOutput::GetSize(CSosOperatorOutput *this)
{
  return 96;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1004C020
// Name: public: virtual void CSosOperatorOutput::SetDefaults(void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorOutput::SetDefaults(CSosOperatorOutput *this, _DWORD *pVoidMem)
{
  pVoidMem[3] = 0;
  pVoidMem[4] = -1;
  pVoidMem[5] = 0;
  pVoidMem[8] = -1;
  pVoidMem[6] = 0;
  pVoidMem[9] = -1;
  pVoidMem[7] = 0;
  pVoidMem[10] = -1;
  pVoidMem[11] = 0;
  pVoidMem[17] = -1;
  pVoidMem[12] = 0;
  pVoidMem[18] = -1;
  pVoidMem[13] = 0;
  pVoidMem[19] = -1;
  pVoidMem[14] = 0;
  pVoidMem[20] = -1;
  pVoidMem[15] = 0;
  pVoidMem[21] = -1;
  pVoidMem[16] = 0;
  pVoidMem[22] = -1;
  pVoidMem[23] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1004C090
// Name: public: virtual void CSosOperatorOutput::Print(void __near *,class CSosOperatorStack __near *,int,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorOutput::Print(
        CSosOperatorOutput *this,
        CSosOperator_t *pVoidMem,
        CSosOperatorStack *pStack,
        const char *nOpIndex,
        int nLevel)
{
  const char *v5; // esi

  CSosOperator::PrintBaseParams(this, pVoidMem, pStack, nOpIndex, nLevel);
  v5 = "none";
  switch ( *(_DWORD *)&pVoidMem[7].m_bExecuteOnce )
  {
    case 1:
      v5 = "volume";
      break;
    case 2:
      v5 = "dsp";
      break;
    case 3:
      v5 = "position";
      break;
    case 4:
      v5 = "speakers";
      break;
    case 5:
      v5 = "facing";
      break;
    case 6:
      v5 = "distvar";
      break;
    case 7:
      v5 = "pitch";
      break;
    case 8:
      v5 = "delay";
      break;
    case 9:
      v5 = "stop_hold";
      break;
    case 0xA:
      v5 = "mixlayer_trigger";
      break;
    case 0xB:
      v5 = "save_restore";
      break;
    case 0xC:
      v5 = "block_start";
      break;
    default:
      break;
  }
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
    LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: LS_MESSAGE, a3: OpColor, a4: "%*sOutput: %s\n", nLevel, "    ", v5);
}

//------------------------------------------------------------------------------
// Address: 0x1004C190
// Name: public: virtual void CSosOperatorOutput::ParseKV(class CSosOperatorStack __near *,void __near *,class KeyValues __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorOutput::ParseKV(
        CSosOperatorOutput *this,
        CSosOperatorStack *pStack,
        CSosOperator_t *pVoidMem,
        KeyValues *pOpKeys)
{
  KeyValues *FirstSubKey; // esi
  const char *Name; // edi
  const char *String; // eax
  const char *v7; // esi
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
        && CSosOperator::BaseParseKV(this, pStack, pStructMem: pVoidMem, pParamString: Name, pValueString: String) == 0 )
      {
        if ( V_strcasecmp(s1: Name, s2: "output") != 0 )
        {
          if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
            _LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: 1, a3: "Error: Unknown sound operator attribute %s\n", Name);
        }
        else if ( V_strcasecmp(s1: v7, s2: "volume") != 0 )
        {
          if ( V_strcasecmp(s1: v7, s2: "dsp") != 0 )
          {
            if ( V_strcasecmp(s1: v7, s2: "position") != 0 )
            {
              if ( V_strcasecmp(s1: v7, s2: "speakers") != 0 )
              {
                if ( V_strcasecmp(s1: v7, s2: "facing") != 0 )
                {
                  if ( V_strcasecmp(s1: v7, s2: "distvar") != 0 )
                  {
                    if ( V_strcasecmp(s1: v7, s2: "pitch") != 0 )
                    {
                      if ( V_strcasecmp(s1: v7, s2: "delay") != 0 )
                      {
                        if ( V_strcasecmp(s1: v7, s2: "stop_hold") != 0 )
                        {
                          if ( V_strcasecmp(s1: v7, s2: "mixlayer_trigger") != 0 )
                          {
                            if ( V_strcasecmp(s1: v7, s2: "save_restore") != 0 )
                            {
                              if ( V_strcasecmp(s1: v7, s2: "block_start") == 0 )
                                *(_DWORD *)&pVoidMem[7].m_bExecuteOnce = 12;
                            }
                            else
                            {
                              *(_DWORD *)&pVoidMem[7].m_bExecuteOnce = 11;
                            }
                          }
                          else
                          {
                            *(_DWORD *)&pVoidMem[7].m_bExecuteOnce = 10;
                          }
                        }
                        else
                        {
                          *(_DWORD *)&pVoidMem[7].m_bExecuteOnce = 9;
                        }
                      }
                      else
                      {
                        *(_DWORD *)&pVoidMem[7].m_bExecuteOnce = 8;
                      }
                    }
                    else
                    {
                      *(_DWORD *)&pVoidMem[7].m_bExecuteOnce = 7;
                    }
                  }
                  else
                  {
                    *(_DWORD *)&pVoidMem[7].m_bExecuteOnce = 6;
                  }
                }
                else
                {
                  *(_DWORD *)&pVoidMem[7].m_bExecuteOnce = 5;
                }
              }
              else
              {
                *(_DWORD *)&pVoidMem[7].m_bExecuteOnce = 4;
              }
            }
            else
            {
              *(_DWORD *)&pVoidMem[7].m_bExecuteOnce = 3;
            }
          }
          else
          {
            *(_DWORD *)&pVoidMem[7].m_bExecuteOnce = 2;
          }
        }
        else
        {
          *(_DWORD *)&pVoidMem[7].m_bExecuteOnce = 1;
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
// Address: 0x1004C3D0
// Name: public: virtual void CSosOperatorOutput::Execute(void __near *,struct channel_t __near *,class CScratchPad __near *,class CSosOperatorStack __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorOutput::Execute(
        CSosOperatorOutput *this,
        char *pVoidMem,
        channel_t *pChannel,
        CScratchPad *pScratchPad,
        CSosOperatorStack *pStack,
        int nOpIndex)
{
  int v7; // ecx
  SOSStopType_t m_stopType; // eax
  SOSStopType_t v9; // eax

  v7 = *((_DWORD *)pVoidMem + 23);
  switch ( v7 )
  {
    case 8:
      pScratchPad->m_flDelay = *((float *)pVoidMem + 3);
      goto LABEL_25;
    case 9:
      m_stopType = pStack->m_stopType;
      if ( m_stopType != SOS_STOP_NONE && m_stopType != SOS_STOP_FORCE )
      {
        v9 = SOS_STOP_HOLD;
        if ( *((float *)pVoidMem + 3) <= 0.0 )
          v9 = SOS_STOP_NORM;
        CSosOperatorStack::SetStopType(this: pStack, stopType: v9);
      }
      goto LABEL_25;
    case 12:
      pScratchPad->m_bBlockStart = *((float *)pVoidMem + 3) > 0.0;
LABEL_25:
      if ( snd_sos_show_operator_updates.m_pParent != nullptr
        && snd_sos_show_operator_updates.m_pParent->m_Value.m_nValue != 0 )
      {
        this->Print(this, a2: pVoidMem, a3: pStack, a4: nOpIndex, a5: 0);
      }
      return;
    default:
      break;
  }
  if ( pChannel != nullptr )
  {
    switch ( v7 )
    {
      case 2:
        pChannel->dspmix = *((float *)pVoidMem + 3);
        break;
      case 3:
        pChannel->origin = *(Vector *)(pVoidMem + 20);
        break;
      case 4:
        ChannelSetVolTargets(pch: pChannel, pvolumes: (float *)pVoidMem + 11, ivol_offset: 0, cvol: 6);
        break;
      case 5:
        pChannel->dspface = (float)(*((float *)pVoidMem + 3) * 2.0) - 1.0;
        break;
      case 6:
        pChannel->distmix = *((float *)pVoidMem + 3);
        break;
      case 7:
        pChannel->basePitch = (int)(float)(*((float *)pVoidMem + 3) * 100.0);
        pChannel->pitch = *((float *)pVoidMem + 3);
        break;
      case 10:
        pChannel->last_vol = *((float *)pVoidMem + 3);
        break;
      case 11:
        *((_BYTE *)&pChannel->flags + 2) ^= ((*((float *)pVoidMem + 3) > 0.0) ^ *((_BYTE *)&pChannel->flags + 2)) & 1;
        break;
      default:
        goto LABEL_25;
    }
    goto LABEL_25;
  }
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
    _LoggingSystem_Log(
      a1: LOG_SND_OPERATORS,
      a2: 1,
      a3: "Error: Sound operator %s requires valid channel pointer, being called without one\n",
      pStack->m_vOperatorMap.m_Elements.m_Tree.m_Elements.m_pMemory[nOpIndex].m_Data.key);
}

//------------------------------------------------------------------------------
// Address: 0x1004C6F0
// Name: public: virtual unsigned int CSosOperatorOutput::GetSize(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CSosOperatorOutput::GetSize(CSosOperatorOutput *this)
{
  return 96;
}

} // namespace engine_xlsp
