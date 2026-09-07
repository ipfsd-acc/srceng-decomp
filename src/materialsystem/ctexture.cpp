// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/ctexture.cpp
// Functions: 163
// ============================================================

#include "materialsystem\ctexture.h"

//------------------------------------------------------------------------------
// Address: 0x1001E1F0
// Name: public: virtual void CMemberFunctor1<class IMaterialInternal __near *,void (IMaterial::*)(float),float,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor1<IMaterialInternal *,void (__thiscall IMaterial::*)(float),float,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor1<IMaterialInternal *,void (__thiscall IMaterial::*)(float),float,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *this)
{
  ((void (__thiscall *)(IMaterialInternal *, _DWORD))this->m_Proxy.m_pfnProxied)(
    a1: this->m_Proxy.m_pObject,
    a2: LODWORD(this->m_arg1));
}

//------------------------------------------------------------------------------
// Address: 0x1002B5E0
// Name: public: virtual void CMemberFunctor1<class IColorCorrectionSystem __near *,void (IColorCorrectionSystem::*)(bool),bool,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor1<IColorCorrectionSystem *,void (__thiscall IColorCorrectionSystem::*)(bool),bool,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor1<IColorCorrectionSystem *,void (__thiscall IColorCorrectionSystem::*)(bool),bool,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this)
{
  ((void (__thiscall *)(char *, bool))LODWORD(this->m_Proxy.m_pfnProxied))(
    a1: (char *)this->m_Proxy.m_pObject + DWORD1(this->m_Proxy.m_pfnProxied),
    a2: this->m_arg1);
}

//------------------------------------------------------------------------------
// Address: 0x1002B6A0
// Name: public: virtual void CMemberFunctor1<class CMatRenderContextBase __near *,void (IMatRenderContext::*)(float),float,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(float),float,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(float),float,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this)
{
  ((void (__thiscall *)(char *, _DWORD))LODWORD(this->m_Proxy.m_pfnProxied))(
    a1: (char *)this->m_Proxy.m_pObject + DWORD1(this->m_Proxy.m_pfnProxied),
    a2: LODWORD(this->m_arg1));
}

//------------------------------------------------------------------------------
// Address: 0x1002B760
// Name: public: virtual void CMemberFunctor1<class CMatRenderContextBase __near *,void (IMatRenderContext::*)(enum MaterialCullMode_t),enum MaterialCullMode_t,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialCullMode_t),enum MaterialCullMode_t,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(enum MaterialNonInteractiveMode_t),enum MaterialNonInteractiveMode_t,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this)
{
  ((void (__thiscall *)(char *, MaterialNonInteractiveMode_t))LODWORD(this->m_Proxy.m_pfnProxied))(
    a1: (char *)this->m_Proxy.m_pObject + DWORD1(this->m_Proxy.m_pfnProxied),
    a2: this->m_arg1);
}

//------------------------------------------------------------------------------
// Address: 0x10034410
// Name: public: CMemberFunctor1<class CMaterialVar __near *,void (CMaterialVar::*)(char const __near *),class CUtlEnvelope<char const __near *>,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>,class CFuncMemPolicyNone>::CMemberFunctor1<class CMaterialVar __near *,void (CMaterialVar::*)(char const __near *),class CUtlEnvelope<char const __near *>,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>,class CFuncMemPolicyNone>(class CMaterialVar __near *,void (CMaterialVar::*)(char const __near *),class CUtlEnvelope<char const __near *> const __near &)
// Source: json
//------------------------------------------------------------------------------
CMemberFunctor1<CMaterialVar *,void (__thiscall CMaterialVar::*)(char const *),CUtlEnvelope<char const *>,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *__thiscall CMemberFunctor1<CMaterialVar *,void (__thiscall CMaterialVar::*)(char const *),CUtlEnvelope<char const *>,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::CMemberFunctor1<CMaterialVar *,void (__thiscall CMaterialVar::*)(char const *),CUtlEnvelope<char const *>,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>(
        CMemberFunctor1<CMaterialVar *,void (__thiscall CMaterialVar::*)(char const *),CUtlEnvelope<char const *>,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this,
        CMaterialVar *pObject,
        __int128 pfnProxied,
        const CUtlEnvelope<char const *> *arg1)
{
  CUtlEnvelope<char const *> *p_m_arg1; // edi

  this->m_iRefs = 1;
  this->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CFunctor::IRefCounted::__vftable = (CMemberFunctor1<CMaterialVar *,void (__thiscall CMaterialVar::*)(char const *),CUtlEnvelope<char const *>,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone>_vtbl *)&CMemberFunctor1<CMaterialVar *,void (__thiscall CMaterialVar::*)(char const *),CUtlEnvelope<char const *>,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  this->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CRefCountServiceDestruct<CRefST>::__vftable = (CRefCountServiceDestruct<CRefST>_vtbl *)&CMemberFunctor1<CMaterialVar *,void (__thiscall CMaterialVar::*)(char const *),CUtlEnvelope<char const *>,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceDestruct<CRefST>'};
  this->m_Proxy.m_pfnProxied = pfnProxied;
  p_m_arg1 = &this->m_arg1;
  this->m_Proxy.m_pObject = pObject;
  CUtlString::CUtlString(this: &this->m_arg1.m_string);
  CUtlString::operator=(this: &p_m_arg1->m_string, src: &arg1->m_string);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100344B0
// Name: public: virtual void CMemberFunctor1<class CMaterialVar __near *,void (CMaterialVar::*)(char const __near *),class CUtlEnvelope<char const __near *>,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor1<CMaterialVar *,void (__thiscall CMaterialVar::*)(char const *),CUtlEnvelope<char const *>,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor1<CMaterialVar *,void (__thiscall CMaterialVar::*)(char const *),CUtlEnvelope<char const *>,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this)
{
  const char *v2; // eax

  v2 = CUtlString::operator char const *(this: &this->m_arg1.m_string);
  ((void (__thiscall *)(char *, const char *))LODWORD(this->m_Proxy.m_pfnProxied))(
    a1: (char *)this->m_Proxy.m_pObject + DWORD1(this->m_Proxy.m_pfnProxied),
    a2: v2);
}

//------------------------------------------------------------------------------
// Address: 0x1003E560
// Name: public: virtual void CMemberFunctor1<class CMatQueuedMesh __near *,void (CMatQueuedMesh::*)(struct CMatQueuedMesh::MST_DrawModulatedInfo_t const __near &),struct CMatQueuedMesh::MST_DrawModulatedInfo_t,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawModulatedInfo_t const &),CMatQueuedMesh::MST_DrawModulatedInfo_t,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(Vector const &),Vector,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this)
{
  ((void (__thiscall *)(char *, Vector *))LODWORD(this->m_Proxy.m_pfnProxied))(
    a1: (char *)this->m_Proxy.m_pObject + DWORD1(this->m_Proxy.m_pfnProxied),
    a2: &this->m_arg1);
}

//------------------------------------------------------------------------------
// Address: 0x1003E5A0
// Name: public: virtual void CMemberFunctor1<class CMatRenderContextBase __near *,void (IMatRenderContext::*)(class Vector),class Vector,class CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(Vector),Vector,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(Vector),Vector,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this)
{
  ((void (__thiscall *)(char *, _DWORD, _DWORD, _DWORD))LODWORD(this->m_Proxy.m_pfnProxied))(
    a1: (char *)this->m_Proxy.m_pObject + DWORD1(this->m_Proxy.m_pfnProxied),
    a2: LODWORD(this->m_arg1.x),
    a3: LODWORD(this->m_arg1.y),
    a4: LODWORD(this->m_arg1.z));
}

//------------------------------------------------------------------------------
// Address: 0x100496F0
// Name: public: virtual ITextureInternal::~ITextureInternal(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ITextureInternal::~ITextureInternal(ITextureInternal *this)
{
  this->__vftable = (ITextureInternal_vtbl *)&ITextureInternal::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10049700
// Name: char __near * NormalizeTextureName(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl NormalizeTextureName(const char *pName, char *pOutName, int nOutNameSize)
{
  int v3; // eax
  char *v4; // edi

  v3 = _V_strlen(str: pName) + 1;
  if ( v3 <= 5 || _V_stricmp(s1: &pName[v3 - 5], s2: ".hdr") != 0 )
  {
    v4 = pOutName;
    V_StripExtension(in: pName, out: pOutName, outSize: nOutNameSize);
  }
  else
  {
    v4 = pOutName;
    V_strncpy(pDest: pOutName, pSrc: pName, maxLen: nOutNameSize);
  }
  _V_strlower(start: v4);
  V_FixSlashes(pname: v4, separator: 47);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10049770
// Name: public: void CReferenceToHandleTexture::SetName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CReferenceToHandleTexture::SetName(CReferenceToHandleTexture *this, const char *szName)
{
  const char *v2; // esi
  int v4; // eax
  char szCleanName[260]; // [esp+8h] [ebp-104h] BYREF

  v2 = szName;
  v4 = _V_strlen(str: szName) + 1;
  if ( v4 <= 5 || _V_stricmp(s1: &v2[v4 - 5], s2: ".hdr") != 0 )
    V_StripExtension(in: v2, out: szCleanName, outSize: 260);
  else
    V_strncpy(pDest: szCleanName, pSrc: v2, maxLen: 260);
  _V_strlower(start: szCleanName);
  V_FixSlashes(pname: szCleanName, separator: 47);
  CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&szName + 1, pStr: szCleanName);
  this->m_Name.m_Id = HIWORD(szName);
}

//------------------------------------------------------------------------------
// Address: 0x10049810
// Name: public: virtual void CReferenceToHandleTexture::Bind(enum Sampler_t,enum TextureBindFlags_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CReferenceToHandleTexture::Bind(
        CReferenceToHandleTexture *this,
        Sampler_t sampler,
        TextureBindFlags_t nBindFlags)
{
  if ( g_pShaderDevice->IsUsingGraphics(this: g_pShaderDevice) )
    g_pShaderAPI->BindTexture(this: g_pShaderAPI, a2: sampler, a3: nBindFlags, a4: this->m_hTexture);
}

//------------------------------------------------------------------------------
// Address: 0x10049850
// Name: public: virtual void CReferenceToHandleTexture::Bind(enum Sampler_t,enum TextureBindFlags_t,int,enum Sampler_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CReferenceToHandleTexture::Bind(
        CReferenceToHandleTexture *this,
        Sampler_t sampler1,
        TextureBindFlags_t nBindFlags,
        int nFrame,
        Sampler_t sampler2)
{
  if ( g_pShaderDevice->IsUsingGraphics(this: g_pShaderDevice) )
    g_pShaderAPI->BindTexture(this: g_pShaderAPI, a2: sampler1, a3: nBindFlags, a4: this->m_hTexture);
}

//------------------------------------------------------------------------------
// Address: 0x10049890
// Name: public: virtual void CReferenceToHandleTexture::BindVertexTexture(enum VertexTextureSampler_t,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CReferenceToHandleTexture::BindVertexTexture(
        CReferenceToHandleTexture *this,
        VertexTextureSampler_t sampler,
        int nFrame)
{
  if ( g_pShaderDevice->IsUsingGraphics(this: g_pShaderDevice) )
    g_pShaderAPI->BindVertexTexture(this: g_pShaderAPI, a2: sampler, a3: this->m_hTexture);
}

//------------------------------------------------------------------------------
// Address: 0x100498D0
// Name: public: virtual void CReferenceToHandleTexture::DeleteIfUnreferenced(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CReferenceToHandleTexture::DeleteIfUnreferenced(CReferenceToHandleTexture *this)
{
  if ( this->m_nRefCount <= 0 )
    g_pTextureManager->RemoveTexture(this: g_pTextureManager, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x100498F0
// Name: public: static void ITextureInternal::Destroy(class ITextureInternal __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ITextureInternal::Destroy(ITextureInternal *pTex)
{
  if ( pTex != nullptr )
    ((void (__thiscall *)(ITextureInternal *, int))pTex->dtr_ITextureInternal)(a1: pTex, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10049910
// Name: public: virtual void CTexture::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTexture::Release(CTexture *this)
{
  this->FreeShaderAPITextures(this);
}

//------------------------------------------------------------------------------
// Address: 0x10049920
// Name: protected: class IVTFTexture __near * CTexture::GetScratchVTFTexture(void)
// Source: json
//------------------------------------------------------------------------------
CVTFTexture *__thiscall CTexture::GetScratchVTFTexture(CTexture *this)
{
  CVTFTexture *result; // eax

  result = (CVTFTexture *)s_pVTFTexture;
  if ( s_pVTFTexture == nullptr )
  {
    result = CreateVTFTexture();
    s_pVTFTexture = result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10049940
// Name: protected: void CTexture::ApplyRenderTargetSizeMode(int __near &,int __near &,enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTexture::ApplyRenderTargetSizeMode(CTexture *this, int *width, int *height, ImageFormat fmt)
{
  int *v4; // esi
  int *v5; // edi
  int i; // eax
  int v7; // ecx
  int v8; // ecx
  int v9; // ecx
  int v10; // ecx
  int *v11; // edx
  int *v12; // ecx

  v4 = width;
  *width = this->m_nOriginalRTWidth;
  v5 = height;
  *height = this->m_nOriginalRTHeight;
  switch ( this->m_RenderTargetSizeMode )
  {
    case RT_SIZE_DEFAULT:
      g_pInternalMaterialSystem->GetBackBufferDimensions(
        this: g_pInternalMaterialSystem,
        a2: (int *)&width,
        a3: (int *)&height);
      if ( *v4 > (int)width )
      {
        v9 = *v4;
        do
          v9 >>= 1;
        while ( v9 > (int)width );
        *v4 = v9;
      }
      if ( *v5 > (int)height )
      {
        v10 = *v5;
        do
          v10 >>= 1;
        while ( v10 > (int)height );
        *v5 = v10;
      }
      break;
    case RT_SIZE_PICMIP:
      g_pInternalMaterialSystem->GetBackBufferDimensions(
        this: g_pInternalMaterialSystem,
        a2: (int *)&width,
        a3: (int *)&height);
      for ( i = g_config.skipMipLevels; i > 0; --i )
      {
        *v4 >>= 1;
        *v5 >>= 1;
      }
      if ( *v4 > (int)width )
      {
        v7 = *v4;
        do
          v7 >>= 1;
        while ( v7 > (int)width );
        *v4 = v7;
      }
      if ( *v5 > (int)height )
      {
        v8 = *v5;
        do
          v8 >>= 1;
        while ( v8 > (int)height );
        *v5 = v8;
      }
      break;
    case RT_SIZE_HDR:
      g_pInternalMaterialSystem->GetBackBufferDimensions(this: g_pInternalMaterialSystem, a2: v4, a3: v5);
      *v4 /= 4;
      *v5 /= 4;
      break;
    case RT_SIZE_FULL_FRAME_BUFFER:
    case RT_SIZE_FULL_FRAME_BUFFER_ROUNDED_UP:
      g_pInternalMaterialSystem->GetBackBufferDimensions(this: g_pInternalMaterialSystem, a2: v4, a3: v5);
      break;
    case RT_SIZE_OFFSCREEN:
      g_pInternalMaterialSystem->GetBackBufferDimensions(
        this: g_pInternalMaterialSystem,
        a2: (int *)&height,
        a3: (int *)&width);
      v11 = width;
      v12 = height;
      while ( *v4 > (int)v12 || *v5 > (int)v11 )
      {
        *v4 >>= 1;
        *v5 >>= 1;
      }
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10049A90
// Name: protected: void CTexture::AllocateTextureHandles(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTexture::AllocateTextureHandles(CTexture *this)
{
  int i; // eax

  this->m_pTextureHandles = (int *)MemAlloc_Alloc(nSize: 4 * this->m_nFrameCount);
  for ( i = 0; i != this->m_nFrameCount; this->m_pTextureHandles[i++] = 0 )
    ;
}

//------------------------------------------------------------------------------
// Address: 0x10049AE0
// Name: int GetCreationFlags(int,int,enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetCreationFlags(int iTextureFlags, int iInternalTextureFlags, ImageFormat fmt)
{
  int v3; // eax
  bool v4; // cl
  int result; // eax

  v3 = (iTextureFlags & 0x4000) != 0;
  v4 = fmt == IMAGE_FORMAT_RGBA16161616F
    || fmt == IMAGE_FORMAT_R32F
    || fmt == IMAGE_FORMAT_RGB323232F
    || fmt == IMAGE_FORMAT_RGBA32323232F;
  if ( (iTextureFlags & 0x80000) != 0 && !v4 )
    v3 |= 0x20000u;
  if ( (iTextureFlags & 0x8000) != 0 )
    result = v3 | 2;
  else
    result = v3 | 4;
  if ( (iTextureFlags & 0x100000) != 0 )
    result = result & 0xFFFFFFEB | 0x10;
  if ( (iTextureFlags & 1) != 0 )
    result |= 0x1000u;
  if ( (iTextureFlags & 0x4000000) != 0 )
    return result | 0x40;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10049B60
// Name: protected: enum ImageFormat CTexture::ComputeActualFormat(enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
ImageFormat __thiscall CTexture::ComputeActualFormat(CTexture *this, ImageFormat srcFormat)
{
  char v3; // al
  ImageFormat (__thiscall *GetNearestSupportedFormat)(IShaderAPI *, ImageFormat, bool); // edx

  v3 = *((_BYTE *)ImageLoader::ImageFormatInfo(fmt: srcFormat) + 11) & 1;
  if ( g_config.bCompressedTextures && v3 != 0
    || srcFormat == IMAGE_FORMAT_UVWQ8888
    || srcFormat == IMAGE_FORMAT_UV88
    || srcFormat == IMAGE_FORMAT_UVLX8888
    || srcFormat == IMAGE_FORMAT_RGBA16161616
    || srcFormat == IMAGE_FORMAT_RGBA16161616F
    || srcFormat == IMAGE_FORMAT_RGBA32323232F
    || srcFormat == IMAGE_FORMAT_R32F )
  {
    return g_pShaderAPI->GetNearestSupportedFormat(this: g_pShaderAPI, a2: srcFormat, a3: true);
  }
  if ( (this->m_nFlags & 0x3000) != 0 )
    return g_pShaderAPI->GetNearestSupportedFormat(this: g_pShaderAPI, a2: IMAGE_FORMAT_BGRA8888, a3: true);
  GetNearestSupportedFormat = g_pShaderAPI->GetNearestSupportedFormat;
  if ( srcFormat == IMAGE_FORMAT_I8 )
    return ((ImageFormat (__stdcall *)(int, int))GetNearestSupportedFormat)(a1: 5, a2: 1);
  else
    return ((ImageFormat (__stdcall *)(int, int))GetNearestSupportedFormat)(a1: 3, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10049C00
// Name: public: virtual void CTexture::SetTextureRegenerator(class ITextureRegenerator __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTexture::SetTextureRegenerator(
        CTexture *this,
        ITextureRegenerator *pTextureRegen,
        bool releaseExisting)
{
  ITextureRegenerator *m_pTextureRegenerator; // ecx

  m_pTextureRegenerator = this->m_pTextureRegenerator;
  if ( m_pTextureRegenerator != nullptr )
  {
    if ( releaseExisting )
      m_pTextureRegenerator->Release(this: m_pTextureRegenerator);
    this->m_pTextureRegenerator = pTextureRegen;
  }
  else
  {
    this->m_pTextureRegenerator = pTextureRegen;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10049C40
// Name: protected: void CTexture::SetWrapState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTexture::SetWrapState(CTexture *this)
{
  unsigned int m_nFlags; // eax
  void (__thiscall *TexWrap)(IShaderAPI *, ShaderTexCoordComponent_t, ShaderTexWrapMode_t); // edx

  m_nFlags = this->m_nFlags;
  if ( (m_nFlags & 0x20000000) != 0 )
  {
    g_pShaderAPI->TexWrap(this: g_pShaderAPI, a2: SHADER_TEXCOORD_S, a3: SHADER_TEXWRAPMODE_BORDER);
    g_pShaderAPI->TexWrap(this: g_pShaderAPI, a2: SHADER_TEXCOORD_T, a3: SHADER_TEXWRAPMODE_BORDER);
    g_pShaderAPI->TexWrap(this: g_pShaderAPI, a2: SHADER_TEXCOORD_U, a3: SHADER_TEXWRAPMODE_BORDER);
  }
  else
  {
    TexWrap = g_pShaderAPI->TexWrap;
    if ( (m_nFlags & 4) != 0 )
      ((void (__stdcall *)(_DWORD, _DWORD))TexWrap)(a1: 0, a2: 0);
    else
      ((void (__stdcall *)(_DWORD, int))TexWrap)(a1: 0, a2: 1);
    ((void (__stdcall *)(int, bool))g_pShaderAPI->TexWrap)(a1: 1, a2: (this->m_nFlags & 8) == 0);
    if ( (this->m_nFlags & 0x2000000) != 0 )
      g_pShaderAPI->TexWrap(this: g_pShaderAPI, a2: SHADER_TEXCOORD_U, a3: SHADER_TEXWRAPMODE_CLAMP);
    else
      g_pShaderAPI->TexWrap(this: g_pShaderAPI, a2: SHADER_TEXCOORD_U, a3: SHADER_TEXWRAPMODE_REPEAT);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10049D00
// Name: protected: void CTexture::SetFilterState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTexture::SetFilterState(CTexture *this)
{
  unsigned int m_nFlags; // eax
  char v3; // cl
  char v4; // al

  m_nFlags = this->m_nFlags;
  if ( (m_nFlags & 1) != 0 )
  {
    g_pShaderAPI->TexMinFilter(this: g_pShaderAPI, a2: SHADER_TEXFILTERMODE_NEAREST);
    g_pShaderAPI->TexMagFilter(this: g_pShaderAPI, a2: SHADER_TEXFILTERMODE_NEAREST);
    return;
  }
  if ( (m_nFlags & 0x100) != 0 )
  {
    g_pShaderAPI->TexMinFilter(this: g_pShaderAPI, a2: SHADER_TEXFILTERMODE_LINEAR);
  }
  else
  {
    if ( g_config.m_nForceAnisotropicLevel > 1 && g_pHWConfig->MaximumAnisotropicLevel(this: g_pHWConfig) > 1
      || ((this->m_nFlags & 0x10) == 0 || g_pHWConfig->MaximumAnisotropicLevel(this: g_pHWConfig) <= 1
        ? (v3 = 0)
        : (v3 = 1),
          g_config.m_nForceAnisotropicLevel == 1 || (this->m_nFlags & 2) != 0 ? (v4 = 1) : (v4 = 0),
          v3 != 0) )
    {
      g_pShaderAPI->TexMinFilter(this: g_pShaderAPI, a2: SHADER_TEXFILTERMODE_ANISOTROPIC);
      g_pShaderAPI->TexMagFilter(this: g_pShaderAPI, a2: SHADER_TEXFILTERMODE_ANISOTROPIC);
      return;
    }
    if ( v4 != 0 )
      g_pShaderAPI->TexMinFilter(this: g_pShaderAPI, a2: SHADER_TEXFILTERMODE_LINEAR_MIPMAP_LINEAR);
    else
      g_pShaderAPI->TexMinFilter(this: g_pShaderAPI, a2: SHADER_TEXFILTERMODE_LINEAR_MIPMAP_NEAREST);
  }
  g_pShaderAPI->TexMagFilter(this: g_pShaderAPI, a2: SHADER_TEXFILTERMODE_LINEAR);
}

//------------------------------------------------------------------------------
// Address: 0x10049DF0
// Name: public: virtual void CTexture::Bind(enum Sampler_t,enum TextureBindFlags_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTexture::Bind(CTexture *this, Sampler_t sampler, TextureBindFlags_t nBindFlags)
{
  this->Bind(this, a2: sampler, a3: nBindFlags, a4: 0, a5: SHADER_SAMPLER_INVALID);
}

//------------------------------------------------------------------------------
// Address: 0x10049E10
// Name: public: virtual void CTexture::Bind(enum Sampler_t,enum TextureBindFlags_t,int,enum Sampler_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTexture::Bind(
        CTexture *this,
        Sampler_t sampler1,
        TextureBindFlags_t nBindFlags,
        int nFrame,
        Sampler_t sampler2)
{
  int v6; // eax

  if ( g_pShaderDevice->IsUsingGraphics(this: g_pShaderDevice) )
  {
    v6 = nFrame;
    if ( nFrame < 0 || nFrame >= this->m_nFrameCount )
      v6 = 0;
    g_pShaderAPI->BindTexture(this: g_pShaderAPI, a2: sampler1, a3: nBindFlags, a4: this->m_pTextureHandles[v6]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10049E60
// Name: public: virtual void CTexture::BindVertexTexture(enum VertexTextureSampler_t,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTexture::BindVertexTexture(CTexture *this, VertexTextureSampler_t sampler, int nFrame)
{
  int v4; // eax

  if ( g_pShaderDevice->IsUsingGraphics(this: g_pShaderDevice) )
  {
    v4 = nFrame;
    if ( nFrame < 0 || nFrame >= this->m_nFrameCount )
      v4 = 0;
    g_pShaderAPI->BindVertexTexture(this: g_pShaderAPI, a2: sampler, a3: this->m_pTextureHandles[v4]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10049EB0
// Name: public: virtual bool CTexture::SetRenderTarget(int,class ITexture __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTexture::SetRenderTarget(CTexture *this, int nRenderTargetID, ITexture *pDepthTexture)
{
  unsigned int m_nFlags; // edx
  int *m_pTextureHandles; // ecx
  int v6; // eax
  int v7; // esi

  m_nFlags = this->m_nFlags;
  if ( (m_nFlags & 0x8000) == 0 )
    return 0;
  m_pTextureHandles = this->m_pTextureHandles;
  v6 = -1;
  v7 = *m_pTextureHandles;
  if ( (m_nFlags & 0x10000) != 0 )
  {
    v6 = m_pTextureHandles[1];
  }
  else if ( (m_nFlags & 0x800000) != 0 )
  {
    v6 = -2;
  }
  if ( pDepthTexture != nullptr )
    v6 = ((int (__thiscall *)(ITexture *, _DWORD, _DWORD))pDepthTexture->__vftable[1].SetTextureRegenerator)(
           a1: pDepthTexture,
           a2: 0,
           a3: 0);
  g_pShaderAPI->SetRenderTargetEx(this: g_pShaderAPI, a2: nRenderTargetID, a3: v7, a4: v6);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10049F20
// Name: protected: void CTexture::SetName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTexture::SetName(CTexture *this, const char *pName)
{
  const char *v2; // esi
  int v4; // eax
  char szCleanName[260]; // [esp+8h] [ebp-104h] BYREF

  v2 = pName;
  v4 = _V_strlen(str: pName) + 1;
  if ( v4 <= 5 || _V_stricmp(s1: &v2[v4 - 5], s2: ".hdr") != 0 )
    V_StripExtension(in: v2, out: szCleanName, outSize: 260);
  else
    V_strncpy(pDest: szCleanName, pSrc: v2, maxLen: 260);
  _V_strlower(start: szCleanName);
  V_FixSlashes(pname: szCleanName, separator: 47);
  CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&pName + 1, pStr: szCleanName);
  this->m_Name.m_Id = HIWORD(pName);
}

//------------------------------------------------------------------------------
// Address: 0x10049FC0
// Name: public: virtual enum ImageFormat CTexture::GetImageFormat(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTexture::GetImageFormat(CVTFTexture *this)
{
  return this->m_nFaceCount;
}

//------------------------------------------------------------------------------
// Address: 0x10049FD0
// Name: public: virtual int CTexture::GetMappingWidth(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTexture::GetMappingWidth(CTexture *this)
{
  return this->m_nMappingWidth;
}

//------------------------------------------------------------------------------
// Address: 0x10049FE0
// Name: public: virtual int CTexture::GetMappingHeight(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTexture::GetMappingHeight(CTexture *this)
{
  return this->m_nMappingHeight;
}

//------------------------------------------------------------------------------
// Address: 0x10049FF0
// Name: public: virtual int CTexture::GetMappingDepth(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTexture::GetMappingDepth(CTexture *this)
{
  return this->m_nMappingDepth;
}

//------------------------------------------------------------------------------
// Address: 0x1004A000
// Name: public: virtual int CTexture::GetActualWidth(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTexture::GetActualWidth(CTexture *this)
{
  return this->m_nActualWidth;
}

//------------------------------------------------------------------------------
// Address: 0x1004A010
// Name: public: virtual int CTexture::GetActualHeight(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTexture::GetActualHeight(CTexture *this)
{
  return this->m_nActualHeight;
}

//------------------------------------------------------------------------------
// Address: 0x1004A030
// Name: public: virtual int CTexture::GetNumAnimationFrames(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTexture::GetNumAnimationFrames(CTexture *this)
{
  return this->m_nFrameCount;
}

//------------------------------------------------------------------------------
// Address: 0x1004A040
// Name: public: virtual void CTexture::GetReflectivity(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTexture::GetReflectivity(CTexture *this, Vector *reflectivity)
{
  this->Precache(this);
  *reflectivity = this->m_vecReflectivity;
}

//------------------------------------------------------------------------------
// Address: 0x1004A070
// Name: public: virtual bool CTexture::IsTranslucent(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CTexture::IsTranslucent(CTexture *this)
{
  return (this->m_nFlags & 0x3000) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1004A080
// Name: public: virtual bool CTexture::IsNormalMap(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CTexture::IsNormalMap(CTexture *this)
{
  return (this->m_nFlags & 0x80) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1004A090
// Name: public: virtual bool CTexture::IsCubeMap(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CTexture::IsCubeMap(CTexture *this)
{
  return (this->m_nFlags & 0x4000) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1004A0A0
// Name: public: virtual bool CTexture::IsRenderTarget(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CTexture::IsRenderTarget(CTexture *this)
{
  return (this->m_nFlags & 0x8000) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1004A0B0
// Name: public: virtual bool CTexture::IsTempRenderTarget(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CTexture::IsTempRenderTarget(CTexture *this)
{
  return (this->m_nInternalFlags & 0x80) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1004A0C0
// Name: public: virtual bool CTexture::IsProcedural(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CTexture::IsProcedural(CTexture *this)
{
  return (this->m_nFlags & 0x800) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1004A0D0
// Name: public: virtual bool CTexture::IsMipmapped(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CTexture::IsMipmapped(CTexture *this)
{
  return (this->m_nFlags & 0x100) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1004A0E0
// Name: public: virtual bool CTexture::IsError(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CTexture::IsError(CTexture *this)
{
  return this->m_nInternalFlags & 1;
}

//------------------------------------------------------------------------------
// Address: 0x1004A0F0
// Name: public: virtual bool CTexture::IsDefaultPool(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CTexture::IsDefaultPool(CTexture *this)
{
  return (this->m_nFlags & 0x100000) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1004A100
// Name: public: virtual bool CTexture::IsVolumeTexture(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CTexture::IsVolumeTexture(CTexture *this)
{
  return this->m_nMappingDepth > 1u;
}

//------------------------------------------------------------------------------
// Address: 0x1004A110
// Name: public: virtual void CTexture::SetFilteringAndClampingMode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTexture::SetFilteringAndClampingMode(CTexture *this)
{
  int m_nFrameCount; // ebx
  int v3; // edi

  if ( (this->m_nInternalFlags & 2) != 0 )
  {
    m_nFrameCount = this->m_nFrameCount;
    v3 = 0;
    if ( this->m_nFrameCount != 0 )
    {
      do
      {
        g_pShaderAPI->ModifyTexture(this: g_pShaderAPI, a2: this->m_pTextureHandles[v3]);
        CTexture::SetWrapState(this);
        CTexture::SetFilterState(this);
        ++v3;
      }
      while ( v3 < m_nFrameCount );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004A160
// Name: protected: void CTexture::LoadLowResTexture(class IVTFTexture __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTexture::LoadLowResTexture(CTexture *this, IVTFTexture *pTexture)
{
  unsigned __int8 v3; // al
  int v4; // ecx
  unsigned __int8 *v5; // eax
  const unsigned __int8 *v6; // eax
  ImageFormat v7; // [esp-1Ch] [ebp-24h]
  unsigned __int8 *v8; // [esp-18h] [ebp-20h]
  int m_LowResImageWidth; // [esp-10h] [ebp-18h]
  int m_LowResImageHeight; // [esp-Ch] [ebp-14h]

  free(pMem: this->m_pLowResImage);
  this->m_pLowResImage = nullptr;
  if ( pTexture->LowResWidth(this: pTexture) != 0 && pTexture->LowResHeight(this: pTexture) != 0 )
  {
    this->m_LowResImageWidth = pTexture->LowResWidth(this: pTexture);
    v3 = pTexture->LowResHeight(this: pTexture);
    v4 = v3 * this->m_LowResImageWidth;
    this->m_LowResImageHeight = v3;
    v5 = (unsigned __int8 *)MemAlloc_Alloc(nSize: 3 * v4);
    m_LowResImageHeight = this->m_LowResImageHeight;
    m_LowResImageWidth = this->m_LowResImageWidth;
    this->m_pLowResImage = v5;
    v8 = v5;
    v7 = pTexture->LowResFormat(this: pTexture);
    v6 = pTexture->LowResImageData(this: pTexture);
    ImageLoader::ConvertImageFormat(
      src: v6,
      srcImageFormat: v7,
      dst: v8,
      dstImageFormat: IMAGE_FORMAT_RGB888,
      width: m_LowResImageWidth,
      height: m_LowResImageHeight,
      srcStride: 0,
      dstStride: 0);
  }
  else
  {
    *(_WORD *)&this->m_LowResImageWidth = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004A210
// Name: FillCompressedTextureWithSingleColor
// Source: json
//------------------------------------------------------------------------------
void __usercall FillCompressedTextureWithSingleColor(
        int blue@<edx>,
        int width@<eax>,
        int red,
        int green,
        unsigned __int8 *alpha,
        int pImageData,
        int height,
        ImageFormat depth)
{
  int v8; // ebx
  int v9; // eax
  DXTColBlock *v10; // ecx
  DXTColBlock colorBlock; // [esp+Ch] [ebp-8h]

  v8 = height;
  if ( (unsigned int)(width - 1) <= 2 )
    width = 4;
  if ( (unsigned int)(pImageData - 1) <= 2 )
    pImageData = 4;
  if ( (unsigned int)(height - 2) <= 1 )
    v8 = 4;
  *(_WORD *)&colorBlock.row[2] = 0;
  colorBlock.col0 = (blue >> 3) & 0x1F | (32 * (((unsigned __int16)(red >> 3) << 6) | (green >> 2) & 0x3F));
  *(_DWORD *)&colorBlock.col1 = colorBlock.col0;
  v9 = v8 * ((pImageData * width) >> 4);
  switch ( depth )
  {
    case IMAGE_FORMAT_DXT1:
    case IMAGE_FORMAT_ATI1N:
      if ( v9 > 0 )
      {
        *(DXTColBlock *)alpha = colorBlock;
        qmemcpy(alpha + 8, alpha, 4 * ((unsigned int)(8 * v9 - 5) >> 2));
      }
      break;
    case IMAGE_FORMAT_DXT5:
    case IMAGE_FORMAT_ATI2N:
      if ( v9 > 0 )
      {
        v10 = (DXTColBlock *)(alpha + 8);
        do
        {
          *v10 = colorBlock;
          v10 += 2;
          --v9;
        }
        while ( v9 != 0 );
      }
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004A310
// Name: protected: bool CTexture::ConvertToActualFormat(class IVTFTexture __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTexture::ConvertToActualFormat(CTexture *this, IVTFTexture *pVTFTexture)
{
  bool result; // al
  ImageFormat v4; // eax
  ImageFormat v5; // edi
  ImageFormat fmt; // [esp+4h] [ebp-8h]
  bool bConverted; // [esp+Bh] [ebp-1h]

  result = g_pShaderDevice->IsUsingGraphics(this: g_pShaderDevice);
  if ( result )
  {
    fmt = this->m_ImageFormat;
    bConverted = false;
    v4 = pVTFTexture->Format(this: pVTFTexture);
    v5 = CTexture::ComputeActualFormat(this, srcFormat: v4);
    if ( fmt == v5 )
    {
      if ( g_pHWConfig->GetHDRType(this: g_pHWConfig) == HDR_TYPE_INTEGER && v5 == IMAGE_FORMAT_RGBA16161616F )
      {
        pVTFTexture->ConvertImageFormat(this: pVTFTexture, a2: IMAGE_FORMAT_RGBA16161616, a3: false, a4: false);
        pVTFTexture->ConvertImageFormat(this: pVTFTexture, a2: IMAGE_FORMAT_RGBA16161616F, a3: false, a4: false);
        return true;
      }
      return bConverted;
    }
    else
    {
      pVTFTexture->ConvertImageFormat(this: pVTFTexture, a2: v5, a3: false, a4: false);
      this->m_ImageFormat = v5;
      return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004A3D0
// Name: public: void CTexture::GetFilename(char __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTexture::GetFilename(CTexture *this, char *pOut, int maxLen)
{
  const char *v3; // eax

  v3 = CUtlSymbol::String(this: &this->m_Name);
  if ( *v3 == 47 && v3[1] == 47 && v3[2] != 47 )
    V_snprintf(pDest: pOut, maxLen, pFormat: "%s.vtf", v3);
  else
    V_snprintf(pDest: pOut, maxLen, pFormat: "materials/%s.vtf", v3);
}

//------------------------------------------------------------------------------
// Address: 0x1004A420
// Name: public: virtual void CTexture::ReloadFilesInList(class IFileList __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTexture::ReloadFilesInList(CTexture *this, IFileList *pFilesToReload)
{
  char filename[260]; // [esp+4h] [ebp-104h] BYREF

  if ( !this->IsProcedural(this) && !this->IsRenderTarget(this) )
  {
    CTexture::GetFilename(this, pOut: filename, maxLen: 260);
    if ( pFilesToReload->IsFileInList(this: pFilesToReload, a2: filename) != 0 )
      this->Download(this, a2: nullptr, a3: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004A560
// Name: protected: void CTexture::WriteDataToShaderAPITexture(int,int,int,int,class IVTFTexture __near *,enum ImageFormat)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTexture::WriteDataToShaderAPITexture(
        CTexture *this,
        int nFrameCount,
        int nFaceCount,
        int nFirstFace,
        int nMipCount,
        IVTFTexture *pVTFTexture,
        ImageFormat fmt)
{
  CTexture *v7; // esi
  int v8; // ebx
  int v10; // ebx
  int v11; // esi
  unsigned __int8 *v12; // eax
  IShaderAPI_vtbl *v13; // ebx
  int v14; // eax
  int m_nFrameCount; // ecx
  int nWidth; // [esp+Ch] [ebp-18h] BYREF
  int nHeight; // [esp+10h] [ebp-14h] BYREF
  int v19; // [esp+14h] [ebp-10h]
  int nDepth; // [esp+18h] [ebp-Ch] BYREF
  int iFrame; // [esp+1Ch] [ebp-8h]
  int iFace; // [esp+20h] [ebp-4h]
  int iMip; // [esp+3Ch] [ebp+18h]

  v7 = this;
  v8 = 0;
  iFrame = 0;
  if ( this->m_nFrameCount != 0 )
  {
    do
    {
      g_pShaderAPI->ModifyTexture(this: g_pShaderAPI, a2: v7->m_pTextureHandles[v8]);
      iFace = 0;
      if ( nFaceCount > 0 )
      {
        do
        {
          v10 = 0;
          iMip = 0;
          if ( nMipCount > 0 )
          {
            do
            {
              pVTFTexture->ComputeMipLevelDimensions(this: pVTFTexture, a2: v10, a3: &nWidth, a4: &nHeight, a5: &nDepth);
              v11 = 0;
              if ( nDepth > 0 )
              {
                v19 = nFirstFace + iFace;
                do
                {
                  v12 = pVTFTexture->ImageData(this: pVTFTexture, a2: iFrame, a3: v19, a4: v10, a5: 0, a6: 0, a7: v11);
                  v13 = g_pShaderAPI->__vftable;
                  v14 = ((int (__thiscall *)(IVTFTexture *, _DWORD, unsigned __int8 *))pVTFTexture->Format)(
                          a1: pVTFTexture,
                          a2: 0,
                          a3: v12);
                  ((void (__thiscall *)(IShaderAPI *, int, int, ImageFormat, int, int, int, int))v13->TexImage2D)(
                    a1: g_pShaderAPI,
                    a2: iMip,
                    a3: iFace,
                    a4: fmt,
                    a5: v11,
                    a6: nWidth,
                    a7: nHeight,
                    a8: v14);
                  v10 = iMip;
                  ++v11;
                }
                while ( v11 < nDepth );
              }
              iMip = ++v10;
            }
            while ( v10 < nMipCount );
            v7 = this;
          }
          ++iFace;
        }
        while ( iFace < nFaceCount );
        v8 = iFrame;
      }
      m_nFrameCount = v7->m_nFrameCount;
      iFrame = ++v8;
    }
    while ( v8 < m_nFrameCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004A690
// Name: public: virtual int CTexture::GetTextureHandle(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTexture::GetTextureHandle(CTexture *this, int nFrame, int nTextureChannel)
{
  if ( nFrame < this->m_nFrameCount )
    return this->m_pTextureHandles[nFrame];
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1004A6B0
// Name: public: virtual void CTexture::GetLowResColorSample(float,float,float __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTexture::GetLowResColorSample(CTexture *this, float s, float t, float *color)
{
  float v4; // xmm2_4
  float v5; // xmm0_4
  int m_LowResImageWidth; // esi
  float v7; // xmm2_4
  int v8; // edi
  int v9; // edx
  int m_LowResImageHeight; // ecx
  float v11; // xmm0_4
  float v12; // xmm2_4
  int v13; // edx
  unsigned __int8 *m_pLowResImage; // ecx
  int v15; // eax
  unsigned __int8 *v16; // edx
  unsigned __int8 *v17; // eax
  float v18; // xmm6_4
  float v19; // xmm5_4
  float v20; // xmm7_4
  int v21; // esi
  unsigned __int8 *v22; // eax
  int v23; // esi
  unsigned __int8 *v24; // ecx
  float v25; // xmm3_4
  float v26; // xmm0_4
  int wholeTPlusOne; // [esp+18h] [ebp-8h]
  float fracT; // [esp+28h] [ebp+8h]
  int wholeSPlusOne; // [esp+2Ch] [ebp+Ch]

  if ( this->m_LowResImageWidth != 0 && this->m_LowResImageHeight != 0 )
  {
    v4 = s;
    if ( s < 0.0 )
      v4 = s + (float)(1.0 - (float)(int)s);
    v5 = t;
    if ( t < 0.0 )
      v5 = t + (float)(1.0 - (float)(int)t);
    m_LowResImageWidth = this->m_LowResImageWidth;
    v7 = (float)(v4 - (float)(int)v4) * (float)m_LowResImageWidth;
    v8 = (int)v7;
    v9 = ((int)v7 + 1) % m_LowResImageWidth;
    m_LowResImageHeight = this->m_LowResImageHeight;
    v11 = (float)(v5 - (float)(int)v5) * (float)m_LowResImageHeight;
    v12 = v7 - (float)(int)v7;
    fracT = v11 - (float)(int)v11;
    wholeSPlusOne = v9;
    v13 = ((int)v11 + 1) % m_LowResImageHeight;
    m_pLowResImage = this->m_pLowResImage;
    v15 = (int)v11 * m_LowResImageWidth;
    wholeTPlusOne = v13;
    v16 = &m_pLowResImage[2 * v15 + 2 * v8 + v15 + v8];
    v17 = &m_pLowResImage[2 * wholeSPlusOne + 2 * v15 + wholeSPlusOne + v15];
    v18 = (float)((float)((float)v17[1] * 0.0039215689) * v12)
        + (float)((float)((float)v16[1] * 0.0039215689) * (float)(1.0 - v12));
    v19 = (float)((float)((float)*v17 * 0.0039215689) * v12)
        + (float)((float)((float)*v16 * 0.0039215689) * (float)(1.0 - v12));
    v20 = (float)((float)v17[2] * 0.0039215689) * v12;
    v21 = wholeTPlusOne * m_LowResImageWidth;
    v22 = &m_pLowResImage[2 * v21 + 2 * v8 + v21 + v8];
    v23 = wholeSPlusOne + v21;
    v24 = &m_pLowResImage[2 * v23];
    v25 = (float)((float)((float)v24[v23 + 1] * 0.0039215689) * v12)
        + (float)((float)((float)v22[1] * 0.0039215689) * (float)(1.0 - v12));
    v26 = (float)((float)(1.0 - fracT)
                * (float)(v20 + (float)((float)((float)v16[2] * 0.0039215689) * (float)(1.0 - v12))))
        + (float)((float)((float)((float)((float)v24[v23 + 2] * 0.0039215689) * v12)
                        + (float)((float)((float)v22[2] * 0.0039215689) * (float)(1.0 - v12)))
                * fracT);
    *color = (float)((float)(1.0 - fracT) * v19)
           + (float)((float)((float)((float)((float)v24[v23] * 0.0039215689) * v12)
                           + (float)((float)((float)*v22 * 0.0039215689) * (float)(1.0 - v12)))
                   * fracT);
    color[1] = (float)((float)(1.0 - fracT) * v18) + (float)(v25 * fracT);
    color[2] = v26;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004A930
// Name: public: virtual int CTexture::GetApproximateVidMemBytes(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTexture::GetApproximateVidMemBytes(CTexture *this)
{
  ImageFormat v2; // edi
  int v3; // ebx
  bool v4; // al
  int numFrames; // [esp+Ch] [ebp-10h]
  int height; // [esp+10h] [ebp-Ch]
  int depth; // [esp+14h] [ebp-8h]

  v2 = this->GetImageFormat(this);
  v3 = this->GetActualWidth(this);
  height = this->GetActualHeight(this);
  depth = this->GetActualDepth(this);
  numFrames = this->GetNumAnimationFrames(this);
  v4 = this->IsMipmapped(this);
  return numFrames
       * ImageLoader::GetMemRequired(width: v3, height, depth, imageFormat: v2, mipmap: v4, pAdjustedHeight: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1004A9B0
// Name: public: virtual void CTexture::CopyFrameBufferToMe(int,struct Rect_t __near *,struct Rect_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTexture::CopyFrameBufferToMe(CTexture *this, int nRenderTargetID, Rect_t *pSrcRect, Rect_t *pDstRect)
{
  int *m_pTextureHandles; // eax

  m_pTextureHandles = this->m_pTextureHandles;
  if ( m_pTextureHandles != nullptr && this->m_nFrameCount != 0 )
    g_pShaderAPI->CopyRenderTargetToTextureEx(
      this: g_pShaderAPI,
      a2: *m_pTextureHandles,
      a3: nRenderTargetID,
      a4: pSrcRect,
      a5: pDstRect);
}

//------------------------------------------------------------------------------
// Address: 0x1004A9F0
// Name: public: virtual class ITexture __near * CTexture::GetEmbeddedTexture(int)
// Source: json
//------------------------------------------------------------------------------
CReferenceToHandleTexture *__thiscall CTexture::GetEmbeddedTexture(CReferenceToHandleTexture *this, int nIndex)
{
  return nIndex == 0 ? this : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1004AA10
// Name: public: virtual void CTexture::MarkAsPreloaded(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTexture::MarkAsPreloaded(CTexture *this, bool bSet)
{
  if ( bSet )
    this->m_nInternalFlags |= 4u;
  else
    this->m_nInternalFlags &= ~4u;
}

//------------------------------------------------------------------------------
// Address: 0x1004AA30
// Name: public: virtual void CTexture::MarkAsExcluded(bool,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTexture::MarkAsExcluded(CTexture *this, bool bSet, unsigned __int16 nDimensionsLimit)
{
  if ( bSet )
  {
    this->m_nInternalFlags |= 0x40u;
    this->m_nDesiredDimensionLimit = 0;
  }
  else
  {
    this->m_nInternalFlags &= ~0x40u;
    this->m_nDesiredDimensionLimit = nDimensionsLimit;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004AA60
// Name: public: virtual bool CTexture::UpdateExcludedState(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTexture::UpdateExcludedState(CTexture *this)
{
  unsigned int m_nInternalFlags; // eax

  m_nInternalFlags = this->m_nInternalFlags;
  if ( (((unsigned __int8)(m_nInternalFlags >> 5) ^ (unsigned __int8)(m_nInternalFlags >> 6)) & 1) == 0
    && this->m_nDesiredDimensionLimit == this->m_nActualDimensionLimit )
  {
    return 0;
  }
  if ( (m_nInternalFlags & 8) == 0 )
    this->Download(this, a2: nullptr, a3: 0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1004AAA0
// Name: SetBufferValue
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetBufferValue(char *chTxtFileBuffer, char *szLookupKey, char *szNewValue)
{
  char v3; // bl
  char *v4; // esi
  char *v5; // eax
  char *v6; // edi
  char *v7; // esi
  int v8; // eax
  char v9; // al
  unsigned __int8 *v10; // esi
  unsigned __int8 *v11; // edi
  signed __int8 i; // al
  char *v13; // eax
  const char *v14; // ecx
  unsigned int v15; // eax
  char *v16; // edx
  int v17; // esi
  char v18; // al
  unsigned int v19; // eax
  char *v20; // edx
  int v21; // esi
  char v22; // al
  unsigned int lenTmp; // [esp+Ch] [ebp-Ch]
  char *pch; // [esp+10h] [ebp-8h]
  unsigned int nTxtFileBufferLen; // [esp+14h] [ebp-4h]

  v3 = 0;
  lenTmp = strlen(szNewValue);
  v4 = chTxtFileBuffer;
  nTxtFileBufferLen = strlen(chTxtFileBuffer);
  strstr(str1: (unsigned __int8 *)chTxtFileBuffer, str2: (unsigned __int8 *)szLookupKey);
  v6 = v5;
  pch = v5;
  if ( v5 != nullptr )
  {
    while ( 1 )
    {
      v7 = &v6[strlen(szLookupKey)];
      v8 = *v7;
      if ( v8 >= 9 && (v8 <= 13 || v8 == 32) )
      {
        v9 = v7[1];
        v10 = (unsigned __int8 *)(v7 + 1);
        v11 = v10;
        if ( v9 != 0 )
        {
          while ( v9 >= 9 && (v9 <= 13 || v9 == 32) )
          {
            v9 = *++v10;
            if ( v9 == 0 )
              goto LABEL_18;
          }
          for ( i = *v10; i != 0; i = *++v10 )
          {
            if ( i >= 9 && (i <= 13 || i == 32) )
              break;
          }
        }
LABEL_18:
        memmove(dst: &v11[lenTmp], src: v10, count: (unsigned int)&chTxtFileBuffer[nTxtFileBufferLen - (_DWORD)v10 + 1]);
        memcpy(dst: v11, src: (unsigned __int8 *)szNewValue, count: lenTmp);
        nTxtFileBufferLen += lenTmp + v11 - v10;
        v6 = pch;
        v3 = 1;
      }
      strstr(str1: (unsigned __int8 *)v6 + 1, str2: (unsigned __int8 *)szLookupKey);
      pch = v13;
      if ( v13 == nullptr )
        break;
      v6 = v13;
    }
    if ( v3 != 0 )
      return v3;
    v4 = chTxtFileBuffer;
  }
  v14 = &v4[nTxtFileBufferLen];
  *(_WORD *)&v4[nTxtFileBufferLen + strlen(&v4[nTxtFileBufferLen])] = 10;
  v15 = (unsigned int)&v14[strlen(v14) + 1];
  v16 = szLookupKey;
  v17 = v15 - 1 - (_DWORD)szLookupKey;
  do
  {
    v18 = *v16;
    v16[v17] = *v16;
    ++v16;
  }
  while ( v18 != 0 );
  *(_WORD *)&v14[strlen(v14)] = 32;
  v19 = (unsigned int)&v14[strlen(v14) + 1];
  v20 = szNewValue;
  v21 = v19 - 1 - (_DWORD)szNewValue;
  do
  {
    v22 = *v20;
    v20[v21] = *v20;
    ++v20;
  }
  while ( v22 != 0 );
  *(_WORD *)&v14[strlen(v14)] = 10;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1004AC70
// Name: BufferReplace
// Source: json
//------------------------------------------------------------------------------
char *__usercall BufferReplace@<eax>(char *szFindData@<eax>, char *buf, char *szNewData)
{
  unsigned int v4; // edi
  unsigned int v5; // ebx
  unsigned __int8 *v6; // eax
  unsigned __int8 *v7; // esi
  unsigned __int8 *v8; // ebx
  unsigned int lNew; // [esp+Ch] [ebp-8h]
  unsigned int lFind; // [esp+10h] [ebp-4h]

  v4 = strlen(buf);
  lFind = strlen(szFindData);
  v5 = strlen(szNewData);
  lNew = v5;
  strstr(str1: (unsigned __int8 *)buf, str2: (unsigned __int8 *)szFindData);
  v7 = v6;
  if ( v6 == nullptr )
    return nullptr;
  v8 = &v6[v5];
  memmove(dst: v8, src: &v6[lFind], count: (unsigned int)&buf[v4 - (_DWORD)v6 - lFind]);
  memmove(dst: v7, src: (unsigned __int8 *)szNewData, count: lNew);
  return (char *)v8;
}

//------------------------------------------------------------------------------
// Address: 0x1004AD00
// Name: public: CP4Requirement::CP4Requirement(void)
// Source: json
//------------------------------------------------------------------------------
CP4Requirement *__thiscall CP4Requirement::CP4Requirement(CP4Requirement *this)
{
  struct CSysModule *Module; // eax
  void *(__cdecl *Factory)(const char *, int *); // eax
  IP4 *v4; // eax

  this->m_bLoadedModule = false;
  this->m_pP4Module = nullptr;
  if ( p4 == nullptr )
  {
    Module = Sys_LoadModule(pModuleName: "p4lib");
    this->m_pP4Module = Module;
    this->m_bLoadedModule = true;
    if ( Module != nullptr )
    {
      Factory = Sys_GetFactory(pModule: Module);
      if ( Factory != nullptr )
      {
        v4 = (IP4 *)Factory(a1: "VP4002", a2: nullptr);
        p4 = v4;
        if ( v4 == nullptr )
        {
LABEL_7:
          _Warning(a1: "Can't load p4lib.dll\n");
          return this;
        }
        v4->Connect(this: v4, a2: g_fnMatSystemConnectCreateInterface);
        p4->Init(this: p4);
      }
    }
    if ( p4 == nullptr )
      goto LABEL_7;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1004AD90
// Name: public: CP4Requirement::~CP4Requirement(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CP4Requirement::~CP4Requirement(CP4Requirement *this)
{
  if ( this->m_bLoadedModule && this->m_pP4Module != nullptr )
  {
    if ( p4 != nullptr )
    {
      p4->Shutdown(this: p4);
      p4->Disconnect(this: p4);
    }
    Sys_UnloadModule(pModule: this->m_pP4Module);
    this->m_pP4Module = nullptr;
    p4 = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004ADE0
// Name: public: void CUtlMemory<struct TextureLodOverride::OverrideInfo,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<TextureLodOverride::OverrideInfo,int>::Grow(
        CUtlMemory<TextureLodOverride::OverrideInfo,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  TextureLodOverride::OverrideInfo *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 16;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 2 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (TextureLodOverride::OverrideInfo *)_g_pMemAlloc->Realloc_2(
                                                              this: _g_pMemAlloc,
                                                              a2: m_pMemory,
                                                              a3: v7);
    else
      this->m_pMemory = (TextureLodOverride::OverrideInfo *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004AE80
// Name: protected: void CTexture::Init(int,int,int,enum ImageFormat,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTexture::Init(
        CTexture *this,
        unsigned __int16 w,
        unsigned __int16 h,
        unsigned __int16 d,
        ImageFormat fmt,
        unsigned int iFlags,
        unsigned __int16 iFrameCount)
{
  void (*FreeShaderAPITextures)(void); // edx

  FreeShaderAPITextures = (void (*)(void))this->FreeShaderAPITextures;
  this->m_nInternalFlags &= ~1u;
  FreeShaderAPITextures();
  if ( this->m_pTextureHandles != nullptr )
  {
    free(pMem: this->m_pTextureHandles);
    this->m_pTextureHandles = nullptr;
  }
  this->m_nMappingHeight = h;
  this->m_nMappingWidth = w;
  this->m_nFrameCount = iFrameCount;
  this->m_nMappingDepth = d;
  this->m_ImageFormat = fmt;
  this->m_nMipSkipCount = 0;
  *(_DWORD *)&this->m_nActualWidth = 0;
  *(_DWORD *)&this->m_nActualDepth = 1;
  this->m_nFlags = iFlags;
  CTexture::AllocateTextureHandles(this);
}

//------------------------------------------------------------------------------
// Address: 0x1004AF00
// Name: protected: void CTexture::FreeOptimalReadBuffer(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTexture::FreeOptimalReadBuffer(CTexture *this, int nMaxSize)
{
  void *v2; // edx

  v2 = s_pOptimalReadBuffer;
  if ( s_pOptimalReadBuffer != nullptr && s_nOptimalReadBufferSize >= nMaxSize )
  {
    if ( mat_spewalloc.m_pParent != nullptr && mat_spewalloc.m_pParent->m_Value.m_nValue != 0 )
    {
      _Msg(a1: "Freeing optimal read buffer of %d bytes @ 0x%8.8X\n", s_nOptimalReadBufferSize, s_pOptimalReadBuffer);
      v2 = s_pOptimalReadBuffer;
    }
    g_pFullFileSystem->FreeOptimalReadBuffer(this: g_pFullFileSystem, a2: v2);
    s_pOptimalReadBuffer = nullptr;
    s_nOptimalReadBufferSize = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004AF70
// Name: public: void CTexture::InitRenderTarget(char const __near *,int,int,enum RenderTargetSizeMode_t,enum ImageFormat,enum RenderTargetType_t,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTexture::InitRenderTarget(
        CTexture *this,
        const char *pRTName,
        unsigned __int16 w,
        unsigned __int16 h,
        RenderTargetSizeMode_t sizeMode,
        ImageFormat fmt,
        RenderTargetType_t type,
        unsigned int textureFlags,
        char renderTargetFlags)
{
  ImageFormat v10; // ebx
  RenderTargetType_t v11; // eax
  unsigned int v12; // edi
  bool v13; // zf
  unsigned __int16 v14; // cx
  unsigned __int16 v15; // dx
  char pName[128]; // [esp+Ch] [ebp-80h] BYREF
  unsigned __int16 nFrameCount; // [esp+94h] [ebp+8h]

  if ( pRTName != nullptr )
  {
    CTexture::SetName(this, pName: pRTName);
  }
  else
  {
    V_snprintf(pDest: pName, maxLen: 128, pFormat: "__render_target_%d", id);
    ++id;
    CTexture::SetName(this, pName);
  }
  if ( (renderTargetFlags & 1) == 0
    || (v10 = IMAGE_FORMAT_RGBA16161616F, g_pHWConfig->GetHDRType(this: g_pHWConfig) != HDR_TYPE_FLOAT) )
  {
    v10 = fmt;
  }
  v11 = type;
  v12 = textureFlags | 0x8100;
  nFrameCount = 1;
  if ( type == RENDER_TARGET_NO_DEPTH )
  {
    v12 = textureFlags | 0x808100;
  }
  else if ( type == RENDER_TARGET_WITH_DEPTH
         || type == RENDER_TARGET_ONLY_DEPTH
         || (v13 = !g_pShaderAPI->DoRenderTargetsNeedSeparateDepthBuffer(this: g_pShaderAPI), v11 = type, !v13) )
  {
    v12 |= 0x10000u;
    nFrameCount = 2;
  }
  if ( (renderTargetFlags & 0x10) != 0 )
    this->m_nInternalFlags |= 0x80u;
  v14 = w;
  v15 = h;
  this->m_nOriginalRenderTargetType = v11;
  this->m_RenderTargetSizeMode = sizeMode;
  this->m_nOriginalRTWidth = v14;
  this->m_nOriginalRTHeight = v15;
  if ( ImageLoader::ImageFormatInfo(fmt: v10)->m_nNumAlphaBits <= 1u )
  {
    if ( ImageLoader::ImageFormatInfo(fmt: v10)->m_nNumAlphaBits == 1 )
      v12 |= 0x1000u;
  }
  else
  {
    v12 |= 0x2000u;
  }
  CTexture::ApplyRenderTargetSizeMode(this, width: (int *)&w, height: (int *)&h, fmt: v10);
  CTexture::Init(this, w, h, d: 1u, fmt: v10, iFlags: v12, iFrameCount: nFrameCount);
  CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&type + 1, pStr: "RenderTargets");
  this->m_TextureGroupName.m_Id = HIWORD(type);
}

//------------------------------------------------------------------------------
// Address: 0x1004B0C0
// Name: public: void CTexture::InitProceduralTexture(char const __near *,char const __near *,int,int,int,enum ImageFormat,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTexture::InitProceduralTexture(
        CTexture *this,
        const char *pTextureName,
        const char *pTextureGroupName,
        unsigned __int16 w,
        unsigned __int16 h,
        unsigned __int16 d,
        ImageFormat fmt,
        int nFlags)
{
  ImageFormat v9; // ebx
  unsigned int v10; // esi
  unsigned int m_nNumAlphaBits; // eax

  CTexture::SetName(this, pName: pTextureName);
  v9 = fmt;
  v10 = nFlags & 0xFFFFF7DF | 0x800;
  m_nNumAlphaBits = ImageLoader::ImageFormatInfo(fmt)->m_nNumAlphaBits;
  if ( m_nNumAlphaBits <= 1 )
  {
    if ( m_nNumAlphaBits == 1 )
      v10 |= 0x1000u;
  }
  else
  {
    v10 |= 0x2000u;
  }
  CTexture::Init(this, w, h, d, fmt: v9, iFlags: v10, iFrameCount: 1u);
  CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&pTextureName + 1, pStr: pTextureGroupName);
  this->m_TextureGroupName.m_Id = HIWORD(pTextureName);
}

//------------------------------------------------------------------------------
// Address: 0x1004B140
// Name: protected: virtual bool CTexture::AllocateShaderAPITextures(void)
// Source: json
//------------------------------------------------------------------------------
bool __usercall CTexture::AllocateShaderAPITextures@<al>(CTexture *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  bool result; // al
  unsigned int m_nFlags; // edi
  int m_nFrameCount; // eax
  bool (__thiscall *IsProcedural)(struct CTexture *); // eax
  int m_nActualDepth; // ebx
  const char *v9; // eax
  IShaderAPI_vtbl *v10; // edi
  int v11; // eax
  const char *v12; // eax
  char debugName[128]; // [esp+4h] [ebp-8Ch] BYREF
  int nCreateFlags; // [esp+84h] [ebp-Ch]
  int nCopies; // [esp+88h] [ebp-8h]
  int nCount; // [esp+8Ch] [ebp-4h]

  result = g_pShaderAPI->CanDownloadTextures(this: g_pShaderAPI);
  if ( result )
  {
    m_nFlags = this->m_nFlags;
    nCreateFlags = GetCreationFlags(
                     iTextureFlags: m_nFlags,
                     iInternalTextureFlags: this->m_nInternalFlags,
                     fmt: this->m_ImageFormat);
    m_nFrameCount = this->m_nFrameCount;
    nCount = m_nFrameCount;
    if ( (m_nFlags & 0x8000) != 0 && (m_nFlags & 0x10000) != 0 && m_nFrameCount == 2 )
      nCount = 1;
    IsProcedural = this->IsProcedural;
    m_nActualDepth = 1;
    nCopies = 1;
    if ( ((unsigned __int8 (__thiscall *)(CTexture *, int, int))IsProcedural)(a1: this, a2: a3, a3: a2) != 0
      && (this->m_nFlags & 0x40000) == 0 )
    {
      nCopies = 6;
    }
    if ( (this->m_nFlags & 0x10000) == 0 || this->m_nOriginalRenderTargetType != RENDER_TARGET_ONLY_DEPTH )
      m_nActualDepth = this->m_nActualDepth;
    v9 = CUtlSymbol::String(this: &this->m_TextureGroupName);
    v10 = g_pShaderAPI->__vftable;
    v11 = ((int (__thiscall *)(CTexture *, const char *))this->GetName)(a1: this, a2: v9);
    ((void (__thiscall *)(IShaderAPI *, int *, int, _DWORD, _DWORD, int, ImageFormat, _DWORD, int, int, int))v10->CreateTextures)(
      a1: g_pShaderAPI,
      a2: this->m_pTextureHandles,
      a3: nCount,
      a4: this->m_nActualWidth,
      a5: this->m_nActualHeight,
      a6: m_nActualDepth,
      a7: this->m_ImageFormat,
      a8: this->m_nActualMipCount,
      a9: nCopies,
      a10: nCreateFlags,
      a11: v11);
    if ( (this->m_nFlags & 0x10000) != 0 )
    {
      v12 = (const char *)this->GetName(this);
      sprintf(string: debugName, format: "%s_ZBuffer", v12);
      this->m_pTextureHandles[1] = g_pShaderAPI->CreateDepthTexture(
                                     this: g_pShaderAPI,
                                     a2: this->m_ImageFormat,
                                     a3: this->m_nActualWidth,
                                     a4: this->m_nActualHeight,
                                     a5: debugName,
                                     a6: this->m_nOriginalRenderTargetType == RENDER_TARGET_ONLY_DEPTH,
                                     a7: false);
    }
    this->m_nInternalFlags |= 2u;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004B290
// Name: protected: virtual void CTexture::FreeShaderAPITextures(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTexture::FreeShaderAPITextures(CTexture *this)
{
  int v2; // edi

  if ( this->m_pTextureHandles != nullptr && (this->m_nInternalFlags & 2) != 0 )
  {
    v2 = this->m_nFrameCount - 1;
    if ( this->m_nFrameCount != 0 )
    {
      do
      {
        if ( g_pShaderAPI->IsTexture(this: g_pShaderAPI, a2: this->m_pTextureHandles[v2]) )
        {
          g_pShaderAPI->DeleteTexture(this: g_pShaderAPI, a2: this->m_pTextureHandles[v2]);
          this->m_pTextureHandles[v2] = 0;
        }
        --v2;
      }
      while ( v2 >= 0 );
    }
    this->m_nInternalFlags &= ~2u;
  }
  else
  {
    this->m_nInternalFlags &= ~2u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004B300
// Name: protected: int CTexture::ComputeActualMipCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTexture::ComputeActualMipCount(CTexture *this)
{
  bool v2; // zf
  int result; // eax
  unsigned int m_nFlags; // eax
  bool v5; // bl
  int m_nActualWidth; // edx
  int m_nActualHeight; // ecx
  int v8; // esi
  _OSVERSIONINFOEXA osvi; // [esp+4h] [ebp-A0h] BYREF
  bool bForceTextureAllMips; // [esp+A3h] [ebp-1h]

  v2 = (this->m_nFlags & 0x4000) == 0;
  bForceTextureAllMips = g_bForceTextureAllMips;
  if ( !v2 && !g_pHWConfig->SupportsMipmappedCubemaps(this: g_pHWConfig) )
    return 1;
  m_nFlags = this->m_nFlags;
  if ( (m_nFlags & 0x100) != 0 )
    return 1;
  if ( (m_nFlags & 0x400) != 0 )
    bForceTextureAllMips = true;
  v5 = (m_nFlags & 0x10000000) != 0;
  if ( r_emulategl.m_pParent != nullptr && r_emulategl.m_pParent->m_Value.m_nValue != 0 )
    bForceTextureAllMips = true;
  memset(dst: (unsigned __int8 *)&osvi, value: 0, count: sizeof(osvi));
  osvi.dwOSVersionInfoSize = 156;
  if ( (GetVersionExA(lpVersionInformation: (LPOSVERSIONINFOA)&osvi) && osvi.dwMajorVersion >= 6 || bForceTextureAllMips)
    && !v5 )
  {
    return ImageLoader::GetNumMipMapLevels(
             width: this->m_nActualWidth,
             height: this->m_nActualHeight,
             depth: this->m_nActualDepth);
  }
  m_nActualWidth = this->m_nActualWidth;
  m_nActualHeight = this->m_nActualHeight;
  for ( result = 1; ; ++result )
  {
    v8 = m_nActualHeight;
    if ( m_nActualHeight >= m_nActualWidth )
      v8 = m_nActualWidth;
    if ( v8 <= 32 )
      break;
    m_nActualHeight >>= 1;
    m_nActualWidth >>= 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004B400
// Name: public: virtual void CTexture::DecrementReferenceCount(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTexture::DecrementReferenceCount(CMaterial *this)
{
  _InterlockedExchangeAdd(&this->m_RefCount.m_value, 0xFFFFFFFF);
}

//------------------------------------------------------------------------------
// Address: 0x1004B410
// Name: protected: void CTexture::GenerateShowMipLevelsTextures(class IVTFTexture __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTexture::GenerateShowMipLevelsTextures(CTexture *this, IVTFTexture *pTexture)
{
  IVTFTexture *v2; // edi
  int (__thiscall *FrameCount)(IVTFTexture *); // eax
  int (__thiscall *FaceCount)(IVTFTexture *); // eax
  int v5; // ebx
  int v6; // esi
  IVTFTexture_vtbl *v7; // edx
  void (__thiscall *ComputeMipLevelDimensions)(IVTFTexture *, int, int *, int *, int *); // edx
  unsigned __int16 v9; // si
  int v10; // ebx
  int v11; // eax
  __int16 v12; // di
  _BYTE *v13; // esi
  unsigned __int8 v14; // al
  unsigned int v15; // edx
  unsigned int v16; // edx
  int v17; // eax
  unsigned __int64 v18; // kr00_8
  unsigned __int64 v19; // rax
  int v20; // ebx
  int v21; // esi
  __int64 v22; // rax
  __int64 v23; // rax
  unsigned __int64 v24; // rax
  int v25; // ebx
  int v26; // esi
  unsigned __int8 *v27; // esi
  ImageFormat v28; // eax
  int (__thiscall *v29)(IVTFTexture *); // eax
  int v30; // esi
  int (__thiscall *v31)(IVTFTexture *); // eax
  int v32; // esi
  _BYTE *pixelWriter_4; // [esp+8h] [ebp-68h]
  unsigned __int8 pixelWriter_10; // [esp+Eh] [ebp-62h]
  int pixelWriter_12; // [esp+10h] [ebp-60h]
  int pixelWriter_16; // [esp+14h] [ebp-5Ch]
  int pixelWriter_20; // [esp+18h] [ebp-58h]
  int pixelWriter_24; // [esp+1Ch] [ebp-54h]
  int pixelWriter_28; // [esp+20h] [ebp-50h]
  unsigned __int8 pixelWriter_32; // [esp+24h] [ebp-4Ch]
  __int64 v41; // [esp+28h] [ebp-48h]
  int v42; // [esp+30h] [ebp-40h]
  int v43; // [esp+34h] [ebp-3Ch]
  int v44; // [esp+38h] [ebp-38h]
  int y; // [esp+3Ch] [ebp-34h]
  int x; // [esp+40h] [ebp-30h]
  int iMip; // [esp+44h] [ebp-2Ch]
  int nWidth; // [esp+48h] [ebp-28h] BYREF
  int red; // [esp+4Ch] [ebp-24h]
  int green; // [esp+50h] [ebp-20h]
  int nHeight; // [esp+54h] [ebp-1Ch] BYREF
  int nDepth; // [esp+58h] [ebp-18h] BYREF
  int z; // [esp+5Ch] [ebp-14h]
  int v54; // [esp+60h] [ebp-10h]
  int iFrame; // [esp+64h] [ebp-Ch]
  int iFace; // [esp+68h] [ebp-8h]
  int blue; // [esp+6Ch] [ebp-4h]

  v2 = pTexture;
  if ( pTexture->FaceCount(this: pTexture) <= 1 )
  {
    switch ( pTexture->Format(this: pTexture) )
    {
      case IMAGE_FORMAT_UV88:
      case IMAGE_FORMAT_RGBA16161616F:
      case IMAGE_FORMAT_R32F:
      case IMAGE_FORMAT_RGB323232F:
      case IMAGE_FORMAT_RGBA32323232F:
        return;
      default:
        FrameCount = pTexture->FrameCount;
        iFrame = 0;
        if ( FrameCount(this: pTexture) > 0 )
        {
          do
          {
            FaceCount = v2->FaceCount;
            iFace = 0;
            if ( FaceCount(this: v2) > 0 )
            {
              do
              {
                v5 = 0;
                iMip = 0;
                if ( v2->MipCount(this: v2) > 0 )
                {
                  while ( 1 )
                  {
                    v6 = v5 + 1;
                    green = (unsigned __int8)-((((_BYTE)v5 + 1) & 1) != 0);
                    v7 = v2->__vftable;
                    red = (unsigned __int8)-((((_BYTE)v5 + 1) & 2) != 0);
                    ComputeMipLevelDimensions = v7->ComputeMipLevelDimensions;
                    blue = (unsigned __int8)-((((_BYTE)v5 + 1) & 4) != 0);
                    v43 = v5 + 1;
                    ComputeMipLevelDimensions(this: v2, a2: v5, a3: &nWidth, a4: &nHeight, a5: &nDepth);
                    if ( v2->Format(this: v2) == IMAGE_FORMAT_DXT1
                      || v2->Format(this: v2) == IMAGE_FORMAT_DXT5
                      || v2->Format(this: v2) == IMAGE_FORMAT_ATI1N
                      || v2->Format(this: v2) == IMAGE_FORMAT_ATI2N )
                    {
                      v27 = v2->ImageData(this: v2, a2: iFrame, a3: iFace, a4: v5, a5: 0, a6: 0, a7: 0);
                      v28 = v2->Format(this: v2);
                      FillCompressedTextureWithSingleColor(
                        blue,
                        width: nWidth,
                        red,
                        green,
                        alpha: v27,
                        pImageData: nHeight,
                        height: nDepth,
                        depth: v28);
LABEL_62:
                      v6 = v43;
                    }
                    else
                    {
                      z = 0;
                      if ( nDepth > 0 )
                      {
                        while ( 1 )
                        {
                          v9 = v2->RowSizeInBytes(this: v2, a2: v5);
                          v10 = (int)v2->ImageData(this: v2, a2: iFrame, a3: iFace, a4: v5, a5: 0, a6: 0, a7: z);
                          switch ( v2->Format(this: v2) )
                          {
                            case IMAGE_FORMAT_RGBA8888:
                            case IMAGE_FORMAT_UVWQ8888:
                              v11 = 255;
                              pixelWriter_10 = 4;
                              pixelWriter_12 = 0x80000;
                              v12 = 16;
                              pixelWriter_16 = 1572880;
                              pixelWriter_20 = 255;
                              goto LABEL_32;
                            case IMAGE_FORMAT_BGR888:
                              v12 = 0;
                              v11 = 255;
                              pixelWriter_10 = 3;
                              pixelWriter_12 = 524304;
                              pixelWriter_16 = 0;
                              pixelWriter_20 = 255;
                              pixelWriter_32 = 0;
                              goto LABEL_33;
                            case IMAGE_FORMAT_I8:
                              pixelWriter_10 = 1;
                              goto LABEL_30;
                            case IMAGE_FORMAT_A8:
                              v12 = 0;
                              v11 = 0;
                              pixelWriter_10 = 1;
                              pixelWriter_12 = 0;
                              pixelWriter_16 = 0;
                              pixelWriter_20 = 0;
                              pixelWriter_32 = -1;
                              goto LABEL_33;
                            case IMAGE_FORMAT_BGRA8888:
                              v11 = 255;
                              pixelWriter_10 = 4;
                              pixelWriter_12 = 524304;
                              v12 = 0;
                              pixelWriter_16 = 1572864;
                              pixelWriter_20 = 255;
                              goto LABEL_32;
                            case IMAGE_FORMAT_BGRX8888:
                              v12 = 0;
                              v11 = 255;
                              pixelWriter_10 = 4;
                              pixelWriter_12 = 524304;
                              pixelWriter_16 = 1572864;
                              pixelWriter_20 = 255;
                              pixelWriter_32 = 0;
                              goto LABEL_33;
                            case IMAGE_FORMAT_BGR565:
                              v11 = 248;
                              pixelWriter_10 = 2;
                              pixelWriter_12 = 196616;
                              v12 = -3;
                              pixelWriter_16 = 65533;
                              pixelWriter_20 = 248;
                              pixelWriter_24 = 252;
                              pixelWriter_32 = 0;
                              goto LABEL_34;
                            case IMAGE_FORMAT_BGRX5551:
                            case IMAGE_FORMAT_BGRA5551:
                              v11 = 248;
                              pixelWriter_10 = 2;
                              pixelWriter_12 = 131079;
                              v12 = -3;
                              pixelWriter_16 = 589821;
                              pixelWriter_20 = 248;
                              pixelWriter_32 = 0x80;
                              goto LABEL_33;
                            case IMAGE_FORMAT_BGRA4444:
                              v11 = 240;
                              pixelWriter_10 = 2;
                              pixelWriter_12 = 4;
                              v12 = -4;
                              pixelWriter_16 = 589820;
                              pixelWriter_20 = 240;
                              goto LABEL_32;
                            case IMAGE_FORMAT_RGBA16161616F:
                            case IMAGE_FORMAT_RGBA16161616:
                              v11 = 0xFFFF;
                              pixelWriter_10 = 8;
                              pixelWriter_12 = 0x100000;
                              v12 = 32;
                              pixelWriter_16 = 3145760;
                              pixelWriter_20 = 0xFFFF;
                              goto LABEL_32;
                            case IMAGE_FORMAT_R32F:
                              pixelWriter_10 = 4;
                              pixelWriter_20 = -1;
                              goto LABEL_31;
                            case IMAGE_FORMAT_RGBA32323232F:
                              v11 = -1;
                              pixelWriter_10 = 16;
                              pixelWriter_12 = 0x200000;
                              v12 = 64;
                              pixelWriter_16 = 6291520;
                              pixelWriter_20 = -1;
                              goto LABEL_32;
                            case IMAGE_FORMAT_BGRA1010102:
                              v11 = 1023;
                              pixelWriter_10 = 4;
                              pixelWriter_12 = 655380;
                              v12 = 0;
                              pixelWriter_16 = 1966080;
                              pixelWriter_20 = 1023;
                              pixelWriter_32 = 3;
                              goto LABEL_33;
                            default:
                              pixelWriter_10 = 0;
LABEL_30:
                              pixelWriter_20 = 255;
LABEL_31:
                              v12 = 0;
                              pixelWriter_12 = 0;
                              pixelWriter_16 = 0;
                              v11 = 0;
LABEL_32:
                              pixelWriter_32 = v11;
LABEL_33:
                              pixelWriter_24 = v11;
LABEL_34:
                              pixelWriter_28 = v11;
                              y = 0;
                              if ( nHeight > 0 )
                              {
                                v42 = v9;
                                v13 = (_BYTE *)v10;
                                v44 = v10;
                                do
                                {
                                  pixelWriter_4 = v13;
                                  x = 0;
                                  if ( nWidth > 0 )
                                  {
                                    v14 = pixelWriter_10;
                                    v54 = pixelWriter_10;
                                    while ( 1 )
                                    {
                                      if ( v14 != 0 )
                                      {
                                        if ( v14 >= 5u )
                                        {
                                          v18 = (unsigned __int64)(red & (unsigned int)pixelWriter_20) << pixelWriter_12;
                                          v19 = (unsigned __int64)(green & (unsigned int)pixelWriter_24) << SBYTE2(pixelWriter_12);
                                          v20 = v19 | v18;
                                          LODWORD(v22) = blue & pixelWriter_28;
                                          v21 = HIDWORD(v19) | HIDWORD(v18);
                                          HIDWORD(v22) = 0;
                                          if ( v12 <= 0 )
                                            v23 = v22 >> -(char)v12;
                                          else
                                            v23 = v22 << v12;
                                          v41 = v23;
                                          v24 = (unsigned __int64)pixelWriter_32 << SBYTE2(pixelWriter_16);
                                          v25 = v41 | v24 | v20;
                                          v26 = HIDWORD(v41) | HIDWORD(v24) | v21;
                                          if ( v54 == 6 )
                                          {
                                            *(_DWORD *)pixelWriter_4 = v25;
                                            *((_WORD *)pixelWriter_4 + 2) = v26;
                                          }
                                          else if ( v54 == 8 )
                                          {
                                            *(_DWORD *)pixelWriter_4 = v25;
                                            *((_DWORD *)pixelWriter_4 + 1) = v26;
                                          }
                                          v13 = pixelWriter_4;
                                        }
                                        else
                                        {
                                          v15 = blue & pixelWriter_28;
                                          if ( v12 <= 0 )
                                            v16 = v15 >> -(char)pixelWriter_16;
                                          else
                                            v16 = v15 << pixelWriter_16;
                                          v17 = v16
                                              | (pixelWriter_32 << SBYTE2(pixelWriter_16))
                                              | ((green & pixelWriter_24) << SBYTE2(pixelWriter_12))
                                              | ((red & pixelWriter_20) << pixelWriter_12);
                                          switch ( v54 )
                                          {
                                            case 1:
                                              *v13 = v17;
                                              break;
                                            case 2:
                                              *(_WORD *)v13 = v17;
                                              break;
                                            case 3:
                                              *(_WORD *)v13 = v17;
                                              v13[2] = BYTE2(v17);
                                              break;
                                            case 4:
                                              *(_DWORD *)v13 = v17;
                                              break;
                                            default:
                                              break;
                                          }
                                        }
                                      }
                                      v13 += v54;
                                      pixelWriter_4 = v13;
                                      if ( ++x >= nWidth )
                                        break;
                                      v14 = pixelWriter_10;
                                    }
                                  }
                                  v13 = (_BYTE *)(v42 + v44);
                                  ++y;
                                  v44 += v42;
                                }
                                while ( y < nHeight );
                              }
                              v2 = pTexture;
                              if ( ++z >= nDepth )
                                goto LABEL_62;
                              v5 = iMip;
                              break;
                          }
                        }
                      }
                    }
                    iMip = v6;
                    if ( v6 >= v2->MipCount(this: v2) )
                      break;
                    v5 = v6;
                  }
                }
                v29 = v2->FaceCount;
                v30 = ++iFace;
              }
              while ( v30 < v29(this: v2) );
            }
            v31 = v2->FrameCount;
            v32 = ++iFrame;
          }
          while ( v32 < v31(this: v2) );
        }
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004BA20
// Name: protected: void CTexture::CopyLowResImageToTexture(class IVTFTexture __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTexture::CopyLowResImageToTexture(CTexture *this, IVTFTexture *pTexture)
{
  CTexture *v3; // edi
  unsigned int v4; // ebx
  int v5; // eax
  unsigned __int16 v6; // ax
  unsigned __int16 m_LowResImageHeight; // dx
  int v8; // eax
  __int16 v9; // bx
  unsigned __int8 *m_pLowResImage; // eax
  unsigned __int8 *v11; // ecx
  unsigned __int8 i; // dl
  int v13; // esi
  int v14; // edi
  unsigned int v15; // eax
  int v16; // eax
  unsigned int v17; // edx
  unsigned int v18; // edx
  int v19; // eax
  unsigned __int64 v20; // rdi
  __int64 v21; // rax
  __int64 v22; // rax
  unsigned __int64 v23; // rdi
  unsigned __int16 v24; // [esp+0h] [ebp-58h]
  unsigned __int16 v25; // [esp+4h] [ebp-54h]
  ImageFormat v26; // [esp+8h] [ebp-50h]
  unsigned int pixelWriter; // [esp+Ch] [ebp-4Ch]
  unsigned __int8 *pixelWritera; // [esp+Ch] [ebp-4Ch]
  unsigned __int16 pixelWriter_4; // [esp+10h] [ebp-48h]
  unsigned __int8 *pixelWriter_4a; // [esp+10h] [ebp-48h]
  unsigned __int8 pixelWriter_10; // [esp+16h] [ebp-42h]
  int pixelWriter_12; // [esp+18h] [ebp-40h]
  int pixelWriter_16; // [esp+1Ch] [ebp-3Ch]
  int pixelWriter_20; // [esp+20h] [ebp-38h]
  char pixelWriter_24; // [esp+24h] [ebp-34h]
  int pixelWriter_28; // [esp+28h] [ebp-30h]
  unsigned __int8 pixelWriter_32; // [esp+2Ch] [ebp-2Ch]
  unsigned __int8 *v38; // [esp+40h] [ebp-18h]
  int y; // [esp+44h] [ebp-14h]
  unsigned __int8 *pLowResImage; // [esp+48h] [ebp-10h]
  int x; // [esp+50h] [ebp-8h]
  int blue; // [esp+54h] [ebp-4h]
  unsigned __int16 pTexturea; // [esp+60h] [ebp+8h]

  v3 = this;
  v4 = pTexture->Flags(this: pTexture) & 0xFFFF8E4C | 0x101;
  v5 = ((int (__thiscall *)(IVTFTexture *, int, int, unsigned int, int))pTexture->Height)(
         a1: pTexture,
         a2: 1,
         a3: 3,
         a4: v4,
         a5: 1);
  v6 = ((int (__thiscall *)(IVTFTexture *, int))pTexture->Width)(a1: pTexture, a2: v5);
  CTexture::Init(this: v3, w: v6, h: v24, d: v25, fmt: v26, iFlags: pixelWriter, iFrameCount: pixelWriter_4);
  ((void (__thiscall *)(IVTFTexture *, _DWORD, _DWORD))pTexture->Init)(
    a1: pTexture,
    a2: v3->m_LowResImageWidth,
    a3: v3->m_LowResImageHeight);
  m_LowResImageHeight = v3->m_LowResImageHeight;
  v3->m_nActualWidth = v3->m_LowResImageWidth;
  v3->m_nActualHeight = m_LowResImageHeight;
  *(_DWORD *)&v3->m_nActualDepth = 65537;
  pTexturea = pTexture->RowSizeInBytes(this: pTexture, a2: 0);
  pixelWritera = pTexture->ImageData_2(this: pTexture, a2: 0, a3: 0, a4: 0);
  switch ( pTexture->Format(this: pTexture) )
  {
    case IMAGE_FORMAT_RGBA8888:
    case IMAGE_FORMAT_UVWQ8888:
      v8 = 255;
      pixelWriter_10 = 4;
      pixelWriter_12 = 0x80000;
      v9 = 16;
      pixelWriter_16 = 1572880;
      pixelWriter_20 = 255;
      goto LABEL_18;
    case IMAGE_FORMAT_BGR888:
      v9 = 0;
      v8 = 255;
      pixelWriter_10 = 3;
      pixelWriter_12 = 524304;
      pixelWriter_16 = 0;
      pixelWriter_20 = 255;
      pixelWriter_32 = 0;
      goto LABEL_19;
    case IMAGE_FORMAT_I8:
      pixelWriter_10 = 1;
      goto LABEL_16;
    case IMAGE_FORMAT_A8:
      v9 = 0;
      v8 = 0;
      pixelWriter_10 = 1;
      pixelWriter_12 = 0;
      pixelWriter_16 = 0;
      pixelWriter_20 = 0;
      pixelWriter_32 = -1;
      goto LABEL_19;
    case IMAGE_FORMAT_BGRA8888:
      v8 = 255;
      pixelWriter_10 = 4;
      pixelWriter_12 = 524304;
      v9 = 0;
      pixelWriter_16 = 1572864;
      pixelWriter_20 = 255;
      goto LABEL_18;
    case IMAGE_FORMAT_BGRX8888:
      v9 = 0;
      v8 = 255;
      pixelWriter_10 = 4;
      pixelWriter_12 = 524304;
      pixelWriter_16 = 1572864;
      pixelWriter_20 = 255;
      pixelWriter_32 = 0;
      goto LABEL_19;
    case IMAGE_FORMAT_BGR565:
      v8 = 248;
      pixelWriter_10 = 2;
      pixelWriter_12 = 196616;
      v9 = -3;
      pixelWriter_16 = 65533;
      pixelWriter_20 = 248;
      pixelWriter_24 = -4;
      pixelWriter_32 = 0;
      goto LABEL_20;
    case IMAGE_FORMAT_BGRX5551:
    case IMAGE_FORMAT_BGRA5551:
      v8 = 248;
      pixelWriter_10 = 2;
      pixelWriter_12 = 131079;
      v9 = -3;
      pixelWriter_16 = 589821;
      pixelWriter_20 = 248;
      pixelWriter_32 = 0x80;
      goto LABEL_19;
    case IMAGE_FORMAT_BGRA4444:
      v8 = 240;
      pixelWriter_10 = 2;
      pixelWriter_12 = 4;
      v9 = -4;
      pixelWriter_16 = 589820;
      pixelWriter_20 = 240;
      goto LABEL_18;
    case IMAGE_FORMAT_RGBA16161616F:
    case IMAGE_FORMAT_RGBA16161616:
      v8 = 0xFFFF;
      pixelWriter_10 = 8;
      pixelWriter_12 = 0x100000;
      v9 = 32;
      pixelWriter_16 = 3145760;
      pixelWriter_20 = 0xFFFF;
      goto LABEL_18;
    case IMAGE_FORMAT_R32F:
      pixelWriter_10 = 4;
      pixelWriter_20 = -1;
      goto LABEL_17;
    case IMAGE_FORMAT_RGBA32323232F:
      v8 = -1;
      pixelWriter_10 = 16;
      pixelWriter_12 = 0x200000;
      v9 = 64;
      pixelWriter_16 = 6291520;
      pixelWriter_20 = -1;
      goto LABEL_18;
    case IMAGE_FORMAT_BGRA1010102:
      v8 = 1023;
      pixelWriter_10 = 4;
      pixelWriter_12 = 655380;
      v9 = 0;
      pixelWriter_16 = 1966080;
      pixelWriter_20 = 1023;
      pixelWriter_32 = 3;
      goto LABEL_19;
    default:
      pixelWriter_10 = 0;
LABEL_16:
      pixelWriter_20 = 255;
LABEL_17:
      v9 = 0;
      pixelWriter_12 = 0;
      pixelWriter_16 = 0;
      v8 = 0;
LABEL_18:
      pixelWriter_32 = v8;
LABEL_19:
      pixelWriter_24 = v8;
LABEL_20:
      pixelWriter_28 = v8;
      m_pLowResImage = v3->m_pLowResImage;
      y = 0;
      if ( v3->m_LowResImageHeight != 0 )
      {
        v11 = pixelWritera;
        v38 = pixelWritera;
        do
        {
          pixelWriter_4a = v11;
          x = 0;
          if ( v3->m_LowResImageWidth != 0 )
          {
            for ( i = pixelWriter_10; ; i = pixelWriter_10 )
            {
              v13 = *m_pLowResImage;
              v14 = m_pLowResImage[2];
              blue = v14;
              pLowResImage = m_pLowResImage + 3;
              if ( i != 0 )
              {
                v15 = (unsigned __int8)(m_pLowResImage[1] & pixelWriter_24);
                if ( i >= 5u )
                {
                  v20 = ((unsigned __int64)(v13 & (unsigned int)pixelWriter_20) << pixelWriter_12)
                      | ((unsigned __int64)v15 << SBYTE2(pixelWriter_12));
                  v21 = blue & (unsigned int)pixelWriter_28;
                  if ( v9 <= 0 )
                    v22 = v21 >> -(char)v9;
                  else
                    v22 = v21 << v9;
                  v23 = v22 | ((unsigned __int64)pixelWriter_32 << SBYTE2(pixelWriter_16)) | v20;
                  if ( pixelWriter_10 == 8 )
                    *(_QWORD *)pixelWriter_4a = v23;
                }
                else
                {
                  v16 = ((v13 & pixelWriter_20) << pixelWriter_12) | (v15 << SBYTE2(pixelWriter_12));
                  v17 = v14 & pixelWriter_28;
                  if ( v9 <= 0 )
                    v18 = v17 >> -(char)pixelWriter_16;
                  else
                    v18 = v17 << pixelWriter_16;
                  v19 = v18 | (pixelWriter_32 << SBYTE2(pixelWriter_16)) | v16;
                  switch ( pixelWriter_10 )
                  {
                    case 1u:
                      *pixelWriter_4a = v19;
                      break;
                    case 2u:
                      *(_WORD *)pixelWriter_4a = v19;
                      break;
                    case 3u:
                      *(_WORD *)pixelWriter_4a = v19;
                      pixelWriter_4a[2] = BYTE2(v19);
                      break;
                    case 4u:
                      *(_DWORD *)pixelWriter_4a = v19;
                      break;
                    default:
                      break;
                  }
                }
              }
              pixelWriter_4a += pixelWriter_10;
              ++x;
              m_pLowResImage = pLowResImage;
              if ( x >= this->m_LowResImageWidth )
                break;
            }
            v3 = this;
          }
          v11 = &v38[pTexturea];
          ++y;
          v38 = v11;
        }
        while ( y < v3->m_LowResImageHeight );
      }
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004BEE0
// Name: protected: bool CTexture::SetupDebuggingTextures(class IVTFTexture __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTexture::SetupDebuggingTextures(CTexture *this, IVTFTexture *pVTFTexture)
{
  char nShowMipLevels; // al

  if ( (pVTFTexture->Flags(this: pVTFTexture) & 0x20000) == 0 )
  {
    nShowMipLevels = g_config.nShowMipLevels;
    if ( g_config.nShowMipLevels != 0 )
    {
      if ( g_config.nShowMipLevels != 1 )
      {
LABEL_6:
        if ( nShowMipLevels != 2 || (pVTFTexture->Flags(this: pVTFTexture) & 0x8000080) != 0 )
        {
          CTexture::GenerateShowMipLevelsTextures(this, pTexture: pVTFTexture);
          return 1;
        }
        return 0;
      }
      if ( (pVTFTexture->Flags(this: pVTFTexture) & 0x8000080) == 0 )
      {
        nShowMipLevels = g_config.nShowMipLevels;
        goto LABEL_6;
      }
    }
    else if ( g_config.bShowLowResImage
           && pVTFTexture->FrameCount(this: pVTFTexture) == 1
           && pVTFTexture->FaceCount(this: pVTFTexture) == 1
           && (pVTFTexture->Flags(this: pVTFTexture) & 0x80u) == 0
           && this->m_LowResImageWidth != 0
           && this->m_LowResImageHeight != 0 )
    {
      CTexture::CopyLowResImageToTexture(this, pTexture: pVTFTexture);
      return 1;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1004BFA0
// Name: protected: class IVTFTexture __near * CTexture::HandleFileLoadFailedTexture(class IVTFTexture __near *)
// Source: json
//------------------------------------------------------------------------------
IVTFTexture *__thiscall CTexture::HandleFileLoadFailedTexture(CTexture *this, IVTFTexture *pVTFTexture)
{
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  unsigned __int16 v9; // ax
  int (__thiscall *Width)(IVTFTexture *); // edx
  ImageFormat m_nFlags; // [esp-Ch] [ebp-14h]

  m_nFlags = this->m_nFlags;
  ((void (__thiscall *)(IVTFTexture *, int, int))pVTFTexture->Init)(a1: pVTFTexture, a2: 32, a3: 32);
  v4 = pVTFTexture->FrameCount(this: pVTFTexture);
  v5 = ((int (__thiscall *)(IVTFTexture *, int))pVTFTexture->Flags)(a1: pVTFTexture, a2: v4);
  v6 = ((int (__thiscall *)(IVTFTexture *, int))pVTFTexture->Format)(a1: pVTFTexture, a2: v5);
  v7 = ((int (__thiscall *)(IVTFTexture *, int))pVTFTexture->Depth)(a1: pVTFTexture, a2: v6);
  v8 = ((int (__thiscall *)(IVTFTexture *, int))pVTFTexture->Height)(a1: pVTFTexture, a2: v7);
  v9 = ((int (__thiscall *)(IVTFTexture *, int))pVTFTexture->Width)(a1: pVTFTexture, a2: v8);
  CTexture::Init(this, w: v9, h: 1u, d: 0xCu, fmt: m_nFlags, iFlags: 1u, iFrameCount: 0xFFFFu);
  Width = pVTFTexture->Width;
  this->m_vecReflectivity.x = 0.5;
  this->m_vecReflectivity.y = 0.5;
  this->m_vecReflectivity.z = 0.5;
  this->m_nActualWidth = Width(this: pVTFTexture);
  this->m_nActualHeight = pVTFTexture->Height(this: pVTFTexture);
  this->m_nActualMipCount = 1;
  g_pTextureManager->GenerateErrorTexture(this: g_pTextureManager, a2: this, a3: pVTFTexture);
  CTexture::ConvertToActualFormat(this, pVTFTexture);
  this->m_nFlags &= ~0x800u;
  this->m_nInternalFlags |= 1u;
  return pVTFTexture;
}

//------------------------------------------------------------------------------
// Address: 0x1004C070
// Name: public: virtual void CTexture::DeleteIfUnreferenced(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTexture::DeleteIfUnreferenced(CTexture *this)
{
  if ( this->m_nRefCount.m_value <= 0 )
    g_pTextureManager->RemoveTexture(this: g_pTextureManager, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x1004C090
// Name: public: virtual char const __near * CReferenceToHandleTexture::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CReferenceToHandleTexture::GetName(CReferenceToHandleTexture *this)
{
  return CUtlSymbol::String(this: &this->m_Name);
}

//------------------------------------------------------------------------------
// Address: 0x1004C0A0
// Name: public: virtual void CReferenceToHandleTexture::GetReflectivity(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CReferenceToHandleTexture::GetReflectivity(CReferenceToHandleTexture *this, Vector *reflectivity)
{
  *(_QWORD *)&reflectivity->y = 0;
  reflectivity->x = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x1004C0C0
// Name: public: virtual void CReferenceToHandleTexture::IncrementReferenceCount(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CReferenceToHandleTexture::IncrementReferenceCount(CReferenceToHandleTexture *this)
{
  ++this->m_nRefCount;
}

//------------------------------------------------------------------------------
// Address: 0x1004C0D0
// Name: public: virtual void CReferenceToHandleTexture::DecrementReferenceCount(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CReferenceToHandleTexture::DecrementReferenceCount(CReferenceToHandleTexture *this)
{
  --this->m_nRefCount;
}

//------------------------------------------------------------------------------
// Address: 0x1004C0E0
// Name: public: virtual int CReferenceToHandleTexture::GetTextureHandle(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CReferenceToHandleTexture::GetTextureHandle(
        CReferenceToHandleTexture *this,
        int nFrame,
        int nTextureChannel)
{
  return this->m_hTexture;
}

//------------------------------------------------------------------------------
// Address: 0x1004C120
// Name: public: static class ITextureInternal __near * ITextureInternal::CreateReferenceTextureFromHandle(char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CReferenceToHandleTexture *__cdecl ITextureInternal::CreateReferenceTextureFromHandle(
        const char *pTextureName,
        const char *pTextureGroupName,
        int hTexture)
{
  CReferenceToHandleTexture *v3; // eax
  CReferenceToHandleTexture *v4; // esi
  CUtlSymbol v6; // [esp+6h] [ebp-2h] BYREF

  v3 = (CReferenceToHandleTexture *)MemAlloc_Alloc(nSize: 0x10u);
  v4 = nullptr;
  if ( v3 != nullptr )
  {
    v3->__vftable = (CReferenceToHandleTexture_vtbl *)&CReferenceToHandleTexture::`vftable';
    *(_DWORD *)&v3->m_Name.m_Id = -1;
    v3->m_hTexture = 0;
    v3->m_nRefCount = 0;
    v4 = v3;
  }
  CReferenceToHandleTexture::SetName(this: v4, szName: pTextureName);
  CUtlSymbol::CUtlSymbol(this: &v6, pStr: pTextureGroupName);
  v4->m_TextureGroupName = v6;
  v4->m_hTexture = hTexture;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1004C180
// Name: public: static void ITextureInternal::ChangeRenderTarget(class ITextureInternal __near *,int,int,enum RenderTargetSizeMode_t,enum ImageFormat,enum RenderTargetType_t,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ITextureInternal::ChangeRenderTarget(
        ITextureInternal *pTex,
        unsigned __int16 w,
        unsigned __int16 h,
        RenderTargetSizeMode_t sizeMode,
        ImageFormat fmt,
        RenderTargetType_t type,
        unsigned int textureFlags,
        char renderTargetFlags)
{
  CTexture *v8; // eax
  const char *v9; // [esp-20h] [ebp-24h]

  pTex->Release(this: pTex);
  v9 = (const char *)pTex->GetName(this: pTex);
  v8 = (CTexture *)__RTDynamicCast(
                     inptr: pTex,
                     VfDelta: 0,
                     SrcType: &ITextureInternal `RTTI Type Descriptor',
                     TargetType: &CTexture `RTTI Type Descriptor',
                     isReference: 0);
  CTexture::InitRenderTarget(this: v8, pRTName: v9, w, h, sizeMode, fmt, type, textureFlags, renderTargetFlags);
}

//------------------------------------------------------------------------------
// Address: 0x1004C1E0
// Name: protected: int CTexture::GetOptimalReadBuffer(void __near *,int,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTexture::GetOptimalReadBuffer(CTexture *this, void *hFile, int nSize, CUtlBuffer *optimalBuffer)
{
  int v4; // edi
  int v5; // esi
  void *(__thiscall *AllocOptimalReadBuffer)(IFileSystem *, void *, unsigned int, unsigned int); // eax
  void *v7; // ecx

  v4 = nSize;
  if ( nSize <= 0x200000 )
    v4 = 0x200000;
  if ( g_pFullFileSystem->GetOptimalIOConstraints(
         this: g_pFullFileSystem,
         a2: hFile,
         a3: (unsigned int *)&nSize,
         a4: nullptr,
         a5: nullptr) )
  {
    v5 = ~(nSize - 1) & (nSize + v4 - 1);
  }
  else
  {
    v5 = v4;
  }
  if ( v5 > s_nOptimalReadBufferSize )
  {
    CTexture::FreeOptimalReadBuffer(this, nMaxSize: 0);
    AllocOptimalReadBuffer = g_pFullFileSystem->AllocOptimalReadBuffer;
    s_nOptimalReadBufferSize = v5;
    v7 = AllocOptimalReadBuffer(this: g_pFullFileSystem, a2: hFile, a3: v4, a4: 0);
    s_pOptimalReadBuffer = v7;
    if ( mat_spewalloc.m_pParent != nullptr && mat_spewalloc.m_pParent->m_Value.m_nValue != 0 )
      _Msg(a1: "Allocated optimal read buffer of %d bytes @ 0x%8.8X\n", s_nOptimalReadBufferSize, v7);
  }
  CUtlBuffer::SetExternalBuffer(
    this: optimalBuffer,
    pMemory: s_pOptimalReadBuffer,
    nSize: s_nOptimalReadBufferSize,
    nInitialPut: 0,
    nFlags: 8);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1004C2B0
// Name: public: virtual void __near * CTexture::GetResourceData(unsigned int,unsigned int __near *)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall CTexture::GetResourceData(CTexture *this, unsigned int eDataType, unsigned int *pnumBytes)
{
  CTexture::DataChunk *m_pMemory; // eax
  CTexture::DataChunk *v4; // ecx

  m_pMemory = this->m_arrDataChunks.m_Memory.m_pMemory;
  v4 = &m_pMemory[this->m_arrDataChunks.m_Size];
  if ( m_pMemory >= v4 )
    return nullptr;
  while ( (m_pMemory->m_eType & 0xFFFFFF) != eDataType )
  {
    if ( ++m_pMemory >= v4 )
      return nullptr;
  }
  if ( (m_pMemory->m_eType & 0x2000000) != 0 )
  {
    if ( pnumBytes != nullptr )
      *pnumBytes = 4;
    return (unsigned __int8 *)&m_pMemory->m_numBytes;
  }
  else
  {
    if ( pnumBytes != nullptr )
      *pnumBytes = m_pMemory->m_numBytes;
    return m_pMemory->m_pvData;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004C320
// Name: protected: void CUtlBuffer::PutTypeBin<char>(char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTypeBin<char>(CUtlBuffer *this, char src)
{
  if ( CUtlBuffer::CheckPut(this, nSize: 1) )
  {
    this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = src;
    CUtlBuffer::AddNullTermination(this, nPut: ++this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004C3D0
// Name: protected: void CUtlBuffer::PutTabs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTabs(CUtlBuffer *this)
{
  int m_nTab; // eax
  int i; // ebx

  if ( (this->m_Flags & 0x10) != 0 )
    m_nTab = 0;
  else
    m_nTab = this->m_nTab;
  for ( i = m_nTab - 1; i >= 0; --i )
  {
    if ( CUtlBuffer::CheckPut(this, nSize: 1) )
    {
      this->m_Memory.m_pMemory[this->m_Put++ - this->m_nOffset] = 9;
      CUtlBuffer::AddNullTermination(this, nPut: this->m_Put);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004C420
// Name: public: void CUtlBuffer::PutChar(char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutChar(CUtlBuffer *this, char c)
{
  int m_Put; // eax

  if ( (this->m_Flags & 1) != 0 )
  {
    m_Put = this->m_Put;
    if ( m_Put != 0 && this->m_Memory.m_pMemory[m_Put - this->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this);
  }
  if ( CUtlBuffer::CheckPut(this, nSize: 1) )
  {
    this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = c;
    CUtlBuffer::AddNullTermination(this, nPut: ++this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004C480
// Name: public: CP4AutoEditFile::CP4AutoEditFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CP4AutoEditFile *__thiscall CP4AutoEditFile::CP4AutoEditFile(CP4AutoEditFile *this, const char *szFilename)
{
  CP4File *v3; // eax

  v3 = CP4Factory::AccessFile(this: g_p4factory, szFilename);
  this->m_spImpl.m_p = v3;
  v3->Edit(this: v3);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1004C4E0
// Name: public: CP4AutoAddFile::CP4AutoAddFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CP4AutoAddFile *__thiscall CP4AutoAddFile::CP4AutoAddFile(CP4AutoAddFile *this, const char *szFilename)
{
  CP4File *v3; // eax

  v3 = CP4Factory::AccessFile(this: g_p4factory, szFilename);
  this->m_spImpl.m_p = v3;
  v3->Add(this: v3);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1004C540
// Name: protected: void CTexture::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTexture::Shutdown(CTexture *this)
{
  CTexture::DataChunk *m_pMemory; // edi
  CTexture::DataChunk *v3; // ebx
  ITextureRegenerator *m_pTextureRegenerator; // ecx

  free(pMem: this->m_pLowResImage);
  m_pMemory = this->m_arrDataChunks.m_Memory.m_pMemory;
  v3 = &m_pMemory[this->m_arrDataChunks.m_Size];
  for ( this->m_pLowResImage = nullptr; m_pMemory < v3; ++m_pMemory )
    free(pMem: m_pMemory->m_pvData);
  this->m_arrDataChunks.m_Size = 0;
  m_pTextureRegenerator = this->m_pTextureRegenerator;
  if ( m_pTextureRegenerator != nullptr )
  {
    m_pTextureRegenerator->Release(this: m_pTextureRegenerator);
    this->m_pTextureRegenerator = nullptr;
  }
  this->FreeShaderAPITextures(this);
  if ( this->m_pTextureHandles != nullptr )
  {
    free(pMem: this->m_pTextureHandles);
    this->m_pTextureHandles = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004C5D0
// Name: public: virtual void CTexture::OnRestore(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTexture::OnRestore(CTexture *this)
{
  unsigned __int16 v2; // bx
  bool v3; // al
  unsigned int m_nFlags; // ecx
  unsigned int v5; // edi
  int width; // [esp+4h] [ebp-10h] BYREF
  int height; // [esp+8h] [ebp-Ch] BYREF
  int newWidth; // [esp+Ch] [ebp-8h] BYREF
  int newHeight; // [esp+10h] [ebp-4h] BYREF

  if ( (this->m_nFlags & 0x8000) != 0 )
  {
    v2 = 1;
    if ( this->m_nOriginalRenderTargetType != RENDER_TARGET
      || (v3 = g_pShaderAPI->DoRenderTargetsNeedSeparateDepthBuffer(this: g_pShaderAPI),
          m_nFlags = this->m_nFlags,
          v3 == (BYTE2(m_nFlags) & 1)) )
    {
      CTexture::ApplyRenderTargetSizeMode(this, width: &newWidth, height: &newHeight, fmt: this->m_ImageFormat);
      if ( newWidth != this->m_nMappingWidth || newHeight != this->m_nMappingHeight )
      {
        CTexture::Shutdown(this);
        CTexture::Init(
          this,
          w: newWidth,
          h: newHeight,
          d: 1u,
          fmt: this->m_ImageFormat,
          iFlags: this->m_nFlags,
          iFrameCount: this->m_nFrameCount);
      }
    }
    else
    {
      if ( v3 )
      {
        v2 = 2;
        v5 = m_nFlags | 0x10000;
      }
      else
      {
        v5 = m_nFlags & 0xFFFEFFFF;
      }
      CTexture::Shutdown(this);
      CTexture::ApplyRenderTargetSizeMode(this, &width, &height, fmt: this->m_ImageFormat);
      CTexture::Init(this, w: width, h: height, d: 1u, fmt: this->m_ImageFormat, iFlags: v5, iFrameCount: v2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004C6B0
// Name: protected: int CTexture::ComputeActualSize(bool,class IVTFTexture __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTexture::ComputeActualSize(CTexture *this, bool bIgnorePicmip, IVTFTexture *pVTFTexture)
{
  int m_nMappingWidth; // eax
  int m_nMappingDepth; // edx
  int m_nMappingHeight; // ebx
  TextureLODControlSettings_t *v7; // edi
  TextureLODControlSettings_t *v8; // eax
  int m_nActualWidth; // eax
  char v10; // cl
  int m_nActualHeight; // eax
  char v12; // cl
  const char *v13; // eax
  int m_Id; // eax
  char x; // al
  TextureLodOverride::OverrideInfo v16; // dx
  char v17; // cl
  char v18; // al
  int v19; // edi
  const char *v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // ecx
  int v24; // eax
  int m_nDesiredDimensionLimit; // edi
  int i; // edx
  bool v27; // sf
  int skipMipLevels; // eax
  int v29; // eax
  int v30; // edi
  int v31; // ebx
  int v32; // eax
  int v33; // ecx
  int v34; // ecx
  int v35; // edx
  int v36; // ecx
  int m_nActualDepth; // edi
  int j; // ebx
  int v39; // eax
  bool v40; // cf
  int nClampZ; // [esp+Ch] [ebp-18h]
  TextureLODControlSettings_t lcs; // [esp+10h] [ebp-14h]
  __int16 default_lod_settings; // [esp+14h] [ebp-10h]
  int nClampY; // [esp+18h] [ebp-Ch]
  int nClampX; // [esp+1Ch] [ebp-8h]
  TextureLodOverride::OverrideInfo oi; // [esp+20h] [ebp-4h] BYREF

  m_nMappingWidth = this->m_nMappingWidth;
  m_nMappingDepth = this->m_nMappingDepth;
  m_nMappingHeight = this->m_nMappingHeight;
  this->m_nActualHeight = m_nMappingHeight;
  v7 = nullptr;
  this->m_nActualWidth = m_nMappingWidth;
  this->m_nActualDepth = m_nMappingDepth;
  nClampX = m_nMappingWidth;
  nClampY = m_nMappingHeight;
  nClampZ = m_nMappingDepth;
  *(_WORD *)&lcs.m_ResolutionClampX = 0;
  if ( pVTFTexture != nullptr )
  {
    v8 = (TextureLODControlSettings_t *)pVTFTexture->GetResourceData(this: pVTFTexture, a2: 4476748, a3: 0);
    v7 = v8;
    if ( v8 != nullptr )
      lcs = *v8;
  }
  m_nActualWidth = this->m_nActualWidth;
  default_lod_settings = 0;
  if ( (unsigned int)m_nActualWidth > 1 )
  {
    v10 = 0;
    do
    {
      m_nActualWidth >>= 1;
      ++v10;
    }
    while ( m_nActualWidth > 1 );
    LOBYTE(default_lod_settings) = v10;
  }
  m_nActualHeight = this->m_nActualHeight;
  if ( (unsigned int)m_nActualHeight > 1 )
  {
    v12 = 0;
    do
    {
      m_nActualHeight >>= 1;
      ++v12;
    }
    while ( m_nActualHeight > 1 );
    HIBYTE(default_lod_settings) = v12;
  }
  v13 = (const char *)this->GetName(this);
  m_Id = CUtlSymbolTable::Find(
           this: &TextureLodOverride::s_OverrideMap.m_SymbolTable,
           result: (CUtlSymbol *)&oi,
           pString: v13)->m_Id;
  if ( (_WORD)m_Id == 0xFFFF )
  {
    x = 0;
    v16.x = 0;
  }
  else
  {
    v16 = TextureLodOverride::s_OverrideMap.m_Vector.m_Memory.m_pMemory[m_Id];
    x = v16.x;
    oi = v16;
    v16.x = v16.y;
    if ( x != 0 && v16.y != 0 && v7 == nullptr )
      *(_WORD *)&lcs.m_ResolutionClampX = default_lod_settings;
  }
  v17 = x + lcs.m_ResolutionClampX;
  v18 = v16.x + lcs.m_ResolutionClampY;
  if ( v17 < 0 )
    v17 = 0;
  if ( v18 < 0 )
    v18 = 0;
  if ( v17 != 0 && v18 != 0 )
  {
    v19 = 1 << v17;
    m_nMappingHeight = 1 << v18;
    nClampX = 1 << v17;
    nClampY = 1 << v18;
  }
  else
  {
    v19 = nClampX;
  }
  v20 = (const char *)this->GetName(this);
  v21 = CUtlSymbolTable::Find(
          this: &TextureLodExclude::s_ExcludeMap.m_SymbolTable,
          result: (CUtlSymbol *)&oi,
          pString: v20)->m_Id;
  if ( (_WORD)v21 != 0xFFFF )
  {
    v22 = TextureLodExclude::s_ExcludeMap.m_Vector.m_Memory.m_pMemory[v21];
    if ( v22 <= 0 )
    {
      if ( v22 == 0 )
      {
        if ( v19 > 4 )
        {
          v19 = 4;
          nClampX = 4;
        }
        if ( m_nMappingHeight > 4 )
        {
          m_nMappingHeight = 4;
          goto LABEL_37;
        }
      }
    }
    else
    {
      if ( v22 < v19 )
      {
        v19 = v22;
        nClampX = v22;
      }
      if ( v22 < m_nMappingHeight )
      {
        m_nMappingHeight = v22;
LABEL_37:
        nClampY = m_nMappingHeight;
      }
    }
  }
  v23 = this->m_nActualWidth;
  if ( v19 >= v23 )
    nClampX = this->m_nActualWidth;
  v24 = this->m_nActualHeight;
  if ( m_nMappingHeight >= v24 )
  {
    m_nMappingHeight = this->m_nActualHeight;
    nClampY = m_nMappingHeight;
  }
  m_nDesiredDimensionLimit = this->m_nDesiredDimensionLimit;
  if ( m_nDesiredDimensionLimit == 1024 )
  {
    if ( ImageLoader::GetMemRequired(
           width: v23,
           height: v24,
           depth: 1,
           imageFormat: this->m_ImageFormat,
           mipmap: false,
           pAdjustedHeight: nullptr) <= 0x20000
      && this->m_nActualWidth == 2048
      && this->m_nActualHeight <= 0x40u
      && pVTFTexture != nullptr
      && pVTFTexture->MipCount(this: pVTFTexture) > 1 )
    {
      m_nDesiredDimensionLimit = 2048;
    }
  }
  else if ( this->m_nDesiredDimensionLimit == 0 )
  {
    i = nClampX;
    goto LABEL_56;
  }
  for ( i = nClampX; i > m_nDesiredDimensionLimit || m_nMappingHeight > m_nDesiredDimensionLimit; i >>= 1 )
    m_nMappingHeight >>= 1;
  nClampY = m_nMappingHeight;
  nClampX = i;
LABEL_56:
  if ( bIgnorePicmip )
    goto LABEL_72;
  if ( (this->m_nFlags & 0x200) != 0 )
    goto LABEL_65;
  v27 = g_config.skipMipLevels < 0;
  if ( g_config.skipMipLevels > 0 )
  {
    skipMipLevels = g_config.skipMipLevels;
    do
    {
      if ( i > 4 && m_nMappingHeight > 4 )
      {
        i >>= 1;
        m_nMappingHeight >>= 1;
      }
      --skipMipLevels;
    }
    while ( skipMipLevels != 0 );
    nClampY = m_nMappingHeight;
    nClampX = i;
LABEL_65:
    v27 = g_config.skipMipLevels < 0;
  }
  if ( v27 )
  {
    v29 = 0;
    if ( g_config.skipMipLevels < 0 )
    {
      do
      {
        if ( i >= this->m_nActualWidth )
          break;
        if ( m_nMappingHeight >= this->m_nActualHeight )
          break;
        ++v29;
        i *= 2;
        m_nMappingHeight *= 2;
      }
      while ( v29 < -g_config.skipMipLevels );
      nClampY = m_nMappingHeight;
      nClampX = i;
    }
  }
LABEL_72:
  v30 = g_pHWConfig->MaxTextureWidth(this: g_pHWConfig);
  v31 = g_pHWConfig->MaxTextureHeight(this: g_pHWConfig);
  v32 = g_pHWConfig->MaxTextureDepth(this: g_pHWConfig);
  v33 = v30;
  if ( v30 <= 4 )
    v33 = 4;
  if ( nClampX >= v33 )
  {
    nClampX = v30;
    if ( v30 <= 4 )
      nClampX = 4;
  }
  v34 = v31;
  if ( v31 <= 4 )
    v34 = 4;
  v35 = nClampY;
  if ( nClampY >= v34 )
  {
    v35 = v31;
    if ( v31 <= 4 )
      v35 = 4;
    nClampY = v35;
  }
  v36 = v32;
  if ( v32 <= 1 )
    v36 = 1;
  m_nActualDepth = nClampZ;
  if ( nClampZ >= v36 )
  {
    m_nActualDepth = v32;
    if ( v32 <= 1 )
      m_nActualDepth = 1;
  }
  if ( nClampX >= this->m_nActualWidth )
    nClampX = this->m_nActualWidth;
  if ( v35 >= this->m_nActualHeight )
    nClampY = this->m_nActualHeight;
  if ( m_nActualDepth >= this->m_nActualDepth )
    m_nActualDepth = this->m_nActualDepth;
  for ( j = 0; ; ++j )
  {
    v39 = this->m_nActualWidth;
    if ( v39 <= nClampX && this->m_nActualHeight <= nClampY && this->m_nActualDepth <= m_nActualDepth )
      break;
    this->m_nActualHeight >>= 1;
    this->m_nActualDepth >>= 1;
    v40 = this->m_nActualDepth == 0;
    this->m_nActualWidth = (unsigned __int16)v39 >> 1;
    if ( v40 )
      this->m_nActualDepth = 1;
  }
  this->m_nActualMipCount = CTexture::ComputeActualMipCount(this);
  return j;
}

//------------------------------------------------------------------------------
// Address: 0x1004CA20
// Name: protected: class IVTFTexture __near * CTexture::ReconstructPartialProceduralBits(struct Rect_t const __near *,struct Rect_t __near *)
// Source: json
//------------------------------------------------------------------------------
IVTFTexture *__thiscall CTexture::ReconstructPartialProceduralBits(CTexture *this, Rect_t *pRect, Rect_t *pActualRect)
{
  int v4; // edi
  int v5; // ebx
  int i; // eax
  CVTFTexture *VTFTexture; // eax
  IVTFTexture *v8; // edi
  IVTFTexture v9; // ebx
  ImageFormat v10; // eax
  unsigned int m_nFlags; // [esp-Ch] [ebp-18h]
  int m_nFrameCount; // [esp-8h] [ebp-14h]

  CTexture::ComputeActualSize(this, bIgnorePicmip: false, pVTFTexture: nullptr);
  v4 = 1;
  v5 = this->GetActualWidth(this);
  if ( v5 != 0 )
    v4 = this->GetMappingWidth(this) / v5;
  for ( i = 0; v4 > 1; ++i )
    v4 >>= 1;
  CVTFTexture::ComputeMipLevelSubRect((CVTFTexture *)this, pSrcRect: pRect, nMipLevel: i, pSubRect: pActualRect);
  if ( this->m_pTextureRegenerator != nullptr
    && this->m_pTextureRegenerator->HasPreallocatedScratchTexture(this: this->m_pTextureRegenerator) )
  {
    VTFTexture = (CVTFTexture *)this->m_pTextureRegenerator->GetPreallocatedScratchTexture(this: this->m_pTextureRegenerator);
  }
  else
  {
    VTFTexture = (CVTFTexture *)s_pVTFTexture;
    if ( s_pVTFTexture == nullptr )
    {
      VTFTexture = CreateVTFTexture();
      s_pVTFTexture = VTFTexture;
    }
  }
  v8 = VTFTexture;
  v9.__vftable = (IVTFTexture_vtbl *)VTFTexture->__vftable;
  m_nFrameCount = this->m_nFrameCount;
  m_nFlags = this->m_nFlags;
  v10 = CTexture::ComputeActualFormat(this, srcFormat: this->m_ImageFormat);
  v9.Init(
    this: v8,
    a2: this->m_nActualWidth,
    a3: this->m_nActualHeight,
    a4: this->m_nActualDepth,
    a5: v10,
    a6: m_nFlags,
    a7: m_nFrameCount,
    a8: -1);
  if ( this->m_pTextureRegenerator != nullptr )
    this->m_pTextureRegenerator->RegenerateTextureBits(
      this: this->m_pTextureRegenerator,
      a2: this,
      a3: v8,
      a4: pActualRect);
  else
    g_pTextureManager->GenerateErrorTexture(this: g_pTextureManager, a2: this, a3: v8);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x1004CB20
// Name: protected: void CTexture::ReconstructPartialTexture(struct Rect_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTexture::ReconstructPartialTexture(CTexture *this, Rect_t *pRect)
{
  CTexture *v2; // ebx
  IVTFTexture *v3; // esi
  bool (__thiscall *IsCubeMap)(struct CTexture *); // edx
  int v5; // edi
  int m_nActualMipCount; // eax
  int v7; // edi
  int v8; // eax
  unsigned __int8 *(__thiscall *ImageData)(IVTFTexture *, int, int, int, int, int, int); // edx
  int v10; // eax
  IShaderAPI_vtbl *v11; // ebx
  int v12; // eax
  int m_nFrameCount; // ecx
  Rect_t vtfRect; // [esp+8h] [ebp-30h] BYREF
  Rect_t mipRect; // [esp+18h] [ebp-20h] BYREF
  int nStride; // [esp+28h] [ebp-10h]
  CTexture *v17; // [esp+2Ch] [ebp-Ch]
  int iFrame; // [esp+30h] [ebp-8h]
  int nFaceCount; // [esp+34h] [ebp-4h]
  int iFace; // [esp+40h] [ebp+8h]

  v2 = this;
  v17 = this;
  v3 = CTexture::ReconstructPartialProceduralBits(this, pRect, pActualRect: &vtfRect);
  if ( (v2->m_nInternalFlags & 2) != 0 || v2->AllocateShaderAPITextures(this: v2) )
  {
    IsCubeMap = v2->IsCubeMap;
    nFaceCount = 1;
    if ( IsCubeMap(this: v2) )
      nFaceCount = 6;
    v5 = 0;
    iFrame = 0;
    if ( v2->m_nFrameCount != 0 )
    {
      do
      {
        g_pShaderAPI->ModifyTexture(this: g_pShaderAPI, a2: v2->m_pTextureHandles[v5]);
        iFace = 0;
        if ( nFaceCount > 0 )
        {
          m_nActualMipCount = v2->m_nActualMipCount;
          do
          {
            v7 = 0;
            if ( m_nActualMipCount > 0 )
            {
              do
              {
                v3->ComputeMipLevelSubRect(this: v3, a2: &vtfRect, a3: v7, a4: &mipRect);
                v8 = v3->RowSizeInBytes(this: v3, a2: v7);
                ImageData = v3->ImageData;
                nStride = v8;
                v10 = (int)ImageData(this: v3, a2: iFrame, a3: iFace, a4: v7, a5: mipRect.x, a6: mipRect.y, a7: 0);
                v11 = g_pShaderAPI->__vftable;
                v12 = ((int (__thiscall *)(IVTFTexture *, int, _DWORD, int))v3->Format)(
                        a1: v3,
                        a2: nStride,
                        a3: 0,
                        a4: v10);
                ((void (__thiscall *)(IShaderAPI *, int, int, int, int, _DWORD, int, int, int))v11->TexSubImage2D)(
                  a1: g_pShaderAPI,
                  a2: v7,
                  a3: iFace,
                  a4: mipRect.x,
                  a5: mipRect.y,
                  a6: 0,
                  a7: mipRect.width,
                  a8: mipRect.height,
                  a9: v12);
                m_nActualMipCount = v17->m_nActualMipCount;
                ++v7;
              }
              while ( v7 < m_nActualMipCount );
              v2 = v17;
            }
            ++iFace;
          }
          while ( iFace < nFaceCount );
          v5 = iFrame;
        }
        m_nFrameCount = v2->m_nFrameCount;
        iFrame = ++v5;
      }
      while ( v5 < m_nFrameCount );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004CC90
// Name: protected: class IVTFTexture __near * CTexture::ReconstructProceduralBits(void)
// Source: json
//------------------------------------------------------------------------------
IVTFTexture *__thiscall CTexture::ReconstructProceduralBits(CTexture *this)
{
  CVTFTexture *VTFTexture; // eax
  IVTFTexture *v3; // edi
  IVTFTexture v4; // ebx
  ImageFormat v5; // eax
  int m_nActualWidth; // ecx
  ITextureRegenerator *m_pTextureRegenerator; // ecx
  ImageFormat m_ImageFormat; // eax
  unsigned int m_nFlags; // [esp-10h] [ebp-28h]
  int m_nFrameCount; // [esp-Ch] [ebp-24h]
  Rect_t rect; // [esp+8h] [ebp-10h] BYREF

  CTexture::ComputeActualSize(this, bIgnorePicmip: false, pVTFTexture: nullptr);
  if ( this->m_pTextureRegenerator != nullptr
    && this->m_pTextureRegenerator->HasPreallocatedScratchTexture(this: this->m_pTextureRegenerator) )
  {
    VTFTexture = (CVTFTexture *)this->m_pTextureRegenerator->GetPreallocatedScratchTexture(this: this->m_pTextureRegenerator);
  }
  else
  {
    VTFTexture = (CVTFTexture *)s_pVTFTexture;
    if ( s_pVTFTexture == nullptr )
    {
      VTFTexture = CreateVTFTexture();
      s_pVTFTexture = VTFTexture;
    }
  }
  v3 = VTFTexture;
  v4.__vftable = (IVTFTexture_vtbl *)VTFTexture->__vftable;
  m_nFrameCount = this->m_nFrameCount;
  m_nFlags = this->m_nFlags;
  v5 = CTexture::ComputeActualFormat(this, srcFormat: this->m_ImageFormat);
  v4.Init(
    this: v3,
    a2: this->m_nActualWidth,
    a3: this->m_nActualHeight,
    a4: this->m_nActualDepth,
    a5: v5,
    a6: m_nFlags,
    a7: m_nFrameCount,
    a8: -1);
  if ( this->m_pTextureRegenerator != nullptr )
  {
    m_nActualWidth = this->m_nActualWidth;
    rect.height = this->m_nActualHeight;
    rect.width = m_nActualWidth;
    m_pTextureRegenerator = this->m_pTextureRegenerator;
    rect.x = 0;
    rect.y = 0;
    m_pTextureRegenerator->RegenerateTextureBits(this: m_pTextureRegenerator, a2: this, a3: v3, a4: &rect);
    return v3;
  }
  else
  {
    m_ImageFormat = this->m_ImageFormat;
    if ( m_ImageFormat != IMAGE_FORMAT_RGBA16161616F
      && m_ImageFormat != IMAGE_FORMAT_RG1616F
      && m_ImageFormat != IMAGE_FORMAT_R32F
      && m_ImageFormat != IMAGE_FORMAT_RG3232F
      && m_ImageFormat != IMAGE_FORMAT_RGB323232F
      && m_ImageFormat != IMAGE_FORMAT_RGBA32323232F )
    {
      g_pTextureManager->GenerateErrorTexture(this: g_pTextureManager, a2: this, a3: v3);
    }
    return v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004CD80
// Name: public: CPlainAutoPtr<class CP4File>::~CPlainAutoPtr<class CP4File>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlainAutoPtr<CP4File>::~CPlainAutoPtr<CP4File>(CP4AutoAddFile *this)
{
  CP4File *m_p; // ecx

  m_p = this->m_spImpl.m_p;
  this->m_spImpl.m_p = nullptr;
  if ( m_p != nullptr )
    ((void (__thiscall *)(CP4File *, int))m_p->dtr_CP4File)(a1: m_p, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1004CDA0
// Name: bool CTextureImpl_GetTextureInformation(char const __near *,struct MaterialTextureInfo_t __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CTextureImpl_GetTextureInformation(const char *szTextureName, MaterialTextureInfo_t *info)
{
  int m_Id; // eax
  CUtlSymbol v4; // [esp+2h] [ebp-2h] BYREF

  m_Id = CUtlSymbolTable::Find(
           this: &TextureLodExclude::s_ExcludeMap.m_SymbolTable,
           result: &v4,
           pString: szTextureName)->m_Id;
  if ( (_WORD)m_Id == 0xFFFF )
    info->iExcludeInformation = -1;
  else
    info->iExcludeInformation = TextureLodExclude::s_ExcludeMap.m_Vector.m_Memory.m_pMemory[m_Id];
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1004CE80
// Name: public: CTexture::CTexture(void)
// Source: json
//------------------------------------------------------------------------------
CTexture *__thiscall CTexture::CTexture(CTexture *this)
{
  this->__vftable = (CTexture_vtbl *)&CTexture::`vftable';
  *(_DWORD *)&this->m_Name.m_Id = -1;
  this->m_nRefCount.m_value = 0;
  this->m_ImageFormat = IMAGE_FORMAT_UNKNOWN;
  this->m_arrDataChunks.m_Memory.m_pMemory = nullptr;
  this->m_arrDataChunks.m_Memory.m_nAllocationCount = 0;
  this->m_arrDataChunks.m_Memory.m_nGrowSize = 0;
  this->m_arrDataChunks.m_Size = 0;
  this->m_arrDataChunks.m_pElements = nullptr;
  this->m_nActualMipCount = 0;
  this->m_nMappingWidth = 0;
  this->m_nMappingHeight = 0;
  this->m_nMappingDepth = 1;
  this->m_nActualWidth = 0;
  this->m_nActualHeight = 0;
  this->m_nActualDepth = 1;
  _InterlockedExchange(&this->m_nRefCount.m_value, 0);
  this->m_nFlags = 0;
  this->m_nInternalFlags = 0;
  this->m_pTextureHandles = nullptr;
  this->m_nFrameCount = 0;
  *(_QWORD *)&this->m_vecReflectivity.y = 0;
  this->m_vecReflectivity.x = 0.0;
  this->m_pTextureRegenerator = nullptr;
  this->m_nOriginalRenderTargetType = NO_RENDER_TARGET;
  this->m_RenderTargetSizeMode = RT_SIZE_NO_CHANGE;
  *(_WORD *)&this->m_LowResImageWidth = 0;
  this->m_pLowResImage = nullptr;
  *(_DWORD *)&this->m_nDesiredDimensionLimit = 0;
  this->m_nMipSkipCount = 0;
  this->m_nOriginalRTHeight = 1;
  this->m_nOriginalRTWidth = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1004CF50
// Name: public: virtual CTexture::~CTexture(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTexture::~CTexture(CTexture *this)
{
  CUtlVector<CTexture::DataChunk,CUtlMemory<CTexture::DataChunk,int> > *p_m_arrDataChunks; // esi
  CTexture::DataChunk *m_pMemory; // eax

  this->__vftable = (CTexture_vtbl *)&CTexture::`vftable';
  CTexture::Shutdown(this);
  p_m_arrDataChunks = &this->m_arrDataChunks;
  this->__vftable = (CTexture_vtbl *)-559038737;
  this->m_arrDataChunks.m_Size = 0;
  if ( this->m_arrDataChunks.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_arrDataChunks->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_arrDataChunks->m_Memory.m_pMemory);
      p_m_arrDataChunks->m_Memory.m_pMemory = nullptr;
    }
    this->m_arrDataChunks.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = p_m_arrDataChunks->m_Memory.m_pMemory;
  this->m_arrDataChunks.m_pElements = this->m_arrDataChunks.m_Memory.m_pMemory;
  if ( this->m_arrDataChunks.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      p_m_arrDataChunks->m_Memory.m_pMemory = nullptr;
    }
    this->m_arrDataChunks.m_Memory.m_nAllocationCount = 0;
  }
  this->__vftable = (CTexture_vtbl *)&ITextureInternal::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1004D000
// Name: public: virtual void CTexture::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTexture::Precache(CTexture *this)
{
  bool (__thiscall *IsRenderTarget)(struct CTexture *); // edx
  const char *v3; // eax
  CVTFTexture *ScratchVTFTexture; // edi
  const char *v5; // eax
  int v6; // ebx
  void *v7; // esp
  bool (__thiscall *ReadFile)(IBaseFileSystem *, const char *, const char *, CUtlBuffer *, int, int, void *(__cdecl *)(const char *, unsigned int)); // edx
  int v9; // ebx
  float *v10; // eax
  int (__thiscall *Width)(struct CVTFTexture *); // edx
  int v12; // [esp+0h] [ebp-16Ch] BYREF
  char pCacheFileName[256]; // [esp+Ch] [ebp-160h] BYREF
  CUtlBuffer buf; // [esp+10Ch] [ebp-60h] BYREF
  int nHackExtraFlags; // [esp+15Ch] [ebp-10h]
  int v16; // [esp+168h] [ebp-4h]

  IsRenderTarget = this->IsRenderTarget;
  nHackExtraFlags = 0;
  if ( !IsRenderTarget(this) && !this->IsProcedural(this) && (this->m_nInternalFlags & 2) == 0 )
  {
    v3 = CUtlSymbol::String(this: &this->m_Name);
    if ( V_strnicmp(s1: v3, s2: "env_cubemap", n: 12) != 0 )
    {
      ScratchVTFTexture = CTexture::GetScratchVTFTexture(this);
      v5 = CUtlSymbol::String(this: &this->m_Name);
      V_snprintf(pDest: pCacheFileName, maxLen: 256, pFormat: "materials/%s.vtf", v5);
      v6 = VTFFileHeaderSize(nMajorVersion: 7, nMinorVersion: -1);
      v7 = alloca(v6);
      CUtlBuffer::CUtlBuffer(this: &buf, pBuffer: &v12, nSize: v6, nFlags: 0);
      ReadFile = g_pFullFileSystem->ReadFile;
      v16 = 0;
      if ( ReadFile(
             this: &g_pFullFileSystem->IBaseFileSystem,
             a2: pCacheFileName,
             a3: nullptr,
             a4: &buf,
             a5: v6,
             a6: 0,
             a7: nullptr) )
      {
        if ( ScratchVTFTexture->Unserialize(this: ScratchVTFTexture, a2: &buf, a3: true, a4: 0) )
        {
          v9 = 512;
          if ( V_strnicmp(s1: pCacheFileName, s2: "materials/graffiti/", n: 19) != 0 )
            v9 = nHackExtraFlags;
          v10 = (float *)ScratchVTFTexture->Reflectivity(this: ScratchVTFTexture);
          this->m_vecReflectivity.x = *v10;
          this->m_vecReflectivity.y = v10[1];
          Width = ScratchVTFTexture->Width;
          this->m_vecReflectivity.z = v10[2];
          this->m_nMappingWidth = Width(this: ScratchVTFTexture);
          this->m_nMappingHeight = ScratchVTFTexture->Height(this: ScratchVTFTexture);
          this->m_nMappingDepth = ScratchVTFTexture->Depth(this: ScratchVTFTexture);
          this->m_nFlags = v9 | ScratchVTFTexture->Flags(this: ScratchVTFTexture);
          this->m_nFrameCount = ScratchVTFTexture->FrameCount(this: ScratchVTFTexture);
          goto LABEL_12;
        }
        _Warning(a1: "Error reading material \"%s\"\n", pCacheFileName);
      }
      this->m_vecReflectivity.x = 0.0;
      this->m_vecReflectivity.y = 0.0;
      this->m_vecReflectivity.z = 0.0;
      this->m_nInternalFlags |= 1u;
      *(_DWORD *)&this->m_nMappingWidth = 2097184;
      this->m_nMappingDepth = 1;
      this->m_nFlags = 256;
      this->m_nFrameCount = 1;
LABEL_12:
      v16 = -1;
      CUtlMemory<CUtlVector<CMorph::MorphQuad_t,CUtlMemory<CMorph::MorphQuad_t,int>>,int>::~CUtlMemory<CUtlVector<CMorph::MorphQuad_t,CUtlMemory<CMorph::MorphQuad_t,int>>,int>(this: &buf);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004D200
// Name: protected: class IVTFTexture __near * CTexture::LoadTextureBitsFromFile(char __near *,char __near * __near *)
// Source: json
//------------------------------------------------------------------------------
IVTFTexture *__thiscall CTexture::LoadTextureBitsFromFile(
        CTexture *this,
        signed int pCacheFileName,
        signed int ppResolvedFilename)
{
  CVTFTexture *VTFTexture; // eax
  IVTFTexture *FailedTexture; // esi
  IFileSystem_vtbl *v6; // edi
  int v7; // eax
  void *v8; // edi
  const char *v9; // edi
  char *v10; // eax
  const char *v11; // eax
  int OptimalReadBuffer; // eax
  IBaseFileSystem_vtbl *v13; // edx
  unsigned int m_nFlags; // eax
  int v15; // eax
  unsigned __int16 v16; // ax
  float *v17; // eax
  int v18; // eax
  IVTFTexture v19; // edx
  char **v20; // eax
  IBaseFileSystem_vtbl *v21; // edx
  int v22; // eax
  signed int v23; // eax
  void *v24; // esp
  unsigned int (__thiscall *GetResourceTypes)(IVTFTexture *, unsigned int *, int); // edx
  char **v26; // edi
  char *v27; // eax
  void *(__thiscall *GetResourceData)(IVTFTexture *, unsigned int, unsigned int *); // edx
  unsigned __int8 *v29; // edi
  unsigned int v30; // eax
  unsigned __int16 v32; // [esp-14h] [ebp-90h]
  unsigned __int16 v33; // [esp-10h] [ebp-8Ch]
  ImageFormat v34; // [esp-Ch] [ebp-88h]
  unsigned int v35; // [esp-8h] [ebp-84h]
  unsigned __int16 v36; // [esp-4h] [ebp-80h]
  _DWORD v37[3]; // [esp+0h] [ebp-7Ch] BYREF
  CUtlBuffer buf; // [esp+Ch] [ebp-70h] BYREF
  CTexture::DataChunk dc; // [esp+5Ch] [ebp-20h] BYREF
  unsigned int *arrRsrcTypesEnd; // [esp+68h] [ebp-14h]
  int nMipSkipCount; // [esp+6Ch] [ebp-10h]
  int v42; // [esp+78h] [ebp-4h]

  VTFTexture = (CVTFTexture *)s_pVTFTexture;
  if ( s_pVTFTexture == nullptr )
  {
    VTFTexture = CreateVTFTexture();
    s_pVTFTexture = VTFTexture;
  }
  FailedTexture = VTFTexture;
  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
  v42 = 0;
  while ( 1 )
  {
    v6 = g_pFullFileSystem->IAppSystem::__vftable;
    v7 = ((int (__thiscall *)(IMaterialSystemInternal *, signed int))g_pInternalMaterialSystem->GetForcedTextureLoadPathID)(
           a1: g_pInternalMaterialSystem,
           a2: ppResolvedFilename);
    v8 = (void *)((int (__thiscall *)(IFileSystem *, signed int, const char *, _DWORD, int))v6->OpenEx)(
                   a1: g_pFullFileSystem,
                   a2: pCacheFileName,
                   a3: "rb",
                   a4: 0,
                   a5: v7);
    if ( v8 != nullptr )
      break;
    v9 = (const char *)pCacheFileName;
    v10 = V_stristr(pStr: (char *)pCacheFileName, pSearch: ".hdr.vtf");
    if ( v10 == nullptr )
    {
      v11 = CUtlSymbol::String(this: &this->m_Name);
      if ( StringAfterPrefix(str: v11, prefix: "env_cubemap") == nullptr )
        DevWarning(a1: "\"%s\": can't be found on disk\n", v9);
      FailedTexture = CTexture::HandleFileLoadFailedTexture(this, pVTFTexture: FailedTexture);
      goto LABEL_34;
    }
    strcpy(v10, ".vtf");
  }
  ppResolvedFilename = VTFFileHeaderSize(nMajorVersion: 7, nMinorVersion: -1);
  OptimalReadBuffer = CTexture::GetOptimalReadBuffer(this, hFile: v8, nSize: ppResolvedFilename, optimalBuffer: &buf);
  g_pFullFileSystem->ReadEx(
    this: g_pFullFileSystem,
    a2: buf.m_Memory.m_pMemory,
    a3: OptimalReadBuffer,
    a4: ppResolvedFilename,
    a5: v8);
  v13 = g_pFullFileSystem->IBaseFileSystem::__vftable;
  ppResolvedFilename = *((_DWORD *)buf.m_Memory.m_pMemory + 3);
  v13->Seek(this: &g_pFullFileSystem->IBaseFileSystem, a2: v8, a3: ppResolvedFilename, a4: FILESYSTEM_SEEK_HEAD);
  CUtlBuffer::SeekPut(this: &buf, type: SEEK_HEAD, offset: ppResolvedFilename);
  if ( FailedTexture->Unserialize(this: FailedTexture, a2: &buf, a3: true, a4: 0) )
  {
    ppResolvedFilename = 0;
    if ( V_strnicmp(s1: (const char *)pCacheFileName, s2: "materials/graffiti/", n: 19) == 0 )
      ppResolvedFilename = 512;
    m_nFlags = this->m_nFlags;
    if ( (m_nFlags & 0x80000) != 0 )
      ppResolvedFilename |= 0x80000u;
    if ( (m_nFlags & 0x10) != 0 )
      ppResolvedFilename |= 0x10u;
    CUtlBuffer::SeekGet(this: &buf, type: SEEK_HEAD, offset: 0);
    v36 = FailedTexture->FrameCount(this: FailedTexture);
    v15 = FailedTexture->Flags(this: FailedTexture);
    v35 = ppResolvedFilename | v15;
    v34 = FailedTexture->Format(this: FailedTexture);
    v33 = FailedTexture->Depth(this: FailedTexture);
    v32 = FailedTexture->Height(this: FailedTexture);
    v16 = FailedTexture->Width(this: FailedTexture);
    CTexture::Init(this, w: v16, h: v32, d: v33, fmt: v34, iFlags: v35, iFrameCount: v36);
    v17 = (float *)FailedTexture->Reflectivity(this: FailedTexture);
    this->m_vecReflectivity.x = *v17;
    this->m_vecReflectivity.y = v17[1];
    this->m_vecReflectivity.z = v17[2];
    v18 = CTexture::ComputeActualSize(this, bIgnorePicmip: false, pVTFTexture: FailedTexture);
    this->m_nMipSkipCount = v18;
    v19.__vftable = FailedTexture->__vftable;
    nMipSkipCount = v18;
    v20 = (char **)v19.FileSize(this: FailedTexture, a2: v18);
    v21 = g_pFullFileSystem->IBaseFileSystem::__vftable;
    ppResolvedFilename = (signed int)v20;
    v21->Seek(this: &g_pFullFileSystem->IBaseFileSystem, a2: v8, a3: 0, a4: FILESYSTEM_SEEK_HEAD);
    v22 = CTexture::GetOptimalReadBuffer(this, hFile: v8, nSize: ppResolvedFilename, optimalBuffer: &buf);
    ppResolvedFilename = g_pFullFileSystem->ReadEx(
                           this: g_pFullFileSystem,
                           a2: buf.m_Memory.m_pMemory,
                           a3: v22,
                           a4: ppResolvedFilename,
                           a5: v8);
    g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: v8);
    CUtlBuffer::SeekPut(this: &buf, type: SEEK_HEAD, offset: ppResolvedFilename);
    if ( FailedTexture->Unserialize(this: FailedTexture, a2: &buf, a3: false, a4: nMipSkipCount) )
    {
      CTexture::LoadLowResTexture(this, pTexture: FailedTexture);
      v23 = FailedTexture->GetResourceTypes(this: FailedTexture, a2: nullptr, a3: 0);
      pCacheFileName = v23;
      if ( v23 != 0 )
      {
        v24 = alloca(4 * v23);
        GetResourceTypes = FailedTexture->GetResourceTypes;
        v26 = (char **)v37;
        ppResolvedFilename = (signed int)v37;
        GetResourceTypes(this: FailedTexture, a2: v37, a3: pCacheFileName);
        CUtlVector<CTexture::DataChunk,CUtlMemory<CTexture::DataChunk,int>>::EnsureCapacity(
          this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_arrDataChunks,
          num: pCacheFileName);
        arrRsrcTypesEnd = &v37[pCacheFileName];
        if ( v37 < arrRsrcTypesEnd )
        {
          do
          {
            v27 = *v26;
            if ( *v26 != (char *)1 && *v26 != (char *)48 )
            {
              GetResourceData = FailedTexture->GetResourceData;
              dc.m_eType = (unsigned int)v27 & 0xFFFFFF;
              v29 = (unsigned __int8 *)GetResourceData(
                                         this: FailedTexture,
                                         a2: (unsigned int)v27 & 0xFFFFFF,
                                         a3: (unsigned int *)&pCacheFileName);
              if ( v29 != nullptr )
              {
                if ( pCacheFileName == 4 )
                {
                  v30 = *(_DWORD *)v29;
                  dc.m_eType |= 0x2000000u;
                  dc.m_pvData = nullptr;
                  dc.m_numBytes = v30;
                }
                else
                {
                  nMipSkipCount = pCacheFileName;
                  dc.m_pvData = (unsigned __int8 *)MemAlloc_Alloc(nSize: pCacheFileName);
                  dc.m_numBytes = nMipSkipCount;
                  memcpy(dst: dc.m_pvData, src: v29, count: pCacheFileName);
                }
                CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int>>::InsertBefore(
                  this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_arrDataChunks,
                  elem: this->m_arrDataChunks.m_Size,
                  src: (const CVTFTexture::ResourceMemorySection *)&dc);
              }
              v26 = (char **)ppResolvedFilename;
            }
            ppResolvedFilename = (signed int)++v26;
          }
          while ( v26 < (char **)arrRsrcTypesEnd );
        }
      }
      if ( !this->IsProcedural(this) )
        CTexture::SetupDebuggingTextures(this, pVTFTexture: FailedTexture);
      CTexture::ConvertToActualFormat(this, pVTFTexture: FailedTexture);
    }
    else
    {
      _Warning(a1: "Error reading material data \"%s\"\n", (const char *)pCacheFileName);
      FailedTexture = CTexture::HandleFileLoadFailedTexture(this, pVTFTexture: FailedTexture);
    }
  }
  else
  {
    _Warning(a1: "Error reading texture header \"%s\"\n", (const char *)pCacheFileName);
    g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: v8);
    FailedTexture = CTexture::HandleFileLoadFailedTexture(this, pVTFTexture: FailedTexture);
  }
LABEL_34:
  v42 = -1;
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
  return FailedTexture;
}

//------------------------------------------------------------------------------
// Address: 0x1004D650
// Name: protected: void CTexture::ReconstructTexture(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CTexture::ReconstructTexture(CTexture *this@<ecx>, int a2@<edi>)
{
  int m_nActualWidth; // eax
  int m_nActualHeight; // ecx
  int m_nActualDepth; // edx
  IVTFTexture *v6; // ebx
  int m_nActualMipCount; // eax
  IMatRenderContext *m_nFrameCount; // ecx
  IVTFTexture *TextureBitsFromFile; // eax
  const char *v10; // eax
  ImageFormat m_ImageFormat; // eax
  IMatRenderContext *v12; // eax
  IMatRenderContext *v13; // edi
  ITexture *(__thiscall *GetEmbeddedTexture)(struct CTexture *, int); // eax
  int v15; // eax
  void (__thiscall *EndRender)(IMatRenderContext *); // edx
  int (__thiscall *Release)(struct IMatRenderContext *); // edx
  int v18; // edi
  char pCacheFileName[256]; // [esp+8h] [ebp-124h] BYREF
  int oldWidth; // [esp+108h] [ebp-24h]
  int oldHeight; // [esp+10Ch] [ebp-20h]
  int oldMipCount; // [esp+110h] [ebp-1Ch]
  int oldDepth; // [esp+114h] [ebp-18h]
  char *pResolvedFilename; // [esp+118h] [ebp-14h] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+11Ch] [ebp-10h]
  int v26; // [esp+128h] [ebp-4h]

  m_nActualWidth = this->m_nActualWidth;
  m_nActualHeight = this->m_nActualHeight;
  m_nActualDepth = this->m_nActualDepth;
  v6 = nullptr;
  oldWidth = m_nActualWidth;
  m_nActualMipCount = this->m_nActualMipCount;
  oldHeight = m_nActualHeight;
  m_nFrameCount = (IMatRenderContext *)this->m_nFrameCount;
  oldDepth = m_nActualDepth;
  oldMipCount = m_nActualMipCount;
  pRenderContext.m_pObject = m_nFrameCount;
  pResolvedFilename = nullptr;
  memset(pCacheFileName, 0, sizeof(pCacheFileName));
  if ( this->IsProcedural(this) )
  {
    TextureBitsFromFile = CTexture::ReconstructProceduralBits(this);
  }
  else
  {
    if ( this->IsRenderTarget(this) )
    {
      CTexture::ComputeActualSize(this, bIgnorePicmip: true, pVTFTexture: nullptr);
      goto LABEL_14;
    }
    if ( (this->m_nInternalFlags & 0x40) != 0 )
    {
      V_snprintf(pDest: pCacheFileName, maxLen: 256, pFormat: "materials/%s.vtf", "dev/dev_exclude_error");
    }
    else
    {
      v10 = CUtlSymbol::String(this: &this->m_Name);
      if ( *v10 == 47 && v10[1] == 47 && v10[2] != 47 )
        V_snprintf(pDest: pCacheFileName, maxLen: 256, pFormat: "%s.vtf", v10);
      else
        V_snprintf(pDest: pCacheFileName, maxLen: 256, pFormat: "materials/%s.vtf", v10);
    }
    TextureBitsFromFile = CTexture::LoadTextureBitsFromFile(
                            this,
                            (signed int)pCacheFileName,
                            ppResolvedFilename: (signed int)&pResolvedFilename);
  }
  v6 = TextureBitsFromFile;
LABEL_14:
  if ( (this->m_nInternalFlags & 2) != 0
    && this->m_nActualWidth == oldWidth
    && this->m_nActualHeight == oldHeight
    && this->m_nActualDepth == oldDepth
    && this->m_nActualMipCount == oldMipCount
    && (IMatRenderContext *)this->m_nFrameCount == pRenderContext.m_pObject )
  {
    goto LABEL_23;
  }
  if ( (this->m_nInternalFlags & 2) != 0 )
    this->FreeShaderAPITextures(this);
  if ( this->AllocateShaderAPITextures(this) )
  {
LABEL_23:
    if ( this->IsRenderTarget(this) )
    {
      m_ImageFormat = this->m_ImageFormat;
      if ( m_ImageFormat != IMAGE_FORMAT_D16_SHADOW && m_ImageFormat != IMAGE_FORMAT_D24X8_SHADOW )
      {
        v12 = (IMatRenderContext *)((int (__thiscall *)(IMaterialSystemInternal *, int))g_pInternalMaterialSystem->GetRenderContext)(
                                     a1: g_pInternalMaterialSystem,
                                     a2);
        v13 = v12;
        pRenderContext.m_pObject = v12;
        v26 = 0;
        if ( v12 != nullptr )
          v12->BeginRender(this: v12);
        GetEmbeddedTexture = this->GetEmbeddedTexture;
        v26 = 1;
        v15 = (int)GetEmbeddedTexture(this, a2: 0);
        v13->PushRenderTargetAndViewport_3(this: v13, a2: (ITexture *)v15);
        g_pShaderAPI->ClearColor4ub(this: g_pShaderAPI, a2: 0, a3: 0, a4: 0, a5: 255u);
        ((void (__stdcall *)(int, _DWORD, _DWORD, _DWORD, _DWORD))g_pShaderAPI->ClearBuffers)(
          a1: 1,
          a2: 0,
          a3: 0,
          a4: this->m_nActualWidth,
          a5: this->m_nActualHeight);
        v13->PopRenderTargetAndViewport(this: v13);
        EndRender = v13->EndRender;
        v26 = 2;
        EndRender(this: v13);
        Release = v13->Release;
        v26 = -1;
        Release(this: v13);
      }
    }
    else
    {
      v18 = 1;
      if ( this->IsCubeMap(this) )
        v18 = 6;
      CTexture::WriteDataToShaderAPITexture(
        this,
        nFrameCount: this->m_nFrameCount,
        nFaceCount: v18,
        nFirstFace: 0,
        nMipCount: this->m_nActualMipCount,
        pVTFTexture: v6,
        fmt: this->m_ImageFormat);
      free(pMem: pResolvedFilename);
      CTexture::FreeOptimalReadBuffer(this, nMaxSize: 0x400000);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004D900
// Name: public: void ICallQueue::QueueCall<class CTexture __near *,class CTexture,void,class ITexture __near *,class ITexture __near *>(class CTexture __near *,void (CTexture::*)(class ITexture __near *),class ITexture __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ICallQueue::QueueCall<CTexture *,CTexture,void,ITexture *,ITexture *>(
        ICallQueue *this,
        CFunctor_vtbl *pObject,
        __int128 pfnProxied,
        ITexture *const *arg1)
{
  CFunctor *v5; // eax
  ITexture *const *v6; // edx
  CFunctor v7; // xmm0_8

  v5 = (CFunctor *)MemAlloc_Alloc(nSize: 0x30u);
  if ( v5 != nullptr )
  {
    v6 = arg1;
    v5[1].m_nUserID = 1;
    v5->__vftable = (CFunctor_vtbl *)&CMemberFunctor1<CTexture *,void (__thiscall CTexture::*)(ITexture *),ITexture *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
    v5[1].__vftable = (CFunctor_vtbl *)&CMemberFunctor1<CTexture *,void (__thiscall CTexture::*)(ITexture *),ITexture *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
    v5[2] = (CFunctor)pfnProxied;
    v7 = *((CFunctor *)&pfnProxied + 1);
    v5[4].__vftable = pObject;
    v5[3] = v7;
    v5[5].__vftable = (CFunctor_vtbl *)*v6;
    this->QueueFunctorInternal(this, a2: v5);
  }
  else
  {
    this->QueueFunctorInternal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004D970
// Name: public: CUtlStringMap<struct TextureLodOverride::OverrideInfo>::~CUtlStringMap<struct TextureLodOverride::OverrideInfo>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlStringMap<TextureLodOverride::OverrideInfo>::~CUtlStringMap<TextureLodOverride::OverrideInfo>(
        CUtlStringMap<int> *this)
{
  int *m_pMemory; // eax

  CUtlSymbolTable::~CUtlSymbolTable(this: &this->m_SymbolTable);
  this->m_Vector.m_Size = 0;
  if ( this->m_Vector.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Vector.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Vector.m_Memory.m_pMemory);
      this->m_Vector.m_Memory.m_pMemory = nullptr;
    }
    this->m_Vector.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_Vector.m_Memory.m_pMemory;
  this->m_Vector.m_pElements = this->m_Vector.m_Memory.m_pMemory;
  if ( this->m_Vector.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Vector.m_Memory.m_pMemory = nullptr;
    }
    this->m_Vector.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004DA10
// Name: public: virtual bool CTexture::SetRenderTarget(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTexture::SetRenderTarget(CTexture_MultipleRenderTarget *this, int nRenderTargetID)
{
  return this->SetRenderTarget(this, a2: nRenderTargetID, a3: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1004DA40
// Name: public: virtual void CTexture_MultipleRenderTarget::Bind(enum Sampler_t,enum TextureBindFlags_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTexture_MultipleRenderTarget::Bind(
        CTexture_MultipleRenderTarget *this,
        Sampler_t sampler,
        TextureBindFlags_t nBindFlags)
{
  int m_nActiveTarget; // eax

  m_nActiveTarget = this->m_nActiveTarget;
  if ( m_nActiveTarget >= 0 )
  {
    if ( m_nActiveTarget >= this->m_Targets.m_Size )
      g_pShaderAPI->BindTexture(this: g_pShaderAPI, a2: sampler, a3: nBindFlags, a4: 0);
    else
      g_pShaderAPI->BindTexture(
        this: g_pShaderAPI,
        a2: sampler,
        a3: nBindFlags,
        a4: this->m_Targets.m_Memory.m_pMemory[m_nActiveTarget].handle);
  }
  else
  {
    this->Bind(this, a2: sampler, a3: nBindFlags, a4: 0, a5: SHADER_SAMPLER_INVALID);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004DAC0
// Name: public: virtual void CTexture_MultipleRenderTarget::Bind(enum Sampler_t,enum TextureBindFlags_t,int,enum Sampler_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTexture_MultipleRenderTarget::Bind(
        CTexture_MultipleRenderTarget *this,
        Sampler_t sampler1,
        TextureBindFlags_t nBindFlags,
        int nFrame,
        Sampler_t sampler2)
{
  unsigned __int8 (*IsUsingGraphics)(void); // edx
  int v7; // edi
  int m_nActiveTarget; // eax

  IsUsingGraphics = (unsigned __int8 (*)(void))g_pShaderDevice->IsUsingGraphics;
  if ( this->m_nActiveTarget >= 0 )
  {
    if ( IsUsingGraphics() != 0 )
    {
      m_nActiveTarget = this->m_nActiveTarget;
      if ( m_nActiveTarget >= this->m_Targets.m_Size )
        g_pShaderAPI->BindTexture(this: g_pShaderAPI, a2: sampler1, a3: nBindFlags, a4: 0);
      else
        g_pShaderAPI->BindTexture(
          this: g_pShaderAPI,
          a2: sampler1,
          a3: nBindFlags,
          a4: this->m_Targets.m_Memory.m_pMemory[m_nActiveTarget].handle);
    }
  }
  else
  {
    v7 = nFrame;
    if ( IsUsingGraphics() != 0 )
    {
      if ( nFrame < 0 || nFrame >= this->m_nFrameCount )
        v7 = 0;
      g_pShaderAPI->BindTexture(this: g_pShaderAPI, a2: sampler1, a3: nBindFlags, a4: this->m_pTextureHandles[v7]);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004DB70
// Name: public: virtual int CTexture_MultipleRenderTarget::GetTextureHandle(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTexture_MultipleRenderTarget::GetTextureHandle(
        CTexture_MultipleRenderTarget *this,
        int nFrame,
        int nTextureChannel)
{
  int m_nActiveTarget; // eax

  m_nActiveTarget = this->m_nActiveTarget;
  if ( m_nActiveTarget >= 0 )
  {
    if ( m_nActiveTarget < this->m_Targets.m_Size )
      return this->m_Targets.m_Memory.m_pMemory[m_nActiveTarget].handle;
  }
  else if ( nFrame < this->m_nFrameCount )
  {
    return this->m_pTextureHandles[nFrame];
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1004DBB0
// Name: public: virtual int CTexture_MultipleRenderTarget::GetActualWidth(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTexture_MultipleRenderTarget::GetActualWidth(CTexture_MultipleRenderTarget *this)
{
  int iDownSizePow2; // edi
  IMatRenderContext *v3; // eax
  int m_nQueuedActiveTarget; // eax
  int m_nActiveTarget; // eax

  iDownSizePow2 = 1;
  v3 = materials->GetRenderContext(this: materials);
  if ( v3->GetCallQueue(this: v3) != nullptr )
  {
    m_nQueuedActiveTarget = this->m_nQueuedActiveTarget;
    if ( m_nQueuedActiveTarget >= 0 && m_nQueuedActiveTarget < this->m_Targets.m_Size )
      return this->m_nActualWidth / this->m_Targets.m_Memory.m_pMemory[m_nQueuedActiveTarget].iDownSizePow2;
  }
  else
  {
    m_nActiveTarget = this->m_nActiveTarget;
    if ( m_nActiveTarget >= 0 && m_nActiveTarget < this->m_Targets.m_Size )
      iDownSizePow2 = this->m_Targets.m_Memory.m_pMemory[m_nActiveTarget].iDownSizePow2;
  }
  return this->m_nActualWidth / iDownSizePow2;
}

//------------------------------------------------------------------------------
// Address: 0x1004DC20
// Name: public: virtual int CTexture_MultipleRenderTarget::GetActualHeight(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTexture_MultipleRenderTarget::GetActualHeight(CTexture_MultipleRenderTarget *this)
{
  int iDownSizePow2; // edi
  IMatRenderContext *v3; // eax
  int m_nQueuedActiveTarget; // eax
  int m_nActiveTarget; // eax

  iDownSizePow2 = 1;
  v3 = materials->GetRenderContext(this: materials);
  if ( v3->GetCallQueue(this: v3) != nullptr )
  {
    m_nQueuedActiveTarget = this->m_nQueuedActiveTarget;
    if ( m_nQueuedActiveTarget >= 0 && m_nQueuedActiveTarget < this->m_Targets.m_Size )
      return this->m_nActualHeight / this->m_Targets.m_Memory.m_pMemory[m_nQueuedActiveTarget].iDownSizePow2;
  }
  else
  {
    m_nActiveTarget = this->m_nActiveTarget;
    if ( m_nActiveTarget >= 0 && m_nActiveTarget < this->m_Targets.m_Size )
      iDownSizePow2 = this->m_Targets.m_Memory.m_pMemory[m_nActiveTarget].iDownSizePow2;
  }
  return this->m_nActualHeight / iDownSizePow2;
}

//------------------------------------------------------------------------------
// Address: 0x1004DC90
// Name: public: virtual bool CTexture_MultipleRenderTarget::AllocateShaderAPITextures(void)
// Source: json
//------------------------------------------------------------------------------
bool __usercall CTexture_MultipleRenderTarget::AllocateShaderAPITextures@<al>(
        CTexture_MultipleRenderTarget *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>)
{
  bool result; // al
  int CreationFlags; // eax
  bool v6; // zf
  const char *v7; // eax
  IShaderAPI_vtbl *v8; // ebx
  int *v9; // edi
  int v10; // eax
  IShaderAPI_vtbl *v11; // ebx
  const char *v12; // eax
  CTexture_MultipleRenderTarget::SubTarget_t *m_pMemory; // edi
  char debugName[128]; // [esp+4h] [ebp-90h] BYREF
  int nCreateFlags; // [esp+84h] [ebp-10h]
  int nShaderApiCreateTextureDepth; // [esp+88h] [ebp-Ch]
  int i; // [esp+8Ch] [ebp-8h]
  IShaderAPI_vtbl *p_SetPixelShaderConstant; // [esp+90h] [ebp-4h]

  result = CTexture::AllocateShaderAPITextures(this, a2, a3);
  if ( result )
  {
    if ( this->m_Targets.m_Size != 0 )
    {
      CreationFlags = GetCreationFlags(
                        iTextureFlags: this->m_nFlags,
                        iInternalTextureFlags: this->m_nInternalFlags,
                        fmt: this->m_ImageFormat);
      v6 = (this->m_nFlags & 0x10000) == 0;
      nCreateFlags = CreationFlags;
      if ( v6 || this->m_nOriginalRenderTargetType != RENDER_TARGET_ONLY_DEPTH )
        nShaderApiCreateTextureDepth = this->m_nActualDepth;
      else
        nShaderApiCreateTextureDepth = 1;
      i = 0;
      if ( this->m_Targets.m_Size != 0 )
      {
        p_SetPixelShaderConstant = nullptr;
        do
        {
          v7 = CUtlSymbol::String(this: &this->m_TextureGroupName);
          v8 = g_pShaderAPI->__vftable;
          v9 = (int *)((char *)p_SetPixelShaderConstant + (unsigned int)this->m_Targets.m_Memory.m_pMemory);
          v10 = ((int (__thiscall *)(CTexture_MultipleRenderTarget *, const char *))this->GetName)(a1: this, a2: v7);
          ((void (__thiscall *)(IShaderAPI *, int *, int, int, int, int, ImageFormat, _DWORD, int, int, int))v8->CreateTextures)(
            a1: g_pShaderAPI,
            a2: v9 + 2,
            a3: 1,
            a4: this->m_nActualWidth / v9[1],
            a5: this->m_nActualHeight / v9[1],
            a6: nShaderApiCreateTextureDepth,
            a7: this->m_ImageFormat,
            a8: this->m_nActualMipCount,
            a9: 1,
            a10: nCreateFlags,
            a11: v10);
          v11 = p_SetPixelShaderConstant;
          if ( *(&this->m_Targets.m_Memory.m_pMemory->bHasSeparateDepth + (unsigned int)p_SetPixelShaderConstant) )
          {
            v12 = (const char *)this->GetName(this);
            sprintf(string: debugName, format: "%s_ZBuffer", v12);
            m_pMemory = this->m_Targets.m_Memory.m_pMemory;
            v6 = this->m_nOriginalRenderTargetType == RENDER_TARGET_ONLY_DEPTH;
            p_SetPixelShaderConstant = g_pShaderAPI->__vftable;
            *(void (__thiscall **)(struct IShaderAPI *, unsigned __int8 *))((char *)&v11->GetSceneFogColor
                                                                          + (_DWORD)m_pMemory) = (void (__thiscall *)(struct IShaderAPI *, unsigned __int8 *))p_SetPixelShaderConstant->CreateDepthTexture(this: g_pShaderAPI, a2: this->m_ImageFormat, a3: this->m_nActualWidth / *(int *)((char *)&v11->GetLightmapDimensions + (_DWORD)m_pMemory), a4: this->m_nActualHeight / *(int *)((char *)&v11->GetLightmapDimensions + (_DWORD)m_pMemory), a5: debugName, a6: v6, a7: false);
          }
          ++i;
          p_SetPixelShaderConstant = (IShaderAPI_vtbl *)&v11->SetPixelShaderConstant;
        }
        while ( i != this->m_Targets.m_Size );
      }
    }
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004DDF0
// Name: public: virtual void CTexture_MultipleRenderTarget::FreeShaderAPITextures(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CTexture_MultipleRenderTarget::FreeShaderAPITextures(
        CTexture_MultipleRenderTarget *this@<ecx>,
        int depthHandle@<edi>)
{
  int v3; // ebx
  int v4; // edi

  v3 = 0;
  if ( this->m_Targets.m_Size != 0 )
  {
    v4 = 0;
    do
    {
      if ( ((unsigned __int8 (__thiscall *)(IShaderAPI *, int, int))g_pShaderAPI->IsTexture)(
             a1: g_pShaderAPI,
             a2: this->m_Targets.m_Memory.m_pMemory[v4].handle,
             a3: depthHandle) != 0 )
      {
        g_pShaderAPI->DeleteTexture(this: g_pShaderAPI, a2: this->m_Targets.m_Memory.m_pMemory[v4].handle);
        this->m_Targets.m_Memory.m_pMemory[v4].handle = 0;
      }
      depthHandle = this->m_Targets.m_Memory.m_pMemory[v4].depthHandle;
      if ( ((unsigned __int8 (__thiscall *)(IShaderAPI *))g_pShaderAPI->IsTexture)(a1: g_pShaderAPI) != 0 )
      {
        g_pShaderAPI->DeleteTexture(this: g_pShaderAPI, a2: this->m_Targets.m_Memory.m_pMemory[v4].depthHandle);
        this->m_Targets.m_Memory.m_pMemory[v4].depthHandle = 0;
      }
      ++v3;
      ++v4;
    }
    while ( v3 != this->m_Targets.m_Size );
  }
  CTexture::FreeShaderAPITextures(this);
}

//------------------------------------------------------------------------------
// Address: 0x1004DEA0
// Name: public: virtual bool CTexture_MultipleRenderTarget::SetRenderTarget(int,class ITexture __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTexture_MultipleRenderTarget::SetRenderTarget(
        CTexture_MultipleRenderTarget *this,
        int nRenderTargetID,
        ITexture *pDepthTexture)
{
  int m_nActiveTarget; // esi
  unsigned int m_nFlags; // ebx
  CTexture_MultipleRenderTarget::SubTarget_t *v6; // edx
  int depthHandle; // eax
  int handle; // edi

  m_nActiveTarget = this->m_nActiveTarget;
  if ( m_nActiveTarget < 0 || m_nActiveTarget >= this->m_Targets.m_Size )
    return CTexture::SetRenderTarget(this, nRenderTargetID, pDepthTexture);
  m_nFlags = this->m_nFlags;
  if ( (m_nFlags & 0x8000) == 0 )
    return 0;
  v6 = &this->m_Targets.m_Memory.m_pMemory[m_nActiveTarget];
  depthHandle = -1;
  handle = v6->handle;
  if ( v6->bHasSeparateDepth )
  {
    depthHandle = this->m_Targets.m_Memory.m_pMemory[m_nActiveTarget].depthHandle;
  }
  else if ( (m_nFlags & 0x800000) != 0 )
  {
    depthHandle = -2;
  }
  if ( pDepthTexture != nullptr )
    depthHandle = ((int (__thiscall *)(ITexture *, _DWORD, _DWORD))pDepthTexture->__vftable[1].SetTextureRegenerator)(
                    a1: pDepthTexture,
                    a2: 0,
                    a3: 0);
  g_pShaderAPI->SetRenderTargetEx(this: g_pShaderAPI, a2: nRenderTargetID, a3: handle, a4: depthHandle);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1004DF30
// Name: public: virtual void CTexture_MultipleRenderTarget::CopyFrameBufferToMe(int,struct Rect_t __near *,struct Rect_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTexture_MultipleRenderTarget::CopyFrameBufferToMe(
        CTexture_MultipleRenderTarget *this,
        int nRenderTargetID,
        Rect_t *pSrcRect,
        Rect_t *pDstRect)
{
  int m_nActiveTarget; // edx
  int *m_pTextureHandles; // edx

  m_nActiveTarget = this->m_nActiveTarget;
  if ( m_nActiveTarget < 0 || m_nActiveTarget >= this->m_Targets.m_Size )
  {
    m_pTextureHandles = this->m_pTextureHandles;
    if ( m_pTextureHandles != nullptr && this->m_nFrameCount != 0 )
      g_pShaderAPI->CopyRenderTargetToTextureEx(
        this: g_pShaderAPI,
        a2: *m_pTextureHandles,
        a3: nRenderTargetID,
        a4: pSrcRect,
        a5: pDstRect);
  }
  else if ( this->m_pTextureHandles != nullptr && this->m_nFrameCount != 0 )
  {
    g_pShaderAPI->CopyRenderTargetToTextureEx(
      this: g_pShaderAPI,
      a2: this->m_Targets.m_Memory.m_pMemory[m_nActiveTarget].handle,
      a3: nRenderTargetID,
      a4: pSrcRect,
      a5: pDstRect);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004E040
// Name: public: virtual void CTexture_MultipleRenderTarget::AddDownsizedSubTarget(char const __near *,int,enum MaterialRenderTargetDepth_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTexture_MultipleRenderTarget::AddDownsizedSubTarget(
        CTexture_MultipleRenderTarget *this,
        const char *szName,
        int iDownsizePow2,
        MaterialRenderTargetDepth_t depth)
{
  const char *v4; // esi
  int v6; // eax
  char szCleanName[260]; // [esp+8h] [ebp-118h] BYREF
  CTexture_MultipleRenderTarget::SubTarget_t temp; // [esp+10Ch] [ebp-14h] BYREF

  v4 = szName;
  temp.name.m_Id = -1;
  v6 = _V_strlen(str: szName) + 1;
  if ( v6 <= 5 || _V_stricmp(s1: &v4[v6 - 5], s2: ".hdr") != 0 )
    V_StripExtension(in: v4, out: szCleanName, outSize: 260);
  else
    V_strncpy(pDest: szCleanName, pSrc: v4, maxLen: 260);
  _V_strlower(start: szCleanName);
  V_FixSlashes(pname: szCleanName, separator: 47);
  CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&szName + 1, pStr: szCleanName);
  temp.name.m_Id = HIWORD(szName);
  temp.iDownSizePow2 = iDownsizePow2;
  temp.handle = 0;
  temp.depthHandle = 0;
  if ( depth == MATERIAL_RT_DEPTH_SEPARATE || (temp.bHasSeparateDepth = false, depth == MATERIAL_RT_DEPTH_ONLY) )
    temp.bHasSeparateDepth = true;
  CUtlVector<CTexture_MultipleRenderTarget::SubTarget_t,CUtlMemory<CTexture_MultipleRenderTarget::SubTarget_t,int>>::InsertBefore(
    this: &this->m_Targets,
    elem: this->m_Targets.m_Size,
    src: &temp);
}

//------------------------------------------------------------------------------
// Address: 0x1004E120
// Name: public: virtual void CTexture_MultipleRenderTarget::SetActiveSubTarget(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTexture_MultipleRenderTarget::SetActiveSubTarget(CTexture_MultipleRenderTarget *this, char *szName)
{
  IMatRenderContext *v3; // eax
  ICallQueue *v4; // ebx
  int v5; // edi
  int v6; // ebx
  CFunctor *v7; // eax
  CFunctor v8; // xmm0_8
  int v9; // edi
  int i; // ebx
  char szCleanName[260]; // [esp+Ch] [ebp-118h] BYREF
  CFunctor v12; // [esp+110h] [ebp-14h]
  CFunctor v13; // [esp+118h] [ebp-Ch]
  ICallQueue *pCallQueue; // [esp+120h] [ebp-4h]

  v3 = materials->GetRenderContext(this: materials);
  v4 = v3->GetCallQueue(this: v3);
  pCallQueue = v4;
  if ( v4 != nullptr )
  {
    this->m_nQueuedActiveTarget = -1;
    if ( szName != nullptr )
    {
      NormalizeTextureName(pName: szName, pOutName: szCleanName, nOutNameSize: 260);
      v5 = 0;
      if ( this->m_Targets.m_Size != 0 )
      {
        v6 = 0;
        while ( !CUtlSymbol::operator==(this: &this->m_Targets.m_Memory.m_pMemory[v6].name, pStr: szCleanName) )
        {
          ++v5;
          ++v6;
          if ( v5 == this->m_Targets.m_Size )
            goto LABEL_9;
        }
        this->m_nQueuedActiveTarget = v5;
LABEL_9:
        v4 = pCallQueue;
      }
      v12.__vftable = (CFunctor_vtbl *) __thiscall CTexture_MultipleRenderTarget::`vcall'{124,{flat}};
      v12.m_nUserID = 0;
      v13 = 0;
      v7 = (CFunctor *)MemAlloc_Alloc(nSize: 0x30u);
      if ( v7 != nullptr )
      {
        v8 = v12;
        v7[1].m_nUserID = 1;
        v7->__vftable = (CFunctor_vtbl *)&CMemberFunctor1<CTexture_MultipleRenderTarget *,void (__thiscall CTexture_MultipleRenderTarget::*)(char const *),char const *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
        v7[1].__vftable = (CFunctor_vtbl *)&CMemberFunctor1<CTexture_MultipleRenderTarget *,void (__thiscall CTexture_MultipleRenderTarget::*)(char const *),char const *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
        v7[2] = v8;
        v7[3] = v13;
        v7[4].__vftable = (CFunctor_vtbl *)this;
        v7[5].__vftable = (CFunctor_vtbl *)szName;
        v4->QueueFunctorInternal(this: v4, a2: v7);
      }
      else
      {
        v4->QueueFunctorInternal(this: v4, a2: nullptr);
      }
    }
  }
  else
  {
    this->m_nActiveTarget = -1;
    if ( szName != nullptr )
    {
      NormalizeTextureName(pName: szName, pOutName: szCleanName, nOutNameSize: 260);
      v9 = 0;
      if ( this->m_Targets.m_Size != 0 )
      {
        for ( i = 0; !CUtlSymbol::operator==(this: &this->m_Targets.m_Memory.m_pMemory[i].name, pStr: szCleanName); ++i )
        {
          if ( ++v9 == this->m_Targets.m_Size )
            return;
        }
        this->m_nActiveTarget = v9;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004E2A0
// Name: public: virtual CTexture_MultipleRenderTarget::~CTexture_MultipleRenderTarget(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTexture_MultipleRenderTarget::~CTexture_MultipleRenderTarget(CTexture_MultipleRenderTarget *this)
{
  CUtlVector<CTexture_MultipleRenderTarget::SubTarget_t,CUtlMemory<CTexture_MultipleRenderTarget::SubTarget_t,int> > *p_m_Targets; // esi
  CTexture_MultipleRenderTarget::SubTarget_t *m_pMemory; // eax

  p_m_Targets = &this->m_Targets;
  this->m_Targets.m_Size = 0;
  if ( this->m_Targets.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_Targets->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_Targets->m_Memory.m_pMemory);
      p_m_Targets->m_Memory.m_pMemory = nullptr;
    }
    p_m_Targets->m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = p_m_Targets->m_Memory.m_pMemory;
  p_m_Targets->m_pElements = p_m_Targets->m_Memory.m_pMemory;
  if ( p_m_Targets->m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      p_m_Targets->m_Memory.m_pMemory = nullptr;
    }
    p_m_Targets->m_Memory.m_nAllocationCount = 0;
  }
  CTexture::~CTexture(this);
}

//------------------------------------------------------------------------------
// Address: 0x1004E340
// Name: public: static class ITextureInternal __near * ITextureInternal::CreateFileTexture(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CTexture *__cdecl ITextureInternal::CreateFileTexture(const char *pFileName, const char *pTextureGroupName)
{
  CTexture *v2; // eax
  CTexture *v3; // esi
  CUtlSymbol v5[2]; // [esp+4h] [ebp-10h] BYREF
  int v6; // [esp+10h] [ebp-4h]

  v2 = (CTexture *)MemAlloc_Alloc(nSize: 0x68u);
  v5[1] = *(CUtlSymbol *)((char *)&v2 + 2);
  v3 = nullptr;
  v6 = 0;
  if ( v2 != nullptr )
    v3 = CTexture::CTexture(this: v2);
  v6 = -1;
  CTexture::SetName(this: v3, pName: pFileName);
  CUtlSymbol::CUtlSymbol(this: &v5[1], pStr: pTextureGroupName);
  v3->m_TextureGroupName = v5[1];
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1004E3B0
// Name: public: static class ITextureInternal __near * ITextureInternal::CreateProceduralTexture(char const __near *,char const __near *,int,int,int,enum ImageFormat,int)
// Source: json
//------------------------------------------------------------------------------
CTexture *__cdecl ITextureInternal::CreateProceduralTexture(
        const char *pTextureName,
        const char *pTextureGroupName,
        unsigned __int16 w,
        unsigned __int16 h,
        unsigned __int16 d,
        ImageFormat fmt,
        int nFlags)
{
  CTexture *v7; // eax
  CTexture *v8; // esi

  v7 = (CTexture *)MemAlloc_Alloc(nSize: 0x68u);
  v8 = nullptr;
  if ( v7 != nullptr )
    v8 = CTexture::CTexture(this: v7);
  CTexture::InitProceduralTexture(this: v8, pTextureName, pTextureGroupName, w, h, d, fmt, nFlags);
  v8->IncrementReferenceCount(this: v8);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x1004E430
// Name: public: static class ITextureInternal __near * ITextureInternal::CreateRenderTarget(char const __near *,int,int,enum RenderTargetSizeMode_t,enum ImageFormat,enum RenderTargetType_t,unsigned int,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
CTexture *__cdecl ITextureInternal::CreateRenderTarget(
        const char *pRTName,
        unsigned __int16 w,
        unsigned __int16 h,
        RenderTargetSizeMode_t sizeMode,
        ImageFormat fmt,
        RenderTargetType_t type,
        unsigned int textureFlags,
        char renderTargetFlags,
        bool bMultipleTargets)
{
  CTexture *v9; // eax
  CTexture *v10; // esi
  CTexture *v11; // eax
  CTexture *v12; // eax

  if ( bMultipleTargets )
  {
    v9 = (CTexture *)MemAlloc_Alloc(nSize: 0x84u);
    v10 = v9;
    if ( v9 != nullptr )
    {
      CTexture::CTexture(this: v9);
      v10->__vftable = (CTexture_vtbl *)&CTexture_MultipleRenderTarget::`vftable';
      v10[1].__vftable = nullptr;
      v10[1].m_vecReflectivity.x = 0.0;
      v10[1].m_vecReflectivity.y = 0.0;
      v10[1].m_vecReflectivity.z = 0.0;
      *(_DWORD *)&v10[1].m_Name.m_Id = 0;
      v10[1].m_nFlags = -1;
      v10[1].m_nInternalFlags = -1;
    }
    else
    {
      v10 = nullptr;
    }
  }
  else
  {
    v11 = (CTexture *)MemAlloc_Alloc(nSize: 0x68u);
    if ( v11 != nullptr )
      v12 = CTexture::CTexture(this: v11);
    else
      v12 = nullptr;
    v10 = v12;
  }
  CTexture::InitRenderTarget(this: v10, pRTName, w, h, sizeMode, fmt, type, textureFlags, renderTargetFlags);
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x1004E540
// Name: protected: void CTexture::DownloadTexture(struct Rect_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CTexture::DownloadTexture(CTexture *this@<ecx>, int a2@<edi>, Rect_t *pRect)
{
  unsigned int m_nInternalFlags; // eax

  if ( g_pShaderDevice->IsUsingGraphics(this: g_pShaderDevice) )
  {
    if ( pRect != nullptr )
      CTexture::ReconstructPartialTexture(this, pRect);
    else
      CTexture::ReconstructTexture(this, a2);
    this->SetFilteringAndClampingMode(this);
    m_nInternalFlags = this->m_nInternalFlags;
    if ( (m_nInternalFlags & 0x40) != 0 )
      this->m_nInternalFlags = m_nInternalFlags | 0x20;
    else
      this->m_nInternalFlags = m_nInternalFlags & 0xFFFFFFDF;
    this->m_nActualDimensionLimit = this->m_nDesiredDimensionLimit;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004E5B0
// Name: public: virtual void CTexture::Download(struct Rect_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTexture::Download(CTexture *this, Rect_t *pRect, int nAdditionalCreationFlags)
{
  MaterialLock_t__ *v4; // edi

  if ( g_pShaderAPI->CanDownloadTextures(this: g_pShaderAPI) )
  {
    v4 = g_pInternalMaterialSystem->Lock(this: g_pInternalMaterialSystem);
    this->m_nFlags |= nAdditionalCreationFlags;
    CTexture::DownloadTexture(this, a2: (int)v4, pRect);
    g_pInternalMaterialSystem->Unlock(this: g_pInternalMaterialSystem, a2: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004E610
// Name: public: virtual void CTexture::SwapContents(class ITexture __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTexture::SwapContents(CTexture *this, CTexture *pOther)
{
  IMatRenderContext *v3; // eax
  ICallQueue *v4; // eax
  void *v5; // esp
  ITexture *v6; // edx
  _WORD v7[70]; // [esp-70h] [ebp-8Ch] BYREF

  if ( pOther != nullptr && pOther != this )
  {
    v3 = materials->GetRenderContext(this: materials);
    v4 = v3->GetCallQueue(this: v3);
    if ( v4 != nullptr )
    {
      memset(&v7[64], 0, 12);
      ICallQueue::QueueCall<CTexture *,CTexture,void,ITexture *,ITexture *>(
        this: v4,
        pObject: (CFunctor_vtbl *)this,
        pfnProxied: (unsigned int) __thiscall IColorCorrectionSystem::`vcall'{104,{flat}},
        arg1: &pOther);
    }
    else
    {
      v5 = alloca(112);
      v6 = pOther;
      qmemcpy(v7, this, 0x68u);
      qmemcpy(this, pOther, sizeof(CTexture));
      qmemcpy(v6, v7, 104);
      LOWORD(v6[4].__vftable) = this->m_Name.m_Id;
      this->m_Name.m_Id = v7[8];
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004E6E0
// Name: mat_texture_list_txlod_sync
// Source: json
//------------------------------------------------------------------------------
void __cdecl mat_texture_list_txlod_sync(const CCommand *args)
{
  const char *v1; // esi
  int v2; // ebx
  const char *v3; // edi
  ITexture *v4; // eax
  TextureLodOverride::OverrideInfo *m_pMemory; // eax
  const char *v6; // edi
  TextureLodOverride::OverrideInfo v7; // bx
  ITexture *v8; // eax
  ITexture *v9; // esi
  CP4File *v10; // ebx
  int (__thiscall *GetActualHeight)(ITexture *); // eax
  CP4File *v12; // esi
  char *v13; // ecx
  char *v14; // eax
  char *v15; // esi
  char *m_pszString; // eax
  char *v17; // edi
  bool (__thiscall *ReadFile)(IBaseFileSystem *, const char *, const char *, CUtlBuffer *, int, int, void *(__cdecl *)(const char *, unsigned int)); // edx
  int i; // edi
  CP4File *v20; // edi
  bool (__thiscall *Edit)(CP4File *); // eax
  bool (__thiscall *WriteFile)(IBaseFileSystem *, const char *, const char *, CUtlBuffer *); // edx
  CP4File *v23; // esi
  bool (__thiscall *Add)(CP4File *); // edx
  void (__thiscall *dtr_CP4File)(CP4File *); // edx
  void (__thiscall *v26)(CP4File *); // eax
  bool (__thiscall *v27)(IBaseFileSystem *, const char *, const char *, CUtlBuffer *, int, int, void *(__cdecl *)(const char *, unsigned int)); // eax
  int j; // edi
  struct CSysModule *m_pP4Module; // esi
  char chCommand[260]; // [esp+Ch] [ebp-4FCh] BYREF
  char chResolveNameArg[260]; // [esp+110h] [ebp-3F8h] BYREF
  char szTxtFileName[260]; // [esp+214h] [ebp-2F4h] BYREF
  char chResolveName[260]; // [esp+318h] [ebp-1F0h] BYREF
  CUtlBuffer v34; // [esp+41Ch] [ebp-ECh] BYREF
  CUtlBuffer bufTxtFileBuffer; // [esp+46Ch] [ebp-9Ch] BYREF
  char chMaxWidth[20]; // [esp+4BCh] [ebp-4Ch] BYREF
  char chMaxHeight[20]; // [esp+4D0h] [ebp-38h] BYREF
  CP4Requirement p4req; // [esp+4E4h] [ebp-24h] BYREF
  CP4AutoAddFile v39; // [esp+4ECh] [ebp-1Ch] BYREF
  CP4AutoEditFile v40; // [esp+4F0h] [ebp-18h] BYREF
  CP4AutoEditFile autop4_edit; // [esp+4F4h] [ebp-14h]
  CP4AutoAddFile autop4_add; // [esp+4F8h] [ebp-10h]
  int v43; // [esp+504h] [ebp-4h]
  int k; // [esp+510h] [ebp+8h]

  if ( args->m_nArgc != 2 )
    goto usage;
  v1 = args->m_ppArgv[1];
  _Msg(a1: "mat_texture_list_txlod_sync %s...\n", v1);
  if ( _V_stricmp(s1: v1, s2: "reset") == 0 )
  {
    v2 = 0;
    if ( TextureLodOverride::s_OverrideMap.m_SymbolTable.m_Lookup.m_NumElements != 0 )
    {
      do
      {
        v3 = CUtlSymbolTable::String(this: &TextureLodOverride::s_OverrideMap.m_SymbolTable, id: (CUtlSymbol)v2);
        TextureLodOverride::s_OverrideMap.m_Vector.m_Memory.m_pMemory[(unsigned __int16)v2] = 0;
        v4 = materials->FindTexture(this: materials, a2: v3, a3: &pMem, a4: 1, a5: 0);
        if ( v4 != nullptr )
          v4->ForceLODOverride(this: v4, a2: 0);
        else
          _Warning(a1: " mat_texture_list_txlod_sync reset - texture '%s' no longer found.\n", v3);
        ++v2;
      }
      while ( v2 < TextureLodOverride::s_OverrideMap.m_SymbolTable.m_Lookup.m_NumElements );
    }
    m_pMemory = TextureLodOverride::s_OverrideMap.m_Vector.m_Memory.m_pMemory;
    TextureLodOverride::s_OverrideMap.m_Vector.m_Size = 0;
    if ( TextureLodOverride::s_OverrideMap.m_Vector.m_Memory.m_nGrowSize >= 0 )
    {
      if ( TextureLodOverride::s_OverrideMap.m_Vector.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: TextureLodOverride::s_OverrideMap.m_Vector.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        TextureLodOverride::s_OverrideMap.m_Vector.m_Memory.m_pMemory = nullptr;
      }
      TextureLodOverride::s_OverrideMap.m_Vector.m_Memory.m_nAllocationCount = 0;
    }
    TextureLodOverride::s_OverrideMap.m_Vector.m_pElements = m_pMemory;
    CUtlSymbolTable::RemoveAll(this: &TextureLodOverride::s_OverrideMap.m_SymbolTable);
    _Msg(a1: "mat_texture_list_txlod_sync reset : completed.\n");
    return;
  }
  if ( _V_stricmp(s1: v1, s2: "save") != 0 )
  {
usage:
    _Warning(
      a1: "Usage:\n"
      "  mat_texture_list_txlod_sync reset - resets all run-time changes to LOD overrides;\n"
      "  mat_texture_list_txlod_sync save  - saves all changes to material content files.\n");
    return;
  }
  CP4Requirement::CP4Requirement(this: &p4req);
  v43 = 0;
  if ( p4 == nullptr )
    CP4Factory::SetDummyMode(this: g_p4factory, bDummyMode: true);
  k = 0;
  if ( TextureLodOverride::s_OverrideMap.m_SymbolTable.m_Lookup.m_NumElements != 0 )
  {
    do
    {
      v6 = CUtlSymbolTable::String(this: &TextureLodOverride::s_OverrideMap.m_SymbolTable, id: (CUtlSymbol)k);
      v7 = TextureLodOverride::s_OverrideMap.m_Vector.m_Memory.m_pMemory[(unsigned __int16)k];
      v8 = materials->FindTexture(this: materials, a2: v6, a3: &pMem, a4: 1, a5: 0);
      v9 = v8;
      if ( v7.x != 0 && v7.y != 0 )
      {
        if ( v8 != nullptr )
        {
          v10 = (CP4File *)v8->GetActualWidth(this: v8);
          GetActualHeight = v9->GetActualHeight;
          autop4_edit.m_spImpl.m_p = v10;
          v12 = (CP4File *)GetActualHeight(this: v9);
          autop4_add.m_spImpl.m_p = v12;
          sprintf(string: chMaxWidth, format: "%d", v10);
          sprintf(string: chMaxHeight, format: "%d", v12);
          memset(chResolveName, 0, sizeof(chResolveName));
          memset(chResolveNameArg, 0, sizeof(chResolveNameArg));
          V_snprintf(pDest: chResolveNameArg, maxLen: 259, pFormat: "materials/%s.vtf", v6);
          if ( (mat_texture_list_content_path.m_nFlags & 0x1000) != 0
            || (v13 = mat_texture_list_content_path.m_pParent->m_Value.m_pszString) != nullptr && *v13 != 0 )
          {
            if ( (mat_texture_list_content_path.m_nFlags & 0x1000) != 0 )
            {
              m_pszString = "FCVAR_NEVER_AS_STRING";
            }
            else
            {
              m_pszString = mat_texture_list_content_path.m_pParent->m_Value.m_pszString;
              if ( m_pszString == nullptr )
                m_pszString = (char *)&pMem;
            }
            V_strncpy(pDest: chResolveName, pSrc: m_pszString, maxLen: 260);
            V_strncat(pDest: chResolveName, pSrc: "/", destBufferSize: 0x104u, max_chars_to_copy: -1);
            V_strncat(pDest: chResolveName, pSrc: v6, destBufferSize: 0x104u, max_chars_to_copy: -1);
            V_strncat(pDest: chResolveName, pSrc: aVtf_0, destBufferSize: 0x104u, max_chars_to_copy: -1);
            v15 = chResolveName;
LABEL_34:
            v17 = &v15[strlen(v15) - 4];
            sprintf(string: v17, format: ".tga");
            if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: v15, a3: nullptr) )
            {
              sprintf(string: v17, format: ".txt");
              CUtlBuffer::CUtlBuffer(this: &bufTxtFileBuffer, growSize: 0, initSize: 0, nFlags: 1);
              ReadFile = g_pFullFileSystem->ReadFile;
              LOBYTE(v43) = 1;
              ReadFile(
                this: &g_pFullFileSystem->IBaseFileSystem,
                a2: v15,
                a3: nullptr,
                a4: &bufTxtFileBuffer,
                a5: 0,
                a6: 0,
                a7: nullptr);
              for ( i = 1024; i != 0; --i )
                CUtlBuffer::PutChar(this: &bufTxtFileBuffer, c: 0);
              SetBufferValue(
                chTxtFileBuffer: (char *)bufTxtFileBuffer.m_Memory.m_pMemory,
                szLookupKey: "maxwidth",
                szNewValue: chMaxWidth);
              SetBufferValue(
                chTxtFileBuffer: (char *)bufTxtFileBuffer.m_Memory.m_pMemory,
                szLookupKey: "maxheight",
                szNewValue: chMaxHeight);
              CUtlBuffer::SeekPut(
                this: &bufTxtFileBuffer,
                type: SEEK_HEAD,
                offset: strlen((const char *)bufTxtFileBuffer.m_Memory.m_pMemory));
              CP4Factory::SetOpenFileChangeList(this: g_p4factory, szChangeListName: "Texture LOD Autocheckout");
              v20 = CP4Factory::AccessFile(this: g_p4factory, szFilename: v15);
              autop4_edit.m_spImpl.m_p = v20;
              Edit = v20->Edit;
              LOBYTE(v43) = 2;
              Edit(this: v20);
              WriteFile = g_pFullFileSystem->WriteFile;
              LOBYTE(v43) = 3;
              if ( WriteFile(this: &g_pFullFileSystem->IBaseFileSystem, a2: v15, a3: nullptr, a4: &bufTxtFileBuffer) )
              {
                _Msg(a1: " '%s' : saved.\n", v15);
                v23 = CP4Factory::AccessFile(this: g_p4factory, szFilename: v15);
                autop4_add.m_spImpl.m_p = v23;
                Add = v23->Add;
                LOBYTE(v43) = 4;
                Add(this: v23);
                dtr_CP4File = v23->dtr_CP4File;
                LOBYTE(v43) = 3;
                ((void (__thiscall *)(CP4File *, int))dtr_CP4File)(a1: v23, a2: 1);
              }
              else
              {
                _Warning(
                  a1: " '%s' : failed to save - set \"maxwidth %d maxheight %d\" manually.\n",
                  v15,
                  v10,
                  autop4_add.m_spImpl.m_p);
              }
              v26 = v20->dtr_CP4File;
              LOBYTE(v43) = 1;
              ((void (__thiscall *)(CP4File *, int))v26)(a1: v20, a2: 1);
              LOBYTE(v43) = 0;
              if ( bufTxtFileBuffer.m_Memory.m_nGrowSize >= 0 && bufTxtFileBuffer.m_Memory.m_pMemory != nullptr )
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bufTxtFileBuffer.m_Memory.m_pMemory);
            }
            else
            {
              sprintf(string: v17, format: ".psd");
              if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: v15, a3: nullptr) )
              {
                memset(szTxtFileName, 0, sizeof(szTxtFileName));
                GetModSubdirectory(pSubDir: "tmp_lod_psdinfo.txt", pBuf: szTxtFileName, nBufLen: 260);
                sprintf(string: chCommand, format: "/C psdinfo \"%s\" > \"%s\"", v15, szTxtFileName);
                ShellExecuteA(
                  hwnd: nullptr,
                  lpOperation: nullptr,
                  lpFile: "cmd.exe",
                  lpParameters: chCommand,
                  lpDirectory: nullptr,
                  nShowCmd: 0);
                Sleep(dwMilliseconds: 0xC8u);
                CUtlBuffer::CUtlBuffer(this: &v34, growSize: 0, initSize: 0, nFlags: 1);
                v27 = g_pFullFileSystem->ReadFile;
                LOBYTE(v43) = 5;
                v27(
                  this: &g_pFullFileSystem->IBaseFileSystem,
                  a2: szTxtFileName,
                  a3: nullptr,
                  a4: &v34,
                  a5: 0,
                  a6: 0,
                  a7: nullptr);
                for ( j = 1024; j != 0; --j )
                  CUtlBuffer::PutChar(this: &v34, c: 0);
                SetBufferValue(
                  chTxtFileBuffer: (char *)v34.m_Memory.m_pMemory,
                  szLookupKey: "maxwidth",
                  szNewValue: chMaxWidth);
                SetBufferValue(
                  chTxtFileBuffer: (char *)v34.m_Memory.m_pMemory,
                  szLookupKey: "maxheight",
                  szNewValue: chMaxHeight);
                CUtlBuffer::SeekPut(this: &v34, type: SEEK_HEAD, offset: strlen((const char *)v34.m_Memory.m_pMemory));
                if ( g_pFullFileSystem->WriteFile(
                       this: &g_pFullFileSystem->IBaseFileSystem,
                       a2: szTxtFileName,
                       a3: nullptr,
                       a4: &v34) )
                {
                  CP4Factory::SetOpenFileChangeList(this: g_p4factory, szChangeListName: "Texture LOD Autocheckout");
                  CP4AutoEditFile::CP4AutoEditFile(this: &v40, szFilename: v15);
                  LOBYTE(v43) = 6;
                  sprintf(string: chCommand, format: "/C psdinfo -write \"%s\" < \"%s\"", v15, szTxtFileName);
                  Sleep(dwMilliseconds: 0xC8u);
                  ShellExecuteA(
                    hwnd: nullptr,
                    lpOperation: nullptr,
                    lpFile: "cmd.exe",
                    lpParameters: chCommand,
                    lpDirectory: nullptr,
                    nShowCmd: 0);
                  Sleep(dwMilliseconds: 0xC8u);
                  _Msg(a1: " '%s' : saved.\n", v15);
                  CP4AutoAddFile::CP4AutoAddFile(this: &v39, szFilename: v15);
                  CPlainAutoPtr<CP4File>::~CPlainAutoPtr<CP4File>(this: &v39);
                  LOBYTE(v43) = 5;
                  CPlainAutoPtr<CP4File>::~CPlainAutoPtr<CP4File>(this: (CP4AutoAddFile *)&v40);
                }
                else
                {
                  _Warning(
                    a1: " '%s' : failed to save - set \"maxwidth %d maxheight %d\" manually.\n",
                    v15,
                    autop4_edit.m_spImpl.m_p,
                    autop4_add.m_spImpl.m_p);
                }
                LOBYTE(v43) = 0;
                CUtlMemory<CUtlVector<CMorph::MorphQuad_t,CUtlMemory<CMorph::MorphQuad_t,int>>,int>::~CUtlMemory<CUtlVector<CMorph::MorphQuad_t,CUtlMemory<CMorph::MorphQuad_t,int>>,int>(this: &v34);
              }
              else
              {
                sprintf(string: v17, format: (const char *)&pMem);
                _Warning(a1: " '%s' : doesn't specify a valid TGA or PSD file!\n", v15);
              }
            }
            goto LABEL_51;
          }
          v14 = (char *)g_pFullFileSystem->RelativePathToFullPath(
                          this: g_pFullFileSystem,
                          a2: chResolveNameArg,
                          a3: "game",
                          a4: chResolveName,
                          a5: 259,
                          a6: 0,
                          a7: 0);
          v15 = v14;
          if ( v14 != nullptr )
          {
            if ( BufferReplace(szFindData: "\\game\\", buf: v14, szNewData: "\\content\\") != nullptr
              && BufferReplace(szFindData: "\\materials\\", buf: v15, szNewData: "\\materialsrc\\") != nullptr )
            {
              goto LABEL_34;
            }
            _Warning(
              a1: " mat_texture_list_txlod_sync save - texture '%s' cannot be mapped to content directory.\n",
              v6);
          }
          else
          {
            _Warning(a1: " mat_texture_list_txlod_sync save - texture '%s' is not loaded from file system.\n", v6);
          }
        }
        else
        {
          _Warning(a1: " mat_texture_list_txlod_sync save - texture '%s' no longer found.\n", v6);
        }
      }
LABEL_51:
      ++k;
    }
    while ( k < TextureLodOverride::s_OverrideMap.m_SymbolTable.m_Lookup.m_NumElements );
  }
  _Msg(a1: "mat_texture_list_txlod_sync save : completed.\n");
  v43 = -1;
  if ( p4req.m_bLoadedModule )
  {
    m_pP4Module = p4req.m_pP4Module;
    if ( p4req.m_pP4Module != nullptr )
    {
      if ( p4 != nullptr )
      {
        p4->Shutdown(this: p4);
        p4->Disconnect(this: p4);
      }
      Sys_UnloadModule(pModule: m_pP4Module);
      p4 = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004EF60
// Name: void TextureLodOverride::Add(char const __near *,struct TextureLodOverride::OverrideInfo)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TextureLodOverride::Add(const char *szName, TextureLodOverride::OverrideInfo oi)
{
  int m_Id; // eax
  int v3; // esi
  CUtlSymbol result; // [esp+4h] [ebp-8h] BYREF
  TextureLodOverride::OverrideInfo oiex; // [esp+8h] [ebp-4h]

  m_Id = CUtlSymbolTable::Find(this: &TextureLodOverride::s_OverrideMap.m_SymbolTable, &result, pString: szName)->m_Id;
  if ( (_WORD)m_Id == 0xFFFF )
    oiex = 0;
  else
    oiex = TextureLodOverride::s_OverrideMap.m_Vector.m_Memory.m_pMemory[m_Id];
  oiex.x += oi.x;
  oiex.y += oi.y;
  CUtlSymbolTable::AddString(this: &TextureLodOverride::s_OverrideMap.m_SymbolTable, &result, pString: szName);
  v3 = result.m_Id;
  if ( TextureLodOverride::s_OverrideMap.m_Vector.m_Size > result.m_Id )
  {
    TextureLodOverride::s_OverrideMap.m_Vector.m_Memory.m_pMemory[result.m_Id] = oiex;
  }
  else if ( TextureLodOverride::s_OverrideMap.m_Vector.m_Size >= result.m_Id + 1 )
  {
    TextureLodOverride::s_OverrideMap.m_Vector.m_Memory.m_pMemory[result.m_Id] = oiex;
  }
  else
  {
    CUtlVector<TextureLodOverride::OverrideInfo,CUtlMemory<TextureLodOverride::OverrideInfo,int>>::InsertMultipleBefore(
      this: &TextureLodOverride::s_OverrideMap.m_Vector,
      elem: TextureLodOverride::s_OverrideMap.m_Vector.m_Size,
      num: result.m_Id + 1 - TextureLodOverride::s_OverrideMap.m_Vector.m_Size);
    TextureLodOverride::s_OverrideMap.m_Vector.m_Memory.m_pMemory[v3] = oiex;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004F010
// Name: void TextureLodExclude::Add(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TextureLodExclude::Add(const char *szName, int iOverride)
{
  int m_Id; // eax
  int v3; // esi
  CUtlSymbol result; // [esp+4h] [ebp-4h] BYREF

  m_Id = CUtlSymbolTable::Find(this: &TextureLodExclude::s_ExcludeMap.m_SymbolTable, &result, pString: szName)->m_Id;
  if ( (_WORD)m_Id == 0xFFFF )
  {
    CUtlSymbolTable::AddString(this: &TextureLodExclude::s_ExcludeMap.m_SymbolTable, &result, pString: szName);
    v3 = result.m_Id;
    if ( TextureLodExclude::s_ExcludeMap.m_Vector.m_Size <= result.m_Id
      && TextureLodExclude::s_ExcludeMap.m_Vector.m_Size < result.m_Id + 1 )
    {
      CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int>>::InsertMultipleBefore(
        this: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)&TextureLodExclude::s_ExcludeMap,
        elem: TextureLodExclude::s_ExcludeMap.m_Vector.m_Size,
        num: result.m_Id + 1 - TextureLodExclude::s_ExcludeMap.m_Vector.m_Size);
    }
    TextureLodExclude::s_ExcludeMap.m_Vector.m_Memory.m_pMemory[v3] = iOverride;
  }
  else
  {
    TextureLodExclude::s_ExcludeMap.m_Vector.m_Memory.m_pMemory[m_Id] = iOverride;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004F090
// Name: public: virtual void CTexture::ForceLODOverride(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTexture::ForceLODOverride(CTexture *this, TextureLodOverride::OverrideInfo iNumLodsOverrideUpOrDown)
{
  const char *v3; // eax

  iNumLodsOverrideUpOrDown.y = iNumLodsOverrideUpOrDown.x;
  v3 = (const char *)this->GetName(this);
  TextureLodOverride::Add(szName: v3, oi: iNumLodsOverrideUpOrDown);
  this->Download(this, a2: nullptr, a3: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1004F0D0
// Name: public: virtual void CTexture::ForceExcludeOverride(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTexture::ForceExcludeOverride(CTexture *this, int iExcludeOverride)
{
  const char *v3; // eax

  v3 = (const char *)this->GetName(this);
  TextureLodExclude::Add(szName: v3, iOverride: iExcludeOverride);
  this->Download(this, a2: nullptr, a3: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1004F100
// Name: mat_texture_list_exclude
// Source: json
//------------------------------------------------------------------------------
void __cdecl mat_texture_list_exclude(const CCommand *args)
{
  const CCommand *v1; // edi
  const char *v2; // esi
  const char *v3; // edi
  bool (__thiscall *ReadFile)(IBaseFileSystem *, const char *, const char *, CUtlBuffer *, int, int, void *(__cdecl *)(const char *, unsigned int)); // eax
  char *i; // esi
  char v6; // al
  int v7; // ebx
  int v8; // edx
  int v9; // eax
  int v10; // esi
  const char *v11; // eax
  ITexture *v12; // eax
  int m_nValue; // eax
  void *m_pMemory; // eax
  int v15; // edi
  const char *v16; // eax
  int v17; // esi
  TextureLodOverride::OverrideInfo *v18; // eax
  int v19; // edi
  const char *v20; // eax
  int v21; // esi
  int *v22; // eax
  int v23; // esi
  const char *v24; // eax
  ITexture *v25; // eax
  bool v26; // zf
  const char *v27; // ebx
  int v28; // edi
  const char *v29; // eax
  int v30; // edi
  const char *v31; // eax
  int v32; // ecx
  CUtlInplaceBuffer bufFile; // [esp+Ch] [ebp-ACh] BYREF
  CUtlStringMap<int> lstReload; // [esp+5Ch] [ebp-5Ch] BYREF
  int v35; // [esp+B4h] [ebp-4h]

  v1 = args;
  if ( args->m_nArgc < 2 )
    goto usage_0;
  v2 = (const char *)&pMem;
  if ( args->m_nArgc > 1 )
    v2 = args->m_ppArgv[1];
  if ( _V_stricmp(s1: v2, s2: "load") == 0 )
  {
    if ( v1->m_nArgc >= 3 )
    {
      if ( v1->m_nArgc > 2 )
        v3 = v1->m_ppArgv[2];
      else
        v3 = (const char *)&pMem;
      _Msg(a1: "mat_texture_list_exclude loading '%s'...\n", v3);
      CUtlInplaceBuffer::CUtlInplaceBuffer(this: (CUtlInplaceBuffer *)&lstReload, growSize: 0, initSize: 0, nFlags: 1);
      ReadFile = g_pFullFileSystem->ReadFile;
      v35 = 0;
      if ( !ReadFile(
              this: &g_pFullFileSystem->IBaseFileSystem,
              a2: v3,
              a3: nullptr,
              a4: (CUtlBuffer *)&lstReload,
              a5: 0,
              a6: 0,
              a7: nullptr) )
      {
        _Warning(a1: "Error: failed to load exclude file '%s'!\n", v3);
        v35 = -1;
        CUtlMemory<CUtlVector<CMorph::MorphQuad_t,CUtlMemory<CMorph::MorphQuad_t,int>>,int>::~CUtlMemory<CUtlVector<CMorph::MorphQuad_t,CUtlMemory<CMorph::MorphQuad_t,int>>,int>(this: (CUtlBuffer *)&lstReload);
        return;
      }
      for ( i = CUtlInplaceBuffer::InplaceGetLinePtr(this: (CUtlInplaceBuffer *)&lstReload);
            i != nullptr;
            i = CUtlInplaceBuffer::InplaceGetLinePtr(this: (CUtlInplaceBuffer *)&lstReload) )
      {
        v6 = *i;
        if ( *i != 0 && (v6 < 9 || v6 > 13 && v6 != 32) && isalnum(c: v6) != 0 )
        {
          v7 = atoi(nptr: i);
          if ( isdigit(c: *i) != 0 )
          {
            do
              v8 = *++i;
            while ( isdigit(c: v8) != 0 );
          }
          while ( 1 )
          {
            v9 = *i;
            if ( v9 < 9 || v9 > 13 && v9 != 32 )
              break;
            ++i;
          }
          if ( isalpha(c: *i) != 0 )
            TextureLodExclude::Add(szName: i, iOverride: v7);
        }
      }
      v10 = 0;
      if ( TextureLodExclude::s_ExcludeMap.m_SymbolTable.m_Lookup.m_NumElements != 0 )
      {
        do
        {
          v11 = CUtlSymbolTable::String(this: &TextureLodExclude::s_ExcludeMap.m_SymbolTable, id: (CUtlSymbol)v10);
          v12 = materials->FindTexture(this: materials, a2: v11, a3: &pMem, a4: 1, a5: 0);
          if ( v12 != nullptr )
            v12->Download(this: v12, a2: nullptr, a3: 0);
          ++v10;
        }
        while ( v10 < TextureLodExclude::s_ExcludeMap.m_SymbolTable.m_Lookup.m_NumElements );
      }
      _Msg(a1: "mat_texture_list_exclude loaded '%s'.\n", v3);
      if ( mat_texture_list_exclude_editing.m_pParent != nullptr )
        m_nValue = mat_texture_list_exclude_editing.m_pParent->m_Value.m_nValue;
      else
        m_nValue = 0;
      ConVar::SetValue(
        this: (ConVar *)&mat_texture_list_exclude_editing.IConVar,
        value: m_nValue < 0 ? 1 : m_nValue + 1);
      v35 = -1;
      if ( lstReload.m_Vector.m_Memory.m_nGrowSize >= 0 )
      {
        m_pMemory = lstReload.m_Vector.m_Memory.m_pMemory;
LABEL_82:
        v26 = m_pMemory == nullptr;
LABEL_83:
        if ( !v26 )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
        return;
      }
      return;
    }
usage_0:
    _Warning(
      a1: "Usage:\n"
      "  mat_texture_list_exclude load excludelistfile.lst - loads exclude list file;\n"
      "  mat_texture_list_exclude reset - resets loaded exclude list information;\n"
      "  mat_texture_list_exclude save excludelistfile.lst - saves exclude list file.\n");
    return;
  }
  if ( _V_stricmp(s1: v2, s2: "reset") == 0 )
  {
    _Msg(a1: "mat_texture_list_exclude reset...\n");
    lstReload.m_Vector.m_Memory.m_nAllocationCount = 0;
    lstReload.m_Vector.m_Memory.m_nGrowSize = 0;
    lstReload.m_Vector.m_Size = 32;
    lstReload.m_Vector.m_pElements = nullptr;
    *(_DWORD *)&lstReload.m_SymbolTable.m_Lookup.m_LessFunc = 0;
    v35 = 1;
    CUtlSymbolTable::CUtlSymbolTable(
      this: (CUtlSymbolTable *)&lstReload.m_SymbolTable.m_Lookup.m_Elements,
      growSize: 0,
      initSize: 32,
      caseInsensitive: true);
    v15 = 0;
    v35 = 2;
    if ( TextureLodOverride::s_OverrideMap.m_SymbolTable.m_Lookup.m_NumElements != 0 )
    {
      do
      {
        v16 = CUtlSymbolTable::String(this: &TextureLodOverride::s_OverrideMap.m_SymbolTable, id: (CUtlSymbol)v15);
        CUtlSymbolTable::AddString(
          this: (CUtlSymbolTable *)&lstReload.m_SymbolTable.m_Lookup.m_Elements,
          result: (CUtlSymbol *)&args,
          pString: v16);
        v17 = (unsigned __int16)args;
        if ( (int)lstReload.m_Vector.m_pElements <= (unsigned __int16)args
          && (int)lstReload.m_Vector.m_pElements < (unsigned __int16)args + 1 )
        {
          CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int>>::InsertMultipleBefore(
            this: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)&lstReload.m_Vector.m_Memory.m_nAllocationCount,
            elem: (int)lstReload.m_Vector.m_pElements,
            num: (unsigned __int16)args + 1 - (unsigned int)lstReload.m_Vector.m_pElements);
        }
        *(_DWORD *)(lstReload.m_Vector.m_Memory.m_nAllocationCount + 4 * v17) = 1;
        ++v15;
      }
      while ( v15 < TextureLodOverride::s_OverrideMap.m_SymbolTable.m_Lookup.m_NumElements );
    }
    v18 = TextureLodOverride::s_OverrideMap.m_Vector.m_Memory.m_pMemory;
    TextureLodOverride::s_OverrideMap.m_Vector.m_Size = 0;
    if ( TextureLodOverride::s_OverrideMap.m_Vector.m_Memory.m_nGrowSize >= 0 )
    {
      if ( TextureLodOverride::s_OverrideMap.m_Vector.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: TextureLodOverride::s_OverrideMap.m_Vector.m_Memory.m_pMemory);
        v18 = nullptr;
        TextureLodOverride::s_OverrideMap.m_Vector.m_Memory.m_pMemory = nullptr;
      }
      TextureLodOverride::s_OverrideMap.m_Vector.m_Memory.m_nAllocationCount = 0;
    }
    TextureLodOverride::s_OverrideMap.m_Vector.m_pElements = v18;
    CUtlSymbolTable::RemoveAll(this: &TextureLodOverride::s_OverrideMap.m_SymbolTable);
    v19 = 0;
    if ( TextureLodExclude::s_ExcludeMap.m_SymbolTable.m_Lookup.m_NumElements != 0 )
    {
      do
      {
        v20 = CUtlSymbolTable::String(this: &TextureLodExclude::s_ExcludeMap.m_SymbolTable, id: (CUtlSymbol)v19);
        CUtlSymbolTable::AddString(
          this: (CUtlSymbolTable *)&lstReload.m_SymbolTable.m_Lookup.m_Elements,
          result: (CUtlSymbol *)&args,
          pString: v20);
        v21 = (unsigned __int16)args;
        if ( (int)lstReload.m_Vector.m_pElements <= (unsigned __int16)args
          && (int)lstReload.m_Vector.m_pElements < (unsigned __int16)args + 1 )
        {
          CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int>>::InsertMultipleBefore(
            this: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)&lstReload.m_Vector.m_Memory.m_nAllocationCount,
            elem: (int)lstReload.m_Vector.m_pElements,
            num: (unsigned __int16)args + 1 - (unsigned int)lstReload.m_Vector.m_pElements);
        }
        *(_DWORD *)(lstReload.m_Vector.m_Memory.m_nAllocationCount + 4 * v21) = 1;
        ++v19;
      }
      while ( v19 < TextureLodExclude::s_ExcludeMap.m_SymbolTable.m_Lookup.m_NumElements );
    }
    v22 = TextureLodExclude::s_ExcludeMap.m_Vector.m_Memory.m_pMemory;
    TextureLodExclude::s_ExcludeMap.m_Vector.m_Size = 0;
    if ( TextureLodExclude::s_ExcludeMap.m_Vector.m_Memory.m_nGrowSize >= 0 )
    {
      if ( TextureLodExclude::s_ExcludeMap.m_Vector.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: TextureLodExclude::s_ExcludeMap.m_Vector.m_Memory.m_pMemory);
        v22 = nullptr;
        TextureLodExclude::s_ExcludeMap.m_Vector.m_Memory.m_pMemory = nullptr;
      }
      TextureLodExclude::s_ExcludeMap.m_Vector.m_Memory.m_nAllocationCount = 0;
    }
    TextureLodExclude::s_ExcludeMap.m_Vector.m_pElements = v22;
    CUtlSymbolTable::RemoveAll(this: &TextureLodExclude::s_ExcludeMap.m_SymbolTable);
    v23 = 0;
    if ( lstReload.m_SymbolTable.m_Lookup.m_LastAlloc.index != 0 )
    {
      do
      {
        v24 = CUtlSymbolTable::String(
                this: (CUtlSymbolTable *)&lstReload.m_SymbolTable.m_Lookup.m_Elements,
                id: (CUtlSymbol)v23);
        v25 = materials->FindTexture(this: materials, a2: v24, a3: &pMem, a4: 1, a5: 0);
        if ( v25 != nullptr )
          v25->Download(this: v25, a2: nullptr, a3: 0);
        ++v23;
      }
      while ( v23 < lstReload.m_SymbolTable.m_Lookup.m_LastAlloc.index );
    }
    _Msg(a1: "mat_texture_list_exclude reset : completed.\n");
    ConVar::SetValue(this: (ConVar *)&mat_texture_list_exclude_editing.IConVar, value: 0);
    v35 = 3;
    CUtlSymbolTable::~CUtlSymbolTable(this: (CUtlSymbolTable *)&lstReload.m_SymbolTable.m_Lookup.m_Elements);
    m_pMemory = (void *)lstReload.m_Vector.m_Memory.m_nAllocationCount;
    v35 = 4;
    lstReload.m_Vector.m_pElements = nullptr;
    if ( lstReload.m_Vector.m_Size >= 0 )
    {
      if ( lstReload.m_Vector.m_Memory.m_nAllocationCount != 0 )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)lstReload.m_Vector.m_Memory.m_nAllocationCount);
        m_pMemory = nullptr;
        lstReload.m_Vector.m_Memory.m_nAllocationCount = 0;
      }
      lstReload.m_Vector.m_Memory.m_nGrowSize = 0;
    }
    *(_DWORD *)&lstReload.m_SymbolTable.m_Lookup.m_LessFunc = m_pMemory;
    v35 = -1;
    if ( lstReload.m_Vector.m_Size >= 0 )
    {
      v26 = m_pMemory == nullptr;
      goto LABEL_83;
    }
    return;
  }
  if ( _V_stricmp(s1: v2, s2: "save") != 0 )
    return;
  if ( v1->m_nArgc < 3 )
    goto usage_0;
  v27 = (const char *)&pMem;
  if ( v1->m_nArgc > 2 )
    v27 = v1->m_ppArgv[2];
  _Msg(a1: "mat_texture_list_exclude saving '%s'...\n", v27);
  CUtlInplaceBuffer::CUtlInplaceBuffer(this: &bufFile, growSize: 0, initSize: 0, nFlags: 1);
  v28 = 0;
  v35 = 5;
  if ( TextureLodExclude::s_ExcludeMap.m_SymbolTable.m_Lookup.m_NumElements != 0 )
  {
    do
    {
      v29 = CUtlSymbolTable::String(this: &TextureLodExclude::s_ExcludeMap.m_SymbolTable, id: (CUtlSymbol)v28);
      if ( TextureLodExclude::s_ExcludeMap.m_Vector.m_Memory.m_pMemory[(unsigned __int16)v28] == 0 )
        CUtlBuffer::Printf(this: &bufFile, pFmt: "%s\n", v29);
      ++v28;
    }
    while ( v28 < TextureLodExclude::s_ExcludeMap.m_SymbolTable.m_Lookup.m_NumElements );
  }
  CUtlBuffer::Printf(this: &bufFile, pFmt: "\n");
  v30 = 0;
  if ( TextureLodExclude::s_ExcludeMap.m_SymbolTable.m_Lookup.m_NumElements != 0 )
  {
    do
    {
      v31 = CUtlSymbolTable::String(this: &TextureLodExclude::s_ExcludeMap.m_SymbolTable, id: (CUtlSymbol)v30);
      v32 = TextureLodExclude::s_ExcludeMap.m_Vector.m_Memory.m_pMemory[(unsigned __int16)v30];
      if ( v32 > 0 )
        CUtlBuffer::Printf(this: &bufFile, pFmt: "%d %s\n", v32, v31);
      ++v30;
    }
    while ( v30 < TextureLodExclude::s_ExcludeMap.m_SymbolTable.m_Lookup.m_NumElements );
  }
  if ( g_pFullFileSystem->WriteFile(this: &g_pFullFileSystem->IBaseFileSystem, a2: v27, a3: nullptr, a4: &bufFile) )
    _Msg(a1: "mat_texture_list_exclude saved '%s'.\n", v27);
  else
    _Warning(a1: "Error: failed to save exclude file '%s'!\n", v27);
  v35 = -1;
  if ( bufFile.m_Memory.m_nGrowSize >= 0 )
  {
    m_pMemory = bufFile.m_Memory.m_pMemory;
    goto LABEL_82;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10055060
// Name: public: virtual int CReferenceToHandleTexture::GetApproximateVidMemBytes(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CReferenceToHandleTexture::GetApproximateVidMemBytes(CReferenceToHandleTexture *this)
{
  return 32;
}

//------------------------------------------------------------------------------
// Address: 0x100FDC70
// Name: public: virtual bool CTexture::IsPreloaded(void)const
// Source: json
//------------------------------------------------------------------------------
const CThreadEvent *__thiscall CTexture::IsPreloaded(_DWORD *this)
{
  return (const CThreadEvent *)((*(this + 6) & 4) != 0);
}

//------------------------------------------------------------------------------
// Address: 0x1028B300
// Name: TextureLodOverride::_dynamic_initializer_for__s_OverrideMap__
// Source: json
//------------------------------------------------------------------------------
int TextureLodOverride::_dynamic_initializer_for__s_OverrideMap__()
{
  CUtlSymbolTable::CUtlSymbolTable(
    this: &TextureLodOverride::s_OverrideMap.m_SymbolTable,
    growSize: 0,
    initSize: 32,
    caseInsensitive: true);
  return atexit(func: TextureLodOverride::_dynamic_atexit_destructor_for__s_OverrideMap__);
}

//------------------------------------------------------------------------------
// Address: 0x1028B350
// Name: TextureLodExclude::_dynamic_initializer_for__s_ExcludeMap__
// Source: json
//------------------------------------------------------------------------------
int TextureLodExclude::_dynamic_initializer_for__s_ExcludeMap__()
{
  CUtlSymbolTable::CUtlSymbolTable(
    this: &TextureLodExclude::s_ExcludeMap.m_SymbolTable,
    growSize: 0,
    initSize: 32,
    caseInsensitive: true);
  return atexit(func: TextureLodExclude::_dynamic_atexit_destructor_for__s_ExcludeMap__);
}

//------------------------------------------------------------------------------
// Address: 0x1028C680
// Name: TextureLodOverride::_dynamic_atexit_destructor_for__s_OverrideMap__
// Source: json
//------------------------------------------------------------------------------
void __cdecl TextureLodOverride::_dynamic_atexit_destructor_for__s_OverrideMap__()
{
  CUtlStringMap<TextureLodOverride::OverrideInfo>::~CUtlStringMap<TextureLodOverride::OverrideInfo>(this: (CUtlStringMap<int> *)&TextureLodOverride::s_OverrideMap);
}

//------------------------------------------------------------------------------
// Address: 0x1028C690
// Name: TextureLodExclude::_dynamic_atexit_destructor_for__s_ExcludeMap__
// Source: json
//------------------------------------------------------------------------------
void __cdecl TextureLodExclude::_dynamic_atexit_destructor_for__s_ExcludeMap__()
{
  CUtlStringMap<TextureLodOverride::OverrideInfo>::~CUtlStringMap<TextureLodOverride::OverrideInfo>(this: &TextureLodExclude::s_ExcludeMap);
}

//------------------------------------------------------------------------------
// Address: 0x1028B3A0
// Name: _dynamic_initializer_for__mat_texture_list_content_path__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_texture_list_content_path__()
{
  ConVar::ConVar(
    this: &mat_texture_list_content_path,
    pName: "mat_texture_list_content_path",
    pDefaultValue: (const char *)&pMem,
    flags: 128,
    pHelpString: "The content path to the materialsrc directory. If left unset, it'll assume your content directory is next to the cur"
    "rently running game dir.");
  return atexit(func: dynamic_atexit_destructor_for__mat_texture_list_content_path__);
}

//------------------------------------------------------------------------------
// Address: 0x1028B3D0
// Name: _dynamic_initializer_for__mat_texture_list_txlod_sync_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_texture_list_txlod_sync_command__()
{
  ConCommand::ConCommand(
    this: &mat_texture_list_txlod_sync_command,
    pName: "mat_texture_list_txlod_sync",
    callback: mat_texture_list_txlod_sync,
    pHelpString: "'reset' - resets all run-time changes to LOD overrides, 'save' - saves all changes to material content files",
    flags: 0x20000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__mat_texture_list_txlod_sync_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1028B400
// Name: _dynamic_initializer_for__mat_texture_list_exclude_editing__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_texture_list_exclude_editing__()
{
  ConVar::ConVar(
    this: &mat_texture_list_exclude_editing,
    pName: "mat_texture_list_exclude_editing",
    pDefaultValue: "0",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_texture_list_exclude_editing__);
}

//------------------------------------------------------------------------------
// Address: 0x1028B430
// Name: _dynamic_initializer_for__mat_texture_list_exclude_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_texture_list_exclude_command__()
{
  ConCommand::ConCommand(
    this: &mat_texture_list_exclude_command,
    pName: "mat_texture_list_exclude",
    callback: mat_texture_list_exclude,
    pHelpString: "'load' - loads the exclude list file, 'reset' - resets all loaded exclude information, 'save' - saves exclude list file",
    flags: 0x20000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__mat_texture_list_exclude_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1028B460
// Name: _dynamic_initializer_for__g_DummyIndices__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_DummyIndices__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_DummyIndices__);
}

//------------------------------------------------------------------------------
// Address: 0x1028B470
// Name: _dynamic_initializer_for__g_DummyMaterialSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_DummyMaterialSystem__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_DummyMaterialSystem__);
}

//------------------------------------------------------------------------------
// Address: 0x1028B480
// Name: _dynamic_initializer_for____g_CreateCDummyMaterialSystemIMaterialSystemStub_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCDummyMaterialSystemIMaterialSystemStub_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCDummyMaterialSystemIMaterialSystemStub_reg,
           fn: (void *(__cdecl *)())_CreateCDummyMaterialSystemIMaterialSystemStub_interface,
           pName: "VMaterialSystemStub001");
}

//------------------------------------------------------------------------------
// Address: 0x1028B4A0
// Name: _dynamic_initializer_for__mat_morphstats__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_morphstats__()
{
  ConVar::ConVar(this: &mat_morphstats, pName: "mat_morphstats", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_morphstats__);
}

//------------------------------------------------------------------------------
// Address: 0x1028B4D0
// Name: _dynamic_initializer_for__s_ActiveMorphHisto__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ActiveMorphHisto__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_ActiveMorphHisto__);
}

//------------------------------------------------------------------------------
// Address: 0x1028B4E0
// Name: _dynamic_initializer_for__s_RenderedQuadHisto__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_RenderedQuadHisto__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_RenderedQuadHisto__);
}

//------------------------------------------------------------------------------
// Address: 0x1028B4F0
// Name: _dynamic_initializer_for__s_RenderedTexelHisto__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_RenderedTexelHisto__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_RenderedTexelHisto__);
}

//------------------------------------------------------------------------------
// Address: 0x1028B500
// Name: _dynamic_initializer_for__mat_reporthwmorphmemory_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_reporthwmorphmemory_command__()
{
  ConCommand::ConCommand(
    this: &mat_reporthwmorphmemory_command,
    pName: "mat_reporthwmorphmemory",
    callback: mat_reporthwmorphmemory,
    pHelpString: "Reports the amount of size in bytes taken up by hardware morph textures.",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__mat_reporthwmorphmemory_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1028B530
// Name: _dynamic_initializer_for__s_OcclusionQueryMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_OcclusionQueryMgr__()
{
  s_OcclusionQueryMgr.m_Mutex.m_ownerID = 0;
  s_OcclusionQueryMgr.m_Mutex.m_depth = 0;
  s_OcclusionQueryMgr.m_nFrameCount = 0;
  return atexit(func: dynamic_atexit_destructor_for__s_OcclusionQueryMgr__);
}

//------------------------------------------------------------------------------
// Address: 0x1028B550
// Name: _dynamic_initializer_for__mat_showenvmapmask__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_showenvmapmask__()
{
  ConVar::ConVar(this: &mat_showenvmapmask, pName: "mat_showenvmapmask", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_showenvmapmask__);
}

//------------------------------------------------------------------------------
// Address: 0x1028B580
// Name: _dynamic_initializer_for__mat_debugdepth__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_debugdepth__()
{
  ConVar::ConVar(this: &mat_debugdepth, pName: "mat_debugdepth", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_debugdepth__);
}

//------------------------------------------------------------------------------
// Address: 0x1028B5B0
// Name: _dynamic_initializer_for__s_ShaderSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ShaderSystem__()
{
  CBufferedLoggingListener::CBufferedLoggingListener(this: &s_ShaderSystem.m_BufferedLoggingListener);
  s_ShaderSystem.m_NonFatalLoggingResponsePolicy.__vftable = (CNonFatalLoggingResponsePolicy_vtbl *)&CNonFatalLoggingResponsePolicy::`vftable';
  s_ShaderSystem.m_bForceUsingGraphicsReturnTrue = false;
  return atexit(func: dynamic_atexit_destructor_for__s_ShaderSystem__);
}

//------------------------------------------------------------------------------
// Address: 0x1028B610
// Name: _dynamic_initializer_for____g_CreateCShaderSystemIShaderSystem_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCShaderSystemIShaderSystem_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCShaderSystemIShaderSystem_reg,
           fn: (void *(__cdecl *)())_CreateCShaderSystemIShaderSystem_interface,
           pName: "ShaderSystem002");
}

//------------------------------------------------------------------------------
// Address: 0x1028B630
// Name: _dynamic_initializer_for__s_TextureManager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_TextureManager__()
{
  CTextureManager::CTextureManager(this: &s_TextureManager);
  return atexit(func: dynamic_atexit_destructor_for__s_TextureManager__);
}

//------------------------------------------------------------------------------
// Address: 0x1028C6A0
// Name: _dynamic_atexit_destructor_for__g_DummyMaterialSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DummyMaterialSystem__()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1028C6B0
// Name: _dynamic_atexit_destructor_for__g_DummyIndices__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DummyIndices__()
{
  unsigned __int16 *m_pMemory; // eax

  m_pMemory = g_DummyIndices.m_Memory.m_pMemory;
  g_DummyIndices.m_Size = 0;
  if ( g_DummyIndices.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_DummyIndices.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_DummyIndices.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      g_DummyIndices.m_Memory.m_pMemory = nullptr;
    }
    g_DummyIndices.m_Memory.m_nAllocationCount = 0;
  }
  g_DummyIndices.m_pElements = m_pMemory;
  if ( g_DummyIndices.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      g_DummyIndices.m_Memory.m_pMemory = nullptr;
    }
    g_DummyIndices.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1028C750
// Name: _dynamic_atexit_destructor_for__mat_morphstats__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_morphstats__()
{
  ConVar::~ConVar(this: &mat_morphstats);
}

//------------------------------------------------------------------------------
// Address: 0x1028C760
// Name: _dynamic_atexit_destructor_for__mat_reporthwmorphmemory_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_reporthwmorphmemory_command__()
{
  ConCommand::~ConCommand(this: &mat_reporthwmorphmemory_command);
}
