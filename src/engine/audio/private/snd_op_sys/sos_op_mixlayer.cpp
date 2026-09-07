// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/audio/private/snd_op_sys/sos_op_mixlayer.cpp
// Functions: 5
// ============================================================

#include "engine\audio\private\snd_op_sys\sos_op_mixlayer.h"

//------------------------------------------------------------------------------
// Address: 0x1004B2E0
// Name: public: virtual void CSosOperatorMixLayer::SetDefaults(void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorMixLayer::SetDefaults(CSosOperatorMixLayer *this, _DWORD *pVoidMem)
{
  pVoidMem[3] = 0;
  pVoidMem[4] = -1;
  pVoidMem[5] = 0;
  pVoidMem[6] = -1;
  pVoidMem[7] = -1;
}

//------------------------------------------------------------------------------
// Address: 0x1004B310
// Name: public: virtual void CSosOperatorMixLayer::Print(void __near *,class CSosOperatorStack __near *,int,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorMixLayer::Print(
        CSosOperatorMixLayer *this,
        CSosOperator_t *pVoidMem,
        CSosOperatorStack *pStack,
        const char *nOpIndex,
        int nLevel)
{
  const char *v5; // esi

  CSosOperator::PrintBaseParams(this, pVoidMem, pStack, nOpIndex, nLevel);
  v5 = "none";
  switch ( *(_DWORD *)&pVoidMem[1].m_bExecuteOnce )
  {
    case 1:
      v5 = "volume";
      break;
    case 2:
      v5 = "level";
      break;
    case 3:
      v5 = "dsp";
      break;
    case 4:
      v5 = "solo";
      break;
    case 5:
      v5 = "mute";
      break;
    default:
      break;
  }
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
    LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: LS_MESSAGE, a3: OpColor, a4: "%*sField: %s\n", nLevel, "    ", v5);
}

//------------------------------------------------------------------------------
// Address: 0x1004B3C0
// Name: public: virtual void CSosOperatorMixLayer::ParseKV(class CSosOperatorStack __near *,void __near *,class KeyValues __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorMixLayer::ParseKV(
        CSosOperatorMixLayer *this,
        CSosOperatorStack *pStack,
        CSosOperator_t *pVoidMem,
        KeyValues *pOpKeys)
{
  KeyValues *FirstSubKey; // esi
  const char *Name; // edi
  const char *String; // eax
  const char *v7; // esi
  int MixLayerIndexFromName; // edi
  int MixGroupIndex; // edi
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
        if ( V_strcasecmp(s1: Name, s2: "field") != 0 )
        {
          if ( V_strcasecmp(s1: Name, s2: "mixlayer") != 0 )
          {
            if ( V_strcasecmp(s1: Name, s2: "mixgroup") != 0 )
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
              MixGroupIndex = S_GetMixGroupIndex(pMixGroupName: v7);
              if ( MixGroupIndex == -1
                && (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
              {
                _LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: 1, a3: "Error: Failed to get mix group %s!\n", v7);
              }
              pVoidMem[2].m_flExecuteOffset[0] = MixGroupIndex;
            }
          }
          else
          {
            MixLayerIndexFromName = MXR_GetMixLayerIndexFromName(szmixlayername: v7);
            if ( MixLayerIndexFromName == -1
              && (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
            {
              _LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: 1, a3: "Error: Failed to get mix layer %s!\n", v7);
            }
            LODWORD(pVoidMem[2].m_flExecute[0]) = MixLayerIndexFromName;
          }
        }
        else if ( V_strcasecmp(s1: v7, s2: "volume") != 0 )
        {
          if ( V_strcasecmp(s1: v7, s2: "level") != 0 )
          {
            if ( V_strcasecmp(s1: v7, s2: "dsp") != 0 )
            {
              if ( V_strcasecmp(s1: v7, s2: "solo") != 0 )
              {
                if ( V_strcasecmp(s1: v7, s2: "mute") == 0 )
                  *(_DWORD *)&pVoidMem[1].m_bExecuteOnce = 5;
              }
              else
              {
                *(_DWORD *)&pVoidMem[1].m_bExecuteOnce = 4;
              }
            }
            else
            {
              *(_DWORD *)&pVoidMem[1].m_bExecuteOnce = 3;
            }
          }
          else
          {
            *(_DWORD *)&pVoidMem[1].m_bExecuteOnce = 2;
          }
        }
        else
        {
          *(_DWORD *)&pVoidMem[1].m_bExecuteOnce = 1;
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
// Address: 0x1004B5E0
// Name: public: virtual void CSosOperatorMixLayer::Execute(void __near *,struct channel_t __near *,class CScratchPad __near *,class CSosOperatorStack __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorMixLayer::Execute(
        CSosOperatorMixLayer *this,
        void *pVoidMem,
        channel_t *pChannel,
        channel_t *pScratchPad,
        CScratchPad *pStack,
        CSosOperatorStack *nOpIndex)
{
  int v6; // eax
  int v8; // ecx

  v6 = *((_DWORD *)pVoidMem + 7);
  if ( v6 >= 0 )
  {
    v8 = *((_DWORD *)pVoidMem + 6);
    if ( v8 >= 0 )
    {
      S_SetMixGroupOfMixLayer(
        nMixGroupIndex: v6,
        nMixLayerIndex: v8,
        nMixGroupField: *((MXRMixGroupFields_t *)pVoidMem + 5),
        flValue: *((float *)pVoidMem + 3));
      if ( snd_sos_show_operator_updates.m_pParent != nullptr
        && snd_sos_show_operator_updates.m_pParent->m_Value.m_nValue != 0 )
      {
        this->Print(this, a2: pVoidMem, a3: (CSosOperatorStack *)pStack, a4: (int)nOpIndex, a5: 0);
      }
    }
    else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
    {
      _LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: 1, a3: "Error: MixLayer operator has invalid mix layer index!\n");
    }
  }
  else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
  {
    _LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: 1, a3: "Error: MixLayer operator has invalid mix group index!\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004B6A0
// Name: public: CSosOperatorMixLayer::CSosOperatorMixLayer(void)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorMixLayer *__thiscall CSosOperatorMixLayer::CSosOperatorMixLayer(CSosOperatorMixLayer *this)
{
  CSosOperatorSystem *SoundOperatorSystem; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  CSosOperator::InputData_t inputData; // [esp+4h] [ebp-14h] BYREF
  int nIndex; // [esp+14h] [ebp-4h] BYREF

  CSosOperator::CSosOperator(this);
  this->__vftable = (CSosOperatorMixLayer_vtbl *)&CSosOperatorMixLayer::`vftable';
  inputData.m_nCount = 1;
  m_Size = this->m_vInputs.m_Size;
  inputData.m_nOffset = 12;
  inputData.m_nOffsetOffset = 16;
  inputData.m_Type = SO_FLOAT;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: m_Size,
             src: &inputData);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input", element: &nIndex);
  nIndex = (int)this;
  SoundOperatorSystem = CSosOperatorSystem::GetSoundOperatorSystem();
  CUtlDict<CSosOperator *,int>::Insert(
    this: &SoundOperatorSystem->m_vOperatorCollection,
    pName: "sys_mixlayer",
    element: (CSosOperator *const *)&nIndex);
  return this;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1004B0C0
// Name: public: virtual void CSosOperatorMixLayer::SetDefaults(void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorMixLayer::SetDefaults(CSosOperatorMixLayer *this, _DWORD *pVoidMem)
{
  pVoidMem[3] = 0;
  pVoidMem[4] = -1;
  pVoidMem[5] = 0;
  pVoidMem[6] = -1;
  pVoidMem[7] = -1;
}

//------------------------------------------------------------------------------
// Address: 0x1004B0F0
// Name: public: virtual void CSosOperatorMixLayer::Print(void __near *,class CSosOperatorStack __near *,int,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorMixLayer::Print(
        CSosOperatorMixLayer *this,
        CSosOperator_t *pVoidMem,
        CSosOperatorStack *pStack,
        const char *nOpIndex,
        int nLevel)
{
  const char *v5; // esi

  CSosOperator::PrintBaseParams(this, pVoidMem, pStack, nOpIndex, nLevel);
  v5 = "none";
  switch ( *(_DWORD *)&pVoidMem[1].m_bExecuteOnce )
  {
    case 1:
      v5 = "volume";
      break;
    case 2:
      v5 = "level";
      break;
    case 3:
      v5 = "dsp";
      break;
    case 4:
      v5 = "solo";
      break;
    case 5:
      v5 = "mute";
      break;
    default:
      break;
  }
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
    LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: LS_MESSAGE, a3: OpColor, a4: "%*sField: %s\n", nLevel, "    ", v5);
}

//------------------------------------------------------------------------------
// Address: 0x1004B1A0
// Name: public: virtual void CSosOperatorMixLayer::ParseKV(class CSosOperatorStack __near *,void __near *,class KeyValues __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorMixLayer::ParseKV(
        CSosOperatorMixLayer *this,
        CSosOperatorStack *pStack,
        CSosOperator_t *pVoidMem,
        KeyValues *pOpKeys)
{
  KeyValues *FirstSubKey; // esi
  const char *Name; // edi
  const char *String; // eax
  const char *v7; // esi
  int MixLayerIndexFromName; // edi
  unsigned int MixGroupIndex; // edi
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
        if ( V_strcasecmp(s1: Name, s2: "field") != 0 )
        {
          if ( V_strcasecmp(s1: Name, s2: "mixlayer") != 0 )
          {
            if ( V_strcasecmp(s1: Name, s2: "mixgroup") != 0 )
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
              MixGroupIndex = S_GetMixGroupIndex(pMixGroupName: v7);
              if ( MixGroupIndex == -1
                && (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
              {
                _LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: 1, a3: "Error: Failed to get mix group %s!\n", v7);
              }
              pVoidMem[2].m_flExecuteOffset[0] = MixGroupIndex;
            }
          }
          else
          {
            MixLayerIndexFromName = MXR_GetMixLayerIndexFromName(szmixlayername: v7);
            if ( MixLayerIndexFromName == -1
              && (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
            {
              _LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: 1, a3: "Error: Failed to get mix layer %s!\n", v7);
            }
            LODWORD(pVoidMem[2].m_flExecute[0]) = MixLayerIndexFromName;
          }
        }
        else if ( V_strcasecmp(s1: v7, s2: "volume") != 0 )
        {
          if ( V_strcasecmp(s1: v7, s2: "level") != 0 )
          {
            if ( V_strcasecmp(s1: v7, s2: "dsp") != 0 )
            {
              if ( V_strcasecmp(s1: v7, s2: "solo") != 0 )
              {
                if ( V_strcasecmp(s1: v7, s2: "mute") == 0 )
                  *(_DWORD *)&pVoidMem[1].m_bExecuteOnce = 5;
              }
              else
              {
                *(_DWORD *)&pVoidMem[1].m_bExecuteOnce = 4;
              }
            }
            else
            {
              *(_DWORD *)&pVoidMem[1].m_bExecuteOnce = 3;
            }
          }
          else
          {
            *(_DWORD *)&pVoidMem[1].m_bExecuteOnce = 2;
          }
        }
        else
        {
          *(_DWORD *)&pVoidMem[1].m_bExecuteOnce = 1;
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
// Address: 0x1004B480
// Name: public: CSosOperatorMixLayer::CSosOperatorMixLayer(void)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorMixLayer *__thiscall CSosOperatorMixLayer::CSosOperatorMixLayer(CSosOperatorMixLayer *this)
{
  CSosOperatorSystem *SoundOperatorSystem; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  CSosOperator::InputData_t inputData; // [esp+4h] [ebp-14h] BYREF
  int nIndex; // [esp+14h] [ebp-4h] BYREF

  CSosOperator::CSosOperator(this);
  this->__vftable = (CSosOperatorMixLayer_vtbl *)&CSosOperatorMixLayer::`vftable';
  inputData.m_nCount = 1;
  m_Size = this->m_vInputs.m_Size;
  inputData.m_nOffset = 12;
  inputData.m_nOffsetOffset = 16;
  inputData.m_Type = SO_FLOAT;
  nIndex = CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
             this: &this->m_vInputs,
             elem: m_Size,
             src: &inputData);
  CUtlDict<int,int>::Insert(this: &this->m_vInputMap, pName: "input", element: &nIndex);
  nIndex = (int)this;
  SoundOperatorSystem = CSosOperatorSystem::GetSoundOperatorSystem();
  CUtlDict<CSosOperator *,int>::Insert(
    this: &SoundOperatorSystem->m_vOperatorCollection,
    pName: "sys_mixlayer",
    element: (CSosOperator *const *)&nIndex);
  return this;
}

} // namespace engine_xlsp
