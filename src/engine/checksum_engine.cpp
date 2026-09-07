// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/checksum_engine.cpp
// Functions: 3
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10149AC0
// Name: bool CRC_File(unsigned long __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CRC_File(unsigned int *crcvalue, char *pszFileName)
{
  int v2; // esi
  void *v3; // eax
  int (__thiscall *Read)(IBaseFileSystem *, void *, int, void *); // edx
  int v5; // eax
  bool v6; // zf
  _BYTE pBuffer[65536]; // [esp+8h] [ebp-10004h] BYREF
  void *file; // [esp+10008h] [ebp-4h] BYREF

  CRC32_Init(pulCRC: crcvalue);
  v2 = COM_OpenFile(filename: pszFileName, &file);
  v3 = file;
  if ( file == nullptr || v2 == -1 )
    return 0;
  if ( v2 > 0 )
  {
    while ( 1 )
    {
      Read = g_pFileSystem->Read;
      if ( (unsigned int)v2 <= 0x10000 )
        v5 = ((int (__stdcall *)(_BYTE *, int, void *))Read)(a1: pBuffer, a2: v2, a3: v3);
      else
        v5 = ((int (__stdcall *)(_BYTE *, int, void *))Read)(a1: pBuffer, a2: 0x10000, a3: v3);
      if ( v5 > 0 )
      {
        v2 -= v5;
        CRC32_ProcessBuffer(pulCRC: crcvalue, pBuffer, nBuffer: v5);
      }
      if ( g_pFileSystem->EndOfFile(this: g_pFileSystem, a2: file) )
      {
        g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: file);
        return 1;
      }
      v6 = !g_pFileSystem->IsOk(this: g_pFileSystem, a2: file);
      v3 = file;
      if ( v6 )
        break;
      if ( v2 <= 0 )
        goto LABEL_12;
    }
    if ( file != nullptr )
      g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: file);
    return 0;
  }
LABEL_12:
  if ( v3 != nullptr )
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v3);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10149BD0
// Name: int LumpCompare(void const __near *,void const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl LumpCompare(_DWORD *pElem0, _DWORD *pElem1)
{
  return g_pMapHeader->lumps[*pElem0].fileofs - g_pMapHeader->lumps[*pElem1].fileofs;
}

//------------------------------------------------------------------------------
// Address: 0x10149C00
// Name: bool CRC_MapFile(unsigned long __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __usercall CRC_MapFile@<al>(void *a1@<edi>, unsigned int *crcvalue, char *pszFileName)
{
  int v3; // eax
  int i; // eax
  int v6; // eax
  int v7; // ebx
  int v8; // edi
  IBaseFileSystem *v9; // ecx
  int v10; // eax
  int v11; // esi
  _BYTE pBuffer[65536]; // [esp+4h] [ebp-1051Ch] BYREF
  _BYTE v14[4]; // [esp+10004h] [ebp-51Ch] BYREF
  int v15; // [esp+10008h] [ebp-518h]
  _BYTE v16[1028]; // [esp+1000Ch] [ebp-514h]
  _DWORD base[64]; // [esp+10410h] [ebp-110h] BYREF
  unsigned int v18; // [esp+10510h] [ebp-10h]
  int v19; // [esp+10514h] [ebp-Ch]
  unsigned int pulCRC; // [esp+10518h] [ebp-8h] BYREF
  void *file; // [esp+1051Ch] [ebp-4h] BYREF

  v3 = COM_OpenFile(filename: pszFileName, &file);
  if ( file == nullptr || v3 == -1 )
    return 0;
  v18 = g_pFileSystem->Tell(this: &g_pFileSystem->IBaseFileSystem, a2: file);
  if ( g_pFileSystem->Read(this: &g_pFileSystem->IBaseFileSystem, a2: v14, a3: 1036, a4: file) == 0 )
  {
    ConMsg(a1: "Could not read BSP header for map [%s].\n", pszFileName);
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: file);
    return 0;
  }
  if ( (unsigned int)(v15 - 19) > 2 )
  {
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: file);
    ConMsg(a1: "Map [%s] has incorrect BSP version (%i should be %i).\n", pszFileName, v15, 21);
    return 0;
  }
  else
  {
    V_FileBase(in: com_gamedir, out: gamedir_4, maxlen: 260);
    g_pMapHeader = (BSPHeader_t *)v14;
    for ( i = 0; i < 64; ++i )
      base[i] = i;
    qsort(base, num: 0x40u, width: 4u, comp: (int (__cdecl *)(const void *, const void *))LumpCompare);
    v6 = 0;
    v19 = 0;
    while ( 1 )
    {
      v7 = base[v6];
      if ( v7 != 0 )
      {
        CRC32_Init(&pulCRC);
        if ( _V_stricmp(s1: gamedir_4, s2: "infested") != 0
          || v7 != 8
          && v7 != 26
          && v7 != 35
          && v7 != 37
          && v7 != 51
          && v7 != 52
          && v7 != 55
          && v7 != 56
          && v7 != 40
          && v7 != 29
          && v7 != 6
          && v7 != 28 )
        {
          v8 = *(_DWORD *)&v16[16 * v7 + 4];
          if ( v8 > 0 )
            break;
        }
      }
LABEL_38:
      v6 = v19 + 1;
      v19 = v6;
      if ( v6 >= 64 )
      {
        if ( file != nullptr )
          g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: file);
        return 1;
      }
    }
    g_pFileSystem->Seek(
      this: &g_pFileSystem->IBaseFileSystem,
      a2: file,
      a3: v18 + *(_DWORD *)&v16[16 * v7],
      a4: FILESYSTEM_SEEK_HEAD);
    while ( 1 )
    {
      v9 = &g_pFileSystem->IBaseFileSystem;
      if ( (unsigned int)v8 <= 0x10000 )
        v10 = ((int (__thiscall *)(IBaseFileSystem *, _BYTE *, int, void *, void *))v9->Read)(
                a1: v9,
                a2: pBuffer,
                a3: v8,
                a4: file,
                a5: a1);
      else
        v10 = ((int (__thiscall *)(IBaseFileSystem *, _BYTE *, int, void *, void *))v9->Read)(
                a1: v9,
                a2: pBuffer,
                a3: 0x10000,
                a4: file,
                a5: a1);
      v11 = v10;
      if ( v10 > 0 )
      {
        v8 -= v10;
        CRC32_ProcessBuffer(pulCRC: crcvalue, pBuffer, nBuffer: v10);
        if ( debug_map_crc.m_pParent != nullptr && debug_map_crc.m_pParent->m_Value.m_nValue != 0 )
          CRC32_ProcessBuffer(&pulCRC, pBuffer, nBuffer: v11);
      }
      a1 = file;
      if ( ((unsigned __int8 (__thiscall *)(IFileSystem *))g_pFileSystem->IsOk)(a1: g_pFileSystem) == 0 )
        break;
      if ( v8 <= 0 )
      {
        if ( debug_map_crc.m_pParent != nullptr && debug_map_crc.m_pParent->m_Value.m_nValue != 0 )
          _Msg(a1: "Lump %d crc %lu\n", v7, pulCRC);
        goto LABEL_38;
      }
    }
    if ( file != nullptr )
      g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: file);
    return 0;
  }
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10149C20
// Name: bool CRC_File(unsigned long __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CRC_File(unsigned int *crcvalue, char *pszFileName)
{
  int v2; // esi
  void *v3; // eax
  int (__thiscall *Read)(IBaseFileSystem *, void *, int, void *); // edx
  int v5; // eax
  bool v6; // zf
  _BYTE pBuffer[65536]; // [esp+8h] [ebp-10004h] BYREF
  void *file; // [esp+10008h] [ebp-4h] BYREF

  CRC32_Init(pulCRC: crcvalue);
  v2 = COM_OpenFile(filename: pszFileName, &file);
  v3 = file;
  if ( file == nullptr || v2 == -1 )
    return 0;
  if ( v2 > 0 )
  {
    while ( 1 )
    {
      Read = g_pFileSystem->Read;
      if ( (unsigned int)v2 <= 0x10000 )
        v5 = ((int (__stdcall *)(_BYTE *, int, void *))Read)(a1: pBuffer, a2: v2, a3: v3);
      else
        v5 = ((int (__stdcall *)(_BYTE *, int, void *))Read)(a1: pBuffer, a2: 0x10000, a3: v3);
      if ( v5 > 0 )
      {
        v2 -= v5;
        CRC32_ProcessBuffer(pulCRC: crcvalue, pBuffer, nBuffer: v5);
      }
      if ( g_pFileSystem->EndOfFile(this: g_pFileSystem, a2: file) )
      {
        g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: file);
        return 1;
      }
      v6 = !g_pFileSystem->IsOk(this: g_pFileSystem, a2: file);
      v3 = file;
      if ( v6 )
        break;
      if ( v2 <= 0 )
        goto LABEL_12;
    }
    if ( file != nullptr )
      g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: file);
    return 0;
  }
LABEL_12:
  if ( v3 != nullptr )
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v3);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10149D30
// Name: int LumpCompare(void const __near *,void const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl LumpCompare(_DWORD *pElem0, _DWORD *pElem1)
{
  return g_pMapHeader->lumps[*pElem0].fileofs - g_pMapHeader->lumps[*pElem1].fileofs;
}

//------------------------------------------------------------------------------
// Address: 0x10149D60
// Name: bool CRC_MapFile(unsigned long __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __usercall CRC_MapFile@<al>(void *a1@<edi>, unsigned int *crcvalue, char *pszFileName)
{
  int v3; // eax
  int i; // eax
  int v6; // eax
  int v7; // ebx
  int v8; // edi
  IBaseFileSystem *v9; // ecx
  int v10; // eax
  int v11; // esi
  _BYTE pBuffer[65536]; // [esp+4h] [ebp-1051Ch] BYREF
  _BYTE v14[4]; // [esp+10004h] [ebp-51Ch] BYREF
  int v15; // [esp+10008h] [ebp-518h]
  _BYTE v16[1028]; // [esp+1000Ch] [ebp-514h]
  _DWORD base[64]; // [esp+10410h] [ebp-110h] BYREF
  unsigned int v18; // [esp+10510h] [ebp-10h]
  int v19; // [esp+10514h] [ebp-Ch]
  unsigned int pulCRC; // [esp+10518h] [ebp-8h] BYREF
  void *file; // [esp+1051Ch] [ebp-4h] BYREF

  v3 = COM_OpenFile(filename: pszFileName, &file);
  if ( file == nullptr || v3 == -1 )
    return 0;
  v18 = g_pFileSystem->Tell(this: &g_pFileSystem->IBaseFileSystem, a2: file);
  if ( g_pFileSystem->Read(this: &g_pFileSystem->IBaseFileSystem, a2: v14, a3: 1036, a4: file) == 0 )
  {
    ConMsg(a1: "Could not read BSP header for map [%s].\n", pszFileName);
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: file);
    return 0;
  }
  if ( (unsigned int)(v15 - 19) > 2 )
  {
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: file);
    ConMsg(a1: "Map [%s] has incorrect BSP version (%i should be %i).\n", pszFileName, v15, 21);
    return 0;
  }
  else
  {
    V_FileBase(in: com_gamedir, out: gamedir_4, maxlen: 260);
    g_pMapHeader = (BSPHeader_t *)v14;
    for ( i = 0; i < 64; ++i )
      base[i] = i;
    qsort(base, num: 0x40u, width: 4u, comp: (int (__cdecl *)(const void *, const void *))LumpCompare);
    v6 = 0;
    v19 = 0;
    while ( 1 )
    {
      v7 = base[v6];
      if ( v7 != 0 )
      {
        CRC32_Init(&pulCRC);
        if ( _V_stricmp(s1: gamedir_4, s2: "infested") != 0
          || v7 != 8
          && v7 != 26
          && v7 != 35
          && v7 != 37
          && v7 != 51
          && v7 != 52
          && v7 != 55
          && v7 != 56
          && v7 != 40
          && v7 != 29
          && v7 != 6
          && v7 != 28 )
        {
          v8 = *(_DWORD *)&v16[16 * v7 + 4];
          if ( v8 > 0 )
            break;
        }
      }
LABEL_38:
      v6 = v19 + 1;
      v19 = v6;
      if ( v6 >= 64 )
      {
        if ( file != nullptr )
          g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: file);
        return 1;
      }
    }
    g_pFileSystem->Seek(
      this: &g_pFileSystem->IBaseFileSystem,
      a2: file,
      a3: v18 + *(_DWORD *)&v16[16 * v7],
      a4: FILESYSTEM_SEEK_HEAD);
    while ( 1 )
    {
      v9 = &g_pFileSystem->IBaseFileSystem;
      if ( (unsigned int)v8 <= 0x10000 )
        v10 = ((int (__thiscall *)(IBaseFileSystem *, _BYTE *, int, void *, void *))v9->Read)(
                a1: v9,
                a2: pBuffer,
                a3: v8,
                a4: file,
                a5: a1);
      else
        v10 = ((int (__thiscall *)(IBaseFileSystem *, _BYTE *, int, void *, void *))v9->Read)(
                a1: v9,
                a2: pBuffer,
                a3: 0x10000,
                a4: file,
                a5: a1);
      v11 = v10;
      if ( v10 > 0 )
      {
        v8 -= v10;
        CRC32_ProcessBuffer(pulCRC: crcvalue, pBuffer, nBuffer: v10);
        if ( debug_map_crc.m_pParent != nullptr && debug_map_crc.m_pParent->m_Value.m_nValue != 0 )
          CRC32_ProcessBuffer(&pulCRC, pBuffer, nBuffer: v11);
      }
      a1 = file;
      if ( ((unsigned __int8 (__thiscall *)(IFileSystem *))g_pFileSystem->IsOk)(a1: g_pFileSystem) == 0 )
        break;
      if ( v8 <= 0 )
      {
        if ( debug_map_crc.m_pParent != nullptr && debug_map_crc.m_pParent->m_Value.m_nValue != 0 )
          _Msg(a1: "Lump %d crc %lu\n", v7, pulCRC);
        goto LABEL_38;
      }
    }
    if ( file != nullptr )
      g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: file);
    return 0;
  }
}

} // namespace engine_xlsp
