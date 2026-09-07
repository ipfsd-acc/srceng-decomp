// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/audio/private/snd_op_sys/sos_op_map_name.cpp
// Functions: 2
// ============================================================

#include "engine\audio\private\snd_op_sys\sos_op_map_name.h"

//------------------------------------------------------------------------------
// Address: 0x10048780
// Name: public: virtual void CSosOperatorMapName::ParseKV(class CSosOperatorStack __near *,void __near *,class KeyValues __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorMapName::ParseKV(
        CSosOperatorMapName *this,
        CSosOperatorStack *pStack,
        CSosOperator_t *pVoidMem,
        KeyValues *pOpKeys)
{
  KeyValues *i; // ebx
  const char *Name; // esi
  const char *String; // eax
  const char *v7; // edi
  const char *v8; // eax

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
      if ( V_strcasecmp(s1: Name, s2: "map_name") != 0 )
      {
        if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
          _LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: 1, a3: "Error: Unknown sound operator attribute %s\n", Name);
      }
      else
      {
        pVoidMem[1].m_flExecute[0] = 0.0;
        v8 = engineClient->GetLevelNameShort(this: engineClient);
        if ( _V_strcmp(s1: v8, s2: v7) == 0 )
          pVoidMem[1].m_flExecute[0] = 1.0;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100488C0
// Name: public: CSosOperatorMapName::CSosOperatorMapName(void)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorMapName *__thiscall CSosOperatorMapName::CSosOperatorMapName(CSosOperatorMapName *this)
{
  CSosOperatorSystem *SoundOperatorSystem; // eax
  int m_Size; // [esp-8h] [ebp-1Ch]
  CSosOperator::OutputData_t outputData; // [esp+4h] [ebp-10h] BYREF
  int nIndex; // [esp+10h] [ebp-4h] BYREF

  CSosOperator::CSosOperator(this);
  this->__vftable = (CSosOperatorMapName_vtbl *)&CSosOperatorMapName::`vftable';
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
    pName: "get_map_name",
    element: (CSosOperator *const *)&nIndex);
  return this;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x100484E0
// Name: public: virtual void CSosOperatorMapName::ParseKV(class CSosOperatorStack __near *,void __near *,class KeyValues __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSosOperatorMapName::ParseKV(
        CSosOperatorMapName *this,
        CSosOperatorStack *pStack,
        CSosOperator_t *pVoidMem,
        KeyValues *pOpKeys)
{
  KeyValues *i; // ebx
  const char *Name; // esi
  const char *String; // eax
  const char *v7; // edi
  const char *v8; // eax

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
      if ( V_strcasecmp(s1: Name, s2: "map_name") != 0 )
      {
        if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SND_OPERATORS, a2: 1) != 0 )
          _LoggingSystem_Log(a1: LOG_SND_OPERATORS, a2: 1, a3: "Error: Unknown sound operator attribute %s\n", Name);
      }
      else
      {
        pVoidMem[1].m_flExecute[0] = 0.0;
        v8 = engineClient->GetLevelNameShort(this: engineClient);
        if ( _V_strcmp(s1: v8, s2: v7) == 0 )
          pVoidMem[1].m_flExecute[0] = 1.0;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10048620
// Name: public: CSosOperatorMapName::CSosOperatorMapName(void)
// Source: json
//------------------------------------------------------------------------------
CSosOperatorMapName *__thiscall CSosOperatorMapName::CSosOperatorMapName(CSosOperatorMapName *this)
{
  CSosOperatorSystem *SoundOperatorSystem; // eax
  int m_Size; // [esp-8h] [ebp-1Ch]
  CSosOperator::OutputData_t outputData; // [esp+4h] [ebp-10h] BYREF
  int nIndex; // [esp+10h] [ebp-4h] BYREF

  CSosOperator::CSosOperator(this);
  this->__vftable = (CSosOperatorMapName_vtbl *)&CSosOperatorMapName::`vftable';
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
    pName: "get_map_name",
    element: (CSosOperator *const *)&nIndex);
  return this;
}

} // namespace engine_xlsp
