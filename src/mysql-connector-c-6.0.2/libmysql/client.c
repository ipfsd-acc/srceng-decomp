// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/libmysql/client.c
// Functions: 53
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0040A1E0
// Name: WspiapiStrdup(x)
// Source: json
//------------------------------------------------------------------------------
char *__stdcall WspiapiStrdup(const char *pszString)
{
  char *result; // eax
  unsigned int v2; // kr00_4
  char *v3; // esi

  if ( pszString == nullptr )
    return nullptr;
  v2 = strlen(pszString);
  result = (char *)calloc(count: 1u, size: v2 + 1);
  v3 = result;
  if ( result != nullptr )
  {
    strcpy_s(_Dst: result, _SizeInBytes: v2 + 1, _Src: pszString);
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040A230
// Name: WspiapiParseV4Address(x,x)
// Source: json
//------------------------------------------------------------------------------
BOOL __stdcall WspiapiParseV4Address(const char *pszAddress, PDWORD pdwAddress)
{
  char v2; // al
  int v3; // edx
  const char *v4; // ecx
  unsigned int v6; // eax

  v2 = *pszAddress;
  v3 = 0;
  v4 = pszAddress;
  if ( *pszAddress == 0 )
    return false;
  do
  {
    if ( v2 == 46 )
      ++v3;
    v2 = *++v4;
  }
  while ( v2 != 0 );
  if ( v3 != 3 )
    return false;
  v6 = inet_addr(cp: pszAddress);
  if ( v6 == -1 )
    return false;
  *pdwAddress = v6;
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x0040A280
// Name: WspiapiNewAddrInfo(x,x,x,x)
// Source: json
//------------------------------------------------------------------------------
struct addrinfo *__stdcall WspiapiNewAddrInfo(int iSocketType, int iProtocol, WORD wPort, DWORD dwAddress)
{
  unsigned __int8 *v4; // esi
  unsigned __int8 *v5; // eax

  v4 = calloc(count: 1u, size: 0x20u);
  if ( v4 == nullptr )
    return nullptr;
  v5 = calloc(count: 1u, size: 0x10u);
  if ( v5 == nullptr )
  {
    free(pMem: v4);
    return nullptr;
  }
  *(_WORD *)v5 = 2;
  *((_WORD *)v5 + 1) = wPort;
  *((_DWORD *)v5 + 1) = dwAddress;
  *((_DWORD *)v4 + 6) = v5;
  *((_DWORD *)v4 + 1) = 2;
  *((_DWORD *)v4 + 2) = iSocketType;
  *((_DWORD *)v4 + 3) = iProtocol;
  *((_DWORD *)v4 + 4) = 16;
  return (struct addrinfo *)v4;
}

//------------------------------------------------------------------------------
// Address: 0x0040A2F0
// Name: WspiapiQueryDNS(x,x,x,x,x,x)
// Source: json
//------------------------------------------------------------------------------
int __stdcall WspiapiQueryDNS(
        _TEB_ACTIVE_FRAME *result,
        int iSocketType,
        int iProtocol,
        WORD wPort,
        char *pszAlias,
        struct addrinfo **a6)
{
  struct addrinfo **v6; // esi
  struct hostent *v7; // eax
  const char **p_h_name; // ecx
  DWORD **h_addr_list; // edi
  DWORD *v10; // eax
  struct addrinfo *v11; // eax
  int v12; // eax
  struct hostent *v13; // [esp+1Ch] [ebp+18h]

  v6 = a6;
  *a6 = nullptr;
  *pszAlias = 0;
  v7 = gethostbyname(name: (const char *)result);
  p_h_name = (const char **)&v7->h_name;
  v13 = v7;
  if ( v7 != nullptr )
  {
    if ( v7->h_addrtype == 2
      && v7->h_length == 4
      && (h_addr_list = (DWORD **)v7->h_addr_list, v10 = *h_addr_list, *h_addr_list != nullptr) )
    {
      while ( 1 )
      {
        v11 = WspiapiNewAddrInfo(iSocketType, iProtocol, wPort, dwAddress: *v10);
        *v6 = v11;
        if ( v11 == nullptr )
          return 8;
        ++h_addr_list;
        v6 = (struct addrinfo **)((char *)v11 + 28);
        v10 = *h_addr_list;
        if ( *h_addr_list == nullptr )
        {
          p_h_name = (const char **)&v13->h_name;
          goto LABEL_8;
        }
      }
    }
    else
    {
LABEL_8:
      strncpy_s(_Dst: pszAlias, _SizeInBytes: 0x401u, _Src: *p_h_name, _Count: 0x400u);
      return 0;
    }
  }
  else
  {
    switch ( WSAGetLastError() )
    {
      case 11002:
        v12 = 11002;
        break;
      case 11003:
        v12 = 11003;
        break;
      default:
        v12 = 11001;
        break;
    }
  }
  return v12;
}

//------------------------------------------------------------------------------
// Address: 0x0040A3E0
// Name: WspiapiLookupNode(x,x,x,x,x,x)
// Source: json
//------------------------------------------------------------------------------
int __stdcall WspiapiLookupNode(
        const char *pszNodeName,
        int iSocketType,
        int iProtocol,
        WORD wPort,
        BOOL bAI_CANONNAME,
        struct addrinfo **pptResult)
{
  char *v6; // ebp
  char *v7; // edi
  int result; // eax
  int DNS; // esi
  char *v10; // [esp-8h] [ebp-830h]
  int v11; // [esp+14h] [ebp-814h]
  char _Dst[1028]; // [esp+1Ch] [ebp-80Ch] BYREF
  char pszString[1028]; // [esp+420h] [ebp-408h] BYREF

  v11 = 0;
  memset(_Dst, 0, 1025);
  memset(pszString, 0, 1025);
  v6 = _Dst;
  v7 = pszString;
  strncpy_s(_Dst, _SizeInBytes: 0x401u, _Src: pszNodeName, _Count: 0x400u);
  result = WspiapiQueryDNS(
             result: (_TEB_ACTIVE_FRAME *)pszNodeName,
             iSocketType,
             iProtocol,
             wPort,
             pszAlias: pszString,
             a6: pptResult);
  DNS = result;
  if ( result == 0 )
  {
    while ( *pptResult == nullptr )
    {
      if ( strlen(v7) == 0 )
        return 11003;
      if ( strcmp(v6, v7) == 0 )
        return 11003;
      if ( ++v11 == 16 )
        return 11003;
      v10 = v6;
      v6 = v7;
      v7 = v10;
      DNS = WspiapiQueryDNS(
              result: (_TEB_ACTIVE_FRAME *)pszNodeName,
              iSocketType,
              iProtocol,
              wPort,
              pszAlias: v10,
              a6: pptResult);
      if ( DNS != 0 )
        return DNS;
    }
    if ( DNS != 0 )
      return DNS;
    if ( !bAI_CANONNAME )
      return DNS;
    *((_DWORD *)*pptResult + 5) = WspiapiStrdup(pszString: v7);
    result = 8;
    if ( *((_DWORD *)*pptResult + 5) != 0 )
      return DNS;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040A570
// Name: WspiapiClone(x,x)
// Source: json
//------------------------------------------------------------------------------
int __stdcall WspiapiClone(WORD wPort, struct addrinfo *ptResult)
{
  struct addrinfo *v2; // edi
  int v3; // ebx
  int v4; // ebp
  unsigned __int8 *v5; // esi
  unsigned __int8 *v6; // eax

  v2 = ptResult;
  if ( ptResult == nullptr )
    return 0;
  while ( 1 )
  {
    v3 = *(_DWORD *)(*((_DWORD *)v2 + 6) + 4);
    v4 = *((_DWORD *)v2 + 3);
    v5 = calloc(count: 1u, size: 0x20u);
    if ( v5 == nullptr )
      break;
    v6 = calloc(count: 1u, size: 0x10u);
    if ( v6 == nullptr )
    {
      free(pMem: v5);
      return 8;
    }
    *((_DWORD *)v6 + 1) = v3;
    *(_WORD *)v6 = 2;
    *((_WORD *)v6 + 1) = wPort;
    *((_DWORD *)v5 + 1) = 2;
    *((_DWORD *)v5 + 2) = 2;
    *((_DWORD *)v5 + 3) = v4;
    *((_DWORD *)v5 + 4) = 16;
    *((_DWORD *)v5 + 6) = v6;
    *((_DWORD *)v5 + 7) = *((_DWORD *)v2 + 7);
    *((_DWORD *)v2 + 7) = v5;
    v2 = *((struct addrinfo **)v5 + 7);
    if ( v2 == nullptr )
      return 0;
  }
  return 8;
}

//------------------------------------------------------------------------------
// Address: 0x0040A610
// Name: WspiapiLegacyFreeAddrInfo(x)
// Source: json
//------------------------------------------------------------------------------
void __stdcall WspiapiLegacyFreeAddrInfo(struct addrinfo *ptHead)
{
  struct addrinfo *v1; // esi
  struct addrinfo *i; // edi

  v1 = ptHead;
  for ( i = ptHead; v1 != nullptr; i = v1 )
  {
    if ( *((_DWORD *)v1 + 5) != 0 )
      free(pMem: *((void **)v1 + 5));
    if ( *((_DWORD *)v1 + 6) != 0 )
      free(pMem: *((void **)v1 + 6));
    v1 = *((struct addrinfo **)v1 + 7);
    free(pMem: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040A660
// Name: WspiapiLegacyGetAddrInfo(x,x,x,x)
// Source: json
//------------------------------------------------------------------------------
int __stdcall WspiapiLegacyGetAddrInfo(
        _EH4_EXCEPTION_REGISTRATION_RECORD *result,
        const char *pszServiceName,
        int *a3,
        struct addrinfo **pptResult)
{
  const char *v4; // edi
  int v5; // ebx
  unsigned int v6; // esi
  u_short v7; // bp
  int v9; // ecx
  struct servent *v10; // eax
  struct servent *v11; // eax
  u_short Length; // ax
  u_long v13; // edi
  struct addrinfo *v14; // eax
  char *v15; // eax
  int iError; // [esp+10h] [ebp-1Ch]
  int bClone; // [esp+14h] [ebp-18h]
  u_short wUdpPort; // [esp+18h] [ebp-14h]
  int iProtocol; // [esp+1Ch] [ebp-10h]
  char *pc; // [esp+20h] [ebp-Ch] BYREF
  int wTcpPort; // [esp+24h] [ebp-8h]
  unsigned int dwAddress; // [esp+28h] [ebp-4h] BYREF

  v4 = (const char *)result;
  LOBYTE(v5) = 0;
  v6 = 0;
  v7 = 0;
  iError = 0;
  iProtocol = 0;
  dwAddress = 0;
  pc = nullptr;
  bClone = 0;
  wTcpPort = 0;
  wUdpPort = 0;
  *pptResult = nullptr;
  if ( result == nullptr && pszServiceName == nullptr )
    return 11001;
  if ( a3 != nullptr )
  {
    if ( a3[4] != 0 || a3[5] != 0 || a3[6] != 0 || a3[7] != 0 )
      return 11003;
    v5 = *a3;
    if ( (*a3 & 2) != 0 && result == nullptr )
      return 10022;
    v9 = a3[1];
    if ( v9 != 0 && v9 != 2 )
      return 10047;
    v6 = a3[2];
    if ( v6 >= 4 )
      return 10044;
    iProtocol = a3[3];
  }
  if ( pszServiceName != nullptr )
  {
    v7 = strtoul(nptr: pszServiceName, endptr: &pc, ibase: 10);
    if ( *pc != 0 )
    {
      if ( v6 == 0 || v6 == 2 )
      {
        v10 = getservbyname(name: pszServiceName, proto: "udp");
        if ( v10 != nullptr )
        {
          wUdpPort = v10[1].Length;
          v7 = wUdpPort;
        }
      }
      if ( v6 <= 1 && (v11 = getservbyname(name: pszServiceName, proto: "tcp")) != nullptr )
      {
        Length = v11[1].Length;
        v7 = Length;
      }
      else
      {
        Length = wTcpPort;
      }
      if ( v7 == 0 )
        return v6 != 0 ? 10109 : 11001;
      if ( v6 == 0 )
      {
        v6 = (Length == 0) + 1;
        if ( Length == 0 || (bClone = 1, wUdpPort == 0) )
          bClone = 0;
      }
      v4 = (const char *)result;
    }
    else
    {
      wUdpPort = htons(hostshort: v7);
      v7 = wUdpPort;
      if ( v6 == 0 )
      {
        v6 = 1;
        bClone = 1;
      }
    }
  }
  if ( v4 == nullptr )
  {
    v13 = htonl(hostlong: (v5 & 1) != 0 ? 0 : 2130706433);
LABEL_49:
    v14 = WspiapiNewAddrInfo(iSocketType: v6, iProtocol, wPort: v7, dwAddress: v13);
    *pptResult = v14;
    if ( v14 == nullptr
      || result != nullptr
      && (*(_DWORD *)v14 |= 4u, (v5 & 2) != 0)
      && (v15 = inet_ntoa(in: (struct in_addr)v13),
          *((_DWORD *)*pptResult + 5) = WspiapiStrdup(pszString: v15),
          *((_DWORD *)*pptResult + 5) == 0) )
    {
      iError = 8;
      goto LABEL_45;
    }
    goto LABEL_43;
  }
  if ( WspiapiParseV4Address(pszAddress: v4, pdwAddress: &dwAddress) )
  {
    v13 = dwAddress;
    goto LABEL_49;
  }
  if ( (v5 & 4) == 0 )
  {
    iError = WspiapiLookupNode(pszNodeName: v4, iSocketType: v6, iProtocol, wPort: v7, bAI_CANONNAME: v5 & 2, pptResult);
    if ( iError != 0 )
      goto LABEL_45;
LABEL_43:
    if ( bClone == 0 )
      return iError;
    iError = WspiapiClone(wPort: wUdpPort, ptResult: *pptResult);
    if ( iError == 0 )
      return iError;
    goto LABEL_45;
  }
  iError = 11001;
LABEL_45:
  WspiapiLegacyFreeAddrInfo(ptHead: *pptResult);
  *pptResult = nullptr;
  return iError;
}

//------------------------------------------------------------------------------
// Address: 0x0040A950
// Name: WspiapiLegacyGetNameInfo(x,x,x,x,x,x,x)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
unsigned int __stdcall WspiapiLegacyGetNameInfo(
        int tSocketLength,
        unsigned int a2,
        char *pszNodeName,
        unsigned int tNodeLength,
        char *pszServiceName,
        unsigned int tServiceLength,
        char iFlags)
{
  char *v7; // edx
  int v9; // ecx
  u_short v10; // si
  struct servent *v11; // eax
  char *v12; // eax
  char *v13; // esi
  struct in_addr v14; // eax
  char *v15; // eax
  struct hostent *v16; // eax
  unsigned __int8 *h_name; // eax
  const char *v18; // esi
  _BYTE *v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // [esp-10h] [ebp-34h]
  int v23; // [esp-10h] [ebp-34h]
  char addr[4]; // [esp+8h] [ebp-1Ch] BYREF
  char *pszService; // [esp+Ch] [ebp-18h]
  char *_Dst; // [esp+10h] [ebp-14h]
  int v27; // [esp+14h] [ebp-10h]
  char szBuffer[6]; // [esp+18h] [ebp-Ch] OVERLAPPED BYREF

  v7 = pszNodeName;
  strcpy(szBuffer, "65535");
  _Dst = pszServiceName;
  pszService = szBuffer;
  if ( tSocketLength == 0 || a2 < 0x10 )
    return 11003;
  if ( *(_WORD *)tSocketLength != 2 )
    return 10047;
  if ( pszNodeName != nullptr && tNodeLength != 0 || pszServiceName != nullptr && tServiceLength != 0 )
  {
    v9 = iFlags & 2;
    v27 = v9;
    if ( (iFlags & 2) != 0 && (iFlags & 4) != 0 )
      return 10022;
    if ( pszServiceName == nullptr || tServiceLength == 0 )
      goto LABEL_23;
    v10 = *(_WORD *)(tSocketLength + 2);
    if ( (iFlags & 8) != 0 )
    {
      v22 = ntohs(netshort: *(_WORD *)(tSocketLength + 2));
      sprintf_s(string: szBuffer, sizeInBytes: 6u, format: "%u", v22);
    }
    else
    {
      v11 = getservbyport(port: v10, proto: (iFlags & 0x10) != 0 ? "udp" : nullptr);
      if ( v11 != nullptr )
      {
        v12 = *(char **)&v11->Length;
        if ( v12 != nullptr )
        {
          v13 = v12;
LABEL_21:
          if ( tServiceLength <= strlen(v13) )
            return 11003;
          strcpy_s(_Dst, _SizeInBytes: tServiceLength, _Src: v13);
          v7 = pszNodeName;
          v9 = v27;
LABEL_23:
          if ( v7 == nullptr || tNodeLength == 0 )
            return 0;
          v14 = *(struct in_addr *)(tSocketLength + 4);
          *(struct in_addr *)addr = v14;
          if ( v9 != 0 )
          {
            v15 = inet_ntoa(in: v14);
LABEL_39:
            v18 = v15;
            goto LABEL_40;
          }
          v16 = gethostbyaddr(addr, len: 4, type: 2);
          if ( v16 != nullptr )
          {
            h_name = (unsigned __int8 *)v16->h_name;
            if ( h_name != nullptr )
            {
              v18 = (const char *)h_name;
              if ( (iFlags & 1) != 0 )
              {
                strchr(string: h_name, chr: 0x2Eu);
                if ( v19 != nullptr )
                  *v19 = 0;
              }
LABEL_40:
              if ( tNodeLength > strlen(v18) )
              {
                strcpy_s(_Dst: pszNodeName, _SizeInBytes: tNodeLength, _Src: v18);
                return 0;
              }
              return 11003;
            }
          }
          if ( (iFlags & 4) == 0 )
          {
            v15 = inet_ntoa(in: *(struct in_addr *)addr);
            goto LABEL_39;
          }
          v20 = WSAGetLastError() - 11001;
          if ( v20 != 0 )
          {
            v21 = v20 - 1;
            if ( v21 == 0 )
              return 11002;
            if ( v21 == 1 )
              return 11003;
          }
          return 11001;
        }
      }
      v23 = ntohs(netshort: v10);
      sprintf_s(string: szBuffer, sizeInBytes: 6u, format: "%u", v23);
    }
    v13 = pszService;
    goto LABEL_21;
  }
  return 11001;
}

//------------------------------------------------------------------------------
// Address: 0x0040AC00
// Name: WspiapiLoad(x)
// Source: json
//------------------------------------------------------------------------------
_EH4_SCOPETABLE *__stdcall WspiapiLoad(_EH4_SCOPETABLE *result)
{
  _EH4_SCOPETABLE *v1; // eax
  HMODULE LibraryA; // eax
  HMODULE v3; // esi
  HMODULE v4; // eax
  int v5; // edi
  int ProcAddress; // eax
  LPCSTR lpProcName; // [esp+0h] [ebp-230h]
  _DWORD v8[2]; // [esp+4h] [ebp-22Ch]
  int (__stdcall *v9)(int, int, char *, unsigned int, char *, unsigned int, int); // [esp+Ch] [ebp-224h]
  const char *v10; // [esp+10h] [ebp-220h]
  void (__stdcall *v11)(struct addrinfo *); // [esp+14h] [ebp-21Ch]
  _ALTERNATIVE_ARCHITECTURE_TYPE Path[67]; // [esp+18h] [ebp-218h] BYREF
  char Buffer[264]; // [esp+124h] [ebp-10Ch] BYREF

  lpProcName = "getaddrinfo";
  v8[0] = WspiapiLegacyGetAddrInfo;
  v8[1] = "getnameinfo";
  v9 = (int (__stdcall *)(int, int, char *, unsigned int, char *, unsigned int, int))WspiapiLegacyGetNameInfo;
  v10 = "freeaddrinfo";
  v11 = WspiapiLegacyFreeAddrInfo;
  if ( `WspiapiLoad'::`2'::bInitialized != 0 )
    return (_EH4_SCOPETABLE *)*(&off_48F274 + 2 * (unsigned __int16)result);
  if ( GetSystemDirectoryA(lpBuffer: Buffer, uSize: 0x104u) != 0 )
  {
    strcpy_s(_Dst: (char *)Path, _SizeInBytes: 0x10Cu, _Src: Buffer);
    strcat_s(_Dst: (char *)Path, _SizeInBytes: 0x10Cu, _Src: "\\ws2_32");
    LibraryA = LoadLibraryA(lpLibFileName: (LPCSTR)Path);
    v3 = LibraryA;
    if ( LibraryA != nullptr )
    {
      if ( (int)GetProcAddress(hModule: LibraryA, lpProcName: "getaddrinfo") != 0 )
        goto LABEL_9;
      FreeLibrary(hLibModule: v3);
    }
    strcpy_s(_Dst: (char *)Path, _SizeInBytes: 0x10Cu, _Src: Buffer);
    strcat_s(_Dst: (char *)Path, _SizeInBytes: 0x10Cu, _Src: "\\wship6");
    v4 = LoadLibraryA(lpLibFileName: (LPCSTR)Path);
    v3 = v4;
    if ( v4 != nullptr )
    {
      if ( (int)GetProcAddress(hModule: v4, lpProcName: "getaddrinfo") == 0 )
      {
LABEL_14:
        FreeLibrary(hLibModule: v3);
        goto LABEL_13;
      }
LABEL_9:
      v5 = 0;
      while ( 1 )
      {
        ProcAddress = (int)GetProcAddress(hModule: v3, lpProcName: (LPCSTR)v8[2 * v5 - 1]);
        v8[2 * v5] = ProcAddress;
        if ( ProcAddress == 0 )
          goto LABEL_14;
        if ( ++v5 >= 3 )
        {
          off_48F274 = (int (__stdcall *)(tagShutdownType, tagShutdownType, int, struct addrinfo **))v8[0];
          off_48F27C = v9;
          off_48F284 = v11;
          break;
        }
      }
    }
  }
LABEL_13:
  v1 = (_EH4_SCOPETABLE *)*(&off_48F274 + 2 * (unsigned __int16)result);
  `WspiapiLoad'::`2'::bInitialized = 1;
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x0040ADB0
// Name: WspiapiGetAddrInfo(x,x,x,x)
// Source: json
//------------------------------------------------------------------------------
_EH4_EXCEPTION_REGISTRATION_RECORD *__stdcall WspiapiGetAddrInfo(
        _EH4_EXCEPTION_REGISTRATION_RECORD *result,
        tagShutdownType servname,
        int a3,
        int a4)
{
  _EH4_SCOPETABLE *GSCookieOffset; // eax
  int v5; // esi

  GSCookieOffset = (_EH4_SCOPETABLE *)`WspiapiGetAddrInfo'::`2'::pfGetAddrInfo.GSCookieOffset;
  if ( `WspiapiGetAddrInfo'::`2'::pfGetAddrInfo.GSCookieOffset == 0 )
  {
    GSCookieOffset = WspiapiLoad(result: nullptr);
    `WspiapiGetAddrInfo'::`2'::pfGetAddrInfo.GSCookieOffset = (DWORD)GSCookieOffset;
  }
  v5 = ((int (__stdcall *)(_EH4_EXCEPTION_REGISTRATION_RECORD *, tagShutdownType, int, int))GSCookieOffset)(
         a1: result,
         a2: servname,
         a3,
         a4);
  WSASetLastError(iError: v5);
  return (_EH4_EXCEPTION_REGISTRATION_RECORD *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x0040ADF0
// Name: WspiapiFreeAddrInfo(x)
// Source: json
//------------------------------------------------------------------------------
void __stdcall WspiapiFreeAddrInfo(struct addrinfo *ai)
{
  _EH4_SCOPETABLE *Length; // eax

  Length = (_EH4_SCOPETABLE *)`WspiapiFreeAddrInfo'::`2'::pfFreeAddrInfo.Length;
  if ( `WspiapiFreeAddrInfo'::`2'::pfFreeAddrInfo.Length == 0 )
  {
    Length = WspiapiLoad(result: (_EH4_SCOPETABLE *)2);
    `WspiapiFreeAddrInfo'::`2'::pfFreeAddrInfo.Length = (unsigned int)Length;
  }
  ((void (__stdcall *)(struct addrinfo *))Length)(a1: ai);
}

//------------------------------------------------------------------------------
// Address: 0x0040AE10
// Name: _my_connect
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_connect(SOCKET s, struct sockaddr *name, int namelen)
{
  return connect(s, name, namelen);
}

//------------------------------------------------------------------------------
// Address: 0x0040AE30
// Name: _set_mysql_error
// Source: json
//------------------------------------------------------------------------------
void __cdecl set_mysql_error(int a1, unsigned int a2)
{
  int v2; // ecx

  if ( a1 != 0 )
  {
    *(_DWORD *)(a1 + 88) = a2;
    strmov(dst: a1 + 95);
  }
  else
  {
    mysql_server_last_errno = a2;
  }
  strmov(dst: v2);
}

//------------------------------------------------------------------------------
// Address: 0x0040AE90
// Name: _net_clear_error
// Source: json
//------------------------------------------------------------------------------
void __stdcall net_clear_error(const char *net)
{
  *((_DWORD *)net + 22) = 0;
  *((_BYTE *)net + 95) = 0;
  strmov(dst: not_error_sqlstate);
}

//------------------------------------------------------------------------------
// Address: 0x0040AEC0
// Name: set_mysql_extended_error
// Source: json
//------------------------------------------------------------------------------
void __usercall set_mysql_extended_error(int a1@<eax>, int a2@<ecx>, tagShutdownType sqlstate, _CONTEXT *format, ...)
{
  va_list va; // [esp+10h] [ebp+Ch] BYREF

  va_start(va, format);
  *(_DWORD *)(a2 + 88) = a1;
  my_vsnprintf(to: (_EXCEPTION_RECORD *)(a2 + 95), n: (_EXCEPTION_REGISTRATION_RECORD *)0x1FF, fmt: format, ap: va);
  strmov(dst: sqlstate);
}

//------------------------------------------------------------------------------
// Address: 0x0040AF00
// Name: _create_named_pipe
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __cdecl create_named_pipe(__lc_time_data *mysql, int a2, const char **a3, char **a4)
{
  char *v4; // ebx
  const char *v5; // ebp
  HANDLE FileA; // eax
  void *v7; // esi
  DWORD LastError; // eax
  DWORD v9; // eax
  char **v10; // eax
  LPSECURITY_ATTRIBUTES v11; // [esp-10h] [ebp-438h] OVERLAPPED BYREF
  DWORD v12; // [esp+40h] [ebp-3E8h]
  DWORD v13; // [esp+44h] [ebp-3E4h]
  HANDLE v14; // [esp+48h] [ebp-3E0h]
  char v15; // [esp+423h] [ebp-5h]

  v4 = *a4;
  *(_DWORD *)&v11.gap18[8] = mysql;
  v5 = *a3;
  *(_DWORD *)&v11.gap18[24] = a3;
  *(_DWORD *)&v11.gap18[20] = a4;
  if ( v4 == nullptr || *v4 == 0 )
    v4 = mysql_unix_port;
  if ( v5 == nullptr || strcmp(v5, "localhost") == 0 )
    v5 = ".";
  v11.exception_address = 0;
  v11.exception_record = (unsigned int)v4;
  v11.exception_flags = (unsigned int)"\\pipe\\";
  v11.exception_number = (unsigned int)v5;
  v15 = 0;
  strxnmov(dst: &v11.gap18[28], len: 0x3FFu, src: (tagShutdownType)"\\\\");
  *(_DWORD *)&v11.gap18[12] = 0;
  while ( 1 )
  {
    v11.exception_address = 0;
    v11.exception_record = 0;
    v11.exception_flags = 3;
    v11.exception_number = 0;
    FileA = CreateFileA(
              lpFileName: &v11.gap18[28],
              dwDesiredAccess: 0xC0000000,
              dwShareMode: 0,
              lpSecurityAttributes: v11,
              dwCreationDisposition: v12,
              dwFlagsAndAttributes: v13,
              hTemplateFile: v14);
    v7 = FileA;
    if ( FileA != (HANDLE)-1 )
      break;
    if ( GetLastError() != 231 )
      goto LABEL_12;
    if ( !WaitNamedPipeA(lpNamedPipeName: &v11.gap18[28], nTimeOut: 1000 * a2) )
    {
      LastError = GetLastError();
      set_mysql_extended_error(
        a1: 2016,
        a2: *(int *)&v11.gap18[8],
        sqlstate: unknown_sqlstate,
        format: (_CONTEXT *)off_48F350,
        v5,
        v4,
        LastError);
      return;
    }
    ++*(_DWORD *)&v11.gap18[12];
    if ( *(int *)&v11.gap18[12] >= 100 )
    {
LABEL_12:
      v11.exception_address = GetLastError();
      set_mysql_extended_error(
        a1: 2017,
        a2: *(int *)&v11.gap18[8],
        sqlstate: unknown_sqlstate,
        format: (_CONTEXT *)off_48F354,
        v5,
        v4,
        v11.exception_address);
      return;
    }
  }
  *(_DWORD *)&v11.gap18[16] = 0;
  if ( SetNamedPipeHandleState(
         hNamedPipe: FileA,
         lpMode: (LPDWORD)&v11.gap18[16],
         lpMaxCollectionCount: nullptr,
         lpCollectDataTimeout: nullptr) )
  {
    v10 = *(char ***)&v11.gap18[20];
    **(_DWORD **)&v11.gap18[24] = v5;
    *v10 = v4;
  }
  else
  {
    CloseHandle(hObject: v7);
    v9 = GetLastError();
    set_mysql_extended_error(
      a1: 2018,
      a2: *(int *)&v11.gap18[8],
      sqlstate: unknown_sqlstate,
      format: (_CONTEXT *)off_48F358,
      v5,
      v4,
      v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040B100
// Name: _create_shared_memory
// Source: json
//------------------------------------------------------------------------------
char *__cdecl create_shared_memory(_DWORD *net, _DWORD *a2, unsigned int connect_timeout)
{
  const char *v3; // ebx
  char *v4; // eax
  char *v5; // esi
  void *v6; // edi
  int v7; // ecx
  int v8; // ecx
  int v9; // ecx
  HANDLE v10; // eax
  int v11; // ecx
  HANDLE v12; // eax
  HANDLE v13; // ebx
  int v15; // ecx
  int v16; // ecx
  int v17; // ecx
  int v18; // ecx
  int v19; // ecx
  HANDLE v20; // ebp
  LPCVOID v21; // [esp-4h] [ebp-68h]
  unsigned int error_allow; // [esp+10h] [ebp-54h]
  DWORD error_code; // [esp+14h] [ebp-50h]
  char *handle_map; // [esp+18h] [ebp-4Ch]
  HANDLE event_connect_answer; // [esp+1Ch] [ebp-48h]
  HANDLE event_client_wrote; // [esp+20h] [ebp-44h]
  HANDLE event_server_wrote; // [esp+24h] [ebp-40h]
  HANDLE event_client_read; // [esp+2Ch] [ebp-38h]
  char *handle_connect_map; // [esp+30h] [ebp-34h]
  void *handle_file_map; // [esp+34h] [ebp-30h]
  HANDLE event_connect_request; // [esp+3Ch] [ebp-28h]
  void *handle_connect_file_map; // [esp+40h] [ebp-24h]

  v3 = (const char *)net[211];
  event_connect_answer = nullptr;
  handle_connect_file_map = nullptr;
  handle_connect_map = nullptr;
  handle_map = nullptr;
  event_server_wrote = nullptr;
  event_client_wrote = nullptr;
  event_client_read = nullptr;
  error_allow = 0;
  error_code = 0;
  v4 = (char *)my_malloc(size: strlen(v3) + 32, my_flags: 8);
  v5 = v4;
  if ( v4 == nullptr )
    return handle_map;
  v6 = strxmov(dst: v4, src: (int)"Global\\", a3: (int)v3);
  strmov(dst: v7);
  event_connect_request = OpenEventA(dwDesiredAccess: 0x100002u, bInheritHandle: false, lpName: v5);
  if ( event_connect_request == nullptr )
  {
    error_allow = 2038;
    goto err_1;
  }
  strmov(dst: v8);
  event_connect_answer = OpenEventA(dwDesiredAccess: 0x100002u, bInheritHandle: false, lpName: v5);
  if ( event_connect_answer == nullptr )
  {
    error_allow = 2039;
    goto err_1;
  }
  strmov(dst: v9);
  v10 = OpenFileMappingA(dwDesiredAccess: 2u, bInheritHandle: false, lpName: v5);
  handle_connect_file_map = v10;
  if ( v10 == nullptr )
  {
    error_allow = 2040;
    goto err_1;
  }
  handle_connect_map = (char *)MapViewOfFile(
                                 hFileMappingObject: v10,
                                 dwDesiredAccess: 2u,
                                 dwFileOffsetHigh: 0,
                                 dwFileOffsetLow: 0,
                                 dwNumberOfBytesToMap: 4u);
  if ( handle_connect_map == nullptr )
  {
    error_allow = 2041;
    goto err_1;
  }
  if ( !SetEvent(hEvent: event_connect_request) )
  {
    error_allow = 2046;
    goto err_1;
  }
  if ( WaitForSingleObject(hHandle: event_connect_answer, dwMilliseconds: 1000 * connect_timeout) != 0 )
  {
    error_allow = 2045;
    goto err_1;
  }
  int10_to_str(result: *(_strflt **)handle_connect_map);
  v6 = strxmov(dst: v5, src: (int)"Global\\", a3: (int)v3);
  strmov(dst: v11);
  v12 = OpenFileMappingA(dwDesiredAccess: 2u, bInheritHandle: false, lpName: v5);
  handle_file_map = v12;
  if ( v12 == nullptr )
  {
    error_allow = 2042;
LABEL_16:
    v13 = nullptr;
    goto LABEL_17;
  }
  handle_map = (char *)MapViewOfFile(
                         hFileMappingObject: v12,
                         dwDesiredAccess: 2u,
                         dwFileOffsetHigh: 0,
                         dwFileOffsetLow: 0,
                         dwNumberOfBytesToMap: 0x3E84u);
  if ( handle_map == nullptr )
  {
    error_allow = 2043;
    goto LABEL_16;
  }
  strmov(dst: v15);
  event_server_wrote = OpenEventA(dwDesiredAccess: 0x100002u, bInheritHandle: false, lpName: v5);
  if ( event_server_wrote == nullptr )
  {
    error_allow = 2044;
    goto LABEL_16;
  }
  strmov(dst: v16);
  v13 = OpenEventA(dwDesiredAccess: 0x100002u, bInheritHandle: false, lpName: v5);
  if ( v13 != nullptr )
  {
    strmov(dst: v17);
    event_client_wrote = OpenEventA(dwDesiredAccess: 0x100002u, bInheritHandle: false, lpName: v5);
    if ( event_client_wrote != nullptr )
    {
      strmov(dst: v18);
      event_client_read = OpenEventA(dwDesiredAccess: 0x100002u, bInheritHandle: false, lpName: v5);
      if ( event_client_read != nullptr )
      {
        strmov(dst: v19);
        v20 = OpenEventA(dwDesiredAccess: 0x100002u, bInheritHandle: false, lpName: v5);
        if ( v20 != nullptr )
        {
          SetEvent(hEvent: v13);
          *a2 = vio_new_win32shared_memory(
                  a1: (int)a2,
                  a2: (int)handle_file_map,
                  a3: (int)handle_map,
                  a4: (int)event_server_wrote,
                  a5: (int)v13,
                  a6: (int)event_client_wrote,
                  a7: (int)event_client_read,
                  dst: (int)v20);
          goto err_1;
        }
        error_allow = 2044;
      }
      else
      {
        error_allow = 2044;
      }
    }
    else
    {
      error_allow = 2044;
    }
  }
  else
  {
    error_allow = 2044;
  }
LABEL_17:
  error_code = GetLastError();
  if ( v13 != nullptr )
    CloseHandle(hObject: v13);
  if ( event_server_wrote != nullptr )
    CloseHandle(hObject: event_server_wrote);
  if ( event_client_read != nullptr )
    CloseHandle(hObject: event_client_read);
  if ( event_client_wrote != nullptr )
    CloseHandle(hObject: event_client_wrote);
  if ( handle_map != nullptr )
  {
    v21.cElems = (unsigned int)handle_map;
    UnmapViewOfFile(lpBaseAddress: v21);
  }
  if ( handle_file_map != nullptr )
    CloseHandle(hObject: handle_file_map);
err_1:
  my_no_flags_free();
  if ( error_allow != 0 )
    error_code = GetLastError();
  if ( event_connect_request != nullptr )
    CloseHandle(hObject: event_connect_request);
  if ( event_connect_answer != nullptr )
    CloseHandle(hObject: event_connect_answer);
  if ( handle_connect_map != nullptr )
  {
    v21.cElems = (unsigned int)handle_connect_map;
    UnmapViewOfFile(lpBaseAddress: v21);
  }
  if ( handle_connect_file_map != nullptr )
    CloseHandle(hObject: handle_connect_file_map);
  if ( error_allow == 0 )
    return handle_map;
  if ( error_allow == 2044 )
    set_mysql_extended_error(
      a1: 2044,
      a2: (int)net,
      sqlstate: unknown_sqlstate,
      format: (_CONTEXT *)off_48F3C0,
      v6,
      error_code);
  else
    set_mysql_extended_error(
      a1: error_allow,
      a2: (int)net,
      sqlstate: unknown_sqlstate,
      format: *((_CONTEXT **)&off_48D3D0 + error_allow),
      error_code);
  return (char *)-1;
}

//------------------------------------------------------------------------------
// Address: 0x0040B560
// Name: _free_rows
// Source: json
//------------------------------------------------------------------------------
void *__stdcall free_rows(unsigned int cur)
{
  void *result; // eax

  if ( cur != 0 )
  {
    free_root(a1: cur + 8, MyFlags: 0);
    return (void *)my_no_flags_free();
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040B580
// Name: _free_old_query
// Source: json
//------------------------------------------------------------------------------
_stat64 *__cdecl free_old_query(_PEB mysql)
{
  _stat64 *result; // eax

  if ( *(_DWORD *)(*(_DWORD *)&mysql.InheritedAddressSpace + 660) != 0 )
    free_root(a1: *(_DWORD *)&mysql.InheritedAddressSpace + 664, MyFlags: 0);
  result = init_alloc_root(result: (_stat64 *)(*(_DWORD *)&mysql.InheritedAddressSpace + 664));
  *(_DWORD *)(*(_DWORD *)&mysql.InheritedAddressSpace + 660) = 0;
  *(_DWORD *)(*(_DWORD *)&mysql.InheritedAddressSpace + 744) = 0;
  *(_DWORD *)(*(_DWORD *)&mysql.InheritedAddressSpace + 756) = 0;
  *(_DWORD *)(*(_DWORD *)&mysql.InheritedAddressSpace + 648) = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040B5D0
// Name: is_NT
// Source: json
//------------------------------------------------------------------------------
BOOL is_NT()
{
  const char *v0; // eax

  v0 = getenv(option: "OS");
  return v0 != nullptr && strcmp(v0, "Windows_NT") == 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040B620
// Name: _end_server
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x0040B660
// Name: mysql_free_result(x)
// Source: json
//------------------------------------------------------------------------------
void __userpurge mysql_free_result(
        _DWORD *result,
        unsigned int a2,
        unsigned int a3,
        int (__cdecl *a4)(const void *, const void *))
{
  _DWORD *v4; // esi
  _BYTE *v5; // esi

  if ( result != nullptr )
  {
    v4 = (_DWORD *)result[6];
    if ( v4 != nullptr )
    {
      if ( (_DWORD *)v4[238] == (_DWORD *)((char *)result + 81) )
        v4[238] = 0;
      if ( v4[224] == 2 )
      {
        (*(void (__cdecl **)(_DWORD *, _DWORD))(v4[236] + 20))(a1: v4, a2: 0);
        v4[224] = 0;
        v5 = (_BYTE *)v4[238];
        if ( v5 != nullptr )
          *v5 = 1;
      }
    }
    free_rows(cur: result[3]);
    if ( result[2] != 0 )
      free_root(a1: result + 10, MyFlags: 0);
    if ( result[8] != 0 )
      my_no_flags_free();
    my_no_flags_free();
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040B700
// Name: add_init_command
// Source: json
//------------------------------------------------------------------------------
int __usercall add_init_command@<eax>(int a1@<ecx>, int a2@<esi>)
{
  const char *v2; // eax
  int *v4; // [esp-8h] [ebp-Ch]
  int v5; // [esp-4h] [ebp-8h]
  int element; // [esp+0h] [ebp-4h] BYREF

  element = a1;
  if ( *(_DWORD *)(a2 + 44) == 0 )
  {
    v2 = (const char *)my_malloc(size: 0x14u, my_flags: 16);
    *(_DWORD *)(a2 + 44) = v2;
    init_dynamic_array(array: v2, element_size: 4, init_alloc: 5, alloc_increment: 5, a5: v4, a6: v5);
  }
  element = my_strdup();
  if ( element != 0 && (unsigned __int8)insert_dynamic(array: *(_DWORD *)(a2 + 44), (int)&element) == 0 )
    return 0;
  my_no_flags_free();
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040B770
// Name: _mysql_read_default_options
// Source: json
//------------------------------------------------------------------------------
int __cdecl mysql_read_default_options(int a1, tagShutdownType filename, tagShutdownType group)
{
  int (__stdcall *v3)(unsigned int, unsigned int, const wchar_t *, int, char *, int, const char *, int *); // eax
  _DWORD *i; // ebp
  _BYTE *v5; // eax
  char *v6; // edi
  _BYTE *j; // eax
  CEmptyConVar *v8; // ecx
  int type; // eax
  _iobuf *v10; // eax
  bool v11; // al
  int result; // eax
  int (__stdcall **p_argv_buff)(unsigned int, unsigned int, const wchar_t *, int, char *, int, const char *, int *); // [esp+Ch] [ebp-18h] BYREF
  int argc; // [esp+10h] [ebp-14h] BYREF
  int (__stdcall *argv_buff)(unsigned int, unsigned int, const wchar_t *, int, char *, int, const char *, int *); // [esp+14h] [ebp-10h] BYREF
  _DWORD v16[3]; // [esp+18h] [ebp-Ch] BYREF

  p_argv_buff = &argv_buff;
  argv_buff = (int (__stdcall *)(unsigned int, unsigned int, const wchar_t *, int, char *, int, const char *, int *))"client";
  v16[0] = "client";
  v16[1] = group;
  argc = 1;
  v16[2] = 0;
  my_load_defaults(a1: filename, a2: v16, a3: &argc, a4: &p_argv_buff, a5: 0);
  if ( argc != 1 )
  {
    v3 = p_argv_buff[1];
    for ( i = p_argv_buff + 1; v3 != nullptr; ++i )
    {
      if ( v3 != (int (__stdcall *)(unsigned int, unsigned int, const wchar_t *, int, char *, int, const char *, int *))args_separator
        && *(_BYTE *)v3 == 45
        && *((_BYTE *)v3 + 1) == 45 )
      {
        v5 = (_BYTE *)strcend();
        v6 = nullptr;
        if ( *v5 != 0 )
        {
          v6 = v5 + 1;
          *v5 = 0;
        }
        for ( j = (_BYTE *)strcend(); *j != 0; j = (_BYTE *)strcend() )
          *j = 45;
        switch ( find_type(x: (char *)(*i + 2), a2: &option_types, full_name: 2u) )
        {
          case 1:
            if ( v6 != nullptr )
              *(_DWORD *)(a1 + 12) = atoi(nptr: v6);
            break;
          case 2:
            if ( v6 != nullptr )
            {
              my_no_flags_free();
              *(_DWORD *)(a1 + 36) = my_strdup();
            }
            break;
          case 3:
            *(_DWORD *)(a1 + 20) |= 0x20u;
            *(_BYTE *)(a1 + 93) = 1;
            break;
          case 4:
            if ( v6 != nullptr )
            {
              my_no_flags_free();
              *(_DWORD *)(a1 + 32) = my_strdup();
            }
            break;
          case 5:
            *(_DWORD *)(a1 + 16) = 3;
            goto $LN41;
          case 6:
          case 0x14:
$LN41:
            if ( v6 != nullptr )
              *(_DWORD *)a1 = atoi(nptr: v6);
            break;
          case 7:
            if ( v6 != nullptr )
            {
              my_no_flags_free();
              *(_DWORD *)(a1 + 28) = my_strdup();
            }
            break;
          case 8:
            add_init_command(a1: (int)v8, a2: a1);
            break;
          case 9:
            if ( v6 != nullptr )
            {
              my_no_flags_free();
              *(_DWORD *)(a1 + 24) = my_strdup();
            }
            break;
          case 0xA:
            if ( v6 != nullptr )
            {
              my_no_flags_free();
              *(_DWORD *)(a1 + 40) = my_strdup();
            }
            break;
          case 0xB:
            if ( v6 == nullptr )
              v6 = "d:t:o,/tmp/client.trace";
            yaSSL::ServerKeyBase::build(this: v8, nValue: (int)v6);
            break;
          case 0xC:
            *(_DWORD *)(a1 + 20) |= 2u;
            break;
          case 0xD:
            my_no_flags_free();
            *(_DWORD *)(a1 + 64) = my_strdup();
            break;
          case 0xE:
            my_no_flags_free();
            *(_DWORD *)(a1 + 68) = my_strdup();
            break;
          case 0xF:
            my_no_flags_free();
            *(_DWORD *)(a1 + 72) = my_strdup();
            break;
          case 0x10:
            my_no_flags_free();
            *(_DWORD *)(a1 + 76) = my_strdup();
            break;
          case 0x11:
            my_no_flags_free();
            *(_DWORD *)(a1 + 56) = my_strdup();
            break;
          case 0x12:
            my_no_flags_free();
            *(_DWORD *)(a1 + 60) = my_strdup();
            break;
          case 0x13:
            *(_DWORD *)(a1 + 20) |= 0x400u;
            break;
          case 0x15:
            if ( v6 != nullptr && atoi(nptr: v6) == 0 )
              goto $LN18_0;
            *(_DWORD *)(a1 + 20) |= 0x80u;
            break;
          case 0x16:
$LN18_0:
            *(_DWORD *)(a1 + 20) &= ~0x80u;
            break;
          case 0x17:
            my_no_flags_free();
            *(_DWORD *)(a1 + 80) = my_strdup();
            break;
          case 0x18:
            if ( v6 != nullptr )
              *(_DWORD *)(a1 + 88) = atoi(nptr: v6);
            break;
          case 0x19:
            type = find_type(x: v6, a2: &sql_protocol_typelib, full_name: 0);
            *(_DWORD *)(a1 + 16) = type;
            if ( type == 0 )
            {
              v10 = __iob_func();
              fprintf(str: v10 + 2, format: "Unknown option to protocol: %s\n", v6);
              exit(code: 1);
            }
            return result;
          case 0x1A:
            if ( *(_DWORD *)(a1 + 84) != def_shared_memory_base_name )
              my_no_flags_free();
            *(_DWORD *)(a1 + 84) = my_strdup();
            break;
          case 0x1B:
            *(_DWORD *)(a1 + 20) |= 0x20000u;
            break;
          case 0x1C:
          case 0x1D:
            *(_DWORD *)(a1 + 20) |= 0x30000u;
            break;
          case 0x1E:
            *(_BYTE *)(a1 + 108) = 1;
            break;
          case 0x1F:
            v11 = v6 == nullptr || atoi(nptr: v6) != 0;
            *(_BYTE *)(a1 + 109) = v11;
            break;
          default:
            break;
        }
      }
      v3 = (int (__stdcall *)(unsigned int, unsigned int, const wchar_t *, int, char *, int, const char *, int *))i[1];
    }
  }
  return free_defaults(a1: p_argv_buff);
}

//------------------------------------------------------------------------------
// Address: 0x0040BBD0
// Name: cli_fetch_lengths
// Source: json
//------------------------------------------------------------------------------
int __cdecl cli_fetch_lengths(int *a1, int *a2, int a3)
{
  int *v3; // ecx
  int result; // eax
  int v5; // ebx
  int v6; // edx
  int *v7; // edi

  v3 = a2;
  result = a3;
  v5 = (int)&a2[a3 + 1];
  v6 = 0;
  v7 = nullptr;
  if ( a2 != (int *)v5 )
  {
    do
    {
      result = *v3;
      if ( *v3 != 0 )
      {
        if ( v6 != 0 )
        {
          result = result - v6 - 1;
          *v7 = result;
        }
        v6 = *v3;
        v7 = a1;
      }
      else
      {
        *a1 = 0;
      }
      ++v3;
      ++a1;
    }
    while ( v3 != (int *)v5 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040BC20
// Name: _unpack_fields
// Source: json
//------------------------------------------------------------------------------
void (__cdecl *__cdecl unpack_fields(
        int ***cur,
        void *mem_root,
        unsigned int a3,
        char default_value,
        __int16 server_capabilities))(int)
{
  unsigned int v5; // esi
  unsigned __int8 *v6; // eax
  int **v8; // edi
  _DWORD *v9; // esi
  unsigned __int16 *(__stdcall *v10)(); // ebx
  void *v11; // eax
  int v12; // edx
  int v13; // ecx
  int v14; // eax
  int v15; // edx
  unsigned __int16 *v16; // eax
  int v17; // edx
  int v18; // eax
  int v19; // ecx
  int v20; // ebx
  _DWORD *v21; // esi
  void *v22; // eax
  int v23; // ecx
  unsigned __int16 *(__stdcall *v24)(); // eax
  unsigned __int16 *v25; // eax
  int v26; // ecx
  int v27; // ecx
  int v28; // eax
  unsigned int v29; // [esp+0h] [ebp-38h]
  unsigned int *v30; // [esp+4h] [ebp-34h]
  _OVERLAPPED *v31; // [esp+8h] [ebp-30h]
  unsigned __int16 *(__stdcall *lengths)(); // [esp+14h] [ebp-24h] BYREF
  int v33; // [esp+18h] [ebp-20h]
  int v34; // [esp+1Ch] [ebp-1Ch]
  int v35; // [esp+20h] [ebp-18h]
  int v36; // [esp+24h] [ebp-14h]
  int v37; // [esp+28h] [ebp-10h]
  int v38; // [esp+30h] [ebp-8h]
  unsigned int v39; // [esp+44h] [ebp+Ch]

  v5 = 84 * a3;
  v6 = (unsigned __int8 *)alloc_root(mem_root, length: (const void *)(84 * a3), a3: v29, a4: v30, a5: v31);
  v39 = (unsigned int)v6;
  if ( v6 != nullptr )
  {
    memset(dst: v6, value: 0, count: v5);
    v8 = *cur;
    if ( (server_capabilities & 0x200) != 0 )
    {
      if ( v8 != nullptr )
      {
        v9 = (_DWORD *)(v39 + 16);
        do
        {
          cli_fetch_lengths(a1: (int *)&lengths, a2: v8[1], a3: (default_value != 0) + 7);
          v10 = lengths;
          v9[1] = strmake_root();
          *v9 = strmake_root();
          *(v9 - 2) = strmake_root();
          *(v9 - 1) = strmake_root();
          *(v9 - 4) = strmake_root();
          v11 = strmake_root();
          v12 = v33;
          v13 = v35;
          *(v9 - 3) = v11;
          v9[7] = v34;
          v14 = v37;
          v9[9] = v12;
          v15 = v36;
          v9[6] = v14;
          v9[10] = v10;
          v9[8] = v13;
          v9[5] = v15;
          v16 = (unsigned __int16 *)v8[1][6];
          v9[14] = *v16;
          v9[3] = *(_DWORD *)(v16 + 1);
          v9[15] = *((unsigned __int8 *)v16 + 6);
          v9[12] = *(unsigned __int16 *)((char *)v16 + 7);
          v17 = *((unsigned __int8 *)v16 + 9);
          v18 = v9[15];
          v9[13] = v17;
          if ( v18 <= 9 && (v18 != 7 || (v19 = v9[3]) == 14 || v19 == 8) || v18 == 13 )
            v9[12] |= 0x8000u;
          if ( default_value != 0 && v8[1][7] != 0 )
          {
            v20 = v38;
            v9[2] = strmake_root();
            v9[11] = v20;
          }
          else
          {
            v9[2] = 0;
          }
          v9[4] = 0;
          v8 = (int **)*v8;
          v9 += 21;
        }
        while ( v8 != nullptr );
      }
    }
    else if ( v8 != nullptr )
    {
      v21 = (_DWORD *)(v39 + 12);
      do
      {
        cli_fetch_lengths(a1: (int *)&lengths, a2: v8[1], a3: (default_value != 0) + 5);
        v22 = strdup_root();
        *(v21 - 1) = v22;
        *v21 = v22;
        *(v21 - 3) = strdup_root();
        v21[4] = *(_DWORD *)v8[1][2] & 0xFFFFFF;
        v23 = v33;
        v21[16] = *(unsigned __int8 *)v8[1][3];
        v21[2] = defaultValue;
        v21[1] = defaultValue;
        v24 = lengths;
        v21[11] = 0;
        v21[10] = 0;
        v21[8] = v24;
        v21[9] = v24;
        v21[6] = v23;
        v25 = (unsigned __int16 *)v8[1][4];
        if ( (server_capabilities & 4) != 0 )
        {
          v21[13] = *v25;
          v26 = *(unsigned __int8 *)(v8[1][4] + 2);
        }
        else
        {
          v21[13] = *(unsigned __int8 *)v25;
          v26 = *(unsigned __int8 *)(v8[1][4] + 1);
        }
        v21[14] = v26;
        v27 = v21[16];
        if ( v27 <= 9 && (v27 != 7 || (v28 = v21[4]) == 14 || v28 == 8) || v27 == 13 )
          v21[13] |= 0x8000u;
        if ( default_value != 0 && v8[1][5] != 0 )
        {
          v21[3] = strdup_root();
          v21[12] = v37;
        }
        else
        {
          v21[3] = 0;
        }
        v21[5] = 0;
        v8 = (int **)*v8;
        v21 += 21;
      }
      while ( v8 != nullptr );
    }
    free_rows((unsigned int)cur);
    return (void (__cdecl *)(int))v39;
  }
  else
  {
    free_rows((unsigned int)cur);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040BF40
// Name: mysql_init(x)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__stdcall mysql_init(unsigned __int8 *mysql, unsigned int mysql_4)
{
  unsigned __int8 *v3; // esi
  int v4; // eax
  LIST_ENTRY32 *v5; // ecx

  if ( mysql_server_init(argc: 0, argv: 0, a3: 0) != 0 )
    return nullptr;
  v3 = mysql;
  if ( mysql != nullptr )
  {
    memset(dst: mysql, value: 0, count: 0x3C8u);
  }
  else
  {
    v4 = my_malloc(size: 0x3C8u, my_flags: 48);
    v3 = (unsigned __int8 *)v4;
    if ( v4 == 0 )
    {
      set_mysql_error(a1: 0, a2: 0x7D8u);
      return nullptr;
    }
    *(_BYTE *)(v4 + 900) = 1;
  }
  *((_DWORD *)v3 + 190) = 20;
  v5 = default_client_charset_info;
  *((_DWORD *)v3 + 164) = default_client_charset_info;
  strmov(dst: (int)v5);
  *((_DWORD *)v3 + 195) |= 0x80u;
  *((_DWORD *)v3 + 211) = def_shared_memory_base_name;
  *((_DWORD *)v3 + 215) = 16;
  v3[869] = 1;
  v3[901] = 0;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x0040C010
// Name: mysql_ssl_free
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x0040C0B0
// Name: ssl_verify_server_cert
// Source: json
//------------------------------------------------------------------------------
int __usercall ssl_verify_server_cert@<eax>(const char *a1@<edi>, int a2)
{
  ShortVector *v2; // eax
  int result; // eax
  yaSSL::X509 *peer_certificate; // esi
  characterset_t *subject_name; // eax
  const char *v6; // ecx
  int v7; // eax
  const char *v8; // esi
  _BYTE *v9; // eax
  int (__stdcall *buf[64])(_EXCEPTION_POINTERS *); // [esp+0h] [ebp-104h] BYREF

  v2 = *(ShortVector **)(a2 + 380);
  if ( v2 == nullptr || a1 == nullptr )
    return 1;
  peer_certificate = (yaSSL::X509 *)yaSSL_get_peer_certificate(a1: v2);
  if ( peer_certificate == nullptr )
    return 1;
  subject_name = (characterset_t *)yaX509_get_subject_name(a1: peer_certificate);
  yaX509_NAME_oneline(name: v6, buffer: subject_name);
  vio_ignore_timeout();
  strstr(str1: (unsigned __int8 *)buf, str2: "/CN=");
  if ( v7 == 0 )
    return 1;
  v8 = (const char *)(v7 + 4);
  strchr(string: (unsigned __int8 *)(v7 + 4), chr: 0x2Fu);
  if ( v9 != nullptr )
    *v9 = 0;
  result = strcmp(v8, a1);
  if ( result != 0 )
    return 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040C1C0
// Name: _mysql_init_character_set
// Source: json
//------------------------------------------------------------------------------
int __cdecl mysql_init_character_set(_IMAGE_OPTIONAL_HEADER *result)
{
  const char *v1; // ebx
  unsigned int v2; // eax
  unsigned int charset_by_csname; // eax
  unsigned int charset_by_name; // eax
  unsigned int v6; // edi
  _LIST_ENTRY *save; // [esp+8h] [ebp-208h]
  IRecordInfo *cs_dir_name; // [esp+Ch] [ebp-204h] BYREF

  if ( result[3].DataDirectory[6].Size != 0 )
  {
    v1 = nullptr;
  }
  else
  {
    v1 = "latin1_swedish_ci";
    v2 = my_strdup();
    result[3].DataDirectory[6].Size = v2;
    if ( v2 == 0 )
      return 1;
  }
  save = `WspiapiFreeAddrInfo'::`2'::pfFreeAddrInfo.InLoadOrderModuleList.Flink;
  if ( result[3].DataDirectory[6].VirtualAddress != 0 )
    `WspiapiFreeAddrInfo'::`2'::pfFreeAddrInfo.InLoadOrderModuleList.Flink = (_LIST_ENTRY *)result[3].DataDirectory[6].VirtualAddress;
  charset_by_csname = get_charset_by_csname();
  result[2].DataDirectory[14].VirtualAddress = charset_by_csname;
  if ( charset_by_csname != 0 && v1 != nullptr )
  {
    charset_by_name = get_charset_by_name(ap: (char)v1, a2: 16);
    v6 = charset_by_name;
    if ( charset_by_name == 0 )
    {
LABEL_12:
      result[2].DataDirectory[14].VirtualAddress = 0;
      goto LABEL_13;
    }
    if ( (unsigned __int8)my_charset_same(cs1: (void *)result[2].DataDirectory[14].VirtualAddress, cs2: charset_by_name) == 0 )
    {
      my_printf_error(
        error: 0x451u,
        format: (tagShutdownType)"COLLATION %s is not valid for CHARACTER SET %s",
        MyFlags: 0,
        ap: (char)v1);
      goto LABEL_12;
    }
    result[2].DataDirectory[14].VirtualAddress = v6;
  }
LABEL_13:
  `WspiapiFreeAddrInfo'::`2'::pfFreeAddrInfo.InLoadOrderModuleList.Flink = save;
  if ( result[2].DataDirectory[14].VirtualAddress != 0 )
    return 0;
  if ( result[3].DataDirectory[6].VirtualAddress != 0 )
  {
    set_mysql_extended_error(
      a1: 2019,
      a2: (int)result,
      sqlstate: unknown_sqlstate,
      format: (_CONTEXT *)off_48F35C,
      result[3].DataDirectory[6].Size,
      result[3].DataDirectory[6].VirtualAddress);
  }
  else
  {
    get_charsets_dir(dst: &cs_dir_name);
    set_mysql_extended_error(
      a1: 2019,
      a2: (int)result,
      sqlstate: unknown_sqlstate,
      format: (_CONTEXT *)off_48F35C,
      result[3].DataDirectory[6].Size,
      &cs_dir_name);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040C380
// Name: mysql_select_db(x,x)
// Source: json
//------------------------------------------------------------------------------
int __stdcall mysql_select_db(int a1, const char *a2)
{
  int result; // eax

  result = (*(char (__cdecl **)(int, int, _DWORD, _DWORD, const char *, unsigned int, _DWORD, _DWORD))(*(_DWORD *)(a1 + 944) + 4))(
             a1,
             a2: 2,
             a3: 0,
             a4: 0,
             a5: a2,
             a6: strlen(a2),
             a7: 0,
             a8: 0);
  if ( (_BYTE)result == 0 )
  {
    my_no_flags_free();
    *(_DWORD *)(a1 + 652) = my_strdup();
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040C3F0
// Name: mysql_close_free_options
// Source: json
//------------------------------------------------------------------------------
void __usercall mysql_close_free_options(int a1@<eax>)
{
  unsigned int *v2; // ebp
  unsigned int v3; // edi
  unsigned int v4; // ebx

  my_no_flags_free();
  my_no_flags_free();
  my_no_flags_free();
  my_no_flags_free();
  my_no_flags_free();
  my_no_flags_free();
  my_no_flags_free();
  my_no_flags_free();
  my_no_flags_free();
  my_no_flags_free();
  v2 = *(unsigned int **)(a1 + 804);
  if ( v2 != nullptr )
  {
    v3 = *v2;
    v4 = *v2 + 4 * v2[1];
    if ( *v2 < v4 )
    {
      do
      {
        my_no_flags_free();
        v3 += 4;
      }
      while ( v3 < v4 );
    }
    delete_dynamic(a1: v2);
    my_no_flags_free();
  }
  mysql_ssl_free();
  if ( *(_DWORD *)(a1 + 844) != def_shared_memory_base_name )
    my_no_flags_free();
  memset(dst: (unsigned __int8 *)(a1 + 760), value: 0, count: 0x88u);
}

//------------------------------------------------------------------------------
// Address: 0x0040C4E0
// Name: mysql_close_free
// Source: json
//------------------------------------------------------------------------------
int __usercall mysql_close_free@<eax>(_DWORD *a1@<esi>)
{
  my_no_flags_free();
  my_no_flags_free();
  my_no_flags_free();
  my_no_flags_free();
  my_no_flags_free();
  a1[239] = 0;
  a1[163] = 0;
  a1[158] = 0;
  a1[157] = 0;
  a1[161] = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040C540
// Name: _mysql_detach_stmt_list
// Source: json
//------------------------------------------------------------------------------
void __cdecl mysql_detach_stmt_list(int *a1)
{
  int v1; // esi
  int v2; // edi
  IRecordInfo *buff; // [esp+8h] [ebp-204h] BYREF

  v1 = *a1;
  my_snprintf(result: (_cpinfo *)&buff);
  for ( ; v1 != 0; v1 = *(_DWORD *)(v1 + 4) )
  {
    v2 = *(_DWORD *)(v1 + 8);
    set_stmt_error(a1: v2, errcode: 2056);
    *(_DWORD *)(v2 + 44) = 0;
  }
  *a1 = 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040C5D0
// Name: mysql_close(x)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x0040C670
// Name: mysql_send_query(x,x,x)
// Source: json
//------------------------------------------------------------------------------
int __stdcall mysql_send_query(int a1, int a2, int a3)
{
  return (*(char (__cdecl **)(int, int, _DWORD, _DWORD, int, int, int, _DWORD))(*(_DWORD *)(a1 + 944) + 4))(
           a1,
           a2: 3,
           a3: 0,
           a4: 0,
           a5: a2,
           a6: a3,
           a7: 1,
           a8: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0040C6A0
// Name: mysql_real_query(x,x,x)
// Source: json
//------------------------------------------------------------------------------
int __stdcall mysql_real_query(int a1, int a2, int a3)
{
  if ( mysql_send_query(a1, a2, a3) != 0 )
    return 1;
  else
    return (**(char (__cdecl ***)(int))(a1 + 944))(a1);
}

//------------------------------------------------------------------------------
// Address: 0x0040C6E0
// Name: cli_use_result
// Source: json
//------------------------------------------------------------------------------
_DWORD *__cdecl cli_use_result(_PEB mysql)
{
  int v2; // eax
  _DWORD *v3; // ebx
  int v4; // eax
  int v5; // edx

  if ( *(_DWORD *)(*(_DWORD *)&mysql.InheritedAddressSpace + 660) == 0 )
    return nullptr;
  if ( *(_DWORD *)(*(_DWORD *)&mysql.InheritedAddressSpace + 896) != 1 )
  {
    set_mysql_error(a1: *(int *)&mysql.InheritedAddressSpace, a2: 0x7DEu);
    return nullptr;
  }
  v2 = my_malloc(size: 4 * *(_DWORD *)(*(_DWORD *)&mysql.InheritedAddressSpace + 744) + 88, my_flags: 48);
  v3 = (_DWORD *)v2;
  if ( v2 == 0 )
    return nullptr;
  *(_DWORD *)(v2 + 20) = v2 + 88;
  *(_DWORD *)(v2 + 28) = *(_DWORD *)(*(_DWORD *)&mysql.InheritedAddressSpace + 944);
  v4 = my_malloc(size: 4 * *(_DWORD *)(*(_DWORD *)&mysql.InheritedAddressSpace + 744) + 4, my_flags: 16);
  v3[8] = v4;
  if ( v4 == 0 )
  {
    my_no_flags_free();
    return nullptr;
  }
  v3[2] = *(_DWORD *)(*(_DWORD *)&mysql.InheritedAddressSpace + 660);
  qmemcpy(v3 + 10, (const void *)(*(_DWORD *)&mysql.InheritedAddressSpace + 664), 0x20u);
  v5 = *(_DWORD *)(*(_DWORD *)&mysql.InheritedAddressSpace + 744);
  v3[6] = *(_DWORD *)&mysql.InheritedAddressSpace;
  v3[18] = v5;
  v3[19] = 0;
  v3[9] = 0;
  *(_DWORD *)(*(_DWORD *)&mysql.InheritedAddressSpace + 664) = 0;
  *(_DWORD *)(*(_DWORD *)&mysql.InheritedAddressSpace + 952) = (char *)v3 + 81;
  *(_DWORD *)(*(_DWORD *)&mysql.InheritedAddressSpace + 660) = 0;
  *(_DWORD *)(*(_DWORD *)&mysql.InheritedAddressSpace + 672) = 0;
  *(_DWORD *)(*(_DWORD *)&mysql.InheritedAddressSpace + 668) = 0;
  *(_DWORD *)(*(_DWORD *)&mysql.InheritedAddressSpace + 676) = 0;
  *(_DWORD *)(*(_DWORD *)&mysql.InheritedAddressSpace + 896) = 2;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x0040C7D0
// Name: mysql_options(x,x,x)
// Source: json
//------------------------------------------------------------------------------
int __stdcall mysql_options(_iobuf *mysql, char *a2, int *arg)
{
  int result; // eax

  switch ( (unsigned int)a2 )
  {
    case 0u:
      mysql[23]._bufsiz = *arg;
      result = 0;
      break;
    case 1u:
      mysql[24]._flag |= 0x20u;
      BYTE1(mysql[26]._charbuf) = 1;
      result = 0;
      break;
    case 2u:
      mysql[24]._base = (char *)3;
      result = 0;
      break;
    case 3u:
      add_init_command(a1: (int)arg, a2: (int)&mysql[23]._bufsiz);
      result = 0;
      break;
    case 4u:
      my_no_flags_free();
      mysql[25]._base = (char *)my_strdup();
      result = 0;
      break;
    case 5u:
      my_no_flags_free();
      mysql[25]._flag = my_strdup();
      result = 0;
      break;
    case 6u:
      my_no_flags_free();
      mysql[25]._file = my_strdup();
      result = 0;
      break;
    case 7u:
      my_no_flags_free();
      mysql[25]._charbuf = my_strdup();
      result = 0;
      break;
    case 8u:
      if ( arg == nullptr || *arg != 0 )
      {
        mysql[24]._flag |= 0x80u;
        result = 0;
      }
      else
      {
        mysql[24]._flag &= ~0x80u;
        result = 0;
      }
      break;
    case 9u:
      mysql[24]._base = (char *)*arg;
      result = 0;
      break;
    case 0xAu:
      if ( mysql[26]._flag != def_shared_memory_base_name )
        my_no_flags_free();
      mysql[26]._flag = my_strdup();
      result = 0;
      break;
    case 0xBu:
      mysql[23]._tmpfname = (char *)*arg;
      result = 0;
      break;
    case 0xCu:
      mysql[24]._ptr = (char *)*arg;
      result = 0;
      break;
    case 0xEu:
    case 0xFu:
    case 0x10u:
      mysql[26]._tmpfname = a2;
      result = 0;
      break;
    case 0x11u:
      mysql[27]._ptr = (char *)my_strdup();
      result = 0;
      break;
    case 0x12u:
      LOBYTE(mysql[27]._cnt) = *(_BYTE *)arg;
      result = 0;
      break;
    case 0x13u:
      BYTE1(mysql[27]._cnt) = *(_BYTE *)arg != 0;
      result = 0;
      break;
    case 0x14u:
      BYTE1(mysql[28]._cnt) = *(_BYTE *)arg;
      result = 0;
      break;
    case 0x15u:
      if ( *(_BYTE *)arg != 0 )
        mysql[24]._flag |= 0x40000000u;
      else
        mysql[24]._flag &= ~0x40000000u;
      result = 0;
      break;
    default:
      result = 1;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040CAA0
// Name: mysql_error(x)
// Source: json
//------------------------------------------------------------------------------
IRecordInfo **__stdcall mysql_error(const wchar_t *mysql, const wchar_t *mysql_4)
{
  if ( mysql != nullptr )
    return (IRecordInfo **)((char *)mysql + 95);
  else
    return &mysql_server_last_error;
}

//------------------------------------------------------------------------------
// Address: 0x0040CAC0
// Name: mysql_get_server_version(x)
// Source: json
//------------------------------------------------------------------------------
unsigned int __userpurge mysql_get_server_version@<eax>(char *mysql, _EXCEPTION_POINTERS *end_pos)
{
  unsigned int v2; // esi
  unsigned int v3; // edi

  v2 = strtoul(nptr: *((const char **)mysql + 160), endptr: &mysql, ibase: 10);
  v3 = strtoul(nptr: mysql + 1, endptr: &mysql, ibase: 10);
  return 100 * (v3 + 100 * v2) + strtoul(nptr: mysql + 1, endptr: &mysql, ibase: 10);
}

//------------------------------------------------------------------------------
// Address: 0x0040CB20
// Name: mysql_set_character_set(x,x)
// Source: json
//------------------------------------------------------------------------------
int __stdcall mysql_set_character_set(unsigned int mysql, const char *ap)
{
  _LIST_ENTRY *Flink; // ebp
  unsigned int charset_by_csname; // ebx
  _EXCEPTION_POINTERS *v5; // [esp+0h] [ebp-240h]
  char string[44]; // [esp+10h] [ebp-230h] BYREF
  _BYTE dst[512]; // [esp+3Ch] [ebp-204h] BYREF

  Flink = `WspiapiFreeAddrInfo'::`2'::pfFreeAddrInfo.InLoadOrderModuleList.Flink;
  if ( *(_DWORD *)(mysql + 816) != 0 )
    `WspiapiFreeAddrInfo'::`2'::pfFreeAddrInfo.InLoadOrderModuleList.Flink = *(_LIST_ENTRY **)(mysql + 816);
  if ( strlen(ap) < 0x20 && (charset_by_csname = get_charset_by_csname()) != 0 )
  {
    `WspiapiFreeAddrInfo'::`2'::pfFreeAddrInfo.InLoadOrderModuleList.Flink = Flink;
    if ( mysql_get_server_version((char *)mysql, end_pos: v5) < 0x9CA4 )
      return 0;
    sprintf(string, format: "SET NAMES %s", ap);
    if ( mysql_real_query(a1: mysql, a2: (int)string, a3: strlen(string)) == 0 )
      *(_DWORD *)(mysql + 656) = charset_by_csname;
  }
  else
  {
    get_charsets_dir(dst);
    set_mysql_extended_error(a1: 2019, a2: mysql, sqlstate: unknown_sqlstate, format: (_CONTEXT *)off_48F35C, ap, dst);
  }
  `WspiapiFreeAddrInfo'::`2'::pfFreeAddrInfo.InLoadOrderModuleList.Flink = Flink;
  return *(_DWORD *)(mysql + 88);
}

//------------------------------------------------------------------------------
// Address: 0x0040CC30
// Name: _cli_safe_read
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl cli_safe_read(void *net)
{
  int v1; // eax
  unsigned int v2; // ebx
  int v3; // eax
  _BYTE *v4; // edi
  unsigned int v5; // ebx
  bool v6; // zf

  if ( *(_DWORD *)net != 0 && (v1 = my_net_read(net), v2 = v1, v1 != -1) && v1 != 0 )
  {
    v3 = *((_DWORD *)net + 4);
    if ( *(_BYTE *)v3 == 0xFF )
    {
      if ( v2 <= 3 )
      {
        set_mysql_error(a1: (int)net, a2: 0x7D0u);
        *((_DWORD *)net + 187) &= ~8u;
        return -1;
      }
      else
      {
        v4 = (_BYTE *)(v3 + 3);
        v5 = v2 - 2;
        v6 = (*((_DWORD *)net + 184) & 0x200) == 0;
        *((_DWORD *)net + 22) = *(unsigned __int16 *)(v3 + 1);
        if ( v6 || *v4 != 35 )
        {
          strmov(dst: (int)net + 607);
        }
        else
        {
          strmake(dst: (char *)net + 607, src: (tagShutdownType)(v3 + 4), length: 5u);
          v4 += 6;
        }
        if ( v5 >= 0x1FF )
          v5 = 511;
        strmake(dst: (char *)net + 95, src: (tagShutdownType)v4, length: v5);
        *((_DWORD *)net + 187) &= ~8u;
        return -1;
      }
    }
    else
    {
      return v2;
    }
  }
  else
  {
    end_server(a1: net);
    set_mysql_error(a1: (int)net, a2: *((_DWORD *)net + 22) != 1153 ? 2013 : 2020);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040CD40
// Name: _flush_one_result
// Source: json
//------------------------------------------------------------------------------
char __cdecl flush_one_result(void *net)
{
  unsigned int v1; // eax
  int v2; // eax

  while ( 1 )
  {
    v1 = cli_safe_read(net);
    if ( v1 == -1 )
      return 1;
    if ( v1 <= 8 )
    {
      v2 = *((_DWORD *)net + 4);
      if ( *(_BYTE *)v2 == 0xFE )
        break;
    }
  }
  if ( (*((_DWORD *)net + 184) & 0x200) != 0 )
  {
    *((_DWORD *)net + 189) = *(unsigned __int16 *)(v2 + 1);
    *((_DWORD *)net + 187) = *(unsigned __int16 *)(v2 + 3);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040CD90
// Name: _opt_flush_ok_packet
// Source: json
//------------------------------------------------------------------------------
char __cdecl opt_flush_ok_packet(char *mysql, bool *is_ok_packet)
{
  bool v3; // al
  unsigned __int8 *v4; // eax
  bool v5; // zf
  unsigned __int8 *posa; // [esp+4h] [ebp-4h] BYREF

  if ( cli_safe_read(net: mysql) == -1 )
    return 1;
  v3 = **((_BYTE **)mysql + 4) == 0;
  *is_ok_packet = v3;
  if ( v3 )
  {
    posa = (unsigned __int8 *)(*((_DWORD *)mysql + 4) + 1);
    net_field_length_ll(packet: (const char *)&posa);
    net_field_length_ll(packet: (const char *)&posa);
    v4 = posa + 2;
    v5 = (*((_DWORD *)mysql + 184) & 0x200) == 0;
    *((_DWORD *)mysql + 187) = *(unsigned __int16 *)posa;
    posa = v4;
    if ( !v5 )
      *((_DWORD *)mysql + 189) = *(unsigned __int16 *)v4;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040CE10
// Name: cli_flush_use_result
// Source: json
//------------------------------------------------------------------------------
char __stdcall cli_flush_use_result(void *mysql, void *flush_all_results)
{
  char result; // al
  char is_ok_packeta; // [esp+7h] [ebp-1h] BYREF

  result = flush_one_result(net: mysql);
  if ( result == 0 && (_BYTE)flush_all_results != 0 && (*((_BYTE *)mysql + 748) & 8) != 0 )
  {
    do
    {
      result = opt_flush_ok_packet((char *)mysql, is_ok_packet: (bool *)&is_ok_packeta);
      if ( result != 0 )
        break;
      if ( is_ok_packeta != 0 )
        break;
      result = flush_one_result(net: mysql);
      if ( result != 0 )
        break;
      result = flush_one_result(net: mysql);
      if ( result != 0 )
        break;
    }
    while ( (*((_BYTE *)mysql + 748) & 8) != 0 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040CE70
// Name: _cli_read_rows
// Source: json
//------------------------------------------------------------------------------
int __usercall cli_read_rows@<eax>(
        unsigned int a1@<edi>,
        unsigned int *a2@<esi>,
        void *fields,
        int a4,
        unsigned int a5)
{
  void *v5; // ebp
  unsigned int v6; // ebx
  int v8; // edi
  bool v9; // cf
  int v10; // ebp
  int v11; // eax
  char *v12; // esi
  char *v13; // ecx
  int v14; // ebx
  unsigned int v15; // edi
  char *v16; // eax
  unsigned __int8 *v17; // eax
  unsigned int v18; // [esp-8h] [ebp-24h]
  unsigned int v19; // [esp-8h] [ebp-24h]
  unsigned int *v20; // [esp-4h] [ebp-20h]
  unsigned int *v21; // [esp-4h] [ebp-20h]
  _OVERLAPPED *v22; // [esp+0h] [ebp-1Ch]
  _OVERLAPPED *v23; // [esp+0h] [ebp-1Ch]
  unsigned __int8 *cp; // [esp+8h] [ebp-14h] BYREF
  unsigned int *v25; // [esp+Ch] [ebp-10h]
  int *v26; // [esp+10h] [ebp-Ch]
  unsigned int cur; // [esp+14h] [ebp-8h]
  char *end_to; // [esp+18h] [ebp-4h]

  v5 = fields;
  v6 = cli_safe_read(net: fields);
  if ( v6 == -1 )
    return 0;
  v20 = a2;
  v18 = a1;
  v8 = my_malloc(size: 0x38u, my_flags: 48);
  cur = v8;
  if ( v8 == 0 )
  {
    set_mysql_error(a1: (int)fields, a2: 0x7D8u);
    return 0;
  }
  init_alloc_root(result: (_stat64 *)(v8 + 8));
  *(_DWORD *)(v8 + 20) = 12;
  v26 = (int *)v8;
  *(_DWORD *)(v8 + 40) = 0;
  *(_DWORD *)(v8 + 44) = 0;
  *(_DWORD *)(v8 + 48) = a5;
  while ( 1 )
  {
    cp = *((unsigned __int8 **)v5 + 4);
    if ( *cp == 0xFE && v6 < 8 )
      break;
    v9 = __CFADD__((*(_DWORD *)(v8 + 40))++, 1);
    *(_DWORD *)(v8 + 44) += v9;
    v10 = alloc_root(mem_root: (void *)(v8 + 8), length: (const void *)0xC, a3: v18, a4: v20, a5: v22);
    if ( v10 == 0
      || (v11 = alloc_root(
                  mem_root: (void *)(v8 + 8),
                  length: (const void *)(v6 + 4 * a5 + 4),
                  a3: v19,
                  a4: v21,
                  a5: v23),
          *(_DWORD *)(v10 + 4) = v11,
          v11 == 0) )
    {
      free_rows(cur: v8);
      set_mysql_error(a1: (int)fields, a2: 0x7D8u);
      return 0;
    }
    *v26 = v10;
    v12 = (char *)(*(_DWORD *)(v10 + 4) + 4 * a5 + 4);
    v13 = &v12[v6 - 1];
    v14 = 0;
    v26 = (int *)v10;
    end_to = v13;
    if ( a5 != 0 )
    {
      v25 = (unsigned int *)(a4 + 32);
      while ( 1 )
      {
        v15 = net_field_length(packet: (unsigned __int16 *)&cp);
        if ( v15 == -1 )
        {
          *(_DWORD *)(*(_DWORD *)(v10 + 4) + 4 * v14) = 0;
        }
        else
        {
          v16 = (char *)(end_to - v12);
          *(_DWORD *)(*(_DWORD *)(v10 + 4) + 4 * v14) = v12;
          if ( v15 > (unsigned int)v16 )
          {
            free_rows(cur);
            set_mysql_error(a1: (int)fields, a2: 0x7EBu);
            return 0;
          }
          memcpy(dst: (unsigned __int8 *)v12, src: cp, count: v15);
          v12[v15] = 0;
          cp += v15;
          v12 += v15 + 1;
          if ( a4 != 0 && *v25 < v15 )
            *v25 = v15;
        }
        v25 += 21;
        if ( ++v14 >= a5 )
        {
          v8 = cur;
          break;
        }
      }
    }
    *(_DWORD *)(*(_DWORD *)(v10 + 4) + 4 * v14) = v12;
    v6 = cli_safe_read(net: fields);
    if ( v6 == -1 )
    {
      free_rows(cur: v8);
      return 0;
    }
    v5 = fields;
  }
  *v26 = 0;
  if ( v6 > 1 )
  {
    v17 = cp;
    *((_DWORD *)v5 + 189) = *(unsigned __int16 *)(cp + 1);
    *((_DWORD *)v5 + 187) = *(unsigned __int16 *)(v17 + 3);
  }
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x0040D0A0
// Name: mysql_real_connect(x,x,x,x,x,x,x,x)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x0040DEB0
// Name: _mysql_reconnect
// Source: json
//------------------------------------------------------------------------------
char __cdecl mysql_reconnect(int a1)
{
  int v1; // edx
  int v2; // eax
  int v3; // ecx
  int v4; // ecx
  int v6; // edi
  _DWORD *v7; // esi
  int v8; // [esp-1Ch] [ebp-3FCh]
  int v9; // [esp-18h] [ebp-3F8h]
  int v10; // [esp-14h] [ebp-3F4h]
  int v11; // [esp-10h] [ebp-3F0h]
  unsigned int v12; // [esp-4h] [ebp-3E4h]
  unsigned int v13; // [esp+0h] [ebp-3E0h]
  int mysql[243]; // [esp+10h] [ebp-3D0h] BYREF

  if ( *(_BYTE *)(a1 + 901) != 0 && (*(_BYTE *)(a1 + 748) & 1) == 0 && *(_DWORD *)(a1 + 644) != 0 )
  {
    mysql_init((unsigned __int8 *)mysql, mysql_4: v13);
    v1 = *(_DWORD *)(a1 + 636);
    v2 = *(_DWORD *)(a1 + 728);
    qmemcpy(&mysql[190], (const void *)(a1 + 760), 0x88u);
    v12 = *(_DWORD *)(a1 + 732) | 0x80000000;
    v11 = *(_DWORD *)(a1 + 652);
    v10 = *(_DWORD *)(a1 + 632);
    v9 = *(_DWORD *)(a1 + 628);
    v8 = *(_DWORD *)(a1 + 624);
    mysql[203] = 0;
    mysql[202] = 0;
    if ( mysql_real_connect(a1: mysql, a2: v8, a3: v9, a4: v10, a5: v11, a6: v2, a7: v1, a8: v12) == 0 )
    {
LABEL_7:
      *(_DWORD *)(a1 + 88) = mysql[22];
      strmov(dst: (int)&mysql[23] + 3);
      strmov(dst: v4);
      return 1;
    }
    if ( mysql_set_character_set((unsigned int)mysql, ap: *(const char **)(*(_DWORD *)(a1 + 656) + 16)) != 0 )
    {
      memset(dst: (unsigned __int8 *)&mysql[190], value: 0, count: 0x88u);
      mysql_close(a1: mysql);
      goto LABEL_7;
    }
    v6 = *(_DWORD *)(a1 + 940);
    LOBYTE(v3) = *(_BYTE *)(a1 + 900);
    BYTE1(mysql[225]) = 1;
    for ( LOBYTE(mysql[225]) = v3; v6 != 0; v6 = *(_DWORD *)(v6 + 4) )
    {
      v7 = *(_DWORD **)(v6 + 8);
      if ( v7[43] == 1 )
      {
        mysql[235] = (int)list_add();
      }
      else
      {
        v7[11] = 0;
        v7[40] = 2013;
        strmov(dst: v3);
        strmov(dst: unknown_sqlstate);
      }
    }
    *(_DWORD *)(a1 + 940) = 0;
    memset(dst: (unsigned __int8 *)(a1 + 760), value: 0, count: 0x88u);
    *(_BYTE *)(a1 + 900) = 0;
    mysql_close(a1);
    qmemcpy((void *)a1, mysql, 968);
    net_clear();
    *(_DWORD *)(a1 + 696) = -1;
    *(_DWORD *)(a1 + 700) = -1;
    return 0;
  }
  else
  {
    *(_DWORD *)(a1 + 748) &= ~1u;
    set_mysql_error(a1, a2: 0x7D6u);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040E110
// Name: cli_read_query_result
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x0040E2F0
// Name: _cli_advanced_command
// Source: json
//------------------------------------------------------------------------------
bool __cdecl cli_advanced_command(
        const LoggingContext_t *header,
        int a2,
        int a3,
        unsigned int header_length,
        const LoggingContext_t *arg,
        unsigned int a6,
        char skip_check,
        int stmt_skip)
{
  unsigned int v9; // eax
  char v10; // [esp+Bh] [ebp-1h]
  bool stmt_skipa; // [esp+2Ch] [ebp+20h]

  v10 = 1;
  stmt_skipa = stmt_skip != 0 && *(_DWORD *)(stmt_skip + 172) != 1;
  if ( header->m_ChannelID != 0 || mysql_reconnect(a1: (int)header) == 0 && !stmt_skipa )
  {
    if ( header[56].m_ChannelID == 0 && (header[46].m_Color._color[0] & 8) == 0 )
    {
      net_clear_error(net: (const char *)header);
      header[43].m_Severity = -1;
      header[43].m_Color = (Color)-1;
      header[40].m_Severity = LS_MESSAGE;
      net_clear();
      if ( net_write_command() != 0 )
      {
        if ( header[5].m_Severity == 1153 )
        {
          set_mysql_error(a1: (int)header, a2: 0x7E4u);
          return true;
        }
        end_server(a1: header);
        if ( mysql_reconnect(a1: (int)header) != 0 || stmt_skipa )
          return v10;
        if ( net_write_command() != 0 )
        {
          set_mysql_error(a1: (int)header, a2: 0x7D6u);
          return true;
        }
      }
      v10 = 0;
      if ( skip_check == 0 )
      {
        v9 = cli_safe_read(net: (void *)header);
        header[45].m_Flags = v9;
        return v9 == -1;
      }
      return v10;
    }
    set_mysql_error(a1: (int)header, a2: 0x7DEu);
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x0040E470
// Name: __my_thread_var
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LPVOID _my_thread_var()
{
  return TlsGetValue(dwTlsIndex: THR_KEY_mysys);
}
