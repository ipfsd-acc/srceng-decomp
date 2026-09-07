// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/xbox/xlspmakefiles/makexlspfiles.cpp
// Functions: 12
// ============================================================

#include "utils\xbox\xlspmakefiles\makexlspfiles.h"

//------------------------------------------------------------------------------
// Address: 0x00401000
// Name: void NET_Init(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NET_Init()
{
  int v0; // eax
  const char *v1; // eax
  int v2; // [esp-4h] [ebp-194h]
  WSAData wsaData; // [esp+0h] [ebp-190h] BYREF

  v0 = WSAStartup(wVersionRequested: 2u, lpWSAData: &wsaData);
  if ( v0 != 0 )
  {
    v2 = v0;
    v1 = strerror(errnum: v0);
    _Error(a1: "NET_Init: socket: %s %i", v1, v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401040
// Name: bool NET_StringToSockaddr(char const __near *,struct sockaddr __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl NET_StringToSockaddr(const char *s, sockaddr *sadr)
{
  char v2; // al
  char *v3; // esi
  u_short v4; // ax
  unsigned int v5; // eax
  struct hostent *v7; // eax
  char copy[128]; // [esp+4h] [ebp-80h] BYREF

  *(_QWORD *)&sadr->sa_family = 0;
  *(_QWORD *)&sadr->sa_data[6] = 0;
  *(_DWORD *)&sadr->sa_family = 2;
  strcpy(copy, s);
  v2 = copy[0];
  v3 = copy;
  if ( copy[0] != 0 )
  {
    do
    {
      if ( *v3 == 58 )
      {
        *v3 = 0;
        v4 = atoi(nptr: v3 + 1);
        *(_WORD *)sadr->sa_data = htons(hostshort: v4);
      }
      ++v3;
    }
    while ( *v3 != 0 );
    v2 = copy[0];
  }
  if ( (unsigned __int8)(v2 - 48) > 9u )
  {
    v7 = gethostbyname(name: copy);
    if ( v7 == nullptr )
      return 0;
    *(_DWORD *)&sadr->sa_data[2] = **(_DWORD **)v7->h_addr_list;
  }
  else
  {
    v5 = inet_addr(cp: copy);
    *(_DWORD *)&sadr->sa_data[2] = v5;
    if ( v5 == -1 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004010F0
// Name: void WriteToConfig(char __near *,...)
// Source: json
//------------------------------------------------------------------------------
void WriteToConfig(char *pFormat, ...)
{
  char pDest[4096]; // [esp+0h] [ebp-1000h] BYREF
  va_list params; // [esp+100Ch] [ebp+Ch] BYREF

  va_start(params, pFormat);
  V_vsnprintf(pDest, maxLen: 4096, pFormat, params);
  if ( g_bSpewOnly )
  {
    _Msg(a1: "%s", pDest);
  }
  else if ( g_fpOutputConfig != nullptr )
  {
    fprintf(str: g_fpOutputConfig, format: "%s", pDest);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401160
// Name: void EmitHeader(class KeyValues __near *,char const __near *,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl EmitHeader(
        KeyValues *pHeaderKey,
        const char *pSGName,
        int nMasterPortStart,
        int nNumMasters,
        int nServerPortStart,
        int nNumServers)
{
  KeyValues *FirstSubKey; // edi
  const char *Name; // ebx
  KeyValues *NextKey; // esi
  const char *v9; // ebx
  char *String; // edi
  char szString[256]; // [esp+0h] [ebp-104h] BYREF
  const char *pValue; // [esp+100h] [ebp-4h]
  KeyValues *pHeaderKeya; // [esp+10Ch] [ebp+8h]

  if ( pHeaderKey != nullptr )
  {
    FirstSubKey = KeyValues::GetFirstSubKey(this: pHeaderKey);
    pHeaderKeya = FirstSubKey;
    if ( FirstSubKey != nullptr )
    {
      while ( 1 )
      {
        Name = KeyValues::GetName(this: FirstSubKey);
        pValue = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: setName);
        NextKey = KeyValues::GetFirstSubKey(this: FirstSubKey);
        if ( NextKey != nullptr )
        {
          WriteToConfig(pFormat: "\n%s\n", Name);
          WriteToConfig(pFormat: "{\n");
          do
          {
            v9 = KeyValues::GetName(this: NextKey);
            String = (char *)KeyValues::GetString(this: NextKey, keyName: nullptr, defaultValue: setName);
            if ( _V_stricmp(s1: v9, s2: "UserData") == 0 )
            {
              V_snprintf(
                pDest: szString,
                maxLen: 256,
                pFormat: "%s**%d_%d_%d_%d",
                pSGName,
                nMasterPortStart,
                nNumMasters,
                nServerPortStart,
                nNumServers);
              String = szString;
            }
            WriteToConfig(pFormat: "\t%-24s %s\n", v9, String);
            NextKey = KeyValues::GetNextKey(this: NextKey);
          }
          while ( NextKey != nullptr );
          WriteToConfig(pFormat: "}\n");
          FirstSubKey = pHeaderKeya;
        }
        else
        {
          WriteToConfig(pFormat: "%-24s %s\n", Name, pValue);
        }
        pHeaderKeya = KeyValues::GetNextKey(this: FirstSubKey);
        if ( pHeaderKeya == nullptr )
          break;
        FirstSubKey = pHeaderKeya;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004012A0
// Name: void Usage(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __noreturn Usage()
{
  _Msg(a1: "usage: xlspmakefiles <DataCenterName> [options]\n");
  _Msg(a1: "options:\n");
  _Msg(a1: "-debug    Spew only, don't write files\n");
  exit(code: -1);
}

//------------------------------------------------------------------------------
// Address: 0x004012D0
// Name: bool ReadFileToBuffer(char const __near *,class CUtlBuffer __near &,bool)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl ReadFileToBuffer(const char *pSourceName, CUtlBuffer *buffer, bool bText)
{
  int v3; // eax
  int v4; // edi
  int v6; // esi
  int *v7; // eax
  int status; // [esp+4h] [ebp-8h]
  bool bSuccess; // [esp+Bh] [ebp-1h]

  bSuccess = true;
  v3 = _open(path: pSourceName, oflag: 0x8000, pmode: 0);
  v4 = v3;
  if ( v3 == -1 )
    return false;
  _lseek(fh: v3, pos: 0, mthd: 2);
  v6 = _tell(filedes: v4);
  _lseek(fh: v4, pos: 0, mthd: 0);
  CUtlBuffer::EnsureCapacity(this: buffer, num: v6);
  CUtlBuffer::SeekPut(this: buffer, type: SEEK_CURRENT, offset: v6);
  status = _read(fh: v4, buf: buffer->m_Memory.m_pMemory, cnt: v6);
  if ( status != v6 )
  {
    v7 = _errno();
    _Warning(a1: "ReadFileToBuffer(): read failure %d, errno=%d\n", status, *v7);
    bSuccess = false;
  }
  if ( bText )
    CUtlBuffer::SetBufferType(this: buffer, bIsText: true, bContainsCRLF: true);
  else
    CUtlBuffer::SetBufferType(this: buffer, bIsText: false, bContainsCRLF: false);
  _close(fh: v4);
  return bSuccess;
}

//------------------------------------------------------------------------------
// Address: 0x00401390
// Name: public: void CUtlMemory<struct xlspAddress_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<xlspAddress_t,int>::Grow(CUtlMemory<xlspAddress_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  xlspAddress_t *m_pMemory; // edx
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
    v7 = 260 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (xlspAddress_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (xlspAddress_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401430
// Name: public: void CUtlMemory<void (*)(class IConVar __near *,char const __near *,float),int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>::Grow(
        CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  void (__cdecl **m_pMemory)(IConVar *, const char *, float); // edx
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
      this->m_pMemory = (void (__cdecl **)(IConVar *, const char *, float))_g_pMemAlloc->Realloc_2(
                                                                             this: _g_pMemAlloc,
                                                                             a2: m_pMemory,
                                                                             a3: v7);
    else
      this->m_pMemory = (void (__cdecl **)(IConVar *, const char *, float))_g_pMemAlloc->Alloc_2(
                                                                             this: _g_pMemAlloc,
                                                                             a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004014C0
// Name: bool MakeSecureGatewayConfig(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl MakeSecureGatewayConfig(KeyValues *pKV)
{
  const char *Name; // esi
  const char *v2; // ebx
  int m_Size; // esi
  KeyValues **m_pMemory; // ebx
  KeyValues *FirstSubKey; // eax
  const char *v6; // eax
  int v7; // edi
  int *v8; // edi
  KeyValues *Key; // esi
  const char *String; // eax
  KeyValues *v11; // edi
  KeyValues *v12; // esi
  KeyValues *v13; // esi
  KeyValues *v14; // esi
  KeyValues *v15; // esi
  int v16; // ebx
  KeyValues *v17; // esi
  const char *v18; // edi
  const char *v19; // esi
  u_short v20; // ax
  int v21; // esi
  xlspAddress_t *v22; // edi
  int v23; // esi
  xlspAddress_t *v24; // edi
  xlspAddress_t *v25; // edi
  int v26; // eax
  xlspAddress_t *v27; // ecx
  int nPort; // edx
  KeyValues *v29; // esi
  xlspAddress_t *v30; // edi
  const char *v31; // ebx
  KeyValues *v32; // esi
  const char *v33; // edi
  const char *v34; // esi
  u_short v35; // ax
  int v36; // esi
  xlspAddress_t *v37; // edi
  const char *v38; // esi
  xlspAddress_t *v39; // edi
  xlspAddress_t *v40; // edi
  int v41; // eax
  int v42; // edx
  xlspAddress_t *v43; // ecx
  int v44; // esi
  int v45; // edi
  int v46; // esi
  KeyValues *v47; // eax
  char *v48; // esi
  char *v49; // edi
  char *v50; // esi
  char *v51; // edi
  const char *v53; // [esp-14h] [ebp-2C8h]
  int v54; // [esp-Ch] [ebp-2C0h]
  int v55; // [esp-8h] [ebp-2BCh]
  char timeString[256]; // [esp+Ch] [ebp-2A8h] BYREF
  xlspAddress_t xlspAddress; // [esp+10Ch] [ebp-1A8h] BYREF
  tm tmv; // [esp+210h] [ebp-A4h] BYREF
  sockaddr_in address; // [esp+234h] [ebp-80h] BYREF
  sockaddr sadr; // [esp+244h] [ebp-70h] BYREF
  KeyValues *pServersKey; // [esp+254h] [ebp-60h]
  KeyValues *pHeaderKey; // [esp+258h] [ebp-5Ch]
  const char *pProtocolString; // [esp+25Ch] [ebp-58h]
  const char *pSGName; // [esp+260h] [ebp-54h]
  int nInterfaceId; // [esp+264h] [ebp-50h]
  const char *pServiceString; // [esp+268h] [ebp-4Ch]
  CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > configList; // [esp+26Ch] [ebp-48h] BYREF
  CUtlVector<xlspAddress_t,CUtlMemory<xlspAddress_t,int> > titleServers; // [esp+280h] [ebp-34h] BYREF
  CUtlVector<xlspAddress_t,CUtlMemory<xlspAddress_t,int> > masterServers; // [esp+294h] [ebp-20h] BYREF
  KeyValues *pTitleServersKey; // [esp+2A8h] [ebp-Ch]
  int iConfig; // [esp+2ACh] [ebp-8h]
  const char *pOutputFilename; // [esp+2B0h] [ebp-4h]

  Name = KeyValues::GetName(this: pKV);
  v2 = V_stristr(pStr: Name, pSearch: "**");
  if ( v2 == nullptr )
    _Error(a1: "MakeSecureGatewayConfig: Malformed SG Name '%s'", Name);
  pSGName = v2 + 2;
  if ( !g_bSpewOnly )
    _Msg(a1: "\nSecureGateway: %s\n", Name);
  m_Size = 0;
  m_pMemory = nullptr;
  memset(&configList, 0, sizeof(configList));
  FirstSubKey = KeyValues::GetFirstSubKey(this: pKV);
  iConfig = (int)FirstSubKey;
  if ( FirstSubKey == nullptr )
    goto LABEL_15;
  do
  {
    v6 = KeyValues::GetName(this: FirstSubKey);
    if ( V_strnicmp(s1: v6, s2: "config_", n: 7) == 0 )
    {
      v7 = m_Size;
      if ( m_Size + 1 > configList.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>::Grow(
          this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&configList,
          num: m_Size - configList.m_Memory.m_nAllocationCount + 1);
        m_Size = configList.m_Size;
        m_pMemory = configList.m_Memory.m_pMemory;
      }
      configList.m_Size = ++m_Size;
      configList.m_pElements = m_pMemory;
      if ( m_Size - v7 - 1 > 0 )
        _V_memmove(dest: &m_pMemory[v7 + 1], src: &m_pMemory[v7], count: 4 * (m_Size - v7 - 1));
      v8 = (int *)&m_pMemory[v7];
      if ( v8 != nullptr )
        *v8 = iConfig;
    }
    FirstSubKey = KeyValues::GetNextKey(this: (KeyValues *)iConfig);
    iConfig = (int)FirstSubKey;
  }
  while ( FirstSubKey != nullptr );
  if ( m_Size == 0 )
LABEL_15:
    _Error(a1: "MakeSecureGatewayConfig: Missing key '%s'", "Config_<???>");
  iConfig = 0;
  if ( m_Size > 0 )
  {
    do
    {
      Key = KeyValues::FindKey(this: configList.m_Memory.m_pMemory[iConfig], keyName: "OutputFile", bCreate: false);
      if ( Key == nullptr )
        _Error(a1: "MakeSecureGatewayConfig: Missing key '%s'", "OutputFile");
      String = KeyValues::GetString(this: Key, keyName: nullptr, defaultValue: setName);
      pOutputFilename = String;
      if ( !g_bSpewOnly )
        _Msg(a1: "Generating: %s\n\n", String);
      pHeaderKey = KeyValues::FindKey(this: pKV, keyName: "Header", bCreate: false);
      if ( pHeaderKey == nullptr )
        _Error(a1: "MakeSecureGatewayConfig: Missing key '%s'", "Header");
      v11 = KeyValues::FindKey(this: pKV, keyName: "Servers", bCreate: false);
      pServersKey = v11;
      if ( v11 == nullptr )
        _Error(a1: "MakeSecureGatewayConfig: Missing key '%s'", "Servers");
      v12 = KeyValues::FindKey(this: v11, keyName: "Service", bCreate: false);
      if ( v12 == nullptr )
        _Error(a1: "MakeSecureGatewayConfig: Missing key '%s'", "Service");
      pServiceString = KeyValues::GetString(this: v12, keyName: nullptr, defaultValue: setName);
      v13 = KeyValues::FindKey(this: v11, keyName: "InterfaceId", bCreate: false);
      if ( v13 == nullptr )
        _Error(a1: "MakeSecureGatewayConfig: Missing key '%s'", "InterfaceId");
      nInterfaceId = KeyValues::GetInt(this: v13, keyName: nullptr, defaultValue: 0);
      v14 = KeyValues::FindKey(this: v11, keyName: "Protocol", bCreate: false);
      if ( v14 == nullptr )
        _Error(a1: "MakeSecureGatewayConfig: Missing key '%s'", "Protocol");
      pProtocolString = KeyValues::GetString(this: v14, keyName: nullptr, defaultValue: setName);
      v15 = KeyValues::FindKey(this: v11, keyName: "MasterServers", bCreate: false);
      if ( v15 == nullptr )
        _Error(a1: "MakeSecureGatewayConfig: Missing key '%s'", "MasterServers");
      v16 = 0;
      memset(&masterServers, 0, sizeof(masterServers));
      pTitleServersKey = KeyValues::GetFirstSubKey(this: v15);
      if ( pTitleServersKey != nullptr )
      {
        do
        {
          v17 = pTitleServersKey;
          v18 = KeyValues::GetName(this: pTitleServersKey);
          v19 = KeyValues::GetString(this: v17, keyName: nullptr, defaultValue: setName);
          xlspAddress.nPort = atoi(nptr: v18);
          if ( NET_StringToSockaddr(s: v19, sadr: (sockaddr *)&address) == 0 )
            _Error(a1: "MakeSecureGatewayConfig: Failed to resolve '%s'", v19);
          v20 = ntohs(netshort: address.sin_port);
          V_snprintf(
            pDest: xlspAddress.address,
            maxLen: 256,
            pFormat: "%i.%i.%i.%i:%i",
            address.sin_addr.S_un.S_un_b.s_b1,
            address.sin_addr.S_un.S_un_b.s_b2,
            address.sin_addr.S_un.S_un_b.s_b3,
            address.sin_addr.S_un.S_un_b.s_b4,
            v20);
          v21 = 0;
          if ( v16 > 0 )
          {
            v22 = masterServers.m_Memory.m_pMemory;
            while ( _V_stricmp(s1: v22->address, s2: xlspAddress.address) != 0 && v22->nPort != xlspAddress.nPort )
            {
              ++v21;
              ++v22;
              if ( v21 >= v16 )
                goto LABEL_43;
            }
            _Error(
              a1: "MakeSecureGatewayConfig: Duplicate master server address '%s' or port '%d'",
              xlspAddress.address,
              xlspAddress.nPort);
          }
LABEL_43:
          v23 = v16;
          if ( v16 + 1 > masterServers.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<xlspAddress_t,int>::Grow(
              this: &masterServers.m_Memory,
              num: v16 - masterServers.m_Memory.m_nAllocationCount + 1);
            v16 = masterServers.m_Size;
          }
          v24 = masterServers.m_Memory.m_pMemory;
          masterServers.m_Size = ++v16;
          masterServers.m_pElements = masterServers.m_Memory.m_pMemory;
          if ( v16 - v23 - 1 > 0 )
            _V_memmove(
              dest: &masterServers.m_Memory.m_pMemory[v23 + 1],
              src: &masterServers.m_Memory.m_pMemory[v23],
              count: 260 * (v16 - v23 - 1));
          v25 = &v24[v23];
          if ( v25 != nullptr )
            *v25 = xlspAddress;
          pTitleServersKey = KeyValues::GetNextKey(this: pTitleServersKey);
        }
        while ( pTitleServersKey != nullptr );
        v11 = pServersKey;
      }
      v26 = 0;
      if ( v16 > 0 )
      {
        v27 = masterServers.m_Memory.m_pMemory;
        nPort = masterServers.m_Memory.m_pMemory->nPort;
        while ( v27->nPort == nPort )
        {
          ++v26;
          ++v27;
          ++nPort;
          if ( v26 >= v16 )
            goto LABEL_57;
        }
        _Error(a1: "MakeSecureGatewayConfig: Master server XLSP ports are not numerically ascending.");
      }
LABEL_57:
      v29 = KeyValues::FindKey(this: v11, keyName: "TitleServers", bCreate: false);
      if ( v29 == nullptr )
        _Error(a1: "MakeSecureGatewayConfig: Missing key '%s'", "TitleServers");
      v30 = nullptr;
      v31 = nullptr;
      memset(&titleServers, 0, sizeof(titleServers));
      pTitleServersKey = KeyValues::GetFirstSubKey(this: v29);
      if ( pTitleServersKey != nullptr )
      {
        do
        {
          v32 = pTitleServersKey;
          v33 = KeyValues::GetName(this: pTitleServersKey);
          v34 = KeyValues::GetString(this: v32, keyName: nullptr, defaultValue: setName);
          xlspAddress.nPort = atoi(nptr: v33);
          if ( NET_StringToSockaddr(s: v34, &sadr) == 0 )
            _Error(a1: "MakeSecureGatewayConfig: Failed to resolve '%s'", v34);
          v35 = ntohs(netshort: *(u_short *)sadr.sa_data);
          V_snprintf(
            pDest: xlspAddress.address,
            maxLen: 256,
            pFormat: "%i.%i.%i.%i:%i",
            (unsigned __int8)sadr.sa_data[2],
            (unsigned __int8)sadr.sa_data[3],
            (unsigned __int8)sadr.sa_data[4],
            (unsigned __int8)sadr.sa_data[5],
            v35);
          v36 = 0;
          if ( (int)v31 > 0 )
          {
            v37 = titleServers.m_Memory.m_pMemory;
            while ( _V_stricmp(s1: v37->address, s2: xlspAddress.address) != 0 && v37->nPort != xlspAddress.nPort )
            {
              ++v36;
              ++v37;
              if ( v36 >= (int)v31 )
                goto LABEL_69;
            }
            _Error(
              a1: "MakeSecureGatewayConfig: Duplicate title server address '%s' or port '%d'",
              xlspAddress.address,
              xlspAddress.nPort);
          }
LABEL_69:
          v38 = v31;
          if ( (int)(v31 + 1) > titleServers.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<xlspAddress_t,int>::Grow(
              this: &titleServers.m_Memory,
              num: (int)&v31[-titleServers.m_Memory.m_nAllocationCount + 1]);
            v31 = (const char *)titleServers.m_Size;
          }
          v39 = titleServers.m_Memory.m_pMemory;
          titleServers.m_Size = (int)++v31;
          titleServers.m_pElements = titleServers.m_Memory.m_pMemory;
          if ( v31 - v38 - 1 > 0 )
            _V_memmove(
              dest: &titleServers.m_Memory.m_pMemory[(int)v38 + 1],
              src: &titleServers.m_Memory.m_pMemory[(_DWORD)v38],
              count: 260 * (v31 - v38 - 1));
          v40 = &v39[(_DWORD)v38];
          if ( v40 != nullptr )
            *v40 = xlspAddress;
          pTitleServersKey = KeyValues::GetNextKey(this: pTitleServersKey);
        }
        while ( pTitleServersKey != nullptr );
        v30 = titleServers.m_Memory.m_pMemory;
      }
      v41 = 0;
      if ( (int)v31 > 0 )
      {
        v42 = v30->nPort;
        v43 = v30;
        while ( v43->nPort == v42 )
        {
          ++v41;
          ++v43;
          ++v42;
          if ( v41 >= (int)v31 )
            goto LABEL_83;
        }
        _Error(a1: "MakeSecureGatewayConfig: Title server XLSP ports are not numerically ascending.");
      }
LABEL_83:
      v44 = titleServers.m_Memory.m_pMemory->nPort;
      v45 = masterServers.m_Memory.m_pMemory->nPort;
      if ( !g_bSpewOnly )
      {
        g_fpOutputConfig = fopen(file: pOutputFilename, mode: "wt");
        if ( g_fpOutputConfig == nullptr )
          _Error(a1: "MakeSecureGatewayConfig: Cannot open '%s'", pOutputFilename);
      }
      _Plat_GetLocalTime(a1: &tmv);
      _Plat_GetTimeString(a1: &tmv, a2: timeString, a3: 256);
      WriteToConfig(pFormat: "; AUTO GENERATED - %s\n", timeString);
      WriteToConfig(pFormat: "\n");
      EmitHeader(
        pHeaderKey,
        pSGName,
        nMasterPortStart: v45,
        nNumMasters: masterServers.m_Size,
        nServerPortStart: v44,
        nNumServers: (int)v31);
      v55 = v44;
      v46 = masterServers.m_Size;
      v54 = masterServers.m_Size;
      v53 = pSGName;
      v47 = KeyValues::FindKey(this: configList.m_Memory.m_pMemory[iConfig], keyName: "Header", bCreate: false);
      EmitHeader(
        pHeaderKey: v47,
        pSGName: v53,
        nMasterPortStart: v45,
        nNumMasters: v54,
        nServerPortStart: v55,
        nNumServers: (int)v31);
      WriteToConfig(pFormat: "\n");
      WriteToConfig(pFormat: ";****************************************************************************************************\n");
      WriteToConfig(pFormat: ";MASTER SERVERS\n");
      WriteToConfig(pFormat: ";****************************************************************************************************\n");
      if ( v46 > 0 )
      {
        v48 = masterServers.m_Memory.m_pMemory->address;
        pOutputFilename = (const char *)masterServers.m_Size;
        do
        {
          v49 = V_stristr(pStr: v48, pSearch: ":");
          *v49 = 0;
          WriteToConfig(pFormat: "\nServer\n");
          WriteToConfig(pFormat: "{\n");
          WriteToConfig(pFormat: "\t%-24s %d\n", "Id", *((_DWORD *)v48 - 1));
          WriteToConfig(pFormat: "\t%-24s %s\n", "Service", pServiceString);
          WriteToConfig(pFormat: "\t%-24s { InterfaceId %d Ip %s Port %s }\n", "Address", nInterfaceId, v48, v49 + 1);
          WriteToConfig(pFormat: "\t%-24s %s\n", "Protocol", pProtocolString);
          WriteToConfig(pFormat: "}\n");
          v48 += 260;
          --pOutputFilename;
        }
        while ( pOutputFilename != nullptr );
      }
      WriteToConfig(pFormat: "\n");
      WriteToConfig(pFormat: ";****************************************************************************************************\n");
      WriteToConfig(pFormat: ";TITLE SERVERS\n");
      WriteToConfig(pFormat: ";****************************************************************************************************\n");
      if ( (int)v31 > 0 )
      {
        v50 = titleServers.m_Memory.m_pMemory->address;
        for ( pOutputFilename = v31; pOutputFilename != nullptr; --pOutputFilename )
        {
          v51 = V_stristr(pStr: v50, pSearch: ":");
          *v51 = 0;
          WriteToConfig(pFormat: "\nServer\n");
          WriteToConfig(pFormat: "{\n");
          WriteToConfig(pFormat: "\t%-24s %d\n", "Id", *((_DWORD *)v50 - 1));
          WriteToConfig(pFormat: "\t%-24s %s\n", "Service", pServiceString);
          WriteToConfig(pFormat: "\t%-24s { InterfaceId %d Ip %s Port %s }\n", "Address", nInterfaceId, v50, v51 + 1);
          WriteToConfig(pFormat: "\t%-24s %s\n", "Protocol", pProtocolString);
          WriteToConfig(pFormat: "}\n");
          v50 += 260;
        }
      }
      if ( g_fpOutputConfig != nullptr )
      {
        fclose(stream: g_fpOutputConfig);
        g_fpOutputConfig = nullptr;
      }
      if ( !g_bSpewOnly )
      {
        _Msg(a1: "MasterServers: %d\n", masterServers.m_Size);
        _Msg(a1: "TitleServers: %d\n", v31);
        _Msg(a1: "Finished.\n\n");
      }
      if ( titleServers.m_Memory.m_nGrowSize >= 0 )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: titleServers.m_Memory.m_pMemory);
      if ( masterServers.m_Memory.m_nGrowSize >= 0 )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: masterServers.m_Memory.m_pMemory);
      ++iConfig;
    }
    while ( iConfig < configList.m_Size );
  }
  if ( configList.m_Memory.m_nGrowSize >= 0 && configList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: configList.m_Memory.m_pMemory);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00401DC0
// Name: bool MakeXLSPFiles(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl MakeXLSPFiles(const char *pCenterName)
{
  int m_Size; // esi
  HMODULE ModuleHandleA; // eax
  KeyValues *v4; // eax
  KeyValues *v5; // edi
  KeyValues **m_pMemory; // ebx
  const char *Name; // eax
  int v8; // edi
  KeyValues **v9; // edi
  int i; // edi
  char szResolvedConfigName[260]; // [esp+0h] [ebp-358h] BYREF
  char exeName[260]; // [esp+104h] [ebp-254h] BYREF
  char szConfig[260]; // [esp+208h] [ebp-150h] BYREF
  CUtlBuffer xlspBuffer; // [esp+30Ch] [ebp-4Ch] BYREF
  CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > sgList; // [esp+33Ch] [ebp-1Ch] BYREF
  KeyValues *pKV; // [esp+350h] [ebp-8h]
  KeyValues *pSubKey; // [esp+354h] [ebp-4h]

  if ( !g_bSpewOnly )
    _Msg(a1: "\nMaking XLSP Files....\n");
  m_Size = 0;
  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  if ( GetModuleFileNameA(hModule: ModuleHandleA, lpFilename: exeName, nSize: 0x104u) != 0 )
  {
    V_StripFilename(path: exeName);
    V_strncat(pDest: exeName, pSrc: "\\..\\", destBufferSize: 0x104u, max_chars_to_copy: -1);
    V_snprintf(
      pDest: szResolvedConfigName,
      maxLen: 260,
      pFormat: "platform\\scripts\\XLSPTitleServers_%s.360.txt",
      pCenterName);
    V_ComposeFileName(path: exeName, filename: szResolvedConfigName, dest: szConfig, destSize: 260);
    CUtlBuffer::CUtlBuffer(this: &xlspBuffer, growSize: 0, initSize: 0, nFlags: 0);
    if ( ReadFileToBuffer(pSourceName: szConfig, buffer: &xlspBuffer, bText: true) )
    {
      v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v4 != nullptr )
      {
        v5 = KeyValues::KeyValues(this: v4, setName: "XLSPTitleServers");
        pKV = v5;
      }
      else
      {
        pKV = nullptr;
        v5 = nullptr;
      }
      if ( KeyValues::LoadFromBuffer(
             this: v5,
             resourceName: "XLSPTitleServers",
             buf: &xlspBuffer,
             pFileSystem: nullptr,
             pPathID: nullptr,
             pfnEvaluateSymbolProc: nullptr) )
      {
        m_pMemory = nullptr;
        memset(&sgList, 0, sizeof(sgList));
        pSubKey = KeyValues::GetFirstSubKey(this: v5);
        if ( pSubKey == nullptr )
          goto LABEL_28;
        do
        {
          Name = KeyValues::GetName(this: pSubKey);
          if ( V_stristr(pStr: Name, pSearch: "SecureGateway**") != nullptr )
          {
            v8 = m_Size;
            if ( m_Size + 1 > sgList.m_Memory.m_nAllocationCount )
            {
              CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>::Grow(
                this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&sgList,
                num: m_Size - sgList.m_Memory.m_nAllocationCount + 1);
              m_Size = sgList.m_Size;
              m_pMemory = sgList.m_Memory.m_pMemory;
            }
            sgList.m_Size = ++m_Size;
            sgList.m_pElements = m_pMemory;
            if ( m_Size - v8 - 1 > 0 )
              _V_memmove(dest: &m_pMemory[v8 + 1], src: &m_pMemory[v8], count: 4 * (m_Size - v8 - 1));
            v9 = &m_pMemory[v8];
            if ( v9 != nullptr )
              *v9 = pSubKey;
          }
          pSubKey = KeyValues::GetNextKey(this: pSubKey);
        }
        while ( pSubKey != nullptr );
        if ( m_Size == 0 )
LABEL_28:
          _Error(a1: "XLSPMaster: Missing key '%s' in XLSP Configuration '%s'", "SecureGateway_<xxx>", szConfig);
        for ( i = 0; i < m_Size; ++i )
          MakeSecureGatewayConfig(pKV: m_pMemory[i]);
        KeyValues::deleteThis(this: pKV);
        CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&sgList);
        if ( xlspBuffer.m_Memory.m_nGrowSize >= 0 && xlspBuffer.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: xlspBuffer.m_Memory.m_pMemory);
        return 1;
      }
      else
      {
        _Error(a1: "XLSPMaster: Failed to unserialize XLSP Configuration '%s'", szConfig);
        KeyValues::deleteThis(this: v5);
        if ( xlspBuffer.m_Memory.m_nGrowSize >= 0 && xlspBuffer.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: xlspBuffer.m_Memory.m_pMemory);
        return 0;
      }
    }
    else
    {
      _Error(a1: "XLSPMaster: Failed to load XLSP Configuration '%s'", szConfig);
      if ( xlspBuffer.m_Memory.m_nGrowSize >= 0 && xlspBuffer.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: xlspBuffer.m_Memory.m_pMemory);
      return 0;
    }
  }
  else
  {
    _Error(a1: "MakeXLSPFiles: Failed to get module name");
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402060
// Name: _main
// Source: json
//------------------------------------------------------------------------------
int __cdecl main(int argc, const char **argv, const char **envp)
{
  void (__thiscall ***v3)(_DWORD, int, const char **); // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax

  v3 = (void (__thiscall ***)(_DWORD, int, const char **))_CommandLine();
  (**v3)(a1: v3, a2: argc, a3: argv);
  v4 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v4 + 40))(a1: v4, a2: "-d") != 0
    || (v5 = _CommandLine(), (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v5 + 40))(a1: v5, a2: "-debug") != 0) )
  {
    g_bSpewOnly = true;
  }
  else
  {
    g_bSpewOnly = false;
    _Msg(a1: "\nXLSPMakeFiles - Valve XLSP Make Files ( Build: %s %s )\n", "Dec 28 2010", "17:00:13");
    _Msg(a1: "( C ) Copyright 1996-2008, Valve Corporation, All rights reserved.\n\n");
  }
  v6 = _CommandLine();
  if ( (*(int (__thiscall **)(int))(*(_DWORD *)v6 + 36))(a1: v6) < 2
    || (v7 = _CommandLine(), (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v7 + 40))(a1: v7, a2: "?") != 0)
    || (v8 = _CommandLine(), (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v8 + 40))(a1: v8, a2: "-h") != 0)
    || (v9 = _CommandLine(), (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v9 + 40))(a1: v9, a2: "-help") != 0) )
  {
    Usage();
  }
  NET_Init();
  MakeXLSPFiles(pCenterName: argv[1]);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00405AE0
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
