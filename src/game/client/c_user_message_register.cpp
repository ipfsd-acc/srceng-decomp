// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_user_message_register.cpp
// Functions: 2
// ============================================================

#include "game\client\c_user_message_register.h"

//------------------------------------------------------------------------------
// Address: 0x10093760
// Name: public: CUserMessageRegister::CUserMessageRegister(char const __near *,void (*)(class bf_read __near &))
// Source: json
//------------------------------------------------------------------------------
CUserMessageRegister *__thiscall CUserMessageRegister::CUserMessageRegister(
        CUserMessageRegister *this,
        const char *pMessageName,
        void (__cdecl *pHookFn)(bf_read *))
{
  this->m_pMessageName = pMessageName;
  this->m_pHookFn = pHookFn;
  this->m_pNext = CUserMessageRegister::s_pHead;
  CUserMessageRegister::s_pHead = this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10093790
// Name: public: static void CUserMessageRegister::RegisterAll(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CUserMessageRegister::RegisterAll()
{
  CUserMessageRegister *i; // esi

  for ( i = CUserMessageRegister::s_pHead; i != nullptr; i = i->m_pNext )
    CUserMessages::HookMessage(this: usermessages, name: i->m_pMessageName, hook: i->m_pHookFn);
}
