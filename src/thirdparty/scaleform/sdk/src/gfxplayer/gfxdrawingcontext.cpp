// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/gfxdrawingcontext.cpp
// Functions: 20
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\gfxdrawingcontext.h"

//------------------------------------------------------------------------------
// Address: 0x1013A500
// Name: public: void GFxDrawingContext::SetNoLine(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxDrawingContext::SetNoLine(IClientTools *this)
{
  *((_DWORD *)this + 5) = 0;
  *((_BYTE *)this + 133) = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1013A510
// Name: public: void GFxDrawingContext::SetNoFill(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxDrawingContext::SetNoFill(IClientTools *this)
{
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1013A520
// Name: public: void GFxDrawingContext::MoveTo(float,float)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall GFxDrawingContext::MoveTo(IClientTools *this, void *x, float y)
{
  return GFxPathPacker::SetMoveTo(
           this: (CStridedConstPtr<__m128> *)(this + 3),
           x: (int)*(float *)&x,
           (int)y,
           numBits: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1013A550
// Name: public: void GFxDrawingContext::LineTo(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxDrawingContext::LineTo(IClientTools *this, void *x, float y)
{
  GFxPathPacker::LineToAbs(this: (CSOAAttributeReference *)(this + 3), x: COERCE_FLOAT((int)*(float *)&x), (int)y);
  *((_BYTE *)this + 133) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1013A580
// Name: public: void GFxDrawingContext::CurveTo(float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxDrawingContext::CurveTo(IClientTools *this, const char *cx, float cy, float a4, float ay)
{
  GFxPathPacker::CurveToAbs(
    this: (GFxPathPacker *)(this + 3),
    a2: (int)*(float *)&cx,
    a3: (int)cy,
    (int)a4,
    a5: (int)ay);
  *((_BYTE *)this + 133) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1013A5C0
// Name: public: void GFxDrawingContext::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxDrawingContext::Clear(IClientTools *this)
{
  void *v2; // eax
  IClientUnknown *v3; // edi
  GFxShapeBase *v4; // ecx
  int v5; // [esp+8h] [ebp-4h] BYREF

  GFxPathPacker::Reset(this: (GFxPathPacker *)(this + 3));
  v5 = 258;
  v2 = GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 124, a3: &v5);
  if ( v2 != nullptr )
    v3 = GFxShapeWithStyles::GFxShapeWithStyles(this: (int)v2, result: (IClientUnknown *)0x1FF8);
  else
    v3 = nullptr;
  v4 = *((GFxShapeBase **)this + 2);
  if ( v4 != nullptr )
    GFxShapeBase::Release(this: v4);
  *((_DWORD *)this + 2) = v3;
  *((_BYTE *)this + 132) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1013A620
// Name: public: bool GFxDrawingContext::SameLineStyle(float,unsigned int,bool,enum GFxLineStyle::LineStyle,enum GFxLineStyle::LineStyle,enum GFxLineStyle::LineStyle,float)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxDrawingContext::SameLineStyle(
        IClientTools *this,
        QAngle *result,
        unsigned int lineWidth,
        bool hinting,
        CMemberFunctor2<IMesh *,void (__thiscall IMesh::*)(int,int),int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *scaling,
        CMemberFunctor2<IMesh *,void (__thiscall IMesh::*)(int,int),int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *caps,
        CMemberFunctor2<IMesh *,void (__thiscall IMesh::*)(int,int),int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *joins,
        float miterLimit)
{
  int v8; // eax
  int v10; // edx
  int v11; // ecx
  __int16 v12; // ax

  v8 = *((_DWORD *)this + 2);
  if ( *(_DWORD *)(v8 + 96) == 0 )
    return 0;
  if ( *((_DWORD *)this + 5) == 0 )
    return 0;
  v10 = *(_DWORD *)(v8 + 92);
  v11 = v10 + 24 * *(_DWORD *)(v8 + 96) - 24;
  if ( *(_DWORD *)(v10 + 24 * *(_DWORD *)(v8 + 96) - 12) != 0 )
    return 0;
  if ( *(_DWORD *)(v11 + 8) == lineWidth
    && *(unsigned __int16 *)(v11 + 4) == (__int64)*(float *)&result
    && (*(_BYTE *)(v11 + 16) & 1) == hinting )
  {
    v12 = *(_WORD *)(v11 + 16);
    if ( (CMemberFunctor2<IMesh *,void (__thiscall IMesh::*)(int,int),int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)(v12 & 6) == scaling
      && (CMemberFunctor2<IMesh *,void (__thiscall IMesh::*)(int,int),int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)(v12 & 0xC0) == caps
      && (CMemberFunctor2<IMesh *,void (__thiscall IMesh::*)(int,int),int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)(v12 & 0x30) == joins
      && miterLimit == *(float *)(v11 + 20) )
    {
      return 1;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1013A6D0
// Name: public: bool GFxDrawingContext::NoLine(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall GFxDrawingContext::NoLine(GFxDrawingContext *this)
{
  return *(_DWORD *)(*((_DWORD *)this + 2) + 96) == 0 || *((_DWORD *)this + 5) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1013A6F0
// Name: public: void GFxDrawingContext::SetNonZeroFill(bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxDrawingContext::SetNonZeroFill(IClientTools *this, const FlashlightState_t *fill)
{
  int result; // eax

  result = *((_DWORD *)this + 2);
  if ( (_BYTE)fill != 0 )
    *(_BYTE *)(result + 36) |= 8u;
  else
    *(_BYTE *)(result + 36) &= ~8u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1013A710
// Name: public: void GFxDrawingContext::AddPath(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxDrawingContext::AddPath(IClientTools *this)
{
  int v1; // eax
  CStridedConstPtr<__m128> *v2; // ecx

  v1 = *((_DWORD *)this + 2);
  v2 = (CStridedConstPtr<__m128> *)(this + 3);
  if ( v2[5].m_pData != nullptr )
    GFxPathPacker::Pack(this: v2, a2: (FloatCubeMap_t *)(v1 + 40), ppathsInfo: (CStridedConstPtr<__m128> *)(v1 + 52));
}

//------------------------------------------------------------------------------
// Address: 0x1013A970
// Name: public: GFxDrawingContext::GFxDrawingContext(void)
// Source: json
//------------------------------------------------------------------------------
IClientTools *__thiscall GFxDrawingContext::GFxDrawingContext(IClientTools *this)
{
  void *v2; // eax
  IClientUnknown *v3; // eax
  const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),CFuncMemPolicyNone> *v5; // [esp+0h] [ebp-8h]
  CMemberFuncProxyBase<CLateBoundPtr<IMesh>,void (__thiscall IMesh::*)(IMesh *,int),CFuncMemPolicyNone> *v6; // [esp+0h] [ebp-8h]
  int v7; // [esp+4h] [ebp-4h] BYREF

  this->__vftable = (IClientTools_vtbl *)&GRefCountImplCore::`vftable';
  *((_DWORD *)this + 1) = 1;
  this->__vftable = (IClientTools_vtbl *)&GFxDrawingContext::`vftable';
  v7 = 258;
  v2 = GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 124, a3: &v7);
  if ( v2 != nullptr )
    v3 = GFxShapeWithStyles::GFxShapeWithStyles(this: (int)v2, result: (IClientUnknown *)0x1FF8);
  else
    v3 = nullptr;
  *((_DWORD *)this + 2) = v3;
  GFxPathPacker::GFxPathPacker(this: (GFxPathPacker *)(this + 3));
  GFxFillStyle::GFxFillStyle(
    this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),CFuncMemPolicyNone> *)(this + 17),
    a2: v5);
  GFxLineStyle::GFxLineStyle(result: v6);
  *((_WORD *)this + 66) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1013A9F0
// Name: public: void GFxDrawingContext::SetLineStyle(float,unsigned int,bool,enum GFxLineStyle::LineStyle,enum GFxLineStyle::LineStyle,enum GFxLineStyle::LineStyle,float)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall GFxDrawingContext::SetLineStyle(
        IClientTools *this,
        Vector *result,
        unsigned int lineWidth,
        char hinting,
        unsigned __int8 scaling,
        char caps,
        unsigned __int8 joins,
        IClientTools miterLimit)
{
  __int16 v9; // cx
  Vector *v10; // eax
  int hintinga; // [esp+14h] [ebp+10h]

  *((_WORD *)this + 56) = (int)*(float *)&result;
  *((_DWORD *)this + 29) = lineWidth;
  *((_WORD *)this + 62) &= ~1u;
  if ( hinting != 0 )
    *((_WORD *)this + 62) |= 1u;
  *((_WORD *)this + 62) ^= (scaling ^ (unsigned __int8)*((_WORD *)this + 62)) & 6;
  v9 = (4 * (caps & 0xC0)) | caps & 0xC0 | *(_WORD *)(this + 31) & 0xFC3F;
  *((_WORD *)this + 62) = v9;
  *((_WORD *)this + 62) ^= (joins ^ (unsigned __int8)v9) & 0x30;
  hintinga = *((_DWORD *)this + 2);
  *(this + 32) = miterLimit;
  GArrayDataBase<GFxLineStyle,GAllocatorLH<GFxLineStyle,259>,GArrayDefaultPolicy>::ResizeNoConstruct(
    this: hintinga + 92,
    a2: (const void *)(hintinga + 92),
    a3: *(_DWORD *)(hintinga + 96) + 1);
  if ( *(_DWORD *)(hintinga + 92) + 24 * *(_DWORD *)(hintinga + 96) != 24 )
    GFxLineStyle::GFxLineStyle(this: (CMemberFuncProxyBase<CLateBoundPtr<IMesh>,void (__thiscall IMesh::*)(IMesh *,int),CFuncMemPolicyNone> *)(*(_DWORD *)(hintinga + 92) + 24 * *(_DWORD *)(hintinga + 96) - 24));
  v10 = *(Vector **)(hintinga + 96);
  *((_DWORD *)this + 5) = v10;
  *((_BYTE *)this + 133) = 1;
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x1013AAE0
// Name: public: class GFxFillStyle __near * GFxDrawingContext::SetNewFill(void)
// Source: json
//------------------------------------------------------------------------------
struct GFxFillStyle *__thiscall GFxDrawingContext::SetNewFill(GFxDrawingContext *this)
{
  int v2; // ebx
  int v3; // eax

  GFxFillStyle::SetFillType(a1: (char *)this + 68, a2: 0);
  v2 = *((_DWORD *)this + 2);
  *((_DWORD *)this + 18) = 0;
  GArrayDataBase<GFxFillStyle,GAllocatorLH<GFxFillStyle,259>,GArrayDefaultPolicy>::ResizeNoConstruct(
    this: (GAtomicOpsRawBase::AcquireSync *)(v2 + 80),
    a2: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),CFuncMemPolicyNone> *)v2,
    pheapAddr: (const void *)(v2 + 80),
    newSize: *(_DWORD *)(v2 + 84) + 1);
  v3 = *(_DWORD *)(v2 + 84);
  if ( *(_DWORD *)(v2 + 80) + 40 * v3 != 40 )
    GFxFillStyle::GFxFillStyle(
      this: (GFxFillStyle *)(*(_DWORD *)(v2 + 80) + 40 * v3 - 40),
      a2: (const struct GFxFillStyle *)((char *)this + 68));
  *((_DWORD *)this + 3) = *(_DWORD *)(v2 + 84);
  *((_DWORD *)this + 4) = 0;
  return (struct GFxFillStyle *)(*(_DWORD *)(*((_DWORD *)this + 2) + 80)
                               + 40 * *(_DWORD *)(*((_DWORD *)this + 2) + 84)
                               - 40);
}

//------------------------------------------------------------------------------
// Address: 0x1013AB50
// Name: public: class GFxFillStyle __near * GFxDrawingContext::CreateLineComplexFill(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxDrawingContext::CreateLineComplexFill(
        GFxDrawingContext *this,
        const CMemberFunctor2<IMesh *,void (__thiscall IMesh::*)(int,int),int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *a2)
{
  int v3; // ebx
  int v4; // eax

  if ( *((_BYTE *)this + 133) == 0 )
  {
    v3 = *((_DWORD *)this + 2);
    GArrayDataBase<GFxLineStyle,GAllocatorLH<GFxLineStyle,259>,GArrayDefaultPolicy>::ResizeNoConstruct(
      this: v3 + 92,
      a2: (const void *)(v3 + 92),
      a3: *(_DWORD *)(v3 + 96) + 1);
    v4 = *(_DWORD *)(v3 + 96);
    if ( *(_DWORD *)(v3 + 92) + 24 * v4 != 24 )
      GFxLineStyle::GFxLineStyle(this: (CMemberFuncProxyBase<CLateBoundPtr<IMesh>,void (__thiscall IMesh::*)(IMesh *,int),CFuncMemPolicyNone> *)(*(_DWORD *)(v3 + 92) + 24 * v4 - 24));
    *((_DWORD *)this + 5) = *(_DWORD *)(v3 + 96);
  }
  GFxLineStyle::CreateComplexFill(
    this: (CMemberFunctor2<IMesh *,void (__thiscall IMesh::*)(int,int),int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)(*(_DWORD *)(*((_DWORD *)this + 2) + 92) + 24 * *(_DWORD *)(*((_DWORD *)this + 2) + 96) - 24),
    a2);
}

//------------------------------------------------------------------------------
// Address: 0x1013ABB0
// Name: public: void GFxDrawingContext::SetFill(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxDrawingContext::SetFill(IClientTools *this@<ecx>, int rgba, const FlashlightState_t *a3)
{
  CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),CFuncMemPolicyNone> *v4; // ebx
  int rgbaa; // [esp+14h] [ebp+8h]

  v4 = (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),CFuncMemPolicyNone> *)(this + 17);
  GFxFillStyle::SetFillType(a1: this + 17, a2: 0);
  rgbaa = *((_DWORD *)this + 2);
  *((_DWORD *)this + 18) = rgba;
  GArrayDataBase<GFxFillStyle,GAllocatorLH<GFxFillStyle,259>,GArrayDefaultPolicy>::ResizeNoConstruct(
    this: (GAtomicOpsRawBase::AcquireSync *)(rgbaa + 80),
    a2: v4,
    pheapAddr: (const void *)(rgbaa + 80),
    newSize: *(_DWORD *)(rgbaa + 84) + 1);
  if ( *(_DWORD *)(rgbaa + 80) + 40 * *(_DWORD *)(rgbaa + 84) != 40 )
    GFxFillStyle::GFxFillStyle(
      this: (GFxFillStyle *)(*(_DWORD *)(rgbaa + 80) + 40 * *(_DWORD *)(rgbaa + 84) - 40),
      a2: (const struct GFxFillStyle *)v4);
  *(this + 3) = *(IClientTools *)(rgbaa + 84);
  *((_DWORD *)this + 4) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1013AC10
// Name: public: void GFxDrawingContext::SetBitmapFill(enum GFxFillType,class GFxImageResource __near *,class GMatrix2D const __near &)
// Source: json
//------------------------------------------------------------------------------
CMemberFuncProxy3<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,CPrimList *,int),IMesh *,CPrimList *,int,CFuncMemPolicyNone> *__thiscall GFxDrawingContext::SetBitmapFill(
        GFxDrawingContext *this,
        CMemberFuncProxy3<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,CPrimList *,int),IMesh *,CPrimList *,int,CFuncMemPolicyNone> *result,
        int pimageRes,
        int pimageRes_4)
{
  CMemberFuncProxy3<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,CPrimList *,int),IMesh *,CPrimList *,int,CFuncMemPolicyNone> *v4; // eax

  v4 = (CMemberFuncProxy3<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,CPrimList *,int),IMesh *,CPrimList *,int,CFuncMemPolicyNone> *)GFxDrawingContext::SetNewFill(this);
  if ( v4 != nullptr )
    return GFxFillStyle::SetImageFill(result);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1013AC30
// Name: public: bool GFxDrawingContext::AcquirePath(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxDrawingContext::AcquirePath(IClientTools *this, unsigned __int16 newShapeFlag)
{
  int v3; // ebx
  CStridedConstPtr<__m128> v4; // [esp+8h] [ebp-38h] BYREF
  void *v5; // [esp+24h] [ebp-1Ch]
  char v6; // [esp+3Dh] [ebp-3h]

  if ( *((_DWORD *)this + 13) != 0 )
  {
    if ( *((_DWORD *)this + 3) != 0 )
      GFxPathPacker::ClosePath(this: (CStridedConstPtr<__m128> *)(this + 3));
    if ( *((_BYTE *)this + 132) != 0 )
    {
      v3 = *((_DWORD *)this + 2);
      GFxPathPacker::GFxPathPacker(this: (GFxPathPacker *)&v4);
      v6 = 1;
      GFxPathPacker::Pack(this: &v4, a2: (FloatCubeMap_t *)(v3 + 40), ppathsInfo: (CStridedConstPtr<__m128> *)(v3 + 52));
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v5);
    }
    if ( *((_DWORD *)this + 13) != 0 )
      GFxPathPacker::Pack(
        this: (CStridedConstPtr<__m128> *)(this + 3),
        a2: (FloatCubeMap_t *)(*((_DWORD *)this + 2) + 40),
        ppathsInfo: (CStridedConstPtr<__m128> *)(*((_DWORD *)this + 2) + 52));
    GFxShapeBase::ResetCache(this: *((GFxShapeBase **)this + 2));
    *(_BYTE *)(*((_DWORD *)this + 2) + 36) &= ~0x10u;
    *((_DWORD *)this + 14) = 0;
    *((_DWORD *)this + 15) = 0;
    *((_DWORD *)this + 13) = 0;
    *((_BYTE *)this + 65) = 0;
    GFxPathPacker::SetMoveTo(
      this: (CStridedConstPtr<__m128> *)(this + 3),
      x: *((_DWORD *)this + 8),
      y: *((_DWORD *)this + 9),
      numBits: 0);
    *((_BYTE *)this + 132) = newShapeFlag;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013ACF0
// Name: public: void GFxDrawingContext::ComputeBound(class GRect<float> __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxDrawingContext::ComputeBound(IClientTools *this)
{
  GFxDrawingContext::AcquirePath(this, newShapeFlag: 1u);
  return (*(bool (__thiscall **)(_DWORD))(**((_DWORD **)this + 2) + 20))(a1: *((_DWORD *)this + 2));
}

//------------------------------------------------------------------------------
// Address: 0x1013AD10
// Name: public: void GFxDrawingContext::Display(class GFxDisplayContext __near &,class GMatrix2D const __near &,class GRenderer::Cxform const __near &,enum GRenderer::BlendType,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxDrawingContext::Display(
        IClientTools *this,
        FBMAttributeMask_t context,
        float *blend_4,
        const void *blend_8,
        int a5,
        bool edgeAADisabled)
{
  GFxAmpViewStats *v6; // esi
  void *v8; // ecx
  __int64 v9; // rax
  _BYTE *v10; // ecx
  float *v11; // eax
  double v12; // st7
  int v13; // ecx
  double v14; // st7
  __int64 v15; // rax
  __int64 v16; // [esp+Ch] [ebp-8Ch]
  int m_nAllocationCount; // [esp+24h] [ebp-74h]
  float v18; // [esp+28h] [ebp-70h]
  int m_nGrowSize; // [esp+2Ch] [ebp-6Ch]
  CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> bounds; // [esp+34h] [ebp-64h] BYREF
  float v21; // [esp+40h] [ebp-58h]
  FBMAttributeMask_t params; // [esp+44h] [ebp-54h] BYREF
  int v23; // [esp+48h] [ebp-50h]
  int v24; // [esp+4Ch] [ebp-4Ch]
  float v25; // [esp+50h] [ebp-48h]
  float v26; // [esp+54h] [ebp-44h]
  float v27; // [esp+58h] [ebp-40h]
  float v28; // [esp+5Ch] [ebp-3Ch]
  float v29; // [esp+60h] [ebp-38h]
  float v30; // [esp+64h] [ebp-34h]
  _DWORD v31[11]; // [esp+68h] [ebp-30h] BYREF

  v6 = *(GFxAmpViewStats **)(context + 144);
  if ( v6 != nullptr )
  {
    GFxAmpViewStats::PushCallstack(this: v6, swdHandle: 1u, swfOffset: 2u);
    GTimer::GetRawTicks(li: v8);
    v16 = v9;
  }
  else
  {
    v16 = 0;
  }
  GFxDrawingContext::AcquirePath(this, newShapeFlag: 0);
  v10 = *((_BYTE **)this + 2);
  if ( *((_DWORD *)v10 + 21) != 0 || *((_DWORD *)v10 + 24) != 0 )
  {
    if ( (v10[36] & 0x10) == 0 )
    {
      *(float *)&bounds.m_pMemory = 0.0;
      *(float *)&bounds.m_nAllocationCount = 0.0;
      *(float *)&bounds.m_nGrowSize = 0.0;
      v21 = 0.0;
      (*(void (__thiscall **)(_BYTE *, CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *))(*(_DWORD *)v10 + 20))(
        a1: v10,
        a2: &bounds);
      v11 = *((float **)this + 2);
      m_nAllocationCount = bounds.m_nAllocationCount;
      m_nGrowSize = bounds.m_nGrowSize;
      v18 = v21;
      v11[1] = *(float *)&bounds.m_pMemory;
      v11[2] = *(float *)&m_nAllocationCount;
      v11[3] = *(float *)&m_nGrowSize;
      v11[4] = v18;
      *(_BYTE *)(*((_DWORD *)this + 2) + 36) |= 0x10u;
    }
    v25 = *blend_4;
    v26 = blend_4[1];
    params = context;
    v12 = blend_4[2];
    v23 = 0;
    v27 = v12;
    v24 = 0;
    v28 = blend_4[3];
    v29 = blend_4[4];
    v30 = blend_4[5];
    qmemcpy(v31, blend_8, 0x20u);
    v13 = *((_DWORD *)this + 2);
    v31[8] = a5;
    v31[9] = 0;
    v31[10] = 0;
    v14 = ((double (__thiscall *)(int, FBMAttributeMask_t *))*(_DWORD *)(*(_DWORD *)v13 + 44))(a1: v13, a2: &params);
    GFxShapeBase::Display(
      this: *((GFxShapeBase **)this + 2),
      a2: v14,
      a3: (struct GFxDisplayParams *)&params,
      a4: edgeAADisabled,
      a5: nullptr);
  }
  if ( v6 != nullptr )
  {
    GTimer::GetRawTicks(li: v10);
    GFxAmpViewStats::PopCallstack(this: (int)v6, result: (GImageInfo *)1, swfOffset: 2u, funcTime: v15 - v16);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013AE80
// Name: public: bool GFxDrawingContext::DefPointTestLocal(class GPoint<float> const __near &,bool,class GFxCharacter const __near *)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall GFxDrawingContext::DefPointTestLocal(IClientTools *this, int pt)
{
  GFxDrawingContext::AcquirePath(this, newShapeFlag: 1u);
  return (*(const char *(__thiscall **)(_DWORD, int))(**((_DWORD **)this + 2) + 12))(a1: *((_DWORD *)this + 2), a2: pt);
}
