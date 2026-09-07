// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/vscript_shared.cpp
// Functions: 39
// ============================================================

#include "game\shared\vscript_shared.h"

//------------------------------------------------------------------------------
// Address: 0x101AAA20
// Name: script_debug_client
// Source: json
//------------------------------------------------------------------------------
void __cdecl script_debug_client()
{
  if ( g_pScriptVM != nullptr )
  {
    g_pScriptVM->ConnectDebugger(this: g_pScriptVM);
  }
  else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VScript, a2: 1) != 0 )
  {
    _LoggingSystem_Log(a1: LOG_VScript, a2: 1, a3: "Scripting disabled or no server running\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101AAA60
// Name: script_dump_all_client
// Source: json
//------------------------------------------------------------------------------
void __cdecl script_dump_all_client()
{
  if ( g_pScriptVM != nullptr )
  {
    g_pScriptVM->DumpState(this: g_pScriptVM);
  }
  else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VScript, a2: 1) != 0 )
  {
    _LoggingSystem_Log(a1: LOG_VScript, a2: 1, a3: "Scripting disabled or no server running\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101AAAB0
// Name: script_client
// Source: json
//------------------------------------------------------------------------------
void __cdecl script_client(const CCommand *args)
{
  char *m_pArgSBuffer; // eax
  _BYTE *i; // eax
  const char *v3; // eax
  char *j; // esi

  if ( args->m_nArgc > 1 && *args->m_ppArgv[1] != 0 )
  {
    if ( g_pScriptVM != nullptr )
    {
      m_pArgSBuffer = args->m_pArgSBuffer;
      if ( args->m_nArgc == 0 )
        m_pArgSBuffer = (char *)prType;
      for ( i = m_pArgSBuffer + 13; *i == 32; ++i )
        ;
      if ( *i != 0 )
      {
        if ( *i == 34 )
        {
          v3 = i + 1;
          for ( j = (char *)v3; *j != 34; ++j )
            ;
          if ( *j != 0 )
          {
            *j = 0;
            g_pScriptVM->Run_3(this: g_pScriptVM, a2: v3, a3: true);
            *j = 34;
          }
        }
        else
        {
          ((void (__stdcall *)(_BYTE *, int))g_pScriptVM->Run_3)(a1: i, a2: 1);
        }
      }
    }
    else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VScript, a2: 1) != 0 )
    {
      _LoggingSystem_Log(a1: LOG_VScript, a2: 1, a3: "Scripting disabled or no server running\n");
    }
  }
  else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VScript, a2: 1) != 0 )
  {
    _LoggingSystem_Log(a1: LOG_VScript, a2: 1, a3: "No function name specified\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101AABA0
// Name: public: char const __near * CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
char *CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf(CFmtStrN<256> *this, const char *pszFormat, ...)
{
  CFmtStrN<256> *v2; // esi
  bool v3; // zf
  va_list params; // [esp+18h] [ebp+10h] BYREF

  va_start(params, pszFormat);
  v2 = this;
  this->InitQuietTruncation(this);
  HIBYTE(this) = 0;
  V_vsnprintfRet(pDest: v2->m_szBuf, maxLen: 0xFFu, pFormat: pszFormat, params, pbTruncated: (bool *)&this + 3);
  v3 = HIBYTE(this) == 0;
  v2->m_szBuf[255] = 0;
  if ( !v3 && !v2->m_bQuietTruncation && `CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf'::`4'::scAsserted < 5 )
    ++`CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf'::`4'::scAsserted;
  v2->m_nLength = _V_strlen(str: v2->m_szBuf);
  return v2->m_szBuf;
}

//------------------------------------------------------------------------------
// Address: 0x101AAC10
// Name: script_help_client
// Source: json
//------------------------------------------------------------------------------
void __cdecl script_help_client(const CCommand *args)
{
  const char *v1; // ecx
  CFmtStrN<256> *v2; // eax
  CFmtStrN<256> v3; // [esp+0h] [ebp-10Ch] BYREF

  if ( g_pScriptVM != nullptr )
  {
    v1 = "*";
    if ( args->m_nArgc > 1 && *args->m_ppArgv[1] != 0 )
      v1 = args->m_ppArgv[1];
    v2 = CFmtStrN<256>::CFmtStrN<256>(this: &v3, pszFormat: "PrintHelp( \"%s\" );", v1);
    g_pScriptVM->Run_3(this: g_pScriptVM, a2: v2->m_szBuf, a3: true);
  }
  else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VScript, a2: 1) != 0 )
  {
    _LoggingSystem_Log(a1: LOG_VScript, a2: 1, a3: "Scripting disabled or no server running\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101AACA0
// Name: struct HSCRIPT__ __near * VScriptCompileScript(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
HSCRIPT__ *__usercall VScriptCompileScript@<eax>(int a1@<ebx>, int a2@<edi>, int a3@<esi>, const char *pszScriptName)
{
  const char *v5; // edi
  const char *v6; // eax
  const char *v7; // esi
  unsigned __int8 *m_pMemory; // esi
  char *v9; // eax
  HSCRIPT__ *v10; // esi
  CFmtStrN<256> scriptPath; // [esp+0h] [ebp-13Ch] BYREF
  CUtlBuffer bufferScript; // [esp+10Ch] [ebp-30h] BYREF

  if ( g_pScriptVM == nullptr )
    return nullptr;
  v5 = pszExtensions[((int (__thiscall *)(IScriptVM *, int, int, int))g_pScriptVM->GetLanguage)(
                       a1: g_pScriptVM,
                       a2,
                       a3,
                       a4: a1)];
  v6 = _V_strrchr(s: pszScriptName, c: 46);
  v7 = v6;
  if ( v6 != nullptr && _V_strcmp(s1: v6, s2: v5) != 0 )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VScript, a2: 1) != 0 )
    {
      _LoggingSystem_Log(a1: LOG_VScript, a2: 1, a3: "Script file type does not match VM type\n");
      return nullptr;
    }
    return nullptr;
  }
  scriptPath.__vftable = (CFmtStrN<256>_vtbl *)&CFmtStrN<256>::`vftable';
  *(_WORD *)&scriptPath.m_bQuietTruncation = 1;
  scriptPath.m_nLength = 0;
  if ( v7 != nullptr )
    CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf(this: &scriptPath, pszFormat: "scripts/vscripts/%s", pszScriptName);
  else
    CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf(
      this: &scriptPath,
      pszFormat: "scripts/vscripts/%s%s",
      pszScriptName,
      v5);
  CUtlBuffer::CUtlBuffer(this: &bufferScript, growSize: 0, initSize: 0, nFlags: 0);
  if ( g_pScriptVM->GetLanguage(this: g_pScriptVM) == SL_PYTHON )
  {
    m_pMemory = nullptr;
  }
  else
  {
    if ( !filesystem->ReadFile(
            this: &filesystem->IBaseFileSystem,
            a2: scriptPath.m_szBuf,
            a3: "GAME",
            a4: &bufferScript,
            a5: 0,
            a6: 0,
            a7: nullptr)
      && (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VScript, a2: 1) != 0 )
    {
      _LoggingSystem_Log(a1: LOG_VScript, a2: 1, a3: "Script not found (%s) \n", scriptPath.m_szBuf);
    }
    m_pMemory = bufferScript.m_Memory.m_pMemory;
    if ( bufferScript.m_Memory.m_pMemory == nullptr || *bufferScript.m_Memory.m_pMemory == 0 )
    {
      if ( bufferScript.m_Memory.m_nGrowSize >= 0 && bufferScript.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bufferScript.m_Memory.m_pMemory);
      return nullptr;
    }
  }
  v9 = _V_strrchr(s: scriptPath.m_szBuf, c: 47);
  v10 = g_pScriptVM->CompileScript(this: g_pScriptVM, a2: m_pMemory, a3: v9 + 1);
  if ( v10 == nullptr && (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VScript, a2: 1) != 0 )
    _LoggingSystem_Log(
      a1: LOG_VScript,
      a2: 1,
      a3: "FAILED to compile and execute script file named %s\n",
      scriptPath.m_szBuf);
  if ( bufferScript.m_Memory.m_nGrowSize >= 0 && bufferScript.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bufferScript.m_Memory.m_pMemory);
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x101AAEA0
// Name: bool VScriptRunScript(char const __near *,struct HSCRIPT__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
bool __usercall VScriptRunScript@<al>(int a1@<ebx>, int a2@<edi>, const char *pszScriptName, HSCRIPT__ *hScope)
{
  HSCRIPT__ *v5; // eax
  bool v6; // bl
  ScriptStatus_t v7; // eax

  if ( g_pScriptVM == nullptr )
    return false;
  if ( pszScriptName == nullptr || *pszScriptName == 0 )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VScript, a2: 1) != 0 )
      _LoggingSystem_Log(a1: LOG_VScript, a2: 1, a3: "Cannot run script: NULL script name\n");
    return false;
  }
  if ( g_ScriptServerRunScriptDepth > 16 )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VScript, a2: 1) != 0 )
      _LoggingSystem_Log(a1: LOG_VScript, a2: 1, a3: "IncludeScript stack overflow\n");
    return false;
  }
  ++g_ScriptServerRunScriptDepth;
  v5 = VScriptCompileScript(a1, a2, a3: (int)pszScriptName, pszScriptName);
  v6 = false;
  if ( v5 != nullptr )
  {
    v7 = g_pScriptVM->Run_2(this: g_pScriptVM, a2: v5, a3: hScope, a4: true);
    v6 = v7 != SCRIPT_ERROR;
    if ( v7 == SCRIPT_ERROR && (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VScript, a2: 1) != 0 )
      _LoggingSystem_Log(a1: LOG_VScript, a2: 1, a3: "Error running script named %s\n", pszScriptName);
  }
  --g_ScriptServerRunScriptDepth;
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x101AAFA0
// Name: script_execute_client
// Source: json
//------------------------------------------------------------------------------
void __cdecl script_execute_client(const CCommand *args)
{
  const char *v1; // eax

  if ( args->m_nArgc > 1 && *(v1 = args->m_ppArgv[1]) != 0 )
  {
    if ( g_pScriptVM != nullptr )
    {
      VScriptRunScript(pszScriptName: v1, hScope: nullptr, bWarnMissing: true);
    }
    else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VScript, a2: 1) != 0 )
    {
      _LoggingSystem_Log(a1: LOG_VScript, a2: 1, a3: "Scripting disabled or no server running\n");
    }
  }
  else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VScript, a2: 1) != 0 )
  {
    _LoggingSystem_Log(a1: LOG_VScript, a2: 1, a3: "No script specified\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x104200F0
// Name: _dynamic_initializer_for__script_client_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__script_client_command__()
{
  ConCommand::ConCommand(
    this: &script_client_command,
    pName: "script_client",
    callback: (void (__cdecl *)())script_client,
    pHelpString: "Run the text as a script",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__script_client_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10420120
// Name: _dynamic_initializer_for__script_execute_client_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__script_execute_client_command__()
{
  ConCommand::ConCommand(
    this: &script_execute_client_command,
    pName: "script_execute_client",
    callback: (void (__cdecl *)())script_execute_client,
    pHelpString: "Run a vscript file",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__script_execute_client_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10420150
// Name: _dynamic_initializer_for__script_debug_client_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__script_debug_client_command__()
{
  ConCommand::ConCommand(
    this: &script_debug_client_command,
    pName: "script_debug_client",
    callback: script_debug_client,
    pHelpString: "Connect the vscript VM to the script debugger",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__script_debug_client_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10420180
// Name: _dynamic_initializer_for__script_help_client_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__script_help_client_command__()
{
  ConCommand::ConCommand(
    this: &script_help_client_command,
    pName: "script_help_client",
    callback: (void (__cdecl *)())script_help_client,
    pHelpString: "Output help for script functions, optionally with a search string",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__script_help_client_command__);
}

//------------------------------------------------------------------------------
// Address: 0x104201B0
// Name: _dynamic_initializer_for__script_dump_all_client_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__script_dump_all_client_command__()
{
  ConCommand::ConCommand(
    this: &script_dump_all_client_command,
    pName: "script_dump_all_client",
    callback: script_dump_all_client,
    pHelpString: "Dump the state of the VM to the console",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__script_dump_all_client_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10434F40
// Name: _dynamic_atexit_destructor_for__script_client_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__script_client_command__()
{
  ConCommand::~ConCommand(this: &script_client_command);
}

//------------------------------------------------------------------------------
// Address: 0x10434F50
// Name: _dynamic_atexit_destructor_for__script_execute_client_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__script_execute_client_command__()
{
  ConCommand::~ConCommand(this: &script_execute_client_command);
}

//------------------------------------------------------------------------------
// Address: 0x10434F60
// Name: _dynamic_atexit_destructor_for__script_debug_client_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__script_debug_client_command__()
{
  ConCommand::~ConCommand(this: &script_debug_client_command);
}

//------------------------------------------------------------------------------
// Address: 0x10434F70
// Name: _dynamic_atexit_destructor_for__script_help_client_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__script_help_client_command__()
{
  ConCommand::~ConCommand(this: &script_help_client_command);
}

//------------------------------------------------------------------------------
// Address: 0x10434F80
// Name: _dynamic_atexit_destructor_for__script_dump_all_client_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__script_dump_all_client_command__()
{
  ConCommand::~ConCommand(this: &script_dump_all_client_command);
}

//------------------------------------------------------------------------------
// Address: 0x10434F90
// Name: _dynamic_atexit_destructor_for__m_WeaponInfoDatabase__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__m_WeaponInfoDatabase__()
{
  CUtlDict<FileWeaponInfo_t *,unsigned short>::RemoveAll(this: &m_WeaponInfoDatabase);
  CUtlRBTree<CUtlMap<char const *,FileWeaponInfo_t *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,FileWeaponInfo_t *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,FileWeaponInfo_t *,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,FileWeaponInfo_t *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,FileWeaponInfo_t *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,FileWeaponInfo_t *,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &m_WeaponInfoDatabase.m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x10434FB0
// Name: _dynamic_atexit_destructor_for__hud_drawhistory_time__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__hud_drawhistory_time__()
{
  ConVar::~ConVar(this: &hud_drawhistory_time);
}

//------------------------------------------------------------------------------
// Address: 0x10434FC0
// Name: _dynamic_atexit_destructor_for__hud_fastswitch__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__hud_fastswitch__()
{
  ConVar::~ConVar(this: &hud_fastswitch);
}

//------------------------------------------------------------------------------
// Address: 0x10434FD0
// Name: _dynamic_atexit_destructor_for__slot1__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__slot1__()
{
  ConCommand::~ConCommand(this: &slot1);
}

//------------------------------------------------------------------------------
// Address: 0x10434FE0
// Name: _dynamic_atexit_destructor_for__slot2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__slot2__()
{
  ConCommand::~ConCommand(this: &slot2);
}

//------------------------------------------------------------------------------
// Address: 0x10434FF0
// Name: _dynamic_atexit_destructor_for__slot3__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__slot3__()
{
  ConCommand::~ConCommand(this: &slot3);
}

//------------------------------------------------------------------------------
// Address: 0x10435000
// Name: _dynamic_atexit_destructor_for__slot4__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__slot4__()
{
  ConCommand::~ConCommand(this: &slot4);
}

//------------------------------------------------------------------------------
// Address: 0x10435010
// Name: _dynamic_atexit_destructor_for__slot5__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__slot5__()
{
  ConCommand::~ConCommand(this: &slot5);
}

//------------------------------------------------------------------------------
// Address: 0x10435020
// Name: _dynamic_atexit_destructor_for__slot6__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__slot6__()
{
  ConCommand::~ConCommand(this: &slot6);
}

//------------------------------------------------------------------------------
// Address: 0x10435030
// Name: _dynamic_atexit_destructor_for__slot7__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__slot7__()
{
  ConCommand::~ConCommand(this: &slot7);
}

//------------------------------------------------------------------------------
// Address: 0x10435040
// Name: _dynamic_atexit_destructor_for__slot8__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__slot8__()
{
  ConCommand::~ConCommand(this: &slot8);
}

//------------------------------------------------------------------------------
// Address: 0x10435050
// Name: _dynamic_atexit_destructor_for__slot9__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__slot9__()
{
  ConCommand::~ConCommand(this: &slot9);
}

//------------------------------------------------------------------------------
// Address: 0x10435060
// Name: _dynamic_atexit_destructor_for__slot0__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__slot0__()
{
  ConCommand::~ConCommand(this: &slot0);
}

//------------------------------------------------------------------------------
// Address: 0x10435070
// Name: _dynamic_atexit_destructor_for__slot10__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__slot10__()
{
  ConCommand::~ConCommand(this: &slot10);
}

//------------------------------------------------------------------------------
// Address: 0x10435080
// Name: _dynamic_atexit_destructor_for__cancelselect__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cancelselect__()
{
  ConCommand::~ConCommand(this: &cancelselect);
}

//------------------------------------------------------------------------------
// Address: 0x10435090
// Name: _dynamic_atexit_destructor_for__invnext__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__invnext__()
{
  ConCommand::~ConCommand(this: &invnext);
}

//------------------------------------------------------------------------------
// Address: 0x104350A0
// Name: _dynamic_atexit_destructor_for__invprev__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__invprev__()
{
  ConCommand::~ConCommand(this: &invprev);
}

//------------------------------------------------------------------------------
// Address: 0x104350B0
// Name: _dynamic_atexit_destructor_for__lastinv__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__lastinv__()
{
  ConCommand::~ConCommand(this: &lastinv);
}

//------------------------------------------------------------------------------
// Address: 0x104350C0
// Name: _dynamic_atexit_destructor_for__invnextgrenade__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__invnextgrenade__()
{
  ConCommand::~ConCommand(this: &invnextgrenade);
}

//------------------------------------------------------------------------------
// Address: 0x104350D0
// Name: _dynamic_atexit_destructor_for__invnextnongrenade__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__invnextnongrenade__()
{
  ConCommand::~ConCommand(this: &invnextnongrenade);
}

//------------------------------------------------------------------------------
// Address: 0x104350E0
// Name: _dynamic_atexit_destructor_for__gWR__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__gWR__()
{
  ;
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x10262F20
// Name: script_debug
// Source: json
//------------------------------------------------------------------------------
void __cdecl script_debug()
{
  if ( g_pScriptVM != nullptr )
  {
    g_pScriptVM->ConnectDebugger(this: g_pScriptVM);
  }
  else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VScript, a2: 1) != 0 )
  {
    _LoggingSystem_Log(a1: LOG_VScript, a2: 1, a3: "Scripting disabled or no server running\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10262F60
// Name: script_dump_all
// Source: json
//------------------------------------------------------------------------------
void __cdecl script_dump_all()
{
  if ( g_pScriptVM != nullptr )
  {
    g_pScriptVM->DumpState(this: g_pScriptVM);
  }
  else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VScript, a2: 1) != 0 )
  {
    _LoggingSystem_Log(a1: LOG_VScript, a2: 1, a3: "Scripting disabled or no server running\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10262FC0
// Name: script
// Source: json
//------------------------------------------------------------------------------
void __cdecl script(const CCommand *args)
{
  char *m_pArgSBuffer; // eax
  _BYTE *i; // eax
  const char *v3; // eax
  char *j; // esi

  if ( args->m_nArgc > 1 && *args->m_ppArgv[1] != 0 )
  {
    if ( g_pScriptVM != nullptr )
    {
      m_pArgSBuffer = args->m_pArgSBuffer;
      if ( args->m_nArgc == 0 )
        m_pArgSBuffer = (char *)locale;
      for ( i = m_pArgSBuffer + 6; *i == 32; ++i )
        ;
      if ( *i != 0 )
      {
        if ( *i == 34 )
        {
          v3 = i + 1;
          for ( j = (char *)v3; *j != 34; ++j )
            ;
          if ( *j != 0 )
          {
            *j = 0;
            g_pScriptVM->Run_3(this: g_pScriptVM, a2: v3, a3: true);
            *j = 34;
          }
        }
        else
        {
          ((void (__stdcall *)(_BYTE *, int))g_pScriptVM->Run_3)(a1: i, a2: 1);
        }
      }
    }
    else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VScript, a2: 1) != 0 )
    {
      _LoggingSystem_Log(a1: LOG_VScript, a2: 1, a3: "Scripting disabled or no server running\n");
    }
  }
  else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VScript, a2: 1) != 0 )
  {
    _LoggingSystem_Log(a1: LOG_VScript, a2: 1, a3: "No function name specified\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x102630B0
// Name: script_help
// Source: json
//------------------------------------------------------------------------------
void __cdecl script_help(const CCommand *args)
{
  const char *v1; // ecx
  CFmtStrN<256> *v2; // eax
  CFmtStrN<256> v3; // [esp+0h] [ebp-10Ch] BYREF

  if ( g_pScriptVM != nullptr )
  {
    v1 = "*";
    if ( args->m_nArgc > 1 && *args->m_ppArgv[1] != 0 )
      v1 = args->m_ppArgv[1];
    v2 = CFmtStrN<256>::CFmtStrN<256>(this: &v3, pszFormat: "PrintHelp( \"%s\" );", v1);
    g_pScriptVM->Run_3(this: g_pScriptVM, a2: v2->m_szBuf, a3: true);
  }
  else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VScript, a2: 1) != 0 )
  {
    _LoggingSystem_Log(a1: LOG_VScript, a2: 1, a3: "Scripting disabled or no server running\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10263140
// Name: struct HSCRIPT__ __near * VScriptCompileScript(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
HSCRIPT__ *__usercall VScriptCompileScript@<eax>(int a1@<ebx>, int a2@<edi>, int a3@<esi>, const char *pszScriptName)
{
  const char *v5; // edi
  const char *v6; // eax
  const char *v7; // esi
  unsigned __int8 *m_pMemory; // esi
  char *v9; // eax
  HSCRIPT__ *v10; // esi
  CFmtStrN<256> scriptPath; // [esp+0h] [ebp-13Ch] BYREF
  CUtlBuffer bufferScript; // [esp+10Ch] [ebp-30h] BYREF

  if ( g_pScriptVM == nullptr )
    return nullptr;
  v5 = pszExtensions[((int (__thiscall *)(IScriptVM *, int, int, int))g_pScriptVM->GetLanguage)(
                       a1: g_pScriptVM,
                       a2,
                       a3,
                       a4: a1)];
  v6 = _V_strrchr(s: pszScriptName, c: 46);
  v7 = v6;
  if ( v6 != nullptr && _V_strcmp(s1: v6, s2: v5) != 0 )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VScript, a2: 1) != 0 )
    {
      _LoggingSystem_Log(a1: LOG_VScript, a2: 1, a3: "Script file type does not match VM type\n");
      return nullptr;
    }
    return nullptr;
  }
  scriptPath.__vftable = (CFmtStrN<256>_vtbl *)&CFmtStrN<256>::`vftable';
  *(_WORD *)&scriptPath.m_bQuietTruncation = 1;
  scriptPath.m_nLength = 0;
  if ( v7 != nullptr )
    CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf(this: &scriptPath, pszFormat: "scripts/vscripts/%s", pszScriptName);
  else
    CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf(
      this: &scriptPath,
      pszFormat: "scripts/vscripts/%s%s",
      pszScriptName,
      v5);
  CUtlBuffer::CUtlBuffer(this: &bufferScript, growSize: 0, initSize: 0, nFlags: 0);
  if ( g_pScriptVM->GetLanguage(this: g_pScriptVM) == SL_PYTHON )
  {
    m_pMemory = nullptr;
  }
  else
  {
    if ( !filesystem->ReadFile(
            this: &filesystem->IBaseFileSystem,
            a2: scriptPath.m_szBuf,
            a3: "GAME",
            a4: &bufferScript,
            a5: 0,
            a6: 0,
            a7: nullptr)
      && (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VScript, a2: 1) != 0 )
    {
      _LoggingSystem_Log(a1: LOG_VScript, a2: 1, a3: "Script not found (%s) \n", scriptPath.m_szBuf);
    }
    m_pMemory = bufferScript.m_Memory.m_pMemory;
    if ( bufferScript.m_Memory.m_pMemory == nullptr || *bufferScript.m_Memory.m_pMemory == 0 )
    {
      if ( bufferScript.m_Memory.m_nGrowSize >= 0 && bufferScript.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bufferScript.m_Memory.m_pMemory);
      return nullptr;
    }
  }
  v9 = _V_strrchr(s: scriptPath.m_szBuf, c: 47);
  v10 = g_pScriptVM->CompileScript(this: g_pScriptVM, a2: m_pMemory, a3: v9 + 1);
  if ( v10 == nullptr && (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VScript, a2: 1) != 0 )
    _LoggingSystem_Log(
      a1: LOG_VScript,
      a2: 1,
      a3: "FAILED to compile and execute script file named %s\n",
      scriptPath.m_szBuf);
  if ( bufferScript.m_Memory.m_nGrowSize >= 0 && bufferScript.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bufferScript.m_Memory.m_pMemory);
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x10263340
// Name: bool VScriptRunScript(char const __near *,struct HSCRIPT__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
bool __usercall VScriptRunScript@<al>(int a1@<ebx>, int a2@<esi>, const char *pszScriptName, HSCRIPT__ *hScope)
{
  HSCRIPT__ *v5; // esi
  bool v6; // bl
  CBasePlayer *LocalPlayer; // eax
  ScriptStatus_t v8; // eax
  _DWORD v9[2]; // [esp+0h] [ebp-8h] BYREF

  if ( g_pScriptVM == nullptr )
    return false;
  if ( pszScriptName == nullptr || *pszScriptName == 0 )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VScript, a2: 1) != 0 )
      _LoggingSystem_Log(a1: LOG_VScript, a2: 1, a3: "Cannot run script: NULL script name\n");
    return false;
  }
  if ( g_ScriptServerRunScriptDepth > 16 )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VScript, a2: 1) != 0 )
    {
      _LoggingSystem_Log(a1: LOG_VScript, a2: 1, a3: "IncludeScript stack overflow\n");
      return false;
    }
    return false;
  }
  ++g_ScriptServerRunScriptDepth;
  v5 = VScriptCompileScript(a1, a2: (int)pszScriptName, a3: a2, pszScriptName);
  v6 = false;
  if ( v5 != nullptr )
  {
    if ( gpGlobals->maxClients == 1 )
    {
      LocalPlayer = UTIL_GetLocalPlayer();
      if ( LocalPlayer != nullptr )
      {
        v9[0] = CBaseEntity::GetScriptInstance(this: LocalPlayer);
        v9[1] = 33;
        g_pScriptVM->SetValue(this: g_pScriptVM, a2: nullptr, a3: "player", a4: (const ScriptVariant_t *)v9);
      }
    }
    v8 = g_pScriptVM->Run_2(this: g_pScriptVM, a2: v5, a3: hScope, a4: true);
    v6 = v8 != SCRIPT_ERROR;
    if ( v8 == SCRIPT_ERROR && (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VScript, a2: 1) != 0 )
      _LoggingSystem_Log(a1: LOG_VScript, a2: 1, a3: "Error running script named %s\n", pszScriptName);
  }
  --g_ScriptServerRunScriptDepth;
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x102634A0
// Name: script_execute
// Source: json
//------------------------------------------------------------------------------
void __usercall script_execute(int a1@<ebx>, int a2@<esi>, const CCommand *args)
{
  const char *v3; // eax

  if ( args->m_nArgc > 1 && *(v3 = args->m_ppArgv[1]) != 0 )
  {
    if ( g_pScriptVM != nullptr )
    {
      VScriptRunScript(a1, a2, pszScriptName: v3, hScope: nullptr);
    }
    else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VScript, a2: 1) != 0 )
    {
      _LoggingSystem_Log(a1: LOG_VScript, a2: 1, a3: "Scripting disabled or no server running\n");
    }
  }
  else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VScript, a2: 1) != 0 )
  {
    _LoggingSystem_Log(a1: LOG_VScript, a2: 1, a3: "No script specified\n");
  }
}

} // namespace server
