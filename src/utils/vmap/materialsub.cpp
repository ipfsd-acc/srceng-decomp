// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vmap/materialsub.cpp
// Functions: 3
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00428840
// Name: void LoadMaterialReplacementKeys(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoadMaterialReplacementKeys(const char *gamedir, char *mapname)
{
  KeyValues *v2; // eax
  char path[1024]; // [esp+8h] [ebp-400h] BYREF

  if ( kv != nullptr )
  {
    KeyValues::deleteThis(this: kv);
    kv = nullptr;
  }
  if ( allMapKeys != nullptr )
    allMapKeys = nullptr;
  if ( curMapKeys != nullptr )
    curMapKeys = nullptr;
  _Msg(a1: "Loading Replacement Keys\n");
  V_snprintf(pDest: path, maxLen: 1024, pFormat: "%scfg\\materialsub.cfg", gamedir);
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    kv = KeyValues::KeyValues(this: v2, setName: "MaterialReplacements");
  else
    kv = nullptr;
  _Msg(a1: "File path: %s", path);
  if ( KeyValues::LoadFromFile(
         this: kv,
         filesystem: g_pFileSystem,
         resourceName: path,
         pathID: nullptr,
         pfnEvaluateSymbolProc: nullptr) )
  {
    allMapKeys = KeyValues::FindKey(this: kv, keyName: "AllMaps", bCreate: true);
    curMapKeys = KeyValues::FindKey(this: kv, keyName: mapname, bCreate: false);
    CDmElement::ChangeHandle(this: allMapKeys, pChain: curMapKeys);
  }
  else
  {
    _Msg(a1: "Failed to load KeyValues file!\n");
    g_ReplaceMaterials = false;
    KeyValues::deleteThis(this: kv);
    kv = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00428970
// Name: void DeleteMaterialReplacementKeys(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DeleteMaterialReplacementKeys()
{
  if ( kv != nullptr )
  {
    KeyValues::deleteThis(this: kv);
    kv = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00428990
// Name: char const __near * ReplaceMaterialName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl ReplaceMaterialName(const char *name)
{
  char newName[1024]; // [esp+4h] [ebp-400h] BYREF

  V_strncpy(pDest: newName, pSrc: name, maxLen: 1024);
  V_FixSlashes(pname: newName, separator: 92);
  return KeyValues::GetString(this: allMapKeys, keyName: newName, defaultValue: name);
}
