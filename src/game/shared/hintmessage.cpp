// Original: game/shared/hintmessage.cpp
// Functions: stubbed / inlined in this build
// ============================================================

#include "game\shared\hintmessage.h"

// Stub: CUtlMemory<char *,int>::Grow
void Grow() {}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x1015C8E0
// Name: public: void CHintMessage::Send(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHintMessage::Send(CHintMessage *this, CBasePlayer *client)
{
  CSingleUserRecipientFilter user; // [esp+8h] [ebp-20h] BYREF

  if ( client != nullptr )
  {
    CRecipientFilter::CRecipientFilter(this: &user);
    user.__vftable = (CSingleUserRecipientFilter_vtbl *)&CSingleUserRecipientFilter::`vftable';
    CRecipientFilter::AddRecipient(this: &user, player: client);
    CRecipientFilter::MakeReliable(this: (CFmtStrN<1024> *)&user);
    UserMessageBegin(filter: &user, messagename: "HintText");
    MessageWriteString(sz: this->m_hintString);
    MessageEnd();
    CRecipientFilter::~CRecipientFilter(this: &user);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015C940
// Name: public: bool CHintMessage::IsEquivalent(char const __near *,class CUtlVector<char const __near *,class CUtlMemory<char const __near *,int>> __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHintMessage::IsEquivalent(
        CHintMessage *this,
        const char *hintString,
        CUtlVector<char const *,CUtlMemory<char const *,int> > *args)
{
  int m_Size; // eax
  int v6; // esi
  char *v7; // ecx

  if ( hintString == this->m_hintString || _V_stricmp(s1: hintString, s2: this->m_hintString) == 0 )
  {
    if ( args == nullptr )
      return this->m_args.m_Size == 0;
    m_Size = args->m_Size;
    if ( m_Size == this->m_args.m_Size )
    {
      v6 = 0;
      if ( m_Size > 0 )
      {
        do
        {
          v7 = (char *)args->m_Memory.m_pMemory[v6];
          if ( v7 != this->m_args.m_Memory.m_pMemory[v6]
            && _V_stricmp(s1: v7, s2: this->m_args.m_Memory.m_pMemory[v6]) != 0 )
          {
            break;
          }
          ++v6;
        }
        while ( v6 < args->m_Size );
      }
    }
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x1015C9B0
// Name: public: void CHintMessageTimers::RemoveTimer(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHintMessageTimers::RemoveTimer(CHintMessageTimers *this, int iHintID)
{
  int m_Size; // ecx
  int v4; // eax
  CHintMessageTimers::hintmessagetime_t **i; // edx
  int v6; // ecx

  m_Size = this->m_Timers.m_Size;
  v4 = 0;
  if ( m_Size > 0 )
  {
    for ( i = this->m_Timers.m_Memory.m_pMemory; (*i)->iHintID != iHintID; ++i )
    {
      if ( ++v4 >= m_Size )
        return;
    }
    if ( v4 != -1 )
    {
      v6 = m_Size - v4 - 1;
      if ( v6 > 0 )
        _V_memmove(
          dest: &this->m_Timers.m_Memory.m_pMemory[v4],
          src: &this->m_Timers.m_Memory.m_pMemory[v4 + 1],
          count: 4 * v6);
      --this->m_Timers.m_Size;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015CA10
// Name: public: CHintMessageTimers::hintmessagetime_t::~hintmessagetime_t(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHintMessageTimers::hintmessagetime_t::~hintmessagetime_t(CHintMessageTimers::hintmessagetime_t *this)
{
  int i; // edi
  char **m_pMemory; // eax

  for ( i = 0; i < this->args.m_Size; ++i )
    free(pMem: this->args.m_Memory.m_pMemory[i]);
  this->args.m_Size = 0;
  if ( this->args.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->args.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->args.m_Memory.m_pMemory);
      this->args.m_Memory.m_pMemory = nullptr;
    }
    this->args.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->args.m_Memory.m_pMemory;
  this->args.m_pElements = m_pMemory;
  if ( this->args.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->args.m_Memory.m_pMemory = nullptr;
    }
    this->args.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015CA90
// Name: public: CHintMessage::~CHintMessage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHintMessage::~CHintMessage(CHintMessage *this)
{
  int i; // edi
  char **m_pMemory; // eax

  for ( i = 0; i < this->m_args.m_Size; ++i )
    free(pMem: this->m_args.m_Memory.m_pMemory[i]);
  this->m_args.m_Size = 0;
  if ( this->m_args.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_args.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_args.m_Memory.m_pMemory);
      this->m_args.m_Memory.m_pMemory = nullptr;
    }
    this->m_args.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_args.m_Memory.m_pMemory;
  this->m_args.m_pElements = m_pMemory;
  if ( this->m_args.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_args.m_Memory.m_pMemory = nullptr;
    }
    this->m_args.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015CB10
// Name: public: CHintMessageQueue::CHintMessageQueue(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
CHintMessageQueue *__thiscall CHintMessageQueue::CHintMessageQueue(CHintMessageQueue *this, CBasePlayer *pPlayer)
{
  this->m_messages.m_Memory.m_pMemory = nullptr;
  this->m_messages.m_Memory.m_nAllocationCount = 0;
  this->m_messages.m_Memory.m_nGrowSize = 0;
  this->m_messages.m_Size = 0;
  this->m_messages.m_pElements = nullptr;
  this->m_pPlayer = pPlayer;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1015CB30
// Name: public: void CHintMessageQueue::Update(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHintMessageQueue::Update(CHintMessageQueue *this)
{
  CBasePlayer *m_pPlayer; // eax
  CHintMessage **m_pMemory; // ecx
  CHintMessage *v4; // edi

  m_pPlayer = this->m_pPlayer;
  if ( m_pPlayer != nullptr && this->m_messages.m_Size != 0 )
  {
    m_pMemory = this->m_messages.m_Memory.m_pMemory;
    v4 = *m_pMemory;
    this->m_tmMessageEnd = gpGlobals->curtime + (*m_pMemory)->m_duration;
    CHintMessage::Send(this: v4, client: m_pPlayer);
    CHintMessage::~CHintMessage(this: v4);
    free(pMem: v4);
    if ( this->m_messages.m_Size - 1 > 0 )
      _V_memmove(
        dest: this->m_messages.m_Memory.m_pMemory,
        src: this->m_messages.m_Memory.m_pMemory + 1,
        count: 4 * (this->m_messages.m_Size - 1));
    --this->m_messages.m_Size;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015CBA0
// Name: public: void CHintMessageTimers::Update(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHintMessageTimers::Update(CHintMessageTimers *this)
{
  int i; // edi
  CHintMessageTimers::hintmessagetime_t **v3; // ecx
  CHintMessageTimers::hintmessagetime_t *v4; // eax
  bool v5; // zf
  CHintMessageTimers::hintmessagetime_t *v6; // eax

  if ( this->m_pHintSystem != nullptr )
  {
    for ( i = 0; i < this->m_Timers.m_Size; ++i )
    {
      v3 = &this->m_Timers.m_Memory.m_pMemory[i];
      v4 = *v3;
      if ( (*v3)->timer.m_fIsRunning && (float)(gpGlobals->curtime - v4->timer.m_next) > -0.001 )
      {
        v5 = !CHintSystem::TimerShouldFire(this: this->m_pHintSystem, iHintID: v4->iHintID);
        v6 = this->m_Timers.m_Memory.m_pMemory[i];
        if ( !v5 )
        {
          CHintSystem::HintMessage(this: this->m_pHintSystem, hint: v6->iHintID, bForce: false, bOnlyIfClear: false);
          CHintMessageTimers::RemoveTimer(this, iHintID: this->m_Timers.m_Memory.m_pMemory[i]->iHintID);
          return;
        }
        v6->timer.m_fIsRunning = true;
        v6->timer.m_next = gpGlobals->curtime + v6->timer.m_interval;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015CC40
// Name: public: CHintMessage::CHintMessage(char const __near *,class CUtlVector<char const __near *,class CUtlMemory<char const __near *,int>> __near *,float)
// Source: json
//------------------------------------------------------------------------------
CHintMessage *__thiscall CHintMessage::CHintMessage(
        CHintMessage *this,
        const char *hintString,
        CUtlVector<char const *,CUtlMemory<char const *,int> > *args,
        float duration)
{
  CHintMessage *result; // eax
  CUtlMemory<vgui::TreeNode *,int> *p_m_args; // esi
  CUtlVector<char const *,CUtlMemory<char const *,int> > *v6; // edx
  const char *v7; // edi
  char *v8; // ebx
  vgui::TreeNode **m_pMemory; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v11; // ecx
  int v12; // eax
  char **v13; // eax
  int i; // [esp+Ch] [ebp+8h]

  result = this;
  p_m_args = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_args;
  this->m_args.m_Memory.m_pMemory = nullptr;
  this->m_args.m_Memory.m_nAllocationCount = 0;
  this->m_args.m_Memory.m_nGrowSize = 0;
  this->m_args.m_Size = 0;
  this->m_args.m_pElements = nullptr;
  this->m_hintString = hintString;
  v6 = args;
  this->m_duration = duration;
  if ( args != nullptr )
  {
    i = 0;
    if ( args->m_Size > 0 )
    {
      while ( 1 )
      {
        v7 = v6->m_Memory.m_pMemory[i];
        v8 = (char *)operator new(nSize: strlen(v7) + 1);
        strcpy(v8, v7);
        m_pMemory = p_m_args[1].m_pMemory;
        m_nAllocationCount = p_m_args->m_nAllocationCount;
        if ( (int)m_pMemory + 1 > m_nAllocationCount )
          CUtlMemory<CNavLadder *,int>::Grow(this: p_m_args, num: (int)m_pMemory - m_nAllocationCount + 1);
        ++p_m_args[1].m_pMemory;
        v11 = p_m_args->m_pMemory;
        v12 = (char *)p_m_args[1].m_pMemory - (char *)m_pMemory - 1;
        p_m_args[1].m_nAllocationCount = (int)p_m_args->m_pMemory;
        if ( v12 > 0 )
          _V_memmove(dest: &v11[(_DWORD)m_pMemory + 1], src: &v11[(_DWORD)m_pMemory], count: 4 * v12);
        v13 = (char **)&p_m_args->m_pMemory[(_DWORD)m_pMemory];
        if ( v13 != nullptr )
          *v13 = v8;
        if ( ++i >= args->m_Size )
          break;
        v6 = args;
      }
      return this;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1015CD30
// Name: public: void CHintMessageQueue::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHintMessageQueue::Reset(CHintMessageQueue *this)
{
  int v2; // edi
  CHintMessage **m_pMemory; // eax
  CHintMessage *v4; // ebx

  v2 = 0;
  this->m_tmMessageEnd = 0.0;
  if ( this->m_messages.m_Size <= 0 )
  {
    this->m_messages.m_Size = 0;
  }
  else
  {
    do
    {
      m_pMemory = this->m_messages.m_Memory.m_pMemory;
      v4 = m_pMemory[v2];
      if ( v4 != nullptr )
      {
        CHintMessage::~CHintMessage(this: m_pMemory[v2]);
        free(pMem: v4);
      }
      ++v2;
    }
    while ( v2 < this->m_messages.m_Size );
    this->m_messages.m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015CD80
// Name: public: bool CHintMessageQueue::AddMessage(char const __near *,float,class CUtlVector<char const __near *,class CUtlMemory<char const __near *,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHintMessageQueue::AddMessage(
        CHintMessageQueue *this,
        const char *message,
        float duration,
        CUtlVector<char const *,CUtlMemory<char const *,int> > *args)
{
  int v6; // esi
  CHintMessage *v7; // eax
  CHintMessage *v8; // ebx
  int m_nAllocationCount; // eax
  CUtlMemory<vgui::TreeNode *,int> *p_m_messages; // esi
  int m_Size; // edi
  vgui::TreeNode **m_pMemory; // ecx
  int v13; // eax
  CHintMessage **v14; // eax

  if ( this->m_pPlayer == nullptr )
    return 0;
  v6 = 0;
  if ( this->m_messages.m_Size <= 0 )
  {
LABEL_6:
    v7 = (CHintMessage *)operator new(nSize: 0x1Cu);
    if ( v7 != nullptr )
      v8 = CHintMessage::CHintMessage(this: v7, hintString: message, args, duration);
    else
      v8 = nullptr;
    m_nAllocationCount = this->m_messages.m_Memory.m_nAllocationCount;
    p_m_messages = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_messages;
    m_Size = this->m_messages.m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CNavLadder *,int>::Grow(this: p_m_messages, num: m_Size - m_nAllocationCount + 1);
    ++p_m_messages[1].m_pMemory;
    m_pMemory = p_m_messages->m_pMemory;
    v13 = (int)p_m_messages[1].m_pMemory - m_Size - 1;
    p_m_messages[1].m_nAllocationCount = (int)p_m_messages->m_pMemory;
    if ( v13 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v13);
    v14 = (CHintMessage **)&p_m_messages->m_pMemory[m_Size];
    if ( v14 != nullptr )
      *v14 = v8;
  }
  else
  {
    while ( !CHintMessage::IsEquivalent(this: this->m_messages.m_Memory.m_pMemory[v6], hintString: message, args) )
    {
      if ( ++v6 >= this->m_messages.m_Size )
        goto LABEL_6;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1015CE50
// Name: public: void CHintMessageTimers::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHintMessageTimers::Reset(CHintMessageTimers *this)
{
  int v2; // edi
  CHintMessageTimers::hintmessagetime_t *v3; // ebx

  v2 = 0;
  if ( this->m_Timers.m_Size <= 0 )
  {
    this->m_Timers.m_Size = 0;
  }
  else
  {
    do
    {
      v3 = this->m_Timers.m_Memory.m_pMemory[v2];
      if ( v3 != nullptr )
      {
        CHintMessageTimers::hintmessagetime_t::~hintmessagetime_t(this: this->m_Timers.m_Memory.m_pMemory[v2]);
        free(pMem: v3);
      }
      ++v2;
    }
    while ( v2 < this->m_Timers.m_Size );
    this->m_Timers.m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015CE90
// Name: public: void CHintMessageTimers::AddTimer(int,float,float,class CUtlVector<char const __near *,class CUtlMemory<char const __near *,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHintMessageTimers::AddTimer(
        CHintMessageTimers *this,
        int iHintID,
        float timer_duration,
        float message_duration,
        CUtlVector<char const *,CUtlMemory<char const *,int> > *args)
{
  int v6; // eax
  CHintMessageTimers::hintmessagetime_t **m_pMemory; // ecx
  CHintMessageTimers::hintmessagetime_t *v8; // eax
  CHintMessageTimers::hintmessagetime_t *v9; // edi
  CUtlVector<char const *,CUtlMemory<char const *,int> > *v10; // eax
  CUtlMemory<vgui::TreeNode *,int> *p_args; // esi
  const char *v12; // edi
  vgui::TreeNode **v13; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v15; // ecx
  int v16; // eax
  char **v17; // eax
  int m_Size; // esi
  int v19; // eax
  CHintMessageTimers::hintmessagetime_t **v20; // ecx
  int v21; // eax
  CHintMessageTimers::hintmessagetime_t **v22; // eax
  int i; // [esp+14h] [ebp+8h]
  CHintMessageTimers::hintmessagetime_t *newTimer; // [esp+18h] [ebp+Ch]
  char *message_durationa; // [esp+1Ch] [ebp+10h]

  v6 = 0;
  if ( this->m_Timers.m_Size <= 0 )
    goto LABEL_7;
  m_pMemory = this->m_Timers.m_Memory.m_pMemory;
  while ( (*m_pMemory)->iHintID != iHintID )
  {
    ++v6;
    ++m_pMemory;
    if ( v6 >= this->m_Timers.m_Size )
      goto LABEL_7;
  }
  if ( v6 == -1 )
  {
LABEL_7:
    v8 = (CHintMessageTimers::hintmessagetime_t *)operator new(nSize: 0x28u);
    if ( v8 != nullptr )
    {
      v8->timer.m_next = -1.0;
      v8->timer.m_interval = timer_duration;
      v8->timer.m_fIsRunning = false;
      v8->args.m_Memory.m_pMemory = nullptr;
      v8->args.m_Memory.m_nAllocationCount = 0;
      v8->args.m_Memory.m_nGrowSize = 0;
      v8->args.m_Size = 0;
      v8->args.m_pElements = nullptr;
      v9 = v8;
      v8->iHintID = 0;
      v8->flMessageDuration = 6.0;
      newTimer = v8;
    }
    else
    {
      newTimer = nullptr;
      v9 = nullptr;
    }
    v9->iHintID = iHintID;
    v10 = args;
    v9->flMessageDuration = message_duration;
    if ( args != nullptr )
    {
      i = 0;
      if ( args->m_Size > 0 )
      {
        p_args = (CUtlMemory<vgui::TreeNode *,int> *)&v9->args;
        while ( 1 )
        {
          v12 = v10->m_Memory.m_pMemory[i];
          message_durationa = (char *)operator new(nSize: strlen(v12) + 1);
          strcpy(message_durationa, v12);
          v13 = p_args[1].m_pMemory;
          m_nAllocationCount = p_args->m_nAllocationCount;
          if ( (int)v13 + 1 > m_nAllocationCount )
            CUtlMemory<CNavLadder *,int>::Grow(this: p_args, num: (int)v13 - m_nAllocationCount + 1);
          ++p_args[1].m_pMemory;
          v15 = p_args->m_pMemory;
          v16 = (char *)p_args[1].m_pMemory - (char *)v13 - 1;
          p_args[1].m_nAllocationCount = (int)p_args->m_pMemory;
          if ( v16 > 0 )
            _V_memmove(dest: &v15[(_DWORD)v13 + 1], src: &v15[(_DWORD)v13], count: 4 * v16);
          v17 = (char **)&p_args->m_pMemory[(_DWORD)v13];
          if ( v17 != nullptr )
            *v17 = message_durationa;
          if ( ++i >= args->m_Size )
            break;
          v10 = args;
        }
        v9 = newTimer;
      }
    }
    m_Size = this->m_Timers.m_Size;
    v19 = this->m_Timers.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > v19 )
      CUtlMemory<CNavLadder *,int>::Grow((CUtlMemory<vgui::TreeNode *,int> *)this, num: m_Size - v19 + 1);
    ++this->m_Timers.m_Size;
    v20 = this->m_Timers.m_Memory.m_pMemory;
    v21 = this->m_Timers.m_Size - m_Size - 1;
    this->m_Timers.m_pElements = this->m_Timers.m_Memory.m_pMemory;
    if ( v21 > 0 )
      _V_memmove(dest: &v20[m_Size + 1], src: &v20[m_Size], count: 4 * v21);
    v22 = &this->m_Timers.m_Memory.m_pMemory[m_Size];
    if ( v22 != nullptr )
      *v22 = v9;
  }
}

} // namespace server
