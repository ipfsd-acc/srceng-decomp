// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/networkstringtableclient.cpp
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x101C7F30
// Name: void CL_PrintStringTables(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_PrintStringTables()
{
  CClientState *BaseLocalClient; // eax

  if ( GetBaseLocalClient()->m_StringTableContainer != nullptr )
  {
    BaseLocalClient = GetBaseLocalClient();
    CNetworkStringTableContainer::Dump(this: BaseLocalClient->m_StringTableContainer);
  }
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x101C8370
// Name: void CL_PrintStringTables(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_PrintStringTables()
{
  CClientState *BaseLocalClient; // eax

  if ( GetBaseLocalClient()->m_StringTableContainer != nullptr )
  {
    BaseLocalClient = GetBaseLocalClient();
    CNetworkStringTableContainer::Dump(this: BaseLocalClient->m_StringTableContainer);
  }
}

} // namespace engine_xlsp
