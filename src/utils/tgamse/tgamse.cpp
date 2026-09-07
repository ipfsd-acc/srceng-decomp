// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/tgamse/tgamse.cpp
// Functions: 3
// ============================================================

#include "utils\tgamse\tgamse.h"

//------------------------------------------------------------------------------
// Address: 0x004010C0
// Name: void Usage(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __noreturn Usage()
{
  printf(format: "Fuzzy compare of two tga files.\n\n");
  printf(format: "Usage: tgamse src1.tga src2.tga \n");
  printf(format: "Return: MSE\n\n");
  printf(format: "Usage: tgamse src1.tga src2.tga threshhold \n");
  printf(format: "Return: PASS\\FAIL\n");
  exit(code: -1);
}

//------------------------------------------------------------------------------
// Address: 0x00401100
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
// Address: 0x00401130
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
  unsigned __int8 *v11; // esi
  _iobuf *v12; // eax
  const char *v13; // edi
  _iobuf *v14; // eax
  unsigned int MemRequired; // eax
  unsigned __int8 *v16; // ebx
  unsigned int v17; // eax
  unsigned __int8 *v18; // edi
  unsigned int v19; // eax
  char *v20; // edi
  unsigned int v21; // eax
  unsigned __int8 *v22; // esi
  int v23; // edx
  float v24; // xmm1_4
  int v25; // eax
  unsigned __int8 *v26; // ebx
  unsigned __int8 *v27; // ecx
  float v28; // xmm0_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  float v31; // xmm1_4
  float v32; // xmm0_4
  float v33; // xmm0_4
  float v34; // xmm1_4
  char *v35; // ecx
  int v36; // esi
  int v37; // edi
  int v38; // eax
  float v39; // xmm1_4
  int targetGamma; // [esp+44h] [ebp-4ACh]
  int targetGamma_4; // [esp+48h] [ebp-4A8h]
  int v42; // [esp+4Ch] [ebp-4A4h]
  char pBuf[3][260]; // [esp+50h] [ebp-4A0h] BYREF
  char pCurrentDirectory[260]; // [esp+35Ch] [ebp-194h] BYREF
  CUtlBuffer buf2; // [esp+460h] [ebp-90h] BYREF
  CUtlBuffer buf1; // [esp+490h] [ebp-60h] BYREF
  float gamma2; // [esp+4C0h] [ebp-30h] BYREF
  float gamma1; // [esp+4C4h] [ebp-2Ch] BYREF
  float fMSE; // [esp+4C8h] [ebp-28h]
  unsigned __int8 *pImage1; // [esp+4CCh] [ebp-24h]
  char *v51; // [esp+4D0h] [ebp-20h]
  unsigned __int8 *pImage2Tmp; // [esp+4D4h] [ebp-1Ch]
  ImageFormat imageFormat2; // [esp+4D8h] [ebp-18h] BYREF
  ImageFormat imageFormat1; // [esp+4DCh] [ebp-14h] BYREF
  int height1; // [esp+4E0h] [ebp-10h] BYREF
  int height2; // [esp+4E4h] [ebp-Ch] BYREF
  int width1; // [esp+4E8h] [ebp-8h] BYREF
  int width2; // [esp+4ECh] [ebp-4h] BYREF

  if ( argc != 3 && argc != 4 )
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
  v42 = v3;
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
      (&pImage1)[v8] = (unsigned __int8 *)*v10;
    }
    else
    {
      V_snprintf(pDest: v9, maxLen: 260, pFormat: "%s\\%s", pCurrentDirectory, *v10);
      (&pImage1)[v8] = (unsigned __int8 *)v9;
    }
    ++v8;
    v9 += 260;
    ++v10;
  }
  while ( v8 < 2 );
  fMSE = 10000.0;
  if ( argc == 4 )
    fMSE = atof(nptr: argv[3]);
  CUtlBuffer::CUtlBuffer(this: &buf1, growSize: 0, initSize: 0, nFlags: 0);
  v11 = pImage1;
  if ( ((unsigned __int8 (__thiscall *)(IBaseFileSystem *, unsigned __int8 *, _DWORD, CUtlBuffer *, _DWORD, _DWORD, _DWORD, int, int, int))g_pFullFileSystem->ReadFile)(
         a1: &g_pFullFileSystem->IBaseFileSystem,
         a2: pImage1,
         a3: 0,
         a4: &buf1,
         a5: 0,
         a6: 0,
         a7: 0,
         a8: targetGamma,
         a9: targetGamma_4,
         a10: v42) == 0 )
  {
    v12 = __iob_func();
    fprintf(str: v12 + 2, format: "%s not found\n", (const char *)v11);
LABEL_15:
    if ( buf1.m_Memory.m_nGrowSize >= 0 && buf1.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf1.m_Memory.m_pMemory);
    return -1;
  }
  if ( !TGALoader::GetInfo(
          buf: &buf1,
          width: &width1,
          height: &height1,
          imageFormat: &imageFormat1,
          sourceGamma: &gamma1) )
    goto LABEL_20;
  CUtlBuffer::CUtlBuffer(this: &buf2, growSize: 0, initSize: 0, nFlags: 0);
  v13 = v51;
  if ( !g_pFullFileSystem->ReadFile(
          this: &g_pFullFileSystem->IBaseFileSystem,
          a2: v51,
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
    goto LABEL_15;
  }
  if ( !TGALoader::GetInfo(
          buf: &buf2,
          width: &width2,
          height: &height2,
          imageFormat: &imageFormat2,
          sourceGamma: &gamma2) )
  {
    printf(format: "error loading %s\n", v13);
    exit(code: -1);
  }
  if ( width1 != width2 || height1 != height2 )
  {
    printf(
      format: "image dimensions different (%dx%d!=%dx%d): can't do diff for %s\n",
      width1,
      height1,
      width2,
      height2,
      (const char *)v11);
LABEL_21:
    exit(code: -1);
  }
  if ( gamma1 != gamma2 )
  {
    printf(format: "image gamma different (%f!=%f). . can't do diff for %s\n", gamma1, gamma2, (const char *)v11);
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
LABEL_20:
    printf(format: "error loading %s\n", (const char *)v11);
    goto LABEL_21;
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
    printf(format: "error loading %s\n", v51);
    goto LABEL_21;
  }
  v19 = ImageLoader::GetMemRequired(
          width: width1,
          height: height1,
          depth: 1,
          imageFormat: IMAGE_FORMAT_ABGR8888,
          mipmap: false,
          pAdjustedHeight: nullptr);
  v20 = (char *)MemAlloc_Alloc(nSize: v19);
  v51 = v20;
  v21 = ImageLoader::GetMemRequired(
          width: width2,
          height: height2,
          depth: 1,
          imageFormat: IMAGE_FORMAT_ABGR8888,
          mipmap: false,
          pAdjustedHeight: nullptr);
  v22 = (unsigned __int8 *)MemAlloc_Alloc(nSize: v21);
  ImageLoader::ConvertImageFormat(
    src: v16,
    srcImageFormat: imageFormat1,
    dst: (unsigned __int8 *)v20,
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
  v23 = height1 * width1 * ImageLoader::ImageFormatInfo(fmt: IMAGE_FORMAT_ABGR8888)->m_nNumBytes;
  v24 = 0.0;
  v25 = 0;
  if ( v23 >= 4 )
  {
    v26 = (unsigned __int8 *)(v22 - (unsigned __int8 *)v20);
    v27 = (unsigned __int8 *)v20;
    for ( pImage2Tmp = (unsigned __int8 *)(v22 - (unsigned __int8 *)v20); ; v26 = pImage2Tmp )
    {
      v28 = (float)(v27[(_DWORD)v26] - *v27);
      v29 = (float)(v28 * v28) + v24;
      v30 = (float)(v22[v25 + 1] - v27[1]);
      v31 = (float)(v30 * v30) + v29;
      v32 = (float)(v22[v25 + 2] - v27[2]);
      v33 = (float)(v32 * v32) + v31;
      v34 = (float)(v22[v25 + 3] - v27[3]);
      v25 += 4;
      v27 += 4;
      v24 = (float)(v34 * v34) + v33;
      if ( v25 >= v23 - 3 )
        break;
    }
    v20 = v51;
  }
  if ( v25 < v23 )
  {
    v35 = &v20[v25];
    v36 = v22 - (unsigned __int8 *)v20;
    v37 = v23 - v25;
    do
    {
      v38 = (unsigned __int8)v35[v36] - (unsigned __int8)*v35;
      ++v35;
      --v37;
      v24 = v24 + (float)((float)v38 * (float)v38);
    }
    while ( v37 != 0 );
  }
  v39 = v24 / (float)v23;
  if ( argc == 3 )
  {
    printf(format: "MSE=%f\n", v39);
  }
  else if ( v39 <= fMSE )
  {
    printf(format: "PASS");
  }
  else
  {
    printf(format: "FAIL");
  }
  CUtlBuffer::~CUtlBuffer(this: &buf2);
  CUtlBuffer::~CUtlBuffer(this: &buf1);
  return 0;
}
