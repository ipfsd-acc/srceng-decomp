// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/ai_link.cpp
// Functions: 1
// ============================================================

#include "game\server\ai_link.h"

//------------------------------------------------------------------------------
// Address: 0x100581C0
// Name: private: CAI_Link::CAI_Link(void)
// Source: json
//------------------------------------------------------------------------------
CAI_Link *__thiscall CAI_Link::CAI_Link(CAI_Link *this)
{
  this->m_iSrcID = -1;
  this->m_timeStaleExpires = 0.0;
  this->m_iDestID = -1;
  this->m_LinkInfo = 0;
  this->m_pDynamicLink = nullptr;
  this->m_nDangerCount = 0;
  *(_QWORD *)this->m_iAcceptedMoveTypes = 0;
  *(_DWORD *)&this->m_iAcceptedMoveTypes[8] = 0;
  return this;
}
