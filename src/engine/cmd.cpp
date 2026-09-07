// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/cmd.cpp
// Functions: 30
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1014A740
// Name: void Cmd_SetRptActive(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Cmd_SetRptActive(bool bActive)
{
  g_bRPTActive = bActive;
}

//------------------------------------------------------------------------------
// Address: 0x1014A750
// Name: bool Cmd_IsRptActive(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl Cmd_IsRptActive()
{
  return g_bRPTActive;
}

//------------------------------------------------------------------------------
// Address: 0x1014A760
// Name: void Cbuf_Init(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Cbuf_Init()
{
  CCommandBuffer *v0; // esi

  v0 = s_CommandBuffer;
  do
    CCommandBuffer::SetWaitDelayTime(this: v0++, nTickDelay: 1);
  while ( (int)v0 < (int)&s_CommandBufferMutex );
}

//------------------------------------------------------------------------------
// Address: 0x1014A780
// Name: void Cbuf_Clear(enum ECommandTarget_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Cbuf_Clear(ECommandTarget_t eTarget)
{
  CCommandBuffer::SetWaitDelayTime(this: &s_CommandBuffer[eTarget], nTickDelay: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1014A7A0
// Name: Cmd_TranslateFileAssociation
// Source: json
//------------------------------------------------------------------------------
char *__usercall Cmd_TranslateFileAssociation@<eax>(const char *param@<eax>)
{
  char *result; // eax
  const char *v2; // esi
  FileAssociationInfo *v3; // ebx
  int *v4; // edi
  int v5; // esi
  char *v6; // eax
  char temp[512]; // [esp+4h] [ebp-208h] BYREF
  const char *extension; // [esp+204h] [ebp-8h]
  char *retval; // [esp+208h] [ebp-4h]

  retval = nullptr;
  V_strncpy(pDest: temp, pSrc: param, maxLen: 512);
  V_FixSlashes(pname: temp, separator: 92);
  _V_strlower(start: temp);
  result = (char *)V_GetFileExtension(path: temp);
  v2 = result;
  extension = result;
  if ( result != nullptr )
  {
    v3 = g_FileAssociations;
    while ( 1 )
    {
      if ( _V_strcmp(s1: v2, s2: v3->extension + 1) == 0 )
      {
        v4 = (int *)_CommandLine();
        v5 = *v4;
        v6 = va(format: "+%s", v3->command_to_issue);
        if ( (*(int (__thiscall **)(int *, char *))(v5 + 40))(a1: v4, a2: v6) == 0 )
        {
          V_strncpy(pDest: sz_0, pSrc: temp, maxLen: 512);
          V_FileBase(in: sz_0, out: temp, maxlen: 512);
          V_snprintf(pDest: sz_0, maxLen: 512, pFormat: "%s %s", v3->command_to_issue, temp);
          return sz_0;
        }
        v2 = extension;
      }
      if ( (int)++v3 >= (int)&cmd_clientslot )
        return retval;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1014A8B0
// Name: bool IsValidFileExtension(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsValidFileExtension(const char *pszFilename)
{
  return pszFilename != nullptr
      && _V_strstr(s1: pszFilename, search: ".exe") == nullptr
      && _V_strstr(s1: pszFilename, search: ".vbs") == nullptr
      && _V_strstr(s1: pszFilename, search: ".com") == nullptr
      && _V_strstr(s1: pszFilename, search: ".bat") == nullptr
      && _V_strstr(s1: pszFilename, search: ".dll") == nullptr
      && _V_strstr(s1: pszFilename, search: ".ini") == nullptr
      && _V_strstr(s1: pszFilename, search: ".gcf") == nullptr
      && _V_strstr(s1: pszFilename, search: ".sys") == nullptr
      && _V_strstr(s1: pszFilename, search: ".blob") == nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1014A980
// Name: echo
// Source: json
//------------------------------------------------------------------------------
void __cdecl echo(const CCommand *args)
{
  const CCommand *v1; // eax
  int m_nArgc; // edi
  int v3; // esi
  const char **v4; // ebx
  const char *v5; // eax

  v1 = args;
  m_nArgc = args->m_nArgc;
  v3 = 1;
  if ( args->m_nArgc > 1 )
  {
    v4 = &args->m_ppArgv[1];
    while ( 1 )
    {
      v5 = v3 < 0 || v3 >= v1->m_nArgc ? defaultValue : *v4;
      ConMsg(a1: "%s ", v5);
      ++v3;
      ++v4;
      if ( v3 >= m_nArgc )
        break;
      v1 = args;
    }
  }
  ConMsg(a1: "\n");
}

//------------------------------------------------------------------------------
// Address: 0x1014A9E0
// Name: alias
// Source: json
//------------------------------------------------------------------------------
void __cdecl alias(const CCommand *args)
{
  int m_nArgc; // edi
  cmdalias_t *i; // esi
  int v3; // esi
  const char **v4; // ebx
  const char *v5; // eax
  cmdalias_t *v6; // esi
  char cmd[1024]; // [esp+Ch] [ebp-404h] BYREF
  char *str; // [esp+40Ch] [ebp-4h]

  m_nArgc = args->m_nArgc;
  if ( args->m_nArgc == 1 )
  {
    ConMsg(a1: "Current alias commands:\n");
    for ( i = cmd_alias; i != nullptr; i = i->next )
      ConMsg(a1: "%s : %s\n", i->name, i->value);
    return;
  }
  if ( args->m_nArgc > 1 )
    str = (char *)args->m_ppArgv[1];
  else
    str = (char *)defaultValue;
  if ( _V_strlen(str) >= 32 )
  {
    ConMsg(a1: "Alias name is too long\n");
    return;
  }
  v3 = 2;
  cmd[0] = 0;
  if ( m_nArgc > 2 )
  {
    v4 = &args->m_ppArgv[2];
    do
    {
      if ( v3 < 0 || v3 >= args->m_nArgc )
        v5 = defaultValue;
      else
        v5 = *v4;
      V_strncat(pDest: cmd, pSrc: v5, destBufferSize: 0x400u, max_chars_to_copy: -1);
      if ( v3 != m_nArgc )
        V_strncat(pDest: cmd, pSrc: " ", destBufferSize: 0x400u, max_chars_to_copy: -1);
      ++v3;
      ++v4;
    }
    while ( v3 < m_nArgc );
  }
  V_strncat(pDest: cmd, pSrc: "\n", destBufferSize: 0x400u, max_chars_to_copy: -1);
  v6 = cmd_alias;
  if ( cmd_alias == nullptr )
  {
LABEL_22:
    v6 = (cmdalias_t *)MemAlloc_Alloc(nSize: 0x28u);
    v6->next = cmd_alias;
    cmd_alias = v6;
LABEL_23:
    V_strncpy(pDest: v6->name, pSrc: str, maxLen: 32);
    v6->value = COM_StringCopy(in: cmd);
    return;
  }
  while ( _V_strcmp(s1: str, s2: v6->name) != 0 )
  {
    v6 = v6->next;
    if ( v6 == nullptr )
      goto LABEL_22;
  }
  if ( _V_strcmp(s1: v6->value, s2: cmd) != 0 )
  {
    free(pMem: v6->value);
    goto LABEL_23;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014AB80
// Name: g_exec_CompletionFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl g_exec_CompletionFunc(char *partial, char (*commands)[64])
{
  if ( (_S2_10 & 1) == 0 )
  {
    _S2_10 |= 1u;
    execComplete.m_pszCommandName = "exec";
    execComplete.m_pszSubDir = "cfg";
    execComplete.m_pszExtension = "cfg";
  }
  return CBaseAutoCompleteFileList::AutoCompletionFunc(this: &execComplete, partial, commands);
}

//------------------------------------------------------------------------------
// Address: 0x1014ABD0
// Name: g_execifexists_CompletionFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl g_execifexists_CompletionFunc(char *partial, char (*commands)[64])
{
  if ( (_S3_3 & 1) == 0 )
  {
    _S3_3 |= 1u;
    execifexistsComplete.m_pszCommandName = "execifexists";
    execifexistsComplete.m_pszSubDir = "cfg";
    execifexistsComplete.m_pszExtension = "cfg";
  }
  return CBaseAutoCompleteFileList::AutoCompletionFunc(this: &execifexistsComplete, partial, commands);
}

//------------------------------------------------------------------------------
// Address: 0x1014AC20
// Name: void Cmd_Init(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Cmd_Init()
{
  Sys_CreateFileAssociations(count: 3, list: g_FileAssociations);
}

//------------------------------------------------------------------------------
// Address: 0x1014AC30
// Name: void Cmd_Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Cmd_Shutdown()
{
  cmdalias_t *v0; // eax
  cmdalias_t *next; // esi

  v0 = cmd_alias;
  if ( cmd_alias != nullptr )
  {
    do
    {
      next = v0->next;
      free(pMem: v0->value);
      free(pMem: cmd_alias);
      v0 = next;
      cmd_alias = next;
    }
    while ( next != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014AC70
// Name: void Cmd_Dispatch(class ConCommandBase const __near *,class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Cmd_Dispatch(ConCommandBase *pCommand, const CCommand *command)
{
  pCommand->__vftable[1].IsFlagSet(this: pCommand, a2: (int)command);
}

//------------------------------------------------------------------------------
// Address: 0x1014AC90
// Name: void Cmd_ForwardToServer(class CCommand const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Cmd_ForwardToServer(const CCommand *args)
{
  bool v1; // cc
  const char *v2; // eax
  const char *v3; // eax
  int m_nArgv0Size; // eax
  bool v5; // zf
  const char *v6; // eax
  CClientState *LocalClient; // eax
  char str[1024]; // [esp+0h] [ebp-400h] BYREF

  if ( !demoplayer->IsPlayingBack(this: demoplayer) )
  {
    v1 = args->m_nArgc <= 0;
    str[0] = 0;
    v2 = defaultValue;
    if ( !v1 )
      v2 = args->m_ppArgv[0];
    if ( V_strcasecmp(s1: v2, s2: "cmd") != 0 )
    {
      v3 = defaultValue;
      if ( args->m_nArgc > 0 )
        v3 = args->m_ppArgv[0];
      V_strncat(pDest: str, pSrc: v3, destBufferSize: 0x400u, max_chars_to_copy: -1);
      V_strncat(pDest: str, pSrc: " ", destBufferSize: 0x400u, max_chars_to_copy: -1);
    }
    if ( args->m_nArgc > 1 )
    {
      m_nArgv0Size = args->m_nArgv0Size;
      v5 = m_nArgv0Size == 0;
      v6 = &args->m_pArgSBuffer[m_nArgv0Size];
      if ( v5 )
        v6 = defaultValue;
      V_strncat(pDest: str, pSrc: v6, destBufferSize: 0x400u, max_chars_to_copy: -1);
    }
    LocalClient = GetLocalClient(nSlot: -1);
    CBaseClientState::SendStringCmd(this: LocalClient, command: str);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014AD70
// Name: void Cbuf_AddText(enum ECommandTarget_t,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Cbuf_AddText(ECommandTarget_t eTarget, char *pText, int nTickDelay)
{
  DWORD CurrentThreadId; // ecx

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != s_CommandBufferMutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&s_CommandBufferMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &s_CommandBufferMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++s_CommandBufferMutex.m_depth;
  }
  if ( CCommandBuffer::AddText(this: &s_CommandBuffer[eTarget], pText, nTickDelay) == 0 )
    ConMsg(a1: "Cbuf_AddText: buffer overflow\n");
  if ( --s_CommandBufferMutex.m_depth == 0 )
    _InterlockedExchange((volatile __int32 *)&s_CommandBufferMutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x1014AE00
// Name: void Cbuf_InsertText(enum ECommandTarget_t,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Cbuf_InsertText(ECommandTarget_t eTarget, char *pText, const char *nTickDelay)
{
  DWORD CurrentThreadId; // ecx

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != s_CommandBufferMutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&s_CommandBufferMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &s_CommandBufferMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++s_CommandBufferMutex.m_depth;
  }
  Cbuf_AddText(eTarget, pText, (int)nTickDelay);
  if ( --s_CommandBufferMutex.m_depth == 0 )
    _InterlockedExchange((volatile __int32 *)&s_CommandBufferMutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x1014AE70
// Name: cmd
// Source: json
//------------------------------------------------------------------------------
void __cdecl cmd(const CCommand *args)
{
  Cmd_ForwardToServer(args);
}

//------------------------------------------------------------------------------
// Address: 0x1014AE90
// Name: BindToggle
// Source: json
//------------------------------------------------------------------------------
void __cdecl BindToggle(const CCommand *args)
{
  const char *v1; // eax
  char newCmd[1024]; // [esp+0h] [ebp-400h] BYREF

  if ( args->m_nArgc > 2 )
  {
    v1 = defaultValue;
    if ( args->m_nArgc > 1 )
      v1 = args->m_ppArgv[1];
    V_snprintf(pDest: newCmd, maxLen: 1024, pFormat: "bind %s \"incrementvar %s 0 1 1\"\n", v1, args->m_ppArgv[2]);
    Cbuf_InsertText(eTarget: CBUF_FIRST_PLAYER, pText: newCmd, nTickDelay: nullptr);
  }
  else
  {
    ConMsg(a1: "BindToggle <key> <cvar>: invalid syntax specified\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014AF00
// Name: FindAndRemoveExecutionMarker
// Source: json
//------------------------------------------------------------------------------
char __thiscall FindAndRemoveExecutionMarker(void *iCode)
{
  int m_Size; // edx
  int v2; // eax

  m_Size = g_ExecutionMarkers.m_Size;
  v2 = 0;
  if ( g_ExecutionMarkers.m_Size <= 0 )
    return 0;
  while ( (void *)g_ExecutionMarkers.m_Memory.m_pMemory[v2] != iCode )
  {
    if ( ++v2 >= g_ExecutionMarkers.m_Size )
      return 0;
  }
  if ( v2 == -1 )
    return 0;
  if ( g_ExecutionMarkers.m_Size - v2 - 1 > 0 )
  {
    _V_memmove(
      dest: &g_ExecutionMarkers.m_Memory.m_pMemory[v2],
      src: &g_ExecutionMarkers.m_Memory.m_pMemory[v2 + 1],
      count: 4 * (g_ExecutionMarkers.m_Size - v2 - 1));
    m_Size = g_ExecutionMarkers.m_Size;
  }
  g_ExecutionMarkers.m_Size = m_Size - 1;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1014AF60
// Name: HandleExecutionMarker
// Source: json
//------------------------------------------------------------------------------
void __usercall HandleExecutionMarker(char *pCommand@<eax>, const char *pMarkerCode@<ecx>)
{
  char v2; // bl
  void *v3; // eax

  v2 = *pCommand;
  v3 = (void *)atoi(nptr: pMarkerCode);
  if ( FindAndRemoveExecutionMarker(iCode: v3) != 0 )
  {
    switch ( v2 )
    {
      case 'a':
        ++g_iFilterCommandsByServerCanExecute;
        break;
      case 'b':
        --g_iFilterCommandsByServerCanExecute;
        break;
      case 'c':
        ++g_iFilterCommandsByClientCmdCanExecute;
        break;
      case 'd':
        --g_iFilterCommandsByClientCmdCanExecute;
        break;
      default:
        break;
    }
  }
  else if ( ++cnt < 3 )
  {
    _Warning(a1: "Invalid execution marker code.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014AFD0
// Name: stuffcmds
// Source: json
//------------------------------------------------------------------------------
void __cdecl stuffcmds(const CCommand *args)
{
  int v1; // edi
  int v2; // eax
  int v3; // eax
  _BYTE *v4; // eax
  _BYTE *v5; // esi
  char v6; // al
  int v7; // eax
  int v8; // eax
  const char *v9; // eax
  char *v10; // esi
  char *v11; // eax
  int v12; // eax
  const char *v13; // eax
  char *v14; // eax
  int v15; // eax
  CUtlBuffer build; // [esp+0h] [ebp-30h] BYREF

  if ( args->m_nArgc != 1 )
  {
    ConMsg(a1: "stuffcmds : execute command line parameters\n");
    return;
  }
  CUtlBuffer::CUtlBuffer(this: &build, growSize: 0, initSize: 0, nFlags: 1u);
  v1 = 1;
  v2 = _CommandLine();
  if ( (*(int (__thiscall **)(int))(*(_DWORD *)v2 + 36))(a1: v2) > 1 )
  {
    do
    {
      v3 = _CommandLine();
      v4 = (_BYTE *)(*(int (__thiscall **)(int, int))(*(_DWORD *)v3 + 44))(a1: v3, a2: v1);
      v5 = v4;
      if ( v4 != nullptr )
      {
        v6 = *v4;
        if ( *v5 == 45 )
        {
          v7 = _CommandLine();
          if ( (*(int (__thiscall **)(int, _BYTE *, _DWORD))(*(_DWORD *)v7 + 32))(a1: v7, a2: v5, a3: 0) != 0 )
            ++v1;
          goto LABEL_15;
        }
        if ( v6 == 43 )
        {
          v8 = _CommandLine();
          v9 = (const char *)(*(int (__thiscall **)(int, _BYTE *, _DWORD))(*(_DWORD *)v8 + 32))(a1: v8, a2: v5, a3: 0);
          v10 = v5 + 1;
          if ( v9 == nullptr )
          {
            CUtlBuffer::PutString(this: &build, pString: v10);
LABEL_14:
            CUtlBuffer::PutChar(this: &build, c: 10);
            goto LABEL_15;
          }
          v11 = va(format: "%s %s\n", v10, v9);
          CUtlBuffer::PutString(this: &build, pString: v11);
          ++v1;
        }
        else
        {
          v12 = _CommandLine();
          v13 = (const char *)(*(int (__thiscall **)(int, int))(*(_DWORD *)v12 + 44))(a1: v12, a2: v1);
          v14 = Cmd_TranslateFileAssociation(param: v13);
          if ( v14 != nullptr )
          {
            CUtlBuffer::PutString(this: &build, pString: v14);
            goto LABEL_14;
          }
        }
      }
LABEL_15:
      ++v1;
      v15 = _CommandLine();
    }
    while ( v1 < (*(int (__thiscall **)(int))(*(_DWORD *)v15 + 36))(a1: v15) );
  }
  if ( (build.m_Flags & 1) != 0 && build.m_Put != 0 && build.m_Memory.m_pMemory[build.m_Put - build.m_nOffset - 1] == 10 )
    CUtlBuffer::PutTabs(this: &build);
  if ( CUtlBuffer::CheckPut(this: &build, nSize: 1) != 0 )
  {
    build.m_Memory.m_pMemory[build.m_Put++ - build.m_nOffset] = 0;
    CUtlBuffer::AddNullTermination(this: &build, nPut: build.m_Put);
  }
  if ( build.m_Put > 1 )
    Cbuf_InsertText(eTarget: CBUF_FIRST_PLAYER, pText: (char *)build.m_Memory.m_pMemory, nTickDelay: nullptr);
  if ( build.m_Memory.m_nGrowSize >= 0 && build.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: build.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1014B150
// Name: CreateExecutionMarker
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __thiscall CreateExecutionMarker(IUniformRandomStream *this)
{
  int v1; // edi
  int m_Size; // eax
  int v3; // esi
  int *m_pMemory; // ecx
  int v5; // eax
  int *v6; // eax

  if ( g_ExecutionMarkers.m_Size > 2048 )
  {
    if ( g_ExecutionMarkers.m_Size - 1 > 0 )
      _V_memmove(
        dest: g_ExecutionMarkers.m_Memory.m_pMemory,
        src: g_ExecutionMarkers.m_Memory.m_pMemory + 1,
        count: 4 * (g_ExecutionMarkers.m_Size - 1));
    --g_ExecutionMarkers.m_Size;
  }
  v1 = _RandomInt(this, a2: 0, a3: 0x40000000);
  m_Size = g_ExecutionMarkers.m_Size;
  v3 = g_ExecutionMarkers.m_Size;
  if ( g_ExecutionMarkers.m_Size + 1 > g_ExecutionMarkers.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<INetMessage *,int>::Grow(
      this: (CUtlMemory<S3RGBA,int> *)&g_ExecutionMarkers,
      num: g_ExecutionMarkers.m_Size - g_ExecutionMarkers.m_Memory.m_nAllocationCount + 1);
    m_Size = g_ExecutionMarkers.m_Size;
  }
  m_pMemory = g_ExecutionMarkers.m_Memory.m_pMemory;
  g_ExecutionMarkers.m_Size = m_Size + 1;
  v5 = m_Size - v3;
  g_ExecutionMarkers.m_pElements = g_ExecutionMarkers.m_Memory.m_pMemory;
  if ( v5 > 0 )
  {
    _V_memmove(
      dest: &g_ExecutionMarkers.m_Memory.m_pMemory[v3 + 1],
      src: &g_ExecutionMarkers.m_Memory.m_pMemory[v3],
      count: 4 * v5);
    m_pMemory = g_ExecutionMarkers.m_Memory.m_pMemory;
  }
  v6 = &m_pMemory[v3];
  if ( v6 != nullptr )
  {
    *v6 = v1;
    m_pMemory = g_ExecutionMarkers.m_Memory.m_pMemory;
  }
  return m_pMemory[v3];
}

//------------------------------------------------------------------------------
// Address: 0x1014B210
// Name: void Cbuf_AddExecutionMarker(enum ECommandTarget_t,enum ECmdExecutionMarker)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Cbuf_AddExecutionMarker(ECommandTarget_t eTarget, ECmdExecutionMarker marker)
{
  IUniformRandomStream *v2; // ecx
  int ExecutionMarker; // eax
  char str[512]; // [esp+0h] [ebp-200h] BYREF

  ExecutionMarker = CreateExecutionMarker(this: v2);
  V_snprintf(pDest: str, maxLen: 512, pFormat: ";%s %c %d;", "[$&*,`]", (char)marker, ExecutionMarker);
  Cbuf_AddText(eTarget, pText: str, nTickDelay: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1014B260
// Name: ShouldPreventClientCommand
// Source: json
//------------------------------------------------------------------------------
char __usercall ShouldPreventClientCommand@<al>(ConCommandBase *pCommand@<esi>)
{
  const char *v1; // eax
  const char *v2; // eax
  CUtlMap<char const *,int,int>::Node_t search; // [esp+0h] [ebp-8h] BYREF

  if ( g_iFilterCommandsByClientCmdCanExecute <= 0 )
    return 0;
  if ( pCommand->IsFlagSet(this: pCommand, a2: 0x40000000) )
    return 0;
  v1 = pCommand->GetName(this: pCommand);
  if ( v1 != nullptr )
  {
    search.key = v1;
    if ( CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Find(
           this: &g_ExtraClientCmdCanExecuteCvars.m_Elements.m_Tree,
           &search) != -1 )
      return 0;
  }
  if ( !pCommand->IsFlagSet(this: pCommand, a2: 4) )
  {
    v2 = pCommand->GetName(this: pCommand);
    _Warning(a1: "FCVAR_CLIENTCMD_CAN_EXECUTE prevented running command: %s\n", v2);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1014B2E0
// Name: class ConCommandBase const __near * Cmd_ExecuteCommand(enum ECommandTarget_t,class CCommand const __near &,enum cmd_source_t,int)
// Source: json
//------------------------------------------------------------------------------
const ConCommandBase *__usercall Cmd_ExecuteCommand@<eax>(
        int a1@<ebx>,
        ECommandTarget_t eTarget,
        const CCommand *command,
        cmd_source_t src,
        int nClientSlot)
{
  const char *v5; // eax
  cmdalias_t *v7; // esi
  const char *v8; // eax
  const char *v9; // eax
  ConCommandBase *v10; // esi
  const char *v11; // eax
  bool v12; // bl
  char v13; // al
  CServerPlugin_vtbl *v14; // ebx
  CClientState *LocalClient; // eax
  const char *v16; // eax
  const char *v17; // eax
  bool v18; // al
  ConCommandBase_vtbl *v19; // edx
  const char *v20; // eax
  const char *v21; // eax

  if ( command->m_nArgc == 0 )
    return nullptr;
  v5 = defaultValue;
  if ( command->m_nArgc > 0 )
    v5 = command->m_ppArgv[0];
  if ( _V_strcmp(s1: v5, s2: "[$&*,`]") == 0 )
  {
    if ( command->m_nArgc == 3 )
    {
      HandleExecutionMarker(pCommand: (char *)command->m_ppArgv[1], pMarkerCode: command->m_ppArgv[2]);
      return nullptr;
    }
    _Warning(a1: "WARNING: INVALID EXECUTION MARKER.\n");
    return nullptr;
  }
  v7 = cmd_alias;
  if ( cmd_alias == nullptr )
  {
LABEL_12:
    cmd_clientslot = nClientSlot;
    cmd_source = src;
    v9 = defaultValue;
    if ( command->m_nArgc > 0 )
      v9 = command->m_ppArgv[0];
    v10 = g_pCVar->FindCommandBase_2(this: g_pCVar, a2: v9);
    if ( !Host_IsSinglePlayerGame() && g_iFilterCommandsByServerCanExecute > 0 )
    {
      if ( v10 == nullptr )
        goto LABEL_54;
      if ( !v10->IsFlagSet(this: v10, a2: 0x10000000) )
      {
        v11 = v10->GetName(this: v10);
        _Warning(a1: "FCVAR_SERVER_CAN_EXECUTE prevented server running command: %s\n", v11);
        return nullptr;
      }
    }
    if ( v10 != nullptr
      && v10->IsCommand(this: v10)
      && ShouldPreventClientCommand(pCommand: v10) == 0
      && v10->IsCommand(this: v10) )
    {
      v12 = v10->IsFlagSet(this: v10, a2: 4) && cmd_source == src_command && !sv.m_bIsDedicated;
      if ( serverGameClients != nullptr )
      {
        if ( sv.m_State < ss_active )
        {
          if ( v12 )
          {
            if ( GetBaseLocalClient()->m_nSignonState >= 2 )
            {
              Cmd_ForwardToServer(args: command);
              return nullptr;
            }
            return nullptr;
          }
        }
        else
        {
          g_pServerPluginHandler->SetCommandClient(this: g_pServerPluginHandler, a2: -1);
          if ( v12 )
          {
            v13 = ((int (__thiscall *)(ISplitScreen *, int))splitscreen->IsLocalPlayerResolvable)(
                    a1: splitscreen,
                    a2: a1);
            v14 = g_pServerPluginHandler->__vftable;
            if ( v13 != 0 )
              LocalClient = GetLocalClient(nSlot: -1);
            else
              LocalClient = GetBaseLocalClient();
            v14->SetCommandClient(this: g_pServerPluginHandler, a2: LocalClient->m_nPlayerSlot);
          }
        }
      }
      if ( !v10->IsFlagSet(this: v10, a2: 0x4000)
        || Host_IsSinglePlayerGame()
        || sv_cheats.m_pParent != nullptr && sv_cheats.m_pParent->m_Value.m_nValue != 0
        || g_bRPTActive
        || g_iFilterCommandsByServerCanExecute != 0 && v10->IsFlagSet(this: v10, a2: 0x10000000) )
      {
        if ( !v10->IsFlagSet(this: v10, a2: 64) || Host_IsSinglePlayerGame() )
        {
          v18 = v10->IsFlagSet(this: v10, a2: 2);
          v19 = v10->__vftable;
          if ( v18 )
          {
            v20 = v19->GetName(this: v10);
            _Msg(a1: "Unknown command \"%s\"\n", v20);
            return nullptr;
          }
          else
          {
            v19[1].IsFlagSet(this: v10, a2: (int)command);
            return v10;
          }
        }
        else
        {
          v17 = v10->GetName(this: v10);
          _Msg(a1: "Can't use command %s in multiplayer.\n", v17);
          return nullptr;
        }
      }
      v16 = v10->GetName(this: v10);
      _Msg(a1: "Can't use cheat command %s in multiplayer, unless the server has sv_cheats set to 1.\n", v16);
      return nullptr;
    }
LABEL_54:
    if ( CCvarUtilities::IsCommand(this: cv, args: command, iSplitscreenSlot: eTarget) != 0 )
      return v10;
    if ( cmd_source == src_command && GetBaseLocalClient()->m_nSignonState >= 2 )
    {
      Cmd_ForwardToServer(args: command);
      return nullptr;
    }
    else
    {
      v21 = defaultValue;
      if ( command->m_nArgc > 0 )
        v21 = command->m_ppArgv[0];
      _Msg(a1: "Unknown command \"%s\"\n", v21);
      return nullptr;
    }
  }
  while ( 1 )
  {
    v8 = CCommand::operator[](this: command, nIndex: 0);
    if ( V_strcasecmp(s1: v8, s2: v7->name) == 0 )
      break;
    v7 = v7->next;
    if ( v7 == nullptr )
      goto LABEL_12;
  }
  Cbuf_InsertText(eTarget: CBUF_FIRST_PLAYER, pText: v7->value, nTickDelay: nullptr);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1014B630
// Name: void Cbuf_Execute(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Cbuf_Execute()
{
  int v0; // ecx
  DWORD CurrentThreadId; // ecx
  ECommandTarget_t v2; // ebx
  CCommandBuffer *v3; // edi
  const ConCommandBase *v4; // eax
  const char *m_pArgSBuffer; // eax

  if ( (unsigned __int8)_ThreadInMainThread() == 0 )
  {
    _Warning(a1: "Executing command outside main loop thread\n");
    if ( _executeCount_2 < 1 )
    {
      ++_executeCount_2;
      if ( (unsigned __int8)_Plat_IsInDebugSession(a1: v0) != 0 )
        __debugbreak();
    }
  }
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != s_CommandBufferMutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&s_CommandBufferMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &s_CommandBufferMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++s_CommandBufferMutex.m_depth;
  }
  v2 = CBUF_FIRST_PLAYER;
  v3 = s_CommandBuffer;
  do
  {
    if ( !CCommandBuffer::IsProcessingCommands(this: v3) )
    {
      CCommandBuffer::BeginProcessingCommands(this: v3, nDeltaTicks: 1);
      while ( CCommandBuffer::DequeueNextCommand(this: v3) != 0 )
      {
        v4 = Cmd_ExecuteCommand(a1: v2, eTarget: v2, command: &v3->m_CurrentCommand, src: src_command, nClientSlot: -1);
        if ( v4 != nullptr && !v4->IsFlagSet(this: (ConCommandBase *)v4, a2: 0x20000) )
        {
          m_pArgSBuffer = v3->m_CurrentCommand.m_pArgSBuffer;
          if ( v3->m_CurrentCommand.m_nArgc == 0 )
            m_pArgSBuffer = defaultValue;
          demorecorder->RecordCommand(this: demorecorder, a2: m_pArgSBuffer);
        }
      }
      CCommandBuffer::EndProcessingCommands(this: v3);
    }
    ++v3;
    ++v2;
  }
  while ( (int)v3 < (int)&s_CommandBufferMutex );
  if ( --s_CommandBufferMutex.m_depth == 0 )
    _InterlockedExchange((volatile __int32 *)&s_CommandBufferMutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x1014B760
// Name: void _Cmd_Exec_f(class CCommand const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl _Cmd_Exec_f(const CCommand *args, bool bOnlyIfExists)
{
  DWORD CurrentThreadId; // ecx
  int m_nArgc; // edi
  const char *v4; // esi
  const char *v5; // ebx
  const char *v6; // edi
  const char *v7; // esi
  char *v8; // edi
  const char *v9; // esi
  int NextCommandHandle; // esi
  const char *i; // ebx
  DWORD v12; // eax
  const ConCommandBase *v13; // eax
  char *m_pArgSBuffer; // eax
  const char *v15; // [esp-Ch] [ebp-4120h]
  const char *v16; // [esp-Ch] [ebp-4120h]
  char buffer[16384]; // [esp+8h] [ebp-410Ch] BYREF
  char pDest[264]; // [esp+4008h] [ebp-10Ch] BYREF
  int filesize; // [esp+4110h] [ebp-4h] BYREF

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != s_CommandBufferMutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&s_CommandBufferMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &s_CommandBufferMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++s_CommandBufferMutex.m_depth;
  }
  m_nArgc = args->m_nArgc;
  if ( args->m_nArgc < 2 )
  {
    if ( m_nArgc > 0 )
      v4 = args->m_ppArgv[0];
    else
      v4 = defaultValue;
    ConMsg(a1: "%s <filename> [path id]: execute a script file\n", v4);
    if ( --s_CommandBufferMutex.m_depth == 0 )
      _InterlockedExchange((volatile __int32 *)&s_CommandBufferMutex, 0);
    return;
  }
  v5 = defaultValue;
  if ( m_nArgc > 1 )
    v5 = args->m_ppArgv[1];
  DevMsg(a1: "Execing config: %s\n", v5);
  if ( m_nArgc < 3 )
  {
    v6 = "*";
  }
  else
  {
    v6 = defaultValue;
    if ( args->m_nArgc > 2 )
      v6 = args->m_ppArgv[2];
  }
  if ( _V_stricmp(s1: v6, s2: "T") != 0 )
  {
    V_snprintf(pDest, maxLen: 260, pFormat: "//%s/cfg/%s", v6, v5);
    V_DefaultExtension(path: pDest, extension: ".cfg", pathStringLength: 260);
    if ( !COM_IsValidPath(pszFilename: pDest) )
    {
      if ( args->m_nArgc > 0 )
        v7 = args->m_ppArgv[0];
      else
        v7 = defaultValue;
      ConMsg(a1: "%s %s: invalid path.\n", v7, pDest);
      if ( --s_CommandBufferMutex.m_depth == 0 )
        _InterlockedExchange((volatile __int32 *)&s_CommandBufferMutex, 0);
      return;
    }
  }
  else
  {
    V_snprintf(pDest, maxLen: 260, pFormat: "T:/cfg/%s", v5);
  }
  if ( !IsValidFileExtension(pszFilename: pDest) )
  {
    if ( args->m_nArgc > 0 )
      v15 = args->m_ppArgv[0];
    else
      v15 = defaultValue;
    ConMsg(a1: "%s %s: invalid file type.\n", v15, pDest);
    goto LABEL_45;
  }
  if ( g_pFileSystem->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: pDest, a3: nullptr)
    && g_pFileSystem->Size(this: &g_pFileSystem->IBaseFileSystem, a2: pDest, a3: nullptr) > 0x100000 )
  {
    if ( args->m_nArgc > 0 )
      v16 = args->m_ppArgv[0];
    else
      v16 = defaultValue;
    ConMsg(a1: "%s %s: file size larger than 1 MB!\n", v16, v5);
    goto LABEL_45;
  }
  v8 = (char *)COM_LoadStackFile(path: pDest, buffer, bufsize: 0x4000, &filesize);
  if ( v8 == nullptr )
  {
    if ( V_stristr(pStr: v5, pSearch: "autoexec.cfg") == nullptr
      && V_stristr(pStr: v5, pSearch: "joystick.cfg") == nullptr
      && V_stristr(pStr: v5, pSearch: "game.cfg") == nullptr
      && !bOnlyIfExists )
    {
      if ( args->m_nArgc > 0 )
        v9 = args->m_ppArgv[0];
      else
        v9 = defaultValue;
      ConMsg(a1: "%s: couldn't exec %s\n", v9, v5);
    }
LABEL_45:
    if ( --s_CommandBufferMutex.m_depth != 0 )
      return;
    goto LABEL_66;
  }
  _ConDMsg(a1: "execing %s\n", v5);
  NextCommandHandle = CCommandBuffer::GetNextCommandHandle(this: s_CommandBuffer);
  for ( i = COM_ParseLine(data: v8); _V_strlen(str: com_token) > 0; i = COM_ParseLine(data: i) )
  {
    v12 = GetCurrentThreadId();
    if ( v12 != s_CommandBufferMutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)&s_CommandBufferMutex, v12, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &s_CommandBufferMutex, a2: v12, a3: 0);
    }
    else
    {
      ++s_CommandBufferMutex.m_depth;
    }
    Cbuf_AddText(eTarget: CBUF_FIRST_PLAYER, pText: com_token, nTickDelay: 0);
    if ( --s_CommandBufferMutex.m_depth == 0 )
      _InterlockedExchange((volatile __int32 *)&s_CommandBufferMutex, 0);
    while ( CCommandBuffer::GetNextCommandHandle(this: s_CommandBuffer) != NextCommandHandle )
    {
      if ( CCommandBuffer::DequeueNextCommand(this: s_CommandBuffer) == 0 )
        break;
      v13 = Cmd_ExecuteCommand(
              eTarget: CBUF_FIRST_PLAYER,
              command: &s_CommandBuffer[0].m_CurrentCommand,
              src: src_command,
              nClientSlot: -1);
      if ( v13 != nullptr && !v13->IsFlagSet(this: (ConCommandBase *)v13, a2: 0x20000) )
      {
        m_pArgSBuffer = s_CommandBuffer[0].m_CurrentCommand.m_pArgSBuffer;
        if ( s_CommandBuffer[0].m_CurrentCommand.m_nArgc == 0 )
          m_pArgSBuffer = (char *)defaultValue;
        demorecorder->RecordCommand(this: demorecorder, a2: m_pArgSBuffer);
      }
    }
  }
  if ( v8 != buffer )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v8);
  if ( --s_CommandBufferMutex.m_depth == 0 )
LABEL_66:
    _InterlockedExchange((volatile __int32 *)&s_CommandBufferMutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x1014BBB0
// Name: void Cmd_Exec_f(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Cmd_Exec_f(const CCommand *args)
{
  _Cmd_Exec_f(args, bOnlyIfExists: false);
}

//------------------------------------------------------------------------------
// Address: 0x1014BBD0
// Name: void Cmd_ExecIfExists_f(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Cmd_ExecIfExists_f(const CCommand *args)
{
  _Cmd_Exec_f(args, bOnlyIfExists: true);
}

//------------------------------------------------------------------------------
// Address: 0x1014BBF0
// Name: void Cmd_AddClientCmdCanExecuteVar(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Cmd_AddClientCmdCanExecuteVar(char *pName)
{
  CUtlMap<char const *,int,int>::Node_t search; // [esp+4h] [ebp-8h] BYREF

  if ( pName == nullptr
    || (search.key = pName,
        CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Find(
          this: &g_ExtraClientCmdCanExecuteCvars.m_Elements.m_Tree,
          &search) == -1) )
  {
    CUtlDict<int,int>::Insert(this: &g_ExtraClientCmdCanExecuteCvars, pName);
  }
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1014A8A0
// Name: void Cmd_SetRptActive(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Cmd_SetRptActive(bool bActive)
{
  g_bRPTActive = bActive;
}

//------------------------------------------------------------------------------
// Address: 0x1014A8C0
// Name: void Cbuf_Init(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Cbuf_Init()
{
  CCommandBuffer *v0; // esi

  v0 = s_CommandBuffer;
  do
    CCommandBuffer::SetWaitDelayTime(this: v0++, nTickDelay: 1);
  while ( (int)v0 < (int)&s_CommandBufferMutex );
}

//------------------------------------------------------------------------------
// Address: 0x1014A8E0
// Name: void Cbuf_Clear(enum ECommandTarget_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Cbuf_Clear(ECommandTarget_t eTarget)
{
  CCommandBuffer::SetWaitDelayTime(this: &s_CommandBuffer[eTarget], nTickDelay: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1014A900
// Name: Cmd_TranslateFileAssociation
// Source: json
//------------------------------------------------------------------------------
char *__usercall Cmd_TranslateFileAssociation@<eax>(const char *param@<eax>)
{
  char *result; // eax
  const char *v2; // esi
  FileAssociationInfo *v3; // ebx
  int *v4; // edi
  int v5; // esi
  char *v6; // eax
  char temp[512]; // [esp+4h] [ebp-208h] BYREF
  const char *extension; // [esp+204h] [ebp-8h]
  char *retval; // [esp+208h] [ebp-4h]

  retval = nullptr;
  V_strncpy(pDest: temp, pSrc: param, maxLen: 512);
  V_FixSlashes(pname: temp, separator: 92);
  _V_strlower(start: temp);
  result = (char *)V_GetFileExtension(path: temp);
  v2 = result;
  extension = result;
  if ( result != nullptr )
  {
    v3 = g_FileAssociations;
    while ( 1 )
    {
      if ( _V_strcmp(s1: v2, s2: v3->extension + 1) == 0 )
      {
        v4 = (int *)_CommandLine();
        v5 = *v4;
        v6 = va(format: "+%s", v3->command_to_issue);
        if ( (*(int (__thiscall **)(int *, char *))(v5 + 40))(a1: v4, a2: v6) == 0 )
        {
          V_strncpy(pDest: sz_0, pSrc: temp, maxLen: 512);
          V_FileBase(in: sz_0, out: temp, maxlen: 512);
          V_snprintf(pDest: sz_0, maxLen: 512, pFormat: "%s %s", v3->command_to_issue, temp);
          return sz_0;
        }
        v2 = extension;
      }
      if ( (int)++v3 >= (int)&cmd_clientslot )
        return retval;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1014AA10
// Name: bool IsValidFileExtension(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsValidFileExtension(const char *pszFilename)
{
  return pszFilename != nullptr
      && _V_strstr(s1: pszFilename, search: ".exe") == nullptr
      && _V_strstr(s1: pszFilename, search: ".vbs") == nullptr
      && _V_strstr(s1: pszFilename, search: ".com") == nullptr
      && _V_strstr(s1: pszFilename, search: ".bat") == nullptr
      && _V_strstr(s1: pszFilename, search: ".dll") == nullptr
      && _V_strstr(s1: pszFilename, search: ".ini") == nullptr
      && _V_strstr(s1: pszFilename, search: ".gcf") == nullptr
      && _V_strstr(s1: pszFilename, search: ".sys") == nullptr
      && _V_strstr(s1: pszFilename, search: ".blob") == nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1014AAE0
// Name: echo
// Source: json
//------------------------------------------------------------------------------
void __cdecl echo(const CCommand *args)
{
  const CCommand *v1; // eax
  int m_nArgc; // edi
  int v3; // esi
  const char **v4; // ebx
  const char *v5; // eax

  v1 = args;
  m_nArgc = args->m_nArgc;
  v3 = 1;
  if ( args->m_nArgc > 1 )
  {
    v4 = &args->m_ppArgv[1];
    while ( 1 )
    {
      v5 = v3 < 0 || v3 >= v1->m_nArgc ? defaultValue : *v4;
      ConMsg(a1: "%s ", v5);
      ++v3;
      ++v4;
      if ( v3 >= m_nArgc )
        break;
      v1 = args;
    }
  }
  ConMsg(a1: "\n");
}

//------------------------------------------------------------------------------
// Address: 0x1014AB40
// Name: alias
// Source: json
//------------------------------------------------------------------------------
void __cdecl alias(const CCommand *args)
{
  int m_nArgc; // edi
  cmdalias_t *i; // esi
  int v3; // esi
  const char **v4; // ebx
  const char *v5; // eax
  cmdalias_t *v6; // esi
  char cmd[1024]; // [esp+Ch] [ebp-404h] BYREF
  char *str; // [esp+40Ch] [ebp-4h]

  m_nArgc = args->m_nArgc;
  if ( args->m_nArgc == 1 )
  {
    ConMsg(a1: "Current alias commands:\n");
    for ( i = cmd_alias; i != nullptr; i = i->next )
      ConMsg(a1: "%s : %s\n", i->name, i->value);
    return;
  }
  if ( args->m_nArgc > 1 )
    str = (char *)args->m_ppArgv[1];
  else
    str = (char *)defaultValue;
  if ( _V_strlen(str) >= 32 )
  {
    ConMsg(a1: "Alias name is too long\n");
    return;
  }
  v3 = 2;
  cmd[0] = 0;
  if ( m_nArgc > 2 )
  {
    v4 = &args->m_ppArgv[2];
    do
    {
      if ( v3 < 0 || v3 >= args->m_nArgc )
        v5 = defaultValue;
      else
        v5 = *v4;
      V_strncat(pDest: cmd, pSrc: v5, destBufferSize: 0x400u, max_chars_to_copy: -1);
      if ( v3 != m_nArgc )
        V_strncat(pDest: cmd, pSrc: " ", destBufferSize: 0x400u, max_chars_to_copy: -1);
      ++v3;
      ++v4;
    }
    while ( v3 < m_nArgc );
  }
  V_strncat(pDest: cmd, pSrc: "\n", destBufferSize: 0x400u, max_chars_to_copy: -1);
  v6 = cmd_alias;
  if ( cmd_alias == nullptr )
  {
LABEL_22:
    v6 = (cmdalias_t *)MemAlloc_Alloc(nSize: 0x28u);
    v6->next = cmd_alias;
    cmd_alias = v6;
LABEL_23:
    V_strncpy(pDest: v6->name, pSrc: str, maxLen: 32);
    v6->value = COM_StringCopy(in: cmd);
    return;
  }
  while ( _V_strcmp(s1: str, s2: v6->name) != 0 )
  {
    v6 = v6->next;
    if ( v6 == nullptr )
      goto LABEL_22;
  }
  if ( _V_strcmp(s1: v6->value, s2: cmd) != 0 )
  {
    free(pMem: v6->value);
    goto LABEL_23;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014ACE0
// Name: g_exec_CompletionFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl g_exec_CompletionFunc(const char *partial, char (*commands)[64])
{
  if ( (_S2_10 & 1) == 0 )
  {
    _S2_10 |= 1u;
    execComplete.m_pszCommandName = "exec";
    execComplete.m_pszSubDir = "cfg";
    execComplete.m_pszExtension = "cfg";
  }
  return CBaseAutoCompleteFileList::AutoCompletionFunc(this: &execComplete, partial, commands);
}

//------------------------------------------------------------------------------
// Address: 0x1014AD30
// Name: g_execifexists_CompletionFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl g_execifexists_CompletionFunc(const char *partial, char (*commands)[64])
{
  if ( (_S3_3 & 1) == 0 )
  {
    _S3_3 |= 1u;
    execifexistsComplete.m_pszCommandName = "execifexists";
    execifexistsComplete.m_pszSubDir = "cfg";
    execifexistsComplete.m_pszExtension = "cfg";
  }
  return CBaseAutoCompleteFileList::AutoCompletionFunc(this: &execifexistsComplete, partial, commands);
}

//------------------------------------------------------------------------------
// Address: 0x1014AD80
// Name: void Cmd_Init(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Cmd_Init()
{
  Sys_CreateFileAssociations(count: 3, list: g_FileAssociations);
}

//------------------------------------------------------------------------------
// Address: 0x1014AD90
// Name: void Cmd_Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Cmd_Shutdown()
{
  cmdalias_t *v0; // eax
  cmdalias_t *next; // esi

  v0 = cmd_alias;
  if ( cmd_alias != nullptr )
  {
    do
    {
      next = v0->next;
      free(pMem: v0->value);
      free(pMem: cmd_alias);
      v0 = next;
      cmd_alias = next;
    }
    while ( next != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014ADD0
// Name: void Cmd_Dispatch(class ConCommandBase const __near *,class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Cmd_Dispatch(ConCommandBase *pCommand, const CCommand *command)
{
  pCommand->__vftable[1].IsFlagSet(this: pCommand, a2: (int)command);
}

//------------------------------------------------------------------------------
// Address: 0x1014ADF0
// Name: void Cmd_ForwardToServer(class CCommand const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Cmd_ForwardToServer(const CCommand *args)
{
  bool v1; // cc
  const char *v2; // eax
  const char *v3; // eax
  int m_nArgv0Size; // eax
  bool v5; // zf
  const char *v6; // eax
  CClientState *LocalClient; // eax
  char str[1024]; // [esp+0h] [ebp-400h] BYREF

  if ( !demoplayer->IsPlayingBack(this: demoplayer) )
  {
    v1 = args->m_nArgc <= 0;
    str[0] = 0;
    v2 = defaultValue;
    if ( !v1 )
      v2 = args->m_ppArgv[0];
    if ( V_strcasecmp(s1: v2, s2: "cmd") != 0 )
    {
      v3 = defaultValue;
      if ( args->m_nArgc > 0 )
        v3 = args->m_ppArgv[0];
      V_strncat(pDest: str, pSrc: v3, destBufferSize: 0x400u, max_chars_to_copy: -1);
      V_strncat(pDest: str, pSrc: " ", destBufferSize: 0x400u, max_chars_to_copy: -1);
    }
    if ( args->m_nArgc > 1 )
    {
      m_nArgv0Size = args->m_nArgv0Size;
      v5 = m_nArgv0Size == 0;
      v6 = &args->m_pArgSBuffer[m_nArgv0Size];
      if ( v5 )
        v6 = defaultValue;
      V_strncat(pDest: str, pSrc: v6, destBufferSize: 0x400u, max_chars_to_copy: -1);
    }
    LocalClient = GetLocalClient(nSlot: -1);
    CBaseClientState::SendStringCmd(this: LocalClient, command: str);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014AED0
// Name: void Cbuf_AddText(enum ECommandTarget_t,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Cbuf_AddText(ECommandTarget_t eTarget, const char *pText, int nTickDelay)
{
  DWORD CurrentThreadId; // ecx

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != s_CommandBufferMutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&s_CommandBufferMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &s_CommandBufferMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++s_CommandBufferMutex.m_depth;
  }
  if ( !CCommandBuffer::AddText(this: &s_CommandBuffer[eTarget], pText, nTickDelay) )
    ConMsg(a1: "Cbuf_AddText: buffer overflow\n");
  if ( --s_CommandBufferMutex.m_depth == 0 )
    _InterlockedExchange((volatile __int32 *)&s_CommandBufferMutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x1014AFF0
// Name: BindToggle
// Source: json
//------------------------------------------------------------------------------
void __cdecl BindToggle(const CCommand *args)
{
  const char *v1; // eax
  char newCmd[1024]; // [esp+0h] [ebp-400h] BYREF

  if ( args->m_nArgc > 2 )
  {
    v1 = defaultValue;
    if ( args->m_nArgc > 1 )
      v1 = args->m_ppArgv[1];
    V_snprintf(pDest: newCmd, maxLen: 1024, pFormat: "bind %s \"incrementvar %s 0 1 1\"\n", v1, args->m_ppArgv[2]);
    Cbuf_InsertText(eTarget: CBUF_FIRST_PLAYER, pText: newCmd, nTickDelay: 0);
  }
  else
  {
    ConMsg(a1: "BindToggle <key> <cvar>: invalid syntax specified\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014B060
// Name: FindAndRemoveExecutionMarker
// Source: json
//------------------------------------------------------------------------------
char __thiscall FindAndRemoveExecutionMarker(void *iCode)
{
  int m_Size; // edx
  int v2; // eax

  m_Size = g_ExecutionMarkers.m_Size;
  v2 = 0;
  if ( g_ExecutionMarkers.m_Size <= 0 )
    return 0;
  while ( (void *)g_ExecutionMarkers.m_Memory.m_pMemory[v2] != iCode )
  {
    if ( ++v2 >= g_ExecutionMarkers.m_Size )
      return 0;
  }
  if ( v2 == -1 )
    return 0;
  if ( g_ExecutionMarkers.m_Size - v2 - 1 > 0 )
  {
    _V_memmove(
      dest: &g_ExecutionMarkers.m_Memory.m_pMemory[v2],
      src: &g_ExecutionMarkers.m_Memory.m_pMemory[v2 + 1],
      count: 4 * (g_ExecutionMarkers.m_Size - v2 - 1));
    m_Size = g_ExecutionMarkers.m_Size;
  }
  g_ExecutionMarkers.m_Size = m_Size - 1;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1014B0C0
// Name: HandleExecutionMarker
// Source: json
//------------------------------------------------------------------------------
void __usercall HandleExecutionMarker(char *pCommand@<eax>, const char *pMarkerCode@<ecx>)
{
  char v2; // bl
  void *v3; // eax

  v2 = *pCommand;
  v3 = (void *)atoi(nptr: pMarkerCode);
  if ( FindAndRemoveExecutionMarker(iCode: v3) != 0 )
  {
    switch ( v2 )
    {
      case 'a':
        ++g_iFilterCommandsByServerCanExecute;
        break;
      case 'b':
        --g_iFilterCommandsByServerCanExecute;
        break;
      case 'c':
        ++g_iFilterCommandsByClientCmdCanExecute;
        break;
      case 'd':
        --g_iFilterCommandsByClientCmdCanExecute;
        break;
      default:
        break;
    }
  }
  else if ( ++cnt < 3 )
  {
    _Warning(a1: "Invalid execution marker code.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014B130
// Name: stuffcmds
// Source: json
//------------------------------------------------------------------------------
void __cdecl stuffcmds(const CCommand *args)
{
  int v1; // edi
  int v2; // eax
  int v3; // eax
  _BYTE *v4; // eax
  _BYTE *v5; // esi
  char v6; // al
  int v7; // eax
  int v8; // eax
  const char *v9; // eax
  const char *v10; // esi
  const char *v11; // eax
  int v12; // eax
  const char *v13; // eax
  char *v14; // eax
  int v15; // eax
  CUtlBuffer build; // [esp+0h] [ebp-30h] BYREF

  if ( args->m_nArgc != 1 )
  {
    ConMsg(a1: "stuffcmds : execute command line parameters\n");
    return;
  }
  CUtlBuffer::CUtlBuffer(this: &build, growSize: 0, initSize: 0, nFlags: 1);
  v1 = 1;
  v2 = _CommandLine();
  if ( (*(int (__thiscall **)(int))(*(_DWORD *)v2 + 36))(a1: v2) > 1 )
  {
    do
    {
      v3 = _CommandLine();
      v4 = (_BYTE *)(*(int (__thiscall **)(int, int))(*(_DWORD *)v3 + 44))(a1: v3, a2: v1);
      v5 = v4;
      if ( v4 != nullptr )
      {
        v6 = *v4;
        if ( *v5 == 45 )
        {
          v7 = _CommandLine();
          if ( (*(int (__thiscall **)(int, _BYTE *, _DWORD))(*(_DWORD *)v7 + 32))(a1: v7, a2: v5, a3: 0) != 0 )
            ++v1;
          goto LABEL_15;
        }
        if ( v6 == 43 )
        {
          v8 = _CommandLine();
          v9 = (const char *)(*(int (__thiscall **)(int, _BYTE *, _DWORD))(*(_DWORD *)v8 + 32))(a1: v8, a2: v5, a3: 0);
          v10 = v5 + 1;
          if ( v9 == nullptr )
          {
            CUtlBuffer::PutString(this: &build, pString: v10);
LABEL_14:
            CUtlBuffer::PutChar(this: &build, c: 10);
            goto LABEL_15;
          }
          v11 = va(format: "%s %s\n", v10, v9);
          CUtlBuffer::PutString(this: &build, pString: v11);
          ++v1;
        }
        else
        {
          v12 = _CommandLine();
          v13 = (const char *)(*(int (__thiscall **)(int, int))(*(_DWORD *)v12 + 44))(a1: v12, a2: v1);
          v14 = Cmd_TranslateFileAssociation(param: v13);
          if ( v14 != nullptr )
          {
            CUtlBuffer::PutString(this: &build, pString: v14);
            goto LABEL_14;
          }
        }
      }
LABEL_15:
      ++v1;
      v15 = _CommandLine();
    }
    while ( v1 < (*(int (__thiscall **)(int))(*(_DWORD *)v15 + 36))(a1: v15) );
  }
  if ( (build.m_Flags & 1) != 0 && build.m_Put != 0 && build.m_Memory.m_pMemory[build.m_Put - build.m_nOffset - 1] == 10 )
    CUtlBuffer::PutTabs(this: &build);
  if ( CUtlBuffer::CheckPut(this: &build, nSize: 1) )
  {
    build.m_Memory.m_pMemory[build.m_Put++ - build.m_nOffset] = 0;
    CUtlBuffer::AddNullTermination(this: &build, nPut: build.m_Put);
  }
  if ( build.m_Put > 1 )
    Cbuf_InsertText(eTarget: CBUF_FIRST_PLAYER, pText: (const char *)build.m_Memory.m_pMemory, nTickDelay: 0);
  if ( build.m_Memory.m_nGrowSize >= 0 && build.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: build.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1014B2B0
// Name: CreateExecutionMarker
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __thiscall CreateExecutionMarker(IUniformRandomStream *this)
{
  int v1; // edi
  int m_Size; // eax
  int v3; // esi
  int *m_pMemory; // ecx
  int v5; // eax
  int *v6; // eax

  if ( g_ExecutionMarkers.m_Size > 2048 )
  {
    if ( g_ExecutionMarkers.m_Size - 1 > 0 )
      _V_memmove(
        dest: g_ExecutionMarkers.m_Memory.m_pMemory,
        src: g_ExecutionMarkers.m_Memory.m_pMemory + 1,
        count: 4 * (g_ExecutionMarkers.m_Size - 1));
    --g_ExecutionMarkers.m_Size;
  }
  v1 = _RandomInt(this, a2: 0, a3: 0x40000000);
  m_Size = g_ExecutionMarkers.m_Size;
  v3 = g_ExecutionMarkers.m_Size;
  if ( g_ExecutionMarkers.m_Size + 1 > g_ExecutionMarkers.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<INetMessage *,int>::Grow(
      this: (CUtlMemory<S3RGBA,int> *)&g_ExecutionMarkers,
      num: g_ExecutionMarkers.m_Size - g_ExecutionMarkers.m_Memory.m_nAllocationCount + 1);
    m_Size = g_ExecutionMarkers.m_Size;
  }
  m_pMemory = g_ExecutionMarkers.m_Memory.m_pMemory;
  g_ExecutionMarkers.m_Size = m_Size + 1;
  v5 = m_Size - v3;
  g_ExecutionMarkers.m_pElements = g_ExecutionMarkers.m_Memory.m_pMemory;
  if ( v5 > 0 )
  {
    _V_memmove(
      dest: &g_ExecutionMarkers.m_Memory.m_pMemory[v3 + 1],
      src: &g_ExecutionMarkers.m_Memory.m_pMemory[v3],
      count: 4 * v5);
    m_pMemory = g_ExecutionMarkers.m_Memory.m_pMemory;
  }
  v6 = &m_pMemory[v3];
  if ( v6 != nullptr )
  {
    *v6 = v1;
    m_pMemory = g_ExecutionMarkers.m_Memory.m_pMemory;
  }
  return m_pMemory[v3];
}

//------------------------------------------------------------------------------
// Address: 0x1014B370
// Name: void Cbuf_AddExecutionMarker(enum ECommandTarget_t,enum ECmdExecutionMarker)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Cbuf_AddExecutionMarker(ECommandTarget_t eTarget, ECmdExecutionMarker marker)
{
  IUniformRandomStream *v2; // ecx
  int ExecutionMarker; // eax
  char str[512]; // [esp+0h] [ebp-200h] BYREF

  ExecutionMarker = CreateExecutionMarker(this: v2);
  V_snprintf(pDest: str, maxLen: 512, pFormat: ";%s %c %d;", "[$&*,`]", (char)marker, ExecutionMarker);
  Cbuf_AddText(eTarget, pText: str, nTickDelay: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1014B3C0
// Name: ShouldPreventClientCommand
// Source: json
//------------------------------------------------------------------------------
char __usercall ShouldPreventClientCommand@<al>(ConCommandBase *pCommand@<esi>)
{
  const char *v1; // eax
  const char *v2; // eax
  CUtlMap<char const *,int,int>::Node_t search; // [esp+0h] [ebp-8h] BYREF

  if ( g_iFilterCommandsByClientCmdCanExecute <= 0 )
    return 0;
  if ( pCommand->IsFlagSet(this: pCommand, a2: 0x40000000) )
    return 0;
  v1 = pCommand->GetName(this: pCommand);
  if ( v1 != nullptr )
  {
    search.key = v1;
    if ( CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Find(
           this: &g_ExtraClientCmdCanExecuteCvars.m_Elements.m_Tree,
           &search) != -1 )
      return 0;
  }
  if ( !pCommand->IsFlagSet(this: pCommand, a2: 4) )
  {
    v2 = pCommand->GetName(this: pCommand);
    _Warning(a1: "FCVAR_CLIENTCMD_CAN_EXECUTE prevented running command: %s\n", v2);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1014B440
// Name: class ConCommandBase const __near * Cmd_ExecuteCommand(enum ECommandTarget_t,class CCommand const __near &,enum cmd_source_t,int)
// Source: json
//------------------------------------------------------------------------------
const ConCommandBase *__usercall Cmd_ExecuteCommand@<eax>(
        int a1@<ebx>,
        ECommandTarget_t eTarget,
        const CCommand *command,
        cmd_source_t src,
        int nClientSlot)
{
  const char *v5; // eax
  cmdalias_t *v7; // esi
  const char *v8; // eax
  const char *v9; // eax
  ConCommandBase *v10; // esi
  const char *v11; // eax
  bool v12; // bl
  char v13; // al
  CServerPlugin_vtbl *v14; // ebx
  CClientState *LocalClient; // eax
  const char *v16; // eax
  const char *v17; // eax
  bool v18; // al
  ConCommandBase_vtbl *v19; // edx
  const char *v20; // eax
  const char *v21; // eax

  if ( command->m_nArgc == 0 )
    return nullptr;
  v5 = defaultValue;
  if ( command->m_nArgc > 0 )
    v5 = command->m_ppArgv[0];
  if ( _V_strcmp(s1: v5, s2: "[$&*,`]") == 0 )
  {
    if ( command->m_nArgc == 3 )
    {
      HandleExecutionMarker(pCommand: (char *)command->m_ppArgv[1], pMarkerCode: command->m_ppArgv[2]);
      return nullptr;
    }
    _Warning(a1: "WARNING: INVALID EXECUTION MARKER.\n");
    return nullptr;
  }
  v7 = cmd_alias;
  if ( cmd_alias == nullptr )
  {
LABEL_12:
    cmd_clientslot = nClientSlot;
    cmd_source = src;
    v9 = defaultValue;
    if ( command->m_nArgc > 0 )
      v9 = command->m_ppArgv[0];
    v10 = g_pCVar->FindCommandBase_2(this: g_pCVar, a2: v9);
    if ( !Host_IsSinglePlayerGame() && g_iFilterCommandsByServerCanExecute > 0 )
    {
      if ( v10 == nullptr )
        goto LABEL_54;
      if ( !v10->IsFlagSet(this: v10, a2: 0x10000000) )
      {
        v11 = v10->GetName(this: v10);
        _Warning(a1: "FCVAR_SERVER_CAN_EXECUTE prevented server running command: %s\n", v11);
        return nullptr;
      }
    }
    if ( v10 != nullptr
      && v10->IsCommand(this: v10)
      && ShouldPreventClientCommand(pCommand: v10) == 0
      && v10->IsCommand(this: v10) )
    {
      v12 = v10->IsFlagSet(this: v10, a2: 4) && cmd_source == src_command && !sv.m_bIsDedicated;
      if ( serverGameClients != nullptr )
      {
        if ( sv.m_State < ss_active )
        {
          if ( v12 )
          {
            if ( GetBaseLocalClient()->m_nSignonState >= 2 )
            {
              Cmd_ForwardToServer(args: command);
              return nullptr;
            }
            return nullptr;
          }
        }
        else
        {
          g_pServerPluginHandler->SetCommandClient(this: g_pServerPluginHandler, a2: -1);
          if ( v12 )
          {
            v13 = ((int (__thiscall *)(ISplitScreen *, int))splitscreen->IsLocalPlayerResolvable)(
                    a1: splitscreen,
                    a2: a1);
            v14 = g_pServerPluginHandler->__vftable;
            if ( v13 != 0 )
              LocalClient = GetLocalClient(nSlot: -1);
            else
              LocalClient = GetBaseLocalClient();
            v14->SetCommandClient(this: g_pServerPluginHandler, a2: LocalClient->m_nPlayerSlot);
          }
        }
      }
      if ( !v10->IsFlagSet(this: v10, a2: 0x4000)
        || Host_IsSinglePlayerGame()
        || sv_cheats.m_pParent != nullptr && sv_cheats.m_pParent->m_Value.m_nValue != 0
        || g_bRPTActive
        || g_iFilterCommandsByServerCanExecute != 0 && v10->IsFlagSet(this: v10, a2: 0x10000000) )
      {
        if ( !v10->IsFlagSet(this: v10, a2: 64) || Host_IsSinglePlayerGame() )
        {
          v18 = v10->IsFlagSet(this: v10, a2: 2);
          v19 = v10->__vftable;
          if ( v18 )
          {
            v20 = v19->GetName(this: v10);
            _Msg(a1: "Unknown command \"%s\"\n", v20);
            return nullptr;
          }
          else
          {
            v19[1].IsFlagSet(this: v10, a2: (int)command);
            return v10;
          }
        }
        else
        {
          v17 = v10->GetName(this: v10);
          _Msg(a1: "Can't use command %s in multiplayer.\n", v17);
          return nullptr;
        }
      }
      v16 = v10->GetName(this: v10);
      _Msg(a1: "Can't use cheat command %s in multiplayer, unless the server has sv_cheats set to 1.\n", v16);
      return nullptr;
    }
LABEL_54:
    if ( CCvarUtilities::IsCommand(this: cv, args: command, iSplitscreenSlot: eTarget) )
      return v10;
    if ( cmd_source == src_command && GetBaseLocalClient()->m_nSignonState >= 2 )
    {
      Cmd_ForwardToServer(args: command);
      return nullptr;
    }
    else
    {
      v21 = defaultValue;
      if ( command->m_nArgc > 0 )
        v21 = command->m_ppArgv[0];
      _Msg(a1: "Unknown command \"%s\"\n", v21);
      return nullptr;
    }
  }
  while ( 1 )
  {
    v8 = CCommand::operator[](this: command, nIndex: 0);
    if ( V_strcasecmp(s1: v8, s2: v7->name) == 0 )
      break;
    v7 = v7->next;
    if ( v7 == nullptr )
      goto LABEL_12;
  }
  Cbuf_InsertText(eTarget: CBUF_FIRST_PLAYER, pText: v7->value, nTickDelay: 0);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1014B790
// Name: void Cbuf_Execute(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Cbuf_Execute()
{
  DWORD CurrentThreadId; // ecx
  ECommandTarget_t v1; // ebx
  CCommandBuffer *v2; // edi
  const ConCommandBase *v3; // eax
  const char *m_pArgSBuffer; // eax

  if ( (unsigned __int8)_ThreadInMainThread() == 0 )
  {
    _Warning(a1: "Executing command outside main loop thread\n");
    if ( _executeCount_2 < 1 )
    {
      ++_executeCount_2;
      if ( (unsigned __int8)_Plat_IsInDebugSession() != 0 )
        __debugbreak();
    }
  }
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != s_CommandBufferMutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&s_CommandBufferMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &s_CommandBufferMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++s_CommandBufferMutex.m_depth;
  }
  v1 = CBUF_FIRST_PLAYER;
  v2 = s_CommandBuffer;
  do
  {
    if ( !CCommandBuffer::IsProcessingCommands(this: v2) )
    {
      CCommandBuffer::BeginProcessingCommands(this: v2, nDeltaTicks: 1);
      while ( CCommandBuffer::DequeueNextCommand(this: v2) )
      {
        v3 = Cmd_ExecuteCommand(a1: v1, eTarget: v1, command: &v2->m_CurrentCommand, src: src_command, nClientSlot: -1);
        if ( v3 != nullptr && !v3->IsFlagSet(this: (ConCommandBase *)v3, a2: 0x20000) )
        {
          m_pArgSBuffer = v2->m_CurrentCommand.m_pArgSBuffer;
          if ( v2->m_CurrentCommand.m_nArgc == 0 )
            m_pArgSBuffer = defaultValue;
          demorecorder->RecordCommand(this: demorecorder, a2: m_pArgSBuffer);
        }
      }
      CCommandBuffer::EndProcessingCommands(this: v2);
    }
    ++v2;
    ++v1;
  }
  while ( (int)v2 < (int)&s_CommandBufferMutex );
  if ( --s_CommandBufferMutex.m_depth == 0 )
    _InterlockedExchange((volatile __int32 *)&s_CommandBufferMutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x1014B8C0
// Name: void _Cmd_Exec_f(class CCommand const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl _Cmd_Exec_f(const CCommand *args, bool bOnlyIfExists)
{
  DWORD CurrentThreadId; // ecx
  int m_nArgc; // edi
  const char *v4; // esi
  const char *v5; // ebx
  const char *v6; // edi
  const char *v7; // esi
  char *v8; // edi
  const char *v9; // esi
  int NextCommandHandle; // esi
  const char *i; // ebx
  DWORD v12; // eax
  const ConCommandBase *v13; // eax
  char *m_pArgSBuffer; // eax
  const char *v15; // [esp-Ch] [ebp-4120h]
  const char *v16; // [esp-Ch] [ebp-4120h]
  char buffer[16384]; // [esp+8h] [ebp-410Ch] BYREF
  char pDest[264]; // [esp+4008h] [ebp-10Ch] BYREF
  int filesize; // [esp+4110h] [ebp-4h] BYREF

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != s_CommandBufferMutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&s_CommandBufferMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &s_CommandBufferMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++s_CommandBufferMutex.m_depth;
  }
  m_nArgc = args->m_nArgc;
  if ( args->m_nArgc < 2 )
  {
    if ( m_nArgc > 0 )
      v4 = args->m_ppArgv[0];
    else
      v4 = defaultValue;
    ConMsg(a1: "%s <filename> [path id]: execute a script file\n", v4);
    if ( --s_CommandBufferMutex.m_depth == 0 )
      _InterlockedExchange((volatile __int32 *)&s_CommandBufferMutex, 0);
    return;
  }
  v5 = defaultValue;
  if ( m_nArgc > 1 )
    v5 = args->m_ppArgv[1];
  DevMsg(a1: "Execing config: %s\n", v5);
  if ( m_nArgc < 3 )
  {
    v6 = "*";
  }
  else
  {
    v6 = defaultValue;
    if ( args->m_nArgc > 2 )
      v6 = args->m_ppArgv[2];
  }
  if ( _V_stricmp(s1: v6, s2: "T") != 0 )
  {
    V_snprintf(pDest, maxLen: 260, pFormat: "//%s/cfg/%s", v6, v5);
    V_DefaultExtension(path: pDest, extension: ".cfg", pathStringLength: 260);
    if ( !COM_IsValidPath(pszFilename: pDest) )
    {
      if ( args->m_nArgc > 0 )
        v7 = args->m_ppArgv[0];
      else
        v7 = defaultValue;
      ConMsg(a1: "%s %s: invalid path.\n", v7, pDest);
      if ( --s_CommandBufferMutex.m_depth == 0 )
        _InterlockedExchange((volatile __int32 *)&s_CommandBufferMutex, 0);
      return;
    }
  }
  else
  {
    V_snprintf(pDest, maxLen: 260, pFormat: "T:/cfg/%s", v5);
  }
  if ( !IsValidFileExtension(pszFilename: pDest) )
  {
    if ( args->m_nArgc > 0 )
      v15 = args->m_ppArgv[0];
    else
      v15 = defaultValue;
    ConMsg(a1: "%s %s: invalid file type.\n", v15, pDest);
    goto LABEL_45;
  }
  if ( g_pFileSystem->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: pDest, a3: nullptr)
    && g_pFileSystem->Size(this: &g_pFileSystem->IBaseFileSystem, a2: pDest, a3: nullptr) > 0x100000 )
  {
    if ( args->m_nArgc > 0 )
      v16 = args->m_ppArgv[0];
    else
      v16 = defaultValue;
    ConMsg(a1: "%s %s: file size larger than 1 MB!\n", v16, v5);
    goto LABEL_45;
  }
  v8 = (char *)COM_LoadStackFile(path: pDest, buffer, bufsize: 0x4000, &filesize);
  if ( v8 == nullptr )
  {
    if ( V_stristr(pStr: v5, pSearch: "autoexec.cfg") == nullptr
      && V_stristr(pStr: v5, pSearch: "joystick.cfg") == nullptr
      && V_stristr(pStr: v5, pSearch: "game.cfg") == nullptr
      && !bOnlyIfExists )
    {
      if ( args->m_nArgc > 0 )
        v9 = args->m_ppArgv[0];
      else
        v9 = defaultValue;
      ConMsg(a1: "%s: couldn't exec %s\n", v9, v5);
    }
LABEL_45:
    if ( --s_CommandBufferMutex.m_depth != 0 )
      return;
    goto LABEL_66;
  }
  _ConDMsg(a1: "execing %s\n", v5);
  NextCommandHandle = CCommandBuffer::GetNextCommandHandle(this: s_CommandBuffer);
  for ( i = COM_ParseLine(data: v8); _V_strlen(str: com_token) > 0; i = COM_ParseLine(data: i) )
  {
    v12 = GetCurrentThreadId();
    if ( v12 != s_CommandBufferMutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)&s_CommandBufferMutex, v12, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &s_CommandBufferMutex, a2: v12, a3: 0);
    }
    else
    {
      ++s_CommandBufferMutex.m_depth;
    }
    Cbuf_AddText(eTarget: CBUF_FIRST_PLAYER, pText: com_token, nTickDelay: 0);
    if ( --s_CommandBufferMutex.m_depth == 0 )
      _InterlockedExchange((volatile __int32 *)&s_CommandBufferMutex, 0);
    while ( CCommandBuffer::GetNextCommandHandle(this: s_CommandBuffer) != NextCommandHandle )
    {
      if ( !CCommandBuffer::DequeueNextCommand(this: s_CommandBuffer) )
        break;
      v13 = Cmd_ExecuteCommand(
              a1: (int)i,
              eTarget: CBUF_FIRST_PLAYER,
              command: &s_CommandBuffer[0].m_CurrentCommand,
              src: src_command,
              nClientSlot: -1);
      if ( v13 != nullptr && !v13->IsFlagSet(this: (ConCommandBase *)v13, a2: 0x20000) )
      {
        m_pArgSBuffer = s_CommandBuffer[0].m_CurrentCommand.m_pArgSBuffer;
        if ( s_CommandBuffer[0].m_CurrentCommand.m_nArgc == 0 )
          m_pArgSBuffer = (char *)defaultValue;
        demorecorder->RecordCommand(this: demorecorder, a2: m_pArgSBuffer);
      }
    }
  }
  if ( v8 != buffer )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v8);
  if ( --s_CommandBufferMutex.m_depth == 0 )
LABEL_66:
    _InterlockedExchange((volatile __int32 *)&s_CommandBufferMutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x1014BD10
// Name: void Cmd_Exec_f(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Cmd_Exec_f(const CCommand *args)
{
  _Cmd_Exec_f(args, bOnlyIfExists: false);
}

//------------------------------------------------------------------------------
// Address: 0x1014BD30
// Name: void Cmd_ExecIfExists_f(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Cmd_ExecIfExists_f(const CCommand *args)
{
  _Cmd_Exec_f(args, bOnlyIfExists: true);
}

//------------------------------------------------------------------------------
// Address: 0x1014BD50
// Name: void Cmd_AddClientCmdCanExecuteVar(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Cmd_AddClientCmdCanExecuteVar(char *pName)
{
  CUtlMap<char const *,int,int>::Node_t search; // [esp+4h] [ebp-8h] BYREF

  if ( pName == nullptr
    || (search.key = pName,
        CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::Find(
          this: &g_ExtraClientCmdCanExecuteCvars.m_Elements.m_Tree,
          &search) == -1) )
  {
    CUtlDict<int,int>::Insert(this: &g_ExtraClientCmdCanExecuteCvars, pName);
  }
}

} // namespace engine_xlsp
