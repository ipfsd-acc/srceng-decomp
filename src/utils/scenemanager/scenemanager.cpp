// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/scenemanager/scenemanager.cpp
// Functions: 10
// ============================================================

#include "utils\scenemanager\scenemanager.h"

//------------------------------------------------------------------------------
// Address: 0x00409D00
// Name: public: virtual void CSceneManagerLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneManagerLoggingListener::Log(
        CSceneManagerLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  if ( pContext->m_Severity == LS_WARNING || pContext->m_Severity == LS_ASSERT )
  {
    Con_ColorPrintf(r: 255, g: 0, b: 0, fmt: pMessage);
  }
  else if ( pContext->m_Severity == LS_ERROR )
  {
    _Plat_MessageBox(a1: "ERROR", a2: pMessage);
  }
  else
  {
    Con_Printf(fmt: pMessage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409D60
// Name: public: virtual bool CHLSceneManagerApp::Create(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHLSceneManagerApp::Create(CHLSceneManagerApp *this)
{
  AppSystemInfo_t appSystems[3]; // [esp+4h] [ebp-18h] BYREF

  _LoggingSystem_PushLoggingState(a1: 0, a2: 1);
  _LoggingSystem_RegisterLoggingListener(a1: &s_SceneManagerLoggingListener);
  appSystems[2].m_pModuleName = &WindowName;
  appSystems[2].m_pInterfaceName = &WindowName;
  appSystems[0].m_pModuleName = "vgui2.dll";
  appSystems[0].m_pInterfaceName = "VGUI_ivgui008";
  appSystems[1].m_pModuleName = "soundemittersystem.dll";
  appSystems[1].m_pInterfaceName = "VSoundEmitter003";
  return CAppSystemGroup::AddSystems(this, pSystemList: appSystems);
}

//------------------------------------------------------------------------------
// Address: 0x00409DC0
// Name: public: virtual void CHLSceneManagerApp::Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLSceneManagerApp::Destroy(CHLSceneManagerApp *this)
{
  _LoggingSystem_PopLoggingState(a1: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00409DD0
// Name: private: bool CHLSceneManagerApp::SetupSearchPaths(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHLSceneManagerApp::SetupSearchPaths(CHLSceneManagerApp *this)
{
  bool result; // al
  const char *GameInfoPath; // eax

  result = CSteamAppSystemGroup::SetupSearchPaths(
             this,
             pStartingDir: nullptr,
             bOnlyUseStartingDir: false,
             bIsTool: true);
  if ( result )
  {
    GameInfoPath = CSteamAppSystemGroup::GetGameInfoPath(this);
    V_MakeAbsolutePath(pOut: gamedir, outLen: 1024, pPath: GameInfoPath, pStartingDir: nullptr);
    V_AppendSlash(pStr: gamedir, strSize: 1024);
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00409E20
// Name: public: virtual bool CHLSceneManagerApp::PreInit(void)
// Source: json
//------------------------------------------------------------------------------
bool __usercall CHLSceneManagerApp::PreInit@<al>(CHLSceneManagerApp *this@<ecx>, const char *a2@<esi>)
{
  IBaseFileSystem *v3; // eax
  void *(__cdecl *Factory)(const char *, int *); // [esp+24h] [ebp-8h] BYREF
  void *(__cdecl *pFactoryList)(const char *, int *); // [esp+28h] [ebp-4h] BYREF

  MathLib_Init(
    gamma: 2.2,
    texGamma: 2.2,
    brightness: 0.0,
    overbright: 2,
    bAllow3DNow: false,
    bAllowSSE: false,
    bAllowSSE2: false,
    bAllowMMX: false);
  pFactoryList = CAppSystemGroup::GetFactory();
  ConnectTier1Libraries(&pFactoryList, nFactoryCount: 1);
  ConVar_Register(nCVarFlag: 0, pAccessor: nullptr);
  ConnectTier2Libraries(&pFactoryList, nFactoryCount: 1);
  Factory = CAppSystemGroup::GetFactory();
  CSteamApplication::PostShutdown(pFactoryList: &Factory, nFactoryCount: 1);
  filesystem = g_pFullFileSystem;
  if ( g_pFullFileSystem != nullptr )
    v3 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v3 = nullptr;
  g_pFileSystem = v3;
  if ( g_pSoundEmitterSystem != nullptr && g_pVGuiLocalize != nullptr && v3 != nullptr )
  {
    ((void (__stdcall *)(int (__cdecl *)(_DWORD, _DWORD)))g_pFullFileSystem->SetWarningFunc)(a1: _Warning);
    return CHLSceneManagerApp::SetupSearchPaths(this);
  }
  else
  {
    _Error(this: (ISceneTokenProcessor *)&stru_44DE38, a2);
    return false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409F00
// Name: public: virtual void CHLSceneManagerApp::PostShutdown(void)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x00409F20
// Name: public: virtual int CHLSceneManagerApp::Main(void)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
int __usercall CHLSceneManagerApp::Main@<eax>(CHLSceneManagerApp *this@<ecx>, int a2@<ebx>, int a3@<edi>, int a4@<esi>)
{
  CWorkspaceManager *v4; // eax
  char v5; // bl
  int v6; // edi
  int v7; // eax
  int v8; // eax
  unsigned __int8 *v9; // eax
  const char *v10; // esi
  int v11; // eax
  int v12; // eax
  int v13; // esi
  char workspace_name[512]; // [esp+0h] [ebp-204h] BYREF
  CWorkspaceManager *sm; // [esp+200h] [ebp-4h]

  sound->Init(this: sound);
  v4 = (CWorkspaceManager *)operator new(nSize: 0x54u);
  if ( v4 != nullptr )
    sm = CWorkspaceManager::CWorkspaceManager(this: v4);
  else
    sm = nullptr;
  v5 = 0;
  v6 = 1;
  v7 = _CommandLine(a1: a3, a2: a4, a3: a2);
  if ( (*(int (__thiscall **)(int))(*(_DWORD *)v7 + 36))(a1: v7) <= 1 )
    goto LABEL_10;
  do
  {
    v8 = _CommandLine(
           a1: *(_DWORD *)workspace_name,
           a2: *(_DWORD *)&workspace_name[4],
           a3: *(_DWORD *)&workspace_name[8]);
    v9 = (unsigned __int8 *)(*(int (__thiscall **)(int, int))(*(_DWORD *)v8 + 44))(a1: v8, a2: v6);
    v10 = (const char *)v9;
    if ( v5 == 0 )
    {
      strstr(str1: v9, str2: ".vsw");
      if ( v11 != 0 )
      {
        v5 = 1;
        filesystem->FullPathToRelativePath(this: filesystem, a2: v10, a3: workspace_name, a4: 512);
        CWorkspaceManager::AutoLoad(this: sm, workspace: (CWorkspaceManager::RecentFile *)workspace_name);
      }
    }
    ++v6;
    v12 = _CommandLine(
            a1: *(_DWORD *)workspace_name,
            a2: *(_DWORD *)&workspace_name[4],
            a3: *(_DWORD *)&workspace_name[8]);
  }
  while ( v6 < (*(int (__thiscall **)(int))(*(_DWORD *)v12 + 36))(a1: v12) );
  if ( v5 == 0 )
LABEL_10:
    CWorkspaceManager::AutoLoad(this: sm, workspace: nullptr);
  v13 = mx::run();
  sound->Shutdown(this: sound);
  return v13;
}

//------------------------------------------------------------------------------
// Address: 0x0040A510
// Name: public: void CUtlDict<int,unsigned short>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<int,unsigned short>::RemoveAll(CUtlDict<int,unsigned short> *this)
{
  unsigned __int16 i; // si

  for ( i = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != 0xFFFF;
        i = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x0040A570
// Name: _main
// Source: json
//------------------------------------------------------------------------------
int __cdecl main(int argc, const char **argv, const char **envp)
{
  void (__thiscall ***v3)(_DWORD, int, const char **); // eax
  int v4; // esi
  char workingdir[256]; // [esp+108h] [ebp-2DCh] BYREF
  CHLSceneManagerApp sceneManagerApp; // [esp+208h] [ebp-1DCh] BYREF
  CSteamApplication steamApplication; // [esp+374h] [ebp-70h] BYREF

  v3 = (void (__thiscall ***)(_DWORD, int, const char **))_CommandLine();
  (**v3)(a1: v3, a2: argc, a3: argv);
  CoInitialize(pvReserved: nullptr);
  strlen(mx::getApplicationPath());
  mx::init(argc, (char **)argv);
  workingdir[0] = 0;
  Q_getwd(out: workingdir, outSize: 256);
  CSteamAppSystemGroup::CSteamAppSystemGroup(this: &sceneManagerApp, pFileSystem: nullptr, pAppSystemParent: nullptr);
  sceneManagerApp.__vftable = (CHLSceneManagerApp_vtbl *)&CHLSceneManagerApp::`vftable';
  CSteamApplication::CSteamApplication(this: &steamApplication, pAppSystemGroup: &sceneManagerApp);
  v4 = CAppSystemGroup::Run(this: &steamApplication);
  CoUninitialize();
  CUtlDict<int,unsigned short>::RemoveAll(this: &steamApplication.m_SystemDict);
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &steamApplication.m_SystemDict.m_Elements.m_Tree);
  CUtlVector<CFileLoaderThread::SentenceRequest *,CUtlMemory<CFileLoaderThread::SentenceRequest *,int>>::~CUtlVector<CFileLoaderThread::SentenceRequest *,CUtlMemory<CFileLoaderThread::SentenceRequest *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&steamApplication.m_NonAppSystemFactories);
  CUtlVector<CFileLoaderThread::SentenceRequest *,CUtlMemory<CFileLoaderThread::SentenceRequest *,int>>::~CUtlVector<CFileLoaderThread::SentenceRequest *,CUtlMemory<CFileLoaderThread::SentenceRequest *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&steamApplication.m_Systems);
  CUtlVector<CFileLoaderThread::SentenceRequest *,CUtlMemory<CFileLoaderThread::SentenceRequest *,int>>::~CUtlVector<CFileLoaderThread::SentenceRequest *,CUtlMemory<CFileLoaderThread::SentenceRequest *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&steamApplication.m_Modules);
  CUtlDict<int,unsigned short>::RemoveAll(this: &sceneManagerApp.m_SystemDict);
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &sceneManagerApp.m_SystemDict.m_Elements.m_Tree);
  CUtlVector<CFileLoaderThread::SentenceRequest *,CUtlMemory<CFileLoaderThread::SentenceRequest *,int>>::~CUtlVector<CFileLoaderThread::SentenceRequest *,CUtlMemory<CFileLoaderThread::SentenceRequest *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&sceneManagerApp.m_NonAppSystemFactories);
  CUtlVector<CFileLoaderThread::SentenceRequest *,CUtlMemory<CFileLoaderThread::SentenceRequest *,int>>::~CUtlVector<CFileLoaderThread::SentenceRequest *,CUtlMemory<CFileLoaderThread::SentenceRequest *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&sceneManagerApp.m_Systems);
  CUtlVector<CFileLoaderThread::SentenceRequest *,CUtlMemory<CFileLoaderThread::SentenceRequest *,int>>::~CUtlVector<CFileLoaderThread::SentenceRequest *,CUtlMemory<CFileLoaderThread::SentenceRequest *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&sceneManagerApp.m_Modules);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x0041F440
// Name: protected: static void __near * (*CAppSystemGroup::GetFactory(void))(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void *(__cdecl *__cdecl CAppSystemGroup::GetFactory())(const char *, int *)
{
  return AppSystemCreateInterfaceFn;
}
