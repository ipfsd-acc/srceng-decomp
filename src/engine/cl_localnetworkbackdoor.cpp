// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/cl_localnetworkbackdoor.cpp
// Functions: 2
// ============================================================

#include "engine\cl_localnetworkbackdoor.h"

//------------------------------------------------------------------------------
// Address: 0x10087750
// Name: void CL_SetupLocalNetworkBackDoor(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_SetupLocalNetworkBackDoor(bool bUseBackDoor)
{
  CClientState *BaseLocalClient; // eax

  if ( bUseBackDoor )
  {
    if ( g_pLocalNetworkBackdoor == nullptr )
    {
      g_pLocalNetworkBackdoor = &s_LocalNetworkBackdoor;
      CLocalNetworkBackdoor::StartBackdoorMode(this: &s_LocalNetworkBackdoor);
    }
  }
  else if ( g_pLocalNetworkBackdoor != nullptr )
  {
    CLocalNetworkBackdoor::StopBackdoorMode(this: g_pLocalNetworkBackdoor);
    g_pLocalNetworkBackdoor = nullptr;
    BaseLocalClient = GetBaseLocalClient();
    CBaseClientState::ForceFullUpdate(this: BaseLocalClient, pchReason: "cl_localnetworkbackdoor state change");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10087810
// Name: public: CLocalNetworkBackdoor::CLocalNetworkBackdoor(void)
// Source: json
//------------------------------------------------------------------------------
CLocalNetworkBackdoor *__thiscall CLocalNetworkBackdoor::CLocalNetworkBackdoor(CLocalNetworkBackdoor *this)
{
  int v2; // ecx
  int *p_m_iSerialNumber; // eax

  if ( this != nullptr )
    memset(dst: (unsigned __int8 *)this, value: 0, count: 0x100u);
  if ( this != (CLocalNetworkBackdoor *)-256 )
    memset(dst: (unsigned __int8 *)&this->m_PrevEntsAlive, value: 0, count: sizeof(this->m_PrevEntsAlive));
  this->m_PendingDormantEntities.m_Memory.m_pMemory = nullptr;
  this->m_PendingDormantEntities.m_Memory.m_nAllocationCount = 0;
  this->m_PendingDormantEntities.m_Memory.m_nGrowSize = 0;
  this->m_PendingDormantEntities.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_PendingDormantEntities.m_FirstFree = 0xFFFF;
  this->m_PendingDormantEntities.m_pElements = this->m_PendingDormantEntities.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_PendingDormantEntities.m_Head = -1;
  this->m_PendingDormantEntities.m_NumAlloced = 0;
  v2 = 2047;
  p_m_iSerialNumber = &this->m_CachedEntState[0].m_iSerialNumber;
  do
  {
    *p_m_iSerialNumber = -1;
    p_m_iSerialNumber += 4;
    --v2;
  }
  while ( v2 >= 0 );
  return this;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10087470
// Name: void CL_SetupLocalNetworkBackDoor(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_SetupLocalNetworkBackDoor(bool bUseBackDoor)
{
  CClientState *BaseLocalClient; // eax

  if ( bUseBackDoor )
  {
    if ( g_pLocalNetworkBackdoor == nullptr )
    {
      g_pLocalNetworkBackdoor = &s_LocalNetworkBackdoor;
      CLocalNetworkBackdoor::StartBackdoorMode(this: &s_LocalNetworkBackdoor);
    }
  }
  else if ( g_pLocalNetworkBackdoor != nullptr )
  {
    CLocalNetworkBackdoor::StopBackdoorMode(this: g_pLocalNetworkBackdoor);
    g_pLocalNetworkBackdoor = nullptr;
    BaseLocalClient = GetBaseLocalClient();
    CBaseClientState::ForceFullUpdate(this: BaseLocalClient, pchReason: "cl_localnetworkbackdoor state change");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10087530
// Name: public: CLocalNetworkBackdoor::CLocalNetworkBackdoor(void)
// Source: json
//------------------------------------------------------------------------------
CLocalNetworkBackdoor *__thiscall CLocalNetworkBackdoor::CLocalNetworkBackdoor(CLocalNetworkBackdoor *this)
{
  int v2; // ecx
  int *p_m_iSerialNumber; // eax

  if ( this != nullptr )
    memset(dst: (unsigned __int8 *)this, value: 0, count: 0x100u);
  if ( this != (CLocalNetworkBackdoor *)-256 )
    memset(dst: (unsigned __int8 *)&this->m_PrevEntsAlive, value: 0, count: sizeof(this->m_PrevEntsAlive));
  this->m_PendingDormantEntities.m_Memory.m_pMemory = nullptr;
  this->m_PendingDormantEntities.m_Memory.m_nAllocationCount = 0;
  this->m_PendingDormantEntities.m_Memory.m_nGrowSize = 0;
  this->m_PendingDormantEntities.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_PendingDormantEntities.m_FirstFree = 0xFFFF;
  this->m_PendingDormantEntities.m_pElements = this->m_PendingDormantEntities.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_PendingDormantEntities.m_Head = -1;
  this->m_PendingDormantEntities.m_NumAlloced = 0;
  v2 = 2047;
  p_m_iSerialNumber = &this->m_CachedEntState[0].m_iSerialNumber;
  do
  {
    *p_m_iSerialNumber = -1;
    p_m_iSerialNumber += 4;
    --v2;
  }
  while ( v2 >= 0 );
  return this;
}

} // namespace engine_xlsp
