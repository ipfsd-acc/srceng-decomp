// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/mapentities_shared.cpp
// Functions: 7
// ============================================================

#include "game\shared\mapentities_shared.h"

//------------------------------------------------------------------------------
// Address: 0x10097F10
// Name: public: char const __near * CEntityMapData::CurrentBufferPosition(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEntityMapData::CurrentBufferPosition(CBaseAchievement *this)
{
  return *(_DWORD *)&this->m_bRegisteredForEvents;
}

//------------------------------------------------------------------------------
// Address: 0x1011C1B0
// Name: char const __near * MapEntity_ParseToken(char const __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl MapEntity_ParseToken(const char *data, char *newToken)
{
  const char *v2; // esi
  int v3; // edi
  const char *v5; // ecx
  char i; // al
  int v7; // eax

  v2 = data;
  v3 = 0;
  *newToken = 0;
  if ( data != nullptr )
  {
    if ( s_BuildReverseMap )
    {
      s_BuildReverseMap = false;
      _V_memset(dest: s_BraceCharacters, fill: 0, count: 256);
      v5 = s_BraceChars;
      for ( i = *s_BraceChars; *v5 != 0; i = *v5 )
      {
        ++v5;
        s_BraceCharacters[i] = true;
      }
    }
    LOBYTE(v7) = *data;
    while ( 1 )
    {
      v7 = (char)v7;
      if ( (char)v7 <= 32 )
        break;
LABEL_10:
      if ( v7 != 47 )
      {
        if ( v7 == 34 )
        {
          ++v2;
          while ( 1 )
          {
            v7 = *v2++;
            if ( v7 == 34 || v7 == 0 )
              break;
            newToken[v3] = v7;
            if ( ++v3 >= 2048 )
            {
              newToken[--v3] = 0;
              goto LABEL_22;
            }
          }
        }
        else
        {
LABEL_22:
          if ( s_BraceCharacters[v7] )
          {
            newToken[v3] = v7;
            newToken[v3 + 1] = 0;
            return v2 + 1;
          }
          do
          {
            newToken[v3] = v7;
            v7 = *++v2;
            ++v3;
            if ( s_BraceCharacters[v7] )
              break;
            if ( v3 >= 2048 )
              newToken[--v3] = 0;
          }
          while ( v7 > 32 );
        }
        newToken[v3] = 0;
        return v2;
      }
      if ( v2[1] != 47 )
        goto LABEL_22;
      LOBYTE(v7) = *v2;
      if ( *v2 != 0 )
      {
        do
        {
          if ( (_BYTE)v7 == 10 )
            break;
          LOBYTE(v7) = *++v2;
        }
        while ( (_BYTE)v7 != 0 );
      }
    }
    while ( v7 != 0 )
    {
      v7 = *++v2;
      if ( v7 > 32 )
        goto LABEL_10;
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1011C2C0
// Name: public: bool CEntityMapData::GetNextKey(char __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CEntityMapData::GetNextKey(CEntityMapData *this, char *keyName, char *value)
{
  char *m_pCurrentKey; // esi
  char *v5; // eax
  bool v6; // zf
  unsigned int v8; // eax
  char *v9; // eax
  char *v10; // eax
  char token[2048]; // [esp+8h] [ebp-800h] BYREF

  m_pCurrentKey = this->m_pCurrentKey;
  v5 = (char *)MapEntity_ParseToken(data: m_pCurrentKey, newToken: token);
  v6 = token[0] == 125;
  this->m_pCurrentKey = v5;
  if ( v6 )
  {
    this->m_pCurrentKey = m_pCurrentKey;
    return 0;
  }
  else
  {
    if ( v5 == nullptr )
      goto LABEL_4;
    V_strncpy(pDest: keyName, pSrc: token, maxLen: 2048);
    v8 = strlen(keyName);
    if ( v8 != 0 )
    {
      v9 = &keyName[v8 - 1];
      do
      {
        if ( *v9 != 32 )
          break;
        *v9-- = 0;
      }
      while ( &v9[1 - (_DWORD)keyName] != nullptr );
    }
    v10 = (char *)MapEntity_ParseToken(data: this->m_pCurrentKey, newToken: token);
    this->m_pCurrentKey = v10;
    if ( v10 != nullptr )
    {
      if ( token[0] == 125 )
      {
        _Warning(a1: "CEntityMapData::GetNextKey: closing brace without data\n");
        return 0;
      }
      else
      {
        V_strncpy(pDest: value, pSrc: token, maxLen: 2048);
        return 1;
      }
    }
    else
    {
LABEL_4:
      _Warning(a1: "CEntityMapData::GetNextKey: EOF without closing brace\n");
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011C3C0
// Name: bool MapEntity_ExtractValue(char const __near *,char const __near *,char __near * const)
// Source: json
//------------------------------------------------------------------------------
char __cdecl MapEntity_ExtractValue(const char *pEntData, const char *keyName, char *Value)
{
  const char *v3; // esi
  int v4; // edi
  const char *v5; // ecx
  char i; // al
  int v7; // eax
  char token[2048]; // [esp+Ch] [ebp-800h] BYREF

  v3 = pEntData;
  if ( pEntData == nullptr )
    return 0;
  while ( 1 )
  {
    v4 = 0;
    token[0] = 0;
    if ( v3 != nullptr )
    {
      if ( s_BuildReverseMap )
      {
        s_BuildReverseMap = false;
        _V_memset(dest: s_BraceCharacters, fill: 0, count: 256);
        v5 = s_BraceChars;
        for ( i = *s_BraceChars; *v5 != 0; i = *v5 )
        {
          ++v5;
          s_BraceCharacters[i] = true;
        }
      }
      LOBYTE(v7) = *v3;
      while ( 1 )
      {
        v7 = (char)v7;
        if ( (char)v7 <= 32 )
          break;
LABEL_11:
        if ( v7 != 47 )
        {
          if ( v7 == 34 )
          {
            ++v3;
            while ( 1 )
            {
              v7 = *v3++;
              if ( v7 == 34 || v7 == 0 )
                break;
              token[v4++] = v7;
              if ( v4 >= 2048 )
              {
                token[--v4] = 0;
                goto LABEL_24;
              }
            }
          }
          else
          {
LABEL_24:
            if ( s_BraceCharacters[v7] )
            {
              token[v4] = v7;
              token[v4 + 1] = 0;
              ++v3;
              goto LABEL_31;
            }
            do
            {
              ++v3;
              token[v4] = v7;
              v7 = *v3;
              ++v4;
              if ( s_BraceCharacters[v7] )
                break;
              if ( v4 >= 2048 )
                token[--v4] = 0;
            }
            while ( v7 > 32 );
          }
          token[v4] = 0;
          goto LABEL_31;
        }
        if ( v3[1] != 47 )
          goto LABEL_24;
        LOBYTE(v7) = *v3;
        if ( *v3 != 0 )
        {
          do
          {
            if ( (_BYTE)v7 == 10 )
              break;
            LOBYTE(v7) = *++v3;
          }
          while ( (_BYTE)v7 != 0 );
        }
      }
      while ( v7 != 0 )
      {
        v7 = *++v3;
        if ( v7 > 32 )
          goto LABEL_11;
      }
      v3 = nullptr;
LABEL_31:
      if ( token[0] == 125 )
        return 0;
    }
    else
    {
      v3 = nullptr;
    }
    if ( strcmp(token, keyName) == 0 )
      break;
    v3 = MapEntity_ParseToken(data: v3, newToken: token);
    if ( v3 == nullptr )
      return 0;
  }
  MapEntity_ParseToken(data: v3, newToken: token);
  V_strncpy(pDest: Value, pSrc: token, maxLen: 2048);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1011C580
// Name: char const __near * MapEntity_SkipToNextEntity(char const __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl MapEntity_SkipToNextEntity(const char *pMapData, char *pWorkBuffer)
{
  const char *v2; // esi
  int v4; // ebx

  v2 = pMapData;
  if ( pMapData == nullptr )
    return nullptr;
  v4 = 1;
  while ( 1 )
  {
    v2 = MapEntity_ParseToken(data: v2, newToken: pWorkBuffer);
    if ( _V_stricmp(s1: pWorkBuffer, s2: "{") != 0 )
      break;
    ++v4;
LABEL_8:
    if ( v2 == nullptr )
      return nullptr;
  }
  if ( _V_stricmp(s1: pWorkBuffer, s2: "}") != 0 )
    goto LABEL_8;
  if ( --v4 != 0 )
    goto LABEL_8;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x1011C5F0
// Name: public: bool CEntityMapData::ExtractValue(char const __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CEntityMapData::ExtractValue(CEntityMapData *this, const char *keyName, char *value)
{
  return MapEntity_ExtractValue(pEntData: this->m_pEntData, keyName, Value: value);
}

//------------------------------------------------------------------------------
// Address: 0x1011C610
// Name: public: bool CEntityMapData::GetFirstKey(char __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CEntityMapData::GetFirstKey(CEntityMapData *this, char *keyName, char *value)
{
  this->m_pCurrentKey = this->m_pEntData;
  return CEntityMapData::GetNextKey(this, keyName, value);
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x1016FDD0
// Name: char const __near * MapEntity_ParseToken(char const __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl MapEntity_ParseToken(const char *data, char *newToken)
{
  const char *v2; // esi
  int v3; // edi
  const char *v5; // ecx
  char i; // al
  int v7; // eax

  v2 = data;
  v3 = 0;
  *newToken = 0;
  if ( data != nullptr )
  {
    if ( s_BuildReverseMap )
    {
      s_BuildReverseMap = false;
      _V_memset(dest: s_BraceCharacters, fill: 0, count: 256);
      v5 = s_BraceChars;
      for ( i = *s_BraceChars; *v5 != 0; i = *v5 )
      {
        ++v5;
        s_BraceCharacters[i] = true;
      }
    }
    LOBYTE(v7) = *data;
    while ( 1 )
    {
      v7 = (char)v7;
      if ( (char)v7 <= 32 )
        break;
LABEL_10:
      if ( v7 != 47 )
      {
        if ( v7 == 34 )
        {
          ++v2;
          while ( 1 )
          {
            v7 = *v2++;
            if ( v7 == 34 || v7 == 0 )
              break;
            newToken[v3] = v7;
            if ( ++v3 >= 2048 )
            {
              newToken[--v3] = 0;
              goto LABEL_22;
            }
          }
        }
        else
        {
LABEL_22:
          if ( s_BraceCharacters[v7] )
          {
            newToken[v3] = v7;
            newToken[v3 + 1] = 0;
            return v2 + 1;
          }
          do
          {
            newToken[v3] = v7;
            v7 = *++v2;
            ++v3;
            if ( s_BraceCharacters[v7] )
              break;
            if ( v3 >= 2048 )
              newToken[--v3] = 0;
          }
          while ( v7 > 32 );
        }
        newToken[v3] = 0;
        return v2;
      }
      if ( v2[1] != 47 )
        goto LABEL_22;
      LOBYTE(v7) = *v2;
      if ( *v2 != 0 )
      {
        do
        {
          if ( (_BYTE)v7 == 10 )
            break;
          LOBYTE(v7) = *++v2;
        }
        while ( (_BYTE)v7 != 0 );
      }
    }
    while ( v7 != 0 )
    {
      v7 = *++v2;
      if ( v7 > 32 )
        goto LABEL_10;
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1016FEE0
// Name: public: bool CEntityMapData::GetNextKey(char __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CEntityMapData::GetNextKey(CEntityMapData *this, char *keyName, char *value)
{
  char *m_pCurrentKey; // esi
  char *v5; // eax
  bool v6; // zf
  unsigned int v8; // eax
  char *v9; // eax
  char *v10; // eax
  char token[2048]; // [esp+8h] [ebp-800h] BYREF

  m_pCurrentKey = this->m_pCurrentKey;
  v5 = (char *)MapEntity_ParseToken(data: m_pCurrentKey, newToken: token);
  v6 = token[0] == 125;
  this->m_pCurrentKey = v5;
  if ( v6 )
  {
    this->m_pCurrentKey = m_pCurrentKey;
    return 0;
  }
  else
  {
    if ( v5 == nullptr )
      goto LABEL_4;
    V_strncpy(pDest: keyName, pSrc: token, maxLen: 2048);
    v8 = strlen(keyName);
    if ( v8 != 0 )
    {
      v9 = &keyName[v8 - 1];
      do
      {
        if ( *v9 != 32 )
          break;
        *v9-- = 0;
      }
      while ( &v9[1 - (_DWORD)keyName] != nullptr );
    }
    v10 = (char *)MapEntity_ParseToken(data: this->m_pCurrentKey, newToken: token);
    this->m_pCurrentKey = v10;
    if ( v10 != nullptr )
    {
      if ( token[0] == 125 )
      {
        _Warning(a1: "CEntityMapData::GetNextKey: closing brace without data\n");
        return 0;
      }
      else
      {
        V_strncpy(pDest: value, pSrc: token, maxLen: 2048);
        return 1;
      }
    }
    else
    {
LABEL_4:
      _Warning(a1: "CEntityMapData::GetNextKey: EOF without closing brace\n");
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016FFE0
// Name: bool MapEntity_ExtractValue(char const __near *,char const __near *,char __near * const)
// Source: json
//------------------------------------------------------------------------------
char __cdecl MapEntity_ExtractValue(const char *pEntData, const char *keyName, char *Value)
{
  const char *v3; // esi
  int v4; // edi
  const char *v5; // ecx
  char i; // al
  int v7; // eax
  char token[2048]; // [esp+Ch] [ebp-800h] BYREF

  v3 = pEntData;
  if ( pEntData == nullptr )
    return 0;
  while ( 1 )
  {
    v4 = 0;
    token[0] = 0;
    if ( v3 != nullptr )
    {
      if ( s_BuildReverseMap )
      {
        s_BuildReverseMap = false;
        _V_memset(dest: s_BraceCharacters, fill: 0, count: 256);
        v5 = s_BraceChars;
        for ( i = *s_BraceChars; *v5 != 0; i = *v5 )
        {
          ++v5;
          s_BraceCharacters[i] = true;
        }
      }
      LOBYTE(v7) = *v3;
      while ( 1 )
      {
        v7 = (char)v7;
        if ( (char)v7 <= 32 )
          break;
LABEL_11:
        if ( v7 != 47 )
        {
          if ( v7 == 34 )
          {
            ++v3;
            while ( 1 )
            {
              v7 = *v3++;
              if ( v7 == 34 || v7 == 0 )
                break;
              token[v4++] = v7;
              if ( v4 >= 2048 )
              {
                token[--v4] = 0;
                goto LABEL_24;
              }
            }
          }
          else
          {
LABEL_24:
            if ( s_BraceCharacters[v7] )
            {
              token[v4] = v7;
              token[v4 + 1] = 0;
              ++v3;
              goto LABEL_31;
            }
            do
            {
              ++v3;
              token[v4] = v7;
              v7 = *v3;
              ++v4;
              if ( s_BraceCharacters[v7] )
                break;
              if ( v4 >= 2048 )
                token[--v4] = 0;
            }
            while ( v7 > 32 );
          }
          token[v4] = 0;
          goto LABEL_31;
        }
        if ( v3[1] != 47 )
          goto LABEL_24;
        LOBYTE(v7) = *v3;
        if ( *v3 != 0 )
        {
          do
          {
            if ( (_BYTE)v7 == 10 )
              break;
            LOBYTE(v7) = *++v3;
          }
          while ( (_BYTE)v7 != 0 );
        }
      }
      while ( v7 != 0 )
      {
        v7 = *++v3;
        if ( v7 > 32 )
          goto LABEL_11;
      }
      v3 = nullptr;
LABEL_31:
      if ( token[0] == 125 )
        return 0;
    }
    else
    {
      v3 = nullptr;
    }
    if ( strcmp(token, keyName) == 0 )
      break;
    v3 = MapEntity_ParseToken(data: v3, newToken: token);
    if ( v3 == nullptr )
      return 0;
  }
  MapEntity_ParseToken(data: v3, newToken: token);
  V_strncpy(pDest: Value, pSrc: token, maxLen: 2048);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101701A0
// Name: int MapEntity_GetNumKeysInEntity(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl MapEntity_GetNumKeysInEntity(const char *pEntData)
{
  int result; // eax
  int v3; // edi
  const char *v4; // ecx
  char i; // al
  int v6; // eax
  char token[2048]; // [esp+8h] [ebp-800h] BYREF
  int iNumKeys; // [esp+810h] [ebp+8h]

  result = 0;
  iNumKeys = 0;
  if ( pEntData != nullptr )
  {
    do
    {
      v3 = 0;
      token[0] = 0;
      if ( pEntData != nullptr )
      {
        if ( s_BuildReverseMap )
        {
          s_BuildReverseMap = false;
          _V_memset(dest: s_BraceCharacters, fill: 0, count: 256);
          v4 = s_BraceChars;
          for ( i = *s_BraceChars; *v4 != 0; i = *v4 )
          {
            ++v4;
            s_BraceCharacters[i] = true;
          }
        }
        LOBYTE(v6) = *pEntData;
        while ( 1 )
        {
          v6 = (char)v6;
          if ( (char)v6 <= 32 )
          {
            while ( v6 != 0 )
            {
              v6 = *++pEntData;
              if ( v6 > 32 )
                goto LABEL_11;
            }
            goto LABEL_3;
          }
LABEL_11:
          if ( v6 != 47 )
            break;
          if ( pEntData[1] != 47 )
            goto LABEL_23;
          LOBYTE(v6) = *pEntData;
          if ( *pEntData != 0 )
          {
            do
            {
              if ( (_BYTE)v6 == 10 )
                break;
              LOBYTE(v6) = *++pEntData;
            }
            while ( (_BYTE)v6 != 0 );
          }
        }
        if ( v6 == 34 )
        {
          ++pEntData;
          while ( 1 )
          {
            v6 = *pEntData++;
            if ( v6 == 34 || v6 == 0 )
              goto LABEL_29;
            token[v3++] = v6;
            if ( v3 >= 2048 )
            {
              token[--v3] = 0;
              break;
            }
          }
        }
LABEL_23:
        if ( s_BraceCharacters[v6] )
        {
          token[v3] = v6;
          token[v3 + 1] = 0;
          ++pEntData;
          goto LABEL_30;
        }
        do
        {
          ++pEntData;
          token[v3] = v6;
          v6 = *pEntData;
          ++v3;
          if ( s_BraceCharacters[v6] )
            break;
          if ( v3 >= 2048 )
            token[--v3] = 0;
        }
        while ( v6 > 32 );
LABEL_29:
        token[v3] = 0;
LABEL_30:
        if ( token[0] == 125 )
          return iNumKeys;
      }
      else
      {
LABEL_3:
        pEntData = nullptr;
      }
      ++iNumKeys;
      pEntData = MapEntity_ParseToken(data: pEntData, newToken: token);
    }
    while ( pEntData != nullptr );
    return iNumKeys;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10170300
// Name: char const __near * MapEntity_SkipToNextEntity(char const __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl MapEntity_SkipToNextEntity(const char *pMapData, char *pWorkBuffer)
{
  const char *v2; // edi
  int v4; // ebx

  v2 = pMapData;
  if ( pMapData == nullptr )
    return nullptr;
  v4 = 1;
  while ( 1 )
  {
    v2 = MapEntity_ParseToken(data: v2, newToken: pWorkBuffer);
    if ( pWorkBuffer != "{" && _V_stricmp(s1: pWorkBuffer, s2: "{") != 0 )
      break;
    ++v4;
LABEL_10:
    if ( v2 == nullptr )
      return nullptr;
  }
  if ( pWorkBuffer != "}" && _V_stricmp(s1: pWorkBuffer, s2: "}") != 0 )
    goto LABEL_10;
  if ( --v4 != 0 )
    goto LABEL_10;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10170380
// Name: public: bool CEntityMapData::ExtractValue(char const __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CEntityMapData::ExtractValue(CEntityMapData *this, const char *keyName, char *value)
{
  return MapEntity_ExtractValue(pEntData: this->m_pEntData, keyName, Value: value);
}

//------------------------------------------------------------------------------
// Address: 0x101703A0
// Name: public: bool CEntityMapData::GetFirstKey(char __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CEntityMapData::GetFirstKey(CEntityMapData *this, char *keyName, char *value)
{
  this->m_pCurrentKey = this->m_pEntData;
  return CEntityMapData::GetNextKey(this, keyName, value);
}

//------------------------------------------------------------------------------
// Address: 0x101703B0
// Name: public: bool CEntityMapData::SetValue(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CEntityMapData::SetValue(CEntityMapData *this, const char *keyName, char *NewValue, int nKeyInstance)
{
  bool v5; // zf
  char *m_pEntData; // eax
  int i; // esi
  char *v9; // ebx
  unsigned int v10; // esi
  char *v11; // edi
  const char *v12; // eax
  int v13; // esi
  char token[2048]; // [esp+4h] [ebp-C04h] BYREF
  char newvaluebuf[1024]; // [esp+804h] [ebp-404h] BYREF
  CEntityMapData *v16; // [esp+C04h] [ebp-4h]
  int iNewValueLen; // [esp+C10h] [ebp+8h]

  v5 = this->m_nEntDataSize == -1;
  v16 = this;
  if ( v5 )
    return 0;
  m_pEntData = this->m_pEntData;
  for ( i = 0; m_pEntData != nullptr; m_pEntData = (char *)MapEntity_ParseToken(data: v9, newToken: token) )
  {
    v9 = (char *)MapEntity_ParseToken(data: m_pEntData, newToken: token);
    if ( token[0] == 125 )
      break;
    if ( strcmp(token, keyName) == 0 && ++i > nKeyInstance )
    {
      v10 = strlen(this->m_pEntData);
      v11 = (char *)operator new(nSize: v10);
      v12 = MapEntity_ParseToken(data: v9, newToken: token);
      V_strncpy(pDest: v11, pSrc: v12, maxLen: v10);
      if ( *NewValue == 34 )
        V_strncpy(pDest: newvaluebuf, pSrc: NewValue, maxLen: 1024);
      else
        V_snprintf(pDest: newvaluebuf, maxLen: 1024, pFormat: "\"%s\"", NewValue);
      iNewValueLen = _V_strlen(str: newvaluebuf);
      v13 = iNewValueLen - _V_strlen(str: token) - 2;
      V_strncpy(pDest: v9 + 1, pSrc: newvaluebuf, maxLen: iNewValueLen + 1);
      V_strncat(
        pDest: v9,
        pSrc: v11,
        destBufferSize: v16->m_pEntData - v9 + v16->m_nEntDataSize - 1,
        max_chars_to_copy: -1);
      v16->m_pCurrentKey += v13;
      free(pMem: v11);
      return 1;
    }
  }
  return 0;
}

} // namespace server
