// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/gameui/vguisystemmoduleloader.cpp
// Functions: 11
// ============================================================

#include "game\client\cstrike15\gameui\vguisystemmoduleloader.h"

//------------------------------------------------------------------------------
// Address: 0x101EC2C0
// Name: public: virtual void CVGuiSystemModuleLoader::SetPlatformToRestart(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVGuiSystemModuleLoader::SetPlatformToRestart(CVGuiSystemModuleLoader *this)
{
  this->m_bPlatformShouldRestartAfterExit = true;
}

//------------------------------------------------------------------------------
// Address: 0x101EC2D0
// Name: private: bool CVGuiSystemModuleLoader::InitializeAllModules(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVGuiSystemModuleLoader::InitializeAllModules(
        CVGuiSystemModuleLoader *this,
        void *(__cdecl **factorylist)(const char *, int *),
        int factorycount)
{
  int v4; // edi
  int v5; // ebx
  IVGuiModule *moduleInterface; // ecx
  int m_Size; // ebx
  void *v8; // esp
  int v9; // edi
  int v10; // ebx
  int v11; // edi
  int v12; // ecx
  int *v13; // ebx
  int v14; // edi
  unsigned int GameUIBasePanel; // eax
  bool result; // al
  const char *v17[3]; // [esp+0h] [ebp-14h] BYREF
  int i; // [esp+Ch] [ebp-8h]
  bool bSuccess; // [esp+13h] [ebp-1h]
  int factorycounta; // [esp+20h] [ebp+Ch]

  v4 = 0;
  bSuccess = true;
  if ( this->m_Modules.m_Size > 0 )
  {
    v5 = 0;
    do
    {
      moduleInterface = this->m_Modules.m_Memory.m_pMemory[v5].moduleInterface;
      if ( !moduleInterface->Initialize(this: moduleInterface, a2: factorylist, a3: factorycount) )
      {
        bSuccess = false;
        _Error(this: (ISceneTokenProcessor *)&stru_104B7750, a2: v17[0]);
      }
      ++v4;
      ++v5;
    }
    while ( v4 < this->m_Modules.m_Size );
  }
  m_Size = this->m_Modules.m_Size;
  v8 = alloca(4 * m_Size);
  v9 = 0;
  if ( m_Size > 0 )
  {
    v10 = 0;
    do
      v17[v9++] = (const char *)Sys_GetFactory(pModule: this->m_Modules.m_Memory.m_pMemory[v10++].module);
    while ( v9 < this->m_Modules.m_Size );
  }
  v11 = 0;
  i = 0;
  if ( this->m_Modules.m_Size > 0 )
  {
    for ( factorycounta = 0; ; v11 = factorycounta )
    {
      v12 = *(int *)((char *)&this->m_Modules.m_Memory.m_pMemory->moduleInterface + v11);
      if ( (*(unsigned __int8 (__thiscall **)(int, const char **, int))(*(_DWORD *)v12 + 8))(
             a1: v12,
             a2: v17,
             a3: this->m_Modules.m_Size) == 0 )
      {
        bSuccess = false;
        _Error(this: (ISceneTokenProcessor *)&stru_104B7750, a2: v17[0]);
      }
      v13 = *(int **)((char *)&this->m_Modules.m_Memory.m_pMemory->moduleInterface + v11);
      v14 = *v13;
      GameUIBasePanel = GetGameUIBasePanel();
      (*(void (__thiscall **)(int *, unsigned int))(v14 + 36))(a1: v13, a2: GameUIBasePanel);
      factorycounta += 12;
      if ( ++i >= this->m_Modules.m_Size )
        break;
    }
  }
  result = bSuccess;
  this->m_bModulesInitialized = true;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101EC3E0
// Name: public: void CVGuiSystemModuleLoader::DeactivatePlatformModules(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVGuiSystemModuleLoader::DeactivatePlatformModules(CVGuiSystemModuleLoader *this)
{
  int v2; // edi
  int v3; // ebx
  IVGuiModule *moduleInterface; // ecx

  v2 = 0;
  if ( this->m_Modules.m_Size > 0 )
  {
    v3 = 0;
    do
    {
      moduleInterface = this->m_Modules.m_Memory.m_pMemory[v3].moduleInterface;
      moduleInterface->Deactivate(this: moduleInterface);
      ++v2;
      ++v3;
    }
    while ( v2 < this->m_Modules.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EC410
// Name: public: virtual char const __near * CVGuiSystemModuleLoader::GetModuleLabel(int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CVGuiSystemModuleLoader::GetModuleLabel(CVGuiSystemModuleLoader *this, int moduleIndex)
{
  return KeyValues::GetString(
           this: this->m_Modules.m_Memory.m_pMemory[moduleIndex].data,
           keyName: "MenuName",
           defaultValue: "< unknown >");
}

//------------------------------------------------------------------------------
// Address: 0x101EC440
// Name: public: virtual bool CVGuiSystemModuleLoader::ActivateModule(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVGuiSystemModuleLoader::ActivateModule(CVGuiSystemModuleLoader *this, int moduleIndex)
{
  IVGuiModule *moduleInterface; // ecx

  if ( moduleIndex < 0 || moduleIndex >= this->m_Modules.m_Size )
    return 0;
  moduleInterface = this->m_Modules.m_Memory.m_pMemory[moduleIndex].moduleInterface;
  moduleInterface->Activate(this: moduleInterface);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101EC470
// Name: public: virtual bool CVGuiSystemModuleLoader::ActivateModule(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVGuiSystemModuleLoader::ActivateModule(CVGuiSystemModuleLoader *this, const char *moduleName)
{
  int v3; // edi
  int i; // ebx
  const char *v5; // eax
  const char *Name; // eax

  v3 = 0;
  if ( this->GetModuleCount(this) <= 0 )
    return 0;
  for ( i = 0; ; ++i )
  {
    v5 = this->GetModuleLabel(this, a2: v3);
    if ( _V_stricmp(s1: v5, s2: moduleName) == 0 )
      break;
    Name = KeyValues::GetName(this: this->m_Modules.m_Memory.m_pMemory[i].data);
    if ( _V_stricmp(s1: Name, s2: moduleName) == 0 )
      break;
    if ( ++v3 >= this->GetModuleCount(this) )
      return 0;
  }
  this->ActivateModule_2(this, a2: v3);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101EC4F0
// Name: public: virtual void __near * (*CVGuiSystemModuleLoader::GetModuleFactory(int))(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void *(__cdecl *__thiscall CVGuiSystemModuleLoader::GetModuleFactory(
        CVGuiSystemModuleLoader *this,
        int moduleIndex))(const char *, int *)
{
  return Sys_GetFactory(pModule: this->m_Modules.m_Memory.m_pMemory[moduleIndex].module);
}

//------------------------------------------------------------------------------
// Address: 0x101EC510
// Name: public: void CVGuiSystemModuleLoader::PostMessageToAllModules(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVGuiSystemModuleLoader::PostMessageToAllModules(CVGuiSystemModuleLoader *this, KeyValues *message)
{
  IVGuiModule *moduleInterface; // edi
  vgui::IVGui *v3; // ebx
  vgui::IVGui_vtbl *v4; // esi
  KeyValues *Copy; // eax
  int v6; // eax
  CVGuiSystemModuleLoader *v7; // [esp+10h] [ebp-Ch]
  int i; // [esp+14h] [ebp-8h]
  int v9; // [esp+18h] [ebp-4h]

  v7 = this;
  i = 0;
  if ( this->m_Modules.m_Size > 0 )
  {
    v9 = 0;
    do
    {
      moduleInterface = this->m_Modules.m_Memory.m_pMemory[v9].moduleInterface;
      v3 = g_pVGui;
      v4 = g_pVGui->__vftable;
      Copy = KeyValues::MakeCopy(this: message);
      v6 = ((int (__thiscall *)(IVGuiModule *, KeyValues *, _DWORD, _DWORD))moduleInterface->GetPanel)(
             a1: moduleInterface,
             a2: Copy,
             a3: 0,
             a4: 0);
      ((void (__thiscall *)(vgui::IVGui *, int))v4->PostMessage)(a1: v3, a2: v6);
      this = v7;
      ++v9;
      ++i;
    }
    while ( i < v7->m_Modules.m_Size );
  }
  KeyValues::deleteThis(this: message);
}

//------------------------------------------------------------------------------
// Address: 0x101EC590
// Name: public: void CVGuiSystemModuleLoader::ShutdownPlatformModules(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVGuiSystemModuleLoader::ShutdownPlatformModules(CVGuiSystemModuleLoader *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax
  IVGuiModule *moduleInterface; // ecx
  vgui::IVGui *v5; // ebx
  vgui::IVGui_vtbl *v6; // esi
  int v7; // eax
  int v8; // esi
  int v9; // ebx
  IVGuiModule *v10; // ecx
  int i; // [esp+10h] [ebp-8h]
  int v12; // [esp+14h] [ebp-4h]

  if ( !runningFunction )
  {
    runningFunction = true;
    CVGuiSystemModuleLoader::DeactivatePlatformModules(this);
    i = 0;
    if ( this->m_Modules.m_Size > 0 )
    {
      v12 = 0;
      do
      {
        v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v2 != nullptr )
          v3 = KeyValues::KeyValues(this: v2, setName: "Command", firstKey: "command", firstValue: "Quit");
        else
          v3 = nullptr;
        moduleInterface = this->m_Modules.m_Memory.m_pMemory[v12].moduleInterface;
        v5 = g_pVGui;
        v6 = g_pVGui->__vftable;
        v7 = ((int (__thiscall *)(IVGuiModule *, KeyValues *, _DWORD, _DWORD))moduleInterface->GetPanel)(
               a1: moduleInterface,
               a2: v3,
               a3: 0,
               a4: 0);
        ((void (__thiscall *)(vgui::IVGui *, int))v6->PostMessage)(a1: v5, a2: v7);
        ++v12;
        ++i;
      }
      while ( i < this->m_Modules.m_Size );
    }
    v8 = 0;
    if ( this->m_Modules.m_Size > 0 )
    {
      v9 = 0;
      do
      {
        v10 = this->m_Modules.m_Memory.m_pMemory[v9].moduleInterface;
        v10->Shutdown(this: v10);
        ++v8;
        ++v9;
      }
      while ( v8 < this->m_Modules.m_Size );
    }
    runningFunction = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EC660
// Name: public: void CVGuiSystemModuleLoader::UnloadPlatformModules(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVGuiSystemModuleLoader::UnloadPlatformModules(CVGuiSystemModuleLoader *this)
{
  int v2; // edi
  int v3; // ebx
  KeyValues *m_pPlatformModuleData; // ecx

  v2 = 0;
  if ( this->m_Modules.m_Size > 0 )
  {
    v3 = 0;
    do
    {
      g_pFullFileSystem->UnloadModule(this: g_pFullFileSystem, a2: this->m_Modules.m_Memory.m_pMemory[v3].module);
      ++v2;
      ++v3;
    }
    while ( v2 < this->m_Modules.m_Size );
  }
  this->m_Modules.m_Size = 0;
  m_pPlatformModuleData = this->m_pPlatformModuleData;
  if ( m_pPlatformModuleData != nullptr )
  {
    KeyValues::deleteThis(this: m_pPlatformModuleData);
    this->m_pPlatformModuleData = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EC6E0
// Name: public: bool CVGuiSystemModuleLoader::LoadPlatformModules(void __near * (*__near *)(char const __near *,int __near *),int,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVGuiSystemModuleLoader::LoadPlatformModules(
        CVGuiSystemModuleLoader *this,
        void *(__cdecl **factorylist)(const char *, int *),
        int factorycount,
        bool useSteamModules)
{
  CVGuiSystemModuleLoader *v4; // ebx
  KeyValues *v5; // eax
  IBaseFileSystem *v6; // eax
  KeyValues *v7; // edi
  KeyValues *Key; // eax
  KeyValues *FirstSubKey; // esi
  char *String; // edi
  char *v12; // eax
  struct CSysModule *v13; // eax
  struct CSysModule *v14; // ebx
  char *v15; // eax
  void *(__cdecl *Factory)(const char *, int *); // eax
  char *v17; // eax
  int v18; // eax
  char *v19; // [esp-8h] [ebp-20h]
  IVGuiModule *moduleInterface; // [esp+8h] [ebp-10h]
  KeyValues *kv; // [esp+10h] [ebp-8h]
  bool bSuccess; // [esp+17h] [ebp-1h]

  v4 = this;
  bSuccess = true;
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
    kv = KeyValues::KeyValues(this: v5, setName: "Platform");
  else
    kv = nullptr;
  if ( g_pFullFileSystem != nullptr )
    v6 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v6 = nullptr;
  v7 = kv;
  if ( KeyValues::LoadFromFile(
         this: kv,
         filesystem: v6,
         resourceName: "steam/games/PlatformMenu.vdf",
         pathID: "PLATFORM",
         pfnEvaluateSymbolProc: nullptr) )
  {
    Key = KeyValues::FindKey(this: kv, keyName: "Menu", bCreate: true);
    FirstSubKey = KeyValues::GetFirstSubKey(this: Key);
    if ( FirstSubKey != nullptr )
    {
      do
      {
        if ( useSteamModules || KeyValues::GetInt(this: FirstSubKey, keyName: "SteamApp", defaultValue: 0) == 0 )
        {
          String = KeyValues::GetString(this: FirstSubKey, keyName: "interface", defaultValue: prType);
          if ( _V_stricmp(s1: String, s2: "VGuiModuleTracker001") != 0 || !bSteamCommunityFriendsVersion )
          {
            v12 = KeyValues::GetString(this: FirstSubKey, keyName: "dll", defaultValue: prType);
            v13 = g_pFullFileSystem->LoadModule(this: g_pFullFileSystem, a2: v12, a3: "EXECUTABLE_PATH", a4: 1);
            v14 = v13;
            if ( v13 != nullptr )
            {
              Factory = Sys_GetFactory(pModule: v13);
              moduleInterface = (IVGuiModule *)Factory(a1: String, a2: nullptr);
              if ( moduleInterface != nullptr )
              {
                v18 = CUtlVector<OcclusionHandleViewIDPair_t,CUtlMemory<OcclusionHandleViewIDPair_t,int>>::AddToTail(this: (CUtlVector<OcclusionHandleViewIDPair_t,CUtlMemory<OcclusionHandleViewIDPair_t,int> > *)&this->m_Modules);
                this->m_Modules.m_Memory.m_pMemory[v18].module = v14;
                this->m_Modules.m_Memory.m_pMemory[v18].moduleInterface = moduleInterface;
                this->m_Modules.m_Memory.m_pMemory[v18].data = FirstSubKey;
              }
              else
              {
                v19 = KeyValues::GetString(this: FirstSubKey, keyName: "interface", defaultValue: prType);
                v17 = KeyValues::GetString(this: FirstSubKey, keyName: "dll", defaultValue: prType);
                _Warning(a1: "Platform Error: module version ('%s, %s) invalid, not loading\n", v17, v19);
                bSuccess = false;
              }
            }
            else
            {
              v15 = KeyValues::GetString(this: FirstSubKey, keyName: "dll", defaultValue: prType);
              _Error(this: (ISceneTokenProcessor *)&stru_104B7800, a2: v15);
              bSuccess = false;
            }
          }
        }
        FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
      }
      while ( FirstSubKey != nullptr );
      v7 = kv;
      v4 = this;
    }
    v4->m_pPlatformModuleData = v7;
    return CVGuiSystemModuleLoader::InitializeAllModules(this: v4, factorylist, factorycount) && bSuccess;
  }
  else
  {
    KeyValues::deleteThis(this: kv);
    return false;
  }
}
