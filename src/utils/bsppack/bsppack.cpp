// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/bsppack/bsppack.cpp
// Functions: 13
// ============================================================

#include "utils\bsppack\bsppack.h"

//------------------------------------------------------------------------------
// Address: 0x10011AA0
// Name: public: virtual void CBSPPack::LoadBSPFile(class IFileSystem __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBSPPack::LoadBSPFile(CBSPPack *this, IFileSystem *pFileSystem, char *filename)
{
  MathLib_Init(
    gamma: 2.2,
    texGamma: 2.2,
    brightness: 0.0,
    overbright: 2,
    bAllow3DNow: true,
    bAllowSSE: true,
    bAllowSSE2: true,
    bAllowMMX: true);
  g_pFullFileSystem = pFileSystem;
  if ( pFileSystem != nullptr )
    g_pFileSystem = &pFileSystem->IBaseFileSystem;
  else
    g_pFileSystem = nullptr;
  LoadBSPFile(filename);
}

//------------------------------------------------------------------------------
// Address: 0x10011B20
// Name: public: virtual void CBSPPack::WriteBSPFile(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBSPPack::WriteBSPFile(CBSPPack *this@<ecx>, int a2@<ebx>, char *filename)
{
  WriteBSPFile(a1: a2, filename);
}

//------------------------------------------------------------------------------
// Address: 0x10011B40
// Name: public: virtual void CBSPPack::ClearPackFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBSPPack::ClearPackFile(CBSPPack *this)
{
  IZip *PakFile; // eax

  PakFile = GetPakFile();
  ClearPakFile(pak: PakFile);
}

//------------------------------------------------------------------------------
// Address: 0x10011B50
// Name: public: virtual void CBSPPack::AddFileToPack(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBSPPack::AddFileToPack(CBSPPack *this, const char *relativename, const char *fullpath)
{
  IZip *PakFile; // eax

  PakFile = GetPakFile();
  AddFileToPak(pak: PakFile, relativename, fullpath);
}

//------------------------------------------------------------------------------
// Address: 0x10011B70
// Name: public: virtual void CBSPPack::AddBufferToPack(char const __near *,void __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBSPPack::AddBufferToPack(
        CBSPPack *this,
        const char *relativename,
        void *data,
        int length,
        BOOL bTextMode)
{
  IZip *PakFile; // eax

  PakFile = GetPakFile();
  AddBufferToPak(pak: PakFile, pRelativeName: relativename, data, length, bTextMode);
}

//------------------------------------------------------------------------------
// Address: 0x10011BA0
// Name: public: virtual void CBSPPack::RemoveFileFromPack(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBSPPack::RemoveFileFromPack(CBSPPack *this, const char *relativename)
{
  IZip *PakFile; // eax

  PakFile = GetPakFile();
  RemoveFileFromPak(pak: PakFile, relativename);
}

//------------------------------------------------------------------------------
// Address: 0x10011BC0
// Name: public: virtual void CBSPPack::AddBufferToPackAndLZMACompress(char const __near *,void __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBSPPack::AddBufferToPackAndLZMACompress(
        CBSPPack *this,
        const char *relativename,
        unsigned __int8 *data,
        int length)
{
  unsigned __int8 *v4; // eax
  unsigned __int8 *v5; // esi
  IZip *PakFile; // eax
  IZip *v7; // eax
  unsigned __int8 *v8; // [esp-Ch] [ebp-1Ch]
  unsigned int v9; // [esp-8h] [ebp-18h]
  unsigned int compressedSize; // [esp+Ch] [ebp-4h] BYREF

  compressedSize = 0;
  v4 = LZMA_Compress(pInput: data, inputSize: length, pOutputSize: &compressedSize, dictionarySize: 0x12u);
  v5 = v4;
  if ( v4 != nullptr )
  {
    v9 = compressedSize;
    v8 = v4;
    PakFile = GetPakFile();
    AddBufferToPak(pak: PakFile, pRelativeName: relativename, data: v8, length: v9, bTextMode: false);
    free(pMem: v5);
  }
  else
  {
    v7 = GetPakFile();
    AddBufferToPak(pak: v7, pRelativeName: relativename, data, length, bTextMode: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011C30
// Name: public: virtual void CBSPPack::SetHDRMode(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBSPPack::SetHDRMode(CBSPPack *this, bool bHDR)
{
  SetHDRMode(bHDR);
}

//------------------------------------------------------------------------------
// Address: 0x10011C50
// Name: public: virtual bool CBSPPack::SwapBSPFile(class IFileSystem __near *,char const __near *,char const __near *,bool,bool (*)(char const __near *,class CUtlBuffer __near &,class CUtlBuffer __near &,bool (*)(class CUtlBuffer __near &,class CUtlBuffer __near &),bool),bool (*)(char const __near *,char const __near *,class CUtlBuffer __near &,class CUtlBuffer __near &),bool (*)(char const __near *,class CUtlBuffer __near &,class CUtlBuffer __near &),bool (*)(class CUtlBuffer __near &,class CUtlBuffer __near &),char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBSPPack::SwapBSPFile(
        CBSPPack *this,
        IFileSystem *pFileSystem,
        char *filename,
        const char *swapFilename,
        bool bSwapOnLoad,
        bool (__cdecl *pVTFConvertFunc)(const char *, CUtlBuffer *, CUtlBuffer *, bool (__cdecl *)(CUtlBuffer *, CUtlBuffer *), bool),
        bool (__cdecl *pVHVFixupFunc)(const char *, const char *, CUtlBuffer *, CUtlBuffer *),
        bool (__cdecl *pStudioConvertFunc)(const char *, CUtlBuffer *, CUtlBuffer *),
        bool (__cdecl *pCompressFunc)(CUtlBuffer *, CUtlBuffer *),
        char *szPlatform)
{
  g_pFullFileSystem = pFileSystem;
  if ( pFileSystem != nullptr )
    g_pFileSystem = &pFileSystem->IBaseFileSystem;
  else
    g_pFileSystem = nullptr;
  return SwapBSPFile(
           pInFilename: filename,
           pOutFilename: swapFilename,
           bSwapOnLoad,
           pVTFConvertFunc,
           pVHVFixupFunc,
           pStudioConvertFunc,
           pCompressFunc,
           szPlatform);
}

//------------------------------------------------------------------------------
// Address: 0x10011CA0
// Name: public: virtual bool CBSPPack::GetPakFileLump(class IFileSystem __near *,char const __near *,void __near * __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBSPPack::GetPakFileLump(
        CBSPPack *this,
        IFileSystem *pFileSystem,
        const char *pBSPFilename,
        void **pPakData,
        int *pPakSize)
{
  g_pFullFileSystem = pFileSystem;
  if ( pFileSystem != nullptr )
    g_pFileSystem = &pFileSystem->IBaseFileSystem;
  else
    g_pFileSystem = nullptr;
  return GetPakFileLump(pBSPFilename, (BSPHeader_t *)pPakData, pPakSize);
}

//------------------------------------------------------------------------------
// Address: 0x10011CE0
// Name: public: virtual bool CBSPPack::SetPakFileLump(class IFileSystem __near *,char const __near *,char const __near *,void __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CBSPPack::SetPakFileLump@<al>(
        CBSPPack *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        IFileSystem *pFileSystem,
        char *pBSPFilename,
        char *pNewFilename,
        void *pPakData,
        int pakSize)
{
  g_pFullFileSystem = pFileSystem;
  if ( pFileSystem != nullptr )
    g_pFileSystem = &pFileSystem->IBaseFileSystem;
  else
    g_pFileSystem = nullptr;
  return SetPakFileLump(a1: a2, a2: a3, pBSPFilename, pNewFilename, pPakData, pakSize);
}

//------------------------------------------------------------------------------
// Address: 0x10011D20
// Name: public: virtual bool CBSPPack::GetBSPDependants(class IFileSystem __near *,char const __near *,class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBSPPack::GetBSPDependants(
        CBSPPack *this,
        IFileSystem *pFileSystem,
        const char *pBSPFilename,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *pList)
{
  g_pFullFileSystem = pFileSystem;
  if ( pFileSystem != nullptr )
    g_pFileSystem = &pFileSystem->IBaseFileSystem;
  else
    g_pFileSystem = nullptr;
  return GetBSPDependants(pBSPFilename, pList);
}

//------------------------------------------------------------------------------
// Address: 0x10011D70
// Name: __CreateCBSPPackIBSPPack_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBSPPack *__cdecl _CreateCBSPPackIBSPPack_interface()
{
  return &_g_CBSPPack_singleton;
}
