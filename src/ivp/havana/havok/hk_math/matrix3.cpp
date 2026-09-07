// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/havana/havok/hk_math/matrix3.cpp
// Functions: 4
// ============================================================

#include "ivp\havana\havok\hk_math\matrix3.h"

//------------------------------------------------------------------------------
// Address: 0x10045000
// Name: public: void hk_Matrix3::set_zero(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_Matrix3::set_zero(hk_Matrix3 *this)
{
  *(_QWORD *)&this->m_elems[1] = 0;
  this->m_elems[0] = 0.0;
  *(_QWORD *)&this->m_elems[5] = 0;
  this->m_elems[4] = 0.0;
  *(_QWORD *)&this->m_elems[9] = 0;
  this->m_elems[8] = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10045030
// Name: public: void hk_Matrix3::set_mul3(class hk_Matrix3 const __near &,class hk_Matrix3 const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_Matrix3::set_mul3(hk_Matrix3 *this, const hk_Matrix3 *Ma, const hk_Matrix3 *Mb)
{
  float v4; // xmm7_4
  float v5; // xmm4_4
  float v6; // xmm5_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm3_4
  float v10; // xmm2_4
  float v11; // xmm7_4
  float v12; // xmm0_4
  float v13; // xmm5_4
  float v14; // xmm1_4
  float v15; // xmm3_4
  float v16; // xmm2_4
  float v17; // xmm4_4
  float v18; // xmm0_4
  float v19; // xmm5_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  float v22; // xmm4_4
  float v23; // xmm6_4
  float v24; // [esp+0h] [ebp-14h]
  float v25; // [esp+4h] [ebp-10h]
  float v26; // [esp+4h] [ebp-10h]
  float v27; // [esp+4h] [ebp-10h]
  float v28; // [esp+8h] [ebp-Ch]
  float Mba; // [esp+20h] [ebp+Ch]
  float Mbb; // [esp+20h] [ebp+Ch]
  float Mbc; // [esp+20h] [ebp+Ch]

  v4 = Ma->m_elems[10];
  v25 = Ma->m_elems[2];
  v5 = Ma->m_elems[6];
  v6 = Mb->m_elems[0] * Ma->m_elems[1];
  v28 = Mb->m_elems[0];
  v7 = Mb->m_elems[0] * Ma->m_elems[0];
  v8 = Mb->m_elems[1];
  Mba = Ma->m_elems[9];
  v9 = Mb->m_elems[2];
  v10 = v8 * Ma->m_elems[5];
  this->m_elems[0] = (float)(v7 + (float)(v8 * Ma->m_elems[4])) + (float)(v9 * Ma->m_elems[8]);
  this->m_elems[2] = (float)((float)(v8 * v5) + (float)(v28 * v25)) + (float)(v9 * v4);
  this->m_elems[1] = (float)(v10 + v6) + (float)(v9 * Mba);
  v11 = Ma->m_elems[10];
  v12 = Mb->m_elems[4];
  v26 = Ma->m_elems[2];
  v13 = v12 * Ma->m_elems[1];
  v14 = Mb->m_elems[5];
  Mbb = Ma->m_elems[9];
  v15 = Mb->m_elems[6];
  v16 = v14 * Ma->m_elems[5];
  v17 = v14 * Ma->m_elems[6];
  this->m_elems[4] = (float)((float)(v12 * Ma->m_elems[0]) + (float)(v14 * Ma->m_elems[4]))
                   + (float)(v15 * Ma->m_elems[8]);
  this->m_elems[5] = (float)(v16 + v13) + (float)(v15 * Mbb);
  this->m_elems[6] = (float)(v17 + (float)(v12 * v26)) + (float)(v15 * v11);
  v18 = Mb->m_elems[8];
  v27 = Ma->m_elems[2];
  v19 = v18 * Ma->m_elems[1];
  v20 = Mb->m_elems[9];
  Mbc = Ma->m_elems[9];
  v21 = v20 * Ma->m_elems[5];
  v22 = v20 * Ma->m_elems[6];
  v24 = Ma->m_elems[10];
  v23 = Mb->m_elems[10];
  this->m_elems[8] = (float)((float)(v18 * Ma->m_elems[0]) + (float)(v20 * Ma->m_elems[4]))
                   + (float)(v23 * Ma->m_elems[8]);
  this->m_elems[9] = (float)(v21 + v19) + (float)(v23 * Mbc);
  this->m_elems[10] = (float)(v22 + (float)(v18 * v27)) + (float)(v23 * v24);
}

//------------------------------------------------------------------------------
// Address: 0x10045270
// Name: public: void hk_Matrix3::set_mul3_inv(class hk_Rotation const __near &,class hk_Matrix3 const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_Matrix3::set_mul3_inv(hk_Matrix3 *this, const hk_Rotation *Ma, const hk_Matrix3 *Mb)
{
  float v3; // xmm1_4
  float v4; // xmm7_4
  float v5; // xmm0_4
  float v6; // xmm2_4
  float v7; // xmm4_4
  float v8; // xmm3_4
  float v9; // xmm5_4
  float v10; // xmm6_4
  float v11; // xmm1_4
  float v12; // xmm7_4
  float v13; // xmm0_4
  float v14; // xmm2_4
  float v15; // xmm4_4
  float v16; // xmm3_4
  float v17; // xmm5_4
  float v18; // xmm6_4
  float v19; // xmm2_4
  float v20; // xmm1_4
  float v21; // xmm6_4
  float v22; // xmm5_4
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // [esp+8h] [ebp-Ch]
  float v26; // [esp+8h] [ebp-Ch]

  v3 = Mb->m_elems[0];
  v4 = Ma->m_elems[10];
  v5 = Mb->m_elems[1];
  v25 = Ma->m_elems[8];
  v6 = v5 * Ma->m_elems[5];
  v7 = v5 * Ma->m_elems[9];
  v8 = Mb->m_elems[2];
  v9 = Mb->m_elems[0] * Ma->m_elems[4];
  v10 = v8 * Ma->m_elems[6];
  this->m_elems[0] = (float)((float)(v5 * Ma->m_elems[1]) + (float)(Mb->m_elems[0] * Ma->m_elems[0]))
                   + (float)(v8 * Ma->m_elems[2]);
  this->m_elems[2] = (float)(v7 + (float)(v3 * v25)) + (float)(v8 * v4);
  this->m_elems[1] = (float)(v6 + v9) + v10;
  v11 = Mb->m_elems[4];
  v12 = Ma->m_elems[10];
  v13 = Mb->m_elems[5];
  v26 = Ma->m_elems[8];
  v14 = v13 * Ma->m_elems[5];
  v15 = v13 * Ma->m_elems[9];
  v16 = Mb->m_elems[6];
  v17 = v11 * Ma->m_elems[4];
  v18 = v16 * Ma->m_elems[6];
  this->m_elems[4] = (float)((float)(v13 * Ma->m_elems[1]) + (float)(v11 * Ma->m_elems[0]))
                   + (float)(v16 * Ma->m_elems[2]);
  this->m_elems[5] = (float)(v14 + v17) + v18;
  this->m_elems[6] = (float)(v15 + (float)(v11 * v26)) + (float)(v16 * v12);
  v19 = Mb->m_elems[8];
  v20 = Mb->m_elems[9];
  v21 = (float)(Ma->m_elems[1] * v20) + (float)(Ma->m_elems[0] * v19);
  v22 = Mb->m_elems[10];
  v23 = (float)((float)(v20 * Ma->m_elems[5]) + (float)(v19 * Ma->m_elems[4])) + (float)(v22 * Ma->m_elems[6]);
  v24 = (float)((float)(v20 * Ma->m_elems[9]) + (float)(v19 * Ma->m_elems[8])) + (float)(v22 * Ma->m_elems[10]);
  this->m_elems[8] = v21 + (float)(Ma->m_elems[2] * v22);
  this->m_elems[9] = v23;
  this->m_elems[10] = v24;
}

//------------------------------------------------------------------------------
// Address: 0x100454B0
// Name: public: void hk_Matrix3::rotate(int,float)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge hk_Matrix3::rotate(
        hk_Matrix3 *this@<ecx>,
        int a2@<ebp>,
        long double a3@<esi:edi>,
        int axis,
        float angle)
{
  int v6; // esi
  float v7; // xmm1_4
  int v8; // eax
  long double v10; // [esp-1Ch] [ebp-8Ch]
  __int64 v11; // [esp-Ch] [ebp-7Ch] BYREF
  _BYTE v12[41]; // [esp-4h] [ebp-74h] OVERLAPPED BYREF
  hk_Matrix3 rotation; // [esp+30h] [ebp-40h]
  int v14; // [esp+60h] [ebp-10h]
  int v15; // [esp+64h] [ebp-Ch]
  float cos_alpha; // [esp+68h] [ebp-8h]
  float retaddr; // [esp+70h] [ebp+0h]

  v15 = a2;
  cos_alpha = retaddr;
  hk_Matrix3::set_zero(this: (hk_Matrix3 *)&v12[40]);
  v6 = axis + 1;
  if ( axis == 2 )
    v6 = 0;
  v14 = v6 + 1;
  if ( v6 == 2 )
    v14 = 0;
  __libm_sse2_cos(x: a3);
  rotation.m_elems[11] = angle;
  __libm_sse2_sin(x: v10);
  v7 = rotation.m_elems[11];
  *(float *)&v12[20 * v6 + 40] = rotation.m_elems[11];
  v8 = v14;
  *(float *)&v12[20 * v14 + 40] = v7;
  *(float *)&v12[16 * v6 + 40 + 4 * v8] = angle;
  *(_DWORD *)&v12[16 * v8 + 40 + 4 * v6] = LODWORD(angle) ^ _mask__NegFloat_;
  *(_DWORD *)&v12[20 * axis + 40] = 1065353216;
  hk_Matrix3::set_mul3(this: (hk_Matrix3 *)&v11, Ma: this, Mb: (const hk_Matrix3 *)&v12[40]);
  *(_QWORD *)this->m_elems = v11;
  qmemcpy(&this->m_elems[2], v12, 40);
}
