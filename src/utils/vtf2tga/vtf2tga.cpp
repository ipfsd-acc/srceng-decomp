// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vtf2tga/vtf2tga.cpp
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x004010C0
// Name: PFMWrite
// Source: json
//------------------------------------------------------------------------------
void __usercall PFMWrite(const char *pFilename@<eax>, int height@<ecx>, float *pFloatImage, int width)
{
  _iobuf *v5; // edi
  int v6; // esi
  unsigned int v7; // ecx
  float *v8; // ebx

  v5 = fopen(file: pFilename, mode: "wb");
  fprintf(str: v5, format: "PF\n%d %d\n-1.000000\n", width, height);
  v6 = height - 1;
  if ( v6 >= 0 )
  {
    v7 = 12 * width;
    v8 = &pFloatImage[3 * width * v6];
    while ( 1 )
    {
      fwrite(buffer: v8, size: v7, count: 1u, stream: v5);
      v8 -= 3 * width;
      if ( --v6 < 0 )
        break;
      v7 = 12 * width;
    }
  }
  fclose(stream: v5);
}

//------------------------------------------------------------------------------
// Address: 0x00401150
// Name: _main
// Source: json
//------------------------------------------------------------------------------
int __cdecl main(int argc, const char **argv, const char **envp)
{
  void (__thiscall ***v3)(_DWORD, int, const char **); // eax
  int v4; // eax
  const char *v5; // edi
  int v6; // eax
  const char *v7; // ebx
  int v8; // eax
  _iobuf *v9; // eax
  _iobuf *v11; // eax
  _iobuf *v12; // esi
  int v13; // edi
  int v14; // edi
  IVTFTexture *VTFTexture; // edi
  bool (__thiscall *Unserialize)(IVTFTexture *, CUtlBuffer *, bool, int); // edx
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  bool v21; // zf
  const char *v22; // eax
  const char *v23; // eax
  const char *v24; // eax
  const char *v25; // eax
  const char *v26; // eax
  const char *v27; // eax
  const char *v28; // eax
  const char *v29; // eax
  bool v30; // sf
  const char *v31; // eax
  const char *v32; // eax
  const char *v33; // eax
  const char *v34; // eax
  const char *v35; // eax
  const char *v36; // eax
  const char *v37; // eax
  const char *v38; // eax
  const char *v39; // eax
  const char *v40; // eax
  const char *v41; // eax
  const char *v42; // eax
  const char *v43; // eax
  int v44; // eax
  float v45; // ecx
  const ImageFormatInfo_t *v46; // eax
  int v47; // esi
  int (__thiscall *FaceCount)(IVTFTexture *); // eax
  int v49; // eax
  IVTFTexture v50; // edx
  int v51; // ebx
  bool (__thiscall *IsCubeMap)(IVTFTexture *); // eax
  int v53; // ebx
  int v54; // ecx
  unsigned int v55; // eax
  void *v56; // esp
  unsigned __int8 *v57; // eax
  ImageFormat v58; // esi
  ImageFormat v59; // esi
  unsigned int MemRequired; // eax
  unsigned __int8 *v61; // edi
  unsigned int v62; // eax
  const ImageFormatInfo_t *v63; // eax
  unsigned int v64; // eax
  const ImageFormatInfo_t *v65; // eax
  _iobuf *v66; // eax
  const char *m_pName; // esi
  const ImageFormatInfo_t *v68; // eax
  unsigned int v69; // [esp+3Ch] [ebp-4DCh]
  char v70[12]; // [esp+44h] [ebp-4D4h] BYREF
  char pOutFileNameBase[260]; // [esp+50h] [ebp-4C8h] BYREF
  char pCurrentDirectory[260]; // [esp+154h] [ebp-3C4h] BYREF
  char pBuf[260]; // [esp+258h] [ebp-2C0h] BYREF
  char pActualVTFFileName[260]; // [esp+35Ch] [ebp-1BCh] BYREF
  CUtlBuffer outBuffer; // [esp+460h] [ebp-B8h] BYREF
  CUtlBuffer buf; // [esp+490h] [ebp-88h] BYREF
  char pDest[8]; // [esp+4C0h] [ebp-58h] BYREF
  char pTemp[4]; // [esp+4C8h] [ebp-50h] BYREF
  unsigned int i; // [esp+4CCh] [ebp-4Ch]
  Vector vecReflectivity; // [esp+4D0h] [ebp-48h] BYREF
  int iFaceCount; // [esp+4DCh] [ebp-3Ch]
  int iTGANameLen; // [esp+4E0h] [ebp-38h]
  int iDepth; // [esp+4E4h] [ebp-34h] BYREF
  int nFrameCount; // [esp+4E8h] [ebp-30h]
  IVTFTexture *pTex; // [esp+4ECh] [ebp-2Ch]
  int z; // [esp+4F0h] [ebp-28h]
  int iLastMipLevel; // [esp+4F4h] [ebp-24h]
  ImageFormat srcFormat; // [esp+4F8h] [ebp-20h]
  int iMipLevel; // [esp+4FCh] [ebp-1Ch]
  int iFrame; // [esp+500h] [ebp-18h]
  int iCubeFace; // [esp+504h] [ebp-14h]
  bool bIsCubeMap; // [esp+50Ah] [ebp-Eh]
  bool bGenerateMipLevels; // [esp+50Bh] [ebp-Dh]
  int iHeight; // [esp+50Ch] [ebp-Ch] BYREF
  int iWidth; // [esp+510h] [ebp-8h] BYREF
  unsigned __int8 *tmpImage; // [esp+514h] [ebp-4h]

  v3 = (void (__thiscall ***)(_DWORD, int, const char **))_CommandLine();
  (**v3)(a1: v3, a2: argc, a3: argv);
  MathLib_Init(
    gamma: 2.2,
    texGamma: 2.2,
    brightness: 0.0,
    overbright: 1,
    bAllow3DNow: false,
    bAllowSSE: false,
    bAllowSSE2: false,
    bAllowMMX: false);
  InitDefaultFileSystem();
  v4 = _CommandLine();
  v5 = (const char *)(*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v4 + 32))(a1: v4, a2: "-i", a3: 0);
  v6 = _CommandLine();
  v7 = (const char *)(*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v6 + 32))(a1: v6, a2: "-o", a3: 0);
  v8 = _CommandLine();
  bGenerateMipLevels = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v8 + 12))(
                         a1: v8,
                         a2: "-mip",
                         a3: 0) != 0;
  if ( v5 == nullptr )
  {
    _Error(a1: "Usage: vtf2tga -i <input vtf> [-o <output tga>] [-mip]\n");
    exit(code: -1);
  }
  if ( v7 == nullptr )
    v7 = v5;
  if ( _getcwd(pnbuf: pCurrentDirectory, maxlen: 260) != nullptr )
  {
    V_StripTrailingSlash(ppath: pCurrentDirectory);
    if ( V_IsAbsolutePath(pStr: v7) )
      V_strncpy(pDest: pBuf, pSrc: v7, maxLen: 260);
    else
      V_snprintf(pDest: pBuf, maxLen: 260, pFormat: "%s\\%s", pCurrentDirectory, v7);
    V_FixSlashes(pname: pBuf, separator: 92);
    V_StripExtension(in: pBuf, out: pOutFileNameBase, outSize: 260);
    V_strncpy(pDest: pActualVTFFileName, pSrc: v5, maxLen: 260);
    if ( _V_strstr(s1: pActualVTFFileName, search: ".vtf") == nullptr )
      V_strncat(pDest: pActualVTFFileName, pSrc: ".vtf", destBufferSize: 0x104u, max_chars_to_copy: -1);
    v11 = fopen(file: pActualVTFFileName, mode: "rb");
    v12 = v11;
    if ( v11 == nullptr )
    {
      _Error(a1: "Can't open %s\n", pActualVTFFileName);
      exit(code: -1);
    }
    fseek(stream: v11, offset: 0, whence: 2);
    v13 = ftell(stream: v12);
    fseek(stream: v12, offset: 0, whence: 0);
    CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
    CUtlBuffer::EnsureCapacity(this: &buf, num: v13);
    v14 = fread(buffer: buf.m_Memory.m_pMemory, elementSize: 1u, count: v13, stream: v12);
    fclose(stream: v12);
    CUtlBuffer::SeekPut(this: &buf, type: SEEK_HEAD, offset: v14);
    VTFTexture = CreateVTFTexture();
    Unserialize = VTFTexture->Unserialize;
    pTex = VTFTexture;
    if ( !Unserialize(this: VTFTexture, a2: &buf, a3: false, a4: 0) )
    {
      _Error(a1: "*** Error reading in .VTF file %s\n", pActualVTFFileName);
      exit(code: -1);
    }
    v17 = VTFTexture->Width(this: VTFTexture);
    _Msg(a1: "vtf width: %d\n", v17);
    v18 = VTFTexture->Height(this: VTFTexture);
    _Msg(a1: "vtf height: %d\n", v18);
    v19 = VTFTexture->FrameCount(this: VTFTexture);
    _Msg(a1: "vtf numFrames: %d\n", v19);
    v20 = VTFTexture->MipCount(this: VTFTexture);
    _Msg(a1: "vtf MipCount(): %d\n", v20);
    v21 = (VTFTexture->Flags(this: VTFTexture) & 1) == 0;
    v22 = "true";
    if ( v21 )
      v22 = "false";
    _Msg(a1: "TEXTUREFLAGS_POINTSAMPLE=%s\n", v22);
    v21 = (VTFTexture->Flags(this: VTFTexture) & 2) == 0;
    v23 = "true";
    if ( v21 )
      v23 = "false";
    _Msg(a1: "TEXTUREFLAGS_TRILINEAR=%s\n", v23);
    v21 = (VTFTexture->Flags(this: VTFTexture) & 4) == 0;
    v24 = "true";
    if ( v21 )
      v24 = "false";
    _Msg(a1: "TEXTUREFLAGS_CLAMPS=%s\n", v24);
    v21 = (VTFTexture->Flags(this: VTFTexture) & 8) == 0;
    v25 = "true";
    if ( v21 )
      v25 = "false";
    _Msg(a1: "TEXTUREFLAGS_CLAMPT=%s\n", v25);
    v21 = (VTFTexture->Flags(this: VTFTexture) & 0x2000000) == 0;
    v26 = "true";
    if ( v21 )
      v26 = "false";
    _Msg(a1: "TEXTUREFLAGS_CLAMPU=%s\n", v26);
    v21 = (VTFTexture->Flags(this: VTFTexture) & 0x10) == 0;
    v27 = "true";
    if ( v21 )
      v27 = "false";
    _Msg(a1: "TEXTUREFLAGS_ANISOTROPIC=%s\n", v27);
    v21 = (VTFTexture->Flags(this: VTFTexture) & 0x20) == 0;
    v28 = "true";
    if ( v21 )
      v28 = "false";
    _Msg(a1: "TEXTUREFLAGS_HINT_DXT5=%s\n", v28);
    v21 = (VTFTexture->Flags(this: VTFTexture) & 0x80000) == 0;
    v29 = "true";
    if ( v21 )
      v29 = "false";
    _Msg(a1: "TEXTUREFLAGS_SRGB=%s\n", v29);
    v30 = (VTFTexture->Flags(this: VTFTexture) & 0x80u) != 0;
    v31 = "true";
    if ( !v30 )
      v31 = "false";
    _Msg(a1: "TEXTUREFLAGS_NORMAL=%s\n", v31);
    v21 = (VTFTexture->Flags(this: VTFTexture) & 0x100) == 0;
    v32 = "true";
    if ( v21 )
      v32 = "false";
    _Msg(a1: "TEXTUREFLAGS_NOMIP=%s\n", v32);
    v21 = (VTFTexture->Flags(this: VTFTexture) & 0x200) == 0;
    v33 = "true";
    if ( v21 )
      v33 = "false";
    _Msg(a1: "TEXTUREFLAGS_NOLOD=%s\n", v33);
    v21 = (VTFTexture->Flags(this: VTFTexture) & 0x400) == 0;
    v34 = "true";
    if ( v21 )
      v34 = "false";
    _Msg(a1: "TEXTUREFLAGS_ALL_MIPS=%s\n", v34);
    v21 = (VTFTexture->Flags(this: VTFTexture) & 0x10000000) == 0;
    v35 = "true";
    if ( v21 )
      v35 = "false";
    _Msg(a1: "TEXTUREFLAGS_MOST_MIPS=%s\n", v35);
    v21 = (VTFTexture->Flags(this: VTFTexture) & 0x800) == 0;
    v36 = "true";
    if ( v21 )
      v36 = "false";
    _Msg(a1: "TEXTUREFLAGS_PROCEDURAL=%s\n", v36);
    v21 = (VTFTexture->Flags(this: VTFTexture) & 0x1000) == 0;
    v37 = "true";
    if ( v21 )
      v37 = "false";
    _Msg(a1: "TEXTUREFLAGS_ONEBITALPHA=%s\n", v37);
    v21 = (VTFTexture->Flags(this: VTFTexture) & 0x2000) == 0;
    v38 = "true";
    if ( v21 )
      v38 = "false";
    _Msg(a1: "TEXTUREFLAGS_EIGHTBITALPHA=%s\n", v38);
    v21 = (VTFTexture->Flags(this: VTFTexture) & 0x4000) == 0;
    v39 = "true";
    if ( v21 )
      v39 = "false";
    _Msg(a1: "TEXTUREFLAGS_ENVMAP=%s\n", v39);
    v21 = (VTFTexture->Flags(this: VTFTexture) & 0x8000) == 0;
    v40 = "true";
    if ( v21 )
      v40 = "false";
    _Msg(a1: "TEXTUREFLAGS_RENDERTARGET=%s\n", v40);
    v21 = (VTFTexture->Flags(this: VTFTexture) & 0x10000) == 0;
    v41 = "true";
    if ( v21 )
      v41 = "false";
    _Msg(a1: "TEXTUREFLAGS_DEPTHRENDERTARGET=%s\n", v41);
    v21 = (VTFTexture->Flags(this: VTFTexture) & 0x20000) == 0;
    v42 = "true";
    if ( v21 )
      v42 = "false";
    _Msg(a1: "TEXTUREFLAGS_NODEBUGOVERRIDE=%s\n", v42);
    v21 = (VTFTexture->Flags(this: VTFTexture) & 0x40000) == 0;
    v43 = "true";
    if ( v21 )
      v43 = "false";
    _Msg(a1: "TEXTUREFLAGS_SINGLECOPY=%s\n", v43);
    v44 = (int)VTFTexture->Reflectivity(this: VTFTexture);
    v45 = *(float *)(v44 + 8);
    *(_QWORD *)&vecReflectivity.x = *(_QWORD *)v44;
    vecReflectivity.z = v45;
    _Msg(a1: "vtf reflectivity: %f %f %f\n", vecReflectivity.x, vecReflectivity.y, v45);
    _Msg(a1: "transparency: ");
    if ( (VTFTexture->Flags(this: VTFTexture) & 0x2000) != 0 )
    {
      _Msg(a1: "eightbitalpha\n");
    }
    else if ( (VTFTexture->Flags(this: VTFTexture) & 0x1000) != 0 )
    {
      _Msg(a1: "onebitalpha\n");
    }
    else
    {
      _Msg(a1: "noalpha\n");
    }
    srcFormat = VTFTexture->Format(this: VTFTexture);
    v46 = ImageLoader::ImageFormatInfo(fmt: srcFormat);
    _Msg(a1: "vtf format: %s\n", v46->m_pName);
    v47 = _V_strlen(str: pOutFileNameBase);
    FaceCount = VTFTexture->FaceCount;
    iTGANameLen = v47;
    v49 = FaceCount(this: VTFTexture);
    v50.__vftable = VTFTexture->__vftable;
    iFaceCount = v49;
    v51 = v50.FrameCount(this: VTFTexture);
    IsCubeMap = VTFTexture->IsCubeMap;
    nFrameCount = v51;
    bIsCubeMap = IsCubeMap(this: VTFTexture);
    if ( bGenerateMipLevels )
      iLastMipLevel = VTFTexture->MipCount(this: VTFTexture) - 1;
    else
      iLastMipLevel = 0;
    iFrame = 0;
    if ( v51 > 0 )
    {
      do
      {
        v53 = 0;
        for ( iMipLevel = 0; v53 <= iLastMipLevel; iMipLevel = v53 )
        {
          VTFTexture->ComputeMipLevelDimensions(this: VTFTexture, a2: v53, a3: &iWidth, a4: &iHeight, a5: &iDepth);
          iCubeFace = 0;
          if ( iFaceCount > 0 )
          {
            v54 = iDepth;
            do
            {
              z = 0;
              if ( v54 > 0 )
              {
                v55 = (v47 + 28) & 0xFFFFFFF0;
                for ( i = v55; ; v55 = i )
                {
                  v56 = alloca(v55);
                  V_strncpy(pDest: v70, pSrc: pOutFileNameBase, maxLen: v47 + 1);
                  _V_strrchr(s: v70, c: 46);
                  if ( bIsCubeMap )
                    V_strncat(
                      pDest: v70,
                      pSrc: pCubeFaceName[iCubeFace],
                      destBufferSize: v47 + 13,
                      max_chars_to_copy: -1);
                  if ( nFrameCount > 1 )
                  {
                    V_snprintf(pDest: pTemp, maxLen: 4, pFormat: "%03d", iFrame);
                    V_strncat(pDest: v70, pSrc: pTemp, destBufferSize: v47 + 13, max_chars_to_copy: -1);
                  }
                  if ( iLastMipLevel != 0 )
                  {
                    V_snprintf(pDest: (char *)&vecReflectivity.y, maxLen: 8, pFormat: "_mip%d", iMipLevel);
                    V_strncat(
                      pDest: v70,
                      pSrc: (const char *)&vecReflectivity.y,
                      destBufferSize: v47 + 13,
                      max_chars_to_copy: -1);
                  }
                  if ( VTFTexture->Depth(this: VTFTexture) > 1 )
                  {
                    V_snprintf(pDest, maxLen: 6, pFormat: "_z%03d", z);
                    V_strncat(pDest: v70, pSrc: pDest, destBufferSize: v47 + 13, max_chars_to_copy: -1);
                  }
                  v69 = v47 + 13;
                  if ( srcFormat == IMAGE_FORMAT_RGBA16161616F )
                    V_strncat(pDest: v70, pSrc: ".pfm", destBufferSize: v69, max_chars_to_copy: -1);
                  else
                    V_strncat(pDest: v70, pSrc: ".tga", destBufferSize: v69, max_chars_to_copy: -1);
                  v57 = VTFTexture->ImageData(
                          this: VTFTexture,
                          a2: iFrame,
                          a3: iCubeFace,
                          a4: iMipLevel,
                          a5: 0,
                          a6: 0,
                          a7: z);
                  v58 = srcFormat;
                  tmpImage = v57;
                  if ( srcFormat == IMAGE_FORMAT_RGBA16161616F )
                  {
                    v59 = IMAGE_FORMAT_RGB323232F;
                  }
                  else if ( ImageLoader::ImageFormatInfo(fmt: srcFormat)->m_nNumAlphaBits != 0
                         || v58 == IMAGE_FORMAT_ATI1N
                         || (v21 = v58 == IMAGE_FORMAT_ATI2N, v59 = IMAGE_FORMAT_BGR888, v21) )
                  {
                    v59 = IMAGE_FORMAT_BGRA8888;
                  }
                  MemRequired = ImageLoader::GetMemRequired(
                                  width: iWidth,
                                  height: iHeight,
                                  depth: 1,
                                  imageFormat: v59,
                                  mipmap: false,
                                  pAdjustedHeight: nullptr);
                  v61 = (unsigned __int8 *)MemAlloc_Alloc(nSize: MemRequired);
                  if ( !ImageLoader::ConvertImageFormat(
                          src: tmpImage,
                          srcImageFormat: srcFormat,
                          dst: v61,
                          dstImageFormat: v59,
                          width: iWidth,
                          height: iHeight,
                          srcStride: 0,
                          dstStride: 0) )
                  {
                    m_pName = ImageLoader::ImageFormatInfo(fmt: v59)->m_pName;
                    v68 = ImageLoader::ImageFormatInfo(fmt: srcFormat);
                    _Error(a1: "Error converting from %s to %s\n", v68->m_pName, m_pName);
                    exit(code: -1);
                  }
                  if ( v59 == IMAGE_FORMAT_RGB323232F )
                  {
                    PFMWrite(pFilename: v70, height: iHeight, pFloatImage: (float *)v61, width: iWidth);
                  }
                  else
                  {
                    if ( ImageLoader::ImageFormatInfo(fmt: v59)->m_nNumAlphaBits != 0 )
                    {
                      tmpImage = v61;
                      v62 = ImageLoader::GetMemRequired(
                              width: iWidth,
                              height: iHeight,
                              depth: 1,
                              imageFormat: IMAGE_FORMAT_RGBA8888,
                              mipmap: false,
                              pAdjustedHeight: nullptr);
                      v61 = (unsigned __int8 *)MemAlloc_Alloc(nSize: v62);
                      if ( !ImageLoader::ConvertImageFormat(
                              src: tmpImage,
                              srcImageFormat: v59,
                              dst: v61,
                              dstImageFormat: IMAGE_FORMAT_RGBA8888,
                              width: iWidth,
                              height: iHeight,
                              srcStride: 0,
                              dstStride: 0) )
                      {
                        tmpImage = (unsigned __int8 *)ImageLoader::ImageFormatInfo(fmt: IMAGE_FORMAT_RGBA8888)->m_pName;
                        v63 = ImageLoader::ImageFormatInfo(fmt: v59);
                        _Error(a1: "Error converting from %s to %s\n", v63->m_pName, (const char *)tmpImage);
                      }
                      v59 = IMAGE_FORMAT_RGBA8888;
                    }
                    else if ( ImageLoader::ImageFormatInfo(fmt: v59)->m_nNumAlphaBits == 0 )
                    {
                      tmpImage = v61;
                      v64 = ImageLoader::GetMemRequired(
                              width: iWidth,
                              height: iHeight,
                              depth: 1,
                              imageFormat: IMAGE_FORMAT_RGB888,
                              mipmap: false,
                              pAdjustedHeight: nullptr);
                      v61 = (unsigned __int8 *)MemAlloc_Alloc(nSize: v64);
                      if ( !ImageLoader::ConvertImageFormat(
                              src: tmpImage,
                              srcImageFormat: v59,
                              dst: v61,
                              dstImageFormat: IMAGE_FORMAT_RGB888,
                              width: iWidth,
                              height: iHeight,
                              srcStride: 0,
                              dstStride: 0) )
                      {
                        tmpImage = (unsigned __int8 *)ImageLoader::ImageFormatInfo(fmt: IMAGE_FORMAT_RGB888)->m_pName;
                        v65 = ImageLoader::ImageFormatInfo(fmt: v59);
                        _Error(a1: "Error converting from %s to %s\n", v65->m_pName, (const char *)tmpImage);
                      }
                      v59 = IMAGE_FORMAT_RGB888;
                    }
                    CUtlBuffer::CUtlBuffer(this: &outBuffer, growSize: 0, initSize: 0, nFlags: 0);
                    TGAWriter::WriteToBuffer(
                      pImageData: v61,
                      buffer: &outBuffer,
                      width: iWidth,
                      height: iHeight,
                      srcFormat: v59,
                      dstFormat: v59);
                    if ( !g_pFullFileSystem->WriteFile(
                            this: &g_pFullFileSystem->IBaseFileSystem,
                            a2: v70,
                            a3: nullptr,
                            a4: &outBuffer) )
                    {
                      v66 = __iob_func();
                      fprintf(str: v66 + 2, format: "unable to write %s\n", v70);
                    }
                    if ( outBuffer.m_Memory.m_nGrowSize >= 0 && outBuffer.m_Memory.m_pMemory != nullptr )
                      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: outBuffer.m_Memory.m_pMemory);
                  }
                  v54 = iDepth;
                  v47 = iTGANameLen;
                  VTFTexture = pTex;
                  if ( ++z >= iDepth )
                    break;
                }
              }
              ++iCubeFace;
            }
            while ( iCubeFace < iFaceCount );
            v53 = iMipLevel;
          }
          ++v53;
        }
        ++iFrame;
      }
      while ( iFrame < nFrameCount );
    }
    if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    return 0;
  }
  else
  {
    v9 = __iob_func();
    fprintf(str: v9 + 2, format: "Unable to get the current directory\n");
    return -1;
  }
}
