// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/grenderer/grenderer.cpp
// Functions: 14
// ============================================================

#include "thirdparty\scaleform\sdk\src\grenderer\grenderer.h"

//------------------------------------------------------------------------------
// Address: 0x100633A0
// Name: public: void GRenderer::Cxform::Concatenate(class GRenderer::Cxform const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GRenderer::Cxform::Concatenate(GRenderer::Cxform *this, const struct GRenderer::Cxform *a2)
{
  this->M_[0][1] = a2->M_[0][1] * this->M_[0][0] + this->M_[0][1];
  this->M_[1][1] = a2->M_[1][1] * this->M_[1][0] + this->M_[1][1];
  this->M_[2][1] = a2->M_[2][1] * this->M_[2][0] + this->M_[2][1];
  this->M_[3][1] = a2->M_[3][1] * this->M_[3][0] + this->M_[3][1];
  this->M_[0][0] = a2->M_[0][0] * this->M_[0][0];
  this->M_[1][0] = a2->M_[1][0] * this->M_[1][0];
  this->M_[2][0] = a2->M_[2][0] * this->M_[2][0];
  this->M_[3][0] = a2->M_[3][0] * this->M_[3][0];
}

//------------------------------------------------------------------------------
// Address: 0x10063400
// Name: public: void GRenderer::Cxform::SetIdentity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GRenderer::Cxform::SetIdentity(float *this)
{
  *this = 1.0;
  *(this + 2) = 1.0;
  *(this + 4) = 1.0;
  *(this + 6) = 1.0;
  *(this + 1) = 0.0;
  *(this + 3) = 0.0;
  *(this + 5) = 0.0;
  *(this + 7) = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10063420
// Name: public: bool GRenderer::Cxform::IsIdentity(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall GRenderer::Cxform::IsIdentity(GRenderer::Cxform *this)
{
  return 1.0 == this->M_[0][0]
      && 1.0 == this->M_[1][0]
      && 1.0 == this->M_[2][0]
      && this->M_[3][0] == 1.0
      && 0.0 == this->M_[0][1]
      && 0.0 == this->M_[1][1]
      && 0.0 == this->M_[2][1]
      && this->M_[3][1] == 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x100634A0
// Name: public: static void GRenderer::ResizeImage(unsigned char __near *,int,int,int,unsigned char const __near *,int,int,int,enum GRenderer::ResizeImageType)
// Source: json
//------------------------------------------------------------------------------
static void __stdcall GRenderer::ResizeImage(
        unsigned __int8 *a1,
        int a2,
        int a3,
        int a4,
        const unsigned __int8 *a5,
        int a6,
        int a7,
        int a8,
        enum GRenderer::ResizeImageType a9)
{
  switch ( a9 )
  {
    case ResizeRgbToRgb:
      GResizeImageBilinear(a1, a2, a3, a4, a5, a6, a7, a8, a9: 0);
      break;
    case ResizeRgbaToRgba:
      GResizeImageBilinear(a1, a2, a3, a4, a5, a6, a7, a8, a9: 1);
      break;
    case ResizeRgbToRgba:
      GResizeImageBilinear(a1, a2, a3, a4, a5, a6, a7, a8, a9: 2);
      break;
    case ResizeGray:
      GResizeImageBilinear(a1, a2, a3, a4, a5, a6, a7, a8, a9: 3);
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10063550
// Name: public: GRenderer::Cxform::Cxform(void)
// Source: json
//------------------------------------------------------------------------------
float *__thiscall GRenderer::Cxform::Cxform(float *this)
{
  *this = 1.0;
  *(this + 2) = 1.0;
  *(this + 4) = 1.0;
  *(this + 6) = 1.0;
  *(this + 1) = 0.0;
  *(this + 3) = 0.0;
  *(this + 5) = 0.0;
  *(this + 7) = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10063570
// Name: public: virtual bool GRenderer::AddEventHandler(class GRendererEventHandler __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GRenderer::AddEventHandler(IShaderUtil *this, const IShaderUtil *phandler)
{
  if ( phandler[2].__vftable == nullptr && phandler[1].__vftable == nullptr )
  {
    phandler[1].__vftable = (IShaderUtil_vtbl *)*(this + 2);
    phandler[2].__vftable = (IShaderUtil_vtbl *)(this + 1);
    *(_DWORD *)(*((_DWORD *)this + 2) + 8) = phandler;
    *((_DWORD *)this + 2) = phandler;
    phandler[3].__vftable = (IShaderUtil_vtbl *)this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100635B0
// Name: public: virtual void GRenderer::RemoveEventHandler(class GRendererEventHandler __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GRenderer::RemoveEventHandler(IShaderUtil *this, void (__cdecl *phandler)(const char *, const char *))
{
  if ( *((_DWORD *)phandler + 2) != 0 && *((_DWORD *)phandler + 1) != 0 )
  {
    *(_DWORD *)(*((_DWORD *)phandler + 1) + 8) = *((_DWORD *)phandler + 2);
    *(_DWORD *)(*((_DWORD *)phandler + 2) + 4) = *((_DWORD *)phandler + 1);
  }
  *((_DWORD *)phandler + 1) = 0;
  *((_DWORD *)phandler + 2) = 0;
  *((_DWORD *)phandler + 3) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100635F0
// Name: public: void GRendererEventHandler::RemoveFromList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GRendererEventHandler::RemoveFromList(GRendererEventHandler *this)
{
  GRenderer *pRenderer; // ecx

  pRenderer = this->pRenderer;
  if ( pRenderer != nullptr )
  {
    pRenderer->RemoveEventHandler(this: pRenderer, a2: this);
  }
  else
  {
    if ( this->pNext != nullptr && this->pPrev != nullptr )
    {
      this->pPrev->pNext = this->pNext;
      this->pNext->pPrev = this->pPrev;
    }
    this->pPrev = nullptr;
    this->pNext = nullptr;
    this->pRenderer = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100637F0
// Name: public: virtual GRenderer::~GRenderer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GRenderer::~GRenderer(CUtlMemory<char *,int> *this)
{
  int *v2; // esi
  int *v3; // eax
  int *v4; // ecx
  void (__thiscall *v5)(int *, CUtlMemory<char *,int> *, int); // edx
  int *v6; // edx
  int *v7; // eax
  _DWORD *v8; // ecx
  int *v9; // eax

  v2 = *((int **)this + 3);
  this->m_pMemory = (char **)&GRenderer::`vftable';
  if ( v2 != nullptr )
  {
    while ( 1 )
    {
      v3 = this == (CUtlMemory<char *,int> *)-8 ? nullptr : &this->m_nAllocationCount;
      if ( v2 == v3 )
        break;
      v4 = v2;
      v5 = *(void (__thiscall **)(int *, CUtlMemory<char *,int> *, int))(*v2 + 4);
      v2 = (int *)v2[2];
      v5(a1: v4, a2: this, a3: 1);
    }
  }
  v6 = *((int **)this + 3);
  if ( v6 != nullptr )
  {
    while ( 1 )
    {
      v7 = this == (CUtlMemory<char *,int> *)-8 ? nullptr : &this->m_nAllocationCount;
      if ( v6 == v7 )
        break;
      v8 = v6 + 2;
      v9 = v6;
      v6 = (int *)v6[2];
      if ( v6 != nullptr && v9[1] != 0 )
      {
        *(_DWORD *)(v9[1] + 8) = v9[2];
        *(_DWORD *)(v9[2] + 4) = v9[1];
      }
      v9[1] = 0;
      *v8 = 0;
      v9[3] = 0;
    }
  }
  GRefCountImplCore::~GRefCountImplCore((IShaderAPI *)this);
}

//------------------------------------------------------------------------------
// Address: 0x10063880
// Name: public: virtual void GRenderer::EndFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GRenderer::EndFrame(CUtlMemory<char *,int> *this)
{
  int *v2; // esi
  int *v3; // eax
  int *v4; // ecx
  void (__thiscall *v5)(int *, CUtlMemory<char *,int> *, _DWORD); // edx
  GFxAmpServer *Instance; // eax

  v2 = *((int **)this + 3);
  if ( v2 != nullptr )
  {
    while ( 1 )
    {
      v3 = this == (CUtlMemory<char *,int> *)-8 ? nullptr : &this->m_nAllocationCount;
      if ( v2 == v3 )
        break;
      v4 = v2;
      v5 = *(void (__thiscall **)(int *, CUtlMemory<char *,int> *, _DWORD))(*v2 + 4);
      v2 = (int *)v2[2];
      v5(a1: v4, a2: this, a3: 0);
    }
  }
  Instance = (GFxAmpServer *)GFxAmpServer::GetInstance(a1: (unsigned int)this);
  GFxAmpServer::AdvanceFrame(this: Instance);
}

//------------------------------------------------------------------------------
// Address: 0x100638C0
// Name: public: static void GRenderer::MakeViewAndPersp3D(class GRect<float> const __near &,class GMatrix3D __near &,class GMatrix3D __near &,float,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GRenderer::MakeViewAndPersp3D(
        const CUtlMemory<unsigned char,int> *result,
        CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *a2,
        GMatrix3D *a3,
        float eyeZ,
        char fAR)
{
  double v6; // st7
  double v8; // st6
  float v9[3]; // [esp+10h] [ebp-38h] BYREF
  float v10[3]; // [esp+1Ch] [ebp-2Ch] BYREF
  float v11[3]; // [esp+28h] [ebp-20h] BYREF
  float DisplayWidth; // [esp+34h] [ebp-14h]
  float centerY; // [esp+38h] [ebp-10h]
  float centerX; // [esp+3Ch] [ebp-Ch]
  float v15; // [esp+40h] [ebp-8h]
  float DisplayHeight; // [esp+44h] [ebp-4h]
  float fovYAnglea; // [esp+50h] [ebp+8h]
  float fovYAngleb; // [esp+50h] [ebp+8h]
  float fovYAnglec; // [esp+50h] [ebp+8h]
  float fovYAngled; // [esp+50h] [ebp+8h]
  float fovYAngle; // [esp+50h] [ebp+8h]
  float eyeZb; // [esp+5Ch] [ebp+14h]
  float eyeZc; // [esp+5Ch] [ebp+14h]
  float eyeZd; // [esp+5Ch] [ebp+14h]
  float eyeZe; // [esp+5Ch] [ebp+14h]
  float eyeZf; // [esp+5Ch] [ebp+14h]
  float eyeZg; // [esp+5Ch] [ebp+14h]
  float eyeZa; // [esp+5Ch] [ebp+14h]
  float eyeZh; // [esp+5Ch] [ebp+14h]
  float fARb; // [esp+60h] [ebp+18h]
  float fARa; // [esp+60h] [ebp+18h]

  fovYAnglea = *(float *)&result[1].m_pMemory - *(float *)&result->m_nAllocationCount;
  fovYAngleb = fabs(fovYAnglea);
  DisplayHeight = fovYAngleb;
  fovYAnglec = *(float *)&result->m_nGrowSize - *(float *)&result->m_pMemory;
  fovYAngled = fabs(fovYAnglec);
  DisplayWidth = fovYAngled;
  fovYAngle = eyeZ * 3.141592653589793 / 180.0;
  centerX = (*(float *)&result->m_nGrowSize + *(float *)&result->m_pMemory) * 0.5;
  centerY = (*(float *)&result[1].m_pMemory + *(float *)&result->m_nAllocationCount) * 0.5;
  eyeZb = DisplayHeight / 20.0;
  eyeZc = eyeZb * 0.5;
  v15 = eyeZc;
  eyeZd = 0.5 * fovYAngle;
  eyeZe = tan(eyeZd);
  eyeZf = v15 / eyeZe;
  eyeZg = eyeZf * 20.0;
  eyeZa = -eyeZg;
  v6 = -100000.0;
  if ( eyeZa >= -100000.0 )
    v6 = eyeZa;
  eyeZh = v6;
  v9[0] = centerX;
  v9[1] = centerY;
  v9[2] = eyeZh;
  v10[0] = centerX;
  v10[1] = centerY;
  v10[2] = 0.0;
  if ( fAR != 0 )
    v8 = 1.0;
  else
    v8 = -1.0;
  fARb = v8;
  v11[0] = 0.0;
  v11[1] = fARb;
  v11[2] = 0.0;
  if ( fAR != 0 )
    GMatrix3D::ViewLH(this: a2, eyePt: v9, lookAtPt: v10, upVec: v11);
  else
    GMatrix3D::ViewRH(this: a2, eyePt: v9, lookAtPt: v10, upVec: v11);
  fARa = DisplayWidth / DisplayHeight;
  if ( fAR != 0 )
    GMatrix3D::PerspectiveLH(this: a3, a2: fovYAngle, a3: fARa, a4: 1.0, a5: 100000.0);
  else
    GMatrix3D::PerspectiveRH(this: a3, a2: fovYAngle, a3: fARa, a4: 1.0, a5: 100000.0);
}

//------------------------------------------------------------------------------
// Address: 0x10063A50
// Name: public: GRenderer::GRenderer(void)
// Source: json
//------------------------------------------------------------------------------
GRenderer *__thiscall GRenderer::GRenderer(GRenderer *this)
{
  GRenderer *result; // eax
  GList<GRendererEventHandler> *p_Handlers; // ecx
  GRendererEventHandler *p_pNext; // edx

  result = this;
  p_Handlers = &this->Handlers;
  result->__vftable = (GRenderer_vtbl *)&GRefCountImplCore::`vftable';
  result->RefCount = 1;
  result->__vftable = (GRenderer_vtbl *)&GRenderer::`vftable';
  if ( p_Handlers != nullptr )
    p_pNext = (GRendererEventHandler *)&p_Handlers[-1].Root.pNext;
  else
    p_pNext = nullptr;
  p_Handlers->Root.pPrev = p_pNext;
  result->S3DParams.DisplayWidthCm = 0.0;
  p_Handlers->Root.pNext = p_pNext;
  result->S3DParams.Distortion = 0.75;
  result->S3DParams.DisplayDiagInches = 52.0;
  result->S3DParams.DisplayAspectRatio = 0.5625;
  result->S3DParams.EyeSeparationCm = 6.4000001;
  result->S3DDisplay = StereoCenter;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10063AE0
// Name: unsigned int G_Format<float,float,float,float,float,float,float,float>(class GMsgFormat::Sink const __near &,char const __near *,float const __near &,float const __near &,float const __near &,float const __near &,float const __near &,float const __near &,float const __near &,float const __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl G_Format<float,float,float,float,float,float,float,float>(
        struct GMsgFormat::Sink *a1,
        CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *a2,
        CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int>::Iterator_t *v,
        CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int>::Iterator_t *a4,
        const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *a5,
        const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *a6,
        const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *a7,
        const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *a8,
        const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *a9,
        const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *a10)
{
  int m_nGrowSize; // esi
  unsigned __int16 v12; // [esp+0h] [ebp-328h]
  unsigned __int16 v13; // [esp+0h] [ebp-328h]
  CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > v14[27]; // [esp+24h] [ebp-304h] BYREF

  GMsgFormat::GMsgFormat(this: (GMsgFormat *)v14, a2: a1);
  GMsgFormat::Parse(result: a2);
  GMsgFormat::FormatD1<float>(
    this: (CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *)v14,
    (const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *)v);
  GMsgFormat::FormatD1<float>(
    this: (CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *)v14,
    v: (const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *)a4);
  GMsgFormat::FormatD1<float>(this: (CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *)v14, v: a5);
  GMsgFormat::FormatD1<float>(this: (CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *)v14, v: a6);
  GMsgFormat::FormatD1<float>(this: (CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *)v14, v: a7);
  GMsgFormat::FormatD1<float>(this: (CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *)v14, v: a8);
  GMsgFormat::FormatD1<float>(this: (CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *)v14, v: a9);
  GMsgFormat::FormatD1<float>(this: (CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *)v14, v: a10);
  GMsgFormat::FinishFormatD(this: v14, a2: v12);
  m_nGrowSize = v14[0].m_Elements.m_nGrowSize;
  GMsgFormat::~GMsgFormat(this: v14, data_size: v13);
  return m_nGrowSize;
}

//------------------------------------------------------------------------------
// Address: 0x10063C10
// Name: public: void GRenderer::Cxform::Format(char __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GRenderer::Cxform::Format(GRenderer::Cxform *this, char *pbuffer)
{
  _DWORD v2[3]; // [esp+0h] [ebp-Ch] BYREF

  v2[1] = pbuffer;
  v2[0] = 2;
  v2[2] = 512;
  G_Format<float,float,float,float,float,float,float,float>(
    a1: (struct GMsgFormat::Sink *)v2,
    a2: (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)"    *         +\n| {0:4.4} {1:4.4}|\n| {2:4.4} {3:4.4}|\n| {4:4.4} {5:4.4}|\n| {6:4.4} {7:4.4}|\n",
    v: (CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int>::Iterator_t *)this,
    a4: (CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int>::Iterator_t *)&this->M_[0][1],
    a5: (const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *)this->M_[1],
    a6: (const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *)&this->M_[1][1],
    a7: (const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *)this->M_[2],
    a8: (const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *)&this->M_[2][1],
    a9: (const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *)this->M_[3],
    a10: (const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *)&this->M_[3][1]);
}
