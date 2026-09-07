// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vmpi/vmpi_service/service_conn_mgr.cpp
// Functions: 10
// ============================================================

#include "utils\vmpi\vmpi_service\service_conn_mgr.h"

//------------------------------------------------------------------------------
// Address: 0x00402F70
// Name: public: virtual void CServiceConnMgr::OnNewConnection(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServiceConnMgr::OnNewConnection(CServiceConnMgr *this, int id)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x00402F80
// Name: public: virtual void CServiceConnMgr::HandlePacket(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServiceConnMgr::HandlePacket(CServiceConnMgr *this, const char *pData, const char *len)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x00402F90
// Name: public: bool CServiceConnMgr::IsConnected(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CServiceConnMgr::IsConnected(CServiceConnMgr *this)
{
  return this->m_Connections.m_ElementCount != 0;
}

//------------------------------------------------------------------------------
// Address: 0x00403130
// Name: public: void CServiceConnMgr::SendPacket(int,void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServiceConnMgr::SendPacket(CServiceConnMgr *this, int id, const void *pData, int len)
{
  int m_Head; // esi
  UtlLinkedListElem_t<CServiceConn *,int> *m_pMemory; // eax
  int v7; // esi
  ITCPSocket *m_pSocket; // ecx

  if ( id == -1 )
  {
    m_Head = this->m_Connections.m_Head;
    if ( m_Head != -1 )
    {
      m_pMemory = this->m_Connections.m_Memory.m_pMemory;
      do
      {
        v7 = m_Head;
        m_pMemory[v7].m_Element->m_pSocket->Send(this: m_pMemory[v7].m_Element->m_pSocket, a2: pData, a3: len);
        m_pMemory = this->m_Connections.m_Memory.m_pMemory;
        m_Head = m_pMemory[v7].m_Next;
      }
      while ( m_Head != -1 );
    }
  }
  else
  {
    m_pSocket = this->m_Connections.m_Memory.m_pMemory[id].m_Element->m_pSocket;
    m_pSocket->Send(this: m_pSocket, a2: pData, a3: len);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004031A0
// Name: public: CServiceConnMgr::CServiceConnMgr(void)
// Source: json
//------------------------------------------------------------------------------
CServiceConnMgr *__thiscall CServiceConnMgr::CServiceConnMgr(CServiceConnMgr *this)
{
  UtlLinkedListElem_t<CServiceConn *,int> *m_pMemory; // edx

  this->__vftable = (CServiceConnMgr_vtbl *)&CServiceConnMgr::`vftable';
  this->m_Connections.m_Memory.m_pMemory = nullptr;
  this->m_Connections.m_Memory.m_nAllocationCount = 0;
  this->m_Connections.m_Memory.m_nGrowSize = 0;
  this->m_Connections.m_LastAlloc.index = -1;
  this->m_Connections.m_Head = -1;
  this->m_Connections.m_Tail = -1;
  this->m_Connections.m_FirstFree = -1;
  m_pMemory = this->m_Connections.m_Memory.m_pMemory;
  this->m_Connections.m_ElementCount = 0;
  this->m_Connections.m_NumAlloced = 0;
  this->m_Connections.m_pElements = m_pMemory;
  *(_WORD *)&this->m_bShuttingDown = 0;
  this->m_pListenSocket = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00403260
// Name: public: void CServiceConnMgr::Term(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServiceConnMgr::Term(CServiceConnMgr *this)
{
  ITCPListenSocket *m_pListenSocket; // ecx

  m_pListenSocket = this->m_pListenSocket;
  this->m_bShuttingDown = true;
  if ( m_pListenSocket != nullptr )
  {
    m_pListenSocket->Release(this: m_pListenSocket);
    this->m_pListenSocket = nullptr;
  }
  CUtlLinkedList<CServiceConn *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServiceConn *,int>,int>>::PurgeAndDeleteElements(this: &this->m_Connections);
  this->m_bShuttingDown = false;
}

//------------------------------------------------------------------------------
// Address: 0x00403290
// Name: public: CServiceConnMgr::~CServiceConnMgr(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServiceConnMgr::~CServiceConnMgr(CServiceConnMgr *this)
{
  ITCPListenSocket *m_pListenSocket; // ecx

  m_pListenSocket = this->m_pListenSocket;
  this->__vftable = (CServiceConnMgr_vtbl *)&CServiceConnMgr::`vftable';
  this->m_bShuttingDown = true;
  if ( m_pListenSocket != nullptr )
  {
    m_pListenSocket->Release(this: m_pListenSocket);
    this->m_pListenSocket = nullptr;
  }
  CUtlLinkedList<CServiceConn *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServiceConn *,int>,int>>::PurgeAndDeleteElements(this: &this->m_Connections);
  this->m_bShuttingDown = false;
  CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::RemoveAll(this: &this->m_Connections);
  if ( this->m_Connections.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Connections.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Connections.m_Memory.m_pMemory);
      this->m_Connections.m_Memory.m_pMemory = nullptr;
    }
    this->m_Connections.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403300
// Name: public: bool CServiceConnMgr::InitServer(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CServiceConnMgr::InitServer(CServiceConnMgr *this)
{
  ITCPListenSocket *m_pListenSocket; // ecx
  int v3; // edi
  ITCPListenSocket *TCPListenSocketEmu; // eax

  m_pListenSocket = this->m_pListenSocket;
  this->m_bShuttingDown = true;
  if ( m_pListenSocket != nullptr )
  {
    m_pListenSocket->Release(this: m_pListenSocket);
    this->m_pListenSocket = nullptr;
  }
  CUtlLinkedList<CServiceConn *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServiceConn *,int>,int>>::PurgeAndDeleteElements(this: &this->m_Connections);
  *(_WORD *)&this->m_bShuttingDown = 256;
  v3 = 23300;
  while ( 1 )
  {
    TCPListenSocketEmu = CreateTCPListenSocketEmu(port: v3, nQueueLength: 5);
    this->m_pListenSocket = TCPListenSocketEmu;
    if ( TCPListenSocketEmu != nullptr )
      break;
    if ( ++v3 > 23310 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00403360
// Name: private: void CServiceConnMgr::AttemptConnect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServiceConnMgr::AttemptConnect(CServiceConnMgr *this)
{
  int i; // esi
  ITCPSocket *TCPSocketEmu; // ebx
  CServiceConn *v3; // eax
  int v4; // eax
  int v5; // edi
  CServiceConn *v6; // esi
  int m_ID; // eax
  UtlLinkedListElem_t<CServiceConn *,int> *m_pMemory; // eax
  int v9; // ecx
  int m_Tail; // edx
  UtlLinkedListElem_t<CServiceConn *,int> *v11; // eax
  UtlLinkedListElem_t<CServiceConn *,int> *v12; // eax
  CServiceConn *pConn; // [esp+1Ch] [ebp-8h] BYREF

  this->m_LastConnectAttemptTime = GetTickCount();
  for ( i = 23300; i <= 23310; ++i )
  {
    TCPSocketEmu = CreateTCPSocketEmu();
    if ( TCPSocketEmu == nullptr || !TCPSocketEmu->BindToAny(this: TCPSocketEmu, a2: 0) )
      break;
    CIPAddr::CIPAddr(this: (CIPAddr *)&pConn, ip0: 0x7Fu, ip1: 0, ip2: 0, ip3: 1u, ipPort: i);
    if ( TCPSocket_Connect(pSocket: TCPSocketEmu, pAddr: (const CIPAddr *)&pConn, flTimeout: 0.1) )
    {
      v3 = (CServiceConn *)operator new(nSize: 0xCu);
      if ( v3 != nullptr )
      {
        v3->m_pSocket = nullptr;
        pConn = v3;
      }
      else
      {
        pConn = nullptr;
      }
      v4 = CUtlLinkedList<CServiceConn *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServiceConn *,int>,int>>::AllocInternal(
             this: &this->m_Connections,
             multilist: false);
      v5 = v4;
      if ( v4 == -1 )
      {
        v5 = -1;
        goto LABEL_12;
      }
      CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::Unlink(
        this: &this->m_Connections,
        elem: v4);
      m_pMemory = this->m_Connections.m_Memory.m_pMemory;
      v9 = v5;
      m_pMemory[v9].m_Next = -1;
      m_Tail = this->m_Connections.m_Tail;
      m_pMemory[v9].m_Previous = m_Tail;
      this->m_Connections.m_Tail = v5;
      if ( m_Tail == -1 )
        this->m_Connections.m_Head = v5;
      else
        this->m_Connections.m_Memory.m_pMemory[m_Tail].m_Next = v5;
      v11 = this->m_Connections.m_Memory.m_pMemory;
      ++this->m_Connections.m_ElementCount;
      v12 = &v11[v9];
      if ( v12 != nullptr )
      {
        v6 = pConn;
        v12->m_Element = pConn;
      }
      else
      {
LABEL_12:
        v6 = pConn;
      }
      v6->m_ID = v5;
      v6->m_LastRecvTime = GetTickCount();
      m_ID = v6->m_ID;
      v6->m_pSocket = TCPSocketEmu;
      this->OnNewConnection(this, a2: m_ID);
      return;
    }
    TCPSocketEmu->Release(this: TCPSocketEmu);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403490
// Name: public: void CServiceConnMgr::Update(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServiceConnMgr::Update(CServiceConnMgr *this)
{
  CServiceConnMgr *v1; // ebx
  DWORD TickCount; // eax
  bool v3; // zf
  CServiceConn *v4; // eax
  int v5; // eax
  int v6; // esi
  CServiceConn *v7; // eax
  ITCPSocket *v8; // edx
  UtlLinkedListElem_t<CServiceConn *,int> *m_pMemory; // eax
  int v10; // ecx
  int m_Tail; // edx
  UtlLinkedListElem_t<CServiceConn *,int> *v12; // edx
  CServiceConn **p_m_Element; // edx
  int m_Head; // esi
  UtlLinkedListElem_t<CServiceConn *,int> *v15; // eax
  CServiceConn *m_Element; // ebx
  int m_Next; // edx
  int *m_pSocket; // ecx
  int v19; // eax
  DWORD v20; // eax
  ITCPSocket *v21; // ecx
  DWORD v22; // esi
  unsigned __int8 *v23; // eax
  CServiceConnMgr *v24; // eax
  CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > data; // [esp+28h] [ebp-2Ch] BYREF
  CIPAddr addr; // [esp+3Ch] [ebp-18h] BYREF
  int iNext; // [esp+44h] [ebp-10h]
  ITCPSocket *pSocket; // [esp+48h] [ebp-Ch]
  CServiceConn *pConn; // [esp+4Ch] [ebp-8h]
  CServiceConnMgr *v30; // [esp+50h] [ebp-4h]

  v1 = this;
  v30 = this;
  TickCount = GetTickCount();
  v3 = !v1->m_bServer;
  iNext = TickCount;
  if ( v3 )
  {
    if ( v1->m_Connections.m_ElementCount == 0 && TickCount - v1->m_LastConnectAttemptTime >= 0x3E8 )
      CServiceConnMgr::AttemptConnect(this: v1);
  }
  else if ( v1->m_pListenSocket != nullptr )
  {
    CIPAddr::CIPAddr(this: &addr);
    for ( pSocket = v1->m_pListenSocket->UpdateListen(this: v1->m_pListenSocket, a2: &addr);
          pSocket != nullptr;
          pSocket = v1->m_pListenSocket->UpdateListen(this: v1->m_pListenSocket, a2: &addr) )
    {
      v4 = (CServiceConn *)operator new(nSize: 0xCu);
      if ( v4 != nullptr )
      {
        v4->m_pSocket = nullptr;
        pConn = v4;
      }
      else
      {
        pConn = nullptr;
      }
      v5 = CUtlLinkedList<CServiceConn *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServiceConn *,int>,int>>::AllocInternal(
             this: &v1->m_Connections,
             multilist: false);
      v6 = v5;
      if ( v5 == -1 )
      {
        v6 = -1;
      }
      else
      {
        CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::Unlink(
          this: &v1->m_Connections,
          elem: v5);
        m_pMemory = v1->m_Connections.m_Memory.m_pMemory;
        v10 = v6;
        m_pMemory[v10].m_Next = -1;
        m_Tail = v1->m_Connections.m_Tail;
        m_pMemory[v10].m_Previous = m_Tail;
        v1->m_Connections.m_Tail = v6;
        if ( m_Tail == -1 )
          v1->m_Connections.m_Head = v6;
        else
          v1->m_Connections.m_Memory.m_pMemory[m_Tail].m_Next = v6;
        v12 = v1->m_Connections.m_Memory.m_pMemory;
        ++v1->m_Connections.m_ElementCount;
        p_m_Element = &v12[v10].m_Element;
        if ( p_m_Element != nullptr )
        {
          v7 = pConn;
          *p_m_Element = pConn;
          goto LABEL_10;
        }
      }
      v7 = pConn;
LABEL_10:
      v8 = pSocket;
      v7->m_LastRecvTime = iNext;
      v7->m_pSocket = v8;
      v7->m_ID = v6;
      v1->OnNewConnection(this: v1, a2: v6);
      CIPAddr::CIPAddr(this: &addr);
    }
  }
  m_Head = v1->m_Connections.m_Head;
  if ( m_Head != -1 )
  {
    while ( 1 )
    {
      v15 = v1->m_Connections.m_Memory.m_pMemory;
      m_Element = v15[m_Head].m_Element;
      m_Next = v15[m_Head].m_Next;
      m_pSocket = (int *)m_Element->m_pSocket;
      v19 = *m_pSocket;
      iNext = m_Next;
      if ( (*(unsigned __int8 (__thiscall **)(int *))(v19 + 16))(a1: m_pSocket) != 0 )
      {
        v20 = GetTickCount();
        v21 = m_Element->m_pSocket;
        v22 = v20;
        memset(&data, 0, sizeof(data));
        if ( ((unsigned __int8 (__thiscall *)(ITCPSocket *, CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *, _DWORD, _DWORD))v21->Recv)(
               a1: v21,
               a2: &data,
               a3: 0,
               a4: 0) != 0 )
        {
          do
            v30->HandlePacket(this: v30, a2: (const char *)data.m_Memory.m_pMemory, a3: data.m_Size);
          while ( GetTickCount() - v22 <= 0x32
               && ((unsigned __int8 (__thiscall *)(ITCPSocket *, CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *, _DWORD, _DWORD))m_Element->m_pSocket->Recv)(
                    a1: m_Element->m_pSocket,
                    a2: &data,
                    a3: 0,
                    a4: 0) != 0 );
        }
        v23 = data.m_Memory.m_pMemory;
        data.m_Size = 0;
        if ( data.m_Memory.m_nGrowSize >= 0 )
        {
          if ( data.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: data.m_Memory.m_pMemory);
            v23 = nullptr;
            data.m_Memory.m_pMemory = nullptr;
          }
          data.m_Memory.m_nAllocationCount = 0;
        }
        data.m_pElements = v23;
        if ( data.m_Memory.m_nGrowSize >= 0 && v23 != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v23);
      }
      else
      {
        v30->OnTerminateConnection(this: v30, a2: m_Head);
        CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::Unlink(
          this: &v30->m_Connections,
          elem: m_Head);
        v24 = v30;
        v30->m_Connections.m_Memory.m_pMemory[m_Head].m_Next = v30->m_Connections.m_FirstFree;
        v24->m_Connections.m_FirstFree = m_Head;
        if ( m_Element->m_pSocket != nullptr )
          m_Element->m_pSocket->Release(this: m_Element->m_pSocket);
        free(pMem: m_Element);
      }
      m_Head = iNext;
      if ( iNext == -1 )
        break;
      v1 = v30;
    }
  }
}

// ============================================================
// Overlay from vmpi_service_ui (Missing functions)
// ============================================================
namespace vmpi_service_ui {

//------------------------------------------------------------------------------
// Address: 0x00401740
// Name: public: virtual void CServiceConnMgr::OnNewConnection(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServiceConnMgr::OnNewConnection(CServiceConnMgr *this, int id)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x00401750
// Name: public: virtual void CServiceConnMgr::HandlePacket(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServiceConnMgr::HandlePacket(CServiceConnMgr *this, const char *pData, const char *len)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x00401760
// Name: public: bool CServiceConnMgr::IsConnected(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CServiceConnMgr::IsConnected(CServiceConnMgr *this)
{
  return this->m_Connections.m_ElementCount != 0;
}

//------------------------------------------------------------------------------
// Address: 0x004018A0
// Name: public: void CServiceConnMgr::SendPacket(int,void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServiceConnMgr::SendPacket(CServiceConnMgr *this, int id, const void *pData, int len)
{
  int m_Head; // esi
  UtlLinkedListElem_t<CServiceConn *,int> *m_pMemory; // eax
  int v7; // esi
  ITCPSocket *m_pSocket; // ecx

  if ( id == -1 )
  {
    m_Head = this->m_Connections.m_Head;
    if ( m_Head != -1 )
    {
      m_pMemory = this->m_Connections.m_Memory.m_pMemory;
      do
      {
        v7 = m_Head;
        m_pMemory[v7].m_Element->m_pSocket->Send(this: m_pMemory[v7].m_Element->m_pSocket, a2: pData, a3: len);
        m_pMemory = this->m_Connections.m_Memory.m_pMemory;
        m_Head = m_pMemory[v7].m_Next;
      }
      while ( m_Head != -1 );
    }
  }
  else
  {
    m_pSocket = this->m_Connections.m_Memory.m_pMemory[id].m_Element->m_pSocket;
    m_pSocket->Send(this: m_pSocket, a2: pData, a3: len);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401990
// Name: public: CServiceConnMgr::CServiceConnMgr(void)
// Source: json
//------------------------------------------------------------------------------
CServiceConnMgr *__thiscall CServiceConnMgr::CServiceConnMgr(CServiceConnMgr *this)
{
  UtlLinkedListElem_t<CServiceConn *,int> *m_pMemory; // edx

  this->__vftable = (CServiceConnMgr_vtbl *)&CServiceConnMgr::`vftable';
  this->m_Connections.m_Memory.m_pMemory = nullptr;
  this->m_Connections.m_Memory.m_nAllocationCount = 0;
  this->m_Connections.m_Memory.m_nGrowSize = 0;
  this->m_Connections.m_LastAlloc.index = -1;
  this->m_Connections.m_Head = -1;
  this->m_Connections.m_Tail = -1;
  this->m_Connections.m_FirstFree = -1;
  m_pMemory = this->m_Connections.m_Memory.m_pMemory;
  this->m_Connections.m_ElementCount = 0;
  this->m_Connections.m_NumAlloced = 0;
  this->m_Connections.m_pElements = m_pMemory;
  *(_WORD *)&this->m_bShuttingDown = 0;
  this->m_pListenSocket = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00401A50
// Name: public: void CServiceConnMgr::Term(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServiceConnMgr::Term(CServiceConnMgr *this)
{
  ITCPListenSocket *m_pListenSocket; // ecx

  m_pListenSocket = this->m_pListenSocket;
  this->m_bShuttingDown = true;
  if ( m_pListenSocket != nullptr )
  {
    m_pListenSocket->Release(this: m_pListenSocket);
    this->m_pListenSocket = nullptr;
  }
  CUtlLinkedList<CServiceConn *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServiceConn *,int>,int>>::PurgeAndDeleteElements(this: &this->m_Connections);
  this->m_bShuttingDown = false;
}

//------------------------------------------------------------------------------
// Address: 0x00401A80
// Name: public: CServiceConnMgr::~CServiceConnMgr(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServiceConnMgr::~CServiceConnMgr(CServiceConnMgr *this)
{
  ITCPListenSocket *m_pListenSocket; // ecx

  m_pListenSocket = this->m_pListenSocket;
  this->__vftable = (CServiceConnMgr_vtbl *)&CServiceConnMgr::`vftable';
  this->m_bShuttingDown = true;
  if ( m_pListenSocket != nullptr )
  {
    m_pListenSocket->Release(this: m_pListenSocket);
    this->m_pListenSocket = nullptr;
  }
  CUtlLinkedList<CServiceConn *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServiceConn *,int>,int>>::PurgeAndDeleteElements(this: &this->m_Connections);
  this->m_bShuttingDown = false;
  CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::RemoveAll(this: &this->m_Connections);
  if ( this->m_Connections.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Connections.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Connections.m_Memory.m_pMemory);
      this->m_Connections.m_Memory.m_pMemory = nullptr;
    }
    this->m_Connections.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401AF0
// Name: private: void CServiceConnMgr::AttemptConnect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServiceConnMgr::AttemptConnect(CServiceConnMgr *this)
{
  int i; // esi
  ITCPSocket *TCPSocketEmu; // ebx
  CServiceConn *v3; // eax
  int v4; // eax
  int v5; // edi
  CServiceConn *v6; // esi
  int m_ID; // eax
  UtlLinkedListElem_t<CServiceConn *,int> *m_pMemory; // eax
  int v9; // ecx
  int m_Tail; // edx
  UtlLinkedListElem_t<CServiceConn *,int> *v11; // eax
  UtlLinkedListElem_t<CServiceConn *,int> *v12; // eax
  CServiceConn *pConn; // [esp+1Ch] [ebp-8h] BYREF

  this->m_LastConnectAttemptTime = GetTickCount();
  for ( i = 23300; i <= 23310; ++i )
  {
    TCPSocketEmu = CreateTCPSocketEmu();
    if ( TCPSocketEmu == nullptr || !TCPSocketEmu->BindToAny(this: TCPSocketEmu, a2: 0) )
      break;
    CIPAddr::CIPAddr(this: (CIPAddr *)&pConn, ip0: 0x7Fu, ip1: 0, ip2: 0, ip3: 1u, ipPort: i);
    if ( TCPSocket_Connect(pSocket: TCPSocketEmu, pAddr: (const CIPAddr *)&pConn, flTimeout: 0.1) )
    {
      v3 = (CServiceConn *)operator new(nSize: 0xCu);
      if ( v3 != nullptr )
      {
        v3->m_pSocket = nullptr;
        pConn = v3;
      }
      else
      {
        pConn = nullptr;
      }
      v4 = CUtlLinkedList<CServiceConn *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServiceConn *,int>,int>>::AllocInternal(
             this: &this->m_Connections,
             multilist: false);
      v5 = v4;
      if ( v4 == -1 )
      {
        v5 = -1;
        goto LABEL_12;
      }
      CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::Unlink(
        this: &this->m_Connections,
        elem: v4);
      m_pMemory = this->m_Connections.m_Memory.m_pMemory;
      v9 = v5;
      m_pMemory[v9].m_Next = -1;
      m_Tail = this->m_Connections.m_Tail;
      m_pMemory[v9].m_Previous = m_Tail;
      this->m_Connections.m_Tail = v5;
      if ( m_Tail == -1 )
        this->m_Connections.m_Head = v5;
      else
        this->m_Connections.m_Memory.m_pMemory[m_Tail].m_Next = v5;
      v11 = this->m_Connections.m_Memory.m_pMemory;
      ++this->m_Connections.m_ElementCount;
      v12 = &v11[v9];
      if ( v12 != nullptr )
      {
        v6 = pConn;
        v12->m_Element = pConn;
      }
      else
      {
LABEL_12:
        v6 = pConn;
      }
      v6->m_ID = v5;
      v6->m_LastRecvTime = GetTickCount();
      m_ID = v6->m_ID;
      v6->m_pSocket = TCPSocketEmu;
      this->OnNewConnection(this, a2: m_ID);
      return;
    }
    TCPSocketEmu->Release(this: TCPSocketEmu);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401C20
// Name: public: bool CServiceConnMgr::InitClient(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CServiceConnMgr::InitClient(CServiceConnMgr *this)
{
  ITCPListenSocket *m_pListenSocket; // ecx

  m_pListenSocket = this->m_pListenSocket;
  this->m_bShuttingDown = true;
  if ( m_pListenSocket != nullptr )
  {
    m_pListenSocket->Release(this: m_pListenSocket);
    this->m_pListenSocket = nullptr;
  }
  CUtlLinkedList<CServiceConn *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServiceConn *,int>,int>>::PurgeAndDeleteElements(this: &this->m_Connections);
  *(_WORD *)&this->m_bShuttingDown = 0;
  CServiceConnMgr::AttemptConnect(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00401C60
// Name: public: void CServiceConnMgr::Update(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServiceConnMgr::Update(CServiceConnMgr *this)
{
  CServiceConnMgr *v1; // ebx
  DWORD TickCount; // eax
  bool v3; // zf
  CServiceConn *v4; // eax
  int v5; // eax
  int v6; // esi
  CServiceConn *v7; // eax
  ITCPSocket *v8; // edx
  UtlLinkedListElem_t<CServiceConn *,int> *m_pMemory; // eax
  int v10; // ecx
  int m_Tail; // edx
  UtlLinkedListElem_t<CServiceConn *,int> *v12; // edx
  CServiceConn **p_m_Element; // edx
  int m_Head; // esi
  UtlLinkedListElem_t<CServiceConn *,int> *v15; // eax
  CServiceConn *m_Element; // ebx
  int m_Next; // edx
  int *m_pSocket; // ecx
  int v19; // eax
  DWORD v20; // eax
  ITCPSocket *v21; // ecx
  DWORD v22; // esi
  unsigned __int8 *v23; // eax
  CServiceConnMgr *v24; // eax
  CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > data; // [esp+28h] [ebp-2Ch] BYREF
  CIPAddr addr; // [esp+3Ch] [ebp-18h] BYREF
  int iNext; // [esp+44h] [ebp-10h]
  ITCPSocket *pSocket; // [esp+48h] [ebp-Ch]
  CServiceConn *pConn; // [esp+4Ch] [ebp-8h]
  CServiceConnMgr *v30; // [esp+50h] [ebp-4h]

  v1 = this;
  v30 = this;
  TickCount = GetTickCount();
  v3 = !v1->m_bServer;
  iNext = TickCount;
  if ( v3 )
  {
    if ( v1->m_Connections.m_ElementCount == 0 && TickCount - v1->m_LastConnectAttemptTime >= 0x3E8 )
      CServiceConnMgr::AttemptConnect(this: v1);
  }
  else if ( v1->m_pListenSocket != nullptr )
  {
    CIPAddr::CIPAddr(this: &addr);
    for ( pSocket = v1->m_pListenSocket->UpdateListen(this: v1->m_pListenSocket, a2: &addr);
          pSocket != nullptr;
          pSocket = v1->m_pListenSocket->UpdateListen(this: v1->m_pListenSocket, a2: &addr) )
    {
      v4 = (CServiceConn *)operator new(nSize: 0xCu);
      if ( v4 != nullptr )
      {
        v4->m_pSocket = nullptr;
        pConn = v4;
      }
      else
      {
        pConn = nullptr;
      }
      v5 = CUtlLinkedList<CServiceConn *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServiceConn *,int>,int>>::AllocInternal(
             this: &v1->m_Connections,
             multilist: false);
      v6 = v5;
      if ( v5 == -1 )
      {
        v6 = -1;
      }
      else
      {
        CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::Unlink(
          this: &v1->m_Connections,
          elem: v5);
        m_pMemory = v1->m_Connections.m_Memory.m_pMemory;
        v10 = v6;
        m_pMemory[v10].m_Next = -1;
        m_Tail = v1->m_Connections.m_Tail;
        m_pMemory[v10].m_Previous = m_Tail;
        v1->m_Connections.m_Tail = v6;
        if ( m_Tail == -1 )
          v1->m_Connections.m_Head = v6;
        else
          v1->m_Connections.m_Memory.m_pMemory[m_Tail].m_Next = v6;
        v12 = v1->m_Connections.m_Memory.m_pMemory;
        ++v1->m_Connections.m_ElementCount;
        p_m_Element = &v12[v10].m_Element;
        if ( p_m_Element != nullptr )
        {
          v7 = pConn;
          *p_m_Element = pConn;
          goto LABEL_10;
        }
      }
      v7 = pConn;
LABEL_10:
      v8 = pSocket;
      v7->m_LastRecvTime = iNext;
      v7->m_pSocket = v8;
      v7->m_ID = v6;
      v1->OnNewConnection(this: v1, a2: v6);
      CIPAddr::CIPAddr(this: &addr);
    }
  }
  m_Head = v1->m_Connections.m_Head;
  if ( m_Head != -1 )
  {
    while ( 1 )
    {
      v15 = v1->m_Connections.m_Memory.m_pMemory;
      m_Element = v15[m_Head].m_Element;
      m_Next = v15[m_Head].m_Next;
      m_pSocket = (int *)m_Element->m_pSocket;
      v19 = *m_pSocket;
      iNext = m_Next;
      if ( (*(unsigned __int8 (__thiscall **)(int *))(v19 + 16))(a1: m_pSocket) != 0 )
      {
        v20 = GetTickCount();
        v21 = m_Element->m_pSocket;
        v22 = v20;
        memset(&data, 0, sizeof(data));
        if ( ((unsigned __int8 (__thiscall *)(ITCPSocket *, CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *, _DWORD, _DWORD))v21->Recv)(
               a1: v21,
               a2: &data,
               a3: 0,
               a4: 0) != 0 )
        {
          do
            v30->HandlePacket(this: v30, a2: (const char *)data.m_Memory.m_pMemory, a3: data.m_Size);
          while ( GetTickCount() - v22 <= 0x32
               && ((unsigned __int8 (__thiscall *)(ITCPSocket *, CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *, _DWORD, _DWORD))m_Element->m_pSocket->Recv)(
                    a1: m_Element->m_pSocket,
                    a2: &data,
                    a3: 0,
                    a4: 0) != 0 );
        }
        v23 = data.m_Memory.m_pMemory;
        data.m_Size = 0;
        if ( data.m_Memory.m_nGrowSize >= 0 )
        {
          if ( data.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: data.m_Memory.m_pMemory);
            v23 = nullptr;
            data.m_Memory.m_pMemory = nullptr;
          }
          data.m_Memory.m_nAllocationCount = 0;
        }
        data.m_pElements = v23;
        if ( data.m_Memory.m_nGrowSize >= 0 && v23 != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v23);
      }
      else
      {
        v30->OnTerminateConnection(this: v30, a2: m_Head);
        CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::Unlink(
          this: &v30->m_Connections,
          elem: m_Head);
        v24 = v30;
        v30->m_Connections.m_Memory.m_pMemory[m_Head].m_Next = v30->m_Connections.m_FirstFree;
        v24->m_Connections.m_FirstFree = m_Head;
        if ( m_Element->m_pSocket != nullptr )
          m_Element->m_pSocket->Release(this: m_Element->m_pSocket);
        free(pMem: m_Element);
      }
      m_Head = iNext;
      if ( iNext == -1 )
        break;
      v1 = v30;
    }
  }
}

} // namespace vmpi_service_ui
