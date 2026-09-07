// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gkernel/gscreentoworld.cpp
// Functions: 4
// ============================================================

#include "thirdparty\scaleform\sdk\src\gkernel\gscreentoworld.h"

//------------------------------------------------------------------------------
// Address: 0x10106050
// Name: private: void GScreenToWorld::VectorMult(float __near *,float const __near *,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
float *__thiscall GScreenToWorld::VectorMult(
        CUtlBuffer *this,
        CUtlCharConversion *po,
        float *a3,
        float x,
        float y,
        float z,
        float w)
{
  *(float *)&po->__vftable = a3[12] * w + a3[8] * z + *a3 * x + a3[4] * y;
  *(float *)&po->m_nEscapeChar = a3[1] * x + a3[5] * y + a3[9] * z + a3[13] * w;
  *(float *)&po->m_pDelimiter = a3[2] * x + a3[6] * y + a3[10] * z + a3[14] * w;
  *(float *)&po->m_nDelimiterLength = w * a3[15] + y * a3[7] + x * a3[3] + z * a3[11];
  return a3;
}

//------------------------------------------------------------------------------
// Address: 0x101060F0
// Name: private: void GScreenToWorld::VectorMult(float __near *,float const __near *,float const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GScreenToWorld::VectorMult(CUtlBuffer *this, CUtlCharConversion *po, float *pa, float *v)
{
  *(float *)&po->__vftable = pa[4] * v[1] + *pa * *v + pa[8] * v[2] + pa[12] * v[3];
  *(float *)&po->m_nEscapeChar = pa[1] * *v + pa[5] * v[1] + pa[9] * v[2] + pa[13] * v[3];
  *(float *)&po->m_pDelimiter = pa[2] * *v + pa[6] * v[1] + pa[10] * v[2] + pa[14] * v[3];
  *(float *)&po->m_nDelimiterLength = pa[3] * *v + pa[7] * v[1] + pa[11] * v[2] + pa[15] * v[3];
}

//------------------------------------------------------------------------------
// Address: 0x10106180
// Name: public: void GScreenToWorld::GetWorldPoint(class GPoint3<float> __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall GScreenToWorld::GetWorldPoint(CUtlBuffer *this, float a2)
{
  bool v3; // zf
  GMatrix3D *m_nTab; // eax
  GMatrix3D *v5; // esi
  float *v6; // eax
  float *v7; // edx
  float v8; // eax
  double v9; // st7
  double v10; // st6
  double result; // st7
  float v12; // [esp+4h] [ebp-158h]
  float v13; // [esp+4h] [ebp-158h]
  float v14; // [esp+8h] [ebp-154h]
  float v15; // [esp+8h] [ebp-154h]
  float v16; // [esp+1Ch] [ebp-140h] BYREF
  float v17; // [esp+20h] [ebp-13Ch]
  float v18; // [esp+24h] [ebp-138h]
  float v19; // [esp+28h] [ebp-134h]
  int v20; // [esp+2Ch] [ebp-130h] BYREF
  float v21; // [esp+30h] [ebp-12Ch]
  float v22; // [esp+34h] [ebp-128h]
  float v23; // [esp+38h] [ebp-124h]
  int v; // [esp+3Ch] [ebp-120h] BYREF
  float v25; // [esp+40h] [ebp-11Ch]
  float v26; // [esp+44h] [ebp-118h]
  float v27; // [esp+48h] [ebp-114h]
  float mz; // [esp+4Ch] [ebp-110h]
  float v29; // [esp+50h] [ebp-10Ch]
  float v30; // [esp+54h] [ebp-108h]
  float v31[16]; // [esp+58h] [ebp-104h] BYREF
  GMatrix3D v32; // [esp+98h] [ebp-C4h] BYREF
  GMatrix3D v33; // [esp+D8h] [ebp-84h] BYREF
  GMatrix3D v34; // [esp+118h] [ebp-44h] BYREF

  v3 = this->m_Put == 0;
  v29 = a2;
  if ( !v3 && *(_DWORD *)&this->m_Error != 0 && this->m_nTab != 0 )
  {
    GMatrix3D::SetIdentity(this: &v34);
    GMatrix3D::SetIdentity(this: &v33);
    GMatrix3D::SetIdentity(this: &v32);
    GMatrix3D::MatrixInverse(
      this: (CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *)&v34,
      po: (float *)&v34,
      a3: (float *)this->m_Put);
    m_nTab = (GMatrix3D *)this->m_nTab;
    v32 = *m_nTab;
    v5 = m_nTab;
    v6 = *(float **)&this->m_Error;
    qmemcpy(v31, v5, sizeof(v31));
    GMatrix3D::MultiplyMatrix(this: (CBasePerMaterialContextData *)&v32, a2: v31, a3: v6);
    GMatrix3D::MatrixInverse(
      this: (CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *)&v33,
      po: (float *)&v33,
      a3: (float *)&v32);
    GScreenToWorld::VectorMult(
      this,
      po: (CUtlCharConversion *)&v16,
      a3: (float *)this->m_Put,
      x: 0.0,
      y: 0.0,
      z: -0.5,
      w: 1.0);
    GScreenToWorld::VectorMult(this, po: (CUtlCharConversion *)&v20, a3: v7, x: 0.0, y: 0.0, z: -100.0, w: 1.0);
    v30 = v18 * v19;
    v14 = v30;
    v30 = *(float *)&this->m_Memory.m_nAllocationCount * v19;
    v12 = v30;
    v30 = v19 * *(float *)&this->m_Memory.m_pMemory;
    GScreenToWorld::VectorMult(this, po: (CUtlCharConversion *)&v, a3: (float *)&v34, x: v30, y: v12, z: v14, w: v19);
    v30 = v22 * v23;
    v15 = v30;
    v30 = *(float *)&this->m_Memory.m_nAllocationCount * v23;
    v13 = v30;
    v30 = v23 * *(float *)&this->m_Memory.m_pMemory;
    GScreenToWorld::VectorMult(this, po: (CUtlCharConversion *)&v20, a3: (float *)&v34, x: v30, y: v13, z: v15, w: v23);
    *(float *)&v = v27 * *(float *)&v;
    v25 = v25 * v27;
    v26 = v27 * v26;
    v27 = 1.0;
    *(float *)&v20 = v23 * *(float *)&v20;
    v21 = v21 * v23;
    v22 = v23 * v22;
    v23 = 1.0;
    GScreenToWorld::VectorMult(this, po: (CUtlCharConversion *)&v16, pa: (float *)&v33, (float *)&v);
    GScreenToWorld::VectorMult(this, po: (CUtlCharConversion *)&v, pa: (float *)&v33, v: (float *)&v20);
    v30 = v26 - v18;
    mz = -v18 / v30;
    v30 = *(float *)&v - v16;
    v8 = v29;
    v9 = mz;
    mz = v16 + v30 * mz;
    v10 = mz;
    *(float *)LODWORD(v29) = mz;
    *(float *)&this->m_Memory.m_nGrowSize = v10;
    v29 = v25 - v17;
    v29 = v9 * v29 + v17;
    result = v29;
    *(float *)(LODWORD(v8) + 4) = v29;
    *(float *)&this->m_Get = result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101064A0
// Name: public: void GScreenToWorld::GetWorldPoint(class GPoint<float> __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall GScreenToWorld::GetWorldPoint(CUtlBuffer *this, float *a2)
{
  double result; // st7
  float v3[3]; // [esp+0h] [ebp-Ch] BYREF

  result = GScreenToWorld::GetWorldPoint(this, a2: COERCE_FLOAT(v3));
  *a2 = v3[0];
  a2[1] = v3[1];
  return result;
}
