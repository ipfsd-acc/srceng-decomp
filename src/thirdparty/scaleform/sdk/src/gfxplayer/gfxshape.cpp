// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/gfxshape.cpp
// Functions: 141
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\gfxshape.h"

//------------------------------------------------------------------------------
// Address: 0x10025D50
// Name: public: virtual unsigned char const __near * GFxShapeNoStyles::GetPathData(void)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall GFxShapeNoStyles::GetPathData(CVTFTexture *this)
{
  return &this->m_vecReflectivity;
}

//------------------------------------------------------------------------------
// Address: 0x100DDAB0
// Name: public: virtual class GRect<float> GFxShapeCharacterDef::GetRectBoundsLocal(void)const
// Source: rtti_class
//------------------------------------------------------------------------------
int __thiscall GFxShapeCharacterDef::GetRectBoundsLocal(_DWORD *this, int a2)
{
  (*(void (__thiscall **)(_DWORD *, int))(*(this + 4) + 4))(a1: this + 4, a2);
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x10137A90
// Name: float GMath2D::CalcPointToSegmentPos<class GPoint<float>,class GPoint<float>>(class GPoint<float> const __near &,class GPoint<float> const __near &,class GPoint<float> const __near &)
// Source: json
//------------------------------------------------------------------------------
double __cdecl GMath2D::CalcPointToSegmentPos<GPoint<float>,GPoint<float>>(float *a1, float *a2, float *a3)
{
  double v3; // st7
  double v4; // st3
  float v6; // [esp+0h] [ebp-4h]
  float v7; // [esp+Ch] [ebp+8h]
  float v9; // [esp+10h] [ebp+Ch]

  v6 = a1[1];
  v3 = *a1;
  v7 = *a2 - v3;
  v9 = a2[1] - v6;
  v4 = v9;
  if ( 0.0 == v7 && 0.0 == v4 )
    return (float)0.0;
  return (float)((v7 * (*a3 - v3) + v4 * (a3[1] - v6)) / (v4 * v4 + v7 * v7));
}

//------------------------------------------------------------------------------
// Address: 0x10144E70
// Name: public: bool GFxFillStyle::IsClippedImageFill(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxFillStyle::IsClippedImageFill(
        CMemberFunctor1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CMatQueuedMesh::MST_DrawInfo_t,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10144E90
// Name: public: void GFxScale9GridInfo::MakeKey(void __near *,float,unsigned char)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxScale9GridInfo::MakeKey(GFxScale9GridInfo *this, float *a2, float a3, unsigned __int8 a4)
{
  *a2 = 0.0;
  *(_BYTE *)a2 = a4;
  a2[1] = a3;
  a2[2] = *((float *)this + 2);
  a2[3] = *((float *)this + 3);
  a2[4] = *((float *)this + 4);
  a2[5] = *((float *)this + 5);
  a2[6] = *((float *)this + 6);
  a2[7] = *((float *)this + 7);
  a2[8] = *((float *)this + 9);
  a2[9] = *((float *)this + 10);
  a2[10] = *((float *)this + 12);
  a2[11] = *((float *)this + 13);
  a2[12] = *((float *)this + 14);
  a2[13] = *((float *)this + 15);
  a2[14] = *((float *)this + 16);
  a2[15] = *((float *)this + 17);
  a2[16] = *((float *)this + 18);
  a2[17] = *((float *)this + 19);
  a2[18] = *((float *)this + 20);
  a2[19] = *((float *)this + 21);
  a2[20] = *((float *)this + 22);
}

//------------------------------------------------------------------------------
// Address: 0x10144F20
// Name: public: void GFxShapeBase::ResetCache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxShapeBase::ResetCache(GFxShapeBase *this)
{
  GFxMeshCache *v2; // ecx
  void (__thiscall ***v3)(_DWORD, int); // ecx

  v2 = *((GFxMeshCache **)this + 6);
  if ( v2 != nullptr )
    GFxMeshCache::AddShapeToKillList(this: v2, a2: (struct GFxShapeBase *)this);
  v3 = *((void (__thiscall ****)(_DWORD, int))this + 8);
  *((_DWORD *)this + 6) = 0;
  if ( v3 != nullptr )
    (**v3)(a1: v3, a2: 1);
  *((_DWORD *)this + 8) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10144F70
// Name: public: virtual void GFxShapeBase::GetFillAndLineStyles(class GFxFillStyle const __near * __near *,unsigned int __near *,class GFxLineStyle const __near * __near *,unsigned int __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxShapeBase::GetFillAndLineStyles(
        GFxShapeBase *this,
        CSOAAttributeReferenceBinaryOp<&DivSIMD> *const ppfillStyles,
        unsigned int *pfillStylesNum,
        const struct GFxLineStyle **plineStylesNum,
        unsigned int *a5)
{
  ppfillStyles->m_opA.m_pContainer = nullptr;
  *pfillStylesNum = 0;
  *plineStylesNum = nullptr;
  *a5 = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10144FA0
// Name: public: virtual void GFxShapeBase::GetFillAndLineStyles(struct GFxDisplayParams __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxShapeBase::GetFillAndLineStyles(GFxShapeBase *this, struct GFxDisplayParams *a2)
{
  *((_DWORD *)a2 + 1) = 0;
  *((_DWORD *)a2 + 2) = 0;
  *((_DWORD *)a2 + 18) = 0;
  *((_DWORD *)a2 + 19) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10144FC0
// Name: float GMath2D::CalcPointOnQuadCurve1D(float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl GMath2D::CalcPointOnQuadCurve1D(float x1, float x2, float x3, float t)
{
  float x1a; // [esp+8h] [ebp+8h]
  float x2a; // [esp+Ch] [ebp+Ch]

  x1a = x1 + (x2 - x1) * t;
  x2a = x2 + (x3 - x2) * t;
  return (float)(t * (x2a - x1a) + x1a);
}

//------------------------------------------------------------------------------
// Address: 0x10145010
// Name: bool GMath2D::CheckMonoCurveIntersection(float,float,float,float,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl GMath2D::CheckMonoCurveIntersection(
        GMath2D *this,
        float a2,
        float a3,
        float a4,
        float a5,
        float a6,
        float a7,
        float a8)
{
  double v8; // st7
  double v9; // st6
  double v10; // st5
  double v11; // st4
  BOOL v12; // edx
  BOOL v13; // ecx
  double v15; // st7
  double v16; // [esp+10h] [ebp-18h]
  double v17; // [esp+18h] [ebp-10h]
  double v18; // [esp+20h] [ebp-8h]
  float v19; // [esp+24h] [ebp-4h]
  float v20; // [esp+24h] [ebp-4h]
  float v21; // [esp+4Ch] [ebp+24h]
  float v22; // [esp+4Ch] [ebp+24h]
  float v23; // [esp+4Ch] [ebp+24h]
  float v24; // [esp+4Ch] [ebp+24h]
  float v25; // [esp+4Ch] [ebp+24h]
  float v26; // [esp+4Ch] [ebp+24h]

  v8 = a8;
  v9 = a2;
  if ( a2 > (double)a8 )
    return false;
  v10 = a6;
  if ( a6 <= v8 )
    return false;
  v11 = a4;
  v21 = (a7 - a3) * (a4 - v9) - (a3 - *(float *)&this) * (v8 - a4);
  v12 = v21 > 0.0;
  v18 = a7 - a5;
  v17 = v8 - v10;
  v22 = (v10 - a4) * v18 - (a5 - a3) * v17;
  v13 = v22 > 0.0;
  v16 = v10 - v9;
  v23 = v16 * v18 - (a5 - *(float *)&this) * v17;
  if ( v13 && v23 > 0.0 && v12 )
    return true;
  if ( !v13 && v23 <= 0.0 && !v12 )
    return false;
  v19 = v9 - (v11 + v11) + v10;
  v24 = -1.0;
  if ( 0.0 == v19 )
  {
    v20 = v16;
    if ( v20 != 0.0 )
      v24 = (v8 - v9) / v20;
  }
  else
  {
    v25 = v8 * a6 + v11 * v11 - (v10 - v8) * v9 - (v8 + v8) * v11;
    if ( v25 <= 0.0 )
    {
      v15 = (v9 + (float)0.0 - a4) / v19;
    }
    else
    {
      v26 = sqrt(v25);
      v15 = (a2 + v26 - a4) / v19;
    }
    v24 = v15;
  }
  return a7 > GMath2D::CalcPointOnQuadCurve1D(x1: *(float *)&this, x2: a3, x3: a5, t: v24);
}

//------------------------------------------------------------------------------
// Address: 0x10145220
// Name: public: GFxPathAllocator::GFxPathAllocator(unsigned int)
// Source: json
//------------------------------------------------------------------------------
FloatCubeMap_t *__thiscall GFxPathAllocator::GFxPathAllocator(_DWORD *this, FloatCubeMap_t *result)
{
  *this = 0;
  *(this + 1) = 0;
  *((_WORD *)this + 4) = 0;
  *((_WORD *)this + 5) = (_WORD)result;
  return (FloatCubeMap_t *)this;
}

//------------------------------------------------------------------------------
// Address: 0x10145250
// Name: public: void GFxPathAllocator::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxPathAllocator::Clear(FloatCubeMap_t *this)
{
  _DWORD *m_nColumns; // eax
  _DWORD *v3; // esi

  m_nColumns = (_DWORD *)this->face_maps[0].m_nColumns;
  if ( this->face_maps[0].m_nColumns != 0 )
  {
    do
    {
      v3 = (_DWORD *)*m_nColumns;
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: m_nColumns);
      m_nColumns = v3;
    }
    while ( v3 != nullptr );
  }
  this->face_maps[0].m_nColumns = 0;
  this->face_maps[0].m_nRows = 0;
  LOWORD(this->face_maps[0].m_nSlices) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10145290
// Name: public: unsigned char __near * GFxPathAllocator::AllocMemoryBlock(unsigned long,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxPathAllocator::AllocMemoryBlock(
        FloatCubeMap_t *this,
        unsigned int sizeForCurrentPage,
        unsigned int size)
{
  unsigned int m_nSlices_low; // edi
  _DWORD *v5; // eax
  _DWORD *m_nRows; // ecx
  bool v7; // zf

  m_nSlices_low = LOWORD(this->face_maps[0].m_nSlices);
  if ( this->face_maps[0].m_nRows != 0 && m_nSlices_low >= sizeForCurrentPage )
  {
    size = sizeForCurrentPage;
  }
  else
  {
    m_nSlices_low = HIWORD(this->face_maps[0].m_nSlices);
    if ( size > m_nSlices_low )
      m_nSlices_low = size;
    sizeForCurrentPage = 2;
    v5 = GMemory::pGlobalHeap->AllocAutoHeap_2(
           this: GMemory::pGlobalHeap,
           a2: this,
           a3: m_nSlices_low + 8,
           a4: &sizeForCurrentPage);
    *v5 = 0;
    v5[1] = m_nSlices_low;
    m_nRows = (_DWORD *)this->face_maps[0].m_nRows;
    if ( m_nRows != nullptr )
    {
      *m_nRows = v5;
      *(_DWORD *)(this->face_maps[0].m_nRows + 4) -= LOWORD(this->face_maps[0].m_nSlices);
    }
    v7 = this->face_maps[0].m_nColumns == 0;
    this->face_maps[0].m_nRows = (int)v5;
    if ( v7 )
      this->face_maps[0].m_nColumns = (int)v5;
  }
  LOWORD(this->face_maps[0].m_nSlices) = m_nSlices_low - size;
}

//------------------------------------------------------------------------------
// Address: 0x10145320
// Name: public: bool GFxPathAllocator::ReallocLastBlock(unsigned char __near *,unsigned long,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxPathAllocator::ReallocLastBlock(
        FloatCubeMap_t *this,
        unsigned __int8 *ptr,
        unsigned int oldSize,
        unsigned int newSize)
{
  int m_nRows; // edx
  int v5; // edx
  unsigned int v6; // edx

  if ( newSize < oldSize )
  {
    m_nRows = this->face_maps[0].m_nRows;
    if ( m_nRows != 0 && (int)&ptr[-m_nRows - 8] < *(_DWORD *)(m_nRows + 4) )
    {
      v5 = *(_DWORD *)(m_nRows + 4) - (_DWORD)&ptr[-m_nRows - 8];
      if ( v5 - oldSize == LOWORD(this->face_maps[0].m_nSlices) )
      {
        v6 = v5 - newSize;
        if ( v6 < 0x10000 )
          LOWORD(this->face_maps[0].m_nSlices) = v6;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10145380
// Name: public: void GFxPathPacker::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxPathPacker::Reset(GFxPathPacker *this)
{
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 1) = 0;
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 12) = 0;
  *((_WORD *)this + 26) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x101453B0
// Name: public: GFxSwfPathData::PathsIterator::PathsIterator(class GFxSwfPathData::PathsIterator const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxSwfPathData::PathsIterator::PathsIterator(
        IKMeansErrorMetric *this@<ecx>,
        const int *p,
        int a3,
        KMeansQuantizedValue *a4,
        int a5,
        int a6,
        CSOAContainer *a7)
{
  *(this + 1) = (IKMeansErrorMetric)p[1];
  *(this + 2) = (IKMeansErrorMetric)p[2];
  *(this + 3) = (IKMeansErrorMetric)p[3];
  *(this + 4) = (IKMeansErrorMetric)p[4];
  *(this + 5) = (IKMeansErrorMetric)p[5];
  *(this + 6) = (IKMeansErrorMetric)p[6];
  *(this + 7) = (IKMeansErrorMetric)p[7];
  *((_BYTE *)this + 32) = *((_BYTE *)p + 32);
  *(this + 9) = (IKMeansErrorMetric)p[9];
  *(this + 10) = (IKMeansErrorMetric)p[10];
  *(this + 11) = (IKMeansErrorMetric)p[11];
  *(this + 12) = (IKMeansErrorMetric)p[12];
  *(this + 13) = (IKMeansErrorMetric)p[13];
  *(this + 14) = (IKMeansErrorMetric)p[14];
  *(this + 15) = (IKMeansErrorMetric)p[15];
  *(this + 16) = (IKMeansErrorMetric)p[16];
  *(this + 17) = (IKMeansErrorMetric)p[17];
  *(this + 18) = (IKMeansErrorMetric)p[18];
  *(this + 19) = (IKMeansErrorMetric)p[19];
  *(this + 20) = (IKMeansErrorMetric)p[20];
  *(this + 21) = (IKMeansErrorMetric)p[21];
  *(this + 22) = (IKMeansErrorMetric)p[22];
  *(this + 23) = (IKMeansErrorMetric)p[23];
  *(this + 24) = (IKMeansErrorMetric)p[24];
  *(this + 25) = (IKMeansErrorMetric)p[25];
  *(this + 26) = (IKMeansErrorMetric)p[26];
  *(this + 27) = (IKMeansErrorMetric)p[27];
  *((_BYTE *)this + 112) = *((_BYTE *)p + 112);
}

//------------------------------------------------------------------------------
// Address: 0x10145470
// Name: private: void GFxSwfPathData::PathsIterator::ReadNext(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSwfPathData::PathsIterator::ReadNext(IKMeansErrorMetric *this)
{
  IKMeansErrorMetric *v1; // edi
  unsigned int v2; // ebx
  int v3; // edx
  IKMeansErrorMetric *v4; // esi
  int v5; // eax
  int v6; // ebx
  int v7; // eax
  int v8; // ebx
  int v9; // edx
  unsigned int v10; // edi
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  unsigned int UInt; // eax
  unsigned int v17; // eax
  unsigned int v18; // eax
  unsigned int v19; // eax
  unsigned int v20; // eax
  int v21; // eax
  unsigned int v22; // eax
  int v23; // eax
  IKMeansErrorMetric_vtbl *v24; // eax
  IKMeansErrorMetric_vtbl *v25; // edx
  int v26; // edx
  IKMeansErrorMetric_vtbl *v27; // eax
  IKMeansErrorMetric_vtbl *v28; // edx
  IKMeansErrorMetric_vtbl *v29; // eax
  IKMeansErrorMetric_vtbl *v30; // ebx
  int v31; // eax
  IKMeansErrorMetric_vtbl *v32; // eax
  int v33; // ecx
  IKMeansErrorMetric_vtbl *v34; // ecx
  IKMeansErrorMetric_vtbl *v35; // ebx
  int v36; // eax
  IKMeansErrorMetric_vtbl *v37; // ecx
  IKMeansErrorMetric_vtbl *v38; // ecx
  IKMeansErrorMetric_vtbl *v39; // ecx
  IKMeansErrorMetric_vtbl *v40; // ecx
  int v41; // eax
  int v42; // eax
  int v43; // eax
  int v44; // eax
  IKMeansErrorMetric_vtbl *v45; // ecx
  int v46; // eax
  IKMeansErrorMetric_vtbl *v47; // ecx
  int v48; // eax
  IKMeansErrorMetric_vtbl *v49; // ecx
  int v50; // eax
  IKMeansErrorMetric_vtbl *v51; // ecx
  int v52; // eax
  unsigned int v53; // ebx
  int v54; // edx
  int v55; // eax
  int v56; // eax
  int v57; // eax
  int v58; // eax
  int v59; // ecx
  int v60; // ecx
  int v61; // ecx
  int v62; // ecx
  unsigned int v63; // edi
  unsigned int v64; // eax
  int v65; // ebx
  unsigned int v66; // eax
  unsigned int v67; // eax
  unsigned int v68; // eax
  int v69; // eax
  int v70; // ecx
  int v71; // ecx
  int v72; // ecx
  int v73; // ecx
  IKMeansErrorMetric_vtbl *v74; // edx
  unsigned int v75; // ebx
  int v76; // eax
  unsigned int v77; // ecx
  unsigned int v78; // eax
  int v79; // edi
  unsigned int v80; // eax
  bool v81; // zf
  IKMeansErrorMetric_vtbl *v82; // edi
  IKMeansErrorMetric_vtbl *v83; // edx
  int v84; // eax
  unsigned int v85; // eax
  int v86; // [esp+Ch] [ebp-8h]

  v1 = this;
  v2 = *((_DWORD *)this + 4);
  v3 = *((_DWORD *)this + 3);
  v4 = this + 1;
  v5 = *(unsigned __int8 *)(v3 + *((_DWORD *)this + 1)) & (1 << (7 - v2++));
  *((_DWORD *)this + 4) = v2;
  if ( v2 >= 8 )
  {
    *((_DWORD *)this + 4) = 0;
    *((_DWORD *)this + 3) = v3 + 1;
  }
  if ( v5 == 0 )
  {
    switch ( *((_DWORD *)this + 4) )
    {
      case 0:
        v6 = *(unsigned __int8 *)(*((_DWORD *)this + 3) + *((_DWORD *)this + 1)) >> 3;
        *((_DWORD *)this + 4) = 5;
        goto LABEL_15;
      case 1:
        v6 = (*(unsigned __int8 *)(*((_DWORD *)this + 3) + *((_DWORD *)this + 1)) >> 2) & 0x1F;
        *((_DWORD *)this + 4) = 6;
        goto LABEL_15;
      case 2:
        v6 = (*(unsigned __int8 *)(*((_DWORD *)this + 3) + *((_DWORD *)this + 1)) >> 1) & 0x1F;
        *((_DWORD *)this + 4) = 7;
        goto LABEL_15;
      case 3:
        v7 = *((_DWORD *)this + 3);
        v6 = *((_BYTE *)&v4->CalculateError + v7) & 0x1F;
        *((_DWORD *)this + 4) = 0;
        goto LABEL_14;
      case 4:
        v7 = *((_DWORD *)this + 3);
        v8 = *((unsigned __int8 *)&v4->CalculateError + v7 + 1) >> 7;
        v9 = 2 * (*((_BYTE *)&v4->CalculateError + v7) & 0xF);
        *((_DWORD *)this + 4) = 1;
        goto LABEL_13;
      case 5:
        v7 = *((_DWORD *)this + 3);
        v8 = *((unsigned __int8 *)&v4->CalculateError + v7 + 1) >> 6;
        v9 = 4 * (*((_BYTE *)&v4->CalculateError + v7) & 7);
        *((_DWORD *)this + 4) = 2;
        goto LABEL_13;
      case 6:
        v7 = *((_DWORD *)this + 3);
        v8 = *((unsigned __int8 *)&v4->CalculateError + v7 + 1) >> 5;
        v9 = 8 * (*((_BYTE *)&v4->CalculateError + v7) & 3);
        *((_DWORD *)this + 4) = 3;
        goto LABEL_13;
      case 7:
        v7 = *((_DWORD *)this + 3);
        v8 = *((unsigned __int8 *)&v4->CalculateError + v7 + 1) >> 4;
        v9 = 16 * (*((_BYTE *)&v4->CalculateError + v7) & 1);
        *((_DWORD *)this + 4) = 4;
LABEL_13:
        v6 = v9 | v8;
LABEL_14:
        *((_DWORD *)this + 3) = v7 + 1;
LABEL_15:
        if ( v6 == 0 )
          goto LABEL_20;
        if ( (v6 & 1) != 0 )
        {
          *((_BYTE *)this + 32) = 3;
          if ( *((_DWORD *)this + 19) != 0 )
          {
            ++*((_DWORD *)this + 9);
            ++*((_DWORD *)this + 20);
            *((_DWORD *)this + 19) = 0;
          }
          switch ( *((_DWORD *)this + 4) )
          {
            case 0:
              v10 = *(unsigned __int8 *)(*((_DWORD *)this + 3) + *((_DWORD *)this + 1)) >> 3;
              *((_DWORD *)this + 4) = 5;
              break;
            case 1:
              v10 = (*(unsigned __int8 *)(*((_DWORD *)this + 3) + *((_DWORD *)this + 1)) >> 2) & 0x1F;
              *((_DWORD *)this + 4) = 6;
              break;
            case 2:
              v10 = (*(unsigned __int8 *)(*((_DWORD *)this + 3) + *((_DWORD *)this + 1)) >> 1) & 0x1F;
              *((_DWORD *)this + 4) = 7;
              break;
            case 3:
              v11 = *((_DWORD *)this + 3);
              v10 = *((_BYTE *)&v4->CalculateError + v11) & 0x1F;
              *((_DWORD *)this + 4) = 0;
              *((_DWORD *)this + 3) = v11 + 1;
              break;
            case 4:
              v12 = *((_DWORD *)this + 3);
              v10 = (2 * (*((_BYTE *)&v4->CalculateError + v12) & 0xF))
                  | (*((unsigned __int8 *)&v4->CalculateError + v12 + 1) >> 7);
              *((_DWORD *)this + 4) = 1;
              *((_DWORD *)this + 3) = v12 + 1;
              break;
            case 5:
              v13 = *((_DWORD *)this + 3);
              v10 = (4 * (*((_BYTE *)&v4->CalculateError + v13) & 7))
                  | (*((unsigned __int8 *)&v4->CalculateError + v13 + 1) >> 6);
              *((_DWORD *)this + 4) = 2;
              *((_DWORD *)this + 3) = v13 + 1;
              break;
            case 6:
              v14 = *((_DWORD *)this + 3);
              v10 = (8 * (*((_BYTE *)&v4->CalculateError + v14) & 3))
                  | (*((unsigned __int8 *)&v4->CalculateError + v14 + 1) >> 5);
              *((_DWORD *)this + 4) = 3;
              *((_DWORD *)this + 3) = v14 + 1;
              break;
            case 7:
              v15 = *((_DWORD *)this + 3);
              v10 = (16 * (*((_BYTE *)&v4->CalculateError + v15) & 1))
                  | (*((unsigned __int8 *)&v4->CalculateError + v15 + 1) >> 4);
              *((_DWORD *)this + 4) = 4;
              *((_DWORD *)this + 3) = v15 + 1;
              break;
            default:
              v10 = 0;
              break;
          }
          UInt = GFxStreamContext::ReadUInt(this: (GFxStreamContext *)v4, a2: v10);
          v86 = 1 << (v10 - 1);
          if ( (UInt & v86) != 0 )
            UInt |= -1 << v10;
          *((_DWORD *)this + 11) = UInt;
          v17 = GFxStreamContext::ReadUInt(this: (GFxStreamContext *)v4, a2: v10);
          if ( (v17 & v86) != 0 )
            v17 |= -1 << v10;
          *((_DWORD *)this + 12) = v17;
          v1 = this;
        }
        if ( (v6 & 2) != 0 )
        {
          v18 = (unsigned int)v1[17].__vftable;
          if ( v18 != 0 )
          {
            LOBYTE(v1[8].__vftable) = 3;
            if ( v1[19].__vftable != nullptr )
            {
              ++v1[9].__vftable;
              ++v1[20].__vftable;
              v1[19].__vftable = nullptr;
            }
            v19 = GFxStreamContext::ReadUInt(this: (GFxStreamContext *)v4, a2: v18);
            if ( v19 != 0 )
              v19 += *((_DWORD *)this + 13);
            *((_DWORD *)this + 5) = v19;
            v1 = this;
          }
        }
        if ( (v6 & 4) != 0 )
        {
          v20 = (unsigned int)v1[17].__vftable;
          if ( v20 != 0 )
          {
            LOBYTE(v1[8].__vftable) = 3;
            if ( v1[19].__vftable != nullptr )
            {
              ++v1[9].__vftable;
              ++v1[20].__vftable;
              v1[19].__vftable = nullptr;
            }
            v21 = GFxStreamContext::ReadUInt(this: (GFxStreamContext *)v4, a2: v20);
            if ( v21 > 0 )
              v21 += *((_DWORD *)this + 13);
            *((_DWORD *)this + 6) = v21;
            v1 = this;
          }
        }
        if ( (v6 & 8) != 0 )
        {
          v22 = (unsigned int)v1[18].__vftable;
          if ( v22 != 0 )
          {
            LOBYTE(v1[8].__vftable) = 3;
            if ( v1[19].__vftable != nullptr )
            {
              ++v1[9].__vftable;
              ++v1[20].__vftable;
              v1[19].__vftable = nullptr;
            }
            v23 = GFxStreamContext::ReadUInt(this: (GFxStreamContext *)v4, a2: v22);
            if ( v23 > 0 )
              v23 += *((_DWORD *)this + 14);
            *((_DWORD *)this + 7) = v23;
            v1 = this;
          }
        }
        if ( (v6 & 0x10) != 0 )
        {
          LOBYTE(v1[8].__vftable) = 2;
          if ( v1[20].__vftable != nullptr )
          {
            ++v1[10].__vftable;
            v1[20].__vftable = nullptr;
          }
          if ( v1[19].__vftable != nullptr )
          {
            ++v1[9].__vftable;
            ++v1[20].__vftable;
            v1[19].__vftable = nullptr;
          }
          v1[7].__vftable = nullptr;
          v1[6].__vftable = nullptr;
          v1[5].__vftable = nullptr;
          if ( v4[3].__vftable != nullptr )
            ++v4[2].__vftable;
          v4[3].__vftable = nullptr;
          v24 = v4[2].__vftable;
          v25 = v4->__vftable;
          v4[3].__vftable = nullptr;
          v26 = *((unsigned __int8 *)&v25->CalculateError + (_DWORD)v24);
          v4[2].__vftable = (IKMeansErrorMetric_vtbl *)((char *)&v24->CalculateError + 1);
          if ( v26 == 255 && ((int)v1[28].__vftable & 4) != 0 )
          {
            v27 = v4[2].__vftable;
            v28 = v4->__vftable;
            v4[3].__vftable = nullptr;
            v26 = *(unsigned __int16 *)((char *)&v27->CalculateError + (_DWORD)v28);
            v4[2].__vftable = (IKMeansErrorMetric_vtbl *)((char *)&v27->CalculateError + 2);
          }
          if ( v4[3].__vftable != nullptr )
            ++v4[2].__vftable;
          v29 = v4[2].__vftable;
          v30 = v4->__vftable;
          v4[3].__vftable = nullptr;
          LOBYTE(v30) = *((_BYTE *)&v30->CalculateError + (_DWORD)v29);
          v4[2].__vftable = (IKMeansErrorMetric_vtbl *)((char *)&v29->CalculateError + 1);
          v31 = (unsigned __int8)v30;
          if ( (unsigned __int8)v30 == 255 )
          {
            v32 = v4[2].__vftable;
            v4[3].__vftable = nullptr;
            v33 = *(unsigned __int16 *)((char *)&v4->CalculateError + (unsigned int)v32);
            v4[2].__vftable = (IKMeansErrorMetric_vtbl *)((char *)&v32->CalculateError + 2);
            v31 = v33;
          }
          v34 = v1[15].__vftable;
          v35 = v1[16].__vftable;
          v1[14].__vftable = v35;
          v1[13].__vftable = v34;
          v1[16].__vftable = (IKMeansErrorMetric_vtbl *)((char *)v35 + v31);
          v1[15].__vftable = (IKMeansErrorMetric_vtbl *)((char *)v34 + v26);
          switch ( (unsigned int)v4[3].__vftable )
          {
            case 0u:
              v36 = *((unsigned __int8 *)&v4[2].CalculateError + (unsigned int)v4->__vftable) >> 4;
              v4[3].__vftable = (IKMeansErrorMetric_vtbl *)4;
              break;
            case 1u:
              v36 = (*((unsigned __int8 *)&v4[2].CalculateError + (unsigned int)v4->__vftable) >> 3) & 0xF;
              v4[3].__vftable = (IKMeansErrorMetric_vtbl *)5;
              break;
            case 2u:
              v36 = (*((unsigned __int8 *)&v4[2].CalculateError + (unsigned int)v4->__vftable) >> 2) & 0xF;
              v4[3].__vftable = (IKMeansErrorMetric_vtbl *)6;
              break;
            case 3u:
              v36 = (*((unsigned __int8 *)&v4[2].CalculateError + (unsigned int)v4->__vftable) >> 1) & 0xF;
              v4[3].__vftable = (IKMeansErrorMetric_vtbl *)7;
              break;
            case 4u:
              v37 = v4[2].__vftable;
              v36 = *((_BYTE *)&v37->CalculateError + (unsigned int)v4->__vftable) & 0xF;
              v4[3].__vftable = nullptr;
              v4[2].__vftable = (IKMeansErrorMetric_vtbl *)((char *)&v37->CalculateError + 1);
              break;
            case 5u:
              v38 = v4[2].__vftable;
              v36 = (*((unsigned __int8 *)&v38->CalculateError + (unsigned int)v4->__vftable + 1) >> 7)
                  | (2 * (*((_BYTE *)&v38->CalculateError + (unsigned int)v4->__vftable) & 7));
              v4[3].__vftable = (IKMeansErrorMetric_vtbl *)1;
              v4[2].__vftable = (IKMeansErrorMetric_vtbl *)((char *)&v38->CalculateError + 1);
              break;
            case 6u:
              v39 = v4[2].__vftable;
              v36 = (*((unsigned __int8 *)&v39->CalculateError + (unsigned int)v4->__vftable + 1) >> 6)
                  | (4 * (*((_BYTE *)&v39->CalculateError + (unsigned int)v4->__vftable) & 3));
              v4[3].__vftable = (IKMeansErrorMetric_vtbl *)2;
              v4[2].__vftable = (IKMeansErrorMetric_vtbl *)((char *)&v39->CalculateError + 1);
              break;
            case 7u:
              v40 = v4[2].__vftable;
              v36 = (*((unsigned __int8 *)&v40->CalculateError + (unsigned int)v4->__vftable + 1) >> 5)
                  | (8 * (*((_BYTE *)&v40->CalculateError + (unsigned int)v4->__vftable) & 1));
              v4[3].__vftable = (IKMeansErrorMetric_vtbl *)3;
              v4[2].__vftable = (IKMeansErrorMetric_vtbl *)((char *)&v40->CalculateError + 1);
              break;
            default:
              v36 = 0;
              break;
          }
          v1[17].__vftable = (IKMeansErrorMetric_vtbl *)v36;
          switch ( (unsigned int)v4[3].__vftable )
          {
            case 0u:
              v41 = *((unsigned __int8 *)&v4[2].CalculateError + (unsigned int)v4->__vftable) >> 4;
              v4[3].__vftable = (IKMeansErrorMetric_vtbl *)4;
              v1[18].__vftable = (IKMeansErrorMetric_vtbl *)v41;
              break;
            case 1u:
              v42 = (*((unsigned __int8 *)&v4[2].CalculateError + (unsigned int)v4->__vftable) >> 3) & 0xF;
              v4[3].__vftable = (IKMeansErrorMetric_vtbl *)5;
              v1[18].__vftable = (IKMeansErrorMetric_vtbl *)v42;
              break;
            case 2u:
              v43 = (*((unsigned __int8 *)&v4[2].CalculateError + (unsigned int)v4->__vftable) >> 2) & 0xF;
              v4[3].__vftable = (IKMeansErrorMetric_vtbl *)6;
              v1[18].__vftable = (IKMeansErrorMetric_vtbl *)v43;
              break;
            case 3u:
              v44 = *((unsigned __int8 *)&v4[2].CalculateError + (unsigned int)v4->__vftable) >> 1;
              v4[3].__vftable = (IKMeansErrorMetric_vtbl *)7;
              v1[18].__vftable = (IKMeansErrorMetric_vtbl *)(v44 & 0xF);
              break;
            case 4u:
              v45 = v4[2].__vftable;
              v46 = *((_BYTE *)&v45->CalculateError + (unsigned int)v4->__vftable) & 0xF;
              v4[3].__vftable = nullptr;
              v4[2].__vftable = (IKMeansErrorMetric_vtbl *)((char *)&v45->CalculateError + 1);
              v1[18].__vftable = (IKMeansErrorMetric_vtbl *)v46;
              break;
            case 5u:
              v47 = v4[2].__vftable;
              v48 = (*((unsigned __int8 *)&v47->CalculateError + (unsigned int)v4->__vftable + 1) >> 7)
                  | (2 * (*((_BYTE *)&v47->CalculateError + (unsigned int)v4->__vftable) & 7));
              v4[3].__vftable = (IKMeansErrorMetric_vtbl *)1;
              v4[2].__vftable = (IKMeansErrorMetric_vtbl *)((char *)&v47->CalculateError + 1);
              v1[18].__vftable = (IKMeansErrorMetric_vtbl *)v48;
              break;
            case 6u:
              v49 = v4[2].__vftable;
              v50 = (*((unsigned __int8 *)&v49->CalculateError + (unsigned int)v4->__vftable + 1) >> 6)
                  | (4 * (*((_BYTE *)&v49->CalculateError + (unsigned int)v4->__vftable) & 3));
              v4[3].__vftable = (IKMeansErrorMetric_vtbl *)2;
              v4[2].__vftable = (IKMeansErrorMetric_vtbl *)((char *)&v49->CalculateError + 1);
              v1[18].__vftable = (IKMeansErrorMetric_vtbl *)v50;
              break;
            case 7u:
              v51 = v4[2].__vftable;
              v52 = (*((unsigned __int8 *)&v51->CalculateError + (unsigned int)v4->__vftable + 1) >> 5)
                  | (8 * (*((_BYTE *)&v51->CalculateError + (unsigned int)v4->__vftable) & 1));
              v4[3].__vftable = (IKMeansErrorMetric_vtbl *)3;
              v4[2].__vftable = (IKMeansErrorMetric_vtbl *)((char *)&v51->CalculateError + 1);
              v1[18].__vftable = (IKMeansErrorMetric_vtbl *)v52;
              break;
            default:
              v1[18].__vftable = nullptr;
              break;
          }
        }
        break;
      default:
LABEL_20:
        *((_BYTE *)this + 32) = 1;
        if ( *((_DWORD *)this + 19) != 0 )
        {
          ++*((_DWORD *)this + 9);
          ++*((_DWORD *)this + 20);
          *((_DWORD *)this + 19) = 0;
        }
        break;
    }
    return;
  }
  v53 = *((_DWORD *)this + 4);
  v54 = *((_DWORD *)this + 3);
  v55 = 1 << (7 - v53++);
  v56 = (unsigned __int8)(*((_BYTE *)&v4->CalculateError + v54) & v55);
  *((_DWORD *)this + 4) = v53;
  if ( v53 >= 8 )
  {
    *((_DWORD *)this + 4) = 0;
    *((_DWORD *)this + 3) = v54 + 1;
  }
  ++*((_DWORD *)this + 19);
  v81 = v56 == 0;
  v57 = *((_DWORD *)this + 4);
  if ( v81 )
  {
    switch ( v57 )
    {
      case 0:
        v58 = *(unsigned __int8 *)(*((_DWORD *)this + 3) + *((_DWORD *)this + 1)) >> 4;
        *((_DWORD *)this + 4) = 4;
        break;
      case 1:
        v58 = (*(unsigned __int8 *)(*((_DWORD *)this + 3) + *((_DWORD *)this + 1)) >> 3) & 0xF;
        *((_DWORD *)this + 4) = 5;
        break;
      case 2:
        v58 = (*(unsigned __int8 *)(*((_DWORD *)this + 3) + *((_DWORD *)this + 1)) >> 2) & 0xF;
        *((_DWORD *)this + 4) = 6;
        break;
      case 3:
        v58 = (*(unsigned __int8 *)(*((_DWORD *)this + 3) + *((_DWORD *)this + 1)) >> 1) & 0xF;
        *((_DWORD *)this + 4) = 7;
        break;
      case 4:
        v59 = *((_DWORD *)this + 3);
        v58 = *((_BYTE *)&v4->CalculateError + v59) & 0xF;
        v4[3].__vftable = nullptr;
        v4[2].__vftable = (IKMeansErrorMetric_vtbl *)(v59 + 1);
        break;
      case 5:
        v60 = *((_DWORD *)this + 3);
        v58 = (*((unsigned __int8 *)&v4->CalculateError + v60 + 1) >> 7)
            | (2 * (*((_BYTE *)&v4->CalculateError + v60) & 7));
        v4[3].__vftable = (IKMeansErrorMetric_vtbl *)1;
        v4[2].__vftable = (IKMeansErrorMetric_vtbl *)(v60 + 1);
        break;
      case 6:
        v61 = *((_DWORD *)this + 3);
        v58 = (*((unsigned __int8 *)&v4->CalculateError + v61 + 1) >> 6)
            | (4 * (*((_BYTE *)&v4->CalculateError + v61) & 3));
        v4[3].__vftable = (IKMeansErrorMetric_vtbl *)2;
        v4[2].__vftable = (IKMeansErrorMetric_vtbl *)(v61 + 1);
        break;
      case 7:
        v62 = *((_DWORD *)this + 3);
        v58 = (*((unsigned __int8 *)&v4->CalculateError + v62 + 1) >> 5)
            | (8 * (*((_BYTE *)&v4->CalculateError + v62) & 1));
        v4[3].__vftable = (IKMeansErrorMetric_vtbl *)3;
        v4[2].__vftable = (IKMeansErrorMetric_vtbl *)(v62 + 1);
        break;
      default:
        v58 = 0;
        break;
    }
    v63 = v58 + 2;
    v64 = GFxStreamContext::ReadUInt(this: (GFxStreamContext *)v4, a2: v58 + 2);
    v65 = 1 << (v63 - 1);
    if ( (v64 & v65) != 0 )
      v64 |= -1 << v63;
    *((_DWORD *)this + 23) = v64;
    v66 = GFxStreamContext::ReadUInt(this: (GFxStreamContext *)v4, a2: v63);
    if ( (v66 & v65) != 0 )
      v66 |= -1 << v63;
    *((_DWORD *)this + 24) = v66;
    v67 = GFxStreamContext::ReadUInt(this: (GFxStreamContext *)v4, a2: v63);
    if ( (v67 & v65) != 0 )
      v67 |= -1 << v63;
    *((_DWORD *)this + 21) = v67;
    v68 = GFxStreamContext::ReadUInt(this: (GFxStreamContext *)v4, a2: v63);
    if ( (v68 & v65) != 0 )
      v68 |= -1 << v63;
    *((_DWORD *)this + 22) = v68;
    *((_BYTE *)this + 32) = -123;
    return;
  }
  switch ( v57 )
  {
    case 0:
      v69 = *(unsigned __int8 *)(*((_DWORD *)this + 3) + *((_DWORD *)this + 1)) >> 4;
      *((_DWORD *)this + 4) = 4;
      break;
    case 1:
      v69 = (*(unsigned __int8 *)(*((_DWORD *)this + 3) + *((_DWORD *)this + 1)) >> 3) & 0xF;
      *((_DWORD *)this + 4) = 5;
      break;
    case 2:
      v69 = (*(unsigned __int8 *)(*((_DWORD *)this + 3) + *((_DWORD *)this + 1)) >> 2) & 0xF;
      *((_DWORD *)this + 4) = 6;
      break;
    case 3:
      v69 = (*(unsigned __int8 *)(*((_DWORD *)this + 3) + *((_DWORD *)this + 1)) >> 1) & 0xF;
      *((_DWORD *)this + 4) = 7;
      break;
    case 4:
      v70 = *((_DWORD *)this + 3);
      v69 = *((_BYTE *)&v4->CalculateError + v70) & 0xF;
      v4[3].__vftable = nullptr;
      v4[2].__vftable = (IKMeansErrorMetric_vtbl *)(v70 + 1);
      break;
    case 5:
      v71 = *((_DWORD *)this + 3);
      v69 = (*((unsigned __int8 *)&v4->CalculateError + v71 + 1) >> 7)
          | (2 * (*((_BYTE *)&v4->CalculateError + v71) & 7));
      v4[3].__vftable = (IKMeansErrorMetric_vtbl *)1;
      v4[2].__vftable = (IKMeansErrorMetric_vtbl *)(v71 + 1);
      break;
    case 6:
      v72 = *((_DWORD *)this + 3);
      v69 = (*((unsigned __int8 *)&v4->CalculateError + v72 + 1) >> 6)
          | (4 * (*((_BYTE *)&v4->CalculateError + v72) & 3));
      v4[3].__vftable = (IKMeansErrorMetric_vtbl *)2;
      v4[2].__vftable = (IKMeansErrorMetric_vtbl *)(v72 + 1);
      break;
    case 7:
      v73 = *((_DWORD *)this + 3);
      v69 = (*((unsigned __int8 *)&v4->CalculateError + v73 + 1) >> 5)
          | (8 * (*((_BYTE *)&v4->CalculateError + v73) & 1));
      v4[3].__vftable = (IKMeansErrorMetric_vtbl *)3;
      v4[2].__vftable = (IKMeansErrorMetric_vtbl *)(v73 + 1);
      break;
    default:
      v69 = 0;
      break;
  }
  v74 = v4[2].__vftable;
  v75 = v69 + 2;
  v76 = *((unsigned __int8 *)&v74->CalculateError + (unsigned int)v4->__vftable) & (1 << (7 - LOBYTE(v4[3].__vftable)));
  v77 = (unsigned int)&v4[3].CalculateError + 1;
  v4[3].__vftable = (IKMeansErrorMetric_vtbl *)v77;
  if ( v77 >= 8 )
  {
    v4[3].__vftable = nullptr;
    v4[2].__vftable = (IKMeansErrorMetric_vtbl *)((char *)&v74->CalculateError + 1);
  }
  v1[25].__vftable = nullptr;
  v1[26].__vftable = nullptr;
  if ( v76 != 0 )
  {
    v78 = GFxStreamContext::ReadUInt(this: (GFxStreamContext *)v4, a2: v75);
    v79 = 1 << (v75 - 1);
    if ( (v79 & v78) != 0 )
      v78 |= -1 << v75;
    *((_DWORD *)this + 25) = v78;
    v80 = GFxStreamContext::ReadUInt(this: (GFxStreamContext *)v4, a2: v75);
    v81 = (v79 & v80) == 0;
    goto LABEL_136;
  }
  v82 = v4[3].__vftable;
  v83 = v4[2].__vftable;
  v84 = *((unsigned __int8 *)&v83->CalculateError + (unsigned int)v4->__vftable) & (1 << (7 - (_BYTE)v82));
  v4[3].__vftable = (IKMeansErrorMetric_vtbl *)((char *)&v82->CalculateError + 1);
  if ( (unsigned int)&v82->CalculateError + 1 >= 8 )
  {
    v4[3].__vftable = nullptr;
    v4[2].__vftable = (IKMeansErrorMetric_vtbl *)((char *)&v83->CalculateError + 1);
  }
  if ( v84 != 0 )
  {
    v80 = GFxStreamContext::ReadUInt(this: (GFxStreamContext *)v4, a2: v75);
    v81 = ((1 << (v75 - 1)) & v80) == 0;
LABEL_136:
    if ( !v81 )
      v80 |= -1 << v75;
    *((_DWORD *)this + 26) = v80;
    *((_BYTE *)this + 32) = -124;
    return;
  }
  v85 = GFxStreamContext::ReadUInt(this: (GFxStreamContext *)v4, a2: v75);
  if ( ((1 << (v75 - 1)) & v85) != 0 )
    v85 |= -1 << v75;
  *((_DWORD *)this + 25) = v85;
  *((_BYTE *)this + 32) = -124;
}

//------------------------------------------------------------------------------
// Address: 0x10145FF0
// Name: public: void GFxSwfPathData::EdgesIterator::GetMoveXY(float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxSwfPathData::EdgesIterator::GetMoveXY(
        CSOAContainer *this@<ecx>,
        float *px,
        float *py,
        int a4,
        int a5,
        const CSOAContainer *a6,
        int a7,
        int a8)
{
  int m_nColumns; // eax

  m_nColumns = this->m_nColumns;
  *px = (float)*(int *)(this->m_nColumns + 44);
  *py = (float)*(int *)(m_nColumns + 48);
  if ( *(char *)(m_nColumns + 112) < 0 )
  {
    *px = *px * *(float *)(m_nColumns + 108);
    *py = *(float *)(m_nColumns + 108) * *py;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10146020
// Name: public: void GFxSwfPathData::EdgesIterator::GetEdge(struct GFxSwfPathData::EdgesIterator::Edge __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSwfPathData::EdgesIterator::GetEdge(
        GFxSwfPathData::EdgesIterator *this,
        struct GFxSwfPathData::EdgesIterator::Edge *a2,
        bool a3)
{
  CSOAContainer *m_pContainer; // edx
  CSOAContainer *v4; // edx

  m_pContainer = this->m_opA.m_pContainer;
  if ( LOBYTE(this->m_opA.m_pContainer->m_pAttributePtrs[2]) == 132 )
  {
    *((float *)a2 + 2) = (float)(unsigned int)&m_pContainer->m_pAttributePtrs[5][(unsigned int)m_pContainer->m_pAttributePtrs[19]];
    *((float *)a2 + 3) = (float)(unsigned int)&this->m_opA.m_pContainer->m_pAttributePtrs[6][(unsigned int)this->m_opA.m_pContainer->m_pAttributePtrs[20]];
    v4 = this->m_opA.m_pContainer;
    if ( a3 )
    {
      *(float *)a2 = (double)(int)v4->m_pAttributePtrs[19] * 0.5 + (double)(int)v4->m_pAttributePtrs[5];
      *((float *)a2 + 1) = 0.5 * (double)(int)this->m_opA.m_pContainer->m_pAttributePtrs[20]
                         + (double)(int)this->m_opA.m_pContainer->m_pAttributePtrs[6];
      if ( SLOBYTE(this->m_opA.m_pContainer->m_pAttributePtrs[22]) < 0 )
      {
        *(float *)a2 = *(float *)&this->m_opA.m_pContainer->m_pAttributePtrs[21] * *(float *)a2;
        *((float *)a2 + 1) = *(float *)&this->m_opA.m_pContainer->m_pAttributePtrs[21] * *((float *)a2 + 1);
        *((float *)a2 + 2) = *(float *)&this->m_opA.m_pContainer->m_pAttributePtrs[21] * *((float *)a2 + 2);
        *((float *)a2 + 3) = *(float *)&this->m_opA.m_pContainer->m_pAttributePtrs[21] * *((float *)a2 + 3);
      }
      *((_BYTE *)a2 + 16) = 1;
    }
    else
    {
      if ( SLOBYTE(v4->m_pAttributePtrs[22]) < 0 )
      {
        *((float *)a2 + 2) = *(float *)&v4->m_pAttributePtrs[21] * *((float *)a2 + 2);
        *((float *)a2 + 3) = *(float *)&this->m_opA.m_pContainer->m_pAttributePtrs[21] * *((float *)a2 + 3);
      }
      *((_BYTE *)a2 + 16) = 0;
    }
    this->m_opA.m_pContainer->m_pAttributePtrs[5] += (unsigned int)this->m_opA.m_pContainer->m_pAttributePtrs[19];
    this->m_opA.m_pContainer->m_pAttributePtrs[6] += (unsigned int)this->m_opA.m_pContainer->m_pAttributePtrs[20];
    goto LABEL_14;
  }
  if ( LOBYTE(this->m_opA.m_pContainer->m_pAttributePtrs[2]) != 133 )
  {
LABEL_14:
    ++this->m_opA.m_nAttributeID;
    GFxSwfPathData::PathsIterator::ReadNext(this: (IKMeansErrorMetric *)this->m_opA.m_pContainer);
    return;
  }
  *(float *)a2 = (float)(unsigned int)&m_pContainer->m_pAttributePtrs[5][(unsigned int)m_pContainer->m_pAttributePtrs[17]];
  *((float *)a2 + 1) = (float)(unsigned int)&this->m_opA.m_pContainer->m_pAttributePtrs[6][(unsigned int)this->m_opA.m_pContainer->m_pAttributePtrs[18]];
  this->m_opA.m_pContainer->m_pAttributePtrs[5] += (unsigned int)&this->m_opA.m_pContainer->m_pAttributePtrs[15][(unsigned int)this->m_opA.m_pContainer->m_pAttributePtrs[17]];
  this->m_opA.m_pContainer->m_pAttributePtrs[6] += (unsigned int)&this->m_opA.m_pContainer->m_pAttributePtrs[16][(unsigned int)this->m_opA.m_pContainer->m_pAttributePtrs[18]];
  *((float *)a2 + 2) = (float)(int)this->m_opA.m_pContainer->m_pAttributePtrs[5];
  *((float *)a2 + 3) = (float)(int)this->m_opA.m_pContainer->m_pAttributePtrs[6];
  if ( SLOBYTE(this->m_opA.m_pContainer->m_pAttributePtrs[22]) < 0 )
  {
    *(float *)a2 = *(float *)&this->m_opA.m_pContainer->m_pAttributePtrs[21] * *(float *)a2;
    *((float *)a2 + 1) = *(float *)&this->m_opA.m_pContainer->m_pAttributePtrs[21] * *((float *)a2 + 1);
    *((float *)a2 + 2) = *(float *)&this->m_opA.m_pContainer->m_pAttributePtrs[21] * *((float *)a2 + 2);
    *((float *)a2 + 3) = *(float *)&this->m_opA.m_pContainer->m_pAttributePtrs[21] * *((float *)a2 + 3);
  }
  *((_BYTE *)a2 + 16) = 1;
  ++this->m_opA.m_nAttributeID;
  GFxSwfPathData::PathsIterator::ReadNext(this: (IKMeansErrorMetric *)this->m_opA.m_pContainer);
}

//------------------------------------------------------------------------------
// Address: 0x10146190
// Name: public: void GFxSwfPathData::EdgesIterator::GetPlainEdge(struct GFxSwfPathData::EdgesIterator::PlainEdge __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSwfPathData::EdgesIterator::GetPlainEdge(
        IKMeansErrorMetric **this,
        CSOAAttributeReferenceBinaryOp<&SubSIMD> *result)
{
  IKMeansErrorMetric *v2; // esi
  CSOAAttributeReferenceBinaryOp<&SubSIMD> *p_m_opB; // eax
  IKMeansErrorMetric *v4; // esi
  int v5; // edi

  v2 = *this;
  p_m_opB = result;
  if ( LOBYTE((*this)[8].__vftable) == 132 )
  {
    result->m_opA.m_pContainer = (CSOAContainer *)v2[25].__vftable;
    result->m_opA.m_nAttributeID = (int)(*this)[26].__vftable;
    p_m_opB = (CSOAAttributeReferenceBinaryOp<&SubSIMD> *)&result->m_opB;
    (*this)[11].__vftable = (IKMeansErrorMetric_vtbl *)((char *)(*this)[11].__vftable
                                                      + (unsigned int)(*this)[25].__vftable);
    v4 = *this;
    v5 = (int)(*this)[26].__vftable;
    goto LABEL_5;
  }
  if ( LOBYTE((*this)[8].__vftable) == 133 )
  {
    result->m_opA.m_pContainer = (CSOAContainer *)v2[23].__vftable;
    result->m_opA.m_nAttributeID = (int)(*this)[24].__vftable;
    result->m_opB = *(CSOAAttributeReference *)&(*this)[21].__vftable;
    p_m_opB = result + 1;
    (*this)[11].__vftable = (IKMeansErrorMetric_vtbl *)((char *)(*this)[11].__vftable
                                                      + (unsigned int)(*this)[21].__vftable
                                                      + (unsigned int)(*this)[23].__vftable);
    v4 = *this;
    v5 = (int)(*this)[22].__vftable + (unsigned int)(*this)[24].__vftable;
LABEL_5:
    v4[12].__vftable = (IKMeansErrorMetric_vtbl *)((char *)v4[12].__vftable + v5);
  }
  result[1].m_opA.m_pContainer = (CSOAContainer *)(((char *)p_m_opB - (char *)result) >> 2);
  *(this + 1) = (IKMeansErrorMetric *)((char *)*(this + 1) + 1);
  GFxSwfPathData::PathsIterator::ReadNext(this: *this);
}

//------------------------------------------------------------------------------
// Address: 0x10146220
// Name: public: static void GFxSwfPathData::GetShapeAndPathCounts(unsigned char const __near *,unsigned int __near *,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSwfPathData::GetShapeAndPathCounts(
        GFxJpegSupportBase *ppaths,
        unsigned __int8 *a2,
        unsigned int *pshapesCnt,
        unsigned int *ppathsCnt)
{
  unsigned int v4; // eax
  unsigned int v5; // esi
  char v6; // cl
  int v7; // edi
  unsigned int v8; // edx
  unsigned int v9; // eax
  int v10; // ebx
  unsigned __int8 *v11; // edi
  unsigned int v12; // edx
  unsigned int v13; // eax
  int i; // ecx
  int v15; // ebx
  unsigned __int8 *v16; // edi
  unsigned int v17; // edx
  unsigned int v18; // eax
  int j; // ecx
  int v20; // ebx
  int v21; // [esp+Ch] [ebp-4h]

  v4 = *a2;
  v5 = ((v4 >> 5) & 3) + 1;
  v6 = 0;
  v7 = 0;
  v8 = 0;
  v9 = ((v4 >> 3) & 3) + 1;
  v21 = 0;
  if ( v9 != 0 )
  {
    do
    {
      v10 = a2[++v8] << v6;
      v6 = v21 + 8;
      v7 |= v10;
      v21 += 8;
    }
    while ( v8 < v9 );
  }
  v11 = &a2[v7 - 2 * v5];
  if ( pshapesCnt != nullptr )
  {
    v12 = 0;
    v13 = 0;
    for ( i = 0; v13 < v5; v12 |= v15 )
    {
      v15 = v11[v13++] << i;
      i += 8;
    }
    *pshapesCnt = v12;
  }
  v16 = &v11[v5];
  if ( ppathsCnt != nullptr )
  {
    v17 = 0;
    v18 = 0;
    for ( j = 0; v18 < v5; v17 |= v20 )
    {
      v20 = v16[v18++] << j;
      j += 8;
    }
    *ppathsCnt = v17;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101462D0
// Name: public: virtual void GFxShapeNoStyles::GetShapeAndPathCounts(unsigned int __near *,unsigned int __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxShapeNoStyles::GetShapeAndPathCounts(
        GFxShapeNoStyles *this,
        unsigned int *pshapesCnt,
        unsigned int *ppathsCnt)
{
  if ( pshapesCnt != nullptr )
    *pshapesCnt = *((_DWORD *)this + 15);
  if ( ppathsCnt != nullptr )
    *ppathsCnt = *((_DWORD *)this + 14);
}

//------------------------------------------------------------------------------
// Address: 0x101462F0
// Name: public: void GFxPathData::EdgesIterator::GetEdge(struct GFxPathData::EdgesIterator::Edge __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxPathData::EdgesIterator::GetEdge(
        CSOAContainer *this@<ecx>,
        const CSOAContainer *pedge,
        char doLines2CurveConv,
        int ax,
        int ay,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11)
{
  unsigned __int8 *v11; // eax
  unsigned __int8 *v12; // edx
  int v13; // eax
  unsigned __int8 *v14; // esi
  int v15; // edx
  int v16; // edi
  int v17; // edi
  double v18; // st7
  unsigned __int8 *v19; // eax
  int v20; // edx
  int v21; // esi
  double v22; // st7
  unsigned __int8 *v23; // eax
  unsigned __int8 *v24; // edx
  unsigned __int8 *v25; // esi
  unsigned __int8 *v26; // eax
  int v27; // [esp+4h] [ebp-8h]
  int aya; // [esp+8h] [ebp-4h]
  int ayb; // [esp+8h] [ebp-4h]

  if ( this->m_nRows < (unsigned int)this->m_nSlices )
  {
    v11 = this->m_pAttributePtrs[1];
    if ( v11 != nullptr )
    {
      if ( this->m_pAttributePtrs[0] > (unsigned __int8 *)0x8000 )
      {
        this->m_pDataMemory = (unsigned __int8 *)*(__int16 *)v11;
        this->m_pAttributePtrs[1] = v11 + 2;
        this->m_pAttributePtrs[0] = (unsigned __int8 *)1;
      }
      if ( ((int)this->m_pDataMemory & (int)this->m_pAttributePtrs[0]) != 0 )
      {
        v12 = this->m_pAttributePtrs[1];
        v13 = *(__int16 *)v12;
        v14 = v12 + 2;
        this->m_pAttributePtrs[1] = v12 + 2;
        v15 = *((__int16 *)v12 + 1);
        v14 += 2;
        this->m_pAttributePtrs[1] = v14;
        v16 = *(__int16 *)v14;
        v14 += 2;
        this->m_pAttributePtrs[1] = v14;
        aya = *(__int16 *)v14;
        this->m_pAttributePtrs[1] = v14 + 2;
LABEL_7:
        *(float *)&pedge->m_nColumns = (double)(v13 + this->m_nPaddedColumns) * *(float *)&this->m_pAttributePtrs[3];
        v17 = v13 + v16;
        *(float *)&pedge->m_nRows = (double)(v15 + this->m_nNumQuadsPerRow) * *(float *)&this->m_pAttributePtrs[3];
        *(float *)&pedge->m_nSlices = (double)(this->m_nPaddedColumns + v17) * *(float *)&this->m_pAttributePtrs[3];
        v18 = (double)(v15 + aya + this->m_nNumQuadsPerRow) * *(float *)&this->m_pAttributePtrs[3];
        LOBYTE(pedge->m_nNumQuadsPerRow) = 1;
        *(float *)&pedge->m_nPaddedColumns = v18;
        this->m_nPaddedColumns += v17;
        ++this->m_nRows;
        this->m_nNumQuadsPerRow += v15 + aya;
        this->m_pAttributePtrs[0] = (unsigned __int8 *)((int)this->m_pAttributePtrs[0] * 2);
        return;
      }
      v19 = this->m_pAttributePtrs[1];
      v20 = *(__int16 *)v19;
      v19 += 2;
      this->m_pAttributePtrs[1] = v19;
      v21 = *(__int16 *)v19;
      v27 = v20;
      ayb = v21;
      this->m_pAttributePtrs[1] = v19 + 2;
    }
    else
    {
      if ( this->m_pAttributePtrs[0] == nullptr )
      {
        v23 = this->m_pAttributePtrs[2];
        this->m_pDataMemory = *(unsigned __int8 **)v23;
        this->m_pAttributePtrs[2] = v23 + 4;
        this->m_pAttributePtrs[0] = (unsigned __int8 *)1;
      }
      if ( ((int)this->m_pDataMemory & (int)this->m_pAttributePtrs[0]) != 0 )
      {
        v24 = this->m_pAttributePtrs[2];
        v13 = *(_DWORD *)v24;
        v25 = v24 + 4;
        this->m_pAttributePtrs[2] = v24 + 4;
        v15 = *((_DWORD *)v24 + 1);
        v25 += 4;
        this->m_pAttributePtrs[2] = v25;
        v16 = *(_DWORD *)v25;
        v25 += 4;
        this->m_pAttributePtrs[2] = v25;
        aya = *(_DWORD *)v25;
        this->m_pAttributePtrs[2] = v25 + 4;
        goto LABEL_7;
      }
      v26 = this->m_pAttributePtrs[2];
      v20 = *(_DWORD *)v26;
      v26 += 4;
      this->m_pAttributePtrs[2] = v26;
      v21 = *(_DWORD *)v26;
      v27 = v20;
      ayb = *(_DWORD *)v26;
      this->m_pAttributePtrs[2] = v26 + 4;
    }
    *(float *)&pedge->m_nSlices = (double)(v20 + this->m_nPaddedColumns) * *(float *)&this->m_pAttributePtrs[3];
    *(float *)&pedge->m_nPaddedColumns = (double)(v21 + this->m_nNumQuadsPerRow) * *(float *)&this->m_pAttributePtrs[3];
    if ( doLines2CurveConv != 0 )
    {
      *(float *)&pedge->m_nColumns = ((double)v27 * 0.5 + (double)this->m_nPaddedColumns)
                                   * *(float *)&this->m_pAttributePtrs[3];
      v22 = (0.5 * (double)ayb + (double)this->m_nNumQuadsPerRow) * *(float *)&this->m_pAttributePtrs[3];
      LOBYTE(pedge->m_nNumQuadsPerRow) = 1;
      *(float *)&pedge->m_nRows = v22;
    }
    else
    {
      LOBYTE(pedge->m_nNumQuadsPerRow) = 0;
    }
    this->m_nNumQuadsPerRow += v21;
    ++this->m_nRows;
    this->m_nPaddedColumns += v20;
    this->m_pAttributePtrs[0] = (unsigned __int8 *)((int)this->m_pAttributePtrs[0] * 2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101464D0
// Name: public: void GFxPathData::EdgesIterator::GetPlainEdge(struct GFxPathData::EdgesIterator::PlainEdge __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxPathData::EdgesIterator::GetPlainEdge(
        GFxPathData::EdgesIterator *this,
        struct GFxPathData::EdgesIterator::PlainEdge *a2)
{
  __int16 *v2; // eax
  bool v3; // zf
  int v4; // eax
  _DWORD *v5; // eax
  struct GFxPathData::EdgesIterator::PlainEdge *v6; // eax

  if ( *((_DWORD *)this + 1) < *((_DWORD *)this + 2) )
  {
    v2 = *((__int16 **)this + 7);
    if ( v2 != nullptr )
    {
      if ( *((_DWORD *)this + 6) > 0x8000u )
      {
        *((_DWORD *)this + 5) = *v2;
        *((_DWORD *)this + 7) = v2 + 1;
        *((_DWORD *)this + 6) = 1;
      }
      v3 = (*((_DWORD *)this + 5) & *((_DWORD *)this + 6)) == 0;
      a2->Type = **((__int16 **)this + 7);
      *((_DWORD *)this + 7) += 2;
      a2[1].Type = **((__int16 **)this + 7);
      *((_DWORD *)this + 7) += 2;
      if ( v3 )
      {
        ++*((_DWORD *)this + 1);
        *((_DWORD *)this + 6) *= 2;
        v4 = 8;
      }
      else
      {
        a2[2].Type = **((__int16 **)this + 7);
        *((_DWORD *)this + 7) += 2;
        a2[3].Type = **((__int16 **)this + 7);
        *((_DWORD *)this + 7) += 2;
        ++*((_DWORD *)this + 1);
        *((_DWORD *)this + 6) *= 2;
        v4 = 16;
      }
      a2[4].Type = v4 >> 2;
    }
    else
    {
      if ( *((_DWORD *)this + 6) == 0 )
      {
        v5 = *((_DWORD **)this + 8);
        *((_DWORD *)this + 5) = *v5;
        *((_DWORD *)this + 8) = v5 + 1;
        *((_DWORD *)this + 6) = 1;
      }
      v3 = (*((_DWORD *)this + 5) & *((_DWORD *)this + 6)) == 0;
      a2->Type = (*((struct GFxPathData::EdgesIterator::PlainEdge **)this + 8))->Type;
      v6 = a2 + 1;
      if ( !v3 )
      {
        *((_DWORD *)this + 8) += 4;
        v6->Type = (*((struct GFxPathData::EdgesIterator::PlainEdge **)this + 8))->Type;
        *((_DWORD *)this + 8) += 4;
        a2[2].Type = (*((struct GFxPathData::EdgesIterator::PlainEdge **)this + 8))->Type;
        v6 = a2 + 3;
      }
      *((_DWORD *)this + 8) += 4;
      v6->Type = (*((struct GFxPathData::EdgesIterator::PlainEdge **)this + 8))->Type;
      *((_DWORD *)this + 8) += 4;
      ++*((_DWORD *)this + 1);
      *((_DWORD *)this + 6) *= 2;
      a2[4].Type = &v6[1] - a2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10146600
// Name: private: GFxPathData::PathsIterator::PathsIterator(class GFxShapeBase const __near *)
// Source: json
//------------------------------------------------------------------------------
GFxPathData::PathsIterator *__thiscall GFxPathData::PathsIterator::PathsIterator(
        GFxPathData::PathsIterator *this,
        const struct GFxShapeBase *a2)
{
  GFxPathData::PathsIterator *result; // eax

  result = this;
  *(_DWORD *)this = a2;
  *((_DWORD *)this + 1) = *((_DWORD *)a2 + 13);
  *((_DWORD *)this + 2) = *((_DWORD *)a2 + 13);
  *((_DWORD *)this + 3) = *((_DWORD *)a2 + 14);
  *((_DWORD *)this + 4) = *((_DWORD *)a2 + 15);
  *((_DWORD *)this + 5) = *((_DWORD *)a2 + 16);
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = *((_DWORD *)a2 + 14);
  if ( (*((_BYTE *)a2 + 36) & 2) != 0 )
    *((float *)this + 8) = 0.050000001;
  else
    *((float *)this + 8) = 1.0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10146660
// Name: public: virtual class GFxShapeBase::PathsIterator __near * GFxShapeCharacterDef::GetPathsIterator(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GFxShapeCharacterDef::GetPathsIterator(old_bf_read *this, int a2)
{
  return (*(unsigned int (__thiscall **)(bool *, int))(*(_DWORD *)&this->m_bOverflow + 72))(a1: &this->m_bOverflow, a2);
}

//------------------------------------------------------------------------------
// Address: 0x10146670
// Name: void GMath2D::SubdivideQuadCurve<struct GMath2D::QuadCoordType>(float,float,float,float,float,float,float,struct GMath2D::QuadCoordType __near *,struct GMath2D::QuadCoordType __near *)
// Source: json
//------------------------------------------------------------------------------
float *__cdecl GMath2D::SubdivideQuadCurve<GMath2D::QuadCoordType>(
        float a1,
        float a2,
        float a3,
        float a4,
        float a5,
        float a6,
        float a7,
        float *a8,
        float *a9)
{
  double v9; // st5
  double v10; // st6
  double v11; // st4
  double v12; // st3
  double v13; // st2
  double v14; // st6
  float v16; // [esp+8h] [ebp+8h]
  float v17; // [esp+10h] [ebp+10h]
  float v18; // [esp+14h] [ebp+14h]
  float v19; // [esp+14h] [ebp+14h]
  float v20; // [esp+20h] [ebp+20h]
  float v21; // [esp+20h] [ebp+20h]

  v9 = a1;
  v10 = a7;
  v20 = (a3 - a1) * a7 + a1;
  v11 = a4;
  v18 = (a4 - a2) * v10 + a2;
  v17 = a3 + (a5 - a3) * v10;
  v16 = v11 + (a6 - v11) * v10;
  v12 = v20;
  v21 = (v17 - v20) * v10 + v20;
  v13 = v10 * (v16 - v18) + v18;
  v14 = v18;
  v19 = v13;
  *a8 = v9;
  a8[1] = a2;
  a8[2] = v12;
  a8[3] = v14;
  a8[4] = v21;
  a8[5] = v19;
  *a9 = v21;
  a9[1] = v19;
  a9[2] = v17;
  a9[3] = v16;
  a9[4] = a5;
  a9[5] = a6;
  return a9;
}

//------------------------------------------------------------------------------
// Address: 0x10146740
// Name: public: virtual GFxShapeBase::~GFxShapeBase(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxShapeBase::~GFxShapeBase(GFxShapeBase *this)
{
  GFxMeshCache *v2; // ecx
  void (__thiscall ***v3)(_DWORD, int); // ecx

  v2 = *((GFxMeshCache **)this + 6);
  *(_DWORD *)this = &GFxShapeBase::`vftable';
  if ( v2 != nullptr )
    GFxMeshCache::AddShapeToKillList(this: v2, a2: (struct GFxShapeBase *)this);
  v3 = *((void (__thiscall ****)(_DWORD, int))this + 8);
  *((_DWORD *)this + 6) = 0;
  if ( v3 != nullptr )
    (**v3)(a1: v3, a2: 1);
  *((_DWORD *)this + 8) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10146780
// Name: public: virtual float GFxShapeBase::GetMaxStrokeExtent(void)const
// Source: json
//------------------------------------------------------------------------------
double GFxShapeBase::GetMaxStrokeExtent()
{
  return 100.0;
}

//------------------------------------------------------------------------------
// Address: 0x10146790
// Name: public: static void GFxShapeBase::ApplyScale9Grid(class GCompoundShape __near *,struct GFxScale9GridInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxShapeBase::ApplyScale9Grid(CMaterialVar *shape, __int128 sg)
{
  unsigned int i; // esi

  for ( i = 0; i < *(_DWORD *)(sg + 8); ++i )
    GFxScale9GridInfo::Transform(
      this: (GFxScale9GridInfo *)DWORD1(sg),
      x: (float *)(*(_DWORD *)(*(_DWORD *)(sg + 20) + 4 * (i >> 8)) + 8 * (unsigned __int8)i),
      a3: (float *)(*(_DWORD *)(*(_DWORD *)(sg + 20) + 4 * (i >> 8)) + 8 * (unsigned __int8)i + 4));
}

//------------------------------------------------------------------------------
// Address: 0x101467D0
// Name: public: void GFxShapeBase::Display(struct GFxDisplayParams __near &,bool,class GFxCharacter __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxShapeBase::Display(
        GFxShapeBase *this@<ecx>,
        double a2@<st0>,
        struct GFxDisplayParams *a3,
        bool a4,
        struct GFxCharacter *a5)
{
  GFxAmpViewStats *v5; // esi
  IInputSystem_vtbl *v6; // eax
  float v7; // ecx
  int v8; // edx
  int v9; // edx
  GFxMeshCache *v10; // ecx
  float v11; // eax
  bool v12; // zf
  int v13; // edi
  GRefCountNTSImpl *v14; // edi
  GRefCountNTSImpl *v15; // eax
  GFxMeshSet *v16; // ecx
  float v17; // ecx
  double v18; // st7
  char v19; // cl
  bool v20; // al
  unsigned __int8 v21; // al
  unsigned int v22; // eax
  int v23; // ebx
  GFxMeshSet *MeshSet; // esi
  int v25; // ecx
  float v26; // esi
  int (__thiscall *v27)(int, int, int *); // eax
  GFxMeshSet *v28; // eax
  GFxMeshSet *v29; // esi
  double v30; // st7
  struct GFxShapeBase *v31; // ecx
  float v32; // [esp+Ch] [ebp-B4h]
  struct GFxDisplayParams *v33; // [esp+10h] [ebp-B0h]
  float v34; // [esp+18h] [ebp-A8h]
  float *v35; // [esp+1Ch] [ebp-A4h]
  int v36; // [esp+24h] [ebp-9Ch] BYREF
  bool v37[4]; // [esp+28h] [ebp-98h]
  IInputSystem v38; // [esp+2Ch] [ebp-94h] BYREF
  int v39; // [esp+30h] [ebp-90h]
  GFxAmpViewStats *v40; // [esp+34h] [ebp-8Ch]
  int v41; // [esp+38h] [ebp-88h]
  int v42; // [esp+3Ch] [ebp-84h]
  struct GFxDisplayParams *v43; // [esp+44h] [ebp-7Ch]
  struct GFxCharacter *v44; // [esp+48h] [ebp-78h]
  GFxMeshCache *v45; // [esp+4Ch] [ebp-74h]
  float v46; // [esp+50h] [ebp-70h]
  struct GFxShapeBase *v47; // [esp+54h] [ebp-6Ch]
  float v48; // [esp+58h] [ebp-68h]
  char v49; // [esp+5Fh] [ebp-61h]
  float v50; // [esp+60h] [ebp-60h]
  char v51; // [esp+67h] [ebp-59h]
  float v52[21]; // [esp+68h] [ebp-58h] BYREF

  v47 = (struct GFxShapeBase *)this;
  v5 = *(GFxAmpViewStats **)(*(_DWORD *)a3 + 144);
  v44 = a5;
  v6 = nullptr;
  v43 = a3;
  v40 = v5;
  v41 = 1;
  v42 = 4;
  if ( v5 != nullptr )
  {
    GFxAmpViewStats::PushCallstack(this: v5, swdHandle: 1u, a3: 4u);
    GTimer::GetRawTicks(li: v7, a2: v34, a3: v35);
    v39 = v8;
  }
  else
  {
    v39 = 0;
  }
  v9 = *(_DWORD *)a3;
  v10 = *(GFxMeshCache **)(*(_DWORD *)(*(_DWORD *)a3 + 104) + 20);
  v38.__vftable = v6;
  v11 = *(float *)(v9 + 72);
  v12 = (*(_BYTE *)(LODWORD(v11) + 20) & 0x10) == 0;
  v46 = v11;
  v45 = v10;
  if ( v12
    || ((v13 = *(_DWORD *)(LODWORD(v11) + 28)) & 0x100) == 0
    || (v13 & 0x200) == 0 && (*((_BYTE *)v47 + 36) & 1) != 0
    || a4
    || (v12 = *(_DWORD *)(v9 + 148) == 0, v51 = 1, !v12) )
  {
    v51 = 0;
  }
  v14 = nullptr;
  if ( *((char *)v47 + 36) < 0 && v44 != nullptr && (*((_BYTE *)v44 + 118) & 1) != 0 )
  {
    v48 = *(float *)(v9 + 116);
    v50 = *(float *)(LODWORD(v11) + 16) * v48;
    a2 = v50;
    GFxCharacter::CreateScale9Grid(
      a1: (int)v44,
      a2: nullptr,
      result: (const CMemberFunctor4<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(ITexture *,int,Rect_t *,Rect_t *),ITexture *,int,Rect_t *,Rect_t *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)LODWORD(v50));
    v14 = v15;
  }
  v16 = *((GFxMeshSet **)v47 + 8);
  if ( v16 != nullptr && v14 == nullptr && v51 == *((_BYTE *)v16 + 21) )
  {
    GFxMeshSet::Display(this: v16, a2: a3, a3: false);
LABEL_46:
    if ( v5 != nullptr )
    {
      GTimer::GetRawTicks(li: v17, a2: v34, a3: v35);
      GFxAmpViewStats::PopCallstack(result: (GImageInfo *)1);
    }
    return;
  }
  GMatrix2D::GetMaxScale(this: (CMaterialDict::MaterialLookup_t *)((char *)a3 + 12));
  v50 = a2;
  v18 = v50;
  v50 = fabs(v50);
  if ( v50 < 0.000001 )
  {
    if ( v14 != nullptr )
      GRefCountNTSImpl::Release(this: v14);
    goto LABEL_46;
  }
  v50 = fabs(*((float *)a3 + 16));
  if ( v50 < 1.0 )
  {
    v49 = 0;
    v19 = 0;
  }
  else
  {
    v19 = 1;
    v49 = 1;
  }
  v50 = fabs(*((float *)a3 + 15));
  if ( v50 >= 0.001 || v19 != 0 || *(_DWORD *)(*(_DWORD *)a3 + 148) != 0 )
  {
    v20 = (*(_DWORD *)(LODWORD(v46) + 20) & 0x20) != 0;
    v50 = v18 * *(float *)(*(_DWORD *)a3 + 116);
    v21 = (v51 != 0) | (2 * ((v19 != 0) | (2 * v20)));
    if ( v14 != nullptr )
    {
      GFxScale9GridInfo::MakeKey(this: (GFxScale9GridInfo *)v14, a2: v52, a3: 0.0, a4: v21);
      v23 = 84;
      LODWORD(v48) = 1;
    }
    else
    {
      LOBYTE(v52[0]) = v21;
      if ( v51 != 0 )
      {
        v48 = v50 * 0.8410000205039978;
        v48 = v48 * v48;
        LOBYTE(v22) = (LODWORD(v48) >> 23) - 64;
      }
      else
      {
        v48 = v50;
        v22 = ((unsigned int)(unsigned __int8)(LODWORD(v50) >> 23) - 64) >> 1;
      }
      BYTE1(v52[0]) = v22;
      v23 = 3;
      BYTE2(v52[0]) = ((unsigned int)(unsigned __int8)(COERCE_UNSIGNED_INT(*(float *)(LODWORD(v46) + 16)) >> 23) - 64) >> 1;
      v48 = 0.0;
    }
    MeshSet = (GFxMeshSet *)GFxMeshCache::GetMeshSet(a1: v45, a2: v47, a3: v44, a4: LODWORD(v48), a5: v52, a6: v23);
    if ( MeshSet != nullptr )
    {
      v33 = v43;
      *((_BYTE *)MeshSet + 25) = 1;
      GFxMeshSet::Display(this: MeshSet, a2: v33, a3: v14 != nullptr);
      *((_BYTE *)MeshSet + 25) = 0;
    }
    else
    {
      v25 = *((_DWORD *)v45 + 2);
      v26 = v46;
      v27 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v25 + 40);
      v36 = 131;
      v50 = 20.0 / v50;
      v46 = v50 * 0.75 * *(float *)(LODWORD(v46) + 16);
      v28 = (GFxMeshSet *)v27(a1: v25, a2: 116, a3: &v36);
      if ( v28 != nullptr )
      {
        v37[0] = (*(_DWORD *)(LODWORD(v26) + 20) & 0x20) != 0;
        v29 = GFxMeshSet::GFxMeshSet(this: v28, a2: v50, a3: v46, a4: v51 == 0, a5: v37[0]);
      }
      else
      {
        v29 = nullptr;
      }
      v30 = v46;
      v31 = v47;
      *((_BYTE *)v29 + 23) = v49;
      v32 = v30;
      (*(void (__stdcall **)(GFxMeshSet *, _DWORD, _DWORD, GRefCountNTSImpl *))(*(_DWORD *)v31 + 16))(
        a1: v29,
        a2: LODWORD(v32),
        a3: *(_DWORD *)v43,
        a4: v14);
      GFxMeshSet::SetMeshKey(a1: v29, a2: LODWORD(v48), a3: v52, a4: v23, a5: v44);
      GFxMeshSet::Display(this: v29, a2: v43, a3: v14 != nullptr);
      GFxMeshCache::AddMeshSet(this: v45, a2: v47, a3: v29);
    }
    if ( v14 != nullptr )
      GRefCountNTSImpl::Release(this: v14);
    v5 = v40;
    goto LABEL_46;
  }
  if ( v14 != nullptr )
    GRefCountNTSImpl::Release(this: v14);
  ScopeFunctionTimer::~ScopeFunctionTimer(this: &v38, a2: SLODWORD(v34));
}

//------------------------------------------------------------------------------
// Address: 0x10146BB0
// Name: bool GMath2D::CheckCurveIntersection(float,float,float,float,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl GMath2D::CheckCurveIntersection(
        GMath2D *this,
        float a2,
        float a3,
        float a4,
        float a5,
        float a6,
        float a7,
        float a8)
{
  double v8; // st7
  double v9; // st6
  double v10; // st5
  double v12; // st4
  double v13; // st7
  double v14; // st6
  bool v15; // bl
  float v16; // [esp+4h] [ebp-50h]
  float v17; // [esp+Ch] [ebp-48h]
  float v18; // [esp+14h] [ebp-40h]
  int v19; // [esp+24h] [ebp-30h] BYREF
  float v20; // [esp+28h] [ebp-2Ch]
  float v21; // [esp+2Ch] [ebp-28h]
  float v22; // [esp+30h] [ebp-24h]
  float v23; // [esp+34h] [ebp-20h]
  float v24; // [esp+38h] [ebp-1Ch]
  int v25; // [esp+3Ch] [ebp-18h] BYREF
  float v26; // [esp+40h] [ebp-14h]
  float v27; // [esp+44h] [ebp-10h]
  float v28; // [esp+48h] [ebp-Ch]
  float v29; // [esp+4Ch] [ebp-8h]
  float v30; // [esp+50h] [ebp-4h]
  float v31; // [esp+68h] [ebp+14h]
  float v32; // [esp+68h] [ebp+14h]
  int v33; // [esp+68h] [ebp+14h]
  float v34; // [esp+68h] [ebp+14h]
  int v35; // [esp+68h] [ebp+14h]
  float v36; // [esp+68h] [ebp+14h]

  v8 = a4;
  v9 = a2;
  v10 = a6;
  if ( a2 <= (double)a4 && v10 >= v8 )
    return GMath2D::CheckMonoCurveIntersection(this, a2, a3, a4, a5, a6, a7, a8);
  v31 = v8 + v8 - v9 - v10;
  if ( 0.0 == v31 )
    v12 = -1.0;
  else
    v12 = (v8 - v9) / v31;
  v32 = v12;
  v17 = v8;
  GMath2D::SubdivideQuadCurve<GMath2D::QuadCoordType>(
    a1: *(float *)&this,
    a2,
    a3,
    a4: v17,
    a5,
    a6,
    a7: v32,
    a8: (float *)&v19,
    a9: (float *)&v25);
  if ( v24 < (double)v20 )
  {
    v33 = v19;
    *(float *)&v19 = v23;
    v23 = *(float *)&v33;
    v34 = v20;
    v20 = v24;
    v24 = v34;
  }
  v13 = v26;
  v14 = v30;
  if ( v30 < (double)v26 )
  {
    v35 = v25;
    *(float *)&v25 = v29;
    v29 = *(float *)&v35;
    v36 = v26;
    v26 = v30;
    v30 = v36;
    v13 = v26;
    v14 = v36;
  }
  v18 = v14;
  v16 = v13;
  v15 = GMath2D::CheckMonoCurveIntersection(this: (GMath2D *)v25, a2: v16, a3: v27, a4: v28, a5: v29, a6: v18, a7, a8);
  return GMath2D::CheckMonoCurveIntersection(this: (GMath2D *)v19, a2: v20, a3: v21, a4: v22, a5: v23, a6: v24, a7, a8) != v15;
}

//------------------------------------------------------------------------------
// Address: 0x10146D70
// Name: public: int GFxShapeBase::GetTexture9GridStyle(class GCompoundShape const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxShapeBase::GetTexture9GridStyle(GFxShapeBase *this, const struct GCompoundShape *a2)
{
  int result; // eax
  _DWORD *v3; // edx
  int v4; // esi
  int (__thiscall *v5)(GFxShapeBase *, const struct GCompoundShape **); // edx
  int v6; // eax
  char v7; // al

  result = -1;
  if ( (*((_BYTE *)this + 36) & 0x40) != 0 && *((_DWORD *)a2 + 6) == 1 )
  {
    v3 = **((_DWORD ***)a2 + 9);
    v4 = v3[3];
    if ( v4 < 0 == (int)v3[4] < 0 || (int)v3[5] >= 0 )
      return -1;
    if ( v4 < 0 )
      v4 = v3[4];
    v5 = *(int (__thiscall **)(GFxShapeBase *, const struct GCompoundShape **))(*(_DWORD *)this + 36);
    a2 = nullptr;
    v6 = v5(a1: this, &a2);
    if ( v4 < (int)a2
      && (GFxFillStyle::IsClippedImageFill(this: (CMemberFunctor1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_DrawInfo_t const &),CMatQueuedMesh::MST_DrawInfo_t,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)(v6 + 40 * v4)),
          v7 == 0) )
    {
      return -1;
    }
    else
    {
      return v4;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10146DF0
// Name: public: GFxPathAllocator::~GFxPathAllocator(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall GFxPathAllocator::~GFxPathAllocator(FloatCubeMap_t *this)
{
  GFxPathAllocator::Clear(this);
}

//------------------------------------------------------------------------------
// Address: 0x10146E00
// Name: public: unsigned char __near * GFxPathAllocator::AllocPath(unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxPathAllocator::AllocPath(
        FloatCubeMap_t *this,
        unsigned int edgesDataSize,
        unsigned int pathSize,
        unsigned int edgeSize)
{
  unsigned int v5; // edx
  unsigned int v6; // esi
  int m_nRows; // ebx
  unsigned int v8; // eax
  int v9; // ecx
  int v10; // eax
  FloatCubeMap_t *v11; // [esp+Ch] [ebp-4h]
  unsigned int pathSizea; // [esp+1Ch] [ebp+Ch]

  pathSizea = 3 * pathSize;
  v5 = pathSizea + edgesDataSize + 1;
  v11 = this;
  v6 = v5;
  if ( edgesDataSize != 0 )
  {
    m_nRows = this->face_maps[0].m_nRows;
    v8 = 0;
    if ( m_nRows != 0 )
    {
      v9 = *(_DWORD *)(m_nRows + 4) - LOWORD(this->face_maps[0].m_nSlices) + m_nRows + 9;
      v10 = (~(pathSize - 1) & ((v9 & (pathSize - 1)) + pathSize - 1)) - (v9 & (pathSize - 1));
      v5 = pathSizea + edgesDataSize + 1;
      v8 = (~(edgeSize - 1) & (((edgeSize - 1) & (v10 + v9 + pathSizea)) + edgeSize - 1))
         - ((edgeSize - 1) & (v10 + v9 + pathSizea))
         + v10;
      this = v11;
    }
    v6 = v8 + v5;
    if ( m_nRows == 0 || LOWORD(this->face_maps[0].m_nSlices) < v6 )
      v8 = edgesDataSize + (~(edgeSize - 1) & (pathSizea + (pathSize & ~(pathSize - 1)) + edgeSize - 1)) - v5;
    v5 += v8;
  }
  GFxPathAllocator::AllocMemoryBlock(this, sizeForCurrentPage: v6, size: v5);
}

//------------------------------------------------------------------------------
// Address: 0x10146EB0
// Name: public: void GFxPathPacker::Pack(class GFxPathAllocator __near *,struct GFxPathData::PathsInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxPathPacker::Pack(
        CStridedConstPtr<__m128> *this,
        FloatCubeMap_t *a2,
        CStridedConstPtr<__m128> *ppathsInfo)
{
  unsigned int v4; // eax
  unsigned __int8 v5; // al
  __m128 *v6; // eax
  char v7; // bl
  _WORD *v8; // ecx
  _WORD *v9; // ecx
  int v10; // edi
  int v11; // edx
  int v12; // edi
  __int16 v13; // dx
  unsigned int v14; // edi
  unsigned int v15; // ebx
  unsigned int v16; // eax
  unsigned int v17; // ecx
  unsigned int v18; // eax
  _BYTE *v19; // ecx
  int v20; // edi
  _WORD *v21; // ecx
  _WORD *v22; // ebx
  _WORD *v23; // ecx
  __int16 v24; // di
  int v25; // edx
  int v26; // eax
  unsigned int v27; // edx
  unsigned int *v28; // ecx
  int v29; // ebx
  _DWORD *v30; // ecx
  _DWORD *v31; // edi
  int v32; // edx
  int v33; // eax
  __int16 v34; // di
  unsigned int bytesToAllocate; // [esp+Ch] [ebp-Ch]
  unsigned int bytesToAllocatea; // [esp+Ch] [ebp-Ch]
  unsigned int v37; // [esp+10h] [ebp-8h]
  unsigned int v38; // [esp+10h] [ebp-8h]
  unsigned __int8 edgesTypes; // [esp+15h] [ebp-3h]
  unsigned __int8 i; // [esp+16h] [ebp-2h]
  unsigned __int8 flags; // [esp+17h] [ebp-1h]
  unsigned __int8 flagsa; // [esp+17h] [ebp-1h]

  v4 = *((_DWORD *)this + 2) | (int)this->m_pData | this->m_nStride;
  if ( v4 >= 0x8000 )
  {
    if ( v4 >= 0x800000 )
    {
      if ( v4 >= 0x8000000 )
      {
        if ( v4 >= 0x20000000 )
        {
          if ( v4 >= 0x40000000 )
            v5 = 32 - (v4 < 0x80000000);
          else
            v5 = 30;
        }
        else
        {
          v5 = 29 - (v4 < 0x10000000);
        }
      }
      else if ( v4 >= 0x2000000 )
      {
        v5 = 27 - (v4 < 0x4000000);
      }
      else
      {
        v5 = 25 - (v4 < 0x1000000);
      }
    }
    else if ( v4 >= 0x80000 )
    {
      if ( v4 >= 0x200000 )
        v5 = 23 - (v4 < 0x400000);
      else
        v5 = 21 - (v4 < 0x100000);
    }
    else if ( v4 >= 0x20000 )
    {
      v5 = 19 - (v4 < 0x40000);
    }
    else
    {
      v5 = 17 - (v4 < 0x10000);
    }
  }
  else if ( v4 >= 0x80 )
  {
    if ( v4 >= 0x800 )
    {
      if ( v4 >= 0x2000 )
        v5 = 15 - (v4 < 0x4000);
      else
        v5 = 13 - (v4 < 0x1000);
    }
    else if ( v4 >= 0x200 )
    {
      v5 = 11 - (v4 < 0x400);
    }
    else
    {
      v5 = 9 - (v4 < 0x100);
    }
  }
  else if ( v4 >= 8 )
  {
    if ( v4 >= 0x20 )
      v5 = 7 - (v4 < 0x40);
    else
      v5 = 5 - (v4 < 0x10);
  }
  else if ( v4 >= 2 )
  {
    v5 = 3 - (v4 < 4);
  }
  else
  {
    v5 = v4 != 0;
  }
  if ( *((_BYTE *)this + 53) != 0 )
  {
    GFxPathAllocator::AllocMemoryBlock(this: a2, sizeForCurrentPage: 1u, size: 1u);
    v6->m128_i8[0] = 0;
    goto LABEL_86;
  }
  if ( v5 <= 8u && *((_BYTE *)this + 52) <= 0x10u && *((_DWORD *)this + 10) <= 4u )
  {
    v7 = (2 * ((*((_BYTE *)this + 40) - 1) & 3)) | 1;
    edgesTypes = 0;
    GFxPathAllocator::AllocPath(
      this: a2,
      edgesDataSize: 4 * (*((_DWORD *)this + 12) + 2 * *((_DWORD *)this + 11)) + 4,
      pathSize: 1u,
      edgeSize: 2u);
    v6->m128_i8[1] = (char)this->m_pData;
    v6->m128_i8[2] = this->m_nStride;
    v6->m128_i8[3] = *((_BYTE *)this + 8);
    v8 = (_WORD *)(((unsigned int)&v6->m128_u32[1] + 1) & 0xFFFFFFFE);
    *v8 = *((_WORD *)this + 6);
    v8[1] = *((_WORD *)this + 8);
    v9 = v8 + 2;
    bytesToAllocate = (unsigned int)v6;
    flags = 1;
    i = 0;
    if ( *((_DWORD *)this + 10) != 0 )
    {
      v10 = 0;
      do
      {
        v11 = *((_DWORD *)this + 7);
        v12 = 20 * v10;
        if ( *(_BYTE *)(v11 + v12 + 16) == 0 )
        {
          *v9 = *(_WORD *)(v11 + v12);
          v9[1] = *(_WORD *)(*((_DWORD *)this + 7) + v12 + 4);
          v6 = (__m128 *)bytesToAllocate;
          v9 += 2;
          edgesTypes |= flags;
        }
        ++i;
        flags *= 2;
        *v9 = *(_WORD *)(*((_DWORD *)this + 7) + v12 + 8);
        v13 = *(_WORD *)(*((_DWORD *)this + 7) + v12 + 12);
        v10 = i;
        v9[1] = v13;
        v9 += 2;
      }
      while ( (unsigned int)i < *((_DWORD *)this + 10) );
    }
    v6->m128_i8[0] = v7 | (8 * (edgesTypes & 0xF));
    goto LABEL_86;
  }
  v14 = 1;
  if ( v5 > 8u )
  {
    if ( v5 > 0x10u )
    {
      flagsa = 6;
      v14 = 4;
    }
    else
    {
      flagsa = 4;
      v14 = 2;
    }
  }
  else
  {
    flagsa = 2;
  }
  if ( *((_BYTE *)this + 52) > 0x10u || *((_DWORD *)this + 10) > 0xFFFFu )
  {
    flagsa |= 8u;
    v15 = 4;
  }
  else
  {
    v15 = 2;
  }
  v16 = *((_DWORD *)this + 10);
  if ( v16 >= 0x10 )
  {
    v17 = v15;
  }
  else
  {
    flagsa |= 16 * (_BYTE)v16;
    v17 = 0;
  }
  if ( *((_BYTE *)this + 52) > 0x10u )
    v18 = v17 + 4 * ((v16 + 31) >> 5);
  else
    v18 = v17 + 2 * ((v16 + 15) >> 4);
  GFxPathAllocator::AllocPath(
    this: a2,
    edgesDataSize: v18 + 2 * v15 * (*((_DWORD *)this + 12) + 2 * *((_DWORD *)this + 11) + 1),
    pathSize: v14,
    edgeSize: v15);
  v6->m128_i8[0] = flagsa;
  v19 = (_BYTE *)(~(v14 - 1) & ((unsigned int)v6 + v14));
  bytesToAllocatea = (unsigned int)v6;
  if ( v14 == 1 )
  {
    *v19 = this->m_pData;
    v6->m128_i8[2] = this->m_nStride;
    v6->m128_i8[3] = *((_BYTE *)this + 8);
  }
  else if ( v14 == 2 )
  {
    *(_WORD *)v19 = this->m_pData;
    *(_WORD *)((((unsigned int)v6->m128_u32 + 2) & 0xFFFFFFFE) + 2) = this->m_nStride;
    *(_WORD *)((((unsigned int)v6->m128_u32 + 2) & 0xFFFFFFFE) + 4) = *((_WORD *)this + 4);
  }
  else
  {
    *(_DWORD *)v19 = this->m_pData;
    *(_DWORD *)(((unsigned int)&v6->m128_u32[1] & 0xFFFFFFFC) + 4) = this->m_nStride;
    *(_DWORD *)(((unsigned int)&v6->m128_u32[1] & 0xFFFFFFFC) + 8) = *((_DWORD *)this + 2);
  }
  v20 = 3 * v14;
  if ( v15 == 2 )
  {
    v21 = (_WORD *)((unsigned int)&v19[v20 + 1] & 0xFFFFFFFE);
    if ( *((_DWORD *)this + 10) >= 0x10u )
      *v21++ = *((_WORD *)this + 20);
    *v21 = *((_WORD *)this + 6);
    v21[1] = *((_WORD *)this + 8);
    v22 = nullptr;
    v23 = v21 + 2;
    v24 = 0;
    v37 = 0;
    if ( *((_DWORD *)this + 10) != 0 )
    {
      v25 = 0;
      do
      {
        if ( (v37 & 0xF) == 0 )
        {
          v22 = v23++;
          *v22 = 0;
          v24 = 1;
        }
        v26 = *((_DWORD *)this + 7);
        if ( *(_BYTE *)(v26 + v25 + 16) == 0 )
        {
          *v23 = *(_WORD *)(v26 + v25);
          v23[1] = *(_WORD *)(*((_DWORD *)this + 7) + v25 + 4);
          v23 += 2;
          *v22 |= v24;
        }
        ++v37;
        *v23 = *(_WORD *)(*((_DWORD *)this + 7) + v25 + 8);
        v23[1] = *(_WORD *)(*((_DWORD *)this + 7) + v25 + 12);
        v23 += 2;
        v25 += 20;
        v24 *= 2;
      }
      while ( v37 < *((_DWORD *)this + 10) );
LABEL_85:
      v6 = (__m128 *)bytesToAllocatea;
    }
  }
  else
  {
    v27 = *((_DWORD *)this + 10);
    v28 = (unsigned int *)(~(v15 - 1) & (unsigned int)&v19[v20 - 1 + v15]);
    if ( v27 >= 0x10 )
      *v28++ = v27;
    *v28 = *((_DWORD *)this + 3);
    v28[1] = *((_DWORD *)this + 4);
    v29 = 0;
    v30 = v28 + 2;
    v31 = nullptr;
    v38 = 0;
    if ( *((_DWORD *)this + 10) != 0 )
    {
      v32 = 0;
      do
      {
        if ( (v38 & 0x1F) == 0 )
        {
          v31 = v30++;
          *v31 = 0;
          v29 = 1;
        }
        v33 = *((_DWORD *)this + 7);
        if ( *(_BYTE *)(v33 + v32 + 16) == 0 )
        {
          *v30 = *(_DWORD *)(v33 + v32);
          v30[1] = *(_DWORD *)(*((_DWORD *)this + 7) + v32 + 4);
          v30 += 2;
          *v31 |= v29;
        }
        ++v38;
        *v30 = *(_DWORD *)(*((_DWORD *)this + 7) + v32 + 8);
        v30[1] = *(_DWORD *)(*((_DWORD *)this + 7) + v32 + 12);
        v30 += 2;
        v32 += 20;
        v29 *= 2;
      }
      while ( v38 < *((_DWORD *)this + 10) );
      goto LABEL_85;
    }
  }
LABEL_86:
  if ( ppathsInfo != nullptr )
  {
    if ( ppathsInfo->m_pData == nullptr )
    {
      v34 = (_WORD)v6 - LOWORD(a2->face_maps[0].m_nRows);
      ppathsInfo->m_pData = v6;
      LOWORD(ppathsInfo[1].m_nStride) = v34;
    }
    if ( *((_BYTE *)this + 53) != 0 )
      ++ppathsInfo[1].m_pData;
    ++ppathsInfo->m_nStride;
  }
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 12) = 0;
  *((_DWORD *)this + 10) = 0;
  *((_BYTE *)this + 53) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x101473A0
// Name: public: void GFxPathPacker::SetMoveTo(int,int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall GFxPathPacker::SetMoveTo(CStridedConstPtr<__m128> *this, int x, int y, unsigned int numBits)
{
  unsigned __int8 result; // al
  unsigned __int8 v5; // bl
  unsigned int v6; // esi
  unsigned int v7; // eax
  unsigned int v8; // eax

  result = x;
  v5 = *((_BYTE *)this + 52);
  *((_DWORD *)this + 5) = x;
  *((_DWORD *)this + 3) = x;
  *((_DWORD *)this + 6) = y;
  *((_DWORD *)this + 4) = y;
  if ( numBits <= v5 )
  {
    if ( numBits == 0 )
    {
      if ( x != 0 )
        v6 = 2 * abs32(x);
      else
        v6 = 0;
      if ( y != 0 )
        v7 = 2 * abs32(y);
      else
        v7 = 0;
      v8 = v6 | v7;
      if ( v8 >= 0x8000 )
      {
        if ( v8 >= 0x800000 )
        {
          if ( v8 >= 0x8000000 )
          {
            if ( v8 >= 0x20000000 )
            {
              if ( v8 >= 0x40000000 )
                result = 32 - (v8 < 0x80000000);
              else
                result = 30;
            }
            else
            {
              result = 29 - (v8 < 0x10000000);
            }
          }
          else if ( v8 >= 0x2000000 )
          {
            result = 27 - (v8 < 0x4000000);
          }
          else
          {
            result = 25 - (v8 < 0x1000000);
          }
        }
        else if ( v8 >= 0x80000 )
        {
          if ( v8 >= 0x200000 )
            result = 23 - (v8 < 0x400000);
          else
            result = 21 - (v8 < 0x100000);
        }
        else if ( v8 >= 0x20000 )
        {
          result = 19 - (v8 < 0x40000);
        }
        else
        {
          result = 17 - (v8 < 0x10000);
        }
      }
      else if ( v8 >= 0x80 )
      {
        if ( v8 >= 0x800 )
        {
          if ( v8 >= 0x2000 )
            result = 15 - (v8 < 0x4000);
          else
            result = 13 - (v8 < 0x1000);
        }
        else if ( v8 >= 0x200 )
        {
          result = 11 - (v8 < 0x400);
        }
        else
        {
          result = 9 - (v8 < 0x100);
        }
      }
      else if ( v8 >= 8 )
      {
        if ( v8 >= 0x20 )
          result = 7 - (v8 < 0x40);
        else
          result = 5 - (v8 < 0x10);
      }
      else if ( v8 >= 2 )
      {
        result = 3 - (v8 < 4);
      }
      else
      {
        result = v8 != 0;
      }
      if ( v5 >= result )
        result = v5;
      *((_BYTE *)this + 52) = result;
    }
  }
  else
  {
    *((_BYTE *)this + 52) = numBits;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10147550
// Name: public: virtual unsigned long GFxConstShapeNoStyles::ComputeGeometryHash(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GFxConstShapeNoStyles::ComputeGeometryHash(GFxConstShapeNoStyles *this)
{
  unsigned __int8 *v1; // esi
  int v2; // ecx
  unsigned int v3; // edx
  int v4; // edi
  int v5; // ecx
  unsigned int result; // eax
  int v7; // edx
  int v8; // [esp+8h] [ebp-4h]

  v1 = *((unsigned __int8 **)this + 10);
  v2 = 0;
  v8 = 0;
  v3 = 0;
  if ( ((*v1 >> 3) & 3) != 0xFFFFFFFF )
  {
    do
    {
      v4 = v1[++v3] << v2;
      v2 += 8;
      v8 |= v4;
    }
    while ( v3 < ((*v1 >> 3) & 3u) + 1 );
  }
  v5 = v8;
  for ( result = 0; v5 != 0; result = v7 ^ (33 * result) )
    v7 = v1[--v5];
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101475B0
// Name: public: virtual void GFxConstShapeNoStyles::GetShapeAndPathCounts(unsigned int __near *,unsigned int __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxConstShapeNoStyles::GetShapeAndPathCounts(
        CBitRead *this,
        unsigned int *pshapesCnt,
        unsigned int *ppathsCnt)
{
  GFxSwfPathData::GetShapeAndPathCounts(
    ppaths: (GFxJpegSupportBase *)this,
    a2: *((unsigned __int8 **)this + 10),
    pshapesCnt,
    ppathsCnt);
}

//------------------------------------------------------------------------------
// Address: 0x101475D0
// Name: private: void GFxSwfPathData::PathsIterator::ReadNextEdge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSwfPathData::PathsIterator::ReadNextEdge(IKMeansErrorMetric *this)
{
  if ( *((_BYTE *)this + 32) != 1 )
  {
    do
      GFxSwfPathData::PathsIterator::ReadNext(this);
    while ( *((_BYTE *)this + 32) == 3 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101475F0
// Name: public: GFxSwfPathData::EdgesIterator::EdgesIterator(class GFxSwfPathData::PathsIterator __near &)
// Source: json
//------------------------------------------------------------------------------
IKMeansErrorMetric **__thiscall GFxSwfPathData::EdgesIterator::EdgesIterator(
        IKMeansErrorMetric **this,
        IKMeansErrorMetric *a2)
{
  char v3; // al

  *this = a2;
  *(this + 1) = nullptr;
  v3 = (char)a2[8].__vftable;
  if ( v3 >= 0 && v3 != 1 )
  {
    do
      GFxSwfPathData::PathsIterator::ReadNext(this: a2);
    while ( LOBYTE(a2[8].__vftable) == 3 );
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10147630
// Name: public: GFxPathData::EdgesIterator::EdgesIterator(class GFxPathData::PathsIterator const __near &)
// Source: json
//------------------------------------------------------------------------------
CSOAContainer *__thiscall GFxPathData::EdgesIterator::EdgesIterator(CSOAContainer *this, int pathIter)
{
  CSOAContainer *result; // eax
  _BYTE *v3; // edx
  _BYTE *v4; // edi
  unsigned __int8 v5; // dl
  unsigned __int8 *v6; // ecx
  int v7; // edx
  int v8; // esi
  unsigned __int8 v9; // cl
  int v10; // edx
  _DWORD *v11; // ecx
  unsigned __int8 *v12; // ecx
  int v13; // edx
  int v14; // edx
  unsigned __int8 *v15; // edx
  int *v16; // ecx
  int v17; // edx
  int v18; // edx
  unsigned __int8 *v19; // edx

  result = this;
  v3 = *(_BYTE **)(pathIter + 4);
  this->m_nColumns = (int)v3;
  this->m_nRows = 0;
  v4 = v3;
  this->m_pAttributePtrs[3] = *(unsigned __int8 **)(pathIter + 32);
  this->m_pAttributePtrs[0] = (unsigned __int8 *)1;
  if ( v3 != nullptr )
  {
    v5 = *v3;
    if ( (*v4 & 1) != 0 )
    {
      this->m_pDataMemory = (unsigned __int8 *)((v5 >> 3) & 0xF);
      v6 = (unsigned __int8 *)((unsigned int)(v4 + 5) & 0xFFFFFFFE);
      result->m_pAttributePtrs[1] = v6;
      result->m_nSlices = ((v5 >> 1) & 3) + 1;
      v7 = *(__int16 *)v6;
      v6 += 2;
      result->m_pAttributePtrs[1] = v6;
      result->m_nPaddedColumns = v7;
      result->m_nNumQuadsPerRow = *(__int16 *)v6;
      result->m_pAttributePtrs[1] = v6 + 2;
    }
    else
    {
      v8 = 2 * ((*v4 & 8) != 0) + 2;
      v9 = (v5 >> 1) & 3;
      if ( v9 != 0 )
      {
        v10 = v5 >> 4;
        v11 = (_DWORD *)(~(v8 - 1) & (3 * pathSFactorTable[v9] + v8 + ((unsigned int)&v4[v9] & ~(v9 - 1)) - 1));
        result->m_nSlices = v10;
        if ( v8 == 2 )
        {
          result->m_pAttributePtrs[1] = (unsigned __int8 *)v11;
          if ( v10 == 0 )
          {
            result->m_nSlices = *(unsigned __int16 *)v11;
            result->m_pAttributePtrs[1] = (unsigned __int8 *)v11 + 2;
          }
          v12 = result->m_pAttributePtrs[1];
          v13 = *(__int16 *)v12;
          v12 += 2;
          result->m_pAttributePtrs[1] = v12;
          result->m_nPaddedColumns = v13;
          v14 = *(__int16 *)v12;
          v12 += 2;
          result->m_pAttributePtrs[1] = v12;
          result->m_nNumQuadsPerRow = v14;
          v15 = (unsigned __int8 *)*(unsigned __int16 *)v12;
          result->m_pAttributePtrs[1] = v12 + 2;
          result->m_pAttributePtrs[2] = nullptr;
          result->m_pDataMemory = v15;
        }
        else
        {
          result->m_pAttributePtrs[2] = (unsigned __int8 *)v11;
          if ( v10 == 0 )
          {
            result->m_nSlices = *v11;
            result->m_pAttributePtrs[2] = (unsigned __int8 *)(v11 + 1);
          }
          v16 = (int *)result->m_pAttributePtrs[2];
          v17 = *v16++;
          result->m_pAttributePtrs[2] = (unsigned __int8 *)v16;
          result->m_nPaddedColumns = v17;
          v18 = *v16++;
          result->m_pAttributePtrs[2] = (unsigned __int8 *)v16;
          result->m_nNumQuadsPerRow = v18;
          v19 = (unsigned __int8 *)*v16;
          result->m_pAttributePtrs[2] = (unsigned __int8 *)(v16 + 1);
          result->m_pAttributePtrs[1] = nullptr;
          result->m_pDataMemory = v19;
        }
      }
      else
      {
        result->m_nSlices = 0;
      }
    }
  }
  else
  {
    this->m_nSlices = 0;
    this->m_pDataMemory = nullptr;
    this->m_pAttributePtrs[1] = nullptr;
    this->m_pAttributePtrs[2] = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10147790
// Name: public: void GFxPathData::PathsIterator::GetStyles(unsigned int __near *,unsigned int __near *,unsigned int __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxPathData::PathsIterator::GetStyles(
        GFxPathData::PathsIterator *this,
        unsigned int *a2,
        unsigned int *a3,
        unsigned int *a4)
{
  char *v4; // eax
  char v5; // cl
  unsigned __int16 *v6; // eax
  unsigned int *v7; // eax

  v4 = *((char **)this + 1);
  v5 = *v4;
  if ( (*v4 & 1) != 0 || (v5 & 6) == 2 )
  {
    *a2 = (unsigned __int8)v4[1];
    *a3 = (unsigned __int8)v4[2];
    *a4 = (unsigned __int8)v4[3];
  }
  else if ( (v5 & 7) != 0 )
  {
    if ( (v5 & 6) == 4 )
    {
      v6 = (unsigned __int16 *)((unsigned int)(v4 + 2) & 0xFFFFFFFE);
      *a2 = *v6;
      *a3 = v6[1];
      *a4 = v6[2];
    }
    else
    {
      v7 = (unsigned int *)((unsigned int)(v4 + 4) & 0xFFFFFFFC);
      *a2 = *v7;
      *a3 = v7[1];
      *a4 = v7[2];
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10147820
// Name: public: void GFxPathData::PathsIterator::AdvanceBy(class GFxPathData::EdgesIterator const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxPathData::PathsIterator::AdvanceBy(
        CSOAContainer *this@<ecx>,
        Vector edgeIt,
        Vector a3,
        int a4,
        int a5)
{
  int v5; // eax
  int m_nSlices; // edx
  int *v7; // edx
  int v8; // edx

  if ( *(_DWORD *)(LODWORD(edgeIt.x) + 4) >= *(_DWORD *)(LODWORD(edgeIt.x) + 8) )
  {
    v5 = *(_DWORD *)(LODWORD(edgeIt.x) + 28);
    if ( v5 == 0 )
      v5 = *(_DWORD *)(LODWORD(edgeIt.x) + 32);
    m_nSlices = this->m_nSlices;
    ++this->m_pAttributePtrs[0];
    v7 = (int *)(m_nSlices - LOWORD(this->m_pDataMemory));
    this->m_nRows = v5;
    if ( v5 - (int)v7 - 8 >= v7[1] )
    {
      v8 = *v7;
      if ( v8 != 0 )
      {
        this->m_nRows = v8 + 8;
        this->m_nSlices = v8 + 8;
        LOWORD(this->m_pDataMemory) = 8;
      }
      else
      {
        this->m_nRows = 0;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10147880
// Name: private: void GFxPathData::PathsIterator::SkipComplex(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxPathData::PathsIterator::SkipComplex(CSOAContainer *this)
{
  unsigned __int8 *m_nRows; // esi
  unsigned __int8 v2; // al
  unsigned int v3; // ebx
  int *v4; // edi
  int v5; // ecx
  int v6; // eax
  __int16 *v7; // edx
  int v8; // ebx
  unsigned __int16 *v9; // edx
  unsigned __int16 *v10; // edi
  CSOAContainer *v11; // ecx
  int m_pDataMemory_low; // edx
  int m_nSlices; // eax
  int *v14; // eax
  int v15; // eax

  m_nRows = (unsigned __int8 *)this->m_nRows;
  v2 = *m_nRows;
  v3 = 1;
  v4 = nullptr;
  if ( (*m_nRows & 1) != 0 )
  {
    v5 = (v2 >> 3) & 0xF;
    v6 = ((v2 >> 1) & 3) + 1;
    v7 = (__int16 *)(((unsigned int)(m_nRows + 5) & 0xFFFFFFFE) + 4);
  }
  else
  {
    v8 = 2 * ((v2 & 8) != 0) + 2;
    if ( ((v2 >> 1) & 3) == 0 )
    {
      this->m_nRows = (int)(m_nRows + 1);
      return;
    }
    v9 = (unsigned __int16 *)(~(v8 - 1)
                            & (3 * pathSFactorTable[(v2 >> 1) & 3]
                             + v8
                             + ((unsigned int)&m_nRows[(v2 >> 1) & 3] & ~(((v2 >> 1) & 3) - 1))
                             - 1));
    v6 = v2 >> 4;
    if ( v8 != 2 )
    {
      v10 = v9;
      if ( v6 == 0 )
      {
        v6 = *(_DWORD *)v9;
        v10 = v9 + 2;
      }
      v5 = *((_DWORD *)v10 + 2);
      v3 = 1;
      v4 = (int *)(v10 + 6);
      goto LABEL_18;
    }
    if ( v6 == 0 )
      v6 = *v9++;
    v5 = v9[2];
    v3 = 1;
    v7 = (__int16 *)(v9 + 3);
  }
  if ( v7 == nullptr )
  {
LABEL_18:
    while ( v6 != 0 )
    {
      if ( v3 == 0 )
      {
        v5 = *v4++;
        v3 = 1;
      }
      if ( (v3 & v5) != 0 )
        v4 += 4;
      else
        v4 += 2;
      v3 *= 2;
      --v6;
    }
    this->m_nRows = (int)v4;
    v11 = this;
    goto LABEL_29;
  }
  for ( ; v6 != 0; --v6 )
  {
    if ( v3 > 0x8000 )
    {
      v5 = *v7++;
      v3 = 1;
    }
    if ( (v3 & v5) != 0 )
      v7 += 4;
    else
      v7 += 2;
    v3 *= 2;
  }
  v11 = this;
  this->m_nRows = (int)v7;
LABEL_29:
  m_pDataMemory_low = LOWORD(v11->m_pDataMemory);
  m_nSlices = v11->m_nSlices;
  ++v11->m_pAttributePtrs[0];
  v14 = (int *)(m_nSlices - m_pDataMemory_low);
  if ( v11->m_nRows - (int)v14 - 8 >= v14[1] )
  {
    v15 = *v14;
    if ( v15 != 0 )
    {
      v11->m_nRows = v15 + 8;
      v11->m_nSlices = v15 + 8;
      LOWORD(v11->m_pDataMemory) = 8;
    }
    else
    {
      v11->m_nRows = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10147BD0
// Name: public: void GFxPathData::PathsIterator::Skip(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxPathData::PathsIterator::Skip(CSOAContainer *this)
{
  _BYTE *m_nRows; // eax
  int m_pDataMemory_low; // ecx
  int m_nSlices; // eax
  int v5; // edx
  int *v6; // eax
  int v7; // eax

  if ( this->m_pAttributePtrs[0] < this->m_pAttributePtrs[1] )
  {
    m_nRows = (_BYTE *)this->m_nRows;
    if ( (*m_nRows & 7) != 0 )
      GFxPathData::PathsIterator::SkipComplex(this);
    else
      this->m_nRows = (int)(m_nRows + 1);
    m_pDataMemory_low = LOWORD(this->m_pDataMemory);
    m_nSlices = this->m_nSlices;
    v5 = this->m_nRows;
    ++this->m_pAttributePtrs[0];
    v6 = (int *)(m_nSlices - m_pDataMemory_low);
    if ( v5 - (int)v6 - 8 >= v6[1] )
    {
      v7 = *v6;
      if ( v7 != 0 )
      {
        this->m_nRows = v7 + 8;
        this->m_nSlices = v7 + 8;
        LOWORD(this->m_pDataMemory) = 8;
      }
      else
      {
        this->m_nRows = 0;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10147C30
// Name: public: virtual class GRect<float> GFxShapeBase::GetRectBoundsLocal(void)const
// Source: rtti_class
//------------------------------------------------------------------------------
float *__thiscall GFxShapeBase::GetRectBoundsLocal(float *this, float *a2)
{
  *a2 = *(this + 1);
  a2[1] = *(this + 2);
  a2[2] = *(this + 3);
  a2[3] = *(this + 4);
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x10147C60
// Name: public: void GFxShapeBase::AddRef(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxShapeBase::AddRef(GFxShapeBase *this)
{
  InterlockedExchangeAdd(Addend: (volatile LONG *)this + 5, Value: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10147C70
// Name: public: void GFxShapeBase::Display(class GFxDisplayContext __near &,class GFxCharacter __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxShapeBase::Display(
        GFxShapeBase *this,
        FBMAttributeMask_t inst,
        CMemberFuncProxy2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,int),IMesh *,int,CFuncMemPolicyNone> *a3)
{
  float *v3; // eax
  double v4; // st7
  GFxShapeBase *v5; // esi
  int v6; // eax
  float *v7; // ecx
  CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> tbounds; // [esp+Ch] [ebp-A4h] BYREF
  float v9; // [esp+18h] [ebp-98h]
  GFxShapeBase *v10; // [esp+1Ch] [ebp-94h]
  FBMAttributeMask_t v11; // [esp+20h] [ebp-90h]
  GRenderer::Cxform v12; // [esp+24h] [ebp-8Ch] BYREF
  FBMAttributeMask_t params; // [esp+44h] [ebp-6Ch] BYREF
  int v14; // [esp+48h] [ebp-68h] BYREF
  float v15[7]; // [esp+4Ch] [ebp-64h] BYREF
  GRenderer::Cxform v16; // [esp+68h] [ebp-48h]
  int v17; // [esp+88h] [ebp-28h]
  int v18; // [esp+8Ch] [ebp-24h] BYREF
  int v19; // [esp+90h] [ebp-20h] BYREF
  GMatrix2D v20; // [esp+94h] [ebp-1Ch] BYREF

  v3 = *(float **)(inst + 4);
  v20.M_[0][0] = *v3;
  v10 = this;
  v20.M_[0][1] = v3[1];
  v11 = inst;
  v20.M_[0][2] = v3[2];
  v20.M_[1][0] = v3[3];
  v20.M_[1][1] = v3[4];
  v20.M_[1][2] = v3[5];
  GMatrix2D::Prepend(this: &v20, a2: (const struct GMatrix2D *)(&a3[2].m_pObject + 1));
  v12 = *(GRenderer::Cxform *)*(_DWORD *)inst;
  GRenderer::Cxform::Concatenate(this: &v12, a2: (const struct GRenderer::Cxform *)((char *)&a3[1].m_pfnProxied + 12));
  GFxCharacter::GetActiveBlendMode(this: a3);
  v15[1] = v20.M_[0][0];
  v14 = 0;
  v15[2] = v20.M_[0][1];
  v15[0] = 0.0;
  v15[3] = v20.M_[0][2];
  v15[4] = v20.M_[1][0];
  params = inst;
  v15[5] = v20.M_[1][1];
  v4 = v20.M_[1][2];
  v15[6] = v20.M_[1][2];
  v16 = v12;
  v5 = v10;
  v17 = v6;
  v18 = 0;
  v19 = 0;
  if ( *(_DWORD *)(inst + 8) != 0 )
    goto LABEL_8;
  if ( (*((_BYTE *)v10 + 36) & 0x10) == 0 )
    goto LABEL_8;
  *(float *)&tbounds.m_pMemory = 0.0;
  *(float *)&tbounds.m_nAllocationCount = 0.0;
  *(float *)&tbounds.m_nGrowSize = 0.0;
  v9 = 0.0;
  GMatrix2D::EncloseTransform(a1: &tbounds, a2: (char *)v10 + 4);
  v7 = (float *)(*(int (__thiscall **)(CMemberFuncProxy2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,int),IMesh *,int,CFuncMemPolicyNone> *))(LODWORD(a3->m_pfnProxied) + 84))(a1: a3);
  v4 = v7[39];
  if ( *(float *)&tbounds.m_nAllocationCount <= v4 )
  {
    v4 = v9;
    if ( v7[37] <= (double)v9 )
    {
      v4 = *(float *)&tbounds.m_nGrowSize;
      if ( v7[36] <= (double)*(float *)&tbounds.m_nGrowSize )
      {
        v4 = v7[38];
        if ( *(float *)&tbounds.m_pMemory <= v4 )
          goto LABEL_8;
      }
    }
  }
  if ( (*(_DWORD *)(*(_DWORD *)(v11 + 72) + 20) & 0x100) != 0 )
  {
LABEL_8:
    if ( (*((_BYTE *)v5 + 36) & 0x40) != 0 )
      v4 = ((double (__thiscall *)(GFxShapeBase *, int *, int *, float *, int *))*(_DWORD *)(*(_DWORD *)v5 + 48))(
             a1: v5,
             a2: &v14,
             a3: &v18,
             a4: v15,
             a5: &v19);
    GFxShapeBase::Display(
      this: v5,
      a2: v4,
      a3: (struct GFxDisplayParams *)&params,
      a4: *((_WORD *)&a3[4].m_pObject + 2) != 0,
      a5: (struct GFxCharacter *)a3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10147E40
// Name: private: GFxSwfPathData::PathsIterator::PathsIterator(class GFxShapeBase const __near *)
// Source: json
//------------------------------------------------------------------------------
GFxSwfPathData::PathsIterator *__thiscall GFxSwfPathData::PathsIterator::PathsIterator(
        GFxSwfPathData::PathsIterator *this,
        CFltX4AttributeIterator *a2)
{
  int v3; // eax
  int v4; // edx
  char v5; // dl
  double v6; // st7
  unsigned int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // edx
  int v11; // edx
  int v12; // eax
  int v13; // edx
  int v14; // edx
  int v15; // eax
  int v16; // edx
  int v17; // edx
  int v18; // edx
  int v19; // edx
  int v20; // eax
  int v21; // edx
  int v22; // edx
  int v23; // edx
  int v24; // edx
  bool v25; // zf

  *this = a2;
  *(this + 1) = (GFxSwfPathData::PathsIterator)a2[5].m_pData;
  *((_DWORD *)this + 2) = -1;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_BYTE *)this + 32) = 0;
  if ( *((_DWORD *)this + 1) != 0 )
  {
    if ( *((_DWORD *)this + 4) != 0 )
      ++*((_DWORD *)this + 3);
    v3 = *((_DWORD *)this + 3);
    v4 = *((_DWORD *)this + 1);
    *((_DWORD *)this + 4) = 0;
    v5 = *(_BYTE *)(v3 + v4);
    *((_DWORD *)this + 3) = v3 + 1;
    *((_BYTE *)this + 112) = v5;
    if ( (a2[4].m_nStride & 2) != 0 )
    {
      v6 = 0.050000001;
      *((_BYTE *)this + 112) = v5 | 0x80;
    }
    else
    {
      v6 = 1.0;
    }
    v7 = *((unsigned __int8 *)this + 112);
    *((float *)this + 27) = v6;
    v8 = ((v7 >> 3) & 3) + 1;
    if ( *((_DWORD *)this + 4) != 0 )
      ++*((_DWORD *)this + 3);
    *((_DWORD *)this + 3) += v8;
    *((_DWORD *)this + 4) = 0;
    if ( (*(_BYTE *)(this + 28) & 1) != 0 )
    {
      v9 = *((_DWORD *)this + 3);
      v10 = *((_DWORD *)this + 1);
      *((_DWORD *)this + 4) = 0;
      v11 = *(unsigned __int16 *)(v10 + v9);
      *((_DWORD *)this + 3) = v9 + 2;
      *((_DWORD *)this + 15) = v11;
    }
    else
    {
      *((_DWORD *)this + 15) = 0;
    }
    if ( (*(_BYTE *)(this + 28) & 2) != 0 )
    {
      if ( *((_DWORD *)this + 4) != 0 )
        ++*((_DWORD *)this + 3);
      v12 = *((_DWORD *)this + 3);
      v13 = *((_DWORD *)this + 1);
      *((_DWORD *)this + 4) = 0;
      v14 = *(unsigned __int16 *)(v13 + v12);
      *((_DWORD *)this + 3) = v12 + 2;
      *((_DWORD *)this + 16) = v14;
    }
    else
    {
      *((_DWORD *)this + 16) = 0;
    }
    *((_DWORD *)this + 14) = 0;
    *((_DWORD *)this + 13) = 0;
    switch ( *((_DWORD *)this + 4) )
    {
      case 0:
        v15 = *(unsigned __int8 *)(*((_DWORD *)this + 3) + *((_DWORD *)this + 1)) >> 4;
        *((_DWORD *)this + 4) = 4;
        break;
      case 1:
        v15 = (*(unsigned __int8 *)(*((_DWORD *)this + 3) + *((_DWORD *)this + 1)) >> 3) & 0xF;
        *((_DWORD *)this + 4) = 5;
        break;
      case 2:
        v15 = (*(unsigned __int8 *)(*((_DWORD *)this + 3) + *((_DWORD *)this + 1)) >> 2) & 0xF;
        *((_DWORD *)this + 4) = 6;
        break;
      case 3:
        v15 = (*(unsigned __int8 *)(*((_DWORD *)this + 3) + *((_DWORD *)this + 1)) >> 1) & 0xF;
        *((_DWORD *)this + 4) = 7;
        break;
      case 4:
        v16 = *((_DWORD *)this + 3);
        v15 = *(_BYTE *)(*((_DWORD *)this + 1) + v16) & 0xF;
        *((_DWORD *)this + 4) = 0;
        *((_DWORD *)this + 3) = v16 + 1;
        break;
      case 5:
        v17 = *((_DWORD *)this + 3);
        v15 = (2 * (*(_BYTE *)(*((_DWORD *)this + 1) + v17) & 7))
            | (*(unsigned __int8 *)(*((_DWORD *)this + 1) + v17 + 1) >> 7);
        *((_DWORD *)this + 4) = 1;
        *((_DWORD *)this + 3) = v17 + 1;
        break;
      case 6:
        v18 = *((_DWORD *)this + 3);
        v15 = (4 * (*(_BYTE *)(*((_DWORD *)this + 1) + v18) & 3))
            | (*(unsigned __int8 *)(*((_DWORD *)this + 1) + v18 + 1) >> 6);
        *((_DWORD *)this + 4) = 2;
        *((_DWORD *)this + 3) = v18 + 1;
        break;
      case 7:
        v19 = *((_DWORD *)this + 3);
        v15 = (8 * (*(_BYTE *)(*((_DWORD *)this + 1) + v19) & 1))
            | (*(unsigned __int8 *)(*((_DWORD *)this + 1) + v19 + 1) >> 5);
        *((_DWORD *)this + 4) = 3;
        *((_DWORD *)this + 3) = v19 + 1;
        break;
      default:
        v15 = 0;
        break;
    }
    *((_DWORD *)this + 17) = v15;
    switch ( *((_DWORD *)this + 4) )
    {
      case 0:
        v20 = *(unsigned __int8 *)(*((_DWORD *)this + 3) + *((_DWORD *)this + 1)) >> 4;
        *((_DWORD *)this + 4) = 4;
        break;
      case 1:
        v20 = (*(unsigned __int8 *)(*((_DWORD *)this + 3) + *((_DWORD *)this + 1)) >> 3) & 0xF;
        *((_DWORD *)this + 4) = 5;
        break;
      case 2:
        v20 = (*(unsigned __int8 *)(*((_DWORD *)this + 3) + *((_DWORD *)this + 1)) >> 2) & 0xF;
        *((_DWORD *)this + 4) = 6;
        break;
      case 3:
        v20 = (*(unsigned __int8 *)(*((_DWORD *)this + 3) + *((_DWORD *)this + 1)) >> 1) & 0xF;
        *((_DWORD *)this + 4) = 7;
        break;
      case 4:
        v21 = *((_DWORD *)this + 3);
        v20 = *(_BYTE *)(v21 + *((_DWORD *)this + 1)) & 0xF;
        *((_DWORD *)this + 4) = 0;
        *((_DWORD *)this + 3) = v21 + 1;
        break;
      case 5:
        v22 = *((_DWORD *)this + 3);
        v20 = (2 * (*(_BYTE *)(v22 + *((_DWORD *)this + 1)) & 7))
            | (*(unsigned __int8 *)(v22 + *((_DWORD *)this + 1) + 1) >> 7);
        *((_DWORD *)this + 4) = 1;
        *((_DWORD *)this + 3) = v22 + 1;
        break;
      case 6:
        v23 = *((_DWORD *)this + 3);
        v20 = (4 * (*(_BYTE *)(v23 + *((_DWORD *)this + 1)) & 3))
            | (*(unsigned __int8 *)(v23 + *((_DWORD *)this + 1) + 1) >> 6);
        *((_DWORD *)this + 4) = 2;
        *((_DWORD *)this + 3) = v23 + 1;
        break;
      case 7:
        v24 = *((_DWORD *)this + 3);
        v20 = (8 * (*(_BYTE *)(v24 + *((_DWORD *)this + 1)) & 1))
            | (*(unsigned __int8 *)(v24 + *((_DWORD *)this + 1) + 1) >> 5);
        *((_DWORD *)this + 4) = 3;
        *((_DWORD *)this + 3) = v24 + 1;
        break;
      default:
        v20 = 0;
        break;
    }
    v25 = *((_BYTE *)this + 32) == 1;
    *((_DWORD *)this + 18) = v20;
    *((_DWORD *)this + 12) = 0;
    *((_DWORD *)this + 11) = 0;
    *((_DWORD *)this + 19) = 0;
    *((_DWORD *)this + 20) = 0;
    *((_DWORD *)this + 7) = 0;
    *((_DWORD *)this + 6) = 0;
    *((_DWORD *)this + 5) = 0;
    *((_DWORD *)this + 10) = 0;
    *((_DWORD *)this + 9) = 0;
    if ( !v25 )
    {
      while ( 1 )
      {
        GFxSwfPathData::PathsIterator::ReadNext((IKMeansErrorMetric *)this);
        if ( *((_BYTE *)this + 32) != 3 )
          break;
        if ( *((_BYTE *)this + 32) == 1 )
          return this;
      }
    }
  }
  else
  {
    *((_BYTE *)this + 32) = 1;
    *((float *)this + 27) = 1.0;
    *((_BYTE *)this + 112) = 0;
    *((_DWORD *)this + 16) = 0;
    *((_DWORD *)this + 15) = 0;
    *((_DWORD *)this + 14) = 0;
    *((_DWORD *)this + 13) = 0;
    *((_DWORD *)this + 18) = 0;
    *((_DWORD *)this + 17) = 0;
    *((_DWORD *)this + 12) = 0;
    *((_DWORD *)this + 11) = 0;
    *((_DWORD *)this + 19) = 0;
    *((_DWORD *)this + 20) = 0;
    *((_DWORD *)this + 7) = 0;
    *((_DWORD *)this + 6) = 0;
    *((_DWORD *)this + 5) = 0;
    *((_DWORD *)this + 10) = 0;
    *((_DWORD *)this + 9) = 0;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10148220
// Name: private: void GFxSwfPathData::PathsIterator::SkipComplex(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSwfPathData::PathsIterator::SkipComplex(IKMeansErrorMetric *this)
{
  char v2; // al
  char v3; // al
  int v4; // eax
  int v5; // eax
  int v6; // eax

  v2 = *((_BYTE *)this + 32);
  if ( v2 >= 0 && v2 != 1 )
  {
    do
      GFxSwfPathData::PathsIterator::ReadNext(this);
    while ( *((_BYTE *)this + 32) == 3 );
  }
  while ( 1 )
  {
    v3 = *((_BYTE *)this + 32);
    if ( v3 >= 0 )
      break;
    v4 = (unsigned __int8)v3 - 132;
    if ( v4 != 0 )
    {
      if ( v4 != 1 )
        goto LABEL_9;
      v5 = *((_DWORD *)this + 21) + *((_DWORD *)this + 23);
      *((_DWORD *)this + 12) += *((_DWORD *)this + 22) + *((_DWORD *)this + 24);
      *((_DWORD *)this + 11) += v5;
      GFxSwfPathData::PathsIterator::ReadNext(this);
    }
    else
    {
      v6 = *((_DWORD *)this + 26);
      *((_DWORD *)this + 11) += *((_DWORD *)this + 25);
      *((_DWORD *)this + 12) += v6;
LABEL_9:
      GFxSwfPathData::PathsIterator::ReadNext(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10148290
// Name: public: unsigned int GFxSwfPathData::PathsIterator::GetEdgesCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxSwfPathData::PathsIterator::GetEdgesCount(GFxSwfPathData::PathsIterator *this)
{
  CFltX4AttributeIterator *pit; // [esp+0h] [ebp-94h] BYREF
  KMeansQuantizedValue *v3; // [esp+4h] [ebp-90h]
  int v4; // [esp+8h] [ebp-8Ch]
  int v5; // [esp+Ch] [ebp-88h]
  CSOAContainer *v6; // [esp+10h] [ebp-84h]
  char v7; // [esp+20h] [ebp-74h]
  CFltX4AttributeIterator **p_pit; // [esp+74h] [ebp-20h] BYREF
  int v9; // [esp+78h] [ebp-1Ch]
  CSOAAttributeReferenceBinaryOp<&SubSIMD> v10; // [esp+7Ch] [ebp-18h] BYREF

  GFxSwfPathData::PathsIterator::PathsIterator(
    this: (IKMeansErrorMetric *)&pit,
    p: (const int *)this,
    a3: (int)pit,
    a4: v3,
    a5: v4,
    a6: v5,
    a7: v6);
  p_pit = &pit;
  v9 = 0;
  if ( v7 >= 0 && v7 != 1 )
  {
    do
      GFxSwfPathData::PathsIterator::ReadNext(this: (IKMeansErrorMetric *)&pit);
    while ( v7 == 3 );
  }
  while ( *((char *)p_pit + 32) < 0 )
    GFxSwfPathData::EdgesIterator::GetPlainEdge(this: (IKMeansErrorMetric **)&p_pit, result: &v10);
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x10148310
// Name: public: unsigned int GFxSwfPathData::EdgesIterator::GetEdgesCount(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSwfPathData::EdgesIterator::GetEdgesCount(CSOAAttributeReferenceBinaryOp<&SubSIMD> *this)
{
  CFltX4AttributeIterator *pita; // [esp+0h] [ebp-94h] BYREF
  KMeansQuantizedValue *v2; // [esp+4h] [ebp-90h]
  int v3; // [esp+8h] [ebp-8Ch]
  int v4; // [esp+Ch] [ebp-88h]
  CSOAContainer *v5; // [esp+10h] [ebp-84h]
  char v6; // [esp+20h] [ebp-74h]
  CSOAAttributeReferenceBinaryOp<&SubSIMD> eita; // [esp+74h] [ebp-20h] BYREF

  GFxSwfPathData::PathsIterator::PathsIterator(
    this: (IKMeansErrorMetric *)&pita,
    p: &this->m_opA.m_pContainer->m_nColumns,
    a3: (int)pita,
    a4: v2,
    a5: v3,
    a6: v4,
    a7: v5);
  eita.m_opA.m_pContainer = (CSOAContainer *)&pita;
  eita.m_opA.m_nAttributeID = 0;
  if ( v6 >= 0 && v6 != 1 )
  {
    do
      GFxSwfPathData::PathsIterator::ReadNext(this: (IKMeansErrorMetric *)&pita);
    while ( v6 == 3 );
  }
  while ( SLOBYTE(eita.m_opA.m_pContainer->m_pAttributePtrs[2]) < 0 )
    GFxSwfPathData::EdgesIterator::GetPlainEdge(
      this: (IKMeansErrorMetric **)&eita,
      result: (CSOAAttributeReferenceBinaryOp<&SubSIMD> *)&eita.m_opB);
}

//------------------------------------------------------------------------------
// Address: 0x10148390
// Name: public: virtual GFxConstShapeWithStyles::~GFxConstShapeWithStyles(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxConstShapeWithStyles::~GFxConstShapeWithStyles(GFxConstShapeWithStyles *this)
{
  unsigned int v2; // edi
  int v3; // ebx
  unsigned int v4; // edi
  int v5; // ebx
  GFxMeshCache *v6; // ecx
  void (__thiscall ***v7)(_DWORD, int); // ecx
  CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),CFuncMemPolicyNone> *v8; // [esp+0h] [ebp-Ch]

  v2 = 0;
  *(_DWORD *)this = &GFxConstShapeWithStyles::`vftable';
  if ( *((_DWORD *)this + 13) != 0 )
  {
    v3 = 0;
    do
    {
      GFxFillStyle::~GFxFillStyle(result: v8);
      ++v2;
      v3 += 40;
    }
    while ( v2 < *((_DWORD *)this + 13) );
  }
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 11));
  v4 = 0;
  if ( *((_DWORD *)this + 14) != 0 )
  {
    v5 = 0;
    do
    {
      (**(void (__thiscall ***)(int, _DWORD))(*((_DWORD *)this + 12) + v5))(a1: v5 + *((_DWORD *)this + 12), a2: 0);
      ++v4;
      v5 += 24;
    }
    while ( v4 < *((_DWORD *)this + 14) );
  }
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 12));
  v6 = *((GFxMeshCache **)this + 6);
  *(_DWORD *)this = &GFxShapeBase::`vftable';
  if ( v6 != nullptr )
    GFxMeshCache::AddShapeToKillList(this: v6, a2: this);
  v7 = *((void (__thiscall ****)(_DWORD, int))this + 8);
  *((_DWORD *)this + 6) = 0;
  if ( v7 != nullptr )
    (**v7)(a1: v7, a2: 1);
  *((_DWORD *)this + 8) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10148430
// Name: public: virtual class GFxFillStyle const __near * GFxConstShapeWithStyles::GetFillStyles(unsigned int __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxConstShapeWithStyles::GetFillStyles(GFxConstShapeWithStyles *this, unsigned int *pstylesNum)
{
  *pstylesNum = *((_DWORD *)this + 13);
  return *((_DWORD *)this + 11);
}

//------------------------------------------------------------------------------
// Address: 0x10148450
// Name: public: virtual class GFxLineStyle const __near * GFxConstShapeWithStyles::GetLineStyles(unsigned int __near *)const
// Source: json
//------------------------------------------------------------------------------
struct IClientNetworkable *__thiscall GFxConstShapeWithStyles::GetLineStyles(
        IClientUnknown *this,
        unsigned int *pstylesNum)
{
  *pstylesNum = *((_DWORD *)this + 14);
  return *((struct IClientNetworkable **)this + 12);
}

//------------------------------------------------------------------------------
// Address: 0x10148470
// Name: public: virtual void GFxConstShapeWithStyles::GetFillAndLineStyles(class GFxFillStyle const __near * __near *,unsigned int __near *,class GFxLineStyle const __near * __near *,unsigned int __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxConstShapeWithStyles::GetFillAndLineStyles(
        GFxConstShapeWithStyles *this,
        CSOAAttributeReferenceBinaryOp<&DivSIMD> *const ppfillStyles,
        unsigned int *pfillStylesNum,
        const struct GFxLineStyle **plineStylesNum,
        unsigned int *a5)
{
  ppfillStyles->m_opA.m_pContainer = *((CSOAContainer **)this + 11);
  *pfillStylesNum = *((_DWORD *)this + 13);
  *plineStylesNum = *((const struct GFxLineStyle **)this + 12);
  *a5 = *((_DWORD *)this + 14);
}

//------------------------------------------------------------------------------
// Address: 0x101484A0
// Name: public: virtual void GFxConstShapeWithStyles::GetFillAndLineStyles(struct GFxDisplayParams __near *)const
// Source: json
//------------------------------------------------------------------------------
IClientUnknown *__thiscall GFxConstShapeWithStyles::GetFillAndLineStyles(IClientUnknown *this, IClientUnknown *a2)
{
  a2[1].__vftable = (IClientUnknown_vtbl *)*(this + 11);
  a2[2].__vftable = (IClientUnknown_vtbl *)*(this + 12);
  a2[18].__vftable = (IClientUnknown_vtbl *)*(this + 13);
  a2[19].__vftable = (IClientUnknown_vtbl *)*(this + 14);
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x101484D0
// Name: public: virtual void GFxConstShapeWithStyles::SetMaxStrokeExtent(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxConstShapeWithStyles::SetMaxStrokeExtent(GFxConstShapeWithStyles *this, float m)
{
  *((float *)this + 15) = m;
}

//------------------------------------------------------------------------------
// Address: 0x101484E0
// Name: public: virtual float GFxConstShapeWithStyles::GetMaxStrokeExtent(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall GFxConstShapeWithStyles::GetMaxStrokeExtent(GFxConstShapeWithStyles *this)
{
  return *((float *)this + 15);
}

//------------------------------------------------------------------------------
// Address: 0x101484F0
// Name: public: virtual class GRect<float> GFxConstShapeWithStyles::GetRectBoundsLocal(void)const
// Source: rtti_class
//------------------------------------------------------------------------------
IClientUnknown *__thiscall GFxConstShapeWithStyles::GetRectBoundsLocal(
        IClientUnknown_vtbl **this,
        IClientUnknown *result)
{
  result->__vftable = *(this + 16);
  result[1].__vftable = *(this + 17);
  result[2].__vftable = *(this + 18);
  result[3].__vftable = *(this + 19);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10148520
// Name: public: virtual void GFxConstShapeWithStyles::SetRectBoundsLocal(class GRect<float> const __near &)
// Source: json
//------------------------------------------------------------------------------
struct ICollideable *__thiscall GFxConstShapeWithStyles::SetRectBoundsLocal(
        IClientUnknown *this,
        CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *r)
{
  struct ICollideable *result; // eax
  float v3; // [esp+0h] [ebp-8h]
  float v4; // [esp+4h] [ebp-4h]
  int ra; // [esp+10h] [ebp+8h]

  result = (struct ICollideable *)r;
  ra = r->m_Memory.m_nAllocationCount;
  v4 = *((float *)result + 2);
  v3 = *((float *)result + 3);
  *(this + 16) = *(IClientUnknown *)result;
  *(this + 17) = (IClientUnknown)ra;
  *((float *)this + 18) = v4;
  *((float *)this + 19) = v3;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10148560
// Name: public: virtual void GFxConstShapeCharacterDef::Display(class GFxDisplayContext __near &,class GFxCharacter __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxConstShapeCharacterDef::Display(
        old_bf_read *this,
        __vc_attributes::pointer_defaultAttribute inst,
        CMemberFuncProxy2<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,int),IMesh *,int,CFuncMemPolicyNone> *a3)
{
  GFxShapeBase::Display(this: (GFxShapeBase *)&this->m_bOverflow, inst: (FBMAttributeMask_t)inst.type, a3);
}

//------------------------------------------------------------------------------
// Address: 0x10148570
// Name: public: GFxVirtualPathIterator<class GFxShapeNoStyles,class GFxPathData>::GFxVirtualPathIterator<class GFxShapeNoStyles,class GFxPathData>(class GFxShapeNoStyles const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxVirtualPathIterator<GFxShapeNoStyles,GFxPathData>::GFxVirtualPathIterator<GFxShapeNoStyles,GFxPathData>(
        int this,
        int a2)
{
  GFxPathData::PathsIterator *v3; // esi
  double v4; // st7
  _BYTE v6[40]; // [esp+Ch] [ebp-28h] BYREF
  float v7; // [esp+3Ch] [ebp+8h]

  *(_DWORD *)this = &GRefCountImplCore::`vftable';
  *(_DWORD *)(this + 4) = 1;
  *(_DWORD *)this = &GFxVirtualPathIterator<GFxShapeNoStyles,GFxPathData>::`vftable';
  *(_DWORD *)(this + 8) = a2;
  v3 = (GFxPathData::PathsIterator *)(this + 8);
  *(_DWORD *)(this + 12) = *(_DWORD *)(a2 + 52);
  *(_DWORD *)(this + 16) = *(_DWORD *)(a2 + 52);
  *(_DWORD *)(this + 20) = *(_DWORD *)(a2 + 56);
  *(_DWORD *)(this + 24) = *(_DWORD *)(a2 + 60);
  *(_DWORD *)(this + 28) = *(_DWORD *)(a2 + 64);
  *(_DWORD *)(this + 32) = 0;
  *(_DWORD *)(this + 36) = *(_DWORD *)(a2 + 56);
  if ( (*(_BYTE *)(a2 + 36) & 2) != 0 )
    v4 = 0.050000001;
  else
    v4 = 1.0;
  v7 = v4;
  *(float *)(this + 40) = v7;
  *(_DWORD *)(this + 44) = 0;
  *(_DWORD *)(this + 52) = 0;
  if ( *(_DWORD *)(this + 32) < *(_DWORD *)(this + 36) )
  {
    *(_DWORD *)(this + 84) = 0;
    GFxPathData::PathsIterator::GetStyles(
      this: v3,
      a2: (unsigned int *)(this + 96),
      a3: (unsigned int *)(this + 100),
      a4: (unsigned int *)(this + 104));
    GFxPathData::EdgesIterator::EdgesIterator(this: (CSOAContainer *)v6, pathIter: (int)v3);
    qmemcpy((void *)(this + 44), v6, 40);
    *(float *)(this + 88) = (double)*(int *)(this + 56) * *(float *)(this + 80);
    *(float *)(this + 92) = (double)*(int *)(this + 60) * *(float *)(this + 80);
  }
  else
  {
    *(_DWORD *)(this + 84) = 4;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10148650
// Name: public: virtual bool GFxVirtualPathIterator<class GFxShapeNoStyles,class GFxPathData>::GetNext(struct GFxShapeBase::PathsIterator::StateInfo __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall GFxVirtualPathIterator<GFxShapeNoStyles,GFxPathData>::GetNext(int this, _DWORD *a2)
{
  int v3; // eax
  int v4; // eax
  char v6; // dl
  double v7; // st7
  Vector v8; // [esp-4h] [ebp-4Ch]
  Vector v9; // [esp+8h] [ebp-40h] BYREF
  int v10; // [esp+14h] [ebp-34h]
  int v11; // [esp+18h] [ebp-30h]
  int v12; // [esp+1Ch] [ebp-2Ch]
  float v13[4]; // [esp+34h] [ebp-14h] BYREF
  char v14; // [esp+44h] [ebp-4h]

  *a2 = *(_DWORD *)(this + 84);
  a2[1] = *(_DWORD *)(this + 88);
  a2[2] = *(_DWORD *)(this + 92);
  a2[3] = *(_DWORD *)(this + 96);
  a2[4] = *(_DWORD *)(this + 100);
  a2[5] = *(_DWORD *)(this + 104);
  v3 = *(_DWORD *)(this + 84);
  if ( v3 == 0 )
    goto LABEL_4;
  v4 = v3 - 2;
  if ( v4 != 0 )
  {
    if ( v4 != 1 )
      return *a2 != 4;
LABEL_4:
    if ( *(_DWORD *)(this + 48) >= *(_DWORD *)(this + 52) )
    {
      LODWORD(v8.x) = this + 44;
      *(_DWORD *)(this + 84) = 2;
      GFxPathData::PathsIterator::AdvanceBy(this: (CSOAContainer *)(this + 8), edgeIt: v8, a3: v9, a4: v10, a5: v11);
      return *a2 != 4;
    }
    GFxPathData::EdgesIterator::GetEdge(
      this: (CSOAContainer *)(this + 44),
      pedge: (const CSOAContainer *)v13,
      doLines2CurveConv: 0,
      ax: SLODWORD(v8.y),
      ay: SLODWORD(v8.z),
      a6: SLODWORD(v9.x),
      a7: SLODWORD(v9.y),
      a8: SLODWORD(v9.z),
      a9: v10,
      a10: v11,
      a11: v12);
    v6 = v14;
    *(float *)(this + 88) = v13[0];
    v7 = v13[1];
    *(_DWORD *)(this + 84) = 3;
    *(float *)(this + 92) = v7;
    *(_BYTE *)(this + 104) = v6;
    *(float *)(this + 96) = v13[2];
    *(float *)(this + 100) = v13[3];
    return *a2 != 4;
  }
  if ( *(_DWORD *)(this + 32) < *(_DWORD *)(this + 36) )
  {
    if ( (**(_BYTE **)(this + 12) & 7) == 0 )
      GFxPathData::PathsIterator::Skip(this: (CSOAContainer *)(this + 8));
    *(_DWORD *)(this + 84) = 0;
    GFxPathData::PathsIterator::GetStyles(
      this: (GFxPathData::PathsIterator *)(this + 8),
      a2: (unsigned int *)(this + 96),
      a3: (unsigned int *)(this + 100),
      a4: (unsigned int *)(this + 104));
    qmemcpy(
      (void *)(this + 44),
      GFxPathData::EdgesIterator::EdgesIterator(this: (CSOAContainer *)&v9.y, pathIter: this + 8),
      0x28u);
    *(float *)(this + 88) = (double)*(int *)(this + 56) * *(float *)(this + 80);
    *(float *)(this + 92) = (double)*(int *)(this + 60) * *(float *)(this + 80);
    return *a2 != 4;
  }
  else
  {
    *(_DWORD *)(this + 84) = 4;
    return *a2 != 4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101488A0
// Name: protected: bool GFxShapeBase::IsEqualGeometryImpl<class GFxSwfPathData>(class GFxShapeBase const __near &)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxShapeBase::IsEqualGeometryImpl<GFxSwfPathData>(
        CFltX4AttributeIterator *this,
        CFltX4AttributeIterator *a2)
{
  void (__thiscall *v3)(CFltX4AttributeIterator *, unsigned int *, unsigned int *); // eax
  void (__thiscall *v4)(CFltX4AttributeIterator *, unsigned int *, unsigned int *); // edx
  char v5; // bl
  char v6; // dl
  unsigned int v7; // eax
  int v8; // ecx
  int v9; // eax
  int v10; // esi
  int v11; // eax
  unsigned int v12; // eax
  const GPtr<GFxJpegSupportBase> **p_edge2; // ecx
  const GPtr<GFxJpegSupportBase> **p_edge1; // esi
  GFxSwfPathData::PathsIterator pit1[5]; // [esp+Ch] [ebp-15Ch] BYREF
  int v17; // [esp+20h] [ebp-148h]
  int v18; // [esp+24h] [ebp-144h]
  int v19; // [esp+28h] [ebp-140h]
  char v20; // [esp+2Ch] [ebp-13Ch]
  int v21; // [esp+38h] [ebp-130h]
  int v22; // [esp+3Ch] [ebp-12Ch]
  float v23; // [esp+78h] [ebp-F0h]
  char v24; // [esp+7Ch] [ebp-ECh]
  GFxSwfPathData::PathsIterator pit2[5]; // [esp+80h] [ebp-E8h] BYREF
  int v26; // [esp+94h] [ebp-D4h]
  int v27; // [esp+98h] [ebp-D0h]
  int v28; // [esp+9Ch] [ebp-CCh]
  char v29; // [esp+A0h] [ebp-C8h]
  int v30; // [esp+ACh] [ebp-BCh]
  int v31; // [esp+B0h] [ebp-B8h]
  float v32; // [esp+ECh] [ebp-7Ch]
  char v33; // [esp+F0h] [ebp-78h]
  CSOAAttributeReferenceBinaryOp<&SubSIMD> eit1; // [esp+F4h] [ebp-74h] BYREF
  unsigned int pathsCnt; // [esp+104h] [ebp-64h] BYREF
  unsigned int cmpWithShapesCnt; // [esp+108h] [ebp-60h] BYREF
  unsigned int shapesCnt; // [esp+10Ch] [ebp-5Ch] BYREF
  unsigned int cmpWithPathsCnt; // [esp+110h] [ebp-58h] BYREF
  float ax1; // [esp+114h] [ebp-54h]
  float ay1; // [esp+118h] [ebp-50h]
  float ax2; // [esp+11Ch] [ebp-4Ch]
  float ay2; // [esp+120h] [ebp-48h]
  const GPtr<GFxJpegSupportBase> *edge2; // [esp+124h] [ebp-44h] BYREF
  int v44; // [esp+134h] [ebp-34h]
  const GPtr<GFxJpegSupportBase> *edge1; // [esp+138h] [ebp-30h] BYREF
  int v46; // [esp+148h] [ebp-20h]
  _DWORD v47[3]; // [esp+14Ch] [ebp-1Ch]
  _DWORD v48[3]; // [esp+158h] [ebp-10h]

  v3 = (void (__thiscall *)(CFltX4AttributeIterator *, unsigned int *, unsigned int *))this->m_pData[4].m128_i32[1];
  shapesCnt = 0;
  pathsCnt = 0;
  v3(a1: this, a2: &shapesCnt, a3: &pathsCnt);
  v4 = (void (__thiscall *)(CFltX4AttributeIterator *, unsigned int *, unsigned int *))a2->m_pData[4].m128_i32[1];
  cmpWithShapesCnt = 0;
  cmpWithPathsCnt = 0;
  v4(a1: a2, a2: &cmpWithShapesCnt, a3: &cmpWithPathsCnt);
  if ( shapesCnt != cmpWithShapesCnt || pathsCnt != cmpWithPathsCnt )
    return 0;
  GFxSwfPathData::PathsIterator::PathsIterator(this: pit1, a2: this);
  GFxSwfPathData::PathsIterator::PathsIterator(this: pit2, a2);
  v5 = v20;
  if ( v20 != 1 )
  {
LABEL_4:
    v6 = v29;
    if ( v29 != 1 )
    {
      v47[0] = v17;
      v47[1] = v18;
      v47[2] = v19;
      v48[0] = v26;
      v48[1] = v27;
      v48[2] = v28;
      v7 = 12;
      v8 = 0;
      while ( v47[v8] == v48[v8] )
      {
        v7 -= 4;
        ++v8;
        if ( v7 < 4 )
        {
          eit1.m_opA.m_pContainer = (CSOAContainer *)pit1;
          eit1.m_opA.m_nAttributeID = 0;
          if ( v5 >= 0 )
          {
            do
              GFxSwfPathData::PathsIterator::ReadNext(this: (IKMeansErrorMetric *)pit1);
            while ( v20 == 3 );
            v6 = v29;
          }
          eit1.m_opB.m_pContainer = (CSOAContainer *)pit2;
          eit1.m_opB.m_nAttributeID = 0;
          if ( v6 >= 0 && v6 != 1 )
          {
            do
              GFxSwfPathData::PathsIterator::ReadNext(this: (IKMeansErrorMetric *)pit2);
            while ( v29 == 3 );
          }
          ax1 = (float)v21;
          ay1 = (float)v22;
          if ( v24 < 0 )
          {
            ax1 = v23 * ax1;
            ay1 = v23 * ay1;
          }
          ax2 = (float)v30;
          ay2 = (float)v31;
          if ( v33 < 0 )
          {
            ax2 = v32 * ax2;
            ay2 = v32 * ay2;
          }
          if ( ax2 != ax1 )
            return 0;
          if ( ay2 != ay1 )
            return 0;
          GFxSwfPathData::EdgesIterator::GetEdgesCount(this: (CSOAAttributeReferenceBinaryOp<&SubSIMD> *)&eit1.m_opB);
          v10 = v9;
          GFxSwfPathData::EdgesIterator::GetEdgesCount(this: &eit1);
          if ( v11 != v10 )
            return 0;
          while ( SLOBYTE(eit1.m_opA.m_pContainer->m_pAttributePtrs[2]) < 0 )
          {
            if ( SLOBYTE(eit1.m_opB.m_pContainer->m_pAttributePtrs[2]) >= 0 )
              return 0;
            GFxSwfPathData::EdgesIterator::GetPlainEdge(
              this: (IKMeansErrorMetric **)&eit1,
              result: (CSOAAttributeReferenceBinaryOp<&SubSIMD> *)&edge1);
            GFxSwfPathData::EdgesIterator::GetPlainEdge(
              this: (IKMeansErrorMetric **)&eit1.m_opB,
              result: (CSOAAttributeReferenceBinaryOp<&SubSIMD> *)&edge2);
            if ( v46 != v44 )
              return 0;
            v12 = 4 * v46;
            p_edge2 = &edge2;
            p_edge1 = &edge1;
            if ( (unsigned int)(4 * v46) >= 4 )
            {
              while ( *p_edge1 == *p_edge2 )
              {
                v12 -= 4;
                ++p_edge2;
                ++p_edge1;
                if ( v12 < 4 )
                  goto LABEL_27;
              }
              return 0;
            }
LABEL_27:
            if ( v12 != 0
              && (*(_BYTE *)p_edge2 != *(_BYTE *)p_edge1
               || v12 > 1
               && (*((_BYTE *)p_edge2 + 1) != *((_BYTE *)p_edge1 + 1)
                || v12 > 2 && *((_BYTE *)p_edge2 + 2) != *((_BYTE *)p_edge1 + 2))) )
            {
              return 0;
            }
          }
          v5 = v20;
          if ( v20 != 1 )
            goto LABEL_4;
          return 1;
        }
      }
    }
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10148B60
// Name: protected: unsigned long GFxShapeBase::ComputeGeometryHashImpl<class GFxPathData>(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxShapeBase::ComputeGeometryHashImpl<GFxPathData>(_BYTE *this)
{
  void (__thiscall *v2)(_BYTE *, unsigned int *, unsigned int *); // eax
  int v3; // eax
  int i; // ecx
  int v5; // edx
  int j; // ecx
  int v7; // edx
  bool v8; // zf
  _BYTE *v9; // ecx
  int v10; // edx
  int k; // edi
  int v12; // eax
  int v13; // edx
  unsigned int v14; // eax
  double v15; // st7
  char v16; // dl
  unsigned __int16 *v17; // eax
  int v18; // ecx
  int v19; // edx
  int v20; // eax
  int *v21; // eax
  _BYTE *v22; // eax
  int v23; // eax
  int v24; // esi
  int v25; // ecx
  int v26; // eax
  int v27; // ecx
  int v28; // eax
  int m; // ecx
  int v30; // edx
  _DWORD *v31; // eax
  int v32; // eax
  char v34; // [esp+8h] [ebp-80h] BYREF
  unsigned int v35; // [esp+Ch] [ebp-7Ch]
  unsigned int v36; // [esp+10h] [ebp-78h]
  int v37; // [esp+14h] [ebp-74h]
  int v38; // [esp+18h] [ebp-70h]
  _BYTE *v39; // [esp+24h] [ebp-64h]
  _BYTE *v40; // [esp+28h] [ebp-60h]
  float v41[3]; // [esp+2Ch] [ebp-5Ch]
  int pathIter; // [esp+38h] [ebp-50h] BYREF
  _BYTE *v43; // [esp+3Ch] [ebp-4Ch]
  _BYTE *v44; // [esp+40h] [ebp-48h]
  int v45; // [esp+44h] [ebp-44h]
  int v46; // [esp+48h] [ebp-40h]
  int v47; // [esp+4Ch] [ebp-3Ch]
  unsigned int v48; // [esp+50h] [ebp-38h]
  unsigned int v49; // [esp+54h] [ebp-34h]
  float v50; // [esp+58h] [ebp-30h]
  unsigned int pathsCnt; // [esp+5Ch] [ebp-2Ch] BYREF
  unsigned int shapesCnt; // [esp+60h] [ebp-28h] BYREF
  GFxEvent edge; // [esp+64h] [ebp-24h] BYREF
  _DWORD v54[4]; // [esp+74h] [ebp-14h]

  v2 = *(void (__thiscall **)(_BYTE *, unsigned int *, unsigned int *))(*(_DWORD *)this + 68);
  shapesCnt = 0;
  pathsCnt = 0;
  v2(a1: this, a2: &shapesCnt, a3: &pathsCnt);
  v3 = 5381;
  for ( i = 4; i != 0; --i )
  {
    v5 = *((unsigned __int8 *)&pathsCnt + i + 3);
    v3 = v5 ^ (33 * v3);
  }
  for ( j = 4; j != 0; --j )
  {
    v7 = *((unsigned __int8 *)&v50 + j + 3);
    v3 = v7 ^ (33 * v3);
  }
  v8 = (*(this + 36) & 2) == 0;
  v10 = *((_DWORD *)this + 14);
  k = v3;
  v44 = *((_BYTE **)this + 13);
  v9 = v44;
  v12 = *((_DWORD *)this + 15);
  v45 = v10;
  v13 = *((_DWORD *)this + 16);
  v46 = v12;
  v14 = *((_DWORD *)this + 14);
  pathIter = (int)this;
  v43 = v44;
  v47 = v13;
  v48 = 0;
  v49 = v14;
  if ( v8 )
    v15 = 1.0;
  else
    v15 = 0.050000001;
  v50 = v15;
  if ( v14 != 0 )
  {
    do
    {
      v16 = *v9;
      if ( (*v9 & 1) != 0 || (v16 & 6) == 2 )
      {
        v19 = (unsigned __int8)v9[2];
        v22 = v9 + 1;
        v18 = (unsigned __int8)v9[1];
        v20 = (unsigned __int8)v22[2];
      }
      else
      {
        if ( (v16 & 7) == 0 )
          goto LABEL_17;
        if ( (v16 & 6) == 4 )
        {
          v17 = (unsigned __int16 *)((unsigned int)(v9 + 2) & 0xFFFFFFFE);
          v18 = *v17;
          v19 = v17[1];
          v20 = v17[2];
        }
        else
        {
          v21 = (int *)((unsigned int)(v9 + 4) & 0xFFFFFFFC);
          v18 = *v21;
          v19 = v21[1];
          v20 = v21[2];
        }
      }
      v54[1] = v18;
      v54[2] = v19;
      v54[3] = v20;
LABEL_17:
      v23 = 12;
      v24 = k;
      do
      {
        v25 = *((unsigned __int8 *)v54 + v23-- + 3);
        v24 = v25 ^ (33 * v24);
      }
      while ( v23 != 0 );
      GFxPathData::EdgesIterator::EdgesIterator(this: (CSOAContainer *)&v34, (int)&pathIter);
      v26 = 8;
      v41[1] = (double)v37 * v41[0];
      v41[2] = v41[0] * (double)v38;
      do
      {
        v27 = *((unsigned __int8 *)v41 + v26-- + 3);
        v24 = v27 ^ (33 * v24);
      }
      while ( v26 != 0 );
      for ( k = v24; v35 < v36; k = m )
      {
        GFxPathData::EdgesIterator::GetPlainEdge(this: (GFxPathData::EdgesIterator *)&v34, a2: &edge);
        v28 = 4 * v54[0];
        for ( m = k; v28 != 0; m = v30 ^ (33 * m) )
          v30 = *((unsigned __int8 *)&shapesCnt + v28-- + 3);
      }
      v9 = v39;
      if ( v39 == nullptr )
        v9 = v40;
      ++v48;
      v31 = &v44[-(unsigned __int16)v47];
      v43 = v9;
      if ( v9 - (_BYTE *)v31 - 8 >= v31[1] )
      {
        v32 = *v31;
        if ( v32 != 0 )
        {
          v9 = (_BYTE *)(v32 + 8);
          v43 = (_BYTE *)(v32 + 8);
          v44 = (_BYTE *)(v32 + 8);
          LOWORD(v47) = 8;
        }
        else
        {
          v9 = nullptr;
          v43 = nullptr;
        }
      }
    }
    while ( v48 < v49 );
  }
  return k;
}

//------------------------------------------------------------------------------
// Address: 0x10148D70
// Name: protected: bool GFxShapeBase::IsEqualGeometryImpl<class GFxPathData>(class GFxShapeBase const __near &)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxShapeBase::IsEqualGeometryImpl<GFxPathData>(struct GFxShapeBase *this, struct GFxShapeBase *a2)
{
  void (__thiscall *v3)(struct GFxShapeBase *, unsigned int *, unsigned int *); // eax
  void (__thiscall *v4)(struct GFxShapeBase *, unsigned int *, unsigned int *); // edx
  unsigned __int16 v5; // bx
  int v6; // edi
  unsigned int v7; // eax
  int v8; // ecx
  double v9; // st6
  double v10; // st7
  unsigned int v11; // eax
  GFxEvent *p_edge2; // ecx
  GFxEvent *p_edge1; // esi
  int v14; // ecx
  int *v15; // eax
  int v16; // eax
  int v17; // ecx
  int *v18; // eax
  int v19; // eax
  char v21; // [esp+Ch] [ebp-F0h] BYREF
  unsigned int v22; // [esp+10h] [ebp-ECh]
  unsigned int v23; // [esp+14h] [ebp-E8h]
  int v24; // [esp+18h] [ebp-E4h]
  int v25; // [esp+1Ch] [ebp-E0h]
  int v26; // [esp+28h] [ebp-D4h]
  int v27; // [esp+2Ch] [ebp-D0h]
  float v28; // [esp+30h] [ebp-CCh]
  char v29; // [esp+34h] [ebp-C8h] BYREF
  unsigned int v30; // [esp+38h] [ebp-C4h]
  unsigned int v31; // [esp+3Ch] [ebp-C0h]
  int v32; // [esp+40h] [ebp-BCh]
  int v33; // [esp+44h] [ebp-B8h]
  int v34; // [esp+50h] [ebp-ACh]
  int v35; // [esp+54h] [ebp-A8h]
  float v36; // [esp+58h] [ebp-A4h]
  int v37; // [esp+5Ch] [ebp-A0h] BYREF
  int v38; // [esp+60h] [ebp-9Ch]
  int v39; // [esp+64h] [ebp-98h]
  __int16 v40; // [esp+70h] [ebp-8Ch]
  unsigned int v41; // [esp+74h] [ebp-88h]
  unsigned int v42; // [esp+78h] [ebp-84h]
  int pathIter; // [esp+80h] [ebp-7Ch] BYREF
  int v44; // [esp+84h] [ebp-78h]
  int v45; // [esp+88h] [ebp-74h]
  unsigned __int16 v46; // [esp+94h] [ebp-68h]
  unsigned int v47; // [esp+98h] [ebp-64h]
  unsigned int v48; // [esp+9Ch] [ebp-60h]
  unsigned int cmpWithPathsCnt; // [esp+A4h] [ebp-58h] BYREF
  unsigned int cmpWithShapesCnt; // [esp+A8h] [ebp-54h] BYREF
  unsigned int pathsCnt; // [esp+ACh] [ebp-50h] BYREF
  unsigned int shapesCnt; // [esp+B0h] [ebp-4Ch] BYREF
  float v53; // [esp+B4h] [ebp-48h]
  GFxEvent edge2; // [esp+B8h] [ebp-44h] BYREF
  int v55; // [esp+C8h] [ebp-34h]
  GFxEvent edge1; // [esp+CCh] [ebp-30h] BYREF
  int v57; // [esp+DCh] [ebp-20h]
  unsigned int v58; // [esp+E0h] [ebp-1Ch] BYREF
  unsigned int v59; // [esp+E4h] [ebp-18h] BYREF
  unsigned int v60; // [esp+E8h] [ebp-14h] BYREF
  unsigned int v61; // [esp+ECh] [ebp-10h] BYREF
  unsigned int v62; // [esp+F0h] [ebp-Ch] BYREF
  unsigned int v63; // [esp+F4h] [ebp-8h] BYREF

  v3 = *(void (__thiscall **)(struct GFxShapeBase *, unsigned int *, unsigned int *))(*(_DWORD *)this + 68);
  shapesCnt = 0;
  pathsCnt = 0;
  v3(a1: this, a2: &shapesCnt, a3: &pathsCnt);
  v4 = *(void (__thiscall **)(struct GFxShapeBase *, unsigned int *, unsigned int *))(*(_DWORD *)a2 + 68);
  cmpWithShapesCnt = 0;
  cmpWithPathsCnt = 0;
  v4(a1: a2, a2: &cmpWithShapesCnt, a3: &cmpWithPathsCnt);
  if ( shapesCnt == cmpWithShapesCnt && pathsCnt == cmpWithPathsCnt )
  {
    GFxPathData::PathsIterator::PathsIterator(this: (GFxPathData::PathsIterator *)&pathIter, a2: this);
    GFxPathData::PathsIterator::PathsIterator(this: (GFxPathData::PathsIterator *)&v37, a2);
    if ( v47 >= v48 )
      return 1;
    v5 = v40;
    v6 = v39;
LABEL_5:
    if ( v41 < v42 )
    {
      GFxPathData::PathsIterator::GetStyles(this: (GFxPathData::PathsIterator *)&pathIter, a2: &v58, a3: &v59, a4: &v60);
      GFxPathData::PathsIterator::GetStyles(this: (GFxPathData::PathsIterator *)&v37, a2: &v61, a3: &v62, a4: &v63);
      v7 = 12;
      v8 = 0;
      while ( *(unsigned int *)((char *)&v58 + v8) == *(unsigned int *)((char *)&v61 + v8) )
      {
        v7 -= 4;
        v8 += 4;
        if ( v7 < 4 )
        {
          GFxPathData::EdgesIterator::EdgesIterator(this: (CSOAContainer *)&v21, (int)&pathIter);
          GFxPathData::EdgesIterator::EdgesIterator(this: (CSOAContainer *)&v29, pathIter: (int)&v37);
          v53 = (double)v24 * v28;
          v9 = v53;
          v53 = (double)v32 * v36;
          if ( v53 != v9 )
            return 0;
          v53 = v28 * (double)v25;
          v10 = v53;
          v53 = v36 * (double)v33;
          if ( v53 != v10 || v23 != v31 )
            return 0;
          if ( v22 < v23 )
          {
            while ( v30 < v31 )
            {
              GFxPathData::EdgesIterator::GetPlainEdge(this: (GFxPathData::EdgesIterator *)&v21, a2: &edge1);
              GFxPathData::EdgesIterator::GetPlainEdge(this: (GFxPathData::EdgesIterator *)&v29, a2: &edge2);
              if ( v57 != v55 )
                break;
              v11 = 4 * v57;
              p_edge2 = &edge2;
              p_edge1 = &edge1;
              if ( (unsigned int)(4 * v57) >= 4 )
              {
                while ( p_edge1->Type == p_edge2->Type )
                {
                  v11 -= 4;
                  ++p_edge2;
                  ++p_edge1;
                  if ( v11 < 4 )
                    goto LABEL_18;
                }
                return 0;
              }
LABEL_18:
              if ( v11 != 0
                && (LOBYTE(p_edge2->Type) != LOBYTE(p_edge1->Type)
                 || v11 > 1
                 && (BYTE1(p_edge2->Type) != BYTE1(p_edge1->Type)
                  || v11 > 2 && BYTE2(p_edge2->Type) != BYTE2(p_edge1->Type))) )
              {
                return 0;
              }
              if ( v22 >= v23 )
                goto LABEL_25;
            }
            return 0;
          }
LABEL_25:
          v14 = v26;
          if ( v26 == 0 )
            v14 = v27;
          v15 = (int *)(v45 - v46);
          v44 = v14;
          ++v47;
          if ( v14 - (int)v15 - 8 >= v15[1] )
          {
            v16 = *v15;
            if ( v16 != 0 )
            {
              v44 = v16 + 8;
              v45 = v16 + 8;
              v46 = 8;
            }
            else
            {
              v44 = 0;
            }
          }
          if ( v30 >= v31 )
          {
            v17 = v34;
            if ( v34 == 0 )
              v17 = v35;
            ++v41;
            v18 = (int *)(v6 - v5);
            v38 = v17;
            if ( v17 - (int)v18 - 8 >= v18[1] )
            {
              v19 = *v18;
              if ( v19 != 0 )
              {
                v6 = v19 + 8;
                v38 = v19 + 8;
                v5 = 8;
                v39 = v19 + 8;
                v40 = 8;
              }
              else
              {
                v38 = 0;
              }
            }
          }
          if ( v47 < v48 )
            goto LABEL_5;
          return 1;
        }
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101490C0
// Name: protected: void GFxShapeBase::ComputeBoundImpl<class GFxPathData>(class GRect<float> __near *)const
// Source: json
//------------------------------------------------------------------------------
_BYTE *__userpurge GFxShapeBase::ComputeBoundImpl<GFxPathData>@<eax>(int a1@<ecx>, int a2@<ebx>, float *ay)
{
  bool v4; // zf
  _BYTE *result; // eax
  unsigned int v6; // edx
  _BYTE *v7; // edi
  double v8; // st7
  unsigned __int16 v9; // bx
  _DWORD *v10; // ecx
  int v11; // ecx
  double v12; // st6
  double v13; // st7
  double v14; // st5
  double v15; // st6
  double v16; // rtt
  double v17; // st6
  double v18; // st7
  unsigned int v19; // ecx
  double v20; // st7
  double v21; // st6
  double v22; // st5
  double v23; // st4
  double v24; // st3
  double v25; // st2
  double v26; // st2
  double v27; // st1
  double v28; // st7
  double v29; // st2
  double v30; // st6
  double v31; // st3
  double v32; // st7
  double v33; // st2
  double v34; // st3
  double v35; // st2
  double v36; // st3
  double v37; // st2
  double v38; // rtt
  double v39; // st2
  double v40; // st2
  bool v41; // c0
  bool v42; // c3
  double v43; // st3
  double v44; // st4
  double v45; // st4
  double v46; // st5
  double v47; // st3
  double v48; // st4
  double v49; // rt2
  double v50; // st4
  double v51; // st5
  unsigned int v52; // eax
  int v53; // [esp-4h] [ebp-74h]
  int v54; // [esp+0h] [ebp-70h]
  int v55; // [esp+4h] [ebp-6Ch]
  int v56; // [esp+8h] [ebp-68h] BYREF
  unsigned int v57; // [esp+Ch] [ebp-64h]
  unsigned int v58; // [esp+10h] [ebp-60h]
  int v59; // [esp+14h] [ebp-5Ch]
  int v60; // [esp+18h] [ebp-58h]
  _BYTE *v61; // [esp+24h] [ebp-4Ch]
  _BYTE *v62; // [esp+28h] [ebp-48h]
  float v63; // [esp+2Ch] [ebp-44h]
  int pathIter; // [esp+30h] [ebp-40h] BYREF
  _BYTE *v65; // [esp+34h] [ebp-3Ch]
  _BYTE *v66; // [esp+38h] [ebp-38h]
  int v67; // [esp+3Ch] [ebp-34h]
  int v68; // [esp+40h] [ebp-30h]
  int v69; // [esp+44h] [ebp-2Ch]
  unsigned int v70; // [esp+48h] [ebp-28h]
  unsigned int v71; // [esp+4Ch] [ebp-24h]
  float v72; // [esp+50h] [ebp-20h]
  GFxMovieView::HE_ReturnValueType edge; // [esp+54h] [ebp-1Ch] BYREF
  float v74; // [esp+58h] [ebp-18h]
  float v75; // [esp+5Ch] [ebp-14h]
  float v76; // [esp+60h] [ebp-10h]
  char v77; // [esp+64h] [ebp-Ch]
  float v78; // [esp+68h] [ebp-8h]
  float t; // [esp+6Ch] [ebp-4h]
  float aya; // [esp+78h] [ebp+8h]
  float ayo; // [esp+78h] [ebp+8h]
  float ayp; // [esp+78h] [ebp+8h]
  float ayb; // [esp+78h] [ebp+8h]
  float ayq; // [esp+78h] [ebp+8h]
  float ayc; // [esp+78h] [ebp+8h]
  float ayd; // [esp+78h] [ebp+8h]
  float ayr; // [esp+78h] [ebp+8h]
  float aye; // [esp+78h] [ebp+8h]
  float ayf; // [esp+78h] [ebp+8h]
  float ays; // [esp+78h] [ebp+8h]
  float ayt; // [esp+78h] [ebp+8h]
  float ayg; // [esp+78h] [ebp+8h]
  float ayu; // [esp+78h] [ebp+8h]
  float ayh; // [esp+78h] [ebp+8h]
  float ayv; // [esp+78h] [ebp+8h]
  float ayi; // [esp+78h] [ebp+8h]
  float ayw; // [esp+78h] [ebp+8h]
  float ayj; // [esp+78h] [ebp+8h]
  float ayk; // [esp+78h] [ebp+8h]
  float ayl; // [esp+78h] [ebp+8h]
  float aym; // [esp+78h] [ebp+8h]
  float ayn; // [esp+78h] [ebp+8h]

  *ay = 1.0e10;
  ay[1] = 1.0e10;
  pathIter = a1;
  v70 = 0;
  ay[2] = -1.0e10;
  ay[3] = -1.0e10;
  v4 = (*(_BYTE *)(a1 + 36) & 2) == 0;
  result = *(_BYTE **)(a1 + 52);
  v67 = *(_DWORD *)(a1 + 56);
  v68 = *(_DWORD *)(a1 + 60);
  v69 = *(_DWORD *)(a1 + 64);
  v6 = *(_DWORD *)(a1 + 56);
  v7 = result;
  v65 = result;
  v66 = result;
  v71 = v6;
  if ( v4 )
    v8 = 1.0;
  else
    v8 = 0.050000001;
  v72 = v8;
  if ( v6 != 0 )
  {
    v53 = a2;
    v9 = v69;
    while ( 1 )
    {
      if ( (*result & 7) != 0 )
      {
        GFxPathData::EdgesIterator::EdgesIterator(this: (CSOAContainer *)&v56, (int)&pathIter);
        t = (double)v59 * v63;
        aya = v63 * (double)v60;
        v78 = *ay;
        v12 = t;
        if ( t <= (double)v78 )
        {
          v13 = t;
        }
        else
        {
          v12 = v78;
          v13 = t;
        }
        v78 = v12;
        *ay = v78;
        v78 = ay[1];
        v14 = aya;
        if ( aya <= (double)v78 )
        {
          v15 = aya;
        }
        else
        {
          v14 = v78;
          v15 = aya;
        }
        v78 = v14;
        ay[1] = v78;
        v78 = ay[2];
        if ( v78 > v13 )
          v13 = v78;
        v16 = v15;
        v17 = v13;
        v18 = v16;
        v78 = v17;
        ay[2] = v78;
        v78 = ay[3];
        if ( v78 > v16 )
          v18 = v78;
        v19 = v57;
        v78 = v18;
        ay[3] = v78;
        if ( v19 < v58 )
        {
          do
          {
            GFxPathData::EdgesIterator::GetEdge(
              this: (CSOAContainer *)&v56,
              pedge: (const CSOAContainer *)&edge,
              doLines2CurveConv: 0,
              ax: v53,
              ay: v54,
              a6: v55,
              a7: v56,
              a8: v57,
              a9: v58,
              a10: v59,
              a11: v60);
            v20 = v76;
            v21 = v75;
            if ( v77 != 0 )
            {
              v22 = *(float *)&edge;
              v23 = t;
              v78 = v22 + v22 - t - v21;
              if ( 0.0 == v78 )
              {
                v24 = 0.0;
                v25 = -1.0;
              }
              else
              {
                v25 = (v22 - v23) / v78;
                v24 = 0.0;
              }
              t = v25;
              v26 = t;
              v27 = v74;
              if ( t <= v24 || v26 >= 1.0 )
              {
                v30 = aya;
                v39 = v76;
                v32 = v74;
              }
              else
              {
                v28 = t;
                v78 = (v22 - v23) * v26 + v23;
                t = (v27 - aya) * v26 + aya;
                v29 = (v21 - v22) * v26 + v22;
                v30 = aya;
                ayo = v29;
                v78 = (ayo - v78) * v28 + v78;
                ayp = (v76 - v27) * v28 + v27;
                v31 = v28 * (ayp - t) + t;
                v32 = v74;
                t = v31;
                ayb = *ay;
                v33 = v78;
                if ( v78 <= (double)ayb )
                {
                  v34 = v78;
                }
                else
                {
                  v33 = ayb;
                  v34 = v78;
                }
                ayq = v33;
                *ay = ayq;
                ayc = ay[1];
                v35 = t;
                if ( t <= (double)ayc )
                  ayc = t;
                ay[1] = ayc;
                ayd = ay[2];
                if ( ayd <= v34 )
                {
                  v38 = v35;
                  v37 = v34;
                  v36 = v38;
                }
                else
                {
                  v36 = v35;
                  v37 = ayd;
                }
                ayr = v37;
                ay[2] = ayr;
                aye = ay[3];
                if ( aye <= v36 )
                  aye = v36;
                ay[3] = aye;
                v24 = 0.0;
                v39 = v76;
              }
              ayf = v32 + v32 - v30 - v39;
              if ( v24 == ayf )
                v40 = -1.0;
              else
                v40 = (v32 - v30) / ayf;
              t = v40;
              v41 = t < v24;
              v42 = t == v24;
              v43 = t;
              if ( v41 || v42 || v43 >= 1.0 )
              {
                v20 = v76;
                v21 = v75;
              }
              else
              {
                v78 = v23 + (v22 - v23) * v43;
                t = v30 + (v32 - v30) * v43;
                ays = v22 + (v75 - v22) * v43;
                v78 = (ays - v78) * v43 + v78;
                v44 = v32 + (v76 - v32) * v43;
                v20 = v76;
                ayt = v44;
                v21 = v75;
                t = v43 * (ayt - t) + t;
                ayg = *ay;
                v45 = v78;
                if ( v78 <= (double)ayg )
                {
                  v46 = v78;
                }
                else
                {
                  v45 = ayg;
                  v46 = v78;
                }
                ayu = v45;
                *ay = ayu;
                ayh = ay[1];
                v47 = t;
                if ( t <= (double)ayh )
                {
                  v48 = t;
                }
                else
                {
                  v47 = ayh;
                  v48 = t;
                }
                ayv = v47;
                ay[1] = ayv;
                ayi = ay[2];
                if ( ayi > v46 )
                  v46 = ayi;
                v49 = v48;
                v50 = v46;
                v51 = v49;
                ayw = v50;
                ay[2] = ayw;
                ayj = ay[3];
                if ( ayj <= v49 )
                  ayj = v51;
                ay[3] = ayj;
              }
            }
            ayk = *ay;
            if ( ayk >= v21 )
              ayk = v21;
            *ay = ayk;
            ayl = ay[1];
            if ( ayl >= v20 )
              ayl = v20;
            ay[1] = ayl;
            aym = ay[2];
            if ( aym <= v21 )
              aym = v21;
            ay[2] = aym;
            ayn = ay[3];
            if ( ayn <= v20 )
              ayn = v20;
            v52 = v57;
            ay[3] = ayn;
            t = v21;
            aya = v20;
          }
          while ( v52 < v58 );
        }
        result = v61;
        if ( v61 == nullptr )
          result = v62;
      }
      else
      {
        if ( v70 >= v6 )
          return result;
        ++result;
      }
      ++v70;
      v10 = &v7[-v9];
      v65 = result;
      if ( result - (_BYTE *)v10 - 8 >= v10[1] )
      {
        v11 = *v10;
        if ( v11 != 0 )
        {
          result = (_BYTE *)(v11 + 8);
          v9 = 8;
          v7 = (_BYTE *)(v11 + 8);
          LOWORD(v69) = 8;
          v66 = (_BYTE *)(v11 + 8);
        }
        else
        {
          result = nullptr;
        }
        v65 = result;
      }
      if ( v70 >= v71 )
        break;
      v6 = v71;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10149600
// Name: protected: unsigned long GFxShapeBase::ComputeGeometryHashImpl<class GFxSwfPathData>(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxShapeBase::ComputeGeometryHashImpl<GFxSwfPathData>(CFltX4AttributeIterator *this)
{
  void (__thiscall *v2)(CFltX4AttributeIterator *, unsigned int *, unsigned int *); // eax
  int v3; // eax
  int i; // ecx
  int v5; // edx
  int j; // ecx
  int v7; // edx
  int v8; // edx
  int k; // ebx
  char v10; // dl
  int v11; // eax
  int v12; // esi
  int v13; // ecx
  int v14; // ecx
  int v15; // eax
  int v16; // esi
  const GPtr<GFxJpegSupportBase> **p_edge; // eax
  const GPtr<GFxJpegSupportBase> *v18; // ecx
  int v19; // edx
  int v20; // eax
  int m; // ecx
  int v22; // edx
  GFxSwfPathData::PathsIterator pit[5]; // [esp+Ch] [ebp-A8h] BYREF
  int v25; // [esp+20h] [ebp-94h]
  int v26; // [esp+24h] [ebp-90h]
  int v27; // [esp+28h] [ebp-8Ch]
  char v28; // [esp+2Ch] [ebp-88h]
  int v29; // [esp+38h] [ebp-7Ch]
  int v30; // [esp+3Ch] [ebp-78h]
  int v31; // [esp+60h] [ebp-54h]
  int v32; // [esp+64h] [ebp-50h]
  const GPtr<GFxJpegSupportBase> *v33; // [esp+68h] [ebp-4Ch]
  int v34; // [esp+6Ch] [ebp-48h]
  const GPtr<GFxJpegSupportBase> *v35; // [esp+70h] [ebp-44h]
  int v36; // [esp+74h] [ebp-40h]
  float v37; // [esp+78h] [ebp-3Ch]
  char v38; // [esp+7Ch] [ebp-38h]
  char v39; // [esp+7Fh] [ebp-35h]
  unsigned int pathsCnt; // [esp+80h] [ebp-34h] BYREF
  unsigned int shapesCnt; // [esp+84h] [ebp-30h] BYREF
  float v42; // [esp+88h] [ebp-2Ch]
  float v43; // [esp+8Ch] [ebp-28h]
  const GPtr<GFxJpegSupportBase> *edge; // [esp+90h] [ebp-24h] BYREF
  int v45; // [esp+94h] [ebp-20h]
  _DWORD v46[2]; // [esp+98h] [ebp-1Ch] BYREF
  _DWORD v47[4]; // [esp+A0h] [ebp-14h] BYREF

  v2 = (void (__thiscall *)(CFltX4AttributeIterator *, unsigned int *, unsigned int *))this->m_pData[4].m128_i32[1];
  shapesCnt = 0;
  pathsCnt = 0;
  v2(a1: this, a2: &shapesCnt, a3: &pathsCnt);
  v3 = 5381;
  for ( i = 4; i != 0; --i )
  {
    v5 = *((unsigned __int8 *)&pathsCnt + i + 3);
    v3 = v5 ^ (33 * v3);
  }
  for ( j = 4; j != 0; --j )
  {
    v7 = (unsigned __int8)*(&v39 + j);
    v8 = (33 * v3) ^ v7;
    v3 = v8;
  }
  k = v8;
  GFxSwfPathData::PathsIterator::PathsIterator(this: pit, a2: this);
  v10 = v28;
  if ( v28 != 1 )
  {
LABEL_6:
    v47[1] = v25;
    v47[3] = v27;
    v47[2] = v26;
    v11 = 12;
    v12 = k;
    do
    {
      v13 = *((unsigned __int8 *)v47 + v11-- + 3);
      v12 = v13 ^ (33 * v12);
    }
    while ( v11 != 0 );
    if ( v10 >= 0 && v10 != 1 )
    {
      do
      {
        GFxSwfPathData::PathsIterator::ReadNext(this: (IKMeansErrorMetric *)pit);
        v10 = v28;
      }
      while ( v28 == 3 );
    }
    v42 = (float)v29;
    v43 = (float)v30;
    if ( v38 < 0 )
    {
      v42 = v37 * v42;
      v43 = v37 * v43;
    }
    v14 = 8;
    v15 = v12;
    do
    {
      v16 = *((unsigned __int8 *)&shapesCnt + v14-- + 3);
      v15 = v16 ^ (33 * v15);
    }
    while ( v14 != 0 );
    for ( k = v15; ; k = m )
    {
      if ( v10 == 1 )
        return k;
      if ( v10 >= 0 )
        goto LABEL_6;
      p_edge = &edge;
      if ( (unsigned __int8)v10 == 132 )
      {
        v18 = v35;
        v19 = v36;
        v29 += (int)v35;
        v30 += v36;
        p_edge = (const GPtr<GFxJpegSupportBase> **)v46;
      }
      else
      {
        if ( (unsigned __int8)v10 != 133 )
          goto LABEL_23;
        v18 = v33;
        v19 = v34;
        v46[0] = v31;
        v29 += (int)v33 + v31;
        v46[1] = v32;
        v30 += v34 + v32;
        p_edge = (const GPtr<GFxJpegSupportBase> **)v47;
      }
      v45 = v19;
      edge = v18;
LABEL_23:
      v47[0] = p_edge - &edge;
      GFxSwfPathData::PathsIterator::ReadNext(this: (IKMeansErrorMetric *)pit);
      v20 = 4 * v47[0];
      for ( m = k; v20 != 0; m = (33 * m) ^ v22 )
        v22 = *((unsigned __int8 *)&v43 + v20-- + 3);
      v10 = v28;
    }
  }
  return k;
}

//------------------------------------------------------------------------------
// Address: 0x101497F0
// Name: public: void GFxSwfPathData::PathsIterator::Skip(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSwfPathData::PathsIterator::Skip(IKMeansErrorMetric *this)
{
  char v2; // al

  v2 = *((_BYTE *)this + 32);
  if ( v2 != 1 )
  {
    if ( v2 == 2 )
    {
      do
        GFxSwfPathData::PathsIterator::ReadNext(this);
      while ( *((_BYTE *)this + 32) == 3 );
    }
    else
    {
      GFxSwfPathData::PathsIterator::SkipComplex(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10149820
// Name: public: void GFxShapeBase::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxShapeBase::Release(GFxShapeBase *this)
{
  if ( InterlockedExchangeAdd(Addend: (volatile LONG *)this + 5, Value: -1) == 1 && this != nullptr )
    (**(void (__thiscall ***)(GFxShapeBase *, int))this)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x101499C0
// Name: public: virtual bool GFxConstShapeNoStyles::IsEqualGeometry(class GFxShapeBase const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxConstShapeNoStyles::IsEqualGeometry(
        CBitRead *this@<ecx>,
        CFltX4AttributeIterator *cmpWith,
        EBitCoordType a3)
{
  CFltX4AttributeIterator *v3; // esi
  _DWORD *v5; // ebx
  unsigned int v6; // edi
  unsigned int v7; // edx
  int v8; // ecx
  int v9; // esi
  int *m_pData; // esi
  unsigned int v11; // edx
  int v12; // ecx
  int v13; // edi
  unsigned int i; // ecx
  unsigned int v15; // [esp+Ch] [ebp-4h]
  int cmpWitha; // [esp+18h] [ebp+8h]

  v3 = cmpWith;
  if ( ((int (__thiscall *)(CFltX4AttributeIterator *))cmpWith->m_pData[4].m128_i32[0])(a1: cmpWith) != 0 )
  {
    GFxShapeBase::IsEqualGeometryImpl<GFxSwfPathData>((CFltX4AttributeIterator *)this, a2: cmpWith);
  }
  else
  {
    v5 = *((_DWORD **)this + 10);
    v6 = 0;
    v7 = 0;
    v15 = 0;
    v8 = 0;
    if ( ((*(unsigned __int8 *)v5 >> 3) & 3) != 0xFFFFFFFF )
    {
      do
      {
        v9 = *((unsigned __int8 *)v5 + ++v7) << v8;
        v8 += 8;
        v6 |= v9;
      }
      while ( v7 < ((*(unsigned __int8 *)v5 >> 3) & 3u) + 1 );
      v3 = cmpWith;
      v15 = v6;
    }
    m_pData = (int *)v3[5].m_pData;
    v11 = 0;
    cmpWitha = 0;
    v12 = 0;
    if ( ((*(unsigned __int8 *)m_pData >> 3) & 3) != 0xFFFFFFFF )
    {
      do
      {
        v13 = *((unsigned __int8 *)m_pData + ++v11) << v12;
        v12 += 8;
        cmpWitha |= v13;
      }
      while ( v11 < ((*(unsigned __int8 *)m_pData >> 3) & 3u) + 1 );
      v6 = v15;
    }
    if ( v6 == cmpWitha )
    {
      for ( i = v6; i >= 4; ++v5 )
      {
        if ( *v5 != *m_pData )
          break;
        i -= 4;
        ++m_pData;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10149AF0
// Name: public: virtual unsigned long GFxShapeNoStyles::ComputeGeometryHash(void)const
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
int __thiscall GFxShapeNoStyles::ComputeGeometryHash(_BYTE *this)
{
  return GFxShapeBase::ComputeGeometryHashImpl<GFxPathData>(this);
}

//------------------------------------------------------------------------------
// Address: 0x10149B00
// Name: public: virtual bool GFxShapeNoStyles::IsEqualGeometry(class GFxShapeBase const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxShapeNoStyles::IsEqualGeometry(
        CMemberFunctor0<CMaterialVar *,void (__thiscall CMaterialVar::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this,
        struct GFxShapeBase *cmpWith)
{
  GFxShapeBase::IsEqualGeometryImpl<GFxPathData>((struct GFxShapeBase *)this, a2: cmpWith);
}

//------------------------------------------------------------------------------
// Address: 0x10149B10
// Name: public: virtual void GFxShapeNoStyles::ComputeBound(class GRect<float> __near *)const
// Source: json
//------------------------------------------------------------------------------
CMemberFunctor0<CMaterialVar *,void (__thiscall CMaterialVar::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *__userpurge GFxShapeNoStyles::ComputeBound@<eax>(
        int a1@<ecx>,
        int a2@<ebx>,
        float *result)
{
  return (CMemberFunctor0<CMaterialVar *,void (__thiscall CMaterialVar::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)GFxShapeBase::ComputeBoundImpl<GFxPathData>(a1, a2, ay: result);
}

//------------------------------------------------------------------------------
// Address: 0x10149B20
// Name: public: virtual class GFxShapeBase::PathsIterator __near * GFxShapeNoStyles::GetPathsIterator(void)const
// Source: json
//------------------------------------------------------------------------------
struct GFxShapeBase::PathsIterator *__thiscall GFxShapeNoStyles::GetPathsIterator(GFxShapeNoStyles *this)
{
  void *v2; // eax
  int v4; // [esp+4h] [ebp-4h] BYREF

  v4 = 2;
  v2 = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 108, a4: &v4);
  if ( v2 != nullptr )
    return (struct GFxShapeBase::PathsIterator *)GFxVirtualPathIterator<GFxShapeNoStyles,GFxPathData>::GFxVirtualPathIterator<GFxShapeNoStyles,GFxPathData>(
                                                   this: (int)v2,
                                                   a2: (int)this);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10149B90
// Name: public: virtual void GFxShapeCharacterDef::ComputeBound(class GRect<float> __near *)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxShapeCharacterDef::ComputeBound(old_bf_read *this@<ecx>, int a2@<ebx>, float *a3)
{
  GFxShapeBase::ComputeBoundImpl<GFxPathData>(a1: (int)&this->m_bOverflow, a2, ay: a3);
}

//------------------------------------------------------------------------------
// Address: 0x10149BA0
// Name: public: virtual unsigned long GFxShapeCharacterDef::ComputeGeometryHash(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxShapeCharacterDef::ComputeGeometryHash(old_bf_read *this)
{
  GFxShapeBase::ComputeGeometryHashImpl<GFxPathData>(this: &this->m_bOverflow);
}

//------------------------------------------------------------------------------
// Address: 0x10149BB0
// Name: public: virtual bool GFxShapeCharacterDef::IsEqualGeometry(class GFxShapeBaseCharacterDef const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxShapeCharacterDef::IsEqualGeometry(old_bf_read *this@<ecx>, int cmpWith, int a3)
{
  struct GFxShapeBase *v4; // eax

  v4 = (struct GFxShapeBase *)(*(int (__thiscall **)(int))(*(_DWORD *)cmpWith + 64))(a1: cmpWith);
  GFxShapeBase::IsEqualGeometryImpl<GFxPathData>(this: (struct GFxShapeBase *)&this->m_bOverflow, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10149BD0
// Name: public: virtual unsigned long GFxConstShapeCharacterDef::ComputeGeometryHash(void)const
// Source: json
//------------------------------------------------------------------------------
const CMemberFunctor2<CMaterialVar *,void (__thiscall CMaterialVar::*)(unsigned long,void *),unsigned long,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *__thiscall GFxConstShapeCharacterDef::ComputeGeometryHash(
        CFltX4AttributeIterator *this)
{
  return (const CMemberFunctor2<CMaterialVar *,void (__thiscall CMaterialVar::*)(unsigned long,void *),unsigned long,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)GFxShapeBase::ComputeGeometryHashImpl<GFxSwfPathData>(this: this + 2);
}

//------------------------------------------------------------------------------
// Address: 0x10149BE0
// Name: public: virtual bool GFxConstShapeCharacterDef::IsEqualGeometry(class GFxShapeBaseCharacterDef const __near &)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxConstShapeCharacterDef::IsEqualGeometry(
        CFltX4AttributeIterator *this,
        const struct GFxShapeBaseCharacterDef *a2)
{
  CFltX4AttributeIterator *v3; // eax

  v3 = (CFltX4AttributeIterator *)(*(int (__thiscall **)(const struct GFxShapeBaseCharacterDef *))(*(_DWORD *)a2 + 64))(a1: a2);
  return GFxShapeBase::IsEqualGeometryImpl<GFxSwfPathData>(this: this + 2, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x10149C00
// Name: public: GFxVirtualPathIterator<class GFxConstShapeNoStyles,class GFxSwfPathData>::GFxVirtualPathIterator<class GFxConstShapeNoStyles,class GFxSwfPathData>(class GFxConstShapeNoStyles const __near *)
// Source: json
//------------------------------------------------------------------------------
IKMeansErrorMetric *__thiscall GFxVirtualPathIterator<GFxConstShapeNoStyles,GFxSwfPathData>::GFxVirtualPathIterator<GFxConstShapeNoStyles,GFxSwfPathData>(
        IKMeansErrorMetric *this,
        CFltX4AttributeIterator *a2)
{
  IKMeansErrorMetric *v3; // edi
  char v5; // al

  this->__vftable = (IKMeansErrorMetric_vtbl *)&GRefCountImplCore::`vftable';
  v3 = this + 2;
  *((_DWORD *)this + 1) = 1;
  this->__vftable = (IKMeansErrorMetric_vtbl *)&GFxVirtualPathIterator<GFxConstShapeNoStyles,GFxSwfPathData>::`vftable';
  GFxSwfPathData::PathsIterator::PathsIterator(this: (GFxSwfPathData::PathsIterator *)this + 2, a2);
  *((_DWORD *)this + 31) = 0;
  *((_DWORD *)this + 32) = 0;
  if ( *((_BYTE *)this + 40) == 1 )
  {
    *((_DWORD *)this + 33) = 4;
    return this;
  }
  else
  {
    *((_DWORD *)this + 33) = 0;
    *(this + 36) = v3[5];
    *(this + 37) = v3[6];
    *(this + 38) = v3[7];
    v5 = (char)v3[8].__vftable;
    if ( v5 >= 0 && v5 != 1 )
    {
      do
        GFxSwfPathData::PathsIterator::ReadNext(this: v3);
      while ( LOBYTE(v3[8].__vftable) == 3 );
    }
    *((_DWORD *)this + 32) = 0;
    *((_DWORD *)this + 31) = v3;
    *((float *)this + 34) = (float)(int)v3[11].__vftable;
    *((float *)this + 35) = (float)(int)v3[12].__vftable;
    if ( SLOBYTE(v3[28].__vftable) < 0 )
    {
      *((float *)this + 34) = *(float *)&v3[27].__vftable * *((float *)this + 34);
      *((float *)this + 35) = *((float *)this + 35) * *(float *)&v3[27].__vftable;
    }
    return this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10149D10
// Name: public: virtual bool GFxVirtualPathIterator<class GFxConstShapeNoStyles,class GFxSwfPathData>::GetNext(struct GFxShapeBase::PathsIterator::StateInfo __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall GFxVirtualPathIterator<GFxConstShapeNoStyles,GFxSwfPathData>::GetNext(int this, _DWORD *a2)
{
  int v3; // eax
  int v4; // eax
  char v5; // al
  GFxSwfPathData::EdgesIterator *v6; // ecx
  char v8; // al
  IKMeansErrorMetric **v9; // eax
  IKMeansErrorMetric *v10; // edx
  char v11; // cl
  double v12; // st7
  float v13[4]; // [esp+8h] [ebp-1Ch] BYREF
  char v14; // [esp+18h] [ebp-Ch]
  IKMeansErrorMetric *v15; // [esp+1Ch] [ebp-8h] BYREF

  *a2 = *(_DWORD *)(this + 132);
  a2[1] = *(_DWORD *)(this + 136);
  a2[2] = *(_DWORD *)(this + 140);
  a2[3] = *(_DWORD *)(this + 144);
  a2[4] = *(_DWORD *)(this + 148);
  a2[5] = *(_DWORD *)(this + 152);
  v3 = *(_DWORD *)(this + 132);
  if ( v3 == 0 )
    goto LABEL_4;
  v4 = v3 - 2;
  if ( v4 != 0 )
  {
    if ( v4 == 1 )
    {
LABEL_4:
      v5 = *(_BYTE *)(*(_DWORD *)(this + 124) + 32);
      v6 = (GFxSwfPathData::EdgesIterator *)(this + 124);
      if ( v5 >= 0 )
      {
        *(_DWORD *)(this + 132) = 2;
        return *a2 != 4;
      }
      GFxSwfPathData::EdgesIterator::GetEdge(this: v6, a2: (struct GFxSwfPathData::EdgesIterator::Edge *)v13, a3: false);
      v11 = v14;
      *(float *)(this + 136) = v13[0];
      v12 = v13[1];
      *(_DWORD *)(this + 132) = 3;
      *(float *)(this + 140) = v12;
      *(_BYTE *)(this + 152) = v11;
      *(float *)(this + 144) = v13[2];
      *(float *)(this + 148) = v13[3];
    }
  }
  else
  {
    v8 = *(_BYTE *)(this + 40);
    if ( v8 == 1 )
    {
      *(_DWORD *)(this + 132) = 4;
      return *a2 != 4;
    }
    if ( v8 == 2 )
      GFxSwfPathData::PathsIterator::Skip(this: (IKMeansErrorMetric *)(this + 8));
    *(_DWORD *)(this + 132) = 0;
    *(_DWORD *)(this + 144) = *(_DWORD *)(this + 28);
    *(_DWORD *)(this + 148) = *(_DWORD *)(this + 32);
    *(_DWORD *)(this + 152) = *(_DWORD *)(this + 36);
    v9 = GFxSwfPathData::EdgesIterator::EdgesIterator(this: &v15, a2: (IKMeansErrorMetric *)(this + 8));
    v10 = *v9;
    *(_DWORD *)(this + 124) = *v9;
    *(_DWORD *)(this + 128) = v9[1];
    *(float *)(this + 136) = (float)(int)v10[11].__vftable;
    *(float *)(this + 140) = (float)(int)v10[12].__vftable;
    if ( SLOBYTE(v10[28].__vftable) < 0 )
    {
      *(float *)(this + 136) = *(float *)(this + 136) * *(float *)&v10[27].__vftable;
      *(float *)(this + 140) = *(float *)(this + 140) * *(float *)&v10[27].__vftable;
      return *a2 != 4;
    }
  }
  return *a2 != 4;
}

//------------------------------------------------------------------------------
// Address: 0x10149F90
// Name: protected: void GFxShapeBase::ComputeBoundImpl<class GFxSwfPathData>(class GRect<float> __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxShapeBase::ComputeBoundImpl<GFxSwfPathData>(CFltX4AttributeIterator *this, float *ay)
{
  char result; // al
  double v4; // st6
  double v5; // st7
  double v6; // st5
  double v7; // st6
  double v8; // rt2
  double v9; // st6
  double v10; // st7
  double v11; // st7
  double v12; // st6
  double v13; // st5
  double v14; // st4
  double v15; // st3
  double v16; // st2
  double v17; // st2
  double v18; // st1
  double v19; // st7
  double v20; // st2
  double v21; // st6
  double v22; // st3
  double v23; // st7
  double v24; // st2
  double v25; // st3
  double v26; // st2
  double v27; // st3
  double v28; // st2
  double v29; // rt2
  double v30; // st2
  double v31; // st2
  bool v32; // c0
  bool v33; // c3
  double v34; // st3
  double v35; // st4
  double v36; // st4
  double v37; // st5
  double v38; // st3
  double v39; // st4
  double v40; // rt1
  double v41; // st4
  double v42; // st5
  GFxSwfPathData::PathsIterator it[8]; // [esp+4h] [ebp-98h] BYREF
  char v44; // [esp+24h] [ebp-78h]
  int v45; // [esp+30h] [ebp-6Ch]
  int v46; // [esp+34h] [ebp-68h]
  float v47; // [esp+70h] [ebp-2Ch]
  char v48; // [esp+74h] [ebp-28h]
  CSOAAttributeReferenceBinaryOp<&SubSIMD> edgesIt; // [esp+78h] [ebp-24h] BYREF
  float v50; // [esp+88h] [ebp-14h]
  float v51; // [esp+8Ch] [ebp-10h]
  char v52; // [esp+90h] [ebp-Ch]
  float t; // [esp+94h] [ebp-8h]
  float v54; // [esp+98h] [ebp-4h]
  float aya; // [esp+A4h] [ebp+8h]
  float ayo; // [esp+A4h] [ebp+8h]
  float ayp; // [esp+A4h] [ebp+8h]
  float ayb; // [esp+A4h] [ebp+8h]
  float ayq; // [esp+A4h] [ebp+8h]
  float ayc; // [esp+A4h] [ebp+8h]
  float ayd; // [esp+A4h] [ebp+8h]
  float ayr; // [esp+A4h] [ebp+8h]
  float aye; // [esp+A4h] [ebp+8h]
  float ayf; // [esp+A4h] [ebp+8h]
  float ays; // [esp+A4h] [ebp+8h]
  float ayt; // [esp+A4h] [ebp+8h]
  float ayg; // [esp+A4h] [ebp+8h]
  float ayu; // [esp+A4h] [ebp+8h]
  float ayh; // [esp+A4h] [ebp+8h]
  float ayv; // [esp+A4h] [ebp+8h]
  float ayi; // [esp+A4h] [ebp+8h]
  float ayw; // [esp+A4h] [ebp+8h]
  float ayj; // [esp+A4h] [ebp+8h]
  float ayk; // [esp+A4h] [ebp+8h]
  float ayl; // [esp+A4h] [ebp+8h]
  float aym; // [esp+A4h] [ebp+8h]
  float ayn; // [esp+A4h] [ebp+8h]

  *ay = 1.0e10;
  ay[1] = 1.0e10;
  ay[2] = -1.0e10;
  ay[3] = -1.0e10;
  GFxSwfPathData::PathsIterator::PathsIterator(this: it, a2: this);
  result = v44;
  while ( result != 1 )
  {
    if ( result == 2 )
    {
      do
      {
        GFxSwfPathData::PathsIterator::ReadNext(this: (IKMeansErrorMetric *)it);
        result = v44;
      }
      while ( v44 == 3 );
    }
    else
    {
      edgesIt.m_opA.m_pContainer = (CSOAContainer *)it;
      edgesIt.m_opA.m_nAttributeID = 0;
      if ( result >= 0 && result != 1 )
      {
        do
          GFxSwfPathData::PathsIterator::ReadNext(this: (IKMeansErrorMetric *)it);
        while ( v44 == 3 );
      }
      t = (float)v45;
      aya = (float)v46;
      if ( v48 < 0 )
      {
        t = v47 * t;
        aya = v47 * aya;
      }
      v54 = *ay;
      v4 = t;
      if ( t <= (double)v54 )
      {
        v5 = t;
      }
      else
      {
        v4 = v54;
        v5 = t;
      }
      v54 = v4;
      *ay = v54;
      v54 = ay[1];
      v6 = aya;
      if ( aya <= (double)v54 )
      {
        v7 = aya;
      }
      else
      {
        v6 = v54;
        v7 = aya;
      }
      v54 = v6;
      ay[1] = v54;
      v54 = ay[2];
      if ( v54 > v5 )
        v5 = v54;
      v8 = v7;
      v9 = v5;
      v10 = v8;
      v54 = v9;
      ay[2] = v54;
      v54 = ay[3];
      if ( v54 > v8 )
        v10 = v54;
      v54 = v10;
      ay[3] = v54;
      while ( SLOBYTE(edgesIt.m_opA.m_pContainer->m_pAttributePtrs[2]) < 0 )
      {
        GFxSwfPathData::EdgesIterator::GetEdge(
          this: &edgesIt,
          a2: (struct GFxSwfPathData::EdgesIterator::Edge *)&edgesIt.m_opB,
          a3: false);
        v11 = v51;
        v12 = v50;
        if ( v52 != 0 )
        {
          v13 = *(float *)&edgesIt.m_opB.m_pContainer;
          v14 = t;
          v54 = v13 + v13 - t - v12;
          if ( 0.0 == v54 )
          {
            v15 = 0.0;
            v16 = -1.0;
          }
          else
          {
            v16 = (v13 - v14) / v54;
            v15 = 0.0;
          }
          t = v16;
          v17 = t;
          v18 = *(float *)&edgesIt.m_opB.m_nAttributeID;
          if ( t <= v15 || v17 >= 1.0 )
          {
            v21 = aya;
            v30 = v51;
            v23 = *(float *)&edgesIt.m_opB.m_nAttributeID;
          }
          else
          {
            v19 = t;
            v54 = (v13 - v14) * v17 + v14;
            t = (v18 - aya) * v17 + aya;
            v20 = (v12 - v13) * v17 + v13;
            v21 = aya;
            ayo = v20;
            v54 = (ayo - v54) * v19 + v54;
            ayp = (v51 - v18) * v19 + v18;
            v22 = v19 * (ayp - t) + t;
            v23 = *(float *)&edgesIt.m_opB.m_nAttributeID;
            t = v22;
            ayb = *ay;
            v24 = v54;
            if ( v54 <= (double)ayb )
            {
              v25 = v54;
            }
            else
            {
              v24 = ayb;
              v25 = v54;
            }
            ayq = v24;
            *ay = ayq;
            ayc = ay[1];
            v26 = t;
            if ( t <= (double)ayc )
              ayc = t;
            ay[1] = ayc;
            ayd = ay[2];
            if ( ayd <= v25 )
            {
              v29 = v26;
              v28 = v25;
              v27 = v29;
            }
            else
            {
              v27 = v26;
              v28 = ayd;
            }
            ayr = v28;
            ay[2] = ayr;
            aye = ay[3];
            if ( aye <= v27 )
              aye = v27;
            ay[3] = aye;
            v15 = 0.0;
            v30 = v51;
          }
          ayf = v23 + v23 - v21 - v30;
          if ( v15 == ayf )
            v31 = -1.0;
          else
            v31 = (v23 - v21) / ayf;
          t = v31;
          v32 = t < v15;
          v33 = t == v15;
          v34 = t;
          if ( v32 || v33 || v34 >= 1.0 )
          {
            v11 = v51;
            v12 = v50;
          }
          else
          {
            v54 = v14 + (v13 - v14) * v34;
            t = v21 + (v23 - v21) * v34;
            ays = v13 + (v50 - v13) * v34;
            v54 = (ays - v54) * v34 + v54;
            v35 = v23 + (v51 - v23) * v34;
            v11 = v51;
            ayt = v35;
            v12 = v50;
            t = v34 * (ayt - t) + t;
            ayg = *ay;
            v36 = v54;
            if ( v54 <= (double)ayg )
            {
              v37 = v54;
            }
            else
            {
              v36 = ayg;
              v37 = v54;
            }
            ayu = v36;
            *ay = ayu;
            ayh = ay[1];
            v38 = t;
            if ( t <= (double)ayh )
            {
              v39 = t;
            }
            else
            {
              v38 = ayh;
              v39 = t;
            }
            ayv = v38;
            ay[1] = ayv;
            ayi = ay[2];
            if ( ayi > v37 )
              v37 = ayi;
            v40 = v39;
            v41 = v37;
            v42 = v40;
            ayw = v41;
            ay[2] = ayw;
            ayj = ay[3];
            if ( ayj <= v40 )
              ayj = v42;
            ay[3] = ayj;
          }
        }
        ayk = *ay;
        if ( ayk >= v12 )
          ayk = v12;
        *ay = ayk;
        ayl = ay[1];
        if ( ayl >= v11 )
          ayl = v11;
        ay[1] = ayl;
        aym = ay[2];
        if ( aym <= v12 )
          aym = v12;
        ay[2] = aym;
        ayn = ay[3];
        if ( ayn <= v11 )
          ayn = v11;
        ay[3] = ayn;
        t = v12;
        aya = v11;
      }
      result = v44;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1014A490
// Name: public: void GFxShapeBase::AddShapeToMesh(class GFxMeshSet __near *,class GCompoundShape __near *,class GFxDisplayContext __near &,struct GFxScale9GridInfo __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxShapeBase::AddShapeToMesh(
        GFxShapeBase *this,
        struct GFxMeshSet *meshSet,
        struct GCompoundShape *meshSet_4,
        struct GFxDisplayContext *s9g,
        struct GFxScale9GridInfo *s9g_4)
{
  bool v6; // zf
  int Texture9GridStyle; // esi
  CMaterialVar *v8; // ecx
  GFxMeshSet *v9; // esi
  GFxMeshSet *v10; // esi
  __int128 v11; // [esp+4h] [ebp-1D8h]
  char *maxLen; // [esp+8h] [ebp-1D4h]
  int v13; // [esp+14h] [ebp-1C8h]
  CCountedStringPoolBase<unsigned int>::hash_item_t result; // [esp+18h] [ebp-1C4h] BYREF
  float v15; // [esp+24h] [ebp-1B8h]
  float v16; // [esp+28h] [ebp-1B4h]
  float v17; // [esp+2Ch] [ebp-1B0h]
  struct GFxDisplayContext *v18; // [esp+30h] [ebp-1ACh]
  GFxMeshSet *v19; // [esp+34h] [ebp-1A8h]
  unsigned int fillStylesNum; // [esp+38h] [ebp-1A4h] BYREF
  int p; // [esp+3Ch] [ebp-1A0h] BYREF
  float v22; // [esp+40h] [ebp-19Ch]
  struct GFxFillStyle *v23; // [esp+44h] [ebp-198h]
  _BYTE v24[340]; // [esp+48h] [ebp-194h] BYREF
  struct GRenderer::FillTexture scaleMultiplier; // [esp+19Ch] [ebp-40h] BYREF
  CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > v26; // [esp+1C0h] [ebp-1Ch] BYREF
  float v27; // [esp+1D4h] [ebp-8h]

  v18 = s9g;
  v19 = meshSet;
  GMatrix2D::SetIdentity(result: (const CMaterialDict::MissingMaterial_t *)DWORD2(v11));
  GFxTexture9Grid::GFxTexture9Grid(this: (GFxTexture9Grid *)v24);
  *(float *)&result.nReferenceCount = 0.0;
  v6 = (*((_BYTE *)this + 36) & 0x40) == 0;
  v15 = 0.0;
  v16 = 0.0;
  v23 = nullptr;
  v17 = 0.0;
  fillStylesNum = 0;
  if ( !v6 )
    v23 = (struct GFxFillStyle *)(*(int (__thiscall **)(GFxShapeBase *, unsigned int *))(*(_DWORD *)this + 36))(
                                   a1: this,
                                   a2: &fillStylesNum);
  if ( (*((_BYTE *)this + 36) & 0xC0) == 0 )
    goto LABEL_9;
  if ( s9g_4 == nullptr )
  {
LABEL_11:
    v9 = v19;
    v22 = *((float *)v19 + 2) * 0.25;
    GCompoundShape::RemoveShortSegments(
      this: (long double *)meshSet_4,
      maxLen: (char *)LODWORD(v22),
      j: DWORD2(v11),
      i: SHIDWORD(v11),
      start: v13,
      num: (int)result.pString,
      v1: (localeinfo_struct *)result.nNextElement);
    GFxMeshSet::AddTessellatedShape(
      this: v9,
      a2: meshSet_4,
      a3: v23,
      idx: fillStylesNum,
      a5: v18,
      a6: *((const struct GFxRenderConfig **)v18 + 18));
    return;
  }
  if ( *((_BYTE *)s9g_4 + 92) == 0 )
    goto LABEL_9;
  Texture9GridStyle = GFxShapeBase::GetTexture9GridStyle(this, a2: meshSet_4);
  if ( Texture9GridStyle < 0 )
    goto LABEL_9;
  GFxFillStyle::GetFillTexture(
    this: (GFxFillStyle *)((char *)v23 + 40 * Texture9GridStyle),
    &scaleMultiplier,
    a3: v18,
    a4: 1.0,
    a5: nullptr);
  *(float *)&v26.m_Memory.m_pMemory = scaleMultiplier.TextureMatrix.M_[0][0];
  *(float *)&v26.m_Memory.m_nAllocationCount = scaleMultiplier.TextureMatrix.M_[0][1];
  *(float *)&v26.m_Size = scaleMultiplier.TextureMatrix.M_[1][0];
  *(float *)&v26.m_pElements = scaleMultiplier.TextureMatrix.M_[1][1];
  *(float *)&v26.m_Memory.m_nGrowSize = 0.0;
  v27 = 0.0;
  *(float *)&p = 1.0;
  v22 = 0.0;
  GMatrix2D::Transform(this: &v26, &result, (int)&p, a4: SDWORD2(v11));
  v22 = fabs(*(float *)&result.pString);
  if ( v22 > 0.000001 )
  {
    v22 = fabs(*(float *)&result.nNextElement);
    if ( v22 > 0.000001 )
    {
LABEL_9:
      if ( s9g_4 != nullptr )
      {
        GFxScale9GridInfo::ComputeImgAdjustRects(this: (CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,LightDesc_t const *),int,LightDesc_t const *,CFuncMemPolicyNone> *)s9g_4);
        *(_QWORD *)&v11 = __PAIR64__((unsigned int)s9g_4, (unsigned int)meshSet_4);
        GFxShapeBase::ApplyScale9Grid(shape: v8, sg: v11);
      }
      goto LABEL_11;
    }
  }
  GCompoundShape::PerceiveBounds(this: (int *)meshSet_4, x1: (_iobuf *)&result.nReferenceCount);
  maxLen = (char *)Texture9GridStyle;
  v10 = v19;
  GFxTexture9Grid::Compute(a1: v24, a2: s9g_4, a3: &result.nReferenceCount, a4: *((float *)v19 + 3), a5: maxLen);
  GFxMeshSet::AddTexture9Grid(this: v10, a2: (const struct GFxTexture9Grid *)v24);
}

//------------------------------------------------------------------------------
// Address: 0x1014A6E0
// Name: public: GFxPathPacker::GFxPathPacker(void)
// Source: json
//------------------------------------------------------------------------------
GFxPathPacker *__thiscall GFxPathPacker::GFxPathPacker(GFxPathPacker *this)
{
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 8) = 0;
  *((_DWORD *)this + 9) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 1) = 0;
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 12) = 0;
  *((_WORD *)this + 26) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1014A710
// Name: public: virtual void GFxConstShapeNoStyles::ComputeBound(class GRect<float> __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxConstShapeNoStyles::ComputeBound(CFltX4AttributeIterator *this, float *ay)
{
  return GFxShapeBase::ComputeBoundImpl<GFxSwfPathData>(this, ay);
}

//------------------------------------------------------------------------------
// Address: 0x1014A720
// Name: public: virtual class GFxShapeBase::PathsIterator __near * GFxConstShapeNoStyles::GetPathsIterator(void)const
// Source: json
//------------------------------------------------------------------------------
IKMeansErrorMetric *__thiscall GFxConstShapeNoStyles::GetPathsIterator(CFltX4AttributeIterator *this)
{
  IKMeansErrorMetric *v2; // eax
  int v4; // [esp+4h] [ebp-4h] BYREF

  v4 = 2;
  v2 = (IKMeansErrorMetric *)GMemory::pGlobalHeap->AllocAutoHeap_2(
                               this: GMemory::pGlobalHeap,
                               a2: this,
                               a3: 156,
                               a4: &v4);
  if ( v2 != nullptr )
    return GFxVirtualPathIterator<GFxConstShapeNoStyles,GFxSwfPathData>::GFxVirtualPathIterator<GFxConstShapeNoStyles,GFxSwfPathData>(
             this: v2,
             a2: this);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1014A760
// Name: public: void GFxSwfPathData::PathsIterator::AddForTessellation(class GCompoundShape __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxSwfPathData::PathsIterator::AddForTessellation(
        GFxSwfPathData::PathsIterator *this,
        GCompoundShape *a2)
{
  char v3; // al
  bool v4; // zf
  unsigned int v5; // edi
  unsigned int v6; // edi
  float v7[2]; // [esp+1Ch] [ebp-28h] BYREF
  CSOAContainer *v8; // [esp+24h] [ebp-20h]
  float v9; // [esp+28h] [ebp-1Ch]
  char v10; // [esp+2Ch] [ebp-18h]
  GFxSwfPathData::EdgesIterator v11; // [esp+30h] [ebp-14h] BYREF
  float v12; // [esp+40h] [ebp-4h]

  v3 = *((_BYTE *)this + 32);
  v11.m_opA.m_pContainer = (CSOAContainer *)this;
  v11.m_opA.m_nAttributeID = 0;
  if ( v3 >= 0 && v3 != 1 )
  {
    do
      GFxSwfPathData::PathsIterator::ReadNext((IKMeansErrorMetric *)this);
    while ( *((_BYTE *)this + 32) == 3 );
  }
  v4 = *((_BYTE *)this + 112) >= 0;
  *(float *)&v11.m_opB.m_nAttributeID = (float)*((int *)this + 11);
  v12 = (float)*((int *)this + 12);
  if ( !v4 )
  {
    *(float *)&v11.m_opB.m_nAttributeID = *(float *)&v11.m_opB.m_nAttributeID * *((float *)this + 27);
    v12 = v12 * *((float *)this + 27);
  }
  GCompoundShape::BeginPath(this: (char *)a2, lStyle: (localeinfo_struct *)(*((_DWORD *)this + 5) - 1));
  while ( SLOBYTE(v11.m_opA.m_pContainer->m_pAttributePtrs[2]) < 0 )
  {
    GFxSwfPathData::EdgesIterator::GetEdge(this: &v11, a2: (struct GFxSwfPathData::EdgesIterator::Edge *)v7, a3: false);
    if ( v10 != 0 )
    {
      GCompoundShape::AddCurve(this: a2, a2: v7[0], a3: v7[1], a4: *(float *)&v8, a5: v9);
    }
    else
    {
      v5 = *((_DWORD *)a2 + 2);
      v11.m_opB.m_pContainer = v8;
      v6 = v5 >> 8;
      *(float *)&v11.m_opB.m_nAttributeID = v9;
      if ( v6 >= *((_DWORD *)a2 + 3) )
        GArrayPagedBase<GPointType,8,64,GAllocatorPagedLH_POD<GPointType,138>>::allocatePage(a1: v6);
      *(CSOAAttributeReference *)(*(_DWORD *)(*((_DWORD *)a2 + 5) + 4 * v6)
                                + 8 * (unsigned __int8)(*((_DWORD *)a2 + 2))++) = v11.m_opB;
      ++*(_DWORD *)(*((_DWORD *)a2 + 10) + 4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014A890
// Name: public: void GFxPathData::PathsIterator::AddForTessellation(class GCompoundShape __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxPathData::PathsIterator::AddForTessellation(
        CSOAContainer *this@<ecx>,
        int a2@<edi>,
        CSOAContainer *cs,
        int edge,
        int fill0,
        int line,
        int fill1)
{
  CSOAContainer *v8; // esi
  unsigned int m_nSlices; // edi
  unsigned int v10; // edi
  int v11; // ecx
  int v12; // eax
  int v13; // ecx
  int m_pDataMemory_low; // edx
  int v15; // eax
  int *v16; // eax
  int v17; // eax
  int v18; // [esp+10h] [ebp-5Ch]
  int v19; // [esp+14h] [ebp-58h]
  int v20; // [esp+18h] [ebp-54h]
  int v21; // [esp+1Ch] [ebp-50h] BYREF
  unsigned int v22; // [esp+20h] [ebp-4Ch]
  unsigned int v23; // [esp+24h] [ebp-48h]
  int v24; // [esp+28h] [ebp-44h]
  int v25; // [esp+2Ch] [ebp-40h]
  int v26; // [esp+38h] [ebp-34h]
  int v27; // [esp+3Ch] [ebp-30h]
  float v28; // [esp+40h] [ebp-2Ch]
  GFxMovieView::HE_ReturnValueType edgea; // [esp+44h] [ebp-28h] BYREF
  float v30; // [esp+48h] [ebp-24h]
  float v31; // [esp+4Ch] [ebp-20h]
  float v32; // [esp+50h] [ebp-1Ch]
  char v33; // [esp+54h] [ebp-18h]
  float v34; // [esp+58h] [ebp-14h]
  unsigned int fill0a; // [esp+5Ch] [ebp-10h] BYREF
  unsigned int fill1a; // [esp+60h] [ebp-Ch] BYREF
  unsigned int linea; // [esp+64h] [ebp-8h] BYREF
  float v38; // [esp+68h] [ebp-4h]

  GFxPathData::EdgesIterator::EdgesIterator(this: (CSOAContainer *)&v21, pathIter: (int)this);
  GFxPathData::PathsIterator::GetStyles((GFxPathData::PathsIterator *)this, a2: &fill0a, a3: &fill1a, a4: &linea);
  v8 = cs;
  v38 = v28 * (double)v24;
  GCompoundShape::BeginPath(this: (char *)cs, lStyle: (localeinfo_struct *)(fill0a - 1));
  if ( v22 < v23 )
  {
    v18 = a2;
    do
    {
      GFxPathData::EdgesIterator::GetEdge(
        this: (CSOAContainer *)&v21,
        pedge: (const CSOAContainer *)&edgea,
        doLines2CurveConv: 0,
        ax: v18,
        ay: v19,
        a6: v20,
        a7: v21,
        a8: v22,
        a9: v23,
        a10: v24,
        a11: v25);
      if ( v33 != 0 )
      {
        GCompoundShape::AddCurve(this: (GCompoundShape *)v8, a2: *(float *)&edgea, a3: v30, a4: v31, a5: v32);
      }
      else
      {
        m_nSlices = v8->m_nSlices;
        v34 = v31;
        v10 = m_nSlices >> 8;
        *(float *)&fill0a = v32;
        if ( v10 >= v8->m_nPaddedColumns )
          GArrayPagedBase<GPointType,8,64,GAllocatorPagedLH_POD<GPointType,138>>::allocatePage(a1: v10);
        v11 = *(_DWORD *)&v8->m_pDataMemory[4 * v10];
        v12 = (unsigned __int8)v8->m_nSlices;
        *(float *)(v11 + 8 * v12) = v34;
        *(float *)(v11 + 8 * v12 + 4) = *(float *)&fill0a;
        ++v8->m_nSlices;
        ++*((_DWORD *)cs->m_pAttributePtrs[4] + 1);
        v8 = cs;
      }
    }
    while ( v22 < v23 );
  }
  v13 = v26;
  if ( v26 == 0 )
    v13 = v27;
  m_pDataMemory_low = LOWORD(this->m_pDataMemory);
  v15 = this->m_nSlices;
  ++this->m_pAttributePtrs[0];
  this->m_nRows = v13;
  v16 = (int *)(v15 - m_pDataMemory_low);
  if ( v13 - (int)v16 - 8 >= v16[1] )
  {
    v17 = *v16;
    if ( v17 != 0 )
    {
      this->m_nRows = v17 + 8;
      this->m_nSlices = v17 + 8;
      LOWORD(this->m_pDataMemory) = 8;
    }
    else
    {
      this->m_nRows = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014A9F0
// Name: public: virtual void GFxConstShapeCharacterDef::ComputeBound(class GRect<float> __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxConstShapeCharacterDef::ComputeBound(CFltX4AttributeIterator *this, float *a2)
{
  return GFxShapeBase::ComputeBoundImpl<GFxSwfPathData>(this: this + 2, ay: a2);
}

//------------------------------------------------------------------------------
// Address: 0x1014AA00
// Name: protected: void GFxShapeBase::TessellateImpl<class GFxSwfPathData>(class GFxMeshSet __near *,float,class GFxDisplayContext __near &,struct GFxScale9GridInfo __near *,float)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxShapeBase::TessellateImpl<GFxSwfPathData>(
        GFxShapeBase *this,
        struct GFxMeshSet *a2,
        char *a3,
        int a4,
        CMemberFuncProxy1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(Vector),Vector,CFuncMemPolicyNone> *a5,
        float a6)
{
  struct GFxScale9GridInfo *v6; // esi
  GFxAmpViewStats *v8; // ecx
  int v9; // eax
  float v10; // ecx
  int v11; // edx
  int v12; // edi
  int v13; // eax
  int (__thiscall *v14)(GFxShapeBase *, int *); // edx
  _BYTE *v15; // eax
  int v16; // esi
  char v17; // al
  unsigned int v18; // esi
  double v19; // st7
  int *v20; // eax
  int v21; // esi
  int v22; // ecx
  unsigned int v23; // ebx
  unsigned int v24; // ebx
  int v25; // ebx
  int flag; // ecx
  int v27; // eax
  unsigned int v28; // ebx
  unsigned int v29; // ebx
  int v30; // ebx
  int v31; // edx
  int v32; // eax
  unsigned int v33; // ebx
  unsigned int v34; // ebx
  int v35; // ebx
  int v36; // ecx
  int v37; // eax
  unsigned int v38; // ebx
  unsigned int v39; // ebx
  int v40; // ebx
  int v41; // edx
  int v42; // eax
  int v43; // esi
  GFxFillStyle *v44; // esi
  int v45; // eax
  float v46; // ecx
  char i; // al
  const CMaterialDict::MissingMaterial_t *v48; // [esp+10h] [ebp-194h]
  int v49; // [esp+10h] [ebp-194h]
  float *v50; // [esp+14h] [ebp-190h]
  IKMeansErrorMetric v51; // [esp+1Ch] [ebp-188h] BYREF
  char v52; // [esp+3Ch] [ebp-168h]
  IKMeansErrorMetric v53; // [esp+90h] [ebp-114h] BYREF
  char v54; // [esp+B0h] [ebp-F4h]
  int v55; // [esp+104h] [ebp-A0h]
  int v56; // [esp+108h] [ebp-9Ch]
  GFxAmpViewStats *v57; // [esp+10Ch] [ebp-98h]
  struct GFxDisplayContext *v58; // [esp+11Ch] [ebp-88h]
  GFxShapeBase *v59; // [esp+120h] [ebp-84h]
  struct GFxMeshSet *v60; // [esp+124h] [ebp-80h]
  struct GFxScale9GridInfo *v61; // [esp+128h] [ebp-7Ch]
  int v62; // [esp+12Ch] [ebp-78h] BYREF
  int v63; // [esp+130h] [ebp-74h] BYREF
  float v64; // [esp+134h] [ebp-70h] BYREF
  _iobuf x1; // [esp+138h] [ebp-6Ch] BYREF
  int v66; // [esp+15Ch] [ebp-48h]
  CCountedStringPoolBase<unsigned int>::hash_item_t *v67; // [esp+160h] [ebp-44h]
  CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > v68; // [esp+170h] [ebp-34h] BYREF
  float v69; // [esp+184h] [ebp-20h]
  float v70; // [esp+188h] [ebp-1Ch]
  float v71; // [esp+18Ch] [ebp-18h]
  int v72; // [esp+190h] [ebp-14h] BYREF
  float v73; // [esp+194h] [ebp-10h]
  CCountedStringPoolBase<unsigned int>::hash_item_t result; // [esp+198h] [ebp-Ch] BYREF

  v6 = (struct GFxScale9GridInfo *)a5;
  v8 = *(GFxAmpViewStats **)(a4 + 144);
  v60 = a2;
  v9 = 0;
  v59 = this;
  v58 = (struct GFxDisplayContext *)a4;
  v61 = (struct GFxScale9GridInfo *)a5;
  v57 = v8;
  if ( v8 != nullptr )
  {
    GFxAmpViewStats::PushCallstack(this: v8, swdHandle: 1u, a3: 0x10u);
    GTimer::GetRawTicks(li: v10, a2: *(float *)&v48, a3: v50);
    v56 = v11;
  }
  else
  {
    v56 = 0;
  }
  x1._cnt = *(_DWORD *)(*(_DWORD *)(a4 + 104) + 16);
  v12 = x1._cnt + 8;
  v55 = v9;
  GCompoundShape::Clear(this: (GCompoundShape *)(x1._cnt + 8));
  GCompoundShape::SetCurveTolerance(this: (long double *)(x1._cnt + 8), t: a3);
  *(_BYTE *)(x1._cnt + 76) = (*((_BYTE *)this + 36) & 8) != 0;
  if ( (*((_BYTE *)this + 36) & 0x10) != 0 )
    GFxMeshSet::SetShapeBounds(a1: (int)this + 4, a2: a6);
  if ( a5 != nullptr )
  {
    GFxScale9GridInfo::Compute(this: a5, gy1: (unsigned int)v48);
    if ( (*((_BYTE *)this + 36) & 0x10) != 0 )
    {
      v13 = GFxScale9GridInfo::AdjustBounds(a1: (int)&v72, xb1: COERCE_FLOAT((GFxShapeBase *)((char *)this + 4)));
      GFxMeshSet::SetShapeBounds(a1: v13, a2: a6);
    }
    if ( (*((_BYTE *)this + 36) & 0x40) != 0 )
    {
      v14 = *(int (__thiscall **)(GFxShapeBase *, int *))(*(_DWORD *)this + 36);
      x1._file = 0;
      v15 = (_BYTE *)v14(a1: this, a2: &x1._file);
      if ( x1._file == 9 )
      {
        v16 = (*v15 & 0x40) != 0;
        if ( (v15[40] & 0x40) != 0 )
          ++v16;
        if ( (v15[80] & 0x40) != 0 )
          ++v16;
        if ( (v15[120] & 0x40) != 0 )
          ++v16;
        if ( (v15[160] & 0x40) != 0 )
          ++v16;
        if ( (v15[200] & 0x40) != 0 )
          ++v16;
        if ( (v15[240] & 0x40) != 0 )
          ++v16;
        if ( (v15[280] & 0x40) != 0 )
          ++v16;
        if ( (v15[320] & 0x40) != 0 )
          ++v16;
        if ( v16 == 9 )
        {
          GFxSwfPathData::PathsIterator::PathsIterator(
            this: (GFxSwfPathData::PathsIterator *)&v51,
            a2: (CFltX4AttributeIterator *)this);
          if ( v52 != 1 )
          {
            do
            {
              GFxSwfPathData::PathsIterator::AddForTessellation(
                this: (GFxSwfPathData::PathsIterator *)&v51,
                a2: (GCompoundShape *)v12);
              v17 = v52;
              if ( v52 == 2 )
              {
                do
                {
                  GFxSwfPathData::PathsIterator::ReadNext(this: &v51);
                  v17 = v52;
                }
                while ( v52 == 3 );
              }
            }
            while ( v17 != 1 );
          }
          if ( *(_DWORD *)(x1._cnt + 32) == 9 )
          {
            v18 = 0;
            *(float *)&x1._file = 0.0;
            do
            {
              *(float *)&x1._ptr = 1.0e30;
              *(float *)&v62 = 1.0e30;
              v64 = -1.0e30;
              *(float *)&v63 = -1.0e30;
              GCompoundShape::ExpandPathBounds(
                a1: (const struct GCompoundShape::SPath *)(*(_DWORD *)(*(_DWORD *)(x1._cnt + 44) + 4 * (v18 >> 6))
                                                     + 24 * (v18 & 0x3F)),
                a2: (float *)&x1,
                a3: (float *)&v62,
                a4: &v64,
                a5: (float *)&v63);
              ++v18;
              *(float *)&x1._file = (*(float *)&v63 - *(float *)&v62) * (v64 - *(float *)&x1._ptr) + *(float *)&x1._file;
            }
            while ( v18 < *(_DWORD *)(x1._cnt + 32) );
            GCompoundShape::PerceiveBounds(this: (int *)v12, &x1);
            v19 = *(float *)&x1._file;
            *(float *)&x1._file = (*(float *)&v63 - *(float *)&v62) * (v64 - *(float *)&x1._ptr);
            *(float *)&x1._file = v19 - *(float *)&x1._file;
            *(float *)&x1._file = fabs(*(float *)&x1._file);
            if ( *(float *)&x1._file <= 1600.0 )
            {
              v20 = **(int ***)(x1._cnt + 44);
              v21 = v20[3];
              v22 = v20[4];
              if ( v21 < 0 == v22 < 0 || v20[5] >= 0 )
              {
                this = v59;
              }
              else
              {
                x1._file = v20[3];
                if ( v21 < 0 )
                  x1._file = v22;
                GCompoundShape::Clear(this: (GCompoundShape *)v12);
                GCompoundShape::BeginPath(this: (GCompoundShape *)v12, lStyle: x1._file, rStyle: -1, a4: -1);
                v23 = *(_DWORD *)(v12 + 8);
                x1._base = x1._ptr;
                v24 = v23 >> 8;
                x1._flag = v62;
                if ( v24 >= *(_DWORD *)(v12 + 12) )
                  GArrayPagedBase<GPointType,8,64,GAllocatorPagedLH_POD<GPointType,138>>::allocatePage(a1: v24);
                v25 = *(_DWORD *)(*(_DWORD *)(v12 + 20) + 4 * v24);
                flag = x1._flag;
                v27 = (unsigned __int8)*(_DWORD *)(v12 + 8);
                *(_DWORD *)(v25 + 8 * v27) = x1._base;
                *(_DWORD *)(v25 + 8 * v27 + 4) = flag;
                ++*(_DWORD *)(v12 + 8);
                ++*(_DWORD *)(*(_DWORD *)(v12 + 40) + 4);
                v28 = *(_DWORD *)(v12 + 8);
                *(float *)&x1._base = v64;
                v29 = v28 >> 8;
                x1._flag = v62;
                if ( v29 >= *(_DWORD *)(v12 + 12) )
                  GArrayPagedBase<GPointType,8,64,GAllocatorPagedLH_POD<GPointType,138>>::allocatePage(a1: v29);
                v30 = *(_DWORD *)(*(_DWORD *)(v12 + 20) + 4 * v29);
                v31 = x1._flag;
                v32 = (unsigned __int8)*(_DWORD *)(v12 + 8);
                *(_DWORD *)(v30 + 8 * v32) = x1._base;
                *(_DWORD *)(v30 + 8 * v32 + 4) = v31;
                ++*(_DWORD *)(v12 + 8);
                ++*(_DWORD *)(*(_DWORD *)(v12 + 40) + 4);
                v33 = *(_DWORD *)(v12 + 8);
                *(float *)&x1._base = v64;
                v34 = v33 >> 8;
                x1._flag = v63;
                if ( v34 >= *(_DWORD *)(v12 + 12) )
                  GArrayPagedBase<GPointType,8,64,GAllocatorPagedLH_POD<GPointType,138>>::allocatePage(a1: v34);
                v35 = *(_DWORD *)(*(_DWORD *)(v12 + 20) + 4 * v34);
                v36 = x1._flag;
                v37 = (unsigned __int8)*(_DWORD *)(v12 + 8);
                *(_DWORD *)(v35 + 8 * v37) = x1._base;
                *(_DWORD *)(v35 + 8 * v37 + 4) = v36;
                ++*(_DWORD *)(v12 + 8);
                ++*(_DWORD *)(*(_DWORD *)(v12 + 40) + 4);
                v38 = *(_DWORD *)(v12 + 8);
                x1._base = x1._ptr;
                v39 = v38 >> 8;
                x1._flag = v63;
                if ( v39 >= *(_DWORD *)(v12 + 12) )
                  GArrayPagedBase<GPointType,8,64,GAllocatorPagedLH_POD<GPointType,138>>::allocatePage(a1: v39);
                v40 = *(_DWORD *)(*(_DWORD *)(v12 + 20) + 4 * v39);
                v41 = x1._flag;
                v42 = (unsigned __int8)*(_DWORD *)(v12 + 8);
                *(_DWORD *)(v40 + 8 * v42) = x1._base;
                *(_DWORD *)(v40 + 8 * v42 + 4) = v41;
                ++*(_DWORD *)(v12 + 8);
                ++*(_DWORD *)(*(_DWORD *)(v12 + 40) + 4);
                GCompoundShape::ClosePath(this: (GCompoundShape *)v12);
                this = v59;
                v43 = (*(int (__thiscall **)(GFxShapeBase *, int *))(*(_DWORD *)v59 + 36))(a1: v59, a2: &x1._cnt);
                GMatrix2D::SetIdentity(result: v48);
                v44 = (GFxFillStyle *)(v43 + 40 * x1._file);
                GFxFillStyle::GetFillTexture(
                  this: v44,
                  scaleMultiplier: (struct GRenderer::FillTexture *)&x1._charbuf,
                  a3: v58,
                  a4: 1.0,
                  a5: nullptr);
                v68.m_Memory.m_pMemory = (CCountedStringPoolBase<unsigned int>::hash_item_t *)x1._bufsiz;
                v68.m_Memory.m_nAllocationCount = (int)x1._tmpfname;
                v68.m_Size = v66;
                v68.m_pElements = v67;
                *(float *)&v68.m_Memory.m_nGrowSize = 0.0;
                v69 = 0.0;
                *(float *)&x1._base = 1.0;
                *(float *)&x1._flag = 0.0;
                GMatrix2D::Transform(this: &v68, &result, p: (int)&x1._base, a4: v49);
                *(float *)&x1._file = fabs(*(float *)&result.pString);
                if ( *(float *)&x1._file <= 0.000001
                  || (*(float *)&x1._file = fabs(*(float *)&result.nNextElement), *(float *)&x1._file <= 0.000001) )
                {
                  GMatrix2D::SetIdentity(result: v48);
                  v70 = v70 * 0.009999999776482582;
                  v71 = v71 * 0.009999999776482582;
                  *(float *)&v72 = *(float *)&v72 * 0.009999999776482582;
                  v73 = v73 * 0.009999999776482582;
                  *(float *)&result.pString = *(float *)&result.pString * 0.009999999776482582;
                  *(float *)&result.nNextElement = 0.009999999776482582 * *(float *)&result.nNextElement;
                  *((float *)v44 + 4) = v70;
                  *((float *)v44 + 5) = v71;
                  *((float *)v44 + 6) = *(float *)&v72;
                  *((float *)v44 + 7) = v73;
                  *((float *)v44 + 8) = *(float *)&result.pString;
                  *((float *)v44 + 9) = *(float *)&result.nNextElement;
                  v45 = *(unsigned __int8 *)v44;
                  if ( v45 == 66 )
                  {
                    v45 = 67;
                  }
                  else if ( v45 == 64 )
                  {
                    v45 = 65;
                  }
                  GFxFillStyle::SetFillType(a1: v44, a2: v45);
                  GFxShapeBase::AddShapeToMesh(
                    this,
                    meshSet: v60,
                    meshSet_4: (struct GCompoundShape *)v12,
                    s9g: v58,
                    s9g_4: v61);
                  GCompoundShape::Clear(this: (GCompoundShape *)v12);
                  goto LABEL_69;
                }
              }
            }
          }
        }
      }
    }
    v6 = v61;
  }
  GCompoundShape::Clear(this: (GCompoundShape *)v12);
  GFxSwfPathData::PathsIterator::PathsIterator(
    this: (GFxSwfPathData::PathsIterator *)&v53,
    a2: (CFltX4AttributeIterator *)this);
  for ( i = v54; v54 != 1; i = v54 )
  {
    if ( i == 2 )
    {
      GFxShapeBase::AddShapeToMesh(this, meshSet: v60, meshSet_4: (struct GCompoundShape *)v12, s9g: v58, s9g_4: v6);
      GCompoundShape::Clear(this: (GCompoundShape *)v12);
      if ( v54 == 1 )
        break;
      if ( v54 == 2 )
      {
        do
          GFxSwfPathData::PathsIterator::ReadNext(this: &v53);
        while ( v54 == 3 );
      }
      else
      {
        GFxSwfPathData::PathsIterator::SkipComplex(this: &v53);
      }
    }
    else
    {
      GFxSwfPathData::PathsIterator::AddForTessellation(
        this: (GFxSwfPathData::PathsIterator *)&v53,
        a2: (GCompoundShape *)v12);
    }
  }
  GFxShapeBase::AddShapeToMesh(this, meshSet: v60, meshSet_4: (struct GCompoundShape *)v12, s9g: v58, s9g_4: v6);
  GCompoundShape::Clear(this: (GCompoundShape *)v12);
  if ( v6 != nullptr && *((_DWORD *)v6 + 89) != 0 )
  {
    GFxScale9GridInfo::ComputeImgAdjustMatrices(
      this: (CMemberFuncProxy1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(Vector),Vector,CFuncMemPolicyNone> *)v6,
      p: (unsigned int)v48);
    GFxMeshSet::SetImgAdjustMatrices(a1: (char *)v6 + 352);
  }
LABEL_69:
  if ( v57 != nullptr )
  {
    GTimer::GetRawTicks(li: v46, a2: *(float *)&v48, a3: v50);
    GFxAmpViewStats::PopCallstack(result: (GImageInfo *)1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014B050
// Name: protected: void GFxShapeBase::TessellateImpl<class GFxPathData>(class GFxMeshSet __near *,float,class GFxDisplayContext __near &,struct GFxScale9GridInfo __near *,float)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxShapeBase::TessellateImpl<GFxPathData>(
        GFxShapeBase *this,
        int a2,
        char *a3,
        int a4,
        int a5,
        float a6)
{
  GFxAmpViewStats *v7; // ecx
  int v8; // eax
  float v9; // ecx
  int v10; // esi
  CSOAContainer *v11; // edi
  int v12; // eax
  int (__thiscall *v13)(GFxShapeBase *, char **); // edx
  _BYTE *v14; // eax
  int v15; // esi
  _BYTE *v16; // eax
  _DWORD *v17; // ecx
  int v18; // ecx
  unsigned int v19; // esi
  double v20; // st7
  int v21; // esi
  char *v22; // eax
  unsigned int m_nSlices; // ebx
  unsigned int v24; // ebx
  int v25; // ebx
  int bufsiz; // ecx
  int v27; // eax
  unsigned int v28; // ebx
  unsigned int v29; // ebx
  int v30; // ebx
  int v31; // edx
  int v32; // eax
  unsigned int v33; // ebx
  unsigned int v34; // ebx
  int v35; // ebx
  int v36; // ecx
  int v37; // eax
  unsigned int v38; // ebx
  unsigned int v39; // ebx
  int v40; // ebx
  int v41; // edx
  int v42; // eax
  int v43; // esi
  GFxFillStyle *v44; // esi
  bool v45; // zf
  _BYTE *v46; // esi
  CCountedStringPoolBase<unsigned int>::hash_item_t *v47; // eax
  int v48; // ecx
  int v49; // edx
  double v50; // st7
  int v51; // eax
  float v52; // ecx
  _DWORD *v53; // eax
  int v54; // eax
  const CMaterialDict::MissingMaterial_t *v55; // [esp+10h] [ebp-B8h]
  int v56; // [esp+10h] [ebp-B8h]
  float *v57; // [esp+14h] [ebp-B4h]
  int v58; // [esp+18h] [ebp-B0h]
  int v59; // [esp+1Ch] [ebp-ACh]
  GFxAmpViewStats *v60; // [esp+24h] [ebp-A4h]
  GFxShapeBase *v61; // [esp+34h] [ebp-94h]
  int v62; // [esp+40h] [ebp-88h] BYREF
  _iobuf x1; // [esp+44h] [ebp-84h] BYREF
  struct GRenderer::FillTexture scaleMultiplier; // [esp+64h] [ebp-64h] BYREF
  float v65; // [esp+88h] [ebp-40h]
  float v66; // [esp+8Ch] [ebp-3Ch]
  int v67; // [esp+90h] [ebp-38h] BYREF
  float v68; // [esp+94h] [ebp-34h]
  CCountedStringPoolBase<unsigned int>::hash_item_t result; // [esp+98h] [ebp-30h] BYREF
  _BYTE *v70; // [esp+A4h] [ebp-24h]
  _BYTE *v71; // [esp+A8h] [ebp-20h]
  CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > v72; // [esp+ACh] [ebp-1Ch] BYREF
  float v73; // [esp+C0h] [ebp-8h]

  x1._file = a2;
  v7 = *(GFxAmpViewStats **)(a4 + 144);
  v8 = 0;
  v61 = this;
  v60 = v7;
  if ( v7 != nullptr )
  {
    GFxAmpViewStats::PushCallstack(this: v7, swdHandle: 1u, a3: 0x10u);
    GTimer::GetRawTicks(li: v9, a2: *(float *)&v55, a3: v57);
  }
  v10 = *(_DWORD *)(*(_DWORD *)(a4 + 104) + 16);
  v11 = (CSOAContainer *)(v10 + 8);
  v59 = v8;
  v62 = v10;
  GCompoundShape::Clear(this: (GCompoundShape *)(v10 + 8));
  GCompoundShape::SetCurveTolerance(this: (long double *)(v10 + 8), t: a3);
  *(_BYTE *)(v10 + 76) = (*((_BYTE *)this + 36) & 8) != 0;
  if ( (*((_BYTE *)this + 36) & 0x10) != 0 )
    GFxMeshSet::SetShapeBounds(a1: (int)this + 4, a2: a6);
  if ( a5 == 0 )
    goto LABEL_52;
  GFxScale9GridInfo::Compute(
    this: (CMemberFuncProxy1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(Vector),Vector,CFuncMemPolicyNone> *)a5,
    gy1: (unsigned int)v55);
  if ( (*((_BYTE *)this + 36) & 0x10) != 0 )
  {
    v12 = GFxScale9GridInfo::AdjustBounds(a1: (int)&v67, xb1: COERCE_FLOAT((GFxShapeBase *)((char *)this + 4)));
    GFxMeshSet::SetShapeBounds(a1: v12, a2: a6);
  }
  if ( (*((_BYTE *)this + 36) & 0x40) == 0 )
    goto LABEL_52;
  v13 = *(int (__thiscall **)(GFxShapeBase *, char **))(*(_DWORD *)this + 36);
  x1._tmpfname = nullptr;
  v14 = (_BYTE *)v13(a1: this, a2: &x1._tmpfname);
  if ( x1._tmpfname != (char *)9 )
    goto LABEL_52;
  v15 = (*v14 & 0x40) != 0;
  if ( (v14[40] & 0x40) != 0 )
    ++v15;
  if ( (v14[80] & 0x40) != 0 )
    ++v15;
  if ( (v14[120] & 0x40) != 0 )
    ++v15;
  if ( (v14[160] & 0x40) != 0 )
    ++v15;
  if ( (v14[200] & 0x40) != 0 )
    ++v15;
  if ( (v14[240] & 0x40) != 0 )
    ++v15;
  if ( (v14[280] & 0x40) != 0 )
    ++v15;
  if ( (v14[320] & 0x40) != 0 )
    ++v15;
  if ( v15 != 9 )
    goto LABEL_52;
  GFxPathData::PathsIterator::PathsIterator(
    this: (GFxPathData::PathsIterator *)&result.nReferenceCount,
    a2: (const struct GFxShapeBase *)this);
  while ( (CCountedStringPoolBase<unsigned int>::hash_item_t *)v72.m_Size < v72.m_pElements )
  {
    GFxPathData::PathsIterator::AddForTessellation(
      this: (CSOAContainer *)&result.nReferenceCount,
      a2: (int)v11,
      cs: v11,
      edge: (int)v55,
      fill0: (int)v57,
      line: v58,
      fill1: v59);
    v16 = v70;
    if ( (*v70 & 7) == 0 )
    {
      if ( (CCountedStringPoolBase<unsigned int>::hash_item_t *)v72.m_Size >= v72.m_pElements )
        break;
      ++v72.m_Size;
      v17 = &v71[-LOWORD(v72.m_Memory.m_nGrowSize)];
      ++v70;
      if ( v16 + 1 - (_BYTE *)v17 - 8 >= v17[1] )
      {
        v18 = *v17;
        if ( v18 != 0 )
        {
          v70 = (_BYTE *)(v18 + 8);
          v71 = (_BYTE *)(v18 + 8);
          LOWORD(v72.m_Memory.m_nGrowSize) = 8;
        }
        else
        {
          v70 = nullptr;
        }
      }
    }
  }
  if ( *(_DWORD *)(v62 + 32) != 9 )
    goto LABEL_52;
  v19 = 0;
  *(float *)&x1._tmpfname = 0.0;
  do
  {
    *(float *)&x1._ptr = 1.0e30;
    *(float *)&x1._cnt = 1.0e30;
    *(float *)&x1._base = -1.0e30;
    *(float *)&x1._flag = -1.0e30;
    GCompoundShape::ExpandPathBounds(
      a1: (const struct GCompoundShape::SPath *)(*(_DWORD *)(*(_DWORD *)(v62 + 44) + 4 * (v19 >> 6)) + 24 * (v19 & 0x3F)),
      a2: (float *)&x1,
      a3: (float *)&x1._cnt,
      a4: (float *)&x1._base,
      a5: (float *)&x1._flag);
    ++v19;
    *(float *)&x1._tmpfname = (*(float *)&x1._flag - *(float *)&x1._cnt) * (*(float *)&x1._base - *(float *)&x1._ptr)
                            + *(float *)&x1._tmpfname;
  }
  while ( v19 < *(_DWORD *)(v62 + 32) );
  GCompoundShape::PerceiveBounds(this: &v11->m_nColumns, &x1);
  v20 = *(float *)&x1._tmpfname;
  *(float *)&x1._tmpfname = (*(float *)&x1._flag - *(float *)&x1._cnt) * (*(float *)&x1._base - *(float *)&x1._ptr);
  *(float *)&x1._tmpfname = v20 - *(float *)&x1._tmpfname;
  *(float *)&x1._tmpfname = fabs(*(float *)&x1._tmpfname);
  if ( *(float *)&x1._tmpfname > 1600.0 )
    goto LABEL_52;
  v21 = **(_DWORD **)(v62 + 44);
  v22 = *(char **)(v21 + 16);
  if ( *(int *)(v21 + 12) < 0 == (int)v22 < 0 || *(int *)(v21 + 20) >= 0 )
    goto LABEL_52;
  x1._tmpfname = *(char **)(v21 + 12);
  if ( (int)x1._tmpfname < 0 )
    x1._tmpfname = v22;
  GCompoundShape::Clear(this: (GCompoundShape *)v11);
  GCompoundShape::BeginPath(this: (GCompoundShape *)v11, lStyle: x1._tmpfname, rStyle: -1, a4: -1);
  m_nSlices = v11->m_nSlices;
  x1._charbuf = (int)x1._ptr;
  v24 = m_nSlices >> 8;
  x1._bufsiz = x1._cnt;
  if ( v24 >= v11->m_nPaddedColumns )
    GArrayPagedBase<GPointType,8,64,GAllocatorPagedLH_POD<GPointType,138>>::allocatePage(a1: v24);
  v25 = *(_DWORD *)&v11->m_pDataMemory[4 * v24];
  bufsiz = x1._bufsiz;
  v27 = (unsigned __int8)v11->m_nSlices;
  *(_DWORD *)(v25 + 8 * v27) = x1._charbuf;
  *(_DWORD *)(v25 + 8 * v27 + 4) = bufsiz;
  ++v11->m_nSlices;
  ++*((_DWORD *)v11->m_pAttributePtrs[4] + 1);
  v28 = v11->m_nSlices;
  x1._charbuf = (int)x1._base;
  v29 = v28 >> 8;
  x1._bufsiz = x1._cnt;
  if ( v29 >= v11->m_nPaddedColumns )
    GArrayPagedBase<GPointType,8,64,GAllocatorPagedLH_POD<GPointType,138>>::allocatePage(a1: v29);
  v30 = *(_DWORD *)&v11->m_pDataMemory[4 * v29];
  v31 = x1._bufsiz;
  v32 = (unsigned __int8)v11->m_nSlices;
  *(_DWORD *)(v30 + 8 * v32) = x1._charbuf;
  *(_DWORD *)(v30 + 8 * v32 + 4) = v31;
  ++v11->m_nSlices;
  ++*((_DWORD *)v11->m_pAttributePtrs[4] + 1);
  v33 = v11->m_nSlices;
  x1._charbuf = (int)x1._base;
  v34 = v33 >> 8;
  x1._bufsiz = x1._flag;
  if ( v34 >= v11->m_nPaddedColumns )
    GArrayPagedBase<GPointType,8,64,GAllocatorPagedLH_POD<GPointType,138>>::allocatePage(a1: v34);
  v35 = *(_DWORD *)&v11->m_pDataMemory[4 * v34];
  v36 = x1._bufsiz;
  v37 = (unsigned __int8)v11->m_nSlices;
  *(_DWORD *)(v35 + 8 * v37) = x1._charbuf;
  *(_DWORD *)(v35 + 8 * v37 + 4) = v36;
  ++v11->m_nSlices;
  ++*((_DWORD *)v11->m_pAttributePtrs[4] + 1);
  v38 = v11->m_nSlices;
  x1._charbuf = (int)x1._ptr;
  v39 = v38 >> 8;
  x1._bufsiz = x1._flag;
  if ( v39 >= v11->m_nPaddedColumns )
    GArrayPagedBase<GPointType,8,64,GAllocatorPagedLH_POD<GPointType,138>>::allocatePage(a1: v39);
  v40 = *(_DWORD *)&v11->m_pDataMemory[4 * v39];
  v41 = x1._bufsiz;
  v42 = (unsigned __int8)v11->m_nSlices;
  *(_DWORD *)(v40 + 8 * v42) = x1._charbuf;
  *(_DWORD *)(v40 + 8 * v42 + 4) = v41;
  ++v11->m_nSlices;
  ++*((_DWORD *)v11->m_pAttributePtrs[4] + 1);
  GCompoundShape::ClosePath(this: (GCompoundShape *)v11);
  this = v61;
  v43 = (*(int (__thiscall **)(GFxShapeBase *, int *))(*(_DWORD *)v61 + 36))(a1: v61, a2: &v62);
  GMatrix2D::SetIdentity(result: v55);
  v44 = (GFxFillStyle *)(v43 + 40 * (int)x1._tmpfname);
  GFxFillStyle::GetFillTexture(
    this: v44,
    &scaleMultiplier,
    a3: (const struct GFxDisplayContext *)a4,
    a4: 1.0,
    a5: nullptr);
  *(float *)&v72.m_Memory.m_pMemory = scaleMultiplier.TextureMatrix.M_[0][0];
  *(float *)&v72.m_Memory.m_nAllocationCount = scaleMultiplier.TextureMatrix.M_[0][1];
  *(float *)&v72.m_Size = scaleMultiplier.TextureMatrix.M_[1][0];
  *(float *)&v72.m_pElements = scaleMultiplier.TextureMatrix.M_[1][1];
  *(float *)&v72.m_Memory.m_nGrowSize = 0.0;
  v73 = 0.0;
  *(float *)&x1._charbuf = 1.0;
  *(float *)&x1._bufsiz = 0.0;
  GMatrix2D::Transform(this: &v72, &result, p: (int)&x1._charbuf, a4: v56);
  *(float *)&x1._tmpfname = fabs(*(float *)&result.pString);
  if ( *(float *)&x1._tmpfname <= 0.000001
    || (*(float *)&x1._tmpfname = fabs(*(float *)&result.nNextElement), *(float *)&x1._tmpfname <= 0.000001) )
  {
    GMatrix2D::SetIdentity(result: v55);
    v65 = v65 * 0.009999999776482582;
    v66 = v66 * 0.009999999776482582;
    *(float *)&v67 = *(float *)&v67 * 0.009999999776482582;
    v68 = v68 * 0.009999999776482582;
    *(float *)&result.pString = *(float *)&result.pString * 0.009999999776482582;
    *(float *)&result.nNextElement = 0.009999999776482582 * *(float *)&result.nNextElement;
    *((float *)v44 + 4) = v65;
    *((float *)v44 + 5) = v66;
    *((float *)v44 + 6) = *(float *)&v67;
    *((float *)v44 + 7) = v68;
    *((float *)v44 + 8) = *(float *)&result.pString;
    *((float *)v44 + 9) = *(float *)&result.nNextElement;
    v51 = *(unsigned __int8 *)v44;
    if ( v51 == 66 )
    {
      v51 = 67;
    }
    else if ( v51 == 64 )
    {
      v51 = 65;
    }
    GFxFillStyle::SetFillType(a1: v44, a2: v51);
    GFxShapeBase::AddShapeToMesh(
      this: v61,
      meshSet: (struct GFxMeshSet *)x1._file,
      meshSet_4: (struct GCompoundShape *)v11,
      s9g: (struct GFxDisplayContext *)a4,
      s9g_4: (struct GFxScale9GridInfo *)a5);
    GCompoundShape::Clear(this: (GCompoundShape *)v11);
  }
  else
  {
LABEL_52:
    GCompoundShape::Clear(this: (GCompoundShape *)v11);
    v45 = (*((_BYTE *)this + 36) & 2) == 0;
    v47 = *((CCountedStringPoolBase<unsigned int>::hash_item_t **)this + 14);
    v48 = *((_DWORD *)this + 15);
    v71 = *((_BYTE **)this + 13);
    v46 = v71;
    v49 = *((_DWORD *)this + 16);
    *(_DWORD *)&result.nReferenceCount = this;
    v70 = v71;
    v72.m_Memory.m_pMemory = v47;
    v72.m_Memory.m_nAllocationCount = v48;
    v72.m_Memory.m_nGrowSize = v49;
    v72.m_Size = 0;
    v72.m_pElements = v47;
    if ( v45 )
      v50 = 1.0;
    else
      v50 = 0.050000001;
    v73 = v50;
    if ( v47 != nullptr )
    {
      do
      {
        if ( (*v46 & 7) != 0 )
        {
          GFxPathData::PathsIterator::AddForTessellation(
            this: (CSOAContainer *)&result.nReferenceCount,
            a2: (int)v11,
            cs: v11,
            edge: (int)v55,
            fill0: (int)v57,
            line: v58,
            fill1: v59);
          v46 = v70;
        }
        else
        {
          GFxShapeBase::AddShapeToMesh(
            this,
            meshSet: (struct GFxMeshSet *)x1._file,
            meshSet_4: (struct GCompoundShape *)v11,
            s9g: (struct GFxDisplayContext *)a4,
            s9g_4: (struct GFxScale9GridInfo *)a5);
          GCompoundShape::Clear(this: (GCompoundShape *)v11);
          if ( (CCountedStringPoolBase<unsigned int>::hash_item_t *)v72.m_Size >= v72.m_pElements )
            break;
          if ( (*v46 & 7) != 0 )
          {
            GFxPathData::PathsIterator::SkipComplex(this: (CSOAContainer *)&result.nReferenceCount);
            v46 = v70;
          }
          else
          {
            v70 = ++v46;
          }
          ++v72.m_Size;
          v53 = &v71[-LOWORD(v72.m_Memory.m_nGrowSize)];
          if ( v46 - (_BYTE *)v53 - 8 >= v53[1] )
          {
            v54 = *v53;
            if ( v54 != 0 )
            {
              v46 = (_BYTE *)(v54 + 8);
              v70 = (_BYTE *)(v54 + 8);
              v71 = (_BYTE *)(v54 + 8);
              LOWORD(v72.m_Memory.m_nGrowSize) = 8;
            }
            else
            {
              v46 = nullptr;
              v70 = nullptr;
            }
          }
        }
      }
      while ( (CCountedStringPoolBase<unsigned int>::hash_item_t *)v72.m_Size < v72.m_pElements );
    }
    GFxShapeBase::AddShapeToMesh(
      this,
      meshSet: (struct GFxMeshSet *)x1._file,
      meshSet_4: (struct GCompoundShape *)v11,
      s9g: (struct GFxDisplayContext *)a4,
      s9g_4: (struct GFxScale9GridInfo *)a5);
    GCompoundShape::Clear(this: (GCompoundShape *)v11);
    if ( a5 != 0 && *(_DWORD *)(a5 + 356) != 0 )
    {
      GFxScale9GridInfo::ComputeImgAdjustMatrices(
        this: (CMemberFuncProxy1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(Vector),Vector,CFuncMemPolicyNone> *)a5,
        p: (unsigned int)v55);
      GFxMeshSet::SetImgAdjustMatrices(a1: a5 + 352);
    }
  }
  if ( v60 != nullptr )
  {
    GTimer::GetRawTicks(li: v52, a2: *(float *)&v55, a3: v57);
    GFxAmpViewStats::PopCallstack(result: (GImageInfo *)1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014B750
// Name: protected: void GFxShapeBase::MakeCompoundShapeImpl<class GFxPathData>(class GCompoundShape __near *,float)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxShapeBase::MakeCompoundShapeImpl<GFxPathData>(int this, CSOAContainer *a2, char *tolerance)
{
  bool v4; // zf
  int result; // eax
  int v6; // ecx
  int v7; // edx
  double v8; // st7
  int v9; // [esp+4h] [ebp-2Ch]
  int v10; // [esp+8h] [ebp-28h]
  int v11; // [esp+Ch] [ebp-24h] BYREF
  int v12; // [esp+10h] [ebp-20h]
  int v13; // [esp+14h] [ebp-1Ch]
  int v14; // [esp+18h] [ebp-18h]
  int v15; // [esp+1Ch] [ebp-14h]
  int v16; // [esp+20h] [ebp-10h]
  unsigned int v17; // [esp+24h] [ebp-Ch]
  unsigned int v18; // [esp+28h] [ebp-8h]
  float v19; // [esp+2Ch] [ebp-4h]

  GCompoundShape::Clear(this: (GCompoundShape *)a2);
  GCompoundShape::SetCurveTolerance(this: (long double *)&a2->m_nColumns, t: tolerance);
  LOBYTE(a2->m_pAttributePtrs[11]) = (*(_BYTE *)(this + 36) & 8) != 0;
  v4 = (*(_BYTE *)(this + 36) & 2) == 0;
  result = *(_DWORD *)(this + 56);
  v12 = *(_DWORD *)(this + 52);
  v6 = *(_DWORD *)(this + 60);
  v13 = v12;
  v7 = *(_DWORD *)(this + 64);
  v11 = this;
  v14 = result;
  v15 = v6;
  v16 = v7;
  v17 = 0;
  v18 = result;
  if ( v4 )
    v8 = 1.0;
  else
    v8 = 0.050000001;
  v19 = v8;
  if ( result != 0 )
  {
    do
    {
      GFxPathData::PathsIterator::AddForTessellation(
        this: (CSOAContainer *)&v11,
        (int)a2,
        cs: a2,
        edge: v9,
        fill0: v10,
        line: v11,
        fill1: v12);
      result = v17;
    }
    while ( v17 < v18 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1014B7E0
// Name: protected: void GFxShapeBase::PreTessellateImpl<class GFxPathData>(float,class GFxRenderConfig const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxShapeBase::PreTessellateImpl<GFxPathData>(
        struct GFxShapeBase *a1@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        float a4,
        struct GFxRenderConfig *a5,
        struct GFxFillStyle *a6)
{
  unsigned int RendererCapBits; // eax
  GFxRenderGen *v8; // eax
  GFxRenderGen *v9; // edi
  void *(__thiscall *AllocAutoHeap_2)(GMemoryHeap *, const void *, unsigned int, const GAllocDebugInfo *); // edx
  GFxMeshSet *v11; // eax
  GFxMeshSet *v12; // eax
  CSOAContainer *v13; // esi
  int (__thiscall *v14)(struct GFxShapeBase *); // edx
  localeinfo_struct *v15; // edi
  localeinfo_struct **v16; // eax
  localeinfo_struct *v17; // eax
  unsigned int *t; // [esp+24h] [ebp-44h]
  int *p_i; // [esp+28h] [ebp-40h]
  int v20; // [esp+2Ch] [ebp-3Ch]
  int v21; // [esp+30h] [ebp-38h] BYREF
  localeinfo_struct *v22; // [esp+34h] [ebp-34h]
  localeinfo_struct *v23; // [esp+38h] [ebp-30h]
  unsigned __int16 v24; // [esp+44h] [ebp-24h]
  unsigned int v25; // [esp+48h] [ebp-20h]
  unsigned int v26; // [esp+4Ch] [ebp-1Ch]
  int i; // [esp+54h] [ebp-14h] BYREF
  int v28; // [esp+58h] [ebp-10h] BYREF
  unsigned int j; // [esp+5Ch] [ebp-Ch] BYREF
  GFxRenderGen *v30; // [esp+60h] [ebp-8h]
  bool v31; // [esp+67h] [ebp-1h]
  float v32; // [esp+70h] [ebp+8h]
  float maxLen; // [esp+70h] [ebp+8h]
  struct GFxFillStyle *v34; // [esp+78h] [ebp+10h]

  if ( *((_DWORD *)a1 + 8) == 0 )
  {
    v31 = (a5->RenderFlags & 0x10) != 0
       && ((RendererCapBits = a5->RendererCapBits) & 0x100) != 0
       && ((RendererCapBits & 0x200) != 0 || (*((_BYTE *)a1 + 36) & 1) == 0);
    v28 = 2;
    v8 = (GFxRenderGen *)((int (__thiscall *)(GMemoryHeap *, int, int *, int, int))GMemory::pGlobalHeap->Alloc_2)(
                           a1: GMemory::pGlobalHeap,
                           a2: 948,
                           a3: &v28,
                           a4: a2,
                           a5: a3);
    if ( v8 != nullptr )
    {
      v9 = GFxRenderGen::GFxRenderGen(this: v8, a2: GMemory::pGlobalHeap);
      v30 = v9;
    }
    else
    {
      v30 = nullptr;
      v9 = nullptr;
    }
    p_i = &i;
    i = 131;
    AllocAutoHeap_2 = GMemory::pGlobalHeap->AllocAutoHeap_2;
    *(float *)&v28 = 20.0 / a4;
    v32 = *(float *)&v28 * 0.75 * a5->MaxCurvePixelError;
    v11 = (GFxMeshSet *)((int (__stdcall *)(struct GFxShapeBase *, int))AllocAutoHeap_2)(a1, a2: 116);
    if ( v11 != nullptr )
      v12 = GFxMeshSet::GFxMeshSet(this: v11, a2: *(float *)&v28, a3: v32, a4: !v31, a5: false);
    else
      v12 = nullptr;
    v13 = (CSOAContainer *)((char *)v9 + 8);
    *((_DWORD *)a1 + 8) = v12;
    GCompoundShape::Clear(this: (GCompoundShape *)v9 + 2);
    GCompoundShape::SetCurveTolerance(this: (long double *)v9 + 1, t: (char *)LODWORD(v32));
    *((_BYTE *)v9 + 76) = (*((_BYTE *)a1 + 36) & 8) != 0;
    if ( (*((_BYTE *)a1 + 36) & 0x10) != 0 )
      GFxMeshSet::SetShapeBounds(a1: (int)a1 + 4, a2: *(float *)&a6);
    GFxPathData::PathsIterator::PathsIterator(this: (GFxPathData::PathsIterator *)&v21, a2: a1);
    v14 = *(int (__thiscall **)(struct GFxShapeBase *))(*(_DWORD *)a1 + 36);
    t = &j;
    j = 0;
    v34 = (struct GFxFillStyle *)v14(a1);
    if ( v25 < v26 )
    {
      v15 = v22;
      do
      {
        if ( ((int)v15->locinfo & 7) != 0 )
        {
          GFxPathData::PathsIterator::AddForTessellation(
            this: (CSOAContainer *)&v21,
            a2: (int)v15,
            cs: v13,
            edge: (int)t,
            fill0: (int)p_i,
            line: v20,
            fill1: v21);
          v15 = v22;
        }
        else
        {
          *(float *)&i = v32 * 0.25;
          GCompoundShape::RemoveShortSegments(
            this: (long double *)&v13->m_nColumns,
            maxLen: (char *)i,
            j: (unsigned int)t,
            i: (int)p_i,
            start: v20,
            num: v21,
            v1: v22);
          GFxMeshSet::AddTessellatedShape(
            this: *((GFxMeshSet **)a1 + 8),
            a2: (const struct GCompoundShape *)v13,
            a3: v34,
            idx: j,
            a5: nullptr,
            a6: a5);
          GCompoundShape::Clear(this: (GCompoundShape *)v13);
          if ( v25 >= v26 )
            break;
          if ( ((int)v15->locinfo & 7) != 0 )
          {
            GFxPathData::PathsIterator::SkipComplex(this: (CSOAContainer *)&v21);
            v15 = v22;
          }
          else
          {
            v15 = (localeinfo_struct *)((char *)v15 + 1);
            v22 = v15;
          }
          ++v25;
          v16 = (localeinfo_struct **)&v23[v24 / 0xFFFFFFF8];
          if ( (char *)v15 - (char *)v16 - 8 >= (int)v16[1] )
          {
            v17 = *v16;
            if ( v17 != nullptr )
            {
              v15 = v17 + 1;
              v22 = v17 + 1;
              v23 = v17 + 1;
              v24 = 8;
            }
            else
            {
              v15 = nullptr;
              v22 = nullptr;
            }
          }
        }
      }
      while ( v25 < v26 );
      v9 = v30;
    }
    maxLen = v32 * 0.25;
    GCompoundShape::RemoveShortSegments(
      this: (long double *)&v13->m_nColumns,
      maxLen: (char *)LODWORD(maxLen),
      j: (unsigned int)t,
      i: (int)p_i,
      start: v20,
      num: v21,
      v1: v22);
    GFxMeshSet::AddTessellatedShape(
      this: *((GFxMeshSet **)a1 + 8),
      a2: (const struct GCompoundShape *)v13,
      a3: v34,
      idx: j,
      a5: nullptr,
      a6: a5);
    GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014BA30
// Name: protected: void GFxShapeBase::PreTessellateImpl<class GFxSwfPathData>(float,class GFxRenderConfig const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxShapeBase::PreTessellateImpl<GFxSwfPathData>(
        struct GFxShapeBase *a1@<ecx>,
        int a2@<ebx>,
        int a3@<esi>,
        float a4,
        struct GFxRenderConfig *a5,
        float a6)
{
  unsigned int RendererCapBits; // eax
  GFxRenderGen *v8; // eax
  GFxRenderGen *v9; // ebx
  void *(__thiscall *AllocAutoHeap_2)(GMemoryHeap *, const void *, unsigned int, const GAllocDebugInfo *); // edx
  GFxMeshSet *v11; // eax
  GFxMeshSet *v12; // eax
  long double *v13; // esi
  int (__thiscall *v14)(struct GFxShapeBase *); // edx
  const struct GFxFillStyle *v15; // ebx
  char k; // al
  unsigned int *t; // [esp+24h] [ebp-94h]
  int *p_i; // [esp+28h] [ebp-90h]
  int v19; // [esp+2Ch] [ebp-8Ch]
  IKMeansErrorMetric v20; // [esp+30h] [ebp-88h] BYREF
  localeinfo_struct *v21; // [esp+34h] [ebp-84h]
  char v22; // [esp+50h] [ebp-68h]
  int i; // [esp+A4h] [ebp-14h] BYREF
  unsigned int j; // [esp+A8h] [ebp-10h] BYREF
  GRefCountNTSImpl *v25; // [esp+ACh] [ebp-Ch]
  int v26; // [esp+B0h] [ebp-8h] BYREF
  bool v27; // [esp+B7h] [ebp-1h]
  float v28; // [esp+C0h] [ebp+8h]
  float v29; // [esp+C0h] [ebp+8h]
  float maxLen; // [esp+C8h] [ebp+10h]

  if ( *((_DWORD *)a1 + 8) == 0 )
  {
    v27 = (a5->RenderFlags & 0x10) != 0
       && ((RendererCapBits = a5->RendererCapBits) & 0x100) != 0
       && ((RendererCapBits & 0x200) != 0 || (*((_BYTE *)a1 + 36) & 1) == 0);
    v26 = 2;
    v8 = (GFxRenderGen *)((int (__thiscall *)(GMemoryHeap *, int, int *, int, int))GMemory::pGlobalHeap->Alloc_2)(
                           a1: GMemory::pGlobalHeap,
                           a2: 948,
                           a3: &v26,
                           a4: a3,
                           a5: a2);
    if ( v8 != nullptr )
    {
      v9 = GFxRenderGen::GFxRenderGen(this: v8, a2: GMemory::pGlobalHeap);
      v25 = (GRefCountNTSImpl *)v9;
    }
    else
    {
      v25 = nullptr;
      v9 = nullptr;
    }
    p_i = &i;
    i = 131;
    AllocAutoHeap_2 = GMemory::pGlobalHeap->AllocAutoHeap_2;
    *(float *)&v26 = 20.0 / a4;
    v28 = *(float *)&v26 * 0.75 * a5->MaxCurvePixelError;
    v11 = (GFxMeshSet *)((int (__stdcall *)(struct GFxShapeBase *, int))AllocAutoHeap_2)(a1, a2: 116);
    if ( v11 != nullptr )
      v12 = GFxMeshSet::GFxMeshSet(this: v11, a2: *(float *)&v26, a3: v28, a4: !v27, a5: false);
    else
      v12 = nullptr;
    v13 = (long double *)((char *)v9 + 8);
    *((_DWORD *)a1 + 8) = v12;
    GCompoundShape::Clear(this: (GCompoundShape *)v9 + 2);
    GCompoundShape::SetCurveTolerance(this: (long double *)v9 + 1, t: (char *)LODWORD(v28));
    *((_BYTE *)v9 + 76) = (*((_BYTE *)a1 + 36) & 8) != 0;
    if ( (*((_BYTE *)a1 + 36) & 0x10) != 0 )
      GFxMeshSet::SetShapeBounds(a1: (int)a1 + 4, a2: a6);
    GFxSwfPathData::PathsIterator::PathsIterator(
      this: (GFxSwfPathData::PathsIterator *)&v20,
      a2: (CFltX4AttributeIterator *)a1);
    v14 = *(int (__thiscall **)(struct GFxShapeBase *))(*(_DWORD *)a1 + 36);
    t = &j;
    j = 0;
    v15 = (const struct GFxFillStyle *)v14(a1);
    for ( k = v22; v22 != 1; k = v22 )
    {
      if ( k == 2 )
      {
        maxLen = v28 * 0.25;
        GCompoundShape::RemoveShortSegments(
          this: v13,
          maxLen: (char *)LODWORD(maxLen),
          j: (unsigned int)t,
          i: (int)p_i,
          start: v19,
          num: (int)v20.__vftable,
          v1: v21);
        GFxMeshSet::AddTessellatedShape(
          this: *((GFxMeshSet **)a1 + 8),
          a2: (const struct GCompoundShape *)v13,
          a3: v15,
          idx: j,
          a5: nullptr,
          a6: a5);
        GCompoundShape::Clear(this: (GCompoundShape *)v13);
        if ( v22 == 1 )
          break;
        if ( v22 == 2 )
        {
          do
            GFxSwfPathData::PathsIterator::ReadNext(this: &v20);
          while ( v22 == 3 );
        }
        else
        {
          GFxSwfPathData::PathsIterator::SkipComplex(this: &v20);
        }
      }
      else
      {
        GFxSwfPathData::PathsIterator::AddForTessellation(
          this: (GFxSwfPathData::PathsIterator *)&v20,
          a2: (GCompoundShape *)v13);
      }
    }
    v29 = v28 * 0.25;
    GCompoundShape::RemoveShortSegments(
      this: v13,
      maxLen: (char *)LODWORD(v29),
      j: (unsigned int)t,
      i: (int)p_i,
      start: v19,
      num: (int)v20.__vftable,
      v1: v21);
    GFxMeshSet::AddTessellatedShape(
      this: *((GFxMeshSet **)a1 + 8),
      a2: (const struct GCompoundShape *)v13,
      a3: v15,
      idx: j,
      a5: nullptr,
      a6: a5);
    GRefCountNTSImpl::Release(this: v25);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014BC40
// Name: public: GFxRenderGenStroker::GFxRenderGenStroker(void)
// Source: json
//------------------------------------------------------------------------------
GFxRenderGenStroker *__thiscall GFxRenderGenStroker::GFxRenderGenStroker(GFxRenderGenStroker *this)
{
  *(_DWORD *)this = &GRefCountImplCore::`vftable';
  *((_DWORD *)this + 1) = 1;
  *(_DWORD *)this = &GFxRenderGenStroker::`vftable';
  *((float *)this + 2) = 1.0;
  *((float *)this + 3) = 1.0;
  *((_DWORD *)this + 4) = 3;
  *((float *)this + 7) = 4.0;
  *((_DWORD *)this + 5) = 2;
  *((_DWORD *)this + 6) = 2;
  *((_DWORD *)this + 8) = 0;
  *((_DWORD *)this + 9) = 0;
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 11) = 0;
  *((_BYTE *)this + 48) = 0;
  *((float *)this + 13) = 1.0;
  *((float *)this + 14) = 0.0625;
  *((_DWORD *)this + 15) = 0;
  *((_DWORD *)this + 16) = 0;
  *((_DWORD *)this + 17) = 0;
  *((_DWORD *)this + 18) = 0;
  *((_DWORD *)this + 19) = 0;
  *((_DWORD *)this + 20) = 0;
  *((_DWORD *)this + 21) = 0;
  *((_DWORD *)this + 22) = 0;
  *((float *)this + 26) = 1.0;
  *((float *)this + 27) = 1.0;
  *((_DWORD *)this + 23) = 0;
  *((_DWORD *)this + 24) = 0x7FFFFFFF;
  *((float *)this + 28) = 0.0;
  *((_DWORD *)this + 25) = -2147483647;
  *((float *)this + 29) = 0.0;
  *((_BYTE *)this + 120) = 0;
  *((float *)this + 31) = 1.0;
  *((float *)this + 32) = 0.0625;
  *((_DWORD *)this + 33) = 0;
  *((_DWORD *)this + 34) = 0;
  *((_DWORD *)this + 35) = 0;
  *((_DWORD *)this + 36) = 0;
  *((_DWORD *)this + 37) = 0;
  *((_DWORD *)this + 38) = 0;
  *((_DWORD *)this + 39) = 0;
  *((_DWORD *)this + 40) = 0;
  *((float *)this + 44) = 1.0;
  *((float *)this + 45) = 1.0;
  *((_DWORD *)this + 41) = 0;
  *((_DWORD *)this + 42) = 0x7FFFFFFF;
  *((float *)this + 46) = 0.0;
  *((_DWORD *)this + 43) = -2147483647;
  *((float *)this + 47) = 0.0;
  *((_BYTE *)this + 192) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1014BDB0
// Name: GFx_ReadLineStyles
// Source: json
//------------------------------------------------------------------------------
int __cdecl GFx_ReadLineStyles(GArrayLH<GString,2,GArrayDefaultPolicy> *a1, unsigned int p)
{
  unsigned int v2; // esi
  int v3; // eax
  int v4; // eax
  GArrayLH<GString,2,GArrayDefaultPolicy> *v5; // ecx
  int v6; // edi
  unsigned int v7; // esi
  int v8; // edx
  int v9; // eax
  int v10; // ecx
  __int16 v11; // dx
  GArrayLH<GString,2,GArrayDefaultPolicy> *v12; // ecx
  _DWORD *v13; // eax
  int v14; // esi
  unsigned int Size; // ebx
  int v16; // esi
  int v17; // ecx
  int v18; // esi
  unsigned int v19; // eax
  _cpinfo *v21; // [esp+0h] [ebp-14h]
  int v22; // [esp+Ch] [ebp-8h]
  unsigned int pfmt; // [esp+10h] [ebp-4h]
  unsigned int pfmta; // [esp+10h] [ebp-4h]

  v2 = *(_DWORD *)(p + 804);
  if ( v2 == 0 )
    v2 = p + 40;
  v3 = *(_DWORD *)(v2 + 48) - *(_DWORD *)(v2 + 44);
  *(_BYTE *)(v2 + 21) = 0;
  if ( v3 < 1 )
    GFxStream::PopulateBuffer1(result: v21);
  v4 = *(_DWORD *)(v2 + 44);
  v5 = *(GArrayLH<GString,2,GArrayDefaultPolicy> **)(v2 + 60);
  LOBYTE(v5) = *((_BYTE *)&v5->Data.Data + v4);
  v6 = (unsigned __int8)v5;
  *(_DWORD *)(v2 + 44) = v4 + 1;
  pfmt = p + 20;
  GFxLogBase<GFxLoadProcess>::LogParse(
    this: v5,
    pfmt: p + 20,
    a3: (int)"  GFx_ReadLineStyles: count = %d\n",
    a4: (char)v5);
  if ( v6 == 255 )
  {
    v7 = *(_DWORD *)(p + 804);
    if ( v7 == 0 )
      v7 = p + 40;
    v8 = *(_DWORD *)(v7 + 48) - *(_DWORD *)(v7 + 44);
    *(_BYTE *)(v7 + 21) = 0;
    if ( v8 < 2 )
      GFxStream::PopulateBuffer(result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
    v9 = *(_DWORD *)(v7 + 44);
    v10 = *(_DWORD *)(v7 + 60);
    v11 = *(unsigned __int8 *)(v10 + v9 + 1);
    v12 = (GArrayLH<GString,2,GArrayDefaultPolicy> *)*(unsigned __int8 *)(v10 + v9);
    v6 = (unsigned __int16)((unsigned __int16)v12 | (v11 << 8));
    *(_DWORD *)(v7 + 44) = v9 + 2;
    GFxLogBase<GFxLoadProcess>::LogParse(this: v12, pfmt, a3: (int)"  GFx_ReadLineStyles: count2 = %d\n", a4: (char)v12);
  }
  v13 = *(_DWORD **)(p + 804);
  if ( v13 == nullptr )
    v13 = (_DWORD *)(p + 40);
  v14 = v13[11] + v13[13] - v13[12];
  v22 = v14;
  if ( a1 != nullptr )
  {
    Size = a1->Data.Size;
    GArrayDataBase<GFxLineStyle,GAllocatorGH<GFxLineStyle,259>,GArrayDefaultPolicy>::ResizeNoConstruct(
      this: (int)a1,
      a2: (int)a1,
      a3: Size + v6);
    if ( Size + v6 > Size )
    {
      v16 = v6;
      v17 = (int)&a1->Data.Data[6 * Size];
      for ( pfmta = v17; v16 != 0; pfmta = v17 )
      {
        if ( v17 != 0 )
        {
          GFxLineStyle::GFxLineStyle(result: (CMemberFuncProxyBase<CLateBoundPtr<IMesh>,void (__thiscall IMesh::*)(IMesh *,int),CFuncMemPolicyNone> *)v21);
          v17 = pfmta;
        }
        v17 += 24;
        --v16;
      }
    }
    if ( v6 != 0 )
    {
      v18 = 6 * Size;
      do
      {
        v19 = *(_DWORD *)(p + 804);
        if ( v19 == 0 )
          v19 = p + 40;
        *(_BYTE *)(v19 + 21) = 0;
        GFxLineStyle::Read(
          this: (CMemberFuncProxyBase<CLateBoundPtr<IMesh>,void (__thiscall IMesh::*)(IMesh *,int),CFuncMemPolicyNone> *)&a1->Data.Data[v18],
          p);
        v18 += 6;
        --v6;
      }
      while ( v6 != 0 );
    }
    return v22;
  }
  else
  {
    if ( v6 != 0 )
      GFxLogBase<GFxLoadProcess>::LogError(
        this: nullptr,
        pfmt,
        a3: (int)"Error: GFx_ReadLineStyles, trying to read %d linestyles into no-style shape\n",
        a4: v6);
    return v14;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014BF30
// Name: public: GFxShapeBase::GFxShapeBase(void)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GFxShapeBase::GFxShapeBase(void *this)
{
  *(_DWORD *)this = &GFxShapeBase::`vftable';
  *((float *)this + 1) = 0.0;
  *((float *)this + 2) = 0.0;
  *((float *)this + 3) = 0.0;
  *((float *)this + 4) = 0.0;
  InterlockedExchange(Target: (volatile LONG *)this + 5, Value: 1);
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 8) = 0;
  *((float *)this + 1) = 0.0;
  *((float *)this + 2) = 0.0;
  *((float *)this + 3) = 0.0;
  *((float *)this + 4) = 0.0;
  *((_WORD *)this + 18) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1014BF80
// Name: public: void GFxPathPacker::AddLineTo(int,int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall GFxPathPacker::AddLineTo(CStridedConstPtr<__m128> *this, int x, int y, unsigned int numBits)
{
  unsigned int v5; // eax
  int *v6; // eax
  int v7; // edx
  unsigned int v8; // ecx
  unsigned __int8 result; // al
  unsigned int v10; // ecx
  unsigned int v11; // eax
  unsigned int v12; // eax
  $65641F8DABE66144ED05A5F444F1B791 e; // [esp+Ch] [ebp-14h] BYREF
  int v14; // [esp+10h] [ebp-10h]
  int v15; // [esp+14h] [ebp-Ch]
  int v16; // [esp+18h] [ebp-8h]
  int v17; // [esp+1Ch] [ebp-4h]

  v5 = *((_DWORD *)this + 10);
  e = x;
  v14 = y;
  v15 = x;
  v16 = y;
  LOBYTE(v17) = 1;
  if ( v5 >= *((_DWORD *)this + 8) )
  {
    GArrayData<GFxPathPacker::Edge,GAllocatorGH<GFxPathPacker::Edge,2>,GArrayDefaultPolicy>::PushBack(
      this: (int *)this + 7,
      result: (ModelRenderInfo_t *)&e);
  }
  else
  {
    v6 = (int *)(*((_DWORD *)this + 7) + 20 * v5);
    *v6 = x;
    v6[1] = y;
    v7 = v17;
    v6[2] = x;
    v6[3] = y;
    v6[4] = v7;
  }
  v8 = *((unsigned __int8 *)this + 52);
  result = numBits;
  ++*((_DWORD *)this + 10);
  ++*((_DWORD *)this + 12);
  if ( numBits > v8 )
  {
LABEL_46:
    *((_BYTE *)this + 52) = result;
    goto LABEL_47;
  }
  if ( numBits == 0 )
  {
    if ( x != 0 )
      v10 = 2 * abs32(x);
    else
      v10 = 0;
    v11 = y;
    if ( y != 0 )
      v11 = 2 * abs32(y);
    v12 = v10 | v11;
    if ( v12 >= 0x8000 )
    {
      if ( v12 >= 0x800000 )
      {
        if ( v12 >= 0x8000000 )
        {
          if ( v12 >= 0x20000000 )
          {
            if ( v12 >= 0x40000000 )
              result = 32 - (v12 < 0x80000000);
            else
              result = 30;
          }
          else
          {
            result = 29 - (v12 < 0x10000000);
          }
        }
        else if ( v12 >= 0x2000000 )
        {
          result = 27 - (v12 < 0x4000000);
        }
        else
        {
          result = 25 - (v12 < 0x1000000);
        }
      }
      else if ( v12 >= 0x80000 )
      {
        if ( v12 >= 0x200000 )
          result = 23 - (v12 < 0x400000);
        else
          result = 21 - (v12 < 0x100000);
      }
      else if ( v12 >= 0x20000 )
      {
        result = 19 - (v12 < 0x40000);
      }
      else
      {
        result = 17 - (v12 < 0x10000);
      }
    }
    else if ( v12 >= 0x80 )
    {
      if ( v12 >= 0x800 )
      {
        if ( v12 >= 0x2000 )
          result = 15 - (v12 < 0x4000);
        else
          result = 13 - (v12 < 0x1000);
      }
      else if ( v12 >= 0x200 )
      {
        result = 11 - (v12 < 0x400);
      }
      else
      {
        result = 9 - (v12 < 0x100);
      }
    }
    else if ( v12 >= 8 )
    {
      if ( v12 >= 0x20 )
        result = 7 - (v12 < 0x40);
      else
        result = 5 - (v12 < 0x10);
    }
    else if ( v12 >= 2 )
    {
      result = 3 - (v12 < 4);
    }
    else
    {
      result = v12 != 0;
    }
    if ( *((_BYTE *)this + 52) >= result )
      result = *((_BYTE *)this + 52);
    goto LABEL_46;
  }
LABEL_47:
  *((_DWORD *)this + 5) += x;
  *((_DWORD *)this + 6) += y;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1014C180
// Name: public: void GFxPathPacker::AddCurve(int,int,int,int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
const CSOAAttributeReference *__thiscall GFxPathPacker::AddCurve(
        int this,
        const CSOAAttributeReference *result,
        int cy,
        int a4,
        int ay,
        unsigned int numBits)
{
  int v6; // ebx
  unsigned int v8; // eax
  _DWORD *v9; // eax
  int v10; // ecx
  int v11; // edx
  unsigned int v12; // ecx
  unsigned __int8 v13; // al
  unsigned int v14; // edi
  unsigned int v15; // ecx
  unsigned int v16; // eax
  unsigned int v17; // eax
  $65641F8DABE66144ED05A5F444F1B791 e; // [esp+Ch] [ebp-14h] BYREF
  int v20; // [esp+10h] [ebp-10h]
  int v21; // [esp+14h] [ebp-Ch]
  int v22; // [esp+18h] [ebp-8h]
  int v23; // [esp+1Ch] [ebp-4h]

  v6 = (int)result;
  v22 = ay;
  v8 = *(_DWORD *)(this + 40);
  e = ($65641F8DABE66144ED05A5F444F1B791)result;
  v20 = cy;
  v21 = a4;
  LOBYTE(v23) = 0;
  if ( v8 >= *(_DWORD *)(this + 32) )
  {
    GArrayData<GFxPathPacker::Edge,GAllocatorGH<GFxPathPacker::Edge,2>,GArrayDefaultPolicy>::PushBack(
      this: (int *)(this + 28),
      result: (ModelRenderInfo_t *)&e);
  }
  else
  {
    v9 = (_DWORD *)(*(_DWORD *)(this + 28) + 20 * v8);
    v6 = (int)result;
    *v9 = result;
    v10 = v22;
    v9[1] = cy;
    v11 = v23;
    v9[2] = a4;
    v9[3] = v10;
    v9[4] = v11;
  }
  v12 = *(unsigned __int8 *)(this + 52);
  ++*(_DWORD *)(this + 40);
  ++*(_DWORD *)(this + 44);
  v13 = numBits;
  if ( numBits > v12 )
  {
LABEL_52:
    *(_BYTE *)(this + 52) = v13;
    goto LABEL_53;
  }
  if ( numBits == 0 )
  {
    if ( v6 != 0 )
      v6 = 2 * abs32(v6);
    if ( cy != 0 )
      v14 = 2 * abs32(cy);
    else
      v14 = 0;
    if ( a4 != 0 )
      v15 = 2 * abs32(a4);
    else
      v15 = 0;
    v16 = ay;
    if ( ay != 0 )
      v16 = 2 * abs32(ay);
    v17 = v6 | v14 | v15 | v16;
    if ( v17 >= 0x8000 )
    {
      if ( v17 >= 0x800000 )
      {
        if ( v17 >= 0x8000000 )
        {
          if ( v17 >= 0x20000000 )
          {
            if ( v17 >= 0x40000000 )
              v13 = 32 - (v17 < 0x80000000);
            else
              v13 = 30;
          }
          else
          {
            v13 = 29 - (v17 < 0x10000000);
          }
        }
        else if ( v17 >= 0x2000000 )
        {
          v13 = 27 - (v17 < 0x4000000);
        }
        else
        {
          v13 = 25 - (v17 < 0x1000000);
        }
      }
      else if ( v17 >= 0x80000 )
      {
        if ( v17 >= 0x200000 )
          v13 = 23 - (v17 < 0x400000);
        else
          v13 = 21 - (v17 < 0x100000);
      }
      else if ( v17 >= 0x20000 )
      {
        v13 = 19 - (v17 < 0x40000);
      }
      else
      {
        v13 = 17 - (v17 < 0x10000);
      }
    }
    else if ( v17 >= 0x80 )
    {
      if ( v17 >= 0x800 )
      {
        if ( v17 >= 0x2000 )
          v13 = 15 - (v17 < 0x4000);
        else
          v13 = 13 - (v17 < 0x1000);
      }
      else if ( v17 >= 0x200 )
      {
        v13 = 11 - (v17 < 0x400);
      }
      else
      {
        v13 = 9 - (v17 < 0x100);
      }
    }
    else if ( v17 >= 8 )
    {
      if ( v17 >= 0x20 )
        v13 = 7 - (v17 < 0x40);
      else
        v13 = 5 - (v17 < 0x10);
    }
    else if ( v17 >= 2 )
    {
      v13 = 3 - (v17 < 4);
    }
    else
    {
      v13 = v17 != 0;
    }
    if ( *(_BYTE *)(this + 52) >= v13 )
      v13 = *(_BYTE *)(this + 52);
    v6 = (int)result;
    goto LABEL_52;
  }
LABEL_53:
  *(_DWORD *)(this + 20) += a4 + v6;
  *(_DWORD *)(this + 24) += ay + cy;
  return (const CSOAAttributeReference *)(ay + cy);
}

//------------------------------------------------------------------------------
// Address: 0x1014C3C0
// Name: public: void GFxPathPacker::LineToAbs(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxPathPacker::LineToAbs(CSOAAttributeReference *this, float x, int y)
{
  GFxPathPacker::AddLineTo(
    (CStridedConstPtr<__m128> *)this,
    x: LODWORD(x) - *((_DWORD *)this + 5),
    y: y - *((_DWORD *)this + 6),
    numBits: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1014C3E0
// Name: public: void GFxPathPacker::CurveToAbs(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxPathPacker::CurveToAbs(GFxPathPacker *this, int a2, int a3, int a4, int a5)
{
  GFxPathPacker::AddCurve(
    (int)this,
    result: (const CSOAAttributeReference *)(a2 - *((_DWORD *)this + 5)),
    cy: a3 - *((_DWORD *)this + 6),
    a4: a4 - a2,
    ay: a5 - a3,
    numBits: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1014C410
// Name: public: void GFxPathPacker::ClosePath(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxPathPacker::ClosePath(CStridedConstPtr<__m128> *this)
{
  int v1; // edx
  int v2; // eax

  v1 = *((_DWORD *)this + 5);
  v2 = *((_DWORD *)this + 3);
  if ( v1 != v2 || *((_DWORD *)this + 6) != *((_DWORD *)this + 4) )
    GFxPathPacker::AddLineTo(this, x: v2 - v1, y: *((_DWORD *)this + 4) - *((_DWORD *)this + 6), numBits: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1014C440
// Name: public: virtual void GFxConstShapeNoStyles::Tessellate(class GFxMeshSet __near *,float,class GFxDisplayContext __near &,struct GFxScale9GridInfo __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxConstShapeNoStyles::Tessellate(
        CBitRead *this,
        Vector *meshSet,
        char *a3,
        int s9g,
        CMemberFuncProxy1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(Vector),Vector,CFuncMemPolicyNone> *s9g_4)
{
  GFxShapeBase::TessellateImpl<GFxSwfPathData>(
    (GFxShapeBase *)this,
    a2: (struct GFxMeshSet *)meshSet,
    a3,
    a4: s9g,
    a5: s9g_4,
    a6: 100.0);
}

//------------------------------------------------------------------------------
// Address: 0x1014C470
// Name: public: virtual void GFxConstShapeNoStyles::MakeCompoundShape(class GCompoundShape __near *,float)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall GFxConstShapeNoStyles::MakeCompoundShape(CBitRead *this, EBitCoordType cs, char *tolerance)
{
  double result; // st7
  GFxSwfPathData::PathsIterator v5[8]; // [esp+Ch] [ebp-74h] BYREF
  char v6; // [esp+2Ch] [ebp-54h]

  GCompoundShape::Clear(this: (GCompoundShape *)cs);
  result = *(float *)&tolerance;
  GCompoundShape::SetCurveTolerance(this: (long double *)cs, t: tolerance);
  *(_BYTE *)(cs + 68) = (*(_BYTE *)(this + 1) & 8) != 0;
  GFxSwfPathData::PathsIterator::PathsIterator(this: v5, a2: (CFltX4AttributeIterator *)this);
  while ( v6 != 1 )
    GFxSwfPathData::PathsIterator::AddForTessellation(this: v5, a2: (GCompoundShape *)cs);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1014C4D0
// Name: public: GFxShapeNoStyles::GFxShapeNoStyles(unsigned int)
// Source: json
//------------------------------------------------------------------------------
GFxShapeNoStyles *__thiscall GFxShapeNoStyles::GFxShapeNoStyles(GFxShapeNoStyles *this, __int16 pageSize)
{
  *(_DWORD *)this = &GFxShapeBase::`vftable';
  *((float *)this + 1) = 0.0;
  *((float *)this + 2) = 0.0;
  *((float *)this + 3) = 0.0;
  *((float *)this + 4) = 0.0;
  InterlockedExchange(Target: (volatile LONG *)this + 5, Value: 1);
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 8) = 0;
  *((float *)this + 1) = 0.0;
  *((float *)this + 2) = 0.0;
  *((float *)this + 3) = 0.0;
  *((float *)this + 4) = 0.0;
  *((_WORD *)this + 18) = 0;
  *(_DWORD *)this = &GFxShapeNoStyles::`vftable';
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 11) = 0;
  *((_WORD *)this + 24) = 0;
  *((_WORD *)this + 25) = pageSize;
  *((_DWORD *)this + 13) = 0;
  *((_DWORD *)this + 14) = 0;
  *((_DWORD *)this + 15) = 0;
  *((_WORD *)this + 32) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1014C5B0
// Name: public: virtual void GFxShapeNoStyles::Tessellate(class GFxMeshSet __near *,float,class GFxDisplayContext __near &,struct GFxScale9GridInfo __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxShapeNoStyles::Tessellate(CMaterialVar *this, int tolerance, char *a3, int s9g, int s9g_4)
{
  GFxShapeBase::TessellateImpl<GFxPathData>((GFxShapeBase *)this, a2: tolerance, a3, a4: s9g, a5: s9g_4, a6: 100.0);
}

//------------------------------------------------------------------------------
// Address: 0x1014C5E0
// Name: public: virtual void GFxShapeNoStyles::MakeCompoundShape(class GCompoundShape __near *,float)const
// Source: json
//------------------------------------------------------------------------------
const CMemberFunctor0<CMaterialVar *,void (__thiscall CMaterialVar::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *__thiscall GFxShapeNoStyles::MakeCompoundShape(
        void *this,
        CSOAContainer *result,
        char *tolerance)
{
  return (const CMemberFunctor0<CMaterialVar *,void (__thiscall CMaterialVar::*)(void),CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *)GFxShapeBase::MakeCompoundShapeImpl<GFxPathData>((int)this, a2: result, tolerance);
}

//------------------------------------------------------------------------------
// Address: 0x1014C600
// Name: public: virtual void GFxConstShapeWithStyles::Tessellate(class GFxMeshSet __near *,float,class GFxDisplayContext __near &,struct GFxScale9GridInfo __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxConstShapeWithStyles::Tessellate(
        GFxConstShapeWithStyles *this,
        struct GFxMeshSet *tolerance,
        char *a3,
        struct GFxDisplayContext *s9g,
        CMemberFuncProxy1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(Vector),Vector,CFuncMemPolicyNone> *s9g_4)
{
  GFxShapeBase::TessellateImpl<GFxSwfPathData>(
    (GFxShapeBase *)this,
    a2: tolerance,
    a3,
    a4: (int)s9g,
    a5: s9g_4,
    a6: *((float *)this + 15));
}

//------------------------------------------------------------------------------
// Address: 0x1014C670
// Name: public: virtual GFxShapeWithStyles::~GFxShapeWithStyles(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxShapeWithStyles::~GFxShapeWithStyles(IClientUnknown *this)
{
  int v2; // eax
  void (__thiscall ***v3)(_DWORD, _DWORD); // edi
  int v4; // ebx
  int v5; // eax
  int v6; // edi
  int v7; // ebx
  GFxMeshCache *v8; // ecx
  void (__thiscall ***v9)(_DWORD, int); // ecx
  CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),CFuncMemPolicyNone> *v10; // [esp+0h] [ebp-Ch]

  this->__vftable = (IClientUnknown_vtbl *)&GFxShapeWithStyles::`vftable';
  v2 = *((_DWORD *)this + 24);
  v3 = (void (__thiscall ***)(_DWORD, _DWORD))(*((_DWORD *)this + 23) + 24 * v2 - 24);
  if ( v2 != 0 )
  {
    v4 = *((_DWORD *)this + 24);
    do
    {
      (**v3)(a1: v3, a2: 0);
      v3 -= 6;
      --v4;
    }
    while ( v4 != 0 );
  }
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 23));
  v5 = *((_DWORD *)this + 21);
  v6 = *((_DWORD *)this + 20) + 40 * v5 - 40;
  if ( v5 != 0 )
  {
    v7 = *((_DWORD *)this + 21);
    do
    {
      GFxFillStyle::~GFxFillStyle(result: v10);
      v6 -= 40;
      --v7;
    }
    while ( v7 != 0 );
  }
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 20));
  GFxPathAllocator::Clear(this: (FloatCubeMap_t *)(this + 17));
  GFxPathAllocator::Clear(this: (FloatCubeMap_t *)(this + 10));
  v8 = *((GFxMeshCache **)this + 6);
  this->__vftable = (IClientUnknown_vtbl *)&GFxShapeBase::`vftable';
  if ( v8 != nullptr )
    GFxMeshCache::AddShapeToKillList(this: v8, a2: (struct GFxShapeBase *)this);
  v9 = *((void (__thiscall ****)(_DWORD, int))this + 8);
  *((_DWORD *)this + 6) = 0;
  if ( v9 != nullptr )
    (**v9)(a1: v9, a2: 1);
  *((_DWORD *)this + 8) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1014C720
// Name: public: virtual void GFxShapeWithStyles::SetMaxStrokeExtent(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxShapeWithStyles::SetMaxStrokeExtent(IPVSNotify *this, IPVSNotify m)
{
  *(this + 26) = m;
}

//------------------------------------------------------------------------------
// Address: 0x1014C730
// Name: public: virtual float GFxShapeWithStyles::GetMaxStrokeExtent(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall GFxShapeWithStyles::GetMaxStrokeExtent(GFxShapeWithStyles *this)
{
  return *((float *)this + 26);
}

//------------------------------------------------------------------------------
// Address: 0x1014C740
// Name: public: virtual class GFxFillStyle const __near * GFxShapeWithStyles::GetFillStyles(unsigned int __near *)const
// Source: json
//------------------------------------------------------------------------------
const struct GFxFillStyle *__thiscall GFxShapeWithStyles::GetFillStyles(
        GFxShapeWithStyles *this,
        unsigned int *pstylesNum)
{
  *pstylesNum = *((_DWORD *)this + 21);
  if ( *((_DWORD *)this + 21) != 0 )
    return *((const struct GFxFillStyle **)this + 20);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1014C760
// Name: public: virtual class GFxLineStyle const __near * GFxShapeWithStyles::GetLineStyles(unsigned int __near *)const
// Source: json
//------------------------------------------------------------------------------
const struct GFxLineStyle *__thiscall GFxShapeWithStyles::GetLineStyles(
        GFxShapeWithStyles *this,
        unsigned int *pstylesNum)
{
  *pstylesNum = *((_DWORD *)this + 24);
  if ( *((_DWORD *)this + 24) != 0 )
    return *((const struct GFxLineStyle **)this + 23);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1014C780
// Name: public: virtual void GFxShapeWithStyles::GetFillAndLineStyles(class GFxFillStyle const __near * __near *,unsigned int __near *,class GFxLineStyle const __near * __near *,unsigned int __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxShapeWithStyles::GetFillAndLineStyles(
        GFxShapeWithStyles *this,
        CSOAAttributeReferenceBinaryOp<&DivSIMD> *const ppfillStyles,
        unsigned int *pfillStylesNum,
        const struct GFxLineStyle **plineStylesNum,
        unsigned int *a5)
{
  CSOAContainer *v5; // eax

  *pfillStylesNum = *((_DWORD *)this + 21);
  *a5 = *((_DWORD *)this + 24);
  if ( *((_DWORD *)this + 21) != 0 )
    v5 = *((CSOAContainer **)this + 20);
  else
    v5 = nullptr;
  ppfillStyles->m_opA.m_pContainer = v5;
  if ( *((_DWORD *)this + 24) != 0 )
    *plineStylesNum = *((const struct GFxLineStyle **)this + 23);
  else
    *plineStylesNum = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1014C7D0
// Name: public: virtual void GFxShapeWithStyles::GetFillAndLineStyles(struct GFxDisplayParams __near *)const
// Source: json
//------------------------------------------------------------------------------
CMemberFunctor1<CMaterialVar *,void (__thiscall CMaterialVar::*)(VMatrix const &),VMatrix,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *__thiscall GFxShapeWithStyles::GetFillAndLineStyles(
        int this,
        CMemberFunctor1<CMaterialVar *,void (__thiscall CMaterialVar::*)(VMatrix const &),VMatrix,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *result)
{
  CMemberFunctor1<CMaterialVar *,void (__thiscall CMaterialVar::*)(VMatrix const &),VMatrix,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *v2; // eax
  bool v3; // zf
  unsigned int v4; // edx

  v2 = result;
  result->m_arg1.m[2][0] = *(float *)(this + 84);
  v3 = LODWORD(result->m_arg1.m[2][0]) == 0;
  result->m_arg1.m[2][1] = *(float *)(this + 96);
  if ( v3 )
    v4 = 0;
  else
    v4 = *(_DWORD *)(this + 80);
  v3 = LODWORD(result->m_arg1.m[2][1]) == 0;
  result->m_nUserID = v4;
  if ( v3 )
    result->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CRefCountServiceDestruct<CRefST>::__vftable = nullptr;
  else
    result->CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >::CRefCountServiceDestruct<CRefST>::__vftable = *(CRefCountServiceDestruct<CRefST>_vtbl **)(this + 92);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x1014C810
// Name: public: virtual class GRect<float> GFxShapeWithStyles::GetRectBoundsLocal(void)const
// Source: rtti_class
//------------------------------------------------------------------------------
float *__thiscall GFxShapeWithStyles::GetRectBoundsLocal(float *this, float *a2)
{
  *a2 = *(this + 27);
  a2[1] = *(this + 28);
  a2[2] = *(this + 29);
  a2[3] = *(this + 30);
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x1014C840
// Name: public: virtual void GFxShapeWithStyles::SetRectBoundsLocal(class GRect<float> const __near &)
// Source: json
//------------------------------------------------------------------------------
float *__thiscall GFxShapeWithStyles::SetRectBoundsLocal(
        float *this,
        CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *r)
{
  float *result; // eax
  float v3; // [esp+0h] [ebp-8h]
  float v4; // [esp+4h] [ebp-4h]
  int ra; // [esp+10h] [ebp+8h]

  result = (float *)r;
  ra = r->m_Memory.m_nAllocationCount;
  v4 = result[2];
  v3 = result[3];
  *(this + 27) = *result;
  *(this + 28) = *(float *)&ra;
  *(this + 29) = v4;
  *(this + 30) = v3;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1014C880
// Name: public: virtual void GFxShapeWithStyles::Tessellate(class GFxMeshSet __near *,float,class GFxDisplayContext __near &,struct GFxScale9GridInfo __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxShapeWithStyles::Tessellate(
        GFxShapeWithStyles *this,
        struct GFxMeshSet *tolerance,
        char *a3,
        struct GFxDisplayContext *s9g,
        struct GFxScale9GridInfo *s9g_4)
{
  GFxShapeBase::TessellateImpl<GFxPathData>(
    (GFxShapeBase *)this,
    a2: (int)tolerance,
    a3,
    a4: (int)s9g,
    a5: (int)s9g_4,
    a6: *((float *)this + 26));
}

//------------------------------------------------------------------------------
// Address: 0x1014C8B0
// Name: public: virtual void GFxShapeCharacterDef::MakeCompoundShape(class GCompoundShape __near *,float)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall GFxShapeCharacterDef::MakeCompoundShape(old_bf_read *this, CSOAContainer *a2, char *tolerance)
{
  return (const char *)GFxShapeBase::MakeCompoundShapeImpl<GFxPathData>(this: (int)&this->m_bOverflow, a2, tolerance);
}

//------------------------------------------------------------------------------
// Address: 0x1014C8D0
// Name: public: virtual void GFxShapeCharacterDef::PreTessellate(float,class GFxRenderConfig const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxShapeCharacterDef::PreTessellate(
        old_bf_read *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        float masterScale,
        struct GFxRenderConfig *a5)
{
  GFxShapeBase::PreTessellateImpl<GFxPathData>(
    a1: (struct GFxShapeBase *)&this->m_bOverflow,
    a2,
    a3,
    a4: masterScale,
    a5,
    a6: COERCE_STRUCT_GFXFILLSTYLE_(100.0));
}

//------------------------------------------------------------------------------
// Address: 0x1014C900
// Name: public: virtual void GFxConstShapeCharacterDef::MakeCompoundShape(class GCompoundShape __near *,float)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxConstShapeCharacterDef::MakeCompoundShape(
        GFxConstShapeCharacterDef *this,
        CSOAContainer *a2,
        char *tolerance)
{
  CFltX4AttributeIterator *v3; // edi
  GFxSwfPathData::PathsIterator v4[8]; // [esp+Ch] [ebp-74h] BYREF
  char v5; // [esp+2Ch] [ebp-54h]

  v3 = (CFltX4AttributeIterator *)((char *)this + 16);
  GCompoundShape::Clear(this: (GCompoundShape *)a2);
  GCompoundShape::SetCurveTolerance(this: (long double *)&a2->m_nColumns, t: tolerance);
  LOBYTE(a2->m_pAttributePtrs[11]) = (v3[4].m_nStride & 8) != 0;
  GFxSwfPathData::PathsIterator::PathsIterator(this: v4, a2: v3);
  while ( v5 != 1 )
    GFxSwfPathData::PathsIterator::AddForTessellation(this: v4, (GCompoundShape *)a2);
}

//------------------------------------------------------------------------------
// Address: 0x1014C960
// Name: public: virtual void GFxConstShapeCharacterDef::PreTessellate(float,class GFxRenderConfig const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxConstShapeCharacterDef::PreTessellate(
        CMemberFunctor2<CMaterialVar *,void (__thiscall CMaterialVar::*)(unsigned long,void *),unsigned long,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this@<ecx>,
        int a2@<ebx>,
        int a3@<esi>,
        const CMemberFunctor2<CMaterialVar *,void (__thiscall CMaterialVar::*)(unsigned long,void *),unsigned long,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *masterScale,
        struct GFxRenderConfig *a5)
{
  GFxShapeBase::PreTessellateImpl<GFxSwfPathData>(
    a1: (struct GFxShapeBase *)&this->m_Proxy,
    a2,
    a3,
    a4: *(float *)&masterScale,
    a5,
    a6: 100.0);
}

//------------------------------------------------------------------------------
// Address: 0x1014C990
// Name: public: bool GFxShapeBase::PointInShape<class GFxSwfPathData,class GFxSwfPathData::PathsIterator>(class GFxSwfPathData::PathsIterator __near &,struct GFxScale9GridInfo const __near *,float,float)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxShapeBase::PointInShape<GFxSwfPathData,GFxSwfPathData::PathsIterator>(
        _BYTE *this,
        IKMeansErrorMetric *a2,
        GFxScale9GridInfo *a3,
        _iobuf *x,
        int *y)
{
  int (__thiscall *v6)(_BYTE *, int *); // edx
  int m_nAttributeID; // edi
  bool v8; // zf
  char v9; // al
  GFxRenderGenStroker *v10; // ebx
  unsigned int v11; // edi
  int v12; // esi
  int v13; // ecx
  double v14; // st7
  int v15; // eax
  float v16; // esi
  CSOAContainer *v17; // ecx
  char v18; // al
  GFxRenderGenStroker *v19; // eax
  GFxRenderGenStroker *v20; // esi
  double v21; // st7
  unsigned int v22; // edi
  int v23; // ecx
  int v24; // eax
  double v26; // st7
  int v27; // eax
  int v28; // eax
  int v29; // eax
  int v30; // eax
  char v31; // al
  int v32; // [esp+38h] [ebp-64h]
  float v33; // [esp+3Ch] [ebp-60h]
  float v34; // [esp+40h] [ebp-5Ch]
  GFxSwfPathData::EdgesIterator v35; // [esp+44h] [ebp-58h] BYREF
  int v36; // [esp+54h] [ebp-48h] BYREF
  float v37; // [esp+58h] [ebp-44h]
  int v38; // [esp+5Ch] [ebp-40h]
  float v39; // [esp+60h] [ebp-3Ch]
  GMath2D *v40; // [esp+64h] [ebp-38h]
  float v41; // [esp+68h] [ebp-34h] BYREF
  GFxScale9GridInfo *v42; // [esp+6Ch] [ebp-30h]
  float v43; // [esp+70h] [ebp-2Ch] BYREF
  int v44; // [esp+74h] [ebp-28h]
  int v45; // [esp+78h] [ebp-24h] BYREF
  float v46; // [esp+7Ch] [ebp-20h]
  char v47; // [esp+83h] [ebp-19h]
  float v48; // [esp+84h] [ebp-18h] BYREF
  float v49; // [esp+88h] [ebp-14h] BYREF
  GMath2D *v50; // [esp+8Ch] [ebp-10h] BYREF
  float v51; // [esp+90h] [ebp-Ch] BYREF
  char v52; // [esp+94h] [ebp-8h]

  v6 = *(int (__thiscall **)(_BYTE *, int *))(*(_DWORD *)this + 40);
  m_nAttributeID = (int)a2;
  v42 = a3;
  v35.m_opB.m_nAttributeID = (int)a2;
  v36 = 0;
  v32 = v6(a1: this, a2: &v36);
  if ( v36 == 0 || (v8 = (*(this + 36) & 0x40) == 0, v47 = 1, v8) )
    v47 = 0;
  v9 = (char)a2[8].__vftable;
  v10 = nullptr;
  v44 = 0;
  if ( v9 != 1 )
  {
    do
    {
      if ( v9 == 2 )
      {
        if ( v44 != 0 )
          goto LABEL_57;
        do
          GFxSwfPathData::PathsIterator::ReadNext(this: (IKMeansErrorMetric *)m_nAttributeID);
        while ( *(_BYTE *)(m_nAttributeID + 32) == 3 );
        v44 = 0;
      }
      else
      {
        v15 = *(_DWORD *)(m_nAttributeID + 28);
        v16 = *(float *)(m_nAttributeID + 20);
        v17 = *(CSOAContainer **)(m_nAttributeID + 24);
        v46 = v16;
        v35.m_opB.m_pContainer = v17;
        v38 = v15;
        if ( v15 != 0 || (LODWORD(v16) == 0) != (v17 == nullptr) )
        {
          v18 = *(_BYTE *)(m_nAttributeID + 32);
          v35.m_opA.m_pContainer = (CSOAContainer *)m_nAttributeID;
          v35.m_opA.m_nAttributeID = 0;
          if ( v18 >= 0 && v18 != 1 )
          {
            do
              GFxSwfPathData::PathsIterator::ReadNext(this: (IKMeansErrorMetric *)m_nAttributeID);
            while ( *(_BYTE *)(m_nAttributeID + 32) == 3 );
          }
          v43 = (float)*(int *)(m_nAttributeID + 44);
          v41 = (float)*(int *)(m_nAttributeID + 48);
          if ( *(char *)(m_nAttributeID + 112) < 0 )
          {
            v43 = v43 * *(float *)(m_nAttributeID + 108);
            v41 = v41 * *(float *)(m_nAttributeID + 108);
          }
          if ( v42 != nullptr )
            GFxScale9GridInfo::Transform(this: v42, x: &v43, a3: &v41);
          if ( v47 != 0 && v38 != 0 )
          {
            if ( v10 == nullptr )
            {
              v45 = 2;
              v19 = (GFxRenderGenStroker *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 196, a3: &v45);
              if ( v19 != nullptr )
                v20 = GFxRenderGenStroker::GFxRenderGenStroker(this: v19);
              else
                v20 = nullptr;
              v10 = v20;
              GCompoundShape::SetCurveTolerance(this: (long double *)((char *)v20 + 52), t: COERCE_CHAR_(20.0));
              GCompoundShape::SetCurveTolerance(
                this: (long double *)((char *)v20 + 124),
                t: COERCE_CHAR_(*((float *)v20 + 13)));
              m_nAttributeID = v35.m_opB.m_nAttributeID;
              v16 = v46;
            }
            GCompoundShape::BeginPath(this: (char *)v10 + 52, lStyle: (localeinfo_struct *)0xFFFFFFFF);
          }
          while ( 1 )
          {
            if ( SLOBYTE(v35.m_opA.m_pContainer->m_pAttributePtrs[2]) >= 0 )
              goto LABEL_9;
            GFxSwfPathData::EdgesIterator::GetEdge(
              this: &v35,
              a2: (struct GFxSwfPathData::EdgesIterator::Edge *)&v48,
              a3: false);
            if ( v42 != nullptr )
              GFxScale9GridInfo::Transform(this: v42, x: (float *)&v50, a3: &v51);
            *(float *)&v45 = v43;
            v39 = v41;
            v40 = v50;
            v37 = v51;
            if ( v51 < (double)v41 )
            {
              v45 = (int)v50;
              *(float *)&v40 = v43;
              v39 = v51;
              v37 = v41;
            }
            if ( v52 != 0 )
            {
              if ( v42 != nullptr )
                GFxScale9GridInfo::Transform(this: v42, x: &v48, a3: &v49);
              if ( (LODWORD(v16) == 0) != (v35.m_opB.m_pContainer == nullptr)
                && GMath2D::CheckCurveIntersection(
                     this: (GMath2D *)v45,
                     a2: v39,
                     a3: v48,
                     a4: v49,
                     a5: *(float *)&v40,
                     a6: v37,
                     a7: *(float *)&x,
                     a8: *(float *)&y) )
              {
                v44 ^= 1u;
              }
            }
            else if ( (LODWORD(v16) == 0) != (v35.m_opB.m_pContainer == nullptr) )
            {
              v21 = *(float *)&y;
              if ( v39 <= (double)*(float *)&y && v37 > v21 )
              {
                *(float *)&v45 = (*(float *)&x - *(float *)&v40) * (v37 - v39)
                               - (*(float *)&v40 - *(float *)&v45) * (v21 - v37);
                if ( *(float *)&v45 > 0.0 )
                  v44 ^= 1u;
              }
            }
            if ( v47 != 0 && v38 != 0 )
            {
              if ( v52 != 0 )
              {
                GCompoundShape::AddCurve(
                  this: (GCompoundShape *)v10 + 13,
                  a2: v48,
                  a3: v49,
                  a4: *(float *)&v50,
                  a5: v51);
                v43 = *(float *)&v50;
                v41 = v51;
                continue;
              }
              v33 = *(float *)&v50;
              v22 = *((_DWORD *)v10 + 15) >> 8;
              v34 = v51;
              if ( v22 >= *((_DWORD *)v10 + 16) )
                GArrayPagedBase<GPointType,8,64,GAllocatorPagedLH_POD<GPointType,138>>::allocatePage(a1: v22);
              v23 = *(_DWORD *)(*((_DWORD *)v10 + 18) + 4 * v22);
              m_nAttributeID = v35.m_opB.m_nAttributeID;
              v16 = v46;
              v24 = (unsigned __int8)*((_DWORD *)v10 + 15);
              *(float *)(v23 + 8 * v24) = v33;
              *(float *)(v23 + 8 * v24 + 4) = v34;
              ++*((_DWORD *)v10 + 15);
              ++*(_DWORD *)(*((_DWORD *)v10 + 23) + 4);
            }
            v43 = *(float *)&v50;
            v41 = v51;
          }
        }
        GFxSwfPathData::PathsIterator::SkipComplex(this: (IKMeansErrorMetric *)m_nAttributeID);
      }
LABEL_9:
      v9 = *(_BYTE *)(m_nAttributeID + 32);
    }
    while ( v9 != 1 );
    if ( v44 != 0 )
    {
LABEL_57:
      if ( v10 == nullptr )
        return 1;
LABEL_58:
      GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)v10);
      return 1;
    }
    if ( v10 != nullptr )
    {
      v11 = 0;
      if ( *((_DWORD *)v10 + 19) != 0 )
      {
        do
        {
          v12 = *(_DWORD *)(*((_DWORD *)v10 + 22) + 4 * (v11 >> 6)) + 24 * (v11 & 0x3F);
          v13 = v32 + 24 * *(_DWORD *)(v12 + 20);
          LODWORD(v46) = *(unsigned __int16 *)(v13 + 4);
          if ( (double)SLODWORD(v46) >= 20.0 )
            v14 = (double)SLODWORD(v46);
          else
            v14 = 20.0;
          v46 = v14;
          v46 = v46 * 0.5;
          v26 = v46;
          *((float *)v10 + 2) = v46;
          if ( v26 < 0.0 )
            v26 = -v26;
          v46 = v26;
          *((float *)v10 + 3) = v46;
          v27 = *(_WORD *)(v13 + 16) & 0x30;
          v28 = v27 == 16 ? 4 : v27 != 32 ? 3 : 0;
          *((_DWORD *)v10 + 4) = v28;
          if ( (*(_WORD *)(v13 + 16) & 0xC0) == 0x40 )
            v29 = 0;
          else
            v29 = (*(_WORD *)(v13 + 16) & 0xC0) == 0x80 ? 1 : 2;
          *((_DWORD *)v10 + 5) = v29;
          if ( ((*(unsigned __int16 *)(v13 + 16) >> 2) & 0xC0) == 0x40 )
            v30 = 0;
          else
            v30 = ((*(unsigned __int16 *)(v13 + 16) >> 2) & 0xC0) == 0x80 ? 1 : 2;
          *((_DWORD *)v10 + 6) = v30;
          if ( (*(_BYTE *)(v13 + 16) & 0x30) == 0x20 )
            *((float *)v10 + 7) = *(float *)(v13 + 20);
          GCompoundShape::Clear(this: (GCompoundShape *)v10 + 31);
          GStroker::generateEquidistant(
            this: (unsigned int)v10 + 8,
            srcPath: (long double *)v12,
            dstShape: (unsigned int)v10 + 124);
          GCompoundShape::PointInShape(this: (_WORD)v10 + 124, x, y);
          if ( v31 != 0 )
            goto LABEL_58;
        }
        while ( ++v11 < *((_DWORD *)v10 + 19) );
      }
      GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)v10);
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1014CEE0
// Name: public: bool GFxShapeBase::PointInShape<class GFxPathData,class GFxPathData::PathsIterator>(class GFxPathData::PathsIterator __near &,struct GFxScale9GridInfo const __near *,float,float)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxShapeBase::PointInShape<GFxPathData,GFxPathData::PathsIterator>(
        _BYTE *this,
        CSOAContainer *a2,
        GFxScale9GridInfo *a3,
        _iobuf *x,
        int *y)
{
  int (__thiscall *v6)(_BYTE *, int *); // edx
  bool v7; // zf
  unsigned __int8 *v8; // eax
  char *m_nRows; // eax
  char v10; // cl
  unsigned __int8 *v11; // ecx
  int v12; // esi
  int v13; // ecx
  _BYTE *v14; // eax
  _DWORD *v15; // ecx
  int v16; // ecx
  char v17; // cl
  unsigned __int16 *v18; // eax
  int v19; // esi
  int v20; // edi
  int *v21; // eax
  GFxRenderGenStroker *v22; // eax
  GFxScale9GridInfo *v23; // edi
  float v24; // esi
  double v25; // st7
  GRefCountNTSImpl *v26; // esi
  volatile unsigned int RefCount; // edi
  GRefCountNTSImpl_vtbl *v28; // edi
  void (__thiscall *dtr_GRefCountImplCore)(struct GRefCountNTSImpl *); // ecx
  int v30; // eax
  int v31; // ecx
  int m_pDataMemory_low; // edx
  int m_nSlices; // eax
  int *v34; // eax
  int v35; // eax
  unsigned int v37; // ebx
  GRefCountNTSImpl *v38; // esi
  int v39; // edi
  int v40; // ecx
  double v41; // st7
  unsigned int v42; // edx
  double v43; // st7
  int v44; // eax
  int v45; // eax
  int v46; // eax
  int v47; // eax
  char v48; // al
  int v49; // [esp+2Ch] [ebp-90h]
  int v50; // [esp+30h] [ebp-8Ch]
  int v51; // [esp+34h] [ebp-88h]
  int v52; // [esp+38h] [ebp-84h] BYREF
  unsigned int v53; // [esp+3Ch] [ebp-80h]
  unsigned int v54; // [esp+40h] [ebp-7Ch]
  int v55; // [esp+44h] [ebp-78h]
  int v56; // [esp+48h] [ebp-74h]
  int v57; // [esp+54h] [ebp-68h]
  int v58; // [esp+58h] [ebp-64h]
  float v59; // [esp+5Ch] [ebp-60h]
  int v60; // [esp+60h] [ebp-5Ch]
  float v61; // [esp+64h] [ebp-58h]
  float v62; // [esp+68h] [ebp-54h]
  int v63; // [esp+6Ch] [ebp-50h] BYREF
  float v64; // [esp+70h] [ebp-4Ch]
  float v65; // [esp+74h] [ebp-48h]
  float v66; // [esp+78h] [ebp-44h] BYREF
  unsigned int v67; // [esp+7Ch] [ebp-40h] BYREF
  GFxScale9GridInfo *v68; // [esp+80h] [ebp-3Ch]
  int v69; // [esp+84h] [ebp-38h]
  unsigned int v70; // [esp+88h] [ebp-34h]
  int v71; // [esp+8Ch] [ebp-30h]
  float v72; // [esp+90h] [ebp-2Ch]
  unsigned int dstShape; // [esp+94h] [ebp-28h]
  GRefCountNTSImpl *v74; // [esp+98h] [ebp-24h]
  int v75; // [esp+9Ch] [ebp-20h] BYREF
  char v76; // [esp+A3h] [ebp-19h]
  float v77; // [esp+A4h] [ebp-18h] BYREF
  float v78; // [esp+A8h] [ebp-14h] BYREF
  float v79; // [esp+ACh] [ebp-10h] BYREF
  float v80; // [esp+B0h] [ebp-Ch] BYREF
  char v81; // [esp+B4h] [ebp-8h]

  v6 = *(int (__thiscall **)(_BYTE *, int *))(*(_DWORD *)this + 40);
  v68 = a3;
  v63 = 0;
  v60 = v6(a1: this, a2: &v63);
  if ( v63 == 0 || (v7 = (*(this + 36) & 0x40) == 0, v76 = 1, v7) )
    v76 = 0;
  v8 = a2->m_pAttributePtrs[0];
  v74 = nullptr;
  v71 = 0;
  if ( v8 >= a2->m_pAttributePtrs[1] )
    return 0;
  do
  {
    m_nRows = (char *)a2->m_nRows;
    v10 = *m_nRows;
    if ( (*m_nRows & 7) != 0 )
    {
      if ( (v10 & 1) != 0 || (v17 = v10 & 6) == 2 )
      {
        v19 = (unsigned __int8)m_nRows[1];
        v20 = (unsigned __int8)m_nRows[2];
        v69 = (unsigned __int8)m_nRows[3];
      }
      else if ( v17 == 4 )
      {
        v18 = (unsigned __int16 *)((unsigned int)(m_nRows + 2) & 0xFFFFFFFE);
        v19 = *v18;
        v20 = v18[1];
        v69 = v18[2];
      }
      else
      {
        v21 = (int *)((unsigned int)(m_nRows + 4) & 0xFFFFFFFC);
        v19 = *v21;
        v20 = v21[1];
        v69 = v21[2];
      }
      if ( v69 != 0 || (v19 == 0) != (v20 == 0) )
      {
        GFxPathData::EdgesIterator::EdgesIterator(this: (CSOAContainer *)&v52, pathIter: (int)a2);
        *(float *)&v67 = (double)v55 * v59;
        v66 = v59 * (double)v56;
        if ( v68 != nullptr )
          GFxScale9GridInfo::Transform(this: v68, x: (float *)&v67, a3: &v66);
        if ( v76 != 0 && v69 != 0 )
        {
          if ( v74 == nullptr )
          {
            v75 = 2;
            v22 = (GFxRenderGenStroker *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 196, a3: &v75);
            if ( v22 != nullptr )
              v72 = COERCE_FLOAT(GFxRenderGenStroker::GFxRenderGenStroker(this: v22));
            else
              v72 = 0.0;
            v74 = (GRefCountNTSImpl *)LODWORD(v72);
            GCompoundShape::SetCurveTolerance(this: (long double *)(LODWORD(v72) + 52), t: COERCE_CHAR_(20.0));
            GCompoundShape::SetCurveTolerance(
              this: (long double *)(LODWORD(v72) + 124),
              t: COERCE_CHAR_(*(float *)(LODWORD(v72) + 52)));
          }
          GCompoundShape::BeginPath(this: (char *)&v74[6].RefCount, lStyle: (localeinfo_struct *)0xFFFFFFFF);
        }
        if ( v53 < v54 )
        {
          v7 = v20 == 0;
          v23 = v68;
          LODWORD(v24) = v19 == 0;
          v64 = v24;
          v75 = v7;
          do
          {
            GFxPathData::EdgesIterator::GetEdge(
              this: (CSOAContainer *)&v52,
              pedge: (const CSOAContainer *)&v77,
              doLines2CurveConv: 0,
              ax: v49,
              ay: v50,
              a6: v51,
              a7: v52,
              a8: v53,
              a9: v54,
              a10: v55,
              a11: v56);
            if ( v23 != nullptr )
              GFxScale9GridInfo::Transform(this: v23, x: &v79, a3: &v80);
            dstShape = v67;
            v72 = v66;
            *(float *)&v70 = v79;
            v65 = v80;
            if ( v80 < (double)v66 )
            {
              *(float *)&dstShape = v79;
              v70 = v67;
              v72 = v80;
              v65 = v66;
            }
            if ( v81 != 0 )
            {
              if ( v23 != nullptr )
                GFxScale9GridInfo::Transform(this: v23, x: &v77, a3: &v78);
              if ( LODWORD(v24) != v75
                && GMath2D::CheckCurveIntersection(
                     this: (GMath2D *)dstShape,
                     a2: v72,
                     a3: v77,
                     a4: v78,
                     a5: *(float *)&v70,
                     a6: v65,
                     a7: *(float *)&x,
                     a8: *(float *)&y) )
              {
                v71 ^= 1u;
              }
            }
            else if ( LODWORD(v24) != v75 )
            {
              v25 = *(float *)&y;
              if ( v72 <= (double)*(float *)&y && v65 > v25 )
              {
                *(float *)&dstShape = (*(float *)&x - *(float *)&v70) * (v65 - v72)
                                    - (*(float *)&v70 - *(float *)&dstShape) * (v25 - v65);
                if ( *(float *)&dstShape > 0.0 )
                  v71 ^= 1u;
              }
            }
            if ( v76 != 0 && v69 != 0 )
            {
              if ( v81 != 0 )
              {
                GCompoundShape::AddCurve(this: (GCompoundShape *)&v74[6].RefCount, a2: v77, a3: v78, a4: v79, a5: v80);
              }
              else
              {
                v26 = v74;
                RefCount = v74[7].RefCount;
                v61 = v79;
                v28 = (GRefCountNTSImpl_vtbl *)(RefCount >> 8);
                v62 = v80;
                if ( v28 >= v74[8].__vftable )
                  GArrayPagedBase<GPointType,8,64,GAllocatorPagedLH_POD<GPointType,138>>::allocatePage(a1: v28);
                dtr_GRefCountImplCore = v26[9].__vftable[(_DWORD)v28].dtr_GRefCountImplCore;
                v23 = v68;
                v30 = (unsigned __int8)v26[7].RefCount;
                *((float *)dtr_GRefCountImplCore + 2 * v30) = v61;
                *((float *)dtr_GRefCountImplCore + 2 * v30 + 1) = v62;
                ++v26[7].RefCount;
                ++*(_DWORD *)(v74[11].RefCount + 4);
                v24 = v64;
              }
            }
            *(float *)&v67 = v79;
            v66 = v80;
          }
          while ( v53 < v54 );
        }
        v31 = v57;
        if ( v57 == 0 )
          v31 = v58;
        m_pDataMemory_low = LOWORD(a2->m_pDataMemory);
        m_nSlices = a2->m_nSlices;
        ++a2->m_pAttributePtrs[0];
        a2->m_nRows = v31;
        v34 = (int *)(m_nSlices - m_pDataMemory_low);
        if ( v31 - (int)v34 - 8 >= v34[1] )
        {
          v35 = *v34;
          if ( v35 != 0 )
          {
            a2->m_nRows = v35 + 8;
            a2->m_nSlices = v35 + 8;
            LOWORD(a2->m_pDataMemory) = 8;
          }
          else
          {
            a2->m_nRows = 0;
          }
        }
      }
      else
      {
        GFxPathData::PathsIterator::SkipComplex(this: a2);
      }
    }
    else
    {
      if ( v71 != 0 )
      {
        if ( v74 != nullptr )
          GRefCountNTSImpl::Release(this: v74);
        return 1;
      }
      v11 = a2->m_pAttributePtrs[0];
      if ( v11 >= a2->m_pAttributePtrs[1] )
        goto LABEL_11;
      v12 = LOWORD(a2->m_pDataMemory);
      a2->m_pAttributePtrs[0] = v11 + 1;
      v13 = a2->m_nSlices;
      v14 = m_nRows + 1;
      a2->m_nRows = (int)v14;
      v15 = (_DWORD *)(v13 - v12);
      if ( v14 - (_BYTE *)v15 - 8 < v15[1] )
        goto LABEL_11;
      v16 = *v15;
      if ( v16 != 0 )
      {
        a2->m_nRows = v16 + 8;
        a2->m_nSlices = v16 + 8;
        LOWORD(a2->m_pDataMemory) = 8;
LABEL_11:
        v71 = 0;
        continue;
      }
      a2->m_nRows = 0;
      v71 = 0;
    }
  }
  while ( a2->m_pAttributePtrs[0] < a2->m_pAttributePtrs[1] );
  if ( v71 != 0 )
  {
    if ( v74 != nullptr )
      GRefCountNTSImpl::Release(this: v74);
    return 1;
  }
  else
  {
    if ( v74 == nullptr )
      return 0;
    v37 = 0;
    if ( v74[9].RefCount == 0 )
    {
LABEL_96:
      GRefCountNTSImpl::Release(this: v74);
      return 0;
    }
    v38 = v74;
    v70 = (unsigned int)&v74[1];
    dstShape = (unsigned int)&v74[15].RefCount;
    while ( 1 )
    {
      v39 = (int)v38[11].__vftable[v37 >> 6].dtr_GRefCountImplCore + 24 * (v37 & 0x3F);
      v40 = v60 + 24 * *(_DWORD *)(v39 + 20);
      v75 = *(unsigned __int16 *)(v40 + 4);
      if ( (double)v75 >= 20.0 )
        v41 = (double)v75;
      else
        v41 = 20.0;
      v42 = v70;
      *(float *)&v75 = v41;
      v64 = *(float *)&v75 * 0.5;
      v43 = v64;
      *(float *)v70 = v64;
      if ( v43 < 0.0 )
        v43 = -v43;
      *(float *)&v75 = v43;
      *(float *)(v42 + 4) = *(float *)&v75;
      v44 = *(_WORD *)(v40 + 16) & 0x30;
      if ( v44 == 16 )
        v45 = 4;
      else
        v45 = v44 != 32 ? 3 : 0;
      v38[2].__vftable = (GRefCountNTSImpl_vtbl *)v45;
      if ( (*(_WORD *)(v40 + 16) & 0xC0) == 0x40 )
      {
        v46 = 0;
      }
      else if ( (*(_WORD *)(v40 + 16) & 0xC0) == 0x80 )
      {
        v46 = 1;
      }
      else
      {
        v46 = 2;
      }
      v38[2].RefCount = v46;
      if ( ((*(unsigned __int16 *)(v40 + 16) >> 2) & 0xC0) == 0x40 )
      {
        v47 = 0;
      }
      else if ( ((*(unsigned __int16 *)(v40 + 16) >> 2) & 0xC0) == 0x80 )
      {
        v47 = 1;
      }
      else
      {
        v47 = 2;
      }
      v38[3].__vftable = (GRefCountNTSImpl_vtbl *)v47;
      if ( (*(_BYTE *)(v40 + 16) & 0x30) == 0x20 )
        v38[3].RefCount = *(volatile int *)(v40 + 20);
      GCompoundShape::Clear(this: (GCompoundShape *)dstShape);
      GStroker::generateEquidistant(this: v70, srcPath: (long double *)v39, dstShape);
      GCompoundShape::PointInShape(this: dstShape, x, y);
      if ( v48 != 0 )
        break;
      if ( ++v37 >= v38[9].RefCount )
        goto LABEL_96;
    }
    GRefCountNTSImpl::Release(this: v38);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014D580
// Name: GFx_ReadFillStyles
// Source: json
//------------------------------------------------------------------------------
int __usercall GFx_ReadFillStyles@<eax>(GFxAmpMsgHandler *a1@<eax>, _DWORD *a2, int a3)
{
  GFxAmpMsgHandler *RefCount; // esi
  int v5; // eax
  volatile int v6; // eax
  GArrayLH<GString,2,GArrayDefaultPolicy> *v7; // ecx
  int v8; // edi
  _DWORD *v9; // eax
  int v10; // esi
  unsigned int v11; // esi
  unsigned int v12; // edi
  int v13; // edi
  CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),CFuncMemPolicyNone> *v14; // ecx
  int v15; // edi
  int v16; // esi
  GFxAmpMsgHandler *v17; // eax
  _cpinfo *v19; // [esp+0h] [ebp-18h]
  int v20; // [esp+Ch] [ebp-Ch]
  CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),CFuncMemPolicyNone> *i; // [esp+10h] [ebp-8h]
  int U16; // [esp+14h] [ebp-4h]

  RefCount = (GFxAmpMsgHandler *)a1[40].RefCount;
  if ( RefCount == nullptr )
    RefCount = a1 + 2;
  v5 = RefCount[2].RecvPort - RefCount[2].RefCount;
  BYTE1(RefCount[1].__vftable) = 0;
  if ( v5 < 1 )
    GFxStream::PopulateBuffer1(result: v19);
  v6 = RefCount[2].RefCount;
  v7 = (GArrayLH<GString,2,GArrayDefaultPolicy> *)RefCount[3].__vftable;
  LOBYTE(v7) = *((_BYTE *)&v7->Data.Data + v6);
  v8 = (unsigned __int8)v7;
  RefCount[2].RefCount = v6 + 1;
  U16 = (unsigned __int8)v7;
  if ( a3 > 2 && (unsigned __int8)v7 == 255 )
  {
    U16 = (unsigned __int16)GFxLoadProcess::ReadU16(this: a1, a2: (const GFxAmpMsgHandler *)v19);
    v8 = U16;
  }
  v9 = (_DWORD *)a1[40].RefCount;
  if ( v9 == nullptr )
    v9 = &a1[2].__vftable;
  v10 = v9[11] + v9[13] - v9[12];
  v20 = v10;
  if ( a2 != nullptr )
  {
    GFxLogBase<GFxLoadProcess>::LogParse(
      this: v7,
      pfmt: (unsigned int)&a1[1],
      a3: (int)"  GFx_ReadFillStyles: count = %d\n",
      a4: v8);
    v11 = a2[1];
    if ( v8 != 0 )
    {
      v12 = v11 + v8;
      GArrayDataBase<GFxFillStyle,GAllocatorGH<GFxFillStyle,259>,GArrayDefaultPolicy>::ResizeNoConstruct(
        a1: (int)a2,
        a2: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),CFuncMemPolicyNone> *)a1,
        a3: (int)a2,
        a4: v12);
      if ( v12 > v11 )
      {
        v13 = v12 - v11;
        v14 = (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),CFuncMemPolicyNone> *)(*a2 + 40 * v11);
        for ( i = v14; v13 != 0; i = v14 )
        {
          if ( v14 != nullptr )
          {
            GFxFillStyle::GFxFillStyle(
              this: v14,
              a2: (const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),CFuncMemPolicyNone> *)v19);
            v14 = i;
          }
          v14 = (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),CFuncMemPolicyNone> *)((char *)v14 + 40);
          --v13;
        }
      }
      v15 = U16;
      if ( U16 != 0 )
      {
        v16 = 40 * v11;
        do
        {
          v17 = (GFxAmpMsgHandler *)a1[40].RefCount;
          if ( v17 == nullptr )
            v17 = a1 + 2;
          BYTE1(v17[1].__vftable) = 0;
          GFxFillStyle::Read(this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),CFuncMemPolicyNone> *)(v16 + *a2));
          v16 += 40;
          --v15;
        }
        while ( v15 != 0 );
      }
    }
    return v20;
  }
  else
  {
    if ( v8 != 0 )
      GFxLogBase<GFxLoadProcess>::LogError(
        this: v7,
        pfmt: (unsigned int)&a1[1],
        a3: (int)"Error: GFx_ReadFillStyles, trying to read %d fillstyles into no-style shape\n",
        a4: v8);
    return v10;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014D6C0
// Name: protected: void GFxConstShapeNoStyles::Read(class GFxLoadProcess __near *,enum GFxTagType,unsigned int,bool,class GArray<class GFxFillStyle,259,struct GArrayDefaultPolicy> __near *,class GArray<class GFxLineStyle,259,struct GArrayDefaultPolicy> __near *,class GFxPathAllocator __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxConstShapeNoStyles::Read(
        CBitRead *this@<ecx>,
        _cpinfo *a2@<edi>,
        GFxAmpMsgHandler *p,
        int a4,
        unsigned int lenInBytes,
        bool withStyle,
        _DWORD *a7,
        GArrayLH<GString,2,GArrayDefaultPolicy> *a8,
        FloatCubeMap_t *a9)
{
  _DWORD *v9; // edx
  FloatCubeMap_t *v10; // eax
  GFxAmpMsgHandler *RefCount; // edi
  CBitRead *v12; // eax
  int v13; // ebx
  int v14; // eax
  int v15; // eax
  char v16; // bl
  int v17; // eax
  unsigned int v18; // eax
  unsigned __int8 v19; // bl
  unsigned __int8 *v20; // eax
  unsigned __int8 *v21; // esi
  int v22; // eax
  unsigned int Size; // eax
  struct GMemoryHeap *v24; // ebx
  tagMETAFILEPICT *MaterialPage; // eax
  int UInt; // eax
  int v27; // esi
  bool v28; // bl
  int v29; // eax
  const IShaderDeviceMgr *v30; // edi
  signed int v31; // ebx
  int v32; // edi
  int v33; // edi
  int v34; // eax
  int v35; // esi
  GFxAmpMsgHandler *v36; // ebx
  int FillStyles; // eax
  unsigned int v38; // esi
  int LineStyles; // eax
  unsigned int v40; // edi
  int v41; // ebx
  unsigned int v42; // ebx
  unsigned int v43; // esi
  const IShaderDeviceMgr *v44; // esi
  const IShaderDeviceMgr *SInt; // edi
  const IShaderDeviceMgr *v46; // ebx
  const IShaderDeviceMgr *v47; // esi
  double v48; // st7
  const IShaderDeviceMgr *v49; // esi
  const IShaderDeviceMgr *v50; // ebx
  const IShaderDeviceMgr *v51; // edi
  unsigned int v52; // ecx
  unsigned __int8 *v53; // eax
  unsigned int v54; // ecx
  CBitRead *v55; // ecx
  GFxAmpMsgHandler *v56; // edx
  unsigned int v57; // esi
  unsigned int v58; // eax
  _BYTE *v59; // edx
  unsigned int v60; // eax
  int v61; // ebx
  unsigned int v62; // edx
  unsigned __int8 *v63; // esi
  int v64; // edi
  int i; // eax
  unsigned int v66; // edx
  int v67; // edi
  int j; // eax
  int v69; // edx
  unsigned __int8 *v70; // eax
  unsigned int v71; // edi
  unsigned __int8 *v72; // eax
  int k; // esi
  unsigned int v74; // ebx
  GArrayLH<GString,2,GArrayDefaultPolicy> *v75; // eax
  signed int v76; // edi
  unsigned int v77; // ebx
  unsigned int v78; // edx
  GString *v79; // ecx
  GString *v80; // esi
  double v81; // st6
  double v82; // st6
  double v83; // st6
  double v84; // st6
  float *v85; // edx
  unsigned int v86; // edi
  double v87; // st6
  double v88; // [esp+20h] [ebp-2D8h]
  unsigned int v89; // [esp+2Ch] [ebp-2CCh]
  struct GFxParseControl *RecvPort; // [esp+2Ch] [ebp-2CCh]
  _cpinfo *v91; // [esp+30h] [ebp-2C8h]
  CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> rectBound; // [esp+3Ch] [ebp-2BCh] BYREF
  float v93; // [esp+48h] [ebp-2B0h]
  GFxAmpMsgHandler *v94; // [esp+4Ch] [ebp-2ACh]
  int lineBase; // [esp+50h] [ebp-2A8h]
  int numLineBits; // [esp+54h] [ebp-2A4h]
  int numFillBits; // [esp+58h] [ebp-2A0h]
  float sfactor; // [esp+5Ch] [ebp-29Ch]
  unsigned __int8 *ptr; // [esp+60h] [ebp-298h]
  int fillBase; // [esp+64h] [ebp-294h]
  FloatCubeMap_t *v101; // [esp+68h] [ebp-290h]
  unsigned int shapeLen; // [esp+6Ch] [ebp-28Ch]
  unsigned int memBlockSizeInBytes; // [esp+70h] [ebp-288h]
  unsigned int memBlockSize; // [esp+74h] [ebp-284h]
  unsigned __int8 *pmemBlock; // [esp+78h] [ebp-280h]
  GFxAmpMsgHandler *v106; // [esp+7Ch] [ebp-27Ch]
  _DWORD *v107; // [esp+80h] [ebp-278h]
  CBitRead *v108; // [esp+84h] [ebp-274h]
  unsigned int totalShapesCount; // [esp+88h] [ebp-270h]
  GArrayLH<GString,2,GArrayDefaultPolicy> *v110; // [esp+8Ch] [ebp-26Ch]
  int curEdgesCount; // [esp+90h] [ebp-268h]
  unsigned int newMemBlockSize; // [esp+94h] [ebp-264h]
  int moveX; // [esp+98h] [ebp-260h]
  int foff; // [esp+9Ch] [ebp-25Ch]
  int curPathsCount; // [esp+A0h] [ebp-258h]
  int moveY; // [esp+A4h] [ebp-254h]
  int HeapTypeBits_low; // [esp+A8h] [ebp-250h]
  float maxStrokeExtent; // [esp+ACh] [ebp-24Ch]
  IShaderDeviceMgr v119; // [esp+B0h] [ebp-248h] BYREF
  char v120; // [esp+C5h] [ebp-233h]
  int v121; // [esp+DCh] [ebp-21Ch]
  int v122; // [esp+E0h] [ebp-218h]
  int v123; // [esp+E4h] [ebp-214h]

  v9 = a7;
  v110 = a8;
  v10 = a9;
  v108 = this;
  v106 = p;
  v107 = a7;
  if ( a9 == nullptr )
    v10 = *(FloatCubeMap_t **)(p[1].RecvAddress + 24);
  v91 = a2;
  RefCount = (GFxAmpMsgHandler *)p[40].RefCount;
  v101 = v10;
  if ( RefCount == nullptr )
    RefCount = p + 2;
  v94 = RefCount;
  if ( withStyle )
  {
    v12 = v108;
    v13 = RefCount[2].RefCount + RefCount[2].RecvAddress - RefCount[2].RecvPort;
    LOBYTE(v108[1].m_pDebugName) |= 0x10u;
    GFxStream::ReadRect(this: (GFxStream *)RefCount, a2: (int)&v12->m_bOverflow);
    if ( a4 == 83 || a4 == 75 )
    {
      *(float *)&rectBound.m_pMemory = 0.0;
      *(float *)&rectBound.m_nAllocationCount = 0.0;
      *(float *)&rectBound.m_nGrowSize = 0.0;
      v93 = 0.0;
      GFxStream::ReadRect(this: (GFxStream *)RefCount, a2: (int)&rectBound);
      (*((void (__thiscall **)(CBitRead *, CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *))v108->m_pDebugName
       + 2))(
        a1: v108,
        a2: &rectBound);
      v14 = RefCount[2].RecvPort - RefCount[2].RefCount;
      BYTE1(RefCount[1].__vftable) = 0;
      if ( v14 < 1 )
        GFxStream::PopulateBuffer1(result: v91);
      ++RefCount[2].RefCount;
    }
    else
    {
      (*((void (__thiscall **)(CBitRead *, bool *))v108->m_pDebugName + 2))(a1: v108, a2: &v108->m_bOverflow);
    }
    GFx_ReadFillStyles(a1: v106, a2: v107, a3: a4);
    GFx_ReadLineStyles(a1: v110, p: (unsigned int)v106);
    v9 = v107;
    v15 = RefCount[2].RefCount + RefCount[2].RecvAddress - v13 - RefCount[2].RecvPort;
  }
  else
  {
    v15 = 0;
  }
  v16 = a4 <= 2 ? 0 : 4;
  shapeLen = lenInBytes - v15;
  newMemBlockSize = lenInBytes - v15;
  v17 = lenInBytes - v15 + 1;
  if ( withStyle )
  {
    if ( v9 != nullptr && v9[1] != 0 )
    {
      v16 |= 1u;
      v17 += 2;
    }
    if ( v110 != nullptr && v110->Data.Size != 0 )
    {
      v16 |= 2u;
      v17 += 2;
    }
  }
  v18 = v17 + 8;
  memBlockSize = v18;
  if ( v18 >= 0x100 )
  {
    if ( v18 >= 0x10000 )
      memBlockSizeInBytes = 4 - (v18 < 0x1000000);
    else
      memBlockSizeInBytes = 2;
  }
  else
  {
    memBlockSizeInBytes = 1;
  }
  v19 = (8 * ((memBlockSizeInBytes - 1) & 3)) | v16;
  memBlockSize += memBlockSizeInBytes;
  GFxPathAllocator::AllocMemoryBlock(this: v101, sizeForCurrentPage: memBlockSize, size: memBlockSize);
  v21 = &v20[memBlockSizeInBytes + 1];
  pmemBlock = v20;
  *v20 = v19;
  ptr = v21;
  if ( (v19 & 1) != 0 )
  {
    v22 = v107[1];
    *v21 = v22;
    v21[1] = BYTE1(v22) & 0x7F;
    v21 += 2;
    ptr = v21;
  }
  if ( (v19 & 2) != 0 )
  {
    Size = v110->Data.Size;
    *v21 = Size;
    v21[1] = BYTE1(Size) & 0x7F;
    v21 += 2;
    ptr = v21;
  }
  v89 = shapeLen;
  BYTE1(RefCount[1].__vftable) = 0;
  GFxStream::ReadToBuffer(this: (GFxStream *)RefCount, pdestBuf: v21, a3: v89);
  sfactor = 1.0;
  if ( a4 == 75 )
  {
    LOBYTE(v108[1].m_pDebugName) |= 2u;
    sfactor = 0.050000001;
  }
  v24 = *(struct GMemoryHeap **)(v106[1].RecvAddress + 28);
  RecvPort = (struct GFxParseControl *)RefCount->RecvPort;
  MaterialPage = CMaterialSubRect::GetMaterialPage(this: RefCount);
  GFxStream::GFxStream(
    this: (GFxStream *)&v119,
    a2: v21,
    bufSize: shapeLen,
    a4: v24,
    a5: (struct GFxLog *)MaterialPage,
    a6: RecvPort);
  v106[40].RefCount = (volatile int)&v119;
  v120 = 0;
  numFillBits = GFxStream::ReadUInt(this: (GFxStream *)&v119, a2: 4u);
  UInt = GFxStream::ReadUInt(this: (GFxStream *)&v119, a2: 4u);
  numLineBits = UInt;
  if ( withStyle )
    GFxLogBase<GFxStream>::LogParse(
      this: (tagBITMAPINFOHEADER *)&v119,
      a2: (int)"  ShapeCharacter read: nfillbits = %d, nlinebits = %d\n",
      numFillBits,
      UInt);
  v27 = 0;
  fillBase = 0;
  lineBase = 0;
  moveX = 0;
  *(float *)&moveY = 0.0;
  maxStrokeExtent = 0.0;
  totalShapesCount = 0;
  curEdgesCount = 0;
  curPathsCount = 0;
  v28 = false;
  while ( 1 )
  {
    if ( GFxStream::ReadUInt1(this: &v119) != 0 )
    {
      curEdgesCount = v27 + 1;
      if ( GFxStream::ReadUInt1(this: &v119) == 0 )
      {
        v44 = (const IShaderDeviceMgr *)(GFxStream::ReadUInt(this: (GFxStream *)&v119, a2: 4u) + 2);
        SInt = GFxStream::ReadSInt(result: v44);
        v46 = GFxStream::ReadSInt(result: v44);
        foff = (int)GFxStream::ReadSInt(result: v44);
        v47 = GFxStream::ReadSInt(result: v44);
        if ( GFxStream::IsVerboseParseShape(this: (GFxStream *)&v119) )
        {
          HeapTypeBits_low = (int)v46 + (_DWORD)v47 + moveY;
          v48 = (double)HeapTypeBits_low * sfactor;
          HeapTypeBits_low = (int)SInt + foff + moveX;
          v88 = (double)HeapTypeBits_low * sfactor;
          HeapTypeBits_low = (int)SInt + moveX;
          GFxLogBase<GFxStream>::LogParseShape(
            this: (tagBITMAPINFOHEADER *)&v119,
            a2: (int)"  ShapeCharacter read: curved edge   = %4g %4g - %4g %4g - %4g %4g\n",
            sfactor * (double)moveX,
            (double)moveY * sfactor,
            (double)((int)SInt + moveX) * sfactor,
            (double)((int)v46 + moveY) * sfactor,
            v88,
            v48);
        }
        moveX += (int)SInt + foff;
        moveY += (int)v47 + (_DWORD)v46;
        goto LABEL_97;
      }
      v49 = (const IShaderDeviceMgr *)(GFxStream::ReadUInt(this: (GFxStream *)&v119, a2: 4u) + 2);
      v50 = nullptr;
      v51 = nullptr;
      if ( GFxStream::ReadUInt1(this: &v119) != 0 )
      {
        v50 = GFxStream::ReadSInt(result: v49);
      }
      else if ( GFxStream::ReadUInt1(this: &v119) == 0 )
      {
        v50 = GFxStream::ReadSInt(result: v49);
        goto LABEL_94;
      }
      v51 = GFxStream::ReadSInt(result: v49);
LABEL_94:
      if ( GFxStream::IsVerboseParseShape(this: (GFxStream *)&v119) )
      {
        HeapTypeBits_low = (int)v50 + moveX;
        GFxLogBase<GFxStream>::LogParseShape(
          this: (tagBITMAPINFOHEADER *)&v119,
          a2: (int)"  ShapeCharacter read: straight edge = %4g %4g - %4g %4g\n",
          sfactor * (double)moveX,
          (double)moveY * sfactor,
          (double)((int)v50 + moveX) * sfactor,
          (double)((int)v51 + moveY) * sfactor);
      }
      moveX += (int)v50;
      moveY += (int)v51;
      goto LABEL_97;
    }
    v29 = GFxStream::ReadUInt(this: (GFxStream *)&v119, a2: 5u);
    foff = v29;
    if ( v29 == 0 )
      break;
    if ( (v29 & 1) != 0 )
    {
      if ( v27 > 0 )
      {
        ++LODWORD(maxStrokeExtent);
        v27 = 0;
        ++curPathsCount;
        curEdgesCount = 0;
      }
      v30 = (const IShaderDeviceMgr *)GFxStream::ReadUInt(this: (GFxStream *)&v119, a2: 5u);
      moveX = (int)GFxStream::ReadSInt(result: v30);
      *(float *)&moveY = COERCE_FLOAT(GFxStream::ReadSInt(result: v30));
      if ( GFxStream::IsVerboseParseShape(this: (GFxStream *)&v119) )
        GFxLogBase<GFxStream>::LogParseShape(
          this: (tagBITMAPINFOHEADER *)&v119,
          a2: (int)"  ShapeCharacter read: moveto %4g %4g\n",
          sfactor * (double)moveX,
          (double)moveY * sfactor);
    }
    v31 = numFillBits;
    if ( (foff & 2) != 0 && numFillBits > 0 )
    {
      if ( v27 > 0 )
      {
        ++LODWORD(maxStrokeExtent);
        v27 = 0;
        ++curPathsCount;
        curEdgesCount = 0;
      }
      v32 = GFxStream::ReadUInt(this: (GFxStream *)&v119, a2: numFillBits);
      if ( GFxStream::IsVerboseParseShape(this: (GFxStream *)&v119) )
      {
        if ( v32 > 0 )
          v32 += fillBase;
        GFxLogBase<GFxStream>::LogParseShape(
          this: (tagBITMAPINFOHEADER *)&v119,
          a2: (int)"  ShapeCharacter read: fill0 = %d\n",
          v32);
      }
    }
    if ( (foff & 4) != 0 && v31 > 0 )
    {
      if ( v27 > 0 )
      {
        ++LODWORD(maxStrokeExtent);
        v27 = 0;
        ++curPathsCount;
        curEdgesCount = 0;
      }
      v33 = GFxStream::ReadUInt(this: (GFxStream *)&v119, a2: v31);
      if ( GFxStream::IsVerboseParseShape(this: (GFxStream *)&v119) )
      {
        if ( v33 > 0 )
          v33 += fillBase;
        GFxLogBase<GFxStream>::LogParseShape(
          this: (tagBITMAPINFOHEADER *)&v119,
          a2: (int)"  ShapeCharacter read: fill1 = %d\n",
          v33);
      }
    }
    if ( (foff & 8) != 0 && numLineBits > 0 )
    {
      if ( v27 > 0 )
      {
        ++LODWORD(maxStrokeExtent);
        ++curPathsCount;
        curEdgesCount = 0;
      }
      v34 = GFxStream::ReadUInt(this: (GFxStream *)&v119, a2: numLineBits);
      v35 = v34;
      if ( v34 > 0 )
        v35 = lineBase + v34;
      if ( GFxStream::IsVerboseParseShape(this: (GFxStream *)&v119) )
        GFxLogBase<GFxStream>::LogParseShape(
          this: (tagBITMAPINFOHEADER *)&v119,
          a2: (int)"  ShapeCharacter read: line = %d\n",
          v35);
    }
    if ( (foff & 0x10) != 0 )
    {
      GFxLogBase<GFxStream>::LogParse(
        this: (tagBITMAPINFOHEADER *)&v119,
        a2: (int)"  ShapeCharacter read: more fill styles\n");
      if ( curPathsCount > 0 )
      {
        ++totalShapesCount;
        curPathsCount = 0;
      }
      if ( curEdgesCount > 0 )
      {
        ++LODWORD(maxStrokeExtent);
        ++curPathsCount;
        curEdgesCount = 0;
      }
      if ( v107 != nullptr )
        fillBase = v107[1];
      else
        fillBase = 0;
      if ( v110 != nullptr )
        lineBase = v110->Data.Size;
      else
        lineBase = 0;
      v36 = v106;
      FillStyles = GFx_ReadFillStyles(a1: v106, a2: v107, a3: a4);
      v38 = v123 + v121 - v122;
      foff = FillStyles;
      LineStyles = GFx_ReadLineStyles(a1: v110, p: (unsigned int)v36);
      v40 = v123 + v121 - v122;
      v41 = LineStyles;
      if ( foff != v38 )
      {
        if ( foff > (int)v38 || v38 > newMemBlockSize )
          goto LABEL_98;
        v42 = LineStyles - v38;
        memmove(dst: &ptr[foff], src: &ptr[v38], count: LineStyles - v38);
        v41 = foff + v42;
      }
      if ( v41 != v40 )
      {
        if ( v41 > (int)v40 || v40 > newMemBlockSize )
          goto LABEL_98;
        v43 = shapeLen;
        memmove(dst: &ptr[v41], src: &ptr[v40], count: shapeLen - v40);
        shapeLen = v41 - v40 + v43;
      }
      GFxStream::SetPosition(this: &v119, pos: v41, a3: (int)v91);
      numFillBits = GFxStream::ReadUInt(this: (GFxStream *)&v119, a2: 4u);
      numLineBits = GFxStream::ReadUInt(this: (GFxStream *)&v119, a2: 4u);
    }
LABEL_97:
    v52 = v123 + v121 - v122;
    v28 = v52 > newMemBlockSize;
    if ( v52 > newMemBlockSize )
      goto LABEL_98;
    v27 = curEdgesCount;
  }
  if ( v27 > 0 )
  {
    ++LODWORD(maxStrokeExtent);
    ++curPathsCount;
  }
  if ( v28 )
  {
LABEL_98:
    GFxLogBase<GFxStream>::LogWarning(
      this: (tagBITMAPINFOHEADER *)&v119,
      a2: (int)"Error: Corrupted shape detected in file %s\n",
      (const char *)((v94[1].RefCount & 0xFFFFFFFC) + 8));
    v53 = pmemBlock;
    v54 = memBlockSize;
    *(_WORD *)pmemBlock = 0;
    *((_WORD *)v53 + 1) = 0;
    *((_WORD *)v53 + 2) = 0;
    if ( v54 > 6 )
      GFxPathAllocator::ReallocLastBlock(this: v101, ptr: v53, oldSize: v54, newSize: 6u);
    goto LABEL_100;
  }
  if ( curPathsCount > 0 )
    ++totalShapesCount;
  v60 = totalShapesCount;
  if ( LODWORD(maxStrokeExtent) >= totalShapesCount )
    v60 = LODWORD(maxStrokeExtent);
  if ( v60 >= 0x100 )
  {
    if ( v60 >= 0x10000 )
      v61 = 4 - (v60 < 0x1000000);
    else
      v61 = 2;
  }
  else
  {
    v61 = 1;
  }
  v62 = shapeLen + memBlockSize - newMemBlockSize + 2 * v61 - 8;
  v63 = &pmemBlock[v62 - 2 * v61];
  v64 = 0;
  newMemBlockSize = v62;
  if ( v61 != 0 )
  {
    for ( i = v61; i != 0; --i )
    {
      v66 = totalShapesCount >> v64;
      ++v63;
      v64 += 8;
      *(v63 - 1) = v66;
    }
    v62 = newMemBlockSize;
  }
  v67 = 0;
  if ( v61 != 0 )
  {
    for ( j = v61; j != 0; --j )
    {
      v69 = LODWORD(maxStrokeExtent) >> v67;
      ++v63;
      v67 += 8;
      *(v63 - 1) = v69;
    }
    v62 = newMemBlockSize;
  }
  if ( memBlockSize > v62 )
  {
    GFxPathAllocator::ReallocLastBlock(this: v101, ptr: pmemBlock, oldSize: memBlockSize, newSize: newMemBlockSize);
    v62 = newMemBlockSize;
  }
  v70 = pmemBlock;
  v71 = memBlockSizeInBytes;
  *pmemBlock |= 32 * ((v61 - 1) & 3);
  v72 = v70 + 1;
  for ( k = 0; v71 != 0; *(v72 - 1) = v74 )
  {
    v74 = v62 >> k;
    ++v72;
    k += 8;
    --v71;
  }
LABEL_100:
  v55 = v108;
  v56 = v106;
  *(_DWORD *)&v108[1].m_bOverflow = pmemBlock;
  v56[40].RefCount = 0;
  LOBYTE(v55[1].m_pDebugName) &= ~1u;
  if ( v107 != nullptr )
  {
    v57 = v107[1];
    v58 = 0;
    if ( v57 != 0 )
    {
      v59 = (_BYTE *)*v107;
      while ( *v59 == 0 )
      {
        ++v58;
        v59 += 40;
        if ( v58 >= v57 )
          goto LABEL_134;
      }
      LOBYTE(v55[1].m_pDebugName) |= 1u;
    }
  }
LABEL_134:
  if ( ((int)v55[1].m_pDebugName & 0x40) != 0 )
  {
    v75 = v110;
    maxStrokeExtent = 1.0;
    if ( v110 != nullptr )
    {
      v76 = v110->Data.Size;
      v77 = 0;
      if ( v76 >= 4 )
      {
        v78 = ((unsigned int)(v76 - 4) >> 2) + 1;
        v79 = v110->Data.Data + 1;
        v80 = v110->Data.Data + 7;
        v77 = 4 * v78;
        do
        {
          v81 = *(float *)&v79[4].pData * 0.1000000014901161;
          HeapTypeBits_low = LOWORD(v79->HeapTypeBits);
          *(float *)&moveY = v81 * (double)HeapTypeBits_low;
          if ( maxStrokeExtent <= (double)*(float *)&moveY )
            maxStrokeExtent = *(float *)&moveY;
          v82 = *(float *)&v80[4].pData * 0.1000000014901161;
          HeapTypeBits_low = LOWORD(v80->HeapTypeBits);
          *(float *)&moveY = v82 * (double)HeapTypeBits_low;
          if ( maxStrokeExtent <= (double)*(float *)&moveY )
            maxStrokeExtent = *(float *)&moveY;
          v83 = *(float *)&v80[10].pData * 0.1000000014901161;
          HeapTypeBits_low = LOWORD(v80[6].HeapTypeBits);
          *(float *)&moveY = v83 * (double)HeapTypeBits_low;
          if ( maxStrokeExtent <= (double)*(float *)&moveY )
            maxStrokeExtent = *(float *)&moveY;
          v84 = *(float *)&v80[16].pData * 0.1000000014901161;
          HeapTypeBits_low = LOWORD(v80[12].HeapTypeBits);
          *(float *)&moveY = v84 * (double)HeapTypeBits_low;
          if ( maxStrokeExtent <= (double)*(float *)&moveY )
            maxStrokeExtent = *(float *)&moveY;
          v79 += 24;
          v80 += 24;
          --v78;
        }
        while ( v78 != 0 );
        v55 = v108;
        v75 = v110;
      }
      if ( v77 < v76 )
      {
        v85 = (float *)&v75->Data.Data[6 * v77 + 1];
        v86 = v76 - v77;
        do
        {
          v87 = v85[4] * 0.1000000014901161;
          HeapTypeBits_low = *(unsigned __int16 *)v85;
          *(float *)&moveY = v87 * (double)HeapTypeBits_low;
          if ( maxStrokeExtent <= (double)*(float *)&moveY )
            maxStrokeExtent = *(float *)&moveY;
          v85 += 6;
          --v86;
        }
        while ( v86 != 0 );
      }
    }
    (*((void (__stdcall **)(float))v55->m_pDebugName + 13))(a1: COERCE_FLOAT(LODWORD(maxStrokeExtent)));
  }
  GFxStream::~GFxStream(this: (GFxStream *)&v119);
}

//------------------------------------------------------------------------------
// Address: 0x1014E3A0
// Name: public: GFxConstShapeWithStyles::GFxConstShapeWithStyles(void)
// Source: json
//------------------------------------------------------------------------------
GFxConstShapeWithStyles *__thiscall GFxConstShapeWithStyles::GFxConstShapeWithStyles(GFxConstShapeWithStyles *this)
{
  *(_DWORD *)this = &GFxShapeBase::`vftable';
  *((float *)this + 1) = 0.0;
  *((float *)this + 2) = 0.0;
  *((float *)this + 3) = 0.0;
  *((float *)this + 4) = 0.0;
  InterlockedExchange(Target: (volatile LONG *)this + 5, Value: 1);
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 8) = 0;
  *((float *)this + 1) = 0.0;
  *((float *)this + 2) = 0.0;
  *((float *)this + 3) = 0.0;
  *((float *)this + 4) = 0.0;
  *((_WORD *)this + 18) = 0;
  *((_DWORD *)this + 10) = 0;
  *(_DWORD *)this = &GFxConstShapeWithStyles::`vftable';
  *((float *)this + 16) = 0.0;
  *((float *)this + 17) = 0.0;
  *((float *)this + 18) = 0.0;
  *((float *)this + 19) = 0.0;
  *((_BYTE *)this + 36) |= 0xC0u;
  *((_DWORD *)this + 11) = 0;
  *((float *)this + 15) = 100.0;
  *((_DWORD *)this + 12) = 0;
  *((_DWORD *)this + 14) = 0;
  *((_DWORD *)this + 13) = 0;
  *((float *)this + 16) = 0.0;
  *((float *)this + 17) = 0.0;
  *((float *)this + 18) = 0.0;
  *((float *)this + 19) = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1014E420
// Name: public: void GFxConstShapeWithStyles::Read(class GFxLoadProcess __near *,enum GFxTagType,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxConstShapeWithStyles::Read(
        CBitRead *this,
        GFxAmpMsgHandler *p,
        int a3,
        unsigned int lenInBytes,
        unsigned int i)
{
  int v6; // eax
  int v7; // ebx
  int (__thiscall *v8)(int, int, unsigned int *); // edx
  int v9; // eax
  int v10; // ecx
  GFxFillStyle *v11; // edi
  unsigned int Size; // edi
  int (__thiscall *v13)(int, unsigned int, unsigned int *); // edx
  int v14; // eax
  bool v15; // zf
  CMemberFuncProxyBase<CLateBoundPtr<IMesh>,void (__thiscall IMesh::*)(IMesh *,int),CFuncMemPolicyNone> *v16; // ebx
  GString *j; // esi
  int v18; // ebx
  int v19; // esi
  int k; // edi
  CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),CFuncMemPolicyNone> *v22; // [esp+0h] [ebp-24h]
  int v23; // [esp+Ch] [ebp-18h] BYREF
  int v24; // [esp+10h] [ebp-14h]
  int v25; // [esp+14h] [ebp-10h]
  GArrayLH<GString,2,GArrayDefaultPolicy> v26; // [esp+18h] [ebp-Ch] BYREF
  int v27; // [esp+30h] [ebp+Ch]

  v23 = 0;
  v24 = 0;
  v25 = 0;
  memset(&v26, 0, sizeof(v26));
  GFxConstShapeNoStyles::Read(this, a2: nullptr, p, a4: a3, lenInBytes, withStyle: i, a7: &v23, a8: &v26, a9: nullptr);
  v6 = v24;
  v7 = *(_DWORD *)(p[1].RecvAddress + 28);
  if ( v24 != 0 )
  {
    *((_DWORD *)this + 13) = v24;
    v8 = *(int (__thiscall **)(int, int, unsigned int *))(*(_DWORD *)v7 + 40);
    lenInBytes = 259;
    v9 = v8(a1: v7, a2: 40 * v6, a3: &lenInBytes);
    *((_DWORD *)this + 11) = v9;
    i = 0;
    if ( *((_DWORD *)this + 13) != 0 )
    {
      v10 = v23 - v9;
      v11 = (GFxFillStyle *)v9;
      v27 = v23 - v9;
      do
      {
        if ( v11 != nullptr )
        {
          GFxFillStyle::GFxFillStyle(this: v11, a2: (const struct GFxFillStyle *)((char *)v11 + v10));
          v10 = v27;
        }
        v11 = (GFxFillStyle *)((char *)v11 + 40);
        ++i;
      }
      while ( i < *((_DWORD *)this + 13) );
    }
  }
  Size = v26.Data.Size;
  if ( v26.Data.Size != 0 )
  {
    *((_DWORD *)this + 14) = v26.Data.Size;
    v13 = *(int (__thiscall **)(int, unsigned int, unsigned int *))(*(_DWORD *)v7 + 40);
    lenInBytes = 259;
    v14 = v13(a1: v7, a2: 24 * Size, a3: &lenInBytes);
    v15 = *((_DWORD *)this + 14) == 0;
    *((_DWORD *)this + 12) = v14;
    i = 0;
    if ( !v15 )
    {
      v16 = (CMemberFuncProxyBase<CLateBoundPtr<IMesh>,void (__thiscall IMesh::*)(IMesh *,int),CFuncMemPolicyNone> *)v14;
      do
      {
        if ( v16 != nullptr )
          GFxLineStyle::GFxLineStyle(this: v16);
        ++v16;
        ++i;
      }
      while ( i < *((_DWORD *)this + 14) );
    }
  }
  for ( j = &v26.Data.Data[6 * Size - 6]; Size != 0; --Size )
  {
    ((void (__thiscall *)(GString *, _DWORD))j->pData->Size)(a1: j, a2: 0);
    j -= 6;
  }
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v26.Data.Data);
  v18 = v23;
  v19 = v23 + 40 * v24 - 40;
  if ( v24 != 0 )
  {
    for ( k = v24; k != 0; --k )
    {
      GFxFillStyle::~GFxFillStyle(result: v22);
      v19 -= 40;
    }
  }
  return ((int (__thiscall *)(GMemoryHeap *, int))GMemory::pGlobalHeap->Free)(a1: GMemory::pGlobalHeap, a2: v18);
}

//------------------------------------------------------------------------------
// Address: 0x1014E590
// Name: public: GFxShapeWithStyles::GFxShapeWithStyles(unsigned int)
// Source: json
//------------------------------------------------------------------------------
IClientUnknown *__thiscall GFxShapeWithStyles::GFxShapeWithStyles(int this, IClientUnknown *result)
{
  GFxShapeNoStyles::GFxShapeNoStyles((GFxShapeNoStyles *)this, pageSize: (__int16)result);
  *(_DWORD *)this = &GFxShapeWithStyles::`vftable';
  *(_DWORD *)(this + 76) = 536346624;
  *(_DWORD *)(this + 68) = 0;
  *(_DWORD *)(this + 72) = 0;
  *(_DWORD *)(this + 80) = 0;
  *(_DWORD *)(this + 84) = 0;
  *(_DWORD *)(this + 88) = 0;
  *(_DWORD *)(this + 92) = 0;
  *(_DWORD *)(this + 96) = 0;
  *(_DWORD *)(this + 100) = 0;
  *(float *)(this + 108) = 0.0;
  *(float *)(this + 112) = 0.0;
  *(float *)(this + 116) = 0.0;
  *(float *)(this + 120) = 0.0;
  *(_BYTE *)(this + 36) |= 0xC0u;
  *(float *)(this + 104) = 100.0;
  *(float *)(this + 108) = 0.0;
  *(float *)(this + 112) = 0.0;
  *(float *)(this + 116) = 0.0;
  *(float *)(this + 120) = 0.0;
  return (IClientUnknown *)this;
}

//------------------------------------------------------------------------------
// Address: 0x1014E630
// Name: public: void GFxShapeWithStyles::SetToImage(class GFxImageResource __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxShapeWithStyles::SetToImage(GFxShapeWithStyles *this, struct GFxImageResource *bilinear, bool a3)
{
  int v4; // ecx
  int v5; // edi
  int v6; // ebx
  int v7; // edx
  CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),CFuncMemPolicyNone> *v8; // ecx
  bool v9; // zf
  CStridedConstPtr<__m128> *v10; // ecx
  const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),CFuncMemPolicyNone> *v11; // [esp+0h] [ebp-8Ch]
  int v12; // [esp+Ch] [ebp-80h] BYREF
  int v13; // [esp+10h] [ebp-7Ch]
  int v14; // [esp+14h] [ebp-78h]
  int v15; // [esp+18h] [ebp-74h]
  CStridedConstPtr<__m128> v16; // [esp+1Ch] [ebp-70h] BYREF
  int v17; // [esp+24h] [ebp-68h]
  int v18; // [esp+28h] [ebp-64h]
  int v19; // [esp+2Ch] [ebp-60h]
  int v20; // [esp+30h] [ebp-5Ch]
  int v21; // [esp+34h] [ebp-58h]
  void *v22; // [esp+38h] [ebp-54h]
  int v23; // [esp+3Ch] [ebp-50h]
  int v24; // [esp+40h] [ebp-4Ch]
  int v25; // [esp+44h] [ebp-48h]
  int v26; // [esp+48h] [ebp-44h]
  int v27; // [esp+4Ch] [ebp-40h]
  __int16 v28; // [esp+50h] [ebp-3Ch]
  float width; // [esp+54h] [ebp-38h]
  struct GFxImageResource *v30; // [esp+58h] [ebp-34h]
  int v31; // [esp+5Ch] [ebp-30h]
  CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),CFuncMemPolicyNone> *v32; // [esp+60h] [ebp-2Ch]
  int v33; // [esp+64h] [ebp-28h]
  float height; // [esp+68h] [ebp-24h]
  int v35; // [esp+6Ch] [ebp-20h]

  v4 = *((_DWORD *)bilinear + 3);
  v30 = bilinear;
  (*(void (__thiscall **)(int, int *))(*(_DWORD *)v4 + 28))(a1: v4, a2: &v12);
  v5 = v14 - v12;
  v6 = v15 - v13;
  v7 = *((_DWORD *)this + 21);
  v33 = 20 * (v14 - v12);
  v31 = 20 * (v15 - v13);
  width = (float)v33;
  height = (float)v31;
  v35 = v7;
  GArrayDataBase<GFxFillStyle,GAllocatorLH<GFxFillStyle,259>,GArrayDefaultPolicy>::ResizeNoConstruct(
    this: (GAtomicOpsRawBase::AcquireSync *)this + 80,
    a2: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),CFuncMemPolicyNone> *)(v15 - v13),
    pheapAddr: (char *)this + 80,
    newSize: 1u);
  if ( v35 == 0 )
  {
    v8 = *((CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),CFuncMemPolicyNone> **)this
         + 20);
    v32 = v8;
    v35 = 1;
    do
    {
      if ( v8 != nullptr )
      {
        GFxFillStyle::GFxFillStyle(this: v8, a2: v11);
        v8 = v32;
      }
      v8 = (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),CFuncMemPolicyNone> *)((char *)v8 + 40);
      v9 = v35-- == 1;
      v32 = v8;
    }
    while ( !v9 );
  }
  GMatrix2D::SetIdentity(result: (const CMaterialDict::MissingMaterial_t *)v11);
  GFxFillStyle::SetImageFill(result: (CMemberFuncProxy3<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,CPrimList *,int),IMesh *,CPrimList *,int,CFuncMemPolicyNone> *)(2 * !a3 + 65));
  *((_BYTE *)this + 36) |= 1u;
  *(float *)&this->m_SpaceUsed = 0.0;
  *(float *)this->m_Data = 0.0;
  *((float *)this + 3) = width;
  *((float *)this + 4) = height;
  (*(void (__thiscall **)(GFxShapeWithStyles *, int *))(this->m_TotalLen + 8))(a1: this, a2: &this->m_SpaceUsed);
  *((_BYTE *)this + 36) |= 0x10u;
  *((float *)this + 26) = 0.0;
  LODWORD(height) = (char *)this + 68;
  if ( *((_DWORD *)this + 17) == 0 )
    *((_WORD *)this + 39) = 32;
  *((_BYTE *)this + 36) |= 4u;
  v22 = nullptr;
  v23 = 0;
  v24 = 0;
  v21 = 0;
  v20 = 0;
  v19 = 0;
  v18 = 0;
  v25 = 0;
  v26 = 0;
  v27 = 0;
  v28 = 0;
  v16.m_pData = nullptr;
  v16.m_nStride = 1;
  v17 = 0;
  GFxPathPacker::SetMoveTo(this: &v16, x: 0, y: 0, numBits: 0);
  GFxPathPacker::AddLineTo(this: v10, x: v33, y: 0, numBits: 0);
  GFxPathPacker::AddLineTo(this: &v16, x: 0, y: v31, numBits: 0);
  GFxPathPacker::AddLineTo(this: &v16, x: -20 * v5, y: 0, numBits: 0);
  GFxPathPacker::AddLineTo(this: &v16, x: 0, y: -20 * v6, numBits: 0);
  GFxPathPacker::Pack(
    this: &v16,
    a2: (FloatCubeMap_t *)LODWORD(height),
    ppathsInfo: (CStridedConstPtr<__m128> *)((char *)this + 52));
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v22);
}

//------------------------------------------------------------------------------
// Address: 0x1014E810
// Name: public: void GFxShapeCharacterDef::SetToImage(class GFxImageResource __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxShapeCharacterDef::SetToImage(old_bf_read *this, struct GFxImageResource *pimage, bool a3)
{
  GFxShapeWithStyles::SetToImage(this: (GFxShapeWithStyles *)&this->m_bOverflow, bilinear: pimage, a3);
}

//------------------------------------------------------------------------------
// Address: 0x1014E820
// Name: protected: bool GFxShapeBase::DefPointTestLocalImpl<class GFxSwfPathData>(class GPoint<float> const __near &,bool,class GFxCharacter const __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxShapeBase::DefPointTestLocalImpl<GFxSwfPathData>(
        int this,
        float *testShape,
        char a3,
        GFxCharacter *pinst)
{
  GFxScale9GridInfo *v6; // esi
  CMemberFuncProxy1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(Vector),Vector,CFuncMemPolicyNone> *v7; // eax
  bool v8; // zf
  int v9; // eax
  unsigned int v11; // [esp+10h] [ebp-ACh]
  GFxSwfPathData::PathsIterator it[29]; // [esp+1Ch] [ebp-A0h] BYREF
  int v13[4]; // [esp+90h] [ebp-2Ch] BYREF
  int v14; // [esp+A0h] [ebp-1Ch]
  float v15; // [esp+A4h] [ebp-18h]
  struct GFxShapeBase *v16; // [esp+A8h] [ebp-14h]
  CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> b2; // [esp+ACh] [ebp-10h] BYREF
  float v18; // [esp+B8h] [ebp-4h]
  char v19; // [esp+C8h] [ebp+Ch]
  int pinsta; // [esp+CCh] [ebp+10h]

  v6 = nullptr;
  v16 = (struct GFxShapeBase *)this;
  if ( pinst != nullptr && (*((_BYTE *)pinst + 118) & 1) != 0 )
  {
    GFxCharacter::CreateScale9Grid(
      a1: (int)pinst,
      a2: (const CMaterialDict::MissingMaterial_t *)this,
      result: COERCE_CONST_CMEMBERFUNCTOR4_CMATRENDERCONTEXTBASE_VOID_THISCALL_IMATRENDERCONTEXT_ITEXTURE_INT_RECT_T_RECT_T_ITEXTURE_INT_RECT_T_RECT_T_CREFCOUNTED1_CFUNCTOR_CREFCOUNTSERVICEDESTRUCT_CREFST_CFUNCMEMPOLICYNONE_(1.0));
    v6 = (GFxScale9GridInfo *)v7;
    if ( v7 != nullptr )
      GFxScale9GridInfo::Compute(this: v7, gy1: v11);
  }
  v8 = (*(_BYTE *)(this + 36) & 0x10) == 0;
  b2.m_pMemory = *(CMatRenderContextBase::MatrixStackItem_t **)(this + 4);
  b2.m_nAllocationCount = *(int *)(this + 8);
  b2.m_nGrowSize = *(int *)(this + 12);
  v18 = *(float *)(this + 16);
  if ( v8 )
    (*(void (__thiscall **)(int, CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *))(*(_DWORD *)this + 20))(
      a1: this,
      a2: &b2);
  if ( v6 != nullptr )
  {
    v9 = GFxScale9GridInfo::AdjustBounds(a1: (int)v13, xb1: COERCE_FLOAT(&b2));
    pinsta = *(int *)(v9 + 4);
    v14 = *(int *)(v9 + 8);
    v15 = *(float *)(v9 + 12);
    b2.m_pMemory = *(CMatRenderContextBase::MatrixStackItem_t **)v9;
    b2.m_nAllocationCount = pinsta;
    b2.m_nGrowSize = v14;
    v18 = v15;
  }
  if ( *(float *)&b2.m_nGrowSize >= (double)*testShape
    && *(float *)&b2.m_pMemory <= (double)*testShape
    && v18 >= (double)testShape[1]
    && *(float *)&b2.m_nAllocationCount <= (double)testShape[1] )
  {
    if ( a3 != 0 )
    {
      if ( pinst != nullptr
        && v6 == nullptr
        && GFxCharacter::CheckLastHitResult(this: (int)pinst, x: *testShape, y: testShape[1]) )
      {
        return (*((_BYTE *)pinst + 118) & 8) != 0;
      }
      else
      {
        GFxSwfPathData::PathsIterator::PathsIterator(this: it, a2: (CFltX4AttributeIterator *)v16);
        v19 = GFxShapeBase::PointInShape<GFxSwfPathData,GFxSwfPathData::PathsIterator>(
                this: v16,
                a2: (IKMeansErrorMetric *)it,
                a3: v6,
                x: COERCE__IOBUF_(*testShape),
                y: COERCE_INT_(testShape[1]));
        if ( pinst != nullptr )
          GFxCharacter::SetLastHitResult(this: pinst, x: *testShape, y: testShape[1], result: v19);
        if ( v6 != nullptr )
          GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)v6);
        return v19;
      }
    }
    else
    {
      if ( v6 != nullptr )
        GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)v6);
      return true;
    }
  }
  else
  {
    if ( v6 != nullptr )
      GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)v6);
    return false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014E9D0
// Name: protected: bool GFxShapeBase::DefPointTestLocalImpl<class GFxPathData>(class GPoint<float> const __near &,bool,class GFxCharacter const __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxShapeBase::DefPointTestLocalImpl<GFxPathData>(
        int this,
        float *testShape,
        char a3,
        GFxCharacter *pinst)
{
  GFxScale9GridInfo *v6; // esi
  CMemberFuncProxy1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(Vector),Vector,CFuncMemPolicyNone> *v7; // eax
  bool v8; // zf
  int v9; // eax
  unsigned int v11; // [esp+10h] [ebp-5Ch]
  _BYTE v12[36]; // [esp+1Ch] [ebp-50h] BYREF
  int v13[4]; // [esp+40h] [ebp-2Ch] BYREF
  CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> b2; // [esp+50h] [ebp-1Ch] BYREF
  float v15; // [esp+5Ch] [ebp-10h]
  float v16; // [esp+60h] [ebp-Ch]
  int v17; // [esp+64h] [ebp-8h]
  struct GFxShapeBase *v18; // [esp+68h] [ebp-4h]
  char v19; // [esp+78h] [ebp+Ch]
  int pinsta; // [esp+7Ch] [ebp+10h]

  v6 = nullptr;
  v18 = (struct GFxShapeBase *)this;
  if ( pinst != nullptr && (*((_BYTE *)pinst + 118) & 1) != 0 )
  {
    GFxCharacter::CreateScale9Grid(
      a1: (int)pinst,
      a2: (const CMaterialDict::MissingMaterial_t *)this,
      result: COERCE_CONST_CMEMBERFUNCTOR4_CMATRENDERCONTEXTBASE_VOID_THISCALL_IMATRENDERCONTEXT_ITEXTURE_INT_RECT_T_RECT_T_ITEXTURE_INT_RECT_T_RECT_T_CREFCOUNTED1_CFUNCTOR_CREFCOUNTSERVICEDESTRUCT_CREFST_CFUNCMEMPOLICYNONE_(1.0));
    v6 = (GFxScale9GridInfo *)v7;
    if ( v7 != nullptr )
      GFxScale9GridInfo::Compute(this: v7, gy1: v11);
  }
  v8 = (*(_BYTE *)(this + 36) & 0x10) == 0;
  b2.m_pMemory = *(CMatRenderContextBase::MatrixStackItem_t **)(this + 4);
  b2.m_nAllocationCount = *(int *)(this + 8);
  b2.m_nGrowSize = *(int *)(this + 12);
  v15 = *(float *)(this + 16);
  if ( v8 )
    (*(void (__thiscall **)(int, CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *))(*(_DWORD *)this + 20))(
      a1: this,
      a2: &b2);
  if ( v6 != nullptr )
  {
    v9 = GFxScale9GridInfo::AdjustBounds(a1: (int)v13, xb1: COERCE_FLOAT(&b2));
    pinsta = *(int *)(v9 + 4);
    v17 = *(int *)(v9 + 8);
    v16 = *(float *)(v9 + 12);
    b2.m_pMemory = *(CMatRenderContextBase::MatrixStackItem_t **)v9;
    b2.m_nAllocationCount = pinsta;
    b2.m_nGrowSize = v17;
    v15 = v16;
  }
  if ( *(float *)&b2.m_nGrowSize >= (double)*testShape
    && *(float *)&b2.m_pMemory <= (double)*testShape
    && v15 >= (double)testShape[1]
    && *(float *)&b2.m_nAllocationCount <= (double)testShape[1] )
  {
    if ( a3 != 0 )
    {
      if ( pinst != nullptr
        && v6 == nullptr
        && GFxCharacter::CheckLastHitResult(this: (int)pinst, x: *testShape, y: testShape[1]) )
      {
        return (*((_BYTE *)pinst + 118) & 8) != 0;
      }
      else
      {
        GFxPathData::PathsIterator::PathsIterator(this: (GFxPathData::PathsIterator *)v12, a2: v18);
        v19 = GFxShapeBase::PointInShape<GFxPathData,GFxPathData::PathsIterator>(
                this: v18,
                a2: (CSOAContainer *)v12,
                a3: v6,
                x: COERCE__IOBUF_(*testShape),
                y: COERCE_INT_(testShape[1]));
        if ( pinst != nullptr )
          GFxCharacter::SetLastHitResult(this: pinst, x: *testShape, y: testShape[1], result: v19);
        if ( v6 != nullptr )
          GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)v6);
        return v19;
      }
    }
    else
    {
      if ( v6 != nullptr )
        GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)v6);
      return true;
    }
  }
  else
  {
    if ( v6 != nullptr )
      GRefCountNTSImpl::Release(this: (GRefCountNTSImpl *)v6);
    return false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1014EB70
// Name: public: virtual bool GFxConstShapeNoStyles::DefPointTestLocal(class GPoint<float> const __near &,bool,class GFxCharacter const __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxConstShapeNoStyles::DefPointTestLocal(int this, float *testShape, char a3, GFxCharacter *pinst)
{
  return GFxShapeBase::DefPointTestLocalImpl<GFxSwfPathData>(this, testShape, a3, pinst);
}

//------------------------------------------------------------------------------
// Address: 0x1014EB80
// Name: public: void GFxConstShapeNoStyles::Read(class GFxLoadProcess __near *,enum GFxTagType,unsigned int,bool,class GFxPathAllocator __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxConstShapeNoStyles::Read(
        CBitRead *this@<ecx>,
        _cpinfo *a2@<edi>,
        GFxAmpMsgHandler *p,
        int a4,
        unsigned int lenInBytes,
        bool withStyle,
        FloatCubeMap_t *a7)
{
  GFxConstShapeNoStyles::Read(this, a2, p, a4, lenInBytes, withStyle, a7: nullptr, a8: nullptr, a9: a7);
}

//------------------------------------------------------------------------------
// Address: 0x1014EBB0
// Name: public: virtual bool GFxShapeNoStyles::DefPointTestLocal(class GPoint<float> const __near &,bool,class GFxCharacter const __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxShapeNoStyles::DefPointTestLocal(int this, float *testShape, char a3, GFxCharacter *pinst)
{
  return GFxShapeBase::DefPointTestLocalImpl<GFxPathData>(this, testShape, a3, pinst);
}

//------------------------------------------------------------------------------
// Address: 0x1014EBC0
// Name: public: virtual bool GFxShapeCharacterDef::DefPointTestLocal(class GPoint<float> const __near &,bool,class GFxCharacter const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxShapeCharacterDef::DefPointTestLocal(old_bf_read *this, float *pt, char a3, GFxCharacter *pinst)
{
  GFxShapeBase::DefPointTestLocalImpl<GFxPathData>(this: (int)&this->m_bOverflow, testShape: pt, a3, pinst);
}

//------------------------------------------------------------------------------
// Address: 0x1014EBD0
// Name: public: virtual bool GFxConstShapeCharacterDef::DefPointTestLocal(class GPoint<float> const __near &,bool,class GFxCharacter const __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxConstShapeCharacterDef::DefPointTestLocal(
        void *this,
        CMemberFunctor2<CMaterialVar *,void (__thiscall CMaterialVar::*)(unsigned long,void *),unsigned long,void *,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *result,
        char a3,
        GFxCharacter *pinst)
{
  return GFxShapeBase::DefPointTestLocalImpl<GFxSwfPathData>(
           this: (int)this + 16,
           testShape: (float *)result,
           a3,
           pinst);
}
