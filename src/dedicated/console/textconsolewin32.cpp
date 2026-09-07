// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: dedicated/console/textconsolewin32.cpp
// Functions: 11
// ============================================================

#include "dedicated\console\textconsolewin32.h"

//------------------------------------------------------------------------------
// Address: 0x100046F0
// Name: public: virtual void CTextConsoleWin32::SetTitle(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextConsoleWin32::SetTitle(CSys *this, char *szText)
{
  SetConsoleTitleA(lpConsoleTitle: szText);
}

//------------------------------------------------------------------------------
// Address: 0x100055E0
// Name: struct HWND__ __near * GetConsoleHwnd(void)
// Source: json
//------------------------------------------------------------------------------
HWND __cdecl GetConsoleHwnd()
{
  DWORD TickCount; // eax
  HWND WindowA; // edi
  DWORD CurrentProcessId; // [esp-4h] [ebp-80Ch]
  char pszOldWindowTitle[1024]; // [esp+8h] [ebp-800h] BYREF
  char pszNewWindowTitle[1024]; // [esp+408h] [ebp-400h] BYREF

  GetConsoleTitleA(lpConsoleTitle: pszOldWindowTitle, nSize: 0x400u);
  CurrentProcessId = GetCurrentProcessId();
  TickCount = GetTickCount();
  _wsprintfA(a1: pszNewWindowTitle, a2: "%d/%d", TickCount, CurrentProcessId);
  SetConsoleTitleA(lpConsoleTitle: pszNewWindowTitle);
  Sleep(dwMilliseconds: 0x28u);
  WindowA = FindWindowA(lpClassName: nullptr, lpWindowName: pszNewWindowTitle);
  SetConsoleTitleA(lpConsoleTitle: pszOldWindowTitle);
  return WindowA;
}

//------------------------------------------------------------------------------
// Address: 0x10005660
// Name: public: virtual bool CTextConsoleWin32::Init(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTextConsoleWin32::Init(CTextConsoleWin32 *this)
{
  HWND ConsoleHwnd; // eax

  if ( !AllocConsole() )
    this->SetTitle(this, a2: "SOURCE DEDICATED SERVER");
  this->hinput = GetStdHandle(nStdHandle: 0xFFFFFFF6);
  this->houtput = GetStdHandle(nStdHandle: 0xFFFFFFF5);
  if ( !SetConsoleCtrlHandler(HandlerRoutine: CFileSystem_Stdio::WaitForResources, Add: true) )
    this->Print(this, a2: "WARNING! TextConsole::Init: Could not attach console hook.\n");
  this->Attrib = 138;
  ConsoleHwnd = GetConsoleHwnd();
  SetWindowPos(hWnd: ConsoleHwnd, hWndInsertAfter: nullptr, X: 0, Y: 0, cx: 0, cy: 0, uFlags: 0x241u);
  return CTextConsole::Init(this);
}

//------------------------------------------------------------------------------
// Address: 0x100056F0
// Name: public: virtual void CTextConsoleWin32::ShutDown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextConsoleWin32::ShutDown(CTextConsoleWin32 *this)
{
  FreeConsole();
  CSteamApplication::PostShutdown((vgui::Panel *)this);
}

//------------------------------------------------------------------------------
// Address: 0x10005710
// Name: public: virtual void CTextConsoleWin32::SetVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextConsoleWin32::SetVisible(CTextConsoleWin32 *this, bool visible)
{
  HWND ConsoleHwnd; // eax

  ConsoleHwnd = GetConsoleHwnd();
  ShowWindow(hWnd: ConsoleHwnd, nCmdShow: visible ? 5 : 0);
  this->m_ConsoleVisible = visible;
}

//------------------------------------------------------------------------------
// Address: 0x10005740
// Name: public: virtual char __near * CTextConsoleWin32::GetLine(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CTextConsoleWin32::GetLine(CTextConsoleWin32 *this)
{
  signed int v2; // ebx
  unsigned __int16 *p_wVirtualKeyCode; // esi
  int v4; // eax
  _INPUT_RECORD Buffer; // [esp+Ch] [ebp-500Ch] BYREF
  char v7[4]; // [esp+500Ch] [ebp-Ch]
  unsigned int NumberOfEventsRead; // [esp+5010h] [ebp-8h] BYREF
  unsigned int NumberOfEvents; // [esp+5014h] [ebp-4h] BYREF

  if ( GetNumberOfConsoleInputEvents(hConsoleInput: this->hinput, lpNumberOfEvents: &NumberOfEvents) )
  {
    while ( NumberOfEvents != 0 )
    {
      if ( !ReadConsoleInputA(
              hConsoleInput: this->hinput,
              lpBuffer: &Buffer,
              nLength: 0x400u,
              lpNumberOfEventsRead: &NumberOfEventsRead) )
      {
        _Error(a1: "CTextConsoleWin32::GetLine: !ReadConsoleInput");
        return nullptr;
      }
      if ( NumberOfEventsRead == 0 )
        return nullptr;
      v2 = 0;
      if ( (int)NumberOfEventsRead > 0 )
      {
        p_wVirtualKeyCode = &Buffer.Event.KeyEvent.wVirtualKeyCode;
        do
        {
          if ( *(p_wVirtualKeyCode - 5) == 1 && *(_DWORD *)(p_wVirtualKeyCode - 3) != 0 )
          {
            v4 = *p_wVirtualKeyCode;
            switch ( v4 )
            {
              case '&':
                CTextConsole::ReceiveUpArrow(this);
                break;
              case '(':
                CTextConsole::ReceiveDownArrow(this);
                break;
              case '%':
                CTextConsole::ReceiveLeftArrow(this);
                break;
              case '\'':
                CTextConsole::ReceiveRightArrow(this);
                break;
              default:
                v7[0] = *((_BYTE *)p_wVirtualKeyCode + 4);
                switch ( v7[0] )
                {
                  case 8:
                    CTextConsole::ReceiveBackspace(this);
                    break;
                  case 9:
                    CTextConsole::ReceiveTab(this);
                    break;
                  case 13:
                    if ( CTextConsole::ReceiveNewline(this) != 0 )
                      return this->m_szConsoleText;
                    break;
                  default:
                    if ( (unsigned __int8)(v7[0] - 32) <= 0x5Eu )
                      CTextConsole::ReceiveStandardChar(this, ch: v7[0]);
                    break;
                }
                break;
            }
          }
          ++v2;
          p_wVirtualKeyCode += 10;
        }
        while ( v2 < (int)NumberOfEventsRead );
      }
      if ( !GetNumberOfConsoleInputEvents(hConsoleInput: this->hinput, lpNumberOfEvents: &NumberOfEvents) )
        goto LABEL_28;
    }
  }
  else
  {
LABEL_28:
    _Error(a1: "CTextConsoleWin32::GetLine: !GetNumberOfConsoleInputEvents");
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100058C0
// Name: public: virtual void CTextConsoleWin32::PrintRaw(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextConsoleWin32::PrintRaw(CTextConsoleWin32 *this, char *pszMsg, DWORD nChars)
{
  if ( nChars != 0 )
    WriteFile(
      hFile: this->houtput,
      lpBuffer: pszMsg,
      nNumberOfBytesToWrite: nChars,
      lpNumberOfBytesWritten: (LPDWORD)&pszMsg,
      lpOverlapped: nullptr);
  else
    WriteFile(
      hFile: this->houtput,
      lpBuffer: pszMsg,
      nNumberOfBytesToWrite: strlen(pszMsg),
      lpNumberOfBytesWritten: (LPDWORD)&pszMsg,
      lpOverlapped: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10005920
// Name: public: virtual void CTextConsoleWin32::Echo(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextConsoleWin32::Echo(CTextConsoleWin32 *this, char *pszMsg, int nChars)
{
  this->PrintRaw(this, a2: pszMsg, a3: nChars);
}

//------------------------------------------------------------------------------
// Address: 0x10005930
// Name: public: virtual int CTextConsoleWin32::GetWidth(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTextConsoleWin32::GetWidth(CTextConsoleWin32 *this)
{
  int result; // eax
  _CONSOLE_SCREEN_BUFFER_INFO csbi; // [esp+0h] [ebp-18h] BYREF

  if ( !GetConsoleScreenBufferInfo(hConsoleOutput: this->houtput, lpConsoleScreenBufferInfo: &csbi) )
    return 80;
  result = csbi.dwSize.X;
  if ( csbi.dwSize.X <= 1 )
    return 80;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10005960
// Name: public: virtual void CTextConsoleWin32::SetStatusLine(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextConsoleWin32::SetStatusLine(CTextConsoleWin32 *this, char *pszStatus)
{
  void (__thiscall *UpdateStatus)(struct CTextConsoleWin32 *); // eax

  strncpy(dest: (unsigned __int8 *)this->statusline, source: (unsigned __int8 *)pszStatus, count: 0x50u);
  UpdateStatus = this->UpdateStatus;
  this->statusline[79] = 0;
  UpdateStatus(this);
}

//------------------------------------------------------------------------------
// Address: 0x10005990
// Name: public: virtual void CTextConsoleWin32::UpdateStatus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextConsoleWin32::UpdateStatus(CTextConsoleWin32 *this)
{
  void *houtput; // ecx
  unsigned __int16 wAttrib[80]; // [esp+8h] [ebp-A8h] BYREF
  _COORD coord; // [esp+A8h] [ebp-8h]
  unsigned int dwWritten; // [esp+ACh] [ebp-4h] BYREF

  memset32(wAttrib, (this->Attrib << 16) | this->Attrib, 0x28u);
  houtput = this->houtput;
  coord = 0;
  dwWritten = 0;
  WriteConsoleOutputAttribute(
    hConsoleOutput: houtput,
    lpAttribute: wAttrib,
    nLength: 0x50u,
    dwWriteCoord: 0,
    lpNumberOfAttrsWritten: &dwWritten);
  WriteConsoleOutputCharacterA(
    hConsoleOutput: this->houtput,
    lpCharacter: this->statusline,
    nLength: 0x50u,
    dwWriteCoord: 0,
    lpNumberOfCharsWritten: &dwWritten);
}
