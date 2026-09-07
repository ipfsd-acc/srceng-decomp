// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/vscript_client.cpp
// Functions: 13
// ============================================================

#include "game\client\vscript_client.h"

//------------------------------------------------------------------------------
// Address: 0x101AA310
// Name: GetMapName
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl GetMapName()
{
  return engine->GetLevelName(this: engine);
}

//------------------------------------------------------------------------------
// Address: 0x101AA320
// Name: int GetDeveloperLevel(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetDeveloperLevel()
{
  if ( developer.m_pParent != nullptr )
    return developer.m_pParent->m_Value.m_nValue;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101AA330
// Name: public: static bool CNonMemberScriptBinding0<char const __near * (*)(void),char const __near *>::Call(void __near *,void __near *,struct ScriptVariant_t __near *,int,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CNonMemberScriptBinding0<char const * (__cdecl *)(void),char const *>::Call(
        int (*pFunction)(void),
        void *pContext,
        ScriptVariant_t *pArguments,
        int nArguments,
        ScriptVariant_t *pReturn)
{
  if ( nArguments != 0 || pReturn == nullptr || pContext != nullptr )
    return 0;
  pReturn->m_int = pFunction();
  pReturn->m_type = 32;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101AA360
// Name: public: static bool CNonMemberScriptBinding0<float (*)(void),float>::Call(void __near *,void __near *,struct ScriptVariant_t __near *,int,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CNonMemberScriptBinding0<float (__cdecl *)(void),float>::Call(
        double (*pFunction)(void),
        void *pContext,
        ScriptVariant_t *pArguments,
        int nArguments,
        ScriptVariant_t *pReturn)
{
  if ( nArguments != 0 || pReturn == nullptr || pContext != nullptr )
    return 0;
  pReturn->m_float = pFunction();
  pReturn->m_type = 1;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101AA390
// Name: public: static bool CNonMemberScriptBinding2<bool (*)(char const __near *,struct HSCRIPT__ __near *),bool,char const __near *,struct HSCRIPT__ __near *>::Call(void __near *,void __near *,struct ScriptVariant_t __near *,int,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CNonMemberScriptBinding2<bool (__cdecl *)(char const *,HSCRIPT__ *),bool,char const *,HSCRIPT__ *>::Call(
        int (__cdecl *pFunction)(const char *, int),
        void *pContext,
        ScriptVariant_t *pArguments,
        int nArguments,
        ScriptVariant_t *pReturn)
{
  const char *m_int; // eax

  if ( nArguments != 2 || pReturn == nullptr || pContext != nullptr )
    return 0;
  m_int = (const char *)pArguments->m_int;
  if ( pArguments->m_int == 0 )
    m_int = prType;
  pReturn->m_char = pFunction(a1: m_int, a2: pArguments[1].m_int);
  pReturn->m_type = 6;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101AA3E0
// Name: public: static bool CNonMemberScriptBinding0<int (*)(void),int>::Call(void __near *,void __near *,struct ScriptVariant_t __near *,int,struct ScriptVariant_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CNonMemberScriptBinding0<int (__cdecl *)(void),int>::Call(
        int (*pFunction)(void),
        void *pContext,
        ScriptVariant_t *pArguments,
        int nArguments,
        ScriptVariant_t *pReturn)
{
  if ( nArguments != 0 || pReturn == nullptr || pContext != nullptr )
    return 0;
  pReturn->m_int = pFunction();
  pReturn->m_type = 5;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101AA410
// Name: bool DoIncludeScript(char const __near *,struct HSCRIPT__ __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl DoIncludeScript(const char *pszScript, HSCRIPT__ *hScope)
{
  const char *v2; // eax
  CFmtStrN<256> *v3; // eax
  CFmtStrN<256> v5; // [esp+4h] [ebp-10Ch] BYREF

  if ( VScriptRunScript(pszScriptName: pszScript, hScope, bWarnMissing: true) )
    return 1;
  v2 = pszScript;
  if ( pszScript == nullptr )
    v2 = "unknown";
  v3 = CFmtStrN<256>::CFmtStrN<256>(this: &v5, pszFormat: "Failed to include script \"%s\"", v2);
  g_pScriptVM->RaiseException(this: g_pScriptVM, a2: v3->m_szBuf);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101AA480
// Name: public: virtual void CVScriptGameSystem::LevelInitPostEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVScriptGameSystem::LevelInitPostEntity(CVScriptGameSystem *this)
{
  this->m_bAllowEntityCreationInScripts = false;
}

//------------------------------------------------------------------------------
// Address: 0x101AA490
// Name: public: virtual void CVScriptGameSystem::LevelShutdownPostEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVScriptGameSystem::LevelShutdownPostEntity(CVScriptGameSystem *this)
{
  if ( g_pScriptVM != nullptr )
  {
    scriptmanager->DestroyVM(this: scriptmanager, a2: g_pScriptVM);
    g_pScriptVM = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101AA4C0
// Name: public: virtual void CVScriptGameSystem::FrameUpdatePostEntityThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVScriptGameSystem::FrameUpdatePostEntityThink(CVScriptGameSystem *this)
{
  if ( g_pScriptVM != nullptr )
    ((void (__stdcall *)(_DWORD))g_pScriptVM->Frame)(a1: *(_DWORD *)(gpGlobals.m_Index + 16));
}

//------------------------------------------------------------------------------
// Address: 0x101AA5F0
// Name: bool VScriptClientInit(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall VScriptClientInit@<al>(int a1@<ecx>, int a2@<edi>)
{
  ScriptLanguage_t v2; // ebx
  int v3; // eax
  const char *v4; // eax
  const char *pszScriptLanguage; // [esp+8h] [ebp-4h] BYREF

  if ( scriptmanager != nullptr )
  {
    v2 = SL_SQUIRREL;
    v3 = _CommandLine(a1);
    if ( (*(int (__thiscall **)(int, const char *, const char **))(*(_DWORD *)v3 + 12))(
           a1: v3,
           a2: "-scriptlang",
           a3: &pszScriptLanguage) != 0 )
    {
      if ( _V_stricmp(s1: pszScriptLanguage, s2: "gamemonkey") != 0 )
      {
        if ( _V_stricmp(s1: pszScriptLanguage, s2: "squirrel") != 0 )
        {
          if ( _V_stricmp(s1: pszScriptLanguage, s2: "python") != 0 )
          {
            DevWarning(
              a1: "-scriptlang does not recognize a language named '%s'. virtual machine did NOT start.\n",
              pszScriptLanguage);
            g_pScriptVM = nullptr;
            return 0;
          }
          v2 = SL_PYTHON;
        }
      }
      else
      {
        v2 = SL_GAMEMONKEY;
      }
    }
    if ( g_pScriptVM != nullptr
      || (g_pScriptVM = scriptmanager->CreateVM(this: scriptmanager, a2: v2), g_pScriptVM != nullptr) )
    {
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VScript, a2: 0) != 0 )
      {
        v4 = g_pScriptVM->GetLanguageName(this: g_pScriptVM);
        _LoggingSystem_Log(
          a1: LOG_VScript,
          a2: 0,
          a3: "VSCRIPT: Started VScript virtual machine using script language '%s'\n",
          v4);
      }
      if ( (_S5_128 & 1) == 0 )
      {
        _S5_128 |= 1u;
        binding_2.m_desc.m_Parameters.m_Memory.m_pMemory = nullptr;
        binding_2.m_desc.m_Parameters.m_Memory.m_nAllocationCount = 0;
        binding_2.m_desc.m_Parameters.m_Memory.m_nGrowSize = 0;
        binding_2.m_desc.m_Parameters.m_Size = 0;
        binding_2.m_desc.m_Parameters.m_pElements = nullptr;
        binding_2.m_desc.m_pszFunction = nullptr;
        binding_2.m_desc.m_ReturnType = 31;
        binding_2.m_desc.m_pszDescription = nullptr;
        atexit(func: VScriptClientInit_::_35_::_dynamic_atexit_destructor_for__binding__);
      }
      binding_2.m_desc.m_pszScriptName = "GetMapName";
      binding_2.m_desc.m_pszFunction = "GetMapName";
      binding_2.m_desc.m_pszDescription = "Get the name of the map.";
      binding_2.m_desc.m_Parameters.m_Size = 0;
      binding_2.m_desc.m_ReturnType = 32;
      binding_2.m_pfnBinding = CNonMemberScriptBinding0<char const * (__cdecl *)(void),char const *>::Call;
      binding_2.m_pFunction = GetMapName;
      ((void (__thiscall *)(IScriptVM *, ScriptFunctionBinding_t *, int))g_pScriptVM->RegisterFunction)(
        a1: g_pScriptVM,
        a2: &binding_2,
        a3: a2);
      if ( (_S5_128 & 2) == 0 )
      {
        _S5_128 |= 2u;
        binding_1.m_desc.m_Parameters.m_Memory.m_pMemory = nullptr;
        binding_1.m_desc.m_Parameters.m_Memory.m_nAllocationCount = 0;
        binding_1.m_desc.m_Parameters.m_Memory.m_nGrowSize = 0;
        binding_1.m_desc.m_Parameters.m_Size = 0;
        binding_1.m_desc.m_Parameters.m_pElements = nullptr;
        binding_1.m_desc.m_pszFunction = nullptr;
        binding_1.m_desc.m_ReturnType = 31;
        binding_1.m_desc.m_pszDescription = nullptr;
        atexit(func: VScriptClientInit_::_44_::_dynamic_atexit_destructor_for__binding__);
      }
      binding_1.m_desc.m_pszScriptName = "Time";
      binding_1.m_desc.m_pszFunction = "Time";
      binding_1.m_desc.m_pszDescription = "Get the current server time";
      binding_1.m_desc.m_Parameters.m_Size = 0;
      binding_1.m_desc.m_ReturnType = 1;
      binding_1.m_pfnBinding = CNonMemberScriptBinding0<float (__cdecl *)(void),float>::Call;
      binding_1.m_pFunction = CountdownTimer::Now;
      g_pScriptVM->RegisterFunction(this: g_pScriptVM, a2: &binding_1);
      if ( (_S5_128 & 4) == 0 )
      {
        _S5_128 |= 4u;
        binding_0.m_desc.m_Parameters.m_Memory.m_pMemory = nullptr;
        binding_0.m_desc.m_Parameters.m_Memory.m_nAllocationCount = 0;
        binding_0.m_desc.m_Parameters.m_Memory.m_nGrowSize = 0;
        binding_0.m_desc.m_Parameters.m_Size = 0;
        binding_0.m_desc.m_Parameters.m_pElements = nullptr;
        binding_0.m_desc.m_pszFunction = nullptr;
        binding_0.m_desc.m_ReturnType = 31;
        binding_0.m_desc.m_pszDescription = nullptr;
        atexit(func: VScriptClientInit_::_53_::_dynamic_atexit_destructor_for__binding__);
      }
      binding_0.m_desc.m_pszDescription = "Execute a script (internal)";
      binding_0.m_desc.m_Parameters.m_Size = 0;
      binding_0.m_desc.m_pszScriptName = "DoIncludeScript";
      binding_0.m_desc.m_pszFunction = "DoIncludeScript";
      ScriptDeduceFunctionSignature<bool,char const *,HSCRIPT__ *>(pDesc: &binding_0.m_desc);
      binding_0.m_pfnBinding = CNonMemberScriptBinding2<bool (__cdecl *)(char const *,HSCRIPT__ *),bool,char const *,HSCRIPT__ *>::Call;
      binding_0.m_pFunction = DoIncludeScript;
      g_pScriptVM->RegisterFunction(this: g_pScriptVM, a2: &binding_0);
      if ( (_S5_128 & 8) == 0 )
      {
        _S5_128 |= 8u;
        binding.m_desc.m_Parameters.m_Memory.m_pMemory = nullptr;
        binding.m_desc.m_Parameters.m_Memory.m_nAllocationCount = 0;
        binding.m_desc.m_Parameters.m_Memory.m_nGrowSize = 0;
        binding.m_desc.m_Parameters.m_Size = 0;
        binding.m_desc.m_Parameters.m_pElements = nullptr;
        binding.m_desc.m_pszFunction = nullptr;
        binding.m_desc.m_ReturnType = 31;
        binding.m_desc.m_pszDescription = nullptr;
        atexit(func: VScriptClientInit_::_62_::_dynamic_atexit_destructor_for__binding__);
      }
      binding.m_desc.m_pszScriptName = "GetDeveloperLevel";
      binding.m_desc.m_pszFunction = "GetDeveloperLevel";
      binding.m_desc.m_pszDescription = "Gets the level of 'develoer'";
      binding.m_desc.m_Parameters.m_Size = 0;
      binding.m_desc.m_ReturnType = 5;
      binding.m_pfnBinding = CNonMemberScriptBinding0<int (__cdecl *)(void),int>::Call;
      binding.m_pFunction = GetDeveloperLevel;
      g_pScriptVM->RegisterFunction(this: g_pScriptVM, a2: &binding);
      if ( g_pGameRules != nullptr )
        g_pGameRules->RegisterScriptFunctions(this: g_pGameRules);
      if ( v2 == SL_SQUIRREL )
        g_pScriptVM->Run_3(this: g_pScriptVM, a2: (const char *)g_Script_vscript_client, a3: true);
      VScriptRunScript(pszScriptName: "mapspawn", hScope: nullptr, bWarnMissing: false);
      return 1;
    }
    else
    {
      DevWarning(a1: "VM Did not start!\n");
      g_pScriptVM = nullptr;
      return 0;
    }
  }
  else
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VScript, a2: 0) != 0 )
      _LoggingSystem_Log(a1: LOG_VScript, a2: 0, a3: "\nVSCRIPT: Scripting is disabled.\n");
    g_pScriptVM = nullptr;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101AAA10
// Name: public: virtual void CVScriptGameSystem::LevelInitPreEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CVScriptGameSystem::LevelInitPreEntity(CVScriptGameSystem *this@<ecx>, int a2@<edi>)
{
  this->m_bAllowEntityCreationInScripts = true;
  VScriptClientInit(a1: (int)this, a2);
}

//------------------------------------------------------------------------------
// Address: 0x101AA4F0
// Name: void ScriptDeduceFunctionSignature<bool,char const __near *,struct HSCRIPT__ __near *>(struct ScriptFuncDescriptor_t __near *,bool (*)(char const __near *,struct HSCRIPT__ __near *))
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ScriptDeduceFunctionSignature<bool,char const *,HSCRIPT__ *>(ScriptFuncDescriptor_t *pDesc)
{
  CUtlVector<int,CUtlMemory<int,int> > *p_m_Parameters; // esi
  IMemAlloc_vtbl *v2; // edx
  int v3; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v7; // eax
  int *v8; // eax
  int v9; // edi
  int v10; // eax
  int *v11; // ecx
  int v12; // eax
  int *v13; // eax

  pDesc->m_ReturnType = 6;
  pDesc->m_Parameters.m_Memory.m_nGrowSize = 1;
  p_m_Parameters = &pDesc->m_Parameters;
  if ( pDesc->m_Parameters.m_Memory.m_nAllocationCount < 2 && pDesc->m_Parameters.m_Memory.m_nGrowSize >= 0 )
  {
    pDesc->m_Parameters.m_Memory.m_nAllocationCount = 2;
    v2 = _g_pMemAlloc->__vftable;
    if ( p_m_Parameters->m_Memory.m_pMemory != nullptr )
      v3 = ((int (__stdcall *)(int *, int))v2->Realloc_2)(a1: p_m_Parameters->m_Memory.m_pMemory, a2: 8);
    else
      v3 = ((int (__stdcall *)(int))v2->Alloc_2)(a1: 8);
    p_m_Parameters->m_Memory.m_pMemory = (int *)v3;
  }
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  m_Size = pDesc->m_Parameters.m_Size;
  m_nAllocationCount = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CChoreoActor *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters,
      num: m_Size - m_nAllocationCount + 1);
  ++pDesc->m_Parameters.m_Size;
  m_pMemory = p_m_Parameters->m_Memory.m_pMemory;
  v7 = pDesc->m_Parameters.m_Size - m_Size - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
  v8 = &p_m_Parameters->m_Memory.m_pMemory[m_Size];
  if ( v8 != nullptr )
    *v8 = 32;
  v9 = pDesc->m_Parameters.m_Size;
  v10 = pDesc->m_Parameters.m_Memory.m_nAllocationCount;
  if ( v9 + 1 > v10 )
    CUtlMemory<CChoreoActor *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Parameters, num: v9 - v10 + 1);
  ++pDesc->m_Parameters.m_Size;
  v11 = p_m_Parameters->m_Memory.m_pMemory;
  v12 = pDesc->m_Parameters.m_Size - v9 - 1;
  pDesc->m_Parameters.m_pElements = pDesc->m_Parameters.m_Memory.m_pMemory;
  if ( v12 > 0 )
    _V_memmove(dest: &v11[v9 + 1], src: &v11[v9], count: 4 * v12);
  v13 = &p_m_Parameters->m_Memory.m_pMemory[v9];
  if ( v13 != nullptr )
    *v13 = 33;
}
