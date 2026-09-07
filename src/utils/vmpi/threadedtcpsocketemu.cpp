// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vmpi/threadedtcpsocketemu.cpp
// Functions: 22
// ============================================================

#include "utils\vmpi\threadedtcpsocketemu.h"

//------------------------------------------------------------------------------
// Address: 0x00404F70
// Name: private: virtual class ITCPSocket __near * CThreadedTCPListenSocketEmu::UpdateListen(class CIPAddr __near *)
// Source: json
//------------------------------------------------------------------------------
CThreadedTCPSocketEmu *__thiscall CThreadedTCPListenSocketEmu::UpdateListen(
        CThreadedTCPListenSocketEmu *this,
        CIPAddr *pAddr)
{
  ITCPConnectSocket *m_pListener; // ecx
  CThreadedTCPSocketEmu *m_pLastCreatedSocket; // esi
  _BYTE v6[6]; // [esp+6h] [ebp-Ah] BYREF
  IThreadedTCPSocket *pSocket; // [esp+Ch] [ebp-4h] BYREF

  m_pListener = this->m_pListener;
  if ( m_pListener == nullptr || !m_pListener->Update(this: m_pListener, a2: &pSocket, a3: 0) || pSocket == nullptr )
    return nullptr;
  *pAddr = *pSocket->GetRemoteAddr(this: pSocket, result: v6);
  m_pLastCreatedSocket = this->m_pLastCreatedSocket;
  m_pLastCreatedSocket->Init(this: &m_pLastCreatedSocket->ITCPSocketHandler, a2: pSocket);
  this->m_pLastCreatedSocket = nullptr;
  return m_pLastCreatedSocket;
}

//------------------------------------------------------------------------------
// Address: 0x00405020
// Name: class ITCPListenSocket __near * CreateTCPListenSocketEmu(unsigned short,int)
// Source: json
//------------------------------------------------------------------------------
IHandlerCreator *__cdecl CreateTCPListenSocketEmu(unsigned __int16 port, int nQueueLength)
{
  IHandlerCreator *v2; // eax
  IHandlerCreator *v3; // ecx
  IHandlerCreator *v4; // esi
  ITCPConnectSocket *Listener; // eax

  v2 = (IHandlerCreator *)operator new(nSize: 0x10u);
  if ( v2 != nullptr )
  {
    v3 = v2 + 1;
    v2[1].__vftable = (IHandlerCreator_vtbl *)&IHandlerCreator::`vftable';
    v2->__vftable = (IHandlerCreator_vtbl *)&CThreadedTCPListenSocketEmu::`vftable'{for `ITCPListenSocket'};
    v2[1].__vftable = (IHandlerCreator_vtbl *)&CThreadedTCPListenSocketEmu::`vftable'{for `IHandlerCreator'};
    v2[2].__vftable = nullptr;
    v2[3].__vftable = nullptr;
    v4 = v2;
  }
  else
  {
    v4 = nullptr;
    v3 = nullptr;
  }
  Listener = ThreadedTCP_CreateListener(pHandlerCreator: v3, port, nQueueLength);
  v4[2].__vftable = (IHandlerCreator_vtbl *)Listener;
  if ( Listener != nullptr )
    return v4;
  ((void (__thiscall *)(IHandlerCreator *, int))v4->__vftable[2].CreateNewHandler)(a1: v4, a2: 1);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00405090
// Name: public: CThreadedTCPSocketEmu::CThreadedTCPSocketEmu(void)
// Source: json
//------------------------------------------------------------------------------
CThreadedTCPSocketEmu *__thiscall CThreadedTCPSocketEmu::CThreadedTCPSocketEmu(CThreadedTCPSocketEmu *this)
{
  UtlLinkedListElem_t<CTCPPacket *,int> *m_pMemory; // eax

  this->ITCPSocketHandler::__vftable = (ITCPSocketHandler_vtbl *)&ITCPSocketHandler::`vftable';
  this->IHandlerCreator::__vftable = (IHandlerCreator_vtbl *)&IHandlerCreator::`vftable';
  this->ITCPSocket::IChannel::__vftable = (CThreadedTCPSocketEmu_vtbl *)&CThreadedTCPSocketEmu::`vftable'{for `ITCPSocket'};
  this->ITCPSocketHandler::__vftable = (ITCPSocketHandler_vtbl *)&CThreadedTCPSocketEmu::`vftable'{for `ITCPSocketHandler'};
  this->IHandlerCreator::__vftable = (IHandlerCreator_vtbl *)&CThreadedTCPSocketEmu::`vftable'{for `IHandlerCreator'};
  CEvent::CEvent(this: &this->m_RecvPacketsEvent);
  CCriticalSection::CCriticalSection(this: &this->m_RecvPacketsCS);
  this->m_RecvPackets.m_Memory.m_pMemory = nullptr;
  this->m_RecvPackets.m_Memory.m_nAllocationCount = 0;
  this->m_RecvPackets.m_Memory.m_nGrowSize = 0;
  this->m_RecvPackets.m_LastAlloc.index = -1;
  this->m_RecvPackets.m_Head = -1;
  this->m_RecvPackets.m_Tail = -1;
  this->m_RecvPackets.m_FirstFree = -1;
  m_pMemory = this->m_RecvPackets.m_Memory.m_pMemory;
  this->m_RecvPackets.m_ElementCount = 0;
  this->m_RecvPackets.m_NumAlloced = 0;
  this->m_RecvPackets.m_pElements = m_pMemory;
  CCriticalSection::CCriticalSection(this: &this->m_ErrorStringCS);
  this->m_ErrorString.m_Memory.m_pMemory = nullptr;
  this->m_ErrorString.m_Memory.m_nAllocationCount = 0;
  this->m_ErrorString.m_Memory.m_nGrowSize = 0;
  this->m_ErrorString.m_Size = 0;
  this->m_ErrorString.m_pElements = nullptr;
  this->m_LocalPort = -1;
  this->m_pSocket = nullptr;
  this->m_pConnectSocket = nullptr;
  CEvent::Init(this: &this->m_RecvPacketsEvent, bManualReset: false, bInitialState: false);
  this->m_bError = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00405150
// Name: public: virtual void CThreadedTCPSocketEmu::Init(class IThreadedTCPSocket __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadedTCPSocketEmu::Init(CThreadedTCPSocketEmu *this, IThreadedTCPSocket *pSocket)
{
  this->IHandlerCreator::__vftable = (IHandlerCreator_vtbl *)pSocket;
}

//------------------------------------------------------------------------------
// Address: 0x00405160
// Name: private: virtual void CThreadedTCPSocketEmu::Release(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadedTCPSocketEmu::Release(CThreadedTCPSocketEmu *this, bool bForce)
{
  char *v2; // ecx

  v2 = (char *)this - 4;
  if ( v2 != nullptr )
    (*(void (__thiscall **)(char *, int))(*(_DWORD *)v2 + 36))(a1: v2, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x00405180
// Name: public: virtual class ITCPSocketHandler __near * CThreadedTCPSocketEmu::CreateNewHandler(void)
// Source: json
//------------------------------------------------------------------------------
ITCPSocketHandler *__thiscall CThreadedTCPSocketEmu::CreateNewHandler(CThreadedTCPSocketEmu *this)
{
  if ( this == (CThreadedTCPSocketEmu *)8 )
    return nullptr;
  else
    return (ITCPSocketHandler *)((char *)this - 4);
}

//------------------------------------------------------------------------------
// Address: 0x00405190
// Name: public: virtual void CThreadedTCPSocketEmu::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadedTCPSocketEmu::Release(CThreadedTCPSocketEmu *this)
{
  if ( this != nullptr )
    ((void (__thiscall *)(CThreadedTCPSocketEmu *, int))this->dtr_CThreadedTCPSocketEmu)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x004051A0
// Name: public: virtual bool CThreadedTCPSocketEmu::BindToAny(unsigned short)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CThreadedTCPSocketEmu::BindToAny(CThreadedTCPSocketEmu *this, unsigned __int16 port)
{
  this->m_LocalPort = port;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004051C0
// Name: public: virtual bool CThreadedTCPSocketEmu::BeginConnect(class CIPAddr const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CThreadedTCPSocketEmu::BeginConnect(CThreadedTCPSocketEmu *this, const CIPAddr *addr)
{
  ITCPConnectSocket *m_pConnectSocket; // ecx
  CIPAddr *v4; // eax
  CIPAddr *Connector; // eax
  CIPAddr v7; // [esp+6h] [ebp-6h] BYREF

  m_pConnectSocket = this->m_pConnectSocket;
  if ( m_pConnectSocket != nullptr )
    m_pConnectSocket->Release(this: m_pConnectSocket);
  v4 = CIPAddr::CIPAddr(this: &v7, ip0: 0, ip1: 0, ip2: 0, ip3: 0, ipPort: this->m_LocalPort);
  Connector = ThreadedTCP_CreateConnector(addr, localAddr: v4, pHandlerCreator: &this->IHandlerCreator);
  this->m_pConnectSocket = (ITCPConnectSocket *)Connector;
  return Connector != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00405210
// Name: public: virtual bool CThreadedTCPSocketEmu::UpdateConnect(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CThreadedTCPSocketEmu::UpdateConnect(CThreadedTCPSocketEmu *this)
{
  ITCPConnectSocket *m_pConnectSocket; // ecx

  m_pConnectSocket = this->m_pConnectSocket;
  if ( m_pConnectSocket == nullptr )
    return 0;
  if ( m_pConnectSocket->Update(this: m_pConnectSocket, a2: &this->m_pSocket, a3: 0) )
  {
    if ( this->m_pSocket != nullptr )
    {
      this->m_pConnectSocket->Release(this: this->m_pConnectSocket);
      this->m_pConnectSocket = nullptr;
      return 1;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    this->m_pConnectSocket->Release(this: this->m_pConnectSocket);
    this->m_pConnectSocket = nullptr;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405270
// Name: public: virtual bool CThreadedTCPSocketEmu::IsConnected(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CThreadedTCPSocketEmu::IsConnected(CThreadedTCPSocketEmu *this)
{
  IThreadedTCPSocket *m_pSocket; // ecx
  ITCPConnectSocket *m_pConnectSocket; // ecx

  if ( !this->m_bError )
    return this->m_pSocket != nullptr;
  m_pSocket = this->m_pSocket;
  if ( m_pSocket != nullptr )
  {
    m_pSocket->Release(this: m_pSocket);
    this->m_pSocket = nullptr;
  }
  m_pConnectSocket = this->m_pConnectSocket;
  if ( m_pConnectSocket != nullptr )
  {
    m_pConnectSocket->Release(this: m_pConnectSocket);
    this->m_pConnectSocket = nullptr;
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x004052C0
// Name: public: virtual bool CThreadedTCPSocketEmu::Send(void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CThreadedTCPSocketEmu::Send(CThreadedTCPSocketEmu *this, const void *pData, int size)
{
  return this->m_pSocket != nullptr && this->m_pSocket->Send(this: this->m_pSocket, a2: pData, a3: size);
}

//------------------------------------------------------------------------------
// Address: 0x004052E0
// Name: public: virtual bool CThreadedTCPSocketEmu::SendChunks(void const __near * const __near *,int const __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CThreadedTCPSocketEmu::SendChunks(
        CThreadedTCPSocketEmu *this,
        const void *const *pChunks,
        const int *pChunkLengths,
        int nChunks)
{
  return this->m_pSocket != nullptr
      && this->m_pSocket->IsValid(this: this->m_pSocket)
      && this->m_pSocket->SendChunks(this: this->m_pSocket, a2: pChunks, a3: pChunkLengths, a4: nChunks);
}

//------------------------------------------------------------------------------
// Address: 0x00405310
// Name: public: virtual int CThreadedTCPSocketEmu::GetConnectionID(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CThreadedTCPSocketEmu::GetConnectionID(CThreadedTCPSocketEmu *this)
{
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00405320
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
// Address: 0x00405560
// Name: public: virtual CThreadedTCPSocketEmu::~CThreadedTCPSocketEmu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadedTCPSocketEmu::~CThreadedTCPSocketEmu(CThreadedTCPSocketEmu *this)
{
  IThreadedTCPSocket *m_pSocket; // ecx
  ITCPConnectSocket *m_pConnectSocket; // ecx

  m_pSocket = this->m_pSocket;
  this->ITCPSocket::IChannel::__vftable = (CThreadedTCPSocketEmu_vtbl *)&CThreadedTCPSocketEmu::`vftable'{for `ITCPSocket'};
  this->ITCPSocketHandler::__vftable = (ITCPSocketHandler_vtbl *)&CThreadedTCPSocketEmu::`vftable'{for `ITCPSocketHandler'};
  this->IHandlerCreator::__vftable = (IHandlerCreator_vtbl *)&CThreadedTCPSocketEmu::`vftable'{for `IHandlerCreator'};
  if ( m_pSocket != nullptr )
  {
    m_pSocket->Release(this: m_pSocket);
    this->m_pSocket = nullptr;
  }
  m_pConnectSocket = this->m_pConnectSocket;
  if ( m_pConnectSocket != nullptr )
  {
    m_pConnectSocket->Release(this: m_pConnectSocket);
    this->m_pConnectSocket = nullptr;
  }
  CUtlVector<char,CUtlMemory<char,int>>::~CUtlVector<char,CUtlMemory<char,int>>(this: &this->m_ErrorString);
  CCriticalSection::~CCriticalSection(this: &this->m_ErrorStringCS);
  CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::RemoveAll(this: (CUtlLinkedList<CServiceConn *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServiceConn *,int>,int> > *)&this->m_RecvPackets);
  if ( this->m_RecvPackets.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_RecvPackets.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_RecvPackets.m_Memory.m_pMemory);
      this->m_RecvPackets.m_Memory.m_pMemory = nullptr;
    }
    this->m_RecvPackets.m_Memory.m_nAllocationCount = 0;
  }
  CCriticalSection::~CCriticalSection(this: &this->m_RecvPacketsCS);
  CEvent::~CEvent(this: &this->m_RecvPacketsEvent);
}

//------------------------------------------------------------------------------
// Address: 0x00405630
// Name: class ITCPSocket __near * CreateTCPSocketEmu(void)
// Source: json
//------------------------------------------------------------------------------
CThreadedTCPSocketEmu *__cdecl CreateTCPSocketEmu()
{
  CThreadedTCPSocketEmu *v0; // eax

  v0 = (CThreadedTCPSocketEmu *)operator new(nSize: 0x10Cu);
  if ( v0 != nullptr )
    return CThreadedTCPSocketEmu::CThreadedTCPSocketEmu(this: v0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00405650
// Name: private: virtual class ITCPSocketHandler __near * CThreadedTCPListenSocketEmu::CreateNewHandler(void)
// Source: json
//------------------------------------------------------------------------------
ITCPConnectSocket *__thiscall CThreadedTCPListenSocketEmu::CreateNewHandler(CThreadedTCPListenSocketEmu *this)
{
  CThreadedTCPSocketEmu *v2; // eax
  ITCPConnectSocket *v3; // eax

  v2 = (CThreadedTCPSocketEmu *)operator new(nSize: 0x10Cu);
  if ( v2 != nullptr )
    v3 = (ITCPConnectSocket *)CThreadedTCPSocketEmu::CThreadedTCPSocketEmu(this: v2);
  else
    v3 = nullptr;
  this->m_pListener = v3;
  if ( v3 != nullptr )
    return v3 + 1;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004056F0
// Name: private: virtual void CThreadedTCPSocketEmu::OnPacketReceived(class CTCPPacket __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadedTCPSocketEmu::OnPacketReceived(CThreadedTCPSocketEmu *this, CTCPPacket *pPacket)
{
  CCriticalSectionLock csLock; // [esp+4h] [ebp-8h] BYREF

  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: (CCriticalSection *)&this->m_RecvPacketsEvent);
  CCriticalSectionLock::Lock(this: &csLock);
  CUtlLinkedList<CTCPPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CTCPPacket *,int>,int>>::AddToTail(
    this: (CUtlLinkedList<CTCPPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CTCPPacket *,int>,int> > *)&this->m_RecvPacketsCS.m_DeadlockProtect[20],
    src: &pPacket);
  CEvent::SetEvent(this: (CEvent *)&this->m_pConnectSocket);
  CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
}

//------------------------------------------------------------------------------
// Address: 0x004057A0
// Name: private: virtual void CThreadedTCPSocketEmu::OnError(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadedTCPSocketEmu::OnError(CThreadedTCPSocketEmu *this, int errorCode, const char *pErrorString)
{
  CCriticalSectionLock csLock; // [esp+8h] [ebp-8h] BYREF

  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: (CCriticalSection *)&this->m_RecvPackets.m_pElements);
  CCriticalSectionLock::Lock(this: &csLock);
  CUtlVector<char,CUtlMemory<char,int>>::CopyArray(
    this: (CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *)&this->m_ErrorStringCS.m_DeadlockProtect[20],
    pArray: (const unsigned __int8 *)pErrorString,
    size: strlen(pErrorString) + 1);
  LOBYTE(this->m_ErrorString.m_pElements) = 1;
  CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
}

//------------------------------------------------------------------------------
// Address: 0x00405800
// Name: public: virtual void CThreadedTCPSocketEmu::GetDisconnectReason(class CUtlVector<char,class CUtlMemory<char,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadedTCPSocketEmu::GetDisconnectReason(
        CThreadedTCPSocketEmu *this,
        CUtlVector<char,CUtlMemory<char,int> > *reason)
{
  CCriticalSectionLock csLock; // [esp+4h] [ebp-8h] BYREF

  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &this->m_ErrorStringCS);
  CCriticalSectionLock::Lock(this: &csLock);
  CUtlVector<char,CUtlMemory<char,int>>::operator=(this: reason, other: &this->m_ErrorString);
  CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
}

//------------------------------------------------------------------------------
// Address: 0x004058B0
// Name: public: virtual bool CThreadedTCPSocketEmu::Recv(class CUtlVector<unsigned char,class CUtlMemory<unsigned char,int>> __near &,double)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CThreadedTCPSocketEmu::Recv(
        CThreadedTCPSocketEmu *this,
        CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *data,
        long double flTimeout)
{
  void *EventHandle; // eax
  int m_Head; // edi
  CTCPPacket *m_Element; // eax
  CEvent *p_m_RecvPacketsEvent; // [esp+0h] [ebp-10h]
  CCriticalSectionLock csLock; // [esp+8h] [ebp-8h] BYREF
  CTCPPacket *pPacket_4; // [esp+20h] [ebp+10h]

  p_m_RecvPacketsEvent = &this->m_RecvPacketsEvent;
  csLock = (CCriticalSectionLock)(__int64)(flTimeout * 1000.0);
  EventHandle = CEvent::GetEventHandle(this: &this->m_RecvPacketsEvent);
  if ( WaitForSingleObject(hHandle: EventHandle, dwMilliseconds: (DWORD)csLock.m_pCS) != 0 )
    return 0;
  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &this->m_RecvPacketsCS);
  CCriticalSectionLock::Lock(this: &csLock);
  m_Head = this->m_RecvPackets.m_Head;
  m_Element = this->m_RecvPackets.m_Memory.m_pMemory[m_Head].m_Element;
  pPacket_4 = m_Element;
  CUtlVector<char,CUtlMemory<char,int>>::CopyArray(
    this: data,
    pArray: (const unsigned __int8 *)m_Element->m_Data,
    size: m_Element->m_Len);
  CTCPPacket::Release(this: pPacket_4);
  CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::Unlink(
    this: (CUtlLinkedList<CServiceConn *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServiceConn *,int>,int> > *)&this->m_RecvPackets,
    elem: m_Head);
  this->m_RecvPackets.m_Memory.m_pMemory[m_Head].m_Next = this->m_RecvPackets.m_FirstFree;
  this->m_RecvPackets.m_FirstFree = m_Head;
  if ( this->m_RecvPackets.m_ElementCount > 0 )
    CEvent::SetEvent(this: p_m_RecvPacketsEvent);
  CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
  return 1;
}

// ============================================================
// Overlay from vmpi_service_ui (Missing functions)
// ============================================================
namespace vmpi_service_ui {

//------------------------------------------------------------------------------
// Address: 0x00403800
// Name: public: CThreadedTCPSocketEmu::CThreadedTCPSocketEmu(void)
// Source: json
//------------------------------------------------------------------------------
CThreadedTCPSocketEmu *__thiscall CThreadedTCPSocketEmu::CThreadedTCPSocketEmu(CThreadedTCPSocketEmu *this)
{
  UtlLinkedListElem_t<CTCPPacket *,int> *m_pMemory; // eax

  this->ITCPSocketHandler::__vftable = (ITCPSocketHandler_vtbl *)&ITCPSocketHandler::`vftable';
  this->IHandlerCreator::__vftable = (IHandlerCreator_vtbl *)&IHandlerCreator::`vftable';
  this->ITCPSocket::IChannel::__vftable = (CThreadedTCPSocketEmu_vtbl *)&CThreadedTCPSocketEmu::`vftable'{for `ITCPSocket'};
  this->ITCPSocketHandler::__vftable = (ITCPSocketHandler_vtbl *)&CThreadedTCPSocketEmu::`vftable'{for `ITCPSocketHandler'};
  this->IHandlerCreator::__vftable = (IHandlerCreator_vtbl *)&CThreadedTCPSocketEmu::`vftable'{for `IHandlerCreator'};
  CEvent::CEvent(this: &this->m_RecvPacketsEvent);
  CCriticalSection::CCriticalSection(this: &this->m_RecvPacketsCS);
  this->m_RecvPackets.m_Memory.m_pMemory = nullptr;
  this->m_RecvPackets.m_Memory.m_nAllocationCount = 0;
  this->m_RecvPackets.m_Memory.m_nGrowSize = 0;
  this->m_RecvPackets.m_LastAlloc.index = -1;
  this->m_RecvPackets.m_Head = -1;
  this->m_RecvPackets.m_Tail = -1;
  this->m_RecvPackets.m_FirstFree = -1;
  m_pMemory = this->m_RecvPackets.m_Memory.m_pMemory;
  this->m_RecvPackets.m_ElementCount = 0;
  this->m_RecvPackets.m_NumAlloced = 0;
  this->m_RecvPackets.m_pElements = m_pMemory;
  CCriticalSection::CCriticalSection(this: &this->m_ErrorStringCS);
  this->m_ErrorString.m_Memory.m_pMemory = nullptr;
  this->m_ErrorString.m_Memory.m_nAllocationCount = 0;
  this->m_ErrorString.m_Memory.m_nGrowSize = 0;
  this->m_ErrorString.m_Size = 0;
  this->m_ErrorString.m_pElements = nullptr;
  this->m_LocalPort = -1;
  this->m_pSocket = nullptr;
  this->m_pConnectSocket = nullptr;
  CEvent::Init(this: &this->m_RecvPacketsEvent, bManualReset: false, bInitialState: false);
  this->m_bError = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004038C0
// Name: public: virtual void CThreadedTCPSocketEmu::Init(class IThreadedTCPSocket __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadedTCPSocketEmu::Init(CThreadedTCPSocketEmu *this, IThreadedTCPSocket *pSocket)
{
  this->IHandlerCreator::__vftable = (IHandlerCreator_vtbl *)pSocket;
}

//------------------------------------------------------------------------------
// Address: 0x004038D0
// Name: private: virtual void CThreadedTCPSocketEmu::Release(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadedTCPSocketEmu::Release(CThreadedTCPSocketEmu *this, bool bForce)
{
  char *v2; // ecx

  v2 = (char *)this - 4;
  if ( v2 != nullptr )
    (*(void (__thiscall **)(char *, int))(*(_DWORD *)v2 + 36))(a1: v2, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x004038F0
// Name: public: virtual class ITCPSocketHandler __near * CThreadedTCPSocketEmu::CreateNewHandler(void)
// Source: json
//------------------------------------------------------------------------------
ITCPSocketHandler *__thiscall CThreadedTCPSocketEmu::CreateNewHandler(CThreadedTCPSocketEmu *this)
{
  if ( this == (CThreadedTCPSocketEmu *)8 )
    return nullptr;
  else
    return (ITCPSocketHandler *)((char *)this - 4);
}

//------------------------------------------------------------------------------
// Address: 0x00403900
// Name: public: virtual void CThreadedTCPSocketEmu::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadedTCPSocketEmu::Release(CThreadedTCPSocketEmu *this)
{
  if ( this != nullptr )
    ((void (__thiscall *)(CThreadedTCPSocketEmu *, int))this->dtr_CThreadedTCPSocketEmu)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x00403910
// Name: public: virtual bool CThreadedTCPSocketEmu::BindToAny(unsigned short)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CThreadedTCPSocketEmu::BindToAny(CThreadedTCPSocketEmu *this, unsigned __int16 port)
{
  this->m_LocalPort = port;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00403930
// Name: public: virtual bool CThreadedTCPSocketEmu::BeginConnect(class CIPAddr const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CThreadedTCPSocketEmu::BeginConnect(CThreadedTCPSocketEmu *this, const CIPAddr *addr)
{
  ITCPConnectSocket *m_pConnectSocket; // ecx
  CIPAddr *v4; // eax
  CIPAddr *Connector; // eax
  CIPAddr v7; // [esp+6h] [ebp-6h] BYREF

  m_pConnectSocket = this->m_pConnectSocket;
  if ( m_pConnectSocket != nullptr )
    m_pConnectSocket->Release(this: m_pConnectSocket);
  v4 = CIPAddr::CIPAddr(this: &v7, ip0: 0, ip1: 0, ip2: 0, ip3: 0, ipPort: this->m_LocalPort);
  Connector = ThreadedTCP_CreateConnector(addr, localAddr: v4, pHandlerCreator: &this->IHandlerCreator);
  this->m_pConnectSocket = (ITCPConnectSocket *)Connector;
  return Connector != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00403980
// Name: public: virtual bool CThreadedTCPSocketEmu::UpdateConnect(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CThreadedTCPSocketEmu::UpdateConnect(CThreadedTCPSocketEmu *this)
{
  ITCPConnectSocket *m_pConnectSocket; // ecx

  m_pConnectSocket = this->m_pConnectSocket;
  if ( m_pConnectSocket == nullptr )
    return 0;
  if ( m_pConnectSocket->Update(this: m_pConnectSocket, a2: &this->m_pSocket, a3: 0) )
  {
    if ( this->m_pSocket != nullptr )
    {
      this->m_pConnectSocket->Release(this: this->m_pConnectSocket);
      this->m_pConnectSocket = nullptr;
      return 1;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    this->m_pConnectSocket->Release(this: this->m_pConnectSocket);
    this->m_pConnectSocket = nullptr;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004039E0
// Name: public: virtual bool CThreadedTCPSocketEmu::IsConnected(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CThreadedTCPSocketEmu::IsConnected(CThreadedTCPSocketEmu *this)
{
  IThreadedTCPSocket *m_pSocket; // ecx
  ITCPConnectSocket *m_pConnectSocket; // ecx

  if ( !this->m_bError )
    return this->m_pSocket != nullptr;
  m_pSocket = this->m_pSocket;
  if ( m_pSocket != nullptr )
  {
    m_pSocket->Release(this: m_pSocket);
    this->m_pSocket = nullptr;
  }
  m_pConnectSocket = this->m_pConnectSocket;
  if ( m_pConnectSocket != nullptr )
  {
    m_pConnectSocket->Release(this: m_pConnectSocket);
    this->m_pConnectSocket = nullptr;
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x00403A30
// Name: public: virtual bool CThreadedTCPSocketEmu::Send(void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CThreadedTCPSocketEmu::Send(CThreadedTCPSocketEmu *this, const void *pData, int size)
{
  return this->m_pSocket != nullptr && this->m_pSocket->Send(this: this->m_pSocket, a2: pData, a3: size);
}

//------------------------------------------------------------------------------
// Address: 0x00403A50
// Name: public: virtual bool CThreadedTCPSocketEmu::SendChunks(void const __near * const __near *,int const __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CThreadedTCPSocketEmu::SendChunks(
        CThreadedTCPSocketEmu *this,
        const void *const *pChunks,
        const int *pChunkLengths,
        int nChunks)
{
  return this->m_pSocket != nullptr
      && this->m_pSocket->IsValid(this: this->m_pSocket)
      && this->m_pSocket->SendChunks(this: this->m_pSocket, a2: pChunks, a3: pChunkLengths, a4: nChunks);
}

//------------------------------------------------------------------------------
// Address: 0x00403A80
// Name: public: virtual int CThreadedTCPSocketEmu::GetConnectionID(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CThreadedTCPSocketEmu::GetConnectionID(CThreadedTCPSocketEmu *this)
{
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00403B30
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
// Address: 0x00403CF0
// Name: public: virtual CThreadedTCPSocketEmu::~CThreadedTCPSocketEmu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadedTCPSocketEmu::~CThreadedTCPSocketEmu(CThreadedTCPSocketEmu *this)
{
  IThreadedTCPSocket *m_pSocket; // ecx
  ITCPConnectSocket *m_pConnectSocket; // ecx

  m_pSocket = this->m_pSocket;
  this->ITCPSocket::IChannel::__vftable = (CThreadedTCPSocketEmu_vtbl *)&CThreadedTCPSocketEmu::`vftable'{for `ITCPSocket'};
  this->ITCPSocketHandler::__vftable = (ITCPSocketHandler_vtbl *)&CThreadedTCPSocketEmu::`vftable'{for `ITCPSocketHandler'};
  this->IHandlerCreator::__vftable = (IHandlerCreator_vtbl *)&CThreadedTCPSocketEmu::`vftable'{for `IHandlerCreator'};
  if ( m_pSocket != nullptr )
  {
    m_pSocket->Release(this: m_pSocket);
    this->m_pSocket = nullptr;
  }
  m_pConnectSocket = this->m_pConnectSocket;
  if ( m_pConnectSocket != nullptr )
  {
    m_pConnectSocket->Release(this: m_pConnectSocket);
    this->m_pConnectSocket = nullptr;
  }
  CUtlVector<char,CUtlMemory<char,int>>::~CUtlVector<char,CUtlMemory<char,int>>(this: &this->m_ErrorString);
  CCriticalSection::~CCriticalSection(this: &this->m_ErrorStringCS);
  CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::RemoveAll(this: (CUtlLinkedList<CServiceConn *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServiceConn *,int>,int> > *)&this->m_RecvPackets);
  if ( this->m_RecvPackets.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_RecvPackets.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_RecvPackets.m_Memory.m_pMemory);
      this->m_RecvPackets.m_Memory.m_pMemory = nullptr;
    }
    this->m_RecvPackets.m_Memory.m_nAllocationCount = 0;
  }
  CCriticalSection::~CCriticalSection(this: &this->m_RecvPacketsCS);
  CEvent::~CEvent(this: &this->m_RecvPacketsEvent);
}

//------------------------------------------------------------------------------
// Address: 0x00403DC0
// Name: class ITCPSocket __near * CreateTCPSocketEmu(void)
// Source: json
//------------------------------------------------------------------------------
CThreadedTCPSocketEmu *__cdecl CreateTCPSocketEmu()
{
  CThreadedTCPSocketEmu *v0; // eax

  v0 = (CThreadedTCPSocketEmu *)operator new(nSize: 0x10Cu);
  if ( v0 != nullptr )
    return CThreadedTCPSocketEmu::CThreadedTCPSocketEmu(this: v0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00403E50
// Name: private: virtual void CThreadedTCPSocketEmu::OnPacketReceived(class CTCPPacket __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadedTCPSocketEmu::OnPacketReceived(CThreadedTCPSocketEmu *this, CTCPPacket *pPacket)
{
  CCriticalSectionLock csLock; // [esp+4h] [ebp-8h] BYREF

  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: (CCriticalSection *)&this->m_RecvPacketsEvent);
  CCriticalSectionLock::Lock(this: &csLock);
  CUtlLinkedList<CTCPPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CTCPPacket *,int>,int>>::AddToTail(
    this: (CUtlLinkedList<CTCPPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CTCPPacket *,int>,int> > *)&this->m_RecvPacketsCS.m_DeadlockProtect[20],
    src: &pPacket);
  CEvent::SetEvent(this: (CEvent *)&this->m_pConnectSocket);
  CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
}

//------------------------------------------------------------------------------
// Address: 0x00403F70
// Name: private: virtual void CThreadedTCPSocketEmu::OnError(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadedTCPSocketEmu::OnError(CThreadedTCPSocketEmu *this, int errorCode, const char *pErrorString)
{
  CCriticalSectionLock csLock; // [esp+8h] [ebp-8h] BYREF

  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: (CCriticalSection *)&this->m_RecvPackets.m_pElements);
  CCriticalSectionLock::Lock(this: &csLock);
  CUtlVector<char,CUtlMemory<char,int>>::CopyArray(
    this: (CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *)&this->m_ErrorStringCS.m_DeadlockProtect[20],
    pArray: (const unsigned __int8 *)pErrorString,
    size: strlen(pErrorString) + 1);
  LOBYTE(this->m_ErrorString.m_pElements) = 1;
  CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
}

//------------------------------------------------------------------------------
// Address: 0x00403FD0
// Name: public: virtual void CThreadedTCPSocketEmu::GetDisconnectReason(class CUtlVector<char,class CUtlMemory<char,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThreadedTCPSocketEmu::GetDisconnectReason(
        CThreadedTCPSocketEmu *this,
        CUtlVector<char,CUtlMemory<char,int> > *reason)
{
  CCriticalSectionLock csLock; // [esp+4h] [ebp-8h] BYREF

  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &this->m_ErrorStringCS);
  CCriticalSectionLock::Lock(this: &csLock);
  CUtlVector<char,CUtlMemory<char,int>>::operator=(this: reason, other: &this->m_ErrorString);
  CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
}

//------------------------------------------------------------------------------
// Address: 0x00404010
// Name: public: virtual bool CThreadedTCPSocketEmu::Recv(class CUtlVector<unsigned char,class CUtlMemory<unsigned char,int>> __near &,double)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CThreadedTCPSocketEmu::Recv(
        CThreadedTCPSocketEmu *this,
        CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *data,
        long double flTimeout)
{
  void *EventHandle; // eax
  int m_Head; // edi
  CTCPPacket *m_Element; // eax
  CEvent *p_m_RecvPacketsEvent; // [esp+0h] [ebp-10h]
  CCriticalSectionLock csLock; // [esp+8h] [ebp-8h] BYREF
  CTCPPacket *pPacket_4; // [esp+20h] [ebp+10h]

  p_m_RecvPacketsEvent = &this->m_RecvPacketsEvent;
  csLock = (CCriticalSectionLock)(__int64)(flTimeout * 1000.0);
  EventHandle = CEvent::GetEventHandle(this: &this->m_RecvPacketsEvent);
  if ( WaitForSingleObject(hHandle: EventHandle, dwMilliseconds: (DWORD)csLock.m_pCS) != 0 )
    return 0;
  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &this->m_RecvPacketsCS);
  CCriticalSectionLock::Lock(this: &csLock);
  m_Head = this->m_RecvPackets.m_Head;
  m_Element = this->m_RecvPackets.m_Memory.m_pMemory[m_Head].m_Element;
  pPacket_4 = m_Element;
  CUtlVector<char,CUtlMemory<char,int>>::CopyArray(
    this: data,
    pArray: (const unsigned __int8 *)m_Element->m_Data,
    size: m_Element->m_Len);
  CTCPPacket::Release(this: pPacket_4);
  CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::Unlink(
    this: (CUtlLinkedList<CServiceConn *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServiceConn *,int>,int> > *)&this->m_RecvPackets,
    elem: m_Head);
  this->m_RecvPackets.m_Memory.m_pMemory[m_Head].m_Next = this->m_RecvPackets.m_FirstFree;
  this->m_RecvPackets.m_FirstFree = m_Head;
  if ( this->m_RecvPackets.m_ElementCount > 0 )
    CEvent::SetEvent(this: p_m_RecvPacketsEvent);
  CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00405E10
// Name: public: void CUtlMemory<class CUtlString,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CUtlString,int>::Grow(CUtlMemory<CUtlString,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CUtlString *m_pMemory; // edx
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
    v7 = 16 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CUtlString *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CUtlString *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

} // namespace vmpi_service_ui
