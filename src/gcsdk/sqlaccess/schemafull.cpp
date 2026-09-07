// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: gcsdk/sqlaccess/schemafull.cpp
// Functions: 112
// ============================================================

#include "gcsdk\sqlaccess\schemafull.h"

//------------------------------------------------------------------------------
// Address: 0x100057C0
// Name: class GCSDK::CGCClient __near * GGCClient(void)
// Source: json
//------------------------------------------------------------------------------
GCSDK::CGCClient *__cdecl GGCClient()
{
  return &g_GCClient;
}

//------------------------------------------------------------------------------
// Address: 0x10019CB0
// Name: public: static bool CDefOps<enum GCSDK::ESchemaCatalog>::LessFunc(enum GCSDK::ESchemaCatalog const __near &,enum GCSDK::ESchemaCatalog const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CDefOps<enum GCSDK::ESchemaCatalog>::LessFunc(const int *lhs, const int *rhs)
{
  return *lhs < *rhs;
}

//------------------------------------------------------------------------------
// Address: 0x100310A0
// Name: public: void GCSDK::CSchemaFull::Uninit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GCSDK::CSchemaFull::Uninit(GCSDK::CSchemaFull *this)
{
  int v2; // esi
  int v3; // edi
  unsigned __int8 *m_pubScratchBuffer; // eax

  v2 = this->m_VecSchema.m_Size - 1;
  if ( v2 >= 0 )
  {
    v3 = v2;
    do
    {
      GCSDK::CSchema::~CSchema(this: &this->m_VecSchema.m_Memory.m_pMemory[v3--]);
      --v2;
    }
    while ( v2 >= 0 );
  }
  m_pubScratchBuffer = this->m_pubScratchBuffer;
  this->m_VecSchema.m_Size = 0;
  if ( m_pubScratchBuffer != nullptr )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pubScratchBuffer);
    this->m_pubScratchBuffer = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100313B0
// Name: public: GCSDK::CSchemaFull::CSchemaFull(void)
// Source: json
//------------------------------------------------------------------------------
GCSDK::CSchemaFull *__thiscall GCSDK::CSchemaFull::CSchemaFull(GCSDK::CSchemaFull *this)
{
  GCSDK::CSchemaFull *result; // eax

  result = this;
  this->m_VecSchema.m_Memory.m_pMemory = nullptr;
  this->m_VecSchema.m_Memory.m_nAllocationCount = 0;
  this->m_VecSchema.m_Memory.m_nGrowSize = 0;
  this->m_VecSchema.m_Size = 0;
  this->m_VecSchema.m_pElements = nullptr;
  this->m_VecTriggers.m_Memory.m_pMemory = nullptr;
  this->m_VecTriggers.m_Memory.m_nAllocationCount = 0;
  this->m_VecTriggers.m_Memory.m_nGrowSize = 0;
  this->m_VecTriggers.m_Size = 0;
  this->m_VecTriggers.m_pElements = nullptr;
  this->m_mapFTSEnabled.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_mapFTSEnabled.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_mapFTSEnabled.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_mapFTSEnabled.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_mapFTSEnabled.m_Tree.m_Root = -1;
  this->m_mapFTSEnabled.m_Tree.m_NumElements = 0;
  this->m_mapFTSEnabled.m_Tree.m_FirstFree = -1;
  this->m_mapFTSEnabled.m_Tree.m_LastAlloc.index = -1;
  this->m_mapFTSEnabled.m_Tree.m_pElements = this->m_mapFTSEnabled.m_Tree.m_Elements.m_pMemory;
  this->m_vecFTSCatalogs.m_Memory.m_pMemory = nullptr;
  this->m_vecFTSCatalogs.m_Memory.m_nAllocationCount = 0;
  this->m_vecFTSCatalogs.m_Memory.m_nGrowSize = 0;
  this->m_vecFTSCatalogs.m_Size = 0;
  this->m_vecFTSCatalogs.m_pElements = nullptr;
  this->m_VecDeleteTable.m_Memory.m_pMemory = nullptr;
  this->m_VecDeleteTable.m_Memory.m_nAllocationCount = 0;
  this->m_VecDeleteTable.m_Memory.m_nGrowSize = 0;
  this->m_VecDeleteTable.m_Size = 0;
  this->m_VecDeleteTable.m_pElements = nullptr;
  this->m_VecRenameTable.m_Memory.m_pMemory = nullptr;
  this->m_VecRenameTable.m_Memory.m_nAllocationCount = 0;
  this->m_VecRenameTable.m_Memory.m_nGrowSize = 0;
  this->m_VecRenameTable.m_Size = 0;
  this->m_VecRenameTable.m_pElements = nullptr;
  this->m_pubScratchBuffer = nullptr;
  this->m_cubScratchBuffer = 0;
  this->m_unCheckSum = 0;
  if ( this->m_mapFTSEnabled.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_mapFTSEnabled.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const GCSDK::ESchemaCatalog *, const GCSDK::ESchemaCatalog *))CDefOps<enum GCSDK::ESchemaCatalog>::LessFunc;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10031450
// Name: public: GCSDK::CSchemaFull::~CSchemaFull(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GCSDK::CSchemaFull::~CSchemaFull(GCSDK::CSchemaFull *this)
{
  GCSDK::CSchemaFull::Uninit(this);
  CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>::~CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_VecRenameTable);
  CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>::~CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_VecDeleteTable);
  CUtlVector<GCSDK::CFTSCatalogInfo,CUtlMemory<GCSDK::CFTSCatalogInfo,int>>::Purge(this: &this->m_vecFTSCatalogs);
  if ( this->m_vecFTSCatalogs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_vecFTSCatalogs.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_vecFTSCatalogs.m_Memory.m_pMemory);
      this->m_vecFTSCatalogs.m_Memory.m_pMemory = nullptr;
    }
    this->m_vecFTSCatalogs.m_Memory.m_nAllocationCount = 0;
  }
  CUtlRBTree<CUtlMap<enum GCSDK::ESchemaCatalog,bool,unsigned short>::Node_t,unsigned short,CUtlMap<enum GCSDK::ESchemaCatalog,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GCSDK::ESchemaCatalog,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<enum GCSDK::ESchemaCatalog,bool,unsigned short>::Node_t,unsigned short,CUtlMap<enum GCSDK::ESchemaCatalog,bool,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum GCSDK::ESchemaCatalog,bool,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &this->m_mapFTSEnabled.m_Tree);
  CUtlVector<GCSDK::CTriggerInfo,CUtlMemory<GCSDK::CTriggerInfo,int>>::~CUtlVector<GCSDK::CTriggerInfo,CUtlMemory<GCSDK::CTriggerInfo,int>>(this: &this->m_VecTriggers);
  CUtlVector<GCSDK::CSchema,CUtlMemory<GCSDK::CSchema,int>>::Purge(this: &this->m_VecSchema);
  if ( this->m_VecSchema.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_VecSchema.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_VecSchema.m_Memory.m_pMemory);
      this->m_VecSchema.m_Memory.m_pMemory = nullptr;
    }
    this->m_VecSchema.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10053EE0
// Name: GCSDK::_dynamic_initializer_for__g_RegJob_CGCSOCreateJob__
// Source: json
//------------------------------------------------------------------------------
void GCSDK::_dynamic_initializer_for__g_RegJob_CGCSOCreateJob__()
{
  GCSDK::CJobMgr::RegisterJobType(pJobType: &g_JobType_CGCSOCreateJob);
}

//------------------------------------------------------------------------------
// Address: 0x10053EF0
// Name: GCSDK::_dynamic_initializer_for__g_RegJob_CGCSODestroyJob__
// Source: json
//------------------------------------------------------------------------------
void GCSDK::_dynamic_initializer_for__g_RegJob_CGCSODestroyJob__()
{
  GCSDK::CJobMgr::RegisterJobType(pJobType: &g_JobType_CGCSODestroyJob);
}

//------------------------------------------------------------------------------
// Address: 0x10053F00
// Name: GCSDK::_dynamic_initializer_for__g_RegJob_CGCSOUpdateJob__
// Source: json
//------------------------------------------------------------------------------
void GCSDK::_dynamic_initializer_for__g_RegJob_CGCSOUpdateJob__()
{
  GCSDK::CJobMgr::RegisterJobType(pJobType: &g_JobType_CGCSOUpdateJob);
}

//------------------------------------------------------------------------------
// Address: 0x10053F10
// Name: GCSDK::_dynamic_initializer_for__g_RegJob_CGCSOCacheSubscribedJob__
// Source: json
//------------------------------------------------------------------------------
void GCSDK::_dynamic_initializer_for__g_RegJob_CGCSOCacheSubscribedJob__()
{
  GCSDK::CJobMgr::RegisterJobType(pJobType: &g_JobType_CGCSOCacheSubscribedJob);
}

//------------------------------------------------------------------------------
// Address: 0x10053F20
// Name: GCSDK::_dynamic_initializer_for__g_RegJob_CGCSOCacheUnsubscribedJob__
// Source: json
//------------------------------------------------------------------------------
void GCSDK::_dynamic_initializer_for__g_RegJob_CGCSOCacheUnsubscribedJob__()
{
  GCSDK::CJobMgr::RegisterJobType(pJobType: &g_JobType_CGCSOCacheUnsubscribedJob);
}

//------------------------------------------------------------------------------
// Address: 0x10053F30
// Name: GCSDK::_dynamic_initializer_for__g_mutexTempTextBuffer__
// Source: json
//------------------------------------------------------------------------------
int GCSDK::_dynamic_initializer_for__g_mutexTempTextBuffer__()
{
  CThreadMutex::CThreadMutex(this: &GCSDK::g_mutexTempTextBuffer);
  return atexit(func: GCSDK::_dynamic_atexit_destructor_for__g_mutexTempTextBuffer__);
}

//------------------------------------------------------------------------------
// Address: 0x10053F50
// Name: GCSDK::_dynamic_initializer_for__g_vecTempTextBuffer__
// Source: json
//------------------------------------------------------------------------------
int GCSDK::_dynamic_initializer_for__g_vecTempTextBuffer__()
{
  return atexit(func: GCSDK::_dynamic_atexit_destructor_for__g_vecTempTextBuffer__);
}

//------------------------------------------------------------------------------
// Address: 0x10054200
// Name: GCSDK::_dynamic_initializer_for__g_MemPoolMsg__
// Source: json
//------------------------------------------------------------------------------
int GCSDK::_dynamic_initializer_for__g_MemPoolMsg__()
{
  CThreadSafeMultiMemoryPool::CThreadSafeMultiMemoryPool(
    this: &GCSDK::g_MemPoolMsg,
    pMemPoolConfig: s_MemPoolConfigAllocSize,
    cnMemPoolConfig: 11,
    nGrowMode: 1);
  return atexit(func: GCSDK::_dynamic_atexit_destructor_for__g_MemPoolMsg__);
}

//------------------------------------------------------------------------------
// Address: 0x10054220
// Name: GCSDK::_dynamic_initializer_for__g_theMessageList__
// Source: json
//------------------------------------------------------------------------------
int GCSDK::_dynamic_initializer_for__g_theMessageList__()
{
  return atexit(func: GCSDK::_dynamic_atexit_destructor_for__g_theMessageList__);
}

//------------------------------------------------------------------------------
// Address: 0x10054680
// Name: GCSDK::_dynamic_initializer_for__g_SOMessageReg__
// Source: json
//------------------------------------------------------------------------------
GCSDK::CMessageListRegistration *GCSDK::_dynamic_initializer_for__g_SOMessageReg__()
{
  return GCSDK::CMessageListRegistration::CMessageListRegistration(
           this: &GCSDK::g_SOMessageReg,
           pMsgInfo: GCSDK::g_SOMsgInfo,
           cMsgInfo: 5,
           pExtra: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100546A0
// Name: GCSDK::_dynamic_initializer_for__g_RegJob_CPreTestSetupJob__
// Source: json
//------------------------------------------------------------------------------
void GCSDK::_dynamic_initializer_for__g_RegJob_CPreTestSetupJob__()
{
  GCSDK::CJobMgr::RegisterJobType(pJobType: &g_JobType_CPreTestSetupJob);
}

//------------------------------------------------------------------------------
// Address: 0x100546B0
// Name: GCSDK::_dynamic_initializer_for__g_RegJob_CStartPlayingJob__
// Source: json
//------------------------------------------------------------------------------
void GCSDK::_dynamic_initializer_for__g_RegJob_CStartPlayingJob__()
{
  GCSDK::CJobMgr::RegisterJobType(pJobType: &g_JobType_CStartPlayingJob);
}

//------------------------------------------------------------------------------
// Address: 0x100546C0
// Name: GCSDK::_dynamic_initializer_for__g_RegJob_CStopPlayingJob__
// Source: json
//------------------------------------------------------------------------------
void GCSDK::_dynamic_initializer_for__g_RegJob_CStopPlayingJob__()
{
  GCSDK::CJobMgr::RegisterJobType(pJobType: &g_JobType_CStopPlayingJob);
}

//------------------------------------------------------------------------------
// Address: 0x100546D0
// Name: GCSDK::_dynamic_initializer_for__g_RegJob_CStartGameserverJob__
// Source: json
//------------------------------------------------------------------------------
void GCSDK::_dynamic_initializer_for__g_RegJob_CStartGameserverJob__()
{
  GCSDK::CJobMgr::RegisterJobType(pJobType: &g_JobType_CStartGameserverJob);
}

//------------------------------------------------------------------------------
// Address: 0x100546E0
// Name: GCSDK::_dynamic_initializer_for__g_RegJob_CStopGameserverJob__
// Source: json
//------------------------------------------------------------------------------
void GCSDK::_dynamic_initializer_for__g_RegJob_CStopGameserverJob__()
{
  GCSDK::CJobMgr::RegisterJobType(pJobType: &g_JobType_CStopGameserverJob);
}

//------------------------------------------------------------------------------
// Address: 0x10054C00
// Name: GCSDK::_dynamic_initializer_for__g_SchemaFull__
// Source: json
//------------------------------------------------------------------------------
int GCSDK::_dynamic_initializer_for__g_SchemaFull__()
{
  GCSDK::CSchemaFull::CSchemaFull(this: &GCSDK::g_SchemaFull);
  return atexit(func: GCSDK::_dynamic_atexit_destructor_for__g_SchemaFull__);
}

//------------------------------------------------------------------------------
// Address: 0x10054F00
// Name: GCSDK::_dynamic_atexit_destructor_for__g_mutexTempTextBuffer__
// Source: json
//------------------------------------------------------------------------------
void __cdecl GCSDK::_dynamic_atexit_destructor_for__g_mutexTempTextBuffer__()
{
  CThreadMutex::~CThreadMutex(this: &GCSDK::g_mutexTempTextBuffer);
}

//------------------------------------------------------------------------------
// Address: 0x10054F10
// Name: _GCSDK::GetPchTempTextBuffer_::_2_::_dynamic_atexit_destructor_for__s_rgtlsBuffers__
// Source: json
//------------------------------------------------------------------------------
void __cdecl GCSDK::GetPchTempTextBuffer_::_2_::_dynamic_atexit_destructor_for__s_rgtlsBuffers__()
{
  GenericThreadLocals::CThreadLocal<int> *v0; // esi
  int i; // edi

  v0 = &s_irgchBuffer;
  for ( i = 4; i >= 0; --i )
    GenericThreadLocals::CThreadLocalBase::~CThreadLocalBase(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x10054F40
// Name: _GCSDK::GetPchTempTextBuffer_::_2_::_dynamic_atexit_destructor_for__s_irgchBuffer__
// Source: json
//------------------------------------------------------------------------------
void __cdecl GCSDK::GetPchTempTextBuffer_::_2_::_dynamic_atexit_destructor_for__s_irgchBuffer__()
{
  GenericThreadLocals::CThreadLocalBase::~CThreadLocalBase(this: &s_irgchBuffer);
}

//------------------------------------------------------------------------------
// Address: 0x10054F50
// Name: GCSDK::_dynamic_atexit_destructor_for__g_vecTempTextBuffer__
// Source: json
//------------------------------------------------------------------------------
void __cdecl GCSDK::_dynamic_atexit_destructor_for__g_vecTempTextBuffer__()
{
  CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>::~CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&GCSDK::g_vecTempTextBuffer);
}

//------------------------------------------------------------------------------
// Address: 0x100550D0
// Name: _GCSDK::GMapJobTypes_::_2_::_dynamic_atexit_destructor_for__s_MapJobTypes__
// Source: json
//------------------------------------------------------------------------------
void __cdecl GCSDK::GMapJobTypes_::_2_::_dynamic_atexit_destructor_for__s_MapJobTypes__()
{
  CUtlRBTree<GCSDK::JobType_t const *,unsigned short,bool (__cdecl *)(GCSDK::JobType_t const * const &,GCSDK::JobType_t const * const &),CUtlMemory<UtlRBTreeNode_t<GCSDK::JobType_t const *,unsigned short>,unsigned short>>::~CUtlRBTree<GCSDK::JobType_t const *,unsigned short,bool (__cdecl *)(GCSDK::JobType_t const * const &,GCSDK::JobType_t const * const &),CUtlMemory<UtlRBTreeNode_t<GCSDK::JobType_t const *,unsigned short>,unsigned short>>(this: &s_MapJobTypes);
}

//------------------------------------------------------------------------------
// Address: 0x100550E0
// Name: GCSDK::_dynamic_atexit_destructor_for__g_MemPoolMsg__
// Source: json
//------------------------------------------------------------------------------
void __cdecl GCSDK::_dynamic_atexit_destructor_for__g_MemPoolMsg__()
{
  CThreadSafeMultiMemoryPool::~CThreadSafeMultiMemoryPool(this: &GCSDK::g_MemPoolMsg);
}

//------------------------------------------------------------------------------
// Address: 0x10055100
// Name: GCSDK::_dynamic_atexit_destructor_for__g_theMessageList__
// Source: json
//------------------------------------------------------------------------------
void __cdecl GCSDK::_dynamic_atexit_destructor_for__g_theMessageList__()
{
  GCSDK::CMessageList::~CMessageList(this: &GCSDK::g_theMessageList);
}

//------------------------------------------------------------------------------
// Address: 0x100554E0
// Name: GCSDK::_dynamic_atexit_destructor_for__g_SchemaFull__
// Source: json
//------------------------------------------------------------------------------
void __cdecl GCSDK::_dynamic_atexit_destructor_for__g_SchemaFull__()
{
  GCSDK::CSchemaFull::~CSchemaFull(this: &GCSDK::g_SchemaFull);
}

//------------------------------------------------------------------------------
// Address: 0x10053F60
// Name: _dynamic_initializer_for__g_MatchEventsSubscription__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_MatchEventsSubscription__()
{
  CMatchEventsSubscription::CMatchEventsSubscription(this: &g_MatchEventsSubscription);
  return atexit(func: dynamic_atexit_destructor_for__g_MatchEventsSubscription__);
}

//------------------------------------------------------------------------------
// Address: 0x10053F80
// Name: _dynamic_initializer_for__cl_names_debug__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_names_debug__()
{
  ConVar::ConVar(this: &cl_names_debug, pName: "cl_names_debug", pDefaultValue: "0", flags: 2);
  return atexit(func: dynamic_atexit_destructor_for__cl_names_debug__);
}

//------------------------------------------------------------------------------
// Address: 0x10053FB0
// Name: _dynamic_initializer_for__s_arrSessionSearchesQueue__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_arrSessionSearchesQueue__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_arrSessionSearchesQueue__);
}

//------------------------------------------------------------------------------
// Address: 0x10053FC0
// Name: _dynamic_initializer_for__mm_player_search_count__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mm_player_search_count__()
{
  ConVar::ConVar(this: &mm_player_search_count, pName: "mm_player_search_count", pDefaultValue: "5", flags: 2);
  return atexit(func: dynamic_atexit_destructor_for__mm_player_search_count__);
}

//------------------------------------------------------------------------------
// Address: 0x10054000
// Name: _dynamic_initializer_for__mm_cfgoverride_file__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mm_cfgoverride_file__()
{
  ConVar::ConVar(this: &mm_cfgoverride_file, pName: "mm_cfgoverride_file", pDefaultValue: defaultValue, flags: 2);
  return atexit(func: dynamic_atexit_destructor_for__mm_cfgoverride_file__);
}

//------------------------------------------------------------------------------
// Address: 0x10054030
// Name: _dynamic_initializer_for__mm_cfgoverride_commit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mm_cfgoverride_commit__()
{
  ConVar::ConVar(this: &mm_cfgoverride_commit, pName: "mm_cfgoverride_commit", pDefaultValue: defaultValue, flags: 2);
  return atexit(func: dynamic_atexit_destructor_for__mm_cfgoverride_commit__);
}

//------------------------------------------------------------------------------
// Address: 0x10054060
// Name: _dynamic_initializer_for__mm_cfgdebug_mode__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mm_cfgdebug_mode__()
{
  ConVar::ConVar(this: &mm_cfgdebug_mode, pName: "mm_cfgdebug_mode", pDefaultValue: "0", flags: 2);
  return atexit(func: dynamic_atexit_destructor_for__mm_cfgdebug_mode__);
}

//------------------------------------------------------------------------------
// Address: 0x10054090
// Name: _dynamic_initializer_for__ms_player_dump_properties_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ms_player_dump_properties_command__()
{
  ConCommand::ConCommand(
    this: &ms_player_dump_properties_command,
    pName: "ms_player_dump_properties",
    callback: (void (__cdecl *)(const CCommand *))ms_player_dump_properties,
    pHelpString: "Prints a dump the current players property data",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__ms_player_dump_properties_command__);
}

//------------------------------------------------------------------------------
// Address: 0x100540C0
// Name: _dynamic_initializer_for__ms_player_unaward_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ms_player_unaward_command__()
{
  ConCommand::ConCommand(
    this: &ms_player_unaward_command,
    pName: "ms_player_unaward",
    callback: ms_player_unaward,
    pHelpString: "UnAwards the current player an award",
    flags: 2,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__ms_player_unaward_command__);
}

//------------------------------------------------------------------------------
// Address: 0x100540F0
// Name: _dynamic_initializer_for__net_allow_multicast__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_allow_multicast__()
{
  ConVar::ConVar(this: &net_allow_multicast, pName: "net_allow_multicast", pDefaultValue: "1", flags: 524416);
  return atexit(func: dynamic_atexit_destructor_for__net_allow_multicast__);
}

//------------------------------------------------------------------------------
// Address: 0x10054120
// Name: _dynamic_initializer_for__net_allow_syslink__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__net_allow_syslink__()
{
  ConVar::ConVar(this: &net_allow_syslink, pName: "net_allow_syslink", pDefaultValue: "1", flags: 2);
  return atexit(func: dynamic_atexit_destructor_for__net_allow_syslink__);
}

//------------------------------------------------------------------------------
// Address: 0x10054150
// Name: _dynamic_initializer_for__g_ConnectionlessLanMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ConnectionlessLanMgr__()
{
  CUtlBuffer::CUtlBuffer(this: &g_ConnectionlessLanMgr.m_buffer, growSize: 0, initSize: 0, nFlags: 0);
  return atexit(func: dynamic_atexit_destructor_for__g_ConnectionlessLanMgr__);
}

//------------------------------------------------------------------------------
// Address: 0x10054170
// Name: _dynamic_initializer_for__mm_events_listeners_validation__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mm_events_listeners_validation__()
{
  ConVar::ConVar(
    this: &mm_events_listeners_validation,
    pName: "mm_events_listeners_validation",
    pDefaultValue: "0",
    flags: 2);
  return atexit(func: dynamic_atexit_destructor_for__mm_events_listeners_validation__);
}

//------------------------------------------------------------------------------
// Address: 0x100541A0
// Name: _dynamic_initializer_for__g_MatchSteamInviteListener__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_MatchSteamInviteListener__()
{
  *((_DWORD *)&g_MatchSteamInviteListener.m_msgPending.m_steamIDLobby.m_steamid.m_comp + 1) &= 0xFF0FFFFF;
  *((_DWORD *)&g_MatchSteamInviteListener.m_msgPending.m_steamIDFriend.m_steamid.m_comp + 1) &= 0xFF0FFFFF;
  HIBYTE(g_MatchSteamInviteListener.m_msgPending.m_steamIDLobby.m_steamid.m_unAll64Bits) = 0;
  *((_DWORD *)&g_MatchSteamInviteListener.m_msgPending.m_steamIDLobby.m_steamid.m_comp + 1) &= 0xFFF00000;
  HIBYTE(g_MatchSteamInviteListener.m_msgPending.m_steamIDFriend.m_steamid.m_unAll64Bits) = 0;
  *((_DWORD *)&g_MatchSteamInviteListener.m_msgPending.m_steamIDFriend.m_steamid.m_comp + 1) &= 0xFFF00000;
  return atexit(func: dynamic_atexit_destructor_for__g_MatchSteamInviteListener__);
}

//------------------------------------------------------------------------------
// Address: 0x10054230
// Name: _dynamic_initializer_for__g_LeaderboardRequestQueue__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_LeaderboardRequestQueue__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_LeaderboardRequestQueue__);
}

//------------------------------------------------------------------------------
// Address: 0x10054240
// Name: _dynamic_initializer_for__mm_datacenter_update_interval__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mm_datacenter_update_interval__()
{
  ConVar::ConVar(
    this: &mm_datacenter_update_interval,
    pName: "mm_datacenter_update_interval",
    pDefaultValue: "3600",
    flags: 2,
    pHelpString: "Interval between datacenter stats updates.");
  return atexit(func: dynamic_atexit_destructor_for__mm_datacenter_update_interval__);
}

//------------------------------------------------------------------------------
// Address: 0x10054270
// Name: _dynamic_initializer_for__mm_datacenter_retry_interval__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mm_datacenter_retry_interval__()
{
  ConVar::ConVar(
    this: &mm_datacenter_retry_interval,
    pName: "mm_datacenter_retry_interval",
    pDefaultValue: "75",
    flags: 2,
    pHelpString: "Interval between datacenter stats retries.");
  return atexit(func: dynamic_atexit_destructor_for__mm_datacenter_retry_interval__);
}

//------------------------------------------------------------------------------
// Address: 0x100542A0
// Name: _dynamic_initializer_for__mm_datacenter_retry_infochunks_attempts__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mm_datacenter_retry_infochunks_attempts__()
{
  ConVar::ConVar(
    this: &mm_datacenter_retry_infochunks_attempts,
    pName: "mm_datacenter_retry_infochunks_attempts",
    pDefaultValue: "3",
    flags: 2,
    pHelpString: "How many times can we retry retrieving each info chunk before failing.");
  return atexit(func: dynamic_atexit_destructor_for__mm_datacenter_retry_infochunks_attempts__);
}

//------------------------------------------------------------------------------
// Address: 0x100542D0
// Name: _dynamic_initializer_for__mm_datacenter_query_delay__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mm_datacenter_query_delay__()
{
  ConVar::ConVar(
    this: &mm_datacenter_query_delay,
    pName: "mm_datacenter_query_delay",
    pDefaultValue: "2",
    flags: 2,
    pHelpString: "Delay after datacenter update is enabled before data is actually queried.");
  return atexit(func: dynamic_atexit_destructor_for__mm_datacenter_query_delay__);
}

//------------------------------------------------------------------------------
// Address: 0x10054300
// Name: _dynamic_initializer_for__mm_datacenter_report_version__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mm_datacenter_report_version__()
{
  ConVar::ConVar(
    this: &mm_datacenter_report_version,
    pName: "mm_datacenter_report_version",
    pDefaultValue: "5",
    flags: 2,
    pHelpString: "Data version to report to DC.");
  return atexit(func: dynamic_atexit_destructor_for__mm_datacenter_report_version__);
}

//------------------------------------------------------------------------------
// Address: 0x10054330
// Name: _dynamic_initializer_for__mm_datacenter_delay_mount_frames__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mm_datacenter_delay_mount_frames__()
{
  ConVar::ConVar(
    this: &mm_datacenter_delay_mount_frames,
    pName: "mm_datacenter_delay_mount_frames",
    pDefaultValue: "6",
    flags: 2,
    pHelpString: "How many frames to delay before attempting to mount the xlsp patch.");
  return atexit(func: dynamic_atexit_destructor_for__mm_datacenter_delay_mount_frames__);
}

//------------------------------------------------------------------------------
// Address: 0x10054360
// Name: _dynamic_initializer_for__g_Datacenter__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Datacenter__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_Datacenter__);
}

//------------------------------------------------------------------------------
// Address: 0x10054370
// Name: _dynamic_initializer_for__mm_datacenter_debugprint_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mm_datacenter_debugprint_command__()
{
  ConCommand::ConCommand(
    this: &mm_datacenter_debugprint_command,
    pName: "mm_datacenter_debugprint",
    callback: mm_datacenter_debugprint,
    pHelpString: "Shows information retrieved from data center",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__mm_datacenter_debugprint_command__);
}

//------------------------------------------------------------------------------
// Address: 0x100543A0
// Name: _dynamic_initializer_for__mm_server_search_update_interval__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mm_server_search_update_interval__()
{
  ConVar::ConVar(
    this: &mm_server_search_update_interval,
    pName: "mm_server_search_update_interval",
    pDefaultValue: "60",
    flags: 2,
    pHelpString: "Interval between servers updates.");
  return atexit(func: dynamic_atexit_destructor_for__mm_server_search_update_interval__);
}

//------------------------------------------------------------------------------
// Address: 0x100543D0
// Name: _dynamic_initializer_for__mm_server_search_inet_ping_interval__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mm_server_search_inet_ping_interval__()
{
  ConVar::ConVar(
    this: &mm_server_search_inet_ping_interval,
    pName: "mm_server_search_inet_ping_interval",
    pDefaultValue: "1.0",
    flags: 2,
    pHelpString: "How long to wait between pinging internet server details.");
  return atexit(func: dynamic_atexit_destructor_for__mm_server_search_inet_ping_interval__);
}

//------------------------------------------------------------------------------
// Address: 0x10054400
// Name: _dynamic_initializer_for__mm_server_search_inet_ping_timeout__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mm_server_search_inet_ping_timeout__()
{
  ConVar::ConVar(
    this: &mm_server_search_inet_ping_timeout,
    pName: "mm_server_search_inet_ping_timeout",
    pDefaultValue: "3.0",
    flags: 2,
    pHelpString: "How long to wait for internet server details.");
  return atexit(func: dynamic_atexit_destructor_for__mm_server_search_inet_ping_timeout__);
}

//------------------------------------------------------------------------------
// Address: 0x10054430
// Name: _dynamic_initializer_for__mm_server_search_inet_ping_window__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mm_server_search_inet_ping_window__()
{
  ConVar::ConVar(
    this: &mm_server_search_inet_ping_window,
    pName: "mm_server_search_inet_ping_window",
    pDefaultValue: "10",
    flags: 2,
    pHelpString: "How many servers can be pinged for server details in a batch.");
  return atexit(func: dynamic_atexit_destructor_for__mm_server_search_inet_ping_window__);
}

//------------------------------------------------------------------------------
// Address: 0x10054460
// Name: _dynamic_initializer_for__mm_server_search_inet_ping_refresh__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mm_server_search_inet_ping_refresh__()
{
  ConVar::ConVar(
    this: &mm_server_search_inet_ping_refresh,
    pName: "mm_server_search_inet_ping_refresh",
    pDefaultValue: "15",
    flags: 2,
    pHelpString: "How often to refresh a listed server.");
  return atexit(func: dynamic_atexit_destructor_for__mm_server_search_inet_ping_refresh__);
}

//------------------------------------------------------------------------------
// Address: 0x10054490
// Name: _dynamic_initializer_for__mm_server_search_server_lifetime__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mm_server_search_server_lifetime__()
{
  ConVar::ConVar(
    this: &mm_server_search_server_lifetime,
    pName: "mm_server_search_server_lifetime",
    pDefaultValue: "180",
    flags: 2,
    pHelpString: "How long until a server is no longer returned by the master till we remove it.");
  return atexit(func: dynamic_atexit_destructor_for__mm_server_search_server_lifetime__);
}

//------------------------------------------------------------------------------
// Address: 0x100544C0
// Name: _dynamic_initializer_for__mm_server_search_lan_ping_interval__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mm_server_search_lan_ping_interval__()
{
  ConVar::ConVar(
    this: &mm_server_search_lan_ping_interval,
    pName: "mm_server_search_lan_ping_interval",
    pDefaultValue: "0.4",
    flags: 2,
    pHelpString: "Interval between LAN discovery pings.");
  return atexit(func: dynamic_atexit_destructor_for__mm_server_search_lan_ping_interval__);
}

//------------------------------------------------------------------------------
// Address: 0x100544F0
// Name: _dynamic_initializer_for__mm_server_search_lan_ping_duration__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mm_server_search_lan_ping_duration__()
{
  ConVar::ConVar(
    this: &mm_server_search_lan_ping_duration,
    pName: "mm_server_search_lan_ping_duration",
    pDefaultValue: "1.0",
    flags: 2,
    pHelpString: "Duration of LAN discovery ping phase.");
  return atexit(func: dynamic_atexit_destructor_for__mm_server_search_lan_ping_duration__);
}

//------------------------------------------------------------------------------
// Address: 0x10054520
// Name: _dynamic_initializer_for__mm_server_search_lan_ports__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mm_server_search_lan_ports__()
{
  ConVar::ConVar(
    this: &mm_server_search_lan_ports,
    pName: "mm_server_search_lan_ports",
    pDefaultValue: "27015,27016,27017,27018,27019,27020",
    flags: 524416,
    pHelpString: "Ports to scan during LAN games discovery. Also used to discover and correctly connect to dedicated LAN servers behind NATs.");
  return atexit(func: dynamic_atexit_destructor_for__mm_server_search_lan_ports__);
}

//------------------------------------------------------------------------------
// Address: 0x10054550
// Name: _dynamic_initializer_for__g_ServerManager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ServerManager__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_ServerManager__);
}

//------------------------------------------------------------------------------
// Address: 0x10054560
// Name: _dynamic_initializer_for__g_MatchNetMsgControllerBase__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_MatchNetMsgControllerBase__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_MatchNetMsgControllerBase__);
}

//------------------------------------------------------------------------------
// Address: 0x10054570
// Name: _dynamic_initializer_for__s_MatchSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_MatchSystem__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_MatchSystem__);
}

//------------------------------------------------------------------------------
// Address: 0x10054580
// Name: _dynamic_initializer_for__mm_disable_listen_server__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mm_disable_listen_server__()
{
  ConVar::ConVar(this: &mm_disable_listen_server, pName: "mm_disable_listen_server", pDefaultValue: "0", flags: 2);
  return atexit(func: dynamic_atexit_destructor_for__mm_disable_listen_server__);
}

//------------------------------------------------------------------------------
// Address: 0x100545B0
// Name: _dynamic_initializer_for__mm_ignored_sessions_forget_time__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mm_ignored_sessions_forget_time__()
{
  ConVar::ConVar(
    this: &mm_ignored_sessions_forget_time,
    pName: "mm_ignored_sessions_forget_time",
    pDefaultValue: "120",
    flags: 2);
  return atexit(func: dynamic_atexit_destructor_for__mm_ignored_sessions_forget_time__);
}

//------------------------------------------------------------------------------
// Address: 0x100545E0
// Name: _dynamic_initializer_for__mm_ignored_sessions_forget_pass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mm_ignored_sessions_forget_pass__()
{
  ConVar::ConVar(
    this: &mm_ignored_sessions_forget_pass,
    pName: "mm_ignored_sessions_forget_pass",
    pDefaultValue: "2",
    flags: 2);
  return atexit(func: dynamic_atexit_destructor_for__mm_ignored_sessions_forget_pass__);
}

//------------------------------------------------------------------------------
// Address: 0x10054610
// Name: _dynamic_initializer_for__g_IgnoredSessionsMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_IgnoredSessionsMgr__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_IgnoredSessionsMgr__);
}

//------------------------------------------------------------------------------
// Address: 0x10054620
// Name: _dynamic_initializer_for__g_DlcManager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_DlcManager__()
{
  g_DlcManager.m_CallbackOnDLCInstalled.m_Func = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__g_DlcManager__);
}

//------------------------------------------------------------------------------
// Address: 0x10054640
// Name: _dynamic_initializer_for__mm_dlc_debugprint_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mm_dlc_debugprint_command__()
{
  ConCommand::ConCommand(
    this: &mm_dlc_debugprint_command,
    pName: "mm_dlc_debugprint",
    callback: mm_dlc_debugprint,
    pHelpString: "Shows information about dlc",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__mm_dlc_debugprint_command__);
}

//------------------------------------------------------------------------------
// Address: 0x100546F0
// Name: _dynamic_initializer_for__g_MatchVoice__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_MatchVoice__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_MatchVoice__);
}

//------------------------------------------------------------------------------
// Address: 0x10054F60
// Name: _dynamic_atexit_destructor_for__g_MatchEventsSubscription__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_MatchEventsSubscription__()
{
  g_MatchEventsSubscription.__vftable = (CMatchEventsSubscription_vtbl *)&CMatchEventsSubscription::`vftable';
  CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>::~CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&g_MatchEventsSubscription.m_arrSentEvents);
  CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>::~CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&g_MatchEventsSubscription.m_arrEventData);
  CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>::~CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&g_MatchEventsSubscription.m_arrQueuedEvents);
  CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>::~CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&g_MatchEventsSubscription.m_arrIteratorsOutstanding);
  CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>::~CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&g_MatchEventsSubscription.m_arrRefCount);
  CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>::~CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&g_MatchEventsSubscription.m_arrSinks);
}

//------------------------------------------------------------------------------
// Address: 0x10054FB0
// Name: _dynamic_atexit_destructor_for__cl_names_debug__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_names_debug__()
{
  ConVar::~ConVar(this: &cl_names_debug);
}

//------------------------------------------------------------------------------
// Address: 0x10054FC0
// Name: _dynamic_atexit_destructor_for__mm_player_search_count__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_player_search_count__()
{
  ConVar::~ConVar(this: &mm_player_search_count);
}

//------------------------------------------------------------------------------
// Address: 0x10054FD0
// Name: _dynamic_atexit_destructor_for__mm_cfgoverride_file__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_cfgoverride_file__()
{
  ConVar::~ConVar(this: &mm_cfgoverride_file);
}

//------------------------------------------------------------------------------
// Address: 0x10054FE0
// Name: _dynamic_atexit_destructor_for__mm_cfgoverride_commit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_cfgoverride_commit__()
{
  ConVar::~ConVar(this: &mm_cfgoverride_commit);
}

//------------------------------------------------------------------------------
// Address: 0x10054FF0
// Name: _dynamic_atexit_destructor_for__mm_cfgdebug_mode__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_cfgdebug_mode__()
{
  ConVar::~ConVar(this: &mm_cfgdebug_mode);
}

//------------------------------------------------------------------------------
// Address: 0x10055000
// Name: _dynamic_atexit_destructor_for__ms_player_dump_properties_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ms_player_dump_properties_command__()
{
  ConCommand::~ConCommand(this: &ms_player_dump_properties_command);
}

//------------------------------------------------------------------------------
// Address: 0x10055010
// Name: _dynamic_atexit_destructor_for__ms_player_unaward_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ms_player_unaward_command__()
{
  ConCommand::~ConCommand(this: &ms_player_unaward_command);
}

//------------------------------------------------------------------------------
// Address: 0x10055020
// Name: _dynamic_atexit_destructor_for__s_arrSessionSearchesQueue__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_arrSessionSearchesQueue__()
{
  CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>::~CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&s_arrSessionSearchesQueue);
}

//------------------------------------------------------------------------------
// Address: 0x10055030
// Name: _dynamic_atexit_destructor_for__net_allow_multicast__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_allow_multicast__()
{
  ConVar::~ConVar(this: &net_allow_multicast);
}

//------------------------------------------------------------------------------
// Address: 0x10055040
// Name: _dynamic_atexit_destructor_for__net_allow_syslink__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_allow_syslink__()
{
  ConVar::~ConVar(this: &net_allow_syslink);
}

//------------------------------------------------------------------------------
// Address: 0x10055050
// Name: _dynamic_atexit_destructor_for__g_ConnectionlessLanMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ConnectionlessLanMgr__()
{
  g_ConnectionlessLanMgr.__vftable = (CConnectionlessLanMgr_vtbl *)&CConnectionlessLanMgr::`vftable';
  if ( g_ConnectionlessLanMgr.m_buffer.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_ConnectionlessLanMgr.m_buffer.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_ConnectionlessLanMgr.m_buffer.m_Memory.m_pMemory);
      g_ConnectionlessLanMgr.m_buffer.m_Memory.m_pMemory = nullptr;
    }
    g_ConnectionlessLanMgr.m_buffer.m_Memory.m_nAllocationCount = 0;
  }
  g_ConnectionlessLanMgr.__vftable = (CConnectionlessLanMgr_vtbl *)&IConnectionlessPacketHandler::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x100550A0
// Name: _dynamic_atexit_destructor_for__mm_events_listeners_validation__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_events_listeners_validation__()
{
  ConVar::~ConVar(this: &mm_events_listeners_validation);
}

//------------------------------------------------------------------------------
// Address: 0x100550B0
// Name: _dynamic_atexit_destructor_for__g_MatchSteamInviteListener__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_MatchSteamInviteListener__()
{
  g_MatchSteamInviteListener.m_CallbackOnGameLobbyJoinRequested.__vftable = (CCallbackManual<CMatchSteamInviteListener,GameLobbyJoinRequested_t,0>_vtbl *)&CCallback<CMatchSteamInviteListener,GameLobbyJoinRequested_t,0>::`vftable';
  if ( (g_MatchSteamInviteListener.m_CallbackOnGameLobbyJoinRequested.m_nCallbackFlags & 1) != 0 )
    _SteamAPI_UnregisterCallback(a1: &g_MatchSteamInviteListener);
}

//------------------------------------------------------------------------------
// Address: 0x10055110
// Name: _dynamic_atexit_destructor_for__g_LeaderboardRequestQueue__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_LeaderboardRequestQueue__()
{
  CLeaderboardRequestQueue::~CLeaderboardRequestQueue(this: &g_LeaderboardRequestQueue);
}

//------------------------------------------------------------------------------
// Address: 0x10055120
// Name: _dynamic_atexit_destructor_for__mm_datacenter_update_interval__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_datacenter_update_interval__()
{
  ConVar::~ConVar(this: &mm_datacenter_update_interval);
}

//------------------------------------------------------------------------------
// Address: 0x10055130
// Name: _dynamic_atexit_destructor_for__mm_datacenter_retry_interval__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_datacenter_retry_interval__()
{
  ConVar::~ConVar(this: &mm_datacenter_retry_interval);
}

//------------------------------------------------------------------------------
// Address: 0x10055140
// Name: _dynamic_atexit_destructor_for__mm_datacenter_retry_infochunks_attempts__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_datacenter_retry_infochunks_attempts__()
{
  ConVar::~ConVar(this: &mm_datacenter_retry_infochunks_attempts);
}

//------------------------------------------------------------------------------
// Address: 0x10055150
// Name: _dynamic_atexit_destructor_for__mm_datacenter_query_delay__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_datacenter_query_delay__()
{
  ConVar::~ConVar(this: &mm_datacenter_query_delay);
}

//------------------------------------------------------------------------------
// Address: 0x10055160
// Name: _dynamic_atexit_destructor_for__mm_datacenter_report_version__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_datacenter_report_version__()
{
  ConVar::~ConVar(this: &mm_datacenter_report_version);
}

//------------------------------------------------------------------------------
// Address: 0x10055170
// Name: _dynamic_atexit_destructor_for__mm_datacenter_delay_mount_frames__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_datacenter_delay_mount_frames__()
{
  ConVar::~ConVar(this: &mm_datacenter_delay_mount_frames);
}

//------------------------------------------------------------------------------
// Address: 0x10055180
// Name: _dynamic_atexit_destructor_for__mm_datacenter_debugprint_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_datacenter_debugprint_command__()
{
  ConCommand::~ConCommand(this: &mm_datacenter_debugprint_command);
}

//------------------------------------------------------------------------------
// Address: 0x10055190
// Name: _dynamic_atexit_destructor_for__g_Datacenter__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_Datacenter__()
{
  CDatacenter::~CDatacenter(this: &g_Datacenter);
}

//------------------------------------------------------------------------------
// Address: 0x100551A0
// Name: _dynamic_atexit_destructor_for__mm_server_search_update_interval__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_server_search_update_interval__()
{
  ConVar::~ConVar(this: &mm_server_search_update_interval);
}

//------------------------------------------------------------------------------
// Address: 0x100551B0
// Name: _dynamic_atexit_destructor_for__mm_server_search_inet_ping_interval__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_server_search_inet_ping_interval__()
{
  ConVar::~ConVar(this: &mm_server_search_inet_ping_interval);
}

//------------------------------------------------------------------------------
// Address: 0x100551C0
// Name: _dynamic_atexit_destructor_for__mm_server_search_inet_ping_timeout__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_server_search_inet_ping_timeout__()
{
  ConVar::~ConVar(this: &mm_server_search_inet_ping_timeout);
}

//------------------------------------------------------------------------------
// Address: 0x100551D0
// Name: _dynamic_atexit_destructor_for__mm_server_search_inet_ping_window__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_server_search_inet_ping_window__()
{
  ConVar::~ConVar(this: &mm_server_search_inet_ping_window);
}

//------------------------------------------------------------------------------
// Address: 0x100551E0
// Name: _dynamic_atexit_destructor_for__mm_server_search_inet_ping_refresh__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_server_search_inet_ping_refresh__()
{
  ConVar::~ConVar(this: &mm_server_search_inet_ping_refresh);
}

//------------------------------------------------------------------------------
// Address: 0x100551F0
// Name: _dynamic_atexit_destructor_for__mm_server_search_server_lifetime__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_server_search_server_lifetime__()
{
  ConVar::~ConVar(this: &mm_server_search_server_lifetime);
}

//------------------------------------------------------------------------------
// Address: 0x10055200
// Name: _dynamic_atexit_destructor_for__mm_server_search_lan_ping_interval__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_server_search_lan_ping_interval__()
{
  ConVar::~ConVar(this: &mm_server_search_lan_ping_interval);
}

//------------------------------------------------------------------------------
// Address: 0x10055210
// Name: _dynamic_atexit_destructor_for__mm_server_search_lan_ping_duration__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_server_search_lan_ping_duration__()
{
  ConVar::~ConVar(this: &mm_server_search_lan_ping_duration);
}

//------------------------------------------------------------------------------
// Address: 0x10055220
// Name: _dynamic_atexit_destructor_for__mm_server_search_lan_ports__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_server_search_lan_ports__()
{
  ConVar::~ConVar(this: &mm_server_search_lan_ports);
}

//------------------------------------------------------------------------------
// Address: 0x10055230
// Name: _dynamic_atexit_destructor_for__g_ServerManager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ServerManager__()
{
  CServerManager::~CServerManager(this: &g_ServerManager);
}

//------------------------------------------------------------------------------
// Address: 0x10055240
// Name: _dynamic_atexit_destructor_for__g_MatchNetMsgControllerBase__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_MatchNetMsgControllerBase__()
{
  g_MatchNetMsgControllerBase.__vftable = (CMatchNetworkMsgControllerBase_vtbl *)&CMatchNetworkMsgControllerBase::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10055250
// Name: _dynamic_atexit_destructor_for__s_MatchSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_MatchSystem__()
{
  s_MatchSystem.__vftable = (CMatchSystem_vtbl *)&CMatchSystem::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10055260
// Name: _dynamic_atexit_destructor_for__mm_disable_listen_server__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_disable_listen_server__()
{
  ConVar::~ConVar(this: &mm_disable_listen_server);
}

//------------------------------------------------------------------------------
// Address: 0x10055270
// Name: _dynamic_atexit_destructor_for__mm_ignored_sessions_forget_time__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_ignored_sessions_forget_time__()
{
  ConVar::~ConVar(this: &mm_ignored_sessions_forget_time);
}

//------------------------------------------------------------------------------
// Address: 0x10055280
// Name: _dynamic_atexit_destructor_for__mm_ignored_sessions_forget_pass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_ignored_sessions_forget_pass__()
{
  ConVar::~ConVar(this: &mm_ignored_sessions_forget_pass);
}

//------------------------------------------------------------------------------
// Address: 0x10055290
// Name: _dynamic_atexit_destructor_for__g_IgnoredSessionsMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_IgnoredSessionsMgr__()
{
  CUtlRBTree<CUtlMap<XNKID,CIgnoredSessionsMgr::SessionSearchPass_t,unsigned short>::Node_t,unsigned short,CUtlMap<XNKID,CIgnoredSessionsMgr::SessionSearchPass_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<XNKID,CIgnoredSessionsMgr::SessionSearchPass_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<XNKID,CIgnoredSessionsMgr::SessionSearchPass_t,unsigned short>::Node_t,unsigned short,CUtlMap<XNKID,CIgnoredSessionsMgr::SessionSearchPass_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<XNKID,CIgnoredSessionsMgr::SessionSearchPass_t,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &g_IgnoredSessionsMgr.m_IgnoredSessionsAndTime.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x100552A0
// Name: _dynamic_atexit_destructor_for__mm_dlc_debugprint_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_dlc_debugprint_command__()
{
  ConCommand::~ConCommand(this: &mm_dlc_debugprint_command);
}

//------------------------------------------------------------------------------
// Address: 0x100552B0
// Name: _dynamic_atexit_destructor_for__g_DlcManager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DlcManager__()
{
  g_DlcManager.IDlcManager::__vftable = (CDlcManager_vtbl *)&CDlcManager::`vftable'{for `IDlcManager'};
  g_DlcManager.IMatchEventsSink::__vftable = (IMatchEventsSink_vtbl *)&CDlcManager::`vftable'{for `IMatchEventsSink'};
  if ( g_DlcManager.m_pDataInfo != nullptr )
    KeyValues::deleteThis(this: g_DlcManager.m_pDataInfo);
  g_DlcManager.m_pDataInfo = nullptr;
  g_DlcManager.m_CallbackOnDLCInstalled.__vftable = (CCallbackManual<CDlcManager,DlcInstalled_t,0>_vtbl *)&CCallback<CDlcManager,DlcInstalled_t,0>::`vftable';
  if ( (g_DlcManager.m_CallbackOnDLCInstalled.m_nCallbackFlags & 1) != 0 )
    _SteamAPI_UnregisterCallback(a1: &g_DlcManager.m_CallbackOnDLCInstalled);
}
