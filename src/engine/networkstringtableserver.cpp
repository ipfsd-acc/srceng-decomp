// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/networkstringtableserver.cpp
// Functions: 3
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x101C8300
// Name: void SV_CreateNetworkStringTables(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_CreateNetworkStringTables(const char *pchMapName)
{
  g_pStringTableDictionary->OnLevelLoadStart(this: g_pStringTableDictionary, a2: pchMapName, a3: nullptr);
  CNetworkStringTableContainer::RemoveAllTables(this: &s_NetworkStringTableServer);
  CNetMessage::SetReliable(this: (CNetMessage *)&s_NetworkStringTableServer, state: true);
  CGameServer::CreateEngineStringTables(this: &sv);
  serverGameDLL->CreateNetworkStringTables(this: serverGameDLL);
  CNetMessage::SetReliable(this: (CNetMessage *)&s_NetworkStringTableServer, state: false);
}

//------------------------------------------------------------------------------
// Address: 0x101C8350
// Name: void SV_PrintStringTables(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_PrintStringTables()
{
  CNetworkStringTableContainer::Dump(this: &s_NetworkStringTableServer);
}

//------------------------------------------------------------------------------
// Address: 0x101C8360
// Name: void SV_CreateDictionary(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_CreateDictionary(const char *pchMapName)
{
  CNetworkStringTableContainer::CreateDictionary(this: &s_NetworkStringTableServer, pchMapName);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x101C8760
// Name: void SV_CreateNetworkStringTables(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_CreateNetworkStringTables(const char *pchMapName)
{
  g_pStringTableDictionary->OnLevelLoadStart(this: g_pStringTableDictionary, a2: pchMapName, a3: nullptr);
  CNetworkStringTableContainer::RemoveAllTables(this: &s_NetworkStringTableServer);
  CNetMessage::SetReliable(this: (CNetMessage *)&s_NetworkStringTableServer, state: true);
  CGameServer::CreateEngineStringTables(this: &sv);
  serverGameDLL->CreateNetworkStringTables(this: serverGameDLL);
  CNetMessage::SetReliable(this: (CNetMessage *)&s_NetworkStringTableServer, state: false);
}

//------------------------------------------------------------------------------
// Address: 0x101C87B0
// Name: void SV_PrintStringTables(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_PrintStringTables()
{
  CNetworkStringTableContainer::Dump(this: &s_NetworkStringTableServer);
}

//------------------------------------------------------------------------------
// Address: 0x101C87C0
// Name: void SV_CreateDictionary(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_CreateDictionary(const char *pchMapName)
{
  CNetworkStringTableContainer::CreateDictionary(this: &s_NetworkStringTableServer, pchMapName);
}

//------------------------------------------------------------------------------
// Address: 0x1031D280
// Name: _dynamic_initializer_for__stringtable_usedictionaries__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__stringtable_usedictionaries__()
{
  ConVar::ConVar(
    this: &stringtable_usedictionaries,
    pName: "stringtable_usedictionaries",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Use dictionaries for string table networking\n");
  return atexit(func: dynamic_atexit_destructor_for__stringtable_usedictionaries__);
}

//------------------------------------------------------------------------------
// Address: 0x1031D2B0
// Name: _dynamic_initializer_for__stringtable_alwaysrebuilddictionaries__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__stringtable_alwaysrebuilddictionaries__()
{
  ConVar::ConVar(
    this: &stringtable_alwaysrebuilddictionaries,
    pName: "stringtable_alwaysrebuilddictionaries",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Rebuild dictionary file on every level load\n");
  return atexit(func: dynamic_atexit_destructor_for__stringtable_alwaysrebuilddictionaries__);
}

//------------------------------------------------------------------------------
// Address: 0x1031D2E0
// Name: _dynamic_initializer_for__stringtable_compress__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__stringtable_compress__()
{
  ConVar::ConVar(
    this: &stringtable_compress,
    pName: "stringtable_compress",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Compress string table for networking\n");
  return atexit(func: dynamic_atexit_destructor_for__stringtable_compress__);
}

//------------------------------------------------------------------------------
// Address: 0x1031D310
// Name: _dynamic_initializer_for__stringtable_showsizes__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__stringtable_showsizes__()
{
  ConVar::ConVar(
    this: &stringtable_showsizes,
    pName: "stringtable_showsizes",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Show sizes of string tables when building for signon\n");
  return atexit(func: dynamic_atexit_destructor_for__stringtable_showsizes__);
}

//------------------------------------------------------------------------------
// Address: 0x10326720
// Name: _dynamic_atexit_destructor_for__stringtable_usedictionaries__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__stringtable_usedictionaries__()
{
  ConVar::~ConVar(this: &stringtable_usedictionaries);
}

//------------------------------------------------------------------------------
// Address: 0x10326730
// Name: _dynamic_atexit_destructor_for__stringtable_alwaysrebuilddictionaries__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__stringtable_alwaysrebuilddictionaries__()
{
  ConVar::~ConVar(this: &stringtable_alwaysrebuilddictionaries);
}

//------------------------------------------------------------------------------
// Address: 0x10326740
// Name: _dynamic_atexit_destructor_for__stringtable_compress__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__stringtable_compress__()
{
  ConVar::~ConVar(this: &stringtable_compress);
}

//------------------------------------------------------------------------------
// Address: 0x10326750
// Name: _dynamic_atexit_destructor_for__stringtable_showsizes__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__stringtable_showsizes__()
{
  ConVar::~ConVar(this: &stringtable_showsizes);
}

//------------------------------------------------------------------------------
// Address: 0x1031D340
// Name: _dynamic_initializer_for__g_StringTableDictionary__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_StringTableDictionary__()
{
  CUtlString::CUtlString(this: &g_StringTableDictionary.m_sCurrentMap);
  g_StringTableDictionary.m_Strings.m_Memory.m_pMemory = nullptr;
  g_StringTableDictionary.m_Strings.m_Memory.m_nAllocationCount = 0;
  g_StringTableDictionary.m_Strings.m_Memory.m_nGrowSize = 0;
  g_StringTableDictionary.m_Strings.m_Size = 0;
  g_StringTableDictionary.m_Strings.m_pElements = nullptr;
  g_StringTableDictionary.m_StringHashToIndex.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const unsigned int *, const unsigned int *))CDmxSerializationDictionary::LessFunc;
  g_StringTableDictionary.m_StringHashToIndex.m_Tree.m_Elements.m_pMemory = nullptr;
  g_StringTableDictionary.m_StringHashToIndex.m_Tree.m_Elements.m_nAllocationCount = 0;
  g_StringTableDictionary.m_StringHashToIndex.m_Tree.m_Elements.m_nGrowSize = 0;
  *(_DWORD *)&g_StringTableDictionary.m_StringHashToIndex.m_Tree.m_Root = 0xFFFF;
  *(_DWORD *)&g_StringTableDictionary.m_StringHashToIndex.m_Tree.m_FirstFree = -1;
  g_StringTableDictionary.m_StringHashToIndex.m_Tree.m_pElements = nullptr;
  g_StringTableDictionary.m_CRC = 0;
  g_StringTableDictionary.m_nEncodeBits = 1;
  *(_WORD *)&g_StringTableDictionary.m_bForceRebuildDictionaries = 0;
  CNetworkStringTableDictionaryManager::CStringTableDictionaryCache::CStringTableDictionaryCache(this: &g_StringTableDictionary.m_BuildStringTableDictionaryCache);
  return atexit(func: dynamic_atexit_destructor_for__g_StringTableDictionary__);
}

//------------------------------------------------------------------------------
// Address: 0x10326760
// Name: _dynamic_atexit_destructor_for__g_StringTableDictionary__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_StringTableDictionary__()
{
  CNetworkStringTableDictionaryManager::~CNetworkStringTableDictionaryManager(this: &g_StringTableDictionary);
}

} // namespace engine_xlsp
