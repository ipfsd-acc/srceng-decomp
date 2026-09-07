// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/xboxsystem.cpp
// Functions: 49
// ============================================================

#include "engine\xboxsystem.h"

//------------------------------------------------------------------------------
// Address: 0x10002040
// Name: public: virtual int CXboxSystem::SessionLeaveLocal(void __near *,unsigned int,unsigned int const __near *,bool,void __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CXboxSystem::SessionLeaveLocal(
        CEngineSoundServer *this,
        const char *pSample,
        float flVolume,
        int iPitch,
        int flags,
        float soundtime)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101386A0
// Name: public: virtual bool CXboxSystem::DeviceCapacityAdequate(int,unsigned long,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CXboxSystem::DeviceCapacityAdequate(
        CBaseServer *this,
        netadr_s *adr,
        netadr_s *nAuthProtocol,
        const char *szRawCertificate)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101F68A0
// Name: public: virtual int CXboxSystem::GetOverlappedResult(void __near *,unsigned int __near *,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CXboxSystem::GetOverlappedResult(CXboxSystem *this, void *handle, unsigned int *pResultCode, bool bWait)
{
  if ( pResultCode != nullptr )
    *pResultCode = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101F68D0
// Name: public: virtual void CXboxSystem::CloseAllContainers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CXboxSystem::CloseAllContainers(CXboxSystem *this)
{
  unsigned int i; // esi

  for ( i = 0; i < 4; ++i )
    this->CloseContainers(this, a2: i);
}

//------------------------------------------------------------------------------
// Address: 0x101F68F0
// Name: public: virtual unsigned int CXboxSystem::GetContainerOpenResult(int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CXboxSystem::GetContainerOpenResult(CXboxSystem *this, int iController)
{
  this->m_OpenContainerResult[iController] = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101F6910
// Name: private: virtual unsigned int CXboxSystem::CreateUserSettingsContainer(int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CXboxSystem::CreateUserSettingsContainer(
        CSaveRestoreFileSystem *this,
        FSAsyncControl_t__ *hControl,
        bool wait)
{
  return FSASYNC_OK;
}

//------------------------------------------------------------------------------
// Address: 0x101F6920
// Name: public: virtual void CXboxSystem::FinishAllContainerWrites(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CXboxSystem::FinishAllContainerWrites(CXboxSystem *this)
{
  unsigned int i; // esi

  for ( i = 0; i < 4; ++i )
    this->FinishContainerWrites(this, a2: i);
}

//------------------------------------------------------------------------------
// Address: 0x101F6940
// Name: public: virtual bool CXboxSystem::GameHasSavegames(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CXboxSystem::GameHasSavegames(CXboxSystem *this)
{
  char *mod; // esi

  if ( !s_bInitialized )
  {
    mod = host_parms.mod;
    if ( _V_stricmp(s1: host_parms.mod, s2: "left4dead2") == 0 || _V_stricmp(s1: mod, s2: "tf") == 0 )
      s_bHasSavegames = false;
    s_bInitialized = true;
  }
  return s_bHasSavegames;
}

//------------------------------------------------------------------------------
// Address: 0x101F6990
// Name: public: virtual void CXboxSystem::GetModSaveContainerNames(char const __near *,wchar_t const __near * __near *,char const __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CXboxSystem::GetModSaveContainerNames(
        CXboxSystem *this@<ecx>,
        int a2@<esi>,
        const char *pchModName,
        const wchar_t **ppchDisplayName,
        const char **ppchName)
{
  const wchar_t *v5; // eax
  char chFmtString[256]; // [esp+0h] [ebp-100h] BYREF

  if ( g_szModSaveContainerDisplayName[0] != 0 )
  {
    *ppchDisplayName = g_szModSaveContainerDisplayName;
    *ppchName = g_szModSaveContainerName;
  }
  else
  {
    memset(chFmtString, 0, sizeof(chFmtString));
    V_snprintf(pDest: chFmtString, maxLen: 256, pFormat: "#GameUI_Console_%s_Saves", pchModName);
    v5 = (const wchar_t *)((int (__thiscall *)(vgui::ILocalize *, char *, int))g_pVGuiLocalize->Find)(
                            a1: g_pVGuiLocalize,
                            a2: chFmtString,
                            a3: a2);
    if ( v5 == nullptr || *v5 == 0 )
      v5 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: "#GameUI_Console_SaveGames");
    if ( v5 == nullptr || *v5 == 0 )
      v5 = L"SAVES";
    V_wcsncpy(pDest: g_szModSaveContainerDisplayName, pSrc: v5, maxLenInBytes: 256);
    V_snprintf(pDest: g_szModSaveContainerName, maxLen: 42, pFormat: "%s_saves", pchModName);
    *ppchDisplayName = g_szModSaveContainerDisplayName;
    *ppchName = g_szModSaveContainerName;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F6A80
// Name: public: virtual unsigned long CXboxSystem::DiscoverUserData(unsigned long,char const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CXboxSystem::DiscoverUserData(CXboxSystem *this, unsigned int nUserID, const char *pModName)
{
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x101F6A90
// Name: public: virtual unsigned int CXboxSystem::GetContainerRemainingSpace(unsigned long)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CXboxSystem::GetContainerRemainingSpace(CXboxSystem *this, unsigned int nStorageID)
{
  return 0x40000000;
}

//------------------------------------------------------------------------------
// Address: 0x101F6AA0
// Name: public: virtual int CXboxSystem::UserSetContext(unsigned int,struct _XUSER_CONTEXT const __near &,bool,void __near * __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::IBorder *__thiscall CXboxSystem::UserSetContext(
        vgui::RadioButton *this,
        bool depressed,
        bool armed,
        bool selected,
        bool keyfocus)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101F6AB0
// Name: public: virtual int CXboxSystem::CreateSession(unsigned int,unsigned int,unsigned int,unsigned int,unsigned __int64 __near *,void __near *,void __near * __near *,bool,void __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CXboxSystem::CreateSession(
        CXboxSystem *this,
        unsigned int nFlags,
        unsigned int nUserIdx,
        unsigned int nMaxPublicSlots,
        unsigned int nMaxPrivateSlots,
        unsigned __int64 *pNonce,
        unsigned __int64 *pSessionInfo,
        void **pSessionHandle,
        bool bAsync,
        void **pAsyncHandle)
{
  return 1260;
}

//------------------------------------------------------------------------------
// Address: 0x101F6AC0
// Name: public: virtual unsigned int CXboxSystem::SessionSearch(unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,struct _XUSER_PROPERTY __near *,struct _XUSER_CONTEXT __near *,unsigned int __near *,struct _XSESSION_SEARCHRESULT_HEADER __near *,bool,void __near * __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CXboxSystem::SessionSearch(
        CXboxSystem *this,
        unsigned int nProcedureIndex,
        unsigned int nUserIndex,
        unsigned int nNumResults,
        unsigned int nNumUsers,
        unsigned int nNumProperties,
        unsigned int nNumContexts,
        _XUSER_PROPERTY *pSearchProperties,
        _XUSER_PROPERTY *pSearchContexts,
        _XUSER_CONTEXT *pcbResultsBuffer,
        _XSESSION_SEARCHRESULT_HEADER *pSearchResults,
        bool bAsync,
        void **pAsyncHandle)
{
  return 1260;
}

//------------------------------------------------------------------------------
// Address: 0x101F6AD0
// Name: public: virtual unsigned int CXboxSystem::SessionStart(void __near *,unsigned int,bool,void __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CXboxSystem::SessionStart(
        CXboxSystem *this,
        unsigned int userIndex,
        void **ppBuffer,
        bool bAsync,
        void **pAsyncHandle)
{
  return 1260;
}

//------------------------------------------------------------------------------
// Address: 0x101F6AE0
// Name: public: virtual int CXboxSystem::SessionJoinRemote(void __near *,unsigned int,unsigned __int64 const __near *,bool const __near *,bool,void __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CXboxSystem::SessionJoinRemote(
        CXboxSystem *this,
        void *hSession,
        void *nUserCount,
        const unsigned __int64 *pXuids,
        const bool *pPrivateSlots,
        bool bAsync,
        void **pAsyncHandle)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101F6AF0
// Name: public: virtual int CXboxSystem::AwardAchievement(unsigned int,unsigned int,void __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CXboxSystem::AwardAchievement(
        CXboxSystem *this,
        unsigned int nUserIdx,
        unsigned int nAwardId,
        void **ppOverlappedResult)
{
  return 1260;
}

//------------------------------------------------------------------------------
// Address: 0x101F6B00
// Name: public: virtual int CXboxSystem::WriteStats(void __near *,unsigned __int64,unsigned int,void __near *,bool,void __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CXboxSystem::WriteStats(
        CXboxSystem *this,
        unsigned int nStartingRank,
        unsigned int nNumRows,
        unsigned int nNumSpecs,
        unsigned int pSpecs,
        void **ppResults,
        bool bAsync,
        void **pAsyncHandle)
{
  return 1260;
}

//------------------------------------------------------------------------------
// Address: 0x101F6B10
// Name: public: virtual int CXboxSystem::EnumerateStatsByXuid(unsigned __int64,unsigned int,unsigned int,void __near *,void __near * __near *,bool,void __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CXboxSystem::EnumerateStatsByXuid(
        CXboxSystem *this,
        unsigned __int64 nUserId,
        unsigned int nNumRows,
        unsigned int nNumSpecs,
        unsigned int pSpecs,
        void **ppResults,
        bool bAsync,
        void **pAsyncHandle)
{
  return 1260;
}

//------------------------------------------------------------------------------
// Address: 0x101F6B20
// Name: public: virtual int CXboxSystem::EnumerateAchievements(unsigned int,unsigned __int64,unsigned int,unsigned int,void __near *,unsigned int,bool,void __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CXboxSystem::EnumerateAchievements(
        CXboxSystem *this,
        unsigned int nUserIdx,
        unsigned __int64 xuid,
        unsigned int nStartingIdx,
        unsigned int nCount,
        unsigned int pBuffer,
        void *nBufferBytes,
        bool bAsync,
        void **pAsyncHandle)
{
  _Error(
    a1: "This function is obsolete and should not be used!\n"
    "Return code cannot be an error code and number of results at the same time!\n");
  return 1313;
}

//------------------------------------------------------------------------------
// Address: 0x101F6B40
// Name: public: virtual float CXboxSystem::GetArcadeRemainingTrialTime(int)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CXboxSystem::GetArcadeRemainingTrialTime(CXboxSystem *this, int nSlot)
{
  SplitScreenConVarRef trialTime; // [esp+0h] [ebp-10h] BYREF

  SplitScreenConVarRef::SplitScreenConVarRef(this: &trialTime, pName: "xbox_arcade_remaining_trial_time");
  return trialTime.m_Info[nSlot].m_pConVarState->m_Value.m_fValue;
}

//------------------------------------------------------------------------------
// Address: 0x101F6B80
// Name: public: virtual int CXboxSystem::Io_HasOverlappedIoCompleted(struct _XOVERLAPPED __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CXboxSystem::Io_HasOverlappedIoCompleted(CXboxSystem *this, _XOVERLAPPED *pOverlapped)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101F6B90
// Name: public: virtual int CXboxSystem::NetRandom(unsigned char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __thiscall CXboxSystem::NetRandom(CXboxSystem *this, unsigned __int8 *pb, unsigned int numBytes)
{
  unsigned __int8 *v3; // esi

  v3 = pb;
  if ( pb == nullptr )
    return 0;
  if ( pb >= &pb[numBytes] )
    return 0;
  do
    *v3++ = _RandomInt((IUniformRandomStream *)this, a2: 0, a3: 255);
  while ( v3 < &pb[numBytes] );
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101F6BE0
// Name: public: virtual unsigned long CXboxSystem::NetGetTitleXnAddr(struct XNADDR __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CXboxSystem::NetGetTitleXnAddr(CXboxSystem *this, XNADDR *pxna)
{
  if ( pxna != nullptr )
  {
    pxna->ina.S_un.S_addr = 0;
    pxna->inaOnline.S_un.S_addr = 0;
    *(_DWORD *)&pxna->wPortOnline = 0;
    *(_DWORD *)&pxna->abEnet[2] = 0;
    *(_DWORD *)pxna->abOnline = 0;
    *(_DWORD *)&pxna->abOnline[4] = 0;
    *(_DWORD *)&pxna->abOnline[8] = 0;
    *(_DWORD *)&pxna->abOnline[12] = 0;
    *(_DWORD *)&pxna->abOnline[16] = 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101F6C10
// Name: public: virtual int CXboxSystem::NetXnAddrToMachineId(struct XNADDR const __near *,unsigned __int64 __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CXboxSystem::NetXnAddrToMachineId(
        CXboxSystem *this,
        const XNADDR *pxnaddr,
        unsigned __int64 *pqwMachineId)
{
  if ( pqwMachineId != nullptr )
    *pqwMachineId = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101F6C30
// Name: public: virtual int CXboxSystem::NetInAddrToXnAddr(struct in_addr,struct XNADDR __near *,struct XNKID __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CXboxSystem::NetInAddrToXnAddr(CXboxSystem *this, in_addr ina, XNADDR *pxna, XNKID *pxnkid)
{
  if ( pxnkid != nullptr )
  {
    *(_DWORD *)pxnkid->ab = 0;
    *(_DWORD *)&pxnkid->ab[4] = 0;
  }
  if ( pxna != nullptr )
  {
    pxna->inaOnline.S_un.S_addr = 0;
    *(_DWORD *)&pxna->wPortOnline = 0;
    *(_DWORD *)&pxna->abEnet[2] = 0;
    *(_DWORD *)pxna->abOnline = 0;
    *(_DWORD *)&pxna->abOnline[4] = 0;
    *(_DWORD *)&pxna->abOnline[8] = 0;
    *(_DWORD *)&pxna->abOnline[12] = 0;
    *(_DWORD *)&pxna->abOnline[16] = 0;
    pxna->ina = ina;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101F6C70
// Name: public: virtual int CXboxSystem::NetXnAddrToInAddr(struct XNADDR const __near *,struct XNKID const __near *,struct in_addr __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CXboxSystem::NetXnAddrToInAddr(
        CXboxSystem *this,
        const XNADDR *pxna,
        const XNKID *pxnkid,
        in_addr *pina)
{
  if ( pina != nullptr )
  {
    if ( pxna != nullptr )
    {
      *pina = pxna->ina;
      return 0;
    }
    pina->S_un.S_addr = 0;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101F6CB0
// Name: public: virtual CXboxSystem::~CXboxSystem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CXboxSystem::~CXboxSystem(CXboxSystem *this)
{
  AsyncResult_s *v1; // eax
  AsyncResult_s *i; // ecx
  int v3; // edi
  void (__thiscall *Free_2)(IMemAlloc *, void *); // edx
  AsyncResult_s *v5; // esi

  v1 = g_pAsyncResultHead;
  this->__vftable = (CXboxSystem_vtbl *)&CXboxSystem::`vftable';
  for ( i = v1; i != nullptr; i = i->pNext )
    ;
  v3 = 0;
  if ( v1 != nullptr )
  {
    do
    {
      Free_2 = _g_pMemAlloc->Free_2;
      v5 = v1;
      g_pAsyncResultHead = v1->pNext;
      Free_2(this: _g_pMemAlloc, a2: v1->pInputData);
      free(pMem: v5);
      v1 = g_pAsyncResultHead;
      ++v3;
    }
    while ( g_pAsyncResultHead != nullptr );
    if ( v3 != 0 )
      _Warning(a1: "Released %d async handles\n", v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10287E60
// Name: public: virtual int CXboxSystem::UserGetContext(unsigned int,unsigned int,unsigned int __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CXboxSystem::UserGetContext(CDragDropHelperPanel *this, int x, int y, bool traversePopups)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1031EC80
// Name: _dynamic_initializer_for__xbox_arcade_title_unlocked__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__xbox_arcade_title_unlocked__()
{
  ConVar::ConVar(
    this: &xbox_arcade_title_unlocked,
    pName: "xbox_arcade_title_unlocked",
    pDefaultValue: "1",
    flags: 2,
    pHelpString: "debug unlocking arcade title");
  return atexit(func: dynamic_atexit_destructor_for__xbox_arcade_title_unlocked__);
}

//------------------------------------------------------------------------------
// Address: 0x1031ECB0
// Name: _dynamic_initializer_for__xbox_arcade_remaining_trial_time__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__xbox_arcade_remaining_trial_time__()
{
  ConVar::ConVar(
    this: &xbox_arcade_remaining_trial_time,
    pName: "xbox_arcade_remaining_trial_time",
    pDefaultValue: "2700.0",
    flags: 16809986,
    pHelpString: "time remaining in trial mode");
  return atexit(func: dynamic_atexit_destructor_for__xbox_arcade_remaining_trial_time__);
}

//------------------------------------------------------------------------------
// Address: 0x10327070
// Name: _dynamic_atexit_destructor_for__xbox_arcade_title_unlocked__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__xbox_arcade_title_unlocked__()
{
  ConVar::~ConVar(this: &xbox_arcade_title_unlocked);
}

//------------------------------------------------------------------------------
// Address: 0x10327080
// Name: _dynamic_atexit_destructor_for__xbox_arcade_remaining_trial_time__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__xbox_arcade_remaining_trial_time__()
{
  ConVar::~ConVar(this: &xbox_arcade_remaining_trial_time);
}

//------------------------------------------------------------------------------
// Address: 0x1031ECE0
// Name: _dynamic_initializer_for__lasterrorZ__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__lasterrorZ__()
{
  GenericThreadLocals::CThreadLocalBase::CThreadLocalBase(this: &lasterrorZ);
  return atexit(func: dynamic_atexit_destructor_for__lasterrorZ__);
}

//------------------------------------------------------------------------------
// Address: 0x1031ED00
// Name: _dynamic_initializer_for__g_HunkMemoryStack__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_HunkMemoryStack__()
{
  CMemoryStack::CMemoryStack(this: &g_HunkMemoryStack);
  return atexit(func: dynamic_atexit_destructor_for__g_HunkMemoryStack__);
}

//------------------------------------------------------------------------------
// Address: 0x1031ED20
// Name: _dynamic_initializer_for__hunk_track_allocation_types__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__hunk_track_allocation_types__()
{
  ConVar::ConVar(
    this: &hunk_track_allocation_types,
    pName: "hunk_track_allocation_types",
    pDefaultValue: "1",
    flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__hunk_track_allocation_types__);
}

//------------------------------------------------------------------------------
// Address: 0x1031ED50
// Name: _dynamic_initializer_for__g_HunkAllocationsByName__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_HunkAllocationsByName__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_HunkAllocationsByName__);
}

//------------------------------------------------------------------------------
// Address: 0x1031ED60
// Name: _dynamic_initializer_for__hunk_print_allocations_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__hunk_print_allocations_command__()
{
  ConCommand::ConCommand(
    this: &hunk_print_allocations_command,
    pName: "hunk_print_allocations",
    callback: hunk_print_allocations,
    pHelpString: defaultValue,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__hunk_print_allocations_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031ED90
// Name: _dynamic_initializer_for__g_EngineTool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_EngineTool__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_EngineTool__);
}

//------------------------------------------------------------------------------
// Address: 0x1031EDA0
// Name: _dynamic_initializer_for____g_CreateCEngineToolIEngineTool_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCEngineToolIEngineTool_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCEngineToolIEngineTool_reg,
           fn: (void *(__cdecl *)())_CreateCEngineToolIEngineToolFramework_interface,
           pName: "VENGINETOOL003");
}

//------------------------------------------------------------------------------
// Address: 0x1031EDC0
// Name: _dynamic_initializer_for____g_CreateCEngineToolIEngineToolFramework_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCEngineToolIEngineToolFramework_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCEngineToolIEngineToolFramework_reg,
           fn: (void *(__cdecl *)())_CreateCEngineToolIEngineToolFramework_interface,
           pName: "VENGINETOOLFRAMEWORK003");
}

//------------------------------------------------------------------------------
// Address: 0x1031EDE0
// Name: _dynamic_initializer_for__g_ToolFrameworkInternal__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ToolFrameworkInternal__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_ToolFrameworkInternal__);
}

//------------------------------------------------------------------------------
// Address: 0x1031EDF0
// Name: _dynamic_initializer_for__ToolUnload__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ToolUnload__()
{
  ConCommand::ConCommand(
    this: &ToolUnload,
    pName: "toolunload",
    callback: (void (__cdecl *)())Tool_Unload_f,
    pHelpString: "Unload a tool.",
    flags: 0,
    completionFunc: g_ToolUnload_CompletionFunc);
  return atexit(func: dynamic_atexit_destructor_for__ToolUnload__);
}

//------------------------------------------------------------------------------
// Address: 0x1031EE20
// Name: _dynamic_initializer_for__ToolLoad__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ToolLoad__()
{
  ConCommand::ConCommand(
    this: &ToolLoad,
    pName: "toolload",
    callback: (void (__cdecl *)())Tool_Load_f,
    pHelpString: "Load a tool.",
    flags: 0,
    completionFunc: (int (__cdecl *)(const char *, char (*)[64]))g_ToolLoad_CompletionFunc);
  return atexit(func: dynamic_atexit_destructor_for__ToolLoad__);
}

//------------------------------------------------------------------------------
// Address: 0x1031EE50
// Name: _dynamic_initializer_for____g_CreateCToolFrameworkInternalIToolFrameworkInternal_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCToolFrameworkInternalIToolFrameworkInternal_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCToolFrameworkInternalIToolFrameworkInternal_reg,
           fn: (void *(__cdecl *)())_CreateCToolFrameworkInternalIToolFrameworkInternal_interface,
           pName: "VTOOLFRAMEWORKVERSION002");
}

//------------------------------------------------------------------------------
// Address: 0x1031EE70
// Name: _dynamic_initializer_for____g_CClientEngineTools_singleton__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____g_CClientEngineTools_singleton__()
{
  return atexit(func: dynamic_atexit_destructor_for____g_CClientEngineTools_singleton__);
}

//------------------------------------------------------------------------------
// Address: 0x1031EE80
// Name: _dynamic_initializer_for____g_CreateCClientEngineToolsIClientEngineTools_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCClientEngineToolsIClientEngineTools_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCClientEngineToolsIClientEngineTools_reg,
           fn: (void *(__cdecl *)())_CreateCClientEngineToolsIClientEngineTools_interface,
           pName: "VCLIENTENGINETOOLS001");
}

//------------------------------------------------------------------------------
// Address: 0x1031EEA0
// Name: _dynamic_initializer_for____g_CServerEngineTools_singleton__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____g_CServerEngineTools_singleton__()
{
  return atexit(func: dynamic_atexit_destructor_for____g_CServerEngineTools_singleton__);
}

//------------------------------------------------------------------------------
// Address: 0x1031EEB0
// Name: _dynamic_initializer_for____g_CreateCServerEngineToolsIServerEngineTools_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCServerEngineToolsIServerEngineTools_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCServerEngineToolsIServerEngineTools_reg,
           fn: (void *(__cdecl *)())_CreateCServerEngineToolsIServerEngineTools_interface,
           pName: "VSERVERENGINETOOLS001");
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10035A70
// Name: public: virtual int CXboxSystem::UserGetContext(unsigned int,unsigned int,unsigned int __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CXboxSystem::UserGetContext(CDragDropHelperPanel *this, int x, int y, bool traversePopups)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10035E90
// Name: public: virtual int CXboxSystem::UserSetContext(unsigned int,struct _XUSER_CONTEXT const __near &,bool,void __near * __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::IBorder *__thiscall CXboxSystem::UserSetContext(
        vgui::RadioButton *this,
        bool depressed,
        bool armed,
        bool selected,
        bool keyfocus)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101387B0
// Name: public: virtual bool CXboxSystem::DeviceCapacityAdequate(int,unsigned long,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CXboxSystem::DeviceCapacityAdequate(
        CBaseServer *this,
        netadr_s *adr,
        netadr_s *nAuthProtocol,
        const char *szRawCertificate)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101CED10
// Name: private: virtual unsigned int CXboxSystem::CreateUserSettingsContainer(int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
FSAsyncStatus_t __thiscall CXboxSystem::CreateUserSettingsContainer(
        CSaveRestoreFileSystem *this,
        FSAsyncControl_t__ *hControl,
        bool wait)
{
  return FSASYNC_OK;
}

//------------------------------------------------------------------------------
// Address: 0x101F6B60
// Name: public: virtual void CXboxSystem::CloseAllContainers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CXboxSystem::CloseAllContainers(CXboxSystem *this)
{
  unsigned int i; // esi

  for ( i = 0; i < 4; ++i )
    this->CloseContainers(this, a2: i);
}

//------------------------------------------------------------------------------
// Address: 0x101F6BA0
// Name: public: virtual void CXboxSystem::FinishAllContainerWrites(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CXboxSystem::FinishAllContainerWrites(CXboxSystem *this)
{
  unsigned int i; // esi

  for ( i = 0; i < 4; ++i )
    this->FinishContainerWrites(this, a2: i);
}

//------------------------------------------------------------------------------
// Address: 0x101F6BC0
// Name: public: virtual bool CXboxSystem::GameHasSavegames(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CXboxSystem::GameHasSavegames(CXboxSystem *this)
{
  char *mod; // esi

  if ( !s_bInitialized )
  {
    mod = host_parms.mod;
    if ( _V_stricmp(s1: host_parms.mod, s2: "left4dead2") == 0 || _V_stricmp(s1: mod, s2: "tf") == 0 )
      s_bHasSavegames = false;
    s_bInitialized = true;
  }
  return s_bHasSavegames;
}

//------------------------------------------------------------------------------
// Address: 0x101F6D00
// Name: public: virtual unsigned long CXboxSystem::DiscoverUserData(unsigned long,char const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CXboxSystem::DiscoverUserData(CXboxSystem *this, unsigned int nUserID, const char *pModName)
{
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x101F6D10
// Name: public: virtual unsigned int CXboxSystem::GetContainerRemainingSpace(unsigned long)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CXboxSystem::GetContainerRemainingSpace(CXboxSystem *this, unsigned int nStorageID)
{
  return 0x40000000;
}

//------------------------------------------------------------------------------
// Address: 0x101F6D20
// Name: public: virtual int CXboxSystem::CreateSession(unsigned int,unsigned int,unsigned int,unsigned int,unsigned __int64 __near *,void __near *,void __near * __near *,bool,void __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CXboxSystem::CreateSession(
        CXboxSystem *this,
        unsigned int nFlags,
        unsigned int nUserIdx,
        unsigned int nMaxPublicSlots,
        unsigned int nMaxPrivateSlots,
        unsigned __int64 *pNonce,
        unsigned __int64 *pSessionInfo,
        void **pSessionHandle,
        bool bAsync,
        void **pAsyncHandle)
{
  return 1260;
}

//------------------------------------------------------------------------------
// Address: 0x101F6D30
// Name: public: virtual unsigned int CXboxSystem::SessionSearch(unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,struct _XUSER_PROPERTY __near *,struct _XUSER_CONTEXT __near *,unsigned int __near *,struct _XSESSION_SEARCHRESULT_HEADER __near *,bool,void __near * __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CXboxSystem::SessionSearch(
        CXboxSystem *this,
        unsigned int nProcedureIndex,
        unsigned int nUserIndex,
        unsigned int nNumResults,
        unsigned int nNumUsers,
        unsigned int nNumProperties,
        unsigned int nNumContexts,
        _XUSER_PROPERTY *pSearchProperties,
        _XUSER_PROPERTY *pSearchContexts,
        _XUSER_CONTEXT *pcbResultsBuffer,
        _XSESSION_SEARCHRESULT_HEADER *pSearchResults,
        bool bAsync,
        void **pAsyncHandle)
{
  return 1260;
}

//------------------------------------------------------------------------------
// Address: 0x101F6D40
// Name: public: virtual int CXboxSystem::SessionJoinRemote(void __near *,unsigned int,unsigned __int64 const __near *,bool const __near *,bool,void __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CXboxSystem::SessionJoinRemote(
        CXboxSystem *this,
        void *hSession,
        void *nUserCount,
        const unsigned __int64 *pXuids,
        const bool *pPrivateSlots,
        bool bAsync,
        void **pAsyncHandle)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101F6D50
// Name: public: virtual int CXboxSystem::SessionLeaveLocal(void __near *,unsigned int,unsigned int const __near *,bool,void __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CXboxSystem::SessionLeaveLocal(
        CEngineSoundServer *this,
        const char *pSample,
        float flVolume,
        int iPitch,
        int flags,
        float soundtime)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101F6D60
// Name: public: virtual unsigned int CXboxSystem::SessionStart(void __near *,unsigned int,bool,void __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CXboxSystem::SessionStart(
        CXboxSystem *this,
        unsigned int userIndex,
        void **ppBuffer,
        bool bAsync,
        void **pAsyncHandle)
{
  return 1260;
}

//------------------------------------------------------------------------------
// Address: 0x101F6D70
// Name: public: virtual int CXboxSystem::WriteStats(void __near *,unsigned __int64,unsigned int,void __near *,bool,void __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CXboxSystem::WriteStats(
        CXboxSystem *this,
        unsigned int nStartingRank,
        unsigned int nNumRows,
        unsigned int nNumSpecs,
        unsigned int pSpecs,
        void **ppResults,
        bool bAsync,
        void **pAsyncHandle)
{
  return 1260;
}

//------------------------------------------------------------------------------
// Address: 0x101F6D80
// Name: public: virtual int CXboxSystem::AwardAchievement(unsigned int,unsigned int,void __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CXboxSystem::AwardAchievement(
        CXboxSystem *this,
        unsigned int nUserIdx,
        unsigned int nAwardId,
        void **ppOverlappedResult)
{
  return 1260;
}

//------------------------------------------------------------------------------
// Address: 0x101F6D90
// Name: public: virtual int CXboxSystem::EnumerateStatsByXuid(unsigned __int64,unsigned int,unsigned int,void __near *,void __near * __near *,bool,void __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CXboxSystem::EnumerateStatsByXuid(
        CXboxSystem *this,
        unsigned __int64 nUserId,
        unsigned int nNumRows,
        unsigned int nNumSpecs,
        unsigned int pSpecs,
        void **ppResults,
        bool bAsync,
        void **pAsyncHandle)
{
  return 1260;
}

//------------------------------------------------------------------------------
// Address: 0x101F6DA0
// Name: public: virtual int CXboxSystem::EnumerateAchievements(unsigned int,unsigned __int64,unsigned int,unsigned int,void __near *,unsigned int,bool,void __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CXboxSystem::EnumerateAchievements(
        CXboxSystem *this,
        unsigned int nUserIdx,
        unsigned __int64 xuid,
        unsigned int nStartingIdx,
        unsigned int nCount,
        unsigned int pBuffer,
        void *nBufferBytes,
        bool bAsync,
        void **pAsyncHandle)
{
  _Error(
    a1: "This function is obsolete and should not be used!\n"
    "Return code cannot be an error code and number of results at the same time!\n");
  return 1313;
}

//------------------------------------------------------------------------------
// Address: 0x101F6DC0
// Name: public: virtual float CXboxSystem::GetArcadeRemainingTrialTime(int)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CXboxSystem::GetArcadeRemainingTrialTime(CXboxSystem *this, int nSlot)
{
  SplitScreenConVarRef trialTime; // [esp+0h] [ebp-10h] BYREF

  SplitScreenConVarRef::SplitScreenConVarRef(this: &trialTime, pName: "xbox_arcade_remaining_trial_time");
  return trialTime.m_Info[nSlot].m_pConVarState->m_Value.m_fValue;
}

//------------------------------------------------------------------------------
// Address: 0x101F6DF0
// Name: public: virtual int CXboxSystem::Io_HasOverlappedIoCompleted(struct _XOVERLAPPED __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CXboxSystem::Io_HasOverlappedIoCompleted(CXboxSystem *this, _XOVERLAPPED *pOverlapped)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101F6E00
// Name: public: virtual int CXboxSystem::NetRandom(unsigned char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __thiscall CXboxSystem::NetRandom(CXboxSystem *this, unsigned __int8 *pb, unsigned int numBytes)
{
  unsigned __int8 *v3; // esi

  v3 = pb;
  if ( pb == nullptr )
    return 0;
  if ( pb >= &pb[numBytes] )
    return 0;
  do
    *v3++ = _RandomInt((IUniformRandomStream *)this, a2: 0, a3: 255);
  while ( v3 < &pb[numBytes] );
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101F6E50
// Name: public: virtual unsigned long CXboxSystem::NetGetTitleXnAddr(struct XNADDR __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CXboxSystem::NetGetTitleXnAddr(CXboxSystem *this, XNADDR *pxna)
{
  if ( pxna != nullptr )
  {
    pxna->ina.S_un.S_addr = 0;
    pxna->inaOnline.S_un.S_addr = 0;
    *(_DWORD *)&pxna->wPortOnline = 0;
    *(_DWORD *)&pxna->abEnet[2] = 0;
    *(_DWORD *)pxna->abOnline = 0;
    *(_DWORD *)&pxna->abOnline[4] = 0;
    *(_DWORD *)&pxna->abOnline[8] = 0;
    *(_DWORD *)&pxna->abOnline[12] = 0;
    *(_DWORD *)&pxna->abOnline[16] = 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101F6E80
// Name: public: virtual int CXboxSystem::NetXnAddrToMachineId(struct XNADDR const __near *,unsigned __int64 __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CXboxSystem::NetXnAddrToMachineId(
        CXboxSystem *this,
        const XNADDR *pxnaddr,
        unsigned __int64 *pqwMachineId)
{
  if ( pqwMachineId != nullptr )
    *pqwMachineId = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101F6EA0
// Name: public: virtual int CXboxSystem::NetInAddrToXnAddr(struct in_addr,struct XNADDR __near *,struct XNKID __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CXboxSystem::NetInAddrToXnAddr(CXboxSystem *this, in_addr ina, XNADDR *pxna, XNKID *pxnkid)
{
  if ( pxnkid != nullptr )
  {
    *(_DWORD *)pxnkid->ab = 0;
    *(_DWORD *)&pxnkid->ab[4] = 0;
  }
  if ( pxna != nullptr )
  {
    pxna->inaOnline.S_un.S_addr = 0;
    *(_DWORD *)&pxna->wPortOnline = 0;
    *(_DWORD *)&pxna->abEnet[2] = 0;
    *(_DWORD *)pxna->abOnline = 0;
    *(_DWORD *)&pxna->abOnline[4] = 0;
    *(_DWORD *)&pxna->abOnline[8] = 0;
    *(_DWORD *)&pxna->abOnline[12] = 0;
    *(_DWORD *)&pxna->abOnline[16] = 0;
    pxna->ina = ina;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101F6EE0
// Name: public: virtual int CXboxSystem::NetXnAddrToInAddr(struct XNADDR const __near *,struct XNKID const __near *,struct in_addr __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CXboxSystem::NetXnAddrToInAddr(
        CXboxSystem *this,
        const XNADDR *pxna,
        const XNKID *pxnkid,
        in_addr *pina)
{
  if ( pina != nullptr )
  {
    if ( pxna != nullptr )
    {
      *pina = pxna->ina;
      return 0;
    }
    pina->S_un.S_addr = 0;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101F6F10
// Name: public: virtual CXboxSystem::~CXboxSystem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CXboxSystem::~CXboxSystem(CXboxSystem *this)
{
  AsyncResult_s *v1; // eax
  AsyncResult_s *i; // ecx
  int v3; // edi
  void (__thiscall *Free_2)(IMemAlloc *, void *); // edx
  AsyncResult_s *v5; // esi

  v1 = g_pAsyncResultHead;
  this->__vftable = (CXboxSystem_vtbl *)&CXboxSystem::`vftable';
  for ( i = v1; i != nullptr; i = i->pNext )
    ;
  v3 = 0;
  if ( v1 != nullptr )
  {
    do
    {
      Free_2 = _g_pMemAlloc->Free_2;
      v5 = v1;
      g_pAsyncResultHead = v1->pNext;
      Free_2(this: _g_pMemAlloc, a2: v1->pInputData);
      free(pMem: v5);
      v1 = g_pAsyncResultHead;
      ++v3;
    }
    while ( g_pAsyncResultHead != nullptr );
    if ( v3 != 0 )
      _Warning(a1: "Released %d async handles\n", v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1031EE60
// Name: _dynamic_initializer_for__xbox_arcade_title_unlocked__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__xbox_arcade_title_unlocked__()
{
  ConVar::ConVar(
    this: &xbox_arcade_title_unlocked,
    pName: "xbox_arcade_title_unlocked",
    pDefaultValue: "1",
    flags: 2,
    pHelpString: "debug unlocking arcade title");
  return atexit(func: dynamic_atexit_destructor_for__xbox_arcade_title_unlocked__);
}

//------------------------------------------------------------------------------
// Address: 0x1031EE90
// Name: _dynamic_initializer_for__xbox_arcade_remaining_trial_time__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__xbox_arcade_remaining_trial_time__()
{
  ConVar::ConVar(
    this: &xbox_arcade_remaining_trial_time,
    pName: "xbox_arcade_remaining_trial_time",
    pDefaultValue: "2700.0",
    flags: 16809986,
    pHelpString: "time remaining in trial mode");
  return atexit(func: dynamic_atexit_destructor_for__xbox_arcade_remaining_trial_time__);
}

//------------------------------------------------------------------------------
// Address: 0x10327260
// Name: _dynamic_atexit_destructor_for__xbox_arcade_title_unlocked__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__xbox_arcade_title_unlocked__()
{
  ConVar::~ConVar(this: &xbox_arcade_title_unlocked);
}

//------------------------------------------------------------------------------
// Address: 0x10327270
// Name: _dynamic_atexit_destructor_for__xbox_arcade_remaining_trial_time__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__xbox_arcade_remaining_trial_time__()
{
  ConVar::~ConVar(this: &xbox_arcade_remaining_trial_time);
}

//------------------------------------------------------------------------------
// Address: 0x1031EEC0
// Name: _dynamic_initializer_for__lasterrorZ__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__lasterrorZ__()
{
  GenericThreadLocals::CThreadLocalBase::CThreadLocalBase(this: &lasterrorZ);
  return atexit(func: dynamic_atexit_destructor_for__lasterrorZ__);
}

//------------------------------------------------------------------------------
// Address: 0x1031EEE0
// Name: _dynamic_initializer_for__g_HunkMemoryStack__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_HunkMemoryStack__()
{
  CMemoryStack::CMemoryStack(this: &g_HunkMemoryStack);
  return atexit(func: dynamic_atexit_destructor_for__g_HunkMemoryStack__);
}

//------------------------------------------------------------------------------
// Address: 0x1031EF00
// Name: _dynamic_initializer_for__hunk_track_allocation_types__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__hunk_track_allocation_types__()
{
  ConVar::ConVar(
    this: &hunk_track_allocation_types,
    pName: "hunk_track_allocation_types",
    pDefaultValue: "1",
    flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__hunk_track_allocation_types__);
}

//------------------------------------------------------------------------------
// Address: 0x1031EF30
// Name: _dynamic_initializer_for__g_HunkAllocationsByName__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_HunkAllocationsByName__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_HunkAllocationsByName__);
}

//------------------------------------------------------------------------------
// Address: 0x1031EF40
// Name: _dynamic_initializer_for__hunk_print_allocations_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__hunk_print_allocations_command__()
{
  ConCommand::ConCommand(
    this: &hunk_print_allocations_command,
    pName: "hunk_print_allocations",
    callback: hunk_print_allocations,
    pHelpString: defaultValue,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__hunk_print_allocations_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031EF70
// Name: _dynamic_initializer_for__g_EngineTool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_EngineTool__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_EngineTool__);
}

//------------------------------------------------------------------------------
// Address: 0x1031EF80
// Name: _dynamic_initializer_for____g_CreateCEngineToolIEngineTool_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCEngineToolIEngineTool_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCEngineToolIEngineTool_reg,
           fn: (void *(__cdecl *)())_CreateCEngineToolIEngineToolFramework_interface,
           pName: "VENGINETOOL003");
}

//------------------------------------------------------------------------------
// Address: 0x1031EFA0
// Name: _dynamic_initializer_for____g_CreateCEngineToolIEngineToolFramework_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCEngineToolIEngineToolFramework_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCEngineToolIEngineToolFramework_reg,
           fn: (void *(__cdecl *)())_CreateCEngineToolIEngineToolFramework_interface,
           pName: "VENGINETOOLFRAMEWORK003");
}

//------------------------------------------------------------------------------
// Address: 0x1031EFC0
// Name: _dynamic_initializer_for__g_ToolFrameworkInternal__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ToolFrameworkInternal__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_ToolFrameworkInternal__);
}

//------------------------------------------------------------------------------
// Address: 0x1031EFD0
// Name: _dynamic_initializer_for__ToolUnload__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ToolUnload__()
{
  ConCommand::ConCommand(
    this: &ToolUnload,
    pName: "toolunload",
    callback: Tool_Unload_f,
    pHelpString: "Unload a tool.",
    flags: 0,
    completionFunc: g_ToolUnload_CompletionFunc);
  return atexit(func: dynamic_atexit_destructor_for__ToolUnload__);
}

//------------------------------------------------------------------------------
// Address: 0x1031F000
// Name: _dynamic_initializer_for__ToolLoad__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ToolLoad__()
{
  ConCommand::ConCommand(
    this: &ToolLoad,
    pName: "toolload",
    callback: Tool_Load_f,
    pHelpString: "Load a tool.",
    flags: 0,
    completionFunc: g_ToolLoad_CompletionFunc);
  return atexit(func: dynamic_atexit_destructor_for__ToolLoad__);
}

//------------------------------------------------------------------------------
// Address: 0x1031F030
// Name: _dynamic_initializer_for____g_CreateCToolFrameworkInternalIToolFrameworkInternal_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCToolFrameworkInternalIToolFrameworkInternal_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCToolFrameworkInternalIToolFrameworkInternal_reg,
           fn: _CreateCToolFrameworkInternalIToolFrameworkInternal_interface,
           pName: "VTOOLFRAMEWORKVERSION002");
}

//------------------------------------------------------------------------------
// Address: 0x1031F050
// Name: _dynamic_initializer_for____g_CClientEngineTools_singleton__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____g_CClientEngineTools_singleton__()
{
  return atexit(func: dynamic_atexit_destructor_for____g_CClientEngineTools_singleton__);
}

//------------------------------------------------------------------------------
// Address: 0x1031F060
// Name: _dynamic_initializer_for____g_CreateCClientEngineToolsIClientEngineTools_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCClientEngineToolsIClientEngineTools_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCClientEngineToolsIClientEngineTools_reg,
           fn: _CreateCClientEngineToolsIClientEngineTools_interface,
           pName: "VCLIENTENGINETOOLS001");
}

//------------------------------------------------------------------------------
// Address: 0x1031F080
// Name: _dynamic_initializer_for____g_CServerEngineTools_singleton__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____g_CServerEngineTools_singleton__()
{
  return atexit(func: dynamic_atexit_destructor_for____g_CServerEngineTools_singleton__);
}

//------------------------------------------------------------------------------
// Address: 0x1031F090
// Name: _dynamic_initializer_for____g_CreateCServerEngineToolsIServerEngineTools_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCServerEngineToolsIServerEngineTools_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCServerEngineToolsIServerEngineTools_reg,
           fn: _CreateCServerEngineToolsIServerEngineTools_interface,
           pName: "VSERVERENGINETOOLS001");
}

} // namespace engine_xlsp
