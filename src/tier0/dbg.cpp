// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tier0/dbg.cpp
// Functions: 29
// ============================================================

#include "tier0\dbg.h"

//------------------------------------------------------------------------------
// Address: 0x100038D0
// Name: public: class Color CLoggingSystem::GetChannelColor(int)const
// Source: json
//------------------------------------------------------------------------------
Color *__thiscall CLoggingSystem::GetChannelColor(CLoggingSystem *this, Color *result, int channelID)
{
  Color m_SpewColor; // ecx

  m_SpewColor = CLoggingSystem::GetChannel(this, channelID)->m_SpewColor;
  *result = m_SpewColor;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100038F0
// Name: float fabs(float)
// Source: json
//------------------------------------------------------------------------------
long double __cdecl fabs(float _X)
{
  return fabs(_X);
}

//------------------------------------------------------------------------------
// Address: 0x100039E0
// Name: void AppendCallStackToLogMessage(char __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AppendCallStackToLogMessage(char *formattedMessage, int iMessageLength, int iAppendCallStackLength)
{
  void *v3; // esp
  const char *v4; // [esp+0h] [ebp-34h] BYREF
  int v5; // [esp+8h] [ebp-2Ch]
  const char *v6; // [esp+Ch] [ebp-28h]
  const char **v7; // [esp+10h] [ebp-24h]
  int v8; // [esp+14h] [ebp-20h]
  char *v9; // [esp+1Ch] [ebp-18h]
  char *v10; // [esp+20h] [ebp-14h]
  int iCount; // [esp+24h] [ebp-10h]
  int iExistingMessageLength; // [esp+28h] [ebp-Ch]
  void **CallStackBuffer; // [esp+2Ch] [ebp-8h]
  int iAppendedLength; // [esp+30h] [ebp-4h]
  char *formattedMessagea; // [esp+3Ch] [ebp+8h]
  signed int iMessageLengtha; // [esp+40h] [ebp+Ch]

  if ( iAppendCallStackLength > 0 )
  {
    v9 = formattedMessage + 1;
    v10 = &formattedMessage[strlen(formattedMessage) + 1];
    v8 = v10 - v9;
    iExistingMessageLength = v10 - (formattedMessage + 1);
    formattedMessagea = v10 - 1;
    iMessageLengtha = iMessageLength - (v10 - v9);
    if ( iMessageLengtha > 32 )
    {
      if ( iExistingMessageLength > 0 && *(v10 - 2) == 10 )
      {
        formattedMessagea = v10 - 2;
        ++iMessageLengtha;
      }
      iAppendedLength = _snprintf(string: formattedMessagea, count: iMessageLengtha, format: "\nCall Stack:\n\t");
      v3 = alloca(4 * iAppendCallStackLength);
      v7 = &v4;
      CallStackBuffer = (void **)&v4;
      iCount = GetCallStack(pReturnAddressesOut: (void **)&v4, iArrayCount: iAppendCallStackLength, iSkipCount: 2);
      if ( TranslateStackInfo(
             pCallStack: (const void *const *)CallStackBuffer,
             iCallStackCount: iCount,
             szOutput: &formattedMessagea[iAppendedLength],
             iOutBufferSize: iMessageLengtha - iAppendedLength,
             szEntrySeparator: "\n\t",
             style: TSISTYLEFLAG_DEFAULT) != 0 )
      {
        v6 = &formattedMessagea[iAppendedLength];
        v5 = (int)&formattedMessagea[iAppendedLength + 1];
        v6 += strlen(v6);
        v4 = &(++v6)[-v5];
        iAppendedLength = v6 - (formattedMessagea + 1);
        if ( iAppendedLength < iMessageLengtha )
        {
          formattedMessagea[iAppendedLength] = 10;
          formattedMessagea[++iAppendedLength] = 0;
        }
      }
      else
      {
        *formattedMessagea = 0;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003B40
// Name: _CrackSmokingCompiler
// Source: json
//------------------------------------------------------------------------------
long double __cdecl CrackSmokingCompiler(float a)
{
  return fabs(_X: a);
}

//------------------------------------------------------------------------------
// Address: 0x10003B60
// Name: _Plat_SimpleLog
// Source: json
//------------------------------------------------------------------------------
void *__cdecl Plat_SimpleLog(const char *file, int line)
{
  _iobuf *f; // [esp+0h] [ebp-4h]

  f = fopen(file: "simple.log", mode: "at+");
  fprintf(str: f, format: "%s:%i\n", file, line);
  fclose(stream: f);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10003BB0
// Name: public: static void CHardwareBreakPoint::SetBits(unsigned long __near &,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CHardwareBreakPoint::SetBits(unsigned int *dw, char lowBit, char bits, int newValue)
{
  *dw = (newValue << lowBit) | *dw & ~(((1 << bits) - 1) << lowBit);
}

//------------------------------------------------------------------------------
// Address: 0x10003BF0
// Name: public: static unsigned long CHardwareBreakPoint::ThreadProc(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall CHardwareBreakPoint::ThreadProc(HANDLE *lpParameter)
{
  int st; // [esp+0h] [ebp-2E8h]
  int le; // [esp+4h] [ebp-2E4h]
  int Dr1Busy; // [esp+Bh] [ebp-2DDh]
  _CONTEXT ct; // [esp+18h] [ebp-2D0h] BYREF

  SuspendThread(hThread: lpParameter[1]);
  memset(dst: (unsigned __int8 *)&ct.Dr0, value: 0, count: 0x2C8u);
  ct.ContextFlags = 65552;
  GetThreadContext(hThread: lpParameter[1], lpContext: &ct);
  Dr1Busy = (ct.Dr7 & 4) != 0;
  if ( lpParameter[6] == HANDLE_FLAG_INHERIT )
  {
    if ( lpParameter[5] == nullptr )
    {
      BYTE1(Dr1Busy) = 0;
      ct.Dr0 = 0;
    }
    if ( lpParameter[5] == HANDLE_FLAG_INHERIT )
    {
      BYTE1(Dr1Busy) = 2;
      ct.Dr1 = 0;
    }
    if ( lpParameter[5] == HANDLE_FLAG_PROTECT_FROM_CLOSE )
    {
      BYTE1(Dr1Busy) = 4;
      ct.Dr2 = 0;
    }
    if ( lpParameter[5] == HANDLE_FLAG_PROTECT_FROM_CLOSE|HANDLE_FLAG_INHERIT )
    {
      BYTE1(Dr1Busy) = 6;
      ct.Dr3 = 0;
    }
    ct.Dr7 &= ~(1 << SBYTE1(Dr1Busy));
  }
  else
  {
    if ( (ct.Dr7 & 1) != 0 )
    {
      if ( (ct.Dr7 & 4) != 0 )
      {
        if ( (ct.Dr7 & 0x10) != 0 )
        {
          if ( (ct.Dr7 & 0x40) != 0 )
          {
            *((_BYTE *)lpParameter + 28) = 0;
            ResumeThread(hThread: lpParameter[1]);
            SetEvent(hEvent: lpParameter[4]);
            return 0;
          }
          lpParameter[5] = HANDLE_FLAG_PROTECT_FROM_CLOSE|HANDLE_FLAG_INHERIT;
          ct.Dr3 = (unsigned int)*lpParameter;
        }
        else
        {
          lpParameter[5] = HANDLE_FLAG_PROTECT_FROM_CLOSE;
          ct.Dr2 = (unsigned int)*lpParameter;
        }
      }
      else
      {
        lpParameter[5] = HANDLE_FLAG_INHERIT;
        ct.Dr1 = (unsigned int)*lpParameter;
      }
    }
    else
    {
      lpParameter[5] = nullptr;
      ct.Dr0 = (unsigned int)*lpParameter;
    }
    ct.Dr6 = 0;
    st = 0;
    if ( lpParameter[2] == nullptr )
      st = 0;
    if ( lpParameter[2] == HANDLE_FLAG_PROTECT_FROM_CLOSE )
      st = 3;
    if ( lpParameter[2] == HANDLE_FLAG_INHERIT )
      st = 1;
    le = 0;
    if ( lpParameter[3] == HANDLE_FLAG_INHERIT )
      le = 0;
    if ( lpParameter[3] == HANDLE_FLAG_PROTECT_FROM_CLOSE )
      le = 1;
    if ( lpParameter[3] == (HANDLE)4 )
      le = 3;
    if ( lpParameter[3] == (HANDLE)8 )
      le = 2;
    CHardwareBreakPoint::SetBits(dw: &ct.Dr7, lowBit: 4 * (unsigned __int8)lpParameter[5] + 16, bits: 2, newValue: st);
    CHardwareBreakPoint::SetBits(dw: &ct.Dr7, lowBit: 4 * (unsigned __int8)lpParameter[5] + 18, bits: 2, newValue: le);
    CHardwareBreakPoint::SetBits(dw: &ct.Dr7, lowBit: 2 * (unsigned __int8)lpParameter[5], bits: 1, newValue: 1);
  }
  ct.ContextFlags = 65552;
  SetThreadContext(hThread: lpParameter[1], lpContext: &ct);
  ResumeThread(hThread: lpParameter[1]);
  *((_BYTE *)lpParameter + 28) = 1;
  SetEvent(hEvent: lpParameter[4]);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10004000
// Name: _SetHardwareBreakpoint
// Source: json
//------------------------------------------------------------------------------
_DWORD *__cdecl SetHardwareBreakpoint(
        EHardwareBreakpointType eType,
        EHardwareBreakpointSize eSize,
        const void *pvLocation)
{
  _DWORD *v4; // [esp+0h] [ebp-18h]
  _DWORD *v5; // [esp+8h] [ebp-10h]
  unsigned int nThreadId; // [esp+Ch] [ebp-Ch]
  HANDLE hThread; // [esp+10h] [ebp-8h]

  v5 = operator new(size: 0x20u);
  if ( v5 != nullptr )
  {
    v5[6] = 0;
    *v5 = 0;
    v5[1] = 0;
    v5[4] = 0;
    v5[5] = 0;
    *((_BYTE *)v5 + 28) = 0;
    v4 = v5;
  }
  else
  {
    v4 = nullptr;
  }
  *v4 = pvLocation;
  v4[3] = eSize;
  v4[2] = eType;
  hThread = GetCurrentThread();
  v4[1] = hThread;
  if ( hThread == GetCurrentThread() )
  {
    nThreadId = GetCurrentThreadId();
    v4[1] = OpenThread(dwDesiredAccess: 0x1FFFFFu, bInheritHandle: false, dwThreadId: nThreadId);
  }
  v4[4] = CreateEventA(lpEventAttributes: nullptr, bManualReset: false, bInitialState: false, lpName: nullptr);
  v4[6] = 0;
  CreateThread(
    lpThreadAttributes: nullptr,
    dwStackSize: 0,
    lpStartAddress: (LPTHREAD_START_ROUTINE)CHardwareBreakPoint::ThreadProc,
    lpParameter: v4,
    dwCreationFlags: 0,
    lpThreadId: nullptr);
  WaitForSingleObject(hHandle: (HANDLE)v4[4], dwMilliseconds: 0xFFFFFFFF);
  CloseHandle(hObject: (HANDLE)v4[4]);
  v4[4] = 0;
  if ( hThread == GetCurrentThread() )
    CloseHandle(hObject: (HANDLE)v4[1]);
  v4[1] = hThread;
  if ( *((_BYTE *)v4 + 28) != 0 )
    return v4;
  operator delete(p: v4);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10004170
// Name: _ClearHardwareBreakpoint
// Source: json
//------------------------------------------------------------------------------
char __cdecl ClearHardwareBreakpoint(void *handle)
{
  unsigned int nThreadId; // [esp+4h] [ebp-Ch]
  bool bOpened; // [esp+Bh] [ebp-5h]

  if ( handle == nullptr )
    return 0;
  bOpened = false;
  if ( *((HANDLE *)handle + 1) == GetCurrentThread() )
  {
    nThreadId = GetCurrentThreadId();
    *((_DWORD *)handle + 1) = OpenThread(dwDesiredAccess: 0x1FFFFFu, bInheritHandle: false, dwThreadId: nThreadId);
    bOpened = true;
  }
  *((_DWORD *)handle + 4) = CreateEventA(
                              lpEventAttributes: nullptr,
                              bManualReset: false,
                              bInitialState: false,
                              lpName: nullptr);
  *((_DWORD *)handle + 6) = 1;
  CreateThread(
    lpThreadAttributes: nullptr,
    dwStackSize: 0,
    lpStartAddress: (LPTHREAD_START_ROUTINE)CHardwareBreakPoint::ThreadProc,
    lpParameter: handle,
    dwCreationFlags: 0,
    lpThreadId: nullptr);
  WaitForSingleObject(hHandle: *((HANDLE *)handle + 4), dwMilliseconds: 0xFFFFFFFF);
  CloseHandle(hObject: *((HANDLE *)handle + 4));
  *((_DWORD *)handle + 4) = 0;
  if ( bOpened )
    CloseHandle(hObject: *((HANDLE *)handle + 1));
  operator delete(p: handle);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10004250
// Name: public: bool CLoggingSystem::IsChannelEnabled(int,enum LoggingSeverity_t)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CLoggingSystem::IsChannelEnabled(CLoggingSystem *this, int channelID, LoggingSeverity_t severity)
{
  return channelID >= 0
      && channelID < this->m_nChannelCount
      && severity >= CLoggingSystem::GetChannel(this, channelID)->m_MinimumSeverity;
}

//------------------------------------------------------------------------------
// Address: 0x10004280
// Name: _Msg
// Source: json
//------------------------------------------------------------------------------
void Msg(const char *pMsgFormat, ...)
{
  Color *ChannelColor; // eax
  Color result; // [esp+0h] [ebp-80Ch] BYREF
  char formattedMessage[2048]; // [esp+4h] [ebp-808h] BYREF
  char *args; // [esp+804h] [ebp-8h]
  CLoggingSystem *pLoggingSystem; // [esp+808h] [ebp-4h]
  va_list va; // [esp+818h] [ebp+Ch] BYREF

  va_start(va, pMsgFormat);
  pLoggingSystem = GetGlobalLoggingSystem();
  if ( CLoggingSystem::IsChannelEnabled(this: pLoggingSystem, channelID: LOG_GENERAL, severity: LS_MESSAGE) )
  {
    va_copy(args, va);
    _vsnprintf(string: formattedMessage, count: 0x800u, format: pMsgFormat, ap: va);
    args = nullptr;
    AppendCallStackToLogMessage(formattedMessage, iMessageLength: 2048, iAppendCallStackLength: 0);
    ChannelColor = CLoggingSystem::GetChannelColor(this: pLoggingSystem, &result, channelID: LOG_GENERAL);
    CLoggingSystem::LogDirect(
      this: pLoggingSystem,
      channelID: LOG_GENERAL,
      severity: LS_MESSAGE,
      color: *ChannelColor,
      pMessage: formattedMessage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004330
// Name: _Warning
// Source: json
//------------------------------------------------------------------------------
void Warning(const char *pMsgFormat, ...)
{
  Color *ChannelColor; // eax
  Color result; // [esp+0h] [ebp-80Ch] BYREF
  char formattedMessage[2048]; // [esp+4h] [ebp-808h] BYREF
  char *args; // [esp+804h] [ebp-8h]
  CLoggingSystem *pLoggingSystem; // [esp+808h] [ebp-4h]
  va_list va; // [esp+818h] [ebp+Ch] BYREF

  va_start(va, pMsgFormat);
  pLoggingSystem = GetGlobalLoggingSystem();
  if ( CLoggingSystem::IsChannelEnabled(this: pLoggingSystem, channelID: LOG_GENERAL, severity: LS_WARNING) )
  {
    va_copy(args, va);
    _vsnprintf(string: formattedMessage, count: 0x800u, format: pMsgFormat, ap: va);
    args = nullptr;
    AppendCallStackToLogMessage(
      formattedMessage,
      iMessageLength: 2048,
      iAppendCallStackLength: s_bCallStacksWithAllWarnings ? s_iWarningMaxCallStackLength : 0);
    ChannelColor = CLoggingSystem::GetChannelColor(this: pLoggingSystem, &result, channelID: LOG_GENERAL);
    CLoggingSystem::LogDirect(
      this: pLoggingSystem,
      channelID: LOG_GENERAL,
      severity: LS_WARNING,
      color: *ChannelColor,
      pMessage: formattedMessage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100043F0
// Name: _Warning_SpewCallStack
// Source: json
//------------------------------------------------------------------------------
void Warning_SpewCallStack(int iMaxCallStackLength, const char *pMsgFormat, ...)
{
  Color *ChannelColor; // eax
  Color result; // [esp+0h] [ebp-80Ch] BYREF
  char formattedMessage[2048]; // [esp+4h] [ebp-808h] BYREF
  char *args; // [esp+804h] [ebp-8h]
  CLoggingSystem *pLoggingSystem; // [esp+808h] [ebp-4h]
  va_list va; // [esp+81Ch] [ebp+10h] BYREF

  va_start(va, pMsgFormat);
  pLoggingSystem = GetGlobalLoggingSystem();
  if ( CLoggingSystem::IsChannelEnabled(this: pLoggingSystem, channelID: LOG_GENERAL, severity: LS_WARNING) )
  {
    va_copy(args, va);
    _vsnprintf(string: formattedMessage, count: 0x800u, format: pMsgFormat, ap: va);
    args = nullptr;
    AppendCallStackToLogMessage(formattedMessage, iMessageLength: 2048, iAppendCallStackLength: iMaxCallStackLength);
    ChannelColor = CLoggingSystem::GetChannelColor(this: pLoggingSystem, &result, channelID: LOG_GENERAL);
    CLoggingSystem::LogDirect(
      this: pLoggingSystem,
      channelID: LOG_GENERAL,
      severity: LS_WARNING,
      color: *ChannelColor,
      pMessage: formattedMessage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100044A0
// Name: _Error
// Source: json
//------------------------------------------------------------------------------
void Error(const char *pMsgFormat, ...)
{
  Color *ChannelColor; // eax
  Color result; // [esp+0h] [ebp-80Ch] BYREF
  char formattedMessage[2048]; // [esp+4h] [ebp-808h] BYREF
  char *args; // [esp+804h] [ebp-8h]
  CLoggingSystem *pLoggingSystem; // [esp+808h] [ebp-4h]
  va_list va; // [esp+818h] [ebp+Ch] BYREF

  va_start(va, pMsgFormat);
  pLoggingSystem = GetGlobalLoggingSystem();
  if ( CLoggingSystem::IsChannelEnabled(this: pLoggingSystem, channelID: LOG_GENERAL, severity: LS_ERROR) )
  {
    va_copy(args, va);
    _vsnprintf(string: formattedMessage, count: 0x800u, format: pMsgFormat, ap: va);
    args = nullptr;
    AppendCallStackToLogMessage(
      formattedMessage,
      iMessageLength: 2048,
      iAppendCallStackLength: s_bCallStacksWithAllErrors ? s_iErrorMaxCallStackLength : 0);
    ChannelColor = CLoggingSystem::GetChannelColor(this: pLoggingSystem, &result, channelID: LOG_GENERAL);
    CLoggingSystem::LogDirect(
      this: pLoggingSystem,
      channelID: LOG_GENERAL,
      severity: LS_ERROR,
      color: *ChannelColor,
      pMessage: formattedMessage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004560
// Name: _Error_SpewCallStack
// Source: json
//------------------------------------------------------------------------------
void Error_SpewCallStack(int iMaxCallStackLength, const char *pMsgFormat, ...)
{
  Color *ChannelColor; // eax
  Color result; // [esp+0h] [ebp-80Ch] BYREF
  char formattedMessage[2048]; // [esp+4h] [ebp-808h] BYREF
  char *args; // [esp+804h] [ebp-8h]
  CLoggingSystem *pLoggingSystem; // [esp+808h] [ebp-4h]
  va_list va; // [esp+81Ch] [ebp+10h] BYREF

  va_start(va, pMsgFormat);
  pLoggingSystem = GetGlobalLoggingSystem();
  if ( CLoggingSystem::IsChannelEnabled(this: pLoggingSystem, channelID: LOG_GENERAL, severity: LS_ERROR) )
  {
    va_copy(args, va);
    _vsnprintf(string: formattedMessage, count: 0x800u, format: pMsgFormat, ap: va);
    args = nullptr;
    AppendCallStackToLogMessage(formattedMessage, iMessageLength: 2048, iAppendCallStackLength: iMaxCallStackLength);
    ChannelColor = CLoggingSystem::GetChannelColor(this: pLoggingSystem, &result, channelID: LOG_GENERAL);
    CLoggingSystem::LogDirect(
      this: pLoggingSystem,
      channelID: LOG_GENERAL,
      severity: LS_ERROR,
      color: *ChannelColor,
      pMessage: formattedMessage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004610
// Name: _DevMsg
// Source: json
//------------------------------------------------------------------------------
void DevMsg(int level, const char *pMsgFormat, ...)
{
  Color *ChannelColor; // eax
  int v3; // [esp+0h] [ebp-818h]
  Color result; // [esp+4h] [ebp-814h] BYREF
  char formattedMessage[2052]; // [esp+8h] [ebp-810h] BYREF
  char *args; // [esp+80Ch] [ebp-Ch]
  CLoggingSystem *pLoggingSystem; // [esp+810h] [ebp-8h]
  int channel; // [esp+814h] [ebp-4h]
  va_list va; // [esp+828h] [ebp+10h] BYREF

  va_start(va, pMsgFormat);
  if ( level < 2 )
    v3 = LOG_DEVELOPER;
  else
    v3 = LOG_DEVELOPER_VERBOSE;
  channel = v3;
  pLoggingSystem = GetGlobalLoggingSystem();
  if ( CLoggingSystem::IsChannelEnabled(this: pLoggingSystem, channelID: v3, severity: LS_MESSAGE) )
  {
    va_copy(args, va);
    _vsnprintf(string: formattedMessage, count: 0x800u, format: pMsgFormat, ap: va);
    args = nullptr;
    AppendCallStackToLogMessage(formattedMessage, iMessageLength: 2048, iAppendCallStackLength: 0);
    ChannelColor = CLoggingSystem::GetChannelColor(this: pLoggingSystem, &result, channelID: channel);
    CLoggingSystem::LogDirect(
      this: pLoggingSystem,
      channelID: channel,
      severity: LS_MESSAGE,
      color: *ChannelColor,
      pMessage: formattedMessage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100046E0
// Name: _DevWarning
// Source: json
//------------------------------------------------------------------------------
void DevWarning(int level, const char *pMsgFormat, ...)
{
  Color *ChannelColor; // eax
  int v3; // [esp+0h] [ebp-818h]
  Color result; // [esp+4h] [ebp-814h] BYREF
  char formattedMessage[2052]; // [esp+8h] [ebp-810h] BYREF
  char *args; // [esp+80Ch] [ebp-Ch]
  CLoggingSystem *pLoggingSystem; // [esp+810h] [ebp-8h]
  int channel; // [esp+814h] [ebp-4h]
  va_list va; // [esp+828h] [ebp+10h] BYREF

  va_start(va, pMsgFormat);
  if ( level < 2 )
    v3 = LOG_DEVELOPER;
  else
    v3 = LOG_DEVELOPER_VERBOSE;
  channel = v3;
  pLoggingSystem = GetGlobalLoggingSystem();
  if ( CLoggingSystem::IsChannelEnabled(this: pLoggingSystem, channelID: v3, severity: LS_WARNING) )
  {
    va_copy(args, va);
    _vsnprintf(string: formattedMessage, count: 0x800u, format: pMsgFormat, ap: va);
    args = nullptr;
    AppendCallStackToLogMessage(formattedMessage, iMessageLength: 2048, iAppendCallStackLength: 0);
    ChannelColor = CLoggingSystem::GetChannelColor(this: pLoggingSystem, &result, channelID: channel);
    CLoggingSystem::LogDirect(
      this: pLoggingSystem,
      channelID: channel,
      severity: LS_WARNING,
      color: *ChannelColor,
      pMessage: formattedMessage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100047B0
// Name: void DevMsg(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void DevMsg(const char *pMsgFormat, ...)
{
  Color *ChannelColor; // eax
  Color result; // [esp+0h] [ebp-80Ch] BYREF
  char formattedMessage[2048]; // [esp+4h] [ebp-808h] BYREF
  char *args; // [esp+804h] [ebp-8h]
  CLoggingSystem *pLoggingSystem; // [esp+808h] [ebp-4h]
  va_list va; // [esp+818h] [ebp+Ch] BYREF

  va_start(va, pMsgFormat);
  pLoggingSystem = GetGlobalLoggingSystem();
  if ( CLoggingSystem::IsChannelEnabled(this: pLoggingSystem, channelID: LOG_DEVELOPER, severity: LS_MESSAGE) )
  {
    va_copy(args, va);
    _vsnprintf(string: formattedMessage, count: 0x800u, format: pMsgFormat, ap: va);
    args = nullptr;
    AppendCallStackToLogMessage(formattedMessage, iMessageLength: 2048, iAppendCallStackLength: 0);
    ChannelColor = CLoggingSystem::GetChannelColor(this: pLoggingSystem, &result, channelID: LOG_DEVELOPER);
    CLoggingSystem::LogDirect(
      this: pLoggingSystem,
      channelID: LOG_DEVELOPER,
      severity: LS_MESSAGE,
      color: *ChannelColor,
      pMessage: formattedMessage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004860
// Name: void DevWarning(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void DevWarning(const char *pMsgFormat, ...)
{
  Color *ChannelColor; // eax
  Color result; // [esp+0h] [ebp-80Ch] BYREF
  char formattedMessage[2048]; // [esp+4h] [ebp-808h] BYREF
  char *args; // [esp+804h] [ebp-8h]
  CLoggingSystem *pLoggingSystem; // [esp+808h] [ebp-4h]
  va_list va; // [esp+818h] [ebp+Ch] BYREF

  va_start(va, pMsgFormat);
  pLoggingSystem = GetGlobalLoggingSystem();
  if ( CLoggingSystem::IsChannelEnabled(this: pLoggingSystem, channelID: LOG_DEVELOPER, severity: LS_WARNING) )
  {
    va_copy(args, va);
    _vsnprintf(string: formattedMessage, count: 0x800u, format: pMsgFormat, ap: va);
    args = nullptr;
    AppendCallStackToLogMessage(formattedMessage, iMessageLength: 2048, iAppendCallStackLength: 0);
    ChannelColor = CLoggingSystem::GetChannelColor(this: pLoggingSystem, &result, channelID: LOG_DEVELOPER);
    CLoggingSystem::LogDirect(
      this: pLoggingSystem,
      channelID: LOG_DEVELOPER,
      severity: LS_WARNING,
      color: *ChannelColor,
      pMessage: formattedMessage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004910
// Name: void ConColorMsg(class Color const __near &,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void ConColorMsg(const Color *clr, const char *pMsgFormat, ...)
{
  char formattedMessage[2048]; // [esp+0h] [ebp-808h] BYREF
  char *args; // [esp+800h] [ebp-8h]
  CLoggingSystem *pLoggingSystem; // [esp+804h] [ebp-4h]
  va_list va; // [esp+818h] [ebp+10h] BYREF

  va_start(va, pMsgFormat);
  pLoggingSystem = GetGlobalLoggingSystem();
  if ( CLoggingSystem::IsChannelEnabled(this: pLoggingSystem, channelID: LOG_CONSOLE, severity: LS_MESSAGE) )
  {
    va_copy(args, va);
    _vsnprintf(string: formattedMessage, count: 0x800u, format: pMsgFormat, ap: va);
    args = nullptr;
    AppendCallStackToLogMessage(formattedMessage, iMessageLength: 2048, iAppendCallStackLength: 0);
    CLoggingSystem::LogDirect(
      this: pLoggingSystem,
      channelID: LOG_CONSOLE,
      severity: LS_MESSAGE,
      color: *clr,
      pMessage: formattedMessage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100049A0
// Name: void ConMsg(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void ConMsg(const char *pMsgFormat, ...)
{
  Color *ChannelColor; // eax
  Color result; // [esp+0h] [ebp-80Ch] BYREF
  char formattedMessage[2048]; // [esp+4h] [ebp-808h] BYREF
  char *args; // [esp+804h] [ebp-8h]
  CLoggingSystem *pLoggingSystem; // [esp+808h] [ebp-4h]
  va_list va; // [esp+818h] [ebp+Ch] BYREF

  va_start(va, pMsgFormat);
  pLoggingSystem = GetGlobalLoggingSystem();
  if ( CLoggingSystem::IsChannelEnabled(this: pLoggingSystem, channelID: LOG_CONSOLE, severity: LS_MESSAGE) )
  {
    va_copy(args, va);
    _vsnprintf(string: formattedMessage, count: 0x800u, format: pMsgFormat, ap: va);
    args = nullptr;
    AppendCallStackToLogMessage(formattedMessage, iMessageLength: 2048, iAppendCallStackLength: 0);
    ChannelColor = CLoggingSystem::GetChannelColor(this: pLoggingSystem, &result, channelID: LOG_CONSOLE);
    CLoggingSystem::LogDirect(
      this: pLoggingSystem,
      channelID: LOG_CONSOLE,
      severity: LS_MESSAGE,
      color: *ChannelColor,
      pMessage: formattedMessage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004A50
// Name: _ConDMsg
// Source: json
//------------------------------------------------------------------------------
void ConDMsg(const char *pMsgFormat, ...)
{
  Color *ChannelColor; // eax
  Color result; // [esp+0h] [ebp-80Ch] BYREF
  char formattedMessage[2048]; // [esp+4h] [ebp-808h] BYREF
  char *args; // [esp+804h] [ebp-8h]
  CLoggingSystem *pLoggingSystem; // [esp+808h] [ebp-4h]
  va_list va; // [esp+818h] [ebp+Ch] BYREF

  va_start(va, pMsgFormat);
  pLoggingSystem = GetGlobalLoggingSystem();
  if ( CLoggingSystem::IsChannelEnabled(this: pLoggingSystem, channelID: LOG_DEVELOPER_CONSOLE, severity: LS_MESSAGE) )
  {
    va_copy(args, va);
    _vsnprintf(string: formattedMessage, count: 0x800u, format: pMsgFormat, ap: va);
    args = nullptr;
    AppendCallStackToLogMessage(formattedMessage, iMessageLength: 2048, iAppendCallStackLength: 0);
    ChannelColor = CLoggingSystem::GetChannelColor(this: pLoggingSystem, &result, channelID: LOG_DEVELOPER_CONSOLE);
    CLoggingSystem::LogDirect(
      this: pLoggingSystem,
      channelID: LOG_DEVELOPER_CONSOLE,
      severity: LS_MESSAGE,
      color: *ChannelColor,
      pMessage: formattedMessage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004B00
// Name: _COM_TimestampedLog
// Source: json
//------------------------------------------------------------------------------
void COM_TimestampedLog(const char *fmt, ...)
{
  CCommandLine *v1; // [esp+28h] [ebp-414h]
  CCommandLine *v2; // [esp+2Ch] [ebp-410h]
  _iobuf *fp; // [esp+30h] [ebp-40Ch]
  char string[1024]; // [esp+34h] [ebp-408h] BYREF
  char *argptr; // [esp+434h] [ebp-8h]
  float curStamp; // [esp+438h] [ebp-4h]
  va_list va; // [esp+448h] [ebp+Ch] BYREF

  va_start(va, fmt);
  if ( !s_bChecked )
  {
    v2 = CommandLine();
    s_bShouldLog = v2->CheckParm(this: v2, a2: "-profile", a3: nullptr) != nullptr;
    v1 = CommandLine();
    s_bShouldLogToConsole = ((double (__thiscall *)(CCommandLine *, const char *, _DWORD))v1->ParmValue)(
                              a1: v1,
                              a2: "-profile",
                              a3: 0) != 0.0;
    s_bChecked = true;
  }
  if ( s_bShouldLog )
  {
    va_copy(argptr, va);
    _vsnprintf(string, count: 0x400u, format: fmt, ap: va);
    argptr = nullptr;
    curStamp = Plat_FloatTime();
    if ( !s_bFirstWrite )
    {
      unlink(path: "timestamped.log");
      s_bFirstWrite = true;
    }
    fp = fopen(file: "timestamped.log", mode: "at+");
    fprintf(str: fp, format: "%8.4f / %8.4f:  %s\n", curStamp, (float)(curStamp - s_LastStamp), string);
    fclose(stream: fp);
    if ( s_bShouldLogToConsole )
      Msg(pMsgFormat: "%8.4f / %8.4f:  %s\n", curStamp, (float)(curStamp - s_LastStamp), string);
    s_LastStamp = curStamp;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003900
// Name: __Warning_AlwaysSpewCallStack_Enable
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _Warning_AlwaysSpewCallStack_Enable(bool bEnable)
{
  s_bCallStacksWithAllWarnings = bEnable;
}

//------------------------------------------------------------------------------
// Address: 0x10003910
// Name: __Warning_AlwaysSpewCallStack_Length
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _Warning_AlwaysSpewCallStack_Length(int iMaxCallStackLength)
{
  s_iWarningMaxCallStackLength = iMaxCallStackLength;
}

//------------------------------------------------------------------------------
// Address: 0x10003920
// Name: __Error_AlwaysSpewCallStack_Enable
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _Error_AlwaysSpewCallStack_Enable(bool bEnable)
{
  s_bCallStacksWithAllErrors = bEnable;
}

//------------------------------------------------------------------------------
// Address: 0x10003930
// Name: __Error_AlwaysSpewCallStack_Length
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _Error_AlwaysSpewCallStack_Length(int iMaxCallStackLength)
{
  s_iErrorMaxCallStackLength = iMaxCallStackLength;
}

//------------------------------------------------------------------------------
// Address: 0x10003940
// Name: __ExitOnFatalAssert
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _ExitOnFatalAssert(const char *pFile, int line)
{
  if ( LoggingSystem_IsChannelEnabled(channelID: LOG_ASSERT, severity: LS_MESSAGE) )
    LoggingSystem_Log(
      channelID: LOG_ASSERT,
      severity: LS_MESSAGE,
      pMessageFormat: "Fatal assert failed: %s, line %d.  Application exiting.\n",
      pFile,
      line);
  if ( !Plat_IsInDebugSession() )
    WriteMiniDump();
  if ( LoggingSystem_IsChannelEnabled(channelID: LOG_DEVELOPER, severity: LS_MESSAGE) )
    LoggingSystem_Log(channelID: LOG_DEVELOPER, severity: LS_MESSAGE, pMessageFormat: "_ExitOnFatalAssert\n");
  Plat_ExitProcess(nCode: 1u);
}

//------------------------------------------------------------------------------
// Address: 0x100039D0
// Name: __AssertValidReadWritePtr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Alternative name is '_AssertValidReadPtr'
// Alternative name is '_AssertValidReadWritePtr'
// Alternative name is '_AssertValidStringPtr'
void __cdecl _AssertValidReadWritePtr()
{
  ;
}

// ============================================================
// Overlay from tier0_s (Missing functions)
// ============================================================
namespace tier0_s {

//------------------------------------------------------------------------------
// Address: 0x3F0025C0
// Name: _AssertValidStringPtr
// Source: json
//------------------------------------------------------------------------------
void __usercall AssertValidStringPtr(int a1@<ebp>)
{
  Sleep(dwMilliseconds: 0);
  if ( sub_3F002350(a1: 0, a2: 1u) != 0 )
    sub_3F002410(this: (_DWORD *)(a1 - 44), a2: 0x100000000LL);
  JUMPOUT(0x3F0025EF);
}

//------------------------------------------------------------------------------
// Address: 0x3F0025F0
// Name: _AssertValidStringPtrW
// Source: json
//------------------------------------------------------------------------------
void __usercall AssertValidStringPtrW(
        char a1@<cf>,
        int a2@<eax>,
        char a3@<cl>,
        void *_EBX@<ebx>,
        int a5@<ebp>,
        void *a6@<edi>,
        int a7@<esi>)
{
  __asm { fmul    dword ptr [ebx-153E1B83h] }
  *(_BYTE *)(a2 - 2147221164) -= a1 + a3;
  if ( 2 * a7 == 0 )
  {
    SetProcessAffinityMask(hProcess: a6, dwProcessAffinityMask: *(_DWORD *)(a5 - 24));
    SetThreadAffinityMask(hThread: _EBX, dwThreadAffinityMask: *(_DWORD *)(a5 - 20));
    JUMPOUT(0x3F00261F);
  }
  JUMPOUT(0x3F0025A4);
}

//------------------------------------------------------------------------------
// Address: 0x3F002620
// Name: enum SpewRetval_t DefaultSpewFunc(enum SpewType_t,char const __near *)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
SpewRetval_t __userpurge DefaultSpewFunc@<eax>(int a1@<ebp>, SpewType_t type, const char *pMsg)
{
  *(_DWORD *)(a1 - 4) = -1;
  return *(_DWORD *)(a1 + 8);
}

//------------------------------------------------------------------------------
// Address: 0x3F002650
// Name: _SpewOutputFunc
// Source: json
//------------------------------------------------------------------------------
void __cdecl SpewOutputFunc()
{
  GetCurrentProcess();
  JUMPOUT(0x3F002668);
}

//------------------------------------------------------------------------------
// Address: 0x3F002670
// Name: _GetSpewOutputFunc
// Source: json
//------------------------------------------------------------------------------
void __usercall GetSpewOutputFunc(int a1@<eax>, _BYTE *a2@<ebx>, int a3@<ebp>, void (__cdecl *a4)())
{
  LOBYTE(a1) = a1 & 0x33;
  *a2 = 0;
  *(_BYTE *)(a3 - 40) = 0;
  *(_DWORD *)(a3 - 39) = a1;
  SetFlushLogFunc(func: a4);
}

//------------------------------------------------------------------------------
// Address: 0x3F002680
// Name: _SetFlushLogFunc
// Source: json
//------------------------------------------------------------------------------
void __usercall SetFlushLogFunc(int a1@<eax>, int a2@<ebp>)
{
  *(_DWORD *)(a2 - 35) = a1;
  *(_DWORD *)(a2 - 31) = a1;
  *(_DWORD *)(a2 - 27) = a1;
  *(_DWORD *)(a2 - 23) = a1;
  JUMPOUT(0x3F00268C);
}

//------------------------------------------------------------------------------
// Address: 0x3F002690
// Name: _CallFlushLogFunc
// Source: json
//------------------------------------------------------------------------------
void __usercall CallFlushLogFunc(char a1@<cf>, __int16 a2@<ax>, int a3@<ebp>)
{
  char v3; // cc
  int v4; // ebp

  v3 = a1 | (a3 == -1);
  v4 = a3 + 1;
  __asm { icebp }
  *(_WORD *)(v4 - 11) = a2;
  *(_BYTE *)(v4 - 9) = a2;
  if ( !v3 )
    JUMPOUT(0x3F00269E);
  JUMPOUT(0x3F0026FF);
}

//------------------------------------------------------------------------------
// Address: 0x3F0026A0
// Name: _SetAssertFailedNotifyFunc
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetAssertFailedNotifyFunc()
{
  JUMPOUT(0x3F0026AB);
}

//------------------------------------------------------------------------------
// Address: 0x3F0026B0
// Name: _CallAssertFailedNotifyFunc
// Source: json
//------------------------------------------------------------------------------
void __usercall CallAssertFailedNotifyFunc(int a1@<edi>)
{
  if ( a1 != 0 )
    JUMPOUT(0x3F0026BC);
  JUMPOUT(0x3F0026D3);
}

//------------------------------------------------------------------------------
// Address: 0x3F002B00
// Name: public: CStack::CStack(void)
// Source: json
//------------------------------------------------------------------------------
CStack *__thiscall CStack::CStack(CStack *this)
{
  *((_DWORD *)this + 40) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x3F002B10
// Name: _Warning
// Source: json
//------------------------------------------------------------------------------
// Alternative name is '??1CStack@@QAE@XZ'
// Alternative name is '?Finalize@CValidator@@QAEXXZ'
void Warning()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F002B20
// Name: public: void CStack::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStack::Reset(CStack *this)
{
  *((_DWORD *)this + 40) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F002B30
// Name: _DWarning
// Source: json
//------------------------------------------------------------------------------
void __userpurge DWarning(int a1@<ecx>, const char *pGroupName, const char *level, const char *pMsgFormat)
{
  int v4; // eax

  v4 = *(_DWORD *)(a1 + 160);
  if ( v4 < 20 )
  {
    *(_DWORD *)(a1 + 8 * v4) = pGroupName;
    *(_DWORD *)(a1 + 8 * v4 + 4) = level;
    ++*(_DWORD *)(a1 + 160);
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F002B60
// Name: public: int CStack::GetNumFrames(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CStack::GetNumFrames(CStack *this)
{
  return *((_DWORD *)this + 40);
}

//------------------------------------------------------------------------------
// Address: 0x3F002B70
// Name: public: unsigned __int64 CStack::NGetPC(int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int64 __thiscall CStack::NGetPC(CStack *this, int a2)
{
  return this->m_StackPC[a2];
}

//------------------------------------------------------------------------------
// Address: 0x3F002B90
// Name: _Log
// Source: json
//------------------------------------------------------------------------------
void __usercall Log(char *a1@<ecx>, const char *pMsgFormat, ...)
{
  qmemcpy(a1, pMsgFormat, 0xA8u);
  JUMPOUT(0x3F002BA5);
}

//------------------------------------------------------------------------------
// Address: 0x3F002BB0
// Name: _DLog
// Source: json
//------------------------------------------------------------------------------
void DLog(const char *pGroupName, int level, const char *pMsgFormat, ...)
{
  IsDebuggerPresent();
}

//------------------------------------------------------------------------------
// Address: 0x3F002BF0
// Name: SpewOutputFunc
// Source: json
//------------------------------------------------------------------------------
int (__cdecl *__cdecl SpewOutputFunc(int (__cdecl *a1)(int, int)))(int, int)
{
  int (__cdecl *result)(int, int); // eax

  result = a1;
  off_3F03C278 = a1;
  if ( a1 == nullptr )
    off_3F03C278 = sub_3F002BC0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F002C10
// Name: _Error
// Source: json
//------------------------------------------------------------------------------
void Error(const char *pMsgFormat, ...)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F002C20
// Name: SetFlushLogFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl SetFlushLogFunc(int a1)
{
  dword_3F03D36C = a1;
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x3F002C30
// Name: bool FindSpewGroup(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl FindSpewGroup()
{
  bool result; // al

  result = (char)dword_3F03D36C;
  if ( dword_3F03D36C != nullptr )
    return dword_3F03D36C();
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F002C40
// Name: SetAssertFailedNotifyFunc
// Source: json
//------------------------------------------------------------------------------
int (*__cdecl SetAssertFailedNotifyFunc(int (*a1)(void)))(void)
{
  dword_3F03D370 = a1;
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x3F002C50
// Name: CallAssertFailedNotifyFunc
// Source: json
//------------------------------------------------------------------------------
int (*CallAssertFailedNotifyFunc())(void)
{
  int (*result)(void); // eax

  result = dword_3F03D370;
  if ( dword_3F03D370 != nullptr )
    return (int (*)(void))dword_3F03D370();
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F002CA0
// Name: _SpewActivate
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __cdecl SpewActivate()
{
  SetAssertDumpStack(bAssertDumpStack: (bool)"console");
  GetCurrentProcess();
  JUMPOUT(0x3F002CB5);
}

//------------------------------------------------------------------------------
// Address: 0x3F002CC0
// Name: _SpewAndLogActivate
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __cdecl SpewAndLogActivate()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F002E40
// Name: _SpewChangeIfStillDefault
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall SpewChangeIfStillDefault(char a1@<cl>, int a2@<ebx>, int a3@<ebp>, int a4@<esi>)
{
  bool v4; // cf
  int v5; // ebp
  char *ind; // [esp+0h] [ebp-8h]
  va_list v7; // [esp+4h] [ebp-4h]

  v4 = __CFADD__(a1, *(_BYTE *)(a2 - 1950130715));
  *(_BYTE *)(a2 - 1950130715) += a1;
  v5 = a3 + 1;
  *(_BYTE *)(a2 + 1364200525) += a1 + v4;
  if ( sub_3F01ACDC(Buffer: (char *)(v5 + a4 - 5036), BufferCount: 5019 - a4, Format: ind, ArgList: v7) == -1 )
  {
    *(_DWORD *)(v5 - 4) = -1;
    if ( --dword_3F0A35FC == 0 )
      _InterlockedExchange(&dword_3F0A35F8, 0);
    JUMPOUT(0x3F002E87);
  }
  JUMPOUT(0x3F002E9B);
}

//------------------------------------------------------------------------------
// Address: 0x3F002E90
// Name: _SpewAndLogChangeIfStillDefault
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __cdecl SpewAndLogChangeIfStillDefault()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F002F40
// Name: _IsLogActive
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __fastcall IsLogActive(int a1, int a2)
{
  return ((int (__cdecl *)(int, int))SpewMessageType)(a1: a2, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x3F002F80
// Name: _CrackSmokingCompiler
// Source: json
//------------------------------------------------------------------------------
void __usercall CrackSmokingCompiler(char a1@<sf>, char a2@<of>)
{
  if ( a1 != a2 )
    JUMPOUT(0x3F002F9A);
  JUMPOUT(0x3F002F9E);
}

//------------------------------------------------------------------------------
// Address: 0x3F002FA0
// Name: _Plat_SimpleLog
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __fastcall Plat_SimpleLog(int a1, int a2)
{
  return ((int (__cdecl *)(int, int))SpewMessageType)(a1: a2, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x3F002FC0
// Name: Msg
// Source: json
//------------------------------------------------------------------------------
int Msg(int a1, ...)
{
  va_list va; // [esp+Ch] [ebp+Ch] BYREF

  va_start(va, a1);
  return ((int (__cdecl *)(_DWORD, int, char *))SpewMessageType)(a1: 0, a2: a1, a3: va);
}

//------------------------------------------------------------------------------
// Address: 0x3F002FE0
// Name: _SetAssertDumpStack
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F002FF0
// Name: _AssertMsgImplementation
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall AssertMsgImplementation(char a1@<al>, int a2@<ebx>, int a3@<ebp>)
{
  bool v3; // zf
  int v4; // ecx
  bool v5; // sf
  bool v6; // of

  v3 = a1 + *(_BYTE *)(a2 - 1065088828) == 0;
  *(_BYTE *)(a2 - 1065088828) += a1;
  if ( v3 )
  {
    v6 = __OFSUB__(dword_3F03D37C, *(_DWORD *)(a3 + 12));
    v5 = dword_3F03D37C - *(_DWORD *)(a3 + 12) < 0;
  }
  else
  {
    v4 = *((_DWORD *)dword_3F03D374 + 14 * *(_DWORD *)(a3 - 4) + 12);
    v6 = __OFSUB__(v4, *(_DWORD *)(a3 + 12));
    v5 = v4 - *(_DWORD *)(a3 + 12) < 0;
  }
  if ( v5 == v6 )
    ((void (__cdecl *)(_DWORD, _DWORD, int))SpewMessageType)(a1: 0, a2: *(_DWORD *)(a3 + 16), a3: a3 + 20);
}

//------------------------------------------------------------------------------
// Address: 0x3F003040
// Name: Warning
// Source: json
//------------------------------------------------------------------------------
int Warning(int a1, ...)
{
  va_list va; // [esp+Ch] [ebp+Ch] BYREF

  va_start(va, a1);
  return ((int (__cdecl *)(int, int, char *))SpewMessageType)(a1: 1, a2: a1, a3: va);
}

//------------------------------------------------------------------------------
// Address: 0x3F003060
// Name: DWarning
// Source: json
//------------------------------------------------------------------------------
char __usercall DWarning@<al>(int a1@<ecx>, int a2, int a3, int a4, ...)
{
  int v4; // ecx
  bool v5; // sf
  bool v6; // of
  char result; // al
  va_list va; // [esp+18h] [ebp+14h] BYREF

  va_start(va, a4);
  if ( (unsigned __int8)((int (__stdcall *)(int))sub_3F003160)(a1: a2) != 0 )
  {
    v4 = *((_DWORD *)dword_3F03D374 + 14 * a1 + 12);
    v6 = __OFSUB__(v4, a3);
    v5 = v4 - a3 < 0;
  }
  else
  {
    v6 = __OFSUB__(dword_3F03D37C, a3);
    v5 = dword_3F03D37C - a3 < 0;
  }
  result = v5 == v6;
  if ( v5 == v6 )
    return ((int (__cdecl *)(int, int, char *))SpewMessageType)(a1: 1, a2: a4, a3: va);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F0030C0
// Name: Log
// Source: json
//------------------------------------------------------------------------------
int Log(int a1, ...)
{
  va_list va; // [esp+Ch] [ebp+Ch] BYREF

  va_start(va, a1);
  return ((int (__cdecl *)(int, int, char *))SpewMessageType)(a1: 4, a2: a1, a3: va);
}

//------------------------------------------------------------------------------
// Address: 0x3F0030E0
// Name: DLog
// Source: json
//------------------------------------------------------------------------------
void __cdecl DLog(CValidator *a1)
{
  int v1; // ecx
  int v2; // [esp+0h] [ebp-4h] BYREF

  v2 = v1;
  if ( (unsigned __int8)sub_3F003160(a1, a2: &v2) == 0 )
    JUMPOUT(0x3F003112);
  ValidateSpew(validator: a1);
}

//------------------------------------------------------------------------------
// Address: 0x3F003110
// Name: _ValidateSpew
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall ValidateSpew(char a1@<sf>, char a2@<of>, int a3@<ebp>)
{
  if ( a1 == a2 )
    ((void (__cdecl *)(int, _DWORD, int))SpewMessageType)(a1: 4, a2: *(_DWORD *)(a3 + 16), a3: a3 + 20);
}

//------------------------------------------------------------------------------
// Address: 0x3F003140
// Name: Error
// Source: json
//------------------------------------------------------------------------------
int Error(int a1, ...)
{
  va_list va; // [esp+Ch] [ebp+Ch] BYREF

  va_start(va, a1);
  return ((int (__cdecl *)(int, int, char *))SpewMessageType)(a1: 3, a2: a1, a3: va);
}

//------------------------------------------------------------------------------
// Address: 0x3F0031D0
// Name: SpewActivate
// Source: json
//------------------------------------------------------------------------------
void *__cdecl SpewActivate(int nMemSize)
{
  return MemAllocScratch(nMemSize);
}

//------------------------------------------------------------------------------
// Address: 0x3F0033D0
// Name: SpewAndLogChangeIfStillDefault
// Source: json
//------------------------------------------------------------------------------
_DWORD *__cdecl SpewAndLogChangeIfStillDefault(int nMemSize, int a2, int a3, int a4, int a5)
{
  _DWORD *result; // eax
  int v6; // [esp+4h] [ebp-4h] BYREF

  result = (_DWORD *)sub_3F003160(a1: nMemSize, a2: &v6);
  if ( (_BYTE)result != 0 )
  {
    result = (char *)dword_3F03D374 + 56 * v6;
    if ( result[12] == a3 && result[13] == a5 )
      return MemAllocScratch(nMemSize);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F003430
// Name: IsSpewActive
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl IsSpewActive(int a1, int a2)
{
  int v2; // ecx
  int v4; // [esp+0h] [ebp-4h] BYREF

  v4 = v2;
  if ( (unsigned __int8)sub_3F003160(a1, a2: &v4) != 0 )
    return *((_DWORD *)dword_3F03D374 + 14 * v4 + 12) >= a2;
  else
    return dword_3F03D37C >= a2;
}

//------------------------------------------------------------------------------
// Address: 0x3F003480
// Name: IsLogActive
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl IsLogActive(int a1, int a2)
{
  int v2; // esi
  int v4; // [esp+4h] [ebp-4h] BYREF

  v2 = dword_3F03D380;
  if ( (unsigned __int8)sub_3F003160(a1, a2: &v4) != 0 )
    v2 = *((_DWORD *)dword_3F03D374 + 14 * v4 + 13);
  return v2 >= a2;
}

//------------------------------------------------------------------------------
// Address: 0x3F0034D0
// Name: CrackSmokingCompiler
// Source: json
//------------------------------------------------------------------------------
double __cdecl CrackSmokingCompiler(float a1)
{
  return (float)fabs(a1);
}

//------------------------------------------------------------------------------
// Address: 0x3F003660
// Name: ValidateSpew
// Source: json
//------------------------------------------------------------------------------
void __cdecl ValidateSpew(CValidator *a1)
{
  CValObject *m_pValObjectCur; // eax

  CValidator::Push(this: a1, a2: "Spew globals", a3: nullptr, a4: "Global");
  CValidator::ClaimMemory(this: a1, a2: dword_3F03D374);
  if ( LOBYTE(a1[1].m_cValObjectsAllocated) == 0 && BYTE1(a1->m_threadMutexValidationLock[1]) == 0 )
  {
    if ( a1->m_pValObjectCur == nullptr )
      ((void (__cdecl *)(errentry *, _DWORD, errentry *, int, void *, _DWORD))AssertMsgImplementation)(
        a1: &errtable[34],
        a2: 0,
        a3: &errtable[9],
        a4: 158,
        a5: &unk_3F041A88,
        a6: 0);
    m_pValObjectCur = a1->m_pValObjectCur;
    a1->m_pValObjectCur = m_pValObjectCur->m_pValObjectParent;
    if ( m_pValObjectCur->m_cubMemTree <= 0 )
      --a1->m_cValObjectsUsed;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F0026C0
// Name: __ExitOnFatalAssert
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _ExitOnFatalAssert(
        char a1@<cf>,
        int a2@<eax>,
        unsigned int a3@<edx>,
        int a4@<ecx>,
        char a5@<bl>,
        int a6@<ebp>,
        unsigned int a7@<edi>,
        unsigned __int8 *a8@<esi>)
{
  unsigned int v8; // ecx

  *(_DWORD *)(a3 - 338548914) -= a1 + a4;
  do
  {
    if ( *(_BYTE *)(a6 + a3 - 40) == a5 )
      break;
    ++a3;
  }
  while ( a3 < a7 );
  if ( a3 == a7 )
    *(_BYTE *)(a6 + a3 - 40) = (unsigned __int8)(a8[a2 + 4] & (a8[42] | a8[44])) >> a8[39];
  v8 = a8[36];
  ++*(_DWORD *)(a6 - 4);
  if ( a2 + 1 < v8 )
    JUMPOUT(0x3F0026A2);
}

//------------------------------------------------------------------------------
// Address: 0x3F002720
// Name: __SpewInfo
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _SpewInfo(
        int a1@<eax>,
        int a2@<ecx>,
        int a3@<ebp>,
        int a4@<esi>,
        SpewType_t type,
        const char *pFile,
        char *line)
{
  *(_BYTE *)(a3 - 36) = 0;
  *(_DWORD *)(a3 - 35) = a1;
  *(_DWORD *)(a3 - 31) = a1;
  *(_DWORD *)(a3 - 27) = a1;
  *(_DWORD *)(a3 - 23) = a1;
  *(_DWORD *)(a3 - 19) = a1;
  *(_DWORD *)(a3 - 15) = a1;
  *(_DWORD *)(a3 - 11) = a1;
  *(_WORD *)(a3 - 7) = a1;
  *(_BYTE *)(a3 - 5) = a1;
  if ( a2 == 0 )
    JUMPOUT(0x3F00279F);
  *(_DWORD *)(a3 - 4) = a4 + 4;
  _SpewMessageType(spewType: type, pMsgFormat: pFile, args: line);
}

//------------------------------------------------------------------------------
// Address: 0x3F002780
// Name: __SpewMessageType
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall _SpewMessageType@<eax>(
        int a1@<eax>,
        int a2@<edx>,
        char a3@<cl>,
        char a4@<bl>,
        int a5@<ebp>,
        int a6@<edi>,
        int a7@<esi>)
{
  int v7; // edi
  unsigned int v8; // ecx

  v7 = a6 + 1;
  *(_BYTE *)(a5 + a2 - 36) = (unsigned __int8)(*(_BYTE *)(a7 + a1 + 4) & a4) >> a3;
  v8 = *(unsigned __int8 *)(a7 + 36);
  ++*(_DWORD *)(a5 - 4);
  if ( a1 + 1 < v8 )
    JUMPOUT(0x3F002750);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x3F002A00
// Name: __SpewMessage
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _SpewMessage(int a1@<eax>, int a2@<ebp>, const char *pMsgFormat, ...)
{
  *(_DWORD *)(a2 - 16) = a1;
  *(_DWORD *)(a2 - 4) = 0;
  if ( a1 != 0 )
  {
    ((void (__cdecl *)(int))loc_3F001EE0)(a1);
    *(_DWORD *)(a2 - 4) = -1;
    JUMPOUT(0x3F002A1B);
  }
  JUMPOUT(0x3F002A2B);
}

//------------------------------------------------------------------------------
// Address: 0x3F002A20
// Name: __DSpewMessage
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void _DSpewMessage()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F002AB0
// Name: __DMsg
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge _DMsg(char *pGroupName, const char *level, const char *pMsgFormat)
{
  *(_DWORD *)pGroupName = &ICpuTopology::`vftable';
  *(_DWORD *)pGroupName = &`anonymous namespace'::DefaultImpl::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x3F002BC0
// Name: sub_3F002BC0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __cdecl sub_3F002BC0(int a1)
{
  ((void (__stdcall *)(void *))loc_3F01A9E6)(a1: &unk_3F030FBC);
  if ( a1 == 2 )
    return 0;
  else
    return (a1 == 3) + 1;
}

//------------------------------------------------------------------------------
// Address: 0x3F002C60
// Name: _ExitOnFatalAssert
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ExitOnFatalAssert(const char *a1, int a2)
{
  SpewMessage(a1: "Fatal assert failed: %s, line %d.  Application exiting.\n", a1, a2);
  if ( !IsDebuggerPresent() )
    WriteMiniDump(a1: "Fatal assert", a2: a1, a3: a2, a4: 0, a5: 1);
  SpewActivate();
}

//------------------------------------------------------------------------------
// Address: 0x3F002CD0
// Name: _SpewInfo
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl SpewInfo(int a1, int a2, int a3)
{
  unsigned int v3; // esi
  unsigned int v4; // eax
  int result; // eax

  v3 = ((int (__cdecl *)(int, int))loc_3F01AB6B)(a1: a2, a2: 92);
  v4 = ((int (__cdecl *)(int, int))loc_3F01AB6B)(a1: a2, a2: 47);
  if ( v3 < v4 )
    v3 = v4;
  if ( v3 != 0 )
  {
    result = a3;
    dword_3F03D2A8 = v3 + 1;
  }
  else
  {
    result = a1;
    dword_3F03D2A8 = a2;
  }
  dword_3F03D2A4 = a3;
  dword_3F03D2A0 = a1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F002F30
// Name: _SpewMessage
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F002F50
// Name: _DSpewMessage
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DSpewMessage(int a1, int a2)
{
  int v2; // ecx
  int v3; // [esp+0h] [ebp-4h] BYREF

  v3 = v2;
  if ( (unsigned __int8)sub_3F003160(a1, a2: &v3) == 0 )
    JUMPOUT(0x3F002F82);
  CrackSmokingCompiler(
    a1: *((_DWORD *)dword_3F03D374 + 14 * v3 + 12) - a2 < 0,
    a2: __OFSUB__(*((_DWORD *)dword_3F03D374 + 14 * v3 + 12), a2));
}

//------------------------------------------------------------------------------
// Address: 0x3F0036F0
// Name: sub_3F0036F0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F0036F0()
{
  int v0; // esi
  int i; // eax
  _HEAPINFO EntryInfo; // [esp+4h] [ebp-Ch] BYREF

  v0 = 0;
  EntryInfo._pentry = nullptr;
  for ( i = _heapwalk(&EntryInfo); i == -2; i = _heapwalk(&EntryInfo) )
    v0 += EntryInfo._useflag == 1 ? EntryInfo._size : 0;
  if ( i == -5 || i == -1 )
    return v0;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x3F003750
// Name: sub_3F003750
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void sub_3F003750()
{
  JUMPOUT(0x3F003760);
}

//------------------------------------------------------------------------------
// Address: 0x3F003770
// Name: sub_3F003770
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void sub_3F003770()
{
  InitStackWalk();
}

} // namespace tier0_s
