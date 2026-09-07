// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/hltvtest.cpp
// Functions: 3
// ============================================================

#include "engine\hltvtest.h"

//------------------------------------------------------------------------------
// Address: 0x10183EC0
// Name: public: void CHLTVTestSystem::RunFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CHLTVTestSystem::RunFrame(CHLTVTestSystem *this@<ecx>, int a2@<ebx>)
{
  int i; // esi

  for ( i = 0; i < this->m_Servers.m_Size; ++i )
    CHLTVServer::RunFrame(this: this->m_Servers.m_Memory.m_pMemory[i], a2, p_m_ClientState: (CHLTVClientState *)this);
}

//------------------------------------------------------------------------------
// Address: 0x10183EF0
// Name: public: bool CHLTVTestSystem::StopsTest(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHLTVTestSystem::StopsTest(CHLTVTestSystem *this)
{
  int i; // edi
  int j; // edi
  CHLTVServer *v4; // ecx
  bool v5; // sf

  for ( i = 0; i < this->m_Servers.m_Size; ++i )
    this->m_Servers.m_Memory.m_pMemory[i]->Shutdown(this: &this->m_Servers.m_Memory.m_pMemory[i]->CBaseServer);
  for ( j = 0; j < this->m_Servers.m_Size; ++j )
  {
    v4 = this->m_Servers.m_Memory.m_pMemory[j];
    if ( v4 != nullptr )
      ((void (__thiscall *)(CHLTVServer *, int))v4->dtr_IGameEventListener2)(a1: v4, a2: 1);
  }
  v5 = this->m_Servers.m_Memory.m_nGrowSize < 0;
  this->m_Servers.m_Size = 0;
  if ( !v5 )
  {
    if ( this->m_Servers.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Servers.m_Memory.m_pMemory);
      this->m_Servers.m_Memory.m_pMemory = nullptr;
    }
    this->m_Servers.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Servers.m_pElements = this->m_Servers.m_Memory.m_pMemory;
  NET_RemoveAllExtraSockets();
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10183F80
// Name: public: CHLTVTestSystem::~CHLTVTestSystem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVTestSystem::~CHLTVTestSystem(CHLTVTestSystem *this)
{
  CHLTVTestSystem::StopsTest(this);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>((CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)this);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x101842B0
// Name: public: void CHLTVTestSystem::RunFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CHLTVTestSystem::RunFrame(CHLTVTestSystem *this@<ecx>, int a2@<ebx>)
{
  int i; // esi

  for ( i = 0; i < this->m_Servers.m_Size; ++i )
    CHLTVServer::RunFrame(this: this->m_Servers.m_Memory.m_pMemory[i], a2, p_m_ClientState: (CHLTVClientState *)this);
}

//------------------------------------------------------------------------------
// Address: 0x101842E0
// Name: public: bool CHLTVTestSystem::StopsTest(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHLTVTestSystem::StopsTest(CHLTVTestSystem *this)
{
  int i; // edi
  int j; // edi
  CHLTVServer *v4; // ecx
  bool v5; // sf

  for ( i = 0; i < this->m_Servers.m_Size; ++i )
    this->m_Servers.m_Memory.m_pMemory[i]->Shutdown(this: &this->m_Servers.m_Memory.m_pMemory[i]->CBaseServer);
  for ( j = 0; j < this->m_Servers.m_Size; ++j )
  {
    v4 = this->m_Servers.m_Memory.m_pMemory[j];
    if ( v4 != nullptr )
      ((void (__thiscall *)(CHLTVServer *, int))v4->dtr_IGameEventListener2)(a1: v4, a2: 1);
  }
  v5 = this->m_Servers.m_Memory.m_nGrowSize < 0;
  this->m_Servers.m_Size = 0;
  if ( !v5 )
  {
    if ( this->m_Servers.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Servers.m_Memory.m_pMemory);
      this->m_Servers.m_Memory.m_pMemory = nullptr;
    }
    this->m_Servers.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Servers.m_pElements = this->m_Servers.m_Memory.m_pMemory;
  NET_RemoveAllExtraSockets();
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10184370
// Name: public: CHLTVTestSystem::~CHLTVTestSystem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLTVTestSystem::~CHLTVTestSystem(CHLTVTestSystem *this)
{
  CHLTVTestSystem::StopsTest(this);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>((CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x1031E460
// Name: _dynamic_initializer_for__Test_Wait_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__Test_Wait_command__()
{
  ConCommand::ConCommand(
    this: &Test_Wait_command,
    pName: "Test_Wait",
    callback: Test_Wait,
    pHelpString: defaultValue,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__Test_Wait_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E490
// Name: _dynamic_initializer_for__Test_RunFrame_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__Test_RunFrame_command__()
{
  ConCommand::ConCommand(
    this: &Test_RunFrame_command,
    pName: "Test_RunFrame",
    callback: Test_RunFrame,
    pHelpString: defaultValue,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__Test_RunFrame_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E4C0
// Name: _dynamic_initializer_for__Test_WaitForCheckPoint_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__Test_WaitForCheckPoint_command__()
{
  ConCommand::ConCommand(
    this: &Test_WaitForCheckPoint_command,
    pName: "Test_WaitForCheckPoint",
    callback: Test_WaitForCheckPoint,
    pHelpString: defaultValue,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__Test_WaitForCheckPoint_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E4F0
// Name: _dynamic_initializer_for__Test_StartLoop_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__Test_StartLoop_command__()
{
  ConCommand::ConCommand(
    this: &Test_StartLoop_command,
    pName: "Test_StartLoop",
    callback: Test_StartLoop,
    pHelpString: "Test_StartLoop <loop name> - Denote the start of a loop. Really just defines a named point you can jump to.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__Test_StartLoop_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E520
// Name: _dynamic_initializer_for__Test_LoopCount_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__Test_LoopCount_command__()
{
  ConCommand::ConCommand(
    this: &Test_LoopCount_command,
    pName: "Test_LoopCount",
    callback: Test_LoopCount,
    pHelpString: "Test_LoopCount <loop name> <count> - loop back to the specified loop start point the specified # of times.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__Test_LoopCount_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E550
// Name: _dynamic_initializer_for__Test_Loop_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__Test_Loop_command__()
{
  ConCommand::ConCommand(
    this: &Test_Loop_command,
    pName: "Test_Loop",
    callback: Test_Loop,
    pHelpString: "Test_Loop <loop name> - loop back to the specified loop start point unconditionally.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__Test_Loop_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E580
// Name: _dynamic_initializer_for__Test_LoopForNumSeconds_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__Test_LoopForNumSeconds_command__()
{
  ConCommand::ConCommand(
    this: &Test_LoopForNumSeconds_command,
    pName: "Test_LoopForNumSeconds",
    callback: Test_LoopForNumSeconds,
    pHelpString: "Test_LoopForNumSeconds <loop name> <time> - loop back to the specified start point for the specified # of seconds.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__Test_LoopForNumSeconds_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E5B0
// Name: _dynamic_initializer_for__Test_RandomChance_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__Test_RandomChance_command__()
{
  ConCommand::ConCommand(
    this: &Test_RandomChance_command,
    pName: "Test_RandomChance",
    callback: Test_RandomChance,
    pHelpString: "Test_RandomChance <percent chance, 0-100> <token1> <token2...> - Roll the dice and maybe run the command following t"
    "he percentage chance.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__Test_RandomChance_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E5E0
// Name: _dynamic_initializer_for__Test_SendKey_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__Test_SendKey_command__()
{
  ConCommand::ConCommand(
    this: &Test_SendKey_command,
    pName: "Test_SendKey",
    callback: Test_SendKey,
    pHelpString: defaultValue,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__Test_SendKey_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E610
// Name: _dynamic_initializer_for__Test_StartScript_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__Test_StartScript_command__()
{
  ConCommand::ConCommand(
    this: &Test_StartScript_command,
    pName: "Test_StartScript",
    callback: Test_StartScript,
    pHelpString: "Start a test script running..",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__Test_StartScript_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10326EA0
// Name: _dynamic_atexit_destructor_for__Test_Wait_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__Test_Wait_command__()
{
  ConCommand::~ConCommand(this: &Test_Wait_command);
}

//------------------------------------------------------------------------------
// Address: 0x10326EB0
// Name: _dynamic_atexit_destructor_for__Test_RunFrame_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__Test_RunFrame_command__()
{
  ConCommand::~ConCommand(this: &Test_RunFrame_command);
}

//------------------------------------------------------------------------------
// Address: 0x10326EC0
// Name: _dynamic_atexit_destructor_for__Test_WaitForCheckPoint_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__Test_WaitForCheckPoint_command__()
{
  ConCommand::~ConCommand(this: &Test_WaitForCheckPoint_command);
}

//------------------------------------------------------------------------------
// Address: 0x10326ED0
// Name: _dynamic_atexit_destructor_for__Test_StartLoop_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__Test_StartLoop_command__()
{
  ConCommand::~ConCommand(this: &Test_StartLoop_command);
}

//------------------------------------------------------------------------------
// Address: 0x10326EE0
// Name: _dynamic_atexit_destructor_for__Test_LoopCount_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__Test_LoopCount_command__()
{
  ConCommand::~ConCommand(this: &Test_LoopCount_command);
}

//------------------------------------------------------------------------------
// Address: 0x10326EF0
// Name: _dynamic_atexit_destructor_for__Test_Loop_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__Test_Loop_command__()
{
  ConCommand::~ConCommand(this: &Test_Loop_command);
}

//------------------------------------------------------------------------------
// Address: 0x10326F00
// Name: _dynamic_atexit_destructor_for__Test_LoopForNumSeconds_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__Test_LoopForNumSeconds_command__()
{
  ConCommand::~ConCommand(this: &Test_LoopForNumSeconds_command);
}

//------------------------------------------------------------------------------
// Address: 0x10326F10
// Name: _dynamic_atexit_destructor_for__Test_RandomChance_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__Test_RandomChance_command__()
{
  ConCommand::~ConCommand(this: &Test_RandomChance_command);
}

//------------------------------------------------------------------------------
// Address: 0x10326F20
// Name: _dynamic_atexit_destructor_for__Test_SendKey_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__Test_SendKey_command__()
{
  ConCommand::~ConCommand(this: &Test_SendKey_command);
}

//------------------------------------------------------------------------------
// Address: 0x10326F30
// Name: _dynamic_atexit_destructor_for__Test_StartScript_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__Test_StartScript_command__()
{
  ConCommand::~ConCommand(this: &Test_StartScript_command);
}

//------------------------------------------------------------------------------
// Address: 0x1031E640
// Name: _dynamic_initializer_for__g_InitTracker__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_InitTracker__()
{
  int v0; // edx
  int *p_m_nGrowSize; // eax

  v0 = 3;
  p_m_nGrowSize = &g_InitTracker.m_Funcs[0].m_Memory.m_nGrowSize;
  do
  {
    *(p_m_nGrowSize - 2) = 0;
    *(p_m_nGrowSize - 1) = 0;
    *p_m_nGrowSize = 0;
    p_m_nGrowSize[1] = 0;
    p_m_nGrowSize[2] = 0;
    p_m_nGrowSize += 5;
    --v0;
  }
  while ( v0 >= 0 );
  g_InitTracker.m_nNumFuncs[0] = 0;
  g_InitTracker.m_nNumFuncs[1] = 0;
  g_InitTracker.m_nNumFuncs[2] = 0;
  g_InitTracker.m_nNumFuncs[3] = 0;
  return atexit(func: dynamic_atexit_destructor_for__g_InitTracker__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E690
// Name: _dynamic_initializer_for____g_CVoiceServer_singleton__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____g_CVoiceServer_singleton__()
{
  return atexit(func: dynamic_atexit_destructor_for____g_CVoiceServer_singleton__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E6A0
// Name: _dynamic_initializer_for____g_CreateCVoiceServerIVoiceServer_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCVoiceServerIVoiceServer_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCVoiceServerIVoiceServer_reg,
           fn: _CreateCVoiceServerIVoiceServer_interface,
           pName: "VoiceServer002");
}

//------------------------------------------------------------------------------
// Address: 0x10326F40
// Name: _dynamic_atexit_destructor_for__g_TestScriptMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_TestScriptMgr__()
{
  CTestScriptMgr::~CTestScriptMgr(this: &g_TestScriptMgr);
}

//------------------------------------------------------------------------------
// Address: 0x10326F50
// Name: _dynamic_atexit_destructor_for__g_InitTracker__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_InitTracker__()
{
  CInitTracker::~CInitTracker(this: &g_InitTracker);
}

//------------------------------------------------------------------------------
// Address: 0x10326F60
// Name: _dynamic_atexit_destructor_for____g_CVoiceServer_singleton__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____g_CVoiceServer_singleton__()
{
  _g_CVoiceServer_singleton.__vftable = (CVoiceServer_vtbl *)&IVoiceServer::`vftable';
}

} // namespace engine_xlsp
