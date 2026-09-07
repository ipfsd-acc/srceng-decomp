// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/cstrike15/point_surroundtest.cpp
// Functions: 3
// ============================================================

#include "game\server\cstrike15\point_surroundtest.h"

//------------------------------------------------------------------------------
// Address: 0x102A5600
// Name: private: virtual struct datamap_t __near * CSurroundTest::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CSurroundTest::GetDataDescMap(CSurroundTest *this)
{
  return &CSurroundTest::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x102A5620
// Name: public: void CSurroundTest::FireCorrectOutput(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSurroundTest::FireCorrectOutput(CSurroundTest *this, inputdata_t *inputdata)
{
  ConVar *v3; // eax
  ConVar *m_pParent; // eax
  int m_nValue; // eax
  COutputEvent *p_m_On4Speakers; // ecx

  v3 = cvar->FindVar_2(this: cvar, a2: "snd_surround_speakers");
  if ( v3 != nullptr )
  {
    m_pParent = v3->m_pParent;
    if ( m_pParent != nullptr && (m_nValue = m_pParent->m_Value.m_nValue) != 0 && m_nValue != 2 )
    {
      if ( m_nValue == 4 )
      {
        p_m_On4Speakers = &this->m_On4Speakers;
      }
      else
      {
        if ( m_nValue != 5 )
          return;
        p_m_On4Speakers = &this->m_On51Speakers;
      }
    }
    else
    {
      p_m_On4Speakers = &this->m_On2Speakers;
    }
    COutputEvent::FireOutput(this: p_m_On4Speakers, pActivator: this, pCaller: this, fDelay: 0.0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10410520
// Name: CSurroundTest_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CSurroundTest_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CSurroundTest>();
  CSurroundTest_DataDescInit::g_DataMapHolder = result;
  return result;
}
