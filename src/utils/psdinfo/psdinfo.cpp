// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/psdinfo/psdinfo.cpp
// Functions: 5
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x004010C0
// Name: int Usage(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Usage()
{
  printf(format: "psdinfo ver. Dec 28 2010 16:58:23\n");
  printf(format: "Usage: \n");
  printf(format: "      psdinfo [OPTIONS] psdfile.psd \n");
  printf(format: "Options: \n");
  printf(format: "      -read         read and print the info record (default) \n");
  printf(format: "      -write        update the info record with data from pipe \n");
  printf(format: "psdfile.psd         the PSD file to process. \n");
  printf(format: "\n");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00401120
// Name: bool LoadFileAndClose(struct _iobuf __near *,class CUtlBuffer __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl LoadFileAndClose(_iobuf *fp, CUtlBuffer *buf, int numExtraBytesAlloc)
{
  unsigned int v4; // edi
  int v5; // edi

  if ( fp == nullptr )
    return 0;
  fseek(stream: fp, offset: 0, whence: 2);
  v4 = ftell(stream: fp);
  fseek(stream: fp, offset: 0, whence: 0);
  CUtlBuffer::EnsureCapacity(this: buf, num: v4 + numExtraBytesAlloc);
  v5 = fread(buffer: buf->m_Memory.m_pMemory, elementSize: 1u, count: v4, stream: fp);
  fclose(stream: fp);
  CUtlBuffer::SeekPut(this: buf, type: SEEK_HEAD, offset: v5);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00401190
// Name: int WriteInfo(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl WriteInfo()
{
  _iobuf *v0; // eax
  _iobuf *v1; // eax
  int v2; // kr00_4
  _iobuf *v3; // eax
  _iobuf *v4; // eax
  unsigned __int8 *m_pMemory; // edi
  unsigned __int8 *m_pvData; // eax
  unsigned int m_Put; // edx
  int v8; // ebx
  __int16 v9; // ax
  unsigned __int8 *v10; // esi
  __int16 v11; // ax
  unsigned __int16 v12; // ax
  unsigned int v13; // esi
  unsigned __int8 *v14; // ecx
  __int16 v15; // ax
  _iobuf *v16; // edi
  int v18; // [esp-2h] [ebp-109Ch]
  char string[4096]; // [esp+2h] [ebp-1098h] BYREF
  CUtlBuffer v20; // [esp+1002h] [ebp-98h] BYREF
  CUtlBuffer buf; // [esp+1032h] [ebp-68h] BYREF
  unsigned __int8 src[4]; // [esp+1062h] [ebp-38h] BYREF
  int v23; // [esp+1066h] [ebp-34h]
  PSDImageResources::ResElement v24; // [esp+106Ah] [ebp-30h] BYREF
  PSDResFileInfo::ResFileInfoElement v25; // [esp+1076h] [ebp-24h] BYREF
  unsigned __int8 v26[2]; // [esp+1082h] [ebp-18h] BYREF
  char v27; // [esp+1084h] [ebp-16h]
  PSDResFileInfo v28; // [esp+1086h] [ebp-14h] BYREF
  PSDImageResources v29; // [esp+1092h] [ebp-8h] BYREF

  CUtlBuffer::CUtlBuffer(this: &v20, growSize: 0, initSize: 0, nFlags: 0);
  v0 = __iob_func();
  if ( feof(stream: v0) == 0 )
  {
    do
    {
      v1 = __iob_func();
      if ( fgets(string, count: 4095, str: v1) == nullptr )
        break;
      string[4095] = 0;
      v2 = strlen(string);
      if ( v2 != 0 && string[v2 - 1] == 10 )
        string[v2 - 1] = 13;
      CUtlBuffer::Put(this: &v20, pMem: string, size: v2);
      v3 = __iob_func();
    }
    while ( feof(stream: v3) == 0 );
  }
  if ( v20.m_Put != 0 && v20.m_Memory.m_pMemory[v20.m_Put - 1] == 13 )
    CUtlBuffer::SeekPut(this: &v20, type: SEEK_CURRENT, offset: -1);
  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
  v18 = v20.m_Put + 256;
  v4 = fopen(file: s_opts.szFilename, mode: "rb");
  if ( LoadFileAndClose(fp: v4, &buf, numExtraBytesAlloc: v18) == 0 )
    _Error(a1: "%s cannot be opened for read!\n", s_opts.szFilename);
  m_pMemory = buf.m_Memory.m_pMemory;
  if ( !IsPSDFile(&buf) )
    _Error(a1: "%s is not a valid PSD file!\n", s_opts.szFilename);
  v29 = *PSDGetImageResources(result: (PSDImageResources *)&v24.m_numBytes, &buf);
  if ( v29.m_pvBuffer == nullptr )
    _Error(a1: "%s does not have image resources to write!\n", s_opts.szFilename);
  v28 = (PSDResFileInfo)*PSDImageResources::FindElement(this: &v29, result: &v24, eType: eResFileInfo);
  if ( v28.m_res.m_pvData == nullptr )
  {
    v29.m_numBytes += 20;
    *(_DWORD *)src = 1296646712;
    v23 = 1028;
    v24.m_eType = 117440512;
    *(_DWORD *)&v24.m_numBytes = 540;
    v24.m_pvData = (const unsigned __int8 *)131074;
    *((_DWORD *)v29.m_pvBuffer - 1) = _byteswap_ulong(v29.m_numBytes);
    memmove(
      dst: (unsigned __int8 *)v29.m_pvBuffer + 20,
      src: (unsigned __int8 *)v29.m_pvBuffer,
      count: (unsigned int)&m_pMemory[buf.m_Put - (unsigned int)v29.m_pvBuffer]);
    memmove(dst: (unsigned __int8 *)v29.m_pvBuffer, src, count: 0x14u);
    v28.m_res.m_numBytes = 7;
    v28.m_res.m_eType = eResFileInfo;
    v28.m_res.m_pvData = v29.m_pvBuffer + 12;
    CUtlBuffer::SeekPut(this: &buf, type: SEEK_CURRENT, offset: 20);
  }
  PSDResFileInfo::FindElement(this: &v28, result: &v25, eType: eDescription);
  m_pvData = (unsigned __int8 *)v25.m_pvData;
  if ( v25.m_pvData != nullptr )
  {
    m_Put = v20.m_Put;
    v8 = v20.m_Put - v25.m_numBytes;
    if ( v20.m_Put != v25.m_numBytes )
    {
      memmove(
        dst: (unsigned __int8 *)&v25.m_pvData[v20.m_Put],
        src: (unsigned __int8 *)&v25.m_pvData[v25.m_numBytes],
        count: (unsigned int)&m_pMemory[buf.m_Put - v25.m_numBytes - (unsigned int)v25.m_pvData]);
      m_Put = v20.m_Put;
      m_pvData = (unsigned __int8 *)v25.m_pvData;
    }
    memmove(dst: m_pvData, src: v20.m_Memory.m_pMemory, count: m_Put);
    v25.m_numBytes += v8;
    LOBYTE(v9) = HIBYTE(v25.m_numBytes);
    HIBYTE(v9) = v25.m_numBytes;
    *((_WORD *)v25.m_pvData - 1) = v9;
  }
  else
  {
    v10 = (unsigned __int8 *)&v28.m_res.m_pvData[v28.m_res.m_numBytes];
    v8 = v20.m_Put + 5;
    memmove(dst: &v10[v20.m_Put + 5], src: v10, count: (unsigned int)&m_pMemory[buf.m_Put - (_DWORD)v10]);
    *(_WORD *)v26 = 540;
    v27 = 120;
    memmove(dst: v10, src: v26, count: 3u);
    v24.m_pvData = (const unsigned __int8 *)LOWORD(v20.m_Put);
    LOBYTE(v11) = BYTE1(v20.m_Put);
    HIBYTE(v11) = v20.m_Put;
    *(_WORD *)(v10 + 3) = v11;
    memmove(dst: v10 + 5, src: v20.m_Memory.m_pMemory, count: v20.m_Put);
  }
  CUtlBuffer::SeekPut(this: &buf, type: SEEK_CURRENT, offset: v8);
  v12 = v8 + v28.m_res.m_numBytes;
  v28.m_res.m_numBytes += v8;
  if ( (v8 & 1) != 0 )
  {
    v13 = buf.m_Put - v12 - (unsigned int)v28.m_res.m_pvData;
    v14 = (unsigned __int8 *)&v28.m_res.m_pvData[v12];
    if ( (v28.m_res.m_numBytes & 1) != 0 )
    {
      ++v8;
      memmove(dst: v14 + 1, src: (unsigned __int8 *)&v28.m_res.m_pvData[v12], count: (unsigned int)&m_pMemory[v13]);
      v28.m_res.m_pvData[v28.m_res.m_numBytes] = 0;
      CUtlBuffer::SeekPut(this: &buf, type: SEEK_CURRENT, offset: 1);
    }
    else
    {
      --v8;
      memmove(dst: v14, src: v14 + 1, count: (unsigned int)&m_pMemory[v13 - 1]);
      CUtlBuffer::SeekPut(this: &buf, type: SEEK_CURRENT, offset: -1);
    }
  }
  LOBYTE(v15) = HIBYTE(v28.m_res.m_numBytes);
  HIBYTE(v15) = v28.m_res.m_numBytes;
  *((_WORD *)v28.m_res.m_pvData - 1) = v15;
  v29.m_numBytes += v8;
  *((_DWORD *)v29.m_pvBuffer - 1) = _byteswap_ulong(v29.m_numBytes);
  v16 = fopen(file: s_opts.szFilename, mode: "wb");
  if ( v16 == nullptr )
    _Error(a1: "%s cannot be opened for update!\n", s_opts.szFilename);
  fwrite(buffer: buf.m_Memory.m_pMemory, size: 1u, count: buf.m_Put, stream: v16);
  fclose(stream: v16);
  if ( buf.m_Memory.m_nGrowSize >= 0 )
  {
    if ( buf.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
      buf.m_Memory.m_pMemory = nullptr;
    }
    buf.m_Memory.m_nAllocationCount = 0;
  }
  if ( v20.m_Memory.m_nGrowSize >= 0 && v20.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v20.m_Memory.m_pMemory);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004015A0
// Name: int ReadInfo(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ReadInfo()
{
  _iobuf *v0; // eax
  const unsigned __int8 *m_pvData; // esi
  const unsigned __int8 *v2; // ebx
  int v3; // eax
  int v4; // edi
  int v5; // eax
  CUtlBuffer bufFile; // [esp+4h] [ebp-5Ch] BYREF
  PSDImageResources::ResElement v8; // [esp+34h] [ebp-2Ch] BYREF
  PSDResFileInfo::ResFileInfoElement descr; // [esp+40h] [ebp-20h] BYREF
  PSDResFileInfo resFileInfo; // [esp+4Ch] [ebp-14h] BYREF
  PSDImageResources imgres; // [esp+58h] [ebp-8h] BYREF

  CUtlBuffer::CUtlBuffer(this: &bufFile, growSize: 0, initSize: 0, nFlags: 0);
  v0 = fopen(file: s_opts.szFilename, mode: "rb");
  if ( LoadFileAndClose(fp: v0, buf: &bufFile, numExtraBytesAlloc: 0) == 0 )
    _Error(a1: "%s cannot be opened for read!\n", s_opts.szFilename);
  if ( !IsPSDFile(buf: &bufFile) )
    _Error(a1: "%s is not a valid PSD file!\n", s_opts.szFilename);
  PSDGetImageResources(result: &imgres, buf: &bufFile);
  resFileInfo = (PSDResFileInfo)*PSDImageResources::FindElement(this: &imgres, result: &v8, eType: eResFileInfo);
  PSDResFileInfo::FindElement(this: &resFileInfo, result: &descr, eType: eDescription);
  m_pvData = descr.m_pvData;
  if ( descr.m_pvData != nullptr )
  {
    v2 = &descr.m_pvData[descr.m_numBytes];
    memchr(buf: (unsigned __int8 *)descr.m_pvData, chr: 0xDu, cnt: descr.m_numBytes);
    v4 = v3;
    if ( v3 != 0 )
    {
      do
      {
        printf(format: "%.*s\n", v4 - (_DWORD)m_pvData, (const char *)m_pvData);
        m_pvData = (const unsigned __int8 *)(v4 + 1);
        memchr(buf: (unsigned __int8 *)(v4 + 1), chr: 0xDu, cnt: (unsigned int)&v2[-v4 - 1]);
        v4 = v5;
      }
      while ( v5 != 0 );
    }
    if ( v2 > m_pvData )
      printf(format: "%.*s\n", v2 - m_pvData, (const char *)m_pvData);
  }
  if ( bufFile.m_Memory.m_nGrowSize >= 0 && bufFile.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bufFile.m_Memory.m_pMemory);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004016E0
// Name: _main
// Source: json
//------------------------------------------------------------------------------
int __cdecl main(int argc, const char **argv, const char **envp)
{
  int v4; // esi

  if ( argc <= 1 )
    return Usage();
  v4 = 1;
  for ( s_opts.szFilename = argv[argc - 1]; v4 < argc - 1; ++v4 )
  {
    if ( _V_stricmp(s1: argv[v4], s2: "-read") != 0 )
    {
      if ( _V_stricmp(s1: argv[v4], s2: "-write") != 0 )
      {
        printf(format: "Unknown option \"%s\"!\n", argv[v4]);
        return Usage();
      }
      s_opts.bWriteInfo = true;
    }
    else
    {
      s_opts.bWriteInfo = false;
    }
  }
  if ( s_opts.bWriteInfo )
    return WriteInfo();
  else
    return ReadInfo();
}
