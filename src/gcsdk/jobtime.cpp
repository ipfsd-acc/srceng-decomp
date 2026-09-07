// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: gcsdk/jobtime.cpp
// Functions: 5
// ============================================================

#include "gcsdk\jobtime.h"

//------------------------------------------------------------------------------
// Address: 0x10019990
// Name: public: GCSDK::CJobTime::CJobTime(void)
// Source: json
//------------------------------------------------------------------------------
GCSDK::CJobTime *__thiscall GCSDK::CJobTime::CJobTime(GCSDK::CJobTime *this)
{
  this->m_lTime = GCSDK::CJobTime::sm_lTimeCur;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100199B0
// Name: public: void GCSDK::CJobTime::SetToJobTime(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GCSDK::CJobTime::SetToJobTime(GCSDK::CJobTime *this)
{
  this->m_lTime = GCSDK::CJobTime::sm_lTimeCur;
}

//------------------------------------------------------------------------------
// Address: 0x100199D0
// Name: public: void GCSDK::CJobTime::SetFromJobTime(__int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GCSDK::CJobTime::SetFromJobTime(GCSDK::CJobTime *this, __int64 dMicroSecOffset)
{
  this->m_lTime = dMicroSecOffset + GCSDK::CJobTime::sm_lTimeCur;
}

//------------------------------------------------------------------------------
// Address: 0x100199F0
// Name: public: __int64 GCSDK::CJobTime::CServerMicroSecsPassed(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int64 __thiscall GCSDK::CJobTime::CServerMicroSecsPassed(GCSDK::CJobTime *this)
{
  return GCSDK::CJobTime::sm_lTimeCur - this->m_lTime;
}

//------------------------------------------------------------------------------
// Address: 0x10019A10
// Name: public: static void GCSDK::CJobTime::UpdateJobTime(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GCSDK::CJobTime::UpdateJobTime(int cMicroSecPerShellFrame)
{
  GCSDK::CJobTime::sm_lTimeCur += cMicroSecPerShellFrame;
}
