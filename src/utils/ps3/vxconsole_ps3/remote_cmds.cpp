// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/ps3/vxconsole_ps3/remote_cmds.cpp
// Functions: 14
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00409D70
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
// Address: 0x00409DF0
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
// Address: 0x00409EC0
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
// Address: 0x00409F00
// Name: void DebugCommand(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void DebugCommand(const char *pStrFormat, ...)
{
  char buffer[512]; // [esp+0h] [ebp-200h] BYREF
  va_list ap; // [esp+20Ch] [ebp+Ch] BYREF

  va_start(ap, pStrFormat);
  if ( g_debugCommands != 0 )
  {
    _vsnprintf(string: buffer, count: 0x200u, format: pStrFormat, ap);
    PrintToQueue(rgb: 0x8000u, strFormat: "[CMD]: %s", buffer);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409F50
// Name: unsigned long Remote_NotifyPrintFunc(char const __near *,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl Remote_NotifyPrintFunc(char *pStrNotification, unsigned int nDataLength, bool bTerminalNewline)
{
  char *v3; // edi
  __int64 v4; // xmm0_8
  __int16 v5; // ax
  unsigned int v6; // ebx
  void *v7; // esp
  unsigned __int8 *v8; // esi
  const char *v9; // eax
  unsigned __int8 v11[12]; // [esp+0h] [ebp-20h] BYREF
  char buff[16]; // [esp+Ch] [ebp-14h] BYREF
  int color; // [esp+1Ch] [ebp-4h] BYREF

  v3 = pStrNotification;
  if ( V_strncasecmp(s1: pStrNotification, s2: "XPRT", n: 4) == 0 )
    v3 = pStrNotification + 5;
  color = 0;
  if ( V_strncasecmp(s1: v3, s2: "XCLR", n: 4) == 0 )
  {
    v4 = *(_QWORD *)(v3 + 4);
    v5 = *((_WORD *)v3 + 6);
    v3 += 4;
    *(_QWORD *)buff = v4;
    *(_WORD *)&buff[8] = v5;
    if ( (_BYTE)v4 == 91 && buff[9] == 93 )
    {
      buff[0] = 32;
      strcpy(&buff[9], " ");
      sscanf(string: buff, format: "%x", &color);
      v3 += 10;
    }
  }
  v6 = _V_strlen(str: v3);
  v7 = alloca(v6 + 1);
  v8 = v11;
  memcpy(dst: v11, src: (unsigned __int8 *)v3, count: v6);
  v11[v6] = 0;
  v9 = (const char *)v11;
  if ( v11[0] != 0 )
  {
    do
    {
      if ( *v8 == 10 )
      {
        *v8++ = 0;
        PrintToQueue(rgb: color, strFormat: "%s\n", v9);
        v9 = (const char *)v8;
      }
      ++v8;
    }
    while ( *v8 != 0 );
    if ( v9 != (const char *)v8 )
      PrintToQueue(rgb: color, strFormat: "%s", v9);
  }
  if ( bTerminalNewline )
    PrintToQueue(rgb: color, strFormat: "\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040A070
// Name: unsigned long Remote_NotifyPrintFunc(char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall Remote_NotifyPrintFunc(char *pStrNotification, unsigned int nDataLength)
{
  return Remote_NotifyPrintFunc(pStrNotification, nDataLength, bTerminalNewline: false);
}

//------------------------------------------------------------------------------
// Address: 0x0040A090
// Name: unsigned long Remote_NotifyPrintFunc(class CUtlString const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall Remote_NotifyPrintFunc(CUtlString *pStrNotification)
{
  unsigned int v1; // edi
  char *v2; // eax

  v1 = CUtlString::Length(this: pStrNotification);
  v2 = (char *)CUtlString::Get(this: pStrNotification);
  return Remote_NotifyPrintFunc(pStrNotification: v2, nDataLength: v1, bTerminalNewline: false);
}

//------------------------------------------------------------------------------
// Address: 0x0040A0C0
// Name: unsigned long Remote_NotifyPrintIffVerboseFunc(char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall Remote_NotifyPrintIffVerboseFunc(char *pStrNotification, unsigned int nDataLength)
{
  if ( g_bVerbosePrinting != 0 )
    return Remote_NotifyPrintFunc(pStrNotification, nDataLength, bTerminalNewline: true);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040A0F0
// Name: unsigned long Remote_NotifyPerfFunc(char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall Remote_NotifyPerfFunc(const char *pStrNotification, unsigned int nDataLength)
{
  if ( g_bPlayTestMode != 0 )
    PerfmonPrintf(strFormat: pStrNotification + 5);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040A120
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
// Address: 0x0040A180
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

  if ( g_numRemoteCommands == 4096 )
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
// Address: 0x0040A280
// Name: int rc_AddCommands(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl rc_AddCommands(char *commandPtr, int nDataPacketSize)
{
  char *v3; // edi
  const char *v4; // esi
  char *v5; // ecx
  char *v6; // eax
  int numCommands; // [esp+4h] [ebp-4h] BYREF

  numCommands = 0;
  ConsoleWindowPrintf(rgb: 0, strFormat: "Receiving Console Commands From Game...");
  sscanf(string: commandPtr, format: "AddCommandsPS3(%d)", &numCommands);
  if ( numCommands >= 1 )
  {
    v3 = &commandPtr[nDataPacketSize];
    commandPtr[nDataPacketSize - 1] = 0;
    v4 = &commandPtr[_V_strlen(str: commandPtr) + 1];
    if ( v4 != nullptr )
    {
      while ( v4 < v3 )
      {
        v5 = (char *)v4;
        if ( *v4 != 9 )
        {
          while ( v4 < v3 )
          {
            if ( *v4 == 0 )
            {
              ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "Parsing failure: %s has no tab character.", v4);
              return -1;
            }
            if ( *++v4 == 9 )
              goto LABEL_9;
          }
LABEL_15:
          ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "AddCommands() parsing failure: overran buffer.", v4);
          break;
        }
LABEL_9:
        if ( v4 >= v3 )
          goto LABEL_15;
        *v4 = 0;
        v6 = (char *)(v4 + 1);
        v4 = &v6[strlen(v6) + 1];
        if ( v4 >= v3 )
          v4 = nullptr;
        Remote_AddCommand(command: v5, helptext: v6);
        if ( v4 == nullptr )
          break;
      }
    }
    if ( g_bPlayTestMode != 0 && g_connectionState == kCONNECTEDAPP )
    {
      ProcessCommand(strCmdIn: "developer 1");
      ProcessCommand(strCmdIn: "exec playtest.ps3.cfg");
    }
    return 0;
  }
  else
  {
    ConsoleWindowPrintf(rgb: 0xFFu, strFormat: "%s means added no commands.", commandPtr);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040A3A0
// Name: int rc_AddCommand(char __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl rc_AddCommand(char *commandPtr)
{
  const char *Token; // eax
  char help[1024]; // [esp+0h] [ebp-440h] BYREF
  char name[64]; // [esp+400h] [ebp-40h] BYREF

  Token = GetToken(ppTokenStream: &commandPtr);
  V_strncpy(pDest: name, pSrc: Token, maxLen: 64);
  V_strncpy(pDest: help, pSrc: commandPtr, maxLen: 1024);
  Remote_AddCommand(command: name, helptext: help);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040A3F0
// Name: unsigned long Remote_NotifyCommandFunc(char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall Remote_NotifyCommandFunc(char *strNotification, unsigned int nDataLength)
{
  char *v2; // edi
  const char *v3; // ebx
  char *v4; // edi
  unsigned __int8 *Token; // eax
  char *v6; // esi
  char *v7; // edi
  unsigned int v8; // ebx
  int v9; // eax
  int v10; // eax
  int v11; // eax
  char *i; // esi
  char string[260]; // [esp+Ch] [ebp-110h] BYREF
  const char *pOriginalBufferStart; // [esp+110h] [ebp-Ch]
  char *commandPtr; // [esp+114h] [ebp-8h] BYREF
  int errCode; // [esp+118h] [ebp-4h]

  v2 = strNotification;
  if ( g_bVerbosePrinting != 0 )
    Remote_NotifyPrintFunc(pStrNotification: strNotification, nDataLength, bTerminalNewline: false);
  v3 = v2;
  v4 = v2 + 5;
  pOriginalBufferStart = v3;
  strNotification = v4;
  commandPtr = v4;
  errCode = -1;
  Token = (unsigned __int8 *)GetToken(ppTokenStream: &commandPtr);
  v6 = (char *)Token;
  if ( Token == nullptr )
    goto LABEL_49;
  v7 = commandPtr;
  v8 = nDataLength + v3 - commandPtr;
  strstr(str1: Token, str2: "AddCommandsPS3");
  if ( v9 == 0 )
  {
    if ( _V_stricmp(s1: v6, s2: "AddCommand()") == 0 )
    {
      errCode = rc_AddCommand(commandPtr: v7);
      goto LABEL_50;
    }
    strstr(str1: (unsigned __int8 *)v6, str2: "SetProfilePS3");
    if ( v10 != 0 )
    {
      if ( sscanf(string: v6, format: "SetProfilePS3(%d)", &strNotification) >= 1 )
      {
        for ( ; *v7 == 32; ++v7 )
          ;
        if ( _V_stricmp(s1: v7, s2: "cpu") != 0 )
        {
          if ( _V_stricmp(s1: v7, s2: "texture") == 0 )
            errCode = rc_SetTexProfile(commandPtr: v7 + 8);
        }
        else
        {
          errCode = rc_SetCpuProfile(data: (unsigned __int8 *)v7 + 4, nPayloadSize: (unsigned int)strNotification);
        }
      }
      goto LABEL_50;
    }
    strstr(str1: (unsigned __int8 *)v6, str2: "SetProfileDataPS3");
    if ( v11 != 0 )
    {
      if ( sscanf(string: v6, format: "SetProfileDataPS3(%d)", &strNotification) >= 1 )
      {
        for ( i = v7; *i == 32; ++i )
          ;
        if ( _V_stricmp(s1: i, s2: "cpu") != 0 )
        {
          if ( _V_stricmp(s1: i, s2: "texture") == 0 )
            errCode = rc_SetTexProfileData(commandPtr: i + 8);
        }
        else
        {
          errCode = rc_SetCpuProfileData(
                      data: (unsigned __int8 *)i + 4,
                      nPayloadSize: nDataLength + pOriginalBufferStart - (i + 4));
        }
      }
      goto LABEL_50;
    }
    if ( _V_stricmp(s1: v6, s2: "TextureList()") == 0 )
    {
      errCode = rc_TextureList(commandPtr: v7);
      goto LABEL_50;
    }
    if ( _V_stricmp(s1: v6, s2: "MaterialList()") == 0 )
    {
      errCode = rc_MaterialList(commandPtr: v7, nDataLength: v8);
      goto LABEL_50;
    }
    if ( _V_stricmp(s1: v6, s2: "SoundList()") == 0 )
    {
      errCode = rc_SoundList(commandPtr: v7, nDataLength: v8);
      goto LABEL_50;
    }
    if ( _V_stricmp(s1: v6, s2: "ModelList()") == 0 )
    {
      errCode = rc_ModelList(commandPtr: v7, nDataLength: v8);
      goto LABEL_50;
    }
    if ( _V_stricmp(s1: v6, s2: "TimeStampLog()") == 0 )
    {
      errCode = rc_TimeStampLog(commandPtr: v7);
      goto LABEL_50;
    }
    if ( _V_stricmp(s1: v6, s2: "MemDump()") == 0 )
    {
      rc_MemDump(pCommand: v7);
      return 0;
    }
    if ( _V_stricmp(s1: v6, s2: "MapInfo()") == 0 )
    {
      errCode = rc_MapInfo(commandPtr: v7);
      goto LABEL_50;
    }
    if ( _V_stricmp(s1: v6, s2: "Screenshot()") == 0 )
    {
      errCode = rc_Screenshot(commandPtr: v7);
      goto LABEL_50;
    }
    if ( _V_stricmp(s1: v6, s2: "Assert()") == 0 )
    {
      errCode = rc_Assert(commandPtr: v7);
      goto LABEL_50;
    }
    if ( _V_stricmp(s1: v6, s2: "FreeMemory()") == 0 )
    {
      rc_FreeMemory(commandPtr: v7);
      return 0;
    }
    if ( _V_stricmp(s1: v6, s2: "Disconnect()") == 0 )
    {
      CommandCompleted(errCode: 0);
      jpeg_mem_term(cinfo: (jpeg_common_struct *)1);
      return 0;
    }
    if ( _V_stricmp(s1: v6, s2: "PublishPerfSaves()") == 0 )
    {
      PerfSaves_Publish();
      errCode = 0;
      goto LABEL_50;
    }
    v4 = strNotification;
LABEL_49:
    PrintToQueue(rgb: 0xFFu, strFormat: "Unknown Command: %s\n", v4);
    goto LABEL_50;
  }
  errCode = rc_AddCommands(commandPtr: strNotification, nDataPacketSize: nDataLength - 5);
LABEL_50:
  sprintf(string, format: "%s!__complete__%d", "XCMD", errCode);
  DmAPI_SendCommand(strCommand: string, wait: true);
  return 0;
}
