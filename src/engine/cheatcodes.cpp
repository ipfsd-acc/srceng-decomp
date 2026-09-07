// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/cheatcodes.cpp
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x101498D0
// Name: void ClearCheatCommands(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClearCheatCommands()
{
  s_CheatCodeCommands.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x101498E0
// Name: void ReadCheatCommandsFromFile(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ReadCheatCommandsFromFile(char *pchFileName)
{
  KeyValues *v1; // eax
  KeyValues *v2; // esi
  IBaseFileSystem *v3; // eax
  KeyValues *FirstTrueSubKey; // edi
  int m_Size; // eax
  int v6; // esi
  CheatCodeData_t *m_pMemory; // ecx
  int v8; // eax
  CheatCodeData_t *v9; // esi
  const char *Name; // eax
  char *String; // eax
  KeyValues *i; // ebx
  const char *v13; // eax
  IInputSystem_vtbl *v14; // edi
  char *v15; // eax
  int v16; // eax
  const char *v17; // eax
  KeyValues *pCheatCodeKeys; // [esp+4h] [ebp-8h]
  KeyValues *pKey; // [esp+8h] [ebp-4h]

  v1 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v1 != nullptr )
  {
    v2 = KeyValues::KeyValues(this: v1, setName: "cheat_codes");
    pCheatCodeKeys = v2;
  }
  else
  {
    pCheatCodeKeys = nullptr;
    v2 = nullptr;
  }
  if ( g_pFullFileSystem != nullptr )
    v3 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v3 = nullptr;
  if ( KeyValues::LoadFromFile(
         this: v2,
         filesystem: v3,
         resourceName: pchFileName,
         pathID: nullptr,
         pfnEvaluateSymbolProc: nullptr) )
  {
    FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: v2);
    pKey = FirstTrueSubKey;
    if ( FirstTrueSubKey != nullptr )
    {
      while ( 1 )
      {
        m_Size = s_CheatCodeCommands.m_Size;
        v6 = s_CheatCodeCommands.m_Size;
        if ( s_CheatCodeCommands.m_Size + 1 > s_CheatCodeCommands.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<CheatCodeData_t,int>::Grow(
            this: &s_CheatCodeCommands.m_Memory,
            num: s_CheatCodeCommands.m_Size - s_CheatCodeCommands.m_Memory.m_nAllocationCount + 1);
          m_Size = s_CheatCodeCommands.m_Size;
        }
        m_pMemory = s_CheatCodeCommands.m_Memory.m_pMemory;
        s_CheatCodeCommands.m_Size = m_Size + 1;
        v8 = m_Size - v6;
        s_CheatCodeCommands.m_pElements = s_CheatCodeCommands.m_Memory.m_pMemory;
        if ( v8 > 0 )
        {
          _V_memmove(
            dest: &s_CheatCodeCommands.m_Memory.m_pMemory[v6 + 1],
            src: &s_CheatCodeCommands.m_Memory.m_pMemory[v6],
            count: 208 * v8);
          m_pMemory = s_CheatCodeCommands.m_Memory.m_pMemory;
        }
        v9 = &m_pMemory[v6];
        Name = KeyValues::GetName(this: FirstTrueSubKey);
        V_strncpy(pDest: v9->szName, pSrc: Name, maxLen: 32);
        v9->bDevOnly = KeyValues::GetInt(this: FirstTrueSubKey, keyName: "dev", defaultValue: 0) != 0;
        v9->iCodeLength = 0;
        String = KeyValues::GetString(
                   this: FirstTrueSubKey,
                   keyName: "command",
                   defaultValue: "echo \"Cheat code has no command!\"");
        V_strncpy(pDest: v9->szCommand, pSrc: String, maxLen: 128);
        for ( i = KeyValues::GetFirstSubKey(this: FirstTrueSubKey); i != nullptr; i = KeyValues::GetNextKey(this: i) )
        {
          v13 = KeyValues::GetName(this: i);
          if ( _V_strcmp(s1: v13, s2: "code") == 0 )
          {
            v14 = g_pInputSystem->__vftable;
            v15 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: defaultValue);
            v16 = v14->StringToButtonCode(this: g_pInputSystem, a2: v15);
            FirstTrueSubKey = pKey;
            v9->pButtonCodes[v9->iCodeLength++] = v16;
          }
        }
        if ( v9->iCodeLength < 32 )
        {
          v17 = KeyValues::GetName(this: FirstTrueSubKey);
          DevWarning(a1: "Cheat code \"%s\" has less than %i code elements!", v17, 32);
        }
        pKey = KeyValues::GetNextTrueSubKey(this: FirstTrueSubKey);
        if ( pKey == nullptr )
          break;
        FirstTrueSubKey = pKey;
      }
      v2 = pCheatCodeKeys;
    }
  }
  KeyValues::deleteThis(this: v2);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10149A30
// Name: void ClearCheatCommands(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ClearCheatCommands()
{
  s_CheatCodeCommands.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10149A40
// Name: void ReadCheatCommandsFromFile(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ReadCheatCommandsFromFile(char *pchFileName)
{
  KeyValues *v1; // eax
  KeyValues *v2; // esi
  IBaseFileSystem *v3; // eax
  KeyValues *FirstTrueSubKey; // edi
  int m_Size; // eax
  int v6; // esi
  CheatCodeData_t *m_pMemory; // ecx
  int v8; // eax
  CheatCodeData_t *v9; // esi
  const char *Name; // eax
  const char *String; // eax
  KeyValues *i; // ebx
  const char *v13; // eax
  IInputSystem_vtbl *v14; // edi
  const char *v15; // eax
  int v16; // eax
  const char *v17; // eax
  KeyValues *pCheatCodeKeys; // [esp+4h] [ebp-8h]
  KeyValues *pKey; // [esp+8h] [ebp-4h]

  v1 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v1 != nullptr )
  {
    v2 = KeyValues::KeyValues(this: v1, setName: "cheat_codes");
    pCheatCodeKeys = v2;
  }
  else
  {
    pCheatCodeKeys = nullptr;
    v2 = nullptr;
  }
  if ( g_pFullFileSystem != nullptr )
    v3 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v3 = nullptr;
  if ( KeyValues::LoadFromFile(
         this: v2,
         filesystem: v3,
         resourceName: pchFileName,
         pathID: nullptr,
         pfnEvaluateSymbolProc: nullptr) )
  {
    FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: v2);
    pKey = FirstTrueSubKey;
    if ( FirstTrueSubKey != nullptr )
    {
      while ( 1 )
      {
        m_Size = s_CheatCodeCommands.m_Size;
        v6 = s_CheatCodeCommands.m_Size;
        if ( s_CheatCodeCommands.m_Size + 1 > s_CheatCodeCommands.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<CheatCodeData_t,int>::Grow(
            this: &s_CheatCodeCommands.m_Memory,
            num: s_CheatCodeCommands.m_Size - s_CheatCodeCommands.m_Memory.m_nAllocationCount + 1);
          m_Size = s_CheatCodeCommands.m_Size;
        }
        m_pMemory = s_CheatCodeCommands.m_Memory.m_pMemory;
        s_CheatCodeCommands.m_Size = m_Size + 1;
        v8 = m_Size - v6;
        s_CheatCodeCommands.m_pElements = s_CheatCodeCommands.m_Memory.m_pMemory;
        if ( v8 > 0 )
        {
          _V_memmove(
            dest: &s_CheatCodeCommands.m_Memory.m_pMemory[v6 + 1],
            src: &s_CheatCodeCommands.m_Memory.m_pMemory[v6],
            count: 208 * v8);
          m_pMemory = s_CheatCodeCommands.m_Memory.m_pMemory;
        }
        v9 = &m_pMemory[v6];
        Name = KeyValues::GetName(this: FirstTrueSubKey);
        V_strncpy(pDest: v9->szName, pSrc: Name, maxLen: 32);
        v9->bDevOnly = KeyValues::GetInt(this: FirstTrueSubKey, keyName: "dev", defaultValue: 0) != 0;
        v9->iCodeLength = 0;
        String = KeyValues::GetString(
                   this: FirstTrueSubKey,
                   keyName: "command",
                   defaultValue: "echo \"Cheat code has no command!\"");
        V_strncpy(pDest: v9->szCommand, pSrc: String, maxLen: 128);
        for ( i = KeyValues::GetFirstSubKey(this: FirstTrueSubKey); i != nullptr; i = KeyValues::GetNextKey(this: i) )
        {
          v13 = KeyValues::GetName(this: i);
          if ( _V_strcmp(s1: v13, s2: "code") == 0 )
          {
            v14 = g_pInputSystem->__vftable;
            v15 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: defaultValue);
            v16 = v14->StringToButtonCode(this: g_pInputSystem, a2: v15);
            FirstTrueSubKey = pKey;
            v9->pButtonCodes[v9->iCodeLength++] = v16;
          }
        }
        if ( v9->iCodeLength < 32 )
        {
          v17 = KeyValues::GetName(this: FirstTrueSubKey);
          DevWarning(a1: "Cheat code \"%s\" has less than %i code elements!", v17, 32);
        }
        pKey = KeyValues::GetNextTrueSubKey(this: FirstTrueSubKey);
        if ( pKey == nullptr )
          break;
        FirstTrueSubKey = pKey;
      }
      v2 = pCheatCodeKeys;
    }
  }
  KeyValues::deleteThis(this: v2);
}

} // namespace engine_xlsp
