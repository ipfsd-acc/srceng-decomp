// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: dedicated/console/textconsole.cpp
// Functions: 27
// ============================================================

#include "dedicated\console\textconsole.h"

//------------------------------------------------------------------------------
// Address: 0x10004FE0
// Name: public: virtual bool CTextConsole::Init(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTextConsole::Init(CTextConsole *this)
{
  memset(dst: (unsigned __int8 *)this->m_szConsoleText, value: 0, count: sizeof(this->m_szConsoleText));
  this->m_nConsoleTextLen = 0;
  this->m_nCursorPosition = 0;
  memset(dst: (unsigned __int8 *)this->m_szSavedConsoleText, value: 0, count: sizeof(this->m_szSavedConsoleText));
  this->m_nSavedConsoleTextLen = 0;
  memset(dst: (unsigned __int8 *)this->m_aszLineBuffer, value: 0, count: sizeof(this->m_aszLineBuffer));
  this->m_nTotalLines = 0;
  this->m_nInputLine = 0;
  this->m_nBrowseLine = 0;
  _Msg(a1: "\n");
  _Msg(a1: "Console initialized.\n");
  this->m_ConsoleVisible = true;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10005060
// Name: public: virtual void CTextConsole::SetVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextConsole::SetVisible(CTextConsole *this, bool visible)
{
  this->m_ConsoleVisible = visible;
}

//------------------------------------------------------------------------------
// Address: 0x10005070
// Name: public: virtual bool CTextConsole::IsVisible(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTextConsole::IsVisible(CTextConsole *this)
{
  return this->m_ConsoleVisible;
}

//------------------------------------------------------------------------------
// Address: 0x10005080
// Name: public: virtual void CTextConsole::Print(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextConsole::Print(CTextConsole *this, char *pszMsg)
{
  int i; // edi

  for ( i = this->m_nConsoleTextLen; i != 0; --i )
    this->PrintRaw(this, a2: "\b \b", a3: 0);
  this->PrintRaw(this, a2: pszMsg, a3: 0);
  if ( this->m_nConsoleTextLen != 0 )
    this->PrintRaw(this, a2: this->m_szConsoleText, a3: this->m_nConsoleTextLen);
  this->UpdateStatus(this);
}

//------------------------------------------------------------------------------
// Address: 0x100050E0
// Name: protected: int CTextConsole::ReceiveNewline(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTextConsole::ReceiveNewline(CTextConsole *this)
{
  int m_nConsoleTextLen; // eax
  int m_nInputLine; // edi
  int v4; // eax
  int v6; // [esp+Ch] [ebp-4h]

  this->Echo(this, a2: "\n", a3: 0);
  m_nConsoleTextLen = this->m_nConsoleTextLen;
  v6 = m_nConsoleTextLen;
  if ( m_nConsoleTextLen == 0 )
    return 0;
  this->m_szConsoleText[m_nConsoleTextLen] = 0;
  m_nInputLine = this->m_nInputLine;
  this->m_nConsoleTextLen = 0;
  this->m_nCursorPosition = 0;
  if ( m_nInputLine == 0 || strcmp(&this->m_szSavedConsoleText[256 * m_nInputLine + 4], this->m_szConsoleText) != 0 )
  {
    strncpy(
      dest: (unsigned __int8 *)this->m_aszLineBuffer[m_nInputLine],
      source: (unsigned __int8 *)this->m_szConsoleText,
      count: 0x100u);
    v4 = ++this->m_nInputLine;
    if ( v4 > this->m_nTotalLines )
      this->m_nTotalLines = v4;
    if ( v4 >= 30 )
      this->m_nInputLine = 0;
  }
  this->m_nBrowseLine = this->m_nInputLine;
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x100051C0
// Name: protected: void CTextConsole::ReceiveBackspace(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CTextConsole::ReceiveBackspace(CTextConsole *this@<ecx>, int a2@<edi>)
{
  int m_nCursorPosition; // eax
  int i; // edi
  int j; // edi

  m_nCursorPosition = this->m_nCursorPosition;
  if ( m_nCursorPosition != 0 )
  {
    --this->m_nConsoleTextLen;
    this->m_nCursorPosition = m_nCursorPosition - 1;
    ((void (__thiscall *)(CTextConsole *, const char *, _DWORD, int))this->Echo)(a1: this, a2: "\b", a3: 0, a4: a2);
    for ( i = this->m_nCursorPosition; i < this->m_nConsoleTextLen; ++i )
    {
      this->m_szConsoleText[i] = this->m_szConsoleText[i + 1];
      this->Echo(this, a2: &this->m_szConsoleText[i], a3: 1);
    }
    ((void (__thiscall *)(CTextConsole *, const char *))this->Echo)(a1: this, a2: " ");
    for ( j = this->m_nConsoleTextLen; j >= this->m_nCursorPosition; --j )
      this->Echo(this, a2: "\b", a3: 0);
    this->m_nBrowseLine = this->m_nInputLine;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005270
// Name: protected: void CTextConsole::ReceiveStandardChar(char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextConsole::ReceiveStandardChar(CTextConsole *this, char ch)
{
  int m_nConsoleTextLen; // eax
  int v4; // edi

  m_nConsoleTextLen = this->m_nConsoleTextLen;
  if ( (unsigned int)m_nConsoleTextLen < 0xFE )
  {
    for ( ; m_nConsoleTextLen > this->m_nCursorPosition; --m_nConsoleTextLen )
      this->m_szConsoleText[m_nConsoleTextLen] = *((_BYTE *)&this->__vftable + m_nConsoleTextLen + 3);
    this->m_szConsoleText[this->m_nCursorPosition] = ch;
    this->Echo(
      this,
      a2: &this->m_szConsoleText[this->m_nCursorPosition],
      a3: this->m_nConsoleTextLen - this->m_nCursorPosition + 1);
    v4 = ++this->m_nConsoleTextLen;
    if ( v4 > ++this->m_nCursorPosition )
    {
      do
      {
        this->Echo(this, a2: "\b", a3: 0);
        --v4;
      }
      while ( v4 > this->m_nCursorPosition );
    }
    this->m_nBrowseLine = this->m_nInputLine;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005320
// Name: protected: void CTextConsole::ReceiveUpArrow(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextConsole::ReceiveUpArrow(CTextConsole *this)
{
  int m_nInputLine; // edx
  int v3; // eax
  int m_nBrowseLine; // ecx
  void (__thiscall *Echo)(CTextConsole *, char *, int); // eax
  int v7; // eax
  void (__thiscall *v8)(CTextConsole *, char *, int); // edx
  const char *v9; // eax
  int v10; // eax

  m_nInputLine = this->m_nInputLine;
  v3 = m_nInputLine + 1;
  if ( m_nInputLine + 1 > this->m_nTotalLines )
    v3 = 0;
  m_nBrowseLine = this->m_nBrowseLine;
  if ( m_nBrowseLine != v3 )
  {
    if ( m_nBrowseLine == m_nInputLine )
    {
      if ( this->m_nConsoleTextLen > 0 )
        strncpy(
          dest: (unsigned __int8 *)this->m_szSavedConsoleText,
          source: (unsigned __int8 *)this->m_szConsoleText,
          count: this->m_nConsoleTextLen);
      this->m_nSavedConsoleTextLen = this->m_nConsoleTextLen;
    }
    if ( --this->m_nBrowseLine < 0 )
      this->m_nBrowseLine = this->m_nTotalLines - 1;
    while ( this->m_nConsoleTextLen != 0 )
    {
      Echo = this->Echo;
      --this->m_nConsoleTextLen;
      Echo(this, a2: "\b \b", a3: 0);
    }
    v7 = this->m_nBrowseLine;
    v8 = this->Echo;
    --this->m_nConsoleTextLen;
    v8(this, a2: this->m_aszLineBuffer[v7], a3: 0);
    strncpy(
      dest: (unsigned __int8 *)this->m_szConsoleText,
      source: (unsigned __int8 *)this->m_aszLineBuffer[this->m_nBrowseLine],
      count: 0x100u);
    v9 = this->m_aszLineBuffer[this->m_nBrowseLine];
    v10 = &v9[strlen(v9) + 1] - &this->m_aszLineBuffer[this->m_nBrowseLine][1];
    this->m_nConsoleTextLen = v10;
    this->m_nCursorPosition = v10;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005430
// Name: protected: void CTextConsole::ReceiveDownArrow(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextConsole::ReceiveDownArrow(CTextConsole *this)
{
  int m_nBrowseLine; // eax
  int v3; // eax
  void (__thiscall *Echo)(CTextConsole *, char *, int); // edx
  int v5; // eax
  unsigned int m_nSavedConsoleTextLen; // eax
  const char *v7; // eax

  m_nBrowseLine = this->m_nBrowseLine;
  if ( m_nBrowseLine != this->m_nInputLine )
  {
    v3 = m_nBrowseLine + 1;
    this->m_nBrowseLine = v3;
    if ( v3 > this->m_nTotalLines )
      this->m_nBrowseLine = 0;
    while ( this->m_nConsoleTextLen != 0 )
    {
      Echo = this->Echo;
      --this->m_nConsoleTextLen;
      Echo(this, a2: "\b \b", a3: 0);
    }
    v5 = this->m_nBrowseLine;
    --this->m_nConsoleTextLen;
    if ( v5 == this->m_nInputLine )
    {
      if ( this->m_nSavedConsoleTextLen > 0 )
      {
        strncpy(
          dest: (unsigned __int8 *)this->m_szConsoleText,
          source: (unsigned __int8 *)this->m_szSavedConsoleText,
          count: this->m_nSavedConsoleTextLen);
        this->Echo(this, a2: this->m_szConsoleText, a3: this->m_nSavedConsoleTextLen);
      }
      m_nSavedConsoleTextLen = this->m_nSavedConsoleTextLen;
    }
    else
    {
      this->Echo(this, a2: this->m_aszLineBuffer[v5], a3: 0);
      strncpy(
        dest: (unsigned __int8 *)this->m_szConsoleText,
        source: (unsigned __int8 *)this->m_aszLineBuffer[this->m_nBrowseLine],
        count: 0x100u);
      v7 = this->m_aszLineBuffer[this->m_nBrowseLine];
      m_nSavedConsoleTextLen = &v7[strlen(v7) + 1] - &this->m_aszLineBuffer[this->m_nBrowseLine][1];
    }
    this->m_nConsoleTextLen = m_nSavedConsoleTextLen;
    this->m_nCursorPosition = m_nSavedConsoleTextLen;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005540
// Name: protected: void CTextConsole::ReceiveLeftArrow(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextConsole::ReceiveLeftArrow(CTextConsole *this)
{
  if ( this->m_nCursorPosition != 0 )
  {
    this->Echo(this, a2: "\b", a3: 0);
    --this->m_nCursorPosition;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005570
// Name: protected: void CTextConsole::ReceiveRightArrow(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextConsole::ReceiveRightArrow(CTextConsole *this)
{
  int m_nCursorPosition; // eax

  m_nCursorPosition = this->m_nCursorPosition;
  if ( m_nCursorPosition != this->m_nConsoleTextLen )
  {
    ((void (__stdcall *)(char *, int))this->Echo)(a1: &this->m_szConsoleText[m_nCursorPosition], a2: 1);
    ++this->m_nCursorPosition;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100055A0
// Name: protected: void CTextConsole::ReceiveTab(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextConsole::ReceiveTab(CTextConsole *this)
{
  CUtlVector<char *,CUtlMemory<char *,int> > matches; // [esp+0h] [ebp-14h] BYREF

  this->m_szConsoleText[this->m_nConsoleTextLen] = 0;
  memset(&matches, 0, sizeof(matches));
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&matches);
}

//------------------------------------------------------------------------------
// Address: 0x100B2730
// Name: _dynamic_initializer_for__console__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__console__()
{
  return atexit(func: dynamic_atexit_destructor_for__console__);
}

//------------------------------------------------------------------------------
// Address: 0x100B3900
// Name: _dynamic_atexit_destructor_for__console__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__console__()
{
  console.__vftable = (CTextConsoleWin32_vtbl *)&CTextConsole::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x100B2740
// Name: _dynamic_initializer_for__g_Sys__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Sys__()
{
  g_Sys.__vftable = (CSys_vtbl *)&CSys::`vftable';
  return atexit(func: dynamic_atexit_destructor_for__g_Sys__);
}

//------------------------------------------------------------------------------
// Address: 0x100B2790
// Name: _dynamic_initializer_for__fs_report_sync_opens__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fs_report_sync_opens__()
{
  ConVar::ConVar(
    this: &fs_report_sync_opens,
    pName: "fs_report_sync_opens",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "0:Off, 1:Always, 2:Not during map load");
  return atexit(func: dynamic_atexit_destructor_for__fs_report_sync_opens__);
}

//------------------------------------------------------------------------------
// Address: 0x100B27C0
// Name: _dynamic_initializer_for__fs_report_sync_opens_callstack__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fs_report_sync_opens_callstack__()
{
  ConVar::ConVar(
    this: &fs_report_sync_opens_callstack,
    pName: "fs_report_sync_opens_callstack",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "0 to not display the call-stack when we hit a fs_report_sync_opens warning. Set to 1 to display the call-stack.");
  return atexit(func: dynamic_atexit_destructor_for__fs_report_sync_opens_callstack__);
}

//------------------------------------------------------------------------------
// Address: 0x100B27F0
// Name: _dynamic_initializer_for__fs_report_long_reads__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fs_report_long_reads__()
{
  ConVar::ConVar(
    this: &fs_report_long_reads,
    pName: "fs_report_long_reads",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "0:Off, 1:All (for tracking accumulated duplicate read times), >1:Microsecond threshold");
  return atexit(func: dynamic_atexit_destructor_for__fs_report_long_reads__);
}

//------------------------------------------------------------------------------
// Address: 0x100B2820
// Name: _dynamic_initializer_for__fs_warning_mode__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fs_warning_mode__()
{
  ConVar::ConVar(
    this: &fs_warning_mode,
    pName: "fs_warning_mode",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "0:Off, 1:Warn main thread, 2:Warn other threads");
  return atexit(func: dynamic_atexit_destructor_for__fs_warning_mode__);
}

//------------------------------------------------------------------------------
// Address: 0x100B2850
// Name: _dynamic_initializer_for__fs_monitor_read_from_pack__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__fs_monitor_read_from_pack__()
{
  ConVar::ConVar(
    this: &fs_monitor_read_from_pack,
    pName: "fs_monitor_read_from_pack",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "0:Off, 1:Any, 2:Sync only");
  return atexit(func: dynamic_atexit_destructor_for__fs_monitor_read_from_pack__);
}

//------------------------------------------------------------------------------
// Address: 0x100B2880
// Name: _dynamic_initializer_for__g_PathIDTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_PathIDTable__()
{
  CUtlSymbolTable::CUtlSymbolTable(this: &g_PathIDTable, growSize: 0, initSize: 32, caseInsensitive: true);
  g_PathIDTable.m_lock.m_lockInfo.m_i32 = 0;
  g_PathIDTable.m_lock.m_writerId = 0;
  return atexit(func: dynamic_atexit_destructor_for__g_PathIDTable__);
}

//------------------------------------------------------------------------------
// Address: 0x100B3910
// Name: _dynamic_atexit_destructor_for__g_Sys__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_Sys__()
{
  sys = nullptr;
  g_Sys.__vftable = (CSys_vtbl *)&ISys::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x100B3960
// Name: _dynamic_atexit_destructor_for__fs_report_sync_opens__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fs_report_sync_opens__()
{
  ConVar::~ConVar(this: &fs_report_sync_opens);
}

//------------------------------------------------------------------------------
// Address: 0x100B3970
// Name: _dynamic_atexit_destructor_for__fs_report_sync_opens_callstack__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fs_report_sync_opens_callstack__()
{
  ConVar::~ConVar(this: &fs_report_sync_opens_callstack);
}

//------------------------------------------------------------------------------
// Address: 0x100B3980
// Name: _dynamic_atexit_destructor_for__fs_report_long_reads__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fs_report_long_reads__()
{
  ConVar::~ConVar(this: &fs_report_long_reads);
}

//------------------------------------------------------------------------------
// Address: 0x100B3990
// Name: _dynamic_atexit_destructor_for__fs_warning_mode__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fs_warning_mode__()
{
  ConVar::~ConVar(this: &fs_warning_mode);
}

//------------------------------------------------------------------------------
// Address: 0x100B39A0
// Name: _dynamic_atexit_destructor_for__fs_monitor_read_from_pack__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__fs_monitor_read_from_pack__()
{
  ConVar::~ConVar(this: &fs_monitor_read_from_pack);
}
