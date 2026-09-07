// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/cl_splitscreen.cpp
// Functions: 14
// ============================================================

#include "engine\cl_splitscreen.h"

//------------------------------------------------------------------------------
// Address: 0x10090870
// Name: public: virtual bool CSplitScreen::AddBaseUser(int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSplitScreen::AddBaseUser(CSplitScreen *this, int nSlot, int nPlayerIndex)
{
  CSplitScreen::SplitPlayer_t *v3; // eax

  v3 = this->m_SplitScreenPlayers[nSlot];
  v3->m_bActive = true;
  v3->m_Client.m_nSplitScreenSlot = nSlot;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10090890
// Name: public: virtual int CSplitScreen::GetSplitScreenPlayerEntity(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSplitScreen::GetSplitScreenPlayerEntity(CSplitScreen *this, int nSlot)
{
  CSplitScreen::SplitPlayer_t *v2; // eax

  if ( nSlot >= 0 && nSlot < host_state.max_splitscreen_players && (v2 = this->m_SplitScreenPlayers[nSlot])->m_bActive )
    return v2->m_Client.m_nPlayerSlot + 1;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x100908C0
// Name: public: virtual class INetChannel __near * CSplitScreen::GetSplitScreenPlayerNetChan(int)
// Source: json
//------------------------------------------------------------------------------
INetChannel *__thiscall CSplitScreen::GetSplitScreenPlayerNetChan(CSplitScreen *this, int nSlot)
{
  CSplitScreen::SplitPlayer_t *v2; // eax

  if ( nSlot >= 0 && nSlot < host_state.max_splitscreen_players && (v2 = this->m_SplitScreenPlayers[nSlot])->m_bActive )
    return v2->m_Client.m_NetChannel;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100908F0
// Name: public: virtual bool CSplitScreen::IsValidSplitScreenSlot(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSplitScreen::IsValidSplitScreenSlot(CSplitScreen *this, int nSlot)
{
  return nSlot >= 0 && nSlot < host_state.max_splitscreen_players && this->m_SplitScreenPlayers[nSlot]->m_bActive;
}

//------------------------------------------------------------------------------
// Address: 0x10090920
// Name: public: virtual int CSplitScreen::NextValidSplitScreenSlot(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSplitScreen::NextValidSplitScreenSlot(CSplitScreen *this, int nPreviousSlot)
{
  int result; // eax
  CSplitScreen::SplitPlayer_t **i; // ecx

  result = nPreviousSlot + 1;
  if ( nPreviousSlot + 1 >= host_state.max_splitscreen_players )
    return -1;
  for ( i = &this->m_SplitScreenPlayers[result]; !(*i)->m_bActive; ++i )
  {
    if ( ++result >= host_state.max_splitscreen_players )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10090950
// Name: public: virtual bool CSplitScreen::IsDisconnecting(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSplitScreen::IsDisconnecting(CSplitScreen *this, int nSlot)
{
  return nSlot >= 0
      && nSlot < host_state.max_splitscreen_players
      && this->m_SplitScreenPlayers[nSlot]->m_Client.m_nSignonState == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10090980
// Name: public: virtual void CSplitScreen::SetDisconnecting(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSplitScreen::SetDisconnecting(CSplitScreen *this, int nSlot, bool bState)
{
  if ( nSlot >= 0 && nSlot < host_state.max_splitscreen_players )
    this->m_SplitScreenPlayers[nSlot]->m_Client.m_nSignonState = bState ? 0 : 6;
}

//------------------------------------------------------------------------------
// Address: 0x100909B0
// Name: class CClientState __near & GetLocalClient(int)
// Source: json
//------------------------------------------------------------------------------
CClientState *__cdecl GetLocalClient(int nSlot)
{
  int v1; // eax

  v1 = nSlot;
  if ( nSlot == -1 )
    v1 = g_SplitScreenMgr.GetActiveSplitScreenPlayerSlot(this: &g_SplitScreenMgr);
  return &g_SplitScreenMgr.m_SplitScreenPlayers[v1]->m_Client;
}

//------------------------------------------------------------------------------
// Address: 0x100909E0
// Name: class CClientState __near & GetBaseLocalClient(void)
// Source: json
//------------------------------------------------------------------------------
CClientState *__cdecl GetBaseLocalClient()
{
  return &g_SplitScreenMgr.m_SplitScreenPlayers[0]->m_Client;
}

//------------------------------------------------------------------------------
// Address: 0x100909F0
// Name: public: virtual bool CSplitScreen::Init(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSplitScreen::Init(CSplitScreen *this)
{
  _WORD *v2; // esi
  _WORD *v3; // eax
  __int16 v4; // cx
  int v5; // esi
  CSplitScreen::SplitPlayer_t **m_SplitScreenPlayers; // ebx
  CSplitScreen::SplitPlayer_t *v7; // eax
  CSplitScreen::SplitPlayer_t *v8; // edi
  CSplitScreen::SplitPlayer_t *v9; // eax
  bool v10; // cl
  bool v11; // dl

  this->m_bInitialized = true;
  v2 = GenericThreadLocals::CThreadLocalBase::Get(this: &this->m_SplitSlot);
  if ( v2 == nullptr )
  {
    v3 = MemAlloc_Alloc(nSize: 4u);
    if ( v3 != nullptr )
    {
      v3[1] &= 0xFFFCu;
      *v3 = 0;
      v2 = v3;
    }
    else
    {
      v2 = nullptr;
    }
    GenericThreadLocals::CThreadLocalBase::Set(this: &this->m_SplitSlot, a2: v2);
  }
  v4 = v2[1] & 0xFFFC | 2;
  *v2 = 0;
  v2[1] = v4;
  this->m_nActiveSplitScreenUserCount = 1;
  v5 = 0;
  m_SplitScreenPlayers = this->m_SplitScreenPlayers;
  do
  {
    v7 = (CSplitScreen::SplitPlayer_t *)MemAlloc_Alloc(nSize: 0x18FA8u);
    v8 = v7;
    if ( v7 != nullptr )
    {
      v7->m_bActive = false;
      CClientState::CClientState(this: &v7->m_Client);
      v9 = v8;
    }
    else
    {
      v9 = nullptr;
    }
    v10 = v5 == 0;
    v11 = v5 != 0;
    *m_SplitScreenPlayers = v9;
    ++v5;
    ++m_SplitScreenPlayers;
    v9->m_bActive = v10;
    v9->m_Client.m_bSplitScreenUser = v11;
  }
  while ( v5 < 2 );
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10090AB0
// Name: public: virtual bool CSplitScreen::AddSplitScreenUser(int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSplitScreen::AddSplitScreenUser(CSplitScreen *this, int nSlot, int nPlayerEntityIndex)
{
  CSplitScreen::SplitPlayer_t *v4; // esi
  void (__thiscall *Clear)(struct CClientState *); // eax
  INetChannel *v6; // eax
  void (__thiscall *SetDisconnecting)(struct CSplitScreen *, int, bool); // eax
  char szName[256]; // [esp+Ch] [ebp-10Ch] BYREF
  netadr_s adr; // [esp+10Ch] [ebp-Ch] BYREF

  v4 = this->m_SplitScreenPlayers[nSlot];
  if ( !v4->m_bActive )
  {
    netadr_s::SetIP(this: &adr, unIP: 0);
    netadr_s::SetPort(this: &adr, newport: 0);
    netadr_s::SetType(this: &adr, newtype: NA_IP);
    V_snprintf(pDest: szName, maxLen: 256, pFormat: "SPLIT%d", nSlot);
    Clear = v4->m_Client.Clear;
    v4->m_bActive = true;
    Clear(this: &v4->m_Client);
    v4->m_Client.m_nPlayerSlot = nPlayerEntityIndex - 1;
    v4->m_Client.m_nSplitScreenSlot = nSlot;
    v6 = NET_CreateNetChannel(socket: 0, &adr, name: szName, handler: &v4->m_Client, bForceNewChannel: true);
    v4->m_Client.m_NetChannel = v6;
    g_SplitScreenMgr.m_SplitScreenPlayers[0]->m_Client.m_NetChannel->AttachSplitPlayer(
      this: g_SplitScreenMgr.m_SplitScreenPlayers[0]->m_Client.m_NetChannel,
      a2: nSlot,
      a3: v6);
    v4->m_Client.m_nViewEntity = nPlayerEntityIndex;
    SetDisconnecting = this->SetDisconnecting;
    ++this->m_nActiveSplitScreenUserCount;
    SetDisconnecting(this, a2: nSlot, a3: false);
    ClientDLL_OnSplitScreenStateChanged();
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10090B80
// Name: public: virtual bool CSplitScreen::RemoveSplitScreenUser(int,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSplitScreen::RemoveSplitScreenUser(CSplitScreen *this, int nSlot, int nPlayerIndex)
{
  int v3; // eax
  CSplitScreen::SplitPlayer_t **i; // ecx
  CSplitScreen::SplitPlayer_t *v6; // esi

  v3 = 1;
  if ( host_state.max_splitscreen_players > 1 )
  {
    for ( i = &this->m_SplitScreenPlayers[1]; (*i)->m_Client.m_nPlayerSlot != nPlayerIndex - 1; ++i )
    {
      if ( ++v3 >= host_state.max_splitscreen_players )
      {
        LOBYTE(v3) = 1;
        return v3;
      }
    }
    if ( v3 != -1 )
    {
      v6 = this->m_SplitScreenPlayers[v3];
      if ( v6->m_Client.m_NetChannel != nullptr )
      {
        g_SplitScreenMgr.m_SplitScreenPlayers[0]->m_Client.m_NetChannel->DetachSplitPlayer(
          this: g_SplitScreenMgr.m_SplitScreenPlayers[0]->m_Client.m_NetChannel,
          a2: v3);
        v6->m_Client.m_NetChannel->Shutdown(this: v6->m_Client.m_NetChannel, a2: "RemoveSplitScreenUser");
        v6->m_Client.m_NetChannel = nullptr;
      }
      v6->m_Client.m_nPlayerSlot = -1;
      v6->m_bActive = false;
      this->SetDisconnecting(this, a2: nSlot, a3: true);
      --this->m_nActiveSplitScreenUserCount;
      ClientDLL_OnSplitScreenStateChanged();
    }
    LOBYTE(v3) = 1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10090C30
// Name: public: virtual bool CSplitScreen::SetLocalPlayerIsResolvable(char const __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSplitScreen::SetLocalPlayerIsResolvable(
        CSplitScreen *this,
        const char *pchContext,
        int line,
        bool bResolvable)
{
  GenericThreadLocals::CThreadLocalPtr<CSplitScreen::SplitSlot_t> *p_m_SplitSlot; // edi
  _BYTE *v5; // esi
  _WORD *v6; // eax
  bool result; // al

  p_m_SplitSlot = &this->m_SplitSlot;
  v5 = GenericThreadLocals::CThreadLocalBase::Get(this: &this->m_SplitSlot);
  if ( v5 == nullptr )
  {
    v6 = MemAlloc_Alloc(nSize: 4u);
    if ( v6 != nullptr )
    {
      v6[1] &= 0xFFFCu;
      *v6 = 0;
      v5 = v6;
    }
    else
    {
      v5 = nullptr;
    }
    GenericThreadLocals::CThreadLocalBase::Set(this: p_m_SplitSlot, a2: v5);
  }
  result = v5[2] & 1;
  *((_WORD *)v5 + 1) = *((_WORD *)v5 + 1) & 0xFFFE | bResolvable;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10090CA0
// Name: public: virtual void CSplitScreen::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSplitScreen::Shutdown(CSplitScreen *this)
{
  CSplitScreen::SplitPlayer_t **m_SplitScreenPlayers; // esi
  int i; // ebx
  CSplitScreen::SplitPlayer_t *v3; // edi

  m_SplitScreenPlayers = this->m_SplitScreenPlayers;
  for ( i = 2; i != 0; --i )
  {
    v3 = *m_SplitScreenPlayers;
    if ( *m_SplitScreenPlayers != nullptr )
    {
      CClientState::~CClientState(this: &v3->m_Client);
      free(pMem: v3);
    }
    *m_SplitScreenPlayers++ = nullptr;
  }
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10090520
// Name: public: virtual bool CSplitScreen::AddBaseUser(int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSplitScreen::AddBaseUser(CSplitScreen *this, int nSlot, int nPlayerIndex)
{
  CSplitScreen::SplitPlayer_t *v3; // eax

  v3 = this->m_SplitScreenPlayers[nSlot];
  v3->m_bActive = true;
  v3->m_Client.m_nSplitScreenSlot = nSlot;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10090540
// Name: public: virtual int CSplitScreen::GetSplitScreenPlayerEntity(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSplitScreen::GetSplitScreenPlayerEntity(CSplitScreen *this, int nSlot)
{
  CSplitScreen::SplitPlayer_t *v2; // eax

  if ( nSlot >= 0 && nSlot < host_state.max_splitscreen_players && (v2 = this->m_SplitScreenPlayers[nSlot])->m_bActive )
    return v2->m_Client.m_nPlayerSlot + 1;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10090570
// Name: public: virtual class INetChannel __near * CSplitScreen::GetSplitScreenPlayerNetChan(int)
// Source: json
//------------------------------------------------------------------------------
INetChannel *__thiscall CSplitScreen::GetSplitScreenPlayerNetChan(CSplitScreen *this, int nSlot)
{
  CSplitScreen::SplitPlayer_t *v2; // eax

  if ( nSlot >= 0 && nSlot < host_state.max_splitscreen_players && (v2 = this->m_SplitScreenPlayers[nSlot])->m_bActive )
    return v2->m_Client.m_NetChannel;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100905A0
// Name: public: virtual bool CSplitScreen::IsValidSplitScreenSlot(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSplitScreen::IsValidSplitScreenSlot(CSplitScreen *this, int nSlot)
{
  return nSlot >= 0 && nSlot < host_state.max_splitscreen_players && this->m_SplitScreenPlayers[nSlot]->m_bActive;
}

//------------------------------------------------------------------------------
// Address: 0x100905D0
// Name: public: virtual int CSplitScreen::NextValidSplitScreenSlot(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSplitScreen::NextValidSplitScreenSlot(CSplitScreen *this, int nPreviousSlot)
{
  int result; // eax
  CSplitScreen::SplitPlayer_t **i; // ecx

  result = nPreviousSlot + 1;
  if ( nPreviousSlot + 1 >= host_state.max_splitscreen_players )
    return -1;
  for ( i = &this->m_SplitScreenPlayers[result]; !(*i)->m_bActive; ++i )
  {
    if ( ++result >= host_state.max_splitscreen_players )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10090600
// Name: public: virtual bool CSplitScreen::IsDisconnecting(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSplitScreen::IsDisconnecting(CSplitScreen *this, int nSlot)
{
  return nSlot >= 0
      && nSlot < host_state.max_splitscreen_players
      && this->m_SplitScreenPlayers[nSlot]->m_Client.m_nSignonState == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10090630
// Name: public: virtual void CSplitScreen::SetDisconnecting(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSplitScreen::SetDisconnecting(CSplitScreen *this, int nSlot, bool bState)
{
  if ( nSlot >= 0 && nSlot < host_state.max_splitscreen_players )
    this->m_SplitScreenPlayers[nSlot]->m_Client.m_nSignonState = bState ? 0 : 6;
}

//------------------------------------------------------------------------------
// Address: 0x10090660
// Name: class CClientState __near & GetLocalClient(int)
// Source: json
//------------------------------------------------------------------------------
CClientState *__cdecl GetLocalClient(int nSlot)
{
  int v1; // eax

  v1 = nSlot;
  if ( nSlot == -1 )
    v1 = g_SplitScreenMgr.GetActiveSplitScreenPlayerSlot(this: &g_SplitScreenMgr);
  return &g_SplitScreenMgr.m_SplitScreenPlayers[v1]->m_Client;
}

//------------------------------------------------------------------------------
// Address: 0x10090690
// Name: class CClientState __near & GetBaseLocalClient(void)
// Source: json
//------------------------------------------------------------------------------
CClientState *__cdecl GetBaseLocalClient()
{
  return &g_SplitScreenMgr.m_SplitScreenPlayers[0]->m_Client;
}

//------------------------------------------------------------------------------
// Address: 0x100906A0
// Name: public: virtual bool CSplitScreen::Init(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSplitScreen::Init(CSplitScreen *this)
{
  _WORD *v2; // esi
  _WORD *v3; // eax
  __int16 v4; // cx
  int v5; // esi
  CSplitScreen::SplitPlayer_t **m_SplitScreenPlayers; // ebx
  CSplitScreen::SplitPlayer_t *v7; // eax
  CSplitScreen::SplitPlayer_t *v8; // edi
  CSplitScreen::SplitPlayer_t *v9; // eax
  bool v10; // cl
  bool v11; // dl

  this->m_bInitialized = true;
  v2 = GenericThreadLocals::CThreadLocalBase::Get(this: &this->m_SplitSlot);
  if ( v2 == nullptr )
  {
    v3 = MemAlloc_Alloc(nSize: 4u);
    if ( v3 != nullptr )
    {
      v3[1] &= 0xFFFCu;
      *v3 = 0;
      v2 = v3;
    }
    else
    {
      v2 = nullptr;
    }
    GenericThreadLocals::CThreadLocalBase::Set(this: &this->m_SplitSlot, a2: v2);
  }
  v4 = v2[1] & 0xFFFC | 2;
  *v2 = 0;
  v2[1] = v4;
  this->m_nActiveSplitScreenUserCount = 1;
  v5 = 0;
  m_SplitScreenPlayers = this->m_SplitScreenPlayers;
  do
  {
    v7 = (CSplitScreen::SplitPlayer_t *)MemAlloc_Alloc(nSize: 0x18FA8u);
    v8 = v7;
    if ( v7 != nullptr )
    {
      v7->m_bActive = false;
      CClientState::CClientState(this: &v7->m_Client);
      v9 = v8;
    }
    else
    {
      v9 = nullptr;
    }
    v10 = v5 == 0;
    v11 = v5 != 0;
    *m_SplitScreenPlayers = v9;
    ++v5;
    ++m_SplitScreenPlayers;
    v9->m_bActive = v10;
    v9->m_Client.m_bSplitScreenUser = v11;
  }
  while ( v5 < 2 );
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10090760
// Name: public: virtual bool CSplitScreen::AddSplitScreenUser(int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSplitScreen::AddSplitScreenUser(CSplitScreen *this, int nSlot, int nPlayerEntityIndex)
{
  CSplitScreen::SplitPlayer_t *v4; // esi
  void (__thiscall *Clear)(struct CClientState *); // eax
  CNetChan *v6; // eax
  void (__thiscall *SetDisconnecting)(struct CSplitScreen *, int, bool); // eax
  char szName[256]; // [esp+Ch] [ebp-10Ch] BYREF
  netadr_s adr; // [esp+10Ch] [ebp-Ch] BYREF

  v4 = this->m_SplitScreenPlayers[nSlot];
  if ( !v4->m_bActive )
  {
    netadr_s::SetIP(this: &adr, unIP: 0);
    netadr_s::SetPort(this: &adr, newport: 0);
    netadr_s::SetType(this: &adr, newtype: NA_IP);
    V_snprintf(pDest: szName, maxLen: 256, pFormat: "SPLIT%d", nSlot);
    Clear = v4->m_Client.Clear;
    v4->m_bActive = true;
    Clear(this: &v4->m_Client);
    v4->m_Client.m_nPlayerSlot = nPlayerEntityIndex - 1;
    v4->m_Client.m_nSplitScreenSlot = nSlot;
    v6 = NET_CreateNetChannel(socket: 0, &adr, name: szName, handler: &v4->m_Client, bForceNewChannel: true);
    v4->m_Client.m_NetChannel = v6;
    g_SplitScreenMgr.m_SplitScreenPlayers[0]->m_Client.m_NetChannel->AttachSplitPlayer(
      this: g_SplitScreenMgr.m_SplitScreenPlayers[0]->m_Client.m_NetChannel,
      a2: nSlot,
      a3: v6);
    v4->m_Client.m_nViewEntity = nPlayerEntityIndex;
    SetDisconnecting = this->SetDisconnecting;
    ++this->m_nActiveSplitScreenUserCount;
    SetDisconnecting(this, a2: nSlot, a3: false);
    ClientDLL_OnSplitScreenStateChanged();
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10090830
// Name: public: virtual bool CSplitScreen::RemoveSplitScreenUser(int,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSplitScreen::RemoveSplitScreenUser(CSplitScreen *this, int nSlot, int nPlayerIndex)
{
  int v3; // eax
  CSplitScreen::SplitPlayer_t **i; // ecx
  CSplitScreen::SplitPlayer_t *v6; // esi

  v3 = 1;
  if ( host_state.max_splitscreen_players > 1 )
  {
    for ( i = &this->m_SplitScreenPlayers[1]; (*i)->m_Client.m_nPlayerSlot != nPlayerIndex - 1; ++i )
    {
      if ( ++v3 >= host_state.max_splitscreen_players )
      {
        LOBYTE(v3) = 1;
        return v3;
      }
    }
    if ( v3 != -1 )
    {
      v6 = this->m_SplitScreenPlayers[v3];
      if ( v6->m_Client.m_NetChannel != nullptr )
      {
        g_SplitScreenMgr.m_SplitScreenPlayers[0]->m_Client.m_NetChannel->DetachSplitPlayer(
          this: g_SplitScreenMgr.m_SplitScreenPlayers[0]->m_Client.m_NetChannel,
          a2: v3);
        v6->m_Client.m_NetChannel->Shutdown(this: v6->m_Client.m_NetChannel, a2: "RemoveSplitScreenUser");
        v6->m_Client.m_NetChannel = nullptr;
      }
      v6->m_Client.m_nPlayerSlot = -1;
      v6->m_bActive = false;
      this->SetDisconnecting(this, a2: nSlot, a3: true);
      --this->m_nActiveSplitScreenUserCount;
      ClientDLL_OnSplitScreenStateChanged();
    }
    LOBYTE(v3) = 1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100908E0
// Name: public: virtual bool CSplitScreen::SetLocalPlayerIsResolvable(char const __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSplitScreen::SetLocalPlayerIsResolvable(
        CSplitScreen *this,
        const char *pchContext,
        int line,
        bool bResolvable)
{
  GenericThreadLocals::CThreadLocalPtr<CSplitScreen::SplitSlot_t> *p_m_SplitSlot; // edi
  _BYTE *v5; // esi
  _WORD *v6; // eax
  bool result; // al

  p_m_SplitSlot = &this->m_SplitSlot;
  v5 = GenericThreadLocals::CThreadLocalBase::Get(this: &this->m_SplitSlot);
  if ( v5 == nullptr )
  {
    v6 = MemAlloc_Alloc(nSize: 4u);
    if ( v6 != nullptr )
    {
      v6[1] &= 0xFFFCu;
      *v6 = 0;
      v5 = v6;
    }
    else
    {
      v5 = nullptr;
    }
    GenericThreadLocals::CThreadLocalBase::Set(this: p_m_SplitSlot, a2: v5);
  }
  result = v5[2] & 1;
  *((_WORD *)v5 + 1) = *((_WORD *)v5 + 1) & 0xFFFE | bResolvable;
  return result;
}

} // namespace engine_xlsp
