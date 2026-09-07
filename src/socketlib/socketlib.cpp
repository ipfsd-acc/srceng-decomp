// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: socketlib/socketlib.cpp
// Functions: 28
// ============================================================

#include "socketlib\socketlib.h"

//------------------------------------------------------------------------------
// Address: 0x004062C0
// Name: void SocketLibInit(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SocketLibInit()
{
  WSAData wsa_data; // [esp+0h] [ebp-190h] BYREF

  WSAStartup(wVersionRequested: 0x202u, lpWSAData: &wsa_data);
  s_SocketLibInitialized = true;
}

//------------------------------------------------------------------------------
// Address: 0x004062F0
// Name: void SocketLibShutdown(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall SocketLibShutdown()
{
  return WSACleanup();
}

//------------------------------------------------------------------------------
// Address: 0x00406300
// Name: char const __near * ConvertWinsockErrorToString(int)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl ConvertWinsockErrorToString(int errorCode)
{
  const char *result; // eax

  if ( errorCode == 0 )
    return "Success";
  if ( errorCode > 11001 )
  {
    switch ( errorCode )
    {
      case 11002:
        result = "WSATRY_AGAIN";
        break;
      case 11003:
        result = "WSANO_RECOVERY";
        break;
      case 11004:
        result = "WSANO_DATA";
        break;
      case 11005:
        result = "WSA_QOS_RECEIVERS";
        break;
      case 11006:
        result = "WSA_QOS_SENDERS";
        break;
      case 11007:
        result = "WSA_QOS_NO_SENDERS";
        break;
      case 11008:
        result = "WSA_QOS_NO_RECEIVERS";
        break;
      case 11009:
        result = "WSA_QOS_REQUEST_CONFIRMED";
        break;
      case 11010:
        result = "WSA_QOS_ADMISSION_FAILURE";
        break;
      case 11011:
        result = "WSA_QOS_POLICY_FAILURE";
        break;
      case 11012:
        result = "WSA_QOS_BAD_STYLE";
        break;
      case 11013:
        result = "WSA_QOS_BAD_OBJECT";
        break;
      case 11014:
        result = "WSA_QOS_TRAFFIC_CTRL_ERROR";
        break;
      case 11015:
        result = "WSA_QOS_GENERIC_ERROR";
        break;
      default:
LABEL_80:
        result = "Unrecognized error.";
        break;
    }
  }
  else if ( errorCode == 11001 )
  {
    return "WSAHOST_NOT_FOUND";
  }
  else
  {
    switch ( errorCode )
    {
      case 10004:
        result = "WSAEINTR";
        break;
      case 10009:
        result = "WSAEBADF";
        break;
      case 10013:
        result = "WSAEACCES";
        break;
      case 10014:
        result = "WSAEFAULT";
        break;
      case 10022:
        result = "WSAEINVAL";
        break;
      case 10024:
        result = "WSAEMFILE";
        break;
      case 10035:
        result = "WSAEWOULDBLOCK";
        break;
      case 10036:
        result = "WSAEINPROGRESS";
        break;
      case 10037:
        result = "WSAEALREADY";
        break;
      case 10038:
        result = "WSAENOTSOCK";
        break;
      case 10039:
        result = "WSAEDESTADDRREQ";
        break;
      case 10040:
        result = "WSAEMSGSIZE";
        break;
      case 10041:
        result = "WSAEPROTOTYPE";
        break;
      case 10042:
        result = "WSAENOPROTOOPT";
        break;
      case 10043:
        result = "WSAEPROTONOSUPPORT";
        break;
      case 10044:
        result = "WSAESOCKTNOSUPPORT";
        break;
      case 10045:
        result = "WSAEOPNOTSUPP";
        break;
      case 10046:
        result = "WSAEPFNOSUPPORT";
        break;
      case 10047:
        result = "WSAEAFNOSUPPORT";
        break;
      case 10048:
        result = "WSAEADDRINUSE";
        break;
      case 10049:
        result = "WSAEADDRNOTAVAIL";
        break;
      case 10050:
        result = "WSAENETDOWN";
        break;
      case 10051:
        result = "WSAENETUNREACH";
        break;
      case 10052:
        result = "WSAENETRESET";
        break;
      case 10053:
        result = "WSAECONNABORTED";
        break;
      case 10054:
        result = "WSAECONNRESET";
        break;
      case 10055:
        result = "WSAENOBUFS";
        break;
      case 10056:
        result = "WSAEISCONN";
        break;
      case 10057:
        result = "WSAENOTCONN";
        break;
      case 10058:
        result = "WSAESHUTDOWN";
        break;
      case 10059:
        result = "WSAETOOMANYREFS";
        break;
      case 10060:
        result = "WSAETIMEDOUT";
        break;
      case 10061:
        result = "WSAECONNREFUSED";
        break;
      case 10062:
        result = "WSAELOOP";
        break;
      case 10063:
        result = "WSAENAMETOOLONG";
        break;
      case 10064:
        result = "WSAEHOSTDOWN";
        break;
      case 10065:
        result = "WSAEHOSTUNREACH";
        break;
      case 10066:
        result = "WSAENOTEMPTY";
        break;
      case 10067:
        result = "WSAEPROCLIM";
        break;
      case 10068:
        result = "WSAEUSERS";
        break;
      case 10069:
        result = "WSAEDQUOT";
        break;
      case 10070:
        result = "WSAESTALE";
        break;
      case 10071:
        result = "WSAEREMOTE";
        break;
      case 10091:
        result = "WSASYSNOTREADY";
        break;
      case 10092:
        result = "WSAVERNOTSUPPORTED";
        break;
      case 10093:
        result = "WSANOTINITIALISED";
        break;
      case 10101:
        result = "WSAEDISCON";
        break;
      case 10102:
        result = "WSAENOMORE";
        break;
      case 10103:
        result = "WSAECANCELLED";
        break;
      case 10104:
        result = "WSAEINVALIDPROCTABLE";
        break;
      case 10105:
        result = "WSAEINVALIDPROVIDER";
        break;
      case 10106:
        result = "WSAEPROVIDERFAILEDINIT";
        break;
      case 10107:
        result = "WSASYSCALLFAILURE";
        break;
      case 10108:
        result = "WSASERVICE_NOT_FOUND";
        break;
      case 10109:
        result = "WSATYPE_NOT_FOUND";
        break;
      case 10110:
        result = "WSA_E_NO_MORE";
        break;
      case 10111:
        result = "WSA_E_CANCELLED";
        break;
      case 10112:
        result = "WSAEREFUSED";
        break;
      default:
        goto LABEL_80;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004066F0
// Name: char const __near * ConvertSocketLibErrorToString(enum SocketErrorCode_t)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl ConvertSocketLibErrorToString(SocketErrorCode_t errorCode)
{
  const char *result; // eax

  if ( errorCode == SOCKET_SUCCESS )
    return "Success";
  switch ( errorCode )
  {
    case SOCKET_ERR_OPERATION_NOT_SUPPORTED:
      result = "SOCKET_ERR_OPERATION_NOT_SUPPORTED";
      break;
    case SOCKET_ERR_CREATE_FAILED:
      result = "SOCKET_ERR_CREATE_FAILED";
      break;
    case SOCKET_ERR_READ_OPERATION_FAILED:
      result = "SOCKET_ERR_READ_OPERATION_FAILED";
      break;
    case SOCKET_ERR_WRITE_OPERATION_FAILED:
      result = "SOCKET_ERR_WRITE_OPERATION_FAILED";
      break;
    case SOCKET_ERR_CONNECT_FAILED:
      result = "SOCKET_ERR_CONNECT_FAILED";
      break;
    case SOCKET_ERR_LISTEN_FAILED:
      result = "SOCKET_ERR_LISTEN_FAILED";
      break;
    case SOCKET_ERR_ACCEPT_FAILED:
      result = "SOCKET_ERR_ACCEPT_FAILED";
      break;
    case SOCKET_ERR_POLLING_OPERATION_FAILED:
      result = "SOCKET_ERR_POLLING_OPERATION_FAILED";
      break;
    case SOCKET_ERR_BIND_OPERATION_FAILED:
      result = "SOCKET_ERR_BIND_OPERATION_FAILED";
      break;
    case SOCKET_ERR_ENABLE_NON_BLOCKING_MODE_FAILED:
      result = "SOCKET_ERR_ENABLE_NON_BLOCKING_MODE_FAILED";
      break;
    case SOCKET_ERR_HOST_NOT_FOUND:
      result = "SOCKET_ERR_HOST_NOT_FOUND";
      break;
    case SOCKET_ERR_GENERAL_SOCKET_ERROR:
      result = "SOCKET_ERR_GENERAL_SOCKET_ERROR";
      break;
    case SOCKET_ERR_READ_OPERATION_WOULD_BLOCK:
      result = "SOCKET_ERR_READ_OPERATION_WOULD_BLOCK";
      break;
    case SOCKET_ERR_WRITE_OPERATION_WOULD_BLOCK:
      result = "SOCKET_ERR_WRITE_OPERATION_WOULD_BLOCK";
      break;
    case SOCKET_ERR_CONNECTION_CLOSED:
      result = "SOCKET_ERR_CONNECTION_CLOSED";
      break;
    case SOCKET_ERR_CONNECTION_RESET:
      result = "SOCKET_ERR_CONNECTION_RESET";
      break;
    case SOCKET_ERR_NO_INCOMING_CONNECTIONS:
      result = "SOCKET_ERR_NO_INCOMING_CONNECTIONS";
      break;
    case SOCKET_ERR_NO_AVAILABLE_ENDPOINTS:
      result = "SOCKET_ERR_NO_AVAILABLE_ENDPOINTS";
      break;
    case SOCKET_ERR_BAD_USER_DATA:
      result = "SOCKET_ERR_BAD_USER_DATA";
      break;
    case SOCKET_ERR_INVALID_CONNECTION:
      result = "SOCKET_ERR_INVALID_CONNECTION";
      break;
    case SOCKET_ERR_CANT_WRITE:
      result = "SOCKET_ERR_CANT_WRITE";
      break;
    case SOCKET_ERR_MIXING_PACKET_SENDS:
      result = "SOCKET_ERR_MIXING_PACKET_SENDS";
      break;
    case SOCKET_ERR_PARTIAL_PACKET_OVERFLOW:
      result = "SOCKET_ERR_PARTIAL_PACKET_OVERFLOW";
      break;
    default:
      result = "Unrecognized error.";
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00406820
// Name: public: CSocketConnection::CSocketConnection(void)
// Source: json
//------------------------------------------------------------------------------
CSocketConnection *__thiscall CSocketConnection::CSocketConnection(CSocketConnection *this)
{
  int v1; // edx
  CSocketConnection *result; // eax
  int v3; // ecx

  v1 = HIDWORD(InvalidSocketHandle_0);
  result = this;
  v3 = InvalidSocketHandle_0;
  result->m_ListeningSocket = InvalidSocketHandle_0;
  result->m_ListeningSocketState = SSTATE_UNINITIALIZED;
  result->m_ConnectionType = CT_INDETERMINATE;
  result->m_SocketProtocol = SP_INDETERMINATE;
  result->m_LastError = SOCKET_SUCCESS;
  result->m_LastSystemError = 0;
  LODWORD(result->m_EndpointSockets[0]) = v3;
  HIDWORD(result->m_EndpointSockets[0]) = v1;
  result->m_EndpointStates[0] = SSTATE_UNINITIALIZED;
  LODWORD(result->m_EndpointSockets[1]) = v3;
  HIDWORD(result->m_EndpointSockets[1]) = v1;
  result->m_EndpointStates[1] = SSTATE_UNINITIALIZED;
  LODWORD(result->m_EndpointSockets[2]) = v3;
  HIDWORD(result->m_EndpointSockets[2]) = v1;
  result->m_EndpointStates[2] = SSTATE_UNINITIALIZED;
  LODWORD(result->m_EndpointSockets[3]) = v3;
  HIDWORD(result->m_EndpointSockets[3]) = v1;
  result->m_EndpointStates[3] = SSTATE_UNINITIALIZED;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00406870
// Name: public: enum SocketErrorCode_t CSocketConnection::Init(enum ConnectionType_t,enum SocketProtocol_t)
// Source: json
//------------------------------------------------------------------------------
SocketErrorCode_t __thiscall CSocketConnection::Init(
        CSocketConnection *this,
        ConnectionType_t connectionType,
        SocketProtocol_t socketProtocol)
{
  this->m_ConnectionType = connectionType;
  this->m_SocketProtocol = socketProtocol;
  this->m_LastError = SOCKET_SUCCESS;
  this->m_LastSystemError = 0;
  return SOCKET_SUCCESS;
}

//------------------------------------------------------------------------------
// Address: 0x00406890
// Name: public: enum SocketState_t CSocketConnection::GetEndpointSocketState(int)
// Source: json
//------------------------------------------------------------------------------
SocketState_t __thiscall CSocketConnection::GetEndpointSocketState(CSocketConnection *this, int endpointIndex)
{
  return this->m_EndpointStates[endpointIndex];
}

//------------------------------------------------------------------------------
// Address: 0x004068A0
// Name: public: char const __near * CSocketConnection::GetLastSystemErrorString(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CSocketConnection::GetLastSystemErrorString(CSocketConnection *this)
{
  return ConvertWinsockErrorToString(errorCode: this->m_LastSystemError);
}

//------------------------------------------------------------------------------
// Address: 0x004068B0
// Name: public: char const __near * CSocketConnection::GetLastErrorString(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CSocketConnection::GetLastErrorString(CSocketConnection *this)
{
  return ConvertSocketLibErrorToString(errorCode: this->m_LastError);
}

//------------------------------------------------------------------------------
// Address: 0x004068C0
// Name: CloseSocket
// Source: json
//------------------------------------------------------------------------------
void __usercall CloseSocket(__int64 *socket_handle@<esi>)
{
  if ( *socket_handle != InvalidSocketHandle_0 )
  {
    if ( shutdown(s: *(_DWORD *)socket_handle, how: 2) == -1 && WSAGetLastError() != 10057 )
      _Error(a1: "Cannot recover from failed socket shutdown.");
    closesocket(s: *(_DWORD *)socket_handle);
    *socket_handle = InvalidSocketHandle_0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406920
// Name: CanReadFromSocket
// Source: json
//------------------------------------------------------------------------------
int __usercall CanReadFromSocket@<eax>(SOCKET socket@<esi>, bool *canRead@<edi>)
{
  fd_set readable_set; // [esp+4h] [ebp-210h] BYREF
  fd_set error_set; // [esp+108h] [ebp-10Ch] BYREF
  timeval timeout; // [esp+20Ch] [ebp-8h] BYREF

  *canRead = false;
  timeout.tv_sec = 0;
  timeout.tv_usec = 0;
  memset(dst: (unsigned __int8 *)readable_set.fd_array, value: 0, count: sizeof(readable_set.fd_array));
  memset(dst: (unsigned __int8 *)error_set.fd_array, value: 0, count: sizeof(error_set.fd_array));
  readable_set.fd_array[0] = socket;
  readable_set.fd_count = 1;
  error_set.fd_array[0] = socket;
  error_set.fd_count = 1;
  if ( select(nfds: 0, readfds: &readable_set, writefds: nullptr, exceptfds: &error_set, &timeout) == -1 )
    return 8;
  if ( __WSAFDIsSet(fd: socket, a2: &error_set) != 0 )
    return 12;
  if ( __WSAFDIsSet(fd: socket, a2: &readable_set) != 0 )
    *canRead = true;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00406A30
// Name: CanWriteToSocket
// Source: json
//------------------------------------------------------------------------------
int __usercall CanWriteToSocket@<eax>(SOCKET socket@<esi>, bool *canWrite@<edi>)
{
  fd_set writeable_set; // [esp+4h] [ebp-210h] BYREF
  fd_set error_set; // [esp+108h] [ebp-10Ch] BYREF
  timeval timeout; // [esp+20Ch] [ebp-8h] BYREF

  *canWrite = false;
  timeout.tv_sec = 0;
  timeout.tv_usec = 0;
  memset(dst: (unsigned __int8 *)writeable_set.fd_array, value: 0, count: sizeof(writeable_set.fd_array));
  memset(dst: (unsigned __int8 *)error_set.fd_array, value: 0, count: sizeof(error_set.fd_array));
  writeable_set.fd_array[0] = socket;
  writeable_set.fd_count = 1;
  error_set.fd_array[0] = socket;
  error_set.fd_count = 1;
  if ( select(nfds: 0, readfds: nullptr, writefds: &writeable_set, exceptfds: &error_set, &timeout) == -1 )
    return 8;
  if ( __WSAFDIsSet(fd: socket, a2: &error_set) != 0 )
    return 12;
  if ( __WSAFDIsSet(fd: socket, a2: &writeable_set) != 0 )
    *canWrite = true;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00406B40
// Name: public: void CSocketMessageBuilder::FeedData(void const __near *,int,void (*)(struct MessageHeader_t const __near &,unsigned char const __near *,void __near *),void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSocketMessageBuilder::FeedData(
        CSocketMessageBuilder *this,
        char *data,
        const unsigned __int8 *dataLength,
        void (__cdecl *networkMessageHandlerFunc)(const MessageHeader_t *, const unsigned __int8 *, void *),
        void *userContext)
{
  int v5; // ebx
  signed int v7; // eax
  signed int v8; // edi
  int bytes_remaining; // [esp+Ch] [ebp-4h]

  v5 = (int)dataLength;
  bytes_remaining = (int)dataLength;
  if ( bytes_remaining > 0 )
  {
    do
    {
      v7 = this->m_MessageHeader.m_nLength - this->m_nMessageBytesRead;
      v8 = 4 - this->m_nHeaderBytesRead;
      if ( v8 <= 0 )
      {
        if ( v7 <= 0 )
        {
          _Error(a1: "Not sure how we got here.");
        }
        else
        {
          if ( v7 < v5 )
            v5 = this->m_MessageHeader.m_nLength - this->m_nMessageBytesRead;
          CUtlBuffer::Put(this: &this->m_MessageData, pMem: data, size: v5);
          this->m_nMessageBytesRead += v5;
          data += v5;
          bytes_remaining -= v5;
          if ( this->m_nMessageBytesRead == this->m_MessageHeader.m_nLength )
          {
            networkMessageHandlerFunc(
              a1: &this->m_MessageHeader,
              a2: this->m_MessageData.m_Memory.m_pMemory,
              a3: userContext);
            this->m_nHeaderBytesRead = 0;
            this->m_nMessageBytesRead = 0;
            this->m_MessageData.m_Get = 0;
            this->m_MessageData.m_Put = 0;
            this->m_MessageData.m_Error = 0;
            this->m_MessageData.m_nOffset = 0;
            this->m_MessageData.m_nMaxPut = -1;
            CUtlBuffer::AddNullTermination(this: &this->m_MessageData, nPut: 0);
          }
          v5 = bytes_remaining;
        }
      }
      else
      {
        if ( v8 >= v5 )
          v8 = v5;
        memcpy(dst: (unsigned __int8 *)this + this->m_nHeaderBytesRead, src: (unsigned __int8 *)data, count: v8);
        this->m_nHeaderBytesRead += v8;
        data += v8;
        v5 -= v8;
        bytes_remaining = v5;
        if ( this->m_nHeaderBytesRead == 4 )
          this->m_MessageHeader.m_nLength = _byteswap_ulong(this->m_MessageHeader.m_nLength);
      }
    }
    while ( v5 > 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406C30
// Name: public: enum SocketErrorCode_t CSocketConnection::TryAcceptIncomingConnection(int __near *)
// Source: json
//------------------------------------------------------------------------------
SocketErrorCode_t __thiscall CSocketConnection::TryAcceptIncomingConnection(
        CSocketConnection *this,
        int newEndpointIndex)
{
  _DWORD *v2; // ebx
  int v4; // edi
  SocketState_t *i; // eax
  SOCKET v7; // eax
  int Error; // eax
  SOCKET m_ListeningSocket; // [esp-Ch] [ebp-28h]
  sockaddr_in client_info; // [esp+Ch] [ebp-10h] BYREF

  v2 = (_DWORD *)newEndpointIndex;
  *(_DWORD *)newEndpointIndex = -1;
  v4 = 0;
  for ( i = this->m_EndpointStates; *i != SSTATE_LISTENING; ++i )
  {
    if ( ++v4 >= 4 )
    {
      this->m_LastSystemError = 0;
      this->m_LastError = SOCKET_ERR_NO_AVAILABLE_ENDPOINTS;
      return SOCKET_ERR_NO_AVAILABLE_ENDPOINTS;
    }
  }
  if ( v4 == -1 )
  {
    this->m_LastSystemError = 0;
    this->m_LastError = SOCKET_ERR_NO_AVAILABLE_ENDPOINTS;
    return SOCKET_ERR_NO_AVAILABLE_ENDPOINTS;
  }
  else
  {
    m_ListeningSocket = this->m_ListeningSocket;
    newEndpointIndex = 16;
    v7 = accept(s: m_ListeningSocket, addr: (struct sockaddr *)&client_info, addrlen: &newEndpointIndex);
    if ( v7 == -1 )
    {
      Error = WSAGetLastError();
      this->m_LastSystemError = Error;
      if ( Error == 10035 )
        this->m_LastError = SOCKET_ERR_NO_INCOMING_CONNECTIONS;
      else
        this->m_LastError = SOCKET_ERR_ACCEPT_FAILED;
      return this->m_LastError;
    }
    else
    {
      *v2 = v4;
      LODWORD(this->m_EndpointSockets[v4]) = v7;
      HIDWORD(this->m_EndpointSockets[v4]) = 0;
      this->m_EndpointStates[v4] = SSTATE_CONNECTED;
      this->m_LastError = SOCKET_SUCCESS;
      this->m_LastSystemError = 0;
      return SOCKET_SUCCESS;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406D10
// Name: private: void CSocketConnection::ResetEndpoint(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSocketConnection::ResetEndpoint(CSocketConnection *this, int endpointIndex)
{
  if ( this->m_ConnectionType == CT_CLIENT )
  {
    this->m_EndpointStates[endpointIndex] = SSTATE_UNINITIALIZED;
    CloseSocket(socket_handle: &this->m_EndpointSockets[endpointIndex]);
  }
  else if ( this->m_ConnectionType == CT_SERVER )
  {
    this->m_EndpointStates[endpointIndex] = SSTATE_LISTENING;
    CloseSocket(socket_handle: &this->m_EndpointSockets[endpointIndex]);
  }
  else
  {
    _Error(a1: "Invalid connection type.");
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406D70
// Name: CreateNonBlockingSocket
// Source: json
//------------------------------------------------------------------------------
int __usercall CreateNonBlockingSocket@<eax>(SocketProtocol_t socketProtocol@<eax>, __int64 *new_socket_handle@<ecx>)
{
  int v2; // eax
  int v4; // eax
  SOCKET v5; // eax
  unsigned int non_blocking_value; // [esp+4h] [ebp-4h] BYREF

  v2 = socketProtocol - 1;
  if ( v2 != 0 )
  {
    v4 = v2 - 1;
    if ( v4 == 0 )
    {
      _Error(a1: "VDP is not supported on this platform.");
      goto LABEL_9;
    }
    if ( v4 != 1 )
    {
      _Error(a1: "Unknown protocol.");
LABEL_9:
      *new_socket_handle = InvalidSocketHandle_0;
      return 2;
    }
    v5 = socket(af: 2, type: 1, protocol: 6);
  }
  else
  {
    v5 = socket(af: 2, type: 2, protocol: 17);
  }
  if ( v5 == -1 )
    goto LABEL_9;
  *(_DWORD *)new_socket_handle = v5;
  *((_DWORD *)new_socket_handle + 1) = 0;
  non_blocking_value = 1;
  if ( ioctlsocket(s: v5, cmd: -2147195266, argp: &non_blocking_value) != -1 )
    return 0;
  CloseSocket(socket_handle: new_socket_handle);
  return 10;
}

//------------------------------------------------------------------------------
// Address: 0x00406E10
// Name: public: enum SocketErrorCode_t CSocketConnection::Listen(unsigned short,int)
// Source: json
//------------------------------------------------------------------------------
SocketErrorCode_t __thiscall CSocketConnection::Listen(
        CSocketConnection *this,
        u_short localPort,
        int numAllowedConnections)
{
  SocketErrorCode_t NonBlockingSocket; // eax
  sockaddr_in sa; // [esp+4h] [ebp-10h] BYREF

  NonBlockingSocket = CreateNonBlockingSocket(
                        socketProtocol: this->m_SocketProtocol,
                        new_socket_handle: &this->m_ListeningSocket);
  this->m_LastError = NonBlockingSocket;
  if ( NonBlockingSocket != SOCKET_SUCCESS )
    goto LABEL_4;
  sa.sin_family = 2;
  sa.sin_addr.S_un.S_addr = 0;
  sa.sin_port = htons(hostshort: localPort);
  if ( bind(s: this->m_ListeningSocket, name: (const struct sockaddr *)&sa, namelen: 16) != 0 )
  {
    CloseSocket(socket_handle: &this->m_ListeningSocket);
    this->m_LastError = SOCKET_ERR_BIND_OPERATION_FAILED;
LABEL_4:
    this->m_LastSystemError = WSAGetLastError();
    return this->m_LastError;
  }
  if ( listen(s: this->m_ListeningSocket, backlog: 16) == -1 )
  {
    CloseSocket(socket_handle: &this->m_ListeningSocket);
    this->m_LastError = SOCKET_ERR_LISTEN_FAILED;
    this->m_LastSystemError = WSAGetLastError();
    return this->m_LastError;
  }
  else
  {
    this->m_ListeningSocketState = SSTATE_LISTENING;
    if ( numAllowedConnections > 0 )
      memset32(this->m_EndpointStates, 1, numAllowedConnections);
    this->m_LastError = SOCKET_SUCCESS;
    this->m_LastSystemError = 0;
    return SOCKET_SUCCESS;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406EE0
// Name: public: enum SocketErrorCode_t CSocketConnection::CanReadFromEndpoint(int,bool __near *)
// Source: json
//------------------------------------------------------------------------------
SocketErrorCode_t __thiscall CSocketConnection::CanReadFromEndpoint(
        CSocketConnection *this,
        int endpointIndex,
        bool *canRead)
{
  SocketErrorCode_t result; // eax
  __int64 *socket_handle; // [esp+Ch] [ebp-4h]

  socket_handle = &this->m_EndpointSockets[endpointIndex];
  result = CanReadFromSocket(socket: *(_DWORD *)socket_handle, canRead);
  this->m_LastError = result;
  if ( result != SOCKET_SUCCESS )
  {
    if ( this->m_ConnectionType == CT_CLIENT )
    {
      this->m_EndpointStates[endpointIndex] = SSTATE_UNINITIALIZED;
    }
    else
    {
      if ( this->m_ConnectionType != CT_SERVER )
      {
        _Error(a1: "Invalid connection type.");
        this->m_LastSystemError = WSAGetLastError();
        return this->m_LastError;
      }
      this->m_EndpointStates[endpointIndex] = SSTATE_LISTENING;
    }
    CloseSocket(socket_handle);
    this->m_LastSystemError = WSAGetLastError();
    return this->m_LastError;
  }
  else
  {
    this->m_LastSystemError = 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00406F80
// Name: public: enum SocketErrorCode_t CSocketConnection::CanWriteToEndpoint(int,bool __near *)
// Source: json
//------------------------------------------------------------------------------
SocketErrorCode_t __thiscall CSocketConnection::CanWriteToEndpoint(
        CSocketConnection *this,
        int endpointIndex,
        bool *canWrite)
{
  SocketErrorCode_t result; // eax
  __int64 *socket_handle; // [esp+Ch] [ebp-4h]

  socket_handle = &this->m_EndpointSockets[endpointIndex];
  result = CanWriteToSocket(socket: *(_DWORD *)socket_handle, canWrite);
  this->m_LastError = result;
  if ( result != SOCKET_SUCCESS )
  {
    if ( this->m_ConnectionType == CT_CLIENT )
    {
      this->m_EndpointStates[endpointIndex] = SSTATE_UNINITIALIZED;
    }
    else
    {
      if ( this->m_ConnectionType != CT_SERVER )
      {
        _Error(a1: "Invalid connection type.");
        this->m_LastSystemError = WSAGetLastError();
        return this->m_LastError;
      }
      this->m_EndpointStates[endpointIndex] = SSTATE_LISTENING;
    }
    CloseSocket(socket_handle);
    this->m_LastSystemError = WSAGetLastError();
    return this->m_LastError;
  }
  else
  {
    this->m_LastSystemError = 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00407020
// Name: public: enum SocketErrorCode_t CSocketConnection::ReadFromEndpoint(int,unsigned char __near *,int,int __near *)
// Source: json
//------------------------------------------------------------------------------
SocketErrorCode_t __thiscall CSocketConnection::ReadFromEndpoint(
        CSocketConnection *this,
        int endpointIndex,
        unsigned __int8 *destinationBuffer,
        int bufferSize,
        int *bytesRead)
{
  int v6; // eax
  int Error; // eax
  int v8; // eax

  *bytesRead = 0;
  v6 = recv(s: this->m_EndpointSockets[endpointIndex], buf: (char *)destinationBuffer, len: bufferSize, flags: 0);
  if ( v6 == -1 )
  {
    Error = WSAGetLastError();
    this->m_LastSystemError = Error;
    v8 = Error - 10035;
    if ( v8 != 0 )
    {
      if ( v8 == 19 )
        this->m_LastError = SOCKET_ERR_CONNECTION_RESET;
      else
        this->m_LastError = SOCKET_ERR_READ_OPERATION_FAILED;
      CSocketConnection::ResetEndpoint(this, endpointIndex);
      return this->m_LastError;
    }
    else
    {
      this->m_LastError = SOCKET_ERR_READ_OPERATION_WOULD_BLOCK;
      return this->m_LastError;
    }
  }
  else if ( v6 != 0 )
  {
    *bytesRead = v6;
    this->m_LastError = SOCKET_SUCCESS;
    this->m_LastSystemError = 0;
    return SOCKET_SUCCESS;
  }
  else
  {
    CSocketConnection::ResetEndpoint(this, endpointIndex);
    this->m_LastError = SOCKET_ERR_CONNECTION_CLOSED;
    this->m_LastSystemError = 0;
    return SOCKET_ERR_CONNECTION_CLOSED;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004070E0
// Name: public: enum SocketErrorCode_t CSocketConnection::WriteToEndpoint(int,unsigned char __near *,int,int __near *)
// Source: json
//------------------------------------------------------------------------------
SocketErrorCode_t __thiscall CSocketConnection::WriteToEndpoint(
        CSocketConnection *this,
        int endpointIndex,
        unsigned __int8 *sourceBuffer,
        int bufferSize,
        int *bytesWritten)
{
  int v6; // eax
  int Error; // eax
  int v8; // eax

  *bytesWritten = 0;
  v6 = send(s: this->m_EndpointSockets[endpointIndex], buf: (const char *)sourceBuffer, len: bufferSize, flags: 0);
  if ( v6 == -1 )
  {
    Error = WSAGetLastError();
    this->m_LastSystemError = Error;
    v8 = Error - 10035;
    if ( v8 != 0 )
    {
      if ( v8 == 19 )
      {
        this->m_LastError = SOCKET_ERR_CONNECTION_RESET;
        CSocketConnection::ResetEndpoint(this, endpointIndex);
      }
      else
      {
        this->m_LastError = SOCKET_ERR_WRITE_OPERATION_FAILED;
      }
      return this->m_LastError;
    }
    else
    {
      this->m_LastError = SOCKET_ERR_WRITE_OPERATION_WOULD_BLOCK;
      return this->m_LastError;
    }
  }
  else
  {
    if ( v6 != 0 )
      *bytesWritten = v6;
    this->m_LastError = SOCKET_SUCCESS;
    this->m_LastSystemError = 0;
    return SOCKET_SUCCESS;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407180
// Name: public: CSocketMessageBuilder::~CSocketMessageBuilder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSocketMessageBuilder::~CSocketMessageBuilder(CSocketMessageBuilder *this)
{
  if ( this->m_pRecvBuf != nullptr )
    operator delete(p: this->m_pRecvBuf);
  if ( this->m_MessageData.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_MessageData.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_MessageData.m_Memory.m_pMemory);
      this->m_MessageData.m_Memory.m_pMemory = nullptr;
    }
    this->m_MessageData.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004071C0
// Name: public: enum SocketErrorCode_t CSocketMessageBuilder::SendDataPacket(void const restrict __near *,int)
// Source: json
//------------------------------------------------------------------------------
SocketErrorCode_t __thiscall CSocketMessageBuilder::SendDataPacket(
        CSocketMessageBuilder *this,
        unsigned __int8 *data,
        int dataLength)
{
  int v4; // edi
  bool m_bSendingPartialMessage; // al
  SocketErrorCode_t result; // eax
  int bytesWritten; // [esp+10h] [ebp-8h] BYREF
  MessageHeader_t pHeader; // [esp+14h] [ebp-4h] BYREF

  if ( data != nullptr )
  {
    v4 = dataLength;
    if ( dataLength > 0 )
    {
      if ( this->m_pConnection == nullptr || this->m_nConnectionEndpoint == -1 )
        return SOCKET_ERR_INVALID_CONNECTION;
      m_bSendingPartialMessage = this->m_bSendingPartialMessage;
      if ( !m_bSendingPartialMessage || dataLength + this->m_PartialMessageBytesSent <= this->m_PartialMessageBytesTotal )
      {
        bytesWritten = 0;
        HIBYTE(dataLength) = 0;
        if ( m_bSendingPartialMessage )
        {
          if ( this->m_PartialMessageBytesSent != 0 )
            goto LABEL_15;
          pHeader.m_nLength = this->m_PartialMessageBytesTotal;
        }
        else
        {
          pHeader.m_nLength = v4;
        }
        pHeader.m_nLength = _byteswap_ulong(pHeader.m_nLength);
        result = CSocketConnection::CanWriteToEndpoint(
                   this: this->m_pConnection,
                   endpointIndex: this->m_nConnectionEndpoint,
                   canWrite: (bool *)&dataLength + 3);
        if ( result != SOCKET_SUCCESS )
          return result;
        if ( HIBYTE(dataLength) == 0 )
          return SOCKET_ERR_CANT_WRITE;
        result = CSocketConnection::WriteToEndpoint(
                   this: this->m_pConnection,
                   endpointIndex: this->m_nConnectionEndpoint,
                   sourceBuffer: (unsigned __int8 *)&pHeader,
                   bufferSize: 4,
                   &bytesWritten);
        if ( result != SOCKET_SUCCESS )
          return result;
        result = SOCKET_ERR_WRITE_OPERATION_FAILED;
        if ( bytesWritten != 4 )
          return result;
LABEL_15:
        result = CSocketConnection::CanWriteToEndpoint(
                   this: this->m_pConnection,
                   endpointIndex: this->m_nConnectionEndpoint,
                   canWrite: (bool *)&dataLength + 3);
        if ( result != SOCKET_SUCCESS )
          return result;
        if ( HIBYTE(dataLength) == 0 )
          return SOCKET_ERR_CANT_WRITE;
        result = CSocketConnection::WriteToEndpoint(
                   this: this->m_pConnection,
                   endpointIndex: this->m_nConnectionEndpoint,
                   sourceBuffer: data,
                   bufferSize: v4,
                   &bytesWritten);
        if ( bytesWritten != v4 )
          return SOCKET_ERR_WRITE_OPERATION_FAILED;
        if ( this->m_bSendingPartialMessage )
        {
          this->m_PartialMessageBytesSent += v4;
          if ( this->m_PartialMessageBytesSent >= this->m_PartialMessageBytesTotal )
          {
            this->m_bSendingPartialMessage = false;
            this->m_PartialMessageBytesSent = 0;
            this->m_PartialMessageBytesTotal = 0;
          }
        }
        return result;
      }
    }
  }
  return SOCKET_ERR_BAD_USER_DATA;
}

//------------------------------------------------------------------------------
// Address: 0x00407310
// Name: public: enum SocketErrorCode_t CSocketMessageBuilder::SendDataPacket(class CSocketConnection __near *,int,void const restrict __near *,int)
// Source: json
//------------------------------------------------------------------------------
SocketErrorCode_t __thiscall CSocketMessageBuilder::SendDataPacket(
        CSocketMessageBuilder *this,
        CSocketConnection *pConnection,
        int endpoint,
        unsigned __int8 *data,
        int dataLength)
{
  this->m_pConnection = pConnection;
  if ( pConnection != nullptr )
    this->m_nConnectionEndpoint = endpoint;
  else
    this->m_nConnectionEndpoint = -1;
  return CSocketMessageBuilder::SendDataPacket(this, data, dataLength);
}

//------------------------------------------------------------------------------
// Address: 0x00407350
// Name: public: enum SocketErrorCode_t CSocketMessageBuilder::BeginSendPartialDataPacket(unsigned int,void const restrict __near *,int)
// Source: json
//------------------------------------------------------------------------------
SocketErrorCode_t __thiscall CSocketMessageBuilder::BeginSendPartialDataPacket(
        CSocketMessageBuilder *this,
        unsigned int totalSize,
        unsigned __int8 *data,
        int dataLength)
{
  if ( this->m_bSendingPartialMessage )
    return SOCKET_ERR_MIXING_PACKET_SENDS;
  if ( totalSize < 2 )
    return SOCKET_ERR_BAD_USER_DATA;
  this->m_PartialMessageBytesTotal = totalSize;
  this->m_PartialMessageBytesSent = 0;
  this->m_bSendingPartialMessage = true;
  return CSocketMessageBuilder::SendDataPacket(this, data, dataLength);
}

//------------------------------------------------------------------------------
// Address: 0x004073A0
// Name: public: enum SocketErrorCode_t CSocketMessageBuilder::BeginSendPartialDataPacket(class CSocketConnection __near *,int,unsigned int,void const restrict __near *,int)
// Source: json
//------------------------------------------------------------------------------
SocketErrorCode_t __thiscall CSocketMessageBuilder::BeginSendPartialDataPacket(
        CSocketMessageBuilder *this,
        CSocketConnection *pConnection,
        int endpoint,
        unsigned int totalSize,
        unsigned __int8 *data,
        int dataLength)
{
  bool v7; // zf

  this->m_pConnection = pConnection;
  if ( pConnection == nullptr )
    endpoint = -1;
  v7 = !this->m_bSendingPartialMessage;
  this->m_nConnectionEndpoint = endpoint;
  if ( !v7 )
    return SOCKET_ERR_MIXING_PACKET_SENDS;
  if ( totalSize < 2 )
    return SOCKET_ERR_BAD_USER_DATA;
  this->m_PartialMessageBytesTotal = totalSize;
  this->m_PartialMessageBytesSent = 0;
  this->m_bSendingPartialMessage = true;
  return CSocketMessageBuilder::SendDataPacket(this, data, dataLength);
}

//------------------------------------------------------------------------------
// Address: 0x00407400
// Name: public: CSocketMessageBuilder::CSocketMessageBuilder(int,int)
// Source: json
//------------------------------------------------------------------------------
CSocketMessageBuilder *__thiscall CSocketMessageBuilder::CSocketMessageBuilder(
        CSocketMessageBuilder *this,
        int initialSize,
        int growSize)
{
  this->m_nHeaderBytesRead = 0;
  this->m_nMessageBytesRead = 0;
  this->m_pConnection = nullptr;
  this->m_nConnectionEndpoint = -1;
  CUtlBuffer::CUtlBuffer(this: &this->m_MessageData, growSize, initSize: initialSize, nFlags: 0);
  this->m_PartialMessageBytesSent = 0;
  this->m_PartialMessageBytesTotal = 0;
  this->m_bSendingPartialMessage = false;
  this->m_MessageHeader.m_nLength = 0;
  this->m_bSwappedHeader = false;
  this->m_nRecvBufSize = 0x10000;
  this->m_pRecvBuf = (unsigned __int8 *)operator new(size: 0x10000u);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00407458
// Name: __WSAFDIsSet(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall __WSAFDIsSet(SOCKET fd, fd_set *a2)
{
  return __imp____WSAFDIsSet@8(fd, a2);
}
