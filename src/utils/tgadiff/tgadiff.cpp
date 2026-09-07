// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/tgadiff/tgadiff.cpp
// Functions: 3
// ============================================================

#include "utils\tgadiff\tgadiff.h"

//------------------------------------------------------------------------------
// Address: 0x004010C0
// Name: void Usage(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __noreturn Usage()
{
  printf(format: "Usage: tgadiff src1.tga src2.tga diff.tga\n");
  exit(code: -1);
}

//------------------------------------------------------------------------------
// Address: 0x004010E0
// Name: public: CUtlBuffer::~CUtlBuffer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::~CUtlBuffer(CUtlBuffer *this)
{
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401110
// Name: _main
// Source: json
//------------------------------------------------------------------------------
int __cdecl main(int argc, const char **argv, const char **envp)
{
  int v3; // ebx
  int v4; // edi
  int v5; // esi
  _iobuf *v6; // eax
  int v8; // esi
  char *v9; // edi
  const char **v10; // ebx
  const char *v11; // esi
  _iobuf *v12; // eax
  const char *v13; // edi
  _iobuf *v14; // eax
  unsigned int MemRequired; // eax
  unsigned __int8 *v16; // ebx
  unsigned int v17; // eax
  unsigned __int8 *v18; // esi
  unsigned int v19; // eax
  unsigned __int8 *v20; // esi
  unsigned int v21; // eax
  unsigned __int8 *v22; // edi
  unsigned int v23; // eax
  int m_nNumBytes; // ebx
  int v25; // edi
  int v26; // ecx
  const char *v27; // esi
  _iobuf *v28; // eax
  int targetGamma; // [esp+44h] [ebp-4E4h]
  int targetGamma_4; // [esp+48h] [ebp-4E0h]
  int v31; // [esp+4Ch] [ebp-4DCh]
  char pBuf[3][260]; // [esp+50h] [ebp-4D8h] BYREF
  char pCurrentDirectory[260]; // [esp+35Ch] [ebp-1CCh] BYREF
  CUtlBuffer outBuffer; // [esp+460h] [ebp-C8h] BYREF
  CUtlBuffer buf2; // [esp+490h] [ebp-98h] BYREF
  CUtlBuffer buf1; // [esp+4C0h] [ebp-68h] BYREF
  float gamma2; // [esp+4F0h] [ebp-38h] BYREF
  unsigned __int8 *v38; // [esp+4F4h] [ebp-34h]
  float gamma1; // [esp+4F8h] [ebp-30h] BYREF
  unsigned __int8 *pDiff; // [esp+4FCh] [ebp-2Ch]
  int i; // [esp+500h] [ebp-28h]
  const char *pFileName[3]; // [esp+504h] [ebp-24h]
  ImageFormat imageFormat2; // [esp+510h] [ebp-18h] BYREF
  ImageFormat imageFormat1; // [esp+514h] [ebp-14h] BYREF
  int width2; // [esp+518h] [ebp-10h] BYREF
  int height2; // [esp+51Ch] [ebp-Ch] BYREF
  int height1; // [esp+520h] [ebp-8h] BYREF
  int width1; // [esp+524h] [ebp-4h] BYREF
  unsigned __int8 *pImage2Tmp; // [esp+530h] [ebp+8h]
  char pImage2Tmp_3; // [esp+533h] [ebp+Bh]

  if ( argc != 4 )
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
  if ( _getcwd(pnbuf: pCurrentDirectory, maxlen: 260) == nullptr )
  {
    v6 = __iob_func();
    fprintf(str: v6 + 2, format: "Unable to get the current directory\n");
    return -1;
  }
  v31 = v3;
  targetGamma_4 = v5;
  targetGamma = v4;
  V_FixSlashes(pname: pCurrentDirectory, separator: 92);
  V_StripTrailingSlash(ppath: pCurrentDirectory);
  v8 = 0;
  v9 = pBuf[0];
  v10 = argv + 1;
  do
  {
    if ( V_IsAbsolutePath(pStr: *v10) )
    {
      pFileName[v8] = *v10;
    }
    else
    {
      V_snprintf(pDest: v9, maxLen: 260, pFormat: "%s\\%s", pCurrentDirectory, *v10);
      pFileName[v8] = v9;
    }
    ++v8;
    v9 += 260;
    ++v10;
  }
  while ( v8 < 3 );
  CUtlBuffer::CUtlBuffer(this: &buf1, growSize: 0, initSize: 0, nFlags: 0);
  v11 = pFileName[0];
  if ( ((unsigned __int8 (__thiscall *)(IBaseFileSystem *, const char *, _DWORD, CUtlBuffer *, _DWORD, _DWORD, _DWORD, int, int, int))g_pFullFileSystem->ReadFile)(
         a1: &g_pFullFileSystem->IBaseFileSystem,
         a2: pFileName[0],
         a3: 0,
         a4: &buf1,
         a5: 0,
         a6: 0,
         a7: 0,
         a8: targetGamma,
         a9: targetGamma_4,
         a10: v31) != 0 )
  {
    if ( !TGALoader::GetInfo(
            buf: &buf1,
            width: &width1,
            height: &height1,
            imageFormat: &imageFormat1,
            sourceGamma: &gamma1) )
    {
      printf(format: "error loading %s\n", v11);
      exit(code: -1);
    }
    CUtlBuffer::CUtlBuffer(this: &buf2, growSize: 0, initSize: 0, nFlags: 0);
    v13 = pFileName[1];
    if ( !g_pFullFileSystem->ReadFile(
            this: &g_pFullFileSystem->IBaseFileSystem,
            a2: pFileName[1],
            a3: nullptr,
            a4: &buf2,
            a5: 0,
            a6: 0,
            a7: nullptr) )
    {
      v14 = __iob_func();
      fprintf(str: v14 + 2, format: "%s not found\n", v13);
      if ( buf2.m_Memory.m_nGrowSize >= 0 )
      {
        if ( buf2.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf2.m_Memory.m_pMemory);
          buf2.m_Memory.m_pMemory = nullptr;
        }
        buf2.m_Memory.m_nAllocationCount = 0;
      }
      goto LABEL_12;
    }
    if ( !TGALoader::GetInfo(
            buf: &buf2,
            width: &width2,
            height: &height2,
            imageFormat: &imageFormat2,
            sourceGamma: &gamma2) )
      goto LABEL_24;
    if ( width1 == width2 && height1 == height2 )
    {
      if ( gamma1 != gamma2 )
      {
        printf(format: "image gamma different (%f!=%f). . can't do diff for %s\n", gamma1, gamma2, pFileName[2]);
        exit(code: -1);
      }
      MemRequired = ImageLoader::GetMemRequired(
                      width: width1,
                      height: height1,
                      depth: 1,
                      imageFormat: imageFormat1,
                      mipmap: false,
                      pAdjustedHeight: nullptr);
      v16 = (unsigned __int8 *)MemAlloc_Alloc(nSize: MemRequired);
      v17 = ImageLoader::GetMemRequired(
              width: width2,
              height: height2,
              depth: 1,
              imageFormat: imageFormat2,
              mipmap: false,
              pAdjustedHeight: nullptr);
      v18 = (unsigned __int8 *)MemAlloc_Alloc(nSize: v17);
      pImage2Tmp = v18;
      CUtlBuffer::SeekGet(this: &buf1, type: SEEK_HEAD, offset: 0);
      if ( !TGALoader::Load(
              pOutputImage: v16,
              buf: &buf1,
              width: width1,
              height: height1,
              imageFormat: imageFormat1,
              targetGamma: 2.2,
              mipmap: false) )
      {
        printf(format: "error loading %s\n", pFileName[0]);
        exit(code: -1);
      }
      CUtlBuffer::SeekGet(this: &buf2, type: SEEK_HEAD, offset: 0);
      if ( !TGALoader::Load(
              pOutputImage: v18,
              buf: &buf2,
              width: width2,
              height: height2,
              imageFormat: imageFormat2,
              targetGamma: 2.2,
              mipmap: false) )
      {
LABEL_24:
        printf(format: "error loading %s\n", v13);
        goto LABEL_25;
      }
      v19 = ImageLoader::GetMemRequired(
              width: width1,
              height: height1,
              depth: 1,
              imageFormat: IMAGE_FORMAT_ABGR8888,
              mipmap: false,
              pAdjustedHeight: nullptr);
      v20 = (unsigned __int8 *)MemAlloc_Alloc(nSize: v19);
      v21 = ImageLoader::GetMemRequired(
              width: width2,
              height: height2,
              depth: 1,
              imageFormat: IMAGE_FORMAT_ABGR8888,
              mipmap: false,
              pAdjustedHeight: nullptr);
      v22 = (unsigned __int8 *)MemAlloc_Alloc(nSize: v21);
      v23 = ImageLoader::GetMemRequired(
              width: width2,
              height: height2,
              depth: 1,
              imageFormat: IMAGE_FORMAT_ABGR8888,
              mipmap: false,
              pAdjustedHeight: nullptr);
      pDiff = (unsigned __int8 *)MemAlloc_Alloc(nSize: v23);
      ImageLoader::ConvertImageFormat(
        src: v16,
        srcImageFormat: imageFormat1,
        dst: v20,
        dstImageFormat: IMAGE_FORMAT_ABGR8888,
        width: width1,
        height: height1,
        srcStride: 0,
        dstStride: 0);
      ImageLoader::ConvertImageFormat(
        src: pImage2Tmp,
        srcImageFormat: imageFormat2,
        dst: v22,
        dstImageFormat: IMAGE_FORMAT_ABGR8888,
        width: width2,
        height: height2,
        srcStride: 0,
        dstStride: 0);
      m_nNumBytes = ImageLoader::ImageFormatInfo(fmt: IMAGE_FORMAT_ABGR8888)->m_nNumBytes;
      pImage2Tmp_3 = 0;
      i = 0;
      if ( height1 * width1 * m_nNumBytes <= 0 )
        goto LABEL_39;
      v25 = v22 - v20;
      v38 = (unsigned __int8 *)(pDiff - v20);
      do
      {
        v26 = v20[v25] - *v20;
        v20[(_DWORD)v38] = abs32(v26);
        if ( v26 != 0 )
          pImage2Tmp_3 = 1;
        ++v20;
        ++i;
      }
      while ( i < height1 * width1 * m_nNumBytes );
      if ( pImage2Tmp_3 != 0 )
      {
        v27 = pFileName[2];
        printf(format: "Generating diff: %s!\n", pFileName[2]);
        CUtlBuffer::CUtlBuffer(this: &outBuffer, growSize: 0, initSize: 0, nFlags: 0);
        if ( TGAWriter::WriteToBuffer(
               pImageData: pDiff,
               buffer: &outBuffer,
               width: width1,
               height: height1,
               srcFormat: IMAGE_FORMAT_RGBA8888,
               dstFormat: IMAGE_FORMAT_RGBA8888) )
        {
          if ( g_pFullFileSystem->WriteFile(
                 this: &g_pFullFileSystem->IBaseFileSystem,
                 a2: v27,
                 a3: nullptr,
                 a4: &outBuffer) )
          {
            CUtlBuffer::~CUtlBuffer(this: &outBuffer);
            CUtlBuffer::~CUtlBuffer(this: &buf2);
            CUtlBuffer::~CUtlBuffer(this: &buf1);
            return 0;
          }
          else
          {
            v28 = __iob_func();
            fprintf(str: v28 + 2, format: "unable to write %s\n", v27);
            CUtlBuffer::~CUtlBuffer(this: &outBuffer);
            CUtlBuffer::~CUtlBuffer(this: &buf2);
            CUtlBuffer::~CUtlBuffer(this: &buf1);
            return -1;
          }
        }
        printf(format: "error writing %s to buffer\n", v27);
      }
      else
      {
LABEL_39:
        printf(format: "Files are the same %s %s : not generating %s\n", pFileName[0], pFileName[1], pFileName[2]);
      }
    }
    else
    {
      printf(
        format: "image dimensions different (%dx%d!=%dx%d): can't do diff for %s\n",
        width1,
        height1,
        width2,
        height2,
        pFileName[2]);
    }
LABEL_25:
    exit(code: -1);
  }
  v12 = __iob_func();
  fprintf(str: v12 + 2, format: "%s not found\n", v11);
LABEL_12:
  if ( buf1.m_Memory.m_nGrowSize >= 0 && buf1.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf1.m_Memory.m_pMemory);
  return -1;
}
