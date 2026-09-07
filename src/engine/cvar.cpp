// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/cvar.cpp
// Functions: 35
// ============================================================

#include "engine\cvar.h"

//------------------------------------------------------------------------------
// Address: 0x101590F0
// Name: private: void CCvarUtilities::SetDirect(class ConVar __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CCvarUtilities::SetDirect(
        CCvarUtilities *this@<ecx>,
        int a2@<ebx>,
        int a3@<esi>,
        ConVar *var,
        const char *value)
{
  ConVar *v5; // edi
  const char *v6; // ebx
  unsigned __int16 *v7; // esi
  wchar_t *i; // edi
  int v9; // eax
  wchar_t *v10; // esi
  IConVar_vtbl *v11; // esi
  float v12; // [esp+0h] [ebp-C0Ch]
  _BYTE v14[48]; // [esp+Ch] [ebp-C00h] BYREF
  char szNew[1024]; // [esp+3Ch] [ebp-BD0h] BYREF
  wchar_t unicode[512]; // [esp+43Ch] [ebp-7D0h] BYREF
  __int16 newUnicode_974; // [esp+C0Ah] [ebp-2h] OVERLAPPED

  v5 = var;
  if ( !var->IsFlagSet(this: var, a2: 512) || !sv.m_bIsDedicated )
  {
    v6 = value;
    if ( ((unsigned __int8 (__thiscall *)(ConVar *, int, int, int))var->IsFlagSet)(a1: var, a2: 1024, a3, a4: a2) != 0 )
    {
      if ( sv.m_bIsDedicated )
        _V_UTF8ToUnicode(a1: value, a2: &szNew[976], a3: 1024);
      else
        g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: value, a3: (wchar_t *)&szNew[976], a4: 1024);
      unicode[488] = 0;
      v7 = (unsigned __int16 *)&szNew[976];
      for ( i = &unicode[488]; *v7 != 0; ++v7 )
      {
        if ( iswcntrl(c: *v7) == 0 )
        {
          v9 = *v7;
          if ( v9 != 126 )
            *i++ = v9;
        }
      }
      *i = 0;
      if ( wcslen(&unicode[488]) != 0 )
      {
        v10 = &unicode[488];
        do
        {
          if ( *v10 == 0 )
            break;
          if ( iswspace(c: *v10) == 0 )
            goto LABEL_18;
          ++v10;
        }
        while ( v10 != nullptr );
      }
      wcsncpy(dest: &unicode[488], source: L"#empty", count: 0x1FFu);
      newUnicode_974 = 0;
LABEL_18:
      if ( sv.m_bIsDedicated )
        _V_UnicodeToUTF8(a1: &unicode[488], a2: v14, a3: 1024);
      else
        g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: &unicode[488], a3: v14, a4: 1024);
      v5 = var;
      v6 = v14;
    }
    if ( v5->IsFlagSet(this: v5, a2: 4096) )
    {
      v11 = v5->IConVar::__vftable;
      v12 = atof(nptr: v6);
      ((void (__thiscall *)(IConVar *, _DWORD))v11->SetValue_3)(a1: &v5->IConVar, a2: LODWORD(v12));
    }
    else
    {
      ((void (__thiscall *)(IConVar *))v5->SetValue_4)(a1: &v5->IConVar);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101592A0
// Name: CVarSortFunc
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CVarSortFunc(ConVar *const *lhs, ConVar *const *rhs)
{
  const char *v2; // esi
  const char *v3; // eax

  v2 = (const char *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)rhs + 24))(a1: *rhs);
  v3 = (const char *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)lhs + 24))(a1: *lhs);
  if ( v3 == nullptr )
    return false;
  if ( v2 != nullptr )
    return _V_stricmp(s1: v3, s2: v2) < 0;
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x101592F0
// Name: cmd1
// Source: json
//------------------------------------------------------------------------------
void __cdecl cmd1(const CCommand *args)
{
  int m_nArgv0Size; // eax
  bool v2; // zf
  const char *v3; // eax
  char *v4; // eax

  m_nArgv0Size = args->m_nArgv0Size;
  if ( host_state.max_splitscreen_players > 0 )
  {
    v2 = m_nArgv0Size == 0;
    v4 = &args->m_pArgSBuffer[m_nArgv0Size];
    if ( v2 )
      v4 = (char *)defaultValue;
    Cbuf_AddText(eTarget: CBUF_FIRST_PLAYER, pText: v4, nTickDelay: 0);
  }
  else
  {
    v2 = m_nArgv0Size == 0;
    v3 = &args->m_pArgSBuffer[m_nArgv0Size];
    if ( v2 )
      v3 = defaultValue;
    _DevMsg(a1: 1, a2: "ignore:  %d '%s'\n", 0, v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10159340
// Name: cmd2
// Source: json
//------------------------------------------------------------------------------
void __cdecl cmd2(const CCommand *args)
{
  int m_nArgv0Size; // eax
  bool v2; // zf
  const char *v3; // eax
  char *v4; // eax

  m_nArgv0Size = args->m_nArgv0Size;
  if ( host_state.max_splitscreen_players > 1 )
  {
    v2 = m_nArgv0Size == 0;
    v4 = &args->m_pArgSBuffer[m_nArgv0Size];
    if ( v2 )
      v4 = (char *)defaultValue;
    Cbuf_AddText(eTarget: CBUF_LAST_PLAYER, pText: v4, nTickDelay: 0);
  }
  else
  {
    v2 = m_nArgv0Size == 0;
    v3 = &args->m_pArgSBuffer[m_nArgv0Size];
    if ( v2 )
      v3 = defaultValue;
    _DevMsg(a1: 1, a2: "ignore:  %d '%s'\n", 1, v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10159390
// Name: cmd3
// Source: json
//------------------------------------------------------------------------------
void __cdecl cmd3(const CCommand *args)
{
  int m_nArgv0Size; // eax
  bool v2; // zf
  const char *v3; // eax
  char *v4; // eax

  m_nArgv0Size = args->m_nArgv0Size;
  if ( host_state.max_splitscreen_players > 2 )
  {
    v2 = m_nArgv0Size == 0;
    v4 = &args->m_pArgSBuffer[m_nArgv0Size];
    if ( v2 )
      v4 = (char *)defaultValue;
    Cbuf_AddText(eTarget: CBUF_SERVER, pText: v4, nTickDelay: 0);
  }
  else
  {
    v2 = m_nArgv0Size == 0;
    v3 = &args->m_pArgSBuffer[m_nArgv0Size];
    if ( v2 )
      v3 = defaultValue;
    _DevMsg(a1: 1, a2: "ignore:  %d '%s'\n", 2, v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101593E0
// Name: cmd4
// Source: json
//------------------------------------------------------------------------------
void __cdecl cmd4(const CCommand *args)
{
  int m_nArgv0Size; // eax
  bool v2; // zf
  const char *v3; // eax
  char *v4; // eax

  m_nArgv0Size = args->m_nArgv0Size;
  if ( host_state.max_splitscreen_players > 3 )
  {
    v2 = m_nArgv0Size == 0;
    v4 = &args->m_pArgSBuffer[m_nArgv0Size];
    if ( v2 )
      v4 = (char *)defaultValue;
    Cbuf_AddText(eTarget: CBUF_COUNT, pText: v4, nTickDelay: 0);
  }
  else
  {
    v2 = m_nArgv0Size == 0;
    v3 = &args->m_pArgSBuffer[m_nArgv0Size];
    if ( v2 )
      v3 = defaultValue;
    _DevMsg(a1: 1, a2: "ignore:  %d '%s'\n", 3, v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10159430
// Name: StripTabsAndReturns
// Source: json
//------------------------------------------------------------------------------
char *__usercall StripTabsAndReturns@<eax>(const char *inbuffer@<ecx>, char *outbuffer@<eax>, int outbufferSize)
{
  const char *v3; // esi
  bool v4; // zf
  char *v5; // ecx
  int v6; // edi
  char v7; // dl

  v3 = inbuffer;
  *outbuffer = 0;
  v4 = *inbuffer == 0;
  v5 = outbuffer;
  if ( !v4 )
  {
    v6 = 0;
    do
    {
      if ( v6 >= outbufferSize - 1 )
        break;
      v7 = *v3;
      if ( *v3 == 10 || v7 == 13 || v7 == 9 )
      {
        *v5 = 32;
        ++v6;
      }
      else
      {
        ++v6;
        *v5 = v7 == 34 ? 39 : v7;
      }
      ++v3;
      ++v5;
    }
    while ( *v3 != 0 );
  }
  *v5 = 0;
  return outbuffer;
}

//------------------------------------------------------------------------------
// Address: 0x10159480
// Name: PrintListHeader
// Source: json
//------------------------------------------------------------------------------
void __cdecl PrintListHeader(void **f)
{
  const char **p_desc; // esi
  char csvflagstr[1024]; // [esp+4h] [ebp-440h] BYREF
  char csvf[64]; // [esp+404h] [ebp-40h] BYREF

  csvflagstr[0] = 0;
  p_desc = &g_ConVarFlags[0].desc;
  do
  {
    V_snprintf(pDest: csvf, maxLen: 64, pFormat: "\"%s\",", *p_desc);
    V_strncat(pDest: csvflagstr, pSrc: csvf, destBufferSize: 0x400u, max_chars_to_copy: -1);
    p_desc += 3;
  }
  while ( (int)p_desc < (int)&vec2_invalid_46.y );
  g_pFileSystem->FPrintf(
    this: g_pFileSystem,
    a2: *f,
    a3: "\"%s\",\"%s\",%s,\"%s\"\n",
    "Name",
    "Value",
    csvflagstr,
    "Help Text");
}

//------------------------------------------------------------------------------
// Address: 0x10159510
// Name: PrintCvar
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall PrintCvar(ConVar *var@<edi>, bool logging, void **f)
{
  const char **p_desc; // esi
  ConVar *m_pParent; // eax
  int m_nValue; // ecx
  int m_fValue; // edx
  int v7; // eax
  const char *v8; // eax
  char *v9; // eax
  const char *v10; // eax
  const char *v11; // eax
  char v12; // dl
  char *v13; // ecx
  int v14; // esi
  IFileSystem *v15; // eax
  IFileSystem_vtbl *v16; // esi
  int v17; // eax
  const char *v18; // [esp-4h] [ebp-594h]
  const char *v19; // [esp+0h] [ebp-590h]
  const char *v20; // [esp+4h] [ebp-58Ch]
  char v21[16]; // [esp+8h] [ebp-588h] BYREF
  char csvflagstr[1024]; // [esp+18h] [ebp-578h] BYREF
  char flagstr[128]; // [esp+418h] [ebp-178h] BYREF
  char tempbuff[128]; // [esp+498h] [ebp-F8h] BYREF
  char csvf[64]; // [esp+518h] [ebp-78h] BYREF
  char v26[12]; // [esp+56Ch] [ebp-24h] BYREF
  float valstr_20; // [esp+58Ch] [ebp-4h] OVERLAPPED

  csvflagstr[1012] = 0;
  v21[4] = 0;
  p_desc = &g_ConVarFlags[0].desc;
  do
  {
    if ( var->IsFlagSet(this: var, a2: (int)*(p_desc - 1)) )
    {
      V_snprintf(pDest: &csvf[52], maxLen: 32, pFormat: ", %s", p_desc[1]);
      V_strncat(pDest: &csvflagstr[1012], pSrc: &csvf[52], destBufferSize: 0x80u, max_chars_to_copy: -1);
      V_snprintf(pDest: &tempbuff[116], maxLen: 64, pFormat: "\"%s\",", *p_desc);
    }
    else
    {
      V_snprintf(pDest: &tempbuff[116], maxLen: 64, pFormat: ",");
    }
    V_strncat(pDest: &v21[4], pSrc: &tempbuff[116], destBufferSize: 0x400u, max_chars_to_copy: -1);
    p_desc += 3;
  }
  while ( (int)p_desc < (int)&vec2_invalid_46.y );
  m_pParent = var->m_pParent;
  if ( m_pParent != nullptr )
    m_nValue = m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  m_fValue = (int)m_pParent->m_Value.m_fValue;
  valstr_20 = m_pParent->m_Value.m_fValue;
  if ( m_nValue == m_fValue )
  {
    if ( m_pParent != nullptr )
      v7 = m_pParent->m_Value.m_nValue;
    else
      v7 = 0;
    V_snprintf(pDest: v26, maxLen: 32, pFormat: "%-8i", v7);
  }
  else
  {
    V_snprintf(pDest: v26, maxLen: 32, pFormat: "%-8.3f", valstr_20);
  }
  v8 = var->GetHelpText(this: var);
  v9 = StripTabsAndReturns(inbuffer: v8, outbuffer: &flagstr[116], outbufferSize: 128);
  v10 = (const char *)((int (__thiscall *)(ConVar *, char *, char *, char *))var->GetName)(
                        a1: var,
                        a2: v26,
                        a3: &csvflagstr[1012],
                        a4: v9);
  ConMsg(a1: "%-40s : %-8s : %-16s : %s\n", v10, v18, v19, v20);
  if ( logging )
  {
    v11 = var->GetHelpText(this: var);
    flagstr[116] = 0;
    v12 = *v11;
    v13 = &flagstr[116];
    if ( *v11 != 0 )
    {
      v14 = 0;
      do
      {
        if ( v14 >= 127 )
          break;
        ++v14;
        *v13 = v12 == 34 ? 39 : v12;
        v12 = *++v11;
        ++v13;
      }
      while ( v12 != 0 );
    }
    v15 = g_pFileSystem;
    *v13 = 0;
    v16 = v15->IAppSystem::__vftable;
    v17 = ((int (__thiscall *)(ConVar *, char *, char *, char *))var->GetName)(
            a1: var,
            a2: v26,
            a3: &v21[4],
            a4: &flagstr[116]);
    v16->FPrintf(this: g_pFileSystem, a2: *f, a3: "\"%s\",\"%s\",%s,\"%s\"\n", v17);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101596F0
// Name: PrintCommand
// Source: json
//------------------------------------------------------------------------------
void __usercall PrintCommand(const ConCommand *cmd@<eax>, bool logging, void **f)
{
  const char *v4; // eax
  char *v5; // eax
  const char *v6; // eax
  int i; // edi
  const char *v8; // eax
  const char *v9; // eax
  const char *v10; // eax
  char v11; // dl
  _BYTE *v12; // ecx
  int v13; // esi
  IFileSystem *v14; // eax
  void *v15; // edx
  const char *v16; // [esp-Ch] [ebp-350h]
  const char *v17; // [esp-8h] [ebp-34Ch]
  const char *v18; // [esp-4h] [ebp-348h]
  char tempbuff[128]; // [esp+4h] [ebp-340h] BYREF
  char emptyflags[256]; // [esp+84h] [ebp-2C0h] BYREF
  char name[256]; // [esp+184h] [ebp-1C0h] BYREF
  _BYTE v22[128]; // [esp+284h] [ebp-C0h] BYREF
  char csvf[64]; // [esp+304h] [ebp-40h] BYREF

  v4 = cmd->GetHelpText(this: cmd);
  v5 = StripTabsAndReturns(inbuffer: v4, outbuffer: tempbuff, outbufferSize: 128);
  v6 = (const char *)((int (__thiscall *)(const ConCommand *, const char *, const char *, char *))cmd->GetName)(
                       a1: cmd,
                       a2: "cmd",
                       a3: defaultValue,
                       a4: v5);
  ConMsg(a1: "%-40s : %-8s : %-16s : %s\n", v6, v16, v17, v18);
  if ( logging )
  {
    emptyflags[0] = 0;
    for ( i = 18; i != 0; --i )
    {
      V_snprintf(pDest: csvf, maxLen: 64, pFormat: ",");
      V_strncat(pDest: emptyflags, pSrc: csvf, destBufferSize: 0x100u, max_chars_to_copy: -1);
    }
    v8 = cmd->GetName(this: cmd);
    V_snprintf(pDest: name, maxLen: 256, pFormat: "%s", v8);
    if ( name[0] == 43 || name[0] == 45 )
    {
      v9 = cmd->GetName(this: cmd);
      V_snprintf(pDest: name, maxLen: 256, pFormat: "'%s'", v9);
    }
    v10 = cmd->GetHelpText(this: cmd);
    v22[0] = 0;
    v11 = *v10;
    v12 = v22;
    if ( *v10 != 0 )
    {
      v13 = 0;
      do
      {
        if ( v13 >= 127 )
          break;
        ++v13;
        *v12 = v11 == 34 ? 39 : v11;
        v11 = *++v10;
        ++v12;
      }
      while ( v11 != 0 );
    }
    v14 = g_pFileSystem;
    v15 = *f;
    *v12 = 0;
    v14->FPrintf(this: v14, a2: v15, a3: "\"%s\",\"%s\",%s,\"%s\"\n", name, "cmd", emptyflags, v22);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10159850
// Name: ConCommandBaseLessFunc
// Source: json
//------------------------------------------------------------------------------
bool __cdecl ConCommandBaseLessFunc(const ConCommandBase *const *lhs, const ConCommandBase *const *rhs)
{
  const char *v2; // esi
  const char *v3; // eax

  v2 = (const char *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)lhs + 24))(a1: *lhs);
  v3 = (const char *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)rhs + 24))(a1: *rhs);
  if ( *v2 == 45 || *v2 == 43 )
    ++v2;
  if ( *v3 == 45 || *v3 == 43 )
    ++v3;
  return _V_stricmp(s1: v2, s2: v3) < 0;
}

//------------------------------------------------------------------------------
// Address: 0x101598A0
// Name: public: void CCvarUtilities::EnableDevCvars(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCvarUtilities::EnableDevCvars(CCvarUtilities *this)
{
  ICvar::ICVarIteratorInternal *v1; // esi
  int v2; // eax

  v1 = g_pCVar->FactoryInternalIterator(this: g_pCVar);
  v1->SetFirst(this: v1);
  while ( v1->IsValid(this: v1) )
  {
    v2 = (int)v1->Get(this: v1);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v2 + 16))(a1: v2, a2: 2);
    v1->Next(this: v1);
  }
  free(pMem: v1);
}

//------------------------------------------------------------------------------
// Address: 0x10159900
// Name: public: int CCvarUtilities::CountVariablesWithFlags(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCvarUtilities::CountVariablesWithFlags(CCvarUtilities *this, int flags)
{
  int v2; // ebx
  ICvar::ICVarIteratorInternal *v3; // esi
  int v4; // edi

  v2 = 0;
  v3 = g_pCVar->FactoryInternalIterator(this: g_pCVar);
  v3->SetFirst(this: v3);
  while ( v3->IsValid(this: v3) )
  {
    v4 = (int)v3->Get(this: v3);
    if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v4 + 4))(a1: v4) == 0
      && (*(unsigned __int8 (__thiscall **)(int, int))(*(_DWORD *)v4 + 8))(a1: v4, a2: flags) != 0 )
    {
      ++v2;
    }
    v3->Next(this: v3);
  }
  free(pMem: v3);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10159990
// Name: public: void CCvarUtilities::CvarDifferences(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCvarUtilities::CvarDifferences(CCvarUtilities *this, const CCommand *args)
{
  ICvar::ICVarIteratorInternal *v2; // edi
  ConVar *v3; // esi
  const char *m_pszString; // eax
  const char *Default; // eax
  const char *v6; // [esp-8h] [ebp-Ch]

  v2 = g_pCVar->FactoryInternalIterator(this: g_pCVar);
  v2->SetFirst(this: v2);
  while ( v2->IsValid(this: v2) )
  {
    v3 = (ConVar *)v2->Get(this: v2);
    if ( !v3->IsCommand(this: v3) && !v3->IsFlagSet(this: v3, a2: 2) && !v3->IsFlagSet(this: v3, a2: 16) )
    {
      if ( (v3->m_nFlags & 0x1000) != 0 )
      {
        m_pszString = "FCVAR_NEVER_AS_STRING";
      }
      else
      {
        m_pszString = v3->m_pParent->m_Value.m_pszString;
        if ( m_pszString == nullptr )
          m_pszString = defaultValue;
      }
      v6 = m_pszString;
      Default = ConVar::GetDefault(this: v3);
      if ( _V_stricmp(s1: Default, s2: v6) != 0 )
        ConVar_PrintDescription(pVar: v3);
    }
    v2->Next(this: v2);
  }
  free(pMem: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10159A60
// Name: public: int CCvarUtilities::CvarFindFlagsCompletionCallback(char const __near *,char (__near * const)[64])
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCvarUtilities::CvarFindFlagsCompletionCallback(
        CCvarUtilities *this,
        const char *partial,
        char (*commands)[64])
{
  int v3; // edi
  char *v4; // esi
  int v5; // ebx
  const char **i; // edi
  char *v7; // esi
  const char **p_desc; // edi
  const char *pSub; // [esp+Ch] [ebp-4h]
  int nSubLen; // [esp+18h] [ebp+8h]

  v3 = _V_strlen(str: partial);
  if ( v3 >= _V_strlen(str: "findflags ") )
  {
    pSub = &partial[_V_strlen(str: "findflags ")];
    v7 = (char *)commands;
    nSubLen = _V_strlen(str: pSub);
    v5 = 0;
    p_desc = &g_ConVarFlags[0].desc;
    do
    {
      if ( V_strnicmp(s1: *p_desc, s2: pSub, n: nSubLen) == 0 )
      {
        V_snprintf(pDest: v7, maxLen: 64, pFormat: "%s %s", "findflags ", *p_desc);
        _V_strlower(start: v7);
        ++v5;
        v7 += 64;
        if ( v5 >= 64 )
          break;
      }
      p_desc += 3;
    }
    while ( (int)p_desc < (int)&vec2_invalid_46.y );
  }
  else
  {
    v4 = (char *)commands;
    v5 = 0;
    for ( i = &g_ConVarFlags[0].desc; (int)i < (int)&vec2_invalid_46.y; i += 3 )
    {
      V_snprintf(pDest: v4, maxLen: 64, pFormat: "%s %s", "findflags ", *i);
      _V_strlower(start: v4);
      ++v5;
      v4 += 64;
    }
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10159B40
// Name: public: void CCvarUtilities::CvarFindFlags_f(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCvarUtilities::CvarFindFlags_f(CCvarUtilities *this, const CCommand *args)
{
  unsigned int j; // esi
  ICvar::ICVarIteratorInternal *v3; // ebx
  const ConCommandBase *v4; // edi
  unsigned int i; // esi
  const char *argsa; // [esp+10h] [ebp+8h]

  if ( args->m_nArgc >= 2 )
  {
    if ( args->m_nArgc > 1 )
      argsa = args->m_ppArgv[1];
    else
      argsa = defaultValue;
    v3 = g_pCVar->FactoryInternalIterator(this: g_pCVar);
    v3->SetFirst(this: v3);
    while ( v3->IsValid(this: v3) )
    {
      v4 = v3->Get(this: v3);
      if ( !v4->IsFlagSet(this: (ConCommandBase *)v4, a2: 2) && !v4->IsFlagSet(this: (ConCommandBase *)v4, a2: 16) )
      {
        for ( i = 0; i < 18; ++i )
        {
          if ( v4->IsFlagSet(this: (ConCommandBase *)v4, a2: g_ConVarFlags[i].bit)
            && _V_stricmp(s1: g_ConVarFlags[i].desc, s2: argsa) == 0 )
          {
            ConVar_PrintDescription(pVar: v4);
          }
        }
      }
      v3->Next(this: v3);
    }
    free(pMem: v3);
  }
  else
  {
    ConMsg(a1: "Usage:  findflags <string>\n");
    ConMsg(a1: "Available flags to search for: \n");
    for ( j = 0; j < 18; ++j )
      ConMsg(a1: "   - %s\n", g_ConVarFlags[j].desc);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10159C70
// Name: int FindFlagsCompletionCallback(char const __near *,char (__near * const)[64])
// Source: json
//------------------------------------------------------------------------------
int __cdecl FindFlagsCompletionCallback(const char *partial, char (*commands)[64])
{
  return CCvarUtilities::CvarFindFlagsCompletionCallback(this: cv, partial, commands);
}

//------------------------------------------------------------------------------
// Address: 0x10159C90
// Name: findflags
// Source: json
//------------------------------------------------------------------------------
void __cdecl findflags(const CCommand *args)
{
  CCvarUtilities::CvarFindFlags_f(this: cv, args);
}

//------------------------------------------------------------------------------
// Address: 0x10159CB0
// Name: help
// Source: json
//------------------------------------------------------------------------------
void __cdecl help(const CCommand *args)
{
  const char *v1; // esi
  const ConCommandBase *v2; // eax

  if ( args->m_nArgc == 2 )
  {
    v1 = args->m_ppArgv[1];
    v2 = g_pCVar->FindCommandBase_2(this: g_pCVar, a2: v1);
    if ( v2 != nullptr )
      ConVar_PrintDescription(pVar: v2);
    else
      ConMsg(a1: "help:  no cvar or command named %s\n", v1);
  }
  else
  {
    ConMsg(a1: "Usage:  help <cvarname>\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10159D10
// Name: differences
// Source: json
//------------------------------------------------------------------------------
void __cdecl differences(const CCommand *args)
{
  CCvarUtilities::CvarDifferences(this: cv, args);
}

//------------------------------------------------------------------------------
// Address: 0x10159D30
// Name: CanCheat
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CanCheat()
{
  return sv_cheats.m_pParent != nullptr && sv_cheats.m_pParent->m_Value.m_nValue != 0 || Cmd_IsRptActive();
}

//------------------------------------------------------------------------------
// Address: 0x10159D60
// Name: public: bool CCvarUtilities::IsCommand(class CCommand const __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCvarUtilities::IsCommand(CCvarUtilities *this, const CCommand *args, const int iSplitscreenSlot)
{
  int m_nArgc; // ebx
  const char *v5; // eax
  ConVar *v6; // eax
  ConVar *v7; // edi
  const char *v8; // eax
  const char *v9; // eax
  const char *v10; // eax
  const char *v11; // eax
  const char *v12; // eax
  int m_nArgv0Size; // eax
  const char *v14; // esi
  int v15; // ebx
  int v16; // eax
  bool v17; // zf
  const char *v18; // eax
  char *i; // eax
  char buf[512]; // [esp+4h] [ebp-604h] BYREF
  char remaining[1024]; // [esp+204h] [ebp-404h] BYREF
  CCvarUtilities *v22; // [esp+604h] [ebp-4h]
  bool bIsQuoted_3; // [esp+617h] [ebp+Fh]

  m_nArgc = args->m_nArgc;
  v22 = this;
  if ( m_nArgc == 0 )
    return 0;
  if ( m_nArgc > 0 )
    v5 = args->m_ppArgv[0];
  else
    v5 = defaultValue;
  v6 = g_pCVar->FindVar_2(this: g_pCVar, a2: v5);
  v7 = v6;
  if ( v6 == nullptr )
    return 0;
  if ( iSplitscreenSlot > 0 && v6->IsFlagSet(this: v6, a2: 0x8000) )
  {
    if ( args->m_nArgc > 0 )
      v8 = args->m_ppArgv[0];
    else
      v8 = defaultValue;
    V_snprintf(pDest: buf, maxLen: 512, pFormat: "%s%d", v8, iSplitscreenSlot + 1);
    v7 = g_pCVar->FindVar_2(this: g_pCVar, a2: buf);
  }
  if ( v7 == nullptr || v7->IsFlagSet(this: v7, a2: 2) )
    return 0;
  if ( m_nArgc == 1 )
  {
    ConVar_PrintDescription(pVar: v7);
    return 1;
  }
  else if ( v7->IsFlagSet(this: v7, a2: 64)
         && GetBaseLocalClient()->m_nSignonState >= 2
         && GetBaseLocalClient()->m_nMaxClients > 1 )
  {
    v9 = v7->GetName(this: v7);
    ConMsg(a1: "Can't set %s in multiplayer\n", v9);
    return 1;
  }
  else if ( v7->IsFlagSet(this: v7, a2: 0x400000) && GetBaseLocalClient()->m_nSignonState >= 2 )
  {
    v10 = v7->GetName(this: v7);
    ConMsg(a1: "Can't set %s when connected\n", v10);
    return 1;
  }
  else if ( !v7->IsFlagSet(this: v7, a2: 0x4000)
         || Host_IsSinglePlayerGame()
         || CanCheat()
         || GetBaseLocalClient()->ishltv
         || demoplayer->IsPlayingBack(this: demoplayer) )
  {
    if ( v7->IsFlagSet(this: v7, a2: 0x2000)
      && !demoplayer->IsPlayingBack(this: demoplayer)
      && sv.m_State <= ss_dead
      && cmd_source == src_command
      && GetBaseLocalClient()->m_nSignonState >= 2 )
    {
      v12 = v7->GetName(this: v7);
      ConMsg(
        a1: "Can't change replicated ConVar %s from console of client, only server operator can change its value\n",
        v12);
      return 1;
    }
    else
    {
      m_nArgv0Size = args->m_nArgv0Size;
      v14 = &args->m_pArgSBuffer[m_nArgv0Size];
      if ( m_nArgv0Size == 0 )
        v14 = defaultValue;
      v15 = _V_strlen(str: v14);
      bIsQuoted_3 = *v14 == 34;
      if ( *v14 == 34 )
      {
        --v15;
        V_strncpy(pDest: remaining, pSrc: ++v14, maxLen: 1024);
      }
      else
      {
        v16 = args->m_nArgv0Size;
        v17 = v16 == 0;
        v18 = &args->m_pArgSBuffer[v16];
        if ( v17 )
          v18 = defaultValue;
        V_strncpy(pDest: remaining, pSrc: v18, maxLen: 1024);
      }
      for ( i = &buf[v15 + 511]; i >= remaining; *i-- = 0 )
      {
        if ( *i > 32 )
          break;
      }
      if ( bIsQuoted_3 && i >= remaining && *i == 34 )
        *i = 0;
      CCvarUtilities::SetDirect(this: v22, a2: v15, a3: (int)v14, var: v7, value: remaining);
      return 1;
    }
  }
  else
  {
    v11 = v7->GetName(this: v7);
    ConMsg(a1: "Can't use cheat cvar %s in multiplayer, unless the server has sv_cheats set to 1.\n", v11);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015A060
// Name: private: bool CCvarUtilities::IsValidToggleCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCvarUtilities::IsValidToggleCommand(CCvarUtilities *this, const char *cmd)
{
  ConVar *v2; // esi
  const char *v4; // eax
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax

  v2 = g_pCVar->FindVar_2(this: g_pCVar, a2: cmd);
  if ( v2 == nullptr )
  {
    ConMsg(a1: "%s is not a valid cvar\n", cmd);
    return 0;
  }
  if ( v2->IsFlagSet(this: v2, a2: 2) || v2->IsFlagSet(this: v2, a2: 16) )
    return 0;
  if ( v2->IsFlagSet(this: v2, a2: 64)
    && GetBaseLocalClient()->m_nSignonState >= 2
    && GetBaseLocalClient()->m_nMaxClients > 1 )
  {
    v4 = v2->GetName(this: v2);
    ConMsg(a1: "Can't set %s in multiplayer\n", v4);
    return 0;
  }
  else if ( v2->IsFlagSet(this: v2, a2: 0x400000) && GetBaseLocalClient()->m_nSignonState >= 2 )
  {
    v5 = v2->GetName(this: v2);
    ConMsg(a1: "Can't set %s when connected\n", v5);
    return 0;
  }
  else if ( !v2->IsFlagSet(this: v2, a2: 0x4000)
         || Host_IsSinglePlayerGame()
         || CanCheat()
         || demoplayer->IsPlayingBack(this: demoplayer) )
  {
    if ( v2->IsFlagSet(this: v2, a2: 0x2000)
      && !demoplayer->IsPlayingBack(this: demoplayer)
      && sv.m_State <= ss_dead
      && cmd_source == src_command
      && GetBaseLocalClient()->m_nSignonState >= 2 )
    {
      v7 = v2->GetName(this: v2);
      ConMsg(
        a1: "Can't change replicated ConVar %s from console of client, only server operator can change its value\n",
        v7);
      return 0;
    }
    else
    {
      return 1;
    }
  }
  else
  {
    v6 = v2->GetName(this: v2);
    ConMsg(a1: "Can't use cheat cvar %s in multiplayer, unless the server has sv_cheats set to 1.\n", v6);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015A200
// Name: public: void CCvarUtilities::CvarToggle(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCvarUtilities::CvarToggle(CCvarUtilities *this, const CCommand *args)
{
  const CCommand *v2; // ebx
  int m_nArgc; // edi
  const char *v5; // eax
  const char *v6; // eax
  ConVar *m_pParent; // eax
  int m_nValue; // eax
  int v9; // esi
  const char **v10; // ebx
  const char *v11; // ecx
  const char *m_pszString; // eax
  int v13; // esi
  const char *v14; // esi
  ConVar *var; // [esp+Ch] [ebp-4h]

  v2 = args;
  m_nArgc = args->m_nArgc;
  if ( args->m_nArgc < 2 )
  {
    ConMsg(a1: "Usage:  toggle <cvarname> [value1] [value2] [value3]...\n");
    return;
  }
  v5 = defaultValue;
  if ( m_nArgc > 1 )
    v5 = args->m_ppArgv[1];
  var = g_pCVar->FindVar_2(this: g_pCVar, a2: v5);
  v6 = defaultValue;
  if ( args->m_nArgc > 1 )
    v6 = args->m_ppArgv[1];
  if ( CCvarUtilities::IsValidToggleCommand(this, cmd: v6) != 0 )
  {
    if ( m_nArgc == 2 )
    {
      m_pParent = var->m_pParent;
      if ( m_pParent != nullptr )
        m_nValue = m_pParent->m_Value.m_nValue;
      else
        m_nValue = 0;
      var->SetValue_2(this: &var->IConVar, a2: m_nValue == 0);
      ConVar_PrintDescription(pVar: var);
      return;
    }
    v9 = 2;
    if ( m_nArgc > 2 )
    {
      v10 = &args->m_ppArgv[2];
      do
      {
        if ( v9 < 0 || v9 >= args->m_nArgc )
          v11 = defaultValue;
        else
          v11 = *v10;
        if ( (var->m_nFlags & 0x1000) != 0 )
        {
          m_pszString = "FCVAR_NEVER_AS_STRING";
        }
        else
        {
          m_pszString = var->m_pParent->m_Value.m_pszString;
          if ( m_pszString == nullptr )
            m_pszString = defaultValue;
        }
        if ( _V_strcmp(s1: m_pszString, s2: v11) == 0 )
          break;
        ++v9;
        ++v10;
      }
      while ( v9 < m_nArgc );
      v2 = args;
    }
    v13 = v9 + 1;
    if ( v13 < m_nArgc )
    {
      if ( v13 < 0 )
        goto LABEL_31;
    }
    else
    {
      v13 = 2;
    }
    if ( v13 < v2->m_nArgc )
    {
      v14 = v2->m_ppArgv[v13];
LABEL_32:
      var->SetValue_4(this: &var->IConVar, a2: v14);
      ConVar_PrintDescription(pVar: var);
      return;
    }
LABEL_31:
    v14 = defaultValue;
    goto LABEL_32;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015A350
// Name: toggle
// Source: json
//------------------------------------------------------------------------------
void __cdecl toggle(const CCommand *args)
{
  CCvarUtilities::CvarToggle(this: cv, args);
}

//------------------------------------------------------------------------------
// Address: 0x1015AEA0
// Name: public: virtual bool CCvarQuery::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCvarQuery::Connect(CCvarQuery *this, void *(__cdecl *factory)(const char *, int *))
{
  void *v3; // eax

  v3 = factory(a1: "VEngineCvar007", a2: nullptr);
  if ( v3 == nullptr )
    return 0;
  (*(void (__thiscall **)(void *, CCvarQuery *))(*(_DWORD *)v3 + 112))(a1: v3, a2: this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1015AED0
// Name: public: virtual void __near * CCvarQuery::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CCvarQuery *__thiscall CCvarQuery::QueryInterface(CCvarQuery *this, const char *pInterfaceName)
{
  return _V_stricmp(s1: pInterfaceName, s2: "VCvarQuery001") == 0 ? this : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1015AF00
// Name: public: virtual bool CCvarQuery::AreConVarsLinkable(class ConVar const __near *,class ConVar const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCvarQuery::AreConVarsLinkable(CCvarQuery *this, ConVar *child, ConVar *parent)
{
  bool v3; // bl
  bool v4; // al
  const char *v6; // [esp-4h] [ebp-210h]
  const char *v7; // [esp-4h] [ebp-210h]
  const char *v8; // [esp-4h] [ebp-210h]
  const char *v9; // [esp-4h] [ebp-210h]
  const char *v10; // [esp-4h] [ebp-210h]
  const char *v11; // [esp-4h] [ebp-210h]
  const char *v12; // [esp-4h] [ebp-210h]
  char sz[512]; // [esp+Ch] [ebp-200h] BYREF

  v3 = child->IsFlagSet(this: child, a2: 0x2000);
  v4 = parent->IsFlagSet(this: parent, a2: 0x2000);
  if ( !v3 )
  {
    if ( !v4 )
    {
      if ( parent->IsFlagSet(this: parent, a2: 8) )
      {
        v10 = child->GetName(this: child);
        V_snprintf(pDest: sz, maxLen: 512, pFormat: "Parent cvar in client.dll not allowed (%s)\n", v10);
        goto LABEL_22;
      }
      if ( parent->IsFlagSet(this: parent, a2: 4) )
      {
        v11 = child->GetName(this: child);
        V_snprintf(pDest: sz, maxLen: 512, pFormat: "Parent cvar in server.dll not allowed (%s)\n", v11);
        goto LABEL_22;
      }
      return 1;
    }
LABEL_21:
    v12 = child->GetName(this: child);
    V_snprintf(
      pDest: sz,
      maxLen: 512,
      pFormat: "Both ConVars must be marked FCVAR_REPLICATED for linkage to work (%s)\n",
      v12);
    goto LABEL_22;
  }
  if ( !v4 )
    goto LABEL_21;
  if ( child->IsFlagSet(this: child, a2: 32) || parent->IsFlagSet(this: parent, a2: 32) )
  {
    v9 = child->GetName(this: child);
    V_snprintf(pDest: sz, maxLen: 512, pFormat: "FCVAR_REPLICATED can't also be FCVAR_PROTECTED (%s)\n", v9);
    goto LABEL_22;
  }
  if ( child->IsCommand(this: child) || parent->IsCommand(this: parent) )
  {
    v8 = child->GetName(this: child);
    V_snprintf(pDest: sz, maxLen: 512, pFormat: "FCVAR_REPLICATED not valid on ConCommands (%s)\n", v8);
    goto LABEL_22;
  }
  if ( !child->IsFlagSet(this: child, a2: 4) || parent->IsFlagSet(this: parent, a2: 8) )
  {
    if ( child->IsFlagSet(this: child, a2: 8) && !parent->IsFlagSet(this: parent, a2: 4) )
    {
      v7 = child->GetName(this: child);
      V_snprintf(
        pDest: sz,
        maxLen: 512,
        pFormat: "For FCVAR_REPLICATED, ConVar must be defined in client and game .dlls (%s)\n",
        v7);
      goto LABEL_22;
    }
    return 1;
  }
  v6 = child->GetName(this: child);
  V_snprintf(
    pDest: sz,
    maxLen: 512,
    pFormat: "For FCVAR_REPLICATED, ConVar must be defined in client and game .dlls (%s)\n",
    v6);
LABEL_22:
  ConMsg(a1: sz);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1015C1C0
// Name: ConVarNetworkChangeCallback
// Source: json
//------------------------------------------------------------------------------
void __usercall ConVarNetworkChangeCallback(int a1@<esi>, IConVar *pConVar, const char *pOldValue, float flOldValue)
{
  const char *v4; // eax
  CClientState *LocalClient; // eax
  IGameEvent *v6; // esi
  int v7; // eax
  bool v8; // al
  IGameEvent_vtbl *v9; // edx
  const ConVar *v10; // eax
  const char *v12; // [esp+0h] [ebp-30h]
  NET_SetConVar convar; // [esp+4h] [ebp-2Ch] BYREF
  ConVarRef var; // [esp+28h] [ebp-8h] BYREF

  ConVarRef::ConVarRef(this: &var, pConVar);
  if ( pOldValue != nullptr )
  {
    if ( _V_strcmp(s1: var.m_pConVarState->m_Value.m_pszString, s2: pOldValue) == 0 )
      return;
  }
  else if ( var.m_pConVarState->m_Value.m_fValue == flOldValue )
  {
    return;
  }
  if ( var.m_pConVar->IsFlagSet(this: var.m_pConVar, a2: 512) && GetLocalClient(nSlot: -1)->m_nSignonState >= 2 )
  {
    v4 = (const char *)((int (__thiscall *)(IConVar *, char *))var.m_pConVar->GetBaseName)(
                         a1: var.m_pConVar,
                         a2: var.m_pConVarState->m_Value.m_pszString);
    NET_SetConVar::NET_SetConVar(this: &convar, name: v4, value: v12);
    LocalClient = GetLocalClient(nSlot: -1);
    ((void (__thiscall *)(INetChannel *, NET_SetConVar *, _DWORD))LocalClient->m_NetChannel->SendNetMsg)(
      a1: LocalClient->m_NetChannel,
      a2: &convar,
      a3: 0);
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&convar.m_ConVars);
  }
  if ( var.m_pConVar->IsFlagSet(this: var.m_pConVar, a2: 256) )
  {
    v6 = g_GameEventManager->CreateEventA(this: g_GameEventManager, a2: "server_cvar", a3: 0, a4: 0);
    if ( v6 != nullptr )
    {
      v7 = ((int (__thiscall *)(IConVar *, int))var.m_pConVar->GetName)(a1: var.m_pConVar, a2: a1);
      v6->SetString(this: v6, a2: "cvarname", a3: (const char *)v7);
      v8 = var.m_pConVar->IsFlagSet(this: var.m_pConVar, a2: 32);
      v9 = v6->__vftable;
      if ( v8 )
        v9->SetString(this: v6, a2: "cvarvalue", a3: "***PROTECTED***");
      else
        v9->SetString(this: v6, a2: "cvarvalue", a3: var.m_pConVarState->m_Value.m_pszString);
      ((void (__thiscall *)(CGameEventManager *, IGameEvent *))g_GameEventManager->FireEvent)(
        a1: g_GameEventManager,
        a2: v6);
    }
  }
  if ( var.m_pConVar->IsFlagSet(this: var.m_pConVar, a2: 0x2000) && sv.m_State >= ss_active )
  {
    if ( pConVar != nullptr )
      v10 = (const ConVar *)&pConVar[-6];
    else
      v10 = nullptr;
    SV_ReplicateConVarChange(var: v10, newValue: var.m_pConVarState->m_Value.m_pszString);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015C340
// Name: public: virtual enum InitReturnVal_t CCvarQuery::Init(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCvarQuery::Init(CCvarQuery *this)
{
  if ( !this->m_bCallbackInstalled )
  {
    this->m_bCallbackInstalled = true;
    g_pCVar->InstallGlobalChangeCallback(this: g_pCVar, a2: ConVarNetworkChangeCallback);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1015C370
// Name: public: virtual void CCvarQuery::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCvarQuery::Shutdown(CCvarQuery *this)
{
  g_pCVar->RemoveGlobalChangeCallback(this: g_pCVar, a2: ConVarNetworkChangeCallback);
  this->m_bCallbackInstalled = false;
}

//------------------------------------------------------------------------------
// Address: 0x1015C390
// Name: void InstallConVarHook(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallConVarHook()
{
  if ( !s_CvarQuery.m_bCallbackInstalled )
  {
    s_CvarQuery.m_bCallbackInstalled = true;
    g_pCVar->InstallGlobalChangeCallback(
      this: g_pCVar,
      a2: (void (__cdecl *)(IConVar *, const char *, float))ConVarNetworkChangeCallback);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015C430
// Name: public: void CCvarUtilities::WriteVariables(class CUtlBuffer __near *,int,bool,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCvarUtilities::WriteVariables(
        CCvarUtilities *this,
        CUtlBuffer *buff,
        int iSplitscreenSlot,
        bool bSlotRequired,
        CUtlMemory<S3RGBA,int> *pConvarsListVoid)
{
  ICvar::ICVarIteratorInternal *(__thiscall *FactoryInternalIterator)(ICvar *); // edx
  ICvar::ICVarIteratorInternal *m_pIter; // edi
  void (__thiscall *SetFirst)(ICvar::ICVarIteratorInternal *); // edx
  ConVar *v8; // esi
  char v9; // bl
  _DWORD *v10; // eax
  int v11; // eax
  UtlRBTreeNode_t<ConVar *,int> *m_pMemory; // ecx
  int v13; // edx
  int v14; // esi
  int v15; // edx
  int v16; // eax
  ConVar *m_Data; // ebx
  int v18; // eax
  const char *v19; // edi
  const char *m_pszString; // eax
  const char *v21; // eax
  S3RGBA *v22; // edi
  int m_nAllocationCount; // eax
  S3RGBA *v24; // ecx
  int v25; // eax
  ConVar **v26; // eax
  CUtlRBTree<ConVar *,int,bool (__cdecl*)(ConVar * const &,ConVar * const &),CUtlMemory<UtlRBTreeNode_t<ConVar *,int>,int> > sorted; // [esp+Ch] [ebp-34h] BYREF
  int parent; // [esp+30h] [ebp-10h] BYREF
  ICvar::Iterator iter; // [esp+34h] [ebp-Ch]
  ConVar *cv; // [esp+38h] [ebp-8h] BYREF
  bool leftchild; // [esp+3Fh] [ebp-1h] BYREF
  int i; // [esp+50h] [ebp+10h]

  FactoryInternalIterator = g_pCVar->FactoryInternalIterator;
  sorted.m_LessFunc = CVarSortFunc;
  memset(&sorted.m_Elements, 0, sizeof(sorted.m_Elements));
  sorted.m_Root = -1;
  sorted.m_NumElements = 0;
  sorted.m_FirstFree = -1;
  sorted.m_LastAlloc.index = -1;
  sorted.m_pElements = nullptr;
  m_pIter = FactoryInternalIterator(this: g_pCVar);
  SetFirst = m_pIter->SetFirst;
  iter.m_pIter = m_pIter;
  SetFirst(this: m_pIter);
  while ( m_pIter->IsValid(this: m_pIter) )
  {
    v8 = (ConVar *)m_pIter->Get(this: m_pIter);
    if ( v8->IsCommand(this: v8) )
      goto LABEL_22;
    cv = v8;
    if ( !v8->IsFlagSet(this: v8, a2: 128) )
      goto LABEL_22;
    if ( iSplitscreenSlot < 0 )
      goto LABEL_14;
    v9 = 0;
    if ( cv->IsFlagSet(this: cv, a2: 0x8000) )
    {
      if ( iSplitscreenSlot != 0 )
        goto LABEL_21;
      v9 = 1;
    }
    if ( !cv->IsFlagSet(this: cv, a2: 0x40000) )
      goto LABEL_12;
    v10 = __RTDynamicCast(
            inptr: cv,
            VfDelta: 0,
            SrcType: &ConVar `RTTI Type Descriptor',
            TargetType: &CSplitScreenAddedConVar `RTTI Type Descriptor',
            isReference: 0);
    if ( v10 == nullptr || (*(int (__thiscall **)(_DWORD *))(v10[6] + 28))(a1: v10 + 6) == iSplitscreenSlot )
    {
      v9 = 1;
LABEL_12:
      if ( bSlotRequired == v9 )
      {
        m_pIter = iter.m_pIter;
LABEL_14:
        parent = -1;
        leftchild = false;
        CUtlRBTree<ConVar *,int,bool (__cdecl *)(ConVar * const &,ConVar * const &),CUtlMemory<UtlRBTreeNode_t<ConVar *,int>,int>>::FindInsertionPosition(
          this: &sorted,
          insert: &cv,
          &parent,
          &leftchild);
        v11 = CUtlRBTree<msurface2_t *,int,bool (__cdecl *)(msurface2_t * const &,msurface2_t * const &),CUtlMemory<UtlRBTreeNode_t<msurface2_t *,int>,int>>::NewNode(this: (CUtlRBTree<char const *,int,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int> > *)&sorted);
        m_pMemory = sorted.m_Elements.m_pMemory;
        v13 = parent;
        v14 = v11;
        sorted.m_Elements.m_pMemory[v14].m_Parent = parent;
        m_pMemory[v14].m_Right = -1;
        m_pMemory[v14].m_Left = -1;
        m_pMemory[v14].m_Tag = 0;
        if ( v13 == -1 )
        {
          sorted.m_Root = v11;
        }
        else
        {
          v15 = v13;
          if ( leftchild )
            m_pMemory[v15].m_Left = v11;
          else
            m_pMemory[v15].m_Right = v11;
        }
        CUtlRBTree<ConVar *,int,bool (__cdecl *)(ConVar * const &,ConVar * const &),CUtlMemory<UtlRBTreeNode_t<ConVar *,int>,int>>::InsertRebalance(
          this: &sorted,
          elem: v11);
        ++sorted.m_NumElements;
        if ( &sorted.m_Elements.m_pMemory[v14] != (UtlRBTreeNode_t<ConVar *,int> *)-16 )
          sorted.m_Elements.m_pMemory[v14].m_Data = cv;
        goto LABEL_22;
      }
    }
LABEL_21:
    m_pIter = iter.m_pIter;
LABEL_22:
    m_pIter->Next(this: m_pIter);
  }
  v16 = CUtlRBTree<ConVar *,int,bool (__cdecl *)(ConVar * const &,ConVar * const &),CUtlMemory<UtlRBTreeNode_t<ConVar *,int>,int>>::FirstInorder(this: &sorted);
  i = v16;
  if ( v16 != -1 )
  {
    while ( 1 )
    {
      m_Data = sorted.m_Elements.m_pMemory[v16].m_Data;
      v18 = (int)(iSplitscreenSlot < 0 ? m_Data->GetName(this: m_Data) : m_Data->GetBaseName(this: &m_Data->IConVar));
      v19 = (const char *)v18;
      if ( (m_Data->m_nFlags & 0x1000) != 0 )
      {
        m_pszString = "FCVAR_NEVER_AS_STRING";
      }
      else
      {
        m_pszString = m_Data->m_pParent->m_Value.m_pszString;
        if ( m_pszString == nullptr )
          m_pszString = defaultValue;
      }
      _DevMsg(a1: 2, a2: "%s \"%s\"\n", v19, m_pszString);
      if ( buff != nullptr )
      {
        if ( (m_Data->m_nFlags & 0x1000) != 0 )
        {
          v21 = "FCVAR_NEVER_AS_STRING";
        }
        else
        {
          v21 = m_Data->m_pParent->m_Value.m_pszString;
          if ( v21 == nullptr )
            v21 = defaultValue;
        }
        CUtlBuffer::Printf(this: buff, pFmt: "%s \"%s\"\n", v19, v21);
      }
      if ( pConvarsListVoid != nullptr )
      {
        v22 = pConvarsListVoid[1].m_pMemory;
        m_nAllocationCount = pConvarsListVoid->m_nAllocationCount;
        if ( (int)&v22->g > m_nAllocationCount )
          CUtlMemory<INetMessage *,int>::Grow(this: pConvarsListVoid, num: (int)(&v22->g - m_nAllocationCount));
        ++pConvarsListVoid[1].m_pMemory;
        v24 = pConvarsListVoid->m_pMemory;
        v25 = (char *)pConvarsListVoid[1].m_pMemory - (char *)v22 - 1;
        pConvarsListVoid[1].m_nAllocationCount = (int)pConvarsListVoid->m_pMemory;
        if ( v25 > 0 )
          _V_memmove(dest: &v24[(_DWORD)v22 + 1], src: &v24[(_DWORD)v22], count: 4 * v25);
        v26 = (ConVar **)&pConvarsListVoid->m_pMemory[(_DWORD)v22];
        if ( v26 != nullptr )
          *v26 = m_Data;
      }
      i = CUtlRBTree<ConVar *,int,bool (__cdecl *)(ConVar * const &,ConVar * const &),CUtlMemory<UtlRBTreeNode_t<ConVar *,int>,int>>::NextInorder(
            this: &sorted,
            i);
      if ( i == -1 )
        break;
      v16 = i;
    }
    m_pIter = iter.m_pIter;
  }
  free(pMem: m_pIter);
  CUtlRBTree<ConVar *,int,bool (__cdecl *)(ConVar * const &,ConVar * const &),CUtlMemory<UtlRBTreeNode_t<ConVar *,int>,int>>::RemoveAll(this: &sorted);
  if ( sorted.m_Elements.m_nGrowSize >= 0 && sorted.m_Elements.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sorted.m_Elements.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1015C740
// Name: public: void CCvarUtilities::CvarList(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCvarUtilities::CvarList(CCvarUtilities *this, ConCommandBase *args)
{
  const CCommand *v2; // esi
  int v3; // ebx
  const char *v4; // edi
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // esi
  ICvar::ICVarIteratorInternal *(__thiscall *FactoryInternalIterator)(ICvar *); // eax
  ICvar::ICVarIteratorInternal *v9; // esi
  const char *v10; // eax
  int v11; // ebx
  const ConCommand *m_Data; // edi
  int v13; // [esp-4h] [ebp-13Ch]
  char fn[256]; // [esp+Ch] [ebp-12Ch] BYREF
  CUtlRBTree<ConCommandBase const *,unsigned short,bool (__cdecl*)(ConCommandBase const * const &,ConCommandBase const * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase const *,unsigned short>,unsigned short> > sorted; // [esp+10Ch] [ebp-2Ch] BYREF
  int ipLen; // [esp+128h] [ebp-10h]
  const char *partial; // [esp+12Ch] [ebp-Ch]
  BOOL bLogging; // [esp+130h] [ebp-8h]
  void *f; // [esp+134h] [ebp-4h] BYREF

  v2 = (const CCommand *)args;
  v3 = (int)args->__vftable;
  v4 = nullptr;
  partial = nullptr;
  ipLen = 0;
  f = nullptr;
  LOBYTE(bLogging) = 0;
  if ( v3 == 2 && V_strcasecmp(s1: (const char *)args[43].m_pNext, s2: "?") == 0 )
  {
    ConMsg(a1: "cvarlist:  [log logfile] [ partial ]\n");
    return;
  }
  v5 = defaultValue;
  if ( v2->m_nArgc > 1 )
    v5 = v2->m_ppArgv[1];
  if ( V_strcasecmp(s1: v5, s2: "log") != 0 || v3 < 3 )
  {
    if ( v2->m_nArgc > 1 )
      v7 = v2->m_ppArgv[1];
    else
      v7 = defaultValue;
    goto LABEL_19;
  }
  v6 = defaultValue;
  if ( v2->m_nArgc > 2 )
    v6 = v2->m_ppArgv[2];
  V_snprintf(pDest: fn, maxLen: 256, pFormat: "%s", v6);
  f = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: fn, a3: "wb", a4: 0);
  if ( f == nullptr )
  {
    ConMsg(a1: "Couldn't open '%s' for writing!\n", fn);
    return;
  }
  LOBYTE(bLogging) = 1;
  if ( v3 == 4 )
  {
    if ( v2->m_nArgc > 3 )
      v7 = v2->m_ppArgv[3];
    else
      v7 = defaultValue;
LABEL_19:
    partial = v7;
    v4 = v7;
    ipLen = _V_strlen(str: v7);
  }
  ConMsg(a1: "cvar list\n--------------\n");
  FactoryInternalIterator = g_pCVar->FactoryInternalIterator;
  sorted.m_LessFunc = ConCommandBaseLessFunc;
  memset(&sorted.m_Elements, 0, sizeof(sorted.m_Elements));
  *(_DWORD *)&sorted.m_Root = 0xFFFF;
  *(_DWORD *)&sorted.m_FirstFree = -1;
  sorted.m_pElements = nullptr;
  v9 = FactoryInternalIterator(this: g_pCVar);
  v9->SetFirst(this: v9);
  while ( v9->IsValid(this: v9) )
  {
    args = v9->Get(this: v9);
    if ( !args->IsFlagSet(this: args, a2: 2) && !args->IsFlagSet(this: args, a2: 16) )
    {
      if ( v4 == nullptr || (v13 = ipLen, v10 = args->GetName(this: args), V_strncasecmp(s1: v10, s2: v4, n: v13) == 0) )
        CUtlRBTree<ConCommandBase const *,unsigned short,bool (__cdecl *)(ConCommandBase const * const &,ConCommandBase const * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase const *,unsigned short>,unsigned short>>::Insert(
          this: &sorted,
          insert: (const ConCommandBase *const *)&args);
    }
    v9->Next(this: v9);
  }
  if ( bLogging )
    PrintListHeader(&f);
  v11 = CUtlRBTree<ConCommandBase const *,unsigned short,bool (__cdecl *)(ConCommandBase const * const &,ConCommandBase const * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase const *,unsigned short>,unsigned short>>::FirstInorder(this: &sorted);
  if ( v11 != 0xFFFF )
  {
    do
    {
      m_Data = (const ConCommand *)sorted.m_Elements.m_pMemory[(unsigned __int16)v11].m_Data;
      if ( m_Data->IsCommand(this: (struct ConCommand *)m_Data) )
        PrintCommand(cmd: m_Data, logging: bLogging, &f);
      else
        PrintCvar(var: (const ConVar *)m_Data, logging: bLogging, &f);
      v11 = CUtlRBTree<ConCommandBase const *,unsigned short,bool (__cdecl *)(ConCommandBase const * const &,ConCommandBase const * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase const *,unsigned short>,unsigned short>>::NextInorder(
              this: &sorted,
              i: v11);
    }
    while ( v11 != 0xFFFF );
    v4 = partial;
  }
  if ( v4 != nullptr && *v4 != 0 )
    ConMsg(a1: "--------------\n%3i convars/concommands for [%s]\n", sorted.m_NumElements, v4);
  else
    ConMsg(a1: "--------------\n%3i total convars/concommands\n", sorted.m_NumElements);
  if ( bLogging )
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: f);
  free(pMem: v9);
  CUtlRBTree<ConCommandBase const *,unsigned short,bool (__cdecl *)(ConCommandBase const * const &,ConCommandBase const * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase const *,unsigned short>,unsigned short>>::RemoveAll(this: &sorted);
  if ( sorted.m_Elements.m_nGrowSize >= 0 && sorted.m_Elements.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sorted.m_Elements.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1015CA50
// Name: cvarlist
// Source: json
//------------------------------------------------------------------------------
void __cdecl cvarlist(ConCommandBase *args)
{
  CCvarUtilities::CvarList(this: cv, args);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10159450
// Name: CVarSortFunc
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CVarSortFunc(ConVar *const *lhs, ConVar *const *rhs)
{
  const char *v2; // esi
  const char *v3; // eax

  v2 = (const char *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)rhs + 24))(a1: *rhs);
  v3 = (const char *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)lhs + 24))(a1: *lhs);
  if ( v3 == nullptr )
    return false;
  if ( v2 != nullptr )
    return _V_stricmp(s1: v3, s2: v2) < 0;
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x101594A0
// Name: cmd1
// Source: json
//------------------------------------------------------------------------------
void __cdecl cmd1(const CCommand *args)
{
  int m_nArgv0Size; // eax
  bool v2; // zf
  const char *v3; // eax
  const char *v4; // eax

  m_nArgv0Size = args->m_nArgv0Size;
  if ( host_state.max_splitscreen_players > 0 )
  {
    v2 = m_nArgv0Size == 0;
    v4 = &args->m_pArgSBuffer[m_nArgv0Size];
    if ( v2 )
      v4 = defaultValue;
    Cbuf_AddText(eTarget: CBUF_FIRST_PLAYER, pText: v4, nTickDelay: 0);
  }
  else
  {
    v2 = m_nArgv0Size == 0;
    v3 = &args->m_pArgSBuffer[m_nArgv0Size];
    if ( v2 )
      v3 = defaultValue;
    _DevMsg(a1: 1, a2: "ignore:  %d '%s'\n", 0, v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101594F0
// Name: cmd2
// Source: json
//------------------------------------------------------------------------------
void __cdecl cmd2(const CCommand *args)
{
  int m_nArgv0Size; // eax
  bool v2; // zf
  const char *v3; // eax
  const char *v4; // eax

  m_nArgv0Size = args->m_nArgv0Size;
  if ( host_state.max_splitscreen_players > 1 )
  {
    v2 = m_nArgv0Size == 0;
    v4 = &args->m_pArgSBuffer[m_nArgv0Size];
    if ( v2 )
      v4 = defaultValue;
    Cbuf_AddText(eTarget: CBUF_LAST_PLAYER, pText: v4, nTickDelay: 0);
  }
  else
  {
    v2 = m_nArgv0Size == 0;
    v3 = &args->m_pArgSBuffer[m_nArgv0Size];
    if ( v2 )
      v3 = defaultValue;
    _DevMsg(a1: 1, a2: "ignore:  %d '%s'\n", 1, v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10159540
// Name: cmd3
// Source: json
//------------------------------------------------------------------------------
void __cdecl cmd3(const CCommand *args)
{
  int m_nArgv0Size; // eax
  bool v2; // zf
  const char *v3; // eax
  const char *v4; // eax

  m_nArgv0Size = args->m_nArgv0Size;
  if ( host_state.max_splitscreen_players > 2 )
  {
    v2 = m_nArgv0Size == 0;
    v4 = &args->m_pArgSBuffer[m_nArgv0Size];
    if ( v2 )
      v4 = defaultValue;
    Cbuf_AddText(eTarget: CBUF_SERVER, pText: v4, nTickDelay: 0);
  }
  else
  {
    v2 = m_nArgv0Size == 0;
    v3 = &args->m_pArgSBuffer[m_nArgv0Size];
    if ( v2 )
      v3 = defaultValue;
    _DevMsg(a1: 1, a2: "ignore:  %d '%s'\n", 2, v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10159590
// Name: cmd4
// Source: json
//------------------------------------------------------------------------------
void __cdecl cmd4(const CCommand *args)
{
  int m_nArgv0Size; // eax
  bool v2; // zf
  const char *v3; // eax
  const char *v4; // eax

  m_nArgv0Size = args->m_nArgv0Size;
  if ( host_state.max_splitscreen_players > 3 )
  {
    v2 = m_nArgv0Size == 0;
    v4 = &args->m_pArgSBuffer[m_nArgv0Size];
    if ( v2 )
      v4 = defaultValue;
    Cbuf_AddText(eTarget: CBUF_COUNT, pText: v4, nTickDelay: 0);
  }
  else
  {
    v2 = m_nArgv0Size == 0;
    v3 = &args->m_pArgSBuffer[m_nArgv0Size];
    if ( v2 )
      v3 = defaultValue;
    _DevMsg(a1: 1, a2: "ignore:  %d '%s'\n", 3, v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101595E0
// Name: StripTabsAndReturns
// Source: json
//------------------------------------------------------------------------------
char *__usercall StripTabsAndReturns@<eax>(const char *inbuffer@<ecx>, char *outbuffer@<eax>, int outbufferSize)
{
  const char *v3; // esi
  bool v4; // zf
  char *v5; // ecx
  int v6; // edi
  char v7; // dl

  v3 = inbuffer;
  *outbuffer = 0;
  v4 = *inbuffer == 0;
  v5 = outbuffer;
  if ( !v4 )
  {
    v6 = 0;
    do
    {
      if ( v6 >= outbufferSize - 1 )
        break;
      v7 = *v3;
      if ( *v3 == 10 || v7 == 13 || v7 == 9 )
      {
        *v5 = 32;
        ++v6;
      }
      else
      {
        ++v6;
        *v5 = v7 == 34 ? 39 : v7;
      }
      ++v3;
      ++v5;
    }
    while ( *v3 != 0 );
  }
  *v5 = 0;
  return outbuffer;
}

//------------------------------------------------------------------------------
// Address: 0x10159630
// Name: PrintListHeader
// Source: json
//------------------------------------------------------------------------------
void __cdecl PrintListHeader(void **f)
{
  const char **p_desc; // esi
  char csvflagstr[1024]; // [esp+4h] [ebp-440h] BYREF
  char csvf[64]; // [esp+404h] [ebp-40h] BYREF

  csvflagstr[0] = 0;
  p_desc = &g_ConVarFlags[0].desc;
  do
  {
    V_snprintf(pDest: csvf, maxLen: 64, pFormat: "\"%s\",", *p_desc);
    V_strncat(pDest: csvflagstr, pSrc: csvf, destBufferSize: 0x400u, max_chars_to_copy: -1);
    p_desc += 3;
  }
  while ( (int)p_desc < (int)&vec2_invalid_46.y );
  g_pFileSystem->FPrintf(
    this: g_pFileSystem,
    a2: *f,
    a3: "\"%s\",\"%s\",%s,\"%s\"\n",
    "Name",
    "Value",
    csvflagstr,
    "Help Text");
}

//------------------------------------------------------------------------------
// Address: 0x101596C0
// Name: PrintCvar
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall PrintCvar(ConVar *var@<edi>, bool logging, void **f)
{
  const char **p_desc; // esi
  ConVar *m_pParent; // eax
  int m_nValue; // ecx
  int m_fValue; // edx
  int v7; // eax
  const char *v8; // eax
  char *v9; // eax
  const char *v10; // eax
  const char *v11; // eax
  char v12; // dl
  char *v13; // ecx
  int v14; // esi
  IFileSystem *v15; // eax
  IFileSystem_vtbl *v16; // esi
  int v17; // eax
  const char *v18; // [esp-4h] [ebp-594h]
  const char *v19; // [esp+0h] [ebp-590h]
  const char *v20; // [esp+4h] [ebp-58Ch]
  char v21[16]; // [esp+8h] [ebp-588h] BYREF
  char csvflagstr[1024]; // [esp+18h] [ebp-578h] BYREF
  char flagstr[128]; // [esp+418h] [ebp-178h] BYREF
  char tempbuff[128]; // [esp+498h] [ebp-F8h] BYREF
  char csvf[64]; // [esp+518h] [ebp-78h] BYREF
  char v26[12]; // [esp+56Ch] [ebp-24h] BYREF
  float valstr_20; // [esp+58Ch] [ebp-4h] OVERLAPPED

  csvflagstr[1012] = 0;
  v21[4] = 0;
  p_desc = &g_ConVarFlags[0].desc;
  do
  {
    if ( var->IsFlagSet(this: var, a2: (int)*(p_desc - 1)) )
    {
      V_snprintf(pDest: &csvf[52], maxLen: 32, pFormat: ", %s", p_desc[1]);
      V_strncat(pDest: &csvflagstr[1012], pSrc: &csvf[52], destBufferSize: 0x80u, max_chars_to_copy: -1);
      V_snprintf(pDest: &tempbuff[116], maxLen: 64, pFormat: "\"%s\",", *p_desc);
    }
    else
    {
      V_snprintf(pDest: &tempbuff[116], maxLen: 64, pFormat: ",");
    }
    V_strncat(pDest: &v21[4], pSrc: &tempbuff[116], destBufferSize: 0x400u, max_chars_to_copy: -1);
    p_desc += 3;
  }
  while ( (int)p_desc < (int)&vec2_invalid_46.y );
  m_pParent = var->m_pParent;
  if ( m_pParent != nullptr )
    m_nValue = m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  m_fValue = (int)m_pParent->m_Value.m_fValue;
  valstr_20 = m_pParent->m_Value.m_fValue;
  if ( m_nValue == m_fValue )
  {
    if ( m_pParent != nullptr )
      v7 = m_pParent->m_Value.m_nValue;
    else
      v7 = 0;
    V_snprintf(pDest: v26, maxLen: 32, pFormat: "%-8i", v7);
  }
  else
  {
    V_snprintf(pDest: v26, maxLen: 32, pFormat: "%-8.3f", valstr_20);
  }
  v8 = var->GetHelpText(this: var);
  v9 = StripTabsAndReturns(inbuffer: v8, outbuffer: &flagstr[116], outbufferSize: 128);
  v10 = (const char *)((int (__thiscall *)(ConVar *, char *, char *, char *))var->GetName)(
                        a1: var,
                        a2: v26,
                        a3: &csvflagstr[1012],
                        a4: v9);
  ConMsg(a1: "%-40s : %-8s : %-16s : %s\n", v10, v18, v19, v20);
  if ( logging )
  {
    v11 = var->GetHelpText(this: var);
    flagstr[116] = 0;
    v12 = *v11;
    v13 = &flagstr[116];
    if ( *v11 != 0 )
    {
      v14 = 0;
      do
      {
        if ( v14 >= 127 )
          break;
        ++v14;
        *v13 = v12 == 34 ? 39 : v12;
        v12 = *++v11;
        ++v13;
      }
      while ( v12 != 0 );
    }
    v15 = g_pFileSystem;
    *v13 = 0;
    v16 = v15->IAppSystem::__vftable;
    v17 = ((int (__thiscall *)(ConVar *, char *, char *, char *))var->GetName)(
            a1: var,
            a2: v26,
            a3: &v21[4],
            a4: &flagstr[116]);
    v16->FPrintf(this: g_pFileSystem, a2: *f, a3: "\"%s\",\"%s\",%s,\"%s\"\n", v17);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10159A00
// Name: ConCommandBaseLessFunc
// Source: json
//------------------------------------------------------------------------------
bool __cdecl ConCommandBaseLessFunc(const ConCommandBase *const *lhs, const ConCommandBase *const *rhs)
{
  const char *v2; // esi
  const char *v3; // eax

  v2 = (const char *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)lhs + 24))(a1: *lhs);
  v3 = (const char *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)rhs + 24))(a1: *rhs);
  if ( *v2 == 45 || *v2 == 43 )
    ++v2;
  if ( *v3 == 45 || *v3 == 43 )
    ++v3;
  return _V_stricmp(s1: v2, s2: v3) < 0;
}

//------------------------------------------------------------------------------
// Address: 0x10159A50
// Name: public: void CCvarUtilities::EnableDevCvars(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCvarUtilities::EnableDevCvars(CCvarUtilities *this)
{
  ICvar::ICVarIteratorInternal *v1; // esi
  int v2; // eax

  v1 = g_pCVar->FactoryInternalIterator(this: g_pCVar);
  v1->SetFirst(this: v1);
  while ( v1->IsValid(this: v1) )
  {
    v2 = (int)v1->Get(this: v1);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v2 + 16))(a1: v2, a2: 2);
    v1->Next(this: v1);
  }
  free(pMem: v1);
}

//------------------------------------------------------------------------------
// Address: 0x10159AB0
// Name: public: int CCvarUtilities::CountVariablesWithFlags(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCvarUtilities::CountVariablesWithFlags(CCvarUtilities *this, int flags)
{
  int v2; // ebx
  ICvar::ICVarIteratorInternal *v3; // esi
  int v4; // edi

  v2 = 0;
  v3 = g_pCVar->FactoryInternalIterator(this: g_pCVar);
  v3->SetFirst(this: v3);
  while ( v3->IsValid(this: v3) )
  {
    v4 = (int)v3->Get(this: v3);
    if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v4 + 4))(a1: v4) == 0
      && (*(unsigned __int8 (__thiscall **)(int, int))(*(_DWORD *)v4 + 8))(a1: v4, a2: flags) != 0 )
    {
      ++v2;
    }
    v3->Next(this: v3);
  }
  free(pMem: v3);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10159C10
// Name: public: int CCvarUtilities::CvarFindFlagsCompletionCallback(char const __near *,char (__near * const)[64])
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCvarUtilities::CvarFindFlagsCompletionCallback(
        CCvarUtilities *this,
        const char *partial,
        char (*commands)[64])
{
  int v3; // edi
  char *v4; // esi
  int v5; // ebx
  const char **i; // edi
  char *v7; // esi
  const char **p_desc; // edi
  const char *pSub; // [esp+Ch] [ebp-4h]
  int nSubLen; // [esp+18h] [ebp+8h]

  v3 = _V_strlen(str: partial);
  if ( v3 >= _V_strlen(str: "findflags ") )
  {
    pSub = &partial[_V_strlen(str: "findflags ")];
    v7 = (char *)commands;
    nSubLen = _V_strlen(str: pSub);
    v5 = 0;
    p_desc = &g_ConVarFlags[0].desc;
    do
    {
      if ( V_strnicmp(s1: *p_desc, s2: pSub, n: nSubLen) == 0 )
      {
        V_snprintf(pDest: v7, maxLen: 64, pFormat: "%s %s", "findflags ", *p_desc);
        _V_strlower(start: v7);
        ++v5;
        v7 += 64;
        if ( v5 >= 64 )
          break;
      }
      p_desc += 3;
    }
    while ( (int)p_desc < (int)&vec2_invalid_46.y );
  }
  else
  {
    v4 = (char *)commands;
    v5 = 0;
    for ( i = &g_ConVarFlags[0].desc; (int)i < (int)&vec2_invalid_46.y; i += 3 )
    {
      V_snprintf(pDest: v4, maxLen: 64, pFormat: "%s %s", "findflags ", *i);
      _V_strlower(start: v4);
      ++v5;
      v4 += 64;
    }
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10159CF0
// Name: public: void CCvarUtilities::CvarFindFlags_f(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCvarUtilities::CvarFindFlags_f(CCvarUtilities *this, const CCommand *args)
{
  unsigned int j; // esi
  ICvar::ICVarIteratorInternal *v3; // ebx
  const ConCommandBase *v4; // edi
  unsigned int i; // esi
  const char *argsa; // [esp+10h] [ebp+8h]

  if ( args->m_nArgc >= 2 )
  {
    if ( args->m_nArgc > 1 )
      argsa = args->m_ppArgv[1];
    else
      argsa = defaultValue;
    v3 = g_pCVar->FactoryInternalIterator(this: g_pCVar);
    v3->SetFirst(this: v3);
    while ( v3->IsValid(this: v3) )
    {
      v4 = v3->Get(this: v3);
      if ( !v4->IsFlagSet(this: (ConCommandBase *)v4, a2: 2) && !v4->IsFlagSet(this: (ConCommandBase *)v4, a2: 16) )
      {
        for ( i = 0; i < 18; ++i )
        {
          if ( v4->IsFlagSet(this: (ConCommandBase *)v4, a2: g_ConVarFlags[i].bit)
            && _V_stricmp(s1: g_ConVarFlags[i].desc, s2: argsa) == 0 )
          {
            ConVar_PrintDescription(pVar: v4);
          }
        }
      }
      v3->Next(this: v3);
    }
    free(pMem: v3);
  }
  else
  {
    ConMsg(a1: "Usage:  findflags <string>\n");
    ConMsg(a1: "Available flags to search for: \n");
    for ( j = 0; j < 18; ++j )
      ConMsg(a1: "   - %s\n", g_ConVarFlags[j].desc);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10159E20
// Name: int FindFlagsCompletionCallback(char const __near *,char (__near * const)[64])
// Source: json
//------------------------------------------------------------------------------
int __cdecl FindFlagsCompletionCallback(const char *partial, char (*commands)[64])
{
  return CCvarUtilities::CvarFindFlagsCompletionCallback(this: cv, partial, commands);
}

//------------------------------------------------------------------------------
// Address: 0x10159E40
// Name: findflags
// Source: json
//------------------------------------------------------------------------------
void __cdecl findflags(const CCommand *args)
{
  CCvarUtilities::CvarFindFlags_f(this: cv, args);
}

//------------------------------------------------------------------------------
// Address: 0x10159E60
// Name: help
// Source: json
//------------------------------------------------------------------------------
void __cdecl help(const CCommand *args)
{
  const char *v1; // esi
  const ConCommandBase *v2; // eax

  if ( args->m_nArgc == 2 )
  {
    v1 = args->m_ppArgv[1];
    v2 = g_pCVar->FindCommandBase_2(this: g_pCVar, a2: v1);
    if ( v2 != nullptr )
      ConVar_PrintDescription(pVar: v2);
    else
      ConMsg(a1: "help:  no cvar or command named %s\n", v1);
  }
  else
  {
    ConMsg(a1: "Usage:  help <cvarname>\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10159EC0
// Name: differences
// Source: json
//------------------------------------------------------------------------------
void __cdecl differences(const CCommand *args)
{
  CCvarUtilities::CvarDifferences(this: cv, args);
}

//------------------------------------------------------------------------------
// Address: 0x10159EE0
// Name: CanCheat
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CanCheat()
{
  return sv_cheats.m_pParent != nullptr && sv_cheats.m_pParent->m_Value.m_nValue != 0 || Cmd_IsRptActive();
}

//------------------------------------------------------------------------------
// Address: 0x10159F10
// Name: public: bool CCvarUtilities::IsCommand(class CCommand const __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCvarUtilities::IsCommand(CCvarUtilities *this, const CCommand *args, const int iSplitscreenSlot)
{
  int m_nArgc; // ebx
  const char *v5; // eax
  ConVar *v6; // eax
  ConVar *v7; // edi
  const char *v8; // eax
  const char *v9; // eax
  const char *v10; // eax
  const char *v11; // eax
  const char *v12; // eax
  int m_nArgv0Size; // eax
  char *v14; // esi
  int v15; // ebx
  int v16; // eax
  bool v17; // zf
  const char *v18; // eax
  char *i; // eax
  char buf[512]; // [esp+4h] [ebp-604h] BYREF
  char remaining[1024]; // [esp+204h] [ebp-404h] BYREF
  CCvarUtilities *v22; // [esp+604h] [ebp-4h]
  bool bIsQuoted_3; // [esp+617h] [ebp+Fh]

  m_nArgc = args->m_nArgc;
  v22 = this;
  if ( m_nArgc == 0 )
    return 0;
  if ( m_nArgc > 0 )
    v5 = args->m_ppArgv[0];
  else
    v5 = defaultValue;
  v6 = g_pCVar->FindVar_2(this: g_pCVar, a2: v5);
  v7 = v6;
  if ( v6 == nullptr )
    return 0;
  if ( iSplitscreenSlot > 0 && v6->IsFlagSet(this: v6, a2: 0x8000) )
  {
    if ( args->m_nArgc > 0 )
      v8 = args->m_ppArgv[0];
    else
      v8 = defaultValue;
    V_snprintf(pDest: buf, maxLen: 512, pFormat: "%s%d", v8, iSplitscreenSlot + 1);
    v7 = g_pCVar->FindVar_2(this: g_pCVar, a2: buf);
  }
  if ( v7 == nullptr || v7->IsFlagSet(this: v7, a2: 2) )
    return 0;
  if ( m_nArgc == 1 )
  {
    ConVar_PrintDescription(pVar: v7);
    return 1;
  }
  else if ( v7->IsFlagSet(this: v7, a2: 64)
         && GetBaseLocalClient()->m_nSignonState >= 2
         && GetBaseLocalClient()->m_nMaxClients > 1 )
  {
    v9 = v7->GetName(this: v7);
    ConMsg(a1: "Can't set %s in multiplayer\n", v9);
    return 1;
  }
  else if ( v7->IsFlagSet(this: v7, a2: 0x400000) && GetBaseLocalClient()->m_nSignonState >= 2 )
  {
    v10 = v7->GetName(this: v7);
    ConMsg(a1: "Can't set %s when connected\n", v10);
    return 1;
  }
  else if ( !v7->IsFlagSet(this: v7, a2: 0x4000)
         || Host_IsSinglePlayerGame()
         || CanCheat()
         || GetBaseLocalClient()->ishltv
         || demoplayer->IsPlayingBack(this: demoplayer) )
  {
    if ( v7->IsFlagSet(this: v7, a2: 0x2000)
      && !demoplayer->IsPlayingBack(this: demoplayer)
      && sv.m_State <= ss_dead
      && cmd_source == src_command
      && GetBaseLocalClient()->m_nSignonState >= 2 )
    {
      v12 = v7->GetName(this: v7);
      ConMsg(
        a1: "Can't change replicated ConVar %s from console of client, only server operator can change its value\n",
        v12);
      return 1;
    }
    else
    {
      m_nArgv0Size = args->m_nArgv0Size;
      v14 = &args->m_pArgSBuffer[m_nArgv0Size];
      if ( m_nArgv0Size == 0 )
        v14 = (char *)defaultValue;
      v15 = _V_strlen(str: v14);
      bIsQuoted_3 = *v14 == 34;
      if ( *v14 == 34 )
      {
        --v15;
        V_strncpy(pDest: remaining, pSrc: v14 + 1, maxLen: 1024);
      }
      else
      {
        v16 = args->m_nArgv0Size;
        v17 = v16 == 0;
        v18 = &args->m_pArgSBuffer[v16];
        if ( v17 )
          v18 = defaultValue;
        V_strncpy(pDest: remaining, pSrc: v18, maxLen: 1024);
      }
      for ( i = &buf[v15 + 511]; i >= remaining; *i-- = 0 )
      {
        if ( *i > 32 )
          break;
      }
      if ( bIsQuoted_3 && i >= remaining && *i == 34 )
        *i = 0;
      CCvarUtilities::SetDirect(this: v22, var: v7, value: remaining);
      return 1;
    }
  }
  else
  {
    v11 = v7->GetName(this: v7);
    ConMsg(a1: "Can't use cheat cvar %s in multiplayer, unless the server has sv_cheats set to 1.\n", v11);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015A210
// Name: private: bool CCvarUtilities::IsValidToggleCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCvarUtilities::IsValidToggleCommand(CCvarUtilities *this, const char *cmd)
{
  ConVar *v2; // esi
  const char *v4; // eax
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax

  v2 = g_pCVar->FindVar_2(this: g_pCVar, a2: cmd);
  if ( v2 == nullptr )
  {
    ConMsg(a1: "%s is not a valid cvar\n", cmd);
    return 0;
  }
  if ( v2->IsFlagSet(this: v2, a2: 2) || v2->IsFlagSet(this: v2, a2: 16) )
    return 0;
  if ( v2->IsFlagSet(this: v2, a2: 64)
    && GetBaseLocalClient()->m_nSignonState >= 2
    && GetBaseLocalClient()->m_nMaxClients > 1 )
  {
    v4 = v2->GetName(this: v2);
    ConMsg(a1: "Can't set %s in multiplayer\n", v4);
    return 0;
  }
  else if ( v2->IsFlagSet(this: v2, a2: 0x400000) && GetBaseLocalClient()->m_nSignonState >= 2 )
  {
    v5 = v2->GetName(this: v2);
    ConMsg(a1: "Can't set %s when connected\n", v5);
    return 0;
  }
  else if ( !v2->IsFlagSet(this: v2, a2: 0x4000)
         || Host_IsSinglePlayerGame()
         || CanCheat()
         || demoplayer->IsPlayingBack(this: demoplayer) )
  {
    if ( v2->IsFlagSet(this: v2, a2: 0x2000)
      && !demoplayer->IsPlayingBack(this: demoplayer)
      && sv.m_State <= ss_dead
      && cmd_source == src_command
      && GetBaseLocalClient()->m_nSignonState >= 2 )
    {
      v7 = v2->GetName(this: v2);
      ConMsg(
        a1: "Can't change replicated ConVar %s from console of client, only server operator can change its value\n",
        v7);
      return 0;
    }
    else
    {
      return 1;
    }
  }
  else
  {
    v6 = v2->GetName(this: v2);
    ConMsg(a1: "Can't use cheat cvar %s in multiplayer, unless the server has sv_cheats set to 1.\n", v6);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015A3B0
// Name: public: void CCvarUtilities::CvarToggle(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCvarUtilities::CvarToggle(CCvarUtilities *this, const CCommand *args)
{
  const CCommand *v2; // ebx
  int m_nArgc; // edi
  const char *v5; // eax
  const char *v6; // eax
  ConVar *m_pParent; // eax
  int m_nValue; // eax
  int v9; // esi
  const char **v10; // ebx
  const char *v11; // ecx
  const char *m_pszString; // eax
  int v13; // esi
  const char *v14; // esi
  ConVar *var; // [esp+Ch] [ebp-4h]

  v2 = args;
  m_nArgc = args->m_nArgc;
  if ( args->m_nArgc < 2 )
  {
    ConMsg(a1: "Usage:  toggle <cvarname> [value1] [value2] [value3]...\n");
    return;
  }
  v5 = defaultValue;
  if ( m_nArgc > 1 )
    v5 = args->m_ppArgv[1];
  var = g_pCVar->FindVar_2(this: g_pCVar, a2: v5);
  v6 = defaultValue;
  if ( args->m_nArgc > 1 )
    v6 = args->m_ppArgv[1];
  if ( CCvarUtilities::IsValidToggleCommand(this, cmd: v6) != 0 )
  {
    if ( m_nArgc == 2 )
    {
      m_pParent = var->m_pParent;
      if ( m_pParent != nullptr )
        m_nValue = m_pParent->m_Value.m_nValue;
      else
        m_nValue = 0;
      var->SetValue_2(this: &var->IConVar, a2: m_nValue == 0);
      ConVar_PrintDescription(pVar: var);
      return;
    }
    v9 = 2;
    if ( m_nArgc > 2 )
    {
      v10 = &args->m_ppArgv[2];
      do
      {
        if ( v9 < 0 || v9 >= args->m_nArgc )
          v11 = defaultValue;
        else
          v11 = *v10;
        if ( (var->m_nFlags & 0x1000) != 0 )
        {
          m_pszString = "FCVAR_NEVER_AS_STRING";
        }
        else
        {
          m_pszString = var->m_pParent->m_Value.m_pszString;
          if ( m_pszString == nullptr )
            m_pszString = defaultValue;
        }
        if ( _V_strcmp(s1: m_pszString, s2: v11) == 0 )
          break;
        ++v9;
        ++v10;
      }
      while ( v9 < m_nArgc );
      v2 = args;
    }
    v13 = v9 + 1;
    if ( v13 < m_nArgc )
    {
      if ( v13 < 0 )
        goto LABEL_31;
    }
    else
    {
      v13 = 2;
    }
    if ( v13 < v2->m_nArgc )
    {
      v14 = v2->m_ppArgv[v13];
LABEL_32:
      var->SetValue_4(this: &var->IConVar, a2: v14);
      ConVar_PrintDescription(pVar: var);
      return;
    }
LABEL_31:
    v14 = defaultValue;
    goto LABEL_32;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015A500
// Name: toggle
// Source: json
//------------------------------------------------------------------------------
void __cdecl toggle(const CCommand *args)
{
  CCvarUtilities::CvarToggle(this: cv, args);
}

//------------------------------------------------------------------------------
// Address: 0x1015B140
// Name: public: virtual bool CCvarQuery::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCvarQuery::Connect(CCvarQuery *this, void *(__cdecl *factory)(const char *, int *))
{
  void *v3; // eax

  v3 = factory(a1: "VEngineCvar007", a2: nullptr);
  if ( v3 == nullptr )
    return 0;
  (*(void (__thiscall **)(void *, CCvarQuery *))(*(_DWORD *)v3 + 112))(a1: v3, a2: this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1015B170
// Name: public: virtual void __near * CCvarQuery::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CCvarQuery *__thiscall CCvarQuery::QueryInterface(CCvarQuery *this, const char *pInterfaceName)
{
  return _V_stricmp(s1: pInterfaceName, s2: "VCvarQuery001") == 0 ? this : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1015B1A0
// Name: public: virtual bool CCvarQuery::AreConVarsLinkable(class ConVar const __near *,class ConVar const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCvarQuery::AreConVarsLinkable(CCvarQuery *this, ConVar *child, ConVar *parent)
{
  bool v3; // bl
  bool v4; // al
  const char *v6; // [esp-4h] [ebp-210h]
  const char *v7; // [esp-4h] [ebp-210h]
  const char *v8; // [esp-4h] [ebp-210h]
  const char *v9; // [esp-4h] [ebp-210h]
  const char *v10; // [esp-4h] [ebp-210h]
  const char *v11; // [esp-4h] [ebp-210h]
  const char *v12; // [esp-4h] [ebp-210h]
  char sz[512]; // [esp+Ch] [ebp-200h] BYREF

  v3 = child->IsFlagSet(this: child, a2: 0x2000);
  v4 = parent->IsFlagSet(this: parent, a2: 0x2000);
  if ( !v3 )
  {
    if ( !v4 )
    {
      if ( parent->IsFlagSet(this: parent, a2: 8) )
      {
        v10 = child->GetName(this: child);
        V_snprintf(pDest: sz, maxLen: 512, pFormat: "Parent cvar in client.dll not allowed (%s)\n", v10);
        goto LABEL_22;
      }
      if ( parent->IsFlagSet(this: parent, a2: 4) )
      {
        v11 = child->GetName(this: child);
        V_snprintf(pDest: sz, maxLen: 512, pFormat: "Parent cvar in server.dll not allowed (%s)\n", v11);
        goto LABEL_22;
      }
      return 1;
    }
LABEL_21:
    v12 = child->GetName(this: child);
    V_snprintf(
      pDest: sz,
      maxLen: 512,
      pFormat: "Both ConVars must be marked FCVAR_REPLICATED for linkage to work (%s)\n",
      v12);
    goto LABEL_22;
  }
  if ( !v4 )
    goto LABEL_21;
  if ( child->IsFlagSet(this: child, a2: 32) || parent->IsFlagSet(this: parent, a2: 32) )
  {
    v9 = child->GetName(this: child);
    V_snprintf(pDest: sz, maxLen: 512, pFormat: "FCVAR_REPLICATED can't also be FCVAR_PROTECTED (%s)\n", v9);
    goto LABEL_22;
  }
  if ( child->IsCommand(this: child) || parent->IsCommand(this: parent) )
  {
    v8 = child->GetName(this: child);
    V_snprintf(pDest: sz, maxLen: 512, pFormat: "FCVAR_REPLICATED not valid on ConCommands (%s)\n", v8);
    goto LABEL_22;
  }
  if ( !child->IsFlagSet(this: child, a2: 4) || parent->IsFlagSet(this: parent, a2: 8) )
  {
    if ( child->IsFlagSet(this: child, a2: 8) && !parent->IsFlagSet(this: parent, a2: 4) )
    {
      v7 = child->GetName(this: child);
      V_snprintf(
        pDest: sz,
        maxLen: 512,
        pFormat: "For FCVAR_REPLICATED, ConVar must be defined in client and game .dlls (%s)\n",
        v7);
      goto LABEL_22;
    }
    return 1;
  }
  v6 = child->GetName(this: child);
  V_snprintf(
    pDest: sz,
    maxLen: 512,
    pFormat: "For FCVAR_REPLICATED, ConVar must be defined in client and game .dlls (%s)\n",
    v6);
LABEL_22:
  ConMsg(a1: sz);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1015C460
// Name: ConVarNetworkChangeCallback
// Source: json
//------------------------------------------------------------------------------
void __usercall ConVarNetworkChangeCallback(int a1@<esi>, IConVar *pConVar, const char *pOldValue, float flOldValue)
{
  const char *v4; // eax
  CClientState *LocalClient; // eax
  IGameEvent *v6; // esi
  int v7; // eax
  bool v8; // al
  IGameEvent_vtbl *v9; // edx
  const ConVar *v10; // eax
  const char *v12; // [esp+0h] [ebp-30h]
  NET_SetConVar convar; // [esp+4h] [ebp-2Ch] BYREF
  ConVarRef var; // [esp+28h] [ebp-8h] BYREF

  ConVarRef::ConVarRef(this: &var, pConVar);
  if ( pOldValue != nullptr )
  {
    if ( _V_strcmp(s1: var.m_pConVarState->m_Value.m_pszString, s2: pOldValue) == 0 )
      return;
  }
  else if ( var.m_pConVarState->m_Value.m_fValue == flOldValue )
  {
    return;
  }
  if ( var.m_pConVar->IsFlagSet(this: var.m_pConVar, a2: 512) && GetLocalClient(nSlot: -1)->m_nSignonState >= 2 )
  {
    v4 = (const char *)((int (__thiscall *)(IConVar *, char *))var.m_pConVar->GetBaseName)(
                         a1: var.m_pConVar,
                         a2: var.m_pConVarState->m_Value.m_pszString);
    NET_SetConVar::NET_SetConVar(this: &convar, name: v4, value: v12);
    LocalClient = GetLocalClient(nSlot: -1);
    ((void (__thiscall *)(INetChannel *, NET_SetConVar *, _DWORD))LocalClient->m_NetChannel->SendNetMsg)(
      a1: LocalClient->m_NetChannel,
      a2: &convar,
      a3: 0);
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&convar.m_ConVars);
  }
  if ( var.m_pConVar->IsFlagSet(this: var.m_pConVar, a2: 256) )
  {
    v6 = g_GameEventManager->CreateEventA(this: g_GameEventManager, a2: "server_cvar", a3: 0, a4: 0);
    if ( v6 != nullptr )
    {
      v7 = ((int (__thiscall *)(IConVar *, int))var.m_pConVar->GetName)(a1: var.m_pConVar, a2: a1);
      v6->SetString(this: v6, a2: "cvarname", a3: (const char *)v7);
      v8 = var.m_pConVar->IsFlagSet(this: var.m_pConVar, a2: 32);
      v9 = v6->__vftable;
      if ( v8 )
        v9->SetString(this: v6, a2: "cvarvalue", a3: "***PROTECTED***");
      else
        v9->SetString(this: v6, a2: "cvarvalue", a3: var.m_pConVarState->m_Value.m_pszString);
      ((void (__thiscall *)(CGameEventManager *, IGameEvent *))g_GameEventManager->FireEvent)(
        a1: g_GameEventManager,
        a2: v6);
    }
  }
  if ( var.m_pConVar->IsFlagSet(this: var.m_pConVar, a2: 0x2000) && sv.m_State >= ss_active )
  {
    if ( pConVar != nullptr )
      v10 = (const ConVar *)&pConVar[-6];
    else
      v10 = nullptr;
    SV_ReplicateConVarChange(var: v10, newValue: var.m_pConVarState->m_Value.m_pszString);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015C5E0
// Name: public: virtual enum InitReturnVal_t CCvarQuery::Init(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCvarQuery::Init(CCvarQuery *this)
{
  if ( !this->m_bCallbackInstalled )
  {
    this->m_bCallbackInstalled = true;
    g_pCVar->InstallGlobalChangeCallback(
      this: g_pCVar,
      a2: (void (__cdecl *)(IConVar *, const char *, float))ConVarNetworkChangeCallback);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1015C610
// Name: public: virtual void CCvarQuery::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCvarQuery::Shutdown(CCvarQuery *this)
{
  g_pCVar->RemoveGlobalChangeCallback(
    this: g_pCVar,
    a2: (void (__cdecl *)(IConVar *, const char *, float))ConVarNetworkChangeCallback);
  this->m_bCallbackInstalled = false;
}

//------------------------------------------------------------------------------
// Address: 0x1015C630
// Name: void InstallConVarHook(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InstallConVarHook()
{
  if ( !s_CvarQuery.m_bCallbackInstalled )
  {
    s_CvarQuery.m_bCallbackInstalled = true;
    g_pCVar->InstallGlobalChangeCallback(
      this: g_pCVar,
      a2: (void (__cdecl *)(IConVar *, const char *, float))ConVarNetworkChangeCallback);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015C6D0
// Name: public: void CCvarUtilities::WriteVariables(class CUtlBuffer __near *,int,bool,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCvarUtilities::WriteVariables(
        CCvarUtilities *this,
        CUtlBuffer *buff,
        int iSplitscreenSlot,
        bool bSlotRequired,
        CUtlMemory<S3RGBA,int> *pConvarsListVoid)
{
  ICvar::ICVarIteratorInternal *(__thiscall *FactoryInternalIterator)(ICvar *); // edx
  ICvar::ICVarIteratorInternal *m_pIter; // edi
  void (__thiscall *SetFirst)(ICvar::ICVarIteratorInternal *); // edx
  ConVar *v8; // esi
  char v9; // bl
  _DWORD *v10; // eax
  int v11; // eax
  UtlRBTreeNode_t<ConVar *,int> *m_pMemory; // ecx
  int v13; // edx
  int v14; // esi
  int v15; // edx
  int v16; // eax
  ConVar *m_Data; // ebx
  int v18; // eax
  const char *v19; // edi
  const char *m_pszString; // eax
  const char *v21; // eax
  S3RGBA *v22; // edi
  int m_nAllocationCount; // eax
  S3RGBA *v24; // ecx
  int v25; // eax
  ConVar **v26; // eax
  CUtlRBTree<ConVar *,int,bool (__cdecl*)(ConVar * const &,ConVar * const &),CUtlMemory<UtlRBTreeNode_t<ConVar *,int>,int> > sorted; // [esp+Ch] [ebp-34h] BYREF
  int parent; // [esp+30h] [ebp-10h] BYREF
  ICvar::Iterator iter; // [esp+34h] [ebp-Ch]
  ConVar *cv; // [esp+38h] [ebp-8h] BYREF
  bool leftchild; // [esp+3Fh] [ebp-1h] BYREF
  int i; // [esp+50h] [ebp+10h]

  FactoryInternalIterator = g_pCVar->FactoryInternalIterator;
  sorted.m_LessFunc = CVarSortFunc;
  memset(&sorted.m_Elements, 0, sizeof(sorted.m_Elements));
  sorted.m_Root = -1;
  sorted.m_NumElements = 0;
  sorted.m_FirstFree = -1;
  sorted.m_LastAlloc.index = -1;
  sorted.m_pElements = nullptr;
  m_pIter = FactoryInternalIterator(this: g_pCVar);
  SetFirst = m_pIter->SetFirst;
  iter.m_pIter = m_pIter;
  SetFirst(this: m_pIter);
  while ( m_pIter->IsValid(this: m_pIter) )
  {
    v8 = (ConVar *)m_pIter->Get(this: m_pIter);
    if ( v8->IsCommand(this: v8) )
      goto LABEL_22;
    cv = v8;
    if ( !v8->IsFlagSet(this: v8, a2: 128) )
      goto LABEL_22;
    if ( iSplitscreenSlot < 0 )
      goto LABEL_14;
    v9 = 0;
    if ( cv->IsFlagSet(this: cv, a2: 0x8000) )
    {
      if ( iSplitscreenSlot != 0 )
        goto LABEL_21;
      v9 = 1;
    }
    if ( !cv->IsFlagSet(this: cv, a2: 0x40000) )
      goto LABEL_12;
    v10 = __RTDynamicCast(
            inptr: cv,
            VfDelta: 0,
            SrcType: &ConVar `RTTI Type Descriptor',
            TargetType: &CSplitScreenAddedConVar `RTTI Type Descriptor',
            isReference: 0);
    if ( v10 == nullptr || (*(int (__thiscall **)(_DWORD *))(v10[6] + 28))(a1: v10 + 6) == iSplitscreenSlot )
    {
      v9 = 1;
LABEL_12:
      if ( bSlotRequired == v9 )
      {
        m_pIter = iter.m_pIter;
LABEL_14:
        parent = -1;
        leftchild = false;
        CUtlRBTree<ConVar *,int,bool (__cdecl *)(ConVar * const &,ConVar * const &),CUtlMemory<UtlRBTreeNode_t<ConVar *,int>,int>>::FindInsertionPosition(
          this: &sorted,
          insert: &cv,
          &parent,
          &leftchild);
        v11 = CUtlRBTree<msurface2_t *,int,bool (__cdecl *)(msurface2_t * const &,msurface2_t * const &),CUtlMemory<UtlRBTreeNode_t<msurface2_t *,int>,int>>::NewNode(this: (CUtlRBTree<char const *,int,bool (__cdecl*)(char const * const &,char const * const &),CUtlMemory<UtlRBTreeNode_t<char const *,int>,int> > *)&sorted);
        m_pMemory = sorted.m_Elements.m_pMemory;
        v13 = parent;
        v14 = v11;
        sorted.m_Elements.m_pMemory[v14].m_Parent = parent;
        m_pMemory[v14].m_Right = -1;
        m_pMemory[v14].m_Left = -1;
        m_pMemory[v14].m_Tag = 0;
        if ( v13 == -1 )
        {
          sorted.m_Root = v11;
        }
        else
        {
          v15 = v13;
          if ( leftchild )
            m_pMemory[v15].m_Left = v11;
          else
            m_pMemory[v15].m_Right = v11;
        }
        CUtlRBTree<ConVar *,int,bool (__cdecl *)(ConVar * const &,ConVar * const &),CUtlMemory<UtlRBTreeNode_t<ConVar *,int>,int>>::InsertRebalance(
          this: &sorted,
          elem: v11);
        ++sorted.m_NumElements;
        if ( &sorted.m_Elements.m_pMemory[v14] != (UtlRBTreeNode_t<ConVar *,int> *)-16 )
          sorted.m_Elements.m_pMemory[v14].m_Data = cv;
        goto LABEL_22;
      }
    }
LABEL_21:
    m_pIter = iter.m_pIter;
LABEL_22:
    m_pIter->Next(this: m_pIter);
  }
  v16 = CUtlRBTree<ConVar *,int,bool (__cdecl *)(ConVar * const &,ConVar * const &),CUtlMemory<UtlRBTreeNode_t<ConVar *,int>,int>>::FirstInorder(this: &sorted);
  i = v16;
  if ( v16 != -1 )
  {
    while ( 1 )
    {
      m_Data = sorted.m_Elements.m_pMemory[v16].m_Data;
      v18 = (int)(iSplitscreenSlot < 0 ? m_Data->GetName(this: m_Data) : m_Data->GetBaseName(this: &m_Data->IConVar));
      v19 = (const char *)v18;
      if ( (m_Data->m_nFlags & 0x1000) != 0 )
      {
        m_pszString = "FCVAR_NEVER_AS_STRING";
      }
      else
      {
        m_pszString = m_Data->m_pParent->m_Value.m_pszString;
        if ( m_pszString == nullptr )
          m_pszString = defaultValue;
      }
      _DevMsg(a1: 2, a2: "%s \"%s\"\n", v19, m_pszString);
      if ( buff != nullptr )
      {
        if ( (m_Data->m_nFlags & 0x1000) != 0 )
        {
          v21 = "FCVAR_NEVER_AS_STRING";
        }
        else
        {
          v21 = m_Data->m_pParent->m_Value.m_pszString;
          if ( v21 == nullptr )
            v21 = defaultValue;
        }
        CUtlBuffer::Printf(this: buff, pFmt: "%s \"%s\"\n", v19, v21);
      }
      if ( pConvarsListVoid != nullptr )
      {
        v22 = pConvarsListVoid[1].m_pMemory;
        m_nAllocationCount = pConvarsListVoid->m_nAllocationCount;
        if ( (int)&v22->g > m_nAllocationCount )
          CUtlMemory<INetMessage *,int>::Grow(this: pConvarsListVoid, num: (int)(&v22->g - m_nAllocationCount));
        ++pConvarsListVoid[1].m_pMemory;
        v24 = pConvarsListVoid->m_pMemory;
        v25 = (char *)pConvarsListVoid[1].m_pMemory - (char *)v22 - 1;
        pConvarsListVoid[1].m_nAllocationCount = (int)pConvarsListVoid->m_pMemory;
        if ( v25 > 0 )
          _V_memmove(dest: &v24[(_DWORD)v22 + 1], src: &v24[(_DWORD)v22], count: 4 * v25);
        v26 = (ConVar **)&pConvarsListVoid->m_pMemory[(_DWORD)v22];
        if ( v26 != nullptr )
          *v26 = m_Data;
      }
      i = CUtlRBTree<ConVar *,int,bool (__cdecl *)(ConVar * const &,ConVar * const &),CUtlMemory<UtlRBTreeNode_t<ConVar *,int>,int>>::NextInorder(
            this: &sorted,
            i);
      if ( i == -1 )
        break;
      v16 = i;
    }
    m_pIter = iter.m_pIter;
  }
  free(pMem: m_pIter);
  CUtlRBTree<ConVar *,int,bool (__cdecl *)(ConVar * const &,ConVar * const &),CUtlMemory<UtlRBTreeNode_t<ConVar *,int>,int>>::RemoveAll(this: &sorted);
  if ( sorted.m_Elements.m_nGrowSize >= 0 && sorted.m_Elements.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sorted.m_Elements.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1015C9E0
// Name: public: void CCvarUtilities::CvarList(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCvarUtilities::CvarList(CCvarUtilities *this, ConCommandBase *args)
{
  const CCommand *v2; // esi
  int v3; // ebx
  const char *v4; // edi
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // esi
  ICvar::ICVarIteratorInternal *(__thiscall *FactoryInternalIterator)(ICvar *); // eax
  ICvar::ICVarIteratorInternal *v9; // esi
  const char *v10; // eax
  int v11; // ebx
  ConCommand *m_Data; // edi
  int v13; // [esp-4h] [ebp-13Ch]
  char fn[256]; // [esp+Ch] [ebp-12Ch] BYREF
  CUtlRBTree<ConCommandBase const *,unsigned short,bool (__cdecl*)(ConCommandBase const * const &,ConCommandBase const * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase const *,unsigned short>,unsigned short> > sorted; // [esp+10Ch] [ebp-2Ch] BYREF
  int ipLen; // [esp+128h] [ebp-10h]
  const char *partial; // [esp+12Ch] [ebp-Ch]
  BOOL bLogging; // [esp+130h] [ebp-8h]
  void *f; // [esp+134h] [ebp-4h] BYREF

  v2 = (const CCommand *)args;
  v3 = (int)args->__vftable;
  v4 = nullptr;
  partial = nullptr;
  ipLen = 0;
  f = nullptr;
  LOBYTE(bLogging) = 0;
  if ( v3 == 2 && V_strcasecmp(s1: (const char *)args[43].m_pNext, s2: "?") == 0 )
  {
    ConMsg(a1: "cvarlist:  [log logfile] [ partial ]\n");
    return;
  }
  v5 = defaultValue;
  if ( v2->m_nArgc > 1 )
    v5 = v2->m_ppArgv[1];
  if ( V_strcasecmp(s1: v5, s2: "log") != 0 || v3 < 3 )
  {
    if ( v2->m_nArgc > 1 )
      v7 = v2->m_ppArgv[1];
    else
      v7 = defaultValue;
    goto LABEL_19;
  }
  v6 = defaultValue;
  if ( v2->m_nArgc > 2 )
    v6 = v2->m_ppArgv[2];
  V_snprintf(pDest: fn, maxLen: 256, pFormat: "%s", v6);
  f = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: fn, a3: "wb", a4: 0);
  if ( f == nullptr )
  {
    ConMsg(a1: "Couldn't open '%s' for writing!\n", fn);
    return;
  }
  LOBYTE(bLogging) = 1;
  if ( v3 == 4 )
  {
    if ( v2->m_nArgc > 3 )
      v7 = v2->m_ppArgv[3];
    else
      v7 = defaultValue;
LABEL_19:
    partial = v7;
    v4 = v7;
    ipLen = _V_strlen(str: v7);
  }
  ConMsg(a1: "cvar list\n--------------\n");
  FactoryInternalIterator = g_pCVar->FactoryInternalIterator;
  sorted.m_LessFunc = ConCommandBaseLessFunc;
  memset(&sorted.m_Elements, 0, sizeof(sorted.m_Elements));
  *(_DWORD *)&sorted.m_Root = 0xFFFF;
  *(_DWORD *)&sorted.m_FirstFree = -1;
  sorted.m_pElements = nullptr;
  v9 = FactoryInternalIterator(this: g_pCVar);
  v9->SetFirst(this: v9);
  while ( v9->IsValid(this: v9) )
  {
    args = v9->Get(this: v9);
    if ( !args->IsFlagSet(this: args, a2: 2) && !args->IsFlagSet(this: args, a2: 16) )
    {
      if ( v4 == nullptr || (v13 = ipLen, v10 = args->GetName(this: args), V_strncasecmp(s1: v10, s2: v4, n: v13) == 0) )
        CUtlRBTree<ConCommandBase const *,unsigned short,bool (__cdecl *)(ConCommandBase const * const &,ConCommandBase const * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase const *,unsigned short>,unsigned short>>::Insert(
          this: &sorted,
          insert: (const ConCommandBase *const *)&args);
    }
    v9->Next(this: v9);
  }
  if ( bLogging )
    PrintListHeader(&f);
  v11 = (unsigned __int16)CUtlRBTree<ConCommandBase const *,unsigned short,bool (__cdecl *)(ConCommandBase const * const &,ConCommandBase const * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase const *,unsigned short>,unsigned short>>::FirstInorder(this: &sorted);
  if ( v11 != 0xFFFF )
  {
    do
    {
      m_Data = (ConCommand *)sorted.m_Elements.m_pMemory[(unsigned __int16)v11].m_Data;
      if ( m_Data->IsCommand(this: m_Data) )
        PrintCommand(cmd: m_Data, logging: bLogging, &f);
      else
        PrintCvar(var: (ConVar *)m_Data, logging: bLogging, &f);
      v11 = (unsigned __int16)CUtlRBTree<ConCommandBase const *,unsigned short,bool (__cdecl *)(ConCommandBase const * const &,ConCommandBase const * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase const *,unsigned short>,unsigned short>>::NextInorder(
                                this: &sorted,
                                i: v11);
    }
    while ( v11 != 0xFFFF );
    v4 = partial;
  }
  if ( v4 != nullptr && *v4 != 0 )
    ConMsg(a1: "--------------\n%3i convars/concommands for [%s]\n", sorted.m_NumElements, v4);
  else
    ConMsg(a1: "--------------\n%3i total convars/concommands\n", sorted.m_NumElements);
  if ( bLogging )
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: f);
  free(pMem: v9);
  CUtlRBTree<ConCommandBase const *,unsigned short,bool (__cdecl *)(ConCommandBase const * const &,ConCommandBase const * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase const *,unsigned short>,unsigned short>>::RemoveAll(this: &sorted);
  if ( sorted.m_Elements.m_nGrowSize >= 0 && sorted.m_Elements.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sorted.m_Elements.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1015CCF0
// Name: cvarlist
// Source: json
//------------------------------------------------------------------------------
void __cdecl cvarlist(ConCommandBase *args)
{
  CCvarUtilities::CvarList(this: cv, args);
}

} // namespace engine_xlsp
