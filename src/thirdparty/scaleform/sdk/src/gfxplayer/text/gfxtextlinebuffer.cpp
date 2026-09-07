// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/text/gfxtextlinebuffer.cpp
// Functions: 34
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\text\gfxtextlinebuffer.h"

//------------------------------------------------------------------------------
// Address: 0x101746B0
// Name: public: static int GFxTextLineBuffer::LineYOffsetComparator::Compare(class GFxTextLineBuffer::Line const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextLineBuffer::LineYOffsetComparator::Compare(CMatRenderContextBase *p1)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10174720
// Name: public: static int GFxTextLineBuffer::LineYOffsetComparator::Less(class GFxTextLineBuffer::Line const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextLineBuffer::LineYOffsetComparator::Less(CMatRenderContextBase *p1)
{
  GFxTextLineBuffer::LineYOffsetComparator::Compare(p1);
}

//------------------------------------------------------------------------------
// Address: 0x10174750
// Name: private: float TextUtil3D::SnapToRamp(float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall TextUtil3D::SnapToRamp(TextUtil3D *this, float a2)
{
  double v2; // st7
  int v3; // edi
  int v4; // esi
  float v6; // [esp+0h] [ebp-4h]
  float v7; // [esp+Ch] [ebp+8h]

  v2 = a2;
  v3 = 31;
  v4 = 0;
  do
  {
    if ( *((float *)this + ((v3 + v4) >> 1)) <= v2 )
      v4 = (v3 + v4) >> 1;
    else
      v3 = (v3 + v4) >> 1;
  }
  while ( v3 - v4 > 1 );
  v7 = *((float *)this + v4);
  v6 = *((float *)this + v3);
  if ( v2 - v7 >= v6 - v2 )
    return v6;
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x101747D0
// Name: private: double TextUtil3D::PolygonArea(class GPoint<float> __near *,int)
// Source: json
//------------------------------------------------------------------------------
long double __stdcall TextUtil3D::PolygonArea(int a1, int a2)
{
  double v2; // st7
  int v5; // esi
  int v6; // ebx
  int v7; // esi
  double v8; // st6
  int v9; // edx
  double v10; // st7
  double v11; // st6
  int v12; // edx
  double v13; // st7
  int v14; // eax
  bool v15; // zf
  unsigned int v17; // [esp+14h] [ebp+8h]
  int v18; // [esp+18h] [ebp+Ch]

  v2 = 0.0;
  v5 = 0;
  if ( a2 >= 4 )
  {
    v17 = ((unsigned int)(a2 - 4) >> 2) + 1;
    v6 = 2;
    v7 = a1 + 8;
    v18 = 4 * v17;
    do
    {
      v8 = *(float *)(v7 - 8);
      v9 = (v6 - 1) % a2;
      v7 += 32;
      v10 = v2 + v8 * *(float *)(a1 + 8 * v9 + 4);
      v11 = *(float *)(v7 - 36) * *(float *)(a1 + 8 * v9);
      v12 = (v6 + 1) % a2;
      v13 = v10
          - v11
          + *(float *)(a1 + 8 * (v6 % a2) + 4) * *(float *)(v7 - 32)
          - *(float *)(v7 - 28) * *(float *)(a1 + 8 * (v6 % a2));
      v14 = v6 + 2;
      v6 += 4;
      v15 = v17-- == 1;
      v2 = v13
         + *(float *)(v7 - 24) * *(float *)(a1 + 8 * v12 + 4)
         - *(float *)(v7 - 20) * *(float *)(a1 + 8 * v12)
         + *(float *)(v7 - 16) * *(float *)(a1 + 8 * (v14 % a2) + 4)
         - *(float *)(v7 - 12) * *(float *)(a1 + 8 * (v14 % a2));
    }
    while ( !v15 );
    v5 = v18;
  }
  if ( v5 < a2 )
  {
    while ( 1 )
    {
      v2 = v2
         + *(float *)(a1 + 8 * v5) * *(float *)(a1 + 8 * ((v5 + 1) % a2) + 4)
         - *(float *)(a1 + 8 * v5 + 4) * *(float *)(a1 + 8 * ((v5 + 1) % a2));
      if ( v5 + 1 >= a2 )
        break;
      ++v5;
    }
  }
  return fabs(v2 * 0.5);
}

//------------------------------------------------------------------------------
// Address: 0x101748B0
// Name: public: class GFxTextLineBuffer::Line __near * GFxTextLineBuffer::TextLineAllocator::AllocLine(unsigned int,enum GFxTextLineBuffer::LineType)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxTextLineBuffer::TextLineAllocator::AllocLine(
        GFxMovieView *this@<ecx>,
        float size,
        float lineType,
        unsigned int a4,
        unsigned int a5)
{
  _DWORD *v5; // eax
  int v6; // ecx
  int v7; // [esp+4h] [ebp-4h] BYREF

  v7 = 2;
  v5 = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: LODWORD(size), a4: &v7);
  *v5 ^= (LODWORD(size) ^ *v5) & 0xFFFFFFF;
  v6 = *v5 & 0xFFFFFFF;
  if ( lineType == 0.0 )
  {
    *v5 = v6 | 0xC0000000;
    v5[2] = 0;
    *(_DWORD *)((char *)v5 + 26) = 0;
    v5[4] = 0;
    v5[3] = 0;
  }
  else
  {
    *v5 = v6 | 0x40000000;
    v5[1] = 0;
    v5[2] = 0;
    *((_WORD *)v5 + 19) = 0;
    *((_WORD *)v5 + 20) = 0;
    v5[4] = 0;
    v5[3] = 0;
    v5[6] = 0;
    v5[8] = 0;
  }
  v5[5] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10174970
// Name: public: bool GFxTextLineBuffer::Line::HasNewLine(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxTextLineBuffer::Line::HasNewLine(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this)
{
  int v1; // edx
  char *v2; // eax

  if ( (int)this->m_pAllocator >= 0 )
    v1 = *((_DWORD *)this + 1);
  else
    v1 = *((unsigned __int8 *)this + 28);
  if ( v1 == 0 )
    return false;
  v2 = (char *)this + 30;
  if ( (int)this->m_pAllocator >= 0 )
    v2 = (char *)this + 42;
  return (v2[8 * v1 - 1] & 1) != 0 && (*(_WORD *)&v2[8 * v1 - 4] & 0xF000) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x101749B0
// Name: public: static unsigned int GFxTextLineBuffer::CalcLineSize(unsigned int,unsigned int,enum GFxTextLineBuffer::LineType)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > *__thiscall GFxTextLineBuffer::CalcLineSize(
        const CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > *glyphCount,
        unsigned int glyphCounta,
        unsigned int formatDataElementsCount,
        int a4)
{
  return (CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > *)((((a4 != 0 ? 0xC : 0) + 8 * glyphCounta + 33)
                                                                       & 0xFFFFFFFC)
                                                                      + 4 * formatDataElementsCount);
}

//------------------------------------------------------------------------------
// Address: 0x101749D0
// Name: public: void GFxTextLineBuffer::SetFirstVisibleLine(unsigned int)
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > *__thiscall GFxTextLineBuffer::SetFirstVisibleLine(
        int this,
        const CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > *result)
{
  *(_DWORD *)(this + 20) = result;
  *(_BYTE *)(this + 116) |= 1u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101749F0
// Name: public: void GFxTextLineBuffer::SetHScrollOffset(unsigned int)
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > *__thiscall GFxTextLineBuffer::SetHScrollOffset(
        _DWORD *this,
        const CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > *result)
{
  *(this + 10) = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10174A60
// Name: public: bool GFxTextFieldParam::operator==(struct GFxTextFieldParam const __near &)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall GFxTextFieldParam::operator==(_WORD *this, IVJobs *key)
{
  return *(IVJobs_vtbl **)this == key->__vftable
      && *(this + 2) == LOWORD(key[1].__vftable)
      && *((_BYTE *)this + 6) == BYTE2(key[1].__vftable)
      && *((_BYTE *)this + 7) == HIBYTE(key[1].__vftable)
      && *((_BYTE *)this + 8) == LOBYTE(key[2].__vftable)
      && *((_BYTE *)this + 9) == BYTE1(key[2].__vftable)
      && *((_BYTE *)this + 10) == BYTE2(key[2].__vftable)
      && *((_BYTE *)this + 11) == HIBYTE(key[2].__vftable)
      && GFxGlyphParam::operator==(this: this + 6, a2: (int)&key[3])
      && *((IVJobs_vtbl **)this + 6) == key[6].__vftable
      && *(this + 14) == LOWORD(key[7].__vftable)
      && *(this + 15) == HIWORD(key[7].__vftable)
      && *((IVJobs_vtbl **)this + 8) == key[8].__vftable
      && *((_BYTE *)this + 36) == LOBYTE(key[9].__vftable);
}

//------------------------------------------------------------------------------
// Address: 0x10174B00
// Name: public: void TextUtil3D::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TextUtil3D::Init(TextUtil3D *this)
{
  unsigned int v1; // eax
  float v2; // [esp+4h] [ebp-8h]
  float v3; // [esp+8h] [ebp-4h]
  float v4; // [esp+8h] [ebp-4h]

  if ( *((_BYTE *)this + 128) == 0 )
  {
    v3 = sqrt(2.0);
    v1 = 0;
    v2 = v3;
    v4 = 1.0;
    do
    {
      *((float *)this + v1++) = v4;
      v4 = v4 * v2;
    }
    while ( v1 < 0x20 );
    *((_BYTE *)this + 128) = 1;
  }
  *((_BYTE *)this + 196) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10174B60
// Name: public: class GFxTextLineBuffer::Line __near * GFxTextLineBuffer::GetLine(unsigned int)
// Source: json
//------------------------------------------------------------------------------
struct GFxTextLineBuffer::Line *__thiscall GFxTextLineBuffer::GetLine(GFxTextLineBuffer *this, unsigned int a2)
{
  struct GFxTextLineBuffer::Line *result; // eax

  if ( a2 >= *((_DWORD *)this + 1) )
    return nullptr;
  result = *(struct GFxTextLineBuffer::Line **)(*(_DWORD *)this + 4 * a2);
  *((_BYTE *)this + 116) |= 1u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10174B80
// Name: public: unsigned int GFxTextLineBuffer::GetVScrollOffsetInTwips(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextLineBuffer::GetVScrollOffsetInTwips(CMatCallQueue *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10174C50
// Name: public: bool GFxTextLineBuffer::IsPartiallyVisible(float)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxTextLineBuffer::IsPartiallyVisible(
        CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > *this,
        IMaterialVar *const *yOffset)
{
  unsigned int v2; // eax
  IMaterialVar *v3; // eax
  int v4; // esi
  float w; // esi
  int v6; // esi
  float lh; // [esp+4h] [ebp-Ch]
  float vrectH; // [esp+8h] [ebp-8h]
  float v10; // [esp+Ch] [ebp-4h]
  float yf; // [esp+18h] [ebp+8h]

  v2 = *((_DWORD *)this + 5);
  if ( v2 >= this->m_Memory.m_nAllocationCount )
    return 0;
  v3 = this->m_Memory.m_pMemory[v2];
  v4 = (int)v3->__vftable >= 0 ? LODWORD(v3->m_VecVal.z) : LOWORD(v3->m_VecVal.z);
  if ( v4 == 0 )
    return 0;
  if ( (int)v3->__vftable >= 0 )
    w = v3->m_VecVal.w;
  else
    LODWORD(w) = HIWORD(v3->m_VecVal.z);
  if ( w == 0.0 )
    return 0;
  v6 = (int)v3->__vftable >= 0 ? LODWORD(v3->m_VecVal.w) : HIWORD(v3->m_VecVal.z);
  v10 = *((float *)this + 9) - *((float *)this + 7);
  vrectH = v10 + 20.0;
  yf = (double)SLODWORD(v3->m_VecVal.y) + *(float *)&yOffset;
  if ( vrectH < (double)yf )
    return 0;
  lh = (float)v6;
  return vrectH < yf + lh;
}

//------------------------------------------------------------------------------
// Address: 0x10174D10
// Name: public: int GFxTextLineBuffer::GetMinLineHeight(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GFxTextLineBuffer::GetMinLineHeight(GFxTextLineBuffer *this)
{
  unsigned int result; // eax
  int v2; // esi
  int v3; // edi
  int v4; // edx
  int v5; // edx

  result = *((_DWORD *)this + 1);
  if ( result != 0 )
  {
    v2 = 0;
    v3 = 0x7FFFFFFF;
    while ( v2 < result && v2 >= 0 )
    {
      v4 = *(_DWORD *)(*(_DWORD *)this + 4 * v2);
      if ( *(int *)v4 >= 0 )
        v5 = *(_DWORD *)(v4 + 24);
      else
        v5 = *(unsigned __int16 *)(v4 + 22);
      if ( v5 < v3 )
        v3 = v5;
      ++v2;
    }
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10174D60
// Name: void GFx_RecalculateRectToFit16Bit(class GMatrix2D __near &,class GRect<float> const __near &,class GRect<float> __near *)
// Source: json
//------------------------------------------------------------------------------
struct GMatrix2D *__cdecl GFx_RecalculateRectToFit16Bit(GMatrix2D *a1, float *a2, float *a3)
{
  double v3; // st6
  double v4; // st7
  struct GMatrix2D *result; // eax
  float v6; // [esp+0h] [ebp-2Ch]
  float v7; // [esp+4h] [ebp-28h]
  float v8; // [esp+8h] [ebp-24h]
  float v9; // [esp+Ch] [ebp-20h]
  struct GMatrix2D v10; // [esp+10h] [ebp-1Ch] BYREF

  v3 = a2[1];
  v4 = *a2;
  a1->M_[0][2] = a1->M_[0][0] * v4 + a1->M_[0][1] * v3 + a1->M_[0][2];
  a1->M_[1][2] = v4 * a1->M_[1][0] + v3 * a1->M_[1][1] + a1->M_[1][2];
  v9 = 1.0;
  v7 = a2[2] - *a2;
  if ( v7 > 32767.0 )
  {
    v9 = v7 / 32767.0;
    v7 = 32767.0;
  }
  v8 = 1.0;
  v6 = a2[3] - a2[1];
  if ( v6 > 32767.0 )
  {
    v8 = v6 / 32767.0;
    v6 = 32767.0;
  }
  v10.M_[0][0] = v9;
  v10.M_[0][1] = 0.0;
  v10.M_[0][2] = 0.0;
  v10.M_[1][0] = 0.0;
  v10.M_[1][1] = v8;
  v10.M_[1][2] = 0.0;
  result = GMatrix2D::Prepend(this: a1, a2: &v10);
  *a3 = 0.0;
  a3[1] = 0.0;
  a3[2] = v7 + 0.0;
  a3[3] = v6 + 0.0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10174E60
// Name: public: void TextUtil3D::BeginDisplay(class GFxDisplayContext const __near &,class GMatrix2D __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TextUtil3D::BeginDisplay(TextUtil3D *this, const struct GFxDisplayContext *a2, struct GMatrix2D *a3)
{
  bool v3; // zf
  CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *v4; // esi
  TextUtil3D *v5; // edi
  double v6; // st7
  double v7; // st6
  double v8; // st7
  const struct GFxDisplayContext *v9; // eax
  const void *v10; // esi
  GMatrix3D *v11; // eax
  float v12[4]; // [esp+18h] [ebp-118h] BYREF
  const struct GFxDisplayContext *v13; // [esp+28h] [ebp-108h]
  TextUtil3D *v14; // [esp+2Ch] [ebp-104h]
  CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *v15; // [esp+30h] [ebp-100h]
  GMatrix3D v16; // [esp+34h] [ebp-FCh] BYREF
  GMatrix3D v17; // [esp+74h] [ebp-BCh] BYREF
  GMatrix3D v18; // [esp+B4h] [ebp-7Ch] BYREF
  float v19[2]; // [esp+F4h] [ebp-3Ch] BYREF
  float v20; // [esp+FCh] [ebp-34h]
  float v21; // [esp+100h] [ebp-30h]
  float v22; // [esp+104h] [ebp-2Ch]
  float v23; // [esp+108h] [ebp-28h]
  int v24[8]; // [esp+10Ch] [ebp-24h] BYREF

  v3 = *((_BYTE *)a2 + 20) == 0;
  v14 = this;
  v13 = a2;
  if ( !v3 )
  {
    v15 = *((CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> **)a2
          + 20);
    if ( *(float *)&v15 != 0.0 )
    {
      v16 = *(GMatrix3D *)*((_DWORD *)a2 + 2);
      GMatrix3D::GMatrix3D(this: &v17, a2: a3);
      v18 = v16;
      GMatrix3D::MultiplyMatrix(this: (CBasePerMaterialContextData *)&v16, a2: (float *)&v17, a3: (float *)&v18);
      v4 = v15;
      GFxCharacter::GetProjectedBounds(this: v15, a2: (float *)v24, a3: &v16);
      v5 = v14;
      *(float *)&v15 = TextUtil3D::PolygonArea(a1: (int)v24, a2: 4);
      GMatrix2D::SetIdentity(this: v19);
      GFxCharacter::GetWorldMatrix(this: (GFxCharacter *)v4, pmat: (CMaterialDict *)v19);
      (*(void (__thiscall **)(CMemberFuncProxy1<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CMatQueuedMesh::MST_MeshInfo_t,CFuncMemPolicyNone> *, float *, float *))(LODWORD(v4->m_pfnProxied) + 52))(
        a1: v4,
        a2: v12,
        a3: v19);
      v20 = v12[0] / 20.0;
      v21 = v12[1] / 20.0;
      v22 = v12[2] / 20.0;
      v23 = v12[3] / 20.0;
      v6 = *(float *)&v15;
      *(float *)&v15 = v23 - v21;
      v7 = *(float *)&v15;
      *(float *)&v15 = v22 - v20;
      *(float *)&v15 = v7 * *(float *)&v15;
      *(float *)&v15 = v6 / *(float *)&v15;
      *(float *)&v15 = TextUtil3D::SnapToRamp(this: v5, a2: *(float *)&v15);
      v8 = *(float *)&v15;
      if ( *(float *)&v15 > 1.0 )
      {
        *(float *)&v15 = 1.0 / v8;
        a3->M_[0][0] = a3->M_[0][0] * v8;
        a3->M_[0][1] = a3->M_[0][1] * v8;
        a3->M_[0][2] = a3->M_[0][2] * v8;
        a3->M_[1][0] = a3->M_[1][0] * v8;
        a3->M_[1][1] = a3->M_[1][1] * v8;
        a3->M_[1][2] = v8 * a3->M_[1][2];
        GMatrix3D::SetIdentity(this: &v18);
        GMatrix3D::SetIdentity(this: &v18);
        v9 = v13;
        v18.M_[0][0] = *(float *)&v15;
        v10 = *((const void **)v13 + 2);
        v18.M_[1][1] = *(float *)&v15;
        v18.M_[2][2] = *(float *)&v15;
        qmemcpy((char *)v5 + 132, v10, 0x40u);
        v11 = *((GMatrix3D **)v9 + 2);
        v17 = *v11;
        GMatrix3D::MultiplyMatrix(this: (CBasePerMaterialContextData *)v11, a2: (float *)&v18, a3: (float *)&v17);
        *((_BYTE *)v14 + 196) = 1;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101750A0
// Name: public: static bool GFxTextLineBuffer::DrawMask(class GFxDisplayContext __near &,class GMatrix2D const __near &,class GRect<float> const __near &,enum GRenderer::SubmitMaskMode)
// Source: json
//------------------------------------------------------------------------------
char __cdecl GFxTextLineBuffer::DrawMask(
        CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *rect,
        float *a2,
        float *a3,
        int a4)
{
  int v4; // esi
  CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> newRect; // [esp+Ch] [ebp-40h] BYREF
  float v7; // [esp+18h] [ebp-34h]
  __int16 v8; // [esp+1Eh] [ebp-2Eh]
  GMatrix2D v9; // [esp+20h] [ebp-2Ch] BYREF
  __int16 v10; // [esp+38h] [ebp-14h] BYREF
  __int16 v11; // [esp+3Ah] [ebp-12h]
  __int16 v12; // [esp+3Ch] [ebp-10h]
  __int16 v13; // [esp+3Eh] [ebp-Eh]
  __int16 v14; // [esp+40h] [ebp-Ch]
  __int16 v15; // [esp+42h] [ebp-Ah]
  __int16 v16; // [esp+44h] [ebp-8h]
  __int16 v17; // [esp+46h] [ebp-6h]

  v4 = *(_DWORD *)(rect[3].m_Size + 12);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v4 + 156))(a1: v4, a2: a4);
  v9.M_[0][0] = *a2;
  v9.M_[0][1] = a2[1];
  v9.M_[0][2] = a2[2];
  v9.M_[1][0] = a2[3];
  v9.M_[1][1] = a2[4];
  v9.M_[1][2] = a2[5];
  *(float *)&newRect.m_pMemory = 0.0;
  *(float *)&newRect.m_nAllocationCount = 0.0;
  *(float *)&newRect.m_nGrowSize = 0.0;
  v7 = 0.0;
  GFx_RecalculateRectToFit16Bit(a1: &v9, a2: a3, a3: (float *)&newRect);
  (*(void (__thiscall **)(int, GMatrix2D *))(*(_DWORD *)v4 + 56))(a1: v4, a2: &v9);
  v10 = (int)*(float *)&newRect.m_pMemory;
  v11 = (int)*(float *)&newRect.m_nAllocationCount;
  v8 = (int)*(float *)&newRect.m_nGrowSize;
  v12 = v8;
  v13 = v11;
  v14 = v10;
  v15 = (int)v7;
  v16 = v8;
  v17 = v15;
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v4 + 136))(a1: v4, a2: -1);
  (*(void (__thiscall **)(int, __int16 *, int, int, _DWORD))(*(_DWORD *)v4 + 104))(
    a1: v4,
    a2: &v10,
    a3: 4,
    a4: 1,
    a5: 0);
  (*(void (__thiscall **)(int, void *, int, int, _DWORD))(*(_DWORD *)v4 + 108))(
    a1: v4,
    a2: &`GFxEditTextCharacter::Display'::`21'::indices,
    a3: 6,
    a4: 1,
    a5: 0);
  (*(void (__thiscall **)(int, _DWORD, _DWORD, int, _DWORD, int))(*(_DWORD *)v4 + 116))(
    a1: v4,
    a2: 0,
    a3: 0,
    a4: 4,
    a5: 0,
    a6: 2);
  (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v4 + 104))(
    a1: v4,
    a2: 0,
    a3: 0,
    a4: 0,
    a5: 0);
  (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v4 + 108))(
    a1: v4,
    a2: 0,
    a3: 0,
    a4: 0,
    a5: 0);
  (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 160))(a1: v4);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10175210
// Name: public: void GFxTextLineBuffer::DrawUnderline(float,float,float,float,class GRect<float> const __near &,int,enum GFxTextHighlightInfo::UnderlineStyle,unsigned long,class GMatrix2D const __near &,class GMatrix2D const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextLineBuffer::DrawUnderline(
        IClientTools **this,
        void *a2,
        float a3,
        float a4,
        float a5,
        int a6,
        int a7,
        int a8,
        int rgba,
        CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *a10,
        CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *a11)
{
  double v12; // st7
  bool v13; // c0
  bool v14; // c3
  double v15; // st7
  int v16; // ebx
  double v17; // st6
  double v18; // st7
  double v19; // st7
  double v20; // st7
  bool v21; // c0
  bool v22; // c3
  double v23; // st7
  double v24; // st7
  bool v25; // c0
  bool v26; // c3
  double v27; // st7
  bool v28; // zf
  IClientTools *v29; // eax
  IClientTools *v30; // edi
  GRefCountNTSImpl *v31; // ecx
  double v32; // st7
  CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *v33; // edi
  CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *v34; // ebx
  double v35; // st7
  double v36; // st7
  IClientTools *v37; // ecx
  CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *v38; // edi
  double v39; // st7
  CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *v40; // ebx
  double v41; // st6
  double v42; // st7
  double v43; // st7
  IClientTools *v44; // ecx
  IClientTools *v45; // ecx
  IClientTools *v46; // ecx
  CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *X_4; // [esp+10h] [ebp-60h]
  const FlashlightState_t *v48; // [esp+14h] [ebp-5Ch]
  int v49; // [esp+14h] [ebp-5Ch]
  int v50; // [esp+14h] [ebp-5Ch]
  int v51; // [esp+14h] [ebp-5Ch]
  CCountedStringPoolBase<unsigned int>::hash_item_t v52; // [esp+28h] [ebp-48h] BYREF
  float v53; // [esp+34h] [ebp-3Ch]
  double v54; // [esp+38h] [ebp-38h]
  CCountedStringPoolBase<unsigned int>::hash_item_t result; // [esp+40h] [ebp-30h] BYREF
  float v56; // [esp+4Ch] [ebp-24h]
  double v57; // [esp+50h] [ebp-20h]
  void *v58; // [esp+58h] [ebp-18h]
  float v59; // [esp+5Ch] [ebp-14h]
  int p; // [esp+60h] [ebp-10h] BYREF
  float v61; // [esp+64h] [ebp-Ch]
  void *v62; // [esp+68h] [ebp-8h]
  float v63; // [esp+6Ch] [ebp-4h]
  int v64; // [esp+80h] [ebp+10h]
  float v65; // [esp+80h] [ebp+10h]
  float v66; // [esp+84h] [ebp+14h]
  int v67; // [esp+84h] [ebp+14h]
  float v68; // [esp+84h] [ebp+14h]
  float v69; // [esp+84h] [ebp+14h]
  float v70; // [esp+84h] [ebp+14h]
  int v71; // [esp+84h] [ebp+14h]
  float v72; // [esp+84h] [ebp+14h]
  float v73; // [esp+84h] [ebp+14h]
  float v74; // [esp+84h] [ebp+14h]
  float v75; // [esp+84h] [ebp+14h]
  int i; // [esp+88h] [ebp+18h]

  v12 = *(float *)a6;
  v13 = *(float *)&a2 < v12;
  v14 = *(float *)&a2 == v12;
  v15 = *(float *)&a2;
  if ( v13 || v14 )
  {
    v62 = *(void **)a6;
  }
  else if ( *(float *)(a6 + 8) > v15 )
  {
    v62 = a2;
  }
  else
  {
    v62 = *(void **)(a6 + 8);
  }
  if ( a3 > (double)*(float *)(a6 + 4) )
  {
    if ( *(float *)(a6 + 12) > (double)a3 )
      v63 = a3;
    else
      v63 = *(float *)(a6 + 12);
  }
  else
  {
    v63 = *(float *)(a6 + 4);
  }
  v16 = a8;
  v17 = v15 + (double)a7;
  v18 = a3;
  *(float *)&a7 = v17;
  if ( a8 == 2 )
    v19 = v18 + a4 + a4;
  else
    v19 = v18 + a4;
  *(float *)&v52.nNextElement = v19;
  v20 = *(float *)a6;
  v21 = *(float *)&a7 < v20;
  v22 = *(float *)&a7 == v20;
  v23 = *(float *)&a7;
  if ( v21 || v22 )
  {
    v23 = *(float *)a6;
  }
  else if ( *(float *)(a6 + 8) <= v23 )
  {
    v23 = *(float *)(a6 + 8);
  }
  *(float *)&p = v23;
  v24 = *(float *)(a6 + 4);
  v25 = *(float *)&v52.nNextElement < v24;
  v26 = *(float *)&v52.nNextElement == v24;
  v27 = *(float *)&v52.nNextElement;
  if ( v25 || v26 )
  {
    v27 = *(float *)(a6 + 4);
  }
  else if ( *(float *)(a6 + 12) <= v27 )
  {
    v27 = *(float *)(a6 + 12);
  }
  v61 = v27;
  v59 = v61;
  *(float *)&a7 = *(float *)&p + 0.5;
  *(float *)&a7 = floor(X: *(float *)&a7);
  v58 = (void *)a7;
  *(float *)&a7 = v61 + 0.5;
  *(float *)&a7 = floor(X: *(float *)&a7);
  v28 = *(this + 51) == nullptr;
  v59 = *(float *)&a7;
  if ( v28 )
  {
    a7 = 322;
    v29 = (IClientTools *)GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 136, a4: &a7);
    if ( v29 != nullptr )
      v30 = GFxDrawingContext::GFxDrawingContext(this: v29);
    else
      v30 = nullptr;
    v31 = (GRefCountNTSImpl *)*(this + 51);
    if ( v31 != nullptr )
      GRefCountNTSImpl::Release(this: v31);
    *(this + 51) = v30;
  }
  GFxDrawingContext::SetFill(this: *(this + 51), rgba, a3: v48);
  if ( v16 == 3 )
    v32 = 2.0;
  else
    v32 = 1.0;
  *(float *)&a7 = v32;
  switch ( v16 )
  {
    case 1:
    case 2:
      GFxDrawingContext::MoveTo(this: *(this + 51), x: v62, y: v63);
      GFxDrawingContext::LineTo(this: *(this + 51), x: v58, y: v63);
      GFxDrawingContext::LineTo(this: *(this + 51), x: v58, y: v59);
      GFxDrawingContext::LineTo(this: *(this + 51), x: v62, y: v59);
      GFxDrawingContext::LineTo(this: *(this + 51), x: v62, y: v63);
      GFxDrawingContext::AddPath(this: *(this + 51));
      break;
    case 3:
    case 4:
      v57 = *(float *)&v58;
      if ( *(float *)&v58 > (double)*(float *)&v62 )
      {
        v33 = a11;
        v34 = a10;
        v54 = *(float *)&a7 * a5;
        v35 = *(float *)&v62;
        do
        {
          *(float *)&p = v35;
          v61 = v59;
          GMatrix2D::Transform(
            this: v34,
            result: (CCountedStringPoolBase<unsigned int>::hash_item_t *)&result.nReferenceCount,
            (float *)&p,
            p_4: v49);
          v66 = *(float *)&result.nReferenceCount + 0.5;
          *(float *)&v67 = floor(X: v66);
          p = v67;
          v68 = v56 + 0.5;
          v69 = floor(X: v68);
          v61 = v69;
          GMatrix2D::Transform(this: v33, &result, (float *)&p, p_4: v50);
          v70 = *(float *)&result.pString + 0.5;
          *(float *)&v71 = floor(X: v70);
          p = v71;
          v72 = *(float *)&result.nNextElement + 0.5;
          v36 = floor(X: v72);
          v37 = *(this + 51);
          v73 = v36;
          v61 = v73;
          v64 = p;
          GFxDrawingContext::MoveTo(this: v37, x: (void *)p, y: v63);
          v74 = *(float *)&p + v54;
          GFxDrawingContext::LineTo(this: *(this + 51), x: (void *)LODWORD(v74), y: v63);
          v75 = *(float *)&p + v54;
          GFxDrawingContext::LineTo(this: *(this + 51), x: (void *)LODWORD(v75), y: v59);
          GFxDrawingContext::LineTo(this: *(this + 51), x: (void *)p, y: v59);
          GFxDrawingContext::LineTo(this: *(this + 51), x: (void *)p, y: v63);
          GFxDrawingContext::AddPath(this: *(this + 51));
          v65 = *(float *)&v64 + v54 + v54;
          v35 = v65;
        }
        while ( v65 < v57 );
      }
      break;
    case 5:
      v38 = a11;
      v39 = a5;
      v40 = a10;
      for ( i = 0; i < 2; ++i )
      {
        *(float *)&a7 = (double)i * v39 + *(float *)&v62;
        v57 = *(float *)&v58;
        if ( *(float *)&a7 < (double)*(float *)&v58 )
        {
          v41 = v39;
          v42 = *(float *)&a7;
          do
          {
            *(float *)&p = v42;
            v61 = v63;
            GMatrix2D::Transform(
              this: v40,
              result: (CCountedStringPoolBase<unsigned int>::hash_item_t *)&v52.nReferenceCount,
              (float *)&p,
              p_4: v49);
            *(float *)&a7 = *(float *)&v52.nReferenceCount + 0.5;
            *(float *)&a7 = floor(X: *(float *)&a7);
            p = a7;
            *(float *)&a7 = v53 + 0.5;
            *(float *)&a7 = floor(X: *(float *)&a7);
            v61 = *(float *)&a7;
            GMatrix2D::Transform(this: v38, result: &v52, (float *)&p, p_4: v51);
            *(float *)&a7 = *(float *)&v52.pString + 0.5;
            *(float *)&a7 = floor(X: *(float *)&a7);
            p = a7;
            *(float *)&a7 = *(float *)&v52.nNextElement + 0.5;
            v43 = floor(X: *(float *)&a7);
            v44 = *(this + 51);
            *(float *)&a7 = v43;
            v61 = *(float *)&a7;
            a7 = p;
            GFxDrawingContext::MoveTo(this: v44, x: (void *)p, y: v61);
            v45 = *(this + 51);
            *(float *)&a11 = *(float *)&p + a5;
            GFxDrawingContext::LineTo(this: v45, x: a11, y: v61);
            *(float *)&a11 = v61 + a4;
            X_4 = a11;
            *(float *)&a11 = *(float *)&p + a5;
            GFxDrawingContext::LineTo(this: *(this + 51), x: a11, y: *(float *)&X_4);
            v46 = *(this + 51);
            *(float *)&a11 = v61 + a4;
            GFxDrawingContext::LineTo(this: v46, x: (void *)p, y: *(float *)&a11);
            GFxDrawingContext::LineTo(this: *(this + 51), x: (void *)p, y: v61);
            GFxDrawingContext::AddPath(this: *(this + 51));
            *(float *)&a7 = *(float *)&a7 + v41 + v41;
            v42 = *(float *)&a7;
          }
          while ( *(float *)&a7 < v57 );
          v39 = a5;
        }
        v63 = v63 + a4;
      }
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10175810
// Name: public: class GFxTextLineBuffer::Iterator GFxTextLineBuffer::FindLineByTextPos(unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __fastcall GFxTextLineBuffer::FindLineByTextPos(int *a1, int a2, int a3, unsigned int textPos)
{
  int v4; // edi
  int v5; // edx
  int v6; // ecx
  int v7; // edx
  int v8; // esi
  int v9; // edx
  int v10; // edi
  int v11; // eax
  unsigned int v12; // esi
  int v13; // eax
  char v15; // cl
  int *v16; // [esp+10h] [ebp-Ch]
  int v17; // [esp+14h] [ebp-8h]
  int v18; // [esp+18h] [ebp-4h]

  v4 = a1[1];
  v16 = a1;
  if ( v4 == 0 )
    goto LABEL_30;
  v5 = 0;
  v18 = 0;
  if ( v4 > 0 )
  {
    v17 = *a1;
    do
    {
      v6 = (v4 >> 1) + v5;
      v7 = *(_DWORD *)(v17 + 4 * v6);
      v8 = *(_DWORD *)(v7 + 8);
      if ( *(int *)v7 < 0 )
      {
        v8 &= 0xFFFFFFu;
        if ( v8 == 0xFFFFFF )
          v8 = -1;
      }
      if ( (int)textPos >= v8
        && (*(int *)v7 >= 0 ? (v9 = *(_DWORD *)(v7 + 32)) : (v9 = *(unsigned __int8 *)(v7 + 11)), (int)textPos < v8 + v9)
        || (int)(v8 - textPos) >= 0 )
      {
        v4 >>= 1;
      }
      else
      {
        v18 = v6 + 1;
        v4 += -1 - (v4 >> 1);
      }
      v5 = v18;
    }
    while ( v4 > 0 );
    a1 = v16;
  }
  v10 = v5;
  if ( v5 == a1[1] )
    v10 = v5 - 1;
  v11 = *(_DWORD *)(*a1 + 4 * v10);
  if ( *(int *)v11 >= 0 )
    v12 = *(_DWORD *)(v11 + 8);
  else
    v12 = (*(_DWORD *)(v11 + 8) & 0xFFFFFF) == 0xFFFFFF ? -1 : *(_DWORD *)(v11 + 8) & 0xFFFFFF;
  if ( textPos >= v12
    && (*(int *)v11 >= 0 ? (v13 = *(_DWORD *)(v11 + 32)) : (v13 = *(unsigned __int8 *)(v11 + 11)), textPos <= v12 + v13) )
  {
    *(_DWORD *)a3 = a1;
    *(float *)(a3 + 12) = 0.0;
    v15 = *((_BYTE *)a1 + 116);
    *(_DWORD *)(a3 + 8) = v10;
    *(_DWORD *)(a3 + 4) = 0;
    *(_BYTE *)(a3 + 16) = (v15 & 4) != 0;
    return a3;
  }
  else
  {
LABEL_30:
    *(float *)(a3 + 12) = 0.0;
    *(_DWORD *)a3 = 0;
    *(_DWORD *)(a3 + 4) = 0;
    *(_DWORD *)(a3 + 8) = 0;
    *(_BYTE *)(a3 + 16) = 0;
    return a3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10175930
// Name: public: class GFxTextLineBuffer::Iterator GFxTextLineBuffer::FindLineAtYOffset(float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxTextLineBuffer::FindLineAtYOffset(
        CMatCallQueue *this@<ecx>,
        CMatRenderContextBase *yoff,
        __int128 yoffa,
        const MaterialNonInteractiveMode_t *a4)
{
  CMatCallQueue::Elem_t *m_pTail; // eax
  CMatCallQueue::Elem_t *v6; // eax
  int v7; // edx
  double v8; // st7
  CMatCallQueue::Elem_t *pNext; // ecx
  int v10; // edi
  bool v11; // bl
  int v12; // eax
  int v13; // eax
  char v14; // dl

  m_pTail = this->m_pTail;
  if ( m_pTail == nullptr )
    goto LABEL_13;
  v6 = (CMatCallQueue::Elem_t *)G_LowerBoundSliced<GArrayLH<GFxTextLineBuffer::Line *,2,GArrayDefaultPolicy>,float,int (__cdecl *)(GFxTextLineBuffer::Line const *,float)>(
                                  a1: this,
                                  a2: 0,
                                  a3: (int)m_pTail,
                                  a4: (float *)&yoffa,
                                  a5: (int (__cdecl *)(_DWORD, float))GFxTextLineBuffer::LineYOffsetComparator::Less);
  v7 = (int)v6;
  if ( v6 == this->m_pTail )
    v7 = (int)&v6[-1].pNext + 3;
  v8 = *(float *)&yoffa;
  pNext = this->m_pHead[v7].pNext;
  v10 = (int)pNext[4].pNext;
  v11 = (int)pNext->pNext < 0;
  if ( (double)v10 > *(float *)&yoffa )
    goto LABEL_13;
  v12 = (int)pNext->pNext >= 0 ? (int)pNext[6].pNext : HIWORD(pNext[5].pNext);
  LODWORD(yoffa) = v12;
  v13 = v11 ? SBYTE1(pNext[7].pNext) : SLOWORD(pNext[10].pNext);
  LODWORD(yoffa) = v10 + yoffa + v13;
  if ( (double)(int)yoffa > v8 )
  {
    yoff->m_iRefs = v7;
    *(float *)&yoff->m_pCurrentMaterial = 0.0;
    v14 = *((_BYTE *)this + 116) >> 2;
    yoff->CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::IMatRenderContextInternal::IMatRenderContext::IRefCounted::__vftable = (CMatRenderContextBase_vtbl *)this;
    yoff->CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = nullptr;
    LOBYTE(yoff->m_pCurrentProxyData) = v14 & 1;
  }
  else
  {
LABEL_13:
    *(float *)&yoff->m_pCurrentMaterial = 0.0;
    yoff->CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::IMatRenderContextInternal::IMatRenderContext::IRefCounted::__vftable = nullptr;
    yoff->CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = nullptr;
    yoff->m_iRefs = 0;
    LOBYTE(yoff->m_pCurrentProxyData) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10175A00
// Name: public: class GFxTextLineBuffer::Iterator GFxTextLineBuffer::FindLineAtOffset(class GPoint<float> const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxTextLineBuffer::FindLineAtOffset(int this, int a2, float *p)
{
  int v4; // eax
  float *v5; // edi
  int v6; // eax
  int v7; // eax
  int v8; // ecx
  int v9; // edx
  bool v10; // bl
  int v11; // esi
  int v12; // eax
  int v13; // edx
  int v14; // ecx
  bool v16; // cl
  int v18; // [esp+10h] [ebp-14h]
  int v19; // [esp+14h] [ebp-10h]
  int v20; // [esp+1Ch] [ebp-8h]
  unsigned int i; // [esp+20h] [ebp-4h]

  v4 = *(_DWORD *)(this + 4);
  if ( v4 != 0 )
  {
    v5 = p + 1;
    v6 = G_LowerBoundSliced<GArrayLH<GFxTextLineBuffer::Line *,2,GArrayDefaultPolicy>,float,int (__cdecl *)(GFxTextLineBuffer::Line const *,float)>(
           a1: (_DWORD *)this,
           a2: 0,
           a3: v4,
           a4: p + 1,
           a5: (int (__cdecl *)(_DWORD, float))GFxTextLineBuffer::LineYOffsetComparator::Less);
    i = v6;
    v18 = *(_DWORD *)(this + 4);
    if ( v6 == v18 )
      i = --v6;
    v7 = *(_DWORD *)this + 4 * v6;
    v8 = *(_DWORD *)v7;
    v9 = *(_DWORD *)(*(_DWORD *)v7 + 16);
    v19 = v9;
    v10 = **(int **)v7 < 0;
    v20 = v7;
    while ( (double)v9 <= *v5 )
    {
      v11 = v10 ? *(unsigned __int16 *)(v8 + 22) : *(_DWORD *)(v8 + 24);
      v12 = v10 ? *(char *)(v8 + 29) : *(__int16 *)(v8 + 40);
      if ( (double)(v9 + v11 + v12) <= *v5 )
        break;
      v13 = *(_DWORD *)(v8 + 12);
      if ( (double)v13 <= *p )
      {
        v14 = v10 ? *(unsigned __int16 *)(v8 + 20) : *(_DWORD *)(v8 + 20);
        if ( (double)(v13 + v14) > *p )
        {
          *(float *)(a2 + 12) = 0.0;
          *(_DWORD *)a2 = this;
          v16 = (*(_BYTE *)(this + 116) & 4) != 0;
          *(_DWORD *)(a2 + 4) = 0;
          *(_DWORD *)(a2 + 8) = i;
          *(_BYTE *)(a2 + 16) = v16;
          return a2;
        }
      }
      v20 += 4;
      if ( ++i != v18 )
      {
        v8 = *(_DWORD *)v20;
        v9 = *(_DWORD *)(*(_DWORD *)v20 + 16);
        v10 = **(int **)v20 < 0;
        if ( v9 == v19 )
          continue;
      }
      break;
    }
  }
  *(float *)(a2 + 12) = 0.0;
  *(_DWORD *)a2 = 0;
  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)(a2 + 8) = 0;
  *(_BYTE *)(a2 + 16) = 0;
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x10175B60
// Name: GFx_CalcHeightRatio_GMatrix2D_
// Source: json
//------------------------------------------------------------------------------
void __cdecl GFx_CalcHeightRatio_GMatrix2D_(int a1)
{
  CCountedStringPoolBase<unsigned int>::hash_item_t result; // [esp+0h] [ebp-3Ch] BYREF
  int p; // [esp+18h] [ebp-24h] BYREF
  float v3; // [esp+1Ch] [ebp-20h]
  CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > v4; // [esp+20h] [ebp-1Ch] BYREF
  float v5; // [esp+34h] [ebp-8h]

  v4.m_Memory.m_pMemory = *(CCountedStringPoolBase<unsigned int>::hash_item_t **)a1;
  v4.m_Memory.m_nAllocationCount = *(int *)(a1 + 4);
  v4.m_Size = *(int *)(a1 + 12);
  v4.m_pElements = *(CCountedStringPoolBase<unsigned int>::hash_item_t **)(a1 + 16);
  *(float *)&v4.m_Memory.m_nGrowSize = 0.0;
  v5 = 0.0;
  *(float *)&p = 0.0;
  v3 = 1.0;
  GMatrix2D::Transform(
    this: &v4,
    result: (CCountedStringPoolBase<unsigned int>::hash_item_t *)&result.nReferenceCount,
    (float *)&p,
    p_4: (int)result.pString);
  *(float *)&p = 1.0;
  v3 = 0.0;
  GMatrix2D::Transform(this: &v4, &result, (float *)&p, p_4: (int)result.pString);
}

//------------------------------------------------------------------------------
// Address: 0x10175C70
// Name: private: static void GFxTextLineBuffer::ReleasePartOfLine(class GFxTextLineBuffer::GlyphEntry __near *,unsigned int,union GFxTextLineBuffer::GFxFormatDataEntry __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextLineBuffer::ReleasePartOfLine(CMatRenderContextBase *pglyphs, __int128 n)
{
  GRefCountNTSImpl **v2; // ebx
  _WORD *v3; // edi
  GRefCountNTSImpl *v4; // esi

  if ( DWORD1(n) != 0 )
  {
    v2 = (GRefCountNTSImpl **)DWORD2(n);
    v3 = (_WORD *)(n + 6);
    do
    {
      if ( (*v3 & 0x4000) != 0 )
      {
        if ( (*v3 & 0x2000) != 0 )
        {
          v4 = *v2;
          if ( (*v2)->__vftable-- == (GRefCountNTSImpl_vtbl *)1 )
          {
            GFxFontHandle::~GFxFontHandle(this: (CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *)v4);
            GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v4);
          }
          ++v2;
        }
        if ( (*v3 & 0x1000) != 0 )
          ++v2;
        if ( (*v3 & 0x800) != 0 )
          GRefCountNTSImpl::Release(this: *v2++);
      }
      v3 += 4;
      --DWORD1(n);
    }
    while ( DWORD1(n) != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10175CF0
// Name: public: void GFxTextLineBuffer::GlyphInserter::ResetTo(class GFxTextLineBuffer::GlyphInserter const __near &)
// Source: json
//------------------------------------------------------------------------------
IShaderAPI_vtbl *__userpurge GFxTextLineBuffer::GlyphInserter::ResetTo@<eax>(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this@<ecx>,
        int a2@<ebx>,
        IShaderAPI *savedPos,
        __int128 a4)
{
  IShaderAPI_vtbl *v5; // eax
  IShaderAPI_vtbl *v6; // ecx
  IShaderAPI_vtbl *result; // eax
  __int128 v8; // [esp-10h] [ebp-18h]

  v5 = *((IShaderAPI_vtbl **)this + 2);
  if ( savedPos[2].__vftable < v5 && *((_DWORD *)this + 3) != 0 )
  {
    v6 = savedPos[2].__vftable;
    HIDWORD(v8) = a2;
    DWORD2(v8) = (char *)savedPos[1].__vftable + 4 * (int)savedPos[4].__vftable;
    DWORD1(v8) = (char *)v5 - (char *)v6;
    GFxTextLineBuffer::ReleasePartOfLine(
      pglyphs: (CMatRenderContextBase *)((char *)savedPos->__vftable + 8 * (_DWORD)v6),
      n: v8);
  }
  this->m_pAllocator = (CMemoryStack *)savedPos->__vftable;
  *(this + 1) = (CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > >)savedPos[1].__vftable;
  *(this + 2) = (CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > >)savedPos[2].__vftable;
  *(this + 3) = (CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > >)savedPos[3].__vftable;
  result = savedPos[4].__vftable;
  *((_DWORD *)this + 4) = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10175D50
// Name: public: void GFxTextLineBuffer::Line::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall GFxTextLineBuffer::Line::Release(
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *this@<ecx>,
        int a2@<edi>)
{
  bool v3; // al
  char *v4; // edi
  unsigned int v5; // edx
  CMatRenderContextBase *v6; // ecx
  int v7; // eax
  __int128 v8; // [esp-10h] [ebp-14h]

  if ( ((int)this->m_pAllocator & 0x40000000) != 0 )
  {
    v3 = (int)this->m_pAllocator < 0;
    HIDWORD(v8) = a2;
    v4 = (char *)this + 30;
    if ( (int)this->m_pAllocator < 0 )
    {
      v5 = *((unsigned __int8 *)this + 28);
    }
    else
    {
      v4 = (char *)this + 42;
      v5 = *((_DWORD *)this + 1);
    }
    v6 = (CMatRenderContextBase *)((char *)this + 30);
    if ( v3 )
    {
      v7 = *((unsigned __int8 *)this + 28);
    }
    else
    {
      v7 = *((_DWORD *)this + 1);
      v6 = (CMatRenderContextBase *)((char *)this + 42);
    }
    DWORD2(v8) = ((unsigned int)&v6->CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >::IMatRenderContextInternal::IMatRenderContext::IRefCounted::__vftable
                + 8 * v7
                + 3)
               & 0xFFFFFFFC;
    *(_QWORD *)&v8 = __PAIR64__(v5, (unsigned int)v4);
    GFxTextLineBuffer::ReleasePartOfLine(pglyphs: v6, n: v8);
    if ( (int)this->m_pAllocator >= 0 )
      *((_DWORD *)this + 1) = 0;
    else
      *((_BYTE *)this + 28) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10175DC0
// Name: public: void GFxTextLineBuffer::TextLineAllocator::FreeLine(class GFxTextLineBuffer::Line __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxTextLineBuffer::TextLineAllocator::FreeLine(
        int a1@<edi>,
        CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *a2)
{
  if ( a2 != nullptr )
  {
    GFxTextLineBuffer::Line::Release(this: a2, a2: a1);
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10175DF0
// Name: private: void GFxTextLineBuffer::GlyphIterator::UpdateDesc(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxTextLineBuffer::GlyphIterator::UpdateDesc(_DWORD *this)
{
  GRefCountNTSImpl *v2; // ecx
  unsigned int Raw; // eax
  __int16 v4; // ax
  _DWORD *v5; // ebx
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v6; // edi
  unsigned int v8; // edx
  int *v9; // eax
  int v10; // ecx
  int v11; // edi
  GRefCountNTSImpl *v12; // ecx
  int v13; // edx
  int v15; // [esp+4h] [ebp-8h] BYREF
  int v16; // [esp+8h] [ebp-4h] BYREF

  v2 = (GRefCountNTSImpl *)*(this + 20);
  if ( v2 != nullptr )
    GRefCountNTSImpl::Release(this: v2);
  *(this + 20) = 0;
  Raw = *this;
  if ( *this != 0 && Raw < *(this + 1) )
  {
    v4 = *(_WORD *)(Raw + 6);
    if ( (v4 & 0x4000) != 0 )
    {
      if ( (v4 & 0x2000) != 0 )
      {
        v5 = *(_DWORD **)*(this + 2);
        if ( v5 != nullptr )
          ++*v5;
        v6 = (CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *)*(this + 19);
        if ( v6 != nullptr && LODWORD(v6->m_pfnProxied)-- == 1 )
        {
          GFxFontHandle::~GFxFontHandle(this: v6);
          GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v6);
        }
        *(this + 19) = v5;
        *(this + 2) += 4;
      }
      v8 = *this;
      if ( (*(_WORD *)(*this + 6) & 0x1000) != 0 )
      {
        v9 = (int *)*(this + 2);
        v10 = *v9;
        *(this + 16) = *v9;
        *(this + 17) = v10;
        *(this + 2) = v9 + 1;
      }
      if ( (*(_WORD *)(v8 + 6) & 0x800) != 0 )
      {
        v11 = *(_DWORD *)*(this + 2);
        if ( v11 != 0 )
          ++*(_DWORD *)(v11 + 4);
        v12 = (GRefCountNTSImpl *)*(this + 20);
        if ( v12 != nullptr )
          GRefCountNTSImpl::Release(this: v12);
        *(this + 20) = v11;
        *(this + 2) += 4;
      }
    }
    if ( (*(_WORD *)(*this + 6) & 0x400) != 0 )
    {
      v13 = *(this + 16);
      *(this + 21) = 1;
      *(this + 18) = v13;
    }
    else
    {
      *(this + 21) = 0;
    }
    if ( GFxTextHighlighterPosIterator::IsFinished(this: (GFxTextHighlighterPosIterator *)(this + 3)) )
    {
      Raw = *this;
      if ( (*(_WORD *)(*this + 6) & 0x400) == 0 )
        return Raw;
      *(this + 21) = 1;
      goto LABEL_35;
    }
    *(this + 16) = *(this + 17);
    Raw = *this;
    if ( (*(_WORD *)(*this + 4) & 0xF000) != 0 || (*(_BYTE *)(Raw + 6) & 8) != 0 )
    {
      if ( (*(_BYTE *)(this + 15) & 0x10) != 0 )
        *(this + 16) = *(_DWORD *)GFxTextHighlightInfo::GetTextColor(
                                    this: (GFxTextHighlightInfo *)(this + 12),
                                    a2: &v16).Raw;
      LOBYTE(Raw) = *((_BYTE *)this + 60);
      if ( (Raw & 7) != 0 )
        *(this + 21) = Raw & 7;
      if ( (*(_BYTE *)(this + 15) & 0x20) != 0 )
      {
        Raw = GFxTextHighlightInfo::GetUnderlineColor(this: (GFxTextHighlightInfo *)(this + 12), a2: &v15).Raw;
        *(this + 18) = *(_DWORD *)Raw;
        return Raw;
      }
LABEL_35:
      *(this + 18) = *(this + 16);
    }
  }
  return Raw;
}

//------------------------------------------------------------------------------
// Address: 0x10175FF0
// Name: public: GFxTextLineBuffer::GFxTextLineBuffer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextLineBuffer::GFxTextLineBuffer(CMatCallQueue *this)
{
  unsigned int v2; // [esp+8h] [ebp-4h]

  this->m_pHead = nullptr;
  this->m_pTail = nullptr;
  this->m_Allocator.m_pNextAlloc = nullptr;
  this->m_Allocator.m_pBase = nullptr;
  *(float *)&this->m_Allocator.m_bRegisteredAllocation = 0.0;
  *(float *)&this->m_Allocator.m_pszAllocOwner = 0.0;
  *(float *)&this->m_Allocator.m_maxSize = 0.0;
  *(float *)&this->m_Allocator.m_alignment = 0.0;
  this->m_Allocator.m_commitSize = 0;
  *(float *)&this->m_Allocator.m_minCommit = 0.0;
  *(float *)&this->m_FunctorFactory.m_pAllocator = 0.0;
  *(float *)&this->m_nCurSerialNumber = 0.0;
  *(float *)&this->m_nBreakSerialNumber = 0.0;
  *((float *)this + 15) = 0.0;
  *((float *)this + 16) = 0.0;
  *((float *)this + 17) = 0.0;
  *((float *)this + 18) = 0.0;
  *((float *)this + 19) = 0.0;
  *((float *)this + 20) = 0.0;
  *((float *)this + 21) = 0.0;
  *((float *)this + 22) = 0.0;
  *((float *)this + 23) = -1.0;
  *((float *)this + 24) = 0.0;
  *((float *)this + 25) = 0.0;
  *((_DWORD *)this + 28) = 0;
  *((float *)this + 26) = 0.0;
  *((_BYTE *)this + 116) = 0;
  *((float *)this + 27) = 0.0;
  *((_DWORD *)this + 30) = 0;
  *((_DWORD *)this + 31) = 0;
  *((_DWORD *)this + 32) = 0x100000;
  *((_DWORD *)this + 34) = 0;
  *((_DWORD *)this + 33) = 0;
  *((_DWORD *)this + 35) = 0x100000;
  *((_DWORD *)this + 36) = 0;
  *((_DWORD *)this + 37) = 0;
  *((_DWORD *)this + 38) = 0;
  *((_BYTE *)this + 156) = 0;
  GFxFillStyle::GFxFillStyle(this: (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),CFuncMemPolicyNone> *)((char *)this + 160));
  *((_DWORD *)this + 51) = 0;
  *((_DWORD *)this + 41) = -1;
  *(float *)&this->m_Allocator.m_bRegisteredAllocation = 0.0;
  *(float *)&this->m_Allocator.m_pszAllocOwner = 0.0;
  *(float *)&v2 = 0.0 + 0.0;
  this->m_Allocator.m_maxSize = v2;
  this->m_Allocator.m_alignment = v2;
  *((_DWORD *)this + 52) = -1;
  this->m_Allocator.m_pCommitLimit = nullptr;
  this->m_Allocator.m_pAllocLimit = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101760E0
// Name: public: class GFxTextLineBuffer::Line __near * GFxTextLineBuffer::InsertNewLine(unsigned int,unsigned int,unsigned int,enum GFxTextLineBuffer::LineType)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextLineBuffer::InsertNewLine(
        int this,
        MaterialVarFlags_t index,
        int a3,
        int a4,
        const char *(__thiscall *lineType)(struct CMaterial_QueueFriendly *this))
{
  int v6; // eax
  unsigned int v7; // [esp+0h] [ebp-Ch]
  unsigned int v8; // [esp+4h] [ebp-8h]

  GFxTextLineBuffer::TextLineAllocator::AllocLine(
    this: (GFxMovieView *)(this + 200),
    size: COERCE_FLOAT((((lineType != nullptr ? 0xC : 0) + 8 * a3 + 33) & 0xFFFFFFFC) + 4 * a4),
    lineType: *(float *)&lineType,
    a4: v7,
    a5: v8);
  lineType = (const char *(__thiscall *)(struct CMaterial_QueueFriendly *))v6;
  if ( v6 != 0 )
  {
    if ( *(int *)v6 >= 0 )
      *(_DWORD *)(v6 + 4) = a3;
    else
      *(_BYTE *)(v6 + 28) = a3;
    GArrayBase<GArrayData<GFxTextLineBuffer::Line *,GAllocatorLH<GFxTextLineBuffer::Line *,2>,GArrayDefaultPolicy>>::InsertAt(
      (CMaterial_QueueFriendly *)this,
      index,
      val: &lineType);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10176150
// Name: public: void GFxTextLineBuffer::Display(class GFxDisplayContext __near &,class GMatrix2D const __near &,class GRenderer::Cxform const __near &,bool,struct GFxTextFieldParam const __near &,class GFxTextHighlighter const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextLineBuffer::Display(
        CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > *this,
        int nextFrame,
        float *a3,
        GRenderer::Cxform *a4,
        char a5,
        IVJobs *textFieldParam,
        IVJobs *phighlighter)
{
  IVJobs_vtbl *v7; // edx
  IVJobs_vtbl *v9; // ecx
  IVJobs_vtbl *v10; // edx
  IVJobs_vtbl *v11; // ecx
  IVJobs_vtbl *v12; // edx
  IVJobs_vtbl *v13; // ecx
  IVJobs_vtbl *v14; // edx
  IVJobs_vtbl *v15; // ecx
  int v16; // eax
  float *v17; // ecx
  int v18; // eax
  char v19; // cl
  char v20; // dl
  float v21; // eax
  int v22; // edx
  double v23; // st3
  int v24; // eax
  int v25; // ecx
  unsigned int m_nAllocationCount; // edx
  double v27; // st7
  double v28; // st7
  float v29; // ecx
  double v30; // st6
  double v31; // st5
  double v32; // st4
  double v33; // st3
  double v34; // st2
  bool v35; // zf
  bool v36; // cf
  double v37; // rtt
  double v38; // st2
  double v39; // st3
  double v40; // rt0
  double v41; // st2
  double v42; // st4
  double v43; // rt1
  double v44; // st2
  double v45; // st5
  double v46; // rt2
  double v47; // st2
  double v48; // st6
  double v49; // rtt
  double v50; // st2
  double v51; // st7
  bool v52; // c3
  double v53; // st6
  bool v54; // c3
  double v55; // st7
  CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *v56; // edi
  float *v57; // esi
  double v58; // st7
  double v59; // st7
  double v60; // st6
  double v61; // st7
  double v62; // st6
  double v63; // st7
  double v64; // st1
  double v65; // st6
  char v66; // al
  GRefCountNTSImpl *v67; // ecx
  GFxFontCacheManagerImpl **m_Size; // eax
  IMaterialVar **m_pElements; // ecx
  CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *v70; // esi
  double v71; // st7
  IMaterialVar **v72; // ecx
  char v73; // dl
  signed int v74; // esi
  bool v75; // dl
  CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > *v76; // ecx
  IMaterialVar *v77; // edi
  CUtlSymbol *p_m_Name; // edx
  char *m_pStringVal; // eax
  CUtlSymbol *v80; // esi
  char *v81; // edx
  CUtlSymbol *v82; // ecx
  CUtlSymbol *v83; // eax
  __int16 *v84; // ebx
  CUtlSymbol *v85; // edx
  __int16 v86; // cx
  int v87; // edi
  int v88; // eax
  double v89; // st7
  double TextureGlyphMaxHeight; // st7
  bool v91; // al
  int v92; // ecx
  int v93; // eax
  int v94; // ecx
  CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *v95; // esi
  IClientTools **v96; // esi
  double v97; // st7
  IClientTools *v98; // edx
  IClientTools *v99; // eax
  IClientTools *v100; // ecx
  IClientTools *v101; // edx
  IClientTools *v102; // ecx
  IClientTools *v103; // ecx
  unsigned int v104; // ecx
  GMemoryHeap *v105; // eax
  IMaterialVar **v106; // ecx
  int v107; // eax
  int v108; // eax
  unsigned int v109; // eax
  char v110; // bl
  unsigned int v111; // esi
  IMaterialVar *v112; // ecx
  int v113; // eax
  double v114; // st7
  __int16 v115; // cx
  float v116; // eax
  int v117; // ebx
  double v118; // st7
  IClientTools **v119; // edi
  char v120; // dl
  double v121; // st7
  double v122; // st6
  int v123; // eax
  double v124; // st7
  GFxFontResource *v125; // esi
  struct GFxShapeBase *GlyphShape; // eax
  int v127; // eax
  __int16 v128; // si
  double v129; // st7
  GRefCountNTSImpl *v130; // esi
  GRefCountNTSImpl_vtbl *v131; // ecx
  float *v132; // esi
  float *v133; // edi
  int v134; // eax
  struct GFxFontHandle *v135; // esi
  GFxFontManager *v136; // ecx
  IShaderDevice *v137; // ecx
  IShaderDevice *v138; // ecx
  IShaderDevice *v139; // ecx
  volatile LONG *v140; // edi
  IClientTools *v141; // ecx
  IClientTools *v142; // edx
  double v143; // st7
  bool v144; // cl
  double v145; // st7
  double v146; // st7
  IClientTools **v147; // ebx
  unsigned int v148; // esi
  CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *v149; // edi
  int v150; // esi
  double v151; // st7
  unsigned __int16 *v152; // ecx
  unsigned __int16 v153; // dx
  float v154; // eax
  double BaseLineOffset; // st7
  double v156; // st7
  float v157; // edi
  float v158; // ebx
  int v159; // eax
  struct GFxFontHandle *v160; // esi
  GFxFontManager *v161; // ecx
  IShaderDevice *v162; // ecx
  IShaderDevice *v163; // ecx
  IShaderDevice *v164; // ecx
  volatile LONG *v165; // edi
  IClientTools **v166; // esi
  IClientTools *v167; // ecx
  CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *v168; // edi
  int v169; // [esp+10h] [ebp-270h]
  CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *v170; // [esp+18h] [ebp-268h]
  __int128 v171; // [esp+28h] [ebp-258h]
  unsigned int v172; // [esp+28h] [ebp-258h]
  int v173; // [esp+2Ch] [ebp-254h]
  int v174; // [esp+2Ch] [ebp-254h]
  int v175; // [esp+2Ch] [ebp-254h]
  int v176; // [esp+2Ch] [ebp-254h]
  int v177; // [esp+2Ch] [ebp-254h]
  int v178; // [esp+2Ch] [ebp-254h]
  int v179; // [esp+2Ch] [ebp-254h]
  int v180; // [esp+2Ch] [ebp-254h]
  CCountedStringPoolBase<unsigned int>::hash_item_t result; // [esp+38h] [ebp-248h] BYREF
  const float *v182; // [esp+44h] [ebp-23Ch]
  GFxTextHighlighterPosIterator v183; // [esp+4Ch] [ebp-234h] BYREF
  float v184; // [esp+88h] [ebp-1F8h]
  int v185; // [esp+8Ch] [ebp-1F4h]
  GRefCountNTSImpl *v186; // [esp+90h] [ebp-1F0h]
  float v187; // [esp+94h] [ebp-1ECh]
  int v188; // [esp+98h] [ebp-1E8h]
  CCountedStringPoolBase<unsigned int>::hash_item_t v189; // [esp+9Ch] [ebp-1E4h] BYREF
  IClientTools *v190; // [esp+A8h] [ebp-1D8h]
  IClientTools *v191; // [esp+ACh] [ebp-1D4h]
  IClientTools *v192; // [esp+B0h] [ebp-1D0h]
  IClientTools *v193; // [esp+B4h] [ebp-1CCh]
  IClientTools *v194; // [esp+B8h] [ebp-1C8h]
  IClientTools *v195; // [esp+BCh] [ebp-1C4h]
  __int16 v196; // [esp+C0h] [ebp-1C0h]
  __int16 v197; // [esp+C2h] [ebp-1BEh]
  IClientTools *v198; // [esp+C4h] [ebp-1BCh]
  char v199; // [esp+C8h] [ebp-1B8h]
  float *v200; // [esp+CCh] [ebp-1B4h]
  float v201; // [esp+D4h] [ebp-1ACh] BYREF
  float v202; // [esp+D8h] [ebp-1A8h]
  float v203; // [esp+DCh] [ebp-1A4h]
  float v204; // [esp+E0h] [ebp-1A0h]
  IVJobs *v205; // [esp+E4h] [ebp-19Ch]
  float v206; // [esp+E8h] [ebp-198h] BYREF
  float v207; // [esp+ECh] [ebp-194h]
  int v208; // [esp+F0h] [ebp-190h] BYREF
  IVJobs *v209; // [esp+F4h] [ebp-18Ch]
  IClientTools *v210; // [esp+F8h] [ebp-188h]
  float v211; // [esp+FCh] [ebp-184h]
  float v212; // [esp+100h] [ebp-180h]
  GRenderer::Cxform *v213; // [esp+104h] [ebp-17Ch]
  float v214; // [esp+108h] [ebp-178h]
  GRefCountNTSImpl *v215; // [esp+10Ch] [ebp-174h]
  float v216; // [esp+110h] [ebp-170h]
  float v217; // [esp+114h] [ebp-16Ch] BYREF
  int nNextElement; // [esp+118h] [ebp-168h]
  CCountedStringPoolBase<unsigned int>::hash_item_t v219; // [esp+11Ch] [ebp-164h] BYREF
  float v220; // [esp+128h] [ebp-158h]
  char v221; // [esp+12Eh] [ebp-152h]
  char v222; // [esp+12Fh] [ebp-151h]
  float v223; // [esp+130h] [ebp-150h] BYREF
  float v224; // [esp+134h] [ebp-14Ch]
  CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *v225; // [esp+138h] [ebp-148h]
  float v226; // [esp+13Ch] [ebp-144h]
  IClientTools **v227; // [esp+140h] [ebp-140h]
  CCountedStringPoolBase<unsigned int>::hash_item_t p; // [esp+144h] [ebp-13Ch] BYREF
  float x; // [esp+150h] [ebp-130h]
  char v230; // [esp+157h] [ebp-129h]
  double v231; // [esp+158h] [ebp-128h] BYREF
  unsigned __int16 v232; // [esp+162h] [ebp-11Eh]
  float v233; // [esp+164h] [ebp-11Ch]
  CUtlSymbol *v234; // [esp+168h] [ebp-118h] BYREF
  unsigned int v235; // [esp+16Ch] [ebp-114h]
  unsigned int v236; // [esp+170h] [ebp-110h]
  float v237[17]; // [esp+174h] [ebp-10Ch] BYREF
  GRefCountNTSImpl *v238; // [esp+1B8h] [ebp-C8h]
  int v239; // [esp+1BCh] [ebp-C4h]
  int v240; // [esp+1C0h] [ebp-C0h]
  GRenderer::Cxform v241; // [esp+1C4h] [ebp-BCh] BYREF
  struct GRenderer::Cxform v242; // [esp+1E4h] [ebp-9Ch] BYREF
  struct GMatrix2D v243; // [esp+204h] [ebp-7Ch] BYREF
  float v244; // [esp+21Ch] [ebp-64h] BYREF
  float v245; // [esp+220h] [ebp-60h]
  float v246; // [esp+224h] [ebp-5Ch]
  float v247; // [esp+228h] [ebp-58h]
  float v248; // [esp+22Ch] [ebp-54h]
  float v249; // [esp+230h] [ebp-50h]
  struct GMatrix2D v250; // [esp+234h] [ebp-4Ch] BYREF
  GMatrix2D v251; // [esp+24Ch] [ebp-34h] BYREF
  struct GMatrix2D v252; // [esp+264h] [ebp-1Ch] BYREF

  v213 = a4;
  *(float *)&v219.nReferenceCount = 1.25;
  v7 = textFieldParam->__vftable;
  v205 = phighlighter;
  v9 = textFieldParam[1].__vftable;
  *(_DWORD *)&v189.nReferenceCount = v7;
  v10 = textFieldParam[2].__vftable;
  v190 = (IClientTools *)v9;
  v11 = textFieldParam[3].__vftable;
  v191 = (IClientTools *)v10;
  v12 = textFieldParam[4].__vftable;
  v192 = (IClientTools *)v11;
  v13 = textFieldParam[5].__vftable;
  v193 = (IClientTools *)v12;
  v14 = textFieldParam[6].__vftable;
  v194 = (IClientTools *)v13;
  LOWORD(v13) = textFieldParam[7].__vftable;
  v195 = (IClientTools *)v14;
  LOWORD(v14) = HIWORD(textFieldParam[7].__vftable);
  v196 = (__int16)v13;
  v15 = textFieldParam[8].__vftable;
  v197 = (__int16)v14;
  LOBYTE(v14) = textFieldParam[9].__vftable;
  v16 = *(_DWORD *)(nextFrame + 72);
  v198 = (IClientTools *)v15;
  v199 = (char)v14;
  v17 = *(float **)(v16 + 12);
  v18 = *(_DWORD *)(nextFrame + 96);
  v200 = v17;
  v227 = (IClientTools **)this;
  v225 = (CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *)nextFrame;
  v230 = 0;
  v222 = 0;
  v221 = 0;
  x = 0.0;
  if ( v18 != 0 )
  {
    this->m_pElements = *(IMaterialVar ***)(v18 + 72);
    v19 = *(_BYTE *)(v18 + 40);
    *(float *)&v219.nReferenceCount = *(float *)(v18 + 44);
    v20 = *(_BYTE *)(v18 + 41);
    v21 = *(float *)(v18 + 48);
    v230 = v19;
    v222 = v20;
    x = v21;
  }
  else
  {
    this->m_pElements = nullptr;
  }
  v252.M_[0][0] = *a3;
  v252.M_[0][1] = a3[1];
  v252.M_[0][2] = a3[2];
  v252.M_[1][0] = a3[3];
  v252.M_[1][1] = a3[4];
  v252.M_[1][2] = a3[5];
  if ( (_S3_3 & 1) == 0 )
  {
    _S3_3 |= 1u;
    byte_10359960 = 0;
    GMatrix3D::SetIdentity(this: &stru_10359964);
    byte_103599A4 = 0;
  }
  if ( v222 != 0 )
  {
    TextUtil3D::Init(this: (TextUtil3D *)&text3D);
    TextUtil3D::BeginDisplay(this: (TextUtil3D *)&text3D, a2: (const struct GFxDisplayContext *)nextFrame, a3: &v252);
  }
  v22 = *((_DWORD *)this + 10);
  v244 = v252.M_[0][0];
  v245 = v252.M_[0][1];
  v247 = v252.M_[1][0];
  v248 = v252.M_[1][1];
  v23 = (double)*((int *)this + 10);
  if ( v22 < 0 )
    v23 = v23 + 4294967300.0;
  v24 = *((_DWORD *)this + 5);
  v233 = -v23;
  v25 = 0;
  v246 = v252.M_[0][1] * 0.0 + v252.M_[0][0] * v233 + v252.M_[0][2];
  v249 = 0.0 * v252.M_[1][1] + v233 * v252.M_[1][0] + v252.M_[1][2];
  if ( v24 != 0 )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    if ( v24 < m_nAllocationCount && v24 >= 0 && m_nAllocationCount != 0 )
      v25 = LODWORD(this->m_Memory.m_pMemory[v24]->m_VecVal.y) - LODWORD((*this->m_Memory.m_pMemory)->m_VecVal.y);
  }
  HIDWORD(v231) = v25;
  v214 = -(double)(unsigned int)v25;
  v27 = *(float *)(nextFrame + 136) * 20.0;
  v233 = v27;
  GFx_CalcHeightRatio_GMatrix2D_(a1: (int)&v252);
  v226 = v27 * v233;
  if ( v226 < 0.001 )
    v226 = 0.001;
  v28 = v252.M_[1][2];
  v29 = x;
  v30 = v252.M_[1][1];
  v31 = v252.M_[1][0];
  v32 = v252.M_[0][2];
  v33 = v252.M_[0][1];
  v34 = v252.M_[0][0];
  if ( x != 0.0 && (HIBYTE(v190) & 1) == 0 )
  {
    if ( *((float *)this + 11) == v34
      && *((float *)this + 12) == v33
      && *((float *)this + 13) == v32
      && *((float *)this + 14) == v31
      && *((float *)this + 15) == v30
      && *((float *)this + 16) == v28 )
    {
      if ( a5 != 0 )
      {
        v36 = ++*((_DWORD *)this + 28) < LODWORD(v29);
        if ( *((_DWORD *)this + 28) <= LODWORD(v29) )
        {
LABEL_31:
          if ( !v36 )
          {
            HIBYTE(v190) |= 1u;
            HIBYTE(v193) |= 1u;
            if ( (*((_BYTE *)this + 116) & 8) == 0 )
              *((_BYTE *)this + 116) |= 9u;
          }
          goto LABEL_34;
        }
        *((float *)this + 28) = v29;
      }
    }
    else
    {
      v35 = (*((_BYTE *)this + 116) & 8) == 0;
      *((_DWORD *)this + 28) = 0;
      if ( !v35 )
      {
        *((_BYTE *)this + 116) |= 1u;
        *((_BYTE *)this + 116) &= ~8u;
      }
    }
    v36 = *((_DWORD *)this + 28) < LODWORD(v29);
    goto LABEL_31;
  }
LABEL_34:
  v243.M_[0][0] = v34;
  v37 = v34;
  v38 = v33;
  v39 = v37;
  v243.M_[0][1] = v38;
  v40 = v38;
  v41 = v32;
  v42 = v40;
  v243.M_[0][2] = v41;
  v43 = v41;
  v44 = v31;
  v45 = v43;
  v243.M_[1][0] = v44;
  v46 = v44;
  v47 = v30;
  v48 = v46;
  v243.M_[1][1] = v47;
  v49 = v47;
  v50 = v28;
  v51 = v49;
  v243.M_[1][2] = v50;
  if ( (HIBYTE(v190) & 1) == 0 )
  {
    v56 = (CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *)(nextFrame + 120);
    v57 = (float *)((char *)this + 68);
    if ( *(float *)(nextFrame + 120) != *((float *)this + 17)
      || *(float *)(nextFrame + 124) != *((float *)this + 18)
      || *(float *)(nextFrame + 128) != *((float *)this + 19)
      || *(float *)(nextFrame + 132) != *((float *)this + 20)
      || *(float *)(nextFrame + 136) != *((float *)this + 21)
      || (v64 = *((float *)this + 22), HIBYTE(v232) = 0, *(float *)(nextFrame + 140) != v64) )
    {
      HIBYTE(v232) = 1;
    }
    if ( (*((_BYTE *)this + 116) & 0x10) != 0 && *((float *)this + 23) != v226 )
      HIBYTE(v232) = 1;
    *((float *)this + 11) = v39;
    *((float *)this + 12) = v42;
    *((float *)this + 13) = v45;
    *((float *)this + 14) = v48;
    v65 = v51;
    v63 = v50;
    *((float *)this + 15) = v65;
    goto LABEL_63;
  }
  if ( *((float *)this + 11) != v39
    || *((float *)this + 12) != v42
    || *((float *)this + 13) != v45
    || (v52 = *((float *)this + 14) == v48, v53 = v50, !v52)
    || (v54 = *((float *)this + 15) == v51, v55 = v45, !v54)
    || *((float *)this + 16) != v50
    || (v56 = (CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *)(nextFrame + 120),
        v57 = (float *)((char *)this + 68),
        *((float *)this + 17) != *(float *)(nextFrame + 120))
    || *((float *)this + 18) != *(float *)(nextFrame + 124)
    || *((float *)this + 19) != *(float *)(nextFrame + 128)
    || *((float *)this + 20) != *(float *)(nextFrame + 132)
    || *((float *)this + 21) != *(float *)(nextFrame + 136)
    || *((float *)this + 22) != *(float *)(nextFrame + 140) )
  {
    *(float *)&p.nReferenceCount = *((float *)this + 6);
    v57 = (float *)((char *)this + 68);
    x = *((float *)this + 7);
    p.pString = *((char **)this + 8);
    p.nNextElement = *((unsigned int *)this + 7);
    v223 = *((float *)this + 8);
    v224 = *((float *)this + 9);
    v217 = *(float *)&p.nReferenceCount;
    *(float *)&nNextElement = x;
    *(float *)&v231 = *(float *)&p.pString;
    *((float *)&v231 + 1) = *(float *)&p.nNextElement;
    v206 = v223;
    v207 = v224;
    v233 = *(float *)&p.nReferenceCount;
    *(float *)&p.nReferenceCount = *(float *)&p.nReferenceCount * *((float *)this + 11) + x * *((float *)this + 12);
    x = x * *((float *)this + 15) + v233 * *((float *)this + 14);
    GMatrix2D::Transform(
      this: (CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *)((char *)this + 68),
      result: &v219,
      p: (float *)&p.nReferenceCount,
      p_4: SDWORD1(v171));
    *(float *)&p.nReferenceCount = *(float *)&v219.pString;
    x = *(float *)&v219.nNextElement;
    v233 = *(float *)&p.pString;
    *(float *)&p.pString = *(float *)&p.pString * *((float *)this + 11)
                         + *(float *)&p.nNextElement * *((float *)this + 12);
    *(float *)&p.nNextElement = *(float *)&p.nNextElement * *((float *)this + 15) + v233 * *((float *)this + 14);
    GMatrix2D::Transform(
      this: (CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *)((char *)this + 68),
      result: &v219,
      (float *)&p,
      p_4: v173);
    p.pString = v219.pString;
    p.nNextElement = v219.nNextElement;
    v233 = v223;
    v223 = v223 * *((float *)this + 11) + v224 * *((float *)this + 12);
    v224 = v224 * *((float *)this + 15) + v233 * *((float *)this + 14);
    GMatrix2D::Transform(
      this: (CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *)((char *)this + 68),
      result: &v219,
      p: &v223,
      p_4: v174);
    v223 = *(float *)&v219.pString;
    v224 = *(float *)&v219.nNextElement;
    v56 = v225 + 6;
    v233 = v217;
    v217 = v217 * v252.M_[0][0] + *(float *)&nNextElement * v252.M_[0][1];
    *(float *)&nNextElement = *(float *)&nNextElement * v252.M_[1][1] + v233 * v252.M_[1][0];
    GMatrix2D::Transform(this: v225 + 6, result: &v219, p: &v217, p_4: v175);
    v217 = *(float *)&v219.pString;
    nNextElement = v219.nNextElement;
    v233 = *(float *)&v231;
    *(float *)&v231 = *(float *)&v231 * v252.M_[0][0] + *((float *)&v231 + 1) * v252.M_[0][1];
    *((float *)&v231 + 1) = *((float *)&v231 + 1) * v252.M_[1][1] + v233 * v252.M_[1][0];
    GMatrix2D::Transform(this: v56, result: &v219, p: (float *)&v231, p_4: v176);
    *(float *)&v231 = *(float *)&v219.pString;
    *((float *)&v231 + 1) = *(float *)&v219.nNextElement;
    v233 = v206;
    v206 = v206 * v252.M_[0][0] + v207 * v252.M_[0][1];
    v207 = v207 * v252.M_[1][1] + v233 * v252.M_[1][0];
    GMatrix2D::Transform(this: v56, result: &v219, p: &v206, p_4: v177);
    v233 = *(float *)&p.pString - *(float *)&v231;
    v233 = fabs(v233);
    v58 = v233;
    v233 = *(float *)&p.nNextElement - *((float *)&v231 + 1);
    v233 = fabs(v233);
    v233 = v58 + v233;
    v59 = v233;
    v233 = *(float *)&p.nReferenceCount - v217;
    v233 = fabs(v233);
    v60 = v233;
    v233 = x - *(float *)&nNextElement;
    v233 = fabs(v233);
    v233 = v60 + v233;
    v61 = v59 + v233;
    v233 = v223 - *(float *)&v219.pString;
    v233 = fabs(v233);
    v62 = v233;
    v233 = v224 - *(float *)&v219.nNextElement;
    v233 = fabs(v233);
    v233 = v62 + v233;
    v233 = v61 + v233;
    if ( v233 <= 0.30000001 )
    {
      HIBYTE(v232) = 0;
      v53 = v252.M_[1][2];
      v55 = v252.M_[0][2];
      goto LABEL_51;
    }
    HIBYTE(v232) = 1;
    *((float *)this + 11) = v252.M_[0][0];
    *((float *)this + 12) = v252.M_[0][1];
    *((float *)this + 13) = v252.M_[0][2];
    *((float *)this + 14) = v252.M_[1][0];
    *((float *)this + 15) = v252.M_[1][1];
    v63 = v252.M_[1][2];
LABEL_63:
    *((float *)this + 16) = v63;
    goto LABEL_64;
  }
  HIBYTE(v232) = 0;
LABEL_51:
  v243.M_[0][0] = *((float *)this + 11);
  v243.M_[0][1] = *((float *)this + 12);
  v243.M_[1][0] = *((float *)this + 14);
  v243.M_[1][1] = *((float *)this + 15);
  *(float *)&p.pString = v55 - *((float *)this + 24);
  *(float *)&p.nNextElement = v53 - *((float *)this + 25);
  x = *(float *)&v56->m_Memory.m_pMemory;
  nNextElement = (int)v225[6].m_pElements;
  v233 = *(float *)&p.pString * x + 0.5;
  v233 = floor(X: v233);
  v243.M_[0][2] = v233 / x + *((float *)this + 24);
  v233 = *(float *)&p.nNextElement * *(float *)&nNextElement + 0.5;
  v233 = floor(X: v233);
  v243.M_[1][2] = v233 / *(float *)&nNextElement + *((float *)this + 25);
LABEL_64:
  v35 = v205 == nullptr;
  *((float *)this + 23) = v226;
  *v57 = *(float *)&v56->m_Memory.m_pMemory;
  v57[1] = *(float *)&v56->m_Memory.m_nAllocationCount;
  v57[2] = *(float *)&v56->m_Memory.m_nGrowSize;
  v57[3] = *(float *)&v56->m_Size;
  v57[4] = *(float *)&v56->m_pElements;
  v57[5] = *(float *)&v56[1].m_Memory.m_pMemory;
  if ( !v35 )
  {
    GFxTextHighlighter::HasUnderlineHighlight(this: v205);
    v35 = LOBYTE(v205[6].__vftable) == 0;
    v221 = v66;
    if ( v35 )
      *((_BYTE *)this + 116) |= 1u;
  }
  if ( (*((_BYTE *)this + 116) & 1) != 0 || HIBYTE(v232) != 0 || *((_DWORD *)this + 52) != *((_DWORD *)this + 10) )
  {
    v67 = *((GRefCountNTSImpl **)this + 51);
    if ( v67 != nullptr )
      GRefCountNTSImpl::Release(this: v67);
    *((_DWORD *)this + 51) = 0;
  }
  if ( (*((_BYTE *)this + 116) & 1) == 0
    && GFxTextFieldParam::operator==(this: &v189.nReferenceCount, key: (IVJobs *)this + 30)
    && HIBYTE(v232) == 0
    && (m_Size = (GFxFontCacheManagerImpl **)this->m_Size) != nullptr
    && (m_pElements = this->m_pElements) != nullptr )
  {
    v70 = v225;
    if ( v225[7].m_Memory.m_nGrowSize == 0 && *((_DWORD *)this + 52) == *((_DWORD *)this + 10) )
    {
      v71 = (HIBYTE(v190) & 1) != 0 ? 0.0 : v226;
      x = v71;
      if ( GFxFontCacheManagerImpl::VerifyBatchPackage(
             this: (GFxFontCacheManagerImpl *)m_pElements,
             a2: m_Size,
             a3: (struct GFxDisplayContext *)v225,
             a4: x) != 0 )
        goto LABEL_89;
    }
  }
  else
  {
    v70 = v225;
  }
  v72 = this->m_pElements;
  if ( v72 != nullptr )
    GFxFontCacheManagerImpl::ReleaseBatchPackage(
      this: (_RTL_CRITICAL_SECTION *)v72,
      a2: (struct GFxBatchPackage *)this->m_Size);
  this->m_Size = 0;
  *((_BYTE *)this + 116) &= ~1u;
LABEL_89:
  *((_DWORD *)this + 52) = *((_DWORD *)this + 10);
  v220 = 0.0;
  if ( this->m_Size == 0 && v70[7].m_Memory.m_nGrowSize == 0 )
  {
    *((_BYTE *)this + 116) &= ~2u;
    v73 = *((_BYTE *)this + 116);
    v211 = v214;
    v74 = *((_DWORD *)this + 5);
    v75 = (v73 & 4) != 0;
    *((_BYTE *)this + 116) &= ~0x10u;
    v76 = this;
    v208 = (int)this;
    v209 = nullptr;
    LOBYTE(v212) = v75;
LABEL_92:
    v210 = (IClientTools *)v74;
LABEL_93:
    if ( v76 != nullptr
      && (unsigned int)v74 < v76->m_Memory.m_nAllocationCount
      && v74 >= 0
      && (v75 || GFxTextLineBuffer::IsLineVisible(this: v76, lineIndex: v74, yOffset: v211)) )
    {
      v77 = v76->m_Memory.m_pMemory[v74];
      p_m_Name = &v77->m_Name;
      if ( (int)v77->__vftable < 0 )
      {
        m_pStringVal = (char *)*((unsigned __int8 *)v77 + 28);
      }
      else
      {
        p_m_Name = (CUtlSymbol *)&v77[1].m_intVal + 1;
        m_pStringVal = v77->m_pStringVal;
      }
      v80 = &p_m_Name[4 * (_DWORD)m_pStringVal];
      if ( (int)v77->__vftable >= 0 )
        v81 = v77->m_pStringVal;
      else
        v81 = (char *)*((unsigned __int8 *)v77 + 28);
      v82 = &v77->m_Name;
      if ( (int)v77->__vftable >= 0 )
        v82 = (CUtlSymbol *)&v77[1].m_intVal + 1;
      v234 = v82;
      v237[3] = NAN;
      v237[4] = 0.0;
      v237[5] = NAN;
      memset(&v237[6], 0, 25);
      v237[2] = 0.0;
      v237[1] = 0.0;
      memset(&v237[13], 0, 16);
      v238 = nullptr;
      v239 = 0;
      v240 = 0;
      v235 = (unsigned int)&v82[4 * (_DWORD)v81];
      v236 = ((unsigned int)&v80[1].m_Id + 1) & 0xFFFFFFFC;
LABEL_107:
      GFxTextLineBuffer::GlyphIterator::UpdateDesc(this: &v234);
      v83 = v234;
      while ( 1 )
      {
        if ( v83 == nullptr || (unsigned int)v83 >= v235 )
        {
LABEL_141:
          if ( v238 != nullptr )
            GRefCountNTSImpl::Release(this: v238);
          if ( LODWORD(v237[16]) != 0 )
          {
            v95 = (CMemberFuncProxy1<CMaterialVar *,void (__thiscall CMaterialVar::*)(IMaterial *),IMaterial *,CFuncMemPolicyNone> *)LODWORD(v237[16]);
            --*(_DWORD *)LODWORD(v237[16]);
            if ( LODWORD(v95->m_pfnProxied) == 0 )
            {
              GFxFontHandle::~GFxFontHandle(this: v95);
              GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v95);
            }
          }
          v74 = (signed int)v210;
          v76 = (CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > *)v208;
          v75 = LOBYTE(v212);
          if ( (unsigned int)v210 < *(_DWORD *)(v208 + 4) )
          {
            v74 = (signed int)&v210->__vftable + 1;
            goto LABEL_92;
          }
          goto LABEL_93;
        }
        v84 = (__int16 *)&v83[3];
        v85 = v83;
        v83[3].m_Id &= ~0x8000u;
        if ( v239 != 0 )
          *((_BYTE *)v227 + 116) |= 2u;
        if ( v83->m_Id != 0xFFFF )
        {
          nNextElement = v83->m_Id;
          v86 = *v84;
          if ( (*v84 & 0x200) == 0 && v238 == nullptr )
          {
            v87 = LODWORD(v237[16]) != 0 ? *(_DWORD *)(LODWORD(v237[16]) + 28) : 0;
            v88 = v83[2].m_Id & 0xFFF;
            HIDWORD(v231) = v85[2].m_Id & 0xFFF;
            v89 = (v86 & 0x10) != 0 ? (double)(unsigned int)v88 * 0.0625 : (double)(unsigned int)v88;
            x = v89;
            LODWORD(v233) = v232 | 0xC00;
            *(_QWORD *)&v189.pString = (__int64)x;
            if ( v189.pString != nullptr )
            {
              if ( *(_DWORD *)(v87 + 16) != 0 )
              {
                HIDWORD(v231) = (__int64)x;
                v233 = (double)(unsigned int)v189.pString * v226;
                TextureGlyphMaxHeight = GFxFontPackParams::GetTextureGlyphMaxHeight(a1: v87);
                if ( v233 <= TextureGlyphMaxHeight * *(float *)&v219.nReferenceCount
                  || (*(_DWORD *)(*(_DWORD *)(v87 + 12) + 20) & 0x1000) != 0 )
                {
                  *((_BYTE *)v227 + 116) |= 0x10u;
                  v91 = true;
                }
                else
                {
                  v91 = false;
                  *((_BYTE *)v227 + 116) |= 0x10u;
                }
              }
              else
              {
                if ( v230 == 0 || v227[4] == nullptr )
                {
LABEL_132:
                  *((_BYTE *)v227 + 116) |= 0x10u;
                  goto LABEL_133;
                }
                v92 = *(_DWORD *)(v87 + 12);
                v201 = 0.0;
                v202 = 0.0;
                v203 = 0.0;
                v204 = 0.0;
                v93 = (*(int (__thiscall **)(int, int, float *))(*(_DWORD *)v92 + 48))(
                        a1: v92,
                        a2: nNextElement,
                        a3: &v201);
                v91 = GFxFontCacheManagerImpl::GlyphFits(
                        this: v227[4],
                        a2: v93,
                        a3: (int)v189.pString,
                        a4: v226,
                        a5: &v189.nReferenceCount,
                        a6: *(float *)&v219.nReferenceCount);
              }
              if ( !v91 )
                goto LABEL_132;
              *v84 |= 0x8000u;
              ++LODWORD(v220);
            }
          }
        }
LABEL_133:
        v83 = v234;
        if ( v234 == nullptr )
          goto LABEL_141;
        if ( (unsigned int)v234 < v235 )
        {
          v94 = v240;
          if ( v240 == 0 )
          {
            v94 = v234[2].m_Id >> 12;
            v240 = v94;
          }
          v234 += 4;
          if ( (v234[2].m_Id & 0xF000) != 0
            && v94 != 0
            && !GFxTextHighlighterPosIterator::IsFinished(this: (GFxTextHighlighterPosIterator *)v237) )
          {
            GFxTextHighlighterPosIterator::operator+=(
              this: (CMemberFunctor1<CMaterialSystem *,void (__thiscall CMaterialSystem::*)(CMatQueuedRenderContext *),CMatQueuedRenderContext *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *)v237,
              p: v240);
            v240 = 0;
          }
          goto LABEL_107;
        }
      }
    }
    v96 = v227;
    v97 = v214;
    v203 = v214;
    v98 = v190;
    v99 = v191;
    v227[30] = *(IClientTools **)&v189.nReferenceCount;
    v100 = v192;
    v96[31] = v98;
    v101 = v193;
    v96[33] = v100;
    v102 = v195;
    v96[34] = v101;
    LOWORD(v101) = v196;
    v96[32] = v99;
    v96[35] = v194;
    LOWORD(v99) = v197;
    v96[36] = v102;
    v103 = v198;
    *((_WORD *)v96 + 74) = (_WORD)v101;
    LOBYTE(v101) = v199;
    *((_WORD *)v96 + 75) = (_WORD)v99;
    v96[38] = v103;
    *((_BYTE *)v96 + 156) = (_BYTE)v101;
    LOBYTE(v101) = *((_BYTE *)v96 + 116);
    v219.pString = *((char **)v96 + 6);
    v104 = (unsigned int)v96[5];
    *(float *)&v219.nNextElement = v97 + *((float *)v96 + 7);
    LOBYTE(v204) = ((unsigned __int8)v101 & 4) != 0;
    v210 = (IClientTools *)v104;
    v208 = (int)v96;
    v209 = nullptr;
    v211 = v203;
    v212 = v204;
    if ( v96[4] != nullptr )
    {
      v172 = LODWORD(v220);
      v209 = v205;
      v170 = v225;
      v169 = (int)v96[3];
      v105 = GMemory::pGlobalHeap->GetAllocHeap(this: GMemory::pGlobalHeap, a2: v96);
      v96[3] = (IClientTools *)GFxFontCacheManagerImpl::CreateBatchPackage(
                                 this: (GFxFontCacheManagerImpl *)v96[4],
                                 a2: (int)v105,
                                 a3: v169,
                                 a4: (int)&v208,
                                 a5: (int)v170,
                                 a6: (float *)&v219,
                                 a7: (int)(v96 + 5),
                                 a8: (int)&v189.nReferenceCount,
                                 a9: v172);
    }
    this = (CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > *)v96;
    v96[24] = (IClientTools *)LODWORD(v252.M_[0][2]);
    v96[25] = (IClientTools *)LODWORD(v252.M_[1][2]);
    v70 = v225;
  }
  v106 = this->m_pElements;
  HIBYTE(v232) = 0;
  if ( v106 != nullptr )
    GFxFontCacheManagerImpl::DisplayBatchPackage(
      this: (GFxFontCacheManagerImpl *)v106,
      a2: (struct GFxBatchPackage *)this->m_Size,
      a3: (struct GFxDisplayContext *)v70,
      a4: &v243,
      a5: v213);
  if ( this->m_pElements != nullptr )
  {
    v107 = this->m_Size;
    if ( v107 != 0 )
    {
      v108 = *(_DWORD *)(v107 + 8);
      if ( v108 == 0 || *(_BYTE *)(v108 + 76) == 0 )
        goto LABEL_256;
      v70 = v225;
    }
  }
  if ( GFxTextLineBuffer::IsPartiallyVisible(this, yOffset: (IMaterialVar *const *)LODWORD(v214)) != 0 )
    HIBYTE(v232) = GFxTextLineBuffer::DrawMask(
                     rect: v70,
                     a2: (float *)&v252,
                     a3: (float *)this + 6,
                     a4: v70[7].m_pElements != nullptr);
  v109 = *((_DWORD *)this + 5);
  v110 = *((_BYTE *)this + 116);
  v201 = 0.0;
  v202 = 0.0;
  v203 = 0.0;
  v204 = 0.0;
  v241 = *v213;
  v210 = (IClientTools *)v109;
  LOBYTE(v212) = (v110 & 4) != 0;
LABEL_161:
  v111 = (unsigned int)v210;
  this = (CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > *)v227;
  if ( v210 < v227[1]
    && (int)v210 >= 0
    && (LOBYTE(v212) != 0
     || GFxTextLineBuffer::IsLineVisible(
          this: (CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > *)v227,
          lineIndex: (unsigned int)v210,
          yOffset: v214)) )
  {
    v112 = this->m_Memory.m_pMemory[v111];
    v113 = (int)v112->__vftable;
    x = v112->m_VecVal.x;
    v114 = (double)SLODWORD(x);
    x = v112->m_VecVal.y;
    *(float *)&p.pString = v114;
    *(float *)&p.nNextElement = (float)SLODWORD(x);
    v223 = *((float *)this + 6);
    v224 = *((float *)this + 7);
    *(float *)&p.pString = *(float *)&p.pString + v223;
    *(float *)&p.nNextElement = v224 + *(float *)&p.nNextElement;
    if ( v113 >= 0 )
      LODWORD(v233) = HIWORD(v112[1].m_pStringVal);
    else
      LODWORD(v233) = HIWORD(v112->m_VecVal.w);
    x = (float)SLODWORD(v233);
    LODWORD(v171) = v205;
    *(float *)&p.nNextElement = x + v214 + *(float *)&p.nNextElement;
    GFxTextLineBuffer::Line::Begin(
      this: (CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *)v112,
      phighlighter: (CMatRenderContextBase *)&result.nReferenceCount,
      a3: v171,
      a4: (ITexture *const *)result.pString,
      a5: (const float *)result.nNextElement,
      a6: *(const float **)&result.nReferenceCount,
      a7: v182);
    while ( 1 )
    {
      if ( *(_DWORD *)&result.nReferenceCount == 0 || *(_DWORD *)&result.nReferenceCount >= (unsigned int)v182 )
      {
LABEL_239:
        if ( *(float *)&v186 != 0.0 )
          GRefCountNTSImpl::Release(this: v186);
        if ( v185 != 0 )
        {
          v135 = (struct GFxFontHandle *)v185;
          --*(_DWORD *)v185;
          if ( *(_DWORD *)v135 == 0 )
          {
            v136 = *((GFxFontManager **)v135 + 1);
            if ( v136 != nullptr )
              GFxFontManager::RemoveFontHandle(this: v136, a2: v135);
            v137 = *((IShaderDevice **)v135 + 7);
            if ( v137 != nullptr )
              GFxResource::Release(this: v137);
            *((_DWORD *)v135 + 7) = 0;
            v138 = *((IShaderDevice **)v135 + 8);
            if ( v138 != nullptr )
              GFxResource::Release(this: v138);
            v139 = *((IShaderDevice **)v135 + 7);
            if ( v139 != nullptr )
              GFxResource::Release(this: v139);
            v140 = (volatile LONG *)(*((_DWORD *)v135 + 3) & 0xFFFFFFFC);
            if ( InterlockedExchangeAdd(Addend: v140 + 1, Value: -1) == 1 )
              GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v140);
            GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v135);
          }
        }
        if ( v210 < v227[1] )
          v210 = (IClientTools *)((char *)v210 + 1);
        goto LABEL_161;
      }
      v115 = *(_WORD *)(*(_DWORD *)&result.nReferenceCount + 6);
      LODWORD(v207) = *(_DWORD *)&result.nReferenceCount + 6;
      nNextElement = (v115 & 0x40) != 0
                   ? -*(unsigned __int16 *)(*(_DWORD *)&result.nReferenceCount + 2)
                   : *(unsigned __int16 *)(*(_DWORD *)&result.nReferenceCount + 2);
      if ( (v115 & 0x8000) == 0 && ((v115 & 0x200) == 0 || v187 != 0.0 || *(float *)&v186 != 0.0) )
        break;
LABEL_227:
      if ( *(_DWORD *)&result.nReferenceCount != 0 && *(_DWORD *)&result.nReferenceCount < (unsigned int)v182 )
      {
        v134 = v188;
        if ( v188 == 0 )
        {
          v134 = *(unsigned __int16 *)(*(_DWORD *)&result.nReferenceCount + 4) >> 12;
          v188 = v134;
        }
        *(_DWORD *)&result.nReferenceCount += 8;
        if ( (*(_WORD *)(*(_DWORD *)&result.nReferenceCount + 4) & 0xF000) != 0
          && v134 != 0
          && !GFxTextHighlighterPosIterator::IsFinished(this: &v183) )
        {
          GFxTextHighlighterPosIterator::operator+=(
            this: (CMemberFunctor1<CMaterialSystem *,void (__thiscall CMaterialSystem::*)(CMatQueuedRenderContext *),CMatQueuedRenderContext *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *)&v183,
            p: v188);
          v188 = 0;
        }
        GFxTextLineBuffer::GlyphIterator::UpdateDesc(this: &result.nReferenceCount);
      }
      *(float *)&p.pString = (double)nNextElement + *(float *)&p.pString;
    }
    LODWORD(v116) = (unsigned __int16)**(_WORD **)&result.nReferenceCount;
    v220 = 1.0;
    v216 = 0.0;
    v226 = v116;
    if ( LOWORD(v116) == 0xFFFF )
      v226 = NAN;
    v117 = 0;
    *(float *)&v215 = 0.0;
    if ( *(float *)&v186 != 0.0 )
    {
      v118 = (double)(unsigned int)v186[3].__vftable;
      v215 = v186;
      goto LABEL_182;
    }
    v123 = *(_WORD *)(*(_DWORD *)&result.nReferenceCount + 4) & 0xFFF;
    v233 = *(float *)&v123;
    if ( (v115 & 0x10) != 0 )
      v124 = (double)(unsigned int)v123 * 0.0625;
    else
      v124 = (double)(unsigned int)v123;
    x = v124;
    v233 = x * 20.0;
    v220 = v233 * 0.0009765625;
    if ( v185 != 0 )
      v125 = *(GFxFontResource **)(v185 + 28);
    else
      v125 = nullptr;
    v119 = v227;
    if ( v227[4] != nullptr )
    {
      v233 = *((float *)v125[1].pElems + 3) + *((float *)v125[1].pElems + 2);
      x = *(float *)(v185 + 20) * v233;
      v233 = v233 * *(float *)(v185 + 24);
      if ( v226 != NAN )
      {
        GlyphShape = GFxFontCacheManagerImpl::GetGlyphShape(
                       this: (_RTL_CRITICAL_SECTION *)v227[4],
                       a2: v125,
                       a3: LODWORD(v226),
                       a4: 0,
                       a5: COERCE_FLOAT((HIBYTE(v190) & 8) != 0 || (*(_DWORD *)(v185 + 8) & 2) != 0),
                       a6: COERCE_FLOAT(((HIBYTE(v190) & 0x10) != 0) | *(_BYTE *)(v185 + 8) & 1),
                       a7: x,
                       a8: v233,
                       a9: COERCE_FLOAT((HIBYTE(v191) >> 1) & 0xF),
                       a10: (struct GFxLog *)v225[5].m_Memory.m_pMemory);
        v117 = (int)GlyphShape;
        if ( GlyphShape != nullptr )
        {
          v118 = *((float *)GlyphShape + 3) * v220;
LABEL_182:
          v216 = v118;
        }
        v119 = v227;
      }
    }
    else
    {
      if ( v226 != NAN )
        v117 = (*(int (__thiscall **)(__int16 *, float, _DWORD))(*(_DWORD *)v125[1].pElems + 24))(
                 a1: v125[1].pElems,
                 a2: COERCE_FLOAT(LODWORD(v226)),
                 a3: 0);
      if ( ((_BYTE)v119[29] & 4) != 0 )
      {
        v216 = 0.0;
      }
      else
      {
        v127 = (*(int (__thiscall **)(__int16 *, float, float *))(*(_DWORD *)v125[1].pElems + 48))(
                 a1: v125[1].pElems,
                 a2: COERCE_FLOAT(LODWORD(v226)),
                 a3: &v201);
        v216 = *(float *)(v127 + 8) * v220;
      }
    }
    v120 = *((_BYTE *)v119 + 116);
    v233 = *(float *)&p.pString - (double)(unsigned int)v119[10];
    v121 = v216;
    v122 = v233;
    if ( (v120 & 4) == 0 )
    {
      if ( v226 != NAN && *((float *)v119 + 6) >= v122 + v121 )
      {
LABEL_225:
        if ( v117 != 0 )
          GFxShapeBase::Release(this: (GFxShapeBase *)v117);
        goto LABEL_227;
      }
      if ( *((float *)v119 + 8) <= v122 )
      {
        if ( v117 != 0 )
          GFxShapeBase::Release(this: (GFxShapeBase *)v117);
        goto LABEL_239;
      }
    }
    if ( v187 == 0.0 )
      goto LABEL_214;
    v128 = *(_WORD *)LODWORD(v207);
    if ( (*(_WORD *)LODWORD(v207) & 0x100) == 0 )
      v221 = 1;
    if ( (v128 & 0x200) == 0 )
    {
LABEL_214:
      if ( HIBYTE(v232) == 0
        && (v120 & 4) == 0
        && (v120 & 0x20) == 0
        && (*((float *)v119 + 6) > v122 && *((float *)v119 + 6) < v122 + v121
         || *((float *)v119 + 8) > v122 && *((float *)v119 + 8) < v121 + v122) )
      {
        HIBYTE(v232) = GFxTextLineBuffer::DrawMask(
                         rect: v225,
                         a2: (float *)&v252,
                         a3: (float *)v119 + 6,
                         a4: v225[7].m_pElements != nullptr);
      }
      v251.M_[0][0] = v244;
      v251.M_[0][1] = v245;
      v251.M_[1][0] = v247;
      v251.M_[1][1] = v248;
      v251.M_[0][2] = v244 * *(float *)&p.pString + v245 * *(float *)&p.nNextElement + v246;
      v251.M_[1][2] = *(float *)&p.nNextElement * v248 + *(float *)&p.pString * v247 + v249;
      if ( *(float *)&v215 == 0.0 )
      {
        *(_DWORD *)&v219.nReferenceCount = *(_DWORD *)&v183.name[44];
        if ( *(_DWORD *)&v183.name[44] != 0 )
        {
          GRenderer::Cxform::Cxform(this: (float *)&v242);
          v242.M_[0][0] = (double)*(&v219.pad + 1) * 0.003921568859368563;
          v241 = *v213;
          v242.M_[1][0] = (double)v219.pad * 0.003921568859368563;
          v242.M_[2][0] = (double)v219.nReferenceCount * 0.003921568859368563;
          LODWORD(v233) = *(&v219.pad + 2);
          v242.M_[3][0] = 0.003921568859368563 * (double)*(&v219.pad + 2);
          GRenderer::Cxform::Concatenate(this: &v241, a2: &v242);
        }
        v250.M_[0][0] = v220;
        v250.M_[0][1] = 0.0;
        v250.M_[0][2] = 0.0;
        v250.M_[1][0] = 0.0;
        v250.M_[1][2] = 0.0;
        v250.M_[1][1] = v220;
        GMatrix2D::Prepend(this: &v251, a2: &v250);
        if ( v226 == NAN )
        {
          v132 = v200;
          v133 = (float *)v213;
          (*(void (__thiscall **)(float *, GRenderer::Cxform *))(*(_DWORD *)v200 + 64))(a1: v200, a2: v213);
          (*(void (__thiscall **)(float *, GMatrix2D *))(*(_DWORD *)v132 + 56))(a1: v132, a2: &v251);
          GRenderer::Cxform::Transform(
            this: v133,
            result: (CBaseAutoPtr<CFunctor> *)&v231 + 1,
            a3: *(unsigned int *)&v183.name[44]);
          (*(void (__thiscall **)(float *, _DWORD))(*(_DWORD *)v132 + 128))(a1: v132, a2: HIDWORD(v231));
          (*(void (__thiscall **)(float *, void *, int, int, _DWORD))(*(_DWORD *)v132 + 104))(
            a1: v132,
            a2: &EmptyCharBox,
            a3: 5,
            a4: 1,
            a5: 0);
          (*(void (__thiscall **)(float *, _DWORD, int))(*(_DWORD *)v132 + 120))(a1: v132, a2: 0, a3: 4);
          (*(void (__thiscall **)(float *, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v132 + 104))(
            a1: v132,
            a2: 0,
            a3: 0,
            a4: 0,
            a5: 0);
        }
        else
        {
          if ( v117 == 0 )
            goto LABEL_227;
          *(_BYTE *)(v117 + 36) |= 8u;
          v237[3] = v251.M_[0][0];
          v237[4] = v251.M_[0][1];
          LODWORD(v237[0]) = v225;
          v237[5] = v251.M_[0][2];
          v237[2] = 0.0;
          v237[6] = v251.M_[1][0];
          v237[7] = v251.M_[1][1];
          v237[8] = v251.M_[1][2];
          *(GRenderer::Cxform *)&v237[9] = v241;
          v238 = nullptr;
          v240 = 0;
          v239 = 1;
          LODWORD(v237[1]) = v227 + 40;
          GFxShapeBase::Display(
            this: (GFxShapeBase *)v117,
            a2: v251.M_[1][2],
            a3: (struct GFxDisplayParams *)v237,
            a4: false,
            a5: nullptr);
        }
      }
      else if ( v215[1].__vftable != nullptr )
      {
        GMatrix2D::Prepend(this: &v251, a2: (const struct GMatrix2D *)&v215[4]);
        v237[3] = v251.M_[0][0];
        v237[4] = v251.M_[0][1];
        LODWORD(v237[0]) = v225;
        v237[5] = v251.M_[0][2];
        v237[1] = 0.0;
        v237[2] = 0.0;
        v237[6] = v251.M_[1][0];
        v237[7] = v251.M_[1][1];
        v129 = v251.M_[1][2];
        v237[8] = v251.M_[1][2];
        qmemcpy(&v237[9], v213, 0x20u);
        v130 = v215;
        v131 = v215[1].__vftable;
        v238 = nullptr;
        v239 = 0;
        v240 = 0;
        (*((void (__thiscall **)(GRefCountNTSImpl_vtbl *, float *))v131->dtr_GRefCountImplCore + 11))(
          a1: v131,
          a2: v237);
        GFxShapeBase::Display(
          this: (GFxShapeBase *)v130[1].__vftable,
          a2: v129,
          a3: (struct GFxDisplayParams *)v237,
          a4: false,
          a5: nullptr);
      }
    }
    goto LABEL_225;
  }
LABEL_256:
  if ( v221 == 0 )
  {
    if ( (*((_BYTE *)this + 116) & 2) == 0 )
      goto LABEL_314;
    this = (CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > *)v227;
  }
  if ( *((_DWORD *)this + 51) == 0 )
  {
    v141 = v227[5];
    v142 = v227[10];
    v201 = *((float *)v227 + 6);
    v143 = *((float *)v227 + 7);
    v210 = v141;
    LOBYTE(v141) = *((_BYTE *)v227 + 116);
    v202 = v143;
    v203 = *((float *)v227 + 8);
    v144 = ((unsigned __int8)v141 & 4) != 0;
    v145 = *((float *)v227 + 9);
    LOBYTE(v212) = v144;
    v204 = v145;
    v146 = (double)(int)v227[10];
    if ( (int)v142 < 0 )
      v146 = v146 + 4294967300.0;
    *((float *)&v231 + 1) = v146;
    v147 = v227;
    v201 = v201 + *((float *)&v231 + 1);
    v203 = *((float *)&v231 + 1) + v203;
    while ( 1 )
    {
      v148 = (unsigned int)v210;
      if ( v210 >= v147[1]
        || (int)v210 < 0
        || !v144
        && !GFxTextLineBuffer::IsLineVisible(
              this: (CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > *)v147,
              lineIndex: (unsigned int)v210,
              yOffset: v214) )
      {
        break;
      }
      v200 = (float *)(*v147)[v148].__vftable;
      v149 = (CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *)v200;
      x = v200[3];
      v223 = (float)SLODWORD(x);
      x = v200[4];
      v150 = 0;
      v230 = 1;
      v224 = (float)SLODWORD(x);
      v216 = 0.0;
      v151 = *((float *)v147 + 6);
      v233 = NAN;
      *(float *)&v219.pString = v151;
      v226 = 0.0;
      v219.nNextElement = *((unsigned int *)v147 + 7);
      v223 = *(float *)&v219.pString + v223;
      v224 = *(float *)&v219.nNextElement + v224;
      *(float *)&v219.nReferenceCount = 0.0;
      x = 0.0;
      *(float *)&nNextElement = 0.0;
      v207 = 0.0;
      GMatrix2D::SetIdentity(this: (float *)&v251);
      GMatrix2D::SetIdentity(this: (float *)&v250);
      LODWORD(v171) = v205;
      GFxTextLineBuffer::Line::Begin(
        this: v149,
        phighlighter: (CMatRenderContextBase *)&result.nReferenceCount,
        a3: v171,
        a4: (ITexture *const *)result.pString,
        a5: (const float *)result.nNextElement,
        a6: *(const float **)&result.nReferenceCount,
        a7: v182);
      v152 = *(unsigned __int16 **)&result.nReferenceCount;
      *(float *)&v215 = 0.0;
      while ( v152 != nullptr && v152 < (unsigned __int16 *)v182 )
      {
        v153 = v152[3];
        LODWORD(v154) = v152[1];
        if ( (v153 & 0x40) != 0 )
          LODWORD(v154) = -LODWORD(v154);
        v220 = v154;
        if ( v187 != 0.0 && *(float *)&v186 == 0.0 && (v153 & 0x100) == 0 )
        {
          *((float *)&v231 + 1) = v223 - (double)(unsigned int)v147[10];
          if ( *((float *)v147 + 8) <= (double)*((float *)&v231 + 1) )
            break;
          if ( *((float *)v147 + 6) <= *((float *)&v231 + 1) + (double)SLODWORD(v220) )
          {
            if ( v230 != 0 )
            {
              *((float *)&v231 + 1) = (float)(int)GFxTextLineBuffer::Line::GetHeight(this: v149);
              BaseLineOffset = GFxTextLineBuffer::Line::GetBaseLineOffset(this: v149);
              *((float *)&v231 + 1) = *((float *)&v231 + 1) - BaseLineOffset;
              v231 = *((float *)&v231 + 1) * 0.5;
              v156 = GFxTextLineBuffer::Line::GetBaseLineOffset(this: v149);
              v224 = v156 + v214 + v231 + v224;
              v251.M_[0][0] = v244;
              v251.M_[0][1] = v245;
              v251.M_[0][2] = v246;
              v251.M_[1][0] = v247;
              v251.M_[1][1] = v248;
              v251.M_[1][2] = v249;
              GMatrix2D::Append(this: &v251, a2: (const struct GMatrix2D *)&v225[6]);
              v250.M_[0][0] = v251.M_[0][0];
              v250.M_[0][1] = v251.M_[0][1];
              v250.M_[0][2] = v251.M_[0][2];
              v250.M_[1][0] = v251.M_[1][0];
              v250.M_[1][1] = v251.M_[1][1];
              v250.M_[1][2] = v251.M_[1][2];
              v242.M_[1][0] = v251.M_[0][0];
              v242.M_[1][1] = v251.M_[0][1];
              v242.M_[2][0] = v251.M_[0][2];
              v242.M_[2][1] = v251.M_[1][0];
              v242.M_[3][0] = v251.M_[1][1];
              v242.M_[3][1] = v251.M_[1][2];
              GMatrix2D::SetInverse(
                a1: (float *)&v250,
                m: (const CMaterialDict::MaterialLookup_t *)v242.M_[1],
                a3: (const CMaterialDict::MaterialLookup_t *)DWORD1(v171));
              GMatrix2D::Transform(
                this: (CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *)&v251,
                result: &p,
                p: &v223,
                p_4: v178);
              *((float *)&v231 + 1) = *(float *)&p.pString + 0.5;
              *((float *)&v231 + 1) = floor(X: *((float *)&v231 + 1));
              p.pString = (char *)HIDWORD(v231);
              *((float *)&v231 + 1) = *(float *)&p.nNextElement + 0.5;
              *((float *)&v231 + 1) = floor(X: *((float *)&v231 + 1));
              p.nNextElement = HIDWORD(v231);
              GMatrix2D::Transform(
                this: (CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *)&v250,
                &result,
                (float *)&p,
                p_4: v179);
              *((float *)&v231 + 1) = *(float *)&result.pString + 0.5;
              *((float *)&v231 + 1) = floor(X: *((float *)&v231 + 1));
              v223 = *((float *)&v231 + 1);
              *((float *)&v231 + 1) = *(float *)&result.nNextElement + 0.5;
              *((float *)&v231 + 1) = floor(X: *((float *)&v231 + 1));
              v224 = *((float *)&v231 + 1);
              *(float *)&p.pString = *(float *)&p.pString + 1.0;
              *(float *)&p.nNextElement = *(float *)&p.nNextElement + 1.0;
              GMatrix2D::Transform(
                this: (CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *)&v250,
                result: &v189,
                (float *)&p,
                p_4: v180);
              *((float *)&v231 + 1) = *(float *)&v189.pString + 0.5;
              *((float *)&v231 + 1) = floor(X: *((float *)&v231 + 1));
              p.pString = (char *)HIDWORD(v231);
              *((float *)&v231 + 1) = *(float *)&v189.nNextElement + 0.5;
              *((float *)&v231 + 1) = floor(X: *((float *)&v231 + 1));
              v152 = *(unsigned __int16 **)&result.nReferenceCount;
              p.nNextElement = HIDWORD(v231);
              v230 = 0;
              *(float *)&nNextElement = *((float *)&v231 + 1) - v224;
              v207 = *(float *)&p.pString - v223;
              *(float *)&v219.nReferenceCount = v223;
              x = v224;
            }
            v157 = v184;
            v158 = v187;
            if ( v150 != 0
              && (LODWORD(v216) != LODWORD(v184)
               || (GRefCountNTSImpl *)(LODWORD(v233) + 1) != v215
               || LODWORD(v187) != LODWORD(v226)) )
            {
              GFxTextLineBuffer::DrawUnderline(
                this: v227,
                a2: *(void **)&v219.nReferenceCount,
                a3: x,
                a4: *(float *)&nNextElement,
                a5: v207,
                a6: (int)&v201,
                a7: v150,
                a8: SLODWORD(v226),
                rgba: SLODWORD(v216),
                a10: (CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *)&v251,
                a11: (CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *)&v250);
              v152 = *(unsigned __int16 **)&result.nReferenceCount;
              *(float *)&v219.nReferenceCount = v223;
              v150 = 0;
            }
            v150 += LODWORD(v220);
            v216 = v157;
            v149 = (CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *)v200;
            v226 = v158;
            v147 = v227;
            v233 = *(float *)&v215;
          }
        }
        if ( v152 != nullptr && v152 < (unsigned __int16 *)v182 )
        {
          v159 = v188;
          if ( v188 == 0 )
          {
            v159 = v152[2] >> 12;
            v188 = v159;
          }
          *(_DWORD *)&result.nReferenceCount = v152 + 4;
          if ( (v152[6] & 0xF000) != 0 && v159 != 0 && !GFxTextHighlighterPosIterator::IsFinished(this: &v183) )
          {
            GFxTextHighlighterPosIterator::operator+=(
              this: (CMemberFunctor1<CMaterialSystem *,void (__thiscall CMaterialSystem::*)(CMatQueuedRenderContext *),CMatQueuedRenderContext *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *)&v183,
              p: v188);
            v188 = 0;
          }
          GFxTextLineBuffer::GlyphIterator::UpdateDesc(this: &result.nReferenceCount);
          v152 = *(unsigned __int16 **)&result.nReferenceCount;
        }
        v215 = (GRefCountNTSImpl *)((char *)v215 + 1);
        v223 = (double)SLODWORD(v220) + v223;
      }
      if ( v150 != 0 )
        GFxTextLineBuffer::DrawUnderline(
          this: v147,
          a2: *(void **)&v219.nReferenceCount,
          a3: x,
          a4: *(float *)&nNextElement,
          a5: v207,
          a6: (int)&v201,
          a7: v150,
          a8: SLODWORD(v226),
          rgba: SLODWORD(v216),
          a10: (CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *)&v251,
          a11: (CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *)&v250);
      if ( *(float *)&v186 != 0.0 )
        GRefCountNTSImpl::Release(this: v186);
      v160 = (struct GFxFontHandle *)v185;
      if ( v185 != 0 )
      {
        --*(_DWORD *)v185;
        if ( *(_DWORD *)v160 == 0 )
        {
          v161 = *((GFxFontManager **)v160 + 1);
          if ( v161 != nullptr )
            GFxFontManager::RemoveFontHandle(this: v161, a2: v160);
          v162 = *((IShaderDevice **)v160 + 7);
          if ( v162 != nullptr )
            GFxResource::Release(this: v162);
          *((_DWORD *)v160 + 7) = 0;
          v163 = *((IShaderDevice **)v160 + 8);
          if ( v163 != nullptr )
            GFxResource::Release(this: v163);
          v164 = *((IShaderDevice **)v160 + 7);
          if ( v164 != nullptr )
            GFxResource::Release(this: v164);
          v165 = (volatile LONG *)(*((_DWORD *)v160 + 3) & 0xFFFFFFFC);
          if ( InterlockedExchangeAdd(Addend: v165 + 1, Value: -1) == 1 )
            GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v165);
          GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v160);
        }
      }
      v144 = LOBYTE(v212);
      if ( v210 < v147[1] )
        v210 = (IClientTools *)((char *)v210 + 1);
    }
  }
LABEL_314:
  v166 = v227;
  v167 = v227[51];
  v168 = v225;
  if ( v167 != nullptr )
    GFxDrawingContext::Display(
      this: v167,
      context: (FBMAttributeMask_t)v225,
      blend_4: &v244,
      blend_8: v213,
      a5: 0,
      edgeAADisabled: false);
  if ( HIBYTE(v232) != 0 )
  {
    if ( v168[7].m_pElements != nullptr )
      GFxTextLineBuffer::DrawMask(rect: v168, a2: (float *)&v252, a3: (float *)v166 + 6, a4: 2);
    else
      (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(v168[3].m_Size + 12) + 164))(a1: *(_DWORD *)(v168[3].m_Size + 12));
  }
  if ( v222 != 0 && byte_103599A4 != 0 )
    qmemcpy((void *)v168->m_Memory.m_nGrowSize, &stru_10359964, 64);
}

//------------------------------------------------------------------------------
// Address: 0x10178470
// Name: public: void GFxTextLineBuffer::Scale(float)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GFxTextLineBuffer::Scale(
        CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > *this,
        float scaleFactor)
{
  unsigned int result; // eax
  double v3; // st7
  IMaterialVar *v4; // esi
  bool v5; // bl
  int v6; // eax
  int v7; // edi
  int v8; // eax
  bool v9; // bl
  double v10; // st6
  CUtlSymbol *p_m_Name; // ecx
  char *m_pStringVal; // eax
  CUtlSymbol *v13; // ecx
  char *v14; // edx
  CUtlSymbol *v15; // esi
  CUtlSymbol *v16; // esi
  int v17; // eax
  int v18; // eax
  double v19; // st6
  unsigned int v20; // eax
  struct GFxFontHandle *v21; // esi
  GFxFontManager *v22; // ecx
  IShaderDevice *v23; // ecx
  IShaderDevice *v24; // ecx
  IShaderDevice *v25; // ecx
  volatile LONG *v26; // edi
  unsigned int i; // [esp+18h] [ebp-78h]
  CUtlSymbol *v28; // [esp+24h] [ebp-6Ch] BYREF
  CUtlSymbol *v29; // [esp+28h] [ebp-68h]
  unsigned int v30; // [esp+2Ch] [ebp-64h]
  CMemberFunctor1<CMaterialSystem *,void (__thiscall CMaterialSystem::*)(CMatQueuedRenderContext *),CMatQueuedRenderContext *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> v31; // [esp+30h] [ebp-60h] BYREF
  char v32; // [esp+60h] [ebp-30h]
  int v33; // [esp+64h] [ebp-2Ch]
  int v34; // [esp+68h] [ebp-28h]
  int v35; // [esp+6Ch] [ebp-24h]
  struct GFxFontHandle *v36; // [esp+70h] [ebp-20h]
  GRefCountNTSImpl *v37; // [esp+74h] [ebp-1Ch]
  int v38; // [esp+78h] [ebp-18h]
  unsigned int p; // [esp+7Ch] [ebp-14h]
  float newLeading; // [esp+80h] [ebp-10h]
  CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > *v41; // [esp+84h] [ebp-Ch]
  int newW; // [esp+88h] [ebp-8h]
  int newH; // [esp+8Ch] [ebp-4h]

  result = 0;
  v41 = this;
  for ( i = 0; ; result = i )
  {
    v3 = scaleFactor;
    if ( this == nullptr || result >= this->m_Memory.m_nAllocationCount || (result & 0x80000000) != 0 )
      break;
    v4 = this->m_Memory.m_pMemory[result];
    v5 = (int)v4->__vftable < 0;
    if ( (int)v4->__vftable >= 0 )
      newH = SLOWORD(v4[1].m_intVal);
    else
      newH = (char)v4->m_nTempIndex;
    newLeading = (double)newH * v3;
    if ( v5 )
      newH = LOWORD(v4->m_VecVal.z);
    else
      newH = SLODWORD(v4->m_VecVal.z);
    *(float *)&newW = (double)newH * v3;
    if ( v5 )
      newH = HIWORD(v4->m_VecVal.z);
    else
      newH = SLODWORD(v4->m_VecVal.w);
    *(float *)&newH = (double)newH * v3;
    v6 = (int)newLeading;
    if ( v5 )
      v4->m_nTempIndex = v6;
    else
      LOWORD(v4[1].m_intVal) = v6;
    v7 = (int)*(float *)&newH;
    v8 = (int)*(float *)&newW;
    if ( v5 )
    {
      LOWORD(v4->m_VecVal.z) = v8;
      HIWORD(v4->m_VecVal.z) = v7;
    }
    else
    {
      LODWORD(v4->m_VecVal.z) = v8;
      LODWORD(v4->m_VecVal.w) = v7;
    }
    v9 = (int)v4->__vftable < 0;
    if ( (int)v4->__vftable >= 0 )
      newW = HIWORD(v4[1].m_pStringVal);
    else
      newW = HIWORD(v4->m_VecVal.w);
    *(float *)&newH = (float)newW;
    *(float *)&newH = *(float *)&newH * v3;
    v10 = *(float *)&newH;
    newW = (int)*(float *)&newH;
    if ( v9 )
      HIWORD(v4->m_VecVal.w) = (int)v10;
    else
      HIWORD(v4[1].m_pStringVal) = (int)v10;
    newH = SLODWORD(v4->m_VecVal.x);
    LODWORD(v4->m_VecVal.x) = (int)((double)newH * v3);
    newH = SLODWORD(v4->m_VecVal.y);
    LODWORD(v4->m_VecVal.y) = (int)(v3 * (double)newH);
    p_m_Name = &v4->m_Name;
    if ( v9 )
    {
      m_pStringVal = (char *)*((unsigned __int8 *)v4 + 28);
    }
    else
    {
      m_pStringVal = v4->m_pStringVal;
      p_m_Name = (CUtlSymbol *)&v4[1].m_intVal + 1;
    }
    v13 = &p_m_Name[4 * (_DWORD)m_pStringVal];
    if ( v9 )
      v14 = (char *)*((unsigned __int8 *)v4 + 28);
    else
      v14 = v4->m_pStringVal;
    if ( v9 )
      v15 = &v4->m_Name;
    else
      v15 = (CUtlSymbol *)&v4[1].m_intVal + 1;
    v31.m_iRefs = -1;
    v31.m_Proxy.m_pfnProxied = 0xFFFFFFFF00000000uLL;
    memset(&v31.m_Proxy.m_pObject, 0, 16);
    v32 = 0;
    v31.CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = nullptr;
    v31.m_nUserID = 0;
    v33 = 0;
    v34 = 0;
    v35 = 0;
    v36 = nullptr;
    v37 = nullptr;
    v38 = 0;
    p = 0;
    v28 = v15;
    v29 = &v15[4 * (_DWORD)v14];
    v30 = ((unsigned int)&v13[1].m_Id + 1) & 0xFFFFFFFC;
    GFxTextLineBuffer::GlyphIterator::UpdateDesc(this: &v28);
    v16 = v28;
    while ( v16 != nullptr && v16 < v29 )
    {
      if ( (v16[3].m_Id & 0x40) != 0 )
        newH = -v16[1].m_Id;
      else
        newH = v16[1].m_Id;
      *(float *)&newW = (double)newH * scaleFactor;
      v17 = (int)*(float *)&newW;
      if ( v17 < 0 )
      {
        v16[3].m_Id |= 0x40u;
        v16[1].m_Id = abs32(v17);
      }
      else
      {
        v16[1].m_Id = v17;
        v16[3].m_Id &= ~0x40u;
      }
      v18 = v16[2].m_Id & 0xFFF;
      if ( (v16[3].m_Id & 0x10) != 0 )
      {
        newW = v16[2].m_Id & 0xFFF;
        v19 = (double)(unsigned int)v18 * 0.0625;
      }
      else
      {
        newW = v16[2].m_Id & 0xFFF;
        v19 = (double)(unsigned int)v18;
      }
      *(float *)&newH = v19;
      *(float *)&newW = scaleFactor * *(float *)&newH;
      GFxTextLineBuffer::GlyphEntry::SetFontSize(this: v16, result: (const CIndexBufferBase *)newW);
      v16 = v28;
      if ( v28 != nullptr && v28 < v29 )
      {
        v20 = p;
        if ( p == 0 )
        {
          v20 = v28[2].m_Id >> 12;
          p = v20;
        }
        v28 += 4;
        if ( (v28[2].m_Id & 0xF000) != 0
          && v20 != 0
          && !GFxTextHighlighterPosIterator::IsFinished(this: (GFxTextHighlighterPosIterator *)&v31) )
        {
          GFxTextHighlighterPosIterator::operator+=(this: &v31, p);
          p = 0;
        }
        GFxTextLineBuffer::GlyphIterator::UpdateDesc(this: &v28);
        v16 = v28;
      }
    }
    if ( v37 != nullptr )
      GRefCountNTSImpl::Release(this: v37);
    v21 = v36;
    if ( v36 != nullptr )
    {
      --*(_DWORD *)v36;
      if ( *(_DWORD *)v21 == 0 )
      {
        v22 = *((GFxFontManager **)v21 + 1);
        if ( v22 != nullptr )
          GFxFontManager::RemoveFontHandle(this: v22, a2: v21);
        v23 = *((IShaderDevice **)v21 + 7);
        if ( v23 != nullptr )
          GFxResource::Release(this: v23);
        *((_DWORD *)v21 + 7) = 0;
        v24 = *((IShaderDevice **)v21 + 8);
        if ( v24 != nullptr )
          GFxResource::Release(this: v24);
        v25 = *((IShaderDevice **)v21 + 7);
        if ( v25 != nullptr )
          GFxResource::Release(this: v25);
        v26 = (volatile LONG *)(*((_DWORD *)v21 + 3) & 0xFFFFFFFC);
        if ( InterlockedExchangeAdd(Addend: v26 + 1, Value: -1) == 1 )
          GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v26);
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v21);
      }
    }
    this = v41;
    if ( i < v41->m_Memory.m_nAllocationCount )
      ++i;
  }
  *((_BYTE *)this + 116) |= 1u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10178850
// Name: public: void GFxTextLineBuffer::RemoveLines(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextLineBuffer::RemoveLines(
        CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > *this,
        unsigned int lineIdx,
        unsigned int num)
{
  int v3; // ebx
  unsigned int v4; // edi
  IMaterialVar *v6; // edi
  int m_nAllocationCount; // eax
  unsigned int i; // [esp+Ch] [ebp-4h]

  v3 = lineIdx;
  v4 = num;
  for ( i = 0; i < num; ++i )
  {
    if ( this == nullptr || (unsigned int)v3 >= this->m_Memory.m_nAllocationCount || v3 < 0 )
      break;
    v6 = this->m_Memory.m_pMemory[v3];
    if ( v6 != nullptr )
    {
      GFxTextLineBuffer::Line::Release(
        this: (CCustomizedFunctorFactory<CMemoryStack,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> > > *)this->m_Memory.m_pMemory[v3],
        a2: (int)v6);
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v6);
    }
    if ( (unsigned int)v3 < this->m_Memory.m_nAllocationCount )
      ++v3;
    v4 = num;
  }
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_nAllocationCount != v4 )
  {
    memmove(
      dst: (unsigned __int8 *)&this->m_Memory.m_pMemory[lineIdx],
      src: (unsigned __int8 *)&this->m_Memory.m_pMemory[lineIdx] + 4 * v4,
      count: 4 * (m_nAllocationCount - lineIdx - v4));
    this->m_Memory.m_nAllocationCount -= v4;
    return;
  }
  if ( m_nAllocationCount == 0 )
  {
    if ( this->m_Memory.m_nGrowSize == 0 )
      GArrayDataBase<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,GAllocatorLH<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,2>,GArrayDefaultPolicy>::Reserve(
        (GRenderer::CachedData *)this,
        pheapAddr: this,
        newCapacity: 0);
    goto LABEL_18;
  }
  if ( (this->m_Memory.m_nGrowSize & 0xFFFFFFFE) == 0 )
  {
LABEL_18:
    this->m_Memory.m_nAllocationCount = 0;
    return;
  }
  if ( this->m_Memory.m_pMemory != nullptr )
  {
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: this->m_Memory.m_pMemory);
    this->m_Memory.m_pMemory = nullptr;
  }
  this->m_Memory.m_nGrowSize = 0;
  this->m_Memory.m_nAllocationCount = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10178950
// Name: public: GFxTextLineBuffer::~GFxTextLineBuffer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTextLineBuffer::~GFxTextLineBuffer(CMatCallQueue *this)
{
  unsigned __int8 *m_pAllocLimit; // ecx
  GRefCountNTSImpl *v3; // ecx

  m_pAllocLimit = this->m_Allocator.m_pAllocLimit;
  if ( m_pAllocLimit != nullptr )
    GFxFontCacheManagerImpl::ReleaseBatchPackage(
      this: (_RTL_CRITICAL_SECTION *)m_pAllocLimit,
      a2: (struct GFxBatchPackage *)this->m_Allocator.m_pCommitLimit);
  *((_BYTE *)this + 116) |= 1u;
  GFxTextLineBuffer::RemoveLines(
    (CUtlVector<IMaterialVar *,CUtlMemory<IMaterialVar *,int> > *)this,
    lineIdx: 0,
    num: (unsigned int)this->m_pTail);
  v3 = *((GRefCountNTSImpl **)this + 51);
  if ( v3 != nullptr )
    GRefCountNTSImpl::Release(this: v3);
  GFxFillStyle::~GFxFillStyle(this: (char *)this + 160);
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: this->m_pHead);
}
