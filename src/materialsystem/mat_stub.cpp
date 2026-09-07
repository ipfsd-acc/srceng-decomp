// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/mat_stub.cpp
// Functions: 102
// ============================================================

#include "materialsystem\mat_stub.h"

//------------------------------------------------------------------------------
// Address: 0x1001B6B0
// Name: public: virtual CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>::~CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>::~CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>(
        CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > *this)
{
  this->CFunctor::IRefCounted::__vftable = (CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >_vtbl *)&CFunctor::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1001B970
// Name: public: virtual int CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>::AddRef(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>::AddRef(
        CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > *this)
{
  return ++this->m_iRefs;
}

//------------------------------------------------------------------------------
// Address: 0x1001B980
// Name: public: virtual int CRefCounted1<class CFunctor,class CRefCountServiceDestruct<class CRefST>>::Release(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST>>::Release(
        CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > *this)
{
  CRefCountServiceDestruct<CRefST> *v1; // ecx
  bool v2; // zf
  int result; // eax

  v1 = &this->CRefCountServiceDestruct<CRefST>;
  v2 = v1->m_iRefs-- == 1;
  result = v1->m_iRefs;
  if ( v2 )
  {
    ((void (__thiscall *)(CRefCountServiceDestruct<CRefST> *, _DWORD))v1->dtr_CRefCountServiceDestruct<CRefST>)(
      a1: v1,
      a2: 0);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001E1A0
// Name: public: virtual int CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>::AddRef(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>::AddRef(
        CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > *this)
{
  return _InterlockedIncrement(&this->m_iRefs);
}

//------------------------------------------------------------------------------
// Address: 0x1001E1B0
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
// Address: 0x10025C30
// Name: public: virtual int CRefCounted1<class IMatRenderContextInternal,class CRefCountServiceBase<1,class CRefMT>>::Release(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT>>::Release(
        CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> > *this)
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
// Address: 0x1002B5D0
// Name: public: virtual int CRefCounted1<class IRefCounted,class CRefCountServiceBase<1,class CRefMT>>::AddRef(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRefCounted1<IRefCounted,CRefCountServiceBase<1,CRefMT>>::AddRef(
        CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> > *this)
{
  return _InterlockedIncrement(&this->m_iRefs);
}

//------------------------------------------------------------------------------
// Address: 0x1003BB10
// Name: public: virtual void CDummyMaterialSystem::EndBatch(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDummyMaterialSystem::EndBatch()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1003BB40
// Name: public: virtual void CDummyMaterial::GetLowResColorSample(float,float,float __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDummyMaterial::GetLowResColorSample(
        SFTextObjectImpl *this,
        unsigned int startPos,
        unsigned int startPosa,
        unsigned int length)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1003BBB0
// Name: public: virtual class IIndexBuffer __near * CDummyMaterialSystem::CreateStaticIndexBuffer(enum MaterialIndexFormat_t,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
IIndexBuffer *__thiscall CDummyMaterialSystem::CreateStaticIndexBuffer(
        CMatNullRenderContext *this,
        MaterialIndexFormat_t fmt,
        MaterialIndexFormat_t nIndexCount,
        const char *pBudgetGroup)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1004F940
// Name: void __near * DummyMaterialSystemFactory(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
CDummyHardwareConfig *__cdecl DummyMaterialSystemFactory(const char *pName)
{
  return _V_stricmp(s1: pName, s2: "MaterialSystemHardwareConfig013") == 0 ? &g_DummyHardwareConfig : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1004F980
// Name: public: virtual char const __near * CDummyTexture::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDummyTexture::GetName(CDummyTexture *this)
{
  return "DummyTexture";
}

//------------------------------------------------------------------------------
// Address: 0x1004F9A0
// Name: public: virtual int CDummyMaterial::GetNumPasses(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDummyMaterial::GetNumPasses(
        CMemberFunctor0<CMaterialVar *,void (__thiscall CMaterialVar::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1004F9B0
// Name: public: virtual char const __near * CDummyMaterialVar::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDummyMaterialVar::GetName(CDummyMaterialVar *this)
{
  return "DummyMaterialVar";
}

//------------------------------------------------------------------------------
// Address: 0x1004F9C0
// Name: public: virtual void CDummyMaterialVar::GetLinearVecValue(float __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDummyMaterialVar::GetLinearVecValue(CDummyMaterialVar *this, float *val, int numcomps)
{
  if ( numcomps > 0 )
    memset32(val, 1065353216, numcomps);
}

//------------------------------------------------------------------------------
// Address: 0x1004F9E0
// Name: public: virtual float const __near * CDummyMaterialVar::GetVecValueInternal(void)const
// Source: json
//------------------------------------------------------------------------------
float *__thiscall CDummyMaterialVar::GetVecValueInternal(CDummyMaterialVar *this)
{
  return `CDummyMaterialVar::GetVecValueInternal'::`2'::val;
}

//------------------------------------------------------------------------------
// Address: 0x1004F9F0
// Name: public: virtual class ITexture __near * CDummyMaterialVar::GetTextureValue(void)
// Source: json
//------------------------------------------------------------------------------
CDummyTexture *__thiscall CDummyMaterialVar::GetTextureValue(CDummyMaterialSystem *this)
{
  return &g_DummyTexture;
}

//------------------------------------------------------------------------------
// Address: 0x1004FA00
// Name: public: virtual CDummyMaterialVar::operator class ITexture __near *(void)
// Source: json
//------------------------------------------------------------------------------
ITexture *__thiscall CDummyMaterialVar::operator ITexture *(CMaterialVar *this)
{
  return this->GetTextureValue(this);
}

//------------------------------------------------------------------------------
// Address: 0x1004FA10
// Name: public: virtual class IMaterial __near * CDummyMaterialVar::GetOwningMaterial(void)
// Source: json
//------------------------------------------------------------------------------
IMaterial *__thiscall CDummyMaterialVar::GetOwningMaterial(CDummyMaterialVar *this)
{
  return g_pDummyMaterial;
}

//------------------------------------------------------------------------------
// Address: 0x1004FA20
// Name: public: virtual class VMatrix const __near & CDummyMaterialVar::GetMatrixValue(void)
// Source: json
//------------------------------------------------------------------------------
const VMatrix *__thiscall CDummyMaterialVar::GetMatrixValue(CDummyMaterialVar *this)
{
  return &g_DummyMatrix;
}

//------------------------------------------------------------------------------
// Address: 0x1004FA30
// Name: public: virtual bool CDummyTexture::IsVolumeTexture(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDummyTexture::IsVolumeTexture(CVTFTexture *this)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x1004FA50
// Name: public: virtual float CDummyHardwareConfig::GetShadowSlopeScaleDepthBias(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CDummyHardwareConfig::GetShadowSlopeScaleDepthBias(CMatRenderContext *this)
{
  return 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x1004FA60
// Name: public: virtual enum ImageFormat CDummyHardwareConfig::GetShadowDepthTextureFormat(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDummyHardwareConfig::GetShadowDepthTextureFormat(CDummyHardwareConfig *this)
{
  return 47;
}

//------------------------------------------------------------------------------
// Address: 0x1004FA70
// Name: public: virtual int CDummyHardwareConfig::GetMinDXSupportLevel(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDummyHardwareConfig::GetMinDXSupportLevel(CDummyHardwareConfig *this)
{
  return 90;
}

//------------------------------------------------------------------------------
// Address: 0x1004FA80
// Name: public: virtual char const __near * CDummyMaterial::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDummyMaterial::GetName(CDummyMaterial *this)
{
  return "dummy material";
}

//------------------------------------------------------------------------------
// Address: 0x1004FA90
// Name: public: virtual char const __near * CDummyMaterial::GetTextureGroupName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDummyMaterial::GetTextureGroupName(CDummyMaterial *this)
{
  return "dummy group";
}

//------------------------------------------------------------------------------
// Address: 0x1004FAA0
// Name: public: virtual enum PreviewImageRetVal_t CDummyMaterial::GetPreviewImageProperties(int __near *,int __near *,enum ImageFormat __near *,bool __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDummyMaterial::GetPreviewImageProperties(
        CDummyMaterial *this,
        int *width,
        int *height,
        ImageFormat *imageFormat,
        bool *isTranslucent)
{
  if ( width != nullptr )
    *width = 4;
  if ( height != nullptr )
    *height = 4;
  if ( imageFormat != nullptr )
    *imageFormat = IMAGE_FORMAT_RGBA8888;
  if ( isTranslucent != nullptr )
    *isTranslucent = false;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1004FAE0
// Name: public: virtual enum PreviewImageRetVal_t CDummyMaterial::GetPreviewImage(unsigned char __near *,int,int,enum ImageFormat)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDummyMaterial::GetPreviewImage(
        CDummyMaterial *this,
        unsigned __int8 *data,
        unsigned __int8 *width,
        int height,
        int imageFormat)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1004FAF0
// Name: public: virtual void CDummyMaterial::GetMaterialOffset(float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDummyMaterial::GetMaterialOffset(CMaterial *this, float *pOffset)
{
  *pOffset = 0.0;
  pOffset[1] = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x1004FB30
// Name: public: virtual class IMaterialVar __near * CDummyMaterial::FindVar(char const __near *,bool __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CDummyMaterialVar *__thiscall CDummyMaterial::FindVar(
        CDummyMaterial *this,
        const char *varName,
        bool *found,
        bool complain)
{
  if ( found != nullptr )
    *found = true;
  return &g_DummyMaterialVar;
}

//------------------------------------------------------------------------------
// Address: 0x1004FB50
// Name: public: virtual unsigned __int64 CDummyMaterial::GetVertexFormat(void)const
// Source: json
//------------------------------------------------------------------------------
__int64 __thiscall CDummyMaterial::GetVertexFormat(MaterialSystem_Config_t *this)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1004FB60
// Name: public: virtual float CDummyHardwareConfig::GetLightMapScaleFactor(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CDummyHardwareConfig::GetLightMapScaleFactor(CDummyMaterial *this)
{
  return 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x1004FB70
// Name: public: virtual void CDummyMaterial::GetColorModulation(float __near *,float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDummyMaterial::GetColorModulation(CDummyMaterial *this, float *r, float *g, float *b)
{
  *b = 1.0;
  *g = 1.0;
  *r = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x1004FBA0
// Name: public: virtual void CDummyMaterial::GetReflectivity(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDummyMaterial::GetReflectivity(CDummyMaterial *this, Vector *reflect)
{
  reflect->x = 1.0;
  reflect->y = 0.0;
  reflect->z = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x1004FBD0
// Name: public: virtual int CDummyMaterial::GetTextureMemoryBytes(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDummyMaterial::GetTextureMemoryBytes(CDummyMaterial *this)
{
  return 64;
}

//------------------------------------------------------------------------------
// Address: 0x1004FBE0
// Name: public: virtual char const __near * CDummyMaterial::GetShaderName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDummyMaterial::GetShaderName(CDummyMaterial *this)
{
  return "Wireframe";
}

//------------------------------------------------------------------------------
// Address: 0x1004FBF0
// Name: public: virtual void CDummyMesh::LockMesh(int,int,struct MeshDesc_t __near &,struct MeshBuffersAllocationSettings_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDummyMesh::LockMesh(
        CDummyMesh *this,
        int nVertexCount,
        int nIndexCount,
        MeshDesc_t *desc,
        MeshBuffersAllocationSettings_t *pSettings)
{
  IndexDesc_t *v6; // eax

  this->Lock(this, a2: nVertexCount, a3: false, a4: desc);
  if ( desc != nullptr )
    v6 = &desc->IndexDesc_t;
  else
    v6 = nullptr;
  this->Lock(this: &this->IIndexBuffer, a2: nIndexCount, a3: false, a4: v6);
}

//------------------------------------------------------------------------------
// Address: 0x1004FC30
// Name: public: virtual void CDummyMesh::ModifyBeginEx(bool,int,int,int,int,struct MeshDesc_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDummyMesh::ModifyBeginEx(
        CDummyMesh *this,
        BOOL bReadOnly,
        int nFirstVertex,
        int nVertexCount,
        int nFirstIndex,
        int nIndexCount,
        MeshDesc_t *desc)
{
  IndexDesc_t *v7; // eax

  if ( desc != nullptr )
    v7 = &desc->IndexDesc_t;
  else
    v7 = nullptr;
  this->ModifyBegin(this: &this->IIndexBuffer, a2: bReadOnly, a3: nFirstIndex, a4: nIndexCount, a5: v7);
}

//------------------------------------------------------------------------------
// Address: 0x1004FC60
// Name: public: virtual void CDummyMesh::ModifyBegin(int,int,int,int,struct MeshDesc_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDummyMesh::ModifyBegin(
        CDummyMesh *this,
        int nFirstVertex,
        int nVertexCount,
        int nFirstIndex,
        int nIndexCount,
        MeshDesc_t *desc)
{
  IndexDesc_t *v6; // eax

  if ( desc != nullptr )
    v6 = &desc->IndexDesc_t;
  else
    v6 = nullptr;
  this->ModifyBegin(this: &this->IIndexBuffer, a2: false, a3: nFirstIndex, a4: nIndexCount, a5: v6);
}

//------------------------------------------------------------------------------
// Address: 0x1004FC90
// Name: public: virtual bool CDummyMesh::Lock(int,bool,struct IndexDesc_t __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDummyMesh::Lock(CDummyMesh *this, int nMaxIndexCount, bool bAppend, IndexDesc_t *desc)
{
  desc->m_pIndices = &`CDummyMesh::Lock'::`2'::dummyIndex;
  desc->m_nIndexSize = 0;
  desc->m_nFirstIndex = 0;
  desc->m_nOffset = 0;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1004FCB0
// Name: public: virtual void CDummyMesh::ModifyBegin(bool,int,int,struct IndexDesc_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDummyMesh::ModifyBegin(
        CDummyMesh *this,
        bool bReadOnly,
        int nFirstIndex,
        int nIndexCount,
        IndexDesc_t *desc)
{
  desc->m_pIndices = &`CDummyMesh::ModifyBegin'::`2'::dummyIndex;
  desc->m_nIndexSize = 0;
  desc->m_nFirstIndex = 0;
  desc->m_nOffset = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1004FCD0
// Name: public: virtual bool CDummyMesh::Lock(int,bool,struct VertexDesc_t __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDummyMesh::Lock(CDummyMesh *this, int nVertexCount, bool bAppend, VertexDesc_t *desc)
{
  memset(dst: (unsigned __int8 *)desc, value: 0, count: sizeof(VertexDesc_t));
  desc->m_pPosition = `CDummyMesh::Lock'::`2'::dummyFloat;
  desc->m_pBoneWeight = `CDummyMesh::Lock'::`2'::dummyFloat;
  desc->m_pNormal = `CDummyMesh::Lock'::`2'::dummyFloat;
  desc->m_pBoneMatrixIndex = `CDummyMesh::Lock'::`2'::dummyChar;
  desc->m_pColor = `CDummyMesh::Lock'::`2'::dummyChar;
  desc->m_pSpecular = `CDummyMesh::Lock'::`2'::dummyChar;
  desc->m_pTexCoord[0] = `CDummyMesh::Lock'::`2'::dummyFloat;
  desc->m_pTexCoord[1] = `CDummyMesh::Lock'::`2'::dummyFloat;
  desc->m_pTexCoord[2] = `CDummyMesh::Lock'::`2'::dummyFloat;
  desc->m_pTexCoord[3] = `CDummyMesh::Lock'::`2'::dummyFloat;
  desc->m_pTexCoord[4] = `CDummyMesh::Lock'::`2'::dummyFloat;
  desc->m_pTexCoord[5] = `CDummyMesh::Lock'::`2'::dummyFloat;
  desc->m_pTexCoord[6] = `CDummyMesh::Lock'::`2'::dummyFloat;
  desc->m_pTexCoord[7] = `CDummyMesh::Lock'::`2'::dummyFloat;
  desc->m_pTangentS = `CDummyMesh::Lock'::`2'::dummyFloat;
  desc->m_pTangentT = `CDummyMesh::Lock'::`2'::dummyFloat;
  desc->m_pWrinkle = `CDummyMesh::Lock'::`2'::dummyFloat;
  desc->m_pUserData = `CDummyMesh::Lock'::`2'::dummyFloat;
  desc->m_nFirstVertex = 0;
  desc->m_nOffset = 0;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1004FD70
// Name: public: virtual unsigned __int64 CDummyMesh::GetVertexFormat(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int64 __thiscall CDummyMesh::GetVertexFormat(CDummyMesh *this)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1004FD80
// Name: public: virtual class IMesh __near * CDummyMesh::GetMesh(void)
// Source: json
//------------------------------------------------------------------------------
CMatQueuedMesh *__thiscall CDummyMesh::GetMesh(CMatQueuedMesh *this)
{
  return (CMatQueuedMesh *)((char *)this - 4);
}

//------------------------------------------------------------------------------
// Address: 0x1004FDC0
// Name: public: virtual void CDummyMaterialSystem::SetRealMaterialSystem(class IMaterialSystem __near *)
// Source: json
//------------------------------------------------------------------------------
tagWNDCLASSEXA *__thiscall CDummyMaterialSystem::SetRealMaterialSystem(_DWORD *this, tagWNDCLASSEXA *result)
{
  *(this + 2) = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004FDD0
// Name: public: virtual void __near * (*CDummyMaterialSystem::Init(char const __near *,class IMaterialProxyFactory __near *,void __near * (*)(char const __near *,int __near *),void __near * (*)(char const __near *,int __near *)))(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
CDummyHardwareConfig *(__cdecl *__thiscall CDummyMaterialSystem::Init(
        CDummyMaterialSystem *this,
        const char *pShaderDLL,
        IMaterialProxyFactory *pMaterialProxyFactory,
        IMaterialProxyFactory *fileSystemFactory,
        void *(__cdecl *cvarFactory)(const char *, int *)))(const char *pName)
{
  return DummyMaterialSystemFactory;
}

//------------------------------------------------------------------------------
// Address: 0x1004FDE0
// Name: public: virtual class IMaterialSystemHardwareConfig __near * CDummyMaterialSystem::GetHardwareConfig(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
CDummyHardwareConfig *__thiscall CDummyMaterialSystem::GetHardwareConfig(
        CDummyMaterialSystem *this,
        const char *pVersion,
        int *returnCode)
{
  if ( returnCode != nullptr )
    *returnCode = 1;
  return &g_DummyHardwareConfig;
}

//------------------------------------------------------------------------------
// Address: 0x1004FE00
// Name: public: virtual unsigned short CDummyMaterialSystem::InvalidMaterial(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CDummyMaterialSystem::InvalidMaterial(CDummyMaterialSystem *this)
{
  if ( this->m_pRealMaterialSystem != nullptr )
    return this->m_pRealMaterialSystem->InvalidMaterial(this: this->m_pRealMaterialSystem);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1004FE20
// Name: public: virtual class IMaterial __near * CDummyMaterialSystem::GetMaterial(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
CDummyMaterial *__thiscall CDummyMaterialSystem::GetMaterial(CDummyMaterialSystem *this, int h)
{
  if ( this->m_pRealMaterialSystem != nullptr )
    return (CDummyMaterial *)this->m_pRealMaterialSystem->GetMaterial(this: this->m_pRealMaterialSystem, a2: h);
  else
    return &g_DummyMaterial;
}

//------------------------------------------------------------------------------
// Address: 0x1004FE40
// Name: public: virtual class IMaterial __near * CDummyMaterialSystem::FindMaterial(char const __near *,char const __near *,bool,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDummyMaterial *__thiscall CDummyMaterialSystem::FindMaterial(
        CDummyMaterialSystem *this,
        const char *pMaterialName,
        const char *pTextureGroupName,
        BOOL complain,
        const char *pComplainPrefix)
{
  if ( this->m_pRealMaterialSystem != nullptr )
    return (CDummyMaterial *)this->m_pRealMaterialSystem->FindMaterial(
                               this: this->m_pRealMaterialSystem,
                               a2: pMaterialName,
                               a3: pTextureGroupName,
                               a4: complain,
                               a5: pComplainPrefix);
  else
    return &g_DummyMaterial;
}

//------------------------------------------------------------------------------
// Address: 0x1004FE60
// Name: public: virtual class IMaterial __near * CDummyMaterialSystem::FindProceduralMaterial(char const __near *,char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CDummyMaterial *__thiscall CDummyMaterialSystem::FindProceduralMaterial(
        CDummyMaterialSystem *this,
        const char *pMaterialName,
        const char *pTextureGroupName,
        KeyValues *pVMTKeyValues)
{
  if ( this->m_pRealMaterialSystem != nullptr )
    return (CDummyMaterial *)this->m_pRealMaterialSystem->FindProceduralMaterial(
                               this: this->m_pRealMaterialSystem,
                               a2: pMaterialName,
                               a3: pTextureGroupName,
                               a4: pVMTKeyValues);
  else
    return &g_DummyMaterial;
}

//------------------------------------------------------------------------------
// Address: 0x1004FE80
// Name: public: virtual class ITexture __near * CDummyMaterialSystem::FindTexture(char const __near *,char const __near *,bool,int)
// Source: json
//------------------------------------------------------------------------------
CDummyTexture *__thiscall CDummyMaterialSystem::FindTexture(
        CDummyMaterialSystem *this,
        const char *pTextureName,
        const char *pTextureGroupName,
        BOOL complain,
        int nAdditionalCreationFlags)
{
  if ( this->m_pRealMaterialSystem != nullptr )
    return (CDummyTexture *)this->m_pRealMaterialSystem->FindTexture(
                              this: this->m_pRealMaterialSystem,
                              a2: pTextureName,
                              a3: pTextureGroupName,
                              a4: complain,
                              a5: nAdditionalCreationFlags);
  else
    return &g_DummyTexture;
}

//------------------------------------------------------------------------------
// Address: 0x1004FEA0
// Name: public: virtual void CDummyMaterialSystem::GetRenderTargetDimensions(int __near &,int __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDummyMaterialSystem::GetRenderTargetDimensions(CDummyMaterialSystem *this, int *width, int *height)
{
  *width = 256;
  *height = 256;
}

//------------------------------------------------------------------------------
// Address: 0x1004FEC0
// Name: public: virtual int CDummyMaterialSystem::GetNumMaterials(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDummyMaterialSystem::GetNumMaterials(CDummyMaterialSystem *this)
{
  return this->m_pRealMaterialSystem->GetNumMaterials(this: this->m_pRealMaterialSystem);
}

//------------------------------------------------------------------------------
// Address: 0x1004FED0
// Name: public: virtual void CDummyMaterialSystem::UncacheUnusedMaterials(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDummyMaterialSystem::UncacheUnusedMaterials(CDummyMaterialSystem *this, BOOL bRecomputeStateSnapshots)
{
  if ( this->m_pRealMaterialSystem != nullptr )
    this->m_pRealMaterialSystem->UncacheUnusedMaterials(this: this->m_pRealMaterialSystem, a2: bRecomputeStateSnapshots);
}

//------------------------------------------------------------------------------
// Address: 0x1004FEF0
// Name: public: virtual void CDummyMaterialSystem::UncacheAllMaterials(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDummyMaterialSystem::UncacheAllMaterials(CDummyMaterialSystem *this)
{
  if ( this->m_pRealMaterialSystem != nullptr )
    this->m_pRealMaterialSystem->UncacheAllMaterials(this: this->m_pRealMaterialSystem);
}

//------------------------------------------------------------------------------
// Address: 0x1004FF10
// Name: public: virtual void CDummyMaterialSystem::CacheUsedMaterials(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDummyMaterialSystem::CacheUsedMaterials(CDummyMaterialSystem *this)
{
  if ( this->m_pRealMaterialSystem != nullptr )
    this->m_pRealMaterialSystem->CacheUsedMaterials(this: this->m_pRealMaterialSystem);
}

//------------------------------------------------------------------------------
// Address: 0x1004FF30
// Name: public: virtual int CDummyMaterialSystem::AllocateDynamicLightmap(int __near * const,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDummyMaterialSystem::AllocateDynamicLightmap(
        CDummyMaterialSystem *this,
        int *lightmapSize,
        int *pOutOffsetIntoPage,
        int *frameID)
{
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1004FF40
// Name: public: virtual void CDummyMaterialSystem::UpdateLightmap(int,int __near * const,int __near * const,float __near *,float __near *,float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDummyMaterialSystem::UpdateLightmap(
        CMatNullRenderContext *this,
        unsigned __int8 __formal,
        unsigned __int8 __formala,
        unsigned __int8 lightmapSize,
        unsigned __int8 offsetIntoLightmapPage,
        bool pFloatImage,
        bool pFloatImageBump1,
        bool pFloatImageBump2)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1004FF50
// Name: public: virtual int CDummyMaterialSystem::GetNumSortIDs(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDummyMaterialSystem::GetNumSortIDs(GPtr<GFxURLBuilder> *this)
{
  return 10;
}

//------------------------------------------------------------------------------
// Address: 0x1004FF60
// Name: public: virtual class ITexture __near * CDummyMaterialSystem::GetRenderTargetEx(int)
// Source: json
//------------------------------------------------------------------------------
CDummyTexture *__thiscall CDummyMaterialSystem::GetRenderTargetEx(CDummyMaterialSystem *this, int textureIndex)
{
  return &g_DummyTexture;
}

//------------------------------------------------------------------------------
// Address: 0x1004FF70
// Name: public: virtual void CDummyMaterialSystem::GetMatrix(enum MaterialMatrixMode_t,class VMatrix __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDummyMaterialSystem::GetMatrix(
        CDummyMaterialSystem *this,
        MaterialMatrixMode_t matrixMode,
        VMatrix *pMatrix)
{
  MatrixSetIdentity(dst: pMatrix);
}

//------------------------------------------------------------------------------
// Address: 0x1004FF90
// Name: public: virtual void CDummyMaterialSystem::GetMatrix(enum MaterialMatrixMode_t,struct matrix3x4_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDummyMaterialSystem::GetMatrix(
        CDummyMaterialSystem *this,
        MaterialMatrixMode_t matrixMode,
        matrix3x4_t *pMatrix)
{
  SetIdentityMatrix(matrix: pMatrix);
}

//------------------------------------------------------------------------------
// Address: 0x1004FFB0
// Name: public: virtual void CDummyMaterialSystem::Ortho(double,double,double,double,double,double)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDummyMaterialSystem::Ortho(
        CDummyMaterialSystem *this,
        long double left,
        long double top,
        long double right,
        long double bottom,
        long double zNear,
        long double zFar)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1004FFC0
// Name: public: virtual void CDummyMaterialSystem::GetViewport(int __near &,int __near &,int __near &,int __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDummyMaterialSystem::GetViewport(CDummyMaterialSystem *this, int *x, int *y, int *width, int *height)
{
  *y = 0;
  *x = 0;
  *height = 640;
  *width = 640;
}

//------------------------------------------------------------------------------
// Address: 0x1004FFF0
// Name: public: virtual void CDummyMaterialSystem::GetLightmapPageSize(int,int __near *,int __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDummyMaterialSystem::GetLightmapPageSize(
        CDummyMaterialSystem *this,
        int lightmap,
        int *width,
        int *height)
{
  if ( this->m_pRealMaterialSystem != nullptr )
  {
    this->m_pRealMaterialSystem->GetLightmapPageSize(
      this: this->m_pRealMaterialSystem,
      a2: lightmap,
      a3: width,
      a4: height);
  }
  else
  {
    *height = 32;
    *width = 32;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10050020
// Name: public: virtual class ITexture __near * CDummyMaterialSystem::CreateRenderTargetTexture(int,int,enum RenderTargetSizeMode_t,enum ImageFormat,enum MaterialRenderTargetDepth_t)
// Source: json
//------------------------------------------------------------------------------
CDummyTexture *__thiscall CDummyMaterialSystem::CreateRenderTargetTexture(
        CDummyMaterialSystem *this,
        int w,
        int h,
        int sizeMode,
        RenderTargetSizeMode_t format,
        ImageFormat depth)
{
  return &g_DummyTexture;
}

//------------------------------------------------------------------------------
// Address: 0x10050030
// Name: public: virtual class ITexture __near * CDummyMaterialSystem::CreateProceduralTexture(char const __near *,char const __near *,int,int,enum ImageFormat,int)
// Source: json
//------------------------------------------------------------------------------
CDummyTexture *__thiscall CDummyMaterialSystem::CreateProceduralTexture(
        CDummyMaterialSystem *this,
        const char *pTextureName,
        const char *pTextureGroupName,
        const char *w,
        int h,
        int fmt,
        ImageFormat nFlags)
{
  return &g_DummyTexture;
}

//------------------------------------------------------------------------------
// Address: 0x10050040
// Name: public: virtual class IMaterial __near * CDummyMaterialSystem::CreateMaterial(char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CDummyMaterial *__thiscall CDummyMaterialSystem::CreateMaterial(
        CDummyMaterialSystem *this,
        const char *pMaterialName,
        KeyValues *pVMTKeyValues)
{
  return &g_DummyMaterial;
}

//------------------------------------------------------------------------------
// Address: 0x10050050
// Name: public: virtual void CDummyMaterialSystem::GetBackBufferDimensions(int __near &,int __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDummyMaterialSystem::GetBackBufferDimensions(CDummyMaterialSystem *this, int *w, int *h)
{
  *w = 1024;
  *h = 768;
}

//------------------------------------------------------------------------------
// Address: 0x10050070
// Name: public: virtual struct AspectRatioInfo_t const __near & CDummyMaterialSystem::GetAspectRatioInfo(void)const
// Source: json
//------------------------------------------------------------------------------
const AspectRatioInfo_t *__thiscall CDummyMaterialSystem::GetAspectRatioInfo(CDummyMaterialSystem *this)
{
  if ( (`CDummyMaterialSystem::GetAspectRatioInfo'::`2'::`local static guard' & 1) == 0 )
  {
    `CDummyMaterialSystem::GetAspectRatioInfo'::`2'::`local static guard' |= 1u;
    `CDummyMaterialSystem::GetAspectRatioInfo'::`2'::dummy.m_flFrameBufferAspectRatio = 1.3333334;
    `CDummyMaterialSystem::GetAspectRatioInfo'::`2'::dummy.m_flPhysicalAspectRatio = 1.3333334;
    *(_WORD *)&`CDummyMaterialSystem::GetAspectRatioInfo'::`2'::dummy.m_bIsWidescreen = 0;
    `CDummyMaterialSystem::GetAspectRatioInfo'::`2'::dummy.m_flFrameBuffertoPhysicalScalar = 1.0;
    `CDummyMaterialSystem::GetAspectRatioInfo'::`2'::dummy.m_flPhysicalToFrameBufferScalar = 1.0;
    `CDummyMaterialSystem::GetAspectRatioInfo'::`2'::dummy.m_bInitialized = false;
  }
  return &`CDummyMaterialSystem::GetAspectRatioInfo'::`2'::dummy;
}

//------------------------------------------------------------------------------
// Address: 0x100500D0
// Name: public: virtual int CDummyHardwareConfig::MaxTextureHeight(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDummyHardwareConfig::MaxTextureHeight(ConVar *this)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100500E0
// Name: public: virtual class ITexture __near * CDummyMaterialSystem::CreateNamedRenderTargetTexture(char const __near *,int,int,enum RenderTargetSizeMode_t,enum ImageFormat,enum MaterialRenderTargetDepth_t,bool,bool)
// Source: json
//------------------------------------------------------------------------------
CDummyTexture *__thiscall CDummyMaterialSystem::CreateNamedRenderTargetTexture(
        CDummyMaterialSystem *this,
        const char *pRTName,
        const char *w,
        int h,
        int sizeMode,
        RenderTargetSizeMode_t format,
        ImageFormat depth,
        bool bClampTexCoords,
        bool bAutoMipMap)
{
  return &g_DummyTexture;
}

//------------------------------------------------------------------------------
// Address: 0x100500F0
// Name: public: virtual float CDummyMaterialSystem::ComputePixelDiameterOfSphere(class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CDummyMaterialSystem::ComputePixelDiameterOfSphere(
        CDummyMaterialSystem *this,
        const Vector *origin,
        float flRadius)
{
  return 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x10050100
// Name: public: virtual struct MaterialSystem_Config_t const __near & CDummyMaterialSystem::GetCurrentConfigForVideoCard(void)const
// Source: json
//------------------------------------------------------------------------------
const MaterialSystem_Config_t *__thiscall CDummyMaterialSystem::GetCurrentConfigForVideoCard(
        CDummyMaterialSystem *this)
{
  if ( (`CDummyMaterialSystem::GetCurrentConfigForVideoCard'::`2'::`local static guard' & 1) == 0 )
  {
    `CDummyMaterialSystem::GetCurrentConfigForVideoCard'::`2'::`local static guard' |= 1u;
    MaterialSystem_Config_t::MaterialSystem_Config_t(this: &`CDummyMaterialSystem::GetCurrentConfigForVideoCard'::`2'::dummy);
  }
  return &`CDummyMaterialSystem::GetCurrentConfigForVideoCard'::`2'::dummy;
}

//------------------------------------------------------------------------------
// Address: 0x10050130
// Name: public: virtual struct MaterialSystemHardwareIdentifier_t const __near & CDummyMaterialSystem::GetVideoCardIdentifier(void)const
// Source: json
//------------------------------------------------------------------------------
const MaterialSystemHardwareIdentifier_t *__thiscall CDummyMaterialSystem::GetVideoCardIdentifier(
        CDummyMaterialSystem *this)
{
  return &`CDummyMaterialSystem::GetVideoCardIdentifier'::`2'::dummy;
}

//------------------------------------------------------------------------------
// Address: 0x10050150
// Name: public: virtual class ITexture __near * CDummyMaterialSystem::CreateNamedMultiRenderTargetTexture(char const __near *,int,int,enum RenderTargetSizeMode_t,enum ImageFormat,enum MaterialRenderTargetDepth_t,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
ITexture *__thiscall CDummyMaterialSystem::CreateNamedMultiRenderTargetTexture(
        CDummyMaterialSystem *this,
        const char *pRTName,
        const char *w,
        int h,
        int sizeMode,
        RenderTargetSizeMode_t format,
        ImageFormat depth,
        MaterialRenderTargetDepth_t textureFlags,
        unsigned int renderTargetFlags)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10050160
// Name: public: virtual void CDummyMaterialSystem::SetNonInteractiveLogoTexture(class ITexture __near *,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDummyMaterialSystem::SetNonInteractiveLogoTexture(
        CMatNullRenderContext *this,
        int slot,
        int x,
        int y,
        int w,
        int h)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10050170
// Name: public: virtual void CDummyMesh::CopyToMeshBuilder(int,int,int,int,int,class CMeshBuilder __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDummyMesh::CopyToMeshBuilder(
        CMatNullRenderContext *this,
        int __formal,
        int __formala,
        ITexture *pDepthTexture,
        int nViewX,
        unsigned __int8 *nViewY,
        int nViewW)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10050180
// Name: public: virtual void CDummyMaterialSystem::GetShaderFallback(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDummyMaterialSystem::GetShaderFallback(
        CDummyMaterialSystem *this,
        const char *pShaderName,
        char *pFallbackShader,
        int nFallbackLength)
{
  *pFallbackShader = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10050190
// Name: public: virtual void CDummyMaterialSystem::PerspectiveOffCenterX(double,double,double,double,double,double,double,double)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDummyMaterialSystem::PerspectiveOffCenterX(
        CDummyMaterialSystem *this,
        long double fovx,
        long double aspect,
        long double zNear,
        long double zFar,
        long double bottom,
        long double top,
        long double left,
        long double right)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x100501A0
// Name: public: virtual class Vector CDummyMaterialSystem::GetToneMappingScaleLinear(void)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CDummyMaterialSystem::GetToneMappingScaleLinear(CDummyMaterialSystem *this, Vector *result)
{
  result->x = 1.0;
  result->y = 1.0;
  result->z = 1.0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100501C0
// Name: public: virtual void CDummyMaterialSystem::GetMaxToRender(class IMesh __near *,bool,int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDummyMaterialSystem::GetMaxToRender(
        CDummyMaterialSystem *this,
        IMesh *pMesh,
        bool bMaxUntilFlush,
        int *pMaxVerts,
        int *pMaxIndices)
{
  *pMaxVerts = 0x8000;
  *pMaxIndices = 0x8000;
}

//------------------------------------------------------------------------------
// Address: 0x100501E0
// Name: public: virtual int CDummyMaterialSystem::GetMaxVerticesToRender(class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDummyMaterialSystem::GetMaxVerticesToRender(CDummyMaterialSystem *this, IMaterial *pMaterial)
{
  return 0x8000;
}

//------------------------------------------------------------------------------
// Address: 0x100501F0
// Name: public: virtual bool CDummyMaterialSystem::RemoveLookup(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDummyMaterialSystem::RemoveLookup(CMatNullRenderContext *this, unsigned int handle)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10050200
// Name: public: virtual class IMatRenderContext __near * CDummyMaterialSystem::GetRenderContext(void)
// Source: json
//------------------------------------------------------------------------------
CRefCounted1<IMatRenderContext,CRefCountServiceNull> *__thiscall CDummyMaterialSystem::GetRenderContext(
        CDummyMaterialSystem *this)
{
  if ( this != nullptr )
    return &this->CRefCounted1<IMatRenderContext,CRefCountServiceNull>;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10050210
// Name: public: virtual void CDummyHardwareConfig::SetHDREnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDummyHardwareConfig::SetHDREnabled(CEmptyConVar *this, CMeshReader *nValue)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10050220
// Name: public: virtual void CDummyMaterialSystem::GetWorldSpaceCameraPosition(class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDummyMaterialSystem::GetWorldSpaceCameraPosition(CDummyMaterialSystem *this, Vector *pCameraPos)
{
  pCameraPos->x = 0.0;
  pCameraPos->y = 0.0;
  pCameraPos->z = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10050240
// Name: public: virtual void CDummyMaterialSystem::GetWorldSpaceCameraVectors(class Vector __near *,class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDummyMaterialSystem::GetWorldSpaceCameraVectors(
        CDummyMaterialSystem *this,
        Vector *pVecForward,
        Vector *pVecRight,
        Vector *pVecUp)
{
  if ( pVecForward != nullptr )
  {
    pVecForward->x = 1.0;
    pVecForward->y = 0.0;
    pVecForward->z = 0.0;
  }
  if ( pVecRight != nullptr )
  {
    pVecRight->x = 0.0;
    pVecRight->y = -1.0;
    pVecRight->z = 0.0;
  }
  if ( pVecUp != nullptr )
  {
    pVecUp->x = 0.0;
    pVecUp->y = 0.0;
    pVecUp->z = 1.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100502A0
// Name: public: virtual class IMatRenderContext __near * CDummyMaterialSystem::CreateRenderContext(enum MaterialContextType_t)
// Source: json
//------------------------------------------------------------------------------
CRefCounted1<IMatRenderContext,CRefCountServiceNull> *__thiscall CDummyMaterialSystem::CreateRenderContext(
        CDummyMaterialSystem *this,
        MaterialContextType_t type)
{
  CRefCounted1<IMatRenderContext,CRefCountServiceNull> *v3; // ecx

  if ( this != nullptr )
    v3 = &this->CRefCounted1<IMatRenderContext,CRefCountServiceNull>;
  else
    v3 = nullptr;
  v3->AddRef(this: v3);
  if ( this != nullptr )
    return &this->CRefCounted1<IMatRenderContext,CRefCountServiceNull>;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100502D0
// Name: public: virtual int CDummyMaterialSystem::AllocateLightmap(int,int,int __near * const,class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
GTexture *__thiscall CDummyMaterialSystem::AllocateLightmap(
        ScaleformRenderer *this,
        const GRect<float> *frameRect,
        const GRect<float> *targetW,
        unsigned int targetH,
        bool wantStencil)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10050300
// Name: public: virtual void CDummyMaterialSystem::PickMatrix(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDummyMaterialSystem::PickMatrix(
        ScaleformRenderer *this,
        GTexture *psrcin,
        GTexture *insrcrect,
        const GRect<float> *destrect,
        const GRect<float> *matrix)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10050340
// Name: public: virtual class IMatRenderContext __near * CDummyMaterialSystem::SetRenderContext(class IMatRenderContext __near *)
// Source: json
//------------------------------------------------------------------------------
CRefCounted1<IMatRenderContext,CRefCountServiceNull> *__thiscall CDummyMaterialSystem::SetRenderContext(
        CDummyMaterialSystem *this,
        IMatRenderContext *pContext)
{
  if ( pContext != nullptr )
    pContext->Release(this: pContext);
  this->AddRef(this: &this->CRefCounted1<IMatRenderContext,CRefCountServiceNull>);
  return &this->CRefCounted1<IMatRenderContext,CRefCountServiceNull>;
}

//------------------------------------------------------------------------------
// Address: 0x10050370
// Name: public: virtual class IMorph __near * CDummyMaterialSystem::CreateMorph(unsigned int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDummyMorph *__thiscall CDummyMaterialSystem::CreateMorph(
        CDummyMaterialSystem *this,
        unsigned int __formal,
        const char *pDebugName)
{
  if ( (`CDummyMaterialSystem::CreateMorph'::`2'::`local static guard' & 1) == 0 )
  {
    `CDummyMaterialSystem::CreateMorph'::`2'::`local static guard' |= 1u;
    `CDummyMaterialSystem::CreateMorph'::`2'::s_DummyMorph.__vftable = (CDummyMorph_vtbl *)&CDummyMorph::`vftable';
  }
  return &`CDummyMaterialSystem::CreateMorph'::`2'::s_DummyMorph;
}

//------------------------------------------------------------------------------
// Address: 0x100503A0
// Name: public: virtual void CDummyMaterialSystem::GetWindowSize(int __near &,int __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDummyMaterialSystem::GetWindowSize(CDummyMaterialSystem *this, int *width, int *height)
{
  CRefCounted1<IMatRenderContext,CRefCountServiceNull>_vtbl *v3; // ecx
  int v4; // esi

  *height = 0;
  *width = 0;
  v3 = this->CRefCounted1<IMatRenderContext,CRefCountServiceNull>::IMatRenderContext::IRefCounted::__vftable;
  if ( v3 != nullptr )
  {
    v4 = (*((int (__thiscall **)(CRefCounted1<IMatRenderContext,CRefCountServiceNull>_vtbl *))v3->AddRef + 111))(a1: v3);
    if ( v4 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 8))(a1: v4);
    (*(void (__thiscall **)(int, int *, int *))(*(_DWORD *)v4 + 416))(a1: v4, a2: width, a3: height);
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 12))(a1: v4);
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 4))(a1: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10050460
// Name: public: virtual class IMesh __near * CDummyMaterialSystem::CreateStaticMesh(unsigned __int64,char const __near *,class IMaterial __near *,struct VertexStreamSpec_t __near *)
// Source: json
//------------------------------------------------------------------------------
CDummyMesh *__thiscall CDummyMaterialSystem::CreateStaticMesh(
        CDummyMaterialSystem *this,
        unsigned __int64 fmt,
        const char *pTextureBudgetGroup,
        IMaterial *pMaterial,
        VertexStreamSpec_t *pStreamSpec)
{
  CDummyMesh *result; // eax

  result = g_pDummyMesh;
  if ( g_pDummyMesh == nullptr )
  {
    result = (CDummyMesh *)MemAlloc_Alloc(nSize: 8u);
    if ( result != nullptr )
    {
      result->IMesh::IIndexBuffer::__vftable = (IIndexBuffer_vtbl *)&IIndexBuffer::`vftable';
      result->IMesh::IVertexBuffer::__vftable = (CDummyMesh_vtbl *)&CDummyMesh::`vftable'{for `IVertexBuffer'};
      result->IMesh::IIndexBuffer::__vftable = (IIndexBuffer_vtbl *)&CDummyMesh::`vftable'{for `IIndexBuffer'};
      g_pDummyMesh = result;
    }
    else
    {
      g_pDummyMesh = nullptr;
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100504A0
// Name: public: virtual class IMesh __near * CDummyMaterialSystem::GetDynamicMesh(bool,class IMesh __near *,class IMesh __near *,class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
CDummyMesh *__thiscall CDummyMaterialSystem::GetDynamicMesh(
        CDummyMaterialSystem *this,
        bool bBuffered,
        IMesh *pVertexOverride,
        IMesh *pIndexOverride,
        IMesh *pAutoBind)
{
  CDummyMesh *result; // eax

  result = g_pDummyMesh;
  if ( g_pDummyMesh == nullptr )
  {
    result = (CDummyMesh *)MemAlloc_Alloc(nSize: 8u);
    if ( result != nullptr )
    {
      result->IMesh::IIndexBuffer::__vftable = (IIndexBuffer_vtbl *)&IIndexBuffer::`vftable';
      result->IMesh::IVertexBuffer::__vftable = (CDummyMesh_vtbl *)&CDummyMesh::`vftable'{for `IVertexBuffer'};
      result->IMesh::IIndexBuffer::__vftable = (IIndexBuffer_vtbl *)&CDummyMesh::`vftable'{for `IIndexBuffer'};
      g_pDummyMesh = result;
    }
    else
    {
      g_pDummyMesh = nullptr;
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100504E0
// Name: public: virtual class IMesh __near * CDummyMaterialSystem::GetDynamicMeshEx(unsigned __int64,bool,class IMesh __near *,class IMesh __near *,class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
CDummyMesh *__thiscall CDummyMaterialSystem::GetDynamicMeshEx(
        CDummyMaterialSystem *this,
        unsigned __int64 vertexFormat,
        bool bBuffered,
        IMesh *pVertexOverride,
        IMesh *pIndexOverride,
        IMesh *pAutoBind)
{
  CDummyMesh *result; // eax

  result = g_pDummyMesh;
  if ( g_pDummyMesh == nullptr )
  {
    result = (CDummyMesh *)MemAlloc_Alloc(nSize: 8u);
    if ( result != nullptr )
    {
      result->IMesh::IIndexBuffer::__vftable = (IIndexBuffer_vtbl *)&IIndexBuffer::`vftable';
      result->IMesh::IVertexBuffer::__vftable = (CDummyMesh_vtbl *)&CDummyMesh::`vftable'{for `IVertexBuffer'};
      result->IMesh::IIndexBuffer::__vftable = (IIndexBuffer_vtbl *)&CDummyMesh::`vftable'{for `IIndexBuffer'};
      g_pDummyMesh = result;
    }
    else
    {
      g_pDummyMesh = nullptr;
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10050520
// Name: public: virtual class IMesh __near * CDummyMaterialSystem::GetFlexMesh(void)
// Source: json
//------------------------------------------------------------------------------
CDummyMesh *__thiscall CDummyMaterialSystem::GetFlexMesh(CDummyMaterialSystem *this)
{
  CDummyMesh *result; // eax

  result = g_pDummyMesh;
  if ( g_pDummyMesh == nullptr )
  {
    result = (CDummyMesh *)MemAlloc_Alloc(nSize: 8u);
    if ( result != nullptr )
    {
      result->IMesh::IIndexBuffer::__vftable = (IIndexBuffer_vtbl *)&IIndexBuffer::`vftable';
      result->IMesh::IVertexBuffer::__vftable = (CDummyMesh_vtbl *)&CDummyMesh::`vftable'{for `IVertexBuffer'};
      result->IMesh::IIndexBuffer::__vftable = (IIndexBuffer_vtbl *)&CDummyMesh::`vftable'{for `IIndexBuffer'};
      g_pDummyMesh = result;
    }
    else
    {
      g_pDummyMesh = nullptr;
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10072770
// Name: public: virtual bool CDummyMaterialSystem::UpdateConfig(bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDummyMaterialSystem::UpdateConfig(CUtlBuffer *this, GSize<float> *nSize)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x100EC7A0
// Name: public: virtual char const __near * CDummyMaterialSystem::ShaderFlagName(int)const
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<void (__cdecl*)(int),CUtlMemory<void (__cdecl*)(int),int> > *__thiscall CDummyMaterialSystem::ShaderFlagName(
        CDummyMaterialSystem *this,
        int nIndex)
{
  return &pMem;
}

//------------------------------------------------------------------------------
// Address: 0x1004F970
// Name: __CreateCDummyMaterialSystemIMaterialSystemStub_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDummyMaterialSystem *__cdecl _CreateCDummyMaterialSystemIMaterialSystemStub_interface()
{
  return &g_DummyMaterialSystem;
}
