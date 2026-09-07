// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/audio/private/snd_op_sys/sos_op_dashboard.cpp
// Functions: 4
// ============================================================

#include "engine\audio\private\snd_op_sys\sos_op_dashboard.h"

//------------------------------------------------------------------------------
// Address: 0x10047770
// Name: public: virtual void CSosOperatorDashboard::SetDefaults(void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorDashboard::SetDefaults(CSosOperatorDashboard *this, _DWORD *pVoidMem)
{
  pVoidMem[4] = 1065353216;
  *((_BYTE *)pVoidMem + 12) = 1;
}

//------------------------------------------------------------------------------
// Address: 0x10047790
// Name: public: virtual void CSosOperatorDashboard::ParseKV(class CSosOperatorStack __near *,void __near *,class KeyValues __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorDashboard::ParseKV(
        CSosOperatorDashboard *this,
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
      if ( V_strcasecmp(s1: Name, s2: "ds_type") != 0 )
      {
        if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
          _LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: 1, a3: "Error: Unknown sound operator attribute %s\n", Name);
      }
      else
      {
        LOBYTE(pVoidMem[1].m_flExecute[0]) = V_strcasecmp(s1: v7, s2: "music") == 0;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10047870
// Name: public: virtual void CSosOperatorDashboard::Execute(void __near *,struct channel_t __near *,class CScratchPad __near *,class CSosOperatorStack __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorDashboard::Execute(
        CSosOperatorDashboard *this,
        float *pVoidMem,
        channel_t *pChannel,
        CScratchPad *pScratchPad,
        CSosOperatorStack *pStack,
        int nOpIndex)
{
  float v6; // xmm0_4
  float flValue; // [esp+8h] [ebp+8h]

  v6 = 1.0;
  if ( *((_BYTE *)pVoidMem + 12) != 0 )
  {
    flValue = S_GetDashboarMusicMixValue();
    v6 = flValue;
  }
  pVoidMem[4] = v6;
  if ( snd_sos_show_operator_updates.m_pParent != nullptr
    && snd_sos_show_operator_updates.m_pParent->m_Value.m_nValue != 0 )
  {
    this->Print(this, a2: pVoidMem, a3: pStack, a4: nOpIndex, a5: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100478D0
// Name: public: CSosOperatorDashboard::CSosOperatorDashboard(void)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorDashboard *__thiscall CSosOperatorDashboard::CSosOperatorDashboard(CSosOperatorDashboard *this)
{
  CSosOperatorSystem *SoundOperatorSystem; // eax
  int m_Size; // [esp-8h] [ebp-1Ch]
  CSosOperator::OutputData_t outputData; // [esp+4h] [ebp-10h] BYREF
  int nIndex; // [esp+10h] [ebp-4h] BYREF

  CSosOperator::CSosOperator(this);
  this->__vftable = (CSosOperatorDashboard_vtbl *)&CSosOperatorDashboard::`vftable';
  outputData.m_nCount = 1;
  m_Size = this->m_vOutputs.m_Size;
  outputData.m_nOffset = 16;
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
    pName: "get_dashboard",
    element: (CSosOperator *const *)&nIndex);
  return this;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10047590
// Name: public: virtual void CSosOperatorDashboard::SetDefaults(void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorDashboard::SetDefaults(CSosOperatorDashboard *this, _DWORD *pVoidMem)
{
  pVoidMem[4] = 1065353216;
  *((_BYTE *)pVoidMem + 12) = 1;
}

//------------------------------------------------------------------------------
// Address: 0x100475B0
// Name: public: virtual void CSosOperatorDashboard::ParseKV(class CSosOperatorStack __near *,void __near *,class KeyValues __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorDashboard::ParseKV(
        CSosOperatorDashboard *this,
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
      if ( V_strcasecmp(s1: Name, s2: "ds_type") != 0 )
      {
        if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
          _LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: 1, a3: "Error: Unknown sound operator attribute %s\n", Name);
      }
      else
      {
        LOBYTE(pVoidMem[1].m_flExecute[0]) = V_strcasecmp(s1: v7, s2: "music") == 0;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10047690
// Name: public: virtual void CSosOperatorDashboard::Execute(void __near *,struct channel_t __near *,class CScratchPad __near *,class CSosOperatorStack __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorDashboard::Execute(
        CSosOperatorDashboard *this,
        float *pVoidMem,
        channel_t *pChannel,
        CScratchPad *pScratchPad,
        CSosOperatorStack *pStack,
        int nOpIndex)
{
  float v6; // xmm0_4
  float flValue; // [esp+8h] [ebp+8h]

  v6 = 1.0;
  if ( *((_BYTE *)pVoidMem + 12) != 0 )
  {
    flValue = S_GetDashboarMusicMixValue();
    v6 = flValue;
  }
  pVoidMem[4] = v6;
  if ( snd_sos_show_operator_updates.m_pParent != nullptr
    && snd_sos_show_operator_updates.m_pParent->m_Value.m_nValue != 0 )
  {
    this->Print(this, a2: pVoidMem, a3: pStack, a4: nOpIndex, a5: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100476F0
// Name: public: CSosOperatorDashboard::CSosOperatorDashboard(void)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorDashboard *__thiscall CSosOperatorDashboard::CSosOperatorDashboard(CSosOperatorDashboard *this)
{
  CSosOperatorSystem *SoundOperatorSystem; // eax
  int m_Size; // [esp-8h] [ebp-1Ch]
  CSosOperator::OutputData_t outputData; // [esp+4h] [ebp-10h] BYREF
  int nIndex; // [esp+10h] [ebp-4h] BYREF

  CSosOperator::CSosOperator(this);
  this->__vftable = (CSosOperatorDashboard_vtbl *)&CSosOperatorDashboard::`vftable';
  outputData.m_nCount = 1;
  m_Size = this->m_vOutputs.m_Size;
  outputData.m_nOffset = 16;
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
    pName: "get_dashboard",
    element: (CSosOperator *const *)&nIndex);
  return this;
}

} // namespace engine_xlsp
