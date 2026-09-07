// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/xbox/xlspmaster/masterdlg.cpp
// Functions: 152
// ============================================================

#include "utils\xbox\xlspmaster\masterdlg.h"

//------------------------------------------------------------------------------
// Address: 0x004011A0
// Name: EncodePatchData
// Source: json
//------------------------------------------------------------------------------
void __usercall EncodePatchData(__int128 _XMM0@<xmm0>, const unsigned __int8 *pvData, int numBytes, KeyValues *kv)
{
  unsigned int v4; // ecx
  unsigned int v5; // ebx
  int v6; // esi
  int i; // edi
  int v8; // eax
  unsigned __int64 v9; // rax
  KeyValues *v10; // eax
  KeyValues *v11; // esi
  unsigned int ui_4; // [esp+4h] [ebp-4h]

  v4 = numBytes;
  if ( numBytes > 0 )
  {
    while ( 1 )
    {
      __asm { xorpd   xmm0, xmm0 }
      ui_4 = DWORD1(_XMM0);
      v5 = _XMM0;
      v6 = 0;
      for ( i = 0; ; i += 8 )
      {
        v8 = 8;
        if ( v4 <= 8 )
          v8 = v4;
        if ( v6 >= v8 )
          break;
        v9 = (unsigned __int64)pvData[v6] << i;
        ui_4 |= HIDWORD(v9);
        v4 = numBytes;
        v5 |= v9;
        ++v6;
      }
      pvData += 8;
      numBytes = v4 - 8;
      v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      v11 = v10 != nullptr ? KeyValues::KeyValues(this: v10, setName: defaultValue) : nullptr;
      KeyValues::SetUint64(this: v11, keyName: nullptr, value: __PAIR64__(ui_4, v5));
      KeyValues::AddSubKey(this: kv, pSubkey: v11);
      if ( numBytes <= 0 )
        break;
      v4 = numBytes;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401260
// Name: void SetCriteria(struct string_criteria_t __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetCriteria(string_criteria_t *c, const char *value)
{
  string_criteria_t *v2; // ebx
  char *v3; // esi
  int v4; // edi

  v2 = c;
  v3 = c->value;
  V_strncpy(pDest: c->value, pSrc: value, maxLen: 64);
  strlwr(string: v3);
  v4 = strlen(v3);
  v2->length = v4;
  CRC32_Init(pulCRC: (unsigned int *)&c);
  CRC32_ProcessBuffer(pulCRC: (unsigned int *)&c, pBuffer: v3, nBuffer: v4);
  CRC32_Final(pulCRC: (unsigned int *)&c);
  v2->checksum = (int)c;
}

//------------------------------------------------------------------------------
// Address: 0x004012C0
// Name: AddressLessFunc
// Source: json
//------------------------------------------------------------------------------
bool __cdecl AddressLessFunc(const sockaddr_in *lhs, const sockaddr_in *rhs)
{
  in_addr::<unnamed_type_S_un> S_un; // eax
  in_addr::<unnamed_type_S_un> v3; // ecx

  S_un = lhs->sin_addr.S_un;
  v3 = rhs->sin_addr.S_un;
  if ( S_un.S_addr < v3.S_addr )
    return true;
  if ( S_un.S_addr <= v3.S_addr )
    return lhs->sin_port < rhs->sin_port;
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x004012F0
// Name: class KeyValues __near * FindKeyRecursive(class KeyValues __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__cdecl FindKeyRecursive(KeyValues *pKV, const char *pFindName)
{
  const char *Name; // eax
  KeyValues *result; // eax
  KeyValues *FirstSubKey; // esi

  Name = KeyValues::GetName(this: pKV);
  if ( _V_stricmp(s1: Name, s2: pFindName) == 0 )
    return pKV;
  FirstSubKey = KeyValues::GetFirstSubKey(this: pKV);
  if ( FirstSubKey == nullptr )
    return nullptr;
  while ( 1 )
  {
    result = FindKeyRecursive(pKV: FirstSubKey, pFindName);
    if ( result != nullptr )
      break;
    FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
    if ( FirstSubKey == nullptr )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00401350
// Name: private: void CMasterDlg::ClearLogWindow(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterDlg::ClearLogWindow(CMasterDlg *this)
{
  SetWindowTextA(hWnd: this->m_hLogWnd, lpString: defaultValue);
}

//------------------------------------------------------------------------------
// Address: 0x00401370
// Name: private: void CMasterDlg::TimeoutServers(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CMasterDlg::TimeoutServers(CMasterDlg *this@<ecx>, __int128 _XMM0@<xmm0>, __int128 _XMM1@<xmm1>)
{
  sv_t **m_pGameServers; // edi
  int i; // ebx
  sv_t **j; // esi
  double current; // [esp+4h] [ebp-8h]

  current = _Plat_FloatTime();
  if ( current - tLastTimeOut >= 60.0 )
  {
    __asm { movsd   xmm0, [ebp+current] }
    __asm { movsd   tLastTimeOut, xmm0 }
    m_pGameServers = this->m_pGameServers;
    for ( i = 2019; i != 0; --i )
    {
      _EAX = *m_pGameServers;
      for ( j = m_pGameServers; *j != nullptr; _EAX = *j )
      {
        __asm
        {
          movd    xmm0, dword ptr [eax+1Ch]
          movsd   xmm1, [ebp+current]
          cvtdq2pd xmm0, xmm0
          subsd   xmm1, xmm0
          movsd   xmm0, ds:__real@4082c00000000000
        }
        if ( *(double *)&_XMM0 <= *(double *)&_XMM1 )
        {
          *j = _EAX->next;
          free(pMem: _EAX);
        }
        else
        {
          j = &_EAX->next;
        }
      }
      ++m_pGameServers;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401410
// Name: private: void CMasterDlg::CloseLogFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterDlg::CloseLogFile(CMasterDlg *this)
{
  if ( this->m_pLogfile != nullptr )
  {
    fclose(stream: this->m_pLogfile);
    this->m_pLogfile = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401440
// Name: private: void CMasterDlg::Sys_MessageBox(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CMasterDlg::Sys_MessageBox(CMasterDlg *this, char *pFormat, ...)
{
  char string[4096]; // [esp+0h] [ebp-1000h] BYREF
  va_list ap; // [esp+1010h] [ebp+10h] BYREF

  va_start(ap, pFormat);
  vsprintf_s(string, sizeInBytes: 0x1000u, format: pFormat, ap);
  MessageBoxA(hWnd: nullptr, lpText: string, lpCaption: "Warning!", uType: 0x42000u);
}

//------------------------------------------------------------------------------
// Address: 0x00401490
// Name: private: bool CMasterDlg::NET_StringToSockaddr(char const __near *,struct sockaddr __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CMasterDlg::NET_StringToSockaddr@<al>(
        CMasterDlg *this@<ecx>,
        __int128 _XMM0@<xmm0>,
        const char *s,
        sockaddr *sadr)
{
  char v6; // al
  char *v7; // esi
  u_short v8; // ax
  unsigned int v9; // eax
  struct hostent *v11; // eax
  char copy[128]; // [esp+4h] [ebp-80h] BYREF

  _EDI = sadr;
  __asm
  {
    pxor    xmm0, xmm0
    movq    qword ptr [edi], xmm0
  }
  __asm { movq    qword ptr [edi+8], xmm0 }
  *(_DWORD *)&sadr->sa_family = 2;
  strcpy(copy, s);
  v6 = copy[0];
  v7 = copy;
  if ( copy[0] != 0 )
  {
    do
    {
      if ( *v7 == 58 )
      {
        *v7 = 0;
        v8 = atoi(nptr: v7 + 1);
        *(_WORD *)sadr->sa_data = htons(hostshort: v8);
      }
      ++v7;
    }
    while ( *v7 != 0 );
    v6 = copy[0];
  }
  if ( (unsigned __int8)(v6 - 48) > 9u )
  {
    v11 = gethostbyname(name: copy);
    if ( v11 == nullptr )
      return 0;
    *(_DWORD *)&sadr->sa_data[2] = **(_DWORD **)v11->h_addr_list;
  }
  else
  {
    v9 = inet_addr(cp: copy);
    *(_DWORD *)&sadr->sa_data[2] = v9;
    if ( v9 == -1 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00401540
// Name: private: void CMasterDlg::Sys_Printf(char __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CMasterDlg::Sys_Printf(CMasterDlg *this, char *pMsg, ...)
{
  HWND__ *m_hWnd; // [esp-18h] [ebp-1024h]
  char string[4096]; // [esp+4h] [ebp-1008h] BYREF
  LPARAM lParam[2]; // [esp+1004h] [ebp-8h] BYREF
  va_list ap; // [esp+101Ch] [ebp+10h] BYREF

  va_start(ap, pMsg);
  if ( this->m_bShowTraffic )
  {
    vsprintf_s(string, sizeInBytes: 0x1000u, format: pMsg, ap);
    m_hWnd = this->m_hWnd;
    lParam[0] = -1;
    lParam[1] = -2;
    SendDlgItemMessageA(hDlg: m_hWnd, nIDDlgItem: 1001, Msg: 0x437u, wParam: 0, (LPARAM)lParam);
    SendDlgItemMessageA(hDlg: this->m_hWnd, nIDDlgItem: 1001, Msg: 0xC2u, wParam: 0, lParam: (LPARAM)string);
    SendDlgItemMessageA(hDlg: this->m_hWnd, nIDDlgItem: 1001, Msg: 0xB7u, wParam: 0, lParam: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004015E0
// Name: private: char __near * CMasterDlg::MSG_ReadString(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CMasterDlg::MSG_ReadString(CMasterDlg *this)
{
  int m_msg_readcount; // edx
  char *result; // eax
  int v3; // esi
  unsigned __int8 v4; // dl
  int v5; // edx
  bool v6; // bl
  int v7; // edx
  unsigned __int8 v8; // bl

  m_msg_readcount = this->m_msg_readcount;
  result = (char *)&this->m_PacketData[m_msg_readcount];
  if ( m_msg_readcount < this->m_packet_length )
  {
    do
    {
      v3 = this->m_msg_readcount;
      v4 = this->m_PacketData[v3];
      if ( v4 == 13 )
        break;
      if ( v4 == 10 )
        break;
      if ( v4 == 0 )
        break;
      this->m_msg_readcount = v3 + 1;
    }
    while ( v3 + 1 < this->m_packet_length );
  }
  v5 = this->m_msg_readcount;
  v6 = this->m_PacketData[v5] != 0;
  this->m_PacketData[v5] = 0;
  v7 = ++this->m_msg_readcount;
  if ( v6 )
  {
    while ( 1 )
    {
      v8 = this->m_PacketData[v7];
      if ( v8 != 13 && v8 != 10 )
        break;
      this->m_msg_readcount = ++v7;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00401680
// Name: private: void CMasterDlg::FreeServers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterDlg::FreeServers(CMasterDlg *this)
{
  sv_t **m_pGameServers; // edi
  int i; // ebx
  sv_t *v3; // eax
  sv_t *next; // esi
  modsv_t *v5; // eax
  modsv_t *v6; // esi
  CMasterDlg *v7; // [esp+Ch] [ebp-4h]

  v7 = this;
  m_pGameServers = this->m_pGameServers;
  for ( i = 2019; i != 0; --i )
  {
    v3 = *m_pGameServers;
    if ( *m_pGameServers != nullptr )
    {
      do
      {
        next = v3->next;
        free(pMem: v3);
        v3 = next;
      }
      while ( next != nullptr );
      this = v7;
    }
    *m_pGameServers++ = nullptr;
  }
  v5 = this->m_pMods[0];
  if ( v5 != nullptr )
  {
    do
    {
      v6 = v5->next;
      free(pMem: v5);
      v5 = v6;
    }
    while ( v6 != nullptr );
    v7->m_pMods[0] = nullptr;
  }
  else
  {
    this->m_pMods[0] = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401710
// Name: private: int CMasterDlg::HashServer(struct sockaddr_in __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CMasterDlg::HashServer(CMasterDlg *this, sockaddr_in *address)
{
  return (SHIBYTE(address->sin_port)
        ^ ((SLOBYTE(address->sin_port)
          ^ (((char)address->sin_addr.S_un.S_un_b.s_b4
            ^ (((char)address->sin_addr.S_un.S_un_b.s_b3
              ^ (((char)address->sin_addr.S_un.S_un_b.s_b2
                ^ (((char)address->sin_addr.S_un.S_un_b.s_b1
                  ^ (unsigned int)(2 * (char)address->sin_addr.S_un.S_un_b.s_b1))
                 + 2 * (char)address->sin_addr.S_un.S_un_b.s_b2))
               + 2 * (char)address->sin_addr.S_un.S_un_b.s_b3))
             + 2 * (char)address->sin_addr.S_un.S_un_b.s_b4))
           + 2 * SLOBYTE(address->sin_port)))
         + 2 * SHIBYTE(address->sin_port)))
       % 0x7E3;
}

//------------------------------------------------------------------------------
// Address: 0x00401770
// Name: private: bool CMasterDlg::ServerMatchesCriteria(struct sv_t __near *,struct search_criteria_t __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMasterDlg::ServerMatchesCriteria(CMasterDlg *this, sv_t *server, search_criteria_t *criteria)
{
  bool result; // al
  int players; // esi
  int v5; // esi

  if ( criteria == nullptr )
    return true;
  if ( criteria->usegame != 0
    && (criteria->gamedir.checksum != server->gamedir.checksum || criteria->gamedir.length != server->gamedir.length)
    || criteria->usemap != 0
    && (criteria->map.checksum != server->map.checksum || criteria->map.length != server->map.length) )
  {
    return false;
  }
  result = true;
  if ( criteria->useempty != 0 )
  {
    if ( server->bIsReserved )
      return false;
    if ( server->gameId == E_GAME_L4D )
    {
      players = server->players;
      if ( players != 0 && players != server->bots )
        return false;
    }
    else if ( server->players != 0 )
    {
      return false;
    }
  }
  if ( criteria->usefull != 0 )
  {
    v5 = server->players;
    if ( server->gameId != E_GAME_L4D )
    {
      if ( v5 == server->maxPlayers )
        goto LABEL_22;
      return false;
    }
    if ( v5 - server->bots < 4 )
      return false;
  }
LABEL_22:
  if ( criteria->usePrivate != 0
    && (criteria->privateKey.checksum != server->privateKey.checksum
     || criteria->privateKey.length != server->privateKey.length) )
  {
    return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00401850
// Name: public: virtual bool CMasterThread::Init(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMasterThread::Init(CMasterThread *this, unsigned int socketReceive)
{
  CMasterThread_vtbl *v2; // edx

  v2 = this->__vftable;
  this->m_ListenSocket = socketReceive;
  return ((bool (__stdcall *)(_DWORD))v2->Start_2)(a1: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00401870
// Name: private: virtual bool CMasterThread::Start(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMasterThread::Start(CMasterThread *this, unsigned int nBytesStack)
{
  this->Shutdown(this);
  this->m_bThreadShouldExit = false;
  if ( !CThread::Start(this, a2: nBytesStack, a3: PRIORITY_DEFAULT) )
    return 0;
  CThread::SetPriority(this, a2: 2);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004018B0
// Name: private: virtual bool CReportingThread::Start(unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CReportingThread::Start(CReportingThread *this, unsigned int nBytesStack)
{
  this->Shutdown(this);
  this->m_bThreadShouldExit = false;
  return CThread::Start(this, a2: nBytesStack, a3: PRIORITY_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x004018E0
// Name: protected: virtual void CFmtStrN<256>::InitQuietTruncation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFmtStrN<256>::InitQuietTruncation(CFmtStrN<256> *this)
{
  this->m_bQuietTruncation = true;
}

//------------------------------------------------------------------------------
// Address: 0x004018F0
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
// Address: 0x00401980
// Name: public: static void QueuedPacket_t::operator delete(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl QueuedPacket_t::operator delete(void *p)
{
  DWORD CurrentThreadId; // ecx

  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != QueuedPacket_t::s_Allocator.m_mutex.m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)&QueuedPacket_t::s_Allocator.m_mutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: &QueuedPacket_t::s_Allocator.m_mutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++QueuedPacket_t::s_Allocator.m_mutex.m_depth;
  }
  CUtlMemoryPool::Free(this: &QueuedPacket_t::s_Allocator, memBlock: p);
  if ( --QueuedPacket_t::s_Allocator.m_mutex.m_depth == 0 )
    _InterlockedExchange((volatile __int32 *)&QueuedPacket_t::s_Allocator.m_mutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x004019F0
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
// Address: 0x00401AB0
// Name: private: void CMasterDlg::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterDlg::Shutdown(CMasterDlg *this)
{
  CReportingThread *m_ReportingThreads; // edi
  int i; // ebx

  if ( this->m_ServiceMessagesTimer != 0 )
    KillTimer(hWnd: this->m_hWnd, uIDEvent: 0x29Au);
  KillTimer(hWnd: this->m_hWnd, uIDEvent: 0x309u);
  CMasterDlg::FreeServers(this);
  this->m_MasterThread.Shutdown(this: &this->m_MasterThread);
  m_ReportingThreads = this->m_ReportingThreads;
  for ( i = 15; i != 0; --i )
  {
    m_ReportingThreads->Shutdown(this: m_ReportingThreads);
    ++m_ReportingThreads;
  }
  if ( this->m_net_socket != 0 )
    closesocket(s: this->m_net_socket);
  if ( this->m_pLogfile != nullptr )
  {
    fclose(stream: this->m_pLogfile);
    this->m_pLogfile = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401B50
// Name: private: void CMasterDlg::ComputeModStatistics(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterDlg::ComputeModStatistics(CMasterDlg *this)
{
  CMasterDlg *v1; // esi
  modsv_t *v2; // eax
  modsv_t *next; // edi
  sv_t *j; // edi
  char *value; // ebx
  char *v6; // esi
  char *v7; // eax
  char v8; // cl
  int i; // [esp+Ch] [ebp-Ch]
  sv_t **m_pGameServers; // [esp+10h] [ebp-8h]

  v1 = this;
  v2 = this->m_pMods[0];
  if ( v2 != nullptr )
  {
    do
    {
      next = v2->next;
      free(pMem: v2);
      v2 = next;
    }
    while ( next != nullptr );
  }
  v1->m_pMods[0] = nullptr;
  m_pGameServers = v1->m_pGameServers;
  for ( i = 2019; i != 0; --i )
  {
    for ( j = *m_pGameServers; j != nullptr; v1 = this )
    {
      value = j->gamedir.value;
      if ( j != (sv_t *)-2116 && *value != 0 && (v6 = (char *)v1->m_pMods[0]) != nullptr )
      {
        while ( _V_stricmp(s1: j->gamedir.value, s2: v6 + 4) != 0 )
        {
          v6 = *(char **)v6;
          if ( v6 == nullptr )
            goto LABEL_12;
        }
      }
      else
      {
LABEL_12:
        v6 = (char *)operator new(nSize: 0x64u);
        memset(dst: (unsigned __int8 *)v6, value: 0, count: 0x64u);
        v7 = j->gamedir.value;
        do
        {
          v8 = *v7;
          v7[v6 - value + 4] = *v7;
          ++v7;
        }
        while ( v8 != 0 );
        *(_DWORD *)v6 = this->m_pMods[0];
        this->m_pMods[0] = (modsv_t *)v6;
      }
      if ( j->islan != 0 )
      {
        ++*((_DWORD *)v6 + 22);
        *((_DWORD *)v6 + 21) += j->players;
        *((_DWORD *)v6 + 23) += j->bots;
        if ( j->bots != 0 )
          ++*((_DWORD *)v6 + 24);
      }
      else
      {
        ++*((_DWORD *)v6 + 18);
        *((_DWORD *)v6 + 17) += j->players;
        *((_DWORD *)v6 + 19) += j->bots;
        if ( j->bots != 0 )
          ++*((_DWORD *)v6 + 20);
      }
      j = j->next;
    }
    ++m_pGameServers;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401C90
// Name: private: int CMasterDlg::CheckChallenge(int,struct sockaddr_in __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMasterDlg::CheckChallenge(CMasterDlg *this, int challenge, sockaddr_in *adr)
{
  int s_b4; // edx
  int v7; // eax
  int v8; // edi
  __int64 v13; // [esp+4h] [ebp-10h]
  __int64 v14; // [esp+4h] [ebp-10h]

  _ESI = adr;
  __asm { movq    xmm0, qword ptr [esi] }
  s_b4 = adr->sin_addr.S_un.S_un_b.s_b4;
  __asm
  {
    movq    [ebp+var_10], xmm0
    movq    xmm0, qword ptr [esi+8]
  }
  v7 = 0;
  v8 = HIDWORD(v13);
  __asm { movq    [ebp+var_8], xmm0 }
  for ( _ESI = this->m_Challenges[s_b4]; ; ++_ESI )
  {
    __asm
    {
      movq    xmm0, qword ptr [esi]
      movq    [ebp+var_10], xmm0
      movq    xmm0, qword ptr [esi+8]
      movq    [ebp+var_8], xmm0
    }
    if ( v8 == HIDWORD(v14) )
      break;
    if ( ++v7 >= 32 )
      return 2;
  }
  return challenge != this->m_Challenges[s_b4][v7].challenge;
}

//------------------------------------------------------------------------------
// Address: 0x00401D20
// Name: private: void CMasterDlg::Packet_Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterDlg::Packet_Shutdown(CMasterDlg *this)
{
  unsigned int v1; // esi
  sv_t **p_next; // edx
  int v6; // ecx
  unsigned int v7; // esi
  __int64 v10; // [esp+Ch] [ebp-10h]
  __int64 v11; // [esp+Ch] [ebp-10h]

  v1 = (SHIBYTE(this->m_packet_from.sin_port)
      ^ ((SLOBYTE(this->m_packet_from.sin_port)
        ^ (((char)this->m_packet_from.sin_addr.S_un.S_un_b.s_b4
          ^ (((char)this->m_packet_from.sin_addr.S_un.S_un_b.s_b3
            ^ (((char)this->m_packet_from.sin_addr.S_un.S_un_b.s_b2
              ^ (((char)this->m_packet_from.sin_addr.S_un.S_un_b.s_b1
                ^ (unsigned int)(2 * (char)this->m_packet_from.sin_addr.S_un.S_un_b.s_b1))
               + 2 * (char)this->m_packet_from.sin_addr.S_un.S_un_b.s_b2))
             + 2 * (char)this->m_packet_from.sin_addr.S_un.S_un_b.s_b3))
           + 2 * (char)this->m_packet_from.sin_addr.S_un.S_un_b.s_b4))
         + 2 * SLOBYTE(this->m_packet_from.sin_port)))
       + 2 * SHIBYTE(this->m_packet_from.sin_port)))
     % 0x7E3;
  _EAX = this->m_pGameServers[v1];
  p_next = &this->m_pGameServers[v1];
  if ( _EAX != nullptr )
  {
    __asm
    {
      movq    xmm0, qword ptr [this+140h]
      movq    [ebp+var_10], xmm0
      movq    xmm0, qword ptr [this+148h]
    }
    v6 = HIDWORD(v10);
    v7 = v10;
    __asm { movq    [ebp+var_8], xmm0 }
    while ( 1 )
    {
      __asm
      {
        movq    xmm0, qword ptr [eax+4]
        movq    [ebp+var_10], xmm0
        movq    xmm0, qword ptr [eax+0Ch]
        movq    [ebp+var_8], xmm0
      }
      if ( v6 == HIDWORD(v11) && HIWORD(v7) == WORD1(v11) )
        break;
      p_next = &_EAX->next;
      _EAX = _EAX->next;
      if ( _EAX == nullptr )
        return;
    }
    *p_next = _EAX->next;
    free(pMem: _EAX);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401E10
// Name: private: void CMasterDlg::Sys_Error(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void __noreturn CMasterDlg::Sys_Error(CMasterDlg *this, char *pFormat, ...)
{
  char string[4096]; // [esp+4h] [ebp-1000h] BYREF
  va_list ap; // [esp+1014h] [ebp+10h] BYREF

  va_start(ap, pFormat);
  if ( this->m_net_socket != 0 )
    closesocket(s: this->m_net_socket);
  if ( this->m_pLogfile != nullptr )
  {
    fclose(stream: this->m_pLogfile);
    this->m_pLogfile = nullptr;
  }
  vsprintf_s(string, sizeInBytes: 0x1000u, format: pFormat, ap);
  CMasterDlg::Sys_Printf(this, pMsg: "\nSys_Error:\n");
  CMasterDlg::Sys_Printf(this, pMsg: string);
  CMasterDlg::Sys_Printf(this, pMsg: "\n");
  CMasterDlg::Sys_MessageBox(this, pFormat: string);
  exit(code: 1);
}

//------------------------------------------------------------------------------
// Address: 0x00401EB0
// Name: private: void CMasterDlg::Sys_Warning(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CMasterDlg::Sys_Warning(CMasterDlg *this, char *pFormat, ...)
{
  char string[4096]; // [esp+4h] [ebp-1000h] BYREF
  va_list ap; // [esp+1014h] [ebp+10h] BYREF

  va_start(ap, pFormat);
  vsprintf_s(string, sizeInBytes: 0x1000u, format: pFormat, ap);
  CMasterDlg::Sys_Printf(this, pMsg: "WARNING: ");
  CMasterDlg::Sys_Printf(this, pMsg: string);
  CMasterDlg::Sys_Printf(this, pMsg: "\n");
}

//------------------------------------------------------------------------------
// Address: 0x00401F10
// Name: private: void CMasterDlg::Sys_VPrintf(char __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CMasterDlg::Sys_VPrintf(CMasterDlg *this, char *pMsg, ...)
{
  _iobuf *m_pLogfile; // eax
  char string[4096]; // [esp+4h] [ebp-2060h] BYREF
  char pDest[4096]; // [esp+1004h] [ebp-1060h] BYREF
  char v5[64]; // [esp+2004h] [ebp-60h] BYREF
  char buffer[32]; // [esp+2044h] [ebp-20h] BYREF
  va_list ap; // [esp+2074h] [ebp+10h] BYREF

  va_start(ap, pMsg);
  vsprintf_s(string, sizeInBytes: 0x1000u, format: pMsg, ap);
  _strtime(buffer);
  _strdate(buffer: v5);
  V_snprintf(pDest, maxLen: 4096, pFormat: "%s %s: %s", v5, buffer, string);
  m_pLogfile = this->m_pLogfile;
  if ( m_pLogfile != nullptr )
    fprintf(str: m_pLogfile, format: "%s", pDest);
  CMasterDlg::Sys_Printf(this, pMsg: "%s", pDest);
}

//------------------------------------------------------------------------------
// Address: 0x00401FB0
// Name: private: void CMasterDlg::Sys_SendPacket(struct sockaddr_in __near *,unsigned char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterDlg::Sys_SendPacket(CMasterDlg *this, sockaddr_in *to, unsigned __int8 *data, unsigned int len)
{
  bool v5; // zf
  DWORD v6; // eax
  int *v7; // edi
  int *v8; // edi
  int *v9; // ebx
  const char *v10; // eax
  _WSABUF buffers[2]; // [esp+4h] [ebp-14h] BYREF
  unsigned int nSend; // [esp+14h] [ebp-4h] BYREF

  v5 = !this->m_bPureUDP;
  nSend = 0;
  if ( v5 )
  {
    buffers[0].buf = (char *)&len;
    v6 = 2;
    buffers[0].len = 2;
    buffers[1].len = len;
    buffers[1].buf = (char *)data;
  }
  else
  {
    buffers[0].len = len;
    buffers[0].buf = (char *)data;
    v6 = 1;
  }
  if ( WSASendTo(
         s: this->m_net_socket,
         lpBuffers: buffers,
         dwBufferCount: v6,
         lpNumberOfBytesSent: &nSend,
         dwFlags: 0,
         lpTo: (const struct sockaddr *)to,
         iTolen: 16,
         lpOverlapped: nullptr,
         lpCompletionRoutine: nullptr) == -1 )
  {
    v7 = _errno();
    *v7 = WSAGetLastError();
    v8 = _errno();
    v9 = _errno();
    v10 = strerror(errnum: *v8);
    CMasterDlg::Sys_VPrintf(this, pMsg: "ERROR: Sys_SendPacket: ( %i ) %s\r\n", *v9, v10);
  }
  else
  {
    this->m_fBytesSent = (double)nSend + this->m_fBytesSent;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402090
// Name: private: void CMasterDlg::ListServers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterDlg::ListServers(CMasterDlg *this)
{
  int v2; // ebx
  sv_t **m_pGameServers; // eax
  u_short v7; // ax
  bool v8; // zf
  sv_t **v9; // eax
  int v10; // ebx
  u_short v14; // ax
  modsv_t *v15; // esi
  int i; // ebx
  search_criteria_t criteria; // [esp+Ch] [ebp-144h] BYREF
  char szAddress[64]; // [esp+F8h] [ebp-58h] BYREF
  __int64 v19; // [esp+138h] [ebp-18h]
  int v21; // [esp+148h] [ebp-8h]
  int v22; // [esp+14Ch] [ebp-4h]

  v2 = 1;
  criteria.usefull = 0;
  criteria.usemap = 0;
  criteria.usegame = 0;
  criteria.usePrivate = 0;
  criteria.useempty = 1;
  CMasterDlg::Sys_Printf(this, pMsg: "\nActive Servers:\n");
  CMasterDlg::Sys_Printf(this, pMsg: "--------------------\n");
  m_pGameServers = this->m_pGameServers;
  v22 = (int)this->m_pGameServers;
  v21 = 2019;
  do
  {
    for ( _ESI = *m_pGameServers; _ESI != nullptr; ++v2 )
    {
      if ( !CMasterDlg::ServerMatchesCriteria(this, server: _ESI, &criteria) )
      {
        __asm
        {
          movq    xmm0, qword ptr [esi+4]
          movq    [ebp+var_18], xmm0
        }
        __asm { movq    xmm0, qword ptr [esi+0Ch] }
        __asm { movq    [ebp+var_10], xmm0 }
        v7 = ntohs(netshort: WORD1(v19));
        V_snprintf(
          pDest: szAddress,
          maxLen: 64,
          pFormat: "%i.%i.%i.%i:%i",
          BYTE4(v19),
          BYTE5(v19),
          BYTE6(v19),
          HIBYTE(v19),
          v7);
        CMasterDlg::Sys_Printf(
          this,
          pMsg: "%i: %s Game:%s Map:%s\n",
          v2,
          szAddress,
          _ESI->gamedir.value,
          _ESI->map.value);
        CMasterDlg::Sys_Printf(this, pMsg: "  Users:%6i Bots:%6i\n", _ESI->players - _ESI->bots, _ESI->bots);
      }
      _ESI = _ESI->next;
    }
    m_pGameServers = (sv_t **)(v22 + 4);
    v8 = v21-- == 1;
    v22 += 4;
  }
  while ( !v8 );
  CMasterDlg::Sys_Printf(this, pMsg: "\nEmpty Servers:\n");
  CMasterDlg::Sys_Printf(this, pMsg: "--------------------\n");
  v9 = this->m_pGameServers;
  v10 = 1;
  v21 = (int)this->m_pGameServers;
  v22 = 2019;
  do
  {
    for ( _ESI = *v9; _ESI != nullptr; ++v10 )
    {
      if ( CMasterDlg::ServerMatchesCriteria(this, server: _ESI, &criteria) )
      {
        __asm
        {
          movq    xmm0, qword ptr [esi+4]
          movq    [ebp+var_18], xmm0
        }
        __asm { movq    xmm0, qword ptr [esi+0Ch] }
        __asm { movq    [ebp+var_10], xmm0 }
        v14 = ntohs(netshort: WORD1(v19));
        V_snprintf(
          pDest: szAddress,
          maxLen: 64,
          pFormat: "%i.%i.%i.%i:%i",
          BYTE4(v19),
          BYTE5(v19),
          BYTE6(v19),
          HIBYTE(v19),
          v14);
        CMasterDlg::Sys_Printf(
          this,
          pMsg: "%i: %s Game:%s Map:%s\n",
          v10,
          szAddress,
          _ESI->gamedir.value,
          _ESI->map.value);
        CMasterDlg::Sys_Printf(this, pMsg: "  Users:%6i Bots:%6i\n", _ESI->players - _ESI->bots, _ESI->bots);
      }
      _ESI = _ESI->next;
    }
    v9 = (sv_t **)(v21 + 4);
    v8 = v22-- == 1;
    v21 += 4;
  }
  while ( !v8 );
  CMasterDlg::Sys_Printf(this, pMsg: "\nTotals By Game:\n");
  CMasterDlg::Sys_Printf(this, pMsg: "--------------------\n");
  v15 = this->m_pMods[0];
  for ( i = 1; v15 != nullptr; ++i )
  {
    CMasterDlg::Sys_Printf(this, pMsg: "%i: %s\n", i, v15->gamedir);
    CMasterDlg::Sys_Printf(
      this,
      pMsg: " Internet: Servers:%6i Users:%6i Bots:%6i BotServers:%6i\n",
      v15->ip_servers,
      v15->ip_players - v15->ip_bots,
      v15->ip_bots,
      v15->ip_bots_servers);
    CMasterDlg::Sys_Printf(
      this,
      pMsg: " LAN:      Servers:%6i Users:%6i Bots:%6i BotServers:%6i\n",
      v15->lan_servers,
      v15->lan_players - v15->lan_bots,
      v15->lan_bots,
      v15->lan_bots_servers);
    v15 = v15->next;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402340
// Name: private: struct sv_t __near * CMasterDlg::FindServerByAddress(struct sockaddr_in __near *)
// Source: json
//------------------------------------------------------------------------------
sv_t *__thiscall CMasterDlg::FindServerByAddress(CMasterDlg *this, sockaddr_in *address)
{
  sv_t *result; // eax
  int v6; // ecx
  unsigned int v7; // edx
  __int64 v10; // [esp+4h] [ebp-14h]
  __int64 v11; // [esp+4h] [ebp-14h]

  _EDI = address;
  if ( address == nullptr )
    return nullptr;
  result = this->m_pGameServers[(SHIBYTE(address->sin_port)
                               ^ ((SLOBYTE(address->sin_port)
                                 ^ (((char)address->sin_addr.S_un.S_un_b.s_b4
                                   ^ (((char)address->sin_addr.S_un.S_un_b.s_b3
                                     ^ (((char)address->sin_addr.S_un.S_un_b.s_b2
                                       ^ (((char)address->sin_addr.S_un.S_un_b.s_b1
                                         ^ (unsigned int)(2 * (char)address->sin_addr.S_un.S_un_b.s_b1))
                                        + 2 * (char)address->sin_addr.S_un.S_un_b.s_b2))
                                      + 2 * (char)address->sin_addr.S_un.S_un_b.s_b3))
                                    + 2 * (char)address->sin_addr.S_un.S_un_b.s_b4))
                                  + 2 * SLOBYTE(address->sin_port)))
                                + 2 * SHIBYTE(address->sin_port)))
                              % 0x7E3];
  if ( result == nullptr )
    return nullptr;
  __asm
  {
    movq    xmm0, qword ptr [edi]
    movq    [ebp+var_14], xmm0
    movq    xmm0, qword ptr [edi+8]
  }
  v6 = HIDWORD(v10);
  v7 = v10;
  __asm { movq    [ebp+var_C], xmm0 }
  while ( 1 )
  {
    __asm
    {
      movq    xmm0, qword ptr [eax+4]
      movq    [ebp+var_14], xmm0
      movq    xmm0, qword ptr [eax+0Ch]
      movq    [ebp+var_C], xmm0
    }
    if ( v6 == HIDWORD(v11) && HIWORD(v7) == WORD1(v11) )
      break;
    result = result->next;
    if ( result == nullptr )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00402410
// Name: public: CFmtStrN<256>::CFmtStrN<256>(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
CFmtStrN<256> *CFmtStrN<256>::CFmtStrN<256>(CFmtStrN<256> *this, const char *pszFormat, ...)
{
  CFmtStrN<256> *v2; // esi
  char *m_szBuf; // edi
  bool v4; // zf
  char *v6; // [esp-14h] [ebp-1Ch]
  const char *v7; // [esp-Ch] [ebp-14h]
  va_list params; // [esp+18h] [ebp+10h] BYREF

  va_start(params, pszFormat);
  v2 = this;
  v7 = pszFormat;
  m_szBuf = this->m_szBuf;
  v6 = this->m_szBuf;
  this->__vftable = (CFmtStrN<256>_vtbl *)&CFmtStrN<256>::`vftable';
  v2->m_bQuietTruncation = true;
  HIBYTE(this) = 0;
  V_vsnprintfRet(pDest: v6, maxLen: 255, pFormat: v7, params, pbTruncated: (bool *)&this + 3);
  v4 = HIBYTE(this) == 0;
  v2->m_szBuf[255] = 0;
  if ( !v4 && !v2->m_bQuietTruncation && `CFmtStrN<256>::CFmtStrN<256>'::`4'::scAsserted < 5 )
    ++`CFmtStrN<256>::CFmtStrN<256>'::`4'::scAsserted;
  v2->m_nLength = _V_strlen(str: m_szBuf);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x004024F0
// Name: public: void CByteswap::SwapBufferToTargetEndian<unsigned short>(unsigned short __near *,unsigned short __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<unsigned short>(
        CByteswap *this,
        unsigned __int8 *outputBuffer,
        __int16 *inputBuffer,
        int count)
{
  int v4; // ebx
  unsigned __int8 *v5; // esi
  int v6; // edi
  unsigned __int8 v7; // dl
  unsigned __int8 v8; // cl

  v4 = count;
  if ( count > 0 && outputBuffer != nullptr )
  {
    v5 = (unsigned __int8 *)inputBuffer;
    if ( inputBuffer == nullptr )
      v5 = outputBuffer;
    if ( (*(_BYTE *)this & 1) != 0 )
    {
      v6 = outputBuffer - v5;
      do
      {
        v7 = v5[1];
        count = *(unsigned __int16 *)&v5[v6];
        v8 = *v5;
        LOBYTE(count) = v7;
        BYTE1(count) = v8;
        _V_memcpy(dest: &v5[v6], src: &count, count: 2);
        v5 += 2;
        --v4;
      }
      while ( v4 != 0 );
    }
    else if ( v5 != nullptr && outputBuffer != v5 )
    {
      memcpy(dst: outputBuffer, src: v5, count: 2 * count);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402570
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<struct sockaddr_in,struct xlspTitleServer_t,int>::Node_t,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int> *m_pMemory; // edx
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
    v7 = 100 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int> *)_g_pMemAlloc->Realloc_2(
                                                                                                     this: _g_pMemAlloc,
                                                                                                     a2: m_pMemory,
                                                                                                     a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int> *)_g_pMemAlloc->Alloc_2(
                                                                                                     this: _g_pMemAlloc,
                                                                                                     a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402600
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct sv_t __near *,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>::Grow(
        CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<sv_t *,int> *m_pMemory; // edx
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
    v7 = 20 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<sv_t *,int> *)_g_pMemAlloc->Realloc_2(
                                                         this: _g_pMemAlloc,
                                                         a2: m_pMemory,
                                                         a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<sv_t *,int> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004026A0
// Name: public: int CUtlVector<struct QueuedPacket_t __near *,class CUtlMemory<struct QueuedPacket_t __near *,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<QueuedPacket_t *,CUtlMemory<QueuedPacket_t *,int>>::InsertMultipleBefore(
        CUtlVector<QueuedPacket_t *,CUtlMemory<QueuedPacket_t *,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  QueuedPacket_t **m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>::Grow(
      (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem] + num, src: &m_pMemory[elem], count: 4 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00402710
// Name: bool KeyValuesDumpAsDevMsg(class KeyValues __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl KeyValuesDumpAsDevMsg(KeyValues *pKeyValues, int nIndentLevel, int nDeveloperLevel)
{
  CKeyValuesDumpContextAsDevMsg ctx; // [esp+0h] [ebp-8h] BYREF

  ctx.__vftable = (CKeyValuesDumpContextAsDevMsg_vtbl *)&CKeyValuesDumpContextAsDevMsg::`vftable';
  ctx.m_nDeveloperLevel = nDeveloperLevel;
  return KeyValues::Dump(this: pKeyValues, pDump: &ctx, nIndentLevel);
}

//------------------------------------------------------------------------------
// Address: 0x00402740
// Name: class KeyValues __near * GetGlobalInfoChunk_Part(int)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__cdecl GetGlobalInfoChunk_Part(int idxPart)
{
  KeyValues *v1; // eax
  KeyValues *Copy; // eax

  if ( (_S1 & 1) == 0 )
  {
    _S1 |= 1u;
    v1 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v1 != nullptr )
      g_pKV = KeyValues::KeyValues(this: v1, setName: g_szXlspDataRoot);
    else
      g_pKV = nullptr;
  }
  KeyValues::Clear(this: g_pKV);
  if ( idxPart > 0 && idxPart < InfoChunks::g_arrChunks.m_Size )
  {
    Copy = KeyValues::MakeCopy(this: InfoChunks::g_arrChunks.m_Memory.m_pMemory[idxPart]);
    KeyValues::AddSubKey(this: g_pKV, pSubkey: Copy);
  }
  return g_pKV;
}

//------------------------------------------------------------------------------
// Address: 0x004027C0
// Name: class KeyValues __near * GetGlobalInfoPatch_Part(int)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__cdecl GetGlobalInfoPatch_Part(int idxPart)
{
  KeyValues *v1; // eax
  KeyValues *Copy; // eax

  if ( (_S2 & 1) == 0 )
  {
    _S2 |= 1u;
    v1 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v1 != nullptr )
      g_pKV_0 = KeyValues::KeyValues(this: v1, setName: g_szXlspDataRoot);
    else
      g_pKV_0 = nullptr;
  }
  KeyValues::Clear(this: g_pKV_0);
  if ( idxPart > 0 && idxPart < InfoChunks::g_arrPatches.m_Size )
  {
    Copy = KeyValues::MakeCopy(this: InfoChunks::g_arrPatches.m_Memory.m_pMemory[idxPart]);
    KeyValues::AddSubKey(this: g_pKV_0, pSubkey: Copy);
  }
  return g_pKV_0;
}

//------------------------------------------------------------------------------
// Address: 0x00402840
// Name: class KeyValues __near * GetMasterData_Init(void)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__cdecl GetMasterData_Init()
{
  KeyValues *v0; // eax
  KeyValues *v1; // edi
  KeyValues *v2; // ecx
  KeyValues *i; // esi
  KeyValues *Copy; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  KeyValues *v7; // esi
  KeyValues *v8; // eax
  KeyValues *v9; // eax
  KeyValues *v10; // eax
  KeyValues *v11; // eax

  v0 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v0 != nullptr )
    v1 = KeyValues::KeyValues(this: v0, setName: g_szXlspDataRoot);
  else
    v1 = nullptr;
  KeyValues::SetString(this: v1, keyName: "info", value: g_szCenterInfo);
  if ( InfoChunks::g_arrChunks.m_Size != 0 )
    v2 = *InfoChunks::g_arrChunks.m_Memory.m_pMemory;
  else
    v2 = nullptr;
  for ( i = KeyValues::GetFirstValue(this: v2); i != nullptr; i = KeyValues::GetNextValue(this: i) )
  {
    Copy = KeyValues::MakeCopy(this: i);
    KeyValues::AddSubKey(this: v1, pSubkey: Copy);
  }
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
  {
    v6 = KeyValues::KeyValues(this: v5, setName: "chunks");
    v7 = v6;
    if ( v6 != nullptr )
    {
      KeyValues::AddSubKey(this: v1, pSubkey: v6);
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
        v9 = KeyValues::KeyValues(
               this: v8,
               setName: "data_chunk",
               firstKey: "chunks",
               firstValue: InfoChunks::g_arrChunks.m_Size - 1);
      else
        v9 = nullptr;
      KeyValues::AddSubKey(this: v7, pSubkey: v9);
      v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v10 != nullptr )
      {
        v11 = KeyValues::KeyValues(
                this: v10,
                setName: "data_patch",
                firstKey: "chunks",
                firstValue: InfoChunks::g_arrPatches.m_Size - 1);
        KeyValues::AddSubKey(this: v7, pSubkey: v11);
        return v1;
      }
      KeyValues::AddSubKey(this: v7, pSubkey: nullptr);
    }
  }
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x00402960
// Name: class KeyValues __near * GetMasterData(void)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__cdecl GetMasterData()
{
  KeyValues *result; // eax

  result = InfoChunks::g_pMasterData;
  if ( InfoChunks::g_pMasterData == nullptr )
  {
    result = GetMasterData_Init();
    InfoChunks::g_pMasterData = result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00402980
// Name: private: void CMasterDlg::RejectConnection(struct sockaddr_in __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterDlg::RejectConnection(CMasterDlg *this, sockaddr_in *adr, const char *pszMessage)
{
  unsigned __int8 *m_Reply; // esi

  m_Reply = (unsigned __int8 *)this->m_Reply;
  V_snprintf(pDest: this->m_Reply, maxLen: 1400, pFormat: "%c%c%c%c%c\n%s\n", 255, 255, 255, 255, 108, pszMessage);
  CMasterDlg::Sys_SendPacket(this, to: adr, data: m_Reply, len: strlen((const char *)m_Reply) + 1);
}

//------------------------------------------------------------------------------
// Address: 0x004029E0
// Name: private: void CMasterDlg::Packet_Ping(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterDlg::Packet_Ping(CMasterDlg *this)
{
  unsigned __int8 *m_Reply; // edi

  m_Reply = (unsigned __int8 *)this->m_Reply;
  V_snprintf(pDest: this->m_Reply, maxLen: 1400, pFormat: "%c%c%c%c%c\r\n", 255, 255, 255, 255, 106);
  CMasterDlg::Sys_SendPacket(this, to: &this->m_packet_from, data: m_Reply, len: strlen((const char *)m_Reply) + 1);
}

//------------------------------------------------------------------------------
// Address: 0x00402A40
// Name: private: void CMasterDlg::OpenNewLogFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterDlg::OpenNewLogFile(CMasterDlg *this)
{
  tm *v2; // esi
  int v3; // edi
  _iobuf *v4; // eax
  _iobuf *v5; // eax
  char name[260]; // [esp+4h] [ebp-10Ch] BYREF
  __int64 t; // [esp+108h] [ebp-8h] BYREF

  if ( this->m_bGenerateLogs )
  {
    t = _time64(timeptr: nullptr);
    v2 = _localtime64(ptime: &t);
    this->m_nCurrentDay = v2->tm_mday;
    v3 = 0;
    while ( 1 )
    {
      V_snprintf(
        pDest: name,
        maxLen: 260,
        pFormat: "MasterServer_%i_%i_%i_%i.log",
        v2->tm_mon + 1,
        v2->tm_mday,
        v2->tm_year,
        v3);
      v4 = fopen(file: name, mode: "rt");
      this->m_pLogfile = v4;
      if ( v4 == nullptr )
        break;
      if ( ++v3 >= 999 )
        CMasterDlg::Sys_Error(this, pFormat: "Logfile creation failed");
    }
    v5 = fopen(file: name, mode: "wt");
    this->m_pLogfile = v5;
    if ( v5 == nullptr )
      CMasterDlg::Sys_Error(this, pFormat: "Logfile creation failed");
    CMasterDlg::Sys_VPrintf(this, pMsg: "Logfile '%s' created.\n", name);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402B20
// Name: private: void CMasterDlg::NET_GetLocalAddress(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CMasterDlg::NET_GetLocalAddress(CMasterDlg *this@<ecx>, __int128 a2@<xmm0>)
{
  const char *v3; // eax
  struct hostent *v4; // eax
  char **h_addr_list; // eax
  int *v6; // eax
  char *v7; // eax
  u_short v10; // ax
  SOCKET m_net_socket; // [esp-Ch] [ebp-178h]
  char buff[256]; // [esp+8h] [ebp-164h] BYREF
  char szAddress[64]; // [esp+108h] [ebp-64h] BYREF
  sockaddr_in address; // [esp+148h] [ebp-24h] BYREF
  __int64 v15; // [esp+158h] [ebp-14h]
  int namelen; // [esp+168h] [ebp-4h] BYREF

  _ESI = this;
  if ( CUtlString::operator==(this: &this->m_strLocalIPAddress, src: defaultValue) )
  {
    gethostname(name: buff, namelen: 256);
    buff[255] = 0;
    v4 = gethostbyname(name: buff);
    if ( v4 == nullptr )
      CMasterDlg::Sys_Error(this: _ESI, pFormat: "gethostbyname failed");
    h_addr_list = v4->h_addr_list;
    if ( h_addr_list[1] != nullptr )
      CMasterDlg::Sys_Error(
        this: _ESI,
        pFormat: "multiple local ip addresses found. must specify one on the command line.");
    _ESI->m_net_local_adr.sin_addr.S_un.S_addr = *(_DWORD *)*h_addr_list;
  }
  else
  {
    v3 = CUtlString::operator char const *(this: &_ESI->m_strLocalIPAddress);
    if ( CMasterDlg::NET_StringToSockaddr(this: _ESI, _XMM0: a2, s: v3, sadr: (sockaddr *)&address) == 0 )
      CMasterDlg::Sys_Error(this: _ESI, pFormat: "cannot parse ip address on command line");
    _ESI->m_net_local_adr.sin_addr.S_un.S_addr = address.sin_addr.S_un.S_addr;
  }
  m_net_socket = _ESI->m_net_socket;
  namelen = 16;
  if ( getsockname(s: m_net_socket, name: (struct sockaddr *)&address, &namelen) == -1 )
  {
    v6 = _errno();
    v7 = strerror(errnum: *v6);
    CMasterDlg::Sys_Error(this: _ESI, pFormat: "NET_Init: getsockname:", v7);
  }
  _ESI->m_net_local_adr.sin_port = address.sin_port;
  __asm
  {
    movq    xmm0, qword ptr [esi+130h]
    movq    [ebp+var_14], xmm0
  }
  __asm { movq    xmm0, qword ptr [esi+138h] }
  __asm { movq    [ebp+var_C], xmm0 }
  v10 = ntohs(netshort: WORD1(v15));
  V_snprintf(
    pDest: szAddress,
    maxLen: 64,
    pFormat: "%i.%i.%i.%i:%i",
    BYTE4(v15),
    BYTE5(v15),
    BYTE6(v15),
    HIBYTE(v15),
    v10);
  CMasterDlg::Sys_VPrintf(this: _ESI, pMsg: "IP Address: %s\n", szAddress);
}

//------------------------------------------------------------------------------
// Address: 0x00402C80
// Name: private: bool CMasterDlg::Sys_ParseCommandLineArg(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMasterDlg::Sys_ParseCommandLineArg(
        CMasterDlg *this,
        const char *pKey,
        char *pValueBuff,
        int valueBuffSize)
{
  KeyValues *v4; // ecx
  KeyValues *Key; // eax
  KeyValues *v6; // eax
  const char *v8; // ebx
  int v9; // eax
  const char *CommandLineA; // eax
  const char *v12; // eax
  char *v13; // eax
  int i; // ecx
  const char *szValue; // [esp+Ch] [ebp+Ch]

  if ( InfoChunks::g_arrChunks.m_Size != 0 )
    v4 = *InfoChunks::g_arrChunks.m_Memory.m_pMemory;
  else
    v4 = nullptr;
  Key = KeyValues::FindKey(this: v4, keyName: "settings", bCreate: false);
  v6 = KeyValues::FindKey(this: Key, keyName: pKey, bCreate: false);
  if ( v6 == nullptr )
  {
    CommandLineA = GetCommandLineA();
    v12 = V_stristr(pStr: CommandLineA, pSearch: pKey);
    if ( v12 == nullptr )
      return 0;
    if ( pValueBuff != nullptr )
    {
      v13 = (char *)&v12[strlen(pKey)];
      if ( *v13 == 32 )
        ++v13;
      for ( i = 0; i < valueBuffSize; ++v13 )
      {
        pValueBuff[i] = *v13;
        if ( *v13 == 0 )
          break;
        if ( *v13 == 32 )
          break;
        ++i;
      }
      pValueBuff[i] = 0;
    }
  }
  else if ( pValueBuff != nullptr && valueBuffSize > 0 )
  {
    szValue = KeyValues::GetString(this: v6, keyName: nullptr, defaultValue: defaultValue);
    v8 = StringAfterPrefix(str: szValue, prefix: "#.../");
    if ( v8 != nullptr )
    {
      V_ExtractFilePath(path: g_szCenterChunkFile, dest: pValueBuff, destSize: valueBuffSize);
      v9 = _V_strlen(str: pValueBuff);
      V_strncpy(pDest: &pValueBuff[v9], pSrc: v8, maxLen: valueBuffSize - v9);
    }
    else
    {
      V_strncpy(pDest: pValueBuff, pSrc: szValue, maxLen: valueBuffSize);
    }
    return 1;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00402DB0
// Name: private: void CMasterDlg::ComputeStatistics(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterDlg::ComputeStatistics(CMasterDlg *this)
{
  sv_t **m_pGameServers; // edi
  sv_t *i; // eax
  int bots; // ecx
  __int64 timeptr; // [esp+Ch] [ebp-8h] BYREF

  CMasterDlg::ComputeModStatistics(this);
  this->m_nServerCount = 0;
  this->m_nUsers = 0;
  this->m_nLanServerCount = 0;
  this->m_nLanUsers = 0;
  this->m_nBotCount = 0;
  this->m_nLanBotCount = 0;
  this->m_nMaxSlots = 0;
  this->m_nEmpty = 0;
  m_pGameServers = this->m_pGameServers;
  HIDWORD(timeptr) = 2019;
  do
  {
    for ( i = *m_pGameServers; i != nullptr; i = i->next )
    {
      if ( i->islan != 0 )
      {
        ++this->m_nLanServerCount;
        this->m_nLanUsers += i->players - i->bots;
      }
      else
      {
        ++this->m_nServerCount;
        this->m_nUsers += i->players - i->bots;
      }
      bots = i->bots;
      if ( bots != 0 )
      {
        if ( i->islan != 0 )
          this->m_nLanBotCount += bots;
        else
          this->m_nBotCount += bots;
      }
      if ( i->players != 0 )
        this->m_nMaxSlots += i->maxPlayers;
      else
        ++this->m_nEmpty;
    }
    ++m_pGameServers;
    --HIDWORD(timeptr);
  }
  while ( HIDWORD(timeptr) != 0 );
  if ( this->m_bGenerateLogs )
  {
    _time64(&timeptr);
    if ( _localtime64(ptime: &timeptr)->tm_mday != this->m_nCurrentDay )
    {
      CMasterDlg::Sys_VPrintf(this, pMsg: "Changing to new day logfile\n");
      if ( this->m_pLogfile != nullptr )
      {
        fclose(stream: this->m_pLogfile);
        this->m_pLogfile = nullptr;
      }
      CMasterDlg::OpenNewLogFile(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402EF0
// Name: public: int CUtlRBTree<struct CUtlMap<struct sockaddr_in,struct xlspTitleServer_t,int>::Node_t,int,class CUtlMap<struct sockaddr_in,struct xlspTitleServer_t,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<struct sockaddr_in,struct xlspTitleServer_t,int>::Node_t,int>,int>>::Parent(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Parent(
        CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_5A7EE8 = -1;
    dword_5A7EEC = -1;
    dword_5A7EF0 = 1;
  }
  if ( i == -1 )
    return dword_5A7EEC;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x00402F40
// Name: public: int CUtlRBTree<struct CUtlMap<struct sockaddr_in,struct xlspTitleServer_t,int>::Node_t,int,class CUtlMap<struct sockaddr_in,struct xlspTitleServer_t,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<struct sockaddr_in,struct xlspTitleServer_t,int>::Node_t,int>,int>>::LeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::LeftChild(
        CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_5A7EE8 = -1;
    dword_5A7EEC = -1;
    dword_5A7EF0 = 1;
  }
  if ( i == -1 )
    return `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    return this->m_Elements.m_pMemory[i].m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x00402FA0
// Name: public: bool CUtlRBTree<struct CUtlMap<struct sockaddr_in,struct xlspTitleServer_t,int>::Node_t,int,class CUtlMap<struct sockaddr_in,struct xlspTitleServer_t,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<struct sockaddr_in,struct xlspTitleServer_t,int>::Node_t,int>,int>>::IsRightChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::IsRightChild(
        CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int> *v3; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_5A7EE8 = -1;
    dword_5A7EEC = -1;
    dword_5A7EF0 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_5A7EE8 = -1;
    dword_5A7EEC = -1;
    dword_5A7EF0 = 1;
  }
  if ( m_Parent == -1 )
    return dword_5A7EE8 == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Right == i;
}

//------------------------------------------------------------------------------
// Address: 0x00403050
// Name: protected: void CUtlRBTree<struct CUtlMap<struct sockaddr_in,struct xlspTitleServer_t,int>::Node_t,int,class CUtlMap<struct sockaddr_in,struct xlspTitleServer_t,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<struct sockaddr_in,struct xlspTitleServer_t,int>::Node_t,int>,int>>::FindInsertionPosition(struct CUtlMap<struct sockaddr_in,struct xlspTitleServer_t,int>::Node_t const __near &,int __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::FindInsertionPosition(
        CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int> > *this,
        const CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t *insert,
        int *parent,
        bool *leftchild)
{
  int m_Root; // edi

  m_Root = this->m_Root;
  *parent = -1;
  *leftchild = false;
  while ( m_Root != -1 )
  {
    *parent = m_Root;
    if ( this->m_LessFunc.m_LessFunc(a1: insert, a2: &this->m_Elements.m_pMemory[m_Root].m_Data) != 0 )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_5A7EE8 = -1;
        dword_5A7EEC = -1;
        dword_5A7EF0 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_5A7EE8 = -1;
        dword_5A7EEC = -1;
        dword_5A7EF0 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403140
// Name: public: int CUtlRBTree<struct sv_t __near *,int,bool (*)(struct sv_t __near * const __near &,struct sv_t __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct sv_t __near *,int>,int>>::Parent(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Parent(
        CUtlRBTree<sv_t *,int,bool (__cdecl*)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_5A7EFC = -1;
    dword_5A7F00 = -1;
    dword_5A7F04 = 1;
  }
  if ( i == -1 )
    return dword_5A7F00;
  else
    return this->m_Elements.m_pMemory[i].m_Parent;
}

//------------------------------------------------------------------------------
// Address: 0x004031A0
// Name: public: int CUtlRBTree<struct sv_t __near *,int,bool (*)(struct sv_t __near * const __near &,struct sv_t __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct sv_t __near *,int>,int>>::RightChild(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::RightChild(
        CUtlRBTree<sv_t *,int,bool (__cdecl*)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int> > *this,
        int i)
{
  if ( (`CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_5A7EFC = -1;
    dword_5A7F00 = -1;
    dword_5A7F04 = 1;
  }
  if ( i == -1 )
    return dword_5A7EFC;
  else
    return this->m_Elements.m_pMemory[i].m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x00403200
// Name: public: bool CUtlRBTree<struct sv_t __near *,int,bool (*)(struct sv_t __near * const __near &,struct sv_t __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct sv_t __near *,int>,int>>::IsRightChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::IsRightChild(
        CUtlRBTree<sv_t *,int,bool (__cdecl*)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<sv_t *,int> *v3; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_5A7EFC = -1;
    dword_5A7F00 = -1;
    dword_5A7F04 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<sv_t *,int> *)&`CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_5A7EFC = -1;
    dword_5A7F00 = -1;
    dword_5A7F04 = 1;
  }
  if ( m_Parent == -1 )
    return dword_5A7EFC == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Right == i;
}

//------------------------------------------------------------------------------
// Address: 0x004032B0
// Name: protected: void CUtlRBTree<struct sv_t __near *,int,bool (*)(struct sv_t __near * const __near &,struct sv_t __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct sv_t __near *,int>,int>>::FindInsertionPosition(struct sv_t __near * const __near &,int __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::FindInsertionPosition(
        CUtlRBTree<sv_t *,int,bool (__cdecl*)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int> > *this,
        sv_t *const *insert,
        int *parent,
        bool *leftchild)
{
  int m_Root; // esi

  m_Root = this->m_Root;
  *parent = -1;
  *leftchild = false;
  while ( m_Root != -1 )
  {
    *parent = m_Root;
    if ( this->m_LessFunc(a1: insert, a2: &this->m_Elements.m_pMemory[m_Root].m_Data) != 0 )
    {
      *leftchild = true;
      if ( (`CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_5A7EFC = -1;
        dword_5A7F00 = -1;
        dword_5A7F04 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      *leftchild = false;
      if ( (`CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_5A7EFC = -1;
        dword_5A7F00 = -1;
        dword_5A7F04 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Right;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004033A0
// Name: public: int CUtlRBTree<struct CUtlMap<struct sockaddr_in,struct xlspTitleServer_t,int>::Node_t,int,class CUtlMap<struct sockaddr_in,struct xlspTitleServer_t,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<struct sockaddr_in,struct xlspTitleServer_t,int>::Node_t,int>,int>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::NewNode(
        CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int> > *this)
{
  int m_FirstFree; // ecx
  int index; // ecx
  int m_nAllocationCount; // eax
  int v5; // ecx
  int v6; // edi
  int v7; // ecx
  int v8; // eax
  int v9; // ecx
  UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int> *m_pMemory; // edx
  UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int> *v12; // edx

  m_FirstFree = this->m_FirstFree;
  if ( m_FirstFree == -1 )
  {
    index = this->m_LastAlloc.index;
    if ( index < 0 || (m_nAllocationCount = this->m_Elements.m_nAllocationCount, index >= m_nAllocationCount) )
    {
      m_nAllocationCount = this->m_Elements.m_nAllocationCount;
      v5 = (m_nAllocationCount > 0) - 1;
    }
    else
    {
      v5 = index + 1;
      if ( v5 < 0 || v5 >= m_nAllocationCount )
        v5 = -1;
    }
    v6 = v5;
    if ( v5 < 0 || v5 >= m_nAllocationCount )
    {
      CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>::Grow(
        this: &this->m_Elements,
        num: 1);
      v7 = this->m_LastAlloc.index;
      if ( v7 < 0 || (v8 = this->m_Elements.m_nAllocationCount, v7 >= v8) )
      {
        v8 = this->m_Elements.m_nAllocationCount;
        v9 = (v8 > 0) - 1;
      }
      else
      {
        v9 = v7 + 1;
        if ( v9 < 0 || v9 >= v8 )
          v9 = -1;
      }
      v6 = v9;
      if ( v9 < 0 || v9 >= v8 )
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
// Address: 0x00403460
// Name: public: int CUtlRBTree<struct sv_t __near *,int,bool (*)(struct sv_t __near * const __near &,struct sv_t __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct sv_t __near *,int>,int>>::NewNode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::NewNode(
        CUtlRBTree<sv_t *,int,bool (__cdecl*)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int> > *this)
{
  int result; // eax
  int index; // ecx
  int m_nAllocationCount; // eax
  int v5; // ecx
  int v6; // edi
  int v7; // ecx
  int v8; // eax
  int v9; // ecx
  UtlRBTreeNode_t<sv_t *,int> *m_pMemory; // edx
  UtlRBTreeNode_t<sv_t *,int> *v11; // edx

  result = this->m_FirstFree;
  if ( result == -1 )
  {
    index = this->m_LastAlloc.index;
    if ( index < 0 || (m_nAllocationCount = this->m_Elements.m_nAllocationCount, index >= m_nAllocationCount) )
    {
      m_nAllocationCount = this->m_Elements.m_nAllocationCount;
      v5 = (m_nAllocationCount > 0) - 1;
    }
    else
    {
      v5 = index + 1;
      if ( v5 < 0 || v5 >= m_nAllocationCount )
        v5 = -1;
    }
    v6 = v5;
    if ( v5 < 0 || v5 >= m_nAllocationCount )
    {
      CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>::Grow(this: &this->m_Elements, num: 1);
      v7 = this->m_LastAlloc.index;
      if ( v7 < 0 || (v8 = this->m_Elements.m_nAllocationCount, v7 >= v8) )
      {
        v8 = this->m_Elements.m_nAllocationCount;
        v9 = (v8 > 0) - 1;
      }
      else
      {
        v9 = v7 + 1;
        if ( v9 < 0 || v9 >= v8 )
          v9 = -1;
      }
      v6 = v9;
      if ( v9 < 0 || v9 >= v8 )
        _Error(a1: "CUtlRBTree overflow!\n");
    }
    m_pMemory = this->m_Elements.m_pMemory;
    this->m_LastAlloc.index = v6;
    this->m_pElements = m_pMemory;
    return v6;
  }
  else
  {
    v11 = this->m_Elements.m_pMemory;
    this->m_FirstFree = v11[result].m_Right;
    this->m_pElements = v11;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00403520
// Name: public: bool CUtlRBTree<struct CUtlMap<struct sockaddr_in,struct xlspTitleServer_t,int>::Node_t,int,class CUtlMap<struct sockaddr_in,struct xlspTitleServer_t,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<struct sockaddr_in,struct xlspTitleServer_t,int>::Node_t,int>,int>>::IsLeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::IsLeftChild(
        CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int> *v3; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_5A7EE8 = -1;
    dword_5A7EEC = -1;
    dword_5A7EF0 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_5A7EE8 = -1;
    dword_5A7EEC = -1;
    dword_5A7EF0 = 1;
  }
  if ( m_Parent == -1 )
    return `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Left == i;
}

//------------------------------------------------------------------------------
// Address: 0x004035D0
// Name: protected: void CUtlRBTree<struct CUtlMap<struct sockaddr_in,struct xlspTitleServer_t,int>::Node_t,int,class CUtlMap<struct sockaddr_in,struct xlspTitleServer_t,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<struct sockaddr_in,struct xlspTitleServer_t,int>::Node_t,int>,int>>::RotateLeft(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::RotateLeft(
        CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v3; // ecx
  UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int> *v4; // eax
  int m_Right; // edi
  UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int> *v6; // eax
  int v7; // edx
  int v8; // ecx
  UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int> *v9; // eax
  UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int> *v10; // eax
  UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int> *v11; // eax
  int v12; // eax

  v3 = `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v3 = `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_5A7EE8 = -1;
    dword_5A7EEC = -1;
    dword_5A7EF0 = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Right = v4->m_Right;
  if ( (v3 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v3 | 1;
    `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_5A7EE8 = -1;
    dword_5A7EEC = -1;
    dword_5A7EF0 = 1;
  }
  if ( m_Right == -1 )
    v6 = (UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Right];
  v7 = elem;
  this->m_Elements.m_pMemory[elem].m_Right = v6->m_Left;
  v8 = `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v8 = `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_5A7EE8 = -1;
    dword_5A7EEC = -1;
    dword_5A7EF0 = 1;
  }
  if ( m_Right == -1 )
    v9 = (UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v9 = &this->m_Elements.m_pMemory[m_Right];
  if ( v9->m_Left != -1 )
  {
    if ( (v8 & 1) == 0 )
    {
      `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v8 | 1;
      `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_5A7EE8 = -1;
      dword_5A7EEC = -1;
      dword_5A7EF0 = 1;
    }
    if ( m_Right == -1 )
      v10 = (UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
    else
      v10 = &this->m_Elements.m_pMemory[m_Right];
    this->m_Elements.m_pMemory[v10->m_Left].m_Parent = elem;
    v8 = `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  }
  if ( m_Right != -1 )
  {
    if ( (v8 & 1) == 0 )
    {
      `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v8 | 1;
      `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_5A7EE8 = -1;
      dword_5A7EEC = -1;
      dword_5A7EF0 = 1;
    }
    if ( elem == -1 )
      v11 = (UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
    else
      v11 = &this->m_Elements.m_pMemory[v7];
    this->m_Elements.m_pMemory[m_Right].m_Parent = v11->m_Parent;
    v7 = elem;
  }
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Right;
  }
  else if ( CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::IsLeftChild(
              this,
              i: elem) )
  {
    v12 = CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Parent(
            this,
            i: elem);
    v7 = elem;
    this->m_Elements.m_pMemory[v12].m_Left = m_Right;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Right;
    v7 = elem;
  }
  this->m_Elements.m_pMemory[m_Right].m_Left = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[v7].m_Parent = m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x004037D0
// Name: protected: void CUtlRBTree<struct CUtlMap<struct sockaddr_in,struct xlspTitleServer_t,int>::Node_t,int,class CUtlMap<struct sockaddr_in,struct xlspTitleServer_t,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<struct sockaddr_in,struct xlspTitleServer_t,int>::Node_t,int>,int>>::RotateRight(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::RotateRight(
        CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v3; // ecx
  UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int> *v4; // eax
  int m_Left; // edi
  UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int> *v6; // eax
  int v7; // edx
  int v8; // ecx
  UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int> *v9; // eax
  UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int> *v10; // eax
  UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int> *v11; // eax
  int v12; // eax

  v3 = `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v3 = `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_5A7EE8 = -1;
    dword_5A7EEC = -1;
    dword_5A7EF0 = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Left = v4->m_Left;
  if ( (v3 & 1) == 0 )
  {
    `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v3 | 1;
    `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_5A7EE8 = -1;
    dword_5A7EEC = -1;
    dword_5A7EF0 = 1;
  }
  if ( m_Left == -1 )
    v6 = (UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Left];
  v7 = elem;
  this->m_Elements.m_pMemory[elem].m_Left = v6->m_Right;
  v8 = `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v8 = `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_5A7EE8 = -1;
    dword_5A7EEC = -1;
    dword_5A7EF0 = 1;
  }
  if ( m_Left == -1 )
    v9 = (UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v9 = &this->m_Elements.m_pMemory[m_Left];
  if ( v9->m_Right != -1 )
  {
    if ( (v8 & 1) == 0 )
    {
      `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v8 | 1;
      `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_5A7EE8 = -1;
      dword_5A7EEC = -1;
      dword_5A7EF0 = 1;
    }
    if ( m_Left == -1 )
      v10 = (UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
    else
      v10 = &this->m_Elements.m_pMemory[m_Left];
    this->m_Elements.m_pMemory[v10->m_Right].m_Parent = elem;
    v8 = `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  }
  if ( m_Left != -1 )
  {
    if ( (v8 & 1) == 0 )
    {
      `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v8 | 1;
      `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_5A7EE8 = -1;
      dword_5A7EEC = -1;
      dword_5A7EF0 = 1;
    }
    if ( elem == -1 )
      v11 = (UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
    else
      v11 = &this->m_Elements.m_pMemory[v7];
    this->m_Elements.m_pMemory[m_Left].m_Parent = v11->m_Parent;
    v7 = elem;
  }
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Left;
  }
  else if ( CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::IsRightChild(
              this,
              i: elem) )
  {
    v12 = CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Parent(
            this,
            i: elem);
    v7 = elem;
    this->m_Elements.m_pMemory[v12].m_Right = m_Left;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Left;
    v7 = elem;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[v7].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x004039D0
// Name: public: bool CUtlRBTree<struct sv_t __near *,int,bool (*)(struct sv_t __near * const __near &,struct sv_t __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct sv_t __near *,int>,int>>::IsLeftChild(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::IsLeftChild(
        CUtlRBTree<sv_t *,int,bool (__cdecl*)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<sv_t *,int> *v3; // eax
  int m_Parent; // eax

  v2 = `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_5A7EFC = -1;
    dword_5A7F00 = -1;
    dword_5A7F04 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<sv_t *,int> *)&`CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  m_Parent = v3->m_Parent;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_5A7EFC = -1;
    dword_5A7F00 = -1;
    dword_5A7F04 = 1;
  }
  if ( m_Parent == -1 )
    return `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::s_Sentinel == i;
  else
    return this->m_Elements.m_pMemory[m_Parent].m_Left == i;
}

//------------------------------------------------------------------------------
// Address: 0x00403A80
// Name: protected: void CUtlRBTree<struct sv_t __near *,int,bool (*)(struct sv_t __near * const __near &,struct sv_t __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct sv_t __near *,int>,int>>::RotateLeft(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::RotateLeft(
        CUtlRBTree<sv_t *,int,bool (__cdecl*)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int> > *this,
        int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<sv_t *,int> *v4; // ecx
  int m_Right; // edi
  UtlRBTreeNode_t<sv_t *,int> *v6; // eax
  int v7; // eax
  UtlRBTreeNode_t<sv_t *,int> *v8; // ecx
  UtlRBTreeNode_t<sv_t *,int> *v9; // eax

  v2 = `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_5A7EFC = -1;
    dword_5A7F00 = -1;
    dword_5A7F04 = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<sv_t *,int> *)&`CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Right = v4->m_Right;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_5A7EFC = -1;
    dword_5A7F00 = -1;
    dword_5A7F04 = 1;
  }
  if ( m_Right == -1 )
    v6 = (UtlRBTreeNode_t<sv_t *,int> *)&`CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Right];
  this->m_Elements.m_pMemory[elem].m_Right = v6->m_Left;
  v7 = `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v7 = `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_5A7EFC = -1;
    dword_5A7F00 = -1;
    dword_5A7F04 = 1;
  }
  if ( m_Right == -1 )
    v8 = (UtlRBTreeNode_t<sv_t *,int> *)&`CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v8 = &this->m_Elements.m_pMemory[m_Right];
  if ( v8->m_Left != -1 )
  {
    if ( (v7 & 1) == 0 )
    {
      `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard' = v7 | 1;
      `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_5A7EFC = -1;
      dword_5A7F00 = -1;
      dword_5A7F04 = 1;
    }
    if ( m_Right == -1 )
      v9 = (UtlRBTreeNode_t<sv_t *,int> *)&`CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::s_Sentinel;
    else
      v9 = &this->m_Elements.m_pMemory[m_Right];
    this->m_Elements.m_pMemory[v9->m_Left].m_Parent = elem;
  }
  if ( m_Right != -1 )
    this->m_Elements.m_pMemory[m_Right].m_Parent = CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Parent(
                                                     this,
                                                     i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Right;
  }
  else if ( CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::IsLeftChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Right;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Right;
  }
  this->m_Elements.m_pMemory[m_Right].m_Left = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Right;
}

//------------------------------------------------------------------------------
// Address: 0x00403C30
// Name: protected: void CUtlRBTree<struct sv_t __near *,int,bool (*)(struct sv_t __near * const __near &,struct sv_t __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct sv_t __near *,int>,int>>::RotateRight(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::RotateRight(
        CUtlRBTree<sv_t *,int,bool (__cdecl*)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int> > *this,
        int elem)
{
  int v2; // eax
  UtlRBTreeNode_t<sv_t *,int> *v4; // ecx
  int m_Left; // edi
  UtlRBTreeNode_t<sv_t *,int> *v6; // eax
  UtlRBTreeNode_t<sv_t *,int> *v7; // eax

  v2 = `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_5A7EFC = -1;
    dword_5A7F00 = -1;
    dword_5A7F04 = 1;
  }
  if ( elem == -1 )
    v4 = (UtlRBTreeNode_t<sv_t *,int> *)&`CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[elem];
  m_Left = v4->m_Left;
  if ( (v2 & 1) == 0 )
  {
    `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
    `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_5A7EFC = -1;
    dword_5A7F00 = -1;
    dword_5A7F04 = 1;
  }
  if ( m_Left == -1 )
    v6 = (UtlRBTreeNode_t<sv_t *,int> *)&`CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v6 = &this->m_Elements.m_pMemory[m_Left];
  this->m_Elements.m_pMemory[elem].m_Left = v6->m_Right;
  if ( (`CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_5A7EFC = -1;
    dword_5A7F00 = -1;
    dword_5A7F04 = 1;
  }
  if ( m_Left == -1 )
    v7 = (UtlRBTreeNode_t<sv_t *,int> *)&`CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v7 = &this->m_Elements.m_pMemory[m_Left];
  if ( v7->m_Right != -1 )
    this->m_Elements.m_pMemory[CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::RightChild(
                                 this,
                                 i: m_Left)].m_Parent = elem;
  if ( m_Left != -1 )
    this->m_Elements.m_pMemory[m_Left].m_Parent = CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Parent(
                                                    this,
                                                    i: elem);
  if ( elem == this->m_Root )
  {
    this->m_Root = m_Left;
  }
  else if ( CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::IsRightChild(
              this,
              i: elem) )
  {
    this->m_Elements.m_pMemory[CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Right = m_Left;
  }
  else
  {
    this->m_Elements.m_pMemory[CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Parent(
                                 this,
                                 i: elem)].m_Left = m_Left;
  }
  this->m_Elements.m_pMemory[m_Left].m_Right = elem;
  if ( elem != -1 )
    this->m_Elements.m_pMemory[elem].m_Parent = m_Left;
}

//------------------------------------------------------------------------------
// Address: 0x00403DA0
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
// Address: 0x00403DD0
// Name: public: void CMasterDlg::ConfigPoll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterDlg::ConfigPoll(CMasterDlg *this)
{
  KeyValues *v1; // eax
  KeyValues *v2; // ebx
  bool v3; // zf
  int Int; // edi
  KeyValues *v5; // ecx
  int v6; // eax
  int v7; // esi
  CMasterDlg *v8; // esi
  int v9; // [esp-24h] [ebp-60h]
  CUtlBuffer xlspBuffer; // [esp+8h] [ebp-34h] BYREF
  CMasterDlg *v11; // [esp+38h] [ebp-4h]

  v11 = this;
  v1 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v1 != nullptr )
    v2 = KeyValues::KeyValues(this: v1, setName: g_szXlspDataRoot);
  else
    v2 = nullptr;
  CUtlBuffer::CUtlBuffer(this: &xlspBuffer, growSize: 0, initSize: 0, nFlags: 0);
  if ( !ReadFileToBuffer(pSourceName: g_szCenterChunkFile, buffer: &xlspBuffer, bText: true) )
  {
    if ( xlspBuffer.m_Memory.m_nGrowSize < 0 )
    {
LABEL_9:
      v3 = v2 == nullptr;
      goto LABEL_26;
    }
    if ( xlspBuffer.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: xlspBuffer.m_Memory.m_pMemory);
      xlspBuffer.m_Memory.m_pMemory = nullptr;
    }
LABEL_8:
    xlspBuffer.m_Memory.m_nAllocationCount = 0;
    goto LABEL_9;
  }
  if ( KeyValues::LoadFromBuffer(
         this: v2,
         resourceName: g_szXlspDataRoot,
         buf: &xlspBuffer,
         pFileSystem: nullptr,
         pPathID: nullptr,
         pfnEvaluateSymbolProc: nullptr) )
  {
    Int = KeyValues::GetInt(this: v2, keyName: "version", defaultValue: 0);
    if ( InfoChunks::g_arrChunks.m_Size != 0 )
      v5 = *InfoChunks::g_arrChunks.m_Memory.m_pMemory;
    else
      v5 = nullptr;
    v6 = KeyValues::GetInt(this: v5, keyName: "version", defaultValue: 0);
    v7 = v6;
    if ( Int != 0 && v6 != 0 && Int > v6 )
    {
      _Msg(a1: "Need reloading configuration file (old version = %d, new version = %d)\n", v6, Int);
      KeyValuesDumpAsDevMsg(pKeyValues: v2, nIndentLevel: 1, nDeveloperLevel: 0);
      v9 = v7;
      v8 = v11;
      CMasterDlg::Sys_Printf(
        this: v11,
        pMsg: "********* Scheduling to reload configuration file in %u sec (old version = %d, new version = %d)\n",
        5,
        v9,
        Int);
      SetTimer(hWnd: v8->m_hWnd, nIDEvent: 0x378u, uElapse: 0x1388u, lpTimerFunc: nullptr);
    }
    if ( xlspBuffer.m_Memory.m_nGrowSize >= 0 )
    {
      if ( xlspBuffer.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: xlspBuffer.m_Memory.m_pMemory);
        xlspBuffer.m_Memory.m_pMemory = nullptr;
      }
      xlspBuffer.m_Memory.m_nAllocationCount = 0;
    }
    v3 = v2 == nullptr;
  }
  else
  {
    if ( xlspBuffer.m_Memory.m_nGrowSize < 0 )
      goto LABEL_9;
    if ( xlspBuffer.m_Memory.m_pMemory == nullptr )
      goto LABEL_8;
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: xlspBuffer.m_Memory.m_pMemory);
    xlspBuffer.m_Memory.m_pMemory = nullptr;
    xlspBuffer.m_Memory.m_nAllocationCount = 0;
    v3 = v2 == nullptr;
  }
LABEL_26:
  if ( !v3 )
    KeyValues::deleteThis(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x00403F50
// Name: private: void CMasterDlg::NET_Init(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CMasterDlg::NET_Init(CMasterDlg *this@<ecx>, __int128 a2@<xmm0>)
{
  int Error; // eax
  const char *v4; // eax
  SOCKET v5; // eax
  u_short v6; // ax
  SOCKET m_net_socket; // edx
  int v8; // edi
  int *v9; // eax
  const char *v10; // eax
  int v11; // [esp-4h] [ebp-1ACh]
  u_short m_net_hostport; // [esp-4h] [ebp-1ACh]
  WSAData wsaData; // [esp+4h] [ebp-1A4h] BYREF
  sockaddr_in address; // [esp+194h] [ebp-14h] BYREF
  unsigned int opt; // [esp+1A4h] [ebp-4h] BYREF

  Error = WSAStartup(wVersionRequested: 2u, lpWSAData: &wsaData);
  if ( Error != 0 )
  {
LABEL_2:
    v11 = Error;
    v4 = strerror(errnum: Error);
    CMasterDlg::Sys_Error(this, pFormat: "NET_Init: socket: %s %i", v4, v11);
  }
  v5 = socket(af: 2, type: 2, protocol: 17);
  this->m_net_socket = v5;
  if ( v5 == -1 )
  {
    Error = WSAGetLastError();
    goto LABEL_2;
  }
  opt = 1;
  ioctlsocket(s: v5, cmd: -2147195266, argp: &opt);
  m_net_hostport = this->m_net_hostport;
  address.sin_family = 2;
  address.sin_addr.S_un.S_addr = 0;
  v6 = htons(hostshort: m_net_hostport);
  m_net_socket = this->m_net_socket;
  address.sin_port = v6;
  if ( bind(s: m_net_socket, name: (const struct sockaddr *)&address, namelen: 16) == -1 )
  {
    v8 = WSAGetLastError();
    v9 = _errno();
    v10 = strerror(errnum: *v9);
    CMasterDlg::Sys_Error(this, pFormat: "NET_Init: bind to %i failed: %s %i", this->m_net_hostport, v10, v8);
  }
  CMasterDlg::NET_GetLocalAddress(this, a2);
}

//------------------------------------------------------------------------------
// Address: 0x00404030
// Name: private: void CMasterDlg::GenerateFakeServers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterDlg::GenerateFakeServers(CMasterDlg *this)
{
  unsigned int m_NumElements; // edi
  unsigned int v4; // edx
  bool v9; // zf
  signed int v10; // eax
  bool v11; // zf
  signed int v12; // eax
  const char *v13; // edi
  int v14; // eax
  int v15; // et2
  int v16; // eax
  int i; // edi
  int v18; // eax
  unsigned int v27; // ecx
  char info[1024]; // [esp+Ch] [ebp-85Ch] BYREF
  char temp[1024]; // [esp+40Ch] [ebp-45Ch] BYREF
  char szModName[32]; // [esp+80Ch] [ebp-5Ch] BYREF
  char value[32]; // [esp+82Ch] [ebp-3Ch] BYREF
  CMasterDlg *v33; // [esp+854h] [ebp-14h]
  int v34; // [esp+858h] [ebp-10h]
  unsigned int pulCRC; // [esp+85Ch] [ebp-Ch] BYREF
  unsigned int v36; // [esp+860h] [ebp-8h] BYREF
  int c; // [esp+864h] [ebp-4h]

  _EBX = this;
  v33 = this;
  v34 = 1000;
  do
  {
    _ESI = (sv_t *)operator new(nSize: 0x914u);
    memset(dst: (unsigned __int8 *)_ESI, value: 0, count: sizeof(sv_t));
    m_NumElements = _EBX->m_XLSPPortMapping.m_Tree.m_NumElements;
    v4 = rand() % m_NumElements;
    _ECX = _EBX->m_XLSPPortMapping.m_Tree.m_Elements.m_pMemory;
    _EAX = 100 * v4;
    __asm
    {
      movq    xmm0, qword ptr [eax+this+10h]
      movq    xmm1, qword ptr [eax+this+18h]
    }
    __asm
    {
      movq    qword ptr [esi+4], xmm0
      movq    qword ptr [esi+0Ch], xmm1
    }
    _ESI->hXLSPPort = v4;
    _ESI->uniqueid = _EBX->m_nUniqueID++;
    _ESI->islan = 1;
    v10 = rand() & 0x80000007;
    v9 = v10 == 0;
    if ( v10 < 0 )
      v9 = (((_BYTE)v10 - 1) | 0xFFFFFFF8) == -1;
    _ESI->bIsReserved = v9;
    v12 = rand() & 0x80000001;
    v11 = v12 == 0;
    if ( v12 < 0 )
      v11 = (((_BYTE)v12 - 1) | 0xFFFFFFFE) == -1;
    v13 = "mod";
    if ( !v11 )
      v13 = "MOD";
    v14 = rand();
    V_snprintf(pDest: szModName, maxLen: 32, pFormat: "%s%03i", v13, v14 % 10);
    V_strncpy(pDest: _ESI->gamedir.value, pSrc: szModName, maxLen: 64);
    strlwr(string: _ESI->gamedir.value);
    c = strlen(_ESI->gamedir.value);
    _ESI->gamedir.length = c;
    CRC32_Init(&pulCRC);
    CRC32_ProcessBuffer(&pulCRC, pBuffer: _ESI->gamedir.value, nBuffer: c);
    CRC32_Final(&pulCRC);
    _ESI->gamedir.checksum = pulCRC;
    _ESI->maxPlayers = rand() % 30 + 2;
    v15 = rand() % _ESI->maxPlayers;
    _ESI->players = v15;
    if ( v15 != 0 )
      _ESI->bots = rand() % _ESI->players;
    else
      _ESI->bots = 0;
    v16 = rand();
    V_snprintf(pDest: temp, maxLen: 1024, pFormat: "map%03i", v16 % 10);
    V_strncpy(pDest: _ESI->map.value, pSrc: temp, maxLen: 64);
    strlwr(string: _ESI->map.value);
    c = strlen(_ESI->map.value);
    _ESI->map.length = c;
    CRC32_Init(pulCRC: &v36);
    CRC32_ProcessBuffer(pulCRC: &v36, pBuffer: _ESI->map.value, nBuffer: c);
    CRC32_Final(pulCRC: &v36);
    _ESI->map.checksum = v36;
    c = rand() & 7;
    if ( c == 0 )
      c = 1;
    for ( i = 0; i < c; ++i )
    {
      v18 = rand();
      V_snprintf(pDest: value, maxLen: 32, pFormat: "%i", v18 % 100);
      V_snprintf(pDest: info, maxLen: 1024, pFormat: "\\%s\\%s", g_FakeInfoKeys[i], value);
      V_strncat(pDest: _ESI->info, pSrc: info, destBufferSize: 0x800u, max_chars_to_copy: -1);
    }
    _ESI->info_length = strlen(_ESI->info) + 1;
    __asm
    {
      movd    xmm0, dword ptr [ebx+154h]
      cvtdq2pd xmm0, xmm0
      movsd   [ebp+var_1C], xmm0
    }
    _EDX = rand() % 1000;
    __asm
    {
      movsd   xmm0, [ebp+var_1C]
      xorps   xmm1, xmm1
      cvtsi2sd xmm1, edx
      subsd   xmm0, xmm1
      cvttsd2si edx, xmm0
    }
    _ESI->time = _EDX;
    _EBX = v33;
    v27 = (SHIBYTE(_ESI->address.sin_port)
         ^ ((SLOBYTE(_ESI->address.sin_port)
           ^ (((char)_ESI->address.sin_addr.S_un.S_un_b.s_b4
             ^ (((char)_ESI->address.sin_addr.S_un.S_un_b.s_b3
               ^ (((char)_ESI->address.sin_addr.S_un.S_un_b.s_b2
                 ^ (((char)_ESI->address.sin_addr.S_un.S_un_b.s_b1
                   ^ (unsigned int)(2 * (char)_ESI->address.sin_addr.S_un.S_un_b.s_b1))
                  + 2 * (char)_ESI->address.sin_addr.S_un.S_un_b.s_b2))
                + 2 * (char)_ESI->address.sin_addr.S_un.S_un_b.s_b3))
              + 2 * (char)_ESI->address.sin_addr.S_un.S_un_b.s_b4))
            + 2 * SLOBYTE(_ESI->address.sin_port)))
          + 2 * SHIBYTE(_ESI->address.sin_port)))
        % 0x7E3;
    v9 = v34-- == 1;
    _ESI->next = v33->m_pGameServers[v27];
    _EBX->m_pGameServers[v27] = _ESI;
  }
  while ( !v9 );
}

//------------------------------------------------------------------------------
// Address: 0x00404370
// Name: ServerListSortFunc
// Source: json
//------------------------------------------------------------------------------
bool __cdecl ServerListSortFunc(sv_t *const *pLHS, sv_t *const *pRHS)
{
  int hXLSPPort; // edi
  int v3; // esi
  int v4; // eax
  UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int> *m_pMemory; // eax
  int nXLSPPort; // esi
  int v8; // edi
  int v9; // edx

  hXLSPPort = (*pRHS)->hXLSPPort;
  v3 = (*pLHS)->hXLSPPort;
  v4 = strcmp(
         g_pMaster->m_XLSPPortMapping.m_Tree.m_Elements.m_pMemory[v3].m_Data.elem.SGName,
         g_pMaster->m_XLSPPortMapping.m_Tree.m_Elements.m_pMemory[hXLSPPort].m_Data.elem.SGName);
  if ( v4 != 0 )
    return v4 < 0;
  m_pMemory = g_pMaster->m_XLSPPortMapping.m_Tree.m_Elements.m_pMemory;
  nXLSPPort = m_pMemory[v3].m_Data.elem.nXLSPPort;
  v8 = m_pMemory[hXLSPPort].m_Data.elem.nXLSPPort;
  if ( s_bServerListSortFuncJitter
    && (v9 = (s_nServerListSortFuncStart + nXLSPPort % s_nServerListSortFuncSeed) % s_nServerListSortFuncSeed
           - (s_nServerListSortFuncStart + v8 % s_nServerListSortFuncSeed) % s_nServerListSortFuncSeed) != 0 )
  {
    return v9 < 0;
  }
  else
  {
    return nXLSPPort - v8 < 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404430
// Name: public: virtual bool CReportingThread::Init(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CReportingThread::Init@<al>(
        CReportingThread *this@<ecx>,
        unsigned int a2@<ebx>,
        const char *chFileName)
{
  KeyValues *Key; // eax
  const char *client_info; // eax
  const char *v7; // eax
  const char *server_info; // eax
  bool (__thiscall *Start_2)(CReportingThread *, unsigned int); // eax
  bool v10; // bl
  const char *v11; // [esp-1Ch] [ebp-54h]
  const char *v12; // [esp-18h] [ebp-50h]
  const char *String; // [esp-14h] [ebp-4Ch]
  int Int; // [esp-10h] [ebp-48h]
  int v15; // [esp-8h] [ebp-40h]
  int v16; // [esp-8h] [ebp-40h]
  const wchar_t *v17; // [esp-4h] [ebp-3Ch]
  CUtlBuffer fileBuffer; // [esp+8h] [ebp-30h] BYREF

  if ( chFileName == nullptr || *chFileName == 0 )
    return 1;
  CUtlBuffer::CUtlBuffer(this: &fileBuffer, growSize: 0, initSize: 0, nFlags: 0);
  if ( ReadFileToBuffer(pSourceName: chFileName, buffer: &fileBuffer, bText: true) )
  {
    if ( KeyValues::LoadFromBuffer(
           this: this->m_pConfig,
           resourceName: "SqlConfig",
           buf: &fileBuffer,
           pFileSystem: nullptr,
           pPathID: nullptr,
           pfnEvaluateSymbolProc: nullptr) )
    {
      Key = KeyValues::FindKey(this: this->m_pConfig, keyName: "tabledef", bCreate: false);
      if ( KeyValues::GetFirstValue(this: Key) != nullptr )
      {
        client_info = (const char *)mysql_get_client_info();
        _Msg(a1: "MySQL Client API Version is %s\n", client_info);
        if ( mysql_init(mysql: &this->m_mysql, a2) != 0 )
        {
          mysql_options(mysql: (_iobuf *)&this->m_mysql);
          Int = KeyValues::GetInt(this: this->m_pConfig, keyName: "db/port", defaultValue: 0);
          String = KeyValues::GetString(this: this->m_pConfig, keyName: "db/schema", defaultValue: defaultValue);
          v12 = KeyValues::GetString(this: this->m_pConfig, keyName: "db/pwd", defaultValue: defaultValue);
          v11 = KeyValues::GetString(this: this->m_pConfig, keyName: "db/user", defaultValue: defaultValue);
          v7 = KeyValues::GetString(this: this->m_pConfig, keyName: "db/host", defaultValue: defaultValue);
          if ( mysql_real_connect(a1: &this->m_mysql, a2: v7, a3: v11, a4: v12, a5: String, a6: Int, a7: 0, a8: 0) != 0 )
          {
            mysql_options(mysql: (_iobuf *)&this->m_mysql);
            server_info = (const char *)mysql_get_server_info(mysql: (const wchar_t *)&this->m_mysql, a2: v17);
            _Msg(a1: "MySQL Server Version is %s\n", server_info);
            Start_2 = this->Start_2;
            this->m_bMySqlConnected = true;
            v10 = Start_2(this, a2: 0);
            CUtlBuffer::~CUtlBuffer(this: &fileBuffer);
            return v10;
          }
          mysql_close(a1: &this->m_mysql);
          v16 = mysql_error(mysql: (const wchar_t *)&this->m_mysql, a2: v17);
          _Error(a1: "mysql_real_connect failed! %s\n", v16);
        }
        else
        {
          v15 = mysql_error(mysql: (const wchar_t *)&this->m_mysql, a2: v17);
          _Error(a1: "mysql_init failed! %s\n", v15);
        }
      }
      else
      {
        _Error(a1: "XLSPMaster: SQL Configuration '%s' is missing tabledef", chFileName);
      }
    }
    else
    {
      _Error(a1: "XLSPMaster: Failed to unserialize SQL Configuration '%s'", chFileName);
    }
    CUtlBuffer::~CUtlBuffer(this: &fileBuffer);
    return 0;
  }
  _Error(a1: "XLSPMaster: Failed to load SQL Configuration '%s'", chFileName);
  if ( fileBuffer.m_Memory.m_nGrowSize >= 0 && fileBuffer.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileBuffer.m_Memory.m_pMemory);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00404650
// Name: private: virtual int CReportingThread::Run(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall CReportingThread::Run@<eax>(CReportingThread *this@<ecx>, __int128 _XMM0@<xmm0>, __int128 _XMM1@<xmm1>)
{
  const char *String; // eax
  char *v5; // edi
  KeyValues *Key; // eax
  KeyValues *i; // esi
  const char *v8; // eax
  KeyValues *v9; // esi
  int m_Size; // eax
  int v12; // eax
  char *v13; // esi
  KeyValues *v14; // eax
  KeyValues *FirstValue; // eax
  int NameSymbol; // eax
  KeyValues *v17; // edi
  int v18; // ecx
  double Float; // st7
  unsigned __int64 Uint64; // rax
  const char *v21; // esi
  const char *v22; // eax
  const char *v23; // edi
  int v24; // eax
  const char *v25; // eax
  CFmtStrN<256> *v26; // eax
  int v27; // eax
  int v28; // esi
  const char *v29; // eax
  int v30; // edi
  int j; // esi
  double v42; // [esp+0h] [ebp-1148h]
  double v44; // [esp+Ch] [ebp-113Ch]
  double defaultValuea; // [esp+14h] [ebp-1134h]
  double defaultValueb; // [esp+14h] [ebp-1134h]
  int defaultValue_4; // [esp+18h] [ebp-1130h]
  int defaultValue_4a; // [esp+18h] [ebp-1130h]
  float defaultValue_4b; // [esp+18h] [ebp-1130h]
  const char *defaultValue_4c; // [esp+18h] [ebp-1130h]
  const wchar_t *v52; // [esp+1Ch] [ebp-112Ch]
  char pDest[4096]; // [esp+28h] [ebp-1120h] BYREF
  CFmtStrN<256> v54; // [esp+1028h] [ebp-120h] BYREF
  char *str; // [esp+1134h] [ebp-14h]
  float v56; // [esp+1138h] [ebp-10h]
  KeyValues *NextValue; // [esp+113Ch] [ebp-Ch]
  KeyValues *v58; // [esp+1140h] [ebp-8h]
  float v59; // [esp+1144h] [ebp-4h]

  String = KeyValues::GetString(this: this->m_pConfig, keyName: "db/table", defaultValue: ::defaultValue);
  V_snprintf(pDest, maxLen: 128, pFormat: "INSERT INTO %s( ", String);
  v5 = &pDest[_V_strlen(str: pDest)];
  Key = KeyValues::FindKey(this: this->m_pConfig, keyName: "tabledef", bCreate: false);
  for ( i = KeyValues::GetFirstValue(this: Key); i != nullptr; i = KeyValues::GetNextValue(this: i) )
  {
    v8 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: ::defaultValue);
    V_snprintf(pDest: v5, maxLen: 128, pFormat: "%s, ", v8);
    v5 += _V_strlen(str: v5);
  }
  V_snprintf(pDest: v5 - 2, maxLen: 128, pFormat: " ) VALUES ( ");
  str = &v5[_V_strlen(str: v5)];
  while ( !this->m_bThreadShouldExit )
  {
    v9 = nullptr;
    v59 = 0.0;
    v56 = _Plat_FloatTime();
    m_Size = this->m_ReportData.m_Size;
    if ( m_Size > 0 )
    {
      __asm { movss   xmm0, [ebp+var_10] }
      __asm
      {
        cvtps2pd xmm0, xmm0
        movsd   qword ptr [esp+1134h+defaultValue], xmm0
      }
      _Msg(
        a1: "Reporting %d/%d data rows @ %.2f\n",
        m_Size,
        this->m_ReportData.m_Memory.m_nAllocationCount,
        defaultValuea);
    }
    while ( 1 )
    {
      EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_CS);
      if ( v9 != nullptr )
      {
        if ( this->m_ReportData.m_Size - 1 > 0 )
          _V_memmove(
            dest: this->m_ReportData.m_Memory.m_pMemory,
            src: this->m_ReportData.m_Memory.m_pMemory + 1,
            count: 4 * (this->m_ReportData.m_Size - 1));
        --this->m_ReportData.m_Size;
        KeyValues::deleteThis(this: v9);
      }
      v12 = this->m_ReportData.m_Size;
      if ( v12 != 0 )
      {
        v58 = *this->m_ReportData.m_Memory.m_pMemory;
        if ( v12 > s_nMaxCount )
        {
          s_nMaxCount = v12;
          _Msg(a1: "Report backlog peaked at %d\n", v12);
        }
      }
      else
      {
        v58 = nullptr;
      }
      LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_CS);
      if ( v58 == nullptr )
        break;
      v13 = str;
      v14 = KeyValues::FindKey(this: this->m_pConfig, keyName: "tabledef", bCreate: false);
      FirstValue = KeyValues::GetFirstValue(this: v14);
      NextValue = FirstValue;
      if ( FirstValue != nullptr )
      {
        while ( 1 )
        {
          NameSymbol = KeyValues::GetNameSymbol(this: FirstValue);
          v17 = KeyValues::FindKey(this: v58, keySymbol: NameSymbol);
          switch ( KeyValues::GetDataType(this: v17, keyName: nullptr) )
          {
            case TYPE_STRING:
              *v13 = 39;
              v21 = v13 + 1;
              v22 = KeyValues::GetString(this: v17, keyName: nullptr, defaultValue: ::defaultValue);
              v23 = v22;
              if ( v22 != nullptr )
              {
                v24 = _V_strlen(str: v22);
                mysql_escape_string(a1: v21, a2: v23, a3: v24);
              }
              v13 = (char *)&v21[_V_strlen(str: v21)];
              V_snprintf(pDest: v13, maxLen: 128, pFormat: "', ");
              break;
            case TYPE_INT:
              defaultValue_4 = KeyValues::GetInt(this: v17, keyName: nullptr, defaultValue: 0);
              V_snprintf(pDest: v13, maxLen: 128, pFormat: "%d, ", defaultValue_4);
              break;
            case TYPE_FLOAT:
              __asm { xorps   xmm0, xmm0; jumptable 0040483E case 3 }
              defaultValue_4a = v18;
              __asm { movss   [esp+1130h+defaultValue+4], xmm0; defaultValue }
              Float = KeyValues::GetFloat(this: v17, keyName: nullptr, defaultValue: defaultValue_4b);
              V_snprintf(pDest: v13, maxLen: 128, pFormat: "%.3f, ", Float);
              break;
            case TYPE_UINT64:
              Uint64 = KeyValues::GetUint64(this: v17, keyName: nullptr, defaultValue: 0);
              V_snprintf(pDest: v13, maxLen: 128, pFormat: "%llu, ", Uint64);
              break;
            default:
              v25 = KeyValues::GetString(this: NextValue, keyName: nullptr, defaultValue: ::defaultValue);
              v26 = CFmtStrN<256>::CFmtStrN<256>(this: &v54, pszFormat: "defaultvalues/%s", v25);
              defaultValue_4c = KeyValues::GetString(this: this->m_pConfig, keyName: v26->m_szBuf, defaultValue: "NULL");
              V_snprintf(pDest: v13, maxLen: 128, pFormat: "%s, ", defaultValue_4c);
              break;
          }
          v13 += _V_strlen(str: v13);
          NextValue = KeyValues::GetNextValue(this: NextValue);
          if ( NextValue == nullptr )
            break;
          FirstValue = NextValue;
        }
      }
      V_snprintf(pDest: v13 - 2, maxLen: 128, pFormat: " )");
      v27 = _V_strlen(str: v13);
      if ( mysql_real_query(a1: &this->m_mysql, a2: pDest, a3: &v13[v27] - pDest) != 0 )
      {
        v28 = this->m_ReportData.m_Size;
        v29 = (const char *)mysql_error(mysql: (const wchar_t *)&this->m_mysql, a2: v52);
        _Warning(a1: "Error while submitting query (backlog = %d)! %s\n", v28, v29);
        if ( this->m_ReportData.m_Size > 200000 )
        {
          v30 = 0;
          do
          {
            EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_CS);
            for ( j = 0; j < 1000; ++j )
              KeyValues::deleteThis(this: this->m_ReportData.m_Memory.m_pMemory[j]);
            if ( this->m_ReportData.m_Size - 1000 > 0 )
              _V_memmove(
                dest: this->m_ReportData.m_Memory.m_pMemory,
                src: this->m_ReportData.m_Memory.m_pMemory + 1000,
                count: 4 * (this->m_ReportData.m_Size - 1000));
            this->m_ReportData.m_Size -= 1000;
            LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_CS);
            v30 += 1000;
          }
          while ( this->m_ReportData.m_Size > 100000 );
          _Warning(a1: "Purged %d backlogged records! Normal backlog size = %d\n", v30, this->m_ReportData.m_Size);
        }
        break;
      }
      ++LODWORD(v59);
      v9 = v58;
    }
    _ESI = v59;
    if ( SLODWORD(v59) > 0 )
    {
      v59 = _Plat_FloatTime();
      __asm { movss   xmm1, [ebp+var_4] }
      _XMM0 = _XMM1;
      __asm { subss   xmm0, [ebp+var_10] }
      if ( *(float *)&_XMM0 > 0.0 )
      {
        __asm { cvtps2pd xmm1, xmm1 }
        __asm
        {
          movsd   qword ptr [esp+113Ch+defaultValue], xmm1
          xorps   xmm1, xmm1
          cvtss2sd xmm1, xmm0
          movsd   [esp+113Ch+var_113C], xmm1
          xorps   xmm1, xmm1
        }
        __asm
        {
          cvtsi2ss xmm1, esi
          divss   xmm1, xmm0
          xorps   xmm0, xmm0
        }
        __asm
        {
          cvtps2pd xmm0, xmm1
          movsd   [esp+1148h+var_1148], xmm0
        }
        _Msg(a1: "Report throughput is %.0f rows/sec [%d/%.2f] @%.2f\n", v42, _ESI, v44, defaultValueb);
      }
    }
    _ThreadSleep(a1: 1000);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00404B00
// Name: public: int CUtlRBTree<struct CUtlMap<struct sockaddr_in,struct xlspTitleServer_t,int>::Node_t,int,class CUtlMap<struct sockaddr_in,struct xlspTitleServer_t,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<struct sockaddr_in,struct xlspTitleServer_t,int>::Node_t,int>,int>>::Find(struct CUtlMap<struct sockaddr_in,struct xlspTitleServer_t,int>::Node_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Find(
        CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int> > *this,
        const CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t *search)
{
  int m_Root; // ebx
  int v4; // esi

  m_Root = this->m_Root;
  if ( m_Root == -1 )
    return -1;
  do
  {
    v4 = m_Root;
    if ( this->m_LessFunc.m_LessFunc(a1: search, a2: &this->m_Elements.m_pMemory[m_Root].m_Data) != 0 )
    {
      if ( (`CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_5A7EE8 = -1;
        dword_5A7EEC = -1;
        dword_5A7EF0 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[m_Root].m_Left;
    }
    else
    {
      if ( this->m_LessFunc.m_LessFunc(a1: &this->m_Elements.m_pMemory[v4].m_Data, a2: search) == 0 )
        return m_Root;
      if ( (`CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_5A7EE8 = -1;
        dword_5A7EEC = -1;
        dword_5A7EF0 = 1;
      }
      m_Root = this->m_Elements.m_pMemory[v4].m_Right;
    }
  }
  while ( m_Root != -1 );
  return m_Root;
}

//------------------------------------------------------------------------------
// Address: 0x00404BF0
// Name: public: int CUtlRBTree<struct CUtlMap<struct sockaddr_in,struct xlspTitleServer_t,int>::Node_t,int,class CUtlMap<struct sockaddr_in,struct xlspTitleServer_t,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<struct sockaddr_in,struct xlspTitleServer_t,int>::Node_t,int>,int>>::FirstInorder(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::FirstInorder(
        CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int> > *this)
{
  int v1; // ebx
  int result; // eax
  int *v3; // edx

  v1 = `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  result = this->m_Root;
  while ( 1 )
  {
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_5A7EE8 = -1;
      dword_5A7EEC = -1;
      dword_5A7EF0 = 1;
    }
    v3 = result == -1
       ? &`CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
       : (int *)&this->m_Elements.m_pMemory[result];
    if ( *v3 == -1 )
      break;
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_5A7EE8 = -1;
      dword_5A7EEC = -1;
      dword_5A7EF0 = 1;
    }
    if ( result == -1 )
      result = `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
    else
      result = this->m_Elements.m_pMemory[result].m_Left;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00404C80
// Name: public: int CUtlRBTree<struct CUtlMap<struct sockaddr_in,struct xlspTitleServer_t,int>::Node_t,int,class CUtlMap<struct sockaddr_in,struct xlspTitleServer_t,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<struct sockaddr_in,struct xlspTitleServer_t,int>::Node_t,int>,int>>::NextInorder(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::NextInorder(
        CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int> > *this,
        int i)
{
  int v2; // edx
  UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int> *v4; // ecx
  UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int> *v5; // eax
  int result; // eax
  int *v7; // ecx
  UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int> *v8; // ecx
  int m_Parent; // esi
  int v10; // [esp-4h] [ebp-10h]

  v2 = `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
  if ( (`CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    v2 = `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
       | 1;
    `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_5A7EE8 = -1;
    dword_5A7EEC = -1;
    dword_5A7EF0 = 1;
  }
  if ( i == -1 )
    v4 = (UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v4 = &this->m_Elements.m_pMemory[i];
  if ( v4->m_Right == -1 )
  {
    if ( (v2 & 1) == 0 )
    {
      `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2 | 1;
      `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_5A7EE8 = -1;
      dword_5A7EEC = -1;
      dword_5A7EF0 = 1;
    }
    if ( i == -1 )
      v8 = (UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
    else
      v8 = &this->m_Elements.m_pMemory[i];
    m_Parent = v8->m_Parent;
    if ( CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::IsRightChild(
           this,
           i) )
    {
      do
      {
        if ( m_Parent == -1 )
          break;
        if ( (`CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_5A7EE8 = -1;
          dword_5A7EEC = -1;
          dword_5A7EF0 = 1;
        }
        v10 = m_Parent;
        m_Parent = this->m_Elements.m_pMemory[m_Parent].m_Parent;
      }
      while ( CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::IsRightChild(
                this,
                i: v10) );
    }
    return m_Parent;
  }
  else
  {
    if ( (v2 & 1) == 0 )
    {
      v2 |= 1u;
      `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2;
      `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_5A7EE8 = -1;
      dword_5A7EEC = -1;
      dword_5A7EF0 = 1;
    }
    if ( i == -1 )
      v5 = (UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
    else
      v5 = &this->m_Elements.m_pMemory[i];
    result = v5->m_Right;
    while ( 1 )
    {
      if ( (v2 & 1) == 0 )
      {
        v2 |= 1u;
        `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2;
        `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_5A7EE8 = -1;
        dword_5A7EEC = -1;
        dword_5A7EF0 = 1;
      }
      v7 = result == -1
         ? &`CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel
         : (int *)&this->m_Elements.m_pMemory[result];
      if ( *v7 == -1 )
        break;
      if ( (v2 & 1) == 0 )
      {
        v2 |= 1u;
        `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v2;
        `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_5A7EE8 = -1;
        dword_5A7EEC = -1;
        dword_5A7EF0 = 1;
      }
      if ( result == -1 )
        result = `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        result = this->m_Elements.m_pMemory[result].m_Left;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00404E30
// Name: public: int CUtlRBTree<struct sv_t __near *,int,bool (*)(struct sv_t __near * const __near &,struct sv_t __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct sv_t __near *,int>,int>>::FirstInorder(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::FirstInorder(
        CUtlRBTree<sv_t *,int,bool (__cdecl*)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int> > *this)
{
  int v1; // ebx
  int result; // eax
  int *v3; // edx

  v1 = `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard';
  result = this->m_Root;
  while ( 1 )
  {
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_5A7EFC = -1;
      dword_5A7F00 = -1;
      dword_5A7F04 = 1;
    }
    v3 = result == -1
       ? &`CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::s_Sentinel
       : (int *)&this->m_Elements.m_pMemory[result];
    if ( *v3 == -1 )
      break;
    if ( (v1 & 1) == 0 )
    {
      v1 |= 1u;
      `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard' = v1;
      `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::s_Sentinel = -1;
      dword_5A7EFC = -1;
      dword_5A7F00 = -1;
      dword_5A7F04 = 1;
    }
    if ( result == -1 )
      result = `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::s_Sentinel;
    else
      result = this->m_Elements.m_pMemory[result].m_Left;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00404ED0
// Name: public: int CUtlRBTree<struct sv_t __near *,int,bool (*)(struct sv_t __near * const __near &,struct sv_t __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct sv_t __near *,int>,int>>::NextInorder(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::NextInorder(
        CUtlRBTree<sv_t *,int,bool (__cdecl*)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int> > *this,
        int i)
{
  UtlRBTreeNode_t<sv_t *,int> *v3; // eax
  int result; // eax
  int v5; // edx
  int *v6; // ecx
  int m_Parent; // esi
  int v8; // ecx

  if ( (`CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard'
      & 1) == 0 )
  {
    `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
    `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::s_Sentinel = -1;
    dword_5A7EFC = -1;
    dword_5A7F00 = -1;
    dword_5A7F04 = 1;
  }
  if ( i == -1 )
    v3 = (UtlRBTreeNode_t<sv_t *,int> *)&`CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::s_Sentinel;
  else
    v3 = &this->m_Elements.m_pMemory[i];
  if ( v3->m_Right == -1 )
  {
    m_Parent = CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Parent(
                 this,
                 i);
    if ( CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::IsRightChild(
           this,
           i) )
    {
      do
      {
        v8 = m_Parent;
        if ( m_Parent == -1 )
          break;
        if ( (`CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_5A7EFC = -1;
          dword_5A7F00 = -1;
          dword_5A7F04 = 1;
        }
        m_Parent = this->m_Elements.m_pMemory[m_Parent].m_Parent;
      }
      while ( CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::IsRightChild(
                this,
                i: v8) );
    }
    return m_Parent;
  }
  else
  {
    result = CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::RightChild(
               this,
               i);
    v5 = `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard';
    while ( 1 )
    {
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_5A7EFC = -1;
        dword_5A7F00 = -1;
        dword_5A7F04 = 1;
      }
      v6 = result == -1
         ? &`CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::s_Sentinel
         : (int *)&this->m_Elements.m_pMemory[result];
      if ( *v6 == -1 )
        break;
      if ( (v5 & 1) == 0 )
      {
        v5 |= 1u;
        `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard' = v5;
        `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_5A7EFC = -1;
        dword_5A7F00 = -1;
        dword_5A7F04 = 1;
      }
      if ( result == -1 )
        result = `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::s_Sentinel;
      else
        result = this->m_Elements.m_pMemory[result].m_Left;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00405040
// Name: public: void CUtlRBTree<struct CUtlMap<struct sockaddr_in,struct xlspTitleServer_t,int>::Node_t,int,class CUtlMap<struct sockaddr_in,struct xlspTitleServer_t,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<struct sockaddr_in,struct xlspTitleServer_t,int>::Node_t,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::RemoveAll(
        CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int> > *this)
{
  int index; // edx
  int v2; // eax
  int v3; // edx

  index = this->m_LastAlloc.index;
  if ( index != -1 )
  {
    v2 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v2 >= 0 && v2 < this->m_Elements.m_nAllocationCount && v2 <= index )
        {
          if ( (`CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_5A7EE8 = -1;
            dword_5A7EEC = -1;
            dword_5A7EF0 = 1;
          }
          if ( this->m_Elements.m_pMemory[v2].m_Left != v2 )
          {
            v3 = v2;
            this->m_Elements.m_pMemory[v3].m_Right = this->m_FirstFree;
            this->m_Elements.m_pMemory[v3].m_Left = v2;
            this->m_FirstFree = v2;
          }
        }
        index = this->m_LastAlloc.index;
        if ( v2 == index )
          break;
        if ( ++v2 < 0 || v2 >= this->m_Elements.m_nAllocationCount )
          v2 = -1;
      }
      while ( v2 != -1 );
    }
    this->m_Root = -1;
    this->m_NumElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405100
// Name: public: void CUtlRBTree<struct sv_t __near *,int,bool (*)(struct sv_t __near * const __near &,struct sv_t __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct sv_t __near *,int>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::RemoveAll(
        CUtlRBTree<sv_t *,int,bool (__cdecl*)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int> > *this)
{
  int index; // edx
  int v2; // eax
  int v3; // edx

  index = this->m_LastAlloc.index;
  if ( index != -1 )
  {
    v2 = (this->m_Elements.m_nAllocationCount > 0) - 1;
    if ( this->m_Elements.m_nAllocationCount > 0 )
    {
      do
      {
        if ( v2 >= 0 && v2 < this->m_Elements.m_nAllocationCount && v2 <= index )
        {
          if ( (`CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_5A7EFC = -1;
            dword_5A7F00 = -1;
            dword_5A7F04 = 1;
          }
          if ( this->m_Elements.m_pMemory[v2].m_Left != v2 )
          {
            v3 = v2;
            this->m_Elements.m_pMemory[v3].m_Right = this->m_FirstFree;
            this->m_Elements.m_pMemory[v3].m_Left = v2;
            this->m_FirstFree = v2;
          }
        }
        index = this->m_LastAlloc.index;
        if ( v2 == index )
          break;
        if ( ++v2 < 0 || v2 >= this->m_Elements.m_nAllocationCount )
          v2 = -1;
      }
      while ( v2 != -1 );
    }
    this->m_Root = -1;
    this->m_NumElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004051C0
// Name: protected: void CUtlRBTree<struct CUtlMap<struct sockaddr_in,struct xlspTitleServer_t,int>::Node_t,int,class CUtlMap<struct sockaddr_in,struct xlspTitleServer_t,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<struct sockaddr_in,struct xlspTitleServer_t,int>::Node_t,int>,int>>::InsertRebalance(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::InsertRebalance(
        CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int> > *this,
        int elem)
{
  int v2; // eax
  int v4; // edx
  UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int> *v5; // ecx
  int m_Parent; // ecx
  UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int> *v7; // ecx
  UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int> *v8; // eax
  int v9; // esi
  UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int> *v10; // eax
  int v11; // ebx
  bool IsLeftChild; // al
  int v13; // ecx
  UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int> *v14; // eax
  int m_Right; // eax
  UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int> *v16; // ecx
  int v17; // eax
  UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int> *v18; // esi
  UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int> *v19; // eax
  UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int> *v20; // eax
  UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int> *v21; // ecx
  int v22; // eax
  UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int> *v23; // esi
  UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int> *v24; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      v4 = `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        v4 = `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_5A7EE8 = -1;
        dword_5A7EEC = -1;
        dword_5A7EF0 = 1;
      }
      if ( v2 == -1 )
        v5 = (UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v5 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v5->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_5A7EE8 = -1;
        dword_5A7EEC = -1;
        dword_5A7EF0 = 1;
      }
      if ( m_Parent == -1 )
        v7 = (UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v7 = &this->m_Elements.m_pMemory[m_Parent];
      if ( v7->m_Tag != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_5A7EE8 = -1;
        dword_5A7EEC = -1;
        dword_5A7EF0 = 1;
      }
      if ( v2 == -1 )
        v8 = (UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      v9 = v8->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
        `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_5A7EE8 = -1;
        dword_5A7EEC = -1;
        dword_5A7EF0 = 1;
      }
      if ( v9 == -1 )
        v10 = (UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v10 = &this->m_Elements.m_pMemory[v9];
      v11 = v10->m_Parent;
      IsLeftChild = CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::IsLeftChild(
                      this,
                      i: v9);
      v13 = `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
      if ( IsLeftChild )
      {
        if ( (`CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_5A7EE8 = -1;
          dword_5A7EEC = -1;
          dword_5A7EF0 = 1;
        }
        if ( v11 == -1 )
          v14 = (UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v14 = &this->m_Elements.m_pMemory[v11];
        m_Right = v14->m_Right;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_5A7EE8 = -1;
          dword_5A7EEC = -1;
          dword_5A7EF0 = 1;
        }
        if ( m_Right == -1 )
          v16 = (UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v16 = &this->m_Elements.m_pMemory[m_Right];
        if ( v16->m_Tag == 0 )
          goto LABEL_61;
        if ( CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::IsRightChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::RotateLeft(
            this,
            elem: v9);
          v17 = `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v17 = `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_5A7EE8 = -1;
            dword_5A7EEC = -1;
            dword_5A7EF0 = 1;
          }
          if ( v9 == -1 )
            v18 = (UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v18 = &this->m_Elements.m_pMemory[v9];
          v9 = v18->m_Parent;
          if ( (v17 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v17 | 1;
            `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_5A7EE8 = -1;
            dword_5A7EEC = -1;
            dword_5A7EF0 = 1;
          }
          if ( v9 == -1 )
            v19 = (UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v19 = &this->m_Elements.m_pMemory[v9];
          v11 = v19->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::RotateRight(
          this,
          elem: v11);
      }
      else
      {
        if ( (`CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_5A7EE8 = -1;
          dword_5A7EEC = -1;
          dword_5A7EF0 = 1;
        }
        if ( v11 == -1 )
          v20 = (UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v20 = &this->m_Elements.m_pMemory[v11];
        m_Right = v20->m_Left;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_5A7EE8 = -1;
          dword_5A7EEC = -1;
          dword_5A7EF0 = 1;
        }
        if ( m_Right == -1 )
          v21 = (UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v21 = &this->m_Elements.m_pMemory[m_Right];
        if ( v21->m_Tag == 0 )
        {
LABEL_61:
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
          goto LABEL_75;
        }
        if ( CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::IsLeftChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::RotateRight(
            this,
            elem: v9);
          v22 = `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v22 = `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_5A7EE8 = -1;
            dword_5A7EEC = -1;
            dword_5A7EF0 = 1;
          }
          if ( v9 == -1 )
            v23 = (UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v23 = &this->m_Elements.m_pMemory[v9];
          v9 = v23->m_Parent;
          if ( (v22 & 1) == 0 )
          {
            `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::`local static guard' = v22 | 1;
            `CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_5A7EE8 = -1;
            dword_5A7EEC = -1;
            dword_5A7EF0 = 1;
          }
          if ( v9 == -1 )
            v24 = (UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int> *)&`CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v24 = &this->m_Elements.m_pMemory[v9];
          v11 = v24->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::RotateLeft(
          this,
          elem: v11);
      }
LABEL_75:
      if ( elem == this->m_Root )
        break;
      v2 = elem;
    }
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x00405610
// Name: protected: void CUtlRBTree<struct sv_t __near *,int,bool (*)(struct sv_t __near * const __near &,struct sv_t __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<struct sv_t __near *,int>,int>>::InsertRebalance(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::InsertRebalance(
        CUtlRBTree<sv_t *,int,bool (__cdecl*)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int> > *this,
        int elem)
{
  int v2; // edx
  int v4; // eax
  UtlRBTreeNode_t<sv_t *,int> *v5; // ecx
  int m_Parent; // ecx
  UtlRBTreeNode_t<sv_t *,int> *v7; // ecx
  UtlRBTreeNode_t<sv_t *,int> *v8; // ecx
  int v9; // esi
  UtlRBTreeNode_t<sv_t *,int> *v10; // eax
  int v11; // edi
  bool IsLeftChild; // al
  int v13; // ecx
  UtlRBTreeNode_t<sv_t *,int> *v14; // eax
  int m_Right; // eax
  UtlRBTreeNode_t<sv_t *,int> *v16; // ecx
  int v17; // eax
  UtlRBTreeNode_t<sv_t *,int> *v18; // ecx
  UtlRBTreeNode_t<sv_t *,int> *v19; // eax
  UtlRBTreeNode_t<sv_t *,int> *v20; // eax
  UtlRBTreeNode_t<sv_t *,int> *v21; // ecx
  int v22; // eax
  UtlRBTreeNode_t<sv_t *,int> *v23; // ecx
  UtlRBTreeNode_t<sv_t *,int> *v24; // eax

  v2 = elem;
  if ( elem != this->m_Root )
  {
    while ( 1 )
    {
      v4 = `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard';
      if ( (`CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        v4 = `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard'
           | 1;
        `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_5A7EFC = -1;
        dword_5A7F00 = -1;
        dword_5A7F04 = 1;
      }
      if ( v2 == -1 )
        v5 = (UtlRBTreeNode_t<sv_t *,int> *)&`CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v5 = &this->m_Elements.m_pMemory[v2];
      m_Parent = v5->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_5A7EFC = -1;
        dword_5A7F00 = -1;
        dword_5A7F04 = 1;
      }
      if ( m_Parent == -1 )
        v7 = (UtlRBTreeNode_t<sv_t *,int> *)&`CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v7 = &this->m_Elements.m_pMemory[m_Parent];
      if ( v7->m_Tag != 0 )
        break;
      if ( (v4 & 1) == 0 )
      {
        v4 |= 1u;
        `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard' = v4;
        `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_5A7EFC = -1;
        dword_5A7F00 = -1;
        dword_5A7F04 = 1;
      }
      if ( v2 == -1 )
        v8 = (UtlRBTreeNode_t<sv_t *,int> *)&`CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v8 = &this->m_Elements.m_pMemory[v2];
      v9 = v8->m_Parent;
      if ( (v4 & 1) == 0 )
      {
        `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard' = v4 | 1;
        `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::s_Sentinel = -1;
        dword_5A7EFC = -1;
        dword_5A7F00 = -1;
        dword_5A7F04 = 1;
      }
      if ( v9 == -1 )
        v10 = (UtlRBTreeNode_t<sv_t *,int> *)&`CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::s_Sentinel;
      else
        v10 = &this->m_Elements.m_pMemory[v9];
      v11 = v10->m_Parent;
      IsLeftChild = CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::IsLeftChild(
                      this,
                      i: v9);
      v13 = `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard';
      if ( IsLeftChild )
      {
        if ( (`CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_5A7EFC = -1;
          dword_5A7F00 = -1;
          dword_5A7F04 = 1;
        }
        if ( v11 == -1 )
          v14 = (UtlRBTreeNode_t<sv_t *,int> *)&`CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v14 = &this->m_Elements.m_pMemory[v11];
        m_Right = v14->m_Right;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_5A7EFC = -1;
          dword_5A7F00 = -1;
          dword_5A7F04 = 1;
        }
        if ( m_Right == -1 )
          v16 = (UtlRBTreeNode_t<sv_t *,int> *)&`CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v16 = &this->m_Elements.m_pMemory[m_Right];
        if ( v16->m_Tag == 0 )
          goto LABEL_61;
        if ( CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::IsRightChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::RotateLeft(
            this,
            elem: v9);
          v17 = `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v17 = `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_5A7EFC = -1;
            dword_5A7F00 = -1;
            dword_5A7F04 = 1;
          }
          if ( v9 == -1 )
            v18 = (UtlRBTreeNode_t<sv_t *,int> *)&`CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v18 = &this->m_Elements.m_pMemory[v9];
          v9 = v18->m_Parent;
          if ( (v17 & 1) == 0 )
          {
            `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard' = v17 | 1;
            `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_5A7EFC = -1;
            dword_5A7F00 = -1;
            dword_5A7F04 = 1;
          }
          if ( v9 == -1 )
            v19 = (UtlRBTreeNode_t<sv_t *,int> *)&`CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v19 = &this->m_Elements.m_pMemory[v9];
          v11 = v19->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::RotateRight(
          this,
          elem: v11);
      }
      else
      {
        if ( (`CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          v13 = `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard'
              | 1;
          `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_5A7EFC = -1;
          dword_5A7F00 = -1;
          dword_5A7F04 = 1;
        }
        if ( v11 == -1 )
          v20 = (UtlRBTreeNode_t<sv_t *,int> *)&`CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v20 = &this->m_Elements.m_pMemory[v11];
        m_Right = v20->m_Left;
        if ( (v13 & 1) == 0 )
        {
          `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard' = v13 | 1;
          `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::s_Sentinel = -1;
          dword_5A7EFC = -1;
          dword_5A7F00 = -1;
          dword_5A7F04 = 1;
        }
        if ( m_Right == -1 )
          v21 = (UtlRBTreeNode_t<sv_t *,int> *)&`CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::s_Sentinel;
        else
          v21 = &this->m_Elements.m_pMemory[m_Right];
        if ( v21->m_Tag == 0 )
        {
LABEL_61:
          this->m_Elements.m_pMemory[v9].m_Tag = 1;
          this->m_Elements.m_pMemory[m_Right].m_Tag = 1;
          this->m_Elements.m_pMemory[v11].m_Tag = 0;
          elem = v11;
          goto LABEL_75;
        }
        if ( CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::IsLeftChild(
               this,
               i: elem) )
        {
          elem = v9;
          CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::RotateRight(
            this,
            elem: v9);
          v22 = `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard';
          if ( (`CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard'
              & 1) == 0 )
          {
            v22 = `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard'
                | 1;
            `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard' |= 1u;
            `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_5A7EFC = -1;
            dword_5A7F00 = -1;
            dword_5A7F04 = 1;
          }
          if ( v9 == -1 )
            v23 = (UtlRBTreeNode_t<sv_t *,int> *)&`CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v23 = &this->m_Elements.m_pMemory[v9];
          v9 = v23->m_Parent;
          if ( (v22 & 1) == 0 )
          {
            `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::`local static guard' = v22 | 1;
            `CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::s_Sentinel = -1;
            dword_5A7EFC = -1;
            dword_5A7F00 = -1;
            dword_5A7F04 = 1;
          }
          if ( v9 == -1 )
            v24 = (UtlRBTreeNode_t<sv_t *,int> *)&`CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::Links'::`2'::s_Sentinel;
          else
            v24 = &this->m_Elements.m_pMemory[v9];
          v11 = v24->m_Parent;
        }
        this->m_Elements.m_pMemory[v9].m_Tag = 1;
        this->m_Elements.m_pMemory[v11].m_Tag = 0;
        CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::RotateLeft(
          this,
          elem: v11);
      }
LABEL_75:
      if ( elem == this->m_Root )
        break;
      v2 = elem;
    }
  }
  this->m_Elements.m_pMemory[this->m_Root].m_Tag = 1;
}

//------------------------------------------------------------------------------
// Address: 0x00405A70
// Name: public: virtual void CMasterThread::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterThread::Shutdown(CMasterThread *this)
{
  int i; // ebx
  QueuedPacket_t *v3; // esi
  bool v4; // sf

  if ( CThread::IsAlive(this) )
  {
    this->m_bThreadShouldExit = true;
    CThread::Join(this, a2: 0xFFFFFFFF);
    for ( i = 0; i < this->m_Packets.m_Size; ++i )
    {
      v3 = this->m_Packets.m_Memory.m_pMemory[i];
      if ( v3 != nullptr )
      {
        v4 = v3->m_Data.m_Memory.m_nGrowSize < 0;
        v3->m_Data.m_nActualLength = 0;
        if ( !v4 )
        {
          if ( v3->m_Data.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Data.m_Memory.m_pMemory);
            v3->m_Data.m_Memory.m_pMemory = nullptr;
          }
          v3->m_Data.m_Memory.m_nAllocationCount = 0;
        }
        QueuedPacket_t::operator delete(p: v3);
      }
    }
    v4 = this->m_Packets.m_Memory.m_nGrowSize < 0;
    this->m_Packets.m_Size = 0;
    if ( !v4 )
    {
      if ( this->m_Packets.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Packets.m_Memory.m_pMemory);
        this->m_Packets.m_Memory.m_pMemory = nullptr;
      }
      this->m_Packets.m_Memory.m_nAllocationCount = 0;
    }
    this->m_Packets.m_pElements = this->m_Packets.m_Memory.m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405B30
// Name: private: virtual int CMasterThread::Run(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMasterThread::Run(CMasterThread *this)
{
  CMasterThread *v1; // esi
  volatile bool m_bThreadShouldExit; // al
  unsigned int m_ListenSocket; // ecx
  int v4; // eax
  int v5; // edi
  DWORD CurrentThreadId; // ecx
  CUtlBinaryBlock *v8; // eax
  bool v9; // zf
  int m_Size; // edi
  int m_nAllocationCount; // eax
  QueuedPacket_t **m_pMemory; // ecx
  int v16; // eax
  CUtlBinaryBlock **v17; // edi
  sockaddr_in sa; // [esp+Ch] [ebp-24h] BYREF
  timeval tv; // [esp+1Ch] [ebp-14h] BYREF
  CMasterThread *v20; // [esp+28h] [ebp-8h]
  int fromlen; // [esp+2Ch] [ebp-4h] BYREF

  v1 = this;
  m_bThreadShouldExit = this->m_bThreadShouldExit;
  v20 = this;
  fromlen = 16;
  if ( m_bThreadShouldExit )
    return 1;
  while ( 1 )
  {
    m_ListenSocket = v1->m_ListenSocket;
    v1->m_fdset.fd_count = 0;
    v1->m_fdset.fd_array[0] = m_ListenSocket;
    ++v1->m_fdset.fd_count;
    tv.tv_sec = 0;
    tv.tv_usec = 10000;
    if ( select(nfds: 0, readfds: &v1->m_fdset, writefds: nullptr, exceptfds: nullptr, timeout: &tv) == -1 )
      break;
    do
    {
      while ( 1 )
      {
        v4 = recvfrom(
               s: v1->m_ListenSocket,
               buf: (char *)v1->m_IncomingData,
               len: 4000,
               flags: 0,
               from: (struct sockaddr *)&sa,
               &fromlen);
        v5 = v4;
        if ( v4 == -1 )
          break;
        if ( v4 > 0 )
        {
          CurrentThreadId = GetCurrentThreadId();
          if ( CurrentThreadId != QueuedPacket_t::s_Allocator.m_mutex.m_ownerID
            && _InterlockedCompareExchange(
                 (volatile signed __int32 *)&QueuedPacket_t::s_Allocator.m_mutex,
                 CurrentThreadId,
                 0) != 0 )
          {
            _mm_pause();
            CThreadFastMutex::Lock(a1: &QueuedPacket_t::s_Allocator.m_mutex, a2: CurrentThreadId, a3: 0);
          }
          else
          {
            ++QueuedPacket_t::s_Allocator.m_mutex.m_depth;
          }
          v8 = (CUtlBinaryBlock *)CUtlMemoryPool::Alloc(this: &QueuedPacket_t::s_Allocator, amount: 0x20u);
          v9 = QueuedPacket_t::s_Allocator.m_mutex.m_depth-- == 1;
          _EBX = v8;
          if ( v9 )
            _InterlockedExchange((volatile __int32 *)&QueuedPacket_t::s_Allocator.m_mutex, 0);
          if ( v8 != nullptr )
            CUtlBinaryBlock::CUtlBinaryBlock(this: v8 + 1, growSize: 0, initSize: 0);
          else
            _EBX = nullptr;
          __asm
          {
            movq    xmm0, qword ptr [ebp+sa.sin_family]
            movq    qword ptr [ebx], xmm0
            movq    xmm0, qword ptr [ebp+sa.sin_zero]
          }
          __asm { movq    qword ptr [ebx+8], xmm0 }
          CUtlBinaryBlock::Set(this: _EBX + 1, pValue: v1->m_IncomingData, nLen: v5);
          EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&v1->m_PacketsCS);
          m_Size = v1->m_Packets.m_Size;
          m_nAllocationCount = v1->m_Packets.m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>::Grow(
              this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&v1->m_Packets,
              num: m_Size - m_nAllocationCount + 1);
          ++v1->m_Packets.m_Size;
          m_pMemory = v1->m_Packets.m_Memory.m_pMemory;
          v16 = v1->m_Packets.m_Size - m_Size - 1;
          v1->m_Packets.m_pElements = m_pMemory;
          if ( v16 > 0 )
            _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v16);
          v17 = (CUtlBinaryBlock **)&v1->m_Packets.m_Memory.m_pMemory[m_Size];
          if ( v17 != nullptr )
            *v17 = _EBX;
          LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&v20->m_PacketsCS);
          v1 = v20;
        }
      }
    }
    while ( WSAGetLastError() != 10035 );
    if ( v1->m_bThreadShouldExit )
      return 1;
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00405D00
// Name: public: virtual void CReportingThread::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CReportingThread::Shutdown(CReportingThread *this)
{
  int i; // edi

  if ( CThread::IsAlive(this) )
  {
    this->m_bThreadShouldExit = true;
    CThread::Join(this, a2: 0xFFFFFFFF);
    for ( i = 0; i < this->m_ReportData.m_Size; ++i )
      KeyValues::deleteThis(this: this->m_ReportData.m_Memory.m_pMemory[i]);
    this->m_ReportData.m_Size = 0;
    if ( this->m_ReportData.m_Memory.m_nGrowSize >= 0 )
    {
      if ( this->m_ReportData.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_ReportData.m_Memory.m_pMemory);
        this->m_ReportData.m_Memory.m_pMemory = nullptr;
      }
      this->m_ReportData.m_Memory.m_nAllocationCount = 0;
    }
    this->m_ReportData.m_pElements = this->m_ReportData.m_Memory.m_pMemory;
    if ( this->m_bMySqlConnected )
    {
      mysql_close(a1: &this->m_mysql);
      memset(dst: (unsigned __int8 *)&this->m_mysql, value: 0, count: sizeof(this->m_mysql));
      this->m_bMySqlConnected = false;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405DA0
// Name: public: bool CUtlMap<struct sockaddr_in,struct xlspTitleServer_t,int>::IsValidIndex(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlMap<sockaddr_in,xlspTitleServer_t,int>::IsValidIndex(
        CUtlMap<sockaddr_in,xlspTitleServer_t,int> *this,
        int i)
{
  return i >= 0
      && i < this->m_Tree.m_Elements.m_nAllocationCount
      && i <= this->m_Tree.m_LastAlloc.index
      && CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::LeftChild(
           this: &this->m_Tree,
           i) != i;
}

//------------------------------------------------------------------------------
// Address: 0x00405DD0
// Name: public: int CUtlMap<struct sockaddr_in,struct xlspTitleServer_t,int>::Find(struct sockaddr_in const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Find(
        CUtlMap<sockaddr_in,xlspTitleServer_t,int> *this,
        const sockaddr_in *key)
{
  CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t dummyNode; // [esp+0h] [ebp-54h] BYREF

  _EAX = key;
  __asm
  {
    movq    xmm0, qword ptr [eax]
    movq    qword ptr [ebp+dummyNode.key.sin_family], xmm0
    movq    xmm0, qword ptr [eax+8]
  }
  __asm { movq    qword ptr [ebp+dummyNode.key.sin_zero], xmm0 }
  return CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Find(
           this: &this->m_Tree,
           search: &dummyNode);
}

//------------------------------------------------------------------------------
// Address: 0x00405E00
// Name: protected: void CUtlRBTree<struct CUtlMap<struct sockaddr_in,struct xlspTitleServer_t,int>::Node_t,int,class CUtlMap<struct sockaddr_in,struct xlspTitleServer_t,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<struct sockaddr_in,struct xlspTitleServer_t,int>::Node_t,int>,int>>::LinkToParent(int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::LinkToParent(
        CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int> > *this,
        int i,
        int parent,
        bool isLeft)
{
  UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int> *v4; // eax
  UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int> *m_pMemory; // eax
  int v6; // edx

  v4 = &this->m_Elements.m_pMemory[i];
  v4->m_Parent = parent;
  v4->m_Right = -1;
  v4->m_Left = -1;
  v4->m_Tag = 0;
  if ( parent == -1 )
  {
    this->m_Root = i;
    CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::InsertRebalance(
      this,
      elem: i);
  }
  else
  {
    m_pMemory = this->m_Elements.m_pMemory;
    v6 = parent;
    if ( isLeft )
      m_pMemory[v6].m_Left = i;
    else
      m_pMemory[v6].m_Right = i;
    CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::InsertRebalance(
      this,
      elem: i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405E70
// Name: public: void CUtlBuffer::PutUnsignedChar(unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutUnsignedChar(CUtlBuffer *this, unsigned __int8 c)
{
  if ( (this->m_Flags & 1) != 0 )
  {
    CUtlBuffer::Printf(this, pFmt: "%hu", c);
  }
  else if ( CUtlBuffer::CheckPut(this, nSize: 1) )
  {
    this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = c;
    CUtlBuffer::AddNullTermination(this, nPut: ++this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405EC0
// Name: void GetGlobalPatch_Init(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall GetGlobalPatch_Init(__int128 a1@<xmm0>)
{
  int i; // esi
  int v2; // eax
  int v3; // esi
  int v4; // edi
  int v5; // ebx
  int *v6; // eax
  char v7; // bl
  int m_Size; // eax
  int v9; // esi
  KeyValues **m_pMemory; // ecx
  int v11; // eax
  KeyValues **v12; // ecx
  int m_nMaxPut; // edi
  KeyValues *v14; // eax
  KeyValues *v15; // edi
  int v16; // eax
  int v17; // esi
  KeyValues **v18; // ecx
  int v19; // eax
  KeyValues **v20; // ecx
  KeyValues *v21; // eax
  KeyValues *v22; // ebx
  int v23; // eax
  int v24; // esi
  KeyValues **v25; // ecx
  int v26; // eax
  KeyValues **v27; // eax
  KeyValues *v28; // esi
  CFmtStrN<256> *v29; // eax
  KeyValues *v30; // esi
  int v31; // eax
  const unsigned __int8 *v32; // esi
  int j; // esi
  KeyValues *v34; // ecx
  KeyValues *v35; // [esp-4h] [ebp-15Ch]
  CFmtStrN<256> v36; // [esp+Ch] [ebp-14Ch] BYREF
  CUtlBuffer xlspBuffer; // [esp+118h] [ebp-40h] BYREF
  IKeyValuesDumpContext pDump; // [esp+148h] [ebp-10h] BYREF
  const unsigned __int8 *pchBytes; // [esp+14Ch] [ebp-Ch]
  int idxChunk; // [esp+150h] [ebp-8h]
  char v41; // [esp+157h] [ebp-1h]

  for ( i = 0; i < InfoChunks::g_arrPatches.m_Size; ++i )
    KeyValues::deleteThis(this: InfoChunks::g_arrPatches.m_Memory.m_pMemory[i]);
  InfoChunks::g_arrPatches.m_Size = 0;
  CUtlBuffer::CUtlBuffer(this: &xlspBuffer, growSize: 0, initSize: 0, nFlags: 0);
  v41 = 1;
  v2 = _open(path: g_szCenterPatchFile, oflag: 0x8000, pmode: 0);
  v3 = v2;
  if ( v2 == -1 )
    goto LABEL_8;
  _lseek(fh: v2, pos: 0, mthd: 2);
  v4 = _tell(filedes: v3);
  _lseek(fh: v3, pos: 0, mthd: 0);
  CUtlBuffer::EnsureCapacity(this: &xlspBuffer, num: v4);
  CUtlBuffer::SeekPut(this: &xlspBuffer, type: SEEK_CURRENT, offset: v4);
  v5 = _read(fh: v3, buf: xlspBuffer.m_Memory.m_pMemory, cnt: v4);
  if ( v5 == v4 )
  {
    v7 = v41;
  }
  else
  {
    v6 = _errno();
    _Warning(a1: "ReadFileToBuffer(): read failure %d, errno=%d\n", v5, *v6);
    v7 = 0;
  }
  CUtlBuffer::SetBufferType(this: &xlspBuffer, bIsText: false, bContainsCRLF: false);
  _close(fh: v3);
  if ( v7 == 0 )
  {
LABEL_8:
    _Error(a1: "XLSPMaster: GetGlobalPatch_Init failed to load file '%s'", g_szCenterPatchFile);
LABEL_9:
    if ( xlspBuffer.m_Memory.m_nGrowSize >= 0 && xlspBuffer.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: xlspBuffer.m_Memory.m_pMemory);
    return;
  }
  m_Size = InfoChunks::g_arrPatches.m_Size;
  v9 = InfoChunks::g_arrPatches.m_Size;
  if ( InfoChunks::g_arrPatches.m_Size + 1 > InfoChunks::g_arrPatches.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&InfoChunks::g_arrPatches,
      num: InfoChunks::g_arrPatches.m_Size - InfoChunks::g_arrPatches.m_Memory.m_nAllocationCount + 1);
    m_Size = InfoChunks::g_arrPatches.m_Size;
  }
  m_pMemory = InfoChunks::g_arrPatches.m_Memory.m_pMemory;
  InfoChunks::g_arrPatches.m_Size = m_Size + 1;
  v11 = m_Size - v9;
  InfoChunks::g_arrPatches.m_pElements = InfoChunks::g_arrPatches.m_Memory.m_pMemory;
  if ( v11 > 0 )
  {
    _V_memmove(
      dest: &InfoChunks::g_arrPatches.m_Memory.m_pMemory[v9 + 1],
      src: &InfoChunks::g_arrPatches.m_Memory.m_pMemory[v9],
      count: 4 * v11);
    m_pMemory = InfoChunks::g_arrPatches.m_Memory.m_pMemory;
  }
  v12 = &m_pMemory[v9];
  if ( v12 != nullptr )
    *v12 = nullptr;
  m_nMaxPut = xlspBuffer.m_nMaxPut;
  if ( xlspBuffer.m_nMaxPut <= 0 )
  {
    v14 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v14 != nullptr )
      v15 = KeyValues::KeyValues(this: v14, setName: "patch", firstKey: "size", firstValue: 0);
    else
      v15 = nullptr;
    v16 = InfoChunks::g_arrPatches.m_Size;
    v17 = InfoChunks::g_arrPatches.m_Size;
    if ( InfoChunks::g_arrPatches.m_Size + 1 > InfoChunks::g_arrPatches.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>::Grow(
        this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&InfoChunks::g_arrPatches,
        num: InfoChunks::g_arrPatches.m_Size - InfoChunks::g_arrPatches.m_Memory.m_nAllocationCount + 1);
      v16 = InfoChunks::g_arrPatches.m_Size;
    }
    v18 = InfoChunks::g_arrPatches.m_Memory.m_pMemory;
    InfoChunks::g_arrPatches.m_Size = v16 + 1;
    v19 = v16 - v17;
    InfoChunks::g_arrPatches.m_pElements = InfoChunks::g_arrPatches.m_Memory.m_pMemory;
    if ( v19 > 0 )
    {
      _V_memmove(
        dest: &InfoChunks::g_arrPatches.m_Memory.m_pMemory[v17 + 1],
        src: &InfoChunks::g_arrPatches.m_Memory.m_pMemory[v17],
        count: 4 * v19);
      v18 = InfoChunks::g_arrPatches.m_Memory.m_pMemory;
    }
    v20 = &v18[v17];
    if ( v20 != nullptr )
      *v20 = v15;
    goto LABEL_9;
  }
  idxChunk = 1;
  pchBytes = xlspBuffer.m_Memory.m_pMemory;
  do
  {
    v21 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v21 != nullptr )
      v22 = KeyValues::KeyValues(this: v21, setName: "patch");
    else
      v22 = nullptr;
    v23 = InfoChunks::g_arrPatches.m_Size;
    v24 = InfoChunks::g_arrPatches.m_Size;
    if ( InfoChunks::g_arrPatches.m_Size + 1 > InfoChunks::g_arrPatches.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>::Grow(
        this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&InfoChunks::g_arrPatches,
        num: InfoChunks::g_arrPatches.m_Size - InfoChunks::g_arrPatches.m_Memory.m_nAllocationCount + 1);
      v23 = InfoChunks::g_arrPatches.m_Size;
    }
    v25 = InfoChunks::g_arrPatches.m_Memory.m_pMemory;
    InfoChunks::g_arrPatches.m_Size = v23 + 1;
    v26 = v23 - v24;
    InfoChunks::g_arrPatches.m_pElements = InfoChunks::g_arrPatches.m_Memory.m_pMemory;
    if ( v26 > 0 )
    {
      _V_memmove(
        dest: &InfoChunks::g_arrPatches.m_Memory.m_pMemory[v24 + 1],
        src: &InfoChunks::g_arrPatches.m_Memory.m_pMemory[v24],
        count: 4 * v26);
      v25 = InfoChunks::g_arrPatches.m_Memory.m_pMemory;
    }
    v27 = &v25[v24];
    if ( v27 != nullptr )
      *v27 = v22;
    if ( idxChunk == 1 )
      KeyValues::SetInt(this: v22, keyName: "size", value: m_nMaxPut);
    v28 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v28 != nullptr )
    {
      v29 = CFmtStrN<256>::CFmtStrN<256>(this: &v36, pszFormat: "%d", idxChunk);
      v30 = KeyValues::KeyValues(this: v28, setName: v29->m_szBuf);
    }
    else
    {
      v30 = nullptr;
    }
    KeyValues::AddSubKey(this: v22, pSubkey: v30);
    v31 = m_nMaxPut;
    if ( m_nMaxPut >= 800 )
      v31 = 800;
    v35 = v30;
    v32 = pchBytes;
    EncodePatchData(_XMM0: a1, pvData: pchBytes, numBytes: v31, kv: v35);
    ++idxChunk;
    m_nMaxPut -= 800;
    pchBytes = v32 + 800;
  }
  while ( m_nMaxPut > 0 );
  for ( j = 1; j < InfoChunks::g_arrPatches.m_Size; ++j )
  {
    v34 = InfoChunks::g_arrPatches.m_Memory.m_pMemory[j];
    pDump.__vftable = (IKeyValuesDumpContext_vtbl *)&CKeyValuesDumpContextAsDevMsg::`vftable';
    pchBytes = (const unsigned __int8 *)1;
    KeyValues::Dump(this: v34, &pDump, nIndentLevel: 1);
  }
  if ( xlspBuffer.m_Memory.m_nGrowSize >= 0 && xlspBuffer.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: xlspBuffer.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00406270
// Name: class KeyValues __near * GetGlobalInfoChunk_Init(void)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__cdecl GetGlobalInfoChunk_Init()
{
  KeyValues *v0; // eax
  KeyValues *v1; // edi
  int m_Size; // eax
  int v4; // esi
  KeyValues **m_pMemory; // ecx
  int v6; // eax
  KeyValues **v7; // eax
  KeyValues *i; // edi
  int v9; // esi
  const char *Name; // eax
  int v11; // eax
  int v12; // esi
  KeyValues **v13; // ecx
  int v14; // eax
  KeyValues **v15; // eax
  int j; // esi
  KeyValues *v17; // ecx
  CUtlBuffer xlspBuffer; // [esp+8h] [ebp-3Ch] BYREF
  IKeyValuesDumpContext pDump; // [esp+38h] [ebp-Ch] BYREF
  const char *szServerSideKeys[1]; // [esp+3Ch] [ebp-8h]
  KeyValues *kv; // [esp+40h] [ebp-4h]

  if ( InfoChunks::g_arrChunks.m_Size > 0 )
    KeyValues::deleteThis(this: *InfoChunks::g_arrChunks.m_Memory.m_pMemory);
  InfoChunks::g_arrChunks.m_Size = 0;
  v0 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v0 != nullptr )
  {
    v1 = KeyValues::KeyValues(this: v0, setName: g_szXlspDataRoot);
    kv = v1;
  }
  else
  {
    kv = nullptr;
    v1 = nullptr;
  }
  CUtlBuffer::CUtlBuffer(this: &xlspBuffer, growSize: 0, initSize: 0, nFlags: 0);
  if ( !ReadFileToBuffer(pSourceName: g_szCenterChunkFile, buffer: &xlspBuffer, bText: true) )
  {
    _Error(a1: "XLSPMaster: GetGlobalInfoChunk_Init failed to load file '%s'", g_szCenterChunkFile);
LABEL_8:
    if ( xlspBuffer.m_Memory.m_nGrowSize >= 0 && xlspBuffer.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: xlspBuffer.m_Memory.m_pMemory);
    return nullptr;
  }
  if ( !KeyValues::LoadFromBuffer(
          this: v1,
          resourceName: g_szXlspDataRoot,
          buf: &xlspBuffer,
          pFileSystem: nullptr,
          pPathID: nullptr,
          pfnEvaluateSymbolProc: nullptr) )
  {
    _Error(a1: "XLSPMaster: GetGlobalInfoChunk_Init failed to load from buffer '%s'", g_szCenterChunkFile);
    goto LABEL_8;
  }
  m_Size = InfoChunks::g_arrChunks.m_Size;
  szServerSideKeys[0] = "settings";
  v4 = InfoChunks::g_arrChunks.m_Size;
  if ( InfoChunks::g_arrChunks.m_Size + 1 > InfoChunks::g_arrChunks.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>::Grow(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&InfoChunks::g_arrChunks,
      num: InfoChunks::g_arrChunks.m_Size - InfoChunks::g_arrChunks.m_Memory.m_nAllocationCount + 1);
    m_Size = InfoChunks::g_arrChunks.m_Size;
  }
  m_pMemory = InfoChunks::g_arrChunks.m_Memory.m_pMemory;
  InfoChunks::g_arrChunks.m_Size = m_Size + 1;
  v6 = m_Size - v4;
  InfoChunks::g_arrChunks.m_pElements = InfoChunks::g_arrChunks.m_Memory.m_pMemory;
  if ( v6 > 0 )
  {
    _V_memmove(
      dest: &InfoChunks::g_arrChunks.m_Memory.m_pMemory[v4 + 1],
      src: &InfoChunks::g_arrChunks.m_Memory.m_pMemory[v4],
      count: 4 * v6);
    m_pMemory = InfoChunks::g_arrChunks.m_Memory.m_pMemory;
  }
  v7 = &m_pMemory[v4];
  if ( v7 != nullptr )
    *v7 = v1;
  for ( i = KeyValues::GetFirstTrueSubKey(this: v1); i != nullptr; i = KeyValues::GetNextTrueSubKey(this: i) )
  {
    v9 = 0;
    while ( 1 )
    {
      Name = KeyValues::GetName(this: i);
      if ( _V_stricmp(s1: szServerSideKeys[v9], s2: Name) == 0 )
        break;
      if ( ++v9 != 0 )
      {
        v11 = InfoChunks::g_arrChunks.m_Size;
        v12 = InfoChunks::g_arrChunks.m_Size;
        if ( InfoChunks::g_arrChunks.m_Size + 1 > InfoChunks::g_arrChunks.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>::Grow(
            this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&InfoChunks::g_arrChunks,
            num: InfoChunks::g_arrChunks.m_Size - InfoChunks::g_arrChunks.m_Memory.m_nAllocationCount + 1);
          v11 = InfoChunks::g_arrChunks.m_Size;
        }
        v13 = InfoChunks::g_arrChunks.m_Memory.m_pMemory;
        InfoChunks::g_arrChunks.m_Size = v11 + 1;
        v14 = v11 - v12;
        InfoChunks::g_arrChunks.m_pElements = InfoChunks::g_arrChunks.m_Memory.m_pMemory;
        if ( v14 > 0 )
        {
          _V_memmove(
            dest: &InfoChunks::g_arrChunks.m_Memory.m_pMemory[v12 + 1],
            src: &InfoChunks::g_arrChunks.m_Memory.m_pMemory[v12],
            count: 4 * v14);
          v13 = InfoChunks::g_arrChunks.m_Memory.m_pMemory;
        }
        v15 = &v13[v12];
        if ( v15 != nullptr )
          *v15 = i;
        break;
      }
    }
  }
  for ( j = 0; j < InfoChunks::g_arrChunks.m_Size; ++j )
  {
    v17 = InfoChunks::g_arrChunks.m_Memory.m_pMemory[j];
    pDump.__vftable = (IKeyValuesDumpContext_vtbl *)&CKeyValuesDumpContextAsDevMsg::`vftable';
    szServerSideKeys[0] = nullptr;
    KeyValues::Dump(this: v17, &pDump, nIndentLevel: 1);
  }
  if ( xlspBuffer.m_Memory.m_nGrowSize >= 0 && xlspBuffer.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: xlspBuffer.m_Memory.m_pMemory);
  return kv;
}

//------------------------------------------------------------------------------
// Address: 0x004064B0
// Name: public: void CMasterDlg::ConfigReload(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CMasterDlg::ConfigReload(CMasterDlg *this@<ecx>, __int128 a2@<xmm0>)
{
  KeyValues *MasterData_Init; // eax
  KeyValues *v5; // edi
  KeyValues *GlobalInfoPatch_Part; // eax
  int v7; // eax
  double v12; // [esp+0h] [ebp-28h]
  int v13; // [esp+Ch] [ebp-1Ch]
  int Int; // [esp+10h] [ebp-18h]
  float flTime; // [esp+1Ch] [ebp-Ch]
  IKeyValuesDumpContext pDump; // [esp+20h] [ebp-8h] BYREF
  float flTimeEnd; // [esp+24h] [ebp-4h]

  flTime = _Plat_FloatTime();
  _Msg(a1: "Reloading configuration...\n");
  CMasterDlg::Sys_Printf(this, pMsg: "********* Reloading configuration file: %s\n", g_szCenterChunkFile);
  GetGlobalInfoChunk_Init();
  if ( CMasterDlg::Sys_ParseCommandLineArg(
         this,
         pKey: "-patchfile",
         pValueBuff: g_szCenterPatchFile,
         valueBuffSize: 260) == 0 )
    CMasterDlg::Sys_Error(this, pFormat: "-patchfile parameter is missing!");
  CMasterDlg::Sys_Printf(this, pMsg: "********* Reloading patch file: %s\n", g_szCenterPatchFile);
  GetGlobalPatch_Init(a1: a2);
  if ( InfoChunks::g_pMasterData != nullptr )
  {
    KeyValues::deleteThis(this: InfoChunks::g_pMasterData);
    InfoChunks::g_pMasterData = nullptr;
  }
  InfoChunks::g_pMasterData = GetMasterData_Init();
  pDump.__vftable = (IKeyValuesDumpContext_vtbl *)&CKeyValuesDumpContextAsDevMsg::`vftable';
  flTimeEnd = 0.0;
  KeyValues::Dump(this: InfoChunks::g_pMasterData, &pDump, nIndentLevel: 1);
  flTimeEnd = _Plat_FloatTime();
  MasterData_Init = InfoChunks::g_pMasterData;
  if ( InfoChunks::g_pMasterData == nullptr )
  {
    MasterData_Init = GetMasterData_Init();
    InfoChunks::g_pMasterData = MasterData_Init;
  }
  if ( InfoChunks::g_arrChunks.m_Size != 0 )
    v5 = *InfoChunks::g_arrChunks.m_Memory.m_pMemory;
  else
    v5 = nullptr;
  Int = KeyValues::GetInt(this: MasterData_Init, keyName: "chunks/data_patch/chunks", defaultValue: 0);
  GlobalInfoPatch_Part = GetGlobalInfoPatch_Part(idxPart: 1);
  v13 = KeyValues::GetInt(this: GlobalInfoPatch_Part, keyName: "patch/size", defaultValue: 0);
  v7 = KeyValues::GetInt(this: v5, keyName: "version", defaultValue: 0);
  __asm
  {
    movss   xmm0, [ebp+flTimeEnd]
    subss   xmm0, [ebp+flTime]
  }
  __asm
  {
    cvtps2pd xmm0, xmm0
    movsd   [esp+28h+var_28], xmm0
  }
  CMasterDlg::Sys_Printf(
    this,
    pMsg: "********* Reloaded configuration in %.3f sec: version = %d, patch size = %d bytes (%d packets)\n",
    v12,
    v7,
    v13,
    Int);
}

//------------------------------------------------------------------------------
// Address: 0x00406600
// Name: private: void CMasterDlg::Packet_GetChallenge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterDlg::Packet_GetChallenge(CMasterDlg *this)
{
  int v4; // eax
  int v5; // ebx
  unsigned int v6; // eax
  int s_b4; // edx
  int v9; // esi
  int v20; // ebx
  int v24; // edx
  int v25; // ecx
  int v26; // edx
  CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t search; // [esp+8h] [ebp-80h] BYREF
  __int64 v31; // [esp+5Ch] [ebp-2Ch]
  __int64 v33; // [esp+6Ch] [ebp-1Ch]
  int v35; // [esp+7Ch] [ebp-Ch]
  int bucket; // [esp+80h] [ebp-8h]
  int oldest; // [esp+84h] [ebp-4h]

  _EDI = this;
  __asm { movq    xmm0, qword ptr [edi+140h] }
  __asm
  {
    movq    qword ptr [ebp+search.key.sin_family], xmm0
    movq    xmm0, qword ptr [edi+148h]
  }
  __asm { movq    qword ptr [ebp+search.key.sin_zero], xmm0 }
  v4 = CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Find(
         this: &this->m_XLSPPortMapping.m_Tree,
         &search);
  if ( v4 >= 0
    && v4 < _EDI->m_XLSPPortMapping.m_Tree.m_Elements.m_nAllocationCount
    && v4 <= _EDI->m_XLSPPortMapping.m_Tree.m_LastAlloc.index
    && CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::LeftChild(
         this: &_EDI->m_XLSPPortMapping.m_Tree,
         i: v4) != v4 )
  {
    oldest = 0;
    v5 = 0x7FFFFFFF;
    v6 = _time64(timeptr: nullptr);
    srand(seed: v6);
    s_b4 = _EDI->m_packet_from.sin_addr.S_un.S_un_b.s_b4;
    __asm { movq    xmm0, qword ptr [edi+140h] }
    v9 = 0;
    __asm
    {
      movq    [ebp+var_2C], xmm0
      movq    xmm0, qword ptr [edi+148h]
    }
    bucket = s_b4;
    __asm { movq    [ebp+var_24], xmm0 }
    _EAX = &_EDI->m_Challenges[s_b4][0].time;
    do
    {
      __asm { movq    xmm0, qword ptr [eax-14h] }
      __asm
      {
        movq    [ebp+var_1C], xmm0
        movq    xmm0, qword ptr [eax-0Ch]
        movq    [ebp+var_14], xmm0
      }
      if ( HIDWORD(v31) == HIDWORD(v33) )
        break;
      if ( *_EAX < v5 )
      {
        v5 = *_EAX;
        oldest = v9;
      }
      __asm { movq    xmm0, qword ptr [eax+4] }
      __asm
      {
        movq    [ebp+var_1C], xmm0
        movq    xmm0, qword ptr [eax+0Ch]
        movq    [ebp+var_14], xmm0
      }
      if ( HIDWORD(v31) == HIDWORD(v33) )
      {
        ++v9;
        break;
      }
      if ( _EAX[6] < v5 )
      {
        v5 = _EAX[6];
        oldest = v9 + 1;
      }
      __asm { movq    xmm0, qword ptr [eax+1Ch] }
      __asm
      {
        movq    [ebp+var_1C], xmm0
        movq    xmm0, qword ptr [eax+24h]
        movq    [ebp+var_14], xmm0
      }
      if ( HIDWORD(v31) == HIDWORD(v33) )
      {
        v9 += 2;
        break;
      }
      if ( _EAX[12] < v5 )
      {
        v5 = _EAX[12];
        oldest = v9 + 2;
      }
      __asm { movq    xmm0, qword ptr [eax+34h] }
      __asm
      {
        movq    [ebp+var_1C], xmm0
        movq    xmm0, qword ptr [eax+3Ch]
        movq    [ebp+var_14], xmm0
      }
      if ( HIDWORD(v31) == HIDWORD(v33) )
      {
        v9 += 3;
        break;
      }
      if ( _EAX[18] < v5 )
      {
        v5 = _EAX[18];
        oldest = v9 + 3;
      }
      v9 += 4;
      _EAX += 24;
    }
    while ( v9 < 32 );
    if ( v9 == 32 )
    {
      v35 = rand() << 16;
      v20 = bucket;
      _ESI = (char *)_EDI + 768 * bucket + 24 * oldest;
      *((_DWORD *)_ESI + 2114) = (v35 | rand()) & 0x7FFFFFFF;
      __asm
      {
        movq    xmm0, qword ptr [edi+140h]
        movq    qword ptr [esi+20F8h], xmm0
        movq    xmm0, qword ptr [edi+148h]
        movq    qword ptr [esi+2100h], xmm0
      }
      *((_DWORD *)_ESI + 2115) = _EDI->m_curtime;
      v9 = oldest;
    }
    else
    {
      v20 = s_b4;
      v24 = 3 * (32 * s_b4 + v9);
      v25 = _EDI->m_curtime - _EDI->m_Challenges[0][v24 / 3u].time;
      bucket = (int)_EDI + 8 * v24;
      if ( v25 > 15 )
      {
        v35 = rand() << 16;
        v26 = v35 | rand();
        _EAX = bucket;
        *(_DWORD *)(bucket + 8456) = v26 & 0x7FFFFFFF;
        __asm
        {
          movq    xmm0, qword ptr [edi+140h]
          movq    qword ptr [eax+20F8h], xmm0
          movq    xmm0, qword ptr [edi+148h]
          movq    qword ptr [eax+2100h], xmm0
        }
        *(_DWORD *)(_EAX + 8460) = _EDI->m_curtime;
      }
    }
    V_snprintf(pDest: _EDI->m_Reply, maxLen: 1400, pFormat: "%c%c%c%c%c\n", 255, 255, 255, 255, 115);
    *(_DWORD *)&_EDI->m_Reply[6] = _EDI->m_Challenges[v20][v9].challenge;
    CMasterDlg::Sys_SendPacket(this: _EDI, to: &_EDI->m_packet_from, data: (unsigned __int8 *)_EDI->m_Reply, len: 0xAu);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004068C0
// Name: private: void CMasterDlg::Packet_Heartbeat2(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterDlg::Packet_Heartbeat2(CMasterDlg *this)
{
  const char *String; // eax
  char *v3; // eax
  int v4; // eax
  CFmtStrN<256> *v5; // eax
  char *v6; // eax
  int v7; // eax
  int v9; // eax
  CMasterDlg *v10; // ecx
  char *v11; // eax
  char *v12; // eax
  char *v13; // eax
  char *v14; // eax
  char *v15; // eax
  char *v16; // eax
  char *v17; // eax
  char *v18; // eax
  int v20; // eax
  int v21; // edx
  unsigned int v24; // eax
  int v25; // ebx
  BOOL v26; // edx
  int v27; // ecx
  int v28; // edx
  CFmtStrN<256> v29; // [esp+8h] [ebp-AA0h] BYREF
  char info[2048]; // [esp+114h] [ebp-994h] BYREF
  char map[128]; // [esp+914h] [ebp-194h] BYREF
  char privateKey[128]; // [esp+994h] [ebp-114h] BYREF
  char gamedir[128]; // [esp+A14h] [ebp-94h] BYREF
  int hXLSPPort; // [esp+A94h] [ebp-14h]
  int nMaxPlayers; // [esp+A98h] [ebp-10h]
  int nPlayers; // [esp+A9Ch] [ebp-Ch]
  int nBots; // [esp+AA0h] [ebp-8h]
  bool bIsReserved; // [esp+AA6h] [ebp-2h]
  bool bIsLan; // [esp+AA7h] [ebp-1h]

  ++this->m_msg_readcount;
  String = CMasterDlg::MSG_ReadString(this);
  V_strncpy(pDest: info, pSrc: String, maxLen: 2048);
  if ( info[0] == 0 )
  {
    V_snprintf(
      pDest: this->m_Reply,
      maxLen: 1400,
      pFormat: "%c%c%c%c%c\n%s\n",
      255,
      255,
      255,
      255,
      108,
      "Outdated protocol.");
    CMasterDlg::Sys_SendPacket(
      this,
      to: &this->m_packet_from,
      data: (unsigned __int8 *)this->m_Reply,
      len: strlen(this->m_Reply) + 1);
    return;
  }
  v3 = Info_ValueForKey(s: info, key: "protocol");
  v4 = atoi(nptr: v3);
  if ( v4 != 7 )
  {
    v5 = CFmtStrN<256>::CFmtStrN<256>(this: &v29, pszFormat: "Outdated protocol. Got %d, Expected %d", v4, 7);
    CMasterDlg::RejectConnection(this, adr: &this->m_packet_from, pszMessage: v5->m_szBuf);
    return;
  }
  v6 = Info_ValueForKey(s: info, key: "challenge");
  v7 = atoi(nptr: v6);
  _EBX = &this->m_packet_from;
  v9 = CMasterDlg::CheckChallenge(this, challenge: v7, adr: &this->m_packet_from) - 1;
  if ( v9 == 0 )
  {
    CMasterDlg::RejectConnection(this: v10, adr: &this->m_packet_from, pszMessage: "Bad challenge.");
    return;
  }
  if ( v9 == 1 )
  {
    CMasterDlg::RejectConnection(this: v10, adr: &this->m_packet_from, pszMessage: "No challenge for your address.");
  }
  else
  {
    v11 = Info_ValueForKey(s: info, key: "players");
    nPlayers = atoi(nptr: v11);
    v12 = Info_ValueForKey(s: info, key: "max");
    nMaxPlayers = atoi(nptr: v12);
    v13 = Info_ValueForKey(s: info, key: "bots");
    nBots = atoi(nptr: v13);
    v14 = Info_ValueForKey(s: info, key: "lan");
    bIsLan = atoi(nptr: v14) != 0;
    v15 = Info_ValueForKey(s: info, key: "reserved");
    bIsReserved = atoi(nptr: v15) != 0;
    v16 = Info_ValueForKey(s: info, key: "gamedir");
    V_strncpy(pDest: gamedir, pSrc: v16, maxLen: 128);
    _V_strlower(start: gamedir);
    v17 = Info_ValueForKey(s: info, key: "map");
    V_strncpy(pDest: map, pSrc: v17, maxLen: 128);
    _V_strlower(start: map);
    v18 = Info_ValueForKey(s: info, key: "private");
    V_strncpy(pDest: privateKey, pSrc: v18, maxLen: 128);
    _V_strlower(start: privateKey);
    _ESI = CMasterDlg::FindServerByAddress(this, address: &this->m_packet_from);
    if ( _ESI == nullptr )
    {
      hXLSPPort = CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Find(
                    this: &this->m_XLSPPortMapping,
                    key: &this->m_packet_from);
      if ( !CUtlMap<sockaddr_in,xlspTitleServer_t,int>::IsValidIndex(this: &this->m_XLSPPortMapping, i: hXLSPPort) )
        return;
      _ESI = (sv_t *)operator new(nSize: 0x914u);
      memset(dst: (unsigned __int8 *)_ESI, value: 0, count: sizeof(sv_t));
      v20 = _V_stricmp(s1: gamedir, s2: "left4dead2");
      v21 = hXLSPPort;
      _ESI->gameId = v20 == 0;
      __asm
      {
        movq    xmm0, qword ptr [ebx]
        movq    qword ptr [esi+4], xmm0
        movq    xmm0, qword ptr [ebx+8]
        movq    qword ptr [esi+0Ch], xmm0
      }
      _ESI->hXLSPPort = v21;
      _ESI->uniqueid = this->m_nUniqueID++;
      v24 = CMasterDlg::HashServer(this, address: &this->m_packet_from);
      _ESI->next = this->m_pGameServers[v24];
      this->m_pGameServers[v24] = _ESI;
    }
    v25 = 4;
    if ( _ESI->gameId != E_GAME_L4D )
      v25 = nMaxPlayers;
    SetCriteria(c: &_ESI->gamedir, value: gamedir);
    SetCriteria(c: &_ESI->map, value: map);
    SetCriteria(c: &_ESI->privateKey, value: privateKey);
    v26 = bIsLan;
    v27 = nPlayers;
    _ESI->bIsReserved = bIsReserved;
    _ESI->maxPlayers = v25;
    _ESI->islan = v26;
    v28 = nBots;
    _ESI->players = v27;
    _ESI->bots = v28;
    V_strncpy(pDest: _ESI->info, pSrc: info, maxLen: 2048);
    _ESI->info_length = strlen(_ESI->info) + 1;
    _ESI->time = this->m_curtime;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406C80
// Name: private: void CMasterDlg::ListPorts(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterDlg::ListPorts(CMasterDlg *this)
{
  int i; // esi
  int SGName; // ebx
  u_short v8; // ax
  char szAddress[64]; // [esp+8h] [ebp-50h] BYREF
  sockaddr_in address; // [esp+48h] [ebp-10h]

  CMasterDlg::Sys_Printf(this, pMsg: "\nXLSP Ports:\n");
  CMasterDlg::Sys_Printf(this, pMsg: "--------------------\n");
  for ( i = CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_XLSPPortMapping.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_XLSPPortMapping.m_Tree,
              i) )
  {
    _ECX = this->m_XLSPPortMapping.m_Tree.m_Elements.m_pMemory;
    _EAX = 100 * i;
    __asm
    {
      movq    xmm0, qword ptr [eax+this+10h]
      movq    qword ptr [ebp+address.sin_family], xmm0
    }
    __asm { movq    xmm0, qword ptr [eax+this+18h] }
    __asm { movq    qword ptr [ebp+address.sin_zero], xmm0 }
    SGName = (int)_ECX[i].m_Data.elem.SGName;
    v8 = ntohs(netshort: address.sin_port);
    V_snprintf(
      pDest: szAddress,
      maxLen: 64,
      pFormat: "%i.%i.%i.%i:%i",
      address.sin_addr.S_un.S_un_b.s_b1,
      address.sin_addr.S_un.S_un_b.s_b2,
      address.sin_addr.S_un.S_un_b.s_b3,
      address.sin_addr.S_un.S_un_b.s_b4,
      v8);
    CMasterDlg::Sys_Printf(this, pMsg: "%s:%d        %s\n", (const char *)SGName, *(_DWORD *)(SGName + 64), szAddress);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406D40
// Name: private: void CMasterDlg::KV_Respond_Cmd(class CKVCommand __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterDlg::KV_Respond_Cmd(CMasterDlg *this, CKVCommand *cmd)
{
  unsigned __int8 m_nCommand; // bl
  unsigned __int8 m_nVersion; // bl
  void *v5; // esp
  bool v6; // zf
  int m_nMaxPut; // eax
  int v8; // [esp-580h] [ebp-5ECh] BYREF
  int m_nHeader; // [esp-4h] [ebp-70h]
  CUtlBuffer bufKV; // [esp+Ch] [ebp-60h] BYREF
  CUtlBuffer buf; // [esp+3Ch] [ebp-30h] BYREF

  CUtlBuffer::CUtlBuffer(this: &buf, pBuffer: this->m_Reply, nSize: 1400, nFlags: 0);
  m_nHeader = -1;
  if ( (buf.m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: &buf, pFmt: "%u", m_nHeader);
  else
    CUtlBuffer::PutTypeBin<int>(this: &buf, src: m_nHeader);
  m_nCommand = cmd->m_nCommand;
  if ( (buf.m_Flags & 1) != 0 )
  {
    CUtlBuffer::Printf(this: &buf, pFmt: "%hu", m_nCommand);
  }
  else if ( CUtlBuffer::CheckPut(this: &buf, nSize: 1) )
  {
    buf.m_Memory.m_pMemory[buf.m_Put - buf.m_nOffset] = m_nCommand;
    CUtlBuffer::AddNullTermination(this: &buf, nPut: ++buf.m_Put);
  }
  m_nVersion = cmd->m_nVersion;
  if ( (buf.m_Flags & 1) != 0 )
  {
    CUtlBuffer::Printf(this: &buf, pFmt: "%hu", m_nVersion);
  }
  else if ( CUtlBuffer::CheckPut(this: &buf, nSize: 1) )
  {
    buf.m_Memory.m_pMemory[buf.m_Put - buf.m_nOffset] = m_nVersion;
    CUtlBuffer::AddNullTermination(this: &buf, nPut: ++buf.m_Put);
  }
  m_nHeader = cmd->m_nHeader;
  if ( (buf.m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: &buf, pFmt: "%u", m_nHeader);
  else
    CUtlBuffer::PutTypeBin<int>(this: &buf, src: m_nHeader);
  m_nHeader = cmd->m_nReplyId;
  if ( (buf.m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: &buf, pFmt: "%u", m_nHeader);
  else
    CUtlBuffer::PutTypeBin<int>(this: &buf, src: m_nHeader);
  m_nHeader = cmd->m_nChallenge;
  if ( (buf.m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: &buf, pFmt: "%u", m_nHeader);
  else
    CUtlBuffer::PutTypeBin<int>(this: &buf, src: m_nHeader);
  m_nHeader = cmd->m_nExtra;
  if ( (buf.m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: &buf, pFmt: "%u", m_nHeader);
  else
    CUtlBuffer::PutTypeBin<int>(this: &buf, src: m_nHeader);
  v5 = alloca(1408);
  CUtlBuffer::CUtlBuffer(this: &bufKV, pBuffer: &v8, nSize: 1400, nFlags: 0);
  CUtlBuffer::ActivateByteSwapping(this: &bufKV, bActivate: true);
  if ( KeyValues::WriteAsBinary(this: cmd->m_pKV, buffer: &bufKV) )
  {
    v6 = (buf.m_Flags & 1) == 0;
    m_nMaxPut = bufKV.m_nMaxPut;
    cmd->m_numBytes = bufKV.m_nMaxPut;
    if ( v6 )
      CUtlBuffer::PutTypeBin<int>(this: &buf, src: m_nMaxPut);
    else
      CUtlBuffer::Printf(this: &buf, pFmt: "%u", m_nMaxPut);
    CUtlBuffer::Put(this: &buf, pMem: bufKV.m_Memory.m_pMemory, size: cmd->m_numBytes);
    CMasterDlg::Sys_SendPacket(
      this,
      to: &this->m_packet_from,
      data: (unsigned __int8 *)this->m_Reply,
      len: buf.m_nMaxPut);
  }
  if ( bufKV.m_Memory.m_nGrowSize >= 0 )
  {
    if ( bufKV.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bufKV.m_Memory.m_pMemory);
      bufKV.m_Memory.m_pMemory = nullptr;
    }
    bufKV.m_Memory.m_nAllocationCount = 0;
  }
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00406F80
// Name: public: CReportingThread::CReportingThread(void)
// Source: json
//------------------------------------------------------------------------------
CReportingThread *__thiscall CReportingThread::CReportingThread(CReportingThread *this)
{
  KeyValues *v2; // eax

  CThread::CThread(this);
  this->__vftable = (CReportingThread_vtbl *)&CReportingThread::`vftable';
  this->m_ReportData.m_Memory.m_pMemory = nullptr;
  this->m_ReportData.m_Memory.m_nAllocationCount = 0;
  this->m_ReportData.m_Memory.m_nGrowSize = 0;
  this->m_ReportData.m_Size = 0;
  this->m_ReportData.m_pElements = nullptr;
  CThreadMutex::CThreadMutex(this: &this->m_CS);
  memset(dst: (unsigned __int8 *)&this->m_mysql, value: 0, count: sizeof(this->m_mysql));
  this->m_bMySqlConnected = false;
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    this->m_pConfig = KeyValues::KeyValues(this: v2, setName: "SqlConfig");
  else
    this->m_pConfig = nullptr;
  this->m_bThreadShouldExit = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00407000
// Name: public: virtual bool CReportingThread::IsRunning(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
bool __thiscall CReportingThread::IsRunning(CReportingThread *this)
{
  return CThread::IsAlive(this);
}

//------------------------------------------------------------------------------
// Address: 0x00407010
// Name: public: void CReportingThread::AddReportingData(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CReportingThread::AddReportingData(CReportingThread *this, KeyValues *pData)
{
  KeyValues *Copy; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  KeyValues **m_pMemory; // ecx
  int v7; // eax
  KeyValues **v8; // eax
  KeyValues *pCopy; // [esp+Ch] [ebp+8h]

  if ( this->m_bMySqlConnected )
  {
    if ( this->m_ReportData.m_Size <= 250000 )
    {
      EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_CS);
      Copy = KeyValues::MakeCopy(this: pData);
      m_Size = this->m_ReportData.m_Size;
      pCopy = Copy;
      m_nAllocationCount = this->m_ReportData.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>::Grow(
          this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&this->m_ReportData,
          num: m_Size - m_nAllocationCount + 1);
      ++this->m_ReportData.m_Size;
      m_pMemory = this->m_ReportData.m_Memory.m_pMemory;
      v7 = this->m_ReportData.m_Size - m_Size - 1;
      this->m_ReportData.m_pElements = m_pMemory;
      if ( v7 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
      v8 = &this->m_ReportData.m_Memory.m_pMemory[m_Size];
      if ( v8 != nullptr )
        *v8 = pCopy;
      LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_CS);
    }
    else
    {
      _Warning(a1: "Backlog size critical! Dropping report data!\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004070C0
// Name: public: CUtlRBTree<struct CUtlMap<struct sockaddr_in,struct xlspTitleServer_t,int>::Node_t,int,class CUtlMap<struct sockaddr_in,struct xlspTitleServer_t,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<struct sockaddr_in,struct xlspTitleServer_t,int>::Node_t,int>,int>>::~CUtlRBTree<struct CUtlMap<struct sockaddr_in,struct xlspTitleServer_t,int>::Node_t,int,class CUtlMap<struct sockaddr_in,struct xlspTitleServer_t,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<struct sockaddr_in,struct xlspTitleServer_t,int>::Node_t,int>,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>(
        CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int> > *this)
{
  CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::RemoveAll(this);
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
// Address: 0x00407120
// Name: public: CMasterDlg::~CMasterDlg(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterDlg::~CMasterDlg(CMasterDlg *this)
{
  CReportingThread *m_chReportingGameStats; // edi
  char *v2; // esi
  KeyValues *v3; // ecx
  void *v4; // eax
  int v6; // [esp+10h] [ebp-4h]

  m_chReportingGameStats = (CReportingThread *)this->m_chReportingGameStats;
  v6 = 14;
  v2 = &this->m_chReportingGameStats[1][48];
  do
  {
    --m_chReportingGameStats;
    v2 -= 1144;
    m_chReportingGameStats->__vftable = (CReportingThread_vtbl *)&CReportingThread::`vftable';
    CReportingThread::Shutdown(this: m_chReportingGameStats);
    v3 = *((KeyValues **)v2 + 255);
    if ( v3 != nullptr )
      KeyValues::deleteThis(this: v3);
    CThreadMutex::~CThreadMutex(this: (CThreadMutex *)(v2 + 12));
    *((_DWORD *)v2 + 1) = 0;
    if ( *(int *)v2 >= 0 )
    {
      if ( *((_DWORD *)v2 - 2) != 0 )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v2 - 2));
        *((_DWORD *)v2 - 2) = 0;
      }
      *((_DWORD *)v2 - 1) = 0;
    }
    v4 = *((void **)v2 - 2);
    *((_DWORD *)v2 + 2) = v4;
    if ( *(int *)v2 >= 0 )
    {
      if ( v4 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
        *((_DWORD *)v2 - 2) = 0;
      }
      *((_DWORD *)v2 - 1) = 0;
    }
    CThread::~CThread(this: m_chReportingGameStats);
    --v6;
  }
  while ( v6 >= 0 );
  this->m_MasterThread.__vftable = (CMasterThread_vtbl *)&CMasterThread::`vftable';
  CMasterThread::Shutdown(this: &this->m_MasterThread);
  CThreadMutex::~CThreadMutex(this: &this->m_MasterThread.m_PacketsCS);
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&this->m_MasterThread.m_Packets);
  CThread::~CThread(this: &this->m_MasterThread);
  this->m_strLocalIPAddress.m_Storage.m_nActualLength = 0;
  if ( this->m_strLocalIPAddress.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_strLocalIPAddress.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_strLocalIPAddress.m_Storage.m_Memory.m_pMemory);
      this->m_strLocalIPAddress.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_strLocalIPAddress.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>(this: &this->m_XLSPPortMapping.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x00407250
// Name: private: void CMasterDlg::KV_Cmd_X360_to_Master_1(class CKVCommand __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMasterDlg::KV_Cmd_X360_to_Master_1(CMasterDlg *this@<ecx>, __int128 _XMM0@<xmm0>, CKVCommand *cmd)
{
  CKVCommand *v3; // ebx
  CMasterDlg *v4; // edi
  const char *Name; // esi
  KeyValues *i; // esi
  const char *v7; // edi
  KeyValues *v8; // ecx
  KeyValues *Key; // eax
  int v11; // ecx
  KeyValues *v13; // ecx
  KeyValues *v15; // eax
  KeyValues *j; // esi
  const char *v18; // edi
  KeyValues *v20; // ecx
  KeyValues *v21; // eax
  int v22; // ecx
  KeyValues *v25; // ecx
  int Int; // esi
  int v27; // eax
  KeyValues *v28; // ecx
  int v29; // esi
  int v30; // eax
  const char *v31; // eax
  int v32; // esi
  const char *v33; // edi
  int defaultValue; // [esp+0h] [ebp-18h]
  float defaultValuea; // [esp+0h] [ebp-18h]
  KeyValues *defaultValueb; // [esp+0h] [ebp-18h]
  float defaultValuec; // [esp+0h] [ebp-18h]
  int defaultValued; // [esp+0h] [ebp-18h]
  float defaultValuee; // [esp+0h] [ebp-18h]
  float flValue; // [esp+10h] [ebp-8h]
  float flValuea; // [esp+10h] [ebp-8h]
  const char *szGameStat; // [esp+20h] [ebp+8h]
  float szGameStata; // [esp+20h] [ebp+8h]
  const char *szGameStatb; // [esp+20h] [ebp+8h]

  v3 = cmd;
  v4 = this;
  Name = KeyValues::GetName(this: cmd->m_pKV);
  if ( _V_stricmp(s1: Name, s2: "stat_agg") == 0 )
  {
    for ( i = KeyValues::GetFirstValue(this: cmd->m_pKV); i != nullptr; i = KeyValues::GetNextValue(this: i) )
    {
      if ( KeyValues::GetDataType(this: i, keyName: nullptr) == TYPE_INT )
      {
        v7 = KeyValues::GetName(this: i);
        szGameStat = (const char *)KeyValues::GetInt(this: i, keyName: nullptr, defaultValue: 0);
        if ( InfoChunks::g_arrChunks.m_Size != 0 )
          v8 = *InfoChunks::g_arrChunks.m_Memory.m_pMemory;
        else
          v8 = nullptr;
        Key = KeyValues::FindKey(this: v8, keyName: "stat", bCreate: false);
        __asm { movd    xmm0, [ebp+szGameStat] }
        defaultValue = v11;
        __asm
        {
          cvtdq2ps xmm0, xmm0
          movss   [esp+18h+defaultValue], xmm0; defaultValue
        }
        __asm { movss   [ebp+flValue], xmm0 }
        szGameStata = KeyValues::GetFloat(this: Key, keyName: v7, defaultValue: defaultValuea) * 0.89999998
                    + flValue * 0.1;
        if ( InfoChunks::g_arrChunks.m_Size != 0 )
          v13 = *InfoChunks::g_arrChunks.m_Memory.m_pMemory;
        else
          v13 = nullptr;
        __asm { movss   xmm0, [ebp+szGameStat] }
        defaultValueb = v13;
        __asm { movss   [esp+18h+defaultValue], xmm0; value }
        v15 = KeyValues::FindKey(this: v13, keyName: "stat", bCreate: false);
        KeyValues::SetFloat(this: v15, keyName: v7, value: defaultValuec);
        __asm { cvttss2si edx, [ebp+szGameStat] }
        KeyValues::SetInt(this: i, keyName: nullptr, value: _EDX);
        v4 = this;
      }
    }
LABEL_47:
    v3->m_nHeader = 827862349;
    CMasterDlg::KV_Respond_Cmd(this: v4, cmd: v3);
    return;
  }
  if ( _V_stricmp(s1: Name, s2: "stat_query") == 0 )
  {
    for ( j = KeyValues::GetFirstValue(this: cmd->m_pKV); j != nullptr; j = KeyValues::GetNextValue(this: j) )
    {
      if ( KeyValues::GetDataType(this: j, keyName: nullptr) == TYPE_INT )
      {
        v18 = KeyValues::GetName(this: j);
        _EBX = KeyValues::GetInt(this: j, keyName: nullptr, defaultValue: 0);
        if ( InfoChunks::g_arrChunks.m_Size != 0 )
          v20 = *InfoChunks::g_arrChunks.m_Memory.m_pMemory;
        else
          v20 = nullptr;
        v21 = KeyValues::FindKey(this: v20, keyName: "stat", bCreate: false);
        defaultValued = v22;
        __asm
        {
          xorps   xmm0, xmm0
          cvtsi2ss xmm0, ebx
          movss   [esp+18h+defaultValue], xmm0; defaultValue
        }
        flValuea = KeyValues::GetFloat(this: v21, keyName: v18, defaultValue: defaultValuee);
        __asm { cvttss2si this, [ebp+flValue] }
        KeyValues::SetInt(this: j, keyName: nullptr, value: _ECX);
        v3 = cmd;
        v4 = this;
      }
    }
    goto LABEL_47;
  }
  if ( _V_stricmp(s1: Name, s2: "data_chunk") == 0 )
  {
    if ( InfoChunks::g_arrChunks.m_Size != 0 )
      v25 = *InfoChunks::g_arrChunks.m_Memory.m_pMemory;
    else
      v25 = nullptr;
    Int = KeyValues::GetInt(this: v25, keyName: "version", defaultValue: 0);
    if ( KeyValues::GetInt(this: cmd->m_pKV, keyName: "version", defaultValue: 0) == Int )
    {
      v27 = KeyValues::GetInt(this: cmd->m_pKV, keyName: "chunk", defaultValue: 0);
      cmd->m_pKV = GetGlobalInfoChunk_Part(idxPart: v27);
      goto LABEL_47;
    }
    return;
  }
  if ( _V_stricmp(s1: Name, s2: "data_patch") == 0 )
  {
    if ( InfoChunks::g_arrChunks.m_Size != 0 )
      v28 = *InfoChunks::g_arrChunks.m_Memory.m_pMemory;
    else
      v28 = nullptr;
    v29 = KeyValues::GetInt(this: v28, keyName: "version", defaultValue: 0);
    if ( KeyValues::GetInt(this: cmd->m_pKV, keyName: "version", defaultValue: 0) == v29 )
    {
      v30 = KeyValues::GetInt(this: cmd->m_pKV, keyName: "chunk", defaultValue: 0);
      cmd->m_pKV = GetGlobalInfoPatch_Part(idxPart: v30);
      goto LABEL_47;
    }
    return;
  }
  if ( _V_stricmp(s1: Name, s2: "datarequest") == 0 )
  {
    CReportingThread::AddReportingData(this: v4->m_ReportingThreads, pData: cmd->m_pKV);
    cmd->m_pKV = GetMasterData();
    goto LABEL_47;
  }
  if ( _V_stricmp(s1: Name, s2: "vote") == 0 )
  {
    CReportingThread::AddReportingData(this: &v4->m_ReportingThreads[1], pData: cmd->m_pKV);
    goto LABEL_47;
  }
  v31 = StringAfterPrefix(str: Name, prefix: "gamestat_");
  szGameStatb = v31;
  if ( v31 != nullptr )
  {
    v32 = 0;
    v33 = v4->m_chReportingGameStats[0];
    do
    {
      if ( *v33 != 0 )
      {
        if ( _V_stricmp(s1: v31, s2: v33) == 0 )
        {
          v4 = this;
          if ( this->m_chReportingGameStats[v32][0] != 0 )
          {
            CReportingThread::AddReportingData(this: &this->m_ReportingThreads[v32 + 2], pData: v3->m_pKV);
            goto LABEL_47;
          }
          return;
        }
        v31 = szGameStatb;
      }
      ++v32;
      v33 += 64;
    }
    while ( v32 < 13 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407600
// Name: public: void CMasterThread::GetQueuedPackets(class CUtlVector<struct QueuedPacket_t __near *,class CUtlMemory<struct QueuedPacket_t __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterThread::GetQueuedPackets(
        CMasterThread *this,
        CUtlVector<QueuedPacket_t *,CUtlMemory<QueuedPacket_t *,int> > *list)
{
  int m_Size; // esi
  int i; // eax
  _RTL_CRITICAL_SECTION *lpCriticalSection; // [esp+Ch] [ebp-8h]
  QueuedPacket_t **m_pMemory; // [esp+10h] [ebp-4h]

  lpCriticalSection = (_RTL_CRITICAL_SECTION *)&this->m_PacketsCS;
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&this->m_PacketsCS);
  m_Size = this->m_Packets.m_Size;
  m_pMemory = this->m_Packets.m_Memory.m_pMemory;
  list->m_Size = 0;
  CUtlVector<QueuedPacket_t *,CUtlMemory<QueuedPacket_t *,int>>::InsertMultipleBefore(this: list, elem: 0, num: m_Size);
  for ( i = 0; i < m_Size; ++i )
    list->m_Memory.m_pMemory[i] = m_pMemory[i];
  this->m_Packets.m_Size = 0;
  LeaveCriticalSection(lpCriticalSection);
}

//------------------------------------------------------------------------------
// Address: 0x004076C0
// Name: public: int CUtlRBTree<struct CUtlMap<struct sockaddr_in,struct xlspTitleServer_t,int>::Node_t,int,class CUtlMap<struct sockaddr_in,struct xlspTitleServer_t,int>::CKeyLess,class CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<struct sockaddr_in,struct xlspTitleServer_t,int>::Node_t,int>,int>>::Insert(struct CUtlMap<struct sockaddr_in,struct xlspTitleServer_t,int>::Node_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Insert(
        CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int> > *this,
        const CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t *insert)
{
  int v4; // ebx
  UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int> *m_pMemory; // edx
  int parent; // [esp+Ch] [ebp-8h] BYREF
  BOOL leftchild; // [esp+10h] [ebp-4h] BYREF

  _EDI = insert;
  parent = -1;
  LOBYTE(leftchild) = 0;
  CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::FindInsertionPosition(
    this,
    insert,
    &parent,
    (bool *)&leftchild);
  v4 = CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::NewNode(this);
  CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::LinkToParent(
    this,
    i: v4,
    parent,
    isLeft: leftchild);
  m_pMemory = this->m_Elements.m_pMemory;
  ++this->m_NumElements;
  _EAX = (int)&m_pMemory[v4].m_Data;
  if ( &m_pMemory[v4] != (UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int> *)-16 )
  {
    __asm
    {
      movq    xmm0, qword ptr [edi]
      movq    qword ptr [eax], xmm0
      movq    xmm0, qword ptr [edi+8]
    }
    __asm { movq    qword ptr [eax+8], xmm0 }
    qmemcpy(&m_pMemory[v4].m_Data.elem, &insert->elem, sizeof(m_pMemory[v4].m_Data.elem));
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00407740
// Name: private: void CMasterDlg::Packet_KV_Cmd(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CMasterDlg::Packet_KV_Cmd(CMasterDlg *this@<ecx>, __int128 _XMM0@<xmm0>)
{
  int m_msg_readcount; // eax
  int v4; // ecx
  int v6; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // edi
  int v17; // eax
  KeyValues *v18; // eax
  KeyValues *v19; // edi
  CUtlBuffer buf; // [esp+4h] [ebp-54h] BYREF
  CKVCommand cmd; // [esp+34h] [ebp-24h] BYREF
  int v22; // [esp+54h] [ebp-4h]

  m_msg_readcount = this->m_msg_readcount;
  v4 = this->m_PacketData[m_msg_readcount];
  __asm { pxor    xmm0, xmm0 }
  v6 = m_msg_readcount + 1;
  __asm
  {
    movq    qword ptr [ebp+cmd.m_nCommand], xmm0
    movq    qword ptr [ebp+cmd.m_nHeader], xmm0
    movq    qword ptr [ebp+cmd.m_nChallenge], xmm0
    movq    qword ptr [ebp+cmd.m_numBytes], xmm0
  }
  cmd.m_nCommand = 63;
  cmd.m_nVersion = v4;
  this->m_msg_readcount = v6;
  if ( v4 == 1 )
  {
    if ( v6 < this->m_packet_length )
    {
      this->m_msg_readcount = v6 + 4;
      v8 = *(_DWORD *)&this->m_PacketData[v6];
    }
    else
    {
      CMasterDlg::Sys_Printf(this, pMsg: "Overflow reading int\n");
      v8 = -1;
    }
    v22 = v8;
    cmd.m_nHeader = v8;
    v9 = this->m_msg_readcount;
    if ( v9 < this->m_packet_length )
    {
      this->m_msg_readcount = v9 + 4;
      v10 = *(_DWORD *)&this->m_PacketData[v9];
    }
    else
    {
      CMasterDlg::Sys_Printf(this, pMsg: "Overflow reading int\n");
      v10 = -1;
    }
    cmd.m_nReplyId = v10;
    v11 = this->m_msg_readcount;
    if ( v11 < this->m_packet_length )
    {
      this->m_msg_readcount = v11 + 4;
      v12 = *(_DWORD *)&this->m_PacketData[v11];
    }
    else
    {
      CMasterDlg::Sys_Printf(this, pMsg: "Overflow reading int\n");
      v12 = -1;
    }
    cmd.m_nChallenge = v12;
    v13 = this->m_msg_readcount;
    if ( v13 < this->m_packet_length )
    {
      this->m_msg_readcount = v13 + 4;
      v14 = *(_DWORD *)&this->m_PacketData[v13];
    }
    else
    {
      CMasterDlg::Sys_Printf(this, pMsg: "Overflow reading int\n");
      v14 = -1;
    }
    cmd.m_nExtra = v14;
    v15 = this->m_msg_readcount;
    if ( v15 < this->m_packet_length )
    {
      this->m_msg_readcount = v15 + 4;
      v16 = *(_DWORD *)&this->m_PacketData[v15];
    }
    else
    {
      CMasterDlg::Sys_Printf(this, pMsg: "Overflow reading int\n");
      v16 = -1;
    }
    v17 = this->m_msg_readcount;
    cmd.m_numBytes = v16;
    if ( v17 + v16 <= this->m_packet_length )
    {
      CUtlBuffer::CUtlBuffer(this: &buf, pBuffer: &this->m_PacketData[v17], nSize: v16, nFlags: 8);
      CUtlBuffer::ActivateByteSwapping(this: &buf, bActivate: true);
      this->m_msg_readcount += v16;
      v18 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v18 != nullptr )
        v19 = KeyValues::KeyValues(this: v18, setName: defaultValue);
      else
        v19 = nullptr;
      cmd.m_pKV = v19;
      if ( v19 != nullptr )
      {
        if ( KeyValues::ReadAsBinary(this: v19, buffer: &buf) && v22 == 827141464 )
          CMasterDlg::KV_Cmd_X360_to_Master_1(this, _XMM0, &cmd);
        KeyValues::deleteThis(this: v19);
        CUtlBuffer::~CUtlBuffer(this: &buf);
      }
      else if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407950
// Name: private: void CMasterDlg::Packet_BatchResponder(int,int,struct search_criteria_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterDlg::Packet_BatchResponder(
        CMasterDlg *this,
        int truenextid,
        unsigned int challenge,
        search_criteria_t *pCriteria)
{
  bool v4; // bl
  CMasterDlg *v5; // edi
  int v6; // eax
  sv_t *v7; // esi
  int v8; // eax
  UtlRBTreeNode_t<sv_t *,int> *m_pMemory; // ecx
  int v10; // edx
  int v11; // esi
  int v12; // edx
  int v13; // ebx
  int SGName; // edi
  int v15; // esi
  unsigned int v16; // esi
  unsigned int info_length; // edi
  int v18; // esi
  int v19; // eax
  int v20; // ecx
  int v21; // eax
  unsigned int v22; // ecx
  unsigned int v23; // eax
  char szAddress[128]; // [esp+Ch] [ebp-C0h] BYREF
  int nextid; // [esp+8Ch] [ebp-40h]
  CUtlRBTree<sv_t *,int,bool (__cdecl*)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int> > sortedList; // [esp+90h] [ebp-3Ch] BYREF
  int v27; // [esp+B4h] [ebp-18h]
  int parent; // [esp+B8h] [ebp-14h] BYREF
  CMasterDlg *v29; // [esp+BCh] [ebp-10h]
  const char *pLastSGName; // [esp+C0h] [ebp-Ch]
  sv_t *pServer; // [esp+C4h] [ebp-8h] BYREF
  bool bSendInfo; // [esp+CBh] [ebp-1h]

  v4 = truenextid < 0;
  v5 = this;
  nextid = truenextid & 0x7FFFFFFF;
  v29 = this;
  bSendInfo = truenextid < 0;
  V_snprintf(pDest: this->m_Reply, maxLen: 1400, pFormat: "%c%c%c%c%c\n", 255, 255, 255, 255, 102);
  *(_DWORD *)&v5->m_Reply[10] = challenge;
  challenge = 14;
  s_bServerListSortFuncJitter = !v4;
  v6 = rand();
  ++s_nServerListSortFuncStart;
  sortedList.m_LessFunc = ServerListSortFunc;
  memset(&sortedList.m_Elements, 0, sizeof(sortedList.m_Elements));
  sortedList.m_NumElements = 0;
  sortedList.m_pElements = nullptr;
  v27 = 2019;
  s_nServerListSortFuncSeed = v6 % 10 + 25;
  sortedList.m_Root = -1;
  sortedList.m_FirstFree = -1;
  sortedList.m_LastAlloc.index = -1;
  pLastSGName = (const char *)v5->m_pGameServers;
  do
  {
    v7 = *(sv_t **)pLastSGName;
    for ( pServer = v7; v7 != nullptr; pServer = v7 )
    {
      if ( CMasterDlg::ServerMatchesCriteria(this: v5, server: v7, criteria: pCriteria) )
      {
        parent = -1;
        HIBYTE(truenextid) = 0;
        CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::FindInsertionPosition(
          this: &sortedList,
          insert: &pServer,
          &parent,
          leftchild: (bool *)&truenextid + 3);
        v8 = CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::NewNode(this: &sortedList);
        m_pMemory = sortedList.m_Elements.m_pMemory;
        v10 = parent;
        v11 = v8;
        sortedList.m_Elements.m_pMemory[v11].m_Parent = parent;
        m_pMemory[v11].m_Right = -1;
        m_pMemory[v11].m_Left = -1;
        m_pMemory[v11].m_Tag = 0;
        if ( v10 == -1 )
        {
          sortedList.m_Root = v8;
        }
        else
        {
          v12 = v10;
          if ( HIBYTE(truenextid) != 0 )
            m_pMemory[v12].m_Left = v8;
          else
            m_pMemory[v12].m_Right = v8;
        }
        CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::InsertRebalance(
          this: &sortedList,
          elem: v8);
        ++sortedList.m_NumElements;
        if ( &sortedList.m_Elements.m_pMemory[v11] != (UtlRBTreeNode_t<sv_t *,int> *)-16 )
          sortedList.m_Elements.m_pMemory[v11].m_Data = pServer;
        v7 = pServer;
      }
      v7 = v7->next;
    }
    pLastSGName += 4;
    --v27;
  }
  while ( v27 != 0 );
  pCriteria = nullptr;
  pServer = nullptr;
  HIBYTE(truenextid) = 0;
  pLastSGName = defaultValue;
  v13 = CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::FirstInorder(this: &sortedList);
  if ( v13 != -1 )
  {
    do
    {
      if ( nextid <= (int)pCriteria )
      {
        pServer = sortedList.m_Elements.m_pMemory[v13].m_Data;
        SGName = (int)v5->m_XLSPPortMapping.m_Tree.m_Elements.m_pMemory[pServer->hXLSPPort].m_Data.elem.SGName;
        v15 = 0;
        if ( strcmp(pLastSGName, (const char *)SGName) != 0 )
        {
          if ( *pLastSGName != 0 )
          {
            *(_WORD *)szAddress = -1;
            v15 = 2;
          }
          v15 += V_snprintf(pDest: &szAddress[v15], maxLen: 128 - v15, pFormat: "%s\n", (const char *)SGName);
          pLastSGName = (const char *)SGName;
        }
        szAddress[v15] = *(_BYTE *)(SGName + 64);
        szAddress[v15 + 1] = BYTE1(*(_DWORD *)(SGName + 64));
        v16 = v15 + 2;
        if ( bSendInfo )
          info_length = pServer->info_length;
        else
          info_length = 0;
        if ( info_length + v16 + challenge + 2 >= 0x578 )
        {
          v5 = v29;
          HIBYTE(truenextid) = 1;
          break;
        }
        memcpy(dst: (unsigned __int8 *)&v29->m_Reply[challenge], src: (unsigned __int8 *)szAddress, count: v16);
        challenge += v16;
        if ( info_length != 0 )
        {
          v18 = challenge;
          memcpy(
            dst: (unsigned __int8 *)&v29->m_Reply[challenge],
            src: (unsigned __int8 *)pServer->info,
            count: info_length);
          challenge = info_length + v18;
        }
        v5 = v29;
      }
      v19 = CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::NextInorder(
              this: &sortedList,
              i: v13);
      pCriteria = (search_criteria_t *)((char *)pCriteria + 1);
      v13 = v19;
    }
    while ( v19 != -1 );
  }
  v20 = challenge;
  v21 = HIBYTE(truenextid);
  *(_WORD *)&v5->m_Reply[challenge] = 0;
  v22 = v20 + 2;
  v23 = v21 != 0 ? (unsigned int)pCriteria : 0;
  if ( bSendInfo )
    v23 |= 0x80000000;
  *(_DWORD *)&v5->m_Reply[6] = v23;
  CMasterDlg::Sys_SendPacket(this: v5, to: &v5->m_packet_from, data: (unsigned __int8 *)v5->m_Reply, len: v22);
  CUtlRBTree<sv_t *,int,bool (__cdecl *)(sv_t * const &,sv_t * const &),CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int>>::RemoveAll(this: &sortedList);
  if ( sortedList.m_Elements.m_nGrowSize >= 0 && sortedList.m_Elements.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sortedList.m_Elements.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00407CC0
// Name: private: bool CMasterDlg::LoadPortMappings(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall CMasterDlg::LoadPortMappings@<al>(CMasterDlg *this@<ecx>, __int128 _XMM0@<xmm0>)
{
  KeyValues **m_pMemory; // edi
  HMODULE ModuleHandleA; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // esi
  const char *Name; // eax
  int m_Size; // esi
  int v9; // eax
  int v10; // eax
  KeyValues **v11; // esi
  KeyValues *KeyRecursive; // esi
  KeyValues *FirstSubKey; // esi
  const char *v14; // eax
  const char *String; // eax
  const char *v16; // edi
  int v18; // eax
  char exeName[260]; // [esp+Ch] [ebp-30Ch] BYREF
  char szConfig[260]; // [esp+110h] [ebp-208h] BYREF
  xlspTitleServer_t titleServer; // [esp+214h] [ebp-104h] BYREF
  CUtlBuffer xlspBuffer; // [esp+258h] [ebp-C0h] BYREF
  CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t search; // [esp+288h] [ebp-90h] BYREF
  sockaddr_in address; // [esp+2DCh] [ebp-3Ch] BYREF
  const char *pSGName; // [esp+2ECh] [ebp-2Ch]
  int nXLSPPort; // [esp+2F0h] [ebp-28h]
  CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > sgList; // [esp+2F4h] [ebp-24h] BYREF
  KeyValues *pKV; // [esp+308h] [ebp-10h]
  int i; // [esp+30Ch] [ebp-Ch]
  KeyValues *pSubKey; // [esp+310h] [ebp-8h]
  bool bValid; // [esp+317h] [ebp-1h]

  m_pMemory = nullptr;
  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  if ( GetModuleFileNameA(hModule: ModuleHandleA, lpFilename: exeName, nSize: 0x104u) == 0 )
    CMasterDlg::Sys_Error(this, pFormat: "XLSPMaster: Failed to get module name");
  V_StripFilename(path: exeName);
  V_strncat(pDest: exeName, pSrc: "\\..\\", destBufferSize: 0x104u, max_chars_to_copy: -1);
  if ( CMasterDlg::Sys_ParseCommandLineArg(this, pKey: "-xlsp", pValueBuff: g_szCenterName, valueBuffSize: 260) == 0 )
    CMasterDlg::Sys_Error(this, pFormat: "XLSPMaster: missing -xlsp <DataCenterName>");
  if ( CMasterDlg::Sys_ParseCommandLineArg(this, pKey: "-titleservers", pValueBuff: szConfig, valueBuffSize: 260) == 0 )
    CMasterDlg::Sys_Error(this, pFormat: "XLSPMaster: missing -titleservers <titleservers.txt>");
  CUtlBuffer::CUtlBuffer(this: &xlspBuffer, growSize: 0, initSize: 0, nFlags: 0);
  if ( !ReadFileToBuffer(pSourceName: szConfig, buffer: &xlspBuffer, bText: true) )
    CMasterDlg::Sys_Error(this, pFormat: "XLSPMaster: Failed to load XLSP Configuration '%s'", szConfig);
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
    pKV = KeyValues::KeyValues(this: v5, setName: "XLSPTitleServers");
  else
    pKV = nullptr;
  v6 = pKV;
  if ( !KeyValues::LoadFromBuffer(
          this: pKV,
          resourceName: "XLSPTitleServers",
          buf: &xlspBuffer,
          pFileSystem: nullptr,
          pPathID: nullptr,
          pfnEvaluateSymbolProc: nullptr) )
    CMasterDlg::Sys_Error(this, pFormat: "XLSPMaster: Failed to unserialize XLSP Configuration '%s'", szConfig);
  memset(&sgList, 0, sizeof(sgList));
  pSubKey = KeyValues::GetFirstSubKey(this: v6);
  if ( pSubKey != nullptr )
  {
    do
    {
      Name = KeyValues::GetName(this: pSubKey);
      if ( V_stristr(pStr: Name, pSearch: "SecureGateway**") != nullptr )
      {
        m_Size = sgList.m_Size;
        v9 = sgList.m_Size;
        if ( sgList.m_Size + 1 > sgList.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>::Grow(
            this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&sgList,
            num: sgList.m_Size - sgList.m_Memory.m_nAllocationCount + 1);
          m_pMemory = sgList.m_Memory.m_pMemory;
          v9 = sgList.m_Size;
        }
        sgList.m_Size = v9 + 1;
        v10 = v9 - m_Size;
        sgList.m_pElements = m_pMemory;
        if ( v10 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v10);
        v11 = &m_pMemory[m_Size];
        if ( v11 != nullptr )
          *v11 = pSubKey;
      }
      pSubKey = KeyValues::GetNextKey(this: pSubKey);
    }
    while ( pSubKey != nullptr );
    if ( sgList.m_Size != 0 )
    {
      for ( i = 0; i < sgList.m_Size; ++i )
      {
        KeyRecursive = FindKeyRecursive(pKV: m_pMemory[i], pFindName: "TitleServers");
        if ( KeyRecursive == nullptr )
          CMasterDlg::Sys_Error(
            this,
            pFormat: "XLSPMaster: Missing key '%s' in XLSP Configuration '%s'",
            "TitleServers",
            szConfig);
        pSGName = KeyValues::GetName(this: m_pMemory[i]) + 15;
        FirstSubKey = KeyValues::GetFirstSubKey(this: KeyRecursive);
        pSubKey = FirstSubKey;
        if ( FirstSubKey != nullptr )
        {
          while ( 1 )
          {
            v14 = KeyValues::GetName(this: FirstSubKey);
            nXLSPPort = atoi(nptr: v14);
            if ( nXLSPPort <= 0 )
              CMasterDlg::Sys_Error(
                this,
                pFormat: "XLSPMaster: Bad Port value in '%s' in XLSP Configuration '%s'",
                "TitleServers",
                szConfig);
            String = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: defaultValue);
            v16 = String;
            if ( String == nullptr || *String == 0 )
              CMasterDlg::Sys_Error(
                this,
                pFormat: "XLSPMaster: Bad IP value in '%s' in XLSP Configuration '%s'",
                "TitleServers",
                szConfig);
            bValid = true;
            if ( CMasterDlg::NET_StringToSockaddr(this: g_pMaster, _XMM0, s: String, sadr: (sockaddr *)&address) == 0 )
            {
              CMasterDlg::Sys_Warning(
                this,
                pFormat: "XLSPMaster: Failed to resolve IP value '%s' in '%s' in XLSP Configuration '%s'",
                v16,
                "TitleServers",
                szConfig);
              bValid = false;
            }
            __asm { movq    xmm0, qword ptr [ebp+address.sin_family] }
            __asm
            {
              movq    qword ptr [ebp+search.key.sin_family], xmm0
              movq    xmm0, qword ptr [ebp+address.sin_zero]
            }
            __asm { movq    qword ptr [ebp+search.key.sin_zero], xmm0 }
            v18 = CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Find(
                    this: &this->m_XLSPPortMapping.m_Tree,
                    &search);
            if ( v18 < 0
              || v18 >= this->m_XLSPPortMapping.m_Tree.m_Elements.m_nAllocationCount
              || v18 > this->m_XLSPPortMapping.m_Tree.m_LastAlloc.index
              || CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::LeftChild(
                   this: &this->m_XLSPPortMapping.m_Tree,
                   i: v18) == v18 )
            {
              if ( bValid )
              {
                V_strncpy(pDest: titleServer.SGName, pSrc: pSGName, maxLen: 64);
                _V_strlower(start: titleServer.SGName);
                __asm { movq    xmm0, qword ptr [ebp+address.sin_family] }
                titleServer.nXLSPPort = nXLSPPort;
                __asm
                {
                  movq    qword ptr [ebp+search.key.sin_family], xmm0
                  movq    xmm0, qword ptr [ebp+address.sin_zero]
                }
                __asm { movq    qword ptr [ebp+search.key.sin_zero], xmm0 }
                search.elem = titleServer;
                CUtlRBTree<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int,CUtlMap<sockaddr_in,xlspTitleServer_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>>::Insert(
                  this: &this->m_XLSPPortMapping.m_Tree,
                  insert: &search);
              }
            }
            else
            {
              CMasterDlg::Sys_Warning(
                this,
                pFormat: "XLSPMaster: Duplicate IP value '%s' in '%s' in XLSP Configuration '%s'",
                v16,
                "TitleServers",
                szConfig);
            }
            pSubKey = KeyValues::GetNextKey(this: pSubKey);
            if ( pSubKey == nullptr )
              break;
            FirstSubKey = pSubKey;
          }
          m_pMemory = sgList.m_Memory.m_pMemory;
        }
      }
      KeyValues::deleteThis(this: pKV);
      CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&sgList);
      CUtlBuffer::~CUtlBuffer(this: &xlspBuffer);
      return 1;
    }
  }
  CMasterDlg::Sys_Error(
    this,
    pFormat: "XLSPMaster: Missing key '%s' in XLSP Configuration '%s'",
    "SecureGateway_<xxx>",
    szConfig);
}

//------------------------------------------------------------------------------
// Address: 0x004080F0
// Name: private: bool CMasterDlg::Startup(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CMasterDlg::Startup@<al>(CMasterDlg *this@<ecx>, __int128 a2@<xmm0>, HWND__ *hWnd)
{
  const tm *v4; // eax
  unsigned __int8 *v5; // edi
  _BYTE *v6; // eax
  __int128 v7; // xmm0
  int v8; // ebx
  const char *v9; // edi
  CFmtStrN<256> *v10; // eax
  char v11; // al
  int v12; // edi
  CReportingThread *v13; // ebx
  CFmtStrN<256> *v14; // eax
  const char *FileName; // eax
  const char *v16; // eax
  HICON IconA; // eax
  u_short v20; // ax
  KeyValues *v22; // edi
  KeyValues *v23; // ecx
  KeyValues *Key; // eax
  const char *CommandLineA; // eax
  KeyValues *MasterData_Init; // eax
  KeyValues *v27; // eax
  KeyValues *v28; // eax
  KeyValues *Copy; // eax
  KeyValues *v30; // ebx
  int v31; // eax
  HWND m_hWnd; // edx
  int v35; // [esp-8h] [ebp-338h]
  int Int; // [esp-4h] [ebp-334h]
  CFmtStrN<256> v37; // [esp+Ch] [ebp-324h] BYREF
  char szText[256]; // [esp+118h] [ebp-218h] BYREF
  char chMysqlConnectionConfigFile[256]; // [esp+218h] [ebp-118h] BYREF
  __int64 t; // [esp+318h] [ebp-18h] BYREF
  __int64 v41; // [esp+320h] [ebp-10h]
  __int64 k; // [esp+328h] [ebp-8h] BYREF
  HWND__ *hWnda; // [esp+338h] [ebp+8h]
  char *hWndb; // [esp+338h] [ebp+8h]
  HWND__ *hWndc; // [esp+338h] [ebp+8h]

  _ESI = this;
  this->m_hWnd = hWnd;
  this->m_hLogWnd = GetDlgItem(hDlg: hWnd, nIDDlgItem: 1001);
  t = _time64(timeptr: nullptr);
  v4 = _localtime64(ptime: &t);
  v5 = (unsigned __int8 *)asctime(tb: v4);
  strrchr(string: v5, chr: 0xAu);
  if ( v6 != nullptr )
    *v6 = 0;
  CMasterDlg::Sys_VPrintf(this: _ESI, pMsg: "Service Started: %s\n", (const char *)v5);
  if ( CMasterDlg::Sys_ParseCommandLineArg(
         this: _ESI,
         pKey: "-chunkfile",
         pValueBuff: g_szCenterChunkFile,
         valueBuffSize: 260) == 0 )
    CMasterDlg::Sys_Error(this: _ESI, pFormat: "-chunkfile parameter is missing!");
  GetGlobalInfoChunk_Init();
  if ( CMasterDlg::Sys_ParseCommandLineArg(
         this: _ESI,
         pKey: "-patchfile",
         pValueBuff: g_szCenterPatchFile,
         valueBuffSize: 260) == 0 )
    CMasterDlg::Sys_Error(this: _ESI, pFormat: "-patchfile parameter is missing!");
  GetGlobalPatch_Init(a1: a2);
  CMasterDlg::NET_Init(this: _ESI, a2: v7);
  _ESI->m_MasterThread.Init_2(this: &_ESI->m_MasterThread, a2: _ESI->m_net_socket);
  LODWORD(k) = "data";
  HIDWORD(k) = "vote";
  v8 = 0;
  hWnda = (HWND__ *)_ESI->m_ReportingThreads;
  do
  {
    memset(chMysqlConnectionConfigFile, 0, sizeof(chMysqlConnectionConfigFile));
    v9 = *((const char **)&k + v8);
    v10 = CFmtStrN<256>::CFmtStrN<256>(this: &v37, pszFormat: "-mysql%s", v9);
    if ( CMasterDlg::Sys_ParseCommandLineArg(
           this: _ESI,
           pKey: v10->m_szBuf,
           pValueBuff: chMysqlConnectionConfigFile,
           valueBuffSize: 256) == 0 )
      chMysqlConnectionConfigFile[0] = 0;
    v11 = (*(int (__thiscall **)(HWND__ *, char *))(*(_DWORD *)hWnda + 28))(a1: hWnda, a2: chMysqlConnectionConfigFile);
    if ( chMysqlConnectionConfigFile[0] == 0 || v11 == 0 )
      CMasterDlg::Sys_Warning(this: _ESI, pFormat: "Failed to open connection specified in -mysql%s config!", v9);
    hWnda += 286;
    ++v8;
  }
  while ( v8 < 2 );
  HIDWORD(k) = 2;
  v12 = 0;
  v13 = &_ESI->m_ReportingThreads[2];
  hWndb = _ESI->m_chReportingGameStats[0];
  do
  {
    memset(chMysqlConnectionConfigFile, 0, sizeof(chMysqlConnectionConfigFile));
    v14 = CFmtStrN<256>::CFmtStrN<256>(this: &v37, pszFormat: "-gamestat%d", v12);
    if ( CMasterDlg::Sys_ParseCommandLineArg(
           this: _ESI,
           pKey: v14->m_szBuf,
           pValueBuff: chMysqlConnectionConfigFile,
           valueBuffSize: 256) == 0
      || chMysqlConnectionConfigFile[0] == 0 )
    {
      break;
    }
    FileName = V_GetFileName(pPath: chMysqlConnectionConfigFile);
    v16 = StringAfterPrefix(str: FileName, prefix: "gamestat_");
    if ( v16 == nullptr )
      CMasterDlg::Sys_Error(this: _ESI, pFormat: "Invalid configuration setup for -gamestat%d config!", HIDWORD(k) - 2);
    V_strncpy(pDest: hWndb, pSrc: v16, maxLen: 64);
    if ( !v13->Init_2(this: v13, a2: chMysqlConnectionConfigFile) )
      CMasterDlg::Sys_Warning(this: _ESI, pFormat: "Failed to open connection specified in -gamestat%d config!", v12);
    ++HIDWORD(k);
    hWndb += 64;
    ++v12;
    ++v13;
  }
  while ( v12 < 13 );
  CMasterDlg::OpenNewLogFile(this: _ESI);
  IconA = LoadIconA(hInstance: g_hInstance, lpIconName: (LPCSTR)0x66);
  SetClassLongA(hWnd: _ESI->m_hWnd, nIndex: -14, dwNewLong: (LONG)IconA);
  __asm
  {
    movq    xmm0, qword ptr [esi+130h]
    movq    [ebp+var_10], xmm0
  }
  __asm { movq    xmm0, qword ptr [esi+138h] }
  __asm { movq    [ebp+k], xmm0 }
  v20 = ntohs(netshort: WORD1(v41));
  V_snprintf(
    pDest: g_szCenterAddress,
    maxLen: 260,
    pFormat: "%i.%i.%i.%i:%i",
    BYTE4(v41),
    BYTE5(v41),
    BYTE6(v41),
    HIBYTE(v41),
    v20);
  V_snprintf(
    pDest: szText,
    maxLen: 256,
    pFormat: "XLSP Master %s - L4D %s/%d (Build: Jul 15 2011 03:34:05)",
    g_szCenterAddress,
    _ESI->m_szL4DVersion,
    7);
  SetWindowTextA(hWnd: _ESI->m_hWnd, lpString: szText);
  CMasterDlg::LoadPortMappings(this: _ESI, _XMM0);
  V_snprintf(
    pDest: g_szCenterInfo,
    maxLen: 260,
    pFormat: "%s@%s<%s>%d",
    g_szCenterName,
    g_szCenterAddress,
    _ESI->m_szL4DVersion,
    7);
  v22 = nullptr;
  if ( InfoChunks::g_arrChunks.m_Size != 0 )
    v23 = *InfoChunks::g_arrChunks.m_Memory.m_pMemory;
  else
    v23 = nullptr;
  Key = KeyValues::FindKey(this: v23, keyName: "settings", bCreate: false);
  if ( KeyValues::FindKey(this: Key, keyName: "-fake", bCreate: false) != nullptr
    || (CommandLineA = GetCommandLineA(), V_stristr(pStr: CommandLineA, pSearch: "-fake") != nullptr) )
  {
    CMasterDlg::GenerateFakeServers(this: _ESI);
  }
  MasterData_Init = InfoChunks::g_pMasterData;
  if ( InfoChunks::g_pMasterData == nullptr )
  {
    MasterData_Init = GetMasterData_Init();
    InfoChunks::g_pMasterData = MasterData_Init;
  }
  LODWORD(k) = &CKeyValuesDumpContextAsDevMsg::`vftable';
  HIDWORD(k) = 0;
  KeyValues::Dump(this: MasterData_Init, pDump: (IKeyValuesDumpContext *)&k, nIndentLevel: 1);
  v27 = InfoChunks::g_pMasterData;
  if ( InfoChunks::g_pMasterData == nullptr )
  {
    v27 = GetMasterData_Init();
    InfoChunks::g_pMasterData = v27;
  }
  hWndc = (HWND__ *)v27;
  if ( (_S2 & 1) == 0 )
  {
    _S2 |= 1u;
    v28 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v28 != nullptr )
      g_pKV_0 = KeyValues::KeyValues(this: v28, setName: g_szXlspDataRoot);
    else
      g_pKV_0 = nullptr;
  }
  KeyValues::Clear(this: g_pKV_0);
  if ( InfoChunks::g_arrPatches.m_Size > 1 )
  {
    Copy = KeyValues::MakeCopy(this: InfoChunks::g_arrPatches.m_Memory.m_pMemory[1]);
    KeyValues::AddSubKey(this: g_pKV_0, pSubkey: Copy);
  }
  v30 = g_pKV_0;
  if ( InfoChunks::g_arrChunks.m_Size != 0 )
    v22 = *InfoChunks::g_arrChunks.m_Memory.m_pMemory;
  Int = KeyValues::GetInt(this: (KeyValues *)hWndc, keyName: "chunks/data_patch/chunks", defaultValue: 0);
  v35 = KeyValues::GetInt(this: v30, keyName: "patch/size", defaultValue: 0);
  v31 = KeyValues::GetInt(this: v22, keyName: "version", defaultValue: 0);
  CMasterDlg::Sys_Printf(
    this: _ESI,
    pMsg: "********* Configuration: version = %d, patch size = %d bytes (%d packets)\n",
    v31,
    v35,
    Int);
  CMasterDlg::ComputeStatistics(this: _ESI);
  _ESI->m_fProfilingStartTime = _Plat_FloatTime();
  m_hWnd = _ESI->m_hWnd;
  __asm { xorps   xmm0, xmm0 }
  __asm { movss   dword ptr [esi+33630h], xmm0 }
  _ESI->m_nInTransactions = 0;
  __asm { movss   dword ptr [esi+3362Ch], xmm0 }
  _ESI->m_bReadyForService = true;
  _ESI->m_ServiceMessagesTimer = SetTimer(hWnd: m_hWnd, nIDEvent: 0x29Au, uElapse: 0x64u, lpTimerFunc: nullptr);
  SetTimer(hWnd: _ESI->m_hWnd, nIDEvent: 0x309u, uElapse: 0xEA60u, lpTimerFunc: nullptr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00408610
// Name: private: void CMasterDlg::Packet_GetServersBatch2(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMasterDlg::Packet_GetServersBatch2(CMasterDlg *this)
{
  int v2; // eax
  int v3; // ebx
  int m_msg_readcount; // eax
  unsigned int v5; // edi
  unsigned __int8 *String; // eax
  char *v7; // eax
  char *v8; // eax
  char *v9; // eax
  char *v10; // eax
  char *v11; // eax
  char info[2048]; // [esp+Ch] [ebp-8ECh] BYREF
  search_criteria_t criteria; // [esp+80Ch] [ebp-ECh] BYREF

  v2 = ++this->m_msg_readcount;
  if ( v2 < this->m_packet_length )
  {
    this->m_msg_readcount = v2 + 4;
    v3 = *(_DWORD *)&this->m_PacketData[v2];
  }
  else
  {
    CMasterDlg::Sys_Printf(this, pMsg: "Overflow reading int\n");
    v3 = -1;
  }
  m_msg_readcount = this->m_msg_readcount;
  if ( m_msg_readcount < this->m_packet_length )
  {
    this->m_msg_readcount = m_msg_readcount + 4;
    v5 = *(_DWORD *)&this->m_PacketData[m_msg_readcount];
  }
  else
  {
    CMasterDlg::Sys_Printf(this, pMsg: "Overflow reading int\n");
    v5 = -1;
  }
  String = (unsigned __int8 *)CMasterDlg::MSG_ReadString(this);
  strncpy(dest: (unsigned __int8 *)info, source: String, count: 0x7FFu);
  info[2047] = 0;
  if ( info[0] != 0 )
  {
    memset(dst: (unsigned __int8 *)&criteria, value: 0, count: sizeof(criteria));
    v7 = Info_ValueForKey(s: info, key: "map");
    if ( v7 != nullptr && *v7 != 0 )
    {
      criteria.usemap = 1;
      SetCriteria(c: &criteria.map, value: v7);
    }
    v8 = Info_ValueForKey(s: info, key: "gamedir");
    if ( v8 != nullptr && *v8 != 0 )
    {
      criteria.usegame = 1;
      SetCriteria(c: &criteria.gamedir, value: v8);
    }
    v9 = Info_ValueForKey(s: info, key: "full");
    if ( v9 != nullptr && *v9 != 0 )
      criteria.usefull = 1;
    v10 = Info_ValueForKey(s: info, key: "empty");
    if ( v10 != nullptr && *v10 != 0 )
      criteria.useempty = 1;
    v11 = Info_ValueForKey(s: info, key: "private");
    criteria.usePrivate = 1;
    SetCriteria(c: &criteria.privateKey, value: v11);
    CMasterDlg::Packet_BatchResponder(this, truenextid: v3, challenge: v5, pCriteria: &criteria);
  }
  else
  {
    CMasterDlg::Packet_BatchResponder(this, truenextid: v3, challenge: v5, pCriteria: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004087E0
// Name: private: void CMasterDlg::PacketCommand(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CMasterDlg::PacketCommand(CMasterDlg *this@<ecx>, __int128 _XMM0@<xmm0>)
{
  int v3; // edi
  bool v4; // zf
  u_short v6; // ax
  char *v7; // ebx
  int v8; // eax
  int m_msg_readcount; // eax
  unsigned __int8 v10; // cl
  int v11; // edi
  u_short v14; // ax
  char dataString[256]; // [esp+4h] [ebp-150h] BYREF
  char szAddress[64]; // [esp+104h] [ebp-50h] BYREF
  __int64 v17; // [esp+144h] [ebp-10h]

  _ESI = this;
  if ( this->m_packet_length <= 1500 )
  {
    v3 = 0;
    v4 = !this->m_bPureUDP;
    this->m_msg_readcount = 0;
    if ( v4 )
      this->m_msg_readcount = 2;
    if ( this->m_bShowPackets )
    {
      __asm
      {
        movq    xmm0, qword ptr [esi+140h]
        movq    [ebp+var_10], xmm0
      }
      __asm { movq    xmm0, qword ptr [esi+148h] }
      __asm { movq    [ebp+var_8], xmm0 }
      v6 = ntohs(netshort: WORD1(v17));
      V_snprintf(
        pDest: szAddress,
        maxLen: 64,
        pFormat: "%i.%i.%i.%i:%i",
        BYTE4(v17),
        BYTE5(v17),
        BYTE6(v17),
        HIBYTE(v17),
        v6);
      v7 = dataString;
      if ( _ESI->m_packet_length > 0 )
      {
        do
        {
          if ( v3 >= 16 )
            break;
          v8 = sprintf(string: v7, format: "%2.2x ", _ESI->m_PacketData[v3++]);
          v7 += v8;
        }
        while ( v3 < _ESI->m_packet_length );
      }
      CMasterDlg::Sys_VPrintf(this: _ESI, pMsg: "%s :: %s\n", szAddress, dataString);
    }
    m_msg_readcount = _ESI->m_msg_readcount;
    v10 = _ESI->m_PacketData[m_msg_readcount];
    v11 = v10;
    _ESI->m_msg_readcount = m_msg_readcount + 1;
    switch ( v10 )
    {
      case '0':
        CMasterDlg::Packet_Heartbeat2(this: _ESI);
        break;
      case '1':
        CMasterDlg::Packet_GetServersBatch2(this: _ESI);
        break;
      case '?':
        CMasterDlg::Packet_KV_Cmd(this: _ESI, _XMM0);
        break;
      case 'b':
        CMasterDlg::Packet_Shutdown(this: _ESI);
        break;
      case 'i':
        CMasterDlg::Packet_Ping(this: _ESI);
        break;
      case 'q':
        CMasterDlg::Packet_GetChallenge(this: _ESI);
        break;
      default:
        __asm
        {
          movq    xmm0, qword ptr [esi+140h]; jumptable 004088FE default case, cases 50-62,64-97,99-104,106-112
          movq    [ebp+var_10], xmm0
        }
        __asm { movq    xmm0, qword ptr [esi+148h] }
        __asm { movq    [ebp+var_8], xmm0 }
        v14 = ntohs(netshort: WORD1(v17));
        V_snprintf(
          pDest: szAddress,
          maxLen: 64,
          pFormat: "%i.%i.%i.%i:%i",
          BYTE4(v17),
          BYTE5(v17),
          BYTE6(v17),
          HIBYTE(v17),
          v14);
        CMasterDlg::Sys_VPrintf(this: _ESI, pMsg: "Unknown Packet Command (%d) from %s\n", v11, szAddress);
        break;
    }
  }
  else
  {
    CMasterDlg::Sys_VPrintf(this, pMsg: "Bad packet size: %i\n", this->m_packet_length);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408A20
// Name: public: void CMasterDlg::ServiceMessages(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CMasterDlg::ServiceMessages(
        CMasterDlg *this@<ecx>,
        __int128 a2@<xmm0>,
        __int128 a3@<xmm1>,
        __int128 _XMM2@<xmm2>)
{
  int v5; // ebx
  int m_nActualLength; // eax
  bool v13; // sf
  HWND DlgItem; // eax
  HWND v22; // eax
  HWND v23; // eax
  HWND v32; // eax
  HWND v43; // eax
  HWND v44; // eax
  HWND v48; // eax
  HWND v51; // eax
  double v55; // [esp+4h] [ebp-234h]
  double v57; // [esp+4h] [ebp-234h]
  double v59; // [esp+4h] [ebp-234h]
  char szText[512]; // [esp+18h] [ebp-220h] BYREF
  CUtlVector<QueuedPacket_t *,CUtlMemory<QueuedPacket_t *,int> > vecPackets; // [esp+218h] [ebp-20h] BYREF

  _ESI = this;
  if ( this->m_bReadyForService && !s_bInService )
  {
    s_bInService = true;
    this->m_curtime = (int)_Plat_FloatTime();
    CMasterDlg::TimeoutServers(this: _ESI, _XMM0: a2, _XMM1: a3);
    v5 = 0;
    memset(&vecPackets, 0, sizeof(vecPackets));
    CMasterThread::GetQueuedPackets(this: &_ESI->m_MasterThread, list: &vecPackets);
    if ( vecPackets.m_Size > 0 )
    {
      do
      {
        _EDI = vecPackets.m_Memory.m_pMemory[v5];
        m_nActualLength = _EDI->m_Data.m_nActualLength;
        _ESI->m_packet_length = m_nActualLength;
        if ( m_nActualLength != 0 )
        {
          __asm
          {
            movq    xmm0, qword ptr [edi]
            movq    qword ptr [esi+140h], xmm0
            movq    xmm0, qword ptr [edi+8]
          }
          ++_ESI->m_nInTransactions;
          __asm
          {
            movq    qword ptr [esi+148h], xmm0
            movd    xmm0, dword ptr [esi+150h]
            cvtdq2ps xmm0, xmm0
            addss   xmm0, dword ptr [esi+33630h]
          }
          __asm { movss   dword ptr [esi+33630h], xmm0 }
          _V_memcpy(dest: _ESI->m_PacketData, src: _EDI->m_Data.m_Memory.m_pMemory, count: m_nActualLength);
          CMasterDlg::PacketCommand(this: _ESI, _XMM0);
        }
        v13 = _EDI->m_Data.m_Memory.m_nGrowSize < 0;
        _EDI->m_Data.m_nActualLength = 0;
        if ( !v13 )
        {
          if ( _EDI->m_Data.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: _EDI->m_Data.m_Memory.m_pMemory);
            _EDI->m_Data.m_Memory.m_pMemory = nullptr;
          }
          _EDI->m_Data.m_Memory.m_nAllocationCount = 0;
        }
        QueuedPacket_t::operator delete(p: _EDI);
        ++v5;
      }
      while ( v5 < vecPackets.m_Size );
    }
    CMasterDlg::ComputeStatistics(this: _ESI);
    __asm
    {
      movd    xmm0, dword ptr [esi+154h]
      cvtdq2pd xmm0, xmm0
    }
    _XMM1 = _XMM0;
    __asm
    {
      subsd   xmm0, tLastScreenUpdateTime
      subsd   xmm1, qword ptr [esi+33620h]
      cvtsd2ss xmm0, xmm0
    }
    __asm
    {
      cvtsd2ss xmm1, xmm1
      movss   [ebp+fProfilingElapsed], xmm1
    }
    if ( *(float *)&_XMM0 > 1.0 )
    {
      V_snprintf(
        pDest: szText,
        maxLen: 512,
        pFormat: "Servers:%6i Users:%6i Bots:%6i",
        _ESI->m_nServerCount,
        _ESI->m_nUsers,
        _ESI->m_nBotCount);
      DlgItem = GetDlgItem(hDlg: _ESI->m_hWnd, nIDDlgItem: 1002);
      SetWindowTextA(hWnd: DlgItem, lpString: szText);
      V_snprintf(
        pDest: szText,
        maxLen: 512,
        pFormat: "Servers:%6i Users:%6i Bots:%6i",
        _ESI->m_nLanServerCount,
        _ESI->m_nLanUsers,
        _ESI->m_nLanBotCount);
      v22 = GetDlgItem(hDlg: _ESI->m_hWnd, nIDDlgItem: 1011);
      SetWindowTextA(hWnd: v22, lpString: szText);
      V_snprintf(
        pDest: szText,
        maxLen: 512,
        pFormat: "Servers:%6i Users:%6i Bots:%6i",
        _ESI->m_nServerCount + _ESI->m_nLanServerCount,
        _ESI->m_nUsers + _ESI->m_nLanUsers,
        _ESI->m_nBotCount + _ESI->m_nLanBotCount);
      v23 = GetDlgItem(hDlg: _ESI->m_hWnd, nIDDlgItem: 1013);
      SetWindowTextA(hWnd: v23, lpString: szText);
      _EAX = _ESI->m_nMaxSlots;
      __asm { xorps   xmm0, xmm0 }
      if ( _EAX > 0 )
      {
        _ECX = _ESI->m_nUsers + _ESI->m_nLanUsers;
        __asm
        {
          xorps   xmm0, xmm0
          xorps   xmm1, xmm1
          cvtsi2ss xmm0, this
          cvtsi2ss xmm1, eax
          divss   xmm0, xmm1
        }
      }
      __asm { mulss   xmm0, ds:__real@42c80000 }
      __asm
      {
        cvtps2pd xmm0, xmm0
        movsd   [esp+234h+var_238+4], xmm0
      }
      V_snprintf(
        pDest: szText,
        maxLen: 512,
        pFormat: "Capacity:%6i Empty:%6i Users/Server:%.2f%%",
        _EAX,
        _ESI->m_nEmpty,
        v55);
      v32 = GetDlgItem(hDlg: _ESI->m_hWnd, nIDDlgItem: 1014);
      SetWindowTextA(hWnd: v32, lpString: szText);
      __asm
      {
        xorps   xmm0, xmm0
        movss   xmm2, [ebp+fProfilingElapsed]
      }
      __asm
      {
        movss   [ebp+fInRate], xmm0
        movss   [ebp+fOutRate], xmm0
      }
      if ( *(float *)&_XMM2 > *(float *)&_XMM0 )
      {
        __asm
        {
          movss   xmm0, ds:__real@3f800000
          movss   xmm1, dword ptr [esi+33630h]
          divss   xmm0, xmm2
          mulss   xmm1, xmm0
          movss   [ebp+fInRate], xmm1
          movss   xmm1, dword ptr [esi+3362Ch]
          mulss   xmm1, xmm0
          movss   [ebp+fOutRate], xmm1
        }
      }
      __asm
      {
        movss   xmm0, dword ptr [esi+33618h]
        subss   xmm0, xmm2
        cvttss2si eax, xmm0
      }
      V_snprintf(pDest: szText, maxLen: 512, pFormat: "%i", _EAX);
      v43 = GetDlgItem(hDlg: _ESI->m_hWnd, nIDDlgItem: 1005);
      SetWindowTextA(hWnd: v43, lpString: szText);
      V_snprintf(pDest: szText, maxLen: 512, pFormat: "%i", _ESI->m_nInTransactions);
      v44 = GetDlgItem(hDlg: _ESI->m_hWnd, nIDDlgItem: 1004);
      SetWindowTextA(hWnd: v44, lpString: szText);
      __asm
      {
        movss   xmm0, [ebp+fInRate]
        cvttss2si edx, dword ptr [esi+33630h]
      }
      __asm
      {
        cvtps2pd xmm0, xmm0
        movsd   [esp+234h+var_238+4], xmm0
      }
      V_snprintf(pDest: szText, maxLen: 512, pFormat: "%i / %.2f", _EDX, v57);
      v48 = GetDlgItem(hDlg: _ESI->m_hWnd, nIDDlgItem: 1003);
      SetWindowTextA(hWnd: v48, lpString: szText);
      __asm
      {
        movss   xmm0, [ebp+fOutRate]
        cvttss2si eax, dword ptr [esi+3362Ch]
      }
      __asm
      {
        cvtps2pd xmm0, xmm0
        movsd   [esp+234h+var_238+4], xmm0
      }
      V_snprintf(pDest: szText, maxLen: 512, pFormat: "%i / %.2f", _EAX, v59);
      v51 = GetDlgItem(hDlg: _ESI->m_hWnd, nIDDlgItem: 1006);
      SetWindowTextA(hWnd: v51, lpString: szText);
      tLastScreenUpdateTime = _Plat_FloatTime();
    }
    __asm { movss   xmm0, [ebp+fProfilingElapsed] }
    if ( *(float *)&_XMM0 >= _ESI->m_fProfilingCycleTime )
    {
      _ESI->m_fProfilingStartTime = _Plat_FloatTime();
      __asm
      {
        xorps   xmm0, xmm0
        movss   dword ptr [esi+33630h], xmm0
      }
      _ESI->m_nInTransactions = 0;
      __asm { movss   dword ptr [esi+3362Ch], xmm0 }
    }
    s_bInService = false;
    CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&vecPackets);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408EA0
// Name: public: int CMasterDlg::DlgProc(struct HWND__ __near *,unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CMasterDlg::DlgProc@<eax>(
        CMasterDlg *this@<ecx>,
        __int128 a2@<xmm0>,
        __int128 a3@<xmm1>,
        __int128 a4@<xmm2>,
        HWND__ *hWnd,
        unsigned int message,
        HMENU wParam,
        int lParam)
{
  int result; // eax
  bool m_bGenerateLogs; // zf

  switch ( message )
  {
    case 0x110u:
      CMasterDlg::Startup(this, a2, hWnd);
      return 1;
    case 0x111u:
      if ( (unsigned __int16)wParam > 0x9C4Eu )
      {
        switch ( (unsigned __int16)wParam )
        {
          case 0x9C50u:
            m_bGenerateLogs = this->m_bGenerateLogs;
            this->m_bGenerateLogs ^= 1u;
            if ( m_bGenerateLogs )
              CMasterDlg::CloseLogFile(this);
            else
              CMasterDlg::OpenNewLogFile(this);
            result = 1;
            break;
          case 0x9C51u:
            this->m_bShowPackets ^= 1u;
            result = 1;
            break;
          case 0x9C54u:
            this->m_bShowTraffic ^= 1u;
            result = 1;
            break;
          case 0x9C56u:
            CMasterDlg::ListPorts(this);
            result = 1;
            break;
          default:
            return 0;
        }
      }
      else
      {
        switch ( (unsigned __int16)wParam )
        {
          case 0x9C4Eu:
            CMasterDlg::ClearLogWindow(this);
            return 1;
          case 2u:
            CMasterDlg::Shutdown(this);
            EndDialog(hDlg: this->m_hWnd, nResult: (INT_PTR)wParam);
            PostQuitMessage(nExitCode: 0);
            return 1;
          case 0x9C46u:
            CMasterDlg::ListServers(this);
            return 1;
          case 0x9C4Au:
            break;
          default:
            return 0;
        }
      }
      return result;
    case 0x113u:
      switch ( (unsigned __int16)wParam )
      {
        case 0x29Au:
          CMasterDlg::ServiceMessages(this, a2, a3, _XMM2: a4);
          return 1;
        case 0x309u:
          CMasterDlg::ConfigPoll(this);
          return 1;
        case 0x378u:
          KillTimer(hWnd: this->m_hWnd, uIDEvent: 0x378u);
          CMasterDlg::ConfigReload(this, a2);
          return 1;
        default:
          return 0;
      }
    case 0x116u:
      CheckMenuItem(hMenu: wParam, uIDCheckItem: 0x9C50u, uCheck: this->m_bGenerateLogs ? 8 : 0);
      CheckMenuItem(hMenu: wParam, uIDCheckItem: 0x9C51u, uCheck: this->m_bShowPackets ? 8 : 0);
      CheckMenuItem(hMenu: wParam, uIDCheckItem: 0x9C54u, uCheck: this->m_bShowTraffic ? 8 : 0);
      return 1;
    default:
      return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004090A0
// Name: int Master_DlgProc(struct HWND__ __near *,unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __userpurge Master_DlgProc@<eax>(
        __int128 a1@<xmm0>,
        __int128 a2@<xmm1>,
        __int128 a3@<xmm2>,
        HWND__ *hWnd,
        unsigned int message,
        HMENU wParam,
        int lParam)
{
  return CMasterDlg::DlgProc(this: g_pMaster, a2: a1, a3: a2, a4: a3, hWnd, message, wParam, lParam);
}

//------------------------------------------------------------------------------
// Address: 0x004090B0
// Name: public: CMasterDlg::CMasterDlg(void)
// Source: json
//------------------------------------------------------------------------------
CMasterDlg *__usercall CMasterDlg::CMasterDlg@<eax>(CMasterDlg *this@<ecx>, __int128 _XMM0@<xmm0>)
{
  CReportingThread *m_ReportingThreads; // edi
  KeyValues *v4; // ecx
  KeyValues *Key; // eax
  bool v6; // al
  const char *CommandLineA; // eax
  KeyValues *v8; // ecx
  KeyValues *v9; // eax
  bool v10; // al
  const char *v11; // eax
  char strLocalIPAddress[260]; // [esp+Ch] [ebp-20Ch] BYREF
  char argString[260]; // [esp+110h] [ebp-108h] BYREF
  int i; // [esp+214h] [ebp-4h]

  _ESI = this;
  this->m_XLSPPortMapping.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_XLSPPortMapping.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_XLSPPortMapping.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_XLSPPortMapping.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_XLSPPortMapping.m_Tree.m_Root = -1;
  this->m_XLSPPortMapping.m_Tree.m_FirstFree = -1;
  this->m_XLSPPortMapping.m_Tree.m_NumElements = 0;
  this->m_XLSPPortMapping.m_Tree.m_LastAlloc.index = -1;
  this->m_XLSPPortMapping.m_Tree.m_pElements = this->m_XLSPPortMapping.m_Tree.m_Elements.m_pMemory;
  CUtlString::CUtlString(this: &this->m_strLocalIPAddress);
  CThread::CThread(this: &_ESI->m_MasterThread);
  _ESI->m_MasterThread.__vftable = (CMasterThread_vtbl *)&CMasterThread::`vftable';
  _ESI->m_MasterThread.m_Packets.m_Memory.m_pMemory = nullptr;
  _ESI->m_MasterThread.m_Packets.m_Memory.m_nAllocationCount = 0;
  _ESI->m_MasterThread.m_Packets.m_Memory.m_nGrowSize = 0;
  _ESI->m_MasterThread.m_Packets.m_Size = 0;
  _ESI->m_MasterThread.m_Packets.m_pElements = nullptr;
  CThreadMutex::CThreadMutex(this: &_ESI->m_MasterThread.m_PacketsCS);
  _ESI->m_MasterThread.m_bThreadShouldExit = false;
  m_ReportingThreads = _ESI->m_ReportingThreads;
  for ( i = 14; i >= 0; --i )
    CReportingThread::CReportingThread(this: m_ReportingThreads++);
  _V_memset(dest: _ESI->m_chReportingGameStats, fill: 0, count: 832);
  g_pMaster = _ESI;
  if ( InfoChunks::g_arrChunks.m_Size != 0 )
    v4 = *InfoChunks::g_arrChunks.m_Memory.m_pMemory;
  else
    v4 = nullptr;
  Key = KeyValues::FindKey(this: v4, keyName: "settings", bCreate: false);
  if ( KeyValues::FindKey(this: Key, keyName: "-pureudp", bCreate: false) != nullptr )
  {
    v6 = true;
  }
  else
  {
    CommandLineA = GetCommandLineA();
    v6 = V_stristr(pStr: CommandLineA, pSearch: "-pureudp") != nullptr;
  }
  _ESI->m_bPureUDP = v6;
  if ( InfoChunks::g_arrChunks.m_Size != 0 )
    v8 = *InfoChunks::g_arrChunks.m_Memory.m_pMemory;
  else
    v8 = nullptr;
  v9 = KeyValues::FindKey(this: v8, keyName: "settings", bCreate: false);
  if ( KeyValues::FindKey(this: v9, keyName: "-log", bCreate: false) != nullptr )
  {
    v10 = true;
  }
  else
  {
    v11 = GetCommandLineA();
    v10 = V_stristr(pStr: v11, pSearch: "-log") != nullptr;
  }
  _ESI->m_bGenerateLogs = v10;
  _ESI->m_net_hostport = 27011;
  argString[0] = 0;
  if ( CMasterDlg::Sys_ParseCommandLineArg(this: _ESI, pKey: "-udport", pValueBuff: argString, valueBuffSize: 260) != 0 )
    _ESI->m_net_hostport = atoi(nptr: argString);
  CUtlString::operator=(this: &_ESI->m_strLocalIPAddress, src: defaultValue);
  if ( CMasterDlg::Sys_ParseCommandLineArg(
         this: _ESI,
         pKey: "-localip",
         pValueBuff: strLocalIPAddress,
         valueBuffSize: 260) != 0 )
    CUtlString::operator=(this: &_ESI->m_strLocalIPAddress, src: strLocalIPAddress);
  __asm { xorps   xmm0, xmm0 }
  *(_WORD *)&_ESI->m_bShowPackets = 256;
  _ESI->m_bReadyForService = false;
  _ESI->m_pLogfile = nullptr;
  *(_DWORD *)_ESI->m_szL4DVersion = *(_DWORD *)a10;
  __asm
  {
    movsd   qword ptr [esi+33620h], xmm0
    movss   xmm0, ds:__real@42700000
  }
  __asm
  {
    movss   dword ptr [esi+33618h], xmm0
    xorps   xmm0, xmm0
  }
  *(_DWORD *)&_ESI->m_szL4DVersion[4] = 3157553;
  _ESI->m_nLanServerCount = 0;
  _ESI->m_nLanUsers = 0;
  _ESI->m_nServerCount = 0;
  _ESI->m_nUsers = 0;
  _ESI->m_nMaxSlots = 0;
  _ESI->m_nEmpty = 0;
  __asm
  {
    movss   dword ptr [esi+33630h], xmm0
    movss   dword ptr [esi+3362Ch], xmm0
  }
  _ESI->m_nInTransactions = 0;
  memset(dst: (unsigned __int8 *)_ESI->m_pGameServers, value: 0, count: sizeof(_ESI->m_pGameServers));
  _ESI->m_pMods[0] = nullptr;
  _ESI->m_nUniqueID = 1;
  _ESI->m_hWnd = nullptr;
  _ESI->m_hLogWnd = nullptr;
  _ESI->m_curtime = (int)_Plat_FloatTime();
  _ESI->m_ServiceMessagesTimer = 0;
  if ( _ESI->m_XLSPPortMapping.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    _ESI->m_XLSPPortMapping.m_Tree.m_LessFunc.m_LessFunc = AddressLessFunc;
  CreateDialogParamA(
    hInstance: g_hInstance,
    lpTemplateName: (LPCSTR)0x65,
    hWndParent: nullptr,
    lpDialogFunc: (DLGPROC)Master_DlgProc,
    dwInitParam: 0);
  return _ESI;
}

//------------------------------------------------------------------------------
// Address: 0x00454CDE
// Name: ?Start@CThread@@UAE_NIW4ThreadPriorityEnum_t@1@@Z_0
// Source: rtti_class
//------------------------------------------------------------------------------
// attributes: thunk
bool __thiscall CThread::Start(CThread *this, unsigned int a2, enum CThread::ThreadPriorityEnum_t a3)
{
  return __imp_?Start@CThread@@UAE_NIW4ThreadPriorityEnum_t@1@@Z(this, a2, a3);
}

//------------------------------------------------------------------------------
// Address: 0x00454CE4
// Name: ?Init@CThread@@MAE_NXZ_0
// Source: rtti_class
//------------------------------------------------------------------------------
// attributes: thunk
bool __thiscall CThread::Init(CThread *this)
{
  return __imp_?Init@CThread@@MAE_NXZ(this);
}

//------------------------------------------------------------------------------
// Address: 0x00454CEA
// Name: ?OnExit@CThread@@MAEXXZ_0
// Source: rtti_class
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CThread::OnExit(CThread *this)
{
  __imp_?OnExit@CThread@@MAEXXZ(this);
}

//------------------------------------------------------------------------------
// Address: 0x00454CF0
// Name: ?WaitForCreateComplete@CThread@@MAE_NPAVCThreadEvent@@@Z_0
// Source: rtti_class
//------------------------------------------------------------------------------
// attributes: thunk
bool __thiscall CThread::WaitForCreateComplete(CThread *this, struct CThreadEvent *a2)
{
  return __imp_?WaitForCreateComplete@CThread@@MAE_NPAVCThreadEvent@@@Z(this, a2);
}

//------------------------------------------------------------------------------
// Address: 0x00454CF6
// Name: ?GetThreadProc@CThread@@MAEP6GKPAX@ZXZ_0
// Source: rtti_class
//------------------------------------------------------------------------------
// attributes: thunk
unsigned int (__stdcall *__thiscall CThread::GetThreadProc(CThread *this))(void *)
{
  return __imp_?GetThreadProc@CThread@@MAEP6GKPAX@ZXZ(this);
}

//------------------------------------------------------------------------------
// Address: 0x00456850
// Name: public: void CByteswap::SwapBufferToTargetEndian<unsigned int>(unsigned int __near *,unsigned int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<unsigned int>(
        CByteswap *this,
        int *outputBuffer,
        int *inputBuffer,
        int count)
{
  int v4; // ebx
  int *v5; // edi
  int *v6; // eax
  char *v7; // esi
  char v8; // cl
  char v9; // dl
  char v10; // al
  char v11; // cl

  v4 = count;
  if ( count > 0 )
  {
    v5 = outputBuffer;
    if ( outputBuffer != nullptr )
    {
      v6 = inputBuffer;
      if ( inputBuffer == nullptr )
        v6 = outputBuffer;
      if ( (*(_BYTE *)this & 1) != 0 )
      {
        v7 = (char *)v6 + 2;
        do
        {
          v8 = v7[1];
          v9 = *v7;
          count = *v5;
          v10 = *(v7 - 1);
          BYTE1(count) = v9;
          LOBYTE(count) = v8;
          v11 = *(v7 - 2);
          BYTE2(count) = v10;
          HIBYTE(count) = v11;
          _V_memcpy(dest: v5++, src: &count, count: 4);
          v7 += 4;
          --v4;
        }
        while ( v4 != 0 );
      }
      else if ( v6 != nullptr && outputBuffer != v6 )
      {
        memcpy(dst: (unsigned __int8 *)outputBuffer, src: (unsigned __int8 *)v6, count: 4 * count);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045A7F0
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
// Address: 0x00475FA0
// Name: InfoChunks::_dynamic_initializer_for__g_arrChunks__
// Source: json
//------------------------------------------------------------------------------
int InfoChunks::_dynamic_initializer_for__g_arrChunks__()
{
  return atexit(func: InfoChunks::_dynamic_atexit_destructor_for__g_arrChunks__);
}

//------------------------------------------------------------------------------
// Address: 0x00475FB0
// Name: InfoChunks::_dynamic_initializer_for__g_arrPatches__
// Source: json
//------------------------------------------------------------------------------
int InfoChunks::_dynamic_initializer_for__g_arrPatches__()
{
  return atexit(func: InfoChunks::_dynamic_atexit_destructor_for__g_arrPatches__);
}

//------------------------------------------------------------------------------
// Address: 0x004760D0
// Name: InfoChunks::_dynamic_atexit_destructor_for__g_arrChunks__
// Source: json
//------------------------------------------------------------------------------
void __cdecl InfoChunks::_dynamic_atexit_destructor_for__g_arrChunks__()
{
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&InfoChunks::g_arrChunks);
}

//------------------------------------------------------------------------------
// Address: 0x004760E0
// Name: InfoChunks::_dynamic_atexit_destructor_for__g_arrPatches__
// Source: json
//------------------------------------------------------------------------------
void __cdecl InfoChunks::_dynamic_atexit_destructor_for__g_arrPatches__()
{
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&InfoChunks::g_arrPatches);
}

//------------------------------------------------------------------------------
// Address: 0x00409390
// Name: __realloc_crt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl _realloc_crt(void *ptr, unsigned int size)
{
  return _g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: ptr, a3: size);
}

//------------------------------------------------------------------------------
// Address: 0x004760F0
// Name: _dynamic_atexit_destructor_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ExpressionEvaluator__()
{
  CExpressionEvaluator::~CExpressionEvaluator(this: &g_ExpressionEvaluator);
}

//------------------------------------------------------------------------------
// Address: 0x00476100
// Name: _dynamic_atexit_destructor_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyConVar__()
{
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConVar::`vftable'{for `ConCommandBase'};
  s_EmptyConVar.ConVar::IConVar::__vftable = (IConVar_vtbl *)&ConVar::`vftable'{for `IConVar'};
  if ( s_EmptyConVar.m_Value.m_pszString != nullptr )
  {
    free(pMem: s_EmptyConVar.m_Value.m_pszString);
    s_EmptyConVar.m_Value.m_pszString = nullptr;
  }
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: &s_EmptyConVar.m_fnChangeCallbacks);
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConCommandBase::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x004772E8
// Name: isMMX$initializer$
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge isMMX_initializer_(CUtlMemory<char *,int> *this@<ecx>, int _EDI@<edi>, int a3, int a4)
{
  __asm { rcr     byte ptr [edi+47h], 0 }
  JUMPOUT(0x4772EC);
}

//------------------------------------------------------------------------------
// Address: 0x0047C384
// Name: client
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x0047C61C
// Name: PAD2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall PAD2(CUtlString *this, int a2)
{
  JUMPOUT(0x47C64C);
}

//------------------------------------------------------------------------------
// Address: 0x0047C64C
// Name: client_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x0047C650
// Name: server_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x0047D700
// Name: K512
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __fastcall K512(IBaseFileSystem *this, int a2, const char *a3, const char *a4)
{
  __outdword(a2, *(_BYTE *)(a2 - 51));
  __asm { iret }
  JUMPOUT(0x47D715);
}

//------------------------------------------------------------------------------
// Address: 0x0047D9B8
// Name: totrot
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge totrot(
        CDefaultAccessor *this@<ecx>,
        int a2@<eax>,
        _DWORD *a3@<edx>,
        _OWORD *a4@<ebx>,
        __int128 a5@<xmm2>,
        const CDefaultAccessor *a6)
{
  *a3 += a2;
  *(_BYTE *)a3 |= (unsigned __int8)this;
  *a4 = a5;
  JUMPOUT(0x47D9C8);
}

//------------------------------------------------------------------------------
// Address: 0x004904F8
// Name: sort_order_latin1_de
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall sort_order_latin1_de(
        int _EAX@<eax>,
        int a2@<edx>,
        unsigned __int8 *a3@<ecx>,
        _BYTE *a4@<ebx>,
        int a5@<ebp>,
        int a6@<edi>,
        int a7@<esi>)
{
  bool v8; // tt
  unsigned __int8 v9; // tt
  unsigned __int8 v10; // tt
  int v15; // ebp
  unsigned __int8 *v16; // esi
  unsigned __int8 *v17; // edi
  bool v18; // of
  int v19; // edi
  int v20; // edx
  int **v23; // [esp-34h] [ebp-34h] BYREF
  int v24; // [esp-30h] [ebp-30h]
  int v25; // [esp-2Ch] [ebp-2Ch]
  int v26; // [esp-28h] [ebp-28h]
  int v27; // [esp-24h] [ebp-24h]
  int v28; // [esp-20h] [ebp-20h]
  int v29; // [esp-1Ch] [ebp-1Ch]
  int **v30; // [esp-18h] [ebp-18h]
  int *v31; // [esp-14h] [ebp-14h] BYREF
  int v32; // [esp-10h] [ebp-10h]
  unsigned __int8 *v33; // [esp-Ch] [ebp-Ch]
  unsigned __int8 *v34; // [esp-8h] [ebp-8h]
  int v35; // [esp-4h] [ebp-4h] BYREF

  *a3 += _EAX;
  LOBYTE(_EAX) = *a4 + _EAX + 5;
  v35 = (unsigned __int16)__ES__;
  *a3 |= (unsigned __int8)a3;
  LOBYTE(a3) = *a4 | (unsigned __int8)a3;
  LOBYTE(_EAX) = _EAX | 0xD;
  v35 = (unsigned __int16)__CS__;
  _CF = __CFADD__(*a4, (_BYTE)a2);
  LOBYTE(a2) = *a4 + a2;
  v8 = _CF;
  _CF = __CFADD__(_CF, (_BYTE)_EAX);
  LOBYTE(_EAX) = v8 + _EAX;
  v34 = (unsigned __int8 *)(unsigned __int16)__SS__;
  v9 = (_CF | __CFADD__((_BYTE)_EAX, 21)) + (_BYTE)a4;
  _CF = *a3 < v9;
  *a3 -= v9;
  v10 = _CF + *a4;
  _CF = (unsigned __int8)a4 < v10;
  LOBYTE(a4) = (_BYTE)a4 - v10;
  v34 = (unsigned __int8 *)(unsigned __int16)__DS__;
  *a3 &= BYTE1(_EAX);
  BYTE1(_EAX) &= *a4;
  LOBYTE(_EAX) = (_EAX + 21 - (_CF + 29)) & 0x25;
  __asm { daa }
  *a3 -= BYTE1(a3);
  BYTE1(a3) -= *a4;
  LOBYTE(_EAX) = _EAX - 45;
  __asm { das }
  *a3 ^= BYTE1(a2);
  BYTE1(a2) ^= *a4;
  LOBYTE(_EAX) = _EAX ^ 0x35;
  __asm { aaa }
  __asm { aas }
  v34 = _EAX;
  v33 = a3;
  v32 = a2;
  v15 = v32;
  v16 = v33;
  v17 = v34;
  v34 = v33;
  v33 = v17;
  v31 = &v35;
  v30 = &v31;
  v29 = a7;
  v28 = a5;
  v27 = a6;
  v18 = __OFSUB__(++v17, 1);
  v19 = (int)(v17 - 1);
  v26 = a6 - 1;
  v25 = a7;
  v24 = a5;
  v23 = &v31;
  v20 = v32;
  if ( __SETP__(v19, 0) )
  {
    if ( v19 < 0 == v18 )
      JUMPOUT(0x4905F5);
    if ( !((v19 < 0) ^ v18 | (v19 == 0)) )
      JUMPOUT(0x4904F9);
    *(_DWORD *)(v32 - 2038070141) -= 1970698105;
    _EBX = v20;
    MEMORY[0x9EA7A68B](
      a1: *(_DWORD *)(v15 + 4 * (_DWORD)v16 - 1852797042),
      a2: (unsigned __int64)(__int16)v19 >> 32,
      a3: &v23,
      a4: v23,
      a5: v24,
      a6: v25,
      a7: v26,
      a8: v27,
      a9: v28,
      a10: v29,
      a11: v30,
      a12: v31);
    _EAX = MEMORY[0xA5A4A3A2];
    v16[5] = MEMORY[0xA5A4A3A2];
    *(_DWORD *)(v16 + 6) = _EAX;
    ++_EBX;
    _CF = *(_DWORD *)(v16 + 11) < *(_DWORD *)(v15 + 6);
    __asm { xlat }
  }
  JUMPOUT(0x4905F8);
}

//------------------------------------------------------------------------------
// Address: 0x004C0628
// Name: uctype_page00
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall uctype_page00@<eax>(_BYTE *a1@<eax>, _BYTE *a2@<edx>, _DWORD *a3@<ecx>)
{
  bool v3; // cf
  bool v4; // tt
  bool v5; // tt
  bool v6; // tt
  bool v7; // tt
  bool v8; // tt
  bool v9; // tt
  bool v10; // tt
  bool v11; // tt
  int v12; // et2
  bool v13; // tt
  bool v14; // tt
  bool v15; // tt
  bool v16; // tt
  bool v17; // tt
  bool v18; // tt
  bool v19; // tt
  bool v20; // tt
  bool v21; // tt
  bool v22; // tt
  _UNKNOWN *retaddr; // [esp+0h] [ebp+0h]

  *a1 &= BYTE1(a1);
  *a1 &= BYTE1(a1);
  *a1 &= BYTE1(a1);
  *a1 &= BYTE1(a1);
  *a1 &= BYTE1(a1);
  *a1 &= BYTE1(a1);
  *a1 &= BYTE1(a1);
  *a1 &= BYTE1(a1);
  *a1 &= BYTE1(a1);
  *a1 &= BYTE1(a1);
  *a1 &= BYTE1(a1);
  *a1 &= BYTE1(a1);
  *a1 &= BYTE1(a1);
  *a1 &= BYTE1(a1);
  *a1 &= BYTE1(a1);
  *a1 &= BYTE1(a1);
  *a1 |= (unsigned __int8)a2;
  v3 = __CFADD__((_BYTE)a2, *a1);
  *a1 += (_BYTE)a2;
  v4 = v3;
  v3 = __CFADD__(v3, *a1) | __CFADD__((_BYTE)a2, v3 + *a1);
  *a1 += (_BYTE)a2 + v4;
  v5 = v3;
  v3 = __CFADD__(v3, *a1) | __CFADD__((_BYTE)a2, v3 + *a1);
  *a1 += (_BYTE)a2 + v5;
  v6 = v3;
  v3 = __CFADD__(v3, *a1) | __CFADD__((_BYTE)a2, v3 + *a1);
  *a1 += (_BYTE)a2 + v6;
  v7 = v3;
  v3 = __CFADD__(v3, *a1) | __CFADD__((_BYTE)a2, v3 + *a1);
  *a1 += (_BYTE)a2 + v7;
  v8 = v3;
  v3 = __CFADD__(v3, *a1) | __CFADD__((_BYTE)a2, v3 + *a1);
  *a1 += (_BYTE)a2 + v8;
  *a1 += (_BYTE)a2 + v3;
  LOBYTE(a1) = (_BYTE)a1 + 16;
  v3 = __CFADD__((_BYTE)a1, 4);
  LOBYTE(a1) = (_BYTE)a1 + 4;
  v9 = v3;
  v3 = __CFADD__(v3, *a1) | __CFADD__((_BYTE)a2, v3 + *a1);
  *a1 += (_BYTE)a2 + v9;
  v10 = v3;
  v3 = __CFADD__(v3, *a1) | __CFADD__((_BYTE)a2, v3 + *a1);
  *a1 += (_BYTE)a2 + v10;
  v11 = v3;
  v3 = __CFADD__(v3, *a1) | __CFADD__((_BYTE)a2, v3 + *a1);
  *a1 += (_BYTE)a2 + v11;
  *((_BYTE *)a3 - 2122219135) += (_BYTE)a1 + v3;
  *(_DWORD *)((char *)a3 - 2122219135) -= 2122219135;
  v3 = __CFADD__(__PAIR64__(*(_DWORD *)a1, *(_DWORD *)((char *)a3 - 2122219135)), 0x1010101081818181LL);
  v12 = *(_DWORD *)((char *)a3 - 2122219135) - 2122219135;
  *(_DWORD *)a1 = (__PAIR64__(*(_DWORD *)a1, *(_DWORD *)((char *)a3 - 2122219135)) + 0x1010101081818181LL) >> 32;
  *(_DWORD *)((char *)a3 - 2122219135) = v12;
  *(a2 - 2105376126) += (_BYTE)a1 + v3;
  *(a2 - 2105376126) -= 126;
  *(a2 - 2105376126) -= 126;
  v3 = __CFADD__(*(a2 - 2105376126), -126);
  *(a2 - 2105376126) -= 126;
  v13 = v3;
  v3 = __CFADD__(v3, *a1) | __CFADD__((_BYTE)a2, v3 + *a1);
  *a1 += (_BYTE)a2 + v13;
  *a1 += (_BYTE)a2 + v3;
  *a1 &= BYTE1(a1);
  *a1 &= BYTE1(a1);
  *a1 &= BYTE1(a1);
  *a1 &= BYTE1(a1);
  *a1 &= BYTE1(a1);
  *a1 &= BYTE1(a1);
  *a1 &= BYTE1(a1);
  *a1 &= BYTE1(a1);
  *a1 &= BYTE1(a1);
  *a1 &= BYTE1(a1);
  *a1 &= BYTE1(a1);
  *a1 &= BYTE1(a1);
  *a1 &= BYTE1(a1);
  *a1 &= BYTE1(a1);
  *a1 &= BYTE1(a1);
  *a1 &= BYTE1(a1);
  *a1 &= (unsigned __int8)a3;
  v3 = __CFADD__((_BYTE)a2, *a1);
  *a1 += (_BYTE)a2;
  v14 = v3;
  v3 = __CFADD__(v3, *a1) | __CFADD__((_BYTE)a2, v3 + *a1);
  *a1 += (_BYTE)a2 + v14;
  v15 = v3;
  v3 = __CFADD__(v3, *a1) | __CFADD__((_BYTE)a2, v3 + *a1);
  *a1 += (_BYTE)a2 + v15;
  v16 = v3;
  v3 = __CFADD__(v3, *a1) | __CFADD__((_BYTE)a2, v3 + *a1);
  *a1 += (_BYTE)a2 + v16;
  v17 = v3;
  v3 = __CFADD__(v3, *a2) | __CFADD__((_BYTE)a1, v3 + *a2);
  *a2 += (_BYTE)a1 + v17;
  *a1 += (_BYTE)a2 + v3;
  *a1 &= (unsigned __int8)a2;
  v3 = __CFADD__((_BYTE)a2, *a1);
  *a1 += (_BYTE)a2;
  v18 = v3;
  v3 = __CFADD__(v3, *((_BYTE *)&retaddr + (_DWORD)a2)) | __CFADD__((_BYTE)a2, v3 + *((_BYTE *)&retaddr + (_DWORD)a2));
  *((_BYTE *)&retaddr + (_DWORD)a2) += (_BYTE)a2 + v18;
  v19 = v3;
  v3 = __CFADD__(v3, *a2) | __CFADD__((_BYTE)a1, v3 + *a2);
  *a2 += (_BYTE)a1 + v19;
  v20 = v3;
  v3 = __CFADD__(v3, *a1) | __CFADD__((_BYTE)a2, v3 + *a1);
  *a1 += (_BYTE)a2 + v20;
  v21 = v3;
  v3 = __CFADD__(v3, a1[(_DWORD)a2]) | __CFADD__((_BYTE)a2, v3 + a1[(_DWORD)a2]);
  a1[(_DWORD)a2] += (_BYTE)a2 + v21;
  v22 = v3;
  v3 = __CFADD__(v3, *((_BYTE *)&retaddr + (_DWORD)a2)) | __CFADD__((_BYTE)a2, v3 + *((_BYTE *)&retaddr + (_DWORD)a2));
  *((_BYTE *)&retaddr + (_DWORD)a2) += (_BYTE)a2 + v22;
  LOBYTE(a1) = v3 + (_BYTE)a1 + 16;
  *a3 += a1;
  *a3 += a1;
  *a3 += a1;
  *a3 += a1;
  *a3 += a1;
  *a3 += a1;
  *a3 += a1;
  *a3 += a1;
  *a3 += a1;
  *a3 += a1;
  *a3 += a1;
  *(_DWORD *)a1 += a2;
  *a3 += a1;
  *a3 += a1;
  *a3 += a1;
  *(_DWORD *)a2 += a1;
  return uctype_page01();
}

//------------------------------------------------------------------------------
// Address: 0x004C0728
// Name: uctype_page01
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall uctype_page01@<eax>(int a1@<eax>, _DWORD *a2@<edx>, _BYTE *a3@<ecx>)
{
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  LOBYTE(a1) = *(_BYTE *)a2 + *a3 + *a3 + *a3 + *a3 + *a3 + *a3 + *a3 + *a3 + a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *(_DWORD *)a3 += a1;
  LOBYTE(a1) = *a3 + *(_BYTE *)a2 + *a3 + *a3 + a1;
  *a2 += a1;
  *a2 += a1;
  *(_DWORD *)a3 += a1;
  LOBYTE(a1) = *a3 + a1;
  *(_DWORD *)a3 += a1;
  LOBYTE(a1) = *(_BYTE *)a2 + a1;
  *(_DWORD *)a3 += a1;
  *(_DWORD *)a3 += a1;
  LOBYTE(a1) = *a3 + a1;
  *a2 += a1;
  *(_DWORD *)a3 += a1;
  *a2 += a1;
  LOBYTE(a1) = *(_BYTE *)a2 + a1;
  *(_DWORD *)a3 += a1;
  LOBYTE(a1) = *a3 + a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *(_DWORD *)a3 += a1;
  LOBYTE(a1) = *(_BYTE *)a2 + *a3 + a1;
  *a2 += a1;
  *(_DWORD *)a3 += a1;
  LOBYTE(a1) = *a3 + a1;
  *(_DWORD *)a3 += a1;
  LOBYTE(a1) = *a3 + *a3 + a1;
  *a2 += a1;
  LOBYTE(a1) = *(_BYTE *)a2 + a1;
  *a2 += a1;
  LOBYTE(a1) = *(_BYTE *)a2 + *(_BYTE *)a2 + *(_BYTE *)a2 + a1;
  *(_DWORD *)a3 += a1;
  LOBYTE(a1) = *a3 + a1;
  *a2 += a1;
  *(_DWORD *)a3 += a1;
  LOBYTE(a1) = *(_BYTE *)a2 + *a3 + *a3 + *a3 + *a3 + *a3 + *a3 + *a3 + *a3 + a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  LOBYTE(a1) = *a3 + a1;
  *a2 += a1;
  *a2 += a1;
  *(_DWORD *)a3 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  return uctype_page02();
}

//------------------------------------------------------------------------------
// Address: 0x004C0828
// Name: uctype_page02
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall uctype_page02(_BYTE *a1@<eax>, _BYTE *a2@<edx>, _DWORD *a3@<ecx>)
{
  bool v3; // cf
  bool v4; // tt
  bool v5; // tt
  bool v6; // tt
  bool v7; // tt
  bool v8; // tt
  bool v9; // tt
  bool v10; // tt
  char v11; // dl
  bool v12; // tt
  bool v13; // tt
  bool v14; // tt
  char v15; // dl
  bool v16; // tt
  bool v17; // tt
  bool v18; // tt
  bool v19; // tt
  bool v20; // tt
  bool v21; // tt
  bool v22; // tt

  *(_DWORD *)a2 += a1;
  *(_DWORD *)a2 += a1;
  *(_DWORD *)a2 += a1;
  *(_DWORD *)a2 += a1;
  *(_DWORD *)a2 += a1;
  *(_DWORD *)a2 += a1;
  *(_DWORD *)a2 += a1;
  *(_DWORD *)a2 += a1;
  *(_DWORD *)a2 += a1;
  *(_DWORD *)a2 += a1;
  *(_DWORD *)a2 += a1;
  *(_DWORD *)a2 += a1;
  *(_DWORD *)a2 += a1;
  *(_DWORD *)a2 += a1;
  *(_DWORD *)a2 += a1;
  *(_DWORD *)a2 += a1;
  *(_DWORD *)a2 += a1;
  *(_DWORD *)a2 += a1;
  *(_DWORD *)a2 += a1;
  *(_DWORD *)a2 += a1;
  *(_DWORD *)a2 += a1;
  *(_DWORD *)a2 += a1;
  *(_DWORD *)a2 += a1;
  *(_DWORD *)a2 += a1;
  *(_DWORD *)a2 += a1;
  *(_DWORD *)a2 += a1;
  LOBYTE(a1) = *a2 + *a2 + *a2 + (_BYTE)a1;
  *a3 += a1;
  LOBYTE(a1) = *(_BYTE *)a3 + (_BYTE)a1;
  *(_DWORD *)a2 += a1;
  LOBYTE(a1) = *(_BYTE *)a3 + *(_BYTE *)a3 + (_BYTE)a1;
  *a3 += a1;
  *(_DWORD *)a2 += a1;
  *(_DWORD *)a2 += a1;
  *(_DWORD *)a2 += a1;
  *(_DWORD *)a2 += a1;
  *(_DWORD *)a2 += a1;
  LOBYTE(a1) = *a2
             + *a2
             + *a2
             + *a2
             + *a2
             + *a2
             + *a2
             + *a2
             + *a2
             + *a2
             + *a2
             + *a2
             + *a2
             + *a2
             + *a2
             + *a2
             + *a2
             + *a2
             + *a2
             + *a2
             + *a2
             + *a2
             + *a2
             + *a2
             + *a2
             + *a2
             + *a2
             + *a2
             + *a2
             + *a2
             + *a2
             + *a2
             + *a2
             + *a2
             + *a2
             + *a2
             + *a2
             + *a2
             + *a2
             + *a2
             + *a2
             + *a2
             + *a2
             + *a2
             + *a2
             + *a2
             + *a2
             + *a2
             + *a2
             + *a2
             + *a2
             + *a2
             + *a2
             + *a2
             + *a2
             + *a2
             + (_BYTE)a1;
  v3 = __CFADD__(*a2, (_BYTE)a1);
  LOBYTE(a1) = *a2 + (_BYTE)a1;
  v4 = v3;
  v3 = __CFADD__(v3, *a1) | __CFADD__((_BYTE)a2, v3 + *a1);
  *a1 += (_BYTE)a2 + v4;
  *a1 += (_BYTE)a2 + v3;
  LOBYTE(a1) = *a2 + *a2 + *a2 + *a2 + *a2 + (_BYTE)a1;
  v3 = __CFADD__(*a2, (_BYTE)a1);
  LOBYTE(a1) = *a2 + (_BYTE)a1;
  v5 = v3;
  v3 = __CFADD__(v3, *a1) | __CFADD__((_BYTE)a2, v3 + *a1);
  *a1 += (_BYTE)a2 + v5;
  v6 = v3;
  v3 = __CFADD__(v3, *a1) | __CFADD__((_BYTE)a2, v3 + *a1);
  *a1 += (_BYTE)a2 + v6;
  v7 = v3;
  v3 = __CFADD__(v3, *a1) | __CFADD__((_BYTE)a2, v3 + *a1);
  *a1 += (_BYTE)a2 + v7;
  v8 = v3;
  v3 = __CFADD__(v3, *a1) | __CFADD__((_BYTE)a2, v3 + *a1);
  *a1 += (_BYTE)a2 + v8;
  v9 = v3;
  v3 = __CFADD__(v3, *a1) | __CFADD__((_BYTE)a2, v3 + *a1);
  *a1 += (_BYTE)a2 + v9;
  v10 = v3;
  v3 = __CFADD__(v3, *a1) | __CFADD__((_BYTE)a2, v3 + *a1);
  *a1 += (_BYTE)a2 + v10;
  *a1 += (_BYTE)a2 + v3;
  LOBYTE(a1) = *a2 + *a2 + (_BYTE)a1;
  v3 = __CFADD__(*a1, (_BYTE)a2);
  v11 = *a1 + (_BYTE)a2;
  v12 = v3;
  v3 = __CFADD__(v3, *a1) | __CFADD__(v11, v3 + *a1);
  *a1 += v11 + v12;
  v13 = v3;
  v3 = __CFADD__(v3, *a1) | __CFADD__(v11, v3 + *a1);
  *a1 += v11 + v13;
  v14 = v3;
  v3 = __CFADD__(v3, *a1) | __CFADD__(v11, v3 + *a1);
  *a1 += v11 + v14;
  *a1 += v11 + v3;
  v3 = __CFADD__(*a1, v11);
  v15 = *a1 + v11;
  v16 = v3;
  v3 = __CFADD__(v3, *a1) | __CFADD__(v15, v3 + *a1);
  *a1 += v15 + v16;
  v17 = v3;
  v3 = __CFADD__(v3, *a1) | __CFADD__(v15, v3 + *a1);
  *a1 += v15 + v17;
  v18 = v3;
  v3 = __CFADD__(v3, *a1) | __CFADD__(v15, v3 + *a1);
  *a1 += v15 + v18;
  v19 = v3;
  v3 = __CFADD__(v3, *a1) | __CFADD__(v15, v3 + *a1);
  *a1 += v15 + v19;
  v20 = v3;
  v3 = __CFADD__(v3, *a1) | __CFADD__(v15, v3 + *a1);
  *a1 += v15 + v20;
  v21 = v3;
  v3 = __CFADD__(v3, *a1) | __CFADD__(v15, v3 + *a1);
  *a1 += v15 + v21;
  v22 = v3;
  v3 = __CFADD__(v3, *a1) | __CFADD__(v15, v3 + *a1);
  *a1 += v15 + v22;
  *a1 += v15 + v3;
  JUMPOUT(0x4C0928);
}

//------------------------------------------------------------------------------
// Address: 0x004C0A28
// Name: uctype_page04
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall uctype_page04(char *a1@<eax>, _DWORD *a2@<edx>, _DWORD *a3@<ecx>)
{
  bool v3; // cf
  bool v4; // tt
  char v5; // t1
  bool v6; // tt
  char v7; // t1
  bool v8; // tt

  *a3 += a1;
  *a3 += a1;
  *a3 += a1;
  *a3 += a1;
  *a3 += a1;
  *a3 += a1;
  *a3 += a1;
  *a3 += a1;
  *a3 += a1;
  *a3 += a1;
  *a3 += a1;
  *a3 += a1;
  *a3 += a1;
  *a3 += a1;
  *a3 += a1;
  *a3 += a1;
  *a3 += a1;
  *a3 += a1;
  *a3 += a1;
  *a3 += a1;
  *a3 += a1;
  *a3 += a1;
  *a3 += a1;
  *a3 += a1;
  LOBYTE(a1) = *(_BYTE *)a2
             + *(_BYTE *)a2
             + *(_BYTE *)a2
             + *(_BYTE *)a2
             + *(_BYTE *)a2
             + *(_BYTE *)a2
             + *(_BYTE *)a2
             + *(_BYTE *)a2
             + *(_BYTE *)a2
             + *(_BYTE *)a2
             + *(_BYTE *)a2
             + *(_BYTE *)a2
             + *(_BYTE *)a2
             + *(_BYTE *)a2
             + *(_BYTE *)a2
             + *(_BYTE *)a2
             + *(_BYTE *)a2
             + *(_BYTE *)a2
             + *(_BYTE *)a2
             + *(_BYTE *)a2
             + *(_BYTE *)a2
             + *(_BYTE *)a2
             + *(_BYTE *)a2
             + *(_BYTE *)a2
             + (_BYTE)a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  v3 = __CFADD__(a1, *a2);
  *a2 += a1;
  v4 = v3;
  v3 = __CFADD__(v3, *(_BYTE *)a2) | __CFADD__((_BYTE)a2, v3 + *(_BYTE *)a2);
  *(_BYTE *)a2 += (_BYTE)a2 + v4;
  v5 = *(_BYTE *)a2;
  v6 = v3;
  v3 = __CFADD__(v3, (_BYTE)a2);
  LOBYTE(a2) = v6 + (_BYTE)a2;
  v3 |= __CFADD__(v5, (_BYTE)a2);
  LOBYTE(a2) = v5 + (_BYTE)a2;
  v7 = *a1;
  v8 = v3;
  v3 = __CFADD__(v3, (_BYTE)a1);
  LOBYTE(a1) = v8 + (_BYTE)a1;
  v3 |= __CFADD__(v7, (_BYTE)a1);
  LOBYTE(a1) = v7 + (_BYTE)a1;
  LOBYTE(a2) = *(_BYTE *)a2 + v3 + (_BYTE)a2;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a3 += a1;
  LOBYTE(a1) = *(_BYTE *)a2
             + *(_BYTE *)a3
             + *(_BYTE *)a3
             + *(_BYTE *)a3
             + *(_BYTE *)a3
             + *(_BYTE *)a3
             + *(_BYTE *)a3
             + (_BYTE)a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  *a2 += a1;
  JUMPOUT(0x4C0B28);
}

//------------------------------------------------------------------------------
// Address: 0x004C1928
// Name: uctype_page14
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall uctype_page14(char a1@<al>, _BYTE *a2@<edx>)
{
  *a2 += a1;
  JUMPOUT(0x4C1A28);
}

//------------------------------------------------------------------------------
// Address: 0x004C6828
// Name: plane05
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __userpurge plane05@<eax>(
        DName *this@<ecx>,
        int a2@<eax>,
        int a3@<edx>,
        int a4@<ebp>,
        int a5@<edi>,
        int a6@<esi>,
        DName *result,
        const DName *a8,
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
        int a48,
        int a49,
        int a50,
        int a51,
        int a52,
        int a53,
        int a54,
        int a55,
        int a56,
        int a57,
        int a58,
        int a59,
        int a60,
        int a61,
        int a62,
        int a63,
        int a64)
{
  int v64; // eax
  int v65; // eax
  int v66; // eax
  bool v67; // cf
  bool v68; // tt
  BOOL v69; // ett
  int v70; // eax
  int v71; // ett
  unsigned int v72; // eax
  unsigned int v73; // ett
  unsigned int v74; // eax
  unsigned int v75; // ett
  int v76; // eax
  int v77; // eax
  int v79; // eax
  int v81; // eax
  DName *v85; // esi
  int v86; // eax
  DName *v87; // edi
  int v88; // eax
  __int32 v91; // eax
  DName *v92; // eax
  int v93; // esi
  int v94; // et2
  int v95; // eax
  unsigned int v96; // kr00_4
  char v97; // fl
  _DWORD v99[8]; // [esp-34h] [ebp-34h] BYREF
  _DWORD v100[2]; // [esp-14h] [ebp-14h] BYREF
  DName *v101; // [esp-Ch] [ebp-Ch]
  DName *v102; // [esp-8h] [ebp-8h]
  int v103; // [esp-4h] [ebp-4h] BYREF

  MEMORY[0x5000500] += a2;
  MEMORY[0x5010501] += a2;
  LOBYTE(a2) = MEMORY[0x5020502] + a2;
  v64 = MEMORY[0x5030503] + a2;
  LOBYTE(v64) = v64 + 15;
  v64 += 337253402;
  MEMORY[0x5090509] |= v64;
  MEMORY[0x50A050A] |= v64;
  LOBYTE(v64) = MEMORY[0x50B050B] | v64;
  v65 = MEMORY[0x50C050C] | v64;
  LOBYTE(v65) = v65 | 5;
  v66 = (v65 | 0xD050D05) + 84804878;
  v103 = (unsigned __int16)__CS__;
  v67 = __CFADD__(v66, 84870415);
  v66 += 84870415;
  __asm { syscall; Low latency system call }
  v68 = v67;
  v67 = __CFADD__(v67, MEMORY[0x5100510]) | __CFADD__((_BYTE)v66, v67 + MEMORY[0x5100510]);
  MEMORY[0x5100510] += v66 + v68;
  v69 = v67;
  v67 = __CFADD__(v67, MEMORY[0x5110511]) | __CFADD__(v66, v67 + MEMORY[0x5110511]);
  MEMORY[0x5110511] += v66 + v69;
  LOBYTE(v69) = v67;
  v67 = __CFADD__(v67, (_BYTE)v66);
  LOBYTE(v66) = v69 + v66;
  v67 |= __CFADD__(MEMORY[0x5120512], (_BYTE)v66);
  LOBYTE(v66) = MEMORY[0x5120512] + v66;
  v71 = v67;
  v67 = __CFADD__(v67, v66);
  v70 = v71 + v66;
  v67 |= __CFADD__(MEMORY[0x5130513], v70);
  v70 += MEMORY[0x5130513];
  LOBYTE(v71) = v67;
  v67 = __CFADD__(v67, (_BYTE)v70);
  LOBYTE(v70) = v71 + v70;
  v67 |= __CFADD__((_BYTE)v70, 5);
  LOBYTE(v70) = v70 + 5;
  LOBYTE(v71) = v67;
  v67 = __CFADD__(v67, (_BYTE)v70);
  LOBYTE(v70) = v71 + v70;
  v67 |= __CFADD__((_BYTE)v70, 5);
  LOBYTE(v70) = v70 + 5;
  LOBYTE(v71) = v67;
  v67 = __CFADD__(v67, (_BYTE)v70);
  LOBYTE(v70) = v71 + v70;
  v67 |= __CFADD__((_BYTE)v70, 5);
  LOBYTE(v70) = v70 + 5;
  v72 = v67 + v70 + 523378482;
  v67 = __CFADD__(v72, 85460248);
  v72 += 85460248;
  LOBYTE(v71) = v67 + v72;
  v67 = MEMORY[0x5190519] < (unsigned __int8)(v67 + v72);
  MEMORY[0x5190519] -= v71;
  v73 = v67 + v72;
  v67 = MEMORY[0x51A051A] < v73;
  MEMORY[0x51A051A] -= v73;
  LOBYTE(v73) = v67 + MEMORY[0x51B051B];
  v67 = (unsigned __int8)v72 < (unsigned __int8)(v67 + MEMORY[0x51B051B]);
  LOBYTE(v72) = v72 - v73;
  v75 = v67 + MEMORY[0x51C051C];
  v67 = v72 < v75;
  v74 = v72 - v75;
  LOBYTE(v75) = v67 + 5;
  v67 = (unsigned __int8)v74 < (unsigned __int8)(v67 + 5);
  LOBYTE(v74) = v74 - v75;
  v76 = v74 - (v67 + 486874373) + 257757021;
  MEMORY[0x5210521] &= v76;
  MEMORY[0x5220522] &= v76;
  LOBYTE(v76) = MEMORY[0x5230523] & v76;
  v77 = MEMORY[0x5240524] & v76;
  LOBYTE(v77) = v77 & 5;
  _EAX = (v77 & 0x25052505) + 172821069;
  __asm { daa }
  _EAX += 86508840;
  MEMORY[0x5290529] -= _EAX;
  MEMORY[0x52A052A] -= _EAX;
  LOBYTE(_EAX) = _EAX - MEMORY[0x52B052B];
  v79 = _EAX - MEMORY[0x52C052C];
  LOBYTE(v79) = v79 - 5;
  _EAX = v79 - 755313925 + 173869661;
  __asm { das }
  _EAX += 87033136;
  MEMORY[0x5610531] ^= _EAX;
  MEMORY[0x5620532] ^= _EAX;
  LOBYTE(_EAX) = MEMORY[0x5630533] ^ _EAX;
  v81 = MEMORY[0x5640534] ^ _EAX;
  LOBYTE(v81) = v81 ^ 5;
  _EAX = (v81 ^ 0x35056505) + 181209709;
  __asm { aaa }
  _EAX += 272961461;
  __asm { aas }
  v102 = _EAX + 194972473;
  v101 = this;
  v100[1] = a3;
  v85 = v101;
  v86 = a5 + 629417348;
  v87 = v102;
  v102 = v101;
  v101 = v87;
  v100[0] = &v103;
  v99[7] = v100;
  v99[6] = a6;
  v99[5] = a4;
  v99[4] = v86 + 90178912;
  v86 += 180423313;
  MEMORY[0x5620532] ^= v86;
  LOBYTE(v86) = MEMORY[0x5630533] ^ v86;
  v88 = MEMORY[0x5640534] ^ v86;
  LOBYTE(v88) = v88 ^ 5;
  _EAX = (v88 ^ 0x35056505) + 181209709;
  __asm { aaa }
  _EAX += 272961461;
  __asm { aas }
  v99[3] = _EAX + 1559779784;
  v99[2] = a6;
  v99[1] = a4;
  v99[0] = v100;
  v91 = _InterlockedExchange((volatile __int32 *)0x5880588, _EAX - 2087420092);
  MEMORY[0x5890589] = v91;
  MEMORY[0x58A058A] = v91;
  MEMORY[0x58D058D] = __ES__;
  __ES__ = MEMORY[0x58F058F];
  MEMORY[0x5900590] = v85;
  v92 = v85;
  v93 = a3 + 93717910;
  v94 = (int)&v92[11722930] + 7;
  v95 = MEMORY[0x9B0F4B55](a1: 186583839, a2: ((__int16)((_WORD)v87 + 1432) + 93914521) >> 31, a3, a4: v99);
  v96 = __readeflags();
  __writeeflags(v96);
  v95 += 376837750;
  BYTE1(v95) = v97;
  v95 += 94373280;
  LOBYTE(v95) = MEMORY[0xA105A105];
  v95 += 94504353;
  MEMORY[0xA305A205] = v95;
  *(_BYTE *)v94 = *(_BYTE *)v93;
  *(_DWORD *)(v94 + 1) = *(_DWORD *)(v93 + 1);
  v95 += 568533475;
  *(_BYTE *)(v94 + 10) = v95;
  *(_DWORD *)(v94 + 11) = v95 + 95094187;
  MEMORY[0x5C105C0] = __ROL1__(MEMORY[0x5C105C0], 193);
  return -629810574;
}

//------------------------------------------------------------------------------
// Address: 0x004C8628
// Name: planeFF
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__userpurge planeFF@<eax>(
        DName *this@<ecx>,
        int a2@<eax>,
        _DWORD *a3@<edx>,
        int a4@<ebx>,
        int a5@<edi>,
        int a6@<esi>,
        DName *result,
        const DName *a8)
{
  int v8; // edi
  unsigned int v9; // eax
  int (**v10)(void); // eax
  void (**v11)(void); // eax
  void (**v12)(void); // ecx
  void (**v13)(void); // ecx
  void (**v14)(void); // ecx
  void (**v15)(void); // edx
  void (**v16)(void); // edx
  void (**v17)(void); // edx
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // ecx
  int v22; // ecx
  int v23; // ecx
  int v24; // edx
  int v25; // edx
  int v26; // edx
  DName *(__stdcall **v27)(DName *, const DName *); // eax

  BYTE1(a4) <<= 6;
  v8 = a5 << 6;
  LOBYTE(a2) = a2 - 3;
  v9 = a2 + 100599295;
  ++*(_DWORD *)a6;
  ++*(_DWORD *)a6;
  ++*(_DWORD *)a6;
  ++*(_DWORD *)v8;
  ++*(_DWORD *)v8;
  ++*(_DWORD *)v8;
  --*(_DWORD *)v9;
  --*(_DWORD *)v9;
  --*(_DWORD *)v9;
  --this->node;
  --this->node;
  --this->node;
  --*a3;
  --*a3;
  --*a3;
  --*(_DWORD *)a4;
  --*(_DWORD *)a4;
  --*(_DWORD *)a4;
  --*(_DWORD *)(9 * v8);
  LOBYTE(v9) = -1;
  --*(_DWORD *)a6;
  --*(_DWORD *)a6;
  --*(_DWORD *)a6;
  --*(_DWORD *)v8;
  --*(_DWORD *)v8;
  --*(_DWORD *)v8;
  v10 = (int (**)(void))(*(int (**)(void))(v9 | 0xDFF0DFF))();
  v11 = (void (**)(void))(*v10)();
  (*v11)();
  (*v12)();
  (*v13)();
  (*v14)();
  (*v15)();
  (*v16)();
  (*v17)();
  (*(void (**)(void))a4)();
  (*(void (**)(void))a4)();
  (*(void (**)(void))a4)();
  (*(void (**)(void))(9 * v8))();
  (*(void (**)(void))a6)();
  (*(void (**)(void))a6)();
  (*(void (**)(void))a6)();
  (*(void (**)(void))v8)();
  (*(void (**)(void))v8)();
  v18 = (*(int (**)(void))v8)();
  v19 = MK_FP(*(_WORD *)(v18 + 4), *(_DWORD *)v18)();
  v20 = MK_FP(*(_WORD *)(v19 + 4), *(_DWORD *)v19)();
  MK_FP(*(_WORD *)(v20 + 4), *(_DWORD *)v20)();
  MK_FP(*(_WORD *)(v21 + 4), *(_DWORD *)v21)();
  MK_FP(*(_WORD *)(v22 + 4), *(_DWORD *)v22)();
  MK_FP(*(_WORD *)(v23 + 4), *(_DWORD *)v23)();
  MK_FP(*(_WORD *)(v24 + 4), *(_DWORD *)v24)();
  MK_FP(*(_WORD *)(v25 + 4), *(_DWORD *)v25)();
  MK_FP(*(_WORD *)(v26 + 4), *(_DWORD *)v26)();
  MK_FP(*(_WORD *)(a4 + 4), *(_DWORD *)a4)();
  MK_FP(*(_WORD *)(a4 + 4), *(_DWORD *)a4)();
  MK_FP(*(_WORD *)(a4 + 4), *(_DWORD *)a4)();
  MK_FP(*(_WORD *)(9 * v8 + 4), *(_DWORD *)(9 * v8))();
  MK_FP(*(_WORD *)(a6 + 4), *(_DWORD *)a6)();
  MK_FP(*(_WORD *)(a6 + 4), *(_DWORD *)a6)();
  MK_FP(*(_WORD *)(a6 + 4), *(_DWORD *)a6)();
  MK_FP(*(_WORD *)(v8 + 4), *(_DWORD *)v8)();
  MK_FP(*(_WORD *)(v8 + 4), *(_DWORD *)v8)();
  v27 = (DName *(__stdcall **)(DName *, const DName *))MK_FP(*(_WORD *)(v8 + 4), *(_DWORD *)v8)();
  return (*v27)(a1: result, a2: a8);
}

//------------------------------------------------------------------------------
// Address: 0x004CDCE0
// Name: uni_1E00_1FFF
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge uni_1E00_1FFF(
        DName *this@<ecx>,
        bool a2@<cf>,
        int a3@<eax>,
        int _EDX@<edx>,
        int a5@<ebx>,
        int a6@<ebp>,
        int a7@<edi>,
        int _ESI@<esi>,
        DName *a9)
{
  int v9; // ebp
  unsigned int v10; // ecx
  int v11; // eax
  int v15; // ebx
  int v16; // edi
  int v18; // edi
  _WORD v20[8]; // [esp-24h] [ebp-24h] BYREF
  int v21; // [esp-14h] [ebp-14h]

  __asm { insb }
  __asm { insb }
  *(_DWORD *)(a7 + a3 + 135008700) += a7 + a2;
  *(_BYTE *)(2 * _EDX - 84) |= a5;
  *(_BYTE *)(2 * _EDX + 0x12FC08FC) |= BYTE1(this);
  *(_DWORD *)(a5 + _EDX - 100) |= (unsigned int)this;
  *(_DWORD *)(a5 + _EDX + 334236140) |= a5;
  *(_WORD *)_EDX = __CS__;
  v20[4 * a5] = __SS__;
  LOBYTE(a5) = BYTE1(a3) | a5;
  LOBYTE(a3) = (a3 | 0x12) + 44;
  v9 = *(_DWORD *)(_EDX + 360450940) | a6;
  __debugbreak();
  v10 = (unsigned int)v20 | (unsigned int)this;
  v11 = a3 + 370936860;
  __asm { insb }
  LOBYTE(v11) = v11 | 0x6C;
  v11 |= 0xD5C170Cu;
  __SS__ = v20[0];
  __asm { insd }
  __asm { insd }
  *MK_FP(v20[0], v9 + 219266311) = a7 + *MK_FP(v20[0], v9 + 219266311);
  MEMORY[0x5D085D12] |= v10;
  a2 = __CFADD__(*(_BYTE *)(v9 + 9), (_BYTE)v10);
  LOBYTE(v10) = *(_BYTE *)(v9 + 9) + v10;
  v15 = *(_DWORD *)(--v9 - 317481719) + a2 + a5;
  v16 = MEMORY[0x8D143D0A] + a7;
  LOBYTE(v10) = *(_BYTE *)(v9 - 586490604) | v10;
  LOBYTE(v11) = v11 + 45;
  __SS__ = v20[4];
  __asm { outsb }
  __asm { outsb }
  *(_DWORD *)(_ESI + 236043783) += v16;
  *(_BYTE *)_ESI |= v10;
  LOBYTE(v15) = *(_BYTE *)(_ESI + 8) + v15;
  HIBYTE(_DX) |= BYTE1(v15);
  a2 = __CFADD__(*(_BYTE *)(v21 + 9), (_BYTE)v10);
  LOBYTE(v10) = *(_BYTE *)(v21 + 9) + v10;
  _ESI = (_DWORD *)(v21 - 1);
  a2 = __CFADD__(a2, v15) | __CFADD__(*(_DWORD *)(v21 - 1 + 1880333833), a2 + v15);
  __outbyte(_DX, (v11 - 51 - (__CFADD__(v11, 365759437) + 12)) | 0x6D);
  v18 = *_ESI + a2 + v16;
  __asm { into }
  LOBYTE(v10) = (unsigned __int8)_ESI | *((_BYTE *)_ESI - 569713132) | v10;
  __asm { outsb }
  _ESI = (unsigned __int16)__SS__;
  __asm { outsd }
  __asm { outsd }
  *(_DWORD *)(v18 + 252821255) += v18;
  *(_BYTE *)v18 |= v10;
  __asm { iret }
  JUMPOUT(0x4CDE09);
}

//------------------------------------------------------------------------------
// Address: 0x004E9964
// Name: tab_jisx0212_uni3
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge tab_jisx0212_uni3(
        DName *this@<ecx>,
        int a2@<eax>,
        int a3@<ebx>,
        int a4@<ebp>,
        int a5@<edi>,
        int _ESI@<esi>,
        DNameNode *a7)
{
  bool v7; // cf
  bool v8; // zf
  int v9; // ecx
  int v11; // ecx
  int v13; // eax
  int v14; // et1
  bool v15; // of
  int v19; // [esp-8h] [ebp-8h]
  __int16 v20; // [esp-4h] [ebp-4h]

  LOBYTE(a2) = *(_BYTE *)(a3 + a2) + a2 + 101;
  v7 = __CFADD__(BYTE1(a3), *(_BYTE *)(a2 - 661574256));
  v8 = BYTE1(a3) + *(_BYTE *)(a2 - 661574256) == 0;
  *(_BYTE *)(a2 - 661574256) += BYTE1(a3);
  v9 = a2;
  __indword(0x6Cu);
  _EAX = (unsigned __int16)__CS__;
  v11 = v9 - 1;
  if ( v11 == 0 )
  {
    if ( v8 )
      __halt();
    JUMPOUT(0x4E99F5);
  }
  while ( 1 )
  {
    __DS__ = v20;
    v20 = a5;
    if ( v8 )
      break;
    BYTE1(_EAX) += *(_BYTE *)(_EAX + 18) + v7;
    do
    {
      _DX = _EAX;
      v19 = v11;
      ++_ESI;
      __asm { int     51h }
      *(_BYTE *)(_EAX + 16) += _EAX;
      v13 = v11;
      v11 = a5;
      v14 = v13;
      _EAX = a4;
      a4 = v14;
      v15 = __OFSUB__(-*(_BYTE *)(v19 + 4 * a5 + 93), 1);
      v7 = *(_BYTE *)(v19 + 4 * a5 + 93) != 0;
      *(_BYTE *)(v19 + 4 * a5 + 93) = -*(_BYTE *)(v19 + 4 * a5 + 93);
      if ( !v15 )
        JUMPOUT(0x4E9A7F);
      v8 = v19 == -1;
      _EBX = v19 + 1;
      __asm { xlat }
    }
    while ( v7 || v19 == -1 );
    __asm
    {
      insd
      outsd
      outsb
    }
    __asm
    {
      insd
      outsd
    }
    if ( !__OFADD__(1, v19) )
      JUMPOUT(0x4E9A7E);
    _ESI = 1759471804;
  }
  JUMPOUT(0x4E9A4F);
}

//------------------------------------------------------------------------------
// Address: 0x004E9A3C
// Name: tab_jisx0212_uni4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge __noreturn tab_jisx0212_uni4(
        DName *this@<ecx>,
        char a2@<ah>,
        int a3@<edx>,
        int a4@<ebx>,
        int a5@<ebp>,
        int a6@<esi>,
        DNameNode *a7)
{
  char v7; // zf
  char v8; // sf
  __int16 v11; // [esp-1Ch] [ebp-1Ch]

  *(_BYTE *)(a4 - 124) += a2;
  if ( !(v8 ^ ((unsigned __int64)(-1941533948LL * *(int *)(a5 - 1978759708)) >> 32 != 0) | v7) )
  {
    *(_DWORD *)(3 * a6 + 0x30982D96) -= ((unsigned __int64)(-1941533948LL * *(int *)(a5 - 1978759708)) >> 32 != 0) + a3;
    MEMORY[0x50D2C328](a1: a3);
    _DX = v11;
    __asm { insd }
    __indword(0x7Au);
    __halt();
  }
  JUMPOUT(0x905E2A6D);
}

//------------------------------------------------------------------------------
// Address: 0x004EA0E6
// Name: nullsub_10
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int nullsub_10()
{
  _BYTE retaddr[8]; // [esp+0h] [ebp+0h]

  return MK_FP(*(_WORD *)retaddr, *(_DWORD *)retaddr)();
}

//------------------------------------------------------------------------------
// Address: 0x004EA140
// Name: tab_jisx0208_uni39
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
char *__userpurge tab_jisx0208_uni39@<eax>(
        charNode *this@<ecx>,
        unsigned __int8 a2@<al>,
        int a3@<edx>,
        int _ESI@<esi>,
        char *a5,
        char *a6,
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
        int a48,
        int a49,
        int a50,
        int a51,
        int a52,
        int a53,
        int a54,
        int a55,
        int a56,
        int a57,
        int a58,
        int a59,
        int a60,
        int a61,
        int a62,
        int a63,
        int a64)
{
  char v64; // of
  _BYTE retaddr[8]; // [esp+0h] [ebp+0h] BYREF

  __outbyte(a3, a2);
  __asm { outsd }
  *(_DWORD *)(a3 - 118) >>= (char)this;
  if ( v64 )
    return (char *)nullsub_10();
  else
    return MK_FP(*(_WORD *)retaddr, *(_DWORD *)retaddr)(a1: (char *)&this->__vftable + 1, a2: retaddr);
}

//------------------------------------------------------------------------------
// Address: 0x00503F58
// Name: pl0E
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __userpurge pl0E@<eax>(
        int a1@<eax>,
        int a2@<ecx>,
        int a3@<edi>,
        int a4,
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
        int a48,
        int a49,
        int a50,
        int a51,
        int a52,
        int a53,
        int a54,
        int a55,
        int a56,
        int a57,
        int a58,
        int a59,
        int a60,
        int a61,
        int a62,
        int a63,
        int a64)
{
  int v64; // edi

  *(_BYTE *)(a2 - 1515936862) += BYTE1(a1);
  v64 = a3 + 5;
  *(_BYTE *)v64 = a1;
  *(_DWORD *)(v64 + 1) = a1;
  return -1128547655;
}

//------------------------------------------------------------------------------
// Address: 0x005740F4
// Name: tab_jisx0212_uni3_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge tab_jisx0212_uni3_0(
        DName *this@<ecx>,
        unsigned int _EAX@<eax>,
        int _EDX@<edx>,
        int a4@<ebx>,
        int _EBP@<ebp>,
        unsigned int *_EDI@<edi>,
        DNameNode *a7)
{
  char v7; // pf
  bool v9; // pf
  char v10; // cc
  bool v11; // cf
  char v12; // zf
  char v13; // sf
  _BYTE *v15; // edi
  char v20; // ch
  bool v21; // cf
  bool v22; // pf
  int v23; // edi
  char v24; // cf
  bool v25; // tt
  bool v26; // zf
  bool v27; // sf
  int v29; // [esp-1Ch] [ebp-1Ch]

  LOBYTE(_EAX) = *(_BYTE *)(a4 + _EAX) + _EAX + 49;
  while ( 1 )
  {
    LOBYTE(_EAX) = _EAX + 52;
    v11 = __CFADD__(BYTE1(a4), BYTE1(this));
    v9 = __SETP__(BYTE1(a4) + BYTE1(this), 0);
    v10 = ((char)(BYTE1(a4) + BYTE1(this)) < 0) ^ __OFADD__(BYTE1(a4), BYTE1(this));
    BYTE1(this) += BYTE1(a4);
    LOBYTE(this) = 123;
    if ( v11 )
      break;
    _EAX = 1216382843;
    if ( v9 )
    {
      MEMORY[0xBDE0FCCC] = __ES__;
      v11 = (unsigned __int64)(-110LL * *(int *)((char *)this + 98)) >> 32 != 0;
      MEMORY[0xDB] = __GS__;
      if ( !(v11 | v12) )
        JUMPOUT(0x7058D88A);
      if ( v13 ^ v11 | v12 )
      {
        LOBYTE(_EAX) = __inbyte(0x79u);
        __outdword(0x77u, _EAX);
        *(unsigned int *)((char *)_EDI + _EBP + 1515349327) -= _EAX;
        __asm
        {
          int     62h; reserved for user interrupt
          iret
        }
        JUMPOUT(0x5740D7);
      }
      MK_FP(MEMORY[0x4A], MEMORY[0x46])();
      if ( v11 )
      {
        __asm { fadd    dword ptr [edx] }
        *_EDX = 47775928;
        __asm { fld     qword ptr [edx] }
        JUMPOUT(0x574022);
      }
      if ( v7 )
      {
        MEMORY[0x9875FB24]();
        __asm { fcom    qword ptr [edi-5Eh] }
        JUMPOUT(0x57406E);
      }
      JUMPOUT(0x5740BD);
    }
  }
  if ( !v10 )
  {
    LOBYTE(_EDX) = 96;
    _ECX = (char *)this - 1;
    __asm { bound   edi, [ecx+62h] }
    *_EDI = _EAX;
    v15 = _EDI + 1;
    __asm
    {
      bound   edx, [eax-33942B9Bh]
      insb
    }
    if ( *v15 > (unsigned __int8)_EAX )
    {
      if ( (char)(*v15 - _EAX) >= 0 )
        JUMPOUT(0x574172);
      JUMPOUT(0x57417D);
    }
    JUMPOUT(0x574134);
  }
  _ESI = *(_DWORD *)(_EBP - 19);
  _AX = MEMORY[0x81A59E76](a1: a4);
  v21 = *((_BYTE *)_EDI + 2 * a4) < 0xC5u;
  v22 = __SETP__(*((_BYTE *)_EDI + 2 * a4) + 59, 0);
LABEL_19:
  v23 = v29;
  __asm { bound   esi, [ebp+46h] }
  if ( v22 )
  {
    do
    {
      v29 = 1520130539;
      v25 = v21;
      v24 = __CFADD__(v21, *(_BYTE *)(_EBP + 126)) | __CFADD__(BYTE1(a4), v21 + *(_BYTE *)(_EBP + 126));
      v10 = v24 | (BYTE1(a4) + v25 + *(_BYTE *)(_EBP + 126) == 0);
      *(_BYTE *)(_EBP + 126) += BYTE1(a4) + v25;
      if ( v10 )
        goto LABEL_26;
      _ESI = _EBP;
      --v23;
      *(_DWORD *)(_EDX + 55) -= v24 + _EBP;
      __asm { insb }
      v21 = __CFADD__(*(_BYTE *)(v23 - 30), v20);
      v26 = *(_BYTE *)(v23 - 30) + v20 == 0;
      v22 = __SETP__(*(_BYTE *)(v23 - 30) + v20, 0);
      v27 = (char)(*(_BYTE *)(v23 - 30) + v20) < 0;
      v20 += *(_BYTE *)(v23 - 30);
      if ( v20 == 0 )
      {
        MEMORY[0x53B34423]();
        JUMPOUT(0x5742A3);
      }
      if ( !v27 )
        JUMPOUT(0x574289);
      *(_BYTE *)(_EBP - 118) = _EDX;
      __asm
      {
        fistp   word ptr [esi-31h]
        arpl    bp, ax
      }
      if ( !v26 )
        goto LABEL_19;
    }
    while ( !v27 );
    *(_BYTE *)_AX += 109;
    LOWORD(_EDX) = _AX;
    __readeflags();
    MEMORY[0x6C54C19C] = v20;
LABEL_26:
    *(_WORD *)(_EBP + 92) = __FS__;
  }
  __asm { insd }
  JUMPOUT(0x574247);
}

//------------------------------------------------------------------------------
// Address: 0x005741CC
// Name: tab_jisx0212_uni4_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge tab_jisx0212_uni4_0(
        DName *this@<ecx>,
        int a2@<edx>,
        _BYTE *a3@<ebx>,
        DNameNode *a4,
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
        int a48,
        int a49,
        int a50,
        int a51,
        int a52,
        int a53,
        int a54,
        int a55,
        int a56,
        int a57,
        int a58,
        int a59,
        int a60,
        int a61,
        int a62,
        int a63,
        int a64)
{
  *a3 += BYTE1(a3);
  __asm { retf    1767h }
}

//------------------------------------------------------------------------------
// Address: 0x0057464E
// Name: nullsub_11
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int nullsub_11()
{
  _BYTE retaddr[8]; // [esp+0h] [ebp+0h]

  return MK_FP(*(_WORD *)retaddr, *(_DWORD *)retaddr)();
}

//------------------------------------------------------------------------------
// Address: 0x005746A8
// Name: tab_jisx0208_uni39_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
char *__userpurge tab_jisx0208_uni39_0@<eax>(
        charNode *this@<ecx>,
        unsigned __int8 a2@<al>,
        int a3@<edx>,
        int _ESI@<esi>,
        char *a5,
        char *a6,
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
        int a48,
        int a49,
        int a50,
        int a51,
        int a52,
        int a53,
        int a54,
        int a55,
        int a56,
        int a57,
        int a58,
        int a59,
        int a60,
        int a61,
        int a62,
        int a63,
        int a64)
{
  char v64; // of
  _BYTE retaddr[8]; // [esp+0h] [ebp+0h] BYREF

  __outbyte(a3, a2);
  __asm { outsd }
  *(_DWORD *)(a3 - 118) >>= (char)this;
  if ( v64 )
    return (char *)nullsub_11();
  else
    return MK_FP(*(_WORD *)retaddr, *(_DWORD *)retaddr)(a1: (char *)&this->__vftable + 1, a2: retaddr);
}

//------------------------------------------------------------------------------
// Address: 0x0058CE60
// Name: doubles
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall doubles(DName *this, unsigned __int64 a2)
{
  __asm { iret }
  JUMPOUT(0x58CE62);
}

//------------------------------------------------------------------------------
// Address: 0x0058E158
// Name: doubles_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall doubles_0(DName *this, unsigned __int64 a2)
{
  __asm { iret }
  JUMPOUT(0x58E15A);
}
