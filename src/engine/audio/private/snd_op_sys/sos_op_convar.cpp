// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/audio/private/snd_op_sys/sos_op_convar.cpp
// Functions: 5
// ============================================================

#include "engine\audio\private\snd_op_sys\sos_op_convar.h"

//------------------------------------------------------------------------------
// Address: 0x100474E0
// Name: public: virtual void CSosOperatorConvar::SetDefaults(void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorConvar::SetDefaults(CSosOperatorConvar *this, _DWORD *pVoidMem)
{
  pVoidMem[21] = 1065353216;
}

//------------------------------------------------------------------------------
// Address: 0x10047500
// Name: public: virtual void CSosOperatorConvar::Print(void __near *,class CSosOperatorStack __near *,int,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorConvar::Print(
        CSosOperatorConvar *this,
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
      a4: "%*sconvar: %s\n",
      nLevel,
      "    ",
      (const char *)&pVoidMem[1]);
}

//------------------------------------------------------------------------------
// Address: 0x10047560
// Name: public: virtual void CSosOperatorConvar::ParseKV(class CSosOperatorStack __near *,void __near *,class KeyValues __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorConvar::ParseKV(
        CSosOperatorConvar *this,
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
      if ( V_strcasecmp(s1: Name, s2: "convar") != 0 )
      {
        if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
          _LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: 1, a3: "Error: Unknown sound operator attribute %s\n", Name);
      }
      else
      {
        _V_strcpy(dest: pVoidMem + 12, src: v7);
        ConVarRef::Init(this: (ConVarRef *)(pVoidMem + 76), pName: v7, bIgnoreMissing: true);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10047640
// Name: public: virtual void CSosOperatorConvar::Execute(void __near *,struct channel_t __near *,class CScratchPad __near *,class CSosOperatorStack __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorConvar::Execute(
        CSosOperatorConvar *this,
        char *pVoidMem,
        channel_t *pChannel,
        CScratchPad *pScratchPad,
        CSosOperatorStack *pStack,
        int nOpIndex)
{
  int v6; // xmm0_4

  if ( ConVarRef::IsValid(this: (ConVarRef *)(pVoidMem + 76)) )
  {
    v6 = *(_DWORD *)(*((_DWORD *)pVoidMem + 20) + 44);
  }
  else
  {
    ConVarRef::Init(this: (ConVarRef *)(pVoidMem + 76), pName: pVoidMem + 12, bIgnoreMissing: true);
    if ( ConVarRef::IsValid(this: (ConVarRef *)(pVoidMem + 76)) )
    {
      v6 = *(_DWORD *)(*((_DWORD *)pVoidMem + 20) + 44);
    }
    else
    {
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
        _LoggingSystem_Log(
          a1: LOG_SND_OPERATORS,
          a2: 1,
          a3: "Warning: Unable to acquire convar value: %s\n",
          pVoidMem + 12);
      v6 = 1065353216;
    }
  }
  *((_DWORD *)pVoidMem + 21) = v6;
  if ( snd_sos_show_operator_updates.m_pParent != nullptr
    && snd_sos_show_operator_updates.m_pParent->m_Value.m_nValue != 0 )
  {
    this->Print(this, a2: pVoidMem, a3: pStack, a4: nOpIndex, a5: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100476F0
// Name: public: CSosOperatorConvar::CSosOperatorConvar(void)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorConvar *__thiscall CSosOperatorConvar::CSosOperatorConvar(CSosOperatorConvar *this)
{
  CSosOperatorSystem *SoundOperatorSystem; // eax
  int m_Size; // [esp-8h] [ebp-1Ch]
  CSosOperator::OutputData_t outputData; // [esp+4h] [ebp-10h] BYREF
  int nIndex; // [esp+10h] [ebp-4h] BYREF

  CSosOperator::CSosOperator(this);
  this->__vftable = (CSosOperatorConvar_vtbl *)&CSosOperatorConvar::`vftable';
  outputData.m_nCount = 1;
  m_Size = this->m_vOutputs.m_Size;
  outputData.m_nOffset = 84;
  outputData.m_Type = SO_FLOAT;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: m_Size,
             src: (const Vector *)&outputData);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output", element: &nIndex);
  nIndex = (int)this;
  SoundOperatorSystem = CSosOperatorSystem::GetSoundOperatorSystem();
  CUtlDict<CSosOperator *,int>::Insert(
    this: &SoundOperatorSystem->m_vOperatorCollection,
    pName: "get_convar",
    element: (CSosOperator *const *)&nIndex);
  return this;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10047280
// Name: public: virtual void CSosOperatorConvar::SetDefaults(void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorConvar::SetDefaults(CSosOperatorConvar *this, _DWORD *pVoidMem)
{
  pVoidMem[21] = 1065353216;
}

//------------------------------------------------------------------------------
// Address: 0x100472A0
// Name: public: virtual void CSosOperatorConvar::Print(void __near *,class CSosOperatorStack __near *,int,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorConvar::Print(
        CSosOperatorConvar *this,
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
      a4: "%*sconvar: %s\n",
      nLevel,
      "    ",
      (const char *)&pVoidMem[1]);
}

//------------------------------------------------------------------------------
// Address: 0x10047300
// Name: public: virtual void CSosOperatorConvar::ParseKV(class CSosOperatorStack __near *,void __near *,class KeyValues __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorConvar::ParseKV(
        CSosOperatorConvar *this,
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
      if ( V_strcasecmp(s1: Name, s2: "convar") != 0 )
      {
        if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
          _LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: 1, a3: "Error: Unknown sound operator attribute %s\n", Name);
      }
      else
      {
        _V_strcpy(dest: pVoidMem + 12, src: v7);
        ConVarRef::Init(this: (ConVarRef *)(pVoidMem + 76), pName: v7, bIgnoreMissing: true);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100473E0
// Name: public: virtual void CSosOperatorConvar::Execute(void __near *,struct channel_t __near *,class CScratchPad __near *,class CSosOperatorStack __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorConvar::Execute(
        CSosOperatorConvar *this,
        char *pVoidMem,
        channel_t *pChannel,
        CScratchPad *pScratchPad,
        CSosOperatorStack *pStack,
        int nOpIndex)
{
  int v6; // xmm0_4

  if ( ConVarRef::IsValid(this: (ConVarRef *)(pVoidMem + 76)) )
  {
    v6 = *(_DWORD *)(*((_DWORD *)pVoidMem + 20) + 44);
  }
  else
  {
    ConVarRef::Init(this: (ConVarRef *)(pVoidMem + 76), pName: pVoidMem + 12, bIgnoreMissing: true);
    if ( ConVarRef::IsValid(this: (ConVarRef *)(pVoidMem + 76)) )
    {
      v6 = *(_DWORD *)(*((_DWORD *)pVoidMem + 20) + 44);
    }
    else
    {
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
        _LoggingSystem_Log(
          a1: LOG_SND_OPERATORS,
          a2: 1,
          a3: "Warning: Unable to acquire convar value: %s\n",
          pVoidMem + 12);
      v6 = 1065353216;
    }
  }
  *((_DWORD *)pVoidMem + 21) = v6;
  if ( snd_sos_show_operator_updates.m_pParent != nullptr
    && snd_sos_show_operator_updates.m_pParent->m_Value.m_nValue != 0 )
  {
    this->Print(this, a2: pVoidMem, a3: pStack, a4: nOpIndex, a5: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10047510
// Name: public: CSosOperatorConvar::CSosOperatorConvar(void)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorConvar *__thiscall CSosOperatorConvar::CSosOperatorConvar(CSosOperatorConvar *this)
{
  CSosOperatorSystem *SoundOperatorSystem; // eax
  int m_Size; // [esp-8h] [ebp-1Ch]
  CSosOperator::OutputData_t outputData; // [esp+4h] [ebp-10h] BYREF
  int nIndex; // [esp+10h] [ebp-4h] BYREF

  CSosOperator::CSosOperator(this);
  this->__vftable = (CSosOperatorConvar_vtbl *)&CSosOperatorConvar::`vftable';
  outputData.m_nCount = 1;
  m_Size = this->m_vOutputs.m_Size;
  outputData.m_nOffset = 84;
  outputData.m_Type = SO_FLOAT;
  nIndex = CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
             this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_vOutputs,
             elem: m_Size,
             src: (const Vector *)&outputData);
  CUtlDict<int,int>::Insert(this: &this->m_vOutputMap, pName: "output", element: &nIndex);
  nIndex = (int)this;
  SoundOperatorSystem = CSosOperatorSystem::GetSoundOperatorSystem();
  CUtlDict<CSosOperator *,int>::Insert(
    this: &SoundOperatorSystem->m_vOperatorCollection,
    pName: "get_convar",
    element: (CSosOperator *const *)&nIndex);
  return this;
}

} // namespace engine_xlsp
