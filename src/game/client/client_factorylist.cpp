// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/client_factorylist.cpp
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x100A26D0
// Name: void FactoryList_Store(struct factorylist_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FactoryList_Store(const factorylist_t *sourceData)
{
  s_factories.appSystemFactory = sourceData->appSystemFactory;
}

//------------------------------------------------------------------------------
// Address: 0x100A26E0
// Name: void FactoryList_Retrieve(struct factorylist_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FactoryList_Retrieve(factorylist_t *destData)
{
  destData->appSystemFactory = s_factories.appSystemFactory;
}
