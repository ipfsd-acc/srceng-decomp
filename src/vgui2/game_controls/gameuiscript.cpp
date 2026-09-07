// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/game_controls/gameuiscript.cpp
// Functions: 9
// ============================================================

#include "vgui2\game_controls\gameuiscript.h"

//------------------------------------------------------------------------------
// Address: 0x00423590
// Name: ScriptOutputFunc
// Source: json
//------------------------------------------------------------------------------
void __cdecl ScriptOutputFunc(const char *pszText)
{
  _Msg(a1: "%s\n", pszText);
}

//------------------------------------------------------------------------------
// Address: 0x004235B0
// Name: ScriptErrorFunc
// Source: json
//------------------------------------------------------------------------------
char __cdecl ScriptErrorFunc(ScriptErrorLevel_t eLevel, const char *pszText)
{
  unsigned __int8 *v2; // eax
  const char *v3; // ebx
  const char *v4; // eax
  const char *v5; // esi
  unsigned __int8 *v6; // eax
  const char *v7; // edi
  int v8; // eax
  const char *v9; // edx
  char *m_pszString; // ecx

  v2 = (unsigned __int8 *)StringAfterPrefix(str: pszText, prefix: "[string \"");
  v3 = (const char *)v2;
  if ( v2 != nullptr
    && (strchr(string: v2, chr: 0x22u), v5 = v4, v4 != nullptr)
    && (v6 = (unsigned __int8 *)StringAfterPrefix(str: v4, prefix: "\"]:"), v7 = (const char *)v6, v6 != nullptr)
    && (strchr(string: v6, chr: 0x3Au), v8 != 0) )
  {
    v9 = "WARNING";
    if ( eLevel != SCRIPT_LEVEL_WARNING )
      v9 = "ERROR";
    if ( (ui_script_error_path.m_nFlags & 0x1000) != 0 )
    {
      m_pszString = "FCVAR_NEVER_AS_STRING";
    }
    else
    {
      m_pszString = ui_script_error_path.m_pParent->m_Value.m_pszString;
      if ( m_pszString == nullptr )
        m_pszString = (char *)defaultValue;
    }
    _Warning(a1: "%s%.*s(%.*s): %s: %s\n", m_pszString, v5 - v3, v3, v8 - (_DWORD)v7, v7, v9, (const char *)(v8 + 1));
    return 1;
  }
  else
  {
    if ( eLevel != SCRIPT_LEVEL_WARNING )
    {
      if ( eLevel == SCRIPT_LEVEL_ERROR )
      {
        _Warning(a1: "ERROR: %s\n", pszText);
        return 1;
      }
    }
    else
    {
      _Warning(a1: "WARNING: %s\n", pszText);
    }
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004236A0
// Name: private: bool CGameUIScript::GetScriptVersion(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameUIScript::GetScriptVersion(CGameUIScript *this)
{
  HSCRIPT__ *v2; // edi
  IScriptVM *m_pScriptVM; // ecx
  HSCRIPT__ *m_Scope; // [esp+10h] [ebp-1Ch]
  ScriptVariant_t Return; // [esp+20h] [ebp-Ch] BYREF
  __int16 v7; // [esp+28h] [ebp-4h]
  __int16 v8; // [esp+2Ah] [ebp-2h]

  v2 = this->m_pScriptVM->LookupFunction(this: this->m_pScriptVM, a2: "Version", a3: this->m_Scope);
  if ( v2 == nullptr )
    return 0;
  m_pScriptVM = this->m_pScriptVM;
  m_Scope = this->m_Scope;
  v7 = 0;
  v8 = 0;
  *(_DWORD *)&Return.m_type = 0;
  m_pScriptVM->ExecuteFunction(
    this: m_pScriptVM,
    a2: v2,
    a3: nullptr,
    a4: 0,
    a5: (ScriptVariant_t *)&Return.m_type,
    a6: m_Scope,
    a7: true);
  if ( v7 == 1 )
    this->m_Version = (int)*(float *)&Return.m_type;
  else
    this->m_Version = *(_DWORD *)&Return.m_type;
  this->m_pScriptVM->ReleaseFunction(this: this->m_pScriptVM, a2: v2);
  this->m_pScriptVM->ReleaseValue(this: this->m_pScriptVM, a2: (ScriptVariant_t *)&Return.m_type);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00423740
// Name: public: bool CGameUIScript::Execute(class KeyValues __near *,class KeyValues __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameUIScript::Execute(CGameUIScript *this, KeyValues *pData, KeyValues **ppResult)
{
  const char *Name; // eax
  HSCRIPT__ *v5; // ebx
  HSCRIPT__ *v7; // eax
  IScriptVM *m_pScriptVM; // ecx
  HSCRIPT__ *v9; // edi
  HSCRIPT__ *m_Scope; // [esp+Ch] [ebp-28h]
  ScriptVariant_t varResult; // [esp+20h] [ebp-14h] BYREF
  ScriptVariant_t varParams; // [esp+28h] [ebp-Ch] BYREF
  __int16 v13; // [esp+30h] [ebp-4h]
  __int16 v14; // [esp+32h] [ebp-2h]
  ScriptStatus_t ret; // [esp+38h] [ebp+4h]

  Name = KeyValues::GetName(this: pData);
  v5 = this->m_pScriptVM->LookupFunction(this: this->m_pScriptVM, a2: Name, a3: this->m_Scope);
  if ( v5 == nullptr )
    return 0;
  v7 = CGameUIScriptInterface::ScriptTableFromKeyValues(pVM: this->m_pScriptVM, kv: pData);
  m_pScriptVM = this->m_pScriptVM;
  v9 = v7;
  m_Scope = this->m_Scope;
  v13 = 33;
  v14 = 0;
  *(_DWORD *)&varParams.m_type = v7;
  varParams.m_int = 0;
  *(_DWORD *)&varResult.m_type = 0;
  ret = m_pScriptVM->ExecuteFunction(
          this: m_pScriptVM,
          a2: v5,
          a3: (ScriptVariant_t *)&varParams.m_type,
          a4: 1,
          a5: (ScriptVariant_t *)&varResult.m_type,
          a6: m_Scope,
          a7: true);
  if ( v9 != nullptr )
    this->m_pScriptVM->ReleaseValue(this: this->m_pScriptVM, a2: (ScriptVariant_t *)&varParams.m_type);
  if ( ret == SCRIPT_DONE && LOWORD(varParams.m_float) == 33 && ppResult != nullptr )
    *ppResult = CGameUIScriptInterface::ScriptVmKeyValueFromVariant(
                  pVM: this->m_pScriptVM,
                  varValue: (ScriptVariant_t *)&varResult.m_type);
  this->m_pScriptVM->ReleaseValue(this: this->m_pScriptVM, a2: (ScriptVariant_t *)&varResult.m_type);
  this->m_pScriptVM->ReleaseFunction(this: this->m_pScriptVM, a2: v5);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00423830
// Name: public: void CGameUIScript::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUIScript::Shutdown(CGameUIScript *this)
{
  CGameUIScriptInterface *m_pGameUIScriptInterface; // esi

  m_pGameUIScriptInterface = this->m_pGameUIScriptInterface;
  if ( this->m_pGameUIScriptInterface != nullptr )
  {
    CGameUIScriptInterface::~CGameUIScriptInterface(this: this->m_pGameUIScriptInterface);
    free(pMem: m_pGameUIScriptInterface);
    this->m_pGameUIScriptInterface = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00423860
// Name: public: bool CGameUIScript::SetScript(char const __near *,class CGameUIDefinition __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameUIScript::SetScript(CGameUIScript *this, const char *pszFileName, CGameUIDefinition *pDef)
{
  CUtlString *p_m_ScriptFile; // edi
  CGameUIScriptInterface *v5; // eax
  CGameUIScriptInterface *v6; // eax
  const char *v7; // eax
  const char *v9; // eax
  ScriptVariant_t Value; // [esp+8h] [ebp-Ch] BYREF
  __int16 v11; // [esp+10h] [ebp-4h]
  __int16 v12; // [esp+12h] [ebp-2h]

  p_m_ScriptFile = &this->m_ScriptFile;
  v11 = 0;
  v12 = 0;
  *(_DWORD *)&Value.m_type = 0;
  CUtlString::operator=(this: &this->m_ScriptFile, src: pszFileName);
  v5 = (CGameUIScriptInterface *)MemAlloc_Alloc(nSize: 0x44u);
  if ( v5 != nullptr )
    v6 = CGameUIScriptInterface::CGameUIScriptInterface(this: v5, pScriptVM: this->m_pScriptVM, pDef);
  else
    v6 = nullptr;
  this->m_pGameUIScriptInterface = v6;
  v7 = CUtlString::operator char const *(this: p_m_ScriptFile);
  if ( !GameUIScriptSystemRun(pScriptVM: this->m_pScriptVM, pszScriptName: v7, hScope: nullptr, bWarnMissing: true) )
    return 0;
  v9 = CUtlString::operator char const *(this: &pDef->m_pName);
  if ( !this->m_pScriptVM->GetValue(this: this->m_pScriptVM, a2: nullptr, a3: v9, a4: (ScriptVariant_t *)&Value.m_type) )
    return 0;
  this->m_Scope = *(HSCRIPT__ **)&Value.m_type;
  CGameUIScript::GetScriptVersion(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00423910
// Name: public: CGameUIScript::CGameUIScript(void)
// Source: json
//------------------------------------------------------------------------------
CGameUIScript *__thiscall CGameUIScript::CGameUIScript(CGameUIScript *this)
{
  CUtlString *p_m_Name; // edi
  IScriptVM *v3; // eax

  p_m_Name = &this->m_Name;
  CUtlString::CUtlString(this: &this->m_Name);
  CUtlString::CUtlString(this: &this->m_ScriptFile);
  v3 = GameUIScriptSystemCreate();
  this->m_pScriptVM = v3;
  v3->SetOutputCallback(this: v3, a2: ScriptOutputFunc);
  this->m_pScriptVM->SetErrorCallback(
    this: this->m_pScriptVM,
    a2: (bool (__cdecl *)(ScriptErrorLevel_t, const char *))ScriptErrorFunc);
  this->m_IsActive = false;
  this->m_pGameUIScriptInterface = nullptr;
  this->m_Version = -1;
  CUtlString::operator=(this: p_m_Name, src: "unknown");
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00423980
// Name: public: CGameUIScript::~CGameUIScript(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUIScript::~CGameUIScript(CGameUIScript *this)
{
  CGameUIScriptInterface *m_pGameUIScriptInterface; // edi
  bool v3; // sf

  m_pGameUIScriptInterface = this->m_pGameUIScriptInterface;
  if ( this->m_pGameUIScriptInterface != nullptr )
  {
    CGameUIScriptInterface::~CGameUIScriptInterface(this: this->m_pGameUIScriptInterface);
    free(pMem: m_pGameUIScriptInterface);
    this->m_pGameUIScriptInterface = nullptr;
  }
  v3 = this->m_ScriptFile.m_Storage.m_Memory.m_nGrowSize < 0;
  this->m_ScriptFile.m_Storage.m_nActualLength = 0;
  if ( !v3 )
  {
    if ( this->m_ScriptFile.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_ScriptFile.m_Storage.m_Memory.m_pMemory);
      this->m_ScriptFile.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_ScriptFile.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  v3 = this->m_Name.m_Storage.m_Memory.m_nGrowSize < 0;
  this->m_Name.m_Storage.m_nActualLength = 0;
  if ( !v3 )
  {
    if ( this->m_Name.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Name.m_Storage.m_Memory.m_pMemory);
      this->m_Name.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_Name.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004239F0
// Name: struct DmxElementUnpackStructure_t __near * DmxElementUnpackInit<class CGameStage>(class CGameStage __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *__cdecl DmxElementUnpackInit<CGameStage>()
{
  if ( (_S1_2 & 1) == 0 )
  {
    _S1_2 |= 1u;
    dword_5BA980 = 9;
    dword_5BA984 = 436;
    dword_5BA988 = 8;
    dword_5BA98C = -1;
    dword_5BA990 = 0;
    dword_5BA994 = 0;
    dword_5BA998 = 0;
    dword_5BA99C = 0;
    dword_5BA9A0 = 0;
    dword_5BA9A4 = (int)"fullscreen";
    dword_5BA9A8 = (int)"1";
    dword_5BA9AC = 4;
    dword_5BA9B0 = 452;
    dword_5BA9B4 = 1;
    dword_5BA9B8 = -1;
    dword_5BA9BC = 0;
    dword_5BA9C0 = 0;
    dword_5BA9C4 = 0;
    dword_5BA9C8 = 0;
    dword_5BA9CC = 0;
    dword_5BA9D0 = 0;
    dword_5BA9D4 = 0;
    dword_5BA9D8 = 0;
    dword_5BA9DC = 0;
    dword_5BA9E0 = 0;
    dword_5BA9E4 = -1;
    dword_5BA9E8 = 0;
    dword_5BA9EC = 0;
    dword_5BA9F0 = 0;
    dword_5BA9F4 = 0;
    dword_5BA9F8 = 0;
  }
  return unpack_2;
}
