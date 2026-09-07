// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tier0/minidump.cpp
// Functions: 7
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1000A150
// Name: _WriteMiniDumpUsingExceptionInfo
// Source: json
//------------------------------------------------------------------------------
char __cdecl WriteMiniDumpUsingExceptionInfo(
        unsigned int uStructuredExceptionCode,
        ExceptionInfo_t *pExceptionInfo,
        MINIDUMP_TYPE minidumpType,
        char *ptchMinidumpFileNameBuffer)
{
  HINSTANCE__ *LibraryA; // eax
  BOOL (__stdcall *MiniDumpWriteDump)(HANDLE, DWORD, HANDLE, MINIDUMP_TYPE, PMINIDUMP_EXCEPTION_INFORMATION, PMINIDUMP_USER_STREAM_INFORMATION, PMINIDUMP_CALLBACK_INFORMATION); // edi
  _BYTE *v8; // eax
  int v9; // eax
  const char *v10; // eax
  const char *v11; // ecx
  HANDLE FileA; // esi
  HANDLE CurrentProcess; // eax
  BOOL v14; // edi
  char *v15; // eax
  char v16; // cl
  DWORD CurrentProcessId; // [esp-20h] [ebp-364h]
  char rgchFailedFileName[260]; // [esp+4h] [ebp-340h] BYREF
  char rgchModuleName[260]; // [esp+108h] [ebp-23Ch] BYREF
  char rgchFileName[260]; // [esp+20Ch] [ebp-138h] BYREF
  tm curtime; // [esp+310h] [ebp-34h] BYREF
  _MINIDUMP_EXCEPTION_INFORMATION ExInfo; // [esp+334h] [ebp-10h] BYREF
  HINSTANCE__ *hDbgHelpDll; // [esp+340h] [ebp-4h]
  char bReturnValue_3; // [esp+35Bh] [ebp+17h]

  if ( ptchMinidumpFileNameBuffer != nullptr )
    *ptchMinidumpFileNameBuffer = 0;
  LibraryA = LoadLibraryA(lpLibFileName: "DbgHelp.dll");
  hDbgHelpDll = LibraryA;
  if ( LibraryA == nullptr )
    return 0;
  bReturnValue_3 = 0;
  MiniDumpWriteDump = (BOOL (__stdcall *)(HANDLE, DWORD, HANDLE, MINIDUMP_TYPE, PMINIDUMP_EXCEPTION_INFORMATION, PMINIDUMP_USER_STREAM_INFORMATION, PMINIDUMP_CALLBACK_INFORMATION))GetProcAddress(hModule: LibraryA, lpProcName: "MiniDumpWriteDump");
  if ( MiniDumpWriteDump == nullptr )
    goto LABEL_20;
  Plat_GetLocalTime(pNow: &curtime);
  ++g_nMinidumpsWritten;
  GetModuleFileNameA(hModule: nullptr, lpFilename: rgchModuleName, nSize: 0x104u);
  strrchr(string: (unsigned __int8 *)rgchModuleName, chr: 0x2Eu);
  if ( v8 != nullptr )
    *v8 = 0;
  strrchr(string: (unsigned __int8 *)rgchModuleName, chr: 0x5Cu);
  if ( v9 != 0 )
    v10 = (const char *)(v9 + 1);
  else
    v10 = "unknown";
  v11 = "assert";
  if ( !g_bWritingNonfatalMinidump )
    v11 = "crash";
  _snprintf(
    string: rgchFileName,
    count: 0x104u,
    format: "%s_%s_%d%.2d%2d%.2d%.2d%.2d_%d.mdmp",
    v10,
    v11,
    curtime.tm_year + 1900,
    curtime.tm_mon + 1,
    curtime.tm_mday,
    curtime.tm_hour,
    curtime.tm_min,
    curtime.tm_sec,
    g_nMinidumpsWritten);
  FileA = CreateFileA(
            lpFileName: rgchFileName,
            dwDesiredAccess: 0x40000000u,
            dwShareMode: 2u,
            lpSecurityAttributes: nullptr,
            dwCreationDisposition: 2u,
            dwFlagsAndAttributes: 0x80u,
            hTemplateFile: nullptr);
  if ( FileA == nullptr
    || (ExInfo.ThreadId = GetCurrentThreadId(),
        ExInfo.ExceptionPointers = (_EXCEPTION_POINTERS *)pExceptionInfo,
        ExInfo.ClientPointers = 0,
        CurrentProcessId = GetCurrentProcessId(),
        CurrentProcess = GetCurrentProcess(),
        v14 = MiniDumpWriteDump(
                hProcess: CurrentProcess,
                ProcessId: CurrentProcessId,
                hFile: FileA,
                DumpType: minidumpType,
                ExceptionParam: &ExInfo,
                UserStreamParam: nullptr,
                CallbackParam: nullptr),
        CloseHandle(hObject: FileA),
        !v14) )
  {
    _snprintf(string: rgchFailedFileName, count: 0x104u, format: "(failed)%s", rgchFileName);
    rename(oldname: rgchFileName, newname: rgchFailedFileName);
    goto LABEL_20;
  }
  bReturnValue_3 = 1;
  if ( ptchMinidumpFileNameBuffer == nullptr )
  {
LABEL_20:
    FreeLibrary(hLibModule: hDbgHelpDll);
    return bReturnValue_3;
  }
  v15 = ptchMinidumpFileNameBuffer;
  do
  {
    v16 = v15[rgchFileName - ptchMinidumpFileNameBuffer];
    *v15++ = v16;
  }
  while ( v16 != 0 );
  FreeLibrary(hLibModule: hDbgHelpDll);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000A330
// Name: void InternalWriteMiniDumpUsingExceptionInfo(unsigned int,struct ExceptionInfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InternalWriteMiniDumpUsingExceptionInfo(
        unsigned int uStructuredExceptionCode,
        ExceptionInfo_t *pExceptionInfo)
{
  if ( WriteMiniDumpUsingExceptionInfo(
         uStructuredExceptionCode,
         pExceptionInfo,
         minidumpType: MiniDumpWithIndirectlyReferencedMemory|MiniDumpWithDataSegs,
         ptchMinidumpFileNameBuffer: nullptr) == 0 )
    WriteMiniDumpUsingExceptionInfo(
      uStructuredExceptionCode,
      pExceptionInfo,
      minidumpType: MiniDumpWithDataSegs,
      ptchMinidumpFileNameBuffer: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1000A360
// Name: _SetMiniDumpFunction
// Source: json
//------------------------------------------------------------------------------
void (__cdecl *__cdecl SetMiniDumpFunction(
        void (__cdecl *pfn)(unsigned int, ExceptionInfo_t *)))(unsigned int, ExceptionInfo_t *)
{
  void (__cdecl *result)(unsigned int, ExceptionInfo_t *); // eax

  result = g_pfnWriteMiniDump;
  g_pfnWriteMiniDump = pfn;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000A380
// Name: ValveUnhandledExceptionFilter
// Source: json
//------------------------------------------------------------------------------
int __stdcall ValveUnhandledExceptionFilter(_EXCEPTION_POINTERS *pExceptionInfo)
{
  g_UnhandledExceptionFunction(
    a1: pExceptionInfo->ExceptionRecord->ExceptionCode,
    a2: (ExceptionInfo_t *)pExceptionInfo);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000A3A0
// Name: _MinidumpSetUnhandledExceptionFunction
// Source: json
//------------------------------------------------------------------------------
void __cdecl MinidumpSetUnhandledExceptionFunction(void (__cdecl *pfn)(unsigned int, ExceptionInfo_t *))
{
  g_UnhandledExceptionFunction = pfn;
  SetUnhandledExceptionFilter(lpTopLevelExceptionFilter: ValveUnhandledExceptionFilter);
}

//------------------------------------------------------------------------------
// Address: 0x1000A3C0
// Name: _WriteMiniDump
// Source: json
//------------------------------------------------------------------------------
void WriteMiniDump()
{
  g_bWritingNonfatalMinidump = true;
  RaiseException(dwExceptionCode: 0, dwExceptionFlags: 1u, nNumberOfArguments: 0, lpArguments: nullptr);
  g_bWritingNonfatalMinidump = false;
}

//------------------------------------------------------------------------------
// Address: 0x1000A440
// Name: _CatchAndWriteMiniDump
// Source: json
//------------------------------------------------------------------------------
void __cdecl CatchAndWriteMiniDump(void (__cdecl *pfn)(int, char **), int argc, char **argv)
{
  _DWORD v3[7]; // [esp+0h] [ebp-1Ch] BYREF

  v3[3] = v3;
  if ( Plat_IsInDebugSession() )
  {
    pfn(a1: argc, a2: argv);
  }
  else
  {
    v3[6] = 0;
    _set_se_translator(pNew: (void (__cdecl *)(unsigned int, _EXCEPTION_POINTERS *))g_pfnWriteMiniDump);
    pfn(a1: argc, a2: argv);
  }
}

// ============================================================
// Overlay from tier0_s (Missing functions)
// ============================================================
namespace tier0_s {

//------------------------------------------------------------------------------
// Address: 0x3F004B00
// Name: public: bool CThreadFastMutex::TryLock(void)volatile
// Source: json
//------------------------------------------------------------------------------
void __usercall CThreadFastMutex::TryLock(CThreadFastMutex *this@<ecx>, char a2@<bl>, _BYTE *a3@<esi>)
{
  *a3 &= a2;
  JUMPOUT(0x3F004B02);
}

//------------------------------------------------------------------------------
// Address: 0x3F004B60
// Name: _BGetMiniDumpLock
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __stdcall BGetMiniDumpLock(int a1, int a2)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F004B70
// Name: _MiniDumpUnlock
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __stdcall MiniDumpUnlock(int a1, int a2)
{
  __asm { rcr     byte ptr [edi+5Eh], cl }
}

//------------------------------------------------------------------------------
// Address: 0x3F004BB0
// Name: _BWritingMiniDump
// Source: json
//------------------------------------------------------------------------------
void __usercall BWritingMiniDump(_BYTE *a1@<eax>, unsigned int a2@<edi>, int a3@<esi>)
{
  int v3; // eax

  *a1 |= (unsigned __int8)a1;
  v3 = *(_DWORD *)(a3 + 5104);
  if ( a2 >= *(_DWORD *)(v3 + 36) && a2 < *(_DWORD *)(v3 + 40) )
    JUMPOUT(0x3F004BCB);
  JUMPOUT(0x3F004BD7);
}

//------------------------------------------------------------------------------
// Address: 0x3F004BD0
// Name: _BWritingFatalMiniDump
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __stdcall BWritingFatalMiniDump(int a1, int a2)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F004C90
// Name: _SetWritingMiniDump
// Source: json
//------------------------------------------------------------------------------
void __userpurge SetWritingMiniDump(
        int a1@<eax>,
        _BYTE *a2@<ebx>,
        unsigned int a3@<esi>,
        unsigned int a4,
        void *a5,
        const char *a6,
        const char *a7,
        int a8)
{
  bool v8; // cf
  bool v9; // of

  v8 = __CFADD__(BYTE1(a2), *a2);
  v9 = __OFADD__(BYTE1(a2), *a2);
  *a2 += BYTE1(a2);
  if ( v9 )
    JUMPOUT(0x3F004CB8);
  if ( v8 || a3 >= *(_DWORD *)(a1 + 40) )
    JUMPOUT(0x3F004CCF);
  if ( (a3 - *(_DWORD *)(a1 + 36)) >> 16 < 0x4000 )
    JUMPOUT(0x3F004CAF);
  WriteMiniDumpUsingExceptionInfo(uStructuredExceptionCode: a4, pvExceptionInfo: a5, pchMsg: a6, pchFile: a7, nLine: a8);
}

//------------------------------------------------------------------------------
// Address: 0x3F004CB0
// Name: _ClearWritingMiniDump
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
double __userpurge ClearWritingMiniDump@<st0>(char a1@<sf>, char a2@<of>, int a3, int a4)
{
  if ( a1 == a2 )
  {
    ((void (*)(void))loc_3F008340)();
    JUMPOUT(0x3F004CBD);
  }
  return MEMORY[0x5E5F0000];
}

//------------------------------------------------------------------------------
// Address: 0x3F004CC0
// Name: void WriteMiniDumpUsingExceptionInfo(unsigned int,void __near *,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge WriteMiniDumpUsingExceptionInfo(
        unsigned int uStructuredExceptionCode,
        void *pvExceptionInfo,
        const char *pchMsg,
        const char *pchFile,
        int nLine)
{
  ((void (__cdecl *)(_DWORD))loc_3F008340)(a1: 0);
}

//------------------------------------------------------------------------------
// Address: 0x3F004F60
// Name: _SetMiniDumpFunction
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetMiniDumpFunction(
        void (__cdecl *pfn)(unsigned int, void *, const char *, const char *, int),
        const char *a2,
        int a3)
{
  WriteMiniDump(pchMsg: (const char *)pfn, pchFile: a2, nLine: a3);
}

//------------------------------------------------------------------------------
// Address: 0x3F004F70
// Name: _WriteMiniDump
// Source: json
//------------------------------------------------------------------------------
void __usercall WriteMiniDump(
        int a1@<edx>,
        int a2@<ecx>,
        unsigned __int8 a3@<bh>,
        void *a4@<edi>,
        const char *pchMsg,
        const char *pchFile,
        const char *nLine,
        int nLinea,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        _PROCESS_HEAP_ENTRY Entry,
        char a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        int a30,
        int a31,
        int a32,
        int a33,
        int a34,
        int a35,
        int a36,
        int a37,
        int a38,
        int a39,
        int a40,
        int a41,
        int a42,
        int a43,
        int a44,
        int a45,
        int a46,
        int a47,
        int a48)
{
  int i; // ecx

  do
  {
    if ( a1 < 1 << a2 )
      goto LABEL_4;
    ++a2;
  }
  while ( a2 < 32 );
  a2 = 0;
LABEL_4:
  ++*(&a48 + a2);
  for ( i = 0; i < 32; ++i )
  {
    if ( a1 < 1 << i )
      goto LABEL_8;
  }
  i = 0;
LABEL_8:
  *(&STACK[0x148] + i) += a1;
  if ( a3 < 0x64u && *(&a22 + a3) == 0 )
    *(&a22 + a3) = 1;
  if ( !HeapWalk(hHeap: a4, lpEntry: &Entry) )
  {
    HeapUnlock(hHeap: a4);
    Msg(a1: (int)"hHeap %x\n", a4);
    Msg(a1: (int)"Uncommitted %u\n", a16);
    Msg(a1: (int)"Uncommitted OverHead %u\n", a11);
    Msg(a1: (int)"Uncommitted blocks %u\n", a18);
    Msg(a1: (int)"Used %u\n", a13);
    JUMPOUT(0x3F005052);
  }
  JUMPOUT(0x3F004E70);
}

//------------------------------------------------------------------------------
// Address: 0x3F005060
// Name: _CatchAndWriteMiniDump
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall CatchAndWriteMiniDump(
        int a1@<edx>,
        void (__cdecl *pfn)(int, char **),
        int argc,
        char **argv,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28)
{
  Msg(a1: (int)"Used blocks %u\n", a1);
  Msg(a1: (int)"Used Overhead ( beyond 4 byte alignment ) %u\n", a28);
  JUMPOUT(0x3F00507B);
}

//------------------------------------------------------------------------------
// Address: 0x3F005080
// Name: _CatchAndWriteMiniDumpEx
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall CatchAndWriteMiniDumpEx(
        int a1@<ebx>,
        int a2@<edi>,
        int a3@<esi>,
        void (__cdecl *pfn)(int, char **),
        void (__cdecl *argc)(int, char **),
        char **argv,
        char **eAction,
        ECatchAndWriteMinidumpAction eActiona,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13)
{
  int v13; // esi
  int v14; // eax
  int v15; // [esp-4h] [ebp-4h]

  Msg(a1: (int)"Other %u\n", v15);
  Msg(a1: (int)"Other Overhead %u\n", a13);
  Msg(a1: (int)"Other blocks %u\n", eAction);
  Msg(a1: (int)"Other Overhead ( beyond 4 byte alignment ) %u\n", a9);
  Msg(a1: (int)"Committed size %u\n", a1);
  Msg(a1: (int)"Committed size in large blocks %u\n", a3);
  Msg(a1: (int)"Uncommitted size %u\n", a11);
  Msg(a1: (int)"Free fragments %u\n", a1 + a3 - a2);
  Msg(a1: (int)"Free blocks size %12s %12s %12s %12s\n", "min", "max", "count", "total bytes");
  v13 = 1;
  while ( 1 )
  {
    v14 = *(&STACK[0x2C8] + v13);
    if ( v14 != 0 )
      Msg(a1: (int)"Free blocks size %12u %12u %12u %12u\n", 1 << (v13 - 1), 1 << v13, v14, *(&STACK[0x1C8] + v13));
    if ( ++v13 >= 32 )
      JUMPOUT(0x3F005163);
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F005270
// Name: _CatchAndWriteMiniDumpExForVoidPtrFn
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __cdecl CatchAndWriteMiniDumpExForVoidPtrFn()
{
  int v0; // [esp-14h] [ebp-1Ch]
  int v1; // [esp-10h] [ebp-18h]

  Msg(a1: (int)"Failed to enable the low-fragmentation heap on %x with LastError %d.\n", v0, v1);
}

//------------------------------------------------------------------------------
// Address: 0x3F009090
// Name: MiniDumpUnlock
// Source: json
//------------------------------------------------------------------------------
void MiniDumpUnlock()
{
  LeaveCriticalSection(lpCriticalSection: &CriticalSection);
}

//------------------------------------------------------------------------------
// Address: 0x3F0090A0
// Name: BWritingMiniDump
// Source: json
//------------------------------------------------------------------------------
char BWritingMiniDump()
{
  if ( dword_3F0415D0 != nullptr )
  {
    if ( dword_3F0415D0(a1: &CriticalSection) == 0 )
      return 1;
  }
  else
  {
    EnterCriticalSection(lpCriticalSection: &CriticalSection);
  }
  if ( byte_3F03D36B != 0 || byte_3F03D3C4 != 0 )
  {
    LeaveCriticalSection(lpCriticalSection: &CriticalSection);
    return 1;
  }
  else
  {
    LeaveCriticalSection(lpCriticalSection: &CriticalSection);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F009140
// Name: BWritingNonFatalMiniDump
// Source: json
//------------------------------------------------------------------------------
char BWritingNonFatalMiniDump()
{
  char v1; // bl

  if ( dword_3F0415D0 != nullptr )
  {
    if ( dword_3F0415D0(a1: &CriticalSection) == 0 )
      return 1;
  }
  else
  {
    EnterCriticalSection(lpCriticalSection: &CriticalSection);
  }
  v1 = byte_3F03D36B;
  LeaveCriticalSection(lpCriticalSection: &CriticalSection);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x3F009B80
// Name: WriteMiniDump
// Source: json
//------------------------------------------------------------------------------
void __cdecl WriteMiniDump(const char *a1, const char *a2, int a3, int a4, char a5)
{
  __time32_t v5; // eax
  int v6; // [esp-4h] [ebp-4h]

  if ( a5 == 0 )
  {
    v5 = time(Time: nullptr);
    if ( v5 < dword_3F03D3D8 + 10 )
      return;
    dword_3F03D3D8 = v5;
  }
  if ( dword_3F0415D0 != nullptr )
  {
    if ( dword_3F0415D0(a1: &CriticalSection) == 0 )
      return;
  }
  else
  {
    EnterCriticalSection(lpCriticalSection: &CriticalSection);
  }
  if ( BWritingMiniDump() == 0 )
  {
    sub_3F009180(a1: v6);
    if ( byte_3F03D3C5 == 0 )
    {
      sub_3F009A40(a1, a2, a3, a4);
      byte_3F03D3C5 = 0;
      if ( dword_3F03D36C != nullptr )
        dword_3F03D36C();
      ((void (*)(void))ClearWritingMiniDump)();
    }
  }
  LeaveCriticalSection(lpCriticalSection: &CriticalSection);
}

//------------------------------------------------------------------------------
// Address: 0x3F009F40
// Name: CatchAndWriteMiniDumpExReturnsInt
// Source: json
//------------------------------------------------------------------------------
CValidator *__cdecl CatchAndWriteMiniDumpExReturnsInt(int a1, CValidator a2)
{
  if ( a1 != 0 )
    JUMPOUT(0x3F009F7D);
  return CValidator::CValidator(this: &a2, cubThreshold: 0);
}

//------------------------------------------------------------------------------
// Address: 0x3F009F90
// Name: CatchAndWriteMiniDumpExForVoidPtrFn
// Source: json
//------------------------------------------------------------------------------
void __cdecl CatchAndWriteMiniDumpExForVoidPtrFn(unsigned int a1, char a2, unsigned int a3)
{
  CWorkerThread *v3; // ecx
  unsigned int dw[6]; // [esp+0h] [ebp-18h] BYREF

  v3 = nullptr;
  dw[5] = a3;
  dw[0] = 3;
  dw[1] = a1;
  dw[2] = 0;
  dw[3] = 0;
  dw[4] = (unsigned int)&a2;
  if ( a1 == 0 )
    Error(a1: (int)"CatchAndWriteContext_t::Set w/o a function pointer!");
  CWorkerThread::Reply(this: v3, (unsigned int)dw);
}

//------------------------------------------------------------------------------
// Address: 0x3F009110
// Name: ?GetName@CThread@@QAEPBDXZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall CThread::GetName(CThread *this@<ecx>, int a2@<ebp>)
{
  *(_BYTE *)(a2 - 1979025984) = __ROL1__(*(_BYTE *)(a2 - 1979025984), 1);
}

//------------------------------------------------------------------------------
// Address: 0x3F009180
// Name: sub_3F009180
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall sub_3F009180(CThread *this, const char *a2)
{
  if ( dword_3F0415D0 == nullptr )
    JUMPOUT(0x3F0091AA);
  CThread::SetName(this, pszName: a2);
}

//------------------------------------------------------------------------------
// Address: 0x3F0091A0
// Name: ?SetName@CThread@@QAEXPBD@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge CThread::SetName(
        CThread *this@<ecx>,
        int (__thiscall *a2)(CThread *)@<eax>,
        int a3@<ebp>,
        void (__stdcall *a4)(_RTL_CRITICAL_SECTION *)@<esi>,
        const char *pszName)
{
  *(_BYTE *)(a3 - 1) = a2(a1: this) != 0;
  if ( byte_3F0A3605 == 0 && *(_BYTE *)(a3 - 1) == 0 && byte_3F03D369 == 0 )
  {
    if ( dword_3F0415D0 != nullptr )
    {
      if ( dword_3F0415D0(a1: &CriticalSection) == 0 )
        goto LABEL_13;
    }
    else
    {
      a4(a1: &CriticalSection);
    }
    if ( dword_3F0415D0 != nullptr )
    {
      if ( dword_3F0415D0(a1: &CriticalSection) == 0 )
        JUMPOUT(0x3F009369);
    }
    else
    {
      a4(a1: &CriticalSection);
    }
    JUMPOUT(0x3F009215);
  }
LABEL_13:
  JUMPOUT(0x3F009370);
}

//------------------------------------------------------------------------------
// Address: 0x3F009C40
// Name: ?WaitForReply@CWorkerThread@@QAEHI@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge CWorkerThread::WaitForReply(
        CWorkerThread *this@<ecx>,
        int a2@<eax>,
        int a3@<ebp>,
        unsigned int timeout)
{
  *(_DWORD *)(a3 - 28) = 1;
  *(_DWORD *)(a3 - 8) = this;
  *(_DWORD *)(a3 - 24) = a2;
  JUMPOUT(0x3F009C4F);
}

//------------------------------------------------------------------------------
// Address: 0x3F009C50
// Name: ?WaitForReply@CWorkerThread@@IAEHIP6GIIPBQAXHI@Z@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall CWorkerThread::WaitForReply(CWorkerThread *this@<ecx>, char a2@<zf>, int _EBP@<ebp>)
{
  __asm { lock mov [ebp-0Ch], this }
  if ( a2 )
    Error(a1: (int)"CatchAndWriteContext_t::Set w/o a function pointer!");
  CWorkerThread::Reply(this, dw: _EBP - 28);
}

//------------------------------------------------------------------------------
// Address: 0x3F009D70
// Name: ?WaitForCall@CWorkerThread@@QAE_NPAI@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CWorkerThread::WaitForCall(CWorkerThread *this, unsigned int *pResult)
{
  if ( dword_3F03D36C != nullptr )
    dword_3F03D36C(a1: this);
  ((void (__fastcall *)(CWorkerThread *))ClearWritingMiniDump)(a1: this);
  LeaveCriticalSection(lpCriticalSection: &CriticalSection);
  JUMPOUT(0x3F009D8D);
}

//------------------------------------------------------------------------------
// Address: 0x3F009D90
// Name: ?WaitForCall@CWorkerThread@@QAE_NIPAI@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
bool __usercall CWorkerThread::WaitForCall@<al>(CWorkerThread *this@<ecx>, char a2@<cf>, char a3@<al>)
{
  return a3 - (a2 + 95);
}

//------------------------------------------------------------------------------
// Address: 0x3F009DA0
// Name: sub_3F009DA0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
bool __usercall sub_3F009DA0@<al>(_DWORD *a1@<esi>, unsigned int *a2)
{
  CWorkerThread *v2; // ecx

  if ( *a1 == 1 )
    JUMPOUT(0x3F009E02);
  if ( *a1 == 2 )
    JUMPOUT(0x3F009DD4);
  if ( *a1 != 3 )
    JUMPOUT(0x3F009E2F);
  if ( a1[4] != 0 )
    JUMPOUT(0x3F009DC3);
  Error(a1: (int)"CatchAndWriteContext_t::Invoke with bogus void *ptr");
  return CWorkerThread::PeekCall(this: v2, pParam: a2);
}

//------------------------------------------------------------------------------
// Address: 0x3F009DC0
// Name: ?PeekCall@CWorkerThread@@QAE_NPAI@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall CWorkerThread::PeekCall@<eax>(CWorkerThread *this@<ecx>, int a2@<esi>)
{
  (*(void (__cdecl **)(_DWORD))(a2 + 4))(a1: **(_DWORD **)(a2 + 16));
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F009E40
// Name: ?Reply@CWorkerThread@@QAEXI@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F009FE0
// Name: ??1CValidator@@QAE@XZ_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CValidator::~CValidator(CValidator *this)
{
  JUMPOUT(0x3F009FF6);
}

//------------------------------------------------------------------------------
// Address: 0x3F00A040
// Name: GetCrashHandlerFactory
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int GetCrashHandlerFactory()
{
  ((void (*)(void))loc_3F009660)();
  return dword_3F03F288;
}

} // namespace tier0_s
