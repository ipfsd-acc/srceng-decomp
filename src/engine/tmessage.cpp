// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/tmessage.cpp
// Functions: 11
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x101147A0
// Name: int ParseFloats(char const __near *,float __near *,int)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl ParseFloats(const char *pText, float *pFloat, int count)
{
  const char *v4; // esi
  char v6; // al
  int i; // ecx
  const char *v8; // esi
  char v9; // al
  int j; // ecx

  v4 = pText;
  if ( pText != nullptr )
  {
    while ( count > 0 )
    {
      v6 = *v4;
      for ( i = 0; v6 != 0; ++i )
      {
        if ( g_WhiteSpace.set[v6] != 0 )
          break;
        v6 = v4[i + 1];
      }
      v8 = &v4[i];
      if ( v8 == nullptr )
        break;
      v9 = *v8;
      for ( j = 0; v9 != 0; ++j )
      {
        if ( g_WhiteSpace.set[v9] == 0 )
          break;
        v9 = v8[j + 1];
      }
      v4 = &v8[j];
      if ( v4 == nullptr )
        break;
      *pFloat = atof(nptr: v4);
      --count;
      ++pFloat;
    }
  }
  return count == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10114820
// Name: int ParseString(char const __near *,char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ParseString(char *pText, char *buf, unsigned int bufsize)
{
  char v3; // cl
  int i; // eax
  const char *v5; // eax
  char v6; // cl
  int j; // edx
  const char *v8; // eax
  char v9; // dl
  int k; // ecx
  int v11; // esi

  if ( pText == nullptr )
    return 0;
  v3 = *pText;
  for ( i = 0; v3 != 0; ++i )
  {
    if ( g_WhiteSpace.set[v3] != 0 )
      break;
    v3 = pText[i + 1];
  }
  v5 = &pText[i];
  if ( v5 == nullptr )
    return 0;
  v6 = *v5;
  for ( j = 0; v6 != 0; ++j )
  {
    if ( g_WhiteSpace.set[v6] == 0 )
      break;
    v6 = v5[j + 1];
  }
  v8 = &v5[j];
  if ( v8 == nullptr )
    return 0;
  v9 = *v8;
  for ( k = 0; v9 != 0; ++k )
  {
    if ( g_WhiteSpace.set[v9] != 0 )
      break;
    v9 = v8[k + 1];
  }
  v11 = bufsize - 1;
  if ( k + 1 < (int)(bufsize - 1) )
    v11 = k + 1;
  V_strncpy(pDest: buf, pSrc: v8, maxLen: v11);
  buf[v11] = 0;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101148E0
// Name: void TrimSpace(char const __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TrimSpace(const char *source, char *dest)
{
  int v2; // edi
  unsigned int v3; // eax
  char i; // cl
  int j; // eax
  int v6; // eax
  int v7; // esi

  v2 = 0;
  v3 = strlen(source);
  for ( i = *source; i != 0; ++v2 )
  {
    if ( g_WhiteSpace.set[i] == 0 )
      break;
    i = source[v2 + 1];
  }
  for ( j = v3 - 1; j > 0; --j )
  {
    if ( g_WhiteSpace.set[source[j]] == 0 )
      break;
  }
  v6 = j - v2;
  v7 = v6 + 1;
  if ( v6 + 1 <= 0 )
  {
    *dest = 0;
  }
  else
  {
    memcpy(dst: (unsigned __int8 *)dest, src: (unsigned __int8 *)&source[v2], count: v6 + 1);
    dest[v7] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10114960
// Name: int IsToken(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl IsToken(const char *pText, const char *pTokenName)
{
  return pText != nullptr
      && pTokenName != nullptr
      && V_strnicmp(s1: pText + 1, s2: pTokenName, n: strlen(pTokenName)) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x101149A0
// Name: int ParseDirective(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ParseDirective(char *pText)
{
  int i; // eax
  float tempFloat[8]; // [esp+4h] [ebp-20h] BYREF

  if ( pText == nullptr || *pText != 36 )
    return 0;
  if ( V_strnicmp(s1: pText + 1, s2: "position", n: 8) == 0 )
  {
    if ( ParseFloats(pText, pFloat: tempFloat, count: 2) )
    {
      gMessageParms.x = tempFloat[0];
      gMessageParms.y = tempFloat[1];
      return 1;
    }
    return 1;
  }
  if ( IsToken(pText, pTokenName: "effect") )
  {
    if ( ParseFloats(pText, pFloat: tempFloat, count: 1) )
    {
      gMessageParms.effect = (int)tempFloat[0];
      return 1;
    }
    return 1;
  }
  if ( IsToken(pText, pTokenName: "fxtime") )
  {
    if ( ParseFloats(pText, pFloat: tempFloat, count: 1) )
    {
      gMessageParms.fxtime = tempFloat[0];
      return 1;
    }
    return 1;
  }
  if ( IsToken(pText, pTokenName: "color2") )
  {
    if ( ParseFloats(pText, pFloat: tempFloat, count: 3) )
    {
      gMessageParms.r2 = (int)tempFloat[0];
      gMessageParms.g2 = (int)tempFloat[1];
      gMessageParms.b2 = (int)tempFloat[2];
      return 1;
    }
    return 1;
  }
  if ( IsToken(pText, pTokenName: "color") )
  {
    if ( ParseFloats(pText, pFloat: tempFloat, count: 3) )
    {
      gMessageParms.b1 = (int)tempFloat[2];
      gMessageParms.r1 = (int)tempFloat[0];
      gMessageParms.g1 = (int)tempFloat[1];
      return 1;
    }
    return 1;
  }
  if ( IsToken(pText, pTokenName: "fadein") )
  {
    if ( ParseFloats(pText, pFloat: tempFloat, count: 1) )
    {
      gMessageParms.fadein = tempFloat[0];
      return 1;
    }
    return 1;
  }
  if ( IsToken(pText, pTokenName: "fadeout") )
  {
    if ( ParseFloats(pText, pFloat: tempFloat, count: 3) )
    {
      gMessageParms.fadeout = tempFloat[0];
      return 1;
    }
    return 1;
  }
  if ( IsToken(pText, pTokenName: "holdtime") )
  {
    if ( ParseFloats(pText, pFloat: tempFloat, count: 3) )
    {
      gMessageParms.holdtime = tempFloat[0];
      return 1;
    }
    return 1;
  }
  if ( IsToken(pText, pTokenName: "boxsize") )
  {
    if ( ParseFloats(pText, pFloat: tempFloat, count: 1) )
    {
      gMessageParms.bRoundedRectBackdropBox = tempFloat[0] != 0.0;
      gMessageParms.flBoxSize = tempFloat[0];
      return 1;
    }
    return 1;
  }
  if ( IsToken(pText, pTokenName: "boxcolor") )
  {
    if ( ParseFloats(pText, pFloat: tempFloat, count: 4) )
    {
      for ( i = 0; i < 4; ++i )
        gMessageParms.boxcolor[i] = (int)tempFloat[i];
      return 1;
    }
    return 1;
  }
  if ( !IsToken(pText, pTokenName: "clearmessage") )
  {
    _ConDMsg(a1: "Unknown token: %s\n", pText);
    return 1;
  }
  if ( ParseString(pText, buf: g_pchSkipName, bufsize: 0x40u) == 0 )
    return 1;
  if ( g_pchSkipName[0] != 0 && _V_stricmp(s1: g_pchSkipName, s2: "0") != 0 )
  {
    gMessageParms.pClearMessage = g_pchSkipName;
    return 1;
  }
  else
  {
    gMessageParms.pClearMessage = nullptr;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10114D30
// Name: TextMessageParse
// Source: json
//------------------------------------------------------------------------------
void __cdecl TextMessageParse(unsigned __int8 *pMemFile, int fileSize)
{
  int v2; // edi
  int v3; // esi
  int v4; // eax
  char *v5; // ebx
  unsigned __int8 *v6; // ecx
  unsigned __int8 v7; // al
  char *v8; // eax
  unsigned int v9; // eax
  const char *v10; // edi
  char *v11; // esi
  int v12; // eax
  int v13; // eax
  bool v14; // zf
  const char *v15; // eax
  const char *v16; // eax
  const char *v17; // eax
  int v18; // kr08_4
  int v19; // edx
  const char **v20; // ebx
  int i; // edi
  unsigned int v22; // eax
  unsigned int v23; // edi
  unsigned int v24; // esi
  unsigned __int8 *v25; // esi
  client_textmessage_t *v26; // eax
  int v27; // edi
  char *v28; // ebx
  int v29; // ecx
  int v30; // esi
  client_textmessage_t *v31; // eax
  unsigned __int8 v32[44]; // [esp+38h] [ebp-DC20h] BYREF
  char v33; // [esp+64h] [ebp-DBF4h] BYREF
  char v34; // [esp+68h] [ebp-DBF0h] BYREF
  unsigned __int8 str[52]; // [esp+963Ch] [ebp-461Ch] BYREF
  char source[52]; // [esp+D63Ch] [ebp-61Ch] BYREF
  char v37[52]; // [esp+D83Ch] [ebp-41Ch] BYREF
  char pText[52]; // [esp+DA3Ch] [ebp-21Ch] BYREF
  int v39; // [esp+DC3Ch] [ebp-1Ch]
  int v40; // [esp+DC40h] [ebp-18h]
  int v41; // [esp+DC44h] [ebp-14h] BYREF
  unsigned __int8 *v42; // [esp+DC48h] [ebp-10h]
  _BYTE v43[5]; // [esp+DC4Fh] [ebp-9h]
  unsigned int v44; // [esp+DC54h] [ebp-4h]

  v2 = 0;
  v3 = 0;
  v42 = nullptr;
  v39 = 0;
  v44 = 0;
  v40 = 0;
  v41 = 0;
  *(_DWORD *)&v43[1] = 0;
  v4 = _CommandLine();
  *(_DWORD *)v43 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v4 + 40))(a1: v4, a2: "-textmessagedebug") != 0;
  CharacterSetBuild(pSetBuffer: &g_WhiteSpace, pszSetString: " \r\n\t");
  if ( memfgets(pMemFile, fileSize, pFilePos: &v41, pBuffer: source, bufferSize: 512) == nullptr )
    goto LABEL_44;
  v5 = &v33;
  while ( 1 )
  {
    TrimSpace(source, dest: pText);
    if ( v39 != 0 )
    {
      if ( v39 != 1 )
        goto LABEL_38;
      if ( pText[0] == 125 )
      {
        if ( (int)(v44 + strlen(v37)) > 0x2000 )
        {
          _ConDMsg(a1: "Error parsing file!\n");
          return;
        }
        _V_strcpy(dest: (char *)&str[v44], src: v37);
        if ( v42 != nullptr && *v42 == 35 && v2 > 1 )
        {
          v6 = pMemFile;
          v7 = pMemFile[v2 - 2];
          if ( v7 == 10 || v7 == 13 )
          {
            pMemFile[v2 - 2] = 0;
LABEL_15:
            v8 = (char *)&str[v44];
            qmemcpy(v5 - 40, &gMessageParms, 64);
            *(_DWORD *)v5 = v8;
            v9 = v44 + strlen(v37) + 1;
            v44 = v9;
            if ( gMessageParms.pClearMessage != nullptr )
            {
              v10 = *((const char **)v5 + 5);
              v11 = (char *)&str[v9];
              v12 = _V_strlen(str: v10);
              V_strncpy(pDest: v11, pSrc: v10, maxLen: v12 + 1);
              *((_DWORD *)v5 + 5) = v11;
              v13 = _V_strlen(str: v11);
              v44 += v13 + 1;
            }
            v14 = v43[0] == 0;
            *((_DWORD *)v5 + 1) = v42;
            if ( !v14 )
            {
              v15 = *(const char **)v5;
              if ( *(_DWORD *)v5 == 0 )
                v15 = "(null)";
              _Msg(a1: "%d %s\n", *(_DWORD *)&v43[1], v15);
              _Msg(
                a1: "  effect %d, color1(%d,%d,%d,%d), color2(%d,%d,%d,%d)\n",
                *((_DWORD *)v5 - 10),
                (unsigned __int8)*(v5 - 36),
                (unsigned __int8)*(v5 - 35),
                (unsigned __int8)*(v5 - 34),
                (unsigned __int8)*(v5 - 33),
                (unsigned __int8)*(v5 - 32),
                (unsigned __int8)*(v5 - 31),
                (unsigned __int8)*(v5 - 30),
                (unsigned __int8)*(v5 - 29));
              _Msg(
                a1: "  pos %f,%f, fadein %f fadeout %f hold %f fxtime %f\n",
                *((float *)v5 - 7),
                *((float *)v5 - 6),
                *((float *)v5 - 5),
                *((float *)v5 - 4),
                *((float *)v5 - 3),
                *((float *)v5 - 2));
              v16 = *((const char **)v5 + 1);
              if ( v16 == nullptr )
                v16 = "(null)";
              _Msg(a1: "  '%s'\n", v16);
              v17 = "yes";
              if ( v5[8] == 0 )
                v17 = "no";
              _Msg(
                a1: "  box %s, size %f, color(%d,%d,%d,%d)\n",
                v17,
                *((float *)v5 + 3),
                (unsigned __int8)v5[16],
                (unsigned __int8)v5[17],
                (unsigned __int8)v5[18],
                (unsigned __int8)v5[19]);
              if ( *((_DWORD *)v5 + 5) != 0 )
                _Msg(a1: "  will clear '%s'\n", *((const char **)v5 + 5));
            }
            v3 = ++*(_DWORD *)&v43[1];
            v5 += 64;
            v39 = 0;
            goto LABEL_38;
          }
        }
        else
        {
          v6 = pMemFile;
        }
        v6[v2 - 1] = 0;
        goto LABEL_15;
      }
      if ( pText[0] == 123 )
      {
        _ConDMsg(a1: "Unexpected '{' found, line %d\n", v40);
        return;
      }
    }
    else
    {
      v18 = strlen(pText);
      if ( (v18 < 2 || pText[0] != 47 || pText[1] != 47) && v18 > 0 && ParseDirective(pText) == 0 )
      {
        if ( pText[0] == 123 )
        {
          v39 = 1;
          v42 = &pMemFile[v41];
        }
        else
        {
          if ( pText[0] == 125 )
          {
            _ConDMsg(a1: "Unexpected '}' found, line %d\n", v40);
            return;
          }
          V_strncpy(pDest: v37, pSrc: pText, maxLen: 512);
        }
      }
    }
LABEL_38:
    ++v40;
    v2 = v41;
    if ( v3 >= 600 )
      break;
    if ( memfgets(pMemFile, fileSize, pFilePos: &v41, pBuffer: source, bufferSize: 512) == nullptr )
      goto LABEL_44;
  }
  ConMsg(a1: "WARNING: TOO MANY MESSAGES IN TITLES.TXT, MAX IS %d\n", 600);
LABEL_44:
  _ConDMsg(a1: "Parsed %d text messages\n", v3);
  v19 = 0;
  if ( v3 > 0 )
  {
    v20 = (const char **)&v34;
    for ( i = v3; i != 0; --i )
    {
      v22 = strlen(*v20);
      v20 += 16;
      v19 += v22 + 1;
    }
    v3 = *(_DWORD *)&v43[1];
  }
  v23 = v44;
  v24 = v3 << 6;
  gMessageTable = (client_textmessage_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v44 + v24 + v19);
  memcpy(dst: (unsigned __int8 *)gMessageTable, src: &v32[4], count: v24);
  v25 = (unsigned __int8 *)gMessageTable + v24;
  memcpy(dst: v25, src: str, count: v23);
  v26 = gMessageTable;
  v27 = v25 - (unsigned __int8 *)gMessageTable->pName;
  v28 = (char *)&v25[v44];
  v29 = *(_DWORD *)&v43[1];
  if ( *(int *)&v43[1] > 0 )
  {
    v30 = 0;
    v42 = *(unsigned __int8 **)&v43[1];
    while ( 1 )
    {
      v26[v30].pName += v27;
      v31 = gMessageTable;
      if ( gMessageTable[v30].pClearMessage != nullptr )
      {
        gMessageTable[v30].pClearMessage += v27;
        v31 = gMessageTable;
      }
      _V_strcpy(dest: v28, src: v31[v30].pMessage);
      gMessageTable[v30++].pMessage = v28;
      v14 = v42-- == (unsigned __int8 *)1;
      v28 += strlen(v28) + 1;
      if ( v14 )
        break;
      v26 = gMessageTable;
    }
    v29 = *(_DWORD *)&v43[1];
  }
  gMessageTableCount = v29;
}

//------------------------------------------------------------------------------
// Address: 0x10115210
// Name: _TextMessageShutdown
// Source: json
//------------------------------------------------------------------------------
client_textmessage_t *TextMessageShutdown()
{
  client_textmessage_t *result; // eax

  result = gMessageTable;
  if ( gMessageTable != nullptr )
  {
    result = (client_textmessage_t *)((int (__thiscall *)(IMemAlloc *, client_textmessage_t *))_g_pMemAlloc->Free_2)(
                                       a1: _g_pMemAlloc,
                                       a2: gMessageTable);
    gMessageTable = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10115240
// Name: _TextMessageInit
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall TextMessageInit(void *this)
{
  unsigned __int8 *result; // eax
  unsigned __int8 *v2; // esi
  int fileSize; // [esp+0h] [ebp-4h] BYREF

  fileSize = (int)this;
  if ( gMessageTable != nullptr )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: gMessageTable);
    gMessageTable = nullptr;
  }
  result = COM_LoadFile(path: "scripts/titles.txt", usehunk: 5, pLength: &fileSize);
  v2 = result;
  if ( result != nullptr )
  {
    TextMessageParse(pMemFile: result, fileSize);
    result = (unsigned __int8 *)((int (__thiscall *)(IMemAlloc *, unsigned __int8 *))_g_pMemAlloc->Free_2)(
                                  a1: _g_pMemAlloc,
                                  a2: v2);
  }
  gNetworkTextMessage[0].pMessage = gNetworkTextMessageBuffer[0];
  gNetworkTextMessage[1].pMessage = gNetworkTextMessageBuffer[1];
  gNetworkTextMessage[2].pMessage = gNetworkTextMessageBuffer[2];
  gNetworkTextMessage[3].pMessage = gNetworkTextMessageBuffer[3];
  gNetworkTextMessage[4].pMessage = gNetworkTextMessageBuffer[4];
  gNetworkTextMessage[5].pMessage = gNetworkTextMessageBuffer[5];
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101152E0
// Name: _TextMessage_DemoMessageFull
// Source: json
//------------------------------------------------------------------------------
void __cdecl TextMessage_DemoMessageFull(const char *pszMessage, const client_textmessage_t *message)
{
  if ( message != nullptr && pszMessage != nullptr && *pszMessage != 0 )
  {
    tm_demomessage = *message;
    tm_demomessage.pMessage = orig_demo_message.pMessage;
    tm_demomessage.pName = orig_demo_message.pName;
    V_strncpy(pDest: gDemoMessageBuffer, pSrc: pszMessage, maxLen: 512);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10115340
// Name: _TextMessageGet
// Source: json
//------------------------------------------------------------------------------
client_textmessage_t *__cdecl TextMessageGet(const char *pName)
{
  int v2; // esi
  int i; // edi

  if ( _V_stricmp(s1: pName, s2: "__DEMOMESSAGE__") == 0 )
    return &tm_demomessage;
  if ( _V_stricmp(s1: pName, s2: "__NETMESSAGE__1") == 0 )
    return gNetworkTextMessage;
  if ( _V_stricmp(s1: pName, s2: "__NETMESSAGE__2") == 0 )
    return &gNetworkTextMessage[1];
  if ( _V_stricmp(s1: pName, s2: "__NETMESSAGE__3") == 0 )
    return &gNetworkTextMessage[2];
  if ( _V_stricmp(s1: pName, s2: "__NETMESSAGE__4") == 0 )
    return &gNetworkTextMessage[3];
  if ( _V_stricmp(s1: pName, s2: "__NETMESSAGE__5") == 0 )
    return &gNetworkTextMessage[4];
  if ( _V_stricmp(s1: pName, s2: "__NETMESSAGE__6") == 0 )
    return &gNetworkTextMessage[5];
  v2 = 0;
  if ( gMessageTableCount <= 0 )
    return nullptr;
  for ( i = 0; _V_stricmp(s1: pName, s2: gMessageTable[i].pName) != 0; ++i )
  {
    if ( ++v2 >= gMessageTableCount )
      return nullptr;
  }
  return &gMessageTable[v2];
}

//------------------------------------------------------------------------------
// Address: 0x102618B0
// Name: bool ParseString(char const __near * __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ParseString(const char **expr, const char *str)
{
  const char *v2; // edi
  const char *v3; // ecx
  char v4; // al
  const char *v5; // eax

  v2 = *expr;
  while ( 1 )
  {
    v3 = *expr;
    v4 = **expr;
    if ( v4 != 32 && v4 != 9 )
      break;
    *expr = v3 + 1;
  }
  v5 = StringAfterPrefix(str: v3, prefix: str);
  *expr = v5;
  if ( v5 != nullptr )
    return 1;
  *expr = v2;
  return 0;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10114940
// Name: int ParseFloats(char const __near *,float __near *,int)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl ParseFloats(const char *pText, float *pFloat, int count)
{
  const char *v4; // esi
  char v6; // al
  int i; // ecx
  const char *v8; // esi
  char v9; // al
  int j; // ecx

  v4 = pText;
  if ( pText != nullptr )
  {
    while ( count > 0 )
    {
      v6 = *v4;
      for ( i = 0; v6 != 0; ++i )
      {
        if ( g_WhiteSpace.set[v6] != 0 )
          break;
        v6 = v4[i + 1];
      }
      v8 = &v4[i];
      if ( v8 == nullptr )
        break;
      v9 = *v8;
      for ( j = 0; v9 != 0; ++j )
      {
        if ( g_WhiteSpace.set[v9] == 0 )
          break;
        v9 = v8[j + 1];
      }
      v4 = &v8[j];
      if ( v4 == nullptr )
        break;
      *pFloat = atof(nptr: v4);
      --count;
      ++pFloat;
    }
  }
  return count == 0;
}

//------------------------------------------------------------------------------
// Address: 0x101149C0
// Name: int ParseString(char const __near *,char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ParseString(char *pText, char *buf, unsigned int bufsize)
{
  char v3; // cl
  int i; // eax
  const char *v5; // eax
  char v6; // cl
  int j; // edx
  const char *v8; // eax
  char v9; // dl
  int k; // ecx
  int v11; // esi

  if ( pText == nullptr )
    return 0;
  v3 = *pText;
  for ( i = 0; v3 != 0; ++i )
  {
    if ( g_WhiteSpace.set[v3] != 0 )
      break;
    v3 = pText[i + 1];
  }
  v5 = &pText[i];
  if ( v5 == nullptr )
    return 0;
  v6 = *v5;
  for ( j = 0; v6 != 0; ++j )
  {
    if ( g_WhiteSpace.set[v6] == 0 )
      break;
    v6 = v5[j + 1];
  }
  v8 = &v5[j];
  if ( v8 == nullptr )
    return 0;
  v9 = *v8;
  for ( k = 0; v9 != 0; ++k )
  {
    if ( g_WhiteSpace.set[v9] != 0 )
      break;
    v9 = v8[k + 1];
  }
  v11 = bufsize - 1;
  if ( k + 1 < (int)(bufsize - 1) )
    v11 = k + 1;
  V_strncpy(pDest: buf, pSrc: v8, maxLen: v11);
  buf[v11] = 0;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10114A80
// Name: void TrimSpace(char const __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TrimSpace(const char *source, char *dest)
{
  int v2; // edi
  unsigned int v3; // eax
  char i; // cl
  int j; // eax
  int v6; // eax
  int v7; // esi

  v2 = 0;
  v3 = strlen(source);
  for ( i = *source; i != 0; ++v2 )
  {
    if ( g_WhiteSpace.set[i] == 0 )
      break;
    i = source[v2 + 1];
  }
  for ( j = v3 - 1; j > 0; --j )
  {
    if ( g_WhiteSpace.set[source[j]] == 0 )
      break;
  }
  v6 = j - v2;
  v7 = v6 + 1;
  if ( v6 + 1 <= 0 )
  {
    *dest = 0;
  }
  else
  {
    memcpy(dst: (unsigned __int8 *)dest, src: (unsigned __int8 *)&source[v2], count: v6 + 1);
    dest[v7] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10114B00
// Name: int IsToken(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl IsToken(const char *pText, const char *pTokenName)
{
  return pText != nullptr
      && pTokenName != nullptr
      && V_strnicmp(s1: pText + 1, s2: pTokenName, n: strlen(pTokenName)) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10114B40
// Name: int ParseDirective(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ParseDirective(char *pText)
{
  int i; // eax
  float tempFloat[8]; // [esp+4h] [ebp-20h] BYREF

  if ( pText == nullptr || *pText != 36 )
    return 0;
  if ( V_strnicmp(s1: pText + 1, s2: "position", n: 8) == 0 )
  {
    if ( ParseFloats(pText, pFloat: tempFloat, count: 2) )
    {
      gMessageParms.x = tempFloat[0];
      gMessageParms.y = tempFloat[1];
      return 1;
    }
    return 1;
  }
  if ( IsToken(pText, pTokenName: "effect") )
  {
    if ( ParseFloats(pText, pFloat: tempFloat, count: 1) )
    {
      gMessageParms.effect = (int)tempFloat[0];
      return 1;
    }
    return 1;
  }
  if ( IsToken(pText, pTokenName: "fxtime") )
  {
    if ( ParseFloats(pText, pFloat: tempFloat, count: 1) )
    {
      gMessageParms.fxtime = tempFloat[0];
      return 1;
    }
    return 1;
  }
  if ( IsToken(pText, pTokenName: "color2") )
  {
    if ( ParseFloats(pText, pFloat: tempFloat, count: 3) )
    {
      gMessageParms.r2 = (int)tempFloat[0];
      gMessageParms.g2 = (int)tempFloat[1];
      gMessageParms.b2 = (int)tempFloat[2];
      return 1;
    }
    return 1;
  }
  if ( IsToken(pText, pTokenName: "color") )
  {
    if ( ParseFloats(pText, pFloat: tempFloat, count: 3) )
    {
      gMessageParms.b1 = (int)tempFloat[2];
      gMessageParms.r1 = (int)tempFloat[0];
      gMessageParms.g1 = (int)tempFloat[1];
      return 1;
    }
    return 1;
  }
  if ( IsToken(pText, pTokenName: "fadein") )
  {
    if ( ParseFloats(pText, pFloat: tempFloat, count: 1) )
    {
      gMessageParms.fadein = tempFloat[0];
      return 1;
    }
    return 1;
  }
  if ( IsToken(pText, pTokenName: "fadeout") )
  {
    if ( ParseFloats(pText, pFloat: tempFloat, count: 3) )
    {
      gMessageParms.fadeout = tempFloat[0];
      return 1;
    }
    return 1;
  }
  if ( IsToken(pText, pTokenName: "holdtime") )
  {
    if ( ParseFloats(pText, pFloat: tempFloat, count: 3) )
    {
      gMessageParms.holdtime = tempFloat[0];
      return 1;
    }
    return 1;
  }
  if ( IsToken(pText, pTokenName: "boxsize") )
  {
    if ( ParseFloats(pText, pFloat: tempFloat, count: 1) )
    {
      gMessageParms.bRoundedRectBackdropBox = tempFloat[0] != 0.0;
      gMessageParms.flBoxSize = tempFloat[0];
      return 1;
    }
    return 1;
  }
  if ( IsToken(pText, pTokenName: "boxcolor") )
  {
    if ( ParseFloats(pText, pFloat: tempFloat, count: 4) )
    {
      for ( i = 0; i < 4; ++i )
        gMessageParms.boxcolor[i] = (int)tempFloat[i];
      return 1;
    }
    return 1;
  }
  if ( !IsToken(pText, pTokenName: "clearmessage") )
  {
    _ConDMsg(a1: "Unknown token: %s\n", pText);
    return 1;
  }
  if ( ParseString(pText, buf: g_pchSkipName, bufsize: 0x40u) == 0 )
    return 1;
  if ( g_pchSkipName[0] != 0 && _V_stricmp(s1: g_pchSkipName, s2: "0") != 0 )
  {
    gMessageParms.pClearMessage = g_pchSkipName;
    return 1;
  }
  else
  {
    gMessageParms.pClearMessage = nullptr;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10114ED0
// Name: TextMessageParse
// Source: json
//------------------------------------------------------------------------------
void __cdecl TextMessageParse(__int64 pMemFile)
{
  int v1; // edi
  int v2; // esi
  int v3; // eax
  char *v4; // ebx
  int v5; // ecx
  char v6; // al
  char *v7; // eax
  unsigned int v8; // eax
  const char *v9; // edi
  char *v10; // esi
  int v11; // eax
  int v12; // eax
  bool v13; // zf
  const char *v14; // eax
  const char *v15; // eax
  const char *v16; // eax
  int v17; // kr08_4
  int v18; // edx
  const char **v19; // ebx
  int i; // edi
  unsigned int v21; // eax
  unsigned int v22; // edi
  unsigned int v23; // esi
  unsigned __int8 *v24; // esi
  client_textmessage_t *v25; // eax
  int v26; // edi
  char *v27; // ebx
  int v28; // ecx
  int v29; // esi
  client_textmessage_t *v30; // eax
  unsigned __int8 v31[40]; // [esp+40h] [ebp-DC1Ch] BYREF
  char v32; // [esp+68h] [ebp-DBF4h] BYREF
  char v33; // [esp+6Ch] [ebp-DBF0h] BYREF
  unsigned __int8 pDest[16384]; // [esp+9640h] [ebp-461Ch] BYREF
  char pBuffer[512]; // [esp+D640h] [ebp-61Ch] BYREF
  char src[512]; // [esp+D840h] [ebp-41Ch] BYREF
  char dest[512]; // [esp+DA40h] [ebp-21Ch] BYREF
  int v38; // [esp+DC40h] [ebp-1Ch]
  int v39; // [esp+DC44h] [ebp-18h]
  int pFilePos; // [esp+DC48h] [ebp-14h] BYREF
  _BYTE *v41; // [esp+DC4Ch] [ebp-10h]
  _BYTE v42[5]; // [esp+DC53h] [ebp-9h]
  unsigned int count; // [esp+DC58h] [ebp-4h]

  v1 = 0;
  v2 = 0;
  v41 = nullptr;
  v38 = 0;
  count = 0;
  v39 = 0;
  pFilePos = 0;
  *(_DWORD *)&v42[1] = 0;
  v3 = _CommandLine();
  *(_DWORD *)v42 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v3 + 40))(a1: v3, a2: "-textmessagedebug") != 0;
  CharacterSetBuild(pSetBuffer: &g_WhiteSpace, pszSetString: " \r\n\t");
  if ( memfgets((unsigned __int8 *)pMemFile, fileSize: SHIDWORD(pMemFile), &pFilePos, pBuffer, bufferSize: 512) == nullptr )
    goto LABEL_44;
  v4 = &v32;
  while ( 1 )
  {
    TrimSpace(source: pBuffer, dest);
    if ( v38 != 0 )
    {
      if ( v38 != 1 )
        goto LABEL_38;
      if ( dest[0] == 125 )
      {
        if ( (int)(count + strlen(src)) > 0x2000 )
        {
          _ConDMsg(a1: "Error parsing file!\n");
          return;
        }
        _V_strcpy(dest: (char *)&pDest[count], src);
        if ( v41 != nullptr && *v41 == 35 && v1 > 1 )
        {
          v5 = pMemFile;
          v6 = *(_BYTE *)(v1 + pMemFile - 2);
          if ( v6 == 10 || v6 == 13 )
          {
            *(_BYTE *)(v1 + pMemFile - 2) = 0;
LABEL_15:
            v7 = (char *)&pDest[count];
            qmemcpy(v4 - 40, &gMessageParms, 64);
            *(_DWORD *)v4 = v7;
            v8 = count + strlen(src) + 1;
            count = v8;
            if ( gMessageParms.pClearMessage != nullptr )
            {
              v9 = *((const char **)v4 + 5);
              v10 = (char *)&pDest[v8];
              v11 = _V_strlen(str: v9);
              V_strncpy(pDest: v10, pSrc: v9, maxLen: v11 + 1);
              *((_DWORD *)v4 + 5) = v10;
              v12 = _V_strlen(str: v10);
              count += v12 + 1;
            }
            v13 = v42[0] == 0;
            *((_DWORD *)v4 + 1) = v41;
            if ( !v13 )
            {
              v14 = *(const char **)v4;
              if ( *(_DWORD *)v4 == 0 )
                v14 = "(null)";
              _Msg(a1: "%d %s\n", *(_DWORD *)&v42[1], v14);
              _Msg(
                a1: "  effect %d, color1(%d,%d,%d,%d), color2(%d,%d,%d,%d)\n",
                *((_DWORD *)v4 - 10),
                (unsigned __int8)*(v4 - 36),
                (unsigned __int8)*(v4 - 35),
                (unsigned __int8)*(v4 - 34),
                (unsigned __int8)*(v4 - 33),
                (unsigned __int8)*(v4 - 32),
                (unsigned __int8)*(v4 - 31),
                (unsigned __int8)*(v4 - 30),
                (unsigned __int8)*(v4 - 29));
              _Msg(
                a1: "  pos %f,%f, fadein %f fadeout %f hold %f fxtime %f\n",
                *((float *)v4 - 7),
                *((float *)v4 - 6),
                *((float *)v4 - 5),
                *((float *)v4 - 4),
                *((float *)v4 - 3),
                *((float *)v4 - 2));
              v15 = *((const char **)v4 + 1);
              if ( v15 == nullptr )
                v15 = "(null)";
              _Msg(a1: "  '%s'\n", v15);
              v16 = "yes";
              if ( v4[8] == 0 )
                v16 = "no";
              _Msg(
                a1: "  box %s, size %f, color(%d,%d,%d,%d)\n",
                v16,
                *((float *)v4 + 3),
                (unsigned __int8)v4[16],
                (unsigned __int8)v4[17],
                (unsigned __int8)v4[18],
                (unsigned __int8)v4[19]);
              if ( *((_DWORD *)v4 + 5) != 0 )
                _Msg(a1: "  will clear '%s'\n", *((const char **)v4 + 5));
            }
            v2 = ++*(_DWORD *)&v42[1];
            v4 += 64;
            v38 = 0;
            goto LABEL_38;
          }
        }
        else
        {
          v5 = pMemFile;
        }
        *(_BYTE *)(v1 + v5 - 1) = 0;
        goto LABEL_15;
      }
      if ( dest[0] == 123 )
      {
        _ConDMsg(a1: "Unexpected '{' found, line %d\n", v39);
        return;
      }
    }
    else
    {
      v17 = strlen(dest);
      if ( (v17 < 2 || dest[0] != 47 || dest[1] != 47) && v17 > 0 && ParseDirective(pText: dest) == 0 )
      {
        if ( dest[0] == 123 )
        {
          v38 = 1;
          v41 = (_BYTE *)(pMemFile + pFilePos);
        }
        else
        {
          if ( dest[0] == 125 )
          {
            _ConDMsg(a1: "Unexpected '}' found, line %d\n", v39);
            return;
          }
          V_strncpy(pDest: src, pSrc: dest, maxLen: 512);
        }
      }
    }
LABEL_38:
    ++v39;
    v1 = pFilePos;
    if ( v2 >= 600 )
      break;
    if ( memfgets((unsigned __int8 *)pMemFile, fileSize: SHIDWORD(pMemFile), &pFilePos, pBuffer, bufferSize: 512) == nullptr )
      goto LABEL_44;
  }
  ConMsg(a1: "WARNING: TOO MANY MESSAGES IN TITLES.TXT, MAX IS %d\n", 600);
LABEL_44:
  _ConDMsg(a1: "Parsed %d text messages\n", v2);
  v18 = 0;
  if ( v2 > 0 )
  {
    v19 = (const char **)&v33;
    for ( i = v2; i != 0; --i )
    {
      v21 = strlen(*v19);
      v19 += 16;
      v18 += v21 + 1;
    }
    v2 = *(_DWORD *)&v42[1];
  }
  v22 = count;
  v23 = v2 << 6;
  gMessageTable = (client_textmessage_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: count + v23 + v18);
  memcpy(dst: (unsigned __int8 *)gMessageTable, src: v31, count: v23);
  v24 = (unsigned __int8 *)gMessageTable + v23;
  memcpy(dst: v24, src: pDest, count: v22);
  v25 = gMessageTable;
  v26 = v24 - (unsigned __int8 *)gMessageTable->pName;
  v27 = (char *)&v24[count];
  v28 = *(_DWORD *)&v42[1];
  if ( *(int *)&v42[1] > 0 )
  {
    v29 = 0;
    v41 = *(_BYTE **)&v42[1];
    while ( 1 )
    {
      v25[v29].pName += v26;
      v30 = gMessageTable;
      if ( gMessageTable[v29].pClearMessage != nullptr )
      {
        gMessageTable[v29].pClearMessage += v26;
        v30 = gMessageTable;
      }
      _V_strcpy(dest: v27, src: v30[v29].pMessage);
      gMessageTable[v29++].pMessage = v27;
      v13 = v41-- == (_BYTE *)1;
      v27 += strlen(v27) + 1;
      if ( v13 )
        break;
      v25 = gMessageTable;
    }
    v28 = *(_DWORD *)&v42[1];
  }
  gMessageTableCount = v28;
}

//------------------------------------------------------------------------------
// Address: 0x101153B0
// Name: _TextMessageShutdown
// Source: json
//------------------------------------------------------------------------------
client_textmessage_t *TextMessageShutdown()
{
  client_textmessage_t *result; // eax

  result = gMessageTable;
  if ( gMessageTable != nullptr )
  {
    result = (client_textmessage_t *)((int (__thiscall *)(IMemAlloc *, client_textmessage_t *))_g_pMemAlloc->Free_2)(
                                       a1: _g_pMemAlloc,
                                       a2: gMessageTable);
    gMessageTable = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101153E0
// Name: _TextMessageInit
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall TextMessageInit(void *this)
{
  unsigned __int8 *result; // eax
  unsigned __int8 *v2; // esi
  int fileSize; // [esp+0h] [ebp-4h] BYREF

  fileSize = (int)this;
  if ( gMessageTable != nullptr )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: gMessageTable);
    gMessageTable = nullptr;
  }
  result = COM_LoadFile(path: "scripts/titles.txt", usehunk: 5, pLength: &fileSize);
  v2 = result;
  if ( result != nullptr )
  {
    TextMessageParse(pMemFile: __SPAIR64__(fileSize, (unsigned int)result));
    result = (unsigned __int8 *)((int (__thiscall *)(IMemAlloc *, unsigned __int8 *))_g_pMemAlloc->Free_2)(
                                  a1: _g_pMemAlloc,
                                  a2: v2);
  }
  gNetworkTextMessage[0].pMessage = gNetworkTextMessageBuffer[0];
  gNetworkTextMessage[1].pMessage = gNetworkTextMessageBuffer[1];
  gNetworkTextMessage[2].pMessage = gNetworkTextMessageBuffer[2];
  gNetworkTextMessage[3].pMessage = gNetworkTextMessageBuffer[3];
  gNetworkTextMessage[4].pMessage = gNetworkTextMessageBuffer[4];
  gNetworkTextMessage[5].pMessage = gNetworkTextMessageBuffer[5];
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10115480
// Name: _TextMessage_DemoMessageFull
// Source: json
//------------------------------------------------------------------------------
void __cdecl TextMessage_DemoMessageFull(const char *pszMessage, const client_textmessage_t *message)
{
  if ( message != nullptr && pszMessage != nullptr && *pszMessage != 0 )
  {
    tm_demomessage = *message;
    tm_demomessage.pMessage = orig_demo_message.pMessage;
    tm_demomessage.pName = orig_demo_message.pName;
    V_strncpy(pDest: gDemoMessageBuffer, pSrc: pszMessage, maxLen: 512);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101154E0
// Name: _TextMessageGet
// Source: json
//------------------------------------------------------------------------------
client_textmessage_t *__cdecl TextMessageGet(const char *pName)
{
  int v2; // esi
  int i; // edi

  if ( _V_stricmp(s1: pName, s2: "__DEMOMESSAGE__") == 0 )
    return &tm_demomessage;
  if ( _V_stricmp(s1: pName, s2: "__NETMESSAGE__1") == 0 )
    return gNetworkTextMessage;
  if ( _V_stricmp(s1: pName, s2: "__NETMESSAGE__2") == 0 )
    return &gNetworkTextMessage[1];
  if ( _V_stricmp(s1: pName, s2: "__NETMESSAGE__3") == 0 )
    return &gNetworkTextMessage[2];
  if ( _V_stricmp(s1: pName, s2: "__NETMESSAGE__4") == 0 )
    return &gNetworkTextMessage[3];
  if ( _V_stricmp(s1: pName, s2: "__NETMESSAGE__5") == 0 )
    return &gNetworkTextMessage[4];
  if ( _V_stricmp(s1: pName, s2: "__NETMESSAGE__6") == 0 )
    return &gNetworkTextMessage[5];
  v2 = 0;
  if ( gMessageTableCount <= 0 )
    return nullptr;
  for ( i = 0; _V_stricmp(s1: pName, s2: gMessageTable[i].pName) != 0; ++i )
  {
    if ( ++v2 >= gMessageTableCount )
      return nullptr;
  }
  return &gMessageTable[v2];
}

//------------------------------------------------------------------------------
// Address: 0x102618E0
// Name: bool ParseString(char const __near * __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ParseString(const char **expr, const char *str)
{
  const char *v2; // edi
  const char *v3; // ecx
  char v4; // al
  const char *v5; // eax

  v2 = *expr;
  while ( 1 )
  {
    v3 = *expr;
    v4 = **expr;
    if ( v4 != 32 && v4 != 9 )
      break;
    *expr = v3 + 1;
  }
  v5 = StringAfterPrefix(str: v3, prefix: str);
  *expr = v5;
  if ( v5 != nullptr )
    return 1;
  *expr = v2;
  return 0;
}

} // namespace engine_xlsp
