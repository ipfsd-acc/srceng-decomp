// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: p4lib/p4.cpp
// Functions: 451
// ============================================================

#include "p4lib\p4.h"

//------------------------------------------------------------------------------
// Address: 0x10001160
// Name: public: virtual int ClientUser::OutputError(char __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall ClientUser::OutputError(ClientUser *this, char *errBuf)
{
  this->OutputError_2(this, a2: errBuf);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10001180
// Name: public: virtual int ClientUser::OutputInfo(char,char __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall ClientUser::OutputInfo(ClientUser *this, int level, char *data)
{
  this->OutputInfo_2(this, a2: level, a3: data);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100011A0
// Name: public: virtual int ClientUser::OutputBinary(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall ClientUser::OutputBinary(ClientUser *this, char *data, int length)
{
  this->OutputBinary_2(this, a2: data, a3: length);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100011C0
// Name: public: virtual int ClientUser::OutputText(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall ClientUser::OutputText(ClientUser *this, char *data, int length)
{
  this->OutputText_2(this, a2: data, a3: length);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100011E0
// Name: public: virtual int ClientUser::Help(char __near * const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall ClientUser::Help(ClientUser *this, char *const *help)
{
  this->Help_2(this, a2: (const char *const *)help);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10001210
// Name: private: virtual void CInfoUser::OutputInfo(char,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInfoUser::OutputInfo(CInfoUser *this, char level, const char *data)
{
  const char *v3; // esi
  char *v5; // eax
  char szInfo[260]; // [esp+8h] [ebp-208h] BYREF
  char szCmd[260]; // [esp+10Ch] [ebp-104h] BYREF

  v3 = data;
  V_strncpy(pDest: szCmd, pSrc: data, maxLen: 260);
  v5 = _V_strstr(s1: szCmd, search: " ");
  if ( v5 != nullptr )
  {
    *v5 = 0;
    V_strncpy(pDest: szInfo, pSrc: &v3[v5 - szCmd + 1], maxLen: 260);
  }
  else
  {
    szInfo[0] = 0;
  }
  if ( _V_stricmp(s1: szCmd, s2: "userName") != 0 )
  {
    if ( _V_stricmp(s1: szCmd, s2: "clientName") != 0 )
    {
      if ( _V_stricmp(s1: szCmd, s2: "clientHost") != 0 )
      {
        if ( _V_stricmp(s1: szCmd, s2: "clientRoot") == 0 )
        {
          CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&data + 1, pStr: szInfo);
          this->m_Client.m_sLocalRoot.m_Id = HIWORD(data);
        }
      }
      else
      {
        CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&data + 1, pStr: szInfo);
        this->m_Client.m_sHost.m_Id = HIWORD(data);
      }
    }
    else
    {
      CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&data + 1, pStr: szInfo);
      this->m_Client.m_sName.m_Id = HIWORD(data);
    }
  }
  else
  {
    CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&data + 1, pStr: szInfo);
    this->m_Client.m_sUser.m_Id = HIWORD(data);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001390
// Name: protected: virtual bool CErrorHandlerUser::ShallOutputErrorStringBuffer(class StrBuf __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CErrorHandlerUser::ShallOutputErrorStringBuffer(CErrorHandlerUser *this, StrBuf *buf)
{
  char *buffer; // esi

  buffer = buf->buffer;
  return (this->m_uiFlags & 2) == 0
      || _V_strstr(s1: buffer, search: "already opened for edit") == nullptr
      && _V_strstr(s1: buffer, search: "already opened for add") == nullptr
      && _V_strstr(s1: buffer, search: "currently opened for edit") == nullptr
      && _V_strstr(s1: buffer, search: "currently opened for add") == nullptr
      && _V_strstr(s1: buffer, search: "add of existing file") == nullptr
      && _V_strstr(s1: buffer, search: "add existing file") == nullptr
      && _V_strstr(s1: buffer, search: "can't change from") == nullptr
      && _V_strstr(s1: buffer, search: "no such file") == nullptr
      && _V_strstr(s1: buffer, search: "not on client") == nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10001460
// Name: public: void CSubmitUser::Submit(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSubmitUser::Submit(CSubmitUser *this, int nChangeList)
{
  char pBuf[128]; // [esp+0h] [ebp-8Ch] BYREF
  char *argv[3]; // [esp+80h] [ebp-Ch] BYREF

  this->m_pDescription = nullptr;
  V_snprintf(pDest: pBuf, maxLen: 128, pFormat: "%d", nChangeList);
  argv[0] = "-c";
  argv[1] = pBuf;
  argv[2] = nullptr;
  StrDict::SetArgv(this: &s_p4.m_Client, a2: 2, a3: argv);
  ClientApi::Run(this: &s_p4.m_Client, a2: "submit", a3: &g_ErrorHandlerUser);
}

//------------------------------------------------------------------------------
// Address: 0x100014D0
// Name: public: virtual bool CP4::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4::Connect(CP4 *this, void *(__cdecl *factory)(const char *, int *))
{
  g_pFileSystem = (IFileSystem *)((int (__thiscall *)(CP4 *, const char *, _DWORD))factory)(
                                   a1: this,
                                   a2: "VFileSystem017",
                                   a3: 0);
  return g_pFileSystem != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100014F0
// Name: public: virtual void CP4::Disconnect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CP4::Disconnect(CP4 *this)
{
  g_pFileSystem = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10001500
// Name: public: virtual void CP4::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CP4::Shutdown(CP4 *this)
{
  Error e; // [esp+4h] [ebp-Ch] BYREF

  e.ep = nullptr;
  e.severity = E_EMPTY;
  ClientApi::Final(this: &this->m_Client, a2: &e);
  this->m_bConnectedToServer = false;
  Error::~Error(this: &e);
}

//------------------------------------------------------------------------------
// Address: 0x10001540
// Name: public: virtual void __near * CP4::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CP4::QueryInterface(CP4 *this, const char *pInterfaceName)
{
  void *(__cdecl *FactoryThis)(const char *, int *); // eax

  FactoryThis = Sys_GetFactoryThis();
  return FactoryThis(a1: pInterfaceName, a2: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10001560
// Name: public: virtual char const __near * CP4::String(class CUtlSymbol)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CP4::String(CP4 *this, CUtlSymbol s)
{
  return CUtlSymbol::String(this: &s);
}

//------------------------------------------------------------------------------
// Address: 0x10001570
// Name: public: virtual char const __near * CP4::GetDepotRoot(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CP4::GetDepotRoot(CP4 *this)
{
  if ( this->IsConnectedToServer(this, a2: true) )
    return this->m_szDepotRoot;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10001590
// Name: public: virtual int CP4::GetDepotRootLength(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CP4::GetDepotRootLength(CP4 *this)
{
  if ( this->IsConnectedToServer(this, a2: true) )
    return this->m_iDepotRootLength;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x100015B0
// Name: public: virtual char const __near * CP4::GetLocalRoot(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CP4::GetLocalRoot(CP4 *this)
{
  if ( this->IsConnectedToServer(this, a2: true) )
    return this->m_szLocalRoot;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100015D0
// Name: public: virtual int CP4::GetLocalRootLength(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CP4::GetLocalRootLength(CP4 *this)
{
  if ( this->IsConnectedToServer(this, a2: true) )
    return this->m_iLocalRootLength;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x100015F0
// Name: public: virtual struct P4Client_t __near & CP4::GetActiveClient(void)
// Source: json
//------------------------------------------------------------------------------
P4Client_t *__thiscall CP4::GetActiveClient(CP4 *this)
{
  return &this->m_ActiveClient;
}

//------------------------------------------------------------------------------
// Address: 0x10001600
// Name: public: virtual bool CP4::GetClientSpecForFile(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4::GetClientSpecForFile(CP4 *this, const char *pFullPath, char *pClientSpec, int nMaxLen)
{
  char pCurPath[260]; // [esp+4h] [ebp-104h] BYREF

  V_strncpy(pDest: pCurPath, pSrc: pFullPath, maxLen: 260);
  V_StripFilename(path: pCurPath);
  return this->GetClientSpecForDirectory(this, a2: pCurPath, a3: pClientSpec, a4: nMaxLen);
}

//------------------------------------------------------------------------------
// Address: 0x10001660
// Name: public: virtual bool CP4::GetClientSpecForPath(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CP4::GetClientSpecForPath(CP4 *this, const char *pPathId, char *pClientSpec, int nMaxLen)
{
  bool (__thiscall *IsConnectedToServer)(IP4 *, bool); // edx
  unsigned __int8 *v6; // esi
  unsigned __int8 *v7; // edi
  _BYTE *v8; // eax
  char pPathBuf[2048]; // [esp+0h] [ebp-908h] BYREF
  char pTempClientSpec[260]; // [esp+800h] [ebp-108h] BYREF
  CP4 *v11; // [esp+904h] [ebp-4h]
  char bFoundClientSpec_3; // [esp+913h] [ebp+Bh]

  IsConnectedToServer = this->IsConnectedToServer;
  v11 = this;
  if ( ((unsigned __int8 (__stdcall *)(int))IsConnectedToServer)(a1: 1) == 0 )
  {
    if ( nMaxLen > 0 )
      *pClientSpec = 0;
  }
  else if ( g_pFileSystem->GetSearchPath(this: g_pFileSystem, a2: pPathId, a3: false, a4: pPathBuf, a5: 2048) != 0 )
  {
    bFoundClientSpec_3 = 0;
    v6 = (unsigned __int8 *)pPathBuf;
    do
    {
      v7 = v6;
      strchr(string: v6, chr: 0x3Bu);
      if ( v8 != nullptr )
      {
        *v8 = 0;
        v6 = v8 + 1;
      }
      else
      {
        v6 = nullptr;
      }
      if ( v11->GetClientSpecForDirectory(this: v11, a2: (const char *)v7, a3: pClientSpec, a4: nMaxLen) )
      {
        bFoundClientSpec_3 = 1;
        V_strncpy(pDest: pTempClientSpec, pSrc: pClientSpec, maxLen: 260);
      }
    }
    while ( v6 != nullptr );
    return bFoundClientSpec_3;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10001720
// Name: public: virtual void CP4::SetOpenFileChangeList(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CP4::SetOpenFileChangeList(CP4 *this, const char *pChangeListName)
{
  const char *v3; // esi
  int v4; // eax

  if ( CUtlString::Length(this: &this->m_sChangeListName) == 0 )
    goto LABEL_6;
  v3 = pChangeListName;
  if ( pChangeListName == nullptr || *pChangeListName == 0 )
    goto LABEL_7;
  if ( strcmp(CUtlString::Get(this: &this->m_sChangeListName), pChangeListName) != 0
    || pChangeListName == CUtlString::Get(this: &this->m_sChangeListName) )
  {
LABEL_6:
    v3 = pChangeListName;
LABEL_7:
    CUtlString::Set(this: &this->m_sChangeListName, pValue: v3);
    CUtlString::Set(this: &this->m_sCachedChangeListNum, pValue: "0");
    this->m_nCachedChangeListNumber = 0;
    v4 = CUtlString::Length(this: &this->m_sChangeListName);
    g_ErrorHandlerUser.m_uiFlags = (v4 != 0 ? 2 : 0) | g_ErrorHandlerUser.m_uiFlags & ~(v4 != 0 ? 0 : 2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100017F0
// Name: MakeFilesWritable
// Source: json
//------------------------------------------------------------------------------
char __cdecl MakeFilesWritable(int nCount, const char **ppFullPathList)
{
  char result; // al
  int v4; // esi
  const char *v5; // edi
  char bResult_3; // [esp+13h] [ebp+Bh]

  result = 1;
  v4 = 0;
  bResult_3 = 1;
  if ( nCount > 0 )
  {
    do
    {
      v5 = ppFullPathList[v4];
      if ( access(path: v5, amode: 2) != 0 && chmod(path: v5, mode: 384) != 0 )
        bResult_3 = 0;
      ++v4;
    }
    while ( v4 < nCount );
    return bResult_3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10001840
// Name: public: virtual bool CP4::SubmitFile(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4::SubmitFile(CP4 *this, const char *pFullPath, const char *pDescription)
{
  return this->SubmitFiles(this, a2: 1, a3: &pFullPath, a4: pDescription);
}

//------------------------------------------------------------------------------
// Address: 0x10001860
// Name: void SimplePerforceOp(int,char const __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SimplePerforceOp(int nCount, const char **ppFullPathList)
{
  StrDict::SetArgv(this: &s_p4.m_Client, a2: nCount, a3: (char *const *)ppFullPathList);
  ClientApi::Run(this: &s_p4.m_Client, a2: s_pOperation, a3: &g_ErrorHandlerUser);
}

//------------------------------------------------------------------------------
// Address: 0x10001890
// Name: public: virtual void CP4::OpenFileInP4Win(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CP4::OpenFileInP4Win(CP4 *this, const char *pFullPath)
{
  char pSystem[512]; // [esp+4h] [ebp-358h] BYREF
  char pClientSpec[260]; // [esp+204h] [ebp-158h] BYREF
  _STARTUPINFOA StartupInfo; // [esp+308h] [ebp-54h] BYREF
  _PROCESS_INFORMATION pi; // [esp+34Ch] [ebp-10h] BYREF

  if ( this->IsConnectedToServer(this, a2: true) )
  {
    if ( this->GetClientSpecForFile(this, a2: pFullPath, a3: pClientSpec, a4: 260) )
      V_snprintf(pDest: pSystem, maxLen: 512, pFormat: "p4win -q -c %s -s %s", pClientSpec, pFullPath);
    else
      V_snprintf(pDest: pSystem, maxLen: 512, pFormat: "p4win -q -s %s", pFullPath);
    memset(dst: (unsigned __int8 *)&StartupInfo, value: 0, count: sizeof(StartupInfo));
    StartupInfo.cb = 68;
    memset(&pi, 0, sizeof(pi));
    CreateProcessA(
      lpApplicationName: nullptr,
      lpCommandLine: pSystem,
      lpProcessAttributes: nullptr,
      lpThreadAttributes: nullptr,
      bInheritHandles: false,
      dwCreationFlags: 0,
      lpEnvironment: nullptr,
      lpCurrentDirectory: nullptr,
      lpStartupInfo: &StartupInfo,
      lpProcessInformation: &pi);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001960
// Name: public: virtual bool CP4::IsConnectedToServer(bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4::IsConnectedToServer(CP4 *this, bool bRetry)
{
  if ( !bRetry )
    goto LABEL_5;
  if ( this->m_bConnectedToServer )
  {
    if ( ClientApi::Dropped(this: &this->m_Client) != 0 )
      this->Shutdown(this);
LABEL_5:
    if ( this->m_bConnectedToServer )
      return this->m_bConnectedToServer;
  }
  if ( bRetry )
    this->Init(this);
  return this->m_bConnectedToServer;
}

//------------------------------------------------------------------------------
// Address: 0x100019B0
// Name: public: virtual char const __near * CP4::GetLastError(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CP4::GetLastError(CP4 *this)
{
  return g_ErrorHandlerUser.m_errorBuf.buffer;
}

//------------------------------------------------------------------------------
// Address: 0x100019C0
// Name: public: static bool CDefOps<int>::LessFunc(int const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CDefOps<int>::LessFunc(const int *lhs, const int *rhs)
{
  return *lhs < *rhs;
}

//------------------------------------------------------------------------------
// Address: 0x100019E0
// Name: public: virtual void CErrorHandlerUser::OutputError(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CErrorHandlerUser::OutputError(CErrorHandlerUser *this, const char *errBuf)
{
  ErrorSeverity m_errorSeverity; // eax

  m_errorSeverity = this->m_errorSeverity;
  if ( m_errorSeverity <= E_WARN )
    m_errorSeverity = E_WARN;
  this->m_errorSeverity = m_errorSeverity;
  _Msg(a1: "s_p4 error: %s", errBuf);
  StrBuf::Append(this: &this->m_errorBuf, src: errBuf);
}

//------------------------------------------------------------------------------
// Address: 0x10001A20
// Name: public: virtual void CErrorHandlerUser::Message(class Error __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CErrorHandlerUser::Message(CErrorHandlerUser *this, Error *err)
{
  this->HandleError(this, a2: err);
}

//------------------------------------------------------------------------------
// Address: 0x10001A30
// Name: public: virtual void CErrorHandlerUser::HandleError(class Error __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CErrorHandlerUser::HandleError(CErrorHandlerUser *this, Error *err)
{
  ErrorSeverity m_errorSeverity; // eax
  ErrorSeverity v4; // eax
  StrBuf buf; // [esp+8h] [ebp-Ch] BYREF

  m_errorSeverity = this->m_errorSeverity;
  if ( m_errorSeverity <= err->severity )
    m_errorSeverity = err->severity;
  this->m_errorSeverity = m_errorSeverity;
  buf.size = 0;
  buf.length = 0;
  buf.buffer = StrBuf::nullStrBuf;
  Error::Fmt(this: err, a2: &buf, a3: 2);
  if ( _V_strstr(s1: buf.buffer, search: "can't edit exclusive file already opened") != nullptr )
  {
    v4 = this->m_errorSeverity;
    if ( v4 <= E_WARN )
      v4 = E_WARN;
    this->m_errorSeverity = v4;
  }
  if ( (this->m_uiFlags & 1) != 0 || this->ShallOutputErrorStringBuffer(this, a2: &buf) )
    _Msg(a1: "%s: %s", Error::severityText[err->severity], buf.buffer);
  StrBuf::Append(this: &this->m_errorBuf, a2: &buf);
  if ( buf.buffer != StrBuf::nullStrBuf )
    free(pMem: buf.buffer);
}

//------------------------------------------------------------------------------
// Address: 0x10001B30
// Name: private: virtual void CSubmitUser::InputData(class StrBuf __near *,class Error __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSubmitUser::InputData(CSubmitUser *this, StrBuf *strbuf, Error *e)
{
  const char *v3; // eax
  const char *v4; // [esp-8h] [ebp-408h]
  const char *m_pDescription; // [esp-4h] [ebp-404h]
  char svChangelist[1024]; // [esp+0h] [ebp-400h] BYREF

  m_pDescription = this->m_pDescription;
  v4 = CUtlSymbol::String(this: &s_p4.m_ActiveClient.m_sUser);
  v3 = CUtlSymbol::String(this: &s_p4.m_ActiveClient.m_sName);
  V_snprintf(
    pDest: svChangelist,
    maxLen: 1024,
    pFormat: "Change:\tnew\n\nClient:\t%s\n\nUser:\t%s\n\nStatus:\tnew\n\nDescription:\n\t%s\n\nFiles:\n\n",
    v3,
    v4,
    m_pDescription);
  strbuf->length = 0;
  StrBuf::Append(this: strbuf, src: svChangelist);
  e->severity = E_EMPTY;
}

//------------------------------------------------------------------------------
// Address: 0x10001BA0
// Name: public: void CUtlMemory<struct CClientPathRecord,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CClientPathRecord,int>::Grow(CUtlMemory<CClientPathRecord,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CClientPathRecord *m_pMemory; // edx
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
    v7 = 521 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CClientPathRecord *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CClientPathRecord *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001C40
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<int,struct ChangelistDesc_t const __near *,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
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
        m_nAllocationCount = 2;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 16 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001CF0
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<int,struct ChangelistDesc_t const __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<int,struct ChangelistDesc_t const __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<int,struct ChangelistDesc_t const __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
        CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_1007C48C = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return dword_1007C48C;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x10001D50
// Name: public: virtual enum AppSystemTier_t CBaseAppSystem<class IP4>::GetTier(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAppSystem<IP4>::GetTier(CBaseAppSystem<IP4> *this)
{
  return 4;
}

//------------------------------------------------------------------------------
// Address: 0x10001D60
// Name: public: virtual void CBaseAppSystem<class IP4>::Reconnect(void __near * (*)(char const __near *,int __near *),char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAppSystem<IP4>::Reconnect(
        CBaseAppSystem<IP4> *this,
        void *(__cdecl *factory)(const char *, int *),
        const char *pInterfaceName)
{
  ReconnectInterface(factory, pInterfaceName);
}

//------------------------------------------------------------------------------
// Address: 0x10001D80
// Name: private: void CFileUser::ComputeLocalFileNames(class CUtlVector<struct P4File_t,class CUtlMemory<struct P4File_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileUser::ComputeLocalFileNames(
        CFileUser *this,
        CUtlVector<P4File_t,CUtlMemory<P4File_t,int> > *fileList)
{
  const struct StrPtr *Client; // eax
  int v3; // eax
  CUtlVector<P4File_t,CUtlMemory<P4File_t,int> > *v4; // ebx
  int v5; // esi
  const char *v6; // edi
  bool v7; // al
  char pLocalPath[260]; // [esp+4h] [ebp-214h] BYREF
  char pMatchPattern[260]; // [esp+108h] [ebp-110h] BYREF
  int nLen; // [esp+20Ch] [ebp-Ch]
  int m_Size; // [esp+210h] [ebp-8h]
  CUtlSymbol v12; // [esp+216h] [ebp-2h] BYREF

  Client = ClientApi::GetClient(this: &s_p4.m_Client);
  V_snprintf(pDest: pMatchPattern, maxLen: 260, pFormat: "//%s/", Client->buffer);
  v3 = _V_strlen(str: pMatchPattern);
  v4 = fileList;
  nLen = v3;
  if ( fileList->m_Size > 0 )
  {
    v5 = 0;
    m_Size = fileList->m_Size;
    do
    {
      if ( !v4->m_Memory.m_pMemory[v5].m_bDir )
      {
        HIWORD(fileList) = v4->m_Memory.m_pMemory[v5].m_sClientFile.m_Id;
        v6 = CUtlSymbol::String(this: (CUtlSymbol *)&fileList + 1);
        if ( V_stristr(pStr: v6, pSearch: pMatchPattern) == v6 )
        {
          v7 = s_p4.IsConnectedToServer(this: &s_p4, a2: true);
          V_ComposeFileName(
            path: v7 ? s_p4.m_szLocalRoot : nullptr,
            filename: &v6[nLen],
            dest: pLocalPath,
            destSize: 260);
          V_FixSlashes(pname: pLocalPath, separator: 92);
          CUtlSymbol::CUtlSymbol(this: &v12, pStr: pLocalPath);
          v4->m_Memory.m_pMemory[v5].m_sLocalFile = v12;
        }
      }
      ++v5;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001E90
// Name: public: void CClientspecMap::GetCommonDepotRoot(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientspecMap::GetCommonDepotRoot(CClientspecMap *this, char *pszDest, int destSize)
{
  int m_Size; // esi
  int v4; // ebx
  int v5; // esi
  CClientPathRecord *v6; // ecx
  char *v7; // eax
  int v8; // edx
  char v9; // cl
  char *v10; // eax

  m_Size = this->m_PathMap.m_Size;
  if ( m_Size != 0 )
  {
    V_strncpy(pDest: pszDest, pSrc: this->m_PathMap.m_Memory.m_pMemory->m_szDepotPath, maxLen: destSize);
    if ( m_Size > 1 )
    {
      v4 = 1;
      v5 = m_Size - 1;
      do
      {
        v6 = &this->m_PathMap.m_Memory.m_pMemory[v4];
        if ( !v6->m_bNegative )
        {
          v7 = pszDest;
          if ( *pszDest != 0 )
          {
            v8 = (char *)v6 - pszDest;
            do
            {
              v9 = v7[v8];
              if ( v9 == 0 )
                break;
              if ( *v7 != v9 )
              {
                *v7 = 0;
                break;
              }
              ++v7;
            }
            while ( *v7 != 0 );
          }
        }
        ++v4;
        --v5;
      }
      while ( v5 != 0 );
    }
    v10 = _V_strstr(s1: pszDest, search: "...");
    if ( v10 != nullptr )
      *v10 = 0;
  }
  else
  {
    *pszDest = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001F30
// Name: public: bool CP4::DepotFileToLocalFile(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CP4::DepotFileToLocalFile(CP4 *this, const char *pDepotFile, char *pLocalPath, int nBufLen)
{
  CP4 *v4; // edi
  const struct StrPtr *Client; // eax
  int m_Size; // eax
  const char *m_szDepotPath; // esi
  int v8; // ebx
  bool v9; // al
  int v10; // eax
  unsigned __int8 *v11; // esi
  int v12; // eax
  int v13; // eax
  const char *v14; // edi
  int v15; // esi
  bool v16; // al
  int v17; // eax
  bool v18; // al
  const char *v19; // eax
  const char *v20; // eax
  char pMatchingString[260]; // [esp+4h] [ebp-42Ch] BYREF
  char pClientPattern[260]; // [esp+108h] [ebp-328h] BYREF
  char szLocalRootWithoutSlashes[260]; // [esp+20Ch] [ebp-224h] BYREF
  char pTruncatedClientPath[260]; // [esp+310h] [ebp-120h] BYREF
  int nClientLen; // [esp+414h] [ebp-1Ch]
  int v27; // [esp+418h] [ebp-18h]
  CP4 *v28; // [esp+41Ch] [ebp-14h]
  int nMatchCount; // [esp+420h] [ebp-10h]
  CUtlSymbol v30; // [esp+426h] [ebp-Ah] BYREF
  unsigned int v31; // [esp+428h] [ebp-8h]
  bool bRecursive; // [esp+42Eh] [ebp-2h]
  bool bClientRecursive; // [esp+42Fh] [ebp-1h]

  v4 = this;
  v28 = this;
  Client = ClientApi::GetClient(this: &this->m_Client);
  V_snprintf(pDest: pClientPattern, maxLen: 260, pFormat: "//%s/", Client->buffer);
  nClientLen = _V_strlen(str: pClientPattern);
  m_Size = v4->m_ClientMapping.m_Size;
  nMatchCount = 0;
  if ( m_Size > 0 )
  {
    v31 = 0;
    v27 = m_Size;
    while ( 1 )
    {
      m_szDepotPath = v4->m_ClientMapping.m_Memory.m_pMemory[v31 / 0x209].m_szDepotPath;
      v8 = _V_strlen(str: m_szDepotPath);
      if ( nMatchCount <= v8 )
      {
        bRecursive = _V_stricmp(s1: &m_szDepotPath[v8 - 4], s2: "/...") == 0;
        v9 = _V_stricmp(s1: &m_szDepotPath[v8 - 2], s2: "/*") == 0;
        bClientRecursive = v9;
        if ( bRecursive )
        {
          v10 = v8 - 2;
          goto LABEL_7;
        }
        if ( v9 )
          break;
      }
LABEL_28:
      v31 += 521;
      if ( --v27 == 0 )
        return nMatchCount > 0;
    }
    v10 = v8;
LABEL_7:
    V_strncpy(pDest: pMatchingString, pSrc: m_szDepotPath, maxLen: v10);
    if ( V_stristr(pStr: pDepotFile, pSearch: pMatchingString) != pDepotFile )
      goto LABEL_28;
    if ( bClientRecursive )
    {
      v11 = (unsigned __int8 *)&pDepotFile[v8 - 1];
      strchr(string: v11, chr: 0x5Cu);
      if ( v12 != 0 )
        goto LABEL_28;
      strchr(string: v11, chr: 0x2Fu);
      if ( v13 != 0 )
        goto LABEL_28;
    }
    CUtlSymbol::CUtlSymbol(this: &v30, pStr: v4->m_ClientMapping.m_Memory.m_pMemory[v31 / 0x209].m_szClientPath);
    v14 = CUtlSymbol::String(this: &v30);
    v15 = _V_strlen(str: v14);
    bClientRecursive = _V_stricmp(s1: &v14[v15 - 4], s2: "/...") == 0;
    v16 = _V_stricmp(s1: &v14[v15 - 2], s2: "/*") == 0;
    if ( bClientRecursive )
    {
      v17 = v15 - 2;
    }
    else
    {
      if ( !v16 )
      {
LABEL_27:
        v4 = v28;
        goto LABEL_28;
      }
      v17 = v15;
    }
    V_strncpy(pDest: pTruncatedClientPath, pSrc: v14, maxLen: v17);
    if ( V_stristr(pStr: pTruncatedClientPath, pSearch: pClientPattern) == pTruncatedClientPath )
    {
      v18 = s_p4.IsConnectedToServer(this: &s_p4, a2: true);
      V_strncpy(pDest: szLocalRootWithoutSlashes, pSrc: v18 ? s_p4.m_szLocalRoot : nullptr, maxLen: 260);
      V_StripTrailingSlash(ppath: szLocalRootWithoutSlashes);
      if ( nClientLen >= v15 - 3 )
      {
        if ( bRecursive )
          v20 = &pDepotFile[v8 - 3];
        else
          v20 = &pDepotFile[v8 - 1];
        V_snprintf(pDest: pLocalPath, maxLen: nBufLen, pFormat: "%s\\%s", szLocalRootWithoutSlashes, v20);
      }
      else
      {
        if ( bRecursive )
          v19 = &pDepotFile[v8 - 3];
        else
          v19 = &pDepotFile[v8 - 1];
        V_snprintf(
          pDest: pLocalPath,
          maxLen: nBufLen,
          pFormat: "%s\\%s%s",
          szLocalRootWithoutSlashes,
          &pTruncatedClientPath[nClientLen],
          v19);
      }
      V_FixSlashes(pname: pLocalPath, separator: 92);
      nMatchCount = v8;
    }
    goto LABEL_27;
  }
  return nMatchCount > 0;
}

//------------------------------------------------------------------------------
// Address: 0x100021F0
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<int,struct ChangelistDesc_t const __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<int,struct ChangelistDesc_t const __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<int,struct ChangelistDesc_t const __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
        CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_1007C48C = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return `CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return this->m_Elements.m_pMemory[i].m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x10002250
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<int,struct ChangelistDesc_t const __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<int,struct ChangelistDesc_t const __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<int,struct ChangelistDesc_t const __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
        CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_1007C48C = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return HIWORD(`CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel);
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x100022B0
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<int,struct ChangelistDesc_t const __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<int,struct ChangelistDesc_t const __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<int,struct ChangelistDesc_t const __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(
        CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // eax
  unsigned __int16 index; // cx
  unsigned __int16 v5; // cx
  unsigned __int16 v6; // di
  int v7; // eax
  unsigned __int16 v8; // cx
  unsigned __int16 v9; // cx
  UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short> *v12; // edx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree == 0xFFFF )
  {
    m_nAllocationCount = this->m_Elements.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= m_nAllocationCount )
    {
      m_nAllocationCount = this->m_Elements.m_nAllocationCount;
      v5 = (m_nAllocationCount > 0) - 1;
    }
    else
    {
      index = this->m_LastAlloc.index;
      if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
        v5 = -1;
      else
        v5 = index + 1;
    }
    v6 = v5;
    if ( v5 >= m_nAllocationCount )
    {
      CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
        this: &this->m_Elements,
        num: 1);
      v7 = this->m_Elements.m_nAllocationCount;
      if ( this->m_LastAlloc.index >= v7 )
      {
        v7 = this->m_Elements.m_nAllocationCount;
        v9 = (v7 > 0) - 1;
      }
      else
      {
        v8 = this->m_LastAlloc.index;
        if ( (unsigned __int16)(v8 + 1) >= v7 )
          v9 = -1;
        else
          v9 = v8 + 1;
      }
      v6 = v9;
      if ( v9 >= v7 )
        _Warning(a1: "CUtlRBTree overflow!\n");
    }
    m_pMemory = this->m_Elements.m_pMemory;
    this->m_LastAlloc.index = v6;
    this->m_pElements = m_pMemory;
    return v6;
  }
  else
  {
    v12 = this->m_Elements.m_pMemory;
    this->m_FirstFree = v12[m_FirstFree].m_Right;
    this->m_pElements = v12;
    return m_FirstFree;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100023B0
// Name: public: int CUtlVector<char const __near *,class CUtlMemory<char const __near *,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<char const *,CUtlMemory<char const *,int>>::InsertMultipleBefore(
        CUtlVector<char const *,CUtlMemory<char const *,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  const char **m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<int,int>::Grow(
      (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &(&m_pMemory[elem])[num], src: &m_pMemory[elem], count: 4 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10002420
// Name: public: int CUtlVector<struct CClientPathRecord,class CUtlMemory<struct CClientPathRecord,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CClientPathRecord,CUtlMemory<CClientPathRecord,int>>::InsertMultipleBefore(
        CUtlVector<CClientPathRecord,CUtlMemory<CClientPathRecord,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CClientPathRecord *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CClientPathRecord,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 521 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100024A0
// Name: protected: void CUtlRBTree<struct CUtlMap<int,struct ChangelistDesc_t const __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<int,struct ChangelistDesc_t const __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<int,struct ChangelistDesc_t const __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
        CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v4; // ax
  int v5; // edi
  unsigned __int16 v6; // ax
  int elema; // [esp+14h] [ebp+8h]

  v4 = CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
         this,
         i: elem);
  v5 = v4;
  this->m_Elements.m_pMemory[elem].m_Right = CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
                                               this,
                                               i: v4);
  elema = elem;
  if ( CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
         this,
         i: v5) != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
                                 this,
                                 i: v5)].m_Parent = elem;
  if ( (_WORD)v5 != 0xFFFF )
    this->m_Elements.m_pMemory[v5].m_Parent = CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v5;
  }
  else
  {
    v6 = CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
           this,
           i: v6) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Left = v5;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Right = v5;
  }
  this->m_Elements.m_pMemory[v5].m_Left = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[elema].m_Parent = v5;
}

//------------------------------------------------------------------------------
// Address: 0x10002590
// Name: protected: void CUtlRBTree<struct CUtlMap<int,struct ChangelistDesc_t const __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<int,struct ChangelistDesc_t const __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<int,struct ChangelistDesc_t const __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
        CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v4; // ax
  int v5; // edi
  unsigned __int16 v6; // ax
  int elema; // [esp+14h] [ebp+8h]

  v4 = CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
         this,
         i: elem);
  v5 = v4;
  this->m_Elements.m_pMemory[elem].m_Left = CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
                                              this,
                                              i: v4);
  elema = elem;
  if ( CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
         this,
         i: v5) != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
                                 this,
                                 i: v5)].m_Parent = elem;
  if ( (_WORD)v5 != 0xFFFF )
    this->m_Elements.m_pMemory[v5].m_Parent = CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v5;
  }
  else
  {
    v6 = CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RightChild(
           this,
           i: v6) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Right = v5;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Left = v5;
  }
  this->m_Elements.m_pMemory[v5].m_Right = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[elema].m_Parent = v5;
}

//------------------------------------------------------------------------------
// Address: 0x10002680
// Name: public: void CFileUser::RetrieveFilesInChangelist(unsigned int,class CUtlVector<struct P4File_t,class CUtlMemory<struct P4File_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileUser::RetrieveFilesInChangelist(
        CFileUser *this,
        unsigned int changeListNumber,
        CUtlVector<P4File_t,CUtlMemory<P4File_t,int> > *fileList)
{
  char changeListString[32]; // [esp+8h] [ebp-2Ch] BYREF
  char *argv[3]; // [esp+28h] [ebp-Ch] BYREF

  this->m_bChangesRecord = true;
  this->m_bAwaitingNewRecord = true;
  this->m_pData = fileList;
  this->m_nChangesIndex = 0;
  fileList->m_Size = 0;
  V_snprintf(pDest: changeListString, maxLen: 32, pFormat: "%d", changeListNumber);
  argv[0] = "-s";
  argv[1] = changeListString;
  argv[2] = nullptr;
  StrDict::SetArgv(this: &s_p4.m_Client, a2: 2, a3: argv);
  ClientApi::Run(this: &s_p4.m_Client, a2: "describe", a3: this);
  this->m_bChangesRecord = false;
  this->m_nChangesIndex = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10002700
// Name: private: void CFileUser::ComputeLocalDirectoryNames(class CUtlVector<struct P4File_t,class CUtlMemory<struct P4File_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileUser::ComputeLocalDirectoryNames(
        CFileUser *this,
        CUtlVector<P4File_t,CUtlMemory<P4File_t,int> > *fileList)
{
  CUtlVector<P4File_t,CUtlMemory<P4File_t,int> > *v2; // edi
  int v3; // esi
  int m_Size; // ebx
  const char *v5; // eax
  char pLocalPath[262]; // [esp+4h] [ebp-108h] BYREF
  CUtlSymbol v7; // [esp+10Ah] [ebp-2h] BYREF

  v2 = fileList;
  if ( fileList->m_Size > 0 )
  {
    v3 = 0;
    m_Size = fileList->m_Size;
    do
    {
      if ( v2->m_Memory.m_pMemory[v3].m_bDir )
      {
        HIWORD(fileList) = v2->m_Memory.m_pMemory[v3].m_sDepotFile.m_Id;
        v5 = CUtlSymbol::String(this: (CUtlSymbol *)&fileList + 1);
        if ( CP4::DepotFileToLocalFile(this: &s_p4, pDepotFile: v5, pLocalPath, nBufLen: 260) )
        {
          CUtlSymbol::CUtlSymbol(this: &v7, pStr: pLocalPath);
          v2->m_Memory.m_pMemory[v3].m_sLocalFile = v7;
        }
      }
      ++v3;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002780
// Name: public: virtual void CP4::GetDepotFilePath(char __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CP4::GetDepotFilePath(CP4 *this, char *depotFilePath, char *filespec, int size)
{
  const char *v4; // eax
  char *v5[2]; // [esp+0h] [ebp-8h] BYREF

  if ( this->IsConnectedToServer(this, a2: true) )
  {
    v5[0] = filespec;
    g_WhereUser.m_bAwaitingNewRecord = true;
    g_WhereUser.m_pData = &g_WhereUser.m_Data;
    g_WhereUser.m_Data.m_Size = 0;
    v5[1] = nullptr;
    StrDict::SetArgv(this: &s_p4.m_Client, a2: 1, a3: v5);
    ClientApi::Run(this: &s_p4.m_Client, a2: "where", a3: &g_WhereUser);
    v4 = CUtlSymbol::String(this: &g_WhereUser.m_Data.m_Memory.m_pMemory->m_sDepotFile);
    V_strncpy(pDest: depotFilePath, pSrc: v4, maxLen: size);
  }
  else if ( size > 0 )
  {
    *depotFilePath = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002820
// Name: public: virtual void CP4::GetClientFilePath(char __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CP4::GetClientFilePath(CP4 *this, char *clientFilePath, char *filespec, int size)
{
  const char *v4; // eax
  char *v5[2]; // [esp+0h] [ebp-8h] BYREF

  if ( this->IsConnectedToServer(this, a2: true) )
  {
    v5[0] = filespec;
    g_WhereUser.m_bAwaitingNewRecord = true;
    g_WhereUser.m_pData = &g_WhereUser.m_Data;
    g_WhereUser.m_Data.m_Size = 0;
    v5[1] = nullptr;
    StrDict::SetArgv(this: &s_p4.m_Client, a2: 1, a3: v5);
    ClientApi::Run(this: &s_p4.m_Client, a2: "where", a3: &g_WhereUser);
    v4 = CUtlSymbol::String(this: &g_WhereUser.m_Data.m_Memory.m_pMemory->m_sClientFile);
    V_strncpy(pDest: clientFilePath, pSrc: v4, maxLen: size);
  }
  else if ( size > 0 )
  {
    *clientFilePath = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100028C0
// Name: public: virtual void CP4::GetLocalFilePath(char __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CP4::GetLocalFilePath(CP4 *this, char *localFilePath, char *filespec, int size)
{
  const char *v4; // eax
  char *v5[2]; // [esp+0h] [ebp-8h] BYREF

  if ( this->IsConnectedToServer(this, a2: true) )
  {
    v5[0] = filespec;
    g_WhereUser.m_bAwaitingNewRecord = true;
    g_WhereUser.m_pData = &g_WhereUser.m_Data;
    g_WhereUser.m_Data.m_Size = 0;
    v5[1] = nullptr;
    StrDict::SetArgv(this: &s_p4.m_Client, a2: 1, a3: v5);
    ClientApi::Run(this: &s_p4.m_Client, a2: "where", a3: &g_WhereUser);
    v4 = CUtlSymbol::String(this: &g_WhereUser.m_Data.m_Memory.m_pMemory->m_sLocalFile);
    V_strncpy(pDest: localFilePath, pSrc: v4, maxLen: size);
  }
  else if ( size > 0 )
  {
    *localFilePath = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002960
// Name: public: virtual void CP4::GetOpenedFileList(class CUtlVector<struct P4File_t,class CUtlMemory<struct P4File_t,int>> __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CP4::GetOpenedFileList(
        CP4 *this,
        CUtlVector<P4File_t,CUtlMemory<P4File_t,int> > *fileList,
        bool bDefaultChangeOnly)
{
  char *v3[3]; // [esp+0h] [ebp-Ch] BYREF

  if ( this->IsConnectedToServer(this, a2: true) )
  {
    g_FileUser.m_bAwaitingNewRecord = true;
    g_FileUser.m_pData = fileList;
    fileList->m_Size = 0;
    if ( bDefaultChangeOnly )
    {
      v3[0] = "-c";
      v3[1] = "default";
      v3[2] = nullptr;
      StrDict::SetArgv(this: &s_p4.m_Client, a2: 2, a3: v3);
    }
    ClientApi::Run(this: &s_p4.m_Client, a2: "opened", a3: &g_FileUser);
    CFileUser::ComputeLocalFileNames(this: &g_FileUser, fileList);
  }
  else
  {
    fileList->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100029F0
// Name: public: virtual void CP4::GetFileListInChangelist(unsigned int,class CUtlVector<struct P4File_t,class CUtlMemory<struct P4File_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CP4::GetFileListInChangelist(
        CP4 *this,
        unsigned int changeListNumber,
        CUtlVector<P4File_t,CUtlMemory<P4File_t,int> > *fileList)
{
  if ( this->IsConnectedToServer(this, a2: true) )
    CFileUser::RetrieveFilesInChangelist(this: &g_FileUser, changeListNumber, fileList);
  else
    fileList->m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10002A20
// Name: public: virtual bool CP4::GetClientSpecForDirectory(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4::GetClientSpecForDirectory(CP4 *this, const char *pFullPathDir, char *pClientSpec, int nMaxLen)
{
  bool result; // al
  char temp[1024]; // [esp+4h] [ebp-938h] BYREF
  char token[256]; // [esp+404h] [ebp-538h] BYREF
  char value[256]; // [esp+504h] [ebp-438h] BYREF
  characterset_t breaks; // [esp+604h] [ebp-338h] BYREF
  char pP4ConfigPath[260]; // [esp+704h] [ebp-238h] BYREF
  char pCurPath[260]; // [esp+808h] [ebp-134h] BYREF
  CUtlBuffer buf; // [esp+90Ch] [ebp-30h] BYREF

  if ( nMaxLen == 0 )
    return false;
  *pClientSpec = 0;
  result = this->IsConnectedToServer(this, a2: true);
  if ( result )
  {
    V_strncpy(pDest: pCurPath, pSrc: pFullPathDir, maxLen: 260);
    V_StripTrailingSlash(ppath: pCurPath);
    CharacterSetBuild(pSetBuffer: &breaks, pszSetString: "=\n");
    do
    {
      V_strncpy(pDest: pP4ConfigPath, pSrc: pCurPath, maxLen: 260);
      V_strncat(pDest: pP4ConfigPath, pSrc: "\\p4config", destBufferSize: 0x104u, max_chars_to_copy: 260);
      if ( g_pFileSystem->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: pP4ConfigPath, a3: nullptr) )
      {
        CUtlBuffer::CUtlBuffer(this: &buf, pBuffer: temp, nSize: 1024, nFlags: 3);
        if ( g_pFileSystem->ReadFile(
               this: &g_pFileSystem->IBaseFileSystem,
               a2: pP4ConfigPath,
               a3: nullptr,
               a4: &buf,
               a5: 0,
               a6: 0,
               a7: nullptr) )
        {
          if ( buf.m_Error == 0 )
          {
            while ( CUtlBuffer::ParseToken(
                      this: &buf,
                      pBreaks: &breaks,
                      pTokenBuf: token,
                      nMaxLen: 256,
                      bParseComments: true) != 0
                 && CUtlBuffer::GetToken(this: &buf, pToken: "=")
                 && CUtlBuffer::ParseToken(
                      this: &buf,
                      pBreaks: &breaks,
                      pTokenBuf: value,
                      nMaxLen: 256,
                      bParseComments: true) != 0 )
            {
              if ( _V_stricmp(s1: token, s2: "p4client") == 0 )
              {
                V_strncpy(pDest: pClientSpec, pSrc: value, maxLen: nMaxLen);
                if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
                  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
                return true;
              }
              if ( buf.m_Error != 0 )
                break;
            }
          }
          _Warning(a1: "Unable to read file %s!\n", pP4ConfigPath);
        }
        if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
      }
      V_StripLastDir(dirName: pCurPath, maxlen: 260);
      V_StripTrailingSlash(ppath: pCurPath);
    }
    while ( _V_strlen(str: pCurPath) > 2 );
    return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10002C60
// Name: void SubmitPerforceOp(int,char const __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SubmitPerforceOp(int nCount, const char **ppFullPathList, const char *pDescription)
{
  bool v3; // zf
  int v4; // edi
  void *v5; // esp
  char *v6[2]; // [esp+0h] [ebp-94h] BYREF
  unsigned __int8 v7[4]; // [esp+8h] [ebp-8Ch] BYREF
  char pBuf[128]; // [esp+Ch] [ebp-88h] BYREF
  char *v9[2]; // [esp+8Ch] [ebp-8h] BYREF

  if ( nCount > 0 )
  {
    g_ChangelistCreateUser.m_bAwaitingNewRecord = true;
    g_ChangelistCreateUser.m_pData = &g_ChangelistCreateUser.m_Data;
    g_ChangelistCreateUser.m_Data.m_Size = 0;
    if ( pDescription == nullptr || (v3 = *pDescription == 0, g_ChangelistCreateUser.m_pDescription = pDescription, v3) )
      g_ChangelistCreateUser.m_pDescription = "I'm a loser who didn't type a description. Mock me at your earliest convenience.";
    v9[0] = "-i";
    v9[1] = nullptr;
    StrDict::SetArgv(this: &s_p4.m_Client, a2: 1, a3: v9);
    ClientApi::Run(this: &s_p4.m_Client, a2: "change", a3: &g_ChangelistCreateUser);
    if ( g_ChangelistCreateUser.m_Data.m_Size != 0 )
    {
      v4 = *g_ChangelistCreateUser.m_Data.m_Memory.m_pMemory;
      V_snprintf(pDest: pBuf, maxLen: 128, pFormat: "%d", *g_ChangelistCreateUser.m_Data.m_Memory.m_pMemory);
      v5 = alloca(4 * (nCount + 2));
      v6[1] = pBuf;
      v6[0] = "-c";
      memcpy(dst: v7, src: (unsigned __int8 *)ppFullPathList, count: 4 * nCount);
      StrDict::SetArgv(this: &s_p4.m_Client, a2: nCount + 2, a3: v6);
      ClientApi::Run(this: &s_p4.m_Client, a2: "reopen", a3: &g_ErrorHandlerUser);
      CSubmitUser::Submit(this: &g_SubmitUser, nChangeList: v4);
    }
    else
    {
      g_ErrorHandlerUser.m_errorBuf.length = 0;
      StrBuf::Append(this: &g_ErrorHandlerUser.m_errorBuf, src: "Failed to create changelist for submit operation");
      g_ErrorHandlerUser.m_errorSeverity = E_FATAL;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002DB0
// Name: public: void CUtlRBTree<struct CUtlMap<int,struct ChangelistDesc_t const __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<int,struct ChangelistDesc_t const __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<int,struct ChangelistDesc_t const __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 index; // cx
  unsigned __int16 v3; // di
  int v4; // eax
  unsigned __int16 it; // [esp+4h] [ebp-4h]

  index = this->m_LastAlloc.index;
  if ( index != 0xFFFF )
  {
    v3 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    it = v3;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v3 < this->m_Elements.m_nAllocationCount
          && v3 <= index
          && CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
               this,
               i: it) != v3 )
        {
          v4 = v3;
          this->m_Elements.m_pMemory[v4].m_Right = this->m_FirstFree;
          this->m_Elements.m_pMemory[v4].m_Left = v3;
          this->m_FirstFree = v3;
        }
        index = this->m_LastAlloc.index;
        if ( v3 == index )
          break;
        ++v3;
        if ( (unsigned __int16)(it + 1) >= this->m_Elements.m_nAllocationCount )
          v3 = -1;
        it = v3;
      }
      while ( v3 != 0xFFFF );
    }
    *(_DWORD *)&this->m_Root = 0xFFFF;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002E60
// Name: public: unsigned short CUtlRBTree<struct CUtlMap<int,struct ChangelistDesc_t const __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<int,struct ChangelistDesc_t const __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<int,struct ChangelistDesc_t const __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(
        CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this)
{
  int result; // eax
  int v2; // ebx
  int *v3; // edx

  result = this->m_Root;
  v2 = `CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
  while ( 1 )
  {
    if ( (v2 & 1) == 0 )
    {
      `CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_1007C48C = 0x1FFFF;
      v2 |= 1u;
      `CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v2;
    }
    v3 = (_WORD)result == 0xFFFF
       ? &`CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
       : (int *)&this->m_Elements.m_pMemory[(unsigned __int16)result];
    if ( *(_WORD *)v3 == 0xFFFF )
      break;
    if ( (v2 & 1) == 0 )
    {
      `CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_1007C48C = 0x1FFFF;
      v2 |= 1u;
      `CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v2;
    }
    if ( (_WORD)result == 0xFFFF )
      result = (unsigned __int16)`CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      result = this->m_Elements.m_pMemory[(unsigned __int16)result].m_Left;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10002F30
// Name: public: int CUtlVector<struct CClientPathRecord,class CUtlMemory<struct CClientPathRecord,int>>::InsertBefore(int,struct CClientPathRecord const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CClientPathRecord,CUtlMemory<CClientPathRecord,int>>::InsertBefore(
        CUtlVector<CClientPathRecord,CUtlMemory<CClientPathRecord,int> > *this,
        int elem,
        const CClientPathRecord *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CClientPathRecord *m_pMemory; // ecx
  int v7; // eax
  int result; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CClientPathRecord,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 521 * v7);
  result = elem;
  if ( &this->m_Memory.m_pMemory[elem] != nullptr )
    qmemcpy(&this->m_Memory.m_pMemory[elem], src, sizeof(this->m_Memory.m_pMemory[elem]));
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10002FB0
// Name: protected: void CUtlRBTree<struct CUtlMap<int,struct ChangelistDesc_t const __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<int,struct ChangelistDesc_t const __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<int,struct ChangelistDesc_t const __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(struct CUtlMap<int,struct ChangelistDesc_t const __near *,unsigned short>::Node_t const __near &,unsigned short __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
        CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        const CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t *insert,
        unsigned __int16 *parent,
        bool *leftchild)
{
  unsigned __int16 m_Root; // di
  int v6; // esi

  m_Root = this->m_Root;
  *parent = -1;
  *leftchild = false;
  while ( m_Root != 0xFFFF )
  {
    *parent = m_Root;
    v6 = m_Root;
    if ( this->m_LessFunc.m_LessFunc(a1: insert, a2: &this->m_Elements.m_pMemory[v6].m_Data) != 0 )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1007C48C = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1007C48C = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v6].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100030A0
// Name: protected: void CUtlRBTree<struct CUtlMap<int,struct ChangelistDesc_t const __near *,unsigned short>::Node_t,unsigned short,class CUtlMap<int,struct ChangelistDesc_t const __near *,unsigned short>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<int,struct ChangelistDesc_t const __near *,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
        CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // dx
  int v4; // eax
  int *v5; // ecx
  int v6; // ecx
  int *v7; // ecx
  int *v8; // ecx
  int v9; // edi
  int *v10; // ecx
  int v11; // ebx
  int *v12; // ecx
  int v13; // ecx
  int *v14; // ecx
  int *v15; // ecx
  int v16; // edx
  int *v17; // ecx
  int *v18; // ecx
  int v19; // ecx
  int *v20; // eax
  int v21; // ecx
  int *v22; // eax
  int *v23; // eax
  int *v24; // ecx
  int *v25; // ecx
  int *v26; // ecx
  int v27; // ecx
  int *v28; // eax
  int v29; // ecx
  int *v30; // eax
  int *v31; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      v4 = `CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1007C48C = 0x1FFFF;
        v4 = `CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
      }
      if ( v2 == 0xFFFF )
        v5 = &`CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v5 = (int *)&this->m_Elements.m_pMemory[v2];
      v6 = *((unsigned __int16 *)v5 + 2);
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1007C48C = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v6 == 0xFFFF )
        v7 = &`CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v7 = (int *)&this->m_Elements.m_pMemory[v6];
      if ( *((_WORD *)v7 + 3) != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1007C48C = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( v2 == 0xFFFF )
        v8 = &`CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v8 = (int *)&this->m_Elements.m_pMemory[v2];
      v9 = *((unsigned __int16 *)v8 + 2);
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1007C48C = 0x1FFFF;
      }
      if ( (_WORD)v9 == 0xFFFF )
        v10 = &`CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v10 = (int *)&this->m_Elements.m_pMemory[v9];
      v11 = *((unsigned __int16 *)v10 + 2);
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1007C48C = 0x1FFFF;
      }
      if ( (_WORD)v9 == 0xFFFF )
        v12 = &`CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v12 = (int *)&this->m_Elements.m_pMemory[v9];
      v13 = *((unsigned __int16 *)v12 + 2);
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1007C48C = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v13 == 0xFFFF )
        v14 = &`CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v14 = (int *)&this->m_Elements.m_pMemory[v13];
      if ( *(_WORD *)v14 == (_WORD)v9 )
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1007C48C = 0x1FFFF;
        }
        if ( (_WORD)v11 == 0xFFFF )
          v15 = &`CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v15 = (int *)&this->m_Elements.m_pMemory[v11];
        v16 = *((unsigned __int16 *)v15 + 1);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1007C48C = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        if ( (_WORD)v16 == 0xFFFF )
          v17 = &`CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v17 = (int *)&this->m_Elements.m_pMemory[v16];
        if ( *((_WORD *)v17 + 3) == 0 )
          goto LABEL_81;
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1007C48C = 0x1FFFF;
        }
        if ( elem == 0xFFFF )
          v18 = &`CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v18 = (int *)&this->m_Elements.m_pMemory[elem];
        v19 = *((unsigned __int16 *)v18 + 2);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1007C48C = 0x1FFFF;
        }
        if ( (_WORD)v19 == 0xFFFF )
          v20 = &`CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v20 = (int *)&this->m_Elements.m_pMemory[v19];
        if ( *((_WORD *)v20 + 1) == elem )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
            this,
            elem: v9);
          v21 = `CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v21 = `CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_1007C48C = 0x1FFFF;
          }
          if ( (_WORD)v9 == 0xFFFF )
            v22 = &`CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v22 = (int *)&this->m_Elements.m_pMemory[v9];
          v9 = *((unsigned __int16 *)v22 + 2);
          if ( (v21 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v21 | 1;
            `CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_1007C48C = 0x1FFFF;
          }
          if ( (_WORD)v9 == 0xFFFF )
            v23 = &`CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v23 = (int *)&this->m_Elements.m_pMemory[v9];
          LOWORD(v11) = *((_WORD *)v23 + 2);
        }
        this->m_Elements.m_pMemory[(unsigned __int16)v9].m_Tag = 1;
        this->m_Elements.m_pMemory[(unsigned __int16)v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
          this,
          elem: v11);
      }
      else
      {
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1007C48C = 0x1FFFF;
        }
        if ( (_WORD)v11 == 0xFFFF )
          v24 = &`CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v24 = (int *)&this->m_Elements.m_pMemory[v11];
        v16 = *(unsigned __int16 *)v24;
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1007C48C = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        if ( (_WORD)v16 == 0xFFFF )
          v25 = &`CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v25 = (int *)&this->m_Elements.m_pMemory[v16];
        if ( *((_WORD *)v25 + 3) == 0 )
        {
LABEL_81:
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[v16].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
          goto LABEL_105;
        }
        if ( (v4 & 1) == 0 )
        {
          v4 |= 1u;
          `CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
          `CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1007C48C = 0x1FFFF;
        }
        if ( elem == 0xFFFF )
          v26 = &`CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v26 = (int *)&this->m_Elements.m_pMemory[elem];
        v27 = *((unsigned __int16 *)v26 + 2);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1007C48C = 0x1FFFF;
        }
        if ( (_WORD)v27 == 0xFFFF )
          v28 = &`CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v28 = (int *)&this->m_Elements.m_pMemory[v27];
        if ( *(_WORD *)v28 == elem )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateRight(
            this,
            elem: v9);
          v29 = `CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v29 = `CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_1007C48C = 0x1FFFF;
          }
          if ( (_WORD)v9 == 0xFFFF )
            v30 = &`CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v30 = (int *)&this->m_Elements.m_pMemory[v9];
          v9 = *((unsigned __int16 *)v30 + 2);
          if ( (v29 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v29 | 1;
            `CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
            dword_1007C48C = 0x1FFFF;
          }
          if ( (_WORD)v9 == 0xFFFF )
            v31 = &`CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
          else
            v31 = (int *)&this->m_Elements.m_pMemory[v9];
          LOWORD(v11) = *((_WORD *)v31 + 2);
        }
        this->m_Elements.m_pMemory[(unsigned __int16)v9].m_Tag = 1;
        this->m_Elements.m_pMemory[(unsigned __int16)v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RotateLeft(
          this,
          elem: v11);
      }
LABEL_105:
      if ( elem == this->m_Root )
        break;
      v2 = elem;
    }
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x10003690
// Name: public: CP4::CP4(void)
// Source: json
//------------------------------------------------------------------------------
CP4 *__thiscall CP4::CP4(CP4 *this)
{
  this->__vftable = (CP4_vtbl *)&CP4::`vftable';
  *(_DWORD *)&this->m_ActiveClient.m_sName.m_Id = -1;
  *(_DWORD *)&this->m_ActiveClient.m_sHost.m_Id = -1;
  this->m_ClientMapping.m_Memory.m_pMemory = nullptr;
  this->m_ClientMapping.m_Memory.m_nAllocationCount = 0;
  this->m_ClientMapping.m_Memory.m_nGrowSize = 0;
  this->m_ClientMapping.m_Size = 0;
  this->m_ClientMapping.m_pElements = nullptr;
  CUtlString::CUtlString(this: &this->m_sChangeListName);
  CUtlString::CUtlString(this: &this->m_sCachedChangeListNum);
  ClientApi::ClientApi(this: &this->m_Client);
  this->m_User.binaryStdout = 0;
  this->m_User.outputCharset = 0;
  this->m_User.__vftable = (ClientUser_vtbl *)&ClientUser::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10003700
// Name: public: void CFileUser::RetrieveDir(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileUser::RetrieveDir(CFileUser *this, const char *dir)
{
  CUtlVector<P4File_t,CUtlMemory<P4File_t,int> > *p_m_Data; // edi
  char szSearch[260]; // [esp+8h] [ebp-120h] BYREF
  char *argv2[4]; // [esp+10Ch] [ebp-1Ch] BYREF
  char *argv[3]; // [esp+11Ch] [ebp-Ch] BYREF

  p_m_Data = &this->m_Data;
  this->m_bAwaitingNewRecord = true;
  this->m_pData = &this->m_Data;
  this->m_Data.m_Size = 0;
  V_snprintf(pDest: szSearch, maxLen: 260, pFormat: "%s/*", dir);
  argv[0] = "-C";
  argv[1] = szSearch;
  argv[2] = nullptr;
  StrDict::SetArgv(this: &s_p4.m_Client, a2: 2, a3: argv);
  ClientApi::Run(this: &s_p4.m_Client, a2: "dirs", a3: this);
  argv2[2] = szSearch;
  argv2[0] = "-Rc";
  argv2[1] = "-Op";
  argv2[3] = nullptr;
  StrDict::SetArgv(this: &s_p4.m_Client, a2: 3, a3: argv2);
  ClientApi::Run(this: &s_p4.m_Client, a2: "fstat", a3: this);
  CFileUser::ComputeLocalDirectoryNames(this, fileList: p_m_Data);
}

//------------------------------------------------------------------------------
// Address: 0x100037C0
// Name: public: void CFileUser::RetrieveFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileUser::RetrieveFile(CFileUser *this, char *filespec)
{
  char *argv2[4]; // [esp+8h] [ebp-10h] BYREF

  this->m_bAwaitingNewRecord = true;
  this->m_pData = &this->m_Data;
  this->m_Data.m_Size = 0;
  argv2[2] = filespec;
  argv2[0] = "-Rc";
  argv2[1] = "-Op";
  argv2[3] = nullptr;
  StrDict::SetArgv(this: &s_p4.m_Client, a2: 3, a3: argv2);
  ClientApi::Run(this: &s_p4.m_Client, a2: "fstat", a3: this);
  CFileUser::ComputeLocalDirectoryNames(this, fileList: &this->m_Data);
}

//------------------------------------------------------------------------------
// Address: 0x10003820
// Name: public: void CUtlMemory<struct P4File_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<P4File_t,int>::Grow(CUtlMemory<P4File_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  P4File_t *m_pMemory; // edx
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
    v7 = 32 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (P4File_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (P4File_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100038B0
// Name: public: int CUtlVector<struct P4File_t,class CUtlMemory<struct P4File_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<P4File_t,CUtlMemory<P4File_t,int>>::InsertBefore(
        CUtlVector<P4File_t,CUtlMemory<P4File_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  P4File_t *m_pMemory; // ecx
  int v6; // eax
  P4File_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<P4File_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 32 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    *(_DWORD *)&v7->m_sName.m_Id = -1;
    *(_DWORD *)&v7->m_sDepotFile.m_Id = -1;
    v7->m_sLocalFile.m_Id = -1;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10003930
// Name: public: void CUtlMemory<struct P4Client_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<P4Client_t,int>::Grow(CUtlMemory<P4Client_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  P4Client_t *m_pMemory; // edx
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
        m_nAllocationCount = 4;
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
    v7 = 8 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (P4Client_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (P4Client_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100039D0
// Name: public: int CUtlVector<struct P4Client_t,class CUtlMemory<struct P4Client_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<P4Client_t,CUtlMemory<P4Client_t,int>>::InsertBefore(
        CUtlVector<P4Client_t,CUtlMemory<P4Client_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  P4Client_t *m_pMemory; // ecx
  int v6; // eax
  P4Client_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<P4Client_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 8 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    *(_DWORD *)&v7->m_sName.m_Id = -1;
    *(_DWORD *)&v7->m_sHost.m_Id = -1;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10003A40
// Name: public: void CUtlMemory<struct ChangelistDesc_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<ChangelistDesc_t,int>::Grow(CUtlMemory<ChangelistDesc_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  ChangelistDesc_t *m_pMemory; // edx
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
        m_nAllocationCount = 2;
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
    v7 = 24 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (ChangelistDesc_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (ChangelistDesc_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003AE0
// Name: public: int CUtlVector<struct ChangelistDesc_t,class CUtlMemory<struct ChangelistDesc_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<ChangelistDesc_t,CUtlMemory<ChangelistDesc_t,int>>::InsertBefore(
        CUtlVector<ChangelistDesc_t,CUtlMemory<ChangelistDesc_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  ChangelistDesc_t *m_pMemory; // ecx
  int v6; // eax
  ChangelistDesc_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<ChangelistDesc_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 24 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    *(_DWORD *)&v7->m_sUser.m_Id = -1;
    *(_DWORD *)&v7->m_sStatus.m_Id = -1;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10003B60
// Name: public: virtual CP4::~CP4(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CP4::~CP4(CP4 *this)
{
  Error v2; // [esp+8h] [ebp-Ch] BYREF

  this->__vftable = (CP4_vtbl *)&CP4::`vftable';
  if ( this->m_bConnectedToServer )
  {
    v2.ep = nullptr;
    v2.severity = E_EMPTY;
    ClientApi::Final(this: &this->m_Client, a2: &v2);
    this->m_bConnectedToServer = false;
    Error::~Error(this: &v2);
  }
  ClientUser::~ClientUser(this: &this->m_User);
  ClientApi::~ClientApi(this: &this->m_Client);
  this->m_sCachedChangeListNum.m_Storage.m_nActualLength = 0;
  if ( this->m_sCachedChangeListNum.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_sCachedChangeListNum.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_sCachedChangeListNum.m_Storage.m_Memory.m_pMemory);
      this->m_sCachedChangeListNum.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_sCachedChangeListNum.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->m_sChangeListName.m_Storage.m_nActualLength = 0;
  if ( this->m_sChangeListName.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_sChangeListName.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_sChangeListName.m_Storage.m_Memory.m_pMemory);
      this->m_sChangeListName.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_sChangeListName.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<CClientPathRecord,CUtlMemory<CClientPathRecord,int>>::~CUtlVector<CClientPathRecord,CUtlMemory<CClientPathRecord,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_ClientMapping);
}

//------------------------------------------------------------------------------
// Address: 0x10003C30
// Name: public: int CUtlVector<int,class CUtlMemory<int,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<int,CUtlMemory<int,int>>::AddToTail(CUtlVector<int,CUtlMemory<int,int> > *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  int *m_pMemory; // ecx
  int v5; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<int,int>::Grow(
      (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v5);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10003CB0
// Name: public: struct P4File_t __near & P4File_t::operator=(struct P4File_t const __near &)
// Source: json
//------------------------------------------------------------------------------
P4File_t *__thiscall P4File_t::operator=(P4File_t *this, const P4File_t *__that)
{
  *this = *__that;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10003D20
// Name: private: void CFileUser::OutputRecordInternal(struct P4File_t __near &,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileUser::OutputRecordInternal(CFileUser *this, P4File_t *file, const char *szCmd, const char *szInfo)
{
  const char *v4; // edi
  int v6; // eax
  int v7; // eax
  int v8; // eax
  const char *v9; // ebx
  int v10; // eax
  bool v11; // zf
  char *v12; // eax
  const char *v13; // esi
  P4File_t *v14; // edi
  P4File_t *v15; // edi
  char *v16; // eax
  char *v17; // eax
  char *v18; // eax
  char pLocalPath[260]; // [esp+8h] [ebp-20Ch] BYREF
  char pFilePath[260]; // [esp+10Ch] [ebp-108h] BYREF
  CFileUser *v21; // [esp+210h] [ebp-4h]

  v4 = szCmd;
  v21 = this;
  if ( _V_strcmp(s1: szCmd, s2: "headRev") != 0 )
  {
    if ( _V_strcmp(s1: v4, s2: "haveRev") != 0 )
    {
      v8 = _V_strcmp(s1: v4, s2: "headAction");
      v9 = szInfo;
      if ( v8 != 0 || _V_strcmp(s1: szInfo, s2: "delete") != 0 )
      {
        if ( _V_strcmp(s1: v4, s2: "action") != 0 )
        {
          if ( _V_strcmp(s1: v4, s2: "change") != 0 )
          {
            if ( _V_strcmp(s1: v4, s2: "otherOpen") != 0 )
            {
              if ( !this->m_bChangesRecord
                || _V_strcmp(s1: v4, s2: "user") != 0
                && _V_strcmp(s1: v4, s2: "client") != 0
                && _V_strcmp(s1: v4, s2: "time") != 0
                && _V_strcmp(s1: v4, s2: "desc") != 0
                && _V_strcmp(s1: v4, s2: "status") != 0
                && _V_strcmp(s1: v4, s2: "oldChange") != 0
                && _V_strcmp(s1: v4, s2: "type") != 0
                && _V_strcmp(s1: v4, s2: "rev") != 0 )
              {
                V_strncpy(pDest: pFilePath, pSrc: v9, maxLen: 260);
                v12 = _V_strrchr(s: pFilePath, c: 47);
                v13 = v12;
                if ( v12 != nullptr )
                  v13 = v12 + 1;
                if ( _V_stricmp(s1: v4, s2: "dir") != 0 )
                {
                  if ( _V_strcmp(s1: v4, s2: "depotFile") != 0 )
                  {
                    if ( _V_stricmp(s1: v4, s2: "clientFile") != 0 )
                    {
                      if ( _V_stricmp(s1: v4, s2: "path") == 0 )
                      {
                        v18 = _V_strstr(s1: pFilePath, search: "\\%%1");
                        if ( v18 != nullptr )
                          *v18 = 0;
                        CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&szInfo + 1, pStr: pFilePath);
                        file->m_sLocalFile.m_Id = HIWORD(szInfo);
                      }
                    }
                    else
                    {
                      v17 = _V_strstr(s1: pFilePath, search: "//%%1");
                      if ( v17 != nullptr )
                        *v17 = 0;
                      CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&szInfo + 1, pStr: pFilePath);
                      file->m_sClientFile.m_Id = HIWORD(szInfo);
                    }
                  }
                  else
                  {
                    v15 = file;
                    if ( v21->m_bChangesRecord
                      && CP4::DepotFileToLocalFile(this: &s_p4, pDepotFile: v9, pLocalPath, nBufLen: 260) )
                    {
                      CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&file + 1, pStr: pLocalPath);
                      v15->m_sLocalFile.m_Id = HIWORD(file);
                    }
                    v16 = _V_strstr(s1: pFilePath, search: "//%%1");
                    if ( v16 != nullptr )
                      *v16 = 0;
                    CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&file + 1, pStr: pFilePath);
                    v15->m_sDepotFile.m_Id = HIWORD(file);
                    if ( v13 != nullptr )
                      *((_BYTE *)v13 - 1) = 0;
                    CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&file + 1, pStr: pFilePath);
                    v15->m_sPath.m_Id = HIWORD(file);
                    CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&file + 1, pStr: v13);
                    v15->m_sName.m_Id = HIWORD(file);
                    v15->m_bDir = false;
                  }
                }
                else
                {
                  CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&szInfo + 1, pStr: pFilePath);
                  v14 = file;
                  file->m_sPath.m_Id = HIWORD(szInfo);
                  CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&file + 1, pStr: pFilePath);
                  v14->m_sDepotFile.m_Id = HIWORD(file);
                  CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&file + 1, pStr: v13);
                  v14->m_sName.m_Id = HIWORD(file);
                  v14->m_bDir = true;
                }
              }
            }
            else
            {
              v11 = atoi(nptr: v9) == 0;
              file->m_bOpenedByOther = !v11;
            }
          }
          else
          {
            v10 = atoi(nptr: v9);
            file->m_iChangelist = v10;
          }
        }
        else if ( _V_strcmp(s1: v9, s2: "edit") != 0 )
        {
          if ( _V_strcmp(s1: v9, s2: "delete") != 0 )
          {
            if ( _V_strcmp(s1: v9, s2: "add") != 0 )
            {
              if ( _V_strcmp(s1: v9, s2: "integrate") == 0 )
                file->m_eOpenState = P4FILE_OPENED_FOR_INTEGRATE;
            }
            else
            {
              file->m_eOpenState = P4FILE_OPENED_FOR_ADD;
            }
          }
          else
          {
            file->m_eOpenState = P4FILE_OPENED_FOR_DELETE;
          }
        }
        else
        {
          file->m_eOpenState = P4FILE_OPENED_FOR_EDIT;
        }
      }
      else
      {
        file->m_bDeleted = true;
      }
    }
    else
    {
      v7 = atoi(nptr: szInfo);
      file->m_iHaveRevision = v7;
    }
  }
  else
  {
    v6 = atoi(nptr: szInfo);
    file->m_iHeadRevision = v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004170
// Name: private: virtual void CClientSpecUser::OutputRecord(struct P4Client_t __near &,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientSpecUser::OutputRecord(
        CClientSpecUser *this,
        P4Client_t *client,
        const char *szCmd,
        const char *szInfo)
{
  if ( _V_strcmp(s1: szCmd, s2: "client") != 0 )
  {
    if ( _V_strcmp(s1: szCmd, s2: "Owner") != 0 )
    {
      if ( _V_strcmp(s1: szCmd, s2: "Root") != 0 )
      {
        if ( _V_strcmp(s1: szCmd, s2: "Host") != 0 )
        {
          _Msg(a1: "Unknown field %s = %s\n", szCmd, szInfo);
        }
        else
        {
          CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&szInfo + 1, pStr: szInfo);
          client->m_sHost.m_Id = HIWORD(szInfo);
        }
      }
      else
      {
        CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&szInfo + 1, pStr: szInfo);
        client->m_sLocalRoot.m_Id = HIWORD(szInfo);
      }
    }
    else
    {
      CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&szInfo + 1, pStr: szInfo);
      client->m_sUser.m_Id = HIWORD(szInfo);
    }
  }
  else
  {
    CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&szInfo + 1, pStr: szInfo);
    client->m_sName.m_Id = HIWORD(szInfo);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004250
// Name: public: void CClientspecMap::RemovePathFromClient(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientspecMap::RemovePathFromClient(CClientspecMap *this, char *path)
{
  int v2; // ebx
  CUtlVector<CClientPathRecord,CUtlMemory<CClientPathRecord,int> > *p_m_PathMap; // esi
  const char *m_szDepotPath; // edi
  int v5; // eax
  int v6; // edi
  int v7; // eax
  char *v8; // eax
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int v11; // edi
  CClientPathRecord *m_pMemory; // ecx
  int v13; // eax
  CClientPathRecord *v14; // edi
  CClientPathRecord negativeRecord; // [esp+4h] [ebp-214h] BYREF
  CClientspecMap *v16; // [esp+210h] [ebp-8h]
  unsigned int v17; // [esp+214h] [ebp-4h]
  char *pszNegPaths; // [esp+220h] [ebp+8h]

  v2 = 0;
  v16 = this;
  if ( this->m_PathMap.m_Size > 0 )
  {
    p_m_PathMap = &this->m_PathMap;
    v17 = 0;
    while ( 1 )
    {
      m_szDepotPath = p_m_PathMap->m_Memory.m_pMemory[v17 / 0x209].m_szDepotPath;
      v5 = _V_strlen(str: m_szDepotPath);
      if ( V_strnicmp(s1: m_szDepotPath, s2: path, n: v5 - 4) == 0 )
        break;
      v17 += 521;
      if ( ++v2 >= v16->m_PathMap.m_Size )
        return;
    }
    v6 = (int)p_m_PathMap->m_Memory.m_pMemory[v2].m_szDepotPath;
    negativeRecord.m_bNegative = true;
    V_snprintf(pDest: negativeRecord.m_szDepotPath, maxLen: 260, pFormat: "%s/...", path);
    v7 = 0;
    if ( *(_BYTE *)v6 == negativeRecord.m_szDepotPath[0] )
    {
      do
        ++v7;
      while ( negativeRecord.m_szDepotPath[v6 - (_DWORD)&negativeRecord + v7] == negativeRecord.m_szDepotPath[v7] );
    }
    pszNegPaths = &negativeRecord.m_szDepotPath[v7];
    V_strncpy(pDest: negativeRecord.m_szClientPath, pSrc: (const char *)(v6 + 260), maxLen: 260);
    v8 = _V_strstr(s1: negativeRecord.m_szClientPath, search: "/...");
    if ( v8 != nullptr )
      *v8 = 0;
    V_strncat(pDest: negativeRecord.m_szClientPath, pSrc: "/", destBufferSize: 0x104u, max_chars_to_copy: -1);
    V_strncat(pDest: negativeRecord.m_szClientPath, pSrc: pszNegPaths, destBufferSize: 0x104u, max_chars_to_copy: -1);
    m_Size = p_m_PathMap->m_Size;
    m_nAllocationCount = p_m_PathMap->m_Memory.m_nAllocationCount;
    v11 = v2 + 1;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CClientPathRecord,int>::Grow(this: &p_m_PathMap->m_Memory, num: m_Size - m_nAllocationCount + 1);
    ++p_m_PathMap->m_Size;
    m_pMemory = p_m_PathMap->m_Memory.m_pMemory;
    v13 = p_m_PathMap->m_Size - v11 - 1;
    p_m_PathMap->m_pElements = p_m_PathMap->m_Memory.m_pMemory;
    if ( v13 > 0 )
      _V_memmove(dest: &m_pMemory[v11 + 1], src: &m_pMemory[v11], count: 521 * v13);
    v14 = &p_m_PathMap->m_Memory.m_pMemory[v11];
    if ( v14 != nullptr )
      *v14 = negativeRecord;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100043F0
// Name: public: void CClientspecMap::AddVarToFullClientSpec(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientspecMap::AddVarToFullClientSpec(CClientspecMap *this, const char *variable, const char *data)
{
  V_snprintf(
    pDest: &this->m_szFullClientspec[this->m_iFullClientspecWritePosition],
    maxLen: 0x4000 - this->m_iFullClientspecWritePosition,
    pFormat: "%s: %s\n\n",
    variable,
    data);
  this->m_iFullClientspecWritePosition += strlen(&this->m_szFullClientspec[this->m_iFullClientspecWritePosition]);
}

//------------------------------------------------------------------------------
// Address: 0x10004450
// Name: public: void CClientspecMap::AddStringToFullClientSpec(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientspecMap::AddStringToFullClientSpec(CClientspecMap *this, const char *szString)
{
  V_strncpy(
    pDest: &this->m_szFullClientspec[this->m_iFullClientspecWritePosition],
    pSrc: szString,
    maxLen: 0x4000 - this->m_iFullClientspecWritePosition);
  this->m_iFullClientspecWritePosition += strlen(&this->m_szFullClientspec[this->m_iFullClientspecWritePosition]);
}

//------------------------------------------------------------------------------
// Address: 0x100044A0
// Name: private: virtual void CClientspecEditUser::OutputError(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientspecEditUser::OutputError(CClientspecEditUser *this, const char *errBuf)
{
  _Msg(a1: "s_p4 error: %s", errBuf);
}

//------------------------------------------------------------------------------
// Address: 0x100044C0
// Name: public: void CClientspecMap::WriteClientspec(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientspecMap::WriteClientspec(CClientspecMap *this, char *pszDest, int destSize)
{
  int v3; // ebx
  CClientPathRecord *v5; // esi
  char *v6; // eax
  char pDest[16384]; // [esp+8h] [ebp-4004h] BYREF
  unsigned int v8; // [esp+4008h] [ebp-4h]

  v3 = 0;
  memset(pDest, 0, sizeof(pDest));
  if ( this->m_PathMap.m_Size > 0 )
  {
    v8 = 0;
    do
    {
      v5 = &this->m_PathMap.m_Memory.m_pMemory[v8 / 0x209];
      V_strncat(pDest, pSrc: "     ", destBufferSize: 0x4000u, max_chars_to_copy: -1);
      if ( v5->m_bNegative )
        V_strncat(pDest, pSrc: "-", destBufferSize: 0x4000u, max_chars_to_copy: -1);
      V_strncat(pDest, pSrc: v5->m_szDepotPath, destBufferSize: 0x4000u, max_chars_to_copy: -1);
      V_strncat(pDest, pSrc: " ", destBufferSize: 0x4000u, max_chars_to_copy: -1);
      V_strncat(pDest, pSrc: v5->m_szClientPath, destBufferSize: 0x4000u, max_chars_to_copy: -1);
      V_strncat(pDest, pSrc: " \n", destBufferSize: 0x4000u, max_chars_to_copy: -1);
      v8 += 521;
      ++v3;
    }
    while ( v3 < this->m_PathMap.m_Size );
  }
  v6 = _V_strstr(s1: this->m_szFullClientspec, search: "\n\nView:\n");
  if ( v6 != nullptr )
    V_strncpy(pDest: v6 + 8, pSrc: pDest, maxLen: (char *)this - (v6 + 8) + 0x4000);
  V_strncpy(pDest: pszDest, pSrc: this->m_szFullClientspec, maxLen: destSize);
}

//------------------------------------------------------------------------------
// Address: 0x10004610
// Name: private: virtual void CClientspecEditUser::InputData(class StrBuf __near *,class Error __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientspecEditUser::InputData(CClientspecEditUser *this, StrBuf *strbuf, Error *e)
{
  char pszDest[16384]; // [esp+0h] [ebp-4000h] BYREF

  CClientspecMap::WriteClientspec(this: &this->m_Map, pszDest, destSize: 0x4000);
  strbuf->length = 0;
  StrBuf::Append(this: strbuf, src: pszDest);
  e->severity = E_EMPTY;
}

//------------------------------------------------------------------------------
// Address: 0x10004660
// Name: public: void CClientspecMap::ReadViewLine(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientspecMap::ReadViewLine(CClientspecMap *this, const char *viewLine)
{
  int v3; // eax
  CClientPathRecord record; // [esp+8h] [ebp-23Ch] BYREF
  CUtlBuffer parse; // [esp+214h] [ebp-30h] BYREF

  v3 = _V_strlen(str: viewLine);
  CUtlBuffer::CUtlBuffer(this: &parse, pBuffer: viewLine, nSize: v3, nFlags: 9);
  record.m_bNegative = false;
  CUtlBuffer::GetString(this: &parse, pString: record.m_szDepotPath, nMaxChars: 260);
  if ( _V_strlen(str: record.m_szDepotPath) >= 1 )
  {
    if ( _V_stricmp(s1: record.m_szDepotPath, s2: "-") == 0 )
    {
      CUtlBuffer::GetString(this: &parse, pString: record.m_szDepotPath, nMaxChars: 260);
      record.m_bNegative = true;
    }
    if ( record.m_szDepotPath[0] == 45 )
    {
      record.m_bNegative = true;
      memmove(dst: (unsigned __int8 *)&record, src: (unsigned __int8 *)&record.m_szDepotPath[1], count: 0x103u);
    }
    CUtlBuffer::GetString(this: &parse, pString: record.m_szClientPath, nMaxChars: 260);
    CUtlVector<CClientPathRecord,CUtlMemory<CClientPathRecord,int>>::InsertBefore(
      this: &this->m_PathMap,
      elem: this->m_PathMap.m_Size,
      src: &record);
    if ( parse.m_Memory.m_nGrowSize >= 0 && parse.m_Memory.m_pMemory != nullptr )
      goto LABEL_11;
  }
  else if ( parse.m_Memory.m_nGrowSize >= 0 && parse.m_Memory.m_pMemory != nullptr )
  {
LABEL_11:
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: parse.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004790
// Name: public: void CClientspecMap::ReadClientspec(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientspecMap::ReadClientspec(CClientspecMap *this, const char *clientspec)
{
  char *v3; // esi
  const char *v4; // esi
  int v5; // eax
  char *v6; // esi
  const char *v7; // esi
  int v8; // eax
  CClientspecMap *v9; // esi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CClientPathRecord *m_pMemory; // ecx
  int v13; // eax
  CClientPathRecord *v14; // edi
  CClientPathRecord record; // [esp+Ch] [ebp-240h] BYREF
  CUtlBuffer parse; // [esp+218h] [ebp-34h] BYREF
  CClientspecMap *v17; // [esp+248h] [ebp-4h]

  v17 = this;
  v3 = _V_strstr(s1: clientspec, search: "\n\nRoot:");
  if ( v3 != nullptr )
  {
    v4 = &v3[_V_strlen(str: "\n\nRoot:")];
    v5 = _V_strlen(str: v4);
    CUtlBuffer::CUtlBuffer(this: &parse, pBuffer: v4, nSize: v5, nFlags: 9);
    CUtlBuffer::GetString(this: &parse, pString: this->m_szLocalPath, nMaxChars: 260);
    if ( parse.m_Memory.m_nGrowSize >= 0 && parse.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: parse.m_Memory.m_pMemory);
  }
  v6 = _V_strstr(s1: clientspec, search: "\n\nView:\n");
  if ( v6 != nullptr )
  {
    v7 = &v6[_V_strlen(str: "\n\nView:\n")];
    V_strncpy(pDest: this->m_szFullClientspec, pSrc: clientspec, maxLen: 0x4000);
    v8 = _V_strlen(str: v7);
    CUtlBuffer::CUtlBuffer(this: &parse, pBuffer: v7, nSize: v8, nFlags: 9);
    while ( parse.m_Error == 0 )
    {
      record.m_bNegative = false;
      CUtlBuffer::GetString(this: &parse, pString: record.m_szDepotPath, nMaxChars: 260);
      if ( _V_strlen(str: record.m_szDepotPath) < 1 )
        break;
      if ( _V_stricmp(s1: record.m_szDepotPath, s2: "-") == 0 )
      {
        CUtlBuffer::GetString(this: &parse, pString: record.m_szDepotPath, nMaxChars: 260);
        record.m_bNegative = true;
      }
      if ( record.m_szDepotPath[0] == 45 )
      {
        record.m_bNegative = true;
        memmove(dst: (unsigned __int8 *)&record, src: (unsigned __int8 *)&record.m_szDepotPath[1], count: 0x103u);
      }
      CUtlBuffer::GetString(this: &parse, pString: record.m_szClientPath, nMaxChars: 260);
      v9 = v17;
      m_Size = v17->m_PathMap.m_Size;
      m_nAllocationCount = v17->m_PathMap.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CClientPathRecord,int>::Grow(this: &v17->m_PathMap.m_Memory, num: m_Size - m_nAllocationCount + 1);
      ++v9->m_PathMap.m_Size;
      m_pMemory = v9->m_PathMap.m_Memory.m_pMemory;
      v13 = v9->m_PathMap.m_Size - m_Size - 1;
      v9->m_PathMap.m_pElements = m_pMemory;
      if ( v13 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 521 * v13);
      v14 = &v9->m_PathMap.m_Memory.m_pMemory[m_Size];
      if ( v14 != nullptr )
        *v14 = record;
    }
    if ( parse.m_Memory.m_nGrowSize >= 0 && parse.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: parse.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100049C0
// Name: private: virtual void CClientspecEditUser::OutputInfo(char,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientspecEditUser::OutputInfo(CClientspecEditUser *this, char level, char *data)
{
  char *v4; // eax
  CClientspecMap *p_m_Map; // esi
  char clientspec[16384]; // [esp+8h] [ebp-8000h] BYREF
  char pDest[16384]; // [esp+4008h] [ebp-4000h] BYREF

  V_strncpy(pDest, pSrc: data, maxLen: 0x4000);
  v4 = _V_strstr(s1: pDest, search: " ");
  if ( v4 != nullptr )
  {
    *v4 = 0;
    V_strncpy(pDest: clientspec, pSrc: &data[v4 - pDest + 1], maxLen: 0x4000);
  }
  else
  {
    clientspec[0] = 0;
  }
  if ( pDest[0] != 0 )
  {
    if ( _V_stricmp(s1: pDest, s2: "data") != 0 )
    {
      if ( !this->m_bReadDataVar )
      {
        if ( _V_stricmp(s1: pDest, s2: "root") != 0 )
        {
          if ( V_strnicmp(s1: pDest, s2: "view", n: 4) != 0 )
          {
            CClientspecMap::AddVarToFullClientSpec(this: &this->m_Map, variable: pDest, data: clientspec);
          }
          else
          {
            if ( _V_stricmp(s1: pDest, s2: "view") == 0 || _V_stricmp(s1: pDest, s2: "view0") == 0 )
              CClientspecMap::AddStringToFullClientSpec(this: &this->m_Map, szString: "View:\n");
            p_m_Map = &this->m_Map;
            CClientspecMap::ReadViewLine(this: p_m_Map, viewLine: clientspec);
            CClientspecMap::AddStringToFullClientSpec(this: p_m_Map, szString: "\t");
            CClientspecMap::AddStringToFullClientSpec(this: p_m_Map, szString: clientspec);
            CClientspecMap::AddStringToFullClientSpec(this: p_m_Map, szString: "\n");
          }
        }
        else
        {
          V_strncpy(pDest: this->m_Map.m_szLocalPath, pSrc: clientspec, maxLen: 260);
          CClientspecMap::AddVarToFullClientSpec(this: &this->m_Map, variable: pDest, data: clientspec);
        }
      }
    }
    else
    {
      this->m_bReadDataVar = true;
      CClientspecMap::ReadClientspec(this: &this->m_Map, clientspec);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004BB0
// Name: private: virtual void CChangelistCreateUser::OutputRecord(int __near &,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChangelistCreateUser::OutputRecord(
        CChangelistCreateUser *this,
        int *nChangelist,
        const char *szCmd,
        const char *szInfo)
{
  if ( _V_strcmp(s1: szCmd, s2: "Change") == 0 )
    *nChangelist = atoi(nptr: szInfo);
}

//------------------------------------------------------------------------------
// Address: 0x10004BE0
// Name: private: virtual void CChangelistCreateUser::InputData(class StrBuf __near *,class Error __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChangelistCreateUser::InputData(CChangelistCreateUser *this, StrBuf *strbuf, Error *e)
{
  const char *v3; // eax
  const char *v4; // [esp-8h] [ebp-4808h]
  const char *m_pDescription; // [esp-4h] [ebp-4804h]
  char pDest[18432]; // [esp+0h] [ebp-4800h] BYREF

  m_pDescription = this->m_pDescription;
  v4 = CUtlSymbol::String(this: &s_p4.m_ActiveClient.m_sUser);
  v3 = CUtlSymbol::String(this: &s_p4.m_ActiveClient.m_sName);
  V_snprintf(
    pDest,
    maxLen: 18432,
    pFormat: "Change:\tnew\n\nClient:\t%s\n\nUser:\t%s\n\nStatus:\tnew\n\nDescription:\n\t%s\n\nFiles:\n\n",
    v3,
    v4,
    m_pDescription);
  strbuf->length = 0;
  StrBuf::Append(this: strbuf, src: pDest);
  e->severity = E_EMPTY;
}

//------------------------------------------------------------------------------
// Address: 0x10004C80
// Name: public: CUtlVector<struct CClientPathRecord,class CUtlMemory<struct CClientPathRecord,int>>::~CUtlVector<struct CClientPathRecord,class CUtlMemory<struct CClientPathRecord,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CClientPathRecord,CUtlMemory<CClientPathRecord,int>>::~CUtlVector<CClientPathRecord,CUtlMemory<CClientPathRecord,int>>(
        CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *this)
{
  bool v2; // sf
  CUtlSymbolTable::StringPool_t **m_pMemory; // eax

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
// Address: 0x10004CF0
// Name: public: void CUtlVector<char,class CUtlMemory<char,int>>::SetCount(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<char,CUtlMemory<char,int>>::SetCount(
        CUtlVector<char,CUtlMemory<char,int> > *this,
        int count)
{
  int m_nAllocationCount; // eax
  char *m_pMemory; // ecx
  int v5; // eax

  this->m_Size = 0;
  if ( count != 0 )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    if ( count > m_nAllocationCount )
      CUtlMemory<char,int>::Grow((CUtlMemory<unsigned char,int> *)this, num: count - m_nAllocationCount);
    this->m_Size += count;
    m_pMemory = this->m_Memory.m_pMemory;
    v5 = this->m_Size - count;
    this->m_pElements = this->m_Memory.m_pMemory;
    if ( v5 > 0 && count > 0 )
      _V_memmove(dest: &m_pMemory[count], src: m_pMemory, count: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004D40
// Name: private: virtual void CChangelistFindUser::OutputRecord(struct ChangelistDesc_t __near &,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChangelistFindUser::OutputRecord(
        CChangelistFindUser *this,
        ChangelistDesc_t *cl,
        const char *szCmd,
        const char *szInfo)
{
  const char *v4; // edi
  int m_Size; // esi
  char *m_pMemory; // edi
  int i; // esi
  int v8; // eax
  unsigned __int8 *v9; // [esp-10h] [ebp-28h]
  CUtlVector<char,CUtlMemory<char,int> > arrInfo; // [esp+4h] [ebp-14h] BYREF

  if ( _V_strcmp(s1: szCmd, s2: "change") != 0 )
  {
    if ( _V_strcmp(s1: szCmd, s2: "time") != 0 )
    {
      if ( _V_strcmp(s1: szCmd, s2: "user") != 0 )
      {
        if ( _V_strcmp(s1: szCmd, s2: "client") != 0 )
        {
          if ( _V_strcmp(s1: szCmd, s2: "status") != 0 )
          {
            if ( _V_strcmp(s1: szCmd, s2: "desc") == 0 )
            {
              v4 = szInfo;
              memset(&arrInfo, 0, sizeof(arrInfo));
              CUtlVector<char,CUtlMemory<char,int>>::SetCount(this: &arrInfo, count: strlen(szInfo) + 1);
              m_Size = arrInfo.m_Size;
              v9 = (unsigned __int8 *)v4;
              m_pMemory = arrInfo.m_Memory.m_pMemory;
              memcpy(dst: (unsigned __int8 *)arrInfo.m_Memory.m_pMemory, src: v9, count: arrInfo.m_Size);
              for ( i = m_Size - 1; i > 0; m_pMemory[i] = 0 )
              {
                v8 = m_pMemory[--i];
                if ( isspace(c: v8) == 0 )
                  break;
              }
              CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&szInfo + 1, pStr: m_pMemory);
              cl->m_sDescription.m_Id = HIWORD(szInfo);
              CUtlVector<CClientPathRecord,CUtlMemory<CClientPathRecord,int>>::~CUtlVector<CClientPathRecord,CUtlMemory<CClientPathRecord,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&arrInfo);
            }
          }
          else
          {
            CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&szInfo + 1, pStr: szInfo);
            cl->m_sStatus.m_Id = HIWORD(szInfo);
          }
        }
        else
        {
          CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&szInfo + 1, pStr: szInfo);
          cl->m_sClient.m_Id = HIWORD(szInfo);
        }
      }
      else
      {
        CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&szInfo + 1, pStr: szInfo);
        cl->m_sUser.m_Id = HIWORD(szInfo);
      }
    }
    else
    {
      cl->m_tTimeStamp = atoi(nptr: szInfo);
    }
  }
  else
  {
    cl->id = atoi(nptr: szInfo);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004ED0
// Name: public: virtual class CUtlVector<struct P4Client_t,class CUtlMemory<struct P4Client_t,int>> __near & CP4::GetClientList(void)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<P4Client_t,CUtlMemory<P4Client_t,int> > *__thiscall CP4::GetClientList(CP4 *this)
{
  if ( this->IsConnectedToServer(this, a2: true) )
  {
    g_ClientspecUser.m_bAwaitingNewRecord = true;
    g_ClientspecUser.m_pData = &g_ClientspecUser.m_Data;
    g_ClientspecUser.m_Data.m_Size = 0;
    ClientApi::Run(this: &s_p4.m_Client, a2: "clients", a3: &g_ClientspecUser);
    return &g_ClientspecUser.m_Data;
  }
  else
  {
    if ( (_S4 & 1) == 0 )
    {
      _S4 |= 1u;
      dummy.m_Memory.m_pMemory = nullptr;
      dummy.m_Memory.m_nAllocationCount = 0;
      dummy.m_Memory.m_nGrowSize = 0;
      dummy.m_Size = 0;
      dummy.m_pElements = nullptr;
      atexit(func: CP4::GetClientList_::_5_::_dynamic_atexit_destructor_for__dummy__);
    }
    return &dummy;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004F60
// Name: public: virtual void CP4::RemovePathFromActiveClientspec(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CP4::RemovePathFromActiveClientspec(CP4 *this, char *path)
{
  P4Client_t *(__thiscall *GetActiveClient)(IP4 *); // edx
  CUtlSymbol *v4; // eax
  ClientUser v5; // [esp+4h] [ebp-4140h] BYREF
  CClientspecMap v6; // [esp+18h] [ebp-412Ch] BYREF
  char v7; // [esp+4134h] [ebp-10h]
  char *v8; // [esp+4138h] [ebp-Ch] BYREF
  const char *v9; // [esp+413Ch] [ebp-8h]
  int v10; // [esp+4140h] [ebp-4h]

  if ( this->IsConnectedToServer(this, a2: true) )
  {
    GetActiveClient = this->GetActiveClient;
    v5.binaryStdout = 0;
    v5.outputCharset = 0;
    v5.__vftable = (ClientUser_vtbl *)&CClientspecEditUser::`vftable';
    v7 = 0;
    v4 = (CUtlSymbol *)GetActiveClient(this);
    v9 = CUtlSymbol::String(this: v4);
    v6.m_szFullClientspec[0] = 0;
    memset(&v6.m_iFullClientspecWritePosition, 0, 25);
    v8 = "-o";
    v10 = 0;
    StrDict::SetArgv(this: &s_p4.m_Client, a2: 2, a3: &v8);
    ClientApi::Run(this: &s_p4.m_Client, a2: "client", a3: &v5);
    CClientspecMap::RemovePathFromClient(this: &v6, path);
    v8 = "-i";
    v9 = nullptr;
    v10 = 0;
    StrDict::SetArgv(this: &s_p4.m_Client, a2: 1, a3: &v8);
    ClientApi::Run(this: &s_p4.m_Client, a2: "client", a3: &v5);
    CUtlVector<CClientPathRecord,CUtlMemory<CClientPathRecord,int>>::~CUtlVector<CClientPathRecord,CUtlMemory<CClientPathRecord,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&v6.m_PathMap);
    ClientUser::~ClientUser(this: &v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005080
// Name: public: struct P4File_t __near * CDataRetrievalUser<struct P4File_t>::ForceNextRecord(void)
// Source: json
//------------------------------------------------------------------------------
P4File_t *__thiscall CDataRetrievalUser<P4File_t>::ForceNextRecord(CDataRetrievalUser<P4File_t> *this)
{
  int v2; // eax
  CUtlVector<P4File_t,CUtlMemory<P4File_t,int> > *m_pData; // ecx
  int v4; // edi

  v2 = CUtlVector<P4File_t,CUtlMemory<P4File_t,int>>::InsertBefore(this: this->m_pData, elem: this->m_pData->m_Size);
  m_pData = this->m_pData;
  v4 = v2;
  if ( m_pData->m_Size > 1 )
    P4File_t::operator=(this: &m_pData->m_Memory.m_pMemory[v2], __that: m_pData->m_Memory.m_pMemory);
  return &this->m_pData->m_Memory.m_pMemory[v4];
}

//------------------------------------------------------------------------------
// Address: 0x100050C0
// Name: private: virtual void CDataRetrievalUser<struct P4File_t>::OutputInfo(char,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataRetrievalUser<P4File_t>::OutputInfo(
        CDataRetrievalUser<P4File_t> *this,
        char level,
        const char *data)
{
  int v4; // eax
  CUtlVector<P4File_t,CUtlMemory<P4File_t,int> > *m_pData; // ecx
  bool v6; // zf
  char *v7; // eax
  char *v8; // eax
  char szInfo[260]; // [esp+8h] [ebp-208h] BYREF
  char szVar[260]; // [esp+10Ch] [ebp-104h] BYREF

  if ( _V_strlen(str: data) >= 1 )
  {
    if ( this->m_bAwaitingNewRecord )
    {
      v4 = CUtlVector<P4File_t,CUtlMemory<P4File_t,int>>::InsertBefore(this: this->m_pData, elem: this->m_pData->m_Size);
      m_pData = this->m_pData;
      v4 *= 32;
      v6 = (P4File_t *)((char *)m_pData->m_Memory.m_pMemory + v4) == nullptr;
      v7 = (char *)m_pData->m_Memory.m_pMemory + v4;
      *(_QWORD *)v7 = 0;
      *((_QWORD *)v7 + 1) = 0;
      *((_QWORD *)v7 + 2) = 0;
      *((_QWORD *)v7 + 3) = 0;
      if ( !v6 )
      {
        *(_DWORD *)v7 = -1;
        *((_DWORD *)v7 + 1) = -1;
        *((_WORD *)v7 + 4) = -1;
      }
      this->m_bAwaitingNewRecord = false;
    }
    V_strncpy(pDest: szVar, pSrc: data, maxLen: 260);
    v8 = _V_strstr(s1: szVar, search: " ");
    if ( v8 != nullptr )
    {
      *v8 = 0;
      V_strncpy(pDest: szInfo, pSrc: &data[v8 - szVar + 1], maxLen: 260);
    }
    else
    {
      szInfo[0] = 0;
    }
    this->OutputRecord(this, a2: &this->m_pData->m_Memory.m_pMemory[this->m_pData->m_Size - 1], a3: szVar, a4: szInfo);
  }
  else
  {
    this->m_bAwaitingNewRecord = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100051C0
// Name: private: virtual void CDataRetrievalUser<struct P4Client_t>::OutputInfo(char,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataRetrievalUser<P4Client_t>::OutputInfo(
        CDataRetrievalUser<P4Client_t> *this,
        char level,
        const char *data)
{
  P4Client_t *v4; // eax
  char *v5; // eax
  char szInfo[260]; // [esp+8h] [ebp-208h] BYREF
  char szVar[260]; // [esp+10Ch] [ebp-104h] BYREF

  if ( _V_strlen(str: data) >= 1 )
  {
    if ( this->m_bAwaitingNewRecord )
    {
      v4 = &this->m_pData->m_Memory.m_pMemory[CUtlVector<P4Client_t,CUtlMemory<P4Client_t,int>>::InsertBefore(
                                                this: this->m_pData,
                                                elem: this->m_pData->m_Size)];
      *v4 = 0;
      if ( v4 != nullptr )
      {
        *(_DWORD *)&v4->m_sName.m_Id = -1;
        *(_DWORD *)&v4->m_sHost.m_Id = -1;
      }
      this->m_bAwaitingNewRecord = false;
    }
    V_strncpy(pDest: szVar, pSrc: data, maxLen: 260);
    v5 = _V_strstr(s1: szVar, search: " ");
    if ( v5 != nullptr )
    {
      *v5 = 0;
      V_strncpy(pDest: szInfo, pSrc: &data[v5 - szVar + 1], maxLen: 260);
    }
    else
    {
      szInfo[0] = 0;
    }
    this->OutputRecord(this, a2: &this->m_pData->m_Memory.m_pMemory[this->m_pData->m_Size - 1], a3: szVar, a4: szInfo);
  }
  else
  {
    this->m_bAwaitingNewRecord = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100052B0
// Name: private: virtual void CDataRetrievalUser<int>::OutputInfo(char,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataRetrievalUser<int>::OutputInfo(CDataRetrievalUser<int> *this, char level, const char *data)
{
  char *v4; // eax
  char szInfo[260]; // [esp+8h] [ebp-208h] BYREF
  char szVar[260]; // [esp+10Ch] [ebp-104h] BYREF

  if ( _V_strlen(str: data) >= 1 )
  {
    if ( this->m_bAwaitingNewRecord )
    {
      this->m_pData->m_Memory.m_pMemory[CUtlVector<int,CUtlMemory<int,int>>::AddToTail(this: this->m_pData)] = 0;
      this->m_bAwaitingNewRecord = false;
    }
    V_strncpy(pDest: szVar, pSrc: data, maxLen: 260);
    v4 = _V_strstr(s1: szVar, search: " ");
    if ( v4 != nullptr )
    {
      *v4 = 0;
      V_strncpy(pDest: szInfo, pSrc: &data[v4 - szVar + 1], maxLen: 260);
    }
    else
    {
      szInfo[0] = 0;
    }
    this->OutputRecord(this, a2: &this->m_pData->m_Memory.m_pMemory[this->m_pData->m_Size - 1], a3: szVar, a4: szInfo);
  }
  else
  {
    this->m_bAwaitingNewRecord = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005380
// Name: private: virtual void CDataRetrievalUser<struct ChangelistDesc_t>::OutputInfo(char,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataRetrievalUser<ChangelistDesc_t>::OutputInfo(
        CDataRetrievalUser<ChangelistDesc_t> *this,
        char level,
        const char *data)
{
  ChangelistDesc_t *v4; // eax
  char *v5; // eax
  char szInfo[260]; // [esp+8h] [ebp-208h] BYREF
  char szVar[260]; // [esp+10Ch] [ebp-104h] BYREF

  if ( _V_strlen(str: data) >= 1 )
  {
    if ( this->m_bAwaitingNewRecord )
    {
      v4 = &this->m_pData->m_Memory.m_pMemory[CUtlVector<ChangelistDesc_t,CUtlMemory<ChangelistDesc_t,int>>::InsertBefore(
                                                this: this->m_pData,
                                                elem: this->m_pData->m_Size)];
      *(_QWORD *)&v4->id = 0;
      v4->m_tTimeStamp = 0;
      *(_QWORD *)&v4->m_sUser.m_Id = 0;
      if ( v4 != nullptr )
      {
        *(_DWORD *)&v4->m_sUser.m_Id = -1;
        *(_DWORD *)&v4->m_sStatus.m_Id = -1;
      }
      this->m_bAwaitingNewRecord = false;
    }
    V_strncpy(pDest: szVar, pSrc: data, maxLen: 260);
    v5 = _V_strstr(s1: szVar, search: " ");
    if ( v5 != nullptr )
    {
      *v5 = 0;
      V_strncpy(pDest: szInfo, pSrc: &data[v5 - szVar + 1], maxLen: 260);
    }
    else
    {
      szInfo[0] = 0;
    }
    this->OutputRecord(this, a2: &this->m_pData->m_Memory.m_pMemory[this->m_pData->m_Size - 1], a3: szVar, a4: szInfo);
  }
  else
  {
    this->m_bAwaitingNewRecord = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005480
// Name: private: virtual void CFileUser::OutputRecord(struct P4File_t __near &,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileUser::OutputRecord(CFileUser *this, P4File_t *file, char *szCmd, const char *szInfo)
{
  bool v4; // zf
  char *v5; // edi
  unsigned int v6; // eax
  char *v7; // esi
  int v8; // edx
  int v9; // ebx
  int v10; // esi
  CDataRetrievalUser<P4File_t> *v11; // ecx
  CDataRetrievalUser<P4File_t> *v12; // ebx
  char tmpCmd[1024]; // [esp+Ch] [ebp-404h] BYREF
  CDataRetrievalUser<P4File_t> *v14; // [esp+40Ch] [ebp-4h]
  int end; // [esp+41Ch] [ebp+Ch]

  v4 = !this->m_bChangesRecord;
  v5 = szCmd;
  v14 = this;
  if ( !v4 )
  {
    v6 = _V_strlen(str: szCmd) - 1;
    end = v6;
    if ( v6 < 0x400 )
    {
      v7 = &v5[v6];
      if ( isdigit(c: v5[v6]) != 0 )
      {
        do
        {
          if ( v7 <= v5 )
            break;
          v8 = *--v7;
        }
        while ( isdigit(c: v8) != 0 );
      }
      v9 = v7 - v5;
      if ( v7 - v5 > 0 && v9 < end )
      {
        v10 = atoi(nptr: v7 + 1);
        V_strncpy(pDest: tmpCmd, pSrc: v5, maxLen: 1024);
        v11 = v14;
        tmpCmd[v9 + 1] = 0;
        v5 = tmpCmd;
        if ( (CDataRetrievalUser<P4File_t>_vtbl *)v10 != v11[1].__vftable )
        {
          v12 = v11;
          file = CDataRetrievalUser<P4File_t>::ForceNextRecord(this: v11);
          v12[1].__vftable = (CDataRetrievalUser<P4File_t>_vtbl *)v10;
        }
      }
    }
  }
  CFileUser::OutputRecordInternal(this: (CFileUser *)v14, file, szCmd: v5, szInfo);
}

//------------------------------------------------------------------------------
// Address: 0x10005550
// Name: public: class CUtlVector<struct CClientPathRecord,class CUtlMemory<struct CClientPathRecord,int>> __near & CUtlVector<struct CClientPathRecord,class CUtlMemory<struct CClientPathRecord,int>>::operator=(class CUtlVector<struct CClientPathRecord,class CUtlMemory<struct CClientPathRecord,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<CClientPathRecord,CUtlMemory<CClientPathRecord,int> > *__thiscall CUtlVector<CClientPathRecord,CUtlMemory<CClientPathRecord,int>>::operator=(
        CUtlVector<CClientPathRecord,CUtlMemory<CClientPathRecord,int> > *this,
        const CUtlVector<CClientPathRecord,CUtlMemory<CClientPathRecord,int> > *other)
{
  int m_Size; // esi
  int v4; // eax
  int i; // edx
  CClientPathRecord *v6; // esi
  CClientPathRecord *v7; // edi

  m_Size = other->m_Size;
  this->m_Size = 0;
  CUtlVector<CClientPathRecord,CUtlMemory<CClientPathRecord,int>>::InsertMultipleBefore(this, elem: 0, num: m_Size);
  if ( m_Size > 0 )
  {
    v4 = 0;
    for ( i = m_Size; i != 0; --i )
    {
      v6 = &other->m_Memory.m_pMemory[v4];
      v7 = &this->m_Memory.m_pMemory[v4];
      qmemcpy(v7, v6, 0x208u);
      ++v4;
      v7->m_bNegative = v6->m_bNegative;
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100055A0
// Name: public: void CUtlVector<struct P4Revision_t,class CUtlMemory<struct P4Revision_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<P4Revision_t,CUtlMemory<P4Revision_t,int>>::RemoveAll(
        CUtlVector<P4Revision_t,CUtlMemory<P4Revision_t,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  P4Revision_t *v3; // esi
  CUtlVector<P4Revision_t,CUtlMemory<P4Revision_t,int> > *v4; // [esp+4h] [ebp-4h]

  v1 = this->m_Size - 1;
  v4 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = v1;
    do
    {
      v3 = &this->m_Memory.m_pMemory[v2];
      v3->m_Description.m_Storage.m_nActualLength = 0;
      if ( v3->m_Description.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Description.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Description.m_Storage.m_Memory.m_pMemory);
          this = v4;
          v3->m_Description.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Description.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      --v1;
      --v2;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005610
// Name: private: void CP4::RefreshClientData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CP4::RefreshClientData(CP4 *this)
{
  P4Client_t *(__thiscall *GetActiveClient)(IP4 *); // eax
  CUtlSymbol *v3; // eax
  const char *v4; // eax
  ClientUser v5; // [esp+8h] [ebp-4140h] BYREF
  CClientspecMap v6; // [esp+1Ch] [ebp-412Ch] BYREF
  char v7; // [esp+4138h] [ebp-10h]
  char *v8[3]; // [esp+413Ch] [ebp-Ch] BYREF

  if ( this->m_bConnectedToServer )
  {
    g_InfoUser.m_Client = 0;
    ClientApi::Run(this: &s_p4.m_Client, a2: "info", a3: &g_InfoUser);
    this->m_ActiveClient = g_InfoUser.m_Client;
    GetActiveClient = this->GetActiveClient;
    v5.binaryStdout = 0;
    v5.outputCharset = 0;
    v5.__vftable = (ClientUser_vtbl *)&CClientspecEditUser::`vftable';
    v7 = 0;
    v3 = (CUtlSymbol *)GetActiveClient(this);
    v6.m_szFullClientspec[0] = 0;
    memset(&v6.m_iFullClientspecWritePosition, 0, 25);
    v8[0] = "-o";
    v8[1] = (char *)CUtlSymbol::String(this: v3);
    v8[2] = nullptr;
    StrDict::SetArgv(this: &s_p4.m_Client, a2: 2, a3: v8);
    ClientApi::Run(this: &s_p4.m_Client, a2: "client", a3: &v5);
    CClientspecMap::GetCommonDepotRoot(this: &v6, pszDest: this->m_szDepotRoot, destSize: 260);
    this->m_iDepotRootLength = _V_strlen(str: this->m_szDepotRoot);
    CUtlVector<CClientPathRecord,CUtlMemory<CClientPathRecord,int>>::operator=(
      this: &this->m_ClientMapping,
      other: &v6.m_PathMap);
    V_strncpy(pDest: this->m_szLocalRoot, pSrc: v6.m_szLocalPath, maxLen: 260);
    this->m_iLocalRootLength = _V_strlen(str: this->m_szLocalRoot);
    v4 = CUtlString::Get(this: &this->m_sChangeListName);
    this->SetOpenFileChangeList(this, a2: v4);
    CUtlVector<CClientPathRecord,CUtlMemory<CClientPathRecord,int>>::~CUtlVector<CClientPathRecord,CUtlMemory<CClientPathRecord,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&v6.m_PathMap);
    ClientUser::~ClientUser(this: &v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100057A0
// Name: public: virtual void CP4::RefreshActiveClient(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CP4::RefreshActiveClient(CP4 *this)
{
  if ( this->IsConnectedToServer(this, a2: true) )
    CP4::RefreshClientData(this);
}

//------------------------------------------------------------------------------
// Address: 0x100057C0
// Name: public: virtual void CP4::SetActiveClient(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CP4::SetActiveClient(CP4 *this, const char *clientname)
{
  if ( this->IsConnectedToServer(this, a2: true) )
  {
    ClientApi::SetClient(this: &this->m_Client, a2: clientname);
    CP4::RefreshClientData(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005800
// Name: private: bool CP4::PerformPerforceOp(void (*)(int,char const __near * __near *,char const __near *),int,char const __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4::PerformPerforceOp(
        CP4 *this,
        void (__cdecl *op)(int, const char **, const char *),
        int nCount,
        const char **ppFullPathList,
        const char *pDescription)
{
  int v5; // edi
  const struct StrPtr *Client; // eax
  int v10; // esi
  char pDest[260]; // [esp+8h] [ebp-410h] BYREF
  char pClientSpec[260]; // [esp+10Ch] [ebp-30Ch] BYREF
  char pOldClientSpec[260]; // [esp+210h] [ebp-208h] BYREF
  char pCurrentClientSpec[260]; // [esp+314h] [ebp-104h] BYREF
  char bChangeSpec_3; // [esp+427h] [ebp+Fh]

  v5 = 0;
  g_ErrorHandlerUser.m_errorSeverity = E_EMPTY;
  g_ErrorHandlerUser.m_errorBuf.length = 0;
  if ( this->IsConnectedToServer(this, a2: true) )
  {
    if ( nCount != 0 )
    {
      Client = ClientApi::GetClient(this: &this->m_Client);
      V_strncpy(pDest: pOldClientSpec, pSrc: Client->buffer, maxLen: 260);
      V_strncpy(pDest: pCurrentClientSpec, pSrc: pOldClientSpec, maxLen: 260);
      if ( nCount > 0 )
      {
        do
        {
          bChangeSpec_3 = 0;
          v10 = v5;
          if ( v5 >= nCount )
            break;
          while ( 1 )
          {
            V_strncpy(pDest, pSrc: ppFullPathList[v10], maxLen: 260);
            V_StripFilename(path: pDest);
            if ( s_p4.GetClientSpecForDirectory(this: &s_p4, a2: pDest, a3: pClientSpec, a4: 260)
              && _V_stricmp(s1: pCurrentClientSpec, s2: pClientSpec) != 0 )
            {
              break;
            }
            if ( ++v10 >= nCount )
              goto LABEL_12;
          }
          bChangeSpec_3 = 1;
LABEL_12:
          if ( v10 != v5 )
          {
            op(a1: v10 - v5, a2: &ppFullPathList[v5], a3: pDescription);
            v5 = v10;
          }
          if ( bChangeSpec_3 != 0 )
          {
            if ( s_p4.IsConnectedToServer(this: &s_p4, a2: true) )
            {
              ClientApi::SetClient(this: &s_p4.m_Client, a2: pClientSpec);
              CP4::RefreshClientData(this: &s_p4);
            }
            V_strncpy(pDest: pCurrentClientSpec, pSrc: pClientSpec, maxLen: 260);
          }
        }
        while ( v5 < nCount );
      }
      if ( _V_stricmp(s1: pCurrentClientSpec, s2: pOldClientSpec) != 0
        && s_p4.IsConnectedToServer(this: &s_p4, a2: true) )
      {
        ClientApi::SetClient(this: &s_p4.m_Client, a2: pOldClientSpec);
        CP4::RefreshClientData(this: &s_p4);
      }
      return g_ErrorHandlerUser.m_errorSeverity < E_WARN;
    }
    else
    {
      return true;
    }
  }
  else
  {
    g_ErrorHandlerUser.m_errorBuf.length = 0;
    StrBuf::Append(this: &g_ErrorHandlerUser.m_errorBuf, src: "Not connected to P4 server\n");
    g_ErrorHandlerUser.m_errorSeverity = E_FATAL;
    return false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005A20
// Name: public: virtual bool CP4::RevertFiles(int,char const __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4::RevertFiles(CP4 *this, int nCount, const char **ppFullPathList)
{
  s_pOperation = "revert";
  return CP4::PerformPerforceOp(
           this,
           op: (void (__cdecl *)(int, const char **, const char *))SimplePerforceOp,
           nCount,
           ppFullPathList,
           pDescription: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10005A50
// Name: public: virtual bool CP4::SubmitFiles(int,char const __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4::SubmitFiles(CP4 *this, int nCount, const char **ppFullPathList, const char *pDescription)
{
  return CP4::PerformPerforceOp(this, op: SubmitPerforceOp, nCount, ppFullPathList, pDescription);
}

//------------------------------------------------------------------------------
// Address: 0x10005A70
// Name: public: CUtlVector<struct P4Revision_t,class CUtlMemory<struct P4Revision_t,int>>::~CUtlVector<struct P4Revision_t,class CUtlMemory<struct P4Revision_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<P4Revision_t,CUtlMemory<P4Revision_t,int>>::~CUtlVector<P4Revision_t,CUtlMemory<P4Revision_t,int>>(
        CUtlVector<P4Revision_t,CUtlMemory<P4Revision_t,int> > *this)
{
  bool v2; // sf
  P4Revision_t *m_pMemory; // eax

  CUtlVector<P4Revision_t,CUtlMemory<P4Revision_t,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
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
// Address: 0x10005AD0
// Name: public: CScopedClientSpec::CScopedClientSpec(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CScopedClientSpec *__thiscall CScopedClientSpec::CScopedClientSpec(CScopedClientSpec *this, const char *pClientSpec)
{
  const struct StrPtr *Client; // eax

  this->m_bClientSpecNeedsRestore = false;
  Client = ClientApi::GetClient(this: &s_p4.m_Client);
  V_strncpy(pDest: this->m_pOldClientSpec, pSrc: Client->buffer, maxLen: 260);
  if ( _V_stricmp(s1: this->m_pOldClientSpec, s2: pClientSpec) != 0 )
  {
    if ( s_p4.IsConnectedToServer(this: &s_p4, a2: true) )
    {
      ClientApi::SetClient(this: &s_p4.m_Client, a2: pClientSpec);
      CP4::RefreshClientData(this: &s_p4);
    }
    this->m_bClientSpecNeedsRestore = true;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10005B50
// Name: public: CScopedFileClientSpec::CScopedFileClientSpec(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CScopedFileClientSpec *__thiscall CScopedFileClientSpec::CScopedFileClientSpec(
        CScopedFileClientSpec *this,
        const char *pFullPath)
{
  const struct StrPtr *Client; // eax
  char pClientSpec[260]; // [esp+4h] [ebp-208h] BYREF
  char pDest[260]; // [esp+108h] [ebp-104h] BYREF

  this->m_bClientSpecNeedsRestore = false;
  V_strncpy(pDest, pSrc: pFullPath, maxLen: 260);
  V_StripFilename(path: pDest);
  if ( s_p4.GetClientSpecForDirectory(this: &s_p4, a2: pDest, a3: pClientSpec, a4: 260) )
  {
    Client = ClientApi::GetClient(this: &s_p4.m_Client);
    V_strncpy(pDest: this->m_pOldClientSpec, pSrc: Client->buffer, maxLen: 260);
    if ( _V_stricmp(s1: this->m_pOldClientSpec, s2: pClientSpec) != 0 )
    {
      if ( s_p4.IsConnectedToServer(this: &s_p4, a2: true) )
      {
        ClientApi::SetClient(this: &s_p4.m_Client, a2: pClientSpec);
        CP4::RefreshClientData(this: &s_p4);
      }
      this->m_bClientSpecNeedsRestore = true;
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10005C20
// Name: public: CScopedDirClientSpec::CScopedDirClientSpec(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CScopedDirClientSpec *__thiscall CScopedDirClientSpec::CScopedDirClientSpec(
        CScopedDirClientSpec *this,
        const char *pFullPathDir)
{
  const struct StrPtr *Client; // eax
  char pClientSpec[260]; // [esp+4h] [ebp-104h] BYREF

  this->m_bClientSpecNeedsRestore = false;
  if ( CP4::GetClientSpecForDirectory(this: &s_p4, pFullPathDir, pClientSpec, nMaxLen: 260) )
  {
    Client = ClientApi::GetClient(this: &s_p4.m_Client);
    V_strncpy(pDest: this->m_pOldClientSpec, pSrc: Client->buffer, maxLen: 260);
    if ( _V_stricmp(s1: this->m_pOldClientSpec, s2: pClientSpec) != 0 )
    {
      if ( s_p4.IsConnectedToServer(this: &s_p4, a2: true) )
      {
        ClientApi::SetClient(this: &s_p4.m_Client, a2: pClientSpec);
        CP4::RefreshClientData(this: &s_p4);
      }
      this->m_bClientSpecNeedsRestore = true;
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10005CD0
// Name: public: CScopedPathClientSpec::CScopedPathClientSpec(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CScopedPathClientSpec *__thiscall CScopedPathClientSpec::CScopedPathClientSpec(
        CScopedPathClientSpec *this,
        const char *pPathID)
{
  const struct StrPtr *Client; // eax
  char pClientSpec[260]; // [esp+4h] [ebp-104h] BYREF

  this->m_bClientSpecNeedsRestore = false;
  if ( CP4::GetClientSpecForPath(this: &s_p4, pPathId: pPathID, pClientSpec, nMaxLen: 260) != 0 )
  {
    Client = ClientApi::GetClient(this: &s_p4.m_Client);
    V_strncpy(pDest: this->m_pOldClientSpec, pSrc: Client->buffer, maxLen: 260);
    if ( s_p4.IsConnectedToServer(this: &s_p4, a2: true) )
    {
      ClientApi::SetClient(this: &s_p4.m_Client, a2: pClientSpec);
      CP4::RefreshClientData(this: &s_p4);
    }
    this->m_bClientSpecNeedsRestore = true;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10005D60
// Name: public: void CRevisionHistoryUser::RetrieveHistory(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRevisionHistoryUser::RetrieveHistory(CRevisionHistoryUser *this, const char *path, bool bDir)
{
  CUtlVector<P4Revision_t,CUtlMemory<P4Revision_t,int> > *p_m_Data; // ecx
  char szSearch[260]; // [esp+4h] [ebp-11Ch] BYREF
  char *argv[6]; // [esp+108h] [ebp-18h] BYREF

  p_m_Data = &this->m_Data;
  this->m_bAwaitingNewRecord = true;
  this->m_pData = p_m_Data;
  CUtlVector<P4Revision_t,CUtlMemory<P4Revision_t,int>>::RemoveAll(this: p_m_Data);
  if ( bDir )
    V_snprintf(pDest: szSearch, maxLen: 260, pFormat: "%s/...", path);
  else
    V_snprintf(pDest: szSearch, maxLen: 260, pFormat: "%s", path);
  argv[4] = szSearch;
  argv[0] = "-l";
  argv[1] = "-t";
  argv[2] = "-m";
  argv[3] = "50";
  argv[5] = nullptr;
  StrDict::SetArgv(this: &s_p4.m_Client, a2: 5, a3: argv);
  ClientApi::Run(this: &s_p4.m_Client, a2: "changes", a3: this);
}

//------------------------------------------------------------------------------
// Address: 0x10005E10
// Name: public: void CUtlMemory<struct P4Revision_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<P4Revision_t,int>::Grow(CUtlMemory<P4Revision_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  P4Revision_t *m_pMemory; // edx
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
    v7 = 48 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (P4Revision_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (P4Revision_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005EB0
// Name: public: int CUtlVector<struct P4Revision_t,class CUtlMemory<struct P4Revision_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<P4Revision_t,CUtlMemory<P4Revision_t,int>>::InsertBefore(
        CUtlVector<P4Revision_t,CUtlMemory<P4Revision_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  P4Revision_t *m_pMemory; // ecx
  int v6; // eax
  CUtlString *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<P4Revision_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 48 * v6);
  v7 = (CUtlString *)&this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    v7[1].m_Storage.m_nActualLength = -1;
    CUtlString::CUtlString(this: v7 + 2);
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10005F30
// Name: private: virtual void CDataRetrievalUser<struct P4Revision_t>::OutputInfo(char,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDataRetrievalUser<P4Revision_t>::OutputInfo(
        CDataRetrievalUser<P4Revision_t> *this,
        char level,
        const char *data)
{
  P4Revision_t *v4; // esi
  char *v5; // eax
  char szInfo[260]; // [esp+8h] [ebp-208h] BYREF
  char szVar[260]; // [esp+10Ch] [ebp-104h] BYREF

  if ( _V_strlen(str: data) >= 1 )
  {
    if ( this->m_bAwaitingNewRecord )
    {
      v4 = &this->m_pData->m_Memory.m_pMemory[CUtlVector<P4Revision_t,CUtlMemory<P4Revision_t,int>>::InsertBefore(
                                                this: this->m_pData,
                                                elem: this->m_pData->m_Size)];
      memset(dst: (unsigned __int8 *)v4, value: 0, count: sizeof(P4Revision_t));
      if ( v4 != nullptr )
      {
        *(_DWORD *)&v4->m_sUser.m_Id = -1;
        CUtlString::CUtlString(this: &v4->m_Description);
      }
      this->m_bAwaitingNewRecord = false;
    }
    V_strncpy(pDest: szVar, pSrc: data, maxLen: 260);
    v5 = _V_strstr(s1: szVar, search: " ");
    if ( v5 != nullptr )
    {
      *v5 = 0;
      V_strncpy(pDest: szInfo, pSrc: &data[v5 - szVar + 1], maxLen: 260);
    }
    else
    {
      szInfo[0] = 0;
    }
    this->OutputRecord(this, a2: &this->m_pData->m_Memory.m_pMemory[this->m_pData->m_Size - 1], a3: szVar, a4: szInfo);
  }
  else
  {
    this->m_bAwaitingNewRecord = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006030
// Name: int FindOrCreateChangelist(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FindOrCreateChangelist(const char *pDescription)
{
  const char *v1; // edi
  int v2; // esi
  int id; // ecx
  unsigned __int16 v4; // ax
  unsigned __int16 v5; // dx
  int v6; // ecx
  UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short> *m_pMemory; // eax
  int v8; // esi
  int v9; // edx
  unsigned __int16 Inorder; // ax
  int key; // eax
  bool v12; // zf
  char chClNumber[50]; // [esp+Ch] [ebp-80h] BYREF
  CUtlMap<int,ChangelistDesc_t const *,unsigned short> mapFoundChangelists; // [esp+40h] [ebp-4Ch] BYREF
  char *argv[3]; // [esp+5Ch] [ebp-30h] BYREF
  CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t insert; // [esp+68h] [ebp-24h] BYREF
  int iCreatedEmptyCl; // [esp+70h] [ebp-1Ch]
  int k; // [esp+74h] [ebp-18h]
  unsigned __int16 parent[2]; // [esp+78h] [ebp-14h] BYREF
  int iFoundChangelist; // [esp+7Ch] [ebp-10h]
  unsigned int v22; // [esp+80h] [ebp-Ch]
  CUtlSymbol symDesc; // [esp+84h] [ebp-8h] BYREF
  bool leftchild; // [esp+8Bh] [ebp-1h] BYREF

  v1 = pDescription;
  v2 = 0;
  iCreatedEmptyCl = 0;
  iFoundChangelist = 0;
  mapFoundChangelists.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const int *, const int *))CDefOps<int>::LessFunc;
  memset(&mapFoundChangelists.m_Tree.m_Elements, 0, sizeof(mapFoundChangelists.m_Tree.m_Elements));
  *(_DWORD *)&mapFoundChangelists.m_Tree.m_Root = 0xFFFF;
  *(_DWORD *)&mapFoundChangelists.m_Tree.m_FirstFree = -1;
  mapFoundChangelists.m_Tree.m_pElements = nullptr;
  CUtlSymbol::CUtlSymbol(this: &symDesc, pStr: pDescription);
  while ( 1 )
  {
    CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &mapFoundChangelists.m_Tree);
    g_ChangelistFindUser.m_bAwaitingNewRecord = true;
    g_ChangelistFindUser.m_pData = &g_ChangelistFindUser.m_Data;
    g_ChangelistFindUser.m_Data.m_Size = 0;
    *(_DWORD *)&chClNumber[20] = "-l";
    *(_DWORD *)&chClNumber[24] = "-t";
    *(_DWORD *)&chClNumber[28] = "-s";
    *(_DWORD *)&chClNumber[32] = "pending";
    *(_DWORD *)&chClNumber[36] = "-c";
    *(_DWORD *)&chClNumber[40] = ClientApi::GetClient(this: &s_p4.m_Client)->buffer;
    *(_DWORD *)&chClNumber[44] = 0;
    StrDict::SetArgv(this: &s_p4.m_Client, a2: 6, a3: (char *const *)&chClNumber[20]);
    ClientApi::Run(this: &s_p4.m_Client, a2: "changes", a3: &g_ChangelistFindUser);
    k = 0;
    if ( g_ChangelistFindUser.m_Data.m_Size > 0 )
    {
      v22 = 0;
      do
      {
        if ( symDesc.m_Id == g_ChangelistFindUser.m_Data.m_Memory.m_pMemory[v22 / 0x18].m_sDescription.m_Id )
        {
          id = g_ChangelistFindUser.m_Data.m_Memory.m_pMemory[v22 / 0x18].id;
          insert.elem = &g_ChangelistFindUser.m_Data.m_Memory.m_pMemory[v22 / 0x18];
          insert.key = id;
          *(_DWORD *)parent = 0xFFFF;
          leftchild = false;
          CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
            this: &mapFoundChangelists.m_Tree,
            &insert,
            parent,
            &leftchild);
          v4 = CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(this: &mapFoundChangelists.m_Tree);
          v5 = parent[0];
          v6 = v4;
          m_pMemory = mapFoundChangelists.m_Tree.m_Elements.m_pMemory;
          v8 = v6;
          mapFoundChangelists.m_Tree.m_Elements.m_pMemory[v8].m_Right = -1;
          m_pMemory[v8].m_Left = -1;
          m_pMemory[v8].m_Tag = 0;
          m_pMemory[v8].m_Parent = v5;
          if ( v5 == 0xFFFF )
          {
            mapFoundChangelists.m_Tree.m_Root = v6;
          }
          else
          {
            v9 = v5;
            if ( leftchild )
              m_pMemory[v9].m_Left = v6;
            else
              m_pMemory[v9].m_Right = v6;
          }
          CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
            this: &mapFoundChangelists.m_Tree,
            elem: v6);
          ++mapFoundChangelists.m_Tree.m_NumElements;
          if ( &mapFoundChangelists.m_Tree.m_Elements.m_pMemory[v8] != (UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short> *)-8 )
            mapFoundChangelists.m_Tree.m_Elements.m_pMemory[v8].m_Data = insert;
        }
        v22 += 24;
        ++k;
      }
      while ( k < g_ChangelistFindUser.m_Data.m_Size );
      v1 = pDescription;
      v2 = iCreatedEmptyCl;
    }
    if ( mapFoundChangelists.m_Tree.m_NumElements != 0 )
    {
      Inorder = CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &mapFoundChangelists.m_Tree);
      key = mapFoundChangelists.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.key;
      iFoundChangelist = key;
      goto LABEL_18;
    }
    if ( v2 > 0 )
      break;
    key = iFoundChangelist;
LABEL_18:
    if ( key > 0 )
    {
      if ( v2 > 0 && v2 != key )
      {
        sprintf(string: chClNumber, format: "%d", v2);
        argv[0] = "-d";
        argv[1] = chClNumber;
        argv[2] = nullptr;
        StrDict::SetArgv(this: &s_p4.m_Client, a2: 2, a3: argv);
        ClientApi::Run(this: &s_p4.m_Client, a2: "change", a3: &g_ErrorHandlerUser);
      }
      CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &mapFoundChangelists.m_Tree);
      if ( mapFoundChangelists.m_Tree.m_Elements.m_nGrowSize >= 0
        && mapFoundChangelists.m_Tree.m_Elements.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: mapFoundChangelists.m_Tree.m_Elements.m_pMemory);
      }
      return iFoundChangelist;
    }
    g_ChangelistCreateUser.m_bAwaitingNewRecord = true;
    g_ChangelistCreateUser.m_pData = &g_ChangelistCreateUser.m_Data;
    g_ChangelistCreateUser.m_Data.m_Size = 0;
    if ( v1 == nullptr || (v12 = *v1 == 0, g_ChangelistCreateUser.m_pDescription = v1, v12) )
      g_ChangelistCreateUser.m_pDescription = "I'm a loser who didn't type a description. Mock me at your earliest convenience.";
    argv[1] = "-i";
    argv[2] = nullptr;
    StrDict::SetArgv(this: &s_p4.m_Client, a2: 1, a3: &argv[1]);
    ClientApi::Run(this: &s_p4.m_Client, a2: "change", a3: &g_ChangelistCreateUser);
    if ( g_ChangelistCreateUser.m_Data.m_Size != 0 )
    {
      v2 = *g_ChangelistCreateUser.m_Data.m_Memory.m_pMemory;
      iCreatedEmptyCl = v2;
      if ( v2 != 0 )
        continue;
    }
    CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &mapFoundChangelists.m_Tree);
    if ( mapFoundChangelists.m_Tree.m_Elements.m_nGrowSize >= 0
      && mapFoundChangelists.m_Tree.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: mapFoundChangelists.m_Tree.m_Elements.m_pMemory);
    }
    return 0;
  }
  CUtlRBTree<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short,CUtlMap<int,ChangelistDesc_t const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,ChangelistDesc_t const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &mapFoundChangelists.m_Tree);
  if ( mapFoundChangelists.m_Tree.m_Elements.m_nGrowSize >= 0
    && mapFoundChangelists.m_Tree.m_Elements.m_pMemory != nullptr )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: mapFoundChangelists.m_Tree.m_Elements.m_pMemory);
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x100063A0
// Name: public: virtual enum InitReturnVal_t CP4::Init(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CP4::Init(CP4 *this)
{
  bool v2; // al
  Error e; // [esp+8h] [ebp-Ch] BYREF

  ClientApi::SetProtocol(this: &this->m_Client, a2: "tag", a3: byte_10040CDC);
  e.ep = nullptr;
  e.severity = E_EMPTY;
  ClientApi::Init(this: &this->m_Client, a2: &e);
  v2 = e.severity <= E_INFO && ClientApi::Dropped(this: &this->m_Client) == 0;
  this->m_bConnectedToServer = v2;
  CP4::RefreshClientData(this);
  Error::~Error(this: &e);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10006420
// Name: public: virtual class CUtlVector<struct P4File_t,class CUtlMemory<struct P4File_t,int>> __near & CP4::GetFileList(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<P4File_t,CUtlMemory<P4File_t,int> > *__thiscall CP4::GetFileList(CP4 *this, const char *pPath)
{
  CScopedDirClientSpec spec; // [esp+0h] [ebp-108h] BYREF

  if ( this->IsConnectedToServer(this, a2: true) )
  {
    CScopedDirClientSpec::CScopedDirClientSpec(this: &spec, pFullPathDir: pPath);
    CFileUser::RetrieveDir(this: &g_FileUser, dir: pPath);
    if ( spec.m_bClientSpecNeedsRestore && s_p4.IsConnectedToServer(this: &s_p4, a2: true) )
    {
      ClientApi::SetClient(this: &s_p4.m_Client, a2: spec.m_pOldClientSpec);
      CP4::RefreshClientData(this: &s_p4);
    }
    return &g_FileUser.m_Data;
  }
  else
  {
    if ( (_S1 & 1) == 0 )
    {
      _S1 |= 1u;
      dummy_0.m_Memory.m_pMemory = nullptr;
      dummy_0.m_Memory.m_nAllocationCount = 0;
      dummy_0.m_Memory.m_nGrowSize = 0;
      dummy_0.m_Size = 0;
      dummy_0.m_pElements = nullptr;
      atexit(func: CP4::GetFileList_::_5_::_dynamic_atexit_destructor_for__dummy__);
    }
    return &dummy_0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100064E0
// Name: public: virtual class CUtlVector<struct P4File_t,class CUtlMemory<struct P4File_t,int>> __near & CP4::GetFileListUsingClientSpec(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<P4File_t,CUtlMemory<P4File_t,int> > *__thiscall CP4::GetFileListUsingClientSpec(
        CP4 *this,
        const char *pPath,
        const char *pClientSpec)
{
  CScopedClientSpec spec; // [esp+0h] [ebp-108h] BYREF

  if ( this->IsConnectedToServer(this, a2: true) )
  {
    CScopedClientSpec::CScopedClientSpec(this: &spec, pClientSpec);
    CFileUser::RetrieveDir(this: &g_FileUser, dir: pPath);
    if ( spec.m_bClientSpecNeedsRestore && s_p4.IsConnectedToServer(this: &s_p4, a2: true) )
    {
      ClientApi::SetClient(this: &s_p4.m_Client, a2: spec.m_pOldClientSpec);
      CP4::RefreshClientData(this: &s_p4);
    }
    return &g_FileUser.m_Data;
  }
  else
  {
    if ( (_S2 & 1) == 0 )
    {
      _S2 |= 1u;
      dummy_1.m_Memory.m_pMemory = nullptr;
      dummy_1.m_Memory.m_nAllocationCount = 0;
      dummy_1.m_Memory.m_nGrowSize = 0;
      dummy_1.m_Size = 0;
      dummy_1.m_pElements = nullptr;
      atexit(func: CP4::GetFileListUsingClientSpec_::_5_::_dynamic_atexit_destructor_for__dummy__);
    }
    return &dummy_1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100065A0
// Name: public: virtual void CP4::GetOpenedFileList(char const __near *,class CUtlVector<struct P4File_t,class CUtlMemory<struct P4File_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CP4::GetOpenedFileList(
        CP4 *this,
        const char *pRootDirectory,
        CUtlVector<P4File_t,CUtlMemory<P4File_t,int> > *fileList)
{
  CScopedDirClientSpec spec; // [esp+0h] [ebp-108h] BYREF

  if ( this->IsConnectedToServer(this, a2: true) )
  {
    CScopedDirClientSpec::CScopedDirClientSpec(this: &spec, pFullPathDir: pRootDirectory);
    g_FileUser.m_bAwaitingNewRecord = true;
    g_FileUser.m_pData = fileList;
    fileList->m_Size = 0;
    ClientApi::Run(this: &s_p4.m_Client, a2: "opened", a3: &g_FileUser);
    CFileUser::ComputeLocalFileNames(this: &g_FileUser, fileList);
    if ( spec.m_bClientSpecNeedsRestore && s_p4.IsConnectedToServer(this: &s_p4, a2: true) )
    {
      ClientApi::SetClient(this: &s_p4.m_Client, a2: spec.m_pOldClientSpec);
      CP4::RefreshClientData(this: &s_p4);
    }
  }
  else
  {
    fileList->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006650
// Name: public: virtual void CP4::GetOpenedFileListInPath(char const __near *,class CUtlVector<struct P4File_t,class CUtlMemory<struct P4File_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CP4::GetOpenedFileListInPath(
        CP4 *this,
        const char *pPathID,
        CUtlVector<P4File_t,CUtlMemory<P4File_t,int> > *fileList)
{
  CScopedPathClientSpec spec; // [esp+0h] [ebp-108h] BYREF

  if ( this->IsConnectedToServer(this, a2: true) )
  {
    CScopedPathClientSpec::CScopedPathClientSpec(this: &spec, pPathID);
    g_FileUser.m_bAwaitingNewRecord = true;
    g_FileUser.m_pData = fileList;
    fileList->m_Size = 0;
    ClientApi::Run(this: &s_p4.m_Client, a2: "opened", a3: &g_FileUser);
    CFileUser::ComputeLocalFileNames(this: &g_FileUser, fileList);
    if ( spec.m_bClientSpecNeedsRestore && s_p4.IsConnectedToServer(this: &s_p4, a2: true) )
    {
      ClientApi::SetClient(this: &s_p4.m_Client, a2: spec.m_pOldClientSpec);
      CP4::RefreshClientData(this: &s_p4);
    }
  }
  else
  {
    fileList->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006700
// Name: public: char const __near * CP4::GetOpenFileChangeListNum(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CP4::GetOpenFileChangeListNum(CP4 *this)
{
  const char *v2; // eax
  int Changelist; // eax

  if ( CUtlString::Length(this: &this->m_sChangeListName) == 0 )
    return nullptr;
  if ( this->m_nCachedChangeListNumber != 0 )
    return CUtlString::Get(this: &this->m_sCachedChangeListNum);
  v2 = CUtlString::Get(this: &this->m_sChangeListName);
  Changelist = FindOrCreateChangelist(pDescription: v2);
  this->m_nCachedChangeListNumber = Changelist;
  if ( Changelist != 0 )
    CUtlString::Format(this: &this->m_sCachedChangeListNum, pFormat: "%d", Changelist);
  if ( this->m_nCachedChangeListNumber != 0 )
    return CUtlString::Get(this: &this->m_sCachedChangeListNum);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10006770
// Name: void SimplePerforceOpCurChangeList(int,char const __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SimplePerforceOpCurChangeList(int nCount, const char **ppFullPathList)
{
  const char **m_pMemory; // edi
  const char *v3; // ecx
  int v4; // eax
  _DWORD *v5; // ecx
  CUtlVector<char const *,CUtlMemory<char const *,int> > arrArgv; // [esp+4h] [ebp-18h] BYREF
  const char *szClNum; // [esp+18h] [ebp-4h]

  szClNum = CP4::GetOpenFileChangeListNum(this: &s_p4);
  if ( szClNum != nullptr )
  {
    memset(&arrArgv, 0, sizeof(arrArgv));
    CUtlVector<char const *,CUtlMemory<char const *,int>>::InsertMultipleBefore(
      this: &arrArgv,
      elem: 0,
      num: nCount + 3);
    m_pMemory = arrArgv.m_Memory.m_pMemory;
    v3 = szClNum;
    v4 = 0;
    *arrArgv.m_Memory.m_pMemory = "-c";
    m_pMemory[1] = v3;
    if ( nCount > 0 )
    {
      v5 = m_pMemory + 2;
      do
        *v5++ = ppFullPathList[v4++];
      while ( v4 < nCount );
    }
    m_pMemory[nCount + 2] = nullptr;
    StrDict::SetArgv(this: &s_p4.m_Client, a2: nCount + 2, a3: (char *const *)m_pMemory);
    ClientApi::Run(this: &s_p4.m_Client, a2: s_pOperation, a3: &g_ErrorHandlerUser);
    if ( arrArgv.m_Memory.m_nGrowSize >= 0 )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
  else
  {
    StrDict::SetArgv(this: &s_p4.m_Client, a2: nCount, a3: (char *const *)ppFullPathList);
    ClientApi::Run(this: &s_p4.m_Client, a2: s_pOperation, a3: &g_ErrorHandlerUser);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006850
// Name: private: bool CP4::PerformPerforceOp(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4::PerformPerforceOp(CP4 *this, const char *pOperation, const char *pFullPath)
{
  CScopedFileClientSpec spec; // [esp+8h] [ebp-110h] BYREF
  char *argv[2]; // [esp+110h] [ebp-8h] BYREF
  bool pFullPath_3; // [esp+127h] [ebp+Fh]

  g_ErrorHandlerUser.m_errorSeverity = E_EMPTY;
  g_ErrorHandlerUser.m_errorBuf.length = 0;
  if ( this->IsConnectedToServer(this, a2: true) )
  {
    CScopedFileClientSpec::CScopedFileClientSpec(this: &spec, pFullPath);
    argv[0] = (char *)pFullPath;
    argv[1] = nullptr;
    StrDict::SetArgv(this: &this->m_Client, a2: 1, a3: argv);
    ClientApi::Run(this: &this->m_Client, a2: pOperation, a3: &g_ErrorHandlerUser);
    pFullPath_3 = g_ErrorHandlerUser.m_errorSeverity < E_WARN;
    if ( spec.m_bClientSpecNeedsRestore && s_p4.IsConnectedToServer(this: &s_p4, a2: true) )
    {
      ClientApi::SetClient(this: &s_p4.m_Client, a2: spec.m_pOldClientSpec);
      CP4::RefreshClientData(this: &s_p4);
    }
    return pFullPath_3;
  }
  else
  {
    g_ErrorHandlerUser.m_errorBuf.length = 0;
    StrBuf::Append(this: &g_ErrorHandlerUser.m_errorBuf, src: "Not connected to P4 server\n");
    g_ErrorHandlerUser.m_errorSeverity = E_FATAL;
    return false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006930
// Name: private: bool CP4::PerformPerforceOpCurChangeList(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4::PerformPerforceOpCurChangeList(CP4 *this, const char *pOperation, const char *pFullPath)
{
  char **v5; // edi
  int v6; // ebx
  char *v7; // eax
  bool v8; // bl
  CScopedFileClientSpec spec; // [esp+8h] [ebp-118h] BYREF
  char *argv[4]; // [esp+110h] [ebp-10h] BYREF

  g_ErrorHandlerUser.m_errorSeverity = E_EMPTY;
  g_ErrorHandlerUser.m_errorBuf.length = 0;
  if ( this->IsConnectedToServer(this, a2: true) )
  {
    CScopedFileClientSpec::CScopedFileClientSpec(this: &spec, pFullPath);
    argv[2] = (char *)pFullPath;
    argv[3] = nullptr;
    argv[0] = "-c";
    argv[1] = (char *)byte_10040CDC;
    v5 = argv;
    v6 = 3;
    v7 = (char *)CP4::GetOpenFileChangeListNum(this);
    if ( v7 != nullptr )
    {
      argv[1] = v7;
    }
    else
    {
      v5 = &argv[2];
      v6 = 1;
    }
    StrDict::SetArgv(this: &this->m_Client, a2: v6, a3: v5);
    ClientApi::Run(this: &this->m_Client, a2: pOperation, a3: &g_ErrorHandlerUser);
    v8 = g_ErrorHandlerUser.m_errorSeverity < E_WARN;
    if ( spec.m_bClientSpecNeedsRestore && s_p4.IsConnectedToServer(this: &s_p4, a2: true) )
    {
      ClientApi::SetClient(this: &s_p4.m_Client, a2: spec.m_pOldClientSpec);
      CP4::RefreshClientData(this: &s_p4);
    }
    return v8;
  }
  else
  {
    g_ErrorHandlerUser.m_errorBuf.length = 0;
    StrBuf::Append(this: &g_ErrorHandlerUser.m_errorBuf, src: "Not connected to P4 server\n");
    g_ErrorHandlerUser.m_errorSeverity = E_FATAL;
    return false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006A40
// Name: public: virtual bool CP4::OpenFilesForAdd(int,char const __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4::OpenFilesForAdd(CP4 *this, int nCount, const char **ppFullPathList)
{
  int v4; // eax

  v4 = CUtlString::Length(this: &this->m_sChangeListName);
  s_pOperation = "add";
  if ( v4 != 0 )
    return CP4::PerformPerforceOp(
             this,
             op: (void (__cdecl *)(int, const char **, const char *))SimplePerforceOpCurChangeList,
             nCount,
             ppFullPathList,
             pDescription: nullptr);
  else
    return CP4::PerformPerforceOp(
             this,
             op: (void (__cdecl *)(int, const char **, const char *))SimplePerforceOp,
             nCount,
             ppFullPathList,
             pDescription: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10006AA0
// Name: public: virtual bool CP4::OpenFilesForEdit(int,char const __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CP4::OpenFilesForEdit(CP4 *this, int nCount, const char **ppFullPathList)
{
  int v4; // eax
  char result; // al

  v4 = CUtlString::Length(this: &this->m_sChangeListName);
  s_pOperation = "edit";
  if ( v4 != 0 )
    result = CP4::PerformPerforceOp(
               this,
               op: (void (__cdecl *)(int, const char **, const char *))SimplePerforceOpCurChangeList,
               nCount,
               ppFullPathList,
               pDescription: nullptr);
  else
    result = CP4::PerformPerforceOp(
               this,
               op: (void (__cdecl *)(int, const char **, const char *))SimplePerforceOp,
               nCount,
               ppFullPathList,
               pDescription: nullptr);
  if ( result != 0 )
    return MakeFilesWritable(nCount, ppFullPathList);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10006B00
// Name: public: virtual bool CP4::OpenFilesForDelete(int,char const __near * __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4::OpenFilesForDelete(CP4 *this, int nCount, const char **ppFullPathList)
{
  int v4; // eax

  v4 = CUtlString::Length(this: &this->m_sChangeListName);
  s_pOperation = "delete";
  if ( v4 != 0 )
    return CP4::PerformPerforceOp(
             this,
             op: (void (__cdecl *)(int, const char **, const char *))SimplePerforceOpCurChangeList,
             nCount,
             ppFullPathList,
             pDescription: nullptr);
  else
    return CP4::PerformPerforceOp(
             this,
             op: (void (__cdecl *)(int, const char **, const char *))SimplePerforceOp,
             nCount,
             ppFullPathList,
             pDescription: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10006B60
// Name: public: virtual bool CP4::IsFileInPerforce(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4::IsFileInPerforce(CP4 *this, char *fullpath)
{
  bool v3; // bl
  CScopedFileClientSpec spec; // [esp+0h] [ebp-108h] BYREF

  if ( !this->IsConnectedToServer(this, a2: true) )
    return false;
  CScopedFileClientSpec::CScopedFileClientSpec(this: &spec, pFullPath: fullpath);
  CFileUser::RetrieveFile(this: &g_FileUser, filespec: fullpath);
  if ( g_FileUser.m_Data.m_Size == 0 )
  {
    if ( spec.m_bClientSpecNeedsRestore && s_p4.IsConnectedToServer(this: &s_p4, a2: true) )
    {
      ClientApi::SetClient(this: &s_p4.m_Client, a2: spec.m_pOldClientSpec);
      CP4::RefreshClientData(this: &s_p4);
    }
    return false;
  }
  v3 = !g_FileUser.m_Data.m_Memory.m_pMemory->m_bDeleted;
  if ( spec.m_bClientSpecNeedsRestore && s_p4.IsConnectedToServer(this: &s_p4, a2: true) )
  {
    ClientApi::SetClient(this: &s_p4.m_Client, a2: spec.m_pOldClientSpec);
    CP4::RefreshClientData(this: &s_p4);
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10006C30
// Name: public: virtual enum P4FileState_t CP4::GetFileState(char const __near *)
// Source: json
//------------------------------------------------------------------------------
P4FileState_t __thiscall CP4::GetFileState(CP4 *this, const char *pFullPath)
{
  P4FileState_t m_eOpenState; // esi
  CScopedFileClientSpec spec; // [esp+0h] [ebp-110h] BYREF
  char *v5[2]; // [esp+108h] [ebp-8h] BYREF

  if ( !this->IsConnectedToServer(this, a2: true) )
    return P4FILE_UNOPENED;
  CScopedFileClientSpec::CScopedFileClientSpec(this: &spec, pFullPath);
  g_FileUser.m_bAwaitingNewRecord = true;
  g_FileUser.m_pData = &g_FileUser.m_Data;
  g_FileUser.m_Data.m_Size = 0;
  v5[0] = (char *)pFullPath;
  v5[1] = nullptr;
  StrDict::SetArgv(this: &s_p4.m_Client, a2: 1, a3: v5);
  ClientApi::Run(this: &s_p4.m_Client, a2: "opened", a3: &g_FileUser);
  CFileUser::ComputeLocalFileNames(this: &g_FileUser, fileList: &g_FileUser.m_Data);
  if ( g_FileUser.m_Data.m_Size != 0 )
  {
    m_eOpenState = g_FileUser.m_Data.m_Memory.m_pMemory->m_eOpenState;
    if ( spec.m_bClientSpecNeedsRestore && s_p4.IsConnectedToServer(this: &s_p4, a2: true) )
    {
      ClientApi::SetClient(this: &s_p4.m_Client, a2: spec.m_pOldClientSpec);
      CP4::RefreshClientData(this: &s_p4);
    }
    return m_eOpenState;
  }
  else
  {
    if ( spec.m_bClientSpecNeedsRestore && s_p4.IsConnectedToServer(this: &s_p4, a2: true) )
    {
      ClientApi::SetClient(this: &s_p4.m_Client, a2: spec.m_pOldClientSpec);
      CP4::RefreshClientData(this: &s_p4);
    }
    return P4FILE_UNOPENED;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006D50
// Name: public: virtual bool CP4::GetFileInfo(char const __near *,struct P4File_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CP4::GetFileInfo(CP4 *this, char *pFullPath, P4File_t *pFileInfo)
{
  bool v4; // zf
  CScopedFileClientSpec spec; // [esp+0h] [ebp-108h] BYREF

  if ( !this->IsConnectedToServer(this, a2: true) )
    return 0;
  CScopedFileClientSpec::CScopedFileClientSpec(this: &spec, pFullPath);
  CFileUser::RetrieveFile(this: &g_FileUser, filespec: pFullPath);
  if ( g_FileUser.m_Data.m_Size != 1 )
  {
    if ( spec.m_bClientSpecNeedsRestore && s_p4.IsConnectedToServer(this: &s_p4, a2: true) )
    {
      ClientApi::SetClient(this: &s_p4.m_Client, a2: spec.m_pOldClientSpec);
      CP4::RefreshClientData(this: &s_p4);
    }
    return 0;
  }
  v4 = !spec.m_bClientSpecNeedsRestore;
  *pFileInfo = *g_FileUser.m_Data.m_Memory.m_pMemory;
  if ( !v4 && s_p4.IsConnectedToServer(this: &s_p4, a2: true) )
  {
    ClientApi::SetClient(this: &s_p4.m_Client, a2: spec.m_pOldClientSpec);
    CP4::RefreshClientData(this: &s_p4);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10006E40
// Name: private: virtual void CRevisionHistoryUser::OutputRecord(struct P4Revision_t __near &,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRevisionHistoryUser::OutputRecord(
        CRevisionHistoryUser *this,
        P4Revision_t *revision,
        const char *szCmd,
        const char *szInfo)
{
  tm *v4; // eax
  __int64 iTime; // [esp+4h] [ebp-8h] BYREF

  if ( _V_strcmp(s1: szCmd, s2: "change") != 0 )
  {
    if ( _V_strcmp(s1: szCmd, s2: "user") != 0 )
    {
      if ( _V_strcmp(s1: szCmd, s2: "client") != 0 )
      {
        if ( _V_strcmp(s1: szCmd, s2: "status") != 0 )
        {
          if ( _V_strcmp(s1: szCmd, s2: "desc") != 0 )
          {
            if ( _V_strcmp(s1: szCmd, s2: "time") == 0 )
            {
              iTime = atoi(nptr: szInfo);
              v4 = _gmtime64(timp: &iTime);
              revision->m_nYear = v4->tm_year + 1900;
              revision->m_nMonth = v4->tm_mon + 1;
              revision->m_nDay = v4->tm_mday;
              revision->m_nHour = v4->tm_hour;
              revision->m_nMinute = v4->tm_min;
              revision->m_nSecond = v4->tm_sec;
            }
          }
          else
          {
            CUtlString::operator=(this: &revision->m_Description, src: szInfo);
          }
        }
      }
      else
      {
        CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&szInfo + 1, pStr: szInfo);
        revision->m_sClient.m_Id = HIWORD(szInfo);
      }
    }
    else
    {
      CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&szInfo + 1, pStr: szInfo);
      revision->m_sUser.m_Id = HIWORD(szInfo);
    }
  }
  else
  {
    revision->m_iChange = atoi(nptr: szInfo);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006FB0
// Name: public: virtual class CUtlVector<struct P4Revision_t,class CUtlMemory<struct P4Revision_t,int>> __near & CP4::GetRevisionList(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<P4Revision_t,CUtlMemory<P4Revision_t,int> > *__thiscall CP4::GetRevisionList(
        CP4 *this,
        const char *path,
        bool bIsDir)
{
  if ( this->IsConnectedToServer(this, a2: true) )
  {
    CRevisionHistoryUser::RetrieveHistory(this: &g_RevisionHistoryUser, path, bDir: bIsDir);
    return &g_RevisionHistoryUser.m_Data;
  }
  else
  {
    if ( (_S3 & 1) == 0 )
    {
      _S3 |= 1u;
      dummy_2.m_Memory.m_pMemory = nullptr;
      dummy_2.m_Memory.m_nAllocationCount = 0;
      dummy_2.m_Memory.m_nGrowSize = 0;
      dummy_2.m_Size = 0;
      dummy_2.m_pElements = nullptr;
      atexit(func: CP4::GetRevisionList_::_5_::_dynamic_atexit_destructor_for__dummy__);
    }
    return &dummy_2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10007020
// Name: public: virtual bool CP4::OpenFileForAdd(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4::OpenFileForAdd(CP4 *this, const char *fullpath)
{
  return CP4::PerformPerforceOpCurChangeList(this, pOperation: "add", pFullPath: fullpath);
}

//------------------------------------------------------------------------------
// Address: 0x10007040
// Name: public: virtual bool CP4::OpenFileForEdit(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CP4::OpenFileForEdit(CP4 *this, const char *fullpath)
{
  char result; // al

  result = CP4::PerformPerforceOpCurChangeList(this, pOperation: "edit", pFullPath: fullpath);
  if ( result != 0 )
    return MakeFilesWritable(nCount: 1, ppFullPathList: &fullpath);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10007070
// Name: public: virtual bool CP4::OpenFileForDelete(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4::OpenFileForDelete(CP4 *this, const char *pFullPath)
{
  return CP4::PerformPerforceOpCurChangeList(this, pOperation: "delete", pFullPath);
}

//------------------------------------------------------------------------------
// Address: 0x10007090
// Name: public: virtual bool CP4::SyncFile(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4::SyncFile(CP4 *this, const char *pFullPath, int nRevision)
{
  char szFileOptions[388]; // [esp+4h] [ebp-184h] BYREF

  if ( nRevision < 0 )
    V_snprintf(pDest: szFileOptions, maxLen: 388, pFormat: "%s#head", pFullPath);
  else
    V_snprintf(pDest: szFileOptions, maxLen: 388, pFormat: "%s#%d", pFullPath, nRevision);
  return CP4::PerformPerforceOp(this, pOperation: "sync", pFullPath: szFileOptions);
}

//------------------------------------------------------------------------------
// Address: 0x10007100
// Name: public: virtual bool CP4::RevertFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CP4::RevertFile(CP4 *this, const char *pFullPath)
{
  return CP4::PerformPerforceOp(this, pOperation: "revert", pFullPath);
}

//------------------------------------------------------------------------------
// Address: 0x10007250
// Name: public: virtual ClientUser::~ClientUser(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ClientUser::~ClientUser(ClientUser *this)
{
  this->__vftable = (ClientUser_vtbl *)&ClientUser::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10007260
// Name: public: virtual void ClientUser::Help(char const __near * const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ClientUser::Help(ClientUser *this, const char *const *a2)
{
  const char *const *v2; // esi
  const char *i; // eax

  v2 = a2;
  for ( i = *a2; i != nullptr; ++v2 )
  {
    printf(format: "%s\n", i);
    i = *((const char **)v2 + 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10007290
// Name: public: virtual void ClientUser::OutputError(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ClientUser::OutputError(ClientUser *this, const char *buffer)
{
  _iobuf *v2; // eax
  unsigned int v3; // esi
  _iobuf *v4; // eax

  v2 = __iob_func();
  fflush(stream: v2 + 1);
  v3 = strlen(buffer);
  v4 = __iob_func();
  fwrite(buffer, size: 1u, count: v3, stream: v4 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x100072E0
// Name: public: virtual void ClientUser::OutputInfo(char,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ClientUser::OutputInfo(ClientUser *this, char a2, const char *buffer)
{
  unsigned int v3; // esi
  _iobuf *v4; // eax
  _iobuf *v5; // eax

  if ( a2 == 49 )
  {
    printf(format: "... ");
  }
  else if ( a2 == 50 )
  {
    printf(format: "... ... ");
  }
  v3 = strlen(buffer);
  v4 = __iob_func();
  fwrite(buffer, size: 1u, count: v3, stream: v4 + 1);
  v5 = __iob_func();
  fputc(ch: 10, str: v5 + 1);
}

//------------------------------------------------------------------------------
// Address: 0x10007350
// Name: public: virtual void ClientUser::OutputText(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ClientUser::OutputText(ClientUser *this, const char *buffer, unsigned int count)
{
  _iobuf *v3; // eax

  v3 = __iob_func();
  fwrite(buffer, size: 1u, count, stream: v3 + 1);
}

//------------------------------------------------------------------------------
// Address: 0x10007370
// Name: public: virtual void ClientUser::OutputBinary(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ClientUser::OutputBinary(ClientUser *this, const char *buffer, unsigned int count)
{
  _iobuf *v4; // eax
  _iobuf *v5; // eax
  int v6; // eax
  _iobuf *v7; // eax
  int v8; // [esp-4h] [ebp-Ch]

  if ( this->binaryStdout == (count == 0) )
  {
    this->binaryStdout = count != 0;
    v4 = __iob_func();
    fflush(stream: v4 + 1);
    v8 = this->binaryStdout != 0 ? 0x8000 : 0x4000;
    v5 = __iob_func();
    v6 = fileno(stream: v5 + 1);
    setmode(fh: v6, mode: v8);
  }
  v7 = __iob_func();
  fwrite(buffer, size: 1u, count, stream: v7 + 1);
}

//------------------------------------------------------------------------------
// Address: 0x100073F0
// Name: public: virtual class FileSys __near * ClientUser::File(enum FileSysType)
// Source: json
//------------------------------------------------------------------------------
struct FileSys *__thiscall ClientUser::File(ClientUser *this, enum FileSysType a2)
{
  return FileSys::Create(a1: a2);
}

//------------------------------------------------------------------------------
// Address: 0x10007400
// Name: public: virtual int ClientUser::Resolve(class ClientMerge __near *,class Error __near *)
// Source: json
//------------------------------------------------------------------------------
MergeStatus __thiscall ClientUser::Resolve(ClientUser *this, struct ClientMerge *a2, struct Error *a3)
{
  return a2->Resolve(this: a2, a2: a3);
}

//------------------------------------------------------------------------------
// Address: 0x10007430
// Name: public: virtual void ClientUser::DisableTmpCleanup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ClientUser::DisableTmpCleanup(ClientUser *this)
{
  Signaler::Disable(this: (Signaler *)&signaler);
}

//------------------------------------------------------------------------------
// Address: 0x10007440
// Name: public: virtual void ClientUser::Prompt(class StrPtr const __near &,class StrBuf __near &,int,class Error __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ClientUser::Prompt(ClientUser *this, const struct StrPtr *a2, StrBuf *a3, int a4, struct Error *a5)
{
  _iobuf *v5; // eax
  _iobuf *v6; // eax
  NoEcho *v7; // eax
  NoEcho *v8; // ebp
  bool v9; // cc
  char *buffer; // edi
  _iobuf *v11; // eax
  unsigned int v12; // kr00_4
  char *v13; // ecx
  unsigned int v14; // eax
  bool v15; // zf
  int v16; // eax
  int v17; // edi

  printf(format: a2->buffer);
  v5 = __iob_func();
  fflush(stream: v5 + 1);
  v6 = __iob_func();
  fflush(stream: v6);
  if ( a4 != 0 && (v7 = (NoEcho *)operator new(nSize: 4u)) != nullptr )
    v8 = NoEcho::NoEcho(this: v7);
  else
    v8 = nullptr;
  v9 = a3->size < 1024;
  a3->length = 1024;
  if ( v9 )
    StrBuf::Grow(this: a3, a2: 0);
  buffer = a3->buffer;
  v11 = __iob_func();
  if ( fgets(string: buffer, count: 1024, str: v11) != nullptr )
  {
    v12 = strlen(buffer);
    v13 = a3->buffer;
    v14 = v12 - (unsigned int)a3->buffer;
    v15 = &buffer[v14] == nullptr;
    v16 = (int)&buffer[v14];
    a3->length = v16;
    if ( !v15 && v13[v16 - 1] == 10 )
    {
      v17 = v16 - 1;
      v9 = v16 <= a3->size;
      a3->length = v16;
      if ( !v9 )
        StrBuf::Grow(this: a3, a2: v16 - 1);
      a3->buffer[v17] = 0;
      --a3->length;
    }
  }
  else
  {
    Error::Set(this: a5, a2: &MsgClient::Eof);
    a3->length = buffer - a3->buffer;
  }
  if ( v8 != nullptr )
  {
    NoEcho::~NoEcho(this: v8);
    free(pMem: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10007540
// Name: public: virtual void ClientUser::HandleError(class Error __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ClientUser::HandleError(ClientUser *this, struct Error *a2)
{
  StrBuf pMem; // [esp+4h] [ebp-Ch] BYREF

  pMem.size = 0;
  pMem.length = 0;
  pMem.buffer = StrBuf::nullStrBuf;
  Error::Fmt(this: a2, a2: &pMem, a3: 2);
  this->OutputError(this, a2: pMem.buffer);
  if ( pMem.buffer != StrBuf::nullStrBuf )
    free(pMem: pMem.buffer);
}

//------------------------------------------------------------------------------
// Address: 0x100075A0
// Name: public: virtual void ClientUser::InputData(class StrBuf __near *,class Error __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ClientUser::InputData(ClientUser *this, StrBuf *a2, struct Error *a3)
{
  unsigned int v3; // ebp
  int length; // ebx
  bool v5; // cc
  char *v6; // edi
  int v7; // eax
  int v8; // edi

  v3 = FileSys::BufferSize();
  a2->length = 0;
  do
  {
    length = a2->length;
    v5 = (int)(length + v3) <= a2->size;
    a2->length = length + v3;
    if ( !v5 )
      StrBuf::Grow(this: a2, a2: length);
    v6 = &a2->buffer[length];
    v7 = read(fh: 0, buf: v6, cnt: v3);
    v8 = (int)&v6[v7 - (unsigned int)a2->buffer];
    a2->length = v8;
  }
  while ( v7 > 0 );
  v5 = v8 + 1 <= a2->size;
  a2->length = v8 + 1;
  if ( !v5 )
    StrBuf::Grow(this: a2, a2: v8);
  a2->buffer[v8] = 0;
  --a2->length;
}

//------------------------------------------------------------------------------
// Address: 0x10007610
// Name: public: virtual void ClientUser::OutputStat(class StrDict __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ClientUser::OutputStat(ClientUser *this, struct StrDict *a2)
{
  int (__thiscall *VGetVarX)(StrDict *, int, StrRef *, StrRef *); // eax
  int v4; // [esp+14h] [ebp-24h]
  char v5; // [esp+18h] [ebp-20h]
  struct StrPtr first; // [esp+1Ch] [ebp-1Ch] BYREF
  struct StrPtr v7; // [esp+24h] [ebp-14h] BYREF
  StrBuf pMem; // [esp+2Ch] [ebp-Ch] BYREF

  VGetVarX = a2->VGetVarX;
  pMem.size = 0;
  pMem.length = 0;
  pMem.buffer = StrBuf::nullStrBuf;
  v4 = 0;
  if ( VGetVarX(this: a2, a2: 0, a3: (StrRef *)&first, a4: (StrRef *)&v7) != 0 )
  {
    do
    {
      if ( strcmp(first.buffer, "func") != 0 && strcmp(first.buffer, "specFormatted") != 0 )
      {
        pMem.length = 0;
        StrBuf::Append(this: &pMem, a2: &first);
        StrBuf::Append(this: &pMem, src: " ");
        StrBuf::Append(this: &pMem, a2: &v7);
        v5 = 50 - (strncmp(first: first.buffer, last: "other", count: 5u) != 0);
        this->OutputInfo(this, a2: v5, a3: pMem.buffer);
      }
      ++v4;
    }
    while ( a2->VGetVarX(this: a2, a2: v4, a3: (StrRef *)&first, a4: (StrRef *)&v7) != 0 );
  }
  this->OutputInfo_2(this, a2: 48, a3: byte_10040CDC);
  if ( pMem.buffer != StrBuf::nullStrBuf )
    free(pMem: pMem.buffer);
}

//------------------------------------------------------------------------------
// Address: 0x10007760
// Name: public: static void ClientUser::RunCmd(char const __near *,char const __near *,char const __near *,char const __near *,char const __near *,char const __near *,char const __near *,class Error __near *)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl ClientUser::RunCmd(
        char *string,
        char *a2,
        char *a3,
        char *a4,
        char *a5,
        char *a6,
        char *a7,
        struct Error *a8)
{
  RunCommand *v8; // eax
  RunCommand *v9; // edi
  _iobuf *v10; // eax
  StrBuf pMem; // [esp+4h] [ebp-Ch] BYREF

  v8 = (RunCommand *)operator new(nSize: 4u);
  if ( v8 != nullptr )
    v9 = RunCommand::RunCommand(this: v8);
  else
    v9 = nullptr;
  v10 = __iob_func();
  fflush(stream: v10 + 1);
  Signaler::Block(this: (Signaler *)&signaler);
  pMem.size = 0;
  pMem.length = 0;
  pMem.buffer = StrBuf::nullStrBuf;
  RunArgs::AddCmd(this: &pMem, string);
  if ( a2 != nullptr )
    RunArgs::AddArg(this: &pMem, a2);
  if ( a3 != nullptr )
    RunArgs::AddArg(this: &pMem, a2: a3);
  if ( a4 != nullptr )
    RunArgs::AddArg(this: &pMem, a2: a4);
  if ( a5 != nullptr )
    RunArgs::AddArg(this: &pMem, a2: a5);
  if ( a6 != nullptr )
    RunArgs::AddArg(this: &pMem, a2: a6);
  if ( a7 != nullptr )
  {
    RunArgs::AddArg(this: &pMem, a2: "|");
    RunArgs::AddArg(this: &pMem, a2: a7);
  }
  RunCommand::Run(this: v9, a2: (struct RunArgs *)&pMem, a3: a8);
  if ( v9 != nullptr )
  {
    RunCommand::~RunCommand(this: v9);
    free(pMem: v9);
  }
  Signaler::Catch(this: (Signaler *)&signaler);
  if ( pMem.buffer != StrBuf::nullStrBuf )
    free(pMem: pMem.buffer);
}

//------------------------------------------------------------------------------
// Address: 0x10007890
// Name: public: virtual void ClientUser::Message(class Error __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ClientUser::Message(ClientUser *this, struct Error *a2)
{
  StrBuf pMem; // [esp+8h] [ebp-Ch] BYREF

  if ( a2->severity == E_INFO )
  {
    pMem.size = 0;
    pMem.length = 0;
    pMem.buffer = StrBuf::nullStrBuf;
    Error::Fmt(this: a2, a2: &pMem, a3: 0);
    this->OutputInfo(this, a2: LOBYTE(a2->genericCode) + 48, a3: pMem.buffer);
    if ( pMem.buffer != StrBuf::nullStrBuf )
      free(pMem: pMem.buffer);
  }
  else
  {
    this->HandleError(this, a2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10007910
// Name: public: virtual void ClientUser::ErrorPause(char __near *,class Error __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ClientUser::ErrorPause(ClientUser *this, char *a2, struct Error *a3)
{
  int (__thiscall *OutputError)(ClientUser *, char *); // edx
  void (__thiscall *Prompt)(ClientUser *, const StrPtr *, StrBuf *, int, Error *); // edx
  _DWORD v6[2]; // [esp+Ch] [ebp-14h] BYREF
  void *pMem[3]; // [esp+14h] [ebp-Ch] BYREF

  OutputError = this->OutputError;
  pMem[2] = nullptr;
  pMem[1] = nullptr;
  pMem[0] = StrBuf::nullStrBuf;
  OutputError(this, a2);
  Prompt = this->Prompt;
  v6[0] = "Hit return to continue...";
  v6[1] = 25;
  Prompt(this, a2: (const StrPtr *)v6, a3: (StrBuf *)pMem, a4: 0, a5: a3);
  if ( pMem[0] != StrBuf::nullStrBuf )
    free(pMem: pMem[0]);
}

//------------------------------------------------------------------------------
// Address: 0x10007990
// Name: public: static void ClientUser::Edit(class FileSys __near *,class Enviro __near *,class Error __near *)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl ClientUser::Edit(struct FileSys *a1, struct Enviro *a2, Error *a3)
{
  __int32 v3; // eax
  const char *v4; // esi
  char *buffer; // edi
  RunCommand *v6; // eax
  RunCommand *v7; // ebx
  _iobuf *v8; // eax
  char *v9; // [esp-4h] [ebp-14h]
  StrBuf pMem; // [esp+4h] [ebp-Ch] BYREF

  v3 = a1->type & 0xF;
  if ( v3 == 1 || v3 == 12 || v3 == 14 )
  {
    v4 = Enviro::Get(this: a2, a2: "P4EDITOR");
    if ( v4 == nullptr )
    {
      v4 = Enviro::Get(this: a2, a2: "EDITOR");
      if ( v4 == nullptr )
      {
        v4 = "notepad";
        if ( Enviro::Get(this: a2, a2: "SHELL") != nullptr )
          v4 = "vi";
      }
    }
    buffer = a1->Path(this: a1)->buffer;
    v6 = (RunCommand *)operator new(nSize: 4u);
    if ( v6 != nullptr )
      v7 = RunCommand::RunCommand(this: v6);
    else
      v7 = nullptr;
    v8 = __iob_func();
    fflush(stream: v8 + 1);
    Signaler::Block(this: (Signaler *)&signaler);
    pMem.size = 0;
    pMem.length = 0;
    pMem.buffer = StrBuf::nullStrBuf;
    RunArgs::AddCmd(this: &pMem, string: v4);
    if ( buffer != nullptr )
      RunArgs::AddArg(this: &pMem, a2: buffer);
    RunCommand::Run(this: v7, a2: (struct RunArgs *)&pMem, a3);
    if ( v7 != nullptr )
    {
      RunCommand::~RunCommand(this: v7);
      free(pMem: v7);
    }
    Signaler::Catch(this: (Signaler *)&signaler);
    if ( pMem.buffer != StrBuf::nullStrBuf )
      free(pMem: pMem.buffer);
  }
  else
  {
    v9 = a1->Path(this: a1)->buffer;
    Error::Set(this: a3, a2: &MsgClient::CantEdit);
    Error::operator<<(a1: v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10007AE0
// Name: public: virtual void ClientUser::Diff(class FileSys __near *,class FileSys __near *,int,char __near *,class Error __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ClientUser::Diff(ClientUser *this, FileSys *a2, struct FileSys *a3, int a4, char *a5, struct Error *a6)
{
  __int32 v6; // eax
  __int32 v8; // eax
  __int32 v9; // eax
  FileSys *v10; // eax
  int v11; // ecx
  __int32 v12; // eax
  struct CharSetCvt *v13; // ecx
  StrPtr *v14; // eax
  StrPtr *v15; // eax
  FileSys *v16; // edi
  struct _iobuf *v17; // eax
  const char **v18; // eax
  char *v19; // eax
  FileSys_vtbl *v20; // edx
  FileSys *v21; // esi
  signed int i; // esi
  _iobuf *v23; // eax
  const char *v24; // esi
  RunCommand *v25; // eax
  RunCommand *v26; // ebx
  _iobuf *v27; // eax
  char *v28; // ebx
  char *v29; // edi
  StrPtr *v30; // eax
  char *v31; // esi
  char *v32; // edi
  char *v33; // eax
  StrPtr *v34; // eax
  char *v35; // [esp+14h] [ebp-880h]
  char *v36; // [esp+14h] [ebp-880h]
  char *v37; // [esp+14h] [ebp-880h]
  char *v38; // [esp+18h] [ebp-87Ch]
  char *string; // [esp+3Ch] [ebp-858h]
  char *v40; // [esp+40h] [ebp-854h]
  FileSys *v41; // [esp+40h] [ebp-854h]
  int content_charSet; // [esp+44h] [ebp-850h]
  int v43; // [esp+44h] [ebp-850h]
  struct CharSetCvt *Cvt; // [esp+44h] [ebp-850h]
  char *v45; // [esp+48h] [ebp-84Ch]
  int v46; // [esp+48h] [ebp-84Ch]
  FileSys *v47; // [esp+4Ch] [ebp-848h]
  StrBuf pMem; // [esp+50h] [ebp-844h] BYREF
  char *src; // [esp+5Ch] [ebp-838h]
  _BYTE v50[32]; // [esp+60h] [ebp-834h] BYREF
  _BYTE v51[16]; // [esp+80h] [ebp-814h] BYREF
  _BYTE buffer[2048]; // [esp+90h] [ebp-804h] BYREF

  src = a5;
  v6 = a2->type & 0xF;
  if ( (v6 == 1 || v6 == 12 || v6 == 14) && ((v8 = a3->type & 0xF) == 1 || v8 == 12 || v8 == 14) )
  {
    v45 = nullptr;
    v40 = Enviro::Get(this: this->enviro, a2: "P4DIFF");
    string = Enviro::Get(this: this->enviro, a2: "P4PAGER");
    content_charSet = 0;
    if ( v40 == nullptr )
      v40 = Enviro::Get(this: this->enviro, a2: "DIFF");
    v9 = a2->type & 0xF;
    if ( v9 == 12 || v9 == 14 )
    {
      v45 = Enviro::Get(this: this->enviro, a2: "P4DIFFUNICODE");
      content_charSet = a2->content_charSet;
    }
    if ( a4 != 0 )
    {
      if ( string == nullptr )
        string = Enviro::Get(this: this->enviro, a2: "PAGER");
    }
    else
    {
      string = nullptr;
    }
    if ( v45 != nullptr || v40 != nullptr )
    {
      v28 = src;
      if ( src != nullptr && *src != 0 )
      {
        pMem.size = 0;
        pMem.length = 0;
        pMem.buffer = StrBuf::nullStrBuf;
        StrBuf::Append(this: &pMem, src: "-", a3: 1);
        StrBuf::Append(this: &pMem, src: v28);
        v29 = a3->Path(this: a3)->buffer;
        if ( v45 != nullptr )
        {
          v30 = a2->Path(this: a2);
          v31 = pMem.buffer;
          v38 = v30->buffer;
          v35 = (char *)CharSetApi::Name(a1: content_charSet);
          ClientUser::RunCmd(string: v45, a2: v31, a3: v35, a4: v38, a5: v29, a6: nullptr, a7: string, a8: a6);
        }
        else
        {
          v36 = a2->Path(this: a2)->buffer;
          ClientUser::RunCmd(
            string: v40,
            a2: pMem.buffer,
            a3: v36,
            a4: v29,
            a5: nullptr,
            a6: nullptr,
            a7: string,
            a8: a6);
        }
        if ( pMem.buffer != StrBuf::nullStrBuf )
          free(pMem: pMem.buffer);
      }
      else
      {
        v32 = a3->Path(this: a3)->buffer;
        if ( v45 != nullptr )
        {
          v37 = a2->Path(this: a2)->buffer;
          v33 = (char *)CharSetApi::Name(a1: content_charSet);
          ClientUser::RunCmd(string: v45, a2: v33, a3: v37, a4: v32, a5: nullptr, a6: nullptr, a7: string, a8: a6);
        }
        else
        {
          v34 = a2->Path(this: a2);
          ClientUser::RunCmd(
            string: v40,
            a2: v34->buffer,
            a3: v32,
            a4: nullptr,
            a5: nullptr,
            a6: nullptr,
            a7: string,
            a8: a6);
        }
      }
    }
    else
    {
      v47 = this->File(this, a2: 2);
      v10 = this->File(this, a2: 2);
      v11 = a2->content_charSet;
      v41 = v10;
      v12 = a2->type & 0xF;
      v43 = v11;
      v46 = 0;
      if ( v12 != 12 && v12 != 14 || v11 == this->outputCharset || v11 == 1 )
      {
        if ( FileSys::IsUnicode(this: a2) != 0 && this->outputCharset != v43 )
          v46 = 1;
        v14 = a2->Path(this: a2);
        FileSys::Set(this: v47, a2: v14->buffer);
        v15 = a3->Path(this: a3);
        FileSys::Set(this: v41, a2: v15->buffer);
      }
      else
      {
        v47->isTemp = 1;
        FileSys::MakeGlobalTemp(this: v47);
        v41->isTemp = 1;
        FileSys::MakeGlobalTemp(this: v41);
        Cvt = (struct CharSetCvt *)CharSetCvt::FindCvt(a1: v43, a2: 1);
        a2->Translator(this: a2, a2: Cvt);
        FileSys::Copy(this: a2, a2: v47, a3: FPM_RW, a4: a6);
        if ( a6->severity <= E_INFO )
        {
          v13 = Cvt;
          if ( Cvt != nullptr )
          {
            (*(void (__thiscall **)(struct CharSetCvt *))(*(_DWORD *)Cvt + 20))(a1: Cvt);
            v13 = Cvt;
          }
          a3->Translator(this: a3, a2: v13);
          FileSys::Copy(this: a3, a2: v41, a3: FPM_RW, a4: a6);
        }
        if ( Cvt != nullptr )
          (**(void (__thiscall ***)(struct CharSetCvt *, int))Cvt)(a1: Cvt, a2: 1);
        if ( this->outputCharset >= 2u )
          v46 = 1;
      }
      if ( a6->severity <= E_INFO )
      {
        DiffFlags::Init(this: (DiffFlags *)v51, a2: src);
        Diff::Diff(this: (Diff *)v50);
        Diff::SetInput(this: (Diff *)v50, a2: v47, a3: v41, a4: (const struct DiffFlags *)v51, a5: a6);
        if ( a6->severity <= E_INFO )
        {
          v16 = nullptr;
          if ( string != nullptr || v46 != 0 )
          {
            v16 = this->File(this, a2: a2->type & 0xF000 | 0xC);
            v16->isTemp = 1;
            FileSys::MakeGlobalTemp(this: v16);
            v18 = (const char **)v16->Path(this: v16);
            Diff::SetOutput(this: (Diff *)v50, file: *v18, a3: a6);
          }
          else
          {
            v17 = __iob_func();
            Diff::SetOutput(this: (Diff *)v50, a2: v17 + 1);
          }
          if ( a6->severity <= E_INFO )
            Diff::DiffWithFlags(this: (Diff *)v50, a2: (const struct DiffFlags *)v51);
          Diff::CloseOutput(this: (Diff *)v50, a2: a6);
          if ( v46 != 0 )
          {
            v19 = (char *)CharSetCvt::FindCvt(a1: 1, a2: this->outputCharset);
            v20 = v16->__vftable;
            src = v19;
            v20->Translator(this: v16, a2: (struct CharSetCvt *)v19);
            if ( string != nullptr )
            {
              v21 = this->File(this, a2: a2->type);
              v21->isTemp = 1;
              FileSys::MakeGlobalTemp(this: v21);
              FileSys::Copy(this: v16, a2: v21, a3: FPM_RW, a4: a6);
              ((void (__thiscall *)(FileSys *, int))v16->dtr_FileSys)(a1: v16, a2: 1);
              v16 = v21;
            }
            else
            {
              v16->Open(this: v16, a2: FOM_READ, a3: a6);
              if ( a6->severity <= E_INFO )
              {
                for ( i = v16->Read(this: v16, a2: buffer, a3: 2048, a4: a6);
                      i > 0;
                      i = v16->Read(this: v16, a2: buffer, a3: 2048, a4: a6) )
                {
                  if ( a6->severity > E_INFO )
                    break;
                  v23 = __iob_func();
                  fwrite(buffer, size: i, count: 1u, stream: v23 + 1);
                }
                v16->Close(this: v16, a2: a6);
              }
            }
            if ( src != nullptr )
              (**(void (__thiscall ***)(char *, int))src)(a1: src, a2: 1);
          }
          if ( string != nullptr && a6->severity <= E_INFO )
          {
            v24 = v16->Path(this: v16)->buffer;
            v25 = (RunCommand *)operator new(nSize: 4u);
            if ( v25 != nullptr )
              v26 = RunCommand::RunCommand(this: v25);
            else
              v26 = nullptr;
            v27 = __iob_func();
            fflush(stream: v27 + 1);
            Signaler::Block(this: (Signaler *)&signaler);
            pMem.size = 0;
            pMem.length = 0;
            pMem.buffer = StrBuf::nullStrBuf;
            RunArgs::AddCmd(this: &pMem, string);
            if ( v24 != nullptr )
              RunArgs::AddArg(this: &pMem, a2: v24);
            RunCommand::Run(this: v26, a2: (struct RunArgs *)&pMem, a3: a6);
            if ( v26 != nullptr )
            {
              RunCommand::~RunCommand(this: v26);
              free(pMem: v26);
            }
            Signaler::Catch(this: (Signaler *)&signaler);
            if ( pMem.buffer != StrBuf::nullStrBuf )
              free(pMem: pMem.buffer);
          }
          if ( v16 != nullptr )
            ((void (__thiscall *)(FileSys *, int))v16->dtr_FileSys)(a1: v16, a2: 1);
        }
        Diff::~Diff(this: (Diff *)v50);
      }
      if ( v47 != nullptr )
        ((void (__thiscall *)(FileSys *, int))v47->dtr_FileSys)(a1: v47, a2: 1);
      if ( v41 != nullptr )
        ((void (__thiscall *)(FileSys *, int))v41->dtr_FileSys)(a1: v41, a2: 1);
    }
  }
  else if ( FileSys::Compare(this: a2, a2: a3, a3: a6) != 0 )
  {
    printf(format: "(... files differ ...)\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10008160
// Name: public: virtual void ClientUser::Merge(class FileSys __near *,class FileSys __near *,class FileSys __near *,class FileSys __near *,class Error __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ClientUser::Merge(
        ClientUser *this,
        struct FileSys *a2,
        struct FileSys *a3,
        struct FileSys *a4,
        struct FileSys *a5,
        struct Error *a6)
{
  __int32 v7; // eax
  char *v9; // ebp
  char *buffer; // esi
  char *v11; // edi
  char *v12; // ebx
  char *v13; // eax
  char *v14; // ebp
  char *v15; // esi
  char *v16; // edi
  char *v17; // ebx
  StrPtr *v18; // eax
  char *v19; // [esp-18h] [ebp-28h]
  struct FileSys *content_charSet; // [esp+20h] [ebp+10h]

  v7 = a5->type & 0xF;
  if ( (v7 == 12 || v7 == 14)
    && (content_charSet = (struct FileSys *)a5->content_charSet) != nullptr
    && (v9 = Enviro::Get(this: this->enviro, a2: "P4MERGEUNICODE")) != nullptr )
  {
    buffer = a5->Path(this: a5)->buffer;
    v11 = a4->Path(this: a4)->buffer;
    v12 = a3->Path(this: a3)->buffer;
    v19 = a2->Path(this: a2)->buffer;
    v13 = (char *)CharSetApi::Name(a1: content_charSet);
    ClientUser::RunCmd(string: v9, a2: v13, a3: v19, a4: v12, a5: v11, a6: buffer, a7: nullptr, a8: a6);
  }
  else
  {
    v14 = Enviro::Get(this: this->enviro, a2: "P4MERGE");
    if ( v14 != nullptr || (v14 = Enviro::Get(this: this->enviro, a2: "MERGE")) != nullptr )
    {
      v15 = a5->Path(this: a5)->buffer;
      v16 = a4->Path(this: a4)->buffer;
      v17 = a3->Path(this: a3)->buffer;
      v18 = a2->Path(this: a2);
      ClientUser::RunCmd(string: v14, a2: v18->buffer, a3: v17, a4: v16, a5: v15, a6: nullptr, a7: nullptr, a8: a6);
    }
    else
    {
      Error::Set(this: a6, a2: &MsgClient::NoMerger);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10008280
// Name: public: virtual void ClientUser::Edit(class FileSys __near *,class Error __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ClientUser::Edit(ClientUser *this, struct FileSys *a2, struct Error *a3)
{
  ClientUser::Edit(a1: a2, a2: this->enviro, a3);
}

//------------------------------------------------------------------------------
// Address: 0x10008300
// Name: public: void ClientApi::Init(class Error __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ClientApi::Init(ClientApi *this, struct Error *a2)
{
  Client::Init(this: this->client, a2);
}

//------------------------------------------------------------------------------
// Address: 0x10008820
// Name: public: void Client::Init(class Error __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Client::Init(Client *this, Error *a2)
{
  const struct StrPtr *v4; // eax
  const struct StrPtr *Port; // eax
  ZCService *v6; // eax
  ZCService *v7; // ebx
  int v8; // ebp
  char *buffer; // [esp-10h] [ebp-24h]
  struct StrPtr *v10; // [esp-10h] [ebp-24h]
  char *v11; // [esp-Ch] [ebp-20h]
  StrBuf pMem; // [esp+8h] [ebp-Ch] BYREF
  Error *v13; // [esp+18h] [ebp+4h]

  if ( a2->severity > E_INFO
    || (v4 = Client::GetPort(this),
        RpcService::SetEndpoint(this: (Client *)((char *)this + 276), string: v4->buffer, a3: a2),
        a2->severity > E_INFO)
    || (Rpc::Connect(this, a2), a2->severity > E_INFO) )
  {
    pMem.size = 0;
    pMem.length = 0;
    pMem.buffer = StrBuf::nullStrBuf;
    Port = Client::GetPort(this);
    v6 = ZCService::CreateForResolution(src: Port->buffer, a2: "_p4._tcp");
    v7 = v6;
    if ( v6 != nullptr )
    {
      v8 = ZCService::Resolve(this: v6);
      if ( v8 == 0 )
      {
        v13 = *((Error **)v7 + 25);
        StrBuf::Append(this: &pMem, src: *((const char **)v7 + 7));
        StrBuf::Append(this: &pMem, src: ":");
        StrBuf::operator<<(a1: &pMem, a2: v13);
      }
      ZCService::~ZCService(this: v7);
      free(pMem: v7);
      if ( v8 == 0 )
      {
        buffer = pMem.buffer;
        a2->severity = E_EMPTY;
        RpcService::SetEndpoint(this: (Client *)((char *)this + 276), string: buffer, a3: a2);
        if ( a2->severity <= E_INFO )
        {
          Rpc::Connect(this, a2);
          if ( a2->severity <= E_INFO )
          {
            v11 = Rpc::GetPeerAddress(this, a2: 2)->buffer;
            *((_DWORD *)this + 120) = 0;
            StrBuf::Append(this: (StrBuf *)((char *)this + 476), src: v11);
            goto LABEL_13;
          }
        }
        v10 = (struct StrPtr *)Client::GetPort(this);
        Error::Set(this: a2, a2: &MsgClient::ZCResolve);
        Error::operator<<(a1: v10);
        Error::operator<<(a1: &pMem);
      }
    }
    Error::Set(this: a2, a2: &MsgClient::Connect);
LABEL_13:
    if ( pMem.buffer != StrBuf::nullStrBuf )
      free(pMem: pMem.buffer);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009780
// Name: public: void Client::OutputError(class Error __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Client::OutputError(Client *this, struct Error *a2)
{
  int v2; // eax

  if ( a2->severity > E_INFO )
  {
    v2 = *((_DWORD *)this + 66);
    ++*((_DWORD *)this + 73);
    (*(void (__thiscall **)(_DWORD, struct Error *))(**((_DWORD **)this + v2 + 62) + 8))(
      a1: *((_DWORD *)this + v2 + 62),
      a2);
    a2->severity = E_EMPTY;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000E110
// Name: public: void Rpc::Connect(class Error __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Rpc::Connect(Rpc *this, struct Error *a2)
{
  NetBuffer *v3; // edi
  int v4; // eax
  int v5; // eax
  struct NetTransport *v6; // ebp
  int v7; // eax
  NetBuffer *v8; // eax
  NetBuffer *v9; // ebx

  v3 = nullptr;
  if ( *((_DWORD *)this + 2) != 0 )
  {
    Error::Set(this: a2, a2: &MsgRpc::Reconn);
    return;
  }
  v4 = *((_DWORD *)this + 4);
  *(_DWORD *)(v4 + 12) = 0;
  *(_DWORD *)(v4 + 4) = 0;
  *((_DWORD *)this + 16) = 0;
  *((_DWORD *)this + 13) = 0;
  v5 = *((_DWORD *)this + 1);
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 8) = 0;
  *((_DWORD *)this + 9) = 0;
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 12) = 0;
  if ( *(_DWORD *)v5 == 1 )
  {
    v7 = (*(int (__thiscall **)(_DWORD, struct Error *))(**(_DWORD **)(v5 + 8) + 28))(a1: *(_DWORD *)(v5 + 8), a2);
  }
  else
  {
    if ( *(_DWORD *)v5 != 2 )
    {
      v6 = nullptr;
      Error::Set(this: a2, a2: &MsgRpc::Unconn);
      goto LABEL_9;
    }
    v7 = (*(int (__thiscall **)(_DWORD, struct Error *))(**(_DWORD **)(v5 + 8) + 24))(a1: *(_DWORD *)(v5 + 8), a2);
  }
  v6 = (struct NetTransport *)v7;
LABEL_9:
  if ( a2->severity <= E_INFO )
  {
    v8 = (NetBuffer *)operator new(nSize: 0x2Cu);
    v9 = v8;
    if ( v8 != nullptr )
    {
      NetBuffer::NetBuffer(this: v8, a2: v6);
      *(_DWORD *)v9 = &RpcTransport::`vftable';
      v3 = v9;
    }
    *((_DWORD *)this + 2) = v3;
  }
  else
  {
    Error::operator=(a1: a2);
    Error::operator=(a1: a2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000E200
// Name: public: void Rpc::Disconnect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Rpc::Disconnect(Rpc *this)
{
  NetBuffer *v2; // ecx
  void (__thiscall ***v3)(_DWORD, int); // ecx

  v2 = *((NetBuffer **)this + 2);
  if ( v2 != nullptr )
  {
    NetBuffer::Flush(this: v2, a2: (struct Error *)((char *)this + 52));
    (*(void (__thiscall **)(_DWORD))(**((_DWORD **)this + 2) + 24))(a1: *((_DWORD *)this + 2));
    v3 = *((void (__thiscall ****)(_DWORD, int))this + 2);
    if ( v3 != nullptr )
      (**v3)(a1: v3, a2: 1);
    *((_DWORD *)this + 2) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100115D0
// Name: public: virtual class NetTransport __near * NetTcpEndPoint::Connect(class Error __near *)
// Source: json
//------------------------------------------------------------------------------
struct NetTransport *__thiscall NetTcpEndPoint::Connect(NetTcpEndPoint *this, struct Error *a2)
{
  struct StrPtr *v2; // ebx
  int v3; // eax
  SOCKET v4; // esi
  NetTcpTransport *v6; // eax
  struct sockaddr name; // [esp+Ch] [ebp-14h] BYREF

  v2 = (struct StrPtr *)((char *)this + 4);
  v3 = sub_10010FF0(a1: *((_DWORD *)this + 1));
  v4 = v3;
  if ( v3 < 0 )
    goto LABEL_6;
  if ( dword_1004F2F0 >= 4 )
    printf(format: "NetTcpEndpoint connect on %d\n", v3);
  if ( connect(s: v4, &name, namelen: 16) < 0 )
  {
    Error::Net(this: a2, a2: "connect", a3: v2->buffer);
    closesocket(s: v4);
LABEL_6:
    Error::Set(this: a2, a2: &MsgRpc::TcpConnect);
    Error::operator<<(a1: v2);
    return nullptr;
  }
  setsockopt(s: v4, level: 0xFFFF, optname: 8, optval: &optval, optlen: 4);
  v6 = (NetTcpTransport *)operator new(nSize: 0x28u);
  if ( v6 == nullptr )
    return nullptr;
  return NetTcpTransport::NetTcpTransport(this: v6, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10011900
// Name: public: virtual class NetTransport __near * NetStdioEndPoint::Connect(class Error __near *)
// Source: json
//------------------------------------------------------------------------------
struct NetTransport *__thiscall NetStdioEndPoint::Connect(NetStdioEndPoint *this, struct Error *a2)
{
  RunCommand *v2; // eax
  RunCommand *v3; // esi
  NetTcpTransport *v5; // eax
  NetTcpTransport *v6; // esi
  int v7; // edi
  int v8[2]; // [esp+0h] [ebp-14h] BYREF
  StrBuf pMem; // [esp+8h] [ebp-Ch] BYREF

  pMem.size = 0;
  pMem.length = 0;
  pMem.buffer = StrBuf::nullStrBuf;
  if ( &pMem != (StrBuf *)((char *)this + 4) )
  {
    pMem.length = 0;
    StrBuf::Append(this: &pMem, a2: (const struct StrPtr *)((char *)this + 4));
  }
  v2 = (RunCommand *)operator new(nSize: 4u);
  if ( v2 != nullptr )
    v3 = RunCommand::RunCommand(this: v2);
  else
    v3 = nullptr;
  RunCommand::RunChild(this: v3, a2: (struct RunArgs *)&pMem, a3: 1, a4: v8, a5: a2);
  if ( v3 != nullptr )
  {
    RunCommand::~RunCommand(this: v3);
    free(pMem: v3);
  }
  if ( a2->severity <= E_INFO )
  {
    v5 = (NetTcpTransport *)operator new(nSize: 0x2Cu);
    v6 = v5;
    if ( v5 != nullptr )
    {
      v7 = v8[0];
      NetTcpTransport::NetTcpTransport(this: v5, a2: v8[1]);
      *(_DWORD *)v6 = &NetStdioTransport::`vftable';
      *((_DWORD *)v6 + 10) = v7;
    }
    else
    {
      v6 = nullptr;
    }
    if ( pMem.buffer != StrBuf::nullStrBuf )
      free(pMem: pMem.buffer);
    return v6;
  }
  else
  {
    if ( pMem.buffer != StrBuf::nullStrBuf )
      free(pMem: pMem.buffer);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012650
// Name: public: void DiffFlags::Init(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall DiffFlags::Init(DiffFlags *this, const char *a2)
{
  const char *v2; // esi
  char i; // al

  v2 = a2;
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  if ( a2 != nullptr )
  {
    for ( i = *a2; i != 0; ++v2 )
    {
      switch ( i )
      {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
          *((_DWORD *)this + 3) = i + 10 * *((_DWORD *)this + 3) - 48;
          break;
        case 'C':
        case 'c':
          *(_DWORD *)this = 1;
          break;
        case 'G':
        case 'g':
          *((_DWORD *)this + 2) = 1;
          break;
        case 'H':
        case 'h':
          *(_DWORD *)this = 4;
          *((_DWORD *)this + 1) = 1;
          break;
        case 'U':
        case 'u':
          *(_DWORD *)this = 2;
          break;
        case 'b':
          *((_DWORD *)this + 1) = 3;
          break;
        case 'l':
          *((_DWORD *)this + 1) = 2;
          break;
        case 'n':
          *(_DWORD *)this = 3;
          break;
        case 's':
          *(_DWORD *)this = 5;
          break;
        case 'v':
          *(_DWORD *)this = 4;
          *((_DWORD *)this + 1) = 5;
          break;
        case 'w':
          *((_DWORD *)this + 1) = 4;
          break;
        default:
          break;
      }
      i = v2[1];
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10017D00
// Name: private: int Ticket::Init(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall Ticket::Init(Ticket *this)
{
  StrPtrArray *v3; // eax
  StrPtrArray *v4; // edi
  struct FileSys *v5; // eax
  const StrPtr *v6; // ecx
  char v7; // al

  if ( *((_DWORD *)this + 1) != 0 )
    return true;
  if ( *(_DWORD *)this == 0 )
  {
    v3 = (StrPtrArray *)operator new(nSize: 0xCu);
    v4 = v3;
    if ( v3 != nullptr )
      StrPtrArray::StrPtrArray(this: v3);
    else
      v4 = nullptr;
    *(_DWORD *)this = v4;
  }
  if ( *(_DWORD *)(*((_DWORD *)this + 2) + 4) == 0 )
    return true;
  v5 = FileSys::Create(a1: FST_TEXT);
  v6 = *((const StrPtr **)this + 2);
  *((_DWORD *)this + 1) = v5;
  v5->Set(this: v5, a2: v6);
  v7 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 1) + 36))(a1: *((_DWORD *)this + 1));
  return (v7 & 1) != 0 && (v7 & 4) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100279A0
// Name: public: void CUtlMemory<char,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<char,int>::Grow(CUtlMemory<unsigned char,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  unsigned __int8 *m_pMemory; // edx

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
        m_nAllocationCount = 32;
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
    if ( m_pMemory != nullptr )
      this->m_pMemory = (unsigned __int8 *)_g_pMemAlloc->Realloc_2(
                                             this: _g_pMemAlloc,
                                             a2: m_pMemory,
                                             a3: m_nAllocationCount);
    else
      this->m_pMemory = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100282D0
// Name: public: unsigned short CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::NewNode(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this)
{
  int m_FirstFree; // ecx
  int m_nAllocationCount; // eax
  unsigned __int16 index; // cx
  unsigned __int16 v5; // cx
  unsigned __int16 v6; // di
  int v7; // eax
  unsigned __int16 v8; // cx
  unsigned __int16 v9; // cx
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *m_pMemory; // edx
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *v12; // edx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree == 0xFFFF )
  {
    m_nAllocationCount = this->m_Elements.m_nAllocationCount;
    if ( this->m_LastAlloc.index >= m_nAllocationCount )
    {
      m_nAllocationCount = this->m_Elements.m_nAllocationCount;
      v5 = (m_nAllocationCount > 0) - 1;
    }
    else
    {
      index = this->m_LastAlloc.index;
      if ( (unsigned __int16)(index + 1) >= m_nAllocationCount )
        v5 = -1;
      else
        v5 = index + 1;
    }
    v6 = v5;
    if ( v5 >= m_nAllocationCount )
    {
      CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>::Grow(
        this: &this->m_Elements,
        num: 1);
      v7 = this->m_Elements.m_nAllocationCount;
      if ( this->m_LastAlloc.index >= v7 )
      {
        v7 = this->m_Elements.m_nAllocationCount;
        v9 = (v7 > 0) - 1;
      }
      else
      {
        v8 = this->m_LastAlloc.index;
        if ( (unsigned __int16)(v8 + 1) >= v7 )
          v9 = -1;
        else
          v9 = v8 + 1;
      }
      v6 = v9;
      if ( v9 >= v7 )
        _Error(a1: "CUtlRBTree overflow!\n");
    }
    m_pMemory = this->m_Elements.m_pMemory;
    this->m_LastAlloc.index = v6;
    this->m_pElements = m_pMemory;
    return v6;
  }
  else
  {
    v12 = this->m_Elements.m_pMemory;
    this->m_FirstFree = v12[m_FirstFree].m_Right;
    this->m_pElements = v12;
    return m_FirstFree;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100283D0
// Name: public: void CUtlMemory<int,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<int,int>::Grow(CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CUtlSymbolTable::StringPool_t **m_pMemory; // edx
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
      this->m_pMemory = (CUtlSymbolTable::StringPool_t **)_g_pMemAlloc->Realloc_2(
                                                            this: _g_pMemAlloc,
                                                            a2: m_pMemory,
                                                            a3: v7);
    else
      this->m_pMemory = (CUtlSymbolTable::StringPool_t **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10028460
// Name: public: unsigned short CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_1007C88C = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return dword_1007C88C;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x100285E0
// Name: public: unsigned short CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_1007C88C = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
  else
    return this->m_Elements.m_pMemory[i].m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x10028640
// Name: public: unsigned short CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RightChild(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RightChild(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 i)
{
  if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
    dword_1007C88C = 0x1FFFF;
  }
  if ( i == 0xFFFF )
    return HIWORD(`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel);
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x100286B0
// Name: protected: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::FindInsertionPosition(class CUtlSymbolTable::CStringPoolIndex const __near &,unsigned short __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::FindInsertionPosition(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        const CUtlSymbolTable::CStringPoolIndex *insert,
        unsigned __int16 *parent,
        bool *leftchild)
{
  unsigned __int16 m_Root; // di
  int v6; // esi

  m_Root = this->m_Root;
  *parent = -1;
  *leftchild = false;
  while ( m_Root != 0xFFFF )
  {
    *parent = m_Root;
    v6 = m_Root;
    if ( CUtlSymbolTable::CLess::operator()(
           this: &this->m_LessFunc,
           i1: insert,
           i2: &this->m_Elements.m_pMemory[v6].m_Data) )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1007C88C = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1007C88C = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v6].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100287A0
// Name: protected: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateLeft(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateLeft(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v4; // ax
  int v5; // edi
  unsigned __int16 v6; // ax
  int elema; // [esp+14h] [ebp+8h]

  v4 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RightChild(
         this,
         i: elem);
  v5 = v4;
  this->m_Elements.m_pMemory[elem].m_Right = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(
                                               this,
                                               i: v4);
  elema = elem;
  if ( CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(
         this,
         i: v5) != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(
                                 this,
                                 i: v5)].m_Parent = elem;
  if ( (_WORD)v5 != 0xFFFF )
    this->m_Elements.m_pMemory[v5].m_Parent = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v5;
  }
  else
  {
    v6 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(
           this,
           i: v6) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Left = v5;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Right = v5;
  }
  this->m_Elements.m_pMemory[v5].m_Left = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[elema].m_Parent = v5;
}

//------------------------------------------------------------------------------
// Address: 0x100288A0
// Name: protected: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateRight(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateRight(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v4; // ax
  int v5; // edi
  unsigned __int16 v6; // ax
  int elema; // [esp+14h] [ebp+8h]

  v4 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(
         this,
         i: elem);
  v5 = v4;
  this->m_Elements.m_pMemory[elem].m_Left = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RightChild(
                                              this,
                                              i: v4);
  elema = elem;
  if ( CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RightChild(
         this,
         i: v5) != 0xFFFF )
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RightChild(
                                 this,
                                 i: v5)].m_Parent = elem;
  if ( (_WORD)v5 != 0xFFFF )
    this->m_Elements.m_pMemory[v5].m_Parent = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                                                this,
                                                i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = v5;
  }
  else
  {
    v6 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
           this,
           i: elem);
    if ( CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RightChild(
           this,
           i: v6) == elem )
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Right = v5;
    else
      this->m_Elements.m_pMemory[CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                                   this,
                                   i: elem)].m_Left = v5;
  }
  this->m_Elements.m_pMemory[v5].m_Right = elem;
  if ( elem != 0xFFFF )
    this->m_Elements.m_pMemory[elema].m_Parent = v5;
}

//------------------------------------------------------------------------------
// Address: 0x100289A0
// Name: public: unsigned short CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Find(class CUtlSymbolTable::CStringPoolIndex const __near &)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Find(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        const CUtlSymbolTable::CStringPoolIndex *search)
{
  unsigned __int16 m_Root; // bx
  int v4; // esi

  m_Root = this->m_Root;
  if ( m_Root == 0xFFFF )
    return -1;
  do
  {
    v4 = m_Root;
    if ( CUtlSymbolTable::CLess::operator()(
           this: &this->m_LessFunc,
           i1: search,
           i2: &this->m_Elements.m_pMemory[v4].m_Data) )
    {
      if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1007C88C = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( !CUtlSymbolTable::CLess::operator()(
              this: &this->m_LessFunc,
              i1: &this->m_Elements.m_pMemory[v4].m_Data,
              i2: search) )
        return m_Root;
      if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1007C88C = 0x1FFFF;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != 0xFFFF );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x10028AA0
// Name: public: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RemoveAll(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 index; // cx
  unsigned __int16 v3; // di
  int v4; // eax
  unsigned __int16 it; // [esp+4h] [ebp-4h]

  index = this->m_LastAlloc.index;
  if ( index != 0xFFFF )
  {
    v3 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    it = v3;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v3 < this->m_Elements.m_nAllocationCount
          && v3 <= index
          && CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LeftChild(
               this,
               i: it) != v3 )
        {
          v4 = v3;
          this->m_Elements.m_pMemory[v4].m_Right = this->m_FirstFree;
          this->m_Elements.m_pMemory[v4].m_Left = v3;
          this->m_FirstFree = v3;
        }
        index = this->m_LastAlloc.index;
        if ( v3 == index )
          break;
        ++v3;
        if ( (unsigned __int16)(it + 1) >= this->m_Elements.m_nAllocationCount )
          v3 = -1;
        it = v3;
      }
      while ( v3 != 0xFFFF );
    }
    *(_DWORD *)&this->m_Root = 0xFFFF;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10028B70
// Name: protected: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::InsertRebalance(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::InsertRebalance(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  unsigned __int16 v2; // bx
  int v4; // eax
  int *v5; // ecx
  int v6; // ecx
  int *v7; // ecx
  int *v8; // ecx
  unsigned __int16 v9; // di
  int *v10; // ecx
  int v11; // ecx
  int *v12; // edx
  int v13; // edx
  int *v14; // edx
  int *v15; // edx
  unsigned __int16 v16; // dx
  int *v17; // ebx
  int v18; // eax
  int *v19; // edx
  int v20; // edx
  int *v21; // eax
  int *v22; // edx
  int v23; // edx
  int *v24; // ebx
  int *v25; // edx
  int v26; // edx
  int *v27; // eax

  v2 = elem;
  while ( v2 != this->m_Root )
  {
    v4 = `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard';
    if ( (`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
        & 1) == 0 )
    {
      v4 = `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
         | 1;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_1007C88C = 0x1FFFF;
    }
    if ( v2 == 0xFFFF )
      v5 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v5 = (int *)&this->m_Elements.m_pMemory[v2];
    v6 = *((unsigned __int16 *)v5 + 2);
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_1007C88C = 0x1FFFF;
      v4 |= 1u;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
    }
    if ( (_WORD)v6 == 0xFFFF )
      v7 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v7 = (int *)&this->m_Elements.m_pMemory[v6];
    if ( *((_WORD *)v7 + 3) != 0 )
      break;
    if ( (v4 & 1) == 0 )
    {
      v4 |= 1u;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_1007C88C = 0x1FFFF;
    }
    if ( v2 == 0xFFFF )
      v8 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v8 = (int *)&this->m_Elements.m_pMemory[v2];
    v9 = *((_WORD *)v8 + 2);
    if ( (v4 & 1) == 0 )
    {
      v4 |= 1u;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_1007C88C = 0x1FFFF;
    }
    if ( v9 == 0xFFFF )
      v10 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v10 = (int *)&this->m_Elements.m_pMemory[v9];
    v11 = *((unsigned __int16 *)v10 + 2);
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_1007C88C = 0x1FFFF;
      v4 |= 1u;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
    }
    if ( v9 == 0xFFFF )
      v12 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v12 = (int *)&this->m_Elements.m_pMemory[v9];
    v13 = *((unsigned __int16 *)v12 + 2);
    if ( (v4 & 1) == 0 )
    {
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
      dword_1007C88C = 0x1FFFF;
      v4 |= 1u;
      `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
    }
    if ( (_WORD)v13 == 0xFFFF )
      v14 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
    else
      v14 = (int *)&this->m_Elements.m_pMemory[v13];
    if ( *(_WORD *)v14 == v9 )
    {
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1007C88C = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v11 == 0xFFFF )
        v15 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v15 = (int *)&this->m_Elements.m_pMemory[v11];
      v16 = *((_WORD *)v15 + 1);
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1007C88C = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( v16 == 0xFFFF )
        v17 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v17 = (int *)&this->m_Elements.m_pMemory[v16];
      if ( *((_WORD *)v17 + 3) != 0 )
      {
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1007C88C = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        v2 = elem;
        if ( elem == 0xFFFF )
        {
          v19 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        }
        else
        {
          v19 = (int *)&this->m_Elements.m_pMemory[elem];
          v2 = elem;
        }
        v20 = *((unsigned __int16 *)v19 + 2);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1007C88C = 0x1FFFF;
        }
        if ( (_WORD)v20 == 0xFFFF )
          v21 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v21 = (int *)&this->m_Elements.m_pMemory[v20];
        if ( *((_WORD *)v21 + 1) == v2 )
        {
          v2 = v9;
          elem = v9;
          CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateLeft(
            this,
            elem: v9);
          v9 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                 this,
                 i: v9);
          LOWORD(v11) = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                          this,
                          i: v9);
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[(unsigned __int16)v11].m_Tag = 0;
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateRight(
          this,
          elem: v11);
        continue;
      }
      this->m_Elements.m_pMemory[v9].m_Tag = 1;
      v18 = v16;
    }
    else
    {
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1007C88C = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v11 == 0xFFFF )
        v22 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v22 = (int *)&this->m_Elements.m_pMemory[v11];
      v23 = *(unsigned __int16 *)v22;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_1007C88C = 0x1FFFF;
        v4 |= 1u;
        `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
      }
      if ( (_WORD)v23 == 0xFFFF )
        v24 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
      else
        v24 = (int *)&this->m_Elements.m_pMemory[v23];
      if ( *((_WORD *)v24 + 3) != 0 )
      {
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1007C88C = 0x1FFFF;
          v4 |= 1u;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4;
        }
        v2 = elem;
        if ( elem == 0xFFFF )
        {
          v25 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        }
        else
        {
          v25 = (int *)&this->m_Elements.m_pMemory[elem];
          v2 = elem;
        }
        v26 = *((unsigned __int16 *)v25 + 2);
        if ( (v4 & 1) == 0 )
        {
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' = v4 | 1;
          `CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_1007C88C = 0x1FFFF;
        }
        if ( (_WORD)v26 == 0xFFFF )
          v27 = &`CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v27 = (int *)&this->m_Elements.m_pMemory[v26];
        if ( *(_WORD *)v27 == v2 )
        {
          v2 = v9;
          elem = v9;
          CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateRight(
            this,
            elem: v9);
          v9 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                 this,
                 i: v9);
          LOWORD(v11) = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Parent(
                          this,
                          i: v9);
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[(unsigned __int16)v11].m_Tag = 0;
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RotateLeft(
          this,
          elem: v11);
        continue;
      }
      this->m_Elements.m_pMemory[v9].m_Tag = 1;
      v18 = v23;
    }
    this->m_Elements.m_pMemory[v18].m_Tag = 1;
    v2 = v11;
    this->m_Elements.m_pMemory[v11].m_Tag = 0;
    elem = v11;
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x100291A0
// Name: protected: void CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LinkToParent(unsigned short,unsigned short,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LinkToParent(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        unsigned __int16 i,
        unsigned __int16 parent,
        bool isLeft)
{
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *v4; // eax
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *m_pMemory; // eax

  v4 = &this->m_Elements.m_pMemory[i];
  v4->m_Right = -1;
  v4->m_Left = -1;
  v4->m_Parent = parent;
  v4->m_Tag = 0;
  if ( parent == 0xFFFF )
  {
    this->m_Root = i;
    CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::InsertRebalance(
      this,
      elem: i);
  }
  else
  {
    m_pMemory = this->m_Elements.m_pMemory;
    if ( isLeft )
      m_pMemory[parent].m_Left = i;
    else
      m_pMemory[parent].m_Right = i;
    CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::InsertRebalance(
      this,
      elem: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100292A0
// Name: public: CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::~CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this)
{
  CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::RemoveAll(this);
  this->m_FirstFree = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
  this->m_LastAlloc.index = -1;
  if ( this->m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_pMemory);
      this->m_Elements.m_pMemory = nullptr;
    }
    this->m_Elements.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10029310
// Name: public: unsigned short CUtlRBTree<class CUtlSymbolTable::CStringPoolIndex,unsigned short,class CUtlSymbolTable::CLess,class CUtlMemory<struct UtlRBTreeNode_t<class CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Insert(class CUtlSymbolTable::CStringPoolIndex const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::Insert(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *this,
        const CUtlSymbolTable::CStringPoolIndex *insert)
{
  unsigned __int16 v3; // ax
  int v4; // edi
  UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *m_pMemory; // edx
  int parent; // [esp+Ch] [ebp-8h] BYREF
  BOOL leftchild; // [esp+10h] [ebp-4h] BYREF

  parent = 0xFFFF;
  LOBYTE(leftchild) = 0;
  CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::FindInsertionPosition(
    this,
    insert,
    (unsigned __int16 *)&parent,
    (bool *)&leftchild);
  v3 = CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::NewNode(this);
  v4 = v3;
  CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::LinkToParent(
    this,
    i: v3,
    parent,
    isLeft: leftchild);
  m_pMemory = this->m_Elements.m_pMemory;
  ++this->m_NumElements;
  if ( &m_pMemory[v4] != (UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *)-8 )
    m_pMemory[v4].m_Data = *insert;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1003F8A0
// Name: _CP4::GetFileList_::_5_::_dynamic_atexit_destructor_for__dummy__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CP4::GetFileList_::_5_::_dynamic_atexit_destructor_for__dummy__()
{
  CUtlVector<CClientPathRecord,CUtlMemory<CClientPathRecord,int>>::~CUtlVector<CClientPathRecord,CUtlMemory<CClientPathRecord,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&dummy_0);
}

//------------------------------------------------------------------------------
// Address: 0x1003F8B0
// Name: _CP4::GetFileListUsingClientSpec_::_5_::_dynamic_atexit_destructor_for__dummy__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CP4::GetFileListUsingClientSpec_::_5_::_dynamic_atexit_destructor_for__dummy__()
{
  CUtlVector<CClientPathRecord,CUtlMemory<CClientPathRecord,int>>::~CUtlVector<CClientPathRecord,CUtlMemory<CClientPathRecord,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&dummy_1);
}

//------------------------------------------------------------------------------
// Address: 0x1003F8C0
// Name: _CP4::GetClientList_::_5_::_dynamic_atexit_destructor_for__dummy__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CP4::GetClientList_::_5_::_dynamic_atexit_destructor_for__dummy__()
{
  CUtlVector<CClientPathRecord,CUtlMemory<CClientPathRecord,int>>::~CUtlVector<CClientPathRecord,CUtlMemory<CClientPathRecord,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&dummy);
}

//------------------------------------------------------------------------------
// Address: 0x1003F980
// Name: _CP4::GetRevisionList_::_5_::_dynamic_atexit_destructor_for__dummy__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CP4::GetRevisionList_::_5_::_dynamic_atexit_destructor_for__dummy__()
{
  CUtlVector<P4Revision_t,CUtlMemory<P4Revision_t,int>>::~CUtlVector<P4Revision_t,CUtlMemory<P4Revision_t,int>>(this: &dummy_2);
}

//------------------------------------------------------------------------------
// Address: 0x10001200
// Name: __CreateCP4IP4_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CP4 *__cdecl _CreateCP4IP4_interface()
{
  return &s_p4;
}

//------------------------------------------------------------------------------
// Address: 0x10007420
// Name: public: virtual void PathNT::SetCharSet(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall PathNT::SetCharSet(PathNT *this, int a2)
{
  *((_DWORD *)this + 4) = a2;
}

//------------------------------------------------------------------------------
// Address: 0x100082A0
// Name: public: int Rpc::Dropped(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall Rpc::Dropped(Rpc *this)
{
  int result; // eax

  result = 1;
  if ( *((int *)this + 16) <= 1 && (*((_DWORD *)this + 7) != 0 || *((int *)this + 13) <= 1) )
    return 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100082E0
// Name: public: virtual ClientApi::~ClientApi(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall ClientApi::~ClientApi(ClientApi *this)
{
  struct Client *client; // ecx

  client = this->client;
  this->__vftable = (ClientApi_vtbl *)&ClientApi::`vftable';
  if ( client != nullptr )
    (**(void (__thiscall ***)(struct Client *, int))client)(a1: client, a2: 1);
  StrDict::~StrDict(this);
}

//------------------------------------------------------------------------------
// Address: 0x10008310
// Name: public: void ClientApi::Run(char const __near *,class ClientUser __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall ClientApi::Run(ClientApi *this, const char *a2, struct ClientUser *a3)
{
  Client::Run(this: this->client, src: a2, a3);
}

//------------------------------------------------------------------------------
// Address: 0x10008320
// Name: public: int ClientApi::Final(class Error __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall ClientApi::Final(ClientApi *this, struct Error *a2)
{
  return Client::Final(this: this->client, a2);
}

//------------------------------------------------------------------------------
// Address: 0x10008330
// Name: public: int ClientApi::Dropped(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall ClientApi::Dropped(ClientApi *this)
{
  struct Client *client; // eax

  client = this->client;
  return *((int *)client + 16) > 1 || *((_DWORD *)client + 7) == 0 && *((int *)client + 13) > 1;
}

//------------------------------------------------------------------------------
// Address: 0x10008350
// Name: private: virtual class StrPtr __near * ClientApi::VGetVar(class StrPtr const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct StrPtr *__thiscall ClientApi::VGetVar(ClientApi *this, const struct StrPtr *a2)
{
  return (*(struct StrPtr *(__thiscall **)(_DWORD, const struct StrPtr *))(**((_DWORD **)this->client + 52) + 4))(
           a1: *((_DWORD *)this->client + 52),
           a2);
}

//------------------------------------------------------------------------------
// Address: 0x10008360
// Name: private: virtual void ClientApi::VSetVar(class StrPtr const __near &,class StrPtr const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall ClientApi::VSetVar(ClientApi *this, const struct StrPtr *a2, const struct StrPtr *a3)
{
  (*(void (__thiscall **)(_DWORD, const struct StrPtr *, const struct StrPtr *))(**((_DWORD **)this->client + 52) + 8))(
    a1: *((_DWORD *)this->client + 52),
    a2,
    a3);
}

//------------------------------------------------------------------------------
// Address: 0x10008370
// Name: public: void ClientApi::SetClient(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall ClientApi::SetClient(ClientApi *this, const char *a2)
{
  StrBuf *v2; // ecx

  v2 = (StrBuf *)((char *)this->client + 308);
  v2->length = 0;
  StrBuf::Append(this: v2, src: a2);
}

//------------------------------------------------------------------------------
// Address: 0x10008390
// Name: public: class StrPtr const __near & ClientApi::GetClient(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const struct StrPtr *__thiscall ClientApi::GetClient(ClientApi *this)
{
  return Client::GetClient(this: this->client);
}

//------------------------------------------------------------------------------
// Address: 0x100083A0
// Name: public: ClientApi::ClientApi(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientApi *__thiscall ClientApi::ClientApi(ClientApi *this)
{
  Client *v2; // eax

  this->__vftable = (ClientApi_vtbl *)&ClientApi::`vftable';
  v2 = (Client *)operator new(nSize: 0x208u);
  if ( v2 != nullptr )
    this->client = Client::Client(this: v2);
  else
    this->client = nullptr;
  this->ui = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10008420
// Name: public: void ClientApi::SetProtocol(char const __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall ClientApi::SetProtocol(ClientApi *this, char *a2, char *a3)
{
  struct Client *client; // ecx
  struct StrRef v4; // [esp+8h] [ebp-8h] BYREF

  client = this->client;
  v4.length = strlen(a3);
  v4.buffer = a3;
  RpcService::SetProtocol(this: (struct Client *)((char *)client + 276), a2, a3: &v4);
}

//------------------------------------------------------------------------------
// Address: 0x10008470
// Name: public: void Client::WaitTag(class ClientUser __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall Client::WaitTag(Client *this, struct ClientUser *a2)
{
  int v3; // eax
  struct ClientUser *v4; // edi
  int v5; // ecx

  if ( *((_DWORD *)this + 66) != *((_DWORD *)this + 67) )
  {
    do
    {
      Rpc::Dispatch(a1: this, a2: 0, a3: *(_DWORD *)(*((_DWORD *)this + 1) + 4));
      v3 = *((_DWORD *)this + 66);
      *((_DWORD *)this + 68) = 1;
      v4 = *((struct ClientUser **)this + v3 + 62);
      v4->Finished(this: v4);
      v5 = (*((_DWORD *)this + 66) + 1) % 4;
      *((_DWORD *)this + 66) = v5;
    }
    while ( a2 != v4 && v5 != *((_DWORD *)this + 67) );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100084F0
// Name: public: int Client::Final(class Error __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall Client::Final(StrDict *this, struct Error *a2)
{
  char *v3; // eax

  Rpc::ReleaseFinal(this);
  Rpc::Disconnect((Rpc *)this);
  if ( a2->severity > E_INFO )
    return true;
  v3 = (char *)(this + 13);
  if ( *((int *)this + 13) <= 1 )
    v3 = (char *)(this + 16);
  Error::operator=(a1: v3);
  return a2->severity > E_INFO || *((_DWORD *)this + 73) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10008540
// Name: public: void Client::GetEnv(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall Client::GetEnv(StrDict **this)
{
  const struct StrPtr *Language; // edi
  const struct StrPtr *Client; // eax
  const struct StrPtr *Cwd; // eax
  const struct StrPtr *Host; // eax
  const struct StrPtr *Os; // eax
  const struct StrPtr *User; // eax

  Language = Client::GetLanguage((Client *)this);
  Client = Client::GetClient((Client *)this);
  StrDict::SetVar(this: *(this + 52), a2: "client", a3: Client);
  Cwd = Client::GetCwd((Client *)this);
  StrDict::SetVar(this: *(this + 52), a2: "cwd", a3: Cwd);
  Host = Client::GetHost((Client *)this);
  StrDict::SetVar((StrDict *)this, a2: "host", a3: Host);
  if ( Language->length != 0 )
    StrDict::SetVar(this: *(this + 52), a2: "language", a3: Language);
  Os = Client::GetOs((Client *)this);
  StrDict::SetVar((StrDict *)this, a2: "os", a3: Os);
  User = Client::GetUser((Client *)this);
  StrDict::SetVar(this: *(this + 52), a2: "user", a3: User);
  if ( *(this + 118) != nullptr )
    StrDict::SetVar((StrDict *)this, a2: "unicode");
}

//------------------------------------------------------------------------------
// Address: 0x100085F0
// Name: public: void Client::Confirm(class StrPtr const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall Client::Confirm(StrDict *this, const struct StrPtr *a2)
{
  if ( *((int *)this + 57) < 6 )
    Client::GetEnv((StrDict **)this);
  Rpc::CopyVars((Rpc *)this);
  Rpc::Invoke(this, a2: a2->buffer);
}

//------------------------------------------------------------------------------
// Address: 0x10008620
// Name: public: void Client::NewHandler(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall Client::NewHandler(Client *this)
{
  Client *v2; // ecx
  Client *v3; // ecx

  v2 = *((Client **)this + 52);
  if ( v2 != this )
    (*(void (__thiscall **)(Client *))(*(_DWORD *)v2 + 24))(a1: v2);
  v3 = *((Client **)this + 53);
  if ( v3 != this && v3 != *((Client **)this + 52) )
    (*(void (__thiscall **)(Client *))(*(_DWORD *)v3 + 24))(a1: v3);
}

//------------------------------------------------------------------------------
// Address: 0x10008650
// Name: public: virtual void Client::VSetVar(class StrPtr const __near &,class StrPtr const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall Client::VSetVar(StrDict *this, const struct StrPtr *a2, const struct StrPtr *a3)
{
  StrDict *v4; // ecx

  v4 = *((StrDict **)this + 52);
  if ( v4 != this )
    StrDict::RemoveVar(this: v4, a2: a2->buffer);
  Rpc::VSetVar((Rpc *)this, a2, a3);
}

//------------------------------------------------------------------------------
// Address: 0x10008680
// Name: public: virtual Client::~Client(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall Client::~Client(StrDict *this)
{
  void *v2; // edi

  this->__vftable = (StrDict_vtbl *)&Client::`vftable';
  Client::CleanupTrans((Client *)this);
  v2 = *((void **)this + 116);
  if ( v2 != nullptr )
  {
    Enviro::~Enviro(this: *((Enviro **)this + 116));
    free(pMem: v2);
  }
  if ( *((char **)this + 119) != StrBuf::nullStrBuf )
    free(pMem: *((void **)this + 119));
  if ( *((char **)this + 113) != StrBuf::nullStrBuf )
    free(pMem: *((void **)this + 113));
  if ( *((char **)this + 110) != StrBuf::nullStrBuf )
    free(pMem: *((void **)this + 110));
  if ( *((char **)this + 107) != StrBuf::nullStrBuf )
    free(pMem: *((void **)this + 107));
  if ( *((char **)this + 104) != StrBuf::nullStrBuf )
    free(pMem: *((void **)this + 104));
  if ( *((char **)this + 101) != StrBuf::nullStrBuf )
    free(pMem: *((void **)this + 101));
  if ( *((char **)this + 98) != StrBuf::nullStrBuf )
    free(pMem: *((void **)this + 98));
  if ( *((char **)this + 95) != StrBuf::nullStrBuf )
    free(pMem: *((void **)this + 95));
  if ( *((char **)this + 92) != StrBuf::nullStrBuf )
    free(pMem: *((void **)this + 92));
  if ( *((char **)this + 89) != StrBuf::nullStrBuf )
    free(pMem: *((void **)this + 89));
  if ( *((char **)this + 86) != StrBuf::nullStrBuf )
    free(pMem: *((void **)this + 86));
  if ( *((char **)this + 83) != StrBuf::nullStrBuf )
    free(pMem: *((void **)this + 83));
  if ( *((char **)this + 80) != StrBuf::nullStrBuf )
    free(pMem: *((void **)this + 80));
  if ( *((char **)this + 77) != StrBuf::nullStrBuf )
    free(pMem: *((void **)this + 77));
  if ( *((char **)this + 74) != StrBuf::nullStrBuf )
    free(pMem: *((void **)this + 74));
  RpcService::~RpcService(this: (RpcService *)(this + 69));
  Handlers::~Handlers(this: (Handlers *)(this + 32));
  Rpc::~Rpc(this);
}

//------------------------------------------------------------------------------
// Address: 0x10008980
// Name: public: void Client::RunTag(char const __near *,class ClientUser __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall Client::RunTag(Client *this, char *src, struct ClientUser *a3)
{
  const char *v4; // edi
  int v5; // edi
  int v6; // eax
  bool v7; // zf
  StrBuf pMem; // [esp+4h] [ebp-Ch] BYREF

  *((_DWORD *)this + *((_DWORD *)this + 67) + 62) = a3;
  if ( a3 != nullptr )
  {
    a3->varList = (StrDict *)this;
    a3->enviro = *((struct Enviro **)this + 116);
    if ( *((_DWORD *)this + 55) != 0 )
      a3->SetOutputCharset(this: a3, a2: *((_DWORD *)this + 55));
  }
  v4 = src;
  pMem.size = 0;
  pMem.length = 0;
  pMem.buffer = StrBuf::nullStrBuf;
  if ( src == nullptr )
    v4 = "help";
  StrBuf::Append(this: &pMem, src: "user-");
  StrBuf::Append(this: &pMem, src: v4);
  Client::GetEnv((StrDict **)this);
  Rpc::Invoke((StrDict *)this, a2: pMem.buffer);
  v5 = (*((_DWORD *)this + 67) + 1) % 4;
  v6 = *((_DWORD *)this + 66);
  if ( v5 == v6 )
    Client::WaitTag(this, a2: *((struct ClientUser **)this + v6 + 62));
  v7 = *((_DWORD *)this + 68) == 0;
  *((_DWORD *)this + 67) = v5;
  if ( v7 )
    Client::WaitTag(this, a2: nullptr);
  if ( pMem.buffer != StrBuf::nullStrBuf )
    free(pMem: pMem.buffer);
}

//------------------------------------------------------------------------------
// Address: 0x10008A70
// Name: public: Client::Client(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
Client *__thiscall Client::Client(Client *this)
{
  RpcService *v2; // edi
  Enviro *v3; // eax
  Enviro *v4; // eax
  const struct StrPtr *Cwd; // eax
  struct StrRef v7; // [esp+Ch] [ebp-8h] BYREF

  v2 = (Client *)((char *)this + 276);
  Rpc::Rpc(this, a2: (Client *)((char *)this + 276));
  *(_DWORD *)this = &Client::`vftable';
  Handlers::Handlers(this: (Client *)((char *)this + 128));
  RpcService::RpcService(this: v2);
  *((_DWORD *)this + 76) = 0;
  *((_DWORD *)this + 75) = 0;
  *((_DWORD *)this + 74) = StrBuf::nullStrBuf;
  *((_DWORD *)this + 79) = 0;
  *((_DWORD *)this + 78) = 0;
  *((_DWORD *)this + 77) = StrBuf::nullStrBuf;
  *((_DWORD *)this + 82) = 0;
  *((_DWORD *)this + 81) = 0;
  *((_DWORD *)this + 80) = StrBuf::nullStrBuf;
  *((_DWORD *)this + 85) = 0;
  *((_DWORD *)this + 84) = 0;
  *((_DWORD *)this + 83) = StrBuf::nullStrBuf;
  *((_DWORD *)this + 88) = 0;
  *((_DWORD *)this + 87) = 0;
  *((_DWORD *)this + 86) = StrBuf::nullStrBuf;
  *((_DWORD *)this + 91) = 0;
  *((_DWORD *)this + 90) = 0;
  *((_DWORD *)this + 89) = StrBuf::nullStrBuf;
  *((_DWORD *)this + 94) = 0;
  *((_DWORD *)this + 93) = 0;
  *((_DWORD *)this + 92) = StrBuf::nullStrBuf;
  *((_DWORD *)this + 97) = 0;
  *((_DWORD *)this + 96) = 0;
  *((_DWORD *)this + 95) = StrBuf::nullStrBuf;
  *((_DWORD *)this + 100) = 0;
  *((_DWORD *)this + 99) = 0;
  *((_DWORD *)this + 98) = StrBuf::nullStrBuf;
  *((_DWORD *)this + 103) = 0;
  *((_DWORD *)this + 102) = 0;
  *((_DWORD *)this + 101) = StrBuf::nullStrBuf;
  *((_DWORD *)this + 106) = 0;
  *((_DWORD *)this + 105) = 0;
  *((_DWORD *)this + 104) = StrBuf::nullStrBuf;
  *((_DWORD *)this + 109) = 0;
  *((_DWORD *)this + 108) = 0;
  *((_DWORD *)this + 107) = StrBuf::nullStrBuf;
  *((_DWORD *)this + 112) = 0;
  *((_DWORD *)this + 111) = 0;
  *((_DWORD *)this + 110) = StrBuf::nullStrBuf;
  *((_DWORD *)this + 115) = 0;
  *((_DWORD *)this + 114) = 0;
  *((_DWORD *)this + 113) = StrBuf::nullStrBuf;
  *((_DWORD *)this + 121) = 0;
  *((_DWORD *)this + 120) = 0;
  *((_DWORD *)this + 119) = StrBuf::nullStrBuf;
  *((_DWORD *)this + 49) = 0;
  *((_DWORD *)this + 48) = 0;
  *((_DWORD *)this + 51) = 0;
  *((_DWORD *)this + 50) = 0;
  *((_DWORD *)this + 52) = this;
  *((_DWORD *)this + 53) = this;
  *((_DWORD *)this + 73) = 0;
  *((_DWORD *)this + 118) = 0;
  *((_DWORD *)this + 54) = 0;
  *((_DWORD *)this + 55) = 0;
  v3 = (Enviro *)operator new(nSize: 0x28u);
  if ( v3 != nullptr )
    v4 = Enviro::Enviro(this: v3);
  else
    v4 = nullptr;
  *((_DWORD *)this + 116) = v4;
  *((_DWORD *)this + 67) = 0;
  *((_DWORD *)this + 66) = 0;
  *((_DWORD *)this + 68) = 0;
  *((_DWORD *)this + 117) = 0;
  *((_DWORD *)this + 56) = -1;
  *((_DWORD *)this + 57) = 0;
  *((_DWORD *)this + 58) = 0;
  *((_DWORD *)this + 59) = 0;
  *((_DWORD *)this + 60) = 0;
  Cwd = Client::GetCwd(this);
  Enviro::Config(this: *((Enviro **)this + 116), a2: Cwd);
  RpcService::Dispatcher(this: v2, a2: (const struct RpcDispatch *)&clientDispatch);
  v7 = (struct StrRef)StrRef::null;
  RpcService::SetProtocol(this: v2, a2: "cmpfile", a3: &v7);
  v7.length = strlen("64");
  v7.buffer = "64";
  RpcService::SetProtocol(this: v2, a2: "client", a3: &v7);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10008CF0
// Name: public: void Client::Run(char const __near *,class ClientUser __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall Client::Run(Client *this, char *src, struct ClientUser *a3)
{
  Client::RunTag(this, src, a3);
  Client::WaitTag(this, a2: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10008D20
// Name: private: void Client::CleanupTrans(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall Client::CleanupTrans(Client *this)
{
  Client *v2; // ecx
  Client *v3; // ecx
  void (__thiscall ***v4)(_DWORD, int); // ecx
  void (__thiscall ***v5)(_DWORD, int); // ecx
  void (__thiscall ***v6)(_DWORD, int); // ecx
  void (__thiscall ***v7)(_DWORD, int); // ecx
  Enviro *v8; // ecx

  v2 = *((Client **)this + 53);
  if ( v2 != this && v2 != *((Client **)this + 52) && v2 != nullptr )
    (**(void (__thiscall ***)(Client *, int))v2)(a1: v2, a2: 1);
  v3 = *((Client **)this + 52);
  if ( v3 != this && v3 != nullptr )
    (**(void (__thiscall ***)(Client *, int))v3)(a1: v3, a2: 1);
  v4 = *((void (__thiscall ****)(_DWORD, int))this + 50);
  if ( v4 != *((void (__thiscall ****)(_DWORD, int))this + 48) && v4 != nullptr )
    (**v4)(a1: v4, a2: 1);
  v5 = *((void (__thiscall ****)(_DWORD, int))this + 51);
  if ( v5 != *((void (__thiscall ****)(_DWORD, int))this + 49) && v5 != nullptr )
    (**v5)(a1: v5, a2: 1);
  v6 = *((void (__thiscall ****)(_DWORD, int))this + 48);
  if ( v6 != nullptr )
    (**v6)(a1: v6, a2: 1);
  v7 = *((void (__thiscall ****)(_DWORD, int))this + 49);
  if ( v7 != nullptr )
    (**v7)(a1: v7, a2: 1);
  v8 = *((Enviro **)this + 116);
  *((_DWORD *)this + 49) = 0;
  *((_DWORD *)this + 48) = 0;
  *((_DWORD *)this + 51) = 0;
  *((_DWORD *)this + 50) = 0;
  *((_DWORD *)this + 52) = this;
  *((_DWORD *)this + 53) = this;
  *((_DWORD *)this + 118) = 0;
  *((_DWORD *)this + 54) = 0;
  *((_DWORD *)this + 55) = 0;
  Enviro::SetCharSet(this: v8, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10008E00
// Name: public: class StrBuf const __near & StrBuf::operator=(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
StrBuf *__thiscall StrBuf::operator=(StrBuf *this, char *src)
{
  if ( this != (StrBuf *)src && this->buffer != src )
  {
    this->length = 0;
    StrBuf::Append(this, src);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10008E30
// Name: public: class StrPtr const __near & Client::GetCwd(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const struct StrPtr *__thiscall Client::GetCwd(Client *this)
{
  char v3; // [esp+7h] [ebp-1h] BYREF

  if ( *((_DWORD *)this + 81) == 0 )
    HostEnv::GetCwd(this: (HostEnv *)&v3, a2: (StrBuf *)((char *)this + 320), a3: *((struct Enviro **)this + 116));
  return (const struct StrPtr *)((char *)this + 320);
}

//------------------------------------------------------------------------------
// Address: 0x10008E60
// Name: public: class StrPtr const __near & Client::GetHost(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const struct StrPtr *__thiscall Client::GetHost(Client *this)
{
  const char *v3; // eax
  const struct StrPtr *Address; // eax
  char v5; // [esp+7h] [ebp-1h] BYREF

  if ( *((_DWORD *)this + 84) != 0 )
    return (const struct StrPtr *)((char *)this + 332);
  v3 = Enviro::Get(this: *((Enviro **)this + 116), a2: "P4HOST");
  if ( v3 != nullptr )
  {
    *((_DWORD *)this + 84) = 0;
    StrBuf::Append(this: (StrBuf *)((char *)this + 332), src: v3);
    return (const struct StrPtr *)((char *)this + 332);
  }
  if ( HostEnv::GetHost(this: (HostEnv *)&v5, a2: (struct StrBuf *)((char *)this + 332)) == 0 )
  {
    Address = Rpc::GetAddress(this, a2: 1);
    if ( Address != nullptr )
    {
      *((_DWORD *)this + 84) = 0;
      StrBuf::Append(this: (StrBuf *)((char *)this + 332), a2: Address);
      return (const struct StrPtr *)((char *)this + 332);
    }
    *((_DWORD *)this + 84) = 0;
    StrBuf::Append(this: (StrBuf *)((char *)this + 332), src: "nohost");
  }
  return (const struct StrPtr *)((char *)this + 332);
}

//------------------------------------------------------------------------------
// Address: 0x10008EF0
// Name: public: class StrPtr const __near & Client::GetOs(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
StrBuf *__thiscall Client::GetOs(Client *this)
{
  const char *OS; // eax
  StrBuf *v4; // esi

  if ( *((_DWORD *)this + 87) != 0 )
    return (StrBuf *)((char *)this + 344);
  OS = PathSys::GetOS();
  v4 = (StrBuf *)((char *)this + 344);
  v4->length = 0;
  StrBuf::Append(this: v4, src: OS);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10008F30
// Name: public: class StrPtr const __near & Client::GetPassword2(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const struct StrPtr *__thiscall Client::GetPassword2(Client *this)
{
  return (const struct StrPtr *)((char *)this + 404);
}

//------------------------------------------------------------------------------
// Address: 0x10008F40
// Name: public: class StrPtr const __near & Client::GetPort(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
StrBuf *__thiscall Client::GetPort(Client *this)
{
  const char *v3; // eax
  StrBuf *v4; // esi

  if ( *((_DWORD *)this + 90) != 0 )
    return (StrBuf *)((char *)this + 356);
  v3 = Enviro::Get(this: *((Enviro **)this + 116), a2: "P4PORT");
  v4 = (StrBuf *)((char *)this + 356);
  v4->length = 0;
  if ( v3 != nullptr )
    StrBuf::Append(this: v4, src: v3);
  else
    StrBuf::Append(this: v4, src: "perforce:1666");
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10008F90
// Name: public: class StrPtr const __near & Client::GetUser(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const struct StrPtr *__thiscall Client::GetUser(Client *this)
{
  const char *v2; // eax
  unsigned __int8 *v3; // eax
  unsigned __int8 **v4; // esi
  _BYTE *v5; // eax
  char v7; // [esp+7h] [ebp-1h] BYREF

  if ( *((_DWORD *)this + 96) == 0 )
  {
    v2 = Enviro::Get(this: *((Enviro **)this + 116), a2: "P4USER");
    if ( v2 != nullptr )
    {
      *((_DWORD *)this + 96) = 0;
      StrBuf::Append(this: (StrBuf *)((char *)this + 380), src: v2);
    }
    else if ( HostEnv::GetUser(
                this: (HostEnv *)&v7,
                a2: (StrBuf *)((char *)this + 380),
                a3: *((struct Enviro **)this + 116)) == 0 )
    {
      *((_DWORD *)this + 96) = 0;
      StrBuf::Append(this: (StrBuf *)((char *)this + 380), src: "nouser");
    }
  }
  v3 = *((unsigned __int8 **)this + 95);
  v4 = (unsigned __int8 **)((char *)this + 380);
  strchr(string: v3, chr: 0x20u);
  while ( v5 != nullptr )
  {
    *v5 = 95;
    strchr(string: *v4, chr: 0x20u);
  }
  return (const struct StrPtr *)v4;
}

//------------------------------------------------------------------------------
// Address: 0x10009030
// Name: public: class StrPtr const __near & Client::GetTicketFile(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const struct StrPtr *__thiscall Client::GetTicketFile(Client *this)
{
  const char *v2; // eax
  char v4; // [esp+7h] [ebp-1h] BYREF

  if ( *((_DWORD *)this + 108) == 0 )
  {
    v2 = Enviro::Get(this: *((Enviro **)this + 116), a2: "P4TICKETS");
    if ( v2 != nullptr )
    {
      *((_DWORD *)this + 108) = 0;
      StrBuf::Append(this: (StrBuf *)((char *)this + 428), src: v2);
      return (const struct StrPtr *)((char *)this + 428);
    }
    HostEnv::GetTicketFile(
      this: (HostEnv *)&v4,
      a2: (StrBuf *)((char *)this + 428),
      a3: *((struct Enviro **)this + 116));
  }
  return (const struct StrPtr *)((char *)this + 428);
}

//------------------------------------------------------------------------------
// Address: 0x10009090
// Name: public: class StrPtr const __near & Client::GetLoginSSO(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const struct StrPtr *__thiscall Client::GetLoginSSO(Enviro **this)
{
  const char *v2; // eax
  StrBuf *v3; // ecx

  if ( *(this + 114) == nullptr )
  {
    v2 = Enviro::Get(this: *(this + 116), a2: "P4LOGINSSO");
    v3 = (StrBuf *)(this + 113);
    *(this + 114) = nullptr;
    if ( v2 != nullptr )
    {
      StrBuf::Append(this: v3, src: v2);
      return (const struct StrPtr *)(this + 113);
    }
    StrBuf::Append(this: v3, src: "unset");
  }
  return (const struct StrPtr *)(this + 113);
}

//------------------------------------------------------------------------------
// Address: 0x100090E0
// Name: public: void Client::DefinePassword(char const __near *,class Error __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall Client::DefinePassword(Client *this, char *src, struct Error *a3)
{
  Enviro::Set(this: *((Enviro **)this + 116), lpValueName: "P4PASSWD", lpData: (BYTE *)src, a4: a3);
  *((_DWORD *)this + 99) = 0;
  StrBuf::Append(this: (StrBuf *)((char *)this + 392), src);
  *((_DWORD *)this + 68) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10009120
// Name: public: class StrPtr const __near & Client::GetClient(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
StrBuf *__thiscall Client::GetClient(Client *this)
{
  const char *v3; // eax
  StrBuf *v4; // esi
  const struct StrPtr *Host; // eax
  StrBuf *v6; // esi
  int v7; // eax
  const char *buffer; // [esp-8h] [ebp-Ch]
  int v9; // [esp-4h] [ebp-8h]

  if ( *((_DWORD *)this + 78) != 0 )
    return (StrBuf *)((char *)this + 308);
  v3 = Enviro::Get(this: *((Enviro **)this + 116), a2: "P4CLIENT");
  if ( v3 != nullptr )
  {
    v4 = (StrBuf *)((char *)this + 308);
    v4->length = 0;
    StrBuf::Append(this: v4, src: v3);
    return v4;
  }
  else
  {
    Host = Client::GetHost(this);
    v6 = (StrBuf *)((char *)this + 308);
    v6->length = 0;
    StrBuf::Append(this: v6, a2: Host);
    strchr(string: (unsigned __int8 *)v6->buffer, chr: 0x2Eu);
    if ( v7 != 0 )
    {
      v9 = v7 - (unsigned int)v6->buffer;
      buffer = v6->buffer;
      v6->length = 0;
      StrBuf::Append(this: v6, src: buffer, a3: v9);
    }
    return v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100091B0
// Name: public: class StrPtr const __near & Client::GetLanguage(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const struct StrPtr *__thiscall Client::GetLanguage(Enviro **this)
{
  const char *v2; // eax
  StrBuf *v3; // ecx

  if ( *(this + 105) == nullptr )
  {
    v2 = Enviro::Get(this: *(this + 116), a2: "P4LANGUAGE");
    if ( v2 != nullptr )
    {
      v3 = (StrBuf *)(this + 104);
      if ( this + 104 != (Enviro **)v2 && v3->buffer != v2 )
      {
        *(this + 105) = nullptr;
        StrBuf::Append(this: v3, src: v2);
      }
    }
  }
  return (const struct StrPtr *)(this + 104);
}

//------------------------------------------------------------------------------
// Address: 0x10009200
// Name: public: class StrPtr const __near & Client::GetPassword(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const struct StrPtr *__usercall Client::GetPassword@<eax>(Client *this@<ecx>, int a2@<edi>)
{
  _DWORD *v4; // ebx
  int v5; // eax
  int Cvt; // edi
  char *v7; // eax
  const struct StrPtr *TicketFile; // eax
  const char *Ticket; // eax
  StrBuf *v10; // ecx
  const struct StrPtr *v11; // eax
  const char *v12; // eax
  StrBuf *v13; // ecx
  char *v14; // edi
  StrBuf *v15; // ecx
  char *v16; // esi
  StrBuf pMem; // [esp+10h] [ebp-18h] BYREF
  _BYTE v19[12]; // [esp+1Ch] [ebp-Ch] BYREF

  if ( *((_DWORD *)this + 99) != 0 )
    return (const struct StrPtr *)((char *)this + 392);
  v4 = (_DWORD *)((char *)this + 380);
  pMem.size = 0;
  pMem.length = 0;
  pMem.buffer = StrBuf::nullStrBuf;
  if ( &pMem != (StrBuf *)((char *)this + 380) )
  {
    pMem.length = 0;
    StrBuf::Append(this: &pMem, a2: (const struct StrPtr *)((char *)this + 380));
  }
  v5 = *((_DWORD *)this + 55);
  if ( v5 != 0 )
  {
    Cvt = CharSetCvt::FindCvt(a1: v5, a2: 1);
    if ( Cvt != 0 )
    {
      v7 = (char *)(*(int (__thiscall **)(int, _DWORD, _DWORD, _DWORD, int))(*(_DWORD *)Cvt + 28))(
                     a1: Cvt,
                     a2: *v4,
                     a3: *((_DWORD *)this + 96),
                     a4: 0,
                     a5: a2);
      if ( v7 != nullptr )
        StrBuf::operator=(this: (StrBuf *)&pMem.length, src: v7);
      (**(void (__thiscall ***)(int, int))Cvt)(a1: Cvt, a2: 1);
    }
  }
  if ( *((_DWORD *)this + 58) != 0 )
    StrOps::Lower(a1: &pMem);
  if ( *((_DWORD *)this + 93) != 0 )
  {
    TicketFile = Client::GetTicketFile(this);
    Ticket::Ticket(this: (Ticket *)v19, a2: TicketFile);
    Ticket = Ticket::GetTicket(this: (Ticket *)v19, a2: (struct StrPtr *)this + 46, a3: &pMem);
    if ( Ticket != nullptr )
    {
      v10 = (StrBuf *)((char *)this + 392);
      if ( (char *)this + 392 != Ticket && v10->buffer != Ticket )
      {
        *((_DWORD *)this + 99) = 0;
        StrBuf::Append(this: v10, src: Ticket);
      }
    }
    Ticket::~Ticket(this: (Ticket *)v19);
  }
  if ( *((_DWORD *)this + 99) == 0 )
  {
    v11 = Client::GetTicketFile(this);
    Ticket::Ticket(this: (Ticket *)v19, a2: v11);
    v12 = Ticket::GetTicket(this: (Ticket *)v19, a2: (struct StrPtr *)((char *)this + 356), a3: &pMem);
    if ( v12 != nullptr )
    {
      v13 = (StrBuf *)((char *)this + 392);
      if ( (char *)this + 392 != v12 && v13->buffer != v12 )
      {
        *((_DWORD *)this + 99) = 0;
        StrBuf::Append(this: v13, src: v12);
      }
    }
    Ticket::~Ticket(this: (Ticket *)v19);
  }
  if ( (*((_BYTE *)this + 468) & 8) == 0 )
  {
    v14 = Enviro::Get(this: *((Enviro **)this + 116), a2: "P4PASSWD");
    if ( v14 != nullptr
      && (*((int *)this + 59) < 2 || Enviro::FromRegistry(this: *((Enviro **)this + 116), a2: "P4PASSWD") == 0) )
    {
      v15 = (StrBuf *)((char *)this + 404);
      if ( *((_DWORD *)this + 99) == 0 )
        v15 = (StrBuf *)((char *)this + 392);
      StrBuf::operator=(this: v15, src: v14);
    }
  }
  v16 = (char *)this + 392;
  if ( pMem.buffer != StrBuf::nullStrBuf )
    free(pMem: pMem.buffer);
  return (const struct StrPtr *)v16;
}

//------------------------------------------------------------------------------
// Address: 0x100093D0
// Name: public: int StrPtr::XCompare(class StrPtr const __near &)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall StrPtr::XCompare(StrPtr *this, const struct StrPtr *a2)
{
  return strcmp(this->buffer, a2->buffer);
}

//------------------------------------------------------------------------------
// Address: 0x10009410
// Name: public: int StrPtr::operator==(class StrPtr const __near &)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall StrPtr::operator==(const char **this, const char **a2)
{
  return strcmp(*this, *a2) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10009480
// Name: public: virtual void StrPtrDict::VClear(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall StrPtrDict::VClear(StrPtrDict *this)
{
  *((_DWORD *)this + 3) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100094B0
// Name: public: void FileSys::MkDir(class Error __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall FileSys::MkDir(FileSys *this, struct Error *a2)
{
  ((void (__stdcall *)(StrBuf *, struct Error *))this->MkDir)(a1: &this->path, a2);
}

//------------------------------------------------------------------------------
// Address: 0x100094D0
// Name: public: void FileSys::Chmod2(char const __near *,class Error __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall FileSys::Chmod2(FileSys *this, char *a2, struct Error *a3)
{
  enum FilePerm v4; // eax

  v4 = FileSys::Perm(a1: a2);
  FileSys::Chmod2(this, a2: v4, a3);
}

//------------------------------------------------------------------------------
// Address: 0x10009500
// Name: enum FileSysType LookupType(class StrPtr const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
enum FileSysType __cdecl LookupType(const struct StrPtr *a1)
{
  enum FileSysType result; // eax
  int length; // eax
  int v3; // edx
  int v4; // ecx
  int v5; // edi
  int v6; // eax
  char v7; // cl
  char v8; // al
  char v9; // cl
  char v10; // al
  char v11; // cl
  char v12; // al
  int v13; // edx

  if ( a1 == nullptr )
    return FST_TEXT;
  length = a1->length;
  v3 = 0;
  v4 = 0;
  v5 = 0;
  if ( length != 0 )
  {
    v6 = length - 1;
    if ( v6 != 0 )
    {
      if ( v6 != 1 )
      {
        v7 = a1->buffer[2];
        if ( v7 <= 57 )
          v8 = 48;
        else
          v8 = v7 < 97 ? 55 : 87;
        v3 = (unsigned __int8)(v7 - v8);
      }
      v9 = a1->buffer[1];
      if ( v9 <= 57 )
        v10 = 48;
      else
        v10 = v9 < 97 ? 55 : 87;
      v5 = (unsigned __int8)(v9 - v10);
    }
    v11 = *a1->buffer;
    if ( v11 <= 57 )
      v12 = 48;
    else
      v12 = v11 < 97 ? 55 : 87;
    v4 = (unsigned __int8)(v11 - v12);
  }
  v13 = v4 | (v3 << 8);
  if ( v13 > 257 )
  {
    if ( v13 == 259 )
      result = FST_XUNICODE|FST_TEXT;
    else
LABEL_40:
      result = FST_BINARY;
  }
  else if ( v13 == 257 )
  {
    result = FST_GUNZIP;
  }
  else
  {
    switch ( v13 )
    {
      case 0:
        result = FST_TEXT;
        break;
      case 2:
        result = FST_XTEXT;
        break;
      case 3:
        result = FST_XBINARY;
        break;
      case 4:
        result = FST_SYMLINK;
        break;
      case 5:
        result = FST_RESOURCE;
        break;
      case 6:
        result = FST_XBINARY|0x4;
        break;
      case 7:
        result = FST_XBINARY|FST_DIRECTORY;
        break;
      case 8:
        result = FST_UNICODE;
        break;
      case 9:
        result = FST_RTEXT;
        break;
      case 10:
        result = FST_XUNICODE;
        break;
      case 11:
        result = FST_RXTEXT;
        break;
      case 12:
        result = FST_APPLETEXT;
        break;
      case 13:
        result = FST_APPLEFILE;
        break;
      case 14:
        result = FST_APPLETEXT|FST_M_EXEC;
        break;
      case 15:
        result = FST_XAPPLEFILE;
        break;
      case 24:
        result = FST_UTF16;
        break;
      case 26:
        result = FST_XUTF16;
        break;
      default:
        goto LABEL_40;
    }
  }
  if ( (result & 0xF000) == 0 )
  {
    switch ( v5 )
    {
      case 1:
        result |= 0x1000u;
        break;
      case 2:
        result |= 0x2000u;
        break;
      case 3:
        result |= 0x3000u;
        break;
      case 4:
        result |= 0x4000u;
        break;
      default:
        return result;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10009710
// Name: sub_10009710
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int *__usercall sub_10009710@<eax>(struct Error *a1@<eax>, int a2@<edi>)
{
  struct StrPtr *Var; // ebx
  const struct StrPtr *v4; // eax
  int *v6; // esi
  int v7; // ebp
  enum FileSysType v8; // eax
  int *v9; // esi
  int v10; // edx

  Var = StrDict::GetVar(this: *(StrDict **)(a2 + 212), a2: "path", a3: a1);
  FileSys::Set(this: (FileSys *)a2, a2: "type");
  if ( a1->severity > E_INFO )
    return nullptr;
  v6 = *(int **)(a2 + 4 * *(_DWORD *)(a2 + 264) + 248);
  v7 = *v6;
  v8 = LookupType(a1: v4);
  v9 = (int *)(*(int (__thiscall **)(int *, enum FileSysType))(v7 + 84))(a1: v6, a2: v8);
  v10 = *v9;
  v9[10] = *(_DWORD *)(a2 + 216);
  (*(void (__thiscall **)(int *, struct StrPtr *))(v10 + 4))(a1: v9, a2: Var);
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x100097B0
// Name: void clientWriteFile(class Client __near *,class Error __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl clientWriteFile(StrDict *a1, struct Error *a2)
{
  const struct StrPtr *Var; // edi
  struct StrPtr *v3; // ebp
  struct LastChance *v4; // eax
  struct LastChance *v5; // edi

  Var = StrDict::GetVar(this: a1, a2: "handle", a3: a2);
  v3 = StrDict::GetVar(this: a1, a2: "data", a3: a2);
  if ( a2->severity <= E_INFO )
  {
    v4 = Handlers::Get(this: (Handlers *)&a1[32], a2: Var, a3: a2);
    v5 = v4;
    if ( a2->severity <= E_INFO && v4->isError == 0 )
    {
      (*((void (__thiscall **)(LastChance_vtbl *, char *, int, struct Error *))v4[1].dtr_LastChance + 6))(
        a1: v4[1].__vftable,
        a2: v3->buffer,
        a3: v3->length,
        a4: a2);
      if ( a2->severity > E_INFO )
        v5->isError = 1;
      Client::OutputError(this: (Client *)a1, a2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009830
// Name: void clientCloseFile(class Client __near *,class Error __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl clientCloseFile(StrDict *a1, struct Error *a2)
{
  const struct StrPtr *Var; // esi
  int v3; // eax
  int v4; // edi
  struct LastChance *v5; // eax
  struct LastChance *v6; // esi
  LastChance_vtbl *v7; // ecx
  StrDict_vtbl *v8; // ecx
  _DWORD *v9; // edi
  void (__thiscall **v10)(_DWORD *, int); // eax
  StrDict_vtbl *v11; // ecx
  Handler *handler; // eax
  StrDict_vtbl *v13; // ebx

  Var = StrDict::GetVar(this: a1, a2: "handle", a3: a2);
  FileSys::Set(this: (FileSys *)a1, a2: "commit");
  v4 = v3;
  if ( a2->severity <= E_INFO )
  {
    v5 = Handlers::Get(this: (Handlers *)&a1[32], a2: Var, a3: a2);
    v6 = v5;
    if ( a2->severity <= E_INFO )
    {
      v7 = v5[1].__vftable;
      if ( v7 != nullptr )
        (*((void (__thiscall **)(LastChance_vtbl *, struct Error *))v7->dtr_LastChance + 8))(a1: v7, a2);
      if ( a2->severity > E_INFO )
        goto LABEL_15;
      if ( v6->isError == 0 )
      {
        if ( v6[1].isError != 0 )
        {
          v8 = a1[(int)a1[66].__vftable + 62].__vftable;
          v9 = (_DWORD *)(*((int (__thiscall **)(StrDict_vtbl *, void (__thiscall *)(LastChance *)))v8->dtr_StrDict + 21))(
                           a1: v8,
                           a2: v6[1].__vftable[7].dtr_LastChance);
          v10 = (void (__thiscall **)(_DWORD *, int))*v9;
          v9[10] = v6[1].__vftable[10].dtr_LastChance;
          v10[1](a1: v9, a2: (int)&v6[2]);
          v11 = a1[(int)a1[66].__vftable + 62].__vftable;
          (*((void (__thiscall **)(StrDict_vtbl *, LastChance_vtbl *, _DWORD *, _DWORD, LastChance_vtbl *, struct Error *))v11->dtr_StrDict
           + 16))(
            a1: v11,
            a2: v6[1].__vftable,
            a3: v9,
            a4: 0,
            a5: v6[3].__vftable,
            a6: a2);
          (*(void (__thiscall **)(_DWORD *, int))*v9)(a1: v9, a2: 1);
        }
        else if ( v4 != 0 )
        {
          handler = v6[1].handler;
          if ( handler != nullptr )
          {
            (*((void (__thiscall **)(LastChance_vtbl *, Handler *, struct Error *))v6[1].dtr_LastChance + 13))(
              a1: v6[1].__vftable,
              a2: handler,
              a3: a2);
            if ( a2->severity > E_INFO )
              goto LABEL_15;
            v6[1].__vftable[8].dtr_LastChance = nullptr;
          }
          else
          {
            v6[1].__vftable[8].dtr_LastChance = nullptr;
          }
        }
      }
      if ( a2->severity <= E_INFO )
      {
LABEL_17:
        ((void (__thiscall *)(struct LastChance *, int))v6->dtr_LastChance)(a1: v6, a2: 1);
        return;
      }
LABEL_15:
      v6->isError = 1;
      if ( a2->severity > E_INFO )
      {
        ++a1[73].__vftable;
        v13 = a1[(int)a1[66].__vftable + 62].__vftable;
        (*((void (__thiscall **)(StrDict_vtbl *, struct Error *))v13->dtr_StrDict + 2))(a1: v13, a2);
        a2->severity = E_EMPTY;
      }
      goto LABEL_17;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009980
// Name: void clientDeleteFile(class Client __near *,class Error __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall clientDeleteFile(int a1@<ebp>, FileSys *a2, struct Error *a3, int a4)
{
  const struct StrPtr *v5; // eax
  const struct StrPtr *v6; // ebx
  FileSys_vtbl *v7; // eax
  int *v8; // eax
  int *v9; // ebp
  char v10; // al
  bool v11; // zf
  int v13; // [esp-4h] [ebp-20h]
  LastChance v14; // [esp+10h] [ebp-Ch] BYREF
  int retaddr; // [esp+1Ch] [ebp+0h]
  char v16; // [esp+24h] [ebp+8h]

  Client::NewHandler(this: (Client *)a2);
  StrDict::GetVar(this: (StrDict *)a2[4].charSet, a2: "path", a3);
  FileSys::Set(this: a2, a2: "type");
  FileSys::Set(this: a2, a2: "noclobber");
  FileSys::Set(this: a2, a2: "handle");
  v6 = v5;
  FileSys::Set(this: a2, a2: "rmdir");
  if ( a3->severity > E_INFO && a3->severity != E_FATAL )
  {
    v7 = a2[6].__vftable;
    ++a2[6].type;
    (*(void (__thiscall **)(_DWORD, struct Error *))(**((_DWORD **)&a2[5].type + (_DWORD)v7) + 8))(
      a1: *((_DWORD *)&a2[5].type + (_DWORD)v7),
      a2: a3);
    a3->severity = E_EMPTY;
    return;
  }
  v8 = sub_10009710(a1: a3, (int)a2);
  v9 = v8;
  if ( a3->severity <= E_INFO )
  {
    v10 = (*(int (__thiscall **)(int *, int))(*v8 + 36))(a1: v8, a2: a1);
    v16 = v10;
    if ( a4 != 0 && v6 != nullptr && (v10 & 0xA) == 2 )
    {
      v14.isError = 0;
      v14.handler = (Handler *)&LastChance::`vftable';
      Handlers::Install(this: (Handlers *)&a2[2].content_charSet, a2: v6, a3: (struct LastChance *)&v14.handler, a4: a3);
      retaddr = 1;
      v13 = *(_DWORD *)(*(int (__thiscall **)(int *))(*v9 + 8))(a1: v9);
      Error::Set(this: a3, a2: &MsgClient::ClobberFile);
      Error::operator<<(a1: v13);
      Client::OutputError(this: (Client *)a2, a2: a3);
LABEL_18:
      (*(void (__thiscall **)(int *, int))*v9)(a1: v9, a2: 1);
      LastChance::~LastChance(this: &v14);
      return;
    }
    (*(void (__thiscall **)(int *, struct Error *))(*v9 + 48))(a1: v9, a2: a3);
    if ( a3->severity > E_INFO )
    {
      if ( v6 != nullptr && (v9[7] & 0x202) != 0 )
        v16 = (*(int (__thiscall **)(int *))(*v9 + 36))(a1: v9);
      if ( a3->severity > E_INFO && v6 != nullptr && (v16 & 1) != 0 )
      {
        v14.handler = (Handler *)&LastChance::`vftable';
        v14.isError = 0;
        Handlers::Install(
          this: (Handlers *)&a2[2].content_charSet,
          a2: v6,
          a3: (struct LastChance *)&v14.handler,
          a4: a3);
        retaddr = 1;
        Client::OutputError(this: (Client *)a2, a2: a3);
        if ( (v16 & 2) == 0 )
          (*(void (__thiscall **)(int *, _DWORD, struct Error *))(*v9 + 56))(a1: v9, a2: 0, a3);
        goto LABEL_18;
      }
    }
    v11 = v14.__vftable == nullptr;
    a3->severity = E_EMPTY;
    if ( !v11 )
      (*(void (__thiscall **)(int *, int *, _DWORD))(*v9 + 88))(a1: v9, a2: v9 + 4, a3: 0);
    (*(void (__thiscall **)(int *, int))*v9)(a1: v9, a2: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009B80
// Name: void clientOpenMerge(class Client __near *,class Error __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl clientOpenMerge(FileSys *a1, struct StrPtr *a2)
{
  struct StrPtr *v4; // ebp
  FileSys *v5; // eax
  struct StrPtr *v6; // eax
  struct StrPtr *v7; // ebx
  int v8; // eax
  const StrPtr *v9; // eax
  int v10; // eax
  StrPtr *v11; // eax
  enum MergeType v12; // ebp
  enum FileSysType v13; // eax
  struct ClientMerge *v14; // ebx
  FileSys *charSet; // ebp
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // esi
  int v20; // [esp-8h] [ebp-30h]
  int v21; // [esp-4h] [ebp-2Ch]
  int v22; // [esp+10h] [ebp-18h]
  int v23; // [esp+14h] [ebp-14h]
  const StrPtr *v24; // [esp+18h] [ebp-10h]
  StrPtr *v25; // [esp+1Ch] [ebp-Ch]
  struct StrPtr *v26; // [esp+20h] [ebp-8h]
  struct StrPtr *Var; // [esp+24h] [ebp-4h]
  FileSys *v28; // [esp+2Ch] [ebp+4h]
  enum FileSysType v29; // [esp+2Ch] [ebp+4h]
  FileSys *v30; // [esp+2Ch] [ebp+4h]
  struct StrPtr *v31; // [esp+30h] [ebp+8h]

  Client::NewHandler(this: (Client *)a1);
  Var = StrDict::GetVar(this: (StrDict *)a1[4].charSet, a2: "path", a3: (struct Error *)a2);
  v26 = StrDict::GetVar(this: (StrDict *)a1, a2: "handle", a3: (struct Error *)a2);
  v4 = StrDict::GetVar(this: (StrDict *)a1, a2: "func", a3: (struct Error *)a2);
  FileSys::Set(this: a1, a2: "type");
  v28 = v5;
  FileSys::Set(this: a1, a2: "type2");
  v7 = v6;
  v31 = v6;
  FileSys::Set(this: a1, a2: "showAll");
  v23 = v8;
  FileSys::Set(this: a1, a2: "diffFlags");
  v24 = v9;
  FileSys::Set(this: a1, a2: "noBase");
  v22 = v10;
  FileSys::Set(this: a1, a2: "digest");
  v25 = v11;
  if ( (int)a2->buffer > 1 )
  {
    if ( a2->buffer == (char *)4 )
      return;
    ++a1[6].type;
    goto LABEL_24;
  }
  if ( v7 == nullptr )
    v31 = (struct StrPtr *)v28;
  if ( strcmp(v4->buffer, "client-OpenMerge2") == 0 )
    v12 = CMT_BINARY;
  else
    v12 = (v22 != 0) + 1;
  v29 = LookupType(a1: (const struct StrPtr *)v28);
  v13 = LookupType(a1: v31);
  v14 = ClientMerge::Create(a1: *((struct ClientUser **)&a1[5].type + (int)a1[6].__vftable), a2: v29, a3: v13, a4: v12);
  if ( v23 != 0 )
    v14->SetShowAll(this: v14);
  if ( v24 != nullptr )
    v14->SetDiffFlags(this: v14, a2: v24);
  if ( a1[5].perms >= 16 && v25 != nullptr )
    v14->CopyDigest(this: v14, a2: v25, a3: (Error *)a2);
  Handlers::Install(this: (Handlers *)&a1[2].content_charSet, a2: v26, a3: v14, a4: (struct Error *)a2);
  if ( (int)a2->buffer <= 1 )
  {
    charSet = a1;
    if ( (v29 & 0xF) != 0xC )
      charSet = (FileSys *)a1[4].charSet;
    v30 = (FileSys *)v14->__vftable;
    FileSys::Set(this: charSet, a2: "yourName");
    v21 = v16;
    FileSys::Set(this: charSet, a2: "theirName");
    v20 = v17;
    FileSys::Set(this: charSet, a2: "baseName");
    ((void (__thiscall *)(struct ClientMerge *, int, int, int))v30[1].path.length)(a1: v14, a2: v18, a3: v20, a4: v21);
    v14->Open(
      this: v14,
      a2: Var,
      a3: (Error *)a2,
      a4: (struct CharSetCvt *)a1[4].path.buffer,
      a5: a1[4].content_charSet);
    if ( (int)a2->buffer > 1 )
    {
      v14->isError = 1;
      if ( (int)a2->buffer > 1 )
      {
        ++a1[6].type;
LABEL_24:
        v19 = *((_DWORD *)&a1[5].type + (int)a1[6].__vftable);
        (*(void (__thiscall **)(int, struct StrPtr *))(*(_DWORD *)v19 + 8))(a1: v19, a2);
        a2->buffer = nullptr;
      }
    }
  }
  else if ( v14 != nullptr )
  {
    ((void (__thiscall *)(struct ClientMerge *, int))v14->dtr_LastChance)(a1: v14, a2: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009DF0
// Name: void clientWriteMerge(class Client __near *,class Error __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl clientWriteMerge(StrDict *a1, struct Error *a2)
{
  const struct StrPtr *Var; // ebx
  struct StrPtr *v4; // ebp
  struct Error *v5; // eax
  struct LastChance *v6; // eax
  struct LastChance *v7; // ebx
  struct Error *v8; // [esp+18h] [ebp+8h]

  Var = StrDict::GetVar(this: a1, a2: "handle", a3: a2);
  v4 = StrDict::GetVar(this: a1, a2: "data", a3: a2);
  FileSys::Set(this: (FileSys *)a1, a2: "bits");
  v8 = v5;
  if ( a2->severity <= E_INFO )
  {
    v6 = Handlers::Get(this: (Handlers *)&a1[32], a2: Var, a3: a2);
    v7 = v6;
    if ( a2->severity <= E_INFO && v6->isError == 0 )
    {
      ((void (__thiscall *)(struct LastChance *, struct StrPtr *, struct Error *, struct Error *))v6->__vftable[21].dtr_LastChance)(
        a1: v6,
        a2: v4,
        a3: v8,
        a4: a2);
      if ( a2->severity > E_INFO )
        v7->isError = 1;
      Client::OutputError(this: (Client *)a1, a2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009E80
// Name: void clientCloseMerge(class Client __near *,class Error __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall clientCloseMerge(int a1@<ebp>, StrDict *a2, struct Error *a3, int *a4)
{
  int *v4; // esi
  const struct StrPtr *Var; // edi
  struct StrPtr *v6; // eax
  int v7; // eax
  _DWORD *v8; // eax
  struct LastChance *v9; // ebp
  int v10; // eax
  StrDict_vtbl *v11; // ecx
  const struct StrPtr *v12; // eax
  const struct StrPtr *v13; // eax
  const char *v14; // edi
  const struct StrPtr *v15; // eax
  StrDict_vtbl *v16; // eax
  StrDict_vtbl *v17; // ecx
  int v19; // [esp+24h] [ebp-14h]
  struct StrPtr *v20; // [esp+28h] [ebp-10h]
  int v21; // [esp+30h] [ebp-8h]
  _DWORD *v22; // [esp+34h] [ebp-4h]
  const char **retaddr; // [esp+38h] [ebp+0h]

  v4 = (int *)a3;
  Var = StrDict::GetVar(this: a2, a2: "handle", a3);
  FileSys::Set(this: (FileSys *)a2, a2: "mergeConfirm");
  FileSys::Set(this: (FileSys *)a2, a2: "mergeDecline");
  v20 = v6;
  FileSys::Set(this: (FileSys *)a2, a2: "mergePerms");
  v21 = v7;
  FileSys::Set(this: (FileSys *)a2, a2: "mergeAuto");
  v22 = v8;
  if ( a3->severity > E_INFO )
    return;
  v9 = Handlers::Get(this: (Handlers *)&a2[32], a2: Var, a3);
  if ( a3->severity > E_INFO )
    return;
  ((void (__thiscall *)(struct LastChance *, struct Error *, int))v9->__vftable[22].dtr_LastChance)(
    a1: v9,
    a2: a3,
    a3: a1);
  if ( a3->severity > E_INFO )
    v9->isError = 1;
  if ( v9->isError != 0 )
    goto LABEL_50;
  if ( v20 == nullptr )
    goto LABEL_53;
  while ( 2 )
  {
    if ( v22 != nullptr )
      ((void (__thiscall *)(struct LastChance *, const char *, int *))v9->__vftable[25].dtr_LastChance)(
        a1: v9,
        a2: "rw",
        a3: v4);
    if ( retaddr != nullptr )
    {
      if ( strcmp(*retaddr, "safe") == 0 )
      {
        v10 = ((int (__thiscall *)(struct LastChance *, int))v9->__vftable[1].dtr_LastChance)(a1: v9, a2: 1);
        v4 = a4;
        goto LABEL_18;
      }
      if ( strcmp(*retaddr, "force") == 0 )
      {
        v10 = ((int (__thiscall *)(struct LastChance *, int))v9->__vftable[1].dtr_LastChance)(a1: v9, a2: 2);
        v4 = a4;
        goto LABEL_18;
      }
      if ( strcmp(*retaddr, "auto") == 0 )
      {
        v10 = ((int (__thiscall *)(struct LastChance *, _DWORD))v9->__vftable[1].dtr_LastChance)(a1: v9, a2: 0);
        v4 = a4;
        goto LABEL_18;
      }
      v4 = a4;
    }
    v11 = a2[(int)a2[66].__vftable + 62].__vftable;
    v10 = (*((int (__thiscall **)(StrDict_vtbl *, struct LastChance *, int *))v11->dtr_StrDict + 18))(
            a1: v11,
            a2: v9,
            a3: v4);
    v21 = 1;
LABEL_18:
    v19 = v10;
    if ( v10 == 3 && (int)a2[57].__vftable < 11 )
      v19 = 2;
    switch ( v19 )
    {
      case 0:
        v20 = nullptr;
        goto LABEL_39;
      case 1:
        v20 = nullptr;
        goto LABEL_39;
      case 2:
        v12 = (const struct StrPtr *)((int (__thiscall *)(struct LastChance *))v9->__vftable[13].dtr_LastChance)(a1: v9);
        if ( v12 != nullptr )
          StrDict::SetVar(this: a2, a2: "digest", a3: v12);
        StrDict::SetVar(this: a2, a2: "mergeHow", a3: "merged");
        goto LABEL_39;
      case 3:
        StrDict::SetVar(this: a2, a2: "mergeHow", a3: "edit");
        goto LABEL_39;
      case 4:
        v13 = (const struct StrPtr *)((int (__thiscall *)(struct LastChance *))v9->__vftable[15].dtr_LastChance)(a1: v9);
        if ( v13 != nullptr )
          StrDict::SetVar(this: a2, a2: "digest", a3: v13);
        StrDict::SetVar(this: a2, a2: "mergeHow", a3: "theirs");
        v14 = "no";
        if ( ((int (__thiscall *)(struct LastChance *))v9->__vftable[9].dtr_LastChance)(a1: v9) > 0
          || ((int (__thiscall *)(struct LastChance *))v9->__vftable[12].dtr_LastChance)(a1: v9) > 0 )
        {
          v14 = "yes";
        }
        else if ( ((int (__thiscall *)(struct LastChance *))v9->__vftable[10].dtr_LastChance)(a1: v9) > 0 )
        {
          StrDict::SetVar(this: a2, a2: "force", a3: "theirs");
          goto LABEL_39;
        }
        StrDict::SetVar(this: a2, a2: "force", a3: v14);
LABEL_39:
        if ( *v4 <= 1 )
        {
          ((void (__thiscall *)(struct LastChance *, int, int *))v9->__vftable[23].dtr_LastChance)(
            a1: v9,
            a2: v19,
            a3: v4);
          if ( *v4 <= 1 )
            goto LABEL_47;
        }
        if ( v21 != 0 && v20 != nullptr )
        {
          StrDict::RemoveVar(this: a2, a2: "mergeHow");
          if ( *v4 > 1 )
          {
            v16 = a2[66].__vftable;
            ++a2[73].__vftable;
            (*((void (__thiscall **)(StrDict_vtbl *, int *))a2[(_DWORD)v16 + 62].dtr_StrDict + 2))(
              a1: a2[(_DWORD)v16 + 62].__vftable,
              a2: v4);
            *v4 = 0;
          }
          *v4 = 0;
          continue;
        }
        if ( *v4 > 1 )
          goto LABEL_50;
LABEL_47:
        if ( v22 != nullptr )
          ((void (__thiscall *)(struct LastChance *, _DWORD, int *))v9->__vftable[24].dtr_LastChance)(
            a1: v9,
            a2: *v22,
            a3: v4);
        if ( *v4 > 1 )
LABEL_50:
          v20 = nullptr;
        if ( v20 != nullptr )
          Client::Confirm(this: a2, a2: v20);
LABEL_53:
        if ( *v4 > 1 )
        {
          v9->isError = 1;
          if ( *v4 > 1 )
          {
            v17 = a2[66].__vftable;
            ++a2[73].__vftable;
            (*((void (__thiscall **)(StrDict_vtbl *, int *))a2[(_DWORD)v17 + 62].dtr_StrDict + 2))(
              a1: a2[(_DWORD)v17 + 62].__vftable,
              a2: v4);
            *v4 = 0;
          }
        }
        ((void (__thiscall *)(struct LastChance *, int))v9->dtr_LastChance)(a1: v9, a2: 1);
        return;
      case 5:
        v15 = (const struct StrPtr *)((int (__thiscall *)(struct LastChance *))v9->__vftable[14].dtr_LastChance)(a1: v9);
        if ( v15 != nullptr )
          StrDict::SetVar(this: a2, a2: "digest", a3: v15);
        StrDict::SetVar(this: a2, a2: "mergeHow", a3: "yours");
        goto LABEL_39;
      default:
        goto LABEL_39;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000A220
// Name: void clientErrorPause(class Client __near *,class Error __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl clientErrorPause(StrDict **a1, struct Error *a2)
{
  struct StrPtr *Var; // eax
  StrDict *v3; // ecx

  Client::NewHandler(this: (Client *)a1);
  Var = StrDict::GetVar(this: a1[52], a2: "data", a3: a2);
  if ( a2->severity <= E_INFO )
  {
    v3 = a1[(_DWORD)a1[66] + 62];
    ((void (__thiscall *)(StrDict *, char *, struct Error *))v3->__vftable[2].dtr_StrDict)(
      a1: v3,
      a2: Var->buffer,
      a3: a2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000A270
// Name: void clientHandleError(class Client __near *,class Error __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl clientHandleError(StrDict **a1, struct Error *a2)
{
  const struct StrPtr *Var; // eax
  StrDict *v3; // eax
  StrDict *v4; // ecx
  Error v5; // [esp+8h] [ebp-Ch] BYREF

  Client::NewHandler(this: (Client *)a1);
  Var = StrDict::GetVar(this: a1[52], a2: "data", a3: a2);
  if ( a2->severity <= E_INFO )
  {
    v5.ep = nullptr;
    v5.severity = E_EMPTY;
    Error::UnMarshall0(this: &v5, a2: Var);
    if ( v5.severity >= E_FAILED )
      a1[73] = (StrDict *)((char *)a1[73] + 1);
    v4 = a1[(_DWORD)a1[66] + 62];
    ((void (__thiscall *)(StrDict *, Error *))v4->VSetVar)(a1: v4, a2: &v5);
    Error::~Error(this: &v5);
  }
  else if ( a2->severity != E_FATAL )
  {
    v3 = a1[66];
    a1[73] = (StrDict *)((char *)a1[73] + 1);
    ((void (__thiscall *)(StrDict *, struct Error *))a1[(_DWORD)v3 + 62]->VSetVar)(a1: a1[(_DWORD)v3 + 62], a2);
    a2->severity = E_EMPTY;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000A320
// Name: void clientMessage(class Client __near *,class Error __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl clientMessage(struct StrDict *a1)
{
  struct StrDict *v1; // ebx
  struct StrDict *v2; // esi
  StrBufDict *v3; // eax
  StrDict_vtbl *v4; // ebp
  StrDict_vtbl *v5; // ebx
  StrDict_vtbl *v6; // ecx
  Error v7; // [esp+10h] [ebp-Ch] BYREF

  Client::NewHandler(this: (Client *)a1);
  v1 = (struct StrDict *)a1[52].__vftable;
  v7.ep = nullptr;
  v7.severity = E_EMPTY;
  v2 = a1;
  if ( a1 != v1 )
  {
    v3 = (StrBufDict *)operator new(nSize: 0x18u);
    v2 = (struct StrDict *)v3;
    if ( v3 != nullptr )
    {
      v4 = v1[5].__vftable;
      v5 = v1[4].__vftable;
      StrBufDict::StrBufDict(this: v3);
      v2->__vftable = (StrDict_vtbl *)&TransDictQues::`vftable';
      v2[4].__vftable = v5;
      v2[5].__vftable = v4;
    }
    else
    {
      v2 = nullptr;
    }
  }
  Error::UnMarshall1(this: &v7, a2: v2);
  if ( v7.severity >= E_FAILED )
    ++a1[73].__vftable;
  v6 = a1[(int)a1[66].__vftable + 62].__vftable;
  (*((void (__thiscall **)(StrDict_vtbl *, Error *))v6->dtr_StrDict + 3))(a1: v6, a2: &v7);
  if ( v2 != a1 && v2 != nullptr )
    ((void (__thiscall *)(struct StrDict *, int))v2->dtr_StrDict)(a1: v2, a2: 1);
  Error::~Error(this: &v7);
}

//------------------------------------------------------------------------------
// Address: 0x1000A3D0
// Name: void clientOutputError(class Client __near *,class Error __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl clientOutputError(FileSys *a1, struct Error *a2)
{
  struct StrPtr *Var; // ebx
  int v3; // eax
  FileSys_vtbl *v4; // eax
  int v5; // ecx

  Client::NewHandler(this: (Client *)a1);
  Var = StrDict::GetVar(this: (StrDict *)a1[4].isTemp, a2: "data", a3: a2);
  FileSys::Set(this: a1, a2: "warning");
  if ( v3 == 0 )
    ++a1[6].type;
  if ( a2->severity <= E_INFO )
  {
    v5 = *((_DWORD *)&a1[5].type + (int)a1[6].__vftable);
    (*(void (__thiscall **)(int, char *))(*(_DWORD *)v5 + 16))(a1: v5, a2: Var->buffer);
  }
  else if ( a2->severity != E_FATAL )
  {
    v4 = a1[6].__vftable;
    ++a1[6].type;
    (*(void (__thiscall **)(_DWORD, struct Error *))(**((_DWORD **)&a1[5].type + (_DWORD)v4) + 8))(
      a1: *((_DWORD *)&a1[5].type + (_DWORD)v4),
      a2);
    a2->severity = E_EMPTY;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000A460
// Name: void clientOutputInfo(class Client __near *,class Error __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl clientOutputInfo(FileSys *a1, struct Error *a2)
{
  struct StrPtr *Var; // ebx
  char **v3; // eax
  char v4; // al
  int v5; // ecx
  int v6; // ecx

  Client::NewHandler(this: (Client *)a1);
  Var = StrDict::GetVar(this: (StrDict *)a1[4].isTemp, a2: "data", a3: a2);
  FileSys::Set(this: a1, a2: "level");
  if ( v3 != nullptr )
    v4 = **v3;
  else
    v4 = 48;
  if ( a2->severity <= E_INFO )
  {
    v6 = *((_DWORD *)&a1[5].type + (int)a1[6].__vftable);
    (*(void (__thiscall **)(int, _DWORD, char *))(*(_DWORD *)v6 + 24))(a1: v6, a2: v4, a3: Var->buffer);
  }
  else if ( a2->severity != E_FATAL )
  {
    ++a1[6].type;
    v5 = *((_DWORD *)&a1[5].type + (int)a1[6].__vftable);
    (*(void (__thiscall **)(int, struct Error *))(*(_DWORD *)v5 + 8))(a1: v5, a2);
    a2->severity = E_EMPTY;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000A4F0
// Name: void clientOutputText(class Client __near *,class Error __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl clientOutputText(FileSys *a1, struct Error *a2)
{
  const char **v2; // eax
  StrDict *isTemp; // ecx
  struct StrPtr *Var; // eax
  int v5; // ecx
  int v6; // ecx

  Client::NewHandler(this: (Client *)a1);
  FileSys::Set(this: a1, a2: "trans");
  if ( v2 == nullptr || (isTemp = (StrDict *)a1, strcmp(*v2, "no") != 0) )
    isTemp = (StrDict *)a1[4].isTemp;
  Var = StrDict::GetVar(this: isTemp, a2: "data", a3: a2);
  if ( a2->severity <= E_INFO )
  {
    v6 = *((_DWORD *)&a1[5].type + (int)a1[6].__vftable);
    (*(void (__thiscall **)(int, char *, int))(*(_DWORD *)v6 + 40))(a1: v6, a2: Var->buffer, a3: Var->length);
  }
  else if ( a2->severity != E_FATAL )
  {
    ++a1[6].type;
    v5 = *((_DWORD *)&a1[5].type + (int)a1[6].__vftable);
    (*(void (__thiscall **)(int, struct Error *))(*(_DWORD *)v5 + 8))(a1: v5, a2);
    a2->severity = E_EMPTY;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000A590
// Name: void clientOutputBinary(class Client __near *,class Error __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl clientOutputBinary(StrDict *a1, struct Error *a2)
{
  struct StrPtr *Var; // eax
  StrDict_vtbl *v3; // ecx

  Var = StrDict::GetVar(this: a1, a2: "data", a3: a2);
  if ( a2->severity <= E_INFO )
  {
    v3 = a1[(int)a1[66].__vftable + 62].__vftable;
    (*((void (__thiscall **)(StrDict_vtbl *, char *, int))v3->dtr_StrDict + 8))(
      a1: v3,
      a2: Var->buffer,
      a3: Var->length);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000A5D0
// Name: void clientFstatInfo(class Client __near *,class Error __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl clientFstatInfo(struct Client *a1)
{
  int v1; // ecx

  Client::NewHandler(this: a1);
  v1 = *((_DWORD *)a1 + *((_DWORD *)a1 + 66) + 62);
  (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v1 + 48))(a1: v1, a2: *((_DWORD *)a1 + 52));
}

//------------------------------------------------------------------------------
// Address: 0x1000A600
// Name: void clientAck(class Client __near *,class Error __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl clientAck(StrDict *a1, struct Error *a2)
{
  const struct StrPtr *Var; // ebx
  const struct StrPtr *v3; // eax
  const struct StrPtr *v4; // ebp
  const struct StrPtr *v5; // eax

  Var = StrDict::GetVar(this: a1, a2: "confirm", a3: a2);
  FileSys::Set(this: (FileSys *)a1, a2: "decline");
  v4 = v3;
  FileSys::Set(this: (FileSys *)a1, a2: "handle");
  if ( a2->severity <= E_INFO )
  {
    if ( v5 != nullptr && Handlers::AnyErrors(this: (Handlers *)&a1[32], a2: v5) != 0 )
      Var = v4;
    if ( Var != nullptr )
      Client::Confirm(this: a1, a2: Var);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000A670
// Name: void clientFatalError(class Client __near *,class Error __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl clientFatalError(struct Client *a1, Error *a2)
{
  int v2; // eax

  Error::Set(this: a2, a2: &MsgClient::Fatal);
  v2 = *((_DWORD *)a1 + 66);
  ++*((_DWORD *)a1 + 73);
  (*(void (__thiscall **)(_DWORD, Error *))(**((_DWORD **)a1 + v2 + 62) + 8))(a1: *((_DWORD *)a1 + v2 + 62), a2);
  *((_DWORD *)a1 + 11) = 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000A6B0
// Name: public: StrNum::StrNum(__int64)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
StrNum *__thiscall StrNum::StrNum(StrNum *this, __int64 a2)
{
  char *v3; // eax

  v3 = StrPtr::Itoa64(a1: a2, a2: (char *)this + 32);
  this->buffer = v3;
  this->length = (char *)this - v3 + 31;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000A6E0
// Name: public: void FileSys::ModTime(class StrPtr __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall FileSys::ModTime(FileSys *this, struct StrPtr *a2)
{
  this->modTime = atoi(nptr: a2->buffer);
}

//------------------------------------------------------------------------------
// Address: 0x1000A700
// Name: public: ClientFile::ClientFile(class FileSys __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientFile *__thiscall ClientFile::ClientFile(ClientFile *this, struct FileSys *a2)
{
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *(_DWORD *)this = &ClientFile::`vftable';
  *((_DWORD *)this + 8) = 0;
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 6) = StrBuf::nullStrBuf;
  *((_DWORD *)this + 9) = StrBuf::nullStrBuf;
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 3) = a2;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000A740
// Name: public: virtual ClientFile::~ClientFile(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall ClientFile::~ClientFile(LastChance *this)
{
  void (__thiscall ***v2)(_DWORD, int); // ecx
  void (__thiscall ***v3)(_DWORD, int); // ecx

  v2 = *((void (__thiscall ****)(_DWORD, int))this + 3);
  this->__vftable = (LastChance_vtbl *)&ClientFile::`vftable';
  if ( v2 != nullptr )
    (**v2)(a1: v2, a2: 1);
  v3 = *((void (__thiscall ****)(_DWORD, int))this + 4);
  if ( v3 != nullptr )
    (**v3)(a1: v3, a2: 1);
  if ( *((char **)this + 9) != StrBuf::nullStrBuf )
    free(pMem: *((void **)this + 9));
  if ( *((char **)this + 6) != StrBuf::nullStrBuf )
    free(pMem: *((void **)this + 6));
  LastChance::~LastChance(this);
}

//------------------------------------------------------------------------------
// Address: 0x1000A7C0
// Name: void clientOpenFile(class Client __near *,class Error __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl clientOpenFile(FileSys *a1, struct Error *a2)
{
  int *v3; // esi
  const struct StrPtr *v4; // edi
  struct StrPtr *v5; // eax
  int v6; // eax
  int v7; // eax
  struct StrPtr *v8; // eax
  ClientFile *v9; // eax
  ClientFile *v10; // ebp
  int *v11; // eax
  int v12; // edx
  char v13; // al
  int v14; // eax
  int v15; // ecx
  int v16; // eax
  _DWORD *v17; // eax
  FileSys *v18; // ecx
  int v19; // ebx
  int v20; // [esp-4h] [ebp-2Ch]
  int v21; // [esp-4h] [ebp-2Ch]
  struct StrPtr *v22; // [esp+10h] [ebp-18h]
  struct StrPtr *Var; // [esp+14h] [ebp-14h]
  struct StrPtr *v24; // [esp+18h] [ebp-10h]
  int v25; // [esp+1Ch] [ebp-Ch]
  int v26; // [esp+20h] [ebp-8h]
  struct StrPtr *v27; // [esp+24h] [ebp-4h]
  char v28; // [esp+2Ch] [ebp+4h]

  Client::NewHandler(this: (Client *)a1);
  v3 = (int *)a2;
  Var = StrDict::GetVar(this: (StrDict *)a1[4].charSet, a2: "path", a3: a2);
  v4 = StrDict::GetVar(this: (StrDict *)a1, a2: "handle", a3: a2);
  FileSys::Set(this: a1, a2: "time");
  v27 = v5;
  FileSys::Set(this: a1, a2: "noclobber");
  v25 = v6;
  FileSys::Set(this: a1, a2: "perms");
  v26 = v7;
  v22 = StrDict::GetVar(this: (StrDict *)a1, a2: "func", a3: a2);
  FileSys::Set(this: a1, a2: "diffFlags");
  v24 = v8;
  if ( a2->severity > E_INFO )
  {
    if ( a2->severity == E_FATAL )
      return;
    v9 = (ClientFile *)operator new(nSize: 0x30u);
    if ( v9 != nullptr )
    {
      v10 = ClientFile::ClientFile(this: v9, a2: nullptr);
      Handlers::Install(this: (Handlers *)&a1[2].content_charSet, a2: v4, a3: (struct LastChance *)v10, a4: a2);
    }
    else
    {
      v10 = nullptr;
      Handlers::Install(this: (Handlers *)&a1[2].content_charSet, a2: v4, a3: nullptr, a4: a2);
    }
LABEL_36:
    if ( *v3 <= 1 )
      return;
    goto LABEL_37;
  }
  v10 = (ClientFile *)operator new(nSize: 0x30u);
  if ( v10 != nullptr )
  {
    v11 = sub_10009710(a1: a2, a2: (int)a1);
    *((_DWORD *)v10 + 1) = 0;
    *((_DWORD *)v10 + 2) = 0;
    *(_DWORD *)v10 = &ClientFile::`vftable';
    *((_DWORD *)v10 + 8) = 0;
    *((_DWORD *)v10 + 7) = 0;
    *((_DWORD *)v10 + 6) = StrBuf::nullStrBuf;
    *((_DWORD *)v10 + 11) = 0;
    *((_DWORD *)v10 + 10) = 0;
    *((_DWORD *)v10 + 9) = StrBuf::nullStrBuf;
    *((_DWORD *)v10 + 3) = v11;
    *((_DWORD *)v10 + 4) = 0;
    *((_DWORD *)v10 + 5) = 0;
  }
  else
  {
    v10 = nullptr;
  }
  Handlers::Install(this: (Handlers *)&a1[2].content_charSet, a2: v4, a3: (struct LastChance *)v10, a4: a2);
  if ( a2->severity <= E_INFO )
  {
    if ( strcmp(v4->buffer, "sync") == 0 )
      Handlers::AnyErrors(this: (Handlers *)&a1[2].content_charSet, a2: v4);
    if ( strcmp(v22->buffer, "client-OpenDiff") == 0 )
    {
      v12 = *((_DWORD *)v10 + 3);
      *((_DWORD *)v10 + 5) = 1;
      *(_DWORD *)(v12 + 32) = 1;
      *((_DWORD *)v10 + 7) = 0;
      StrBuf::Append(this: (StrBuf *)v10 + 2, a2: Var);
      if ( v24 != nullptr )
      {
        *((_DWORD *)v10 + 10) = 0;
        StrBuf::Append(this: (StrBuf *)v10 + 3, a2: v24);
      }
      FileSys::MakeGlobalTemp(this: *((FileSys **)v10 + 3));
LABEL_34:
      (*(void (__thiscall **)(_DWORD, int, struct Error *))(**((_DWORD **)v10 + 3) + 20))(
        a1: *((_DWORD *)v10 + 3),
        a2: 1,
        a3: a2);
      (*(void (__thiscall **)(_DWORD, char *))(**((_DWORD **)v10 + 3) + 16))(
        a1: *((_DWORD *)v10 + 3),
        a2: a1[4].path.buffer);
      goto LABEL_35;
    }
    v13 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)v10 + 3) + 36))(a1: *((_DWORD *)v10 + 3));
    v28 = v13;
    if ( v25 != 0 && (v13 & 0xA) == 2 )
    {
      v20 = *(_DWORD *)(*(int (__thiscall **)(_DWORD))(**((_DWORD **)v10 + 3) + 8))(a1: *((_DWORD *)v10 + 3));
      Error::Set(this: a2, a2: &MsgClient::ClobberFile);
      Error::operator<<(a1: v20);
LABEL_35:
      v3 = (int *)a2;
      goto LABEL_36;
    }
    if ( (v13 & 9) != 0 && (v13 & 0x10) == 0 )
    {
      if ( (*(int (__thiscall **)(_DWORD))(**((_DWORD **)v10 + 3) + 12))(a1: *((_DWORD *)v10 + 3)) != 0 )
      {
        v14 = *((_DWORD *)v10 + 3);
        *((_DWORD *)v10 + 4) = v14;
        v15 = *((_DWORD *)&a1[5].type + (int)a1[6].__vftable);
        v16 = (*(int (__thiscall **)(int, _DWORD))(*(_DWORD *)v15 + 84))(a1: v15, a2: *(_DWORD *)(v14 + 28));
        *((_DWORD *)v10 + 3) = v16;
        *(_DWORD *)(v16 + 40) = *(_DWORD *)(v16 + 40);
        v17 = (_DWORD *)(*(int (__thiscall **)(_DWORD))(**((_DWORD **)v10 + 4) + 8))(a1: *((_DWORD *)v10 + 4));
        (*(void (__thiscall **)(_DWORD, _DWORD))(**((_DWORD **)v10 + 3) + 76))(a1: *((_DWORD *)v10 + 3), a2: *v17);
        *(_DWORD *)(*((_DWORD *)v10 + 3) + 32) = 1;
        goto LABEL_29;
      }
      v13 = v28;
    }
    v3 = (int *)a2;
    v18 = *((FileSys **)v10 + 3);
    if ( (v13 & 8) != 0 )
    {
      v18->Unlink(this: v18, a2);
      if ( a2->severity > E_INFO )
      {
LABEL_37:
        *((_DWORD *)v10 + 2) = 1;
        if ( *v3 > 1 )
        {
          ++a1[6].type;
          v19 = *((_DWORD *)&a1[5].type + (int)a1[6].__vftable);
          (*(void (__thiscall **)(int, int *))(*(_DWORD *)v19 + 8))(a1: v19, a2: v3);
          *v3 = 0;
        }
        return;
      }
    }
    else
    {
      if ( (v13 & 1) != 0 )
      {
        FileSys::Chmod2(this: v18, a2: FPM_RW, a3: a2);
        a2->severity = E_EMPTY;
LABEL_29:
        if ( v26 != 0 && StrPtr::operator==(a1: "rw") != 0 )
          *(_DWORD *)(*((_DWORD *)v10 + 3) + 8) = 1;
        if ( v27 != nullptr )
          FileSys::ModTime(this: *((FileSys **)v10 + 3), a2: v27);
        goto LABEL_34;
      }
      FileSys::MkDir(this: v18, a2);
      if ( a2->severity > E_INFO )
      {
        v21 = *(_DWORD *)(*(int (__thiscall **)(_DWORD))(**((_DWORD **)v10 + 3) + 8))(a1: *((_DWORD *)v10 + 3));
        Error::Set(this: a2, a2: &MsgClient::MkDir);
        Error::operator<<(a1: v21);
        goto LABEL_36;
      }
    }
    *(_DWORD *)(*((_DWORD *)v10 + 3) + 32) = 1;
    goto LABEL_29;
  }
  if ( v10 != nullptr )
    (**(void (__thiscall ***)(ClientFile *, int))v10)(a1: v10, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1000AB60
// Name: void clientChmodFile(class Client __near *,class Error __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl clientChmodFile(FileSys *a1, struct Error *a2)
{
  const char **v3; // eax
  const char **v4; // ebp
  FileSys_vtbl *v5; // eax
  int *v6; // eax
  FileSys *v7; // ebx
  int v8; // eax
  FileSys_vtbl *v9; // edx
  enum FilePerm v10; // eax
  int v11; // ecx
  struct StrPtr *Var; // [esp+10h] [ebp+4h]

  Client::NewHandler(this: (Client *)a1);
  StrDict::GetVar(this: (StrDict *)a1[4].charSet, a2: "path", a3: a2);
  Var = StrDict::GetVar(this: (StrDict *)a1, a2: "perms", a3: a2);
  FileSys::Set(this: a1, a2: "type");
  FileSys::Set(this: a1, a2: "time");
  v4 = v3;
  if ( a2->severity <= E_INFO || a2->severity == E_FATAL )
  {
    v6 = sub_10009710(a1: a2, a2: (int)a1);
    v7 = (FileSys *)v6;
    if ( a2->severity <= E_INFO )
    {
      if ( v4 != nullptr && ((*(int (__thiscall **)(int *))(*v6 + 36))(a1: v6) & 2) != 0 )
      {
        v8 = atoi(nptr: *v4);
        v9 = v7->__vftable;
        v7->modTime = v8;
        v9->ChmodTime(this: v7, a2);
      }
      if ( a2->severity <= E_INFO )
      {
        v10 = FileSys::Perm(a1: Var->buffer);
        FileSys::Chmod2(this: v7, a2: v10, a3: a2);
      }
      if ( v7 != nullptr )
        ((void (__thiscall *)(FileSys *, int))v7->dtr_FileSys)(a1: v7, a2: 1);
      if ( a2->severity > E_INFO )
      {
        ++a1[6].type;
        v11 = *((_DWORD *)&a1[5].type + (int)a1[6].__vftable);
        (*(void (__thiscall **)(int, struct Error *))(*(_DWORD *)v11 + 8))(a1: v11, a2);
        a2->severity = E_EMPTY;
      }
    }
  }
  else
  {
    v5 = a1[6].__vftable;
    ++a1[6].type;
    (*(void (__thiscall **)(_DWORD, struct Error *))(**((_DWORD **)&a1[5].type + (_DWORD)v5) + 8))(
      a1: *((_DWORD *)&a1[5].type + (_DWORD)v5),
      a2);
    a2->severity = E_EMPTY;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000AC70
// Name: void clientCheckFile(class Client __near *,class Error __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl clientCheckFile(StrDict *a1, struct Error *a2)
{
  struct StrPtr *Var; // ebx
  const char **v5; // eax
  const char **v6; // esi
  StrDict **v7; // eax
  struct StrPtr *v8; // eax
  StrDict_vtbl *v9; // eax
  StrDict_vtbl *v10; // edi
  const char *v11; // eax
  int *v12; // eax
  int *v13; // esi
  void (__thiscall *v14)(int *, StrDict_vtbl *); // edx
  void *severity; // eax
  bool v16; // zf
  StrDict_vtbl *v17; // eax
  StrDict *v18; // esi
  StrPtr *(__thiscall *VGetVar)(StrDict *, const StrPtr *); // eax
  enum FileSysType v20; // eax
  _DWORD *v21; // ebx
  StrDict *v22; // ebx
  StrDict_vtbl *v23; // ecx
  StrDict *v24; // eax
  int *v25; // eax
  StrDict_vtbl *v26; // ecx
  int *v27; // eax
  int *v28; // eax
  StrDict_vtbl *v29; // ecx
  int v30; // [esp-8h] [ebp-30h]
  int v31; // [esp-8h] [ebp-30h]
  StrDict_vtbl *v32; // [esp-4h] [ebp-2Ch]
  int v33; // [esp-4h] [ebp-2Ch]
  int v34; // [esp-4h] [ebp-2Ch]
  const char *v35; // [esp+0h] [ebp-28h]
  StrDict **v36; // [esp+10h] [ebp-18h]
  struct StrPtr *v37; // [esp+14h] [ebp-14h]
  struct StrPtr *v38; // [esp+18h] [ebp-10h]
  Error pMem; // [esp+1Ch] [ebp-Ch] BYREF
  StrDict *v40; // [esp+2Ch] [ebp+4h]
  const char *v41; // [esp+30h] [ebp+8h]

  Client::NewHandler(this: (Client *)a1);
  Var = StrDict::GetVar(this: (StrDict *)a1[53].__vftable, a2: "path", a3: a2);
  FileSys::Set(this: (FileSys *)a1, a2: "type");
  v6 = v5;
  FileSys::Set(this: (FileSys *)a1, a2: "forceType");
  v36 = v7;
  FileSys::Set(this: (FileSys *)a1, a2: "digest");
  v37 = v8;
  v38 = StrDict::GetVar(this: a1, a2: "confirm", a3: a2);
  if ( a2->severity > E_INFO && a2->severity != E_FATAL )
  {
    v9 = a1[66].__vftable;
    ++a1[73].__vftable;
    v10 = a1[(_DWORD)v9 + 62].__vftable;
LABEL_31:
    (*((void (__thiscall **)(StrDict_vtbl *, struct Error *))v10->dtr_StrDict + 2))(a1: v10, a2);
    a2->severity = E_EMPTY;
    return;
  }
  v41 = "exists";
  if ( v6 != nullptr )
    v11 = *v6;
  else
    v11 = "text";
  v40 = (StrDict *)v11;
  if ( v6 != nullptr )
  {
    v12 = sub_10009710(a1: a2, a2: (int)a1);
    v13 = v12;
    if ( a2->severity > E_INFO )
      return;
    if ( ((*(int (__thiscall **)(int *))(*v12 + 36))(a1: v12) & 9) != 0 )
    {
      if ( v37 != nullptr )
      {
        v14 = *(void (__thiscall **)(int *, StrDict_vtbl *))(*v13 + 16);
        pMem.ep = nullptr;
        pMem.genericCode = 0;
        v32 = a1[49].__vftable;
        pMem.severity = (ErrorSeverity)StrBuf::nullStrBuf;
        v14(a1: v13, a2: v32);
        (*(void (__thiscall **)(int *, Error *, struct Error *))(*v13 + 92))(a1: v13, a2: &pMem, a3: a2);
        if ( a2->severity <= E_INFO && StrPtr::XCompare(this: (StrPtr *)&pMem, a2: v37) == 0 )
          v41 = "same";
        severity = (void *)pMem.severity;
        v16 = pMem.severity == (_DWORD)StrBuf::nullStrBuf;
        a2->severity = E_EMPTY;
        if ( !v16 )
          free(pMem: severity);
      }
      (*(void (__thiscall **)(int *, int))*v13)(a1: v13, a2: 1);
    }
    else
    {
      v41 = "missing";
      (*(void (__thiscall **)(int *, int))*v13)(a1: v13, a2: 1);
    }
  }
  else
  {
    v17 = a1[66].__vftable;
    pMem.ep = nullptr;
    pMem.severity = E_EMPTY;
    v18 = (StrDict *)(*((int (__thiscall **)(StrDict_vtbl *, int))a1[(_DWORD)v17 + 62].dtr_StrDict + 21))(
                       a1: a1[(_DWORD)v17 + 62].__vftable,
                       a2: 2);
    VGetVar = v18->VGetVar;
    v18[10].__vftable = a1[54].__vftable;
    VGetVar(this: v18, a2: Var);
    v20 = FileSys::CheckType(this: (FileSys *)v18);
    v21 = &unk_100413A8;
    do
    {
      if ( v20 == *v21 )
        break;
      v21 += 6;
    }
    while ( v21[4] != 0 );
    if ( v21[4] == 0 )
      v21 = &unk_100413A8;
    switch ( v21[((int)a1[56].__vftable >= v21[1]) + 2] )
    {
      case 0:
        if ( v36 != nullptr )
          v22 = *v36;
        else
          v22 = (StrDict *)v21[4];
        v40 = v22;
        goto LABEL_28;
      case 1:
        if ( v36 != nullptr )
          v24 = *v36;
        else
          v24 = (StrDict *)v21[5];
        v40 = v24;
        v25 = (int *)((int (__thiscall *)(StrDict *))v18->VSetVar)(a1: v18);
        v35 = "exists";
        v33 = v21[4];
        v30 = *v25;
        Error::Set(this: (Error *)&pMem.genericCode, a2: &MsgClient::CheckFileAssume);
        goto LABEL_37;
      case 2:
        v40 = (StrDict *)v21[5];
        v27 = (int *)((int (__thiscall *)(StrDict *))v18->VSetVar)(a1: v18);
        v35 = (const char *)v21[4];
        v33 = v21[5];
        v30 = *v27;
        Error::Set(this: (Error *)&pMem.genericCode, a2: (const struct ErrorId *)&MsgClient::CheckFileSubst);
LABEL_37:
        Error::operator<<(a1: v30);
        Error::operator<<(a1: v33);
        Error::operator<<(a1: v35);
        v26 = a1[(int)a1[66].__vftable + 62].__vftable;
        (*((void (__thiscall **)(StrDict_vtbl *, int *))v26->dtr_StrDict + 3))(a1: v26, a2: &pMem.genericCode);
        goto LABEL_28;
      case 3:
        v28 = (int *)((int (__thiscall *)(StrDict *))v18->VSetVar)(a1: v18);
        v34 = v21[4];
        v31 = *v28;
        Error::Set(this: &pMem, a2: &MsgClient::CheckFileCant);
        Error::operator<<(a1: v31);
        Error::operator<<(a1: v34);
        v29 = a1[(int)a1[66].__vftable + 62].__vftable;
        (*((void (__thiscall **)(StrDict_vtbl *, Error *))v29->dtr_StrDict + 3))(a1: v29, a2: &pMem);
        ++a1[73].__vftable;
        ((void (__thiscall *)(StrDict *, int))v18->dtr_StrDict)(a1: v18, a2: 1);
        Error::~Error(this: &pMem);
        return;
      default:
LABEL_28:
        ((void (__thiscall *)(StrDict *, int))v18->dtr_StrDict)(a1: v18, a2: 1);
        Error::~Error(this: &pMem);
        break;
    }
  }
  StrDict::SetVar(this: a1, a2: "type", a3: (const char *)v40);
  StrDict::SetVar(this: a1, a2: "status", a3: v41);
  Client::Confirm(this: a1, a2: v38);
  if ( a2->severity > E_INFO )
  {
    v23 = a1[66].__vftable;
    ++a1[73].__vftable;
    v10 = a1[(_DWORD)v23 + 62].__vftable;
    goto LABEL_31;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000AFE0
// Name: void clientSendFile(class Client __near *,class Error __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall clientSendFile(int a1@<ebx>, StrDict *a2, struct Error *a3)
{
  struct StrPtr *v3; // eax
  const char **v4; // eax
  const char **v5; // ebp
  struct StrPtr *v6; // eax
  const char **v7; // eax
  StrDict_vtbl *v8; // eax
  int *v9; // eax
  FileSys *v10; // ebx
  int v11; // eax
  StrDict_vtbl *v12; // ecx
  void (__thiscall *Translator)(FileSys *, struct CharSetCvt *); // edx
  int v14; // ebp
  struct StrBuf *v15; // ebp
  int length; // ecx
  bool v17; // cc
  char *v18; // ebx
  int v19; // eax
  StrNum *v20; // eax
  struct StrPtr *v21; // eax
  StrDict_vtbl *v22; // edx
  struct StrPtr *v24; // [esp+28h] [ebp-110h]
  struct StrPtr *v25; // [esp+28h] [ebp-110h]
  struct StrPtr *v26; // [esp+28h] [ebp-110h]
  int *v27; // [esp+2Ch] [ebp-10Ch]
  int v28; // [esp+2Ch] [ebp-10Ch]
  FileSys *v29; // [esp+30h] [ebp-108h]
  _BYTE v30[12]; // [esp+34h] [ebp-104h]
  BOOL pMem; // [esp+40h] [ebp-F8h]
  struct StrPtr v32; // [esp+44h] [ebp-F4h] BYREF
  int v33; // [esp+4Ch] [ebp-ECh]
  struct StrPtr *v34; // [esp+50h] [ebp-E8h]
  struct StrPtr *v35; // [esp+54h] [ebp-E4h]
  struct StrBuf v36; // [esp+58h] [ebp-E0h] BYREF
  struct StrPtr *Var; // [esp+64h] [ebp-D4h]
  struct StrPtr *v38; // [esp+68h] [ebp-D0h]
  struct StrPtr *v39; // [esp+6Ch] [ebp-CCh]
  const char **v40; // [esp+70h] [ebp-C8h]
  StrNum v41; // [esp+74h] [ebp-C4h] BYREF
  char v42[4]; // [esp+94h] [ebp-A4h] BYREF
  _BYTE v43[156]; // [esp+98h] [ebp-A0h] BYREF

  Client::NewHandler(this: (Client *)a2);
  StrDict::GetVar(this: (StrDict *)a2[53].__vftable, a2: "path", a3);
  FileSys::Set(this: (FileSys *)a2, a2: "type");
  FileSys::Set(this: (FileSys *)a2, a2: "perms");
  v35 = v3;
  Var = StrDict::GetVar(this: a2, a2: "handle", a3);
  StrDict::GetVar(this: a2, a2: "open", a3);
  v39 = StrDict::GetVar(this: a2, a2: "write", a3);
  v34 = StrDict::GetVar(this: a2, a2: "confirm", a3);
  v38 = StrDict::GetVar(this: a2, a2: "decline", a3);
  FileSys::Set(this: (FileSys *)a2, a2: "serverDigest");
  v5 = v4;
  FileSys::Set(this: (FileSys *)a2, a2: "revertUnchanged");
  v24 = v6;
  FileSys::Set(this: (FileSys *)a2, a2: "reopen");
  v40 = v7;
  if ( a3->severity > E_INFO && a3->severity != E_FATAL )
  {
    v8 = a2[66].__vftable;
    ++a2[73].__vftable;
    (*((void (__thiscall **)(StrDict_vtbl *, struct Error *))a2[(_DWORD)v8 + 62].dtr_StrDict + 2))(
      a1: a2[(_DWORD)v8 + 62].__vftable,
      a2: a3);
    a3->severity = E_EMPTY;
    return;
  }
  v9 = sub_10009710(a1: a3, (int)a2);
  v10 = (FileSys *)v9;
  v27 = v9;
  if ( a3->severity <= E_INFO )
  {
    *(_QWORD *)v30 = (unsigned int)(*(int (__thiscall **)(int *, int))(*v9 + 40))(a1: v9, a2: a1);
    v11 = (int)a2[57].__vftable;
    Var = nullptr;
    v36.size = 0;
    pMem = v11 >= 17;
    v36.length = (int)StrBuf::nullStrBuf;
    v34 = (struct StrPtr *)(v11 >= 19);
    *(_DWORD *)&v30[8] = 0;
    MD5::MD5(this: (MD5 *)v43);
    if ( v5 != nullptr )
    {
      v12 = a2[49].__vftable;
      v33 = 0;
      v32.length = 0;
      Translator = v10->Translator;
      v32.buffer = StrBuf::nullStrBuf;
      Translator(this: v10, a2: (struct CharSetCvt *)v12);
      v10->Digest(this: v10, a2: (StrBuf *)&v32, a3);
      if ( a3->severity <= E_INFO && strcmp(v32.buffer, *v5) == 0 )
      {
        StrDict::SetVar(this: a2, a2: "status", a3: "same");
        StrDict::SetVar(this: a2, a2: "digest", a3: &v32);
        Client::Confirm(this: a2, a2: v35);
        if ( a3->severity <= E_INFO && v36.buffer != nullptr && v27 != nullptr )
          FileSys::Chmod2(this: v10, a2: *(char **)v36.buffer, a3);
        ((void (__thiscall *)(FileSys *, int))v10->dtr_FileSys)(a1: v10, a2: 1);
        if ( (char *)pMem != StrBuf::nullStrBuf )
          free((void *)pMem);
LABEL_47:
        if ( v36.buffer != StrBuf::nullStrBuf )
          free(pMem: v36.buffer);
        return;
      }
      if ( v32.buffer != StrBuf::nullStrBuf )
        free(pMem: v32.buffer);
    }
    v14 = *(_DWORD *)v30;
    if ( *(_DWORD *)v30 != 0 && !pMem )
      StrDict::SetVar(this: a2, a2: "time", a3: *(int *)v30);
    Client::Confirm(this: a2, a2: v24);
    v10->Open(this: v10, a2: FOM_READ, a3);
    v28 = FileSys::BufferSize();
    if ( a3->severity <= E_INFO )
    {
      v10->Translator(this: v10, a2: (struct CharSetCvt *)a2[49].__vftable);
      if ( Rpc::Dropped(this: (Rpc *)a2) == 0 )
      {
        while ( 1 )
        {
          v15 = Rpc::MakeVar(this: (Rpc *)a2, a2: "data");
          length = v15->length;
          v17 = length + v28 <= v15->size;
          v25 = (struct StrPtr *)length;
          v15->length = length + v28;
          if ( !v17 )
            StrBuf::Grow(this: v15, a2: length);
          v18 = (char *)v25 + (unsigned int)v15->buffer;
          v19 = v29->Read(this: v29, a2: v18, a3: v28, a4: a3);
          v26 = (struct StrPtr *)v19;
          if ( a3->severity > E_INFO )
            break;
          v15->length = (int)&v18[v19 - (unsigned int)v15->buffer];
          if ( v19 != 0 )
          {
            if ( pMem )
            {
              v32.buffer = v18;
              v32.length = v19;
              MD5::Update(this: (MD5 *)v43, a2: &v32);
              v19 = (int)v26;
            }
            if ( v34 != nullptr )
              *(_QWORD *)&v30[4] += v19;
            StrDict::SetVar(this: a2, a2: "handle", a3: v38);
            Rpc::Invoke(this: a2, a2: *v40);
            if ( Rpc::Dropped(this: (Rpc *)a2) == 0 )
              continue;
          }
          goto LABEL_32;
        }
        v15->length = v18 - v15->buffer;
LABEL_32:
        v10 = v29;
      }
      v10->Close(this: v10, a2: a3);
      if ( a3->severity <= E_INFO && v36.buffer != nullptr && v41.buffer == nullptr )
        FileSys::Chmod2(this: v10, a2: *(char **)v36.buffer, a3);
      v14 = *(_DWORD *)v30;
    }
    ((void (__thiscall *)(FileSys *, int))v10->dtr_FileSys)(a1: v10, a2: 1);
    if ( *(_DWORD *)&v30[8] != 0 )
    {
      if ( v33 != 0 )
      {
        v20 = StrNum::StrNum(this: &v41, a2: *(__int64 *)v30);
        StrDict::SetVar(this: a2, a2: "fileSize", a3: v20);
      }
      MD5::Final(this: (MD5 *)v42, a2: &v36);
      StrDict::SetVar(this: a2, a2: "digest", a3: &v36);
      if ( v14 != 0 )
        StrDict::SetVar(this: a2, a2: "time", a3: v14);
    }
    v21 = v38;
    if ( a3->severity <= E_INFO )
      v21 = v34;
    Client::Confirm(this: a2, a2: v21);
    if ( a3->severity > E_INFO )
    {
      v22 = a2[66].__vftable;
      ++a2[73].__vftable;
      (*((void (__thiscall **)(StrDict_vtbl *, struct Error *))a2[(_DWORD)v22 + 62].dtr_StrDict + 2))(
        a1: a2[(_DWORD)v22 + 62].__vftable,
        a2: a3);
      a3->severity = E_EMPTY;
    }
    goto LABEL_47;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B4A0
// Name: void clientEditData(class Client __near *,class Error __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall clientEditData(int a1@<edi>, StrDict *a2, struct Error *a3, struct StrPtr *a4)
{
  const struct StrPtr *v5; // eax
  const struct StrPtr *v6; // ebp
  const struct StrPtr *v7; // eax
  int v8; // eax
  bool v9; // cc
  StrDict_vtbl *v10; // ecx
  int v11; // edi
  StrDict_vtbl *v12; // ecx
  bool v13; // zf
  const char *v14; // eax
  StrDict_vtbl *v15; // eax
  const struct StrPtr *v16; // [esp+18h] [ebp-14h]
  int v17; // [esp+1Ch] [ebp-10h]
  struct StrPtr pMem; // [esp+20h] [ebp-Ch] BYREF
  int v19; // [esp+28h] [ebp-4h]
  struct StrPtr *Var; // [esp+34h] [ebp+8h]

  Var = StrDict::GetVar(this: a2, a2: "data", a3);
  FileSys::Set(this: (FileSys *)a2, a2: "confirm");
  v6 = v5;
  FileSys::Set(this: (FileSys *)a2, a2: "decline");
  v16 = v7;
  FileSys::Set(this: (FileSys *)a2, a2: "compare");
  v17 = v8;
  v9 = a3->severity <= E_INFO;
  v19 = 0;
  pMem.length = 0;
  pMem.buffer = StrBuf::nullStrBuf;
  if ( v9 )
  {
    v10 = a2[(int)a2[66].__vftable + 62].__vftable;
    v11 = (*((int (__thiscall **)(StrDict_vtbl *, int, int))v10->dtr_StrDict + 21))(a1: v10, a2: 12, a3: a1);
    *(StrDict *)(v11 + 40) = a2[54];
    *(_DWORD *)(v11 + 32) = 1;
    FileSys::MakeGlobalTemp(this: (FileSys *)v11);
    if ( v6 != nullptr )
      *(_DWORD *)(v11 + 8) = 1;
    (*(void (__thiscall **)(int, StrDict_vtbl *))(*(_DWORD *)v11 + 16))(a1: v11, a2: a2[50].__vftable);
    if ( a3->severity <= E_INFO )
    {
      FileSys::WriteFile(this: (FileSys *)v11, a2: a4, a3);
      if ( a3->severity <= E_INFO )
      {
        v12 = a2[(int)a2[66].__vftable + 62].__vftable;
        (*((void (__thiscall **)(StrDict_vtbl *, int, struct Error *))v12->dtr_StrDict + 15))(a1: v12, a2: v11, a3);
      }
    }
    (*(void (__thiscall **)(int, StrDict_vtbl *))(*(_DWORD *)v11 + 16))(a1: v11, a2: a2[51].__vftable);
    if ( a3->severity <= E_INFO )
      FileSys::ReadFile(this: (FileSys *)v11, a2: (StrBuf *)&pMem.length, a3);
    (**(void (__thiscall ***)(int, int))v11)(a1: v11, a2: 1);
    if ( a3->severity > E_INFO )
      v6 = v16;
    if ( v6 != nullptr )
    {
      if ( v17 != 0 )
      {
        v13 = !StrPtr::operator==(this: (const char **)&pMem.buffer, a2: (const char **)&Var->buffer);
        v14 = "same";
        if ( v13 )
          v14 = "diff";
        StrDict::SetVar(this: a2, a2: "compare", a3: v14);
      }
      StrDict::SetVar(this: a2, a2: "data", a3: &pMem);
      Client::Confirm(this: a2, a2: v6);
    }
    if ( a3->severity > E_INFO )
    {
      v15 = a2[66].__vftable;
      ++a2[73].__vftable;
      (*((void (__thiscall **)(StrDict_vtbl *, struct Error *))a2[(_DWORD)v15 + 62].dtr_StrDict + 2))(
        a1: a2[(_DWORD)v15 + 62].__vftable,
        a2: a3);
      a3->severity = E_EMPTY;
    }
    if ( pMem.buffer != StrBuf::nullStrBuf )
      free(pMem: pMem.buffer);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B650
// Name: void clientInputData(class Client __near *,class Error __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl clientInputData(StrDict *a1, struct Error *a2)
{
  const struct StrPtr *Var; // ebx
  StrDict_vtbl *v3; // eax
  struct StrPtr pMem; // [esp+Ch] [ebp-Ch] BYREF
  int v5; // [esp+14h] [ebp-4h]

  Client::NewHandler(this: (Client *)a1);
  Var = StrDict::GetVar(this: a1, a2: "confirm", a3: a2);
  v5 = 0;
  pMem.length = 0;
  v3 = a1[66].__vftable;
  pMem.buffer = StrBuf::nullStrBuf;
  (*((void (__thiscall **)(StrDict_vtbl *, struct StrPtr *, struct Error *))a1[(_DWORD)v3 + 62].dtr_StrDict + 1))(
    a1: a1[(_DWORD)v3 + 62].__vftable,
    a2: &pMem,
    a3: a2);
  StrDict::SetVar(this: (StrDict *)a1[52].__vftable, a2: "data", a3: &pMem);
  Client::Confirm(this: a1, a2: Var);
  if ( pMem.buffer != StrBuf::nullStrBuf )
    free(pMem: pMem.buffer);
}

//------------------------------------------------------------------------------
// Address: 0x1000B6E0
// Name: void clientScanDir(class Client __near *,class Error __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall clientScanDir(int a1@<esi>, StrDict *a2, struct Error *a3)
{
  struct StrPtr *Var; // ebx
  StrDict_vtbl *v4; // eax
  StrDict_vtbl *v5; // ecx
  StrDict *v6; // esi
  StrPtr *(__thiscall *VGetVar)(StrDict *, const StrPtr *); // eax
  StrArray *v8; // eax
  StrArray *v9; // ebx
  StrDict_vtbl *v10; // ecx
  struct PathSys *v11; // edi
  void (__thiscall **v12)(struct PathSys *, void *, const struct StrBuf *); // edi
  const struct StrBuf *v13; // eax
  char v14; // al
  const struct StrBuf *v15; // [esp+14h] [ebp-18h]
  const struct StrBuf *v16; // [esp+14h] [ebp-18h]
  struct StrPtr *v17; // [esp+24h] [ebp-8h]
  void *retaddr; // [esp+2Ch] [ebp+0h]
  struct Error *i; // [esp+34h] [ebp+8h]
  struct PathSys *v20; // [esp+38h] [ebp+Ch]

  Client::NewHandler(this: (Client *)a2);
  Var = StrDict::GetVar(this: (StrDict *)a2[53].__vftable, a2: "dir", a3);
  v17 = StrDict::GetVar(this: a2, a2: "confirm", a3);
  if ( a3->severity <= E_INFO )
  {
    v5 = a2[(int)a2[66].__vftable + 62].__vftable;
    v6 = (StrDict *)(*((int (__thiscall **)(StrDict_vtbl *, int, int))v5->dtr_StrDict + 21))(a1: v5, a2: 2, a3: a1);
    VGetVar = v6->VGetVar;
    v6[10].__vftable = a2[54].__vftable;
    VGetVar(this: v6, a2: Var);
    v8 = (StrArray *)((int (__thiscall *)(StrDict *, struct Error *))v6->__vftable[2].VClear)(a1: v6, a2: a3);
    v9 = v8;
    if ( a3->severity <= E_INFO )
    {
      StrArray::Sort(this: v8, a2: 0);
      v11 = PathSys::Create();
      v20 = v11;
      (*(void (__thiscall **)(struct PathSys *, StrDict_vtbl *))(*(_DWORD *)v11 + 20))(a1: v11, a2: v6[9].__vftable);
      for ( i = nullptr; (int)i < StrArray::Count(this: v9); v11 = v20 )
      {
        v12 = (void (__thiscall **)(struct PathSys *, void *, const struct StrBuf *))(*(_DWORD *)v11 + 8);
        v13 = StrArray::Get(this: v9, a2: (int)i);
        (*v12)(a1: v20, a2: retaddr, a3: v13);
        v6->VGetVar(this: v6, a2: (const StrPtr *)((char *)v20 + 4));
        v14 = ((int (__thiscall *)(StrDict *))v6->__vftable[1].VSetVar)(a1: v6);
        if ( (v14 & 4) != 0 )
        {
          v15 = StrArray::Get(this: v9, a2: (int)i);
          StrDict::SetVar(this: a2, a2: "dir", a3: v15);
        }
        else if ( (v14 & 1) != 0 )
        {
          v16 = StrArray::Get(this: v9, a2: (int)i);
          StrDict::SetVar(this: a2, a2: "file", a3: v16);
        }
        i = (struct Error *)((char *)i + 1);
      }
      (**(void (__thiscall ***)(struct PathSys *, int))v11)(a1: v11, a2: 1);
      if ( v9 != nullptr )
      {
        StrArray::~StrArray(this: v9);
        free(pMem: v9);
      }
      ((void (__thiscall *)(StrDict *, int))v6->dtr_StrDict)(a1: v6, a2: 1);
      Client::Confirm(this: a2, a2: v17);
    }
    else
    {
      ((void (__thiscall *)(StrDict *, int))v6->dtr_StrDict)(a1: v6, a2: 1);
      if ( a3->severity > E_INFO )
      {
        ++a2[73].__vftable;
        v10 = a2[(int)a2[66].__vftable + 62].__vftable;
        (*((void (__thiscall **)(StrDict_vtbl *, struct Error *))v10->dtr_StrDict + 2))(a1: v10, a2: a3);
        a3->severity = E_EMPTY;
      }
      Client::Confirm(this: a2, a2: v17);
    }
  }
  else if ( a3->severity != E_FATAL )
  {
    v4 = a2[66].__vftable;
    ++a2[73].__vftable;
    (*((void (__thiscall **)(StrDict_vtbl *, struct Error *))a2[(_DWORD)v4 + 62].dtr_StrDict + 2))(
      a1: a2[(_DWORD)v4 + 62].__vftable,
      a2: a3);
    a3->severity = E_EMPTY;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B8E0
// Name: void clientPrompt(class Client __near *,class Error __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl clientPrompt(StrDict *a1, struct Error *a2)
{
  struct StrPtr *Var; // ebx
  int v3; // eax
  int v4; // eax
  int v5; // ebp
  struct StrPtr *v6; // eax
  struct StrPtr *v7; // eax
  struct StrPtr *v8; // eax
  ErrorSeverity severity; // eax
  bool v10; // cc
  StrDict_vtbl *v11; // eax
  StrDict_vtbl *v12; // ecx
  struct StrPtr *v13; // ebx
  StrDict *v14; // eax
  const char *v15; // eax
  const struct StrPtr *v16; // ebx
  int v17; // eax
  StrBuf v18; // [esp+1Ch] [ebp-1B0h] BYREF
  struct StrPtr *v19; // [esp+28h] [ebp-1A4h] BYREF
  struct StrPtr *v20; // [esp+2Ch] [ebp-1A0h]
  struct StrBuf pMem; // [esp+30h] [ebp-19Ch] BYREF
  struct StrPtr *v22; // [esp+3Ch] [ebp-190h]
  int v23; // [esp+40h] [ebp-18Ch]
  struct StrPtr *v24; // [esp+44h] [ebp-188h]
  _BYTE v25[224]; // [esp+48h] [ebp-184h] BYREF
  _BYTE v26[160]; // [esp+128h] [ebp-A4h] BYREF

  Client::NewHandler(this: (Client *)a1);
  Var = StrDict::GetVar(this: (StrDict *)a1[52].__vftable, a2: "data", a3: a2);
  v22 = StrDict::GetVar(this: a1, a2: "confirm", a3: a2);
  FileSys::Set(this: (FileSys *)a1, a2: "truncate");
  v23 = v3;
  FileSys::Set(this: (FileSys *)a1, a2: "noecho");
  v5 = v4;
  FileSys::Set(this: (FileSys *)a1, a2: "digest");
  v19 = v6;
  FileSys::Set(this: (FileSys *)a1, a2: "mangle");
  v20 = v7;
  FileSys::Set(this: (FileSys *)a1, a2: "user");
  v24 = v8;
  v18.size = 0;
  v18.length = 0;
  severity = a2->severity;
  v10 = a2->severity <= E_INFO;
  v18.buffer = StrBuf::nullStrBuf;
  if ( v10 )
  {
    v12 = a1[(int)a1[66].__vftable + 62].__vftable;
    (*((void (__thiscall **)(StrDict_vtbl *, struct StrPtr *, StrBuf *, bool, struct Error *))v12->dtr_StrDict + 13))(
      a1: v12,
      a2: Var,
      a3: &v18,
      a4: v5 != 0,
      a5: a2);
    if ( a2->severity > E_INFO )
      goto LABEL_37;
    v13 = v19;
    if ( v20 == nullptr && v19 == nullptr )
    {
      if ( a1[120].__vftable == nullptr )
        goto LABEL_35;
      v13 = (struct StrPtr *)&a1[119];
    }
    if ( v18.length != 0 )
    {
      MD5::MD5(this: (MD5 *)v26);
      v14 = (StrDict *)a1[52].__vftable;
      if ( a1 != v14 )
      {
        v19 = nullptr;
        v15 = (const char *)(*((int (__thiscall **)(StrDict_vtbl *, char *, int, struct StrPtr **))v14[6].dtr_StrDict + 7))(
                              a1: v14[6].__vftable,
                              a2: v18.buffer,
                              a3: v18.length,
                              a4: &v19);
        if ( v15 != nullptr )
        {
          v18.length = 0;
          StrBuf::Append(this: &v18, src: v15, a3: (int)v19);
        }
      }
      if ( v23 != 0 && v18.length > 16 )
        v18.length = 16;
      if ( v13 != nullptr )
      {
        MD5::Update(this: (MD5 *)v26, a2: &v18);
        MD5::Final(this: (MD5 *)v26, a2: &v18);
        if ( (int)a1[57].__vftable >= 20 )
        {
          a1[111].__vftable = nullptr;
          StrBuf::Append(this: (StrBuf *)&a1[110], a2: &v18);
        }
        if ( v13->length != 0 )
        {
          MD5::MD5(this: (MD5 *)v25);
          MD5::Update(this: (MD5 *)v25, a2: &v18);
          MD5::Update(this: (MD5 *)v25, a2: v13);
          MD5::Final(this: (MD5 *)v25, a2: &v18);
        }
        if ( a1[120].__vftable != nullptr )
        {
          MD5::MD5(this: (MD5 *)v25);
          MD5::Update(this: (MD5 *)v25, a2: &v18);
          MD5::Update(this: (MD5 *)v25, a2: (const struct StrPtr *)&a1[119]);
          MD5::Final(this: (MD5 *)v25, a2: &v18);
          StrDict::SetVar(this: a1, a2: "ipaddr", a3: (const char *)a1[119].__vftable);
        }
        StrDict::SetVar(this: a1, a2: "data", a3: &v18);
      }
      else
      {
        Mangle::Mangle(this: (Mangle *)v25);
        v16 = nullptr;
        v10 = (int)a1[57].__vftable < 20;
        pMem.size = 0;
        pMem.length = 0;
        pMem.buffer = StrBuf::nullStrBuf;
        if ( !v10 )
          v16 = (const struct StrPtr *)&a1[110];
        MD5::Update(this: (MD5 *)v26, a2: v20);
        MD5::Update(this: (MD5 *)v26, a2: v24);
        if ( v16 != nullptr && v16->length != 0 )
        {
          MD5::Update(this: (MD5 *)v26, a2: v16);
          FileSys::Set(this: (FileSys *)a1, a2: "data2");
          if ( v17 != 0 )
            a1[111].__vftable = nullptr;
        }
        MD5::Final(this: (MD5 *)v26, a2: &pMem);
        Mangle::DoIt(this: (Mangle *)v25, a2: &v18, a3: &pMem, a4: &pMem, a5: 0, a6: 0, a7: a2);
        if ( a2->severity > E_INFO )
        {
          if ( pMem.buffer != StrBuf::nullStrBuf )
            free(pMem: pMem.buffer);
          goto LABEL_37;
        }
        StrDict::SetVar(this: a1, a2: "data", a3: &pMem);
        if ( pMem.buffer != StrBuf::nullStrBuf )
          free(pMem: pMem.buffer);
      }
      goto LABEL_36;
    }
LABEL_35:
    StrDict::SetVar(this: (StrDict *)a1[52].__vftable, a2: "data", a3: &v18);
LABEL_36:
    Client::Confirm(this: a1, a2: v22);
    goto LABEL_37;
  }
  if ( severity == E_FATAL )
    return;
  v11 = a1[66].__vftable;
  ++a1[73].__vftable;
  (*((void (__thiscall **)(StrDict_vtbl *, struct Error *))a1[(_DWORD)v11 + 62].dtr_StrDict + 2))(
    a1: a1[(_DWORD)v11 + 62].__vftable,
    a2);
  a2->severity = E_EMPTY;
LABEL_37:
  if ( v18.buffer != StrBuf::nullStrBuf )
    free(pMem: v18.buffer);
}

//------------------------------------------------------------------------------
// Address: 0x1000BC90
// Name: void clientSingleSignon(class Client __near *,class Error __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl clientSingleSignon(StrDict *a1, struct StrPtr *a2)
{
  StrDict_vtbl *v3; // eax
  RunCommand *v4; // eax
  RunCommand *v5; // esi
  struct StrPtr *Var; // [esp+8h] [ebp-1Ch]
  StrBuf pMem; // [esp+Ch] [ebp-18h] BYREF
  StrBuf v8; // [esp+18h] [ebp-Ch] BYREF
  StrBuf *LoginSSO; // [esp+2Ch] [ebp+8h]

  Var = StrDict::GetVar(this: a1, a2: "confirm", a3: (struct Error *)a2);
  if ( (int)a2->buffer <= 1 )
  {
    LoginSSO = (StrBuf *)Client::GetLoginSSO(this: (Enviro **)a1);
    if ( strcmp(LoginSSO->buffer, "unset") == 0 )
    {
      StrDict::SetVar(this: a1, a2: "status", a3: "unset");
      StrDict::SetVar(this: a1, a2: "sso");
      Client::Confirm(this: a1, a2: Var);
    }
    else
    {
      v4 = (RunCommand *)operator new(nSize: 4u);
      if ( v4 != nullptr )
        v5 = RunCommand::RunCommand(this: v4);
      else
        v5 = nullptr;
      v8.size = 0;
      v8.length = 0;
      v8.buffer = StrBuf::nullStrBuf;
      if ( &v8 != LoginSSO )
      {
        v8.length = 0;
        StrBuf::Append(this: &v8, a2: LoginSSO);
      }
      pMem.size = 0;
      pMem.length = 0;
      pMem.buffer = StrBuf::nullStrBuf;
      if ( RunCommand::RunOut(this: v5, a2: (struct RunArgs *)&v8, a3: &StrRef::null, a4: &pMem, a5: (struct Error *)a2) != 0
        || (int)a2->buffer > 1 )
      {
        StrDict::SetVar(this: a1, a2: "status", a3: "fail");
      }
      else
      {
        StrDict::SetVar(this: a1, a2: "status", a3: "pass");
      }
      if ( pMem.length > 0x20000 )
      {
        pMem.length = 131073;
        if ( pMem.size < 131073 )
          StrBuf::Grow(this: &pMem, a2: 0x20000);
        pMem.buffer[0x20000] = 0;
        --pMem.length;
      }
      StrDict::SetVar(this: a1, a2: "sso", a3: &pMem);
      if ( v5 != nullptr )
      {
        RunCommand::~RunCommand(this: v5);
        free(pMem: v5);
      }
      if ( pMem.buffer != StrBuf::nullStrBuf )
        free(pMem: pMem.buffer);
      if ( v8.buffer != StrBuf::nullStrBuf )
        free(pMem: v8.buffer);
      Client::Confirm(this: a1, a2: Var);
    }
  }
  else if ( a2->buffer != (char *)4 )
  {
    v3 = a1[66].__vftable;
    ++a1[73].__vftable;
    (*((void (__thiscall **)(StrDict_vtbl *, struct StrPtr *))a1[(_DWORD)v3 + 62].dtr_StrDict + 2))(
      a1: a1[(_DWORD)v3 + 62].__vftable,
      a2);
    a2->buffer = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000BE60
// Name: void clientCrypto(class Client __near *,class Error __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl clientCrypto(StrDict *a1, struct Error *a2)
{
  struct StrPtr *Var; // ebx
  int v3; // eax
  const char **v4; // eax
  const char *v5; // eax
  const struct StrPtr *Password; // ebp
  StrBuf *Password2; // eax
  bool v8; // zf
  const char *buffer; // ecx
  int v10; // ebx
  StrDict *v11; // eax
  const char *v12; // eax
  StrBuf pMem; // [esp+Ch] [ebp-C8h] BYREF
  int v14; // [esp+18h] [ebp-BCh] BYREF
  struct StrPtr *v15; // [esp+1Ch] [ebp-B8h]
  const char **p_buffer; // [esp+20h] [ebp-B4h]
  StrBuf *v17; // [esp+24h] [ebp-B0h]
  int v18; // [esp+28h] [ebp-ACh]
  int v19; // [esp+2Ch] [ebp-A8h]
  _BYTE v20[160]; // [esp+30h] [ebp-A4h] BYREF

  Var = StrDict::GetVar(this: a1, a2: "confirm", a3: a2);
  p_buffer = (const char **)&Var->buffer;
  v15 = StrDict::GetVar(this: a1, a2: "token", a3: a2);
  FileSys::Set(this: (FileSys *)a1, a2: "truncate");
  v18 = v3;
  FileSys::Set(this: (FileSys *)a1, a2: "serverAddress");
  if ( a2->severity <= E_INFO )
  {
    if ( v4 != nullptr )
      v5 = *v4;
    else
      v5 = byte_10040CDC;
    a1[93].__vftable = nullptr;
    StrBuf::Append(this: (StrBuf *)&a1[92], src: v5);
    pMem.size = 0;
    pMem.length = 0;
    pMem.buffer = StrBuf::nullStrBuf;
    Password = Client::GetPassword(this: (Client *)a1, a2: 0);
    Password2 = (StrBuf *)Client::GetPassword2(this: (Client *)a1);
    v8 = Password->length == 0;
    v17 = Password2;
    if ( v8 )
    {
      StrDict::SetVar(this: a1, a2: "token", a3: &pMem);
      buffer = Var->buffer;
    }
    else
    {
      v10 = 0;
      v19 = (Password2->length != 0) + 1;
      if ( v19 > 0 )
      {
        while ( 1 )
        {
          if ( v10 == 0 )
            Password2 = (StrBuf *)Password;
          if ( &pMem != Password2 )
          {
            pMem.length = 0;
            StrBuf::Append(this: &pMem, a2: Password2);
          }
          if ( pMem.length != 32 )
          {
            MD5::MD5(this: (MD5 *)v20);
            v11 = (StrDict *)a1[52].__vftable;
            if ( a1 == v11 )
            {
              if ( v18 != 0 && pMem.length > 16 )
                pMem.length = 16;
            }
            else
            {
              v14 = 0;
              v12 = (const char *)(*((int (__thiscall **)(StrDict_vtbl *, char *, int, int *))v11[6].dtr_StrDict + 7))(
                                    a1: v11[6].__vftable,
                                    a2: pMem.buffer,
                                    a3: pMem.length,
                                    a4: &v14);
              if ( v12 != nullptr )
              {
                pMem.length = 0;
                StrBuf::Append(this: &pMem, src: v12, a3: v14);
              }
            }
            MD5::Update(this: (MD5 *)v20, a2: &pMem);
            MD5::Final(this: (MD5 *)v20, a2: &pMem);
          }
          MD5::MD5(this: (MD5 *)v20);
          MD5::Update(this: (MD5 *)v20, a2: v15);
          MD5::Update(this: (MD5 *)v20, a2: &pMem);
          MD5::Final(this: (MD5 *)v20, a2: &pMem);
          if ( a1[120].__vftable != nullptr )
          {
            MD5::MD5(this: (MD5 *)v20);
            MD5::Update(this: (MD5 *)v20, a2: &pMem);
            MD5::Update(this: (MD5 *)v20, a2: (const struct StrPtr *)&a1[119]);
            MD5::Final(this: (MD5 *)v20, a2: &pMem);
          }
          if ( v10 != 0 )
            StrDict::SetVar(this: a1, a2: "token2", a3: &pMem);
          else
            StrDict::SetVar(this: a1, a2: "token", a3: &pMem);
          if ( ++v10 >= v19 )
            break;
          Password2 = v17;
        }
      }
      if ( a1[120].__vftable != nullptr )
        StrDict::SetVar(this: a1, a2: "ipaddr", a3: (const char *)a1[119].__vftable);
      buffer = *p_buffer;
    }
    Rpc::Invoke(this: a1, a2: buffer);
    if ( pMem.buffer != StrBuf::nullStrBuf )
      free(pMem: pMem.buffer);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000C0F0
// Name: void clientProtocol(class Client __near *,class Error __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl clientProtocol(FileSys *a1)
{
  const char **v1; // eax
  const char **v2; // eax
  const char **v3; // eax
  int v4; // eax
  int v5; // eax

  FileSys::Set(this: a1, a2: "xfiles");
  if ( v1 != nullptr )
    a1[5].mode = atoi(nptr: *v1);
  FileSys::Set(this: a1, a2: "server2");
  if ( v2 != nullptr || (FileSys::Set(this: a1, a2: "server"), v2 != nullptr) )
    a1[5].perms = atoi(nptr: *v2);
  FileSys::Set(this: a1, a2: "security");
  if ( v3 != nullptr )
    a1[5].path.buffer = (char *)atoi(nptr: *v3);
  FileSys::Set(this: a1, a2: "nocase");
  a1[5].modTime = v4 != 0;
  FileSys::Set(this: a1, a2: "unicode");
  a1[5].path.length = v5 != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000C1A0
// Name: void clientSetPassword(class Client __near *,class Error __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl clientSetPassword(FileSys *a1, struct Error *a2)
{
  struct StrPtr *Var; // edi
  struct StrPtr *v3; // eax
  const char *buffer; // eax
  const char **v5; // eax
  StrBuf *v6; // eax
  StrBuf *p_pMem; // ebp
  const struct StrPtr *TicketFile; // eax
  StrBuf *Port; // eax
  const struct StrPtr *v10; // eax
  const struct StrPtr *v11; // eax
  StrBuf *v12; // eax
  struct StrPtr *v13; // [esp+Ch] [ebp-38h]
  const char **v14; // [esp+14h] [ebp-30h]
  _DWORD v15[2]; // [esp+18h] [ebp-2Ch] BYREF
  StrBuf pMem; // [esp+20h] [ebp-24h] BYREF
  _BYTE v17[12]; // [esp+2Ch] [ebp-18h] BYREF
  _BYTE v18[12]; // [esp+38h] [ebp-Ch] BYREF

  Client::NewHandler(this: (Client *)a1);
  Var = StrDict::GetVar(this: (StrDict *)a1, a2: "data", a3: a2);
  FileSys::Set(this: a1, a2: "serverAddress");
  v13 = v3;
  if ( a2->severity <= E_INFO )
  {
    buffer = Var->buffer;
    a1[9].__vftable = nullptr;
    StrBuf::Append(this: (StrBuf *)&a1[8].content_charSet, src: buffer);
    a1[6].perms = FPM_RO;
    FileSys::Set(this: a1, a2: "data2");
    v14 = v5;
    FileSys::Set(this: a1, a2: "user");
    p_pMem = v6;
    v15[0] = "******";
    v15[1] = 6;
    pMem.size = 0;
    pMem.length = 0;
    pMem.buffer = StrBuf::nullStrBuf;
    if ( v6 != nullptr )
    {
      if ( a1[5].modTime != 0 )
      {
        if ( &pMem != v6 )
        {
          pMem.length = 0;
          StrBuf::Append(this: &pMem, a2: v6);
        }
        StrOps::Lower(a1: &pMem);
        p_pMem = &pMem;
      }
    }
    else
    {
      p_pMem = (StrBuf *)v15;
    }
    if ( v14 != nullptr )
    {
      if ( strcmp(*v14, "login") == 0 )
      {
        TicketFile = Client::GetTicketFile(this: (Client *)a1);
        Ticket::Ticket(this: (Ticket *)v17, a2: TicketFile);
        Port = (StrBuf *)v13;
        if ( v13 == nullptr )
          Port = Client::GetPort(this: (Client *)a1);
        Ticket::UpdateTicket(this: (Ticket *)v17, a2: Port, a3: p_pMem, a4: Var, a5: 0, a6: a2);
        Ticket::~Ticket(this: (Ticket *)v17);
        goto LABEL_18;
      }
      if ( strcmp(*v14, "logout") == 0 )
      {
        if ( v13 != nullptr )
        {
          v10 = Client::GetTicketFile(this: (Client *)a1);
          Ticket::Ticket(this: (Ticket *)v17, a2: v10);
          Ticket::UpdateTicket(this: (Ticket *)v17, a2: v13, a3: p_pMem, a4: p_pMem, a5: 1, a6: a2);
          Ticket::~Ticket(this: (Ticket *)v17);
        }
        v11 = Client::GetTicketFile(this: (Client *)a1);
        Ticket::Ticket(this: (Ticket *)v18, a2: v11);
        v12 = Client::GetPort(this: (Client *)a1);
        Ticket::UpdateTicket(this: (Ticket *)v18, a2: v12, a3: p_pMem, a4: p_pMem, a5: 1, a6: a2);
        Ticket::~Ticket(this: (Ticket *)v18);
        goto LABEL_18;
      }
    }
    Client::DefinePassword(this: (Client *)a1, src: Var->buffer, a3: a2);
    a2->severity = E_EMPTY;
LABEL_18:
    if ( pMem.buffer != StrBuf::nullStrBuf )
      free(pMem: pMem.buffer);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000C390
// Name: public: virtual void ClientMerge::CopyDigest(class StrPtr __near *,class Error __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall ClientMerge::CopyDigest(ClientMerge *this, struct StrPtr *a2, struct Error *a3)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1000C3A0
// Name: public: virtual int ClientMerge::Chmod(char __near *,class Error __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall ClientMerge::Chmod(ClientMerge *this, char *a2, struct Error *a3)
{
  this->Chmod_2(this, a2, a3);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000C3C0
// Name: public: virtual class FileSys __near * ClientMerge3::GetBaseFile(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct FileSys *__thiscall ClientMerge3::GetBaseFile(ClientMerge3 *this)
{
  return *((struct FileSys **)this + 20);
}

//------------------------------------------------------------------------------
// Address: 0x1000C3D0
// Name: public: virtual int ClientMerge2::GetBothChunks(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall ClientMerge2::GetBothChunks(ClientMerge2 *this)
{
  return *((_DWORD *)this + 19);
}

//------------------------------------------------------------------------------
// Address: 0x1000C3E0
// Name: public: virtual class FileSys __near * ClientMerge3::GetTheirFile(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct FileSys *__thiscall ClientMerge3::GetTheirFile(ClientMerge3 *this)
{
  return *((struct FileSys **)this + 21);
}

//------------------------------------------------------------------------------
// Address: 0x1000C3F0
// Name: public: virtual class FileSys __near * ClientMerge3::GetResultFile(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct FileSys *__thiscall ClientMerge3::GetResultFile(ClientMerge3 *this)
{
  return *((struct FileSys **)this + 22);
}

//------------------------------------------------------------------------------
// Address: 0x1000C400
// Name: public: virtual int ClientMerge3::GetYourChunks(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall ClientMerge3::GetYourChunks(ClientMerge3 *this)
{
  return *((_DWORD *)this + 35);
}

//------------------------------------------------------------------------------
// Address: 0x1000C410
// Name: public: virtual int ClientMerge3::GetTheirChunks(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall ClientMerge3::GetTheirChunks(ClientMerge3 *this)
{
  return *((_DWORD *)this + 36);
}

//------------------------------------------------------------------------------
// Address: 0x1000C420
// Name: public: virtual int ClientMerge3::GetBothChunks(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall ClientMerge3::GetBothChunks(ClientMerge3 *this)
{
  return *((_DWORD *)this + 38);
}

//------------------------------------------------------------------------------
// Address: 0x1000C430
// Name: public: virtual int ClientMerge3::GetConflictChunks(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall ClientMerge3::GetConflictChunks(ClientMerge3 *this)
{
  return *((_DWORD *)this + 37);
}

//------------------------------------------------------------------------------
// Address: 0x1000C440
// Name: public: virtual void ClientMerge3::SetShowAll(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall ClientMerge3::SetShowAll(ClientMerge3 *this)
{
  *((_DWORD *)this + 41) = 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000C450
// Name: public: virtual void ClientMerge3::SetDiffFlags(class StrPtr const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall ClientMerge3::SetDiffFlags(ClientMerge3 *this, const struct StrPtr *a2)
{
  StrBuf *v2; // ecx

  v2 = (StrBuf *)((char *)this + 172);
  v2->length = 0;
  StrBuf::Append(this: v2, a2);
}

//------------------------------------------------------------------------------
// Address: 0x1000C470
// Name: public: static class ClientMerge __near * ClientMerge::Create(class ClientUser __near *,enum FileSysType,enum FileSysType,enum MergeType)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
static struct ClientMerge *__cdecl ClientMerge::Create(
        struct ClientUser *a1,
        enum FileSysType a2,
        enum FileSysType a3,
        enum MergeType a4)
{
  ClientMerge3 *v4; // eax
  ClientMerge3 *v6; // esi
  ClientMerge2 *v7; // eax

  if ( a4 == CMT_BINARY )
  {
    v7 = (ClientMerge2 *)operator new(nSize: 0x54u);
    if ( v7 != nullptr )
      return (struct ClientMerge *)ClientMerge2::ClientMerge2(this: v7, a2: a1, a3: a2, a4: a3);
    return nullptr;
  }
  if ( a4 != CMT_2WAY )
  {
    v4 = (ClientMerge3 *)operator new(nSize: 0xC0u);
    if ( v4 != nullptr )
      return (struct ClientMerge *)ClientMerge3::ClientMerge3(this: v4, a2: a1, a3: a2, a4: a3);
    return nullptr;
  }
  v6 = (ClientMerge3 *)operator new(nSize: 0xC0u);
  if ( v6 == nullptr )
    return nullptr;
  ClientMerge3::ClientMerge3(this: v6, a2: a1, a3: a2, a4: a3);
  *(_DWORD *)v6 = &ClientMerge32::`vftable';
  return (struct ClientMerge *)v6;
}

//------------------------------------------------------------------------------
// Address: 0x1000C510
// Name: public: virtual ClientMerge::~ClientMerge(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall ClientMerge::~ClientMerge(ClientMerge *this)
{
  this->__vftable = (ClientMerge_vtbl *)&ClientMerge::`vftable';
  LastChance::~LastChance(this);
}

//------------------------------------------------------------------------------
// Address: 0x1000C520
// Name: public: virtual void ClientMerge::SetNames(class StrPtr __near *,class StrPtr __near *,class StrPtr __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall ClientMerge::SetNames(ClientMerge *this, struct StrPtr *a2, struct StrPtr *a3, struct StrPtr *a4)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1000C580
// Name: protected: int ClientMerge::Verify(class Error const __near *,class Error __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall ClientMerge::Verify(ClientMerge *this, Error *a2, struct Error *a3)
{
  int result; // eax
  StrBuf pMem; // [esp+20h] [ebp-Ch] BYREF

  pMem.size = 0;
  pMem.length = 0;
  pMem.buffer = StrBuf::nullStrBuf;
  Error::Fmt(this: a2, a2: &pMem, a3: 0);
  this->ui->Prompt(this: this->ui, a2: &pMem, a3: &pMem, a4: 0, a5: a3);
  if ( a3->severity > E_INFO )
  {
LABEL_4:
    if ( pMem.buffer == StrBuf::nullStrBuf )
    {
      return 0;
    }
    else
    {
      free(pMem: pMem.buffer);
      return 0;
    }
  }
  else
  {
    while ( 2 )
    {
      switch ( *pMem.buffer )
      {
        case 'N':
        case 'n':
          if ( pMem.buffer != StrBuf::nullStrBuf )
            free(pMem: pMem.buffer);
          return 0;
        case 'Y':
        case 'y':
          if ( pMem.buffer != StrBuf::nullStrBuf )
            free(pMem: pMem.buffer);
          result = 1;
          break;
        default:
          this->ui->Prompt(this: this->ui, a2: &pMem, a3: &pMem, a4: 0, a5: a3);
          if ( a3->severity > E_INFO )
            goto LABEL_4;
          continue;
      }
      break;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000C6E0
// Name: public: virtual ClientMerge3::~ClientMerge3(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall ClientMerge3::~ClientMerge3(ClientMerge *this)
{
  void (__thiscall ***v2)(_DWORD, int); // ecx
  void (__thiscall ***v3)(_DWORD, int); // ecx
  void (__thiscall ***v4)(_DWORD, int); // ecx
  void (__thiscall ***v5)(_DWORD, int); // ecx
  void (__thiscall ***v6)(_DWORD, int); // ecx
  void (__thiscall ***v7)(_DWORD, int); // ecx
  char *v8; // edi
  int i; // ebx
  char *v10; // eax

  v2 = *((void (__thiscall ****)(_DWORD, int))this + 19);
  this->__vftable = (ClientMerge_vtbl *)&ClientMerge3::`vftable';
  if ( v2 != nullptr )
    (**v2)(a1: v2, a2: 1);
  v3 = *((void (__thiscall ****)(_DWORD, int))this + 20);
  if ( v3 != nullptr )
    (**v3)(a1: v3, a2: 1);
  v4 = *((void (__thiscall ****)(_DWORD, int))this + 21);
  if ( v4 != nullptr )
    (**v4)(a1: v4, a2: 1);
  v5 = *((void (__thiscall ****)(_DWORD, int))this + 22);
  if ( v5 != nullptr )
    (**v5)(a1: v5, a2: 1);
  free(pMem: *((void **)this + 23));
  free(pMem: *((void **)this + 24));
  free(pMem: *((void **)this + 25));
  v6 = *((void (__thiscall ****)(_DWORD, int))this + 46);
  if ( v6 != nullptr )
    (**v6)(a1: v6, a2: 1);
  v7 = *((void (__thiscall ****)(_DWORD, int))this + 47);
  if ( v7 != nullptr )
    (**v7)(a1: v7, a2: 1);
  if ( *((char **)this + 43) != StrBuf::nullStrBuf )
    free(pMem: *((void **)this + 43));
  if ( *((char **)this + 32) != StrBuf::nullStrBuf )
    free(pMem: *((void **)this + 32));
  if ( *((char **)this + 29) != StrBuf::nullStrBuf )
    free(pMem: *((void **)this + 29));
  if ( *((char **)this + 26) != StrBuf::nullStrBuf )
    free(pMem: *((void **)this + 26));
  v8 = (char *)this + 76;
  for ( i = 4; i >= 0; --i )
  {
    v10 = *((char **)v8 - 3);
    v8 -= 12;
    if ( v10 != StrBuf::nullStrBuf )
      free(pMem: v10);
  }
  ClientMerge::~ClientMerge(this);
}

//------------------------------------------------------------------------------
// Address: 0x1000C7F0
// Name: public: virtual void ClientMerge3::SetNames(class StrPtr __near *,class StrPtr __near *,class StrPtr __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall ClientMerge3::SetNames(ClientMerge3 *this, struct StrPtr *a2, struct StrPtr *a3, struct StrPtr *a4)
{
  const struct StrPtr *v5; // ebp
  const struct StrPtr *v6; // ebx
  struct StrPtr v7; // [esp+10h] [ebp-8h] BYREF

  v7 = StrRef::null;
  if ( a2 == nullptr )
    a2 = &v7;
  v5 = a3;
  if ( a3 == nullptr )
    v5 = &v7;
  v6 = a4;
  if ( a4 == nullptr )
    v6 = &v7;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 8) = 0;
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 14) = 0;
  *((_DWORD *)this + 17) = 0;
  StrBuf::Append(this: (StrBuf *)((char *)this + 16), src: ">>>> ORIGINAL ");
  StrBuf::Append(this: (StrBuf *)((char *)this + 16), a2);
  StrBuf::Append(this: (StrBuf *)((char *)this + 28), src: "==== THEIRS ");
  StrBuf::Append(this: (StrBuf *)((char *)this + 28), a2: v5);
  StrBuf::Append(this: (StrBuf *)((char *)this + 40), src: "==== YOURS ");
  StrBuf::Append(this: (StrBuf *)((char *)this + 40), a2: v6);
  StrBuf::Append(this: (StrBuf *)((char *)this + 52), src: "==== BOTH ");
  StrBuf::Append(this: (StrBuf *)((char *)this + 52), a2: v5);
  StrBuf::Append(this: (StrBuf *)((char *)this + 52), src: " ");
  StrBuf::Append(this: (StrBuf *)((char *)this + 52), a2: v6);
  StrBuf::Append(this: (StrBuf *)((char *)this + 64), src: "<<<<");
}

//------------------------------------------------------------------------------
// Address: 0x1000C8D0
// Name: public: virtual void ClientMerge3::Open(class StrPtr __near *,class Error __near *,class CharSetCvt __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall ClientMerge3::Open(
        ClientMerge3 *this,
        struct StrPtr *a2,
        struct Error *a3,
        struct CharSetCvt *a4,
        int a5)
{
  int v6; // eax
  int v7; // ecx

  if ( *((_DWORD *)this + 5) == 0 )
    (*(void (__thiscall **)(ClientMerge3 *, _DWORD, _DWORD, _DWORD))(*(_DWORD *)this + 64))(
      a1: this,
      a2: 0,
      a3: 0,
      a4: 0);
  (*(void (__thiscall **)(_DWORD, struct StrPtr *))(**((_DWORD **)this + 19) + 4))(a1: *((_DWORD *)this + 19), a2);
  if ( a5 != 0 )
  {
    *(_DWORD *)(*((_DWORD *)this + 20) + 40) = a5;
    *(_DWORD *)(*((_DWORD *)this + 21) + 40) = a5;
    *(_DWORD *)(*((_DWORD *)this + 19) + 40) = a5;
    *(_DWORD *)(*((_DWORD *)this + 22) + 40) = a5;
  }
  (*(void (__thiscall **)(_DWORD, char *))(**((_DWORD **)this + 20) + 76))(a1: *((_DWORD *)this + 20), a2: a2->buffer);
  (*(void (__thiscall **)(_DWORD, char *))(**((_DWORD **)this + 21) + 76))(a1: *((_DWORD *)this + 21), a2: a2->buffer);
  (*(void (__thiscall **)(_DWORD, char *))(**((_DWORD **)this + 22) + 76))(a1: *((_DWORD *)this + 22), a2: a2->buffer);
  (*(void (__thiscall **)(_DWORD, int, struct Error *))(**((_DWORD **)this + 20) + 20))(
    a1: *((_DWORD *)this + 20),
    a2: 1,
    a3);
  if ( a3->severity <= E_INFO )
  {
    *(_DWORD *)(*((_DWORD *)this + 22) + 8) = 1;
    (*(void (__thiscall **)(_DWORD, int, struct Error *))(**((_DWORD **)this + 21) + 20))(
      a1: *((_DWORD *)this + 21),
      a2: 1,
      a3);
    (*(void (__thiscall **)(_DWORD, int, struct Error *))(**((_DWORD **)this + 22) + 20))(
      a1: *((_DWORD *)this + 22),
      a2: 1,
      a3);
    if ( a4 != nullptr )
    {
      *((_DWORD *)this + 46) = (*(int (__thiscall **)(struct CharSetCvt *))(*(_DWORD *)a4 + 4))(a1: a4);
      v6 = (*(int (__thiscall **)(struct CharSetCvt *))(*(_DWORD *)a4 + 4))(a1: a4);
      v7 = *((_DWORD *)this + 20);
      *((_DWORD *)this + 47) = v6;
      (*(void (__thiscall **)(int, struct CharSetCvt *))(*(_DWORD *)v7 + 16))(a1: v7, a2: a4);
      (*(void (__thiscall **)(_DWORD, _DWORD))(**((_DWORD **)this + 21) + 16))(
        a1: *((_DWORD *)this + 21),
        a2: *((_DWORD *)this + 46));
      (*(void (__thiscall **)(_DWORD, _DWORD))(**((_DWORD **)this + 22) + 16))(
        a1: *((_DWORD *)this + 22),
        a2: *((_DWORD *)this + 47));
    }
    *((_DWORD *)this + 38) = 0;
    *((_DWORD *)this + 37) = 0;
    *((_DWORD *)this + 36) = 0;
    *((_DWORD *)this + 35) = 0;
    *((_DWORD *)this + 39) = 0;
    *((_DWORD *)this + 40) = 0;
    *((_DWORD *)this + 42) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000CA00
// Name: public: virtual void ClientMerge3::Close(class Error __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall ClientMerge3::Close(ClientMerge3 *this, struct Error *a2)
{
  (*(void (__thiscall **)(_DWORD, struct Error *))(**((_DWORD **)this + 20) + 32))(a1: *((_DWORD *)this + 20), a2);
  (*(void (__thiscall **)(_DWORD, struct Error *))(**((_DWORD **)this + 21) + 32))(a1: *((_DWORD *)this + 21), a2);
  (*(void (__thiscall **)(_DWORD, struct Error *))(**((_DWORD **)this + 22) + 32))(a1: *((_DWORD *)this + 22), a2);
  MD5::Final(this: *((MD5 **)this + 24), a2: (struct StrBuf *)((char *)this + 116));
  MD5::Final(this: *((MD5 **)this + 23), a2: (struct StrBuf *)((char *)this + 104));
  MD5::Final(this: *((MD5 **)this + 25), a2: (struct StrBuf *)((char *)this + 128));
}

//------------------------------------------------------------------------------
// Address: 0x1000CA60
// Name: public: virtual void ClientMerge3::Chmod(char const __near *,class Error __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall ClientMerge3::Chmod(ClientMerge3 *this, char *a2, struct Error *a3)
{
  FileSys *v3; // esi
  enum FilePerm v4; // eax

  v3 = *((FileSys **)this + 19);
  v4 = FileSys::Perm(a1: a2);
  FileSys::Chmod2(this: v3, a2: v4, a3);
}

//------------------------------------------------------------------------------
// Address: 0x1000CA90
// Name: public: virtual enum MergeStatus ClientMerge3::AutoResolve(enum MergeForce)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall ClientMerge3::AutoResolve(ClientMerge3 *this, enum MergeForce a2)
{
  struct Error *v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v8; // [esp-10h] [ebp-24h]
  int v9; // [esp-Ch] [ebp-20h]
  int v10; // [esp-8h] [ebp-1Ch]
  int v11; // [esp-4h] [ebp-18h]
  Error v12; // [esp+8h] [ebp-Ch] BYREF

  v11 = *((_DWORD *)this + 37);
  v10 = *((_DWORD *)this + 38);
  v9 = *((_DWORD *)this + 36);
  v8 = *((_DWORD *)this + 35);
  v12.ep = nullptr;
  v12.severity = E_EMPTY;
  v3 = Error::Set(this: &v12, a2: &MsgClient::MergeMsg3);
  v4 = Error::operator<<(a1: v3, a2: v8);
  v5 = Error::operator<<(a1: v4, a2: v9);
  v6 = Error::operator<<(a1: v5, a2: v10);
  Error::operator<<(a1: v6, a2: v11);
  (*(void (__thiscall **)(_DWORD, Error *))(**((_DWORD **)this + 3) + 12))(a1: *((_DWORD *)this + 3), a2: &v12);
  if ( *((_DWORD *)this + 41) != 0 && a2 == CMF_FORCE )
  {
    Error::~Error(this: &v12);
    return 3;
  }
  if ( *((_DWORD *)this + 37) != 0 )
    goto LABEL_5;
  if ( *((_DWORD *)this + 35) != 0 )
  {
    if ( *((_DWORD *)this + 36) != 0 )
    {
      if ( *((_DWORD *)this + 40) != 0 )
      {
LABEL_5:
        Error::~Error(this: &v12);
        return 2 * (a2 == CMF_FORCE) + 1;
      }
      if ( a2 == CMF_AUTO || a2 == CMF_FORCE )
      {
        Error::~Error(this: &v12);
        return 2;
      }
      else
      {
        Error::~Error(this: &v12);
        return 1;
      }
    }
    else
    {
      Error::~Error(this: &v12);
      return 5;
    }
  }
  else
  {
    Error::~Error(this: &v12);
    return 4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000CBD0
// Name: public: virtual enum MergeStatus ClientMerge32::AutoResolve(enum MergeForce)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall ClientMerge32::AutoResolve(ClientMerge32 *this, enum MergeForce a2)
{
  struct Error *v3; // eax
  int v5; // [esp-4h] [ebp-14h]
  Error v6; // [esp+4h] [ebp-Ch] BYREF

  v5 = *((_DWORD *)this + 36);
  v6.ep = nullptr;
  v6.severity = E_EMPTY;
  v3 = Error::Set(this: &v6, a2: &MsgClient::MergeMsg32);
  Error::operator<<(a1: v3, a2: v5);
  (*(void (__thiscall **)(_DWORD, Error *))(**((_DWORD **)this + 3) + 12))(a1: *((_DWORD *)this + 3), a2: &v6);
  if ( *((_DWORD *)this + 41) != 0 && a2 == CMF_FORCE )
  {
    Error::~Error(this: &v6);
    return 3;
  }
  else if ( *((_DWORD *)this + 36) == 0 || a2 == CMF_FORCE )
  {
    Error::~Error(this: &v6);
    return 4;
  }
  else
  {
    Error::~Error(this: &v6);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000CC80
// Name: public: virtual class StrPtr const __near * ClientMerge3::GetMergeDigest(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const struct StrPtr *__thiscall ClientMerge3::GetMergeDigest(ClientMerge3 *this)
{
  if ( *((_DWORD *)this + 40) != 0 || *((_DWORD *)this + 37) != 0 )
    return nullptr;
  else
    return (const struct StrPtr *)((char *)this + 128);
}

//------------------------------------------------------------------------------
// Address: 0x1000CCA0
// Name: public: virtual class StrPtr const __near * ClientMerge3::GetYourDigest(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const struct StrPtr *__thiscall ClientMerge3::GetYourDigest(ClientMerge3 *this)
{
  return (const struct StrPtr *)((char *)this + 104);
}

//------------------------------------------------------------------------------
// Address: 0x1000CCB0
// Name: public: virtual class StrPtr const __near * ClientMerge3::GetTheirDigest(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const struct StrPtr *__thiscall ClientMerge3::GetTheirDigest(ClientMerge3 *this)
{
  return (const struct StrPtr *)((char *)this + 116);
}

//------------------------------------------------------------------------------
// Address: 0x1000CCC0
// Name: public: ClientMerge3::ClientMerge3(class ClientUser __near *,enum FileSysType,enum FileSysType)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientMerge3 *__thiscall ClientMerge3::ClientMerge3(
        ClientMerge3 *this,
        struct ClientUser *a2,
        enum FileSysType a3,
        enum FileSysType a4)
{
  FileSys *v5; // eax
  int v6; // ecx
  MD5 *v7; // eax
  MD5 *v8; // eax
  MD5 *v9; // eax
  MD5 *v10; // eax
  MD5 *v11; // eax
  MD5 *v12; // eax

  *(_DWORD *)this = &ClientMerge3::`vftable';
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 4) = StrBuf::nullStrBuf;
  *((_DWORD *)this + 9) = 0;
  *((_DWORD *)this + 8) = 0;
  *((_DWORD *)this + 7) = StrBuf::nullStrBuf;
  *((_DWORD *)this + 12) = 0;
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 10) = StrBuf::nullStrBuf;
  *((_DWORD *)this + 15) = 0;
  *((_DWORD *)this + 14) = 0;
  *((_DWORD *)this + 13) = StrBuf::nullStrBuf;
  *((_DWORD *)this + 18) = 0;
  *((_DWORD *)this + 17) = 0;
  *((_DWORD *)this + 16) = StrBuf::nullStrBuf;
  *((_DWORD *)this + 28) = 0;
  *((_DWORD *)this + 27) = 0;
  *((_DWORD *)this + 26) = StrBuf::nullStrBuf;
  *((_DWORD *)this + 31) = 0;
  *((_DWORD *)this + 30) = 0;
  *((_DWORD *)this + 29) = StrBuf::nullStrBuf;
  *((_DWORD *)this + 34) = 0;
  *((_DWORD *)this + 33) = 0;
  *((_DWORD *)this + 32) = StrBuf::nullStrBuf;
  *((_DWORD *)this + 45) = 0;
  *((_DWORD *)this + 44) = 0;
  *((_DWORD *)this + 43) = StrBuf::nullStrBuf;
  *((_DWORD *)this + 3) = a2;
  *((_DWORD *)this + 19) = a2->File(this: a2, a2: a3);
  *((_DWORD *)this + 20) = a2->File(this: a2, a2: a3);
  *((_DWORD *)this + 21) = a2->File(this: a2, a2: a4);
  v5 = a2->File(this: a2, a2: a4);
  v6 = *((_DWORD *)this + 20);
  *((_DWORD *)this + 22) = v5;
  *(_DWORD *)(v6 + 32) = 1;
  *(_DWORD *)(*((_DWORD *)this + 21) + 32) = 1;
  *(_DWORD *)(*((_DWORD *)this + 22) + 32) = 1;
  v7 = (MD5 *)operator new(nSize: 0xA0u);
  if ( v7 != nullptr )
    v8 = MD5::MD5(this: v7);
  else
    v8 = nullptr;
  *((_DWORD *)this + 23) = v8;
  v9 = (MD5 *)operator new(nSize: 0xA0u);
  if ( v9 != nullptr )
    v10 = MD5::MD5(this: v9);
  else
    v10 = nullptr;
  *((_DWORD *)this + 24) = v10;
  v11 = (MD5 *)operator new(nSize: 0xA0u);
  if ( v11 != nullptr )
    v12 = MD5::MD5(this: v11);
  else
    v12 = nullptr;
  *((_DWORD *)this + 41) = 0;
  *((_DWORD *)this + 46) = 0;
  *((_DWORD *)this + 47) = 0;
  *((_DWORD *)this + 25) = v12;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000CE10
// Name: public: virtual void ClientMerge3::Write(class StrPtr __near *,class StrPtr __near *,class Error __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall ClientMerge3::Write(ClientMerge3 *this, struct StrPtr *a2, struct StrPtr *a3, struct Error *a4)
{
  int v4; // edi
  int v6; // edx
  int v7; // eax
  int length; // eax
  int v9; // ebx
  struct StrPtr *v10; // [esp+3Ch] [ebp+8h]

  v4 = 0;
  if ( a3 != nullptr )
  {
    v6 = atoi(nptr: a3->buffer);
    v10 = (struct StrPtr *)v6;
  }
  else
  {
    v10 = nullptr;
    v6 = 0;
  }
  v7 = *((_DWORD *)this + 39);
  if ( v7 != 0 && v7 != v6 )
  {
    switch ( v6 )
    {
      case 10:
        ++*((_DWORD *)this + 36);
        goto LABEL_9;
      case 12:
        ++*((_DWORD *)this + 35);
        goto LABEL_11;
      case 14:
        ++*((_DWORD *)this + 38);
        v4 = 3;
        break;
      case 15:
        v4 = 4;
        break;
      case 17:
        ++*((_DWORD *)this + 37);
        break;
      case 26:
LABEL_9:
        v4 = 1;
        break;
      case 28:
LABEL_11:
        v4 = 2;
        break;
      default:
        break;
    }
    if ( *((_DWORD *)this + 41) != 0 || (v6 & 0x10) != 0 || v6 == 15 && (v7 & 0x10) != 0 )
    {
      if ( *((_DWORD *)this + 42) != 0 )
        (*(void (__thiscall **)(_DWORD, const char *, int, struct Error *))(**((_DWORD **)this + 22) + 24))(
          a1: *((_DWORD *)this + 22),
          a2: "\n",
          a3: 1,
          a4);
      (*(void (__thiscall **)(_DWORD, _DWORD, _DWORD, struct Error *))(**((_DWORD **)this + 22) + 24))(
        a1: *((_DWORD *)this + 22),
        a2: *((_DWORD *)this + 3 * v4 + 4),
        a3: *((_DWORD *)this + 3 * v4 + 5),
        a4);
      (*(void (__thiscall **)(_DWORD, const char *, int, struct Error *))(**((_DWORD **)this + 22) + 24))(
        a1: *((_DWORD *)this + 22),
        a2: "\n",
        a3: 1,
        a4);
      ++*((_DWORD *)this + 40);
      v6 = (int)v10;
    }
  }
  *((_DWORD *)this + 39) = v6;
  length = a2->length;
  if ( length != 0 )
  {
    if ( (v6 & 1) != 0 )
    {
      (*(void (__thiscall **)(_DWORD, char *, int, struct Error *))(**((_DWORD **)this + 20) + 24))(
        a1: *((_DWORD *)this + 20),
        a2: a2->buffer,
        a3: length,
        a4);
      LOBYTE(v6) = (_BYTE)v10;
    }
    if ( (v6 & 2) != 0 )
    {
      (*(void (__thiscall **)(_DWORD, char *, int, struct Error *))(**((_DWORD **)this + 21) + 24))(
        a1: *((_DWORD *)this + 21),
        a2: a2->buffer,
        a3: a2->length,
        a4);
      MD5::Update(this: *((MD5 **)this + 24), a2);
      LOBYTE(v6) = (_BYTE)v10;
    }
    if ( (v6 & 4) != 0 )
    {
      MD5::Update(this: *((MD5 **)this + 23), a2);
      LOBYTE(v6) = (_BYTE)v10;
    }
    v9 = v6 & 8;
    if ( (v6 & 8) != 0 )
      MD5::Update(this: *((MD5 **)this + 25), a2);
    if ( v9 != 0 || *((_DWORD *)this + 41) != 0 || v10 == (struct StrPtr *)17 )
      (*(void (__thiscall **)(_DWORD, char *, int, struct Error *))(**((_DWORD **)this + 22) + 24))(
        a1: *((_DWORD *)this + 22),
        a2: a2->buffer,
        a3: a2->length,
        a4);
    *((_DWORD *)this + 42) = a2->buffer[a2->length - 1] != 10;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000CFF0
// Name: protected: int ClientMerge3::CheckForMarkers(class FileSys __near *,class Error __near *)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall ClientMerge3::CheckForMarkers(ClientMerge3 *this, FileSys *a2, struct Error *a3)
{
  FileSys *v3; // esi
  void (__thiscall *Open)(FileSys *, FileOpenMode, Error *); // edx
  struct Error *v5; // edi
  int v6; // ebp
  int v8; // eax
  const char **v9; // esi
  int i; // edi
  int v11; // [esp+Ch] [ebp-14h]
  StrBuf pMem; // [esp+14h] [ebp-Ch] BYREF

  v3 = a2;
  Open = a2->Open;
  v5 = a3;
  v6 = 0;
  pMem.size = 0;
  pMem.length = 0;
  pMem.buffer = StrBuf::nullStrBuf;
  v11 = 0;
  Open(this: a2, a2: FOM_READ, a3);
  if ( a3->severity <= E_INFO )
  {
    do
    {
      if ( FileSys::ReadLine(this: v3, a2: &pMem, a3: v5) == 0 )
        break;
      if ( pMem.length != 0 )
      {
        strchr(string: "<>==", chr: *pMem.buffer);
        if ( v8 != 0 )
        {
          v9 = (const char **)((char *)this + 16);
          for ( i = 5; i != 0; --i )
          {
            if ( strcmp(pMem.buffer, *v9) == 0 )
              ++v11;
            v9 += 3;
          }
          v5 = a3;
          v3 = a2;
          v6 = v11;
        }
      }
    }
    while ( v6 == 0 );
    v3->Close(this: v3, a2: v5);
    if ( pMem.buffer != StrBuf::nullStrBuf )
      free(pMem: pMem.buffer);
    return v6 > 0;
  }
  else
  {
    if ( pMem.buffer != StrBuf::nullStrBuf )
      free(pMem: pMem.buffer);
    return false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D120
// Name: public: virtual int ClientMerge3::IsAcceptable(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall ClientMerge3::IsAcceptable(ClientMerge3 *this)
{
  int v1; // esi
  bool v2; // zf
  Error v4; // [esp+4h] [ebp-Ch] BYREF

  v1 = 0;
  v2 = *((_DWORD *)this + 40) == 0;
  v4.ep = nullptr;
  v4.severity = E_EMPTY;
  if ( v2 || !ClientMerge3::CheckForMarkers(this, a2: *((FileSys **)this + 22), a3: &v4) )
    v1 = 1;
  Error::~Error(this: &v4);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x1000D160
// Name: public: virtual enum MergeStatus ClientMerge3::DetectResolve(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall ClientMerge3::DetectResolve(ClientMerge3 *this)
{
  void (__thiscall ***v2)(_DWORD, int); // esi
  bool v3; // zf
  void *pMem[3]; // [esp+10h] [ebp-18h] BYREF
  Error v6; // [esp+1Ch] [ebp-Ch] BYREF

  v2 = nullptr;
  v3 = *((_DWORD *)this + 47) == 0;
  pMem[2] = nullptr;
  pMem[1] = nullptr;
  pMem[0] = StrBuf::nullStrBuf;
  v6.ep = nullptr;
  v6.severity = E_EMPTY;
  if ( !v3 )
  {
    v2 = (void (__thiscall ***)(_DWORD, int))(*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 47) + 8))(a1: *((_DWORD *)this + 47));
    (*(void (__thiscall **)(_DWORD, _DWORD))(**((_DWORD **)this + 22) + 16))(a1: *((_DWORD *)this + 22), a2: v2);
  }
  (*(void (__thiscall **)(_DWORD, void **, Error *))(**((_DWORD **)this + 22) + 92))(
    a1: *((_DWORD *)this + 22),
    a2: pMem,
    a3: &v6);
  if ( v2 != nullptr )
    (**v2)(a1: v2, a2: 1);
  if ( strcmp((const char *)pMem[0], *((const char **)this + 29)) == 0 )
  {
    Error::~Error(this: &v6);
    if ( pMem[0] != StrBuf::nullStrBuf )
      free(pMem: pMem[0]);
    return 4;
  }
  else if ( strcmp((const char *)pMem[0], *((const char **)this + 26)) == 0 )
  {
    `vector destructor iterator'(a1: &v6, a2: 0xCu, a3: 1, a4: (void (__thiscall *)(void *))Error::~Error);
    if ( pMem[0] != StrBuf::nullStrBuf )
      free(pMem: pMem[0]);
    return 5;
  }
  else if ( strcmp((const char *)pMem[0], *((const char **)this + 32)) == 0 )
  {
    `vector destructor iterator'(a1: &v6, a2: 0xCu, a3: 1, a4: (void (__thiscall *)(void *))Error::~Error);
    if ( pMem[0] != StrBuf::nullStrBuf )
      free(pMem: pMem[0]);
    return 2;
  }
  else
  {
    `vector destructor iterator'(a1: &v6, a2: 0xCu, a3: 1, a4: (void (__thiscall *)(void *))Error::~Error);
    if ( pMem[0] != StrBuf::nullStrBuf )
      free(pMem: pMem[0]);
    return 3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D320
// Name: public: virtual enum MergeStatus ClientMerge3::Resolve(class Error __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall ClientMerge3::Resolve(ClientMerge *this, Error *a2)
{
  int v3; // ebx
  const char *v4; // ebp
  char *buffer; // ecx
  int v6; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  MergeStatus v12; // eax
  BOOL v13; // eax
  MergeStatus v14; // [esp+18h] [ebp-10h]
  StrBuf pMem; // [esp+1Ch] [ebp-Ch] BYREF

  v14 = this->AutoResolve(this, a2: CMF_FORCE);
  pMem.size = 0;
  pMem.buffer = StrBuf::nullStrBuf;
  while ( 1 )
  {
    v3 = 0;
    switch ( v14 )
    {
      case CMS_MERGED:
        v4 = "am";
        break;
      case CMS_EDIT:
        if ( *((_DWORD *)this + 40) != 0 )
          v4 = "e";
        else
          v4 = "ae";
        break;
      case CMS_THEIRS:
        v4 = "at";
        break;
      case CMS_YOURS:
        v4 = "ay";
        break;
      default:
        v4 = "s";
        break;
    }
    pMem.length = 0;
    a2->severity = E_EMPTY;
    Error::Set(this: a2, a2: &MsgClient::MergePrompt);
    Error::operator<<(a1: v4);
    Error::Fmt(this: a2, a2: &pMem, a3: 0);
    a2->severity = E_EMPTY;
    this->ui->Prompt(this: this->ui, a2: &pMem, a3: &pMem, a4: 0, a5: a2);
    if ( a2->severity > E_INFO )
      break;
    buffer = pMem.buffer;
    if ( *pMem.buffer == 0 && &pMem != (StrBuf *)v4 && pMem.buffer != v4 )
    {
      pMem.length = 0;
      StrBuf::Append(this: &pMem, src: v4);
      buffer = pMem.buffer;
    }
    v6 = (*buffer << 8) | buffer[1];
    if ( v6 > 25716 )
    {
      if ( v6 <= 25977 )
      {
        if ( v6 == 25977 )
        {
          this->ui->Edit(this: this->ui, a2: *((FileSys **)this + 19), a3: a2);
          goto LABEL_64;
        }
        v10 = v6 - 25721;
        if ( v10 == 0 )
        {
          this->ui->Diff(
            this: this->ui,
            a2: *((FileSys **)this + 20),
            a3: *((FileSys **)this + 19),
            a4: 1,
            a5: *((char **)this + 43),
            a6: a2);
          goto LABEL_64;
        }
        v11 = v10 - 135;
        if ( v11 == 0 )
        {
          this->ui->Edit(this: this->ui, a2: *((FileSys **)this + 22), a3: a2);
          v3 = 1;
          goto LABEL_64;
        }
        if ( v11 == 116 )
        {
          this->ui->Edit(this: this->ui, a2: *((FileSys **)this + 21), a3: a2);
          goto LABEL_64;
        }
        goto LABEL_61;
      }
      if ( v6 == 26624 )
      {
LABEL_63:
        this->ui->Help_2(this: this->ui, a2: (const char *const *)&off_10041C48);
        goto LABEL_64;
      }
      if ( v6 != 27904 )
      {
        if ( v6 == 29440 )
        {
          if ( buffer != StrBuf::nullStrBuf )
            free(pMem: buffer);
          return 1;
        }
LABEL_61:
        Error::Set(this: a2, a2: &MsgClient::BadFlag);
        goto LABEL_64;
      }
      this->ui->Merge(
        this: this->ui,
        a2: *((FileSys **)this + 20),
        a3: *((FileSys **)this + 21),
        a4: *((FileSys **)this + 19),
        a5: *((FileSys **)this + 22),
        a6: a2);
      v3 = 1;
    }
    else
    {
      if ( v6 == 25716 )
      {
        this->ui->Diff(
          this: this->ui,
          a2: *((FileSys **)this + 20),
          a3: *((FileSys **)this + 21),
          a4: 1,
          a5: *((char **)this + 43),
          a6: a2);
        goto LABEL_64;
      }
      if ( v6 > 24948 )
      {
        v8 = v6 - 24953;
        if ( v8 == 0 )
        {
          if ( buffer != StrBuf::nullStrBuf )
            free(pMem: buffer);
          return 5;
        }
        v9 = v8 - 647;
        if ( v9 == 0 )
        {
          this->ui->Diff(
            this: this->ui,
            a2: *((FileSys **)this + 19),
            a3: *((FileSys **)this + 22),
            a4: 1,
            a5: *((char **)this + 43),
            a6: a2);
          goto LABEL_64;
        }
        if ( v9 == 109 )
        {
          this->ui->Diff(
            this: this->ui,
            a2: *((FileSys **)this + 20),
            a3: *((FileSys **)this + 22),
            a4: 1,
            a5: *((char **)this + 43),
            a6: a2);
          goto LABEL_64;
        }
        goto LABEL_61;
      }
      if ( v6 == 24948 )
      {
        if ( *((_DWORD *)this + 35) + *((_DWORD *)this + 37) == 0 )
          goto LABEL_40;
        Error::Set(this: a2, a2: &MsgClient::Confirm);
        if ( ClientMerge::Verify(this, a2, a3: a2) != 0 )
        {
          buffer = pMem.buffer;
LABEL_40:
          if ( buffer != StrBuf::nullStrBuf )
            free(pMem: buffer);
          return 4;
        }
      }
      else if ( v6 > 24933 )
      {
        if ( v6 != 24941 )
          goto LABEL_61;
        if ( v14 != CMS_EDIT )
          goto LABEL_34;
        Error::Set(this: a2, a2: &MsgClient::ConfirmEdit);
        if ( ClientMerge::Verify(this, a2, a3: a2) != 0 )
        {
          buffer = pMem.buffer;
LABEL_34:
          if ( buffer != StrBuf::nullStrBuf )
            free(pMem: buffer);
          return 2;
        }
      }
      else
      {
        if ( v6 != 24933 )
        {
          if ( v6 == 16128 )
            goto LABEL_63;
          if ( v6 != 24832 )
            goto LABEL_61;
          if ( v14 != CMS_EDIT )
          {
            if ( buffer != StrBuf::nullStrBuf )
              free(pMem: buffer);
            return v14;
          }
        }
        if ( *((_DWORD *)this + 40) == 0 )
          goto LABEL_27;
        Error::Set(this: a2, a2: &MsgClient::ConfirmMarkers);
        if ( ClientMerge::Verify(this, a2, a3: a2) != 0 )
        {
          buffer = pMem.buffer;
LABEL_27:
          if ( buffer != StrBuf::nullStrBuf )
            free(pMem: buffer);
          return 3;
        }
      }
    }
LABEL_64:
    if ( a2->severity <= E_INFO )
    {
      if ( v3 != 0 )
      {
        v12 = this->DetectResolve(this);
        v14 = v12;
        v13 = *((_DWORD *)this + 40) != 0
           && v12 == CMS_EDIT
           && ClientMerge3::CheckForMarkers((ClientMerge3 *)this, a2: *((FileSys **)this + 22), a3: a2);
        *((_DWORD *)this + 40) = v13;
      }
      if ( a2->severity <= E_INFO )
        continue;
    }
    this->ui->Message(this: this->ui, a2);
    a2->severity = E_EMPTY;
  }
  if ( pMem.buffer != StrBuf::nullStrBuf )
    free(pMem: pMem.buffer);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000D790
// Name: public: virtual void ClientMerge3::Select(enum MergeStatus,class Error __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall ClientMerge3::Select(ClientMerge3 *this, enum MergeStatus a2, struct Error *a3)
{
  const char **v4; // eax
  void (__thiscall ***v5)(_DWORD, int); // ecx
  int v6; // ecx
  const char **v7; // eax
  void (__thiscall ***v8)(_DWORD, int); // ecx
  int v9; // ecx

  if ( a2 >= CMS_MERGED )
  {
    if ( a2 <= CMS_EDIT )
    {
      (*(void (__thiscall **)(_DWORD, _DWORD, struct Error *))(**((_DWORD **)this + 22) + 52))(
        a1: *((_DWORD *)this + 22),
        a2: *((_DWORD *)this + 19),
        a3);
      if ( a3->severity <= E_INFO )
      {
        v7 = (const char **)(*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 19) + 8))(a1: *((_DWORD *)this + 19));
        FileSys::Set(this: *((FileSys **)this + 22), a2: *v7);
        v8 = *((void (__thiscall ****)(_DWORD, int))this + 19);
        if ( v8 != nullptr )
          (**v8)(a1: v8, a2: 1);
        v9 = *((_DWORD *)this + 22);
        *((_DWORD *)this + 22) = 0;
        *((_DWORD *)this + 19) = v9;
      }
    }
    else if ( a2 == CMS_THEIRS )
    {
      (*(void (__thiscall **)(_DWORD, int, struct Error *))(**((_DWORD **)this + 21) + 56))(
        a1: *((_DWORD *)this + 21),
        a2: 1,
        a3);
      (*(void (__thiscall **)(_DWORD, _DWORD, struct Error *))(**((_DWORD **)this + 21) + 52))(
        a1: *((_DWORD *)this + 21),
        a2: *((_DWORD *)this + 19),
        a3);
      if ( a3->severity <= E_INFO )
      {
        v4 = (const char **)(*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 19) + 8))(a1: *((_DWORD *)this + 19));
        FileSys::Set(this: *((FileSys **)this + 21), a2: *v4);
        v5 = *((void (__thiscall ****)(_DWORD, int))this + 19);
        if ( v5 != nullptr )
          (**v5)(a1: v5, a2: 1);
        v6 = *((_DWORD *)this + 21);
        *((_DWORD *)this + 21) = 0;
        *((_DWORD *)this + 19) = v6;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D860
// Name: public: int StrPtr::operator!=(class StrPtr const __near &)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall StrPtr::operator!=(const char **this, const char **a2)
{
  return strcmp(*this, *a2) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000D8B0
// Name: public: virtual ClientMerge2::~ClientMerge2(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall ClientMerge2::~ClientMerge2(ClientMerge *this)
{
  void (__thiscall ***v2)(_DWORD, int); // ecx
  void (__thiscall ***v3)(_DWORD, int); // ecx

  v2 = *((void (__thiscall ****)(_DWORD, int))this + 4);
  this->__vftable = (ClientMerge_vtbl *)&ClientMerge2::`vftable';
  if ( v2 != nullptr )
    (**v2)(a1: v2, a2: 1);
  v3 = *((void (__thiscall ****)(_DWORD, int))this + 5);
  if ( v3 != nullptr )
    (**v3)(a1: v3, a2: 1);
  free(pMem: *((void **)this + 6));
  if ( *((char **)this + 13) != StrBuf::nullStrBuf )
    free(pMem: *((void **)this + 13));
  if ( *((char **)this + 10) != StrBuf::nullStrBuf )
    free(pMem: *((void **)this + 10));
  if ( *((char **)this + 7) != StrBuf::nullStrBuf )
    free(pMem: *((void **)this + 7));
  ClientMerge::~ClientMerge(this);
}

//------------------------------------------------------------------------------
// Address: 0x1000D930
// Name: public: virtual class FileSys __near * ClientMerge2::GetYourFile(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct FileSys *__thiscall ClientMerge2::GetYourFile(ClientMerge2 *this)
{
  return *((struct FileSys **)this + 4);
}

//------------------------------------------------------------------------------
// Address: 0x1000D940
// Name: public: virtual class FileSys __near * ClientMerge2::GetTheirFile(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct FileSys *__thiscall ClientMerge2::GetTheirFile(ClientMerge2 *this)
{
  return *((struct FileSys **)this + 5);
}

//------------------------------------------------------------------------------
// Address: 0x1000D950
// Name: public: virtual int ClientMerge2::GetYourChunks(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall ClientMerge2::GetYourChunks(ClientMerge2 *this)
{
  return *((_DWORD *)this + 16);
}

//------------------------------------------------------------------------------
// Address: 0x1000D960
// Name: public: virtual int ClientMerge2::GetTheirChunks(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall ClientMerge2::GetTheirChunks(ClientMerge2 *this)
{
  return *((_DWORD *)this + 17);
}

//------------------------------------------------------------------------------
// Address: 0x1000D970
// Name: public: virtual int ClientMerge2::GetConflictChunks(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall ClientMerge2::GetConflictChunks(ClientMerge2 *this)
{
  return *((_DWORD *)this + 18);
}

//------------------------------------------------------------------------------
// Address: 0x1000D980
// Name: public: virtual void ClientMerge2::Open(class StrPtr __near *,class Error __near *,class CharSetCvt __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall ClientMerge2::Open(
        ClientMerge2 *this,
        struct StrPtr *a2,
        struct Error *a3,
        struct CharSetCvt *a4,
        int a5)
{
  (*(void (__thiscall **)(_DWORD, struct StrPtr *))(**((_DWORD **)this + 4) + 4))(a1: *((_DWORD *)this + 4), a2);
  if ( *((_DWORD *)this + 20) != 0 )
    (*(void (__thiscall **)(_DWORD, char *, struct Error *))(**((_DWORD **)this + 4) + 92))(
      a1: *((_DWORD *)this + 4),
      a2: (char *)this + 40,
      a3);
  (*(void (__thiscall **)(_DWORD, char *))(**((_DWORD **)this + 5) + 76))(a1: *((_DWORD *)this + 5), a2: a2->buffer);
  *(_DWORD *)(*((_DWORD *)this + 5) + 8) = 1;
  (*(void (__thiscall **)(_DWORD, int, struct Error *))(**((_DWORD **)this + 5) + 20))(
    a1: *((_DWORD *)this + 5),
    a2: 1,
    a3);
  (*(void (__thiscall **)(_DWORD, struct CharSetCvt *))(**((_DWORD **)this + 5) + 16))(
    a1: *((_DWORD *)this + 5),
    a2: a4);
  if ( a5 != 0 )
  {
    *(_DWORD *)(*((_DWORD *)this + 4) + 40) = a5;
    *(_DWORD *)(*((_DWORD *)this + 5) + 40) = a5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000DA00
// Name: public: virtual void ClientMerge2::Write(class StrPtr __near *,class StrPtr __near *,class Error __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall ClientMerge2::Write(ClientMerge2 *this, struct StrPtr *a2, struct StrPtr *a3, struct Error *a4)
{
  (*(void (__thiscall **)(_DWORD, char *, int, struct Error *))(**((_DWORD **)this + 5) + 24))(
    a1: *((_DWORD *)this + 5),
    a2: a2->buffer,
    a3: a2->length,
    a4);
  if ( *((_DWORD *)this + 20) != 0 )
    MD5::Update(this: *((MD5 **)this + 6), a2);
}

//------------------------------------------------------------------------------
// Address: 0x1000DA40
// Name: public: virtual void ClientMerge2::Close(class Error __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall ClientMerge2::Close(ClientMerge2 *this, struct Error *a2)
{
  const char **v3; // ecx
  const char **v4; // [esp-Ch] [ebp-10h]

  (*(void (__thiscall **)(_DWORD, struct Error *))(**((_DWORD **)this + 5) + 32))(a1: *((_DWORD *)this + 5), a2);
  if ( *((_DWORD *)this + 20) != 0 )
  {
    MD5::Final(this: *((MD5 **)this + 6), a2: (struct StrBuf *)((char *)this + 52));
    v3 = (const char **)((char *)this + 28);
    v4 = (const char **)((char *)this + 52);
    if ( strcmp(*((const char **)this + 7), *((const char **)this + 10)) == 0 )
    {
      if ( StrPtr::operator!=(this: v3, a2: v4) )
        *((_DWORD *)this + 17) = 1;
    }
    else if ( StrPtr::operator!=(this: v3, a2: v4) )
    {
      if ( StrPtr::operator!=(this: (const char **)this + 10, a2: (const char **)this + 13) )
        *((_DWORD *)this + 18) = 1;
      else
        *((_DWORD *)this + 19) = 1;
    }
    else
    {
      *((_DWORD *)this + 16) = 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000DB00
// Name: public: virtual void ClientMerge2::Chmod(char const __near *,class Error __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall ClientMerge2::Chmod(ClientMerge2 *this, char *a2, struct Error *a3)
{
  FileSys *v3; // esi
  enum FilePerm v4; // eax

  v3 = *((FileSys **)this + 4);
  v4 = FileSys::Perm(a1: a2);
  FileSys::Chmod2(this: v3, a2: v4, a3);
}

//------------------------------------------------------------------------------
// Address: 0x1000DB30
// Name: public: virtual void ClientMerge2::CopyDigest(class StrPtr __near *,class Error __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall ClientMerge2::CopyDigest(ClientMerge2 *this, struct StrPtr *a2, struct Error *a3)
{
  StrBuf *v4; // ecx

  v4 = (StrBuf *)((char *)this + 28);
  v4->length = 0;
  StrBuf::Append(this: v4, a2);
  *((_DWORD *)this + 20) = 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000DB60
// Name: public: virtual enum MergeStatus ClientMerge2::AutoResolve(enum MergeForce)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall ClientMerge2::AutoResolve(ClientMerge2 *this, enum MergeForce a2)
{
  bool v3; // zf
  struct Error *v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  struct Error *v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // [esp-10h] [ebp-20h]
  int v14; // [esp-Ch] [ebp-1Ch]
  int v15; // [esp-8h] [ebp-18h]
  int v16; // [esp-4h] [ebp-14h]
  Error v17; // [esp+4h] [ebp-Ch] BYREF

  v3 = *((_DWORD *)this + 20) == 0;
  v17.ep = nullptr;
  v17.severity = E_EMPTY;
  if ( v3 )
  {
    if ( FileSys::Compare(this: *((FileSys **)this + 4), a2: *((struct FileSys **)this + 5), a3: &v17) == 0 )
    {
      v4 = Error::Set(this: &v17, a2: &MsgClient::MergeMsg2);
      v5 = Error::operator<<(a1: v4, a2: 0);
      v6 = Error::operator<<(a1: v5, a2: 0);
      v7 = Error::operator<<(a1: v6, a2: 1);
      Error::operator<<(a1: v7, a2: 0);
      (*(void (__thiscall **)(_DWORD, Error *))(**((_DWORD **)this + 3) + 12))(a1: *((_DWORD *)this + 3), a2: &v17);
LABEL_4:
      Error::~Error(this: &v17);
      return 4;
    }
    if ( a2 == CMF_FORCE )
      Error::Set(this: &v17, a2: (const struct ErrorId *)&MsgClient::NonTextFileMerge);
    else
      Error::Set(this: &v17, a2: &MsgClient::ResolveManually);
    (*(void (__thiscall **)(_DWORD, Error *))(**((_DWORD **)this + 3) + 12))(a1: *((_DWORD *)this + 3), a2: &v17);
    goto LABEL_9;
  }
  v16 = *((_DWORD *)this + 18);
  v15 = *((_DWORD *)this + 19);
  v14 = *((_DWORD *)this + 17);
  v13 = *((_DWORD *)this + 16);
  v9 = Error::Set(this: &v17, a2: &MsgClient::MergeMsg2);
  v10 = Error::operator<<(a1: v9, a2: v13);
  v11 = Error::operator<<(a1: v10, a2: v14);
  v12 = Error::operator<<(a1: v11, a2: v15);
  Error::operator<<(a1: v12, a2: v16);
  (*(void (__thiscall **)(_DWORD, Error *))(**((_DWORD **)this + 3) + 12))(a1: *((_DWORD *)this + 3), a2: &v17);
  if ( *((_DWORD *)this + 18) != 0 )
  {
LABEL_9:
    Error::~Error(this: &v17);
    return 1;
  }
  if ( *((_DWORD *)this + 16) == 0 )
    goto LABEL_4;
  Error::~Error(this: &v17);
  return 5;
}

//------------------------------------------------------------------------------
// Address: 0x1000DCA0
// Name: public: virtual class StrPtr const __near * ClientMerge2::GetYourDigest(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const struct StrPtr *__thiscall ClientMerge2::GetYourDigest(ClientMerge2 *this)
{
  return (const struct StrPtr *)((char *)this + 40);
}

//------------------------------------------------------------------------------
// Address: 0x1000DCB0
// Name: public: virtual class StrPtr const __near * ClientMerge2::GetTheirDigest(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const struct StrPtr *__thiscall ClientMerge2::GetTheirDigest(ClientMerge2 *this)
{
  return (const struct StrPtr *)((char *)this + 52);
}

//------------------------------------------------------------------------------
// Address: 0x1000DCC0
// Name: public: ClientMerge2::ClientMerge2(class ClientUser __near *,enum FileSysType,enum FileSysType)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientMerge2 *__thiscall ClientMerge2::ClientMerge2(
        ClientMerge2 *this,
        struct ClientUser *a2,
        enum FileSysType a3,
        enum FileSysType a4)
{
  FileSys *v5; // eax
  MD5 *v6; // eax
  MD5 *v7; // eax

  *(_DWORD *)this = &ClientMerge2::`vftable';
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 9) = 0;
  *((_DWORD *)this + 8) = 0;
  *((_DWORD *)this + 7) = StrBuf::nullStrBuf;
  *((_DWORD *)this + 12) = 0;
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 10) = StrBuf::nullStrBuf;
  *((_DWORD *)this + 15) = 0;
  *((_DWORD *)this + 14) = 0;
  *((_DWORD *)this + 13) = StrBuf::nullStrBuf;
  *((_DWORD *)this + 3) = a2;
  *((_DWORD *)this + 4) = a2->File(this: a2, a2: a3);
  v5 = a2->File(this: a2, a2: a4);
  *((_DWORD *)this + 5) = v5;
  v5->isTemp = 1;
  *((_DWORD *)this + 19) = 0;
  *((_DWORD *)this + 18) = 0;
  *((_DWORD *)this + 17) = 0;
  *((_DWORD *)this + 16) = 0;
  v6 = (MD5 *)operator new(nSize: 0xA0u);
  if ( v6 != nullptr )
  {
    v7 = MD5::MD5(this: v6);
    *((_DWORD *)this + 20) = 0;
    *((_DWORD *)this + 6) = v7;
  }
  else
  {
    *((_DWORD *)this + 20) = 0;
    *((_DWORD *)this + 6) = 0;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000DD90
// Name: public: virtual enum MergeStatus ClientMerge2::Resolve(class Error __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall ClientMerge2::Resolve(ClientMerge2 *this, struct Error *a2)
{
  const char *v3; // ebp
  int v4; // eax
  int v5; // eax
  int v6; // eax
  char *buffer; // ecx
  int v8; // eax
  const char *v10; // [esp-4h] [ebp-24h]
  int v11; // [esp+10h] [ebp-10h]
  StrBuf pMem; // [esp+14h] [ebp-Ch] BYREF

  v11 = (*(int (__thiscall **)(ClientMerge2 *, int))(*(_DWORD *)this + 4))(a1: this, a2: 2);
  pMem.size = 0;
  pMem.buffer = StrBuf::nullStrBuf;
  while ( 1 )
  {
    if ( v11 == 4 )
      v3 = "at";
    else
      v3 = v11 == 5 ? "ay" : byte_10040CDC;
    if ( ((a2->severity = E_EMPTY, v4 = *((_DWORD *)this + 4), pMem.length = 0, (v5 = *(_DWORD *)(v4 + 28) & 0xF) == 1)
       || v5 == 12
       || v5 == 14)
      && ((v6 = *(_DWORD *)(*((_DWORD *)this + 5) + 28) & 0xF) == 1 || v6 == 12 || v6 == 14) )
    {
      v10 = v3;
      Error::Set(this: a2, a2: (const struct ErrorId *)&MsgClient::MergePrompt2Edit);
    }
    else
    {
      v10 = v3;
      Error::Set(this: a2, a2: &MsgClient::MergePrompt2);
    }
    Error::operator<<(a1: v10);
    Error::Fmt(this: a2, a2: &pMem, a3: 0);
    a2->severity = E_EMPTY;
    (*(void (__thiscall **)(_DWORD, StrBuf *, StrBuf *, _DWORD, struct Error *))(**((_DWORD **)this + 3) + 52))(
      a1: *((_DWORD *)this + 3),
      a2: &pMem,
      a3: &pMem,
      a4: 0,
      a5: a2);
    if ( a2->severity > E_INFO )
      break;
    buffer = pMem.buffer;
    if ( *pMem.buffer == 0 && &pMem != (StrBuf *)v3 && pMem.buffer != v3 )
    {
      pMem.length = 0;
      StrBuf::Append(this: &pMem, src: v3);
      buffer = pMem.buffer;
    }
    v8 = buffer[1] | (*buffer << 8);
    if ( v8 > 25972 )
    {
      switch ( v8 )
      {
        case 25977:
          (*(void (__thiscall **)(_DWORD, _DWORD, struct Error *))(**((_DWORD **)this + 3) + 60))(
            a1: *((_DWORD *)this + 3),
            a2: *((_DWORD *)this + 4),
            a3: a2);
          goto LABEL_38;
        case 26624:
LABEL_36:
          (*(void (__thiscall **)(_DWORD, char **))(**((_DWORD **)this + 3) + 80))(
            a1: *((_DWORD *)this + 3),
            a2: &off_10041E20);
          goto LABEL_38;
        case 29440:
          if ( buffer != StrBuf::nullStrBuf )
            free(pMem: buffer);
          return 1;
        default:
          break;
      }
      goto LABEL_35;
    }
    if ( v8 == 25972 )
    {
      (*(void (__thiscall **)(_DWORD, _DWORD, struct Error *))(**((_DWORD **)this + 3) + 60))(
        a1: *((_DWORD *)this + 3),
        a2: *((_DWORD *)this + 5),
        a3: a2);
    }
    else
    {
      if ( v8 <= 24953 )
      {
        switch ( v8 )
        {
          case 24953:
            if ( buffer != StrBuf::nullStrBuf )
              free(pMem: buffer);
            return 5;
          case 16128:
            goto LABEL_36;
          case 24948:
            if ( buffer != StrBuf::nullStrBuf )
              free(pMem: buffer);
            return 4;
          default:
            break;
        }
LABEL_35:
        Error::Set(this: a2, a2: &MsgClient::BadFlag);
        goto LABEL_38;
      }
      if ( v8 != 25600 )
        goto LABEL_35;
      (*(void (__thiscall **)(_DWORD, _DWORD, _DWORD, int, _DWORD, struct Error *))(**((_DWORD **)this + 3) + 64))(
        a1: *((_DWORD *)this + 3),
        a2: *((_DWORD *)this + 5),
        a3: *((_DWORD *)this + 4),
        a4: 1,
        a5: 0,
        a6: a2);
    }
LABEL_38:
    if ( a2->severity > E_INFO )
    {
      (*(void (__thiscall **)(_DWORD, struct Error *))(**((_DWORD **)this + 3) + 12))(a1: *((_DWORD *)this + 3), a2);
      a2->severity = E_EMPTY;
    }
  }
  if ( pMem.buffer != StrBuf::nullStrBuf )
    free(pMem: pMem.buffer);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000DFD0
// Name: public: virtual void ClientMerge2::Select(enum MergeStatus,class Error __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge ClientMerge2::Select(ClientMerge2 *this@<ecx>, int a2@<edi>, enum MergeStatus a3, struct Error *a4)
{
  const char *v5; // edx
  int v6; // edi
  void (__thiscall ***v7)(_DWORD, int); // ecx
  const char *v8; // [esp+14h] [ebp-4h] BYREF
  unsigned int retaddr; // [esp+18h] [ebp+0h]

  if ( a3 == CMS_THEIRS )
  {
    (*(void (__thiscall **)(_DWORD, int, struct Error *, int))(**((_DWORD **)this + 5) + 56))(
      a1: *((_DWORD *)this + 5),
      a2: 1,
      a3: a4,
      a4: a2);
    (*(void (__thiscall **)(_DWORD, _DWORD, struct Error *))(**((_DWORD **)this + 5) + 52))(
      a1: *((_DWORD *)this + 5),
      a2: *((_DWORD *)this + 4),
      a3: a4);
    v5 = *(const char **)(*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 4) + 8))(a1: *((_DWORD *)this + 4));
    v6 = *((_DWORD *)this + 5);
    retaddr = strlen(v5);
    v8 = v5;
    (*(void (__thiscall **)(int, const char **))(*(_DWORD *)v6 + 4))(a1: v6, a2: &v8);
    v7 = *((void (__thiscall ****)(_DWORD, int))this + 4);
    if ( v7 != nullptr )
      (**v7)(a1: v7, a2: 1);
    *((_DWORD *)this + 4) = *((_DWORD *)this + 5);
    *((_DWORD *)this + 5) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000E060
// Name: public: virtual int NetTransport::GetFd(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall NetTransport::GetFd(NetTransport *this)
{
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1000E070
// Name: public: virtual class StrPtr __near * NetBuffer::GetAddress(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct StrPtr *__thiscall NetBuffer::GetAddress(NetBuffer *this, int a2)
{
  return (*(struct StrPtr *(__thiscall **)(_DWORD, int))(**((_DWORD **)this + 1) + 8))(a1: *((_DWORD *)this + 1), a2);
}

//------------------------------------------------------------------------------
// Address: 0x1000E080
// Name: public: virtual class StrPtr __near * NetBuffer::GetPeerAddress(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct StrPtr *__thiscall NetBuffer::GetPeerAddress(NetBuffer *this, int a2)
{
  return (*(struct StrPtr *(__thiscall **)(_DWORD, int))(**((_DWORD **)this + 1) + 12))(a1: *((_DWORD *)this + 1), a2);
}

//------------------------------------------------------------------------------
// Address: 0x1000E090
// Name: public: virtual void NetBuffer::Close(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall NetBuffer::Close(NetBuffer *this)
{
  (*(void (__thiscall **)(_DWORD))(**((_DWORD **)this + 1) + 24))(a1: *((_DWORD *)this + 1));
}

//------------------------------------------------------------------------------
// Address: 0x1000E0A0
// Name: public: virtual void NetBuffer::SetBreak(class KeepAlive __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall NetBuffer::SetBreak(NetBuffer *this, struct KeepAlive *a2)
{
  (*(void (__thiscall **)(_DWORD, struct KeepAlive *))(**((_DWORD **)this + 1) + 28))(a1: *((_DWORD *)this + 1), a2);
}

//------------------------------------------------------------------------------
// Address: 0x1000E0B0
// Name: public: virtual int NetBuffer::GetSendBuffering(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall NetBuffer::GetSendBuffering(NetBuffer *this)
{
  return (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 1) + 32))(a1: *((_DWORD *)this + 1));
}

//------------------------------------------------------------------------------
// Address: 0x1000E0C0
// Name: public: virtual int NetBuffer::GetRecvBuffering(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall NetBuffer::GetRecvBuffering(NetBuffer *this)
{
  return (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 1) + 36))(a1: *((_DWORD *)this + 1));
}

//------------------------------------------------------------------------------
// Address: 0x1000E0D0
// Name: public: void RpcService::SetEndpoint(char const __near *,class Error __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall RpcService::SetEndpoint(RpcService *this, char *string, struct Error *a3)
{
  void (__thiscall ***v4)(_DWORD, int); // ecx

  v4 = *((void (__thiscall ****)(_DWORD, int))this + 2);
  if ( v4 != nullptr )
    (**v4)(a1: v4, a2: 1);
  *((_DWORD *)this + 2) = NetEndPoint::Create(string, a2: a3);
}

//------------------------------------------------------------------------------
// Address: 0x1000E100
// Name: public: void RpcService::Dispatcher(struct RpcDispatch const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall RpcService::Dispatcher(RpcDispatcher **this, const struct RpcDispatch *a2)
{
  RpcDispatcher::Add(this: *(this + 1), a2);
}

//------------------------------------------------------------------------------
// Address: 0x1000E240
// Name: public: class StrPtr __near * Rpc::GetAddress(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct StrPtr *__thiscall Rpc::GetAddress(Rpc *this, int a2)
{
  if ( *((_DWORD *)this + 2) != 0 )
    return (*(struct StrPtr *(__thiscall **)(_DWORD, int))(**((_DWORD **)this + 2) + 8))(a1: *((_DWORD *)this + 2), a2);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1000E260
// Name: public: class StrPtr __near * Rpc::GetPeerAddress(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct StrPtr *__thiscall Rpc::GetPeerAddress(Rpc *this, int a2)
{
  if ( *((_DWORD *)this + 2) != 0 )
    return (*(struct StrPtr *(__thiscall **)(_DWORD, int))(**((_DWORD **)this + 2) + 12))(a1: *((_DWORD *)this + 2), a2);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1000E280
// Name: public: virtual void Rpc::VSetVar(class StrPtr const __near &,class StrPtr const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall Rpc::VSetVar(StrBuf **this, const struct StrPtr *a2, const struct StrPtr *a3)
{
  RpcSendBuffer::SetVar(this: *(this + 4), a2, src: a3);
}

//------------------------------------------------------------------------------
// Address: 0x1000E290
// Name: public: virtual class StrPtr __near * Rpc::VGetVar(class StrPtr const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct StrPtr *__thiscall Rpc::VGetVar(Rpc *this, const struct StrPtr *a2)
{
  return (*(struct StrPtr *(__thiscall **)(int, const struct StrPtr *))(*(_DWORD *)(*((_DWORD *)this + 5) + 12) + 4))(
           a1: *((_DWORD *)this + 5) + 12,
           a2);
}

//------------------------------------------------------------------------------
// Address: 0x1000E2A0
// Name: public: virtual int Rpc::VGetVarX(int,class StrRef __near &,class StrRef __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall Rpc::VGetVarX(Rpc *this, int a2, struct StrRef *a3, struct StrRef *a4)
{
  return (*(int (__thiscall **)(int, int, struct StrRef *, struct StrRef *))(*(_DWORD *)(*((_DWORD *)this + 5) + 12) + 16))(
           a1: *((_DWORD *)this + 5) + 12,
           a2,
           a3,
           a4);
}

//------------------------------------------------------------------------------
// Address: 0x1000E2B0
// Name: public: virtual void Rpc::VRemoveVar(class StrPtr const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall Rpc::VRemoveVar(Rpc *this, const struct StrPtr *a2)
{
  StrDict::RemoveVar(this: (StrDict *)(*((_DWORD *)this + 5) + 12), a2: a2->buffer);
}

//------------------------------------------------------------------------------
// Address: 0x1000E2D0
// Name: public: virtual void Rpc::VClear(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall Rpc::VClear(Rpc *this)
{
  int v1; // eax

  v1 = *((_DWORD *)this + 4);
  *(_DWORD *)(v1 + 12) = 0;
  *(_DWORD *)(v1 + 4) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000E2E0
// Name: public: void Rpc::CopyVars(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall Rpc::CopyVars(Rpc *this)
{
  RpcSendBuffer::CopyVars(this: *((StrBuf **)this + 4), a2: *((struct RpcRecvBuffer **)this + 5));
}

//------------------------------------------------------------------------------
// Address: 0x1000E2F0
// Name: public: void Rpc::DispatchOne(class RpcDispatcher __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall Rpc::DispatchOne(StrDict *this, struct RpcDispatcher *a2)
{
  StrBuf *v3; // edi
  int *v4; // ebx
  int *v5; // ecx
  __int64 v6; // rax
  bool v7; // cf
  struct StrPtr *Var; // eax
  struct StrPtr *v9; // ebp
  int *v10; // edi
  const struct RpcDispatch *v11; // ebx
  const struct RpcDispatch *v12; // eax
  int v13; // [esp-8h] [ebp-14h]

  v3 = *((StrBuf **)this + 5);
  v3[3].buffer = nullptr;
  (*((void (__thiscall **)(StrBuf *))v3[1].buffer + 6))(a1: v3 + 1);
  v3->length = 0;
  v4 = (int *)(this + 16);
  if ( RpcTransport::Receive(
         this: *((RpcTransport **)this + 2),
         a2: v3,
         a3: (Error *)(this + 16),
         a4: (struct Error *)(this + 13)) > 0 )
  {
    v5 = *((int **)this + 5);
    ++*((_DWORD *)this + 28);
    v6 = v5[1];
    v7 = __CFADD__((_DWORD)v6, *((_DWORD *)this + 30));
    *((_DWORD *)this + 30) += v6;
    *((_DWORD *)this + 31) += HIDWORD(v6) + v7;
    RpcRecvBuffer::Parse(this: (RpcRecvBuffer *)v5);
    Var = StrDict::GetVar(this, a2: "func", a3: (struct Error *)(this + 16));
    v9 = Var;
    if ( *v4 > 1 )
      return;
    if ( dword_1004F360 >= 1 )
      printf(format: "Rpc dispatch %s\n", Var->buffer);
    v10 = (int *)(this + 19);
    *((_DWORD *)this + 19) = 0;
    v11 = RpcDispatcher::Find(this: a2, a2: v9->buffer);
    if ( v11 != nullptr || (v11 = RpcDispatcher::Find(this: a2, a2: "funcHandler")) != nullptr )
    {
      (*((void (__cdecl **)(StrDict *, StrDict *))v11 + 1))(a1: this, a2: this + 19);
      if ( *v10 <= 1 )
        return;
      if ( *v10 == 4 )
      {
        v13 = *(_DWORD *)v11;
        Error::Set(this: (Error *)(this + 19), a2: &MsgRpc::Operat);
        Error::operator<<(a1: v13);
      }
    }
    else
    {
      Error::Set(this: (Error *)(this + 19), a2: &MsgRpc::UnReg);
      Error::operator<<(a1: v9);
    }
    v12 = RpcDispatcher::Find(this: a2, a2: "errorHandler");
    if ( v12 != nullptr )
      (*((void (__cdecl **)(StrDict *, StrDict *))v12 + 1))(a1: this, a2: this + 19);
    else
      ErrorLog::Report(this: (ErrorLog *)&AssertLog, a2: (Error *)(this + 19), a3: 1);
  }
  else if ( *v4 <= 1 )
  {
    Error::Set(this: (Error *)(this + 16), a2: &MsgRpc::Closed);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000E430
// Name: public: void Rpc::GotSendCompressed(class Error __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall Rpc::GotSendCompressed(NetBuffer **this, struct Error *a2)
{
  NetBuffer::SendCompression(this: *(this + 2), a2);
}

//------------------------------------------------------------------------------
// Address: 0x1000E440
// Name: public: void Rpc::GotRecvCompressed(class Error __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall Rpc::GotRecvCompressed(NetBuffer **this, struct Error *a2)
{
  NetBuffer::RecvCompression(this: *(this + 2), a2);
}

//------------------------------------------------------------------------------
// Address: 0x1000E450
// Name: public: StrNum::StrNum(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
StrNum *__thiscall StrNum::StrNum(StrNum *this, int a2)
{
  char *v3; // eax

  v3 = StrPtr::Itoa64(a1: a2, a2: (char *)this + 32);
  this->buffer = v3;
  this->length = (char *)this - v3 + 31;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000E4A0
// Name: public: RpcService::RpcService(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
RpcService *__thiscall RpcService::RpcService(RpcService *this)
{
  RpcDispatcher *v2; // eax
  RpcDispatcher *v3; // eax
  _DWORD *v4; // eax
  RpcDispatcher *v5; // ecx

  v2 = (RpcDispatcher *)operator new(nSize: 4u);
  if ( v2 != nullptr )
    v3 = RpcDispatcher::RpcDispatcher(this: v2);
  else
    v3 = nullptr;
  *((_DWORD *)this + 1) = v3;
  v4 = operator new(nSize: 0x10u);
  if ( v4 != nullptr )
  {
    v4[2] = 0;
    v4[1] = 0;
    *v4 = StrBuf::nullStrBuf;
    v4[3] = 0;
  }
  else
  {
    v4 = nullptr;
  }
  v5 = *((RpcDispatcher **)this + 1);
  *((_DWORD *)this + 3) = v4;
  *((_DWORD *)this + 2) = 0;
  *(_DWORD *)this = 2;
  RpcDispatcher::Add(this: v5, a2: (const struct RpcDispatch *)&rpcServices);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000E510
// Name: public: void Rpc::GotFlushed(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall Rpc::GotFlushed(FileSys *this)
{
  const char **v2; // eax
  const char **v3; // edi
  const char **v4; // eax
  const char **v5; // ebx

  FileSys::Set(this, a2: "fseq");
  v3 = v2;
  FileSys::Set(this, a2: "rseq");
  v5 = v4;
  if ( v3 != nullptr )
    this->type -= atoi(nptr: *v3);
  if ( v5 != nullptr )
    this->charSet -= atoi(nptr: *v5);
}

//------------------------------------------------------------------------------
// Address: 0x1000E560
// Name: public: RpcService::~RpcService(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall RpcService::~RpcService(RpcService *this)
{
  void *v2; // edi
  void (__thiscall ***v3)(_DWORD, int); // ecx
  void **v4; // esi

  v2 = *((void **)this + 1);
  if ( v2 != nullptr )
  {
    RpcDispatcher::~RpcDispatcher(this: *((RpcDispatcher **)this + 1));
    free(pMem: v2);
  }
  v3 = *((void (__thiscall ****)(_DWORD, int))this + 2);
  if ( v3 != nullptr )
    (**v3)(a1: v3, a2: 1);
  v4 = *((void ***)this + 3);
  if ( v4 != nullptr )
  {
    if ( *v4 != StrBuf::nullStrBuf )
      free(pMem: *v4);
    free(pMem: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000E5B0
// Name: public: void RpcService::SetProtocol(char const __near *,class StrRef const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall RpcService::SetProtocol(RpcService *this, char *a2, const struct StrRef *src)
{
  StrBuf *v3; // ecx
  struct StrPtr v4; // [esp+8h] [ebp-8h] BYREF

  v3 = *((StrBuf **)this + 3);
  v4.length = strlen(a2);
  v4.buffer = a2;
  RpcSendBuffer::SetVar(this: v3, a2: &v4, src);
}

//------------------------------------------------------------------------------
// Address: 0x1000E5F0
// Name: public: Rpc::Rpc(class RpcService __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
Rpc *__thiscall Rpc::Rpc(Rpc *this, struct RpcService *a2)
{
  _DWORD *v3; // eax
  _DWORD *v4; // eax
  _DWORD *v5; // ebx
  int v6; // edx
  int v7; // eax

  *(_DWORD *)this = &Rpc::`vftable';
  *((_DWORD *)this + 15) = 0;
  *((_DWORD *)this + 13) = 0;
  *((_DWORD *)this + 18) = 0;
  *((_DWORD *)this + 16) = 0;
  *((_DWORD *)this + 21) = 0;
  *((_DWORD *)this + 19) = 0;
  *((_DWORD *)this + 1) = a2;
  v3 = operator new(nSize: 0x10u);
  if ( v3 != nullptr )
  {
    v3[2] = 0;
    v3[1] = 0;
    *v3 = StrBuf::nullStrBuf;
    v3[3] = 0;
  }
  else
  {
    v3 = nullptr;
  }
  *((_DWORD *)this + 4) = v3;
  v4 = operator new(nSize: 0x28u);
  v5 = v4;
  if ( v4 != nullptr )
  {
    v4[2] = 0;
    v4[1] = 0;
    *v4 = StrBuf::nullStrBuf;
    StrPtrDict::StrPtrDict(this: (StrPtrDict *)(v4 + 3));
    StrPtrArray::StrPtrArray(this: (StrPtrArray *)(v5 + 7));
  }
  else
  {
    v5 = nullptr;
  }
  *((_DWORD *)this + 5) = v5;
  *((_DWORD *)this + 2) = 0;
  v6 = dword_1004F8A0;
  *((_DWORD *)this + 23) = dword_1004F8A0;
  *((_DWORD *)this + 24) = v6;
  v7 = dword_1004F8BC;
  *((_DWORD *)this + 25) = 0;
  *((_DWORD *)this + 26) = 0;
  *((_DWORD *)this + 27) = 0;
  *((_DWORD *)this + 28) = 0;
  *((_DWORD *)this + 30) = 0;
  *((_DWORD *)this + 31) = 0;
  *((_DWORD *)this + 22) = v7;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000E6A0
// Name: public: virtual Rpc::~Rpc(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall Rpc::~Rpc(StrDict *this)
{
  NetBuffer *v2; // ecx
  void (__thiscall ***v3)(_DWORD, int); // ecx
  void **v4; // edi
  StrDict *v5; // edi

  v2 = *((NetBuffer **)this + 2);
  this->__vftable = (StrDict_vtbl *)&Rpc::`vftable';
  if ( v2 != nullptr )
  {
    NetBuffer::Flush(this: v2, a2: (struct Error *)(this + 13));
    (*(void (__thiscall **)(_DWORD))(**((_DWORD **)this + 2) + 24))(a1: *((_DWORD *)this + 2));
    v3 = *((void (__thiscall ****)(_DWORD, int))this + 2);
    if ( v3 != nullptr )
      (**v3)(a1: v3, a2: 1);
    *((_DWORD *)this + 2) = 0;
  }
  v4 = *((void ***)this + 4);
  if ( v4 != nullptr )
  {
    if ( *v4 != StrBuf::nullStrBuf )
      free(pMem: *v4);
    free(pMem: v4);
  }
  v5 = *((StrDict **)this + 5);
  if ( v5 != nullptr )
  {
    StrPtrArray::~StrPtrArray(this: (StrPtrArray *)&v5[7]);
    StrPtrDict::~StrPtrDict(this: v5 + 3);
    if ( (char *)v5->__vftable != StrBuf::nullStrBuf )
      free(pMem: v5->__vftable);
    free(pMem: v5);
  }
  Error::~Error(this: (Error *)(this + 19));
  Error::~Error(this: (Error *)(this + 16));
  Error::~Error(this: (Error *)(this + 13));
  StrDict::~StrDict(this);
}

//------------------------------------------------------------------------------
// Address: 0x1000E750
// Name: public: class StrBuf __near * Rpc::MakeVar(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct StrBuf *__thiscall Rpc::MakeVar(Rpc *this, char *a2)
{
  StrBuf *v2; // ecx
  struct StrPtr v4; // [esp+8h] [ebp-8h] BYREF

  v2 = *((StrBuf **)this + 4);
  v4.length = strlen(a2);
  v4.buffer = a2;
  return RpcSendBuffer::MakeVar(this: v2, a2: &v4);
}

//------------------------------------------------------------------------------
// Address: 0x1000E790
// Name: public: int Rpc::InvokeOne(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall Rpc::InvokeOne(StrDict *this, char *a2)
{
  int v3; // ecx
  int v4; // edi
  int v5; // ebp
  StrNum *v6; // eax
  StrNum *v7; // eax
  struct StrPtr *v8; // edi
  int v9; // eax
  int v10; // ecx
  bool v12; // cf
  int v13; // esi
  const struct StrPtr *v14; // [esp-Ch] [ebp-54h]
  struct StrPtr src; // [esp+8h] [ebp-40h] BYREF
  struct StrPtr v16; // [esp+10h] [ebp-38h] BYREF
  StrBuf pMem; // [esp+18h] [ebp-30h] BYREF
  int v18; // [esp+24h] [ebp-24h]
  StrNum v19; // [esp+28h] [ebp-20h] BYREF

  if ( *((int *)this + 13) > 1 || *((int *)this + 16) > 1 )
  {
    v13 = *((_DWORD *)this + 4);
    *(_DWORD *)(v13 + 12) = 0;
    *(_DWORD *)(v13 + 4) = 0;
  }
  else
  {
    if ( *((_DWORD *)this + 12) == 0 && strcmp(a2, "protocol") != 0 )
    {
      v3 = *((_DWORD *)this + 2);
      pMem.size = 0;
      pMem.length = 0;
      pMem.buffer = StrBuf::nullStrBuf;
      v18 = 0;
      v4 = (*(int (__thiscall **)(int))(*(_DWORD *)v3 + 32))(a1: v3);
      v5 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 2) + 36))(a1: *((_DWORD *)this + 2));
      v14 = *(const struct StrPtr **)(*((_DWORD *)this + 1) + 12);
      pMem.length = 0;
      StrBuf::Append(this: &pMem, a2: v14);
      src.length = strlen("sndbuf");
      src.buffer = "sndbuf";
      v6 = StrNum::StrNum(this: &v19, a2: v4);
      RpcSendBuffer::SetVar(this: &pMem, a2: &src, src: v6);
      src.length = strlen("rcvbuf");
      src.buffer = "rcvbuf";
      v7 = StrNum::StrNum(this: &v19, a2: v5);
      RpcSendBuffer::SetVar(this: &pMem, a2: &src, src: v7);
      src.length = strlen("protocol");
      src.buffer = "protocol";
      v16.length = strlen("func");
      v16.buffer = "func";
      RpcSendBuffer::SetVar(this: &pMem, a2: &v16, &src);
      if ( dword_1004F360 >= 1 )
        printf(format: "Rpc invoking protocol\n");
      if ( v18 != 0 )
        RpcSendBuffer::EndVar(this: &pMem);
      RpcTransport::Send(this: *((RpcTransport **)this + 2), a2: &pMem, a3: (Error *)(this + 13));
      if ( pMem.buffer != StrBuf::nullStrBuf )
        free(pMem: pMem.buffer);
    }
    *((_DWORD *)this + 12) = 1;
    StrDict::SetVar(this, a2: "func", a3: a2);
    if ( dword_1004F360 >= 1 )
      printf(format: "Rpc invoking %s\n", a2);
    v8 = *((struct StrPtr **)this + 4);
    if ( v8[1].length != 0 )
      RpcSendBuffer::EndVar(this: *((StrBuf **)this + 4));
    RpcTransport::Send(this: *((RpcTransport **)this + 2), a2: v8, a3: (Error *)(this + 13));
    if ( *((int *)this + 13) <= 1 )
    {
      v9 = *((_DWORD *)this + 4);
      v10 = *(_DWORD *)(v9 + 4);
      *(_DWORD *)(v9 + 12) = 0;
      *(_DWORD *)(v9 + 4) = 0;
      ++*((_DWORD *)this + 25);
      v12 = __CFADD__(v10 + 5, *((_DWORD *)this + 26));
      *((_DWORD *)this + 26) += v10 + 5;
      *((_DWORD *)this + 27) += ((v10 + 5) >> 31) + v12;
      return v10 + 5;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000E9E0
// Name: public: void Rpc::Dispatch(enum Rpc::DispatchFlag,class RpcDispatcher __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall Rpc::Dispatch(int this, int a2, struct RpcDispatcher *a3)
{
  int result; // eax
  int v5; // eax
  int v6; // edi
  int v7; // ebp
  int v8; // ecx
  bool v9; // cc
  bool v10; // zf
  _DWORD *v11; // eax
  _DWORD *v12; // edi
  StrDict *v13; // edi
  int v14; // [esp+4h] [ebp-8h]
  int v15; // [esp+8h] [ebp-4h]

  result = *(_DWORD *)(this + 40);
  if ( result <= 1 )
  {
    v5 = result + 1;
    *(_DWORD *)(this + 40) = v5;
    if ( dword_1004F360 >= 5 )
      printf(
        format: ">>> Dispatch(%d) %d/%d %d/%d %d\n",
        v5,
        *(_DWORD *)(this + 24),
        *(_DWORD *)(this + 28),
        *(_DWORD *)(this + 32),
        *(_DWORD *)(this + 36),
        a2);
    v6 = *(_DWORD *)(this + 88);
    v14 = v6;
    if ( *(_DWORD *)(this + 36) != 0 )
      v7 = *(_DWORD *)(this + 96);
    else
      v7 = *(_DWORD *)(this + 92);
    v8 = a2;
    if ( a2 != 1 )
    {
      v14 = 0;
      v6 = 0;
    }
    if ( a2 == 2 )
      v7 = 0;
    v9 = *(_DWORD *)(this + 64) <= 1;
    v15 = *(_DWORD *)(this + 20);
    *(_DWORD *)(this + 20) = 0;
    if ( v9 )
    {
      while ( *(_DWORD *)(this + 44) == 0 )
      {
        if ( *(_DWORD *)(this + 24) > v6 && *(int *)(this + 52) <= 1 )
        {
          if ( dword_1004F360 >= 5 )
            printf(format: "Rpc flush %d bytes\n", *(_DWORD *)(this + 24));
          StrDict::SetVar((StrDict *)this, a2: "himark", a3: v6 != 0 ? v7 : 0);
          *(_DWORD *)(this + 28) += 60;
          v10 = *(_DWORD *)(this + 24) == -60;
          *(_DWORD *)(this + 24) += 60;
          if ( !v10 )
            StrDict::SetVar((StrDict *)this, a2: "fseq", a3: *(_DWORD *)(this + 24));
          if ( *(_DWORD *)(this + 32) != 0 )
            StrDict::SetVar((StrDict *)this, a2: "rseq", a3: *(_DWORD *)(this + 32));
          *(_DWORD *)(this + 24) = 0;
          *(_DWORD *)(this + 32) = 0;
          Rpc::InvokeOne((StrDict *)this, a2: "flush1");
          goto LABEL_37;
        }
        if ( v8 != 0 )
        {
          if ( v8 == 1 )
          {
            if ( *(_DWORD *)(this + 28) <= v7 )
              goto LABEL_30;
          }
          else if ( v8 != 2 || *(_DWORD *)(this + 28) == 0 )
          {
LABEL_30:
            if ( *(int *)(this + 52) <= 1 )
              break;
          }
        }
        if ( *(_DWORD *)(this + 20) == 0 )
        {
          v11 = operator new(nSize: 0x28u);
          v12 = v11;
          if ( v11 != nullptr )
          {
            v11[2] = 0;
            v11[1] = 0;
            *v11 = StrBuf::nullStrBuf;
            StrPtrDict::StrPtrDict(this: (StrPtrDict *)(v11 + 3));
            StrPtrArray::StrPtrArray(this: (StrPtrArray *)(v12 + 7));
          }
          else
          {
            v12 = nullptr;
          }
          *(_DWORD *)(this + 20) = v12;
          v6 = v14;
        }
        Rpc::DispatchOne((StrDict *)this, a2: a3);
LABEL_37:
        if ( *(int *)(this + 64) > 1 )
          break;
        v8 = a2;
      }
    }
    v13 = *(StrDict **)(this + 20);
    if ( v13 != nullptr )
    {
      StrPtrArray::~StrPtrArray(this: (StrPtrArray *)&v13[7]);
      StrPtrDict::~StrPtrDict(this: v13 + 3);
      if ( (char *)v13->__vftable != StrBuf::nullStrBuf )
        free(pMem: v13->__vftable);
      free(pMem: v13);
    }
    result = v15;
    *(_DWORD *)(this + 20) = v15;
    if ( dword_1004F360 >= 5 )
      result = printf(
                 format: "<<< Dispatch(%d) %d/%d %d/%d %d\n",
                 *(_DWORD *)(this + 40),
                 *(_DWORD *)(this + 24),
                 *(_DWORD *)(this + 28),
                 *(_DWORD *)(this + 32),
                 *(_DWORD *)(this + 36),
                 a2);
    v10 = (*(_DWORD *)(this + 40))-- == 1;
    if ( v10 )
      *(_DWORD *)(this + 44) = 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000EC10
// Name: public: void Rpc::Invoke(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall Rpc::Invoke(StrDict *this, char *a2)
{
  int v3; // eax
  int v4; // ecx

  if ( *((_DWORD *)this + 9) != 0 )
  {
    v3 = Rpc::InvokeOne(this, a2);
    v4 = *((_DWORD *)this + 1);
    *((_DWORD *)this + 7) += v3;
    *((_DWORD *)this + 6) += v3;
    Rpc::Dispatch((int)this, a2: 1, a3: *(struct RpcDispatcher **)(v4 + 4));
  }
  else
  {
    Rpc::InvokeOne(this, a2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000EC50
// Name: public: void Rpc::ReleaseFinal(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall Rpc::ReleaseFinal(StrDict *this)
{
  int v2; // eax

  if ( *((_DWORD *)this + 9) != 0 )
  {
    v2 = Rpc::InvokeOne(this, a2: "release2");
    *((_DWORD *)this + 7) += v2;
    *((_DWORD *)this + 6) += v2;
    Rpc::Dispatch((int)this, a2: 1, a3: *(struct RpcDispatcher **)(*((_DWORD *)this + 1) + 4));
  }
  else
  {
    Rpc::InvokeOne(this, a2: "release2");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000EC90
// Name: private: void RpcSendBuffer::EndVar(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall RpcSendBuffer::EndVar(StrBuf *this)
{
  int v2; // eax
  int v3; // ecx
  char *v4; // edi
  int length; // edi
  bool v6; // cc

  v2 = *((_DWORD *)this + 3);
  v3 = this->length - v2;
  v4 = &this->buffer[v2];
  *(v4 - 4) = v3;
  *(v4 - 3) = v3 / 256;
  *(v4 - 2) = v3 / 0x10000;
  *(v4 - 1) = v3 / 0x1000000;
  length = this->length;
  v6 = length + 1 <= this->size;
  this->length = length + 1;
  if ( !v6 )
    StrBuf::Grow(this, a2: length);
  this->buffer[length] = 0;
  *((_DWORD *)this + 3) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000ED40
// Name: public: void RpcRecvBuffer::Parse(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall RpcRecvBuffer::Parse(RpcRecvBuffer *this)
{
  char *v2; // ebp
  const char *v3; // esi
  unsigned int v4; // ebx
  const char *v5; // eax
  int v6; // eax
  char *buffer; // eax
  struct StrPtr v8; // [esp+10h] [ebp-10h] BYREF
  const char *v9; // [esp+18h] [ebp-8h] BYREF
  int v10; // [esp+1Ch] [ebp-4h]

  v2 = (char *)this + 12;
  *((_DWORD *)this + 9) = 0;
  (*(void (__thiscall **)(char *))(*((_DWORD *)this + 3) + 24))(a1: (char *)this + 12);
  v3 = *(const char **)this;
  v4 = *(_DWORD *)this + *((_DWORD *)this + 1);
  if ( *(_DWORD *)this < v4 )
  {
    do
    {
      v5 = &v3[strlen(v3) + 1];
      v9 = v3;
      v10 = v5 - (v3 + 1);
      v6 = *(unsigned __int8 *)v5
         + ((*((unsigned __int8 *)v5 + 1) + ((*((unsigned __int8 *)v5 + 2) + (*((unsigned __int8 *)v5 + 3) << 8)) << 8)) << 8);
      v8.buffer = (char *)&v3[v10 + 5];
      v3 = &v8.buffer[v6 + 1];
      v8.length = v6;
      if ( v10 != 0 )
        (*(void (__thiscall **)(char *, const char **, struct StrPtr *))(*(_DWORD *)v2 + 8))(a1: v2, a2: &v9, a3: &v8);
      else
        StrPtrArray::Put(this: (RpcRecvBuffer *)((char *)this + 28), a2: &v8);
      if ( dword_1004F360 >= 3 )
      {
        buffer = v8.buffer;
        if ( v8.length >= 110 )
          buffer = "<big>";
        printf(format: "RpcRecvBuffer %s = %s\n", v9, buffer);
      }
    }
    while ( (unsigned int)v3 < v4 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000EE20
// Name: public: class StrBuf __near * RpcSendBuffer::MakeVar(class StrPtr const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct StrBuf *__thiscall RpcSendBuffer::MakeVar(StrBuf *this, const struct StrPtr *a2)
{
  int length; // edi
  bool v4; // zf
  bool v5; // sf
  bool v6; // of

  if ( *((_DWORD *)this + 3) != 0 )
    RpcSendBuffer::EndVar(this);
  StrBuf::Append(this, a2);
  length = this->length;
  v6 = __OFSUB__(length + 5, this->size);
  v4 = length + 5 == this->size;
  v5 = length + 5 - this->size < 0;
  this->length = length + 5;
  if ( !(v5 ^ v6 | v4) )
    StrBuf::Grow(this, a2: length);
  this->buffer[length] = 0;
  *((_DWORD *)this + 3) = this->length;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000EE70
// Name: public: void RpcSendBuffer::SetVar(class StrPtr const __near &,class StrPtr const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall RpcSendBuffer::SetVar(StrBuf *this, const struct StrPtr *a2, const struct StrPtr *src)
{
  unsigned int length; // ebx
  int v6; // edi
  bool v7; // cc
  int v8; // edi
  char *buffer; // eax
  unsigned __int8 *srca; // [esp+18h] [ebp+8h]

  length = src->length;
  srca = (unsigned __int8 *)src->buffer;
  if ( *((_DWORD *)this + 3) != 0 )
    RpcSendBuffer::EndVar(this);
  StrBuf::Append(this, a2);
  v6 = this->length;
  v7 = v6 + 5 <= this->size;
  this->length = v6 + 5;
  if ( !v7 )
    StrBuf::Grow(this, a2: v6);
  this->buffer[v6] = 0;
  v8 = this->length;
  v7 = (int)(v8 + length) <= this->size;
  *((_DWORD *)this + 3) = v8;
  this->length = v8 + length;
  if ( !v7 )
    StrBuf::Grow(this, a2: v8);
  memcpy(dst: (unsigned __int8 *)&this->buffer[v8], src: srca, count: length);
  RpcSendBuffer::EndVar(this);
  if ( dword_1004F360 >= 3 )
  {
    if ( src->length >= 110 )
      buffer = "<big>";
    else
      buffer = src->buffer;
    printf(format: "RpcSendBuffer %s = %s\n", a2->buffer, buffer);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000EF20
// Name: public: void RpcSendBuffer::CopyVars(class RpcRecvBuffer __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall RpcSendBuffer::CopyVars(StrBuf *this, struct RpcRecvBuffer *a2)
{
  int i; // edi
  struct StrPtr v4; // [esp+Ch] [ebp-10h] BYREF
  struct StrPtr src; // [esp+14h] [ebp-8h] BYREF

  for ( i = 0;
        (*(int (__thiscall **)(char *, int, struct StrPtr *, struct StrPtr *))(*((_DWORD *)a2 + 3) + 16))(
          a1: (char *)a2 + 12,
          a2: i,
          a3: &v4,
          a4: &src) != 0;
        ++i )
  {
    if ( strcmp(v4.buffer, "data") != 0 && strcmp(v4.buffer, "func") != 0 )
      RpcSendBuffer::SetVar(this, a2: &v4, &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000F000
// Name: public: StrFixed::StrFixed(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
StrFixed *__thiscall StrFixed::StrFixed(StrFixed *this, unsigned int nSize)
{
  this->length = nSize;
  this->buffer = (char *)operator new(nSize);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000F040
// Name: public: virtual NetBuffer::~NetBuffer(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall NetBuffer::~NetBuffer(NetBuffer *this)
{
  int v2; // eax
  void (__thiscall ***v3)(_DWORD, int); // ecx

  v2 = *((_DWORD *)this + 9);
  *(_DWORD *)this = &NetBuffer::`vftable';
  if ( v2 != 0 )
    PZ_inflateEnd(a1: v2);
  if ( *((_DWORD *)this + 10) != 0 )
    PZ_deflateEnd(a1: *((_DWORD *)this + 10));
  free(pMem: *((void **)this + 9));
  free(pMem: *((void **)this + 10));
  v3 = *((void (__thiscall ****)(_DWORD, int))this + 1);
  if ( v3 != nullptr )
    (**v3)(a1: v3, a2: 1);
  free(pMem: *((void **)this + 7));
  free(pMem: *((void **)this + 5));
  NetTransport::~NetTransport(this);
}

//------------------------------------------------------------------------------
// Address: 0x1000F0B0
// Name: public: void NetBuffer::RecvCompression(class Error __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall NetBuffer::RecvCompression(NetBuffer *this, struct Error *a2)
{
  _DWORD *v3; // eax

  if ( *((_DWORD *)this + 9) == 0 )
  {
    if ( dword_1004F2F0 >= 4 )
      printf(format: "NetBuffer recv compressing\n");
    v3 = operator new(nSize: 0x38u);
    *((_DWORD *)this + 9) = v3;
    v3[8] = 0;
    *(_DWORD *)(*((_DWORD *)this + 9) + 36) = 0;
    *(_DWORD *)(*((_DWORD *)this + 9) + 40) = 0;
    if ( PZ_inflateInit2_(a1: *((_DWORD *)this + 9), a2: -15, a3: "1.1.4", a4: 56) != 0 )
    {
      Error::Set(this: a2, a2: &MsgSupp::InflateInit);
    }
    else
    {
      **((_DWORD **)this + 9) = *((_DWORD *)this + 3);
      *(_DWORD *)(*((_DWORD *)this + 9) + 4) = *((_DWORD *)this + 4) - *((_DWORD *)this + 3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000F140
// Name: public: void NetBuffer::Flush(class Error __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall NetBuffer::Flush(NetBuffer *this, struct Error *a2)
{
  _DWORD *v3; // eax
  int v4; // ebx
  int v5; // eax

  if ( a2->severity <= E_INFO && *((_DWORD *)this + 2) != 0 )
  {
    if ( dword_1004F2F0 >= 4 )
      printf(format: "NetBuffer flush\n");
    v3 = *((_DWORD **)this + 10);
    if ( v3 != nullptr )
    {
      v4 = 0;
      *v3 = 0;
      *(_DWORD *)(*((_DWORD *)this + 10) + 4) = 0;
      if ( a2->severity <= E_INFO )
      {
        while ( 1 )
        {
          v5 = *(_DWORD *)(*((_DWORD *)this + 10) + 16);
          if ( v5 == 0 || v4 != 0 )
          {
            (*(void (__thiscall **)(_DWORD, _DWORD, int, struct Error *))(**((_DWORD **)this + 1) + 16))(
              a1: *((_DWORD *)this + 1),
              a2: *((_DWORD *)this + 5),
              a3: *((_DWORD *)this + 6) - v5,
              a4: a2);
            *(_DWORD *)(*((_DWORD *)this + 10) + 12) = *((_DWORD *)this + 5);
            *(_DWORD *)(*((_DWORD *)this + 10) + 16) = *((_DWORD *)this + 6);
            if ( v4 != 0 )
              break;
          }
          if ( PZ_deflate(a1: *((_DWORD *)this + 10), a2: 3) != 0 )
            Error::Set(this: a2, a2: &MsgSupp::Deflate);
          if ( *(_DWORD *)(*((_DWORD *)this + 10) + 16) != 0 )
            ++v4;
          if ( a2->severity > E_INFO )
          {
            *((_DWORD *)this + 2) = 0;
            return;
          }
        }
      }
    }
    else
    {
      (*(void (__thiscall **)(_DWORD, _DWORD, _DWORD, struct Error *))(**((_DWORD **)this + 1) + 16))(
        a1: *((_DWORD *)this + 1),
        a2: *((_DWORD *)this + 5),
        a3: *((_DWORD *)this + 2),
        a4: a2);
    }
    *((_DWORD *)this + 2) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000F230
// Name: public: virtual int NetBuffer::IsAlive(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall NetBuffer::IsAlive(NetBuffer *this)
{
  int result; // eax

  result = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 1) + 4))(a1: *((_DWORD *)this + 1));
  if ( result == 0 )
    *((_DWORD *)this + 3) = *((_DWORD *)this + 4);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000F250
// Name: public: void NetBuffer::SendCompression(class Error __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall NetBuffer::SendCompression(NetBuffer *this, Error *a2)
{
  _DWORD *v3; // eax

  if ( *((_DWORD *)this + 10) == 0 )
  {
    if ( dword_1004F2F0 >= 4 )
      printf(format: "NetBuffer send compressing\n");
    NetBuffer::Flush(this, a2);
    v3 = operator new(nSize: 0x38u);
    *((_DWORD *)this + 10) = v3;
    v3[8] = 0;
    *(_DWORD *)(*((_DWORD *)this + 10) + 36) = 0;
    *(_DWORD *)(*((_DWORD *)this + 10) + 40) = 0;
    if ( PZ_deflateInit2_(a1: *((_DWORD *)this + 10), a2: -1, a3: 8, a4: -15, a5: 8, a6: 0, a7: "1.1.4", a8: 56) != 0 )
    {
      Error::Set(this: a2, a2: &MsgSupp::DeflateInit);
    }
    else
    {
      *(_DWORD *)(*((_DWORD *)this + 10) + 12) = *((_DWORD *)this + 5);
      *(_DWORD *)(*((_DWORD *)this + 10) + 16) = *((_DWORD *)this + 6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000F2F0
// Name: public: int NetBuffer::Receive(char __near *,int,class Error __near *,class Error __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall NetBuffer::Receive(NetBuffer *this, char *dst, int a3, Error *a4, struct Error *a5)
{
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int result; // eax
  int v10; // ebp
  unsigned __int8 *v11; // ebx
  signed int v12; // edi
  int v13; // eax
  struct StrPtr v14; // [esp+10h] [ebp-8h] BYREF

  v6 = *((_DWORD *)this + 9);
  if ( v6 == 0 )
  {
    v10 = a3;
    v11 = (unsigned __int8 *)dst;
    if ( a3 == 0 )
      goto LABEL_9;
    while ( 1 )
    {
      v12 = *((_DWORD *)this + 4) - *((_DWORD *)this + 3);
      if ( v12 == 0 )
      {
        if ( v10 >= *((_DWORD *)this + 8) )
        {
          NetBuffer::Flush(this, a2: a5);
          result = (*(int (__thiscall **)(_DWORD, unsigned __int8 *, _DWORD, Error *))(**((_DWORD **)this + 1) + 20))(
                     a1: *((_DWORD *)this + 1),
                     a2: v11,
                     a3: *((_DWORD *)this + 8),
                     a4);
          if ( result <= 0 )
            return result;
          v10 -= result;
          v11 += result;
          goto LABEL_25;
        }
        NetBuffer::Flush(this, a2: a5);
        result = (*(int (__thiscall **)(_DWORD, _DWORD, _DWORD, Error *))(**((_DWORD **)this + 1) + 20))(
                   a1: *((_DWORD *)this + 1),
                   a2: *((_DWORD *)this + 7),
                   a3: *((_DWORD *)this + 8),
                   a4);
        v12 = result;
        if ( result <= 0 )
          return result;
        v13 = *((_DWORD *)this + 7);
        *((_DWORD *)this + 4) = v13 + v12;
        *((_DWORD *)this + 3) = v13;
      }
      if ( v12 > v10 )
        v12 = v10;
      memcpy(dst: v11, src: *((unsigned __int8 **)this + 3), count: v12);
      *((_DWORD *)this + 3) += v12;
      v10 -= v12;
      v11 += v12;
LABEL_25:
      if ( v10 == 0 )
        goto LABEL_9;
    }
  }
  *(_DWORD *)(v6 + 12) = dst;
  *(_DWORD *)(*((_DWORD *)this + 9) + 16) = a3;
  if ( *(_DWORD *)(*((_DWORD *)this + 9) + 16) == 0 )
  {
LABEL_9:
    if ( dword_1004F2F0 >= 5 )
    {
      printf(format: "NetBuffer rcv %d: ", a3);
      v14.buffer = dst;
      v14.length = a3;
      StrOps::Dump(a1: &v14);
    }
    return a3;
  }
  while ( 1 )
  {
    v7 = *((_DWORD *)this + 9);
    if ( *(_DWORD *)(v7 + 4) == 0 )
    {
      NetBuffer::Flush(this, a2: a5);
      **((_DWORD **)this + 9) = *((_DWORD *)this + 7);
      *(_DWORD *)(*((_DWORD *)this + 9) + 4) = (*(int (__thiscall **)(_DWORD, _DWORD, _DWORD, Error *))(**((_DWORD **)this + 1) + 20))(
                                                 a1: *((_DWORD *)this + 1),
                                                 a2: *((_DWORD *)this + 7),
                                                 a3: *((_DWORD *)this + 8),
                                                 a4);
      if ( a4->severity > E_INFO )
        return 0;
      v7 = *((_DWORD *)this + 9);
      if ( *(_DWORD *)(v7 + 4) == 0 )
        return 0;
    }
    v8 = PZ_inflate(a1: (unsigned __int8 *)v7, a2: 0);
    if ( v8 == 1 )
      goto LABEL_9;
    if ( v8 != 0 )
    {
      Error::Set(this: a4, a2: &MsgSupp::Inflate);
      return 0;
    }
    if ( *(_DWORD *)(*((_DWORD *)this + 9) + 16) == 0 )
      goto LABEL_9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000F490
// Name: public: virtual void NetBuffer::Send(char const __near *,int,class Error __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall NetBuffer::Send(NetBuffer *this, char *src, int a3, struct Error *a4)
{
  int v4; // ebx
  unsigned __int8 *v5; // ebp
  char **v7; // eax
  int v8; // eax
  int v9; // ecx
  int *v10; // edi
  int v11; // eax
  int v12; // ecx
  unsigned int v13; // edi
  struct StrPtr v14; // [esp+10h] [ebp-8h] BYREF

  v4 = a3;
  v5 = (unsigned __int8 *)src;
  if ( dword_1004F2F0 >= 5 )
  {
    printf(format: "NetBuffer snd %d: ", a3);
    v14.buffer = src;
    v14.length = a3;
    StrOps::Dump(a1: &v14);
  }
  v7 = *((char ***)this + 10);
  if ( v7 == nullptr )
  {
    if ( a3 == 0 )
      return;
    while ( 1 )
    {
      v8 = *((_DWORD *)this + 6);
      v9 = *((_DWORD *)this + 2);
      if ( v9 == v8 )
      {
        v10 = (int *)a4;
        (*(void (__thiscall **)(_DWORD, _DWORD, int, struct Error *))(**((_DWORD **)this + 1) + 16))(
          a1: *((_DWORD *)this + 1),
          a2: *((_DWORD *)this + 5),
          a3: v8,
          a4);
        if ( a4->severity > E_INFO )
          return;
        *((_DWORD *)this + 2) = 0;
      }
      else
      {
        if ( v9 != 0 )
          goto LABEL_21;
        v10 = (int *)a4;
      }
      v8 = *((_DWORD *)this + 6);
      if ( v4 >= v8 )
      {
        (*(void (__thiscall **)(_DWORD, unsigned __int8 *, int, int *))(**((_DWORD **)this + 1) + 16))(
          a1: *((_DWORD *)this + 1),
          a2: v5,
          a3: v8,
          a4: v10);
        if ( *v10 > 1 )
          return;
        v11 = *((_DWORD *)this + 6);
        v5 += v11;
        v4 -= v11;
        goto LABEL_24;
      }
LABEL_21:
      v12 = *((_DWORD *)this + 2);
      v13 = v8 - v12;
      if ( v8 - v12 > v4 )
        v13 = v4;
      memcpy(dst: (unsigned __int8 *)(v12 + *((_DWORD *)this + 5)), src: v5, count: v13);
      *((_DWORD *)this + 2) += v13;
      v5 += v13;
      v4 -= v13;
LABEL_24:
      if ( v4 == 0 )
        return;
    }
  }
  *v7 = src;
  *(_DWORD *)(*((_DWORD *)this + 10) + 4) = a3;
  while ( *(_DWORD *)(*((_DWORD *)this + 10) + 4) != 0 )
  {
    if ( a4->severity > E_INFO )
      break;
    if ( *(_DWORD *)(*((_DWORD *)this + 10) + 16) == 0 )
    {
      (*(void (__thiscall **)(_DWORD, _DWORD, _DWORD, struct Error *))(**((_DWORD **)this + 1) + 16))(
        a1: *((_DWORD *)this + 1),
        a2: *((_DWORD *)this + 5),
        a3: *((_DWORD *)this + 6),
        a4);
      *(_DWORD *)(*((_DWORD *)this + 10) + 12) = *((_DWORD *)this + 5);
      *(_DWORD *)(*((_DWORD *)this + 10) + 16) = *((_DWORD *)this + 6);
    }
    if ( PZ_deflate(a1: *((_DWORD *)this + 10), a2: 0) != 0 )
      Error::Set(this: a4, a2: &MsgSupp::Deflate);
  }
  ++*((_DWORD *)this + 2);
}

//------------------------------------------------------------------------------
// Address: 0x1000F5E0
// Name: public: NetBuffer::NetBuffer(class NetTransport __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
NetBuffer *__thiscall NetBuffer::NetBuffer(NetBuffer *this, struct NetTransport *a2)
{
  int v3; // eax
  unsigned int v5; // [esp-8h] [ebp-Ch]
  unsigned int v6; // [esp-4h] [ebp-8h]

  *(_DWORD *)this = &NetBuffer::`vftable';
  v6 = nSize;
  *((_DWORD *)this + 6) = nSize;
  *((_DWORD *)this + 5) = operator new(nSize: v6);
  v5 = nSize;
  *((_DWORD *)this + 8) = nSize;
  *((_DWORD *)this + 7) = operator new(nSize: v5);
  v3 = *((_DWORD *)this + 7);
  *((_DWORD *)this + 3) = v3;
  *((_DWORD *)this + 4) = v3;
  *((_DWORD *)this + 1) = a2;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 9) = 0;
  *((_DWORD *)this + 10) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000F630
// Name: public: virtual int NetBuffer::Receive(char __near *,int,class Error __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall NetBuffer::Receive(NetBuffer *this, char *dst, int a3, struct Error *a4)
{
  return NetBuffer::Receive(this, dst, a3, a4, a5: a4);
}

//------------------------------------------------------------------------------
// Address: 0x1000F650
// Name: public: RpcDispatcher::RpcDispatcher(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
RpcDispatcher *__thiscall RpcDispatcher::RpcDispatcher(RpcDispatcher *this)
{
  StrPtrArray *v2; // eax

  v2 = (StrPtrArray *)operator new(nSize: 0xCu);
  if ( v2 != nullptr )
    *(_DWORD *)this = StrPtrArray::StrPtrArray(this: v2);
  else
    *(_DWORD *)this = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000F680
// Name: public: void RpcDispatcher::Add(struct RpcDispatch const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall RpcDispatcher::Add(VarArray **this, const struct RpcDispatch *a2)
{
  *VarArray::New(this: *this) = a2;
}

//------------------------------------------------------------------------------
// Address: 0x100116B0
// Name: public: virtual int ClientMerge2::IsAcceptable(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall ClientMerge2::IsAcceptable(ClientMerge2 *this)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100116C0
// Name: public: virtual NetStdioEndPoint::~NetStdioEndPoint(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall NetStdioEndPoint::~NetStdioEndPoint(void **this)
{
  *this = &NetStdioEndPoint::`vftable';
  if ( *(this + 8) != StrBuf::nullStrBuf )
    free(pMem: *(this + 8));
  NetTcpEndPoint::~NetTcpEndPoint((NetTcpEndPoint *)this);
}

//------------------------------------------------------------------------------
// Address: 0x100116F0
// Name: public: virtual void NetStdioEndPoint::Listen(class Error __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall NetStdioEndPoint::Listen(NetStdioEndPoint *this, struct Error *a2)
{
  signal(signum: 2, sigact: (void (__cdecl *)(int))1);
}

//------------------------------------------------------------------------------
// Address: 0x10011700
// Name: public: virtual int NetStdioEndPoint::CheaterCheck(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall NetStdioEndPoint::CheaterCheck(NetStdioEndPoint *this, const char *a2)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10011710
// Name: public: virtual class NetTransport __near * NetStdioEndPoint::Accept(class Error __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct NetTransport *__thiscall NetStdioEndPoint::Accept(NetStdioEndPoint *this, struct Error *a2)
{
  NetTcpTransport *v2; // eax
  NetTcpTransport *v3; // esi

  setmode(fh: 0, mode: 0x8000);
  setmode(fh: 1, mode: 0x8000);
  v2 = (NetTcpTransport *)operator new(nSize: 0x2Cu);
  v3 = v2;
  if ( v2 == nullptr )
    return nullptr;
  NetTcpTransport::NetTcpTransport(this: v2, a2: 1);
  *(_DWORD *)v3 = &NetStdioTransport::`vftable';
  *((_DWORD *)v3 + 10) = 0;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10011760
// Name: public: virtual void NetStdioTransport::Close(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall NetStdioTransport::Close(NetStdioTransport *this)
{
  int v2; // eax

  if ( *((int *)this + 10) >= 0 )
    _close(fh: *((_DWORD *)this + 10));
  v2 = *((_DWORD *)this + 1);
  if ( v2 != *((_DWORD *)this + 10) && v2 >= 0 )
    _close(fh: *((_DWORD *)this + 1));
  *((_DWORD *)this + 1) = -1;
  *((_DWORD *)this + 10) = -1;
}

//------------------------------------------------------------------------------
// Address: 0x100117A0
// Name: public: virtual void NetStdioTransport::Send(char const __near *,int,class Error __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall NetStdioTransport::Send(NetStdioTransport *this, const char *buf, unsigned int cnt, struct Error *a4)
{
  if ( dword_1004F2F0 >= 4 )
    printf(format: "NetStdioTransport send %d bytes\n", cnt);
  if ( _write(fh: *((_DWORD *)this + 1), buf, cnt) != cnt )
  {
    Error::Net(this: a4, a2: "write", a3: "socket");
    Error::Set(this: a4, a2: &MsgRpc::TcpSend);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011800
// Name: public: virtual int NetStdioTransport::Receive(char __near *,int,class Error __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall NetStdioTransport::Receive(NetStdioTransport *this, char *buf, unsigned int cnt, struct Error *a4)
{
  int v4; // esi

  v4 = read(fh: *((_DWORD *)this + 10), buf, cnt);
  if ( v4 < 0 )
  {
    Error::Net(this: a4, a2: "read", a3: "socket");
    Error::Set(this: a4, a2: &MsgRpc::TcpRecv);
  }
  if ( dword_1004F2F0 >= 4 )
    printf(format: "NetStdioTransport recv %d bytes\n", v4);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10011860
// Name: public: virtual NetStdioTransport::~NetStdioTransport(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall NetStdioTransport::~NetStdioTransport(NetStdioTransport *this)
{
  int v2; // eax
  int v3; // eax

  v2 = *((_DWORD *)this + 10);
  *(_DWORD *)this = &NetStdioTransport::`vftable';
  if ( v2 >= 0 )
    _close(fh: v2);
  v3 = *((_DWORD *)this + 1);
  if ( v3 != *((_DWORD *)this + 10) && v3 >= 0 )
    _close(fh: *((_DWORD *)this + 1));
  *((_DWORD *)this + 1) = -1;
  *((_DWORD *)this + 10) = -1;
  *(_DWORD *)this = &NetTcpTransport::`vftable';
  NetTcpTransport::Close(this);
  if ( *((char **)this + 6) != StrBuf::nullStrBuf )
    free(pMem: *((void **)this + 6));
  if ( *((char **)this + 3) != StrBuf::nullStrBuf )
    free(pMem: *((void **)this + 3));
  NetTransport::~NetTransport(this);
}

//------------------------------------------------------------------------------
// Address: 0x100119F0
// Name: public: static int StrPtr::CCompare(char const __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
static int __cdecl StrPtr::CCompare(const char *a1, const char *a2)
{
  const char *v2; // ecx
  char v3; // al
  unsigned __int8 i; // al
  int v6; // esi
  int v7; // eax
  unsigned __int8 v8; // cl
  int v9; // eax
  unsigned __int8 v10; // dl

  v2 = a1;
  v3 = *a1;
  if ( *a1 != 0 )
  {
    while ( v3 == *a2 )
    {
      v3 = *++v2;
      ++a2;
      if ( v3 == 0 )
        goto LABEL_16;
    }
  }
  for ( i = *v2; i != 0; ++a2 )
  {
    if ( i < 0x41u || i > 0x5Au )
      v6 = i;
    else
      v6 = i + 32;
    LOBYTE(v7) = *a2;
    if ( *a2 < 0x41u || (unsigned __int8)v7 > 0x5Au )
      v7 = (unsigned __int8)v7;
    else
      v7 = (unsigned __int8)v7 + 32;
    if ( v6 != v7 )
      break;
    i = *++v2;
  }
LABEL_16:
  v8 = *v2;
  if ( v8 < 0x41u || v8 > 0x5Au )
    v9 = v8;
  else
    v9 = v8 + 32;
  v10 = *a2;
  if ( v10 < 0x41u || v10 > 0x5Au )
    return v9 - v10;
  else
    return v9 - (v10 + 32);
}

//------------------------------------------------------------------------------
// Address: 0x10011A90
// Name: public: static int StrPtr::SCompare(char const __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
static int __cdecl StrPtr::SCompare(const char *a1, const char *a2)
{
  const char *v2; // edx
  char i; // al
  unsigned __int8 v5; // cl
  int result; // eax
  int v7; // edi
  int v8; // ecx
  unsigned __int8 v9; // dl
  int v10; // ecx
  int v11; // edx
  int v12; // ecx

  v2 = a1;
  for ( i = *a1; i != 0; ++a2 )
  {
    if ( i != *a2 )
      break;
    i = *++v2;
  }
  v5 = *v2;
  result = *(unsigned __int8 *)v2 - *(unsigned __int8 *)a2;
  if ( StrPtr::caseUse != ST_UNIX )
  {
    for ( ; v5 != 0; ++a2 )
    {
      if ( v5 < 0x41u || v5 > 0x5Au )
        v7 = v5;
      else
        v7 = v5 + 32;
      LOBYTE(v8) = *a2;
      if ( *a2 < 0x41u || (unsigned __int8)v8 > 0x5Au )
        v8 = (unsigned __int8)v8;
      else
        v8 = (unsigned __int8)v8 + 32;
      if ( v7 != v8 )
        break;
      v5 = *++v2;
    }
    v9 = *v2;
    if ( v9 < 0x41u || v9 > 0x5Au )
      v10 = v9;
    else
      v10 = v9 + 32;
    LOBYTE(v11) = *a2;
    if ( *a2 < 0x41u || (unsigned __int8)v11 > 0x5Au )
      v11 = (unsigned __int8)v11;
    else
      v11 = (unsigned __int8)v11 + 32;
    v12 = v10 - v11;
    if ( v12 != 0 || StrPtr::caseUse == ST_WINDOWS )
      return v12;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10011B50
// Name: public: static char __near * StrPtr::Itoa64(__int64,char __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
static char *__cdecl StrPtr::Itoa64(__int64 a1, char *a2)
{
  unsigned int v2; // eax
  int v3; // ecx
  char *v4; // esi
  int v6; // edi
  signed __int64 v7; // [esp-14h] [ebp-1Ch]

  v2 = HIDWORD(a1);
  v3 = a1;
  if ( a1 < 0 )
  {
    v3 = -(int)a1;
    v6 = 1;
    v2 = (unsigned __int64)-a1 >> 32;
  }
  else
  {
    v6 = 0;
  }
  v4 = a2 - 1;
  *(a2 - 1) = 0;
  do
  {
    v7 = __PAIR64__(v2, v3);
    *--v4 = __SPAIR64__(v2, v3) % 10 + 48;
    v3 = __SPAIR64__(v2, v3) / 10;
    v2 = (unsigned __int64)(v7 / 10) >> 32;
  }
  while ( v7 / 10 != 0 );
  if ( v6 != 0 )
    *--v4 = 45;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10011BC0
// Name: private: void StrBuf::Grow(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall StrBuf::Grow(StrBuf *this, unsigned int count)
{
  int length; // eax
  unsigned __int8 *buffer; // edi
  bool v5; // zf
  char *v6; // eax
  int v7; // [esp-4h] [ebp-Ch]

  length = this->length;
  buffer = (unsigned __int8 *)this->buffer;
  v5 = this->buffer == StrBuf::nullStrBuf;
  this->size = length;
  if ( v5 )
  {
    if ( length < 4096 )
      this->size = length + 1;
    this->buffer = (char *)operator new(nSize: this->size);
  }
  else
  {
    v7 = (3 * length + 90) / 2;
    this->size = v7;
    v6 = (char *)operator new(nSize: v7);
    this->buffer = v6;
    memcpy(dst: (unsigned __int8 *)v6, src: buffer, count);
    free(pMem: buffer);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011C30
// Name: public: void StrBuf::Append(char const __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall StrBuf::Append(StrBuf *this, char *src, unsigned int count)
{
  unsigned int length; // ebx
  int v5; // eax
  bool v6; // cc
  unsigned __int8 *v7; // edi

  length = this->length;
  v5 = length + count + 1;
  v6 = v5 <= this->size;
  this->length = v5;
  if ( !v6 )
    StrBuf::Grow(this, count: length);
  v7 = (unsigned __int8 *)&this->buffer[length];
  memcpy(dst: v7, (unsigned __int8 *)src, count);
  v7[count] = 0;
  --this->length;
}

//------------------------------------------------------------------------------
// Address: 0x10011C80
// Name: public: void StrBuf::Append(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall StrBuf::Append(StrBuf *this, char *src)
{
  unsigned int v3; // ebx
  unsigned int length; // edi
  bool v5; // cc

  v3 = strlen(src) + 1;
  length = this->length;
  v5 = (int)(length + v3) <= this->size;
  this->length = length + v3;
  if ( !v5 )
    StrBuf::Grow(this, count: length);
  memcpy(dst: (unsigned __int8 *)&this->buffer[length], (unsigned __int8 *)src, count: v3);
  --this->length;
}

//------------------------------------------------------------------------------
// Address: 0x10011CD0
// Name: public: void StrBuf::Append(class StrPtr const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall StrBuf::Append(StrBuf *this, const struct StrPtr *a2)
{
  unsigned int length; // ebp
  int v4; // eax
  bool v5; // cc
  unsigned __int8 *v6; // edi

  length = this->length;
  v4 = a2->length + length + 1;
  v5 = v4 <= this->size;
  this->length = v4;
  if ( !v5 )
    StrBuf::Grow(this, count: length);
  v6 = (unsigned __int8 *)&this->buffer[length];
  memcpy(dst: v6, src: (unsigned __int8 *)a2->buffer, count: a2->length);
  v6[a2->length] = 0;
  --this->length;
}

//------------------------------------------------------------------------------
// Address: 0x10011D20
// Name: public: class StrBuf __near & StrBuf::operator<<(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
StrBuf *__thiscall StrBuf::operator<<(StrBuf *this, int a2)
{
  unsigned __int8 *v3; // eax
  unsigned int length; // ebx
  _BYTE *v5; // ecx
  _BYTE *v6; // edx
  bool v7; // cc
  unsigned __int8 *v8; // edi
  unsigned __int8 *v10; // [esp+Ch] [ebp-20h]
  _BYTE *v11; // [esp+10h] [ebp-1Ch]
  char v12; // [esp+2Bh] [ebp-1h] BYREF
  _UNKNOWN *retaddr; // [esp+2Ch] [ebp+0h] BYREF

  v3 = (unsigned __int8 *)StrPtr::Itoa64(a1: a2, a2: (char *)&retaddr);
  length = this->length;
  v5 = (_BYTE *)(&v12 - (char *)v3);
  v6 = (_BYTE *)(length + &v12 - (char *)v3 + 1);
  v7 = (int)v6 <= this->size;
  v10 = v3;
  v11 = (_BYTE *)(&v12 - (char *)v3);
  this->length = (int)v6;
  if ( !v7 )
  {
    StrBuf::Grow(this, count: length);
    v5 = v11;
    v3 = v10;
  }
  v8 = (unsigned __int8 *)&this->buffer[length];
  memcpy(dst: v8, src: v3, count: (unsigned int)v5);
  v11[(_DWORD)v8] = 0;
  --this->length;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10011D90
// Name: public: virtual StrDict::~StrDict(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall StrDict::~StrDict(StrDict *this)
{
  this->__vftable = (StrDict_vtbl *)&StrDict::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10011DA0
// Name: protected: virtual int StrDict::VGetVarX(int,class StrRef __near &,class StrRef __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall StrDict::VGetVarX(StrDict *this, int a2, struct StrRef *a3, struct StrRef *a4)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10011DB0
// Name: protected: virtual void StrDict::VSetError(class StrPtr const __near &,class Error __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall StrDict::VSetError(StrDict *this, struct StrPtr *a2, struct Error *a3)
{
  Error::Set(this: a3, a2: &MsgSupp::NoParm);
  Error::operator<<(a1: a2);
}

//------------------------------------------------------------------------------
// Address: 0x10011DD0
// Name: public: StrVarName::StrVarName(class StrPtr const __near &,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
StrVarName *__thiscall StrVarName::StrVarName(StrVarName *this, const struct StrPtr *a2, int a3)
{
  char *varName; // esi
  unsigned __int8 *v5; // ebp
  char v7; // [esp+2Fh] [ebp-1h] BYREF
  _UNKNOWN *retaddr; // [esp+30h] [ebp+0h] BYREF

  varName = this->varName;
  memcpy(dst: (unsigned __int8 *)this->varName, src: (unsigned __int8 *)a2->buffer, count: a2->length + 1);
  v5 = (unsigned __int8 *)StrPtr::Itoa64(a1: a3, a2: (char *)&retaddr);
  memcpy(dst: (unsigned __int8 *)&varName[strlen(this->varName)], src: v5, count: &v7 - (char *)v5 + 1);
  this->length = strlen(this->varName);
  this->buffer = varName;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10011E60
// Name: public: void StrDict::SetVar(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall StrDict::SetVar(StrDict *this, const char *a2)
{
  void (__thiscall *VSetVar)(StrDict *, const StrPtr *, const StrPtr *); // eax
  _DWORD v3[2]; // [esp+8h] [ebp-8h] BYREF

  v3[1] = strlen(a2);
  VSetVar = this->VSetVar;
  v3[0] = a2;
  VSetVar(this, a2: (const StrPtr *)v3, a3: &StrRef::null);
}

//------------------------------------------------------------------------------
// Address: 0x10011EA0
// Name: public: void StrDict::SetVar(char const __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall StrDict::SetVar(StrDict *this, const char *a2, int a3)
{
  _DWORD v4[2]; // [esp+8h] [ebp-28h] BYREF
  _DWORD v5[7]; // [esp+10h] [ebp-20h] BYREF
  char v6; // [esp+2Fh] [ebp-1h] BYREF
  _UNKNOWN *retaddr; // [esp+30h] [ebp+0h] BYREF

  v5[0] = StrPtr::Itoa64(a1: a3, a2: (char *)&retaddr);
  v5[1] = &v6 - v5[0];
  v4[1] = strlen(a2);
  v4[0] = a2;
  this->VSetVar(this, a2: (const StrPtr *)v4, a3: (const StrPtr *)v5);
}

//------------------------------------------------------------------------------
// Address: 0x10011F00
// Name: public: void StrDict::SetVar(char const __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall StrDict::SetVar(StrDict *this, const char *a2, const char *a3)
{
  void (__thiscall *VSetVar)(StrDict *, const StrPtr *, const StrPtr *); // eax
  _DWORD v4[2]; // [esp+4h] [ebp-10h] BYREF
  _DWORD v5[2]; // [esp+Ch] [ebp-8h] BYREF

  if ( a3 != nullptr )
  {
    v4[1] = strlen(a3);
    v4[0] = a3;
    v5[1] = strlen(a2);
    VSetVar = this->VSetVar;
    v5[0] = a2;
    VSetVar(this, a2: (const StrPtr *)v5, a3: (const StrPtr *)v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011F60
// Name: public: void StrDict::RemoveVar(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall StrDict::RemoveVar(StrDict *this, const char *a2)
{
  void (__thiscall *VRemoveVar)(StrDict *, const StrPtr *); // eax
  _DWORD v3[2]; // [esp+8h] [ebp-8h] BYREF

  v3[1] = strlen(a2);
  VRemoveVar = this->VRemoveVar;
  v3[0] = a2;
  VRemoveVar(this, a2: (const StrPtr *)v3);
}

//------------------------------------------------------------------------------
// Address: 0x10011FA0
// Name: public: void StrDict::SetVar(char const __near *,class StrPtr const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall StrDict::SetVar(StrDict *this, const char *a2, const struct StrPtr *a3)
{
  void (__thiscall *VSetVar)(StrDict *, const StrPtr *, const StrPtr *); // eax
  _DWORD v4[2]; // [esp+4h] [ebp-8h] BYREF

  if ( a3 != nullptr )
  {
    v4[1] = strlen(a2);
    VSetVar = this->VSetVar;
    v4[0] = a2;
    VSetVar(this, a2: (const StrPtr *)v4, a3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011FE0
// Name: public: void StrDict::SetVar(char const __near *,class StrPtr const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall StrDict::SetVar(StrDict *this, const char *a2, const struct StrPtr *a3)
{
  void (__thiscall *VSetVar)(StrDict *, const StrPtr *, const StrPtr *); // eax
  _DWORD v4[2]; // [esp+8h] [ebp-8h] BYREF

  v4[1] = strlen(a2);
  VSetVar = this->VSetVar;
  v4[0] = a2;
  VSetVar(this, a2: (const StrPtr *)v4, a3);
}

//------------------------------------------------------------------------------
// Address: 0x10012020
// Name: public: void StrDict::SetArgv(int,char __near * const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall StrDict::SetArgv(StrDict *this, int a2, char *const *a3)
{
  int i; // esi
  const char *v5; // ecx
  unsigned int v6; // kr00_4
  void (__thiscall *VSetVar)(StrDict *, const StrPtr *, const StrPtr *); // edx
  _DWORD v8[2]; // [esp+Ch] [ebp-8h] BYREF

  for ( i = 0; i < a2; ++i )
  {
    v5 = a3[i];
    v6 = strlen(v5);
    VSetVar = this->VSetVar;
    v8[1] = v6;
    v8[0] = v5;
    VSetVar(this, a2: &StrRef::null, a3: (const StrPtr *)v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012080
// Name: public: class StrPtr __near * StrDict::GetVar(class StrPtr const __near &,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct StrPtr *__thiscall StrDict::GetVar(StrDict *this, const struct StrPtr *a2, int a3)
{
  StrDict_vtbl *v4; // edi
  StrVarName *v5; // eax
  StrVarName v7; // [esp+8h] [ebp-48h] BYREF

  v4 = this->__vftable;
  v5 = StrVarName::StrVarName(this: &v7, a2, a3);
  return v4->VGetVar(this, a2: v5);
}

//------------------------------------------------------------------------------
// Address: 0x10012790
// Name: public: NoEcho::~NoEcho(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall NoEcho::~NoEcho(NoEcho *this)
{
  _iobuf *v2; // eax
  int v3; // eax
  void *osfhandle; // eax
  _iobuf *v5; // eax
  DWORD v6; // [esp-4h] [ebp-8h]

  v6 = *(_DWORD *)(*(_DWORD *)this + 4);
  v2 = __iob_func();
  v3 = fileno(stream: v2);
  osfhandle = (void *)_get_osfhandle(fh: v3);
  SetConsoleMode(hConsoleHandle: osfhandle, dwMode: v6);
  v5 = __iob_func();
  fputc(ch: 10, str: v5 + 1);
  Signaler::DeleteOnIntr(this: (Signaler *)&signaler, a2: this);
  free(pMem: *(void **)this);
}

//------------------------------------------------------------------------------
// Address: 0x100127E0
// Name: void EchoCleanup(class NoEcho __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl EchoCleanup(struct NoEcho *pMem)
{
  if ( pMem != nullptr )
  {
    NoEcho::~NoEcho(this: pMem);
    free(pMem);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012800
// Name: public: NoEcho::NoEcho(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
NoEcho *__thiscall NoEcho::NoEcho(NoEcho *this)
{
  _iobuf *v2; // eax
  int v3; // eax
  void *osfhandle; // eax
  _iobuf *v5; // eax
  int v6; // eax
  void *v7; // eax
  unsigned int *v9; // [esp-4h] [ebp-8h]
  DWORD v10; // [esp-4h] [ebp-8h]

  v9 = (unsigned int *)operator new(nSize: 8u);
  *(_DWORD *)this = v9;
  v2 = __iob_func();
  v3 = fileno(stream: v2);
  osfhandle = (void *)_get_osfhandle(fh: v3);
  GetConsoleMode(hConsoleHandle: osfhandle, lpMode: v9);
  *(_DWORD *)(*(_DWORD *)this + 4) = **(_DWORD **)this;
  **(_DWORD **)this &= ~4u;
  v10 = **(_DWORD **)this;
  v5 = __iob_func();
  v6 = fileno(stream: v5);
  v7 = (void *)_get_osfhandle(fh: v6);
  SetConsoleMode(hConsoleHandle: v7, dwMode: v10);
  Signaler::OnIntr(this: (Signaler *)&signaler, a2: (void (__cdecl *)(void *))EchoCleanup, a3: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10012870
// Name: struct _PROCESS_INFORMATION __near * RunProcess(class RunArgs __near &,enum RunProcessMode,void __near *,void __near *,class Error __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_PROCESS_INFORMATION *__cdecl RunProcess(LPSTR *a1, int a2, void *a3, void *a4, Error *a5)
{
  _PROCESS_INFORMATION *v5; // esi
  BOOL v6; // edx
  DWORD v7; // ecx
  _STARTUPINFOA StartupInfo; // [esp+10h] [ebp-44h] BYREF

  v5 = (_PROCESS_INFORMATION *)operator new(nSize: 0x10u);
  v5->hProcess = nullptr;
  v5->hThread = nullptr;
  v5->dwProcessId = 0;
  v5->dwThreadId = 0;
  memset(dst: (unsigned __int8 *)&StartupInfo.lpReserved, value: 0, count: 0x40u);
  StartupInfo.cb = 68;
  StartupInfo.lpReserved = nullptr;
  StartupInfo.lpTitle = nullptr;
  StartupInfo.dwFlags = 257;
  StartupInfo.wShowWindow = 5;
  StartupInfo.hStdInput = a3;
  StartupInfo.hStdOutput = a4;
  StartupInfo.hStdError = GetStdHandle(nStdHandle: 0xFFFFFFF4);
  v6 = true;
  v7 = 32;
  switch ( a2 )
  {
    case 1:
      StartupInfo.wShowWindow = 0;
      break;
    case 2:
      v6 = false;
      StartupInfo.dwFlags &= ~0x100u;
      v7 = 48;
      StartupInfo.hStdError = nullptr;
      break;
    case 3:
      v7 = 40;
      break;
    default:
      break;
  }
  if ( CreateProcessA(
         lpApplicationName: nullptr,
         lpCommandLine: *a1,
         lpProcessAttributes: nullptr,
         lpThreadAttributes: nullptr,
         bInheritHandles: v6,
         dwCreationFlags: v7,
         lpEnvironment: nullptr,
         lpCurrentDirectory: nullptr,
         lpStartupInfo: &StartupInfo,
         lpProcessInformation: v5) )
  {
    return v5;
  }
  Error::Sys(this: a5, a2: "CreateProcess", a3: *a1);
  free(pMem: v5);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10012960
// Name: public: RunCommand::RunCommand(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
RunCommand *__thiscall RunCommand::RunCommand(RunCommand *this)
{
  *(_DWORD *)this = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10012970
// Name: public: RunCommand::~RunCommand(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall RunCommand::~RunCommand(HANDLE **this)
{
  HANDLE *v1; // esi

  v1 = *this;
  if ( *this != nullptr )
  {
    CloseHandle(hObject: v1[1]);
    CloseHandle(hObject: *v1);
    free(pMem: v1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100129A0
// Name: public: void RunCommand::RunChild(class RunArgs __near &,int,int __near * const,class Error __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall RunCommand::RunChild(RunCommand *this, LPSTR *a2, int a3, int *const a4, struct Error *a5)
{
  int v6; // ecx
  void *osfhandle; // eax
  void *v8; // eax
  void *v9; // eax
  _PROCESS_INFORMATION *v10; // eax
  int v11; // [esp-18h] [ebp-30h]
  int v12; // [esp-Ch] [ebp-24h]
  void *v13; // [esp-8h] [ebp-20h]
  int v14; // [esp+8h] [ebp-10h] BYREF
  int v15; // [esp+Ch] [ebp-Ch]
  int phandles; // [esp+10h] [ebp-8h] BYREF
  int fh; // [esp+14h] [ebp-4h]

  _pipe(&phandles, psize: 0x2000u, textmode: 0x8000);
  _pipe(phandles: &v14, psize: 0x2000u, textmode: 0x8000);
  v6 = fh;
  v12 = fh;
  *a4 = v14;
  a4[1] = v6;
  osfhandle = (void *)_get_osfhandle(fh: v12);
  SetHandleInformation(hObject: osfhandle, dwMask: 1u, dwFlags: 0);
  v8 = (void *)_get_osfhandle(fh: v14);
  SetHandleInformation(hObject: v8, dwMask: 1u, dwFlags: 0);
  v13 = (void *)_get_osfhandle(fh: v15);
  v9 = (void *)_get_osfhandle(fh: phandles);
  v10 = RunProcess(a1: a2, a2: 2 * (a3 != 2) + 1, a3: v9, a4: v13, a5);
  v11 = phandles;
  *(_DWORD *)this = v10;
  _close(fh: v11);
  _close(fh: v15);
  if ( a5->severity > E_INFO )
  {
    _close(fh: v14);
    _close(fh);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012A90
// Name: public: int RunCommand::WaitChild(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall RunCommand::WaitChild(HANDLE **this)
{
  HANDLE *v1; // esi
  unsigned int ExitCode; // [esp+4h] [ebp-4h] BYREF

  v1 = *this;
  if ( *this == nullptr )
    return 0;
  ExitCode = -1;
  if ( WaitForMultipleObjects(nCount: 1u, lpHandles: v1, bWaitAll: true, dwMilliseconds: 0xFFFFFFFF) != -1 )
    GetExitCodeProcess(hProcess: *v1, lpExitCode: &ExitCode);
  return ExitCode;
}

//------------------------------------------------------------------------------
// Address: 0x10012AD0
// Name: public: int RunCommand::Run(class RunArgs __near &,class Error __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
Run *__thiscall RunCommand::Run(Run *this, LPSTR *a2, unsigned int ExitCode)
{
  int *v3; // ebx
  HANDLE v5; // eax
  _PROCESS_INFORMATION *v6; // eax
  HANDLE *p_hProcess; // esi
  HANDLE StdHandle; // [esp-8h] [ebp-14h]
  Error *v10; // [esp-4h] [ebp-10h]

  v3 = (int *)ExitCode;
  v10 = (Error *)ExitCode;
  StdHandle = GetStdHandle(nStdHandle: 0xFFFFFFF5);
  v5 = GetStdHandle(nStdHandle: 0xFFFFFFF6);
  v6 = RunProcess(a1: a2, a2: 0, a3: v5, a4: StdHandle, a5: v10);
  p_hProcess = &v6->hProcess;
  *(_DWORD *)this = v6;
  if ( *v3 > 1 )
    return (Run *)-1;
  if ( v6 == nullptr )
    return nullptr;
  ExitCode = -1;
  if ( WaitForMultipleObjects(nCount: 1u, lpHandles: &v6->hProcess, bWaitAll: true, dwMilliseconds: 0xFFFFFFFF) != -1 )
    GetExitCodeProcess(hProcess: *p_hProcess, lpExitCode: &ExitCode);
  return (Run *)ExitCode;
}

//------------------------------------------------------------------------------
// Address: 0x10012B50
// Name: public: int RunCommand::RunOut(class RunArgs __near &,class StrPtr const __near &,class StrBuf __near &,class Error __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall RunCommand::RunOut(
        RunCommand *this,
        LPSTR *a2,
        const struct StrPtr *a3,
        StrBuf *a4,
        unsigned int ExitCode)
{
  RunCommand *v5; // eax
  RunCommand *v6; // ebx
  struct Error *v7; // edi
  HANDLE *v8; // esi
  int v10; // esi
  HANDLE *v11; // esi
  int v12; // ebp
  unsigned int length; // edi
  bool v14; // cc
  int v15; // eax
  HANDLE *v16; // edi
  HANDLE *v17; // edi
  unsigned int v18; // ebx
  int v19; // eax
  char *buffer; // ecx
  int v21; // eax
  unsigned int v22; // edi
  int v23; // [esp+10h] [ebp-8h] BYREF
  int fh; // [esp+14h] [ebp-4h]

  v5 = (RunCommand *)operator new(nSize: 4u);
  if ( v5 != nullptr )
  {
    *(_DWORD *)v5 = 0;
    v6 = v5;
  }
  else
  {
    v6 = nullptr;
  }
  v7 = (struct Error *)ExitCode;
  RunCommand::RunChild(this: v6, a2, a3: 2, a4: &v23, a5: (struct Error *)ExitCode);
  if ( v7->severity > E_INFO )
  {
    if ( v6 != nullptr )
    {
      v8 = *(HANDLE **)v6;
      if ( *(_DWORD *)v6 != 0 )
      {
        CloseHandle(hObject: v8[1]);
        CloseHandle(hObject: *v8);
        free(pMem: v8);
      }
      free(pMem: v6);
    }
    return -1;
  }
  v10 = fh;
  if ( a3->length != 0 && _write(fh, buf: a3->buffer, cnt: a3->length) < 0 )
  {
    Error::Sys(this: v7, a2: "write", a3: *a2);
    _close(fh: v10);
    _close(fh: v23);
    RunCommand::WaitChild(this: (HANDLE **)v6);
    if ( v6 == nullptr )
      return -1;
    v11 = *(HANDLE **)v6;
    if ( *(_DWORD *)v6 != 0 )
    {
      CloseHandle(hObject: v11[1]);
      CloseHandle(hObject: *v11);
      free(pMem: v11);
    }
    free(pMem: v6);
    return -1;
  }
  else
  {
    _close(fh: v10);
    v12 = v23;
    a4->length = 0;
    do
    {
      length = a4->length;
      v14 = (int)(length + 1024) <= a4->size;
      a4->length = length + 1024;
      if ( !v14 )
        StrBuf::Grow(this: a4, count: length);
      v15 = read(fh: v12, buf: &a4->buffer[length], cnt: 0x400u);
      if ( v15 < 1024 )
        a4->length += v15 - 1024;
    }
    while ( v15 != 0 );
    _close(fh: v12);
    v16 = *(HANDLE **)v6;
    if ( *(_DWORD *)v6 != 0 )
    {
      ExitCode = -1;
      if ( WaitForMultipleObjects(nCount: 1u, lpHandles: v16, bWaitAll: true, dwMilliseconds: 0xFFFFFFFF) != -1 )
        GetExitCodeProcess(hProcess: *v16, lpExitCode: &ExitCode);
    }
    else
    {
      ExitCode = 0;
    }
    v17 = *(HANDLE **)v6;
    if ( *(_DWORD *)v6 != 0 )
    {
      CloseHandle(hObject: v17[1]);
      CloseHandle(hObject: *v17);
      free(pMem: v17);
    }
    free(pMem: v6);
    v18 = ExitCode;
    if ( ExitCode != 0 && a4->length == 0 )
      StrBuf::Append(this: a4, src: "no error message");
    v19 = a4->length;
    if ( v19 != 0 )
    {
      buffer = a4->buffer;
      if ( a4->buffer[v19 - 1] == 10 )
        a4->length = v19 - 1;
      v21 = a4->length;
      if ( buffer[v21 - 1] == 13 )
        a4->length = v21 - 1;
      v22 = a4->length;
      v14 = (int)(v22 + 1) <= a4->size;
      a4->length = v22 + 1;
      if ( !v14 )
        StrBuf::Grow(this: a4, count: v22);
      a4->buffer[v22] = 0;
      --a4->length;
    }
    return v18;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012D80
// Name: public: void RunArgs::AddArg(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall RunArgs::AddArg(StrBuf *this, char *a2)
{
  bool v3; // zf
  struct StrPtr v4; // [esp+8h] [ebp-8h] BYREF

  v3 = this->length == 0;
  v4.buffer = a2;
  v4.length = strlen(a2);
  if ( !v3 )
    StrBuf::Append(this, src: " ");
  StrBuf::Append(this, src: "\"");
  StrBuf::Append(this, a2: &v4);
  StrBuf::Append(this, src: "\"");
}

//------------------------------------------------------------------------------
// Address: 0x10012DF0
// Name: public: void RunArgs::AddCmd(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall RunArgs::AddCmd(StrBuf *this, char *string)
{
  char *v2; // ebx
  int v4; // eax
  int v5; // esi
  int v6; // eax
  int v7; // eax
  bool v8; // zf
  int v9; // eax
  struct StrPtr v10; // [esp+Ch] [ebp-8h] BYREF

  v2 = string;
  strchr((unsigned __int8 *)string, chr: 0x20u);
  v5 = v4;
  if ( v4 != 0 )
  {
    while ( 1 )
    {
      strchr(string: "-+/", chr: *(_BYTE *)(v5 + 1));
      if ( v6 != 0 )
        break;
      strchr(string: (unsigned __int8 *)(v5 + 1), chr: 0x20u);
      v5 = v7;
      if ( v7 == 0 )
        goto LABEL_8;
    }
    do
    {
      v8 = this->length == 0;
      v10.buffer = v2;
      v10.length = v5 - (_DWORD)v2;
      if ( !v8 )
        StrBuf::Append(this, src: " ");
      StrBuf::Append(this, src: "\"");
      StrBuf::Append(this, a2: &v10);
      StrBuf::Append(this, src: "\"");
      v2 = (char *)(v5 + 1);
      strchr(string: (unsigned __int8 *)(v5 + 1), chr: 0x20u);
      v5 = v9;
    }
    while ( v9 != 0 );
  }
LABEL_8:
  v8 = this->length == 0;
  v10.buffer = v2;
  v10.length = strlen(v2);
  if ( !v8 )
    StrBuf::Append(this, src: " ");
  StrBuf::Append(this, src: "\"");
  StrBuf::Append(this, a2: &v10);
  StrBuf::Append(this, src: "\"");
}

//------------------------------------------------------------------------------
// Address: 0x10012F00
// Name: public: virtual FileSys::~FileSys(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall FileSys::~FileSys(FileSys *this)
{
  char *buffer; // esi

  this->__vftable = (FileSys_vtbl *)&FileSys::`vftable';
  Signaler::DeleteOnIntr(this: (Signaler *)&signaler, a2: this);
  buffer = this->path.buffer;
  if ( buffer != StrBuf::nullStrBuf )
    free(pMem: buffer);
}

//------------------------------------------------------------------------------
// Address: 0x10012F30
// Name: public: virtual class StrPtr __near * FileSys::Path(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
StrBuf *__thiscall FileSys::Path(FileSys *this)
{
  return &this->path;
}

//------------------------------------------------------------------------------
// Address: 0x10012F40
// Name: public: static int FileSys::BufferSize(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
static unsigned int __cdecl FileSys::BufferSize()
{
  return dword_1004F76C;
}

//------------------------------------------------------------------------------
// Address: 0x10012F50
// Name: public: void FileSys::Cleanup(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall FileSys::Cleanup(FileSys *this)
{
  void (__thiscall *Close)(FileSys *, Error *); // edx
  Error v3; // [esp+8h] [ebp-Ch] BYREF

  Close = this->Close;
  v3.ep = nullptr;
  v3.severity = E_EMPTY;
  Close(this, a2: &v3);
  if ( this->isTemp != 0 )
    this->Unlink(this, a2: nullptr);
  Error::~Error(this: &v3);
}

//------------------------------------------------------------------------------
// Address: 0x10017D70
// Name: private: void Ticket::WriteTicketFile(class Error __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall Ticket::WriteTicketFile(Ticket *this, struct Error *a2)
{
  struct FileSys *v3; // esi
  void (__thiscall *MakeLocalTemp)(FileSys *, char *); // eax
  void (__thiscall *Open)(FileSys *, FileOpenMode, Error *); // eax
  char **v7; // eax
  struct Error *v8; // ecx
  char *v9; // edx
  int v10; // edi
  void (__thiscall *Close)(FileSys *, Error *); // edx
  const struct StrPtr *v12; // [esp+1Ch] [ebp-20h]
  StrBuf pMem; // [esp+30h] [ebp-Ch] BYREF
  struct Error *v14; // [esp+40h] [ebp+4h]

  v3 = FileSys::Create(a1: FST_TEXT);
  MakeLocalTemp = v3->MakeLocalTemp;
  v3->isTemp = 1;
  MakeLocalTemp(this: v3, a2: **((char ***)this + 2));
  Open = v3->Open;
  v3->perms = FPM_RW;
  Open(this: v3, a2: FOM_WRITE, a3: a2);
  if ( a2->severity <= E_INFO )
  {
    v7 = *(char ***)this;
    v8 = nullptr;
    pMem.size = 0;
    pMem.length = 0;
    pMem.buffer = StrBuf::nullStrBuf;
    v14 = nullptr;
    if ( (int)v7[1] > 0 )
    {
      do
      {
        v9 = v7[2];
        v10 = *(_DWORD *)&v9[4 * (_DWORD)v8];
        if ( *(_DWORD *)(v10 + 36) == 0 )
        {
          v12 = *(const struct StrPtr **)&v9[4 * (_DWORD)v8];
          pMem.length = 0;
          StrBuf::Append(this: &pMem, a2: v12);
          StrBuf::Append(this: &pMem, src: "=");
          StrBuf::Append(this: &pMem, a2: (const struct StrPtr *)(v10 + 12));
          StrBuf::Append(this: &pMem, src: ":");
          StrBuf::Append(this: &pMem, a2: (const struct StrPtr *)(v10 + 24));
          StrBuf::Append(this: &pMem, src: "\n");
          v3->Write(this: v3, a2: pMem.buffer, a3: pMem.length, a4: a2);
          if ( a2->severity > E_INFO )
            break;
          v8 = v14;
        }
        v7 = *(char ***)this;
        v8 = (struct Error *)((char *)v8 + 1);
        v14 = v8;
      }
      while ( (int)v8 < *(_DWORD *)(*(_DWORD *)this + 4) );
    }
    Close = v3->Close;
    v3->isTemp = 0;
    Close(this: v3, a2);
    v3->Rename(this: v3, a2: *((FileSys **)this + 1), a3: a2);
    (*(void (__thiscall **)(_DWORD, int, struct Error *))(**((_DWORD **)this + 1) + 56))(
      a1: *((_DWORD *)this + 1),
      a2: 2,
      a3: a2);
    ((void (__thiscall *)(struct FileSys *, int))v3->dtr_FileSys)(a1: v3, a2: 1);
    if ( pMem.buffer != StrBuf::nullStrBuf )
      free(pMem: pMem.buffer);
  }
  else
  {
    ((void (__thiscall *)(struct FileSys *, int))v3->dtr_FileSys)(a1: v3, a2: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10017ED0
// Name: public: TicketTable::~TicketTable(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall TicketTable::~TicketTable(TicketTable *this)
{
  int i; // edi
  void **v3; // esi

  for ( i = 0; i < *((_DWORD *)this + 1); ++i )
  {
    v3 = *(void ***)(*((_DWORD *)this + 2) + 4 * i);
    if ( v3 != nullptr )
    {
      if ( v3[6] != StrBuf::nullStrBuf )
        free(pMem: v3[6]);
      if ( v3[3] != StrBuf::nullStrBuf )
        free(pMem: v3[3]);
      if ( *v3 != StrBuf::nullStrBuf )
        free(pMem: *v3);
      free(pMem: v3);
    }
  }
  VarArray::~VarArray(this);
}

//------------------------------------------------------------------------------
// Address: 0x10017F50
// Name: public: void TicketTable::AddItem(class StrRef const __near &,class StrRef const __near &,class StrRef const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall TicketTable::AddItem(
        TicketTable *this,
        const struct StrRef *a2,
        const struct StrRef *a3,
        const struct StrRef *a4)
{
  StrBuf *v5; // eax
  StrBuf *v6; // esi

  v5 = (StrBuf *)operator new(nSize: 0x28u);
  if ( v5 != nullptr )
  {
    v5->size = 0;
    v5->length = 0;
    v5->buffer = StrBuf::nullStrBuf;
    v5[1].size = 0;
    v5[1].length = 0;
    v5[1].buffer = StrBuf::nullStrBuf;
    v5[2].size = 0;
    v5[2].length = 0;
    v5[2].buffer = StrBuf::nullStrBuf;
    v6 = v5;
  }
  else
  {
    v6 = nullptr;
  }
  v6->length = 0;
  StrBuf::Append(this: v6, a2);
  v6[1].length = 0;
  StrBuf::Append(this: v6 + 1, a2: a3);
  v6[2].length = 0;
  StrBuf::Append(this: v6 + 2, a2: a4);
  v6[3].buffer = nullptr;
  *VarArray::New(this) = v6;
}

//------------------------------------------------------------------------------
// Address: 0x10017FD0
// Name: public: struct TicketItem __near * TicketTable::GetItem(class StrRef const __near &,class StrRef const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const char **__thiscall TicketTable::GetItem(TicketTable *this, const struct StrRef *a2, const struct StrRef *a3)
{
  int v4; // edi
  const char **v5; // esi

  v4 = 0;
  if ( *((int *)this + 1) <= 0 )
    return nullptr;
  while ( 1 )
  {
    v5 = *(const char ***)(*((_DWORD *)this + 2) + 4 * v4);
    if ( StrPtr::CCompare(a1: *v5, a2: a2->buffer) == 0
      && (StrPtr::SCompare(a1: v5[3], a2: a3->buffer) == 0
       || StrPtr::SCompare(a1: v5[3], a2: "******") == 0
       || StrPtr::SCompare(a1: a3->buffer, a2: "******") == 0) )
    {
      break;
    }
    if ( ++v4 >= *((_DWORD *)this + 1) )
      return nullptr;
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10018070
// Name: private: void Ticket::ReadTicketFile(class Error __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall Ticket::ReadTicketFile(Ticket *this, struct Error *a2)
{
  struct Error *v3; // edi
  FileSys *v4; // ecx
  int v5; // eax
  int v6; // esi
  unsigned __int8 *v7; // esi
  int v8; // eax
  int v9; // edi
  struct StrRef v10; // [esp+8h] [ebp-3Ch] BYREF
  struct StrRef v11; // [esp+10h] [ebp-34h] BYREF
  struct StrRef v12; // [esp+18h] [ebp-2Ch] BYREF
  StrBuf pMem; // [esp+20h] [ebp-24h] BYREF
  StrBuf v14; // [esp+2Ch] [ebp-18h] BYREF
  StrBuf string; // [esp+38h] [ebp-Ch] BYREF

  if ( ((*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 1) + 36))(a1: *((_DWORD *)this + 1)) & 1) != 0 )
  {
    v3 = a2;
    (*(void (__thiscall **)(_DWORD, _DWORD, struct Error *))(**((_DWORD **)this + 1) + 20))(
      a1: *((_DWORD *)this + 1),
      a2: 0,
      a3: a2);
    if ( a2->severity <= E_INFO )
    {
      v4 = *((FileSys **)this + 1);
      string.size = 0;
      string.length = 0;
      string.buffer = StrBuf::nullStrBuf;
      v14.size = 0;
      v14.length = 0;
      v14.buffer = StrBuf::nullStrBuf;
      pMem.size = 0;
      pMem.length = 0;
      pMem.buffer = StrBuf::nullStrBuf;
      if ( FileSys::ReadLine(this: v4, a2: &string, a3: a2) != 0 )
      {
        do
        {
          strchr(string: (unsigned __int8 *)string.buffer, chr: 0x3Du);
          v6 = v5;
          if ( v5 != 0 )
          {
            v14.length = 0;
            StrBuf::Append(this: &v14, src: string.buffer, count: v5 - (unsigned int)string.buffer);
            v7 = (unsigned __int8 *)(v6 + 1);
            strchr(string: v7, chr: 0x3Au);
            v9 = v8;
            if ( v8 != 0 )
            {
              pMem.length = 0;
              StrBuf::Append(this: &pMem, src: (char *)v7, count: v8 - (_DWORD)v7);
              v10.buffer = (char *)(v9 + 1);
              v10.length = strlen((const char *)(v9 + 1));
              v11 = (struct StrRef)pMem.StrPtr;
              v12 = (struct StrRef)v14.StrPtr;
              TicketTable::AddItem(this: *(TicketTable **)this, a2: &v12, a3: &v11, a4: &v10);
            }
            v3 = a2;
          }
        }
        while ( FileSys::ReadLine(this: *((FileSys **)this + 1), a2: &string, a3: v3) != 0 );
      }
      (*(void (__thiscall **)(_DWORD, struct Error *))(**((_DWORD **)this + 1) + 32))(a1: *((_DWORD *)this + 1), a2: v3);
      if ( pMem.buffer != StrBuf::nullStrBuf )
        free(pMem: pMem.buffer);
      if ( v14.buffer != StrBuf::nullStrBuf )
        free(pMem: v14.buffer);
      if ( string.buffer != StrBuf::nullStrBuf )
        free(pMem: string.buffer);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018200
// Name: public: void TicketTable::PutItem(class StrRef const __near &,class StrRef const __near &,class StrRef const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall TicketTable::PutItem(
        TicketTable *this,
        const struct StrRef *a2,
        const struct StrRef *a3,
        const struct StrRef *a4)
{
  StrBuf *Item; // esi

  Item = (StrBuf *)TicketTable::GetItem(this, a2, a3);
  if ( Item != nullptr )
  {
    Item[2].length = 0;
    StrBuf::Append(this: Item + 2, a2: a4);
    Item[1].length = 0;
    StrBuf::Append(this: Item + 1, a2: a3);
  }
  else
  {
    TicketTable::AddItem(this, a2, a3, a4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018260
// Name: public: Ticket::~Ticket(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall Ticket::~Ticket(TicketTable **this)
{
  TicketTable *v2; // edi
  void (__thiscall ***v3)(_DWORD, int); // ecx

  v2 = *this;
  if ( *this != nullptr )
  {
    TicketTable::~TicketTable(this: *this);
    free(pMem: v2);
  }
  v3 = (void (__thiscall ***)(_DWORD, int))*(this + 1);
  if ( v3 != nullptr )
    (**v3)(a1: v3, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10018290
// Name: public: char __near * Ticket::GetTicket(class StrPtr __near &,class StrPtr __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__thiscall Ticket::GetTicket(Ticket *this, struct StrPtr *a2, struct StrPtr *a3)
{
  int v5; // eax
  int length; // edx
  const char **Item; // eax
  const char *v8; // esi
  unsigned __int8 *buffer; // [esp-10h] [ebp-3Ch]
  struct StrRef v10; // [esp+4h] [ebp-28h] BYREF
  struct StrRef v11; // [esp+Ch] [ebp-20h] BYREF
  StrBuf pMem; // [esp+14h] [ebp-18h] BYREF
  Error v13; // [esp+20h] [ebp-Ch] BYREF

  if ( Ticket::Init(this) )
    return nullptr;
  v13.ep = nullptr;
  v13.severity = E_EMPTY;
  Ticket::ReadTicketFile(this, a2: &v13);
  if ( v13.severity <= E_INFO )
  {
    buffer = (unsigned __int8 *)a2->buffer;
    pMem.size = 0;
    pMem.buffer = StrBuf::nullStrBuf;
    strchr(string: buffer, chr: 0x3Au);
    pMem.length = 0;
    if ( v5 == 0 )
      StrBuf::Append(this: &pMem, src: "localhost:");
    StrBuf::Append(this: &pMem, src: a2->buffer);
    length = a3->length;
    v10.buffer = a3->buffer;
    v10.length = length;
    v11 = (struct StrRef)pMem.StrPtr;
    Item = TicketTable::GetItem(this: *(TicketTable **)this, a2: &v11, a3: &v10);
    if ( Item != nullptr )
    {
      v8 = Item[6];
      if ( pMem.buffer != StrBuf::nullStrBuf )
        free(pMem: pMem.buffer);
      Error::~Error(this: &v13);
      return (char *)v8;
    }
    else
    {
      if ( pMem.buffer != StrBuf::nullStrBuf )
        free(pMem: pMem.buffer);
      Error::~Error(this: &v13);
      return nullptr;
    }
  }
  else
  {
    Error::~Error(this: &v13);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100183B0
// Name: private: void Ticket::UpdateTicket(class StrPtr const __near &,class StrPtr __near &,class StrPtr __near &,int,class Error __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall Ticket::UpdateTicket(
        Ticket *this,
        const struct StrPtr *a2,
        struct StrPtr *a3,
        struct StrPtr *a4,
        int a5,
        struct Error *a6)
{
  int v7; // eax
  int length; // eax
  const char **Item; // eax
  int v10; // edx
  char *v11; // ecx
  int v12; // edx
  unsigned __int8 *buffer; // [esp-14h] [ebp-3Ch]
  struct StrRef v14; // [esp+4h] [ebp-24h] BYREF
  struct StrRef v15; // [esp+Ch] [ebp-1Ch] BYREF
  struct StrRef v16; // [esp+14h] [ebp-14h] BYREF
  StrBuf pMem; // [esp+1Ch] [ebp-Ch] BYREF

  if ( !Ticket::Init(this) )
  {
    Ticket::ReadTicketFile(this, a2: a6);
    if ( a6->severity <= E_INFO )
    {
      buffer = (unsigned __int8 *)a2->buffer;
      pMem.size = 0;
      pMem.buffer = StrBuf::nullStrBuf;
      strchr(string: buffer, chr: 0x3Au);
      pMem.length = 0;
      if ( v7 == 0 )
        StrBuf::Append(this: &pMem, src: "localhost:");
      StrBuf::Append(this: &pMem, src: a2->buffer);
      if ( a5 != 0 )
      {
        length = a3->length;
        v14.buffer = a3->buffer;
        v14.length = length;
        v15 = (struct StrRef)pMem.StrPtr;
        Item = TicketTable::GetItem(this: *(TicketTable **)this, a2: &v15, a3: &v14);
        if ( Item != nullptr )
          Item[9] = (const char *)1;
      }
      else
      {
        v10 = a4->length;
        v15.buffer = a4->buffer;
        v11 = a3->buffer;
        v15.length = v10;
        v12 = a3->length;
        v14.buffer = v11;
        v14.length = v12;
        v16 = (struct StrRef)pMem.StrPtr;
        TicketTable::PutItem(this: *(TicketTable **)this, a2: &v16, a3: &v14, a4: &v15);
      }
      Ticket::WriteTicketFile(this, a2: a6);
      if ( pMem.buffer != StrBuf::nullStrBuf )
        free(pMem: pMem.buffer);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100184E0
// Name: public: static void StrOps::Dump(class StrPtr const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
static void __cdecl StrOps::Dump(const struct StrPtr *a1)
{
  char *buffer; // esi
  char *v2; // edi

  buffer = a1->buffer;
  v2 = &a1->buffer[a1->length];
  if ( a1->buffer < v2 )
  {
    do
    {
      if ( *buffer < 0 || isprint(c: (unsigned __int8)*buffer) != 0 )
        putchar(ch: (unsigned __int8)*buffer);
      else
        printf(format: "<%02x>", (unsigned __int8)*buffer);
      ++buffer;
    }
    while ( buffer < v2 );
  }
  putchar(ch: 10);
}

//------------------------------------------------------------------------------
// Address: 0x10018540
// Name: public: static void StrOps::Lower(class StrBuf __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
static void __cdecl StrOps::Lower(struct StrBuf *a1)
{
  int length; // edx
  char *i; // ecx
  char v3; // al

  length = a1->length;
  for ( i = a1->buffer; length != 0; ++i )
  {
    v3 = *i;
    --length;
    if ( *i >= 65 && v3 <= 90 )
      v3 += 32;
    *i = v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018580
// Name: public: static void StrOps::Expand2(class StrBuf __near &,class StrPtr const __near &,class StrDict __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
static void __cdecl StrOps::Expand2(struct StrBuf *a1, const struct StrPtr *a2, struct StrDict *a3)
{
  char *buffer; // ebp
  int v4; // eax
  int v5; // edi
  unsigned __int8 *v6; // eax
  unsigned __int8 *v7; // ebx
  unsigned int v8; // esi
  StrPtr *(__thiscall *VGetVar)(StrDict *, const StrPtr *); // edx
  int v10; // eax
  unsigned int v11; // eax
  unsigned int v12; // esi
  unsigned int v13; // eax
  unsigned int v14; // esi
  int v15; // eax
  struct StrPtr *v16; // [esp+Ch] [ebp-60h]
  unsigned int v17; // [esp+10h] [ebp-5Ch]
  int v18; // [esp+14h] [ebp-58h]
  _DWORD v19[2]; // [esp+20h] [ebp-4Ch] BYREF
  unsigned __int8 dst[64]; // [esp+28h] [ebp-44h] BYREF

  buffer = a2->buffer;
  strchr(string: (unsigned __int8 *)a2->buffer, chr: 0x25u);
  v5 = v4;
  if ( v4 != 0 )
  {
    do
    {
      strchr(string: (unsigned __int8 *)(v5 + 1), chr: 0x25u);
      v7 = v6;
      if ( v6 == nullptr )
        break;
      if ( v6 == (unsigned __int8 *)(v5 + 1) )
      {
        StrBuf::Append(this: a1, src: buffer, count: v6 - (unsigned __int8 *)buffer);
        buffer = (char *)(v7 + 1);
      }
      else
      {
        v8 = (unsigned int)&v6[-v5 - 1];
        memcpy(dst, src: (unsigned __int8 *)(v5 + 1), count: v8);
        dst[v8] = 0;
        v19[0] = dst;
        VGetVar = a3->VGetVar;
        v19[1] = &v7[-v5 - 1];
        v16 = VGetVar(this: a3, a2: (const StrPtr *)v19);
        memchr(buf: (unsigned __int8 *)buffer, chr: 0x5Bu, cnt: v5 - (_DWORD)buffer);
        v18 = v10;
        if ( v10 != 0 )
        {
          strchr(string: v7 + 1, chr: 0x5Du);
          v12 = v11;
          v17 = v11;
          if ( v11 == 0 )
            break;
          StrBuf::Append(this: a1, src: buffer, count: v18 - (_DWORD)buffer);
          memchr(buf: v7, chr: 0x7Cu, cnt: v12 - (_DWORD)v7);
          v14 = v13;
          if ( v13 == 0 )
            v14 = v17;
          if ( v16 != nullptr && v16->length != 0 )
          {
            StrBuf::Append(this: a1, src: (char *)(v18 + 1), count: v5 - v18 - 1);
            StrBuf::Append(this: a1, a2: v16);
            StrBuf::Append(this: a1, src: (char *)v7 + 1, count: v14 - (_DWORD)v7 - 1);
          }
          else if ( v14 < v17 )
          {
            StrBuf::Append(this: a1, src: (char *)(v14 + 1), count: v17 - v14 - 1);
          }
          buffer = (char *)(v17 + 1);
        }
        else
        {
          StrBuf::Append(this: a1, src: buffer, count: v5 - (_DWORD)buffer);
          if ( v16 != nullptr )
            StrBuf::Append(this: a1, a2: v16);
          buffer = (char *)(v7 + 1);
        }
      }
      strchr(string: (unsigned __int8 *)buffer, chr: 0x25u);
      v5 = v15;
    }
    while ( v15 != 0 );
  }
  StrBuf::Append(this: a1, src: buffer);
}

//------------------------------------------------------------------------------
// Address: 0x10018750
// Name: public: static void StrOps::XtoO(char __near *,unsigned char __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
static void __cdecl StrOps::XtoO(char *a1, unsigned __int8 *a2, int a3)
{
  int i; // ebp
  char v6; // al
  char v7; // bl
  char v8; // dl
  char v9; // cl

  for ( i = a3; i != 0; a1 += 2 )
  {
    v6 = *a1;
    --i;
    if ( *a1 <= 57 )
      v7 = 48;
    else
      v7 = v6 < 97 ? 55 : 87;
    v8 = a1[1];
    if ( v8 <= 57 )
      v9 = 48;
    else
      v9 = v8 < 97 ? 55 : 87;
    *a2++ = (v8 - v9) | (16 * (v6 - v7));
  }
}

//------------------------------------------------------------------------------
// Address: 0x100187C0
// Name: public: static int StrOps::UnpackIntA(class StrRef __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
static int __cdecl StrOps::UnpackIntA(struct StrRef *a1)
{
  int length; // ecx
  char *buffer; // edx
  int v3; // esi
  int v4; // ebx
  char v5; // al

  length = a1->length;
  buffer = a1->buffer;
  v3 = 0;
  if ( length != 0 && *buffer == 45 )
  {
    v4 = 1;
    ++buffer;
    --length;
  }
  else
  {
    v4 = 0;
  }
  if ( length != 0 )
  {
    while ( *buffer != 0 )
    {
      v5 = *buffer++;
      --length;
      v3 = v5 + 10 * v3 - 48;
      if ( length == 0 )
        goto LABEL_10;
    }
    ++buffer;
    --length;
  }
LABEL_10:
  a1->buffer = buffer;
  a1->length = length;
  if ( v4 != 0 )
    return -v3;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10018820
// Name: public: static void StrOps::UnpackStringA(class StrRef __near &,class StrBuf __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
static void __cdecl StrOps::UnpackStringA(struct StrRef *a1, StrBuf *a2)
{
  signed int length; // edi
  char *buffer; // [esp-8h] [ebp-10h]

  length = StrOps::UnpackIntA(a1);
  if ( length > a1->length )
    length = a1->length;
  buffer = a1->buffer;
  a2->length = 0;
  StrBuf::Append(this: a2, src: buffer, count: length);
  a1->buffer += length;
  a1->length -= length;
}

//------------------------------------------------------------------------------
// Address: 0x10018860
// Name: public: static void StrOps::OtoX(unsigned char const __near *,int,class StrBuf __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
static void __cdecl StrOps::OtoX(const unsigned __int8 *a1, int a2, StrBuf *a3)
{
  unsigned int length; // esi
  int v4; // eax
  bool v5; // cc
  char *v6; // ecx
  int i; // edx
  unsigned __int8 v8; // al
  char v9; // al
  unsigned __int8 v10; // al
  _BYTE *v11; // ecx
  char v12; // al
  unsigned int v13; // esi

  length = a3->length;
  v4 = length + 2 * a2;
  v5 = v4 <= a3->size;
  a3->length = v4;
  if ( !v5 )
    StrBuf::Grow(this: a3, count: length);
  v6 = &a3->buffer[length];
  for ( i = 0; i < a2; v6 = v11 + 1 )
  {
    v8 = a1[i] >> 4;
    if ( v8 < 0xAu )
      v9 = v8 + 48;
    else
      v9 = v8 + 55;
    *v6 = v9;
    v10 = a1[i] & 0xF;
    v11 = v6 + 1;
    if ( v10 < 0xAu )
      v12 = v10 + 48;
    else
      v12 = v10 + 55;
    *v11 = v12;
    ++i;
  }
  v13 = a3->length;
  v5 = (int)(v13 + 1) <= a3->size;
  a3->length = v13 + 1;
  if ( !v5 )
    StrBuf::Grow(this: a3, count: v13);
  a3->buffer[v13] = 0;
  --a3->length;
}

//------------------------------------------------------------------------------
// Address: 0x100188F0
// Name: public: Mangle::Mangle(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
Mangle *__thiscall Mangle::Mangle(Mangle *this)
{
  *((_DWORD *)this + 2) = 2;
  *((_DWORD *)this + 3) = 1;
  *((_DWORD *)this + 8) = 2;
  *((_DWORD *)this + 13) = 1;
  *((_DWORD *)this + 24) = 2;
  *((_DWORD *)this + 27) = 1;
  *((_DWORD *)this + 33) = 2;
  *((_DWORD *)this + 42) = 1;
  *((_DWORD *)this + 49) = 1;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 23) = 0;
  *((_DWORD *)this + 38) = 0;
  *((_DWORD *)this + 53) = 0;
  *((_DWORD *)this + 43) = 10;
  *((_DWORD *)this + 48) = 10;
  *((_DWORD *)this + 4) = 5;
  *((_DWORD *)this + 9) = 5;
  *((_DWORD *)this + 30) = 5;
  *((_DWORD *)this + 47) = 5;
  *(_DWORD *)this = 7;
  *((_DWORD *)this + 1) = 6;
  *((_DWORD *)this + 6) = 3;
  *((_DWORD *)this + 7) = 4;
  *((_DWORD *)this + 10) = 4;
  *((_DWORD *)this + 12) = 3;
  *((_DWORD *)this + 14) = 7;
  *((_DWORD *)this + 15) = 6;
  *((_DWORD *)this + 16) = 12;
  *((_DWORD *)this + 17) = 15;
  *((_DWORD *)this + 18) = 7;
  *((_DWORD *)this + 19) = 10;
  *((_DWORD *)this + 20) = 14;
  *((_DWORD *)this + 21) = 13;
  *((_DWORD *)this + 22) = 11;
  *((_DWORD *)this + 25) = 6;
  *((_DWORD *)this + 26) = 3;
  *((_DWORD *)this + 28) = 9;
  *((_DWORD *)this + 29) = 4;
  *((_DWORD *)this + 31) = 8;
  *((_DWORD *)this + 32) = 7;
  *((_DWORD *)this + 34) = 14;
  *((_DWORD *)this + 35) = 9;
  *((_DWORD *)this + 36) = 3;
  *((_DWORD *)this + 37) = 11;
  *((_DWORD *)this + 39) = 4;
  *((_DWORD *)this + 40) = 12;
  *((_DWORD *)this + 41) = 13;
  *((_DWORD *)this + 44) = 6;
  *((_DWORD *)this + 45) = 15;
  *((_DWORD *)this + 46) = 8;
  *((_DWORD *)this + 50) = 13;
  *((_DWORD *)this + 51) = 12;
  *((_DWORD *)this + 52) = 4;
  *((_DWORD *)this + 54) = 11;
  *((_DWORD *)this + 55) = 3;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10018A80
// Name: private: void Mangle::Getdval(int,int __near * const,int __near * const)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall Mangle::Getdval(Mangle *this, int a2, int *const a3, int *const a4)
{
  int v4; // edx
  int v5; // ebp
  int v6; // ebx
  int v7; // eax
  int v8; // edi
  _DWORD *v9; // eax
  int v10; // eax
  int v11; // edx
  int v12; // edx
  int v13; // edx
  int v14; // edx
  _DWORD *v15; // eax
  int v16; // esi
  int *v17; // ecx
  int v18; // ecx
  bool v19; // zf
  int *v20; // eax
  int i; // edx
  int v22; // ecx
  int v23; // esi
  int v24; // ecx
  int v25; // esi
  int v26; // ecx
  int v27; // esi
  int v28; // ecx
  int v29; // esi
  int v30; // ecx
  int v31; // esi
  int v32; // ecx
  int v33; // esi
  int v34; // ecx
  int v35; // esi
  int v36; // ecx
  int *v37; // [esp+10h] [ebp-40h]
  Mangle *v38; // [esp+14h] [ebp-3Ch]
  int v39; // [esp+18h] [ebp-38h]
  _DWORD *v40; // [esp+1Ch] [ebp-34h]
  int v41; // [esp+20h] [ebp-30h]
  int v42; // [esp+24h] [ebp-2Ch]
  int v43; // [esp+28h] [ebp-28h]
  int v44; // [esp+2Ch] [ebp-24h]
  int *v45; // [esp+2Ch] [ebp-24h]
  int *v46; // [esp+2Ch] [ebp-24h]
  int *v47; // [esp+2Ch] [ebp-24h]
  _DWORD v48[8]; // [esp+30h] [ebp-20h]

  v4 = a2;
  v5 = 0;
  v6 = a2 != 0 ? 8 : 0;
  v38 = this;
  v41 = 0;
  v42 = 1;
  if ( a2 != 0 )
  {
    *((_DWORD *)this + 40) = *((_DWORD *)this + 52);
    *((_DWORD *)this + 41) = *((_DWORD *)this + 53);
    *((_DWORD *)this + 42) = *((_DWORD *)this + 54);
    *((_DWORD *)this + 43) = *((_DWORD *)this + 55);
  }
  v7 = 256;
  v43 = 16;
  while ( 1 )
  {
    if ( v4 != 0 )
      v6 = ((_BYTE)v6 + 1) & 0xF;
    v8 = 0;
    v37 = &a4[8 * v6];
    v9 = (int *const)((char *)a3 + v7 + 24);
    v40 = v9;
    while ( 1 )
    {
      v39 = *(v9 - 2) + 2 * (*(v9 - 1) + 2 * (*v9 + 2 * v9[1]));
      v44 = *(v9 - 6) + 2 * (*(v9 - 5) + 2 * (*(v9 - 4) + 2 * *(v9 - 3)));
      v10 = *v37 * (*((_DWORD *)this + v44 + 16) + 16 * *((_DWORD *)this + v39 + 32))
          + (1 - *v37) * (*((_DWORD *)this + v39 + 16) + 16 * *((_DWORD *)this + v44 + 32));
      v48[0] = v10 & 1;
      v10 >>= 1;
      v48[1] = v10 & 1;
      v10 >>= 1;
      v48[2] = v10 & 1;
      v10 >>= 1;
      v11 = v10 & 1;
      v10 >>= 1;
      v48[3] = v11;
      v12 = v10 & 1;
      v10 >>= 1;
      v48[4] = v12;
      v13 = v10 & 1;
      v10 >>= 1;
      v48[5] = v13;
      v48[6] = v10 & 1;
      v48[7] = (v10 >> 1) & 1;
      v14 = 0;
      v15 = (_DWORD *)((char *)this + 32);
      do
      {
        v45 = &a3[8 * (((_BYTE)v8 + (unsigned __int8)*(v15 - 8)) & 7) + 8 * v5 + v14];
        v16 = *v45 + v48[*v15] + a4[8 * v6 + *v15];
        v15 += 4;
        *v45 = v16 & 1;
        v46 = &a3[8 * (((_BYTE)v8 + (unsigned __int8)*(v15 - 11)) & 7) + 1 + 8 * v5 + v14];
        *v46 = (*v46 + v48[*(v15 - 3)] + a4[8 * v6 + *(v15 - 3)]) & 1;
        v47 = &a3[8 * (((_BYTE)v8 + (unsigned __int8)*(v15 - 10)) & 7) + 2 + 8 * v5 + v14];
        *v47 = (*v47 + v48[*(v15 - 2)] + a4[8 * v6 + *(v15 - 2)]) & 1;
        v17 = &a3[8 * (((_BYTE)v8 + (unsigned __int8)*(v15 - 9)) & 7) + 3 + 8 * v5 + v14];
        v14 += 4;
        *v17 = (*v17 + v48[*(v15 - 1)] + a4[8 * v6 + *(v15 - 1)]) & 1;
      }
      while ( v14 < 8 );
      if ( v8 < 7 || a2 != 0 )
        v6 = ((_BYTE)v6 + 1) & 0xF;
      ++v37;
      ++v8;
      v9 = v40 + 8;
      v40 += 8;
      if ( v8 >= 8 )
        break;
      this = v38;
    }
    v18 = v41;
    v7 = v41 << 8;
    v19 = v43-- == 1;
    v41 = v42;
    v5 = 8 * v42;
    v42 = v18;
    if ( v19 )
      break;
    this = v38;
    v4 = a2;
  }
  v20 = a3 + 1;
  for ( i = 8; i != 0; --i )
  {
    v22 = *(v20 - 1);
    *(v20 - 1) = v20[63];
    v23 = v20[64];
    v20[63] = v22;
    v24 = *v20;
    *v20 = v23;
    v25 = v20[65];
    v20[64] = v24;
    v26 = v20[1];
    v20[1] = v25;
    v27 = v20[66];
    v20[65] = v26;
    v28 = v20[2];
    v20[2] = v27;
    v29 = v20[67];
    v20[66] = v28;
    v30 = v20[3];
    v20[3] = v29;
    v31 = v20[68];
    v20[67] = v30;
    v32 = v20[4];
    v20[4] = v31;
    v33 = v20[69];
    v20[68] = v32;
    v34 = v20[5];
    v20[5] = v33;
    v35 = v20[70];
    v20[69] = v34;
    v36 = v20[6];
    v20[6] = v35;
    v20[70] = v36;
    v20 += 8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018DF0
// Name: private: void Mangle::DoIt(class StrPtr const __near &,class StrPtr const __near &,class StrBuf __near &,int,int,class Error __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall Mangle::DoIt(
        Mangle *this,
        const struct StrPtr *a2,
        const struct StrPtr *a3,
        struct StrBuf *a4,
        int a5,
        int a6,
        struct Error *a7)
{
  signed int length; // esi
  Mangle *v8; // ebx
  signed int v9; // eax
  unsigned __int8 *v10; // edi
  char *v11; // ebp
  int v12; // edx
  int *v13; // ecx
  int v14; // eax
  int v15; // esi
  int v16; // esi
  int i; // edx
  int v18; // eax
  int v19; // ecx
  int v20; // eax
  int v21; // esi
  int *v22; // eax
  int v23; // ecx
  int v24; // esi
  int v25; // eax
  int v26; // ecx
  int v27; // ecx
  int v28; // ecx
  bool v29; // zf
  int *v30; // eax
  int j; // edx
  int v32; // [esp+10h] [ebp-44Ch]
  int v34[5]; // [esp+1Ch] [ebp-440h] BYREF
  int v35[123]; // [esp+30h] [ebp-42Ch] BYREF
  int v36; // [esp+21Ch] [ebp-240h] BYREF
  char v37; // [esp+220h] [ebp-23Ch] BYREF
  unsigned __int8 v38[4]; // [esp+41Ch] [ebp-40h] BYREF
  int v39; // [esp+420h] [ebp-3Ch]
  int v40; // [esp+424h] [ebp-38h]
  int v41; // [esp+428h] [ebp-34h]
  char v42; // [esp+42Ch] [ebp-30h]
  char src[4]; // [esp+430h] [ebp-2Ch] BYREF
  int v44; // [esp+434h] [ebp-28h]
  int v45; // [esp+438h] [ebp-24h]
  int v46; // [esp+43Ch] [ebp-20h]
  char v47; // [esp+440h] [ebp-1Ch]
  unsigned __int8 dst[4]; // [esp+444h] [ebp-18h] BYREF
  int v49; // [esp+448h] [ebp-14h]
  int v50; // [esp+44Ch] [ebp-10h]
  int v51; // [esp+450h] [ebp-Ch]
  char v52; // [esp+454h] [ebp-8h]

  length = a2->length;
  v8 = this;
  if ( a5 == 0 )
  {
    if ( (length <= 16 || a6 != 0) && (length == 32 || a6 == 0) )
      goto LABEL_4;
LABEL_13:
    Error::Set(this: a7, a2: &MsgSupp::BadMangleParams);
    return;
  }
  if ( length != 32 && length != 0 )
    goto LABEL_13;
LABEL_4:
  *(_DWORD *)v38 = 0;
  v39 = 0;
  v40 = 0;
  v41 = 0;
  v42 = 0;
  *(_DWORD *)src = 0;
  v44 = 0;
  v45 = 0;
  v46 = 0;
  v47 = 0;
  *(_DWORD *)dst = 0;
  v49 = 0;
  v50 = 0;
  v51 = 0;
  v52 = 0;
  v9 = a3->length;
  if ( v9 > 16 )
    v9 = 16;
  memcpy(dst, src: (unsigned __int8 *)a3->buffer, count: v9);
  if ( a5 != 0 || a6 != 0 )
    StrOps::XtoO(a1: a2->buffer, a2: v38, a3: 16);
  else
    memcpy(dst: v38, src: (unsigned __int8 *)a2->buffer, count: length);
  v10 = v38;
  v11 = src;
  v12 = 0;
  v13 = (int *)&v37;
  do
  {
    v14 = dst[v12];
    *(v13 - 1) = dst[v12] & 1;
    v14 >>= 1;
    *v13 = v14 & 1;
    v14 >>= 1;
    v13[1] = v14 & 1;
    v14 >>= 1;
    v13[2] = v14 & 1;
    v14 >>= 1;
    v15 = v14 & 1;
    v14 >>= 1;
    v13[3] = v15;
    v16 = v14 & 1;
    v14 >>= 1;
    v13[4] = v16;
    v13[5] = v14 & 1;
    v13[6] = (v14 >> 1) & 1;
    ++v12;
    v13 += 8;
  }
  while ( v12 < 16 );
  i = 0;
  if ( a5 != 0 )
  {
    v18 = *((_DWORD *)v8 + 49);
    *((_DWORD *)v8 + 36) = *((_DWORD *)v8 + 48);
    v19 = *((_DWORD *)v8 + 50);
    *((_DWORD *)v8 + 37) = v18;
    v20 = *((_DWORD *)v8 + 51);
    *((_DWORD *)v8 + 38) = v19;
    *((_DWORD *)v8 + 39) = v20;
  }
  v32 = 16;
  do
  {
    v21 = (char)*v10++;
    if ( i == 16 )
    {
      Mangle::Getdval(this: v8, a2: a5, a3: v34, a4: &v36);
      v22 = v35;
      for ( i = 16; i != 0; --i )
      {
        *v11++ = *((_BYTE *)v22 - 20)
               + 2
               * (*((_BYTE *)v22 - 16)
                + 2
                * (*((_BYTE *)v22 - 12)
                 + 2
                 * (*((_BYTE *)v22 - 8)
                  + 2
                  * (*((_BYTE *)v22 - 4) + 2 * (*(_BYTE *)v22 + 2 * (*((_BYTE *)v22 + 4) + 2 * *((_BYTE *)v22 + 8)))))));
        v22 += 8;
      }
      v8 = this;
    }
    v23 = v21 & 1;
    v24 = v21 >> 1;
    v25 = 8 * i;
    v34[v25] = v23;
    v34[v25 + 1] = v24 & 1;
    v24 >>= 1;
    v34[v25 + 2] = v24 & 1;
    v24 >>= 1;
    v26 = v24 & 1;
    v24 >>= 1;
    v34[v25 + 3] = v26;
    v27 = v24 & 1;
    v24 >>= 1;
    v34[v25 + 4] = v27;
    v28 = v24 & 1;
    v24 >>= 1;
    v35[v25] = v28;
    ++i;
    v29 = v32-- == 1;
    v35[v25 + 1] = v24 & 1;
    v35[v25 + 2] = (v24 >> 1) & 1;
  }
  while ( !v29 );
  if ( i < 16 )
    memset(&v34[8 * i], 0, 4 * ((8 * (16 - i)) & 0x3FFFFFF8));
  Mangle::Getdval(this: v8, a2: a5, a3: v34, a4: &v36);
  v30 = v35;
  for ( j = 16; j != 0; --j )
  {
    *v11++ = *((_BYTE *)v30 - 20)
           + 2
           * (*((_BYTE *)v30 - 16)
            + 2
            * (*((_BYTE *)v30 - 12)
             + 2
             * (*((_BYTE *)v30 - 8)
              + 2 * (*((_BYTE *)v30 - 4) + 2 * (*(_BYTE *)v30 + 2 * (*((_BYTE *)v30 + 4) + 2 * *((_BYTE *)v30 + 8)))))));
    v30 += 8;
  }
  *v11 = 0;
  a4->length = 0;
  if ( a5 == 0 || a6 != 0 )
  {
    StrOps::OtoX(a1: (const unsigned __int8 *)src, a2: 16, a3: a4);
  }
  else
  {
    a4->length = 0;
    StrBuf::Append(this: a4, src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100191C0
// Name: public: StrPtrDict::StrPtrDict(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
StrPtrDict *__thiscall StrPtrDict::StrPtrDict(StrPtrDict *this)
{
  StrPtrArray *v2; // eax
  StrPtrArray *v3; // eax

  *(_DWORD *)this = &StrPtrDict::`vftable';
  v2 = (StrPtrArray *)operator new(nSize: 0xCu);
  if ( v2 != nullptr )
    v3 = StrPtrArray::StrPtrArray(this: v2);
  else
    v3 = nullptr;
  *((_DWORD *)this + 1) = v3;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10019200
// Name: public: virtual class StrPtr __near * StrPtrDict::VGetVar(class StrPtr const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct StrPtr *__thiscall StrPtrDict::VGetVar(StrPtrDict *this, const struct StrPtr *a2)
{
  int v2; // edi
  int v3; // ebx
  const char **v4; // esi
  int v6; // [esp+10h] [ebp-4h]

  v2 = 0;
  v6 = *((_DWORD *)this + 3);
  if ( v6 <= 0 )
    return nullptr;
  v3 = *((_DWORD *)this + 1);
  while ( 1 )
  {
    v4 = v2 >= *(_DWORD *)(v3 + 4) ? nullptr : *(const char ***)(*(_DWORD *)(v3 + 8) + 4 * v2);
    if ( strcmp(*v4, a2->buffer) == 0 )
      break;
    if ( ++v2 >= v6 )
      return nullptr;
  }
  return (struct StrPtr *)(v4 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x10019280
// Name: public: virtual void StrPtrDict::VSetVar(class StrPtr const __near &,class StrPtr const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall StrPtrDict::VSetVar(VarArray **this, const struct StrPtr *a2, const struct StrPtr *a3)
{
  void *v4; // edi
  int v5; // eax
  int v6; // esi
  struct StrPtr *v7; // eax

  if ( *(this + 3) == *(this + 2) )
  {
    v4 = operator new(nSize: 0x10u);
    *VarArray::New(this: *(this + 1)) = v4;
    *(this + 2) = (VarArray *)((char *)*(this + 2) + 1);
  }
  v5 = (int)*(this + 3);
  *(this + 3) = (VarArray *)(v5 + 1);
  v6 = (int)*(this + 1);
  if ( v5 >= *(_DWORD *)(v6 + 4) )
    v7 = nullptr;
  else
    v7 = *(struct StrPtr **)(*(_DWORD *)(v6 + 8) + 4 * v5);
  *v7 = *a2;
  v7[1] = *a3;
}

//------------------------------------------------------------------------------
// Address: 0x100192F0
// Name: public: virtual void StrBufDict::VRemoveVar(class StrPtr const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall StrBufDict::VRemoveVar(StrBufDict *this, const struct StrPtr *a2)
{
  int v2; // esi
  int v3; // edi
  const char **v4; // eax
  int v5; // eax
  int v6; // ecx
  int v7; // edx

  v2 = 0;
  if ( *((int *)this + 3) > 0 )
  {
    v3 = *((_DWORD *)this + 1);
    while ( 1 )
    {
      v4 = v2 >= *(_DWORD *)(v3 + 4) ? nullptr : *(const char ***)(*(_DWORD *)(v3 + 8) + 4 * v2);
      if ( strcmp(*v4, a2->buffer) == 0 )
        break;
      if ( ++v2 >= *((_DWORD *)this + 3) )
        return;
    }
    v5 = *((_DWORD *)this + 3) - 1;
    *((_DWORD *)this + 3) = v5;
    v6 = *(_DWORD *)(v3 + 8);
    v7 = *(_DWORD *)(v6 + 4 * v5);
    *(_DWORD *)(v6 + 4 * v5) = *(_DWORD *)(v6 + 4 * v2);
    *(_DWORD *)(*(_DWORD *)(v3 + 8) + 4 * v2) = v7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10019380
// Name: public: StrBufDict::StrBufDict(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
StrBufDict *__thiscall StrBufDict::StrBufDict(StrBufDict *this)
{
  StrPtrArray *v2; // eax
  StrPtrArray *v3; // eax

  *(_DWORD *)this = &StrBufDict::`vftable';
  v2 = (StrPtrArray *)operator new(nSize: 0xCu);
  if ( v2 != nullptr )
    v3 = StrPtrArray::StrPtrArray(this: v2);
  else
    v3 = nullptr;
  *((_DWORD *)this + 1) = v3;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100193C0
// Name: public: virtual class StrPtr __near * StrBufDict::VGetVar(class StrPtr const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct StrPtr *__thiscall StrBufDict::VGetVar(StrBufDict *this, const struct StrPtr *a2)
{
  int v2; // edi
  int v3; // ebx
  const char **v4; // esi
  int v6; // [esp+10h] [ebp-4h]

  v2 = 0;
  v6 = *((_DWORD *)this + 3);
  if ( v6 <= 0 )
    return nullptr;
  v3 = *((_DWORD *)this + 1);
  while ( 1 )
  {
    v4 = v2 >= *(_DWORD *)(v3 + 4) ? nullptr : *(const char ***)(*(_DWORD *)(v3 + 8) + 4 * v2);
    if ( strcmp(*v4, a2->buffer) == 0 )
      break;
    if ( ++v2 >= v6 )
      return nullptr;
  }
  return (struct StrPtr *)(v4 + 3);
}

//------------------------------------------------------------------------------
// Address: 0x10019440
// Name: public: virtual class StrPtr __near * BufferDict::VGetVar(class StrPtr const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct StrPtr *__thiscall BufferDict::VGetVar(BufferDict *this, const struct StrPtr *a2)
{
  unsigned int length; // edx
  _DWORD *i; // ebx
  char *buffer; // esi
  _DWORD *v5; // eax
  int v6; // edi
  unsigned int v7; // edx
  unsigned __int8 *v8; // esi
  unsigned __int8 *v9; // eax
  unsigned int v10; // edx
  unsigned __int8 *v11; // esi
  unsigned __int8 *v12; // eax
  unsigned __int8 *v13; // esi
  unsigned __int8 *v14; // eax
  int v15; // eax
  int v17; // edx
  int v18; // [esp+10h] [ebp-8h]

  v18 = 0;
  if ( *((int *)this + 3) <= 0 )
    return nullptr;
  length = a2->length;
  for ( i = (_DWORD *)((char *)this + 16); length != i[1]; i += 4 )
  {
LABEL_20:
    if ( ++v18 >= *((_DWORD *)this + 3) )
      return nullptr;
  }
  buffer = a2->buffer;
  v5 = (_DWORD *)(*i + *((_DWORD *)this + 84));
  if ( length < 4 )
  {
LABEL_7:
    if ( length == 0 )
    {
LABEL_17:
      v15 = 0;
      goto LABEL_18;
    }
  }
  else
  {
    while ( *v5 == *(_DWORD *)buffer )
    {
      length -= 4;
      buffer += 4;
      ++v5;
      if ( length < 4 )
        goto LABEL_7;
    }
  }
  v6 = *(unsigned __int8 *)v5 - (unsigned __int8)*buffer;
  if ( v6 == 0 )
  {
    v7 = length - 1;
    v8 = (unsigned __int8 *)(buffer + 1);
    v9 = (unsigned __int8 *)v5 + 1;
    if ( v7 == 0 )
      goto LABEL_17;
    v6 = *v9 - *v8;
    if ( v6 == 0 )
    {
      v10 = v7 - 1;
      v11 = v8 + 1;
      v12 = v9 + 1;
      if ( v10 == 0 )
        goto LABEL_17;
      v6 = *v12 - *v11;
      if ( v6 == 0 )
      {
        v13 = v11 + 1;
        v14 = v12 + 1;
        if ( v10 == 1 )
          goto LABEL_17;
        v6 = *v14 - *v13;
        if ( v6 == 0 )
          goto LABEL_17;
      }
    }
  }
  v15 = 1;
  if ( v6 <= 0 )
    v15 = -1;
LABEL_18:
  if ( v15 != 0 )
  {
    length = a2->length;
    goto LABEL_20;
  }
  v17 = i[3];
  *((_DWORD *)this + 1) = *((_DWORD *)this + 84) + i[2];
  *((_DWORD *)this + 2) = v17;
  return (struct StrPtr *)((char *)this + 4);
}

//------------------------------------------------------------------------------
// Address: 0x10019550
// Name: public: virtual int BufferDict::VGetVarX(int,class StrRef __near &,class StrRef __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall BufferDict::VGetVarX(BufferDict *this, int a2, struct StrRef *a3, struct StrRef *a4)
{
  int v4; // eax
  int v5; // edx
  _DWORD *v6; // eax
  char *v7; // edi
  int v8; // edx

  if ( a2 < 0 || a2 >= *((_DWORD *)this + 3) )
    return 0;
  v4 = 16 * (a2 + 1);
  v5 = *(_DWORD *)((char *)this + v4 + 4);
  v6 = (_DWORD *)((char *)this + v4);
  v7 = (char *)(*v6 + *((_DWORD *)this + 84));
  a3->length = v5;
  a3->buffer = v7;
  v8 = v6[3];
  a4->buffer = (char *)(*((_DWORD *)this + 84) + v6[2]);
  a4->length = v8;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100195A0
// Name: public: virtual StrPtrDict::~StrPtrDict(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall StrPtrDict::~StrPtrDict(StrDict *this)
{
  int v2; // esi
  bool v3; // zf
  bool v4; // sf
  int v5; // eax
  void *v6; // eax
  void *v7; // esi

  v2 = 0;
  v3 = *((_DWORD *)this + 2) == 0;
  v4 = *((int *)this + 2) < 0;
  this->__vftable = (StrDict_vtbl *)&StrPtrDict::`vftable';
  if ( !v4 && !v3 )
  {
    do
    {
      v5 = *((_DWORD *)this + 1);
      if ( v2 >= *(_DWORD *)(v5 + 4) )
        v6 = nullptr;
      else
        v6 = *(void **)(*(_DWORD *)(v5 + 8) + 4 * v2);
      free(pMem: v6);
      ++v2;
    }
    while ( v2 < *((_DWORD *)this + 2) );
  }
  v7 = *((void **)this + 1);
  if ( v7 != nullptr )
  {
    VarArray::~VarArray(this: *((VarArray **)this + 1));
    free(pMem: v7);
  }
  StrDict::~StrDict(this);
}

//------------------------------------------------------------------------------
// Address: 0x10019600
// Name: public: virtual int StrPtrDict::VGetVarX(int,class StrRef __near &,class StrRef __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall StrPtrDict::VGetVarX(StrPtrDict *this, int a2, struct StrRef *a3, struct StrRef *a4)
{
  int v5; // eax
  int v6; // eax
  int v7; // ecx
  int v8; // ecx

  if ( a2 >= *((_DWORD *)this + 3) )
    return 0;
  v5 = *((_DWORD *)this + 1);
  if ( a2 >= *(_DWORD *)(v5 + 4) )
    v6 = 0;
  else
    v6 = *(_DWORD *)(*(_DWORD *)(v5 + 8) + 4 * a2);
  v7 = *(_DWORD *)(v6 + 4);
  a3->buffer = *(char **)v6;
  a3->length = v7;
  v8 = *(_DWORD *)(v6 + 12);
  a4->buffer = *(char **)(v6 + 8);
  a4->length = v8;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10019650
// Name: public: virtual int StrBufDict::VGetVarX(int,class StrRef __near &,class StrRef __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall StrBufDict::VGetVarX(StrBufDict *this, int a2, struct StrRef *a3, struct StrRef *a4)
{
  int v5; // eax
  int v6; // eax
  int v7; // ecx
  int v8; // ecx

  if ( a2 >= *((_DWORD *)this + 3) )
    return 0;
  v5 = *((_DWORD *)this + 1);
  if ( a2 >= *(_DWORD *)(v5 + 4) )
    v6 = 0;
  else
    v6 = *(_DWORD *)(*(_DWORD *)(v5 + 8) + 4 * a2);
  v7 = *(_DWORD *)(v6 + 4);
  a3->buffer = *(char **)v6;
  a3->length = v7;
  v8 = *(_DWORD *)(v6 + 16);
  a4->buffer = *(char **)(v6 + 12);
  a4->length = v8;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100196A0
// Name: public: class BufferDict __near & BufferDict::operator=(class BufferDict const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall BufferDict::operator=(_DWORD *this, const struct StrPtr *a2)
{
  StrBuf *v3; // ecx
  int length; // eax
  int v5; // edx
  _DWORD *v6; // eax
  int v7; // ecx

  v3 = (StrBuf *)(this + 84);
  if ( v3 != &a2[42] )
  {
    v3->length = 0;
    StrBuf::Append(this: v3, a2: a2 + 42);
  }
  length = a2[1].length;
  v5 = 0;
  *(this + 3) = length;
  if ( length > 0 )
  {
    v6 = this + 4;
    v7 = (char *)a2 - (char *)this;
    do
    {
      *v6 = *(_DWORD *)((char *)v6 + v7);
      v6[1] = *(_DWORD *)((char *)v6 + v7 + 4);
      v6[2] = *(_DWORD *)((char *)v6 + v7 + 8);
      v6[3] = *(_DWORD *)((char *)v6 + v7 + 12);
      ++v5;
      v6 += 4;
    }
    while ( v5 < *(this + 3) );
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10019710
// Name: public: virtual void BufferDict::VSetVar(class StrPtr const __near &,class StrPtr const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall BufferDict::VSetVar(StrBuf *this, const struct StrPtr *a2, const struct StrPtr *a3)
{
  int v4; // edi
  _DWORD *v5; // edi
  unsigned int length; // ecx
  char *buffer; // edx
  unsigned int v8; // ebp
  StrBuf *v9; // esi
  bool v10; // cc
  unsigned int v11; // ebp
  unsigned int v12; // ebx
  unsigned int v13; // edi
  unsigned __int8 *v14; // ebp
  unsigned int v15; // edi
  unsigned __int8 *src; // [esp+10h] [ebp-4h]
  const struct StrPtr *v17; // [esp+18h] [ebp+4h]

  if ( *((_DWORD *)this + 3) == 20 )
    *((_DWORD *)this + 3) = 19;
  v4 = *((_DWORD *)this + 3) + 1;
  *((_DWORD *)this + 3) = v4;
  v4 *= 16;
  *(char **)((char *)&this->buffer + v4) = *((char **)this + 85);
  v5 = (char **)((char *)&this->buffer + v4);
  v5[1] = a2->length;
  length = a2->length;
  buffer = a2->buffer;
  v8 = *((_DWORD *)this + 85);
  v9 = this + 28;
  v10 = (int)(length + v8) <= *((_DWORD *)this + 86);
  v17 = (const struct StrPtr *)length;
  src = (unsigned __int8 *)buffer;
  *((_DWORD *)this + 85) = length + v8;
  if ( !v10 )
  {
    StrBuf::Grow(this: this + 28, count: v8);
    length = (unsigned int)v17;
  }
  memcpy(dst: (unsigned __int8 *)&v9->buffer[v8], src, count: length);
  v11 = *((_DWORD *)this + 85);
  v10 = (int)(v11 + 1) <= *((_DWORD *)this + 86);
  *((_DWORD *)this + 85) = v11 + 1;
  if ( !v10 )
    StrBuf::Grow(this: this + 28, count: v11);
  v9->buffer[v11] = 0;
  v5[2] = *((_DWORD *)this + 85);
  v5[3] = a3->length;
  v12 = a3->length;
  v13 = v9->length;
  v14 = (unsigned __int8 *)a3->buffer;
  v10 = (int)(v13 + v12) <= v9->size;
  v9->length = v13 + v12;
  if ( !v10 )
    StrBuf::Grow(this: v9, count: v13);
  memcpy(dst: (unsigned __int8 *)&v9->buffer[v13], src: v14, count: v12);
  v15 = v9->length;
  v10 = (int)(v15 + 1) <= v9->size;
  v9->length = v15 + 1;
  if ( !v10 )
    StrBuf::Grow(this: v9, count: v15);
  v9->buffer[v15] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10019840
// Name: public: virtual StrBufDict::~StrBufDict(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall StrBufDict::~StrBufDict(StrDict *this)
{
  int v2; // edi
  bool v3; // zf
  bool v4; // sf
  int v5; // eax
  void **v6; // esi
  void *v7; // esi

  v2 = 0;
  v3 = *((_DWORD *)this + 2) == 0;
  v4 = *((int *)this + 2) < 0;
  this->__vftable = (StrDict_vtbl *)&StrBufDict::`vftable';
  if ( !v4 && !v3 )
  {
    do
    {
      v5 = *((_DWORD *)this + 1);
      if ( v2 < *(_DWORD *)(v5 + 4) )
      {
        v6 = *(void ***)(*(_DWORD *)(v5 + 8) + 4 * v2);
        if ( v6 != nullptr )
        {
          if ( v6[3] != StrBuf::nullStrBuf )
            free(pMem: v6[3]);
          if ( *v6 != StrBuf::nullStrBuf )
            free(pMem: *v6);
          free(pMem: v6);
        }
      }
      ++v2;
    }
    while ( v2 < *((_DWORD *)this + 2) );
  }
  v7 = *((void **)this + 1);
  if ( v7 != nullptr )
  {
    VarArray::~VarArray(this: *((VarArray **)this + 1));
    free(pMem: v7);
  }
  StrDict::~StrDict(this);
}

//------------------------------------------------------------------------------
// Address: 0x100198C0
// Name: public: virtual void StrBufDict::VSetVar(class StrPtr const __near &,class StrPtr const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall StrBufDict::VSetVar(VarArray **this, StrBuf *a2, StrBuf *a3)
{
  _DWORD *v4; // eax
  void *v5; // edi
  int v6; // eax
  int v7; // esi
  StrBuf *v8; // esi

  if ( *(this + 3) == *(this + 2) )
  {
    v4 = operator new(nSize: 0x18u);
    if ( v4 != nullptr )
    {
      v4[2] = 0;
      v4[1] = 0;
      *v4 = StrBuf::nullStrBuf;
      v4[5] = 0;
      v4[4] = 0;
      v4[3] = StrBuf::nullStrBuf;
      v5 = v4;
    }
    else
    {
      v5 = nullptr;
    }
    *VarArray::New(this: *(this + 1)) = v5;
    *(this + 2) = (VarArray *)((char *)*(this + 2) + 1);
  }
  v6 = (int)*(this + 3);
  *(this + 3) = (VarArray *)(v6 + 1);
  v7 = (int)*(this + 1);
  if ( v6 >= *(_DWORD *)(v7 + 4) )
    v8 = nullptr;
  else
    v8 = *(StrBuf **)(*(_DWORD *)(v7 + 8) + 4 * v6);
  if ( v8 != a2 )
  {
    v8->length = 0;
    StrBuf::Append(this: v8, a2);
  }
  if ( &v8[1] != a3 )
  {
    v8[1].length = 0;
    StrBuf::Append(this: v8 + 1, a2: a3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003F8D0
// Name: _dynamic_atexit_destructor_for__s_p4__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_p4__()
{
  CP4::~CP4(this: &s_p4);
}

//------------------------------------------------------------------------------
// Address: 0x1003F8E0
// Name: _dynamic_atexit_destructor_for__g_WhereUser__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_WhereUser__()
{
  CUtlVector<CClientPathRecord,CUtlMemory<CClientPathRecord,int>>::~CUtlVector<CClientPathRecord,CUtlMemory<CClientPathRecord,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&g_WhereUser.m_Data);
  ClientUser::~ClientUser(this: &g_WhereUser);
}

//------------------------------------------------------------------------------
// Address: 0x1003F900
// Name: _dynamic_atexit_destructor_for__g_FileUser__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_FileUser__()
{
  CUtlVector<CClientPathRecord,CUtlMemory<CClientPathRecord,int>>::~CUtlVector<CClientPathRecord,CUtlMemory<CClientPathRecord,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&g_FileUser.m_Data);
  ClientUser::~ClientUser(this: &g_FileUser);
}

//------------------------------------------------------------------------------
// Address: 0x1003F920
// Name: _dynamic_atexit_destructor_for__g_ClientspecUser__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ClientspecUser__()
{
  CUtlVector<CClientPathRecord,CUtlMemory<CClientPathRecord,int>>::~CUtlVector<CClientPathRecord,CUtlMemory<CClientPathRecord,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&g_ClientspecUser.m_Data);
  ClientUser::~ClientUser(this: &g_ClientspecUser);
}

//------------------------------------------------------------------------------
// Address: 0x1003F940
// Name: _dynamic_atexit_destructor_for__g_ChangelistCreateUser__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ChangelistCreateUser__()
{
  CUtlVector<CClientPathRecord,CUtlMemory<CClientPathRecord,int>>::~CUtlVector<CClientPathRecord,CUtlMemory<CClientPathRecord,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&g_ChangelistCreateUser.m_Data);
  ClientUser::~ClientUser(this: &g_ChangelistCreateUser);
}

//------------------------------------------------------------------------------
// Address: 0x1003F960
// Name: _dynamic_atexit_destructor_for__g_ChangelistFindUser__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ChangelistFindUser__()
{
  CUtlVector<CClientPathRecord,CUtlMemory<CClientPathRecord,int>>::~CUtlVector<CClientPathRecord,CUtlMemory<CClientPathRecord,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&g_ChangelistFindUser.m_Data);
  ClientUser::~ClientUser(this: &g_ChangelistFindUser);
}

//------------------------------------------------------------------------------
// Address: 0x1003F990
// Name: _dynamic_atexit_destructor_for__g_RevisionHistoryUser__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_RevisionHistoryUser__()
{
  CUtlVector<P4Revision_t,CUtlMemory<P4Revision_t,int>>::~CUtlVector<P4Revision_t,CUtlMemory<P4Revision_t,int>>(this: &g_RevisionHistoryUser.m_Data);
  ClientUser::~ClientUser(this: &g_RevisionHistoryUser);
}

//------------------------------------------------------------------------------
// Address: 0x1003F9B0
// Name: func
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl func()
{
  Enviro::~Enviro(this: (Enviro *)&enviro);
}

//------------------------------------------------------------------------------
// Address: 0x1003F9C0
// Name: sub_1003F9C0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl sub_1003F9C0()
{
  Error::~Error(this: &AssertError);
}

//------------------------------------------------------------------------------
// Address: 0x1003F9D0
// Name: sub_1003F9D0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl sub_1003F9D0()
{
  if ( dword_1004F8F4 != 0 )
    (**(void (__thiscall ***)(int, int))dword_1004F8F4)(a1: dword_1004F8F4, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1003F9F0
// Name: _dynamic_atexit_destructor_for__g_CleanupSymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CleanupSymbolTable__()
{
  CUtlSymbolTableMT *v0; // esi

  v0 = CUtlSymbol::s_pSymbolTable;
  if ( CUtlSymbol::s_pSymbolTable != nullptr )
  {
    CUtlSymbolTable::RemoveAll(this: CUtlSymbol::s_pSymbolTable);
    CUtlVector<CClientPathRecord,CUtlMemory<CClientPathRecord,int>>::~CUtlVector<CClientPathRecord,CUtlMemory<CClientPathRecord,int>>(this: &v0->m_StringPools);
    CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>(this: &v0->m_Lookup);
    free(pMem: v0);
  }
  CUtlSymbol::s_pSymbolTable = nullptr;
}
