// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: matchmaking/matchsystem.cpp
// Functions: 6
// ============================================================

#include "matchmaking\matchsystem.h"

//------------------------------------------------------------------------------
// Address: 0x10003DD0
// Name: public: virtual class IPlayerManager __near * CMatchSystem::GetPlayerManager(void)
// Source: json
//------------------------------------------------------------------------------
PlayerManager *__thiscall CMatchSystem::GetPlayerManager(CMatchSystem *this)
{
  return g_pPlayerManager;
}

//------------------------------------------------------------------------------
// Address: 0x10003DE0
// Name: public: virtual class IMatchVoice __near * CMatchSystem::GetMatchVoice(void)
// Source: json
//------------------------------------------------------------------------------
CMatchVoice *__thiscall CMatchSystem::GetMatchVoice(CMatchSystem *this)
{
  return g_pMatchVoice;
}

//------------------------------------------------------------------------------
// Address: 0x10003DF0
// Name: public: virtual class IServerManager __near * CMatchSystem::GetUserGroupsServerManager(void)
// Source: json
//------------------------------------------------------------------------------
CServerManager *__thiscall CMatchSystem::GetUserGroupsServerManager(CMatchSystem *this)
{
  return g_pServerManager;
}

//------------------------------------------------------------------------------
// Address: 0x10003E00
// Name: public: virtual class ISearchManager __near * CMatchSystem::CreateGameSearchManager(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
ISearchManager *__thiscall CMatchSystem::CreateGameSearchManager(CMatchSystem *this, KeyValues *pParams)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10003E10
// Name: public: virtual class IDatacenter __near * CMatchSystem::GetDatacenter(void)
// Source: json
//------------------------------------------------------------------------------
CDatacenter *__thiscall CMatchSystem::GetDatacenter(CMatchSystem *this)
{
  return g_pDatacenter;
}

//------------------------------------------------------------------------------
// Address: 0x10003E20
// Name: public: void CMatchSystem::Update(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSystem::Update(CMatchSystem *this)
{
  if ( g_pPlayerManager != nullptr )
    g_pPlayerManager->Update(this: g_pPlayerManager);
  if ( g_pServerManager != nullptr )
    SteamApiContext_Shutdown(this: g_pServerManager);
  if ( g_pDatacenter != nullptr )
    CDatacenter::Update(this: g_pDatacenter);
}

// ============================================================
// Overlay from matchmaking (Missing functions)
// ============================================================
namespace matchmaking {

//------------------------------------------------------------------------------
// Address: 0x1001EB60
// Name: public: virtual class IPlayerManager __near * CMatchSystem::GetPlayerManager(void)
// Source: json
//------------------------------------------------------------------------------
PlayerManager *__thiscall CMatchSystem::GetPlayerManager(CMatchSystem *this)
{
  return g_pPlayerManager;
}

//------------------------------------------------------------------------------
// Address: 0x1001EB70
// Name: public: virtual class IMatchVoice __near * CMatchSystem::GetMatchVoice(void)
// Source: json
//------------------------------------------------------------------------------
CMatchVoice *__thiscall CMatchSystem::GetMatchVoice(CMatchSystem *this)
{
  return g_pMatchVoice;
}

//------------------------------------------------------------------------------
// Address: 0x1001EB80
// Name: public: virtual class IServerManager __near * CMatchSystem::GetUserGroupsServerManager(void)
// Source: json
//------------------------------------------------------------------------------
CServerManager *__thiscall CMatchSystem::GetUserGroupsServerManager(CMatchSystem *this)
{
  return g_pServerManager;
}

//------------------------------------------------------------------------------
// Address: 0x1001EB90
// Name: public: virtual class ISearchManager __near * CMatchSystem::CreateGameSearchManager(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CSearchManager *__thiscall CMatchSystem::CreateGameSearchManager(CMatchSystem *this, KeyValues *pParams)
{
  CSearchManager *v2; // eax

  v2 = (CSearchManager *)operator new(nSize: 0x2Cu);
  if ( v2 != nullptr )
    return CSearchManager::CSearchManager(this: v2, pSearchParams: pParams);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1001EBB0
// Name: public: virtual class IDatacenter __near * CMatchSystem::GetDatacenter(void)
// Source: json
//------------------------------------------------------------------------------
CDatacenter *__thiscall CMatchSystem::GetDatacenter(CMatchSystem *this)
{
  return g_pDatacenter;
}

//------------------------------------------------------------------------------
// Address: 0x1001EBC0
// Name: public: virtual class IDlcManager __near * CMatchSystem::GetDlcManager(void)
// Source: json
//------------------------------------------------------------------------------
CDlcManager *__thiscall CMatchSystem::GetDlcManager(CMatchSystem *this)
{
  return g_pDlcManager;
}

//------------------------------------------------------------------------------
// Address: 0x1001EBD0
// Name: public: void CMatchSystem::Update(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSystem::Update(CMatchSystem *this)
{
  if ( g_pPlayerManager != nullptr )
    PlayerManager::Update(this: g_pPlayerManager);
  if ( g_pServerManager != nullptr )
    CServerManager::Update(this: g_pServerManager);
  CSearchManager::UpdateAll();
  if ( g_pLeaderboardRequestQueue != nullptr )
    g_pLeaderboardRequestQueue->Update(this: g_pLeaderboardRequestQueue);
  if ( g_pDatacenter != nullptr )
    CDatacenter::Update(this: g_pDatacenter);
  if ( g_pDlcManager != nullptr )
    CDlcManager::Update(this: g_pDlcManager);
}

} // namespace matchmaking

// ============================================================
// Overlay from matchmaking_ds (Missing functions)
// ============================================================
namespace matchmaking_ds {

//------------------------------------------------------------------------------
// Address: 0x10005F20
// Name: public: virtual class KeyValues __near * CDatacenterCmdBatchImpl::GetResult(int)
// Source: rtti_class
//------------------------------------------------------------------------------
ISearchManager *__thiscall CDatacenterCmdBatchImpl::GetResult(CMatchSystem *this, KeyValues *pParams)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10007AC0
// Name: public: virtual class IPlayerManager __near * CMatchSystem::GetPlayerManager(void)
// Source: json
//------------------------------------------------------------------------------
PlayerManager *__thiscall CMatchSystem::GetPlayerManager(CMatchSystem *this)
{
  return g_pPlayerManager;
}

//------------------------------------------------------------------------------
// Address: 0x10007AD0
// Name: public: virtual class IMatchVoice __near * CMatchSystem::GetMatchVoice(void)
// Source: json
//------------------------------------------------------------------------------
CMatchVoice *__thiscall CMatchSystem::GetMatchVoice(CMatchSystem *this)
{
  return g_pMatchVoice;
}

//------------------------------------------------------------------------------
// Address: 0x10007AE0
// Name: public: virtual class IServerManager __near * CMatchSystem::GetUserGroupsServerManager(void)
// Source: json
//------------------------------------------------------------------------------
CServerManager *__thiscall CMatchSystem::GetUserGroupsServerManager(CMatchSystem *this)
{
  return g_pServerManager;
}

//------------------------------------------------------------------------------
// Address: 0x10007AF0
// Name: public: virtual class IDatacenter __near * CMatchSystem::GetDatacenter(void)
// Source: json
//------------------------------------------------------------------------------
CDatacenter *__thiscall CMatchSystem::GetDatacenter(CMatchSystem *this)
{
  return g_pDatacenter;
}

//------------------------------------------------------------------------------
// Address: 0x10007B00
// Name: public: virtual class IDlcManager __near * CMatchSystem::GetDlcManager(void)
// Source: json
//------------------------------------------------------------------------------
CDlcManager *__thiscall CMatchSystem::GetDlcManager(CMatchSystem *this)
{
  return g_pDlcManager;
}

//------------------------------------------------------------------------------
// Address: 0x10007B10
// Name: public: void CMatchSystem::Update(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSystem::Update(CMatchSystem *this)
{
  if ( g_pPlayerManager != nullptr )
    g_pPlayerManager->Update(this: g_pPlayerManager);
  if ( g_pServerManager != nullptr )
    SteamApiContext_Shutdown(this: g_pServerManager);
  if ( g_pDatacenter != nullptr )
    CDatacenter::Update(this: g_pDatacenter);
  if ( g_pDlcManager != nullptr )
    CDlcManager::Update(this: g_pDlcManager);
}

//------------------------------------------------------------------------------
// Address: 0x10005F30
// Name: public: virtual void CDatacenterCmdBatchImpl::SetDestroyWhenFinished(bool)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDatacenterCmdBatchImpl::SetDestroyWhenFinished(
        CDatacenterCmdBatchImpl *this,
        bool bDestroyWhenFinished)
{
  this->m_bDestroyWhenFinished = bDestroyWhenFinished;
}

//------------------------------------------------------------------------------
// Address: 0x10005F40
// Name: public: virtual void CDatacenterCmdBatchImpl::SetNumRetriesAllowedPerCmd(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDatacenterCmdBatchImpl::SetNumRetriesAllowedPerCmd(
        CDatacenterCmdBatchImpl *this,
        int numRetriesAllowed)
{
  this->m_numRetriesAllowedPerCmd = numRetriesAllowed;
}

//------------------------------------------------------------------------------
// Address: 0x10005F50
// Name: public: virtual void CDatacenterCmdBatchImpl::SetRetryCmdTimeout(float)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDatacenterCmdBatchImpl::SetRetryCmdTimeout(CDatacenterCmdBatchImpl *this, float flRetryCmdTimeout)
{
  this->m_flRetryCmdTimeout = flRetryCmdTimeout;
}

//------------------------------------------------------------------------------
// Address: 0x10005F70
// Name: public: virtual void CDatacenterCmdBatchImpl::Update(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDatacenterCmdBatchImpl::Update(CDatacenterCmdBatchImpl *this)
{
  if ( this->m_bDestroyWhenFinished )
    this->Destroy(this);
}

//------------------------------------------------------------------------------
// Address: 0x10007B50
// Name: public: void CDlcManager::Update(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDlcManager::Update(CDlcManager *this)
{
  if ( this->m_eState == STATE_IDLE && this->m_bNeedToUpdateFileSystem )
  {
    this->m_bNeedToUpdateFileSystem = false;
    g_pFullFileSystem->DiscoverDLC(this: g_pFullFileSystem, a2: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10007B80
// Name: public: virtual void CDlcManager::RequestDlcUpdate(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDlcManager::RequestDlcUpdate(CDlcManager *this)
{
  CDlcManager::State_t m_eState; // eax
  int v3; // eax
  const char *v4; // eax

  m_eState = this->m_eState;
  if ( m_eState <= STATE_IDLE )
  {
    if ( m_eState != STATE_IDLE || this->m_bNeedToDiscoverAllDlcs )
    {
      v3 = _CommandLine();
      v4 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v3 + 8))(a1: v3);
      if ( V_stristr(pStr: v4, pSearch: "-dlc") != nullptr )
      {
        this->m_eState = STATE_IDLE;
        *(_WORD *)&this->m_bNeedToDiscoverAllDlcs = 256;
      }
    }
    else
    {
      _Msg(a1: "DLCMANAGER: RequestDlcUpdate has no new content.\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10007BE0
// Name: public: virtual bool CDlcManager::IsDlcUpdateFinished(bool)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __thiscall CDlcManager::IsDlcUpdateFinished(CDlcManager *this, bool bWaitForFinish)
{
  double v4; // st7
  float flTimestamp; // [esp+14h] [ebp+8h]

  if ( this->m_eState != STATE_IDLE )
  {
    if ( !bWaitForFinish )
      return 0;
    flTimestamp = _Plat_FloatTime();
    while ( this->m_eState != STATE_IDLE )
      _ThreadSleep(a1: 1);
    v4 = _Plat_FloatTime();
    _Warning(a1: "DLCMANAGER: Forcing wait for update to finish stalled for %.3f sec\n", v4 - flTimestamp);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10007C90
// Name: mm_dlc_debugprint
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl mm_dlc_debugprint()
{
  KeyValues *v0; // eax
  IKeyValuesDumpContext pDump; // [esp+0h] [ebp-8h] BYREF
  int v2; // [esp+4h] [ebp-4h]

  v0 = g_pDlcManager->GetDataInfo(this: g_pDlcManager);
  pDump.__vftable = (IKeyValuesDumpContext_vtbl *)&CKeyValuesDumpContextAsDevMsg::`vftable';
  v2 = 1;
  KeyValues::Dump(this: v0, &pDump, nIndentLevel: 1);
}

} // namespace matchmaking_ds
