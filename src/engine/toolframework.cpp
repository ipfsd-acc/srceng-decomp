// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/toolframework.cpp
// Functions: 96
// ============================================================

#include "engine\toolframework.h"

//------------------------------------------------------------------------------
// Address: 0x1017D020
// Name: public: virtual bool CToolFrameworkInternal::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolFrameworkInternal::Connect(CBaseClient *this, CLC_CmdKeyValues *msg)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101E8390
// Name: public: virtual void CBaseAppSystem<class IToolFrameworkInternal>::Reconnect(void __near * (*)(char const __near *,int __near *),char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAppSystem<IToolFrameworkInternal>::Reconnect(
        CBaseAppSystem<ICvarQuery> *this,
        void *(__cdecl *factory)(const char *, int *),
        const char *pInterfaceName)
{
  ReconnectInterface(factory, pInterfaceName);
}

//------------------------------------------------------------------------------
// Address: 0x102003B0
// Name: CToolFrameworkInternal_QuitHandler
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CToolFrameworkInternal_QuitHandler(void *pvUserData)
{
  return pvUserData == nullptr || (*(bool (__thiscall **)(void *))(*(_DWORD *)pvUserData + 112))(a1: pvUserData);
}

//------------------------------------------------------------------------------
// Address: 0x102003D0
// Name: public: virtual bool CToolFrameworkInternal::InToolMode(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CToolFrameworkInternal::InToolMode(CToolFrameworkInternal *this)
{
  return this->m_bInToolMode || g_bReplayLoadedTools;
}

//------------------------------------------------------------------------------
// Address: 0x10200420
// Name: public: virtual bool CServerEngineTools::InToolMode(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CServerEngineTools::InToolMode(CServerEngineTools *this)
{
  return g_ToolFrameworkInternal.m_bInToolMode || g_bReplayLoadedTools;
}

//------------------------------------------------------------------------------
// Address: 0x10200640
// Name: public: virtual bool CToolFrameworkInternal::PostInit(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CToolFrameworkInternal::PostInit(CToolFrameworkInternal *this)
{
  int m_Size; // ebx
  int v3; // esi
  IToolSystem *v4; // ecx
  bool bRetVal; // [esp+Fh] [ebp-1h]

  m_Size = this->m_ToolSystems.m_Size;
  v3 = 0;
  bRetVal = true;
  if ( m_Size <= 0 )
    goto LABEL_6;
  do
  {
    v4 = this->m_ToolSystems.m_Memory.m_pMemory[v3];
    if ( !v4->Init(this: v4) )
      bRetVal = false;
    ++v3;
  }
  while ( v3 < m_Size );
  if ( bRetVal )
LABEL_6:
    this->SwitchToTool_2(this, a2: 0);
  return bRetVal;
}

//------------------------------------------------------------------------------
// Address: 0x10200690
// Name: public: virtual void CToolFrameworkInternal::Think(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFrameworkInternal::Think(CToolFrameworkInternal *this, BOOL finalTick)
{
  int m_Size; // ebx
  int i; // esi
  IToolSystem *v5; // ecx

  m_Size = this->m_ToolSystems.m_Size;
  for ( i = 0; i < m_Size; ++i )
  {
    v5 = this->m_ToolSystems.m_Memory.m_pMemory[i];
    v5->Think(this: v5, a2: finalTick);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102006C0
// Name: public: virtual bool CToolFrameworkInternal::ServerInit(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CToolFrameworkInternal::ServerInit(
        CToolFrameworkInternal *this,
        void *(__cdecl *serverFactory)(const char *, int *))
{
  int m_Size; // ebx
  bool result; // al
  int v5; // esi
  IToolSystem *v6; // ecx
  bool retval; // [esp+Fh] [ebp-1h]

  m_Size = this->m_ToolSystems.m_Size;
  this->m_ServerFactory = serverFactory;
  result = true;
  v5 = 0;
  retval = true;
  if ( m_Size > 0 )
  {
    do
    {
      v6 = this->m_ToolSystems.m_Memory.m_pMemory[v5];
      if ( !v6->ServerInit(this: v6, a2: serverFactory) )
        retval = false;
      ++v5;
    }
    while ( v5 < m_Size );
    return retval;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10200710
// Name: public: virtual bool CToolFrameworkInternal::ClientInit(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CToolFrameworkInternal::ClientInit(
        CToolFrameworkInternal *this,
        void *(__cdecl *clientFactory)(const char *, int *))
{
  int m_Size; // ebx
  bool result; // al
  int v5; // esi
  IToolSystem *v6; // ecx
  bool retval; // [esp+Fh] [ebp-1h]

  m_Size = this->m_ToolSystems.m_Size;
  this->m_ClientFactory = clientFactory;
  result = true;
  v5 = 0;
  retval = true;
  if ( m_Size > 0 )
  {
    do
    {
      v6 = this->m_ToolSystems.m_Memory.m_pMemory[v5];
      if ( !v6->ClientInit(this: v6, a2: clientFactory) )
        retval = false;
      ++v5;
    }
    while ( v5 < m_Size );
    return retval;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10200760
// Name: public: virtual void CToolFrameworkInternal::ServerShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFrameworkInternal::ServerShutdown(CToolFrameworkInternal *this)
{
  int i; // esi
  IToolSystem *v3; // ecx

  for ( i = this->m_ToolSystems.m_Size - 1; i >= 0; --i )
  {
    v3 = this->m_ToolSystems.m_Memory.m_pMemory[i];
    v3->ServerShutdown(this: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10200790
// Name: public: virtual void CToolFrameworkInternal::ClientShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFrameworkInternal::ClientShutdown(CToolFrameworkInternal *this)
{
  int i; // esi
  IToolSystem *v3; // ecx

  for ( i = this->m_ToolSystems.m_Size - 1; i >= 0; --i )
  {
    v3 = this->m_ToolSystems.m_Memory.m_pMemory[i];
    v3->ClientShutdown(this: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102007C0
// Name: public: virtual bool CToolFrameworkInternal::CanQuit(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolFrameworkInternal::CanQuit(CToolFrameworkInternal *this)
{
  int m_Size; // ebx
  int v3; // esi
  IToolSystem *v4; // ecx

  m_Size = this->m_ToolSystems.m_Size;
  v3 = 0;
  if ( m_Size <= 0 )
    return 1;
  while ( 1 )
  {
    v4 = this->m_ToolSystems.m_Memory.m_pMemory[v3];
    if ( !v4->CanQuit(this: v4, a2: "OnQuit") )
      break;
    if ( ++v3 >= m_Size )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10200800
// Name: private: void CToolFrameworkInternal::ShutdownToolDictionaries(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFrameworkInternal::ShutdownToolDictionaries(CToolFrameworkInternal *this)
{
  int v2; // edi
  int v3; // ebx
  IToolDictionary *m_pDictionary; // ecx
  int v5; // ebx
  int v6; // edi
  IToolDictionary *v7; // ecx

  v2 = this->m_Modules.m_Size - 1;
  if ( v2 >= 0 )
  {
    v3 = v2;
    do
    {
      m_pDictionary = this->m_Modules.m_Memory.m_pMemory[v3].m_pDictionary;
      m_pDictionary->Shutdown(this: m_pDictionary);
      --v3;
      --v2;
    }
    while ( v2 >= 0 );
  }
  v5 = this->m_Modules.m_Size - 1;
  if ( v5 >= 0 )
  {
    v6 = v5;
    do
    {
      v7 = this->m_Modules.m_Memory.m_pMemory[v6].m_pDictionary;
      v7->Disconnect(this: v7);
      this->m_Modules.m_Memory.m_pMemory[v6--].m_pDictionary = nullptr;
      --v5;
    }
    while ( v5 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10200870
// Name: public: virtual bool CToolFrameworkInternal::ShouldGameRenderView(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CToolFrameworkInternal::ShouldGameRenderView(CToolFrameworkInternal *this)
{
  int m_nActiveToolIndex; // eax
  IToolSystem *v2; // ecx

  m_nActiveToolIndex = this->m_nActiveToolIndex;
  if ( m_nActiveToolIndex < 0 )
    return true;
  v2 = this->m_ToolSystems.m_Memory.m_pMemory[m_nActiveToolIndex];
  return v2->ShouldGameRenderView(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10200890
// Name: public: virtual bool CToolFrameworkInternal::ShouldGamePlaySounds(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CToolFrameworkInternal::ShouldGamePlaySounds(CToolFrameworkInternal *this)
{
  int m_nActiveToolIndex; // eax
  IToolSystem *v2; // ecx

  m_nActiveToolIndex = this->m_nActiveToolIndex;
  if ( m_nActiveToolIndex < 0 )
    return true;
  v2 = this->m_ToolSystems.m_Memory.m_pMemory[m_nActiveToolIndex];
  return v2->ShouldGamePlaySounds(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x102008B0
// Name: public: virtual class IMaterialProxy __near * CToolFrameworkInternal::LookupProxy(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IMaterialProxy *__thiscall CToolFrameworkInternal::LookupProxy(CToolFrameworkInternal *this, const char *proxyName)
{
  int v3; // esi
  IToolSystem *v4; // ecx
  IMaterialProxy *result; // eax
  int toolCount; // [esp+Ch] [ebp-4h]

  v3 = 0;
  toolCount = this->GetToolCount(this);
  if ( toolCount <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = this->m_ToolSystems.m_Memory.m_pMemory[v3];
    result = v4->LookupProxy(this: v4, a2: proxyName);
    if ( result != nullptr )
      break;
    if ( ++v3 >= toolCount )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10200900
// Name: public: struct ToolModule_t __near * CToolFrameworkInternal::Find(char const __near *)
// Source: json
//------------------------------------------------------------------------------
ToolModule_t *__thiscall CToolFrameworkInternal::Find(CToolFrameworkInternal *this, const char *pModuleName)
{
  int v2; // ebx
  ToolModule_t *v4; // esi
  const char *v5; // eax
  int i; // [esp+Ch] [ebp-4h]

  v2 = 0;
  i = 0;
  if ( this->m_Modules.m_Size <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = &this->m_Modules.m_Memory.m_pMemory[v2];
    v5 = CUtlString::operator char const *(this: &v4->m_sDllName);
    if ( _V_stricmp(s1: v5, s2: pModuleName) == 0 )
      break;
    ++v2;
    if ( ++i >= this->m_Modules.m_Size )
      return nullptr;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10200960
// Name: public: virtual void CToolFrameworkInternal::ClientLevelInitPreEntityAllTools(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFrameworkInternal::ClientLevelInitPreEntityAllTools(CToolFrameworkInternal *this)
{
  int m_Size; // ebx
  int i; // esi

  m_Size = this->m_ToolSystems.m_Size;
  for ( i = 0; i < m_Size; ++i )
     __thiscall IToolSystem::`vcall'{80,{flat}}(a1: this->m_ToolSystems.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x10200990
// Name: public: virtual void CToolFrameworkInternal::ClientLevelInitPostEntityAllTools(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFrameworkInternal::ClientLevelInitPostEntityAllTools(CToolFrameworkInternal *this)
{
  int m_Size; // ebx
  int i; // esi

  m_Size = this->m_ToolSystems.m_Size;
  for ( i = 0; i < m_Size; ++i )
     __thiscall IToolSystem::`vcall'{84,{flat}}(a1: this->m_ToolSystems.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x102009C0
// Name: public: virtual void CToolFrameworkInternal::ClientLevelShutdownPreEntityAllTools(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFrameworkInternal::ClientLevelShutdownPreEntityAllTools(CToolFrameworkInternal *this)
{
  int m_Size; // ebx
  int i; // esi

  m_Size = this->m_ToolSystems.m_Size;
  for ( i = 0; i < m_Size; ++i )
     __thiscall IToolSystem::`vcall'{88,{flat}}(a1: this->m_ToolSystems.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x102009F0
// Name: public: virtual void CToolFrameworkInternal::ClientLevelShutdownPostEntityAllTools(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFrameworkInternal::ClientLevelShutdownPostEntityAllTools(CToolFrameworkInternal *this)
{
  int m_Size; // ebx
  int i; // esi

  m_Size = this->m_ToolSystems.m_Size;
  for ( i = 0; i < m_Size; ++i )
     __thiscall IToolSystem::`vcall'{92,{flat}}(a1: this->m_ToolSystems.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x10200A20
// Name: public: virtual void CToolFrameworkInternal::ClientPreRenderAllTools(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFrameworkInternal::ClientPreRenderAllTools(CToolFrameworkInternal *this)
{
  int m_Size; // ebx
  int i; // esi

  m_Size = this->m_ToolSystems.m_Size;
  for ( i = 0; i < m_Size; ++i )
     __thiscall IToolSystem::`vcall'{96,{flat}}(a1: this->m_ToolSystems.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x10200A50
// Name: public: virtual bool CToolFrameworkInternal::IsThirdPersonCamera(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CToolFrameworkInternal::IsThirdPersonCamera(CToolFrameworkInternal *this)
{
  int m_nActiveToolIndex; // eax
  IToolSystem *v2; // ecx

  m_nActiveToolIndex = this->m_nActiveToolIndex;
  if ( m_nActiveToolIndex < 0 )
    return false;
  v2 = this->m_ToolSystems.m_Memory.m_pMemory[m_nActiveToolIndex];
  return v2->IsThirdPersonCamera(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10200A70
// Name: public: virtual bool CToolFrameworkInternal::IsToolRecording(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CToolFrameworkInternal::IsToolRecording(CToolFrameworkInternal *this)
{
  int m_nActiveToolIndex; // eax
  IToolSystem *v2; // ecx

  m_nActiveToolIndex = this->m_nActiveToolIndex;
  if ( m_nActiveToolIndex < 0 )
    return false;
  v2 = this->m_ToolSystems.m_Memory.m_pMemory[m_nActiveToolIndex];
  return v2->IsToolRecording(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10200A90
// Name: public: virtual void CToolFrameworkInternal::ClientPostRenderAllTools(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFrameworkInternal::ClientPostRenderAllTools(CToolFrameworkInternal *this)
{
  int m_Size; // ebx
  int i; // esi

  m_Size = this->m_ToolSystems.m_Size;
  for ( i = 0; i < m_Size; ++i )
     __thiscall IToolSystem::`vcall'{100,{flat}}(a1: this->m_ToolSystems.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x10200AC0
// Name: public: virtual void CToolFrameworkInternal::ServerLevelInitPreEntityAllTools(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFrameworkInternal::ServerLevelInitPreEntityAllTools(CToolFrameworkInternal *this)
{
  int m_Size; // ebx
  int i; // esi

  m_Size = this->m_ToolSystems.m_Size;
  for ( i = 0; i < m_Size; ++i )
     __thiscall IToolSystem::`vcall'{40,{flat}}(a1: this->m_ToolSystems.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x10200AF0
// Name: public: virtual void CToolFrameworkInternal::ServerLevelInitPostEntityAllTools(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFrameworkInternal::ServerLevelInitPostEntityAllTools(CToolFrameworkInternal *this)
{
  int m_Size; // ebx
  int i; // esi

  m_Size = this->m_ToolSystems.m_Size;
  for ( i = 0; i < m_Size; ++i )
     __thiscall IToolSystem::`vcall'{44,{flat}}(a1: this->m_ToolSystems.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x10200B20
// Name: public: virtual void CToolFrameworkInternal::ServerLevelShutdownPreEntityAllTools(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFrameworkInternal::ServerLevelShutdownPreEntityAllTools(CToolFrameworkInternal *this)
{
  int m_Size; // ebx
  int i; // esi

  m_Size = this->m_ToolSystems.m_Size;
  for ( i = 0; i < m_Size; ++i )
     __thiscall IToolSystem::`vcall'{48,{flat}}(a1: this->m_ToolSystems.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x10200B50
// Name: public: virtual void CToolFrameworkInternal::ServerLevelShutdownPostEntityAllTools(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFrameworkInternal::ServerLevelShutdownPostEntityAllTools(CToolFrameworkInternal *this)
{
  int m_Size; // ebx
  int i; // esi

  m_Size = this->m_ToolSystems.m_Size;
  for ( i = 0; i < m_Size; ++i )
     __thiscall IToolSystem::`vcall'{52,{flat}}(a1: this->m_ToolSystems.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x10200B80
// Name: public: virtual void CToolFrameworkInternal::ServerFrameUpdatePreEntityThinkAllTools(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFrameworkInternal::ServerFrameUpdatePreEntityThinkAllTools(CToolFrameworkInternal *this)
{
  int m_Size; // ebx
  int i; // esi

  m_Size = this->m_ToolSystems.m_Size;
  for ( i = 0; i < m_Size; ++i )
     __thiscall IToolSystem::`vcall'{56,{flat}}(a1: this->m_ToolSystems.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x10200BB0
// Name: public: virtual void CToolFrameworkInternal::ServerFrameUpdatePostEntityThinkAllTools(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFrameworkInternal::ServerFrameUpdatePostEntityThinkAllTools(CToolFrameworkInternal *this)
{
  int m_Size; // ebx
  int i; // esi

  m_Size = this->m_ToolSystems.m_Size;
  for ( i = 0; i < m_Size; ++i )
     __thiscall IToolSystem::`vcall'{60,{flat}}(a1: this->m_ToolSystems.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x10200BE0
// Name: public: virtual void CToolFrameworkInternal::ServerPreClientUpdateAllTools(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFrameworkInternal::ServerPreClientUpdateAllTools(CToolFrameworkInternal *this)
{
  int m_Size; // ebx
  int i; // esi

  m_Size = this->m_ToolSystems.m_Size;
  for ( i = 0; i < m_Size; ++i )
     __thiscall IToolSystem::`vcall'{64,{flat}}(a1: this->m_ToolSystems.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x10200C10
// Name: public: virtual void __near * CToolFrameworkInternal::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CToolFrameworkInternal::QueryInterface(CToolFrameworkInternal *this, const char *pInterfaceName)
{
  int v3; // esi
  IToolSystem *v4; // ecx
  void *result; // eax
  int toolCount; // [esp+Ch] [ebp-4h]

  v3 = 0;
  toolCount = this->m_ToolSystems.m_Size;
  if ( toolCount <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = this->m_ToolSystems.m_Memory.m_pMemory[v3];
    result = v4->QueryInterface(this: v4, a2: pInterfaceName);
    if ( result != nullptr )
      break;
    if ( ++v3 >= toolCount )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10200C50
// Name: public: virtual void CToolFrameworkInternal::ServerPreSetupVisibilityAllTools(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFrameworkInternal::ServerPreSetupVisibilityAllTools(CToolFrameworkInternal *this)
{
  int m_Size; // ebx
  int i; // esi

  m_Size = this->m_ToolSystems.m_Size;
  for ( i = 0; i < m_Size; ++i )
     __thiscall IToolSystem::`vcall'{68,{flat}}(a1: this->m_ToolSystems.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x10200C80
// Name: public: virtual void CToolFrameworkInternal::PostToolMessage(unsigned int,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFrameworkInternal::PostToolMessage(
        CToolFrameworkInternal *this,
        unsigned int hEntity,
        KeyValues *msg)
{
  int m_Size; // ebx
  int i; // esi
  IToolSystem *v6; // ecx

  m_Size = this->m_ToolSystems.m_Size;
  for ( i = 0; i < m_Size; ++i )
  {
    v6 = this->m_ToolSystems.m_Memory.m_pMemory[i];
    v6->PostToolMessage(this: v6, a2: hEntity, a3: msg);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10200CC0
// Name: public: virtual void CToolFrameworkInternal::AdjustEngineViewport(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFrameworkInternal::AdjustEngineViewport(
        CToolFrameworkInternal *this,
        int *x,
        int *y,
        int *width,
        int *height)
{
  int m_nActiveToolIndex; // eax
  IToolSystem *v6; // ecx

  m_nActiveToolIndex = this->m_nActiveToolIndex;
  if ( m_nActiveToolIndex >= 0 )
  {
    v6 = this->m_ToolSystems.m_Memory.m_pMemory[m_nActiveToolIndex];
    v6->AdjustEngineViewport(this: v6, a2: x, a3: y, a4: width, a5: height);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10200CE0
// Name: public: virtual bool CToolFrameworkInternal::SetupEngineView(class Vector __near &,class QAngle __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CToolFrameworkInternal::SetupEngineView(
        CToolFrameworkInternal *this,
        Vector *origin,
        QAngle *angles,
        float *fov)
{
  int m_nActiveToolIndex; // eax
  IToolSystem *v6; // ecx

  m_nActiveToolIndex = this->m_nActiveToolIndex;
  if ( m_nActiveToolIndex < 0 )
    return false;
  v6 = this->m_ToolSystems.m_Memory.m_pMemory[m_nActiveToolIndex];
  return v6->SetupEngineView(this: v6, a2: origin, a3: angles, a4: fov);
}

//------------------------------------------------------------------------------
// Address: 0x10200D00
// Name: public: virtual bool CToolFrameworkInternal::SetupAudioState(struct AudioState_t __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CToolFrameworkInternal::SetupAudioState(CToolFrameworkInternal *this, AudioState_t *audioState)
{
  int m_nActiveToolIndex; // eax
  IToolSystem *v4; // ecx

  m_nActiveToolIndex = this->m_nActiveToolIndex;
  if ( m_nActiveToolIndex < 0 )
    return false;
  v4 = this->m_ToolSystems.m_Memory.m_pMemory[m_nActiveToolIndex];
  return v4->SetupAudioState(this: v4, a2: audioState);
}

//------------------------------------------------------------------------------
// Address: 0x10200D20
// Name: public: virtual void CToolFrameworkInternal::VGui_PreRenderAllTools(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFrameworkInternal::VGui_PreRenderAllTools(CToolFrameworkInternal *this, int paintMode)
{
  int m_Size; // ebx
  int i; // esi

  m_Size = this->m_ToolSystems.m_Size;
  for ( i = 0; i < m_Size; ++i )
     __thiscall IToolSystem::`vcall'{168,{flat}}(a1: this->m_ToolSystems.m_Memory.m_pMemory[i], a2: paintMode);
}

//------------------------------------------------------------------------------
// Address: 0x10200D50
// Name: public: virtual void CToolFrameworkInternal::VGui_PostRenderAllTools(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFrameworkInternal::VGui_PostRenderAllTools(CToolFrameworkInternal *this, int paintMode)
{
  int m_Size; // ebx
  int i; // esi

  m_Size = this->m_ToolSystems.m_Size;
  for ( i = 0; i < m_Size; ++i )
     __thiscall IToolSystem::`vcall'{172,{flat}}(a1: this->m_ToolSystems.m_Memory.m_pMemory[i], a2: paintMode);
}

//------------------------------------------------------------------------------
// Address: 0x10200D80
// Name: public: virtual void CToolFrameworkInternal::VGui_PreSimulateAllTools(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFrameworkInternal::VGui_PreSimulateAllTools(CToolFrameworkInternal *this)
{
  int m_Size; // ebx
  int i; // esi

  m_Size = this->m_ToolSystems.m_Size;
  for ( i = 0; i < m_Size; ++i )
     __thiscall IToolSystem::`vcall'{176,{flat}}(a1: this->m_ToolSystems.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x10200DB0
// Name: public: virtual void CToolFrameworkInternal::VGui_PostSimulateAllTools(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFrameworkInternal::VGui_PostSimulateAllTools(CToolFrameworkInternal *this)
{
  int m_Size; // ebx
  int i; // esi

  m_Size = this->m_ToolSystems.m_Size;
  for ( i = 0; i < m_Size; ++i )
     __thiscall IToolSystem::`vcall'{180,{flat}}(a1: this->m_ToolSystems.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x10200DE0
// Name: public: virtual char const __near * CToolFrameworkInternal::GetToolName(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CToolFrameworkInternal::GetToolName(CToolFrameworkInternal *this, int index)
{
  IToolSystem *v2; // ecx

  if ( index >= 0
    && index < this->m_ToolSystems.m_Size
    && (v2 = this->m_ToolSystems.m_Memory.m_pMemory[index]) != nullptr )
  {
    return v2->GetToolName(this: v2);
  }
  else
  {
    return defaultValue;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10200E10
// Name: public: virtual void CToolFrameworkInternal::SwitchToTool(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFrameworkInternal::SwitchToTool(CToolFrameworkInternal *this, int index)
{
  int m_Size; // eax
  int m_nActiveToolIndex; // eax
  IToolSystem *v5; // ecx
  IToolSystem *v6; // ecx

  m_Size = this->m_ToolSystems.m_Size;
  if ( m_Size < 1 || index >= m_Size )
  {
    this->m_nActiveToolIndex = -1;
  }
  else
  {
    m_nActiveToolIndex = this->m_nActiveToolIndex;
    if ( index != m_nActiveToolIndex )
    {
      if ( m_nActiveToolIndex >= 0 )
      {
        v5 = this->m_ToolSystems.m_Memory.m_pMemory[m_nActiveToolIndex];
        v5->OnToolDeactivate(this: v5);
      }
      this->m_nActiveToolIndex = index;
      if ( index >= 0 )
      {
        v6 = this->m_ToolSystems.m_Memory.m_pMemory[index];
        v6->OnToolActivate(this: v6);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10200E70
// Name: public: virtual class IToolSystem __near * CToolFrameworkInternal::SwitchToTool(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IToolSystem *__thiscall CToolFrameworkInternal::SwitchToTool(CToolFrameworkInternal *this, const char *pToolName)
{
  int v3; // ebx
  int v4; // edi
  const char *v5; // eax

  v3 = this->GetToolCount(this);
  v4 = 0;
  if ( v3 <= 0 )
    return nullptr;
  while ( 1 )
  {
    v5 = this->GetToolName(this, a2: v4);
    if ( _V_stricmp(s1: pToolName, s2: v5) == 0 )
      break;
    if ( ++v4 >= v3 )
      return nullptr;
  }
  this->SwitchToTool_2(this, a2: v4);
  return this->m_ToolSystems.m_Memory.m_pMemory[v4];
}

//------------------------------------------------------------------------------
// Address: 0x10200EE0
// Name: public: virtual bool CToolFrameworkInternal::IsTopmostTool(class IToolSystem const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CToolFrameworkInternal::IsTopmostTool(CToolFrameworkInternal *this, const IToolSystem *sys)
{
  int m_nActiveToolIndex; // eax

  return this->m_ToolSystems.m_Size > 0
      && (m_nActiveToolIndex = this->m_nActiveToolIndex) >= 0
      && this->m_ToolSystems.m_Memory.m_pMemory[m_nActiveToolIndex] == sys;
}

//------------------------------------------------------------------------------
// Address: 0x10200F10
// Name: public: virtual class IToolSystem __near * CToolFrameworkInternal::GetTopmostTool(void)
// Source: json
//------------------------------------------------------------------------------
IToolSystem *__thiscall CToolFrameworkInternal::GetTopmostTool(CToolFrameworkInternal *this)
{
  int m_nActiveToolIndex; // eax

  m_nActiveToolIndex = this->m_nActiveToolIndex;
  if ( m_nActiveToolIndex < 0 )
    return nullptr;
  else
    return this->m_ToolSystems.m_Memory.m_pMemory[m_nActiveToolIndex];
}

//------------------------------------------------------------------------------
// Address: 0x10200F50
// Name: public: virtual void CToolFrameworkInternal::PostMessage(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFrameworkInternal::PostMessage(CToolFrameworkInternal *this, KeyValues *msg)
{
  int m_nActiveToolIndex; // eax
  IToolSystem *v3; // ecx

  m_nActiveToolIndex = this->m_nActiveToolIndex;
  if ( m_nActiveToolIndex >= 0 )
  {
    v3 = this->m_ToolSystems.m_Memory.m_pMemory[m_nActiveToolIndex];
    v3->PostToolMessage(this: v3, a2: 0, a3: msg);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10200F80
// Name: public: virtual bool CToolFrameworkInternal::GetSoundSpatialization(int,int,struct SpatializationInfo_t __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CToolFrameworkInternal::GetSoundSpatialization(
        CToolFrameworkInternal *this,
        int iUserData,
        int guid,
        SpatializationInfo_t *info)
{
  int m_nActiveToolIndex; // eax
  IToolSystem *v5; // ecx

  m_nActiveToolIndex = this->m_nActiveToolIndex;
  if ( m_nActiveToolIndex < 0 )
    return true;
  v5 = this->m_ToolSystems.m_Memory.m_pMemory[m_nActiveToolIndex];
  return v5->GetSoundSpatialization(this: v5, a2: iUserData, a3: guid, a4: info);
}

//------------------------------------------------------------------------------
// Address: 0x10200FB0
// Name: public: virtual void CToolFrameworkInternal::HostRunFrameBegin(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFrameworkInternal::HostRunFrameBegin(CToolFrameworkInternal *this)
{
  int m_Size; // ebx
  int i; // esi

  m_Size = this->m_ToolSystems.m_Size;
  for ( i = 0; i < m_Size; ++i )
     __thiscall IToolSystem::`vcall'{160,{flat}}(a1: this->m_ToolSystems.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x10200FE0
// Name: public: virtual void CToolFrameworkInternal::HostRunFrameEnd(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFrameworkInternal::HostRunFrameEnd(CToolFrameworkInternal *this)
{
  int m_Size; // ebx
  int i; // esi

  m_Size = this->m_ToolSystems.m_Size;
  for ( i = 0; i < m_Size; ++i )
     __thiscall IToolSystem::`vcall'{164,{flat}}(a1: this->m_ToolSystems.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x10201010
// Name: public: virtual void CToolFrameworkInternal::RenderFrameBegin(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFrameworkInternal::RenderFrameBegin(CToolFrameworkInternal *this)
{
  int m_Size; // ebx
  int i; // esi

  m_Size = this->m_ToolSystems.m_Size;
  for ( i = 0; i < m_Size; ++i )
     __thiscall IToolSystem::`vcall'{152,{flat}}(a1: this->m_ToolSystems.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x10201040
// Name: public: virtual void CToolFrameworkInternal::RenderFrameEnd(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFrameworkInternal::RenderFrameEnd(CToolFrameworkInternal *this)
{
  int m_Size; // ebx
  int i; // esi

  m_Size = this->m_ToolSystems.m_Size;
  for ( i = 0; i < m_Size; ++i )
     __thiscall IToolSystem::`vcall'{156,{flat}}(a1: this->m_ToolSystems.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x102010A0
// Name: public: virtual void CClientEngineTools::LevelInitPreEntityAllTools(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientEngineTools::LevelInitPreEntityAllTools(CClientEngineTools *this)
{
  int m_Size; // edi
  int i; // esi

  m_Size = g_ToolFrameworkInternal.m_ToolSystems.m_Size;
  for ( i = 0; i < m_Size; ++i )
     __thiscall IToolSystem::`vcall'{80,{flat}}(a1: g_ToolFrameworkInternal.m_ToolSystems.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x102010D0
// Name: public: virtual void CClientEngineTools::LevelInitPostEntityAllTools(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientEngineTools::LevelInitPostEntityAllTools(CClientEngineTools *this)
{
  int m_Size; // edi
  int i; // esi

  m_Size = g_ToolFrameworkInternal.m_ToolSystems.m_Size;
  for ( i = 0; i < m_Size; ++i )
     __thiscall IToolSystem::`vcall'{84,{flat}}(a1: g_ToolFrameworkInternal.m_ToolSystems.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x10201100
// Name: public: virtual void CClientEngineTools::LevelShutdownPreEntityAllTools(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientEngineTools::LevelShutdownPreEntityAllTools(CClientEngineTools *this)
{
  int m_Size; // edi
  int i; // esi

  m_Size = g_ToolFrameworkInternal.m_ToolSystems.m_Size;
  for ( i = 0; i < m_Size; ++i )
     __thiscall IToolSystem::`vcall'{88,{flat}}(a1: g_ToolFrameworkInternal.m_ToolSystems.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x10201130
// Name: public: virtual void CClientEngineTools::LevelShutdownPostEntityAllTools(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientEngineTools::LevelShutdownPostEntityAllTools(CClientEngineTools *this)
{
  int m_Size; // edi
  int i; // esi

  m_Size = g_ToolFrameworkInternal.m_ToolSystems.m_Size;
  for ( i = 0; i < m_Size; ++i )
     __thiscall IToolSystem::`vcall'{92,{flat}}(a1: g_ToolFrameworkInternal.m_ToolSystems.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x10201160
// Name: public: virtual void CClientEngineTools::PreRenderAllTools(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientEngineTools::PreRenderAllTools(CClientEngineTools *this)
{
  int m_Size; // edi
  int i; // esi

  m_Size = g_ToolFrameworkInternal.m_ToolSystems.m_Size;
  for ( i = 0; i < m_Size; ++i )
     __thiscall IToolSystem::`vcall'{96,{flat}}(a1: g_ToolFrameworkInternal.m_ToolSystems.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x10201190
// Name: public: virtual void CClientEngineTools::PostRenderAllTools(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientEngineTools::PostRenderAllTools(CClientEngineTools *this)
{
  int m_Size; // edi
  int i; // esi

  m_Size = g_ToolFrameworkInternal.m_ToolSystems.m_Size;
  for ( i = 0; i < m_Size; ++i )
     __thiscall IToolSystem::`vcall'{100,{flat}}(a1: g_ToolFrameworkInternal.m_ToolSystems.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x102011C0
// Name: public: virtual void CClientEngineTools::PostToolMessage(unsigned int,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientEngineTools::PostToolMessage(CClientEngineTools *this, unsigned int hEntity, KeyValues *msg)
{
  int m_Size; // edi
  int i; // esi

  m_Size = g_ToolFrameworkInternal.m_ToolSystems.m_Size;
  for ( i = 0; i < m_Size; ++i )
    g_ToolFrameworkInternal.m_ToolSystems.m_Memory.m_pMemory[i]->PostToolMessage(
      this: g_ToolFrameworkInternal.m_ToolSystems.m_Memory.m_pMemory[i],
      a2: hEntity,
      a3: msg);
}

//------------------------------------------------------------------------------
// Address: 0x10201200
// Name: public: virtual void CClientEngineTools::AdjustEngineViewport(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientEngineTools::AdjustEngineViewport(
        CClientEngineTools *this,
        int *x,
        int *y,
        int *width,
        int *height)
{
  if ( g_ToolFrameworkInternal.m_nActiveToolIndex >= 0 )
    g_ToolFrameworkInternal.m_ToolSystems.m_Memory.m_pMemory[g_ToolFrameworkInternal.m_nActiveToolIndex]->AdjustEngineViewport(
      this: g_ToolFrameworkInternal.m_ToolSystems.m_Memory.m_pMemory[g_ToolFrameworkInternal.m_nActiveToolIndex],
      a2: x,
      a3: y,
      a4: width,
      a5: height);
}

//------------------------------------------------------------------------------
// Address: 0x10201230
// Name: public: virtual bool CClientEngineTools::SetupEngineView(class Vector __near &,class QAngle __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CClientEngineTools::SetupEngineView(
        CClientEngineTools *this,
        Vector *origin,
        QAngle *angles,
        float *fov)
{
  return g_ToolFrameworkInternal.m_nActiveToolIndex >= 0
      && g_ToolFrameworkInternal.m_ToolSystems.m_Memory.m_pMemory[g_ToolFrameworkInternal.m_nActiveToolIndex]->SetupEngineView(
           this: g_ToolFrameworkInternal.m_ToolSystems.m_Memory.m_pMemory[g_ToolFrameworkInternal.m_nActiveToolIndex],
           a2: origin,
           a3: angles,
           a4: fov);
}

//------------------------------------------------------------------------------
// Address: 0x10201260
// Name: public: virtual bool CClientEngineTools::SetupAudioState(struct AudioState_t __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CClientEngineTools::SetupAudioState(CClientEngineTools *this, AudioState_t *audioState)
{
  return g_ToolFrameworkInternal.m_nActiveToolIndex >= 0
      && g_ToolFrameworkInternal.m_ToolSystems.m_Memory.m_pMemory[g_ToolFrameworkInternal.m_nActiveToolIndex]->SetupAudioState(
           this: g_ToolFrameworkInternal.m_ToolSystems.m_Memory.m_pMemory[g_ToolFrameworkInternal.m_nActiveToolIndex],
           a2: audioState);
}

//------------------------------------------------------------------------------
// Address: 0x10201290
// Name: public: virtual void CClientEngineTools::VGui_PreRenderAllTools(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientEngineTools::VGui_PreRenderAllTools(CClientEngineTools *this, int paintMode)
{
  int m_Size; // edi
  int i; // esi

  m_Size = g_ToolFrameworkInternal.m_ToolSystems.m_Size;
  for ( i = 0; i < m_Size; ++i )
     __thiscall IToolSystem::`vcall'{168,{flat}}(
      a1: g_ToolFrameworkInternal.m_ToolSystems.m_Memory.m_pMemory[i],
      a2: paintMode);
}

//------------------------------------------------------------------------------
// Address: 0x102012C0
// Name: public: virtual void CClientEngineTools::VGui_PostRenderAllTools(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientEngineTools::VGui_PostRenderAllTools(CClientEngineTools *this, int paintMode)
{
  int m_Size; // edi
  int i; // esi

  m_Size = g_ToolFrameworkInternal.m_ToolSystems.m_Size;
  for ( i = 0; i < m_Size; ++i )
     __thiscall IToolSystem::`vcall'{172,{flat}}(
      a1: g_ToolFrameworkInternal.m_ToolSystems.m_Memory.m_pMemory[i],
      a2: paintMode);
}

//------------------------------------------------------------------------------
// Address: 0x102012F0
// Name: public: virtual bool CClientEngineTools::IsThirdPersonCamera(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CClientEngineTools::IsThirdPersonCamera(CClientEngineTools *this)
{
  return g_ToolFrameworkInternal.m_nActiveToolIndex >= 0
      && g_ToolFrameworkInternal.m_ToolSystems.m_Memory.m_pMemory[g_ToolFrameworkInternal.m_nActiveToolIndex]->IsThirdPersonCamera(this: g_ToolFrameworkInternal.m_ToolSystems.m_Memory.m_pMemory[g_ToolFrameworkInternal.m_nActiveToolIndex]);
}

//------------------------------------------------------------------------------
// Address: 0x10201310
// Name: public: virtual void CServerEngineTools::LevelInitPreEntityAllTools(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerEngineTools::LevelInitPreEntityAllTools(CServerEngineTools *this)
{
  int m_Size; // edi
  int i; // esi

  m_Size = g_ToolFrameworkInternal.m_ToolSystems.m_Size;
  for ( i = 0; i < m_Size; ++i )
     __thiscall IToolSystem::`vcall'{40,{flat}}(a1: g_ToolFrameworkInternal.m_ToolSystems.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x10201340
// Name: public: virtual void CServerEngineTools::LevelInitPostEntityAllTools(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerEngineTools::LevelInitPostEntityAllTools(CServerEngineTools *this)
{
  int m_Size; // edi
  int i; // esi

  m_Size = g_ToolFrameworkInternal.m_ToolSystems.m_Size;
  for ( i = 0; i < m_Size; ++i )
     __thiscall IToolSystem::`vcall'{44,{flat}}(a1: g_ToolFrameworkInternal.m_ToolSystems.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x10201370
// Name: public: virtual void CServerEngineTools::LevelShutdownPreEntityAllTools(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerEngineTools::LevelShutdownPreEntityAllTools(CServerEngineTools *this)
{
  int m_Size; // edi
  int i; // esi

  m_Size = g_ToolFrameworkInternal.m_ToolSystems.m_Size;
  for ( i = 0; i < m_Size; ++i )
     __thiscall IToolSystem::`vcall'{48,{flat}}(a1: g_ToolFrameworkInternal.m_ToolSystems.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x102013A0
// Name: public: virtual void CServerEngineTools::LevelShutdownPostEntityAllTools(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerEngineTools::LevelShutdownPostEntityAllTools(CServerEngineTools *this)
{
  int m_Size; // edi
  int i; // esi

  m_Size = g_ToolFrameworkInternal.m_ToolSystems.m_Size;
  for ( i = 0; i < m_Size; ++i )
     __thiscall IToolSystem::`vcall'{52,{flat}}(a1: g_ToolFrameworkInternal.m_ToolSystems.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x102013D0
// Name: public: virtual void CServerEngineTools::FrameUpdatePreEntityThinkAllTools(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerEngineTools::FrameUpdatePreEntityThinkAllTools(CServerEngineTools *this)
{
  int m_Size; // edi
  int i; // esi

  m_Size = g_ToolFrameworkInternal.m_ToolSystems.m_Size;
  for ( i = 0; i < m_Size; ++i )
     __thiscall IToolSystem::`vcall'{56,{flat}}(a1: g_ToolFrameworkInternal.m_ToolSystems.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x10201400
// Name: public: virtual void CServerEngineTools::FrameUpdatePostEntityThinkAllTools(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerEngineTools::FrameUpdatePostEntityThinkAllTools(CServerEngineTools *this)
{
  int m_Size; // edi
  int i; // esi

  m_Size = g_ToolFrameworkInternal.m_ToolSystems.m_Size;
  for ( i = 0; i < m_Size; ++i )
     __thiscall IToolSystem::`vcall'{60,{flat}}(a1: g_ToolFrameworkInternal.m_ToolSystems.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x10201430
// Name: public: virtual void CServerEngineTools::PreClientUpdateAllTools(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerEngineTools::PreClientUpdateAllTools(CServerEngineTools *this)
{
  int m_Size; // edi
  int i; // esi

  m_Size = g_ToolFrameworkInternal.m_ToolSystems.m_Size;
  for ( i = 0; i < m_Size; ++i )
     __thiscall IToolSystem::`vcall'{64,{flat}}(a1: g_ToolFrameworkInternal.m_ToolSystems.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x10201460
// Name: public: virtual char const __near * CServerEngineTools::GetEntityData(char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CServerEngineTools::GetEntityData(CServerEngineTools *this, const char *pActualEntityData)
{
  if ( g_ToolFrameworkInternal.m_nActiveToolIndex < 0 )
    return pActualEntityData;
  else
    return g_ToolFrameworkInternal.m_ToolSystems.m_Memory.m_pMemory[g_ToolFrameworkInternal.m_nActiveToolIndex]->GetEntityData(
             this: g_ToolFrameworkInternal.m_ToolSystems.m_Memory.m_pMemory[g_ToolFrameworkInternal.m_nActiveToolIndex],
             a2: pActualEntityData);
}

//------------------------------------------------------------------------------
// Address: 0x10201490
// Name: public: virtual void __near * CServerEngineTools::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CServerEngineTools::QueryInterface(CServerEngineTools *this, const char *pInterfaceName)
{
  int v2; // esi
  int m_Size; // ebx
  void *result; // eax

  v2 = 0;
  m_Size = g_ToolFrameworkInternal.m_ToolSystems.m_Size;
  if ( g_ToolFrameworkInternal.m_ToolSystems.m_Size <= 0 )
    return nullptr;
  while ( 1 )
  {
    result = g_ToolFrameworkInternal.m_ToolSystems.m_Memory.m_pMemory[v2]->QueryInterface(
               this: g_ToolFrameworkInternal.m_ToolSystems.m_Memory.m_pMemory[v2],
               a2: pInterfaceName);
    if ( result != nullptr )
      break;
    if ( ++v2 >= m_Size )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102014D0
// Name: public: virtual void CServerEngineTools::PreSetupVisibilityAllTools(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerEngineTools::PreSetupVisibilityAllTools(CServerEngineTools *this)
{
  int m_Size; // edi
  int i; // esi

  m_Size = g_ToolFrameworkInternal.m_ToolSystems.m_Size;
  for ( i = 0; i < m_Size; ++i )
     __thiscall IToolSystem::`vcall'{68,{flat}}(a1: g_ToolFrameworkInternal.m_ToolSystems.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x10201500
// Name: public: int CToolAutoCompleteFileList::AutoCompletionFunc(char const __near *,char (__near * const)[64])
// Source: json
//------------------------------------------------------------------------------
int __thiscall CToolAutoCompleteFileList::AutoCompletionFunc(
        CToolAutoCompleteFileList *this,
        char *partial,
        char (*commands)[64])
{
  char *v3; // ebx
  const char *m_pszCommandName; // esi
  const char *m_pszSubDir; // eax
  int m_Size; // ebx
  CUtlSymbol *m_pMemory; // edi
  const char *First; // esi
  int v10; // eax
  int v11; // esi
  CUtlSymbol *v12; // eax
  const char *Next; // eax
  int v14; // edi
  char *v15; // esi
  const char *v16; // eax
  const char *v17; // eax
  const char *v18; // ecx
  char sz[96]; // [esp+Ch] [ebp-118h] BYREF
  char searchpath[96]; // [esp+6Ch] [ebp-B8h] BYREF
  CUtlSymbolTable entries; // [esp+CCh] [ebp-58h] BYREF
  char *v23; // [esp+104h] [ebp-20h]
  const char *cmdname; // [esp+108h] [ebp-1Ch]
  CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > symbols; // [esp+10Ch] [ebp-18h] BYREF
  char *substring; // [esp+120h] [ebp-4h]

  v3 = partial;
  m_pszCommandName = this->m_pszCommandName;
  cmdname = m_pszCommandName;
  substring = partial;
  if ( _V_strstr(s1: partial, search: m_pszCommandName) != nullptr )
    substring = &v3[strlen(m_pszCommandName) + 1];
  m_pszSubDir = this->m_pszSubDir;
  m_Size = 0;
  if ( m_pszSubDir != nullptr && *m_pszSubDir != 0 && V_strcasecmp(s1: m_pszSubDir, s2: "NULL") != 0 )
    V_snprintf(pDest: searchpath, maxLen: 96, pFormat: "%s/*.%s", this->m_pszSubDir, this->m_pszExtension);
  else
    V_snprintf(pDest: searchpath, maxLen: 96, pFormat: "*.%s", this->m_pszExtension);
  CUtlSymbolTable::CUtlSymbolTable(this: &entries, growSize: 0, initSize: 0, caseInsensitive: true);
  m_pMemory = nullptr;
  memset(&symbols, 0, sizeof(symbols));
  First = Sys_FindFirstEx(pWildcard: searchpath, pPathID: "EXECUTABLE_PATH", basename: nullptr, namelength: 0);
  if ( First != nullptr )
  {
    do
    {
      memset(sz, 0, sizeof(sz));
      V_StripExtension(in: First, out: sz, outSize: 96);
      if ( *substring == 0 || (v23 = substring + 1, V_strncasecmp(s1: First, s2: substring, n: strlen(substring)) == 0) )
      {
        CUtlSymbolTable::AddString(this: &entries, result: (CUtlSymbol *)&partial, pString: First);
        v10 = 0;
        if ( m_Size <= 0 )
          goto LABEL_16;
        while ( m_pMemory[v10].m_Id != (_WORD)partial )
        {
          if ( ++v10 >= m_Size )
            goto LABEL_16;
        }
        if ( v10 == -1 )
        {
LABEL_16:
          v11 = m_Size;
          if ( m_Size + 1 > symbols.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<wchar_t,int>::Grow(
              this: (CUtlMemory<wchar_t,int> *)&symbols,
              num: m_Size - symbols.m_Memory.m_nAllocationCount + 1);
            m_Size = symbols.m_Size;
            m_pMemory = symbols.m_Memory.m_pMemory;
          }
          symbols.m_Size = ++m_Size;
          symbols.m_pElements = m_pMemory;
          if ( m_Size - v11 - 1 > 0 )
            _V_memmove(dest: &m_pMemory[v11 + 1], src: &m_pMemory[v11], count: 2 * (m_Size - v11 - 1));
          v12 = &m_pMemory[v11];
          if ( v12 != nullptr )
            v12->m_Id = (unsigned __int16)partial;
        }
      }
      Next = Sys_FindNext(basename: nullptr, namelength: 0);
      First = Next;
    }
    while ( m_Size < 64 && Next != nullptr );
  }
  Sys_FindClose();
  v14 = 0;
  if ( m_Size > 0 )
  {
    v15 = (char *)commands;
    partial = nullptr;
    do
    {
      v16 = CUtlSymbolTable::String(this: &entries, id: symbols.m_Memory.m_pMemory[v14]);
      V_snprintf(pDest: v15, maxLen: 64, pFormat: "%s %s", cmdname, v16);
      v17 = &partial[strlen(v15)];
      ++v14;
      v18 = partial + 64;
      v15 += 64;
      (*commands)[(_DWORD)v17 - 4] = 0;
      partial = (char *)v18;
    }
    while ( v14 < m_Size );
  }
  if ( symbols.m_Memory.m_nGrowSize >= 0 && symbols.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: symbols.m_Memory.m_pMemory);
  CUtlSymbolTable::~CUtlSymbolTable(this: &entries);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10201760
// Name: g_ToolLoad_CompletionFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl g_ToolLoad_CompletionFunc(char *partial, char (*commands)[64])
{
  if ( (_S1_22 & 1) == 0 )
  {
    _S1_22 |= 1u;
    ToolLoad_Complete.m_pszCommandName = "toolload";
    ToolLoad_Complete.m_pszSubDir = "tools";
    ToolLoad_Complete.m_pszExtension = "dll";
  }
  return CToolAutoCompleteFileList::AutoCompletionFunc(this: &ToolLoad_Complete, partial, commands);
}

//------------------------------------------------------------------------------
// Address: 0x102017B0
// Name: public: void CToolFrameworkInternal::GetModules(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFrameworkInternal::GetModules(
        CToolFrameworkInternal *this,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *list)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlString *m_pMemory; // ecx
  int v7; // eax
  CUtlString *v8; // ecx
  CUtlString str; // [esp+4h] [ebp-14h] BYREF
  int i; // [esp+14h] [ebp-4h]
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *lista; // [esp+20h] [ebp+8h]

  i = 0;
  if ( this->m_Modules.m_Size > 0 )
  {
    lista = nullptr;
    do
    {
      CUtlString::CUtlString(this: &str);
      CUtlString::operator=(
        this: &str,
        src: (const CUtlString *)((char *)lista + (unsigned int)this->m_Modules.m_Memory.m_pMemory));
      m_Size = list->m_Size;
      m_nAllocationCount = list->m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CPortalRect,int>::Grow(
          this: (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)list,
          num: m_Size - m_nAllocationCount + 1);
      ++list->m_Size;
      m_pMemory = list->m_Memory.m_pMemory;
      v7 = list->m_Size - m_Size - 1;
      list->m_pElements = list->m_Memory.m_pMemory;
      if ( v7 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 16 * v7);
      v8 = &list->m_Memory.m_pMemory[m_Size];
      if ( v8 != nullptr )
        CUtlString::CUtlString(this: v8, string: &str);
      str.m_Storage.m_nActualLength = 0;
      if ( str.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( str.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: str.m_Storage.m_Memory.m_pMemory);
          str.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        str.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      lista += 3;
      ++i;
    }
    while ( i < this->m_Modules.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10201A20
// Name: private: void CToolFrameworkInternal::ShutdownTools(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFrameworkInternal::ShutdownTools(CToolFrameworkInternal *this)
{
  int i; // edi
  IToolSystem *v3; // ecx
  int v4; // ebx
  int v5; // edi

  this->SwitchToTool_2(this, a2: -1);
  for ( i = this->m_ToolSystems.m_Size - 1; i >= 0; --i )
  {
    v3 = this->m_ToolSystems.m_Memory.m_pMemory[i];
    v3->Shutdown(this: v3);
  }
  this->m_ToolSystems.m_Size = 0;
  CToolFrameworkInternal::ShutdownToolDictionaries(this);
  v4 = this->m_Modules.m_Size - 1;
  if ( v4 >= 0 )
  {
    v5 = v4;
    do
    {
      Sys_UnloadModule(pModule: this->m_Modules.m_Memory.m_pMemory[v5].m_pModule);
      this->m_Modules.m_Memory.m_pMemory[v5--].m_pModule = nullptr;
      --v4;
    }
    while ( v4 >= 0 );
  }
  CUtlVector<ToolModule_t,CUtlMemory<ToolModule_t,int>>::RemoveAll(this: &this->m_Modules);
}

//------------------------------------------------------------------------------
// Address: 0x10201AA0
// Name: private: struct ToolModule_t __near * CToolFrameworkInternal::LoadToolsFromLibrary(char const __near *)
// Source: json
//------------------------------------------------------------------------------
ToolModule_t *__thiscall CToolFrameworkInternal::LoadToolsFromLibrary(
        CToolFrameworkInternal *this,
        const char *dllname)
{
  struct CSysModule *Module; // eax
  struct CSysModule *v3; // edi
  void *(__cdecl *v5)(const char *, int *); // eax
  int v6; // ebx
  ToolModule_t *v7; // esi
  IToolSystem *v8; // edi
  const char *v9; // eax
  const char *v10; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  IToolSystem **m_pMemory; // ecx
  int v14; // eax
  IToolSystem **v15; // edi
  int v16; // edi
  int v17; // eax
  IToolSystem **v18; // ecx
  int v19; // eax
  IToolSystem **v20; // edi
  void *(__cdecl *factory)(const char *, int *); // [esp+8h] [ebp-18h]
  int toolCount; // [esp+Ch] [ebp-14h]
  IToolSystem *tool; // [esp+10h] [ebp-10h]
  int i; // [esp+18h] [ebp-8h]
  ToolModule_t *tm; // [esp+1Ch] [ebp-4h]
  char first_3; // [esp+2Bh] [ebp+Bh]

  Module = Sys_LoadModule(pModuleName: dllname);
  v3 = Module;
  if ( Module != nullptr )
  {
    v5 = Sys_GetFactory(pModule: Module);
    factory = v5;
    if ( v5 != nullptr )
    {
      v6 = (int)v5(a1: "VTOOLDICTIONARY003", a2: nullptr);
      if ( v6 != 0 )
      {
        if ( (**(unsigned __int8 (__thiscall ***)(int, void *(__cdecl *)(const char *, int *)))v6)(
               a1: v6,
               a2: g_AppSystemFactory) != 0 )
        {
          if ( (*(int (__thiscall **)(int))(*(_DWORD *)v6 + 12))(a1: v6) == 1 )
          {
            (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 32))(a1: v6);
            v7 = &this->m_Modules.m_Memory.m_pMemory[CUtlVector<ToolModule_t,CUtlMemory<ToolModule_t,int>>::InsertBefore(
                                                       this: &this->m_Modules,
                                                       elem: this->m_Modules.m_Size)];
            tm = v7;
            v7->m_pDictionary = (IToolDictionary *)v6;
            v7->m_pModule = v3;
            CUtlString::operator=(this: &v7->m_sDllName, src: dllname);
            first_3 = 1;
            toolCount = (*(int (__thiscall **)(int))(*(_DWORD *)v6 + 36))(a1: v6);
            for ( i = 0; i < toolCount; ++i )
            {
              v8 = (IToolSystem *)(*(int (__thiscall **)(int, int))(*(_DWORD *)v6 + 40))(a1: v6, a2: i);
              tool = v8;
              if ( v8 != nullptr )
              {
                v9 = (const char *)v8->GetToolName(this: v8);
                _Msg(a1: "Loaded tool '%s'\n", v9);
                if ( first_3 != 0 )
                {
                  first_3 = 0;
                  v10 = (const char *)v8->GetToolName(this: v8);
                  CUtlString::operator=(this: &v7->m_sFirstTool, src: v10);
                }
                m_Size = this->m_ToolSystems.m_Size;
                m_nAllocationCount = this->m_ToolSystems.m_Memory.m_nAllocationCount;
                if ( m_Size + 1 > m_nAllocationCount )
                  CUtlMemory<INetMessage *,int>::Grow(
                    this: (CUtlMemory<S3RGBA,int> *)&this->m_ToolSystems,
                    num: m_Size - m_nAllocationCount + 1);
                ++this->m_ToolSystems.m_Size;
                m_pMemory = this->m_ToolSystems.m_Memory.m_pMemory;
                v14 = this->m_ToolSystems.m_Size - m_Size - 1;
                this->m_ToolSystems.m_pElements = m_pMemory;
                if ( v14 > 0 )
                  _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v14);
                v15 = &this->m_ToolSystems.m_Memory.m_pMemory[m_Size];
                if ( v15 != nullptr )
                  *v15 = tool;
                v7 = tm;
                v16 = tm->m_Systems.m_Size;
                v17 = tm->m_Systems.m_Memory.m_nAllocationCount;
                if ( v16 + 1 > v17 )
                  CUtlMemory<INetMessage *,int>::Grow(
                    this: (CUtlMemory<S3RGBA,int> *)&tm->m_Systems,
                    num: v16 - v17 + 1);
                ++tm->m_Systems.m_Size;
                v18 = tm->m_Systems.m_Memory.m_pMemory;
                v19 = tm->m_Systems.m_Size - v16 - 1;
                tm->m_Systems.m_pElements = v18;
                if ( v19 > 0 )
                  _V_memmove(dest: &v18[v16 + 1], src: &v18[v16], count: 4 * v19);
                v20 = &tm->m_Systems.m_Memory.m_pMemory[v16];
                if ( v20 != nullptr )
                  *v20 = tool;
              }
            }
            g_pHammer = (IHammer *)factory(a1: "Hammer001", a2: nullptr);
            return v7;
          }
          else
          {
            Sys_UnloadModule(pModule: v3);
            _Warning(
              a1: "CToolFrameworkInternal::LoadToolsFromLibrary:  Dll '%s' initialization phase failed.\n",
              dllname);
            return nullptr;
          }
        }
        else
        {
          Sys_UnloadModule(pModule: v3);
          _Warning(a1: "CToolFrameworkInternal::LoadToolsFromLibrary:  Dll '%s' connection phase failed.\n", dllname);
          return nullptr;
        }
      }
      else
      {
        Sys_UnloadModule(pModule: v3);
        _Warning(
          a1: "CToolFrameworkInternal::LoadToolsFromLibrary:  Dll '%s' doesn't support '%s'\n",
          dllname,
          "VTOOLDICTIONARY003");
        return nullptr;
      }
    }
    else
    {
      Sys_UnloadModule(pModule: v3);
      _Warning(a1: "CToolFrameworkInternal::LoadToolsFromLibrary:  Dll '%s' has no factory\n", dllname);
      return nullptr;
    }
  }
  else
  {
    _Warning(a1: "CToolFrameworkInternal::LoadToolsFromLibrary:  Unable to load '%s'\n", dllname);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10201D20
// Name: public: virtual bool CToolFrameworkInternal::LoadFilmmaker(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolFrameworkInternal::LoadFilmmaker(CToolFrameworkInternal *this)
{
  const char *ModDirectory; // eax

  ModDirectory = COM_GetModDirectory();
  if ( _V_stricmp(s1: ModDirectory, s2: "tf") != 0 )
    return 0;
  CToolFrameworkInternal::LoadToolsFromLibrary(this, dllname: "tools/ifm.dll");
  this->ClientInit(this, a2: g_ClientFactory);
  this->ServerInit(this, a2: g_ServerFactory);
  this->PostInit(this);
  g_bReplayLoadedTools = true;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10201D80
// Name: public: virtual void CToolFrameworkInternal::UnloadFilmmaker(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFrameworkInternal::UnloadFilmmaker(CToolFrameworkInternal *this)
{
  const char *ModDirectory; // eax

  ModDirectory = COM_GetModDirectory();
  if ( _V_stricmp(s1: ModDirectory, s2: "tf") == 0 )
  {
    this->ServerShutdown(this);
    this->ClientShutdown(this);
    CToolFrameworkInternal::ShutdownTools(this);
    g_bReplayLoadedTools = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10201DC0
// Name: private: void CToolFrameworkInternal::LoadToolsFromCommandLine(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFrameworkInternal::LoadToolsFromCommandLine(
        CToolFrameworkInternal *this,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *list)
{
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *v2; // eax
  const char *v3; // eax
  char *m_szBuf; // esi
  struct CSysModule *Module; // eax
  struct CSysModule *v6; // ebx
  void *(__cdecl *Factory)(const char *, int *); // eax
  int v8; // edi
  CToolFrameworkInternal *v9; // edi
  int v10; // eax
  ToolModule_t *m_pMemory; // edx
  int v12; // edi
  CUtlString *p_m_sDllName; // ecx
  int (__thiscall *v14)(int); // edx
  int v15; // eax
  int v16; // ecx
  int (__thiscall ***v17)(_DWORD); // ebx
  const char *v18; // eax
  int (__thiscall *v19)(_DWORD); // edx
  const char *v20; // eax
  _DWORD *v21; // esi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  int v24; // ecx
  int v25; // eax
  _DWORD *v26; // edi
  CUtlString *v27; // esi
  int v28; // edi
  int m_nActualLength; // eax
  int m_nGrowSize; // ecx
  int v31; // eax
  _DWORD *v32; // edi
  CFmtStrN<256> v33; // [esp+0h] [ebp-130h] BYREF
  void *(__cdecl *v34)(const char *, int *); // [esp+10Ch] [ebp-24h]
  int v35; // [esp+110h] [ebp-20h]
  CToolFrameworkInternal *v36; // [esp+114h] [ebp-1Ch]
  int j; // [esp+118h] [ebp-18h]
  int i; // [esp+11Ch] [ebp-14h]
  CUtlString *v39; // [esp+120h] [ebp-10h]
  unsigned int v40; // [esp+124h] [ebp-Ch]
  int v41; // [esp+128h] [ebp-8h]
  char v42; // [esp+12Fh] [ebp-1h]

  v2 = list;
  this->m_bInToolMode = true;
  v36 = this;
  i = 0;
  if ( list->m_Size > 0 )
  {
    v40 = 0;
    do
    {
      v3 = CUtlString::operator char const *(this: &v2->m_Memory.m_pMemory[v40 / 0x10]);
      m_szBuf = CFmtStrN<256>::CFmtStrN<256>(this: &v33, pszFormat: "tools/%s.dll", v3)->m_szBuf;
      Module = Sys_LoadModule(pModuleName: m_szBuf);
      v6 = Module;
      if ( Module != nullptr )
      {
        Factory = Sys_GetFactory(pModule: Module);
        v34 = Factory;
        if ( Factory != nullptr )
        {
          v8 = (int)Factory(a1: "VTOOLDICTIONARY003", a2: nullptr);
          v41 = v8;
          if ( v8 != 0 )
          {
            if ( (**(unsigned __int8 (__thiscall ***)(int, void *(__cdecl *)(const char *, int *)))v8)(
                   a1: v8,
                   a2: g_AppSystemFactory) != 0 )
            {
              if ( (*(int (__thiscall **)(int))(*(_DWORD *)v8 + 12))(a1: v8) == 1 )
              {
                (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 32))(a1: v8);
                v9 = v36;
                v10 = CUtlVector<ToolModule_t,CUtlMemory<ToolModule_t,int>>::InsertBefore(
                        this: &v36->m_Modules,
                        elem: v36->m_Modules.m_Size);
                m_pMemory = v9->m_Modules.m_Memory.m_pMemory;
                v12 = v41;
                p_m_sDllName = &m_pMemory[v10].m_sDllName;
                v39 = p_m_sDllName;
                p_m_sDllName[2].m_Storage.m_Memory.m_nAllocationCount = v41;
                p_m_sDllName[2].m_Storage.m_Memory.m_pMemory = (unsigned __int8 *)v6;
                CUtlString::operator=(this: p_m_sDllName, src: m_szBuf);
                v14 = *(int (__thiscall **)(int))(*(_DWORD *)v12 + 36);
                v42 = 1;
                v15 = v14(a1: v12);
                v16 = 0;
                v35 = v15;
                for ( j = 0; v16 < v35; j = v16 )
                {
                  v17 = (int (__thiscall ***)(_DWORD))(*(int (__thiscall **)(int, int))(*(_DWORD *)v12 + 40))(
                                                        a1: v12,
                                                        a2: v16);
                  if ( v17 != nullptr )
                  {
                    v18 = (const char *)(**v17)(a1: v17);
                    _Msg(a1: "Loaded tool '%s'\n", v18);
                    if ( v42 != 0 )
                    {
                      v19 = **v17;
                      v42 = 0;
                      v20 = (const char *)v19(a1: v17);
                      CUtlString::operator=(this: v39 + 1, src: v20);
                    }
                    v21 = &v36->__vftable;
                    m_Size = v36->m_ToolSystems.m_Size;
                    m_nAllocationCount = v36->m_ToolSystems.m_Memory.m_nAllocationCount;
                    if ( m_Size + 1 > m_nAllocationCount )
                      CUtlMemory<INetMessage *,int>::Grow(
                        this: (CUtlMemory<S3RGBA,int> *)&v36->m_ToolSystems,
                        num: m_Size - m_nAllocationCount + 1);
                    ++v21[4];
                    v24 = v21[1];
                    v25 = v21[4] - m_Size - 1;
                    v21[5] = v24;
                    if ( v25 > 0 )
                      _V_memmove(
                        dest: (void *)(v24 + 4 * m_Size + 4),
                        src: (const void *)(v24 + 4 * m_Size),
                        count: 4 * v25);
                    v26 = (_DWORD *)(v21[1] + 4 * m_Size);
                    if ( v26 != nullptr )
                      *v26 = v17;
                    v27 = v39;
                    v28 = v39[3].m_Storage.m_Memory.m_nAllocationCount;
                    m_nActualLength = v39[2].m_Storage.m_nActualLength;
                    if ( v28 + 1 > m_nActualLength )
                      CUtlMemory<INetMessage *,int>::Grow(
                        this: (CUtlMemory<S3RGBA,int> *)&v39[2].m_Storage.m_Memory.m_nGrowSize,
                        num: v28 - m_nActualLength + 1);
                    ++v27[3].m_Storage.m_Memory.m_nAllocationCount;
                    m_nGrowSize = v27[2].m_Storage.m_Memory.m_nGrowSize;
                    v31 = v27[3].m_Storage.m_Memory.m_nAllocationCount - v28 - 1;
                    v27[3].m_Storage.m_Memory.m_nGrowSize = m_nGrowSize;
                    if ( v31 > 0 )
                      _V_memmove(
                        dest: (void *)(m_nGrowSize + 4 * v28 + 4),
                        src: (const void *)(m_nGrowSize + 4 * v28),
                        count: 4 * v31);
                    v32 = (_DWORD *)(v27[2].m_Storage.m_Memory.m_nGrowSize + 4 * v28);
                    if ( v32 != nullptr )
                      *v32 = v17;
                    v12 = v41;
                  }
                  v16 = j + 1;
                }
                g_pHammer = (IHammer *)v34(a1: "Hammer001", a2: nullptr);
              }
              else
              {
                Sys_UnloadModule(pModule: v6);
                _Warning(
                  a1: "CToolFrameworkInternal::LoadToolsFromLibrary:  Dll '%s' initialization phase failed.\n",
                  m_szBuf);
              }
            }
            else
            {
              Sys_UnloadModule(pModule: v6);
              _Warning(
                a1: "CToolFrameworkInternal::LoadToolsFromLibrary:  Dll '%s' connection phase failed.\n",
                m_szBuf);
            }
          }
          else
          {
            Sys_UnloadModule(pModule: v6);
            _Warning(
              a1: "CToolFrameworkInternal::LoadToolsFromLibrary:  Dll '%s' doesn't support '%s'\n",
              m_szBuf,
              "VTOOLDICTIONARY003");
          }
        }
        else
        {
          Sys_UnloadModule(pModule: v6);
          _Warning(a1: "CToolFrameworkInternal::LoadToolsFromLibrary:  Dll '%s' has no factory\n", m_szBuf);
        }
      }
      else
      {
        _Warning(a1: "CToolFrameworkInternal::LoadToolsFromLibrary:  Unable to load '%s'\n", m_szBuf);
      }
      v2 = list;
      v40 += 16;
      ++i;
    }
    while ( i < list->m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10202070
// Name: private: void CToolFrameworkInternal::LoadToolsFromEngineToolsManifest(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFrameworkInternal::LoadToolsFromEngineToolsManifest(CToolFrameworkInternal *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // edi
  IBaseFileSystem *v4; // eax
  KeyValues *i; // esi
  const char *Name; // eax
  const char *String; // eax
  char szToolConfigFile[28]; // [esp+8h] [ebp-1Ch] BYREF

  this->m_bInToolMode = true;
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "enginetools");
  else
    v3 = nullptr;
  if ( g_pFileSystem->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: "enginetools.txt", a3: "EXECUTABLE_PATH") )
    V_strncpy(pDest: szToolConfigFile, pSrc: "enginetools.txt", maxLen: 25);
  else
    V_strncpy(pDest: szToolConfigFile, pSrc: "sdkenginetools.txt", maxLen: 25);
  if ( v3 != nullptr )
  {
    v4 = g_pFileSystem != nullptr ? &g_pFileSystem->IBaseFileSystem : nullptr;
    if ( KeyValues::LoadFromFile(
           this: v3,
           filesystem: v4,
           resourceName: szToolConfigFile,
           pathID: "EXECUTABLE_PATH",
           pfnEvaluateSymbolProc: nullptr) )
    {
      for ( i = KeyValues::GetFirstSubKey(this: v3); i != nullptr; i = KeyValues::GetNextKey(this: i) )
      {
        Name = KeyValues::GetName(this: i);
        if ( _V_stricmp(s1: Name, s2: "library") == 0 )
        {
          String = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: defaultValue);
          CToolFrameworkInternal::LoadToolsFromLibrary(this, dllname: String);
        }
      }
      KeyValues::deleteThis(this: v3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10202160
// Name: public: virtual bool CToolFrameworkInternal::LoadToolModule(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolFrameworkInternal::LoadToolModule(
        CToolFrameworkInternal *this,
        const char *pToolModule,
        bool bSwitchToFirst)
{
  CToolFrameworkInternal *v3; // esi
  ToolModule_t *ToolsFromLibrary; // eax
  CUtlString *p_m_sDllName; // edi
  int v7; // ebx
  int v8; // esi
  const char *v9; // eax
  CFmtStrN<256> module; // [esp+8h] [ebp-110h] BYREF
  CToolFrameworkInternal *v11; // [esp+114h] [ebp-4h]

  v3 = this;
  v11 = this;
  CFmtStrN<256>::CFmtStrN<256>(this: &module, pszFormat: "tools/%s.dll", pToolModule);
  if ( CToolFrameworkInternal::Find(this: v3, pModuleName: module.m_szBuf) != nullptr )
    return 1;
  ToolsFromLibrary = CToolFrameworkInternal::LoadToolsFromLibrary(this: v3, dllname: module.m_szBuf);
  p_m_sDllName = &ToolsFromLibrary->m_sDllName;
  if ( ToolsFromLibrary != nullptr )
  {
    v7 = 0;
    if ( ToolsFromLibrary->m_Systems.m_Size > 0 )
    {
      do
      {
        v8 = *(_DWORD *)(p_m_sDllName[2].m_Storage.m_Memory.m_nGrowSize + 4 * v7);
        if ( v8 != 0 )
        {
          (*(void (__thiscall **)(int, void *(__cdecl *)(const char *, int *)))(*(_DWORD *)v8 + 16))(
            a1: v8,
            a2: v11->m_ClientFactory);
          (*(void (__thiscall **)(int, void *(__cdecl *)(const char *, int *)))(*(_DWORD *)v8 + 12))(
            a1: v8,
            a2: v11->m_ServerFactory);
          (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 4))(a1: v8);
        }
        ++v7;
      }
      while ( v7 < p_m_sDllName[3].m_Storage.m_Memory.m_nAllocationCount );
      v3 = v11;
    }
    if ( bSwitchToFirst )
    {
      v9 = CUtlString::operator char const *(this: p_m_sDllName + 1);
      v3->SwitchToTool(this: v3, a2: v9);
    }
    return 1;
  }
  else
  {
    ConMsg(a1: "failed to load tools from %s\n", pToolModule);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10202250
// Name: public: void CToolFrameworkInternal::UnloadTools(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFrameworkInternal::UnloadTools(
        CToolFrameworkInternal *this,
        const char *pModule,
        bool bCheckCanQuit)
{
  ToolModule_t *v4; // eax
  ToolModule_t *v5; // esi
  int v6; // eax
  int v7; // eax
  IToolSystem *v8; // ebx
  const char *v9; // eax
  IToolSystem *v10; // esi
  int m_Size; // ecx
  int v12; // eax
  IToolSystem **m_pMemory; // edx
  int v14; // ebx
  bool v15; // sf
  int v16; // ebx
  struct CSysModule *m_pModule; // esi
  struct CSysModule **p_m_pModule; // eax
  int v19; // ecx
  ToolModule_t *v20; // esi
  IToolSystem **v21; // eax
  int v22; // eax
  ToolModule_t *tm; // [esp+Ch] [ebp-4h]
  int i; // [esp+1Ch] [ebp+Ch]
  int ia; // [esp+1Ch] [ebp+Ch]

  v4 = CToolFrameworkInternal::Find(this: &g_ToolFrameworkInternal, pModuleName: pModule);
  v5 = v4;
  tm = v4;
  if ( v4 != nullptr )
  {
    if ( bCheckCanQuit && (v6 = v4->m_Systems.m_Size - 1, i = v6, v6 >= 0) )
    {
      while ( 1 )
      {
        v8 = v5->m_Systems.m_Memory.m_pMemory[v6];
        if ( !v8->CanQuit(this: v8, a2: "OnUnload") )
          break;
        if ( --i < 0 )
          goto LABEL_5;
        v6 = i;
      }
      v9 = (const char *)v8->GetToolName(this: v8);
      _Msg(a1: "Can't unload %s, %s not ready to exit\n", pModule, v9);
    }
    else
    {
LABEL_5:
      v7 = v5->m_Systems.m_Size - 1;
      ia = v7;
      if ( v7 >= 0 )
      {
        while ( 1 )
        {
          v10 = v5->m_Systems.m_Memory.m_pMemory[v7];
          m_Size = this->m_ToolSystems.m_Size;
          v12 = 0;
          if ( m_Size <= 0 )
          {
LABEL_17:
            v14 = -1;
          }
          else
          {
            m_pMemory = this->m_ToolSystems.m_Memory.m_pMemory;
            while ( *m_pMemory != v10 )
            {
              ++v12;
              ++m_pMemory;
              if ( v12 >= m_Size )
                goto LABEL_17;
            }
            v14 = v12;
          }
          if ( v14 == this->m_nActiveToolIndex )
          {
            v10->OnToolDeactivate(this: v10);
            this->m_nActiveToolIndex = -1;
          }
          v10->Shutdown(this: v10);
          v10->ServerShutdown(this: v10);
          v10->ClientShutdown(this: v10);
          if ( this->m_ToolSystems.m_Size - v14 - 1 > 0 )
            _V_memmove(
              dest: &this->m_ToolSystems.m_Memory.m_pMemory[v14],
              src: &this->m_ToolSystems.m_Memory.m_pMemory[v14 + 1],
              count: 4 * (this->m_ToolSystems.m_Size - v14 - 1));
          --this->m_ToolSystems.m_Size;
          v15 = --ia < 0;
          v5 = tm;
          if ( v15 )
            break;
          v7 = ia;
        }
      }
      v5->m_pDictionary->Shutdown(this: v5->m_pDictionary);
      v5->m_pDictionary->Disconnect(this: v5->m_pDictionary);
      materials->UncacheUnusedMaterials(this: materials, a2: false);
      Sys_UnloadModule(pModule: v5->m_pModule);
      v16 = 0;
      if ( this->m_Modules.m_Size > 0 )
      {
        m_pModule = v5->m_pModule;
        p_m_pModule = &this->m_Modules.m_Memory.m_pMemory->m_pModule;
        while ( *p_m_pModule != m_pModule )
        {
          ++v16;
          p_m_pModule += 15;
          if ( v16 >= this->m_Modules.m_Size )
            goto LABEL_48;
        }
        v19 = v16;
        v20 = &this->m_Modules.m_Memory.m_pMemory[v16];
        v20->m_Systems.m_Size = 0;
        if ( v20->m_Systems.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v20->m_Systems.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v20->m_Systems.m_Memory.m_pMemory);
            v19 = v16;
            v20->m_Systems.m_Memory.m_pMemory = nullptr;
          }
          v20->m_Systems.m_Memory.m_nAllocationCount = 0;
        }
        v21 = v20->m_Systems.m_Memory.m_pMemory;
        v20->m_Systems.m_pElements = v21;
        if ( v20->m_Systems.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v21 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v21);
            v19 = v16;
            v20->m_Systems.m_Memory.m_pMemory = nullptr;
          }
          v20->m_Systems.m_Memory.m_nAllocationCount = 0;
        }
        v20->m_sFirstTool.m_Storage.m_nActualLength = 0;
        if ( v20->m_sFirstTool.m_Storage.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v20->m_sFirstTool.m_Storage.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v20->m_sFirstTool.m_Storage.m_Memory.m_pMemory);
            v19 = v16;
            v20->m_sFirstTool.m_Storage.m_Memory.m_pMemory = nullptr;
          }
          v20->m_sFirstTool.m_Storage.m_Memory.m_nAllocationCount = 0;
        }
        v20->m_sDllName.m_Storage.m_nActualLength = 0;
        if ( v20->m_sDllName.m_Storage.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v20->m_sDllName.m_Storage.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v20->m_sDllName.m_Storage.m_Memory.m_pMemory);
            v19 = v16;
            v20->m_sDllName.m_Storage.m_Memory.m_pMemory = nullptr;
          }
          v20->m_sDllName.m_Storage.m_Memory.m_nAllocationCount = 0;
        }
        v22 = this->m_Modules.m_Size - v16 - 1;
        if ( v22 > 0 )
          _V_memmove(
            dest: &this->m_Modules.m_Memory.m_pMemory[v19],
            src: &this->m_Modules.m_Memory.m_pMemory[v19 + 1],
            count: 60 * v22);
        --this->m_Modules.m_Size;
      }
LABEL_48:
      this->SwitchToTool_2(this, a2: 0);
    }
  }
  else
  {
    ConMsg(a1: "module %s not loaded\n", pModule);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102024F0
// Name: void Tool_Load_f(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Tool_Load_f(const CCommand *args)
{
  CFmtStrN<256> module; // [esp+0h] [ebp-210h] BYREF
  char fn[260]; // [esp+10Ch] [ebp-104h] BYREF

  if ( toolframework->InToolMode(this: toolframework) && cmd_source == src_command )
  {
    if ( args->m_nArgc == 2 )
    {
      V_FileBase(in: args->m_ppArgv[1], out: fn, maxlen: 260);
      CFmtStrN<256>::CFmtStrN<256>(this: &module, pszFormat: "tools/%s.dll", fn);
      if ( CToolFrameworkInternal::Find(this: &g_ToolFrameworkInternal, pModuleName: module.m_szBuf) != nullptr )
        ConMsg(a1: "module %s already loaded\n", module.m_szBuf);
      else
        CToolFrameworkInternal::LoadToolModule(this: &g_ToolFrameworkInternal, pToolModule: fn, bSwitchToFirst: true);
    }
    else
    {
      ConMsg(a1: "toolload <toolname>: loads a tool\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10202610
// Name: public: virtual enum InitReturnVal_t CToolFrameworkInternal::Init(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CToolFrameworkInternal::Init(CToolFrameworkInternal *this)
{
  CToolFrameworkInternal *v1; // esi
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // esi
  int v6; // eax
  int v7; // eax
  const char *v8; // eax
  char v9; // cl
  const CUtlString *v10; // eax
  int v11; // eax
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > vecToolList; // [esp+Ch] [ebp-28h] BYREF
  CUtlString v14; // [esp+20h] [ebp-14h] BYREF
  CToolFrameworkInternal *v15; // [esp+30h] [ebp-4h]

  v1 = this;
  v15 = this;
  this->m_bInToolMode = false;
  this->m_nActiveToolIndex = -1;
  this->m_ServerFactory = nullptr;
  this->m_ClientFactory = nullptr;
  EngineTool_InstallQuitHandler(pvUserData: this, func: CToolFrameworkInternal_QuitHandler);
  v2 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v2 + 40))(a1: v2, a2: "-tools") == 0 )
    return 1;
  memset(&vecToolList, 0, sizeof(vecToolList));
  v3 = _CommandLine();
  v4 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v3 + 40))(a1: v3, a2: "-tools");
  if ( v4 == 0 )
    goto LABEL_12;
  v5 = v4 + 1;
  v6 = _CommandLine();
  if ( v5 < (*(int (__thiscall **)(int))(*(_DWORD *)v6 + 36))(a1: v6) )
  {
    do
    {
      v7 = _CommandLine();
      v8 = (const char *)(*(int (__thiscall **)(int, int))(*(_DWORD *)v7 + 44))(a1: v7, a2: v5);
      if ( v8 == nullptr )
        break;
      v9 = *v8;
      if ( *v8 == 0 )
        break;
      if ( v9 == 45 )
        break;
      if ( v9 == 43 )
        break;
      v10 = CUtlString::CUtlString(this: &v14, pString: v8);
      CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
        this: &vecToolList,
        elem: vecToolList.m_Size,
        src: v10);
      CUtlString::~CUtlString(this: &v14);
      ++v5;
      v11 = _CommandLine();
    }
    while ( v5 < (*(int (__thiscall **)(int))(*(_DWORD *)v11 + 36))(a1: v11) );
    if ( vecToolList.m_Size > 0 )
    {
      CToolFrameworkInternal::LoadToolsFromCommandLine(this: v15, list: &vecToolList);
LABEL_13:
      CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&vecToolList);
      if ( vecToolList.m_Memory.m_nGrowSize >= 0 && vecToolList.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: vecToolList.m_Memory.m_pMemory);
      return 1;
    }
  }
  v1 = v15;
LABEL_12:
  CToolFrameworkInternal::LoadToolsFromEngineToolsManifest(this: v1);
  goto LABEL_13;
}

//------------------------------------------------------------------------------
// Address: 0x10202730
// Name: public: virtual void CToolFrameworkInternal::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CToolFrameworkInternal::Shutdown(CToolFrameworkInternal *this)
{
  CToolFrameworkInternal::ShutdownTools(this);
}

//------------------------------------------------------------------------------
// Address: 0x10202740
// Name: public: int CToolUnloadAutoCompleteFileList::AutoCompletionFunc(char const __near *,char (__near * const)[64])
// Source: json
//------------------------------------------------------------------------------
int __thiscall CToolUnloadAutoCompleteFileList::AutoCompletionFunc(
        CToolUnloadAutoCompleteFileList *this,
        const char *partial,
        char (*commands)[64])
{
  const char *v3; // esi
  int v4; // ebx
  CUtlString *m_pMemory; // ebx
  const char *v7; // eax
  char filename[260]; // [esp+Ch] [ebp-11Ch] BYREF
  const char *cmdname; // [esp+110h] [ebp-18h]
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > modules; // [esp+114h] [ebp-14h] BYREF
  int c; // [esp+130h] [ebp+8h]
  char *commandsa; // [esp+134h] [ebp+Ch]

  v3 = partial;
  cmdname = this->m_pszCommandName;
  if ( _V_strstr(s1: partial, search: cmdname) != nullptr )
    v3 = &partial[strlen(cmdname) + 1];
  v4 = 0;
  memset(&modules, 0, sizeof(modules));
  c = 0;
  CToolFrameworkInternal::GetModules(this: &g_ToolFrameworkInternal, list: &modules);
  if ( modules.m_Size > 0 )
  {
    m_pMemory = modules.m_Memory.m_pMemory;
    for ( commandsa = (char *)modules.m_Size; commandsa != nullptr; --commandsa )
    {
      v7 = CUtlString::operator char const *(this: m_pMemory);
      V_FileBase(in: v7, out: filename, maxlen: 260);
      if ( *v3 == 0 || V_strncasecmp(s1: filename, s2: v3, n: strlen(v3)) == 0 )
      {
        V_snprintf(pDest: (char *)commands, maxLen: 64, pFormat: "%s %s", cmdname, filename);
        ++c;
        ++commands;
      }
      ++m_pMemory;
    }
    v4 = c;
  }
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&modules);
  if ( modules.m_Memory.m_nGrowSize >= 0 && modules.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: modules.m_Memory.m_pMemory);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10202850
// Name: g_ToolUnload_CompletionFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl g_ToolUnload_CompletionFunc(const char *partial, char (*commands)[64])
{
  if ( (_S2_18 & 1) == 0 )
  {
    _S2_18 |= 1u;
    ToolUnload_Complete.m_pszCommandName = "toolunload";
  }
  return CToolUnloadAutoCompleteFileList::AutoCompletionFunc(this: &ToolUnload_Complete, partial, commands);
}

//------------------------------------------------------------------------------
// Address: 0x10202890
// Name: void Tool_Unload_f(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Tool_Unload_f(const CCommand *args)
{
  int m_nArgc; // eax
  const char *v2; // eax
  CFmtStrN<256> module; // [esp+0h] [ebp-214h] BYREF
  char fn[260]; // [esp+10Ch] [ebp-108h] BYREF
  BOOL bPromptForSave; // [esp+210h] [ebp-4h]

  if ( toolframework->InToolMode(this: toolframework) && cmd_source == src_command )
  {
    m_nArgc = args->m_nArgc;
    if ( args->m_nArgc >= 2 )
    {
      LOBYTE(bPromptForSave) = 1;
      if ( m_nArgc > 2 )
        LOBYTE(bPromptForSave) = _V_stricmp(s1: "-nosave", s2: args->m_ppArgv[2]) != 0;
      v2 = defaultValue;
      if ( args->m_nArgc > 1 )
        v2 = args->m_ppArgv[1];
      V_FileBase(in: v2, out: fn, maxlen: 260);
      CFmtStrN<256>::CFmtStrN<256>(this: &module, pszFormat: "tools/%s.dll", fn);
      CToolFrameworkInternal::UnloadTools(
        this: &g_ToolFrameworkInternal,
        pModule: module.m_szBuf,
        bCheckCanQuit: bPromptForSave);
    }
    else
    {
      ConMsg(a1: "toolunload <toolname> [-nosave]: unloads a tool\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102003F0
// Name: __CreateCToolFrameworkInternalIToolFrameworkInternal_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CToolFrameworkInternal *__cdecl _CreateCToolFrameworkInternalIToolFrameworkInternal_interface()
{
  return &g_ToolFrameworkInternal;
}

//------------------------------------------------------------------------------
// Address: 0x10200400
// Name: __CreateCClientEngineToolsIClientEngineTools_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CClientEngineTools *__cdecl _CreateCClientEngineToolsIClientEngineTools_interface()
{
  return &_g_CClientEngineTools_singleton;
}

//------------------------------------------------------------------------------
// Address: 0x10200410
// Name: __CreateCServerEngineToolsIServerEngineTools_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CServerEngineTools *__cdecl _CreateCServerEngineToolsIServerEngineTools_interface()
{
  return &_g_CServerEngineTools_singleton;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1017D3E0
// Name: public: virtual bool CToolFrameworkInternal::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolFrameworkInternal::Connect(CBaseClient *this, CLC_CmdKeyValues *msg)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101E8880
// Name: public: virtual void CBaseAppSystem<class IToolFrameworkInternal>::Reconnect(void __near * (*)(char const __near *,int __near *),char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAppSystem<IToolFrameworkInternal>::Reconnect(
        CBaseAppSystem<ICvarQuery> *this,
        void *(__cdecl *factory)(const char *, int *),
        const char *pInterfaceName)
{
  ReconnectInterface(factory, pInterfaceName);
}

//------------------------------------------------------------------------------
// Address: 0x10200680
// Name: CToolFrameworkInternal_QuitHandler
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CToolFrameworkInternal_QuitHandler(void *pvUserData)
{
  return pvUserData == nullptr || (*(bool (__thiscall **)(void *))(*(_DWORD *)pvUserData + 112))(a1: pvUserData);
}

//------------------------------------------------------------------------------
// Address: 0x102006A0
// Name: public: virtual bool CToolFrameworkInternal::InToolMode(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CToolFrameworkInternal::InToolMode(CToolFrameworkInternal *this)
{
  return this->m_bInToolMode || g_bReplayLoadedTools;
}

//------------------------------------------------------------------------------
// Address: 0x102006F0
// Name: public: virtual bool CServerEngineTools::InToolMode(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CServerEngineTools::InToolMode(CServerEngineTools *this)
{
  return g_ToolFrameworkInternal.m_bInToolMode || g_bReplayLoadedTools;
}

//------------------------------------------------------------------------------
// Address: 0x10200950
// Name: public: virtual void CToolFrameworkInternal::Think(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFrameworkInternal::Think(CToolFrameworkInternal *this, BOOL finalTick)
{
  int m_Size; // ebx
  int i; // esi
  IToolSystem *v5; // ecx

  m_Size = this->m_ToolSystems.m_Size;
  for ( i = 0; i < m_Size; ++i )
  {
    v5 = this->m_ToolSystems.m_Memory.m_pMemory[i];
    v5->Think(this: v5, a2: finalTick);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10200980
// Name: public: virtual bool CToolFrameworkInternal::ServerInit(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CToolFrameworkInternal::ServerInit(
        CToolFrameworkInternal *this,
        void *(__cdecl *serverFactory)(const char *, int *))
{
  int m_Size; // ebx
  bool result; // al
  int v5; // esi
  IToolSystem *v6; // ecx
  bool retval; // [esp+Fh] [ebp-1h]

  m_Size = this->m_ToolSystems.m_Size;
  this->m_ServerFactory = serverFactory;
  result = true;
  v5 = 0;
  retval = true;
  if ( m_Size > 0 )
  {
    do
    {
      v6 = this->m_ToolSystems.m_Memory.m_pMemory[v5];
      if ( !v6->ServerInit(this: v6, a2: serverFactory) )
        retval = false;
      ++v5;
    }
    while ( v5 < m_Size );
    return retval;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102009D0
// Name: public: virtual bool CToolFrameworkInternal::ClientInit(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CToolFrameworkInternal::ClientInit(
        CToolFrameworkInternal *this,
        void *(__cdecl *clientFactory)(const char *, int *))
{
  int m_Size; // ebx
  bool result; // al
  int v5; // esi
  IToolSystem *v6; // ecx
  bool retval; // [esp+Fh] [ebp-1h]

  m_Size = this->m_ToolSystems.m_Size;
  this->m_ClientFactory = clientFactory;
  result = true;
  v5 = 0;
  retval = true;
  if ( m_Size > 0 )
  {
    do
    {
      v6 = this->m_ToolSystems.m_Memory.m_pMemory[v5];
      if ( !v6->ClientInit(this: v6, a2: clientFactory) )
        retval = false;
      ++v5;
    }
    while ( v5 < m_Size );
    return retval;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10200A80
// Name: public: virtual bool CToolFrameworkInternal::CanQuit(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolFrameworkInternal::CanQuit(CToolFrameworkInternal *this)
{
  int m_Size; // ebx
  int v3; // esi
  IToolSystem *v4; // ecx

  m_Size = this->m_ToolSystems.m_Size;
  v3 = 0;
  if ( m_Size <= 0 )
    return 1;
  while ( 1 )
  {
    v4 = this->m_ToolSystems.m_Memory.m_pMemory[v3];
    if ( !v4->CanQuit(this: v4, a2: "OnQuit") )
      break;
    if ( ++v3 >= m_Size )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10200B30
// Name: public: virtual bool CToolFrameworkInternal::ShouldGameRenderView(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CToolFrameworkInternal::ShouldGameRenderView(CToolFrameworkInternal *this)
{
  int m_nActiveToolIndex; // eax
  IToolSystem *v2; // ecx

  m_nActiveToolIndex = this->m_nActiveToolIndex;
  if ( m_nActiveToolIndex < 0 )
    return true;
  v2 = this->m_ToolSystems.m_Memory.m_pMemory[m_nActiveToolIndex];
  return v2->ShouldGameRenderView(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10200B70
// Name: public: virtual class IMaterialProxy __near * CToolFrameworkInternal::LookupProxy(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IMaterialProxy *__thiscall CToolFrameworkInternal::LookupProxy(CToolFrameworkInternal *this, const char *proxyName)
{
  int v3; // esi
  IToolSystem *v4; // ecx
  IMaterialProxy *result; // eax
  int toolCount; // [esp+Ch] [ebp-4h]

  v3 = 0;
  toolCount = this->GetToolCount(this);
  if ( toolCount <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = this->m_ToolSystems.m_Memory.m_pMemory[v3];
    result = v4->LookupProxy(this: v4, a2: proxyName);
    if ( result != nullptr )
      break;
    if ( ++v3 >= toolCount )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10200BC0
// Name: public: struct ToolModule_t __near * CToolFrameworkInternal::Find(char const __near *)
// Source: json
//------------------------------------------------------------------------------
ToolModule_t *__thiscall CToolFrameworkInternal::Find(CToolFrameworkInternal *this, const char *pModuleName)
{
  int v2; // ebx
  ToolModule_t *v4; // esi
  const char *v5; // eax
  int i; // [esp+Ch] [ebp-4h]

  v2 = 0;
  i = 0;
  if ( this->m_Modules.m_Size <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = &this->m_Modules.m_Memory.m_pMemory[v2];
    v5 = CUtlString::operator char const *(this: &v4->m_sDllName);
    if ( _V_stricmp(s1: v5, s2: pModuleName) == 0 )
      break;
    ++v2;
    if ( ++i >= this->m_Modules.m_Size )
      return nullptr;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10200C20
// Name: public: virtual void CToolFrameworkInternal::ClientLevelInitPreEntityAllTools(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFrameworkInternal::ClientLevelInitPreEntityAllTools(CToolFrameworkInternal *this)
{
  int m_Size; // ebx
  int i; // esi

  m_Size = this->m_ToolSystems.m_Size;
  for ( i = 0; i < m_Size; ++i )
     __thiscall IToolSystem::`vcall'{80,{flat}}(a1: this->m_ToolSystems.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x10200CB0
// Name: public: virtual void CToolFrameworkInternal::ClientLevelShutdownPostEntityAllTools(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFrameworkInternal::ClientLevelShutdownPostEntityAllTools(CToolFrameworkInternal *this)
{
  int m_Size; // ebx
  int i; // esi

  m_Size = this->m_ToolSystems.m_Size;
  for ( i = 0; i < m_Size; ++i )
     __thiscall IToolSystem::`vcall'{92,{flat}}(a1: this->m_ToolSystems.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x10200D10
// Name: public: virtual bool CToolFrameworkInternal::IsThirdPersonCamera(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CToolFrameworkInternal::IsThirdPersonCamera(CToolFrameworkInternal *this)
{
  int m_nActiveToolIndex; // eax
  IToolSystem *v2; // ecx

  m_nActiveToolIndex = this->m_nActiveToolIndex;
  if ( m_nActiveToolIndex < 0 )
    return false;
  v2 = this->m_ToolSystems.m_Memory.m_pMemory[m_nActiveToolIndex];
  return v2->IsThirdPersonCamera(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10200D30
// Name: public: virtual bool CToolFrameworkInternal::IsToolRecording(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CToolFrameworkInternal::IsToolRecording(CToolFrameworkInternal *this)
{
  int m_nActiveToolIndex; // eax
  IToolSystem *v2; // ecx

  m_nActiveToolIndex = this->m_nActiveToolIndex;
  if ( m_nActiveToolIndex < 0 )
    return false;
  v2 = this->m_ToolSystems.m_Memory.m_pMemory[m_nActiveToolIndex];
  return v2->IsToolRecording(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10200E40
// Name: public: virtual void CToolFrameworkInternal::ServerFrameUpdatePreEntityThinkAllTools(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFrameworkInternal::ServerFrameUpdatePreEntityThinkAllTools(CToolFrameworkInternal *this)
{
  int m_Size; // ebx
  int i; // esi

  m_Size = this->m_ToolSystems.m_Size;
  for ( i = 0; i < m_Size; ++i )
     __thiscall IToolSystem::`vcall'{56,{flat}}(a1: this->m_ToolSystems.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x10200EA0
// Name: public: virtual void CToolFrameworkInternal::ServerPreClientUpdateAllTools(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFrameworkInternal::ServerPreClientUpdateAllTools(CToolFrameworkInternal *this)
{
  int m_Size; // ebx
  int i; // esi

  m_Size = this->m_ToolSystems.m_Size;
  for ( i = 0; i < m_Size; ++i )
     __thiscall IToolSystem::`vcall'{64,{flat}}(a1: this->m_ToolSystems.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x10200ED0
// Name: public: virtual void __near * CToolFrameworkInternal::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CToolFrameworkInternal::QueryInterface(CToolFrameworkInternal *this, const char *pInterfaceName)
{
  int v3; // esi
  IToolSystem *v4; // ecx
  void *result; // eax
  int toolCount; // [esp+Ch] [ebp-4h]

  v3 = 0;
  toolCount = this->m_ToolSystems.m_Size;
  if ( toolCount <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = this->m_ToolSystems.m_Memory.m_pMemory[v3];
    result = v4->QueryInterface(this: v4, a2: pInterfaceName);
    if ( result != nullptr )
      break;
    if ( ++v3 >= toolCount )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10200F40
// Name: public: virtual void CToolFrameworkInternal::PostToolMessage(unsigned int,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFrameworkInternal::PostToolMessage(
        CToolFrameworkInternal *this,
        unsigned int hEntity,
        KeyValues *msg)
{
  int m_Size; // ebx
  int i; // esi
  IToolSystem *v6; // ecx

  m_Size = this->m_ToolSystems.m_Size;
  for ( i = 0; i < m_Size; ++i )
  {
    v6 = this->m_ToolSystems.m_Memory.m_pMemory[i];
    v6->PostToolMessage(this: v6, a2: hEntity, a3: msg);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10200FA0
// Name: public: virtual bool CToolFrameworkInternal::SetupEngineView(class Vector __near &,class QAngle __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CToolFrameworkInternal::SetupEngineView(
        CToolFrameworkInternal *this,
        Vector *origin,
        QAngle *angles,
        float *fov)
{
  int m_nActiveToolIndex; // eax
  IToolSystem *v6; // ecx

  m_nActiveToolIndex = this->m_nActiveToolIndex;
  if ( m_nActiveToolIndex < 0 )
    return false;
  v6 = this->m_ToolSystems.m_Memory.m_pMemory[m_nActiveToolIndex];
  return v6->SetupEngineView(this: v6, a2: origin, a3: angles, a4: fov);
}

//------------------------------------------------------------------------------
// Address: 0x10200FC0
// Name: public: virtual bool CToolFrameworkInternal::SetupAudioState(struct AudioState_t __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CToolFrameworkInternal::SetupAudioState(CToolFrameworkInternal *this, AudioState_t *audioState)
{
  int m_nActiveToolIndex; // eax
  IToolSystem *v4; // ecx

  m_nActiveToolIndex = this->m_nActiveToolIndex;
  if ( m_nActiveToolIndex < 0 )
    return false;
  v4 = this->m_ToolSystems.m_Memory.m_pMemory[m_nActiveToolIndex];
  return v4->SetupAudioState(this: v4, a2: audioState);
}

//------------------------------------------------------------------------------
// Address: 0x10201070
// Name: public: virtual void CToolFrameworkInternal::VGui_PostSimulateAllTools(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFrameworkInternal::VGui_PostSimulateAllTools(CToolFrameworkInternal *this)
{
  int m_Size; // ebx
  int i; // esi

  m_Size = this->m_ToolSystems.m_Size;
  for ( i = 0; i < m_Size; ++i )
     __thiscall IToolSystem::`vcall'{180,{flat}}(a1: this->m_ToolSystems.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x102011A0
// Name: public: virtual bool CToolFrameworkInternal::IsTopmostTool(class IToolSystem const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CToolFrameworkInternal::IsTopmostTool(CToolFrameworkInternal *this, const IToolSystem *sys)
{
  int m_nActiveToolIndex; // eax

  return this->m_ToolSystems.m_Size > 0
      && (m_nActiveToolIndex = this->m_nActiveToolIndex) >= 0
      && this->m_ToolSystems.m_Memory.m_pMemory[m_nActiveToolIndex] == sys;
}

//------------------------------------------------------------------------------
// Address: 0x102011D0
// Name: public: virtual class IToolSystem __near * CToolFrameworkInternal::GetTopmostTool(void)
// Source: json
//------------------------------------------------------------------------------
IToolSystem *__thiscall CToolFrameworkInternal::GetTopmostTool(CToolFrameworkInternal *this)
{
  int m_nActiveToolIndex; // eax

  m_nActiveToolIndex = this->m_nActiveToolIndex;
  if ( m_nActiveToolIndex < 0 )
    return nullptr;
  else
    return this->m_ToolSystems.m_Memory.m_pMemory[m_nActiveToolIndex];
}

//------------------------------------------------------------------------------
// Address: 0x102011F0
// Name: public: virtual void CToolFrameworkInternal::PostMessage(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFrameworkInternal::PostMessage(CToolFrameworkInternal *this, KeyValues *msg)
{
  int m_nActiveToolIndex; // eax
  IToolSystem *v3; // ecx

  m_nActiveToolIndex = this->m_nActiveToolIndex;
  if ( m_nActiveToolIndex >= 0 )
  {
    v3 = this->m_ToolSystems.m_Memory.m_pMemory[m_nActiveToolIndex];
    v3->PostToolMessage(this: v3, a2: 0, a3: msg);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10201220
// Name: public: virtual bool CToolFrameworkInternal::GetSoundSpatialization(int,int,struct SpatializationInfo_t __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CToolFrameworkInternal::GetSoundSpatialization(
        CToolFrameworkInternal *this,
        int iUserData,
        int guid,
        SpatializationInfo_t *info)
{
  int m_nActiveToolIndex; // eax
  IToolSystem *v5; // ecx

  m_nActiveToolIndex = this->m_nActiveToolIndex;
  if ( m_nActiveToolIndex < 0 )
    return true;
  v5 = this->m_ToolSystems.m_Memory.m_pMemory[m_nActiveToolIndex];
  return v5->GetSoundSpatialization(this: v5, a2: iUserData, a3: guid, a4: info);
}

//------------------------------------------------------------------------------
// Address: 0x10201250
// Name: public: virtual void CToolFrameworkInternal::HostRunFrameBegin(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFrameworkInternal::HostRunFrameBegin(CToolFrameworkInternal *this)
{
  int m_Size; // ebx
  int i; // esi

  m_Size = this->m_ToolSystems.m_Size;
  for ( i = 0; i < m_Size; ++i )
     __thiscall IToolSystem::`vcall'{160,{flat}}(a1: this->m_ToolSystems.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x10201280
// Name: public: virtual void CToolFrameworkInternal::HostRunFrameEnd(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFrameworkInternal::HostRunFrameEnd(CToolFrameworkInternal *this)
{
  int m_Size; // ebx
  int i; // esi

  m_Size = this->m_ToolSystems.m_Size;
  for ( i = 0; i < m_Size; ++i )
     __thiscall IToolSystem::`vcall'{164,{flat}}(a1: this->m_ToolSystems.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x102012B0
// Name: public: virtual void CToolFrameworkInternal::RenderFrameBegin(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFrameworkInternal::RenderFrameBegin(CToolFrameworkInternal *this)
{
  int m_Size; // ebx
  int i; // esi

  m_Size = this->m_ToolSystems.m_Size;
  for ( i = 0; i < m_Size; ++i )
     __thiscall IToolSystem::`vcall'{152,{flat}}(a1: this->m_ToolSystems.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x102012E0
// Name: public: virtual void CToolFrameworkInternal::RenderFrameEnd(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFrameworkInternal::RenderFrameEnd(CToolFrameworkInternal *this)
{
  int m_Size; // ebx
  int i; // esi

  m_Size = this->m_ToolSystems.m_Size;
  for ( i = 0; i < m_Size; ++i )
     __thiscall IToolSystem::`vcall'{156,{flat}}(a1: this->m_ToolSystems.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x10201470
// Name: public: virtual void CClientEngineTools::AdjustEngineViewport(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientEngineTools::AdjustEngineViewport(
        CClientEngineTools *this,
        int *x,
        int *y,
        int *width,
        int *height)
{
  if ( g_ToolFrameworkInternal.m_nActiveToolIndex >= 0 )
    g_ToolFrameworkInternal.m_ToolSystems.m_Memory.m_pMemory[g_ToolFrameworkInternal.m_nActiveToolIndex]->AdjustEngineViewport(
      this: g_ToolFrameworkInternal.m_ToolSystems.m_Memory.m_pMemory[g_ToolFrameworkInternal.m_nActiveToolIndex],
      a2: x,
      a3: y,
      a4: width,
      a5: height);
}

//------------------------------------------------------------------------------
// Address: 0x102014A0
// Name: public: virtual bool CClientEngineTools::SetupEngineView(class Vector __near &,class QAngle __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CClientEngineTools::SetupEngineView(
        CClientEngineTools *this,
        Vector *origin,
        QAngle *angles,
        float *fov)
{
  return g_ToolFrameworkInternal.m_nActiveToolIndex >= 0
      && g_ToolFrameworkInternal.m_ToolSystems.m_Memory.m_pMemory[g_ToolFrameworkInternal.m_nActiveToolIndex]->SetupEngineView(
           this: g_ToolFrameworkInternal.m_ToolSystems.m_Memory.m_pMemory[g_ToolFrameworkInternal.m_nActiveToolIndex],
           a2: origin,
           a3: angles,
           a4: fov);
}

//------------------------------------------------------------------------------
// Address: 0x10201530
// Name: public: virtual void CClientEngineTools::VGui_PostRenderAllTools(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientEngineTools::VGui_PostRenderAllTools(CClientEngineTools *this, int paintMode)
{
  int m_Size; // edi
  int i; // esi

  m_Size = g_ToolFrameworkInternal.m_ToolSystems.m_Size;
  for ( i = 0; i < m_Size; ++i )
     __thiscall IToolSystem::`vcall'{172,{flat}}(
      a1: g_ToolFrameworkInternal.m_ToolSystems.m_Memory.m_pMemory[i],
      a2: paintMode);
}

//------------------------------------------------------------------------------
// Address: 0x10201560
// Name: public: virtual bool CClientEngineTools::IsThirdPersonCamera(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CClientEngineTools::IsThirdPersonCamera(CClientEngineTools *this)
{
  return g_ToolFrameworkInternal.m_nActiveToolIndex >= 0
      && g_ToolFrameworkInternal.m_ToolSystems.m_Memory.m_pMemory[g_ToolFrameworkInternal.m_nActiveToolIndex]->IsThirdPersonCamera(this: g_ToolFrameworkInternal.m_ToolSystems.m_Memory.m_pMemory[g_ToolFrameworkInternal.m_nActiveToolIndex]);
}

//------------------------------------------------------------------------------
// Address: 0x10201580
// Name: public: virtual void CServerEngineTools::LevelInitPreEntityAllTools(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerEngineTools::LevelInitPreEntityAllTools(CServerEngineTools *this)
{
  int m_Size; // edi
  int i; // esi

  m_Size = g_ToolFrameworkInternal.m_ToolSystems.m_Size;
  for ( i = 0; i < m_Size; ++i )
     __thiscall IToolSystem::`vcall'{40,{flat}}(a1: g_ToolFrameworkInternal.m_ToolSystems.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x102015B0
// Name: public: virtual void CServerEngineTools::LevelInitPostEntityAllTools(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerEngineTools::LevelInitPostEntityAllTools(CServerEngineTools *this)
{
  int m_Size; // edi
  int i; // esi

  m_Size = g_ToolFrameworkInternal.m_ToolSystems.m_Size;
  for ( i = 0; i < m_Size; ++i )
     __thiscall IToolSystem::`vcall'{44,{flat}}(a1: g_ToolFrameworkInternal.m_ToolSystems.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x102015E0
// Name: public: virtual void CServerEngineTools::LevelShutdownPreEntityAllTools(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerEngineTools::LevelShutdownPreEntityAllTools(CServerEngineTools *this)
{
  int m_Size; // edi
  int i; // esi

  m_Size = g_ToolFrameworkInternal.m_ToolSystems.m_Size;
  for ( i = 0; i < m_Size; ++i )
     __thiscall IToolSystem::`vcall'{48,{flat}}(a1: g_ToolFrameworkInternal.m_ToolSystems.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x10201610
// Name: public: virtual void CServerEngineTools::LevelShutdownPostEntityAllTools(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerEngineTools::LevelShutdownPostEntityAllTools(CServerEngineTools *this)
{
  int m_Size; // edi
  int i; // esi

  m_Size = g_ToolFrameworkInternal.m_ToolSystems.m_Size;
  for ( i = 0; i < m_Size; ++i )
     __thiscall IToolSystem::`vcall'{52,{flat}}(a1: g_ToolFrameworkInternal.m_ToolSystems.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x10201640
// Name: public: virtual void CServerEngineTools::FrameUpdatePreEntityThinkAllTools(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerEngineTools::FrameUpdatePreEntityThinkAllTools(CServerEngineTools *this)
{
  int m_Size; // edi
  int i; // esi

  m_Size = g_ToolFrameworkInternal.m_ToolSystems.m_Size;
  for ( i = 0; i < m_Size; ++i )
     __thiscall IToolSystem::`vcall'{56,{flat}}(a1: g_ToolFrameworkInternal.m_ToolSystems.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x10201670
// Name: public: virtual void CServerEngineTools::FrameUpdatePostEntityThinkAllTools(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerEngineTools::FrameUpdatePostEntityThinkAllTools(CServerEngineTools *this)
{
  int m_Size; // edi
  int i; // esi

  m_Size = g_ToolFrameworkInternal.m_ToolSystems.m_Size;
  for ( i = 0; i < m_Size; ++i )
     __thiscall IToolSystem::`vcall'{60,{flat}}(a1: g_ToolFrameworkInternal.m_ToolSystems.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x102016A0
// Name: public: virtual void CServerEngineTools::PreClientUpdateAllTools(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerEngineTools::PreClientUpdateAllTools(CServerEngineTools *this)
{
  int m_Size; // edi
  int i; // esi

  m_Size = g_ToolFrameworkInternal.m_ToolSystems.m_Size;
  for ( i = 0; i < m_Size; ++i )
     __thiscall IToolSystem::`vcall'{64,{flat}}(a1: g_ToolFrameworkInternal.m_ToolSystems.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x102016D0
// Name: public: virtual char const __near * CServerEngineTools::GetEntityData(char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CServerEngineTools::GetEntityData(CServerEngineTools *this, const char *pActualEntityData)
{
  if ( g_ToolFrameworkInternal.m_nActiveToolIndex < 0 )
    return pActualEntityData;
  else
    return g_ToolFrameworkInternal.m_ToolSystems.m_Memory.m_pMemory[g_ToolFrameworkInternal.m_nActiveToolIndex]->GetEntityData(
             this: g_ToolFrameworkInternal.m_ToolSystems.m_Memory.m_pMemory[g_ToolFrameworkInternal.m_nActiveToolIndex],
             a2: pActualEntityData);
}

//------------------------------------------------------------------------------
// Address: 0x10201700
// Name: public: virtual void __near * CServerEngineTools::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CServerEngineTools::QueryInterface(CServerEngineTools *this, const char *pInterfaceName)
{
  int v2; // esi
  int m_Size; // ebx
  void *result; // eax

  v2 = 0;
  m_Size = g_ToolFrameworkInternal.m_ToolSystems.m_Size;
  if ( g_ToolFrameworkInternal.m_ToolSystems.m_Size <= 0 )
    return nullptr;
  while ( 1 )
  {
    result = g_ToolFrameworkInternal.m_ToolSystems.m_Memory.m_pMemory[v2]->QueryInterface(
               this: g_ToolFrameworkInternal.m_ToolSystems.m_Memory.m_pMemory[v2],
               a2: pInterfaceName);
    if ( result != nullptr )
      break;
    if ( ++v2 >= m_Size )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10201740
// Name: public: virtual void CServerEngineTools::PreSetupVisibilityAllTools(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerEngineTools::PreSetupVisibilityAllTools(CServerEngineTools *this)
{
  int m_Size; // edi
  int i; // esi

  m_Size = g_ToolFrameworkInternal.m_ToolSystems.m_Size;
  for ( i = 0; i < m_Size; ++i )
     __thiscall IToolSystem::`vcall'{68,{flat}}(a1: g_ToolFrameworkInternal.m_ToolSystems.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x10201770
// Name: public: int CToolAutoCompleteFileList::AutoCompletionFunc(char const __near *,char (__near * const)[64])
// Source: json
//------------------------------------------------------------------------------
int __thiscall CToolAutoCompleteFileList::AutoCompletionFunc(
        CToolAutoCompleteFileList *this,
        char *partial,
        char (*commands)[64])
{
  char *v3; // ebx
  const char *m_pszCommandName; // esi
  const char *m_pszSubDir; // eax
  int m_Size; // ebx
  CUtlSymbol *m_pMemory; // edi
  const char *First; // esi
  int v10; // eax
  int v11; // esi
  CUtlSymbol *v12; // eax
  const char *Next; // eax
  int v14; // edi
  char *v15; // esi
  const char *v16; // eax
  const char *v17; // eax
  const char *v18; // ecx
  char sz[96]; // [esp+Ch] [ebp-118h] BYREF
  char searchpath[96]; // [esp+6Ch] [ebp-B8h] BYREF
  CUtlSymbolTable entries; // [esp+CCh] [ebp-58h] BYREF
  char *v23; // [esp+104h] [ebp-20h]
  const char *cmdname; // [esp+108h] [ebp-1Ch]
  CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > symbols; // [esp+10Ch] [ebp-18h] BYREF
  char *substring; // [esp+120h] [ebp-4h]

  v3 = partial;
  m_pszCommandName = this->m_pszCommandName;
  cmdname = m_pszCommandName;
  substring = partial;
  if ( _V_strstr(s1: partial, search: m_pszCommandName) != nullptr )
    substring = &v3[strlen(m_pszCommandName) + 1];
  m_pszSubDir = this->m_pszSubDir;
  m_Size = 0;
  if ( m_pszSubDir != nullptr && *m_pszSubDir != 0 && V_strcasecmp(s1: m_pszSubDir, s2: "NULL") != 0 )
    V_snprintf(pDest: searchpath, maxLen: 96, pFormat: "%s/*.%s", this->m_pszSubDir, this->m_pszExtension);
  else
    V_snprintf(pDest: searchpath, maxLen: 96, pFormat: "*.%s", this->m_pszExtension);
  CUtlSymbolTable::CUtlSymbolTable(this: &entries, growSize: 0, initSize: 0, caseInsensitive: true);
  m_pMemory = nullptr;
  memset(&symbols, 0, sizeof(symbols));
  First = Sys_FindFirstEx(pWildcard: searchpath, pPathID: "EXECUTABLE_PATH", basename: nullptr, namelength: 0);
  if ( First != nullptr )
  {
    do
    {
      memset(sz, 0, sizeof(sz));
      V_StripExtension(in: First, out: sz, outSize: 96);
      if ( *substring == 0 || (v23 = substring + 1, V_strncasecmp(s1: First, s2: substring, n: strlen(substring)) == 0) )
      {
        CUtlSymbolTable::AddString(this: &entries, result: (CUtlSymbol *)&partial, pString: First);
        v10 = 0;
        if ( m_Size <= 0 )
          goto LABEL_16;
        while ( m_pMemory[v10].m_Id != (_WORD)partial )
        {
          if ( ++v10 >= m_Size )
            goto LABEL_16;
        }
        if ( v10 == -1 )
        {
LABEL_16:
          v11 = m_Size;
          if ( m_Size + 1 > symbols.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<wchar_t,int>::Grow(
              this: (CUtlMemory<wchar_t,int> *)&symbols,
              num: m_Size - symbols.m_Memory.m_nAllocationCount + 1);
            m_Size = symbols.m_Size;
            m_pMemory = symbols.m_Memory.m_pMemory;
          }
          symbols.m_Size = ++m_Size;
          symbols.m_pElements = m_pMemory;
          if ( m_Size - v11 - 1 > 0 )
            _V_memmove(dest: &m_pMemory[v11 + 1], src: &m_pMemory[v11], count: 2 * (m_Size - v11 - 1));
          v12 = &m_pMemory[v11];
          if ( v12 != nullptr )
            v12->m_Id = (unsigned __int16)partial;
        }
      }
      Next = Sys_FindNext(basename: nullptr, namelength: 0);
      First = Next;
    }
    while ( m_Size < 64 && Next != nullptr );
  }
  Sys_FindClose();
  v14 = 0;
  if ( m_Size > 0 )
  {
    v15 = (char *)commands;
    partial = nullptr;
    do
    {
      v16 = CUtlSymbolTable::String(this: &entries, id: symbols.m_Memory.m_pMemory[v14]);
      V_snprintf(pDest: v15, maxLen: 64, pFormat: "%s %s", cmdname, v16);
      v17 = &partial[strlen(v15)];
      ++v14;
      v18 = partial + 64;
      v15 += 64;
      (*commands)[(_DWORD)v17 - 4] = 0;
      partial = (char *)v18;
    }
    while ( v14 < m_Size );
  }
  if ( symbols.m_Memory.m_nGrowSize >= 0 && symbols.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: symbols.m_Memory.m_pMemory);
  CUtlSymbolTable::~CUtlSymbolTable(this: &entries);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x102019D0
// Name: g_ToolLoad_CompletionFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl g_ToolLoad_CompletionFunc(char *partial, char (*commands)[64])
{
  if ( (_S1_22 & 1) == 0 )
  {
    _S1_22 |= 1u;
    ToolLoad_Complete.m_pszCommandName = "toolload";
    ToolLoad_Complete.m_pszSubDir = "tools";
    ToolLoad_Complete.m_pszExtension = "dll";
  }
  return CToolAutoCompleteFileList::AutoCompletionFunc(this: &ToolLoad_Complete, partial, commands);
}

//------------------------------------------------------------------------------
// Address: 0x10201C90
// Name: private: void CToolFrameworkInternal::ShutdownTools(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFrameworkInternal::ShutdownTools(CToolFrameworkInternal *this)
{
  int i; // edi
  IToolSystem *v3; // ecx
  int v4; // ebx
  int v5; // edi

  this->SwitchToTool_2(this, a2: -1);
  for ( i = this->m_ToolSystems.m_Size - 1; i >= 0; --i )
  {
    v3 = this->m_ToolSystems.m_Memory.m_pMemory[i];
    v3->Shutdown(this: v3);
  }
  this->m_ToolSystems.m_Size = 0;
  CToolFrameworkInternal::ShutdownToolDictionaries(this);
  v4 = this->m_Modules.m_Size - 1;
  if ( v4 >= 0 )
  {
    v5 = v4;
    do
    {
      Sys_UnloadModule(pModule: this->m_Modules.m_Memory.m_pMemory[v5].m_pModule);
      this->m_Modules.m_Memory.m_pMemory[v5--].m_pModule = nullptr;
      --v4;
    }
    while ( v4 >= 0 );
  }
  CUtlVector<ToolModule_t,CUtlMemory<ToolModule_t,int>>::RemoveAll(this: &this->m_Modules);
}

//------------------------------------------------------------------------------
// Address: 0x10201D10
// Name: private: struct ToolModule_t __near * CToolFrameworkInternal::LoadToolsFromLibrary(char const __near *)
// Source: json
//------------------------------------------------------------------------------
ToolModule_t *__thiscall CToolFrameworkInternal::LoadToolsFromLibrary(
        CToolFrameworkInternal *this,
        const char *dllname)
{
  struct CSysModule *Module; // eax
  struct CSysModule *v3; // edi
  void *(__cdecl *v5)(const char *, int *); // eax
  int v6; // ebx
  ToolModule_t *v7; // esi
  IToolSystem *v8; // edi
  const char *v9; // eax
  const char *v10; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  IToolSystem **m_pMemory; // ecx
  int v14; // eax
  IToolSystem **v15; // edi
  int v16; // edi
  int v17; // eax
  IToolSystem **v18; // ecx
  int v19; // eax
  IToolSystem **v20; // edi
  void *(__cdecl *factory)(const char *, int *); // [esp+8h] [ebp-18h]
  int toolCount; // [esp+Ch] [ebp-14h]
  IToolSystem *tool; // [esp+10h] [ebp-10h]
  int i; // [esp+18h] [ebp-8h]
  ToolModule_t *tm; // [esp+1Ch] [ebp-4h]
  char first_3; // [esp+2Bh] [ebp+Bh]

  Module = Sys_LoadModule(pModuleName: dllname);
  v3 = Module;
  if ( Module != nullptr )
  {
    v5 = Sys_GetFactory(pModule: Module);
    factory = v5;
    if ( v5 != nullptr )
    {
      v6 = (int)v5(a1: "VTOOLDICTIONARY003", a2: nullptr);
      if ( v6 != 0 )
      {
        if ( (**(unsigned __int8 (__thiscall ***)(int, void *(__cdecl *)(const char *, int *)))v6)(
               a1: v6,
               a2: g_AppSystemFactory) != 0 )
        {
          if ( (*(int (__thiscall **)(int))(*(_DWORD *)v6 + 12))(a1: v6) == 1 )
          {
            (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 32))(a1: v6);
            v7 = &this->m_Modules.m_Memory.m_pMemory[CUtlVector<ToolModule_t,CUtlMemory<ToolModule_t,int>>::InsertBefore(
                                                       this: &this->m_Modules,
                                                       elem: this->m_Modules.m_Size)];
            tm = v7;
            v7->m_pDictionary = (IToolDictionary *)v6;
            v7->m_pModule = v3;
            CUtlString::operator=(this: &v7->m_sDllName, src: dllname);
            first_3 = 1;
            toolCount = (*(int (__thiscall **)(int))(*(_DWORD *)v6 + 36))(a1: v6);
            for ( i = 0; i < toolCount; ++i )
            {
              v8 = (IToolSystem *)(*(int (__thiscall **)(int, int))(*(_DWORD *)v6 + 40))(a1: v6, a2: i);
              tool = v8;
              if ( v8 != nullptr )
              {
                v9 = (const char *)v8->GetToolName(this: v8);
                _Msg(a1: "Loaded tool '%s'\n", v9);
                if ( first_3 != 0 )
                {
                  first_3 = 0;
                  v10 = (const char *)v8->GetToolName(this: v8);
                  CUtlString::operator=(this: &v7->m_sFirstTool, src: v10);
                }
                m_Size = this->m_ToolSystems.m_Size;
                m_nAllocationCount = this->m_ToolSystems.m_Memory.m_nAllocationCount;
                if ( m_Size + 1 > m_nAllocationCount )
                  CUtlMemory<INetMessage *,int>::Grow(
                    this: (CUtlMemory<S3RGBA,int> *)&this->m_ToolSystems,
                    num: m_Size - m_nAllocationCount + 1);
                ++this->m_ToolSystems.m_Size;
                m_pMemory = this->m_ToolSystems.m_Memory.m_pMemory;
                v14 = this->m_ToolSystems.m_Size - m_Size - 1;
                this->m_ToolSystems.m_pElements = m_pMemory;
                if ( v14 > 0 )
                  _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v14);
                v15 = &this->m_ToolSystems.m_Memory.m_pMemory[m_Size];
                if ( v15 != nullptr )
                  *v15 = tool;
                v7 = tm;
                v16 = tm->m_Systems.m_Size;
                v17 = tm->m_Systems.m_Memory.m_nAllocationCount;
                if ( v16 + 1 > v17 )
                  CUtlMemory<INetMessage *,int>::Grow(
                    this: (CUtlMemory<S3RGBA,int> *)&tm->m_Systems,
                    num: v16 - v17 + 1);
                ++tm->m_Systems.m_Size;
                v18 = tm->m_Systems.m_Memory.m_pMemory;
                v19 = tm->m_Systems.m_Size - v16 - 1;
                tm->m_Systems.m_pElements = v18;
                if ( v19 > 0 )
                  _V_memmove(dest: &v18[v16 + 1], src: &v18[v16], count: 4 * v19);
                v20 = &tm->m_Systems.m_Memory.m_pMemory[v16];
                if ( v20 != nullptr )
                  *v20 = tool;
              }
            }
            g_pHammer = (IHammer *)factory(a1: "Hammer001", a2: nullptr);
            return v7;
          }
          else
          {
            Sys_UnloadModule(pModule: v3);
            _Warning(
              a1: "CToolFrameworkInternal::LoadToolsFromLibrary:  Dll '%s' initialization phase failed.\n",
              dllname);
            return nullptr;
          }
        }
        else
        {
          Sys_UnloadModule(pModule: v3);
          _Warning(a1: "CToolFrameworkInternal::LoadToolsFromLibrary:  Dll '%s' connection phase failed.\n", dllname);
          return nullptr;
        }
      }
      else
      {
        Sys_UnloadModule(pModule: v3);
        _Warning(
          a1: "CToolFrameworkInternal::LoadToolsFromLibrary:  Dll '%s' doesn't support '%s'\n",
          dllname,
          "VTOOLDICTIONARY003");
        return nullptr;
      }
    }
    else
    {
      Sys_UnloadModule(pModule: v3);
      _Warning(a1: "CToolFrameworkInternal::LoadToolsFromLibrary:  Dll '%s' has no factory\n", dllname);
      return nullptr;
    }
  }
  else
  {
    _Warning(a1: "CToolFrameworkInternal::LoadToolsFromLibrary:  Unable to load '%s'\n", dllname);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10201F90
// Name: public: virtual bool CToolFrameworkInternal::LoadFilmmaker(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolFrameworkInternal::LoadFilmmaker(CToolFrameworkInternal *this)
{
  char *ModDirectory; // eax

  ModDirectory = COM_GetModDirectory();
  if ( _V_stricmp(s1: ModDirectory, s2: "tf") != 0 )
    return 0;
  CToolFrameworkInternal::LoadToolsFromLibrary(this, dllname: "tools/ifm.dll");
  this->ClientInit(this, a2: g_ClientFactory);
  this->ServerInit(this, a2: g_ServerFactory);
  this->PostInit(this);
  g_bReplayLoadedTools = true;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10201FF0
// Name: public: virtual void CToolFrameworkInternal::UnloadFilmmaker(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFrameworkInternal::UnloadFilmmaker(CToolFrameworkInternal *this)
{
  char *ModDirectory; // eax

  ModDirectory = COM_GetModDirectory();
  if ( _V_stricmp(s1: ModDirectory, s2: "tf") == 0 )
  {
    this->ServerShutdown(this);
    this->ClientShutdown(this);
    CToolFrameworkInternal::ShutdownTools(this);
    g_bReplayLoadedTools = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10202030
// Name: private: void CToolFrameworkInternal::LoadToolsFromCommandLine(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFrameworkInternal::LoadToolsFromCommandLine(
        CToolFrameworkInternal *this,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *list)
{
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *v2; // eax
  const char *v3; // eax
  char *m_szBuf; // esi
  struct CSysModule *Module; // eax
  struct CSysModule *v6; // ebx
  void *(__cdecl *Factory)(const char *, int *); // eax
  int v8; // edi
  CToolFrameworkInternal *v9; // edi
  int v10; // eax
  ToolModule_t *m_pMemory; // edx
  int v12; // edi
  CUtlString *p_m_sDllName; // ecx
  int (__thiscall *v14)(int); // edx
  int v15; // eax
  int v16; // ecx
  int (__thiscall ***v17)(_DWORD); // ebx
  const char *v18; // eax
  int (__thiscall *v19)(_DWORD); // edx
  const char *v20; // eax
  _DWORD *v21; // esi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  int v24; // ecx
  int v25; // eax
  _DWORD *v26; // edi
  CUtlString *v27; // esi
  int v28; // edi
  int m_nActualLength; // eax
  int m_nGrowSize; // ecx
  int v31; // eax
  _DWORD *v32; // edi
  CFmtStrN<256> v33; // [esp+0h] [ebp-130h] BYREF
  void *(__cdecl *v34)(const char *, int *); // [esp+10Ch] [ebp-24h]
  int v35; // [esp+110h] [ebp-20h]
  CToolFrameworkInternal *v36; // [esp+114h] [ebp-1Ch]
  int j; // [esp+118h] [ebp-18h]
  int i; // [esp+11Ch] [ebp-14h]
  CUtlString *v39; // [esp+120h] [ebp-10h]
  unsigned int v40; // [esp+124h] [ebp-Ch]
  int v41; // [esp+128h] [ebp-8h]
  char v42; // [esp+12Fh] [ebp-1h]

  v2 = list;
  this->m_bInToolMode = true;
  v36 = this;
  i = 0;
  if ( list->m_Size > 0 )
  {
    v40 = 0;
    do
    {
      v3 = CUtlString::operator char const *(this: &v2->m_Memory.m_pMemory[v40 / 0x10]);
      m_szBuf = CFmtStrN<256>::CFmtStrN<256>(this: &v33, pszFormat: "tools/%s.dll", v3)->m_szBuf;
      Module = Sys_LoadModule(pModuleName: m_szBuf);
      v6 = Module;
      if ( Module != nullptr )
      {
        Factory = Sys_GetFactory(pModule: Module);
        v34 = Factory;
        if ( Factory != nullptr )
        {
          v8 = (int)Factory(a1: "VTOOLDICTIONARY003", a2: nullptr);
          v41 = v8;
          if ( v8 != 0 )
          {
            if ( (**(unsigned __int8 (__thiscall ***)(int, void *(__cdecl *)(const char *, int *)))v8)(
                   a1: v8,
                   a2: g_AppSystemFactory) != 0 )
            {
              if ( (*(int (__thiscall **)(int))(*(_DWORD *)v8 + 12))(a1: v8) == 1 )
              {
                (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 32))(a1: v8);
                v9 = v36;
                v10 = CUtlVector<ToolModule_t,CUtlMemory<ToolModule_t,int>>::InsertBefore(
                        this: &v36->m_Modules,
                        elem: v36->m_Modules.m_Size);
                m_pMemory = v9->m_Modules.m_Memory.m_pMemory;
                v12 = v41;
                p_m_sDllName = &m_pMemory[v10].m_sDllName;
                v39 = p_m_sDllName;
                p_m_sDllName[2].m_Storage.m_Memory.m_nAllocationCount = v41;
                p_m_sDllName[2].m_Storage.m_Memory.m_pMemory = (unsigned __int8 *)v6;
                CUtlString::operator=(this: p_m_sDllName, src: m_szBuf);
                v14 = *(int (__thiscall **)(int))(*(_DWORD *)v12 + 36);
                v42 = 1;
                v15 = v14(a1: v12);
                v16 = 0;
                v35 = v15;
                for ( j = 0; v16 < v35; j = v16 )
                {
                  v17 = (int (__thiscall ***)(_DWORD))(*(int (__thiscall **)(int, int))(*(_DWORD *)v12 + 40))(
                                                        a1: v12,
                                                        a2: v16);
                  if ( v17 != nullptr )
                  {
                    v18 = (const char *)(**v17)(a1: v17);
                    _Msg(a1: "Loaded tool '%s'\n", v18);
                    if ( v42 != 0 )
                    {
                      v19 = **v17;
                      v42 = 0;
                      v20 = (const char *)v19(a1: v17);
                      CUtlString::operator=(this: v39 + 1, src: v20);
                    }
                    v21 = &v36->__vftable;
                    m_Size = v36->m_ToolSystems.m_Size;
                    m_nAllocationCount = v36->m_ToolSystems.m_Memory.m_nAllocationCount;
                    if ( m_Size + 1 > m_nAllocationCount )
                      CUtlMemory<INetMessage *,int>::Grow(
                        this: (CUtlMemory<S3RGBA,int> *)&v36->m_ToolSystems,
                        num: m_Size - m_nAllocationCount + 1);
                    ++v21[4];
                    v24 = v21[1];
                    v25 = v21[4] - m_Size - 1;
                    v21[5] = v24;
                    if ( v25 > 0 )
                      _V_memmove(
                        dest: (void *)(v24 + 4 * m_Size + 4),
                        src: (const void *)(v24 + 4 * m_Size),
                        count: 4 * v25);
                    v26 = (_DWORD *)(v21[1] + 4 * m_Size);
                    if ( v26 != nullptr )
                      *v26 = v17;
                    v27 = v39;
                    v28 = v39[3].m_Storage.m_Memory.m_nAllocationCount;
                    m_nActualLength = v39[2].m_Storage.m_nActualLength;
                    if ( v28 + 1 > m_nActualLength )
                      CUtlMemory<INetMessage *,int>::Grow(
                        this: (CUtlMemory<S3RGBA,int> *)&v39[2].m_Storage.m_Memory.m_nGrowSize,
                        num: v28 - m_nActualLength + 1);
                    ++v27[3].m_Storage.m_Memory.m_nAllocationCount;
                    m_nGrowSize = v27[2].m_Storage.m_Memory.m_nGrowSize;
                    v31 = v27[3].m_Storage.m_Memory.m_nAllocationCount - v28 - 1;
                    v27[3].m_Storage.m_Memory.m_nGrowSize = m_nGrowSize;
                    if ( v31 > 0 )
                      _V_memmove(
                        dest: (void *)(m_nGrowSize + 4 * v28 + 4),
                        src: (const void *)(m_nGrowSize + 4 * v28),
                        count: 4 * v31);
                    v32 = (_DWORD *)(v27[2].m_Storage.m_Memory.m_nGrowSize + 4 * v28);
                    if ( v32 != nullptr )
                      *v32 = v17;
                    v12 = v41;
                  }
                  v16 = j + 1;
                }
                g_pHammer = (IHammer *)v34(a1: "Hammer001", a2: nullptr);
              }
              else
              {
                Sys_UnloadModule(pModule: v6);
                _Warning(
                  a1: "CToolFrameworkInternal::LoadToolsFromLibrary:  Dll '%s' initialization phase failed.\n",
                  m_szBuf);
              }
            }
            else
            {
              Sys_UnloadModule(pModule: v6);
              _Warning(
                a1: "CToolFrameworkInternal::LoadToolsFromLibrary:  Dll '%s' connection phase failed.\n",
                m_szBuf);
            }
          }
          else
          {
            Sys_UnloadModule(pModule: v6);
            _Warning(
              a1: "CToolFrameworkInternal::LoadToolsFromLibrary:  Dll '%s' doesn't support '%s'\n",
              m_szBuf,
              "VTOOLDICTIONARY003");
          }
        }
        else
        {
          Sys_UnloadModule(pModule: v6);
          _Warning(a1: "CToolFrameworkInternal::LoadToolsFromLibrary:  Dll '%s' has no factory\n", m_szBuf);
        }
      }
      else
      {
        _Warning(a1: "CToolFrameworkInternal::LoadToolsFromLibrary:  Unable to load '%s'\n", m_szBuf);
      }
      v2 = list;
      v40 += 16;
      ++i;
    }
    while ( i < list->m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x102022E0
// Name: private: void CToolFrameworkInternal::LoadToolsFromEngineToolsManifest(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFrameworkInternal::LoadToolsFromEngineToolsManifest(CToolFrameworkInternal *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // edi
  IBaseFileSystem *v4; // eax
  KeyValues *i; // esi
  const char *Name; // eax
  const char *String; // eax
  char szToolConfigFile[28]; // [esp+8h] [ebp-1Ch] BYREF

  this->m_bInToolMode = true;
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "enginetools");
  else
    v3 = nullptr;
  if ( g_pFileSystem->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: "enginetools.txt", a3: "EXECUTABLE_PATH") )
    V_strncpy(pDest: szToolConfigFile, pSrc: "enginetools.txt", maxLen: 25);
  else
    V_strncpy(pDest: szToolConfigFile, pSrc: "sdkenginetools.txt", maxLen: 25);
  if ( v3 != nullptr )
  {
    v4 = g_pFileSystem != nullptr ? &g_pFileSystem->IBaseFileSystem : nullptr;
    if ( KeyValues::LoadFromFile(
           this: v3,
           filesystem: v4,
           resourceName: szToolConfigFile,
           pathID: "EXECUTABLE_PATH",
           pfnEvaluateSymbolProc: nullptr) )
    {
      for ( i = KeyValues::GetFirstSubKey(this: v3); i != nullptr; i = KeyValues::GetNextKey(this: i) )
      {
        Name = KeyValues::GetName(this: i);
        if ( _V_stricmp(s1: Name, s2: "library") == 0 )
        {
          String = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: defaultValue);
          CToolFrameworkInternal::LoadToolsFromLibrary(this, dllname: String);
        }
      }
      KeyValues::deleteThis(this: v3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102023D0
// Name: public: virtual bool CToolFrameworkInternal::LoadToolModule(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolFrameworkInternal::LoadToolModule(
        CToolFrameworkInternal *this,
        const char *pToolModule,
        bool bSwitchToFirst)
{
  CToolFrameworkInternal *v3; // esi
  ToolModule_t *ToolsFromLibrary; // eax
  CUtlString *p_m_sDllName; // edi
  int v7; // ebx
  int v8; // esi
  const char *v9; // eax
  CFmtStrN<256> module; // [esp+8h] [ebp-110h] BYREF
  CToolFrameworkInternal *v11; // [esp+114h] [ebp-4h]

  v3 = this;
  v11 = this;
  CFmtStrN<256>::CFmtStrN<256>(this: &module, pszFormat: "tools/%s.dll", pToolModule);
  if ( CToolFrameworkInternal::Find(this: v3, pModuleName: module.m_szBuf) != nullptr )
    return 1;
  ToolsFromLibrary = CToolFrameworkInternal::LoadToolsFromLibrary(this: v3, dllname: module.m_szBuf);
  p_m_sDllName = &ToolsFromLibrary->m_sDllName;
  if ( ToolsFromLibrary != nullptr )
  {
    v7 = 0;
    if ( ToolsFromLibrary->m_Systems.m_Size > 0 )
    {
      do
      {
        v8 = *(_DWORD *)(p_m_sDllName[2].m_Storage.m_Memory.m_nGrowSize + 4 * v7);
        if ( v8 != 0 )
        {
          (*(void (__thiscall **)(int, void *(__cdecl *)(const char *, int *)))(*(_DWORD *)v8 + 16))(
            a1: v8,
            a2: v11->m_ClientFactory);
          (*(void (__thiscall **)(int, void *(__cdecl *)(const char *, int *)))(*(_DWORD *)v8 + 12))(
            a1: v8,
            a2: v11->m_ServerFactory);
          (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 4))(a1: v8);
        }
        ++v7;
      }
      while ( v7 < p_m_sDllName[3].m_Storage.m_Memory.m_nAllocationCount );
      v3 = v11;
    }
    if ( bSwitchToFirst )
    {
      v9 = CUtlString::operator char const *(this: p_m_sDllName + 1);
      v3->SwitchToTool(this: v3, a2: v9);
    }
    return 1;
  }
  else
  {
    ConMsg(a1: "failed to load tools from %s\n", pToolModule);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102024C0
// Name: public: void CToolFrameworkInternal::UnloadTools(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFrameworkInternal::UnloadTools(
        CToolFrameworkInternal *this,
        const char *pModule,
        bool bCheckCanQuit)
{
  ToolModule_t *v4; // eax
  ToolModule_t *v5; // esi
  int v6; // eax
  int v7; // eax
  IToolSystem *v8; // ebx
  const char *v9; // eax
  IToolSystem *v10; // esi
  int m_Size; // ecx
  int v12; // eax
  IToolSystem **m_pMemory; // edx
  int v14; // ebx
  bool v15; // sf
  int v16; // ebx
  struct CSysModule *m_pModule; // esi
  struct CSysModule **p_m_pModule; // eax
  int v19; // ecx
  ToolModule_t *v20; // esi
  IToolSystem **v21; // eax
  int v22; // eax
  ToolModule_t *tm; // [esp+Ch] [ebp-4h]
  int i; // [esp+1Ch] [ebp+Ch]
  int ia; // [esp+1Ch] [ebp+Ch]

  v4 = CToolFrameworkInternal::Find(this: &g_ToolFrameworkInternal, pModuleName: pModule);
  v5 = v4;
  tm = v4;
  if ( v4 != nullptr )
  {
    if ( bCheckCanQuit && (v6 = v4->m_Systems.m_Size - 1, i = v6, v6 >= 0) )
    {
      while ( 1 )
      {
        v8 = v5->m_Systems.m_Memory.m_pMemory[v6];
        if ( !v8->CanQuit(this: v8, a2: "OnUnload") )
          break;
        if ( --i < 0 )
          goto LABEL_5;
        v6 = i;
      }
      v9 = (const char *)v8->GetToolName(this: v8);
      _Msg(a1: "Can't unload %s, %s not ready to exit\n", pModule, v9);
    }
    else
    {
LABEL_5:
      v7 = v5->m_Systems.m_Size - 1;
      ia = v7;
      if ( v7 >= 0 )
      {
        while ( 1 )
        {
          v10 = v5->m_Systems.m_Memory.m_pMemory[v7];
          m_Size = this->m_ToolSystems.m_Size;
          v12 = 0;
          if ( m_Size <= 0 )
          {
LABEL_17:
            v14 = -1;
          }
          else
          {
            m_pMemory = this->m_ToolSystems.m_Memory.m_pMemory;
            while ( *m_pMemory != v10 )
            {
              ++v12;
              ++m_pMemory;
              if ( v12 >= m_Size )
                goto LABEL_17;
            }
            v14 = v12;
          }
          if ( v14 == this->m_nActiveToolIndex )
          {
            v10->OnToolDeactivate(this: v10);
            this->m_nActiveToolIndex = -1;
          }
          v10->Shutdown(this: v10);
          v10->ServerShutdown(this: v10);
          v10->ClientShutdown(this: v10);
          if ( this->m_ToolSystems.m_Size - v14 - 1 > 0 )
            _V_memmove(
              dest: &this->m_ToolSystems.m_Memory.m_pMemory[v14],
              src: &this->m_ToolSystems.m_Memory.m_pMemory[v14 + 1],
              count: 4 * (this->m_ToolSystems.m_Size - v14 - 1));
          --this->m_ToolSystems.m_Size;
          v15 = --ia < 0;
          v5 = tm;
          if ( v15 )
            break;
          v7 = ia;
        }
      }
      v5->m_pDictionary->Shutdown(this: v5->m_pDictionary);
      v5->m_pDictionary->Disconnect(this: v5->m_pDictionary);
      materials->UncacheUnusedMaterials(this: materials, a2: false);
      Sys_UnloadModule(pModule: v5->m_pModule);
      v16 = 0;
      if ( this->m_Modules.m_Size > 0 )
      {
        m_pModule = v5->m_pModule;
        p_m_pModule = &this->m_Modules.m_Memory.m_pMemory->m_pModule;
        while ( *p_m_pModule != m_pModule )
        {
          ++v16;
          p_m_pModule += 15;
          if ( v16 >= this->m_Modules.m_Size )
            goto LABEL_48;
        }
        v19 = v16;
        v20 = &this->m_Modules.m_Memory.m_pMemory[v16];
        v20->m_Systems.m_Size = 0;
        if ( v20->m_Systems.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v20->m_Systems.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v20->m_Systems.m_Memory.m_pMemory);
            v19 = v16;
            v20->m_Systems.m_Memory.m_pMemory = nullptr;
          }
          v20->m_Systems.m_Memory.m_nAllocationCount = 0;
        }
        v21 = v20->m_Systems.m_Memory.m_pMemory;
        v20->m_Systems.m_pElements = v21;
        if ( v20->m_Systems.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v21 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v21);
            v19 = v16;
            v20->m_Systems.m_Memory.m_pMemory = nullptr;
          }
          v20->m_Systems.m_Memory.m_nAllocationCount = 0;
        }
        v20->m_sFirstTool.m_Storage.m_nActualLength = 0;
        if ( v20->m_sFirstTool.m_Storage.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v20->m_sFirstTool.m_Storage.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v20->m_sFirstTool.m_Storage.m_Memory.m_pMemory);
            v19 = v16;
            v20->m_sFirstTool.m_Storage.m_Memory.m_pMemory = nullptr;
          }
          v20->m_sFirstTool.m_Storage.m_Memory.m_nAllocationCount = 0;
        }
        v20->m_sDllName.m_Storage.m_nActualLength = 0;
        if ( v20->m_sDllName.m_Storage.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v20->m_sDllName.m_Storage.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v20->m_sDllName.m_Storage.m_Memory.m_pMemory);
            v19 = v16;
            v20->m_sDllName.m_Storage.m_Memory.m_pMemory = nullptr;
          }
          v20->m_sDllName.m_Storage.m_Memory.m_nAllocationCount = 0;
        }
        v22 = this->m_Modules.m_Size - v16 - 1;
        if ( v22 > 0 )
          _V_memmove(
            dest: &this->m_Modules.m_Memory.m_pMemory[v19],
            src: &this->m_Modules.m_Memory.m_pMemory[v19 + 1],
            count: 60 * v22);
        --this->m_Modules.m_Size;
      }
LABEL_48:
      this->SwitchToTool_2(this, a2: 0);
    }
  }
  else
  {
    ConMsg(a1: "module %s not loaded\n", pModule);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10202760
// Name: void Tool_Load_f(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Tool_Load_f(const CCommand *args)
{
  CFmtStrN<256> module; // [esp+0h] [ebp-210h] BYREF
  char fn[260]; // [esp+10Ch] [ebp-104h] BYREF

  if ( toolframework->InToolMode(this: toolframework) && cmd_source == src_command )
  {
    if ( args->m_nArgc == 2 )
    {
      V_FileBase(in: args->m_ppArgv[1], out: fn, maxlen: 260);
      CFmtStrN<256>::CFmtStrN<256>(this: &module, pszFormat: "tools/%s.dll", fn);
      if ( CToolFrameworkInternal::Find(this: &g_ToolFrameworkInternal, pModuleName: module.m_szBuf) != nullptr )
        ConMsg(a1: "module %s already loaded\n", module.m_szBuf);
      else
        CToolFrameworkInternal::LoadToolModule(this: &g_ToolFrameworkInternal, pToolModule: fn, bSwitchToFirst: true);
    }
    else
    {
      ConMsg(a1: "toolload <toolname>: loads a tool\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10202880
// Name: public: virtual enum InitReturnVal_t CToolFrameworkInternal::Init(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CToolFrameworkInternal::Init(CToolFrameworkInternal *this)
{
  CToolFrameworkInternal *v1; // esi
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // esi
  int v6; // eax
  int v7; // eax
  const char *v8; // eax
  char v9; // cl
  const CUtlString *v10; // eax
  int v11; // eax
  int v13; // [esp+0h] [ebp-34h]
  int v14; // [esp+0h] [ebp-34h]
  int v15; // [esp+0h] [ebp-34h]
  int v16; // [esp+0h] [ebp-34h]
  int v17; // [esp+0h] [ebp-34h]
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > vecToolList; // [esp+Ch] [ebp-28h] BYREF
  CUtlString v19; // [esp+20h] [ebp-14h] BYREF
  CToolFrameworkInternal *v20; // [esp+30h] [ebp-4h]

  v1 = this;
  v20 = this;
  this->m_bInToolMode = false;
  this->m_nActiveToolIndex = -1;
  this->m_ServerFactory = nullptr;
  this->m_ClientFactory = nullptr;
  EngineTool_InstallQuitHandler(pvUserData: (vgui::Panel *)this, func: CToolFrameworkInternal_QuitHandler);
  v2 = _CommandLine(a1: v13);
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v2 + 40))(a1: v2, a2: "-tools") == 0 )
    return 1;
  memset(&vecToolList, 0, sizeof(vecToolList));
  v3 = _CommandLine(a1: v14);
  v4 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v3 + 40))(a1: v3, a2: "-tools");
  if ( v4 == 0 )
    goto LABEL_12;
  v5 = v4 + 1;
  v6 = _CommandLine(a1: v15);
  if ( v5 < (*(int (__thiscall **)(int))(*(_DWORD *)v6 + 36))(a1: v6) )
  {
    do
    {
      v7 = _CommandLine(a1: v16);
      v8 = (const char *)(*(int (__thiscall **)(int, int))(*(_DWORD *)v7 + 44))(a1: v7, a2: v5);
      if ( v8 == nullptr )
        break;
      v9 = *v8;
      if ( *v8 == 0 )
        break;
      if ( v9 == 45 )
        break;
      if ( v9 == 43 )
        break;
      v10 = CUtlString::CUtlString(this: &v19, pString: v8);
      CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
        this: &vecToolList,
        elem: vecToolList.m_Size,
        src: v10);
      CUtlString::~CUtlString(this: &v19);
      ++v5;
      v11 = _CommandLine(a1: v17);
    }
    while ( v5 < (*(int (__thiscall **)(int))(*(_DWORD *)v11 + 36))(a1: v11) );
    if ( vecToolList.m_Size > 0 )
    {
      CToolFrameworkInternal::LoadToolsFromCommandLine(this: v20, list: &vecToolList);
LABEL_13:
      CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&vecToolList);
      if ( vecToolList.m_Memory.m_nGrowSize >= 0 && vecToolList.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: vecToolList.m_Memory.m_pMemory);
      return 1;
    }
  }
  v1 = v20;
LABEL_12:
  CToolFrameworkInternal::LoadToolsFromEngineToolsManifest(this: v1);
  goto LABEL_13;
}

//------------------------------------------------------------------------------
// Address: 0x102029A0
// Name: public: virtual void CToolFrameworkInternal::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CToolFrameworkInternal::Shutdown(CToolFrameworkInternal *this)
{
  CToolFrameworkInternal::ShutdownTools(this);
}

//------------------------------------------------------------------------------
// Address: 0x102029B0
// Name: public: int CToolUnloadAutoCompleteFileList::AutoCompletionFunc(char const __near *,char (__near * const)[64])
// Source: json
//------------------------------------------------------------------------------
int __thiscall CToolUnloadAutoCompleteFileList::AutoCompletionFunc(
        CToolUnloadAutoCompleteFileList *this,
        const char *partial,
        char (*commands)[64])
{
  const char *v3; // esi
  int v4; // ebx
  CUtlString *m_pMemory; // ebx
  const char *v7; // eax
  char filename[260]; // [esp+Ch] [ebp-11Ch] BYREF
  const char *cmdname; // [esp+110h] [ebp-18h]
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > modules; // [esp+114h] [ebp-14h] BYREF
  int c; // [esp+130h] [ebp+8h]
  char *commandsa; // [esp+134h] [ebp+Ch]

  v3 = partial;
  cmdname = this->m_pszCommandName;
  if ( _V_strstr(s1: partial, search: cmdname) != nullptr )
    v3 = &partial[strlen(cmdname) + 1];
  v4 = 0;
  memset(&modules, 0, sizeof(modules));
  c = 0;
  CToolFrameworkInternal::GetModules(this: &g_ToolFrameworkInternal, list: &modules);
  if ( modules.m_Size > 0 )
  {
    m_pMemory = modules.m_Memory.m_pMemory;
    for ( commandsa = (char *)modules.m_Size; commandsa != nullptr; --commandsa )
    {
      v7 = CUtlString::operator char const *(this: m_pMemory);
      V_FileBase(in: v7, out: filename, maxlen: 260);
      if ( *v3 == 0 || V_strncasecmp(s1: filename, s2: v3, n: strlen(v3)) == 0 )
      {
        V_snprintf(pDest: (char *)commands, maxLen: 64, pFormat: "%s %s", cmdname, filename);
        ++c;
        ++commands;
      }
      ++m_pMemory;
    }
    v4 = c;
  }
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&modules);
  if ( modules.m_Memory.m_nGrowSize >= 0 && modules.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: modules.m_Memory.m_pMemory);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10202AC0
// Name: g_ToolUnload_CompletionFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl g_ToolUnload_CompletionFunc(const char *partial, char (*commands)[64])
{
  if ( (_S2_18 & 1) == 0 )
  {
    _S2_18 |= 1u;
    ToolUnload_Complete.m_pszCommandName = "toolunload";
  }
  return CToolUnloadAutoCompleteFileList::AutoCompletionFunc(this: &ToolUnload_Complete, partial, commands);
}

//------------------------------------------------------------------------------
// Address: 0x10202B00
// Name: void Tool_Unload_f(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Tool_Unload_f(const CCommand *args)
{
  int m_nArgc; // eax
  const char *v2; // eax
  CFmtStrN<256> module; // [esp+0h] [ebp-214h] BYREF
  char fn[260]; // [esp+10Ch] [ebp-108h] BYREF
  BOOL bPromptForSave; // [esp+210h] [ebp-4h]

  if ( toolframework->InToolMode(this: toolframework) && cmd_source == src_command )
  {
    m_nArgc = args->m_nArgc;
    if ( args->m_nArgc >= 2 )
    {
      LOBYTE(bPromptForSave) = 1;
      if ( m_nArgc > 2 )
        LOBYTE(bPromptForSave) = _V_stricmp(s1: "-nosave", s2: args->m_ppArgv[2]) != 0;
      v2 = defaultValue;
      if ( args->m_nArgc > 1 )
        v2 = args->m_ppArgv[1];
      V_FileBase(in: v2, out: fn, maxlen: 260);
      CFmtStrN<256>::CFmtStrN<256>(this: &module, pszFormat: "tools/%s.dll", fn);
      CToolFrameworkInternal::UnloadTools(
        this: &g_ToolFrameworkInternal,
        pModule: module.m_szBuf,
        bCheckCanQuit: bPromptForSave);
    }
    else
    {
      ConMsg(a1: "toolunload <toolname> [-nosave]: unloads a tool\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102006D0
// Name: __CreateCClientEngineToolsIClientEngineTools_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CClientEngineTools *__cdecl _CreateCClientEngineToolsIClientEngineTools_interface()
{
  return &_g_CClientEngineTools_singleton;
}

//------------------------------------------------------------------------------
// Address: 0x102006E0
// Name: __CreateCServerEngineToolsIServerEngineTools_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CServerEngineTools *__cdecl _CreateCServerEngineToolsIServerEngineTools_interface()
{
  return &_g_CServerEngineTools_singleton;
}

} // namespace engine_xlsp
