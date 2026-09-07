// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/init_factory.cpp
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10162A50
// Name: void FactoryList_Store(struct factorylist_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FactoryList_Store(const factorylist_t *sourceData)
{
  void *(__cdecl *fileSystemFactory)(const char *, int *); // eax

  fileSystemFactory = sourceData->fileSystemFactory;
  *(_QWORD *)&s_factories.engineFactory = *(_QWORD *)&sourceData->engineFactory;
  s_factories.fileSystemFactory = fileSystemFactory;
}

//------------------------------------------------------------------------------
// Address: 0x10162A70
// Name: void FactoryList_Retrieve(struct factorylist_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FactoryList_Retrieve(factorylist_t *destData)
{
  *destData = s_factories;
}
