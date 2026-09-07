// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gkernel/gmatrix2d.cpp
// Functions: 22
// ============================================================

#include "thirdparty\scaleform\sdk\src\gkernel\gmatrix2d.h"

//------------------------------------------------------------------------------
// Address: 0x10062860
// Name: public: bool GMatrix2D::IsValid(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GMatrix2D::IsValid(CMaterialDict::MaterialLookup_t *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10062920
// Name: public: void GMatrix2D::SetIdentity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GMatrix2D::SetIdentity(float *this)
{
  *this = 1.0;
  *(this + 1) = 0.0;
  *(this + 2) = 0.0;
  *(this + 3) = 0.0;
  *(this + 5) = 0.0;
  *(this + 4) = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x10062940
// Name: public: void GMatrix2D::SetLerp(class GMatrix2D const __near &,class GMatrix2D const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GMatrix2D::SetLerp(GMatrix2D *this, const struct GMatrix2D *a2, const struct GMatrix2D *a3, float t)
{
  this->M_[0][0] = a2->M_[0][0] + (a3->M_[0][0] - a2->M_[0][0]) * t;
  this->M_[1][0] = (a3->M_[1][0] - a2->M_[1][0]) * t + a2->M_[1][0];
  this->M_[0][1] = (a3->M_[0][1] - a2->M_[0][1]) * t + a2->M_[0][1];
  this->M_[1][1] = (a3->M_[1][1] - a2->M_[1][1]) * t + a2->M_[1][1];
  this->M_[0][2] = (a3->M_[0][2] - a2->M_[0][2]) * t + a2->M_[0][2];
  this->M_[1][2] = t * (a3->M_[1][2] - a2->M_[1][2]) + a2->M_[1][2];
}

//------------------------------------------------------------------------------
// Address: 0x100629F0
// Name: public: void GMatrix2D::Transform(class GPoint<float> __near *,class GPoint<float> const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge GMatrix2D::Transform(
        CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *this@<ecx>,
        CCountedStringPoolBase<unsigned int>::hash_item_t *result,
        float *p,
        int p_4)
{
  *(float *)&result->pString = *(float *)&this->m_Memory.m_nAllocationCount * p[1]
                             + *p * *(float *)&this->m_Memory.m_pMemory
                             + *(float *)&this->m_Memory.m_nGrowSize;
  *(float *)&result->nNextElement = *(float *)&this->m_Size * *p
                                  + *(float *)&this->m_pElements * p[1]
                                  + *((float *)this + 5);
}

//------------------------------------------------------------------------------
// Address: 0x10062A30
// Name: public: void GMatrix2D::SetInverse(class GMatrix2D const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GMatrix2D::SetInverse(
        float *a1@<ecx>,
        const CMaterialDict::MaterialLookup_t *m,
        const CMaterialDict::MaterialLookup_t *a3)
{
  double v4; // st7
  float invDet; // [esp+8h] [ebp+8h]
  float invDeta; // [esp+8h] [ebp+8h]

  invDet = *(float *)&m->m_pMaterial * *(float *)&m[2].m_pMaterial
         - *(float *)&m[1].m_Name.m_Id * *(float *)&m->m_Name.m_Id;
  if ( 0.0 == invDet )
  {
    *a1 = 1.0;
    a1[4] = 1.0;
    a1[1] = 0.0;
    a1[2] = 0.0;
    a1[3] = 0.0;
    a1[5] = 0.0;
    a1[2] = -*(float *)&m[1].m_pMaterial;
    v4 = -*(float *)&m[2].m_Name.m_Id;
  }
  else
  {
    invDeta = 1.0 / invDet;
    *a1 = invDeta * *(float *)&m[2].m_pMaterial;
    a1[4] = *(float *)&m->m_pMaterial * invDeta;
    a1[1] = -*(float *)&m->m_Name.m_Id * invDeta;
    a1[3] = invDeta * -*(float *)&m[1].m_Name.m_Id;
    a1[2] = -(*(float *)&m[2].m_Name.m_Id * a1[1] + *(float *)&m[1].m_pMaterial * *a1);
    v4 = -(*(float *)&m[2].m_Name.m_Id * a1[4] + *(float *)&m[1].m_pMaterial * a1[3]);
  }
  a1[5] = v4;
}

//------------------------------------------------------------------------------
// Address: 0x10062AE0
// Name: public: float GMatrix2D::GetY(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall GMatrix2D::GetY(CMaterialDict::MaterialLookup_t *this)
{
  return *((float *)this + 5);
}

//------------------------------------------------------------------------------
// Address: 0x10062AF0
// Name: public: double GMatrix2D::GetXScale(void)const
// Source: json
//------------------------------------------------------------------------------
long double __thiscall GMatrix2D::GetXScale(GMatrix2D *this)
{
  return sqrt(this->M_[1][0] * this->M_[1][0] + this->M_[0][0] * this->M_[0][0]);
}

//------------------------------------------------------------------------------
// Address: 0x10062B10
// Name: public: double GMatrix2D::GetYScale(void)const
// Source: json
//------------------------------------------------------------------------------
long double __thiscall GMatrix2D::GetYScale(GMatrix2D *this)
{
  return sqrt(this->M_[1][1] * this->M_[1][1] + this->M_[0][1] * this->M_[0][1]);
}

//------------------------------------------------------------------------------
// Address: 0x10062B30
// Name: public: double GMatrix2D::GetRotation(void)const
// Source: json
//------------------------------------------------------------------------------
long double __thiscall GMatrix2D::GetRotation(GMatrix2D *this)
{
  return atan2(this->M_[1][0], this->M_[0][0]);
}

//------------------------------------------------------------------------------
// Address: 0x10062B40
// Name: public: class GMatrix2D __near & GMatrix2D::Prepend(class GMatrix2D const __near &)
// Source: json
//------------------------------------------------------------------------------
struct GMatrix2D *__thiscall GMatrix2D::Prepend(GMatrix2D *this, const struct GMatrix2D *a2)
{
  double v3; // st7
  float v4; // [esp+0h] [ebp-18h]
  float v5; // [esp+8h] [ebp-10h]
  float v6; // [esp+Ch] [ebp-Ch]
  float v7; // [esp+10h] [ebp-8h]
  float v8; // [esp+14h] [ebp-4h]

  v4 = this->M_[0][0];
  v5 = this->M_[0][2];
  v6 = this->M_[1][0];
  v7 = this->M_[1][1];
  v8 = this->M_[1][2];
  v3 = this->M_[0][1];
  this->M_[0][0] = a2->M_[1][0] * v3 + a2->M_[0][0] * v4;
  this->M_[1][0] = a2->M_[1][0] * v7 + a2->M_[0][0] * v6;
  this->M_[0][1] = a2->M_[0][1] * v4 + v3 * a2->M_[1][1];
  this->M_[1][1] = a2->M_[0][1] * v6 + v7 * a2->M_[1][1];
  this->M_[0][2] = v3 * a2->M_[1][2] + v4 * a2->M_[0][2] + v5;
  this->M_[1][2] = v7 * a2->M_[1][2] + v6 * a2->M_[0][2] + v8;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10062BF0
// Name: public: class GMatrix2D __near & GMatrix2D::Append(class GMatrix2D const __near &)
// Source: json
//------------------------------------------------------------------------------
struct GMatrix2D *__thiscall GMatrix2D::Append(GMatrix2D *this, const struct GMatrix2D *a2)
{
  double v3; // st7
  float v4; // [esp+0h] [ebp-18h]
  float v5; // [esp+4h] [ebp-14h]
  float v6; // [esp+8h] [ebp-10h]
  float v7; // [esp+10h] [ebp-8h]
  float v8; // [esp+14h] [ebp-4h]

  v4 = this->M_[0][0];
  v5 = this->M_[0][1];
  v6 = this->M_[0][2];
  v7 = this->M_[1][1];
  v8 = this->M_[1][2];
  v3 = this->M_[1][0];
  this->M_[0][0] = a2->M_[0][1] * v3 + a2->M_[0][0] * v4;
  this->M_[1][0] = v3 * a2->M_[1][1] + v4 * a2->M_[1][0];
  this->M_[0][1] = a2->M_[0][1] * v7 + a2->M_[0][0] * v5;
  this->M_[1][1] = v7 * a2->M_[1][1] + v5 * a2->M_[1][0];
  this->M_[0][2] = a2->M_[0][1] * v8 + a2->M_[0][0] * v6 + a2->M_[0][2];
  this->M_[1][2] = v8 * a2->M_[1][1] + v6 * a2->M_[1][0] + a2->M_[1][2];
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10062CA0
// Name: public: void GMatrix2D::TransformByInverse(class GPoint<float> __near *,class GPoint<float> const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge GMatrix2D::TransformByInverse(
        CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *this@<ecx>,
        CCountedStringPoolBase<unsigned int>::hash_item_t *result,
        float *p,
        int p_4)
{
  CMaterialDict::MaterialLookup_t m; // [esp+0h] [ebp-30h] BYREF
  int v5; // [esp+8h] [ebp-28h]
  int v6; // [esp+Ch] [ebp-24h]
  CCountedStringPoolBase<unsigned int>::hash_item_t *v7; // [esp+10h] [ebp-20h]
  float v8; // [esp+14h] [ebp-1Ch]
  const CMaterialDict::MaterialLookup_t *m_pMemory; // [esp+18h] [ebp-18h] BYREF
  int m_nAllocationCount; // [esp+1Ch] [ebp-14h]
  int m_nGrowSize; // [esp+20h] [ebp-10h]
  int m_Size; // [esp+24h] [ebp-Ch]
  CCountedStringPoolBase<unsigned int>::hash_item_t *m_pElements; // [esp+28h] [ebp-8h]
  float v14; // [esp+2Ch] [ebp-4h]

  m_pMemory = (const CMaterialDict::MaterialLookup_t *)this->m_Memory.m_pMemory;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_nGrowSize = this->m_Memory.m_nGrowSize;
  m_Size = this->m_Size;
  m_pElements = this->m_pElements;
  v14 = *((float *)this + 5);
  *(float *)&m.m_Name.m_Id = *(float *)&m_nAllocationCount;
  v5 = m_nGrowSize;
  v6 = m_Size;
  v7 = m_pElements;
  v8 = v14;
  GMatrix2D::SetInverse(a1: (float *)&m_pMemory, &m, a3: m_pMemory);
  *(float *)&result->pString = *p * *(float *)&m_pMemory + p[1] * *(float *)&m_nAllocationCount + *(float *)&m_nGrowSize;
  *(float *)&result->nNextElement = *p * *(float *)&m_Size + p[1] * *(float *)&m_pElements + v14;
}

//------------------------------------------------------------------------------
// Address: 0x10062D30
// Name: public: float GMatrix2D::GetMaxScale(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall GMatrix2D::GetMaxScale(CMaterialDict::MaterialLookup_t *this)
{
  double v1; // st7
  float basis0Length2; // [esp+0h] [ebp-8h]
  float basis1Length2; // [esp+4h] [ebp-4h]
  float basis1Length2a; // [esp+4h] [ebp-4h]

  basis0Length2 = *((float *)this + 3) * *((float *)this + 3)
                + *(float *)&this->m_pMaterial * *(float *)&this->m_pMaterial;
  basis1Length2 = *((float *)this + 4) * *((float *)this + 4)
                + *(float *)&this->m_Name.m_Id * *(float *)&this->m_Name.m_Id;
  v1 = basis1Length2;
  if ( basis0Length2 > (double)basis1Length2 )
    v1 = basis0Length2;
  basis1Length2a = v1;
  return (float)sqrt(basis1Length2a);
}

//------------------------------------------------------------------------------
// Address: 0x10062D90
// Name: public: class GMatrix2D __near & GMatrix2D::SetParlToParl(float const __near *,float const __near *)
// Source: json
//------------------------------------------------------------------------------
CMaterialDict::MissingMaterial_t *__thiscall GMatrix2D::SetParlToParl(
        int this,
        CMaterialDict::MissingMaterial_t *result,
        float *a3)
{
  double v5; // st7
  double v7; // st6
  double v8; // st5
  double v9; // st4
  double v10; // st3
  const CMaterialDict::MaterialLookup_t *v12; // [esp+0h] [ebp-44h]
  struct GMatrix2D v13; // [esp+4h] [ebp-40h] BYREF
  CMaterialDict::MaterialLookup_t m; // [esp+1Ch] [ebp-28h] BYREF
  float v15; // [esp+24h] [ebp-20h]
  float v16; // [esp+28h] [ebp-1Ch]
  float v17; // [esp+2Ch] [ebp-18h]
  float v18; // [esp+30h] [ebp-14h]
  float v19; // [esp+34h] [ebp-10h]
  float v20; // [esp+38h] [ebp-Ch]
  float v21; // [esp+3Ch] [ebp-8h]
  float v22; // [esp+40h] [ebp-4h]
  float v23; // [esp+4Ch] [ebp+8h]

  v23 = *(float *)&result[8].m_Name.m_Id - *(float *)&result->m_Name.m_Id;
  v21 = *(float *)&result[6].m_Name.m_Id - *(float *)&result[2].m_Name.m_Id;
  v20 = *(float *)&result[10].m_Name.m_Id - *(float *)&result[2].m_Name.m_Id;
  v22 = *(float *)&result->m_Name.m_Id;
  v19 = *(float *)&result[2].m_Name.m_Id;
  v5 = *(float *)&result[4].m_Name.m_Id - *(float *)&result->m_Name.m_Id;
  *(float *)this = v5;
  *(float *)(this + 4) = v23;
  v7 = v22;
  *(float *)(this + 8) = v22;
  v8 = v21;
  *(float *)(this + 12) = v21;
  v9 = v20;
  *(float *)(this + 16) = v20;
  v10 = v19;
  *(float *)(this + 20) = v19;
  v13.M_[0][0] = a3[2] - *a3;
  v13.M_[0][1] = a3[4] - *a3;
  v13.M_[0][2] = *a3;
  v13.M_[1][0] = a3[3] - a3[1];
  v13.M_[1][1] = a3[5] - a3[1];
  v13.M_[1][2] = a3[1];
  m.m_pMaterial = *(IMaterialInternal **)this;
  *(float *)&m.m_Name.m_Id = v23;
  v15 = v7;
  v16 = v8;
  v17 = v9;
  v18 = v10;
  GMatrix2D::SetInverse(a1: (float *)this, &m, a3: v12);
  GMatrix2D::Append((GMatrix2D *)this, a2: &v13);
  return (CMaterialDict::MissingMaterial_t *)this;
}

//------------------------------------------------------------------------------
// Address: 0x10062E50
// Name: public: class GMatrix2D __near & GMatrix2D::SetRectToParl(float,float,float,float,float const __near *)
// Source: json
//------------------------------------------------------------------------------
CMaterialDict::MissingMaterial_t *__thiscall GMatrix2D::SetRectToParl(
        GMatrix2D *this,
        float a2,
        float a3,
        float a4,
        float a5,
        float *a6)
{
  CMaterialDict::MissingMaterial_t v7[2]; // [esp+0h] [ebp-18h] BYREF
  float v8; // [esp+4h] [ebp-14h]
  float v9; // [esp+8h] [ebp-10h]
  float v10; // [esp+Ch] [ebp-Ch]
  float v11; // [esp+10h] [ebp-8h]
  float v12; // [esp+14h] [ebp-4h]

  *(float *)&v7[0].m_Name.m_Id = a2;
  v8 = a3;
  v9 = a4;
  v11 = a4;
  v10 = a3;
  v12 = a5;
  return GMatrix2D::SetParlToParl((int)this, result: v7, a3: a6);
}

//------------------------------------------------------------------------------
// Address: 0x10062E90
// Name: public: void __near * GStackMemPool<512,4,struct GMemPoolImmediateFree>::Alloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GStackMemPool<512,4,GMemPoolImmediateFree>::Alloc(GMemoryHeap **this, unsigned int nbytes)
{
  void *result; // eax
  unsigned int v3; // edx
  GMemoryHeap *v4; // ecx

  if ( nbytes > (unsigned int)*(this + 130) )
  {
    v4 = *this;
    if ( v4 == nullptr )
      v4 = GMemory::pGlobalHeap;
    return v4->Alloc(this: v4, a2: nbytes, a3: 4u, a4: nullptr);
  }
  else
  {
    result = *(this + 129);
    *(this + 129) = (GMemoryHeap *)((((unsigned int)result + nbytes - 1) & 0xFFFFFFFC) + 4);
    v3 = (((unsigned int)result + nbytes - 1) & 0xFFFFFFFC) - (_DWORD)this;
    if ( v3 >= 0x200 )
      *(this + 130) = nullptr;
    else
      *(this + 130) = (GMemoryHeap *)(512 - v3);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10062F00
// Name: public: void GMatrix2D::EncloseTransform(class GRect<float> __near *,class GRect<float> const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GMatrix2D::EncloseTransform(float *this, float *a2, float *a3)
{
  double v3; // st7
  double v4; // st5
  double v5; // st6
  double v6; // st4
  double v7; // st3
  double v8; // st7
  double v9; // st2
  double v10; // st6
  double v11; // rt2
  double v12; // st3
  double v13; // st5
  double v14; // st3
  double v15; // st7
  double v16; // rt0
  double v17; // st4
  double v18; // st5
  double v19; // st4
  double v20; // st3
  double v21; // st5
  double v22; // st3
  double v23; // st2
  double v24; // st6
  double v25; // st2
  double v26; // st5
  double v27; // rt0
  double v28; // st3
  double v29; // st7
  double v30; // st3
  double v31; // st6
  double v32; // st4
  double v33; // st3
  double v34; // st7
  double v35; // st3
  double v36; // st5
  double v37; // rt0
  double v38; // st4
  double v39; // st7
  double v40; // rt1
  double v41; // st5
  double v42; // st6
  float v43; // [esp+0h] [ebp-20h]
  float v44; // [esp+4h] [ebp-1Ch]
  float v45; // [esp+8h] [ebp-18h]
  float v46; // [esp+Ch] [ebp-14h]
  float v47; // [esp+10h] [ebp-10h]
  float v48; // [esp+14h] [ebp-Ch]
  float v49; // [esp+18h] [ebp-8h]
  float v50; // [esp+18h] [ebp-8h]
  float v51; // [esp+18h] [ebp-8h]
  float v52; // [esp+1Ch] [ebp-4h]
  float v53; // [esp+1Ch] [ebp-4h]
  float v54; // [esp+1Ch] [ebp-4h]
  float v55; // [esp+2Ch] [ebp+Ch]
  float v56; // [esp+2Ch] [ebp+Ch]
  float v57; // [esp+2Ch] [ebp+Ch]
  float v58; // [esp+2Ch] [ebp+Ch]
  float v59; // [esp+2Ch] [ebp+Ch]
  float v60; // [esp+2Ch] [ebp+Ch]
  float v61; // [esp+2Ch] [ebp+Ch]
  float v62; // [esp+2Ch] [ebp+Ch]
  float v63; // [esp+2Ch] [ebp+Ch]
  float v64; // [esp+2Ch] [ebp+Ch]
  float v65; // [esp+2Ch] [ebp+Ch]
  float v66; // [esp+2Ch] [ebp+Ch]

  v49 = *a3;
  v52 = a3[1];
  v47 = *this * v49 + *(this + 1) * v52 + *(this + 2);
  v48 = v49 * *(this + 3) + v52 * *(this + 4) + *(this + 5);
  v50 = a3[2];
  v45 = *this * v50 + *(this + 1) * v52 + *(this + 2);
  v46 = v50 * *(this + 3) + v52 * *(this + 4) + *(this + 5);
  v53 = a3[3];
  v43 = *this * v50 + *(this + 1) * v53 + *(this + 2);
  v44 = v50 * *(this + 3) + v53 * *(this + 4) + *(this + 5);
  v3 = *a3;
  v51 = *this * v3 + *(this + 1) * v53 + *(this + 2);
  v54 = v3 * *(this + 3) + v53 * *(this + 4) + *(this + 5);
  *a2 = v47;
  a2[1] = v48;
  a2[3] = v48;
  a2[2] = v47;
  if ( v45 <= (double)v47 )
  {
    v55 = v45;
    v4 = v47;
    v5 = v45;
  }
  else
  {
    v4 = v47;
    v5 = v45;
    v55 = v47;
  }
  v6 = v55;
  *a2 = v55;
  if ( v46 <= (double)v48 )
  {
    v56 = v46;
    v7 = v48;
    v8 = v46;
  }
  else
  {
    v7 = v48;
    v8 = v46;
    v56 = v48;
  }
  a2[1] = v56;
  v9 = v5;
  v10 = v56;
  if ( v9 >= v4 )
    v4 = v9;
  v11 = v7;
  v12 = v4;
  v13 = v11;
  v57 = v12;
  a2[2] = v57;
  v14 = v8;
  v15 = v57;
  if ( v14 >= v11 )
    v13 = v14;
  v16 = v6;
  v17 = v13;
  v18 = v16;
  v58 = v17;
  v19 = v58;
  a2[3] = v58;
  if ( v43 <= v16 )
  {
    v59 = v43;
    v21 = v43;
  }
  else
  {
    v20 = v18;
    v21 = v43;
    v59 = v20;
  }
  v22 = v59;
  *a2 = v59;
  if ( v44 <= v10 )
  {
    v60 = v44;
    v24 = v44;
  }
  else
  {
    v23 = v10;
    v24 = v44;
    v60 = v23;
  }
  a2[1] = v60;
  v25 = v21;
  v26 = v60;
  if ( v25 >= v15 )
    v15 = v25;
  v27 = v22;
  v28 = v15;
  v29 = v27;
  v61 = v28;
  a2[2] = v61;
  v30 = v24;
  v31 = v61;
  if ( v30 >= v19 )
    v19 = v30;
  v62 = v19;
  v32 = v62;
  a2[3] = v62;
  if ( v51 <= v29 )
  {
    v63 = v51;
    v34 = v51;
  }
  else
  {
    v33 = v29;
    v34 = v51;
    v63 = v33;
  }
  *a2 = v63;
  if ( v54 <= v26 )
  {
    v64 = v54;
    v36 = v54;
  }
  else
  {
    v35 = v26;
    v36 = v54;
    v64 = v35;
  }
  a2[1] = v64;
  v37 = v32;
  v38 = v34;
  v39 = v37;
  if ( v38 >= v31 )
    v31 = v38;
  v40 = v36;
  v41 = v31;
  v42 = v40;
  v65 = v41;
  a2[2] = v65;
  if ( v40 >= v39 )
    v66 = v42;
  else
    v66 = v39;
  a2[3] = v66;
}

//------------------------------------------------------------------------------
// Address: 0x10063180
// Name: public: void GMsgFormat::FormatD1<float>(float const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GMsgFormat::FormatD1<float>(
        CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *this,
        const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *v)
{
  bool result; // al
  GMemoryHeap **v4; // esi
  type_info *v5; // eax
  unsigned int v6; // edx
  GMemoryHeap *v7; // ecx
  struct GFormatter *v8; // eax

  result = GMsgFormat::NextFormatter((GMsgFormat *)this);
  if ( result )
  {
    v4 = (GMemoryHeap **)((char *)this + 244);
    do
    {
      if ( *((_DWORD *)this + 191) < 0x188u )
      {
        v7 = *v4;
        if ( *v4 == nullptr )
          v7 = GMemory::pGlobalHeap;
        v5 = (type_info *)v7->Alloc(this: v7, a2: 392u, a3: 4u, a4: nullptr);
      }
      else
      {
        v5 = *((type_info **)this + 190);
        *((_DWORD *)this + 190) = (((unsigned int)&v5[32]._M_data + 3) & 0xFFFFFFFC) + 4;
        v6 = (((unsigned int)&v5[32]._M_data + 3) & 0xFFFFFFFC) - (_DWORD)v4;
        if ( v6 >= 0x200 )
          *((_DWORD *)this + 191) = 0;
        else
          *((_DWORD *)this + 191) = 512 - v6;
      }
      if ( v5 != nullptr )
        v8 = (struct GFormatter *)GDoubleFormatter::GDoubleFormatter(this: v5, f: (const type_info *)this);
      else
        v8 = nullptr;
      GMsgFormat::Bind((GMsgFormat *)this, a2: v8, a3: true);
      result = GMsgFormat::NextFormatter((GMsgFormat *)this);
    }
    while ( result );
  }
  ++BYTE1(this->m_nAllocationCount);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10063250
// Name: unsigned int G_Format<float,float,float,float,float,float>(class GMsgFormat::Sink const __near &,char const __near *,float const __near &,float const __near &,float const __near &,float const __near &,float const __near &,float const __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl G_Format<float,float,float,float,float,float>(
        struct GMsgFormat::Sink *a1,
        CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *a2,
        const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *v1,
        const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *v2,
        const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *v3,
        const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *v4,
        const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *v5,
        const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *v6)
{
  int v8; // esi
  unsigned __int16 v10; // [esp+0h] [ebp-320h]
  unsigned __int16 v11; // [esp+0h] [ebp-320h]
  const CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> *parsed_format; // [esp+1Ch] [ebp-304h] BYREF
  int v13; // [esp+28h] [ebp-2F8h]

  GMsgFormat::GMsgFormat(this: &parsed_format, a2: a1);
  GMsgFormat::Parse(result: a2);
  GMsgFormat::FormatD1<float>(this: (CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *)&parsed_format, v: v1);
  GMsgFormat::FormatD1<float>(this: (CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *)&parsed_format, v: v2);
  GMsgFormat::FormatD1<float>(this: (CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *)&parsed_format, v: v3);
  GMsgFormat::FormatD1<float>(this: (CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *)&parsed_format, v: v4);
  GMsgFormat::FormatD1<float>(this: (CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *)&parsed_format, v: v5);
  GMsgFormat::FormatD1<float>(this: (CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *)&parsed_format, v: v6);
  GMsgFormat::FinishFormatD(
    this: (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&parsed_format,
    a2: v10);
  v8 = v13;
  GMsgFormat::~GMsgFormat(
    this: (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&parsed_format,
    data_size: v11);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x10063340
// Name: public: void GMatrix2D::Format(char __near *)const
// Source: json
//------------------------------------------------------------------------------
CCountedStringPoolBase<unsigned int>::hash_item_t *__thiscall GMatrix2D::Format(
        CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *this,
        char *pbuffer)
{
  double v2; // st7
  _DWORD v4[3]; // [esp+0h] [ebp-14h] BYREF
  float v5; // [esp+Ch] [ebp-8h] BYREF
  float v6; // [esp+10h] [ebp-4h] BYREF

  v2 = *((float *)this + 5);
  v4[1] = pbuffer;
  v4[0] = 2;
  v4[2] = 512;
  v6 = v2 / 20.0;
  v5 = *(float *)&this->m_Memory.m_nGrowSize / 20.0;
  return (CCountedStringPoolBase<unsigned int>::hash_item_t *)G_Format<float,float,float,float,float,float>(
                                                                a1: (struct GMsgFormat::Sink *)v4,
                                                                a2: (CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)"| {0:4.4} {1:4.4} {2:4.4} |\n| {3:4.4} {4:4.4} {5:4.4} |\n",
                                                                v1: (const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *)this,
                                                                v2: (const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *)&this->m_Memory.m_nAllocationCount,
                                                                v3: (const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *)&v5,
                                                                v4: (const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *)&this->m_Size,
                                                                v5: (const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *)&this->m_pElements,
                                                                (const CUtlMemory<CMatRenderContextBase::MatrixStackItem_t,int> *)&v6);
}

//------------------------------------------------------------------------------
// Address: 0x10095AC0
// Name: public: void GMsgFormat::FormatD1<class GStringDataPtr>(class GStringDataPtr const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GMsgFormat::FormatD1<GStringDataPtr>(int this, int v)
{
  bool result; // al
  GMemoryHeap **v4; // esi
  CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *v5; // eax
  unsigned int v6; // edx
  GMemoryHeap *v7; // ecx
  struct GFormatter *v8; // eax

  result = GMsgFormat::NextFormatter((GMsgFormat *)this);
  if ( result )
  {
    v4 = (GMemoryHeap **)(this + 244);
    do
    {
      if ( *(_DWORD *)(this + 764) < 0x14u )
      {
        v7 = *v4;
        if ( *v4 == nullptr )
          v7 = GMemory::pGlobalHeap;
        v5 = (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)v7->Alloc(
                                                                                this: v7,
                                                                                a2: 20u,
                                                                                a3: 4u,
                                                                                a4: nullptr);
      }
      else
      {
        v5 = *(CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> **)(this + 760);
        *(_DWORD *)(this + 760) = (((unsigned int)&v5[1].m_nAllocationCount + 3) & 0xFFFFFFFC) + 4;
        v6 = (((unsigned int)&v5[1].m_nAllocationCount + 3) & 0xFFFFFFFC) - (_DWORD)v4;
        if ( v6 >= 0x200 )
          *(_DWORD *)(this + 764) = 0;
        else
          *(_DWORD *)(this + 764) = 512 - v6;
      }
      if ( v5 != nullptr )
        GStrFormatter::GStrFormatter(this: v5, f: this, v);
      else
        v8 = nullptr;
      GMsgFormat::Bind((GMsgFormat *)this, a2: v8, a3: true);
      result = GMsgFormat::NextFormatter((GMsgFormat *)this);
    }
    while ( result );
  }
  ++*(_BYTE *)(this + 5);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101607B0
// Name: public: void GMsgFormat::FormatD1<class GStringLH>(class GStringLH const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GMsgFormat::FormatD1<GStringLH>(GMsgFormat *this, struct GString *a2)
{
  bool result; // al
  GMemoryHeap **v4; // esi
  GStrFormatter *v5; // eax
  unsigned int v6; // edx
  GMemoryHeap *v7; // ecx
  struct GFormatter *v8; // eax

  result = GMsgFormat::NextFormatter(this);
  if ( result )
  {
    v4 = (GMemoryHeap **)(this + 61);
    do
    {
      if ( (unsigned int)*(this + 191) < 0x14 )
      {
        v7 = *v4;
        if ( *v4 == nullptr )
          v7 = GMemory::pGlobalHeap;
        v5 = (GStrFormatter *)v7->Alloc(this: v7, a2: 20u, a3: 4u, a4: nullptr);
      }
      else
      {
        v5 = (GStrFormatter *)*(this + 190);
        *(this + 190) = (GMsgFormat)((((unsigned int)v5 + 19) & 0xFFFFFFFC) + 4);
        v6 = (((unsigned int)v5 + 19) & 0xFFFFFFFC) - (_DWORD)v4;
        if ( v6 >= 0x200 )
          *(this + 191) = nullptr;
        else
          *(this + 191) = (GMsgFormat)(512 - v6);
      }
      if ( v5 != nullptr )
        v8 = (struct GFormatter *)GStrFormatter::GStrFormatter(this: v5, a2: (struct GMsgFormat *)this, a3: a2);
      else
        v8 = nullptr;
      GMsgFormat::Bind(this, a2: v8, a3: true);
      result = GMsgFormat::NextFormatter(this);
    }
    while ( result );
  }
  ++*((_BYTE *)this + 5);
  return result;
}
