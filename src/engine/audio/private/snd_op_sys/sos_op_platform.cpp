// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/audio/private/snd_op_sys/sos_op_platform.cpp
// Functions: 4
// ============================================================

#include "engine\audio\private\snd_op_sys\sos_op_platform.h"

//------------------------------------------------------------------------------
// Address: 0x10048890
// Name: public: virtual void CSosOperatorPlatform::Execute(void __near *,struct channel_t __near *,class CScratchPad __near *,class CSosOperatorStack __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorPlatform::Execute(
        CSosOperatorMapName *this,
        void *pVoidMem,
        channel_t *pChannel,
        CScratchPad *pScratchPad,
        CSosOperatorStack *pStack,
        int nOpIndex)
{
  if ( snd_sos_show_operator_updates.m_pParent != nullptr
    && snd_sos_show_operator_updates.m_pParent->m_Value.m_nValue != 0 )
  {
    this->Print(this, a2: pVoidMem, a3: pStack, a4: nOpIndex, a5: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004C910
// Name: public: virtual void CSosOperatorPlatform::SetDefaults(void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorPlatform::SetDefaults(CSosOperatorMapName *this, _DWORD *pVoidMem)
{
  pVoidMem[3] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1004C930
// Name: public: virtual void CSosOperatorPlatform::ParseKV(class CSosOperatorStack __near *,void __near *,class KeyValues __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorPlatform::ParseKV(
        CSosOperatorPlatform *this,
        CSosOperatorStack *pStack,
        CSosOperator_t *pVoidMem,
        KeyValues *pOpKeys)
{
  KeyValues *i; // edi
  const char *Name; // esi
  const char *String; // eax

  for ( i = KeyValues::GetFirstSubKey(this: pOpKeys); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    Name = KeyValues::GetName(this: i);
    String = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: defaultValue);
    if ( Name != nullptr
      && *Name != 0
      && String != nullptr
      && *String != 0
      && CSosOperator::BaseParseKV(this, pStack, pStructMem: pVoidMem, pParamString: Name, pValueString: String) == 0 )
    {
      if ( V_strcasecmp(s1: Name, s2: "pc") != 0 )
      {
        if ( V_strcasecmp(s1: Name, s2: "x360") != 0
          && V_strcasecmp(s1: Name, s2: "ps3") != 0
          && V_strcasecmp(s1: Name, s2: "osx") != 0
          && (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
        {
          _LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: 1, a3: "Error: Unknown sound operator attribute %s\n", Name);
        }
      }
      else
      {
        pVoidMem[1].m_flExecute[0] = 1.0;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004CA40
// Name: public: CSosOperatorPlatform::CSosOperatorPlatform(void)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorPlatform *__thiscall CSosOperatorPlatform::CSosOperatorPlatform(CSosOperatorPlatform *this)
{
  CSosOperatorSystem *SoundOperatorSystem; // eax
  int m_Size; // [esp-8h] [ebp-1Ch]
  CSosOperator::OutputData_t outputData; // [esp+4h] [ebp-10h] BYREF
  int nIndex; // [esp+10h] [ebp-4h] BYREF

  CSosOperator::CSosOperator(this);
  this->__vftable = (CSosOperatorPlatform_vtbl *)&CSosOperatorPlatform::`vftable';
  outputData.m_nCount = 1;
  m_Size = this->m_vOutputs.m_Size;
  outputData.m_nOffset = 12;
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
    pName: "sys_platform",
    element: (CSosOperator *const *)&nIndex);
  return this;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x100485F0
// Name: public: virtual void CSosOperatorPlatform::Execute(void __near *,struct channel_t __near *,class CScratchPad __near *,class CSosOperatorStack __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorPlatform::Execute(
        CSosOperatorMapName *this,
        void *pVoidMem,
        channel_t *pChannel,
        CScratchPad *pScratchPad,
        CSosOperatorStack *pStack,
        int nOpIndex)
{
  if ( snd_sos_show_operator_updates.m_pParent != nullptr
    && snd_sos_show_operator_updates.m_pParent->m_Value.m_nValue != 0 )
  {
    this->Print(this, a2: pVoidMem, a3: pStack, a4: nOpIndex, a5: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004C700
// Name: public: virtual void CSosOperatorPlatform::SetDefaults(void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorPlatform::SetDefaults(CSosOperatorMapName *this, _DWORD *pVoidMem)
{
  pVoidMem[3] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1004C720
// Name: public: virtual void CSosOperatorPlatform::ParseKV(class CSosOperatorStack __near *,void __near *,class KeyValues __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorPlatform::ParseKV(
        CSosOperatorPlatform *this,
        CSosOperatorStack *pStack,
        CSosOperator_t *pVoidMem,
        KeyValues *pOpKeys)
{
  KeyValues *i; // edi
  const char *Name; // esi
  const char *String; // eax

  for ( i = KeyValues::GetFirstSubKey(this: pOpKeys); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    Name = KeyValues::GetName(this: i);
    String = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: defaultValue);
    if ( Name != nullptr
      && *Name != 0
      && String != nullptr
      && *String != 0
      && CSosOperator::BaseParseKV(this, pStack, pStructMem: pVoidMem, pParamString: Name, pValueString: String) == 0 )
    {
      if ( V_strcasecmp(s1: Name, s2: "pc") != 0 )
      {
        if ( V_strcasecmp(s1: Name, s2: "x360") != 0
          && V_strcasecmp(s1: Name, s2: "ps3") != 0
          && V_strcasecmp(s1: Name, s2: "osx") != 0
          && (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
        {
          _LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: 1, a3: "Error: Unknown sound operator attribute %s\n", Name);
        }
      }
      else
      {
        pVoidMem[1].m_flExecute[0] = 1.0;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004C830
// Name: public: CSosOperatorPlatform::CSosOperatorPlatform(void)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorPlatform *__thiscall CSosOperatorPlatform::CSosOperatorPlatform(CSosOperatorPlatform *this)
{
  CSosOperatorSystem *SoundOperatorSystem; // eax
  int m_Size; // [esp-8h] [ebp-1Ch]
  CSosOperator::OutputData_t outputData; // [esp+4h] [ebp-10h] BYREF
  int nIndex; // [esp+10h] [ebp-4h] BYREF

  CSosOperator::CSosOperator(this);
  this->__vftable = (CSosOperatorPlatform_vtbl *)&CSosOperatorPlatform::`vftable';
  outputData.m_nCount = 1;
  m_Size = this->m_vOutputs.m_Size;
  outputData.m_nOffset = 12;
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
    pName: "sys_platform",
    element: (CSosOperator *const *)&nIndex);
  return this;
}

} // namespace engine_xlsp
