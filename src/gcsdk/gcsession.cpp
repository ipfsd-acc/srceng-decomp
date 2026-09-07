// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: gcsdk/gcsession.cpp
// Functions: 1
// ============================================================

#include "gcsdk\gcsession.h"

//------------------------------------------------------------------------------
// Address: 0x100314E0
// Name: public: void GCSDK::CGCGSSession::RemoveAllUsers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GCSDK::CGCGSSession::RemoveAllUsers(GCSDK::CGCGSSession *this)
{
  int i; // edi
  GCSDK::CGCBase *v3; // eax
  CTHash<GCSDK::CGCUserSession *,unsigned __int64>::RecHdr_t *UserSession; // eax
  const CSteamID *v5; // [esp-8h] [ebp-Ch]

  if ( this->m_vecUsers.m_Size != 0 )
  {
    this->PreRemoveAllUsers(this);
    for ( i = this->m_vecUsers.m_Size - 1; i >= 0; --i )
    {
      v5 = &this->m_vecUsers.m_Memory.m_pMemory[i];
      v3 = GCSDK::GGCBase();
      UserSession = GCSDK::CGCBase::FindUserSession(this: v3, steamID: v5);
      if ( UserSession != nullptr )
        ((void (__thiscall *)(CTHash<GCSDK::CGCUserSession *,unsigned __int64>::RecHdr_t *))UserSession->m_pRecHdrNext->m_nRunRatio)(a1: UserSession);
    }
    this->m_vecUsers.m_Size = 0;
    this->PostRemoveAllUsers(this);
  }
}
