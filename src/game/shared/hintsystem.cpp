// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/hintsystem.cpp
// Functions: 2
// ============================================================

#include "game\shared\hintsystem.h"

//------------------------------------------------------------------------------
// Address: 0x100EC680
// Name: public: void CHintSystem::PlayedAHint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHintSystem::PlayedAHint(CHintSystem *this)
{
  this->m_flLastHintPlayedAt = *(float *)(gpGlobals.m_Index + 12);
}

//------------------------------------------------------------------------------
// Address: 0x100EC690
// Name: void HintClear(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl HintClear()
{
  C_BasePlayer *LocalPlayer; // esi
  int v1; // eax
  int v2; // ecx

  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  if ( LocalPlayer != nullptr && LocalPlayer->Hints(this: LocalPlayer) != nullptr )
  {
    v1 = (int)LocalPlayer->Hints(this: LocalPlayer);
    v2 = *(_DWORD *)(v1 + 20);
    if ( v2 != 0 )
      memset(dst: v2, value: nullptr, count: 4 * *(unsigned __int16 *)(v1 + 14));
  }
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x1015D040
// Name: public: void CHintSystem::Update(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHintSystem::Update(CHintSystem *this)
{
  CHintMessageQueue *m_pHintMessageQueue; // ecx
  CHintMessageTimers *m_pHintMessageTimers; // ecx

  m_pHintMessageQueue = this->m_pHintMessageQueue;
  if ( m_pHintMessageQueue != nullptr )
    CHintMessageQueue::Update(this: m_pHintMessageQueue);
  m_pHintMessageTimers = this->m_pHintMessageTimers;
  if ( m_pHintMessageTimers != nullptr )
    CHintMessageTimers::Update(this: m_pHintMessageTimers);
}

//------------------------------------------------------------------------------
// Address: 0x1015D060
// Name: public: void CHintSystem::ResetHintTimers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHintSystem::ResetHintTimers(CHintSystem *this)
{
  CHintMessageTimers::Reset(this: this->m_pHintMessageTimers);
}

//------------------------------------------------------------------------------
// Address: 0x1015D070
// Name: public: bool CHintSystem::HintIsCurrentlyVisible(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CHintSystem::HintIsCurrentlyVisible(CHintSystem *this)
{
  return (float)(gpGlobals->curtime - this->m_flLastHintPlayedAt) < 11.0;
}

//------------------------------------------------------------------------------
// Address: 0x1015D0A0
// Name: public: bool CHintSystem::TimerShouldFire(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHintSystem::TimerShouldFire(CHintSystem *this, int iHintID)
{
  int m_Size; // ebx
  int v3; // esi
  CHintSystem::onresethints_t *i; // edi
  CHintSystem *v6; // [esp+Ch] [ebp-4h]

  m_Size = this->m_RegisteredResetHints.m_Size;
  v3 = 0;
  v6 = this;
  if ( m_Size <= 0 )
    return true;
  for ( i = this->m_RegisteredResetHints.m_Memory.m_pMemory; ; ++i )
  {
    if ( i->iHintID == iHintID )
    {
      if ( i->bOnlyIfClear )
      {
        if ( CHintSystem::HintIsCurrentlyVisible(this) )
          return false;
        this = v6;
      }
      if ( i->pfnCallback != nullptr )
        break;
    }
    if ( ++v3 >= m_Size )
      return true;
  }
  return this->m_RegisteredResetHints.m_Memory.m_pMemory[v3].pfnCallback(a1: this->m_pPlayer);
}

//------------------------------------------------------------------------------
// Address: 0x1015D110
// Name: public: bool CHintSystem::HintMessage(int,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHintSystem::HintMessage(CHintSystem *this, int hint, bool bForce, bool bOnlyIfClear)
{
  const char **m_pszHintMessages; // edx
  CBasePlayer *m_pPlayer; // ecx
  const char *v8; // ebx
  CHintMessageQueue *m_pHintMessageQueue; // ecx
  unsigned int *v10; // eax

  if ( bOnlyIfClear && (float)(gpGlobals->curtime - this->m_flLastHintPlayedAt) < 11.0 )
    return 0;
  if ( !bForce && ((1 << (hint & 0x1F)) & this->m_HintHistory.m_pInt[hint >> 5]) != 0 )
    return 0;
  m_pszHintMessages = this->m_pszHintMessages;
  m_pPlayer = this->m_pPlayer;
  this->m_flLastHintPlayedAt = gpGlobals->curtime;
  v8 = m_pszHintMessages[hint];
  if ( m_pPlayer->IsNetClient(this: m_pPlayer) )
  {
    m_pHintMessageQueue = this->m_pHintMessageQueue;
    if ( m_pHintMessageQueue != nullptr && this->m_bShowHints )
      CHintMessageQueue::AddMessage(this: m_pHintMessageQueue, message: v8, duration: 6.0, args: nullptr);
  }
  v10 = &this->m_HintHistory.m_pInt[hint >> 5];
  *v10 |= 1 << (hint & 0x1F);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1015D1D0
// Name: public: void CHintSystem::ResetHints(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHintSystem::ResetHints(CHintSystem *this)
{
  CHintMessageTimers *m_pHintMessageTimers; // ecx
  int v3; // edx
  float *v4; // edx
  CHintMessageQueue *m_pHintMessageQueue; // esi
  int v6; // [esp+18h] [ebp-8h]
  int i; // [esp+1Ch] [ebp-4h]

  m_pHintMessageTimers = this->m_pHintMessageTimers;
  if ( m_pHintMessageTimers != nullptr )
  {
    CHintMessageTimers::Reset(this: m_pHintMessageTimers);
    i = 0;
    if ( this->m_RegisteredResetHints.m_Size > 0 )
    {
      v3 = 0;
      v6 = 0;
      do
      {
        v4 = (float *)((char *)&this->m_RegisteredResetHints.m_Memory.m_pMemory->iHintID + v3);
        if ( ((1 << (*(_DWORD *)v4 & 0x1F)) & this->m_HintHistory.m_pInt[*(int *)v4 >> 5]) == 0 )
          CHintMessageTimers::AddTimer(
            this: this->m_pHintMessageTimers,
            iHintID: *(_DWORD *)v4,
            timer_duration: v4[1],
            message_duration: 6.0,
            args: nullptr);
        v3 = v6 + 16;
        ++i;
        v6 += 16;
      }
      while ( i < this->m_RegisteredResetHints.m_Size );
    }
    m_pHintMessageQueue = this->m_pHintMessageQueue;
    if ( m_pHintMessageQueue != nullptr )
      CHintMessageQueue::Reset(this: m_pHintMessageQueue);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015D270
// Name: void HintClear(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl HintClear()
{
  CBasePlayer *CommandClient; // esi
  int v1; // eax
  int v2; // ecx

  CommandClient = UTIL_GetCommandClient();
  if ( CommandClient != nullptr && CommandClient->Hints(this: CommandClient) != nullptr )
  {
    v1 = (int)CommandClient->Hints(this: CommandClient);
    v2 = *(_DWORD *)(v1 + 20);
    if ( v2 != 0 )
      memset(dst: v2, value: nullptr, count: 4 * *(unsigned __int16 *)(v1 + 14));
  }
}

} // namespace server
