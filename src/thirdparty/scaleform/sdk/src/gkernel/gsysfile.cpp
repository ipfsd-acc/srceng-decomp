// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gkernel/gsysfile.cpp
// Functions: 32
// ============================================================

#include "thirdparty\scaleform\sdk\src\gkernel\gsysfile.h"

//------------------------------------------------------------------------------
// Address: 0x1007E5B0
// Name: public: virtual bool GDelegatedFile::Close(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GDelegatedFile::Close(GDelegatedFile *this)
{
  return this->pFile.pObject->Close(this: this->pFile.pObject);
}

//------------------------------------------------------------------------------
// Address: 0x1007E5C0
// Name: public: virtual int GSysFile::GetErrorCode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GSysFile::GetErrorCode(GSysFile *this)
{
  GFile *pObject; // ecx

  pObject = this->pFile.pObject;
  if ( pObject != nullptr )
    return pObject->GetErrorCode(this: pObject);
  else
    return 4097;
}

//------------------------------------------------------------------------------
// Address: 0x1007E5E0
// Name: public: virtual char const __near * GDelegatedFile::GetFilePath(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GDelegatedFile::GetFilePath(MaterialLightingState_t *this)
{
  (*(void (__thiscall **)(_DWORD))(*(_DWORD *)LODWORD(this->m_vecAmbientCube[0].z) + 4))(a1: LODWORD(this->m_vecAmbientCube[0].z));
}

//------------------------------------------------------------------------------
// Address: 0x1007E5F0
// Name: public: virtual bool GDelegatedFile::IsValid(void)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolTable::CLess *__thiscall GDelegatedFile::IsValid(_DWORD *this)
{
  int v1; // ecx

  v1 = *(this + 2);
  return (CUtlSymbolTable::CLess *)(v1 != 0 && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v1 + 8))(a1: v1) != 0);
}

//------------------------------------------------------------------------------
// Address: 0x1007E610
// Name: public: virtual bool GDelegatedFile::IsWritable(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GDelegatedFile::IsWritable(GDelegatedFile *this)
{
  return this->pFile.pObject->IsWritable(this: this->pFile.pObject);
}

//------------------------------------------------------------------------------
// Address: 0x1007E620
// Name: public: virtual int GDelegatedFile::Tell(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GDelegatedFile::Tell(GDelegatedFile *this)
{
  return this->pFile.pObject->Tell(this: this->pFile.pObject);
}

//------------------------------------------------------------------------------
// Address: 0x1007E630
// Name: public: virtual __int64 GDelegatedFile::LTell(void)
// Source: json
//------------------------------------------------------------------------------
__int64 __thiscall GDelegatedFile::LTell(GDelegatedFile *this)
{
  return this->pFile.pObject->LTell(this: this->pFile.pObject);
}

//------------------------------------------------------------------------------
// Address: 0x1007E640
// Name: public: virtual int GDelegatedFile::GetLength(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GDelegatedFile::GetLength(GDelegatedFile *this)
{
  return this->pFile.pObject->GetLength(this: this->pFile.pObject);
}

//------------------------------------------------------------------------------
// Address: 0x1007E650
// Name: public: virtual __int64 GDelegatedFile::LGetLength(void)
// Source: json
//------------------------------------------------------------------------------
__int64 __thiscall GDelegatedFile::LGetLength(GDelegatedFile *this)
{
  return this->pFile.pObject->LGetLength(this: this->pFile.pObject);
}

//------------------------------------------------------------------------------
// Address: 0x1007E660
// Name: public: virtual int GDelegatedFile::GetErrorCode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GDelegatedFile::GetErrorCode(GDelegatedFile *this)
{
  return this->pFile.pObject->GetErrorCode(this: this->pFile.pObject);
}

//------------------------------------------------------------------------------
// Address: 0x1007E670
// Name: public: virtual int GDelegatedFile::Write(unsigned char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMaterial *),IMaterial *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *__thiscall GDelegatedFile::Write(
        _DWORD **this,
        CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMaterial *),IMaterial *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *result)
{
  return (*(CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMaterial *),IMaterial *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *(__thiscall **)(_DWORD, CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMaterial *),IMaterial *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *))(**(this + 2) + 36))(
           a1: *(this + 2),
           a2: result);
}

//------------------------------------------------------------------------------
// Address: 0x1007E680
// Name: public: virtual int GDelegatedFile::Read(unsigned char __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GDelegatedFile::Read(GDelegatedFile *this, unsigned __int8 *pbuffer, int numBytes)
{
  return this->pFile.pObject->Read(this: this->pFile.pObject, a2: pbuffer, a3: numBytes);
}

//------------------------------------------------------------------------------
// Address: 0x1007E690
// Name: public: virtual int GDelegatedFile::SkipBytes(int)
// Source: json
//------------------------------------------------------------------------------
const CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMaterial *),IMaterial *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *__thiscall GDelegatedFile::SkipBytes(
        _DWORD **this,
        const CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMaterial *),IMaterial *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *result)
{
  return (*(const CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMaterial *),IMaterial *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *(__thiscall **)(_DWORD, const CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMaterial *),IMaterial *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *))(**(this + 2) + 44))(
           a1: *(this + 2),
           a2: result);
}

//------------------------------------------------------------------------------
// Address: 0x1007E6A0
// Name: public: virtual int GDelegatedFile::BytesAvailable(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GDelegatedFile::BytesAvailable(GDelegatedFile *this)
{
  return this->pFile.pObject->BytesAvailable(this: this->pFile.pObject);
}

//------------------------------------------------------------------------------
// Address: 0x1007E6B0
// Name: public: virtual bool GDelegatedFile::Flush(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GDelegatedFile::Flush(GDelegatedFile *this)
{
  return this->pFile.pObject->Flush(this: this->pFile.pObject);
}

//------------------------------------------------------------------------------
// Address: 0x1007E6C0
// Name: public: virtual int GDelegatedFile::Seek(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GDelegatedFile::Seek(GDelegatedFile *this, int a2, int a3)
{
  return this->pFile.pObject->Seek(this: this->pFile.pObject, a2, a3);
}

//------------------------------------------------------------------------------
// Address: 0x1007E6D0
// Name: public: virtual __int64 GDelegatedFile::LSeek(__int64,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GDelegatedFile::LSeek(
        CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMaterial *),IMaterial *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this,
        const CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMaterial *),IMaterial *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *offset,
        int a3,
        int origin)
{
  (*((void (__thiscall **)(CRefCountServiceDestruct<CRefST>_vtbl *, const CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(IMaterial *),IMaterial *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *, int, int))this->dtr_CRefCountServiceDestruct<CRefST>
   + 15))(
    a1: this->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CRefCountServiceDestruct<CRefST>::__vftable,
    a2: offset,
    a3,
    a4: origin);
}

//------------------------------------------------------------------------------
// Address: 0x1007E6F0
// Name: public: virtual bool GDelegatedFile::ChangeSize(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GDelegatedFile::ChangeSize(IMatRenderContext *this, IMaterial *newSize)
{
  (*(void (__thiscall **)(_DWORD, IMaterial *))(**((_DWORD **)this + 2) + 64))(a1: *((_DWORD *)this + 2), a2: newSize);
}

//------------------------------------------------------------------------------
// Address: 0x1007E700
// Name: public: virtual int GDelegatedFile::CopyFromStream(class GFile __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GDelegatedFile::CopyFromStream(GDelegatedFile *this)
{
  return ((int (__thiscall *)(GFile *))this->pFile.pObject->CopyFromStream)(a1: this->pFile.pObject);
}

//------------------------------------------------------------------------------
// Address: 0x1007E710
// Name: public: virtual int GUnopenedFile::GetErrorCode(void)
// Source: json
//------------------------------------------------------------------------------
int GUnopenedFile::GetErrorCode()
{
  return 4097;
}

//------------------------------------------------------------------------------
// Address: 0x1007E7A0
// Name: public: bool GSysFile::Open(class GString const __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GSysFile::Open(GSysFile *this, CImagePacker *a2, int a3, int a4)
{
  char v4; // bl
  struct GFile *v6; // eax
  IShaderAPI *pObject; // ecx
  GFile *v8; // edi
  IClientMaterialSystem *v9; // eax
  GFile *v10; // edi
  IShaderAPI *v11; // ecx
  GFile *v13; // eax
  GFile *v14; // edi
  IShaderAPI *v15; // ecx

  v4 = a3;
  v6 = GFileFILEOpen(result: a2, flags: a3);
  pObject = (IShaderAPI *)this->pFile.pObject;
  v8 = v6;
  if ( pObject != nullptr )
    GRefCountImpl::Release(this: pObject);
  this->pFile.pObject = v8;
  if ( v8 != nullptr && v8->IsValid(this: v8) )
  {
    if ( (v4 & 0x20) != 0 )
    {
      a4 = 2;
      v9 = (IClientMaterialSystem *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 40, a3: &a4);
      if ( v9 != nullptr )
        v10 = (GFile *)GBufferedFile::GBufferedFile(this: v9, pfile: (const IClientMaterialSystem *)this->pFile.pObject);
      else
        v10 = nullptr;
      v11 = (IShaderAPI *)this->pFile.pObject;
      if ( v11 != nullptr )
        GRefCountImpl::Release(this: v11);
      this->pFile.pObject = v10;
    }
    return 1;
  }
  else
  {
    a3 = 2;
    v13 = (GFile *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 8, &a3);
    if ( v13 != nullptr )
    {
      v13->__vftable = (GFile_vtbl *)&GRefCountImplCore::`vftable';
      v13->RefCount = 1;
      v13->__vftable = (GFile_vtbl *)&GUnopenedFile::`vftable';
      v14 = v13;
    }
    else
    {
      v14 = nullptr;
    }
    v15 = (IShaderAPI *)this->pFile.pObject;
    if ( v15 != nullptr )
      GRefCountImpl::Release(this: v15);
    this->pFile.pObject = v14;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007E880
// Name: public: virtual bool GSysFile::Close(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GSysFile::Close(IShaderAPI **this)
{
  IShaderAPI *v2; // eax
  IShaderAPI *v3; // edi
  IShaderAPI *v4; // ecx
  int v6; // [esp+4h] [ebp-4h] BYREF

  if ( ((unsigned __int8 (__thiscall *)(IShaderAPI **))(*this)[2].__vftable)(a1: this) == 0 )
    return 0;
  (*(this + 2))->InFlashlightMode(this: *(this + 2));
  v6 = 2;
  v2 = (IShaderAPI *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 8, a3: &v6);
  if ( v2 != nullptr )
  {
    v2->__vftable = (IShaderAPI_vtbl *)&GRefCountImplCore::`vftable';
    v2[1].__vftable = (IShaderAPI_vtbl *)1;
    v2->__vftable = (IShaderAPI_vtbl *)&GUnopenedFile::`vftable';
    v3 = v2;
  }
  else
  {
    v3 = nullptr;
  }
  v4 = *(this + 2);
  if ( v4 != nullptr )
    GRefCountImpl::Release(this: v4);
  *(this + 2) = v3;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1007E900
// Name: public: GSysFile::GSysFile(class GString const __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
GSysFile *__thiscall GSysFile::GSysFile(GSysFile *this, CImagePacker *a2, int flags, int mode)
{
  this->__vftable = (GSysFile_vtbl *)&GRefCountImplCore::`vftable';
  this->RefCount = 1;
  this->pFile.pObject = nullptr;
  this->__vftable = (GSysFile_vtbl *)&GSysFile::`vftable';
  GSysFile::Open(this, a2, a3: flags, a4: mode);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101DDFF7
// Name: public: long D3DXCore::CFile::Open(void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall D3DXCore::CFile::Open(HANDLE *this, LPCWCH lpWideCharStr, int a3)
{
  const wchar_t *v3; // ebx
  char *v6; // eax
  HANDLE FileW; // eax
  HANDLE FileMappingA; // eax
  DWORD FileSize; // eax
  LPVOID v10; // eax
  unsigned int cbMultiByte; // [esp+Ch] [ebp-A4h]
  char *pMem; // [esp+14h] [ebp-9Ch]
  _OSVERSIONINFOA VersionInformation; // [esp+18h] [ebp-98h] BYREF

  v3 = lpWideCharStr;
  pMem = nullptr;
  if ( lpWideCharStr == nullptr )
    return -2005530516;
  if ( a3 == 0 )
    goto LABEL_10;
  VersionInformation.dwOSVersionInfoSize = 148;
  GetVersionExA(lpVersionInformation: &VersionInformation);
  if ( VersionInformation.dwPlatformId != 2 )
  {
    cbMultiByte = WideCharToMultiByte(
                    CodePage: 0xFDE9u,
                    dwFlags: 0,
                    lpWideCharStr,
                    cchWideChar: -1,
                    lpMultiByteStr: nullptr,
                    cbMultiByte: 0,
                    lpDefaultChar: nullptr,
                    lpUsedDefaultChar: nullptr);
    v6 = (char *)MemAlloc_Alloc(nSize: cbMultiByte);
    pMem = v6;
    if ( v6 == nullptr )
      return -2147024882;
    WideCharToMultiByte(
      CodePage: 0xFDE9u,
      dwFlags: 0,
      lpWideCharStr,
      cchWideChar: -1,
      lpMultiByteStr: v6,
      cbMultiByte,
      lpDefaultChar: nullptr,
      lpUsedDefaultChar: nullptr);
    a3 = 0;
    v3 = (const wchar_t *)pMem;
  }
  if ( a3 != 0 )
    FileW = CreateFileW(
              lpFileName: v3,
              dwDesiredAccess: 0x80000000,
              dwShareMode: 1u,
              lpSecurityAttributes: nullptr,
              dwCreationDisposition: 3u,
              dwFlagsAndAttributes: 0x10000000u,
              hTemplateFile: nullptr);
  else
LABEL_10:
    FileW = CreateFileA(
              lpFileName: (LPCSTR)v3,
              dwDesiredAccess: 0x80000000,
              dwShareMode: 1u,
              lpSecurityAttributes: nullptr,
              dwCreationDisposition: 3u,
              dwFlagsAndAttributes: 0x10000000u,
              hTemplateFile: nullptr);
  *this = FileW;
  free(pMem);
  if ( *this == (HANDLE)-1 )
    goto LABEL_16;
  FileMappingA = CreateFileMappingA(
                   hFile: *this,
                   lpFileMappingAttributes: nullptr,
                   flProtect: 2u,
                   dwMaximumSizeHigh: 0,
                   dwMaximumSizeLow: 0,
                   lpName: nullptr);
  *(this + 1) = FileMappingA;
  if ( FileMappingA == (HANDLE)-1 )
    goto LABEL_16;
  FileSize = GetFileSize(hFile: *this, lpFileSizeHigh: nullptr);
  *(this + 3) = (HANDLE)FileSize;
  if ( FileSize == -1 )
    goto LABEL_16;
  if ( FileSize != 0 )
  {
    v10 = MapViewOfFile(
            hFileMappingObject: *(this + 1),
            dwDesiredAccess: 4u,
            dwFileOffsetHigh: 0,
            dwFileOffsetLow: 0,
            dwNumberOfBytesToMap: 0);
    *(this + 2) = v10;
    if ( v10 == nullptr )
    {
LABEL_16:
      GetLastError();
      return -2005529767;
    }
  }
  else
  {
    *(this + 2) = nullptr;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101DE161
// Name: public: long D3DXCore::CFile::Close(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXCore::CFile::Close(D3DXCore::CFile *this)
{
  if ( *((_DWORD *)this + 2) != 0 )
  {
    UnmapViewOfFile(lpBaseAddress: *((LPCVOID *)this + 2));
    *((_DWORD *)this + 2) = 0;
    *((_DWORD *)this + 3) = 0;
  }
  if ( *((_DWORD *)this + 1) != -1 )
  {
    CloseHandle(hObject: *((HANDLE *)this + 1));
    *((_DWORD *)this + 1) = -1;
  }
  if ( *(_DWORD *)this != -1 )
  {
    CloseHandle(hObject: *(HANDLE *)this);
    *(_DWORD *)this = -1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101DE1A4
// Name: public: D3DXCore::CFile::~CFile(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall D3DXCore::CFile::~CFile(D3DXCore::CFile *this)
{
  if ( *(_DWORD *)this != -1 )
    D3DXCore::CFile::Close(this);
}

//------------------------------------------------------------------------------
// Address: 0x101DE1AF
// Name: public: D3DXCore::CAlloc::CAlloc(unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
D3DXCore::CAlloc *__thiscall D3DXCore::CAlloc::CAlloc(D3DXCore::CAlloc *this, unsigned int a2, unsigned int a3)
{
  unsigned int dwPageSize; // ecx
  unsigned int v5; // eax
  unsigned int v6; // ecx
  _SYSTEM_INFO SystemInfo; // [esp+4h] [ebp-24h] BYREF

  *(_DWORD *)this = 0;
  GetSystemInfo(lpSystemInfo: &SystemInfo);
  dwPageSize = SystemInfo.dwPageSize;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 1) = dwPageSize;
  v5 = ~(dwPageSize - 1) & (dwPageSize + a3 - 1);
  v6 = a2;
  *((_DWORD *)this + 1) = v5;
  if ( a2 == 0 )
    v6 = 0x100000;
  *((_DWORD *)this + 5) = ~(v5 - 1) & (v5 + v6 - 1);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101DE207
// Name: public: D3DXCore::CAlloc::~CAlloc(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall D3DXCore::CAlloc::~CAlloc(D3DXCore::CAlloc *this)
{
  _DWORD *v2; // [esp-Ch] [ebp-10h]

  while ( *(_DWORD *)this != 0 )
  {
    v2 = *(_DWORD **)this;
    *(_DWORD *)this = **(_DWORD **)this;
    VirtualFree(lpAddress: v2, dwSize: 0, dwFreeType: 0x8000u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DE229
// Name: public: unsigned char __near * D3DXCore::CAlloc::Alloc(unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall D3DXCore::CAlloc::Alloc(D3DXCore::CAlloc *this, unsigned int a2, SIZE_T dwSize)
{
  int v4; // edx
  unsigned int v5; // ecx
  unsigned int v6; // edi
  bool v7; // cc
  SIZE_T v8; // ebx
  int v9; // eax
  unsigned int v11; // ecx
  _DWORD *lpAddress; // [esp+Ch] [ebp-4h]
  SIZE_T dwSizea; // [esp+1Ch] [ebp+Ch]

  v4 = *((_DWORD *)this + 2);
  v5 = ~(dwSize - 1);
  v6 = a2 + (v5 & (dwSize + v4 - 1));
  if ( v6 <= *((_DWORD *)this + 4) )
  {
    v11 = *((_DWORD *)this + 3);
    if ( v6 > v11 )
    {
      v8 = ~(*((_DWORD *)this + 1) - 1) & (*((_DWORD *)this + 1) + v6 - 1);
      if ( VirtualAlloc(
             lpAddress: (LPVOID)(v11 + *(_DWORD *)this),
             dwSize: v8 - v11,
             flAllocationType: 0x1000u,
             flProtect: 4u) == nullptr )
        return nullptr;
LABEL_8:
      *((_DWORD *)this + 3) = v8;
    }
    v9 = *(_DWORD *)this - a2;
    *((_DWORD *)this + 2) = v6;
    return (unsigned __int8 *)(v6 + v9);
  }
  v6 = a2 + (v5 & (dwSize + 3));
  dwSizea = *((_DWORD *)this + 5);
  if ( v6 > dwSizea )
  {
    do
    {
      v7 = v6 <= 2 * dwSizea;
      dwSizea *= 2;
    }
    while ( !v7 );
  }
  lpAddress = VirtualAlloc(lpAddress: nullptr, dwSize: dwSizea, flAllocationType: 0x2000u, flProtect: 4u);
  if ( lpAddress == nullptr )
    return nullptr;
  v8 = ~(*((_DWORD *)this + 1) - 1) & (*((_DWORD *)this + 1) + v6 - 1);
  if ( VirtualAlloc(lpAddress, dwSize: v8, flAllocationType: 0x1000u, flProtect: 4u) != nullptr )
  {
    *lpAddress = *(_DWORD *)this;
    *(_DWORD *)this = lpAddress;
    *((_DWORD *)this + 4) = dwSizea;
    goto LABEL_8;
  }
  VirtualFree(lpAddress, dwSize: 0, dwFreeType: 0x8000u);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101DE313
// Name: public: D3DXShader::CNode::CNode(enum D3DXShader::_D3DXNODE_TYPE)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXShader::CNode::CNode(_DWORD *this, int a2)
{
  *(this + 2) = 0;
  *(this + 3) = 0;
  *this = &D3DXShader::CNode::`vftable';
  *(this + 1) = a2;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101DE332
// Name: public: virtual int D3DXShader::CNode::IsEqual(class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CNode *__thiscall D3DXShader::CNode::IsEqual(D3DXShader::CNode *this, struct D3DXShader::CNode *a2)
{
  struct D3DXShader::CNode *result; // eax

  result = a2;
  if ( a2 != nullptr )
    return (struct D3DXShader::CNode *)(*((_DWORD *)this + 1) == *((_DWORD *)a2 + 1));
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101DE34D
// Name: public: static int D3DXShader::CNode::IsEqual(class D3DXShader::CNode __near *,class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
static int __stdcall D3DXShader::CNode::IsEqual(struct D3DXShader::CNode *a1, struct D3DXShader::CNode *a2)
{
  if ( a1 != nullptr )
    return (**(int (__thiscall ***)(struct D3DXShader::CNode *, struct D3DXShader::CNode *))a1)(a1, a2);
  else
    return a2 == nullptr;
}
