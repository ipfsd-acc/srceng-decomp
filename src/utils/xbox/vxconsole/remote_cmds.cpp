// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/xbox/vxconsole/remote_cmds.cpp
// Functions: 17
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00414D30
// Name: int MatchRemoteCommands(char __near *,char const __near * __near * const,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl MatchRemoteCommands(char *pCmdStr, const char **cmdList, int maxCmds)
{
  int v3; // edi
  signed int v4; // esi
  unsigned int matchLen; // [esp+8h] [ebp-4h]

  v3 = 0;
  matchLen = strlen(pCmdStr);
  v4 = 0;
  if ( (int)g_numRemoteCommands <= 0 )
    return 0;
  do
  {
    if ( V_strncasecmp(s1: pCmdStr, s2: g_remoteCommands[v4]->strCommand, n: matchLen) == 0 )
    {
      cmdList[v3++] = g_remoteCommands[v4]->strCommand;
      if ( v3 >= maxCmds )
        break;
    }
    ++v4;
  }
  while ( v4 < (int)g_numRemoteCommands );
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00414DB0
// Name: char __near * GetToken(char __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl GetToken(char **ppTokenStream)
{
  char **v1; // esi
  int v2; // edi
  char *v4; // eax
  char i; // cl
  char v6; // cl
  char *v7; // esi

  v1 = ppTokenStream;
  v2 = 0;
  token[0] = 0;
  if ( ppTokenStream == nullptr )
    return nullptr;
  v4 = *ppTokenStream;
  i = **ppTokenStream;
  while ( 1 )
  {
    if ( i <= 32 )
    {
      while ( i != 0 )
      {
        i = *++v4;
        if ( i > 32 )
          goto LABEL_7;
      }
      goto cleanup;
    }
LABEL_7:
    if ( i != 47 )
      break;
    if ( v4[1] != 47 )
      goto LABEL_19;
    for ( i = *v4; i != 0; i = *++v4 )
    {
      if ( i == 10 )
        break;
    }
  }
  if ( i != 34 )
  {
LABEL_19:
    v7 = (char *)(token - v4);
    do
    {
      v4[(_DWORD)v7] = i;
      ++v2;
      ++v4;
      if ( v2 > 255 )
        break;
      i = *v4;
    }
    while ( (unsigned __int8)(*v4 - 33) <= 0x5Du );
    v1 = ppTokenStream;
    goto cleanup;
  }
  v6 = v4[1];
  v4 += 2;
  if ( v6 != 34 )
  {
    while ( v6 != 0 )
    {
      token[v2++] = v6;
      if ( v2 > 255 )
        break;
      v6 = *v4++;
      if ( v6 == 34 )
      {
        token[v2] = 0;
        *ppTokenStream = v4;
        return token;
      }
    }
  }
cleanup:
  token[v2] = 0;
  *v1 = v4;
  return token;
}

//------------------------------------------------------------------------------
// Address: 0x00414E80
// Name: void CommandCompleted(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandCompleted(int errCode)
{
  char cmdString[260]; // [esp+0h] [ebp-104h] BYREF

  sprintf(string: cmdString, format: "%s!__complete__%d", "XCMD", errCode);
  DmAPI_SendCommand(strCommand: cmdString, wait: true);
}

//------------------------------------------------------------------------------
// Address: 0x00414EC0
// Name: void DebugCommand(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void DebugCommand(char *pStrFormat, ...)
{
  char string[4096]; // [esp+0h] [ebp-1000h] BYREF
  va_list ap; // [esp+100Ch] [ebp+Ch] BYREF

  va_start(ap, pStrFormat);
  if ( g_debugCommands != 0 )
  {
    _vsnprintf(string, count: 0x1000u, format: pStrFormat, ap);
    PrintToQueue(rgb: 0x8000u, strFormat: "[CMD]: %s", string);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00414F10
// Name: unsigned long Remote_NotifyDebugString(unsigned long,unsigned long)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall Remote_NotifyDebugString(unsigned int dwNotification, unsigned int dwParam)
{
  signed int v2; // esi
  unsigned __int8 *v3; // edi

  if ( g_captureDebugSpew != 0 )
  {
    v2 = *(_DWORD *)(dwParam + 4) - 1;
    if ( v2 > 0 )
    {
      while ( *(_BYTE *)(*(_DWORD *)(dwParam + 8) + v2) == 10 )
      {
        if ( --v2 <= 0 )
          goto LABEL_7;
      }
      ++v2;
    }
LABEL_7:
    v3 = (unsigned __int8 *)operator new(nSize: v2 + 1);
    memcpy(dst: v3, src: *(unsigned __int8 **)(dwParam + 8), count: v2);
    v3[v2] = 0;
    PrintToQueue(rgb: 0xFF0000u, strFormat: "[DBG]: %s\n", (const char *)v3);
    free(pMem: v3);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00414F80
// Name: unsigned long Remote_NotifyPerfFunc(char const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall Remote_NotifyPerfFunc(const char *pStrNotification)
{
  if ( g_playtestMode != 0 )
    PerfmonPrintf(strFormat: pStrNotification + 5);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00414FB0
// Name: unsigned long Remote_NotifyBinaryFunc(char const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall Remote_NotifyBinaryFunc(const char *pStrNotification)
{
  const char *v1; // ebx
  int v2; // eax
  int v4; // eax
  int v5; // esi
  void *v6; // esp
  unsigned __int8 *v7; // edi
  int v8; // eax
  int v9; // esi
  unsigned __int8 *v10; // edi
  unsigned int v11; // esi
  int v12; // [esp+0h] [ebp-Ch] BYREF
  char bDeleteMemory_3; // [esp+17h] [ebp+Bh]

  v1 = pStrNotification + 5;
  v2 = _DecodeBinaryFromString(a1: pStrNotification + 5, a2: 0, a3: 0, a4: 0);
  if ( v2 == 0x80000000 )
    return 1;
  v4 = -v2;
  v5 = v4;
  if ( v4 >= 0x20000 )
  {
    v7 = (unsigned __int8 *)operator new(nSize: v4);
    bDeleteMemory_3 = 1;
  }
  else
  {
    v6 = alloca(v4);
    v7 = (unsigned __int8 *)&v12;
    bDeleteMemory_3 = 0;
  }
  _DecodeBinaryFromString(a1: v1, a2: v7, a3: v5, a4: 0);
  v8 = *v7;
  v9 = v5 - 1;
  v10 = v7 + 1;
  if ( v9 <= 0 )
    v10 = nullptr;
  if ( v8 != 0 )
    v11 = 1;
  else
    v11 = StackTranslation_BinaryHandler(pData: v10, iDataSize: v9);
  if ( bDeleteMemory_3 != 0 )
    free(pMem: v10);
  return v11;
}

//------------------------------------------------------------------------------
// Address: 0x00415060
// Name: int Remote_CompareCommands(void const __near *,void const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Remote_CompareCommands(const char ***pElem1, const char ***pElem2)
{
  return strcmp(**pElem1, **pElem2);
}

//------------------------------------------------------------------------------
// Address: 0x004150A0
// Name: void Remote_DeleteCommands(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Remote_DeleteCommands()
{
  signed int i; // esi

  if ( g_numRemoteCommands != 0 )
  {
    for ( i = 0; i < (int)g_numRemoteCommands; ++i )
    {
      free(pMem: g_remoteCommands[i]->strCommand);
      free(pMem: g_remoteCommands[i]->strHelp);
      free(pMem: g_remoteCommands[i]);
      g_remoteCommands[i] = nullptr;
    }
    g_numRemoteCommands = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00415100
// Name: bool Remote_AddCommand(char __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl Remote_AddCommand(char *command, char *helptext)
{
  signed int v3; // esi
  char *strCommand; // edx
  char *v5; // ecx
  char v6; // al
  char *strHelp; // edx
  char *v8; // ecx
  char v9; // al

  if ( g_numRemoteCommands == 6144 )
    return 0;
  v3 = 0;
  if ( (int)g_numRemoteCommands <= 0 )
    goto LABEL_8;
  while ( _V_stricmp(s1: command, s2: g_remoteCommands[v3]->strCommand) != 0 )
  {
    if ( ++v3 >= (int)g_numRemoteCommands )
      goto LABEL_8;
  }
  if ( v3 >= (int)g_numRemoteCommands )
  {
LABEL_8:
    g_remoteCommands[g_numRemoteCommands] = (remoteCommand_t *)operator new(nSize: 8u);
    g_remoteCommands[g_numRemoteCommands]->strCommand = (char *)operator new(nSize: strlen(command) + 1);
    strCommand = g_remoteCommands[g_numRemoteCommands]->strCommand;
    v5 = command;
    do
    {
      v6 = *v5;
      *strCommand++ = *v5++;
    }
    while ( v6 != 0 );
    g_remoteCommands[g_numRemoteCommands]->strHelp = (char *)operator new(nSize: strlen(helptext) + 1);
    strHelp = g_remoteCommands[g_numRemoteCommands]->strHelp;
    v8 = helptext;
    do
    {
      v9 = *v8;
      *strHelp++ = *v8++;
    }
    while ( v9 != 0 );
    ++g_numRemoteCommands;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00415200
// Name: int rc_Version(char __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl rc_Version(char *pCommand)
{
  char *Token; // eax
  unsigned int nVersion; // [esp+4h] [ebp-4h] BYREF

  nVersion = 0;
  Token = GetToken(ppTokenStream: &pCommand);
  if ( *Token == 0 )
    return -1;
  sscanf(string: Token, format: "%x", &nVersion);
  SetActiveVersion(nVersion);
  DebugCommand(pStrFormat: "0x%8.8x = Version( 0x%8.8x )\n", 0, nVersion);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00415260
// Name: SetXboxMemory_UsingDmSendBinary
// Source: json
//------------------------------------------------------------------------------
bool __cdecl SetXboxMemory_UsingDmSendBinary(unsigned int pWriteAddress, const void *pSource, unsigned int iByteCount)
{
  void *v3; // esp
  int v4; // eax
  void *v5; // esp
  int v6; // esi
  _DWORD v8[4]; // [esp-10h] [ebp-24h] BYREF
  _BYTE v9[5]; // [esp+0h] [ebp-14h] BYREF
  _BYTE v10[3]; // [esp+5h] [ebp-Fh] BYREF
  char v11[4]; // [esp+10h] [ebp-4h] BYREF

  v3 = alloca(16);
  LOBYTE(v8[0]) = 1;
  *(_DWORD *)((char *)v8 + 1) = _byteswap_ulong(pWriteAddress);
  *(_DWORD *)((char *)&v8[1] + 1) = _byteswap_ulong(iByteCount);
  v4 = ((int (__cdecl *)(_DWORD *, int, _DWORD, _DWORD))_EncodeBinaryToString)(a1: v8, a2: 9, a3: 0, a4: 0);
  strcpy(v11, "!");
  v5 = alloca((20 - v4) & 0xFFFFFFF0);
  v8[3] = -v4;
  v8[2] = v10;
  v8[1] = 9;
  qmemcpy(v9, "XSTM!", sizeof(v9));
  v8[0] = v8;
  ((void (__cdecl *)())_EncodeBinaryToString)();
  if ( DmSendCommand(a1: g_pdmConnection, a2: v9, a3: 0, a4: 0) != 47841284 )
    return false;
  v6 = DmSendBinary(a1: g_pdmConnection, a2: pSource, a3: iByteCount);
  DmReceiveStatusResponse(a1: g_pdmConnection, a2: 0, a3: 0);
  return v6 == 47841280;
}

//------------------------------------------------------------------------------
// Address: 0x00415330
// Name: SetXboxMemory_UsingBinaryString
// Source: json
//------------------------------------------------------------------------------
bool __cdecl SetXboxMemory_UsingBinaryString(void *pWriteAddress, unsigned __int8 *pSource, unsigned int iByteCount)
{
  void *v3; // esp
  int v4; // eax
  void *v5; // esp
  int v7; // [esp-Ch] [ebp-20h]
  int v8; // [esp-8h] [ebp-1Ch]
  int v9; // [esp-4h] [ebp-18h]
  _BYTE v10[5]; // [esp+0h] [ebp-14h] BYREF
  unsigned __int8 v11[11]; // [esp+5h] [ebp-Fh] BYREF
  __int16 v12; // [esp+10h] [ebp-4h]

  v3 = alloca(iByteCount + 5);
  v10[0] = 0;
  *(_DWORD *)&v10[1] = _byteswap_ulong((unsigned int)pWriteAddress);
  memcpy(dst: v11, src: pSource, count: iByteCount);
  v4 = _EncodeBinaryToString(a1: v10, a2: iByteCount + 5, a3: 0, a4: 0, a5: v7, a6: v8, a7: v9);
  v12 = 33;
  v5 = alloca((20 - v4) & 0xFFFFFFF0);
  qmemcpy(v10, "XSTM!", sizeof(v10));
  ((void (__cdecl *)(_BYTE *, unsigned int, unsigned __int8 *, int))_EncodeBinaryToString)(
    a1: v10,
    a2: iByteCount + 5,
    a3: v11,
    a4: -v4);
  return DmSendCommand(a1: g_pdmConnection, a2: v10, a3: 0, a4: 0) == 47841280
      || SetXboxMemory_UsingDmSendBinary((unsigned int)pWriteAddress, pSource, iByteCount);
}

//------------------------------------------------------------------------------
// Address: 0x00415400
// Name: bool SetXboxMemory(void __near *,void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetXboxMemory(void *pWriteAddress, void *pSource, unsigned int iByteCount)
{
  if ( DmSetMemory(a1: pWriteAddress, a2: iByteCount, a3: pSource, a4: 0) == 47841280 )
    return 1;
  if ( iByteCount >= 0x100 )
    return SetXboxMemory_UsingDmSendBinary((unsigned int)pWriteAddress, pSource, iByteCount);
  return SetXboxMemory_UsingBinaryString(pWriteAddress, (unsigned __int8 *)pSource, iByteCount);
}

//------------------------------------------------------------------------------
// Address: 0x00415450
// Name: unsigned long Remote_NotifyPrintFunc(char const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall Remote_NotifyPrintFunc(char *pStrNotification)
{
  char *v1; // esi
  __int64 v2; // xmm0_8
  __int16 v3; // ax
  int v4; // eax
  int v5; // ebx
  unsigned int v6; // eax
  void *v7; // esp
  bool v8; // zf
  unsigned __int8 *v9; // ebx
  int v10; // esi
  unsigned __int8 *v11; // edi
  signed int v12; // ebx
  unsigned int v13; // eax
  int v14; // edx
  int v15; // ecx
  int v16; // esi
  char *v17; // edi
  unsigned int v18; // eax
  unsigned int v19; // eax
  char *v20; // edi
  unsigned __int8 *v21; // eax
  unsigned __int8 v23[12]; // [esp+0h] [ebp-1003Ch] BYREF
  char pTranslationOut[65536]; // [esp+Ch] [ebp-10030h] BYREF
  int v25; // [esp+1000Ch] [ebp-30h]
  char string[8]; // [esp+10010h] [ebp-2Ch] BYREF
  int v27; // [esp+10018h] [ebp-24h]
  unsigned __int8 *src; // [esp+10020h] [ebp-1Ch]
  TranslateStackInfo_StyleFlags_t style; // [esp+10024h] [ebp-18h]
  unsigned int v30; // [esp+10028h] [ebp-14h]
  unsigned __int8 *v31; // [esp+1002Ch] [ebp-10h]
  unsigned int v32; // [esp+10030h] [ebp-Ch]
  unsigned int rgb; // [esp+10034h] [ebp-8h] BYREF
  unsigned __int8 *str1; // [esp+10038h] [ebp-4h] BYREF
  char *s1; // [esp+10044h] [ebp+8h]

  v1 = pStrNotification;
  if ( V_strncasecmp(s1: pStrNotification, s2: "XPRT", n: 4) == 0 )
    v1 = pStrNotification + 5;
  rgb = 0;
  if ( V_strncasecmp(s1: v1, s2: "XCLR", n: 4) == 0 )
  {
    v2 = *(_QWORD *)(v1 + 4);
    v3 = *((_WORD *)v1 + 6);
    v1 += 4;
    *(_QWORD *)string = v2;
    LOWORD(v27) = v3;
    if ( (_BYTE)v2 == 91 && BYTE1(v27) == 93 )
    {
      string[0] = 32;
      *(_WORD *)((char *)&v27 + 1) = 32;
      sscanf(string, format: "%x", &rgb);
      v1 += 10;
    }
  }
  strstr(str1: (unsigned __int8 *)v1, str2: ":CSDECODE[");
  v5 = v4;
  if ( v4 != 0 )
  {
    v6 = (unsigned int)&v1[strlen(v1) + 1];
    v7 = alloca(v6 - (_DWORD)v1);
    memcpy(dst: v23, src: (unsigned __int8 *)v1, count: v6 - (_DWORD)v1);
    v8 = v23 - (unsigned __int8 *)v1 + v5 == 0;
    v9 = (unsigned __int8 *)(v23 - (unsigned __int8 *)v1 + v5);
    v31 = v9;
    s1 = (char *)v23;
    if ( !v8 )
    {
      while ( 1 )
      {
        str1 = v9 + 10;
        v10 = _DecodeBinaryFromString(a1: v9 + 10, a2: v9 + 10, a3: strlen((const char *)v9 + 10), a4: &str1);
        if ( v10 > 0 )
        {
          v11 = v9 + 11;
          style = v9[10];
          src = v9 + 11;
          v12 = _V_strlen(str: (const char *)v9 + 11);
          v13 = (unsigned int)(v10 - v12 - 2) >> 2;
          v14 = (int)&v11[v12 + 1];
          v15 = 0;
          v30 = v13;
          v25 = v14;
          if ( v13 != 0 )
          {
            do
            {
              v32 = *(_DWORD *)(v14 + 4 * v15);
              *(_DWORD *)(v14 + 4 * v15++) = _byteswap_ulong(v32);
            }
            while ( v15 != v30 );
            v13 = v30;
          }
          v16 = 0x10000;
          v17 = pTranslationOut;
          v32 = 0;
          if ( v13 != 0 )
          {
            while ( StackTranslation_TranslatePointer(
                      pAddress: *(_DWORD *)(v14 + 4 * v32),
                      pTranslationOut: v17,
                      iTranslationBufferLength: v16,
                      style) )
            {
              v18 = strlen(v17);
              v16 -= v18;
              v17 += v18;
              if ( v16 > v12 )
              {
                memcpy(dst: (unsigned __int8 *)v17, src, count: v12);
                v17 += v12;
                v16 -= v12;
              }
              v19 = v32 + 1;
              *v17 = 0;
              v32 = v19;
              if ( v19 == v30 )
                break;
              v14 = v25;
            }
          }
          v20 = &v17[-v12];
          if ( v20 >= pTranslationOut )
            *v20 = 0;
          *v31 = 0;
          PrintToQueue(rgb, strFormat: "%s%s", s1, pTranslationOut);
          s1 = (char *)++str1;
        }
        strstr(str1, str2: ":CSDECODE[");
        v31 = v21;
        if ( v21 == nullptr )
          break;
        v9 = v31;
      }
    }
    v1 = s1;
  }
  if ( v1 != nullptr )
    PrintToQueue(rgb, strFormat: "%s\n", v1);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004156B0
// Name: int rc_AddCommands(char __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl rc_AddCommands(char *commandPtr)
{
  int v1; // esi
  const char *Token; // eax
  const char *v3; // eax
  const char *v4; // eax
  unsigned __int8 *v5; // esi
  unsigned int v6; // ebx
  int v7; // edi
  char *v8; // eax
  int retAddr; // [esp+4h] [ebp-14h] BYREF
  int xboxRetVal; // [esp+8h] [ebp-10h] BYREF
  int retVal; // [esp+Ch] [ebp-Ch]
  int cmdList; // [esp+10h] [ebp-8h] BYREF
  int numCommands; // [esp+14h] [ebp-4h] BYREF

  v1 = -1;
  ConsoleWindowPrintf(rgb: 0, strFormat: "Receiving Console Commands From Game...\n");
  Token = GetToken(ppTokenStream: &commandPtr);
  if ( *Token != 0 )
  {
    sscanf(string: Token, format: "%x", &numCommands);
    v3 = GetToken(ppTokenStream: &commandPtr);
    if ( *v3 != 0 )
    {
      sscanf(string: v3, format: "%x", &cmdList);
      v4 = GetToken(ppTokenStream: &commandPtr);
      if ( *v4 != 0 )
      {
        sscanf(string: v4, format: "%x", &retAddr);
        v5 = (unsigned __int8 *)operator new(nSize: 384 * numCommands);
        memset(dst: v5, value: 0, count: 384 * numCommands);
        DmGetMemory(a1: cmdList, a2: 384 * numCommands, a3: v5, a4: 0);
        ConsoleWindowPrintf(rgb: 0, strFormat: "%d Commands...\n", numCommands);
        v6 = 0;
        v7 = 0;
        if ( numCommands > 0 )
        {
          v8 = (char *)v5;
          retVal = (int)v5;
          while ( Remote_AddCommand(command: v8, helptext: v8 + 128) != 0 )
          {
            retVal += 384;
            ++v7;
            ++v6;
            if ( v7 >= numCommands )
              goto LABEL_11;
            v8 = (char *)retVal;
          }
          ConsoleWindowPrintf(
            rgb: 0xFFu,
            strFormat: "Remote Commands Overflow!, ignoring %d commands.\n",
            numCommands - 6144);
        }
LABEL_11:
        qsort(
          base: g_remoteCommands,
          num: g_numRemoteCommands,
          width: 4u,
          comp: (int (__cdecl *)(const void *, const void *))Remote_CompareCommands);
        ConsoleWindowPrintf(rgb: 0, strFormat: "Completed.\n");
        retVal = v6;
        xboxRetVal = _byteswap_ulong(v6);
        DmSetMemory(a1: retAddr, a2: 4, a3: &xboxRetVal, a4: 0);
        DebugCommand(pStrFormat: "0x%8.8x = AddCommands( 0x%8.8x, 0x%8.8x )\n", v6, numCommands, cmdList);
        free(pMem: v5);
        v1 = 0;
        PostMessageA(hWnd: g_hDlgMain, Msg: 0x401u, wParam: 0, lParam: 0);
      }
    }
  }
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x00415860
// Name: unsigned long Remote_NotifyCommandFunc(char const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall Remote_NotifyCommandFunc(char *strNotification)
{
  const char *v1; // ebx
  int v2; // edi
  const char *Token; // eax
  const char *v4; // esi
  const char *v5; // eax
  const char *v6; // esi
  const char *v7; // eax
  const char *v8; // esi
  char string[260]; // [esp+Ch] [ebp-104h] BYREF

  v1 = strNotification + 5;
  strNotification += 5;
  v2 = -1;
  Token = GetToken(ppTokenStream: &strNotification);
  v4 = Token;
  if ( Token == nullptr )
    goto LABEL_56;
  if ( _V_stricmp(s1: Token, s2: "AddCommands()") != 0 )
  {
    if ( _V_stricmp(s1: v4, s2: "SetProfile()") == 0 )
    {
      v5 = GetToken(ppTokenStream: &strNotification);
      v6 = v5;
      if ( v5 != nullptr )
      {
        if ( _V_stricmp(s1: v5, s2: "cpu") != 0 )
        {
          if ( _V_stricmp(s1: v6, s2: "texture") == 0 )
            v2 = rc_SetTexProfile(commandPtr: strNotification);
        }
        else
        {
          v2 = rc_SetCpuProfile(commandPtr: strNotification);
        }
      }
      goto LABEL_57;
    }
    if ( _V_stricmp(s1: v4, s2: "SetProfileData()") == 0 )
    {
      v7 = GetToken(ppTokenStream: &strNotification);
      v8 = v7;
      if ( v7 != nullptr )
      {
        if ( _V_stricmp(s1: v7, s2: "cpu") == 0 )
        {
          rc_SetCpuProfileData(commandPtr: strNotification);
          return 0;
        }
        if ( _V_stricmp(s1: v8, s2: "texture") == 0 )
        {
          rc_SetTexProfileData(commandPtr: strNotification);
          return 0;
        }
      }
      return 0;
    }
    if ( _V_stricmp(s1: v4, s2: "TextureList()") == 0 )
    {
      v2 = rc_TextureList(commandPtr: strNotification);
      g_texturesAquired = 2;
      goto LABEL_57;
    }
    if ( _V_stricmp(s1: v4, s2: "MaterialList()") == 0 )
    {
      v2 = rc_MaterialList(commandPtr: strNotification);
      goto LABEL_57;
    }
    if ( _V_stricmp(s1: v4, s2: "SoundList()") == 0 )
    {
      v2 = rc_SoundList(commandPtr: strNotification);
      goto LABEL_57;
    }
    if ( _V_stricmp(s1: v4, s2: "ModelList()") == 0 )
    {
      v2 = rc_ModelList(commandPtr: strNotification);
      g_modelsAquired = 2;
      goto LABEL_57;
    }
    if ( _V_stricmp(s1: v4, s2: "DataCacheList()") == 0 )
    {
      v2 = rc_DataCacheList(pCommand: strNotification);
      g_cachedModelsAquired = 2;
      goto LABEL_57;
    }
    if ( _V_stricmp(s1: v4, s2: "VProfNodeList()") == 0 )
    {
      v2 = rc_VProfNodeList(pCommand: strNotification);
      goto LABEL_57;
    }
    if ( _V_stricmp(s1: v4, s2: "TimeStampLog()") == 0 )
    {
      v2 = rc_TimeStampLog(commandPtr: strNotification);
      goto LABEL_57;
    }
    if ( _V_stricmp(s1: v4, s2: "MemDump()") == 0 )
    {
      rc_MemDump(pCommand: strNotification);
      return 0;
    }
    if ( _V_stricmp(s1: v4, s2: "MapInfo()") == 0 )
    {
      v2 = rc_MapInfo(commandPtr: strNotification);
      goto LABEL_57;
    }
    if ( _V_stricmp(s1: v4, s2: "Assert()") == 0 )
    {
      v2 = rc_Assert(commandPtr: strNotification);
      goto LABEL_57;
    }
    if ( _V_stricmp(s1: v4, s2: "FreeMemory()") == 0 )
    {
      rc_FreeMemory(commandPtr: strNotification);
      return 0;
    }
    if ( _V_stricmp(s1: v4, s2: "Disconnect()") == 0 )
    {
      CommandCompleted(errCode: 0);
      DoDisconnect(bKeepConnection: 1, waitTime: 15);
      return 0;
    }
    if ( _V_stricmp(s1: v4, s2: "TraceComplete()") == 0 )
    {
      rc_TraceComplete(pCommand: strNotification);
      return 0;
    }
    if ( _V_stricmp(s1: v4, s2: "BugReporter()") == 0 )
    {
      rc_BugReporter();
      return 0;
    }
    if ( _V_stricmp(s1: v4, s2: "SyncShaderCache()") == 0 )
    {
      if ( SyncShaderCache(bForce: false) )
        v2 = 0;
      goto LABEL_57;
    }
    if ( _V_stricmp(s1: v4, s2: "SyncDvdDevCache()") == 0 )
    {
      if ( SyncDvdDevCache(bForce: false) )
        v2 = 0;
      goto LABEL_57;
    }
    if ( _V_stricmp(s1: v4, s2: "Version()") == 0 )
    {
      rc_Version(pCommand: strNotification);
      return 0;
    }
    if ( _V_stricmp(s1: v4, s2: "PublishPerfSaves()") == 0 )
    {
      PerfSaves_Publish();
      v2 = 0;
      goto LABEL_57;
    }
    if ( _V_stricmp(s1: v4, s2: "BudgetInfo()") == 0 )
    {
      v2 = rc_ShowBudget(commandPtr: strNotification);
      g_bspAquired = 2;
      goto LABEL_57;
    }
LABEL_56:
    PrintToQueue(rgb: 0xFFu, strFormat: "Unknown Command: %s\n", v1);
    goto LABEL_57;
  }
  v2 = rc_AddCommands(commandPtr: strNotification);
LABEL_57:
  sprintf(string, format: "%s!__complete__%d", "XCMD", v2);
  DmAPI_SendCommand(strCommand: string, wait: true);
  return 0;
}
