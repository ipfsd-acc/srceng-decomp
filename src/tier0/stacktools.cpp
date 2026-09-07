// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tier0/stacktools.cpp
// Functions: 34
// ============================================================

#include "tier0\stacktools.h"

//------------------------------------------------------------------------------
// Address: 0x10001000
// Name: public: CCallStackStorage::CCallStackStorage(class CCallStackStorage const __near &)
// Source: json
//------------------------------------------------------------------------------
CCallStackStorage *__thiscall CCallStackStorage::CCallStackStorage(
        CCallStackStorage *this,
        CCallStackStorage *copyFrom)
{
  this->iValidEntries = copyFrom->iValidEntries;
  memcpy(dst: (unsigned __int8 *)this, src: (unsigned __int8 *)copyFrom, count: 4 * copyFrom->iValidEntries);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10006AB0
// Name: unsigned long SymSetOptions_DummyFn(unsigned long)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall SymSetOptions_DummyFn(CStdMemAlloc *this, const char *pchSubStr)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10006AC0
// Name: int SymSetSearchPath_DummyFn(void __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall SymSetSearchPath_DummyFn(CStdMemAlloc *this, int nRptType, int hFile)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1000CEF0
// Name: int SymUnloadModule64_DummyFn(void __near *,unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
int __stdcall SymUnloadModule64_DummyFn(void *hProcess, unsigned __int64 BaseOfDll)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000CF00
// Name: int SymCleanup_DummyFn(void __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall SymCleanup_DummyFn(CStdMemAlloc *this, const void *pMem)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000CF10
// Name: unsigned __int64 SymLoadModule64_DummyFn(void __near *,void __near *,char __near *,char __near *,unsigned __int64,unsigned long)
// Source: json
//------------------------------------------------------------------------------
unsigned __int64 __stdcall SymLoadModule64_DummyFn(
        void *hProcess,
        void *hFile,
        char *ImageName,
        char *ModuleName,
        unsigned __int64 BaseOfDll,
        unsigned int SizeOfDll)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000CF20
// Name: int SymFromAddr_DummyFn(void __near *,unsigned __int64,unsigned __int64 __near *,struct _SYMBOL_INFO __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall SymFromAddr_DummyFn(
        CStdMemAlloc *this,
        int nRptType,
        const char *szFile,
        const char *nLine,
        const char *szModule,
        const char *pMsg)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000CF30
// Name: int StackWalk64_DummyFn(unsigned long,void __near *,void __near *,struct _tagSTACKFRAME64 __near *,void __near *,int (*)(void __near *,unsigned __int64,void __near *,unsigned long,unsigned long __near *),void __near * (*)(void __near *,unsigned __int64),unsigned __int64 (*)(void __near *,unsigned __int64),unsigned __int64 (*)(void __near *,void __near *,struct _tagADDRESS64 __near *))
// Source: json
//------------------------------------------------------------------------------
int __stdcall StackWalk64_DummyFn(
        unsigned int MachineType,
        unsigned int hProcess,
        void *hThread,
        _tagSTACKFRAME64 *StackFrame,
        _tagSTACKFRAME64 *ContextRecord,
        int (__stdcall *ReadMemoryRoutine)(void *, unsigned __int64, void *, unsigned int, unsigned int *),
        int (__stdcall *FunctionTableAccessRoutine)(void *, unsigned __int64, void *, unsigned int, unsigned int *),
        void *(__stdcall *GetModuleBaseRoutine)(void *, unsigned __int64),
        unsigned __int64 (__stdcall *TranslateAddress)(void *, unsigned __int64))
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000CF40
// Name: public: static int CHelperFunctionsLoader::LoadSymbolsCallback(char const __near *,unsigned __int64,unsigned long,void __near *)
// Source: json
//------------------------------------------------------------------------------
int __stdcall CHelperFunctionsLoader::LoadSymbolsCallback(
        const char *ModuleName,
        unsigned __int64 ModuleBase,
        unsigned int ModuleSize,
        void *UserContext)
{
  (*((void (__stdcall **)(_DWORD, _DWORD, const char *, const char *, _DWORD, _DWORD, unsigned int))UserContext + 13))(
    a1: *((_DWORD *)UserContext + 1),
    a2: 0,
    a3: ModuleName,
    a4: ModuleName,
    a5: ModuleBase,
    a6: HIDWORD(ModuleBase),
    a7: ModuleSize);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000CF70
// Name: _StackToolsNotify_LoadedLibrary
// Source: json
//------------------------------------------------------------------------------
void __cdecl StackToolsNotify_LoadedLibrary()
{
  s_HelperFunctions.m_bShouldReloadSymbols = true;
}

//------------------------------------------------------------------------------
// Address: 0x1000CF90
// Name: public: CCallStackStorage::CCallStackStorage(int (*)(void __near * __near *,int,int),unsigned int)
// Source: json
//------------------------------------------------------------------------------
CCallStackStorage *__thiscall CCallStackStorage::CCallStackStorage(
        CCallStackStorage *this,
        int (__cdecl *GetStackFunction)(void **, int, int),
        unsigned int iSkipCalls)
{
  this->iValidEntries = GetStackFunction(a1: this->pStack, a2: 128, a3: iSkipCalls + 1);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000CFC0
// Name: public: void CStackTop_ReferenceParentStack::ReleaseParentStackReferences(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStackTop_ReferenceParentStack::ReleaseParentStackReferences(CStackTop_ReferenceParentStack *this)
{
  this->m_pParentStackTrace = nullptr;
  this->m_iParentStackTraceLength = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000CFD0
// Name: _EncodeBinaryToString
// Source: json
//------------------------------------------------------------------------------
int __cdecl EncodeBinaryToString(
        char *pToEncode,
        int iDataLength,
        char *pEncodeOut,
        const unsigned __int8 *iEncodeBufferSize)
{
  int v5; // eax
  const unsigned __int8 *v6; // esi
  const unsigned __int8 *v7; // ecx
  char *v8; // edx
  int v9; // edi
  char *v10; // ebx
  int iEncodedSize; // [esp+10h] [ebp+Ch]
  const unsigned __int8 *pEncodeStop; // [esp+18h] [ebp+14h]

  v5 = (iDataLength + 6) / 7 + iDataLength + 5;
  iEncodedSize = v5;
  if ( v5 > (int)iEncodeBufferSize )
    return -v5;
  if ( pEncodeOut == nullptr )
    return -v5;
  v6 = (const unsigned __int8 *)pToEncode;
  if ( pToEncode == nullptr )
    return -v5;
  *pEncodeOut = (iDataLength >> 21) | 0x80;
  pEncodeOut[1] = (iDataLength >> 14) | 0x80;
  pEncodeOut[2] = (iDataLength >> 7) | 0x80;
  pEncodeOut[3] = iDataLength | 0x80;
  v7 = (const unsigned __int8 *)&pToEncode[iDataLength];
  v8 = pEncodeOut + 4;
  v9 = 0;
  pEncodeStop = v7;
  v10 = pEncodeOut + 4;
  if ( pToEncode < (char *)v7 )
  {
    do
    {
      if ( v9 != 0 )
      {
        *v8 = *v6 | 0x80;
        v7 = pEncodeStop;
        *v10 |= (~*v6 & 0x80) >> v9;
        v5 = iEncodedSize;
        ++v6;
      }
      else
      {
        v10 = v8;
        *v8 = 0x80;
      }
      ++v8;
      v9 = ((_BYTE)v9 + 1) & 7;
    }
    while ( v6 < v7 );
  }
  *v8 = 0;
  return v5 - 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000D090
// Name: _DecodeBinaryFromString
// Source: json
//------------------------------------------------------------------------------
int __cdecl DecodeBinaryFromString(char *pString, char *pDestBuffer, int iDestBufferSize, char **ppParseFinishOut)
{
  char v4; // cl
  char v5; // al
  int v6; // esi
  int v7; // eax
  bool v8; // zf
  int v9; // eax
  const char *v10; // edi
  int v11; // ecx
  const unsigned __int8 *v13; // ebx
  int v15; // ecx
  char v16; // dl
  const unsigned __int8 *pStopDecoding; // [esp+Ch] [ebp+8h]

  if ( (unsigned __int8)*pString < 0x80u
    || (unsigned __int8)pString[1] < 0x80u
    || (unsigned __int8)(v4 = pString[2]) < 0x80u
    || (unsigned __int8)(v5 = pString[3]) < 0x80u )
  {
    if ( ppParseFinishOut != nullptr )
      *ppParseFinishOut = pString;
    return 0x80000000;
  }
  else
  {
    v6 = v5 & 0x7F | ((v4 & 0x7F | ((pString[1] & 0x7F | ((*pString & 0x7F) << 7)) << 7)) << 7);
    v7 = (v6 + 6) / 7;
    v8 = v6 + v7 == 0;
    v9 = v6 + v7;
    v10 = pString + 4;
    v11 = 0;
    if ( v8 )
    {
LABEL_8:
      if ( iDestBufferSize >= v6 )
      {
        v13 = (const unsigned __int8 *)&v10[v9];
        v15 = 0;
        v16 = 0;
        for ( pStopDecoding = v13; v10 < (const char *)v13; v15 = ((_BYTE)v15 + 1) & 7 )
        {
          if ( v15 != 0 )
          {
            *pDestBuffer++ = *v10 ^ (v16 << v15) & 0x80;
            v13 = pStopDecoding;
          }
          else
          {
            v16 = *v10;
          }
          ++v10;
        }
        if ( ppParseFinishOut != nullptr )
          *ppParseFinishOut = (char *)v10;
        return v6;
      }
      else
      {
        if ( ppParseFinishOut != nullptr )
          *ppParseFinishOut = (char *)v10;
        return -v6;
      }
    }
    else
    {
      while ( v10[v11] >= 0x80u )
      {
        if ( ++v11 == v9 )
          goto LABEL_8;
      }
      if ( ppParseFinishOut != nullptr )
        *ppParseFinishOut = pString;
      return 0x80000000;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D1A0
// Name: int AppendParentStackTrace(void __near * __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl AppendParentStackTrace(void **pReturnAddressesOut, int iArrayCount, int iAlreadyFilled)
{
  void *v3; // eax
  void *v4; // edx
  int v5; // esi
  int v6; // ecx
  int v7; // edi

  v3 = GenericThreadLocals::CThreadLocalBase::Get(this: &g_StackTop);
  if ( v3 == nullptr )
    return iAlreadyFilled;
  v4 = *((void **)v3 + 2);
  v5 = iAlreadyFilled;
  if ( v4 != nullptr )
  {
    v6 = iAlreadyFilled - 1;
    if ( iAlreadyFilled - 1 >= 0 )
    {
      while ( pReturnAddressesOut[v6] != v4 )
      {
        if ( --v6 < 0 )
          goto LABEL_8;
      }
      v5 = v6;
    }
  }
LABEL_8:
  v7 = *((_DWORD *)v3 + 4);
  if ( v7 == 0 )
    return v5;
  if ( iArrayCount - v5 < v7 )
    v7 = iArrayCount - v5;
  memcpy(dst: (unsigned __int8 *)&pReturnAddressesOut[v5], src: *((unsigned __int8 **)v3 + 3), count: 4 * v7);
  return v7 + v5;
}

//------------------------------------------------------------------------------
// Address: 0x1000D220
// Name: public: void CHelperFunctionsLoader::TryLoadingNewSymbols(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHelperFunctionsLoader::TryLoadingNewSymbols(CHelperFunctionsLoader *this)
{
  CThreadFastMutex *p_m_Mutex; // esi
  DWORD CurrentThreadId; // ecx

  p_m_Mutex = &this->m_Mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_Mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_Mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(this: p_m_Mutex, threadId: CurrentThreadId, nSpinSleepTime: 0);
  }
  else
  {
    ++p_m_Mutex->m_depth;
  }
  if ( this->m_bIsInitialized )
  {
    this->m_pEnumerateLoadedModules64(a1: this->m_hProcess, a2: CHelperFunctionsLoader::LoadSymbolsCallback, a3: this);
    this->m_bShouldReloadSymbols = false;
  }
  if ( p_m_Mutex->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)p_m_Mutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x1000D290
// Name: public: void CHelperFunctionsLoader::SetStackTranslationSymbolSearchPath(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHelperFunctionsLoader::SetStackTranslationSymbolSearchPath(
        CHelperFunctionsLoader *this,
        char *szSemicolonSeparatedList)
{
  CThreadFastMutex *p_m_Mutex; // esi
  DWORD CurrentThreadId; // ecx
  unsigned __int8 *v5; // ebx
  int (__stdcall *m_pSymSetSearchPath)(void *, char *); // edx
  void *m_hProcess; // [esp-8h] [ebp-18h]
  unsigned int iLength; // [esp+Ch] [ebp-4h]

  p_m_Mutex = &this->m_Mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_Mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_Mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(this: p_m_Mutex, threadId: CurrentThreadId, nSpinSleepTime: 0);
  }
  else
  {
    ++p_m_Mutex->m_depth;
  }
  if ( this->m_szPDBSearchPath != nullptr )
    operator delete(p: this->m_szPDBSearchPath);
  if ( szSemicolonSeparatedList != nullptr )
  {
    iLength = strlen(szSemicolonSeparatedList) + 1;
    v5 = (unsigned __int8 *)operator new(size: iLength);
    memcpy(dst: v5, src: (unsigned __int8 *)szSemicolonSeparatedList, count: iLength);
    m_pSymSetSearchPath = this->m_pSymSetSearchPath;
    m_hProcess = this->m_hProcess;
    this->m_szPDBSearchPath = (char *)v5;
    m_pSymSetSearchPath(a1: m_hProcess, a2: (char *)v5);
    this->m_bShouldReloadSymbols = true;
  }
  else
  {
    this->m_szPDBSearchPath = nullptr;
  }
  if ( p_m_Mutex->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)p_m_Mutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x1000D340
// Name: public: bool CHelperFunctionsLoader::GetSymbolNameFromAddress(void const __near *,char __near *,int,unsigned __int64 __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHelperFunctionsLoader::GetSymbolNameFromAddress(
        CHelperFunctionsLoader *this,
        int pAddress,
        char *pSymbolNameOut,
        unsigned int iMaxSymbolNameLength,
        unsigned __int64 *pDisplacementOut)
{
  CThreadFastMutex *p_m_Mutex; // esi
  DWORD CurrentThreadId; // ecx
  int (__stdcall *m_pSymFromAddr)(void *, unsigned __int64, unsigned __int64 *, _SYMBOL_INFO *); // eax
  bool v10; // zf
  void *m_hProcess; // [esp-18h] [ebp-84Ch]
  unsigned __int8 genericbuffer[2088]; // [esp+4h] [ebp-830h] BYREF
  unsigned __int64 dwDisplacement; // [esp+82Ch] [ebp-8h] BYREF

  if ( pAddress == 0 )
    return 0;
  p_m_Mutex = &this->m_Mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_Mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_Mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(this: &this->m_Mutex, threadId: CurrentThreadId, nSpinSleepTime: 0);
  }
  else
  {
    ++this->m_Mutex.m_depth;
  }
  m_pSymFromAddr = this->m_pSymFromAddr;
  m_hProcess = this->m_hProcess;
  *(_DWORD *)genericbuffer = 88;
  *(_DWORD *)&genericbuffer[80] = 2000;
  if ( ((int (__stdcall *)(void *, int, int, unsigned __int64 *, unsigned __int8 *))m_pSymFromAddr)(
         a1: m_hProcess,
         a2: pAddress,
         a3: pAddress >> 31,
         a4: &dwDisplacement,
         a5: genericbuffer) != 0 )
  {
    strncpy(dest: (unsigned __int8 *)pSymbolNameOut, source: &genericbuffer[84], count: iMaxSymbolNameLength);
    if ( pDisplacementOut != nullptr )
      *pDisplacementOut = dwDisplacement;
    v10 = this->m_Mutex.m_depth-- == 1;
    if ( v10 )
      _InterlockedExchange((volatile __int32 *)p_m_Mutex, 0);
    return 1;
  }
  else
  {
    v10 = this->m_Mutex.m_depth-- == 1;
    if ( v10 )
      _InterlockedExchange((volatile __int32 *)p_m_Mutex, 0);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D420
// Name: public: bool CHelperFunctionsLoader::GetFileAndLineFromAddress(void const __near *,char __near *,int,unsigned int __near &,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHelperFunctionsLoader::GetFileAndLineFromAddress(
        CHelperFunctionsLoader *this,
        int pAddress,
        char *pFileNameOut,
        unsigned int iMaxFileNameLength,
        unsigned int *iLineNumberOut,
        unsigned int *pDisplacementOut)
{
  CThreadFastMutex *p_m_Mutex; // esi
  DWORD CurrentThreadId; // ecx
  int (__stdcall *m_pSymGetLineFromAddr64)(void *, unsigned __int64, unsigned int *, _IMAGEHLP_LINE64 *); // ecx
  bool v11; // zf
  void *m_hProcess; // [esp-18h] [ebp-438h]
  char szBuffer[1024]; // [esp+4h] [ebp-41Ch] BYREF
  _IMAGEHLP_LINE64 imageHelpLine64; // [esp+404h] [ebp-1Ch] BYREF
  unsigned int dwDisplacement; // [esp+41Ch] [ebp-4h] BYREF

  if ( pAddress == 0 )
    return 0;
  p_m_Mutex = &this->m_Mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_Mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_Mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(this: &this->m_Mutex, threadId: CurrentThreadId, nSpinSleepTime: 0);
  }
  else
  {
    ++this->m_Mutex.m_depth;
  }
  imageHelpLine64.FileName = szBuffer;
  m_pSymGetLineFromAddr64 = this->m_pSymGetLineFromAddr64;
  m_hProcess = this->m_hProcess;
  szBuffer[0] = 0;
  imageHelpLine64.SizeOfStruct = 24;
  if ( ((int (__stdcall *)(void *, int, int, unsigned int *, _IMAGEHLP_LINE64 *))m_pSymGetLineFromAddr64)(
         a1: m_hProcess,
         a2: pAddress,
         a3: pAddress >> 31,
         a4: &dwDisplacement,
         a5: &imageHelpLine64) != 0 )
  {
    strncpy(
      dest: (unsigned __int8 *)pFileNameOut,
      source: (unsigned __int8 *)imageHelpLine64.FileName,
      count: iMaxFileNameLength);
    *iLineNumberOut = imageHelpLine64.LineNumber;
    if ( pDisplacementOut != nullptr )
      *pDisplacementOut = dwDisplacement;
    v11 = this->m_Mutex.m_depth-- == 1;
    if ( v11 )
      _InterlockedExchange((volatile __int32 *)p_m_Mutex, 0);
    return 1;
  }
  else
  {
    v11 = this->m_Mutex.m_depth-- == 1;
    if ( v11 )
      _InterlockedExchange((volatile __int32 *)p_m_Mutex, 0);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D500
// Name: public: bool CHelperFunctionsLoader::GetModuleNameFromAddress(void const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHelperFunctionsLoader::GetModuleNameFromAddress(
        CHelperFunctionsLoader *this,
        int pAddress,
        char *pModuleNameOut,
        unsigned int iMaxModuleNameLength)
{
  CThreadFastMutex *p_m_Mutex; // esi
  DWORD CurrentThreadId; // ecx
  int (__stdcall *m_pSymGetModuleInfo64)(void *, unsigned __int64, _IMAGEHLP_MODULE64 *); // edx
  bool v8; // zf
  void *m_hProcess; // [esp-10h] [ebp-6A0h]
  _IMAGEHLP_MODULE64 moduleInfo; // [esp+8h] [ebp-688h] BYREF

  p_m_Mutex = &this->m_Mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_Mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_Mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(this: p_m_Mutex, threadId: CurrentThreadId, nSpinSleepTime: 0);
  }
  else
  {
    ++p_m_Mutex->m_depth;
  }
  m_pSymGetModuleInfo64 = this->m_pSymGetModuleInfo64;
  m_hProcess = this->m_hProcess;
  moduleInfo.SizeOfStruct = 1672;
  if ( ((int (__stdcall *)(void *, int, int, _IMAGEHLP_MODULE64 *))m_pSymGetModuleInfo64)(
         a1: m_hProcess,
         a2: pAddress,
         a3: pAddress >> 31,
         a4: &moduleInfo) != 0 )
  {
    strncpy(
      dest: (unsigned __int8 *)pModuleNameOut,
      source: (unsigned __int8 *)moduleInfo.ModuleName,
      count: iMaxModuleNameLength);
    v8 = p_m_Mutex->m_depth-- == 1;
    if ( v8 )
      _InterlockedExchange((volatile __int32 *)p_m_Mutex, 0);
    return 1;
  }
  else
  {
    v8 = p_m_Mutex->m_depth-- == 1;
    if ( v8 )
      _InterlockedExchange((volatile __int32 *)p_m_Mutex, 0);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D5B0
// Name: public: bool CHelperFunctionsLoader::TranslatePointer(void const __near * const,char __near *,int,enum TranslateStackInfo_StyleFlags_t)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHelperFunctionsLoader::TranslatePointer(
        CHelperFunctionsLoader *this,
        const void *pAddress,
        char *pTranslationOut,
        int iTranslationBufferLength,
        TranslateStackInfo_StyleFlags_t style)
{
  unsigned __int8 *v5; // edi
  signed int v7; // ebx
  bool v8; // zf
  char *v9; // esi
  unsigned int v10; // eax
  char v11; // cl
  unsigned int v12; // eax
  char v13; // al
  unsigned int v14; // kr00_4
  unsigned int v15; // edi
  char *v16; // eax
  int i; // edx
  char v18; // cl
  const char *v19; // eax
  char szFileName[260]; // [esp+4h] [ebp-108h] BYREF
  CHelperFunctionsLoader *v21; // [esp+108h] [ebp-4h]

  v5 = (unsigned __int8 *)pTranslationOut;
  v21 = this;
  if ( pTranslationOut == nullptr )
    return 0;
  v7 = iTranslationBufferLength;
  if ( iTranslationBufferLength <= 0 )
    return 0;
  v8 = (style & 1) == 0;
  v9 = pTranslationOut;
  *pTranslationOut = 0;
  if ( !v8 )
  {
    if ( CHelperFunctionsLoader::GetModuleNameFromAddress(
           this,
           (int)pAddress,
           pModuleNameOut: (char *)v5,
           iMaxModuleNameLength: v7) == 0 )
      strncpy(dest: v5, source: "unknown_module", count: v7);
    v10 = strlen((const char *)v5);
    v7 -= v10;
    v9 = (char *)&v5[v10];
    if ( v7 < 2 )
      return 0;
    if ( (style & 2) != 0 )
    {
      *v9++ = 33;
      --v7;
      *v9 = v11;
    }
  }
  if ( CHelperFunctionsLoader::GetSymbolNameFromAddress(
         this: v21,
         (int)pAddress,
         pSymbolNameOut: v9,
         iMaxSymbolNameLength: v7,
         pDisplacementOut: nullptr) == 0 )
  {
    if ( _snprintf(string: v9, count: v7, format: "0x%p", pAddress) < 0 )
    {
      *v9 = 0;
      return 0;
    }
    return 1;
  }
  if ( (style & 2) != 0 )
  {
    v12 = strlen(v9);
    v9 += v12;
    v7 -= v12;
  }
  else
  {
    *v9 = 0;
  }
  if ( (style & 0x3C) == 0 )
    return 1;
  if ( v9 != (char *)v5 )
  {
    if ( v7 < 6 )
      return 0;
    *(_DWORD *)v9 = 2108704;
    v9 += 3;
    v7 -= 3;
  }
  if ( CHelperFunctionsLoader::GetFileAndLineFromAddress(
         this: v21,
         (int)pAddress,
         pFileNameOut: szFileName,
         iMaxFileNameLength: 0x104u,
         iLineNumberOut: (unsigned int *)&pTranslationOut,
         pDisplacementOut: (unsigned int *)&pAddress) == 0 )
  {
    *(v9 - 3) = 0;
    return 1;
  }
  v13 = style;
  if ( (style & 4) != 0 )
  {
    v14 = strlen(szFileName);
    v15 = v14;
    if ( v7 >= (int)(v14 + 1) )
    {
      memcpy(dst: (unsigned __int8 *)v9, src: (unsigned __int8 *)szFileName, count: v14 + 1);
LABEL_34:
      v13 = style;
      v9 += v15;
      v7 -= v15;
      goto LABEL_35;
    }
    return 0;
  }
  if ( (style & 8) != 0 )
  {
    v16 = &szFileName[strlen(szFileName)];
    for ( i = 3; v16 > szFileName; --v16 )
    {
      if ( (*v16 == 92 || *v16 == 47) && --i == 0 )
        break;
    }
    v15 = strlen(v16);
    if ( v7 < (int)(v15 + 1) )
    {
      *(v9 - 3) = v18;
      return 0;
    }
    memcpy(dst: (unsigned __int8 *)v9, src: (unsigned __int8 *)szFileName, count: v15 + 1);
    goto LABEL_34;
  }
LABEL_35:
  if ( (v13 & 0x30) != 0 )
  {
    if ( (v13 & 0x20) == 0 || (v19 = "(%d) + %d bytes", pAddress == nullptr) )
      v19 = "(%d)";
    if ( _snprintf(string: v9, count: v7, format: v19, pTranslationOut, pAddress) < 0 )
    {
      *v9 = 0;
      return 0;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000D7F0
// Name: public: void CHelperFunctionsLoader::EnsureReady(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHelperFunctionsLoader::EnsureReady(CHelperFunctionsLoader *this)
{
  CThreadFastMutex *p_m_Mutex; // ebx
  DWORD CurrentThreadId; // ecx
  CCommandLine *v4; // eax
  CCommandLine *v5; // eax
  bool v6; // zf
  HANDLE CurrentProcess; // eax
  HINSTANCE__ *LibraryA; // eax
  BOOL (__stdcall *SymInitialize)(HANDLE, PCSTR, BOOL); // eax
  HINSTANCE__ *m_hDbgHelpDll; // ecx
  BOOL (__stdcall *SymCleanup)(HANDLE); // eax
  DWORD (__stdcall *SymGetOptions)(); // eax
  DWORD (__stdcall *SymSetOptions)(DWORD); // eax
  BOOL (__stdcall *SymSetSearchPath)(HANDLE, PCSTR); // eax
  BOOL (__stdcall *SymEnumerateModules64)(HANDLE, PSYM_ENUMMODULES_CALLBACK64, PVOID); // eax
  BOOL (__stdcall *EnumerateLoadedModules64)(HANDLE, PENUMLOADED_MODULES_CALLBACK64, PVOID); // eax
  DWORD64 (__stdcall *SymLoadModule64)(HANDLE, HANDLE, PCSTR, PCSTR, DWORD64, DWORD); // eax
  BOOL (__stdcall *SymUnloadModule64)(HANDLE, DWORD64); // eax
  BOOL (__stdcall *SymFromAddr)(HANDLE, DWORD64, PDWORD64, PSYMBOL_INFO); // eax
  BOOL (__stdcall *SymGetLineFromAddr64)(HANDLE, DWORD64, PDWORD, PIMAGEHLP_LINE64); // eax
  BOOL (__stdcall *SymGetModuleInfo64)(HANDLE, DWORD64, PIMAGEHLP_MODULE64); // eax
  BOOL (__stdcall *StackWalk64)(DWORD, HANDLE, HANDLE, LPSTACKFRAME64, PVOID, PREAD_PROCESS_MEMORY_ROUTINE64, PFUNCTION_TABLE_ACCESS_ROUTINE64, PGET_MODULE_BASE_ROUTINE64, PTRANSLATE_ADDRESS_ROUTINE64); // eax
  unsigned int v23; // eax

  if ( this->m_bIsInitialized )
  {
    if ( this->m_bShouldReloadSymbols )
      CHelperFunctionsLoader::TryLoadingNewSymbols(this);
    return;
  }
  p_m_Mutex = &this->m_Mutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_Mutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_Mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(this: &this->m_Mutex, threadId: CurrentThreadId, nSpinSleepTime: 0);
  }
  else
  {
    ++this->m_Mutex.m_depth;
  }
  v4 = CommandLine();
  if ( v4->FindParm(this: v4, a2: "-steam") != 0 )
  {
    v5 = CommandLine();
    if ( v5->FindParm(this: v5, a2: "-internalbuild") == 0 )
    {
      this->m_bIsInitialized = true;
      v6 = this->m_Mutex.m_depth-- == 1;
      if ( !v6 )
        return;
      goto LABEL_47;
    }
  }
  CurrentProcess = GetCurrentProcess();
  this->m_hProcess = CurrentProcess;
  if ( CurrentProcess == nullptr )
  {
LABEL_46:
    v6 = this->m_Mutex.m_depth-- == 1;
    if ( !v6 )
      return;
    goto LABEL_47;
  }
  this->m_bIsInitialized = true;
  LibraryA = LoadLibraryA(lpLibFileName: "DbgHelp.dll");
  this->m_hDbgHelpDll = LibraryA;
  if ( LibraryA != nullptr )
  {
    SymInitialize = (BOOL (__stdcall *)(HANDLE, PCSTR, BOOL))GetProcAddress(
                                                               hModule: LibraryA,
                                                               lpProcName: "SymInitialize");
    m_hDbgHelpDll = this->m_hDbgHelpDll;
    this->m_pSymInitialize = (int (__stdcall *)(void *, char *, int))SymInitialize;
    if ( SymInitialize == nullptr )
    {
      FreeLibrary(hLibModule: m_hDbgHelpDll);
      this->m_hDbgHelpDll = nullptr;
      this->m_pSymInitialize = (int (__stdcall *)(void *, char *, int))SymUnloadModule64_DummyFn;
      v6 = this->m_Mutex.m_depth-- == 1;
      if ( !v6 )
        return;
      goto LABEL_47;
    }
    SymCleanup = (BOOL (__stdcall *)(HANDLE))GetProcAddress(hModule: m_hDbgHelpDll, lpProcName: "SymCleanup");
    this->m_pSymCleanup = SymCleanup;
    if ( SymCleanup == nullptr )
      this->m_pSymCleanup = (int (__stdcall *)(void *))SymCleanup_DummyFn;
    SymGetOptions = (DWORD (__stdcall *)())GetProcAddress(hModule: this->m_hDbgHelpDll, lpProcName: "SymGetOptions");
    this->m_pSymGetOptions = SymGetOptions;
    if ( SymGetOptions == nullptr )
      this->m_pSymGetOptions = (unsigned int (__stdcall *)())VirtualMemoryManager_AllocateVirtualMemorySection;
    SymSetOptions = (DWORD (__stdcall *)(DWORD))GetProcAddress(
                                                  hModule: this->m_hDbgHelpDll,
                                                  lpProcName: "SymSetOptions");
    this->m_pSymSetOptions = SymSetOptions;
    if ( SymSetOptions == nullptr )
      this->m_pSymSetOptions = (unsigned int (__stdcall *)(unsigned int))SymSetOptions_DummyFn;
    SymSetSearchPath = (BOOL (__stdcall *)(HANDLE, PCSTR))GetProcAddress(
                                                            hModule: this->m_hDbgHelpDll,
                                                            lpProcName: "SymSetSearchPath");
    this->m_pSymSetSearchPath = (int (__stdcall *)(void *, char *))SymSetSearchPath;
    if ( SymSetSearchPath == nullptr )
      this->m_pSymSetSearchPath = (int (__stdcall *)(void *, char *))SymSetSearchPath_DummyFn;
    SymEnumerateModules64 = (BOOL (__stdcall *)(HANDLE, PSYM_ENUMMODULES_CALLBACK64, PVOID))GetProcAddress(
                                                                                              hModule: this->m_hDbgHelpDll,
                                                                                              lpProcName: "SymEnumerateModules64");
    this->m_pSymEnumerateModules64 = SymEnumerateModules64;
    if ( SymEnumerateModules64 == nullptr )
      this->m_pSymEnumerateModules64 = (int (__stdcall *)(void *, int (__stdcall *)(const char *, unsigned __int64, void *), void *))SymUnloadModule64_DummyFn;
    EnumerateLoadedModules64 = (BOOL (__stdcall *)(HANDLE, PENUMLOADED_MODULES_CALLBACK64, PVOID))GetProcAddress(
                                                                                                    hModule: this->m_hDbgHelpDll,
                                                                                                    lpProcName: "EnumerateLoadedModules64");
    this->m_pEnumerateLoadedModules64 = EnumerateLoadedModules64;
    if ( EnumerateLoadedModules64 == nullptr )
      this->m_pEnumerateLoadedModules64 = (int (__stdcall *)(void *, int (__stdcall *)(const char *, unsigned __int64, unsigned int, void *), void *))SymUnloadModule64_DummyFn;
    SymLoadModule64 = (DWORD64 (__stdcall *)(HANDLE, HANDLE, PCSTR, PCSTR, DWORD64, DWORD))GetProcAddress(
                                                                                             hModule: this->m_hDbgHelpDll,
                                                                                             lpProcName: "SymLoadModule64");
    this->m_pSymLoadModule64 = (unsigned __int64 (__stdcall *)(void *, void *, char *, char *, unsigned __int64, unsigned int))SymLoadModule64;
    if ( SymLoadModule64 == nullptr )
      this->m_pSymLoadModule64 = SymLoadModule64_DummyFn;
    SymUnloadModule64 = (BOOL (__stdcall *)(HANDLE, DWORD64))GetProcAddress(
                                                               hModule: this->m_hDbgHelpDll,
                                                               lpProcName: "SymUnloadModule64");
    this->m_pSymUnloadModule64 = SymUnloadModule64;
    if ( SymUnloadModule64 == nullptr )
      this->m_pSymUnloadModule64 = SymUnloadModule64_DummyFn;
    SymFromAddr = (BOOL (__stdcall *)(HANDLE, DWORD64, PDWORD64, PSYMBOL_INFO))GetProcAddress(
                                                                                 hModule: this->m_hDbgHelpDll,
                                                                                 lpProcName: "SymFromAddr");
    this->m_pSymFromAddr = SymFromAddr;
    if ( SymFromAddr == nullptr )
      this->m_pSymFromAddr = (int (__stdcall *)(void *, unsigned __int64, unsigned __int64 *, _SYMBOL_INFO *))SymFromAddr_DummyFn;
    SymGetLineFromAddr64 = (BOOL (__stdcall *)(HANDLE, DWORD64, PDWORD, PIMAGEHLP_LINE64))GetProcAddress(
                                                                                            hModule: this->m_hDbgHelpDll,
                                                                                            lpProcName: "SymGetLineFromAddr64");
    this->m_pSymGetLineFromAddr64 = SymGetLineFromAddr64;
    if ( SymGetLineFromAddr64 == nullptr )
      this->m_pSymGetLineFromAddr64 = (int (__stdcall *)(void *, unsigned __int64, unsigned int *, _IMAGEHLP_LINE64 *))SymFromAddr_DummyFn;
    SymGetModuleInfo64 = (BOOL (__stdcall *)(HANDLE, DWORD64, PIMAGEHLP_MODULE64))GetProcAddress(
                                                                                    hModule: this->m_hDbgHelpDll,
                                                                                    lpProcName: "SymGetModuleInfo64");
    this->m_pSymGetModuleInfo64 = SymGetModuleInfo64;
    if ( SymGetModuleInfo64 == nullptr )
      this->m_pSymGetModuleInfo64 = (int (__stdcall *)(void *, unsigned __int64, _IMAGEHLP_MODULE64 *))CStdMemAlloc::Expand_NoLongerSupported;
    StackWalk64 = (BOOL (__stdcall *)(DWORD, HANDLE, HANDLE, LPSTACKFRAME64, PVOID, PREAD_PROCESS_MEMORY_ROUTINE64, PFUNCTION_TABLE_ACCESS_ROUTINE64, PGET_MODULE_BASE_ROUTINE64, PTRANSLATE_ADDRESS_ROUTINE64))GetProcAddress(hModule: this->m_hDbgHelpDll, lpProcName: "StackWalk64");
    this->m_pStackWalk64 = StackWalk64;
    if ( StackWalk64 == nullptr )
      this->m_pStackWalk64 = (int (__stdcall *)(unsigned int, void *, void *, _tagSTACKFRAME64 *, void *, int (__stdcall *)(void *, unsigned __int64, void *, unsigned int, unsigned int *), void *(__stdcall *)(void *, unsigned __int64), unsigned __int64 (__stdcall *)(void *, unsigned __int64), unsigned __int64 (__stdcall *)(void *, void *, _tagADDRESS64 *)))StackWalk64_DummyFn;
    v23 = this->m_pSymGetOptions();
    this->m_pSymSetOptions(a1: v23 | 0x80614);
    this->m_pSymInitialize(a1: this->m_hProcess, a2: this->m_szPDBSearchPath, a3: 0);
    CHelperFunctionsLoader::TryLoadingNewSymbols(this);
    goto LABEL_46;
  }
  if ( this->m_szPDBSearchPath == nullptr )
    this->m_bIsInitialized = false;
  v6 = this->m_Mutex.m_depth-- == 1;
  if ( v6 )
LABEL_47:
    _InterlockedExchange((volatile __int32 *)p_m_Mutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x1000DA80
// Name: int CrawlStack_StackWalk64(struct _CONTEXT __near *,void __near * __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CrawlStack_StackWalk64(
        _CONTEXT *pExceptionContext,
        void **pReturnAddressesOut,
        int iArrayCount,
        int iSkipCount)
{
  DWORD CurrentThreadId; // ecx
  int v5; // esi
  HANDLE CurrentThread; // edi
  int i; // esi
  _CONTEXT currentContext; // [esp+Ch] [ebp-3D4h] BYREF
  _tagSTACKFRAME64 sfFrame; // [esp+2D8h] [ebp-108h] BYREF

  CHelperFunctionsLoader::EnsureReady(this: &s_HelperFunctions);
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != s_HelperFunctions.m_Mutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&s_HelperFunctions.m_Mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(this: &s_HelperFunctions.m_Mutex, threadId: CurrentThreadId, nSpinSleepTime: 0);
  }
  else
  {
    ++s_HelperFunctions.m_Mutex.m_depth;
  }
  currentContext = *pExceptionContext;
  v5 = 0;
  memset(dst: (unsigned __int8 *)&sfFrame.AddrPC.Segment, value: 0, count: 0x100u);
  sfFrame.AddrFrame.Mode = AddrModeFlat;
  sfFrame.AddrPC.Mode = AddrModeFlat;
  sfFrame.AddrPC.Offset = currentContext.Eip;
  sfFrame.AddrFrame.Offset = currentContext.Ebp;
  CurrentThread = GetCurrentThread();
  if ( iSkipCount != 0 )
  {
    while ( s_HelperFunctions.m_pStackWalk64(
              a1: 0x14Cu,
              a2: s_HelperFunctions.m_hProcess,
              a3: CurrentThread,
              a4: &sfFrame,
              a5: &currentContext,
              a6: nullptr,
              a7: nullptr,
              a8: nullptr,
              a9: nullptr) != 0
         && sfFrame.AddrFrame.Offset != 0 )
    {
      if ( ++v5 == iSkipCount )
        goto LABEL_9;
    }
    if ( --s_HelperFunctions.m_Mutex.m_depth == 0 )
      _InterlockedExchange((volatile __int32 *)&s_HelperFunctions.m_Mutex, 0);
    return 0;
  }
  else
  {
LABEL_9:
    for ( i = 0; i != iArrayCount; pReturnAddressesOut[i++] = (void *)sfFrame.AddrPC.Offset )
    {
      if ( s_HelperFunctions.m_pStackWalk64(
             a1: 0x14Cu,
             a2: s_HelperFunctions.m_hProcess,
             a3: CurrentThread,
             a4: &sfFrame,
             a5: &currentContext,
             a6: nullptr,
             a7: nullptr,
             a8: nullptr,
             a9: nullptr) == 0 )
        break;
      if ( sfFrame.AddrFrame.Offset == 0 )
        break;
    }
    if ( --s_HelperFunctions.m_Mutex.m_depth == 0 )
      _InterlockedExchange((volatile __int32 *)&s_HelperFunctions.m_Mutex, 0);
    return i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000DC20
// Name: void GetCallStackReturnAddresses_Exception(void __near * __near *,int __near *,int,struct _EXCEPTION_POINTERS __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetCallStackReturnAddresses_Exception(
        void **CallStackReturnAddresses,
        int *pRetCount,
        int iSkipCount,
        _EXCEPTION_POINTERS *pExceptionInfo)
{
  *pRetCount = CrawlStack_StackWalk64(
                 pExceptionContext: pExceptionInfo->ContextRecord,
                 pReturnAddressesOut: CallStackReturnAddresses,
                 iArrayCount: *pRetCount,
                 iSkipCount: iSkipCount + 1);
}

//------------------------------------------------------------------------------
// Address: 0x1000DC50
// Name: _GetCallStack
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetCallStack(CpuidImpl *pReturnAddressesOut)
{
  CHelperFunctionsLoader::EnsureReady(this: &s_HelperFunctions);
  if ( (int (__stdcall *)(unsigned int, unsigned int, void *, _tagSTACKFRAME64 *, _tagSTACKFRAME64 *, int (__stdcall *)(void *, unsigned __int64, void *, unsigned int, unsigned int *), int (__stdcall *)(void *, unsigned __int64, void *, unsigned int, unsigned int *), void *(__stdcall *)(void *, unsigned __int64), unsigned __int64 (__stdcall *)(void *, unsigned __int64)))s_HelperFunctions.m_pStackWalk64 != StackWalk64_DummyFn )
    RaiseException(dwExceptionCode: 0, dwExceptionFlags: 1u, nNumberOfArguments: 0, lpArguments: nullptr);
  return VirtualMemoryManager_AllocateVirtualMemorySection(this: pReturnAddressesOut);
}

//------------------------------------------------------------------------------
// Address: 0x1000DD30
// Name: _SetStackTranslationSymbolSearchPath
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetStackTranslationSymbolSearchPath(char *szSemicolonSeparatedList)
{
  CHelperFunctionsLoader::SetStackTranslationSymbolSearchPath(this: &s_HelperFunctions, szSemicolonSeparatedList);
}

//------------------------------------------------------------------------------
// Address: 0x1000DD50
// Name: _TranslateStackInfo
// Source: json
//------------------------------------------------------------------------------
int __cdecl TranslateStackInfo(
        const void *const *pCallStack,
        int iCallStackCount,
        char *szOutput,
        int iOutBufferSize,
        char *szEntrySeparator,
        TranslateStackInfo_StyleFlags_t style)
{
  char *v6; // esi
  signed int v7; // ebx
  unsigned int v9; // eax
  char *v10; // esi
  int i; // [esp+20h] [ebp+10h]

  CHelperFunctionsLoader::EnsureReady(this: &s_HelperFunctions);
  v6 = szOutput;
  if ( szEntrySeparator == nullptr )
    szEntrySeparator = (char *)&unk_1002C436;
  v7 = strlen(szEntrySeparator);
  i = 0;
  if ( iCallStackCount <= 0 )
  {
LABEL_8:
    v10 = &v6[-v7];
    if ( v10 >= szOutput )
      *v10 = 0;
    return iCallStackCount;
  }
  else
  {
    while ( CHelperFunctionsLoader::TranslatePointer(
              this: &s_HelperFunctions,
              pAddress: pCallStack[i],
              pTranslationOut: v6,
              iTranslationBufferLength: iOutBufferSize,
              style) != 0 )
    {
      v9 = strlen(v6);
      iOutBufferSize -= v9;
      v6 += v9;
      if ( iOutBufferSize > v7 )
      {
        memcpy(dst: (unsigned __int8 *)v6, src: (unsigned __int8 *)szEntrySeparator, count: v7);
        v6 += v7;
        iOutBufferSize -= v7;
      }
      *v6 = 0;
      if ( ++i >= iCallStackCount )
        goto LABEL_8;
    }
    return i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000DE20
// Name: _GetFileAndLineFromAddress
// Source: json
//------------------------------------------------------------------------------
char __cdecl GetFileAndLineFromAddress(
        const void *pAddress,
        char *pFileNameOut,
        unsigned int iMaxFileNameLength,
        unsigned int *iLineNumberOut,
        unsigned int *pDisplacementOut)
{
  CHelperFunctionsLoader::EnsureReady(this: &s_HelperFunctions);
  return CHelperFunctionsLoader::GetFileAndLineFromAddress(
           this: &s_HelperFunctions,
           (int)pAddress,
           pFileNameOut,
           iMaxFileNameLength,
           iLineNumberOut,
           pDisplacementOut);
}

//------------------------------------------------------------------------------
// Address: 0x1000DE50
// Name: _GetSymbolNameFromAddress
// Source: json
//------------------------------------------------------------------------------
char __cdecl GetSymbolNameFromAddress(
        const void *pAddress,
        char *pSymbolNameOut,
        unsigned int iMaxSymbolNameLength,
        unsigned __int64 *pDisplacementOut)
{
  CHelperFunctionsLoader::EnsureReady(this: &s_HelperFunctions);
  return CHelperFunctionsLoader::GetSymbolNameFromAddress(
           this: &s_HelperFunctions,
           (int)pAddress,
           pSymbolNameOut,
           iMaxSymbolNameLength,
           pDisplacementOut);
}

//------------------------------------------------------------------------------
// Address: 0x1000DE80
// Name: _GetModuleNameFromAddress
// Source: json
//------------------------------------------------------------------------------
char __cdecl GetModuleNameFromAddress(const void *pAddress, char *pModuleNameOut, unsigned int iMaxModuleNameLength)
{
  CHelperFunctionsLoader::EnsureReady(this: &s_HelperFunctions);
  return CHelperFunctionsLoader::GetModuleNameFromAddress(
           this: &s_HelperFunctions,
           (int)pAddress,
           pModuleNameOut,
           iMaxModuleNameLength);
}

//------------------------------------------------------------------------------
// Address: 0x1000DEB0
// Name: public: CStackTop_CopyParentStack::CStackTop_CopyParentStack(void __near * const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CStackTop_CopyParentStack *__thiscall CStackTop_CopyParentStack::CStackTop_CopyParentStack(
        CStackTop_CopyParentStack *this,
        void **pParentStackTrace,
        int iParentStackTraceLength)
{
  int v3; // esi
  void *const *v5; // eax
  void **v6; // eax

  v3 = iParentStackTraceLength;
  this->m_pReplaceAddress = nullptr;
  this->m_pStackBase = this;
  this->m_pParentStackTrace = nullptr;
  if ( pParentStackTrace != nullptr && iParentStackTraceLength > 0 )
  {
    v5 = &pParentStackTrace[iParentStackTraceLength - 1];
    while ( *v5 == nullptr )
    {
      --v3;
      --v5;
      if ( v3 <= 0 )
        goto LABEL_8;
    }
    v6 = (void **)operator new(size: 4 * v3);
    this->m_pParentStackTrace = v6;
    memcpy(dst: (unsigned __int8 *)v6, src: (unsigned __int8 *)pParentStackTrace, count: 4 * v3);
  }
LABEL_8:
  this->m_iParentStackTraceLength = v3;
  this->m_pPrevTop = (CStackTop_Base *)GenericThreadLocals::CThreadLocalBase::Get(this: &g_StackTop);
  GenericThreadLocals::CThreadLocalBase::Set(this: &g_StackTop, value: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000DF40
// Name: public: CStackTop_CopyParentStack::~CStackTop_CopyParentStack(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStackTop_CopyParentStack::~CStackTop_CopyParentStack(CStackTop_CopyParentStack *this)
{
  void **m_pParentStackTrace; // esi

  GenericThreadLocals::CThreadLocalBase::Set(this: &g_StackTop, value: this->m_pPrevTop);
  m_pParentStackTrace = (void **)this->m_pParentStackTrace;
  if ( m_pParentStackTrace != nullptr )
    operator delete(p: m_pParentStackTrace);
}

//------------------------------------------------------------------------------
// Address: 0x1000DF70
// Name: public: CStackTop_ReferenceParentStack::CStackTop_ReferenceParentStack(void __near * const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CStackTop_ReferenceParentStack *__thiscall CStackTop_ReferenceParentStack::CStackTop_ReferenceParentStack(
        CStackTop_ReferenceParentStack *this,
        void *const *pParentStackTrace,
        int iParentStackTraceLength)
{
  int v3; // eax
  void *const *v5; // ecx

  v3 = iParentStackTraceLength;
  this->m_pReplaceAddress = nullptr;
  this->m_pStackBase = this;
  this->m_pParentStackTrace = pParentStackTrace;
  if ( pParentStackTrace != nullptr && iParentStackTraceLength > 0 )
  {
    v5 = &pParentStackTrace[iParentStackTraceLength - 1];
    do
    {
      if ( *v5 != nullptr )
        break;
      --v3;
      --v5;
    }
    while ( v3 > 0 );
  }
  this->m_iParentStackTraceLength = v3;
  this->m_pPrevTop = (CStackTop_Base *)GenericThreadLocals::CThreadLocalBase::Get(this: &g_StackTop);
  GenericThreadLocals::CThreadLocalBase::Set(this: &g_StackTop, value: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000DFD0
// Name: public: CStackTop_ReferenceParentStack::~CStackTop_ReferenceParentStack(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStackTop_ReferenceParentStack::~CStackTop_ReferenceParentStack(CStackTop_ReferenceParentStack *this)
{
  GenericThreadLocals::CThreadLocalBase::Set(this: &g_StackTop, value: this->m_pPrevTop);
  this->m_pParentStackTrace = nullptr;
  this->m_iParentStackTraceLength = 0;
}
