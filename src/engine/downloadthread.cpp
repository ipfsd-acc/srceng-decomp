// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/downloadthread.cpp
// Functions: 10
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10164BB0
// Name: void DownloadStatusCallback(void __near *,unsigned long,unsigned long,void __near *,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __stdcall DownloadStatusCallback(
        void *hOpenResource,
        unsigned int dwContext,
        unsigned int dwStatus,
        _DWORD *pStatusInfo,
        unsigned int dwStatusInfoLength)
{
  switch ( dwStatus )
  {
    case 0xAu:
    case 0xBu:
    case 0x14u:
    case 0x15u:
    case 0x1Eu:
    case 0x1Fu:
    case 0x32u:
    case 0x33u:
    case 0x64u:
      if ( pStatusInfo != nullptr )
        pStatusInfo[3] = dwStatus;
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10164C40
// Name: void ReadData(struct RequestContext __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ReadData(RequestContext *rc)
{
  bool v1; // zf
  unsigned int v2; // edi
  unsigned int nBytesCurrent; // ecx
  unsigned __int8 *v4; // eax
  _iobuf *v5; // edi
  unsigned __int8 data[2048]; // [esp+4h] [ebp-938h] BYREF
  char path[260]; // [esp+804h] [ebp-138h] BYREF
  stat buf; // [esp+908h] [ebp-34h] BYREF
  unsigned int dwSize; // [esp+938h] [ebp-4h] BYREF

  v1 = rc->nBytesTotal == 0;
  dwSize = 0;
  if ( v1 )
  {
    rc->status = HTTP_ERROR;
    rc->error = HTTP_ERROR_ZERO_LENGTH_FILE;
  }
  else
  {
    v1 = !rc->shouldStop;
    rc->nBytesCurrent = rc->nBytesCached;
    rc->status = HTTP_FETCH;
    if ( v1 )
    {
      while ( 1 )
      {
        if ( !InternetReadFile(
                hFile: rc->hDataResource,
                lpBuffer: data,
                dwNumberOfBytesToRead: 0x800u,
                lpdwNumberOfBytesRead: &dwSize) )
        {
          rc->status = HTTP_ERROR;
          rc->error = HTTP_ERROR_CONNECTION_CLOSED;
          return;
        }
        v2 = dwSize;
        if ( dwSize == 0 )
          break;
        nBytesCurrent = rc->nBytesCurrent;
        if ( rc->nBytesTotal - nBytesCurrent < dwSize )
          v2 = rc->nBytesTotal - nBytesCurrent;
        v4 = rc->data;
        if ( v4 != nullptr && v2 != 0 )
          memcpy(dst: &v4[nBytesCurrent], src: data, count: v2);
        rc->nBytesCurrent += v2;
        if ( rc->shouldStop )
          goto LABEL_12;
      }
      V_snprintf(pDest: path, maxLen: 260, pFormat: "%s\\%s", rc->basePath, rc->gamePath);
      if ( _stat64i32(name: path, (_stat64i32 *)&buf) == -1 )
      {
        v5 = fopen(file: path, mode: "wb");
        if ( v5 != nullptr )
        {
          fwrite(buffer: rc->data, size: rc->nBytesTotal, count: 1u, stream: v5);
          fclose(stream: v5);
        }
      }
      rc->status = HTTP_DONE;
    }
    else
    {
LABEL_12:
      rc->status = HTTP_ABORTED;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10164DA0
// Name: void CleanUpDownload(struct RequestContext __near &,enum HTTPStatus,enum HTTPError)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CleanUpDownload(RequestContext *rc, HTTPStatus status, HTTPError error)
{
  void *hDataResource; // eax
  bool v4; // zf

  rc->status = status;
  hDataResource = rc->hDataResource;
  rc->error = error;
  if ( (hDataResource == nullptr || InternetCloseHandle(hInternet: hDataResource)) && rc->hOpenResource != nullptr )
    InternetCloseHandle(hInternet: rc->hOpenResource);
  v4 = !rc->shouldStop;
  rc->hDataResource = nullptr;
  rc->hOpenResource = nullptr;
  if ( v4 )
  {
    do
      Sleep(dwMilliseconds: 0x64u);
    while ( !rc->shouldStop );
  }
  if ( rc->data != nullptr )
  {
    free(pMem: rc->data);
    rc->data = nullptr;
  }
  rc->threadDone = true;
}

//------------------------------------------------------------------------------
// Address: 0x10164E30
// Name: unsigned int DownloadThread(void __near *)
// Source: json
//------------------------------------------------------------------------------
HTTPStatus __cdecl DownloadThread(unsigned int voidPtr)
{
  RequestContext *v1; // esi
  HINTERNET v3; // eax
  char *v4; // eax
  DWORD v5; // ecx
  unsigned int nBytesCached; // edx
  HINTERNET v7; // eax
  bool v8; // zf
  unsigned int v9; // ecx
  unsigned int v10; // eax
  unsigned __int8 *cacheData; // edx
  unsigned int nBytesTotal; // eax
  void *hDataResource; // [esp-18h] [ebp-964h]
  void *v14; // [esp-18h] [ebp-964h]
  char urlBuf[6][256]; // [esp+8h] [ebp-944h] BYREF
  char fullURL[512]; // [esp+608h] [ebp-344h] BYREF
  char headers[256]; // [esp+808h] [ebp-144h] BYREF
  URL_COMPONENTSA url; // [esp+908h] [ebp-44h] BYREF
  unsigned int flags; // [esp+944h] [ebp-8h]
  unsigned int code; // [esp+948h] [ebp-4h] BYREF

  v1 = (RequestContext *)voidPtr;
  url.lpszScheme = urlBuf[0];
  url.lpszHostName = urlBuf[1];
  url.lpszUserName = urlBuf[2];
  url.lpszPassword = urlBuf[3];
  url.lpszUrlPath = urlBuf[4];
  url.lpszExtraInfo = urlBuf[5];
  url.dwStructSize = 60;
  url.dwSchemeLength = 256;
  url.dwHostNameLength = 256;
  url.dwUserNameLength = 256;
  url.dwPasswordLength = 256;
  url.dwUrlPathLength = 256;
  url.dwExtraInfoLength = 256;
  V_snprintf(pDest: fullURL, maxLen: 512, pFormat: "%s%s", (const char *)(voidPtr + 20), (const char *)(voidPtr + 532));
  if ( !InternetCrackUrlA(lpszUrl: fullURL, dwUrlLength: 0x200u, dwFlags: 0, lpUrlComponents: &url) )
  {
    CleanUpDownload(rc: v1, status: HTTP_ERROR, error: HTTP_ERROR_INVALID_URL);
    return v1->status;
  }
  if ( url.nScheme != INTERNET_SCHEME_HTTP && url.nScheme != INTERNET_SCHEME_HTTPS )
  {
    CleanUpDownload(rc: v1, status: HTTP_ERROR, error: HTTP_ERROR_INVALID_PROTOCOL);
    return v1->status;
  }
  v3 = InternetOpenA(
         lpszAgent: "Half-Life 2",
         dwAccessType: 0,
         lpszProxy: nullptr,
         lpszProxyBypass: nullptr,
         dwFlags: 0);
  v1->hOpenResource = v3;
  if ( v3 == nullptr )
  {
    CleanUpDownload(rc: v1, status: HTTP_ERROR, error: HTTP_ERROR_CANT_BIND_SOCKET);
    return v1->status;
  }
  InternetSetStatusCallback(hInternet: v3, lpfnInternetCallback: (INTERNET_STATUS_CALLBACK)DownloadStatusCallback);
  if ( v1->shouldStop )
  {
    CleanUpDownload(rc: v1, status: HTTP_ABORTED, error: HTTP_ERROR_NONE);
    return v1->status;
  }
  flags = -2076180480;
  if ( url.nScheme == INTERNET_SCHEME_HTTPS )
    flags = -2067779584;
  memset(headers, 0, sizeof(headers));
  v4 = nullptr;
  v5 = 0;
  if ( v1->cachedTimestamp[0] != 0 && (nBytesCached = v1->nBytesCached) != 0 )
  {
    if ( v1->serverURL[0] != 0 )
      V_snprintf(
        pDest: headers,
        maxLen: 256,
        pFormat: "If-Range: %s\nRange: bytes=%d-\nReferer: hl2://%s\n",
        v1->cachedTimestamp,
        nBytesCached,
        v1->serverURL);
    else
      V_snprintf(
        pDest: headers,
        maxLen: 256,
        pFormat: "If-Range: %s\nRange: bytes=%d-\n",
        v1->cachedTimestamp,
        v1->nBytesCached);
  }
  else
  {
    if ( v1->serverURL[0] == 0 )
      goto LABEL_20;
    V_snprintf(pDest: headers, maxLen: 256, pFormat: "Referer: hl2://%s\n", v1->serverURL);
  }
  v5 = -1;
  v4 = headers;
LABEL_20:
  v7 = InternetOpenUrlA(
         hInternet: v1->hOpenResource,
         lpszUrl: fullURL,
         lpszHeaders: v4,
         dwHeadersLength: v5,
         dwFlags: flags,
         dwContext: (DWORD_PTR)v1);
  v1->hDataResource = v7;
  if ( v7 != nullptr )
  {
    if ( !v1->shouldStop )
    {
      voidPtr = 4;
      if ( !HttpQueryInfoA(
              hRequest: v7,
              dwInfoLevel: 0x20000013u,
              lpBuffer: &code,
              lpdwBufferLength: &voidPtr,
              lpdwIndex: nullptr) )
      {
        CleanUpDownload(rc: v1, status: HTTP_ERROR, error: HTTP_ERROR_NO_HEADERS);
        return v1->status;
      }
      if ( code != 200 && code != 206 )
      {
        CleanUpDownload(rc: v1, status: HTTP_ERROR, error: HTTP_ERROR_FILE_NONEXISTENT);
        return v1->status;
      }
      hDataResource = v1->hDataResource;
      voidPtr = 256;
      if ( !HttpQueryInfoA(
              hRequest: hDataResource,
              dwInfoLevel: 0xBu,
              lpBuffer: v1->cachedTimestamp,
              lpdwBufferLength: &voidPtr,
              lpdwIndex: nullptr) )
        v1->cachedTimestamp[0] = 0;
      v8 = code == 206;
      v1->cachedTimestamp[255] = 0;
      if ( !v8 )
        v1->nBytesCached = 0;
      v14 = v1->hDataResource;
      voidPtr = 4;
      if ( !HttpQueryInfoA(
              hRequest: v14,
              dwInfoLevel: 0x20000005u,
              lpBuffer: &code,
              lpdwBufferLength: &voidPtr,
              lpdwIndex: nullptr) )
      {
        CleanUpDownload(rc: v1, status: HTTP_ERROR, error: HTTP_ERROR_ZERO_LENGTH_FILE);
        return v1->status;
      }
      v9 = code;
      v10 = code + v1->nBytesCached;
      v1->nBytesTotal = v10;
      if ( v9 != 0 )
        v1->data = (unsigned __int8 *)MemAlloc_Alloc(nSize: v10);
      cacheData = v1->cacheData;
      if ( cacheData != nullptr )
      {
        nBytesTotal = v1->nBytesCached;
        if ( nBytesTotal != 0 )
        {
          if ( nBytesTotal >= v1->nBytesTotal )
            nBytesTotal = v1->nBytesTotal;
          memcpy(dst: v1->data, src: cacheData, count: nBytesTotal);
        }
      }
      if ( !v1->shouldStop )
      {
        ReadData(rc: v1);
        CleanUpDownload(rc: v1, status: v1->status, error: v1->error);
        return v1->status;
      }
    }
    CleanUpDownload(rc: v1, status: HTTP_ABORTED, error: HTTP_ERROR_NONE);
    return v1->status;
  }
  CleanUpDownload(rc: v1, status: HTTP_ERROR, error: HTTP_ERROR_CANT_CONNECT);
  return v1->status;
}

//------------------------------------------------------------------------------
// Address: 0x1031AA10
// Name: _dynamic_initializer_for__thread_test_tslist_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__thread_test_tslist_command__()
{
  ConCommand::ConCommand(
    this: &thread_test_tslist_command,
    pName: "thread_test_tslist",
    callback: (void (__cdecl *)())thread_test_tslist,
    pHelpString: defaultValue,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__thread_test_tslist_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031AA40
// Name: _dynamic_initializer_for__thread_test_tsqueue_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__thread_test_tsqueue_command__()
{
  ConCommand::ConCommand(
    this: &thread_test_tsqueue_command,
    pName: "thread_test_tsqueue",
    callback: (void (__cdecl *)())thread_test_tsqueue,
    pHelpString: defaultValue,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__thread_test_tsqueue_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10325610
// Name: _dynamic_atexit_destructor_for__thread_test_tslist_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__thread_test_tslist_command__()
{
  ConCommand::~ConCommand(this: &thread_test_tslist_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325620
// Name: _dynamic_atexit_destructor_for__thread_test_tsqueue_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__thread_test_tsqueue_command__()
{
  ConCommand::~ConCommand(this: &thread_test_tsqueue_command);
}

//------------------------------------------------------------------------------
// Address: 0x1031AA70
// Name: _dynamic_initializer_for__threadpool_run_tests_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__threadpool_run_tests_command__()
{
  ConCommand::ConCommand(
    this: &threadpool_run_tests_command,
    pName: "threadpool_run_tests",
    callback: (void (__cdecl *)())threadpool_run_tests,
    pHelpString: defaultValue,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__threadpool_run_tests_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10325630
// Name: _dynamic_atexit_destructor_for__threadpool_run_tests_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__threadpool_run_tests_command__()
{
  ConCommand::~ConCommand(this: &threadpool_run_tests_command);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10164DC0
// Name: void DownloadStatusCallback(void __near *,unsigned long,unsigned long,void __near *,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __stdcall DownloadStatusCallback(
        void *hOpenResource,
        unsigned int dwContext,
        unsigned int dwStatus,
        _DWORD *pStatusInfo,
        unsigned int dwStatusInfoLength)
{
  switch ( dwStatus )
  {
    case 0xAu:
    case 0xBu:
    case 0x14u:
    case 0x15u:
    case 0x1Eu:
    case 0x1Fu:
    case 0x32u:
    case 0x33u:
    case 0x64u:
      if ( pStatusInfo != nullptr )
        pStatusInfo[3] = dwStatus;
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10164E50
// Name: void ReadData(struct RequestContext __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ReadData(RequestContext *rc)
{
  bool v1; // zf
  unsigned int v2; // edi
  unsigned int nBytesCurrent; // ecx
  unsigned __int8 *v4; // eax
  _iobuf *v5; // edi
  unsigned __int8 data[2048]; // [esp+4h] [ebp-938h] BYREF
  char path[260]; // [esp+804h] [ebp-138h] BYREF
  stat buf; // [esp+908h] [ebp-34h] BYREF
  unsigned int dwSize; // [esp+938h] [ebp-4h] BYREF

  v1 = rc->nBytesTotal == 0;
  dwSize = 0;
  if ( v1 )
  {
    rc->status = HTTP_ERROR;
    rc->error = HTTP_ERROR_ZERO_LENGTH_FILE;
  }
  else
  {
    v1 = !rc->shouldStop;
    rc->nBytesCurrent = rc->nBytesCached;
    rc->status = HTTP_FETCH;
    if ( v1 )
    {
      while ( 1 )
      {
        if ( !InternetReadFile(
                hFile: rc->hDataResource,
                lpBuffer: data,
                dwNumberOfBytesToRead: 0x800u,
                lpdwNumberOfBytesRead: &dwSize) )
        {
          rc->status = HTTP_ERROR;
          rc->error = HTTP_ERROR_CONNECTION_CLOSED;
          return;
        }
        v2 = dwSize;
        if ( dwSize == 0 )
          break;
        nBytesCurrent = rc->nBytesCurrent;
        if ( rc->nBytesTotal - nBytesCurrent < dwSize )
          v2 = rc->nBytesTotal - nBytesCurrent;
        v4 = rc->data;
        if ( v4 != nullptr && v2 != 0 )
          memcpy(dst: &v4[nBytesCurrent], src: data, count: v2);
        rc->nBytesCurrent += v2;
        if ( rc->shouldStop )
          goto LABEL_12;
      }
      V_snprintf(pDest: path, maxLen: 260, pFormat: "%s\\%s", rc->basePath, rc->gamePath);
      if ( _stat64i32(name: path, (_stat64i32 *)&buf) == -1 )
      {
        v5 = fopen(file: (_iobuf *)path, mode: "wb");
        if ( v5 != nullptr )
        {
          fwrite(buffer: rc->data, size: rc->nBytesTotal, count: 1u, stream: v5);
          fclose(stream: v5);
        }
      }
      rc->status = HTTP_DONE;
    }
    else
    {
LABEL_12:
      rc->status = HTTP_ABORTED;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10164FB0
// Name: void CleanUpDownload(struct RequestContext __near &,enum HTTPStatus,enum HTTPError)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CleanUpDownload(RequestContext *rc, HTTPStatus status, HTTPError error)
{
  void *hDataResource; // eax
  bool v4; // zf

  rc->status = status;
  hDataResource = rc->hDataResource;
  rc->error = error;
  if ( (hDataResource == nullptr || InternetCloseHandle(hInternet: hDataResource)) && rc->hOpenResource != nullptr )
    InternetCloseHandle(hInternet: rc->hOpenResource);
  v4 = !rc->shouldStop;
  rc->hDataResource = nullptr;
  rc->hOpenResource = nullptr;
  if ( v4 )
  {
    do
      Sleep(dwMilliseconds: 0x64u);
    while ( !rc->shouldStop );
  }
  if ( rc->data != nullptr )
  {
    free(pMem: rc->data);
    rc->data = nullptr;
  }
  rc->threadDone = true;
}

//------------------------------------------------------------------------------
// Address: 0x10165040
// Name: unsigned int DownloadThread(void __near *)
// Source: json
//------------------------------------------------------------------------------
HTTPStatus __cdecl DownloadThread(unsigned int voidPtr)
{
  RequestContext *v1; // esi
  HINTERNET v3; // eax
  char *v4; // eax
  DWORD v5; // ecx
  unsigned int nBytesCached; // edx
  HINTERNET v7; // eax
  bool v8; // zf
  unsigned int v9; // ecx
  unsigned int v10; // eax
  unsigned __int8 *cacheData; // edx
  unsigned int nBytesTotal; // eax
  void *hDataResource; // [esp-18h] [ebp-964h]
  void *v14; // [esp-18h] [ebp-964h]
  char urlBuf[6][256]; // [esp+8h] [ebp-944h] BYREF
  char fullURL[512]; // [esp+608h] [ebp-344h] BYREF
  char headers[256]; // [esp+808h] [ebp-144h] BYREF
  URL_COMPONENTSA url; // [esp+908h] [ebp-44h] BYREF
  unsigned int flags; // [esp+944h] [ebp-8h]
  unsigned int code; // [esp+948h] [ebp-4h] BYREF

  v1 = (RequestContext *)voidPtr;
  url.lpszScheme = urlBuf[0];
  url.lpszHostName = urlBuf[1];
  url.lpszUserName = urlBuf[2];
  url.lpszPassword = urlBuf[3];
  url.lpszUrlPath = urlBuf[4];
  url.lpszExtraInfo = urlBuf[5];
  url.dwStructSize = 60;
  url.dwSchemeLength = 256;
  url.dwHostNameLength = 256;
  url.dwUserNameLength = 256;
  url.dwPasswordLength = 256;
  url.dwUrlPathLength = 256;
  url.dwExtraInfoLength = 256;
  V_snprintf(pDest: fullURL, maxLen: 512, pFormat: "%s%s", (const char *)(voidPtr + 20), (const char *)(voidPtr + 532));
  if ( !InternetCrackUrlA(lpszUrl: fullURL, dwUrlLength: 0x200u, dwFlags: 0, lpUrlComponents: &url) )
  {
    CleanUpDownload(rc: v1, status: HTTP_ERROR, error: HTTP_ERROR_INVALID_URL);
    return v1->status;
  }
  if ( url.nScheme != INTERNET_SCHEME_HTTP && url.nScheme != INTERNET_SCHEME_HTTPS )
  {
    CleanUpDownload(rc: v1, status: HTTP_ERROR, error: HTTP_ERROR_INVALID_PROTOCOL);
    return v1->status;
  }
  v3 = InternetOpenA(
         lpszAgent: "Half-Life 2",
         dwAccessType: 0,
         lpszProxy: nullptr,
         lpszProxyBypass: nullptr,
         dwFlags: 0);
  v1->hOpenResource = v3;
  if ( v3 == nullptr )
  {
    CleanUpDownload(rc: v1, status: HTTP_ERROR, error: HTTP_ERROR_CANT_BIND_SOCKET);
    return v1->status;
  }
  InternetSetStatusCallback(hInternet: v3, lpfnInternetCallback: (INTERNET_STATUS_CALLBACK)DownloadStatusCallback);
  if ( v1->shouldStop )
  {
    CleanUpDownload(rc: v1, status: HTTP_ABORTED, error: HTTP_ERROR_NONE);
    return v1->status;
  }
  flags = -2076180480;
  if ( url.nScheme == INTERNET_SCHEME_HTTPS )
    flags = -2067779584;
  memset(headers, 0, sizeof(headers));
  v4 = nullptr;
  v5 = 0;
  if ( v1->cachedTimestamp[0] != 0 && (nBytesCached = v1->nBytesCached) != 0 )
  {
    if ( v1->serverURL[0] != 0 )
      V_snprintf(
        pDest: headers,
        maxLen: 256,
        pFormat: "If-Range: %s\nRange: bytes=%d-\nReferer: hl2://%s\n",
        v1->cachedTimestamp,
        nBytesCached,
        v1->serverURL);
    else
      V_snprintf(
        pDest: headers,
        maxLen: 256,
        pFormat: "If-Range: %s\nRange: bytes=%d-\n",
        v1->cachedTimestamp,
        v1->nBytesCached);
  }
  else
  {
    if ( v1->serverURL[0] == 0 )
      goto LABEL_20;
    V_snprintf(pDest: headers, maxLen: 256, pFormat: "Referer: hl2://%s\n", v1->serverURL);
  }
  v5 = -1;
  v4 = headers;
LABEL_20:
  v7 = InternetOpenUrlA(
         hInternet: v1->hOpenResource,
         lpszUrl: fullURL,
         lpszHeaders: v4,
         dwHeadersLength: v5,
         dwFlags: flags,
         dwContext: (DWORD_PTR)v1);
  v1->hDataResource = v7;
  if ( v7 != nullptr )
  {
    if ( !v1->shouldStop )
    {
      voidPtr = 4;
      if ( !HttpQueryInfoA(
              hRequest: v7,
              dwInfoLevel: 0x20000013u,
              lpBuffer: &code,
              lpdwBufferLength: &voidPtr,
              lpdwIndex: nullptr) )
      {
        CleanUpDownload(rc: v1, status: HTTP_ERROR, error: HTTP_ERROR_NO_HEADERS);
        return v1->status;
      }
      if ( code != 200 && code != 206 )
      {
        CleanUpDownload(rc: v1, status: HTTP_ERROR, error: HTTP_ERROR_FILE_NONEXISTENT);
        return v1->status;
      }
      hDataResource = v1->hDataResource;
      voidPtr = 256;
      if ( !HttpQueryInfoA(
              hRequest: hDataResource,
              dwInfoLevel: 0xBu,
              lpBuffer: v1->cachedTimestamp,
              lpdwBufferLength: &voidPtr,
              lpdwIndex: nullptr) )
        v1->cachedTimestamp[0] = 0;
      v8 = code == 206;
      v1->cachedTimestamp[255] = 0;
      if ( !v8 )
        v1->nBytesCached = 0;
      v14 = v1->hDataResource;
      voidPtr = 4;
      if ( !HttpQueryInfoA(
              hRequest: v14,
              dwInfoLevel: 0x20000005u,
              lpBuffer: &code,
              lpdwBufferLength: &voidPtr,
              lpdwIndex: nullptr) )
      {
        CleanUpDownload(rc: v1, status: HTTP_ERROR, error: HTTP_ERROR_ZERO_LENGTH_FILE);
        return v1->status;
      }
      v9 = code;
      v10 = code + v1->nBytesCached;
      v1->nBytesTotal = v10;
      if ( v9 != 0 )
        v1->data = (unsigned __int8 *)MemAlloc_Alloc(nSize: v10);
      cacheData = v1->cacheData;
      if ( cacheData != nullptr )
      {
        nBytesTotal = v1->nBytesCached;
        if ( nBytesTotal != 0 )
        {
          if ( nBytesTotal >= v1->nBytesTotal )
            nBytesTotal = v1->nBytesTotal;
          memcpy(dst: v1->data, src: cacheData, count: nBytesTotal);
        }
      }
      if ( !v1->shouldStop )
      {
        ReadData(rc: v1);
        CleanUpDownload(rc: v1, status: v1->status, error: v1->error);
        return v1->status;
      }
    }
    CleanUpDownload(rc: v1, status: HTTP_ABORTED, error: HTTP_ERROR_NONE);
    return v1->status;
  }
  CleanUpDownload(rc: v1, status: HTTP_ERROR, error: HTTP_ERROR_CANT_CONNECT);
  return v1->status;
}

//------------------------------------------------------------------------------
// Address: 0x1031AC00
// Name: _dynamic_initializer_for__thread_test_tslist_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__thread_test_tslist_command__()
{
  ConCommand::ConCommand(
    this: &thread_test_tslist_command,
    pName: "thread_test_tslist",
    callback: thread_test_tslist,
    pHelpString: defaultValue,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__thread_test_tslist_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031AC30
// Name: _dynamic_initializer_for__thread_test_tsqueue_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__thread_test_tsqueue_command__()
{
  ConCommand::ConCommand(
    this: &thread_test_tsqueue_command,
    pName: "thread_test_tsqueue",
    callback: thread_test_tsqueue,
    pHelpString: defaultValue,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__thread_test_tsqueue_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10325800
// Name: _dynamic_atexit_destructor_for__thread_test_tslist_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__thread_test_tslist_command__()
{
  ConCommand::~ConCommand(this: &thread_test_tslist_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325810
// Name: _dynamic_atexit_destructor_for__thread_test_tsqueue_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__thread_test_tsqueue_command__()
{
  ConCommand::~ConCommand(this: &thread_test_tsqueue_command);
}

//------------------------------------------------------------------------------
// Address: 0x1031AC60
// Name: _dynamic_initializer_for__threadpool_run_tests_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__threadpool_run_tests_command__()
{
  ConCommand::ConCommand(
    this: &threadpool_run_tests_command,
    pName: "threadpool_run_tests",
    callback: threadpool_run_tests,
    pHelpString: defaultValue,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__threadpool_run_tests_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10325820
// Name: _dynamic_atexit_destructor_for__threadpool_run_tests_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__threadpool_run_tests_command__()
{
  ConCommand::~ConCommand(this: &threadpool_run_tests_command);
}

} // namespace engine_xlsp
