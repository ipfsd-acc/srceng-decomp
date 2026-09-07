// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: gcsdk/gcmsg.cpp
// Functions: 1
// ============================================================

#include "gcsdk\gcmsg.h"

//------------------------------------------------------------------------------
// Address: 0x10025CC0
// Name: public: char const __near * GCSDK::GCMsgHdrEx_t::GetHeaderDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall GCSDK::GCMsgHdrEx_t::GetHeaderDescription(GCSDK::GCMsgHdrEx_t *this)
{
  char *PchTempTextBuffer; // edi
  int CchTempTextBuffer; // eax
  const char *v5; // [esp-20h] [ebp-28h]
  unsigned __int64 m_ulSteamID; // [esp-1Ch] [ebp-24h]
  int m_nHdrVersion; // [esp-14h] [ebp-1Ch]
  unsigned __int64 m_JobIDSource; // [esp-10h] [ebp-18h]
  unsigned __int64 m_JobIDTarget; // [esp-8h] [ebp-10h]

  PchTempTextBuffer = GCSDK::GetPchTempTextBuffer();
  m_JobIDTarget = this->m_JobIDTarget;
  m_JobIDSource = this->m_JobIDSource;
  m_nHdrVersion = this->m_nHdrVersion;
  m_ulSteamID = this->m_ulSteamID;
  v5 = GCSDK::PchMsgNameFromEMsg(eMsg: this->m_eMsg);
  CchTempTextBuffer = GCSDK::GetCchTempTextBuffer();
  V_snprintf(
    pDest: PchTempTextBuffer,
    maxLen: CchTempTextBuffer,
    pFormat: "gc msg %s, SteamID %llu, version %hd, job source %llu, job target %llu",
    v5,
    m_ulSteamID,
    m_nHdrVersion,
    m_JobIDSource,
    m_JobIDTarget);
  return PchTempTextBuffer;
}
