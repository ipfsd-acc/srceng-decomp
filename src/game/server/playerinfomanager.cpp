// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/playerinfomanager.cpp
// Functions: 6
// ============================================================

#include "game\server\playerinfomanager.h"

//------------------------------------------------------------------------------
// Address: 0x101CFE80
// Name: _anonymous_namespace_::__CreateCPlayerInfoManager_V1IPlayerInfoManager_V1_interface
// Source: json
//------------------------------------------------------------------------------
CPlayerInfoManager_V1 *__cdecl anonymous_namespace_::__CreateCPlayerInfoManager_V1IPlayerInfoManager_V1_interface()
{
  return &s_PlayerInfoManager_V1;
}

//------------------------------------------------------------------------------
// Address: 0x101CFE90
// Name: public: virtual class CGlobalVars __near * CPlayerInfoManager::GetGlobalVars(void)
// Source: json
//------------------------------------------------------------------------------
CGlobalVars *__thiscall CPlayerInfoManager::GetGlobalVars(CPlayerInfoManager *this)
{
  return gpGlobals;
}

//------------------------------------------------------------------------------
// Address: 0x101CFF10
// Name: public: virtual class IBotController __near * CPluginBotManager::GetBotController(struct edict_t __near *)
// Source: json
//------------------------------------------------------------------------------
IBotController *__thiscall CPluginBotManager::GetBotController(CPluginBotManager *this, edict_t *pEdict)
{
  edict_t *pEdicts; // eax
  IServerUnknown *m_pUnk; // ecx
  int v4; // eax
  int v5; // esi

  pEdicts = pEdict;
  if ( (pEdict != nullptr || gpGlobals->pEdicts != nullptr && ((pEdicts = gpGlobals->pEdicts)->m_fStateFlags & 2) == 0)
    && (m_pUnk = pEdicts->m_pUnk) != nullptr
    && (v4 = (int)m_pUnk->GetBaseEntity(this: m_pUnk), v5 = v4, v4 != 0)
    && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v4 + 1912))(a1: v4) != 0 )
  {
    return (IBotController *)(v5 + 4164);
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CFF70
// Name: public: virtual struct edict_t __near * CPluginBotManager::CreateBot(char const __near *)
// Source: json
//------------------------------------------------------------------------------
edict_t *__thiscall CPluginBotManager::CreateBot(CPluginBotManager *this, const char *botname)
{
  edict_t *v2; // eax
  edict_t *v3; // edi
  IServerUnknown *m_pUnk; // ecx
  CBaseEntity *v6; // esi

  v2 = engine->CreateFakeClient(this: engine, a2: botname);
  v3 = v2;
  if ( v2 != nullptr )
  {
    m_pUnk = v2->m_pUnk;
    if ( m_pUnk != nullptr )
      v6 = m_pUnk->GetBaseEntity(this: m_pUnk);
    else
      v6 = nullptr;
    CBaseEntity::ClearFlags(this: v6);
    CBaseEntity::AddFlag(this: v6, flags: 768);
    v6->ChangeTeam(this: v6, a2: 0);
    v6->__vftable[1].NetworkStateChanged_m_hGroundEntity(this: v6, a2: (void *)1);
    v6->Spawn(this: v6);
    return v3;
  }
  else
  {
    _Msg(a1: "Failed to create Bot.\n");
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CFEA0
// Name: __CreateCPlayerInfoManagerIPlayerInfoManager_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CPlayerInfoManager *__cdecl _CreateCPlayerInfoManagerIPlayerInfoManager_interface()
{
  return &s_PlayerInfoManager;
}

//------------------------------------------------------------------------------
// Address: 0x101CFEB0
// Name: __CreateCPluginBotManagerIBotManager_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CPluginBotManager *__cdecl _CreateCPluginBotManagerIBotManager_interface()
{
  return &s_BotManager;
}
