// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: gcsdk/gcsystemmsgs.cpp
// Functions: 1
// ============================================================

#include "gcsdk\gcsystemmsgs.h"

//------------------------------------------------------------------------------
// Address: 0x10019C80
// Name: void GCSDK::InitGCSystemMessageTypes(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GCSDK::InitGCSystemMessageTypes()
{
  if ( (_S1_4 & 1) == 0 )
  {
    _S1_4 |= 1u;
    GCSDK::CMessageListRegistration::CMessageListRegistration(
      this: &m_reg,
      pMsgInfo: GCSDK::g_MsgInfo,
      cMsgInfo: 19,
      pExtra: nullptr);
  }
}
