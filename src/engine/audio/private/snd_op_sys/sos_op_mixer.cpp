// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/audio/private/snd_op_sys/sos_op_mixer.cpp
// Functions: 5
// ============================================================

#include "engine\audio\private\snd_op_sys\sos_op_mixer.h"

//------------------------------------------------------------------------------
// Address: 0x1004AED0
// Name: public: virtual void CSosOperatorMixGroup::SetDefaults(void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorMixGroup::SetDefaults(CSosOperatorMixGroup *this, _DWORD *pVoidMem)
{
  pVoidMem[4] = 1065353216;
  pVoidMem[5] = 1065353216;
  pVoidMem[6] = 1065353216;
}

//------------------------------------------------------------------------------
// Address: 0x1004AF00
// Name: public: virtual void CSosOperatorMixGroup::Print(void __near *,class CSosOperatorStack __near *,int,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorMixGroup::Print(
        CSosOperatorMixGroup *this,
        void *pVoidMem,
        CSosOperatorStack *pStack,
        const char *nOpIndex,
        int nLevel)
{
  const char *GroupnameFromId; // eax

  CSosOperator::PrintBaseParams(this, (CSosOperator_t *)pVoidMem, pStack, nOpIndex, nLevel);
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
  {
    GroupnameFromId = MXR_GetGroupnameFromId(mixgroupid: *((_DWORD *)pVoidMem + 3));
    LoggingSystem_Log(
      a1: LOG_SND_OPERATORS,
      a2: LS_MESSAGE,
      a3: OpColor,
      a4: "%*smixgroup: %s\n",
      nLevel,
      "    ",
      GroupnameFromId);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004AF80
// Name: public: virtual void CSosOperatorMixGroup::ParseKV(class CSosOperatorStack __near *,void __near *,class KeyValues __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorMixGroup::ParseKV(
        CSosOperatorMixGroup *this,
        CSosOperatorStack *pStack,
        CSosOperator_t *pVoidMem,
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
      && CSosOperator::BaseParseKV(this, pStack, pStructMem: pVoidMem, pParamString: Name, pValueString: String) == 0 )
    {
      if ( V_strcasecmp(s1: Name, s2: "mixgroup") != 0 )
      {
        if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
          _LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: 1, a3: "Error: Unknown sound operator attribute %s\n", Name);
      }
      else
      {
        LODWORD(pVoidMem[1].m_flExecute[0]) = MXR_GetMixgroupFromName(pszgroupname: v7);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004B050
// Name: public: virtual void CSosOperatorMixGroup::Execute(void __near *,struct channel_t __near *,class CScratchPad __near *,class CSosOperatorStack __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorMixGroup::Execute(
        CSosOperatorMixGroup *this,
        char *pVoidMem,
        channel_t *pChannel,
        CScratchPad *pScratchPad,
        CSosOperatorStack *pStack,
        int nOpIndex)
{
  const char *GroupnameFromId; // eax
  int v8; // [esp-8h] [ebp-120h]
  char sndname[260]; // [esp+8h] [ebp-110h] BYREF
  mixervalues_t mixValues; // [esp+10Ch] [ebp-Ch] BYREF

  if ( pChannel != nullptr )
  {
    if ( *((int *)pVoidMem + 3) >= 0 )
    {
      v8 = *((_DWORD *)pVoidMem + 3);
      mixValues.volume = 1.0;
      mixValues.level = 1.0;
      mixValues.dsp = 1.0;
      MXR_GetValuesFromMixGroupIndex(&mixValues, imixgroup: v8);
      *(mixervalues_t *)(pVoidMem + 16) = mixValues;
      if ( snd_sos_show_operator_updates.m_pParent != nullptr
        && snd_sos_show_operator_updates.m_pParent->m_Value.m_nValue != 0 )
      {
        this->Print(this, a2: pVoidMem, a3: pStack, a4: nOpIndex, a5: 0);
      }
      pChannel->last_mixgroupid = *((_DWORD *)pVoidMem + 3);
    }
    else
    {
      pChannel->sfx->getname(this: pChannel->sfx, a2: sndname, a3: 260u);
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
      {
        GroupnameFromId = MXR_GetGroupnameFromId(mixgroupid: *((_DWORD *)pVoidMem + 3));
        _LoggingSystem_Log(
          a1: LOG_SND_OPERATORS,
          a2: 1,
          a3: "Error: MixGroup index error, %s, %s",
          sndname,
          GroupnameFromId);
      }
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
// Address: 0x1004B190
// Name: public: CSosOperatorMixGroup::CSosOperatorMixGroup(void)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorMixGroup *__thiscall CSosOperatorMixGroup::CSosOperatorMixGroup(CSosOperatorMixGroup *this)
{
  int v2; // eax
  CSosOperatorSystem *SoundOperatorSystem; // eax
  int m_Size; // [esp-8h] [ebp-24h]
  int v6; // [esp-8h] [ebp-24h]
  CSosOperator::OutputData_t outputData; // [esp+Ch] [ebp-10h] BYREF
  int nIndex; // [esp+18h] [ebp-4h] BYREF

  CSosOperator::CSosOperator(this);
  this->__vftable = (CSosOperatorMixGroup_vtbl *)&CSosOperatorMixGroup::`vftable';
  m_Size = this->m_vOutputs.m_Size;
  outputData.m_nOffset = 16;
  outputData.m_Type = SO_FLOAT;
  outputData.m_nCount = 1;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: m_Size,
             src: (const Vector *)&outputData);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output_volume", element: &nIndex);
  v2 = this->m_vOutputs.m_Size;
  outputData.m_nCount = 1;
  outputData.m_nOffset = 20;
  outputData.m_Type = SO_FLOAT;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: v2,
             src: (const Vector *)&outputData);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output_level", element: &nIndex);
  v6 = this->m_vOutputs.m_Size;
  outputData.m_nOffset = 24;
  outputData.m_Type = SO_FLOAT;
  outputData.m_nCount = 1;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: v6,
             src: (const Vector *)&outputData);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output_dsp", element: &nIndex);
  nIndex = (int)this;
  SoundOperatorSystem = CSosOperatorSystem::GetSoundOperatorSystem();
  CUtlDict<CSosOperator *,int>::Insert(
    this: &SoundOperatorSystem->m_vOperatorCollection,
    pName: "get_soundmixer",
    element: (CSosOperator *const *)&nIndex);
  return this;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1004AD20
// Name: public: virtual void CSosOperatorMixGroup::SetDefaults(void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorMixGroup::SetDefaults(CSosOperatorMixGroup *this, _DWORD *pVoidMem)
{
  pVoidMem[4] = 1065353216;
  pVoidMem[5] = 1065353216;
  pVoidMem[6] = 1065353216;
}

//------------------------------------------------------------------------------
// Address: 0x1004AD50
// Name: public: virtual void CSosOperatorMixGroup::Print(void __near *,class CSosOperatorStack __near *,int,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorMixGroup::Print(
        CSosOperatorMixGroup *this,
        void *pVoidMem,
        CSosOperatorStack *pStack,
        const char *nOpIndex,
        int nLevel)
{
  grouprule_t *GroupnameFromId; // eax

  CSosOperator::PrintBaseParams(this, (CSosOperator_t *)pVoidMem, pStack, nOpIndex, nLevel);
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 0) != 0 )
  {
    GroupnameFromId = MXR_GetGroupnameFromId(mixgroupid: *((_DWORD *)pVoidMem + 3));
    LoggingSystem_Log(
      a1: LOG_SND_OPERATORS,
      a2: LS_MESSAGE,
      a3: OpColor,
      a4: "%*smixgroup: %s\n",
      nLevel,
      "    ",
      GroupnameFromId->szmixgroup);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004ADC0
// Name: public: virtual void CSosOperatorMixGroup::ParseKV(class CSosOperatorStack __near *,void __near *,class KeyValues __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorMixGroup::ParseKV(
        CSosOperatorMixGroup *this,
        CSosOperatorStack *pStack,
        CSosOperator_t *pVoidMem,
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
      && CSosOperator::BaseParseKV(this, pStack, pStructMem: pVoidMem, pParamString: Name, pValueString: String) == 0 )
    {
      if ( V_strcasecmp(s1: Name, s2: "mixgroup") != 0 )
      {
        if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
          _LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: 1, a3: "Error: Unknown sound operator attribute %s\n", Name);
      }
      else
      {
        LODWORD(pVoidMem[1].m_flExecute[0]) = MXR_GetMixgroupFromName(pszgroupname: v7);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004AE90
// Name: public: virtual void CSosOperatorMixGroup::Execute(void __near *,struct channel_t __near *,class CScratchPad __near *,class CSosOperatorStack __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorMixGroup::Execute(
        CSosOperatorMixGroup *this,
        char *pVoidMem,
        channel_t *pChannel,
        CScratchPad *pScratchPad,
        CSosOperatorStack *pStack,
        int nOpIndex)
{
  grouprule_t *GroupnameFromId; // eax
  int v8; // [esp-8h] [ebp-120h]
  char sndname[260]; // [esp+8h] [ebp-110h] BYREF
  mixervalues_t mixValues; // [esp+10Ch] [ebp-Ch] BYREF

  if ( pChannel != nullptr )
  {
    if ( *((int *)pVoidMem + 3) >= 0 )
    {
      v8 = *((_DWORD *)pVoidMem + 3);
      mixValues.volume = 1.0;
      mixValues.level = 1.0;
      mixValues.dsp = 1.0;
      MXR_GetValuesFromMixGroupIndex(&mixValues, imixgroup: v8);
      *(mixervalues_t *)(pVoidMem + 16) = mixValues;
      if ( snd_sos_show_operator_updates.m_pParent != nullptr
        && snd_sos_show_operator_updates.m_pParent->m_Value.m_nValue != 0 )
      {
        this->Print(this, a2: pVoidMem, a3: pStack, a4: nOpIndex, a5: 0);
      }
      pChannel->last_mixgroupid = *((_DWORD *)pVoidMem + 3);
    }
    else
    {
      pChannel->sfx->getname(this: pChannel->sfx, a2: sndname, a3: 260u);
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
      {
        GroupnameFromId = MXR_GetGroupnameFromId(mixgroupid: *((_DWORD *)pVoidMem + 3));
        _LoggingSystem_Log(
          a1: LOG_SND_OPERATORS,
          a2: 1,
          a3: "Error: MixGroup index error, %s, %s",
          sndname,
          GroupnameFromId->szmixgroup);
      }
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
// Address: 0x1004AFD0
// Name: public: CSosOperatorMixGroup::CSosOperatorMixGroup(void)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorMixGroup *__thiscall CSosOperatorMixGroup::CSosOperatorMixGroup(CSosOperatorMixGroup *this)
{
  int v2; // eax
  CSosOperatorSystem *SoundOperatorSystem; // eax
  int m_Size; // [esp-8h] [ebp-24h]
  int v6; // [esp-8h] [ebp-24h]
  CSosOperator::OutputData_t outputData; // [esp+Ch] [ebp-10h] BYREF
  int nIndex; // [esp+18h] [ebp-4h] BYREF

  CSosOperator::CSosOperator(this);
  this->__vftable = (CSosOperatorMixGroup_vtbl *)&CSosOperatorMixGroup::`vftable';
  m_Size = this->m_vOutputs.m_Size;
  outputData.m_nOffset = 16;
  outputData.m_Type = SO_FLOAT;
  outputData.m_nCount = 1;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: m_Size,
             src: (const Vector *)&outputData);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output_volume", element: &nIndex);
  v2 = this->m_vOutputs.m_Size;
  outputData.m_nCount = 1;
  outputData.m_nOffset = 20;
  outputData.m_Type = SO_FLOAT;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: v2,
             src: (const Vector *)&outputData);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output_level", element: &nIndex);
  v6 = this->m_vOutputs.m_Size;
  outputData.m_nOffset = 24;
  outputData.m_Type = SO_FLOAT;
  outputData.m_nCount = 1;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: v6,
             src: (const Vector *)&outputData);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output_dsp", element: &nIndex);
  nIndex = (int)this;
  SoundOperatorSystem = CSosOperatorSystem::GetSoundOperatorSystem();
  CUtlDict<CSosOperator *,int>::Insert(
    this: &SoundOperatorSystem->m_vOperatorCollection,
    pName: "get_soundmixer",
    element: (CSosOperator *const *)&nIndex);
  return this;
}

} // namespace engine_xlsp
