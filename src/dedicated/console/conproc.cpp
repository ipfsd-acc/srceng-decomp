// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: dedicated/console/conproc.cpp
// Functions: 5
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10004A60
// Name: int SetConsoleCXCY(void __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl SetConsoleCXCY(void *hStdout, int cx, int cy)
{
  COORD LargestConsoleWindowSize; // eax
  int Y; // edi
  int X; // ebx
  _CONSOLE_SCREEN_BUFFER_INFO info; // [esp+Ch] [ebp-18h] BYREF

  LargestConsoleWindowSize = GetLargestConsoleWindowSize(hConsoleOutput: hStdout);
  Y = cy;
  X = cx;
  if ( cy > LargestConsoleWindowSize.Y )
    Y = LargestConsoleWindowSize.Y;
  if ( cx > LargestConsoleWindowSize.X )
    X = LargestConsoleWindowSize.X;
  if ( !GetConsoleScreenBufferInfo(hConsoleOutput: hStdout, lpConsoleScreenBufferInfo: &info) )
    return false;
  *(_DWORD *)&info.srWindow.Left = 0;
  info.srWindow.Bottom = Y - 1;
  info.srWindow.Right = info.dwSize.X - 1;
  if ( Y >= info.dwSize.Y )
  {
    if ( Y > info.dwSize.Y )
    {
      info.dwSize.Y = Y;
      if ( !SetConsoleScreenBufferSize(hConsoleOutput: hStdout, dwSize: info.dwSize) )
        return false;
      if ( !SetConsoleWindowInfo(hConsoleOutput: hStdout, bAbsolute: true, lpConsoleWindow: &info.srWindow) )
        return false;
    }
  }
  else
  {
    if ( !SetConsoleWindowInfo(hConsoleOutput: hStdout, bAbsolute: true, lpConsoleWindow: &info.srWindow) )
      return false;
    info.dwSize.Y = Y;
    if ( !SetConsoleScreenBufferSize(hConsoleOutput: hStdout, dwSize: info.dwSize) )
      return false;
  }
  if ( !GetConsoleScreenBufferInfo(hConsoleOutput: hStdout, lpConsoleScreenBufferInfo: &info) )
    return false;
  *(_DWORD *)&info.srWindow.Left = 0;
  info.srWindow.Bottom = info.dwSize.Y - 1;
  info.srWindow.Right = X - 1;
  if ( X >= info.dwSize.X )
  {
    if ( X <= info.dwSize.X )
      return true;
    info.dwSize.X = X;
    return SetConsoleScreenBufferSize(hConsoleOutput: hStdout, dwSize: info.dwSize)
        && SetConsoleWindowInfo(hConsoleOutput: hStdout, bAbsolute: true, lpConsoleWindow: &info.srWindow);
  }
  if ( !SetConsoleWindowInfo(hConsoleOutput: hStdout, bAbsolute: true, lpConsoleWindow: &info.srWindow) )
    return false;
  info.dwSize.X = X;
  return SetConsoleScreenBufferSize(hConsoleOutput: hStdout, dwSize: info.dwSize);
}

//------------------------------------------------------------------------------
// Address: 0x10004BA0
// Name: int WriteText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl WriteText(char *szText)
{
  char *i; // esi
  char v2; // al
  char v3; // bl
  int v4; // edi
  unsigned __int16 v5; // ax
  int v7; // [esp-Ch] [ebp-28h]
  _INPUT_RECORD rec; // [esp+4h] [ebp-18h] BYREF
  unsigned int dwWritten; // [esp+18h] [ebp-4h] BYREF
  char szText_3; // [esp+27h] [ebp+Bh]

  for ( i = szText; *i != 0; ++i )
  {
    if ( *i == 10 )
      *i = 13;
    v2 = toupper(c: *i);
    v3 = *i;
    v4 = *i;
    rec.EventType = 1;
    rec.Event.KeyEvent.bKeyDown = 1;
    rec.Event.KeyEvent.wRepeatCount = 1;
    rec.Event.KeyEvent.wVirtualKeyCode = v2;
    szText_3 = toupper(c: v4);
    if ( v3 == 13 )
    {
      v5 = 28;
    }
    else if ( isalpha(c: v4) != 0 )
    {
      v5 = szText_3 - 35;
    }
    else if ( isdigit(c: v4) != 0 )
    {
      v5 = szText_3 - 46;
    }
    else
    {
      v5 = v4;
    }
    rec.Event.KeyEvent.wVirtualScanCode = v5;
    v7 = *i;
    rec.Event.KeyEvent.uChar.UnicodeChar = *i;
    rec.Event.KeyEvent.dwControlKeyState = isupper(c: v7) != 0 ? 0x80 : 0;
    WriteConsoleInputA(hConsoleInput: hStdin, lpBuffer: &rec, nLength: 1u, lpNumberOfEventsWritten: &dwWritten);
    rec.Event.KeyEvent.bKeyDown = 0;
    WriteConsoleInputA(hConsoleInput: hStdin, lpBuffer: &rec, nLength: 1u, lpNumberOfEventsWritten: &dwWritten);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10004CA0
// Name: unsigned int RequestProc(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __stdcall __noreturn RequestProc(void *arg)
{
  char *v1; // esi
  int v2; // eax
  int v3; // ecx
  int v4; // eax
  _CONSOLE_SCREEN_BUFFER_INFO ConsoleScreenBufferInfo; // [esp+0h] [ebp-28h] BYREF
  void *heventWait[2]; // [esp+18h] [ebp-10h] BYREF
  unsigned int NumberOfCharsRead; // [esp+20h] [ebp-8h] BYREF
  COORD dwReadCoord; // [esp+24h] [ebp-4h]

  heventWait[0] = heventParentSend;
  heventWait[1] = heventDone;
  if ( WaitForMultipleObjects(nCount: 2u, lpHandles: heventWait, bWaitAll: false, dwMilliseconds: 0xFFFFFFFF) != 1 )
  {
    while ( 1 )
    {
      v1 = (char *)MapViewOfFile(
                     hFileMappingObject: hfileBuffer,
                     dwDesiredAccess: 6u,
                     dwFileOffsetHigh: 0,
                     dwFileOffsetLow: 0,
                     dwNumberOfBytesToMap: 0);
      if ( v1 == nullptr )
        break;
      switch ( *(_DWORD *)v1 )
      {
        case 2:
          v2 = WriteText(szText: v1 + 4);
          goto LABEL_10;
        case 3:
          v3 = *((_DWORD *)v1 + 1);
          v4 = *((_DWORD *)v1 + 2);
          dwReadCoord.X = 0;
          dwReadCoord.Y = v3;
          v2 = ReadConsoleOutputCharacterA(
                 hConsoleOutput: hStdout,
                 lpCharacter: v1 + 4,
                 nLength: 16 * (5 * (v4 - v3) + 5),
                 dwReadCoord,
                 lpNumberOfCharsRead: &NumberOfCharsRead);
          if ( v2 != 0 )
            v1[NumberOfCharsRead + 4] = 0;
          goto LABEL_10;
        case 4:
          v2 = GetConsoleScreenBufferInfo(hConsoleOutput: hStdout, lpConsoleScreenBufferInfo: &ConsoleScreenBufferInfo);
          if ( v2 != 0 )
            *((_DWORD *)v1 + 1) = ConsoleScreenBufferInfo.dwSize.Y;
          goto LABEL_10;
        case 5:
          v2 = SetConsoleCXCY(hStdout: hStdout, cx: 80, cy: *((_DWORD *)v1 + 1));
LABEL_10:
          *(_DWORD *)v1 = v2;
          break;
        default:
          break;
      }
      UnmapViewOfFile(lpBaseAddress: v1);
      SetEvent(hEvent: heventChildSend);
      if ( WaitForMultipleObjects(nCount: 2u, lpHandles: heventWait, bWaitAll: false, dwMilliseconds: 0xFFFFFFFF) == 1 )
        goto LABEL_14;
    }
    sys->Printf(this: sys, a2: "Request Proc:  Invalid -HFILE handle\n");
  }
LABEL_14:
  _endthreadex(retcode: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10004E00
// Name: void DeinitConProc(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DeinitConProc()
{
  if ( heventDone != nullptr )
    SetEvent(hEvent: heventDone);
}

//------------------------------------------------------------------------------
// Address: 0x10004E20
// Name: void InitConProc(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall InitConProc(void *this)
{
  void *v1; // ebx
  void *v2; // edi
  void *v3; // esi
  int v4; // eax
  int v5; // ecx
  int v6; // eax
  int v7; // ecx
  int v8; // eax
  int v9; // ecx
  int v10; // eax
  int v11; // eax
  unsigned int threadAddr; // [esp+Ch] [ebp-Ch] BYREF
  int WantHeight; // [esp+10h] [ebp-8h]
  const char *p; // [esp+14h] [ebp-4h] BYREF

  v1 = nullptr;
  v2 = nullptr;
  v3 = nullptr;
  WantHeight = 50;
  v4 = _CommandLine(a1: this);
  if ( (*(int (__thiscall **)(int, const char *, const char **))(*(_DWORD *)v4 + 12))(a1: v4, a2: "-HFILE", a3: &p) != 0
    && p != nullptr )
  {
    v1 = (void *)atoi(nptr: p);
  }
  v6 = _CommandLine(a1: v5);
  if ( (*(int (__thiscall **)(int, const char *, const char **))(*(_DWORD *)v6 + 12))(a1: v6, a2: "-HPARENT", a3: &p) != 0
    && p != nullptr )
  {
    v2 = (void *)atoi(nptr: p);
  }
  v8 = _CommandLine(a1: v7);
  if ( (*(int (__thiscall **)(int, const char *, const char **))(*(_DWORD *)v8 + 12))(a1: v8, a2: "-HCHILD", a3: &p) != 0
    && p != nullptr )
  {
    v3 = (void *)atoi(nptr: p);
  }
  if ( v1 != nullptr && v2 != nullptr && v3 != nullptr )
  {
    sys->Printf(this: sys, a2: "\n\nInitConProc:  Setting up external control.\n");
    hfileBuffer = v1;
    heventParentSend = v2;
    heventChildSend = v3;
    heventDone = CreateEventA(lpEventAttributes: nullptr, bManualReset: false, bInitialState: false, lpName: nullptr);
    if ( heventDone != nullptr )
    {
      if ( _beginthreadex(
             security: nullptr,
             stacksize: 0,
             initialcode: (unsigned int (__stdcall *)(void *))RequestProc,
             argument: nullptr,
             createflag: 0,
             thrdaddr: &threadAddr) != 0 )
      {
        hStdout = GetStdHandle(nStdHandle: 0xFFFFFFF5);
        hStdin = GetStdHandle(nStdHandle: 0xFFFFFFF6);
        v10 = _CommandLine(a1: v9);
        if ( (*(int (__thiscall **)(int, const char *, const char **))(*(_DWORD *)v10 + 12))(
               a1: v10,
               a2: "-conheight",
               a3: &p) != 0
          && p != nullptr )
        {
          v11 = atoi(nptr: p);
        }
        else
        {
          v11 = WantHeight;
        }
        SetConsoleCXCY(hStdout: hStdout, cx: 80, cy: v11);
      }
      else
      {
        CloseHandle(hObject: heventDone);
        sys->Printf(this: sys, a2: "InitConProc:  Couldn't create third party thread\n");
      }
    }
    else
    {
      sys->Printf(this: sys, a2: "InitConProc:  Couldn't create heventDone\n");
    }
  }
}
