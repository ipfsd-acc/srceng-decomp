// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/xbox/makegamedata/makemodels.cpp
// Functions: 47
// ============================================================

#include "utils\xbox\makegamedata\makemodels.h"

//------------------------------------------------------------------------------
// Address: 0x00408C20
// Name: bool CaselessStringLessThan(char const __near * const __near &,char const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CaselessStringLessThan(const char **lhs, const char **rhs)
{
  if ( *lhs == nullptr )
    return false;
  if ( *rhs != nullptr )
    return _V_stricmp(s1: *lhs, s2: *rhs) < 0;
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x00408C50
// Name: bool Studio_ConvertStudioHdrToNewVersion(struct studiohdr_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl Studio_ConvertStudioHdrToNewVersion(studiohdr_t *pStudioHdr)
{
  int v2; // ebx
  int v4; // edx
  int v5; // ecx
  unsigned __int8 *v6; // edi
  int k; // edx
  int v8; // ecx
  char *v9; // ecx
  int m; // edi
  int v11; // ecx
  char *v12; // ecx
  int v13; // edx
  int j; // edx
  int v15; // ecx
  char *v16; // ecx
  int version; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]
  char bResult_3; // [esp+1Bh] [ebp+Bh]

  v2 = pStudioHdr->version;
  version = v2;
  if ( v2 == 49 )
    return 1;
  bResult_3 = 1;
  if ( v2 < 46 )
  {
    v4 = 0;
    for ( i = 0; v4 < pStudioHdr->numlocalanim; i = v4 )
    {
      v5 = v4;
      if ( v4 < 0 || v4 >= pStudioHdr->numlocalanim )
        v5 = 0;
      v6 = (unsigned __int8 *)pStudioHdr + 100 * v5 + pStudioHdr->localanimindex;
      if ( *((_DWORD *)v6 + 21) != 0 )
      {
        memset(dst: v6 + 16, value: 0, count: 0x54u);
        v4 = i;
        *((_DWORD *)v6 + 4) = 1;
        v2 = version;
        *((_DWORD *)v6 + 13) = -1;
        bResult_3 = 0;
      }
      ++v4;
    }
  }
  if ( v2 >= 47 )
  {
    if ( v2 == 47 )
    {
      for ( j = 0; j < pStudioHdr->numlocalanim; ++j )
      {
        v15 = j;
        if ( j < 0 || j >= pStudioHdr->numlocalanim )
          v15 = 0;
        v16 = (char *)pStudioHdr + 100 * v15 + pStudioHdr->localanimindex;
        if ( *((_DWORD *)v16 + 23) != 0 )
        {
          *((_DWORD *)v16 + 23) = 0;
          *((_WORD *)v16 + 44) = 0;
          bResult_3 = 0;
        }
      }
      goto LABEL_20;
    }
  }
  else
  {
    if ( pStudioHdr->unused4 != 0 )
    {
      pStudioHdr->unused4 = 0;
      bResult_3 = 0;
    }
    for ( k = 0; k < pStudioHdr->numlocalanim; *((_WORD *)v9 + 44) = 0 )
    {
      v8 = k;
      if ( k < 0 || k >= pStudioHdr->numlocalanim )
        v8 = 0;
      v9 = (char *)pStudioHdr + 100 * v8 + pStudioHdr->localanimindex;
      ++k;
      *((_DWORD *)v9 + 23) = 0;
    }
  }
  if ( v2 < 49 )
  {
LABEL_20:
    for ( m = 0; m < pStudioHdr->numlocalanim; ++m )
    {
      v11 = m;
      if ( m < 0 || m >= pStudioHdr->numlocalanim )
        v11 = 0;
      v12 = (char *)pStudioHdr + 100 * v11 + pStudioHdr->localanimindex;
      v13 = *((_DWORD *)v12 + 3);
      if ( (v13 & 0x40) != 0 )
      {
        *((_DWORD *)v12 + 3) = v13 & 0xFFFFFFBF;
        bResult_3 = 0;
      }
    }
  }
  pStudioHdr->version = 49;
  return bResult_3;
}

//------------------------------------------------------------------------------
// Address: 0x00408DD0
// Name: bool InitStudioByteSwap(void)
// Source: json
//------------------------------------------------------------------------------
char __cdecl InitStudioByteSwap()
{
  StudioByteSwap::SetVerbose(bVerbose: false);
  StudioByteSwap::ActivateByteSwapping(activate: true);
  StudioByteSwap::SetCollisionInterface(pPhysicsCollision: g_pPhysicsCollision);
  StudioByteSwap::SourceIsNative(bNative: true);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00408E00
// Name: bool CompressFunc(void const __near *,int,void __near * __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CompressFunc(unsigned __int8 *pInput, unsigned int inputSize, void **pOutput, int *pOutputSize)
{
  void **v4; // esi
  int *v5; // edi
  unsigned __int8 *v6; // eax

  v4 = pOutput;
  v5 = pOutputSize;
  *pOutput = nullptr;
  *v5 = 0;
  if ( inputSize == 0 )
    return 0;
  v6 = LZMA_Compress(pInput, inputSize, pOutputSize: (unsigned int *)&pOutput, dictionarySize: 0x12u);
  if ( v6 == nullptr )
    return 0;
  *v4 = v6;
  *v5 = (int)pOutput;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00408E50
// Name: bool CompressFuncANIStub(void const __near *,int,void __near * __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CompressFuncANIStub(const void *pInput, int inputSize, void **pOutput, int *pOutputSize)
{
  *pOutput = nullptr;
  *pOutputSize = 0;
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x00408E70
// Name: ModelNeedsUpdate
// Source: json
//------------------------------------------------------------------------------
char __cdecl ModelNeedsUpdate(const char *pMdlSourcePath)
{
  unsigned int v2; // edi
  bool *p_bSourceMustExist; // esi
  char szSourcePath[260]; // [esp+4h] [ebp-2D8h] BYREF
  char szTargetPath[260]; // [esp+108h] [ebp-1D4h] BYREF
  _stat64i32 sourceStatBuf; // [esp+20Ch] [ebp-D0h] BYREF
  _stat64i32 targetStatBuf; // [esp+23Ch] [ebp-A0h] BYREF
  ModelNeedsUpdate::__l2::ModelExtensions_t pExtensions[7]; // [esp+26Ch] [ebp-70h] BYREF

  pExtensions[1].pSourceExtension = ".dx90.vtx";
  pExtensions[5].pSourceExtension = ".dx90.vtx";
  pExtensions[0].pSourceExtension = ".mdl";
  pExtensions[0].pXboxTargetExtension = ".360.mdl";
  pExtensions[0].pPS3TargetExtension = ".ps3.mdl";
  pExtensions[0].bSourceMustExist = true;
  pExtensions[1].pXboxTargetExtension = ".dx90.360.vtx";
  pExtensions[1].pPS3TargetExtension = ".dx90.ps3.vtx";
  pExtensions[1].bSourceMustExist = false;
  pExtensions[2].pSourceExtension = ".vvd";
  pExtensions[2].pXboxTargetExtension = ".360.vvd";
  pExtensions[2].pPS3TargetExtension = ".ps3.vvd";
  pExtensions[2].bSourceMustExist = false;
  pExtensions[3].pSourceExtension = ".phy";
  pExtensions[3].pXboxTargetExtension = ".360.phy";
  pExtensions[3].pPS3TargetExtension = ".ps3.phy";
  pExtensions[3].bSourceMustExist = false;
  pExtensions[4].pSourceExtension = ".ani";
  pExtensions[4].pXboxTargetExtension = ".360.ani";
  pExtensions[4].pPS3TargetExtension = ".ps3.ani";
  pExtensions[4].bSourceMustExist = false;
  pExtensions[5].pXboxTargetExtension = "360.vsi";
  pExtensions[5].pPS3TargetExtension = "ps3.vsi";
  pExtensions[5].bSourceMustExist = false;
  pExtensions[6].pSourceExtension = ".vvd";
  pExtensions[6].pXboxTargetExtension = "360.vsi";
  pExtensions[6].pPS3TargetExtension = "ps3.vsi";
  pExtensions[6].bSourceMustExist = false;
  if ( g_bForce )
    return 1;
  v2 = 0;
  p_bSourceMustExist = &pExtensions[0].bSourceMustExist;
  do
  {
    V_strncpy(pDest: szSourcePath, pSrc: pMdlSourcePath, maxLen: 260);
    V_SetExtension(path: szSourcePath, extension: *((const char **)p_bSourceMustExist - 3), pathStringLength: 260);
    if ( _stat64i32(name: szSourcePath, buf: &sourceStatBuf) != 0 )
    {
      if ( *p_bSourceMustExist )
        return 1;
    }
    else
    {
      V_strncpy(pDest: szTargetPath, pSrc: pMdlSourcePath, maxLen: 260);
      if ( g_bSonyPS3 )
        V_SetExtension(path: szTargetPath, extension: *((const char **)p_bSourceMustExist - 1), pathStringLength: 260);
      else
        V_SetExtension(path: szTargetPath, extension: *((const char **)p_bSourceMustExist - 2), pathStringLength: 260);
      if ( _stat64i32(name: szTargetPath, buf: &targetStatBuf) != 0
        || _difftime64(b: sourceStatBuf.st_mtime, a: targetStatBuf.st_mtime) > 0.0 )
      {
        return 1;
      }
    }
    ++v2;
    p_bSourceMustExist += 16;
  }
  while ( v2 < 7 );
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00409030
// Name: ModelNamesLessFunc
// Source: json
//------------------------------------------------------------------------------
bool __cdecl ModelNamesLessFunc(CUtlString *pLHS, CUtlString *pRHS)
{
  const char *v2; // esi
  const char *v3; // eax

  v2 = CUtlString::operator char const *(this: pRHS);
  v3 = CUtlString::operator char const *(this: pLHS);
  if ( v3 == nullptr )
    return false;
  if ( v2 != nullptr )
    return _V_stricmp(s1: v3, s2: v2) < 0;
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x00409220
// Name: bool GetPreloadData_VHV(char const __near *,class CUtlBuffer __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl GetPreloadData_VHV(const char *pFilename, CUtlBuffer *fileBufferIn, CUtlBuffer *preloadBufferOut)
{
  unsigned __int32 v3; // edi

  v3 = _byteswap_ulong(*(_DWORD *)fileBufferIn->m_Memory.m_pMemory);
  preloadBufferOut->m_Get = 0;
  preloadBufferOut->m_Put = 0;
  preloadBufferOut->m_nOffset = 0;
  preloadBufferOut->m_nMaxPut = 0;
  preloadBufferOut->m_Error = 0;
  if ( preloadBufferOut->m_Memory.m_nGrowSize >= 0 )
  {
    if ( preloadBufferOut->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: preloadBufferOut->m_Memory.m_pMemory);
      preloadBufferOut->m_Memory.m_pMemory = nullptr;
    }
    preloadBufferOut->m_Memory.m_nAllocationCount = 0;
  }
  if ( v3 == 2 )
  {
    CUtlBuffer::Put(this: preloadBufferOut, pMem: fileBufferIn->m_Memory.m_pMemory, size: 40);
    return 1;
  }
  else
  {
    _Warning(a1: "Can't preload: '%s', expecting version %d got version %d\n", pFilename, 2, v3);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004092B0
// Name: bool GetPreloadData_VTX(char const __near *,class CUtlBuffer __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl GetPreloadData_VTX(const char *pFilename, CUtlBuffer *fileBufferIn, CUtlBuffer *preloadBufferOut)
{
  unsigned __int32 v3; // edi

  v3 = _byteswap_ulong(*(_DWORD *)fileBufferIn->m_Memory.m_pMemory);
  preloadBufferOut->m_Get = 0;
  preloadBufferOut->m_Put = 0;
  preloadBufferOut->m_nOffset = 0;
  preloadBufferOut->m_nMaxPut = 0;
  preloadBufferOut->m_Error = 0;
  if ( preloadBufferOut->m_Memory.m_nGrowSize >= 0 )
  {
    if ( preloadBufferOut->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: preloadBufferOut->m_Memory.m_pMemory);
      preloadBufferOut->m_Memory.m_pMemory = nullptr;
    }
    preloadBufferOut->m_Memory.m_nAllocationCount = 0;
  }
  if ( v3 == 7 )
  {
    CUtlBuffer::Put(this: preloadBufferOut, pMem: fileBufferIn->m_Memory.m_pMemory, size: 36);
    return 1;
  }
  else
  {
    _Warning(a1: "Can't preload: '%s', expecting version %d got version %d\n", pFilename, 7, v3);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409340
// Name: bool GetPreloadData_VVD(char const __near *,class CUtlBuffer __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl GetPreloadData_VVD(const char *pFilename, CUtlBuffer *fileBufferIn, CUtlBuffer *preloadBufferOut)
{
  unsigned __int32 v3; // edi
  unsigned __int32 v4; // ecx
  unsigned __int32 v6; // [esp+Ch] [ebp-4h]

  v3 = _byteswap_ulong(*(_DWORD *)fileBufferIn->m_Memory.m_pMemory);
  v4 = _byteswap_ulong(*((_DWORD *)fileBufferIn->m_Memory.m_pMemory + 1));
  v6 = v4;
  preloadBufferOut->m_Get = 0;
  preloadBufferOut->m_Put = 0;
  preloadBufferOut->m_nOffset = 0;
  preloadBufferOut->m_nMaxPut = 0;
  preloadBufferOut->m_Error = 0;
  if ( preloadBufferOut->m_Memory.m_nGrowSize >= 0 )
  {
    if ( preloadBufferOut->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: preloadBufferOut->m_Memory.m_pMemory);
      v4 = v6;
      preloadBufferOut->m_Memory.m_pMemory = nullptr;
    }
    preloadBufferOut->m_Memory.m_nAllocationCount = 0;
  }
  if ( v3 == 1448297545 )
  {
    if ( v4 == 4 )
    {
      CUtlBuffer::Put(this: preloadBufferOut, pMem: fileBufferIn->m_Memory.m_pMemory, size: 64);
      return 1;
    }
    else
    {
      _Warning(a1: "Can't preload: '%s', expecting version %d got version %d\n", pFilename, 4, v4);
      return 0;
    }
  }
  else
  {
    _Warning(a1: "Can't preload: '%s', expecting id %d got id %d\n", pFilename, 1448297545, v3);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409410
// Name: public: virtual char const __near * CJob::Describe(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CJob::Describe(CJob *this)
{
  return "Job";
}

//------------------------------------------------------------------------------
// Address: 0x00409420
// Name: private: virtual int CJob::DoAbort(bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CJob::DoAbort(CJob *this, bool bDiscard)
{
  return 3;
}

//------------------------------------------------------------------------------
// Address: 0x00409440
// Name: public: virtual int CRefCounted1<class IRefCounted,class CRefCountServiceBase<1,class CRefMT>>::AddRef(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT>>::AddRef(
        CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> > *this)
{
  return _InterlockedIncrement(&this->m_iRefs);
}

//------------------------------------------------------------------------------
// Address: 0x00409450
// Name: public: virtual int CRefCounted1<class IRefCounted,class CRefCountServiceBase<1,class CRefMT>>::Release(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT>>::Release(
        CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> > *this)
{
  CRefCountServiceBase<1,CRefMT> *v1; // esi
  int result; // eax

  v1 = &this->CRefCountServiceBase<1,CRefMT>;
  result = _InterlockedDecrement(&this->m_iRefs);
  if ( result == 0 )
  {
    if ( v1->OnFinalRelease(this: v1) )
      ((void (__thiscall *)(CRefCountServiceBase<1,CRefMT> *, int))v1->dtr_CRefCountServiceBase<1,CRefMT>)(
        a1: v1,
        a2: 1);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00409C80
// Name: GenerateModelFiles
// Source: json
//------------------------------------------------------------------------------
modelProcessResult_e __usercall GenerateModelFiles@<eax>(const char *pMdlFilename@<eax>)
{
  modelProcessResult_e result; // eax
  char v3; // bl
  char v4; // al
  bool v5; // al
  int v6; // eax
  int v7; // edi
  int m_Put; // ebx
  int v9; // edi
  int v10; // edi
  int v11; // ebx
  int v12; // edi
  int v13; // ebx
  int v14; // edi
  int v15; // ebx
  int v16; // edi
  int v17; // ebx
  int v18; // esi
  char szVsiFilename[260]; // [esp+8h] [ebp-770h] BYREF
  char szMdlFilename[260]; // [esp+10Ch] [ebp-66Ch] BYREF
  char szVtxFilename[260]; // [esp+210h] [ebp-568h] BYREF
  char szAniFilename[260]; // [esp+314h] [ebp-464h] BYREF
  char szVvdFilename[260]; // [esp+418h] [ebp-360h] BYREF
  char szPhyFilename[260]; // [esp+51Ch] [ebp-25Ch] BYREF
  CUtlBuffer vsiBuffer; // [esp+620h] [ebp-158h] BYREF
  CUtlBuffer phyBuffer; // [esp+650h] [ebp-128h] BYREF
  CUtlBuffer aniBuffer; // [esp+680h] [ebp-F8h] BYREF
  CUtlBuffer vtxBuffer; // [esp+6B0h] [ebp-C8h] BYREF
  CUtlBuffer vvdBuffer; // [esp+6E0h] [ebp-98h] BYREF
  CUtlBuffer tempBuffer; // [esp+710h] [ebp-68h] BYREF
  CUtlBuffer mdlBuffer; // [esp+740h] [ebp-38h] BYREF
  IMdlStripInfo *pStripInfo; // [esp+770h] [ebp-8h] BYREF
  bool bHasVvd; // [esp+776h] [ebp-2h]
  bool bHasVtx; // [esp+777h] [ebp-1h]

  CUtlBuffer::CUtlBuffer(this: &tempBuffer, growSize: 0, initSize: 0, nFlags: 0);
  _Msg(a1: "Processing: %s\n", pMdlFilename);
  CUtlBuffer::CUtlBuffer(this: &mdlBuffer, growSize: 0, initSize: 0, nFlags: 0);
  if ( !ReadFileToBuffer(pSourceName: pMdlFilename, buffer: &mdlBuffer, bText: false, bNoOpenFailureWarning: false) )
  {
    _Warning(a1: "Failed to read file: %s\n", pMdlFilename);
    if ( mdlBuffer.m_Memory.m_nGrowSize >= 0 )
    {
      if ( mdlBuffer.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: mdlBuffer.m_Memory.m_pMemory);
        mdlBuffer.m_Memory.m_pMemory = nullptr;
      }
      mdlBuffer.m_Memory.m_nAllocationCount = 0;
    }
    if ( tempBuffer.m_Memory.m_nGrowSize >= 0 && tempBuffer.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tempBuffer.m_Memory.m_pMemory);
    return MODELPROCESS_READFILE_ERROR;
  }
  if ( Studio_ConvertStudioHdrToNewVersion(pStudioHdr: (studiohdr_t *)mdlBuffer.m_Memory.m_pMemory) == 0 )
    _Warning(a1: "%s needs to be recompiled\n", pMdlFilename);
  V_StripExtension(in: pMdlFilename, out: szVtxFilename, outSize: 260);
  V_strncat(pDest: szVtxFilename, pSrc: ".dx90.vtx", destBufferSize: 0x104u, max_chars_to_copy: -1);
  CUtlBuffer::CUtlBuffer(this: &vtxBuffer, growSize: 0, initSize: 0, nFlags: 0);
  v3 = ReadFileToBuffer(pSourceName: szVtxFilename, buffer: &vtxBuffer, bText: false, bNoOpenFailureWarning: true);
  bHasVtx = v3;
  V_StripExtension(in: pMdlFilename, out: szVvdFilename, outSize: 260);
  V_strncat(pDest: szVvdFilename, pSrc: ".vvd", destBufferSize: 0x104u, max_chars_to_copy: -1);
  CUtlBuffer::CUtlBuffer(this: &vvdBuffer, growSize: 0, initSize: 0, nFlags: 0);
  v4 = ReadFileToBuffer(pSourceName: szVvdFilename, buffer: &vvdBuffer, bText: false, bNoOpenFailureWarning: true);
  bHasVvd = v4;
  if ( v3 != v4 )
  {
    if ( vvdBuffer.m_Memory.m_nGrowSize >= 0 )
    {
      if ( vvdBuffer.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: vvdBuffer.m_Memory.m_pMemory);
        vvdBuffer.m_Memory.m_pMemory = nullptr;
      }
      vvdBuffer.m_Memory.m_nAllocationCount = 0;
    }
    if ( vtxBuffer.m_Memory.m_nGrowSize >= 0 )
    {
      if ( vtxBuffer.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: vtxBuffer.m_Memory.m_pMemory);
        vtxBuffer.m_Memory.m_pMemory = nullptr;
      }
      vtxBuffer.m_Memory.m_nAllocationCount = 0;
    }
    if ( mdlBuffer.m_Memory.m_nGrowSize >= 0 )
    {
      if ( mdlBuffer.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: mdlBuffer.m_Memory.m_pMemory);
        mdlBuffer.m_Memory.m_pMemory = nullptr;
      }
      mdlBuffer.m_Memory.m_nAllocationCount = 0;
    }
    if ( tempBuffer.m_Memory.m_nGrowSize >= 0 && tempBuffer.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tempBuffer.m_Memory.m_pMemory);
    return MODELPROCESS_VTXVVD_MISMATCH;
  }
  if ( v3 != 0 && v4 != 0 )
  {
    pStripInfo = nullptr;
    if ( g_bSonyPS3 )
      v5 = mdllib->PrepareModelForPs3(this: mdllib, a2: &mdlBuffer, a3: &vvdBuffer, a4: &vtxBuffer, a5: &pStripInfo);
    else
      v5 = mdllib->StripModelBuffers(this: mdllib, a2: &mdlBuffer, a3: &vvdBuffer, a4: &vtxBuffer, a5: &pStripInfo);
    if ( !v5 )
    {
      CUtlMemory<unsigned char,int>::~CUtlMemory<unsigned char,int>(this: &vvdBuffer);
      CUtlMemory<unsigned char,int>::~CUtlMemory<unsigned char,int>(this: &vtxBuffer);
      CUtlMemory<unsigned char,int>::~CUtlMemory<unsigned char,int>(this: &mdlBuffer);
      CUtlMemory<unsigned char,int>::~CUtlMemory<unsigned char,int>(this: &tempBuffer);
      return MODELPROCESS_LOD_CULL_ERROR;
    }
    if ( pStripInfo != nullptr )
    {
      CUtlBuffer::CUtlBuffer(this: &vsiBuffer, growSize: 0, initSize: 0, nFlags: 0);
      pStripInfo->Serialize(this: pStripInfo, a2: &vsiBuffer);
      pStripInfo->DeleteThis(this: pStripInfo);
      V_StripExtension(in: pMdlFilename, out: szVsiFilename, outSize: 260);
      if ( g_bSonyPS3 )
        V_strncat(pDest: szVsiFilename, pSrc: ".ps3.vsi", destBufferSize: 0x104u, max_chars_to_copy: -1);
      else
        V_strncat(pDest: szVsiFilename, pSrc: ".360.vsi", destBufferSize: 0x104u, max_chars_to_copy: -1);
      WriteBufferToFile(
        pTargetName: szVsiFilename,
        buffer: &vsiBuffer,
        bWriteToZip: false,
        writeMode: WRITE_TO_DISK_ALWAYS);
      CUtlMemory<unsigned char,int>::~CUtlMemory<unsigned char,int>(this: &vsiBuffer);
    }
  }
  V_StripExtension(in: pMdlFilename, out: szAniFilename, outSize: 260);
  V_strncat(pDest: szAniFilename, pSrc: ".ani", destBufferSize: 0x104u, max_chars_to_copy: -1);
  CUtlBuffer::CUtlBuffer(this: &aniBuffer, growSize: 0, initSize: 0, nFlags: 0);
  if ( ReadFileToBuffer(pSourceName: szAniFilename, buffer: &aniBuffer, bText: false, bNoOpenFailureWarning: true) )
  {
    v6 = *((_DWORD *)mdlBuffer.m_Memory.m_pMemory + 88);
    if ( v6 != 0 )
    {
      v7 = 2 * (aniBuffer.m_Put + (v6 << 10));
      m_Put = aniBuffer.m_Put;
      CUtlBuffer::EnsureCapacity(this: &aniBuffer, num: v7);
      CUtlBuffer::EnsureCapacity(this: &tempBuffer, num: v7);
      V_StripExtension(in: pMdlFilename, out: szAniFilename, outSize: 260);
      if ( g_bSonyPS3 )
        V_strncat(pDest: szAniFilename, pSrc: ".ps3.ani", destBufferSize: 0x104u, max_chars_to_copy: -1);
      else
        V_strncat(pDest: szAniFilename, pSrc: ".360.ani", destBufferSize: 0x104u, max_chars_to_copy: -1);
      v9 = StudioByteSwap::ByteswapStudioFile(
             pFilename: szAniFilename,
             pOutBase: tempBuffer.m_Memory.m_pMemory,
             outBaseSize: v7,
             pFileBase: &aniBuffer.m_Memory.m_pMemory[aniBuffer.m_Get - aniBuffer.m_nOffset],
             fileSize: m_Put,
             pHdr: (studiohdr_t *)mdlBuffer.m_Memory.m_pMemory,
             pCompressFunc: CompressFuncANIStub);
      if ( v9 <= 0 )
      {
LABEL_69:
        CUtlMemory<unsigned char,int>::~CUtlMemory<unsigned char,int>(this: &aniBuffer);
        CUtlMemory<unsigned char,int>::~CUtlMemory<unsigned char,int>(this: &vvdBuffer);
        CUtlMemory<unsigned char,int>::~CUtlMemory<unsigned char,int>(this: &vtxBuffer);
        CUtlMemory<unsigned char,int>::~CUtlMemory<unsigned char,int>(this: &mdlBuffer);
        CUtlMemory<unsigned char,int>::~CUtlMemory<unsigned char,int>(this: &tempBuffer);
        if ( v9 == -1 )
          return MODELPROCESS_ALIGNMENT_ERROR;
        return MODELPROCESS_BYTESWAP_ERROR;
      }
      CUtlBuffer::Purge(this: &aniBuffer);
      CUtlBuffer::Put(this: &aniBuffer, pMem: tempBuffer.m_Memory.m_pMemory, size: v9);
      WriteBufferToFile(
        pTargetName: szAniFilename,
        buffer: &aniBuffer,
        bWriteToZip: false,
        writeMode: WRITE_TO_DISK_ALWAYS);
      v3 = bHasVtx;
    }
  }
  V_StripExtension(in: pMdlFilename, out: szPhyFilename, outSize: 260);
  V_strncat(pDest: szPhyFilename, pSrc: ".phy", destBufferSize: 0x104u, max_chars_to_copy: -1);
  CUtlBuffer::CUtlBuffer(this: &phyBuffer, growSize: 0, initSize: 0, nFlags: 0);
  if ( ReadFileToBuffer(pSourceName: szPhyFilename, buffer: &phyBuffer, bText: false, bNoOpenFailureWarning: true) )
  {
    v10 = phyBuffer.m_Put + 4096;
    v11 = phyBuffer.m_Put;
    CUtlBuffer::EnsureCapacity(this: &phyBuffer, num: phyBuffer.m_Put + 4096);
    CUtlBuffer::EnsureCapacity(this: &tempBuffer, num: v10);
    V_StripExtension(in: pMdlFilename, out: szPhyFilename, outSize: 260);
    if ( g_bSonyPS3 )
      V_strncat(pDest: szPhyFilename, pSrc: ".ps3.phy", destBufferSize: 0x104u, max_chars_to_copy: -1);
    else
      V_strncat(pDest: szPhyFilename, pSrc: ".360.phy", destBufferSize: 0x104u, max_chars_to_copy: -1);
    v9 = StudioByteSwap::ByteswapStudioFile(
           pFilename: szPhyFilename,
           pOutBase: tempBuffer.m_Memory.m_pMemory,
           outBaseSize: v10,
           pFileBase: &phyBuffer.m_Memory.m_pMemory[phyBuffer.m_Get - phyBuffer.m_nOffset],
           fileSize: v11,
           pHdr: (studiohdr_t *)mdlBuffer.m_Memory.m_pMemory,
           pCompressFunc: (bool (__cdecl *)(const void *, int, void **, int *))CompressFunc);
    if ( v9 <= 0 )
      goto LABEL_68;
    CUtlBuffer::Purge(this: &phyBuffer);
    CUtlBuffer::Put(this: &phyBuffer, pMem: tempBuffer.m_Memory.m_pMemory, size: v9);
    WriteBufferToFile(
      pTargetName: szPhyFilename,
      buffer: &phyBuffer,
      bWriteToZip: false,
      writeMode: WRITE_TO_DISK_ALWAYS);
    v3 = bHasVtx;
  }
  if ( v3 == 0 )
    goto LABEL_60;
  v12 = vtxBuffer.m_Put + 4096;
  v13 = vtxBuffer.m_Put;
  CUtlBuffer::EnsureCapacity(this: &vtxBuffer, num: vtxBuffer.m_Put + 4096);
  CUtlBuffer::EnsureCapacity(this: &tempBuffer, num: v12);
  V_StripExtension(in: pMdlFilename, out: szVtxFilename, outSize: 260);
  if ( g_bSonyPS3 )
    V_strncat(pDest: szVtxFilename, pSrc: ".dx90.ps3.vtx", destBufferSize: 0x104u, max_chars_to_copy: -1);
  else
    V_strncat(pDest: szVtxFilename, pSrc: ".dx90.360.vtx", destBufferSize: 0x104u, max_chars_to_copy: -1);
  v9 = StudioByteSwap::ByteswapStudioFile(
         pFilename: szVtxFilename,
         pOutBase: tempBuffer.m_Memory.m_pMemory,
         outBaseSize: v12,
         pFileBase: &vtxBuffer.m_Memory.m_pMemory[vtxBuffer.m_Get - vtxBuffer.m_nOffset],
         fileSize: v13,
         pHdr: (studiohdr_t *)mdlBuffer.m_Memory.m_pMemory,
         pCompressFunc: (bool (__cdecl *)(const void *, int, void **, int *))CompressFunc);
  if ( v9 <= 0 )
  {
LABEL_68:
    CUtlMemory<unsigned char,int>::~CUtlMemory<unsigned char,int>(this: &phyBuffer);
    goto LABEL_69;
  }
  CUtlBuffer::Purge(this: &vtxBuffer);
  CUtlBuffer::Put(this: &vtxBuffer, pMem: tempBuffer.m_Memory.m_pMemory, size: v9);
  WriteBufferToFile(pTargetName: szVtxFilename, buffer: &vtxBuffer, bWriteToZip: false, writeMode: WRITE_TO_DISK_ALWAYS);
LABEL_60:
  if ( !bHasVvd )
    goto LABEL_66;
  v14 = vvdBuffer.m_Put + 4096;
  v15 = vvdBuffer.m_Put;
  CUtlBuffer::EnsureCapacity(this: &vvdBuffer, num: vvdBuffer.m_Put + 4096);
  CUtlBuffer::EnsureCapacity(this: &tempBuffer, num: v14);
  V_StripExtension(in: pMdlFilename, out: szVvdFilename, outSize: 260);
  if ( g_bSonyPS3 )
    V_strncat(pDest: szVvdFilename, pSrc: ".ps3.vvd", destBufferSize: 0x104u, max_chars_to_copy: -1);
  else
    V_strncat(pDest: szVvdFilename, pSrc: ".360.vvd", destBufferSize: 0x104u, max_chars_to_copy: -1);
  v9 = StudioByteSwap::ByteswapStudioFile(
         pFilename: szVvdFilename,
         pOutBase: tempBuffer.m_Memory.m_pMemory,
         outBaseSize: v14,
         pFileBase: &vvdBuffer.m_Memory.m_pMemory[vvdBuffer.m_Get - vvdBuffer.m_nOffset],
         fileSize: v15,
         pHdr: (studiohdr_t *)mdlBuffer.m_Memory.m_pMemory,
         pCompressFunc: (bool (__cdecl *)(const void *, int, void **, int *))CompressFunc);
  if ( v9 <= 0 )
    goto LABEL_68;
  CUtlBuffer::Purge(this: &vvdBuffer);
  CUtlBuffer::Put(this: &vvdBuffer, pMem: tempBuffer.m_Memory.m_pMemory, size: v9);
  WriteBufferToFile(pTargetName: szVvdFilename, buffer: &vvdBuffer, bWriteToZip: false, writeMode: WRITE_TO_DISK_ALWAYS);
LABEL_66:
  v16 = mdlBuffer.m_Put + 4096;
  v17 = mdlBuffer.m_Put;
  CUtlBuffer::EnsureCapacity(this: &mdlBuffer, num: mdlBuffer.m_Put + 4096);
  CUtlBuffer::EnsureCapacity(this: &tempBuffer, num: v16);
  V_StripExtension(in: pMdlFilename, out: szMdlFilename, outSize: 260);
  if ( g_bSonyPS3 )
    V_strncat(pDest: szMdlFilename, pSrc: ".ps3.mdl", destBufferSize: 0x104u, max_chars_to_copy: -1);
  else
    V_strncat(pDest: szMdlFilename, pSrc: ".360.mdl", destBufferSize: 0x104u, max_chars_to_copy: -1);
  v18 = StudioByteSwap::ByteswapStudioFile(
          pFilename: szMdlFilename,
          pOutBase: tempBuffer.m_Memory.m_pMemory,
          outBaseSize: v16,
          pFileBase: &mdlBuffer.m_Memory.m_pMemory[mdlBuffer.m_Get - mdlBuffer.m_nOffset],
          fileSize: v17,
          pHdr: nullptr,
          pCompressFunc: (bool (__cdecl *)(const void *, int, void **, int *))CompressFunc);
  if ( v18 > 0 )
  {
    CUtlBuffer::Purge(this: &mdlBuffer);
    CUtlBuffer::Put(this: &mdlBuffer, pMem: tempBuffer.m_Memory.m_pMemory, size: v18);
    WriteBufferToFile(
      pTargetName: szMdlFilename,
      buffer: &mdlBuffer,
      bWriteToZip: false,
      writeMode: WRITE_TO_DISK_ALWAYS);
    CUtlMemory<unsigned char,int>::~CUtlMemory<unsigned char,int>(this: &phyBuffer);
    CUtlMemory<unsigned char,int>::~CUtlMemory<unsigned char,int>(this: &aniBuffer);
    CUtlMemory<unsigned char,int>::~CUtlMemory<unsigned char,int>(this: &vvdBuffer);
    CUtlMemory<unsigned char,int>::~CUtlMemory<unsigned char,int>(this: &vtxBuffer);
    CUtlMemory<unsigned char,int>::~CUtlMemory<unsigned char,int>(this: &mdlBuffer);
    CUtlMemory<unsigned char,int>::~CUtlMemory<unsigned char,int>(this: &tempBuffer);
    return MODELPROCESS_SUCCESS;
  }
  CUtlMemory<unsigned char,int>::~CUtlMemory<unsigned char,int>(this: &phyBuffer);
  CUtlMemory<unsigned char,int>::~CUtlMemory<unsigned char,int>(this: &aniBuffer);
  CUtlMemory<unsigned char,int>::~CUtlMemory<unsigned char,int>(this: &vvdBuffer);
  CUtlMemory<unsigned char,int>::~CUtlMemory<unsigned char,int>(this: &vtxBuffer);
  CUtlMemory<unsigned char,int>::~CUtlMemory<unsigned char,int>(this: &mdlBuffer);
  CUtlMemory<unsigned char,int>::~CUtlMemory<unsigned char,int>(this: &tempBuffer);
  result = MODELPROCESS_ALIGNMENT_ERROR;
  if ( v18 != -1 )
    return MODELPROCESS_BYTESWAP_ERROR;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040A5C0
// Name: public: virtual int CModelPreprocessJob::DoExecute(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CModelPreprocessJob::DoExecute(CModelPreprocessJob *this)
{
  const char *m_szMdlFilename; // eax

  if ( this->m_bDone || (m_szMdlFilename = this->m_szMdlFilename) == nullptr )
    this->m_result = MODELPROCESS_THREADING_ERROR;
  else
    this->m_result = GenerateModelFiles(pMdlFilename: m_szMdlFilename);
  this->m_bDone = true;
  if ( _InterlockedDecrement(&CModelPreprocessJob::s_nTotalModelsLeft.m_value) <= 0 )
    CThreadEvent::Set(this: &CModelPreprocessJob::s_AllDone);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040AB50
// Name: bool CreateTargetFile_Model(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CreateTargetFile_Model(const char *pSourceName, const char *pTargetName, bool bWriteToZip)
{
  bool v4; // bl
  CUtlBuffer targetBuffer; // [esp+4h] [ebp-30h] BYREF

  CUtlBuffer::CUtlBuffer(this: &targetBuffer, growSize: 0, initSize: 0, nFlags: 0);
  if ( ReadFileToBuffer(pSourceName: pTargetName, buffer: &targetBuffer, bText: false, bNoOpenFailureWarning: false) )
  {
    v4 = WriteBufferToFile(pTargetName, buffer: &targetBuffer, bWriteToZip, writeMode: WRITE_TO_DISK_NEVER);
    if ( targetBuffer.m_Memory.m_nGrowSize >= 0 && targetBuffer.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: targetBuffer.m_Memory.m_pMemory);
    return v4;
  }
  else
  {
    if ( targetBuffer.m_Memory.m_nGrowSize >= 0 && targetBuffer.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: targetBuffer.m_Memory.m_pMemory);
    return false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040AC50
// Name: bool GetDependants_MDL(char const __near *,class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
char __usercall GetDependants_MDL@<al>(
        int a1@<edi>,
        const char *pModelName,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *pList)
{
  unsigned __int8 *m_pMemory; // esi
  int v5; // ebx
  int v6; // edi
  int v7; // ebx
  int v8; // eax
  char v9; // cl
  bool v10; // zf
  _BYTE *v11; // eax
  _BYTE v12[2]; // [esp+0h] [ebp-24Eh] BYREF
  char szPath[260]; // [esp+2h] [ebp-24Ch] BYREF
  char szOutName[260]; // [esp+106h] [ebp-148h] BYREF
  CUtlBuffer sourceBuf; // [esp+20Ah] [ebp-44h] BYREF
  CUtlString src; // [esp+23Ah] [ebp-14h] BYREF
  int i; // [esp+24Ah] [ebp-4h]

  if ( g_bModPathIsValid )
  {
    CUtlBuffer::CUtlBuffer(this: &sourceBuf, growSize: 0, initSize: 0, nFlags: 0);
    if ( ((unsigned __int8 (__thiscall *)(IBaseFileSystem *, const char *, const char *, CUtlBuffer *, _DWORD, _DWORD, _DWORD, int))g_pFullFileSystem->ReadFile)(
           a1: &g_pFullFileSystem->IBaseFileSystem,
           a2: pModelName,
           a3: "GAME",
           a4: &sourceBuf,
           a5: 0,
           a6: 0,
           a7: 0,
           a8: a1) != 0 )
    {
      m_pMemory = sourceBuf.m_Memory.m_pMemory;
      Studio_ConvertStudioHdrToNewVersion(pStudioHdr: (studiohdr_t *)sourceBuf.m_Memory.m_pMemory);
      if ( *((_DWORD *)m_pMemory + 1) == 49 )
      {
        if ( (*((_DWORD *)m_pMemory + 38) & 0x200) != 0 )
        {
          V_strncpy(pDest: szOutName, pSrc: "materials/sprites/obsolete.vmt", maxLen: 260);
          V_FixSlashes(pname: szOutName, separator: 92);
          CUtlString::CUtlString(this: &src, pString: szOutName);
          CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(this: pList, elem: pList->m_Size, &src);
          CUtlString::~CUtlString(this: &src);
        }
        else if ( *((_DWORD *)m_pMemory + 52) != 0 )
        {
          v5 = 0;
          for ( i = 0; v5 < *((_DWORD *)m_pMemory + 51); i = v5 )
          {
            v6 = 0;
            if ( *((int *)m_pMemory + 53) > 0 )
            {
              v7 = v5 << 6;
              while ( 1 )
              {
                V_ComposeFileName(
                  path: "materials",
                  filename: (const char *)&m_pMemory[*(_DWORD *)&m_pMemory[4 * v6 + *((_DWORD *)m_pMemory + 54)]],
                  dest: szPath,
                  destSize: 260);
                v8 = &szPath[strlen(szPath) + 1] - &szPath[1];
                if ( v8 > 2 && v12[v8] == 92 )
                {
                  v10 = v12[v8 + 1] == 92;
                  v11 = &v12[v8 + 1];
                  if ( v10 )
                    *v11 = v9;
                }
                V_ComposeFileName(
                  path: szPath,
                  filename: (const char *)&m_pMemory[v7
                                         + *((_DWORD *)m_pMemory + 52)
                                         + *(_DWORD *)&m_pMemory[v7 + *((_DWORD *)m_pMemory + 52)]],
                  dest: szOutName,
                  destSize: 260);
                V_SetExtension(path: szOutName, extension: ".vmt", pathStringLength: 260);
                if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: szOutName, a3: "GAME") )
                  break;
                if ( ++v6 >= *((_DWORD *)m_pMemory + 53) )
                  goto LABEL_30;
              }
              CUtlString::CUtlString(this: &src, pString: szOutName);
              CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(this: pList, elem: pList->m_Size, &src);
              src.m_Storage.m_nActualLength = 0;
              if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 )
              {
                if ( src.m_Storage.m_Memory.m_pMemory != nullptr )
                {
                  _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
                  src.m_Storage.m_Memory.m_pMemory = nullptr;
                }
                src.m_Storage.m_Memory.m_nAllocationCount = 0;
              }
            }
LABEL_30:
            v5 = i + 1;
          }
        }
        if ( sourceBuf.m_Memory.m_nGrowSize >= 0 && sourceBuf.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sourceBuf.m_Memory.m_pMemory);
        return 1;
      }
      else
      {
        _Warning(
          a1: "Error! Bad Model '%s', Expecting Version (%d), got (%d)\n",
          pModelName,
          49,
          *((_DWORD *)m_pMemory + 1));
        if ( sourceBuf.m_Memory.m_nGrowSize >= 0 && sourceBuf.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sourceBuf.m_Memory.m_pMemory);
        return 0;
      }
    }
    else
    {
      _Warning(a1: "Error! Couldn't open file '%s'!\n", pModelName);
      if ( sourceBuf.m_Memory.m_nGrowSize >= 0 && sourceBuf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sourceBuf.m_Memory.m_pMemory);
      return 0;
    }
  }
  else
  {
    _Warning(a1: "Indeterminate mod path, Cannot determine MDL dependants for %s\n", pModelName);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040B0A0
// Name: helper_PreprocessModelFilesThreaded
// Source: json
//------------------------------------------------------------------------------
void __usercall helper_PreprocessModelFilesThreaded(
        unsigned int numthreads@<eax>,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *updatelist)
{
  unsigned int v3; // ecx
  int m_Size; // esi
  int v5; // ecx
  char *v6; // eax
  int v7; // ebx
  CModelPreprocessJob *v8; // edi
  CThreadEvent *v9; // esi
  int v10; // ebx
  int v11; // edi
  bool *p_m_bDone; // esi
  CModelPreprocessJob *v13; // edi
  int i; // ebx
  IThreadPool *v15; // edi
  modelProcessResult_e *p_m_result; // edi
  int j; // ebx
  int v18; // eax
  int v19; // esi
  errorList_t *m_pMemory; // ecx
  int v21; // eax
  unsigned int v22; // esi
  ThreadPoolStartParams_t LocalThreadPoolParams; // [esp+Ch] [ebp-120h] BYREF
  int count; // [esp+120h] [ebp-Ch]
  IThreadPool *pLocalThreadPool; // [esp+124h] [ebp-8h]
  CModelPreprocessJob *pModelJobs; // [esp+128h] [ebp-4h]

  pLocalThreadPool = (IThreadPool *)_CreateNewThreadPool();
  v3 = numthreads;
  LocalThreadPoolParams.nThreads = numthreads;
  LocalThreadPoolParams.fDistribute = TRS_NONE;
  LocalThreadPoolParams.nStackSize = -1;
  LocalThreadPoolParams.iThreadPriority = -32768;
  *((_BYTE *)&LocalThreadPoolParams + 272) &= 0xFCu;
  if ( (*((_BYTE *)&LocalThreadPoolParams + 272) & 2) != 0 )
  {
    if ( numthreads > 0x40 )
      v3 = 64;
    if ( v3 != 0 )
      qmemcpy(LocalThreadPoolParams.iAffinityTable, nullptr, 4 * v3);
  }
  m_Size = updatelist->m_Size;
  v5 = (60 * (unsigned __int64)(unsigned int)m_Size) >> 32 != 0;
  count = m_Size;
  v6 = (char *)MemAlloc_Alloc(nSize: __CFADD__((60 * m_Size) | -v5, 4) ? -1 : ((60 * m_Size) | -v5) + 4);
  if ( v6 != nullptr )
  {
    v7 = m_Size - 1;
    v8 = (CModelPreprocessJob *)(v6 + 4);
    *(_DWORD *)v6 = m_Size;
    pModelJobs = (CModelPreprocessJob *)(v6 + 4);
    if ( m_Size - 1 >= 0 )
    {
      v9 = (CThreadEvent *)(v6 + 28);
      do
      {
        v9[-2].m_hSyncObject = (void *)1;
        v8->CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::IRefCounted::__vftable = (CModelPreprocessJob_vtbl *)&CJob::`vftable'{for `IRefCounted'};
        *(_DWORD *)&v9[-3].m_bCreatedHandle = &CJob::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
        *(_DWORD *)&v9[-2].m_bCreatedHandle = 4;
        v9[-1].m_hSyncObject = (void *)1;
        *(_DWORD *)&v9[-1].m_bCreatedHandle = 0;
        v9->m_hSyncObject = nullptr;
        *(_DWORD *)&v9[1].m_bCreatedHandle = 0;
        *(_WORD *)&v9->m_bCreatedHandle = -256;
        v9[1].m_hSyncObject = (void *)-1;
        CThreadEvent::CThreadEvent(this: v9 + 2, a2: true);
        v8->CJob::CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT> >::IRefCounted::__vftable = (CModelPreprocessJob_vtbl *)&CModelPreprocessJob::`vftable'{for `IRefCounted'};
        *(_DWORD *)&v9[-3].m_bCreatedHandle = &CModelPreprocessJob::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
        v9[3].m_hSyncObject = nullptr;
        *(_DWORD *)&v9[3].m_bCreatedHandle = 1;
        LOBYTE(v9[4].m_hSyncObject) = 0;
        ++v8;
        v9 = (CThreadEvent *)((char *)v9 + 60);
        --v7;
      }
      while ( v7 >= 0 );
      m_Size = count;
      v8 = pModelJobs;
    }
    pModelJobs = v8;
  }
  else
  {
    pModelJobs = nullptr;
  }
  if ( m_Size > 0 )
  {
    v10 = count;
    v11 = 0;
    p_m_bDone = &pModelJobs->m_bDone;
    do
    {
      *((_DWORD *)p_m_bDone - 2) = CUtlString::operator char const *(this: &updatelist->m_Memory.m_pMemory[v11]);
      *p_m_bDone = false;
      ++v11;
      p_m_bDone += 60;
      --v10;
    }
    while ( v10 != 0 );
    m_Size = count;
  }
  _InterlockedExchange(&CModelPreprocessJob::s_nTotalModelsLeft.m_value, m_Size);
  CThreadEvent::Reset(this: &CModelPreprocessJob::s_AllDone);
  pLocalThreadPool->Start_2(this: pLocalThreadPool, a2: &LocalThreadPoolParams);
  if ( m_Size > 0 )
  {
    v13 = pModelJobs;
    for ( i = m_Size; i != 0; --i )
      pLocalThreadPool->AddJob(this: pLocalThreadPool, a2: v13++);
  }
  if ( !CThreadEvent::Wait(this: &CModelPreprocessJob::s_AllDone, a2: 0xFFFFFFFF) )
  {
    _Warning(a1: "Somehow timed out or abandoned the model process job queue!\n");
    if ( (unsigned __int8)_Plat_IsInDebugSession() != 0 )
      __debugbreak();
  }
  if ( pLocalThreadPool->GetJobCount(this: pLocalThreadPool) != 0 )
  {
    _Warning(a1: "Threaded model preprocess somehow ended before all jobs were finished!\n");
    if ( (unsigned __int8)_Plat_IsInDebugSession() != 0 )
      __debugbreak();
  }
  v15 = pLocalThreadPool;
  pLocalThreadPool->SuspendExecution(this: pLocalThreadPool);
  if ( m_Size > 0 )
  {
    p_m_result = &pModelJobs->m_result;
    for ( j = m_Size; j != 0; --j )
    {
      if ( *((_BYTE *)p_m_result + 4) == 0 || *p_m_result != MODELPROCESS_SUCCESS )
      {
        v18 = g_errorList.m_Size;
        v19 = g_errorList.m_Size;
        if ( g_errorList.m_Size + 1 > g_errorList.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int>>,int>::Grow(
            this: (CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> *)&g_errorList,
            num: g_errorList.m_Size - g_errorList.m_Memory.m_nAllocationCount + 1);
          v18 = g_errorList.m_Size;
        }
        m_pMemory = g_errorList.m_Memory.m_pMemory;
        g_errorList.m_Size = v18 + 1;
        v21 = v18 - v19;
        g_errorList.m_pElements = g_errorList.m_Memory.m_pMemory;
        if ( v21 > 0 )
        {
          _V_memmove(
            dest: &g_errorList.m_Memory.m_pMemory[v19 + 1],
            src: &g_errorList.m_Memory.m_pMemory[v19],
            count: 20 * v21);
          m_pMemory = g_errorList.m_Memory.m_pMemory;
        }
        v22 = v19;
        if ( &m_pMemory[v22] != nullptr )
        {
          CUtlString::CUtlString(this: &m_pMemory[v22].fileName);
          m_pMemory = g_errorList.m_Memory.m_pMemory;
        }
        m_pMemory[v22].result = *p_m_result;
        CUtlString::Set(this: &g_errorList.m_Memory.m_pMemory[v22].fileName, pValue: *((const char **)p_m_result - 1));
      }
      p_m_result += 15;
    }
    v15 = pLocalThreadPool;
  }
  if ( pModelJobs != nullptr )
  {
    if ( *(_DWORD *)&pModelJobs[-1].m_bDone != 0 )
    {
      ((void (__thiscall *)(CRefCountServiceBase<1,CRefMT> *, int))pModelJobs->dtr_CRefCountServiceBase<1,CRefMT>)(
        a1: &pModelJobs->CRefCountServiceBase<1,CRefMT>,
        a2: 3);
      _DestroyThreadPool(a1: v15);
      return;
    }
    free(pMem: &pModelJobs[-1].m_bDone);
  }
  _DestroyThreadPool(a1: v15);
}

//------------------------------------------------------------------------------
// Address: 0x0040B410
// Name: bool PreprocessModelFiles(class CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl PreprocessModelFiles(CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *fileList)
{
  int m_Size; // ebx
  int v2; // eax
  char v3; // cl
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *v4; // eax
  const char *v5; // eax
  char *v6; // eax
  bool v7; // bl
  char *v8; // esi
  int v9; // eax
  char v10; // cl
  unsigned int v11; // eax
  char *v12; // edi
  char v13; // cl
  int v14; // eax
  int v15; // eax
  signed int v16; // esi
  int v17; // ecx
  int i; // eax
  CUtlString *v19; // edi
  const char *v20; // eax
  modelProcessResult_e ModelFiles; // ebx
  int v22; // eax
  int v23; // esi
  errorList_t *m_pMemory; // ecx
  int v25; // eax
  unsigned int v26; // esi
  const char *v27; // eax
  int v28; // ecx
  int v29; // edi
  int v30; // esi
  const char *v31; // eax
  int v33; // [esp+0h] [ebp-4B8h] BYREF
  char szFullSourcePath[260]; // [esp+Ch] [ebp-4ACh] BYREF
  char szCleanName[260]; // [esp+110h] [ebp-3A8h] BYREF
  _SYSTEM_INFO info; // [esp+214h] [ebp-2A4h] BYREF
  char szSourcePath[260]; // [esp+238h] [ebp-280h] BYREF
  char szModelName[260]; // [esp+33Ch] [ebp-17Ch] BYREF
  CUtlRBTree<CUtlString,int,bool (__cdecl*)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int> > visitedModels; // [esp+440h] [ebp-78h] BYREF
  CUtlString insert; // [esp+464h] [ebp-54h] BYREF
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > updateList; // [esp+474h] [ebp-44h] BYREF
  CUtlString search; // [esp+488h] [ebp-30h] BYREF
  unsigned __int64 v43; // [esp+498h] [ebp-20h]
  __int64 v44; // [esp+4A0h] [ebp-18h]
  int *v45; // [esp+4A8h] [ebp-10h]
  int v46; // [esp+4B4h] [ebp-4h]

  v45 = &v33;
  StudioByteSwap::SetVerbose(bVerbose: false);
  StudioByteSwap::ActivateByteSwapping(activate: true);
  StudioByteSwap::SetCollisionInterface(pPhysicsCollision: g_pPhysicsCollision);
  StudioByteSwap::SourceIsNative(bNative: true);
  memset(&updateList, 0, sizeof(updateList));
  m_Size = 0;
  visitedModels.m_LessFunc = (bool (__cdecl *)(const CUtlString *, const CUtlString *))ModelNamesLessFunc;
  memset(&visitedModels.m_Elements, 0, sizeof(visitedModels.m_Elements));
  visitedModels.m_Root = -1;
  visitedModels.m_NumElements = 0;
  visitedModels.m_FirstFree = -1;
  visitedModels.m_LastAlloc.index = -1;
  visitedModels.m_pElements = nullptr;
  v2 = 0;
  do
  {
    v3 = g_szSourcePath[v2];
    szSourcePath[v2++] = v3;
  }
  while ( v3 != 0 );
  V_StripFilename(path: szSourcePath);
  if ( szSourcePath[0] == 0 )
    strcpy(szSourcePath, ".");
  V_AppendSlash(pStr: szSourcePath, strSize: 260);
  HIDWORD(v44) = 0;
  v4 = fileList;
  if ( fileList->m_Size > 0 )
  {
    HIDWORD(v43) = 0;
    do
    {
      v5 = CUtlString::operator char const *(this: (CUtlString *)((char *)&v4->m_Memory.m_pMemory->fileName
                                                                + HIDWORD(v43)));
      V_strncpy(pDest: szModelName, pSrc: v5, maxLen: 260);
      if ( V_stristr(pStr: szModelName, pSearch: ".360.") == nullptr
        && V_stristr(pStr: szModelName, pSearch: ".ps3.") == nullptr )
      {
        v6 = V_stristr(pStr: szModelName, pSearch: ".mdl");
        if ( v6 != nullptr
          || (v6 = V_stristr(pStr: szModelName, pSearch: ".dx90.vtx")) != nullptr
          || (v6 = V_stristr(pStr: szModelName, pSearch: ".vvd")) != nullptr
          || (v6 = V_stristr(pStr: szModelName, pSearch: ".ani")) != nullptr
          || (v6 = V_stristr(pStr: szModelName, pSearch: ".phy")) != nullptr
          || (v6 = V_stristr(pStr: szModelName, pSearch: ".vsi")) != nullptr
          || (v6 = V_stristr(pStr: szModelName, pSearch: ".phz")) != nullptr )
        {
          *v6 = 0;
          V_strncat(pDest: szModelName, pSrc: ".mdl", destBufferSize: 0x104u, max_chars_to_copy: -1);
          CUtlString::CUtlString(this: &search, pString: szModelName);
          v7 = CUtlRBTree<CUtlString,int,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int>>::Find(
                 this: &visitedModels,
                 &search) != -1;
          search.m_Storage.m_nActualLength = 0;
          if ( search.m_Storage.m_Memory.m_nGrowSize >= 0 )
          {
            if ( search.m_Storage.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: search.m_Storage.m_Memory.m_pMemory);
              search.m_Storage.m_Memory.m_pMemory = nullptr;
            }
            search.m_Storage.m_Memory.m_nAllocationCount = 0;
          }
          if ( !v7 )
          {
            CUtlString::CUtlString(this: &insert, pString: szModelName);
            CUtlRBTree<CUtlString,int,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int>>::Insert(
              this: &visitedModels,
              &insert);
            insert.m_Storage.m_nActualLength = 0;
            if ( insert.m_Storage.m_Memory.m_nGrowSize >= 0 )
            {
              if ( insert.m_Storage.m_Memory.m_pMemory != nullptr )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: insert.m_Storage.m_Memory.m_pMemory);
                insert.m_Storage.m_Memory.m_pMemory = nullptr;
              }
              insert.m_Storage.m_Memory.m_nAllocationCount = 0;
            }
            v8 = szModelName;
            if ( V_strncasecmp(s1: szModelName, s2: asc_58D3CC, n: 2) != 0 )
            {
              if ( V_strncasecmp(s1: szModelName, s2: szSourcePath, n: strlen(szSourcePath)) == 0 )
                v8 = &szModelName[strlen(szSourcePath)];
            }
            else
            {
              v8 = &szModelName[2];
            }
            v9 = 0;
            do
            {
              v10 = szSourcePath[v9];
              szCleanName[v9++] = v10;
            }
            while ( v10 != 0 );
            v11 = strlen(v8) + 1;
            v12 = &szFullSourcePath[259];
            do
              v13 = *++v12;
            while ( v13 != 0 );
            qmemcpy(v12, v8, v11);
            _fullpath(UserBuf: szFullSourcePath, path: szCleanName, maxlen: 0x104u);
            if ( ModelNeedsUpdate(pMdlSourcePath: szFullSourcePath) != 0 )
            {
              v14 = CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
                      this: &updateList,
                      elem: updateList.m_Size);
              CUtlString::Set(this: &updateList.m_Memory.m_pMemory[v14], pValue: szFullSourcePath);
            }
          }
        }
      }
      ++HIDWORD(v44);
      HIDWORD(v43) += 24;
      v4 = fileList;
    }
    while ( SHIDWORD(v44) < fileList->m_Size );
    m_Size = updateList.m_Size;
  }
  _Msg(a1: "\n");
  v15 = _CommandLine();
  v16 = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v15 + 28))(a1: v15, a2: "-threads", a3: 0);
  if ( v16 == 0 )
  {
    GetSystemInfo(lpSystemInfo: &info);
    v16 = info.dwNumberOfProcessors - 1;
  }
  if ( v16 < 2 || m_Size < v16 )
  {
    _Msg(a1: "Model Pre Pass: Updating %d Models. (singlethreaded)\n", m_Size);
    HIDWORD(v44) = &search.m_Storage.m_Memory.m_nGrowSize;
    *(_QWORD *)&search.m_Storage.m_Memory.m_nGrowSize = __rdtsc();
    for ( i = 0; ; i = HIDWORD(v43) + 1 )
    {
      HIDWORD(v43) = i;
      if ( i >= updateList.m_Size )
        break;
      v46 = 0;
      v19 = &updateList.m_Memory.m_pMemory[i];
      v20 = CUtlString::operator char const *(this: v19);
      ModelFiles = GenerateModelFiles(pMdlFilename: v20);
      if ( ModelFiles != MODELPROCESS_SUCCESS )
      {
        v22 = g_errorList.m_Size;
        v23 = g_errorList.m_Size;
        if ( g_errorList.m_Size + 1 > g_errorList.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int>>,int>::Grow(
            this: (CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> *)&g_errorList,
            num: g_errorList.m_Size - g_errorList.m_Memory.m_nAllocationCount + 1);
          v22 = g_errorList.m_Size;
        }
        g_errorList.m_Size = v22 + 1;
        m_pMemory = g_errorList.m_Memory.m_pMemory;
        g_errorList.m_pElements = g_errorList.m_Memory.m_pMemory;
        v25 = v22 - v23;
        if ( v25 > 0 )
        {
          _V_memmove(
            dest: &g_errorList.m_Memory.m_pMemory[v23 + 1],
            src: &g_errorList.m_Memory.m_pMemory[v23],
            count: 20 * v25);
          m_pMemory = g_errorList.m_Memory.m_pMemory;
        }
        v26 = v23;
        if ( &m_pMemory[v26] != nullptr )
        {
          CUtlString::CUtlString(this: &m_pMemory[v26].fileName);
          m_pMemory = g_errorList.m_Memory.m_pMemory;
        }
        m_pMemory[v26].result = ModelFiles;
        v27 = CUtlString::operator char const *(this: v19);
        CUtlString::Set(this: &g_errorList.m_Memory.m_pMemory[v26].fileName, pValue: v27);
      }
      v46 = -1;
    }
    v43 = __rdtsc();
    v28 = (v43 - *(_QWORD *)&search.m_Storage.m_Memory.m_nGrowSize) >> 32;
    search.m_Storage.m_Memory.m_nGrowSize = v43 - search.m_Storage.m_Memory.m_nGrowSize;
    search.m_Storage.m_nActualLength = v28;
    HIDWORD(v44) = v28 & 0x80000000;
    LODWORD(v44) = 0;
    _Msg(
      a1: "\tfinished in %d'%d\"\n",
      (unsigned int)((unsigned __int64)((double)__PAIR64__(v28, search.m_Storage.m_Memory.m_nGrowSize)
                                      * _g_ClockSpeedSecondsMultiplier)
                   / 0x3C),
      (_DWORD)(((unsigned __int64)((double)__PAIR64__(v28, search.m_Storage.m_Memory.m_nGrowSize)
                                 * _g_ClockSpeedSecondsMultiplier)
              / 0x3C) >> 32));
  }
  else
  {
    _Msg(a1: "Model Pre Pass: Updating %d Models. (%d threads)\n", m_Size, v16);
    HIDWORD(v44) = &search.m_Storage.m_Memory.m_nGrowSize;
    *(_QWORD *)&search.m_Storage.m_Memory.m_nGrowSize = __rdtsc();
    helper_PreprocessModelFilesThreaded(numthreads: v16, updatelist: &updateList);
    v43 = __rdtsc();
    v17 = (v43 - *(_QWORD *)&search.m_Storage.m_Memory.m_nGrowSize) >> 32;
    search.m_Storage.m_Memory.m_nGrowSize = v43 - search.m_Storage.m_Memory.m_nGrowSize;
    search.m_Storage.m_nActualLength = v17;
    v44 = (__int64)((double)__PAIR64__(v17, search.m_Storage.m_Memory.m_nGrowSize) * _g_ClockSpeedSecondsMultiplier);
    _Msg(a1: "\tfinished in %d'%d\"\n", (unsigned int)v44 / 0x3C, (unsigned int)v44 % 0x3C);
  }
  if ( g_errorList.m_Size != 0 )
  {
    _Warning(a1: "\n");
    v29 = 0;
    if ( g_errorList.m_Size > 0 )
    {
      v30 = 0;
      do
      {
        v31 = CUtlString::operator char const *(this: &g_errorList.m_Memory.m_pMemory[v30].fileName);
        _Warning(
          a1: "%s: Could not pre-process model %s\n",
          s_pErrorStrings_2[g_errorList.m_Memory.m_pMemory[v30].result],
          v31);
        ++v29;
        ++v30;
      }
      while ( v29 < g_errorList.m_Size );
    }
  }
  CUtlRBTree<CUtlString,int,bool (__cdecl *)(CUtlString const &,CUtlString const &),CUtlMemory<UtlRBTreeNode_t<CUtlString,int>,int>>::RemoveAll(this: &visitedModels);
  if ( visitedModels.m_Elements.m_nGrowSize >= 0 && visitedModels.m_Elements.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: visitedModels.m_Elements.m_pMemory);
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&updateList);
  if ( updateList.m_Memory.m_nGrowSize >= 0 && updateList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: updateList.m_Memory.m_pMemory);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00573D60
// Name: public: virtual int CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>::AddRef(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>::AddRef(
        CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > *this)
{
  return _InterlockedIncrement(&this->m_iRefs);
}

//------------------------------------------------------------------------------
// Address: 0x00573D70
// Name: public: virtual int CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>::Release(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>::Release(
        CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > *this)
{
  CRefCountServiceBase<1,CRefMT> *v1; // esi
  int result; // eax

  v1 = &this->CRefCountServiceBase<1,CRefMT>;
  result = _InterlockedDecrement(&this->m_iRefs);
  if ( result == 0 )
  {
    if ( v1->OnFinalRelease(this: v1) )
      ((void (__thiscall *)(CRefCountServiceBase<1,CRefMT> *, int))v1->dtr_CRefCountServiceBase<1,CRefMT>)(
        a1: v1,
        a2: 1);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00589BE0
// Name: _dynamic_initializer_for__CModelPreprocessJob::s_nTotalModelsLeft__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void dynamic_initializer_for__CModelPreprocessJob::s_nTotalModelsLeft__()
{
  CModelPreprocessJob::s_nTotalModelsLeft.m_value = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00589BF0
// Name: _dynamic_initializer_for__CModelPreprocessJob::s_AllDone__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CModelPreprocessJob::s_AllDone__()
{
  CThreadEvent::CThreadEvent(this: &CModelPreprocessJob::s_AllDone, a2: false);
  return atexit(func: dynamic_atexit_destructor_for__CModelPreprocessJob::s_AllDone__);
}

//------------------------------------------------------------------------------
// Address: 0x0058B080
// Name: _dynamic_atexit_destructor_for__CModelPreprocessJob::s_AllDone__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CModelPreprocessJob::s_AllDone__()
{
  CThreadSyncObject::~CThreadSyncObject(this: &CModelPreprocessJob::s_AllDone);
}

//------------------------------------------------------------------------------
// Address: 0x00589C10
// Name: _dynamic_initializer_for__g_ASCache__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ASCache__()
{
  CUtlString::CUtlString(this: &g_ASCache.m_szMODPath);
  CUtlString::CUtlString(this: &g_ASCache.m_szModPath);
  CUtlString::CUtlString(this: &g_ASCache.m_szMasterCache);
  CUtlString::CUtlString(this: &g_ASCache.m_szCurrentLanguage);
  g_ASCache.m_pMasterSoundCache = nullptr;
  g_ASCache.m_pBuildingCache = nullptr;
  g_ASCache.m_nServerCount = -1;
  return atexit(func: dynamic_atexit_destructor_for__g_ASCache__);
}

//------------------------------------------------------------------------------
// Address: 0x00589C60
// Name: _dynamic_initializer_for__g_AudioRules__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_AudioRules__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_AudioRules__);
}

//------------------------------------------------------------------------------
// Address: 0x00589C70
// Name: _dynamic_initializer_for__g_PWLTextureTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_PWLTextureTable__()
{
  CUtlSymbolTable::CUtlSymbolTable(this: &g_PWLTextureTable, growSize: 0, initSize: 32, caseInsensitive: true);
  return atexit(func: dynamic_atexit_destructor_for__g_PWLTextureTable__);
}

//------------------------------------------------------------------------------
// Address: 0x00589C90
// Name: _dynamic_initializer_for__g_Allow1024TextureTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Allow1024TextureTable__()
{
  CUtlSymbolTable::CUtlSymbolTable(this: &g_Allow1024TextureTable, growSize: 0, initSize: 32, caseInsensitive: true);
  return atexit(func: dynamic_atexit_destructor_for__g_Allow1024TextureTable__);
}

//------------------------------------------------------------------------------
// Address: 0x00589CB0
// Name: _dynamic_initializer_for__g_PreloadWhiteTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_PreloadWhiteTable__()
{
  CUtlSymbolTable::CUtlSymbolTable(this: &g_PreloadWhiteTable, growSize: 0, initSize: 32, caseInsensitive: true);
  return atexit(func: dynamic_atexit_destructor_for__g_PreloadWhiteTable__);
}

//------------------------------------------------------------------------------
// Address: 0x00589CD0
// Name: _dynamic_initializer_for__g_PreloadBlackTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_PreloadBlackTable__()
{
  CUtlSymbolTable::CUtlSymbolTable(this: &g_PreloadBlackTable, growSize: 0, initSize: 32, caseInsensitive: true);
  return atexit(func: dynamic_atexit_destructor_for__g_PreloadBlackTable__);
}

//------------------------------------------------------------------------------
// Address: 0x00589CF0
// Name: _dynamic_initializer_for__g_AlternateFileTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_AlternateFileTable__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_AlternateFileTable__);
}

//------------------------------------------------------------------------------
// Address: 0x00589D00
// Name: _dynamic_initializer_for__g_CleanupFunctions__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CleanupFunctions__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CleanupFunctions__);
}

//------------------------------------------------------------------------------
// Address: 0x00589D10
// Name: _dynamic_initializer_for__g_ExitStopper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ExitStopper__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_ExitStopper__);
}

//------------------------------------------------------------------------------
// Address: 0x0058B090
// Name: _dynamic_atexit_destructor_for__g_ASCache__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ASCache__()
{
  CMasterCacheBuilder::~CMasterCacheBuilder(this: &g_ASCache);
}

//------------------------------------------------------------------------------
// Address: 0x0058B0A0
// Name: _dynamic_atexit_destructor_for__g_AudioRules__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_AudioRules__()
{
  CUtlVector<AudioConversion_t,CUtlMemory<AudioConversion_t,int>>::~CUtlVector<AudioConversion_t,CUtlMemory<AudioConversion_t,int>>(this: &g_AudioRules);
}

//------------------------------------------------------------------------------
// Address: 0x0058B0B0
// Name: _dynamic_atexit_destructor_for__g_PWLTextureTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_PWLTextureTable__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &g_PWLTextureTable);
}

//------------------------------------------------------------------------------
// Address: 0x0058B0C0
// Name: _dynamic_atexit_destructor_for__g_Allow1024TextureTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_Allow1024TextureTable__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &g_Allow1024TextureTable);
}

//------------------------------------------------------------------------------
// Address: 0x0058B0D0
// Name: _dynamic_atexit_destructor_for__g_PreloadWhiteTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_PreloadWhiteTable__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &g_PreloadWhiteTable);
}

//------------------------------------------------------------------------------
// Address: 0x0058B0E0
// Name: _dynamic_atexit_destructor_for__g_PreloadBlackTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_PreloadBlackTable__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &g_PreloadBlackTable);
}

//------------------------------------------------------------------------------
// Address: 0x0058B0F0
// Name: _dynamic_atexit_destructor_for__g_AlternateFileTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_AlternateFileTable__()
{
  CUtlVector<AlternateFile_t,CUtlMemory<AlternateFile_t,int>>::~CUtlVector<AlternateFile_t,CUtlMemory<AlternateFile_t,int>>(this: &g_AlternateFileTable);
}

//------------------------------------------------------------------------------
// Address: 0x0058B100
// Name: _dynamic_atexit_destructor_for__g_ExitStopper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ExitStopper__()
{
  if ( g_bStopOnExit )
  {
    _Warning(a1: "\nPress any key to quit.\n");
    getch();
  }
}

//------------------------------------------------------------------------------
// Address: 0x0058B120
// Name: _dynamic_atexit_destructor_for__g_CleanupFunctions__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CleanupFunctions__()
{
  CUtlLinkedList<CZip *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CZip *,unsigned short>,unsigned short>>::RemoveAll(this: &g_CleanupFunctions);
  if ( g_CleanupFunctions.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_CleanupFunctions.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_CleanupFunctions.m_Memory.m_pMemory);
      g_CleanupFunctions.m_Memory.m_pMemory = nullptr;
    }
    g_CleanupFunctions.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0058B170
// Name: _CmdLib_FPrintf_::_2_::_dynamic_atexit_destructor_for__buf__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl CmdLib_FPrintf_::_2_::_dynamic_atexit_destructor_for__buf__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&buf);
}

//------------------------------------------------------------------------------
// Address: 0x0058B180
// Name: _DataMapInit_CompiledCaptionHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CompiledCaptionHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder);
}

//------------------------------------------------------------------------------
// Address: 0x0058B190
// Name: _DataMapInit_CaptionLookup_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CaptionLookup_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_0);
}

//------------------------------------------------------------------------------
// Address: 0x0058B1A0
// Name: _dynamic_atexit_destructor_for__g_definevariable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_definevariable__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_definevariable);
}
