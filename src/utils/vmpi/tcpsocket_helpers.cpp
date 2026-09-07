// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vmpi/tcpsocket_helpers.cpp
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x004039C0
// Name: bool TCPSocket_Connect(class ITCPSocket __near *,class CIPAddr const __near *,double)
// Source: json
//------------------------------------------------------------------------------
char __cdecl TCPSocket_Connect(ITCPSocket *pSocket, const CIPAddr *pAddr, long double flTimeout)
{
  CWaitTimer waitTimer; // [esp+14h] [ebp-8h] BYREF

  pSocket->BeginConnect(this: pSocket, a2: pAddr);
  CWaitTimer::CWaitTimer(this: &waitTimer, flSeconds: flTimeout);
  if ( pSocket->UpdateConnect(this: pSocket) )
    return 1;
  while ( CWaitTimer::ShouldKeepWaiting(this: &waitTimer) )
  {
    Sleep(dwMilliseconds: 0xAu);
    if ( pSocket->UpdateConnect(this: pSocket) )
      return 1;
  }
  return 0;
}

// ============================================================
// Overlay from vmpi_service_ui (Missing functions)
// ============================================================
namespace vmpi_service_ui {

//------------------------------------------------------------------------------
// Address: 0x00402450
// Name: bool TCPSocket_Connect(class ITCPSocket __near *,class CIPAddr const __near *,double)
// Source: json
//------------------------------------------------------------------------------
char __cdecl TCPSocket_Connect(ITCPSocket *pSocket, const CIPAddr *pAddr, long double flTimeout)
{
  CWaitTimer waitTimer; // [esp+14h] [ebp-8h] BYREF

  pSocket->BeginConnect(this: pSocket, a2: pAddr);
  CWaitTimer::CWaitTimer(this: &waitTimer, flSeconds: flTimeout);
  if ( pSocket->UpdateConnect(this: pSocket) )
    return 1;
  while ( CWaitTimer::ShouldKeepWaiting(this: &waitTimer) )
  {
    Sleep(dwMilliseconds: 0xAu);
    if ( pSocket->UpdateConnect(this: pSocket) )
      return 1;
  }
  return 0;
}

} // namespace vmpi_service_ui
