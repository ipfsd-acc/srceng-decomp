// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/getbugs/getbugs.cpp
// Functions: 24
// ============================================================

#include "utils\getbugs\getbugs.h"

//------------------------------------------------------------------------------
// Address: 0x00403530
// Name: private: void CBugReporter::ReportError(unsigned long,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugReporter::ReportError(CBugReporter *this, unsigned int rc, const char *func, const char *msg)
{
  unsigned int i; // esi

  if ( rc != 0 )
  {
    if ( rc == 21 )
    {
      _Msg(a1: "%s %s was not found!\n", func, msg);
    }
    else if ( rc == 28 )
    {
      _Msg(a1: "%s %s Invalid field!\n", func, msg);
    }
    else
    {
      for ( i = 0; i < 0x32; ++i )
      {
        if ( g_Lookup[i].id == rc )
        {
          _Msg(a1: "%s returned %i - %s (%s)!\n", func, rc, g_Lookup[i].str, msg);
          return;
        }
      }
      _Msg(a1: "%s returned %i - %s! (%s)\n", func, rc, "???", msg);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004035E0
// Name: private: unsigned long CBugReporter::Login(struct _TRK_HANDLE const __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBugReporter::Login(CBugReporter *this, const _TRK_HANDLE **pTrkHandle, const char *projectname)
{
  int v3; // esi
  char projout[256]; // [esp+Ch] [ebp-19Ch] BYREF
  char password[52]; // [esp+10Ch] [ebp-9Ch] BYREF
  char username[52]; // [esp+140h] [ebp-68h] BYREF
  char dbms[52]; // [esp+174h] [ebp-34h] BYREF

  strcpy(dbms, "tracker");
  memset(dst: (unsigned __int8 *)&dbms[8], value: 0, count: 0x2Au);
  V_strncpy(pDest: username, pSrc: "PublicUser", maxLen: 50);
  V_strncpy(pDest: password, pSrc: "PublicUser", maxLen: 50);
  v3 = TrkProjectLogin(a1: *pTrkHandle, a2: username, a3: password, a4: projectname, a5: 0, a6: 0, a7: 0, a8: 0, a9: 0);
  if ( v3 != 0
    && (v3 = TrkProjectLogin(
               a1: *pTrkHandle,
               a2: username,
               a3: setName,
               a4: projectname,
               a5: 0,
               a6: 0,
               a7: 0,
               a8: 0,
               a9: 0)) != 0 )
  {
    _Msg(a1: "Bug reporter init failed: Your tracker password must be your user name or blank.\n");
    return v3;
  }
  else
  {
    TrkGetLoginDBMSName(a1: *pTrkHandle, a2: 50, a3: dbms);
    TrkGetLoginProjectName(a1: *pTrkHandle, a2: 256, a3: projout);
    _Msg(a1: "Project:  %s\n", projout);
    _Msg(a1: "Server:  %s\n", dbms);
    return v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004036F0
// Name: public: virtual bool CBugReporter::Init(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBugReporter::Init(CBugReporter *this, const char *projectname)
{
  const _TRK_HANDLE **p_trkHandle; // edi
  unsigned int v4; // eax
  unsigned int v6; // eax

  p_trkHandle = &this->trkHandle;
  v4 = TrkHandleAlloc(a1: 400005, a2: &this->trkHandle);
  if ( v4 != 0 )
  {
    CBugReporter::ReportError(this, rc: v4, func: "TrkHandleAlloc", msg: "Failed to Allocate Tracker Handle!");
    return 0;
  }
  if ( CBugReporter::Login(this, pTrkHandle: p_trkHandle, projectname) != 0 )
    return 0;
  v6 = TrkRecordHandleAlloc(a1: *p_trkHandle, a2: &this->trkRecHandle);
  if ( v6 == 0 )
    return 1;
  CBugReporter::ReportError(
    this,
    rc: v6,
    func: "TrkRecordHandleAlloc",
    msg: "Failed to Allocate Tracker Record Handle!");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00403770
// Name: public: virtual void CBugReporter::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugReporter::Shutdown(CBugReporter *this)
{
  unsigned int v2; // eax
  unsigned int v3; // eax
  unsigned int v4; // eax

  if ( this->trkRecHandle != nullptr )
  {
    v2 = TrkRecordHandleFree(a1: &this->trkRecHandle);
    if ( v2 != 0 )
      CBugReporter::ReportError(this, rc: v2, func: "TrkRecordHandleFree", msg: "Failed to Free Tracker Record Handle!");
  }
  if ( this->trkHandle != nullptr )
  {
    v3 = TrkProjectLogout(a1: this->trkHandle);
    if ( v3 != 0 )
    {
      CBugReporter::ReportError(this, rc: v3, func: "TrkProjectLogout", msg: "Failed to Logout of Project!");
    }
    else
    {
      v4 = TrkHandleFree(a1: &this->trkHandle);
      if ( v4 != 0 )
        CBugReporter::ReportError(this, rc: v4, func: "TrkHandleFree", msg: "Failed to Free Tracker Handle!");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004037F0
// Name: void vprint(int,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void vprint(int depth, char *fmt, ...)
{
  _iobuf *v2; // edi
  int v3; // esi
  char *i; // esi
  char string[8192]; // [esp+Ch] [ebp-2000h] BYREF
  va_list ap; // [esp+201Ch] [ebp+10h] BYREF

  va_start(ap, fmt);
  vsprintf(string, format: fmt, ap);
  v2 = nullptr;
  if ( uselogfile )
    v2 = fopen(file: "log.txt", mode: "ab");
  v3 = depth;
  while ( v3 > 0 )
  {
    --v3;
    printf(format: "  ");
    OutputDebugStringA(lpOutputString: "  ");
    if ( v2 != nullptr )
      fprintf(str: v2, format: "  ");
  }
  printf(format: string);
  OutputDebugStringA(lpOutputString: string);
  if ( v2 != nullptr )
  {
    for ( i = string; *i != 0; fputc(ch: *i++, str: v2) )
    {
      if ( *i == 10 )
        fputc(ch: 13, str: v2);
    }
    fclose(stream: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004038E0
// Name: void printusage(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __noreturn printusage()
{
  vprint(
    depth: 0,
    fmt: "usage:  getbugs pvcsproject hostname database username password contentadminexe <startbug endbug>\n"
    "\t\t\n"
    "e.g.:  getbugs \"Steam Beta\" steamweb cserr username password \"u:/p4clients/yahn_steam_work/projects/gazelleproto/"
    "tools/contentadmin/vc70_debug_static/contentadmin.exe\" 1 10\n");
  exit(code: 1);
}

//------------------------------------------------------------------------------
// Address: 0x00403900
// Name: bool GetBugZip(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl GetBugZip(int bugnum, const char *admin)
{
  bool v2; // bl
  DWORD LastError; // eax
  char commandline[512]; // [esp+8h] [ebp-45Ch] BYREF
  char directory[512]; // [esp+208h] [ebp-25Ch] BYREF
  _STARTUPINFOA StartupInfo; // [esp+408h] [ebp-5Ch] BYREF
  _PROCESS_INFORMATION pi; // [esp+44Ch] [ebp-18h] BYREF
  unsigned int exitCode; // [esp+45Ch] [ebp-8h] BYREF
  void *lpMsgBuf; // [esp+460h] [ebp-4h] BYREF

  v2 = false;
  V_strncpy(pDest: directory, pSrc: admin, maxLen: 512);
  V_StripFilename(path: directory);
  sprintf(string: commandline, format: "\"%s\" bugreport %i", admin, bugnum);
  memset(&pi, 0, sizeof(pi));
  memset(dst: (unsigned __int8 *)&StartupInfo, value: 0, count: sizeof(StartupInfo));
  StartupInfo.cb = 68;
  if ( CreateProcessA(
         lpApplicationName: nullptr,
         lpCommandLine: commandline,
         lpProcessAttributes: nullptr,
         lpThreadAttributes: nullptr,
         bInheritHandles: true,
         dwCreationFlags: 0,
         lpEnvironment: nullptr,
         lpCurrentDirectory: directory,
         lpStartupInfo: &StartupInfo,
         lpProcessInformation: &pi) )
  {
    WaitForSingleObject(hHandle: pi.hProcess, dwMilliseconds: 0xFFFFFFFF);
    exitCode = -1;
    if ( GetExitCodeProcess(hProcess: pi.hProcess, lpExitCode: &exitCode) )
      v2 = exitCode == 0;
    CloseHandle(hObject: pi.hProcess);
    CloseHandle(hObject: pi.hThread);
    return v2;
  }
  else
  {
    LastError = GetLastError();
    FormatMessageA(
      dwFlags: 0x1300u,
      lpSource: nullptr,
      dwMessageId: LastError,
      dwLanguageId: 0x400u,
      lpBuffer: (LPSTR)&lpMsgBuf,
      nSize: 0,
      Arguments: nullptr);
    MessageBoxA(hWnd: nullptr, lpText: (LPCSTR)lpMsgBuf, lpCaption: "Error", uType: 0x40u);
    LocalFree(hMem: lpMsgBuf);
    return false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403A20
// Name: void CreateDirHierarchy(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CreateDirHierarchy(const char *path)
{
  char *i; // esi
  char v2; // bl
  char temppath[512]; // [esp+4h] [ebp-200h] BYREF

  V_strncpy(pDest: temppath, pSrc: path, maxLen: 512);
  for ( i = &temppath[1]; *i != 0; ++i )
  {
    v2 = *i;
    if ( *i == 47 || v2 == 92 )
    {
      *i = 0;
      _mkdir(path: temppath);
      *i = v2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403A80
// Name: private: void CBugReporter::SubstituteBugId(int,char __near *,int,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugReporter::SubstituteBugId(CBugReporter *this, int bugid, char *out, int outlen, CUtlBuffer *src)
{
  char *v5; // esi
  CUtlBuffer *v6; // edi
  int v7; // ebx
  const char *v8; // edi
  char *v9; // esi
  char v10; // al
  char *i; // ecx
  char num[32]; // [esp+Ch] [ebp-24h] BYREF
  int replace_len; // [esp+2Ch] [ebp-4h]

  v5 = out;
  v6 = src;
  *out = 0;
  CUtlBuffer::SeekGet(this: src, type: SEEK_HEAD, offset: 0);
  v7 = 0;
  replace_len = _V_strlen(str: "\\BugId\\");
  if ( src->m_Put >= 0 )
  {
    while ( v5 - out < outlen )
    {
      v8 = (const char *)&src->m_Memory.m_pMemory[v6->m_Get - src->m_nOffset + v7];
      if ( V_strnicmp(s1: v8, s2: "\\BugId\\", n: replace_len) != 0 )
      {
        *v5++ = *v8;
        ++v7;
      }
      else
      {
        *v5 = 92;
        v9 = v5 + 1;
        V_snprintf(pDest: num, maxLen: 32, pFormat: "%i", bugid);
        v10 = num[0];
        for ( i = num; *i != 0; ++v9 )
        {
          ++i;
          *v9 = v10;
          v10 = *i;
        }
        *v9 = 92;
        v5 = v9 + 1;
        v7 += replace_len;
      }
      if ( v7 > src->m_Put )
        break;
      v6 = src;
    }
    *v5 = 0;
  }
  else
  {
    *out = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403B50
// Name: public: virtual enum LoggingResponse_t CNonFatalLoggingResponsePolicy::OnLog(struct LoggingContext_t const __near *)
// Source: json
//------------------------------------------------------------------------------
LoggingResponse_t __thiscall CNonFatalLoggingResponsePolicy::OnLog(
        CNonFatalLoggingResponsePolicy *this,
        const LoggingContext_t *pContext)
{
  int v2; // eax
  LoggingResponse_t result; // eax

  result = pContext->m_Severity == LS_ASSERT
        && (v2 = _CommandLine(a1: this),
            (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v2 + 40))(a1: v2, a2: "-noassert") == 0)
        || pContext->m_Severity == LS_ERROR;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00403B90
// Name: public: void CUtlMemory<struct BugField_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<BugField_t,int>::Grow(CUtlMemory<BugField_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  BugField_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 8456 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (BugField_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (BugField_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403C30
// Name: public: void CUtlMemory<int,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<int,int>::Grow(CUtlMemory<KeyValues *,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  KeyValues **m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 8;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 4 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (KeyValues **)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (KeyValues **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403CC0
// Name: protected: void CUtlBuffer::PutTypeBin<char>(char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTypeBin<char>(CUtlBuffer *this, char src)
{
  if ( CUtlBuffer::CheckPut(this, nSize: 1) )
  {
    this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = src;
    CUtlBuffer::AddNullTermination(this, nPut: ++this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403D00
// Name: protected: void CUtlBuffer::PutTabs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTabs(CUtlBuffer *this)
{
  int m_nTab; // eax
  int i; // ebx

  if ( (this->m_Flags & 0x10) != 0 )
    m_nTab = 0;
  else
    m_nTab = this->m_nTab;
  for ( i = m_nTab - 1; i >= 0; --i )
  {
    if ( CUtlBuffer::CheckPut(this, nSize: 1) )
    {
      this->m_Memory.m_pMemory[this->m_Put++ - this->m_nOffset] = 9;
      CUtlBuffer::AddNullTermination(this, nPut: this->m_Put);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403D50
// Name: public: virtual void CBugReporter::StartNewBugReport(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugReporter::StartNewBugReport(CBugReporter *this)
{
  this->m_Fields.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00403D60
// Name: public: CUtlBuffer::~CUtlBuffer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::~CUtlBuffer(CUtlBuffer *this)
{
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403D90
// Name: public: CUtlVector<void (*)(class IConVar __near *,char const __near *,float),class CUtlMemory<void (*)(class IConVar __near *,char const __near *,float),int>>::~CUtlVector<void (*)(class IConVar __near *,char const __near *,float),class CUtlMemory<void (*)(class IConVar __near *,char const __near *,float),int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(
        CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *this)
{
  bool v2; // sf
  void (__cdecl **m_pMemory)(IConVar *, const char *, float); // eax

  v2 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403E00
// Name: public: int CUtlVector<struct BugField_t,class CUtlMemory<struct BugField_t,int>>::InsertBefore(int,struct BugField_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<BugField_t,CUtlMemory<BugField_t,int>>::InsertBefore(
        CUtlVector<BugField_t,CUtlMemory<BugField_t,int> > *this,
        int elem,
        BugField_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  BugField_t *m_pMemory; // ecx
  int v7; // eax
  BugField_t *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<BugField_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 8456 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    memcpy(dst: (unsigned __int8 *)v8, (unsigned __int8 *)src, count: sizeof(BugField_t));
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00403E80
// Name: public: virtual bool CBugReporter::IsPublicUI(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBugReporter::IsPublicUI(ConVar *this)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x00403E90
// Name: public: virtual bool CBugReporter::CommitBugReport(int __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBugReporter::CommitBugReport(CBugReporter *this, int *bugSubmissionId)
{
  int m_Size; // ebx
  unsigned int v4; // eax
  BugField_t *v6; // edi
  const _TRK_RECORD_HANDLE *trkRecHandle; // eax
  int v8; // eax
  unsigned int v9; // ebx
  unsigned int v10; // eax
  unsigned int v11; // eax
  unsigned int NumericFieldValue; // eax
  unsigned int SingleRecord; // eax
  unsigned int updated; // eax
  int v15; // ebx
  void *v16; // edi
  int v17; // eax
  unsigned int v18; // ebx
  unsigned int v19; // eax
  char pDest[256]; // [esp+Ch] [ebp-144h] BYREF
  unsigned int id; // [esp+10Ch] [ebp-44h] BYREF
  int fieldCount; // [esp+110h] [ebp-40h]
  CUtlBuffer buf; // [esp+114h] [ebp-3Ch] BYREF
  int i; // [esp+144h] [ebp-Ch]
  unsigned int v25; // [esp+148h] [ebp-8h]
  unsigned int bugId; // [esp+14Ch] [ebp-4h] BYREF

  *bugSubmissionId = -1;
  m_Size = this->m_Fields.m_Size;
  fieldCount = m_Size;
  if ( m_Size == 0 )
    return 0;
  v4 = TrkNewRecordBegin(a1: this->trkRecHandle, a2: 1);
  if ( v4 != 0 )
  {
    CBugReporter::ReportError(this, rc: v4, func: "TrkNewRecordBegin", msg: "Failed to TrkNewRecordBegin!");
    return 0;
  }
  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 1);
  i = 0;
  if ( m_Size <= 0 )
  {
LABEL_21:
    v11 = TrkNewRecordCommit(a1: this->trkRecHandle, a2: &id);
    if ( v11 != 0 )
    {
      CBugReporter::ReportError(this, rc: v11, func: "TrkNewRecordCommit", msg: "Failed to TrkNewRecordCommit!");
    }
    else
    {
      NumericFieldValue = TrkGetNumericFieldValue(a1: this->trkRecHandle, a2: "Id", a3: &bugId);
      if ( NumericFieldValue != 0 )
        CBugReporter::ReportError(
          this,
          rc: NumericFieldValue,
          func: "TrkGetNumericFieldValue",
          msg: "Failed to TrkGetNumericFieldValue for bug Id #!");
      else
        *bugSubmissionId = bugId;
      SingleRecord = TrkGetSingleRecord(a1: this->trkRecHandle, a2: bugId, a3: 1);
      if ( SingleRecord == 0 )
      {
        updated = TrkUpdateRecordBegin(a1: this->trkRecHandle);
        if ( updated == 0 )
        {
          v15 = 2 * buf.m_Put + 1;
          v16 = operator new(nSize: v15);
          _V_memset(dest: v16, fill: 0, count: v15);
          CBugReporter::SubstituteBugId(this, bugid: bugId, out: (char *)v16, outlen: v15, src: &buf);
          v17 = _V_strlen(str: (const char *)v16);
          v18 = TrkSetDescriptionData(a1: this->trkRecHandle, a2: v17 + 1, a3: v16, a4: 0);
          free(pMem: v16);
          if ( v18 != 0 )
          {
            CBugReporter::ReportError(
              this,
              rc: v18,
              func: "TrkSetDescriptionData(update)",
              msg: "Failed to set description data!");
            CUtlBuffer::~CUtlBuffer(this: &buf);
            return 0;
          }
          else
          {
            v19 = TrkUpdateRecordCommit(a1: this->trkRecHandle, a2: &id);
            if ( v19 != 0 )
            {
              CBugReporter::ReportError(
                this,
                rc: v19,
                func: "TrkUpdateRecordCommit",
                msg: "Failed to TrkUpdateRecordCommit for bug Id #!");
              CUtlBuffer::~CUtlBuffer(this: &buf);
              return 0;
            }
            else
            {
              this->m_Fields.m_Size = 0;
              CUtlBuffer::~CUtlBuffer(this: &buf);
              return 1;
            }
          }
        }
        CBugReporter::ReportError(
          this,
          rc: updated,
          func: "TrkUpdateRecordBegin",
          msg: "Failed to open bug id for update");
        if ( buf.m_Memory.m_nGrowSize < 0 || buf.m_Memory.m_pMemory == nullptr )
          return 0;
LABEL_30:
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
        return 0;
      }
      CBugReporter::ReportError(
        this,
        rc: SingleRecord,
        func: "TrkGetSingleRecord",
        msg: "Failed to open bug id for update");
    }
LABEL_28:
    if ( buf.m_Memory.m_nGrowSize < 0 || buf.m_Memory.m_pMemory == nullptr )
      return 0;
    goto LABEL_30;
  }
  v25 = 0;
  while ( 1 )
  {
    v6 = &this->m_Fields.m_Memory.m_pMemory[v25 / 0x2108];
    if ( !v6->isdesc )
      break;
    CUtlBuffer::Printf(this: &buf, pFmt: "%s\n", this->m_Fields.m_Memory.m_pMemory[v25 / 0x2108].value);
    if ( (buf.m_Flags & 1) != 0 && buf.m_Put != 0 && buf.m_Memory.m_pMemory[buf.m_Put - buf.m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: &buf);
    if ( CUtlBuffer::CheckPut(this: &buf, nSize: 1) )
    {
      buf.m_Memory.m_pMemory[buf.m_Put - buf.m_nOffset] = 0;
      CUtlBuffer::AddNullTermination(this: &buf, nPut: ++buf.m_Put);
    }
    v10 = TrkSetDescriptionData(a1: this->trkRecHandle, a2: buf.m_Put, a3: buf.m_Memory.m_pMemory, a4: 0);
    if ( v10 != 0 )
    {
      CBugReporter::ReportError(this, rc: v10, func: "TrkSetDescriptionData", msg: "Failed to set description data!");
      goto LABEL_28;
    }
LABEL_20:
    v25 += 8456;
    if ( ++i >= m_Size )
      goto LABEL_21;
  }
  trkRecHandle = this->trkRecHandle;
  if ( v6->isnumeric )
    v8 = TrkSetNumericFieldValue(a1: trkRecHandle, a2: v6->trkfield, a3: v6->numvalue);
  else
    v8 = TrkSetStringFieldValue(
           a1: trkRecHandle,
           a2: v6->trkfield,
           a3: &this->m_Fields.m_Memory.m_pMemory[v25 / 0x2108]);
  v9 = v8;
  if ( v8 == 0 )
  {
    m_Size = fieldCount;
    goto LABEL_20;
  }
  V_snprintf(pDest, maxLen: 256, pFormat: "Failed to add '%s'", v6->trkfield);
  CBugReporter::ReportError(this, rc: v9, func: "TrkSetStringFieldValue", msg: pDest);
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00404200
// Name: public: virtual void CBugReporter::AddField(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugReporter::AddField(CBugReporter *this, char *fieldname, char *value, bool isdesc)
{
  int m_Size; // eax
  BugField_t pDest; // [esp+8h] [ebp-2108h] BYREF

  pDest.value[0] = 0;
  pDest.numvalue = 0;
  pDest.trkfield[0] = 0;
  *(_WORD *)&pDest.isdesc = 0;
  V_strncpy(pDest: pDest.value, pSrc: value, maxLen: 0x2000);
  pDest.isnumeric = false;
  V_strncpy(pDest: pDest.trkfield, pSrc: fieldname, maxLen: 256);
  m_Size = this->m_Fields.m_Size;
  pDest.isdesc = isdesc;
  CUtlVector<BugField_t,CUtlMemory<BugField_t,int>>::InsertBefore(this: &this->m_Fields, elem: m_Size, src: &pDest);
}

//------------------------------------------------------------------------------
// Address: 0x00404280
// Name: public: virtual void CBugReporter::AddNumericField(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBugReporter::AddNumericField(CBugReporter *this, char *fieldname, int value)
{
  int m_Size; // [esp-8h] [ebp-2118h]
  BugField_t src; // [esp+8h] [ebp-2108h] BYREF

  src.value[0] = 0;
  src.trkfield[0] = 0;
  src.numvalue = value;
  *(_WORD *)&src.isdesc = 256;
  V_strncpy(pDest: src.trkfield, pSrc: fieldname, maxLen: 256);
  m_Size = this->m_Fields.m_Size;
  src.isdesc = false;
  CUtlVector<BugField_t,CUtlMemory<BugField_t,int>>::InsertBefore(this: &this->m_Fields, elem: m_Size, &src);
}

//------------------------------------------------------------------------------
// Address: 0x00404330
// Name: void GetBugInfo(class CBugReporter __near &,char const __near *,char const __near *,char const __near *,char const __near *,char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall GetBugInfo(
        int a1@<edi>,
        CBugReporter *bug,
        const char *host,
        const char *database,
        const char *username,
        const char *password,
        char *admin,
        int startbug,
        int endbug)
{
  struct CSysModule *Module; // eax
  struct CSysModule *v10; // esi
  int v11; // ebx
  void *(__cdecl *Factory)(const char *, int *); // eax
  int v13; // eax
  int v14; // edi
  int v15; // eax
  int v16; // esi
  int v17; // eax
  const char *v18; // eax
  int v19; // eax
  int v20; // eax
  const char *v21; // eax
  const char *v22; // eax
  const char *v23; // eax
  const char *v24; // eax
  const char *v25; // eax
  int v26; // eax
  const char *v27; // eax
  int v28; // eax
  const char *v29; // eax
  int v30; // ebx
  int v31; // eax
  int v32; // eax
  int v33; // eax
  const char *v34; // eax
  const char *v35; // eax
  const char *v36; // eax
  const char *v37; // eax
  const char *v38; // eax
  const char *v39; // eax
  bool (__thiscall *CommitBugReport)(CBugReporter *, int *); // edx
  int v41; // eax
  int v42; // eax
  int v43; // eax
  int m_Size; // eax
  int v45; // ebx
  void (__cdecl **m_pMemory)(IConVar *, const char *, float); // ecx
  int v47; // eax
  void (__cdecl **v48)(IConVar *, const char *, float); // ebx
  int i; // esi
  struct CSysModule *v50; // esi
  char *v51; // [esp-Ch] [ebp-3050h]
  char v53[8192]; // [esp+8h] [ebp-303Ch] BYREF
  char v54[512]; // [esp+2008h] [ebp-103Ch] BYREF
  char maxlen[512]; // [esp+2208h] [ebp-E3Ch] BYREF
  char v56[512]; // [esp+2408h] [ebp-C3Ch] BYREF
  char path[512]; // [esp+2608h] [ebp-A3Ch] BYREF
  char start[512]; // [esp+2808h] [ebp-83Ch] BYREF
  char pname[512]; // [esp+2A08h] [ebp-63Ch] BYREF
  char pDest[256]; // [esp+2C08h] [ebp-43Ch] BYREF
  char v61[512]; // [esp+2D08h] [ebp-33Ch] BYREF
  _stat64i32 buf; // [esp+2F08h] [ebp-13Ch] BYREF
  char v63[32]; // [esp+2F38h] [ebp-10Ch] BYREF
  _BYTE v64[8]; // [esp+2F58h] [ebp-ECh] BYREF
  _BYTE v65[8]; // [esp+2F60h] [ebp-E4h] BYREF
  _BYTE v66[8]; // [esp+2F68h] [ebp-DCh] BYREF
  _BYTE v67[8]; // [esp+2F70h] [ebp-D4h] BYREF
  _DWORD v68[2]; // [esp+2F78h] [ebp-CCh] BYREF
  _DWORD v69[2]; // [esp+2F80h] [ebp-C4h] BYREF
  _DWORD v70[2]; // [esp+2F88h] [ebp-BCh] BYREF
  _DWORD v71[2]; // [esp+2F90h] [ebp-B4h] BYREF
  _DWORD v72[2]; // [esp+2F98h] [ebp-ACh] BYREF
  _DWORD v73[2]; // [esp+2FA0h] [ebp-A4h] BYREF
  _DWORD v74[2]; // [esp+2FA8h] [ebp-9Ch] BYREF
  _DWORD v75[2]; // [esp+2FB0h] [ebp-94h] BYREF
  _DWORD v76[2]; // [esp+2FB8h] [ebp-8Ch] BYREF
  _DWORD v77[2]; // [esp+2FC0h] [ebp-84h] BYREF
  _DWORD v78[2]; // [esp+2FC8h] [ebp-7Ch] BYREF
  _DWORD v79[2]; // [esp+2FD0h] [ebp-74h] BYREF
  _DWORD v80[2]; // [esp+2FD8h] [ebp-6Ch] BYREF
  _DWORD v81[2]; // [esp+2FE0h] [ebp-64h] BYREF
  _DWORD v82[2]; // [esp+2FE8h] [ebp-5Ch] BYREF
  _DWORD v83[2]; // [esp+2FF0h] [ebp-54h] BYREF
  _DWORD v84[2]; // [esp+2FF8h] [ebp-4Ch] BYREF
  _DWORD v85[2]; // [esp+3000h] [ebp-44h] BYREF
  int v86; // [esp+3008h] [ebp-3Ch]
  struct CSysModule *pModule; // [esp+300Ch] [ebp-38h]
  int v88; // [esp+3010h] [ebp-34h] BYREF
  int v89; // [esp+3014h] [ebp-30h]
  int v90; // [esp+3018h] [ebp-2Ch] BYREF
  char *out; // [esp+301Ch] [ebp-28h]
  int v92; // [esp+3020h] [ebp-24h] BYREF
  int v93; // [esp+3024h] [ebp-20h]
  CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > v94; // [esp+3028h] [ebp-1Ch] BYREF
  int v95; // [esp+303Ch] [ebp-8h] BYREF
  int v96; // [esp+3040h] [ebp-4h]

  Module = Sys_LoadModule(pModuleName: "mysql_wrapper");
  v10 = Module;
  v11 = 0;
  pModule = Module;
  if ( Module == nullptr )
  {
    vprint(depth: 0, fmt: "Unable to load mysql_wrapper.dll, not updating access mysql table!!!");
    return;
  }
  Factory = Sys_GetFactory(pModule: Module);
  if ( Factory == nullptr )
  {
    vprint(depth: 0, fmt: "Unable to get factory from mysql_wrapper.dll, not updating access mysql table!!!");
    goto LABEL_40;
  }
  v13 = (int)Factory(a1: "MySQLWrapper001", a2: nullptr);
  v14 = v13;
  v86 = v13;
  if ( v13 == 0 )
  {
    vprint(depth: 0, fmt: "Unable to connect via mysql_wrapper\n");
LABEL_40:
    Sys_UnloadModule(pModule: v10);
    return;
  }
  if ( (*(unsigned __int8 (__thiscall **)(int, const char *, const char *, const char *, const char *))(*(_DWORD *)v13 + 40))(
         a1: v13,
         a2: database,
         a3: host,
         a4: username,
         a5: password) != 0 )
  {
    pDest[0] = 0;
    if ( startbug != -1 && endbug != -1 )
      V_snprintf(pDest, maxLen: 256, pFormat: "BugId>=%i and BugId<=%i and ", startbug, endbug);
    V_snprintf(
      pDest: v61,
      maxLen: 512,
      pFormat: "select BugId, Time, BuildNumber, ExeName, GameDirectory, MapName, Title, Description, IP,BaseIP, RAM, CPU, Process"
      "orVendor, DXVersionHighPart, DXVersionLowPart, DXVendorID, DXDeviceID, OSVersion, BugReportFilePath, ReportType, E"
      "Mail, AccountName, SteamID, Processed, Important from bugreports where %s ( Processed is NULL or Processed = 0 );",
      pDest);
    if ( (*(int (__thiscall **)(int, char *))(*(_DWORD *)v14 + 44))(a1: v14, a2: v61) != 0 )
    {
      vprint(depth: 0, fmt: "Query %s failed\n", v61);
      (**(void (__thiscall ***)(int))v14)(a1: v14);
      Sys_UnloadModule(pModule: v10);
      return;
    }
    v15 = (*(int (__thiscall **)(int))(*(_DWORD *)v14 + 48))(a1: v14);
    v16 = v15;
    memset(&v94, 0, sizeof(v94));
    if ( v15 != 0 && (*(int (__thiscall **)(int))(*(_DWORD *)v15 + 4))(a1: v15) > 0 )
    {
      if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v16 + 12))(a1: v16) != 0 )
      {
        while ( 1 )
        {
          (*(void (__thiscall **)(int, int *, const char *, int))(*(_DWORD *)v16 + 20))(
            a1: v16,
            a2: &v95,
            a3: "BugId",
            a4: a1);
          (*(void (__thiscall **)(int, _DWORD *, const char *))(*(_DWORD *)v16 + 20))(a1: v16, a2: v83, a3: "Time");
          (*(void (__thiscall **)(int, _DWORD *, const char *))(*(_DWORD *)v16 + 20))(
            a1: v16,
            a2: v75,
            a3: "BuildNumber");
          (*(void (__thiscall **)(int, _DWORD *, const char *))(*(_DWORD *)v16 + 20))(a1: v16, a2: v70, a3: "ExeName");
          (*(void (__thiscall **)(int, _DWORD *, const char *))(*(_DWORD *)v16 + 20))(
            a1: v16,
            a2: v68,
            a3: "GameDirectory");
          (*(void (__thiscall **)(int, _DWORD *, const char *))(*(_DWORD *)v16 + 20))(a1: v16, a2: v81, a3: "MapName");
          (*(void (__thiscall **)(int, _DWORD *, const char *))(*(_DWORD *)v16 + 20))(a1: v16, a2: v78, a3: "Title");
          (*(void (__thiscall **)(int, int *, const char *))(*(_DWORD *)v16 + 20))(a1: v16, a2: &v88, a3: "Description");
          (*(void (__thiscall **)(int, _BYTE *, const char *))(*(_DWORD *)v16 + 20))(a1: v16, a2: v67, a3: "IP");
          (*(void (__thiscall **)(int, _BYTE *, const char *))(*(_DWORD *)v16 + 20))(a1: v16, a2: v66, a3: "BaseIP");
          (*(void (__thiscall **)(int, _DWORD *, const char *))(*(_DWORD *)v16 + 20))(a1: v16, a2: v73, a3: "RAM");
          (*(void (__thiscall **)(int, _DWORD *, const char *))(*(_DWORD *)v16 + 20))(a1: v16, a2: v69, a3: "CPU");
          (*(void (__thiscall **)(int, _DWORD *, const char *))(*(_DWORD *)v16 + 20))(
            a1: v16,
            a2: v79,
            a3: "ProcessorVendor");
          (*(void (__thiscall **)(int, _DWORD *, const char *))(*(_DWORD *)v16 + 20))(
            a1: v16,
            a2: v82,
            a3: "DXVersionHighPart");
          (*(void (__thiscall **)(int, _DWORD *, const char *))(*(_DWORD *)v16 + 20))(
            a1: v16,
            a2: v80,
            a3: "DXVersionLowPart");
          (*(void (__thiscall **)(int, _DWORD *, const char *))(*(_DWORD *)v16 + 20))(
            a1: v16,
            a2: v76,
            a3: "DXVendorID");
          (*(void (__thiscall **)(int, _DWORD *, const char *))(*(_DWORD *)v16 + 20))(
            a1: v16,
            a2: v85,
            a3: "DXDeviceID");
          (*(void (__thiscall **)(int, _DWORD *, const char *))(*(_DWORD *)v16 + 20))(a1: v16, a2: v71, a3: "OSVersion");
          (*(void (__thiscall **)(int, int *, const char *))(*(_DWORD *)v16 + 20))(
            a1: v16,
            a2: &v90,
            a3: "BugReportFilePath");
          (*(void (__thiscall **)(int, _DWORD *, const char *))(*(_DWORD *)v16 + 20))(
            a1: v16,
            a2: v74,
            a3: "ReportType");
          (*(void (__thiscall **)(int, _DWORD *, const char *))(*(_DWORD *)v16 + 20))(a1: v16, a2: v72, a3: "EMail");
          (*(void (__thiscall **)(int, _DWORD *, const char *))(*(_DWORD *)v16 + 20))(
            a1: v16,
            a2: v84,
            a3: "Accountname");
          (*(void (__thiscall **)(int, _DWORD *, const char *))(*(_DWORD *)v16 + 20))(a1: v16, a2: v77, a3: "SteamID");
          (*(void (__thiscall **)(int, _BYTE *, const char *))(*(_DWORD *)v16 + 20))(a1: v16, a2: v65, a3: "Processed");
          (*(void (__thiscall **)(int, _BYTE *, const char *))(*(_DWORD *)v16 + 20))(a1: v16, a2: v64, a3: "Important");
          bug->StartNewBugReport(this: bug);
          v17 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v95 + 32))(a1: v95, a2: v96);
          vprint(depth: 1, fmt: "Processing bug %i\n", v17);
          bug->AddField(this: bug, a2: "Owner", a3: "PublicUser", a4: false);
          bug->AddField(this: bug, a2: "Submitter", a3: "PublicUser", a4: false);
          v18 = (const char *)(*(int (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)v78[0] + 28))(a1: v78[0], a2: v78[1]);
          bug->AddField(this: bug, a2: "Title", a3: v18, a4: false);
          v19 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v95 + 32))(a1: v95, a2: v96);
          bug->AddNumericField(this: bug, a2: "BugId", a3: v19);
          v20 = (*(int (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)v75[0] + 32))(a1: v75[0], a2: v75[1]);
          bug->AddNumericField(this: bug, a2: "Build", a3: v20);
          v21 = (const char *)(*(int (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)v70[0] + 28))(a1: v70[0], a2: v70[1]);
          bug->AddField(this: bug, a2: "Exe", a3: v21, a4: false);
          v22 = (const char *)(*(int (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)v68[0] + 28))(a1: v68[0], a2: v68[1]);
          bug->AddField(this: bug, a2: "Gamedir", a3: v22, a4: false);
          v23 = (const char *)(*(int (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)v81[0] + 28))(a1: v81[0], a2: v81[1]);
          bug->AddField(this: bug, a2: "Map", a3: v23, a4: false);
          v24 = (const char *)(*(int (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)v71[0] + 28))(a1: v71[0], a2: v71[1]);
          bug->AddField(this: bug, a2: "Operating System", a3: v24, a4: false);
          v25 = (const char *)(*(int (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)v79[0] + 28))(a1: v79[0], a2: v79[1]);
          bug->AddField(this: bug, a2: "Processor", a3: v25, a4: false);
          v26 = (*(int (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)v73[0] + 32))(a1: v73[0], a2: v73[1]);
          bug->AddNumericField(this: bug, a2: "Memory", a3: v26);
          v27 = (const char *)(*(int (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)v77[0] + 28))(a1: v77[0], a2: v77[1]);
          bug->AddField(this: bug, a2: "SteamID", a3: v27, a4: false);
          v28 = (*(int (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)v69[0] + 32))(a1: v69[0], a2: v69[1]);
          bug->AddNumericField(this: bug, a2: "CPU", a3: v28);
          v29 = (const char *)(*(int (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)v83[0] + 28))(a1: v83[0], a2: v83[1]);
          bug->AddField(this: bug, a2: "Time", a3: v29, a4: false);
          v30 = (*(int (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)v82[0] + 32))(a1: v82[0], a2: v82[1]);
          v31 = (*(int (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)v80[0] + 32))(a1: v80[0], a2: v80[1]);
          V_snprintf(
            pDest: v54,
            maxLen: 512,
            pFormat: "%u.%u.%u.%u",
            v30 >> 16,
            (unsigned __int16)v30,
            v31 >> 16,
            (unsigned __int16)v31);
          bug->AddField(this: bug, a2: "DXVersion", a3: v54, a4: false);
          v32 = (*(int (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)v85[0] + 32))(a1: v85[0], a2: v85[1]);
          bug->AddNumericField(this: bug, a2: "DXDevice", a3: v32);
          v33 = (*(int (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)v76[0] + 32))(a1: v76[0], a2: v76[1]);
          bug->AddNumericField(this: bug, a2: "DXVendor", a3: v33);
          v34 = (const char *)(*(int (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)v74[0] + 28))(a1: v74[0], a2: v74[1]);
          bug->AddField(this: bug, a2: "BugType", a3: v34, a4: false);
          v35 = (const char *)(*(int (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)v72[0] + 28))(a1: v72[0], a2: v72[1]);
          bug->AddField(this: bug, a2: "E-Mail Address", a3: v35, a4: false);
          v36 = (const char *)(*(int (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)v84[0] + 28))(a1: v84[0], a2: v84[1]);
          bug->AddField(this: bug, a2: "Account Name", a3: v36, a4: false);
          v56[0] = 0;
          v51 = out;
          v37 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v90 + 28))(a1: v90);
          V_FileBase(in: v37, out: v51, (int)maxlen);
          if ( *(_BYTE *)(*(int (__thiscall **)(int, char *, int))(*(_DWORD *)v90 + 28))(a1: v90, a2: out, a3: 512) != 0 )
          {
            V_snprintf(
              pDest: v56,
              maxLen: 512,
              pFormat: "\\\\fileserver\\bugs\\public\\%s\\%s\\%s.zip",
              database,
              "BugId",
              maxlen);
            v38 = (const char *)(*(int (__thiscall **)(int, int))(*(_DWORD *)v88 + 28))(a1: v88, a2: v89);
            V_snprintf(pDest: v53, maxLen: 0x2000, pFormat: "%s\n\nzip url:  %s\n", v38, v56);
          }
          else
          {
            v39 = (const char *)(*(int (__thiscall **)(int, int))(*(_DWORD *)v88 + 28))(a1: v88, a2: v89);
            V_strncpy(pDest: v53, pSrc: v39, maxLen: 0x2000);
          }
          a1 = 1;
          ((void (__thiscall *)(CBugReporter *, const char *, char *))bug->AddField)(
            a1: bug,
            a2: "Description",
            a3: v53);
          CommitBugReport = bug->CommitBugReport;
          v92 = -1;
          if ( CommitBugReport(this: bug, a2: &v92) )
          {
            if ( v56[0] == 0 )
            {
              v42 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v95 + 32))(a1: v95, a2: v96);
              goto LABEL_23;
            }
            V_snprintf(pDest: v63, maxLen: 32, pFormat: "%i", v92);
            V_snprintf(
              pDest: start,
              maxLen: 512,
              pFormat: "\\\\fileserver\\bugs\\public\\%s\\%s\\%s.zip",
              database,
              v63,
              maxlen);
            _V_strlower(start);
            V_FixSlashes(pname: start, separator: 92);
            V_strncpy(pDest: path, pSrc: admin, maxLen: 512);
            V_StripFilename(path);
            _V_strlower(start: path);
            V_FixSlashes(pname: path, separator: 92);
            V_snprintf(pDest: pname, maxLen: 512, pFormat: "%s\\%s.zip", path, maxlen);
            _V_strlower(start: pname);
            V_FixSlashes(pname, separator: 92);
            v41 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v95 + 32))(a1: v95, a2: v96);
            if ( GetBugZip(bugnum: v41, admin) )
            {
              if ( _stat64i32(name: pname, &buf) == 0 )
              {
                CreateDirHierarchy(path: start);
                MoveFileA(lpExistingFileName: pname, lpNewFileName: start);
                v42 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v95 + 32))(a1: v95, a2: v96);
LABEL_23:
                v93 = v42;
                m_Size = v94.m_Size;
                v45 = v94.m_Size;
                if ( v94.m_Size + 1 > v94.m_Memory.m_nAllocationCount )
                {
                  CUtlMemory<int,int>::Grow(
                    this: (CUtlMemory<KeyValues *,int> *)&v94,
                    num: v94.m_Size - v94.m_Memory.m_nAllocationCount + 1);
                  m_Size = v94.m_Size;
                }
                m_pMemory = v94.m_Memory.m_pMemory;
                v94.m_Size = m_Size + 1;
                v47 = m_Size - v45;
                v94.m_pElements = v94.m_Memory.m_pMemory;
                if ( v47 > 0 )
                {
                  _V_memmove(dest: &v94.m_Memory.m_pMemory[v45 + 1], src: &v94.m_Memory.m_pMemory[v45], count: 4 * v47);
                  m_pMemory = v94.m_Memory.m_pMemory;
                }
                v48 = &m_pMemory[v45];
                if ( v48 != nullptr )
                  *v48 = (void (__cdecl *)(IConVar *, const char *, float))v93;
              }
            }
            else
            {
              v43 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v95 + 32))(a1: v95, a2: v96);
              _Warning(a1: "Unable to retrieve bug file for %i\n", v43);
            }
          }
          else
          {
            _Warning(a1: "Unable to post bug report to database\n");
          }
          if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v16 + 12))(a1: v16) == 0 )
          {
            v11 = v94.m_Size;
            v14 = v86;
            break;
          }
        }
      }
      (**(void (__thiscall ***)(int))v16)(a1: v16);
      for ( i = 0; i < v11; ++i )
      {
        V_snprintf(
          pDest: v61,
          maxLen: 512,
          pFormat: "update bugreports set Processed=1 where BugId=%i;",
          v94.m_Memory.m_pMemory[i]);
        if ( (*(int (__thiscall **)(int, char *))(*(_DWORD *)v14 + 44))(a1: v14, a2: v61) != 0 )
          _Msg(a1: "Query failed '%s'\n", v61);
      }
    }
    CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: &v94);
    v50 = pModule;
    (**(void (__thiscall ***)(int))v14)(a1: v14);
    Sys_UnloadModule(pModule: v50);
  }
  else
  {
    vprint(depth: 0, fmt: "InitMySQL failed\n");
    (**(void (__thiscall ***)(int))v14)(a1: v14);
    Sys_UnloadModule(pModule: v10);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404D30
// Name: _main
// Source: json
//------------------------------------------------------------------------------
int __cdecl main(int argc, const char **argv, const char **envp)
{
  int v4; // [esp-8h] [ebp-38h]
  const char *v5; // [esp-4h] [ebp-34h]
  int v6; // [esp-4h] [ebp-34h]
  CBugReporter bugreporter; // [esp+Ch] [ebp-24h] BYREF
  CNonFatalLoggingResponsePolicy nonFatalLoggingResponsePolicy; // [esp+2Ch] [ebp-4h] BYREF

  nonFatalLoggingResponsePolicy.__vftable = (CNonFatalLoggingResponsePolicy_vtbl *)&CNonFatalLoggingResponsePolicy::`vftable';
  _LoggingSystem_SetLoggingResponsePolicy(a1: &nonFatalLoggingResponsePolicy);
  uselogfile = true;
  verbose = 1;
  if ( argc != 7 && argc != 9 )
  {
    vprint(depth: 0, fmt: "Valve Software - getbugs.exe (%s)\n", "Dec 28 2010");
    vprint(depth: 0, fmt: "--- Pulls public bugreporter bugs into PVCS tracker ---\n");
    printusage();
  }
  _unlink(path: "log.txt");
  vprint(depth: 0, fmt: "    Outputting to log.txt\n");
  vprint(depth: 0, fmt: "Valve Software - getbugs.exe (%s)\n", "Dec 28 2010");
  vprint(depth: 0, fmt: "--- Pulls public bugreporter bugs into PVCS tracker ---\n");
  vprint(depth: 0, fmt: "    Getting bugs...\n");
  workingdir[0] = 0;
  Q_getwd(out: workingdir, outSize: 256);
  CmdLib_InitFileSystem(pFilename: workingdir, maxMemoryUsage: 0);
  v5 = argv[1];
  bugreporter.__vftable = (CBugReporter_vtbl *)&CBugReporter::`vftable';
  memset(&bugreporter.trkHandle, 0, 28);
  if ( CBugReporter::Init(this: &bugreporter, projectname: v5) != 0 )
  {
    if ( argc == 9 )
    {
      v6 = atoi(nptr: argv[8]);
      v4 = atoi(nptr: argv[7]);
      GetBugInfo(
        a1: 9,
        bug: &bugreporter,
        host: argv[2],
        database: argv[3],
        username: argv[4],
        password: argv[5],
        admin: (char *)argv[6],
        startbug: v4,
        endbug: v6);
    }
    else
    {
      GetBugInfo(
        a1: argc,
        bug: &bugreporter,
        host: argv[2],
        database: argv[3],
        username: argv[4],
        password: argv[5],
        admin: (char *)argv[6],
        startbug: -1,
        endbug: -1);
    }
    CBugReporter::Shutdown(this: &bugreporter);
    CmdLib_TermFileSystem();
  }
  else
  {
    vprint(depth: 0, fmt: "Couldn't init bug reporter\n");
  }
  bugreporter.__vftable = (CBugReporter_vtbl *)&CBugReporter::`vftable';
  bugreporter.m_Fields.m_Size = 0;
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&bugreporter.m_Fields);
  return 0;
}
