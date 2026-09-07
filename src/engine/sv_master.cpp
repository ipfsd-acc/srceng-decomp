// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/sv_master.cpp
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x101282B0
// Name: void Heartbeat_f(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Heartbeat_f()
{
  CSteam3Server *v0; // eax

  if ( g_nForkID != -1 )
  {
    if ( IsUsingMasterLegacyMode() )
    {
      g_pMaster->Heartbeat_Legacy_f(this: g_pMaster);
    }
    else if ( Steam3Server()->m_pSteamMasterServerUpdater != nullptr )
    {
      v0 = Steam3Server();
      v0->m_pSteamMasterServerUpdater->ForceHeartbeat(this: v0->m_pSteamMasterServerUpdater);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101282F0
// Name: void SetMaster_f(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetMaster_f(const CCommand *args)
{
  ISteamMasterServerUpdater *m_pSteamMasterServerUpdater; // edi
  int m_nArgc; // ebx
  int i; // esi
  char *v4; // esi
  int v5; // esi
  const char *v6; // eax
  char szAdr[512]; // [esp+0h] [ebp-284h] BYREF
  char szMasterAddress[128]; // [esp+200h] [ebp-84h] BYREF
  char *s1; // [esp+280h] [ebp-4h]

  if ( IsUsingMasterLegacyMode() )
  {
    g_pMaster->SetMaster_Legacy_f(this: g_pMaster, a2: args);
  }
  else
  {
    m_pSteamMasterServerUpdater = Steam3Server()->m_pSteamMasterServerUpdater;
    if ( m_pSteamMasterServerUpdater != nullptr )
    {
      m_nArgc = args->m_nArgc;
      if ( args->m_nArgc >= 2 )
      {
        if ( m_nArgc > 1 )
        {
          v4 = (char *)args->m_ppArgv[1];
          s1 = v4;
          if ( v4 != nullptr && *v4 != 0 )
          {
            if ( _V_stricmp(s1: v4, s2: "disable") != 0 )
            {
              if ( _V_stricmp(s1: v4, s2: "enable") != 0 )
              {
                if ( _V_stricmp(s1: v4, s2: "add") != 0 && _V_stricmp(s1: v4, s2: "remove") != 0 )
                {
                  ConMsg(a1: "Invalid setmaster command\n");
                  CBaseServer::SetMasterServerRulesDirty(this: &sv);
                }
                else
                {
                  v5 = 2;
                  for ( szMasterAddress[0] = 0; v5 < m_nArgc; ++v5 )
                  {
                    v6 = CCommand::operator[](this: args, nIndex: v5);
                    V_strncat(pDest: szMasterAddress, pSrc: v6, destBufferSize: 0x80u, max_chars_to_copy: -1);
                  }
                  if ( _V_stricmp(s1, s2: "add") != 0 )
                  {
                    if ( !m_pSteamMasterServerUpdater->RemoveMasterServer(
                            this: m_pSteamMasterServerUpdater,
                            a2: szMasterAddress) )
                      ConMsg(a1: "Can't remove master %s, not in list\n", szMasterAddress);
                    CBaseServer::SetMasterServerRulesDirty(this: &sv);
                  }
                  else
                  {
                    if ( m_pSteamMasterServerUpdater->AddMasterServer(
                           this: m_pSteamMasterServerUpdater,
                           a2: szMasterAddress) )
                    {
                      ConMsg(a1: "Adding master at %s\n", szMasterAddress);
                    }
                    else
                    {
                      ConMsg(a1: "Master at %s already in list\n", szMasterAddress);
                    }
                    g_bEnableMasterServerUpdater = true;
                    CBaseServer::SetMasterServerRulesDirty(this: &sv);
                  }
                }
              }
              else
              {
                g_bEnableMasterServerUpdater = true;
                CBaseServer::SetMasterServerRulesDirty(this: &sv);
              }
            }
            else
            {
              g_bEnableMasterServerUpdater = false;
              CBaseServer::SetMasterServerRulesDirty(this: &sv);
            }
          }
        }
      }
      else
      {
        ConMsg(a1: "Usage:\nsetmaster <add | remove | enable | disable> <IP:port>\n");
        if ( m_pSteamMasterServerUpdater->GetNumMasterServers(this: m_pSteamMasterServerUpdater) != 0 )
        {
          ConMsg(a1: "Current:\n");
          for ( i = 0; i < m_pSteamMasterServerUpdater->GetNumMasterServers(this: m_pSteamMasterServerUpdater); ++i )
          {
            if ( m_pSteamMasterServerUpdater->GetMasterServerAddress(
                   this: m_pSteamMasterServerUpdater,
                   a2: i,
                   a3: szAdr,
                   a4: 512) != 0 )
              ConMsg(a1: "  %i:  %s\n", i + 1, szAdr);
          }
        }
        else
        {
          ConMsg(a1: "Current:  None\n");
        }
      }
    }
  }
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10128410
// Name: void Heartbeat_f(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Heartbeat_f()
{
  CSteam3Server *v0; // eax

  if ( g_nForkID != -1 )
  {
    if ( IsUsingMasterLegacyMode() )
    {
      g_pMaster->Heartbeat_Legacy_f(this: g_pMaster);
    }
    else if ( Steam3Server()->m_pSteamMasterServerUpdater != nullptr )
    {
      v0 = Steam3Server();
      v0->m_pSteamMasterServerUpdater->ForceHeartbeat(this: v0->m_pSteamMasterServerUpdater);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10128450
// Name: void SetMaster_f(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetMaster_f(const CCommand *args)
{
  ISteamMasterServerUpdater *m_pSteamMasterServerUpdater; // edi
  int m_nArgc; // ebx
  int i; // esi
  char *v4; // esi
  int v5; // esi
  const char *v6; // eax
  char szAdr[512]; // [esp+0h] [ebp-284h] BYREF
  char szMasterAddress[128]; // [esp+200h] [ebp-84h] BYREF
  char *s1; // [esp+280h] [ebp-4h]

  if ( IsUsingMasterLegacyMode() )
  {
    g_pMaster->SetMaster_Legacy_f(this: g_pMaster, a2: args);
  }
  else
  {
    m_pSteamMasterServerUpdater = Steam3Server()->m_pSteamMasterServerUpdater;
    if ( m_pSteamMasterServerUpdater != nullptr )
    {
      m_nArgc = args->m_nArgc;
      if ( args->m_nArgc >= 2 )
      {
        if ( m_nArgc > 1 )
        {
          v4 = (char *)args->m_ppArgv[1];
          s1 = v4;
          if ( v4 != nullptr && *v4 != 0 )
          {
            if ( _V_stricmp(s1: v4, s2: "disable") != 0 )
            {
              if ( _V_stricmp(s1: v4, s2: "enable") != 0 )
              {
                if ( _V_stricmp(s1: v4, s2: "add") != 0 && _V_stricmp(s1: v4, s2: "remove") != 0 )
                {
                  ConMsg(a1: "Invalid setmaster command\n");
                  CBaseServer::SetMasterServerRulesDirty(this: &sv);
                }
                else
                {
                  v5 = 2;
                  for ( szMasterAddress[0] = 0; v5 < m_nArgc; ++v5 )
                  {
                    v6 = CCommand::operator[](this: args, nIndex: v5);
                    V_strncat(pDest: szMasterAddress, pSrc: v6, destBufferSize: 0x80u, max_chars_to_copy: -1);
                  }
                  if ( _V_stricmp(s1, s2: "add") != 0 )
                  {
                    if ( !m_pSteamMasterServerUpdater->RemoveMasterServer(
                            this: m_pSteamMasterServerUpdater,
                            a2: szMasterAddress) )
                      ConMsg(a1: "Can't remove master %s, not in list\n", szMasterAddress);
                    CBaseServer::SetMasterServerRulesDirty(this: &sv);
                  }
                  else
                  {
                    if ( m_pSteamMasterServerUpdater->AddMasterServer(
                           this: m_pSteamMasterServerUpdater,
                           a2: szMasterAddress) )
                    {
                      ConMsg(a1: "Adding master at %s\n", szMasterAddress);
                    }
                    else
                    {
                      ConMsg(a1: "Master at %s already in list\n", szMasterAddress);
                    }
                    g_bEnableMasterServerUpdater = true;
                    CBaseServer::SetMasterServerRulesDirty(this: &sv);
                  }
                }
              }
              else
              {
                g_bEnableMasterServerUpdater = true;
                CBaseServer::SetMasterServerRulesDirty(this: &sv);
              }
            }
            else
            {
              g_bEnableMasterServerUpdater = false;
              CBaseServer::SetMasterServerRulesDirty(this: &sv);
            }
          }
        }
      }
      else
      {
        ConMsg(a1: "Usage:\nsetmaster <add | remove | enable | disable> <IP:port>\n");
        if ( m_pSteamMasterServerUpdater->GetNumMasterServers(this: m_pSteamMasterServerUpdater) != 0 )
        {
          ConMsg(a1: "Current:\n");
          for ( i = 0; i < m_pSteamMasterServerUpdater->GetNumMasterServers(this: m_pSteamMasterServerUpdater); ++i )
          {
            if ( m_pSteamMasterServerUpdater->GetMasterServerAddress(
                   this: m_pSteamMasterServerUpdater,
                   a2: i,
                   a3: szAdr,
                   a4: 512) != 0 )
              ConMsg(a1: "  %i:  %s\n", i + 1, szAdr);
          }
        }
        else
        {
          ConMsg(a1: "Current:  None\n");
        }
      }
    }
  }
}

} // namespace engine_xlsp
