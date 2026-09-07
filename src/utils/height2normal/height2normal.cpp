// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/height2normal/height2normal.cpp
// Functions: 5
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00401000
// Name: GetKeyValueFromBuffer
// Source: json
//------------------------------------------------------------------------------
char __usercall GetKeyValueFromBuffer@<al>(CUtlBuffer *buf@<esi>, char **key@<edi>, char **val)
{
  char v3; // cl
  char *v4; // eax
  char *v5; // eax
  bool v6; // zf
  char v7; // cl
  char *v8; // eax
  char *v9; // eax
  char stringBuf[2048]; // [esp+4h] [ebp-800h] BYREF

  if ( buf->m_Error != 0 )
    return 0;
  while ( 1 )
  {
    CUtlBuffer::GetLine(this: buf, pLine: stringBuf, nMaxChars: 2048);
    v3 = stringBuf[0];
    v4 = stringBuf;
    if ( stringBuf[0] != 34 )
    {
      while ( v3 != 35 && v3 != 0 )
      {
        v3 = *++v4;
        if ( v3 == 34 )
          goto LABEL_6;
      }
      goto next_line;
    }
LABEL_6:
    v5 = v4 + 1;
    v6 = *v5 == 34;
    *key = v5;
    if ( !v6 )
    {
      while ( *v5 != 0 )
      {
        if ( *++v5 == 34 )
          goto LABEL_9;
      }
      goto next_line;
    }
LABEL_9:
    *v5 = 0;
    v7 = v5[1];
    v8 = v5 + 1;
    if ( v7 == 34 )
      break;
    while ( v7 != 35 && v7 != 0 )
    {
      v7 = *++v8;
      if ( v7 == 34 )
        goto LABEL_13;
    }
next_line:
    if ( buf->m_Error != 0 )
      return 0;
  }
LABEL_13:
  v9 = v8 + 1;
  *val = v9;
  while ( *v9 != 34 )
  {
    if ( *v9 == 0 )
      goto next_line;
    ++v9;
  }
  *v9 = 0;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004010C0
// Name: Usage
// Source: json
//------------------------------------------------------------------------------
void __noreturn Usage()
{
  _iobuf *v0; // eax
  _iobuf *v1; // eax
  _iobuf *v2; // eax

  v0 = __iob_func();
  fprintf(str: v0 + 2, format: "Usage: height2normal [-nopause] [-quiet] tex1_normal.txt tex2_normal.txt . . .\n");
  v1 = __iob_func();
  fprintf(str: v1 + 2, format: "-quiet   : don't print anything out, don't pause for input\n");
  v2 = __iob_func();
  fprintf(str: v2 + 2, format: "-nopause : don't pause for input\n");
  if ( !g_NoPause )
  {
    printf(format: "Hit a key to continue\n");
    getch();
  }
  exit(code: -1);
}

//------------------------------------------------------------------------------
// Address: 0x00401130
// Name: void ProcessFiles(char const __near *,int,int,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ProcessFiles(const char *pNormalFileNameWithoutExtension, int startFrame, int endFrame, float bumpScale)
{
  char v5; // bl
  int v6; // edi
  const char *v7; // esi
  unsigned int MemRequired; // eax
  unsigned __int8 *v9; // ebx
  unsigned int v10; // eax
  unsigned __int8 *v11; // esi
  int v12; // ecx
  _BYTE *v13; // edx
  unsigned int v14; // eax
  unsigned __int8 *v15; // edi
  _iobuf *v16; // eax
  _iobuf *v17; // eax
  unsigned __int8 *m_pMemory; // eax
  bool v19; // zf
  _iobuf *v20; // eax
  const char *targetGamma; // [esp+18h] [ebp-8Ch]
  CUtlBuffer normalBuf; // [esp+2Ch] [ebp-78h] BYREF
  CUtlBuffer buf; // [esp+5Ch] [ebp-48h] BYREF
  ImageFormat imageFormat; // [esp+8Ch] [ebp-18h] BYREF
  int numFrames; // [esp+90h] [ebp-14h]
  float sourceGamma; // [esp+94h] [ebp-10h] BYREF
  int frameID; // [esp+98h] [ebp-Ch]
  int i; // [esp+9Ch] [ebp-8h]
  int width; // [esp+A0h] [ebp-4h] BYREF
  char animated_3; // [esp+B3h] [ebp+Fh]

  if ( startFrame == -1 || endFrame == -1 )
  {
    animated_3 = 0;
    v5 = 0;
  }
  else
  {
    v5 = 1;
    animated_3 = 1;
  }
  numFrames = endFrame - startFrame + 1;
  frameID = 0;
  if ( numFrames <= 0 )
    return;
  v6 = startFrame;
  for ( i = startFrame; ; v6 = i )
  {
    if ( v5 != 0 )
    {
      v7 = pNormalFileNameWithoutExtension;
      sprintf(string: normalTGAFileName, format: "%s%03d.tga", pNormalFileNameWithoutExtension, v6);
    }
    else
    {
      sprintf(string: normalTGAFileName, format: "%s.tga", pNormalFileNameWithoutExtension);
      v7 = pNormalFileNameWithoutExtension;
    }
    if ( V_stristr(pStr: v7, pSearch: "_normal") == nullptr )
    {
      v16 = __iob_func();
      fprintf(str: v16 + 2, format: "ERROR: config file name must end in _normal.txt\n");
      return;
    }
    strcpy(::buf, v7);
    *V_stristr(pStr: ::buf, pSearch: "_normal") = 0;
    if ( v5 != 0 )
      sprintf(string: heightTGAFileName, format: "%s_height%03d.tga", ::buf, v6);
    else
      sprintf(string: heightTGAFileName, format: "%s_height.tga", ::buf);
    CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
    if ( !g_pFullFileSystem->ReadFile(
            this: &g_pFullFileSystem->IBaseFileSystem,
            a2: heightTGAFileName,
            a3: nullptr,
            a4: &buf,
            a5: 0,
            a6: 0,
            a7: nullptr) )
    {
      targetGamma = "%s not found\n";
LABEL_35:
      v17 = __iob_func();
      fprintf(str: v17 + 2, format: targetGamma, heightTGAFileName);
      if ( buf.m_Memory.m_nGrowSize < 0 )
        return;
      m_pMemory = buf.m_Memory.m_pMemory;
      v19 = buf.m_Memory.m_pMemory == nullptr;
      goto LABEL_44;
    }
    if ( !TGALoader::GetInfo(&buf, &width, height: &endFrame, &imageFormat, &sourceGamma) )
    {
      targetGamma = "error in %s\n";
      goto LABEL_35;
    }
    MemRequired = ImageLoader::GetMemRequired(
                    width,
                    height: endFrame,
                    depth: 1,
                    imageFormat: IMAGE_FORMAT_IA88,
                    mipmap: false,
                    pAdjustedHeight: nullptr);
    v9 = (unsigned __int8 *)operator new(size: MemRequired);
    CUtlBuffer::SeekGet(this: &buf, type: SEEK_HEAD, offset: 0);
    TGALoader::Load(
      pOutputImage: v9,
      &buf,
      width,
      height: endFrame,
      imageFormat: IMAGE_FORMAT_IA88,
      targetGamma: sourceGamma,
      mipmap: false);
    v10 = ImageLoader::GetMemRequired(
            width,
            height: endFrame,
            depth: 1,
            imageFormat: IMAGE_FORMAT_RGBA8888,
            mipmap: false,
            pAdjustedHeight: nullptr);
    v11 = (unsigned __int8 *)operator new(size: v10);
    ImageLoader::ConvertIA88ImageToNormalMapRGBA8888(src: v9, width, height: endFrame, dst: v11, bumpScale);
    CUtlBuffer::CUtlBuffer(this: &normalBuf, growSize: 0, initSize: 0, nFlags: 0);
    ImageLoader::NormalizeNormalMapRGBA8888(src: v11, numTexels: endFrame * width);
    v12 = 0;
    if ( endFrame * width <= 0 )
    {
LABEL_21:
      v14 = ImageLoader::GetMemRequired(
              width,
              height: endFrame,
              depth: 1,
              imageFormat: IMAGE_FORMAT_RGB888,
              mipmap: false,
              pAdjustedHeight: nullptr);
      v15 = (unsigned __int8 *)operator new(size: v14);
      ImageLoader::ConvertImageFormat(
        src: v11,
        srcImageFormat: IMAGE_FORMAT_RGBA8888,
        dst: v15,
        dstImageFormat: IMAGE_FORMAT_RGB888,
        width,
        height: endFrame,
        srcStride: 0,
        dstStride: 0);
      TGAWriter::WriteToBuffer(
        pImageData: v15,
        buffer: &normalBuf,
        width,
        height: endFrame,
        srcFormat: IMAGE_FORMAT_RGB888,
        dstFormat: IMAGE_FORMAT_RGB888);
      operator delete(p: v15);
    }
    else
    {
      v13 = v11 + 3;
      while ( *v13 == 0xFF )
      {
        ++v12;
        v13 += 4;
        if ( v12 >= endFrame * width )
          goto LABEL_21;
      }
      TGAWriter::WriteToBuffer(
        pImageData: v11,
        buffer: &normalBuf,
        width,
        height: endFrame,
        srcFormat: IMAGE_FORMAT_RGBA8888,
        dstFormat: IMAGE_FORMAT_RGBA8888);
    }
    if ( !g_pFullFileSystem->WriteFile(
            this: &g_pFullFileSystem->IBaseFileSystem,
            a2: normalTGAFileName,
            a3: nullptr,
            a4: &normalBuf) )
      break;
    operator delete(p: v9);
    operator delete(p: v11);
    if ( normalBuf.m_Memory.m_nGrowSize >= 0 )
    {
      if ( normalBuf.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: normalBuf.m_Memory.m_pMemory);
        normalBuf.m_Memory.m_pMemory = nullptr;
      }
      normalBuf.m_Memory.m_nAllocationCount = 0;
    }
    if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    ++i;
    if ( ++frameID >= numFrames )
      return;
    v5 = animated_3;
  }
  v20 = __iob_func();
  fprintf(str: v20 + 2, format: "unable to write %s\n", normalTGAFileName);
  if ( normalBuf.m_Memory.m_nGrowSize >= 0 )
  {
    if ( normalBuf.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: normalBuf.m_Memory.m_pMemory);
      normalBuf.m_Memory.m_pMemory = nullptr;
    }
    normalBuf.m_Memory.m_nAllocationCount = 0;
  }
  if ( buf.m_Memory.m_nGrowSize >= 0 )
  {
    m_pMemory = buf.m_Memory.m_pMemory;
    v19 = buf.m_Memory.m_pMemory == nullptr;
LABEL_44:
    if ( !v19 )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401500
// Name: LoadConfigFile
// Source: json
//------------------------------------------------------------------------------
void __usercall LoadConfigFile(const char *pFileName@<eax>, float *bumpScale, int *startFrame, int *endFrame)
{
  _iobuf *v5; // eax
  char *v6; // esi
  int v7; // eax
  char *v8; // edi
  CUtlBuffer buf; // [esp+Ch] [ebp-38h] BYREF
  char *key; // [esp+3Ch] [ebp-8h] BYREF
  char *val; // [esp+40h] [ebp-4h] BYREF

  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 1);
  if ( !g_pFullFileSystem->ReadFile(
          this: &g_pFullFileSystem->IBaseFileSystem,
          a2: pFileName,
          a3: nullptr,
          a4: &buf,
          a5: 0,
          a6: 0,
          a7: nullptr) )
  {
    v5 = __iob_func();
    fprintf(str: v5 + 2, format: "Can't open: %s\n", pFileName);
    if ( !g_NoPause )
    {
      printf(format: "Hit a key to continue\n");
      getch();
    }
    exit(code: -1);
  }
  key = nullptr;
  val = nullptr;
  while ( GetKeyValueFromBuffer(&buf, &key, &val) != 0 )
  {
    v6 = key;
    v7 = _V_stricmp(s1: key, s2: "bumpscale");
    v8 = val;
    if ( v7 == 0 )
      *bumpScale = atof(nptr: val);
    if ( _V_stricmp(s1: v6, s2: "startframe") != 0 )
    {
      if ( _V_stricmp(s1: v6, s2: "endframe") == 0 )
        *endFrame = atoi(nptr: v8);
    }
    else
    {
      *startFrame = atoi(nptr: v8);
    }
  }
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00401630
// Name: _main
// Source: json
//------------------------------------------------------------------------------
int __cdecl main(int argc, const char **argv, const char **envp)
{
  int i; // esi
  const char **v4; // ebx
  _iobuf *v5; // eax
  const char *v7; // edi
  _iobuf *v8; // eax
  int v9; // ebx
  _iobuf *v10; // eax
  char pCurrentDirectory[260]; // [esp+2Ch] [ebp-110h] BYREF
  int endFrame; // [esp+130h] [ebp-Ch] BYREF
  int startFrame; // [esp+134h] [ebp-8h] BYREF
  float bumpScale; // [esp+138h] [ebp-4h] BYREF

  if ( argc < 2 )
    Usage();
  MathLib_Init(
    gamma: 2.2,
    texGamma: 2.2,
    brightness: 0.0,
    overbright: 2,
    bAllow3DNow: true,
    bAllowSSE: true,
    bAllowSSE2: true,
    bAllowMMX: true);
  InitDefaultFileSystem();
  for ( i = 1; i < argc; ++i )
  {
    v4 = argv;
    if ( _V_stricmp(s1: argv[i], s2: "-quiet") == 0 )
    {
      ++i;
      g_Quiet = true;
      g_NoPause = true;
    }
    if ( _V_stricmp(s1: argv[i], s2: "-nopause") != 0 )
      break;
    g_NoPause = true;
  }
  if ( _getcwd(pnbuf: pCurrentDirectory, maxlen: 260) == nullptr )
  {
    v5 = __iob_func();
    fprintf(str: v5 + 2, format: "Unable to get the current directory\n");
    return -1;
  }
  V_FixSlashes(pname: pCurrentDirectory, separator: 92);
  V_StripTrailingSlash(ppath: pCurrentDirectory);
  for ( ; i < argc; ++i )
  {
    if ( V_IsAbsolutePath(pStr: v4[i]) )
    {
      v7 = v4[i];
    }
    else
    {
      V_snprintf(pDest: normalFileNameWithoutExtension, maxLen: 1024, pFormat: "%s\\%s", pCurrentDirectory, v4[i]);
      v7 = normalFileNameWithoutExtension;
    }
    if ( !g_Quiet )
      printf(format: "file: %s\n", v7);
    startFrame = -1;
    endFrame = -1;
    bumpScale = -1.0;
    LoadConfigFile(pFileName: v7, &bumpScale, &startFrame, &endFrame);
    if ( bumpScale == -1.0 )
    {
      v8 = __iob_func();
      fprintf(str: v8 + 2, format: "Must specify \"bumpscale\" in config file\n");
      if ( !g_NoPause )
      {
        printf(format: "Hit a key to continue\n");
        getch();
      }
      continue;
    }
    v9 = endFrame;
    if ( startFrame == -1 )
    {
      if ( endFrame != -1 )
        goto LABEL_28;
    }
    else if ( endFrame == -1 )
    {
LABEL_28:
      v10 = __iob_func();
      fprintf(str: v10 + 2, format: "ERROR: If you use startframe, you must use endframe, and vice versa.\n");
      if ( !g_NoPause )
      {
        printf(format: "Hit a key to continue\n");
        getch();
      }
      goto LABEL_24;
    }
    if ( !g_Quiet )
      printf(format: "\tbumpscale: %f\n", bumpScale);
    V_StripExtension(in: v7, out: normalFileNameWithoutExtension, outSize: 1024);
    ProcessFiles(pNormalFileNameWithoutExtension: normalFileNameWithoutExtension, startFrame, endFrame: v9, bumpScale);
LABEL_24:
    v4 = argv;
  }
  return 0;
}
