// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: public/filesystem_helpers.cpp
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10178F20
// Name: char const __near * ParseFile(char const __near *,char __near *,bool __near *,struct characterset_t __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl ParseFile(char *pFileBytes, char *pToken, bool *pWasQuoted, characterset_t *pCharSet)
{
  char *v4; // esi
  characterset_t *v6; // eax
  int v7; // edx
  int v8; // eax
  char v9; // cl
  char i; // al
  char v11; // al
  int v12; // eax
  char *v13; // ecx
  const char *pFileBytesa; // [esp+8h] [ebp+8h]

  if ( pWasQuoted != nullptr )
    *pWasQuoted = false;
  v4 = pFileBytes;
  if ( pFileBytes == nullptr )
    return nullptr;
  if ( byte_10669344 == 0 )
  {
    CharacterSetBuild(pSetBuffer: &g_BreakSet_0, pszSetString: "{}()'");
    CharacterSetBuild(pSetBuffer: &g_BreakSetIncludingColons_0, pszSetString: "{}()':");
    byte_10669344 = 1;
  }
  v6 = pCharSet;
  if ( pCharSet == nullptr )
  {
    v6 = &g_BreakSet_0;
    if ( !com_ignorecolons )
      v6 = &g_BreakSetIncludingColons_0;
  }
  v7 = 0;
  pFileBytesa = (const char *)v6;
  *pToken = 0;
skipwhite_0:
  while ( 1 )
  {
    v8 = *v4;
    if ( v8 <= 32 )
      break;
LABEL_14:
    if ( v8 != 47 )
    {
      if ( v8 == 34 )
      {
        if ( pWasQuoted != nullptr )
          *pWasQuoted = true;
        v12 = v4[1];
        v4 += 2;
        if ( v12 != 34 )
        {
          while ( v12 != 0 )
          {
            pToken[v7] = v12;
            v12 = *v4;
            ++v7;
            ++v4;
            if ( v12 == 34 )
            {
              pToken[v7] = 0;
              return v4;
            }
          }
        }
      }
      else
      {
LABEL_35:
        if ( pFileBytesa[v8] != 0 )
        {
          *pToken = v8;
          pToken[1] = 0;
          return v4 + 1;
        }
        v13 = (char *)(pToken - v4);
        do
        {
          v4[(_DWORD)v13] = v8;
          v8 = *++v4;
          ++v7;
        }
        while ( pFileBytesa[v8] == 0 && v8 > 32 );
      }
      pToken[v7] = 0;
      return v4;
    }
    v9 = v4[1];
    if ( v9 == 47 )
    {
      for ( i = *v4; i != 0; i = *++v4 )
      {
        if ( i == 10 )
          break;
      }
    }
    else
    {
      if ( v9 != 42 )
        goto LABEL_35;
      v11 = v4[2];
      v4 += 2;
      if ( v11 != 0 )
      {
        while ( v11 != 42 || v4[1] != 47 )
        {
          v11 = *++v4;
          if ( v11 == 0 )
            goto skipwhite_0;
        }
        v4 += 2;
      }
    }
  }
  while ( v8 != 0 )
  {
    v8 = *++v4;
    if ( v8 > 32 )
      goto LABEL_14;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10179080
// Name: char __near * ParseFile(char __near *,char __near *,bool __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl ParseFile(char *pFileBytes, char *pToken, bool *pWasQuoted)
{
  return ParseFile(pFileBytes, pToken, pWasQuoted, pCharSet: nullptr);
}

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x0063AC40
// Name: char const __near * ParseFile(char const __near *,char __near *,bool __near *,struct characterset_t __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl ParseFile(char *pFileBytes, char *pToken, bool *pWasQuoted, characterset_t *pCharSet)
{
  char *v4; // esi
  characterset_t *v6; // eax
  int v7; // edx
  int v8; // eax
  char v9; // cl
  char i; // al
  char v11; // al
  int v12; // eax
  char *v13; // ecx
  const char *pFileBytesa; // [esp+8h] [ebp+8h]

  if ( pWasQuoted != nullptr )
    *pWasQuoted = false;
  v4 = pFileBytes;
  if ( pFileBytes == nullptr )
    return nullptr;
  if ( byte_78DC2C == 0 )
  {
    CharacterSetBuild(pSetBuffer: &g_BreakSet, pszSetString: "{}()'");
    CharacterSetBuild(pSetBuffer: &g_BreakSetIncludingColons, pszSetString: "{}()':");
    byte_78DC2C = 1;
  }
  v6 = pCharSet;
  if ( pCharSet == nullptr )
  {
    v6 = &g_BreakSet;
    if ( !com_ignorecolons )
      v6 = &g_BreakSetIncludingColons;
  }
  v7 = 0;
  pFileBytesa = (const char *)v6;
  *pToken = 0;
skipwhite:
  while ( 1 )
  {
    v8 = *v4;
    if ( v8 <= 32 )
      break;
LABEL_14:
    if ( v8 != 47 )
    {
      if ( v8 == 34 )
      {
        if ( pWasQuoted != nullptr )
          *pWasQuoted = true;
        v12 = v4[1];
        v4 += 2;
        if ( v12 != 34 )
        {
          while ( v12 != 0 )
          {
            pToken[v7] = v12;
            v12 = *v4;
            ++v7;
            ++v4;
            if ( v12 == 34 )
            {
              pToken[v7] = 0;
              return v4;
            }
          }
        }
      }
      else
      {
LABEL_35:
        if ( pFileBytesa[v8] != 0 )
        {
          *pToken = v8;
          pToken[1] = 0;
          return v4 + 1;
        }
        v13 = (char *)(pToken - v4);
        do
        {
          v4[(_DWORD)v13] = v8;
          v8 = *++v4;
          ++v7;
        }
        while ( pFileBytesa[v8] == 0 && v8 > 32 );
      }
      pToken[v7] = 0;
      return v4;
    }
    v9 = v4[1];
    if ( v9 == 47 )
    {
      for ( i = *v4; i != 0; i = *++v4 )
      {
        if ( i == 10 )
          break;
      }
    }
    else
    {
      if ( v9 != 42 )
        goto LABEL_35;
      v11 = v4[2];
      v4 += 2;
      if ( v11 != 0 )
      {
        while ( v11 != 42 || v4[1] != 47 )
        {
          v11 = *++v4;
          if ( v11 == 0 )
            goto skipwhite;
        }
        v4 += 2;
      }
    }
  }
  while ( v8 != 0 )
  {
    v8 = *++v4;
    if ( v8 > 32 )
      goto LABEL_14;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0063ADA0
// Name: char __near * ParseFile(char __near *,char __near *,bool __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl ParseFile(char *pFileBytes, char *pToken, bool *pWasQuoted)
{
  return ParseFile(pFileBytes, pToken, pWasQuoted, pCharSet: nullptr);
}

} // namespace elementviewer

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10179270
// Name: char const __near * ParseFile(char const __near *,char __near *,bool __near *,struct characterset_t __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl ParseFile(char *pFileBytes, char *pToken, bool *pWasQuoted, characterset_t *pCharSet)
{
  char *v4; // esi
  characterset_t *v6; // eax
  int v7; // edx
  int v8; // eax
  char v9; // cl
  char i; // al
  char v11; // al
  int v12; // eax
  char *v13; // ecx
  const char *pFileBytesa; // [esp+8h] [ebp+8h]

  if ( pWasQuoted != nullptr )
    *pWasQuoted = false;
  v4 = pFileBytes;
  if ( pFileBytes == nullptr )
    return nullptr;
  if ( byte_10669344 == 0 )
  {
    CharacterSetBuild(pSetBuffer: &g_BreakSet_0, pszSetString: "{}()'");
    CharacterSetBuild(pSetBuffer: &g_BreakSetIncludingColons_0, pszSetString: "{}()':");
    byte_10669344 = 1;
  }
  v6 = pCharSet;
  if ( pCharSet == nullptr )
  {
    v6 = &g_BreakSet_0;
    if ( !com_ignorecolons )
      v6 = &g_BreakSetIncludingColons_0;
  }
  v7 = 0;
  pFileBytesa = (const char *)v6;
  *pToken = 0;
skipwhite_0:
  while ( 1 )
  {
    v8 = *v4;
    if ( v8 <= 32 )
      break;
LABEL_14:
    if ( v8 != 47 )
    {
      if ( v8 == 34 )
      {
        if ( pWasQuoted != nullptr )
          *pWasQuoted = true;
        v12 = v4[1];
        v4 += 2;
        if ( v12 != 34 )
        {
          while ( v12 != 0 )
          {
            pToken[v7] = v12;
            v12 = *v4;
            ++v7;
            ++v4;
            if ( v12 == 34 )
            {
              pToken[v7] = 0;
              return v4;
            }
          }
        }
      }
      else
      {
LABEL_35:
        if ( pFileBytesa[v8] != 0 )
        {
          *pToken = v8;
          pToken[1] = 0;
          return v4 + 1;
        }
        v13 = (char *)(pToken - v4);
        do
        {
          v4[(_DWORD)v13] = v8;
          v8 = *++v4;
          ++v7;
        }
        while ( pFileBytesa[v8] == 0 && v8 > 32 );
      }
      pToken[v7] = 0;
      return v4;
    }
    v9 = v4[1];
    if ( v9 == 47 )
    {
      for ( i = *v4; i != 0; i = *++v4 )
      {
        if ( i == 10 )
          break;
      }
    }
    else
    {
      if ( v9 != 42 )
        goto LABEL_35;
      v11 = v4[2];
      v4 += 2;
      if ( v11 != 0 )
      {
        while ( v11 != 42 || v4[1] != 47 )
        {
          v11 = *++v4;
          if ( v11 == 0 )
            goto skipwhite_0;
        }
        v4 += 2;
      }
    }
  }
  while ( v8 != 0 )
  {
    v8 = *++v4;
    if ( v8 > 32 )
      goto LABEL_14;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101793D0
// Name: char __near * ParseFile(char __near *,char __near *,bool __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl ParseFile(char *pFileBytes, char *pToken, bool *pWasQuoted)
{
  return ParseFile(pFileBytes, pToken, pWasQuoted, pCharSet: nullptr);
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x100336F0
// Name: char const __near * ParseFile(char const __near *,char __near *,bool __near *,struct characterset_t __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl ParseFile(char *pFileBytes, char *pToken, bool *pWasQuoted, characterset_t *pCharSet)
{
  char *v4; // esi
  characterset_t *v6; // eax
  int v7; // edx
  int v8; // eax
  char v9; // cl
  char i; // al
  char v11; // al
  int v12; // eax
  char *v13; // ecx
  const char *pFileBytesa; // [esp+8h] [ebp+8h]

  if ( pWasQuoted != nullptr )
    *pWasQuoted = false;
  v4 = pFileBytes;
  if ( pFileBytes == nullptr )
    return nullptr;
  if ( byte_1078FBAC == 0 )
  {
    CharacterSetBuild(pSetBuffer: &g_BreakSet, pszSetString: "{}()'");
    CharacterSetBuild(pSetBuffer: &g_BreakSetIncludingColons, pszSetString: "{}()':");
    byte_1078FBAC = 1;
  }
  v6 = pCharSet;
  if ( pCharSet == nullptr )
  {
    v6 = &g_BreakSet;
    if ( !com_ignorecolons )
      v6 = &g_BreakSetIncludingColons;
  }
  v7 = 0;
  pFileBytesa = (const char *)v6;
  *pToken = 0;
skipwhite:
  while ( 1 )
  {
    v8 = *v4;
    if ( v8 <= 32 )
      break;
LABEL_14:
    if ( v8 != 47 )
    {
      if ( v8 == 34 )
      {
        if ( pWasQuoted != nullptr )
          *pWasQuoted = true;
        v12 = v4[1];
        v4 += 2;
        if ( v12 != 34 )
        {
          while ( v12 != 0 )
          {
            pToken[v7] = v12;
            v12 = *v4;
            ++v7;
            ++v4;
            if ( v12 == 34 )
            {
              pToken[v7] = 0;
              return v4;
            }
          }
        }
      }
      else
      {
LABEL_35:
        if ( pFileBytesa[v8] != 0 )
        {
          *pToken = v8;
          pToken[1] = 0;
          return v4 + 1;
        }
        v13 = (char *)(pToken - v4);
        do
        {
          v4[(_DWORD)v13] = v8;
          v8 = *++v4;
          ++v7;
        }
        while ( pFileBytesa[v8] == 0 && v8 > 32 );
      }
      pToken[v7] = 0;
      return v4;
    }
    v9 = v4[1];
    if ( v9 == 47 )
    {
      for ( i = *v4; i != 0; i = *++v4 )
      {
        if ( i == 10 )
          break;
      }
    }
    else
    {
      if ( v9 != 42 )
        goto LABEL_35;
      v11 = v4[2];
      v4 += 2;
      if ( v11 != 0 )
      {
        while ( v11 != 42 || v4[1] != 47 )
        {
          v11 = *++v4;
          if ( v11 == 0 )
            goto skipwhite;
        }
        v4 += 2;
      }
    }
  }
  while ( v8 != 0 )
  {
    v8 = *++v4;
    if ( v8 > 32 )
      goto LABEL_14;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10033850
// Name: char __near * ParseFile(char __near *,char __near *,bool __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl ParseFile(char *pFileBytes, char *pToken, bool *pWasQuoted)
{
  return ParseFile(pFileBytes, pToken, pWasQuoted, pCharSet: nullptr);
}

} // namespace hammer_dll

// ============================================================
// Overlay from localization_check (Missing functions)
// ============================================================
namespace localization_check {

//------------------------------------------------------------------------------
// Address: 0x00403AD0
// Name: char const __near * ParseFile(char const __near *,char __near *,bool __near *,struct characterset_t __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl ParseFile(char *pFileBytes, char *pToken, bool *pWasQuoted, characterset_t *pCharSet)
{
  char *v4; // esi
  characterset_t *v6; // eax
  int v7; // edx
  int v8; // eax
  char v9; // cl
  char i; // al
  char v11; // al
  int v12; // eax
  char *v13; // ecx
  const char *pFileBytesa; // [esp+8h] [ebp+8h]

  if ( pWasQuoted != nullptr )
    *pWasQuoted = false;
  v4 = pFileBytes;
  if ( pFileBytes == nullptr )
    return nullptr;
  if ( byte_4697E4 == 0 )
  {
    CharacterSetBuild(pSetBuffer: &g_BreakSet, pszSetString: "{}()'");
    CharacterSetBuild(pSetBuffer: &g_BreakSetIncludingColons, pszSetString: "{}()':");
    byte_4697E4 = 1;
  }
  v6 = pCharSet;
  if ( pCharSet == nullptr )
  {
    v6 = &g_BreakSet;
    if ( !com_ignorecolons )
      v6 = &g_BreakSetIncludingColons;
  }
  v7 = 0;
  pFileBytesa = (const char *)v6;
  *pToken = 0;
skipwhite:
  while ( 1 )
  {
    v8 = *v4;
    if ( v8 <= 32 )
      break;
LABEL_14:
    if ( v8 != 47 )
    {
      if ( v8 == 34 )
      {
        if ( pWasQuoted != nullptr )
          *pWasQuoted = true;
        v12 = v4[1];
        v4 += 2;
        if ( v12 != 34 )
        {
          while ( v12 != 0 )
          {
            pToken[v7] = v12;
            v12 = *v4;
            ++v7;
            ++v4;
            if ( v12 == 34 )
            {
              pToken[v7] = 0;
              return v4;
            }
          }
        }
      }
      else
      {
LABEL_35:
        if ( pFileBytesa[v8] != 0 )
        {
          *pToken = v8;
          pToken[1] = 0;
          return v4 + 1;
        }
        v13 = (char *)(pToken - v4);
        do
        {
          v4[(_DWORD)v13] = v8;
          v8 = *++v4;
          ++v7;
        }
        while ( pFileBytesa[v8] == 0 && v8 > 32 );
      }
      pToken[v7] = 0;
      return v4;
    }
    v9 = v4[1];
    if ( v9 == 47 )
    {
      for ( i = *v4; i != 0; i = *++v4 )
      {
        if ( i == 10 )
          break;
      }
    }
    else
    {
      if ( v9 != 42 )
        goto LABEL_35;
      v11 = v4[2];
      v4 += 2;
      if ( v11 != 0 )
      {
        while ( v11 != 42 || v4[1] != 47 )
        {
          v11 = *++v4;
          if ( v11 == 0 )
            goto skipwhite;
        }
        v4 += 2;
      }
    }
  }
  while ( v8 != 0 )
  {
    v8 = *++v4;
    if ( v8 > 32 )
      goto LABEL_14;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00403C30
// Name: char __near * ParseFile(char __near *,char __near *,bool __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl ParseFile(char *pFileBytes, char *pToken, bool *pWasQuoted)
{
  return ParseFile(pFileBytes, pToken, pWasQuoted, pCharSet: nullptr);
}

} // namespace localization_check

// ============================================================
// Overlay from missionchooser (Missing functions)
// ============================================================
namespace missionchooser {

//------------------------------------------------------------------------------
// Address: 0x100D7AC0
// Name: char const __near * ParseFile(char const __near *,char __near *,bool __near *,struct characterset_t __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl ParseFile(char *pFileBytes, char *pToken, bool *pWasQuoted, characterset_t *pCharSet)
{
  char *v4; // esi
  characterset_t *v6; // eax
  int v7; // edx
  int v8; // eax
  char v9; // cl
  char i; // al
  char v11; // al
  int v12; // eax
  char *v13; // ecx
  const char *pFileBytesa; // [esp+8h] [ebp+8h]

  if ( pWasQuoted != nullptr )
    *pWasQuoted = false;
  v4 = pFileBytes;
  if ( pFileBytes == nullptr )
    return nullptr;
  if ( byte_101C769C == 0 )
  {
    CharacterSetBuild(pSetBuffer: &g_BreakSet, pszSetString: "{}()'");
    CharacterSetBuild(pSetBuffer: &g_BreakSetIncludingColons, pszSetString: "{}()':");
    byte_101C769C = 1;
  }
  v6 = pCharSet;
  if ( pCharSet == nullptr )
  {
    v6 = &g_BreakSet;
    if ( !com_ignorecolons )
      v6 = &g_BreakSetIncludingColons;
  }
  v7 = 0;
  pFileBytesa = (const char *)v6;
  *pToken = 0;
skipwhite:
  while ( 1 )
  {
    v8 = *v4;
    if ( v8 <= 32 )
      break;
LABEL_14:
    if ( v8 != 47 )
    {
      if ( v8 == 34 )
      {
        if ( pWasQuoted != nullptr )
          *pWasQuoted = true;
        v12 = v4[1];
        v4 += 2;
        if ( v12 != 34 )
        {
          while ( v12 != 0 )
          {
            pToken[v7] = v12;
            v12 = *v4;
            ++v7;
            ++v4;
            if ( v12 == 34 )
            {
              pToken[v7] = 0;
              return v4;
            }
          }
        }
      }
      else
      {
LABEL_35:
        if ( pFileBytesa[v8] != 0 )
        {
          *pToken = v8;
          pToken[1] = 0;
          return v4 + 1;
        }
        v13 = (char *)(pToken - v4);
        do
        {
          v4[(_DWORD)v13] = v8;
          v8 = *++v4;
          ++v7;
        }
        while ( pFileBytesa[v8] == 0 && v8 > 32 );
      }
      pToken[v7] = 0;
      return v4;
    }
    v9 = v4[1];
    if ( v9 == 47 )
    {
      for ( i = *v4; i != 0; i = *++v4 )
      {
        if ( i == 10 )
          break;
      }
    }
    else
    {
      if ( v9 != 42 )
        goto LABEL_35;
      v11 = v4[2];
      v4 += 2;
      if ( v11 != 0 )
      {
        while ( v11 != 42 || v4[1] != 47 )
        {
          v11 = *++v4;
          if ( v11 == 0 )
            goto skipwhite;
        }
        v4 += 2;
      }
    }
  }
  while ( v8 != 0 )
  {
    v8 = *++v4;
    if ( v8 > 32 )
      goto LABEL_14;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100D7C20
// Name: char __near * ParseFile(char __near *,char __near *,bool __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl ParseFile(char *pFileBytes, char *pToken, bool *pWasQuoted)
{
  return ParseFile(pFileBytes, pToken, pWasQuoted, pCharSet: nullptr);
}

} // namespace missionchooser

// ============================================================
// Overlay from modelbrowser (Missing functions)
// ============================================================
namespace modelbrowser {

//------------------------------------------------------------------------------
// Address: 0x004792D0
// Name: char const __near * ParseFile(char const __near *,char __near *,bool __near *,struct characterset_t __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl ParseFile(char *pFileBytes, char *pToken, bool *pWasQuoted, characterset_t *pCharSet)
{
  char *v4; // esi
  characterset_t *v6; // eax
  int v7; // edx
  int v8; // eax
  char v9; // cl
  char i; // al
  char v11; // al
  int v12; // eax
  char *v13; // ecx
  const char *pFileBytesa; // [esp+8h] [ebp+8h]

  if ( pWasQuoted != nullptr )
    *pWasQuoted = false;
  v4 = pFileBytes;
  if ( pFileBytes == nullptr )
    return nullptr;
  if ( byte_50F0AC == 0 )
  {
    CharacterSetBuild(pSetBuffer: &g_BreakSet, pszSetString: "{}()'");
    CharacterSetBuild(pSetBuffer: &g_BreakSetIncludingColons, pszSetString: "{}()':");
    byte_50F0AC = 1;
  }
  v6 = pCharSet;
  if ( pCharSet == nullptr )
  {
    v6 = &g_BreakSet;
    if ( !com_ignorecolons )
      v6 = &g_BreakSetIncludingColons;
  }
  v7 = 0;
  pFileBytesa = (const char *)v6;
  *pToken = 0;
skipwhite:
  while ( 1 )
  {
    v8 = *v4;
    if ( v8 <= 32 )
      break;
LABEL_14:
    if ( v8 != 47 )
    {
      if ( v8 == 34 )
      {
        if ( pWasQuoted != nullptr )
          *pWasQuoted = true;
        v12 = v4[1];
        v4 += 2;
        if ( v12 != 34 )
        {
          while ( v12 != 0 )
          {
            pToken[v7] = v12;
            v12 = *v4;
            ++v7;
            ++v4;
            if ( v12 == 34 )
            {
              pToken[v7] = 0;
              return v4;
            }
          }
        }
      }
      else
      {
LABEL_35:
        if ( pFileBytesa[v8] != 0 )
        {
          *pToken = v8;
          pToken[1] = 0;
          return v4 + 1;
        }
        v13 = (char *)(pToken - v4);
        do
        {
          v4[(_DWORD)v13] = v8;
          v8 = *++v4;
          ++v7;
        }
        while ( pFileBytesa[v8] == 0 && v8 > 32 );
      }
      pToken[v7] = 0;
      return v4;
    }
    v9 = v4[1];
    if ( v9 == 47 )
    {
      for ( i = *v4; i != 0; i = *++v4 )
      {
        if ( i == 10 )
          break;
      }
    }
    else
    {
      if ( v9 != 42 )
        goto LABEL_35;
      v11 = v4[2];
      v4 += 2;
      if ( v11 != 0 )
      {
        while ( v11 != 42 || v4[1] != 47 )
        {
          v11 = *++v4;
          if ( v11 == 0 )
            goto skipwhite;
        }
        v4 += 2;
      }
    }
  }
  while ( v8 != 0 )
  {
    v8 = *++v4;
    if ( v8 > 32 )
      goto LABEL_14;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00479430
// Name: char __near * ParseFile(char __near *,char __near *,bool __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl ParseFile(char *pFileBytes, char *pToken, bool *pWasQuoted)
{
  return ParseFile(pFileBytes, pToken, pWasQuoted, pCharSet: nullptr);
}

} // namespace modelbrowser

// ============================================================
// Overlay from QCGenerator (Missing functions)
// ============================================================
namespace QCGenerator {

//------------------------------------------------------------------------------
// Address: 0x00456370
// Name: char const __near * ParseFile(char const __near *,char __near *,bool __near *,struct characterset_t __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl ParseFile(const char *pFileBytes, char *pToken, bool *pWasQuoted, characterset_t *pCharSet)
{
  const char *v4; // esi
  characterset_t *v6; // eax
  int v7; // edx
  characterset_t *v8; // ebp
  int v9; // eax
  char v10; // cl
  char i; // al
  char v12; // al
  int v13; // eax

  if ( pWasQuoted != nullptr )
    *pWasQuoted = false;
  v4 = pFileBytes;
  if ( pFileBytes == nullptr )
    return nullptr;
  if ( byte_4C751C == 0 )
  {
    CharacterSetBuild(pSetBuffer: &g_BreakSet, pszSetString: "{}()'");
    CharacterSetBuild(pSetBuffer: &g_BreakSetIncludingColons, pszSetString: "{}()':");
    byte_4C751C = 1;
  }
  v6 = pCharSet;
  if ( pCharSet == nullptr )
  {
    v6 = &g_BreakSet;
    if ( !com_ignorecolons )
      v6 = &g_BreakSetIncludingColons;
  }
  v7 = 0;
  v8 = v6;
  *pToken = 0;
skipwhite:
  while ( 1 )
  {
    v9 = *v4;
    if ( v9 <= 32 )
      break;
LABEL_14:
    if ( v9 != 47 )
    {
      if ( v9 == 34 )
      {
        if ( pWasQuoted != nullptr )
          *pWasQuoted = true;
        v13 = v4[1];
        v4 += 2;
        if ( v13 != 34 )
        {
          while ( v13 != 0 )
          {
            pToken[v7] = v13;
            v13 = *v4;
            ++v7;
            ++v4;
            if ( v13 == 34 )
            {
              pToken[v7] = 0;
              return v4;
            }
          }
        }
      }
      else
      {
LABEL_35:
        if ( v8->set[v9] != 0 )
        {
          *pToken = v9;
          pToken[1] = 0;
          return v4 + 1;
        }
        do
        {
          pToken[v7] = v9;
          v9 = *++v4;
          ++v7;
        }
        while ( v8->set[v9] == 0 && v9 > 32 );
      }
      pToken[v7] = 0;
      return v4;
    }
    v10 = v4[1];
    if ( v10 == 47 )
    {
      for ( i = *v4; i != 0; i = *++v4 )
      {
        if ( i == 10 )
          break;
      }
    }
    else
    {
      if ( v10 != 42 )
        goto LABEL_35;
      v12 = v4[2];
      v4 += 2;
      if ( v12 != 0 )
      {
        while ( v12 != 42 || v4[1] != 47 )
        {
          v12 = *++v4;
          if ( v12 == 0 )
            goto skipwhite;
        }
        v4 += 2;
      }
    }
  }
  while ( v9 != 0 )
  {
    v9 = *++v4;
    if ( v9 > 32 )
      goto LABEL_14;
  }
  return nullptr;
}

} // namespace QCGenerator

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x0066FA40
// Name: char const __near * ParseFile(char const __near *,char __near *,bool __near *,struct characterset_t __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl ParseFile(char *pFileBytes, char *pToken, bool *pWasQuoted, characterset_t *pCharSet)
{
  char *v4; // esi
  characterset_t *v6; // eax
  int v7; // edx
  int v8; // eax
  char v9; // cl
  char i; // al
  char v11; // al
  int v12; // eax
  char *v13; // ecx
  const char *pFileBytesa; // [esp+8h] [ebp+8h]

  if ( pWasQuoted != nullptr )
    *pWasQuoted = false;
  v4 = pFileBytes;
  if ( pFileBytes == nullptr )
    return nullptr;
  if ( byte_7D8634 == 0 )
  {
    CharacterSetBuild(pSetBuffer: &g_BreakSet, pszSetString: "{}()'");
    CharacterSetBuild(pSetBuffer: &g_BreakSetIncludingColons, pszSetString: "{}()':");
    byte_7D8634 = 1;
  }
  v6 = pCharSet;
  if ( pCharSet == nullptr )
  {
    v6 = &g_BreakSet;
    if ( !com_ignorecolons )
      v6 = &g_BreakSetIncludingColons;
  }
  v7 = 0;
  pFileBytesa = (const char *)v6;
  *pToken = 0;
skipwhite:
  while ( 1 )
  {
    v8 = *v4;
    if ( v8 <= 32 )
      break;
LABEL_14:
    if ( v8 != 47 )
    {
      if ( v8 == 34 )
      {
        if ( pWasQuoted != nullptr )
          *pWasQuoted = true;
        v12 = v4[1];
        v4 += 2;
        if ( v12 != 34 )
        {
          while ( v12 != 0 )
          {
            pToken[v7] = v12;
            v12 = *v4;
            ++v7;
            ++v4;
            if ( v12 == 34 )
            {
              pToken[v7] = 0;
              return v4;
            }
          }
        }
      }
      else
      {
LABEL_35:
        if ( pFileBytesa[v8] != 0 )
        {
          *pToken = v8;
          pToken[1] = 0;
          return v4 + 1;
        }
        v13 = (char *)(pToken - v4);
        do
        {
          v4[(_DWORD)v13] = v8;
          v8 = *++v4;
          ++v7;
        }
        while ( pFileBytesa[v8] == 0 && v8 > 32 );
      }
      pToken[v7] = 0;
      return v4;
    }
    v9 = v4[1];
    if ( v9 == 47 )
    {
      for ( i = *v4; i != 0; i = *++v4 )
      {
        if ( i == 10 )
          break;
      }
    }
    else
    {
      if ( v9 != 42 )
        goto LABEL_35;
      v11 = v4[2];
      v4 += 2;
      if ( v11 != 0 )
      {
        while ( v11 != 42 || v4[1] != 47 )
        {
          v11 = *++v4;
          if ( v11 == 0 )
            goto skipwhite;
        }
        v4 += 2;
      }
    }
  }
  while ( v8 != 0 )
  {
    v8 = *++v4;
    if ( v8 > 32 )
      goto LABEL_14;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0066FBA0
// Name: char __near * ParseFile(char __near *,char __near *,bool __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl ParseFile(char *pFileBytes, char *pToken, bool *pWasQuoted)
{
  return ParseFile(pFileBytes, pToken, pWasQuoted, pCharSet: nullptr);
}

} // namespace sceneviewer

// ============================================================
// Overlay from ServerBrowser (Missing functions)
// ============================================================
namespace ServerBrowser {

//------------------------------------------------------------------------------
// Address: 0x10078200
// Name: char const __near * ParseFile(char const __near *,char __near *,bool __near *,struct characterset_t __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl ParseFile(char *pFileBytes, char *pToken, bool *pWasQuoted, characterset_t *pCharSet)
{
  char *v4; // esi
  characterset_t *v6; // eax
  int v7; // edx
  int v8; // eax
  char v9; // cl
  char i; // al
  char v11; // al
  int v12; // eax
  char *v13; // ecx
  const char *pFileBytesa; // [esp+8h] [ebp+8h]

  if ( pWasQuoted != nullptr )
    *pWasQuoted = false;
  v4 = pFileBytes;
  if ( pFileBytes == nullptr )
    return nullptr;
  if ( byte_100E5DE4 == 0 )
  {
    CharacterSetBuild(pSetBuffer: &g_BreakSet, pszSetString: "{}()'");
    CharacterSetBuild(pSetBuffer: &g_BreakSetIncludingColons, pszSetString: "{}()':");
    byte_100E5DE4 = 1;
  }
  v6 = pCharSet;
  if ( pCharSet == nullptr )
  {
    v6 = &g_BreakSet;
    if ( !com_ignorecolons )
      v6 = &g_BreakSetIncludingColons;
  }
  v7 = 0;
  pFileBytesa = (const char *)v6;
  *pToken = 0;
skipwhite:
  while ( 1 )
  {
    v8 = *v4;
    if ( v8 <= 32 )
      break;
LABEL_14:
    if ( v8 != 47 )
    {
      if ( v8 == 34 )
      {
        if ( pWasQuoted != nullptr )
          *pWasQuoted = true;
        v12 = v4[1];
        v4 += 2;
        if ( v12 != 34 )
        {
          while ( v12 != 0 )
          {
            pToken[v7] = v12;
            v12 = *v4;
            ++v7;
            ++v4;
            if ( v12 == 34 )
            {
              pToken[v7] = 0;
              return v4;
            }
          }
        }
      }
      else
      {
LABEL_35:
        if ( pFileBytesa[v8] != 0 )
        {
          *pToken = v8;
          pToken[1] = 0;
          return v4 + 1;
        }
        v13 = (char *)(pToken - v4);
        do
        {
          v4[(_DWORD)v13] = v8;
          v8 = *++v4;
          ++v7;
        }
        while ( pFileBytesa[v8] == 0 && v8 > 32 );
      }
      pToken[v7] = 0;
      return v4;
    }
    v9 = v4[1];
    if ( v9 == 47 )
    {
      for ( i = *v4; i != 0; i = *++v4 )
      {
        if ( i == 10 )
          break;
      }
    }
    else
    {
      if ( v9 != 42 )
        goto LABEL_35;
      v11 = v4[2];
      v4 += 2;
      if ( v11 != 0 )
      {
        while ( v11 != 42 || v4[1] != 47 )
        {
          v11 = *++v4;
          if ( v11 == 0 )
            goto skipwhite;
        }
        v4 += 2;
      }
    }
  }
  while ( v8 != 0 )
  {
    v8 = *++v4;
    if ( v8 > 32 )
      goto LABEL_14;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10078360
// Name: char __near * ParseFile(char __near *,char __near *,bool __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl ParseFile(char *pFileBytes, char *pToken, bool *pWasQuoted)
{
  return ParseFile(pFileBytes, pToken, pWasQuoted, pCharSet: nullptr);
}

} // namespace ServerBrowser

// ============================================================
// Overlay from unusedcontent (Missing functions)
// ============================================================
namespace unusedcontent {

//------------------------------------------------------------------------------
// Address: 0x004014C0
// Name: char const __near * ParseFile(char const __near *,char __near *,bool __near *,struct characterset_t __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl ParseFile(char *pFileBytes, char *pToken, bool *pWasQuoted, characterset_t *pCharSet)
{
  char *v4; // esi
  characterset_t *v6; // eax
  int v7; // edx
  int v8; // eax
  char v9; // cl
  char i; // al
  char v11; // al
  int v12; // eax
  char *v13; // ecx
  const char *pFileBytesa; // [esp+8h] [ebp+8h]

  if ( pWasQuoted != nullptr )
    *pWasQuoted = false;
  v4 = pFileBytes;
  if ( pFileBytes == nullptr )
    return nullptr;
  if ( byte_42FEE4 == 0 )
  {
    CharacterSetBuild(pSetBuffer: &g_BreakSet, pszSetString: "{}()'");
    CharacterSetBuild(pSetBuffer: &g_BreakSetIncludingColons, pszSetString: "{}()':");
    byte_42FEE4 = 1;
  }
  v6 = pCharSet;
  if ( pCharSet == nullptr )
  {
    v6 = &g_BreakSet;
    if ( !com_ignorecolons )
      v6 = &g_BreakSetIncludingColons;
  }
  v7 = 0;
  pFileBytesa = (const char *)v6;
  *pToken = 0;
skipwhite:
  while ( 1 )
  {
    v8 = *v4;
    if ( v8 <= 32 )
      break;
LABEL_14:
    if ( v8 != 47 )
    {
      if ( v8 == 34 )
      {
        if ( pWasQuoted != nullptr )
          *pWasQuoted = true;
        v12 = v4[1];
        v4 += 2;
        if ( v12 != 34 )
        {
          while ( v12 != 0 )
          {
            pToken[v7] = v12;
            v12 = *v4;
            ++v7;
            ++v4;
            if ( v12 == 34 )
            {
              pToken[v7] = 0;
              return v4;
            }
          }
        }
      }
      else
      {
LABEL_35:
        if ( pFileBytesa[v8] != 0 )
        {
          *pToken = v8;
          pToken[1] = 0;
          return v4 + 1;
        }
        v13 = (char *)(pToken - v4);
        do
        {
          v4[(_DWORD)v13] = v8;
          v8 = *++v4;
          ++v7;
        }
        while ( pFileBytesa[v8] == 0 && v8 > 32 );
      }
      pToken[v7] = 0;
      return v4;
    }
    v9 = v4[1];
    if ( v9 == 47 )
    {
      for ( i = *v4; i != 0; i = *++v4 )
      {
        if ( i == 10 )
          break;
      }
    }
    else
    {
      if ( v9 != 42 )
        goto LABEL_35;
      v11 = v4[2];
      v4 += 2;
      if ( v11 != 0 )
      {
        while ( v11 != 42 || v4[1] != 47 )
        {
          v11 = *++v4;
          if ( v11 == 0 )
            goto skipwhite;
        }
        v4 += 2;
      }
    }
  }
  while ( v8 != 0 )
  {
    v8 = *++v4;
    if ( v8 > 32 )
      goto LABEL_14;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00401620
// Name: char __near * ParseFile(char __near *,char __near *,bool __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl ParseFile(char *pFileBytes, char *pToken, bool *pWasQuoted)
{
  return ParseFile(pFileBytes, pToken, pWasQuoted, pCharSet: nullptr);
}

} // namespace unusedcontent

// ============================================================
// Overlay from vgui2 (Missing functions)
// ============================================================
namespace vgui2 {

//------------------------------------------------------------------------------
// Address: 0x10001A40
// Name: char const __near * ParseFile(char const __near *,char __near *,bool __near *,struct characterset_t __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl ParseFile(char *pFileBytes, char *pToken, bool *pWasQuoted, characterset_t *pCharSet)
{
  char *v4; // esi
  characterset_t *v6; // eax
  int v7; // edx
  int v8; // eax
  char v9; // cl
  char i; // al
  char v11; // al
  int v12; // eax
  char *v13; // ecx
  const char *pFileBytesa; // [esp+8h] [ebp+8h]

  if ( pWasQuoted != nullptr )
    *pWasQuoted = false;
  v4 = pFileBytes;
  if ( pFileBytes == nullptr )
    return nullptr;
  if ( byte_10050B04 == 0 )
  {
    CharacterSetBuild(pSetBuffer: &g_BreakSet, pszSetString: "{}()'");
    CharacterSetBuild(pSetBuffer: &g_BreakSetIncludingColons, pszSetString: "{}()':");
    byte_10050B04 = 1;
  }
  v6 = pCharSet;
  if ( pCharSet == nullptr )
  {
    v6 = &g_BreakSet;
    if ( !com_ignorecolons )
      v6 = &g_BreakSetIncludingColons;
  }
  v7 = 0;
  pFileBytesa = (const char *)v6;
  *pToken = 0;
skipwhite:
  while ( 1 )
  {
    v8 = *v4;
    if ( v8 <= 32 )
      break;
LABEL_14:
    if ( v8 != 47 )
    {
      if ( v8 == 34 )
      {
        if ( pWasQuoted != nullptr )
          *pWasQuoted = true;
        v12 = v4[1];
        v4 += 2;
        if ( v12 != 34 )
        {
          while ( v12 != 0 )
          {
            pToken[v7] = v12;
            v12 = *v4;
            ++v7;
            ++v4;
            if ( v12 == 34 )
            {
              pToken[v7] = 0;
              return v4;
            }
          }
        }
      }
      else
      {
LABEL_35:
        if ( pFileBytesa[v8] != 0 )
        {
          *pToken = v8;
          pToken[1] = 0;
          return v4 + 1;
        }
        v13 = (char *)(pToken - v4);
        do
        {
          v4[(_DWORD)v13] = v8;
          v8 = *++v4;
          ++v7;
        }
        while ( pFileBytesa[v8] == 0 && v8 > 32 );
      }
      pToken[v7] = 0;
      return v4;
    }
    v9 = v4[1];
    if ( v9 == 47 )
    {
      for ( i = *v4; i != 0; i = *++v4 )
      {
        if ( i == 10 )
          break;
      }
    }
    else
    {
      if ( v9 != 42 )
        goto LABEL_35;
      v11 = v4[2];
      v4 += 2;
      if ( v11 != 0 )
      {
        while ( v11 != 42 || v4[1] != 47 )
        {
          v11 = *++v4;
          if ( v11 == 0 )
            goto skipwhite;
        }
        v4 += 2;
      }
    }
  }
  while ( v8 != 0 )
  {
    v8 = *++v4;
    if ( v8 > 32 )
      goto LABEL_14;
  }
  return nullptr;
}

} // namespace vgui2

// ============================================================
// Overlay from vgui_editor (Missing functions)
// ============================================================
namespace vgui_editor {

//------------------------------------------------------------------------------
// Address: 0x00430670
// Name: char const __near * ParseFile(char const __near *,char __near *,bool __near *,struct characterset_t __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl ParseFile(char *pFileBytes, char *pToken, bool *pWasQuoted, characterset_t *pCharSet)
{
  char *v4; // esi
  characterset_t *v6; // eax
  int v7; // edx
  int v8; // eax
  char v9; // cl
  char i; // al
  char v11; // al
  int v12; // eax
  char *v13; // ecx
  const char *pFileBytesa; // [esp+8h] [ebp+8h]

  if ( pWasQuoted != nullptr )
    *pWasQuoted = false;
  v4 = pFileBytes;
  if ( pFileBytes == nullptr )
    return nullptr;
  if ( byte_4EF41C == 0 )
  {
    CharacterSetBuild(pSetBuffer: &g_BreakSet, pszSetString: "{}()'");
    CharacterSetBuild(pSetBuffer: &g_BreakSetIncludingColons, pszSetString: "{}()':");
    byte_4EF41C = 1;
  }
  v6 = pCharSet;
  if ( pCharSet == nullptr )
  {
    v6 = &g_BreakSet;
    if ( !com_ignorecolons )
      v6 = &g_BreakSetIncludingColons;
  }
  v7 = 0;
  pFileBytesa = (const char *)v6;
  *pToken = 0;
skipwhite:
  while ( 1 )
  {
    v8 = *v4;
    if ( v8 <= 32 )
      break;
LABEL_14:
    if ( v8 != 47 )
    {
      if ( v8 == 34 )
      {
        if ( pWasQuoted != nullptr )
          *pWasQuoted = true;
        v12 = v4[1];
        v4 += 2;
        if ( v12 != 34 )
        {
          while ( v12 != 0 )
          {
            pToken[v7] = v12;
            v12 = *v4;
            ++v7;
            ++v4;
            if ( v12 == 34 )
            {
              pToken[v7] = 0;
              return v4;
            }
          }
        }
      }
      else
      {
LABEL_35:
        if ( pFileBytesa[v8] != 0 )
        {
          *pToken = v8;
          pToken[1] = 0;
          return v4 + 1;
        }
        v13 = (char *)(pToken - v4);
        do
        {
          v4[(_DWORD)v13] = v8;
          v8 = *++v4;
          ++v7;
        }
        while ( pFileBytesa[v8] == 0 && v8 > 32 );
      }
      pToken[v7] = 0;
      return v4;
    }
    v9 = v4[1];
    if ( v9 == 47 )
    {
      for ( i = *v4; i != 0; i = *++v4 )
      {
        if ( i == 10 )
          break;
      }
    }
    else
    {
      if ( v9 != 42 )
        goto LABEL_35;
      v11 = v4[2];
      v4 += 2;
      if ( v11 != 0 )
      {
        while ( v11 != 42 || v4[1] != 47 )
        {
          v11 = *++v4;
          if ( v11 == 0 )
            goto skipwhite;
        }
        v4 += 2;
      }
    }
  }
  while ( v8 != 0 )
  {
    v8 = *++v4;
    if ( v8 > 32 )
      goto LABEL_14;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004307D0
// Name: char __near * ParseFile(char __near *,char __near *,bool __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl ParseFile(char *pFileBytes, char *pToken, bool *pWasQuoted)
{
  return ParseFile(pFileBytes, pToken, pWasQuoted, pCharSet: nullptr);
}

} // namespace vgui_editor

// ============================================================
// Overlay from vphysics (Missing functions)
// ============================================================
namespace vphysics {

//------------------------------------------------------------------------------
// Address: 0x10001990
// Name: char const __near * ParseFile(char const __near *,char __near *,bool __near *,struct characterset_t __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl ParseFile(char *pFileBytes, char *pToken, bool *pWasQuoted, characterset_t *pCharSet)
{
  char *v4; // esi
  characterset_t *v6; // eax
  int v7; // edx
  int v8; // eax
  char v9; // cl
  char i; // al
  char v11; // al
  int v12; // eax
  char *v13; // ecx
  const char *pFileBytesa; // [esp+8h] [ebp+8h]

  if ( pWasQuoted != nullptr )
    *pWasQuoted = false;
  v4 = pFileBytes;
  if ( pFileBytes == nullptr )
    return nullptr;
  if ( byte_100FC404 == 0 )
  {
    CharacterSetBuild(pSetBuffer: &g_BreakSet, pszSetString: "{}()'");
    CharacterSetBuild(pSetBuffer: &g_BreakSetIncludingColons, pszSetString: "{}()':");
    byte_100FC404 = 1;
  }
  v6 = pCharSet;
  if ( pCharSet == nullptr )
  {
    v6 = &g_BreakSet;
    if ( !com_ignorecolons )
      v6 = &g_BreakSetIncludingColons;
  }
  v7 = 0;
  pFileBytesa = (const char *)v6;
  *pToken = 0;
skipwhite:
  while ( 1 )
  {
    v8 = *v4;
    if ( v8 <= 32 )
      break;
LABEL_14:
    if ( v8 != 47 )
    {
      if ( v8 == 34 )
      {
        if ( pWasQuoted != nullptr )
          *pWasQuoted = true;
        v12 = v4[1];
        v4 += 2;
        if ( v12 != 34 )
        {
          while ( v12 != 0 )
          {
            pToken[v7] = v12;
            v12 = *v4;
            ++v7;
            ++v4;
            if ( v12 == 34 )
            {
              pToken[v7] = 0;
              return v4;
            }
          }
        }
      }
      else
      {
LABEL_35:
        if ( pFileBytesa[v8] != 0 )
        {
          *pToken = v8;
          pToken[1] = 0;
          return v4 + 1;
        }
        v13 = (char *)(pToken - v4);
        do
        {
          v4[(_DWORD)v13] = v8;
          v8 = *++v4;
          ++v7;
        }
        while ( pFileBytesa[v8] == 0 && v8 > 32 );
      }
      pToken[v7] = 0;
      return v4;
    }
    v9 = v4[1];
    if ( v9 == 47 )
    {
      for ( i = *v4; i != 0; i = *++v4 )
      {
        if ( i == 10 )
          break;
      }
    }
    else
    {
      if ( v9 != 42 )
        goto LABEL_35;
      v11 = v4[2];
      v4 += 2;
      if ( v11 != 0 )
      {
        while ( v11 != 42 || v4[1] != 47 )
        {
          v11 = *++v4;
          if ( v11 == 0 )
            goto skipwhite;
        }
        v4 += 2;
      }
    }
  }
  while ( v8 != 0 )
  {
    v8 = *++v4;
    if ( v8 > 32 )
      goto LABEL_14;
  }
  return nullptr;
}

} // namespace vphysics

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x100D2C40
// Name: char const __near * ParseFile(char const __near *,char __near *,bool __near *,struct characterset_t __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl ParseFile(char *pFileBytes, char *pToken, bool *pWasQuoted, characterset_t *pCharSet)
{
  char *v4; // esi
  characterset_t *v6; // eax
  int v7; // edx
  int v8; // eax
  char v9; // cl
  char i; // al
  char v11; // al
  int v12; // eax
  char *v13; // ecx
  const char *pFileBytesa; // [esp+8h] [ebp+8h]

  if ( pWasQuoted != nullptr )
    *pWasQuoted = false;
  v4 = pFileBytes;
  if ( pFileBytes == nullptr )
    return nullptr;
  if ( byte_10640D94 == 0 )
  {
    CharacterSetBuild(pSetBuffer: &g_BreakSet, pszSetString: "{}()'");
    CharacterSetBuild(pSetBuffer: &g_BreakSetIncludingColons, pszSetString: "{}()':");
    byte_10640D94 = 1;
  }
  v6 = pCharSet;
  if ( pCharSet == nullptr )
  {
    v6 = &g_BreakSet;
    if ( !com_ignorecolons )
      v6 = &g_BreakSetIncludingColons;
  }
  v7 = 0;
  pFileBytesa = (const char *)v6;
  *pToken = 0;
skipwhite:
  while ( 1 )
  {
    v8 = *v4;
    if ( v8 <= 32 )
      break;
LABEL_14:
    if ( v8 != 47 )
    {
      if ( v8 == 34 )
      {
        if ( pWasQuoted != nullptr )
          *pWasQuoted = true;
        v12 = v4[1];
        v4 += 2;
        if ( v12 != 34 )
        {
          while ( v12 != 0 )
          {
            pToken[v7] = v12;
            v12 = *v4;
            ++v7;
            ++v4;
            if ( v12 == 34 )
            {
              pToken[v7] = 0;
              return v4;
            }
          }
        }
      }
      else
      {
LABEL_35:
        if ( pFileBytesa[v8] != 0 )
        {
          *pToken = v8;
          pToken[1] = 0;
          return v4 + 1;
        }
        v13 = (char *)(pToken - v4);
        do
        {
          v4[(_DWORD)v13] = v8;
          v8 = *++v4;
          ++v7;
        }
        while ( pFileBytesa[v8] == 0 && v8 > 32 );
      }
      pToken[v7] = 0;
      return v4;
    }
    v9 = v4[1];
    if ( v9 == 47 )
    {
      for ( i = *v4; i != 0; i = *++v4 )
      {
        if ( i == 10 )
          break;
      }
    }
    else
    {
      if ( v9 != 42 )
        goto LABEL_35;
      v11 = v4[2];
      v4 += 2;
      if ( v11 != 0 )
      {
        while ( v11 != 42 || v4[1] != 47 )
        {
          v11 = *++v4;
          if ( v11 == 0 )
            goto skipwhite;
        }
        v4 += 2;
      }
    }
  }
  while ( v8 != 0 )
  {
    v8 = *++v4;
    if ( v8 > 32 )
      goto LABEL_14;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100D2DA0
// Name: char __near * ParseFile(char __near *,char __near *,bool __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl ParseFile(char *pFileBytes, char *pToken, bool *pWasQuoted)
{
  return ParseFile(pFileBytes, pToken, pWasQuoted, pCharSet: nullptr);
}

} // namespace client
