// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/sv_plugin.cpp
// Functions: 48
// ============================================================

#include "engine\sv_plugin.h"

//------------------------------------------------------------------------------
// Address: 0x10129820
// Name: public: CPlugin::~CPlugin(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlugin::~CPlugin(CPlugin *this)
{
  IServerPluginCallbacks *m_pPlugin; // ecx
  struct CSysModule *m_pPluginModule; // edx
  struct CSysModule *v4; // eax

  m_pPlugin = this->m_pPlugin;
  if ( m_pPlugin != nullptr )
  {
    m_pPlugin->Unload(this: m_pPlugin);
    m_pPluginModule = this->m_pPluginModule;
    this->m_pPlugin = nullptr;
    g_pFileSystem->UnloadModule(this: g_pFileSystem, a2: m_pPluginModule);
    this->m_pPluginModule = nullptr;
  }
  v4 = this->m_pPluginModule;
  this->m_pPlugin = nullptr;
  if ( v4 != nullptr )
    g_pFileSystem->UnloadModule(this: g_pFileSystem, a2: v4);
  this->m_pPluginModule = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10129880
// Name: public: bool CPlugin::Load(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CPlugin::Load(CPlugin *this, const char *fileName)
{
  struct CSysModule *v3; // eax
  void *(__cdecl *Factory)(const char *, int *); // eax
  void *(__cdecl *v5)(const char *, int *); // edi
  IServerPluginCallbacks *v6; // eax
  IServerPluginCallbacks *v7; // eax
  IServerPluginCallbacks *v8; // eax
  void *(__cdecl *v10)(const char *, int *); // eax
  const char *v11; // eax
  char fixedFileName[260]; // [esp+8h] [ebp-104h] BYREF

  V_strncpy(pDest: fixedFileName, pSrc: fileName, maxLen: 260);
  V_FixSlashes(pname: fixedFileName, separator: 92);
  v3 = g_pFileSystem->LoadModule(this: g_pFileSystem, a2: fixedFileName, a3: "GAME", a4: 0);
  this->m_pPluginModule = v3;
  if ( v3 != nullptr )
  {
    Factory = Sys_GetFactory(pModule: v3);
    v5 = Factory;
    if ( Factory != nullptr )
    {
      this->m_iPluginInterfaceVersion = 3;
      v6 = (IServerPluginCallbacks *)Factory(a1: "ISERVERPLUGINCALLBACKS003", a2: nullptr);
      this->m_pPlugin = v6;
      if ( v6 == nullptr )
      {
        this->m_iPluginInterfaceVersion = 2;
        v7 = (IServerPluginCallbacks *)v5(a1: "ISERVERPLUGINCALLBACKS002", a2: nullptr);
        this->m_pPlugin = v7;
        if ( v7 == nullptr )
        {
          this->m_iPluginInterfaceVersion = 1;
          v8 = (IServerPluginCallbacks *)v5(a1: "ISERVERPLUGINCALLBACKS001", a2: nullptr);
          this->m_pPlugin = v8;
          if ( v8 == nullptr )
          {
            _Warning(a1: "Could not get IServerPluginCallbacks interface from plugin \"%s\"", fileName);
            return 0;
          }
        }
      }
      v10 = Sys_GetFactory(pModule: g_GameDLL);
      if ( ((int (__thiscall *)(IServerPluginCallbacks *, void *(__cdecl *)(const char *, int *), void *(__cdecl *)(const char *, int *)))this->m_pPlugin->Load)(
             a1: this->m_pPlugin,
             a2: g_AppSystemFactory,
             a3: v10) == 0 )
      {
        _Warning(a1: "Failed to load plugin \"%s\"\n", fileName);
        return 0;
      }
      v11 = this->m_pPlugin->GetPluginDescription(this: this->m_pPlugin);
      V_strncpy(pDest: this->m_szName, pSrc: v11, maxLen: 128);
    }
    return 1;
  }
  else
  {
    _Warning(a1: "Unable to load plugin \"%s\"\n", fileName);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101299F0
// Name: public: void CServerPlugin::PrintDetails(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerPlugin::PrintDetails(CServerPlugin *this)
{
  int i; // esi
  CPlugin *v3; // eax
  const char *v4; // ecx

  ConMsg(a1: "Loaded plugins:\n");
  ConMsg(a1: "---------------------\n");
  for ( i = 0; i < this->m_Plugins.m_Size; ++i )
  {
    v3 = this->m_Plugins.m_Memory.m_pMemory[i];
    v4 = " (disabled)";
    if ( !v3->m_bDisable )
      v4 = defaultValue;
    ConMsg(a1: "%i:\t\"%s\"%s\n", i, v3->m_szName, v4);
  }
  ConMsg(a1: "---------------------\n");
}

//------------------------------------------------------------------------------
// Address: 0x10129A50
// Name: public: virtual void CServerPlugin::LevelInit(char const __near *,char const __near *,char const __near *,char const __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerPlugin::LevelInit(
        CServerPlugin *this,
        const char *pMapName,
        const char *pMapEntities,
        const char *pOldLevel,
        const char *pLandmarkName,
        BOOL loadGame,
        BOOL background)
{
  IMDLCache *v7; // ebx
  int i; // esi
  CPlugin *v10; // eax
  IServerPluginCallbacks *m_pPlugin; // ecx
  BOOL bPrevState; // [esp+Ch] [ebp-4h]

  v7 = g_pMDLCache;
  g_pMDLCache->BeginCoarseLock(this: g_pMDLCache);
  for ( i = 0; i < this->m_Plugins.m_Size; ++i )
  {
    v10 = this->m_Plugins.m_Memory.m_pMemory[i];
    if ( !v10->m_bDisable )
    {
      m_pPlugin = v10->m_pPlugin;
      if ( m_pPlugin == nullptr )
      {
        _Warning(a1: "Unable to get callback interface for \"%s\"\n", this->m_Plugins.m_Memory.m_pMemory[i]->m_szName);
        m_pPlugin = nullptr;
      }
      m_pPlugin->LevelInit(this: m_pPlugin, a2: pMapName);
    }
  }
  LOBYTE(bPrevState) = CNetworkStringTableContainer::Lock(this: networkStringTableContainerServer, bLock: false);
  serverGameDLL->LevelInit(
    this: serverGameDLL,
    a2: pMapName,
    a3: pMapEntities,
    a4: pOldLevel,
    a5: pLandmarkName,
    a6: loadGame,
    a7: background);
  CNetworkStringTableContainer::Lock(this: networkStringTableContainerServer, bLock: bPrevState);
  v7->EndCoarseLock(this: v7);
}

//------------------------------------------------------------------------------
// Address: 0x10129B10
// Name: public: virtual void CServerPlugin::ServerActivate(struct edict_t __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerPlugin::ServerActivate(CServerPlugin *this, edict_t *pEdictList, int edictCount, int clientMax)
{
  IMDLCache *v4; // ebx
  int i; // edi
  CPlugin *v7; // eax
  IServerPluginCallbacks *m_pPlugin; // ecx

  v4 = g_pMDLCache;
  g_pMDLCache->BeginCoarseLock(this: g_pMDLCache);
  for ( i = 0; i < this->m_Plugins.m_Size; ++i )
  {
    v7 = this->m_Plugins.m_Memory.m_pMemory[i];
    if ( !v7->m_bDisable )
    {
      m_pPlugin = v7->m_pPlugin;
      if ( m_pPlugin == nullptr )
      {
        _Warning(a1: "Unable to get callback interface for \"%s\"\n", this->m_Plugins.m_Memory.m_pMemory[i]->m_szName);
        m_pPlugin = nullptr;
      }
      m_pPlugin->ServerActivate(this: m_pPlugin, a2: pEdictList, a3: edictCount, a4: clientMax);
    }
  }
  serverGameDLL->ServerActivate(this: serverGameDLL, a2: pEdictList, a3: edictCount, a4: clientMax);
  v4->EndCoarseLock(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10129BA0
// Name: public: virtual void CServerPlugin::GameFrame(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerPlugin::GameFrame(CServerPlugin *this, BOOL simulating)
{
  int i; // esi
  CPlugin *v4; // eax
  IServerPluginCallbacks *m_pPlugin; // ecx

  for ( i = 0; i < this->m_Plugins.m_Size; ++i )
  {
    v4 = this->m_Plugins.m_Memory.m_pMemory[i];
    if ( !v4->m_bDisable )
    {
      m_pPlugin = v4->m_pPlugin;
      if ( m_pPlugin == nullptr )
      {
        _Warning(a1: "Unable to get callback interface for \"%s\"\n", this->m_Plugins.m_Memory.m_pMemory[i]->m_szName);
        m_pPlugin = nullptr;
      }
      m_pPlugin->GameFrame(this: m_pPlugin, a2: simulating);
    }
  }
  serverGameDLL->GameFrame(this: serverGameDLL, a2: simulating);
}

//------------------------------------------------------------------------------
// Address: 0x10129C10
// Name: public: virtual void CServerPlugin::LevelShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerPlugin::LevelShutdown(CServerPlugin *this)
{
  IMDLCache *v1; // ebx
  int v3; // esi
  CPlugin *v4; // eax
  IServerPluginCallbacks *m_pPlugin; // ecx
  IMDLCache *cacheCoarseCriticalSection; // [esp+Ch] [ebp-4h]

  v1 = g_pMDLCache;
  cacheCoarseCriticalSection = g_pMDLCache;
  g_pMDLCache->BeginCoarseLock(this: g_pMDLCache);
  v3 = 0;
  if ( this->m_Plugins.m_Size > 0 )
  {
    do
    {
      v4 = this->m_Plugins.m_Memory.m_pMemory[v3];
      if ( !v4->m_bDisable )
      {
        m_pPlugin = v4->m_pPlugin;
        if ( m_pPlugin == nullptr )
        {
          _Warning(
            a1: "Unable to get callback interface for \"%s\"\n",
            this->m_Plugins.m_Memory.m_pMemory[v3]->m_szName);
          m_pPlugin = nullptr;
        }
        m_pPlugin->LevelShutdown(this: m_pPlugin);
      }
      ++v3;
    }
    while ( v3 < this->m_Plugins.m_Size );
    v1 = cacheCoarseCriticalSection;
  }
  serverGameDLL->LevelShutdown(this: serverGameDLL);
  v1->EndCoarseLock(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x10129CA0
// Name: public: virtual void CServerPlugin::ClientActive(struct edict_t __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerPlugin::ClientActive(CServerPlugin *this, edict_t *pEntity, BOOL bLoadGame)
{
  int i; // esi
  CPlugin *v5; // eax
  IServerPluginCallbacks *m_pPlugin; // ecx

  for ( i = 0; i < this->m_Plugins.m_Size; ++i )
  {
    v5 = this->m_Plugins.m_Memory.m_pMemory[i];
    if ( !v5->m_bDisable )
    {
      m_pPlugin = v5->m_pPlugin;
      if ( m_pPlugin == nullptr )
      {
        _Warning(a1: "Unable to get callback interface for \"%s\"\n", this->m_Plugins.m_Memory.m_pMemory[i]->m_szName);
        m_pPlugin = nullptr;
      }
      m_pPlugin->ClientActive(this: m_pPlugin, a2: pEntity);
    }
  }
  serverGameClients->ClientActive(this: serverGameClients, a2: pEntity, a3: bLoadGame);
}

//------------------------------------------------------------------------------
// Address: 0x10129D10
// Name: public: virtual void CServerPlugin::ClientFullyConnect(struct edict_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerPlugin::ClientFullyConnect(CServerPlugin *this, edict_t *pEntity)
{
  int i; // esi
  CPlugin *v4; // eax
  IServerPluginCallbacks *m_pPlugin; // ecx

  for ( i = 0; i < this->m_Plugins.m_Size; ++i )
  {
    v4 = this->m_Plugins.m_Memory.m_pMemory[i];
    if ( !v4->m_bDisable )
    {
      m_pPlugin = v4->m_pPlugin;
      if ( m_pPlugin == nullptr )
      {
        _Warning(a1: "Unable to get callback interface for \"%s\"\n", this->m_Plugins.m_Memory.m_pMemory[i]->m_szName);
        m_pPlugin = nullptr;
      }
      m_pPlugin->ClientFullyConnect(this: m_pPlugin, a2: pEntity);
    }
  }
  serverGameClients->ClientFullyConnect(this: serverGameClients, a2: pEntity);
}

//------------------------------------------------------------------------------
// Address: 0x10129D80
// Name: public: virtual void CServerPlugin::ClientDisconnect(struct edict_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerPlugin::ClientDisconnect(CServerPlugin *this, edict_t *pEntity)
{
  int i; // esi
  CPlugin *v4; // eax
  IServerPluginCallbacks *m_pPlugin; // ecx

  for ( i = 0; i < this->m_Plugins.m_Size; ++i )
  {
    v4 = this->m_Plugins.m_Memory.m_pMemory[i];
    if ( !v4->m_bDisable )
    {
      m_pPlugin = v4->m_pPlugin;
      if ( m_pPlugin == nullptr )
      {
        _Warning(a1: "Unable to get callback interface for \"%s\"\n", this->m_Plugins.m_Memory.m_pMemory[i]->m_szName);
        m_pPlugin = nullptr;
      }
      m_pPlugin->ClientDisconnect(this: m_pPlugin, a2: pEntity);
    }
  }
  serverGameClients->ClientDisconnect(this: serverGameClients, a2: pEntity);
}

//------------------------------------------------------------------------------
// Address: 0x10129DF0
// Name: public: virtual void CServerPlugin::ClientPutInServer(struct edict_t __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerPlugin::ClientPutInServer(CServerPlugin *this, edict_t *pEntity, const char *playername)
{
  int i; // esi
  CPlugin *v5; // eax
  IServerPluginCallbacks *m_pPlugin; // ecx

  for ( i = 0; i < this->m_Plugins.m_Size; ++i )
  {
    v5 = this->m_Plugins.m_Memory.m_pMemory[i];
    if ( !v5->m_bDisable )
    {
      m_pPlugin = v5->m_pPlugin;
      if ( m_pPlugin == nullptr )
      {
        _Warning(a1: "Unable to get callback interface for \"%s\"\n", this->m_Plugins.m_Memory.m_pMemory[i]->m_szName);
        m_pPlugin = nullptr;
      }
      m_pPlugin->ClientPutInServer(this: m_pPlugin, a2: pEntity, a3: playername);
    }
  }
  serverGameClients->ClientPutInServer(this: serverGameClients, a2: pEntity, a3: playername);
}

//------------------------------------------------------------------------------
// Address: 0x10129E60
// Name: public: virtual void CServerPlugin::SetCommandClient(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerPlugin::SetCommandClient(CServerPlugin *this, int index)
{
  int i; // esi
  CPlugin *v4; // eax
  IServerPluginCallbacks *m_pPlugin; // ecx

  for ( i = 0; i < this->m_Plugins.m_Size; ++i )
  {
    v4 = this->m_Plugins.m_Memory.m_pMemory[i];
    if ( !v4->m_bDisable )
    {
      m_pPlugin = v4->m_pPlugin;
      if ( m_pPlugin == nullptr )
      {
        _Warning(a1: "Unable to get callback interface for \"%s\"\n", this->m_Plugins.m_Memory.m_pMemory[i]->m_szName);
        m_pPlugin = nullptr;
      }
      m_pPlugin->SetCommandClient(this: m_pPlugin, a2: index);
    }
  }
  serverGameClients->SetCommandClient(this: serverGameClients, a2: index);
}

//------------------------------------------------------------------------------
// Address: 0x10129ED0
// Name: public: virtual void CServerPlugin::ClientSettingsChanged(struct edict_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerPlugin::ClientSettingsChanged(CServerPlugin *this, edict_t *pEdict)
{
  int i; // esi
  CPlugin *v4; // eax
  IServerPluginCallbacks *m_pPlugin; // ecx

  for ( i = 0; i < this->m_Plugins.m_Size; ++i )
  {
    v4 = this->m_Plugins.m_Memory.m_pMemory[i];
    if ( !v4->m_bDisable )
    {
      m_pPlugin = v4->m_pPlugin;
      if ( m_pPlugin == nullptr )
      {
        _Warning(a1: "Unable to get callback interface for \"%s\"\n", this->m_Plugins.m_Memory.m_pMemory[i]->m_szName);
        m_pPlugin = nullptr;
      }
      m_pPlugin->ClientSettingsChanged(this: m_pPlugin, a2: pEdict);
    }
  }
  serverGameClients->ClientSettingsChanged(this: serverGameClients, a2: pEdict);
}

//------------------------------------------------------------------------------
// Address: 0x10129F40
// Name: public: virtual bool CServerPlugin::ClientConnect(struct edict_t __near *,char const __near *,char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CServerPlugin::ClientConnect(
        CServerPlugin *this,
        edict_t *pEntity,
        const char *pszName,
        const char *pszAddress,
        char *reject,
        int maxrejectlen)
{
  int v7; // edi
  char v8; // bl
  CPlugin *v9; // eax
  IServerPluginCallbacks *m_pPlugin; // ecx
  int v11; // eax
  bool result; // al
  bool bSavedRetVal; // [esp+Eh] [ebp-2h]
  bool bAllowConnect; // [esp+Fh] [ebp-1h] BYREF

  v7 = 0;
  v8 = 0;
  bAllowConnect = true;
  for ( bSavedRetVal = true; v7 < this->m_Plugins.m_Size; ++v7 )
  {
    v9 = this->m_Plugins.m_Memory.m_pMemory[v7];
    if ( !v9->m_bDisable )
    {
      m_pPlugin = v9->m_pPlugin;
      if ( m_pPlugin == nullptr )
      {
        _Warning(a1: "Unable to get callback interface for \"%s\"\n", this->m_Plugins.m_Memory.m_pMemory[v7]->m_szName);
        m_pPlugin = nullptr;
      }
      v11 = m_pPlugin->ClientConnect(
              this: m_pPlugin,
              a2: &bAllowConnect,
              a3: pEntity,
              a4: pszName,
              a5: pszAddress,
              a6: reject,
              a7: maxrejectlen);
      if ( v11 == 2 )
        return bAllowConnect;
      if ( v11 == 1 && v8 == 0 )
      {
        bSavedRetVal = bAllowConnect;
        v8 = 1;
      }
    }
  }
  result = serverGameClients->ClientConnect(
             this: serverGameClients,
             a2: pEntity,
             a3: pszName,
             a4: pszAddress,
             a5: reject,
             a6: maxrejectlen);
  if ( v8 != 0 )
    return bSavedRetVal;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1012A010
// Name: public: virtual void CServerPlugin::ClientCommand(struct edict_t __near *,class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerPlugin::ClientCommand(CServerPlugin *this, edict_t *pEntity, const CCommand *args)
{
  int v4; // esi
  CPlugin *v5; // eax
  IServerPluginCallbacks *m_pPlugin; // ecx

  v4 = 0;
  if ( this->m_Plugins.m_Size <= 0 )
  {
LABEL_7:
    serverGameClients->ClientCommand(this: serverGameClients, a2: pEntity, a3: args);
  }
  else
  {
    while ( 1 )
    {
      v5 = this->m_Plugins.m_Memory.m_pMemory[v4];
      if ( !v5->m_bDisable )
      {
        m_pPlugin = v5->m_pPlugin;
        if ( m_pPlugin == nullptr )
        {
          _Warning(
            a1: "Unable to get callback interface for \"%s\"\n",
            this->m_Plugins.m_Memory.m_pMemory[v4]->m_szName);
          m_pPlugin = nullptr;
        }
        if ( m_pPlugin->ClientCommand(this: m_pPlugin, a2: pEntity, a3: args) == PLUGIN_STOP )
          break;
      }
      if ( ++v4 >= this->m_Plugins.m_Size )
        goto LABEL_7;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012A090
// Name: public: virtual void CServerPlugin::NetworkIDValidated(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerPlugin::NetworkIDValidated(
        CServerPlugin *this,
        const char *pszUserName,
        const char *pszNetworkID)
{
  int i; // esi
  CPlugin *v5; // eax
  IServerPluginCallbacks *m_pPlugin; // ecx

  for ( i = 0; i < this->m_Plugins.m_Size; ++i )
  {
    v5 = this->m_Plugins.m_Memory.m_pMemory[i];
    if ( !v5->m_bDisable )
    {
      m_pPlugin = v5->m_pPlugin;
      if ( m_pPlugin == nullptr )
      {
        _Warning(a1: "Unable to get callback interface for \"%s\"\n", this->m_Plugins.m_Memory.m_pMemory[i]->m_szName);
        m_pPlugin = nullptr;
      }
      if ( m_pPlugin->NetworkIDValidated(this: m_pPlugin, a2: pszUserName, a3: pszNetworkID) == PLUGIN_STOP )
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012A100
// Name: public: virtual void CServerPlugin::OnQueryCvarValueFinished(int,struct edict_t __near *,enum EQueryCvarValueStatus,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerPlugin::OnQueryCvarValueFinished(
        CServerPlugin *this,
        int iCookie,
        edict_t *pPlayerEntity,
        EQueryCvarValueStatus eStatus,
        const char *pCvarName,
        const char *pCvarValue)
{
  int i; // esi
  CPlugin *v8; // eax
  IServerPluginCallbacks *m_pPlugin; // ecx

  for ( i = 0; i < this->m_Plugins.m_Size; ++i )
  {
    v8 = this->m_Plugins.m_Memory.m_pMemory[i];
    if ( !v8->m_bDisable && v8->m_iPluginInterfaceVersion >= 2 )
    {
      m_pPlugin = v8->m_pPlugin;
      if ( m_pPlugin == nullptr )
      {
        _Warning(a1: "Unable to get callback interface for \"%s\"\n", this->m_Plugins.m_Memory.m_pMemory[i]->m_szName);
        m_pPlugin = nullptr;
      }
      m_pPlugin->OnQueryCvarValueFinished(
        this: m_pPlugin,
        a2: iCookie,
        a3: pPlayerEntity,
        a4: eStatus,
        a5: pCvarName,
        a6: pCvarValue);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012A170
// Name: public: virtual void CServerPlugin::OnEdictAllocated(struct edict_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerPlugin::OnEdictAllocated(CServerPlugin *this, edict_t *edict)
{
  int i; // esi
  CPlugin *v4; // eax
  IServerPluginCallbacks *m_pPlugin; // ecx

  for ( i = 0; i < this->m_Plugins.m_Size; ++i )
  {
    v4 = this->m_Plugins.m_Memory.m_pMemory[i];
    if ( !v4->m_bDisable && v4->m_iPluginInterfaceVersion >= 3 )
    {
      m_pPlugin = v4->m_pPlugin;
      if ( m_pPlugin == nullptr )
      {
        _Warning(a1: "Unable to get callback interface for \"%s\"\n", this->m_Plugins.m_Memory.m_pMemory[i]->m_szName);
        m_pPlugin = nullptr;
      }
      m_pPlugin->OnEdictAllocated(this: m_pPlugin, a2: edict);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012A1E0
// Name: public: virtual void CServerPlugin::OnEdictFreed(struct edict_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerPlugin::OnEdictFreed(CServerPlugin *this, const edict_t *edict)
{
  int i; // esi
  CPlugin *v4; // eax
  IServerPluginCallbacks *m_pPlugin; // ecx

  for ( i = 0; i < this->m_Plugins.m_Size; ++i )
  {
    v4 = this->m_Plugins.m_Memory.m_pMemory[i];
    if ( !v4->m_bDisable && v4->m_iPluginInterfaceVersion >= 3 )
    {
      m_pPlugin = v4->m_pPlugin;
      if ( m_pPlugin == nullptr )
      {
        _Warning(a1: "Unable to get callback interface for \"%s\"\n", this->m_Plugins.m_Memory.m_pMemory[i]->m_szName);
        m_pPlugin = nullptr;
      }
      m_pPlugin->OnEdictFreed(this: m_pPlugin, a2: edict);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012A250
// Name: plugin_print
// Source: json
//------------------------------------------------------------------------------
void __cdecl plugin_print()
{
  CServerPlugin::PrintDetails(this: g_pServerPluginHandler);
}

//------------------------------------------------------------------------------
// Address: 0x1012A260
// Name: plugin_pause
// Source: json
//------------------------------------------------------------------------------
void __cdecl plugin_pause(const CCommand *args)
{
  const char *v1; // eax
  int v2; // eax
  CPlugin *v3; // esi

  if ( args->m_nArgc >= 2 )
  {
    v1 = defaultValue;
    if ( args->m_nArgc > 2 )
      v1 = args->m_ppArgv[2];
    v2 = atoi(nptr: v1);
    if ( v2 >= 0 && v2 < g_pServerPluginHandler->m_Plugins.m_Size )
    {
      v3 = g_pServerPluginHandler->m_Plugins.m_Memory.m_pMemory[v2];
      v3->m_pPlugin->Pause(this: v3->m_pPlugin);
      v3->m_bDisable = true;
    }
    ConMsg(a1: "Plugin disabled\n");
  }
  else
  {
    _Warning(a1: "Syntax: plugin_pause <index>\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012A2D0
// Name: plugin_unpause
// Source: json
//------------------------------------------------------------------------------
void __cdecl plugin_unpause(const CCommand *args)
{
  const char *v1; // eax
  int v2; // eax
  CPlugin *v3; // esi

  if ( args->m_nArgc >= 2 )
  {
    v1 = defaultValue;
    if ( args->m_nArgc > 2 )
      v1 = args->m_ppArgv[2];
    v2 = atoi(nptr: v1);
    if ( v2 >= 0 && v2 < g_pServerPluginHandler->m_Plugins.m_Size )
    {
      v3 = g_pServerPluginHandler->m_Plugins.m_Memory.m_pMemory[v2];
      v3->m_pPlugin->UnPause(this: v3->m_pPlugin);
      v3->m_bDisable = false;
    }
    ConMsg(a1: "Plugin enabled\n");
  }
  else
  {
    _Warning(a1: "Syntax: plugin_unpause <index>\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012A340
// Name: plugin_pause_all
// Source: json
//------------------------------------------------------------------------------
void __cdecl plugin_pause_all()
{
  int v0; // esi
  int *p_m_Size; // ebx
  CPlugin *v2; // edi
  CUtlVector<CPlugin *,CUtlMemory<CPlugin *,int> > *p_m_Plugins; // [esp+8h] [ebp-4h]

  v0 = 0;
  p_m_Size = &g_pServerPluginHandler->m_Plugins.m_Size;
  if ( g_pServerPluginHandler->m_Plugins.m_Size > 0 )
  {
    p_m_Plugins = &g_pServerPluginHandler->m_Plugins;
    do
    {
      v2 = p_m_Plugins->m_Memory.m_pMemory[v0];
      v2->m_pPlugin->Pause(this: v2->m_pPlugin);
      ++v0;
      v2->m_bDisable = true;
    }
    while ( v0 < *p_m_Size );
  }
  ConMsg(a1: "Plugins disabled\n");
}

//------------------------------------------------------------------------------
// Address: 0x1012A3A0
// Name: plugin_unpause_all
// Source: json
//------------------------------------------------------------------------------
void __cdecl plugin_unpause_all()
{
  int v0; // esi
  int *p_m_Size; // ebx
  CPlugin *v2; // edi
  CUtlVector<CPlugin *,CUtlMemory<CPlugin *,int> > *p_m_Plugins; // [esp+8h] [ebp-4h]

  v0 = 0;
  p_m_Size = &g_pServerPluginHandler->m_Plugins.m_Size;
  if ( g_pServerPluginHandler->m_Plugins.m_Size > 0 )
  {
    p_m_Plugins = &g_pServerPluginHandler->m_Plugins;
    do
    {
      v2 = p_m_Plugins->m_Memory.m_pMemory[v0];
      v2->m_pPlugin->UnPause(this: v2->m_pPlugin);
      ++v0;
      v2->m_bDisable = false;
    }
    while ( v0 < *p_m_Size );
  }
  ConMsg(a1: "Plugins enabled\n");
}

//------------------------------------------------------------------------------
// Address: 0x1012A400
// Name: int SendCvarValueQueryToClient(class IClient __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
int __cdecl SendCvarValueQueryToClient(IClient *client, const char *pCvarName, bool bPluginQuery)
{
  int v3; // ecx
  SVC_GetCvarValue msg; // [esp+0h] [ebp-118h] BYREF

  v3 = g_iQueryCvarCookie++;
  msg.m_bReliable = true;
  msg.m_NetChannel = nullptr;
  msg.__vftable = (SVC_GetCvarValue_vtbl *)&SVC_GetCvarValue::`vftable';
  msg.m_iCookie = v3;
  msg.m_szCvarName = pCvarName;
  if ( !bPluginQuery )
    msg.m_iCookie = -v3;
  client->SendNetMsg(this: client, a2: &msg, a3: false, a4: false);
  return msg.m_iCookie;
}

//------------------------------------------------------------------------------
// Address: 0x1012A470
// Name: public: void CServerPlugin::UnloadPlugins(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerPlugin::UnloadPlugins(CServerPlugin *this)
{
  int i; // ebx
  CPlugin *v3; // esi
  IServerPluginCallbacks *m_pPlugin; // ecx
  struct CSysModule *m_pPluginModule; // eax

  for ( i = this->m_Plugins.m_Size - 1; i >= 0; --i )
  {
    v3 = this->m_Plugins.m_Memory.m_pMemory[i];
    m_pPlugin = v3->m_pPlugin;
    if ( m_pPlugin != nullptr )
      m_pPlugin->Unload(this: m_pPlugin);
    m_pPluginModule = v3->m_pPluginModule;
    v3->m_pPlugin = nullptr;
    g_pFileSystem->UnloadModule(this: g_pFileSystem, a2: m_pPluginModule);
    v3->m_pPluginModule = nullptr;
    if ( this->m_Plugins.m_Size - i - 1 > 0 )
      _V_memmove(
        dest: &this->m_Plugins.m_Memory.m_pMemory[i],
        src: &this->m_Plugins.m_Memory.m_pMemory[i + 1],
        count: 4 * (this->m_Plugins.m_Size - i - 1));
    --this->m_Plugins.m_Size;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012A4F0
// Name: public: bool CServerPlugin::UnloadPlugin(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CServerPlugin::UnloadPlugin(CServerPlugin *this, int index)
{
  CPlugin *v3; // esi
  IServerPluginCallbacks *m_pPlugin; // ecx
  struct CSysModule *m_pPluginModule; // eax

  if ( index < 0 || index >= this->m_Plugins.m_Size )
    return 0;
  v3 = this->m_Plugins.m_Memory.m_pMemory[index];
  m_pPlugin = v3->m_pPlugin;
  if ( m_pPlugin != nullptr )
    m_pPlugin->Unload(this: m_pPlugin);
  m_pPluginModule = v3->m_pPluginModule;
  v3->m_pPlugin = nullptr;
  g_pFileSystem->UnloadModule(this: g_pFileSystem, a2: m_pPluginModule);
  v3->m_pPluginModule = nullptr;
  if ( this->m_Plugins.m_Size - index - 1 > 0 )
    _V_memmove(
      dest: &this->m_Plugins.m_Memory.m_pMemory[index],
      src: &this->m_Plugins.m_Memory.m_pMemory[index + 1],
      count: 4 * (this->m_Plugins.m_Size - index - 1));
  --this->m_Plugins.m_Size;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1012A580
// Name: public: virtual int CServerPlugin::StartQueryCvarValue(struct edict_t __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CServerPlugin::StartQueryCvarValue(CServerPlugin *this, edict_t *pEntity, const char *pCvarName)
{
  int v3; // eax
  CBaseClient *v4; // eax
  IClient *v5; // ecx
  bool (__thiscall *SendNetMsg)(IClient *, INetMessage *, bool, bool); // eax
  void **v8; // [esp+0h] [ebp-118h] BYREF
  char v9; // [esp+4h] [ebp-114h]
  int v10; // [esp+8h] [ebp-110h]
  int v11; // [esp+10h] [ebp-108h]
  const char *v12; // [esp+14h] [ebp-104h]

  v3 = NUM_FOR_EDICTINFO(e: pEntity);
  if ( v3 < 1 || v3 > sv.m_Clients.m_Size )
  {
    _Warning(a1: "StartQueryCvarValue: Invalid entity\n");
    return -1;
  }
  else
  {
    v4 = sv.m_Clients.m_Memory.m_pMemory[v3 - 1];
    if ( v4 != nullptr )
      v5 = &v4->IClient;
    else
      v5 = nullptr;
    v11 = g_iQueryCvarCookie++;
    SendNetMsg = v5->SendNetMsg;
    v12 = pCvarName;
    v9 = 1;
    v10 = 0;
    v8 = &SVC_GetCvarValue::`vftable';
    SendNetMsg(this: v5, a2: (INetMessage *)&v8, a3: false, a4: false);
    return v11;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012A630
// Name: public: virtual void CServerPlugin::CreateMessage(struct edict_t __near *,enum DIALOG_TYPE,class KeyValues __near *,class IServerPluginCallbacks __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerPlugin::CreateMessage(
        CServerPlugin *this,
        edict_t *pEntity,
        DIALOG_TYPE type,
        KeyValues *data,
        IServerPluginCallbacks *plugin)
{
  IPluginHelpersCheck_vtbl *v6; // edi
  int v7; // eax
  int v8; // eax
  CBaseClient *v9; // eax
  IClient *v10; // esi
  SVC_Menu menu; // [esp+8h] [ebp-1Ch] BYREF

  if ( pEntity != nullptr )
  {
    if ( data != nullptr )
    {
      if ( plugin != nullptr )
      {
        if ( this->m_PluginHelperCheck == nullptr
          || (v6 = this->m_PluginHelperCheck->__vftable,
              v7 = ((int (__stdcall *)(edict_t *, DIALOG_TYPE, KeyValues *))plugin->GetPluginDescription)(
                     a1: pEntity,
                     a2: type,
                     a3: data),
              ((unsigned __int8 (__thiscall *)(IPluginHelpersCheck *, int))v6->CreateMessage)(
                a1: this->m_PluginHelperCheck,
                a2: v7) != 0) )
        {
          v8 = NUM_FOR_EDICTINFO(e: pEntity);
          if ( v8 < 1 || v8 > sv.m_Clients.m_Size )
          {
            ConMsg(a1: "Invalid entity\n");
          }
          else
          {
            v9 = sv.m_Clients.m_Memory.m_pMemory[v8 - 1];
            if ( v9 != nullptr )
              v10 = &v9->IClient;
            else
              v10 = nullptr;
            SVC_Menu::SVC_Menu(this: &menu, type, data);
            v10->SendNetMsg(this: v10, a2: &menu, a3: false, a4: false);
            SVC_Menu::~SVC_Menu(this: &menu);
          }
        }
        else
        {
          ConMsg(a1: "Disallowed by game dll\n");
        }
      }
      else
      {
        ConMsg(a1: "No plugin provided\n");
      }
    }
    else
    {
      ConMsg(a1: "No data keyvalues provided\n");
    }
  }
  else
  {
    ConMsg(a1: "Invaid pEntity\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012A740
// Name: public: virtual void CServerPlugin::ClientCommand(struct edict_t __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerPlugin::ClientCommand(CServerPlugin *this, edict_t *pEntity, const char *cmd)
{
  int v3; // eax
  int v4; // esi
  CBaseClient *v5; // eax
  int MaxClients; // eax

  v3 = NUM_FOR_EDICTINFO(e: pEntity);
  v4 = v3;
  if ( v3 < 1 || v3 > sv.m_Clients.m_Size )
  {
    MaxClients = CBaseServer::GetMaxClients(this: &sv);
    _Msg(
      a1: "\n"
      "!!!\n"
      "CServerPlugin::ClientCommand:  Some entity tried to stuff '%s' to console buffer of entity %i when maxclients was "
      "set to %i, ignoring\n"
      "\n",
      cmd,
      v4,
      MaxClients);
  }
  else
  {
    v5 = sv.m_Clients.m_Memory.m_pMemory[v3 - 1];
    if ( v5 != nullptr )
      v5->ExecuteStringCommand(this: &v5->IClient, a2: cmd);
    else
      (*(void (__stdcall **)(const char *))(MEMORY[0] + 112))(a1: cmd);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012A7C0
// Name: plugin_unload
// Source: json
//------------------------------------------------------------------------------
void __cdecl plugin_unload(const CCommand *args)
{
  const char *v1; // eax
  int v2; // eax

  if ( args->m_nArgc >= 2 )
  {
    v1 = defaultValue;
    if ( args->m_nArgc > 1 )
      v1 = args->m_ppArgv[1];
    v2 = atoi(nptr: v1);
    if ( CServerPlugin::UnloadPlugin(this: g_pServerPluginHandler, index: v2) != 0 )
    {
      if ( args->m_nArgc > 1 )
        ConMsg(a1: "Unloaded plugin \"%s\"\n", args->m_ppArgv[1]);
      else
        ConMsg(a1: "Unloaded plugin \"%s\"\n", defaultValue);
    }
    else if ( args->m_nArgc > 1 )
    {
      _Warning(a1: "Unable to unload plugin \"%s\", not found\n", args->m_ppArgv[1]);
    }
    else
    {
      _Warning(a1: "Unable to unload plugin \"%s\", not found\n", defaultValue);
    }
  }
  else
  {
    _Warning(a1: "plugin_unload <index>\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012A940
// Name: public: bool CServerPlugin::LoadPlugin(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CServerPlugin::LoadPlugin(CServerPlugin *this, const char *fileName)
{
  CPlugin *v3; // eax
  CPlugin *v4; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CPlugin **m_pMemory; // ecx
  int v8; // eax
  CPlugin **v9; // eax

  v3 = (CPlugin *)MemAlloc_Alloc(nSize: 0x90u);
  if ( v3 != nullptr )
  {
    v3->m_pPlugin = nullptr;
    v3->m_pPluginModule = nullptr;
    v3->m_bDisable = false;
    v3->m_szName[0] = 0;
    v4 = v3;
  }
  else
  {
    v4 = nullptr;
  }
  if ( CPlugin::Load(this: v4, fileName) != 0 )
  {
    m_Size = this->m_Plugins.m_Size;
    m_nAllocationCount = this->m_Plugins.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<INetMessage *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)&this->m_Plugins,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_Plugins.m_Size;
    m_pMemory = this->m_Plugins.m_Memory.m_pMemory;
    v8 = this->m_Plugins.m_Size - m_Size - 1;
    this->m_Plugins.m_pElements = m_pMemory;
    if ( v8 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v8);
    v9 = &this->m_Plugins.m_Memory.m_pMemory[m_Size];
    if ( v9 != nullptr )
      *v9 = v4;
    return 1;
  }
  else
  {
    if ( v4 != nullptr )
    {
      CPlugin::~CPlugin(this: v4);
      free(pMem: v4);
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012AA00
// Name: plugin_load
// Source: json
//------------------------------------------------------------------------------
void __cdecl plugin_load(const CCommand *args)
{
  const char *v1; // eax

  if ( args->m_nArgc >= 2 )
  {
    v1 = defaultValue;
    if ( args->m_nArgc > 1 )
      v1 = args->m_ppArgv[1];
    if ( CServerPlugin::LoadPlugin(this: g_pServerPluginHandler, fileName: v1) != 0 )
    {
      if ( args->m_nArgc > 1 )
        ConMsg(a1: "Loaded plugin \"%s\"\n", args->m_ppArgv[1]);
      else
        ConMsg(a1: "Loaded plugin \"%s\"\n", defaultValue);
    }
    else if ( args->m_nArgc > 1 )
    {
      _Warning(a1: "Unable to load plugin \"%s\"\n", args->m_ppArgv[1]);
    }
    else
    {
      _Warning(a1: "Unable to load plugin \"%s\"\n", defaultValue);
    }
  }
  else
  {
    _Warning(a1: "plugin_load <filename>\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012AAB0
// Name: public: void CServerPlugin::LoadPlugins(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerPlugin::LoadPlugins(CServerPlugin *this)
{
  CServerPlugin *v1; // esi
  const char *First; // edi
  IBaseFileSystem_vtbl *v3; // esi
  char *v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // esi
  IBaseFileSystem *v7; // ebx
  const char *v8; // eax
  const char *String; // eax
  void *(__cdecl *Factory)(const char *, int *); // eax

  v1 = this;
  CUtlVector<CPlugin *,CUtlMemory<CPlugin *,int>>::PurgeAndDeleteElements(this: &this->m_Plugins);
  First = Sys_FindFirst(path: "addons/*.vdf", basename: nullptr, namelength: 0);
  if ( First != nullptr )
  {
    do
    {
      DevMsg(a1: "Plugins: found file \"%s\"\n", First);
      v3 = g_pFileSystem->IBaseFileSystem::__vftable;
      v4 = va(format: "addons/%s", First);
      if ( v3->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: v4, a3: "MOD") )
      {
        v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v5 != nullptr )
          v6 = KeyValues::KeyValues(this: v5, setName: "Plugins");
        else
          v6 = nullptr;
        if ( g_pFileSystem != nullptr )
          v7 = &g_pFileSystem->IBaseFileSystem;
        else
          v7 = nullptr;
        v8 = va(format: "addons/%s", First);
        KeyValues::LoadFromFile(
          this: v6,
          filesystem: v7,
          resourceName: v8,
          pathID: "MOD",
          pfnEvaluateSymbolProc: nullptr);
        if ( KeyValues::GetString(this: v6, keyName: "file", defaultValue: nullptr) != nullptr )
        {
          String = KeyValues::GetString(this: v6, keyName: "file", defaultValue: defaultValue);
          CServerPlugin::LoadPlugin(this, fileName: String);
        }
        KeyValues::deleteThis(this: v6);
      }
      First = Sys_FindNext(basename: nullptr, namelength: 0);
    }
    while ( First != nullptr );
    v1 = this;
  }
  Sys_FindClose();
  Factory = Sys_GetFactory(pModule: g_GameDLL);
  v1->m_PluginHelperCheck = (IPluginHelpersCheck *)Factory(a1: "PluginHelpersCheck001", a2: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10318310
// Name: _dynamic_initializer_for__plugin_print_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__plugin_print_command__()
{
  ConCommand::ConCommand(
    this: &plugin_print_command,
    pName: "plugin_print",
    callback: plugin_print,
    pHelpString: "Prints details about loaded plugins",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__plugin_print_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10318340
// Name: _dynamic_initializer_for__plugin_pause_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__plugin_pause_command__()
{
  ConCommand::ConCommand(
    this: &plugin_pause_command,
    pName: "plugin_pause",
    callback: (void (__cdecl *)())plugin_pause,
    pHelpString: "plugin_pause <index> : pauses a loaded plugin",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__plugin_pause_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10318370
// Name: _dynamic_initializer_for__plugin_unpause_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__plugin_unpause_command__()
{
  ConCommand::ConCommand(
    this: &plugin_unpause_command,
    pName: "plugin_unpause",
    callback: (void (__cdecl *)())plugin_unpause,
    pHelpString: "plugin_unpause <index> : unpauses a disabled plugin",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__plugin_unpause_command__);
}

//------------------------------------------------------------------------------
// Address: 0x103183A0
// Name: _dynamic_initializer_for__plugin_pause_all_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__plugin_pause_all_command__()
{
  ConCommand::ConCommand(
    this: &plugin_pause_all_command,
    pName: "plugin_pause_all",
    callback: plugin_pause_all,
    pHelpString: "pauses all loaded plugins",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__plugin_pause_all_command__);
}

//------------------------------------------------------------------------------
// Address: 0x103183D0
// Name: _dynamic_initializer_for__plugin_unpause_all_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__plugin_unpause_all_command__()
{
  ConCommand::ConCommand(
    this: &plugin_unpause_all_command,
    pName: "plugin_unpause_all",
    callback: plugin_unpause_all,
    pHelpString: "unpauses all disabled plugins",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__plugin_unpause_all_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10318400
// Name: _dynamic_initializer_for__plugin_load_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__plugin_load_command__()
{
  ConCommand::ConCommand(
    this: &plugin_load_command,
    pName: "plugin_load",
    callback: (void (__cdecl *)())plugin_load,
    pHelpString: "plugin_load <filename> : loads a plugin",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__plugin_load_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10318430
// Name: _dynamic_initializer_for__plugin_unload_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__plugin_unload_command__()
{
  ConCommand::ConCommand(
    this: &plugin_unload_command,
    pName: "plugin_unload",
    callback: (void (__cdecl *)())plugin_unload,
    pHelpString: "plugin_unload <index> : unloads a plugin",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__plugin_unload_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10324680
// Name: _dynamic_atexit_destructor_for__plugin_print_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__plugin_print_command__()
{
  ConCommand::~ConCommand(this: &plugin_print_command);
}

//------------------------------------------------------------------------------
// Address: 0x10324690
// Name: _dynamic_atexit_destructor_for__plugin_pause_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__plugin_pause_command__()
{
  ConCommand::~ConCommand(this: &plugin_pause_command);
}

//------------------------------------------------------------------------------
// Address: 0x103246A0
// Name: _dynamic_atexit_destructor_for__plugin_unpause_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__plugin_unpause_command__()
{
  ConCommand::~ConCommand(this: &plugin_unpause_command);
}

//------------------------------------------------------------------------------
// Address: 0x103246B0
// Name: _dynamic_atexit_destructor_for__plugin_pause_all_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__plugin_pause_all_command__()
{
  ConCommand::~ConCommand(this: &plugin_pause_all_command);
}

//------------------------------------------------------------------------------
// Address: 0x103246C0
// Name: _dynamic_atexit_destructor_for__plugin_unpause_all_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__plugin_unpause_all_command__()
{
  ConCommand::~ConCommand(this: &plugin_unpause_all_command);
}

//------------------------------------------------------------------------------
// Address: 0x103246D0
// Name: _dynamic_atexit_destructor_for__plugin_load_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__plugin_load_command__()
{
  ConCommand::~ConCommand(this: &plugin_load_command);
}

//------------------------------------------------------------------------------
// Address: 0x103246E0
// Name: _dynamic_atexit_destructor_for__plugin_unload_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__plugin_unload_command__()
{
  ConCommand::~ConCommand(this: &plugin_unload_command);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10129980
// Name: public: CPlugin::~CPlugin(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlugin::~CPlugin(CPlugin *this)
{
  IServerPluginCallbacks *m_pPlugin; // ecx
  struct CSysModule *m_pPluginModule; // edx
  struct CSysModule *v4; // eax

  m_pPlugin = this->m_pPlugin;
  if ( m_pPlugin != nullptr )
  {
    m_pPlugin->Unload(this: m_pPlugin);
    m_pPluginModule = this->m_pPluginModule;
    this->m_pPlugin = nullptr;
    g_pFileSystem->UnloadModule(this: g_pFileSystem, a2: m_pPluginModule);
    this->m_pPluginModule = nullptr;
  }
  v4 = this->m_pPluginModule;
  this->m_pPlugin = nullptr;
  if ( v4 != nullptr )
    g_pFileSystem->UnloadModule(this: g_pFileSystem, a2: v4);
  this->m_pPluginModule = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101299E0
// Name: public: bool CPlugin::Load(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CPlugin::Load(CPlugin *this, const char *fileName)
{
  struct CSysModule *v3; // eax
  void *(__cdecl *Factory)(const char *, int *); // eax
  void *(__cdecl *v5)(const char *, int *); // edi
  IServerPluginCallbacks *v6; // eax
  IServerPluginCallbacks *v7; // eax
  IServerPluginCallbacks *v8; // eax
  void *(__cdecl *v10)(const char *, int *); // eax
  const char *v11; // eax
  char fixedFileName[260]; // [esp+8h] [ebp-104h] BYREF

  V_strncpy(pDest: fixedFileName, pSrc: fileName, maxLen: 260);
  V_FixSlashes(pname: fixedFileName, separator: 92);
  v3 = g_pFileSystem->LoadModule(this: g_pFileSystem, a2: fixedFileName, a3: "GAME", a4: 0);
  this->m_pPluginModule = v3;
  if ( v3 != nullptr )
  {
    Factory = Sys_GetFactory(pModule: v3);
    v5 = Factory;
    if ( Factory != nullptr )
    {
      this->m_iPluginInterfaceVersion = 3;
      v6 = (IServerPluginCallbacks *)Factory(a1: "ISERVERPLUGINCALLBACKS003", a2: nullptr);
      this->m_pPlugin = v6;
      if ( v6 == nullptr )
      {
        this->m_iPluginInterfaceVersion = 2;
        v7 = (IServerPluginCallbacks *)v5(a1: "ISERVERPLUGINCALLBACKS002", a2: nullptr);
        this->m_pPlugin = v7;
        if ( v7 == nullptr )
        {
          this->m_iPluginInterfaceVersion = 1;
          v8 = (IServerPluginCallbacks *)v5(a1: "ISERVERPLUGINCALLBACKS001", a2: nullptr);
          this->m_pPlugin = v8;
          if ( v8 == nullptr )
          {
            _Warning(a1: "Could not get IServerPluginCallbacks interface from plugin \"%s\"", fileName);
            return 0;
          }
        }
      }
      v10 = Sys_GetFactory(pModule: g_GameDLL);
      if ( ((int (__thiscall *)(IServerPluginCallbacks *, void *(__cdecl *)(const char *, int *), void *(__cdecl *)(const char *, int *)))this->m_pPlugin->Load)(
             a1: this->m_pPlugin,
             a2: g_AppSystemFactory,
             a3: v10) == 0 )
      {
        _Warning(a1: "Failed to load plugin \"%s\"\n", fileName);
        return 0;
      }
      v11 = this->m_pPlugin->GetPluginDescription(this: this->m_pPlugin);
      V_strncpy(pDest: this->m_szName, pSrc: v11, maxLen: 128);
    }
    return 1;
  }
  else
  {
    _Warning(a1: "Unable to load plugin \"%s\"\n", fileName);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10129B50
// Name: public: void CServerPlugin::PrintDetails(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerPlugin::PrintDetails(CServerPlugin *this)
{
  int i; // esi
  CPlugin *v3; // eax
  const char *v4; // ecx

  ConMsg(a1: "Loaded plugins:\n");
  ConMsg(a1: "---------------------\n");
  for ( i = 0; i < this->m_Plugins.m_Size; ++i )
  {
    v3 = this->m_Plugins.m_Memory.m_pMemory[i];
    v4 = " (disabled)";
    if ( !v3->m_bDisable )
      v4 = defaultValue;
    ConMsg(a1: "%i:\t\"%s\"%s\n", i, v3->m_szName, v4);
  }
  ConMsg(a1: "---------------------\n");
}

//------------------------------------------------------------------------------
// Address: 0x10129BB0
// Name: public: virtual void CServerPlugin::LevelInit(char const __near *,char const __near *,char const __near *,char const __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerPlugin::LevelInit(
        CServerPlugin *this,
        const char *pMapName,
        const char *pMapEntities,
        const char *pOldLevel,
        const char *pLandmarkName,
        BOOL loadGame,
        BOOL background)
{
  IMDLCache *v7; // ebx
  int i; // esi
  CPlugin *v10; // eax
  IServerPluginCallbacks *m_pPlugin; // ecx
  BOOL bPrevState; // [esp+Ch] [ebp-4h]

  v7 = g_pMDLCache;
  g_pMDLCache->BeginCoarseLock(this: g_pMDLCache);
  for ( i = 0; i < this->m_Plugins.m_Size; ++i )
  {
    v10 = this->m_Plugins.m_Memory.m_pMemory[i];
    if ( !v10->m_bDisable )
    {
      m_pPlugin = v10->m_pPlugin;
      if ( m_pPlugin == nullptr )
      {
        _Warning(a1: "Unable to get callback interface for \"%s\"\n", this->m_Plugins.m_Memory.m_pMemory[i]->m_szName);
        m_pPlugin = nullptr;
      }
      m_pPlugin->LevelInit(this: m_pPlugin, a2: pMapName);
    }
  }
  LOBYTE(bPrevState) = CNetworkStringTableContainer::Lock(this: networkStringTableContainerServer, bLock: false);
  serverGameDLL->LevelInit(
    this: serverGameDLL,
    a2: pMapName,
    a3: pMapEntities,
    a4: pOldLevel,
    a5: pLandmarkName,
    a6: loadGame,
    a7: background);
  CNetworkStringTableContainer::Lock(this: networkStringTableContainerServer, bLock: bPrevState);
  v7->EndCoarseLock(this: v7);
}

//------------------------------------------------------------------------------
// Address: 0x10129C70
// Name: public: virtual void CServerPlugin::ServerActivate(struct edict_t __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerPlugin::ServerActivate(CServerPlugin *this, edict_t *pEdictList, int edictCount, int clientMax)
{
  IMDLCache *v4; // ebx
  int i; // edi
  CPlugin *v7; // eax
  IServerPluginCallbacks *m_pPlugin; // ecx

  v4 = g_pMDLCache;
  g_pMDLCache->BeginCoarseLock(this: g_pMDLCache);
  for ( i = 0; i < this->m_Plugins.m_Size; ++i )
  {
    v7 = this->m_Plugins.m_Memory.m_pMemory[i];
    if ( !v7->m_bDisable )
    {
      m_pPlugin = v7->m_pPlugin;
      if ( m_pPlugin == nullptr )
      {
        _Warning(a1: "Unable to get callback interface for \"%s\"\n", this->m_Plugins.m_Memory.m_pMemory[i]->m_szName);
        m_pPlugin = nullptr;
      }
      m_pPlugin->ServerActivate(this: m_pPlugin, a2: pEdictList, a3: edictCount, a4: clientMax);
    }
  }
  serverGameDLL->ServerActivate(this: serverGameDLL, a2: pEdictList, a3: edictCount, a4: clientMax);
  v4->EndCoarseLock(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10129D00
// Name: public: virtual void CServerPlugin::GameFrame(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerPlugin::GameFrame(CServerPlugin *this, BOOL simulating)
{
  int i; // esi
  CPlugin *v4; // eax
  IServerPluginCallbacks *m_pPlugin; // ecx

  for ( i = 0; i < this->m_Plugins.m_Size; ++i )
  {
    v4 = this->m_Plugins.m_Memory.m_pMemory[i];
    if ( !v4->m_bDisable )
    {
      m_pPlugin = v4->m_pPlugin;
      if ( m_pPlugin == nullptr )
      {
        _Warning(a1: "Unable to get callback interface for \"%s\"\n", this->m_Plugins.m_Memory.m_pMemory[i]->m_szName);
        m_pPlugin = nullptr;
      }
      m_pPlugin->GameFrame(this: m_pPlugin, a2: simulating);
    }
  }
  serverGameDLL->GameFrame(this: serverGameDLL, a2: simulating);
}

//------------------------------------------------------------------------------
// Address: 0x10129D70
// Name: public: virtual void CServerPlugin::LevelShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerPlugin::LevelShutdown(CServerPlugin *this)
{
  IMDLCache *v1; // ebx
  int v3; // esi
  CPlugin *v4; // eax
  IServerPluginCallbacks *m_pPlugin; // ecx
  IMDLCache *cacheCoarseCriticalSection; // [esp+Ch] [ebp-4h]

  v1 = g_pMDLCache;
  cacheCoarseCriticalSection = g_pMDLCache;
  g_pMDLCache->BeginCoarseLock(this: g_pMDLCache);
  v3 = 0;
  if ( this->m_Plugins.m_Size > 0 )
  {
    do
    {
      v4 = this->m_Plugins.m_Memory.m_pMemory[v3];
      if ( !v4->m_bDisable )
      {
        m_pPlugin = v4->m_pPlugin;
        if ( m_pPlugin == nullptr )
        {
          _Warning(
            a1: "Unable to get callback interface for \"%s\"\n",
            this->m_Plugins.m_Memory.m_pMemory[v3]->m_szName);
          m_pPlugin = nullptr;
        }
        m_pPlugin->LevelShutdown(this: m_pPlugin);
      }
      ++v3;
    }
    while ( v3 < this->m_Plugins.m_Size );
    v1 = cacheCoarseCriticalSection;
  }
  serverGameDLL->LevelShutdown(this: serverGameDLL);
  v1->EndCoarseLock(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x10129E00
// Name: public: virtual void CServerPlugin::ClientActive(struct edict_t __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerPlugin::ClientActive(CServerPlugin *this, edict_t *pEntity, BOOL bLoadGame)
{
  int i; // esi
  CPlugin *v5; // eax
  IServerPluginCallbacks *m_pPlugin; // ecx

  for ( i = 0; i < this->m_Plugins.m_Size; ++i )
  {
    v5 = this->m_Plugins.m_Memory.m_pMemory[i];
    if ( !v5->m_bDisable )
    {
      m_pPlugin = v5->m_pPlugin;
      if ( m_pPlugin == nullptr )
      {
        _Warning(a1: "Unable to get callback interface for \"%s\"\n", this->m_Plugins.m_Memory.m_pMemory[i]->m_szName);
        m_pPlugin = nullptr;
      }
      m_pPlugin->ClientActive(this: m_pPlugin, a2: pEntity);
    }
  }
  serverGameClients->ClientActive(this: serverGameClients, a2: pEntity, a3: bLoadGame);
}

//------------------------------------------------------------------------------
// Address: 0x10129E70
// Name: public: virtual void CServerPlugin::ClientFullyConnect(struct edict_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerPlugin::ClientFullyConnect(CServerPlugin *this, edict_t *pEntity)
{
  int i; // esi
  CPlugin *v4; // eax
  IServerPluginCallbacks *m_pPlugin; // ecx

  for ( i = 0; i < this->m_Plugins.m_Size; ++i )
  {
    v4 = this->m_Plugins.m_Memory.m_pMemory[i];
    if ( !v4->m_bDisable )
    {
      m_pPlugin = v4->m_pPlugin;
      if ( m_pPlugin == nullptr )
      {
        _Warning(a1: "Unable to get callback interface for \"%s\"\n", this->m_Plugins.m_Memory.m_pMemory[i]->m_szName);
        m_pPlugin = nullptr;
      }
      m_pPlugin->ClientFullyConnect(this: m_pPlugin, a2: pEntity);
    }
  }
  serverGameClients->ClientFullyConnect(this: serverGameClients, a2: pEntity);
}

//------------------------------------------------------------------------------
// Address: 0x10129EE0
// Name: public: virtual void CServerPlugin::ClientDisconnect(struct edict_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerPlugin::ClientDisconnect(CServerPlugin *this, edict_t *pEntity)
{
  int i; // esi
  CPlugin *v4; // eax
  IServerPluginCallbacks *m_pPlugin; // ecx

  for ( i = 0; i < this->m_Plugins.m_Size; ++i )
  {
    v4 = this->m_Plugins.m_Memory.m_pMemory[i];
    if ( !v4->m_bDisable )
    {
      m_pPlugin = v4->m_pPlugin;
      if ( m_pPlugin == nullptr )
      {
        _Warning(a1: "Unable to get callback interface for \"%s\"\n", this->m_Plugins.m_Memory.m_pMemory[i]->m_szName);
        m_pPlugin = nullptr;
      }
      m_pPlugin->ClientDisconnect(this: m_pPlugin, a2: pEntity);
    }
  }
  serverGameClients->ClientDisconnect(this: serverGameClients, a2: pEntity);
}

//------------------------------------------------------------------------------
// Address: 0x10129F50
// Name: public: virtual void CServerPlugin::ClientPutInServer(struct edict_t __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerPlugin::ClientPutInServer(CServerPlugin *this, edict_t *pEntity, const char *playername)
{
  int i; // esi
  CPlugin *v5; // eax
  IServerPluginCallbacks *m_pPlugin; // ecx

  for ( i = 0; i < this->m_Plugins.m_Size; ++i )
  {
    v5 = this->m_Plugins.m_Memory.m_pMemory[i];
    if ( !v5->m_bDisable )
    {
      m_pPlugin = v5->m_pPlugin;
      if ( m_pPlugin == nullptr )
      {
        _Warning(a1: "Unable to get callback interface for \"%s\"\n", this->m_Plugins.m_Memory.m_pMemory[i]->m_szName);
        m_pPlugin = nullptr;
      }
      m_pPlugin->ClientPutInServer(this: m_pPlugin, a2: pEntity, a3: playername);
    }
  }
  serverGameClients->ClientPutInServer(this: serverGameClients, a2: pEntity, a3: playername);
}

//------------------------------------------------------------------------------
// Address: 0x10129FC0
// Name: public: virtual void CServerPlugin::SetCommandClient(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerPlugin::SetCommandClient(CServerPlugin *this, int index)
{
  int i; // esi
  CPlugin *v4; // eax
  IServerPluginCallbacks *m_pPlugin; // ecx

  for ( i = 0; i < this->m_Plugins.m_Size; ++i )
  {
    v4 = this->m_Plugins.m_Memory.m_pMemory[i];
    if ( !v4->m_bDisable )
    {
      m_pPlugin = v4->m_pPlugin;
      if ( m_pPlugin == nullptr )
      {
        _Warning(a1: "Unable to get callback interface for \"%s\"\n", this->m_Plugins.m_Memory.m_pMemory[i]->m_szName);
        m_pPlugin = nullptr;
      }
      m_pPlugin->SetCommandClient(this: m_pPlugin, a2: index);
    }
  }
  serverGameClients->SetCommandClient(this: serverGameClients, a2: index);
}

//------------------------------------------------------------------------------
// Address: 0x1012A030
// Name: public: virtual void CServerPlugin::ClientSettingsChanged(struct edict_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerPlugin::ClientSettingsChanged(CServerPlugin *this, edict_t *pEdict)
{
  int i; // esi
  CPlugin *v4; // eax
  IServerPluginCallbacks *m_pPlugin; // ecx

  for ( i = 0; i < this->m_Plugins.m_Size; ++i )
  {
    v4 = this->m_Plugins.m_Memory.m_pMemory[i];
    if ( !v4->m_bDisable )
    {
      m_pPlugin = v4->m_pPlugin;
      if ( m_pPlugin == nullptr )
      {
        _Warning(a1: "Unable to get callback interface for \"%s\"\n", this->m_Plugins.m_Memory.m_pMemory[i]->m_szName);
        m_pPlugin = nullptr;
      }
      m_pPlugin->ClientSettingsChanged(this: m_pPlugin, a2: pEdict);
    }
  }
  serverGameClients->ClientSettingsChanged(this: serverGameClients, a2: pEdict);
}

//------------------------------------------------------------------------------
// Address: 0x1012A0A0
// Name: public: virtual bool CServerPlugin::ClientConnect(struct edict_t __near *,char const __near *,char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CServerPlugin::ClientConnect(
        CServerPlugin *this,
        edict_t *pEntity,
        const char *pszName,
        const char *pszAddress,
        char *reject,
        int maxrejectlen)
{
  int v7; // edi
  char v8; // bl
  CPlugin *v9; // eax
  IServerPluginCallbacks *m_pPlugin; // ecx
  int v11; // eax
  bool result; // al
  bool bSavedRetVal; // [esp+Eh] [ebp-2h]
  bool bAllowConnect; // [esp+Fh] [ebp-1h] BYREF

  v7 = 0;
  v8 = 0;
  bAllowConnect = true;
  for ( bSavedRetVal = true; v7 < this->m_Plugins.m_Size; ++v7 )
  {
    v9 = this->m_Plugins.m_Memory.m_pMemory[v7];
    if ( !v9->m_bDisable )
    {
      m_pPlugin = v9->m_pPlugin;
      if ( m_pPlugin == nullptr )
      {
        _Warning(a1: "Unable to get callback interface for \"%s\"\n", this->m_Plugins.m_Memory.m_pMemory[v7]->m_szName);
        m_pPlugin = nullptr;
      }
      v11 = m_pPlugin->ClientConnect(
              this: m_pPlugin,
              a2: &bAllowConnect,
              a3: pEntity,
              a4: pszName,
              a5: pszAddress,
              a6: reject,
              a7: maxrejectlen);
      if ( v11 == 2 )
        return bAllowConnect;
      if ( v11 == 1 && v8 == 0 )
      {
        bSavedRetVal = bAllowConnect;
        v8 = 1;
      }
    }
  }
  result = serverGameClients->ClientConnect(
             this: serverGameClients,
             a2: pEntity,
             a3: pszName,
             a4: pszAddress,
             a5: reject,
             a6: maxrejectlen);
  if ( v8 != 0 )
    return bSavedRetVal;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1012A1F0
// Name: public: virtual void CServerPlugin::NetworkIDValidated(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerPlugin::NetworkIDValidated(
        CServerPlugin *this,
        const char *pszUserName,
        const char *pszNetworkID)
{
  int i; // esi
  CPlugin *v5; // eax
  IServerPluginCallbacks *m_pPlugin; // ecx

  for ( i = 0; i < this->m_Plugins.m_Size; ++i )
  {
    v5 = this->m_Plugins.m_Memory.m_pMemory[i];
    if ( !v5->m_bDisable )
    {
      m_pPlugin = v5->m_pPlugin;
      if ( m_pPlugin == nullptr )
      {
        _Warning(a1: "Unable to get callback interface for \"%s\"\n", this->m_Plugins.m_Memory.m_pMemory[i]->m_szName);
        m_pPlugin = nullptr;
      }
      if ( m_pPlugin->NetworkIDValidated(this: m_pPlugin, a2: pszUserName, a3: pszNetworkID) == PLUGIN_STOP )
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012A3B0
// Name: plugin_print
// Source: json
//------------------------------------------------------------------------------
void __cdecl plugin_print()
{
  CServerPlugin::PrintDetails(this: g_pServerPluginHandler);
}

//------------------------------------------------------------------------------
// Address: 0x1012A3C0
// Name: plugin_pause
// Source: json
//------------------------------------------------------------------------------
void __cdecl plugin_pause(const CCommand *args)
{
  const char *v1; // eax
  int v2; // eax
  CPlugin *v3; // esi

  if ( args->m_nArgc >= 2 )
  {
    v1 = defaultValue;
    if ( args->m_nArgc > 2 )
      v1 = args->m_ppArgv[2];
    v2 = atoi(nptr: v1);
    if ( v2 >= 0 && v2 < g_pServerPluginHandler->m_Plugins.m_Size )
    {
      v3 = g_pServerPluginHandler->m_Plugins.m_Memory.m_pMemory[v2];
      v3->m_pPlugin->Pause(this: v3->m_pPlugin);
      v3->m_bDisable = true;
    }
    ConMsg(a1: "Plugin disabled\n");
  }
  else
  {
    _Warning(a1: "Syntax: plugin_pause <index>\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012A430
// Name: plugin_unpause
// Source: json
//------------------------------------------------------------------------------
void __cdecl plugin_unpause(const CCommand *args)
{
  const char *v1; // eax
  int v2; // eax
  CPlugin *v3; // esi

  if ( args->m_nArgc >= 2 )
  {
    v1 = defaultValue;
    if ( args->m_nArgc > 2 )
      v1 = args->m_ppArgv[2];
    v2 = atoi(nptr: v1);
    if ( v2 >= 0 && v2 < g_pServerPluginHandler->m_Plugins.m_Size )
    {
      v3 = g_pServerPluginHandler->m_Plugins.m_Memory.m_pMemory[v2];
      v3->m_pPlugin->UnPause(this: v3->m_pPlugin);
      v3->m_bDisable = false;
    }
    ConMsg(a1: "Plugin enabled\n");
  }
  else
  {
    _Warning(a1: "Syntax: plugin_unpause <index>\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012A4A0
// Name: plugin_pause_all
// Source: json
//------------------------------------------------------------------------------
void __cdecl plugin_pause_all()
{
  int v0; // esi
  int *p_m_Size; // ebx
  CPlugin *v2; // edi
  CUtlVector<CPlugin *,CUtlMemory<CPlugin *,int> > *p_m_Plugins; // [esp+8h] [ebp-4h]

  v0 = 0;
  p_m_Size = &g_pServerPluginHandler->m_Plugins.m_Size;
  if ( g_pServerPluginHandler->m_Plugins.m_Size > 0 )
  {
    p_m_Plugins = &g_pServerPluginHandler->m_Plugins;
    do
    {
      v2 = p_m_Plugins->m_Memory.m_pMemory[v0];
      v2->m_pPlugin->Pause(this: v2->m_pPlugin);
      ++v0;
      v2->m_bDisable = true;
    }
    while ( v0 < *p_m_Size );
  }
  ConMsg(a1: "Plugins disabled\n");
}

//------------------------------------------------------------------------------
// Address: 0x1012A500
// Name: plugin_unpause_all
// Source: json
//------------------------------------------------------------------------------
void __cdecl plugin_unpause_all()
{
  int v0; // esi
  int *p_m_Size; // ebx
  CPlugin *v2; // edi
  CUtlVector<CPlugin *,CUtlMemory<CPlugin *,int> > *p_m_Plugins; // [esp+8h] [ebp-4h]

  v0 = 0;
  p_m_Size = &g_pServerPluginHandler->m_Plugins.m_Size;
  if ( g_pServerPluginHandler->m_Plugins.m_Size > 0 )
  {
    p_m_Plugins = &g_pServerPluginHandler->m_Plugins;
    do
    {
      v2 = p_m_Plugins->m_Memory.m_pMemory[v0];
      v2->m_pPlugin->UnPause(this: v2->m_pPlugin);
      ++v0;
      v2->m_bDisable = false;
    }
    while ( v0 < *p_m_Size );
  }
  ConMsg(a1: "Plugins enabled\n");
}

//------------------------------------------------------------------------------
// Address: 0x1012A560
// Name: int SendCvarValueQueryToClient(class IClient __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
int __cdecl SendCvarValueQueryToClient(IClient *client, const char *pCvarName, bool bPluginQuery)
{
  int v3; // ecx
  SVC_GetCvarValue msg; // [esp+0h] [ebp-118h] BYREF

  v3 = g_iQueryCvarCookie++;
  msg.m_bReliable = true;
  msg.m_NetChannel = nullptr;
  msg.__vftable = (SVC_GetCvarValue_vtbl *)&SVC_GetCvarValue::`vftable';
  msg.m_iCookie = v3;
  msg.m_szCvarName = pCvarName;
  if ( !bPluginQuery )
    msg.m_iCookie = -v3;
  client->SendNetMsg(this: client, a2: &msg, a3: false, a4: false);
  return msg.m_iCookie;
}

//------------------------------------------------------------------------------
// Address: 0x1012A5D0
// Name: public: void CServerPlugin::UnloadPlugins(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerPlugin::UnloadPlugins(CServerPlugin *this)
{
  int i; // ebx
  CPlugin *v3; // esi
  IServerPluginCallbacks *m_pPlugin; // ecx
  struct CSysModule *m_pPluginModule; // eax

  for ( i = this->m_Plugins.m_Size - 1; i >= 0; --i )
  {
    v3 = this->m_Plugins.m_Memory.m_pMemory[i];
    m_pPlugin = v3->m_pPlugin;
    if ( m_pPlugin != nullptr )
      m_pPlugin->Unload(this: m_pPlugin);
    m_pPluginModule = v3->m_pPluginModule;
    v3->m_pPlugin = nullptr;
    g_pFileSystem->UnloadModule(this: g_pFileSystem, a2: m_pPluginModule);
    v3->m_pPluginModule = nullptr;
    if ( this->m_Plugins.m_Size - i - 1 > 0 )
      _V_memmove(
        dest: &this->m_Plugins.m_Memory.m_pMemory[i],
        src: &this->m_Plugins.m_Memory.m_pMemory[i + 1],
        count: 4 * (this->m_Plugins.m_Size - i - 1));
    --this->m_Plugins.m_Size;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012A650
// Name: public: bool CServerPlugin::UnloadPlugin(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CServerPlugin::UnloadPlugin(CServerPlugin *this, int index)
{
  CPlugin *v3; // esi
  IServerPluginCallbacks *m_pPlugin; // ecx
  struct CSysModule *m_pPluginModule; // eax

  if ( index < 0 || index >= this->m_Plugins.m_Size )
    return 0;
  v3 = this->m_Plugins.m_Memory.m_pMemory[index];
  m_pPlugin = v3->m_pPlugin;
  if ( m_pPlugin != nullptr )
    m_pPlugin->Unload(this: m_pPlugin);
  m_pPluginModule = v3->m_pPluginModule;
  v3->m_pPlugin = nullptr;
  g_pFileSystem->UnloadModule(this: g_pFileSystem, a2: m_pPluginModule);
  v3->m_pPluginModule = nullptr;
  if ( this->m_Plugins.m_Size - index - 1 > 0 )
    _V_memmove(
      dest: &this->m_Plugins.m_Memory.m_pMemory[index],
      src: &this->m_Plugins.m_Memory.m_pMemory[index + 1],
      count: 4 * (this->m_Plugins.m_Size - index - 1));
  --this->m_Plugins.m_Size;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1012A6E0
// Name: public: virtual int CServerPlugin::StartQueryCvarValue(struct edict_t __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CServerPlugin::StartQueryCvarValue(CServerPlugin *this, edict_t *pEntity, const char *pCvarName)
{
  int v3; // eax
  CBaseClient *v4; // eax
  IClient *v5; // ecx
  bool (__thiscall *SendNetMsg)(IClient *, INetMessage *, bool, bool); // eax
  void **v8; // [esp+0h] [ebp-118h] BYREF
  char v9; // [esp+4h] [ebp-114h]
  int v10; // [esp+8h] [ebp-110h]
  int v11; // [esp+10h] [ebp-108h]
  const char *v12; // [esp+14h] [ebp-104h]

  v3 = NUM_FOR_EDICTINFO(e: pEntity);
  if ( v3 < 1 || v3 > sv.m_Clients.m_Size )
  {
    _Warning(a1: "StartQueryCvarValue: Invalid entity\n");
    return -1;
  }
  else
  {
    v4 = sv.m_Clients.m_Memory.m_pMemory[v3 - 1];
    if ( v4 != nullptr )
      v5 = &v4->IClient;
    else
      v5 = nullptr;
    v11 = g_iQueryCvarCookie++;
    SendNetMsg = v5->SendNetMsg;
    v12 = pCvarName;
    v9 = 1;
    v10 = 0;
    v8 = &SVC_GetCvarValue::`vftable';
    SendNetMsg(this: v5, a2: (INetMessage *)&v8, a3: false, a4: false);
    return v11;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012A790
// Name: public: virtual void CServerPlugin::CreateMessage(struct edict_t __near *,enum DIALOG_TYPE,class KeyValues __near *,class IServerPluginCallbacks __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerPlugin::CreateMessage(
        CServerPlugin *this,
        edict_t *pEntity,
        DIALOG_TYPE type,
        KeyValues *data,
        IServerPluginCallbacks *plugin)
{
  IPluginHelpersCheck_vtbl *v6; // edi
  int v7; // eax
  int v8; // eax
  CBaseClient *v9; // eax
  IClient *v10; // esi
  SVC_Menu menu; // [esp+8h] [ebp-1Ch] BYREF

  if ( pEntity != nullptr )
  {
    if ( data != nullptr )
    {
      if ( plugin != nullptr )
      {
        if ( this->m_PluginHelperCheck == nullptr
          || (v6 = this->m_PluginHelperCheck->__vftable,
              v7 = ((int (__stdcall *)(edict_t *, DIALOG_TYPE, KeyValues *))plugin->GetPluginDescription)(
                     a1: pEntity,
                     a2: type,
                     a3: data),
              ((unsigned __int8 (__thiscall *)(IPluginHelpersCheck *, int))v6->CreateMessage)(
                a1: this->m_PluginHelperCheck,
                a2: v7) != 0) )
        {
          v8 = NUM_FOR_EDICTINFO(e: pEntity);
          if ( v8 < 1 || v8 > sv.m_Clients.m_Size )
          {
            ConMsg(a1: "Invalid entity\n");
          }
          else
          {
            v9 = sv.m_Clients.m_Memory.m_pMemory[v8 - 1];
            if ( v9 != nullptr )
              v10 = &v9->IClient;
            else
              v10 = nullptr;
            SVC_Menu::SVC_Menu(this: &menu, type, data);
            v10->SendNetMsg(this: v10, a2: &menu, a3: false, a4: false);
            SVC_Menu::~SVC_Menu(this: &menu);
          }
        }
        else
        {
          ConMsg(a1: "Disallowed by game dll\n");
        }
      }
      else
      {
        ConMsg(a1: "No plugin provided\n");
      }
    }
    else
    {
      ConMsg(a1: "No data keyvalues provided\n");
    }
  }
  else
  {
    ConMsg(a1: "Invaid pEntity\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012A8A0
// Name: public: virtual void CServerPlugin::ClientCommand(struct edict_t __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerPlugin::ClientCommand(CServerPlugin *this, edict_t *pEntity, const char *cmd)
{
  int v3; // eax
  int v4; // esi
  CBaseClient *v5; // eax
  int MaxClients; // eax

  v3 = NUM_FOR_EDICTINFO(e: pEntity);
  v4 = v3;
  if ( v3 < 1 || v3 > sv.m_Clients.m_Size )
  {
    MaxClients = CBaseServer::GetMaxClients(this: &sv);
    _Msg(
      a1: "\n"
      "!!!\n"
      "CServerPlugin::ClientCommand:  Some entity tried to stuff '%s' to console buffer of entity %i when maxclients was "
      "set to %i, ignoring\n"
      "\n",
      cmd,
      v4,
      MaxClients);
  }
  else
  {
    v5 = sv.m_Clients.m_Memory.m_pMemory[v3 - 1];
    if ( v5 != nullptr )
      v5->ExecuteStringCommand(this: &v5->IClient, a2: cmd);
    else
      (*(void (__stdcall **)(const char *))(MEMORY[0] + 112))(a1: cmd);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012A920
// Name: plugin_unload
// Source: json
//------------------------------------------------------------------------------
void __cdecl plugin_unload(const CCommand *args)
{
  const char *v1; // eax
  int v2; // eax

  if ( args->m_nArgc >= 2 )
  {
    v1 = defaultValue;
    if ( args->m_nArgc > 1 )
      v1 = args->m_ppArgv[1];
    v2 = atoi(nptr: v1);
    if ( CServerPlugin::UnloadPlugin(this: g_pServerPluginHandler, index: v2) != 0 )
    {
      if ( args->m_nArgc > 1 )
        ConMsg(a1: "Unloaded plugin \"%s\"\n", args->m_ppArgv[1]);
      else
        ConMsg(a1: "Unloaded plugin \"%s\"\n", defaultValue);
    }
    else if ( args->m_nArgc > 1 )
    {
      _Warning(a1: "Unable to unload plugin \"%s\", not found\n", args->m_ppArgv[1]);
    }
    else
    {
      _Warning(a1: "Unable to unload plugin \"%s\", not found\n", defaultValue);
    }
  }
  else
  {
    _Warning(a1: "plugin_unload <index>\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012AAA0
// Name: public: bool CServerPlugin::LoadPlugin(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CServerPlugin::LoadPlugin(CServerPlugin *this, const char *fileName)
{
  CPlugin *v3; // eax
  CPlugin *v4; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CPlugin **m_pMemory; // ecx
  int v8; // eax
  CPlugin **v9; // eax

  v3 = (CPlugin *)MemAlloc_Alloc(nSize: 0x90u);
  if ( v3 != nullptr )
  {
    v3->m_pPlugin = nullptr;
    v3->m_pPluginModule = nullptr;
    v3->m_bDisable = false;
    v3->m_szName[0] = 0;
    v4 = v3;
  }
  else
  {
    v4 = nullptr;
  }
  if ( CPlugin::Load(this: v4, fileName) != 0 )
  {
    m_Size = this->m_Plugins.m_Size;
    m_nAllocationCount = this->m_Plugins.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<INetMessage *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)&this->m_Plugins,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_Plugins.m_Size;
    m_pMemory = this->m_Plugins.m_Memory.m_pMemory;
    v8 = this->m_Plugins.m_Size - m_Size - 1;
    this->m_Plugins.m_pElements = m_pMemory;
    if ( v8 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v8);
    v9 = &this->m_Plugins.m_Memory.m_pMemory[m_Size];
    if ( v9 != nullptr )
      *v9 = v4;
    return 1;
  }
  else
  {
    if ( v4 != nullptr )
    {
      CPlugin::~CPlugin(this: v4);
      free(pMem: v4);
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012AB60
// Name: plugin_load
// Source: json
//------------------------------------------------------------------------------
void __cdecl plugin_load(const CCommand *args)
{
  const char *v1; // eax

  if ( args->m_nArgc >= 2 )
  {
    v1 = defaultValue;
    if ( args->m_nArgc > 1 )
      v1 = args->m_ppArgv[1];
    if ( CServerPlugin::LoadPlugin(this: g_pServerPluginHandler, fileName: v1) != 0 )
    {
      if ( args->m_nArgc > 1 )
        ConMsg(a1: "Loaded plugin \"%s\"\n", args->m_ppArgv[1]);
      else
        ConMsg(a1: "Loaded plugin \"%s\"\n", defaultValue);
    }
    else if ( args->m_nArgc > 1 )
    {
      _Warning(a1: "Unable to load plugin \"%s\"\n", args->m_ppArgv[1]);
    }
    else
    {
      _Warning(a1: "Unable to load plugin \"%s\"\n", defaultValue);
    }
  }
  else
  {
    _Warning(a1: "plugin_load <filename>\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012AC10
// Name: public: void CServerPlugin::LoadPlugins(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerPlugin::LoadPlugins(CServerPlugin *this)
{
  CServerPlugin *v1; // esi
  const char *First; // edi
  IBaseFileSystem_vtbl *v3; // esi
  char *v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // esi
  IBaseFileSystem *v7; // ebx
  const char *v8; // eax
  const char *String; // eax
  void *(__cdecl *Factory)(const char *, int *); // eax

  v1 = this;
  CUtlVector<CPlugin *,CUtlMemory<CPlugin *,int>>::PurgeAndDeleteElements(this: &this->m_Plugins);
  First = Sys_FindFirst(path: "addons/*.vdf", basename: nullptr, namelength: 0);
  if ( First != nullptr )
  {
    do
    {
      DevMsg(a1: "Plugins: found file \"%s\"\n", First);
      v3 = g_pFileSystem->IBaseFileSystem::__vftable;
      v4 = va(format: "addons/%s", First);
      if ( v3->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: v4, a3: "MOD") )
      {
        v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v5 != nullptr )
          v6 = KeyValues::KeyValues(this: v5, setName: "Plugins");
        else
          v6 = nullptr;
        if ( g_pFileSystem != nullptr )
          v7 = &g_pFileSystem->IBaseFileSystem;
        else
          v7 = nullptr;
        v8 = va(format: "addons/%s", First);
        KeyValues::LoadFromFile(
          this: v6,
          filesystem: v7,
          resourceName: v8,
          pathID: "MOD",
          pfnEvaluateSymbolProc: nullptr);
        if ( KeyValues::GetString(this: v6, keyName: "file", defaultValue: nullptr) != nullptr )
        {
          String = KeyValues::GetString(this: v6, keyName: "file", defaultValue: defaultValue);
          CServerPlugin::LoadPlugin(this, fileName: String);
        }
        KeyValues::deleteThis(this: v6);
      }
      First = Sys_FindNext(basename: nullptr, namelength: 0);
    }
    while ( First != nullptr );
    v1 = this;
  }
  Sys_FindClose();
  Factory = Sys_GetFactory(pModule: g_GameDLL);
  v1->m_PluginHelperCheck = (IPluginHelpersCheck *)Factory(a1: "PluginHelpersCheck001", a2: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x103184E0
// Name: _dynamic_initializer_for__plugin_print_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__plugin_print_command__()
{
  ConCommand::ConCommand(
    this: &plugin_print_command,
    pName: "plugin_print",
    callback: plugin_print,
    pHelpString: "Prints details about loaded plugins",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__plugin_print_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10318510
// Name: _dynamic_initializer_for__plugin_pause_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__plugin_pause_command__()
{
  ConCommand::ConCommand(
    this: &plugin_pause_command,
    pName: "plugin_pause",
    callback: (void (__cdecl *)())plugin_pause,
    pHelpString: "plugin_pause <index> : pauses a loaded plugin",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__plugin_pause_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10318540
// Name: _dynamic_initializer_for__plugin_unpause_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__plugin_unpause_command__()
{
  ConCommand::ConCommand(
    this: &plugin_unpause_command,
    pName: "plugin_unpause",
    callback: (void (__cdecl *)())plugin_unpause,
    pHelpString: "plugin_unpause <index> : unpauses a disabled plugin",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__plugin_unpause_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10318570
// Name: _dynamic_initializer_for__plugin_pause_all_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__plugin_pause_all_command__()
{
  ConCommand::ConCommand(
    this: &plugin_pause_all_command,
    pName: "plugin_pause_all",
    callback: plugin_pause_all,
    pHelpString: "pauses all loaded plugins",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__plugin_pause_all_command__);
}

//------------------------------------------------------------------------------
// Address: 0x103185A0
// Name: _dynamic_initializer_for__plugin_unpause_all_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__plugin_unpause_all_command__()
{
  ConCommand::ConCommand(
    this: &plugin_unpause_all_command,
    pName: "plugin_unpause_all",
    callback: plugin_unpause_all,
    pHelpString: "unpauses all disabled plugins",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__plugin_unpause_all_command__);
}

//------------------------------------------------------------------------------
// Address: 0x103185D0
// Name: _dynamic_initializer_for__plugin_load_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__plugin_load_command__()
{
  ConCommand::ConCommand(
    this: &plugin_load_command,
    pName: "plugin_load",
    callback: (void (__cdecl *)())plugin_load,
    pHelpString: "plugin_load <filename> : loads a plugin",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__plugin_load_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10318600
// Name: _dynamic_initializer_for__plugin_unload_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__plugin_unload_command__()
{
  ConCommand::ConCommand(
    this: &plugin_unload_command,
    pName: "plugin_unload",
    callback: (void (__cdecl *)())plugin_unload,
    pHelpString: "plugin_unload <index> : unloads a plugin",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__plugin_unload_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10324860
// Name: _dynamic_atexit_destructor_for__plugin_print_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__plugin_print_command__()
{
  ConCommand::~ConCommand(this: &plugin_print_command);
}

//------------------------------------------------------------------------------
// Address: 0x10324870
// Name: _dynamic_atexit_destructor_for__plugin_pause_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__plugin_pause_command__()
{
  ConCommand::~ConCommand(this: &plugin_pause_command);
}

//------------------------------------------------------------------------------
// Address: 0x10324880
// Name: _dynamic_atexit_destructor_for__plugin_unpause_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__plugin_unpause_command__()
{
  ConCommand::~ConCommand(this: &plugin_unpause_command);
}

//------------------------------------------------------------------------------
// Address: 0x10324890
// Name: _dynamic_atexit_destructor_for__plugin_pause_all_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__plugin_pause_all_command__()
{
  ConCommand::~ConCommand(this: &plugin_pause_all_command);
}

//------------------------------------------------------------------------------
// Address: 0x103248A0
// Name: _dynamic_atexit_destructor_for__plugin_unpause_all_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__plugin_unpause_all_command__()
{
  ConCommand::~ConCommand(this: &plugin_unpause_all_command);
}

//------------------------------------------------------------------------------
// Address: 0x103248B0
// Name: _dynamic_atexit_destructor_for__plugin_load_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__plugin_load_command__()
{
  ConCommand::~ConCommand(this: &plugin_load_command);
}

//------------------------------------------------------------------------------
// Address: 0x103248C0
// Name: _dynamic_atexit_destructor_for__plugin_unload_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__plugin_unload_command__()
{
  ConCommand::~ConCommand(this: &plugin_unload_command);
}

} // namespace engine_xlsp
