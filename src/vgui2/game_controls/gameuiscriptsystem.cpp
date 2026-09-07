// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/game_controls/gameuiscriptsystem.cpp
// Functions: 3
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0042CB80
// Name: class IScriptVM __near * GameUIScriptSystemCreate(void)
// Source: json
//------------------------------------------------------------------------------
IScriptVM *__cdecl GameUIScriptSystemCreate()
{
  IScriptVM *result; // eax
  IScriptVM *v1; // esi
  const char *v2; // eax
  char SZFullPath[264]; // [esp+18h] [ebp-108h] BYREF

  result = g_pScriptManager->CreateVM(this: g_pScriptManager, a2: 3);
  v1 = result;
  if ( result != nullptr )
  {
    v2 = result->GetLanguageName(this: result);
    DevMsg(a1: "VSCRIPT: Started VScript virtual machine using script language '%s'\n", v2);
    g_pFullFileSystem->RelativePathToFullPath(
      this: g_pFullFileSystem,
      a2: "scripts/vguiedit/modules",
      a3: "GAME",
      a4: &SZFullPath[4],
      a5: 260,
      a6: FILTER_NONE,
      a7: nullptr);
    v1->AddSearchPath(this: v1, a2: &SZFullPath[4]);
    return v1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042CC00
// Name: struct HSCRIPT__ __near * GameUIScriptSystemCompile(class IScriptVM __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
HSCRIPT__ *__cdecl GameUIScriptSystemCompile(IScriptVM *pScriptVM, const char *pszScriptName)
{
  const char *v3; // ebp
  const char *v4; // eax
  const char *v5; // edi
  const char *m_nAllocationCount; // edi
  char *v7; // eax
  HSCRIPT__ *v8; // esi
  CUtlBuffer bufferScript; // [esp+1Ch] [ebp-140h] BYREF
  CFmtStrN<256> scriptPath; // [esp+4Ch] [ebp-110h] BYREF
  int v11; // [esp+158h] [ebp-4h]

  if ( pScriptVM == nullptr )
    return nullptr;
  v3 = pszExtensions[pScriptVM->GetLanguage(this: pScriptVM)];
  v4 = _V_strrchr(s: pszScriptName, c: 46);
  v5 = v4;
  if ( v4 != nullptr && _V_stricmp(s1: v4, s2: v3) != 0 )
  {
    _Msg(a1: "Script file type does not match VM type\n");
    return nullptr;
  }
  *(_DWORD *)&scriptPath.m_bQuietTruncation = &CFmtStrN<256>::`vftable';
  scriptPath.m_szBuf[3] = 1;
  scriptPath.m_szBuf[4] = 0;
  v11 = 0;
  if ( v5 != nullptr )
    CFmtStrN<256>::sprintf(
      this: (CFmtStrN<256> *)&scriptPath.m_bQuietTruncation,
      pszFormat: "scripts/%s",
      pszScriptName);
  else
    CFmtStrN<256>::sprintf(
      this: (CFmtStrN<256> *)&scriptPath.m_bQuietTruncation,
      pszFormat: "scripts/%s%s",
      pszScriptName,
      v3);
  CUtlBuffer::CUtlBuffer(
    this: (CUtlBuffer *)&bufferScript.m_Memory.m_nAllocationCount,
    growSize: 0,
    initSize: 0,
    nFlags: 0);
  if ( pScriptVM->GetLanguage(this: pScriptVM) == SL_PYTHON )
  {
    m_nAllocationCount = nullptr;
  }
  else
  {
    if ( !g_pFullFileSystem->ReadFile(
            this: &g_pFullFileSystem->IBaseFileSystem,
            a2: &scriptPath.m_szBuf[4],
            a3: "GAME",
            a4: (CUtlBuffer *)&bufferScript.m_Memory.m_nAllocationCount,
            a5: 0,
            a6: 0,
            a7: nullptr) )
      _Warning(a1: "Script not found (%s) \n", &scriptPath.m_szBuf[4]);
    m_nAllocationCount = (const char *)bufferScript.m_Memory.m_nAllocationCount;
    if ( bufferScript.m_Memory.m_nAllocationCount == 0 || *(_BYTE *)bufferScript.m_Memory.m_nAllocationCount == 0 )
    {
      CUtlBuffer::~CUtlBuffer(this: (CUtlBuffer *)&bufferScript.m_Memory.m_nAllocationCount);
      return nullptr;
    }
  }
  v7 = _V_strrchr(s: &scriptPath.m_szBuf[4], c: 47);
  v8 = pScriptVM->CompileScript(this: pScriptVM, a2: m_nAllocationCount, a3: v7 + 1);
  if ( v8 == (HSCRIPT__ *)-1 )
    DevMsg(a1: "FAILED to compile and execute script file named %s\n", &scriptPath.m_szBuf[4]);
  if ( bufferScript.m_Get >= 0 && bufferScript.m_Memory.m_nAllocationCount != 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)bufferScript.m_Memory.m_nAllocationCount);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x0042CDA0
// Name: bool GameUIScriptSystemRun(class IScriptVM __near *,char const __near *,struct HSCRIPT__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
bool __usercall GameUIScriptSystemRun@<al>(
        int a1@<ebx>,
        IScriptVM *pScriptVM,
        const char *pszScriptName,
        HSCRIPT__ *hScope)
{
  HSCRIPT__ *v4; // edi
  bool result; // al
  int v6; // eax
  bool v7; // bl

  v4 = GameUIScriptSystemCompile(pScriptVM, pszScriptName);
  result = false;
  if ( v4 != (HSCRIPT__ *)-1 )
  {
    v6 = ((int (__thiscall *)(IScriptVM *, HSCRIPT__ *, HSCRIPT__ *, int, int))pScriptVM->Run_2)(
           a1: pScriptVM,
           a2: v4,
           a3: hScope,
           a4: 1,
           a5: a1);
    v7 = v6 != -1;
    if ( v6 == -1 )
      DevMsg(a1: "Error running script named %s\n", pszScriptName);
    pScriptVM->ReleaseScript(this: pScriptVM, a2: v4);
    return v7;
  }
  return result;
}
