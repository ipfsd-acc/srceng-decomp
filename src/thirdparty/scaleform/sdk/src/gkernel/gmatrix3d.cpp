// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gkernel/gmatrix3d.cpp
// Functions: 16
// ============================================================

#include "thirdparty\scaleform\sdk\src\gkernel\gmatrix3d.h"

//------------------------------------------------------------------------------
// Address: 0x100615F0
// Name: private: void GMatrix3D::MatrixInverse(float __near *,float const __near *)const
// Source: json
//------------------------------------------------------------------------------
float *__thiscall GMatrix3D::MatrixInverse(
        CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *this,
        float *po,
        float *a3)
{
  _DWORD *v3; // edx
  _DWORD *v4; // ebx
  int v5; // edi
  int v6; // ecx
  int v7; // edx
  int v8; // esi
  int v9; // esi
  _DWORD *v10; // ebx
  float *v11; // esi
  float *v12; // edx
  float *v13; // ecx
  int v14; // edi
  double v15; // st7
  float *v16; // ecx
  double v17; // st6
  double v18; // st5
  double v20; // st4
  float *v21; // [esp+10h] [ebp-A0h]
  int j; // [esp+14h] [ebp-9Ch]
  float *k; // [esp+18h] [ebp-98h]
  float *v24; // [esp+1Ch] [ebp-94h]
  float *v25; // [esp+20h] [ebp-90h]
  float *v26; // [esp+24h] [ebp-8Ch]
  float v27; // [esp+24h] [ebp-8Ch]
  float *v28; // [esp+28h] [ebp-88h]
  float v29; // [esp+28h] [ebp-88h]
  int i; // [esp+2Ch] [ebp-84h]
  float ia; // [esp+2Ch] [ebp-84h]
  float ib; // [esp+2Ch] [ebp-84h]
  float ic; // [esp+2Ch] [ebp-84h]
  _DWORD *det; // [esp+30h] [ebp-80h]
  float deta; // [esp+30h] [ebp-80h]
  float detb; // [esp+30h] [ebp-80h]
  float *v37; // [esp+34h] [ebp-7Ch]
  float v38; // [esp+34h] [ebp-7Ch]
  float v39; // [esp+34h] [ebp-7Ch]
  _DWORD *v40; // [esp+38h] [ebp-78h]
  float v41; // [esp+38h] [ebp-78h]
  float v42; // [esp+38h] [ebp-78h]
  float v43; // [esp+38h] [ebp-78h]
  float v44; // [esp+3Ch] [ebp-74h] BYREF
  float v45; // [esp+40h] [ebp-70h]
  float v46; // [esp+44h] [ebp-6Ch]
  float v47; // [esp+48h] [ebp-68h]
  float v48; // [esp+4Ch] [ebp-64h]
  float v49; // [esp+50h] [ebp-60h]
  float v50; // [esp+54h] [ebp-5Ch]
  float v51; // [esp+58h] [ebp-58h]
  float v52; // [esp+5Ch] [ebp-54h]
  float v53; // [esp+60h] [ebp-50h]
  float v54; // [esp+64h] [ebp-4Ch]
  float v55; // [esp+68h] [ebp-48h]
  float v56; // [esp+6Ch] [ebp-44h]
  float v57; // [esp+70h] [ebp-40h]
  float v58; // [esp+74h] [ebp-3Ch]
  float v59; // [esp+78h] [ebp-38h]
  _DWORD v60[2]; // [esp+7Ch] [ebp-34h] BYREF
  _DWORD v61[10]; // [esp+84h] [ebp-2Ch] BYREF

  v3 = v61;
  v4 = v60;
  i = 0;
  det = v61;
  j = 0;
  v40 = v60;
  for ( k = &v44; ; k = v16 )
  {
    do
    {
      v61[1] = 0;
      v61[4] = 0;
      v61[7] = 0;
      v60[0] = 1;
      v61[5] = 1;
      v61[8] = 1;
      v61[0] = 3;
      v61[3] = 3;
      v61[6] = 3;
      v60[1] = 2;
      v61[2] = 2;
      v61[9] = 2;
      v5 = v4[1];
      v6 = 4 * *(v3 - 1);
      v25 = &a3[v6 + v5];
      v7 = 4 * *(v3 - 2);
      v21 = &a3[v7 + *v4];
      v8 = 4 * *det;
      v28 = &a3[v8 + v4[2]];
      v26 = &a3[v8 + v5];
      v24 = &a3[v6 + *v40];
      v37 = &a3[v7 + v40[2]];
      v9 = *v40 + v8;
      v10 = v40;
      v41 = *v25 * *v21 * *v28;
      v11 = &a3[v9];
      v12 = &a3[v5 + v7];
      v13 = &a3[v10[2] + v6];
      v42 = v41 + *v24 * *v26 * *v37;
      v43 = v42 + *v11 * *v12 * *v13;
      v14 = i;
      v27 = v43 - *v21 * *v26 * *v13;
      v29 = v27 - *v24 * *v12 * *v28;
      v38 = v29 - *v25 * *v11 * *v37;
      v15 = v38;
      if ( (((_BYTE)j + (_BYTE)i) & 1) != 0 )
        v15 = -v15;
      v39 = v15;
      v3 = det;
      *k = v39;
      v16 = k + 1;
      v4 = v10 + 3;
      ++j;
      ++k;
      v40 = v4;
    }
    while ( j < 4 );
    v3 = det + 3;
    ++i;
    det += 3;
    if ( v14 + 1 >= 4 )
      break;
    v4 = v60;
    j = 0;
    v40 = v60;
  }
  ia = *a3 * v44 + 0.0;
  v17 = v45;
  ib = a3[1] * v45 + ia;
  v18 = v46;
  ic = a3[2] * v46 + ib;
  v20 = v47;
  deta = a3[3] * v47 + ic;
  detb = 1.0 / deta;
  *po = v44 * detb;
  po[4] = v17 * detb;
  po[8] = v18 * detb;
  po[12] = v20 * detb;
  po[1] = v48 * detb;
  po[5] = v49 * detb;
  po[9] = v50 * detb;
  po[13] = v51 * detb;
  po[2] = v52 * detb;
  po[6] = v53 * detb;
  po[10] = v54 * detb;
  po[14] = v55 * detb;
  po[3] = v56 * detb;
  po[7] = v57 * detb;
  po[11] = v58 * detb;
  po[15] = detb * v59;
  return po;
}

//------------------------------------------------------------------------------
// Address: 0x10061910
// Name: public: GMatrix3D::GMatrix3D(class GMatrix2D const __near &)
// Source: json
//------------------------------------------------------------------------------
GMatrix3D *__thiscall GMatrix3D::GMatrix3D(GMatrix3D *this, const struct GMatrix2D *a2)
{
  this->M_[0][0] = a2->M_[0][0];
  this->M_[1][0] = a2->M_[0][1];
  this->M_[2][0] = 0.0;
  this->M_[3][0] = a2->M_[0][2];
  this->M_[0][1] = a2->M_[1][0];
  this->M_[1][1] = a2->M_[1][1];
  this->M_[2][1] = 0.0;
  this->M_[3][1] = a2->M_[1][2];
  this->M_[0][2] = 0.0;
  this->M_[1][2] = 0.0;
  this->M_[2][2] = 1.0;
  this->M_[3][3] = 1.0;
  this->M_[3][2] = 0.0;
  this->M_[0][3] = 0.0;
  this->M_[1][3] = 0.0;
  this->M_[2][3] = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10061960
// Name: public: bool GMatrix3D::IsValid(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall GMatrix3D::IsValid(CBitVecT<CVarBitVecBase<unsigned short> > *this)
{
  return *(float *)&this->m_numBits >= -3.402823466385289e38
      && *(float *)&this->m_numBits <= 3.402823466385289e38
      && *(float *)&this->m_iBitStringStorage >= -3.402823466385289e38
      && *(float *)&this->m_iBitStringStorage <= 3.402823466385289e38
      && *(float *)&this->m_pInt >= -3.402823466385289e38
      && *(float *)&this->m_pInt <= 3.402823466385289e38
      && *((float *)this + 3) >= -3.402823466385289e38
      && *((float *)this + 3) <= 3.402823466385289e38
      && *((float *)this + 4) >= -3.402823466385289e38
      && *((float *)this + 4) <= 3.402823466385289e38
      && *((float *)this + 5) >= -3.402823466385289e38
      && *((float *)this + 5) <= 3.402823466385289e38
      && *((float *)this + 6) >= -3.402823466385289e38
      && *((float *)this + 6) <= 3.402823466385289e38
      && *((float *)this + 7) >= -3.402823466385289e38
      && *((float *)this + 7) <= 3.402823466385289e38
      && *((float *)this + 8) >= -3.402823466385289e38
      && *((float *)this + 8) <= 3.402823466385289e38
      && *((float *)this + 9) >= -3.402823466385289e38
      && *((float *)this + 9) <= 3.402823466385289e38
      && *((float *)this + 10) >= -3.402823466385289e38
      && *((float *)this + 10) <= 3.402823466385289e38
      && *((float *)this + 11) >= -3.402823466385289e38
      && *((float *)this + 11) <= 3.402823466385289e38
      && *((float *)this + 12) >= -3.402823466385289e38
      && *((float *)this + 12) <= 3.402823466385289e38
      && *((float *)this + 13) >= -3.402823466385289e38
      && *((float *)this + 13) <= 3.402823466385289e38
      && *((float *)this + 14) >= -3.402823466385289e38
      && *((float *)this + 14) <= 3.402823466385289e38
      && *((float *)this + 15) >= -3.402823466385289e38
      && *((float *)this + 15) <= 3.402823466385289e38;
}

//------------------------------------------------------------------------------
// Address: 0x10061B60
// Name: public: void GMatrix3D::SetIdentity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GMatrix3D::SetIdentity(GMatrix3D *this)
{
  memset(dst: (unsigned __int8 *)this, value: 0, count: sizeof(GMatrix3D));
  this->M_[0][0] = 1.0;
  this->M_[1][1] = 1.0;
  this->M_[2][2] = 1.0;
  this->M_[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x10061B80
// Name: public: void GMatrix3D::MultiplyMatrix(class GMatrix3D const __near &,class GMatrix3D const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GMatrix3D::MultiplyMatrix(CBasePerMaterialContextData *this, float *a2, float *a3)
{
  *(float *)&this->__vftable = *a2 * *a3 + a2[1] * a3[4] + a3[8] * a2[2] + a3[12] * a2[3];
  *(float *)&this->m_nVarChangeID = a3[5] * a2[1] + *a2 * a3[1] + a3[9] * a2[2] + a2[3] * a3[13];
  *(float *)&this->m_bMaterialVarsChanged = a3[6] * a2[1] + a3[2] * *a2 + a2[2] * a3[10] + a2[3] * a3[14];
  *((float *)this + 3) = a3[7] * a2[1] + *a2 * a3[3] + a3[11] * a2[2] + a2[3] * a3[15];
  *((float *)this + 4) = a2[5] * a3[4] + a2[4] * *a3 + a3[8] * a2[6] + a3[12] * a2[7];
  *((float *)this + 5) = a2[4] * a3[1] + a3[5] * a2[5] + a3[9] * a2[6] + a2[7] * a3[13];
  *((float *)this + 6) = a2[5] * a3[6] + a2[4] * a3[2] + a2[6] * a3[10] + a3[14] * a2[7];
  *((float *)this + 7) = a2[4] * a3[3] + a3[7] * a2[5] + a3[11] * a2[6] + a2[7] * a3[15];
  *((float *)this + 8) = a2[9] * a3[4] + a2[8] * *a3 + a3[8] * a2[10] + a3[12] * a2[11];
  *((float *)this + 9) = a2[8] * a3[1] + a3[5] * a2[9] + a3[9] * a2[10] + a2[11] * a3[13];
  *((float *)this + 10) = a2[9] * a3[6] + a2[8] * a3[2] + a2[10] * a3[10] + a3[14] * a2[11];
  *((float *)this + 11) = a2[8] * a3[3] + a3[7] * a2[9] + a3[11] * a2[10] + a2[11] * a3[15];
  *((float *)this + 12) = *a3 * a2[12] + a2[13] * a3[4] + a2[14] * a3[8] + a3[12] * a2[15];
  *((float *)this + 13) = a3[5] * a2[13] + a2[12] * a3[1] + a2[14] * a3[9] + a2[15] * a3[13];
  *((float *)this + 14) = a3[2] * a2[12] + a3[6] * a2[13] + a2[14] * a3[10] + a3[14] * a2[15];
  *((float *)this + 15) = a3[7] * a2[13] + a2[12] * a3[3] + a2[14] * a3[11] + a2[15] * a3[15];
}

//------------------------------------------------------------------------------
// Address: 0x10061DA0
// Name: private: void GMatrix3D::GetEulerAngles(float __near *,float __near *,float __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GMatrix3D::GetEulerAngles(
        CBasePerMaterialContextData *this,
        const CBasePerMaterialContextData *eX,
        float *eY,
        float *eZ)
{
  float *v5; // eax
  double v6; // st7
  float eYa; // [esp+14h] [ebp+Ch]
  float eYb; // [esp+14h] [ebp+Ch]
  float eYc; // [esp+14h] [ebp+Ch]
  float eYd; // [esp+14h] [ebp+Ch]
  float eYe; // [esp+14h] [ebp+Ch]

  if ( *(float *)&this->m_nVarChangeID > 0.9980000257492065 )
  {
    if ( eY != nullptr )
    {
      eYa = atan2(*((float *)this + 8), *((float *)this + 10));
      *eY = eYa;
    }
    v5 = eZ;
    if ( eZ != nullptr )
    {
      v6 = 1.5707964;
LABEL_6:
      *v5 = v6;
    }
LABEL_7:
    if ( eX != nullptr )
      *(float *)&eX->__vftable = 0.0;
    return;
  }
  if ( *(float *)&this->m_nVarChangeID < -0.9980000257492065 )
  {
    if ( eY != nullptr )
    {
      eYb = atan2(*((float *)this + 8), *((float *)this + 10));
      *eY = eYb;
    }
    v5 = eZ;
    if ( eZ == nullptr )
      goto LABEL_7;
    v6 = -1.5707964;
    goto LABEL_6;
  }
  if ( eY != nullptr )
  {
    eYc = atan2(-*(float *)&this->m_bMaterialVarsChanged, *(float *)&this->__vftable);
    *eY = eYc;
  }
  if ( eX != nullptr )
  {
    eYd = atan2(-*((float *)this + 9), *((float *)this + 5));
    *(float *)&eX->__vftable = eYd;
  }
  if ( eZ != nullptr )
  {
    eYe = asin(*(float *)&this->m_nVarChangeID);
    *eZ = eYe;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10061E80
// Name: public: void GMatrix3D::RotateX(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GMatrix3D::RotateX(GMatrix3D *this, float a2)
{
  float v3; // [esp+4h] [ebp-4h]
  float v4; // [esp+10h] [ebp+8h]

  memset(dst: (unsigned __int8 *)this, value: 0, count: sizeof(GMatrix3D));
  this->M_[3][3] = 1.0;
  v3 = cos(a2);
  v4 = sin(a2);
  this->M_[0][0] = 1.0;
  this->M_[0][1] = 0.0;
  this->M_[0][2] = 0.0;
  this->M_[1][0] = 0.0;
  this->M_[1][1] = v3;
  this->M_[1][2] = v4;
  this->M_[2][0] = 0.0;
  this->M_[2][1] = -v4;
  this->M_[2][2] = v3;
}

//------------------------------------------------------------------------------
// Address: 0x10061EF0
// Name: public: void GMatrix3D::RotateY(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GMatrix3D::RotateY(GMatrix3D *this, float a2)
{
  float v3; // [esp+4h] [ebp-4h]
  float v4; // [esp+10h] [ebp+8h]

  memset(dst: (unsigned __int8 *)this, value: 0, count: sizeof(GMatrix3D));
  this->M_[3][3] = 1.0;
  v3 = cos(a2);
  v4 = sin(a2);
  this->M_[0][0] = v3;
  this->M_[0][1] = 0.0;
  this->M_[0][2] = -v4;
  this->M_[1][0] = 0.0;
  this->M_[1][1] = 1.0;
  this->M_[1][2] = 0.0;
  this->M_[2][1] = 0.0;
  this->M_[2][0] = v4;
  this->M_[2][2] = v3;
}

//------------------------------------------------------------------------------
// Address: 0x10061F60
// Name: public: void GMatrix3D::PerspectiveRH(float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GMatrix3D::PerspectiveRH(GMatrix3D *this, float a2, float a3, float a4, float a5)
{
  float v6; // [esp+4h] [ebp-8h]
  float v7; // [esp+8h] [ebp-4h]
  float v8; // [esp+14h] [ebp+8h]
  float v9; // [esp+14h] [ebp+8h]
  float v10; // [esp+14h] [ebp+8h]

  memset(dst: (unsigned __int8 *)this, value: 0, count: sizeof(GMatrix3D));
  v6 = a4 - a5;
  v8 = a2 * 0.5;
  v7 = cos(v8);
  v9 = sin(v8);
  v10 = v7 / v9;
  this->M_[0][0] = v10 / a3;
  this->M_[1][1] = v10;
  this->M_[2][2] = a5 / v6;
  this->M_[2][3] = -1.0;
  this->M_[3][2] = a5 * a4 / v6;
}

//------------------------------------------------------------------------------
// Address: 0x10061FF0
// Name: public: void GMatrix3D::PerspectiveLH(float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GMatrix3D::PerspectiveLH(GMatrix3D *this, float a2, float a3, float a4, float a5)
{
  float v6; // [esp+4h] [ebp-8h]
  float v7; // [esp+8h] [ebp-4h]
  float v8; // [esp+14h] [ebp+8h]
  float v9; // [esp+14h] [ebp+8h]
  float v10; // [esp+14h] [ebp+8h]

  memset(dst: (unsigned __int8 *)this, value: 0, count: sizeof(GMatrix3D));
  v6 = a5 - a4;
  v8 = a2 * 0.5;
  v7 = cos(v8);
  v9 = sin(v8);
  v10 = v7 / v9;
  this->M_[0][0] = v10 / a3;
  this->M_[1][1] = v10;
  this->M_[2][2] = a5 / v6;
  this->M_[2][3] = 1.0;
  this->M_[3][2] = a5 * -a4 / v6;
}

//------------------------------------------------------------------------------
// Address: 0x10062080
// Name: public: void GMatrix3D::Transpose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GMatrix3D::Transpose(GMatrix3D *this)
{
  GMatrix3D dst; // [esp+8h] [ebp-44h] BYREF

  memset((unsigned __int8 *)&dst, value: 0, count: sizeof(dst));
  dst.M_[0][0] = this->M_[0][0];
  dst.M_[1][0] = this->M_[0][1];
  dst.M_[2][0] = this->M_[0][2];
  dst.M_[3][0] = this->M_[0][3];
  dst.M_[0][1] = this->M_[1][0];
  dst.M_[1][1] = this->M_[1][1];
  dst.M_[2][1] = this->M_[1][2];
  dst.M_[3][1] = this->M_[1][3];
  dst.M_[0][2] = this->M_[2][0];
  dst.M_[1][2] = this->M_[2][1];
  dst.M_[2][2] = this->M_[2][2];
  dst.M_[3][2] = this->M_[2][3];
  dst.M_[0][3] = this->M_[3][0];
  dst.M_[1][3] = this->M_[3][1];
  dst.M_[2][3] = this->M_[3][2];
  dst.M_[3][3] = this->M_[3][3];
  *this = dst;
}

//------------------------------------------------------------------------------
// Address: 0x10062120
// Name: public: void GMatrix3D::ViewRH(class GPoint3<float> const __near &,class GPoint3<float> const __near &,class GPoint3<float> const __near &)
// Source: json
//------------------------------------------------------------------------------
float *__thiscall GMatrix3D::ViewRH(
        CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *this,
        float *eyePt,
        float *lookAtPt,
        float *upVec)
{
  int v7; // [esp+8h] [ebp-24h]
  float v8; // [esp+Ch] [ebp-20h]
  float v9; // [esp+10h] [ebp-1Ch]
  float v10; // [esp+14h] [ebp-18h]
  float v11; // [esp+14h] [ebp-18h]
  float v12; // [esp+18h] [ebp-14h]
  float v13; // [esp+18h] [ebp-14h]
  float v14; // [esp+1Ch] [ebp-10h]
  float v15; // [esp+1Ch] [ebp-10h]
  float v16; // [esp+20h] [ebp-Ch]
  int v17; // [esp+20h] [ebp-Ch]
  float v18; // [esp+24h] [ebp-8h]
  float v19; // [esp+24h] [ebp-8h]
  float v20; // [esp+28h] [ebp-4h]
  float v21; // [esp+28h] [ebp-4h]
  float eyePta; // [esp+34h] [ebp+8h]
  float eyePtb; // [esp+34h] [ebp+8h]
  float eyePtc; // [esp+34h] [ebp+8h]
  float eyePtd; // [esp+34h] [ebp+8h]
  float eyePte; // [esp+34h] [ebp+8h]
  float eyePtf; // [esp+34h] [ebp+8h]
  float eyePtg; // [esp+34h] [ebp+8h]

  memset(dst: (unsigned __int8 *)this, value: 0, count: 0x40u);
  v16 = *eyePt - *lookAtPt;
  v18 = eyePt[1] - lookAtPt[1];
  v20 = eyePt[2] - lookAtPt[2];
  eyePta = v18 * v18 + v16 * v16 + v20 * v20;
  eyePtb = sqrt(eyePta);
  *(float *)&v17 = v16 / eyePtb;
  v19 = v18 / eyePtb;
  v21 = v20 / eyePtb;
  v10 = upVec[1] * v21 - upVec[2] * v19;
  v12 = upVec[2] * *(float *)&v17 - v21 * *upVec;
  v14 = v19 * *upVec - *(float *)&v17 * upVec[1];
  eyePtc = v12 * v12 + v10 * v10 + v14 * v14;
  eyePtd = sqrt(eyePtc);
  v11 = v10 / eyePtd;
  v13 = v12 / eyePtd;
  v15 = v14 / eyePtd;
  *(float *)&v7 = v19 * v15 - v21 * v13;
  v8 = v21 * v11 - *(float *)&v17 * v15;
  v9 = *(float *)&v17 * v13 - v19 * v11;
  *(float *)&this->m_Memory.m_pMemory = v11;
  *(float *)&this->m_pElements = v13;
  *((float *)this + 8) = v15;
  eyePte = v15 * eyePt[2] + v13 * eyePt[1] + v11 * *eyePt;
  *((float *)this + 12) = -eyePte;
  this->m_Memory.m_nAllocationCount = v7;
  *((float *)this + 5) = v8;
  *((float *)this + 9) = v9;
  eyePtf = v9 * eyePt[2] + v8 * eyePt[1] + *(float *)&v7 * *eyePt;
  *((float *)this + 13) = -eyePtf;
  this->m_Memory.m_nGrowSize = v17;
  *((float *)this + 6) = v19;
  *((float *)this + 10) = v21;
  eyePtg = v21 * eyePt[2] + v19 * eyePt[1] + *(float *)&v17 * *eyePt;
  *((float *)this + 14) = -eyePtg;
  *((float *)this + 15) = 1.0;
  return upVec;
}

//------------------------------------------------------------------------------
// Address: 0x10062310
// Name: public: void GMatrix3D::ViewLH(class GPoint3<float> const __near &,class GPoint3<float> const __near &,class GPoint3<float> const __near &)
// Source: json
//------------------------------------------------------------------------------
float *__thiscall GMatrix3D::ViewLH(
        CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *this,
        float *eyePt,
        float *lookAtPt,
        float *upVec)
{
  int v7; // [esp+8h] [ebp-24h]
  float v8; // [esp+Ch] [ebp-20h]
  float v9; // [esp+10h] [ebp-1Ch]
  float v10; // [esp+14h] [ebp-18h]
  float v11; // [esp+14h] [ebp-18h]
  float v12; // [esp+18h] [ebp-14h]
  float v13; // [esp+18h] [ebp-14h]
  float v14; // [esp+1Ch] [ebp-10h]
  float v15; // [esp+1Ch] [ebp-10h]
  float v16; // [esp+20h] [ebp-Ch]
  int v17; // [esp+20h] [ebp-Ch]
  float v18; // [esp+24h] [ebp-8h]
  float v19; // [esp+24h] [ebp-8h]
  float v20; // [esp+28h] [ebp-4h]
  float v21; // [esp+28h] [ebp-4h]
  float lookAtPta; // [esp+38h] [ebp+Ch]
  float lookAtPtb; // [esp+38h] [ebp+Ch]
  float lookAtPtc; // [esp+38h] [ebp+Ch]
  float lookAtPtd; // [esp+38h] [ebp+Ch]
  float lookAtPte; // [esp+38h] [ebp+Ch]
  float lookAtPtf; // [esp+38h] [ebp+Ch]
  float lookAtPtg; // [esp+38h] [ebp+Ch]

  memset(dst: (unsigned __int8 *)this, value: 0, count: 0x40u);
  v16 = *lookAtPt - *eyePt;
  v18 = lookAtPt[1] - eyePt[1];
  v20 = lookAtPt[2] - eyePt[2];
  lookAtPta = v18 * v18 + v16 * v16 + v20 * v20;
  lookAtPtb = sqrt(lookAtPta);
  *(float *)&v17 = v16 / lookAtPtb;
  v19 = v18 / lookAtPtb;
  v21 = v20 / lookAtPtb;
  v10 = upVec[1] * v21 - upVec[2] * v19;
  v12 = upVec[2] * *(float *)&v17 - v21 * *upVec;
  v14 = v19 * *upVec - *(float *)&v17 * upVec[1];
  lookAtPtc = v12 * v12 + v10 * v10 + v14 * v14;
  lookAtPtd = sqrt(lookAtPtc);
  v11 = v10 / lookAtPtd;
  v13 = v12 / lookAtPtd;
  v15 = v14 / lookAtPtd;
  *(float *)&v7 = v19 * v15 - v21 * v13;
  v8 = v21 * v11 - *(float *)&v17 * v15;
  v9 = *(float *)&v17 * v13 - v19 * v11;
  *(float *)&this->m_Memory.m_pMemory = v11;
  *(float *)&this->m_pElements = v13;
  *((float *)this + 8) = v15;
  lookAtPte = v15 * eyePt[2] + v13 * eyePt[1] + v11 * *eyePt;
  *((float *)this + 12) = -lookAtPte;
  this->m_Memory.m_nAllocationCount = v7;
  *((float *)this + 5) = v8;
  *((float *)this + 9) = v9;
  lookAtPtf = v9 * eyePt[2] + v8 * eyePt[1] + *(float *)&v7 * *eyePt;
  *((float *)this + 13) = -lookAtPtf;
  this->m_Memory.m_nGrowSize = v17;
  *((float *)this + 6) = v19;
  *((float *)this + 10) = v21;
  lookAtPtg = v21 * eyePt[2] + v19 * eyePt[1] + *(float *)&v17 * *eyePt;
  *((float *)this + 14) = -lookAtPtg;
  *((float *)this + 15) = 1.0;
  return upVec;
}

//------------------------------------------------------------------------------
// Address: 0x10062500
// Name: public: void GMatrix3D::Transform(class GPoint<float> __near *,class GPoint<float> const __near &,bool)const
// Source: json
//------------------------------------------------------------------------------
float *__thiscall GMatrix3D::Transform(float *this, float *a2, float *bDivideByW, float a4)
{
  double v4; // st6
  double v5; // st7
  float *result; // eax
  float v7; // [esp+0h] [ebp-Ch]
  float v8; // [esp+4h] [ebp-8h]
  float v9; // [esp+1Ch] [ebp+10h]

  v4 = bDivideByW[1];
  v5 = *bDivideByW;
  v7 = *this * v5 + *(this + 4) * v4 + *(this + 8) + *(this + 12);
  v8 = *(this + 1) * v5 + *(this + 5) * v4 + *(this + 9) + *(this + 13);
  result = a2;
  if ( LOBYTE(a4) != 0 )
  {
    v9 = v5 * *(this + 3) + v4 * *(this + 7) + *(this + 11) + *(this + 15);
    v7 = v7 / v9;
    v8 = v8 / v9;
  }
  *a2 = v7;
  a2[1] = v8;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100625B0
// Name: public: void GMatrix3D::EncloseTransform(class GRect<float> __near *,class GRect<float> const __near &,bool)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GMatrix3D::EncloseTransform(
        float *this,
        const CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *result,
        CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *r,
        float bDivideByW)
{
  double v5; // st7
  double v6; // st6
  double v7; // rt0
  double v8; // st6
  double v9; // st7
  double v10; // st5
  double v11; // st6
  double v12; // st4
  double v13; // st3
  double v14; // st7
  double v15; // st2
  double v16; // st6
  double v17; // rt2
  double v18; // st3
  double v19; // st5
  double v20; // st3
  double v21; // st7
  double v22; // rt0
  double v23; // st4
  double v24; // st5
  double v25; // st4
  double v26; // st3
  double v27; // st5
  double v28; // st3
  double v29; // st2
  double v30; // st6
  double v31; // st2
  double v32; // st5
  double v33; // rt0
  double v34; // st3
  double v35; // st7
  double v36; // st3
  double v37; // st6
  double v38; // st4
  double v39; // st3
  double v40; // st7
  double v41; // st3
  double v42; // st5
  double v43; // rt0
  double v44; // st4
  double v45; // st7
  double v46; // rt1
  double v47; // st5
  double v48; // st6
  int v49; // [esp+Ch] [ebp-28h] BYREF
  float v50; // [esp+10h] [ebp-24h]
  int v51; // [esp+14h] [ebp-20h] BYREF
  float v52; // [esp+18h] [ebp-1Ch]
  int v53; // [esp+1Ch] [ebp-18h] BYREF
  float v54; // [esp+20h] [ebp-14h]
  int v55; // [esp+24h] [ebp-10h] BYREF
  int v56; // [esp+28h] [ebp-Ch]
  int m_pMemory; // [esp+2Ch] [ebp-8h] BYREF
  int m_nAllocationCount; // [esp+30h] [ebp-4h]
  int ra; // [esp+40h] [ebp+Ch]
  float rb; // [esp+40h] [ebp+Ch]
  int rh; // [esp+40h] [ebp+Ch]
  int ri; // [esp+40h] [ebp+Ch]
  int rc; // [esp+40h] [ebp+Ch]
  float rd; // [esp+40h] [ebp+Ch]
  int rj; // [esp+40h] [ebp+Ch]
  int rk; // [esp+40h] [ebp+Ch]
  int re; // [esp+40h] [ebp+Ch]
  float rf; // [esp+40h] [ebp+Ch]
  int rl; // [esp+40h] [ebp+Ch]
  int rg; // [esp+40h] [ebp+Ch]

  m_pMemory = (int)r->m_Memory.m_pMemory;
  m_nAllocationCount = r->m_Memory.m_nAllocationCount;
  GMatrix3D::Transform(this, a2: (float *)&v55, bDivideByW: (float *)&m_pMemory, a4: bDivideByW);
  m_pMemory = r->m_Memory.m_nGrowSize;
  m_nAllocationCount = r->m_Memory.m_nAllocationCount;
  GMatrix3D::Transform(this, a2: (float *)&v53, bDivideByW: (float *)&m_pMemory, a4: bDivideByW);
  m_pMemory = r->m_Memory.m_nGrowSize;
  m_nAllocationCount = r->m_Size;
  GMatrix3D::Transform(this, a2: (float *)&v51, bDivideByW: (float *)&m_pMemory, a4: bDivideByW);
  m_pMemory = (int)r->m_Memory.m_pMemory;
  m_nAllocationCount = r->m_Size;
  GMatrix3D::Transform(this, a2: (float *)&v49, bDivideByW: (float *)&m_pMemory, a4: bDivideByW);
  v5 = *(float *)&v55;
  result->m_Memory.m_pMemory = (unsigned __int16 *)v55;
  v6 = *(float *)&v56;
  result->m_Memory.m_nAllocationCount = v56;
  *(float *)&result->m_Size = v6;
  v7 = v6;
  v8 = v5;
  v9 = v7;
  *(float *)&result->m_Memory.m_nGrowSize = v8;
  if ( *(float *)&v53 <= v8 )
  {
    ra = v53;
    v10 = v8;
    v11 = *(float *)&v53;
  }
  else
  {
    v10 = v8;
    v11 = *(float *)&v53;
    *(float *)&ra = v10;
  }
  v12 = *(float *)&ra;
  result->m_Memory.m_pMemory = (unsigned __int16 *)ra;
  if ( v54 <= v9 )
  {
    rb = v54;
    v13 = v9;
    v14 = v54;
  }
  else
  {
    v13 = v9;
    v14 = v54;
    rb = v13;
  }
  *(float *)&result->m_Memory.m_nAllocationCount = rb;
  v15 = v11;
  v16 = rb;
  if ( v15 >= v10 )
    v10 = v15;
  v17 = v13;
  v18 = v10;
  v19 = v17;
  *(float *)&rh = v18;
  result->m_Memory.m_nGrowSize = rh;
  v20 = v14;
  v21 = *(float *)&rh;
  if ( v20 >= v17 )
    v19 = v20;
  v22 = v12;
  v23 = v19;
  v24 = v22;
  *(float *)&ri = v23;
  v25 = *(float *)&ri;
  result->m_Size = ri;
  if ( *(float *)&v51 <= v22 )
  {
    rc = v51;
    v27 = *(float *)&v51;
  }
  else
  {
    v26 = v24;
    v27 = *(float *)&v51;
    *(float *)&rc = v26;
  }
  v28 = *(float *)&rc;
  result->m_Memory.m_pMemory = (unsigned __int16 *)rc;
  if ( v52 <= v16 )
  {
    rd = v52;
    v30 = v52;
  }
  else
  {
    v29 = v16;
    v30 = v52;
    rd = v29;
  }
  *(float *)&result->m_Memory.m_nAllocationCount = rd;
  v31 = v27;
  v32 = rd;
  if ( v31 >= v21 )
    v21 = v31;
  v33 = v28;
  v34 = v21;
  v35 = v33;
  *(float *)&rj = v34;
  result->m_Memory.m_nGrowSize = rj;
  v36 = v30;
  v37 = *(float *)&rj;
  if ( v36 >= v25 )
    v25 = v36;
  *(float *)&rk = v25;
  v38 = *(float *)&rk;
  result->m_Size = rk;
  if ( *(float *)&v49 <= v35 )
  {
    re = v49;
    v40 = *(float *)&v49;
  }
  else
  {
    v39 = v35;
    v40 = *(float *)&v49;
    *(float *)&re = v39;
  }
  result->m_Memory.m_pMemory = (unsigned __int16 *)re;
  if ( v50 <= v32 )
  {
    rf = v50;
    v42 = v50;
  }
  else
  {
    v41 = v32;
    v42 = v50;
    rf = v41;
  }
  *(float *)&result->m_Memory.m_nAllocationCount = rf;
  v43 = v38;
  v44 = v40;
  v45 = v43;
  if ( v44 >= v37 )
    v37 = v44;
  v46 = v42;
  v47 = v37;
  v48 = v46;
  *(float *)&rl = v47;
  result->m_Memory.m_nGrowSize = rl;
  if ( v46 >= v45 )
    *(float *)&rg = v48;
  else
    *(float *)&rg = v45;
  result->m_Size = rg;
}

//------------------------------------------------------------------------------
// Address: 0x100627C0
// Name: public: void GMatrix3D::EncloseTransform(class GPoint<float> __near *,class GRect<float> const __near &,bool)const
// Source: json
//------------------------------------------------------------------------------
float *__thiscall GMatrix3D::EncloseTransform(
        CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *this,
        float *pts,
        CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *r,
        float bDivideByW)
{
  int m_pMemory; // [esp+Ch] [ebp-8h] BYREF
  int m_nAllocationCount; // [esp+10h] [ebp-4h]

  m_pMemory = (int)r->m_Memory.m_pMemory;
  m_nAllocationCount = r->m_Memory.m_nAllocationCount;
  GMatrix3D::Transform((float *)this, a2: pts, bDivideByW: (float *)&m_pMemory, a4: bDivideByW);
  m_pMemory = r->m_Memory.m_nGrowSize;
  m_nAllocationCount = r->m_Memory.m_nAllocationCount;
  GMatrix3D::Transform((float *)this, a2: pts + 2, bDivideByW: (float *)&m_pMemory, a4: bDivideByW);
  m_pMemory = r->m_Memory.m_nGrowSize;
  m_nAllocationCount = r->m_Size;
  GMatrix3D::Transform((float *)this, a2: pts + 4, bDivideByW: (float *)&m_pMemory, a4: bDivideByW);
  m_pMemory = (int)r->m_Memory.m_pMemory;
  m_nAllocationCount = r->m_Size;
  return GMatrix3D::Transform((float *)this, a2: pts + 6, bDivideByW: (float *)&m_pMemory, a4: bDivideByW);
}
