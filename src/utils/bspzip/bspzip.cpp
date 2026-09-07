// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/bspzip/bspzip.cpp
// Functions: 3
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0040A3E0
// Name: void StripPath(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl StripPath(const char *pPath, char *pBuf, int nBufLen)
{
  const char *i; // ecx
  char v4; // al

  for ( i = &pPath[_V_strlen(str: pPath) - 1]; i != pPath; --i )
  {
    v4 = *(i - 1);
    if ( v4 == 92 )
      break;
    if ( v4 == 47 )
      break;
    if ( v4 == 58 )
      break;
  }
  V_strncpy(pDest: pBuf, pSrc: i, maxLen: nBufLen);
}

//------------------------------------------------------------------------------
// Address: 0x0040A420
// Name: void Usage(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __noreturn Usage()
{
  _iobuf *v0; // eax
  _iobuf *v1; // eax
  _iobuf *v2; // eax
  _iobuf *v3; // eax
  _iobuf *v4; // eax
  _iobuf *v5; // eax
  _iobuf *v6; // eax
  _iobuf *v7; // eax
  _iobuf *v8; // eax
  _iobuf *v9; // eax
  _iobuf *v10; // eax
  _iobuf *v11; // eax
  _iobuf *v12; // eax

  v0 = __iob_func();
  fprintf(str: v0 + 2, format: "usage: \n");
  v1 = __iob_func();
  fprintf(str: v1 + 2, format: "bspzip -extract <bspfile> <blah.zip>\n");
  v2 = __iob_func();
  fprintf(str: v2 + 2, format: "bspzip -extractfiles <bspfile>\n");
  v3 = __iob_func();
  fprintf(str: v3 + 2, format: "bspzip -dir <bspfile>\n");
  v4 = __iob_func();
  fprintf(str: v4 + 2, format: "bspzip -addfile <bspfile> <relativepathname> <fullpathname> <newbspfile>\n");
  v5 = __iob_func();
  fprintf(str: v5 + 2, format: "bspzip -addlist <bspfile> <listfile> <newbspfile>\n");
  v6 = __iob_func();
  fprintf(str: v6 + 2, format: "bspzip -addorupdatelist <bspfile> <listfile> <newbspfile>\n");
  v7 = __iob_func();
  fprintf(str: v7 + 2, format: "bspzip -extractcubemaps <bspfile> <targetPath>\n");
  v8 = __iob_func();
  fprintf(str: v8 + 2, format: "  Extracts the cubemaps to <targetPath>.\n");
  v9 = __iob_func();
  fprintf(str: v9 + 2, format: "bspzip -deletecubemaps <bspfile>\n");
  v10 = __iob_func();
  fprintf(str: v10 + 2, format: "  Deletes the cubemaps from <bspFile>.\n");
  v11 = __iob_func();
  fprintf(str: v11 + 2, format: "bspzip -addfiles <bspfile> <relativePathPrefix> <listfile> <newbspfile>\n");
  v12 = __iob_func();
  fprintf(str: v12 + 2, format: "  Adds files to <newbspfile>.\n");
  exit(code: -1);
}

//------------------------------------------------------------------------------
// Address: 0x0040A550
// Name: _main
// Source: json
//------------------------------------------------------------------------------
int __cdecl main(int argc, const char **argv, const char **envp)
{
  int v3; // ebx
  int v4; // edi
  void (__thiscall ***v5)(_DWORD, int, const char **); // eax
  const char **v6; // esi
  const char *v7; // esi
  char *v8; // ecx
  char v9; // al
  const char *v11; // esi
  char *v12; // ecx
  char v13; // al
  IZip *PakFile; // eax
  int i; // ebx
  IZip *v16; // eax
  int v17; // eax
  char v18; // cl
  unsigned int v19; // eax
  char *v20; // edi
  char v21; // cl
  _iobuf *v22; // eax
  _iobuf *v23; // esi
  IZip *v24; // eax
  const char *v25; // esi
  char *v26; // ecx
  char v27; // al
  IZip *v28; // eax
  int j; // ebx
  IZip *v30; // eax
  int v31; // eax
  char v32; // cl
  unsigned int v33; // eax
  char *v34; // edi
  char v35; // cl
  _iobuf *v36; // esi
  IZip *v37; // eax
  int v38; // edi
  IZip *v39; // eax
  int k; // esi
  IZip *v41; // eax
  IZip *v42; // eax
  const char *v43; // eax
  char *v44; // edx
  char v45; // cl
  const char *v46; // eax
  char *v47; // edx
  char v48; // cl
  _iobuf *v49; // esi
  IZip *v50; // eax
  char *v51; // eax
  char *v52; // edx
  char v53; // cl
  char *v54; // eax
  char *v55; // edx
  char v56; // cl
  IZip *v57; // eax
  char *v58; // eax
  char *v59; // edx
  char v60; // cl
  _iobuf *v61; // edi
  int v62; // kr04_4
  int v63; // kr08_4
  IZip *v64; // eax
  char *v65; // eax
  char *v66; // edx
  char v67; // cl
  int v68; // kr0C_4
  int v69; // kr10_4
  IZip *v70; // eax
  const char *v71; // eax
  IZip *v72; // eax
  IZip *v73; // eax
  char file[1024]; // [esp+34h] [ebp-1C34h] BYREF
  char src[1024]; // [esp+434h] [ebp-1834h] BYREF
  char pBuf[1024]; // [esp+834h] [ebp-1434h] BYREF
  char path[1024]; // [esp+C34h] [ebp-1034h] BYREF
  char pOut[1023]; // [esp+1034h] [ebp-C34h] BYREF
  char v79; // [esp+1433h] [ebp-835h] BYREF
  char pname[1024]; // [esp+1434h] [ebp-834h] BYREF
  char filename[1024]; // [esp+1834h] [ebp-434h] BYREF
  CUtlBuffer buf; // [esp+1C34h] [ebp-34h] BYREF
  int v83; // [esp+1C64h] [ebp-4h]

  SetHDRMode(bHDR: false);
  _Msg(a1: "\nValve Software - bspzip.exe (%s)\n", "Dec 28 2010");
  v4 = argc;
  if ( argc < 2 )
LABEL_2:
    Usage();
  v5 = (void (__thiscall ***)(_DWORD, int, const char **))_CommandLine();
  v6 = argv;
  (**v5)(a1: v5, a2: v4, a3: argv);
  CmdLib_InitFileSystem(pFilename: v6[2], maxMemoryUsage: 0);
  MathLib_Init(
    gamma: 2.2,
    texGamma: 2.2,
    brightness: 0.0,
    overbright: 2,
    bAllow3DNow: true,
    bAllowSSE: true,
    bAllowSSE2: true,
    bAllowMMX: true);
  if ( _V_stricmp(s1: v6[1], s2: "-extract") == 0 && v4 >= 4 )
  {
    V_MakeAbsolutePath(pOut, outLen: 1024, pPath: v6[2], pStartingDir: nullptr);
    V_DefaultExtension(path: pOut, extension: ".bsp", pathStringLength: 1024);
    v7 = v6[3];
    v8 = (char *)(path - v7);
    do
    {
      v9 = *v7;
      v7[(_DWORD)v8] = *v7;
      ++v7;
    }
    while ( v9 != 0 );
    V_DefaultExtension(path, extension: ".zip", pathStringLength: 1024);
    ExtractZipFileFromBSP(pBSPFileName: pOut, pZipFileName: path);
    return 0;
  }
  if ( _V_stricmp(s1: v6[1], s2: "-extractfiles") == 0 && v4 >= 4 )
  {
    V_MakeAbsolutePath(pOut: filename, outLen: 1024, pPath: v6[2], pStartingDir: nullptr);
    V_DefaultExtension(path: filename, extension: ".bsp", pathStringLength: 1024);
    v11 = v6[3];
    v12 = (char *)(path - v11);
    do
    {
      v13 = *v11;
      v11[(_DWORD)v12] = *v11;
      ++v11;
    }
    while ( v13 != 0 );
    V_AppendSlash(pStr: path, strSize: 1024);
    printf(format: "\n");
    printf(format: "Opening bsp file: %s\n", filename);
    LoadBSPFile(filename);
    CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
    v83 = 0;
    PakFile = GetPakFile();
    for ( i = GetNextFilename(pak: PakFile, id: -1, pBuffer: pOut, bufferSize: 1024, fileSize: &argc);
          i != -1;
          i = GetNextFilename(pak: v24, id: i, pBuffer: pOut, bufferSize: 1024, fileSize: &argc) )
    {
      CUtlBuffer::EnsureCapacity(this: &buf, num: argc);
      CUtlBuffer::SeekPut(this: &buf, type: SEEK_HEAD, offset: 0);
      v16 = GetPakFile();
      ReadFileFromPak(pak: v16, pRelativeName: pOut, bTextMode: false, &buf);
      v17 = 0;
      do
      {
        v18 = path[v17];
        pname[v17++] = v18;
      }
      while ( v18 != 0 );
      v19 = strlen(pOut) + 1;
      v20 = &v79;
      do
        v21 = *++v20;
      while ( v21 != 0 );
      qmemcpy(v20, pOut, v19);
      V_FixSlashes(pname, separator: 92);
      SafeCreatePath(path: pname);
      printf(format: "Writing file: %s\n", pname);
      v22 = fopen(file: pname, mode: "wb");
      v23 = v22;
      if ( v22 == nullptr )
      {
        printf(format: "Error: Could not write %s\n", pname);
        exit(code: -1);
      }
      fwrite(buffer: buf.m_Memory.m_pMemory, size: argc, count: 1u, stream: v22);
      fclose(stream: v23);
      ++v83;
      v24 = GetPakFile();
    }
    printf(format: "%d files extracted.\n", v83);
LABEL_35:
    CUtlBuffer::~CUtlBuffer(this: &buf);
    return 0;
  }
  if ( _V_stricmp(s1: v6[1], s2: "-extractcubemaps") == 0 && v4 >= 4 )
  {
    V_MakeAbsolutePath(pOut, outLen: 1024, pPath: v6[2], pStartingDir: nullptr);
    V_DefaultExtension(path: pOut, extension: ".bsp", pathStringLength: 1024);
    v25 = v6[3];
    v26 = (char *)(path - v25);
    do
    {
      v27 = *v25;
      v25[(_DWORD)v26] = *v25;
      ++v25;
    }
    while ( v27 != 0 );
    V_AppendSlash(pStr: path, strSize: 1024);
    printf(format: "\n");
    printf(format: "Opening bsp file: %s\n", pOut);
    LoadBSPFile(filename: pOut);
    CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
    v83 = 0;
    v28 = GetPakFile();
    for ( j = GetNextFilename(pak: v28, id: -1, pBuffer: filename, bufferSize: 1024, fileSize: &argc);
          j != -1;
          j = GetNextFilename(pak: v37, id: j, pBuffer: filename, bufferSize: 1024, fileSize: &argc) )
    {
      if ( V_stristr(pStr: filename, pSearch: ".vtf") != nullptr )
      {
        CUtlBuffer::EnsureCapacity(this: &buf, num: argc);
        CUtlBuffer::SeekPut(this: &buf, type: SEEK_HEAD, offset: 0);
        v30 = GetPakFile();
        ReadFileFromPak(pak: v30, pRelativeName: filename, bTextMode: false, &buf);
        v31 = 0;
        do
        {
          v32 = path[v31];
          pname[v31++] = v32;
        }
        while ( v32 != 0 );
        v33 = strlen(filename) + 1;
        v34 = &v79;
        do
          v35 = *++v34;
        while ( v35 != 0 );
        qmemcpy(v34, filename, v33);
        V_FixSlashes(pname, separator: 92);
        SafeCreatePath(path: pname);
        printf(format: "Writing vtf file: %s\n", pname);
        v36 = fopen(file: pname, mode: "wb");
        if ( v36 == nullptr )
        {
          printf(format: "Error: Could not write %s\n", pname);
          exit(code: -1);
        }
        fwrite(buffer: buf.m_Memory.m_pMemory, size: argc, count: 1u, stream: v36);
        fclose(stream: v36);
        ++v83;
      }
      v37 = GetPakFile();
    }
    printf(format: "%d cubemaps extracted.\n", v83);
    goto LABEL_35;
  }
  if ( _V_stricmp(s1: v6[1], s2: "-deletecubemaps") != 0 || v4 < 3 )
  {
    if ( _V_stricmp(s1: v6[1], s2: "-addfiles") == 0 && v4 >= 6 )
    {
      V_MakeAbsolutePath(pOut, outLen: 1024, pPath: v6[2], pStartingDir: nullptr);
      V_DefaultExtension(path: pOut, extension: ".bsp", pathStringLength: 1024);
      v43 = v6[3];
      v44 = (char *)(src - v43);
      do
      {
        v45 = *v43;
        v43[(_DWORD)v44] = *v43;
        ++v43;
      }
      while ( v45 != 0 );
      v46 = v6[4];
      v47 = (char *)(file - v46);
      do
      {
        v48 = *v46;
        v46[(_DWORD)v47] = *v46;
        ++v46;
      }
      while ( v48 != 0 );
      V_MakeAbsolutePath(pOut: path, outLen: 1024, pPath: v6[5], pStartingDir: nullptr);
      V_DefaultExtension(path, extension: ".bsp", pathStringLength: 1024);
      v49 = fopen(file, mode: "r");
      if ( v49 != nullptr )
      {
        printf(format: "Opening bsp file: %s\n", pOut);
        LoadBSPFile(filename: pOut);
        if ( feof(stream: v49) != 0 )
        {
LABEL_58:
          printf(format: "Writing new bsp file: %s\n", path);
          WriteBSPFile(a1: v3, filename: path);
          fclose(stream: v49);
          return 0;
        }
        while ( 1 )
        {
          if ( fgets(string: filename, count: 1024, str: v49) != nullptr )
          {
            pname[strlen(filename) + 1023] = 0;
            StripPath(pPath: filename, pBuf, nBufLen: 1024);
            _V_strcpy(dest: pname, src);
            V_strncat(pDest: pname, pSrc: pBuf, destBufferSize: 0x400u, max_chars_to_copy: -1);
            printf(format: "Adding file: %s as %s\n", filename, pname);
            v50 = GetPakFile();
            AddFileToPak(pak: v50, relativename: pname, fullpath: filename);
          }
          else if ( feof(stream: v49) == 0 )
          {
            printf(format: "Error: Missing full path names\n");
            fclose(stream: v49);
            return -1;
          }
          if ( feof(stream: v49) != 0 )
            goto LABEL_58;
        }
      }
      return 0;
    }
    if ( _V_stricmp(s1: v6[1], s2: "-dir") == 0 && v4 >= 3 )
    {
      V_MakeAbsolutePath(pOut: path, outLen: 1024, pPath: v6[2], pStartingDir: nullptr);
      V_DefaultExtension(path, extension: ".bsp", pathStringLength: 1024);
      LoadBSPFile(filename: path);
      PrintBSPPackDirectory();
      return 0;
    }
    if ( _V_stricmp(s1: v6[1], s2: "-addfile") == 0 && v4 >= 6 )
    {
      V_MakeAbsolutePath(pOut: path, outLen: 1024, pPath: v6[2], pStartingDir: nullptr);
      V_DefaultExtension(path, extension: ".bsp", pathStringLength: 1024);
      v51 = (char *)v6[3];
      v52 = (char *)(src - v51);
      do
      {
        v53 = *v51;
        v52[(_DWORD)v51] = *v51;
        ++v51;
      }
      while ( v53 != 0 );
      v54 = (char *)v6[4];
      v55 = (char *)(pBuf - v54);
      do
      {
        v56 = *v54;
        v55[(_DWORD)v54] = *v54;
        ++v54;
      }
      while ( v56 != 0 );
      V_MakeAbsolutePath(pOut, outLen: 1024, pPath: v6[5], pStartingDir: nullptr);
      V_DefaultExtension(path: pOut, extension: ".bsp", pathStringLength: 1024);
      LoadBSPFile(filename: path);
      v57 = GetPakFile();
      AddFileToPak(pak: v57, relativename: src, fullpath: pBuf);
      WriteBSPFile(a1: v3, filename: pOut);
      return 0;
    }
    if ( _V_stricmp(s1: v6[1], s2: "-addlist") != 0 || v4 < 5 )
    {
      if ( _V_stricmp(s1: v6[1], s2: "-addorupdatelist") != 0 || v4 < 5 )
        goto LABEL_2;
      V_MakeAbsolutePath(pOut: path, outLen: 1024, pPath: v6[2], pStartingDir: nullptr);
      V_DefaultExtension(path, extension: ".bsp", pathStringLength: 1024);
      v65 = (char *)v6[3];
      v66 = (char *)(pBuf - v65);
      do
      {
        v67 = *v65;
        v66[(_DWORD)v65] = *v65;
        ++v65;
      }
      while ( v67 != 0 );
      V_MakeAbsolutePath(pOut, outLen: 1024, pPath: v6[4], pStartingDir: nullptr);
      V_DefaultExtension(path: pOut, extension: ".bsp", pathStringLength: 1024);
      v61 = fopen(file: pBuf, mode: "r");
      if ( v61 == nullptr )
        return 0;
      printf(format: "Opening bsp file: %s\n", path);
      LoadBSPFile(filename: path);
      while ( feof(stream: v61) == 0 )
      {
        pname[0] = 0;
        filename[0] = 0;
        if ( fgets(string: pname, count: 1024, str: v61) != nullptr
          && fgets(string: filename, count: 1024, str: v61) != nullptr )
        {
          v68 = strlen(pname);
          v69 = strlen(filename);
          if ( v68 > 0 && pname[v68 - 1] == 10 )
            pname[v68 - 1] = 0;
          if ( v69 > 0 && pname[v69 + 1023] == 10 )
            pname[v69 + 1023] = 0;
          v70 = GetPakFile();
          LOBYTE(v3) = FileExistsInPak(pak: v70, pRelativeName: pname);
          v71 = "Updating";
          if ( (_BYTE)v3 == 0 )
            v71 = "Adding";
          printf(format: "%s file: %s\n", v71, filename);
          if ( (_BYTE)v3 != 0 )
          {
            v72 = GetPakFile();
            RemoveFileFromPak(pak: v72, relativename: pname);
          }
          v73 = GetPakFile();
          AddFileToPak(pak: v73, relativename: pname, fullpath: filename);
        }
        else if ( feof(stream: v61) == 0 || pname[0] != 0 && filename[0] == 0 )
        {
LABEL_90:
          printf(format: "Error: Missing paired relative/full path names\n");
          fclose(stream: v61);
          return -1;
        }
      }
    }
    else
    {
      V_MakeAbsolutePath(pOut: path, outLen: 1024, pPath: v6[2], pStartingDir: nullptr);
      V_DefaultExtension(path, extension: ".bsp", pathStringLength: 1024);
      v58 = (char *)v6[3];
      v59 = (char *)(pBuf - v58);
      do
      {
        v60 = *v58;
        v59[(_DWORD)v58] = *v58;
        ++v58;
      }
      while ( v60 != 0 );
      V_MakeAbsolutePath(pOut, outLen: 1024, pPath: v6[4], pStartingDir: nullptr);
      V_DefaultExtension(path: pOut, extension: ".bsp", pathStringLength: 1024);
      v61 = fopen(file: pBuf, mode: "r");
      if ( v61 == nullptr )
        return 0;
      printf(format: "Opening bsp file: %s\n", path);
      LoadBSPFile(filename: path);
      while ( feof(stream: v61) == 0 )
      {
        filename[0] = 0;
        pname[0] = 0;
        if ( fgets(string: filename, count: 1024, str: v61) != nullptr
          && fgets(string: pname, count: 1024, str: v61) != nullptr )
        {
          v62 = strlen(filename);
          v63 = strlen(pname);
          if ( v62 > 0 && pname[v62 + 1023] == 10 )
            pname[v62 + 1023] = 0;
          if ( v63 > 0 && pname[v63 - 1] == 10 )
            pname[v63 - 1] = 0;
          printf(format: "Adding file: %s\n", pname);
          v64 = GetPakFile();
          AddFileToPak(pak: v64, relativename: filename, fullpath: pname);
        }
        else if ( feof(stream: v61) == 0 || filename[0] != 0 && pname[0] == 0 )
        {
          goto LABEL_90;
        }
      }
    }
    printf(format: "Writing new bsp file: %s\n", pOut);
    WriteBSPFile(a1: v3, filename: pOut);
    fclose(stream: v61);
    return 0;
  }
  V_MakeAbsolutePath(pOut: filename, outLen: 1024, pPath: v6[2], pStartingDir: nullptr);
  V_DefaultExtension(path: filename, extension: ".bsp", pathStringLength: 1024);
  printf(format: "\n");
  printf(format: "Opening bsp file: %s\n", filename);
  LoadBSPFile(filename);
  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
  v38 = 0;
  v39 = GetPakFile();
  for ( k = GetNextFilename(pak: v39, id: -1, pBuffer: pOut, bufferSize: 1024, fileSize: &argc);
        k != -1;
        k = GetNextFilename(pak: v42, id: k, pBuffer: pOut, bufferSize: 1024, fileSize: &argc) )
  {
    if ( V_stristr(pStr: pOut, pSearch: ".vtf") != nullptr )
    {
      v41 = GetPakFile();
      RemoveFileFromPak(pak: v41, relativename: pOut);
      ++v38;
      k = -1;
    }
    v42 = GetPakFile();
  }
  printf(format: "%d cubemaps deleted.\n", v38);
  if ( v38 != 0 )
  {
    printf(format: "Updating bsp file: %s\n", filename);
    WriteBSPFile(a1: v3, filename);
  }
  CUtlBuffer::~CUtlBuffer(this: &buf);
  return 0;
}
