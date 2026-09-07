// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/cmatnullrendercontext.cpp
// Functions: 15
// ============================================================

#include "materialsystem\cmatnullrendercontext.h"

//------------------------------------------------------------------------------
// Address: 0x10003B20
// Name: public: virtual void CMatNullRenderContext::BindVertexBuffer(int,class IVertexBuffer __near *,int,int,int,unsigned __int64,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatNullRenderContext::BindVertexBuffer(
        GRenderer *this,
        GRenderer::BitmapDesc *pbitmapList,
        GRenderer::BitmapDesc *listSize,
        int startIndex,
        int count,
        const GTexture *pti,
        const GTexture *m,
        const GMatrix2D *params,
        const GRenderer::DistanceFieldParams *pcache)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1003BAE0
// Name: public: virtual void CMatNullRenderContext::InitializeFrom(class CMatRenderContextBase __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatNullRenderContext::InitializeFrom(
        CMatNullRenderContext *this,
        CMatRenderContextBase *pInitialState)
{
  CMatRenderContextBase::InitializeFrom(this, pInitialState);
  g_pShaderAPI->GetBackBufferDimensions(this: g_pShaderAPI, a2: &this->m_WidthBackBuffer, a3: &this->m_HeightBackBuffer);
}

//------------------------------------------------------------------------------
// Address: 0x1003BB20
// Name: public: virtual class IMesh __near * CMatNullRenderContext::CreateStaticMesh(unsigned __int64,char const __near *,class IMaterial __near *,struct VertexStreamSpec_t __near *)
// Source: json
//------------------------------------------------------------------------------
IMesh *__thiscall CMatNullRenderContext::CreateStaticMesh(
        CMatNullRenderContext *this,
        unsigned __int64 __formal,
        const char *a3,
        IMaterial *a4,
        VertexStreamSpec_t *a5)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1003BB30
// Name: public: virtual class IMesh __near * CMatNullRenderContext::GetDynamicMeshEx(unsigned __int64,bool,class IMesh __near *,class IMesh __near *,class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
IMesh *__thiscall CMatNullRenderContext::GetDynamicMeshEx(
        CMatNullRenderContext *this,
        unsigned __int64 __formal,
        bool a3,
        IMesh *a4,
        IMesh *a5,
        IMaterial *a6)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1003BB50
// Name: public: virtual int CMatNullRenderContext::OcclusionQuery_GetNumPixelsRendered(struct OcclusionQueryObjectHandle_t__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMatNullRenderContext::OcclusionQuery_GetNumPixelsRendered(
        CUtlMemory<unsigned short,int> *p,
        OcclusionQueryObjectHandle_t__ *__formal,
        unsigned int *a3)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1003BB60
// Name: public: virtual float CMatNullRenderContext::GetFloatRenderingParameter(int)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CMatNullRenderContext::GetFloatRenderingParameter(CMatNullRenderContext *this, int __formal)
{
  return 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x1003BB70
// Name: public: virtual class Vector CMatNullRenderContext::GetVectorRenderingParameter(int)const
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CMatNullRenderContext::GetVectorRenderingParameter(
        CMatNullRenderContext *this,
        Vector *result,
        int __formal)
{
  result->x = 0.0;
  result->y = 0.0;
  result->z = 0.0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003BB90
// Name: public: virtual bool CMatNullRenderContext::OnDrawMeshModulated(class IMesh __near *,class Vector4D const __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMatNullRenderContext::OnDrawMeshModulated(
        CMatNullRenderContext *this,
        IMesh *__formal,
        IMesh *__formala,
        int a4,
        int a5)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1003BBC0
// Name: public: virtual int CMatNullRenderContext::GetIntRenderingParameter(int)const
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CMatNullRenderContext::GetIntRenderingParameter(
        GArrayLH<GPtr<GFxAmpMemItem>,2,GArrayDefaultPolicy> *this,
        tagHELPWININFOW *__formal)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1003BBE0
// Name: public: virtual void CMatNullRenderContext::GetViewport(int __near &,int __near &,int __near &,int __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatNullRenderContext::GetViewport(
        CMatNullRenderContext *this,
        int *x,
        int *y,
        int *width,
        int *height)
{
  CMatRenderContextBase::RenderTargetStackElement_t *m_pMemory; // edx
  CMatRenderContextBase::RenderTargetStackElement_t *v6; // esi

  m_pMemory = this->m_RenderTargetStack.m_Memory.m_pMemory;
  v6 = &m_pMemory[this->m_RenderTargetStack.m_Size - 1];
  if ( m_pMemory[this->m_RenderTargetStack.m_Size - 1].m_nViewW < 0 || v6->m_nViewH < 0 )
  {
    *y = 0;
    *x = 0;
    if ( v6->m_pRenderTargets[0] != nullptr )
    {
      *width = v6->m_pRenderTargets[0]->GetActualWidth(this: v6->m_pRenderTargets[0]);
      *height = v6->m_pRenderTargets[0]->GetActualHeight(this: v6->m_pRenderTargets[0]);
    }
    else
    {
      *width = this->m_WidthBackBuffer;
      *height = this->m_HeightBackBuffer;
    }
  }
  else
  {
    *x = v6->m_nViewX;
    *y = v6->m_nViewY;
    *width = v6->m_nViewW;
    *height = v6->m_nViewH;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003BCB0
// Name: class CMatRenderContextBase __near * CreateNullRenderContext(void)
// Source: json
//------------------------------------------------------------------------------
CMatRenderContextBase *__cdecl CreateNullRenderContext()
{
  CMatRenderContextBase *v0; // eax
  _DWORD *v1; // esi

  v0 = (CMatRenderContextBase *)MemAlloc_Alloc(nSize: 0x1F8u);
  v1 = &v0->CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::IMatRenderContextInternal::IMatRenderContext::IRefCounted::__vftable;
  if ( v0 == nullptr )
    return nullptr;
  CMatRenderContextBase::CMatRenderContextBase(this: v0);
  *v1 = &CMatNullRenderContext::`vftable'{for `IMatRenderContextInternal'};
  v1[1] = &CMatNullRenderContext::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
  v1[124] = 0;
  v1[125] = 0;
  return (CMatRenderContextBase *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x10048ED0
// Name: public: virtual bool CMatNullRenderContext::OnSetPrimitiveType(class IMesh __near *,enum MaterialPrimitiveType_t)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMatNullRenderContext::OnSetPrimitiveType(
        CMatNullRenderContext *this,
        IMesh *__formal,
        MaterialPrimitiveType_t __formala)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1004FD60
// Name: public: virtual void CMatNullRenderContext::OverrideColorWriteEnable(bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatNullRenderContext::OverrideColorWriteEnable(
        CUtlDict<ITextureInternal *,unsigned short> *this,
        unsigned __int16 prenderer,
        HBITMAP__ ptext)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10050140
// Name: public: virtual void CMatNullRenderContext::DrawScreenSpaceRectangle(class IMaterial __near *,int,int,int,int,float,float,float,float,int,int,void __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatNullRenderContext::DrawScreenSpaceRectangle(
        CMatNullRenderContext *this,
        IMaterial *__formal,
        IMaterial *__formala,
        int destx,
        int desty,
        int width,
        float height,
        float src_texture_x0,
        float src_texture_y0,
        float src_texture_x1,
        int src_texture_y1,
        int src_texture_width,
        int src_texture_height,
        void *pClientRenderable,
        int nXDice)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x100502E0
// Name: public: virtual bool CMatNullRenderContext::GetMorphAccumulatorTexCoord(class Vector2D __near *,class IMorph __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMatNullRenderContext::GetMorphAccumulatorTexCoord(
        CMatQueuedRenderContext *this,
        Vector2D *pTexCoord,
        IMorph *pIMorph,
        int nVertex)
{
  pTexCoord->x = 0.0;
  pTexCoord->y = 0.0;
  return false;
}
