// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tier0/win32consoleio.cpp
// Functions: 4
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10015B20
// Name: _SetupWin32ConsoleIO
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetupWin32ConsoleIO()
{
  char v0; // bl
  HANDLE StdHandle; // eax
  HMODULE LibraryA; // eax
  BOOL (__stdcall *AttachConsole)(DWORD); // eax
  HANDLE v4; // eax
  int v5; // eax
  _iobuf *v6; // eax
  HANDLE v7; // eax
  int v8; // eax
  _iobuf *v9; // eax
  HANDLE v10; // eax
  int v11; // eax
  _iobuf *v12; // eax
  std::_Lockit v14; // [esp+28h] [ebp-4h] BYREF
  _iobuf v15; // 0:^18.32
  _iobuf v16; // 0:^18.32
  _iobuf v17; // 0:^18.32

  v0 = 0;
  StdHandle = GetStdHandle(nStdHandle: 0xFFFFFFF5);
  if ( GetFileType(hFile: StdHandle) == 0 )
  {
    LibraryA = LoadLibraryA(lpLibFileName: "kernel32.dll");
    AttachConsole = (BOOL (__stdcall *)(DWORD))GetProcAddress(hModule: LibraryA, lpProcName: "AttachConsole");
    if ( AttachConsole == nullptr || AttachConsole(dwProcessId: -1) == 0 )
    {
      v0 = 1;
      AllocConsole();
    }
    v4 = GetStdHandle(nStdHandle: 0xFFFFFFF5);
    v5 = _open_osfhandle(osfhandle: (int)v4, flags: 0x4000);
    v15 = *_fdopen(filedes: v5, mode: "w");
    __iob_func()[1] = v15;
    v6 = __iob_func();
    setvbuf(str: v6 + 1, buffer: nullptr, type: 4, size: 0);
    v7 = GetStdHandle(nStdHandle: 0xFFFFFFF6);
    v8 = _open_osfhandle(osfhandle: (int)v7, flags: 0x4000);
    v16 = *_fdopen(filedes: v8, mode: "r");
    *__iob_func() = v16;
    v9 = __iob_func();
    setvbuf(str: v9, buffer: nullptr, type: 4, size: 0);
    v10 = GetStdHandle(nStdHandle: 0xFFFFFFF4);
    v11 = _open_osfhandle(osfhandle: (int)v10, flags: 0x4000);
    v17 = *_fdopen(filedes: v11, mode: "w");
    __iob_func()[2] = v17;
    v12 = __iob_func();
    setvbuf(str: v12 + 1, buffer: nullptr, type: 4, size: 0);
    std::_Lockit::_Lockit(this: &v14, kind: 2);
    std::ios_base::_Sync = true;
    std::_Lockit::~_Lockit(this: &v14);
  }
  return v0;
}

//------------------------------------------------------------------------------
// Address: 0x10015D30
// Name: _InitWin32ConsoleColorContext
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitWin32ConsoleColorContext(Win32ConsoleColorContext_t *pContext)
{
  HANDLE StdHandle; // eax
  int v2; // edx
  unsigned __int16 v3; // cx
  _CONSOLE_SCREEN_BUFFER_INFO oldInfo; // [esp+0h] [ebp-18h] BYREF

  StdHandle = GetStdHandle(nStdHandle: 0xFFFFFFF5);
  GetConsoleScreenBufferInfo(hConsoleOutput: StdHandle, lpConsoleScreenBufferInfo: &oldInfo);
  v2 = oldInfo.wAttributes & 0xF;
  v3 = oldInfo.wAttributes & 0xF0;
  pContext->m_LastColor = v2;
  pContext->m_InitialColor = v2;
  pContext->m_BackgroundFlags = v3;
  pContext->m_BadColor = 0;
  if ( (v3 & 0x40) != 0 )
    pContext->m_BadColor = 4;
  if ( (v3 & 0x20) != 0 )
    pContext->m_BadColor |= 2u;
  if ( (v3 & 0x10) != 0 )
    pContext->m_BadColor |= 1u;
  if ( (v3 & 0x80u) != 0 )
    pContext->m_BadColor |= 8u;
}

//------------------------------------------------------------------------------
// Address: 0x10015DA0
// Name: _SetWin32ConsoleColor
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __cdecl SetWin32ConsoleColor(
        Win32ConsoleColorContext_t *pContext,
        int nRed,
        int nGreen,
        int nBlue,
        int nIntensity)
{
  unsigned __int16 m_LastColor; // si
  HANDLE StdHandle; // eax
  WORD v8; // [esp-4h] [ebp-8h]

  m_LastColor = pContext->m_LastColor;
  pContext->m_LastColor = 0;
  if ( nRed != 0 )
    pContext->m_LastColor = 4;
  if ( nGreen != 0 )
    pContext->m_LastColor |= 2u;
  if ( nBlue != 0 )
    pContext->m_LastColor |= 1u;
  if ( nIntensity != 0 )
    pContext->m_LastColor |= 8u;
  if ( pContext->m_LastColor == pContext->m_BadColor )
    pContext->m_LastColor = pContext->m_InitialColor;
  v8 = pContext->m_LastColor | pContext->m_BackgroundFlags;
  StdHandle = GetStdHandle(nStdHandle: 0xFFFFFFF5);
  SetConsoleTextAttribute(hConsoleOutput: StdHandle, wAttributes: v8);
  return m_LastColor;
}

//------------------------------------------------------------------------------
// Address: 0x10015E10
// Name: _RestoreWin32ConsoleColor
// Source: json
//------------------------------------------------------------------------------
void __cdecl RestoreWin32ConsoleColor(Win32ConsoleColorContext_t *pContext, unsigned __int16 prevColor)
{
  HANDLE StdHandle; // eax
  WORD v3; // [esp-4h] [ebp-Ch]

  v3 = prevColor | pContext->m_BackgroundFlags;
  StdHandle = GetStdHandle(nStdHandle: 0xFFFFFFF5);
  SetConsoleTextAttribute(hConsoleOutput: StdHandle, wAttributes: v3);
  pContext->m_LastColor = prevColor;
}
