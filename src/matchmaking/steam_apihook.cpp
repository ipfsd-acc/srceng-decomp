// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: matchmaking/steam_apihook.cpp
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x100022F0
// Name: void SteamApiContext_Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SteamApiContext_Shutdown(CServerManager *this)
{
  ;
}

// ============================================================
// Overlay from matchmaking (Missing functions)
// ============================================================
namespace matchmaking {

//------------------------------------------------------------------------------
// Address: 0x10005670
// Name: public: bool CSteamAPIContext::Init(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSteamAPIContext::Init(CSteamAPIContext *this)
{
  int HSteamPipe; // esi
  int v4; // eax
  ISteamUser *v5; // eax
  int v6; // eax
  ISteamFriends *v7; // eax
  int v8; // eax
  ISteamUtils *v9; // eax
  int v10; // eax
  ISteamMatchmaking *v11; // eax
  int v12; // eax
  ISteamMatchmakingServers *v13; // eax
  int v14; // eax
  ISteamUserStats *v15; // eax
  int v16; // eax
  ISteamApps *v17; // eax
  int v18; // eax
  ISteamNetworking *v19; // eax
  int v20; // eax
  ISteamRemoteStorage *v21; // eax
  int hSteamUser; // [esp+8h] [ebp-4h]

  if ( _SteamClient() == 0 )
    return false;
  hSteamUser = _SteamAPI_GetHSteamUser();
  HSteamPipe = _SteamAPI_GetHSteamPipe();
  v4 = _SteamClient();
  v5 = (ISteamUser *)(*(int (__thiscall **)(int, int, int, const char *))(*(_DWORD *)v4 + 20))(
                       a1: v4,
                       a2: hSteamUser,
                       a3: HSteamPipe,
                       a4: "SteamUser014");
  this->m_pSteamUser = v5;
  if ( v5 == nullptr )
    return false;
  v6 = _SteamClient();
  v7 = (ISteamFriends *)(*(int (__thiscall **)(int, int, int, const char *))(*(_DWORD *)v6 + 32))(
                          a1: v6,
                          a2: hSteamUser,
                          a3: HSteamPipe,
                          a4: "SteamFriends008");
  this->m_pSteamFriends = v7;
  if ( v7 == nullptr )
    return false;
  v8 = _SteamClient();
  v9 = (ISteamUtils *)(*(int (__thiscall **)(int, int, const char *))(*(_DWORD *)v8 + 36))(
                        a1: v8,
                        a2: HSteamPipe,
                        a3: "SteamUtils005");
  this->m_pSteamUtils = v9;
  if ( v9 == nullptr )
    return false;
  v10 = _SteamClient();
  v11 = (ISteamMatchmaking *)(*(int (__thiscall **)(int, int, int, const char *))(*(_DWORD *)v10 + 40))(
                               a1: v10,
                               a2: hSteamUser,
                               a3: HSteamPipe,
                               a4: "SteamMatchMaking008");
  this->m_pSteamMatchmaking = v11;
  if ( v11 == nullptr )
    return false;
  v12 = _SteamClient();
  v13 = (ISteamMatchmakingServers *)(*(int (__thiscall **)(int, int, int, const char *))(*(_DWORD *)v12 + 48))(
                                      a1: v12,
                                      a2: hSteamUser,
                                      a3: HSteamPipe,
                                      a4: "SteamMatchMakingServers002");
  this->m_pSteamMatchmakingServers = v13;
  if ( v13 == nullptr )
    return false;
  v14 = _SteamClient();
  v15 = (ISteamUserStats *)(*(int (__thiscall **)(int, int, int, const char *))(*(_DWORD *)v14 + 56))(
                             a1: v14,
                             a2: hSteamUser,
                             a3: HSteamPipe,
                             a4: "STEAMUSERSTATS_INTERFACE_VERSION009");
  this->m_pSteamUserStats = v15;
  if ( v15 == nullptr )
    return false;
  v16 = _SteamClient();
  v17 = (ISteamApps *)(*(int (__thiscall **)(int, int, int, const char *))(*(_DWORD *)v16 + 64))(
                        a1: v16,
                        a2: hSteamUser,
                        a3: HSteamPipe,
                        a4: "STEAMAPPS_INTERFACE_VERSION004");
  this->m_pSteamApps = v17;
  if ( v17 == nullptr )
    return false;
  v18 = _SteamClient();
  v19 = (ISteamNetworking *)(*(int (__thiscall **)(int, int, int, const char *))(*(_DWORD *)v18 + 68))(
                              a1: v18,
                              a2: hSteamUser,
                              a3: HSteamPipe,
                              a4: "SteamNetworking005");
  this->m_pSteamNetworking = v19;
  if ( v19 == nullptr )
    return false;
  v20 = _SteamClient();
  v21 = (ISteamRemoteStorage *)(*(int (__thiscall **)(int, int, int, const char *))(*(_DWORD *)v20 + 72))(
                                 a1: v20,
                                 a2: hSteamUser,
                                 a3: HSteamPipe,
                                 a4: "STEAMREMOTESTORAGE_INTERFACE_VERSION004");
  this->m_pSteamRemoteStorage = v21;
  return v21 != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100057D0
// Name: void SteamApiContext_Init(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SteamApiContext_Init()
{
  int *v0; // edi
  int v1; // esi
  int HSteamPipe; // eax
  int HSteamUser; // eax
  ISteamGameCoordinator *v4; // eax

  if ( (unsigned __int8)_SteamAPI_InitSafe() != 0
    && CSteamAPIContext::Init(this: steamapicontext)
    && _SteamClient() != 0 )
  {
    v0 = (int *)_SteamClient();
    v1 = *v0;
    HSteamPipe = _SteamAPI_GetHSteamPipe(a1: "SteamGameCoordinator001");
    HSteamUser = _SteamAPI_GetHSteamUser(a1: HSteamPipe);
    v4 = (ISteamGameCoordinator *)(*(int (__thiscall **)(int *, int))(v1 + 52))(a1: v0, a2: HSteamUser);
    GCSDK::CGCClient::BInit(this: &g_GCClient, pSteamGameCoordinator: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005830
// Name: void SteamApiContext_Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SteamApiContext_Shutdown(GCSDK *a1)
{
  CSteamAPIContext *v1; // eax

  v1 = steamapicontext;
  steamapicontext->m_pSteamUser = nullptr;
  v1->m_pSteamFriends = nullptr;
  v1->m_pSteamUtils = nullptr;
  v1->m_pSteamMatchmaking = nullptr;
  v1->m_pSteamUserStats = nullptr;
  v1->m_pSteamApps = nullptr;
  v1->m_pSteamMatchmakingServers = nullptr;
  v1->m_pSteamNetworking = nullptr;
  v1->m_pSteamRemoteStorage = nullptr;
  GCSDK::CGCClient::Uninit(this: &g_GCClient);
  GCSDK::UninitTempTextBuffers(this: a1);
}

} // namespace matchmaking

// ============================================================
// Overlay from matchmaking_ds (Missing functions)
// ============================================================
namespace matchmaking_ds {

//------------------------------------------------------------------------------
// Address: 0x10007D20
// Name: void SteamApiContext_Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SteamApiContext_Shutdown(CServerManager *this)
{
  ;
}

} // namespace matchmaking_ds
